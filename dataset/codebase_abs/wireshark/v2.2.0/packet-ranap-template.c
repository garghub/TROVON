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
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_6 * V_25 = NULL ;
T_3 * V_26 = NULL ;
T_7 * V_27 = ( T_7 * ) T_4 ;
V_14 = 0 ;
V_9 = 0 ;
F_12 ( V_2 -> V_28 , V_29 , L_1 ) ;
V_25 = F_13 ( V_3 , V_30 , V_1 , 0 , - 1 , V_31 ) ;
V_26 = F_14 ( V_25 , V_32 ) ;
F_15 ( V_2 -> V_33 , V_2 , V_30 , V_2 -> V_34 , T_4 ) ;
F_16 ( V_1 , V_2 , V_26 , NULL ) ;
if ( V_27 ) {
if ( V_27 -> T_4 . V_35 . V_36 )
V_27 -> T_4 . V_35 . V_36 -> V_37 = V_38 ;
if ( ! V_27 -> T_4 . V_35 . V_39 && V_7 != 0xFFFFFFFF ) {
const T_8 * V_40 = F_17 ( V_7 , V_41 , L_2 ) ;
V_27 -> T_4 . V_35 . V_39 = F_18 ( F_19 () , V_40 ) ;
}
}
return F_20 ( V_1 ) ;
}
static T_5
F_21 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_9 V_42 ;
T_10 V_43 ;
T_11 V_44 ;
T_12 V_45 ;
int V_46 ;
F_22 ( & V_44 , V_47 , TRUE , V_2 ) ;
#define F_23 3
#define F_24 1
if ( F_3 ( V_1 ) < V_48 ) { return FALSE ; }
V_46 = F_25 ( V_1 , F_23 << 3 , & V_44 , V_3 , - 1 , & V_45 ) ;
V_46 = V_46 >> 3 ;
if ( V_45 != ( F_20 ( V_1 ) - V_46 ) ) {
return FALSE ;
}
V_42 = F_26 ( V_1 , F_24 ) ;
if ( V_42 > V_49 ) { return FALSE ; }
V_43 = F_27 ( V_1 , V_46 + 1 ) ;
if ( V_43 > 0x1ff ) {
return FALSE ;
}
F_11 ( V_1 , V_2 , V_3 , T_4 ) ;
return TRUE ;
}
void F_28 ( void ) {
T_13 * V_50 ;
static T_14 V_51 [] = {
{ & V_52 ,
{ L_3 , L_4 ,
V_53 , V_54 , NULL , 0 ,
NULL , V_55 } } ,
{ & V_56 ,
{ L_5 , L_6 ,
V_57 , V_54 , NULL , 0 ,
NULL , V_55 } } ,
{ & V_58 ,
{ L_7 , L_8 ,
V_59 , V_54 , NULL , 0 ,
NULL , V_55 } } ,
#include "packet-ranap-hfarr.c"
} ;
static T_15 * V_60 [] = {
& V_32 ,
& V_61 ,
& V_62 ,
#include "packet-ranap-ettarr.c"
} ;
V_30 = F_29 ( V_63 , V_64 , V_65 ) ;
F_30 ( V_30 , V_51 , F_31 ( V_51 ) ) ;
F_32 ( V_60 , F_31 ( V_60 ) ) ;
V_66 = F_33 ( L_9 , F_11 , V_30 ) ;
V_13 = F_34 ( L_10 , L_11 , V_30 , V_67 , V_68 ) ;
V_15 = F_34 ( L_12 , L_13 , V_30 , V_67 , V_68 ) ;
V_16 = F_34 ( L_14 , L_15 , V_30 , V_67 , V_68 ) ;
V_17 = F_34 ( L_16 , L_17 , V_30 , V_67 , V_68 ) ;
V_20 = F_34 ( L_18 , L_19 , V_30 , V_67 , V_68 ) ;
V_22 = F_34 ( L_20 , L_21 , V_30 , V_67 , V_68 ) ;
V_23 = F_34 ( L_22 , L_23 , V_30 , V_67 , V_68 ) ;
V_24 = F_34 ( L_24 , L_25 , V_30 , V_67 , V_68 ) ;
V_69 = F_34 ( L_26 , L_27 , V_30 , V_70 , V_68 ) ;
V_50 = F_35 ( V_30 , V_71 ) ;
F_36 ( V_50 , L_28 , L_29 ,
L_30 , 10 ,
& V_72 ) ;
F_37 ( V_50 , L_31 ,
L_32 ,
L_33 ,
& V_73 ) ;
}
void
V_71 ( void )
{
static T_5 V_74 = FALSE ;
static T_15 V_75 ;
if ( ! V_74 ) {
V_76 = F_38 ( L_34 , V_30 ) ;
V_77 = F_38 ( L_35 , V_30 ) ;
V_78 = F_39 ( L_36 ) ;
V_74 = TRUE ;
#include "packet-ranap-dis-tab.c"
} else {
F_40 ( L_37 , V_75 , V_66 ) ;
}
F_41 ( L_37 , V_72 , V_66 ) ;
V_75 = V_72 ;
F_42 ( L_38 , F_21 , L_39 , L_40 , V_30 , V_79 ) ;
F_42 ( L_41 , F_21 , L_42 , L_43 , V_30 , V_79 ) ;
}
