void hrt_isp_css_mm_set_user_ptr(void *userptr,
unsigned int num_pages,
enum hrt_userptr_type type)
{
my_userptr = userptr;
my_num_pages = num_pages;
my_usr_type = type;
}
static ia_css_ptr __hrt_isp_css_mm_alloc(size_t bytes, void *userptr,
unsigned int num_pages,
enum hrt_userptr_type type,
bool cached)
{
#ifdef CONFIG_ION
if (type == HRT_USR_ION)
return hmm_alloc(bytes, HMM_BO_ION, 0,
userptr, cached);
#endif
if (type == HRT_USR_PTR) {
if (userptr == NULL)
return hmm_alloc(bytes, HMM_BO_PRIVATE, 0,
0, cached);
else {
if (num_pages < ((__page_align(bytes)) >> PAGE_SHIFT))
dev_err(atomisp_dev,
"user space memory size is less"
" than the expected size..\n");
else if (num_pages > ((__page_align(bytes))
>> PAGE_SHIFT))
dev_err(atomisp_dev,
"user space memory size is"
" large than the expected size..\n");
return hmm_alloc(bytes, HMM_BO_USER, 0,
userptr, cached);
}
} else {
dev_err(atomisp_dev, "user ptr type is incorrect.\n");
return 0;
}
}
ia_css_ptr hrt_isp_css_mm_alloc(size_t bytes)
{
return __hrt_isp_css_mm_alloc(bytes, my_userptr,
my_num_pages, my_usr_type, false);
}
ia_css_ptr hrt_isp_css_mm_alloc_user_ptr(size_t bytes, void *userptr,
unsigned int num_pages,
enum hrt_userptr_type type,
bool cached)
{
return __hrt_isp_css_mm_alloc(bytes, userptr, num_pages,
type, cached);
}
ia_css_ptr hrt_isp_css_mm_alloc_cached(size_t bytes)
{
if (my_userptr == NULL)
return hmm_alloc(bytes, HMM_BO_PRIVATE, 0, 0,
HMM_CACHED);
else {
if (my_num_pages < ((__page_align(bytes)) >> PAGE_SHIFT))
dev_err(atomisp_dev,
"user space memory size is less"
" than the expected size..\n");
else if (my_num_pages > ((__page_align(bytes)) >> PAGE_SHIFT))
dev_err(atomisp_dev,
"user space memory size is"
" large than the expected size..\n");
return hmm_alloc(bytes, HMM_BO_USER, 0,
my_userptr, HMM_CACHED);
}
}
ia_css_ptr hrt_isp_css_mm_calloc(size_t bytes)
{
ia_css_ptr ptr = hrt_isp_css_mm_alloc(bytes);
if (ptr)
hmm_set(ptr, 0, bytes);
return ptr;
}
ia_css_ptr hrt_isp_css_mm_calloc_cached(size_t bytes)
{
ia_css_ptr ptr = hrt_isp_css_mm_alloc_cached(bytes);
if (ptr)
hmm_set(ptr, 0, bytes);
return ptr;
}
