#include "neuron_base.h"

namespace n {

	neuron_base::neuron_base() : act_code(NULL), _value(NULL) {}

	inline _value_t neuron_base::getVal() {
		return _value;
	}

	// Synaps_ptr

	Synaps_ptr::Synaps_ptr(Synaps* ptr) : synaps(ptr) {}
	
	Synaps_ptr::~Synaps_ptr() { // доделать
		delete synaps;
	}

	inline Synaps& Synaps_ptr::operator*() {
		return *synaps;
	}

	// Input Neuron

	ineuron_base::ineuron_base() : neuron_base() {}
	
	ineuron_base::~ineuron_base() {
		output_neurons.clear();
	}

	void ineuron_base::addOutput(Synaps_ptr output_neuron) {
		output_neurons.push_back(output_neuron);
	}

	// Input Connection

	iconnect::iconnect() {}

	iconnect::iconnect(ineuron_ptr ptr) : _exPtr(ptr) {
		pos = ptr->output_neurons.end();
	}

	void iconnect::remove() {
		_exPtr->output_neurons.erase(pos);
	}

	// Output Neuron

	oneuron_base::oneuron_base() : neuron_base() {}

	oneuron_base::~oneuron_base() {
		input_neurons.clear();
	}

	void oneuron_base::addInput(Synaps_ptr input_neuron) {
		input_neurons.push_back(input_neuron);
	}

	// Output Connection

	oconnect::oconnect() {}

	oconnect::oconnect(oneuron_ptr ptr) : _exPtr(ptr) {
		pos = ptr->input_neurons.end();
	}

	void oconnect::remove() {
		_exPtr->input_neurons.erase(pos);
	}

	//Synaps

	Synaps::Synaps(ineuron_ptr input_ptr, oneuron_ptr output_ptr) {
		input_ptr->addOutput(Synaps_ptr(this));
		input = input_ptr;
		output_ptr->addInput(Synaps_ptr(this));
		output = output_ptr;
	}

	// Middle Neuron

	mneuron_base::mneuron_base() : neuron_base() {}

	mneuron_base::~mneuron_base() {
		input_neurons.clear();
		output_neurons.clear();
	}

}