extern void F_1 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( V_3 , F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
}
extern void F_5 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( V_5 , F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
}
extern void F_6 ( T_1 V_1 , T_2 V_2 V_6 ) {
F_7 ( V_3 , F_3 ( V_1 ) ) ;
if ( ! F_8 ( V_1 ) )
F_9 ( L_1 , V_1 , V_4 ) ;
}
extern void F_10 ( T_1 V_1 , T_2 V_2 V_6 ) {
F_7 ( V_5 , F_3 ( V_1 ) ) ;
if ( ! F_11 ( V_1 ) )
F_9 ( L_1 , V_1 , V_4 ) ;
}
T_2 F_11 ( T_1 V_1 ) {
return ( T_2 ) F_12 ( V_3 , F_3 ( V_1 ) ) ;
}
T_2 F_8 ( T_1 V_1 ) {
return ( T_2 ) F_12 ( V_5 , F_3 ( V_1 ) ) ;
}
static void
F_13 ( T_3 * V_7 , T_4 * V_8 , T_5 * V_9 )
{
T_6 * V_10 = NULL ;
T_5 * V_11 = NULL ;
struct V_12 * V_13 ;
T_2 V_14 ;
T_7 V_15 ;
T_8 V_16 ;
T_9 V_17 ;
T_10 V_18 ;
F_14 ( V_7 , 0 , & V_16 , & V_17 , & V_18 ) ;
if( V_16 == V_19 ) {
switch( V_18 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
F_15 ( V_20 , V_7 , V_8 , V_9 ) ;
return;
break;
default:
return;
}
}
F_16 ( & V_15 , V_21 , TRUE , V_8 ) ;
V_22 = V_9 ;
V_23 = NULL ;
F_17 ( V_8 -> V_24 , V_25 , L_2 ) ;
if( V_9 ) {
V_10 = F_18 ( V_9 , V_26 , V_7 , 0 , - 1 , V_27 ) ;
V_11 = F_19 ( V_10 , V_28 ) ;
V_23 = V_11 ;
}
V_29 = NULL ;
V_30 = NULL ;
F_20 ( & V_31 ) ;
V_8 -> V_32 = & V_31 ;
V_33 = F_21 () ;
V_34 = FALSE ;
V_35 = NULL ;
F_22 ( FALSE , V_7 , 0 , & V_15 , V_11 , - 1 ) ;
if ( V_36 && ! V_34 ) {
V_13 = F_23 ( V_7 , V_8 , V_23 , V_33 ) ;
V_31 . V_37 = V_13 ;
if ( V_13 && V_29 && ! V_13 -> V_38 ) {
F_24 ( V_13 -> V_39 , V_29 , sizeof( V_13 -> V_39 ) ) ;
V_13 -> V_38 = TRUE ;
if ( ( V_14 = F_25 ( V_40 , V_29 ) ) ) {
V_13 -> V_14 = V_14 ;
V_13 -> V_41 = TRUE ;
}
}
if ( V_36 && V_13 && V_13 -> V_42 ) {
( V_13 -> V_42 ) ( V_7 , V_8 , V_23 , V_13 ) ;
}
}
}
void
F_26 ( void )
{
V_43 = F_27 ( L_3 ) ;
V_20 = F_27 ( L_4 ) ;
V_40 = F_28 ( L_5 ) ;
#include "packet-tcap-dis-tab.c"
}
void
F_29 ( void )
{
static T_11 V_44 [] = {
{ & V_45 ,
{ L_6 , L_7 ,
V_46 , V_47 , NULL , 0 ,
NULL , V_48 }
} ,
{ & V_49 ,
{ L_8 , L_9 ,
V_46 , V_50 , NULL , 0 ,
NULL , V_48 }
} ,
{ & V_51 ,
{ L_10 , L_11 ,
V_52 , V_53 , NULL , 0 ,
NULL , V_48 }
} ,
{ & V_54 ,
{ L_12 , L_13 ,
V_52 , V_53 , NULL , 0 ,
NULL , V_48 }
} ,
{ & V_55 ,
{ L_14 ,
L_15 ,
V_56 , V_50 , NULL , 0x0 ,
NULL , V_48 }
} ,
{ & V_57 ,
{ L_16 ,
L_17 ,
V_58 , V_53 , NULL , 0x0 ,
L_18 , V_48 }
} ,
{ & V_59 ,
{ L_19 ,
L_20 ,
V_58 , V_53 , NULL , 0x0 ,
L_21 , V_48 }
} ,
{ & V_60 ,
{ L_22 ,
L_23 ,
V_61 , V_53 , NULL , 0x0 ,
L_24 , V_48 }
} ,
{ & V_62 ,
{ L_25 ,
L_26 ,
V_58 , V_53 , NULL , 0x0 ,
L_27 , V_48 }
} ,
#include "packet-tcap-hfarr.c"
} ;
static T_10 * V_63 [] = {
& V_28 ,
& V_64 ,
& V_65 ,
& V_66 ,
& V_67 ,
#include "packet-tcap-ettarr.c"
} ;
T_12 * V_68 ;
V_26 = F_30 ( V_69 , V_70 , V_71 ) ;
F_31 ( V_26 , V_44 , F_32 ( V_44 ) ) ;
F_33 ( V_63 , F_32 ( V_63 ) ) ;
V_68 = F_34 ( V_26 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_35 ( V_68 , L_28 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_35 ( V_68 , L_29 ) ;
#endif
F_36 ( & V_72 , L_30 , V_73 ) ;
V_74 = F_37 () ;
F_38 ( V_68 , L_31 , L_32 ,
L_33 ,
& V_72 , V_73 ) ;
F_39 ( V_68 , L_34 ,
L_35 ,
L_36 ,
& V_36 ) ;
F_39 ( V_68 , L_37 ,
L_38 ,
L_39 ,
& V_75 ) ;
F_40 ( V_68 , L_40 ,
L_41 ,
L_42 ,
10 , & V_76 ) ;
F_40 ( V_68 , L_43 ,
L_44 ,
L_45 ,
10 , & V_77 ) ;
V_3 = F_41 ( V_78 , V_79 ) ;
V_5 = F_41 ( V_78 , V_79 ) ;
F_42 ( L_46 , F_13 , V_26 ) ;
V_4 = F_43 ( F_13 , V_26 ) ;
F_44 ( & V_80 ) ;
}
static void F_45 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_46 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_80 ( void ) {
if ( V_74 ) {
F_47 ( V_74 , F_45 ) ;
F_48 ( V_74 ) ;
}
V_74 = F_49 ( V_72 ) ;
F_47 ( V_74 , F_46 ) ;
F_50 () ;
}
static int
F_51 ( T_7 * V_81 , T_5 * V_11 , T_3 * V_7 , int V_82 )
{
T_10 V_83 , V_84 , V_85 ;
T_3 * V_86 ;
T_5 * V_87 ;
T_6 * V_88 ;
T_8 V_16 ;
T_9 V_17 ;
T_13 V_18 ;
T_1 V_89 ;
T_1 V_90 ;
T_1 V_91 ;
T_9 V_92 ;
while ( F_52 ( V_7 , V_82 ) > 0 )
{
V_84 = V_82 ;
V_82 = F_14 ( V_7 , V_82 , & V_16 , & V_17 , & V_18 ) ;
V_83 = V_82 ;
V_82 = F_53 ( V_7 , V_82 , & V_89 , & V_92 ) ;
V_85 = V_82 ;
V_90 = V_83 - V_84 ;
V_91 = V_85 - V_83 ;
if ( V_17 )
{
V_88 = F_54 ( V_11 , V_7 , V_84 ,
V_89 + ( V_85 - V_84 ) ,
L_47 ) ;
V_87 = F_19 ( V_88 , V_64 ) ;
F_55 ( V_87 , V_45 , V_7 ,
V_84 , V_90 , V_18 ,
L_48 ) ;
F_56 ( V_87 , V_45 , V_7 , V_84 ,
V_90 , V_16 ) ;
F_56 ( V_87 , V_49 , V_7 , V_83 ,
V_91 , V_89 ) ;
if ( V_89 - ( 2 * V_92 ) )
{
V_86 = F_57 ( V_7 , V_82 , V_89 - ( 2 * V_92 ) ,
V_89 - ( 2 * V_92 ) ) ;
F_51 ( V_81 , V_87 , V_86 , 0 ) ;
}
if ( V_92 )
F_54 ( V_87 , V_7 , V_82 + V_89 - 2 , 2 , L_49 ) ;
V_82 += V_89 ;
}
else
{
V_88 = F_54 ( V_11 , V_7 , V_84 ,
V_89 + ( V_85 - V_84 ) ,
L_50 , V_18 ) ;
V_87 = F_19 ( V_88 , V_64 ) ;
F_56 ( V_87 , V_45 , V_7 , V_84 ,
V_90 , V_18 ) ;
F_56 ( V_87 , V_49 , V_7 ,
V_84 + V_90 , V_91 , V_89 ) ;
if ( V_89 )
{
V_86 = F_57 ( V_7 , V_82 , V_89 , V_89 ) ;
F_58 ( TRUE , V_81 , V_11 , V_86 , 0 ,
V_51 , NULL ) ;
}
V_82 += V_89 ;
}
}
return V_82 ;
}
static void F_20 ( struct V_93 * V_94 )
{
memset ( V_94 , 0 , sizeof( struct V_93 ) ) ;
}
static int
F_59 ( T_9 T_14 V_6 , T_3 * V_7 , int V_82 , T_7 * V_81 V_6 , T_5 * V_11 , int T_15 V_6 )
{
T_2 V_14 = NULL ;
T_9 V_95 = FALSE ;
struct V_12 * V_13 = NULL ;
if ( V_36 ) {
if ( ! V_34 ) {
V_13 = F_23 ( V_7 , V_81 -> V_8 , V_23 , V_33 ) ;
V_34 = TRUE ;
V_35 = V_13 ;
V_31 . V_37 = V_13 ;
} else{
V_13 = V_35 ;
V_31 . V_37 = V_13 ;
}
}
if ( V_13 ) {
if ( V_29 ) {
if ( V_13 -> V_38 ) {
if ( strncmp ( V_13 -> V_39 , V_29 , sizeof( V_13 -> V_39 ) ) != 0 ) {
F_24 ( V_13 -> V_39 , V_29 , sizeof( V_13 -> V_39 ) ) ;
if ( ( V_14 = F_25 ( V_40 , V_29 ) ) ) {
V_13 -> V_14 = V_14 ;
V_13 -> V_41 = TRUE ;
}
}
} else {
F_24 ( V_13 -> V_39 , V_29 , sizeof( V_13 -> V_39 ) ) ;
V_13 -> V_38 = TRUE ;
if ( ( V_14
= F_25 ( V_40 , V_29 ) ) ) {
V_13 -> V_14 = V_14 ;
V_13 -> V_41 = TRUE ;
} else {
if ( ( V_14 = F_8 ( V_81 -> V_8 -> V_96 ) ) ) {
V_13 -> V_14 = V_14 ;
V_13 -> V_41 = TRUE ;
}
}
}
} else {
if ( V_13 -> V_38 ) {
V_31 . V_39 = ( void * ) V_13 -> V_39 ;
V_31 . V_97 = TRUE ;
}
}
}
if ( V_13
&& V_13 -> V_41 ) {
V_14 = V_13 -> V_14 ;
V_95 = TRUE ;
}
if ( ! V_95 && V_98 ) {
V_95 = TRUE ;
V_14 = V_98 ;
}
if ( ! V_95 ) {
if ( V_40 && V_29 ) {
if ( ( V_14
= F_25 ( V_40 , V_29 ) ) ) {
V_95 = TRUE ;
} else {
if ( ( V_14
= F_8 ( V_81 -> V_8 -> V_96 ) ) ) {
V_95 = TRUE ;
} else {
V_14 = V_43 ;
V_95 = TRUE ;
}
}
} else {
if ( ( V_14 = F_8 ( V_81 -> V_8 -> V_96 ) ) ) {
V_95 = TRUE ;
} else {
V_14 = V_43 ;
V_95 = TRUE ;
}
}
} else {
}
if ( V_95 )
F_15 ( V_14 , V_7 , V_81 -> V_8 , V_11 ) ;
return V_82 ;
}
void F_60 ( T_2 V_99 , T_3 * V_7 , T_4 * V_8 , T_5 * V_11 ) {
V_98 = V_99 ;
F_61 {
F_13 ( V_7 , V_8 , V_11 ) ;
} F_62 {
V_98 = NULL ;
V_100 ;
} V_101 ;
V_98 = NULL ;
}
