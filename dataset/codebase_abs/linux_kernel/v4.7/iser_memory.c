void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 , L_1 ) ;
}
int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_7 ;
if ( V_8 -> V_9 && V_8 -> V_10 &&
V_8 -> V_11 && V_8 -> V_12 ) {
F_4 ( L_2 ) ;
V_6 -> V_13 = & V_14 ;
} else if ( V_8 -> V_15 . V_16 & V_17 ) {
F_4 ( L_3 ) ;
V_6 -> V_13 = & V_18 ;
V_6 -> V_19 = V_20 ;
} else {
F_5 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
struct V_21 *
F_6 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
struct V_21 * V_25 ;
unsigned long V_26 ;
F_7 ( & V_24 -> V_27 , V_26 ) ;
V_25 = F_8 ( & V_24 -> V_28 ,
struct V_21 , V_28 ) ;
F_9 ( & V_25 -> V_28 ) ;
F_10 ( & V_24 -> V_27 , V_26 ) ;
return V_25 ;
}
void
F_11 ( struct V_22 * V_22 ,
struct V_21 * V_25 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
unsigned long V_26 ;
F_7 ( & V_24 -> V_27 , V_26 ) ;
F_12 ( & V_25 -> V_28 , & V_24 -> V_28 ) ;
F_10 ( & V_24 -> V_27 , V_26 ) ;
}
struct V_21 *
F_13 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
return F_8 ( & V_24 -> V_28 ,
struct V_21 , V_28 ) ;
}
void
F_14 ( struct V_22 * V_22 ,
struct V_21 * V_25 )
{
}
static void F_15 ( struct V_29 * V_30 ,
struct V_7 * V_31 )
{
struct V_32 * V_33 ;
int V_34 ;
F_16 (data->sg, sg, data->dma_nents, i)
F_17 ( L_5
L_6 ,
V_34 , ( unsigned long ) F_18 ( V_31 , V_33 ) ,
F_19 ( V_33 ) , V_33 -> V_35 ,
V_33 -> V_36 , F_20 ( V_31 , V_33 ) ) ;
}
static void F_21 ( struct V_37 * V_38 )
{
int V_34 ;
F_5 ( L_7 ,
V_38 -> V_39 , V_38 -> V_40 . V_36 ) ;
for ( V_34 = 0 ; V_34 < V_38 -> V_39 ; V_34 ++ )
F_5 ( L_8 , V_34 , V_38 -> V_41 [ V_34 ] ) ;
}
int F_22 ( struct V_42 * V_43 ,
struct V_29 * V_30 ,
enum V_44 V_45 ,
enum V_46 V_47 )
{
struct V_7 * V_48 ;
V_43 -> V_49 [ V_45 ] = 1 ;
V_48 = V_43 -> V_50 -> V_22 . V_6 -> V_7 ;
V_30 -> V_51 = F_23 ( V_48 , V_30 -> V_33 , V_30 -> V_52 , V_47 ) ;
if ( V_30 -> V_51 == 0 ) {
F_5 ( L_9 ) ;
return - V_53 ;
}
return 0 ;
}
void F_24 ( struct V_42 * V_43 ,
struct V_29 * V_30 ,
enum V_46 V_49 )
{
struct V_7 * V_48 ;
V_48 = V_43 -> V_50 -> V_22 . V_6 -> V_7 ;
F_25 ( V_48 , V_30 -> V_33 , V_30 -> V_52 , V_49 ) ;
}
static int
F_26 ( struct V_5 * V_6 , struct V_29 * V_54 ,
struct V_55 * V_56 )
{
struct V_32 * V_33 = V_54 -> V_33 ;
V_56 -> V_57 . V_58 = V_6 -> V_59 -> V_60 ;
V_56 -> V_61 = V_6 -> V_62 ? V_6 -> V_62 -> V_61 : 0 ;
V_56 -> V_57 . V_63 = F_18 ( V_6 -> V_7 , & V_33 [ 0 ] ) ;
V_56 -> V_57 . V_36 = F_20 ( V_6 -> V_7 , & V_33 [ 0 ] ) ;
F_17 ( L_10
L_11 , V_56 -> V_57 . V_58 , V_56 -> V_61 ,
V_56 -> V_57 . V_63 , V_56 -> V_57 . V_36 ) ;
return 0 ;
}
static int F_27 ( struct V_64 * V_62 , T_1 V_63 )
{
struct V_37 * V_38 =
F_28 ( V_62 , struct V_37 , V_40 ) ;
V_38 -> V_41 [ V_38 -> V_39 ++ ] = V_63 ;
return 0 ;
}
static
int F_29 ( struct V_42 * V_43 ,
struct V_29 * V_54 ,
struct V_65 * V_66 ,
struct V_55 * V_56 )
{
struct V_22 * V_22 = & V_43 -> V_50 -> V_22 ;
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_37 * V_38 = V_66 -> V_38 ;
struct V_67 * V_68 = V_66 -> V_68 ;
struct V_69 * V_70 ;
int V_71 , V_72 ;
V_38 -> V_39 = 0 ;
V_38 -> V_40 . V_73 = V_74 ;
V_72 = F_30 ( & V_38 -> V_40 , V_54 -> V_33 ,
V_54 -> V_52 , NULL , F_27 ) ;
if ( F_31 ( V_72 < V_54 -> V_52 ) ) {
F_5 ( L_12 ) ;
F_15 ( V_54 , V_6 -> V_7 ) ;
F_21 ( V_38 ) ;
return - V_53 ;
}
V_70 = F_32 ( V_68 , V_38 -> V_41 ,
V_38 -> V_39 , V_38 -> V_41 [ 0 ] ) ;
if ( F_33 ( V_70 ) ) {
V_71 = F_34 ( V_70 ) ;
F_5 ( L_13 , V_71 ) ;
return V_71 ;
}
V_56 -> V_57 . V_58 = V_70 -> V_70 -> V_58 ;
V_56 -> V_61 = V_70 -> V_70 -> V_61 ;
V_56 -> V_57 . V_63 = V_38 -> V_40 . V_75 ;
V_56 -> V_57 . V_36 = V_38 -> V_40 . V_36 ;
V_56 -> V_76 = V_70 ;
F_17 ( L_14
L_11 , V_56 -> V_57 . V_58 , V_56 -> V_61 ,
V_56 -> V_57 . V_63 , V_56 -> V_57 . V_36 ) ;
return 0 ;
}
void F_35 ( struct V_42 * V_43 ,
enum V_44 V_77 )
{
struct V_55 * V_56 = & V_43 -> V_78 [ V_77 ] ;
int V_71 ;
if ( ! V_56 -> V_76 )
return;
F_17 ( L_15 , V_56 -> V_76 ) ;
V_71 = F_36 ( (struct V_69 * ) V_56 -> V_76 ) ;
if ( V_71 )
F_5 ( L_16 , V_71 ) ;
V_56 -> V_76 = NULL ;
}
void F_37 ( struct V_42 * V_43 ,
enum V_44 V_77 )
{
struct V_5 * V_6 = V_43 -> V_50 -> V_22 . V_6 ;
struct V_55 * V_56 = & V_43 -> V_78 [ V_77 ] ;
if ( ! V_56 -> V_76 )
return;
V_6 -> V_13 -> V_79 ( & V_43 -> V_50 -> V_22 ,
V_56 -> V_76 ) ;
V_56 -> V_76 = NULL ;
}
static void
F_38 ( struct V_80 * V_81 , struct V_82 * V_83 ,
struct V_84 * V_85 )
{
V_85 -> V_86 = V_87 ;
V_85 -> V_88 . V_89 . V_90 = F_39 ( V_81 ) ;
V_85 -> V_88 . V_89 . V_91 = F_40 ( V_81 ) ;
V_85 -> V_88 . V_89 . V_92 = 0xffff ;
V_85 -> V_88 . V_89 . V_93 = true ;
V_85 -> V_88 . V_89 . V_94 = true ;
if ( V_81 -> V_95 & V_96 )
V_85 -> V_88 . V_89 . V_97 = true ;
}
static int
F_41 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
switch ( F_42 ( V_81 ) ) {
case V_98 :
case V_99 :
V_83 -> V_54 . V_86 = V_100 ;
F_38 ( V_81 , V_83 , & V_83 -> V_101 ) ;
V_83 -> V_101 . V_88 . V_89 . V_102 = V_103 ;
break;
case V_104 :
case V_105 :
V_83 -> V_101 . V_86 = V_100 ;
F_38 ( V_81 , V_83 , & V_83 -> V_54 ) ;
V_83 -> V_54 . V_88 . V_89 . V_102 = V_81 -> V_95 & V_106 ?
V_107 : V_103 ;
break;
case V_108 :
case V_109 :
F_38 ( V_81 , V_83 , & V_83 -> V_101 ) ;
V_83 -> V_101 . V_88 . V_89 . V_102 = V_103 ;
F_38 ( V_81 , V_83 , & V_83 -> V_54 ) ;
V_83 -> V_54 . V_88 . V_89 . V_102 = V_81 -> V_95 & V_106 ?
V_107 : V_103 ;
break;
default:
F_5 ( L_17 ,
F_42 ( V_81 ) ) ;
return - V_53 ;
}
return 0 ;
}
static inline void
F_43 ( struct V_80 * V_81 , T_2 * V_110 )
{
* V_110 = 0 ;
if ( V_81 -> V_95 & V_111 )
* V_110 |= V_112 ;
if ( V_81 -> V_95 & V_113 )
* V_110 |= V_114 ;
}
static inline void
F_44 ( struct V_115 * V_116 ,
struct V_64 * V_62 ,
struct V_117 * V_118 )
{
V_116 -> V_119 = V_120 ;
V_116 -> V_121 = V_118 ;
V_116 -> V_122 . V_123 = V_62 -> V_61 ;
V_116 -> V_124 = 0 ;
V_116 -> V_125 = 0 ;
}
static int
F_45 ( struct V_42 * V_43 ,
struct V_126 * V_127 ,
struct V_55 * V_128 ,
struct V_55 * V_129 ,
struct V_55 * V_130 )
{
struct V_131 * V_132 = & V_43 -> V_25 ;
struct V_82 * V_83 = & V_132 -> V_83 ;
struct V_117 * V_118 = & V_43 -> V_50 -> V_22 . V_133 ;
struct V_134 * V_135 ;
struct V_64 * V_62 = V_127 -> V_136 ;
int V_71 ;
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
V_71 = F_41 ( V_43 -> V_81 , V_83 ) ;
if ( V_71 )
goto V_137;
F_43 ( V_43 -> V_81 , & V_83 -> V_138 ) ;
if ( V_127 -> V_139 )
F_44 ( F_46 ( V_132 ) , V_62 , V_118 ) ;
F_47 ( V_62 , F_48 ( V_62 -> V_61 ) ) ;
V_135 = F_49 ( F_46 ( V_132 ) ) ;
V_135 -> V_135 . V_119 = V_140 ;
V_135 -> V_135 . V_121 = V_118 ;
V_135 -> V_135 . V_141 = & V_128 -> V_57 ;
V_135 -> V_135 . V_125 = 1 ;
V_135 -> V_135 . V_124 = 0 ;
V_135 -> V_83 = V_83 ;
V_135 -> V_136 = V_62 ;
if ( F_50 ( V_43 -> V_81 ) )
V_135 -> V_142 = & V_129 -> V_57 ;
else
V_135 -> V_142 = NULL ;
V_135 -> V_143 = V_144 |
V_145 |
V_146 ;
V_127 -> V_139 = 1 ;
V_130 -> V_57 . V_58 = V_62 -> V_58 ;
V_130 -> V_61 = V_62 -> V_61 ;
V_130 -> V_57 . V_63 = 0 ;
V_130 -> V_57 . V_36 = F_51 ( V_43 -> V_81 ) ;
F_17 ( L_18 ,
V_130 -> V_57 . V_58 , V_130 -> V_61 , V_130 -> V_57 . V_63 ,
V_130 -> V_57 . V_36 ) ;
V_137:
return V_71 ;
}
static int F_52 ( struct V_42 * V_43 ,
struct V_29 * V_54 ,
struct V_65 * V_66 ,
struct V_55 * V_56 )
{
struct V_131 * V_132 = & V_43 -> V_25 ;
struct V_117 * V_118 = & V_43 -> V_50 -> V_22 . V_133 ;
struct V_64 * V_62 = V_66 -> V_62 ;
struct V_147 * V_135 ;
int V_148 ;
if ( V_66 -> V_149 )
F_44 ( F_46 ( V_132 ) , V_62 , V_118 ) ;
F_47 ( V_62 , F_48 ( V_62 -> V_61 ) ) ;
V_148 = F_53 ( V_62 , V_54 -> V_33 , V_54 -> V_52 , NULL , V_74 ) ;
if ( F_31 ( V_148 != V_54 -> V_52 ) ) {
F_5 ( L_19 ,
V_148 , V_54 -> V_52 ) ;
return V_148 < 0 ? V_148 : - V_53 ;
}
V_135 = F_54 ( F_46 ( V_132 ) ) ;
V_135 -> V_135 . V_119 = V_150 ;
V_135 -> V_135 . V_121 = V_118 ;
V_135 -> V_135 . V_124 = 0 ;
V_135 -> V_135 . V_125 = 0 ;
V_135 -> V_62 = V_62 ;
V_135 -> V_151 = V_62 -> V_61 ;
V_135 -> V_152 = V_144 |
V_146 |
V_145 ;
V_66 -> V_149 = 1 ;
V_56 -> V_57 . V_58 = V_62 -> V_58 ;
V_56 -> V_61 = V_62 -> V_61 ;
V_56 -> V_57 . V_63 = V_62 -> V_75 ;
V_56 -> V_57 . V_36 = V_62 -> V_36 ;
F_17 ( L_20 ,
V_56 -> V_57 . V_58 , V_56 -> V_61 , V_56 -> V_57 . V_63 , V_56 -> V_57 . V_36 ) ;
return 0 ;
}
static int
F_55 ( struct V_42 * V_153 ,
struct V_29 * V_54 ,
struct V_21 * V_25 ,
bool V_154 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_153 -> V_50 -> V_22 . V_6 ;
if ( V_154 )
return F_26 ( V_6 , V_54 , V_56 ) ;
return V_6 -> V_13 -> V_155 ( V_153 , V_54 , & V_25 -> V_127 -> V_66 , V_56 ) ;
}
static int
F_56 ( struct V_42 * V_153 ,
struct V_29 * V_54 ,
struct V_21 * V_25 ,
bool V_154 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_153 -> V_50 -> V_22 . V_6 ;
if ( V_154 )
return F_26 ( V_6 , V_54 , V_56 ) ;
return V_6 -> V_13 -> V_155 ( V_153 , V_54 , & V_25 -> V_66 , V_56 ) ;
}
int F_57 ( struct V_42 * V_153 ,
enum V_44 V_49 ,
bool V_156 )
{
struct V_22 * V_22 = & V_153 -> V_50 -> V_22 ;
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_29 * V_54 = & V_153 -> V_30 [ V_49 ] ;
struct V_55 * V_56 = & V_153 -> V_78 [ V_49 ] ;
struct V_55 * V_128 ;
struct V_21 * V_25 = NULL ;
bool V_154 ;
int V_137 ;
V_154 = V_54 -> V_51 == 1 && ( V_156 || ! V_20 ) &&
F_42 ( V_153 -> V_81 ) == V_157 ;
if ( ! V_154 ) {
V_25 = V_6 -> V_13 -> V_158 ( V_22 ) ;
V_56 -> V_76 = V_25 ;
}
if ( F_42 ( V_153 -> V_81 ) == V_157 )
V_128 = V_56 ;
else
V_128 = & V_153 -> V_25 . V_128 ;
V_137 = F_56 ( V_153 , V_54 , V_25 , V_154 , V_128 ) ;
if ( F_31 ( V_137 ) )
goto V_159;
if ( F_42 ( V_153 -> V_81 ) != V_157 ) {
struct V_55 * V_129 = & V_153 -> V_25 . V_129 ;
if ( F_50 ( V_153 -> V_81 ) ) {
V_54 = & V_153 -> V_142 [ V_49 ] ;
V_137 = F_55 ( V_153 , V_54 , V_25 ,
V_154 , V_129 ) ;
if ( F_31 ( V_137 ) )
goto V_159;
}
V_137 = F_45 ( V_153 , V_25 -> V_127 , V_128 ,
V_129 , V_56 ) ;
if ( F_31 ( V_137 ) )
goto V_159;
V_25 -> V_127 -> V_160 = 1 ;
}
return 0 ;
V_159:
if ( V_25 )
V_6 -> V_13 -> V_79 ( V_22 , V_25 ) ;
return V_137 ;
}
void F_58 ( struct V_42 * V_153 ,
enum V_44 V_49 )
{
struct V_5 * V_6 = V_153 -> V_50 -> V_22 . V_6 ;
V_6 -> V_13 -> V_161 ( V_153 , V_49 ) ;
}
