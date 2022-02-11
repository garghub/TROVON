static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_6 ,
V_7 ,
V_7 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_9 ,
V_10 |
V_11 ,
0 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_2 , V_3 ) ;
return V_3 ;
}
F_4 ( 100 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_6 ,
V_7 , 0 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
return V_3 ;
}
static T_1 F_5 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_6 ( & V_2 -> V_14 ) ;
return V_15 ;
}
static T_1 F_7 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_8 ( V_2 -> V_8 , L_3 , V_12 ) ;
F_1 ( V_2 ) ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
bool V_16 )
{
int V_3 ;
if ( ! V_16 )
V_3 = F_2 ( V_2 -> V_4 , V_17 ,
V_18 ,
V_19 , 0 ) ;
else
V_3 = F_2 ( V_2 -> V_4 , V_17 ,
V_18 ,
V_19 ,
V_19 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_8 , L_4 , V_3 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 , int V_20 ,
int V_21 )
{
unsigned int V_16 , V_22 ;
int V_3 ;
if ( V_21 ) {
V_22 = ( V_2 -> V_23
<< V_24 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_25 ,
V_26 , V_22 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_5 , V_3 ) ;
return V_3 ;
}
V_16 = ( V_27 |
V_28 |
V_7 ) ;
V_22 = ( V_2 -> V_29
<< V_30 ) ;
V_22 |= ( V_2 -> V_31
<< V_32 ) ;
V_22 |= V_7 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_16 , V_22 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_6 , V_3 ) ;
return V_3 ;
}
V_16 = ( V_33 |
V_34 ) ;
V_22 = ( V_20 | V_34 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_35 , V_16 , V_22 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_7 , V_3 ) ;
return V_3 ;
}
} else {
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_35 , 0 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_8 , L_8 , V_3 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_6 ,
V_7 , 0 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_9 , V_3 ) ;
return V_3 ;
}
}
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 , int V_20 )
{
int V_3 ;
V_3 = F_10 ( V_2 , V_20 , true ) ;
if ( V_3 < 0 )
return V_3 ;
return F_9 ( V_2 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_20 )
{
F_9 ( V_2 , 1 ) ;
F_10 ( V_2 , V_20 , false ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_20 )
{
int V_36 ;
int V_37 ;
int V_38 ;
int V_3 ;
int V_39 ;
int V_40 = V_2 -> V_41 [ V_20 ] . V_40 ;
int V_42 = V_2 -> V_41 [ V_20 ] . V_42 ;
int V_43 = V_2 -> V_41 [ V_20 ] . V_43 ;
int V_44 = V_2 -> V_41 [ V_20 ] . V_44 ;
V_3 = F_15 ( V_2 -> V_4 , V_45 ,
V_2 -> V_41 [ V_20 ] . V_46 , & V_37 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_10 , V_3 ) ;
goto V_47;
}
V_3 = F_15 ( V_2 -> V_4 , V_45 ,
V_2 -> V_41 [ V_20 ] . V_48 , & V_38 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_10 , V_3 ) ;
goto V_47;
}
V_36 = ( 1000 + ( 1000 * ( V_38 - V_37 ) ) / ( V_42 - V_40 ) ) ;
V_39 = ( ( V_44 - V_43 ) * 1000 ) / ( V_42 - V_40 ) ;
V_2 -> V_41 [ V_20 ] . V_49 = V_36 ;
V_2 -> V_41 [ V_20 ] . V_39 = V_39 ;
V_2 -> V_41 [ V_20 ] . V_50 = ( V_37 * 1000 ) - ( ( V_36 - 1000 ) * V_40 ) ;
V_47:
return V_3 ;
}
static int F_16 ( struct V_1 * V_2 , int V_20 )
{
unsigned int V_22 ;
int V_3 ;
F_17 ( & V_2 -> V_14 ) ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_35 ,
V_51 ,
V_51 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_11 , V_3 ) ;
return V_3 ;
}
V_3 = F_18 ( & V_2 -> V_14 ,
V_52 ) ;
if ( V_3 == 0 ) {
F_3 ( V_2 -> V_8 , L_12 ) ;
return - V_53 ;
}
V_3 = F_19 ( V_2 -> V_4 , V_5 ,
V_54 , & V_22 , 2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_13 , V_3 ) ;
return V_3 ;
}
V_3 = V_22 & 0xFFF ;
return V_3 ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_20 , int V_22 )
{
if ( ! V_2 -> V_41 [ V_20 ] . V_55 )
V_22 = ( V_22 * 1000 - V_2 -> V_41 [ V_20 ] . V_50 ) /
V_2 -> V_41 [ V_20 ] . V_49 ;
if ( V_22 < 0 ) {
F_3 ( V_2 -> V_8 , L_14 ) ;
return 0 ;
}
V_22 = ( V_22 * V_2 -> V_41 [ V_20 ] . V_39 ) / 1000 ;
return V_22 ;
}
static int F_21 ( struct V_56 * V_57 ,
struct V_58 const * V_59 , int * V_22 , int * V_60 , long V_16 )
{
struct V_1 * V_2 = F_22 ( V_57 ) ;
int V_20 = V_59 -> V_61 ;
int V_3 = 0 ;
if ( V_20 > V_62 )
return - V_63 ;
F_23 ( & V_57 -> V_64 ) ;
switch ( V_16 ) {
case V_65 :
case V_66 :
V_3 = F_12 ( V_2 , V_20 ) ;
if ( V_3 < 0 )
goto V_67;
V_3 = F_16 ( V_2 , V_20 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_15 ) ;
goto V_67;
}
if ( V_16 == V_66 )
V_3 = F_20 (
V_2 , V_20 , V_3 ) ;
* V_22 = V_3 ;
V_3 = V_68 ;
goto V_67;
}
F_24 ( & V_57 -> V_64 ) ;
return V_3 ;
V_67:
F_13 ( V_2 , V_20 ) ;
F_24 ( & V_57 -> V_64 ) ;
return V_3 ;
}
static int F_25 ( struct V_69 * V_70 ,
struct V_71 * * V_72 )
{
struct V_73 * V_74 = V_70 -> V_8 . V_75 ;
struct V_71 * V_76 ;
int V_3 ;
T_2 V_77 ;
V_76 = F_26 ( & V_70 -> V_8 , sizeof( * V_76 ) , V_78 ) ;
if ( ! V_76 )
return - V_79 ;
V_3 = F_27 ( V_74 , L_16 , & V_77 ) ;
if ( ! V_3 )
V_76 -> V_29 = V_77 ;
V_3 = F_27 ( V_74 , L_17 , & V_77 ) ;
if ( ! V_3 )
V_76 -> V_31 = V_77 ;
V_76 -> V_23 = F_28 ( V_74 ,
L_18 ) ;
* V_72 = V_76 ;
return 0 ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_80 * V_81 ;
struct V_71 * V_72 = NULL ;
struct V_56 * V_57 ;
int V_3 , V_82 ;
V_81 = F_30 ( V_70 -> V_8 . V_83 ) ;
if ( V_81 && V_81 -> V_72 )
V_72 = V_81 -> V_72 ;
if ( ! V_72 && V_70 -> V_8 . V_75 ) {
V_3 = F_25 ( V_70 , & V_72 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( ! V_72 )
return - V_63 ;
V_57 = F_31 ( & V_70 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_57 ) {
F_3 ( & V_70 -> V_8 , L_19 ) ;
return - V_79 ;
}
V_2 = F_22 ( V_57 ) ;
V_2 -> V_8 = & V_70 -> V_8 ;
V_2 -> V_4 = F_32 ( V_70 -> V_8 . V_83 ) ;
V_2 -> V_41 = V_84 ;
F_17 ( & V_2 -> V_14 ) ;
F_33 ( & V_70 -> V_8 , V_57 ) ;
V_2 -> V_85 = V_72 -> V_86 ;
V_2 -> V_12 = F_34 ( V_2 -> V_4 , V_87 ) ;
if ( V_2 -> V_12 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_20 , V_2 -> V_12 ) ;
V_3 = V_2 -> V_12 ;
goto V_67;
}
V_3 = F_35 ( V_2 -> V_12 , NULL ,
F_5 ,
V_88 | V_89 , F_36 ( V_2 -> V_8 ) ,
V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_21 , V_2 -> V_12 , V_3 ) ;
goto V_67;
}
if ( V_72 -> V_90 ) {
memcpy ( & V_2 -> V_91 , V_72 -> V_90 ,
sizeof( V_2 -> V_91 ) ) ;
V_2 -> V_92 = true ;
V_2 -> V_93 = F_37 ( V_70 , 1 ) ;
V_3 = F_35 ( V_2 -> V_93 , NULL ,
F_7 ,
V_88 | V_89 ,
L_22 , V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_23 ,
V_2 -> V_93 , V_3 ) ;
goto V_94;
}
}
if ( V_72 -> V_95 ) {
memcpy ( & V_2 -> V_96 , V_72 -> V_95 ,
sizeof( V_2 -> V_96 ) ) ;
V_2 -> V_97 = true ;
V_2 -> V_98 = F_37 ( V_70 , 2 ) ;
V_3 = F_35 ( V_2 -> V_98 , NULL ,
F_7 ,
V_88 | V_89 ,
L_24 , V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_25 ,
V_2 -> V_98 , V_3 ) ;
goto V_99;
}
}
if ( V_72 -> V_29 <= 1 )
V_2 -> V_29 = V_100 ;
else if ( V_72 -> V_29 <= 5 )
V_2 -> V_29 = V_101 ;
else if ( V_72 -> V_29 <= 15 )
V_2 -> V_29 = V_102 ;
else
V_2 -> V_29 = V_103 ;
if ( V_72 -> V_31 <= 1 )
V_2 -> V_31 = V_104 ;
else if ( V_72 -> V_31 <= 10 )
V_2 -> V_31 = V_105 ;
else if ( V_72 -> V_31 <= 400 )
V_2 -> V_31 = V_106 ;
else
V_2 -> V_31 = V_107 ;
V_2 -> V_23 = V_72 -> V_23 ;
V_57 -> V_108 = V_109 ;
V_57 -> V_8 . V_83 = & V_70 -> V_8 ;
V_57 -> V_110 = & V_111 ;
V_57 -> V_112 = V_113 ;
V_57 -> V_114 = V_115 ;
V_57 -> V_116 = F_38 ( V_115 ) ;
V_3 = F_39 ( V_57 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_26 , V_3 ) ;
goto V_117;
}
F_40 ( & V_70 -> V_8 , 1 ) ;
for ( V_82 = 0 ; V_82 < V_62 ; V_82 ++ ) {
if ( ! ( V_2 -> V_41 [ V_82 ] . V_55 ) )
F_14 ( V_2 , V_82 ) ;
}
if ( V_2 -> V_92 || V_2 -> V_97 )
F_41 ( & V_70 -> V_8 ) ;
return 0 ;
V_117:
if ( V_72 -> V_95 )
F_42 ( V_2 -> V_98 , V_2 ) ;
V_99:
if ( V_72 -> V_90 )
F_42 ( V_2 -> V_93 , V_2 ) ;
V_94:
F_42 ( V_2 -> V_12 , V_2 ) ;
V_67:
return V_3 ;
}
static int F_43 ( struct V_69 * V_70 )
{
struct V_56 * V_57 = F_44 ( & V_70 -> V_8 ) ;
struct V_1 * V_2 = F_22 ( V_57 ) ;
if ( V_2 -> V_92 || V_2 -> V_97 )
F_45 ( & V_70 -> V_8 ) ;
F_46 ( V_57 ) ;
F_42 ( V_2 -> V_12 , V_2 ) ;
if ( V_2 -> V_92 )
F_42 ( V_2 -> V_93 , V_2 ) ;
if ( V_2 -> V_97 )
F_42 ( V_2 -> V_98 , V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_118 , V_119 ;
int V_82 ;
int V_120 = 0 , V_121 = 0 ;
int V_122 ;
int V_3 ;
V_118 = V_2 -> V_85 ;
for ( V_82 = 0 ; V_82 < 16 ; ++ V_82 ) {
if ( ( ( 1000 * ( 1 << V_82 ) ) / 32 ) < V_118 )
continue;
}
if ( V_82 > 0 )
V_82 -- ;
V_118 = V_82 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_9 ,
V_123 ,
V_118 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_27 , V_3 ) ;
return V_3 ;
}
V_119 = 0 ;
if ( V_2 -> V_92 ) {
int V_124 ;
V_120 = V_2 -> V_91 . V_125 ;
V_119 |= V_126 ;
if ( V_2 -> V_91 . V_127 > 0 ) {
V_122 = V_2 -> V_91 . V_127 ;
V_124 = 0 ;
} else {
V_122 = V_2 -> V_91 . V_128 ;
V_124 = V_129 ;
}
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_130 , V_122 & 0xFF ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_28 , V_3 ) ;
return V_3 ;
}
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_131 ,
( ( V_122 >> 8 ) & 0xF ) | V_124 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_29 , V_3 ) ;
return V_3 ;
}
}
if ( V_2 -> V_97 ) {
int V_124 ;
V_121 = V_2 -> V_96 . V_125 ;
V_119 |= V_132 ;
if ( V_2 -> V_96 . V_127 > 0 ) {
V_122 = V_2 -> V_96 . V_127 ;
V_124 = 0 ;
} else {
V_122 = V_2 -> V_96 . V_128 ;
V_124 = V_133 ;
}
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_134 , V_122 & 0xFF ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_30 , V_3 ) ;
return V_3 ;
}
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_135 ,
( ( V_122 >> 8 ) & 0xF ) | V_124 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 ,
L_31 , V_3 ) ;
return V_3 ;
}
}
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_136 , ( V_121 << 4 ) | V_120 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_32 , V_3 ) ;
return V_3 ;
}
V_3 = F_2 ( V_2 -> V_4 , V_5 ,
V_9 ,
V_132 |
V_126 , V_119 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_8 , L_27 , V_3 ) ;
return V_3 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_11 ( V_2 -> V_4 , V_5 ,
V_136 , 0 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_8 , L_32 , V_3 ) ;
return V_3 ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_8 , L_33 , V_3 ) ;
return V_3 ;
}
static int F_49 ( struct V_137 * V_8 )
{
struct V_56 * V_57 = F_44 ( V_8 ) ;
struct V_1 * V_2 = F_22 ( V_57 ) ;
int V_138 = V_2 -> V_92 || V_2 -> V_97 ;
int V_3 ;
if ( ! F_50 ( V_8 ) || ! V_138 )
return 0 ;
V_3 = F_47 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_92 )
F_51 ( V_2 -> V_93 ) ;
if ( V_2 -> V_97 )
F_51 ( V_2 -> V_98 ) ;
return 0 ;
}
static int F_52 ( struct V_137 * V_8 )
{
struct V_56 * V_57 = F_44 ( V_8 ) ;
struct V_1 * V_2 = F_22 ( V_57 ) ;
int V_138 = V_2 -> V_92 || V_2 -> V_97 ;
int V_3 ;
if ( ! F_50 ( V_8 ) || ! V_138 )
return 0 ;
V_3 = F_48 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_92 )
F_53 ( V_2 -> V_93 ) ;
if ( V_2 -> V_97 )
F_53 ( V_2 -> V_98 ) ;
return 0 ;
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_139 ) ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_139 ) ;
}
