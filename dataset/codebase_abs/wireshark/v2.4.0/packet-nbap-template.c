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
T_8 * V_15 = NULL ;
T_9 V_16 ;
if ( V_2 -> V_17 -> V_18 . V_19 ) {
return;
}
F_10 ( & V_12 ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
if ( V_21 [ V_16 ] . V_22 != 0 ) {
V_13 = F_11 ( V_2 -> V_23 , & ( V_21 [ V_16 ] . V_24 ) , & V_12 ,
V_25 ,
V_21 [ V_16 ] . V_22 , 0 , V_26 ) ;
if ( V_13 == NULL ) {
V_13 = F_12 ( V_2 -> V_23 , & ( V_21 [ V_16 ] . V_24 ) ,
& V_12 , V_25 , V_21 [ V_16 ] . V_22 ,
0 , V_27 | V_28 ) ;
F_13 ( V_13 , V_29 ) ;
if( V_2 -> V_30 == V_31 ) {
V_14 = F_14 ( F_15 () , T_7 ) ;
V_14 -> V_32 = V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_36 = V_37 ;
V_14 -> V_38 = 0 ;
V_14 -> V_39 = V_2 -> V_23 ;
F_16 ( F_15 () , & ( V_14 -> V_24 ) , & V_21 [ V_16 ] . V_24 ) ;
V_14 -> V_22 = V_21 [ V_16 ] . V_22 ;
V_15 = F_14 ( F_15 () , T_8 ) ;
V_14 -> V_40 = ( void * ) V_15 ;
V_15 -> V_41 = V_16 ;
V_14 -> V_42 ++ ;
V_14 -> V_43 [ V_14 -> V_42 - 1 ] = V_16 ;
if( V_21 [ V_16 ] . V_44 == V_45 ) {
F_17 ( V_2 , NULL , & V_46 ) ;
} else{
V_15 -> V_47 = (enum V_48 ) V_21 [ V_16 ] . V_44 ;
}
V_14 -> V_49 = V_21 [ V_16 ] . V_49 ;
F_18 ( V_13 , V_14 ) ;
}
}
}
}
}
static void F_19 ( void ) {
T_10 V_16 ;
V_50 = F_20 ( F_21 () , F_15 () ) ;
V_51 = F_20 ( F_21 () , F_15 () ) ;
V_52 = F_20 ( F_21 () , F_15 () ) ;
V_53 = F_20 ( F_21 () , F_15 () ) ;
for ( V_16 = 0 ; V_16 < 15 ; V_16 ++ ) {
V_54 [ V_16 + 1 ] = V_55 [ V_16 ] ;
}
}
static int
F_22 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_11 * V_56 = NULL ;
T_3 * V_57 = NULL ;
int V_16 ;
F_23 ( V_2 -> V_58 , V_59 , L_1 ) ;
V_56 = F_24 ( V_3 , V_60 , V_1 , 0 , - 1 , V_61 ) ;
V_57 = F_25 ( V_56 , V_62 ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_21 [ V_16 ] . V_44 = V_63 ;
}
V_64 = 0 ;
return F_26 ( V_1 , V_2 , V_57 , T_4 ) ;
}
void F_27 ( void )
{
T_12 * V_65 ;
T_10 V_16 ;
static T_13 V_66 [] = {
{ & V_67 ,
{ L_2 , L_3 ,
V_68 , V_69 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_71 ,
{ L_4 , L_5 ,
V_72 , V_69 , NULL , 0 ,
NULL , V_70 } } ,
{ & V_73 ,
{ L_6 , L_7 ,
V_74 , V_69 , NULL , 0 ,
NULL , V_70 } } ,
#include "packet-nbap-hfarr.c"
} ;
static T_14 * V_75 [] = {
& V_62 ,
& V_76 ,
& V_77 ,
& V_78 ,
#include "packet-nbap-ettarr.c"
} ;
static T_15 V_79 [] = {
{ & V_80 , { L_8 , V_81 , V_82 , L_9 , V_83 } } ,
{ & V_84 , { L_10 , V_81 , V_82 , L_11 , V_83 } } ,
{ & V_85 , { L_12 , V_81 , V_82 , L_13 , V_83 } } ,
{ & V_46 , { L_14 , V_81 , V_86 , L_15 , V_83 } } ,
} ;
T_16 * V_87 ;
V_60 = F_28 ( V_88 , V_89 , V_90 ) ;
F_29 ( V_60 , V_66 , F_30 ( V_66 ) ) ;
F_31 ( V_75 , F_30 ( V_75 ) ) ;
V_87 = F_32 ( V_60 ) ;
F_33 ( V_87 , V_79 , F_30 ( V_79 ) ) ;
V_91 = F_34 ( L_16 , F_22 , V_60 ) ;
V_65 = F_35 ( V_60 , NULL ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
F_36 ( V_65 , V_92 [ V_16 ] . V_93 , V_92 [ V_16 ] . V_94 , V_92 [ V_16 ] . V_95 , & V_55 [ V_16 ] , V_96 , FALSE ) ;
}
V_5 = F_37 ( L_17 , L_18 , V_60 , V_97 , V_98 ) ;
V_7 = F_37 ( L_19 , L_20 , V_60 , V_97 , V_98 ) ;
V_9 = F_37 ( L_21 , L_22 , V_60 , V_99 , V_69 ) ;
V_10 = F_37 ( L_23 , L_24 , V_60 , V_99 , V_69 ) ;
V_11 = F_37 ( L_25 , L_26 , V_60 , V_99 , V_69 ) ;
F_38 ( F_19 ) ;
}
void
F_39 ( void )
{
V_29 = F_40 ( L_27 ) ;
F_41 ( L_28 , V_100 , V_91 ) ;
#ifdef F_42
F_41 ( L_28 , 17 , V_91 ) ;
#endif
F_43 ( L_29 , V_91 ) ;
#include "packet-nbap-dis-tab.c"
}
