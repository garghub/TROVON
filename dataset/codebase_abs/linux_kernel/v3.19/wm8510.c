static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static void F_2 ( unsigned int V_5 , unsigned int V_6 )
{
unsigned long long V_7 ;
unsigned int V_8 , V_9 , V_10 ;
V_9 = V_5 / V_6 ;
if ( V_9 < 6 ) {
V_6 >>= 1 ;
V_11 . V_12 = 1 ;
V_9 = V_5 / V_6 ;
} else
V_11 . V_12 = 0 ;
if ( ( V_9 < 6 ) || ( V_9 > 12 ) )
F_3 ( V_13
L_1 ,
V_9 ) ;
V_11 . V_14 = V_9 ;
V_10 = V_5 % V_6 ;
V_7 = V_15 * ( long long ) V_10 ;
F_4 ( V_7 , V_6 ) ;
V_8 = V_7 & 0xFFFFFFFF ;
if ( ( V_8 % 10 ) >= 5 )
V_8 += 5 ;
V_8 /= 10 ;
V_11 . V_16 = V_8 ;
}
static int F_5 ( struct V_17 * V_18 , int V_19 ,
int V_6 , unsigned int V_20 , unsigned int V_21 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_1 V_3 ;
if ( V_20 == 0 || V_21 == 0 ) {
V_3 = F_6 ( V_23 , V_24 ) ;
F_7 ( V_23 , V_24 , V_3 & 0x0ff ) ;
V_3 = F_6 ( V_23 , V_25 ) ;
F_7 ( V_23 , V_25 , V_3 & 0x1df ) ;
return 0 ;
}
F_2 ( V_21 * 4 , V_20 ) ;
F_7 ( V_23 , V_26 , ( V_11 . V_12 << 4 ) | V_11 . V_14 ) ;
F_7 ( V_23 , V_27 , V_11 . V_16 >> 18 ) ;
F_7 ( V_23 , V_28 , ( V_11 . V_16 >> 9 ) & 0x1ff ) ;
F_7 ( V_23 , V_29 , V_11 . V_16 & 0x1ff ) ;
V_3 = F_6 ( V_23 , V_25 ) ;
F_7 ( V_23 , V_25 , V_3 | 0x020 ) ;
V_3 = F_6 ( V_23 , V_24 ) ;
F_7 ( V_23 , V_24 , V_3 | 0x100 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
int V_30 , int div )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_1 V_3 ;
switch ( V_30 ) {
case V_31 :
V_3 = F_6 ( V_23 , V_32 ) & 0x1cf ;
F_7 ( V_23 , V_32 , V_3 | div ) ;
break;
case V_33 :
V_3 = F_6 ( V_23 , V_24 ) & 0x11f ;
F_7 ( V_23 , V_24 , V_3 | div ) ;
break;
case V_34 :
V_3 = F_6 ( V_23 , V_35 ) & 0x1f7 ;
F_7 ( V_23 , V_35 , V_3 | div ) ;
break;
case V_36 :
V_3 = F_6 ( V_23 , V_37 ) & 0x1f7 ;
F_7 ( V_23 , V_37 , V_3 | div ) ;
break;
case V_38 :
V_3 = F_6 ( V_23 , V_24 ) & 0x1e3 ;
F_7 ( V_23 , V_24 , V_3 | div ) ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
unsigned int V_40 )
{
struct V_22 * V_23 = V_18 -> V_23 ;
T_1 V_41 = 0 ;
T_1 V_42 = F_6 ( V_23 , V_24 ) & 0x1fe ;
switch ( V_40 & V_43 ) {
case V_44 :
V_42 |= 0x0001 ;
break;
case V_45 :
break;
default:
return - V_39 ;
}
switch ( V_40 & V_46 ) {
case V_47 :
V_41 |= 0x0010 ;
break;
case V_48 :
break;
case V_49 :
V_41 |= 0x0008 ;
break;
case V_50 :
V_41 |= 0x00018 ;
break;
default:
return - V_39 ;
}
switch ( V_40 & V_51 ) {
case V_52 :
break;
case V_53 :
V_41 |= 0x0180 ;
break;
case V_54 :
V_41 |= 0x0100 ;
break;
case V_55 :
V_41 |= 0x0080 ;
break;
default:
return - V_39 ;
}
F_7 ( V_23 , V_56 , V_41 ) ;
F_7 ( V_23 , V_24 , V_42 ) ;
return 0 ;
}
static int F_10 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
struct V_17 * V_61 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
T_1 V_41 = F_6 ( V_23 , V_56 ) & 0x19f ;
T_1 V_62 = F_6 ( V_23 , V_63 ) & 0x1f1 ;
switch ( F_11 ( V_60 ) ) {
case 16 :
break;
case 20 :
V_41 |= 0x0020 ;
break;
case 24 :
V_41 |= 0x0040 ;
break;
case 32 :
V_41 |= 0x0060 ;
break;
}
switch ( F_12 ( V_60 ) ) {
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
F_7 ( V_23 , V_56 , V_41 ) ;
F_7 ( V_23 , V_63 , V_62 ) ;
return 0 ;
}
static int F_13 ( struct V_17 * V_61 , int V_64 )
{
struct V_22 * V_23 = V_61 -> V_23 ;
T_1 V_65 = F_6 ( V_23 , V_37 ) & 0xffbf ;
if ( V_64 )
F_7 ( V_23 , V_37 , V_65 | 0x40 ) ;
else
F_7 ( V_23 , V_37 , V_65 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 ,
enum V_66 V_67 )
{
struct V_68 * V_69 = F_15 ( V_23 ) ;
T_1 V_70 = F_6 ( V_23 , V_25 ) & ~ 0x3 ;
switch ( V_67 ) {
case V_71 :
case V_72 :
V_70 |= 0x1 ;
F_7 ( V_23 , V_25 , V_70 ) ;
break;
case V_73 :
V_70 |= V_74 | V_75 ;
if ( V_23 -> V_76 . V_77 == V_78 ) {
F_16 ( V_69 -> V_79 ) ;
F_7 ( V_23 , V_25 , V_70 | 0x3 ) ;
F_17 ( 100 ) ;
}
V_70 |= 0x2 ;
F_7 ( V_23 , V_25 , V_70 ) ;
break;
case V_78 :
F_7 ( V_23 , V_25 , 0 ) ;
F_7 ( V_23 , V_80 , 0 ) ;
F_7 ( V_23 , V_81 , 0 ) ;
break;
}
V_23 -> V_76 . V_77 = V_67 ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 )
{
F_19 ( V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_82 * V_83 )
{
struct V_68 * V_69 ;
int V_84 ;
V_69 = F_21 ( & V_83 -> V_2 , sizeof( struct V_68 ) ,
V_85 ) ;
if ( V_69 == NULL )
return - V_86 ;
V_69 -> V_79 = F_22 ( V_83 , & V_87 ) ;
if ( F_23 ( V_69 -> V_79 ) )
return F_24 ( V_69 -> V_79 ) ;
F_25 ( V_83 , V_69 ) ;
V_84 = F_26 ( & V_83 -> V_2 ,
& V_88 , & V_89 , 1 ) ;
return V_84 ;
}
static int F_27 ( struct V_82 * V_83 )
{
F_28 ( & V_83 -> V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_90 * V_91 ,
const struct V_92 * V_93 )
{
struct V_68 * V_69 ;
int V_84 ;
V_69 = F_21 ( & V_91 -> V_2 , sizeof( struct V_68 ) ,
V_85 ) ;
if ( V_69 == NULL )
return - V_86 ;
V_69 -> V_79 = F_30 ( V_91 , & V_87 ) ;
if ( F_23 ( V_69 -> V_79 ) )
return F_24 ( V_69 -> V_79 ) ;
F_31 ( V_91 , V_69 ) ;
V_84 = F_26 ( & V_91 -> V_2 ,
& V_88 , & V_89 , 1 ) ;
return V_84 ;
}
static int F_32 ( struct V_90 * V_94 )
{
F_28 ( & V_94 -> V_2 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
int V_84 = 0 ;
#if F_34 ( V_95 )
V_84 = F_35 ( & V_96 ) ;
if ( V_84 != 0 ) {
F_3 ( V_97 L_2 ,
V_84 ) ;
}
#endif
#if F_36 ( V_98 )
V_84 = F_37 ( & V_99 ) ;
if ( V_84 != 0 ) {
F_3 ( V_97 L_3 ,
V_84 ) ;
}
#endif
return V_84 ;
}
static void T_3 F_38 ( void )
{
#if F_34 ( V_95 )
F_39 ( & V_96 ) ;
#endif
#if F_36 ( V_98 )
F_40 ( & V_99 ) ;
#endif
}
