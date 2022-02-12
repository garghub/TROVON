int get_vaddr_frames(unsigned long start, unsigned int nr_frames,
unsigned int gup_flags, struct frame_vector *vec)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
int ret = 0;
int err;
int locked;
if (nr_frames == 0)
return 0;
if (WARN_ON_ONCE(nr_frames > vec->nr_allocated))
nr_frames = vec->nr_allocated;
down_read(&mm->mmap_sem);
locked = 1;
vma = find_vma_intersection(mm, start, start + 1);
if (!vma) {
ret = -EFAULT;
goto out;
}
if (!(vma->vm_flags & (VM_IO | VM_PFNMAP))) {
vec->got_ref = true;
vec->is_pfns = false;
ret = get_user_pages_locked(start, nr_frames,
gup_flags, (struct page **)(vec->ptrs), &locked);
goto out;
}
vec->got_ref = false;
vec->is_pfns = true;
do {
unsigned long *nums = frame_vector_pfns(vec);
while (ret < nr_frames && start + PAGE_SIZE <= vma->vm_end) {
err = follow_pfn(vma, start, &nums[ret]);
if (err) {
if (ret == 0)
ret = err;
goto out;
}
start += PAGE_SIZE;
ret++;
}
if (ret >= nr_frames || start < vma->vm_end)
break;
vma = find_vma_intersection(mm, start, start + 1);
} while (vma && vma->vm_flags & (VM_IO | VM_PFNMAP));
out:
if (locked)
up_read(&mm->mmap_sem);
if (!ret)
ret = -EFAULT;
if (ret > 0)
vec->nr_frames = ret;
return ret;
}
void put_vaddr_frames(struct frame_vector *vec)
{
int i;
struct page **pages;
if (!vec->got_ref)
goto out;
pages = frame_vector_pages(vec);
if (WARN_ON(IS_ERR(pages)))
goto out;
for (i = 0; i < vec->nr_frames; i++)
put_page(pages[i]);
vec->got_ref = false;
out:
vec->nr_frames = 0;
}
int frame_vector_to_pages(struct frame_vector *vec)
{
int i;
unsigned long *nums;
struct page **pages;
if (!vec->is_pfns)
return 0;
nums = frame_vector_pfns(vec);
for (i = 0; i < vec->nr_frames; i++)
if (!pfn_valid(nums[i]))
return -EINVAL;
pages = (struct page **)nums;
for (i = 0; i < vec->nr_frames; i++)
pages[i] = pfn_to_page(nums[i]);
vec->is_pfns = false;
return 0;
}
void frame_vector_to_pfns(struct frame_vector *vec)
{
int i;
unsigned long *nums;
struct page **pages;
if (vec->is_pfns)
return;
pages = (struct page **)(vec->ptrs);
nums = (unsigned long *)pages;
for (i = 0; i < vec->nr_frames; i++)
nums[i] = page_to_pfn(pages[i]);
vec->is_pfns = true;
}
struct frame_vector *frame_vector_create(unsigned int nr_frames)
{
struct frame_vector *vec;
int size = sizeof(struct frame_vector) + sizeof(void *) * nr_frames;
if (WARN_ON_ONCE(nr_frames == 0))
return NULL;
if (WARN_ON_ONCE(nr_frames > INT_MAX / sizeof(void *) / 2))
return NULL;
vec = kvmalloc(size, GFP_KERNEL);
if (!vec)
return NULL;
vec->nr_allocated = nr_frames;
vec->nr_frames = 0;
return vec;
}
void frame_vector_destroy(struct frame_vector *vec)
{
VM_BUG_ON(vec->nr_frames > 0);
kvfree(vec);
}
