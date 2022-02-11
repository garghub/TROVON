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
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_14 = F_7 ( V_2 , V_15 ) & 0xFD9F ;
T_1 V_38 = F_7 ( V_2 , V_39 ) & 0xFFF1 ;
T_1 V_40 = F_7 ( V_2 ,
V_41 ) & 0xFFDF ;
int V_7 ;
if ( V_34 -> V_42 == V_43
&& F_10 ( V_36 ) == 2 )
V_14 |= ( 1 << 9 ) ;
switch ( F_11 ( V_36 ) ) {
case 8000 :
V_38 |= ( 0x5 << 1 ) ;
break;
case 11025 :
V_38 |= ( 0x4 << 1 ) ;
break;
case 16000 :
V_38 |= ( 0x3 << 1 ) ;
break;
case 22050 :
V_38 |= ( 0x2 << 1 ) ;
break;
case 32000 :
V_38 |= ( 0x1 << 1 ) ;
break;
case 44100 :
case 48000 :
break;
}
V_7 = F_8 ( V_2 , V_39 , V_38 ) ;
if ( V_7 )
goto V_9;
switch ( F_12 ( V_36 ) ) {
case V_44 :
V_40 = V_40 | ( 1 << 5 ) ;
break;
case V_45 :
break;
case V_46 :
V_14 |= ( 1 << 5 ) ;
break;
case V_47 :
V_14 |= ( 2 << 5 ) ;
break;
case V_48 :
V_14 |= ( 3 << 5 ) ;
break;
}
V_7 = F_8 ( V_2 , V_41 , V_40 ) ;
if ( V_7 )
goto V_9;
V_7 = F_8 ( V_2 , V_15 , V_14 ) ;
V_9:
return V_7 ;
}
static int F_13 ( struct V_11 * V_37 , int V_49 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_50 = F_7 ( V_2 , V_51 ) & 0xffbf ;
if ( V_49 )
V_50 |= 0x40 ;
return F_8 ( V_2 , V_51 , V_50 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_52 V_53 )
{
T_1 V_54 ;
T_1 V_55 = F_7 ( V_2 , V_56 ) & 0x1F0 ;
int V_7 = 0 ;
switch ( V_53 ) {
case V_57 :
V_55 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_54 = F_7 ( V_2 , V_58 ) ;
V_7 = F_8 ( V_2 , V_58 , V_54 | 0x2 ) ;
if ( V_7 )
break;
V_7 = F_8 ( V_2 , V_56 , V_55 | 0x1 ) ;
break;
case V_59 :
V_55 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_7 = F_8 ( V_2 , V_56 , V_55 | 0x1 ) ;
break;
case V_60 :
if ( V_2 -> V_6 . V_61 == V_62 ) {
V_7 = F_15 ( V_2 ) ;
if ( V_7 < 0 ) {
F_16 ( V_2 -> V_63 , L_1 , V_7 ) ;
return V_7 ;
}
}
V_55 |= ( 1 << 2 ) | ( 1 << 3 ) ;
V_7 = F_8 ( V_2 , V_56 , V_55 | 0x2 ) ;
break;
case V_62 :
V_7 = F_8 ( V_2 , V_56 , V_55 ) ;
break;
}
V_2 -> V_6 . V_61 = V_53 ;
return V_7 ;
}
static void F_17 ( unsigned int V_64 , unsigned int V_65 )
{
unsigned long long V_66 ;
unsigned int V_67 , V_68 , V_69 ;
V_68 = V_64 / V_65 ;
if ( V_68 > 12 ) {
V_65 <<= 1 ;
V_70 . V_71 = 0 ;
V_68 = V_64 / V_65 ;
} else if ( V_68 < 3 ) {
V_65 >>= 2 ;
V_70 . V_71 = 3 ;
V_68 = V_64 / V_65 ;
} else if ( V_68 < 6 ) {
V_65 >>= 1 ;
V_70 . V_71 = 2 ;
V_68 = V_64 / V_65 ;
} else
V_70 . V_71 = 1 ;
if ( ( V_68 < 6 ) || ( V_68 > 12 ) )
F_18 ( V_72
L_2 ,
V_68 ) ;
V_70 . V_73 = V_68 ;
V_69 = V_64 % V_65 ;
V_66 = V_74 * ( long long ) V_69 ;
F_19 ( V_66 , V_65 ) ;
V_67 = V_66 & 0xFFFFFFFF ;
if ( ( V_67 % 10 ) >= 5 )
V_67 += 5 ;
V_67 /= 10 ;
V_70 . V_75 = V_67 ;
}
static int F_20 ( struct V_11 * V_12 , int V_76 ,
int V_65 , unsigned int V_77 , unsigned int V_78 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_3 ;
V_3 = F_7 ( V_2 , V_56 ) ;
F_8 ( V_2 , V_56 , V_3 & 0x1df ) ;
if ( V_77 == 0 || V_78 == 0 ) {
V_3 = F_7 ( V_2 , V_17 ) ;
F_8 ( V_2 , V_17 , V_3 & 0x0ff ) ;
F_8 ( V_2 , V_79 , ( 1 << 7 ) ) ;
return 0 ;
}
F_17 ( V_78 * 4 , V_77 ) ;
if ( V_70 . V_75 )
F_8 ( V_2 , V_79 ,
( V_70 . V_71 << 4 ) | V_70 . V_73 | ( 1 << 6 ) ) ;
else
F_8 ( V_2 , V_79 ,
( V_70 . V_71 << 4 ) | V_70 . V_73 ) ;
F_8 ( V_2 , V_80 , V_70 . V_75 >> 18 ) ;
F_8 ( V_2 , V_81 , ( V_70 . V_75 >> 9 ) & 0x1ff ) ;
F_8 ( V_2 , V_82 , V_70 . V_75 & 0x1ff ) ;
V_3 = F_7 ( V_2 , V_56 ) ;
F_8 ( V_2 , V_56 , V_3 | 0x020 ) ;
V_3 = F_7 ( V_2 , V_17 ) ;
F_8 ( V_2 , V_17 , V_3 | 0x100 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
int V_83 , unsigned int V_84 , int V_85 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_86 * V_87 = F_22 ( V_2 ) ;
switch ( V_84 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_87 -> V_88 = V_84 ;
return 0 ;
}
return - V_21 ;
}
static int F_23 ( struct V_11 * V_12 ,
int V_89 , int div )
{
struct V_1 * V_2 = V_12 -> V_2 ;
T_1 V_3 ;
int V_7 = 0 ;
switch ( V_89 ) {
case V_90 :
V_3 = F_7 ( V_2 , V_17 ) & 0xFFE3 ;
V_7 = F_8 ( V_2 , V_17 , V_3 | ( div << 2 ) ) ;
break;
case V_91 :
V_3 = F_7 ( V_2 , V_17 ) & 0xFF1F ;
V_7 = F_8 ( V_2 , V_17 , V_3 | ( div << 5 ) ) ;
break;
case V_92 :
V_3 = F_7 ( V_2 , V_93 ) & 0xFFCF ;
V_7 = F_8 ( V_2 , V_93 , V_3 | ( div << 4 ) ) ;
break;
}
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , V_62 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_60 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_22 ( V_2 ) ;
struct V_94 * V_95 = V_2 -> V_63 -> V_96 ;
int V_7 ;
T_1 V_3 ;
V_7 = F_27 ( V_2 , 8 , 16 , V_87 -> V_97 ) ;
if ( V_7 < 0 ) {
F_16 ( V_2 -> V_63 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_28 ( V_2 ) ;
if ( V_7 < 0 ) {
F_16 ( V_2 -> V_63 , L_4 ) ;
return V_7 ;
}
F_14 ( V_2 , V_60 ) ;
V_7 = F_8 ( V_2 , V_56 , 0x180 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_95 )
F_29 ( V_2 -> V_63 , L_5 ) ;
else {
V_3 = F_7 ( V_2 , V_58 ) ;
V_7 = F_8 ( V_2 , V_58 , V_3 | V_95 -> V_98 ) ;
if ( V_7 < 0 )
return V_7 ;
}
V_7 = F_30 ( V_2 , V_99 ,
F_4 ( V_99 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_2 ( V_2 ) ;
return V_7 ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_62 ) ;
return 0 ;
}
static T_2 int F_32 ( struct V_100 * V_101 ,
const struct V_102 * V_103 )
{
struct V_86 * V_87 ;
int V_7 ;
V_87 = F_33 ( & V_101 -> V_63 , sizeof( struct V_86 ) ,
V_104 ) ;
if ( V_87 == NULL )
return - V_105 ;
F_34 ( V_101 , V_87 ) ;
V_87 -> V_97 = V_106 ;
V_7 = F_35 ( & V_101 -> V_63 ,
& V_107 , & V_108 , 1 ) ;
return V_7 ;
}
static T_3 int F_36 ( struct V_100 * V_109 )
{
F_37 ( & V_109 -> V_63 ) ;
return 0 ;
}
