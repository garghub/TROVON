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
struct V_1 * V_2 = V_46 -> V_2 ;
T_2 V_20 ;
unsigned int V_24 ;
switch ( F_16 ( V_44 ) ) {
case 192000 :
V_24 = V_47 ;
break;
case 96000 :
V_24 = V_48 ;
break;
case 48000 :
V_24 = V_49 ;
break;
default:
return - V_16 ;
}
F_13 ( V_2 , V_4 ,
V_50 , V_24 ) ;
V_20 = F_17 ( V_44 ) ;
if ( V_42 -> V_51 == V_52 )
return F_14 ( V_2 , V_20 ) ;
else
return F_11 ( V_2 , V_20 ) ;
}
static int F_18 ( struct V_45 * V_53 ,
unsigned int V_54 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_21 * V_21 = F_12 ( V_2 ) ;
unsigned int V_55 = 0x00 , V_56 = 0x00 ;
bool V_57 ;
switch ( V_54 & V_58 ) {
case V_59 :
V_56 |= V_60 | V_61
| V_62 ;
break;
case V_63 :
break;
default:
return - V_16 ;
}
switch ( V_54 & V_64 ) {
case V_65 :
V_57 = false ;
break;
case V_66 :
V_57 = true ;
break;
case V_67 :
V_57 = false ;
V_55 |= V_68 ;
V_56 |= V_69 ;
break;
case V_70 :
V_57 = true ;
V_55 |= V_68 ;
V_56 |= V_69 ;
break;
default:
return - V_16 ;
}
switch ( V_54 & V_71 ) {
case V_72 :
break;
case V_73 :
V_55 |= V_74 ;
V_56 |= V_75 ;
V_57 = ! V_57 ;
break;
case V_32 :
V_55 |= V_39 ;
V_56 |= V_35 ;
V_57 = ! V_57 ;
break;
default:
return - V_16 ;
}
if ( V_57 ) {
V_56 |= V_76 ;
V_55 |= V_77 ;
}
V_21 -> V_31 = V_54 & V_71 ;
F_19 ( V_2 , V_9 , V_55 ) ;
F_13 ( V_2 , V_5 ,
~ V_23 , V_56 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
unsigned int V_22 = V_80 | V_81 ;
switch ( V_79 ) {
case V_82 :
break;
case V_83 :
break;
case V_84 :
F_13 ( V_2 , V_6 , V_22 , 0x00 ) ;
break;
case V_85 :
F_13 ( V_2 , V_6 , V_22 , V_22 ) ;
break;
}
V_2 -> V_86 . V_87 = V_79 ;
return 0 ;
}
static int F_21 ( struct V_45 * V_46 , int V_88 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
unsigned int V_22 = V_89 ;
unsigned int V_24 ;
if ( V_88 )
V_24 = 0 ;
else
V_24 = V_22 ;
F_13 ( V_2 , V_4 , V_22 , V_24 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_90 ,
int V_91 , unsigned int V_92 , int V_93 )
{
unsigned int V_24 ;
switch ( V_90 ) {
case V_94 :
V_24 = 0x0 ;
break;
case V_95 :
V_24 = V_96 ;
break;
default:
return - V_16 ;
}
F_13 ( V_2 , V_7 , V_96 , V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_18 = F_6 ( V_2 -> V_10 ) ;
V_15 = F_9 ( V_2 ) ;
if ( V_15 )
F_24 ( V_2 -> V_10 , L_2 ) ;
F_19 ( V_2 , V_8 , V_97 ) ;
F_19 ( V_2 , V_4 , V_98 ) ;
return 0 ;
}
static int F_25 ( struct V_99 * V_100 ,
const struct V_101 * V_102 )
{
struct V_21 * V_21 ;
int V_15 ;
V_21 = F_26 ( & V_100 -> V_10 , sizeof( * V_21 ) , V_103 ) ;
if ( ! V_21 )
return - V_104 ;
F_27 ( V_100 , V_21 ) ;
V_15 = F_28 ( & V_100 -> V_10 , & V_105 ,
& V_106 , 1 ) ;
return V_15 ;
}
static int F_29 ( struct V_99 * V_100 )
{
F_30 ( & V_100 -> V_10 ) ;
return 0 ;
}
