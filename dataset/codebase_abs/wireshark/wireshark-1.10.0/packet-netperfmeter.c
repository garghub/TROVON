static void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
F_2 ( V_2 , V_5 ) ;
F_2 ( V_2 , V_6 ) ;
}
static void
F_3 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 V_7 ;
T_4 * V_8 ;
T_2 * V_9 ;
T_5 V_10 ;
T_3 V_11 ;
unsigned int V_12 ;
F_2 ( V_2 , V_13 ) ;
F_2 ( V_2 , V_14 ) ;
F_2 ( V_2 , V_15 ) ;
F_2 ( V_2 , V_16 ) ;
F_2 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 , V_19 , V_1 , V_20 , V_21 ,
100.0 * F_6 ( V_1 , V_20 ) / ( double ) 0xffffffff , L_1 ,
100.0 * F_6 ( V_1 , V_20 ) / ( double ) 0xffffffff ) ;
F_5 ( V_2 , V_22 , V_1 , V_23 , V_24 ,
100.0 * F_6 ( V_1 , V_23 ) / ( double ) 0xffffffff , L_1 ,
100.0 * F_6 ( V_1 , V_23 ) / ( double ) 0xffffffff ) ;
V_7 = F_6 ( V_1 , V_25 ) ;
F_7 ( V_2 , V_26 , V_1 , V_25 , V_27 ,
V_7 , ( V_7 & ( 1 << 31 ) ) ? L_2 : L_3 ,
V_7 & ~ ( 1 << 31 ) ) ;
F_2 ( V_2 , V_28 ) ;
F_2 ( V_2 , V_29 ) ;
F_2 ( V_2 , V_30 ) ;
F_2 ( V_2 , V_31 ) ;
F_2 ( V_2 , V_32 ) ;
F_2 ( V_2 , V_33 ) ;
F_2 ( V_2 , V_34 ) ;
F_2 ( V_2 , V_35 ) ;
F_2 ( V_2 , V_36 ) ;
F_2 ( V_2 , V_37 ) ;
F_2 ( V_2 , V_38 ) ;
F_2 ( V_2 , V_39 ) ;
F_2 ( V_2 , V_40 ) ;
F_2 ( V_2 , V_41 ) ;
F_2 ( V_2 , V_42 ) ;
V_8 = F_2 ( V_2 , V_43 ) ;
V_10 = F_8 ( V_1 , V_44 ) ;
if ( V_10 > 0 ) {
V_9 = F_9 ( V_8 , V_45 ) ;
for( V_12 = 0 ; V_12 < V_10 ; V_12 ++ ) {
V_11 = F_6 ( V_1 , V_46 + ( int ) ( sizeof( T_3 ) * V_12 ) ) ;
F_10 ( V_9 , V_47 , V_1 ,
V_46 + ( int ) ( sizeof( T_3 ) * V_12 ) , ( int ) sizeof( T_3 ) ,
V_11 , L_4 , V_11 / 1000.0 , ( V_12 & 1 ) ? L_5 : L_6 ) ;
}
}
}
static void
F_11 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_48 ) ;
F_2 ( V_2 , V_49 ) ;
F_2 ( V_2 , V_50 ) ;
}
static void
F_12 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_51 ) ;
F_2 ( V_2 , V_52 ) ;
F_2 ( V_2 , V_53 ) ;
F_2 ( V_2 , V_54 ) ;
}
static void
F_13 ( T_1 * V_1 , T_2 * V_2 )
{
const T_5 V_55 = F_8 ( V_1 , V_56 ) ;
F_2 ( V_2 , V_57 ) ;
F_2 ( V_2 , V_58 ) ;
F_2 ( V_2 , V_59 ) ;
F_2 ( V_2 , V_60 ) ;
F_2 ( V_2 , V_61 ) ;
F_2 ( V_2 , V_62 ) ;
F_2 ( V_2 , V_63 ) ;
F_2 ( V_2 , V_64 ) ;
if ( V_55 > V_65 ) {
F_14 ( V_2 , V_66 , V_1 , V_65 , V_55 - V_65 , V_67 ) ;
}
}
static void
F_15 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_68 ) ;
}
static void
F_16 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_69 ) ;
}
static void
F_17 ( T_1 * V_1 , T_2 * V_2 )
{
const T_5 V_55 = F_18 ( V_1 , V_56 ) ;
if ( V_55 > V_70 ) {
F_14 ( V_2 , V_71 , V_1 , V_70 , V_55 - V_70 , V_67 ) ;
}
}
static void
F_19 ( T_1 * V_1 , T_6 * V_72 , T_2 * V_73 )
{
T_7 type ;
type = F_18 ( V_1 , V_74 ) ;
if ( F_20 ( V_72 -> V_75 , V_76 ) ) {
F_21 ( V_72 -> V_75 , V_76 , L_7 , F_22 ( type , V_77 , L_8 ) ) ;
}
F_2 ( V_73 , V_78 ) ;
F_2 ( V_73 , V_79 ) ;
F_2 ( V_73 , V_55 ) ;
switch ( type ) {
case V_80 :
F_1 ( V_1 , V_73 ) ;
break;
case V_81 :
F_3 ( V_1 , V_73 ) ;
break;
case V_82 :
F_11 ( V_1 , V_73 ) ;
break;
case V_83 :
F_12 ( V_1 , V_73 ) ;
break;
case V_84 :
F_13 ( V_1 , V_73 ) ;
break;
case V_85 :
F_15 ( V_1 , V_73 ) ;
break;
case V_86 :
F_16 ( V_1 , V_73 ) ;
break;
case V_87 :
F_17 ( V_1 , V_73 ) ;
break;
}
}
static int
F_23 ( T_1 * V_1 , T_6 * V_72 , T_2 * V_88 , void * T_8 V_89 )
{
T_4 * V_90 ;
T_2 * V_73 ;
F_24 ( V_72 -> V_75 , V_91 , L_9 ) ;
if ( V_88 ) {
V_90 = F_14 ( V_88 , V_92 , V_1 , 0 , - 1 , V_67 ) ;
V_73 = F_9 ( V_90 , V_93 ) ;
} else {
V_73 = NULL ;
} ;
F_19 ( V_1 , V_72 , V_73 ) ;
return ( TRUE ) ;
}
void
F_25 ( void )
{
static T_9 * V_94 [] = {
& V_93 ,
& V_45
} ;
V_92 = F_26 ( L_10 , L_9 , L_11 ) ;
F_27 ( V_92 , V_95 , F_28 ( V_95 ) ) ;
F_29 ( V_94 , F_28 ( V_94 ) ) ;
}
void
F_30 ( void )
{
T_10 V_96 ;
V_96 = F_31 ( F_23 , V_92 ) ;
F_32 ( L_12 , V_97 , V_96 ) ;
F_32 ( L_12 , V_98 , V_96 ) ;
F_32 ( L_12 , V_99 , V_96 ) ;
F_32 ( L_12 , V_100 , V_96 ) ;
}
