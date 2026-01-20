#pragma once

#include "..\Graph\Graph_Vector.h"
using namespace Graph;

namespace Motion
{
	// ֱ���˶�
	class CMotion
	{
	public:
		CMotion()
		{

		}

		~CMotion()
		{

		}

		void SetVelocity(const Vector &velocity)
		{
			m_velocity = velocity;
		}

		const Vector GetVelocity()
		{
			return m_velocity;
		}
	
		void SetAcceleration(const Vector &acceleration)
		{
			m_acceleration = acceleration;
		}

		const Vector GetAcceleration()
		{
			return m_acceleration;
		}

		void SetPosition(const Vector &position)
		{
			m_position = position;
		}

		const Vector GetPosition()
		{
			return m_position;
		}

		// ���tTime ʱ�������λ��
		virtual const Vector GetNowPosition(real tTime) = 0;
	
		// ���tTime ʱ��������ٶ�
		virtual const Vector GetNowVelocity(real tTime) = 0;


	protected:
		// ��ʼ�ٶȼ��ٶȺ�λ��
		Vector m_velocity;
		Vector m_acceleration;
		Vector m_position;
	};

	// ����ֱ���˶�
	class CUniformMotion : public CMotion
	{
		// ���tTime ʱ�������λ��
		virtual const Vector GetNowPosition(real tTime)
		{
			return Vector(m_position+m_velocity*tTime);
		}

		// ���tTime ʱ��������ٶ�
		virtual const Vector GetNowVelocity(real tTime)
		{
			return m_velocity;
		}
	};

	// �ȼ���ֱ���˶�
	class CUniformAccelerationMotion : public CMotion
	{
		// ���tTime ʱ�������λ��
		virtual const Vector GetNowPosition(real tTime)
		{
			return Vector(m_position + m_velocity*tTime + m_acceleration*tTime*tTime*0.5f);
		}

		// ���tTime ʱ��������ٶ�
		virtual const Vector GetNowVelocity(real tTime)
		{
			return Vector(m_velocity + m_acceleration*tTime);
		}
	};

	// �����ֱ���˶�
	class CVaryAccelerationMotion : public CMotion
	{
		// ���tTime ʱ�������λ��
		virtual const Vector GetNowPosition(real tTime)
		{
			// acceleration Ϊ -velocity
			return Vector(m_position + m_velocity*tTime*tTime*0.5f*(1-tTime/3));
		}

		// ���tTime ʱ��������ٶ�
		virtual const Vector GetNowVelocity(real tTime)
		{
			return Vector(m_velocity*(1-tTime*tTime));
		}
	};
	
	//������
	class CDamp
	{
	public:
		// ���tTime ʱ����������
		virtual real GetNowAmplitude(real tTime) = 0;

	public:
		CDamp()
		{
			m_amplitude = 40.0f;
			m_damp = 0.8f;
			m_angularFrequency = 2.0f;
			m_phase = 0.0f;

		}

		CDamp(real amplitude,real damp,real angularFrequency,real phase)
		{
			m_amplitude = amplitude;
			m_damp = damp;
			m_angularFrequency = angularFrequency;
			m_phase = phase;
		}

		void SetAmplitude(real amplitude)
		{
			m_amplitude = amplitude;
		}

		real GetAmplitude() const
		{
			return m_amplitude;
		}

		void SetDamp(real damp)
		{
			m_damp = damp;
		}

		real GetDamp() const
		{
			return m_damp;
		}

		void SetAngularFrequency(real angularFrequency)
		{
			m_angularFrequency = angularFrequency;
		}

		real GetAngularFrequency() const
		{
			return m_angularFrequency;
		}

		void SetPhase(real phase)
		{
			m_phase = phase;
		}

		real GetPhase() const
		{
			return m_phase;
		}

	protected:
		real m_amplitude;			//���
		real m_damp;				//��������
		real m_angularFrequency;	//���н�Ƶ��
		real m_phase;				//��ʼ��λ
	};

	// Ƿ�����˶�(��<��)
	//x(t) = A * exp(-��*t) * cos(sqrt(��^2 - ��^2) * t + ��) , �����������ӣ����ǹ��н�Ƶ�ʣ�A��������ճ�ʼ��λ��Ϊ���������Ե���0��
	//�����ʱ������ƣ���ָ���ݼ��� ��Խ����˥��Խ�죻��֮�����˥��Խ��
	class CUnderDamp : public CDamp
	{
	public:
		CUnderDamp()
		{
			m_amplitude = 40.0f;
			m_damp = 0.8f;
			m_angularFrequency = 2.0f;
			m_phase = 0.0f;
		}

	public:	
		real GetNowAmplitude(real tTime)
		{
			return m_amplitude*exp(-m_damp*tTime)*cos(sqrt(m_angularFrequency*m_angularFrequency-m_damp*m_damp)*tTime + m_phase);
		}
	
	};

	// �������˶�(��>��)
	//x(t) = A * exp(-t*(��-sqrt(��^2-��^2)) + B * exp(-t*(��+sqrt(��^2-��^2)) ,
	//��ʱ������ƣ��ʵ����굥���������㡣�ʵ��˶��Ƿ����ڵĲ������ġ����ʵ��ƿ�ƽ��λ�ú��ͷţ��ʵ�������ص�ƽ��λ��ͣ����
	class COverDamp : public CDamp
	{
	public:
		COverDamp()
		{
			m_amplitudeA = m_amplitudeB = m_amplitude;
			m_damp = 0.4f;
			m_angularFrequency = 0.30f;
			m_phase = 0.0f;
		}

		void SetAmplitudeA(real amplitudeA)
		{
			m_amplitudeA = amplitudeA;
		}

		real GetAmplitudeA() const
		{
			return m_amplitudeA;
		}

		void SetAmplitudeB(real amplitudeB)
		{
			m_amplitudeB = amplitudeB;
		}

		real GetAmplitude() const
		{
			return m_amplitudeB;
		}
	public:	
		real GetNowAmplitude(real tTime)
		{
			return m_amplitudeA*exp(-tTime*(m_damp-sqrt(m_damp*m_damp-m_angularFrequency*m_angularFrequency)))
				+ m_amplitudeB*exp(-tTime*(m_damp+sqrt(m_damp*m_damp-m_angularFrequency*m_angularFrequency)));
		}

	protected:
		real m_amplitudeA,m_amplitudeB; //��ʼ�����������ʼ��������ʼ��������

	};
	
	// �ٽ������˶�(��=��)
	//x(t) = (A + B*t) * exp(-��*t)
	//����������ǰ��С���ʵ��ƿ�ƽ��λ���ͷź��ʵ�ܿ�ص�ƽ��λ�ò�ͣ����
	class CCriticalDamp : public CDamp
	{
	public:
		CCriticalDamp()
		{
			m_amplitudeA = m_amplitudeB = m_amplitude;
			m_damp = 1.0f;
			m_angularFrequency = 1.0f;
			m_phase = 0.0f;
		}

		void SetAmplitudeA(real amplitudeA)
		{
			m_amplitudeA = amplitudeA;
		}

		real GetAmplitudeA() const
		{
			return m_amplitudeA;
		}

		void SetAmplitudeB(real amplitudeB)
		{
			m_amplitudeB = amplitudeB;
		}

		real GetAmplitude() const
		{
			return m_amplitudeB;
		}

	public:	
		real GetNowAmplitude(real tTime)
		{
			return (m_amplitudeA+m_amplitudeB*tTime)*exp(-m_damp*tTime);
		}

	protected:
		real m_amplitudeA,m_amplitudeB; //��ʼ�����������ʼ��������ʼ��������

	};

}