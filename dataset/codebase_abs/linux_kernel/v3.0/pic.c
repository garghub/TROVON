static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_6 = F_3 () ;
if ( V_6 != V_7 )
F_4 ( V_6 ) ;
V_5 -> V_8 ( & V_3 -> V_9 ) ;
}
void T_1 F_5 ( void )
{
struct V_10 * V_10 ;
struct V_11 * V_12 ;
struct V_13 V_14 ;
#ifdef F_6
struct V_11 * V_15 = NULL ;
int V_6 ;
#endif
V_12 = F_7 ( NULL , L_1 ) ;
if ( V_12 == NULL )
return;
F_8 ( V_12 , 0 , & V_14 ) ;
V_10 = F_9 ( V_12 , V_14 . V_16 ,
V_17 | V_18 |
V_19 | V_20 |
V_21 ,
0 , 256 , L_2 ) ;
F_10 ( V_12 ) ;
F_11 ( V_10 == NULL ) ;
F_12 ( V_10 ) ;
#ifdef F_6
F_13 (np, L_3 )
if ( F_14 ( V_12 , L_4 ) ) {
V_15 = V_12 ;
break;
}
if ( V_15 == NULL ) {
F_15 ( V_22 L_5 ) ;
return;
}
V_6 = F_16 ( V_15 , 0 ) ;
if ( V_6 == V_7 ) {
F_15 ( V_23 L_6 ) ;
return;
}
F_17 ( V_15 , 0 ) ;
F_10 ( V_15 ) ;
F_18 ( V_6 , F_1 ) ;
#endif
}
