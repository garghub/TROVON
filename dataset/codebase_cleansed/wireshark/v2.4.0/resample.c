static void *speex_alloc (size_t size) {return g_malloc0(size);}
static void *speex_realloc (void *ptr, size_t size) {return g_realloc(ptr, size);}
static void speex_free (void *ptr) {g_free(ptr);}
static double compute_func(float x, const struct FuncDef *func)
{
float y, frac;
double interp[4];
int ind;
y = x*func->oversample;
ind = (int)floor(y);
frac = (y-ind);
interp[3] = -0.1666666667*frac + 0.1666666667*(frac*frac*frac);
interp[2] = frac + 0.5*(frac*frac) - 0.5*(frac*frac*frac);
interp[0] = -0.3333333333*frac + 0.5*(frac*frac) - 0.1666666667*(frac*frac*frac);
interp[1] = 1.f-interp[3]-interp[2]-interp[0];
return interp[0]*func->table[ind] + interp[1]*func->table[ind+1] + interp[2]*func->table[ind+2] + interp[3]*func->table[ind+3];
}
static spx_word16_t sinc(float cutoff, float x, int N, const struct FuncDef *window_func)
{
float xx = x * cutoff;
if (fabs(x)<1e-6f)
return WORD2INT(32768.*cutoff);
else if (fabs(x) > .5f*N)
return 0;
return WORD2INT(32768.*cutoff*sin(M_PI*xx)/(M_PI*xx) * compute_func(fabs(2.*x/N), window_func));
}
static spx_word16_t sinc(float cutoff, float x, int N, const struct FuncDef *window_func)
{
float xx = x * cutoff;
if (fabs(x)<1e-6)
return cutoff;
else if (fabs(x) > .5*N)
return 0;
return (spx_word16_t)(cutoff*sin(M_PI*xx)/(M_PI*xx) * compute_func((float)fabs(2.*x/N), window_func));
}
static void cubic_coef(spx_word16_t x, spx_word16_t interp[4])
{
spx_word16_t x2, x3;
x2 = MULT16_16_P15(x, x);
x3 = MULT16_16_P15(x, x2);
interp[0] = PSHR32(MULT16_16(QCONST16(-0.16667f, 15),x) + MULT16_16(QCONST16(0.16667f, 15),x3),15);
interp[1] = EXTRACT16(EXTEND32(x) + SHR32(SUB32(EXTEND32(x2),EXTEND32(x3)),1));
interp[3] = PSHR32(MULT16_16(QCONST16(-0.33333f, 15),x) + MULT16_16(QCONST16(.5f,15),x2) - MULT16_16(QCONST16(0.16667f, 15),x3),15);
interp[2] = Q15_ONE-interp[0]-interp[1]-interp[3];
if (interp[2]<32767)
interp[2]+=1;
}
static void cubic_coef(spx_word16_t frac, spx_word16_t interp[4])
{
interp[0] = -0.16667f*frac + 0.16667f*frac*frac*frac;
interp[1] = frac + 0.5f*frac*frac - 0.5f*frac*frac*frac;
interp[3] = -0.33333f*frac + 0.5f*frac*frac - 0.16667f*frac*frac*frac;
interp[2] = (spx_word16_t)(1.-interp[0]-interp[1]-interp[3]);
}
static int resampler_basic_direct_single(SpeexResamplerState *st, spx_uint32_t channel_index, const spx_word16_t *in, spx_uint32_t *in_len, spx_word16_t *out, spx_uint32_t *out_len)
{
const int N = st->filt_len;
int out_sample = 0;
int last_sample = st->last_sample[channel_index];
spx_uint32_t samp_frac_num = st->samp_frac_num[channel_index];
const spx_word16_t *sinc_table = st->sinc_table;
const int out_stride = st->out_stride;
const int int_advance = st->int_advance;
const int frac_advance = st->frac_advance;
const spx_uint32_t den_rate = st->den_rate;
spx_word32_t sum;
while (!(last_sample >= (spx_int32_t)*in_len || out_sample >= (spx_int32_t)*out_len))
{
const spx_word16_t *sinct = & sinc_table[samp_frac_num*N];
const spx_word16_t *iptr = & in[last_sample];
#ifndef OVERRIDE_INNER_PRODUCT_SINGLE
int j;
sum = 0;
for(j=0;j<N;j++) sum += MULT16_16(sinct[j], iptr[j]);
sum = SATURATE32PSHR(sum, 15, 32767);
#else
sum = inner_product_single(sinct, iptr, N);
#endif
out[out_stride * out_sample++] = sum;
last_sample += int_advance;
samp_frac_num += frac_advance;
if (samp_frac_num >= den_rate)
{
samp_frac_num -= den_rate;
last_sample++;
}
}
st->last_sample[channel_index] = last_sample;
st->samp_frac_num[channel_index] = samp_frac_num;
return out_sample;
}
static int resampler_basic_direct_double(SpeexResamplerState *st, spx_uint32_t channel_index, const spx_word16_t *in, spx_uint32_t *in_len, spx_word16_t *out, spx_uint32_t *out_len)
{
const int N = st->filt_len;
int out_sample = 0;
int last_sample = st->last_sample[channel_index];
spx_uint32_t samp_frac_num = st->samp_frac_num[channel_index];
const spx_word16_t *sinc_table = st->sinc_table;
const int out_stride = st->out_stride;
const int int_advance = st->int_advance;
const int frac_advance = st->frac_advance;
const spx_uint32_t den_rate = st->den_rate;
double sum;
while (!(last_sample >= (spx_int32_t)*in_len || out_sample >= (spx_int32_t)*out_len))
{
const spx_word16_t *sinct = & sinc_table[samp_frac_num*N];
const spx_word16_t *iptr = & in[last_sample];
#ifndef OVERRIDE_INNER_PRODUCT_DOUBLE
int j;
double accum[4] = {0,0,0,0};
for(j=0;j<N;j+=4) {
accum[0] += sinct[j]*iptr[j];
accum[1] += sinct[j+1]*iptr[j+1];
accum[2] += sinct[j+2]*iptr[j+2];
accum[3] += sinct[j+3]*iptr[j+3];
}
sum = accum[0] + accum[1] + accum[2] + accum[3];
#else
sum = inner_product_double(sinct, iptr, N);
#endif
out[out_stride * out_sample++] = PSHR32(sum, 15);
last_sample += int_advance;
samp_frac_num += frac_advance;
if (samp_frac_num >= den_rate)
{
samp_frac_num -= den_rate;
last_sample++;
}
}
st->last_sample[channel_index] = last_sample;
st->samp_frac_num[channel_index] = samp_frac_num;
return out_sample;
}
static int resampler_basic_interpolate_single(SpeexResamplerState *st, spx_uint32_t channel_index, const spx_word16_t *in, spx_uint32_t *in_len, spx_word16_t *out, spx_uint32_t *out_len)
{
const int N = st->filt_len;
int out_sample = 0;
int last_sample = st->last_sample[channel_index];
spx_uint32_t samp_frac_num = st->samp_frac_num[channel_index];
const int out_stride = st->out_stride;
const int int_advance = st->int_advance;
const int frac_advance = st->frac_advance;
const spx_uint32_t den_rate = st->den_rate;
spx_word32_t sum;
while (!(last_sample >= (spx_int32_t)*in_len || out_sample >= (spx_int32_t)*out_len))
{
const spx_word16_t *iptr = & in[last_sample];
const int offset = samp_frac_num*st->oversample/st->den_rate;
#ifdef FIXED_POINT
const spx_word16_t frac = PDIV32(SHL32((samp_frac_num*st->oversample) % st->den_rate,15),st->den_rate);
#else
const spx_word16_t frac = ((float)((samp_frac_num*st->oversample) % st->den_rate))/st->den_rate;
#endif
spx_word16_t interp[4];
#ifndef OVERRIDE_INTERPOLATE_PRODUCT_SINGLE
int j;
spx_word32_t accum[4] = {0,0,0,0};
for(j=0;j<N;j++) {
const spx_word16_t curr_in=iptr[j];
accum[0] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset-2]);
accum[1] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset-1]);
accum[2] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset]);
accum[3] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset+1]);
}
cubic_coef(frac, interp);
sum = MULT16_32_Q15(interp[0],SHR32(accum[0], 1)) + MULT16_32_Q15(interp[1],SHR32(accum[1], 1)) + MULT16_32_Q15(interp[2],SHR32(accum[2], 1)) + MULT16_32_Q15(interp[3],SHR32(accum[3], 1));
sum = SATURATE32PSHR(sum, 15, 32767);
#else
cubic_coef(frac, interp);
sum = interpolate_product_single(iptr, st->sinc_table + st->oversample + 4 - offset - 2, N, st->oversample, interp);
#endif
out[out_stride * out_sample++] = sum;
last_sample += int_advance;
samp_frac_num += frac_advance;
if (samp_frac_num >= den_rate)
{
samp_frac_num -= den_rate;
last_sample++;
}
}
st->last_sample[channel_index] = last_sample;
st->samp_frac_num[channel_index] = samp_frac_num;
return out_sample;
}
static int resampler_basic_interpolate_double(SpeexResamplerState *st, spx_uint32_t channel_index, const spx_word16_t *in, spx_uint32_t *in_len, spx_word16_t *out, spx_uint32_t *out_len)
{
const int N = st->filt_len;
int out_sample = 0;
int last_sample = st->last_sample[channel_index];
spx_uint32_t samp_frac_num = st->samp_frac_num[channel_index];
const int out_stride = st->out_stride;
const int int_advance = st->int_advance;
const int frac_advance = st->frac_advance;
const spx_uint32_t den_rate = st->den_rate;
spx_word32_t sum;
while (!(last_sample >= (spx_int32_t)*in_len || out_sample >= (spx_int32_t)*out_len))
{
const spx_word16_t *iptr = & in[last_sample];
const int offset = samp_frac_num*st->oversample/st->den_rate;
#ifdef FIXED_POINT
const spx_word16_t frac = PDIV32(SHL32((samp_frac_num*st->oversample) % st->den_rate,15),st->den_rate);
#else
const spx_word16_t frac = ((float)((samp_frac_num*st->oversample) % st->den_rate))/st->den_rate;
#endif
spx_word16_t interp[4];
#ifndef OVERRIDE_INTERPOLATE_PRODUCT_DOUBLE
int j;
double accum[4] = {0,0,0,0};
for(j=0;j<N;j++) {
const double curr_in=iptr[j];
accum[0] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset-2]);
accum[1] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset-1]);
accum[2] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset]);
accum[3] += MULT16_16(curr_in,st->sinc_table[4+(j+1)*st->oversample-offset+1]);
}
cubic_coef(frac, interp);
sum = MULT16_32_Q15(interp[0],accum[0]) + MULT16_32_Q15(interp[1],accum[1]) + MULT16_32_Q15(interp[2],accum[2]) + MULT16_32_Q15(interp[3],accum[3]);
#else
cubic_coef(frac, interp);
sum = interpolate_product_double(iptr, st->sinc_table + st->oversample + 4 - offset - 2, N, st->oversample, interp);
#endif
out[out_stride * out_sample++] = PSHR32(sum,15);
last_sample += int_advance;
samp_frac_num += frac_advance;
if (samp_frac_num >= den_rate)
{
samp_frac_num -= den_rate;
last_sample++;
}
}
st->last_sample[channel_index] = last_sample;
st->samp_frac_num[channel_index] = samp_frac_num;
return out_sample;
}
static int resampler_basic_zero(SpeexResamplerState *st, spx_uint32_t channel_index, const spx_word16_t *in _U_, spx_uint32_t *in_len, spx_word16_t *out, spx_uint32_t *out_len)
{
int out_sample = 0;
int last_sample = st->last_sample[channel_index];
spx_uint32_t samp_frac_num = st->samp_frac_num[channel_index];
const int out_stride = st->out_stride;
const int int_advance = st->int_advance;
const int frac_advance = st->frac_advance;
const spx_uint32_t den_rate = st->den_rate;
while (!(last_sample >= (spx_int32_t)*in_len || out_sample >= (spx_int32_t)*out_len))
{
out[out_stride * out_sample++] = 0;
last_sample += int_advance;
samp_frac_num += frac_advance;
if (samp_frac_num >= den_rate)
{
samp_frac_num -= den_rate;
last_sample++;
}
}
st->last_sample[channel_index] = last_sample;
st->samp_frac_num[channel_index] = samp_frac_num;
return out_sample;
}
static int update_filter(SpeexResamplerState *st)
{
spx_uint32_t old_length = st->filt_len;
spx_uint32_t old_alloc_size = st->mem_alloc_size;
int use_direct;
spx_uint32_t min_sinc_table_length;
spx_uint32_t min_alloc_size;
st->int_advance = st->num_rate/st->den_rate;
st->frac_advance = st->num_rate%st->den_rate;
st->oversample = quality_map[st->quality].oversample;
st->filt_len = quality_map[st->quality].base_length;
if (st->num_rate > st->den_rate)
{
st->cutoff = quality_map[st->quality].downsample_bandwidth * st->den_rate / st->num_rate;
st->filt_len = st->filt_len*st->num_rate / st->den_rate;
st->filt_len = ((st->filt_len-1)&(~0x7))+8;
if (2*st->den_rate < st->num_rate)
st->oversample >>= 1;
if (4*st->den_rate < st->num_rate)
st->oversample >>= 1;
if (8*st->den_rate < st->num_rate)
st->oversample >>= 1;
if (16*st->den_rate < st->num_rate)
st->oversample >>= 1;
if (st->oversample < 1)
st->oversample = 1;
} else {
st->cutoff = quality_map[st->quality].upsample_bandwidth;
}
#ifdef RESAMPLE_FULL_SINC_TABLE
use_direct = 1;
if (INT_MAX/sizeof(spx_word16_t)/st->den_rate < st->filt_len)
goto fail;
#else
use_direct = st->filt_len*st->den_rate <= st->filt_len*st->oversample+8
&& INT_MAX/(spx_uint32_t)sizeof(spx_word16_t)/st->den_rate >= st->filt_len;
#endif
if (use_direct)
{
min_sinc_table_length = st->filt_len*st->den_rate;
} else {
if ((INT_MAX/(spx_uint32_t)sizeof(spx_word16_t)-8)/st->oversample < st->filt_len)
goto fail;
min_sinc_table_length = st->filt_len*st->oversample+8;
}
if (st->sinc_table_length < min_sinc_table_length)
{
spx_word16_t *sinc_table = (spx_word16_t *)speex_realloc(st->sinc_table,min_sinc_table_length*sizeof(spx_word16_t));
if (!sinc_table)
goto fail;
st->sinc_table = sinc_table;
st->sinc_table_length = min_sinc_table_length;
}
if (use_direct)
{
spx_uint32_t i;
for (i=0;i<st->den_rate;i++)
{
spx_uint32_t j;
for (j=0;j<st->filt_len;j++)
{
st->sinc_table[i*st->filt_len+j] = sinc(st->cutoff,((j-(spx_int32_t)st->filt_len/2+1)-((float)i)/st->den_rate), st->filt_len, quality_map[st->quality].window_func);
}
}
#ifdef FIXED_POINT
st->resampler_ptr = resampler_basic_direct_single;
#else
if (st->quality>8)
st->resampler_ptr = resampler_basic_direct_double;
else
st->resampler_ptr = resampler_basic_direct_single;
#endif
} else {
spx_int32_t i;
for (i=-4;i<(spx_int32_t)(st->oversample*st->filt_len+4);i++)
st->sinc_table[i+4] = sinc(st->cutoff,(i/(float)st->oversample - st->filt_len/2), st->filt_len, quality_map[st->quality].window_func);
#ifdef FIXED_POINT
st->resampler_ptr = resampler_basic_interpolate_single;
#else
if (st->quality>8)
st->resampler_ptr = resampler_basic_interpolate_double;
else
st->resampler_ptr = resampler_basic_interpolate_single;
#endif
}
min_alloc_size = st->filt_len-1 + st->buffer_size;
if (min_alloc_size > st->mem_alloc_size)
{
spx_word16_t *mem;
if (INT_MAX/(spx_uint32_t)sizeof(spx_word16_t)/st->nb_channels < min_alloc_size)
goto fail;
else if (!(mem = (spx_word16_t*)speex_realloc(st->mem, st->nb_channels*min_alloc_size * sizeof(*mem))))
goto fail;
st->mem = mem;
st->mem_alloc_size = min_alloc_size;
}
if (!st->started)
{
spx_uint32_t i;
for (i=0;i<st->nb_channels*st->mem_alloc_size;i++)
st->mem[i] = 0;
} else if (st->filt_len > old_length)
{
spx_uint32_t i;
for (i=st->nb_channels;i--;)
{
spx_uint32_t j;
spx_uint32_t olen = old_length;
{
olen = old_length + 2*st->magic_samples[i];
for (j=old_length-1+st->magic_samples[i];j--;)
st->mem[i*st->mem_alloc_size+j+st->magic_samples[i]] = st->mem[i*old_alloc_size+j];
for (j=0;j<st->magic_samples[i];j++)
st->mem[i*st->mem_alloc_size+j] = 0;
st->magic_samples[i] = 0;
}
if (st->filt_len > olen)
{
for (j=0;j<olen-1;j++)
st->mem[i*st->mem_alloc_size+(st->filt_len-2-j)] = st->mem[i*st->mem_alloc_size+(olen-2-j)];
for (;j<st->filt_len-1;j++)
st->mem[i*st->mem_alloc_size+(st->filt_len-2-j)] = 0;
st->last_sample[i] += (st->filt_len - olen)/2;
} else {
st->magic_samples[i] = (olen - st->filt_len)/2;
for (j=0;j<st->filt_len-1+st->magic_samples[i];j++)
st->mem[i*st->mem_alloc_size+j] = st->mem[i*st->mem_alloc_size+j+st->magic_samples[i]];
}
}
} else if (st->filt_len < old_length)
{
spx_uint32_t i;
for (i=0;i<st->nb_channels;i++)
{
spx_uint32_t j;
spx_uint32_t old_magic = st->magic_samples[i];
st->magic_samples[i] = (old_length - st->filt_len)/2;
for (j=0;j<st->filt_len-1+st->magic_samples[i]+old_magic;j++)
st->mem[i*st->mem_alloc_size+j] = st->mem[i*st->mem_alloc_size+j+st->magic_samples[i]];
st->magic_samples[i] += old_magic;
}
}
return RESAMPLER_ERR_SUCCESS;
fail:
st->resampler_ptr = resampler_basic_zero;
st->filt_len = old_length;
return RESAMPLER_ERR_ALLOC_FAILED;
}
EXPORT SpeexResamplerState *speex_resampler_init(spx_uint32_t nb_channels, spx_uint32_t in_rate, spx_uint32_t out_rate, int quality, int *err)
{
return speex_resampler_init_frac(nb_channels, in_rate, out_rate, in_rate, out_rate, quality, err);
}
EXPORT SpeexResamplerState *speex_resampler_init_frac(spx_uint32_t nb_channels, spx_uint32_t ratio_num, spx_uint32_t ratio_den, spx_uint32_t in_rate, spx_uint32_t out_rate, int quality, int *err)
{
spx_uint32_t i;
SpeexResamplerState *st;
int filter_err;
if (nb_channels == 0 || ratio_num == 0 || ratio_den == 0 || quality > 10 || quality < 0)
{
if (err)
*err = RESAMPLER_ERR_INVALID_ARG;
return NULL;
}
st = (SpeexResamplerState *)speex_alloc(sizeof(SpeexResamplerState));
st->initialised = 0;
st->started = 0;
st->in_rate = 0;
st->out_rate = 0;
st->num_rate = 0;
st->den_rate = 0;
st->quality = -1;
st->sinc_table_length = 0;
st->mem_alloc_size = 0;
st->filt_len = 0;
st->mem = 0;
st->resampler_ptr = 0;
st->cutoff = 1.f;
st->nb_channels = nb_channels;
st->in_stride = 1;
st->out_stride = 1;
st->buffer_size = 160;
st->last_sample = (spx_int32_t*)speex_alloc(nb_channels*sizeof(spx_int32_t));
st->magic_samples = (spx_uint32_t*)speex_alloc(nb_channels*sizeof(spx_uint32_t));
st->samp_frac_num = (spx_uint32_t*)speex_alloc(nb_channels*sizeof(spx_uint32_t));
for (i=0;i<nb_channels;i++)
{
st->last_sample[i] = 0;
st->magic_samples[i] = 0;
st->samp_frac_num[i] = 0;
}
speex_resampler_set_quality(st, quality);
speex_resampler_set_rate_frac(st, ratio_num, ratio_den, in_rate, out_rate);
filter_err = update_filter(st);
if (filter_err == RESAMPLER_ERR_SUCCESS)
{
st->initialised = 1;
} else {
speex_resampler_destroy(st);
st = NULL;
}
if (err)
*err = filter_err;
return st;
}
EXPORT void speex_resampler_destroy(SpeexResamplerState *st)
{
speex_free(st->mem);
speex_free(st->sinc_table);
speex_free(st->last_sample);
speex_free(st->magic_samples);
speex_free(st->samp_frac_num);
speex_free(st);
}
static int speex_resampler_process_native(SpeexResamplerState *st, spx_uint32_t channel_index, spx_uint32_t *in_len, spx_word16_t *out, spx_uint32_t *out_len)
{
int j=0;
const int N = st->filt_len;
int out_sample = 0;
spx_word16_t *mem = st->mem + channel_index * st->mem_alloc_size;
spx_uint32_t ilen;
st->started = 1;
out_sample = st->resampler_ptr(st, channel_index, mem, in_len, out, out_len);
if (st->last_sample[channel_index] < (spx_int32_t)*in_len)
*in_len = st->last_sample[channel_index];
*out_len = out_sample;
st->last_sample[channel_index] -= *in_len;
ilen = *in_len;
for(j=0;j<N-1;++j)
mem[j] = mem[j+ilen];
return RESAMPLER_ERR_SUCCESS;
}
static int speex_resampler_magic(SpeexResamplerState *st, spx_uint32_t channel_index, spx_word16_t **out, spx_uint32_t out_len) {
spx_uint32_t tmp_in_len = st->magic_samples[channel_index];
spx_word16_t *mem = st->mem + channel_index * st->mem_alloc_size;
const int N = st->filt_len;
speex_resampler_process_native(st, channel_index, &tmp_in_len, *out, &out_len);
st->magic_samples[channel_index] -= tmp_in_len;
if (st->magic_samples[channel_index])
{
spx_uint32_t i;
for (i=0;i<st->magic_samples[channel_index];i++)
mem[N-1+i]=mem[N-1+i+tmp_in_len];
}
*out += out_len*st->out_stride;
return out_len;
}
EXPORT int speex_resampler_process_interleaved_float(SpeexResamplerState *st, const float *in, spx_uint32_t *in_len, float *out, spx_uint32_t *out_len)
{
spx_uint32_t i;
int istride_save, ostride_save;
spx_uint32_t bak_out_len = *out_len;
spx_uint32_t bak_in_len = *in_len;
istride_save = st->in_stride;
ostride_save = st->out_stride;
st->in_stride = st->out_stride = st->nb_channels;
for (i=0;i<st->nb_channels;i++)
{
*out_len = bak_out_len;
*in_len = bak_in_len;
if (in != NULL)
speex_resampler_process_float(st, i, in+i, in_len, out+i, out_len);
else
speex_resampler_process_float(st, i, NULL, in_len, out+i, out_len);
}
st->in_stride = istride_save;
st->out_stride = ostride_save;
return st->resampler_ptr == resampler_basic_zero ? RESAMPLER_ERR_ALLOC_FAILED : RESAMPLER_ERR_SUCCESS;
}
EXPORT int speex_resampler_process_interleaved_int(SpeexResamplerState *st, const spx_int16_t *in, spx_uint32_t *in_len, spx_int16_t *out, spx_uint32_t *out_len)
{
spx_uint32_t i;
int istride_save, ostride_save;
spx_uint32_t bak_out_len = *out_len;
spx_uint32_t bak_in_len = *in_len;
istride_save = st->in_stride;
ostride_save = st->out_stride;
st->in_stride = st->out_stride = st->nb_channels;
for (i=0;i<st->nb_channels;i++)
{
*out_len = bak_out_len;
*in_len = bak_in_len;
if (in != NULL)
speex_resampler_process_int(st, i, in+i, in_len, out+i, out_len);
else
speex_resampler_process_int(st, i, NULL, in_len, out+i, out_len);
}
st->in_stride = istride_save;
st->out_stride = ostride_save;
return st->resampler_ptr == resampler_basic_zero ? RESAMPLER_ERR_ALLOC_FAILED : RESAMPLER_ERR_SUCCESS;
}
EXPORT int speex_resampler_set_rate(SpeexResamplerState *st, spx_uint32_t in_rate, spx_uint32_t out_rate)
{
return speex_resampler_set_rate_frac(st, in_rate, out_rate, in_rate, out_rate);
}
EXPORT void speex_resampler_get_rate(SpeexResamplerState *st, spx_uint32_t *in_rate, spx_uint32_t *out_rate)
{
*in_rate = st->in_rate;
*out_rate = st->out_rate;
}
EXPORT int speex_resampler_set_rate_frac(SpeexResamplerState *st, spx_uint32_t ratio_num, spx_uint32_t ratio_den, spx_uint32_t in_rate, spx_uint32_t out_rate)
{
spx_uint32_t fact;
spx_uint32_t old_den;
spx_uint32_t i;
if (ratio_num == 0 || ratio_den == 0)
return RESAMPLER_ERR_INVALID_ARG;
if (st->in_rate == in_rate && st->out_rate == out_rate && st->num_rate == ratio_num && st->den_rate == ratio_den)
return RESAMPLER_ERR_SUCCESS;
old_den = st->den_rate;
st->in_rate = in_rate;
st->out_rate = out_rate;
st->num_rate = ratio_num;
st->den_rate = ratio_den;
for (fact=2;fact<=IMIN(st->num_rate, st->den_rate);fact++)
{
while ((st->num_rate % fact == 0) && (st->den_rate % fact == 0))
{
st->num_rate /= fact;
st->den_rate /= fact;
}
}
if (old_den > 0)
{
for (i=0;i<st->nb_channels;i++)
{
st->samp_frac_num[i]=st->samp_frac_num[i]*st->den_rate/old_den;
if (st->samp_frac_num[i] >= st->den_rate)
st->samp_frac_num[i] = st->den_rate-1;
}
}
if (st->initialised)
return update_filter(st);
return RESAMPLER_ERR_SUCCESS;
}
EXPORT void speex_resampler_get_ratio(SpeexResamplerState *st, spx_uint32_t *ratio_num, spx_uint32_t *ratio_den)
{
*ratio_num = st->num_rate;
*ratio_den = st->den_rate;
}
EXPORT int speex_resampler_set_quality(SpeexResamplerState *st, int quality)
{
if (quality > 10 || quality < 0)
return RESAMPLER_ERR_INVALID_ARG;
if (st->quality == quality)
return RESAMPLER_ERR_SUCCESS;
st->quality = quality;
if (st->initialised)
return update_filter(st);
return RESAMPLER_ERR_SUCCESS;
}
EXPORT void speex_resampler_get_quality(SpeexResamplerState *st, int *quality)
{
*quality = st->quality;
}
EXPORT void speex_resampler_set_input_stride(SpeexResamplerState *st, spx_uint32_t stride)
{
st->in_stride = stride;
}
EXPORT void speex_resampler_get_input_stride(SpeexResamplerState *st, spx_uint32_t *stride)
{
*stride = st->in_stride;
}
EXPORT void speex_resampler_set_output_stride(SpeexResamplerState *st, spx_uint32_t stride)
{
st->out_stride = stride;
}
EXPORT void speex_resampler_get_output_stride(SpeexResamplerState *st, spx_uint32_t *stride)
{
*stride = st->out_stride;
}
EXPORT int speex_resampler_get_input_latency(SpeexResamplerState *st)
{
return st->filt_len / 2;
}
EXPORT int speex_resampler_get_output_latency(SpeexResamplerState *st)
{
return ((st->filt_len / 2) * st->den_rate + (st->num_rate >> 1)) / st->num_rate;
}
EXPORT int speex_resampler_skip_zeros(SpeexResamplerState *st)
{
spx_uint32_t i;
for (i=0;i<st->nb_channels;i++)
st->last_sample[i] = st->filt_len/2;
return RESAMPLER_ERR_SUCCESS;
}
EXPORT int speex_resampler_reset_mem(SpeexResamplerState *st)
{
spx_uint32_t i;
for (i=0;i<st->nb_channels;i++)
{
st->last_sample[i] = 0;
st->magic_samples[i] = 0;
st->samp_frac_num[i] = 0;
}
for (i=0;i<st->nb_channels*(st->filt_len-1);i++)
st->mem[i] = 0;
return RESAMPLER_ERR_SUCCESS;
}
EXPORT const char *speex_resampler_strerror(int err)
{
switch (err)
{
case RESAMPLER_ERR_SUCCESS:
return "Success.";
case RESAMPLER_ERR_ALLOC_FAILED:
return "Memory allocation failed.";
case RESAMPLER_ERR_BAD_STATE:
return "Bad resampler state.";
case RESAMPLER_ERR_INVALID_ARG:
return "Invalid argument.";
case RESAMPLER_ERR_PTR_OVERLAP:
return "Input and output buffers overlap.";
default:
return "Unknown error. Bad error code or strange version mismatch.";
}
}
