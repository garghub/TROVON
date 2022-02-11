static int F_1 ( int V_1 )
{
register unsigned long T_1 V_2 ( L_1 ) = ( V_3 ) V_4 ;
register unsigned long T_2 V_2 ( L_2 ) = V_1 ;
asm volatile(
" diag %1,%0,0x8\n"
: "+d" (reg3) : "d" (reg2) : "cc");
return T_2 ;
}
static int F_2 ( int V_1 , char * V_5 , int * V_6 )
{
register unsigned long T_1 V_2 ( L_1 ) = ( V_3 ) V_4 ;
register unsigned long T_2 V_2 ( L_2 ) = ( V_3 ) V_5 ;
register unsigned long T_3 V_2 ( L_3 ) = V_1 | 0x40000000L ;
register unsigned long T_4 V_2 ( L_4 ) = * V_6 ;
asm volatile(
" diag %2,%0,0x8\n"
" brc 8,1f\n"
" agr %1,%4\n"
"1:\n"
: "+d" (reg4), "+d" (reg5)
: "d" (reg2), "d" (reg3), "d" (*rlen) : "cc");
* V_6 = T_4 ;
return T_3 ;
}
int F_3 ( const char * V_7 , char * V_5 , int V_6 , int * V_8 )
{
int V_1 ;
int V_9 ;
int V_10 ;
V_1 = strlen ( V_7 ) ;
F_4 ( V_1 > 240 ) ;
memcpy ( V_4 , V_7 , V_1 ) ;
F_5 ( V_4 , V_1 ) ;
F_6 ( V_11 ) ;
if ( V_5 ) {
memset ( V_5 , 0 , V_6 ) ;
V_10 = V_6 ;
V_9 = F_2 ( V_1 , V_5 , & V_6 ) ;
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
unsigned long V_12 ;
char * V_13 ;
int V_14 ;
if ( F_9 ( V_5 ) ) {
V_13 = F_10 ( V_6 , V_15 ) ;
if ( ! V_13 ) {
F_11 ( L_5 ) ;
return - V_16 ;
}
F_12 ( & V_17 , V_12 ) ;
V_14 = F_3 ( V_7 , V_13 , V_6 , V_8 ) ;
F_13 ( & V_17 , V_12 ) ;
memcpy ( V_5 , V_13 , V_6 ) ;
F_14 ( V_13 ) ;
} else {
F_12 ( & V_17 , V_12 ) ;
V_14 = F_3 ( V_7 , V_5 , V_6 , V_8 ) ;
F_13 ( & V_17 , V_12 ) ;
}
return V_14 ;
}
