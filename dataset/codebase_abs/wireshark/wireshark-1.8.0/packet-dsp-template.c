static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
int V_5 ;
T_4 * V_6 = NULL ;
T_3 * V_7 = NULL ;
int (* F_2)( T_5 T_6 V_8 , T_1 * V_1 , int V_4 , T_7 * V_9 , T_3 * V_7 , int T_8 V_8 ) = NULL ;
char * V_10 ;
T_7 V_11 ;
F_3 ( & V_11 , V_12 , TRUE , V_2 ) ;
if( ! V_2 -> V_13 ) {
if( V_3 ) {
F_4 ( V_3 , V_1 , V_4 , - 1 ,
L_1 ) ;
}
return ;
} else {
V_14 = ( (struct V_15 * ) ( V_2 -> V_13 ) ) ;
}
if( V_3 ) {
V_6 = F_5 ( V_3 , V_16 , V_1 , 0 , - 1 , V_17 ) ;
V_7 = F_6 ( V_6 , V_18 ) ;
}
F_7 ( V_2 -> V_19 , V_20 , L_2 ) ;
F_8 ( V_2 -> V_19 , V_21 ) ;
switch( V_14 -> V_22 & V_23 ) {
case ( V_24 | V_25 ) :
F_2 = V_26 ;
V_10 = L_3 ;
break;
case ( V_24 | V_27 ) :
F_2 = V_28 ;
V_10 = L_4 ;
break;
case ( V_24 | V_29 ) :
F_2 = V_30 ;
V_10 = L_5 ;
break;
case ( V_31 | V_25 ) :
switch( V_14 -> V_22 & V_32 ) {
case 1 :
F_2 = V_33 ;
V_10 = L_6 ;
break;
case 2 :
F_2 = V_34 ;
V_10 = L_7 ;
break;
case 3 :
F_2 = V_35 ;
V_10 = L_8 ;
break;
case 4 :
F_2 = V_36 ;
V_10 = L_9 ;
break;
case 5 :
F_2 = V_37 ;
V_10 = L_10 ;
break;
case 6 :
F_2 = V_38 ;
V_10 = L_11 ;
break;
case 7 :
F_2 = V_39 ;
V_10 = L_12 ;
break;
case 8 :
F_2 = V_40 ;
V_10 = L_13 ;
break;
case 9 :
F_2 = V_41 ;
V_10 = L_14 ;
break;
default:
F_4 ( V_7 , V_1 , V_4 , - 1 , L_15 ,
V_14 -> V_22 & V_32 ) ;
break;
}
break;
case ( V_31 | V_27 ) :
switch( V_14 -> V_22 & V_32 ) {
case 1 :
F_2 = V_42 ;
V_10 = L_16 ;
break;
case 2 :
F_2 = V_43 ;
V_10 = L_17 ;
break;
case 3 :
F_2 = V_44 ;
V_10 = L_18 ;
break;
case 4 :
F_2 = V_45 ;
V_10 = L_19 ;
break;
case 5 :
F_2 = V_46 ;
V_10 = L_20 ;
break;
case 6 :
F_2 = V_47 ;
V_10 = L_21 ;
break;
case 7 :
F_2 = V_48 ;
V_10 = L_22 ;
break;
case 8 :
F_2 = V_49 ;
V_10 = L_23 ;
break;
case 9 :
F_2 = V_50 ;
V_10 = L_24 ;
break;
default:
F_4 ( V_7 , V_1 , V_4 , - 1 , L_25 ) ;
break;
}
break;
case ( V_31 | V_29 ) :
switch( V_14 -> V_22 & V_32 ) {
case 1 :
F_2 = V_51 ;
V_10 = L_26 ;
break;
case 2 :
F_2 = V_52 ;
V_10 = L_27 ;
break;
case 3 :
F_2 = V_53 ;
V_10 = L_28 ;
break;
case 4 :
F_2 = V_54 ;
V_10 = L_29 ;
break;
case 5 :
F_2 = V_55 ;
V_10 = L_30 ;
break;
case 6 :
F_2 = V_56 ;
V_10 = L_31 ;
break;
case 7 :
F_2 = V_57 ;
V_10 = L_32 ;
break;
case 8 :
F_2 = V_58 ;
V_10 = L_33 ;
break;
case 9 :
F_2 = V_59 ;
V_10 = L_34 ;
break;
default:
F_4 ( V_7 , V_1 , V_4 , - 1 , L_35 ) ;
break;
}
break;
default:
F_4 ( V_7 , V_1 , V_4 , - 1 , L_36 ) ;
return;
}
if( F_2 ) {
F_7 ( V_2 -> V_19 , V_21 , V_10 ) ;
while ( F_9 ( V_1 , V_4 ) > 0 ) {
V_5 = V_4 ;
V_4 = (* F_2)( FALSE , V_1 , V_4 , & V_11 , V_7 , - 1 ) ;
if( V_4 == V_5 ) {
F_4 ( V_7 , V_1 , V_4 , - 1 , L_37 ) ;
break;
}
}
}
}
void F_10 ( void ) {
static T_9 V_60 [] =
{
#include "packet-dsp-hfarr.c"
} ;
static T_10 * V_61 [] = {
& V_18 ,
#include "packet-dsp-ettarr.c"
} ;
T_11 * V_62 ;
V_16 = F_11 ( V_63 , V_64 , V_65 ) ;
F_12 ( L_38 , F_1 , V_16 ) ;
F_13 ( V_16 , V_60 , F_14 ( V_60 ) ) ;
F_15 ( V_61 , F_14 ( V_61 ) ) ;
V_62 = F_16 ( L_39 , V_16 , V_66 ) ;
F_17 ( V_62 , L_40 , L_41 ,
L_42
L_43 ,
10 , & V_67 ) ;
}
void F_18 ( void ) {
T_12 V_68 ;
#include "packet-dsp-dis-tab.c"
F_19 ( L_44 , L_45 ) ;
V_69 = F_20 ( L_46 ) ;
V_68 = F_20 ( L_38 ) ;
F_21 ( L_47 , V_68 , 0 , L_48 , FALSE ) ;
}
static void
V_66 ( void )
{
static T_13 V_70 = 0 ;
if( ( V_70 > 0 ) && ( V_70 != 102 ) && V_69 )
F_22 ( L_40 , V_70 , V_69 ) ;
V_70 = V_67 ;
if( ( V_70 > 0 ) && ( V_70 != 102 ) && V_69 )
F_23 ( L_40 , V_67 , V_69 ) ;
}
