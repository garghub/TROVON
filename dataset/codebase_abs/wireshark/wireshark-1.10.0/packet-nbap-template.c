static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_5 , V_6 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_7 , V_6 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( ! V_8 ) return 0 ;
return ( F_6 ( V_9 , V_8 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( ! V_8 ) return 0 ;
return ( F_6 ( V_10 , V_8 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( ! V_8 ) return 0 ;
return ( F_6 ( V_11 , V_8 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static void F_9 ( T_2 * V_2 , T_3 * V_3 ) {
T_5 V_12 ;
T_6 * V_13 = NULL ;
T_7 * V_14 ;
T_8 V_15 ;
if ( V_2 -> V_16 -> V_17 . V_18 ) {
return;
}
F_10 ( & V_12 , V_19 , 0 , NULL ) ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
if ( V_21 [ V_15 ] . V_22 != 0 ) {
V_13 = F_11 ( V_2 -> V_16 -> V_23 , & ( V_21 [ V_15 ] . V_24 ) , & V_12 ,
V_25 ,
V_21 [ V_15 ] . V_22 , 0 , V_26 ) ;
if ( V_13 == NULL ) {
V_13 = F_12 ( V_2 -> V_16 -> V_23 , & ( V_21 [ V_15 ] . V_24 ) ,
& V_12 , V_25 , V_21 [ V_15 ] . V_22 ,
0 , V_27 | V_28 ) ;
F_13 ( V_13 , V_29 ) ;
if( V_2 -> V_30 == V_31 ) {
V_14 = F_14 ( T_7 ) ;
V_14 -> V_32 = V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_36 = V_37 ;
V_14 -> V_38 = 0 ;
V_14 -> V_39 = V_2 -> V_16 -> V_23 ;
F_15 ( & ( V_14 -> V_24 ) , & V_21 [ V_15 ] . V_24 ) ;
V_14 -> V_22 = V_21 [ V_15 ] . V_22 ;
V_14 -> V_40 = V_15 ;
V_14 -> V_41 ++ ;
V_14 -> V_42 [ V_14 -> V_41 - 1 ] = V_15 ;
if( V_21 [ V_15 ] . V_43 == V_44 ) {
F_16 ( V_2 , V_3 , V_45 , V_46 , L_1 ) ;
} else{
V_14 -> V_47 = (enum V_48 ) V_21 [ V_15 ] . V_43 ;
}
V_14 -> V_49 = V_21 [ V_15 ] . V_49 ;
F_17 ( V_13 , V_14 ) ;
}
}
}
}
}
static T_9 F_18 ( T_10 V_50 , T_10 V_51 , T_11 T_12 V_4 ) {
if( F_19 ( V_50 ) > F_19 ( V_51 ) ) {
return - 1 ;
}
return F_19 ( V_50 ) < F_19 ( V_51 ) ;
}
static void F_20 ( void ) {
T_13 V_15 ;
if( V_52 ) {
F_21 ( V_52 ) ;
}
V_52 = F_22 ( F_18 ,
NULL ,
NULL ,
V_53 ) ;
V_54 = F_22 ( F_18 ,
NULL ,
NULL ,
V_53 ) ;
for ( V_15 = 0 ; V_15 < 15 ; V_15 ++ ) {
V_55 [ V_15 + 1 ] = * V_56 [ V_15 ] ;
}
}
static void
F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_14 * V_57 = NULL ;
T_3 * V_58 = NULL ;
int V_15 ;
F_24 ( V_2 -> V_59 , V_60 , L_2 ) ;
V_57 = F_25 ( V_3 , V_61 , V_1 , 0 , - 1 , V_62 ) ;
V_58 = F_26 ( V_57 , V_63 ) ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_21 [ V_15 ] . V_43 = V_64 ;
}
F_27 ( V_1 , V_2 , V_58 ) ;
}
void F_28 ( void )
{
T_15 * V_65 ;
T_13 V_15 ;
static T_16 V_66 [] = {
{ & V_67 ,
{ L_3 , L_4 ,
V_68 , V_69 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_71 ,
{ L_5 , L_6 ,
V_72 , V_69 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_73 ,
{ L_7 , L_8 ,
V_74 , V_69 , NULL , 0 ,
NULL , V_70 } } ,
#include "packet-nbap-hfarr.c"
} ;
static T_9 * V_75 [] = {
& V_63 ,
& V_76 ,
& V_77 ,
& V_78 ,
#include "packet-nbap-ettarr.c"
} ;
V_61 = F_29 ( V_79 , V_80 , V_81 ) ;
F_30 ( V_61 , V_66 , F_31 ( V_66 ) ) ;
F_32 ( V_75 , F_31 ( V_75 ) ) ;
F_33 ( L_9 , F_23 , V_61 ) ;
V_65 = F_34 ( V_61 , NULL ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ ) {
F_35 ( V_65 , V_82 [ V_15 ] . V_83 , V_82 [ V_15 ] . V_84 , V_82 [ V_15 ] . V_85 , V_56 [ V_15 ] , V_86 , FALSE ) ;
}
V_5 = F_36 ( L_10 , L_11 , V_87 , V_88 ) ;
V_7 = F_36 ( L_12 , L_13 , V_87 , V_88 ) ;
V_9 = F_36 ( L_14 , L_15 , V_89 , V_69 ) ;
V_10 = F_36 ( L_16 , L_17 , V_89 , V_69 ) ;
V_11 = F_36 ( L_18 , L_19 , V_89 , V_69 ) ;
F_37 ( F_20 ) ;
}
void
F_38 ( void )
{
T_17 V_90 ;
V_90 = F_39 ( L_9 ) ;
V_29 = F_39 ( L_20 ) ;
F_40 ( L_21 , V_91 , V_90 ) ;
#ifdef F_41
F_40 ( L_21 , 17 , V_90 ) ;
#endif
F_42 ( L_22 , V_90 ) ;
#include "packet-nbap-dis-tab.c"
}
