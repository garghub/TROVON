T_1 long
F_1 ( unsigned * V_1 , unsigned * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 ;
if ( F_2 ( V_6 ) == V_7 ) {
F_3 ( & V_5 ) ;
} else {
asm("lsl %1,%0" : "=r" (p) : "r" (__PER_CPU_SEG));
}
if ( V_1 )
* V_1 = V_5 & 0xfff ;
if ( V_2 )
* V_2 = V_5 >> 12 ;
return 0 ;
}
