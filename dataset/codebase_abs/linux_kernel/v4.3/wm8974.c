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
static int F_8 ( struct V_14 * V_15 ,
unsigned int V_34 )
{
struct V_19 * V_20 = V_15 -> V_20 ;
T_1 V_35 = 0 ;
T_1 V_36 = F_5 ( V_20 , V_22 ) & 0x1fe ;
switch ( V_34 & V_37 ) {
case V_38 :
V_36 |= 0x0001 ;
break;
case V_39 :
break;
default:
return - V_33 ;
}
switch ( V_34 & V_40 ) {
case V_41 :
V_35 |= 0x0010 ;
break;
case V_42 :
break;
case V_43 :
V_35 |= 0x0008 ;
break;
case V_44 :
V_35 |= 0x00018 ;
break;
default:
return - V_33 ;
}
switch ( V_34 & V_45 ) {
case V_46 :
break;
case V_47 :
V_35 |= 0x0180 ;
break;
case V_48 :
V_35 |= 0x0100 ;
break;
case V_49 :
V_35 |= 0x0080 ;
break;
default:
return - V_33 ;
}
F_6 ( V_20 , V_50 , V_35 ) ;
F_6 ( V_20 , V_22 , V_36 ) ;
return 0 ;
}
static int F_9 ( struct V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_14 * V_55 )
{
struct V_19 * V_20 = V_55 -> V_20 ;
T_1 V_35 = F_5 ( V_20 , V_50 ) & 0x19f ;
T_1 V_56 = F_5 ( V_20 , V_57 ) & 0x1f1 ;
switch ( F_10 ( V_54 ) ) {
case 16 :
break;
case 20 :
V_35 |= 0x0020 ;
break;
case 24 :
V_35 |= 0x0040 ;
break;
case 32 :
V_35 |= 0x0060 ;
break;
}
switch ( F_11 ( V_54 ) ) {
case 8000 :
V_56 |= 0x5 << 1 ;
break;
case 11025 :
V_56 |= 0x4 << 1 ;
break;
case 16000 :
V_56 |= 0x3 << 1 ;
break;
case 22050 :
V_56 |= 0x2 << 1 ;
break;
case 32000 :
V_56 |= 0x1 << 1 ;
break;
case 44100 :
case 48000 :
break;
}
F_6 ( V_20 , V_50 , V_35 ) ;
F_6 ( V_20 , V_57 , V_56 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_55 , int V_58 )
{
struct V_19 * V_20 = V_55 -> V_20 ;
T_1 V_59 = F_5 ( V_20 , V_60 ) & 0xffbf ;
if ( V_58 )
F_6 ( V_20 , V_60 , V_59 | 0x40 ) ;
else
F_6 ( V_20 , V_60 , V_59 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_20 ,
enum V_61 V_62 )
{
T_1 V_63 = F_5 ( V_20 , V_23 ) & ~ 0x3 ;
switch ( V_62 ) {
case V_64 :
case V_65 :
V_63 |= 0x1 ;
F_6 ( V_20 , V_23 , V_63 ) ;
break;
case V_66 :
V_63 |= V_67 | V_68 ;
if ( F_14 ( V_20 ) == V_69 ) {
F_15 ( F_16 ( V_20 -> V_70 , NULL ) ) ;
F_6 ( V_20 , V_23 , V_63 | 0x3 ) ;
F_17 ( 100 ) ;
}
V_63 |= 0x2 ;
F_6 ( V_20 , V_23 , V_63 ) ;
break;
case V_69 :
F_6 ( V_20 , V_23 , 0 ) ;
F_6 ( V_20 , V_71 , 0 ) ;
F_6 ( V_20 , V_72 , 0 ) ;
break;
}
return 0 ;
}
static int F_18 ( struct V_19 * V_20 )
{
int V_73 = 0 ;
V_73 = F_19 ( V_20 ) ;
if ( V_73 < 0 ) {
F_20 ( V_20 -> V_70 , L_2 ) ;
return V_73 ;
}
return 0 ;
}
static int F_21 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_78 * V_78 ;
int V_73 ;
V_78 = F_22 ( V_75 , & V_79 ) ;
if ( F_23 ( V_78 ) )
return F_24 ( V_78 ) ;
V_73 = F_25 ( & V_75 -> V_70 ,
& V_80 , & V_81 , 1 ) ;
return V_73 ;
}
static int F_26 ( struct V_74 * V_82 )
{
F_27 ( & V_82 -> V_70 ) ;
return 0 ;
}
