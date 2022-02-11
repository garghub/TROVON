static void F_1 ( T_1 * V_1 , const char * V_2 )
{
const char * V_3 = NULL ;
V_3 = F_2 ( F_3 () , V_2 ) ;
F_4 ( V_1 -> V_4 , V_5 , L_1 , V_3 ? V_3 : V_2 ) ;
}
static int
F_5 ( const char * V_6 , T_2 * V_7 , int V_8 , T_1 * V_1 , T_3 * V_9 , const char * V_10 , void * V_11 )
{
char * V_12 ;
V_12 = F_6 ( F_3 () , L_2 , V_6 , V_13 ? V_13 : L_3 ) ;
F_4 ( V_1 -> V_4 , V_5 , L_1 , V_10 ) ;
if ( F_7 ( V_14 , V_12 , V_7 , V_1 , V_9 , V_11 ) ) {
V_8 = F_8 ( V_7 ) ;
} else {
T_4 * V_15 ;
T_3 * V_16 ;
V_16 = F_9 ( V_9 , V_7 , 0 , - 1 , V_17 , & V_15 ,
L_4 , V_6 , V_13 ? V_13 : L_5 ) ;
V_8 = F_10 ( V_1 , V_7 , V_8 , V_16 ) ;
F_11 ( V_1 , V_15 , & V_18 ) ;
}
return V_8 ;
}
static int
F_12 ( T_2 * V_7 , T_1 * V_1 , T_3 * V_19 , void * V_11 )
{
int V_8 = 0 ;
int V_20 ;
T_4 * V_15 ;
T_3 * V_9 ;
struct V_21 * V_22 ;
int (* F_13)( T_5 T_6 V_23 , T_2 * V_7 , int V_8 , T_7 * V_24 , T_3 * V_9 , int T_8 V_23 ) = NULL ;
const char * V_25 ;
T_7 V_26 ;
if ( V_11 == NULL )
return 0 ;
V_22 = (struct V_21 * ) V_11 ;
F_14 ( & V_26 , V_27 , TRUE , V_1 ) ;
V_15 = F_15 ( V_19 , V_28 , V_7 , 0 , - 1 , V_29 ) ;
V_9 = F_16 ( V_15 , V_30 ) ;
F_17 ( V_1 -> V_4 , V_31 , L_6 ) ;
F_18 ( V_1 -> V_4 , V_5 ) ;
V_26 . V_32 = V_22 ;
switch( V_22 -> V_33 & V_34 ) {
case ( V_35 | V_36 ) :
F_13 = V_37 ;
V_25 = L_7 ;
break;
case ( V_35 | V_38 ) :
F_13 = V_39 ;
V_25 = L_8 ;
break;
case ( V_35 | V_40 ) :
F_13 = V_41 ;
V_25 = L_9 ;
break;
case ( V_42 | V_36 ) :
switch( V_22 -> V_33 & V_43 ) {
case 100 :
F_13 = V_44 ;
V_25 = L_10 ;
break;
case 101 :
F_13 = V_45 ;
V_25 = L_11 ;
break;
case 102 :
F_13 = V_46 ;
V_25 = L_12 ;
break;
default:
F_19 ( V_9 , V_1 , & V_47 , V_7 , V_8 , - 1 ,
L_13 , V_22 -> V_33 & V_43 ) ;
break;
}
break;
case ( V_42 | V_38 ) :
switch( V_22 -> V_33 & V_43 ) {
case 100 :
F_13 = V_48 ;
V_25 = L_14 ;
break;
case 101 :
F_13 = V_49 ;
V_25 = L_15 ;
break;
case 102 :
F_13 = V_50 ;
V_25 = L_16 ;
break;
default:
F_19 ( V_9 , V_1 , & V_47 , V_7 , V_8 , - 1 ,
L_17 , V_22 -> V_33 & V_43 ) ;
break;
}
break;
case ( V_42 | V_40 ) :
switch( V_22 -> V_33 & V_43 ) {
case 100 :
F_13 = V_51 ;
V_25 = L_18 ;
break;
default:
F_19 ( V_9 , V_1 , & V_52 , V_7 , V_8 , - 1 ,
L_19 , V_22 -> V_33 & V_43 ) ;
break;
}
break;
default:
F_20 ( V_9 , V_1 , & V_53 , V_7 , V_8 , - 1 ) ;
return F_21 ( V_7 ) ;
}
if( F_13 ) {
F_17 ( V_1 -> V_4 , V_5 , V_25 ) ;
while ( F_22 ( V_7 , V_8 ) > 0 ) {
V_20 = V_8 ;
V_8 = (* F_13)( FALSE , V_7 , V_8 , & V_26 , V_9 , - 1 ) ;
if( V_8 == V_20 ) {
F_20 ( V_9 , V_1 , & V_54 , V_7 , V_8 , - 1 ) ;
break;
}
}
}
return F_21 ( V_7 ) ;
}
void F_23 ( void ) {
static T_9 V_55 [] =
{
#include "packet-dop-hfarr.c"
} ;
static T_10 * V_56 [] = {
& V_30 ,
& V_17 ,
#include "packet-dop-ettarr.c"
} ;
static T_11 V_57 [] = {
{ & V_18 , { L_20 , V_58 , V_59 , L_21 , V_60 } } ,
{ & V_47 , { L_22 , V_58 , V_59 , L_23 , V_60 } } ,
{ & V_52 , { L_24 , V_58 , V_59 , L_25 , V_60 } } ,
{ & V_53 , { L_26 , V_58 , V_59 , L_27 , V_60 } } ,
{ & V_54 , { L_28 , V_61 , V_62 , L_29 , V_60 } } ,
} ;
T_12 * V_63 ;
T_13 * V_64 ;
V_28 = F_24 ( V_65 , V_66 , V_67 ) ;
F_25 ( L_30 , F_12 , V_28 ) ;
V_14 = F_26 ( L_31 , L_32 , V_28 , V_68 , V_69 , V_70 ) ;
F_27 ( V_28 , V_55 , F_28 ( V_55 ) ) ;
F_29 ( V_56 , F_28 ( V_56 ) ) ;
V_63 = F_30 ( V_28 ) ;
F_31 ( V_63 , V_57 , F_28 ( V_57 ) ) ;
V_64 = F_32 ( L_33 , V_28 , V_71 ) ;
F_33 ( V_64 , L_34 , L_35 ,
L_36
L_37 ,
10 , & V_72 ) ;
}
void F_34 ( void ) {
T_14 V_73 ;
#include "packet-dop-dis-tab.c"
F_35 ( L_38 , L_39 ) ;
V_73 = F_36 ( L_30 ) ;
F_37 ( L_40 , V_73 , 0 , L_41 , FALSE ) ;
F_35 ( L_42 , L_43 ) ;
F_35 ( L_44 , L_45 ) ;
F_35 ( L_46 , L_47 ) ;
F_35 ( L_48 , L_49 ) ;
F_35 ( L_50 , L_51 ) ;
F_35 ( L_52 , L_53 ) ;
F_35 ( L_54 , L_55 ) ;
F_35 ( L_56 , L_57 ) ;
F_35 ( L_58 , L_59 ) ;
F_35 ( L_60 , L_61 ) ;
F_35 ( L_62 , L_63 ) ;
F_35 ( L_64 , L_65 ) ;
F_35 ( L_66 , L_67 ) ;
F_35 ( L_68 , L_69 ) ;
F_35 ( L_70 , L_71 ) ;
F_35 ( L_72 , L_73 ) ;
V_74 = F_36 ( L_74 ) ;
}
static void
V_71 ( void )
{
static T_15 V_75 = 0 ;
if( ( V_75 > 0 ) && ( V_75 != 102 ) && V_74 )
F_38 ( L_34 , V_75 , V_74 ) ;
V_75 = V_72 ;
if( ( V_75 > 0 ) && ( V_75 != 102 ) && V_74 )
F_39 ( L_34 , V_75 , V_74 ) ;
}
