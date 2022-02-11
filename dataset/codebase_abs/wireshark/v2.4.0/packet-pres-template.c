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
F_3 ( T_5 * T_6 V_9 , T_7 V_8 , const char * V_10 )
{
T_3 * V_2 , * V_11 ;
T_8 * V_12 ;
if ( ! V_10 ) {
return;
}
V_2 = F_4 ( F_5 () , T_3 ) ;
V_2 -> V_3 = V_8 ;
V_2 -> V_10 = F_6 ( F_5 () , V_10 ) ;
V_12 = F_7 ( T_6 -> V_13 , & T_6 -> V_14 , & T_6 -> V_15 ,
T_6 -> V_16 , T_6 -> V_17 , T_6 -> V_18 , 0 ) ;
if ( V_12 ) {
V_2 -> V_8 = V_12 -> V_19 ;
} else {
V_2 -> V_8 = 0 ;
}
V_11 = ( T_3 * ) F_8 ( V_20 , V_2 ) ;
if ( V_11 ) {
F_9 ( V_20 , V_11 ) ;
}
F_10 ( V_20 , V_2 , V_2 ) ;
}
static char *
F_11 ( T_5 * T_6 , T_7 V_3 )
{
T_1 V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
T_9 * V_23 = & ( V_24 [ V_21 ] ) ;
if ( V_23 -> V_3 == V_3 ) {
F_3 ( T_6 , V_23 -> V_3 , V_23 -> V_10 ) ;
return V_23 -> V_10 ;
}
}
return NULL ;
}
char *
F_12 ( T_5 * T_6 , T_7 V_8 )
{
T_3 V_2 , * V_11 ;
T_8 * V_12 ;
V_2 . V_3 = V_8 ;
V_12 = F_7 ( T_6 -> V_13 , & T_6 -> V_14 , & T_6 -> V_15 ,
T_6 -> V_16 , T_6 -> V_17 , T_6 -> V_18 , 0 ) ;
if ( V_12 ) {
V_2 . V_8 = V_12 -> V_19 ;
} else {
V_2 . V_8 = 0 ;
}
V_11 = ( T_3 * ) F_8 ( V_20 , & V_2 ) ;
if ( V_11 ) {
return V_11 -> V_10 ;
}
return F_11 ( T_6 , V_8 ) ;
}
static void *
F_13 ( void * V_25 , const void * V_26 , T_10 T_11 V_9 )
{
T_9 * V_23 = ( T_9 * ) V_25 ;
const T_9 * V_27 = ( const T_9 * ) V_26 ;
V_23 -> V_3 = V_27 -> V_3 ;
V_23 -> V_10 = F_14 ( V_27 -> V_10 ) ;
return V_25 ;
}
static void
F_15 ( void * V_28 )
{
T_9 * V_23 = ( T_9 * ) V_28 ;
F_16 ( V_23 -> V_10 ) ;
}
static int
F_17 ( T_12 * V_29 , int V_30 , T_5 * T_6 , T_13 * V_31 , struct V_32 * V_33 )
{
T_14 * V_34 ;
T_13 * V_35 ;
struct V_32 * V_36 ;
T_15 V_37 ;
F_18 ( & V_37 , V_38 , TRUE , T_6 ) ;
if ( V_33 == NULL ) {
F_19 ( V_31 , T_6 , & V_39 , V_29 , V_30 , - 1 ) ;
return 0 ;
}
V_36 = V_33 ;
if ( V_36 -> V_40 == 0 ) {
F_20 ( V_31 , T_6 , & V_39 , V_29 , V_30 , - 1 ,
L_1 , V_36 -> V_40 ) ;
return 0 ;
}
F_21 ( T_6 -> V_41 , V_42 ,
F_22 ( V_36 -> V_40 , & V_43 , L_2 ) ) ;
V_37 . V_44 = V_36 ;
V_34 = F_23 ( V_31 , V_45 , V_29 , V_30 , - 1 , V_46 ) ;
V_35 = F_24 ( V_34 , V_47 ) ;
switch ( V_36 -> V_40 ) {
case V_48 :
V_30 = F_25 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_49 ) ;
break;
case V_50 :
V_30 = F_26 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_51 ) ;
break;
case V_52 :
case V_53 :
V_30 = F_27 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_54 ) ;
break;
case V_55 :
V_30 = F_28 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_56 ) ;
break;
case V_57 :
V_30 = F_29 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_58 ) ;
break;
case V_59 :
V_30 = F_30 ( FALSE , V_29 , V_30 , & V_37 , V_35 , - 1 ) ;
break;
case V_60 :
V_30 = F_31 ( FALSE , V_29 , V_30 , & V_37 , V_35 , - 1 ) ;
break;
case V_61 :
V_30 = F_32 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_62 ) ;
break;
default:
V_30 = F_28 ( FALSE , V_29 , V_30 , & V_37 , V_35 , V_56 ) ;
break;
}
return V_30 ;
}
static int
F_33 ( T_12 * V_29 , T_5 * T_6 , T_13 * V_63 , void * V_64 )
{
int V_30 = 0 , V_65 ;
struct V_32 * V_36 ;
V_36 = ( (struct V_32 * ) V_64 ) ;
if ( ! F_34 ( V_29 , 0 , 4 ) ) {
if ( V_36 && V_36 -> V_40 != V_66 ) {
F_23 ( V_63 , V_56 , V_29 , V_30 ,
F_35 ( V_29 , V_30 ) , V_46 ) ;
return 0 ;
}
}
V_67 = V_63 ;
V_68 = T_6 ;
if ( V_36 && V_36 -> V_40 == V_69 ) {
T_13 * V_70 = NULL ;
T_14 * V_34 ;
F_36 ( T_6 -> V_41 , V_71 , L_3 ) ;
F_37 ( T_6 -> V_41 , V_42 ) ;
if ( V_63 ) {
V_34 = F_23 ( V_63 , V_72 , V_29 , V_30 , - 1 , V_46 ) ;
V_70 = F_24 ( V_34 , V_47 ) ;
}
F_38 ( V_29 , T_6 , V_70 , NULL ) ;
return F_39 ( V_29 ) ;
}
F_36 ( T_6 -> V_41 , V_71 , L_4 ) ;
F_37 ( T_6 -> V_41 , V_42 ) ;
if ( V_36 && V_36 -> V_40 == V_66 ) {
char * V_10 = F_12 ( T_6 , V_36 -> V_73 ) ;
if ( V_10 ) {
F_40 ( V_10 , V_29 , V_30 , T_6 , V_63 , V_36 ) ;
} else {
F_23 ( V_63 , V_56 , V_29 , V_30 ,
F_35 ( V_29 , V_30 ) , V_46 ) ;
}
return F_39 ( V_29 ) ;
}
while ( F_35 ( V_29 , V_30 ) > 0 ) {
V_65 = V_30 ;
V_30 = F_17 ( V_29 , V_30 , T_6 , V_63 , V_36 ) ;
if ( V_30 <= V_65 ) {
F_19 ( V_63 , T_6 , & V_74 , V_29 , V_30 , - 1 ) ;
break;
}
}
return F_39 ( V_29 ) ;
}
void F_41 ( void ) {
static T_16 V_75 [] = {
{ & V_49 ,
{ L_5 , L_6 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_78 } } ,
{ & V_51 ,
{ L_7 , L_8 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_78 } } ,
{ & V_54 ,
{ L_9 , L_10 ,
V_79 , V_80 , F_42 ( V_81 ) , 0 ,
NULL , V_78 } } ,
{ & V_62 ,
{ L_11 , L_12 ,
V_79 , V_80 , F_42 ( V_82 ) , 0 ,
NULL , V_78 } } ,
{ & V_58 ,
{ L_13 , L_14 ,
V_79 , V_80 , F_42 ( V_83 ) , 0 ,
NULL , V_78 } } ,
#include "packet-pres-hfarr.c"
} ;
static T_4 * V_84 [] = {
& V_47 ,
#include "packet-pres-ettarr.c"
} ;
static T_17 V_85 [] = {
{ & V_86 , { L_15 , V_87 , V_88 , L_16 , V_89 } } ,
{ & V_39 , { L_17 , V_90 , V_88 , L_18 , V_89 } } ,
{ & V_74 , { L_19 , V_91 , V_92 , L_18 , V_89 } } ,
} ;
static T_18 V_93 [] = {
F_43 ( V_24 , V_3 , L_20 , L_21 ) ,
F_44 ( V_24 , V_10 , L_22 , L_23 ) ,
V_94
} ;
T_19 * V_95 = F_45 ( L_24 ,
sizeof( T_9 ) ,
L_25 ,
TRUE ,
& V_24 ,
& V_22 ,
V_96 ,
L_26 ,
F_13 ,
NULL ,
F_15 ,
NULL ,
NULL ,
V_93 ) ;
T_20 * V_97 ;
T_21 * V_98 ;
V_45 = F_46 ( V_99 , V_100 , V_101 ) ;
F_47 ( L_27 , F_33 , V_45 ) ;
V_72 = F_46 ( V_102 , V_103 , V_104 ) ;
F_48 ( V_45 , V_75 , F_49 ( V_75 ) ) ;
F_50 ( V_84 , F_49 ( V_84 ) ) ;
V_97 = F_51 ( V_45 ) ;
F_52 ( V_97 , V_85 , F_49 ( V_85 ) ) ;
V_20 = F_53 ( F_54 () , F_5 () , F_1 , F_2 ) ;
V_98 = F_55 ( V_45 , NULL ) ;
F_56 ( V_98 , L_28 , L_29 ,
L_30
L_31 ,
V_95 ) ;
}
void F_57 ( void ) {
}
