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
struct V_18 * V_19 = V_58 -> V_19 ;
T_1 V_38 = F_5 ( V_19 , V_53 ) & 0x19f ;
T_1 V_59 = F_5 ( V_19 , V_60 ) & 0x1f1 ;
switch ( F_10 ( V_57 ) ) {
case V_61 :
break;
case V_62 :
V_38 |= 0x0020 ;
break;
case V_63 :
V_38 |= 0x0040 ;
break;
case V_64 :
V_38 |= 0x0060 ;
break;
}
switch ( F_11 ( V_57 ) ) {
case 8000 :
V_59 |= 0x5 << 1 ;
break;
case 11025 :
V_59 |= 0x4 << 1 ;
break;
case 16000 :
V_59 |= 0x3 << 1 ;
break;
case 22050 :
V_59 |= 0x2 << 1 ;
break;
case 32000 :
V_59 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
F_6 ( V_19 , V_53 , V_38 ) ;
F_6 ( V_19 , V_60 , V_59 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_58 , int V_65 )
{
struct V_18 * V_19 = V_58 -> V_19 ;
T_1 V_66 = F_5 ( V_19 , V_34 ) & 0xffbf ;
if ( V_65 )
F_6 ( V_19 , V_34 , V_66 | 0x40 ) ;
else
F_6 ( V_19 , V_34 , V_66 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
enum V_67 V_68 )
{
T_1 V_69 = F_5 ( V_19 , V_22 ) & ~ 0x3 ;
switch ( V_68 ) {
case V_70 :
case V_71 :
V_69 |= 0x1 ;
F_6 ( V_19 , V_22 , V_69 ) ;
break;
case V_72 :
V_69 |= V_73 | V_74 ;
if ( V_19 -> V_75 . V_76 == V_77 ) {
F_14 ( V_19 ) ;
F_6 ( V_19 , V_22 , V_69 | 0x3 ) ;
F_15 ( 100 ) ;
}
V_69 |= 0x2 ;
F_6 ( V_19 , V_22 , V_69 ) ;
break;
case V_77 :
F_6 ( V_19 , V_22 , 0 ) ;
F_6 ( V_19 , V_78 , 0 ) ;
F_6 ( V_19 , V_79 , 0 ) ;
break;
}
V_19 -> V_75 . V_76 = V_68 ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
F_13 ( V_19 , V_77 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 )
{
F_13 ( V_19 , V_72 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_80 * V_81 = F_19 ( V_19 ) ;
int V_82 ;
V_82 = F_20 ( V_19 , 7 , 9 , V_81 -> V_83 ) ;
if ( V_82 < 0 ) {
F_2 ( V_84 L_2 , V_82 ) ;
return V_82 ;
}
F_21 ( V_19 ) ;
F_13 ( V_19 , V_72 ) ;
return V_82 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_80 * V_81 = F_19 ( V_19 ) ;
F_13 ( V_19 , V_77 ) ;
F_23 ( V_81 ) ;
return 0 ;
}
static int T_2 F_24 ( struct V_85 * V_86 )
{
struct V_80 * V_81 ;
int V_82 ;
V_81 = F_25 ( sizeof( struct V_80 ) , V_87 ) ;
if ( V_81 == NULL )
return - V_88 ;
V_81 -> V_83 = V_89 ;
F_26 ( V_86 , V_81 ) ;
V_82 = F_27 ( & V_86 -> V_90 ,
& V_91 , & V_92 , 1 ) ;
if ( V_82 < 0 )
F_23 ( V_81 ) ;
return V_82 ;
}
static int T_3 F_28 ( struct V_85 * V_86 )
{
F_29 ( & V_86 -> V_90 ) ;
return 0 ;
}
static T_2 int F_30 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
struct V_80 * V_81 ;
int V_82 ;
V_81 = F_25 ( sizeof( struct V_80 ) , V_87 ) ;
if ( V_81 == NULL )
return - V_88 ;
F_31 ( V_94 , V_81 ) ;
V_81 -> V_83 = V_97 ;
V_82 = F_27 ( & V_94 -> V_90 ,
& V_91 , & V_92 , 1 ) ;
if ( V_82 < 0 )
F_23 ( V_81 ) ;
return V_82 ;
}
static T_3 int F_32 ( struct V_93 * V_98 )
{
F_29 ( & V_98 -> V_90 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_82 = 0 ;
#if F_34 ( V_99 ) || F_34 ( V_100 )
V_82 = F_35 ( & V_101 ) ;
if ( V_82 != 0 ) {
F_2 ( V_84 L_3 ,
V_82 ) ;
}
#endif
#if F_34 ( V_102 )
V_82 = F_36 ( & V_103 ) ;
if ( V_82 != 0 ) {
F_2 ( V_84 L_4 ,
V_82 ) ;
}
#endif
return V_82 ;
}
static void T_5 F_37 ( void )
{
#if F_34 ( V_99 ) || F_34 ( V_100 )
F_38 ( & V_101 ) ;
#endif
#if F_34 ( V_102 )
F_39 ( & V_103 ) ;
#endif
}
