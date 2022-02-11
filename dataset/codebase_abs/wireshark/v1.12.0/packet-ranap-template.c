static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
int V_5 = 0 ;
int V_6 ;
switch( V_7 ) {
case V_8 :
if( ( V_9 == V_10 ) || ( V_9 == V_11 ) ) {
V_6 = V_12 | V_9 ;
V_5 = ( F_2 ( V_13 , V_6 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
break;
}
default:
V_5 = ( F_2 ( V_13 , V_9 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
if ( V_5 == 0 ) {
V_6 = V_14 | V_9 ;
V_5 = ( F_2 ( V_13 , V_6 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
break;
}
return V_5 ;
}
static int
F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_15 , V_9 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_16 , V_9 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_17 , V_18 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
V_14 = V_19 ;
V_5 = F_2 ( V_20 , V_7 , V_1 , V_2 , V_3 , FALSE , NULL ) ;
V_14 = 0 ;
return V_5 ? F_3 ( V_1 ) : 0 ;
}
static int
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
V_14 = V_21 ;
V_5 = F_2 ( V_22 , V_7 , V_1 , V_2 , V_3 , FALSE , NULL ) ;
V_14 = 0 ;
return V_5 ? F_3 ( V_1 ) : 0 ;
}
static int
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_23 , V_7 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static int
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_24 , V_7 , V_1 , V_2 , V_3 , FALSE , NULL ) ) ? F_3 ( V_1 ) : 0 ;
}
static void
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_6 * V_25 = NULL ;
T_3 * V_26 = NULL ;
V_14 = 0 ;
V_9 = 0 ;
F_12 ( V_2 -> V_27 , V_28 , L_1 ) ;
V_25 = F_13 ( V_3 , V_29 , V_1 , 0 , - 1 , V_30 ) ;
V_26 = F_14 ( V_25 , V_31 ) ;
F_15 ( V_1 , V_2 , V_26 , NULL ) ;
if ( V_2 -> V_32 ) {
T_7 * V_33 = V_2 -> V_32 ;
if ( V_33 -> T_4 . V_34 . V_35 )
V_33 -> T_4 . V_34 . V_35 -> V_36 = V_37 ;
if ( ! V_33 -> T_4 . V_34 . V_38 && V_7 != 0xFFFFFFFF ) {
const T_8 * V_39 = F_16 ( V_7 , V_40 , L_2 ) ;
V_33 -> T_4 . V_34 . V_38 = F_17 ( F_18 () , V_39 ) ;
}
}
}
static T_5
F_19 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_9 V_41 ;
T_10 V_42 ;
T_11 V_43 ;
T_12 V_44 ;
int V_45 ;
F_20 ( & V_43 , V_46 , TRUE , V_2 ) ;
#define F_21 3
#define F_22 1
if ( F_3 ( V_1 ) < V_47 ) { return FALSE ; }
V_45 = F_23 ( V_1 , F_21 << 3 , & V_43 , V_3 , - 1 , & V_44 ) ;
V_45 = V_45 >> 3 ;
if ( V_44 != ( F_3 ( V_1 ) - V_45 ) ) {
return FALSE ;
}
V_41 = F_24 ( V_1 , F_22 ) ;
if ( V_41 > V_48 ) { return FALSE ; }
V_42 = F_25 ( V_1 , 5 ) ;
if( V_42 > 0x1ff ) {
return FALSE ;
}
F_11 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
}
void F_26 ( void ) {
T_13 * V_49 ;
static T_14 V_50 [] = {
{ & V_51 ,
{ L_3 , L_4 ,
V_52 , V_53 , NULL , 0 ,
NULL , V_54 } } ,
{ & V_55 ,
{ L_5 , L_6 ,
V_56 , V_53 , NULL , 0 ,
NULL , V_54 } } ,
{ & V_57 ,
{ L_7 , L_8 ,
V_58 , V_53 , NULL , 0 ,
NULL , V_54 } } ,
{ & V_59 ,
{ L_9 , L_10 ,
V_60 , V_53 , NULL , 0 ,
NULL , V_54 } } ,
#include "packet-ranap-hfarr.c"
} ;
static T_15 * V_61 [] = {
& V_31 ,
& V_62 ,
& V_63 ,
#include "packet-ranap-ettarr.c"
} ;
V_29 = F_27 ( V_64 , V_65 , V_66 ) ;
F_28 ( V_29 , V_50 , F_29 ( V_50 ) ) ;
F_30 ( V_61 , F_29 ( V_61 ) ) ;
F_31 ( L_11 , F_11 , V_29 ) ;
V_13 = F_32 ( L_12 , L_13 , V_67 , V_68 ) ;
V_15 = F_32 ( L_14 , L_15 , V_67 , V_68 ) ;
V_16 = F_32 ( L_16 , L_17 , V_67 , V_68 ) ;
V_17 = F_32 ( L_18 , L_19 , V_67 , V_68 ) ;
V_20 = F_32 ( L_20 , L_21 , V_67 , V_68 ) ;
V_22 = F_32 ( L_22 , L_23 , V_67 , V_68 ) ;
V_23 = F_32 ( L_24 , L_25 , V_67 , V_68 ) ;
V_24 = F_32 ( L_26 , L_27 , V_67 , V_68 ) ;
V_69 = F_32 ( L_28 , L_29 , V_70 , V_68 ) ;
V_49 = F_33 ( V_29 , V_71 ) ;
F_34 ( V_49 , L_30 , L_31 ,
L_32 , 10 ,
& V_72 ) ;
F_35 ( V_49 , L_33 ,
L_34 ,
L_35 ,
& V_73 ) ;
}
void
V_71 ( void )
{
static T_5 V_74 = FALSE ;
static T_16 V_75 ;
static T_15 V_76 ;
if ( ! V_74 ) {
V_75 = F_36 ( L_11 ) ;
V_77 = F_36 ( L_36 ) ;
V_78 = F_36 ( L_37 ) ;
V_79 = F_36 ( L_38 ) ;
V_74 = TRUE ;
#include "packet-ranap-dis-tab.c"
} else {
F_37 ( L_39 , V_76 , V_75 ) ;
}
F_38 ( L_39 , V_72 , V_75 ) ;
V_76 = V_72 ;
F_39 ( L_40 , F_19 , V_29 ) ;
F_39 ( L_41 , F_19 , V_29 ) ;
}
