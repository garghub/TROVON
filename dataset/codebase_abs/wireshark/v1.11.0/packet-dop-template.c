static void F_1 ( T_1 * V_1 , const char * V_2 )
{
const char * V_3 = NULL ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_1 -> V_4 , V_5 , L_1 , V_3 ? V_3 : V_2 ) ;
}
static int
F_4 ( const char * V_6 , T_2 * V_7 , int V_8 , T_1 * V_1 , T_3 * V_9 , const char * V_10 )
{
char * V_11 ;
V_11 = F_5 ( F_6 () , L_2 , V_6 , V_12 ? V_12 : L_3 ) ;
F_3 ( V_1 -> V_4 , V_5 , L_1 , V_10 ) ;
if ( F_7 ( V_13 , V_11 , V_7 , V_1 , V_9 ) ) {
V_8 = F_8 ( V_7 ) ;
} else {
T_4 * V_14 = NULL ;
T_3 * V_15 = NULL ;
V_14 = F_9 ( V_9 , V_7 , 0 , F_10 ( V_7 , V_8 ) , L_4 , V_6 , V_12 ? V_12 : L_5 ) ;
if ( V_14 ) {
V_15 = F_11 ( V_14 , V_16 ) ;
}
V_8 = F_12 ( V_1 , V_7 , V_8 , V_15 ) ;
F_13 ( V_1 , V_14 , & V_17 ) ;
}
return V_8 ;
}
static void
F_14 ( T_2 * V_7 , T_1 * V_1 , T_3 * V_18 )
{
int V_8 = 0 ;
int V_19 ;
T_4 * V_14 = NULL ;
T_3 * V_9 = NULL ;
int (* F_15)( T_5 T_6 V_20 , T_2 * V_7 , int V_8 , T_7 * V_21 , T_3 * V_9 , int T_8 V_20 ) = NULL ;
const char * V_22 ;
T_7 V_23 ;
F_16 ( & V_23 , V_24 , TRUE , V_1 ) ;
if( ! V_1 -> V_25 ) {
if( V_18 ) {
F_9 ( V_18 , V_7 , V_8 , - 1 ,
L_6 ) ;
}
return ;
} else {
V_26 = ( (struct V_27 * ) ( V_1 -> V_25 ) ) ;
}
if( V_18 ) {
V_14 = F_17 ( V_18 , V_28 , V_7 , 0 , - 1 , V_29 ) ;
V_9 = F_11 ( V_14 , V_30 ) ;
}
F_18 ( V_1 -> V_4 , V_31 , L_7 ) ;
F_19 ( V_1 -> V_4 , V_5 ) ;
switch( V_26 -> V_32 & V_33 ) {
case ( V_34 | V_35 ) :
F_15 = V_36 ;
V_22 = L_8 ;
break;
case ( V_34 | V_37 ) :
F_15 = V_38 ;
V_22 = L_9 ;
break;
case ( V_34 | V_39 ) :
F_15 = V_40 ;
V_22 = L_10 ;
break;
case ( V_41 | V_35 ) :
switch( V_26 -> V_32 & V_42 ) {
case 100 :
F_15 = V_43 ;
V_22 = L_11 ;
break;
case 101 :
F_15 = V_44 ;
V_22 = L_12 ;
break;
case 102 :
F_15 = V_45 ;
V_22 = L_13 ;
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_14 ,
V_26 -> V_32 & V_42 ) ;
break;
}
break;
case ( V_41 | V_37 ) :
switch( V_26 -> V_32 & V_42 ) {
case 100 :
F_15 = V_46 ;
V_22 = L_15 ;
break;
case 101 :
F_15 = V_47 ;
V_22 = L_16 ;
break;
case 102 :
F_15 = V_48 ;
V_22 = L_17 ;
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_18 ,
V_26 -> V_32 & V_42 ) ;
break;
}
break;
case ( V_41 | V_39 ) :
switch( V_26 -> V_32 & V_42 ) {
case 100 :
F_15 = V_49 ;
V_22 = L_19 ;
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_20 ,
V_26 -> V_32 & V_42 ) ;
break;
}
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_21 ) ;
return;
}
if( F_15 ) {
F_18 ( V_1 -> V_4 , V_5 , V_22 ) ;
while ( F_20 ( V_7 , V_8 ) > 0 ) {
V_19 = V_8 ;
V_8 = (* F_15)( FALSE , V_7 , V_8 , & V_23 , V_9 , - 1 ) ;
if( V_8 == V_19 ) {
F_9 ( V_9 , V_7 , V_8 , - 1 , L_22 ) ;
break;
}
}
}
}
void F_21 ( void ) {
static T_9 V_50 [] =
{
#include "packet-dop-hfarr.c"
} ;
static T_10 * V_51 [] = {
& V_30 ,
& V_16 ,
#include "packet-dop-ettarr.c"
} ;
static T_11 V_52 [] = {
{ & V_17 , { L_23 , V_53 , V_54 , L_24 , V_55 } } ,
} ;
T_12 * V_56 ;
T_13 * V_57 ;
V_28 = F_22 ( V_58 , V_59 , V_60 ) ;
F_23 ( L_25 , F_14 , V_28 ) ;
V_13 = F_24 ( L_26 , L_27 , V_61 , V_62 ) ;
F_25 ( V_28 , V_50 , F_26 ( V_50 ) ) ;
F_27 ( V_51 , F_26 ( V_51 ) ) ;
V_56 = F_28 ( V_28 ) ;
F_29 ( V_56 , V_52 , F_26 ( V_52 ) ) ;
V_57 = F_30 ( L_28 , V_28 , V_63 ) ;
F_31 ( V_57 , L_29 , L_30 ,
L_31
L_32 ,
10 , & V_64 ) ;
}
void F_32 ( void ) {
T_14 V_65 ;
#include "packet-dop-dis-tab.c"
F_33 ( L_33 , L_34 ) ;
V_65 = F_34 ( L_25 ) ;
F_35 ( L_35 , V_65 , 0 , L_36 , FALSE ) ;
F_33 ( L_37 , L_38 ) ;
F_33 ( L_39 , L_40 ) ;
F_33 ( L_41 , L_42 ) ;
F_33 ( L_43 , L_44 ) ;
F_33 ( L_45 , L_46 ) ;
F_33 ( L_47 , L_48 ) ;
F_33 ( L_49 , L_50 ) ;
F_33 ( L_51 , L_52 ) ;
F_33 ( L_53 , L_54 ) ;
F_33 ( L_55 , L_56 ) ;
F_33 ( L_57 , L_58 ) ;
F_33 ( L_59 , L_60 ) ;
F_33 ( L_61 , L_62 ) ;
F_33 ( L_63 , L_64 ) ;
F_33 ( L_65 , L_66 ) ;
F_33 ( L_67 , L_68 ) ;
V_66 = F_34 ( L_69 ) ;
}
static void
V_63 ( void )
{
static T_15 V_67 = 0 ;
if( ( V_67 > 0 ) && ( V_67 != 102 ) && V_66 )
F_36 ( L_29 , V_67 , V_66 ) ;
V_67 = V_64 ;
if( ( V_67 > 0 ) && ( V_67 != 102 ) && V_66 )
F_37 ( L_29 , V_67 , V_66 ) ;
}
