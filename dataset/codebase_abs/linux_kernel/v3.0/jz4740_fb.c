static unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
switch ( V_1 -> V_3 -> V_4 ) {
case V_5 :
V_2 = 4 ;
break;
case V_6 :
V_2 = 4 ;
break;
case V_7 :
V_2 = 3 ;
break;
case V_8 :
case V_9 :
case V_10 :
V_2 = 8 ;
break;
default:
V_2 = 0 ;
break;
}
return V_2 ;
}
static unsigned int F_2 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
switch ( V_1 -> V_3 -> V_4 ) {
case V_5 :
V_2 = 16 ;
break;
case V_6 :
V_2 = 18 ;
break;
case V_7 :
V_2 = 8 ;
break;
case V_8 :
case V_9 :
case V_10 :
if ( V_1 -> V_3 -> V_11 == 18 )
V_2 = 18 ;
else
V_2 = 16 ;
break;
default:
V_2 = 0 ;
break;
}
return V_2 ;
}
static inline T_1 F_3 ( unsigned V_12 ,
struct V_13 * V_14 )
{
return ( ( ( V_12 << V_14 -> V_15 ) + 0x7FFF - V_12 ) >> 16 ) << V_14 -> V_16 ;
}
static int F_4 ( unsigned V_17 , unsigned V_18 , unsigned V_19 ,
unsigned V_20 , unsigned V_21 , struct V_22 * V_23 )
{
T_1 V_24 ;
if ( V_17 >= 16 )
return - V_25 ;
V_24 = F_3 ( V_18 , & V_23 -> V_26 . V_18 ) ;
V_24 |= F_3 ( V_19 , & V_23 -> V_26 . V_19 ) ;
V_24 |= F_3 ( V_20 , & V_23 -> V_26 . V_20 ) ;
V_24 |= F_3 ( V_21 , & V_23 -> V_26 . V_21 ) ;
( ( T_1 * ) ( V_23 -> V_27 ) ) [ V_17 ] = V_24 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_3 -> V_11 ) {
case 18 :
case 24 :
return 32 ;
case 15 :
return 16 ;
default:
return V_1 -> V_3 -> V_11 ;
}
}
static struct V_28 * F_6 ( struct V_1 * V_1 ,
struct V_29 * V_26 )
{
T_2 V_30 ;
struct V_28 * V_31 = V_1 -> V_3 -> V_32 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_3 -> V_33 ; ++ V_30 , ++ V_31 ) {
if ( V_31 -> V_34 == V_26 -> V_34 && V_31 -> V_35 == V_26 -> V_35 )
return V_31 ;
}
return NULL ;
}
static int F_7 ( struct V_29 * V_26 , struct V_22 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_36 ;
struct V_28 * V_31 ;
if ( V_26 -> V_37 != F_5 ( V_1 ) &&
V_26 -> V_37 != V_1 -> V_3 -> V_11 )
return - V_25 ;
V_31 = F_6 ( V_1 , V_26 ) ;
if ( V_31 == NULL )
return - V_25 ;
F_8 ( V_26 , V_31 ) ;
switch ( V_1 -> V_3 -> V_11 ) {
case 8 :
break;
case 15 :
V_26 -> V_18 . V_16 = 10 ;
V_26 -> V_18 . V_15 = 5 ;
V_26 -> V_19 . V_16 = 6 ;
V_26 -> V_19 . V_15 = 5 ;
V_26 -> V_20 . V_16 = 0 ;
V_26 -> V_20 . V_15 = 5 ;
break;
case 16 :
V_26 -> V_18 . V_16 = 11 ;
V_26 -> V_18 . V_15 = 5 ;
V_26 -> V_19 . V_16 = 5 ;
V_26 -> V_19 . V_15 = 6 ;
V_26 -> V_20 . V_16 = 0 ;
V_26 -> V_20 . V_15 = 5 ;
break;
case 18 :
V_26 -> V_18 . V_16 = 16 ;
V_26 -> V_18 . V_15 = 6 ;
V_26 -> V_19 . V_16 = 8 ;
V_26 -> V_19 . V_15 = 6 ;
V_26 -> V_20 . V_16 = 0 ;
V_26 -> V_20 . V_15 = 6 ;
V_26 -> V_37 = 32 ;
break;
case 32 :
case 24 :
V_26 -> V_21 . V_16 = 24 ;
V_26 -> V_21 . V_15 = 8 ;
V_26 -> V_18 . V_16 = 16 ;
V_26 -> V_18 . V_15 = 8 ;
V_26 -> V_19 . V_16 = 8 ;
V_26 -> V_19 . V_15 = 8 ;
V_26 -> V_20 . V_16 = 0 ;
V_26 -> V_20 . V_15 = 8 ;
V_26 -> V_37 = 32 ;
break;
default:
break;
}
return 0 ;
}
static int F_9 ( struct V_22 * V_38 )
{
struct V_1 * V_1 = V_38 -> V_36 ;
struct V_39 * V_3 = V_1 -> V_3 ;
struct V_29 * V_26 = & V_38 -> V_26 ;
struct V_28 * V_31 ;
T_3 V_40 , V_41 ;
T_3 V_42 , V_43 ;
T_3 V_44 , V_45 ;
T_1 V_46 ;
T_1 V_47 ;
unsigned long V_48 ;
V_31 = F_6 ( V_1 , V_26 ) ;
if ( V_31 == NULL )
return - V_25 ;
if ( V_31 == V_38 -> V_31 )
return 0 ;
V_38 -> V_31 = V_31 ;
V_40 = V_31 -> V_49 + V_31 -> V_50 ;
V_42 = V_40 + V_31 -> V_34 ;
V_44 = V_42 + V_31 -> V_51 ;
V_41 = V_31 -> V_52 + V_31 -> V_53 ;
V_43 = V_41 + V_31 -> V_35 ;
V_45 = V_43 + V_31 -> V_54 ;
V_46 = V_55 | V_56 ;
switch ( V_3 -> V_11 ) {
case 1 :
V_46 |= V_57 ;
break;
case 2 :
V_46 |= V_58 ;
break;
case 4 :
V_46 |= V_59 ;
break;
case 8 :
V_46 |= V_60 ;
break;
case 15 :
V_46 |= V_61 ;
case 16 :
V_46 |= V_62 ;
break;
case 18 :
case 24 :
case 32 :
V_46 |= V_63 ;
break;
default:
break;
}
V_47 = V_3 -> V_4 & 0xf ;
if ( ! ( V_31 -> V_64 & V_65 ) )
V_47 |= V_66 ;
if ( ! ( V_31 -> V_64 & V_67 ) )
V_47 |= V_68 ;
if ( V_3 -> V_69 )
V_47 |= V_70 ;
if ( V_3 -> V_71 )
V_47 |= V_72 ;
if ( V_3 -> V_4 == V_6 )
V_47 |= V_73 ;
if ( V_31 -> V_74 ) {
V_48 = F_10 ( V_31 -> V_74 ) * 1000 ;
V_31 -> V_75 = V_48 / V_45 / V_44 ;
} else {
if ( V_3 -> V_4 == V_7 )
V_48 = V_31 -> V_75 * ( V_45 + 2 * V_31 -> V_34 ) * V_44 ;
else
V_48 = V_31 -> V_75 * V_45 * V_44 ;
V_31 -> V_74 = F_11 ( V_48 / 1000 ) ;
}
F_12 ( & V_1 -> V_76 ) ;
if ( ! V_1 -> V_77 )
F_13 ( V_1 -> V_78 ) ;
else
V_46 |= V_79 ;
switch ( V_3 -> V_4 ) {
case V_8 :
case V_9 :
case V_10 :
F_14 ( V_3 -> V_80 . V_81 , V_1 -> V_82 + V_83 ) ;
F_14 ( V_3 -> V_80 . V_84 , V_1 -> V_82 + V_85 ) ;
F_14 ( V_3 -> V_80 . V_86 , V_1 -> V_82 + V_87 ) ;
F_14 ( V_3 -> V_80 . V_86 , V_1 -> V_82 + V_88 ) ;
break;
default:
V_47 |= V_89 ;
V_47 |= V_90 ;
V_47 |= V_91 ;
V_47 |= V_92 ;
break;
}
F_14 ( V_31 -> V_49 , V_1 -> V_82 + V_93 ) ;
F_14 ( V_31 -> V_52 , V_1 -> V_82 + V_94 ) ;
F_14 ( ( V_44 << 16 ) | V_45 , V_1 -> V_82 + V_95 ) ;
F_14 ( ( V_40 << 16 ) | V_42 , V_1 -> V_82 + V_96 ) ;
F_14 ( ( V_41 << 16 ) | V_43 , V_1 -> V_82 + V_97 ) ;
F_14 ( V_47 , V_1 -> V_82 + V_98 ) ;
F_14 ( V_46 , V_1 -> V_82 + V_99 ) ;
if ( ! V_1 -> V_77 )
F_15 ( V_1 -> V_78 ) ;
F_16 ( & V_1 -> V_76 ) ;
F_17 ( V_1 -> V_100 , V_48 ) ;
F_17 ( V_1 -> V_78 , V_48 * 3 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_1 )
{
T_1 V_46 ;
F_13 ( V_1 -> V_78 ) ;
F_19 ( V_101 , F_1 ( V_1 ) ) ;
F_19 ( V_102 , F_2 ( V_1 ) ) ;
F_14 ( 0 , V_1 -> V_82 + V_103 ) ;
F_14 ( V_1 -> V_104 -> V_105 , V_1 -> V_82 + V_106 ) ;
V_46 = F_20 ( V_1 -> V_82 + V_99 ) ;
V_46 |= V_79 ;
V_46 &= ~ V_107 ;
F_14 ( V_46 , V_1 -> V_82 + V_99 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
T_1 V_46 ;
V_46 = F_20 ( V_1 -> V_82 + V_99 ) ;
V_46 |= V_107 ;
F_14 ( V_46 , V_1 -> V_82 + V_99 ) ;
do {
V_46 = F_20 ( V_1 -> V_82 + V_103 ) ;
} while ( ! ( V_46 & V_108 ) );
F_22 ( V_101 , F_1 ( V_1 ) ) ;
F_22 ( V_102 , F_2 ( V_1 ) ) ;
F_15 ( V_1 -> V_78 ) ;
}
static int F_23 ( int V_109 , struct V_22 * V_38 )
{
struct V_1 * V_1 = V_38 -> V_36 ;
switch ( V_109 ) {
case V_110 :
F_12 ( & V_1 -> V_76 ) ;
if ( V_1 -> V_77 ) {
F_16 ( & V_1 -> V_76 ) ;
return 0 ;
}
F_18 ( V_1 ) ;
V_1 -> V_77 = 1 ;
F_16 ( & V_1 -> V_76 ) ;
break;
default:
F_12 ( & V_1 -> V_76 ) ;
if ( ! V_1 -> V_77 ) {
F_16 ( & V_1 -> V_76 ) ;
return 0 ;
}
F_21 ( V_1 ) ;
V_1 -> V_77 = 0 ;
F_16 ( & V_1 -> V_76 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
int V_111 = 0 ;
struct V_28 * V_31 = V_1 -> V_3 -> V_32 ;
void * V_112 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_3 -> V_33 ; ++ V_31 , ++ V_30 ) {
if ( V_111 < V_31 -> V_34 * V_31 -> V_35 )
V_111 = V_31 -> V_34 * V_31 -> V_35 ;
}
V_111 *= F_5 ( V_1 ) >> 3 ;
V_1 -> V_104 = F_25 ( & V_1 -> V_113 -> V_114 ,
sizeof( * V_1 -> V_104 ) ,
& V_1 -> V_115 , V_116 ) ;
if ( ! V_1 -> V_104 )
return - V_117 ;
V_1 -> V_118 = F_26 ( V_111 ) ;
V_1 -> V_119 = F_25 ( & V_1 -> V_113 -> V_114 ,
V_1 -> V_118 ,
& V_1 -> V_120 , V_116 ) ;
if ( ! V_1 -> V_119 )
goto V_121;
for ( V_112 = V_1 -> V_119 ;
V_112 < V_1 -> V_119 + F_26 ( V_1 -> V_118 ) ;
V_112 += V_122 ) {
F_27 ( F_28 ( V_112 ) ) ;
}
V_1 -> V_104 -> V_105 = V_1 -> V_115 ;
V_1 -> V_104 -> V_123 = V_1 -> V_120 ;
V_1 -> V_104 -> V_124 = 0xdeafbead ;
V_1 -> V_104 -> V_125 = 0 ;
V_1 -> V_104 -> V_125 |= V_111 / 4 ;
return 0 ;
V_121:
F_29 ( & V_1 -> V_113 -> V_114 , sizeof( * V_1 -> V_104 ) ,
V_1 -> V_104 , V_1 -> V_115 ) ;
return - V_117 ;
}
static void F_30 ( struct V_1 * V_1 )
{
F_29 ( & V_1 -> V_113 -> V_114 , V_1 -> V_118 ,
V_1 -> V_119 , V_1 -> V_120 ) ;
F_29 ( & V_1 -> V_113 -> V_114 , sizeof( * V_1 -> V_104 ) ,
V_1 -> V_104 , V_1 -> V_115 ) ;
}
static int T_4 F_31 ( struct V_126 * V_113 )
{
int V_127 ;
struct V_1 * V_1 ;
struct V_22 * V_23 ;
struct V_39 * V_3 = V_113 -> V_114 . V_128 ;
struct V_129 * V_130 ;
if ( ! V_3 ) {
F_32 ( & V_113 -> V_114 , L_1 ) ;
return - V_131 ;
}
V_130 = F_33 ( V_113 , V_132 , 0 ) ;
if ( ! V_130 ) {
F_32 ( & V_113 -> V_114 , L_2 ) ;
return - V_131 ;
}
V_130 = F_34 ( V_130 -> V_133 , F_35 ( V_130 ) , V_113 -> V_134 ) ;
if ( ! V_130 ) {
F_32 ( & V_113 -> V_114 , L_3 ) ;
return - V_135 ;
}
V_23 = F_36 ( sizeof( struct V_1 ) , & V_113 -> V_114 ) ;
if ( ! V_23 ) {
F_32 ( & V_113 -> V_114 , L_4 ) ;
V_127 = - V_117 ;
goto V_136;
}
V_23 -> V_137 = & V_138 ;
V_23 -> V_139 = V_140 ;
V_1 = V_23 -> V_36 ;
V_1 -> V_113 = V_113 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_130 = V_130 ;
V_1 -> V_78 = F_37 ( & V_113 -> V_114 , L_5 ) ;
if ( F_38 ( V_1 -> V_78 ) ) {
V_127 = F_39 ( V_1 -> V_78 ) ;
F_32 ( & V_113 -> V_114 , L_6 , V_127 ) ;
goto V_141;
}
V_1 -> V_100 = F_37 ( & V_113 -> V_114 , L_7 ) ;
if ( F_38 ( V_1 -> V_100 ) ) {
V_127 = F_39 ( V_1 -> V_100 ) ;
F_32 ( & V_113 -> V_114 , L_8 , V_127 ) ;
goto V_142;
}
V_1 -> V_82 = F_40 ( V_130 -> V_133 , F_35 ( V_130 ) ) ;
if ( ! V_1 -> V_82 ) {
F_32 ( & V_113 -> V_114 , L_9 ) ;
V_127 = - V_135 ;
goto V_143;
}
F_41 ( V_113 , V_1 ) ;
F_42 ( & V_1 -> V_76 ) ;
F_43 ( V_3 -> V_32 , V_3 -> V_33 ,
& V_23 -> V_144 ) ;
F_8 ( & V_23 -> V_26 , V_3 -> V_32 ) ;
V_23 -> V_26 . V_37 = V_3 -> V_11 ;
F_7 ( & V_23 -> V_26 , V_23 ) ;
V_127 = F_24 ( V_1 ) ;
if ( V_127 ) {
F_32 ( & V_113 -> V_114 , L_10 ) ;
goto V_145;
}
V_23 -> V_146 = V_147 ;
V_23 -> V_146 . V_148 = V_23 -> V_26 . V_37 * V_23 -> V_26 . V_34 / 8 ;
V_23 -> V_146 . V_149 = V_130 -> V_133 ;
V_23 -> V_146 . V_150 = F_35 ( V_130 ) ;
V_23 -> V_146 . V_151 = V_1 -> V_120 ;
V_23 -> V_146 . V_152 = V_23 -> V_146 . V_148 * V_23 -> V_26 . V_35 ;
V_23 -> V_153 = V_1 -> V_119 ;
V_23 -> V_27 = V_1 -> V_27 ;
F_44 ( & V_23 -> V_154 , 256 , 0 ) ;
F_13 ( V_1 -> V_78 ) ;
V_1 -> V_77 = 1 ;
F_14 ( V_1 -> V_104 -> V_105 , V_1 -> V_82 + V_106 ) ;
V_23 -> V_31 = NULL ;
F_9 ( V_23 ) ;
F_45 ( V_101 , F_1 ( V_1 ) ) ;
F_45 ( V_102 , F_2 ( V_1 ) ) ;
V_127 = F_46 ( V_23 ) ;
if ( V_127 ) {
F_32 ( & V_113 -> V_114 , L_11 , V_127 ) ;
goto V_155;
}
V_1 -> V_23 = V_23 ;
return 0 ;
V_155:
F_47 ( V_101 , F_1 ( V_1 ) ) ;
F_47 ( V_102 , F_2 ( V_1 ) ) ;
F_48 ( & V_23 -> V_154 ) ;
F_30 ( V_1 ) ;
V_145:
F_49 ( V_1 -> V_82 ) ;
V_143:
F_50 ( V_1 -> V_100 ) ;
V_142:
F_50 ( V_1 -> V_78 ) ;
V_141:
F_51 ( V_23 ) ;
V_136:
F_52 ( V_130 -> V_133 , F_35 ( V_130 ) ) ;
return V_127 ;
}
static int T_5 F_53 ( struct V_126 * V_113 )
{
struct V_1 * V_1 = F_54 ( V_113 ) ;
F_23 ( V_156 , V_1 -> V_23 ) ;
F_47 ( V_101 , F_1 ( V_1 ) ) ;
F_47 ( V_102 , F_2 ( V_1 ) ) ;
F_49 ( V_1 -> V_82 ) ;
F_52 ( V_1 -> V_130 -> V_133 , F_35 ( V_1 -> V_130 ) ) ;
F_48 ( & V_1 -> V_23 -> V_154 ) ;
F_30 ( V_1 ) ;
F_41 ( V_113 , NULL ) ;
F_50 ( V_1 -> V_100 ) ;
F_50 ( V_1 -> V_78 ) ;
F_51 ( V_1 -> V_23 ) ;
return 0 ;
}
static int F_55 ( struct V_157 * V_114 )
{
struct V_1 * V_1 = F_56 ( V_114 ) ;
F_57 () ;
F_58 ( V_1 -> V_23 , 1 ) ;
F_59 () ;
F_12 ( & V_1 -> V_76 ) ;
if ( V_1 -> V_77 )
F_21 ( V_1 ) ;
F_16 ( & V_1 -> V_76 ) ;
return 0 ;
}
static int F_60 ( struct V_157 * V_114 )
{
struct V_1 * V_1 = F_56 ( V_114 ) ;
F_13 ( V_1 -> V_78 ) ;
F_12 ( & V_1 -> V_76 ) ;
if ( V_1 -> V_77 )
F_18 ( V_1 ) ;
F_16 ( & V_1 -> V_76 ) ;
F_57 () ;
F_58 ( V_1 -> V_23 , 0 ) ;
F_59 () ;
return 0 ;
}
static int T_6 F_61 ( void )
{
return F_62 ( & V_158 ) ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_158 ) ;
}
