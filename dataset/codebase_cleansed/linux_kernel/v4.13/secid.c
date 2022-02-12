u32 aa_alloc_secid(void)
{
u32 secid;
spin_lock(&secid_lock);
secid = (++global_secid);
spin_unlock(&secid_lock);
return secid;
}
void aa_free_secid(u32 secid)
{
;
}
