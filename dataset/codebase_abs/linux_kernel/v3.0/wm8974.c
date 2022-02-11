static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( V_4 , V_5 ,
F_3 ( V_5 ) ) ;
F_4 ( V_4 , V_6 , F_3 ( V_6 ) ) ;
return 0 ;
}
static void F_5 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
unsigned long long V_11 ;
unsigned int V_12 , V_13 , V_14 ;
V_9 *= 4 ;
V_13 = V_9 / V_10 ;
if ( V_13 < 6 ) {
V_10 /= 2 ;
V_8 -> V_15 = 1 ;
V_13 = V_9 / V_10 ;
} else
V_8 -> V_15 = 0 ;
if ( ( V_13 < 6 ) || ( V_13 > 12 ) )
F_6 ( V_16
L_1 ,
V_13 ) ;
V_8 -> V_17 = V_13 ;
V_14 = V_9 % V_10 ;
V_11 = V_18 * ( long long ) V_14 ;
F_7 ( V_11 , V_10 ) ;
V_12 = V_11 & 0xFFFFFFFF ;
if ( ( V_12 % 10 ) >= 5 )
V_12 += 5 ;
V_12 /= 10 ;
V_8 -> V_19 = V_12 ;
}
static int F_8 ( struct V_20 * V_21 , int V_22 ,
int V_10 , unsigned int V_23 , unsigned int V_24 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 V_8 ;
T_1 V_25 ;
if ( V_23 == 0 || V_24 == 0 ) {
V_25 = F_9 ( V_2 , V_26 ) ;
F_10 ( V_2 , V_26 , V_25 & 0x0ff ) ;
V_25 = F_9 ( V_2 , V_27 ) ;
F_10 ( V_2 , V_27 , V_25 & 0x1df ) ;
return 0 ;
}
F_5 ( & V_8 , V_24 , V_23 ) ;
F_10 ( V_2 , V_28 , ( V_8 . V_15 << 4 ) | V_8 . V_17 ) ;
F_10 ( V_2 , V_29 , V_8 . V_19 >> 18 ) ;
F_10 ( V_2 , V_30 , ( V_8 . V_19 >> 9 ) & 0x1ff ) ;
F_10 ( V_2 , V_31 , V_8 . V_19 & 0x1ff ) ;
V_25 = F_9 ( V_2 , V_27 ) ;
F_10 ( V_2 , V_27 , V_25 | 0x020 ) ;
V_25 = F_9 ( V_2 , V_26 ) ;
F_10 ( V_2 , V_26 , V_25 | 0x100 ) ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
int V_32 , int div )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_25 ;
switch ( V_32 ) {
case V_33 :
V_25 = F_9 ( V_2 , V_34 ) & 0x1cf ;
F_10 ( V_2 , V_34 , V_25 | div ) ;
break;
case V_35 :
V_25 = F_9 ( V_2 , V_26 ) & 0x11f ;
F_10 ( V_2 , V_26 , V_25 | div ) ;
break;
case V_36 :
V_25 = F_9 ( V_2 , V_26 ) & 0x1e3 ;
F_10 ( V_2 , V_26 , V_25 | div ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static int F_12 ( struct V_20 * V_21 ,
unsigned int V_38 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_39 = 0 ;
T_1 V_40 = F_9 ( V_2 , V_26 ) & 0x1fe ;
switch ( V_38 & V_41 ) {
case V_42 :
V_40 |= 0x0001 ;
break;
case V_43 :
break;
default:
return - V_37 ;
}
switch ( V_38 & V_44 ) {
case V_45 :
V_39 |= 0x0010 ;
break;
case V_46 :
break;
case V_47 :
V_39 |= 0x0008 ;
break;
case V_48 :
V_39 |= 0x00018 ;
break;
default:
return - V_37 ;
}
switch ( V_38 & V_49 ) {
case V_50 :
break;
case V_51 :
V_39 |= 0x0180 ;
break;
case V_52 :
V_39 |= 0x0100 ;
break;
case V_53 :
V_39 |= 0x0080 ;
break;
default:
return - V_37 ;
}
F_10 ( V_2 , V_54 , V_39 ) ;
F_10 ( V_2 , V_26 , V_40 ) ;
return 0 ;
}
static int F_13 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_20 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
T_1 V_39 = F_9 ( V_2 , V_54 ) & 0x19f ;
T_1 V_60 = F_9 ( V_2 , V_61 ) & 0x1f1 ;
switch ( F_14 ( V_58 ) ) {
case V_62 :
break;
case V_63 :
V_39 |= 0x0020 ;
break;
case V_64 :
V_39 |= 0x0040 ;
break;
case V_65 :
V_39 |= 0x0060 ;
break;
}
switch ( F_15 ( V_58 ) ) {
case 8000 :
V_60 |= 0x5 << 1 ;
break;
case 11025 :
V_60 |= 0x4 << 1 ;
break;
case 16000 :
V_60 |= 0x3 << 1 ;
break;
case 22050 :
V_60 |= 0x2 << 1 ;
break;
case 32000 :
V_60 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
F_10 ( V_2 , V_54 , V_39 ) ;
F_10 ( V_2 , V_61 , V_60 ) ;
return 0 ;
}
static int F_16 ( struct V_20 * V_59 , int V_66 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
T_1 V_67 = F_9 ( V_2 , V_68 ) & 0xffbf ;
if ( V_66 )
F_10 ( V_2 , V_68 , V_67 | 0x40 ) ;
else
F_10 ( V_2 , V_68 , V_67 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_69 V_70 )
{
T_1 V_71 = F_9 ( V_2 , V_27 ) & ~ 0x3 ;
switch ( V_70 ) {
case V_72 :
case V_73 :
V_71 |= 0x1 ;
F_10 ( V_2 , V_27 , V_71 ) ;
break;
case V_74 :
V_71 |= V_75 | V_76 ;
if ( V_2 -> V_4 . V_77 == V_78 ) {
F_10 ( V_2 , V_27 , V_71 | 0x3 ) ;
F_18 ( 100 ) ;
}
V_71 |= 0x2 ;
F_10 ( V_2 , V_27 , V_71 ) ;
break;
case V_78 :
F_10 ( V_2 , V_27 , 0 ) ;
F_10 ( V_2 , V_79 , 0 ) ;
F_10 ( V_2 , V_80 , 0 ) ;
break;
}
V_2 -> V_4 . V_77 = V_70 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_81 )
{
F_17 ( V_2 , V_78 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_82 ;
T_3 V_83 [ 2 ] ;
T_1 * V_84 = V_2 -> V_85 ;
for ( V_82 = 0 ; V_82 < F_3 ( V_86 ) ; V_82 ++ ) {
V_83 [ 0 ] = ( V_82 << 1 ) | ( ( V_84 [ V_82 ] >> 8 ) & 0x0001 ) ;
V_83 [ 1 ] = V_84 [ V_82 ] & 0x00ff ;
V_2 -> V_87 ( V_2 -> V_88 , V_83 , 2 ) ;
}
F_17 ( V_2 , V_74 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_89 = 0 ;
V_89 = F_22 ( V_2 , 7 , 9 , V_90 ) ;
if ( V_89 < 0 ) {
F_23 ( V_2 -> V_91 , L_2 , V_89 ) ;
return V_89 ;
}
V_89 = F_24 ( V_2 ) ;
if ( V_89 < 0 ) {
F_23 ( V_2 -> V_91 , L_3 ) ;
return V_89 ;
}
F_17 ( V_2 , V_74 ) ;
F_25 ( V_2 , V_92 ,
F_3 ( V_92 ) ) ;
F_1 ( V_2 ) ;
return V_89 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_78 ) ;
return 0 ;
}
static T_4 int F_27 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
struct V_97 * V_98 ;
int V_89 ;
V_98 = F_28 ( sizeof( struct V_97 ) , V_99 ) ;
if ( V_98 == NULL )
return - V_100 ;
F_29 ( V_94 , V_98 ) ;
V_89 = F_30 ( & V_94 -> V_91 ,
& V_101 , & V_102 , 1 ) ;
if ( V_89 < 0 )
F_31 ( V_98 ) ;
return V_89 ;
}
static T_5 int F_32 ( struct V_93 * V_103 )
{
F_33 ( & V_103 -> V_91 ) ;
F_31 ( F_34 ( V_103 ) ) ;
return 0 ;
}
static int T_6 F_35 ( void )
{
int V_89 = 0 ;
#if F_36 ( V_104 ) || F_36 ( V_105 )
V_89 = F_37 ( & V_106 ) ;
if ( V_89 != 0 ) {
F_6 ( V_107 L_4 ,
V_89 ) ;
}
#endif
return V_89 ;
}
static void T_7 F_38 ( void )
{
#if F_36 ( V_104 ) || F_36 ( V_105 )
F_39 ( & V_106 ) ;
#endif
}
