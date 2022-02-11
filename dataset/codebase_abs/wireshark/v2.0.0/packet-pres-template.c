static T_1
F_1 ( T_2 V_1 )
{
const T_3 * V_2 = ( const T_3 * ) V_1 ;
return V_2 -> V_3 ;
}
static T_4
F_2 ( T_2 V_4 , T_2 V_5 )
{
const T_3 * V_6 = ( const T_3 * ) V_4 ;
const T_3 * V_7 = ( const T_3 * ) V_5 ;
return ( V_6 -> V_3 == V_7 -> V_3 && V_6 -> V_8 == V_7 -> V_8 ) ;
}
static void
F_3 ( void )
{
V_9 = F_4 ( F_1 ,
F_2 ) ;
}
static void
F_5 ( void )
{
F_6 ( V_9 ) ;
}
static void
F_7 ( T_5 * T_6 V_10 , T_7 V_8 , const char * V_11 )
{
T_3 * V_2 , * V_12 ;
T_8 * V_13 ;
if( ! V_11 ) {
return;
}
V_2 = F_8 ( F_9 () , T_3 ) ;
V_2 -> V_3 = V_8 ;
V_2 -> V_11 = F_10 ( F_9 () , V_11 ) ;
V_13 = F_11 ( T_6 -> V_14 -> V_15 , & T_6 -> V_16 , & T_6 -> V_17 ,
T_6 -> V_18 , T_6 -> V_19 , T_6 -> V_20 , 0 ) ;
if ( V_13 ) {
V_2 -> V_8 = V_13 -> V_21 ;
} else {
V_2 -> V_8 = 0 ;
}
V_12 = ( T_3 * ) F_12 ( V_9 , V_2 ) ;
if( V_12 ) {
F_13 ( V_9 , V_12 ) ;
}
F_14 ( V_9 , V_2 , V_2 ) ;
}
static char *
F_15 ( T_5 * T_6 , T_7 V_3 )
{
T_1 V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
T_9 * V_24 = & ( V_25 [ V_22 ] ) ;
if ( V_24 -> V_3 == V_3 ) {
F_7 ( T_6 , V_24 -> V_3 , V_24 -> V_11 ) ;
return V_24 -> V_11 ;
}
}
return NULL ;
}
char *
F_16 ( T_5 * T_6 , T_7 V_8 )
{
T_3 V_2 , * V_12 ;
T_8 * V_13 ;
V_2 . V_3 = V_8 ;
V_13 = F_11 ( T_6 -> V_14 -> V_15 , & T_6 -> V_16 , & T_6 -> V_17 ,
T_6 -> V_18 , T_6 -> V_19 , T_6 -> V_20 , 0 ) ;
if ( V_13 ) {
V_2 . V_8 = V_13 -> V_21 ;
} else {
V_2 . V_8 = 0 ;
}
V_12 = ( T_3 * ) F_12 ( V_9 , & V_2 ) ;
if( V_12 ) {
return V_12 -> V_11 ;
}
return F_15 ( T_6 , V_8 ) ;
}
static void *
F_17 ( void * V_26 , const void * V_27 , T_10 T_11 V_10 )
{
T_9 * V_24 = ( T_9 * ) V_26 ;
const T_9 * V_28 = ( const T_9 * ) V_27 ;
V_24 -> V_3 = V_28 -> V_3 ;
V_24 -> V_11 = F_18 ( V_28 -> V_11 ) ;
return V_26 ;
}
static void
F_19 ( void * V_29 )
{
T_9 * V_24 = ( T_9 * ) V_29 ;
F_20 ( V_24 -> V_11 ) ;
}
static int
F_21 ( T_12 * V_30 , int V_31 , T_5 * T_6 , T_13 * V_32 , struct V_33 * V_34 )
{
T_14 * V_35 ;
T_13 * V_36 ;
struct V_33 * V_37 ;
T_15 V_38 ;
F_22 ( & V_38 , V_39 , TRUE , T_6 ) ;
if( V_34 == NULL ) {
F_23 ( V_32 , T_6 , & V_40 , V_30 , V_31 , - 1 ) ;
return 0 ;
}
V_37 = V_34 ;
if( V_37 -> V_41 == 0 ) {
F_24 ( V_32 , T_6 , & V_40 , V_30 , V_31 , - 1 ,
L_1 , V_37 -> V_41 ) ;
return 0 ;
}
F_25 ( T_6 -> V_42 , V_43 ,
F_26 ( V_37 -> V_41 , & V_44 , L_2 ) ) ;
V_38 . V_45 = V_37 ;
V_35 = F_27 ( V_32 , V_46 , V_30 , V_31 , - 1 , V_47 ) ;
V_36 = F_28 ( V_35 , V_48 ) ;
switch( V_37 -> V_41 ) {
case V_49 :
V_31 = F_29 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_50 ) ;
break;
case V_51 :
V_31 = F_30 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_52 ) ;
break;
case V_53 :
case V_54 :
V_31 = F_31 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_55 ) ;
break;
case V_56 :
V_31 = F_32 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_57 ) ;
break;
case V_58 :
V_31 = F_33 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_59 ) ;
break;
case V_60 :
V_31 = F_34 ( FALSE , V_30 , V_31 , & V_38 , V_36 , - 1 ) ;
break;
case V_61 :
V_31 = F_35 ( FALSE , V_30 , V_31 , & V_38 , V_36 , - 1 ) ;
break;
case V_62 :
V_31 = F_36 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_63 ) ;
break;
default:
V_31 = F_32 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_57 ) ;
break;
}
return V_31 ;
}
static int
F_37 ( T_12 * V_30 , T_5 * T_6 , T_13 * V_64 , void * V_65 )
{
int V_31 = 0 , V_66 ;
struct V_33 * V_37 ;
V_37 = ( (struct V_33 * ) V_65 ) ;
if ( ! F_38 ( V_30 , 0 , 4 ) ) {
if ( V_37 && V_37 -> V_41 != V_67 ) {
F_27 ( V_64 , V_57 , V_30 , V_31 ,
F_39 ( V_30 , V_31 ) , V_47 ) ;
return 0 ;
}
}
V_68 = V_64 ;
V_69 = T_6 ;
if( V_37 && V_37 -> V_41 == V_70 )
{
T_13 * V_71 = NULL ;
T_14 * V_35 ;
F_40 ( T_6 -> V_42 , V_72 , L_3 ) ;
F_41 ( T_6 -> V_42 , V_43 ) ;
if ( V_64 )
{
V_35 = F_27 ( V_64 , V_73 , V_30 , V_31 , - 1 , V_47 ) ;
V_71 = F_28 ( V_35 , V_48 ) ;
}
F_42 ( V_30 , T_6 , V_71 , NULL ) ;
return F_43 ( V_30 ) ;
}
F_40 ( T_6 -> V_42 , V_72 , L_4 ) ;
F_41 ( T_6 -> V_42 , V_43 ) ;
if ( V_37 && V_37 -> V_41 == V_67 ) {
char * V_11 = F_16 ( T_6 , V_37 -> V_74 ) ;
if ( V_11 ) {
F_44 ( V_11 , V_30 , V_31 , T_6 , V_64 , V_37 ) ;
} else {
F_27 ( V_64 , V_57 , V_30 , V_31 ,
F_39 ( V_30 , V_31 ) , V_47 ) ;
}
return F_43 ( V_30 ) ;
}
while ( F_39 ( V_30 , V_31 ) > 0 ) {
V_66 = V_31 ;
V_31 = F_21 ( V_30 , V_31 , T_6 , V_64 , V_37 ) ;
if( V_31 <= V_66 ) {
F_23 ( V_64 , T_6 , & V_75 , V_30 , V_31 , - 1 ) ;
break;
}
}
return F_43 ( V_30 ) ;
}
void F_45 ( void ) {
static T_16 V_76 [] = {
{ & V_50 ,
{ L_5 , L_6 ,
V_77 , V_78 , NULL , 0 ,
NULL , V_79 } } ,
{ & V_52 ,
{ L_7 , L_8 ,
V_77 , V_78 , NULL , 0 ,
NULL , V_79 } } ,
{ & V_55 ,
{ L_9 , L_10 ,
V_80 , V_81 , F_46 ( V_82 ) , 0 ,
NULL , V_79 } } ,
{ & V_63 ,
{ L_11 , L_12 ,
V_80 , V_81 , F_46 ( V_83 ) , 0 ,
NULL , V_79 } } ,
{ & V_59 ,
{ L_13 , L_14 ,
V_80 , V_81 , F_46 ( V_84 ) , 0 ,
NULL , V_79 } } ,
#include "packet-pres-hfarr.c"
} ;
static T_4 * V_85 [] = {
& V_48 ,
#include "packet-pres-ettarr.c"
} ;
static T_17 V_86 [] = {
{ & V_87 , { L_15 , V_88 , V_89 , L_16 , V_90 } } ,
{ & V_40 , { L_17 , V_91 , V_89 , L_18 , V_90 } } ,
{ & V_75 , { L_19 , V_92 , V_93 , L_18 , V_90 } } ,
} ;
static T_18 V_94 [] = {
F_47 ( V_25 , V_3 , L_20 , L_21 ) ,
F_48 ( V_25 , V_11 , L_22 , L_23 ) ,
V_95
} ;
T_19 * V_96 = F_49 ( L_24 ,
sizeof( T_9 ) ,
L_25 ,
TRUE ,
& V_25 ,
& V_23 ,
V_97 ,
L_26 ,
F_17 ,
NULL ,
F_19 ,
NULL ,
V_94 ) ;
T_20 * V_98 ;
T_21 * V_99 ;
V_46 = F_50 ( V_100 , V_101 , V_102 ) ;
F_51 ( L_27 , F_37 , V_46 ) ;
V_73 = F_50 ( V_103 , V_104 , V_105 ) ;
F_52 ( V_46 , V_76 , F_53 ( V_76 ) ) ;
F_54 ( V_85 , F_53 ( V_85 ) ) ;
V_98 = F_55 ( V_46 ) ;
F_56 ( V_98 , V_86 , F_53 ( V_86 ) ) ;
F_57 ( F_3 ) ;
F_58 ( F_5 ) ;
V_99 = F_59 ( V_46 , NULL ) ;
F_60 ( V_99 , L_28 , L_29 ,
L_30
L_31 ,
V_96 ) ;
}
void F_61 ( void ) {
}
