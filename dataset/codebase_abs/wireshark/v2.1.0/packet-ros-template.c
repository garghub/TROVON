void
F_1 ( const char * V_1 , T_1 V_2 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_3 ( V_6 , ( V_7 ) V_1 , ( V_7 ) V_4 ) ;
if( ! V_5 )
F_4 ( V_1 , V_8 , T_2 , V_4 ) ;
}
void
F_5 ( const char * V_1 , const T_4 * V_9 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_3 ( V_10 , ( V_7 ) V_1 , ( V_7 ) V_9 ) ;
F_3 ( V_6 , ( V_7 ) V_1 , ( V_7 ) V_4 ) ;
if( ! V_5 )
F_4 ( V_1 , V_8 , T_2 , V_4 ) ;
}
static T_5 F_6 ( T_6 V_11 , const T_7 * V_12 , T_3 V_13 )
{
if( V_12 ) {
for(; V_12 -> V_14 != ( T_5 ) ( - 1 ) ; V_12 ++ )
if( V_12 -> V_15 == V_11 )
return V_13 ? V_12 -> V_14 : V_12 -> V_16 ;
}
return NULL ;
}
static T_5 F_7 ( T_6 V_17 , const T_8 * V_18 )
{
if( V_18 ) {
for(; V_18 -> V_19 != ( T_5 ) ( - 1 ) ; V_18 ++ ) {
if( V_18 -> V_17 == V_17 )
return V_18 -> V_19 ;
}
}
return NULL ;
}
static int
F_8 ( const char * V_1 , T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , struct V_23 * V_24 )
{
T_4 * V_9 ;
T_6 V_11 = 0 ;
const T_12 * V_25 = NULL ;
const T_12 * V_26 = NULL ;
T_5 V_27 = NULL ;
const T_13 * V_28 ;
T_14 * V_29 = NULL ;
T_11 * V_30 = NULL ;
if( ( V_24 != NULL ) && ( ( V_9 = ( T_4 * ) F_9 ( V_10 , V_1 ) ) != NULL ) ) {
if( V_22 ) {
V_29 = F_10 ( V_22 , * ( V_9 -> T_2 ) , V_20 , 0 , - 1 , V_31 ) ;
V_30 = F_11 ( V_29 , * ( V_9 -> V_32 ) ) ;
}
F_12 ( V_21 -> V_33 , V_34 , V_9 -> V_4 ) ;
if( ( V_24 -> V_35 & V_36 ) == V_37 ) {
if( ( V_24 -> V_35 & V_38 ) == V_39 )
V_11 = V_40 ;
else
V_11 = V_41 ;
} else
V_11 = V_24 -> V_35 & V_42 ;
V_28 = V_9 -> V_43 ;
switch( V_24 -> V_35 & V_38 ) {
case V_44 :
V_27 = F_6 ( V_11 , V_9 -> V_45 , TRUE ) ;
V_26 = L_2 ;
break;
case V_46 :
V_27 = F_6 ( V_11 , V_9 -> V_45 , FALSE ) ;
V_26 = L_3 ;
break;
case V_39 :
V_27 = F_7 ( V_11 , V_9 -> V_47 ) ;
V_28 = V_9 -> V_48 ;
break;
default:
break;
}
if( V_27 ) {
V_25 = F_13 ( V_11 , V_28 , L_4 ) ;
F_12 ( V_21 -> V_33 , V_49 , V_25 ) ;
if( V_26 )
F_14 ( V_21 -> V_33 , V_49 , V_26 ) ;
return (* V_27)( V_20 , V_21 , V_30 , NULL ) ;
}
}
return 0 ;
}
int
F_15 ( const char * V_1 , T_9 * V_20 , int V_50 , T_10 * V_21 , T_11 * V_22 , struct V_23 * V_24 )
{
T_9 * V_51 ;
int V_52 ;
V_51 = F_16 ( V_20 , V_50 ) ;
if( ( ( V_52 = F_8 ( V_1 , V_51 , V_21 , V_22 , V_24 ) ) == 0 ) &&
( ( V_52 = F_17 ( V_53 , V_1 , V_51 , V_21 , V_22 , V_24 ) ) == 0 ) ) {
T_14 * V_29 ;
T_11 * V_54 ;
V_54 = F_18 ( V_22 , V_51 , 0 , - 1 , V_55 , & V_29 ,
L_5 , V_1 ) ;
F_19 ( V_21 , V_29 , & V_56 ,
L_6 , V_1 ) ;
V_52 = F_20 ( V_21 , V_51 , V_50 , V_54 ) ;
}
V_50 += V_52 ;
return V_50 ;
}
static T_15
F_21 ( T_16 V_57 )
{
const T_17 * V_58 = ( const T_17 * ) V_57 ;
return V_58 -> V_59 ;
}
static T_18
F_22 ( T_16 V_60 , T_16 V_61 )
{
const T_17 * V_62 = ( const T_17 * ) V_60 ;
const T_17 * V_63 = ( const T_17 * ) V_61 ;
if( V_62 -> V_64 && V_63 -> V_64 && ( V_62 -> V_64 != V_63 -> V_64 ) ) {
return 0 ;
}
return V_62 -> V_59 == V_63 -> V_59 ;
}
static T_15
F_23 ( T_16 V_57 )
{
const T_17 * V_58 = ( const T_17 * ) V_57 ;
return V_58 -> V_59 ;
}
static T_18
F_24 ( T_16 V_60 , T_16 V_61 )
{
const T_17 * V_62 = ( const T_17 * ) V_60 ;
const T_17 * V_63 = ( const T_17 * ) V_61 ;
return V_62 -> V_59 == V_63 -> V_59 ;
}
static T_17 *
F_25 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , T_15 V_59 , T_3 V_65 )
{
T_17 V_66 , * V_67 = NULL ;
T_19 * V_68 = V_69 ;
V_66 . V_59 = V_59 ;
V_66 . V_70 = V_65 ;
if( V_65 ) {
V_66 . V_64 = V_21 -> V_71 ;
V_66 . V_72 = 0 ;
} else {
V_66 . V_64 = 0 ;
V_66 . V_72 = V_21 -> V_71 ;
}
V_67 = ( T_17 * ) F_9 ( V_68 -> V_73 , & V_66 ) ;
if( V_67 ) {
V_67 -> V_70 = V_66 . V_70 ;
} else {
if( V_65 ) {
V_66 . V_59 = V_59 ;
V_67 = ( T_17 * ) F_9 ( V_68 -> V_74 , & V_66 ) ;
if( V_67 ) {
F_26 ( V_68 -> V_74 , V_67 ) ;
}
if( ! V_67 ) {
V_67 = F_27 ( F_28 () , T_17 ) ;
}
V_67 -> V_59 = V_59 ;
V_67 -> V_64 = V_21 -> V_71 ;
V_67 -> V_75 = V_21 -> V_76 ;
V_67 -> V_72 = 0 ;
V_67 -> V_70 = TRUE ;
F_3 ( V_68 -> V_74 , V_67 , V_67 ) ;
return NULL ;
} else {
V_66 . V_59 = V_59 ;
V_67 = ( T_17 * ) F_9 ( V_68 -> V_74 , & V_66 ) ;
if( V_67 ) {
if( ! V_67 -> V_72 ) {
F_26 ( V_68 -> V_74 , V_67 ) ;
V_67 -> V_72 = V_21 -> V_71 ;
V_67 -> V_70 = FALSE ;
F_3 ( V_68 -> V_73 , V_67 , V_67 ) ;
}
}
}
}
if( V_67 ) {
T_14 * V_29 = NULL ;
if( V_67 -> V_70 ) {
V_29 = F_29 ( V_22 , V_77 , V_20 , 0 , 0 , V_67 -> V_72 ) ;
F_30 ( V_29 ) ;
} else {
T_20 V_78 ;
V_29 = F_29 ( V_22 , V_79 , V_20 , 0 , 0 , V_67 -> V_64 ) ;
F_30 ( V_29 ) ;
F_31 ( & V_78 , & V_21 -> V_76 , & V_67 -> V_75 ) ;
V_29 = F_32 ( V_22 , V_80 , V_20 , 0 , 0 , & V_78 ) ;
F_30 ( V_29 ) ;
}
}
return V_67 ;
}
static int
F_33 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_81 , void * V_82 )
{
int V_50 = 0 ;
int V_83 ;
T_14 * V_29 ;
T_11 * V_22 ;
T_11 * V_54 = NULL ;
T_21 * V_84 ;
T_19 * V_68 = NULL ;
T_22 V_85 ;
F_34 ( & V_85 , V_86 , TRUE , V_21 ) ;
if ( V_82 == NULL )
return 0 ;
V_85 . V_87 = V_82 ;
V_88 = V_81 ;
V_84 = F_35 ( V_21 ) ;
V_68 = ( T_19 * ) F_36 ( V_84 , V_89 ) ;
if ( V_68 == NULL ) {
V_68 = ( T_19 * ) F_37 ( sizeof( T_19 ) ) ;
V_68 -> V_73 = F_38 ( F_21 , F_22 ) ;
V_68 -> V_74 = F_38 ( F_23 , F_24 ) ;
F_39 ( V_84 , V_89 , V_68 ) ;
V_68 -> V_90 = V_69 ;
V_69 = V_68 ;
}
V_29 = F_10 ( V_81 , V_89 , V_20 , 0 , - 1 , V_31 ) ;
V_22 = F_11 ( V_29 , V_91 ) ;
F_12 ( V_21 -> V_33 , V_34 , L_7 ) ;
F_40 ( V_21 -> V_33 , V_49 ) ;
while ( F_41 ( V_20 , V_50 ) > 0 ) {
V_83 = V_50 ;
V_50 = F_42 ( FALSE , V_20 , V_50 , & V_85 , V_22 , - 1 ) ;
if( V_50 == V_83 ) {
V_54 = F_43 ( V_22 , V_20 , V_50 , - 1 , V_55 , & V_29 , L_8 ) ;
F_44 ( V_21 , V_29 , & V_92 ) ;
F_20 ( V_21 , V_20 , V_50 , V_54 ) ;
break;
}
}
return F_45 ( V_20 ) ;
}
static void
F_46 ( void )
{
T_19 * V_68 ;
for ( V_68 = V_69 ; V_68 != NULL ; ) {
T_19 * V_93 ;
F_47 ( V_68 -> V_73 ) ;
V_68 -> V_73 = NULL ;
F_47 ( V_68 -> V_74 ) ;
V_68 -> V_74 = NULL ;
V_93 = V_68 ;
V_68 = V_68 -> V_90 ;
F_48 ( V_93 ) ;
}
V_69 = NULL ;
}
void F_49 ( void ) {
static T_23 V_94 [] =
{
{ & V_77 ,
{ L_9 , L_10 ,
V_95 , V_96 , NULL , 0x0 ,
L_11 , V_97 } } ,
{ & V_79 ,
{ L_12 , L_13 ,
V_95 , V_96 , NULL , 0x0 ,
L_14 , V_97 } } ,
{ & V_80 ,
{ L_15 , L_16 ,
V_98 , V_96 , NULL , 0x0 ,
L_17 , V_97 } } ,
#include "packet-ros-hfarr.c"
} ;
static T_18 * V_99 [] = {
& V_91 ,
& V_55 ,
& V_100 ,
& V_101 ,
& V_102 ,
& V_103 ,
& V_104 ,
& V_105 ,
& V_106 ,
& V_107 ,
#include "packet-ros-ettarr.c"
} ;
static T_24 V_108 [] = {
{ & V_56 , { L_18 , V_109 , V_110 , L_19 , V_111 } } ,
{ & V_92 , { L_20 , V_109 , V_110 , L_8 , V_111 } } ,
} ;
T_25 * V_112 ;
V_89 = F_50 ( V_113 , V_114 , V_115 ) ;
F_51 ( L_21 , F_33 , V_89 ) ;
F_52 ( V_89 , V_94 , F_53 ( V_94 ) ) ;
F_54 ( V_99 , F_53 ( V_99 ) ) ;
V_112 = F_55 ( V_89 ) ;
F_56 ( V_112 , V_108 , F_53 ( V_108 ) ) ;
V_53 = F_57 ( L_1 , L_22 , V_89 , V_116 , V_96 , V_117 ) ;
V_6 = F_38 ( V_118 , V_119 ) ;
V_10 = F_38 ( V_118 , V_119 ) ;
V_8 = F_58 ( L_21 ) ;
F_59 ( F_46 ) ;
}
void F_60 ( void ) {
}
