static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long long V_3 ;
unsigned int V_4 , V_5 , V_6 ;
V_5 = V_1 / V_2 ;
if ( V_5 < 6 ) {
V_2 >>= 1 ;
V_7 . V_8 = 1 ;
V_5 = V_1 / V_2 ;
} else
V_7 . V_8 = 0 ;
if ( ( V_5 < 6 ) || ( V_5 > 12 ) )
F_2 ( V_9
L_1 ,
V_5 ) ;
V_7 . V_10 = V_5 ;
V_6 = V_1 % V_2 ;
V_3 = V_11 * ( long long ) V_6 ;
F_3 ( V_3 , V_2 ) ;
V_4 = V_3 & 0xFFFFFFFF ;
if ( ( V_4 % 10 ) >= 5 )
V_4 += 5 ;
V_4 /= 10 ;
V_7 . V_12 = V_4 ;
}
static int F_4 ( struct V_13 * V_14 , int V_15 ,
int V_2 , unsigned int V_16 , unsigned int V_17 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
T_1 V_20 ;
if ( V_16 == 0 || V_17 == 0 ) {
V_20 = F_5 ( V_19 , V_21 ) ;
F_6 ( V_19 , V_21 , V_20 & 0x0ff ) ;
V_20 = F_5 ( V_19 , V_22 ) ;
F_6 ( V_19 , V_22 , V_20 & 0x1df ) ;
return 0 ;
}
F_1 ( V_17 * 4 , V_16 ) ;
F_6 ( V_19 , V_23 , ( V_7 . V_8 << 4 ) | V_7 . V_10 ) ;
F_6 ( V_19 , V_24 , V_7 . V_12 >> 18 ) ;
F_6 ( V_19 , V_25 , ( V_7 . V_12 >> 9 ) & 0x1ff ) ;
F_6 ( V_19 , V_26 , V_7 . V_12 & 0x1ff ) ;
V_20 = F_5 ( V_19 , V_22 ) ;
F_6 ( V_19 , V_22 , V_20 | 0x020 ) ;
V_20 = F_5 ( V_19 , V_21 ) ;
F_6 ( V_19 , V_21 , V_20 | 0x100 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_14 ,
int V_27 , int div )
{
struct V_18 * V_19 = V_14 -> V_19 ;
T_1 V_20 ;
switch ( V_27 ) {
case V_28 :
V_20 = F_5 ( V_19 , V_29 ) & 0x1cf ;
F_6 ( V_19 , V_29 , V_20 | div ) ;
break;
case V_30 :
V_20 = F_5 ( V_19 , V_21 ) & 0x11f ;
F_6 ( V_19 , V_21 , V_20 | div ) ;
break;
case V_31 :
V_20 = F_5 ( V_19 , V_32 ) & 0x1f7 ;
F_6 ( V_19 , V_32 , V_20 | div ) ;
break;
case V_33 :
V_20 = F_5 ( V_19 , V_34 ) & 0x1f7 ;
F_6 ( V_19 , V_34 , V_20 | div ) ;
break;
case V_35 :
V_20 = F_5 ( V_19 , V_21 ) & 0x1e3 ;
F_6 ( V_19 , V_21 , V_20 | div ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
unsigned int V_37 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
T_1 V_38 = 0 ;
T_1 V_39 = F_5 ( V_19 , V_21 ) & 0x1fe ;
switch ( V_37 & V_40 ) {
case V_41 :
V_39 |= 0x0001 ;
break;
case V_42 :
break;
default:
return - V_36 ;
}
switch ( V_37 & V_43 ) {
case V_44 :
V_38 |= 0x0010 ;
break;
case V_45 :
break;
case V_46 :
V_38 |= 0x0008 ;
break;
case V_47 :
V_38 |= 0x00018 ;
break;
default:
return - V_36 ;
}
switch ( V_37 & V_48 ) {
case V_49 :
break;
case V_50 :
V_38 |= 0x0180 ;
break;
case V_51 :
V_38 |= 0x0100 ;
break;
case V_52 :
V_38 |= 0x0080 ;
break;
default:
return - V_36 ;
}
F_6 ( V_19 , V_53 , V_38 ) ;
F_6 ( V_19 , V_21 , V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_13 * V_58 )
{
struct V_59 * V_60 = V_55 -> V_61 ;
struct V_18 * V_19 = V_60 -> V_19 ;
T_1 V_38 = F_5 ( V_19 , V_53 ) & 0x19f ;
T_1 V_62 = F_5 ( V_19 , V_63 ) & 0x1f1 ;
switch ( F_10 ( V_57 ) ) {
case V_64 :
break;
case V_65 :
V_38 |= 0x0020 ;
break;
case V_66 :
V_38 |= 0x0040 ;
break;
case V_67 :
V_38 |= 0x0060 ;
break;
}
switch ( F_11 ( V_57 ) ) {
case 8000 :
V_62 |= 0x5 << 1 ;
break;
case 11025 :
V_62 |= 0x4 << 1 ;
break;
case 16000 :
V_62 |= 0x3 << 1 ;
break;
case 22050 :
V_62 |= 0x2 << 1 ;
break;
case 32000 :
V_62 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
F_6 ( V_19 , V_53 , V_38 ) ;
F_6 ( V_19 , V_63 , V_62 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_58 , int V_68 )
{
struct V_18 * V_19 = V_58 -> V_19 ;
T_1 V_69 = F_5 ( V_19 , V_34 ) & 0xffbf ;
if ( V_68 )
F_6 ( V_19 , V_34 , V_69 | 0x40 ) ;
else
F_6 ( V_19 , V_34 , V_69 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
enum V_70 V_71 )
{
T_1 V_72 = F_5 ( V_19 , V_22 ) & ~ 0x3 ;
switch ( V_71 ) {
case V_73 :
case V_74 :
V_72 |= 0x1 ;
F_6 ( V_19 , V_22 , V_72 ) ;
break;
case V_75 :
V_72 |= V_76 | V_77 ;
if ( V_19 -> V_78 . V_79 == V_80 ) {
F_14 ( V_19 ) ;
F_6 ( V_19 , V_22 , V_72 | 0x3 ) ;
F_15 ( 100 ) ;
}
V_72 |= 0x2 ;
F_6 ( V_19 , V_22 , V_72 ) ;
break;
case V_80 :
F_6 ( V_19 , V_22 , 0 ) ;
F_6 ( V_19 , V_81 , 0 ) ;
F_6 ( V_19 , V_82 , 0 ) ;
break;
}
V_19 -> V_78 . V_79 = V_71 ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
F_13 ( V_19 , V_80 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 )
{
F_13 ( V_19 , V_75 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_83 * V_84 = F_19 ( V_19 ) ;
int V_85 ;
V_85 = F_20 ( V_19 , 7 , 9 , V_84 -> V_86 ) ;
if ( V_85 < 0 ) {
F_2 ( V_87 L_2 , V_85 ) ;
return V_85 ;
}
F_21 ( V_19 ) ;
F_13 ( V_19 , V_75 ) ;
return V_85 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_83 * V_84 = F_19 ( V_19 ) ;
F_13 ( V_19 , V_80 ) ;
F_23 ( V_84 ) ;
return 0 ;
}
static int T_2 F_24 ( struct V_88 * V_89 )
{
struct V_83 * V_84 ;
int V_85 ;
V_84 = F_25 ( sizeof( struct V_83 ) , V_90 ) ;
if ( V_84 == NULL )
return - V_91 ;
V_84 -> V_86 = V_92 ;
F_26 ( V_89 , V_84 ) ;
V_85 = F_27 ( & V_89 -> V_93 ,
& V_94 , & V_95 , 1 ) ;
if ( V_85 < 0 )
F_23 ( V_84 ) ;
return V_85 ;
}
static int T_3 F_28 ( struct V_88 * V_89 )
{
F_29 ( & V_89 -> V_93 ) ;
return 0 ;
}
static T_2 int F_30 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
struct V_83 * V_84 ;
int V_85 ;
V_84 = F_25 ( sizeof( struct V_83 ) , V_90 ) ;
if ( V_84 == NULL )
return - V_91 ;
F_31 ( V_97 , V_84 ) ;
V_84 -> V_86 = V_100 ;
V_85 = F_27 ( & V_97 -> V_93 ,
& V_94 , & V_95 , 1 ) ;
if ( V_85 < 0 )
F_23 ( V_84 ) ;
return V_85 ;
}
static T_3 int F_32 ( struct V_96 * V_101 )
{
F_29 ( & V_101 -> V_93 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_85 = 0 ;
#if F_34 ( V_102 ) || F_34 ( V_103 )
V_85 = F_35 ( & V_104 ) ;
if ( V_85 != 0 ) {
F_2 ( V_87 L_3 ,
V_85 ) ;
}
#endif
#if F_34 ( V_105 )
V_85 = F_36 ( & V_106 ) ;
if ( V_85 != 0 ) {
F_2 ( V_87 L_4 ,
V_85 ) ;
}
#endif
return V_85 ;
}
static void T_5 F_37 ( void )
{
#if F_34 ( V_102 ) || F_34 ( V_103 )
F_38 ( & V_104 ) ;
#endif
#if F_34 ( V_105 )
F_39 ( & V_106 ) ;
#endif
}
