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
F_11 ( L_3 , V_8 . V_14 ) ;
F_12 () ;
}
int T_1 F_13 ( void )
{
return F_14 ( NULL , V_15 , NULL ) ;
}
static int T_1 F_15 ( void )
{
unsigned long V_16 = F_16 () ;
char V_17 [ 24 ] ;
int V_18 ;
#ifdef F_17
extern struct V_19 V_20 ;
#endif
if ( F_18 ( V_16 , V_21 ) )
return 1 ;
for ( V_18 = 0 ; V_21 [ V_18 ] ; V_18 ++ ) {
snprintf ( V_17 , sizeof( V_17 ) , L_4 , V_21 [ V_18 ] ) ;
if ( F_19 ( V_16 , V_17 ) ) {
V_8 . V_22 = V_23 ;
V_8 . V_9 = V_24 ;
V_8 . V_25 = V_26 ;
V_8 . V_27 = V_28 ;
V_8 . V_29 = V_28 ;
#ifdef F_17
V_20 . V_30 = NULL ;
V_20 . V_31 = NULL ;
#endif
return 1 ;
}
}
return 0 ;
}
