static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_43 * V_44 = F_3 ( V_39 -> V_45 ) ;
T_1 V_46 = F_4 ( V_44 , V_24 ) ;
if ( F_4 ( V_44 , V_26 ) & 0x180 )
V_46 &= ~ 0x4 ;
else
V_46 |= 0x4 ;
return F_5 ( V_44 , V_24 , V_46 ) ;
}
static inline int F_6 ( int V_47 , int V_48 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_7 ( V_50 ) ; V_49 ++ ) {
if ( V_50 [ V_49 ] . V_48 == V_48 && V_50 [ V_49 ] . V_47 == V_47 )
return V_49 ;
}
return - V_51 ;
}
static int F_8 ( struct V_52 * V_53 ,
int V_54 , unsigned int V_55 , int V_56 )
{
struct V_43 * V_44 = V_53 -> V_44 ;
struct V_57 * V_58 = F_9 ( V_44 ) ;
switch ( V_55 ) {
case 11289600 :
case 18432000 :
case 22579200 :
case 36864000 :
V_58 -> V_59 = & V_60 ;
V_58 -> V_61 = V_55 ;
return 0 ;
case 12288000 :
case 16934400 :
case 24576000 :
case 33868800 :
V_58 -> V_59 = & V_62 ;
V_58 -> V_61 = V_55 ;
return 0 ;
case 12000000 :
case 24000000 :
V_58 -> V_59 = & V_63 ;
V_58 -> V_61 = V_55 ;
return 0 ;
}
return - V_51 ;
}
static int F_10 ( struct V_52 * V_53 ,
unsigned int V_64 )
{
struct V_43 * V_44 = V_53 -> V_44 ;
T_1 V_65 = 0 ;
switch ( V_64 & V_66 ) {
case V_67 :
V_65 = 0x0040 ;
break;
case V_68 :
break;
default:
return - V_51 ;
}
switch ( V_64 & V_69 ) {
case V_70 :
V_65 |= 0x0002 ;
break;
case V_71 :
break;
case V_72 :
V_65 |= 0x0001 ;
break;
case V_73 :
V_65 |= 0x0003 ;
break;
case V_74 :
V_65 |= 0x0013 ;
break;
default:
return - V_51 ;
}
switch ( V_64 & V_75 ) {
case V_76 :
break;
case V_77 :
V_65 |= 0x0090 ;
break;
case V_78 :
V_65 |= 0x0080 ;
break;
case V_79 :
V_65 |= 0x0010 ;
break;
default:
return - V_51 ;
}
F_5 ( V_44 , V_9 , V_65 ) ;
return 0 ;
}
static int F_11 ( struct V_80 * V_81 ,
struct V_52 * V_82 )
{
struct V_43 * V_44 = V_82 -> V_44 ;
struct V_57 * V_58 = F_9 ( V_44 ) ;
if ( ! V_58 -> V_61 ) {
F_12 ( V_44 -> V_2 ,
L_1 ) ;
return - V_51 ;
}
F_13 ( V_81 -> V_83 , 0 ,
V_84 ,
V_58 -> V_59 ) ;
return 0 ;
}
static int F_14 ( struct V_80 * V_81 ,
struct V_85 * V_86 ,
struct V_52 * V_82 )
{
struct V_43 * V_44 = V_82 -> V_44 ;
struct V_57 * V_58 = F_9 ( V_44 ) ;
T_1 V_65 = F_4 ( V_44 , V_9 ) & 0x1f3 ;
T_1 V_87 = F_4 ( V_44 , V_10 ) & 0x180 ;
int V_88 ;
V_88 = F_6 ( V_58 -> V_61 , F_15 ( V_86 ) ) ;
if ( V_88 < 0 ) {
V_88 = F_6 ( V_58 -> V_61 / 2 , F_15 ( V_86 ) ) ;
V_87 |= 0x40 ;
}
if ( V_88 < 0 ) {
F_12 ( V_44 -> V_2 ,
L_2 ,
F_15 ( V_86 ) , V_58 -> V_61 ) ;
return V_88 ;
}
switch ( F_16 ( V_86 ) ) {
case 16 :
break;
case 20 :
V_65 |= 0x0004 ;
break;
case 24 :
V_65 |= 0x0008 ;
break;
case 32 :
V_65 |= 0x000c ;
break;
}
F_5 ( V_44 , V_9 , V_65 ) ;
if ( V_88 >= 0 )
F_5 ( V_44 , V_10 , V_87 |
( V_50 [ V_88 ] . V_89 << 1 ) | V_50 [ V_88 ] . V_90 ) ;
return 0 ;
}
static int F_17 ( struct V_52 * V_82 , int V_91 )
{
struct V_43 * V_44 = V_82 -> V_44 ;
T_1 V_92 = F_4 ( V_44 , V_8 ) & 0xfff7 ;
if ( V_91 )
F_5 ( V_44 , V_8 , V_92 | 0x8 ) ;
else
F_5 ( V_44 , V_8 , V_92 ) ;
return 0 ;
}
static int F_18 ( struct V_43 * V_44 ,
enum V_93 V_94 )
{
struct V_57 * V_58 = F_9 ( V_44 ) ;
T_1 V_95 = F_4 ( V_44 , V_25 ) & ~ 0x1c1 ;
switch ( V_94 ) {
case V_96 :
break;
case V_97 :
F_5 ( V_44 , V_25 , V_95 | 0x00c0 ) ;
break;
case V_98 :
if ( V_44 -> V_45 . V_99 == V_100 ) {
F_19 ( V_58 -> V_101 ) ;
F_5 ( V_44 , V_25 , V_95 | 0x1c1 ) ;
F_20 ( 100 ) ;
}
F_5 ( V_44 , V_25 , V_95 | 0x0141 ) ;
break;
case V_100 :
F_5 ( V_44 , V_25 , 0x0000 ) ;
break;
}
V_44 -> V_45 . V_99 = V_94 ;
return 0 ;
}
static int F_21 ( struct V_43 * V_44 )
{
int V_102 = 0 ;
V_102 = F_22 ( V_44 ) ;
if ( V_102 < 0 ) {
F_12 ( V_44 -> V_2 , L_3 ) ;
return V_102 ;
}
F_23 ( V_44 , V_22 , 0x0100 , 0x0100 ) ;
F_23 ( V_44 , V_12 , 0x0100 , 0x0100 ) ;
F_23 ( V_44 , V_7 , 0x0100 , 0x0100 ) ;
F_23 ( V_44 , V_36 , 0x0100 , 0x0100 ) ;
F_23 ( V_44 , V_5 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_24 ( struct V_103 * V_104 )
{
struct V_57 * V_58 ;
int V_102 ;
V_58 = F_25 ( & V_104 -> V_2 , sizeof( struct V_57 ) ,
V_105 ) ;
if ( V_58 == NULL )
return - V_106 ;
V_58 -> V_101 = F_26 ( V_104 , & V_107 ) ;
if ( F_27 ( V_58 -> V_101 ) ) {
V_102 = F_28 ( V_58 -> V_101 ) ;
F_12 ( & V_104 -> V_2 , L_4 , V_102 ) ;
return V_102 ;
}
F_29 ( V_104 , V_58 ) ;
V_102 = F_30 ( & V_104 -> V_2 ,
& V_108 , & V_109 , 1 ) ;
return V_102 ;
}
static int F_31 ( struct V_103 * V_104 )
{
F_32 ( & V_104 -> V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_110 * V_111 ,
const struct V_112 * V_113 )
{
struct V_57 * V_58 ;
int V_102 ;
V_58 = F_25 ( & V_111 -> V_2 , sizeof( struct V_57 ) ,
V_105 ) ;
if ( V_58 == NULL )
return - V_106 ;
F_34 ( V_111 , V_58 ) ;
V_58 -> V_101 = F_35 ( V_111 , & V_107 ) ;
if ( F_27 ( V_58 -> V_101 ) ) {
V_102 = F_28 ( V_58 -> V_101 ) ;
F_12 ( & V_111 -> V_2 , L_4 , V_102 ) ;
return V_102 ;
}
V_102 = F_30 ( & V_111 -> V_2 ,
& V_108 , & V_109 , 1 ) ;
return V_102 ;
}
static int F_36 ( struct V_110 * V_114 )
{
F_32 ( & V_114 -> V_2 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
int V_102 = 0 ;
#if F_38 ( V_115 )
V_102 = F_39 ( & V_116 ) ;
if ( V_102 != 0 ) {
F_40 ( V_117 L_5 ,
V_102 ) ;
}
#endif
#if F_41 ( V_118 )
V_102 = F_42 ( & V_119 ) ;
if ( V_102 != 0 ) {
F_40 ( V_117 L_6 ,
V_102 ) ;
}
#endif
return V_102 ;
}
static void T_3 F_43 ( void )
{
#if F_38 ( V_115 )
F_44 ( & V_116 ) ;
#endif
#if F_41 ( V_118 )
F_45 ( & V_119 ) ;
#endif
}
