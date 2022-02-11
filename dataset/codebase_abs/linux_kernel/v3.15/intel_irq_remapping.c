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
F_30 ( & V_55 ) ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ ) {
if ( V_43 [ V_37 ] . V_40 == V_41 ) {
V_52 = ( V_43 [ V_37 ] . V_56 << 8 ) | V_43 [ V_37 ] . V_57 ;
break;
}
}
F_31 ( & V_55 ) ;
if ( V_52 == 0 ) {
F_32 ( L_4 , V_41 ) ;
return - 1 ;
}
F_28 ( V_5 , V_58 , V_59 , V_52 ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_5 , T_2 V_40 )
{
int V_37 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
F_30 ( & V_55 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( V_39 [ V_37 ] . V_40 == V_40 ) {
V_52 = ( V_39 [ V_37 ] . V_56 << 8 ) | V_39 [ V_37 ] . V_57 ;
break;
}
}
F_31 ( & V_55 ) ;
if ( V_52 == 0 ) {
F_32 ( L_5 , V_40 ) ;
return - 1 ;
}
F_28 ( V_5 , V_58 , V_60 , V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_5 , struct V_44 * V_45 )
{
struct V_44 * V_61 ;
if ( ! V_5 || ! V_45 )
return - 1 ;
if ( F_35 ( V_45 ) || ! V_45 -> V_56 -> V_62 ) {
F_28 ( V_5 , V_58 , V_59 ,
( V_45 -> V_56 -> V_63 << 8 ) | V_45 -> V_57 ) ;
return 0 ;
}
V_61 = F_36 ( V_45 ) ;
if ( V_61 ) {
if ( F_35 ( V_61 ) )
F_28 ( V_5 , V_64 , V_59 ,
( V_61 -> V_56 -> V_63 << 8 ) | V_45 -> V_56 -> V_63 ) ;
else
F_28 ( V_5 , V_58 , V_59 ,
( V_61 -> V_56 -> V_63 << 8 ) | V_61 -> V_57 ) ;
}
return 0 ;
}
static void F_37 ( struct V_16 * V_13 , int V_65 )
{
T_3 V_66 ;
T_4 V_67 ;
unsigned long V_8 ;
V_66 = F_38 ( ( void * ) V_13 -> V_14 -> V_15 ) ;
F_3 ( & V_13 -> V_68 , V_8 ) ;
F_39 ( V_13 -> V_69 + V_70 ,
( V_66 ) | F_40 ( V_65 ) | V_71 ) ;
V_13 -> V_72 |= V_73 ;
F_41 ( V_13 -> V_72 , V_13 -> V_69 + V_74 ) ;
F_42 ( V_13 , V_75 ,
V_76 , ( V_67 & V_77 ) , V_67 ) ;
F_4 ( & V_13 -> V_68 , V_8 ) ;
F_43 ( V_13 ) ;
F_3 ( & V_13 -> V_68 , V_8 ) ;
V_13 -> V_72 |= V_78 ;
V_13 -> V_72 &= ~ V_79 ;
F_41 ( V_13 -> V_72 , V_13 -> V_69 + V_74 ) ;
F_42 ( V_13 , V_75 ,
V_76 , ( V_67 & V_80 ) , V_67 ) ;
if ( V_67 & V_81 )
F_44 ( 1 , V_82
L_6
L_7 ) ;
F_4 ( & V_13 -> V_68 , V_8 ) ;
}
static int F_45 ( struct V_16 * V_13 , int V_65 )
{
struct V_14 * V_14 ;
struct V_83 * V_84 ;
unsigned long * V_22 ;
V_14 = V_13 -> V_14 = F_46 ( sizeof( struct V_14 ) ,
V_85 ) ;
if ( ! V_13 -> V_14 )
return - V_86 ;
V_84 = F_47 ( V_13 -> V_87 , V_85 | V_88 ,
V_89 ) ;
if ( ! V_84 ) {
F_48 ( L_8 ,
V_13 -> V_24 , V_89 ) ;
F_49 ( V_13 -> V_14 ) ;
return - V_86 ;
}
V_22 = F_50 ( F_51 ( V_23 ) ,
sizeof( long ) , V_85 ) ;
if ( V_22 == NULL ) {
F_48 ( L_9 , V_13 -> V_24 ) ;
F_52 ( V_84 , V_89 ) ;
F_49 ( V_14 ) ;
return - V_86 ;
}
V_14 -> V_15 = F_53 ( V_84 ) ;
V_14 -> V_22 = V_22 ;
F_37 ( V_13 , V_65 ) ;
return 0 ;
}
static void F_54 ( struct V_16 * V_13 )
{
unsigned long V_8 ;
T_4 V_67 ;
if ( ! F_55 ( V_13 -> V_20 ) )
return;
F_43 ( V_13 ) ;
F_3 ( & V_13 -> V_68 , V_8 ) ;
V_67 = F_56 ( V_13 -> V_69 + V_75 ) ;
if ( ! ( V_67 & V_80 ) )
goto V_49;
V_13 -> V_72 &= ~ V_78 ;
F_41 ( V_13 -> V_72 , V_13 -> V_69 + V_74 ) ;
F_42 ( V_13 , V_75 ,
V_76 , ! ( V_67 & V_80 ) , V_67 ) ;
V_49:
F_4 ( & V_13 -> V_68 , V_8 ) ;
}
static int T_5 F_57 ( void )
{
struct V_90 * V_91 ;
V_91 = (struct V_90 * ) V_92 ;
if ( ! V_91 || V_93 )
return 0 ;
return V_91 -> V_8 & V_94 ;
}
static int T_5 F_58 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 ;
if ( V_95 )
return 0 ;
if ( V_96 ) {
F_9 ( V_82
L_10
L_11
L_12
L_13
L_14 ) ;
F_59 ( V_97 , V_98 ) ;
V_95 = 1 ;
return 0 ;
}
if ( ! F_60 () )
return 0 ;
F_61 (iommu, drhd)
if ( ! F_55 ( V_13 -> V_20 ) )
return 0 ;
return 1 ;
}
static int T_5 F_62 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 ;
bool V_99 ;
int V_100 = 0 ;
int V_101 = 0 ;
V_99 = F_63 () ;
if ( F_64 () != 1 ) {
F_9 ( V_102 L_15 ) ;
goto error;
}
if ( V_99 ) {
F_65 ( L_16 ) ;
V_101 = ! F_57 () ;
if ( ! V_101 )
F_9 ( V_82
L_17
L_18
L_19 ) ;
}
F_61 (iommu, drhd) {
if ( V_13 -> V_103 )
continue;
F_66 ( - 1 , V_13 ) ;
F_54 ( V_13 ) ;
F_67 ( V_13 ) ;
}
F_61 (iommu, drhd) {
if ( ! F_55 ( V_13 -> V_20 ) )
continue;
if ( V_101 && ! F_68 ( V_13 -> V_20 ) ) {
F_9 ( V_102 L_20
L_21 , V_47 -> V_104 , V_13 -> V_20 ) ;
goto error;
}
}
F_61 (iommu, drhd) {
int V_105 = F_69 ( V_13 ) ;
if ( V_105 ) {
F_9 ( V_21 L_22
L_23 ,
V_47 -> V_104 , V_13 -> V_20 , V_105 ) ;
goto error;
}
}
F_61 (iommu, drhd) {
if ( ! F_55 ( V_13 -> V_20 ) )
continue;
if ( F_45 ( V_13 , V_101 ) )
goto error;
V_100 = 1 ;
}
if ( ! V_100 )
goto error;
V_106 = 1 ;
V_107 . V_108 = V_109 ;
F_65 ( L_24 , V_101 ? L_25 : L_26 ) ;
return V_101 ? V_110 : V_111 ;
error:
if ( V_99 )
F_11 ( L_27 ) ;
return - 1 ;
}
static void F_70 ( struct V_112 * V_113 ,
struct V_16 * V_13 )
{
struct V_114 * V_115 ;
T_2 V_56 ;
int V_17 ;
V_56 = V_113 -> V_56 ;
V_115 = (struct V_114 * ) ( V_113 + 1 ) ;
V_17 = ( V_113 -> V_116 - sizeof( struct V_112 ) )
/ sizeof( struct V_114 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_71 ( V_56 , V_115 -> V_117 , V_115 -> V_118 ,
V_119 ) ;
V_115 ++ ;
}
V_39 [ V_120 ] . V_56 = V_56 ;
V_39 [ V_120 ] . V_57 = F_72 ( V_115 -> V_117 , V_115 -> V_118 ) ;
V_39 [ V_120 ] . V_13 = V_13 ;
V_39 [ V_120 ] . V_40 = V_113 -> V_121 ;
V_120 ++ ;
}
static void F_73 ( struct V_112 * V_113 ,
struct V_16 * V_13 )
{
struct V_114 * V_115 ;
T_2 V_56 ;
int V_17 ;
V_56 = V_113 -> V_56 ;
V_115 = (struct V_114 * ) ( V_113 + 1 ) ;
V_17 = ( V_113 -> V_116 - sizeof( struct V_112 ) )
/ sizeof( struct V_114 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_71 ( V_56 , V_115 -> V_117 , V_115 -> V_118 ,
V_119 ) ;
V_115 ++ ;
}
V_43 [ V_122 ] . V_56 = V_56 ;
V_43 [ V_122 ] . V_57 = F_72 ( V_115 -> V_117 , V_115 -> V_118 ) ;
V_43 [ V_122 ] . V_13 = V_13 ;
V_43 [ V_122 ] . V_40 = V_113 -> V_121 ;
V_122 ++ ;
}
static int F_74 ( struct V_123 * V_124 ,
struct V_16 * V_13 )
{
struct V_125 * V_47 ;
struct V_112 * V_113 ;
void * V_48 , * V_49 ;
V_47 = (struct V_125 * ) V_124 ;
V_48 = ( void * ) ( V_47 + 1 ) ;
V_49 = ( ( void * ) V_47 ) + V_124 -> V_116 ;
while ( V_48 < V_49 ) {
V_113 = V_48 ;
if ( V_113 -> V_126 == V_127 ) {
if ( V_122 == V_42 ) {
F_9 ( V_82 L_28 ) ;
return - 1 ;
}
F_9 ( V_102 L_29
L_30 , V_113 -> V_121 ,
V_47 -> V_128 , V_13 -> V_24 ) ;
F_73 ( V_113 , V_13 ) ;
} else if ( V_113 -> V_126 == V_129 ) {
if ( V_120 == V_38 ) {
F_9 ( V_82 L_31 ) ;
return - 1 ;
}
F_9 ( V_102 L_32
L_33 , V_113 -> V_121 ,
V_47 -> V_128 ) ;
F_70 ( V_113 , V_13 ) ;
}
V_48 += V_113 -> V_116 ;
}
return 0 ;
}
static int T_5 F_64 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 ;
int V_130 = 0 ;
int V_131 ;
F_61 (iommu, drhd)
if ( F_55 ( V_13 -> V_20 ) ) {
if ( F_74 ( V_47 -> V_132 , V_13 ) )
return - 1 ;
V_130 = 1 ;
}
if ( ! V_130 )
return 0 ;
for ( V_131 = 0 ; V_131 < V_133 ; V_131 ++ ) {
int V_134 = F_75 ( V_131 ) ;
if ( ! F_22 ( V_134 ) ) {
F_48 ( V_135 L_34
L_35 ,
V_134 ) ;
return - 1 ;
}
}
return 1 ;
}
static int T_5 F_76 ( void )
{
int V_105 ;
if ( ! V_106 )
return 0 ;
F_77 ( & V_55 ) ;
V_105 = F_78 () ;
F_79 ( & V_55 ) ;
return V_105 ;
}
static void F_80 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_13 = NULL ;
F_61 (iommu, drhd) {
if ( ! F_55 ( V_13 -> V_20 ) )
continue;
F_54 ( V_13 ) ;
}
}
static int F_81 ( int V_101 )
{
struct V_46 * V_47 ;
int V_100 = 0 ;
struct V_16 * V_13 = NULL ;
F_61 (iommu, drhd)
if ( V_13 -> V_103 )
F_82 ( V_13 ) ;
F_61 (iommu, drhd) {
if ( ! F_55 ( V_13 -> V_20 ) )
continue;
F_37 ( V_13 , V_101 ) ;
V_100 = 1 ;
}
if ( ! V_100 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_83 ( struct V_5 * V_5 , int V_136 ,
unsigned int V_137 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_138 = 1 ;
V_5 -> V_139 = V_41 -> V_140 ;
V_5 -> V_141 = 0 ;
V_5 -> V_142 = V_41 -> V_143 ;
V_5 -> V_136 = V_136 ;
V_5 -> V_144 = F_84 ( V_137 ) ;
V_5 -> V_145 = 1 ;
}
static int F_85 ( int V_2 ,
struct V_146 * V_147 ,
unsigned int V_148 , int V_136 ,
struct V_149 * V_150 )
{
int V_134 = F_75 ( V_150 -> V_151 ) ;
struct V_16 * V_13 ;
struct V_152 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_13 = F_22 ( V_134 ) ;
if ( ! V_13 ) {
F_11 ( L_36 , V_134 ) ;
V_9 = - V_153 ;
} else {
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_11 ( L_37 ,
V_134 ) ;
V_9 = - V_86 ;
}
}
F_31 ( & V_55 ) ;
if ( V_9 < 0 )
return V_9 ;
F_83 ( & V_5 , V_136 , V_148 ) ;
F_29 ( & V_5 , V_134 ) ;
F_18 ( V_2 , & V_5 ) ;
F_86 ( V_154 , V_155 L_38
L_39
L_40
L_41
L_42 ,
V_150 -> V_151 , V_5 . V_138 , V_5 . V_156 , V_5 . V_139 ,
V_5 . V_145 , V_5 . V_141 , V_5 . V_142 ,
V_5 . V_157 , V_5 . V_136 , V_5 . V_144 ,
V_5 . V_52 , V_5 . V_51 , V_5 . V_50 ) ;
V_6 = (struct V_152 * ) V_147 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_158 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_159 = 0 ;
V_6 -> V_160 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_136 = V_150 -> V_161 ;
V_6 -> V_19 = 0 ;
V_6 -> V_162 = V_150 -> V_162 ;
V_6 -> V_163 = V_150 -> V_163 ;
if ( V_150 -> V_162 )
V_6 -> V_19 = 1 ;
return 0 ;
}
static int
F_87 ( struct V_164 * V_165 , const struct V_166 * V_19 ,
bool V_167 )
{
struct V_3 * V_4 = V_165 -> V_168 ;
unsigned int V_137 , V_2 = V_165 -> V_2 ;
struct V_5 V_5 ;
int V_169 ;
if ( ! F_88 ( V_170 ) )
return - V_171 ;
if ( ! F_89 ( V_19 , V_172 ) )
return - V_171 ;
if ( F_2 ( V_2 , & V_5 ) )
return - V_173 ;
V_169 = F_90 ( V_2 , V_4 , V_19 ) ;
if ( V_169 )
return V_169 ;
V_169 = V_41 -> V_174 ( V_4 -> V_175 , V_19 , & V_137 ) ;
if ( V_169 ) {
if ( F_90 ( V_2 , V_4 , V_165 -> V_176 ) )
F_48 ( L_43 , V_2 ) ;
return V_169 ;
}
V_5 . V_136 = V_4 -> V_136 ;
V_5 . V_144 = F_84 ( V_137 ) ;
F_18 ( V_2 , & V_5 ) ;
if ( V_4 -> V_177 )
F_91 ( V_4 ) ;
F_92 ( V_165 -> V_176 , V_19 ) ;
return 0 ;
}
static void F_93 ( struct V_44 * V_178 ,
unsigned int V_2 , unsigned int V_137 ,
struct V_179 * V_180 , T_2 V_36 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_12 = 0 ;
int V_181 ;
V_4 = F_1 ( V_2 ) ;
V_181 = F_16 ( V_2 , & V_12 ) ;
F_94 ( V_181 == - 1 ) ;
F_83 ( & V_5 , V_4 -> V_136 , V_137 ) ;
if ( V_178 )
F_34 ( & V_5 , V_178 ) ;
else
F_33 ( & V_5 , V_36 ) ;
F_18 ( V_2 , & V_5 ) ;
V_180 -> V_182 = V_183 ;
V_180 -> V_165 = V_12 ;
V_180 -> V_184 = V_185 | V_186 |
V_187 |
F_95 ( V_181 ) |
F_96 ( V_181 ) ;
}
static int F_97 ( struct V_44 * V_45 , int V_2 , int V_188 )
{
struct V_16 * V_13 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_13 = F_23 ( V_45 ) ;
if ( ! V_13 ) {
F_9 ( V_21
L_44 , F_98 ( V_45 ) ) ;
V_9 = - V_189 ;
} else {
V_9 = F_5 ( V_13 , V_2 , V_188 ) ;
if ( V_9 < 0 ) {
F_9 ( V_21
L_45 ,
V_188 , F_98 ( V_45 ) ) ;
V_9 = - V_190 ;
}
}
F_31 ( & V_55 ) ;
return V_9 ;
}
static int F_99 ( struct V_44 * V_178 , unsigned int V_2 ,
int V_9 , int V_12 )
{
struct V_16 * V_13 ;
int V_105 = - V_189 ;
F_30 ( & V_55 ) ;
V_13 = F_23 ( V_178 ) ;
if ( V_13 ) {
F_17 ( V_2 , V_13 , V_9 , V_12 ) ;
V_105 = 0 ;
}
F_31 ( & V_55 ) ;
return V_105 ;
}
static int F_100 ( unsigned int V_2 , unsigned int V_40 )
{
int V_105 = - 1 ;
struct V_16 * V_13 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_13 = F_21 ( V_40 ) ;
if ( V_13 ) {
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 >= 0 )
V_105 = 0 ;
}
F_31 ( & V_55 ) ;
return V_105 ;
}
