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
F_22 ( V_32 , V_30 , V_31 , - 1 ,
L_1 ) ;
return 0 ;
}
V_37 = V_34 ;
if( V_37 -> V_40 == 0 ) {
F_22 ( V_32 , V_30 , V_31 , - 1 ,
L_2 , V_37 -> V_40 ) ;
return 0 ;
}
F_23 ( T_6 -> V_41 , V_42 ,
F_24 ( V_37 -> V_40 , V_43 , L_3 ) ) ;
V_38 . V_44 = V_37 ;
V_35 = F_25 ( V_32 , V_45 , V_30 , V_31 , - 1 , V_46 ) ;
V_36 = F_26 ( V_35 , V_47 ) ;
switch( V_37 -> V_40 ) {
case V_48 :
V_31 = F_27 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_49 ) ;
break;
case V_50 :
V_31 = F_28 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_51 ) ;
break;
case V_52 :
case V_53 :
V_31 = F_29 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_54 ) ;
break;
case V_55 :
V_31 = F_30 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_56 ) ;
break;
case V_57 :
V_31 = F_31 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_58 ) ;
break;
case V_59 :
V_31 = F_32 ( FALSE , V_30 , V_31 , & V_38 , V_36 , - 1 ) ;
break;
case V_60 :
V_31 = F_33 ( FALSE , V_30 , V_31 , & V_38 , V_36 , - 1 ) ;
break;
case V_61 :
V_31 = F_34 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_62 ) ;
break;
default:
V_31 = F_30 ( FALSE , V_30 , V_31 , & V_38 , V_36 , V_56 ) ;
break;
}
return V_31 ;
}
static int
F_35 ( T_12 * V_30 , T_5 * T_6 , T_13 * V_63 , void * V_64 )
{
int V_31 = 0 , V_65 ;
struct V_33 * V_37 ;
V_37 = ( (struct V_33 * ) V_64 ) ;
if ( ! F_36 ( V_30 , 0 , 4 ) ) {
if ( V_37 && V_37 -> V_40 != V_66 ) {
F_22 ( V_63 , V_30 , V_31 ,
F_37 ( V_30 , V_31 ) , L_4 ) ;
return 0 ;
}
}
V_67 = V_63 ;
V_68 = T_6 ;
if( V_37 && V_37 -> V_40 == V_69 )
{
T_13 * V_70 = NULL ;
T_14 * V_35 ;
F_38 ( T_6 -> V_41 , V_71 , L_5 ) ;
F_39 ( T_6 -> V_41 , V_42 ) ;
if ( V_63 )
{
V_35 = F_25 ( V_63 , V_72 , V_30 , V_31 , - 1 , V_46 ) ;
V_70 = F_26 ( V_35 , V_47 ) ;
}
F_40 ( V_30 , T_6 , V_70 ) ;
return F_41 ( V_30 ) ;
}
F_38 ( T_6 -> V_41 , V_71 , L_6 ) ;
F_39 ( T_6 -> V_41 , V_42 ) ;
if ( V_37 && V_37 -> V_40 == V_66 ) {
char * V_12 = F_15 ( T_6 , V_37 -> V_73 ) ;
if ( V_12 ) {
F_42 ( V_12 , V_30 , V_31 , T_6 , V_63 , V_37 ) ;
} else {
F_22 ( V_63 , V_30 , V_31 ,
F_37 ( V_30 , V_31 ) , L_4 ) ;
}
return F_41 ( V_30 ) ;
}
while ( F_37 ( V_30 , V_31 ) > 0 ) {
V_65 = V_31 ;
V_31 = F_20 ( V_30 , V_31 , T_6 , V_63 , V_37 ) ;
if( V_31 <= V_65 ) {
F_22 ( V_63 , V_30 , V_31 , - 1 , L_7 ) ;
F_43 ( V_74 ) ;
}
}
return F_41 ( V_30 ) ;
}
void F_44 ( void ) {
static T_16 V_75 [] = {
{ & V_49 ,
{ L_8 , L_9 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_78 } } ,
{ & V_51 ,
{ L_10 , L_11 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_78 } } ,
{ & V_54 ,
{ L_12 , L_13 ,
V_79 , V_80 , F_45 ( V_81 ) , 0 ,
NULL , V_78 } } ,
{ & V_62 ,
{ L_14 , L_15 ,
V_79 , V_80 , F_45 ( V_82 ) , 0 ,
NULL , V_78 } } ,
{ & V_58 ,
{ L_16 , L_17 ,
V_79 , V_80 , F_45 ( V_83 ) , 0 ,
NULL , V_78 } } ,
#include "packet-pres-hfarr.c"
} ;
static T_4 * V_84 [] = {
& V_47 ,
#include "packet-pres-ettarr.c"
} ;
static T_17 V_85 [] = {
{ & V_86 , { L_18 , V_87 , V_88 , L_19 , V_89 } } ,
} ;
static T_18 V_90 [] = {
F_46 ( V_25 , V_3 , L_20 , L_21 ) ,
F_47 ( V_25 , V_12 , L_22 , L_23 ) ,
V_91
} ;
T_19 * V_92 = F_48 ( L_24 ,
sizeof( T_9 ) ,
L_25 ,
TRUE ,
& V_25 ,
& V_23 ,
V_93 ,
L_26 ,
F_16 ,
NULL ,
F_18 ,
NULL ,
V_90 ) ;
T_20 * V_94 ;
T_21 * V_95 ;
V_45 = F_49 ( V_96 , V_97 , V_98 ) ;
F_50 ( L_27 , F_35 , V_45 ) ;
V_72 = F_49 ( V_99 , V_100 , V_101 ) ;
F_51 ( V_45 , V_75 , F_52 ( V_75 ) ) ;
F_53 ( V_84 , F_52 ( V_84 ) ) ;
V_94 = F_54 ( V_45 ) ;
F_55 ( V_94 , V_85 , F_52 ( V_85 ) ) ;
F_56 ( F_3 ) ;
V_95 = F_57 ( V_45 , NULL ) ;
F_58 ( V_95 , L_28 , L_29 ,
L_30
L_31 ,
V_92 ) ;
}
void F_59 ( void ) {
}
