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
V_11 = F_5 ( L_2 , V_6 , V_12 ? V_12 : L_3 ) ;
F_3 ( V_1 -> V_4 , V_5 , L_1 , V_10 ) ;
if ( F_6 ( V_13 , V_11 , V_7 , V_1 , V_9 ) ) {
V_8 = F_7 ( V_7 ) ;
} else {
T_4 * V_14 = NULL ;
T_3 * V_15 = NULL ;
V_14 = F_8 ( V_9 , V_7 , 0 , F_9 ( V_7 , V_8 ) , L_4 , V_6 , V_12 ? V_12 : L_5 ) ;
if ( V_14 ) {
V_15 = F_10 ( V_14 , V_16 ) ;
}
V_8 = F_11 ( V_1 , V_7 , V_8 , V_15 ) ;
F_12 ( V_1 , V_14 , V_17 , V_18 , L_6 ) ;
}
return V_8 ;
}
static void
F_13 ( T_2 * V_7 , T_1 * V_1 , T_3 * V_19 )
{
int V_8 = 0 ;
int V_20 ;
T_4 * V_14 = NULL ;
T_3 * V_9 = NULL ;
int (* F_14)( T_5 T_6 V_21 , T_2 * V_7 , int V_8 , T_7 * V_22 , T_3 * V_9 , int T_8 V_21 ) = NULL ;
const char * V_23 ;
T_7 V_24 ;
F_15 ( & V_24 , V_25 , TRUE , V_1 ) ;
if( ! V_1 -> V_26 ) {
if( V_19 ) {
F_8 ( V_19 , V_7 , V_8 , - 1 ,
L_7 ) ;
}
return ;
} else {
V_27 = ( (struct V_28 * ) ( V_1 -> V_26 ) ) ;
}
if( V_19 ) {
V_14 = F_16 ( V_19 , V_29 , V_7 , 0 , - 1 , V_30 ) ;
V_9 = F_10 ( V_14 , V_31 ) ;
}
F_17 ( V_1 -> V_4 , V_32 , L_8 ) ;
F_18 ( V_1 -> V_4 , V_5 ) ;
switch( V_27 -> V_33 & V_34 ) {
case ( V_35 | V_36 ) :
F_14 = V_37 ;
V_23 = L_9 ;
break;
case ( V_35 | V_38 ) :
F_14 = V_39 ;
V_23 = L_10 ;
break;
case ( V_35 | V_40 ) :
F_14 = V_41 ;
V_23 = L_11 ;
break;
case ( V_42 | V_36 ) :
switch( V_27 -> V_33 & V_43 ) {
case 100 :
F_14 = V_44 ;
V_23 = L_12 ;
break;
case 101 :
F_14 = V_45 ;
V_23 = L_13 ;
break;
case 102 :
F_14 = V_46 ;
V_23 = L_14 ;
break;
default:
F_8 ( V_9 , V_7 , V_8 , - 1 , L_15 ,
V_27 -> V_33 & V_43 ) ;
break;
}
break;
case ( V_42 | V_38 ) :
switch( V_27 -> V_33 & V_43 ) {
case 100 :
F_14 = V_47 ;
V_23 = L_16 ;
break;
case 101 :
F_14 = V_48 ;
V_23 = L_17 ;
break;
case 102 :
F_14 = V_49 ;
V_23 = L_18 ;
break;
default:
F_8 ( V_9 , V_7 , V_8 , - 1 , L_19 ,
V_27 -> V_33 & V_43 ) ;
break;
}
break;
case ( V_42 | V_40 ) :
switch( V_27 -> V_33 & V_43 ) {
case 100 :
F_14 = V_50 ;
V_23 = L_20 ;
break;
default:
F_8 ( V_9 , V_7 , V_8 , - 1 , L_21 ,
V_27 -> V_33 & V_43 ) ;
break;
}
break;
default:
F_8 ( V_9 , V_7 , V_8 , - 1 , L_22 ) ;
return;
}
if( F_14 ) {
F_17 ( V_1 -> V_4 , V_5 , V_23 ) ;
while ( F_19 ( V_7 , V_8 ) > 0 ) {
V_20 = V_8 ;
V_8 = (* F_14)( FALSE , V_7 , V_8 , & V_24 , V_9 , - 1 ) ;
if( V_8 == V_20 ) {
F_8 ( V_9 , V_7 , V_8 , - 1 , L_23 ) ;
break;
}
}
}
}
void F_20 ( void ) {
static T_9 V_51 [] =
{
#include "packet-dop-hfarr.c"
} ;
static T_10 * V_52 [] = {
& V_31 ,
& V_16 ,
#include "packet-dop-ettarr.c"
} ;
T_11 * V_53 ;
V_29 = F_21 ( V_54 , V_55 , V_56 ) ;
F_22 ( L_24 , F_13 , V_29 ) ;
V_13 = F_23 ( L_25 , L_26 , V_57 , V_58 ) ;
F_24 ( V_29 , V_51 , F_25 ( V_51 ) ) ;
F_26 ( V_52 , F_25 ( V_52 ) ) ;
V_53 = F_27 ( L_27 , V_29 , V_59 ) ;
F_28 ( V_53 , L_28 , L_29 ,
L_30
L_31 ,
10 , & V_60 ) ;
}
void F_29 ( void ) {
T_12 V_61 ;
#include "packet-dop-dis-tab.c"
F_30 ( L_32 , L_33 ) ;
V_61 = F_31 ( L_24 ) ;
F_32 ( L_34 , V_61 , 0 , L_35 , FALSE ) ;
F_30 ( L_36 , L_37 ) ;
F_30 ( L_38 , L_39 ) ;
F_30 ( L_40 , L_41 ) ;
F_30 ( L_42 , L_43 ) ;
F_30 ( L_44 , L_45 ) ;
F_30 ( L_46 , L_47 ) ;
F_30 ( L_48 , L_49 ) ;
F_30 ( L_50 , L_51 ) ;
F_30 ( L_52 , L_53 ) ;
F_30 ( L_54 , L_55 ) ;
F_30 ( L_56 , L_57 ) ;
F_30 ( L_58 , L_59 ) ;
F_30 ( L_60 , L_61 ) ;
F_30 ( L_62 , L_63 ) ;
F_30 ( L_64 , L_65 ) ;
F_30 ( L_66 , L_67 ) ;
V_62 = F_31 ( L_68 ) ;
}
static void
V_59 ( void )
{
static T_13 V_63 = 0 ;
if( ( V_63 > 0 ) && ( V_63 != 102 ) && V_62 )
F_33 ( L_28 , V_63 , V_62 ) ;
V_63 = V_60 ;
if( ( V_63 > 0 ) && ( V_63 != 102 ) && V_62 )
F_34 ( L_28 , V_63 , V_62 ) ;
}
