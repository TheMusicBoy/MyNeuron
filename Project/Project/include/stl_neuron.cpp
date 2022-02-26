#include "stl_neuron.h"

#define ITMP template<typename InClass>
#define INTMP ITMP INeuron<InClass>

#define OTMP template<typename OutClass>
#define ONTMP OTMP ONeuron<OutClass>

#define MTMP template<typename ActClass>
#define MNTMP MTMP MNeuron<ActClass>

namespace n {
	
	// Input Neuron Template

	INTMP::INeuron() : ineuron_base() {}

	INTMP::INeuron(const InClass* _input) : ineuron_base() {
		input = _input;
	}

	INTMP::~INeuron() {
		output_neurons.clear();
		delete input;
	}

	ITMP _value_t INeuron<InClass>::activate(act_code_t code) {
		if(act_code == code)
			_value = input->getInput();
		return _value;
	}

	ITMP inline _value_t INeuron<InClass>::getVal() {
		return _value;
	}

	// Output Neuron Template

	ONTMP::ONeuron() : oneuron_base() {}

	ONTMP::ONeuron(const OutClass* _output) : oneuron_base() {
		output = _output;
	}

	ONTMP::~ONeuron() {
		input_neurons.clear();
		delete output;
	}

	OTMP _value_t ONeuron<OutClass>::activate(act_code_t code) {
		if (act_code == code)
			_value = output->getOutput();
		return _value;
	}

	OTMP inline _value_t ONeuron<OutClass>::getVal() {
		return _value;
	}

	// Middle Neuron Template

	MNTMP::MNeuron() : mneuron_base() {}

	MNTMP::MNeuron(const ActClass* _activ) : mneuron_base() {
		_Act = _activ;
	}

	MNTMP::~MNeuron() {
		output_neurons.clear();
		input_neurons.clear();
		delete _Act;
	}

	MTMP _value_t MNeuron<ActClass>::activate(act_code_t code) {
		if (act_code == code) {
			double sigma = 0;
			for (Synaps_ptr iter : input_neurons)
				sigma += (*iter).input * (*iter).weight;
			_value = _Act->activate();
		}
		return _value;
	}

	MTMP inline _value_t MNeuron<ActClass>::getVal() {
		return _value;
	}

}