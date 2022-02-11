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
if ( V_6 -> V_59 -> V_26 & V_61 )
V_56 -> V_62 = V_6 -> V_59 -> V_63 ;
else
V_56 -> V_62 = 0 ;
V_56 -> V_57 . V_64 = F_18 ( V_6 -> V_7 , & V_33 [ 0 ] ) ;
V_56 -> V_57 . V_36 = F_20 ( V_6 -> V_7 , & V_33 [ 0 ] ) ;
F_17 ( L_10
L_11 , V_56 -> V_57 . V_58 , V_56 -> V_62 ,
V_56 -> V_57 . V_64 , V_56 -> V_57 . V_36 ) ;
return 0 ;
}
static int F_27 ( struct V_65 * V_66 , T_1 V_64 )
{
struct V_37 * V_38 =
F_28 ( V_66 , struct V_37 , V_40 ) ;
V_38 -> V_41 [ V_38 -> V_39 ++ ] = V_64 ;
return 0 ;
}
static
int F_29 ( struct V_42 * V_43 ,
struct V_29 * V_54 ,
struct V_67 * V_68 ,
struct V_55 * V_56 )
{
struct V_22 * V_22 = & V_43 -> V_50 -> V_22 ;
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_37 * V_38 = V_68 -> V_38 ;
struct V_69 * V_70 = V_68 -> V_70 ;
struct V_71 * V_72 ;
int V_73 , V_74 ;
V_38 -> V_39 = 0 ;
V_38 -> V_40 . V_75 = V_76 ;
V_74 = F_30 ( & V_38 -> V_40 , V_54 -> V_33 ,
V_54 -> V_52 , NULL , F_27 ) ;
if ( F_31 ( V_74 < V_54 -> V_52 ) ) {
F_5 ( L_12 ) ;
F_15 ( V_54 , V_6 -> V_7 ) ;
F_21 ( V_38 ) ;
return - V_53 ;
}
V_72 = F_32 ( V_70 , V_38 -> V_41 ,
V_38 -> V_39 , V_38 -> V_41 [ 0 ] ) ;
if ( F_33 ( V_72 ) ) {
V_73 = F_34 ( V_72 ) ;
F_5 ( L_13 , V_73 ) ;
return V_73 ;
}
V_56 -> V_57 . V_58 = V_72 -> V_72 -> V_58 ;
V_56 -> V_62 = V_72 -> V_72 -> V_62 ;
V_56 -> V_57 . V_64 = V_38 -> V_40 . V_77 ;
V_56 -> V_57 . V_36 = V_38 -> V_40 . V_36 ;
V_56 -> V_78 = V_72 ;
F_17 ( L_14
L_11 , V_56 -> V_57 . V_58 , V_56 -> V_62 ,
V_56 -> V_57 . V_64 , V_56 -> V_57 . V_36 ) ;
return 0 ;
}
void F_35 ( struct V_42 * V_43 ,
enum V_44 V_79 )
{
struct V_55 * V_56 = & V_43 -> V_80 [ V_79 ] ;
int V_73 ;
if ( ! V_56 -> V_78 )
return;
F_17 ( L_15 , V_56 -> V_78 ) ;
V_73 = F_36 ( (struct V_71 * ) V_56 -> V_78 ) ;
if ( V_73 )
F_5 ( L_16 , V_73 ) ;
V_56 -> V_78 = NULL ;
}
void F_37 ( struct V_42 * V_43 ,
enum V_44 V_79 )
{
struct V_5 * V_6 = V_43 -> V_50 -> V_22 . V_6 ;
struct V_55 * V_56 = & V_43 -> V_80 [ V_79 ] ;
if ( ! V_56 -> V_78 )
return;
V_6 -> V_13 -> V_81 ( & V_43 -> V_50 -> V_22 ,
V_56 -> V_78 ) ;
V_56 -> V_78 = NULL ;
}
static void
F_38 ( struct V_82 * V_83 , struct V_84 * V_85 ,
struct V_86 * V_87 )
{
V_87 -> V_88 = V_89 ;
V_87 -> V_90 . V_91 . V_92 = F_39 ( V_83 ) ;
V_87 -> V_90 . V_91 . V_93 = F_40 ( V_83 ) ;
V_87 -> V_90 . V_91 . V_94 = 0xffff ;
V_87 -> V_90 . V_91 . V_95 = true ;
V_87 -> V_90 . V_91 . V_96 = true ;
if ( V_83 -> V_97 & V_98 )
V_87 -> V_90 . V_91 . V_99 = true ;
}
static int
F_41 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
switch ( F_42 ( V_83 ) ) {
case V_100 :
case V_101 :
V_85 -> V_54 . V_88 = V_102 ;
F_38 ( V_83 , V_85 , & V_85 -> V_103 ) ;
V_85 -> V_103 . V_90 . V_91 . V_104 = V_105 ;
break;
case V_106 :
case V_107 :
V_85 -> V_103 . V_88 = V_102 ;
F_38 ( V_83 , V_85 , & V_85 -> V_54 ) ;
V_85 -> V_54 . V_90 . V_91 . V_104 = V_83 -> V_97 & V_108 ?
V_109 : V_105 ;
break;
case V_110 :
case V_111 :
F_38 ( V_83 , V_85 , & V_85 -> V_103 ) ;
V_85 -> V_103 . V_90 . V_91 . V_104 = V_105 ;
F_38 ( V_83 , V_85 , & V_85 -> V_54 ) ;
V_85 -> V_54 . V_90 . V_91 . V_104 = V_83 -> V_97 & V_108 ?
V_109 : V_105 ;
break;
default:
F_5 ( L_17 ,
F_42 ( V_83 ) ) ;
return - V_53 ;
}
return 0 ;
}
static inline void
F_43 ( struct V_82 * V_83 , T_2 * V_112 )
{
* V_112 = 0 ;
if ( V_83 -> V_97 & V_113 )
* V_112 |= V_114 ;
if ( V_83 -> V_97 & V_115 )
* V_112 |= V_116 ;
}
static inline void
F_44 ( struct V_117 * V_118 ,
struct V_65 * V_66 ,
struct V_119 * V_120 )
{
V_118 -> V_121 = V_122 ;
V_118 -> V_123 = V_120 ;
V_118 -> V_124 . V_125 = V_66 -> V_62 ;
V_118 -> V_126 = 0 ;
V_118 -> V_127 = 0 ;
}
static int
F_45 ( struct V_42 * V_43 ,
struct V_128 * V_129 ,
struct V_55 * V_130 ,
struct V_55 * V_131 ,
struct V_55 * V_132 )
{
struct V_133 * V_134 = & V_43 -> V_25 ;
struct V_84 * V_85 = & V_134 -> V_85 ;
struct V_119 * V_120 = & V_43 -> V_50 -> V_22 . V_135 ;
struct V_136 * V_137 ;
struct V_65 * V_66 = V_129 -> V_138 ;
int V_73 ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
V_73 = F_41 ( V_43 -> V_83 , V_85 ) ;
if ( V_73 )
goto V_139;
F_43 ( V_43 -> V_83 , & V_85 -> V_140 ) ;
if ( V_129 -> V_141 )
F_44 ( F_46 ( V_134 ) , V_66 , V_120 ) ;
F_47 ( V_66 , F_48 ( V_66 -> V_62 ) ) ;
V_137 = F_49 ( F_46 ( V_134 ) ) ;
V_137 -> V_137 . V_121 = V_142 ;
V_137 -> V_137 . V_123 = V_120 ;
V_137 -> V_137 . V_143 = & V_130 -> V_57 ;
V_137 -> V_137 . V_127 = 1 ;
V_137 -> V_137 . V_126 = 0 ;
V_137 -> V_85 = V_85 ;
V_137 -> V_138 = V_66 ;
if ( F_50 ( V_43 -> V_83 ) )
V_137 -> V_144 = & V_131 -> V_57 ;
else
V_137 -> V_144 = NULL ;
V_137 -> V_145 = V_146 |
V_147 |
V_148 ;
V_129 -> V_141 = 1 ;
V_132 -> V_57 . V_58 = V_66 -> V_58 ;
V_132 -> V_62 = V_66 -> V_62 ;
V_132 -> V_57 . V_64 = 0 ;
V_132 -> V_57 . V_36 = F_51 ( V_43 -> V_83 ) ;
F_17 ( L_18 ,
V_132 -> V_57 . V_58 , V_132 -> V_62 , V_132 -> V_57 . V_64 ,
V_132 -> V_57 . V_36 ) ;
V_139:
return V_73 ;
}
static int F_52 ( struct V_42 * V_43 ,
struct V_29 * V_54 ,
struct V_67 * V_68 ,
struct V_55 * V_56 )
{
struct V_133 * V_134 = & V_43 -> V_25 ;
struct V_119 * V_120 = & V_43 -> V_50 -> V_22 . V_135 ;
struct V_65 * V_66 = V_68 -> V_66 ;
struct V_149 * V_137 ;
int V_150 ;
if ( V_68 -> V_151 )
F_44 ( F_46 ( V_134 ) , V_66 , V_120 ) ;
F_47 ( V_66 , F_48 ( V_66 -> V_62 ) ) ;
V_150 = F_53 ( V_66 , V_54 -> V_33 , V_54 -> V_52 , NULL , V_76 ) ;
if ( F_31 ( V_150 != V_54 -> V_52 ) ) {
F_5 ( L_19 ,
V_150 , V_54 -> V_52 ) ;
return V_150 < 0 ? V_150 : - V_53 ;
}
V_137 = F_54 ( F_46 ( V_134 ) ) ;
V_137 -> V_137 . V_121 = V_152 ;
V_137 -> V_137 . V_123 = V_120 ;
V_137 -> V_137 . V_126 = 0 ;
V_137 -> V_137 . V_127 = 0 ;
V_137 -> V_66 = V_66 ;
V_137 -> V_153 = V_66 -> V_62 ;
V_137 -> V_154 = V_146 |
V_148 |
V_147 ;
V_68 -> V_151 = 1 ;
V_56 -> V_57 . V_58 = V_66 -> V_58 ;
V_56 -> V_62 = V_66 -> V_62 ;
V_56 -> V_57 . V_64 = V_66 -> V_77 ;
V_56 -> V_57 . V_36 = V_66 -> V_36 ;
F_17 ( L_20 ,
V_56 -> V_57 . V_58 , V_56 -> V_62 , V_56 -> V_57 . V_64 , V_56 -> V_57 . V_36 ) ;
return 0 ;
}
static int
F_55 ( struct V_42 * V_155 ,
struct V_29 * V_54 ,
struct V_21 * V_25 ,
bool V_156 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_155 -> V_50 -> V_22 . V_6 ;
if ( V_156 )
return F_26 ( V_6 , V_54 , V_56 ) ;
return V_6 -> V_13 -> V_157 ( V_155 , V_54 , & V_25 -> V_129 -> V_68 , V_56 ) ;
}
static int
F_56 ( struct V_42 * V_155 ,
struct V_29 * V_54 ,
struct V_21 * V_25 ,
bool V_156 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_155 -> V_50 -> V_22 . V_6 ;
if ( V_156 )
return F_26 ( V_6 , V_54 , V_56 ) ;
return V_6 -> V_13 -> V_157 ( V_155 , V_54 , & V_25 -> V_68 , V_56 ) ;
}
int F_57 ( struct V_42 * V_155 ,
enum V_44 V_49 ,
bool V_158 )
{
struct V_22 * V_22 = & V_155 -> V_50 -> V_22 ;
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_29 * V_54 = & V_155 -> V_30 [ V_49 ] ;
struct V_55 * V_56 = & V_155 -> V_80 [ V_49 ] ;
struct V_55 * V_130 ;
struct V_21 * V_25 = NULL ;
bool V_156 ;
int V_139 ;
V_156 = V_54 -> V_51 == 1 && ( V_158 || ! V_20 ) &&
F_42 ( V_155 -> V_83 ) == V_159 ;
if ( ! V_156 ) {
V_25 = V_6 -> V_13 -> V_160 ( V_22 ) ;
V_56 -> V_78 = V_25 ;
}
if ( F_42 ( V_155 -> V_83 ) == V_159 )
V_130 = V_56 ;
else
V_130 = & V_155 -> V_25 . V_130 ;
V_139 = F_56 ( V_155 , V_54 , V_25 , V_156 , V_130 ) ;
if ( F_31 ( V_139 ) )
goto V_161;
if ( F_42 ( V_155 -> V_83 ) != V_159 ) {
struct V_55 * V_131 = & V_155 -> V_25 . V_131 ;
if ( F_50 ( V_155 -> V_83 ) ) {
V_54 = & V_155 -> V_144 [ V_49 ] ;
V_139 = F_55 ( V_155 , V_54 , V_25 ,
V_156 , V_131 ) ;
if ( F_31 ( V_139 ) )
goto V_161;
}
V_139 = F_45 ( V_155 , V_25 -> V_129 , V_130 ,
V_131 , V_56 ) ;
if ( F_31 ( V_139 ) )
goto V_161;
V_25 -> V_129 -> V_162 = 1 ;
}
return 0 ;
V_161:
if ( V_25 )
V_6 -> V_13 -> V_81 ( V_22 , V_25 ) ;
return V_139 ;
}
void F_58 ( struct V_42 * V_155 ,
enum V_44 V_49 )
{
struct V_5 * V_6 = V_155 -> V_50 -> V_22 . V_6 ;
V_6 -> V_13 -> V_163 ( V_155 , V_49 ) ;
}
