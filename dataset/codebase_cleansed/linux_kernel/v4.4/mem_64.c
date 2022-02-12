const char *arch_vma_name(struct vm_area_struct *vma)\r\n{\r\nif (vma->vm_mm && vma->vm_start == um_vdso_addr)\r\nreturn "[vdso]";\r\nreturn NULL;\r\n}
