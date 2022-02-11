static struct V_1 * V_1 ( unsigned int V_2 )
{
struct V_3 * V_4 = F_1 ( V_2 ) ;
return V_4 ? & V_4 -> V_1 : NULL ;
}
static int F_2 ( int V_2 , struct V_5 * V_6 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_6 || ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_9 = V_7 -> V_11 + V_7 -> V_12 ;
* V_6 = * ( V_7 -> V_13 -> V_14 -> V_15 + V_9 ) ;
F_4 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_16 * V_13 , int V_2 , T_1 V_17 )
{
struct V_14 * V_18 = V_13 -> V_14 ;
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = F_1 ( V_2 ) ;
unsigned int V_19 = 0 ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_17 || ! V_7 )
return - 1 ;
if ( V_17 > 1 ) {
V_17 = F_6 ( V_17 ) ;
V_19 = F_7 ( V_17 ) ;
}
if ( V_19 > F_8 ( V_13 -> V_20 ) ) {
F_9 ( V_21
L_1
L_2 , V_19 ,
F_8 ( V_13 -> V_20 ) ) ;
return - 1 ;
}
F_3 ( & V_10 , V_8 ) ;
V_9 = F_10 ( V_18 -> V_22 ,
V_23 , V_19 ) ;
if ( V_9 < 0 ) {
F_11 ( L_3 , V_13 -> V_24 ) ;
} else {
V_4 -> V_25 = 1 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 = 0 ;
V_7 -> V_26 = V_19 ;
}
F_4 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_12 ( struct V_16 * V_13 , int V_9 , int V_19 )
{
struct V_27 V_28 ;
V_28 . V_29 = F_13 ( V_9 ) | V_30 | F_14 ( V_19 )
| V_31 ;
V_28 . V_32 = 0 ;
return F_15 ( & V_28 , V_13 ) ;
}
static int F_16 ( int V_2 , T_1 * V_12 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
* V_12 = V_7 -> V_12 ;
V_9 = V_7 -> V_11 ;
F_4 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_17 ( int V_2 , struct V_16 * V_13 , T_1 V_9 , T_1 V_33 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = F_1 ( V_2 ) ;
unsigned long V_8 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_4 -> V_25 = 1 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 = V_33 ;
V_7 -> V_26 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_18 ( int V_2 , struct V_5 * V_34 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_16 * V_13 ;
unsigned long V_8 ;
struct V_5 * V_5 ;
int V_35 , V_9 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_11 + V_7 -> V_12 ;
V_5 = & V_13 -> V_14 -> V_15 [ V_9 ] ;
F_19 ( & V_5 -> V_29 , V_34 -> V_29 ) ;
F_19 ( & V_5 -> V_32 , V_34 -> V_32 ) ;
F_20 ( V_13 , V_5 , sizeof( * V_5 ) ) ;
V_35 = F_12 ( V_13 , V_9 , 0 ) ;
F_4 ( & V_10 , V_8 ) ;
return V_35 ;
}
static struct V_16 * F_21 ( T_2 V_36 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_39 [ V_37 ] . V_40 == V_36 )
return V_39 [ V_37 ] . V_13 ;
return NULL ;
}
static struct V_16 * F_22 ( int V_41 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ )
if ( V_43 [ V_37 ] . V_40 == V_41 )
return V_43 [ V_37 ] . V_13 ;
return NULL ;
}
static struct V_16 * F_23 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
V_47 = F_24 ( V_45 ) ;
if ( ! V_47 )
return NULL ;
return V_47 -> V_13 ;
}
static int F_25 ( struct V_1 * V_7 )
{
struct V_5 * V_48 , * V_6 , * V_49 ;
struct V_16 * V_13 ;
int V_9 ;
if ( V_7 -> V_12 )
return 0 ;
V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_11 + V_7 -> V_12 ;
V_48 = V_13 -> V_14 -> V_15 + V_9 ;
V_49 = V_48 + ( 1 << V_7 -> V_26 ) ;
for ( V_6 = V_48 ; V_6 < V_49 ; V_6 ++ ) {
F_19 ( & V_6 -> V_29 , 0 ) ;
F_19 ( & V_6 -> V_32 , 0 ) ;
}
F_26 ( V_13 -> V_14 -> V_22 , V_9 ,
V_7 -> V_26 ) ;
return F_12 ( V_13 , V_9 , V_7 -> V_26 ) ;
}
static int F_27 ( int V_2 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_35 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_35 = F_25 ( V_7 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_26 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return V_35 ;
}
static void F_28 ( struct V_5 * V_5 , unsigned int V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
if ( V_53 )
V_50 = V_54 ;
V_5 -> V_50 = V_50 ;
V_5 -> V_51 = V_51 ;
V_5 -> V_52 = V_52 ;
}
static int F_29 ( struct V_5 * V_5 , int V_41 )
{
int V_37 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ ) {
if ( V_43 [ V_37 ] . V_40 == V_41 ) {
V_52 = ( V_43 [ V_37 ] . V_55 << 8 ) | V_43 [ V_37 ] . V_56 ;
break;
}
}
if ( V_52 == 0 ) {
F_30 ( L_4 , V_41 ) ;
return - 1 ;
}
F_28 ( V_5 , V_57 , V_58 , V_52 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_5 , T_2 V_40 )
{
int V_37 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( V_39 [ V_37 ] . V_40 == V_40 ) {
V_52 = ( V_39 [ V_37 ] . V_55 << 8 ) | V_39 [ V_37 ] . V_56 ;
break;
}
}
if ( V_52 == 0 ) {
F_30 ( L_5 , V_40 ) ;
return - 1 ;
}
F_28 ( V_5 , V_57 , V_59 , V_52 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_5 , struct V_44 * V_45 )
{
struct V_44 * V_60 ;
if ( ! V_5 || ! V_45 )
return - 1 ;
if ( F_33 ( V_45 ) || ! V_45 -> V_55 -> V_61 ) {
F_28 ( V_5 , V_57 , V_58 ,
( V_45 -> V_55 -> V_62 << 8 ) | V_45 -> V_56 ) ;
return 0 ;
}
V_60 = F_34 ( V_45 ) ;
if ( V_60 ) {
if ( F_33 ( V_60 ) )
F_28 ( V_5 , V_63 , V_58 ,
( V_60 -> V_55 -> V_62 << 8 ) | V_45 -> V_55 -> V_62 ) ;
else
F_28 ( V_5 , V_57 , V_58 ,
( V_60 -> V_55 -> V_62 << 8 ) | V_60 -> V_56 ) ;
}
return 0 ;
}
static void F_35 ( struct V_16 * V_13 , int V_64 )
{
T_3 V_65 ;
T_4 V_66 ;
unsigned long V_8 ;
V_65 = F_36 ( ( void * ) V_13 -> V_14 -> V_15 ) ;
F_3 ( & V_13 -> V_67 , V_8 ) ;
F_37 ( V_13 -> V_68 + V_69 ,
( V_65 ) | F_38 ( V_64 ) | V_70 ) ;
V_13 -> V_71 |= V_72 ;
F_39 ( V_13 -> V_71 , V_13 -> V_68 + V_73 ) ;
F_40 ( V_13 , V_74 ,
V_75 , ( V_66 & V_76 ) , V_66 ) ;
F_4 ( & V_13 -> V_67 , V_8 ) ;
F_41 ( V_13 ) ;
F_3 ( & V_13 -> V_67 , V_8 ) ;
V_13 -> V_71 |= V_77 ;
V_13 -> V_71 &= ~ V_78 ;
F_39 ( V_13 -> V_71 , V_13 -> V_68 + V_73 ) ;
F_40 ( V_13 , V_74 ,
V_75 , ( V_66 & V_79 ) , V_66 ) ;
if ( V_66 & V_80 )
F_42 ( 1 , V_81
L_6
L_7 ) ;
F_4 ( & V_13 -> V_67 , V_8 ) ;
}
static int F_43 ( struct V_16 * V_13 , int V_64 )
{
struct V_14 * V_14 ;
struct V_82 * V_83 ;
unsigned long * V_22 ;
V_14 = V_13 -> V_14 = F_44 ( sizeof( struct V_14 ) ,
V_84 ) ;
if ( ! V_13 -> V_14 )
return - V_85 ;
V_83 = F_45 ( V_13 -> V_86 , V_84 | V_87 ,
V_88 ) ;
if ( ! V_83 ) {
F_46 ( L_8 ,
V_13 -> V_24 , V_88 ) ;
F_47 ( V_13 -> V_14 ) ;
return - V_85 ;
}
V_22 = F_48 ( F_49 ( V_23 ) ,
sizeof( long ) , V_84 ) ;
if ( V_22 == NULL ) {
F_46 ( L_9 , V_13 -> V_24 ) ;
F_50 ( V_83 , V_88 ) ;
F_47 ( V_14 ) ;
return - V_85 ;
}
V_14 -> V_15 = F_51 ( V_83 ) ;
V_14 -> V_22 = V_22 ;
F_35 ( V_13 , V_64 ) ;
return 0 ;
}
static void F_52 ( struct V_16 * V_13 )
{
unsigned long V_8 ;
T_4 V_66 ;
if ( ! F_53 ( V_13 -> V_20 ) )
return;
F_41 ( V_13 ) ;
F_3 ( & V_13 -> V_67 , V_8 ) ;
V_66 = F_54 ( V_13 -> V_68 + V_74 ) ;
if ( ! ( V_66 & V_79 ) )
goto V_49;
V_13 -> V_71 &= ~ V_77 ;
F_39 ( V_13 -> V_71 , V_13 -> V_68 + V_73 ) ;
F_40 ( V_13 , V_74 ,
V_75 , ! ( V_66 & V_79 ) , V_66 ) ;
V_49:
F_4 ( & V_13 -> V_67 , V_8 ) ;
}
static int T_5 F_55 ( void )
{
struct V_89 * V_90 ;
V_90 = (struct V_89 * ) V_91 ;
if ( ! V_90 || V_92 )
return 0 ;
return V_90 -> V_8 & V_93 ;
}
static int T_5 F_56 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 ;
if ( V_94 )
return 0 ;
if ( V_95 ) {
F_9 ( V_81
L_10
L_11
L_12
L_13
L_14 ) ;
F_57 ( V_96 , V_97 ) ;
V_94 = 1 ;
return 0 ;
}
if ( ! F_58 () )
return 0 ;
F_59 (iommu, drhd)
if ( ! F_53 ( V_13 -> V_20 ) )
return 0 ;
return 1 ;
}
static int T_5 F_60 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 ;
bool V_98 ;
int V_99 = 0 ;
int V_100 = 0 ;
V_98 = F_61 () ;
if ( F_62 () != 1 ) {
F_9 ( V_101 L_15 ) ;
goto error;
}
if ( V_98 ) {
F_63 ( L_16 ) ;
V_100 = ! F_55 () ;
if ( ! V_100 )
F_9 ( V_81
L_17
L_18
L_19 ) ;
}
F_59 (iommu, drhd) {
if ( V_13 -> V_102 )
continue;
F_64 ( - 1 , V_13 ) ;
F_52 ( V_13 ) ;
F_65 ( V_13 ) ;
}
F_59 (iommu, drhd) {
if ( ! F_53 ( V_13 -> V_20 ) )
continue;
if ( V_100 && ! F_66 ( V_13 -> V_20 ) ) {
F_9 ( V_101 L_20
L_21 , V_47 -> V_103 , V_13 -> V_20 ) ;
goto error;
}
}
F_59 (iommu, drhd) {
int V_104 = F_67 ( V_13 ) ;
if ( V_104 ) {
F_9 ( V_21 L_22
L_23 ,
V_47 -> V_103 , V_13 -> V_20 , V_104 ) ;
goto error;
}
}
F_59 (iommu, drhd) {
if ( ! F_53 ( V_13 -> V_20 ) )
continue;
if ( F_43 ( V_13 , V_100 ) )
goto error;
V_99 = 1 ;
}
if ( ! V_99 )
goto error;
V_105 = 1 ;
V_106 . V_107 = V_108 ;
F_63 ( L_24 , V_100 ? L_25 : L_26 ) ;
return V_100 ? V_109 : V_110 ;
error:
if ( V_98 )
F_11 ( L_27 ) ;
return - 1 ;
}
static void F_68 ( struct V_111 * V_112 ,
struct V_16 * V_13 )
{
struct V_113 * V_114 ;
T_2 V_55 ;
int V_17 ;
V_55 = V_112 -> V_55 ;
V_114 = (struct V_113 * ) ( V_112 + 1 ) ;
V_17 = ( V_112 -> V_115 - sizeof( struct V_111 ) )
/ sizeof( struct V_113 ) ;
while ( -- V_17 > 0 ) {
V_55 = F_69 ( V_55 , V_114 -> V_116 , V_114 -> V_117 ,
V_118 ) ;
V_114 ++ ;
}
V_39 [ V_119 ] . V_55 = V_55 ;
V_39 [ V_119 ] . V_56 = F_70 ( V_114 -> V_116 , V_114 -> V_117 ) ;
V_39 [ V_119 ] . V_13 = V_13 ;
V_39 [ V_119 ] . V_40 = V_112 -> V_120 ;
V_119 ++ ;
}
static void F_71 ( struct V_111 * V_112 ,
struct V_16 * V_13 )
{
struct V_113 * V_114 ;
T_2 V_55 ;
int V_17 ;
V_55 = V_112 -> V_55 ;
V_114 = (struct V_113 * ) ( V_112 + 1 ) ;
V_17 = ( V_112 -> V_115 - sizeof( struct V_111 ) )
/ sizeof( struct V_113 ) ;
while ( -- V_17 > 0 ) {
V_55 = F_69 ( V_55 , V_114 -> V_116 , V_114 -> V_117 ,
V_118 ) ;
V_114 ++ ;
}
V_43 [ V_121 ] . V_55 = V_55 ;
V_43 [ V_121 ] . V_56 = F_70 ( V_114 -> V_116 , V_114 -> V_117 ) ;
V_43 [ V_121 ] . V_13 = V_13 ;
V_43 [ V_121 ] . V_40 = V_112 -> V_120 ;
V_121 ++ ;
}
static int F_72 ( struct V_122 * V_123 ,
struct V_16 * V_13 )
{
struct V_124 * V_47 ;
struct V_111 * V_112 ;
void * V_48 , * V_49 ;
V_47 = (struct V_124 * ) V_123 ;
V_48 = ( void * ) ( V_47 + 1 ) ;
V_49 = ( ( void * ) V_47 ) + V_123 -> V_115 ;
while ( V_48 < V_49 ) {
V_112 = V_48 ;
if ( V_112 -> V_125 == V_126 ) {
if ( V_121 == V_42 ) {
F_9 ( V_81 L_28 ) ;
return - 1 ;
}
F_9 ( V_101 L_29
L_30 , V_112 -> V_120 ,
V_47 -> V_127 , V_13 -> V_24 ) ;
F_71 ( V_112 , V_13 ) ;
} else if ( V_112 -> V_125 == V_128 ) {
if ( V_119 == V_38 ) {
F_9 ( V_81 L_31 ) ;
return - 1 ;
}
F_9 ( V_101 L_32
L_33 , V_112 -> V_120 ,
V_47 -> V_127 ) ;
F_68 ( V_112 , V_13 ) ;
}
V_48 += V_112 -> V_115 ;
}
return 0 ;
}
static int T_5 F_62 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 ;
int V_129 = 0 ;
int V_130 ;
F_59 (iommu, drhd)
if ( F_53 ( V_13 -> V_20 ) ) {
if ( F_72 ( V_47 -> V_131 , V_13 ) )
return - 1 ;
V_129 = 1 ;
}
if ( ! V_129 )
return 0 ;
for ( V_130 = 0 ; V_130 < V_132 ; V_130 ++ ) {
int V_133 = F_73 ( V_130 ) ;
if ( ! F_22 ( V_133 ) ) {
F_46 ( V_134 L_34
L_35 ,
V_133 ) ;
return - 1 ;
}
}
return 1 ;
}
static int T_5 F_74 ( void )
{
if ( ! V_105 )
return 0 ;
return F_75 () ;
}
static void F_76 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 = NULL ;
F_59 (iommu, drhd) {
if ( ! F_53 ( V_13 -> V_20 ) )
continue;
F_52 ( V_13 ) ;
}
}
static int F_77 ( int V_100 )
{
struct V_46 * V_47 ;
int V_99 = 0 ;
struct V_16 * V_13 = NULL ;
F_59 (iommu, drhd)
if ( V_13 -> V_102 )
F_78 ( V_13 ) ;
F_59 (iommu, drhd) {
if ( ! F_53 ( V_13 -> V_20 ) )
continue;
F_35 ( V_13 , V_100 ) ;
V_99 = 1 ;
}
if ( ! V_99 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_79 ( struct V_5 * V_5 , int V_135 ,
unsigned int V_136 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_137 = 1 ;
V_5 -> V_138 = V_41 -> V_139 ;
V_5 -> V_140 = 0 ;
V_5 -> V_141 = V_41 -> V_142 ;
V_5 -> V_135 = V_135 ;
V_5 -> V_143 = F_80 ( V_136 ) ;
V_5 -> V_144 = 1 ;
}
static int F_81 ( int V_2 ,
struct V_145 * V_146 ,
unsigned int V_147 , int V_135 ,
struct V_148 * V_149 )
{
int V_133 = F_73 ( V_149 -> V_150 ) ;
struct V_16 * V_13 = F_22 ( V_133 ) ;
struct V_151 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
if ( ! V_13 ) {
F_11 ( L_36 , V_133 ) ;
return - V_152 ;
}
V_6 = (struct V_151 * ) V_146 ;
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_11 ( L_37 , V_133 ) ;
return - V_85 ;
}
F_79 ( & V_5 , V_135 , V_147 ) ;
F_29 ( & V_5 , V_133 ) ;
F_18 ( V_2 , & V_5 ) ;
F_82 ( V_153 , V_154 L_38
L_39
L_40
L_41
L_42 ,
V_149 -> V_150 , V_5 . V_137 , V_5 . V_155 , V_5 . V_138 ,
V_5 . V_144 , V_5 . V_140 , V_5 . V_141 ,
V_5 . V_156 , V_5 . V_135 , V_5 . V_143 ,
V_5 . V_52 , V_5 . V_51 , V_5 . V_50 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_157 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_158 = 0 ;
V_6 -> V_159 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_135 = V_149 -> V_160 ;
V_6 -> V_19 = 0 ;
V_6 -> V_161 = V_149 -> V_161 ;
V_6 -> V_162 = V_149 -> V_162 ;
if ( V_149 -> V_161 )
V_6 -> V_19 = 1 ;
return 0 ;
}
static int
F_83 ( struct V_163 * V_164 , const struct V_165 * V_19 ,
bool V_166 )
{
struct V_3 * V_4 = V_164 -> V_167 ;
unsigned int V_136 , V_2 = V_164 -> V_2 ;
struct V_5 V_5 ;
int V_168 ;
if ( ! F_84 ( V_169 ) )
return - V_170 ;
if ( ! F_85 ( V_19 , V_171 ) )
return - V_170 ;
if ( F_2 ( V_2 , & V_5 ) )
return - V_172 ;
V_168 = F_86 ( V_2 , V_4 , V_19 ) ;
if ( V_168 )
return V_168 ;
V_168 = V_41 -> V_173 ( V_4 -> V_174 , V_19 , & V_136 ) ;
if ( V_168 ) {
if ( F_86 ( V_2 , V_4 , V_164 -> V_175 ) )
F_46 ( L_43 , V_2 ) ;
return V_168 ;
}
V_5 . V_135 = V_4 -> V_135 ;
V_5 . V_143 = F_80 ( V_136 ) ;
F_18 ( V_2 , & V_5 ) ;
if ( V_4 -> V_176 )
F_87 ( V_4 ) ;
F_88 ( V_164 -> V_175 , V_19 ) ;
return 0 ;
}
static void F_89 ( struct V_44 * V_177 ,
unsigned int V_2 , unsigned int V_136 ,
struct V_178 * V_179 , T_2 V_36 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_12 = 0 ;
int V_180 ;
V_4 = F_1 ( V_2 ) ;
V_180 = F_16 ( V_2 , & V_12 ) ;
F_90 ( V_180 == - 1 ) ;
F_79 ( & V_5 , V_4 -> V_135 , V_136 ) ;
if ( V_177 )
F_32 ( & V_5 , V_177 ) ;
else
F_31 ( & V_5 , V_36 ) ;
F_18 ( V_2 , & V_5 ) ;
V_179 -> V_181 = V_182 ;
V_179 -> V_164 = V_12 ;
V_179 -> V_183 = V_184 | V_185 |
V_186 |
F_91 ( V_180 ) |
F_92 ( V_180 ) ;
}
static int F_93 ( struct V_44 * V_45 , int V_2 , int V_187 )
{
struct V_16 * V_13 ;
int V_9 ;
V_13 = F_23 ( V_45 ) ;
if ( ! V_13 ) {
F_9 ( V_21
L_44 , F_94 ( V_45 ) ) ;
return - V_188 ;
}
V_9 = F_5 ( V_13 , V_2 , V_187 ) ;
if ( V_9 < 0 ) {
F_9 ( V_21
L_45 , V_187 ,
F_94 ( V_45 ) ) ;
return - V_189 ;
}
return V_9 ;
}
static int F_95 ( struct V_44 * V_177 , unsigned int V_2 ,
int V_9 , int V_12 )
{
struct V_16 * V_13 ;
V_13 = F_23 ( V_177 ) ;
if ( ! V_13 )
return - V_188 ;
F_17 ( V_2 , V_13 , V_9 , V_12 ) ;
return 0 ;
}
static int F_96 ( unsigned int V_2 , unsigned int V_40 )
{
struct V_16 * V_13 = F_21 ( V_40 ) ;
int V_9 ;
if ( ! V_13 )
return - 1 ;
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 )
return - 1 ;
return 0 ;
}
