static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_5 , V_6 = F_2 ( V_2 -> V_7 ) ;
int V_8 , V_9 ;
V_5 = V_2 -> V_10 [ V_4 -> V_11 ] ;
if ( V_5 ) {
V_8 = V_6 / V_5 ;
V_4 -> V_12 = 1 << F_3 ( V_8 + 1 ) ;
} else {
V_4 -> V_12 = 8 ;
}
V_5 = V_6 / V_2 -> V_4 . V_12 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_13 ) ; V_9 ++ )
V_2 -> V_14 [ V_9 ] =
V_5 / ( 6 + V_13 [ V_9 ] * ( 25 + 3 ) ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = V_18 ;
V_4 -> V_19 = true ;
V_4 -> V_20 = true ;
V_4 -> V_21 = 12 ;
V_4 -> V_22 = 1 ;
V_4 -> V_11 = V_23 ;
F_1 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_24 = 0 ;
int V_25 = 0 ;
switch ( V_4 -> V_15 ) {
case V_26 :
V_24 |= V_27 ;
break;
case V_28 :
V_24 |= V_29 ;
break;
default:
break;
}
V_24 |= V_30 ;
V_24 |= V_31 ;
switch ( V_4 -> V_17 ) {
case V_18 :
break;
case V_32 :
V_24 |= V_33 ;
break;
case V_34 :
V_24 |= V_35 ;
break;
default:
F_7 ( V_2 -> V_36 , L_1 ) ;
}
if ( V_4 -> V_20 )
V_24 |= V_37 ;
F_8 ( V_24 , V_2 -> V_38 + V_39 ) ;
F_8 ( V_25 , V_2 -> V_38 + V_40 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_41 , V_42 ;
if ( ! V_2 -> V_4 . V_19 )
return;
V_42 = V_43 | V_44 ;
F_8 ( V_42 , V_2 -> V_38 + V_45 ) ;
V_41 = F_10 ( V_2 -> V_38 + V_40 ) ;
F_8 ( V_41 | V_46 , V_2 -> V_38 + V_40 ) ;
if ( ! F_11 ( & V_2 -> V_47 , V_48 ) )
F_7 ( V_2 -> V_36 , L_2 ) ;
V_41 = F_10 ( V_2 -> V_38 + V_49 ) ;
if ( V_41 & V_50 )
F_7 ( V_2 -> V_36 , L_3 ) ;
V_2 -> V_4 . V_19 = false ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_24 ;
V_24 = F_10 ( V_2 -> V_38 + V_39 ) ;
V_24 &= ~ V_30 ;
if ( V_4 -> V_11 == V_23 )
V_24 |= V_30 ;
V_24 &= ~ V_31 ;
if ( V_4 -> V_11 == V_51 )
V_24 |= V_31 ;
F_8 ( V_24 , V_2 -> V_38 + V_39 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_24 , V_25 ;
V_24 = F_10 ( V_2 -> V_38 + V_39 ) ;
V_25 = F_10 ( V_2 -> V_38 + V_40 ) ;
V_24 &= ~ V_52 ;
switch ( V_4 -> V_21 ) {
case 8 :
V_24 |= V_53 ;
break;
case 10 :
V_24 |= V_54 ;
break;
case 12 :
V_24 |= V_55 ;
break;
default:
F_7 ( V_2 -> V_36 , L_4 ) ;
break;
}
V_24 &= ~ ( V_56 | V_57 ) ;
switch ( V_4 -> V_12 ) {
case 1 :
break;
case 2 :
V_24 |= V_58 ;
break;
case 4 :
V_24 |= V_59 ;
break;
case 8 :
V_24 |= V_60 ;
break;
case 16 :
switch ( V_4 -> V_15 ) {
case V_16 :
V_24 |= V_61 | V_60 ;
break;
default:
F_7 ( V_2 -> V_36 , L_5 ) ;
break;
}
break;
}
V_24 &= ~ ( V_62 | V_63 ) ;
V_24 &= ~ V_64 ;
V_25 &= ~ V_65 ;
switch ( V_4 -> V_22 ) {
case V_66 :
break;
case V_67 :
V_25 |= V_65 ;
break;
case V_68 :
V_25 |= V_65 ;
V_24 |= V_69 ;
break;
case V_70 :
V_25 |= V_65 ;
V_24 |= V_71 ;
break;
case V_72 :
V_25 |= V_65 ;
V_24 |= V_73 ;
break;
default:
F_7 ( V_2 -> V_36 ,
L_6 ) ;
}
F_8 ( V_24 , V_2 -> V_38 + V_39 ) ;
F_8 ( V_25 , V_2 -> V_38 + V_40 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_13 ( V_2 ) ;
F_9 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static int F_15 ( struct V_74 * V_75 ,
const struct V_76 * V_77 ,
unsigned int V_78 )
{
struct V_1 * V_2 = F_16 ( V_75 ) ;
F_17 ( & V_75 -> V_79 ) ;
V_2 -> V_4 . V_11 = V_78 ;
F_1 ( V_2 ) ;
F_14 ( V_2 ) ;
F_18 ( & V_75 -> V_79 ) ;
return 0 ;
}
static int F_19 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_1 * V_2 = F_16 ( V_75 ) ;
return V_2 -> V_4 . V_11 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_80 ;
V_80 = F_10 ( V_2 -> V_38 + V_81 ) ;
switch ( V_2 -> V_4 . V_21 ) {
case 8 :
V_80 &= 0xFF ;
break;
case 10 :
V_80 &= 0x3FF ;
break;
case 12 :
V_80 &= 0xFFF ;
break;
default:
break;
}
return V_80 ;
}
static T_1 F_21 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
int V_84 ;
V_84 = F_10 ( V_2 -> V_38 + V_85 ) ;
if ( V_84 & V_86 ) {
V_2 -> V_87 = F_20 ( V_2 ) ;
F_22 ( & V_2 -> V_47 ) ;
}
return V_88 ;
}
static T_2 F_23 ( struct V_89 * V_36 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_1 * V_2 = F_16 ( F_24 ( V_36 ) ) ;
T_3 V_93 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_2 -> V_14 ) ; V_9 ++ )
V_93 += F_25 ( V_92 + V_93 , V_94 - V_93 ,
L_7 , V_2 -> V_14 [ V_9 ] ) ;
V_92 [ V_93 - 1 ] = '\n' ;
return V_93 ;
}
static int F_26 ( struct V_74 * V_75 ,
struct V_76 const * V_77 ,
int * V_95 ,
int * V_96 ,
long V_97 )
{
struct V_1 * V_2 = F_16 ( V_75 ) ;
unsigned int V_42 ;
long V_98 ;
switch ( V_97 ) {
case V_99 :
case V_100 :
F_17 ( & V_75 -> V_79 ) ;
F_27 ( & V_2 -> V_47 ) ;
V_42 = F_28 ( V_77 -> V_101 ) ;
V_42 |= V_43 ;
F_8 ( V_42 , V_2 -> V_38 + V_45 ) ;
V_98 = F_29
( & V_2 -> V_47 , V_48 ) ;
if ( V_98 == 0 ) {
F_18 ( & V_75 -> V_79 ) ;
return - V_102 ;
}
if ( V_98 < 0 ) {
F_18 ( & V_75 -> V_79 ) ;
return V_98 ;
}
switch ( V_77 -> type ) {
case V_103 :
* V_95 = V_2 -> V_87 ;
break;
case V_104 :
* V_95 = 25000 - ( ( int ) V_2 -> V_87 - 864 ) * 1000000 / 1840 ;
break;
default:
F_18 ( & V_75 -> V_79 ) ;
return - V_105 ;
}
F_18 ( & V_75 -> V_79 ) ;
return V_106 ;
case V_107 :
* V_95 = V_2 -> V_108 / 1000 ;
* V_96 = V_2 -> V_4 . V_21 ;
return V_109 ;
case V_110 :
* V_95 = V_2 -> V_14 [ V_2 -> V_4 . V_22 ] ;
* V_96 = 0 ;
return V_106 ;
default:
break;
}
return - V_105 ;
}
static int F_30 ( struct V_74 * V_75 ,
struct V_76 const * V_77 ,
int V_95 ,
int V_96 ,
long V_97 )
{
struct V_1 * V_2 = F_16 ( V_75 ) ;
int V_9 ;
switch ( V_97 ) {
case V_110 :
for ( V_9 = 0 ;
V_9 < F_4 ( V_2 -> V_14 ) ;
V_9 ++ )
if ( V_95 == V_2 -> V_14 [ V_9 ] ) {
V_2 -> V_4 . V_22 = V_9 ;
F_13 ( V_2 ) ;
return 0 ;
}
break;
default:
break;
}
return - V_105 ;
}
static int F_31 ( struct V_74 * V_75 ,
unsigned V_111 , unsigned V_112 ,
unsigned * V_113 )
{
struct V_1 * V_2 = F_16 ( V_75 ) ;
if ( ( V_113 == NULL ) ||
( ( V_111 % 4 ) || ( V_111 > V_114 ) ) )
return - V_105 ;
* V_113 = F_10 ( V_2 -> V_38 + V_111 ) ;
return 0 ;
}
static int F_32 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_117 * V_118 ;
int V_82 ;
int V_98 ;
V_75 = F_33 ( & V_116 -> V_36 , sizeof( struct V_1 ) ) ;
if ( ! V_75 ) {
F_7 ( & V_116 -> V_36 , L_8 ) ;
return - V_119 ;
}
V_2 = F_16 ( V_75 ) ;
V_2 -> V_36 = & V_116 -> V_36 ;
V_118 = F_34 ( V_116 , V_120 , 0 ) ;
V_2 -> V_38 = F_35 ( & V_116 -> V_36 , V_118 ) ;
if ( F_36 ( V_2 -> V_38 ) )
return F_37 ( V_2 -> V_38 ) ;
V_82 = F_38 ( V_116 , 0 ) ;
if ( V_82 < 0 ) {
F_7 ( & V_116 -> V_36 , L_9 ) ;
return V_82 ;
}
V_98 = F_39 ( V_2 -> V_36 , V_82 ,
F_21 , 0 ,
F_40 ( & V_116 -> V_36 ) , V_2 ) ;
if ( V_98 < 0 ) {
F_7 ( & V_116 -> V_36 , L_10 , V_82 ) ;
return V_98 ;
}
V_2 -> V_7 = F_41 ( & V_116 -> V_36 , L_11 ) ;
if ( F_36 ( V_2 -> V_7 ) ) {
F_7 ( & V_116 -> V_36 , L_12 ,
F_37 ( V_2 -> V_7 ) ) ;
return F_37 ( V_2 -> V_7 ) ;
}
V_2 -> V_121 = F_42 ( & V_116 -> V_36 , L_13 ) ;
if ( F_36 ( V_2 -> V_121 ) )
return F_37 ( V_2 -> V_121 ) ;
V_98 = F_43 ( V_2 -> V_121 ) ;
if ( V_98 )
return V_98 ;
V_2 -> V_108 = F_44 ( V_2 -> V_121 ) ;
F_45 ( V_116 -> V_36 . V_122 , L_14 ,
V_2 -> V_10 , 3 ) ;
F_46 ( V_116 , V_75 ) ;
F_47 ( & V_2 -> V_47 ) ;
V_75 -> V_123 = F_40 ( & V_116 -> V_36 ) ;
V_75 -> V_36 . V_124 = & V_116 -> V_36 ;
V_75 -> V_36 . V_122 = V_116 -> V_36 . V_122 ;
V_75 -> V_2 = & V_125 ;
V_75 -> V_126 = V_127 ;
V_75 -> V_128 = V_129 ;
V_75 -> V_130 = F_4 ( V_129 ) ;
V_98 = F_48 ( V_2 -> V_7 ) ;
if ( V_98 ) {
F_7 ( & V_116 -> V_36 ,
L_15 ) ;
goto V_131;
}
F_5 ( V_2 ) ;
F_14 ( V_2 ) ;
V_98 = F_49 ( V_75 ) ;
if ( V_98 ) {
F_7 ( & V_116 -> V_36 , L_16 ) ;
goto V_132;
}
return 0 ;
V_132:
F_50 ( V_2 -> V_7 ) ;
V_131:
F_51 ( V_2 -> V_121 ) ;
return V_98 ;
}
static int F_52 ( struct V_115 * V_116 )
{
struct V_74 * V_75 = F_53 ( V_116 ) ;
struct V_1 * V_2 = F_16 ( V_75 ) ;
F_54 ( V_75 ) ;
F_51 ( V_2 -> V_121 ) ;
F_50 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_55 ( struct V_89 * V_36 )
{
struct V_74 * V_75 = F_56 ( V_36 ) ;
struct V_1 * V_2 = F_16 ( V_75 ) ;
int V_42 ;
V_42 = F_10 ( V_2 -> V_38 + V_45 ) ;
V_42 |= V_44 ;
F_8 ( V_42 , V_2 -> V_38 + V_45 ) ;
F_50 ( V_2 -> V_7 ) ;
F_51 ( V_2 -> V_121 ) ;
return 0 ;
}
static int F_57 ( struct V_89 * V_36 )
{
struct V_74 * V_75 = F_56 ( V_36 ) ;
struct V_1 * V_2 = F_16 ( V_75 ) ;
int V_98 ;
V_98 = F_43 ( V_2 -> V_121 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_48 ( V_2 -> V_7 ) ;
if ( V_98 )
goto V_133;
F_14 ( V_2 ) ;
return 0 ;
V_133:
F_51 ( V_2 -> V_121 ) ;
return V_98 ;
}
