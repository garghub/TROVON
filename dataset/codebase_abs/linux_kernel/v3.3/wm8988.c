static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 = F_2 ( V_7 , V_9 ) ;
if ( F_2 ( V_7 , V_10 ) & 0x180 )
V_8 &= ~ 0x4 ;
else
V_8 |= 0x4 ;
return F_3 ( V_7 , V_9 , V_8 ) ;
}
static inline int F_4 ( int V_11 , int V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_5 ( V_14 ) ; V_13 ++ ) {
if ( V_14 [ V_13 ] . V_12 == V_12 && V_14 [ V_13 ] . V_11 == V_11 )
return V_13 ;
}
return - V_15 ;
}
static int F_6 ( struct V_16 * V_17 ,
int V_18 , unsigned int V_19 , int V_20 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_21 * V_22 = F_7 ( V_7 ) ;
switch ( V_19 ) {
case 11289600 :
case 18432000 :
case 22579200 :
case 36864000 :
V_22 -> V_23 = & V_24 ;
V_22 -> V_25 = V_19 ;
return 0 ;
case 12288000 :
case 16934400 :
case 24576000 :
case 33868800 :
V_22 -> V_23 = & V_26 ;
V_22 -> V_25 = V_19 ;
return 0 ;
case 12000000 :
case 24000000 :
V_22 -> V_23 = & V_27 ;
V_22 -> V_25 = V_19 ;
return 0 ;
}
return - V_15 ;
}
static int F_8 ( struct V_16 * V_17 ,
unsigned int V_28 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
T_1 V_29 = 0 ;
switch ( V_28 & V_30 ) {
case V_31 :
V_29 = 0x0040 ;
break;
case V_32 :
break;
default:
return - V_15 ;
}
switch ( V_28 & V_33 ) {
case V_34 :
V_29 |= 0x0002 ;
break;
case V_35 :
break;
case V_36 :
V_29 |= 0x0001 ;
break;
case V_37 :
V_29 |= 0x0003 ;
break;
case V_38 :
V_29 |= 0x0013 ;
break;
default:
return - V_15 ;
}
switch ( V_28 & V_39 ) {
case V_40 :
break;
case V_41 :
V_29 |= 0x0090 ;
break;
case V_42 :
V_29 |= 0x0080 ;
break;
case V_43 :
V_29 |= 0x0010 ;
break;
default:
return - V_15 ;
}
F_3 ( V_7 , V_44 , V_29 ) ;
return 0 ;
}
static int F_9 ( struct V_45 * V_46 ,
struct V_16 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
struct V_21 * V_22 = F_7 ( V_7 ) ;
if ( ! V_22 -> V_25 ) {
F_10 ( V_7 -> V_48 ,
L_1 ) ;
return - V_15 ;
}
F_11 ( V_46 -> V_49 , 0 ,
V_50 ,
V_22 -> V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_45 * V_46 ,
struct V_51 * V_52 ,
struct V_16 * V_47 )
{
struct V_53 * V_54 = V_46 -> V_55 ;
struct V_6 * V_7 = V_54 -> V_7 ;
struct V_21 * V_22 = F_7 ( V_7 ) ;
T_1 V_29 = F_2 ( V_7 , V_44 ) & 0x1f3 ;
T_1 V_56 = F_2 ( V_7 , V_57 ) & 0x180 ;
int V_58 ;
V_58 = F_4 ( V_22 -> V_25 , F_13 ( V_52 ) ) ;
if ( V_58 < 0 ) {
V_58 = F_4 ( V_22 -> V_25 / 2 , F_13 ( V_52 ) ) ;
V_56 |= 0x40 ;
}
if ( V_58 < 0 ) {
F_10 ( V_7 -> V_48 ,
L_2 ,
F_13 ( V_52 ) , V_22 -> V_25 ) ;
return V_58 ;
}
switch ( F_14 ( V_52 ) ) {
case V_59 :
break;
case V_60 :
V_29 |= 0x0004 ;
break;
case V_61 :
V_29 |= 0x0008 ;
break;
case V_62 :
V_29 |= 0x000c ;
break;
}
F_3 ( V_7 , V_44 , V_29 ) ;
if ( V_58 >= 0 )
F_3 ( V_7 , V_57 , V_56 |
( V_14 [ V_58 ] . V_63 << 1 ) | V_14 [ V_58 ] . V_64 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_47 , int V_65 )
{
struct V_6 * V_7 = V_47 -> V_7 ;
T_1 V_66 = F_2 ( V_7 , V_67 ) & 0xfff7 ;
if ( V_65 )
F_3 ( V_7 , V_67 , V_66 | 0x8 ) ;
else
F_3 ( V_7 , V_67 , V_66 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
enum V_68 V_69 )
{
T_1 V_70 = F_2 ( V_7 , V_71 ) & ~ 0x1c1 ;
switch ( V_69 ) {
case V_72 :
break;
case V_73 :
F_3 ( V_7 , V_71 , V_70 | 0x00c0 ) ;
break;
case V_74 :
if ( V_7 -> V_75 . V_76 == V_77 ) {
F_17 ( V_7 ) ;
F_3 ( V_7 , V_71 , V_70 | 0x1c1 ) ;
F_18 ( 100 ) ;
}
F_3 ( V_7 , V_71 , V_70 | 0x0141 ) ;
break;
case V_77 :
F_3 ( V_7 , V_71 , 0x0000 ) ;
break;
}
V_7 -> V_75 . V_76 = V_69 ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
F_16 ( V_7 , V_77 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
F_16 ( V_7 , V_74 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = F_7 ( V_7 ) ;
struct V_78 * V_75 = & V_7 -> V_75 ;
int V_79 = 0 ;
V_79 = F_22 ( V_7 , 7 , 9 , V_22 -> V_80 ) ;
if ( V_79 < 0 ) {
F_10 ( V_7 -> V_48 , L_3 , V_79 ) ;
return V_79 ;
}
V_79 = F_23 ( V_7 ) ;
if ( V_79 < 0 ) {
F_10 ( V_7 -> V_48 , L_4 ) ;
return V_79 ;
}
F_24 ( V_7 , V_81 , 0x0100 , 0x0100 ) ;
F_24 ( V_7 , V_82 , 0x0100 , 0x0100 ) ;
F_24 ( V_7 , V_83 , 0x0100 , 0x0100 ) ;
F_24 ( V_7 , V_84 , 0x0100 , 0x0100 ) ;
F_24 ( V_7 , V_85 , 0x0100 , 0x0100 ) ;
F_16 ( V_7 , V_74 ) ;
F_25 ( V_7 , V_86 ,
F_5 ( V_86 ) ) ;
F_26 ( V_75 , V_87 ,
F_5 ( V_87 ) ) ;
F_27 ( V_75 , V_88 , F_5 ( V_88 ) ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
F_16 ( V_7 , V_77 ) ;
return 0 ;
}
static int T_2 F_29 ( struct V_89 * V_90 )
{
struct V_21 * V_22 ;
int V_79 ;
V_22 = F_30 ( sizeof( struct V_21 ) , V_91 ) ;
if ( V_22 == NULL )
return - V_92 ;
V_22 -> V_80 = V_93 ;
F_31 ( V_90 , V_22 ) ;
V_79 = F_32 ( & V_90 -> V_48 ,
& V_94 , & V_95 , 1 ) ;
if ( V_79 < 0 )
F_33 ( V_22 ) ;
return V_79 ;
}
static int T_3 F_34 ( struct V_89 * V_90 )
{
F_35 ( & V_90 -> V_48 ) ;
F_33 ( F_36 ( V_90 ) ) ;
return 0 ;
}
static T_2 int F_37 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
struct V_21 * V_22 ;
int V_79 ;
V_22 = F_30 ( sizeof( struct V_21 ) , V_91 ) ;
if ( V_22 == NULL )
return - V_92 ;
F_38 ( V_97 , V_22 ) ;
V_22 -> V_80 = V_100 ;
V_79 = F_32 ( & V_97 -> V_48 ,
& V_94 , & V_95 , 1 ) ;
if ( V_79 < 0 )
F_33 ( V_22 ) ;
return V_79 ;
}
static T_3 int F_39 ( struct V_96 * V_101 )
{
F_35 ( & V_101 -> V_48 ) ;
F_33 ( F_40 ( V_101 ) ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
int V_79 = 0 ;
#if F_42 ( V_102 ) || F_42 ( V_103 )
V_79 = F_43 ( & V_104 ) ;
if ( V_79 != 0 ) {
F_44 ( V_105 L_5 ,
V_79 ) ;
}
#endif
#if F_42 ( V_106 )
V_79 = F_45 ( & V_107 ) ;
if ( V_79 != 0 ) {
F_44 ( V_105 L_6 ,
V_79 ) ;
}
#endif
return V_79 ;
}
static void T_5 F_46 ( void )
{
#if F_42 ( V_102 ) || F_42 ( V_103 )
F_47 ( & V_104 ) ;
#endif
#if F_42 ( V_106 )
F_48 ( & V_107 ) ;
#endif
}
