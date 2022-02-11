static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
V_2 -> V_3 . V_6 = V_7 ;
V_2 -> V_3 . V_8 = true ;
V_2 -> V_3 . V_9 = true ;
V_2 -> V_3 . V_10 = 1 ;
V_2 -> V_3 . V_11 = 12 ;
V_2 -> V_3 . V_12 = 1 ;
V_2 -> V_3 . V_13 = true ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_14 * V_3 = & V_2 -> V_3 ;
int V_15 = 0 ;
int V_16 = 0 ;
switch ( V_3 -> V_4 ) {
case V_17 :
V_15 |= V_18 ;
break;
case V_19 :
V_15 |= V_20 ;
break;
default:
break;
}
V_15 |= V_21 ;
V_15 |= V_22 ;
switch ( V_3 -> V_6 ) {
case V_7 :
break;
case V_23 :
V_15 |= V_24 ;
break;
case V_25 :
V_15 |= V_26 ;
break;
default:
F_3 ( V_2 -> V_27 , L_1 ) ;
}
if ( V_3 -> V_9 )
V_15 |= V_28 ;
F_4 ( V_15 , V_2 -> V_29 + V_30 ) ;
F_4 ( V_16 , V_2 -> V_29 + V_31 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_32 , V_33 ;
int V_34 ;
if ( ! V_2 -> V_3 . V_8 )
return;
V_33 = V_35 | V_36 ;
F_4 ( V_33 , V_2 -> V_29 + V_37 ) ;
V_32 = F_6 ( V_2 -> V_29 + V_31 ) ;
F_4 ( V_32 | V_38 , V_2 -> V_29 + V_31 ) ;
V_34 = F_7
( & V_2 -> V_39 , V_40 ) ;
if ( V_34 == 0 )
F_3 ( V_2 -> V_27 , L_2 ) ;
V_32 = F_6 ( V_2 -> V_29 + V_41 ) ;
if ( V_32 & V_42 )
F_3 ( V_2 -> V_27 , L_3 ) ;
V_2 -> V_3 . V_8 = false ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_3 = & ( V_2 -> V_3 ) ;
int V_15 ;
V_15 = F_6 ( V_2 -> V_29 + V_30 ) ;
V_15 &= ~ V_21 ;
if ( V_3 -> V_13 )
V_15 |= V_21 ;
V_15 &= ~ V_22 ;
F_4 ( V_15 , V_2 -> V_29 + V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_3 = & ( V_2 -> V_3 ) ;
int V_15 , V_16 ;
V_15 = F_6 ( V_2 -> V_29 + V_30 ) ;
V_16 = F_6 ( V_2 -> V_29 + V_31 ) ;
V_15 &= ~ V_43 ;
switch ( V_3 -> V_11 ) {
case 8 :
V_15 |= V_44 ;
break;
case 10 :
V_15 |= V_45 ;
break;
case 12 :
V_15 |= V_46 ;
break;
default:
F_3 ( V_2 -> V_27 , L_4 ) ;
break;
}
V_15 &= ~ ( V_47 | V_48 ) ;
switch ( V_3 -> V_10 ) {
case 1 :
break;
case 2 :
V_15 |= V_49 ;
break;
case 4 :
V_15 |= V_50 ;
break;
case 8 :
V_15 |= V_51 ;
break;
case 16 :
switch ( V_3 -> V_4 ) {
case V_5 :
V_15 |= V_52 | V_51 ;
break;
default:
F_3 ( V_2 -> V_27 , L_5 ) ;
break;
}
break;
}
V_15 &= ~ ( V_53 | V_54 ) ;
V_15 &= ~ V_55 ;
V_16 &= ~ V_56 ;
switch ( V_3 -> V_12 ) {
case V_57 :
break;
case V_58 :
V_16 |= V_56 ;
break;
case V_59 :
V_16 |= V_56 ;
V_15 |= V_60 ;
break;
case V_61 :
V_16 |= V_56 ;
V_15 |= V_62 ;
break;
case V_63 :
V_16 |= V_56 ;
V_15 |= V_64 ;
break;
default:
F_3 ( V_2 -> V_27 ,
L_6 ) ;
}
F_4 ( V_15 , V_2 -> V_29 + V_30 ) ;
F_4 ( V_16 , V_2 -> V_29 + V_31 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_65 ;
V_65 = F_6 ( V_2 -> V_29 + V_66 ) ;
switch ( V_2 -> V_3 . V_11 ) {
case 8 :
V_65 &= 0xFF ;
break;
case 10 :
V_65 &= 0x3FF ;
break;
case 12 :
V_65 &= 0xFFF ;
break;
default:
break;
}
return V_65 ;
}
static T_1 F_12 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
int V_69 ;
V_69 = F_6 ( V_2 -> V_29 + V_70 ) ;
if ( V_69 & V_71 ) {
V_2 -> V_72 = F_11 ( V_2 ) ;
F_13 ( & V_2 -> V_39 ) ;
}
return V_73 ;
}
static int F_14 ( struct V_74 * V_75 ,
struct V_76 const * V_77 ,
int * V_78 ,
int * V_79 ,
long V_80 )
{
struct V_1 * V_2 = F_15 ( V_75 ) ;
unsigned int V_33 ;
long V_81 ;
switch ( V_80 ) {
case V_82 :
case V_83 :
F_16 ( & V_75 -> V_84 ) ;
F_17 ( & V_2 -> V_39 ) ;
V_33 = F_18 ( V_77 -> V_85 ) ;
V_33 |= V_35 ;
F_4 ( V_33 , V_2 -> V_29 + V_37 ) ;
V_81 = F_19
( & V_2 -> V_39 , V_40 ) ;
if ( V_81 == 0 ) {
F_20 ( & V_75 -> V_84 ) ;
return - V_86 ;
}
if ( V_81 < 0 ) {
F_20 ( & V_75 -> V_84 ) ;
return V_81 ;
}
switch ( V_77 -> type ) {
case V_87 :
* V_78 = V_2 -> V_72 ;
break;
case V_88 :
* V_78 = 25000 - ( ( int ) V_2 -> V_72 - 864 ) * 1000000 / 1840 ;
break;
default:
F_20 ( & V_75 -> V_84 ) ;
return - V_89 ;
}
F_20 ( & V_75 -> V_84 ) ;
return V_90 ;
case V_91 :
* V_78 = V_2 -> V_92 / 1000 ;
* V_79 = V_2 -> V_3 . V_11 ;
return V_93 ;
case V_94 :
* V_78 = V_95 [ V_2 -> V_3 . V_12 ] ;
* V_79 = 0 ;
return V_90 ;
default:
break;
}
return - V_89 ;
}
static int F_21 ( struct V_74 * V_75 ,
struct V_76 const * V_77 ,
int V_78 ,
int V_79 ,
long V_80 )
{
struct V_1 * V_2 = F_15 ( V_75 ) ;
int V_96 ;
switch ( V_80 ) {
case V_94 :
for ( V_96 = 0 ;
V_96 < F_22 ( V_95 ) ;
V_96 ++ )
if ( V_78 == V_95 [ V_96 ] ) {
V_2 -> V_3 . V_12 = V_96 ;
F_9 ( V_2 ) ;
return 0 ;
}
break;
default:
break;
}
return - V_89 ;
}
static int F_23 ( struct V_74 * V_75 ,
unsigned V_97 , unsigned V_98 ,
unsigned * V_99 )
{
struct V_1 * V_2 = F_15 ( V_75 ) ;
if ( ( V_99 == NULL ) ||
( ! ( V_97 % 4 ) || ( V_97 > V_100 ) ) )
return - V_89 ;
* V_99 = F_6 ( V_2 -> V_29 + V_97 ) ;
return 0 ;
}
static int F_24 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_103 * V_104 ;
int V_67 ;
int V_81 ;
V_75 = F_25 ( & V_102 -> V_27 , sizeof( struct V_1 ) ) ;
if ( ! V_75 ) {
F_3 ( & V_102 -> V_27 , L_7 ) ;
return - V_105 ;
}
V_2 = F_15 ( V_75 ) ;
V_2 -> V_27 = & V_102 -> V_27 ;
V_104 = F_26 ( V_102 , V_106 , 0 ) ;
V_2 -> V_29 = F_27 ( & V_102 -> V_27 , V_104 ) ;
if ( F_28 ( V_2 -> V_29 ) )
return F_29 ( V_2 -> V_29 ) ;
V_67 = F_30 ( V_102 , 0 ) ;
if ( V_67 < 0 ) {
F_3 ( & V_102 -> V_27 , L_8 ) ;
return V_67 ;
}
V_81 = F_31 ( V_2 -> V_27 , V_67 ,
F_12 , 0 ,
F_32 ( & V_102 -> V_27 ) , V_2 ) ;
if ( V_81 < 0 ) {
F_3 ( & V_102 -> V_27 , L_9 , V_67 ) ;
return V_81 ;
}
V_2 -> V_107 = F_33 ( & V_102 -> V_27 , L_10 ) ;
if ( F_28 ( V_2 -> V_107 ) ) {
F_3 ( & V_102 -> V_27 , L_11 ,
F_29 ( V_2 -> V_107 ) ) ;
return F_29 ( V_2 -> V_107 ) ;
}
V_2 -> V_108 = F_34 ( & V_102 -> V_27 , L_12 ) ;
if ( F_28 ( V_2 -> V_108 ) )
return F_29 ( V_2 -> V_108 ) ;
V_81 = F_35 ( V_2 -> V_108 ) ;
if ( V_81 )
return V_81 ;
V_2 -> V_92 = F_36 ( V_2 -> V_108 ) ;
F_37 ( V_102 , V_75 ) ;
F_38 ( & V_2 -> V_39 ) ;
V_75 -> V_109 = F_32 ( & V_102 -> V_27 ) ;
V_75 -> V_27 . V_110 = & V_102 -> V_27 ;
V_75 -> V_27 . V_111 = V_102 -> V_27 . V_111 ;
V_75 -> V_2 = & V_112 ;
V_75 -> V_113 = V_114 ;
V_75 -> V_115 = V_116 ;
V_75 -> V_117 = F_22 ( V_116 ) ;
V_81 = F_39 ( V_2 -> V_107 ) ;
if ( V_81 ) {
F_3 ( & V_102 -> V_27 ,
L_13 ) ;
goto V_118;
}
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
V_81 = F_40 ( V_75 ) ;
if ( V_81 ) {
F_3 ( & V_102 -> V_27 , L_14 ) ;
goto V_119;
}
return 0 ;
V_119:
F_41 ( V_2 -> V_107 ) ;
V_118:
F_42 ( V_2 -> V_108 ) ;
return V_81 ;
}
static int F_43 ( struct V_101 * V_102 )
{
struct V_74 * V_75 = F_44 ( V_102 ) ;
struct V_1 * V_2 = F_15 ( V_75 ) ;
F_45 ( V_75 ) ;
F_42 ( V_2 -> V_108 ) ;
F_41 ( V_2 -> V_107 ) ;
return 0 ;
}
static int F_46 ( struct V_120 * V_27 )
{
struct V_74 * V_75 = F_47 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_75 ) ;
int V_33 ;
V_33 = F_6 ( V_2 -> V_29 + V_37 ) ;
V_33 |= V_36 ;
F_4 ( V_33 , V_2 -> V_29 + V_37 ) ;
F_41 ( V_2 -> V_107 ) ;
F_42 ( V_2 -> V_108 ) ;
return 0 ;
}
static int F_48 ( struct V_120 * V_27 )
{
struct V_74 * V_75 = F_47 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_75 ) ;
int V_81 ;
V_81 = F_35 ( V_2 -> V_108 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_39 ( V_2 -> V_107 ) ;
if ( V_81 )
goto V_121;
F_10 ( V_2 ) ;
return 0 ;
V_121:
F_42 ( V_2 -> V_108 ) ;
return V_81 ;
}
