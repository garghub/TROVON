void F_1 ( char V_1 , const char * V_2 )
{
if ( V_3 )
F_2 ( 1 , V_3 + V_4 ) ;
}
void T_1 F_3 ( void )
{
F_4 ( V_5 , F_5 ( V_5 ) ) ;
}
static void F_6 ( void )
{
F_7 () ;
F_8 ( 5 , V_3 + V_6 ) ;
asm("mcr%? p15, 0, %0, c7, c0, 4" : : "r" (0));
}
void T_1 F_9 ( void )
{
struct V_7 * V_8 ;
#if F_10 ( V_9 ) || F_10 ( V_10 )
struct V_7 * V_11 ;
void T_2 * V_12 ;
#endif
#ifdef V_9
V_11 = F_11 ( NULL , NULL , L_1 ) ;
if ( V_11 ) {
V_8 = F_11 ( NULL , NULL , L_2 ) ;
if ( V_8 ) {
V_12 = F_12 ( V_8 , 0 ) ;
if ( ! V_12 )
F_13 ( L_3 ,
V_13 ) ;
F_14 ( V_8 ) ;
} else {
V_12 = F_15 ( V_14 , 0x1000 ) ;
if ( ! V_12 )
F_13 ( L_4 ,
V_13 ) ;
}
if ( V_12 ) {
F_2 ( F_16 ( V_12 + V_15 ) | 1 ,
V_12 + V_15 ) ;
F_17 ( V_12 ) ;
} else
F_13 ( L_5 , V_13 ) ;
F_14 ( V_11 ) ;
}
#endif
#ifdef V_10
V_11 = F_11 ( NULL , NULL , L_6 ) ;
if ( V_11 ) {
V_8 = F_11 ( NULL , NULL , L_7 ) ;
if ( ! V_8 )
V_8 = F_11 ( NULL , NULL ,
L_8 ) ;
if ( V_8 ) {
V_12 = F_12 ( V_8 , 0 ) ;
if ( ! V_12 )
F_13 ( L_3 ,
V_13 ) ;
F_14 ( V_8 ) ;
} else {
V_12 = F_15 ( V_14 , 0x1000 ) ;
if ( ! V_12 )
F_13 ( L_4 ,
V_13 ) ;
}
if ( V_12 ) {
F_2 ( F_16 ( V_12 + V_15 ) |
0x80000000 , V_12 + V_15 ) ;
F_17 ( V_12 ) ;
} else
F_13 ( L_5 , V_13 ) ;
F_14 ( V_11 ) ;
}
#endif
V_8 = F_11 ( NULL , NULL , L_9 ) ;
if ( V_8 ) {
V_3 = F_12 ( V_8 , 0 ) ;
if ( ! V_3 )
F_13 ( L_10 , V_13 ) ;
F_14 ( V_8 ) ;
} else {
V_3 = F_15 ( V_16 , 0x1000 ) ;
if ( ! V_3 )
F_13 ( L_11 , V_13 ) ;
}
if ( V_3 )
V_17 = & F_6 ;
else
F_13 ( L_12 , V_13 ) ;
F_18 ( V_3 ) ;
F_19 ( NULL , V_18 , NULL , NULL ) ;
}
