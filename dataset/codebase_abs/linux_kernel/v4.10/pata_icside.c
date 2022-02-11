static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( 0 , V_5 -> V_7 + V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_4 ( V_5 -> V_7 + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_9 = V_5 -> V_7 ;
if ( ! V_5 -> V_10 [ 0 ] . V_11 )
F_2 ( 0 , V_9 + V_12 ) ;
if ( ! V_5 -> V_10 [ 1 ] . V_11 )
F_2 ( 0 , V_9 + V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_4 ( V_5 -> V_7 + V_12 ) ;
F_4 ( V_5 -> V_7 + V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_4 ( V_5 -> V_7 + V_14 ) & 1 ||
F_4 ( V_5 -> V_7 + V_15 ) & 1 ;
}
static void F_8 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
struct V_22 V_23 ;
unsigned int V_24 ;
char V_25 ;
if ( F_9 ( V_19 , V_19 -> V_26 , & V_23 , 1000 , 1 ) )
return;
if ( V_23 . V_27 <= 50 && V_23 . V_28 <= 375 && V_23 . V_24 <= 425 )
V_25 = 'D' , V_24 = 187 ;
else if ( V_23 . V_27 <= 125 && V_23 . V_28 <= 375 && V_23 . V_24 <= 500 )
V_25 = 'C' , V_24 = 250 ;
else if ( V_23 . V_27 <= 200 && V_23 . V_28 <= 550 && V_23 . V_24 <= 750 )
V_25 = 'B' , V_24 = 437 ;
else
V_25 = 'A' , V_24 = 562 ;
F_10 ( V_19 , L_1 ,
V_23 . V_27 , V_23 . V_28 , V_23 . V_24 , V_25 ) ;
V_5 -> V_10 [ V_17 -> V_29 ] . V_30 [ V_19 -> V_31 ] = V_24 ;
}
static void F_11 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
unsigned int V_34 = V_33 -> V_35 . V_36 & V_37 ;
F_12 ( F_13 ( V_5 -> V_38 ) ) ;
F_2 ( V_5 -> V_10 [ V_17 -> V_29 ] . V_39 , V_5 -> V_40 ) ;
F_14 ( V_5 -> V_38 , V_5 -> V_10 [ V_17 -> V_29 ] . V_30 [ V_33 -> V_41 -> V_31 ] ) ;
F_15 ( V_5 -> V_38 , V_33 -> V_42 , V_33 -> V_43 ) ;
F_16 ( V_5 -> V_38 , V_34 ? V_44 : V_45 ) ;
V_17 -> V_46 -> V_47 ( V_17 , & V_33 -> V_35 ) ;
}
static void F_17 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
F_12 ( F_13 ( V_5 -> V_38 ) ) ;
F_18 ( V_5 -> V_38 ) ;
}
static void F_19 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = V_33 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
F_20 ( V_5 -> V_38 ) ;
F_21 ( V_17 ) ;
}
static T_2 F_22 ( struct V_16 * V_17 )
{
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
void T_1 * V_7 ;
V_7 = V_5 -> V_7 + ( V_17 -> V_29 ? V_15 :
V_14 ) ;
return F_4 ( V_7 ) & 1 ? V_48 : 0 ;
}
static int F_23 ( struct V_49 * V_50 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
struct V_1 * V_2 = V_50 -> V_2 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_5 -> V_10 [ 0 ] . V_30 [ V_51 ] = 480 ;
V_5 -> V_10 [ 1 ] . V_30 [ V_51 ] = 480 ;
}
if ( V_2 -> V_38 != V_53 && ! F_24 ( V_2 -> V_38 , V_54 ) ) {
V_5 -> V_38 = V_2 -> V_38 ;
V_50 -> V_55 = V_56 ;
}
return 0 ;
}
static void F_25 ( struct V_57 * V_58 , unsigned int * V_59 )
{
struct V_16 * V_17 = V_58 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
if ( V_59 [ 0 ] != V_60 || V_59 [ 1 ] != V_60 )
return F_26 ( V_58 , V_59 ) ;
V_5 -> V_10 [ V_17 -> V_29 ] . V_11 = 1 ;
if ( V_5 -> type == V_61 ) {
void T_1 * V_7 = V_5 -> V_7 +
( V_17 -> V_29 ? V_13 : V_12 ) ;
F_4 ( V_7 ) ;
}
}
static void F_27 ( struct V_16 * V_17 , void T_1 * V_9 ,
struct V_49 * V_50 ,
const struct V_62 * V_10 )
{
struct V_63 * V_64 = & V_17 -> V_64 ;
void T_1 * V_65 = V_9 + V_10 -> V_66 ;
V_64 -> V_67 = V_65 ;
V_64 -> V_68 = V_65 + ( V_69 << V_10 -> V_70 ) ;
V_64 -> V_71 = V_65 + ( V_72 << V_10 -> V_70 ) ;
V_64 -> V_73 = V_65 + ( V_74 << V_10 -> V_70 ) ;
V_64 -> V_75 = V_65 + ( V_76 << V_10 -> V_70 ) ;
V_64 -> V_77 = V_65 + ( V_78 << V_10 -> V_70 ) ;
V_64 -> V_79 = V_65 + ( V_80 << V_10 -> V_70 ) ;
V_64 -> V_81 = V_65 + ( V_82 << V_10 -> V_70 ) ;
V_64 -> V_83 = V_65 + ( V_84 << V_10 -> V_70 ) ;
V_64 -> V_85 = V_65 + ( V_86 << V_10 -> V_70 ) ;
V_64 -> V_87 = V_65 + ( V_88 << V_10 -> V_70 ) ;
V_64 -> V_89 = V_9 + V_10 -> V_90 ;
V_64 -> V_91 = V_64 -> V_89 ;
F_28 ( V_17 , L_2 ,
V_50 -> V_92 + V_10 -> V_66 ,
V_50 -> V_92 + V_10 -> V_90 ) ;
if ( V_50 -> V_93 )
F_28 ( V_17 , L_3 , V_50 -> V_93 ) ;
}
static int F_29 ( struct V_49 * V_50 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
void T_1 * V_9 ;
V_9 = F_30 ( V_50 -> V_2 , V_94 , 0 , 0 ) ;
if ( ! V_9 )
return - V_95 ;
V_5 -> V_7 = V_9 ;
V_50 -> V_9 = V_9 ;
V_50 -> V_96 = V_9 + V_97 ;
V_50 -> V_98 = 1 ;
V_50 -> V_99 = & V_100 ;
V_50 -> V_101 = 1 ;
V_50 -> V_10 [ 0 ] = & V_102 ;
V_50 -> V_92 = F_31 ( V_50 -> V_2 , V_94 ) ;
return 0 ;
}
static int F_32 ( struct V_49 * V_50 )
{
struct V_4 * V_5 = V_50 -> V_5 ;
struct V_1 * V_2 = V_50 -> V_2 ;
void T_1 * V_40 , * V_103 ;
unsigned int V_104 = 0 ;
V_40 = F_30 ( V_2 , V_105 , 0 , 0 ) ;
if ( ! V_40 )
return - V_95 ;
V_103 = V_40 ;
if ( F_33 ( V_2 , V_106 ) ) {
V_103 = F_30 ( V_2 , V_106 , 0 , 0 ) ;
if ( ! V_103 )
return - V_95 ;
V_104 = 1 << 5 ;
}
F_2 ( V_104 , V_40 ) ;
V_5 -> V_7 = V_103 ;
V_5 -> V_40 = V_40 ;
V_5 -> V_10 [ 0 ] . V_39 = V_104 ;
V_5 -> V_10 [ 1 ] . V_39 = V_104 | 1 ;
V_50 -> V_9 = V_103 ;
V_50 -> V_99 = & V_107 ;
V_50 -> V_101 = 2 ;
V_50 -> V_10 [ 0 ] = & V_108 ;
V_50 -> V_10 [ 1 ] = & V_109 ;
V_50 -> V_92 = F_31 ( V_2 , V_106 ) ;
V_50 -> V_93 = F_31 ( V_2 , V_105 ) ;
return F_23 ( V_50 ) ;
}
static int F_34 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_110 * V_20 ;
int V_51 ;
if ( V_50 -> V_96 ) {
V_2 -> V_96 = V_50 -> V_96 ;
V_2 -> V_98 = V_50 -> V_98 ;
}
if ( V_50 -> V_99 )
F_35 ( V_2 , V_50 -> V_99 , V_50 -> V_5 ) ;
V_2 -> V_46 -> V_111 ( V_2 , V_2 -> V_112 ) ;
V_20 = F_36 ( & V_2 -> V_41 , V_50 -> V_101 ) ;
if ( ! V_20 )
return - V_95 ;
V_20 -> V_21 = V_50 -> V_5 ;
V_20 -> V_36 = V_113 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_101 ; V_51 ++ ) {
struct V_16 * V_17 = V_20 -> V_114 [ V_51 ] ;
V_17 -> V_115 = V_116 ;
V_17 -> V_55 = V_50 -> V_55 ;
V_17 -> V_36 |= V_117 ;
V_17 -> V_46 = & V_118 ;
F_27 ( V_17 , V_50 -> V_9 , V_50 , V_50 -> V_10 [ V_51 ] ) ;
}
return F_37 ( V_20 , V_2 -> V_112 , V_119 , 0 ,
& V_120 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_121 * V_122 )
{
struct V_4 * V_5 ;
struct V_49 V_50 ;
void T_1 * V_123 ;
int V_124 ;
V_124 = F_39 ( V_2 ) ;
if ( V_124 )
goto V_125;
V_5 = F_40 ( & V_2 -> V_41 , sizeof( * V_5 ) , V_126 ) ;
if ( ! V_5 ) {
V_124 = - V_95 ;
goto V_127;
}
V_5 -> type = V_128 ;
V_5 -> V_38 = V_53 ;
V_123 = F_30 ( V_2 , V_105 , 0 , 0 ) ;
if ( V_123 ) {
unsigned int type ;
type = F_4 ( V_123 + V_129 ) & 1 ;
type |= ( F_4 ( V_123 + V_129 + 4 ) & 1 ) << 1 ;
type |= ( F_4 ( V_123 + V_129 + 8 ) & 1 ) << 2 ;
type |= ( F_4 ( V_123 + V_129 + 12 ) & 1 ) << 3 ;
F_41 ( V_2 , V_123 ) ;
V_5 -> type = type ;
}
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_5 = V_5 ;
V_50 . V_2 = V_2 ;
switch ( V_5 -> type ) {
case V_130 :
F_42 ( & V_2 -> V_41 , L_4 ) ;
V_124 = - V_131 ;
break;
case V_132 :
F_42 ( & V_2 -> V_41 , L_5 ) ;
V_124 = - V_131 ;
break;
case V_133 :
V_124 = F_29 ( & V_50 ) ;
break;
case V_61 :
V_124 = F_32 ( & V_50 ) ;
break;
default:
F_42 ( & V_2 -> V_41 , L_6 ) ;
V_124 = - V_131 ;
break;
}
if ( V_124 == 0 )
V_124 = F_34 ( & V_50 ) ;
if ( V_124 == 0 )
goto V_125;
V_127:
F_43 ( V_2 ) ;
V_125:
return V_124 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_110 * V_20 = F_45 ( V_2 ) ;
unsigned long V_36 ;
F_46 ( V_36 ) ;
V_2 -> V_46 -> V_111 ( V_2 , V_2 -> V_112 ) ;
F_47 ( V_36 ) ;
if ( V_20 ) {
struct V_4 * V_5 = V_20 -> V_21 ;
if ( V_5 -> V_40 )
F_2 ( 0 , V_5 -> V_40 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_110 * V_20 = F_45 ( V_2 ) ;
struct V_4 * V_5 = V_20 -> V_21 ;
F_49 ( V_20 ) ;
F_44 ( V_2 ) ;
if ( V_5 -> V_38 != V_53 )
F_50 ( V_5 -> V_38 ) ;
F_43 ( V_2 ) ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_134 ) ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_134 ) ;
}
