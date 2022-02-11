static unsigned int F_1 ( void )
{
T_1 V_1 ;
F_2 (bb, cfun) {
T_2 V_2 ;
T_3 * T_3 ;
T_4 V_3 = F_3 ( V_1 ) ;
if ( F_4 ( V_3 ) )
continue;
V_2 = F_5 ( V_3 ) ;
T_3 = F_6 ( F_7 ( V_4 , 0 ) ) ;
F_8 ( T_3 , F_9 ( V_2 ) ) ;
F_10 ( & V_3 , T_3 , V_5 ) ;
}
return 0 ;
}
static void F_11 ( void T_5 * V_6 , void T_5 * V_7 )
{
T_6 V_8 , V_9 ;
T_6 V_10 = F_12 ( V_11 , V_12 ) ;
V_4 = F_13 ( L_1 , V_10 ) ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) = 1 ;
F_16 ( V_4 ) = 1 ;
F_17 ( V_4 ) = 1 ;
F_18 ( V_4 ) = 1 ;
F_19 ( V_4 ) = 1 ;
F_20 ( V_4 ) = 1 ;
V_9 = F_21 ( F_22 ( L_2 ) , NULL , NULL ) ;
F_23 ( & V_4 , V_9 , 0 ) ;
F_24 ( F_25 ( V_4 ) ) ;
#if V_13 > 4005
V_8 = F_21 ( F_22 ( L_3 ) , NULL , NULL ) ;
F_23 ( & V_4 , V_8 , 0 ) ;
#endif
}
T_7 int F_26 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
int V_18 ;
const char * const V_19 = V_15 -> V_20 ;
const int V_21 = V_15 -> V_21 ;
const struct V_22 * const V_23 = V_15 -> V_23 ;
bool V_24 = true ;
static const struct V_25 V_26 [] = {
{
. V_27 = & V_4 ,
. V_28 = 1 ,
. V_29 = sizeof( V_4 ) ,
. V_30 = & V_31 ,
. V_32 = & V_33
} ,
V_34
} ;
#if V_13 >= 4009
F_27 ( V_35 , L_4 , 0 , V_36 ) ;
#else
F_27 ( V_35 , L_5 , 1 , V_36 ) ;
#endif
if ( ! F_28 ( V_17 , & V_37 ) ) {
error ( F_29 ( L_6 ) ) ;
return 1 ;
}
for ( V_18 = 0 ; V_18 < V_21 ; ++ V_18 ) {
if ( ! strcmp ( V_23 [ V_18 ] . V_38 , L_7 ) ) {
V_24 = false ;
continue;
}
error ( F_29 ( L_8 ) , V_19 , V_23 [ V_18 ] . V_38 ) ;
}
F_30 ( V_19 , V_39 , NULL , & V_40 ) ;
if ( ! V_24 )
return 0 ;
#if V_13 < 6000
F_30 ( V_19 , V_41 , & F_11 , NULL ) ;
F_30 ( V_19 , V_42 , NULL , ( void * ) & V_26 ) ;
F_30 ( V_19 , V_43 , NULL , & V_44 ) ;
#endif
return 0 ;
}
