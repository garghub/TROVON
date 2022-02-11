static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
int V_5 ;
switch( V_6 ) {
case V_7 :
if( ( V_8 == V_9 ) || ( V_8 == V_10 ) ) {
V_5 = V_11 | V_8 ;
V_4 = ( F_2 ( V_12 , V_5 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
break;
}
default:
V_4 = ( F_2 ( V_12 , V_8 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
if ( V_4 == 0 ) {
V_5 = V_13 | V_8 ;
V_4 = ( F_2 ( V_12 , V_5 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
break;
}
return V_4 ;
}
static int
F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_14 , V_8 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_15 , V_8 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_16 , V_17 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
V_13 = V_18 ;
V_4 = F_2 ( V_19 , V_6 , V_1 , V_2 , V_3 , FALSE ) ;
V_13 = 0 ;
return V_4 ? F_3 ( V_1 ) : 0 ;
}
static int
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
V_13 = V_20 ;
V_4 = F_2 ( V_21 , V_6 , V_1 , V_2 , V_3 , FALSE ) ;
V_13 = 0 ;
return V_4 ? F_3 ( V_1 ) : 0 ;
}
static int
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_22 , V_6 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_23 , V_6 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static void
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_5 * V_24 = NULL ;
T_3 * V_25 = NULL ;
V_13 = 0 ;
V_8 = 0 ;
F_12 ( V_2 -> V_26 , V_27 , L_1 ) ;
V_24 = F_13 ( V_3 , V_28 , V_1 , 0 , - 1 , V_29 ) ;
V_25 = F_14 ( V_24 , V_30 ) ;
F_15 ( V_1 , V_2 , V_25 ) ;
if ( V_2 -> V_31 ) {
T_6 * V_32 = V_2 -> V_31 ;
if ( V_32 -> V_33 . V_34 . V_35 )
V_32 -> V_33 . V_34 . V_35 -> V_36 = V_37 ;
if ( ! V_32 -> V_33 . V_34 . V_38 && V_6 != 0xFFFFFFFF ) {
const T_7 * V_39 = F_16 ( V_6 , V_40 , L_2 ) ;
V_32 -> V_33 . V_34 . V_38 = F_17 ( V_39 ) ;
}
}
}
static T_4
F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_8 V_41 ;
T_9 V_42 ;
T_10 V_43 ;
int V_44 ;
F_19 ( & V_42 , V_45 , TRUE , V_2 ) ;
#define F_20 3
#define F_21 1
if ( F_3 ( V_1 ) < 4 ) { return FALSE ; }
V_44 = F_22 ( V_1 , F_20 << 3 , & V_42 , V_3 , - 1 , & V_43 ) ;
V_44 = V_44 >> 3 ;
if ( V_43 != ( F_3 ( V_1 ) - V_44 ) ) {
return FALSE ;
}
V_41 = F_23 ( V_1 , F_21 ) ;
if ( V_41 > V_46 ) { return FALSE ; }
F_11 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
}
void F_24 ( void ) {
T_11 * V_47 ;
static T_12 V_48 [] = {
{ & V_49 ,
{ L_3 , L_4 ,
V_50 , V_51 , NULL , 0 ,
NULL , V_52 } } ,
{ & V_53 ,
{ L_5 , L_6 ,
V_54 , V_51 , NULL , 0 ,
NULL , V_52 } } ,
{ & V_55 ,
{ L_7 , L_8 ,
V_56 , V_51 , NULL , 0 ,
NULL , V_52 } } ,
{ & V_57 ,
{ L_9 , L_10 ,
V_58 , V_51 , NULL , 0 ,
NULL , V_52 } } ,
#include "packet-ranap-hfarr.c"
} ;
static T_13 * V_59 [] = {
& V_30 ,
& V_60 ,
& V_61 ,
#include "packet-ranap-ettarr.c"
} ;
V_28 = F_25 ( V_62 , V_63 , V_64 ) ;
F_26 ( V_28 , V_48 , F_27 ( V_48 ) ) ;
F_28 ( V_59 , F_27 ( V_59 ) ) ;
F_29 ( L_11 , F_11 , V_28 ) ;
V_12 = F_30 ( L_12 , L_13 , V_65 , V_66 ) ;
V_14 = F_30 ( L_14 , L_15 , V_65 , V_66 ) ;
V_15 = F_30 ( L_16 , L_17 , V_65 , V_66 ) ;
V_16 = F_30 ( L_18 , L_19 , V_65 , V_66 ) ;
V_19 = F_30 ( L_20 , L_21 , V_65 , V_66 ) ;
V_21 = F_30 ( L_22 , L_23 , V_65 , V_66 ) ;
V_22 = F_30 ( L_24 , L_25 , V_65 , V_66 ) ;
V_23 = F_30 ( L_26 , L_27 , V_65 , V_66 ) ;
V_67 = F_30 ( L_28 , L_29 , V_68 , V_66 ) ;
V_47 = F_31 ( V_28 , V_69 ) ;
F_32 ( V_47 , L_30 , L_31 ,
L_32 , 10 ,
& V_70 ) ;
}
void
V_69 ( void )
{
static T_4 V_71 = FALSE ;
static T_14 V_72 ;
static T_13 V_73 ;
if ( ! V_71 ) {
V_72 = F_33 ( L_11 ) ;
V_74 = F_33 ( L_33 ) ;
V_75 = F_33 ( L_34 ) ;
V_76 = F_33 ( L_35 ) ;
V_71 = TRUE ;
#include "packet-ranap-dis-tab.c"
} else {
F_34 ( L_36 , V_73 , V_72 ) ;
}
F_35 ( L_36 , V_70 , V_72 ) ;
V_73 = V_70 ;
F_36 ( L_37 , F_18 , V_28 ) ;
F_36 ( L_38 , F_18 , V_28 ) ;
}
