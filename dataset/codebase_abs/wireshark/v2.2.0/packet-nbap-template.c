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
return ( F_6 ( V_9 , V_8 , V_1 , V_2 , V_3 , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( ! V_8 ) return 0 ;
return ( F_6 ( V_10 , V_8 , V_1 , V_2 , V_3 , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
if ( ! V_8 ) return 0 ;
return ( F_6 ( V_11 , V_8 , V_1 , V_2 , V_3 , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static void F_9 ( T_2 * V_2 ) {
T_5 V_12 ;
T_6 * V_13 = NULL ;
T_7 * V_14 ;
T_8 V_15 ;
if ( V_2 -> V_16 -> V_17 . V_18 ) {
return;
}
F_10 ( & V_12 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
if ( V_20 [ V_15 ] . V_21 != 0 ) {
V_13 = F_11 ( V_2 -> V_22 , & ( V_20 [ V_15 ] . V_23 ) , & V_12 ,
V_24 ,
V_20 [ V_15 ] . V_21 , 0 , V_25 ) ;
if ( V_13 == NULL ) {
V_13 = F_12 ( V_2 -> V_22 , & ( V_20 [ V_15 ] . V_23 ) ,
& V_12 , V_24 , V_20 [ V_15 ] . V_21 ,
0 , V_26 | V_27 ) ;
F_13 ( V_13 , V_28 ) ;
if( V_2 -> V_29 == V_30 ) {
V_14 = F_14 ( F_15 () , T_7 ) ;
V_14 -> V_31 = V_32 ;
V_14 -> V_33 = V_34 ;
V_14 -> V_35 = V_36 ;
V_14 -> V_37 = 0 ;
V_14 -> V_38 = V_2 -> V_22 ;
F_16 ( F_15 () , & ( V_14 -> V_23 ) , & V_20 [ V_15 ] . V_23 ) ;
V_14 -> V_21 = V_20 [ V_15 ] . V_21 ;
V_14 -> V_39 = V_15 ;
V_14 -> V_40 ++ ;
V_14 -> V_41 [ V_14 -> V_40 - 1 ] = V_15 ;
if( V_20 [ V_15 ] . V_42 == V_43 ) {
F_17 ( V_2 , NULL , & V_44 ) ;
} else{
V_14 -> V_45 = (enum V_46 ) V_20 [ V_15 ] . V_42 ;
}
V_14 -> V_47 = V_20 [ V_15 ] . V_47 ;
F_18 ( V_13 , V_14 ) ;
}
}
}
}
}
static void F_19 ( void ) {
T_9 V_15 ;
V_48 = F_20 ( F_21 () , F_15 () ) ;
V_49 = F_20 ( F_21 () , F_15 () ) ;
for ( V_15 = 0 ; V_15 < 15 ; V_15 ++ ) {
V_50 [ V_15 + 1 ] = V_51 [ V_15 ] ;
}
}
static int
F_22 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_10 * V_52 = NULL ;
T_3 * V_53 = NULL ;
int V_15 ;
F_23 ( V_2 -> V_54 , V_55 , L_1 ) ;
V_52 = F_24 ( V_3 , V_56 , V_1 , 0 , - 1 , V_57 ) ;
V_53 = F_25 ( V_52 , V_58 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_20 [ V_15 ] . V_42 = V_59 ;
}
return F_26 ( V_1 , V_2 , V_53 , T_4 ) ;
}
void F_27 ( void )
{
T_11 * V_60 ;
T_9 V_15 ;
static T_12 V_61 [] = {
{ & V_62 ,
{ L_2 , L_3 ,
V_63 , V_64 , NULL , 0 ,
NULL , V_65 } } ,
{ & V_66 ,
{ L_4 , L_5 ,
V_67 , V_64 , NULL , 0 ,
NULL , V_65 } } ,
{ & V_68 ,
{ L_6 , L_7 ,
V_69 , V_64 , NULL , 0 ,
NULL , V_65 } } ,
#include "packet-nbap-hfarr.c"
} ;
static T_13 * V_70 [] = {
& V_58 ,
& V_71 ,
& V_72 ,
& V_73 ,
#include "packet-nbap-ettarr.c"
} ;
static T_14 V_74 [] = {
{ & V_75 , { L_8 , V_76 , V_77 , L_9 , V_78 } } ,
{ & V_79 , { L_10 , V_76 , V_77 , L_11 , V_78 } } ,
{ & V_80 , { L_12 , V_76 , V_77 , L_13 , V_78 } } ,
{ & V_44 , { L_14 , V_76 , V_81 , L_15 , V_78 } } ,
} ;
T_15 * V_82 ;
V_56 = F_28 ( V_83 , V_84 , V_85 ) ;
F_29 ( V_56 , V_61 , F_30 ( V_61 ) ) ;
F_31 ( V_70 , F_30 ( V_70 ) ) ;
V_82 = F_32 ( V_56 ) ;
F_33 ( V_82 , V_74 , F_30 ( V_74 ) ) ;
V_86 = F_34 ( L_16 , F_22 , V_56 ) ;
V_60 = F_35 ( V_56 , NULL ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ ) {
F_36 ( V_60 , V_87 [ V_15 ] . V_88 , V_87 [ V_15 ] . V_89 , V_87 [ V_15 ] . V_90 , & V_51 [ V_15 ] , V_91 , FALSE ) ;
}
V_5 = F_37 ( L_17 , L_18 , V_56 , V_92 , V_93 ) ;
V_7 = F_37 ( L_19 , L_20 , V_56 , V_92 , V_93 ) ;
V_9 = F_37 ( L_21 , L_22 , V_56 , V_94 , V_64 ) ;
V_10 = F_37 ( L_23 , L_24 , V_56 , V_94 , V_64 ) ;
V_11 = F_37 ( L_25 , L_26 , V_56 , V_94 , V_64 ) ;
F_38 ( F_19 ) ;
}
void
F_39 ( void )
{
V_28 = F_40 ( L_27 ) ;
F_41 ( L_28 , V_95 , V_86 ) ;
#ifdef F_42
F_41 ( L_28 , 17 , V_86 ) ;
#endif
F_43 ( L_29 , V_86 ) ;
#include "packet-nbap-dis-tab.c"
}
