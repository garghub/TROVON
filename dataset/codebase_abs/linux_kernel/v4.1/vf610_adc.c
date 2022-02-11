static inline void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 ;
V_3 = V_4 / V_2 -> V_7 . V_8 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_9 ) ; V_6 ++ )
V_2 -> V_10 [ V_6 ] =
V_3 / ( 6 + V_9 [ V_6 ] * ( 25 + 3 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_11 * V_7 = & V_2 -> V_7 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = true ;
V_7 -> V_17 = true ;
V_7 -> V_18 = 12 ;
V_7 -> V_19 = 1 ;
V_7 -> V_20 = true ;
V_7 -> V_8 = 8 ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_7 = & V_2 -> V_7 ;
int V_21 = 0 ;
int V_22 = 0 ;
switch ( V_7 -> V_12 ) {
case V_23 :
V_21 |= V_24 ;
break;
case V_25 :
V_21 |= V_26 ;
break;
default:
break;
}
V_21 |= V_27 ;
V_21 |= V_28 ;
switch ( V_7 -> V_14 ) {
case V_15 :
break;
case V_29 :
V_21 |= V_30 ;
break;
case V_31 :
V_21 |= V_32 ;
break;
default:
F_6 ( V_2 -> V_33 , L_1 ) ;
}
if ( V_7 -> V_17 )
V_21 |= V_34 ;
F_7 ( V_21 , V_2 -> V_35 + V_36 ) ;
F_7 ( V_22 , V_2 -> V_35 + V_37 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_38 , V_39 ;
if ( ! V_2 -> V_7 . V_16 )
return;
V_39 = V_40 | V_41 ;
F_7 ( V_39 , V_2 -> V_35 + V_42 ) ;
V_38 = F_9 ( V_2 -> V_35 + V_37 ) ;
F_7 ( V_38 | V_43 , V_2 -> V_35 + V_37 ) ;
if ( ! F_10 ( & V_2 -> V_44 , V_45 ) )
F_6 ( V_2 -> V_33 , L_2 ) ;
V_38 = F_9 ( V_2 -> V_35 + V_46 ) ;
if ( V_38 & V_47 )
F_6 ( V_2 -> V_33 , L_3 ) ;
V_2 -> V_7 . V_16 = false ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_7 = & ( V_2 -> V_7 ) ;
int V_21 ;
V_21 = F_9 ( V_2 -> V_35 + V_36 ) ;
V_21 &= ~ V_27 ;
if ( V_7 -> V_20 )
V_21 |= V_27 ;
V_21 &= ~ V_28 ;
F_7 ( V_21 , V_2 -> V_35 + V_36 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_7 = & ( V_2 -> V_7 ) ;
int V_21 , V_22 ;
V_21 = F_9 ( V_2 -> V_35 + V_36 ) ;
V_22 = F_9 ( V_2 -> V_35 + V_37 ) ;
V_21 &= ~ V_48 ;
switch ( V_7 -> V_18 ) {
case 8 :
V_21 |= V_49 ;
break;
case 10 :
V_21 |= V_50 ;
break;
case 12 :
V_21 |= V_51 ;
break;
default:
F_6 ( V_2 -> V_33 , L_4 ) ;
break;
}
V_21 &= ~ ( V_52 | V_53 ) ;
switch ( V_7 -> V_8 ) {
case 1 :
break;
case 2 :
V_21 |= V_54 ;
break;
case 4 :
V_21 |= V_55 ;
break;
case 8 :
V_21 |= V_56 ;
break;
case 16 :
switch ( V_7 -> V_12 ) {
case V_13 :
V_21 |= V_57 | V_56 ;
break;
default:
F_6 ( V_2 -> V_33 , L_5 ) ;
break;
}
break;
}
V_21 &= ~ ( V_58 | V_59 ) ;
V_21 &= ~ V_60 ;
V_22 &= ~ V_61 ;
switch ( V_7 -> V_19 ) {
case V_62 :
break;
case V_63 :
V_22 |= V_61 ;
break;
case V_64 :
V_22 |= V_61 ;
V_21 |= V_65 ;
break;
case V_66 :
V_22 |= V_61 ;
V_21 |= V_67 ;
break;
case V_68 :
V_22 |= V_61 ;
V_21 |= V_69 ;
break;
default:
F_6 ( V_2 -> V_33 ,
L_6 ) ;
}
F_7 ( V_21 , V_2 -> V_35 + V_36 ) ;
F_7 ( V_22 , V_2 -> V_35 + V_37 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_70 ;
V_70 = F_9 ( V_2 -> V_35 + V_71 ) ;
switch ( V_2 -> V_7 . V_18 ) {
case 8 :
V_70 &= 0xFF ;
break;
case 10 :
V_70 &= 0x3FF ;
break;
case 12 :
V_70 &= 0xFFF ;
break;
default:
break;
}
return V_70 ;
}
static T_1 F_15 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
int V_74 ;
V_74 = F_9 ( V_2 -> V_35 + V_75 ) ;
if ( V_74 & V_76 ) {
V_2 -> V_77 = F_14 ( V_2 ) ;
F_16 ( & V_2 -> V_44 ) ;
}
return V_78 ;
}
static T_2 F_17 ( struct V_79 * V_33 ,
struct V_80 * V_81 , char * V_82 )
{
struct V_1 * V_2 = F_18 ( F_19 ( V_33 ) ) ;
T_3 V_83 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_2 -> V_10 ) ; V_6 ++ )
V_83 += F_20 ( V_82 + V_83 , V_84 - V_83 ,
L_7 , V_2 -> V_10 [ V_6 ] ) ;
V_82 [ V_83 - 1 ] = '\n' ;
return V_83 ;
}
static int F_21 ( struct V_85 * V_86 ,
struct V_87 const * V_88 ,
int * V_89 ,
int * V_90 ,
long V_91 )
{
struct V_1 * V_2 = F_18 ( V_86 ) ;
unsigned int V_39 ;
long V_92 ;
switch ( V_91 ) {
case V_93 :
case V_94 :
F_22 ( & V_86 -> V_95 ) ;
F_23 ( & V_2 -> V_44 ) ;
V_39 = F_24 ( V_88 -> V_96 ) ;
V_39 |= V_40 ;
F_7 ( V_39 , V_2 -> V_35 + V_42 ) ;
V_92 = F_25
( & V_2 -> V_44 , V_45 ) ;
if ( V_92 == 0 ) {
F_26 ( & V_86 -> V_95 ) ;
return - V_97 ;
}
if ( V_92 < 0 ) {
F_26 ( & V_86 -> V_95 ) ;
return V_92 ;
}
switch ( V_88 -> type ) {
case V_98 :
* V_89 = V_2 -> V_77 ;
break;
case V_99 :
* V_89 = 25000 - ( ( int ) V_2 -> V_77 - 864 ) * 1000000 / 1840 ;
break;
default:
F_26 ( & V_86 -> V_95 ) ;
return - V_100 ;
}
F_26 ( & V_86 -> V_95 ) ;
return V_101 ;
case V_102 :
* V_89 = V_2 -> V_103 / 1000 ;
* V_90 = V_2 -> V_7 . V_18 ;
return V_104 ;
case V_105 :
* V_89 = V_2 -> V_10 [ V_2 -> V_7 . V_19 ] ;
* V_90 = 0 ;
return V_101 ;
default:
break;
}
return - V_100 ;
}
static int F_27 ( struct V_85 * V_86 ,
struct V_87 const * V_88 ,
int V_89 ,
int V_90 ,
long V_91 )
{
struct V_1 * V_2 = F_18 ( V_86 ) ;
int V_6 ;
switch ( V_91 ) {
case V_105 :
for ( V_6 = 0 ;
V_6 < F_3 ( V_2 -> V_10 ) ;
V_6 ++ )
if ( V_89 == V_2 -> V_10 [ V_6 ] ) {
V_2 -> V_7 . V_19 = V_6 ;
F_12 ( V_2 ) ;
return 0 ;
}
break;
default:
break;
}
return - V_100 ;
}
static int F_28 ( struct V_85 * V_86 ,
unsigned V_106 , unsigned V_107 ,
unsigned * V_108 )
{
struct V_1 * V_2 = F_18 ( V_86 ) ;
if ( ( V_108 == NULL ) ||
( ! ( V_106 % 4 ) || ( V_106 > V_109 ) ) )
return - V_100 ;
* V_108 = F_9 ( V_2 -> V_35 + V_106 ) ;
return 0 ;
}
static int F_29 ( struct V_110 * V_111 )
{
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_112 * V_113 ;
int V_72 ;
int V_92 ;
V_86 = F_30 ( & V_111 -> V_33 , sizeof( struct V_1 ) ) ;
if ( ! V_86 ) {
F_6 ( & V_111 -> V_33 , L_8 ) ;
return - V_114 ;
}
V_2 = F_18 ( V_86 ) ;
V_2 -> V_33 = & V_111 -> V_33 ;
V_113 = F_31 ( V_111 , V_115 , 0 ) ;
V_2 -> V_35 = F_32 ( & V_111 -> V_33 , V_113 ) ;
if ( F_33 ( V_2 -> V_35 ) )
return F_34 ( V_2 -> V_35 ) ;
V_72 = F_35 ( V_111 , 0 ) ;
if ( V_72 < 0 ) {
F_6 ( & V_111 -> V_33 , L_9 ) ;
return V_72 ;
}
V_92 = F_36 ( V_2 -> V_33 , V_72 ,
F_15 , 0 ,
F_37 ( & V_111 -> V_33 ) , V_2 ) ;
if ( V_92 < 0 ) {
F_6 ( & V_111 -> V_33 , L_10 , V_72 ) ;
return V_92 ;
}
V_2 -> V_5 = F_38 ( & V_111 -> V_33 , L_11 ) ;
if ( F_33 ( V_2 -> V_5 ) ) {
F_6 ( & V_111 -> V_33 , L_12 ,
F_34 ( V_2 -> V_5 ) ) ;
return F_34 ( V_2 -> V_5 ) ;
}
V_2 -> V_116 = F_39 ( & V_111 -> V_33 , L_13 ) ;
if ( F_33 ( V_2 -> V_116 ) )
return F_34 ( V_2 -> V_116 ) ;
V_92 = F_40 ( V_2 -> V_116 ) ;
if ( V_92 )
return V_92 ;
V_2 -> V_103 = F_41 ( V_2 -> V_116 ) ;
F_42 ( V_111 , V_86 ) ;
F_43 ( & V_2 -> V_44 ) ;
V_86 -> V_117 = F_37 ( & V_111 -> V_33 ) ;
V_86 -> V_33 . V_118 = & V_111 -> V_33 ;
V_86 -> V_33 . V_119 = V_111 -> V_33 . V_119 ;
V_86 -> V_2 = & V_120 ;
V_86 -> V_121 = V_122 ;
V_86 -> V_123 = V_124 ;
V_86 -> V_125 = F_3 ( V_124 ) ;
V_92 = F_44 ( V_2 -> V_5 ) ;
if ( V_92 ) {
F_6 ( & V_111 -> V_33 ,
L_14 ) ;
goto V_126;
}
F_4 ( V_2 ) ;
F_13 ( V_2 ) ;
V_92 = F_45 ( V_86 ) ;
if ( V_92 ) {
F_6 ( & V_111 -> V_33 , L_15 ) ;
goto V_127;
}
return 0 ;
V_127:
F_46 ( V_2 -> V_5 ) ;
V_126:
F_47 ( V_2 -> V_116 ) ;
return V_92 ;
}
static int F_48 ( struct V_110 * V_111 )
{
struct V_85 * V_86 = F_49 ( V_111 ) ;
struct V_1 * V_2 = F_18 ( V_86 ) ;
F_50 ( V_86 ) ;
F_47 ( V_2 -> V_116 ) ;
F_46 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_51 ( struct V_79 * V_33 )
{
struct V_85 * V_86 = F_52 ( V_33 ) ;
struct V_1 * V_2 = F_18 ( V_86 ) ;
int V_39 ;
V_39 = F_9 ( V_2 -> V_35 + V_42 ) ;
V_39 |= V_41 ;
F_7 ( V_39 , V_2 -> V_35 + V_42 ) ;
F_46 ( V_2 -> V_5 ) ;
F_47 ( V_2 -> V_116 ) ;
return 0 ;
}
static int F_53 ( struct V_79 * V_33 )
{
struct V_85 * V_86 = F_52 ( V_33 ) ;
struct V_1 * V_2 = F_18 ( V_86 ) ;
int V_92 ;
V_92 = F_40 ( V_2 -> V_116 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_44 ( V_2 -> V_5 ) ;
if ( V_92 )
goto V_128;
F_13 ( V_2 ) ;
return 0 ;
V_128:
F_47 ( V_2 -> V_116 ) ;
return V_92 ;
}
