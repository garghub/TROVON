static int F_1 ( void )
{
return F_2 ( V_1 ) &&
( F_2 ( V_2 ) ||
F_2 ( V_3 ) ) ;
}
static void F_3 ( int V_4 , T_1 V_5 , void * * V_6 )
{
T_2 * * V_7 = ( T_2 * * ) V_6 ;
T_2 * V_8 , * V_9 ;
int V_10 , V_11 , V_12 ;
V_12 = V_4 - 3 ;
V_8 = V_7 [ V_12 + 1 ] ;
V_9 = V_7 [ V_12 + 2 ] ;
F_4 () ;
asm volatile("movq %0,%%mm0" : : "m" (raid6_mmx_constants.x1d));
asm volatile("pxor %mm5,%mm5");
for ( V_10 = 0 ; V_10 < V_5 ; V_10 += 8 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm2" : : "m" (dptr[z0][d]));
asm volatile("prefetchnta %0" : : "m" (dptr[z0-1][d]));
asm volatile("movq %mm2,%mm4");
asm volatile("movq %0,%%mm6" : : "m" (dptr[z0-1][d]));
for ( V_11 = V_12 - 2 ; V_11 >= 0 ; V_11 -- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("paddb %mm4,%mm4");
asm volatile("pand %mm0,%mm5");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm6,%mm2");
asm volatile("pxor %mm6,%mm4");
asm volatile("movq %0,%%mm6" : : "m" (dptr[z][d]));
}
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("paddb %mm4,%mm4");
asm volatile("pand %mm0,%mm5");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm6,%mm2");
asm volatile("pxor %mm6,%mm4");
asm volatile("movntq %%mm2,%0" : "=m" (p[d]));
asm volatile("movntq %%mm4,%0" : "=m" (q[d]));
}
asm volatile("sfence" : : : "memory");
F_5 () ;
}
static void F_6 ( int V_4 , T_1 V_5 , void * * V_6 )
{
T_2 * * V_7 = ( T_2 * * ) V_6 ;
T_2 * V_8 , * V_9 ;
int V_10 , V_11 , V_12 ;
V_12 = V_4 - 3 ;
V_8 = V_7 [ V_12 + 1 ] ;
V_9 = V_7 [ V_12 + 2 ] ;
F_4 () ;
asm volatile("movq %0,%%mm0" : : "m" (raid6_mmx_constants.x1d));
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm7,%mm7");
for ( V_10 = 0 ; V_10 < V_5 ; V_10 += 16 ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm2" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm3" : : "m" (dptr[z0][d+8]));
asm volatile("movq %mm2,%mm4");
asm volatile("movq %mm3,%mm6");
for ( V_11 = V_12 - 1 ; V_11 >= 0 ; V_11 -- ) {
asm volatile("prefetchnta %0" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("pcmpgtb %mm6,%mm7");
asm volatile("paddb %mm4,%mm4");
asm volatile("paddb %mm6,%mm6");
asm volatile("pand %mm0,%mm5");
asm volatile("pand %mm0,%mm7");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm7,%mm6");
asm volatile("movq %0,%%mm5" : : "m" (dptr[z][d]));
asm volatile("movq %0,%%mm7" : : "m" (dptr[z][d+8]));
asm volatile("pxor %mm5,%mm2");
asm volatile("pxor %mm7,%mm3");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm7,%mm6");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm7,%mm7");
}
asm volatile("movntq %%mm2,%0" : "=m" (p[d]));
asm volatile("movntq %%mm3,%0" : "=m" (p[d+8]));
asm volatile("movntq %%mm4,%0" : "=m" (q[d]));
asm volatile("movntq %%mm6,%0" : "=m" (q[d+8]));
}
asm volatile("sfence" : :: "memory");
F_5 () ;
}
