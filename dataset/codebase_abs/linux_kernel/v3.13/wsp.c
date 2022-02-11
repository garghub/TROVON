static int T_1 F_1 ( void )
{
static V_1 struct V_2 V_3 [] = {
{ . V_4 = V_5 , } ,
{ . V_4 = V_6 , } ,
{ . V_4 = V_7 , } ,
{} ,
} ;
F_2 ( NULL , V_3 , NULL ) ;
return 0 ;
}
void T_1 F_3 ( void )
{
V_8 = 50000000 ;
F_4 () ;
#ifdef F_5
F_6 () ;
#endif
#ifdef F_7
F_8 () ;
#endif
}
void T_1 F_9 ( void )
{
F_10 () ;
F_11 () ;
}
int T_1 F_12 ( void )
{
struct V_9 * V_10 ;
V_10 = F_13 ( NULL , NULL , L_1 ) ;
if ( V_10 != NULL ) {
struct V_11 V_12 ;
if ( F_14 ( V_10 , 0 , & V_12 ) == 0 )
F_15 ( L_2 , 0 , & V_12 , 1 ) ;
}
F_1 () ;
return 0 ;
}
void F_16 ( void )
{
T_2 V_13 ;
T_3 V_14 ;
struct V_9 * V_15 ;
struct V_9 * V_16 ;
struct V_9 * V_17 ;
int V_18 ;
V_17 = F_17 ( F_18 () , NULL ) ;
V_16 = F_19 ( V_17 ) ;
F_20 (dn, L_3 ) {
if ( V_15 == V_16 )
continue;
V_14 = F_21 ( V_15 , 0 , 1 ) ;
V_18 = F_22 ( V_14 , 0 , & V_13 ) ;
if ( V_18 == 0 )
F_23 ( V_14 , 0 , V_13 | 1 ) ;
F_24 ( V_14 ) ;
}
V_14 = F_21 ( V_16 , 0 , 1 ) ;
V_18 = F_22 ( V_14 , 0 , & V_13 ) ;
if ( V_18 == 0 )
F_23 ( V_14 , 0 , V_13 | 1 ) ;
F_24 ( V_14 ) ;
}
