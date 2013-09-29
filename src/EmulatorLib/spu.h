#ifndef SPU_H
#define SPU_H

#include "utils.h"

using Utils::UInt8;

/*
* \class SPU
* \brief Emulates the Sound Processing Unit (SPU)
* \author F�lix-Antoine Ouellet
* \version 0.1
*/
class SPU
{
private:
	// TODO : ...
	// Most certainly a current generator

public:
	/**
	* \fn SPU
	* \brief Default constructor
	*/
	SPU();

	/**
	* \fn ~SPU
	* \brief Destructor
	*/
	~SPU();

public:
	/**
	* \fn Init
	* \brief Initialize the sound processing unit
	* \return Success or failure
	*/
	bool Init();
	
	/**
	* \fn GenerateSound
	* \brief Activate the sound generator
	* \param TODO
	*/
	void GenerateSound(UInt8 in_Attack, UInt8 in_Decay, UInt8 in_Sustain, 
		UInt8 in_Release, UInt8 in_Volume, UInt8 in_Type);

	/**
	* \fn PlayTone
	* \brief Play a given tone for a given duration
	* \param in_Tone The frequency in Hertz of the tone to play
	* \param in_Duration The duration in milliseconds of the tone to play
	*/
	void PlayTone(unsigned in_Tone, unsigned in_Duration);

	/**
	* \fn Stop
	* \brief Stop the sound generator
	*/
	void Stop();
};

#endif // SPU_H