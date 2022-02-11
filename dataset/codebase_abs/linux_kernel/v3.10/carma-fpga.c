static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_6 ( & V_7 -> V_8 ) ;
F_4 ( V_7 ) ;
}
static struct V_6 * F_7 ( const T_1 V_9 )
{
unsigned int V_10 ;
struct V_6 * V_7 ;
int V_11 ;
V_10 = F_8 ( V_9 , V_12 ) ;
V_7 = F_9 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
goto V_14;
F_10 ( & V_7 -> V_15 ) ;
V_7 -> V_16 = V_9 ;
F_11 ( & V_7 -> V_8 ) ;
V_11 = F_12 ( & V_7 -> V_8 , V_17 , V_10 ) ;
if ( V_11 )
goto V_18;
return V_7 ;
V_18:
F_4 ( V_7 ) ;
V_14:
return NULL ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_6 * V_7 , * V_19 ;
F_14 ( V_4 -> V_20 != NULL ) ;
F_15 (buf, tmp, &priv->free, entry) {
F_16 ( & V_7 -> V_15 ) ;
F_17 ( V_4 -> V_21 , & V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
F_15 (buf, tmp, &priv->used, entry) {
F_16 ( & V_7 -> V_15 ) ;
F_17 ( V_4 -> V_21 , & V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
V_4 -> V_22 = 0 ;
V_4 -> V_23 = 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
int V_24 , V_11 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_7 = F_7 ( V_4 -> V_23 ) ;
if ( ! V_7 )
break;
V_11 = F_19 ( V_4 -> V_21 , & V_7 -> V_8 ) ;
if ( V_11 ) {
F_5 ( V_7 ) ;
break;
}
F_20 ( & V_7 -> V_15 , & V_4 -> free ) ;
V_4 -> V_22 ++ ;
}
if ( V_4 -> V_22 < V_26 ) {
F_21 ( V_4 -> V_21 , L_1 ) ;
F_13 ( V_4 ) ;
return - V_27 ;
}
if ( V_4 -> V_22 < V_25 ) {
F_22 ( V_4 -> V_21 ,
L_2 ,
V_25 , V_24 ) ;
}
return 0 ;
}
static T_2 F_23 ( struct V_3 * V_4 , unsigned int V_28 )
{
return V_4 -> V_29 + 0x400000 + ( 0x80000 * V_28 ) ;
}
static T_2 F_24 ( struct V_3 * V_4 , unsigned int V_28 ,
unsigned int V_30 )
{
return F_23 ( V_4 , V_28 ) + ( 0x10000 * ( 1 + V_30 ) ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & V_4 -> V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_24 , V_38 , V_11 ;
V_4 -> V_39 = ( 1 + V_40 ) * V_41 ;
for ( V_24 = 0 ; V_24 < V_40 ; V_24 ++ )
V_4 -> V_39 += V_4 -> V_37 [ V_24 ] . V_42 ;
V_11 = F_26 ( V_32 , V_4 -> V_39 , V_13 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_3 ) ;
return V_11 ;
}
V_35 = V_32 -> V_43 ;
for ( V_24 = 0 ; V_24 < V_40 ; V_24 ++ ) {
F_27 ( V_35 ) = F_23 ( V_4 , V_24 ) ;
F_28 ( V_35 ) = V_41 ;
V_35 = F_29 ( V_35 ) ;
}
F_27 ( V_35 ) = V_44 ;
F_28 ( V_35 ) = V_41 ;
V_35 = F_29 ( V_35 ) ;
for ( V_24 = 0 ; V_24 < V_40 ; V_24 ++ ) {
V_37 = & V_4 -> V_37 [ V_24 ] ;
for ( V_38 = 0 ; V_38 < V_37 -> V_42 ; V_38 ++ ) {
F_27 ( V_35 ) = F_24 ( V_4 , V_24 , V_38 ) ;
F_28 ( V_35 ) = V_37 -> V_45 ;
V_35 = F_29 ( V_35 ) ;
}
}
return 0 ;
}
static void F_30 ( struct V_3 * V_4 , unsigned int V_28 ,
unsigned int V_46 , T_3 V_47 )
{
const int V_48 = V_49 + ( V_28 * V_50 ) ;
F_31 ( V_47 , V_4 -> V_51 + V_48 + V_46 ) ;
}
static T_3 F_32 ( struct V_3 * V_4 , unsigned int V_28 ,
unsigned int V_46 )
{
const int V_48 = V_49 + ( V_28 * V_50 ) ;
return F_33 ( V_4 -> V_51 + V_48 + V_46 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
T_3 V_52 , V_53 , V_54 , V_55 , V_56 ;
T_3 V_57 , V_58 , V_59 ;
T_3 V_42 , V_45 ;
int V_24 ;
V_4 -> V_23 = ( 1 + V_40 ) * V_41 ;
for ( V_24 = 0 ; V_24 < V_40 ; V_24 ++ ) {
V_59 = F_32 ( V_4 , V_24 , V_60 ) ;
V_57 = F_32 ( V_4 , V_24 , V_61 ) ;
V_58 = F_32 ( V_4 , V_24 , V_62 ) ;
if ( ( V_59 & 0x000000FF ) >= 2 ) {
V_52 = ( V_57 & 0x000000F0 ) >> 4 ;
V_56 = ( V_57 & 0x00000F00 ) >> 8 ;
V_53 = ( V_57 & 0x00FFF000 ) >> 12 ;
V_54 = ( V_57 & 0x7F000000 ) >> 24 ;
V_55 = ( V_58 & 0x00000FFF ) >> 0 ;
} else {
V_52 = ( V_57 & 0x000000F0 ) >> 4 ;
V_56 = 1 ;
V_53 = ( V_57 & 0x000FFF00 ) >> 8 ;
V_54 = ( V_57 & 0x7FF00000 ) >> 20 ;
V_55 = ( V_58 & 0x00000FFF ) >> 0 ;
}
V_42 = ( V_52 + V_56 - 1 ) / V_56 ;
V_45 = ( ( V_56 * V_53 ) + V_54 + V_55 ) * 8 ;
V_4 -> V_37 [ V_24 ] . V_42 = V_42 ;
V_4 -> V_37 [ V_24 ] . V_45 = V_45 ;
V_4 -> V_23 += V_42 * V_45 ;
F_35 ( V_4 -> V_21 , L_4 , V_24 , V_52 ) ;
F_35 ( V_4 -> V_21 , L_5 , V_24 , V_56 ) ;
F_35 ( V_4 -> V_21 , L_6 , V_24 , V_53 ) ;
F_35 ( V_4 -> V_21 , L_7 , V_24 , V_54 ) ;
F_35 ( V_4 -> V_21 , L_8 , V_24 , V_55 ) ;
F_35 ( V_4 -> V_21 , L_9 , V_24 , V_45 ) ;
}
F_35 ( V_4 -> V_21 , L_10 , V_4 -> V_23 ) ;
return 0 ;
}
static void F_36 ( struct V_3 * V_4 )
{
F_31 ( 0x2F , V_4 -> V_51 + V_63 ) ;
}
static void F_37 ( struct V_3 * V_4 )
{
F_30 ( V_4 , 0 , V_64 , 0x0 ) ;
F_30 ( V_4 , 1 , V_64 , 0x0 ) ;
F_30 ( V_4 , 2 , V_64 , 0x0 ) ;
F_30 ( V_4 , 3 , V_64 , 0x0 ) ;
F_32 ( V_4 , 0 , V_64 ) ;
F_32 ( V_4 , 1 , V_64 ) ;
F_32 ( V_4 , 2 , V_64 ) ;
F_32 ( V_4 , 3 , V_64 ) ;
F_31 ( 0x3F , V_4 -> V_51 + V_63 ) ;
}
static void F_38 ( void * V_65 )
{
struct V_3 * V_4 = V_65 ;
unsigned long V_66 ;
F_39 ( & V_4 -> V_67 , V_66 ) ;
F_14 ( V_4 -> V_20 == NULL ) ;
F_40 ( & V_4 -> V_20 -> V_15 , & V_4 -> V_68 ) ;
V_4 -> V_20 = NULL ;
if ( V_4 -> V_69 )
F_37 ( V_4 ) ;
F_41 ( & V_4 -> V_67 , V_66 ) ;
F_42 ( & V_4 -> V_70 ) ;
}
static int F_43 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
struct V_34 * V_71 , * V_72 ;
unsigned int V_73 , V_74 ;
struct V_75 * V_76 = V_4 -> V_76 ;
struct V_77 * V_78 ;
T_4 V_79 ;
T_2 V_80 , V_81 ;
unsigned long V_82 = V_83 |
V_84 ;
V_71 = V_7 -> V_8 . V_85 ;
V_73 = V_7 -> V_8 . V_86 ;
V_72 = V_4 -> V_33 . V_43 ;
V_74 = V_4 -> V_39 ;
V_78 = V_76 -> V_87 -> V_88 ( V_76 ,
V_71 , V_73 ,
V_72 , V_74 ,
0 ) ;
if ( ! V_78 ) {
F_21 ( V_4 -> V_21 , L_11 ) ;
return - V_27 ;
}
V_79 = V_78 -> V_89 ( V_78 ) ;
if ( F_44 ( V_79 ) ) {
F_21 ( V_4 -> V_21 , L_12 ) ;
return - V_27 ;
}
V_80 = F_27 ( V_71 ) + ( V_40 * V_41 ) ;
V_81 = V_44 ;
V_78 = V_76 -> V_87 -> V_90 ( V_76 , V_80 , V_81 ,
V_41 ,
V_82 ) ;
if ( ! V_78 ) {
F_21 ( V_4 -> V_21 , L_13 ) ;
return - V_27 ;
}
V_78 -> V_91 = F_38 ;
V_78 -> V_92 = V_4 ;
V_79 = V_78 -> V_89 ( V_78 ) ;
if ( F_44 ( V_79 ) ) {
F_21 ( V_4 -> V_21 , L_14 ) ;
return - V_27 ;
}
return 0 ;
}
static T_5 F_45 ( int V_93 , void * V_94 )
{
struct V_3 * V_4 = V_94 ;
bool V_95 = false ;
struct V_6 * V_7 ;
T_3 V_96 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_96 = F_32 ( V_4 , V_24 , V_64 ) ;
if ( ! ( V_96 & ( V_97 | V_98 ) ) ) {
F_21 ( V_4 -> V_21 , L_15 ) ;
return V_99 ;
}
}
V_96 = F_33 ( V_4 -> V_51 + V_100 ) ;
if ( V_96 & V_101 ) {
F_21 ( V_4 -> V_21 , L_16 ) ;
return V_99 ;
}
F_46 ( & V_4 -> V_67 ) ;
F_14 ( V_4 -> V_20 != NULL ) ;
F_36 ( V_4 ) ;
if ( F_47 ( & V_4 -> free ) ) {
V_4 -> V_102 ++ ;
goto V_103;
}
V_7 = F_48 ( & V_4 -> free , struct V_6 , V_15 ) ;
F_16 ( & V_7 -> V_15 ) ;
F_14 ( V_7 -> V_16 != V_4 -> V_23 ) ;
if ( F_43 ( V_4 , V_7 ) ) {
F_21 ( V_4 -> V_21 , L_17 ) ;
F_40 ( & V_7 -> V_15 , & V_4 -> free ) ;
goto V_103;
}
V_4 -> V_20 = V_7 ;
V_95 = true ;
F_49 ( V_4 -> V_76 ) ;
V_103:
if ( ! V_95 )
F_37 ( V_4 ) ;
F_50 ( & V_4 -> V_67 ) ;
return V_104 ;
}
static int F_51 ( struct V_3 * V_4 )
{
bool V_69 ;
T_3 V_47 ;
int V_11 ;
F_52 ( & V_4 -> V_67 ) ;
V_69 = V_4 -> V_69 ;
F_53 ( & V_4 -> V_67 ) ;
if ( V_69 )
return 0 ;
V_47 = F_33 ( V_4 -> V_51 + V_105 ) ;
if ( ! ( V_47 & ( 1 << 18 ) ) ) {
F_21 ( V_4 -> V_21 , L_18 ) ;
return - V_106 ;
}
V_11 = F_34 ( V_4 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_19 ) ;
goto V_107;
}
V_11 = F_18 ( V_4 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_20 ) ;
goto V_107;
}
V_11 = F_25 ( V_4 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_21 ) ;
goto V_107;
}
F_36 ( V_4 ) ;
V_11 = F_54 ( V_4 -> V_93 , F_45 , V_108 , V_109 , V_4 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_22 ) ;
goto V_107;
}
F_52 ( & V_4 -> V_67 ) ;
V_4 -> V_69 = true ;
F_53 ( & V_4 -> V_67 ) ;
F_37 ( V_4 ) ;
return 0 ;
V_107:
F_55 ( & V_4 -> V_33 ) ;
V_4 -> V_39 = 0 ;
F_13 ( V_4 ) ;
return V_11 ;
}
static int F_56 ( struct V_3 * V_4 )
{
F_52 ( & V_4 -> V_67 ) ;
if ( ! V_4 -> V_69 ) {
F_53 ( & V_4 -> V_67 ) ;
return 0 ;
}
V_4 -> V_69 = false ;
F_36 ( V_4 ) ;
while ( V_4 -> V_20 != NULL ) {
F_53 ( & V_4 -> V_67 ) ;
F_57 ( V_4 -> V_70 , V_4 -> V_20 == NULL ) ;
F_52 ( & V_4 -> V_67 ) ;
}
F_53 ( & V_4 -> V_67 ) ;
F_58 ( V_4 -> V_93 , V_4 ) ;
F_55 ( & V_4 -> V_33 ) ;
V_4 -> V_39 = 0 ;
F_13 ( V_4 ) ;
return 0 ;
}
static unsigned int F_59 ( struct V_110 * V_111 )
{
struct V_110 * V_15 ;
unsigned int V_11 = 0 ;
F_60 (entry, list)
V_11 ++ ;
return V_11 ;
}
static int F_61 ( struct V_112 * V_113 , void * V_114 )
{
struct V_3 * V_4 = V_113 -> V_115 ;
F_52 ( & V_4 -> V_67 ) ;
F_62 ( V_113 , L_23 , V_4 -> V_69 ) ;
F_62 ( V_113 , L_24 , V_4 -> V_23 ) ;
F_62 ( V_113 , L_25 , V_4 -> V_22 ) ;
F_62 ( V_113 , L_26 , F_59 ( & V_4 -> free ) ) ;
F_62 ( V_113 , L_27 , V_4 -> V_20 != NULL ) ;
F_62 ( V_113 , L_28 , F_59 ( & V_4 -> V_68 ) ) ;
F_62 ( V_113 , L_29 , V_4 -> V_102 ) ;
F_53 ( & V_4 -> V_67 ) ;
return 0 ;
}
static int F_63 ( struct V_116 * V_116 , struct V_117 * V_117 )
{
return F_64 ( V_117 , F_61 , V_116 -> V_118 ) ;
}
static int F_65 ( struct V_3 * V_4 )
{
V_4 -> V_119 = F_66 ( V_109 , V_120 , NULL , V_4 ,
& V_121 ) ;
if ( F_67 ( V_4 -> V_119 ) )
return F_68 ( V_4 -> V_119 ) ;
return 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
F_70 ( V_4 -> V_119 ) ;
}
static inline int F_65 ( struct V_3 * V_4 )
{
return 0 ;
}
static inline void F_69 ( struct V_3 * V_4 )
{
}
static T_6 F_71 ( struct V_87 * V_21 , struct V_122 * V_123 ,
char * V_7 )
{
struct V_3 * V_4 = F_72 ( V_21 ) ;
int V_11 ;
F_52 ( & V_4 -> V_67 ) ;
V_11 = snprintf ( V_7 , V_12 , L_30 , V_4 -> V_69 ) ;
F_53 ( & V_4 -> V_67 ) ;
return V_11 ;
}
static T_6 F_73 ( struct V_87 * V_21 , struct V_122 * V_123 ,
const char * V_7 , T_1 V_124 )
{
struct V_3 * V_4 = F_72 ( V_21 ) ;
unsigned long V_125 ;
int V_11 ;
V_11 = F_74 ( V_7 , 0 , & V_125 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_31 ) ;
return - V_126 ;
}
V_11 = F_75 ( & V_4 -> V_5 ) ;
if ( V_11 )
return V_11 ;
if ( V_125 )
V_11 = F_51 ( V_4 ) ;
else
V_11 = F_56 ( V_4 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_32 ,
V_125 ? L_33 : L_34 ) ;
V_124 = V_11 ;
goto V_127;
}
V_127:
F_76 ( & V_4 -> V_5 ) ;
return V_124 ;
}
static int F_77 ( struct V_116 * V_116 , struct V_117 * V_128 )
{
struct V_3 * V_4 = F_2 ( V_128 -> V_129 ,
struct V_3 , V_130 ) ;
struct V_131 * V_132 ;
int V_11 ;
V_132 = F_9 ( sizeof( * V_132 ) , V_13 ) ;
if ( ! V_132 )
return - V_27 ;
V_132 -> V_4 = V_4 ;
V_132 -> V_7 = NULL ;
V_128 -> V_129 = V_132 ;
V_11 = F_78 ( V_116 , V_128 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_35 ) ;
F_4 ( V_132 ) ;
return V_11 ;
}
F_79 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_116 * V_116 , struct V_117 * V_128 )
{
struct V_131 * V_132 = V_128 -> V_129 ;
struct V_3 * V_4 = V_132 -> V_4 ;
F_5 ( V_132 -> V_7 ) ;
F_4 ( V_132 ) ;
V_128 -> V_129 = NULL ;
F_81 ( & V_4 -> V_2 , F_1 ) ;
return 0 ;
}
static T_6 F_82 ( struct V_117 * V_128 , char T_7 * V_133 , T_1 V_124 ,
T_8 * V_134 )
{
struct V_131 * V_132 = V_128 -> V_129 ;
struct V_3 * V_4 = V_132 -> V_4 ;
struct V_110 * V_68 = & V_4 -> V_68 ;
bool V_135 = false ;
struct V_6 * V_136 ;
T_1 V_137 ;
void * V_65 ;
int V_11 ;
if ( V_132 -> V_7 ) {
V_136 = V_132 -> V_7 ;
goto V_138;
}
F_52 ( & V_4 -> V_67 ) ;
while ( F_47 ( V_68 ) ) {
F_53 ( & V_4 -> V_67 ) ;
if ( V_128 -> V_139 & V_140 )
return - V_141 ;
V_11 = F_83 ( V_4 -> V_70 , ! F_47 ( V_68 ) ) ;
if ( V_11 )
return V_11 ;
F_52 ( & V_4 -> V_67 ) ;
}
V_136 = F_48 ( V_68 , struct V_6 , V_15 ) ;
F_16 ( & V_136 -> V_15 ) ;
F_53 ( & V_4 -> V_67 ) ;
F_17 ( V_4 -> V_21 , & V_136 -> V_8 ) ;
V_132 -> V_7 = V_136 ;
V_132 -> V_142 = 0 ;
V_138:
V_137 = V_136 -> V_16 - V_132 -> V_142 ;
V_65 = V_136 -> V_8 . V_143 + V_132 -> V_142 ;
V_124 = F_84 ( V_124 , V_137 ) ;
if ( F_85 ( V_133 , V_65 , V_124 ) )
return - V_144 ;
V_137 -= V_124 ;
if ( V_137 > 0 ) {
V_132 -> V_142 += V_124 ;
V_132 -> V_7 = V_136 ;
return V_124 ;
}
V_11 = F_19 ( V_4 -> V_21 , & V_136 -> V_8 ) ;
if ( V_11 ) {
F_21 ( V_4 -> V_21 , L_36 ) ;
return - V_144 ;
}
F_52 ( & V_4 -> V_67 ) ;
V_132 -> V_7 = NULL ;
if ( ! V_4 -> V_69 || V_136 -> V_16 != V_4 -> V_23 ) {
V_135 = true ;
goto V_127;
}
F_20 ( & V_136 -> V_15 , & V_4 -> free ) ;
V_127:
F_53 ( & V_4 -> V_67 ) ;
if ( V_135 ) {
F_17 ( V_4 -> V_21 , & V_136 -> V_8 ) ;
F_5 ( V_136 ) ;
}
return V_124 ;
}
static unsigned int F_86 ( struct V_117 * V_128 , struct V_145 * V_146 )
{
struct V_131 * V_132 = V_128 -> V_129 ;
struct V_3 * V_4 = V_132 -> V_4 ;
unsigned int V_147 = 0 ;
F_87 ( V_128 , & V_4 -> V_70 , V_146 ) ;
if ( ! F_47 ( & V_4 -> V_68 ) )
V_147 |= V_148 | V_149 ;
return V_147 ;
}
static int F_88 ( struct V_117 * V_128 , struct V_150 * V_151 )
{
struct V_131 * V_132 = V_128 -> V_129 ;
struct V_3 * V_4 = V_132 -> V_4 ;
unsigned long V_114 , V_152 , V_153 , V_154 ;
V_114 = V_151 -> V_155 << V_156 ;
V_152 = V_151 -> V_157 - V_151 -> V_158 ;
V_153 = V_4 -> V_159 - V_114 ;
V_154 = ( V_4 -> V_29 + V_114 ) >> V_156 ;
if ( V_152 > V_153 ) {
F_21 ( V_4 -> V_21 , L_37 ) ;
return - V_126 ;
}
V_151 -> V_160 = F_89 ( V_151 -> V_160 ) ;
return F_90 ( V_151 , V_151 -> V_158 , V_154 , V_152 ,
V_151 -> V_160 ) ;
}
static bool F_91 ( struct V_75 * V_76 , void * V_65 )
{
if ( V_76 -> V_161 == 0 && V_76 -> V_87 -> V_94 == 0 )
return false ;
return true ;
}
static int F_92 ( struct V_162 * V_163 )
{
struct V_164 * V_165 = V_163 -> V_21 . V_165 ;
struct V_87 * V_166 ;
struct V_3 * V_4 ;
struct V_167 V_168 ;
T_9 V_147 ;
int V_11 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 ) {
F_21 ( & V_163 -> V_21 , L_38 ) ;
V_11 = - V_27 ;
goto V_14;
}
F_93 ( & V_163 -> V_21 , V_4 ) ;
V_4 -> V_21 = & V_163 -> V_21 ;
F_94 ( & V_4 -> V_2 ) ;
F_95 ( & V_4 -> V_5 ) ;
F_93 ( V_4 -> V_21 , V_4 ) ;
F_96 ( & V_4 -> V_67 ) ;
F_10 ( & V_4 -> free ) ;
F_10 ( & V_4 -> V_68 ) ;
F_97 ( & V_4 -> V_70 ) ;
V_4 -> V_130 . V_169 = V_170 ;
V_4 -> V_130 . V_171 = V_109 ;
V_4 -> V_130 . V_172 = & V_173 ;
V_11 = F_98 ( V_165 , 0 , & V_168 ) ;
if ( V_11 ) {
F_21 ( & V_163 -> V_21 , L_39 ) ;
V_11 = - V_174 ;
goto V_175;
}
V_4 -> V_29 = V_168 . V_176 ;
V_4 -> V_159 = F_99 ( & V_168 ) ;
V_4 -> V_51 = F_100 ( V_165 , 0 ) ;
if ( ! V_4 -> V_51 ) {
F_21 ( & V_163 -> V_21 , L_40 ) ;
V_11 = - V_27 ;
goto V_175;
}
F_101 ( V_147 ) ;
F_102 ( V_177 , V_147 ) ;
F_102 ( V_178 , V_147 ) ;
F_102 ( V_179 , V_147 ) ;
F_102 ( V_180 , V_147 ) ;
V_4 -> V_76 = F_103 ( V_147 , F_91 , NULL ) ;
if ( ! V_4 -> V_76 ) {
F_21 ( & V_163 -> V_21 , L_41 ) ;
V_11 = - V_174 ;
goto V_181;
}
V_4 -> V_93 = F_104 ( V_165 , 0 ) ;
if ( V_4 -> V_93 == V_182 ) {
F_21 ( & V_163 -> V_21 , L_42 ) ;
V_11 = - V_174 ;
goto V_183;
}
F_31 ( V_101 , V_4 -> V_51 + V_184 ) ;
V_11 = F_105 ( & V_4 -> V_130 ) ;
if ( V_11 ) {
F_21 ( & V_163 -> V_21 , L_43 ) ;
goto V_185;
}
V_11 = F_65 ( V_4 ) ;
if ( V_11 ) {
F_21 ( & V_163 -> V_21 , L_44 ) ;
goto V_186;
}
V_166 = V_4 -> V_130 . V_166 ;
F_93 ( V_166 , V_4 ) ;
V_11 = F_106 ( & V_166 -> V_187 , & V_188 ) ;
if ( V_11 ) {
F_21 ( & V_163 -> V_21 , L_45 ) ;
goto V_189;
}
F_107 ( & V_163 -> V_21 , L_46 ) ;
return 0 ;
V_189:
F_69 ( V_4 ) ;
V_186:
F_108 ( & V_4 -> V_130 ) ;
V_185:
F_109 ( V_4 -> V_93 ) ;
V_183:
F_110 ( V_4 -> V_76 ) ;
V_181:
F_111 ( V_4 -> V_51 ) ;
V_175:
F_81 ( & V_4 -> V_2 , F_1 ) ;
V_14:
return V_11 ;
}
static int F_112 ( struct V_162 * V_163 )
{
struct V_3 * V_4 = F_72 ( & V_163 -> V_21 ) ;
struct V_87 * V_166 = V_4 -> V_130 . V_166 ;
F_113 ( & V_166 -> V_187 , & V_188 ) ;
F_69 ( V_4 ) ;
F_56 ( V_4 ) ;
F_108 ( & V_4 -> V_130 ) ;
F_109 ( V_4 -> V_93 ) ;
F_110 ( V_4 -> V_76 ) ;
F_111 ( V_4 -> V_51 ) ;
F_81 ( & V_4 -> V_2 , F_1 ) ;
return 0 ;
}
