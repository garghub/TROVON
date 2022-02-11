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
static T_3 F_8 ( const char * V_1 , T_9 * V_20 , T_10 * V_21 , T_11 * V_22 )
{
T_4 * V_9 ;
T_6 V_11 = 0 ;
const T_12 * V_23 = NULL ;
const T_12 * V_24 = NULL ;
T_5 V_25 = NULL ;
const T_13 * V_26 ;
T_14 * V_27 = NULL ;
T_11 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
V_30 = ( (struct V_29 * ) ( V_21 -> V_31 ) ) ;
if( ( V_30 != NULL ) && ( ( V_9 = ( T_4 * ) F_9 ( V_10 , V_1 ) ) != NULL ) ) {
if( V_22 ) {
V_27 = F_10 ( V_22 , * ( V_9 -> T_2 ) , V_20 , 0 , - 1 , V_32 ) ;
V_28 = F_11 ( V_27 , * ( V_9 -> V_33 ) ) ;
}
F_12 ( V_21 -> V_34 , V_35 , V_9 -> V_4 ) ;
if( ( V_30 -> V_36 & V_37 ) == V_38 ) {
if( ( V_30 -> V_36 & V_39 ) == V_40 )
V_11 = V_41 ;
else
V_11 = V_42 ;
} else
V_11 = V_30 -> V_36 & V_43 ;
V_26 = V_9 -> V_44 ;
switch( V_30 -> V_36 & V_39 ) {
case V_45 :
V_25 = F_6 ( V_11 , V_9 -> V_46 , TRUE ) ;
V_24 = L_2 ;
break;
case V_47 :
V_25 = F_6 ( V_11 , V_9 -> V_46 , FALSE ) ;
V_24 = L_3 ;
break;
case V_40 :
V_25 = F_7 ( V_11 , V_9 -> V_48 ) ;
V_26 = V_9 -> V_49 ;
break;
default:
break;
}
if( V_25 ) {
V_23 = F_13 ( V_11 , V_26 , L_4 ) ;
if ( F_14 ( V_21 -> V_34 , V_50 ) ) {
F_12 ( V_21 -> V_34 , V_50 , V_23 ) ;
if( V_24 )
F_15 ( V_21 -> V_34 , V_50 , V_24 ) ;
}
(* V_25)( V_20 , V_21 , V_28 , NULL ) ;
return TRUE ;
}
}
return FALSE ;
}
int
F_16 ( const char * V_1 , T_9 * V_20 , int V_51 , T_10 * V_21 , T_11 * V_22 )
{
T_9 * V_52 ;
V_52 = F_17 ( V_20 , V_51 ) ;
if( ! F_8 ( V_1 , V_52 , V_21 , V_22 ) &&
! F_18 ( V_53 , V_1 , V_52 , V_21 , V_22 ) ) {
T_14 * V_27 = F_19 ( V_22 , V_52 , 0 , F_20 ( V_20 , V_51 ) , L_5 , V_1 ) ;
T_11 * V_54 = F_11 ( V_27 , V_55 ) ;
F_21 ( V_21 , V_27 , V_56 , V_57 ,
L_6 , V_1 ) ;
F_22 ( V_21 , V_52 , V_51 , V_54 ) ;
}
V_51 += F_20 ( V_20 , V_51 ) ;
return V_51 ;
}
static T_15
F_23 ( T_16 V_58 )
{
const T_17 * V_59 = ( const T_17 * ) V_58 ;
return V_59 -> V_60 ;
}
static T_18
F_24 ( T_16 V_61 , T_16 V_62 )
{
const T_17 * V_63 = ( const T_17 * ) V_61 ;
const T_17 * V_64 = ( const T_17 * ) V_62 ;
if( V_63 -> V_65 && V_64 -> V_65 && ( V_63 -> V_65 != V_64 -> V_65 ) ) {
return 0 ;
}
return V_63 -> V_60 == V_64 -> V_60 ;
}
static T_15
F_25 ( T_16 V_58 )
{
const T_17 * V_59 = ( const T_17 * ) V_58 ;
return V_59 -> V_60 ;
}
static T_18
F_26 ( T_16 V_61 , T_16 V_62 )
{
const T_17 * V_63 = ( const T_17 * ) V_61 ;
const T_17 * V_64 = ( const T_17 * ) V_62 ;
return V_63 -> V_60 == V_64 -> V_60 ;
}
static T_17 *
F_27 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , T_15 V_60 , T_3 V_66 )
{
T_17 V_67 , * V_68 = NULL ;
T_19 * V_69 = V_70 ;
V_67 . V_60 = V_60 ;
V_67 . V_71 = V_66 ;
if( V_66 ) {
V_67 . V_65 = V_21 -> V_72 -> V_73 ;
V_67 . V_74 = 0 ;
} else {
V_67 . V_65 = 0 ;
V_67 . V_74 = V_21 -> V_72 -> V_73 ;
}
V_68 = ( T_17 * ) F_9 ( V_69 -> V_75 , & V_67 ) ;
if( V_68 ) {
V_68 -> V_71 = V_67 . V_71 ;
} else {
if( V_66 ) {
V_67 . V_60 = V_60 ;
V_68 = ( T_17 * ) F_9 ( V_69 -> V_76 , & V_67 ) ;
if( V_68 ) {
F_28 ( V_69 -> V_76 , V_68 ) ;
}
if( ! V_68 ) {
V_68 = F_29 ( T_17 ) ;
}
V_68 -> V_60 = V_60 ;
V_68 -> V_65 = V_21 -> V_72 -> V_73 ;
V_68 -> V_77 = V_21 -> V_72 -> V_78 ;
V_68 -> V_74 = 0 ;
V_68 -> V_71 = TRUE ;
F_3 ( V_69 -> V_76 , V_68 , V_68 ) ;
return NULL ;
} else {
V_67 . V_60 = V_60 ;
V_68 = ( T_17 * ) F_9 ( V_69 -> V_76 , & V_67 ) ;
if( V_68 ) {
if( ! V_68 -> V_74 ) {
F_28 ( V_69 -> V_76 , V_68 ) ;
V_68 -> V_74 = V_21 -> V_72 -> V_73 ;
V_68 -> V_71 = FALSE ;
F_3 ( V_69 -> V_75 , V_68 , V_68 ) ;
}
}
}
}
if( V_68 ) {
T_14 * V_27 = NULL ;
if( V_68 -> V_71 ) {
V_27 = F_30 ( V_22 , V_79 , V_20 , 0 , 0 , V_68 -> V_74 ) ;
F_31 ( V_27 ) ;
} else {
T_20 V_80 ;
V_27 = F_30 ( V_22 , V_81 , V_20 , 0 , 0 , V_68 -> V_65 ) ;
F_31 ( V_27 ) ;
F_32 ( & V_80 , & V_21 -> V_72 -> V_78 , & V_68 -> V_77 ) ;
V_27 = F_33 ( V_22 , V_82 , V_20 , 0 , 0 , & V_80 ) ;
F_31 ( V_27 ) ;
}
}
return V_68 ;
}
static void
F_34 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_83 )
{
int V_51 = 0 ;
int V_84 ;
T_14 * V_27 = NULL ;
T_11 * V_22 = NULL ;
T_11 * V_54 = NULL ;
T_21 * V_85 ;
T_19 * V_69 = NULL ;
T_22 V_86 ;
F_35 ( & V_86 , V_87 , TRUE , V_21 ) ;
V_88 = V_83 ;
if( ! V_21 -> V_31 ) {
if( V_83 ) {
F_19 ( V_83 , V_20 , V_51 , - 1 ,
L_7 ) ;
}
return ;
}
V_85 = F_36 ( V_21 ) ;
V_69 = ( T_19 * ) F_37 ( V_85 , V_89 ) ;
if ( V_69 == NULL ) {
V_69 = ( T_19 * ) F_38 ( sizeof( T_19 ) ) ;
V_69 -> V_75 = F_39 ( F_23 , F_24 ) ;
V_69 -> V_76 = F_39 ( F_25 , F_26 ) ;
F_40 ( V_85 , V_89 , V_69 ) ;
V_69 -> V_90 = V_70 ;
V_70 = V_69 ;
}
if( V_83 ) {
V_27 = F_10 ( V_83 , V_89 , V_20 , 0 , - 1 , V_32 ) ;
V_22 = F_11 ( V_27 , V_91 ) ;
}
F_12 ( V_21 -> V_34 , V_35 , L_8 ) ;
F_41 ( V_21 -> V_34 , V_50 ) ;
while ( F_42 ( V_20 , V_51 ) > 0 ) {
V_84 = V_51 ;
V_51 = F_43 ( FALSE , V_20 , V_51 , & V_86 , V_22 , - 1 ) ;
if( V_51 == V_84 ) {
V_27 = F_19 ( V_22 , V_20 , V_51 , - 1 , L_9 ) ;
if( V_27 ) {
F_21 ( V_21 , V_27 , V_56 , V_57 , L_9 ) ;
V_54 = F_11 ( V_27 , V_55 ) ;
F_22 ( V_21 , V_20 , V_51 , V_54 ) ;
}
break;
}
}
}
static void
F_44 ( void )
{
T_19 * V_69 ;
for ( V_69 = V_70 ; V_69 != NULL ; ) {
T_19 * V_92 ;
F_45 ( V_69 -> V_75 ) ;
V_69 -> V_75 = NULL ;
F_45 ( V_69 -> V_76 ) ;
V_69 -> V_76 = NULL ;
V_92 = V_69 ;
V_69 = V_69 -> V_90 ;
F_46 ( V_92 ) ;
}
V_70 = NULL ;
}
void F_47 ( void ) {
static T_23 V_93 [] =
{
{ & V_79 ,
{ L_10 , L_11 ,
V_94 , V_95 , NULL , 0x0 ,
L_12 , V_96 } } ,
{ & V_81 ,
{ L_13 , L_14 ,
V_94 , V_95 , NULL , 0x0 ,
L_15 , V_96 } } ,
{ & V_82 ,
{ L_16 , L_17 ,
V_97 , V_95 , NULL , 0x0 ,
L_18 , V_96 } } ,
#include "packet-ros-hfarr.c"
} ;
static T_18 * V_98 [] = {
& V_91 ,
& V_55 ,
#include "packet-ros-ettarr.c"
} ;
V_89 = F_48 ( V_99 , V_100 , V_101 ) ;
F_49 ( L_19 , F_34 , V_89 ) ;
F_50 ( V_89 , V_93 , F_51 ( V_93 ) ) ;
F_52 ( V_98 , F_51 ( V_98 ) ) ;
V_53 = F_53 ( L_1 , L_20 , V_102 , V_95 ) ;
V_6 = F_39 ( V_103 , V_104 ) ;
V_10 = F_39 ( V_103 , V_104 ) ;
V_8 = F_54 ( L_19 ) ;
F_55 ( F_44 ) ;
}
void F_56 ( void ) {
}
