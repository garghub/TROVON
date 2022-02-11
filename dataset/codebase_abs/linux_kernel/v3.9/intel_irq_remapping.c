static struct V_1 * V_1 ( unsigned int V_2 )
{
struct V_3 * V_4 = F_1 ( V_2 ) ;
return V_4 ? & V_4 -> V_1 : NULL ;
}
int F_2 ( int V_2 , struct V_5 * V_6 )
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
T_1 V_9 , V_19 ;
unsigned int V_20 = 0 ;
unsigned long V_8 ;
int V_21 ;
if ( ! V_17 || ! V_7 )
return - 1 ;
V_9 = V_19 = 0 ;
if ( V_17 > 1 ) {
V_17 = F_6 ( V_17 ) ;
V_20 = F_7 ( V_17 ) ;
}
if ( V_20 > F_8 ( V_13 -> V_22 ) ) {
F_9 ( V_23
L_1
L_2 , V_20 ,
F_8 ( V_13 -> V_22 ) ) ;
return - 1 ;
}
F_3 ( & V_10 , V_8 ) ;
do {
for ( V_21 = V_9 ; V_21 < V_9 + V_17 ; V_21 ++ )
if ( V_18 -> V_15 [ V_21 ] . V_24 )
break;
if ( V_21 == V_9 + V_17 )
break;
V_9 = ( V_9 + V_17 ) % V_25 ;
if ( V_9 == V_19 ) {
F_4 ( & V_10 , V_8 ) ;
F_9 ( V_23 L_3 ) ;
return - 1 ;
}
} while ( 1 );
for ( V_21 = V_9 ; V_21 < V_9 + V_17 ; V_21 ++ )
V_18 -> V_15 [ V_21 ] . V_24 = 1 ;
V_4 -> V_26 = 1 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 = 0 ;
V_7 -> V_27 = V_20 ;
F_4 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_10 ( struct V_16 * V_13 , int V_9 , int V_20 )
{
struct V_28 V_29 ;
V_29 . V_30 = F_11 ( V_9 ) | V_31 | F_12 ( V_20 )
| V_32 ;
V_29 . V_33 = 0 ;
return F_13 ( & V_29 , V_13 ) ;
}
static int F_14 ( int V_2 , T_1 * V_12 )
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
static int F_15 ( int V_2 , struct V_16 * V_13 , T_1 V_9 , T_1 V_34 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = F_1 ( V_2 ) ;
unsigned long V_8 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_4 -> V_26 = 1 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 = V_34 ;
V_7 -> V_27 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_16 ( int V_2 , struct V_5 * V_35 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_16 * V_13 ;
unsigned long V_8 ;
struct V_5 * V_5 ;
int V_36 , V_9 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_11 + V_7 -> V_12 ;
V_5 = & V_13 -> V_14 -> V_15 [ V_9 ] ;
F_17 ( & V_5 -> V_30 , V_35 -> V_30 ) ;
F_17 ( & V_5 -> V_33 , V_35 -> V_33 ) ;
F_18 ( V_13 , V_5 , sizeof( * V_5 ) ) ;
V_36 = F_10 ( V_13 , V_9 , 0 ) ;
F_4 ( & V_10 , V_8 ) ;
return V_36 ;
}
static struct V_16 * F_19 ( T_2 V_37 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_38 ; V_21 ++ )
if ( V_39 [ V_21 ] . V_40 == V_37 )
return V_39 [ V_21 ] . V_13 ;
return NULL ;
}
static struct V_16 * F_20 ( int V_41 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_42 ; V_21 ++ )
if ( V_43 [ V_21 ] . V_40 == V_41 )
return V_43 [ V_21 ] . V_13 ;
return NULL ;
}
static struct V_16 * F_21 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
V_47 = F_22 ( V_45 ) ;
if ( ! V_47 )
return NULL ;
return V_47 -> V_13 ;
}
static int F_23 ( struct V_1 * V_7 )
{
struct V_5 * V_48 , * V_6 , * V_49 ;
struct V_16 * V_13 ;
int V_9 ;
if ( V_7 -> V_12 )
return 0 ;
V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_11 + V_7 -> V_12 ;
V_48 = V_13 -> V_14 -> V_15 + V_9 ;
V_49 = V_48 + ( 1 << V_7 -> V_27 ) ;
for ( V_6 = V_48 ; V_6 < V_49 ; V_6 ++ ) {
F_17 ( & V_6 -> V_30 , 0 ) ;
F_17 ( & V_6 -> V_33 , 0 ) ;
}
return F_10 ( V_13 , V_9 , V_7 -> V_27 ) ;
}
static int F_24 ( int V_2 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_36 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_36 = F_23 ( V_7 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_27 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return V_36 ;
}
static void F_25 ( struct V_5 * V_5 , unsigned int V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
if ( V_53 )
V_50 = V_54 ;
V_5 -> V_50 = V_50 ;
V_5 -> V_51 = V_51 ;
V_5 -> V_52 = V_52 ;
}
static int F_26 ( struct V_5 * V_5 , int V_41 )
{
int V_21 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
for ( V_21 = 0 ; V_21 < V_42 ; V_21 ++ ) {
if ( V_43 [ V_21 ] . V_40 == V_41 ) {
V_52 = ( V_43 [ V_21 ] . V_55 << 8 ) | V_43 [ V_21 ] . V_56 ;
break;
}
}
if ( V_52 == 0 ) {
F_27 ( L_4 , V_41 ) ;
return - 1 ;
}
F_25 ( V_5 , 1 , 0 , V_52 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_5 , T_2 V_40 )
{
int V_21 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
for ( V_21 = 0 ; V_21 < V_38 ; V_21 ++ ) {
if ( V_39 [ V_21 ] . V_40 == V_40 ) {
V_52 = ( V_39 [ V_21 ] . V_55 << 8 ) | V_39 [ V_21 ] . V_56 ;
break;
}
}
if ( V_52 == 0 ) {
F_27 ( L_5 , V_40 ) ;
return - 1 ;
}
F_25 ( V_5 , V_57 , V_58 , V_52 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_5 , struct V_44 * V_45 )
{
struct V_44 * V_59 ;
if ( ! V_5 || ! V_45 )
return - 1 ;
if ( F_30 ( V_45 ) || ! V_45 -> V_55 -> V_60 ) {
F_25 ( V_5 , V_57 , V_61 ,
( V_45 -> V_55 -> V_62 << 8 ) | V_45 -> V_56 ) ;
return 0 ;
}
V_59 = F_31 ( V_45 ) ;
if ( V_59 ) {
if ( F_30 ( V_59 ) )
F_25 ( V_5 , V_63 , V_61 ,
( V_59 -> V_55 -> V_62 << 8 ) | V_45 -> V_55 -> V_62 ) ;
else
F_25 ( V_5 , V_57 , V_61 ,
( V_59 -> V_55 -> V_62 << 8 ) | V_59 -> V_56 ) ;
}
return 0 ;
}
static void F_32 ( struct V_16 * V_13 , int V_64 )
{
T_3 V_65 ;
T_4 V_66 ;
unsigned long V_8 ;
V_65 = F_33 ( ( void * ) V_13 -> V_14 -> V_15 ) ;
F_3 ( & V_13 -> V_67 , V_8 ) ;
F_34 ( V_13 -> V_68 + V_69 ,
( V_65 ) | F_35 ( V_64 ) | V_70 ) ;
V_13 -> V_71 |= V_72 ;
F_36 ( V_13 -> V_71 , V_13 -> V_68 + V_73 ) ;
F_37 ( V_13 , V_74 ,
V_75 , ( V_66 & V_76 ) , V_66 ) ;
F_4 ( & V_13 -> V_67 , V_8 ) ;
F_38 ( V_13 ) ;
F_3 ( & V_13 -> V_67 , V_8 ) ;
V_13 -> V_71 |= V_77 ;
V_13 -> V_71 &= ~ V_78 ;
F_36 ( V_13 -> V_71 , V_13 -> V_68 + V_73 ) ;
F_37 ( V_13 , V_74 ,
V_75 , ( V_66 & V_79 ) , V_66 ) ;
if ( V_66 & V_80 )
F_39 ( 1 , V_81
L_6
L_7 ) ;
F_4 ( & V_13 -> V_67 , V_8 ) ;
}
static int F_40 ( struct V_16 * V_13 , int V_64 )
{
struct V_14 * V_14 ;
struct V_82 * V_83 ;
V_14 = V_13 -> V_14 = F_41 ( sizeof( struct V_14 ) ,
V_84 ) ;
if ( ! V_13 -> V_14 )
return - V_85 ;
V_83 = F_42 ( V_13 -> V_86 , V_84 | V_87 ,
V_88 ) ;
if ( ! V_83 ) {
F_9 ( V_23 L_8 ,
V_88 ) ;
F_43 ( V_13 -> V_14 ) ;
return - V_85 ;
}
V_14 -> V_15 = F_44 ( V_83 ) ;
F_32 ( V_13 , V_64 ) ;
return 0 ;
}
static void F_45 ( struct V_16 * V_13 )
{
unsigned long V_8 ;
T_4 V_66 ;
if ( ! F_46 ( V_13 -> V_22 ) )
return;
F_38 ( V_13 ) ;
F_3 ( & V_13 -> V_67 , V_8 ) ;
V_66 = F_47 ( V_13 -> V_68 + V_74 ) ;
if ( ! ( V_66 & V_79 ) )
goto V_49;
V_13 -> V_71 &= ~ V_77 ;
F_36 ( V_13 -> V_71 , V_13 -> V_68 + V_73 ) ;
F_37 ( V_13 , V_74 ,
V_75 , ! ( V_66 & V_79 ) , V_66 ) ;
V_49:
F_4 ( & V_13 -> V_67 , V_8 ) ;
}
static int T_5 F_48 ( void )
{
struct V_89 * V_90 ;
V_90 = (struct V_89 * ) V_91 ;
if ( ! V_90 || V_92 )
return 0 ;
return V_90 -> V_8 & V_93 ;
}
static int T_5 F_49 ( void )
{
struct V_46 * V_47 ;
if ( V_94 )
return 0 ;
if ( ! F_50 () )
return 0 ;
F_51 (drhd) {
struct V_16 * V_13 = V_47 -> V_13 ;
if ( ! F_46 ( V_13 -> V_22 ) )
return 0 ;
}
return 1 ;
}
static int T_5 F_52 ( void )
{
struct V_46 * V_47 ;
bool V_95 ;
int V_96 = 0 ;
int V_97 = 0 ;
V_95 = F_53 () ;
if ( F_54 () != 1 ) {
F_9 ( V_98 L_9 ) ;
goto error;
}
if ( V_95 ) {
V_97 = ! F_48 () ;
if ( ! V_97 )
F_9 ( V_81
L_10
L_11
L_12 ) ;
}
F_51 (drhd) {
struct V_16 * V_13 = V_47 -> V_13 ;
if ( V_13 -> V_99 )
continue;
F_55 ( - 1 , V_13 ) ;
F_45 ( V_13 ) ;
F_56 ( V_13 ) ;
}
F_51 (drhd) {
struct V_16 * V_13 = V_47 -> V_13 ;
if ( ! F_46 ( V_13 -> V_22 ) )
continue;
if ( V_97 && ! F_57 ( V_13 -> V_22 ) ) {
F_9 ( V_98 L_13
L_14 , V_47 -> V_100 , V_13 -> V_22 ) ;
goto error;
}
}
F_51 (drhd) {
int V_101 ;
struct V_16 * V_13 = V_47 -> V_13 ;
V_101 = F_58 ( V_13 ) ;
if ( V_101 ) {
F_9 ( V_23 L_15
L_16 ,
V_47 -> V_100 , V_13 -> V_22 , V_101 ) ;
goto error;
}
}
F_51 (drhd) {
struct V_16 * V_13 = V_47 -> V_13 ;
if ( ! F_46 ( V_13 -> V_22 ) )
continue;
if ( F_40 ( V_13 , V_97 ) )
goto error;
V_96 = 1 ;
}
if ( ! V_96 )
goto error;
V_102 = 1 ;
V_103 . V_104 = V_105 ;
F_59 ( L_17 , V_97 ? L_18 : L_19 ) ;
return V_97 ? V_106 : V_107 ;
error:
if ( V_95 )
F_39 ( 1 , V_81
L_20 ) ;
return - 1 ;
}
static void F_60 ( struct V_108 * V_109 ,
struct V_16 * V_13 )
{
struct V_110 * V_111 ;
T_2 V_55 ;
int V_17 ;
V_55 = V_109 -> V_55 ;
V_111 = (struct V_110 * ) ( V_109 + 1 ) ;
V_17 = ( V_109 -> V_112 - sizeof( struct V_108 ) )
/ sizeof( struct V_110 ) ;
while ( -- V_17 > 0 ) {
V_55 = F_61 ( V_55 , V_111 -> V_45 , V_111 -> V_113 ,
V_114 ) ;
V_111 ++ ;
}
V_39 [ V_115 ] . V_55 = V_55 ;
V_39 [ V_115 ] . V_56 = F_62 ( V_111 -> V_45 , V_111 -> V_113 ) ;
V_39 [ V_115 ] . V_13 = V_13 ;
V_39 [ V_115 ] . V_40 = V_109 -> V_116 ;
V_115 ++ ;
}
static void F_63 ( struct V_108 * V_109 ,
struct V_16 * V_13 )
{
struct V_110 * V_111 ;
T_2 V_55 ;
int V_17 ;
V_55 = V_109 -> V_55 ;
V_111 = (struct V_110 * ) ( V_109 + 1 ) ;
V_17 = ( V_109 -> V_112 - sizeof( struct V_108 ) )
/ sizeof( struct V_110 ) ;
while ( -- V_17 > 0 ) {
V_55 = F_61 ( V_55 , V_111 -> V_45 , V_111 -> V_113 ,
V_114 ) ;
V_111 ++ ;
}
V_43 [ V_117 ] . V_55 = V_55 ;
V_43 [ V_117 ] . V_56 = F_62 ( V_111 -> V_45 , V_111 -> V_113 ) ;
V_43 [ V_117 ] . V_13 = V_13 ;
V_43 [ V_117 ] . V_40 = V_109 -> V_116 ;
V_117 ++ ;
}
static int F_64 ( struct V_118 * V_119 ,
struct V_16 * V_13 )
{
struct V_120 * V_47 ;
struct V_108 * V_109 ;
void * V_48 , * V_49 ;
V_47 = (struct V_120 * ) V_119 ;
V_48 = ( void * ) ( V_47 + 1 ) ;
V_49 = ( ( void * ) V_47 ) + V_119 -> V_112 ;
while ( V_48 < V_49 ) {
V_109 = V_48 ;
if ( V_109 -> V_121 == V_122 ) {
if ( V_117 == V_42 ) {
F_9 ( V_81 L_21 ) ;
return - 1 ;
}
F_9 ( V_98 L_22
L_23 , V_109 -> V_116 ,
V_47 -> V_123 , V_13 -> V_124 ) ;
F_63 ( V_109 , V_13 ) ;
} else if ( V_109 -> V_121 == V_125 ) {
if ( V_115 == V_38 ) {
F_9 ( V_81 L_24 ) ;
return - 1 ;
}
F_9 ( V_98 L_25
L_26 , V_109 -> V_116 ,
V_47 -> V_123 ) ;
F_60 ( V_109 , V_13 ) ;
}
V_48 += V_109 -> V_112 ;
}
return 0 ;
}
int T_5 F_54 ( void )
{
struct V_46 * V_47 ;
int V_126 = 0 ;
int V_127 ;
F_51 (drhd) {
struct V_16 * V_13 = V_47 -> V_13 ;
if ( F_46 ( V_13 -> V_22 ) ) {
if ( F_64 ( V_47 -> V_128 , V_13 ) )
return - 1 ;
V_126 = 1 ;
}
}
if ( ! V_126 )
return 0 ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
int V_130 = F_65 ( V_127 ) ;
if ( ! F_20 ( V_130 ) ) {
F_66 ( V_131 L_27
L_28 ,
V_130 ) ;
return - 1 ;
}
}
return 1 ;
}
int T_5 F_67 ( void )
{
if ( ! V_102 )
return 0 ;
return F_68 () ;
}
static void F_69 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 = NULL ;
F_70 (iommu, drhd) {
if ( ! F_46 ( V_13 -> V_22 ) )
continue;
F_45 ( V_13 ) ;
}
}
static int F_71 ( int V_97 )
{
struct V_46 * V_47 ;
int V_96 = 0 ;
struct V_16 * V_13 = NULL ;
F_70 (iommu, drhd)
if ( V_13 -> V_99 )
F_72 ( V_13 ) ;
F_70 (iommu, drhd) {
if ( ! F_46 ( V_13 -> V_22 ) )
continue;
F_32 ( V_13 , V_97 ) ;
V_96 = 1 ;
}
if ( ! V_96 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_73 ( struct V_5 * V_5 , int V_132 ,
unsigned int V_133 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_24 = 1 ;
V_5 -> V_134 = V_41 -> V_135 ;
V_5 -> V_136 = 0 ;
V_5 -> V_137 = V_41 -> V_138 ;
V_5 -> V_132 = V_132 ;
V_5 -> V_139 = F_74 ( V_133 ) ;
V_5 -> V_140 = 1 ;
}
static int F_75 ( int V_2 ,
struct V_141 * V_142 ,
unsigned int V_143 , int V_132 ,
struct V_144 * V_145 )
{
int V_130 = F_65 ( V_145 -> V_146 ) ;
struct V_16 * V_13 = F_20 ( V_130 ) ;
struct V_147 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
if ( ! V_13 ) {
F_76 ( L_29 , V_130 ) ;
return - V_148 ;
}
V_6 = (struct V_147 * ) V_142 ;
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_76 ( L_30 , V_130 ) ;
return - V_85 ;
}
F_73 ( & V_5 , V_132 , V_143 ) ;
F_26 ( & V_5 , V_130 ) ;
F_16 ( V_2 , & V_5 ) ;
F_77 ( V_149 , V_150 L_31
L_32
L_33
L_34
L_35 ,
V_145 -> V_146 , V_5 . V_24 , V_5 . V_151 , V_5 . V_134 ,
V_5 . V_140 , V_5 . V_136 , V_5 . V_137 ,
V_5 . V_152 , V_5 . V_132 , V_5 . V_139 ,
V_5 . V_52 , V_5 . V_51 , V_5 . V_50 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_153 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_154 = 0 ;
V_6 -> V_155 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_132 = V_145 -> V_156 ;
V_6 -> V_20 = 0 ;
V_6 -> V_157 = V_145 -> V_157 ;
V_6 -> V_158 = V_145 -> V_158 ;
if ( V_145 -> V_157 )
V_6 -> V_20 = 1 ;
return 0 ;
}
static int
F_78 ( struct V_159 * V_160 , const struct V_161 * V_20 ,
bool V_162 )
{
struct V_3 * V_4 = V_160 -> V_163 ;
unsigned int V_133 , V_2 = V_160 -> V_2 ;
struct V_5 V_5 ;
int V_164 ;
if ( ! F_79 ( V_165 ) )
return - V_166 ;
if ( ! F_80 ( V_20 , V_167 ) )
return - V_166 ;
if ( F_2 ( V_2 , & V_5 ) )
return - V_168 ;
V_164 = F_81 ( V_2 , V_4 , V_20 ) ;
if ( V_164 )
return V_164 ;
V_164 = V_41 -> V_169 ( V_4 -> V_170 , V_20 , & V_133 ) ;
if ( V_164 ) {
if ( F_81 ( V_2 , V_4 , V_160 -> V_171 ) )
F_66 ( L_36 , V_2 ) ;
return V_164 ;
}
V_5 . V_132 = V_4 -> V_132 ;
V_5 . V_139 = F_74 ( V_133 ) ;
F_16 ( V_2 , & V_5 ) ;
if ( V_4 -> V_172 )
F_82 ( V_4 ) ;
F_83 ( V_160 -> V_171 , V_20 ) ;
return 0 ;
}
static void F_84 ( struct V_44 * V_173 ,
unsigned int V_2 , unsigned int V_133 ,
struct V_174 * V_175 , T_2 V_37 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_12 = 0 ;
int V_176 ;
V_4 = F_1 ( V_2 ) ;
V_176 = F_14 ( V_2 , & V_12 ) ;
F_85 ( V_176 == - 1 ) ;
F_73 ( & V_5 , V_4 -> V_132 , V_133 ) ;
if ( V_173 )
F_29 ( & V_5 , V_173 ) ;
else
F_28 ( & V_5 , V_37 ) ;
F_16 ( V_2 , & V_5 ) ;
V_175 -> V_177 = V_178 ;
V_175 -> V_160 = V_12 ;
V_175 -> V_179 = V_180 | V_181 |
V_182 |
F_86 ( V_176 ) |
F_87 ( V_176 ) ;
}
static int F_88 ( struct V_44 * V_45 , int V_2 , int V_183 )
{
struct V_16 * V_13 ;
int V_9 ;
V_13 = F_21 ( V_45 ) ;
if ( ! V_13 ) {
F_9 ( V_23
L_37 , F_89 ( V_45 ) ) ;
return - V_184 ;
}
V_9 = F_5 ( V_13 , V_2 , V_183 ) ;
if ( V_9 < 0 ) {
F_9 ( V_23
L_38 , V_183 ,
F_89 ( V_45 ) ) ;
return - V_185 ;
}
return V_9 ;
}
static int F_90 ( struct V_44 * V_173 , unsigned int V_2 ,
int V_9 , int V_12 )
{
struct V_16 * V_13 ;
V_13 = F_21 ( V_173 ) ;
if ( ! V_13 )
return - V_184 ;
F_15 ( V_2 , V_13 , V_9 , V_12 ) ;
return 0 ;
}
static int F_91 ( unsigned int V_2 , unsigned int V_40 )
{
struct V_16 * V_13 = F_19 ( V_40 ) ;
int V_9 ;
if ( ! V_13 )
return - 1 ;
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 )
return - 1 ;
return 0 ;
}
