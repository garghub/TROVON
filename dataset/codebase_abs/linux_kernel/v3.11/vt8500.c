void F_1 ( enum V_1 V_2 , const char * V_3 )
{
if ( V_4 )
F_2 ( 1 , V_4 + V_5 ) ;
}
void T_1 F_3 ( void )
{
F_4 ( V_6 , F_5 ( V_6 ) ) ;
}
static void F_6 ( void )
{
F_7 () ;
F_8 ( 5 , V_4 + V_7 ) ;
asm("mcr%? p15, 0, %0, c7, c0, 4" : : "r" (0));
}
void T_1 F_9 ( void )
{
struct V_8 * V_9 ;
#if F_10 ( V_10 ) || F_10 ( V_11 )
struct V_8 * V_12 ;
void T_2 * V_13 ;
#endif
#ifdef V_10
V_12 = F_11 ( NULL , NULL , L_1 ) ;
if ( V_12 ) {
V_9 = F_11 ( NULL , NULL , L_2 ) ;
if ( V_9 ) {
V_13 = F_12 ( V_9 , 0 ) ;
if ( ! V_13 )
F_13 ( L_3 ,
V_14 ) ;
F_14 ( V_9 ) ;
} else {
V_13 = F_15 ( V_15 , 0x1000 ) ;
if ( ! V_13 )
F_13 ( L_4 ,
V_14 ) ;
}
if ( V_13 ) {
F_2 ( F_16 ( V_13 + V_16 ) | 1 ,
V_13 + V_16 ) ;
F_17 ( V_13 ) ;
} else
F_13 ( L_5 , V_14 ) ;
F_14 ( V_12 ) ;
}
#endif
#ifdef V_11
V_12 = F_11 ( NULL , NULL , L_6 ) ;
if ( V_12 ) {
V_9 = F_11 ( NULL , NULL , L_7 ) ;
if ( ! V_9 )
V_9 = F_11 ( NULL , NULL ,
L_8 ) ;
if ( V_9 ) {
V_13 = F_12 ( V_9 , 0 ) ;
if ( ! V_13 )
F_13 ( L_3 ,
V_14 ) ;
F_14 ( V_9 ) ;
} else {
V_13 = F_15 ( V_15 , 0x1000 ) ;
if ( ! V_13 )
F_13 ( L_4 ,
V_14 ) ;
}
if ( V_13 ) {
F_2 ( F_16 ( V_13 + V_16 ) |
0x80000000 , V_13 + V_16 ) ;
F_17 ( V_13 ) ;
} else
F_13 ( L_5 , V_14 ) ;
F_14 ( V_12 ) ;
}
#endif
V_9 = F_11 ( NULL , NULL , L_9 ) ;
if ( V_9 ) {
V_4 = F_12 ( V_9 , 0 ) ;
if ( ! V_4 )
F_13 ( L_10 , V_14 ) ;
F_14 ( V_9 ) ;
} else {
V_4 = F_15 ( V_17 , 0x1000 ) ;
if ( ! V_4 )
F_13 ( L_11 , V_14 ) ;
}
if ( V_4 )
V_18 = & F_6 ;
else
F_13 ( L_12 , V_14 ) ;
F_18 ( V_4 ) ;
F_19 ( NULL , V_19 , NULL , NULL ) ;
}
