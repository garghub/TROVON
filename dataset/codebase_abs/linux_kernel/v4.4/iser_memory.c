int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
if ( V_2 -> V_5 -> V_6 && V_2 -> V_5 -> V_7 &&
V_2 -> V_5 -> V_8 && V_2 -> V_5 -> V_9 ) {
F_2 ( L_1 ) ;
V_2 -> V_10 = & V_11 ;
} else
if ( V_4 -> V_12 & V_13 ) {
F_2 ( L_2 ) ;
V_2 -> V_10 = & V_14 ;
} else {
F_3 ( L_3 ) ;
return - 1 ;
}
return 0 ;
}
struct V_15 *
F_4 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_15 * V_19 ;
unsigned long V_20 ;
F_5 ( & V_18 -> V_21 , V_20 ) ;
V_19 = F_6 ( & V_18 -> V_22 ,
struct V_15 , V_22 ) ;
F_7 ( & V_19 -> V_22 ) ;
F_8 ( & V_18 -> V_21 , V_20 ) ;
return V_19 ;
}
void
F_9 ( struct V_16 * V_16 ,
struct V_15 * V_19 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
unsigned long V_20 ;
F_5 ( & V_18 -> V_21 , V_20 ) ;
F_10 ( & V_19 -> V_22 , & V_18 -> V_22 ) ;
F_8 ( & V_18 -> V_21 , V_20 ) ;
}
struct V_15 *
F_11 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
return F_6 ( & V_18 -> V_22 ,
struct V_15 , V_22 ) ;
}
void
F_12 ( struct V_16 * V_16 ,
struct V_15 * V_19 )
{
}
static int F_13 ( struct V_23 * V_24 ,
struct V_5 * V_25 , T_1 * V_26 ,
int * V_27 , int * V_28 )
{
struct V_29 * V_30 , * V_31 = V_24 -> V_30 ;
T_1 V_32 , V_33 , V_34 , V_35 = 0 ;
unsigned long V_36 = 0 ;
unsigned int V_37 ;
int V_38 , V_39 , V_40 , V_41 = V_24 -> V_42 - 1 ;
* V_27 = ( T_1 ) V_31 [ 0 ] . V_27 & ~ V_43 ;
V_39 = 1 ;
V_40 = 0 ;
F_14 (sgl, sg, data->dma_nents, i) {
V_32 = F_15 ( V_25 , V_30 ) ;
if ( V_39 )
V_35 = V_32 ;
V_37 = F_16 ( V_25 , V_30 ) ;
V_33 = V_32 + V_37 ;
V_36 += V_37 ;
if ( ! F_17 ( V_33 ) && V_38 < V_41 ) {
V_39 = 0 ;
continue;
}
V_39 = 1 ;
V_34 = V_35 & V_43 ;
do {
V_26 [ V_40 ++ ] = V_34 ;
V_34 += V_44 ;
} while ( V_34 < V_33 );
}
* V_28 = V_36 ;
F_18 ( L_4 ,
* V_28 , V_40 ) ;
return V_40 ;
}
static void F_19 ( struct V_23 * V_24 ,
struct V_5 * V_25 )
{
struct V_29 * V_30 ;
int V_38 ;
F_14 (data->sg, sg, data->dma_nents, i)
F_18 ( L_5
L_6 ,
V_38 , ( unsigned long ) F_15 ( V_25 , V_30 ) ,
F_20 ( V_30 ) , V_30 -> V_27 ,
V_30 -> V_45 , F_16 ( V_25 , V_30 ) ) ;
}
static void F_21 ( struct V_46 * V_47 )
{
int V_38 ;
F_3 ( L_7 ,
V_47 -> V_45 , V_47 -> V_28 ) ;
for ( V_38 = 0 ; V_38 < V_47 -> V_45 ; V_38 ++ )
F_3 ( L_8 , V_38 , ( unsigned long ) V_47 -> V_26 [ V_38 ] ) ;
}
int F_22 ( struct V_48 * V_49 ,
struct V_23 * V_24 ,
enum V_50 V_51 ,
enum V_52 V_53 )
{
struct V_5 * V_54 ;
V_49 -> V_55 [ V_51 ] = 1 ;
V_54 = V_49 -> V_56 -> V_16 . V_2 -> V_5 ;
V_24 -> V_42 = F_23 ( V_54 , V_24 -> V_30 , V_24 -> V_57 , V_53 ) ;
if ( V_24 -> V_42 == 0 ) {
F_3 ( L_9 ) ;
return - V_58 ;
}
return 0 ;
}
void F_24 ( struct V_48 * V_49 ,
struct V_23 * V_24 ,
enum V_52 V_55 )
{
struct V_5 * V_54 ;
V_54 = V_49 -> V_56 -> V_16 . V_2 -> V_5 ;
F_25 ( V_54 , V_24 -> V_30 , V_24 -> V_57 , V_55 ) ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_23 * V_59 ,
struct V_60 * V_61 )
{
struct V_29 * V_30 = V_59 -> V_30 ;
V_61 -> V_62 . V_63 = V_2 -> V_64 -> V_65 ;
V_61 -> V_66 = V_2 -> V_67 -> V_66 ;
V_61 -> V_62 . V_68 = F_15 ( V_2 -> V_5 , & V_30 [ 0 ] ) ;
V_61 -> V_62 . V_45 = F_16 ( V_2 -> V_5 , & V_30 [ 0 ] ) ;
F_18 ( L_10
L_11 , V_61 -> V_62 . V_63 , V_61 -> V_66 ,
V_61 -> V_62 . V_68 , V_61 -> V_62 . V_45 ) ;
return 0 ;
}
static
int F_27 ( struct V_48 * V_49 ,
struct V_23 * V_59 ,
struct V_69 * V_70 ,
struct V_60 * V_61 )
{
struct V_16 * V_16 = & V_49 -> V_56 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_46 * V_47 = V_70 -> V_47 ;
struct V_71 * V_72 = V_70 -> V_72 ;
struct V_73 * V_74 ;
int V_75 , V_76 ;
V_76 = F_13 ( V_59 , V_2 -> V_5 ,
V_47 -> V_26 ,
& V_47 -> V_27 ,
& V_47 -> V_28 ) ;
V_47 -> V_45 = V_76 ;
if ( V_76 * V_44 < V_47 -> V_28 ) {
F_3 ( L_12 ) ;
F_19 ( V_59 , V_2 -> V_5 ) ;
F_21 ( V_47 ) ;
return - V_58 ;
}
V_74 = F_28 ( V_72 ,
V_47 -> V_26 ,
V_47 -> V_45 ,
V_47 -> V_26 [ 0 ] ) ;
if ( F_29 ( V_74 ) ) {
V_75 = F_30 ( V_74 ) ;
F_3 ( L_13 , V_75 ) ;
return V_75 ;
}
V_61 -> V_62 . V_63 = V_74 -> V_74 -> V_63 ;
V_61 -> V_66 = V_74 -> V_74 -> V_66 ;
V_61 -> V_62 . V_68 = V_47 -> V_26 [ 0 ] + V_47 -> V_27 ;
V_61 -> V_62 . V_45 = V_47 -> V_28 ;
V_61 -> V_77 = V_74 ;
F_18 ( L_14
L_11 , V_61 -> V_62 . V_63 , V_61 -> V_66 ,
V_61 -> V_62 . V_68 , V_61 -> V_62 . V_45 ) ;
return 0 ;
}
void F_31 ( struct V_48 * V_49 ,
enum V_50 V_78 )
{
struct V_60 * V_61 = & V_49 -> V_79 [ V_78 ] ;
int V_75 ;
if ( ! V_61 -> V_77 )
return;
F_18 ( L_15 , V_61 -> V_77 ) ;
V_75 = F_32 ( (struct V_73 * ) V_61 -> V_77 ) ;
if ( V_75 )
F_3 ( L_16 , V_75 ) ;
V_61 -> V_77 = NULL ;
}
void F_33 ( struct V_48 * V_49 ,
enum V_50 V_78 )
{
struct V_1 * V_2 = V_49 -> V_56 -> V_16 . V_2 ;
struct V_60 * V_61 = & V_49 -> V_79 [ V_78 ] ;
if ( ! V_61 -> V_77 )
return;
V_2 -> V_10 -> V_80 ( & V_49 -> V_56 -> V_16 ,
V_61 -> V_77 ) ;
V_61 -> V_77 = NULL ;
}
static void
F_34 ( struct V_81 * V_82 , struct V_83 * V_84 ,
struct V_85 * V_86 )
{
V_86 -> V_87 = V_88 ;
V_86 -> V_89 . V_90 . V_91 = F_35 ( V_82 ) ;
V_86 -> V_89 . V_90 . V_92 = F_36 ( V_82 ) ;
V_86 -> V_89 . V_90 . V_93 = 0xffff ;
V_86 -> V_89 . V_90 . V_94 = true ;
V_86 -> V_89 . V_90 . V_95 = true ;
if ( V_82 -> V_96 & V_97 )
V_86 -> V_89 . V_90 . V_98 = true ;
}
static int
F_37 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
switch ( F_38 ( V_82 ) ) {
case V_99 :
case V_100 :
V_84 -> V_59 . V_87 = V_101 ;
F_34 ( V_82 , V_84 , & V_84 -> V_102 ) ;
V_84 -> V_102 . V_89 . V_90 . V_103 = V_104 ;
break;
case V_105 :
case V_106 :
V_84 -> V_102 . V_87 = V_101 ;
F_34 ( V_82 , V_84 , & V_84 -> V_59 ) ;
V_84 -> V_59 . V_89 . V_90 . V_103 = V_82 -> V_96 & V_107 ?
V_108 : V_104 ;
break;
case V_109 :
case V_110 :
F_34 ( V_82 , V_84 , & V_84 -> V_102 ) ;
V_84 -> V_102 . V_89 . V_90 . V_103 = V_104 ;
F_34 ( V_82 , V_84 , & V_84 -> V_59 ) ;
V_84 -> V_59 . V_89 . V_90 . V_103 = V_82 -> V_96 & V_107 ?
V_108 : V_104 ;
break;
default:
F_3 ( L_17 ,
F_38 ( V_82 ) ) ;
return - V_58 ;
}
return 0 ;
}
static inline void
F_39 ( struct V_81 * V_82 , T_2 * V_111 )
{
* V_111 = 0 ;
if ( V_82 -> V_96 & V_112 )
* V_111 |= V_113 ;
if ( V_82 -> V_96 & V_114 )
* V_111 |= V_115 ;
}
static void
F_40 ( struct V_116 * V_117 , struct V_118 * V_67 )
{
T_3 V_66 ;
V_117 -> V_119 = V_120 ;
V_117 -> V_121 = V_122 ;
V_117 -> V_123 . V_124 = V_67 -> V_66 ;
V_117 -> V_125 = 0 ;
V_117 -> V_126 = 0 ;
V_66 = F_41 ( V_67 -> V_66 ) ;
F_42 ( V_67 , V_66 ) ;
}
static int
F_43 ( struct V_48 * V_49 ,
struct V_127 * V_128 ,
struct V_60 * V_129 ,
struct V_60 * V_130 ,
struct V_60 * V_131 )
{
struct V_132 * V_133 = & V_49 -> V_19 ;
struct V_83 * V_84 = & V_133 -> V_84 ;
struct V_134 * V_135 ;
int V_75 ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_75 = F_37 ( V_49 -> V_82 , V_84 ) ;
if ( V_75 )
goto V_136;
F_39 ( V_49 -> V_82 , & V_84 -> V_137 ) ;
if ( ! V_128 -> V_138 )
F_40 ( F_44 ( V_133 ) , V_128 -> V_139 ) ;
V_135 = F_45 ( F_44 ( V_133 ) ) ;
V_135 -> V_135 . V_119 = V_140 ;
V_135 -> V_135 . V_121 = V_122 ;
V_135 -> V_135 . V_141 = & V_129 -> V_62 ;
V_135 -> V_135 . V_126 = 1 ;
V_135 -> V_135 . V_125 = 0 ;
V_135 -> V_84 = V_84 ;
V_135 -> V_139 = V_128 -> V_139 ;
if ( F_46 ( V_49 -> V_82 ) )
V_135 -> V_142 = & V_130 -> V_62 ;
else
V_135 -> V_142 = NULL ;
V_135 -> V_143 = V_144 |
V_145 |
V_146 ;
V_128 -> V_138 = 0 ;
V_131 -> V_62 . V_63 = V_128 -> V_139 -> V_63 ;
V_131 -> V_66 = V_128 -> V_139 -> V_66 ;
V_131 -> V_62 . V_68 = 0 ;
V_131 -> V_62 . V_45 = F_47 ( V_49 -> V_82 ) ;
F_18 ( L_18 ,
V_131 -> V_62 . V_63 , V_131 -> V_66 , V_131 -> V_62 . V_68 ,
V_131 -> V_62 . V_45 ) ;
V_136:
return V_75 ;
}
static int F_48 ( struct V_48 * V_49 ,
struct V_23 * V_59 ,
struct V_69 * V_70 ,
struct V_60 * V_61 )
{
struct V_132 * V_133 = & V_49 -> V_19 ;
struct V_118 * V_67 = V_70 -> V_67 ;
struct V_147 * V_135 ;
int V_148 ;
if ( ! V_70 -> V_149 )
F_40 ( F_44 ( V_133 ) , V_67 ) ;
V_148 = F_49 ( V_67 , V_59 -> V_30 , V_59 -> V_57 , V_44 ) ;
if ( F_50 ( V_148 != V_59 -> V_57 ) ) {
F_3 ( L_19 ,
V_148 , V_59 -> V_57 ) ;
return V_148 < 0 ? V_148 : - V_58 ;
}
V_135 = F_51 ( F_44 ( V_133 ) ) ;
V_135 -> V_135 . V_119 = V_150 ;
V_135 -> V_135 . V_121 = V_122 ;
V_135 -> V_135 . V_125 = 0 ;
V_135 -> V_135 . V_126 = 0 ;
V_135 -> V_67 = V_67 ;
V_135 -> V_151 = V_67 -> V_66 ;
V_135 -> V_152 = V_144 |
V_146 |
V_145 ;
V_70 -> V_149 = 0 ;
V_61 -> V_62 . V_63 = V_67 -> V_63 ;
V_61 -> V_66 = V_67 -> V_66 ;
V_61 -> V_62 . V_68 = V_67 -> V_153 ;
V_61 -> V_62 . V_45 = V_67 -> V_45 ;
F_18 ( L_20 ,
V_61 -> V_62 . V_63 , V_61 -> V_66 , V_61 -> V_62 . V_68 , V_61 -> V_62 . V_45 ) ;
return 0 ;
}
static int
F_52 ( struct V_48 * V_154 ,
struct V_23 * V_59 ,
struct V_15 * V_19 ,
bool V_155 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = V_154 -> V_56 -> V_16 . V_2 ;
if ( V_155 )
return F_26 ( V_2 , V_59 , V_61 ) ;
return V_2 -> V_10 -> V_156 ( V_154 , V_59 , & V_19 -> V_128 -> V_70 , V_61 ) ;
}
static int
F_53 ( struct V_48 * V_154 ,
struct V_23 * V_59 ,
struct V_15 * V_19 ,
bool V_155 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = V_154 -> V_56 -> V_16 . V_2 ;
if ( V_155 )
return F_26 ( V_2 , V_59 , V_61 ) ;
return V_2 -> V_10 -> V_156 ( V_154 , V_59 , & V_19 -> V_70 , V_61 ) ;
}
int F_54 ( struct V_48 * V_154 ,
enum V_50 V_55 )
{
struct V_16 * V_16 = & V_154 -> V_56 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_23 * V_59 = & V_154 -> V_24 [ V_55 ] ;
struct V_60 * V_61 = & V_154 -> V_79 [ V_55 ] ;
struct V_60 * V_129 ;
struct V_15 * V_19 = NULL ;
bool V_155 ;
int V_136 ;
V_155 = ( V_59 -> V_42 == 1 && ! V_157 &&
F_38 ( V_154 -> V_82 ) == V_158 ) ;
if ( ! V_155 ) {
V_19 = V_2 -> V_10 -> V_159 ( V_16 ) ;
V_61 -> V_77 = V_19 ;
}
if ( F_38 ( V_154 -> V_82 ) == V_158 )
V_129 = V_61 ;
else
V_129 = & V_154 -> V_19 . V_129 ;
V_136 = F_53 ( V_154 , V_59 , V_19 , V_155 , V_129 ) ;
if ( F_50 ( V_136 ) )
goto V_160;
if ( F_38 ( V_154 -> V_82 ) != V_158 ) {
struct V_60 * V_130 = & V_154 -> V_19 . V_130 ;
if ( F_46 ( V_154 -> V_82 ) ) {
V_59 = & V_154 -> V_142 [ V_55 ] ;
V_136 = F_52 ( V_154 , V_59 , V_19 ,
V_155 , V_130 ) ;
if ( F_50 ( V_136 ) )
goto V_160;
}
V_136 = F_43 ( V_154 , V_19 -> V_128 , V_129 ,
V_130 , V_61 ) ;
if ( F_50 ( V_136 ) )
goto V_160;
V_19 -> V_128 -> V_161 = 1 ;
}
return 0 ;
V_160:
if ( V_19 )
V_2 -> V_10 -> V_80 ( V_16 , V_19 ) ;
return V_136 ;
}
void F_55 ( struct V_48 * V_154 ,
enum V_50 V_55 )
{
struct V_1 * V_2 = V_154 -> V_56 -> V_16 . V_2 ;
V_2 -> V_10 -> V_162 ( V_154 , V_55 ) ;
}
