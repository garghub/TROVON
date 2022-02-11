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
V_14 = F_14 ( F_15 () , T_7 ) ;
V_14 -> V_32 = V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_36 = V_37 ;
V_14 -> V_38 = 0 ;
V_14 -> V_39 = V_2 -> V_16 -> V_23 ;
F_16 ( & ( V_14 -> V_24 ) , & V_21 [ V_15 ] . V_24 ) ;
V_14 -> V_22 = V_21 [ V_15 ] . V_22 ;
V_14 -> V_40 = V_15 ;
V_14 -> V_41 ++ ;
V_14 -> V_42 [ V_14 -> V_41 - 1 ] = V_15 ;
if( V_21 [ V_15 ] . V_43 == V_44 ) {
F_17 ( V_2 , NULL , & V_45 ) ;
} else{
V_14 -> V_46 = (enum V_47 ) V_21 [ V_15 ] . V_43 ;
}
V_14 -> V_48 = V_21 [ V_15 ] . V_48 ;
F_18 ( V_13 , V_14 ) ;
}
}
}
}
}
static T_9 F_19 ( T_10 V_49 , T_10 V_50 , T_11 T_12 V_4 ) {
if( F_20 ( V_49 ) > F_20 ( V_50 ) ) {
return - 1 ;
}
return F_20 ( V_49 ) < F_20 ( V_50 ) ;
}
static void F_21 ( void ) {
T_13 V_15 ;
if( V_51 ) {
F_22 ( V_51 ) ;
}
if( V_52 ) {
F_22 ( V_52 ) ;
}
V_51 = F_23 ( F_19 ,
NULL ,
NULL ,
V_53 ) ;
V_52 = F_23 ( F_19 ,
NULL ,
NULL ,
V_53 ) ;
for ( V_15 = 0 ; V_15 < 15 ; V_15 ++ ) {
V_54 [ V_15 + 1 ] = * V_55 [ V_15 ] ;
}
}
static void
F_24 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_14 * V_56 = NULL ;
T_3 * V_57 = NULL ;
int V_15 ;
F_25 ( V_2 -> V_58 , V_59 , L_1 ) ;
V_56 = F_26 ( V_3 , V_60 , V_1 , 0 , - 1 , V_61 ) ;
V_57 = F_27 ( V_56 , V_62 ) ;
for ( V_15 = 0 ; V_15 < V_20 ; V_15 ++ ) {
V_21 [ V_15 ] . V_43 = V_63 ;
}
F_28 ( V_1 , V_2 , V_57 ) ;
}
void F_29 ( void )
{
T_15 * V_64 ;
T_13 V_15 ;
static T_16 V_65 [] = {
{ & V_66 ,
{ L_2 , L_3 ,
V_67 , V_68 , NULL , 0 ,
NULL , V_69 } } ,
{ & V_70 ,
{ L_4 , L_5 ,
V_71 , V_68 , NULL , 0 ,
NULL , V_69 } } ,
{ & V_72 ,
{ L_6 , L_7 ,
V_73 , V_68 , NULL , 0 ,
NULL , V_69 } } ,
#include "packet-nbap-hfarr.c"
} ;
static T_9 * V_74 [] = {
& V_62 ,
& V_75 ,
& V_76 ,
& V_77 ,
#include "packet-nbap-ettarr.c"
} ;
static T_17 V_78 [] = {
{ & V_79 , { L_8 , V_80 , V_81 , L_9 , V_82 } } ,
{ & V_83 , { L_10 , V_80 , V_81 , L_11 , V_82 } } ,
{ & V_84 , { L_12 , V_80 , V_81 , L_13 , V_82 } } ,
{ & V_45 , { L_14 , V_80 , V_85 , L_15 , V_82 } } ,
} ;
T_18 * V_86 ;
V_60 = F_30 ( V_87 , V_88 , V_89 ) ;
F_31 ( V_60 , V_65 , F_32 ( V_65 ) ) ;
F_33 ( V_74 , F_32 ( V_74 ) ) ;
V_86 = F_34 ( V_60 ) ;
F_35 ( V_86 , V_78 , F_32 ( V_78 ) ) ;
F_36 ( L_16 , F_24 , V_60 ) ;
V_64 = F_37 ( V_60 , NULL ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ ) {
F_38 ( V_64 , V_90 [ V_15 ] . V_91 , V_90 [ V_15 ] . V_92 , V_90 [ V_15 ] . V_93 , V_55 [ V_15 ] , V_94 , FALSE ) ;
}
V_5 = F_39 ( L_17 , L_18 , V_95 , V_96 ) ;
V_7 = F_39 ( L_19 , L_20 , V_95 , V_96 ) ;
V_9 = F_39 ( L_21 , L_22 , V_97 , V_68 ) ;
V_10 = F_39 ( L_23 , L_24 , V_97 , V_68 ) ;
V_11 = F_39 ( L_25 , L_26 , V_97 , V_68 ) ;
F_40 ( F_21 ) ;
}
void
F_41 ( void )
{
T_19 V_98 ;
V_98 = F_42 ( L_16 ) ;
V_29 = F_42 ( L_27 ) ;
F_43 ( L_28 , V_99 , V_98 ) ;
#ifdef F_44
F_43 ( L_28 , 17 , V_98 ) ;
#endif
F_45 ( L_29 , V_98 ) ;
#include "packet-nbap-dis-tab.c"
}
