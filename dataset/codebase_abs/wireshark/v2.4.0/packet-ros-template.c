void
F_1 ( const char * V_1 , T_1 V_2 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
if( ! V_5 )
F_3 ( V_1 , V_6 , T_2 , V_4 ) ;
}
void
F_4 ( const char * V_1 , const T_4 * V_7 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_5 ( V_8 , ( V_9 ) V_1 , ( V_9 ) V_7 ) ;
if( ! V_5 )
F_3 ( V_1 , V_6 , T_2 , V_4 ) ;
}
static T_5 F_6 ( T_6 V_10 , const T_7 * V_11 , T_3 V_12 )
{
if( V_11 ) {
for(; V_11 -> V_13 != ( T_5 ) ( - 1 ) ; V_11 ++ )
if( V_11 -> V_14 == V_10 )
return V_12 ? V_11 -> V_13 : V_11 -> V_15 ;
}
return NULL ;
}
static T_5 F_7 ( T_6 V_16 , const T_8 * V_17 )
{
if( V_17 ) {
for(; V_17 -> V_18 != ( T_5 ) ( - 1 ) ; V_17 ++ ) {
if( V_17 -> V_16 == V_16 )
return V_17 -> V_18 ;
}
}
return NULL ;
}
static int
F_8 ( const char * V_1 , T_9 * V_19 , T_10 * V_20 , T_11 * V_21 , struct V_22 * V_23 )
{
T_4 * V_7 ;
T_6 V_10 = 0 ;
const T_12 * V_24 = NULL ;
const T_12 * V_25 = NULL ;
T_5 V_26 = NULL ;
const T_13 * V_27 ;
T_14 * V_28 = NULL ;
T_11 * V_29 = NULL ;
if( ( V_23 != NULL ) && ( V_1 != NULL ) && ( ( V_7 = ( T_4 * ) F_9 ( V_8 , V_1 ) ) != NULL ) ) {
if( V_21 ) {
V_28 = F_10 ( V_21 , * ( V_7 -> T_2 ) , V_19 , 0 , - 1 , V_30 ) ;
V_29 = F_11 ( V_28 , * ( V_7 -> V_31 ) ) ;
}
F_12 ( V_20 -> V_32 , V_33 , V_7 -> V_4 ) ;
if( ( V_23 -> V_34 & V_35 ) == V_36 ) {
if( ( V_23 -> V_34 & V_37 ) == V_38 )
V_10 = V_39 ;
else
V_10 = V_40 ;
} else
V_10 = V_23 -> V_34 & V_41 ;
V_27 = V_7 -> V_42 ;
switch( V_23 -> V_34 & V_37 ) {
case V_43 :
V_26 = F_6 ( V_10 , V_7 -> V_44 , TRUE ) ;
V_25 = L_2 ;
break;
case V_45 :
V_26 = F_6 ( V_10 , V_7 -> V_44 , FALSE ) ;
V_25 = L_3 ;
break;
case V_38 :
V_26 = F_7 ( V_10 , V_7 -> V_46 ) ;
V_27 = V_7 -> V_47 ;
break;
default:
break;
}
if( V_26 ) {
V_24 = F_13 ( V_10 , V_27 , L_4 ) ;
F_12 ( V_20 -> V_32 , V_48 , V_24 ) ;
if( V_25 )
F_14 ( V_20 -> V_32 , V_48 , V_25 ) ;
return (* V_26)( V_19 , V_20 , V_29 , NULL ) ;
}
}
return 0 ;
}
int
F_15 ( const char * V_1 , T_9 * V_19 , int V_49 , T_10 * V_20 , T_11 * V_21 , struct V_22 * V_23 )
{
T_9 * V_50 ;
int V_51 ;
V_50 = F_16 ( V_19 , V_49 ) ;
if( ( ( V_51 = F_8 ( V_1 , V_50 , V_20 , V_21 , V_23 ) ) == 0 ) &&
( ( V_51 = F_17 ( V_52 , V_1 , V_50 , V_20 , V_21 , V_23 ) ) == 0 ) ) {
T_14 * V_28 ;
T_11 * V_53 ;
V_53 = F_18 ( V_21 , V_50 , 0 , - 1 , V_54 , & V_28 ,
L_5 , V_1 ) ;
F_19 ( V_20 , V_28 , & V_55 ,
L_6 , V_1 ) ;
V_51 = F_20 ( V_20 , V_50 , V_49 , V_53 ) ;
}
V_49 += V_51 ;
return V_49 ;
}
static T_15
F_21 ( T_16 V_56 )
{
const T_17 * V_57 = ( const T_17 * ) V_56 ;
return V_57 -> V_58 ;
}
static T_18
F_22 ( T_16 V_59 , T_16 V_60 )
{
const T_17 * V_61 = ( const T_17 * ) V_59 ;
const T_17 * V_62 = ( const T_17 * ) V_60 ;
if( V_61 -> V_63 && V_62 -> V_63 && ( V_61 -> V_63 != V_62 -> V_63 ) ) {
return 0 ;
}
return V_61 -> V_58 == V_62 -> V_58 ;
}
static T_15
F_23 ( T_16 V_56 )
{
const T_17 * V_57 = ( const T_17 * ) V_56 ;
return V_57 -> V_58 ;
}
static T_18
F_24 ( T_16 V_59 , T_16 V_60 )
{
const T_17 * V_61 = ( const T_17 * ) V_59 ;
const T_17 * V_62 = ( const T_17 * ) V_60 ;
return V_61 -> V_58 == V_62 -> V_58 ;
}
static T_17 *
F_25 ( T_9 * V_19 , T_10 * V_20 , T_11 * V_21 , T_15 V_58 , T_3 V_64 )
{
T_17 V_65 , * V_66 = NULL ;
T_19 * V_67 ;
T_20 * V_68 ;
V_68 = F_26 ( V_20 -> V_69 , & V_20 -> V_70 , & V_20 -> V_71 ,
V_20 -> V_72 , V_20 -> V_73 ,
V_20 -> V_74 , 0 ) ;
if ( V_68 == NULL )
return NULL ;
V_67 = ( T_19 * ) F_27 ( V_68 , V_75 ) ;
if ( V_67 == NULL )
return NULL ;
V_65 . V_58 = V_58 ;
V_65 . V_76 = V_64 ;
if( V_64 ) {
V_65 . V_63 = V_20 -> V_69 ;
V_65 . V_77 = 0 ;
} else {
V_65 . V_63 = 0 ;
V_65 . V_77 = V_20 -> V_69 ;
}
V_66 = ( T_17 * ) F_9 ( V_67 -> V_78 , & V_65 ) ;
if( V_66 ) {
V_66 -> V_76 = V_65 . V_76 ;
} else {
if( V_64 ) {
V_65 . V_58 = V_58 ;
V_66 = ( T_17 * ) F_9 ( V_67 -> V_79 , & V_65 ) ;
if( V_66 ) {
F_28 ( V_67 -> V_79 , V_66 ) ;
}
if( ! V_66 ) {
V_66 = F_29 ( F_30 () , T_17 ) ;
}
V_66 -> V_58 = V_58 ;
V_66 -> V_63 = V_20 -> V_69 ;
V_66 -> V_80 = V_20 -> V_81 ;
V_66 -> V_77 = 0 ;
V_66 -> V_76 = TRUE ;
F_5 ( V_67 -> V_79 , V_66 , V_66 ) ;
return NULL ;
} else {
V_65 . V_58 = V_58 ;
V_66 = ( T_17 * ) F_9 ( V_67 -> V_79 , & V_65 ) ;
if( V_66 ) {
if( ! V_66 -> V_77 ) {
F_28 ( V_67 -> V_79 , V_66 ) ;
V_66 -> V_77 = V_20 -> V_69 ;
V_66 -> V_76 = FALSE ;
F_5 ( V_67 -> V_78 , V_66 , V_66 ) ;
}
}
}
}
if( V_66 ) {
T_14 * V_28 = NULL ;
if( V_66 -> V_76 ) {
V_28 = F_31 ( V_21 , V_82 , V_19 , 0 , 0 , V_66 -> V_77 ) ;
F_32 ( V_28 ) ;
} else {
T_21 V_83 ;
V_28 = F_31 ( V_21 , V_84 , V_19 , 0 , 0 , V_66 -> V_63 ) ;
F_32 ( V_28 ) ;
F_33 ( & V_83 , & V_20 -> V_81 , & V_66 -> V_80 ) ;
V_28 = F_34 ( V_21 , V_85 , V_19 , 0 , 0 , & V_83 ) ;
F_32 ( V_28 ) ;
}
}
return V_66 ;
}
static int
F_35 ( T_9 * V_19 , T_10 * V_20 , T_11 * V_86 , void * V_87 )
{
int V_49 = 0 ;
int V_88 ;
T_14 * V_28 ;
T_11 * V_21 ;
T_11 * V_53 = NULL ;
T_20 * V_68 ;
T_19 * V_67 = NULL ;
T_22 V_89 ;
F_36 ( & V_89 , V_90 , TRUE , V_20 ) ;
if ( V_87 == NULL )
return 0 ;
V_89 . V_91 = V_87 ;
V_92 = V_86 ;
V_68 = F_37 ( V_20 ) ;
V_67 = ( T_19 * ) F_27 ( V_68 , V_75 ) ;
if ( V_67 == NULL ) {
V_67 = ( T_19 * ) F_38 ( F_30 () , T_19 ) ;
V_67 -> V_78 = F_39 ( F_30 () , F_21 , F_22 ) ;
V_67 -> V_79 = F_39 ( F_30 () , F_23 , F_24 ) ;
F_40 ( V_68 , V_75 , V_67 ) ;
}
V_28 = F_10 ( V_86 , V_75 , V_19 , 0 , - 1 , V_30 ) ;
V_21 = F_11 ( V_28 , V_93 ) ;
F_12 ( V_20 -> V_32 , V_33 , L_7 ) ;
F_41 ( V_20 -> V_32 , V_48 ) ;
while ( F_42 ( V_19 , V_49 ) > 0 ) {
V_88 = V_49 ;
V_49 = F_43 ( FALSE , V_19 , V_49 , & V_89 , V_21 , - 1 ) ;
if( V_49 == V_88 ) {
V_53 = F_44 ( V_21 , V_19 , V_49 , - 1 , V_54 , & V_28 , L_8 ) ;
F_45 ( V_20 , V_28 , & V_94 ) ;
F_20 ( V_20 , V_19 , V_49 , V_53 ) ;
break;
}
}
return F_46 ( V_19 ) ;
}
void F_47 ( void ) {
static T_23 V_95 [] =
{
{ & V_82 ,
{ L_9 , L_10 ,
V_96 , V_97 , NULL , 0x0 ,
L_11 , V_98 } } ,
{ & V_84 ,
{ L_12 , L_13 ,
V_96 , V_97 , NULL , 0x0 ,
L_14 , V_98 } } ,
{ & V_85 ,
{ L_15 , L_16 ,
V_99 , V_97 , NULL , 0x0 ,
L_17 , V_98 } } ,
#include "packet-ros-hfarr.c"
} ;
static T_18 * V_100 [] = {
& V_93 ,
& V_54 ,
& V_101 ,
& V_102 ,
& V_103 ,
& V_104 ,
& V_105 ,
& V_106 ,
& V_107 ,
& V_108 ,
#include "packet-ros-ettarr.c"
} ;
static T_24 V_109 [] = {
{ & V_55 , { L_18 , V_110 , V_111 , L_19 , V_112 } } ,
{ & V_94 , { L_20 , V_110 , V_111 , L_8 , V_112 } } ,
} ;
T_25 * V_113 ;
V_75 = F_48 ( V_114 , V_115 , V_116 ) ;
V_6 = F_49 ( L_21 , F_35 , V_75 ) ;
F_50 ( V_75 , V_95 , F_51 ( V_95 ) ) ;
F_52 ( V_100 , F_51 ( V_100 ) ) ;
V_113 = F_53 ( V_75 ) ;
F_54 ( V_113 , V_109 , F_51 ( V_109 ) ) ;
V_52 = F_55 ( L_1 , L_22 , V_75 , V_117 , V_97 ) ;
V_8 = F_39 ( F_56 () , V_118 , V_119 ) ;
}
void F_57 ( void ) {
}
