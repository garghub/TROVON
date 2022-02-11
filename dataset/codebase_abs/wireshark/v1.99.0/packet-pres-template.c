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
if( V_9 ) {
F_4 ( V_9 ) ;
V_9 = NULL ;
}
V_9 = F_5 ( F_1 ,
F_2 ) ;
}
static void
F_6 ( T_5 * T_6 V_10 , T_7 V_11 , const char * V_12 )
{
T_3 * V_2 , * V_13 ;
T_8 * V_14 ;
if( ! V_12 ) {
return;
}
V_2 = F_7 ( F_8 () , T_3 ) ;
V_2 -> V_3 = V_11 ;
V_2 -> V_12 = F_9 ( F_8 () , V_12 ) ;
V_14 = F_10 ( T_6 -> V_15 -> V_16 , & T_6 -> V_17 , & T_6 -> V_18 ,
T_6 -> V_19 , T_6 -> V_20 , T_6 -> V_21 , 0 ) ;
if ( V_14 ) {
V_2 -> V_8 = V_14 -> V_8 ;
} else {
V_2 -> V_8 = 0 ;
}
V_13 = ( T_3 * ) F_11 ( V_9 , V_2 ) ;
if( V_13 ) {
F_12 ( V_9 , V_13 ) ;
}
F_13 ( V_9 , V_2 , V_2 ) ;
}
static char *
F_14 ( T_5 * T_6 , T_7 V_3 )
{
T_1 V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
T_9 * V_24 = & ( V_25 [ V_22 ] ) ;
if ( V_24 -> V_3 == V_3 ) {
F_6 ( T_6 , V_24 -> V_3 , V_24 -> V_12 ) ;
return V_24 -> V_12 ;
}
}
return NULL ;
}
char *
F_15 ( T_5 * T_6 , T_7 V_11 )
{
T_3 V_2 , * V_13 ;
T_8 * V_14 ;
V_2 . V_3 = V_11 ;
V_14 = F_10 ( T_6 -> V_15 -> V_16 , & T_6 -> V_17 , & T_6 -> V_18 ,
T_6 -> V_19 , T_6 -> V_20 , T_6 -> V_21 , 0 ) ;
if ( V_14 ) {
V_2 . V_8 = V_14 -> V_8 ;
} else {
V_2 . V_8 = 0 ;
}
V_13 = ( T_3 * ) F_11 ( V_9 , & V_2 ) ;
if( V_13 ) {
return V_13 -> V_12 ;
}
return F_14 ( T_6 , V_11 ) ;
}
static void *
F_16 ( void * V_26 , const void * V_27 , T_10 T_11 V_10 )
{
T_9 * V_24 = ( T_9 * ) V_26 ;
const T_9 * V_28 = ( const T_9 * ) V_27 ;
V_24 -> V_3 = V_28 -> V_3 ;
V_24 -> V_12 = F_17 ( V_28 -> V_12 ) ;
return V_26 ;
}
static void
F_18 ( void * V_29 )
{
T_9 * V_24 = ( T_9 * ) V_29 ;
F_19 ( V_24 -> V_12 ) ;
}
static int
F_20 ( T_12 * V_30 , int V_31 , T_5 * T_6 , T_13 * V_32 , struct V_33 * V_34 )
{
T_14 * V_35 ;
T_13 * V_36 ;
struct V_33 * V_37 ;
T_15 V_38 ;
F_21 ( & V_38 , V_39 , TRUE , T_6 ) ;
if( V_34 == NULL ) {
F_22 ( V_32 , T_6 , & V_40 , V_30 , V_31 , - 1 ) ;
return 0 ;
}
V_37 = V_34 ;
if( V_37 -> V_41 == 0 ) {
F_23 ( V_32 , T_6 , & V_40 , V_30 , V_31 , - 1 ,
L_1 , V_37 -> V_41 ) ;
return 0 ;
}
F_24 ( T_6 -> V_42 , V_43 ,
F_25 ( V_37 -> V_41 , & V_44 , L_2 ) ) ;
V_38 . V_45 = V_37 ;
V_35 = F_26 ( V_32 , V_46 , V_30 , V_31 , - 1 , V_47 ) ;
V_36 = F_27 ( V_35 , V_48 ) ;
switch( V_37 -> V_41 ) {
case V_49 :
V_31 = F_28 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_50 ) ;
break;
case V_51 :
V_31 = F_29 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_52 ) ;
break;
case V_53 :
case V_54 :
V_31 = F_30 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_55 ) ;
break;
case V_56 :
V_31 = F_31 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_57 ) ;
break;
case V_58 :
V_31 = F_32 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_59 ) ;
break;
case V_60 :
V_31 = F_33 ( FALSE , V_30 , V_31 , & V_38 , V_36 , - 1 ) ;
break;
case V_61 :
V_31 = F_34 ( FALSE , V_30 , V_31 , & V_38 , V_36 , - 1 ) ;
break;
case V_62 :
V_31 = F_35 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_63 ) ;
break;
default:
V_31 = F_31 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_57 ) ;
break;
}
return V_31 ;
}
static int
F_36 ( T_12 * V_30 , T_5 * T_6 , T_13 * V_64 , void * V_65 )
{
int V_31 = 0 , V_66 ;
struct V_33 * V_37 ;
V_37 = ( (struct V_33 * ) V_65 ) ;
if ( ! F_37 ( V_30 , 0 , 4 ) ) {
if ( V_37 && V_37 -> V_41 != V_67 ) {
F_26 ( V_64 , V_57 , V_30 , V_31 ,
F_38 ( V_30 , V_31 ) , V_47 ) ;
return 0 ;
}
}
V_68 = V_64 ;
V_69 = T_6 ;
if( V_37 && V_37 -> V_41 == V_70 )
{
T_13 * V_71 = NULL ;
T_14 * V_35 ;
F_39 ( T_6 -> V_42 , V_72 , L_3 ) ;
F_40 ( T_6 -> V_42 , V_43 ) ;
if ( V_64 )
{
V_35 = F_26 ( V_64 , V_73 , V_30 , V_31 , - 1 , V_47 ) ;
V_71 = F_27 ( V_35 , V_48 ) ;
}
F_41 ( V_30 , T_6 , V_71 ) ;
return F_42 ( V_30 ) ;
}
F_39 ( T_6 -> V_42 , V_72 , L_4 ) ;
F_40 ( T_6 -> V_42 , V_43 ) ;
if ( V_37 && V_37 -> V_41 == V_67 ) {
char * V_12 = F_15 ( T_6 , V_37 -> V_74 ) ;
if ( V_12 ) {
F_43 ( V_12 , V_30 , V_31 , T_6 , V_64 , V_37 ) ;
} else {
F_26 ( V_64 , V_57 , V_30 , V_31 ,
F_38 ( V_30 , V_31 ) , V_47 ) ;
}
return F_42 ( V_30 ) ;
}
while ( F_38 ( V_30 , V_31 ) > 0 ) {
V_66 = V_31 ;
V_31 = F_20 ( V_30 , V_31 , T_6 , V_64 , V_37 ) ;
if( V_31 <= V_66 ) {
F_22 ( V_64 , T_6 , & V_75 , V_30 , V_31 , - 1 ) ;
break;
}
}
return F_42 ( V_30 ) ;
}
void F_44 ( void ) {
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
V_80 , V_81 , F_45 ( V_82 ) , 0 ,
NULL , V_79 } } ,
{ & V_63 ,
{ L_11 , L_12 ,
V_80 , V_81 , F_45 ( V_83 ) , 0 ,
NULL , V_79 } } ,
{ & V_59 ,
{ L_13 , L_14 ,
V_80 , V_81 , F_45 ( V_84 ) , 0 ,
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
F_46 ( V_25 , V_3 , L_20 , L_21 ) ,
F_47 ( V_25 , V_12 , L_22 , L_23 ) ,
V_95
} ;
T_19 * V_96 = F_48 ( L_24 ,
sizeof( T_9 ) ,
L_25 ,
TRUE ,
& V_25 ,
& V_23 ,
V_97 ,
L_26 ,
F_16 ,
NULL ,
F_18 ,
NULL ,
V_94 ) ;
T_20 * V_98 ;
T_21 * V_99 ;
V_46 = F_49 ( V_100 , V_101 , V_102 ) ;
F_50 ( L_27 , F_36 , V_46 ) ;
V_73 = F_49 ( V_103 , V_104 , V_105 ) ;
F_51 ( V_46 , V_76 , F_52 ( V_76 ) ) ;
F_53 ( V_85 , F_52 ( V_85 ) ) ;
V_98 = F_54 ( V_46 ) ;
F_55 ( V_98 , V_86 , F_52 ( V_86 ) ) ;
F_56 ( F_3 ) ;
V_99 = F_57 ( V_46 , NULL ) ;
F_58 ( V_99 , L_28 , L_29 ,
L_30
L_31 ,
V_96 ) ;
}
void F_59 ( void ) {
}
