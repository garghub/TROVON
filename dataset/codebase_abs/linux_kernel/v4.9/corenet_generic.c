void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
unsigned int V_2 = V_3 | V_4 |
V_5 ;
struct V_6 * V_7 ;
if ( V_8 . V_9 == V_10 )
V_2 |= V_11 ;
V_1 = F_2 ( NULL , 0 , V_2 , 0 , 512 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
V_7 = F_5 ( NULL , NULL , L_2 ) ;
if ( V_7 ) {
F_6 ( V_7 , 0 , V_12 ,
V_13 ) ;
F_7 ( V_7 ) ;
}
}
void T_1 F_8 ( void )
{
F_9 () ;
F_10 () ;
#if F_11 ( V_14 ) && F_11 ( V_15 )
F_12 ( V_16 , 1UL << ( 31 - V_17 ) ) ;
#endif
F_13 ( L_3 , V_8 . V_18 ) ;
F_14 () ;
}
int T_1 F_15 ( void )
{
return F_16 ( NULL , V_19 , NULL ) ;
}
static int T_1 F_17 ( void )
{
char V_20 [ 24 ] ;
int V_21 ;
#ifdef F_18
extern struct V_22 V_23 ;
#endif
if ( F_19 ( V_24 , V_25 ) )
return 1 ;
for ( V_21 = 0 ; V_25 [ V_21 ] ; V_21 ++ ) {
snprintf ( V_20 , sizeof( V_20 ) , L_4 , V_25 [ V_21 ] ) ;
if ( F_20 ( V_20 ) ) {
V_8 . V_26 = V_27 ;
V_8 . V_9 = V_28 ;
V_8 . V_29 = V_30 ;
V_31 = V_32 ;
V_8 . V_33 = V_32 ;
#ifdef F_18
V_23 . V_34 = NULL ;
V_23 . V_35 = NULL ;
#endif
return 1 ;
}
}
return 0 ;
}
