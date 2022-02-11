static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_4 , V_6 ,
F_3 ( V_6 ) ) ;
if ( V_5 )
goto V_7;
V_5 = F_4 ( V_4 , V_8 , F_3 ( V_8 ) ) ;
if ( V_5 )
goto V_7;
V_7:
return V_5 ;
}
static int F_5 ( struct V_9 * V_10 ,
unsigned int V_11 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_12 = F_6 ( V_2 , V_13 ) & 0xFE67 ;
T_1 V_14 = F_6 ( V_2 , V_15 ) & 0x1fe ;
switch ( V_11 & V_16 ) {
case V_17 :
V_14 |= 1 ;
break;
case V_18 :
break;
default:
return - V_19 ;
}
F_7 ( V_2 , V_15 , V_14 ) ;
switch ( V_11 & V_20 ) {
case V_21 :
V_12 |= ( 2 << 3 ) ;
break;
case V_22 :
V_12 |= ( 1 << 3 ) ;
break;
case V_23 :
break;
case V_24 :
V_12 |= ( 3 << 3 ) ;
break;
case V_25 :
V_12 |= ( 3 << 3 ) | ( 1 << 7 ) ;
break;
}
switch ( V_11 & V_26 ) {
case V_27 :
break;
case V_28 :
V_12 |= ( 1 << 7 ) ;
break;
case V_29 :
V_12 |= ( 1 << 8 ) ;
break;
case V_30 :
V_12 |= ( 1 << 8 ) | ( 1 << 7 ) ;
break;
}
F_7 ( V_2 , V_13 , V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_9 * V_35 )
{
struct V_36 * V_37 = V_32 -> V_38 ;
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_12 = F_6 ( V_2 , V_13 ) & 0xFD9F ;
T_1 V_39 = F_6 ( V_2 , V_40 ) & 0xFFF1 ;
T_1 V_41 = F_6 ( V_2 ,
V_42 ) & 0xFFDF ;
int V_5 ;
if ( V_32 -> V_43 == V_44
&& F_9 ( V_34 ) == 2 )
V_12 |= ( 1 << 9 ) ;
switch ( F_10 ( V_34 ) ) {
case 8000 :
V_39 |= ( 0x5 << 1 ) ;
break;
case 11025 :
V_39 |= ( 0x4 << 1 ) ;
break;
case 16000 :
V_39 |= ( 0x3 << 1 ) ;
break;
case 22050 :
V_39 |= ( 0x2 << 1 ) ;
break;
case 32000 :
V_39 |= ( 0x1 << 1 ) ;
break;
case 44100 :
case 48000 :
break;
}
V_5 = F_7 ( V_2 , V_40 , V_39 ) ;
if ( V_5 )
goto V_7;
switch ( F_11 ( V_34 ) ) {
case V_45 :
V_41 = V_41 | ( 1 << 5 ) ;
break;
case V_46 :
break;
case V_47 :
V_12 |= ( 1 << 5 ) ;
break;
case V_48 :
V_12 |= ( 2 << 5 ) ;
break;
case V_49 :
V_12 |= ( 3 << 5 ) ;
break;
}
V_5 = F_7 ( V_2 , V_42 , V_41 ) ;
if ( V_5 )
goto V_7;
V_5 = F_7 ( V_2 , V_13 , V_12 ) ;
V_7:
return V_5 ;
}
static int F_12 ( struct V_9 * V_35 , int V_50 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
T_1 V_51 = F_6 ( V_2 , V_52 ) & 0xffbf ;
if ( V_50 )
V_51 |= 0x40 ;
return F_7 ( V_2 , V_52 , V_51 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_53 V_54 )
{
T_1 V_55 ;
T_1 V_56 = F_6 ( V_2 , V_57 ) & 0x1F0 ;
int V_5 = 0 ;
switch ( V_54 ) {
case V_58 :
V_56 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_55 = F_6 ( V_2 , V_59 ) ;
V_5 = F_7 ( V_2 , V_59 , V_55 | 0x2 ) ;
if ( V_5 )
break;
V_5 = F_7 ( V_2 , V_57 , V_56 | 0x1 ) ;
break;
case V_60 :
V_56 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_5 = F_7 ( V_2 , V_57 , V_56 | 0x1 ) ;
break;
case V_61 :
V_56 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_5 = F_7 ( V_2 , V_57 , V_56 | 0x2 ) ;
break;
case V_62 :
V_5 = F_7 ( V_2 , V_57 , V_56 ) ;
break;
}
return V_5 ;
}
static void F_14 ( unsigned int V_63 , unsigned int V_64 )
{
unsigned long long V_65 ;
unsigned int V_66 , V_67 , V_68 ;
V_67 = V_63 / V_64 ;
if ( V_67 > 12 ) {
V_64 <<= 1 ;
V_69 . V_70 = 0 ;
V_67 = V_63 / V_64 ;
} else if ( V_67 < 3 ) {
V_64 >>= 2 ;
V_69 . V_70 = 3 ;
V_67 = V_63 / V_64 ;
} else if ( V_67 < 6 ) {
V_64 >>= 1 ;
V_69 . V_70 = 2 ;
V_67 = V_63 / V_64 ;
} else
V_69 . V_70 = 1 ;
if ( ( V_67 < 6 ) || ( V_67 > 12 ) )
F_15 ( V_71
L_1 ,
V_67 ) ;
V_69 . V_72 = V_67 ;
V_68 = V_63 % V_64 ;
V_65 = V_73 * ( long long ) V_68 ;
F_16 ( V_65 , V_64 ) ;
V_66 = V_65 & 0xFFFFFFFF ;
if ( ( V_66 % 10 ) >= 5 )
V_66 += 5 ;
V_66 /= 10 ;
V_69 . V_74 = V_66 ;
}
static int F_17 ( struct V_9 * V_10 , int V_75 ,
int V_64 , unsigned int V_76 , unsigned int V_77 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_78 ;
V_78 = F_6 ( V_2 , V_57 ) ;
F_7 ( V_2 , V_57 , V_78 & 0x1df ) ;
if ( V_76 == 0 || V_77 == 0 ) {
V_78 = F_6 ( V_2 , V_15 ) ;
F_7 ( V_2 , V_15 , V_78 & 0x0ff ) ;
F_7 ( V_2 , V_79 , ( 1 << 7 ) ) ;
return 0 ;
}
F_14 ( V_77 * 4 , V_76 ) ;
if ( V_69 . V_74 )
F_7 ( V_2 , V_79 ,
( V_69 . V_70 << 4 ) | V_69 . V_72 | ( 1 << 6 ) ) ;
else
F_7 ( V_2 , V_79 ,
( V_69 . V_70 << 4 ) | V_69 . V_72 ) ;
F_7 ( V_2 , V_80 , V_69 . V_74 >> 18 ) ;
F_7 ( V_2 , V_81 , ( V_69 . V_74 >> 9 ) & 0x1ff ) ;
F_7 ( V_2 , V_82 , V_69 . V_74 & 0x1ff ) ;
V_78 = F_6 ( V_2 , V_57 ) ;
F_7 ( V_2 , V_57 , V_78 | 0x020 ) ;
V_78 = F_6 ( V_2 , V_15 ) ;
F_7 ( V_2 , V_15 , V_78 | 0x100 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 ,
int V_83 , unsigned int V_84 , int V_85 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_86 * V_87 = F_19 ( V_2 ) ;
switch ( V_84 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_87 -> V_88 = V_84 ;
return 0 ;
}
return - V_19 ;
}
static int F_20 ( struct V_9 * V_10 ,
int V_89 , int div )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_78 ;
int V_5 = 0 ;
switch ( V_89 ) {
case V_90 :
V_78 = F_6 ( V_2 , V_15 ) & 0xFFEF3 ;
V_5 = F_7 ( V_2 , V_15 , V_78 | ( div << 2 ) ) ;
break;
case V_91 :
V_78 = F_6 ( V_2 , V_15 ) & 0xFF1F ;
V_5 = F_7 ( V_2 , V_15 , V_78 | ( div << 5 ) ) ;
break;
case V_92 :
V_78 = F_6 ( V_2 , V_40 ) & 0xFFCF ;
V_5 = F_7 ( V_2 , V_40 , V_78 | ( div << 4 ) ) ;
break;
}
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_93 )
{
return F_13 ( V_2 , V_62 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_94 ;
int V_5 ;
T_3 V_95 [ 3 ] ;
T_1 * V_96 = V_2 -> V_97 ;
for ( V_94 = 0 ; V_94 < F_3 ( V_98 ) ; V_94 ++ ) {
V_95 [ 0 ] = V_94 ;
V_95 [ 1 ] = ( V_96 [ V_94 ] & 0xFF00 ) >> 8 ;
V_95 [ 2 ] = V_96 [ V_94 ] & 0x00FF ;
V_5 = V_2 -> V_99 ( V_2 -> V_100 , V_95 , 3 ) ;
if ( V_5 < 0 )
goto V_7;
else if ( V_5 != 3 ) {
V_5 = - V_101 ;
goto V_7;
}
}
V_5 = F_13 ( V_2 , V_61 ) ;
if ( V_5 )
goto V_7;
V_7:
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_19 ( V_2 ) ;
struct V_102 * V_103 = V_2 -> V_104 -> V_105 ;
int V_5 ;
T_1 V_78 ;
V_2 -> V_100 = V_87 -> V_100 ;
V_5 = F_24 ( V_2 , 8 , 16 , V_87 -> V_106 ) ;
if ( V_5 < 0 ) {
F_25 ( V_2 -> V_104 , L_2 , V_5 ) ;
return V_5 ;
}
V_5 = F_26 ( V_2 ) ;
if ( V_5 < 0 ) {
F_25 ( V_2 -> V_104 , L_3 ) ;
return V_5 ;
}
F_13 ( V_2 , V_61 ) ;
V_5 = F_7 ( V_2 , V_57 , 0x180 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! V_103 )
F_27 ( V_2 -> V_104 , L_4 ) ;
else {
V_78 = F_6 ( V_2 , V_59 ) ;
V_5 = F_7 ( V_2 , V_59 , V_78 | V_103 -> V_107 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_5 = F_28 ( V_2 , V_108 ,
F_3 ( V_108 ) ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_62 ) ;
return 0 ;
}
static T_4 int F_30 ( struct V_109 * V_110 ,
const struct V_111 * V_112 )
{
struct V_86 * V_87 ;
int V_5 ;
V_87 = F_31 ( sizeof( struct V_86 ) , V_113 ) ;
if ( V_87 == NULL )
return - V_114 ;
F_32 ( V_110 , V_87 ) ;
V_87 -> V_100 = V_110 ;
V_87 -> V_106 = V_115 ;
V_5 = F_33 ( & V_110 -> V_104 ,
& V_116 , & V_117 , 1 ) ;
if ( V_5 < 0 )
F_34 ( V_87 ) ;
return V_5 ;
}
static T_5 int F_35 ( struct V_109 * V_118 )
{
F_36 ( & V_118 -> V_104 ) ;
F_34 ( F_37 ( V_118 ) ) ;
return 0 ;
}
static int T_6 F_38 ( void )
{
int V_5 = 0 ;
#if F_39 ( V_119 ) || F_39 ( V_120 )
V_5 = F_40 ( & V_121 ) ;
if ( V_5 != 0 ) {
F_15 ( V_122 L_5 ,
V_5 ) ;
}
#endif
return V_5 ;
}
static void T_7 F_41 ( void )
{
#if F_39 ( V_119 ) || F_39 ( V_120 )
F_42 ( & V_121 ) ;
#endif
}
