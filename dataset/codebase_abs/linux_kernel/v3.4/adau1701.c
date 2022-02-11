static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return 2 ;
case V_9 :
return 1 ;
}
F_2 ( V_2 -> V_10 , L_1 , V_3 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_11 )
{
unsigned int V_12 ;
unsigned int V_13 ;
T_1 V_14 [ 4 ] ;
int V_15 ;
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 == 0 )
return - V_16 ;
F_4 ( V_2 , V_3 , V_11 ) ;
V_14 [ 0 ] = 0x08 ;
V_14 [ 1 ] = V_3 ;
for ( V_12 = V_13 + 1 ; V_12 >= 2 ; -- V_12 ) {
V_14 [ V_12 ] = V_11 ;
V_11 >>= 8 ;
}
V_15 = F_5 ( F_6 ( V_2 -> V_10 ) , V_14 , V_13 + 2 ) ;
if ( V_15 == V_13 + 2 )
return 0 ;
else if ( V_15 < 0 )
return V_15 ;
else
return - V_17 ;
}
static unsigned int F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_11 ;
unsigned int V_15 ;
V_15 = F_8 ( V_2 , V_3 , & V_11 ) ;
if ( V_15 )
return V_15 ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 -> V_18 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_20 )
{
struct V_21 * V_21 = F_12 ( V_2 ) ;
unsigned int V_22 = V_23 ;
unsigned int V_24 ;
switch ( V_20 ) {
case V_25 :
V_24 = V_26 ;
break;
case V_27 :
V_24 = V_28 ;
break;
case V_29 :
V_24 = V_30 ;
break;
default:
return - V_16 ;
}
if ( V_21 -> V_31 == V_32 ) {
switch ( V_20 ) {
case V_25 :
V_24 |= V_33 ;
break;
case V_27 :
V_24 |= V_34 ;
break;
case V_29 :
V_24 |= V_35 ;
break;
}
V_22 |= V_36 ;
}
F_13 ( V_2 , V_5 , V_22 , V_24 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_2 V_20 )
{
struct V_21 * V_21 = F_12 ( V_2 ) ;
unsigned int V_24 ;
if ( V_21 -> V_31 != V_32 )
return 0 ;
switch ( V_20 ) {
case V_25 :
V_24 = V_37 ;
break;
case V_27 :
V_24 = V_38 ;
break;
case V_29 :
V_24 = V_39 ;
break;
default:
return - V_16 ;
}
F_13 ( V_2 , V_9 ,
V_40 , V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_41 * V_42 ,
struct V_43 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_42 -> V_49 ;
struct V_1 * V_2 = V_48 -> V_2 ;
T_2 V_20 ;
unsigned int V_24 ;
switch ( F_16 ( V_44 ) ) {
case 192000 :
V_24 = V_50 ;
break;
case 96000 :
V_24 = V_51 ;
break;
case 48000 :
V_24 = V_52 ;
break;
default:
return - V_16 ;
}
F_13 ( V_2 , V_4 ,
V_53 , V_24 ) ;
V_20 = F_17 ( V_44 ) ;
if ( V_42 -> V_54 == V_55 )
return F_14 ( V_2 , V_20 ) ;
else
return F_11 ( V_2 , V_20 ) ;
}
static int F_18 ( struct V_45 * V_56 ,
unsigned int V_57 )
{
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_21 * V_21 = F_12 ( V_2 ) ;
unsigned int V_58 = 0x00 , V_59 = 0x00 ;
bool V_60 ;
switch ( V_57 & V_61 ) {
case V_62 :
V_59 |= V_63 | V_64
| V_65 ;
break;
case V_66 :
break;
default:
return - V_16 ;
}
switch ( V_57 & V_67 ) {
case V_68 :
V_60 = false ;
break;
case V_69 :
V_60 = true ;
break;
case V_70 :
V_60 = false ;
V_58 |= V_71 ;
V_59 |= V_72 ;
break;
case V_73 :
V_60 = true ;
V_58 |= V_71 ;
V_59 |= V_72 ;
break;
default:
return - V_16 ;
}
switch ( V_57 & V_74 ) {
case V_75 :
break;
case V_76 :
V_58 |= V_77 ;
V_59 |= V_78 ;
V_60 = ! V_60 ;
break;
case V_32 :
V_58 |= V_39 ;
V_59 |= V_35 ;
V_60 = ! V_60 ;
break;
default:
return - V_16 ;
}
if ( V_60 ) {
V_59 |= V_79 ;
V_58 |= V_80 ;
}
V_21 -> V_31 = V_57 & V_74 ;
F_19 ( V_2 , V_9 , V_58 ) ;
F_13 ( V_2 , V_5 ,
~ V_23 , V_59 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_81 V_82 )
{
unsigned int V_22 = V_83 | V_84 ;
switch ( V_82 ) {
case V_85 :
break;
case V_86 :
break;
case V_87 :
F_13 ( V_2 , V_6 , V_22 , 0x00 ) ;
break;
case V_88 :
F_13 ( V_2 , V_6 , V_22 , V_22 ) ;
break;
}
V_2 -> V_89 . V_90 = V_82 ;
return 0 ;
}
static int F_21 ( struct V_45 * V_46 , int V_91 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
unsigned int V_22 = V_92 ;
unsigned int V_24 ;
if ( V_91 )
V_24 = 0 ;
else
V_24 = V_22 ;
F_13 ( V_2 , V_4 , V_22 , V_24 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_93 ,
int V_94 , unsigned int V_95 , int V_96 )
{
unsigned int V_24 ;
switch ( V_93 ) {
case V_97 :
V_24 = 0x0 ;
break;
case V_98 :
V_24 = V_99 ;
break;
default:
return - V_16 ;
}
F_13 ( V_2 , V_7 , V_99 , V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_18 = F_6 ( V_2 -> V_10 ) ;
V_15 = F_9 ( V_2 ) ;
if ( V_15 )
F_24 ( V_2 -> V_10 , L_2 ) ;
F_19 ( V_2 , V_8 , V_100 ) ;
F_19 ( V_2 , V_4 , V_101 ) ;
return 0 ;
}
static T_3 int F_25 ( struct V_102 * V_103 ,
const struct V_104 * V_105 )
{
struct V_21 * V_21 ;
int V_15 ;
V_21 = F_26 ( & V_103 -> V_10 , sizeof( * V_21 ) , V_106 ) ;
if ( ! V_21 )
return - V_107 ;
F_27 ( V_103 , V_21 ) ;
V_15 = F_28 ( & V_103 -> V_10 , & V_108 ,
& V_109 , 1 ) ;
return V_15 ;
}
static T_4 int F_29 ( struct V_102 * V_103 )
{
F_30 ( & V_103 -> V_10 ) ;
return 0 ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_110 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_110 ) ;
}
