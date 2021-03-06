/*
 * Copyright © 2020 Google, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "freedreno_gmem.c"

/* NOTE, non-interesting gmem keys (ie. things that are small enough to fit
 * in a single bin) are commented out, but retained for posterity.
 */
static const struct gmem_key keys[] = {
	/* manhattan: */
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
//	{ .minx=0, .miny=0, .width=64, .height=64, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=32, .height=32, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=16, .height=16, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=8, .height=8, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=4, .height=4, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=2, .height=2, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=1, .height=1, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=4, .cbuf_cpp = {4,4,4,4,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
//	{ .minx=0, .miny=0, .width=64, .height=64, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {2,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1024, .height=1024, .gmem_page_align=1, .nr_cbufs=0, .cbuf_cpp = {0,0,0,0,0,0,0,0,}, .zsbuf_cpp = {2,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=0, .cbuf_cpp = {0,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
	{ .minx=0, .miny=0, .width=960, .height=540, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=480, .height=270, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=240, .height=135, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
//	{ .minx=0, .miny=0, .width=120, .height=67, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},

	/* trex: */
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {2,0,}},
	{ .minx=0, .miny=0, .width=960, .height=540, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {2,0,0,0,0,0,0,0,}, .zsbuf_cpp = {2,0,}},
	{ .minx=0, .miny=0, .width=1024, .height=1024, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {2,0,}},
//	{ .minx=0, .miny=0, .width=64, .height=64, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {2,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},

	/* supertuxkart: */
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {2,0,}},
	{ .minx=0, .miny=0, .width=810, .height=810, .gmem_page_align=1, .nr_cbufs=2, .cbuf_cpp = {4,4,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
//	{ .minx=0, .miny=0, .width=405, .height=405, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {2,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=405, .height=405, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {8,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=810, .height=810, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {8,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
	{ .minx=0, .miny=0, .width=810, .height=810, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
	{ .minx=0, .miny=0, .width=810, .height=810, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=960, .height=540, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {2,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {8,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=960, .height=540, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {8,0,0,0,0,0,0,0,}, .zsbuf_cpp = {0,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=2, .cbuf_cpp = {4,4,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {8,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
	{ .minx=0, .miny=0, .width=1920, .height=1080, .gmem_page_align=1, .nr_cbufs=1, .cbuf_cpp = {4,0,0,0,0,0,0,0,}, .zsbuf_cpp = {4,0,}},
};

struct gpu_info {
	const char *name;
	uint32_t gpu_id;
	uint32_t gmem_alignw;
	uint32_t gmem_alignh;
	uint32_t num_vsc_pipes;
	uint32_t gmemsize_bytes;
};

#define SZ_128K  0x00020000
#define SZ_256K  0x00040000
#define SZ_512K  0x00080000
#define SZ_1M    0x00100000

/* keep sorted by gpu name: */
static const struct gpu_info gpu_infos[] = {
	{ "a306", 307, 32, 32,  8, SZ_128K },
	{ "a530", 530, 64, 32, 16, SZ_1M   },
	{ "a618", 618, 32, 32, 32, SZ_512K },
	{ "a630", 630, 32, 32, 32, SZ_1M   },
};

int
main(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: gmemtest GPU_NAME\n");
		return -1;
	}

	const char *gpu_name = argv[1];
	const struct gpu_info *gpu_info = NULL;

	for (int i = 0; i < ARRAY_SIZE(gpu_infos); i++) {
		if (strcmp(gpu_name, gpu_infos[i].name) == 0) {
			gpu_info = &gpu_infos[i];
			break;
		}
	}

	if (!gpu_info) {
		printf("unrecognized gpu name: %s\n", gpu_name);
		printf("supported gpus:\n");
		for (int i = 0; i < ARRAY_SIZE(gpu_infos); i++)
			printf("\t%s\n", gpu_infos[i].name);
		return -1;
	}

	/* Setup a fake screen with enough GMEM related configuration
	 * to make gmem_stateobj_init() happy:
	 */
	struct fd_screen screen = {
		.gpu_id         = gpu_info->gpu_id,
		.gmem_alignw    = gpu_info->gmem_alignw,
		.gmem_alignh    = gpu_info->gmem_alignh,
		.num_vsc_pipes  = gpu_info->num_vsc_pipes,
		.gmemsize_bytes = gpu_info->gmemsize_bytes,
	};

	/* And finally run thru all the GMEM keys: */
	for (int i = 0; i < ARRAY_SIZE(keys); i++) {
		struct fd_gmem_stateobj *gmem =
				gmem_stateobj_init(&screen, (void *)&keys[i]);
		dump_gmem_state(gmem);
		ralloc_free(gmem);
	}

	return 0;
}
