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
struct V_19 V_20 ;
const char * const V_21 = V_15 -> V_22 ;
const int V_23 = V_15 -> V_23 ;
const struct V_24 * const V_25 = V_15 -> V_25 ;
bool V_26 = true ;
static const struct V_27 V_28 [] = {
{
. V_29 = & V_4 ,
. V_30 = 1 ,
. V_31 = sizeof( V_4 ) ,
. V_32 = & V_33 ,
. V_34 = & V_35
} ,
V_36
} ;
V_20 . V_37 = F_27 () ;
#if V_13 >= 4009
V_20 . V_38 = L_4 ;
#else
V_20 . V_38 = L_5 ;
#endif
V_20 . V_39 = 0 ;
V_20 . V_40 = V_41 ;
if ( ! F_28 ( V_17 , & V_42 ) ) {
error ( F_29 ( L_6 ) ) ;
return 1 ;
}
for ( V_18 = 0 ; V_18 < V_23 ; ++ V_18 ) {
if ( ! strcmp ( V_25 [ V_18 ] . V_43 , L_7 ) ) {
V_26 = false ;
continue;
}
error ( F_29 ( L_8 ) , V_21 , V_25 [ V_18 ] . V_43 ) ;
}
F_30 ( V_21 , V_44 , NULL , & V_45 ) ;
if ( ! V_26 )
return 0 ;
#if V_13 < 6000
F_30 ( V_21 , V_46 , & F_11 , NULL ) ;
F_30 ( V_21 , V_47 , NULL , ( void * ) & V_28 ) ;
F_30 ( V_21 , V_48 , NULL , & V_20 ) ;
#endif
return 0 ;
}
