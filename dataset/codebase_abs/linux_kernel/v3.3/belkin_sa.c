static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_7 ) ;
if ( ! V_6 )
return - 1 ;
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = 0 ;
V_6 -> V_12 =
( F_4 ( V_4 -> V_13 . V_14 ) <= 0x0206 ) ? 1 : 0 ;
F_5 ( & V_4 -> V_4 , L_1 ,
F_4 ( V_4 -> V_13 . V_14 ) ,
V_6 -> V_12 ) ;
F_6 ( & V_2 -> V_15 [ 0 ] -> V_16 ) ;
F_7 ( V_2 -> V_15 [ 0 ] , V_6 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_17 ;
F_9 ( L_2 , V_18 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_19 ; ++ V_17 )
F_10 ( F_11 ( V_2 -> V_15 [ V_17 ] ) ) ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_22 * V_15 )
{
int V_23 ;
F_9 ( L_3 , V_18 , V_15 -> V_24 ) ;
V_23 = F_13 ( V_15 -> V_25 , V_7 ) ;
if ( V_23 ) {
F_14 ( & V_15 -> V_4 , L_4 ) ;
return V_23 ;
}
V_23 = F_15 ( V_21 , V_15 ) ;
if ( V_23 )
F_16 ( V_15 -> V_25 ) ;
return V_23 ;
}
static void F_17 ( struct V_22 * V_15 )
{
F_9 ( L_3 , V_18 , V_15 -> V_24 ) ;
F_18 ( V_15 ) ;
F_16 ( V_15 -> V_25 ) ;
}
static void F_19 ( struct V_26 * V_26 )
{
struct V_22 * V_15 = V_26 -> V_27 ;
struct V_5 * V_6 ;
unsigned char * V_28 = V_26 -> V_29 ;
int V_23 ;
int V_30 = V_26 -> V_30 ;
unsigned long V_31 ;
switch ( V_30 ) {
case 0 :
break;
case - V_32 :
case - V_33 :
case - V_34 :
F_9 ( L_5 ,
V_18 , V_30 ) ;
return;
default:
F_9 ( L_6 ,
V_18 , V_30 ) ;
goto exit;
}
F_20 ( V_35 , & V_15 -> V_4 , V_18 ,
V_26 -> V_36 , V_28 ) ;
V_6 = F_11 ( V_15 ) ;
F_21 ( & V_6 -> V_8 , V_31 ) ;
V_6 -> V_11 = V_28 [ V_37 ] ;
if ( V_6 -> V_11 & V_38 )
V_6 -> V_9 |= V_39 ;
else
V_6 -> V_9 &= ~ V_39 ;
if ( V_6 -> V_11 & V_40 )
V_6 -> V_9 |= V_41 ;
else
V_6 -> V_9 &= ~ V_41 ;
if ( V_6 -> V_11 & V_42 )
V_6 -> V_9 |= V_43 ;
else
V_6 -> V_9 &= ~ V_43 ;
if ( V_6 -> V_11 & V_44 )
V_6 -> V_9 |= V_45 ;
else
V_6 -> V_9 &= ~ V_45 ;
V_6 -> V_10 = V_28 [ V_46 ] ;
F_22 ( & V_6 -> V_8 , V_31 ) ;
exit:
V_23 = F_13 ( V_26 , V_47 ) ;
if ( V_23 )
F_14 ( & V_15 -> V_4 , L_7
L_8 , V_18 , V_23 ) ;
}
static void F_23 ( struct V_26 * V_26 )
{
struct V_22 * V_15 = V_26 -> V_27 ;
struct V_5 * V_6 = F_11 ( V_15 ) ;
struct V_20 * V_21 ;
unsigned char * V_28 = V_26 -> V_29 ;
unsigned long V_31 ;
unsigned char V_30 ;
char V_48 ;
V_48 = V_49 ;
F_21 ( & V_6 -> V_8 , V_31 ) ;
V_30 = V_6 -> V_10 ;
V_6 -> V_10 &= ~ V_50 ;
F_22 ( & V_6 -> V_8 , V_31 ) ;
if ( ! V_26 -> V_36 )
return;
V_21 = F_24 ( & V_15 -> V_15 ) ;
if ( ! V_21 )
return;
if ( V_30 & V_50 ) {
if ( V_30 & V_51 )
V_48 = V_52 ;
else if ( V_30 & V_53 )
V_48 = V_54 ;
else if ( V_30 & V_55 )
V_48 = V_56 ;
F_25 ( & V_15 -> V_4 , L_9 , V_48 ) ;
if ( V_30 & V_57 )
F_26 ( V_21 , 0 , V_58 ) ;
}
F_27 ( V_21 , V_28 , V_48 ,
V_26 -> V_36 ) ;
F_28 ( V_21 ) ;
F_29 ( V_21 ) ;
}
static void F_30 ( struct V_20 * V_21 ,
struct V_22 * V_15 , struct V_59 * V_60 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_5 * V_6 = F_11 ( V_15 ) ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_63 = 0 ;
unsigned int V_64 = 0 ;
T_1 V_65 = 0 ;
unsigned long V_31 ;
unsigned long V_9 ;
int V_12 ;
T_2 V_66 ;
struct V_59 * V_67 = V_21 -> V_67 ;
V_61 = V_67 -> V_68 ;
V_62 = V_67 -> V_69 ;
V_67 -> V_69 &= ~ V_70 ;
F_21 ( & V_6 -> V_8 , V_31 ) ;
V_9 = V_6 -> V_9 ;
V_12 = V_6 -> V_12 ;
F_22 ( & V_6 -> V_8 , V_31 ) ;
V_63 = V_60 -> V_68 ;
V_64 = V_60 -> V_69 ;
if ( ( V_62 & V_71 ) != ( V_64 & V_71 ) ) {
if ( ( V_64 & V_71 ) == V_72 ) {
V_9 |= ( V_73 | V_74 ) ;
if ( F_31 ( V_75 , 1 ) < 0 )
F_14 ( & V_15 -> V_4 , L_10 ) ;
if ( ! ( V_64 & V_76 ) )
if ( F_31 ( V_77
, 1 ) < 0 )
F_14 ( & V_15 -> V_4 , L_11 ) ;
}
}
V_66 = F_32 ( V_21 ) ;
if ( V_66 ) {
V_65 = F_33 ( V_66 ) ;
if ( V_65 == 0 )
V_65 = 1 ;
V_66 = F_33 ( V_65 ) ;
F_34 ( V_21 , V_66 , V_66 ) ;
if ( F_31 ( V_78 , V_65 ) < 0 )
F_14 ( & V_15 -> V_4 , L_12 ) ;
} else {
if ( F_31 ( V_79 ,
V_80 ) < 0 )
F_14 ( & V_15 -> V_4 , L_13 ) ;
V_9 &= ~ ( V_73 | V_74 ) ;
if ( F_31 ( V_75 , 0 ) < 0 )
F_14 ( & V_15 -> V_4 , L_14 ) ;
if ( F_31 ( V_77 , 0 ) < 0 )
F_14 ( & V_15 -> V_4 , L_15 ) ;
}
if ( ( V_62 ^ V_64 ) & ( V_81 | V_82 ) ) {
if ( V_62 & V_81 )
V_65 = ( V_62 & V_82 ) ? V_83
: V_84 ;
else
V_65 = V_85 ;
if ( F_31 ( V_86 , V_65 ) < 0 )
F_14 ( & V_15 -> V_4 , L_16 ) ;
}
if ( ( V_62 & V_87 ) != ( V_64 & V_87 ) ) {
switch ( V_62 & V_87 ) {
case V_88 :
V_65 = F_35 ( 5 ) ;
break;
case V_89 :
V_65 = F_35 ( 6 ) ;
break;
case V_90 :
V_65 = F_35 ( 7 ) ;
break;
case V_91 :
V_65 = F_35 ( 8 ) ;
break;
default: F_9 ( L_17 ) ;
V_65 = F_35 ( 8 ) ;
break;
}
if ( F_31 ( V_92 , V_65 ) < 0 )
F_14 ( & V_15 -> V_4 , L_18 ) ;
}
if ( ( V_62 & V_93 ) != ( V_64 & V_93 ) ) {
V_65 = ( V_62 & V_93 ) ? F_36 ( 2 )
: F_36 ( 1 ) ;
if ( F_31 ( V_94 ,
V_65 ) < 0 )
F_14 ( & V_15 -> V_4 , L_19 ) ;
}
if ( ( ( V_61 ^ V_63 ) & ( V_95 | V_96 ) ) ||
( ( V_62 ^ V_64 ) & V_76 ) ) {
V_65 = 0 ;
if ( ( V_61 & V_95 ) || ( V_61 & V_96 ) )
V_65 |= ( V_97 | V_98 ) ;
else
V_65 &= ~ ( V_97 | V_98 ) ;
if ( V_62 & V_76 )
V_65 |= ( V_99 | V_100 ) ;
else
V_65 &= ~ ( V_99 | V_100 ) ;
if ( V_12 )
V_65 &= ~ ( V_100 ) ;
if ( F_31 ( V_79 , V_65 ) < 0 )
F_14 ( & V_15 -> V_4 , L_20 ) ;
}
F_21 ( & V_6 -> V_8 , V_31 ) ;
V_6 -> V_9 = V_9 ;
F_22 ( & V_6 -> V_8 , V_31 ) ;
}
static void F_37 ( struct V_20 * V_21 , int V_101 )
{
struct V_22 * V_15 = V_21 -> V_102 ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( F_31 ( V_103 , V_101 ? 1 : 0 ) < 0 )
F_14 ( & V_15 -> V_4 , L_21 , V_101 ) ;
}
static int F_38 ( struct V_20 * V_21 )
{
struct V_22 * V_15 = V_21 -> V_102 ;
struct V_5 * V_6 = F_11 ( V_15 ) ;
unsigned long V_9 ;
unsigned long V_31 ;
F_9 ( L_2 , V_18 ) ;
F_21 ( & V_6 -> V_8 , V_31 ) ;
V_9 = V_6 -> V_9 ;
F_22 ( & V_6 -> V_8 , V_31 ) ;
return V_9 ;
}
static int F_39 ( struct V_20 * V_21 ,
unsigned int V_104 , unsigned int V_105 )
{
struct V_22 * V_15 = V_21 -> V_102 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_5 * V_6 = F_11 ( V_15 ) ;
unsigned long V_9 ;
unsigned long V_31 ;
int V_23 ;
int V_106 = 0 ;
int V_107 = 0 ;
F_9 ( L_2 , V_18 ) ;
F_21 ( & V_6 -> V_8 , V_31 ) ;
V_9 = V_6 -> V_9 ;
if ( V_104 & V_74 ) {
V_9 |= V_74 ;
V_106 = 1 ;
}
if ( V_104 & V_73 ) {
V_9 |= V_73 ;
V_107 = 1 ;
}
if ( V_105 & V_74 ) {
V_9 &= ~ V_74 ;
V_106 = 0 ;
}
if ( V_105 & V_73 ) {
V_9 &= ~ V_73 ;
V_107 = 0 ;
}
V_6 -> V_9 = V_9 ;
F_22 ( & V_6 -> V_8 , V_31 ) ;
V_23 = F_31 ( V_77 , V_106 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_15 -> V_4 , L_22 , V_23 ) ;
goto exit;
}
V_23 = F_31 ( V_75 , V_107 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_15 -> V_4 , L_23 , V_23 ) ;
goto exit;
}
exit:
return V_23 ;
}
static int T_3 F_40 ( void )
{
int V_23 ;
V_23 = F_41 ( & V_108 ) ;
if ( V_23 )
goto V_109;
V_23 = F_42 ( & V_110 ) ;
if ( V_23 )
goto V_111;
F_43 (KERN_INFO KBUILD_MODNAME L_24 DRIVER_VERSION L_25
DRIVER_DESC L_26 ) ;
return 0 ;
V_111:
F_44 ( & V_108 ) ;
V_109:
return V_23 ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_110 ) ;
F_44 ( & V_108 ) ;
}
