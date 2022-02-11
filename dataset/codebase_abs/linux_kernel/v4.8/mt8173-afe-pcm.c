static int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_4 == V_1 )
return V_3 [ V_2 ] . V_5 ;
return - V_6 ;
}
static int F_3 ( struct V_7 * V_8 , unsigned int V_4 )
{
unsigned int V_9 ;
int V_10 = F_1 ( V_4 ) ;
if ( V_10 < 0 )
return - V_6 ;
F_4 ( V_8 -> V_11 , V_12 , 0x1 , 0x1 ) ;
F_4 ( V_8 -> V_11 , V_13 , 0x1 , 0x1 ) ;
V_9 = V_14 |
F_5 ( V_10 ) |
V_15 ;
F_4 ( V_8 -> V_11 , V_16 , ~ V_17 , V_9 ) ;
V_9 = V_18 |
F_6 ( V_10 ) |
V_19 ;
F_4 ( V_8 -> V_11 , V_20 , ~ V_21 , V_9 ) ;
return 0 ;
}
static void F_7 ( struct V_7 * V_8 , bool V_22 )
{
unsigned int V_9 ;
F_8 ( V_8 -> V_11 , V_16 , & V_9 ) ;
if ( ! ! ( V_9 & V_17 ) == V_22 )
return;
F_4 ( V_8 -> V_11 , V_16 , 0x1 , V_22 ) ;
F_4 ( V_8 -> V_11 , V_20 , 0x1 , V_22 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
struct V_23 * V_24 , struct V_23 * V_25 )
{
int V_26 ;
if ( V_24 ) {
V_26 = F_10 ( V_24 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_1 ) ;
return V_26 ;
}
}
if ( V_25 ) {
V_26 = F_10 ( V_25 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_2 ) ;
return V_26 ;
}
}
return 0 ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_23 * V_24 , unsigned int V_28 ,
struct V_23 * V_25 , unsigned int V_29 )
{
int V_26 ;
if ( V_24 ) {
V_26 = F_13 ( V_24 , V_28 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_3 ) ;
return V_26 ;
}
}
if ( V_25 ) {
V_26 = F_13 ( V_25 , V_29 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_4 ) ;
return V_26 ;
}
}
return 0 ;
}
static void F_14 ( struct V_7 * V_8 ,
struct V_23 * V_24 , struct V_23 * V_25 )
{
if ( V_24 )
F_15 ( V_24 ) ;
if ( V_25 )
F_15 ( V_25 ) ;
}
static int F_16 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
if ( V_33 -> V_38 )
return 0 ;
F_4 ( V_8 -> V_11 , V_39 ,
V_40 | V_41 , 0 ) ;
return 0 ;
}
static void F_18 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
if ( V_33 -> V_38 )
return;
F_7 ( V_8 , false ) ;
F_4 ( V_8 -> V_11 , V_39 ,
V_40 | V_41 ,
V_40 | V_41 ) ;
}
static int F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_42 * const V_43 = V_31 -> V_43 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
struct V_44 * V_45 = V_8 -> V_46 ;
int V_26 ;
F_12 ( V_8 , V_45 -> V_47 [ V_48 ] ,
V_43 -> V_4 * 256 , NULL , 0 ) ;
F_12 ( V_8 , V_45 -> V_47 [ V_49 ] ,
V_43 -> V_4 * 256 , NULL , 0 ) ;
V_26 = F_3 ( V_8 , V_31 -> V_43 -> V_4 ) ;
if ( V_26 )
return V_26 ;
F_7 ( V_8 , true ) ;
return 0 ;
}
static int F_20 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
struct V_44 * V_45 = V_8 -> V_46 ;
if ( V_33 -> V_38 )
return 0 ;
F_9 ( V_8 , V_45 -> V_47 [ V_50 ] ,
V_45 -> V_47 [ V_51 ] ) ;
return 0 ;
}
static void F_21 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
struct V_44 * V_45 = V_8 -> V_46 ;
if ( V_33 -> V_38 )
return;
F_14 ( V_8 , V_45 -> V_47 [ V_50 ] ,
V_45 -> V_47 [ V_51 ] ) ;
}
static int F_22 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_42 * const V_43 = V_31 -> V_43 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
struct V_44 * V_45 = V_8 -> V_46 ;
unsigned int V_9 ;
F_12 ( V_8 , V_45 -> V_47 [ V_50 ] ,
V_43 -> V_4 * 128 ,
V_45 -> V_47 [ V_51 ] ,
V_43 -> V_4 * V_43 -> V_52 * 32 ) ;
V_9 = V_53 |
V_54 |
V_55 |
V_56 |
V_57 |
V_58 |
F_23 ( 32 ) ;
F_4 ( V_8 -> V_11 , V_59 , ~ V_60 , V_9 ) ;
switch ( V_43 -> V_52 ) {
case 1 :
case 2 :
V_9 = V_61 ;
V_9 |= ( V_62 << 4 ) ;
V_9 |= ( V_62 << 8 ) ;
V_9 |= ( V_62 << 12 ) ;
break;
case 3 :
case 4 :
V_9 = V_61 ;
V_9 |= ( V_63 << 4 ) ;
V_9 |= ( V_62 << 8 ) ;
V_9 |= ( V_62 << 12 ) ;
break;
case 5 :
case 6 :
V_9 = V_61 ;
V_9 |= ( V_63 << 4 ) ;
V_9 |= ( V_64 << 8 ) ;
V_9 |= ( V_62 << 12 ) ;
break;
case 7 :
case 8 :
V_9 = V_61 ;
V_9 |= ( V_63 << 4 ) ;
V_9 |= ( V_64 << 8 ) ;
V_9 |= ( V_65 << 12 ) ;
break;
default:
V_9 = 0 ;
}
F_4 ( V_8 -> V_11 , V_66 , 0x0000ffff , V_9 ) ;
F_4 ( V_8 -> V_11 , V_67 ,
0x000000f0 , V_43 -> V_52 << 4 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_31 , int V_68 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
F_25 ( V_8 -> V_27 , L_5 , V_69 , V_68 , V_33 -> V_70 ) ;
switch ( V_68 ) {
case V_71 :
case V_72 :
F_4 ( V_8 -> V_11 , V_39 ,
V_73 | V_74 , 0 ) ;
F_26 ( V_8 -> V_11 , V_75 ,
V_76 |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 |
V_82 |
V_83 ) ;
F_4 ( V_8 -> V_11 , V_67 , 0x1 , 0x1 ) ;
F_4 ( V_8 -> V_11 , V_59 , 0x1 , 0x1 ) ;
return 0 ;
case V_84 :
case V_85 :
F_4 ( V_8 -> V_11 , V_59 , 0x1 , 0 ) ;
F_4 ( V_8 -> V_11 , V_67 , 0x1 , 0 ) ;
F_4 ( V_8 -> V_11 , V_39 ,
V_73 | V_74 ,
V_73 | V_74 ) ;
return 0 ;
default:
return - V_6 ;
}
}
static int F_27 ( struct V_30 * V_31 ,
unsigned int V_4 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_7 * V_8 = F_17 ( V_35 -> V_37 ) ;
struct V_86 * V_87 = & V_8 -> V_87 [ V_35 -> V_88 -> V_89 ] ;
int V_10 ;
if ( V_87 -> V_90 -> V_89 == V_91 ||
V_87 -> V_90 -> V_89 == V_92 ) {
switch ( V_4 ) {
case 8000 :
V_10 = 0 ;
break;
case 16000 :
V_10 = 1 ;
break;
case 32000 :
V_10 = 2 ;
break;
default:
return - V_6 ;
}
} else {
V_10 = F_1 ( V_4 ) ;
}
return V_10 ;
}
static int F_28 ( struct V_30 * V_31 , unsigned int V_4 )
{
return F_1 ( V_4 ) ;
}
static T_1 F_29 ( int V_93 , void * V_94 )
{
struct V_7 * V_8 = V_94 ;
unsigned int V_95 ;
int V_2 , V_26 ;
V_26 = F_8 ( V_8 -> V_11 , V_96 , & V_95 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_6 , V_69 ) ;
V_95 = V_97 ;
goto V_98;
}
for ( V_2 = 0 ; V_2 < V_99 ; V_2 ++ ) {
struct V_86 * V_87 = & V_8 -> V_87 [ V_2 ] ;
struct V_100 * V_93 ;
if ( V_87 -> V_101 < 0 )
continue;
V_93 = & V_8 -> V_102 [ V_87 -> V_101 ] ;
if ( ! ( V_95 & ( 1 << V_93 -> V_103 -> V_104 ) ) )
continue;
F_30 ( V_87 -> V_31 ) ;
}
V_98:
F_26 ( V_8 -> V_11 , V_105 ,
V_95 & V_97 ) ;
return V_106 ;
}
static int F_31 ( struct V_107 * V_27 )
{
struct V_7 * V_8 = F_32 ( V_27 ) ;
struct V_44 * V_45 = V_8 -> V_46 ;
F_4 ( V_8 -> V_11 , V_108 , 0x1 , 0 ) ;
F_4 ( V_8 -> V_11 , V_39 ,
V_109 , V_109 ) ;
F_15 ( V_45 -> V_47 [ V_48 ] ) ;
F_15 ( V_45 -> V_47 [ V_49 ] ) ;
F_15 ( V_45 -> V_47 [ V_110 ] ) ;
F_15 ( V_45 -> V_47 [ V_111 ] ) ;
F_15 ( V_45 -> V_47 [ V_112 ] ) ;
F_15 ( V_45 -> V_47 [ V_113 ] ) ;
F_15 ( V_45 -> V_47 [ V_114 ] ) ;
return 0 ;
}
static int F_33 ( struct V_107 * V_27 )
{
struct V_7 * V_8 = F_32 ( V_27 ) ;
struct V_44 * V_45 = V_8 -> V_46 ;
int V_26 ;
V_26 = F_10 ( V_45 -> V_47 [ V_114 ] ) ;
if ( V_26 )
return V_26 ;
V_26 = F_10 ( V_45 -> V_47 [ V_113 ] ) ;
if ( V_26 )
goto V_115;
V_26 = F_10 ( V_45 -> V_47 [ V_112 ] ) ;
if ( V_26 )
goto V_116;
V_26 = F_10 ( V_45 -> V_47 [ V_110 ] ) ;
if ( V_26 )
goto V_117;
V_26 = F_10 ( V_45 -> V_47 [ V_111 ] ) ;
if ( V_26 )
goto V_118;
V_26 = F_10 ( V_45 -> V_47 [ V_48 ] ) ;
if ( V_26 )
goto V_119;
V_26 = F_10 ( V_45 -> V_47 [ V_49 ] ) ;
if ( V_26 )
goto V_120;
F_4 ( V_8 -> V_11 , V_39 , V_109 , 0 ) ;
F_4 ( V_8 -> V_11 , V_121 ,
V_122 | V_123 , 0 ) ;
F_4 ( V_8 -> V_11 , V_124 , 0xff , 0xff ) ;
F_4 ( V_8 -> V_11 , V_108 , 0x1 , 0x1 ) ;
return 0 ;
V_119:
F_15 ( V_45 -> V_47 [ V_48 ] ) ;
V_120:
F_15 ( V_45 -> V_47 [ V_49 ] ) ;
V_118:
F_15 ( V_45 -> V_47 [ V_110 ] ) ;
V_117:
F_15 ( V_45 -> V_47 [ V_112 ] ) ;
V_116:
F_15 ( V_45 -> V_47 [ V_113 ] ) ;
V_115:
F_15 ( V_45 -> V_47 [ V_114 ] ) ;
return V_26 ;
}
static int F_34 ( struct V_7 * V_8 )
{
T_2 V_2 ;
struct V_44 * V_45 = V_8 -> V_46 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_125 ) ; V_2 ++ ) {
V_45 -> V_47 [ V_2 ] = F_35 ( V_8 -> V_27 , V_125 [ V_2 ] ) ;
if ( F_36 ( V_45 -> V_47 [ V_2 ] ) ) {
F_11 ( V_8 -> V_27 , L_7 ,
V_69 , V_125 [ V_2 ] ) ;
return F_37 ( V_45 -> V_47 [ V_2 ] ) ;
}
}
F_13 ( V_45 -> V_47 [ V_110 ] , 22579200 ) ;
F_13 ( V_45 -> V_47 [ V_111 ] , 24576000 ) ;
return 0 ;
}
static int F_38 ( struct V_126 * V_127 )
{
int V_26 , V_2 ;
unsigned int V_128 ;
struct V_7 * V_8 ;
struct V_44 * V_45 ;
struct V_129 * V_130 ;
V_26 = F_39 ( & V_127 -> V_27 , F_40 ( 33 ) ) ;
if ( V_26 )
return V_26 ;
V_8 = F_41 ( & V_127 -> V_27 , sizeof( * V_8 ) , V_131 ) ;
if ( ! V_8 )
return - V_132 ;
V_8 -> V_46 = F_41 ( & V_127 -> V_27 , sizeof( * V_45 ) ,
V_131 ) ;
V_45 = V_8 -> V_46 ;
if ( ! V_45 )
return - V_132 ;
V_8 -> V_27 = & V_127 -> V_27 ;
V_128 = F_42 ( V_127 , 0 ) ;
if ( ! V_128 ) {
F_11 ( V_8 -> V_27 , L_8 , V_8 -> V_27 -> V_133 -> V_70 ) ;
return - V_134 ;
}
V_26 = F_43 ( V_8 -> V_27 , V_128 , F_29 ,
0 , L_9 , ( void * ) V_8 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_10 ) ;
return V_26 ;
}
V_130 = F_44 ( V_127 , V_135 , 0 ) ;
V_8 -> V_136 = F_45 ( & V_127 -> V_27 , V_130 ) ;
if ( F_36 ( V_8 -> V_136 ) )
return F_37 ( V_8 -> V_136 ) ;
V_8 -> V_11 = F_46 ( & V_127 -> V_27 , V_8 -> V_136 ,
& V_137 ) ;
if ( F_36 ( V_8 -> V_11 ) )
return F_37 ( V_8 -> V_11 ) ;
V_26 = F_34 ( V_8 ) ;
if ( V_26 ) {
F_11 ( V_8 -> V_27 , L_11 ) ;
return V_26 ;
}
V_8 -> V_138 = V_99 ;
V_8 -> V_87 = F_47 ( V_8 -> V_27 , V_8 -> V_138 ,
sizeof( * V_8 -> V_87 ) , V_131 ) ;
if ( ! V_8 -> V_87 )
return - V_132 ;
V_8 -> V_139 = V_140 ;
V_8 -> V_102 = F_47 ( V_8 -> V_27 , V_8 -> V_139 ,
sizeof( * V_8 -> V_102 ) , V_131 ) ;
if ( ! V_8 -> V_102 )
return - V_132 ;
for ( V_2 = 0 ; V_2 < V_8 -> V_139 ; V_2 ++ ) {
V_8 -> V_87 [ V_2 ] . V_90 = & V_141 [ V_2 ] ;
V_8 -> V_102 [ V_2 ] . V_103 = & V_103 [ V_2 ] ;
V_8 -> V_102 [ V_2 ] . V_142 = true ;
V_8 -> V_87 [ V_2 ] . V_101 = V_2 ;
V_8 -> V_87 [ V_2 ] . V_143 = 1 ;
}
V_8 -> V_144 = & V_145 ;
V_8 -> V_146 = F_27 ;
V_8 -> V_147 = F_28 ;
F_48 ( V_127 , V_8 ) ;
F_49 ( & V_127 -> V_27 ) ;
if ( ! F_50 ( & V_127 -> V_27 ) ) {
V_26 = F_33 ( & V_127 -> V_27 ) ;
if ( V_26 )
goto V_148;
}
V_8 -> V_149 = V_150 ;
V_8 -> V_151 = F_2 ( V_150 ) ;
V_8 -> V_152 = F_33 ;
V_8 -> V_153 = F_31 ;
V_26 = F_51 ( & V_127 -> V_27 , & V_154 ) ;
if ( V_26 )
goto V_148;
V_26 = F_52 ( & V_127 -> V_27 ,
& V_155 ,
V_156 ,
F_2 ( V_156 ) ) ;
if ( V_26 )
goto V_157;
V_26 = F_52 ( & V_127 -> V_27 ,
& V_158 ,
V_159 ,
F_2 ( V_159 ) ) ;
if ( V_26 )
goto V_160;
F_25 ( & V_127 -> V_27 , L_12 ) ;
return 0 ;
V_160:
F_53 ( & V_127 -> V_27 ) ;
V_157:
F_54 ( & V_127 -> V_27 ) ;
V_148:
F_55 ( & V_127 -> V_27 ) ;
return V_26 ;
}
static int F_56 ( struct V_126 * V_127 )
{
F_55 ( & V_127 -> V_27 ) ;
if ( ! F_57 ( & V_127 -> V_27 ) )
F_31 ( & V_127 -> V_27 ) ;
F_53 ( & V_127 -> V_27 ) ;
F_54 ( & V_127 -> V_27 ) ;
return 0 ;
}
