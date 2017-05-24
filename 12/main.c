/*
 * main.c
 *
 *  Created on: 2017年5月24日
 *      Author: soul11201
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void usage()
{
	printf( " ----------------------------------------------\n"
			"| -h/--help: Display this usage information.   |\n"
			"| -o/--output filename: Write output to file.  |\n"
			"| -v/--verbose: Print verbose messages.        |\n"
			"| -p the server running prefix like nginx      |\n"
			" ----------------------------------------------\n"
			);
}

int main(int argc, char **argv) {
	for (int i = 0; i< argc; ++i)
	{
		printf("%d %s\n",i,argv[i]);
	}

	printf("--------------------\n\n");

	const char * const short_opts = "hvo:";
	const struct option long_opts[] = {
			{"help",0,NULL,'h'},
			{"verbose",0,NULL,'v'},
			{"output",1,NULL,'o'},
			{NULL,0,NULL,0}
	};

//	int index = -1,*index_ptr = &index;
//	int opt = getopt_long(argc,argv,short_opts,long_opts,index_ptr);
	int opt = getopt_long(argc,argv,short_opts,long_opts,NULL);
	while(opt != -1)
	{
		switch(opt){
		case 'h':
//			printf("index_ptr %d\n",index);
			printf("-h/--help\n");
			break;
		case 'o':
//			printf("index_ptr %d\n",index);
			printf("%s\n",optarg);
			printf("-o/--output\n");
			break;
		case 'v':
//			printf("index_ptr %d\n",index);
			printf("-v/--verbose\n");
			break;
		case '?':
			usage();
			exit(1);
//			abort();
//			printf("index_ptr %d\n",index);
//			printf("invalid parameters\n");
			break;
		case -1:
			printf("process finished\n");
			break;
		default:
			usage();
			printf("abort: %d\n",opt);
			abort();
		}
		printf("\n");
//		opt = getopt_long(argc,argv,short_opts,long_opts,index_ptr);
		opt = getopt_long(argc, argv, short_opts, long_opts, NULL);
	}

	for(int i = 0; i< 3;++i)
	{
		printf("---> %d %s %x\n",i,long_opts[i].name,long_opts[i].flag);
	}

}



