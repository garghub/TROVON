static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned long long V_5 ;
unsigned int V_6 , V_7 , V_8 ;
V_3 *= 4 ;
V_7 = V_3 / V_4 ;
if ( V_7 < 6 ) {
V_4 /= 2 ;
V_2 -> V_9 = 1 ;
V_7 = V_3 / V_4 ;
} else
V_2 -> V_9 = 0 ;
if ( ( V_7 < 6 ) || ( V_7 > 12 ) )
F_2 ( V_10
L_1 ,
V_7 ) ;
V_2 -> V_11 = V_7 ;
V_8 = V_3 % V_4 ;
V_5 = V_12 * ( long long ) V_8 ;
F_3 ( V_5 , V_4 ) ;
V_6 = V_5 & 0xFFFFFFFF ;
if ( ( V_6 % 10 ) >= 5 )
V_6 += 5 ;
V_6 /= 10 ;
V_2 -> V_13 = V_6 ;
}
static int F_4 ( struct V_14 * V_15 , int V_16 ,
int V_4 , unsigned int V_17 , unsigned int V_18 )
{
struct V_19 * V_20 = V_15 -> V_20 ;
struct V_1 V_2 ;
T_1 V_21 ;
if ( V_17 == 0 || V_18 == 0 ) {
V_21 = F_5 ( V_20 , V_22 ) ;
F_6 ( V_20 , V_22 , V_21 & 0x0ff ) ;
V_21 = F_5 ( V_20 , V_23 ) ;
F_6 ( V_20 , V_23 , V_21 & 0x1df ) ;
return 0 ;
}
F_1 ( & V_2 , V_18 , V_17 ) ;
F_6 ( V_20 , V_24 , ( V_2 . V_9 << 4 ) | V_2 . V_11 ) ;
F_6 ( V_20 , V_25 , V_2 . V_13 >> 18 ) ;
F_6 ( V_20 , V_26 , ( V_2 . V_13 >> 9 ) & 0x1ff ) ;
F_6 ( V_20 , V_27 , V_2 . V_13 & 0x1ff ) ;
V_21 = F_5 ( V_20 , V_23 ) ;
F_6 ( V_20 , V_23 , V_21 | 0x020 ) ;
V_21 = F_5 ( V_20 , V_22 ) ;
F_6 ( V_20 , V_22 , V_21 | 0x100 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 ,
int V_28 , int div )
{
struct V_19 * V_20 = V_15 -> V_20 ;
T_1 V_21 ;
switch ( V_28 ) {
case V_29 :
V_21 = F_5 ( V_20 , V_30 ) & 0x1cf ;
F_6 ( V_20 , V_30 , V_21 | div ) ;
break;
case V_31 :
V_21 = F_5 ( V_20 , V_22 ) & 0x11f ;
F_6 ( V_20 , V_22 , V_21 | div ) ;
break;
case V_32 :
V_21 = F_5 ( V_20 , V_22 ) & 0x1e3 ;
F_6 ( V_20 , V_22 , V_21 | div ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static unsigned int F_8 ( unsigned int V_34 , unsigned int V_35 ,
int * V_36 )
{
unsigned int V_37 = 2 * V_34 / V_35 ;
if ( V_37 <= 2 ) {
* V_36 = V_38 ;
V_37 = 2 ;
} else if ( V_37 == 3 ) {
* V_36 = V_39 ;
} else if ( V_37 == 4 ) {
* V_36 = V_40 ;
} else if ( V_37 <= 6 ) {
* V_36 = V_41 ;
V_37 = 6 ;
} else if ( V_37 <= 8 ) {
* V_36 = V_42 ;
V_37 = 8 ;
} else if ( V_37 <= 12 ) {
* V_36 = V_43 ;
V_37 = 12 ;
} else if ( V_37 <= 16 ) {
* V_36 = V_44 ;
V_37 = 16 ;
} else {
* V_36 = V_45 ;
V_37 = 24 ;
}
return V_35 * V_37 / 2 ;
}
static int F_9 ( struct V_14 * V_46 )
{
struct V_19 * V_20 = V_46 -> V_20 ;
struct V_47 * V_48 = F_10 ( V_20 ) ;
unsigned int V_49 ;
unsigned int V_50 = 0 ;
unsigned int V_51 ;
int V_36 ;
if ( ! V_48 -> V_52 || ! V_48 -> V_53 )
return 0 ;
V_49 = 256 * V_48 -> V_53 ;
V_51 = F_8 ( V_48 -> V_52 , V_49 , & V_36 ) ;
if ( V_51 != V_48 -> V_52 ) {
V_50 = F_8 ( 22500000 , V_49 , & V_36 ) ;
}
F_4 ( V_46 , 0 , 0 , V_48 -> V_52 , V_50 ) ;
F_7 ( V_46 , V_31 , V_36 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_46 , int V_54 ,
unsigned int V_55 , int V_56 )
{
struct V_19 * V_20 = V_46 -> V_20 ;
struct V_47 * V_48 = F_10 ( V_20 ) ;
if ( V_56 != V_57 )
return - V_33 ;
V_48 -> V_52 = V_55 ;
return F_9 ( V_46 ) ;
}
static int F_12 ( struct V_14 * V_15 ,
unsigned int V_58 )
{
struct V_19 * V_20 = V_15 -> V_20 ;
T_1 V_59 = 0 ;
T_1 V_60 = F_5 ( V_20 , V_22 ) & 0x1fe ;
switch ( V_58 & V_61 ) {
case V_62 :
V_60 |= 0x0001 ;
break;
case V_63 :
break;
default:
return - V_33 ;
}
switch ( V_58 & V_64 ) {
case V_65 :
V_59 |= 0x0010 ;
break;
case V_66 :
break;
case V_67 :
V_59 |= 0x0008 ;
break;
case V_68 :
V_59 |= 0x00018 ;
break;
default:
return - V_33 ;
}
switch ( V_58 & V_69 ) {
case V_70 :
break;
case V_71 :
V_59 |= 0x0180 ;
break;
case V_72 :
V_59 |= 0x0100 ;
break;
case V_73 :
V_59 |= 0x0080 ;
break;
default:
return - V_33 ;
}
F_6 ( V_20 , V_74 , V_59 ) ;
F_6 ( V_20 , V_22 , V_60 ) ;
return 0 ;
}
static int F_13 ( struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_14 * V_46 )
{
struct V_19 * V_20 = V_46 -> V_20 ;
struct V_47 * V_48 = F_10 ( V_20 ) ;
T_1 V_59 = F_5 ( V_20 , V_74 ) & 0x19f ;
T_1 V_79 = F_5 ( V_20 , V_80 ) & 0x1f1 ;
int V_81 ;
V_48 -> V_53 = F_14 ( V_78 ) ;
V_81 = F_9 ( V_46 ) ;
if ( V_81 )
return V_81 ;
switch ( F_15 ( V_78 ) ) {
case 16 :
break;
case 20 :
V_59 |= 0x0020 ;
break;
case 24 :
V_59 |= 0x0040 ;
break;
case 32 :
V_59 |= 0x0060 ;
break;
}
switch ( F_14 ( V_78 ) ) {
case 8000 :
V_79 |= 0x5 << 1 ;
break;
case 11025 :
V_79 |= 0x4 << 1 ;
break;
case 16000 :
V_79 |= 0x3 << 1 ;
break;
case 22050 :
V_79 |= 0x2 << 1 ;
break;
case 32000 :
V_79 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
F_6 ( V_20 , V_74 , V_59 ) ;
F_6 ( V_20 , V_80 , V_79 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_46 , int V_82 )
{
struct V_19 * V_20 = V_46 -> V_20 ;
T_1 V_83 = F_5 ( V_20 , V_84 ) & 0xffbf ;
if ( V_82 )
F_6 ( V_20 , V_84 , V_83 | 0x40 ) ;
else
F_6 ( V_20 , V_84 , V_83 ) ;
return 0 ;
}
static int F_17 ( struct V_19 * V_20 ,
enum V_85 V_86 )
{
T_1 V_87 = F_5 ( V_20 , V_23 ) & ~ 0x3 ;
switch ( V_86 ) {
case V_88 :
case V_89 :
V_87 |= 0x1 ;
F_6 ( V_20 , V_23 , V_87 ) ;
break;
case V_90 :
V_87 |= V_91 | V_92 ;
if ( F_18 ( V_20 ) == V_93 ) {
F_19 ( F_20 ( V_20 -> V_94 , NULL ) ) ;
F_6 ( V_20 , V_23 , V_87 | 0x3 ) ;
F_21 ( 100 ) ;
}
V_87 |= 0x2 ;
F_6 ( V_20 , V_23 , V_87 ) ;
break;
case V_93 :
F_6 ( V_20 , V_23 , 0 ) ;
F_6 ( V_20 , V_95 , 0 ) ;
F_6 ( V_20 , V_96 , 0 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
int V_97 = 0 ;
V_97 = F_23 ( V_20 ) ;
if ( V_97 < 0 ) {
F_24 ( V_20 -> V_94 , L_2 ) ;
return V_97 ;
}
return 0 ;
}
static int F_25 ( struct V_98 * V_99 ,
const struct V_100 * V_101 )
{
struct V_47 * V_48 ;
struct V_102 * V_102 ;
int V_97 ;
V_48 = F_26 ( & V_99 -> V_94 , sizeof( * V_48 ) , V_103 ) ;
if ( ! V_48 )
return - V_104 ;
F_27 ( V_99 , V_48 ) ;
V_102 = F_28 ( V_99 , & V_105 ) ;
if ( F_29 ( V_102 ) )
return F_30 ( V_102 ) ;
V_97 = F_31 ( & V_99 -> V_94 ,
& V_106 , & V_107 , 1 ) ;
return V_97 ;
}
static int F_32 ( struct V_98 * V_108 )
{
F_33 ( & V_108 -> V_94 ) ;
return 0 ;
}
