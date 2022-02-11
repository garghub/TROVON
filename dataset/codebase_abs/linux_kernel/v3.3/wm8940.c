static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_6 , V_8 ,
F_4 ( V_8 ) ) ;
if ( V_7 )
goto V_9;
V_7 = F_5 ( V_6 , V_10 , F_4 ( V_10 ) ) ;
V_9:
return V_7 ;
}
static int F_6 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_14 = F_7 ( V_2 , V_15 ) & 0xFE67 ;
T_1 V_16 = F_7 ( V_2 , V_17 ) & 0x1fe ;
switch ( V_13 & V_18 ) {
case V_19 :
V_16 |= 1 ;
break;
case V_20 :
break;
default:
return - V_21 ;
}
F_8 ( V_2 , V_17 , V_16 ) ;
switch ( V_13 & V_22 ) {
case V_23 :
V_14 |= ( 2 << 3 ) ;
break;
case V_24 :
V_14 |= ( 1 << 3 ) ;
break;
case V_25 :
break;
case V_26 :
V_14 |= ( 3 << 3 ) ;
break;
case V_27 :
V_14 |= ( 3 << 3 ) | ( 1 << 7 ) ;
break;
}
switch ( V_13 & V_28 ) {
case V_29 :
break;
case V_30 :
V_14 |= ( 1 << 7 ) ;
break;
case V_31 :
V_14 |= ( 1 << 8 ) ;
break;
case V_32 :
V_14 |= ( 1 << 8 ) | ( 1 << 7 ) ;
break;
}
F_8 ( V_2 , V_15 , V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_11 * V_37 )
{
struct V_38 * V_39 = V_34 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
T_1 V_14 = F_7 ( V_2 , V_15 ) & 0xFD9F ;
T_1 V_41 = F_7 ( V_2 , V_42 ) & 0xFFF1 ;
T_1 V_43 = F_7 ( V_2 ,
V_44 ) & 0xFFDF ;
int V_7 ;
if ( V_34 -> V_45 == V_46
&& F_10 ( V_36 ) == 2 )
V_14 |= ( 1 << 9 ) ;
switch ( F_11 ( V_36 ) ) {
case 8000 :
V_41 |= ( 0x5 << 1 ) ;
break;
case 11025 :
V_41 |= ( 0x4 << 1 ) ;
break;
case 16000 :
V_41 |= ( 0x3 << 1 ) ;
break;
case 22050 :
V_41 |= ( 0x2 << 1 ) ;
break;
case 32000 :
V_41 |= ( 0x1 << 1 ) ;
break;
case 44100 :
case 48000 :
break;
}
V_7 = F_8 ( V_2 , V_42 , V_41 ) ;
if ( V_7 )
goto V_9;
switch ( F_12 ( V_36 ) ) {
case V_47 :
V_43 = V_43 | ( 1 << 5 ) ;
break;
case V_48 :
break;
case V_49 :
V_14 |= ( 1 << 5 ) ;
break;
case V_50 :
V_14 |= ( 2 << 5 ) ;
break;
case V_51 :
V_14 |= ( 3 << 5 ) ;
break;
}
V_7 = F_8 ( V_2 , V_44 , V_43 ) ;
if ( V_7 )
goto V_9;
V_7 = F_8 ( V_2 , V_15 , V_14 ) ;
V_9:
return V_7 ;
}
static int F_13 ( struct V_11 * V_37 , int V_52 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_53 = F_7 ( V_2 , V_54 ) & 0xffbf ;
if ( V_52 )
V_53 |= 0x40 ;
return F_8 ( V_2 , V_54 , V_53 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_55 V_56 )
{
T_1 V_57 ;
T_1 V_58 = F_7 ( V_2 , V_59 ) & 0x1F0 ;
int V_7 = 0 ;
switch ( V_56 ) {
case V_60 :
V_58 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_57 = F_7 ( V_2 , V_61 ) ;
V_7 = F_8 ( V_2 , V_61 , V_57 | 0x2 ) ;
if ( V_7 )
break;
V_7 = F_8 ( V_2 , V_59 , V_58 | 0x1 ) ;
break;
case V_62 :
V_58 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_7 = F_8 ( V_2 , V_59 , V_58 | 0x1 ) ;
break;
case V_63 :
if ( V_2 -> V_6 . V_64 == V_65 ) {
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 ) {
F_16 ( V_2 -> V_66 , L_1 , V_7 ) ;
return V_7 ;
}
}
V_58 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_7 = F_8 ( V_2 , V_59 , V_58 | 0x2 ) ;
break;
case V_65 :
V_7 = F_8 ( V_2 , V_59 , V_58 ) ;
break;
}
V_2 -> V_6 . V_64 = V_56 ;
return V_7 ;
}
static void F_17 ( unsigned int V_67 , unsigned int V_68 )
{
unsigned long long V_69 ;
unsigned int V_70 , V_71 , V_72 ;
V_71 = V_67 / V_68 ;
if ( V_71 > 12 ) {
V_68 <<= 1 ;
V_73 . V_74 = 0 ;
V_71 = V_67 / V_68 ;
} else if ( V_71 < 3 ) {
V_68 >>= 2 ;
V_73 . V_74 = 3 ;
V_71 = V_67 / V_68 ;
} else if ( V_71 < 6 ) {
V_68 >>= 1 ;
V_73 . V_74 = 2 ;
V_71 = V_67 / V_68 ;
} else
V_73 . V_74 = 1 ;
if ( ( V_71 < 6 ) || ( V_71 > 12 ) )
F_18 ( V_75
L_2 ,
V_71 ) ;
V_73 . V_76 = V_71 ;
V_72 = V_67 % V_68 ;
V_69 = V_77 * ( long long ) V_72 ;
F_19 ( V_69 , V_68 ) ;
V_70 = V_69 & 0xFFFFFFFF ;
if ( ( V_70 % 10 ) >= 5 )
V_70 += 5 ;
V_70 /= 10 ;
V_73 . V_78 = V_70 ;
}
static int F_20 ( struct V_11 * V_12 , int V_79 ,
int V_68 , unsigned int V_80 , unsigned int V_81 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_59 ) ;
F_8 ( V_2 , V_59 , V_3 & 0x1df ) ;
if ( V_80 == 0 || V_81 == 0 ) {
V_3 = F_7 ( V_2 , V_17 ) ;
F_8 ( V_2 , V_17 , V_3 & 0x0ff ) ;
F_8 ( V_2 , V_82 , ( 1 << 7 ) ) ;
return 0 ;
}
F_17 ( V_81 * 4 , V_80 ) ;
if ( V_73 . V_78 )
F_8 ( V_2 , V_82 ,
( V_73 . V_74 << 4 ) | V_73 . V_76 | ( 1 << 6 ) ) ;
else
F_8 ( V_2 , V_82 ,
( V_73 . V_74 << 4 ) | V_73 . V_76 ) ;
F_8 ( V_2 , V_83 , V_73 . V_78 >> 18 ) ;
F_8 ( V_2 , V_84 , ( V_73 . V_78 >> 9 ) & 0x1ff ) ;
F_8 ( V_2 , V_85 , V_73 . V_78 & 0x1ff ) ;
V_3 = F_7 ( V_2 , V_59 ) ;
F_8 ( V_2 , V_59 , V_3 | 0x020 ) ;
V_3 = F_7 ( V_2 , V_17 ) ;
F_8 ( V_2 , V_17 , V_3 | 0x100 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
int V_86 , unsigned int V_87 , int V_88 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_89 * V_90 = F_22 ( V_2 ) ;
switch ( V_87 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_90 -> V_91 = V_87 ;
return 0 ;
}
return - V_21 ;
}
static int F_23 ( struct V_11 * V_12 ,
int V_92 , int div )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_3 ;
int V_7 = 0 ;
switch ( V_92 ) {
case V_93 :
V_3 = F_7 ( V_2 , V_17 ) & 0xFFE3 ;
V_7 = F_8 ( V_2 , V_17 , V_3 | ( div << 2 ) ) ;
break;
case V_94 :
V_3 = F_7 ( V_2 , V_17 ) & 0xFF1F ;
V_7 = F_8 ( V_2 , V_17 , V_3 | ( div << 5 ) ) ;
break;
case V_95 :
V_3 = F_7 ( V_2 , V_96 ) & 0xFFCF ;
V_7 = F_8 ( V_2 , V_96 , V_3 | ( div << 4 ) ) ;
break;
}
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_65 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_89 * V_90 = F_22 ( V_2 ) ;
struct V_97 * V_98 = V_2 -> V_66 -> V_99 ;
int V_7 ;
T_1 V_3 ;
V_7 = F_27 ( V_2 , 8 , 16 , V_90 -> V_100 ) ;
if ( V_7 < 0 ) {
F_16 ( V_2 -> V_66 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_28 ( V_2 ) ;
if ( V_7 < 0 ) {
F_16 ( V_2 -> V_66 , L_4 ) ;
return V_7 ;
}
F_14 ( V_2 , V_63 ) ;
V_7 = F_8 ( V_2 , V_59 , 0x180 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_98 )
F_29 ( V_2 -> V_66 , L_5 ) ;
else {
V_3 = F_7 ( V_2 , V_61 ) ;
V_7 = F_8 ( V_2 , V_61 , V_3 | V_98 -> V_101 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_30 ( V_2 , V_102 ,
F_4 ( V_102 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_2 ( V_2 ) ;
return V_7 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_65 ) ;
return 0 ;
}
static T_2 int F_32 ( struct V_103 * V_104 ,
const struct V_105 * V_106 )
{
struct V_89 * V_90 ;
int V_7 ;
V_90 = F_33 ( sizeof( struct V_89 ) , V_107 ) ;
if ( V_90 == NULL )
return - V_108 ;
F_34 ( V_104 , V_90 ) ;
V_90 -> V_100 = V_109 ;
V_7 = F_35 ( & V_104 -> V_66 ,
& V_110 , & V_111 , 1 ) ;
if ( V_7 < 0 )
F_36 ( V_90 ) ;
return V_7 ;
}
static T_3 int F_37 ( struct V_103 * V_112 )
{
F_38 ( & V_112 -> V_66 ) ;
F_36 ( F_39 ( V_112 ) ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
int V_7 = 0 ;
#if F_41 ( V_113 ) || F_41 ( V_114 )
V_7 = F_42 ( & V_115 ) ;
if ( V_7 != 0 ) {
F_18 ( V_116 L_6 ,
V_7 ) ;
}
#endif
return V_7 ;
}
static void T_5 F_43 ( void )
{
#if F_41 ( V_113 ) || F_41 ( V_114 )
F_44 ( & V_115 ) ;
#endif
}
