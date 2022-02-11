static int F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( int V_2 , T_1 V_3 , void * * V_4 )
{
T_2 * * V_5 = ( T_2 * * ) V_4 ;
T_2 * V_6 , * V_7 ;
int V_8 , V_9 , V_10 ;
V_10 = V_2 - 3 ;
V_6 = V_5 [ V_10 + 1 ] ;
V_7 = V_5 [ V_10 + 2 ] ;
F_4 () ;
asm volatile("movq %0,%%mm0" : : "m" (raid6_mmx_constants.x1d));
asm volatile("pxor %mm5,%mm5");
for ( V_8 = 0 ; V_8 < V_3 ; V_8 += 8 ) {
asm volatile("movq %0,%%mm2" : : "m" (dptr[z0][d]));
asm volatile("movq %mm2,%mm4");
for ( V_9 = V_10 - 1 ; V_9 >= 0 ; V_9 -- ) {
asm volatile("movq %0,%%mm6" : : "m" (dptr[z][d]));
asm volatile("pcmpgtb %mm4,%mm5");
asm volatile("paddb %mm4,%mm4");
asm volatile("pand %mm0,%mm5");
asm volatile("pxor %mm5,%mm4");
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm6,%mm2");
asm volatile("pxor %mm6,%mm4");
}
asm volatile("movq %%mm2,%0" : "=m" (p[d]));
asm volatile("pxor %mm2,%mm2");
asm volatile("movq %%mm4,%0" : "=m" (q[d]));
asm volatile("pxor %mm4,%mm4");
}
F_5 () ;
}
static void F_6 ( int V_2 , T_1 V_3 , void * * V_4 )
{
T_2 * * V_5 = ( T_2 * * ) V_4 ;
T_2 * V_6 , * V_7 ;
int V_8 , V_9 , V_10 ;
V_10 = V_2 - 3 ;
V_6 = V_5 [ V_10 + 1 ] ;
V_7 = V_5 [ V_10 + 2 ] ;
F_4 () ;
asm volatile("movq %0,%%mm0" : : "m" (raid6_mmx_constants.x1d));
asm volatile("pxor %mm5,%mm5");
asm volatile("pxor %mm7,%mm7");
for ( V_8 = 0 ; V_8 < V_3 ; V_8 += 16 ) {
asm volatile("movq %0,%%mm2" : : "m" (dptr[z0][d]));
asm volatile("movq %0,%%mm3" : : "m" (dptr[z0][d+8]));
asm volatile("movq %mm2,%mm4");
asm volatile("movq %mm3,%mm6");
for ( V_9 = V_10 - 1 ; V_9 >= 0 ; V_9 -- ) {
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
asm volatile("movq %%mm2,%0" : "=m" (p[d]));
asm volatile("movq %%mm3,%0" : "=m" (p[d+8]));
asm volatile("movq %%mm4,%0" : "=m" (q[d]));
asm volatile("movq %%mm6,%0" : "=m" (q[d+8]));
}
F_5 () ;
}
