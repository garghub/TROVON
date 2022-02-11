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
bool V_73 = V_2 -> V_23 -> V_73 ;
F_15 ( V_2 -> V_2 , L_8 ,
( V_2 -> V_55 -> V_56 & V_74 ) ? L_9 : L_10 , V_2 -> V_38 ) ;
F_37 ( & V_2 -> V_70 ) ;
V_2 -> V_69 = 0 ;
if ( ! V_2 -> V_38 ) {
F_3 ( V_2 , V_13 , V_75 ) ;
F_3 ( V_2 , V_12 , V_7 ) ;
} else if ( V_2 -> V_55 -> V_56 & V_74 ) {
unsigned V_76 = V_77 ;
if ( F_1 ( V_2 , V_66 ) & V_8 ) {
F_25 ( V_2 -> V_2 , L_11 ) ;
F_1 ( V_2 , V_53 ) ;
}
if ( V_2 -> V_38 <= 1 && ! ( V_2 -> V_55 -> V_56 & V_57 ) )
V_76 |= V_41 ;
F_3 ( V_2 , V_13 , V_76 ) ;
if ( V_2 -> V_78 && ( V_2 -> V_38 > V_79 ) ) {
F_33 ( V_2 ) ;
F_3 ( V_2 , V_12 ,
V_7 ) ;
} else
F_3 ( V_2 , V_12 ,
V_7 | V_8 ) ;
} else {
if ( V_2 -> V_78 && ( V_2 -> V_38 > V_79 ) ) {
F_22 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_7 ) ;
} else {
F_20 ( V_2 ) ;
F_3 ( V_2 , V_12 ,
V_7 | V_9 ) ;
}
}
V_72 = F_38 ( & V_2 -> V_70 ,
V_2 -> V_80 . V_81 ) ;
if ( V_72 == 0 ) {
F_25 ( V_2 -> V_2 , L_12 ) ;
F_8 ( V_2 ) ;
V_72 = - V_82 ;
goto error;
}
if ( V_2 -> V_69 & V_83 ) {
F_15 ( V_2 -> V_2 , L_13 ) ;
V_72 = - V_84 ;
goto error;
}
if ( V_2 -> V_69 & V_85 ) {
F_25 ( V_2 -> V_2 , L_14 ) ;
V_72 = - V_86 ;
goto error;
}
if ( V_73 && V_2 -> V_69 & V_87 ) {
F_25 ( V_2 -> V_2 , L_15 ) ;
V_72 = - V_86 ;
goto error;
}
if ( V_2 -> V_54 ) {
F_25 ( V_2 -> V_2 , L_16 ) ;
V_72 = - V_88 ;
goto error;
}
F_15 ( V_2 -> V_2 , L_17 ) ;
return 0 ;
error:
F_16 ( V_2 ) ;
return V_72 ;
}
static int F_39 ( struct V_89 * V_90 , struct V_91 * V_55 , int V_92 )
{
struct V_1 * V_2 = F_40 ( V_90 ) ;
int V_72 ;
unsigned V_93 = 0 ;
struct V_91 * V_94 = V_55 ;
F_15 ( & V_90 -> V_2 , L_18 , V_92 ) ;
V_72 = F_41 ( V_2 -> V_2 ) ;
if ( V_72 < 0 )
goto V_95;
if ( V_92 > 2 ) {
F_25 ( V_2 -> V_2 ,
L_19 ) ;
V_72 = 0 ;
goto V_95;
} else if ( V_92 == 2 ) {
int V_96 = 0 ;
int V_97 ;
if ( V_55 -> V_56 & V_74 ) {
F_25 ( V_2 -> V_2 , L_20 ) ;
V_72 = - V_98 ;
goto V_95;
}
if ( V_55 -> V_59 > 3 ) {
F_25 ( V_2 -> V_2 , L_21 ) ;
V_72 = - V_98 ;
goto V_95;
}
V_94 = & V_55 [ 1 ] ;
for ( V_97 = 0 ; V_97 < V_55 -> V_59 ; ++ V_97 ) {
const unsigned V_99 = V_55 -> V_40 [ V_55 -> V_59 - 1 - V_97 ] ;
V_96 |= V_99 << ( 8 * V_97 ) ;
V_93 += V_100 ;
}
F_3 ( V_2 , V_101 , V_96 ) ;
}
F_3 ( V_2 , V_102 , ( V_94 -> V_99 << 16 ) | V_93
| ( ( V_94 -> V_56 & V_74 ) ? V_103 : 0 ) ) ;
V_2 -> V_38 = V_94 -> V_59 ;
V_2 -> V_40 = V_94 -> V_40 ;
V_2 -> V_55 = V_94 ;
V_2 -> V_54 = false ;
V_72 = F_36 ( V_2 ) ;
V_72 = ( V_72 < 0 ) ? V_72 : V_92 ;
V_95:
F_42 ( V_2 -> V_2 ) ;
F_43 ( V_2 -> V_2 ) ;
return V_72 ;
}
static T_3 F_44 ( struct V_89 * V_80 )
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
V_30 -> V_35 = F_46 ( V_2 -> V_2 , L_22 ) ;
if ( F_47 ( V_30 -> V_35 ) ) {
V_72 = F_48 ( V_30 -> V_35 ) ;
V_30 -> V_35 = NULL ;
goto error;
}
V_30 -> V_34 = F_46 ( V_2 -> V_2 , L_23 ) ;
if ( F_47 ( V_30 -> V_34 ) ) {
V_72 = F_48 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
goto error;
}
V_109 . V_32 = V_48 ;
if ( F_49 ( V_30 -> V_35 , & V_109 ) ) {
F_25 ( V_2 -> V_2 , L_24 ) ;
V_72 = - V_98 ;
goto error;
}
V_109 . V_32 = V_62 ;
if ( F_49 ( V_30 -> V_34 , & V_109 ) ) {
F_25 ( V_2 -> V_2 , L_25 ) ;
V_72 = - V_98 ;
goto error;
}
F_50 ( & V_30 -> V_37 , 1 ) ;
V_30 -> V_36 = false ;
V_30 -> V_31 = false ;
V_2 -> V_78 = true ;
F_51 ( V_2 -> V_2 , L_26 ,
F_52 ( V_30 -> V_35 ) , F_52 ( V_30 -> V_34 ) ) ;
return V_72 ;
error:
if ( V_72 != - V_118 )
F_51 ( V_2 -> V_2 , L_27 , V_72 ) ;
if ( V_30 -> V_34 )
F_53 ( V_30 -> V_34 ) ;
if ( V_30 -> V_35 )
F_53 ( V_30 -> V_35 ) ;
return V_72 ;
}
static struct V_22 * F_54 (
struct V_119 * V_120 )
{
if ( V_120 -> V_2 . V_121 ) {
const struct V_122 * V_123 ;
V_123 = F_55 ( V_124 , V_120 -> V_2 . V_121 ) ;
if ( ! V_123 )
return NULL ;
return (struct V_22 * ) V_123 -> V_42 ;
}
return (struct V_22 * ) F_56 ( V_120 ) -> V_125 ;
}
static int F_57 ( struct V_119 * V_120 )
{
struct V_1 * V_2 ;
struct V_126 * V_127 ;
int V_128 ;
T_3 V_107 ;
T_3 V_129 ;
V_2 = F_58 ( & V_120 -> V_2 , sizeof( * V_2 ) , V_130 ) ;
if ( ! V_2 )
return - V_131 ;
F_59 ( & V_2 -> V_70 ) ;
V_2 -> V_2 = & V_120 -> V_2 ;
V_127 = F_60 ( V_120 , V_132 , 0 ) ;
if ( ! V_127 )
return - V_133 ;
V_107 = V_127 -> V_134 ;
V_2 -> V_23 = F_54 ( V_120 ) ;
if ( ! V_2 -> V_23 )
return - V_133 ;
V_2 -> V_4 = F_61 ( & V_120 -> V_2 , V_127 ) ;
if ( F_47 ( V_2 -> V_4 ) )
return F_48 ( V_2 -> V_4 ) ;
V_2 -> V_63 = F_62 ( V_120 , 0 ) ;
if ( V_2 -> V_63 < 0 )
return V_2 -> V_63 ;
V_128 = F_63 ( & V_120 -> V_2 , V_2 -> V_63 , F_34 , 0 ,
F_64 ( V_2 -> V_2 ) , V_2 ) ;
if ( V_128 ) {
F_25 ( V_2 -> V_2 , L_28 , V_2 -> V_63 , V_128 ) ;
return V_128 ;
}
F_65 ( V_120 , V_2 ) ;
V_2 -> V_28 = F_66 ( V_2 -> V_2 , NULL ) ;
if ( F_47 ( V_2 -> V_28 ) ) {
F_25 ( V_2 -> V_2 , L_29 ) ;
return - V_133 ;
}
F_67 ( V_2 -> V_28 ) ;
if ( V_2 -> V_2 -> V_121 ) {
V_128 = F_45 ( V_2 , V_107 ) ;
if ( V_128 == - V_118 )
return V_128 ;
}
V_128 = F_68 ( V_2 -> V_2 -> V_121 , L_30 ,
& V_129 ) ;
if ( V_128 )
V_129 = V_135 ;
F_9 ( V_2 , V_129 ) ;
F_8 ( V_2 ) ;
snprintf ( V_2 -> V_80 . V_136 , sizeof( V_2 -> V_80 . V_136 ) , L_31 ) ;
F_69 ( & V_2 -> V_80 , V_2 ) ;
V_2 -> V_80 . V_137 = V_138 ;
V_2 -> V_80 . V_139 = V_140 ;
V_2 -> V_80 . V_141 = & V_142 ;
V_2 -> V_80 . V_2 . V_143 = V_2 -> V_2 ;
V_2 -> V_80 . V_144 = V_120 -> V_145 ;
V_2 -> V_80 . V_81 = V_146 ;
V_2 -> V_80 . V_2 . V_121 = V_120 -> V_2 . V_121 ;
F_70 ( V_2 -> V_2 , V_147 ) ;
F_71 ( V_2 -> V_2 ) ;
F_72 ( V_2 -> V_2 ) ;
F_73 ( V_2 -> V_2 ) ;
V_128 = F_74 ( & V_2 -> V_80 ) ;
if ( V_128 ) {
F_25 ( V_2 -> V_2 , L_32 ,
V_2 -> V_80 . V_136 ) ;
F_75 ( V_2 -> V_28 ) ;
F_76 ( V_2 -> V_2 ) ;
F_77 ( V_2 -> V_2 ) ;
return V_128 ;
}
F_51 ( V_2 -> V_2 , L_33 ) ;
return 0 ;
}
static int F_78 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_79 ( V_120 ) ;
F_80 ( & V_2 -> V_80 ) ;
F_75 ( V_2 -> V_28 ) ;
F_76 ( V_2 -> V_2 ) ;
F_77 ( V_2 -> V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_148 * V_2 )
{
struct V_1 * V_149 = F_82 ( V_2 ) ;
F_75 ( V_149 -> V_28 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_148 * V_2 )
{
struct V_1 * V_149 = F_82 ( V_2 ) ;
F_85 ( V_2 ) ;
return F_67 ( V_149 -> V_28 ) ;
}
static int F_86 ( struct V_148 * V_2 )
{
if ( ! F_87 ( V_2 ) )
F_81 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_148 * V_2 )
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
return F_91 ( & V_150 ) ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_150 ) ;
}
