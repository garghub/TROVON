static int F_1 ( int V_1 )
{
register unsigned long T_1 V_2 ( L_1 ) = ( V_3 ) V_4 ;
register unsigned long T_2 V_2 ( L_2 ) = V_1 ;
asm volatile(
#ifndef F_2
" diag %1,%0,0x8\n"
#else
" sam31\n"
" diag %1,%0,0x8\n"
" sam64\n"
#endif
: "+d" (reg3) : "d" (reg2) : "cc");
return T_2 ;
}
static int F_3 ( int V_1 , char * V_5 , int * V_6 )
{
register unsigned long T_1 V_2 ( L_1 ) = ( V_3 ) V_4 ;
register unsigned long T_2 V_2 ( L_2 ) = ( V_3 ) V_5 ;
register unsigned long T_3 V_2 ( L_3 ) = V_1 | 0x40000000L ;
register unsigned long T_4 V_2 ( L_4 ) = * V_6 ;
asm volatile(
#ifndef F_2
" diag %2,%0,0x8\n"
" brc 8,1f\n"
" ar %1,%4\n"
#else
" sam31\n"
" diag %2,%0,0x8\n"
" sam64\n"
" brc 8,1f\n"
" agr %1,%4\n"
#endif
"1:\n"
: "+d" (reg4), "+d" (reg5)
: "d" (reg2), "d" (reg3), "d" (*rlen) : "cc");
* V_6 = T_4 ;
return T_3 ;
}
int F_4 ( const char * V_7 , char * V_5 , int V_6 , int * V_8 )
{
int V_1 ;
int V_9 ;
int V_10 ;
V_1 = strlen ( V_7 ) ;
F_5 ( V_1 > 240 ) ;
memcpy ( V_4 , V_7 , V_1 ) ;
F_6 ( V_4 , V_1 ) ;
if ( V_5 ) {
memset ( V_5 , 0 , V_6 ) ;
V_10 = V_6 ;
V_9 = F_3 ( V_1 , V_5 , & V_6 ) ;
F_7 ( V_5 , V_10 ) ;
} else {
V_9 = F_1 ( V_1 ) ;
}
if ( V_8 )
* V_8 = V_9 ;
return V_6 ;
}
int F_8 ( const char * V_7 , char * V_5 , int V_6 , int * V_8 )
{
char * V_11 ;
int V_12 ;
unsigned long V_13 ;
if ( ( F_9 ( V_5 ) != ( unsigned long ) V_5 ) ||
( ( ( unsigned long ) V_5 + V_6 ) >> 31 ) ) {
V_11 = F_10 ( V_6 , V_14 | V_15 ) ;
if ( ! V_11 ) {
F_11 ( L_5
L_6 ) ;
return - V_16 ;
}
F_12 ( & V_17 , V_13 ) ;
V_12 = F_4 ( V_7 , V_11 , V_6 , V_8 ) ;
F_13 ( & V_17 , V_13 ) ;
memcpy ( V_5 , V_11 , V_6 ) ;
F_14 ( V_11 ) ;
} else {
F_12 ( & V_17 , V_13 ) ;
V_12 = F_4 ( V_7 , V_5 , V_6 , V_8 ) ;
F_13 ( & V_17 , V_13 ) ;
}
return V_12 ;
}
