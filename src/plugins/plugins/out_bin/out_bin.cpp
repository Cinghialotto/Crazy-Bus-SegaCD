///////////////////////////////////////////////////////////////////////////////
// Output binary plugins for mdtt
// 
//
//
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Includes

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include "../../mdttSDK.h"

///////////////////////////////////////////////////////////////////////////////
// Local variables


///////////////////////////////////////////////////////////////////////////////
// Get the description of the plugins

DLLEXPORT char* GetDescription(void)
{
	return "Binary Output";
}

///////////////////////////////////////////////////////////////////////////////
// Get the author name

DLLEXPORT char* GetAuthor(void)
{
	return "Spoutnick Team";
}

///////////////////////////////////////////////////////////////////////////////
// Get author contact info

DLLEXPORT char* GetContactInfo(void)
{
	return "www.spoutnickteam.com";
}

///////////////////////////////////////////////////////////////////////////////
// Get build version

DLLEXPORT char* GetBuildVersion(void)
{
	return "1.0";
}

///////////////////////////////////////////////////////////////////////////////
// Get id of the plugins (should be unique!)

DLLEXPORT char* GetID(void)
{
	return"bin";
}

///////////////////////////////////////////////////////////////////////////////
// file extension

DLLEXPORT char* GetExt(void)
{
	return"bin";
}

///////////////////////////////////////////////////////////////////////////////
// define the type of ouput

DLLEXPORT int GetOutputType(void)
{
	return tgOutputType_Raw;
}

///////////////////////////////////////////////////////////////////////////////
// Output the data

DLLEXPORT int OutputData(const char *filename,const char *name,int type,uint8* data,int size)
{
	FILE *out_file=NULL;

	out_file=fopen(filename,"wb");
	if(!out_file)
	{	return tgERR_SAVINGFILE;}

	fwrite(data,size,1,out_file);	

	fclose(out_file);
	
	return tgOK;
}

