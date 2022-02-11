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
static T_9 F_19 ( T_10 V_48 , T_10 V_49 , T_11 T_12 V_4 ) {
if( F_20 ( V_48 ) > F_20 ( V_49 ) ) {
return - 1 ;
}
return F_20 ( V_48 ) < F_20 ( V_49 ) ;
}
static void F_21 ( void ) {
T_13 V_15 ;
V_50 = F_22 ( F_19 ,
NULL ,
NULL ,
V_51 ) ;
V_52 = F_22 ( F_19 ,
NULL ,
NULL ,
V_51 ) ;
for ( V_15 = 0 ; V_15 < 15 ; V_15 ++ ) {
V_53 [ V_15 + 1 ] = V_54 [ V_15 ] ;
}
}
static void F_23 ( void ) {
F_24 ( V_50 ) ;
F_24 ( V_52 ) ;
}
static int
F_25 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_14 * V_55 = NULL ;
T_3 * V_56 = NULL ;
int V_15 ;
F_26 ( V_2 -> V_57 , V_58 , L_1 ) ;
V_55 = F_27 ( V_3 , V_59 , V_1 , 0 , - 1 , V_60 ) ;
V_56 = F_28 ( V_55 , V_61 ) ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_20 [ V_15 ] . V_42 = V_62 ;
}
return F_29 ( V_1 , V_2 , V_56 , T_4 ) ;
}
void F_30 ( void )
{
T_15 * V_63 ;
T_13 V_15 ;
static T_16 V_64 [] = {
{ & V_65 ,
{ L_2 , L_3 ,
V_66 , V_67 , NULL , 0 ,
NULL , V_68 } } ,
{ & V_69 ,
{ L_4 , L_5 ,
V_70 , V_67 , NULL , 0 ,
NULL , V_68 } } ,
{ & V_71 ,
{ L_6 , L_7 ,
V_72 , V_67 , NULL , 0 ,
NULL , V_68 } } ,
#include "packet-nbap-hfarr.c"
} ;
static T_9 * V_73 [] = {
& V_61 ,
& V_74 ,
& V_75 ,
& V_76 ,
#include "packet-nbap-ettarr.c"
} ;
static T_17 V_77 [] = {
{ & V_78 , { L_8 , V_79 , V_80 , L_9 , V_81 } } ,
{ & V_82 , { L_10 , V_79 , V_80 , L_11 , V_81 } } ,
{ & V_83 , { L_12 , V_79 , V_80 , L_13 , V_81 } } ,
{ & V_44 , { L_14 , V_79 , V_84 , L_15 , V_81 } } ,
} ;
T_18 * V_85 ;
V_59 = F_31 ( V_86 , V_87 , V_88 ) ;
F_32 ( V_59 , V_64 , F_33 ( V_64 ) ) ;
F_34 ( V_73 , F_33 ( V_73 ) ) ;
V_85 = F_35 ( V_59 ) ;
F_36 ( V_85 , V_77 , F_33 ( V_77 ) ) ;
F_37 ( L_16 , F_25 , V_59 ) ;
V_63 = F_38 ( V_59 , NULL ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ ) {
F_39 ( V_63 , V_89 [ V_15 ] . V_90 , V_89 [ V_15 ] . V_91 , V_89 [ V_15 ] . V_92 , & V_54 [ V_15 ] , V_93 , FALSE ) ;
}
V_5 = F_40 ( L_17 , L_18 , V_59 , V_94 , V_95 , V_96 ) ;
V_7 = F_40 ( L_19 , L_20 , V_59 , V_94 , V_95 , V_96 ) ;
V_9 = F_40 ( L_21 , L_22 , V_59 , V_97 , V_67 , V_96 ) ;
V_10 = F_40 ( L_23 , L_24 , V_59 , V_97 , V_67 , V_96 ) ;
V_11 = F_40 ( L_25 , L_26 , V_59 , V_97 , V_67 , V_96 ) ;
F_41 ( F_21 ) ;
F_42 ( F_23 ) ;
}
void
F_43 ( void )
{
T_19 V_98 ;
V_98 = F_44 ( L_16 ) ;
V_28 = F_44 ( L_27 ) ;
F_45 ( L_28 , V_99 , V_98 ) ;
#ifdef F_46
F_45 ( L_28 , 17 , V_98 ) ;
#endif
F_47 ( L_29 , V_98 ) ;
#include "packet-nbap-dis-tab.c"
}
