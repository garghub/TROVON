static void F_1 ( T_1 * V_1 , const char * V_2 )
{
const char * V_3 = NULL ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_1 -> V_4 , V_5 , L_1 , V_3 ? V_3 : V_2 ) ;
}
static int
F_4 ( const char * V_6 , T_2 * V_7 , int V_8 , T_1 * V_1 , T_3 * V_9 , const char * V_10 , void * V_11 )
{
char * V_12 ;
V_12 = F_5 ( F_6 () , L_2 , V_6 , V_13 ? V_13 : L_3 ) ;
F_3 ( V_1 -> V_4 , V_5 , L_1 , V_10 ) ;
if ( F_7 ( V_14 , V_12 , V_7 , V_1 , V_9 , V_11 ) ) {
V_8 = F_8 ( V_7 ) ;
} else {
T_4 * V_15 = NULL ;
T_3 * V_16 = NULL ;
V_15 = F_9 ( V_9 , V_7 , 0 , F_10 ( V_7 , V_8 ) , L_4 , V_6 , V_13 ? V_13 : L_5 ) ;
if ( V_15 ) {
V_16 = F_11 ( V_15 , V_17 ) ;
}
V_8 = F_12 ( V_1 , V_7 , V_8 , V_16 ) ;
F_13 ( V_1 , V_15 , & V_18 ) ;
}
return V_8 ;
}
static int
F_14 ( T_2 * V_7 , T_1 * V_1 , T_3 * V_19 , void * V_11 )
{
int V_8 = 0 ;
int V_20 ;
T_4 * V_15 ;
T_3 * V_9 ;
struct V_21 * V_22 ;
int (* F_15)( T_5 T_6 V_23 , T_2 * V_7 , int V_8 , T_7 * V_24 , T_3 * V_9 , int T_8 V_23 ) = NULL ;
const char * V_25 ;
T_7 V_26 ;
if ( V_11 == NULL )
return 0 ;
V_22 = (struct V_21 * ) V_11 ;
F_16 ( & V_26 , V_27 , TRUE , V_1 ) ;
V_15 = F_17 ( V_19 , V_28 , V_7 , 0 , - 1 , V_29 ) ;
V_9 = F_11 ( V_15 , V_30 ) ;
F_18 ( V_1 -> V_4 , V_31 , L_6 ) ;
F_19 ( V_1 -> V_4 , V_5 ) ;
V_26 . V_32 = V_22 ;
switch( V_22 -> V_33 & V_34 ) {
case ( V_35 | V_36 ) :
F_15 = V_37 ;
V_25 = L_7 ;
break;
case ( V_35 | V_38 ) :
F_15 = V_39 ;
V_25 = L_8 ;
break;
case ( V_35 | V_40 ) :
F_15 = V_41 ;
V_25 = L_9 ;
break;
case ( V_42 | V_36 ) :
switch( V_22 -> V_33 & V_43 ) {
case 100 :
F_15 = V_44 ;
V_25 = L_10 ;
break;
case 101 :
F_15 = V_45 ;
V_25 = L_11 ;
break;
case 102 :
F_15 = V_46 ;
V_25 = L_12 ;
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_13 ,
V_22 -> V_33 & V_43 ) ;
break;
}
break;
case ( V_42 | V_38 ) :
switch( V_22 -> V_33 & V_43 ) {
case 100 :
F_15 = V_47 ;
V_25 = L_14 ;
break;
case 101 :
F_15 = V_48 ;
V_25 = L_15 ;
break;
case 102 :
F_15 = V_49 ;
V_25 = L_16 ;
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_17 ,
V_22 -> V_33 & V_43 ) ;
break;
}
break;
case ( V_42 | V_40 ) :
switch( V_22 -> V_33 & V_43 ) {
case 100 :
F_15 = V_50 ;
V_25 = L_18 ;
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_19 ,
V_22 -> V_33 & V_43 ) ;
break;
}
break;
default:
F_9 ( V_9 , V_7 , V_8 , - 1 , L_20 ) ;
return F_20 ( V_7 ) ;
}
if( F_15 ) {
F_18 ( V_1 -> V_4 , V_5 , V_25 ) ;
while ( F_21 ( V_7 , V_8 ) > 0 ) {
V_20 = V_8 ;
V_8 = (* F_15)( FALSE , V_7 , V_8 , & V_26 , V_9 , - 1 ) ;
if( V_8 == V_20 ) {
F_9 ( V_9 , V_7 , V_8 , - 1 , L_21 ) ;
break;
}
}
}
return F_20 ( V_7 ) ;
}
void F_22 ( void ) {
static T_9 V_51 [] =
{
#include "packet-dop-hfarr.c"
} ;
static T_10 * V_52 [] = {
& V_30 ,
& V_17 ,
#include "packet-dop-ettarr.c"
} ;
static T_11 V_53 [] = {
{ & V_18 , { L_22 , V_54 , V_55 , L_23 , V_56 } } ,
} ;
T_12 * V_57 ;
T_13 * V_58 ;
V_28 = F_23 ( V_59 , V_60 , V_61 ) ;
F_24 ( L_24 , F_14 , V_28 ) ;
V_14 = F_25 ( L_25 , L_26 , V_62 , V_63 ) ;
F_26 ( V_28 , V_51 , F_27 ( V_51 ) ) ;
F_28 ( V_52 , F_27 ( V_52 ) ) ;
V_57 = F_29 ( V_28 ) ;
F_30 ( V_57 , V_53 , F_27 ( V_53 ) ) ;
V_58 = F_31 ( L_27 , V_28 , V_64 ) ;
F_32 ( V_58 , L_28 , L_29 ,
L_30
L_31 ,
10 , & V_65 ) ;
}
void F_33 ( void ) {
T_14 V_66 ;
#include "packet-dop-dis-tab.c"
F_34 ( L_32 , L_33 ) ;
V_66 = F_35 ( L_24 ) ;
F_36 ( L_34 , V_66 , 0 , L_35 , FALSE ) ;
F_34 ( L_36 , L_37 ) ;
F_34 ( L_38 , L_39 ) ;
F_34 ( L_40 , L_41 ) ;
F_34 ( L_42 , L_43 ) ;
F_34 ( L_44 , L_45 ) ;
F_34 ( L_46 , L_47 ) ;
F_34 ( L_48 , L_49 ) ;
F_34 ( L_50 , L_51 ) ;
F_34 ( L_52 , L_53 ) ;
F_34 ( L_54 , L_55 ) ;
F_34 ( L_56 , L_57 ) ;
F_34 ( L_58 , L_59 ) ;
F_34 ( L_60 , L_61 ) ;
F_34 ( L_62 , L_63 ) ;
F_34 ( L_64 , L_65 ) ;
F_34 ( L_66 , L_67 ) ;
V_67 = F_35 ( L_68 ) ;
}
static void
V_64 ( void )
{
static T_15 V_68 = 0 ;
if( ( V_68 > 0 ) && ( V_68 != 102 ) && V_67 )
F_37 ( L_28 , V_68 , V_67 ) ;
V_68 = V_65 ;
if( ( V_68 > 0 ) && ( V_68 != 102 ) && V_67 )
F_38 ( L_28 , V_68 , V_67 ) ;
}
