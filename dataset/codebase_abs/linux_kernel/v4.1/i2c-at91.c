static unsigned F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 ,
V_7 | V_8 | V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_10 = F_1 ( V_2 , V_11 ) & 0x7 ;
F_5 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_3 ( V_2 , V_13 , V_14 ) ;
F_3 ( V_2 , V_13 , V_15 ) ;
F_3 ( V_2 , V_13 , V_16 ) ;
F_3 ( V_2 , V_17 , V_2 -> V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_19 )
{
int V_20 , V_21 , div ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_24 = V_23 -> V_25 ;
int V_26 = V_23 -> V_27 ;
div = F_10 ( 0 , ( int ) F_11 ( F_12 ( V_2 -> V_28 ) ,
2 * V_19 ) - V_24 ) ;
V_20 = F_13 ( div >> 8 ) ;
V_21 = div >> V_20 ;
if ( V_20 > V_26 ) {
F_14 ( V_2 -> V_2 , L_1 ,
V_20 , V_26 ) ;
V_20 = V_26 ;
V_21 = 255 ;
}
V_2 -> V_18 = ( V_20 << 16 ) | ( V_21 << 8 ) | V_21 ;
F_15 ( V_2 -> V_2 , L_2 , V_21 , V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
F_6 ( V_2 ) ;
if ( V_30 -> V_31 ) {
if ( V_30 -> V_32 == V_33 )
F_17 ( V_30 -> V_34 ) ;
else
F_17 ( V_30 -> V_35 ) ;
V_30 -> V_31 = false ;
}
if ( V_30 -> V_36 ) {
F_18 ( V_2 -> V_2 , F_19 ( & V_30 -> V_37 ) ,
V_2 -> V_38 , V_30 -> V_32 ) ;
V_30 -> V_36 = false ;
}
F_7 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 <= 0 )
return;
F_3 ( V_2 , V_39 , * V_2 -> V_40 ) ;
if ( -- V_2 -> V_38 == 0 )
F_3 ( V_2 , V_13 , V_41 ) ;
F_15 ( V_2 -> V_2 , L_3 , * V_2 -> V_40 , V_2 -> V_38 ) ;
++ V_2 -> V_40 ;
}
static void F_21 ( void * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
F_18 ( V_2 -> V_2 , F_19 ( & V_2 -> V_30 . V_37 ) ,
V_2 -> V_38 , V_43 ) ;
F_3 ( V_2 , V_13 , V_41 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_44 ;
struct V_45 * V_46 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
struct V_47 * V_35 = V_30 -> V_35 ;
if ( V_2 -> V_38 <= 0 )
return;
V_30 -> V_32 = V_43 ;
F_6 ( V_2 ) ;
V_44 = F_23 ( V_2 -> V_2 , V_2 -> V_40 , V_2 -> V_38 ,
V_43 ) ;
if ( F_24 ( V_2 -> V_2 , V_44 ) ) {
F_25 ( V_2 -> V_2 , L_4 ) ;
return;
}
V_30 -> V_36 = true ;
F_7 ( V_2 ) ;
F_26 ( & V_30 -> V_37 ) = V_2 -> V_38 ;
F_19 ( & V_30 -> V_37 ) = V_44 ;
V_46 = F_27 ( V_35 , & V_30 -> V_37 , 1 , V_48 ,
V_49 | V_50 ) ;
if ( ! V_46 ) {
F_25 ( V_2 -> V_2 , L_5 ) ;
goto error;
}
V_46 -> V_51 = F_21 ;
V_46 -> V_52 = V_2 ;
V_30 -> V_31 = true ;
F_28 ( V_46 ) ;
F_29 ( V_35 ) ;
return;
error:
F_16 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 <= 0 )
return;
* V_2 -> V_40 = F_1 ( V_2 , V_53 ) & 0xff ;
-- V_2 -> V_38 ;
if ( V_2 -> V_54 )
return;
if ( F_31 ( V_2 -> V_55 -> V_56 & V_57 ) ) {
if ( * V_2 -> V_40 <= V_58 && * V_2 -> V_40 > 0 ) {
V_2 -> V_55 -> V_56 &= ~ V_57 ;
V_2 -> V_38 += * V_2 -> V_40 ;
V_2 -> V_55 -> V_59 = V_2 -> V_38 + 1 ;
F_15 ( V_2 -> V_2 , L_6 ,
V_2 -> V_38 ) ;
} else {
V_2 -> V_54 = true ;
V_2 -> V_38 = 1 ;
}
}
if ( V_2 -> V_38 == 1 )
F_3 ( V_2 , V_13 , V_41 ) ;
F_15 ( V_2 -> V_2 , L_7 , * V_2 -> V_40 , V_2 -> V_38 ) ;
++ V_2 -> V_40 ;
}
static void F_32 ( void * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
F_18 ( V_2 -> V_2 , F_19 ( & V_2 -> V_30 . V_37 ) ,
V_2 -> V_38 , V_33 ) ;
V_2 -> V_40 += V_2 -> V_38 - 2 ;
V_2 -> V_38 = 2 ;
F_3 ( V_2 , V_12 , V_8 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_44 ;
struct V_45 * V_60 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
struct V_47 * V_34 = V_30 -> V_34 ;
V_30 -> V_32 = V_33 ;
F_6 ( V_2 ) ;
V_44 = F_23 ( V_2 -> V_2 , V_2 -> V_40 , V_2 -> V_38 - 2 ,
V_33 ) ;
if ( F_24 ( V_2 -> V_2 , V_44 ) ) {
F_25 ( V_2 -> V_2 , L_4 ) ;
return;
}
V_30 -> V_36 = true ;
F_7 ( V_2 ) ;
V_30 -> V_37 . V_61 = V_44 ;
F_26 ( & V_30 -> V_37 ) = V_2 -> V_38 - 2 ;
V_60 = F_27 ( V_34 , & V_30 -> V_37 , 1 , V_62 ,
V_49 | V_50 ) ;
if ( ! V_60 ) {
F_25 ( V_2 -> V_2 , L_5 ) ;
goto error;
}
V_60 -> V_51 = F_32 ;
V_60 -> V_52 = V_2 ;
V_30 -> V_31 = true ;
F_28 ( V_60 ) ;
F_29 ( V_30 -> V_34 ) ;
return;
error:
F_16 ( V_2 ) ;
}
static T_2 F_34 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
const unsigned V_65 = F_1 ( V_2 , V_66 ) ;
const unsigned V_67 = V_65 & F_1 ( V_2 , V_11 ) ;
if ( ! V_67 )
return V_68 ;
else if ( V_67 & V_8 )
F_30 ( V_2 ) ;
else if ( V_67 & V_9 )
F_20 ( V_2 ) ;
V_2 -> V_69 |= V_65 ;
if ( V_67 & V_7 ) {
F_5 ( V_2 ) ;
F_35 ( & V_2 -> V_70 ) ;
}
return V_71 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_72 ;
unsigned long V_73 ;
bool V_74 = V_2 -> V_23 -> V_74 ;
F_15 ( V_2 -> V_2 , L_8 ,
( V_2 -> V_55 -> V_56 & V_75 ) ? L_9 : L_10 , V_2 -> V_38 ) ;
F_37 ( & V_2 -> V_70 ) ;
V_2 -> V_69 = 0 ;
if ( ! V_2 -> V_38 ) {
F_3 ( V_2 , V_13 , V_76 ) ;
F_3 ( V_2 , V_12 , V_7 ) ;
} else if ( V_2 -> V_55 -> V_56 & V_75 ) {
unsigned V_77 = V_78 ;
if ( F_1 ( V_2 , V_66 ) & V_8 ) {
F_25 ( V_2 -> V_2 , L_11 ) ;
F_1 ( V_2 , V_53 ) ;
}
if ( V_2 -> V_38 <= 1 && ! ( V_2 -> V_55 -> V_56 & V_57 ) )
V_77 |= V_41 ;
F_3 ( V_2 , V_13 , V_77 ) ;
if ( V_2 -> V_79 && ( V_2 -> V_38 > V_80 ) ) {
F_33 ( V_2 ) ;
F_3 ( V_2 , V_12 ,
V_7 ) ;
} else
F_3 ( V_2 , V_12 ,
V_7 | V_8 ) ;
} else {
if ( V_2 -> V_79 && ( V_2 -> V_38 > V_80 ) ) {
F_22 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_7 ) ;
} else {
F_20 ( V_2 ) ;
F_3 ( V_2 , V_12 ,
V_7 | V_9 ) ;
}
}
V_73 = F_38 ( & V_2 -> V_70 ,
V_2 -> V_81 . V_82 ) ;
if ( V_73 == 0 ) {
F_25 ( V_2 -> V_2 , L_12 ) ;
F_8 ( V_2 ) ;
V_72 = - V_83 ;
goto error;
}
if ( V_2 -> V_69 & V_84 ) {
F_15 ( V_2 -> V_2 , L_13 ) ;
V_72 = - V_85 ;
goto error;
}
if ( V_2 -> V_69 & V_86 ) {
F_25 ( V_2 -> V_2 , L_14 ) ;
V_72 = - V_87 ;
goto error;
}
if ( V_74 && V_2 -> V_69 & V_88 ) {
F_25 ( V_2 -> V_2 , L_15 ) ;
V_72 = - V_87 ;
goto error;
}
if ( V_2 -> V_54 ) {
F_25 ( V_2 -> V_2 , L_16 ) ;
V_72 = - V_89 ;
goto error;
}
F_15 ( V_2 -> V_2 , L_17 ) ;
return 0 ;
error:
F_16 ( V_2 ) ;
return V_72 ;
}
static int F_39 ( struct V_90 * V_91 , struct V_92 * V_55 , int V_93 )
{
struct V_1 * V_2 = F_40 ( V_91 ) ;
int V_72 ;
unsigned V_94 = 0 ;
struct V_92 * V_95 = V_55 ;
F_15 ( & V_91 -> V_2 , L_18 , V_93 ) ;
V_72 = F_41 ( V_2 -> V_2 ) ;
if ( V_72 < 0 )
goto V_96;
if ( V_93 == 2 ) {
int V_97 = 0 ;
int V_98 ;
V_95 = & V_55 [ 1 ] ;
for ( V_98 = 0 ; V_98 < V_55 -> V_59 ; ++ V_98 ) {
const unsigned V_99 = V_55 -> V_40 [ V_55 -> V_59 - 1 - V_98 ] ;
V_97 |= V_99 << ( 8 * V_98 ) ;
V_94 += V_100 ;
}
F_3 ( V_2 , V_101 , V_97 ) ;
}
F_3 ( V_2 , V_102 , ( V_95 -> V_99 << 16 ) | V_94
| ( ( V_95 -> V_56 & V_75 ) ? V_103 : 0 ) ) ;
V_2 -> V_38 = V_95 -> V_59 ;
V_2 -> V_40 = V_95 -> V_40 ;
V_2 -> V_55 = V_95 ;
V_2 -> V_54 = false ;
V_72 = F_36 ( V_2 ) ;
V_72 = ( V_72 < 0 ) ? V_72 : V_93 ;
V_96:
F_42 ( V_2 -> V_2 ) ;
F_43 ( V_2 -> V_2 ) ;
return V_72 ;
}
static T_3 F_44 ( struct V_90 * V_81 )
{
return V_104 | V_105
| V_106 ;
}
static int F_45 ( struct V_1 * V_2 , T_3 V_107 )
{
int V_72 = 0 ;
struct V_108 V_109 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_110 = ( T_1 ) V_107 + V_53 ;
V_109 . V_111 = V_112 ;
V_109 . V_113 = 1 ;
V_109 . V_114 = ( T_1 ) V_107 + V_39 ;
V_109 . V_115 = V_112 ;
V_109 . V_116 = 1 ;
V_109 . V_117 = false ;
V_30 -> V_35 = F_46 ( V_2 -> V_2 , L_19 ) ;
if ( F_47 ( V_30 -> V_35 ) ) {
V_72 = F_48 ( V_30 -> V_35 ) ;
V_30 -> V_35 = NULL ;
goto error;
}
V_30 -> V_34 = F_46 ( V_2 -> V_2 , L_20 ) ;
if ( F_47 ( V_30 -> V_34 ) ) {
V_72 = F_48 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
goto error;
}
V_109 . V_32 = V_48 ;
if ( F_49 ( V_30 -> V_35 , & V_109 ) ) {
F_25 ( V_2 -> V_2 , L_21 ) ;
V_72 = - V_118 ;
goto error;
}
V_109 . V_32 = V_62 ;
if ( F_49 ( V_30 -> V_34 , & V_109 ) ) {
F_25 ( V_2 -> V_2 , L_22 ) ;
V_72 = - V_118 ;
goto error;
}
F_50 ( & V_30 -> V_37 , 1 ) ;
V_30 -> V_36 = false ;
V_30 -> V_31 = false ;
V_2 -> V_79 = true ;
F_51 ( V_2 -> V_2 , L_23 ,
F_52 ( V_30 -> V_35 ) , F_52 ( V_30 -> V_34 ) ) ;
return V_72 ;
error:
if ( V_72 != - V_119 )
F_51 ( V_2 -> V_2 , L_24 , V_72 ) ;
if ( V_30 -> V_34 )
F_53 ( V_30 -> V_34 ) ;
if ( V_30 -> V_35 )
F_53 ( V_30 -> V_35 ) ;
return V_72 ;
}
static struct V_22 * F_54 (
struct V_120 * V_121 )
{
if ( V_121 -> V_2 . V_122 ) {
const struct V_123 * V_124 ;
V_124 = F_55 ( V_125 , V_121 -> V_2 . V_122 ) ;
if ( ! V_124 )
return NULL ;
return (struct V_22 * ) V_124 -> V_42 ;
}
return (struct V_22 * ) F_56 ( V_121 ) -> V_126 ;
}
static int F_57 ( struct V_120 * V_121 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 ;
int V_129 ;
T_3 V_107 ;
T_3 V_130 ;
V_2 = F_58 ( & V_121 -> V_2 , sizeof( * V_2 ) , V_131 ) ;
if ( ! V_2 )
return - V_132 ;
F_59 ( & V_2 -> V_70 ) ;
V_2 -> V_2 = & V_121 -> V_2 ;
V_128 = F_60 ( V_121 , V_133 , 0 ) ;
if ( ! V_128 )
return - V_134 ;
V_107 = V_128 -> V_135 ;
V_2 -> V_23 = F_54 ( V_121 ) ;
if ( ! V_2 -> V_23 )
return - V_134 ;
V_2 -> V_4 = F_61 ( & V_121 -> V_2 , V_128 ) ;
if ( F_47 ( V_2 -> V_4 ) )
return F_48 ( V_2 -> V_4 ) ;
V_2 -> V_63 = F_62 ( V_121 , 0 ) ;
if ( V_2 -> V_63 < 0 )
return V_2 -> V_63 ;
V_129 = F_63 ( & V_121 -> V_2 , V_2 -> V_63 , F_34 , 0 ,
F_64 ( V_2 -> V_2 ) , V_2 ) ;
if ( V_129 ) {
F_25 ( V_2 -> V_2 , L_25 , V_2 -> V_63 , V_129 ) ;
return V_129 ;
}
F_65 ( V_121 , V_2 ) ;
V_2 -> V_28 = F_66 ( V_2 -> V_2 , NULL ) ;
if ( F_47 ( V_2 -> V_28 ) ) {
F_25 ( V_2 -> V_2 , L_26 ) ;
return - V_134 ;
}
F_67 ( V_2 -> V_28 ) ;
if ( V_2 -> V_2 -> V_122 ) {
V_129 = F_45 ( V_2 , V_107 ) ;
if ( V_129 == - V_119 )
return V_129 ;
}
V_129 = F_68 ( V_2 -> V_2 -> V_122 , L_27 ,
& V_130 ) ;
if ( V_129 )
V_130 = V_136 ;
F_9 ( V_2 , V_130 ) ;
F_8 ( V_2 ) ;
snprintf ( V_2 -> V_81 . V_137 , sizeof( V_2 -> V_81 . V_137 ) , L_28 ) ;
F_69 ( & V_2 -> V_81 , V_2 ) ;
V_2 -> V_81 . V_138 = V_139 ;
V_2 -> V_81 . V_140 = V_141 ;
V_2 -> V_81 . V_142 = & V_143 ;
V_2 -> V_81 . V_144 = & V_145 ;
V_2 -> V_81 . V_2 . V_146 = V_2 -> V_2 ;
V_2 -> V_81 . V_147 = V_121 -> V_148 ;
V_2 -> V_81 . V_82 = V_149 ;
V_2 -> V_81 . V_2 . V_122 = V_121 -> V_2 . V_122 ;
F_70 ( V_2 -> V_2 , V_150 ) ;
F_71 ( V_2 -> V_2 ) ;
F_72 ( V_2 -> V_2 ) ;
F_73 ( V_2 -> V_2 ) ;
V_129 = F_74 ( & V_2 -> V_81 ) ;
if ( V_129 ) {
F_25 ( V_2 -> V_2 , L_29 ,
V_2 -> V_81 . V_137 ) ;
F_75 ( V_2 -> V_28 ) ;
F_76 ( V_2 -> V_2 ) ;
F_77 ( V_2 -> V_2 ) ;
return V_129 ;
}
F_51 ( V_2 -> V_2 , L_30 ) ;
return 0 ;
}
static int F_78 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_79 ( V_121 ) ;
F_80 ( & V_2 -> V_81 ) ;
F_75 ( V_2 -> V_28 ) ;
F_76 ( V_2 -> V_2 ) ;
F_77 ( V_2 -> V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_151 * V_2 )
{
struct V_1 * V_152 = F_82 ( V_2 ) ;
F_75 ( V_152 -> V_28 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_151 * V_2 )
{
struct V_1 * V_152 = F_82 ( V_2 ) ;
F_85 ( V_2 ) ;
return F_67 ( V_152 -> V_28 ) ;
}
static int F_86 ( struct V_151 * V_2 )
{
if ( ! F_87 ( V_2 ) )
F_81 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_151 * V_2 )
{
int V_72 ;
if ( ! F_87 ( V_2 ) ) {
V_72 = F_84 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
F_42 ( V_2 ) ;
F_89 ( V_2 ) ;
return 0 ;
}
static int T_4 F_90 ( void )
{
return F_91 ( & V_153 ) ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_153 ) ;
}
