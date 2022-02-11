static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_5 , V_6 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_7 , V_8 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_9 , V_10 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_11 , V_10 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_12 , V_10 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static void
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_5 * V_13 ;
T_3 * V_14 ;
T_1 * V_15 , * V_16 ;
int V_17 = 0 ;
int V_18 ;
T_6 V_19 , V_20 , V_21 ;
V_19 = F_9 ( V_1 , V_17 ) ;
F_10 ( V_3 , V_22 , V_1 , V_17 , 1 , V_23 ) ;
V_17 ++ ;
if( V_19 > 15 ) {
return;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_14 = F_11 ( V_3 , V_1 , V_17 , 83 , V_24 , NULL ,
L_1 , V_18 + 1 ) ;
V_13 = F_10 ( V_14 , V_25 , V_1 , V_17 , 82 , V_26 ) ;
V_21 = F_9 ( V_1 , V_17 + 82 ) ;
V_15 = F_12 ( V_1 , V_17 , V_21 ) ;
V_16 = F_13 ( V_27 , V_15 , V_14 , V_2 , 0 ) ;
V_20 = F_3 ( V_16 ) ;
if ( V_16 != NULL ) {
if ( V_3 != NULL ) {
T_3 * V_28 = F_14 ( V_13 , V_29 ) ;
F_10 ( V_28 , V_30 , V_16 , 0 , V_20 , V_31 | V_26 ) ;
}
}
V_17 = V_17 + 82 ;
F_10 ( V_14 , V_32 , V_1 , V_17 , 1 , V_23 ) ;
V_17 ++ ;
}
}
static int
F_15 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_33 = NULL ;
T_3 * V_34 = NULL ;
F_16 ( V_2 -> V_35 , V_36 , V_37 ) ;
V_33 = F_10 ( V_3 , V_38 , V_1 , 0 , - 1 , V_26 ) ;
V_34 = F_14 ( V_33 , V_39 ) ;
return F_17 ( V_1 , V_2 , V_34 , NULL ) ;
}
static int
F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_7 V_40 , V_41 ;
T_8 V_42 ;
int V_43 ;
T_9 V_44 ;
T_10 V_45 ;
F_19 ( & V_45 , V_46 , TRUE , V_2 ) ;
V_42 = F_20 ( V_1 ) ;
if ( V_42 < 5 ) {
V_2 -> V_47 = 0 ;
V_2 -> V_48 = V_49 ;
return F_3 ( V_1 ) ;
}
V_43 = 24 ;
do {
V_43 = F_21 ( V_1 , V_43 , & V_45 , NULL , - 1 , & V_40 , & V_44 ) ;
V_43 += 8 * V_40 ;
V_41 = ( V_43 + 7 ) >> 3 ;
if ( V_44 ) {
V_41 += 2 ;
}
if ( V_41 > V_42 ) {
V_2 -> V_47 = 0 ;
V_2 -> V_48 = V_41 - V_42 ;
return F_3 ( V_1 ) ;
}
} while ( V_44 );
return F_15 ( V_1 , V_2 , V_3 , T_4 ) ;
}
void F_22 ( void ) {
static T_11 V_50 [] = {
{ & V_22 ,
{ L_2 , L_3 ,
V_51 , V_52 , NULL , 0 ,
NULL , V_53 } } ,
{ & V_25 ,
{ L_4 , L_5 ,
V_54 , V_55 , NULL , 0 ,
NULL , V_53 } } ,
{ & V_30 ,
{ L_6 , L_7 ,
V_56 , V_55 , NULL , 0 ,
NULL , V_53 } } ,
{ & V_32 ,
{ L_8 , L_9 ,
V_51 , V_52 , NULL , 0 ,
NULL , V_53 } } ,
#include "packet-sabp-hfarr.c"
} ;
static T_12 * V_57 [] = {
& V_39 ,
& V_58 ,
& V_59 ,
& V_60 ,
& V_61 ,
& V_62 ,
& V_24 ,
& V_29 ,
#include "packet-sabp-ettarr.c"
} ;
V_38 = F_23 ( V_63 , V_37 , V_64 ) ;
F_24 ( V_38 , V_50 , F_25 ( V_50 ) ) ;
F_26 ( V_57 , F_25 ( V_57 ) ) ;
V_65 = F_27 ( L_10 , F_15 , V_38 ) ;
V_66 = F_27 ( L_11 , F_18 , V_38 ) ;
V_5 = F_28 ( L_12 , L_13 , V_38 , V_67 , V_52 ) ;
V_7 = F_28 ( L_14 , L_15 , V_38 , V_67 , V_52 ) ;
V_9 = F_28 ( L_16 , L_17 , V_38 , V_67 , V_52 ) ;
V_11 = F_28 ( L_18 , L_19 , V_38 , V_67 , V_52 ) ;
V_12 = F_28 ( L_20 , L_21 , V_38 , V_67 , V_52 ) ;
}
void
F_29 ( void )
{
F_30 ( L_22 , V_68 , V_65 ) ;
F_30 ( L_23 , V_68 , V_66 ) ;
F_31 ( L_24 , V_69 , V_65 ) ;
#include "packet-sabp-dis-tab.c"
}
