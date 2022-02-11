static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( V_4 , V_5 ,
F_3 ( V_5 ) ) ;
F_4 ( V_4 , V_6 , F_3 ( V_6 ) ) ;
return 0 ;
}
static void F_5 ( unsigned int V_7 , unsigned int V_8 )
{
unsigned long long V_9 ;
unsigned int V_10 , V_11 , V_12 ;
V_11 = V_7 / V_8 ;
if ( V_11 < 6 ) {
V_8 >>= 1 ;
V_13 . V_14 = 1 ;
V_11 = V_7 / V_8 ;
} else
V_13 . V_14 = 0 ;
if ( ( V_11 < 6 ) || ( V_11 > 12 ) )
F_6 ( V_15
L_1 ,
V_11 ) ;
V_13 . V_16 = V_11 ;
V_12 = V_7 % V_8 ;
V_9 = V_17 * ( long long ) V_12 ;
F_7 ( V_9 , V_8 ) ;
V_10 = V_9 & 0xFFFFFFFF ;
if ( ( V_10 % 10 ) >= 5 )
V_10 += 5 ;
V_10 /= 10 ;
V_13 . V_18 = V_10 ;
}
static int F_8 ( struct V_19 * V_20 , int V_21 ,
int V_8 , unsigned int V_22 , unsigned int V_23 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
T_1 V_24 ;
if ( V_22 == 0 || V_23 == 0 ) {
V_24 = F_9 ( V_2 , V_25 ) ;
F_10 ( V_2 , V_25 , V_24 & 0x0ff ) ;
V_24 = F_9 ( V_2 , V_26 ) ;
F_10 ( V_2 , V_26 , V_24 & 0x1df ) ;
return 0 ;
}
F_5 ( V_23 * 4 , V_22 ) ;
F_10 ( V_2 , V_27 , ( V_13 . V_14 << 4 ) | V_13 . V_16 ) ;
F_10 ( V_2 , V_28 , V_13 . V_18 >> 18 ) ;
F_10 ( V_2 , V_29 , ( V_13 . V_18 >> 9 ) & 0x1ff ) ;
F_10 ( V_2 , V_30 , V_13 . V_18 & 0x1ff ) ;
V_24 = F_9 ( V_2 , V_26 ) ;
F_10 ( V_2 , V_26 , V_24 | 0x020 ) ;
V_24 = F_9 ( V_2 , V_25 ) ;
F_10 ( V_2 , V_25 , V_24 | 0x100 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 ,
int V_31 , int div )
{
struct V_1 * V_2 = V_20 -> V_2 ;
T_1 V_24 ;
switch ( V_31 ) {
case V_32 :
V_24 = F_9 ( V_2 , V_33 ) & 0x1cf ;
F_10 ( V_2 , V_33 , V_24 | div ) ;
break;
case V_34 :
V_24 = F_9 ( V_2 , V_25 ) & 0x11f ;
F_10 ( V_2 , V_25 , V_24 | div ) ;
break;
case V_35 :
V_24 = F_9 ( V_2 , V_36 ) & 0x1f7 ;
F_10 ( V_2 , V_36 , V_24 | div ) ;
break;
case V_37 :
V_24 = F_9 ( V_2 , V_38 ) & 0x1f7 ;
F_10 ( V_2 , V_38 , V_24 | div ) ;
break;
case V_39 :
V_24 = F_9 ( V_2 , V_25 ) & 0x1e3 ;
F_10 ( V_2 , V_25 , V_24 | div ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
unsigned int V_41 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
T_1 V_42 = 0 ;
T_1 V_43 = F_9 ( V_2 , V_25 ) & 0x1fe ;
switch ( V_41 & V_44 ) {
case V_45 :
V_43 |= 0x0001 ;
break;
case V_46 :
break;
default:
return - V_40 ;
}
switch ( V_41 & V_47 ) {
case V_48 :
V_42 |= 0x0010 ;
break;
case V_49 :
break;
case V_50 :
V_42 |= 0x0008 ;
break;
case V_51 :
V_42 |= 0x00018 ;
break;
default:
return - V_40 ;
}
switch ( V_41 & V_52 ) {
case V_53 :
break;
case V_54 :
V_42 |= 0x0180 ;
break;
case V_55 :
V_42 |= 0x0100 ;
break;
case V_56 :
V_42 |= 0x0080 ;
break;
default:
return - V_40 ;
}
F_10 ( V_2 , V_57 , V_42 ) ;
F_10 ( V_2 , V_25 , V_43 ) ;
return 0 ;
}
static int F_13 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_19 * V_62 )
{
struct V_63 * V_64 = V_59 -> V_65 ;
struct V_1 * V_2 = V_64 -> V_2 ;
T_1 V_42 = F_9 ( V_2 , V_57 ) & 0x19f ;
T_1 V_66 = F_9 ( V_2 , V_67 ) & 0x1f1 ;
switch ( F_14 ( V_61 ) ) {
case V_68 :
break;
case V_69 :
V_42 |= 0x0020 ;
break;
case V_70 :
V_42 |= 0x0040 ;
break;
case V_71 :
V_42 |= 0x0060 ;
break;
}
switch ( F_15 ( V_61 ) ) {
case 8000 :
V_66 |= 0x5 << 1 ;
break;
case 11025 :
V_66 |= 0x4 << 1 ;
break;
case 16000 :
V_66 |= 0x3 << 1 ;
break;
case 22050 :
V_66 |= 0x2 << 1 ;
break;
case 32000 :
V_66 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
F_10 ( V_2 , V_57 , V_42 ) ;
F_10 ( V_2 , V_67 , V_66 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_62 , int V_72 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 V_73 = F_9 ( V_2 , V_38 ) & 0xffbf ;
if ( V_72 )
F_10 ( V_2 , V_38 , V_73 | 0x40 ) ;
else
F_10 ( V_2 , V_38 , V_73 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_74 V_75 )
{
T_1 V_76 = F_9 ( V_2 , V_26 ) & ~ 0x3 ;
switch ( V_75 ) {
case V_77 :
case V_78 :
V_76 |= 0x1 ;
F_10 ( V_2 , V_26 , V_76 ) ;
break;
case V_79 :
V_76 |= V_80 | V_81 ;
if ( V_2 -> V_4 . V_82 == V_83 ) {
F_10 ( V_2 , V_26 , V_76 | 0x3 ) ;
F_18 ( 100 ) ;
}
V_76 |= 0x2 ;
F_10 ( V_2 , V_26 , V_76 ) ;
break;
case V_83 :
F_10 ( V_2 , V_26 , 0 ) ;
F_10 ( V_2 , V_84 , 0 ) ;
F_10 ( V_2 , V_85 , 0 ) ;
break;
}
V_2 -> V_4 . V_82 = V_75 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_86 )
{
F_17 ( V_2 , V_83 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_87 ;
T_3 V_88 [ 2 ] ;
T_1 * V_89 = V_2 -> V_90 ;
for ( V_87 = 0 ; V_87 < F_3 ( V_91 ) ; V_87 ++ ) {
V_88 [ 0 ] = ( V_87 << 1 ) | ( ( V_89 [ V_87 ] >> 8 ) & 0x0001 ) ;
V_88 [ 1 ] = V_89 [ V_87 ] & 0x00ff ;
V_2 -> V_92 ( V_2 -> V_93 , V_88 , 2 ) ;
}
F_17 ( V_2 , V_79 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_22 ( V_2 ) ;
int V_96 ;
V_96 = F_23 ( V_2 , 7 , 9 , V_95 -> V_97 ) ;
if ( V_96 < 0 ) {
F_6 ( V_98 L_2 , V_96 ) ;
return V_96 ;
}
F_24 ( V_2 ) ;
F_17 ( V_2 , V_79 ) ;
F_25 ( V_2 , V_99 ,
F_3 ( V_99 ) ) ;
F_1 ( V_2 ) ;
return V_96 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_22 ( V_2 ) ;
F_17 ( V_2 , V_83 ) ;
F_27 ( V_95 ) ;
return 0 ;
}
static int T_4 F_28 ( struct V_100 * V_101 )
{
struct V_94 * V_95 ;
int V_96 ;
V_95 = F_29 ( sizeof( struct V_94 ) , V_102 ) ;
if ( V_95 == NULL )
return - V_103 ;
V_95 -> V_97 = V_104 ;
F_30 ( V_101 , V_95 ) ;
V_96 = F_31 ( & V_101 -> V_105 ,
& V_106 , & V_107 , 1 ) ;
if ( V_96 < 0 )
F_27 ( V_95 ) ;
return V_96 ;
}
static int T_5 F_32 ( struct V_100 * V_101 )
{
F_33 ( & V_101 -> V_105 ) ;
return 0 ;
}
static T_4 int F_34 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
struct V_94 * V_95 ;
int V_96 ;
V_95 = F_29 ( sizeof( struct V_94 ) , V_102 ) ;
if ( V_95 == NULL )
return - V_103 ;
F_35 ( V_109 , V_95 ) ;
V_95 -> V_97 = V_112 ;
V_96 = F_31 ( & V_109 -> V_105 ,
& V_106 , & V_107 , 1 ) ;
if ( V_96 < 0 )
F_27 ( V_95 ) ;
return V_96 ;
}
static T_5 int F_36 ( struct V_108 * V_113 )
{
F_33 ( & V_113 -> V_105 ) ;
return 0 ;
}
static int T_6 F_37 ( void )
{
int V_96 = 0 ;
#if F_38 ( V_114 ) || F_38 ( V_115 )
V_96 = F_39 ( & V_116 ) ;
if ( V_96 != 0 ) {
F_6 ( V_98 L_3 ,
V_96 ) ;
}
#endif
#if F_38 ( V_117 )
V_96 = F_40 ( & V_118 ) ;
if ( V_96 != 0 ) {
F_6 ( V_98 L_4 ,
V_96 ) ;
}
#endif
return V_96 ;
}
static void T_7 F_41 ( void )
{
#if F_38 ( V_114 ) || F_38 ( V_115 )
F_42 ( & V_116 ) ;
#endif
#if F_38 ( V_117 )
F_43 ( & V_118 ) ;
#endif
}
