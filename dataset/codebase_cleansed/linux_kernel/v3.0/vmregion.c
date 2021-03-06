struct arm_vmregion *
arm_vmregion_alloc(struct arm_vmregion_head *head, size_t align,
size_t size, gfp_t gfp)
{
unsigned long start = head->vm_start, addr = head->vm_end;
unsigned long flags;
struct arm_vmregion *c, *new;
if (head->vm_end - head->vm_start < size) {
printk(KERN_WARNING "%s: allocation too big (requested %#x)\n",
__func__, size);
goto out;
}
new = kmalloc(sizeof(struct arm_vmregion), gfp);
if (!new)
goto out;
spin_lock_irqsave(&head->vm_lock, flags);
addr = rounddown(addr - size, align);
list_for_each_entry_reverse(c, &head->vm_list, vm_list) {
if (addr >= c->vm_end)
goto found;
addr = rounddown(c->vm_start - size, align);
if (addr < start)
goto nospc;
}
found:
list_add(&new->vm_list, &c->vm_list);
new->vm_start = addr;
new->vm_end = addr + size;
new->vm_active = 1;
spin_unlock_irqrestore(&head->vm_lock, flags);
return new;
nospc:
spin_unlock_irqrestore(&head->vm_lock, flags);
kfree(new);
out:
return NULL;
}
static struct arm_vmregion *__arm_vmregion_find(struct arm_vmregion_head *head, unsigned long addr)
{
struct arm_vmregion *c;
list_for_each_entry(c, &head->vm_list, vm_list) {
if (c->vm_active && c->vm_start == addr)
goto out;
}
c = NULL;
out:
return c;
}
struct arm_vmregion *arm_vmregion_find(struct arm_vmregion_head *head, unsigned long addr)
{
struct arm_vmregion *c;
unsigned long flags;
spin_lock_irqsave(&head->vm_lock, flags);
c = __arm_vmregion_find(head, addr);
spin_unlock_irqrestore(&head->vm_lock, flags);
return c;
}
struct arm_vmregion *arm_vmregion_find_remove(struct arm_vmregion_head *head, unsigned long addr)
{
struct arm_vmregion *c;
unsigned long flags;
spin_lock_irqsave(&head->vm_lock, flags);
c = __arm_vmregion_find(head, addr);
if (c)
c->vm_active = 0;
spin_unlock_irqrestore(&head->vm_lock, flags);
return c;
}
void arm_vmregion_free(struct arm_vmregion_head *head, struct arm_vmregion *c)
{
unsigned long flags;
spin_lock_irqsave(&head->vm_lock, flags);
list_del(&c->vm_list);
spin_unlock_irqrestore(&head->vm_lock, flags);
kfree(c);
}
