#ifndef _STL_NEURON_
#define _STL_NEURON_

#include "neuron_base.h"

namespace n {

	template<typename InClass>
	class INeuron : public ineuron_base {
	public:
		INeuron();
		INeuron(const InClass*);

		~INeuron();
		
		_value_t activate(act_code_t) override;

		inline _value_t getVal() override;

	private:
		InClass* input;
	};

	template<typename OutClass>
	class ONeuron : public oneuron_base {
	public:
		ONeuron();
		ONeuron(const OutClass*);

		~ONeuron();

		_value_t activate(act_code_t) override;

		inline _value_t getVal() override;

	private:
		OutClass* output;
	};

	template<typename ActClass>
	class MNeuron : public mneuron_base {
	public:
		MNeuron();
		MNeuron(const ActClass*);
		
		~MNeuron();

		_value_t activate(act_code_t) override;

		inline _value_t getVal() override;

	private:
		ActClass* _Act;
	};

}

#endif