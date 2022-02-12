int kfd_pasid_init(void)
{
pasid_limit = KFD_MAX_NUM_OF_PROCESSES;
pasid_bitmap = kcalloc(BITS_TO_LONGS(pasid_limit), sizeof(long),
GFP_KERNEL);
if (!pasid_bitmap)
return -ENOMEM;
set_bit(0, pasid_bitmap);
return 0;
}
void kfd_pasid_exit(void)
{
kfree(pasid_bitmap);
}
bool kfd_set_pasid_limit(unsigned int new_limit)
{
if (new_limit < pasid_limit) {
bool ok;
mutex_lock(&pasid_mutex);
ok = (find_next_bit(pasid_bitmap, pasid_limit, new_limit) ==
pasid_limit);
if (ok)
pasid_limit = new_limit;
mutex_unlock(&pasid_mutex);
return ok;
}
return true;
}
inline unsigned int kfd_get_pasid_limit(void)
{
return pasid_limit;
}
unsigned int kfd_pasid_alloc(void)
{
unsigned int found;
mutex_lock(&pasid_mutex);
found = find_first_zero_bit(pasid_bitmap, pasid_limit);
if (found == pasid_limit)
found = 0;
else
set_bit(found, pasid_bitmap);
mutex_unlock(&pasid_mutex);
return found;
}
void kfd_pasid_free(unsigned int pasid)
{
if (!WARN_ON(pasid == 0 || pasid >= pasid_limit))
clear_bit(pasid, pasid_bitmap);
}
