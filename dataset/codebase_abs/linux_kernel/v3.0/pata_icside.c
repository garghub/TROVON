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
F_10 ( V_19 , V_29 , L_1 ,
V_23 . V_27 , V_23 . V_28 , V_23 . V_24 , V_25 ) ;
V_5 -> V_10 [ V_17 -> V_30 ] . V_31 [ V_19 -> V_32 ] = V_24 ;
}
static void F_11 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = V_34 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
unsigned int V_35 = V_34 -> V_36 . V_37 & V_38 ;
F_12 ( F_13 ( V_5 -> V_39 ) ) ;
F_2 ( V_5 -> V_10 [ V_17 -> V_30 ] . V_40 , V_5 -> V_41 ) ;
F_14 ( V_5 -> V_39 , V_5 -> V_10 [ V_17 -> V_30 ] . V_31 [ V_34 -> V_42 -> V_32 ] ) ;
F_15 ( V_5 -> V_39 , V_34 -> V_43 , V_34 -> V_44 ) ;
F_16 ( V_5 -> V_39 , V_35 ? V_45 : V_46 ) ;
V_17 -> V_47 -> V_48 ( V_17 , & V_34 -> V_36 ) ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = V_34 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
F_12 ( F_13 ( V_5 -> V_39 ) ) ;
F_18 ( V_5 -> V_39 ) ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = V_34 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
F_20 ( V_5 -> V_39 ) ;
F_21 ( V_17 ) ;
}
static T_2 F_22 ( struct V_16 * V_17 )
{
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
void T_1 * V_7 ;
V_7 = V_5 -> V_7 + ( V_17 -> V_30 ? V_15 :
V_14 ) ;
return F_4 ( V_7 ) & 1 ? V_49 : 0 ;
}
static int F_23 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = V_51 -> V_5 ;
struct V_1 * V_2 = V_51 -> V_2 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_5 -> V_10 [ 0 ] . V_31 [ V_52 ] = 480 ;
V_5 -> V_10 [ 1 ] . V_31 [ V_52 ] = 480 ;
}
if ( V_2 -> V_39 != V_54 && ! F_24 ( V_2 -> V_39 , V_55 ) ) {
V_5 -> V_39 = V_2 -> V_39 ;
V_51 -> V_56 = V_57 ;
}
return 0 ;
}
static void F_25 ( struct V_58 * V_59 , unsigned int * V_60 )
{
struct V_16 * V_17 = V_59 -> V_17 ;
struct V_4 * V_5 = V_17 -> V_20 -> V_21 ;
if ( V_60 [ 0 ] != V_61 || V_60 [ 1 ] != V_61 )
return F_26 ( V_59 , V_60 ) ;
V_5 -> V_10 [ V_17 -> V_30 ] . V_11 = 1 ;
if ( V_5 -> type == V_62 ) {
void T_1 * V_7 = V_5 -> V_7 +
( V_17 -> V_30 ? V_13 : V_12 ) ;
F_4 ( V_7 ) ;
}
}
static void T_3
F_27 ( struct V_16 * V_17 , void T_1 * V_9 ,
struct V_50 * V_51 ,
const struct V_63 * V_10 )
{
struct V_64 * V_65 = & V_17 -> V_65 ;
void T_1 * V_66 = V_9 + V_10 -> V_67 ;
V_65 -> V_68 = V_66 ;
V_65 -> V_69 = V_66 + ( V_70 << V_10 -> V_71 ) ;
V_65 -> V_72 = V_66 + ( V_73 << V_10 -> V_71 ) ;
V_65 -> V_74 = V_66 + ( V_75 << V_10 -> V_71 ) ;
V_65 -> V_76 = V_66 + ( V_77 << V_10 -> V_71 ) ;
V_65 -> V_78 = V_66 + ( V_79 << V_10 -> V_71 ) ;
V_65 -> V_80 = V_66 + ( V_81 << V_10 -> V_71 ) ;
V_65 -> V_82 = V_66 + ( V_83 << V_10 -> V_71 ) ;
V_65 -> V_84 = V_66 + ( V_85 << V_10 -> V_71 ) ;
V_65 -> V_86 = V_66 + ( V_87 << V_10 -> V_71 ) ;
V_65 -> V_88 = V_66 + ( V_89 << V_10 -> V_71 ) ;
V_65 -> V_90 = V_9 + V_10 -> V_91 ;
V_65 -> V_92 = V_65 -> V_90 ;
F_28 ( V_17 , L_2 ,
V_51 -> V_93 + V_10 -> V_67 ,
V_51 -> V_93 + V_10 -> V_91 ) ;
if ( V_51 -> V_94 )
F_28 ( V_17 , L_3 , V_51 -> V_94 ) ;
}
static int T_3 F_29 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = V_51 -> V_5 ;
void T_1 * V_9 ;
V_9 = F_30 ( V_51 -> V_2 , V_95 , 0 , 0 ) ;
if ( ! V_9 )
return - V_96 ;
V_5 -> V_7 = V_9 ;
V_51 -> V_9 = V_9 ;
V_51 -> V_97 = V_9 + V_98 ;
V_51 -> V_99 = 1 ;
V_51 -> V_100 = & V_101 ;
V_51 -> V_102 = 1 ;
V_51 -> V_10 [ 0 ] = & V_103 ;
V_51 -> V_93 = F_31 ( V_51 -> V_2 , V_95 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_50 * V_51 )
{
struct V_4 * V_5 = V_51 -> V_5 ;
struct V_1 * V_2 = V_51 -> V_2 ;
void T_1 * V_41 , * V_104 ;
unsigned int V_105 = 0 ;
V_41 = F_30 ( V_2 , V_106 , 0 , 0 ) ;
if ( ! V_41 )
return - V_96 ;
V_104 = V_41 ;
if ( F_33 ( V_2 , V_107 ) ) {
V_104 = F_30 ( V_2 , V_107 , 0 , 0 ) ;
if ( ! V_104 )
return - V_96 ;
V_105 = 1 << 5 ;
}
F_2 ( V_105 , V_41 ) ;
V_5 -> V_7 = V_104 ;
V_5 -> V_41 = V_41 ;
V_5 -> V_10 [ 0 ] . V_40 = V_105 ;
V_5 -> V_10 [ 1 ] . V_40 = V_105 | 1 ;
V_51 -> V_9 = V_104 ;
V_51 -> V_100 = & V_108 ;
V_51 -> V_102 = 2 ;
V_51 -> V_10 [ 0 ] = & V_109 ;
V_51 -> V_10 [ 1 ] = & V_110 ;
V_51 -> V_93 = F_31 ( V_2 , V_107 ) ;
V_51 -> V_94 = F_31 ( V_2 , V_106 ) ;
return F_23 ( V_51 ) ;
}
static int T_3 F_34 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_111 * V_20 ;
int V_52 ;
if ( V_51 -> V_97 ) {
V_2 -> V_97 = V_51 -> V_97 ;
V_2 -> V_99 = V_51 -> V_99 ;
}
if ( V_51 -> V_100 )
F_35 ( V_2 , V_51 -> V_100 , V_51 -> V_5 ) ;
V_2 -> V_47 -> V_112 ( V_2 , V_2 -> V_113 ) ;
V_20 = F_36 ( & V_2 -> V_42 , V_51 -> V_102 ) ;
if ( ! V_20 )
return - V_96 ;
V_20 -> V_21 = V_51 -> V_5 ;
V_20 -> V_37 = V_114 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_102 ; V_52 ++ ) {
struct V_16 * V_17 = V_20 -> V_115 [ V_52 ] ;
V_17 -> V_116 = V_117 ;
V_17 -> V_56 = V_51 -> V_56 ;
V_17 -> V_37 |= V_118 ;
V_17 -> V_47 = & V_119 ;
F_27 ( V_17 , V_51 -> V_9 , V_51 , V_51 -> V_10 [ V_52 ] ) ;
}
return F_37 ( V_20 , V_2 -> V_113 , V_120 , 0 ,
& V_121 ) ;
}
static int T_3
F_38 ( struct V_1 * V_2 , const struct V_122 * V_123 )
{
struct V_4 * V_5 ;
struct V_50 V_51 ;
void T_1 * V_124 ;
int V_125 ;
V_125 = F_39 ( V_2 ) ;
if ( V_125 )
goto V_126;
V_5 = F_40 ( & V_2 -> V_42 , sizeof( * V_5 ) , V_127 ) ;
if ( ! V_5 ) {
V_125 = - V_96 ;
goto V_128;
}
V_5 -> type = V_129 ;
V_5 -> V_39 = V_54 ;
V_124 = F_30 ( V_2 , V_106 , 0 , 0 ) ;
if ( V_124 ) {
unsigned int type ;
type = F_4 ( V_124 + V_130 ) & 1 ;
type |= ( F_4 ( V_124 + V_130 + 4 ) & 1 ) << 1 ;
type |= ( F_4 ( V_124 + V_130 + 8 ) & 1 ) << 2 ;
type |= ( F_4 ( V_124 + V_130 + 12 ) & 1 ) << 3 ;
F_41 ( V_2 , V_124 ) ;
V_5 -> type = type ;
}
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_5 = V_5 ;
V_51 . V_2 = V_2 ;
switch ( V_5 -> type ) {
case V_131 :
F_42 ( & V_2 -> V_42 , L_4 ) ;
V_125 = - V_132 ;
break;
case V_133 :
F_42 ( & V_2 -> V_42 , L_5 ) ;
V_125 = - V_132 ;
break;
case V_134 :
V_125 = F_29 ( & V_51 ) ;
break;
case V_62 :
V_125 = F_32 ( & V_51 ) ;
break;
default:
F_42 ( & V_2 -> V_42 , L_6 ) ;
V_125 = - V_132 ;
break;
}
if ( V_125 == 0 )
V_125 = F_34 ( & V_51 ) ;
if ( V_125 == 0 )
goto V_126;
V_128:
F_43 ( V_2 ) ;
V_126:
return V_125 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_111 * V_20 = F_45 ( V_2 ) ;
unsigned long V_37 ;
F_46 ( V_37 ) ;
V_2 -> V_47 -> V_112 ( V_2 , V_2 -> V_113 ) ;
F_47 ( V_37 ) ;
if ( V_20 ) {
struct V_4 * V_5 = V_20 -> V_21 ;
if ( V_5 -> V_41 )
F_2 ( 0 , V_5 -> V_41 ) ;
}
}
static void T_4 F_48 ( struct V_1 * V_2 )
{
struct V_111 * V_20 = F_45 ( V_2 ) ;
struct V_4 * V_5 = V_20 -> V_21 ;
F_49 ( V_20 ) ;
F_44 ( V_2 ) ;
if ( V_5 -> V_39 != V_54 )
F_50 ( V_5 -> V_39 ) ;
F_43 ( V_2 ) ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_135 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_135 ) ;
}
