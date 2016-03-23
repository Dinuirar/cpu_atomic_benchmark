/*-
 * Copyright (c) 2016 Semihalf.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _BENCH_H_
#define _BENCH_H_

#include <stdbool.h>
#include <errno.h>

struct thrarg;

typedef void (*benchmark_t)(struct thrarg *arg);

struct thrarg {
	struct thpar {
		unsigned threads;
		unsigned id;
		benchmark_t benchmark;
		benchmark_t init;
		bool print_samples;
		unsigned iters;
		unsigned max_samples;
		unsigned long min_time;
		unsigned char max_error;
	} params;
	struct thres {
		unsigned iters;
		unsigned samples;
		double avg;
		double sum;
		double sdev;
		double u;
		double err;
	} result;
};

int benchmark_auto(struct thrarg *thrarg);
int benchmark_once(struct thrarg *thrarg);

#define USE(x) asm volatile ("" :: "r" (x));

#endif // _BENCH_H_
