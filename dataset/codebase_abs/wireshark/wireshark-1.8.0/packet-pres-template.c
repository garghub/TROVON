static T_1
F_1 ( T_2 V_1 )
{
T_3 * V_2 = ( T_3 * ) V_1 ;
return V_2 -> V_3 ;
}
static T_4
F_2 ( T_2 V_4 , T_2 V_5 )
{
T_3 * V_6 = ( T_3 * ) V_4 ;
T_3 * V_7 = ( T_3 * ) V_5 ;
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
V_2 = F_7 ( sizeof( T_3 ) ) ;
V_2 -> V_3 = V_11 ;
V_2 -> V_12 = F_8 ( V_12 ) ;
V_14 = F_9 ( T_6 -> V_15 -> V_16 , & T_6 -> V_17 , & T_6 -> V_18 ,
T_6 -> V_19 , T_6 -> V_20 , T_6 -> V_21 , 0 ) ;
if ( V_14 ) {
V_2 -> V_8 = V_14 -> V_8 ;
} else {
V_2 -> V_8 = 0 ;
}
V_13 = ( T_3 * ) F_10 ( V_9 , V_2 ) ;
if( V_13 ) {
F_11 ( V_9 , V_13 ) ;
}
F_12 ( V_9 , V_2 , V_2 ) ;
}
char *
F_13 ( T_5 * T_6 V_10 , T_7 V_11 )
{
T_3 V_2 , * V_13 ;
T_8 * V_14 ;
V_2 . V_3 = V_11 ;
V_14 = F_9 ( T_6 -> V_15 -> V_16 , & T_6 -> V_17 , & T_6 -> V_18 ,
T_6 -> V_19 , T_6 -> V_20 , T_6 -> V_21 , 0 ) ;
if ( V_14 ) {
V_2 . V_8 = V_14 -> V_8 ;
} else {
V_2 . V_8 = 0 ;
}
V_13 = ( T_3 * ) F_10 ( V_9 , & V_2 ) ;
if( V_13 ) {
return V_13 -> V_12 ;
}
return NULL ;
}
static void *
F_14 ( void * V_22 , const void * V_23 , T_9 T_10 V_10 )
{
T_11 * V_24 = V_22 ;
const T_11 * V_25 = V_23 ;
V_24 -> V_3 = V_25 -> V_3 ;
V_24 -> V_12 = F_15 ( V_25 -> V_12 ) ;
return V_22 ;
}
static void
F_16 ( void * V_26 )
{
T_11 * V_24 = V_26 ;
F_17 ( V_24 -> V_12 ) ;
}
static T_12
F_18 ( T_7 V_3 , T_13 * V_27 , int V_28 , T_5 * T_6 )
{
T_13 * V_29 ;
T_1 V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
T_11 * V_24 = & ( V_32 [ V_30 ] ) ;
if ( V_24 -> V_3 == V_3 ) {
F_6 ( T_6 , V_24 -> V_3 , V_24 -> V_12 ) ;
V_29 = F_19 ( V_27 , V_28 ) ;
F_20 ( V_24 -> V_12 , V_29 , V_28 , T_6 , V_33 ) ;
return TRUE ;
}
}
return FALSE ;
}
static int
F_21 ( T_13 * V_27 , int V_28 , T_5 * T_6 , T_14 * V_34 )
{
T_15 * V_35 ;
T_14 * V_36 = NULL ;
T_16 V_37 ;
F_22 ( & V_37 , V_38 , TRUE , T_6 ) ;
if( ! T_6 -> V_39 ) {
if( V_34 ) {
F_23 ( V_34 , V_27 , V_28 , - 1 ,
L_1 ) ;
return 0 ;
}
} else{
V_40 = ( (struct V_41 * ) ( T_6 -> V_39 ) ) ;
if( V_40 -> V_42 == 0 ) {
if( V_34 ) {
F_23 ( V_34 , V_27 , V_28 , - 1 ,
L_2 , V_40 -> V_42 ) ;
return 0 ;
}
}
}
F_24 ( T_6 -> V_43 , V_44 ,
F_25 ( V_40 -> V_42 , V_45 , L_3 ) ) ;
if ( V_34 ) {
V_35 = F_26 ( V_34 , V_46 , V_27 , V_28 , - 1 , V_47 ) ;
V_36 = F_27 ( V_35 , V_48 ) ;
}
switch( V_40 -> V_42 ) {
case V_49 :
V_28 = F_28 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_50 ) ;
break;
case V_51 :
V_28 = F_29 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_52 ) ;
break;
case V_53 :
case V_54 :
V_28 = F_30 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_55 ) ;
break;
case V_56 :
V_28 = F_31 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_57 ) ;
break;
case V_58 :
V_28 = F_32 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_59 ) ;
break;
case V_60 :
V_28 = F_33 ( FALSE , V_27 , V_28 , & V_37 , V_36 , - 1 ) ;
break;
case V_61 :
V_28 = F_34 ( FALSE , V_27 , V_28 , & V_37 , V_36 , - 1 ) ;
break;
case V_62 :
V_28 = F_35 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_63 ) ;
break;
default:
V_28 = F_31 ( FALSE , V_27 , V_28 , & V_37 , V_36 , V_57 ) ;
break;
}
return V_28 ;
}
static void
F_36 ( T_13 * V_27 , T_5 * T_6 , T_14 * V_64 )
{
int V_28 = 0 , V_65 ;
V_40 = ( (struct V_41 * ) ( T_6 -> V_39 ) ) ;
if ( ! F_37 ( V_27 , 0 , 4 ) ) {
if ( V_40 && V_40 -> V_42 != V_66 ) {
F_23 ( V_64 , V_27 , V_28 ,
F_38 ( V_27 , V_28 ) , L_4 ) ;
return;
}
}
V_33 = V_64 ;
V_67 = T_6 ;
if( V_40 && V_40 -> V_42 == V_68 )
{
T_14 * V_69 = NULL ;
T_15 * V_35 ;
F_39 ( T_6 -> V_43 , V_70 , L_5 ) ;
F_40 ( T_6 -> V_43 , V_44 ) ;
if ( V_64 )
{
V_35 = F_26 ( V_64 , V_71 , V_27 , V_28 , - 1 , V_47 ) ;
V_69 = F_27 ( V_35 , V_48 ) ;
}
F_41 ( V_27 , T_6 , V_69 ) ;
return;
}
F_39 ( T_6 -> V_43 , V_70 , L_6 ) ;
F_40 ( T_6 -> V_43 , V_44 ) ;
if ( V_40 && V_40 -> V_42 == V_66 ) {
char * V_12 = F_13 ( T_6 , V_40 -> V_72 ) ;
if ( V_12 ) {
F_20 ( V_12 , V_27 , V_28 , T_6 , V_64 ) ;
} else {
F_23 ( V_64 , V_27 , V_28 ,
F_38 ( V_27 , V_28 ) , L_4 ) ;
}
return;
}
while ( F_38 ( V_27 , V_28 ) > 0 ) {
V_65 = V_28 ;
V_28 = F_21 ( V_27 , V_28 , T_6 , V_64 ) ;
if( V_28 <= V_65 ) {
F_23 ( V_64 , V_27 , V_28 , - 1 , L_7 ) ;
F_42 ( V_73 ) ;
}
}
}
void F_43 ( void ) {
static T_17 V_74 [] = {
{ & V_50 ,
{ L_8 , L_9 ,
V_75 , V_76 , NULL , 0 ,
NULL , V_77 } } ,
{ & V_52 ,
{ L_10 , L_11 ,
V_75 , V_76 , NULL , 0 ,
NULL , V_77 } } ,
{ & V_55 ,
{ L_12 , L_13 ,
V_78 , V_79 , F_44 ( V_80 ) , 0 ,
NULL , V_77 } } ,
{ & V_63 ,
{ L_14 , L_15 ,
V_78 , V_79 , F_44 ( V_81 ) , 0 ,
NULL , V_77 } } ,
{ & V_59 ,
{ L_16 , L_17 ,
V_78 , V_79 , F_44 ( V_82 ) , 0 ,
NULL , V_77 } } ,
#include "packet-pres-hfarr.c"
} ;
static T_4 * V_83 [] = {
& V_48 ,
#include "packet-pres-ettarr.c"
} ;
static T_18 V_84 [] = {
F_45 ( V_32 , V_3 , L_18 , L_19 ) ,
F_46 ( V_32 , V_12 , L_20 , L_21 ) ,
V_85
} ;
T_19 * V_86 = F_47 ( L_22 ,
sizeof( T_11 ) ,
L_23 ,
TRUE ,
( void * ) & V_32 ,
& V_31 ,
V_87 ,
L_24 ,
F_14 ,
NULL ,
F_16 ,
NULL ,
V_84 ) ;
static T_20 * V_88 ;
V_46 = F_48 ( V_89 , V_90 , V_91 ) ;
F_49 ( L_25 , F_36 , V_46 ) ;
V_71 = F_48 ( V_92 , V_93 , V_94 ) ;
F_50 ( V_46 , V_74 , F_51 ( V_74 ) ) ;
F_52 ( V_83 , F_51 ( V_83 ) ) ;
F_53 ( F_3 ) ;
V_88 = F_54 ( V_46 , NULL ) ;
F_55 ( V_88 , L_26 , L_27 ,
L_28
L_29 ,
V_86 ) ;
}
void F_56 ( void ) {
}
