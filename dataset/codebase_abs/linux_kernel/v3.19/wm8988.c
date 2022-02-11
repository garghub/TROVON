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
struct V_43 * V_44 = V_39 -> V_44 ;
T_1 V_45 = F_3 ( V_44 , V_24 ) ;
if ( F_3 ( V_44 , V_26 ) & 0x180 )
V_45 &= ~ 0x4 ;
else
V_45 |= 0x4 ;
return F_4 ( V_44 , V_24 , V_45 ) ;
}
static inline int F_5 ( int V_46 , int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_6 ( V_49 ) ; V_48 ++ ) {
if ( V_49 [ V_48 ] . V_47 == V_47 && V_49 [ V_48 ] . V_46 == V_46 )
return V_48 ;
}
return - V_50 ;
}
static int F_7 ( struct V_51 * V_52 ,
int V_53 , unsigned int V_54 , int V_55 )
{
struct V_43 * V_44 = V_52 -> V_44 ;
struct V_56 * V_57 = F_8 ( V_44 ) ;
switch ( V_54 ) {
case 11289600 :
case 18432000 :
case 22579200 :
case 36864000 :
V_57 -> V_58 = & V_59 ;
V_57 -> V_60 = V_54 ;
return 0 ;
case 12288000 :
case 16934400 :
case 24576000 :
case 33868800 :
V_57 -> V_58 = & V_61 ;
V_57 -> V_60 = V_54 ;
return 0 ;
case 12000000 :
case 24000000 :
V_57 -> V_58 = & V_62 ;
V_57 -> V_60 = V_54 ;
return 0 ;
}
return - V_50 ;
}
static int F_9 ( struct V_51 * V_52 ,
unsigned int V_63 )
{
struct V_43 * V_44 = V_52 -> V_44 ;
T_1 V_64 = 0 ;
switch ( V_63 & V_65 ) {
case V_66 :
V_64 = 0x0040 ;
break;
case V_67 :
break;
default:
return - V_50 ;
}
switch ( V_63 & V_68 ) {
case V_69 :
V_64 |= 0x0002 ;
break;
case V_70 :
break;
case V_71 :
V_64 |= 0x0001 ;
break;
case V_72 :
V_64 |= 0x0003 ;
break;
case V_73 :
V_64 |= 0x0013 ;
break;
default:
return - V_50 ;
}
switch ( V_63 & V_74 ) {
case V_75 :
break;
case V_76 :
V_64 |= 0x0090 ;
break;
case V_77 :
V_64 |= 0x0080 ;
break;
case V_78 :
V_64 |= 0x0010 ;
break;
default:
return - V_50 ;
}
F_4 ( V_44 , V_9 , V_64 ) ;
return 0 ;
}
static int F_10 ( struct V_79 * V_80 ,
struct V_51 * V_81 )
{
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_56 * V_57 = F_8 ( V_44 ) ;
if ( ! V_57 -> V_60 ) {
F_11 ( V_44 -> V_2 ,
L_1 ) ;
return - V_50 ;
}
F_12 ( V_80 -> V_82 , 0 ,
V_83 ,
V_57 -> V_58 ) ;
return 0 ;
}
static int F_13 ( struct V_79 * V_80 ,
struct V_84 * V_85 ,
struct V_51 * V_81 )
{
struct V_43 * V_44 = V_81 -> V_44 ;
struct V_56 * V_57 = F_8 ( V_44 ) ;
T_1 V_64 = F_3 ( V_44 , V_9 ) & 0x1f3 ;
T_1 V_86 = F_3 ( V_44 , V_10 ) & 0x180 ;
int V_87 ;
V_87 = F_5 ( V_57 -> V_60 , F_14 ( V_85 ) ) ;
if ( V_87 < 0 ) {
V_87 = F_5 ( V_57 -> V_60 / 2 , F_14 ( V_85 ) ) ;
V_86 |= 0x40 ;
}
if ( V_87 < 0 ) {
F_11 ( V_44 -> V_2 ,
L_2 ,
F_14 ( V_85 ) , V_57 -> V_60 ) ;
return V_87 ;
}
switch ( F_15 ( V_85 ) ) {
case 16 :
break;
case 20 :
V_64 |= 0x0004 ;
break;
case 24 :
V_64 |= 0x0008 ;
break;
case 32 :
V_64 |= 0x000c ;
break;
}
F_4 ( V_44 , V_9 , V_64 ) ;
if ( V_87 >= 0 )
F_4 ( V_44 , V_10 , V_86 |
( V_49 [ V_87 ] . V_88 << 1 ) | V_49 [ V_87 ] . V_89 ) ;
return 0 ;
}
static int F_16 ( struct V_51 * V_81 , int V_90 )
{
struct V_43 * V_44 = V_81 -> V_44 ;
T_1 V_91 = F_3 ( V_44 , V_8 ) & 0xfff7 ;
if ( V_90 )
F_4 ( V_44 , V_8 , V_91 | 0x8 ) ;
else
F_4 ( V_44 , V_8 , V_91 ) ;
return 0 ;
}
static int F_17 ( struct V_43 * V_44 ,
enum V_92 V_93 )
{
struct V_56 * V_57 = F_8 ( V_44 ) ;
T_1 V_94 = F_3 ( V_44 , V_25 ) & ~ 0x1c1 ;
switch ( V_93 ) {
case V_95 :
break;
case V_96 :
F_4 ( V_44 , V_25 , V_94 | 0x00c0 ) ;
break;
case V_97 :
if ( V_44 -> V_98 . V_99 == V_100 ) {
F_18 ( V_57 -> V_101 ) ;
F_4 ( V_44 , V_25 , V_94 | 0x1c1 ) ;
F_19 ( 100 ) ;
}
F_4 ( V_44 , V_25 , V_94 | 0x0141 ) ;
break;
case V_100 :
F_4 ( V_44 , V_25 , 0x0000 ) ;
break;
}
V_44 -> V_98 . V_99 = V_93 ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 )
{
int V_102 = 0 ;
V_102 = F_21 ( V_44 ) ;
if ( V_102 < 0 ) {
F_11 ( V_44 -> V_2 , L_3 ) ;
return V_102 ;
}
F_22 ( V_44 , V_22 , 0x0100 , 0x0100 ) ;
F_22 ( V_44 , V_12 , 0x0100 , 0x0100 ) ;
F_22 ( V_44 , V_7 , 0x0100 , 0x0100 ) ;
F_22 ( V_44 , V_36 , 0x0100 , 0x0100 ) ;
F_22 ( V_44 , V_5 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_23 ( struct V_103 * V_104 )
{
struct V_56 * V_57 ;
int V_102 ;
V_57 = F_24 ( & V_104 -> V_2 , sizeof( struct V_56 ) ,
V_105 ) ;
if ( V_57 == NULL )
return - V_106 ;
V_57 -> V_101 = F_25 ( V_104 , & V_107 ) ;
if ( F_26 ( V_57 -> V_101 ) ) {
V_102 = F_27 ( V_57 -> V_101 ) ;
F_11 ( & V_104 -> V_2 , L_4 , V_102 ) ;
return V_102 ;
}
F_28 ( V_104 , V_57 ) ;
V_102 = F_29 ( & V_104 -> V_2 ,
& V_108 , & V_109 , 1 ) ;
return V_102 ;
}
static int F_30 ( struct V_103 * V_104 )
{
F_31 ( & V_104 -> V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_110 * V_111 ,
const struct V_112 * V_113 )
{
struct V_56 * V_57 ;
int V_102 ;
V_57 = F_24 ( & V_111 -> V_2 , sizeof( struct V_56 ) ,
V_105 ) ;
if ( V_57 == NULL )
return - V_106 ;
F_33 ( V_111 , V_57 ) ;
V_57 -> V_101 = F_34 ( V_111 , & V_107 ) ;
if ( F_26 ( V_57 -> V_101 ) ) {
V_102 = F_27 ( V_57 -> V_101 ) ;
F_11 ( & V_111 -> V_2 , L_4 , V_102 ) ;
return V_102 ;
}
V_102 = F_29 ( & V_111 -> V_2 ,
& V_108 , & V_109 , 1 ) ;
return V_102 ;
}
static int F_35 ( struct V_110 * V_114 )
{
F_31 ( & V_114 -> V_2 ) ;
return 0 ;
}
static int T_2 F_36 ( void )
{
int V_102 = 0 ;
#if F_37 ( V_115 )
V_102 = F_38 ( & V_116 ) ;
if ( V_102 != 0 ) {
F_39 ( V_117 L_5 ,
V_102 ) ;
}
#endif
#if F_40 ( V_118 )
V_102 = F_41 ( & V_119 ) ;
if ( V_102 != 0 ) {
F_39 ( V_117 L_6 ,
V_102 ) ;
}
#endif
return V_102 ;
}
static void T_3 F_42 ( void )
{
#if F_37 ( V_115 )
F_43 ( & V_116 ) ;
#endif
#if F_40 ( V_118 )
F_44 ( & V_119 ) ;
#endif
}
