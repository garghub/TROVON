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
int V_40 ;
if ( ! V_2 -> V_7 . V_16 )
return;
V_39 = V_41 | V_42 ;
F_7 ( V_39 , V_2 -> V_35 + V_43 ) ;
V_38 = F_9 ( V_2 -> V_35 + V_37 ) ;
F_7 ( V_38 | V_44 , V_2 -> V_35 + V_37 ) ;
V_40 = F_10
( & V_2 -> V_45 , V_46 ) ;
if ( V_40 == 0 )
F_6 ( V_2 -> V_33 , L_2 ) ;
V_38 = F_9 ( V_2 -> V_35 + V_47 ) ;
if ( V_38 & V_48 )
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
V_21 &= ~ V_49 ;
switch ( V_7 -> V_18 ) {
case 8 :
V_21 |= V_50 ;
break;
case 10 :
V_21 |= V_51 ;
break;
case 12 :
V_21 |= V_52 ;
break;
default:
F_6 ( V_2 -> V_33 , L_4 ) ;
break;
}
V_21 &= ~ ( V_53 | V_54 ) ;
switch ( V_7 -> V_8 ) {
case 1 :
break;
case 2 :
V_21 |= V_55 ;
break;
case 4 :
V_21 |= V_56 ;
break;
case 8 :
V_21 |= V_57 ;
break;
case 16 :
switch ( V_7 -> V_12 ) {
case V_13 :
V_21 |= V_58 | V_57 ;
break;
default:
F_6 ( V_2 -> V_33 , L_5 ) ;
break;
}
break;
}
V_21 &= ~ ( V_59 | V_60 ) ;
V_21 &= ~ V_61 ;
V_22 &= ~ V_62 ;
switch ( V_7 -> V_19 ) {
case V_63 :
break;
case V_64 :
V_22 |= V_62 ;
break;
case V_65 :
V_22 |= V_62 ;
V_21 |= V_66 ;
break;
case V_67 :
V_22 |= V_62 ;
V_21 |= V_68 ;
break;
case V_69 :
V_22 |= V_62 ;
V_21 |= V_70 ;
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
int V_71 ;
V_71 = F_9 ( V_2 -> V_35 + V_72 ) ;
switch ( V_2 -> V_7 . V_18 ) {
case 8 :
V_71 &= 0xFF ;
break;
case 10 :
V_71 &= 0x3FF ;
break;
case 12 :
V_71 &= 0xFFF ;
break;
default:
break;
}
return V_71 ;
}
static T_1 F_15 ( int V_73 , void * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
int V_75 ;
V_75 = F_9 ( V_2 -> V_35 + V_76 ) ;
if ( V_75 & V_77 ) {
V_2 -> V_78 = F_14 ( V_2 ) ;
F_16 ( & V_2 -> V_45 ) ;
}
return V_79 ;
}
static T_2 F_17 ( struct V_80 * V_33 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_1 * V_2 = F_18 ( F_19 ( V_33 ) ) ;
T_3 V_84 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_2 -> V_10 ) ; V_6 ++ )
V_84 += F_20 ( V_83 + V_84 , V_85 - V_84 ,
L_7 , V_2 -> V_10 [ V_6 ] ) ;
V_83 [ V_84 - 1 ] = '\n' ;
return V_84 ;
}
static int F_21 ( struct V_86 * V_87 ,
struct V_88 const * V_89 ,
int * V_90 ,
int * V_91 ,
long V_92 )
{
struct V_1 * V_2 = F_18 ( V_87 ) ;
unsigned int V_39 ;
long V_93 ;
switch ( V_92 ) {
case V_94 :
case V_95 :
F_22 ( & V_87 -> V_96 ) ;
F_23 ( & V_2 -> V_45 ) ;
V_39 = F_24 ( V_89 -> V_97 ) ;
V_39 |= V_41 ;
F_7 ( V_39 , V_2 -> V_35 + V_43 ) ;
V_93 = F_25
( & V_2 -> V_45 , V_46 ) ;
if ( V_93 == 0 ) {
F_26 ( & V_87 -> V_96 ) ;
return - V_98 ;
}
if ( V_93 < 0 ) {
F_26 ( & V_87 -> V_96 ) ;
return V_93 ;
}
switch ( V_89 -> type ) {
case V_99 :
* V_90 = V_2 -> V_78 ;
break;
case V_100 :
* V_90 = 25000 - ( ( int ) V_2 -> V_78 - 864 ) * 1000000 / 1840 ;
break;
default:
F_26 ( & V_87 -> V_96 ) ;
return - V_101 ;
}
F_26 ( & V_87 -> V_96 ) ;
return V_102 ;
case V_103 :
* V_90 = V_2 -> V_104 / 1000 ;
* V_91 = V_2 -> V_7 . V_18 ;
return V_105 ;
case V_106 :
* V_90 = V_2 -> V_10 [ V_2 -> V_7 . V_19 ] ;
* V_91 = 0 ;
return V_102 ;
default:
break;
}
return - V_101 ;
}
static int F_27 ( struct V_86 * V_87 ,
struct V_88 const * V_89 ,
int V_90 ,
int V_91 ,
long V_92 )
{
struct V_1 * V_2 = F_18 ( V_87 ) ;
int V_6 ;
switch ( V_92 ) {
case V_106 :
for ( V_6 = 0 ;
V_6 < F_3 ( V_2 -> V_10 ) ;
V_6 ++ )
if ( V_90 == V_2 -> V_10 [ V_6 ] ) {
V_2 -> V_7 . V_19 = V_6 ;
F_12 ( V_2 ) ;
return 0 ;
}
break;
default:
break;
}
return - V_101 ;
}
static int F_28 ( struct V_86 * V_87 ,
unsigned V_107 , unsigned V_108 ,
unsigned * V_109 )
{
struct V_1 * V_2 = F_18 ( V_87 ) ;
if ( ( V_109 == NULL ) ||
( ! ( V_107 % 4 ) || ( V_107 > V_110 ) ) )
return - V_101 ;
* V_109 = F_9 ( V_2 -> V_35 + V_107 ) ;
return 0 ;
}
static int F_29 ( struct V_111 * V_112 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
struct V_113 * V_114 ;
int V_73 ;
int V_93 ;
V_87 = F_30 ( & V_112 -> V_33 , sizeof( struct V_1 ) ) ;
if ( ! V_87 ) {
F_6 ( & V_112 -> V_33 , L_8 ) ;
return - V_115 ;
}
V_2 = F_18 ( V_87 ) ;
V_2 -> V_33 = & V_112 -> V_33 ;
V_114 = F_31 ( V_112 , V_116 , 0 ) ;
V_2 -> V_35 = F_32 ( & V_112 -> V_33 , V_114 ) ;
if ( F_33 ( V_2 -> V_35 ) )
return F_34 ( V_2 -> V_35 ) ;
V_73 = F_35 ( V_112 , 0 ) ;
if ( V_73 < 0 ) {
F_6 ( & V_112 -> V_33 , L_9 ) ;
return V_73 ;
}
V_93 = F_36 ( V_2 -> V_33 , V_73 ,
F_15 , 0 ,
F_37 ( & V_112 -> V_33 ) , V_2 ) ;
if ( V_93 < 0 ) {
F_6 ( & V_112 -> V_33 , L_10 , V_73 ) ;
return V_93 ;
}
V_2 -> V_5 = F_38 ( & V_112 -> V_33 , L_11 ) ;
if ( F_33 ( V_2 -> V_5 ) ) {
F_6 ( & V_112 -> V_33 , L_12 ,
F_34 ( V_2 -> V_5 ) ) ;
return F_34 ( V_2 -> V_5 ) ;
}
V_2 -> V_117 = F_39 ( & V_112 -> V_33 , L_13 ) ;
if ( F_33 ( V_2 -> V_117 ) )
return F_34 ( V_2 -> V_117 ) ;
V_93 = F_40 ( V_2 -> V_117 ) ;
if ( V_93 )
return V_93 ;
V_2 -> V_104 = F_41 ( V_2 -> V_117 ) ;
F_42 ( V_112 , V_87 ) ;
F_43 ( & V_2 -> V_45 ) ;
V_87 -> V_118 = F_37 ( & V_112 -> V_33 ) ;
V_87 -> V_33 . V_119 = & V_112 -> V_33 ;
V_87 -> V_33 . V_120 = V_112 -> V_33 . V_120 ;
V_87 -> V_2 = & V_121 ;
V_87 -> V_122 = V_123 ;
V_87 -> V_124 = V_125 ;
V_87 -> V_126 = F_3 ( V_125 ) ;
V_93 = F_44 ( V_2 -> V_5 ) ;
if ( V_93 ) {
F_6 ( & V_112 -> V_33 ,
L_14 ) ;
goto V_127;
}
F_4 ( V_2 ) ;
F_13 ( V_2 ) ;
V_93 = F_45 ( V_87 ) ;
if ( V_93 ) {
F_6 ( & V_112 -> V_33 , L_15 ) ;
goto V_128;
}
return 0 ;
V_128:
F_46 ( V_2 -> V_5 ) ;
V_127:
F_47 ( V_2 -> V_117 ) ;
return V_93 ;
}
static int F_48 ( struct V_111 * V_112 )
{
struct V_86 * V_87 = F_49 ( V_112 ) ;
struct V_1 * V_2 = F_18 ( V_87 ) ;
F_50 ( V_87 ) ;
F_47 ( V_2 -> V_117 ) ;
F_46 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_51 ( struct V_80 * V_33 )
{
struct V_86 * V_87 = F_52 ( V_33 ) ;
struct V_1 * V_2 = F_18 ( V_87 ) ;
int V_39 ;
V_39 = F_9 ( V_2 -> V_35 + V_43 ) ;
V_39 |= V_42 ;
F_7 ( V_39 , V_2 -> V_35 + V_43 ) ;
F_46 ( V_2 -> V_5 ) ;
F_47 ( V_2 -> V_117 ) ;
return 0 ;
}
static int F_53 ( struct V_80 * V_33 )
{
struct V_86 * V_87 = F_52 ( V_33 ) ;
struct V_1 * V_2 = F_18 ( V_87 ) ;
int V_93 ;
V_93 = F_40 ( V_2 -> V_117 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_44 ( V_2 -> V_5 ) ;
if ( V_93 )
goto V_129;
F_13 ( V_2 ) ;
return 0 ;
V_129:
F_47 ( V_2 -> V_117 ) ;
return V_93 ;
}
