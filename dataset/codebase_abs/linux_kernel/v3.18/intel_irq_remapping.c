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
if ( F_4 ( ! V_7 -> V_11 ) ) {
F_5 ( & V_10 , V_8 ) ;
return - 1 ;
}
V_9 = V_7 -> V_12 + V_7 -> V_13 ;
* V_6 = * ( V_7 -> V_11 -> V_14 -> V_15 + V_9 ) ;
F_5 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_16 * V_11 , int V_2 , T_1 V_17 )
{
struct V_14 * V_18 = V_11 -> V_14 ;
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = F_1 ( V_2 ) ;
unsigned int V_19 = 0 ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_17 || ! V_7 )
return - 1 ;
if ( V_17 > 1 ) {
V_17 = F_7 ( V_17 ) ;
V_19 = F_8 ( V_17 ) ;
}
if ( V_19 > F_9 ( V_11 -> V_20 ) ) {
F_10 ( V_21
L_1
L_2 , V_19 ,
F_9 ( V_11 -> V_20 ) ) ;
return - 1 ;
}
F_3 ( & V_10 , V_8 ) ;
V_9 = F_11 ( V_18 -> V_22 ,
V_23 , V_19 ) ;
if ( V_9 < 0 ) {
F_12 ( L_3 , V_11 -> V_24 ) ;
} else {
V_4 -> V_25 = 1 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_12 = V_9 ;
V_7 -> V_13 = 0 ;
V_7 -> V_26 = V_19 ;
}
F_5 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_13 ( struct V_16 * V_11 , int V_9 , int V_19 )
{
struct V_27 V_28 ;
V_28 . V_29 = F_14 ( V_9 ) | V_30 | F_15 ( V_19 )
| V_31 ;
V_28 . V_32 = 0 ;
return F_16 ( & V_28 , V_11 ) ;
}
static int F_17 ( int V_2 , T_1 * V_13 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
* V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_12 ;
F_5 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_18 ( int V_2 , struct V_16 * V_11 , T_1 V_9 , T_1 V_33 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = F_1 ( V_2 ) ;
unsigned long V_8 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_4 -> V_25 = 1 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_12 = V_9 ;
V_7 -> V_13 = V_33 ;
V_7 -> V_26 = 0 ;
F_5 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_19 ( int V_2 , struct V_5 * V_34 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_16 * V_11 ;
unsigned long V_8 ;
struct V_5 * V_5 ;
int V_35 , V_9 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_11 = V_7 -> V_11 ;
V_9 = V_7 -> V_12 + V_7 -> V_13 ;
V_5 = & V_11 -> V_14 -> V_15 [ V_9 ] ;
F_20 ( & V_5 -> V_29 , V_34 -> V_29 ) ;
F_20 ( & V_5 -> V_32 , V_34 -> V_32 ) ;
F_21 ( V_11 , V_5 , sizeof( * V_5 ) ) ;
V_35 = F_13 ( V_11 , V_9 , 0 ) ;
F_5 ( & V_10 , V_8 ) ;
return V_35 ;
}
static struct V_16 * F_22 ( T_2 V_36 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_39 [ V_37 ] . V_40 == V_36 )
return V_39 [ V_37 ] . V_11 ;
return NULL ;
}
static struct V_16 * F_23 ( int V_41 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ )
if ( V_43 [ V_37 ] . V_40 == V_41 )
return V_43 [ V_37 ] . V_11 ;
return NULL ;
}
static struct V_16 * F_24 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
V_47 = F_25 ( V_45 ) ;
if ( ! V_47 )
return NULL ;
return V_47 -> V_11 ;
}
static int F_26 ( struct V_1 * V_7 )
{
struct V_5 * V_48 , * V_6 , * V_49 ;
struct V_16 * V_11 ;
int V_9 ;
if ( V_7 -> V_13 )
return 0 ;
V_11 = V_7 -> V_11 ;
V_9 = V_7 -> V_12 + V_7 -> V_13 ;
V_48 = V_11 -> V_14 -> V_15 + V_9 ;
V_49 = V_48 + ( 1 << V_7 -> V_26 ) ;
for ( V_6 = V_48 ; V_6 < V_49 ; V_6 ++ ) {
F_20 ( & V_6 -> V_29 , 0 ) ;
F_20 ( & V_6 -> V_32 , 0 ) ;
}
F_27 ( V_11 -> V_14 -> V_22 , V_9 ,
V_7 -> V_26 ) ;
return F_13 ( V_11 , V_9 , V_7 -> V_26 ) ;
}
static int F_28 ( int V_2 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_35 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_35 = F_26 ( V_7 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_26 = 0 ;
F_5 ( & V_10 , V_8 ) ;
return V_35 ;
}
static void F_29 ( struct V_5 * V_5 , unsigned int V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
if ( V_53 )
V_50 = V_54 ;
V_5 -> V_50 = V_50 ;
V_5 -> V_51 = V_51 ;
V_5 -> V_52 = V_52 ;
}
static int F_30 ( struct V_5 * V_5 , int V_41 )
{
int V_37 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
F_31 ( & V_55 ) ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ ) {
if ( V_43 [ V_37 ] . V_40 == V_41 ) {
V_52 = ( V_43 [ V_37 ] . V_56 << 8 ) | V_43 [ V_37 ] . V_57 ;
break;
}
}
F_32 ( & V_55 ) ;
if ( V_52 == 0 ) {
F_33 ( L_4 , V_41 ) ;
return - 1 ;
}
F_29 ( V_5 , V_58 , V_59 , V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_5 * V_5 , T_2 V_40 )
{
int V_37 ;
T_1 V_52 = 0 ;
if ( ! V_5 )
return - 1 ;
F_31 ( & V_55 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( V_39 [ V_37 ] . V_40 == V_40 ) {
V_52 = ( V_39 [ V_37 ] . V_56 << 8 ) | V_39 [ V_37 ] . V_57 ;
break;
}
}
F_32 ( & V_55 ) ;
if ( V_52 == 0 ) {
F_33 ( L_5 , V_40 ) ;
return - 1 ;
}
F_29 ( V_5 , V_58 , V_60 , V_52 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_61 , T_1 V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
V_65 -> V_61 = V_61 ;
V_65 -> V_62 = V_62 ;
return 0 ;
}
static int F_36 ( struct V_5 * V_5 , struct V_44 * V_45 )
{
struct V_64 V_65 ;
if ( ! V_5 || ! V_45 )
return - 1 ;
F_37 ( V_45 , F_35 , & V_65 ) ;
if ( F_38 ( V_65 . V_62 ) != V_65 . V_61 -> V_56 -> V_66 )
F_29 ( V_5 , V_67 , V_59 ,
F_39 ( F_38 ( V_65 . V_62 ) ,
V_45 -> V_56 -> V_66 ) ) ;
else if ( V_65 . V_61 -> V_56 -> V_66 != V_45 -> V_56 -> V_66 )
F_29 ( V_5 , V_58 , V_59 , V_65 . V_62 ) ;
else
F_29 ( V_5 , V_58 , V_59 ,
F_39 ( V_45 -> V_56 -> V_66 , V_45 -> V_57 ) ) ;
return 0 ;
}
static void F_40 ( struct V_16 * V_11 , int V_68 )
{
T_3 V_69 ;
T_4 V_70 ;
unsigned long V_8 ;
V_69 = F_41 ( ( void * ) V_11 -> V_14 -> V_15 ) ;
F_3 ( & V_11 -> V_71 , V_8 ) ;
F_42 ( V_11 -> V_72 + V_73 ,
( V_69 ) | F_43 ( V_68 ) | V_74 ) ;
F_44 ( V_11 -> V_75 | V_76 , V_11 -> V_72 + V_77 ) ;
F_45 ( V_11 , V_78 ,
V_79 , ( V_70 & V_80 ) , V_70 ) ;
F_5 ( & V_11 -> V_71 , V_8 ) ;
F_46 ( V_11 ) ;
F_3 ( & V_11 -> V_71 , V_8 ) ;
V_11 -> V_75 |= V_81 ;
V_11 -> V_75 &= ~ V_82 ;
F_44 ( V_11 -> V_75 , V_11 -> V_72 + V_77 ) ;
F_45 ( V_11 , V_78 ,
V_79 , ( V_70 & V_83 ) , V_70 ) ;
if ( V_70 & V_84 )
F_47 ( 1 , V_85
L_6
L_7 ) ;
F_5 ( & V_11 -> V_71 , V_8 ) ;
}
static int F_48 ( struct V_16 * V_11 , int V_68 )
{
struct V_14 * V_14 ;
struct V_86 * V_87 ;
unsigned long * V_22 ;
V_14 = V_11 -> V_14 = F_49 ( sizeof( struct V_14 ) ,
V_88 ) ;
if ( ! V_11 -> V_14 )
return - V_89 ;
V_87 = F_50 ( V_11 -> V_90 , V_88 | V_91 ,
V_92 ) ;
if ( ! V_87 ) {
F_51 ( L_8 ,
V_11 -> V_24 , V_92 ) ;
F_52 ( V_11 -> V_14 ) ;
return - V_89 ;
}
V_22 = F_53 ( F_54 ( V_23 ) ,
sizeof( long ) , V_88 ) ;
if ( V_22 == NULL ) {
F_51 ( L_9 , V_11 -> V_24 ) ;
F_55 ( V_87 , V_92 ) ;
F_52 ( V_14 ) ;
return - V_89 ;
}
V_14 -> V_15 = F_56 ( V_87 ) ;
V_14 -> V_22 = V_22 ;
F_40 ( V_11 , V_68 ) ;
return 0 ;
}
static void F_57 ( struct V_16 * V_11 )
{
unsigned long V_8 ;
T_4 V_70 ;
if ( ! F_58 ( V_11 -> V_20 ) )
return;
F_46 ( V_11 ) ;
F_3 ( & V_11 -> V_71 , V_8 ) ;
V_70 = F_59 ( V_11 -> V_72 + V_78 ) ;
if ( ! ( V_70 & V_83 ) )
goto V_49;
V_11 -> V_75 &= ~ V_81 ;
F_44 ( V_11 -> V_75 , V_11 -> V_72 + V_77 ) ;
F_45 ( V_11 , V_78 ,
V_79 , ! ( V_70 & V_83 ) , V_70 ) ;
V_49:
F_5 ( & V_11 -> V_71 , V_8 ) ;
}
static int T_5 F_60 ( void )
{
struct V_93 * V_94 ;
V_94 = (struct V_93 * ) V_95 ;
if ( ! V_94 || V_96 )
return 0 ;
return V_94 -> V_8 & V_97 ;
}
static int T_5 F_61 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
if ( V_98 )
return 0 ;
if ( V_99 ) {
F_10 ( V_85
L_10
L_11
L_12
L_13
L_14 ) ;
F_62 ( V_100 , V_101 ) ;
V_98 = 1 ;
return 0 ;
}
if ( ! F_63 () )
return 0 ;
F_64 (iommu, drhd)
if ( ! F_58 ( V_11 -> V_20 ) )
return 0 ;
return 1 ;
}
static int T_5 F_65 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
bool V_102 ;
int V_103 = 0 ;
int V_104 = 0 ;
V_102 = F_66 () ;
if ( F_67 () != 1 ) {
F_10 ( V_105 L_15 ) ;
goto error;
}
if ( V_102 ) {
F_68 ( L_16 ) ;
V_104 = ! F_60 () ;
if ( ! V_104 )
F_10 ( V_85
L_17
L_18
L_19 ) ;
}
F_64 (iommu, drhd) {
if ( V_11 -> V_106 )
continue;
F_69 ( - 1 , V_11 ) ;
F_57 ( V_11 ) ;
F_70 ( V_11 ) ;
}
F_64 (iommu, drhd) {
if ( ! F_58 ( V_11 -> V_20 ) )
continue;
if ( V_104 && ! F_71 ( V_11 -> V_20 ) ) {
F_10 ( V_105 L_20
L_21 , V_47 -> V_107 , V_11 -> V_20 ) ;
goto error;
}
}
F_64 (iommu, drhd) {
int V_108 = F_72 ( V_11 ) ;
if ( V_108 ) {
F_10 ( V_21 L_22
L_23 ,
V_47 -> V_107 , V_11 -> V_20 , V_108 ) ;
goto error;
}
}
F_64 (iommu, drhd) {
if ( ! F_58 ( V_11 -> V_20 ) )
continue;
if ( F_48 ( V_11 , V_104 ) )
goto error;
V_103 = 1 ;
}
if ( ! V_103 )
goto error;
V_109 = 1 ;
V_110 . V_111 = V_112 ;
F_68 ( L_24 , V_104 ? L_25 : L_26 ) ;
return V_104 ? V_113 : V_114 ;
error:
if ( V_102 )
F_12 ( L_27 ) ;
return - 1 ;
}
static void F_73 ( struct V_115 * V_116 ,
struct V_16 * V_11 )
{
struct V_117 * V_118 ;
T_2 V_56 ;
int V_17 ;
V_56 = V_116 -> V_56 ;
V_118 = (struct V_117 * ) ( V_116 + 1 ) ;
V_17 = ( V_116 -> V_119 - sizeof( struct V_115 ) )
/ sizeof( struct V_117 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_74 ( V_56 , V_118 -> V_120 , V_118 -> V_121 ,
V_122 ) ;
V_118 ++ ;
}
V_39 [ V_123 ] . V_56 = V_56 ;
V_39 [ V_123 ] . V_57 = F_75 ( V_118 -> V_120 , V_118 -> V_121 ) ;
V_39 [ V_123 ] . V_11 = V_11 ;
V_39 [ V_123 ] . V_40 = V_116 -> V_124 ;
V_123 ++ ;
}
static void F_76 ( struct V_115 * V_116 ,
struct V_16 * V_11 )
{
struct V_117 * V_118 ;
T_2 V_56 ;
int V_17 ;
V_56 = V_116 -> V_56 ;
V_118 = (struct V_117 * ) ( V_116 + 1 ) ;
V_17 = ( V_116 -> V_119 - sizeof( struct V_115 ) )
/ sizeof( struct V_117 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_74 ( V_56 , V_118 -> V_120 , V_118 -> V_121 ,
V_122 ) ;
V_118 ++ ;
}
V_43 [ V_125 ] . V_56 = V_56 ;
V_43 [ V_125 ] . V_57 = F_75 ( V_118 -> V_120 , V_118 -> V_121 ) ;
V_43 [ V_125 ] . V_11 = V_11 ;
V_43 [ V_125 ] . V_40 = V_116 -> V_124 ;
V_125 ++ ;
}
static int F_77 ( struct V_126 * V_127 ,
struct V_16 * V_11 )
{
struct V_128 * V_47 ;
struct V_115 * V_116 ;
void * V_48 , * V_49 ;
V_47 = (struct V_128 * ) V_127 ;
V_48 = ( void * ) ( V_47 + 1 ) ;
V_49 = ( ( void * ) V_47 ) + V_127 -> V_119 ;
while ( V_48 < V_49 ) {
V_116 = V_48 ;
if ( V_116 -> V_129 == V_130 ) {
if ( V_125 == V_42 ) {
F_10 ( V_85 L_28 ) ;
return - 1 ;
}
F_10 ( V_105 L_29
L_30 , V_116 -> V_124 ,
V_47 -> V_131 , V_11 -> V_24 ) ;
F_76 ( V_116 , V_11 ) ;
} else if ( V_116 -> V_129 == V_132 ) {
if ( V_123 == V_38 ) {
F_10 ( V_85 L_31 ) ;
return - 1 ;
}
F_10 ( V_105 L_32
L_33 , V_116 -> V_124 ,
V_47 -> V_131 ) ;
F_73 ( V_116 , V_11 ) ;
}
V_48 += V_116 -> V_119 ;
}
return 0 ;
}
static int T_5 F_67 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
int V_133 = 0 ;
int V_134 ;
F_64 (iommu, drhd)
if ( F_58 ( V_11 -> V_20 ) ) {
if ( F_77 ( V_47 -> V_135 , V_11 ) )
return - 1 ;
V_133 = 1 ;
}
if ( ! V_133 )
return 0 ;
for ( V_134 = 0 ; V_134 < V_136 ; V_134 ++ ) {
int V_137 = F_78 ( V_134 ) ;
if ( ! F_23 ( V_137 ) ) {
F_51 ( V_138 L_34
L_35 ,
V_137 ) ;
return - 1 ;
}
}
return 1 ;
}
static int T_5 F_79 ( void )
{
int V_108 ;
if ( ! V_109 )
return 0 ;
F_80 ( & V_55 ) ;
V_108 = F_81 () ;
F_82 ( & V_55 ) ;
return V_108 ;
}
static void F_83 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 = NULL ;
F_64 (iommu, drhd) {
if ( ! F_58 ( V_11 -> V_20 ) )
continue;
F_57 ( V_11 ) ;
}
}
static int F_84 ( int V_104 )
{
struct V_46 * V_47 ;
int V_103 = 0 ;
struct V_16 * V_11 = NULL ;
F_64 (iommu, drhd)
if ( V_11 -> V_106 )
F_85 ( V_11 ) ;
F_64 (iommu, drhd) {
if ( ! F_58 ( V_11 -> V_20 ) )
continue;
F_40 ( V_11 , V_104 ) ;
V_103 = 1 ;
}
if ( ! V_103 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_86 ( struct V_5 * V_5 , int V_139 ,
unsigned int V_140 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_141 = 1 ;
V_5 -> V_142 = V_41 -> V_143 ;
V_5 -> V_144 = 0 ;
V_5 -> V_145 = V_41 -> V_146 ;
V_5 -> V_139 = V_139 ;
V_5 -> V_147 = F_87 ( V_140 ) ;
V_5 -> V_148 = 1 ;
}
static int F_88 ( int V_2 ,
struct V_149 * V_150 ,
unsigned int V_151 , int V_139 ,
struct V_152 * V_153 )
{
int V_137 = F_78 ( V_153 -> V_154 ) ;
struct V_16 * V_11 ;
struct V_155 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
F_31 ( & V_55 ) ;
V_11 = F_23 ( V_137 ) ;
if ( ! V_11 ) {
F_12 ( L_36 , V_137 ) ;
V_9 = - V_156 ;
} else {
V_9 = F_6 ( V_11 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_12 ( L_37 ,
V_137 ) ;
V_9 = - V_89 ;
}
}
F_32 ( & V_55 ) ;
if ( V_9 < 0 )
return V_9 ;
F_86 ( & V_5 , V_139 , V_151 ) ;
F_30 ( & V_5 , V_137 ) ;
F_19 ( V_2 , & V_5 ) ;
F_89 ( V_157 , V_158 L_38
L_39
L_40
L_41
L_42 ,
V_153 -> V_154 , V_5 . V_141 , V_5 . V_159 , V_5 . V_142 ,
V_5 . V_148 , V_5 . V_144 , V_5 . V_145 ,
V_5 . V_160 , V_5 . V_139 , V_5 . V_147 ,
V_5 . V_52 , V_5 . V_51 , V_5 . V_50 ) ;
V_6 = (struct V_155 * ) V_150 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_161 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_162 = 0 ;
V_6 -> V_163 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_139 = V_153 -> V_164 ;
V_6 -> V_19 = 0 ;
V_6 -> V_165 = V_153 -> V_165 ;
V_6 -> V_166 = V_153 -> V_166 ;
if ( V_153 -> V_165 )
V_6 -> V_19 = 1 ;
return 0 ;
}
static int
F_90 ( struct V_167 * V_65 , const struct V_168 * V_19 ,
bool V_169 )
{
struct V_3 * V_4 = V_65 -> V_170 ;
unsigned int V_140 , V_2 = V_65 -> V_2 ;
struct V_5 V_5 ;
int V_171 ;
if ( ! F_91 ( V_172 ) )
return - V_173 ;
if ( ! F_92 ( V_19 , V_174 ) )
return - V_173 ;
if ( F_2 ( V_2 , & V_5 ) )
return - V_175 ;
V_171 = F_93 ( V_2 , V_4 , V_19 ) ;
if ( V_171 )
return V_171 ;
V_171 = V_41 -> V_176 ( V_4 -> V_177 , V_19 , & V_140 ) ;
if ( V_171 ) {
if ( F_93 ( V_2 , V_4 , V_65 -> V_178 ) )
F_51 ( L_43 , V_2 ) ;
return V_171 ;
}
V_5 . V_139 = V_4 -> V_139 ;
V_5 . V_147 = F_87 ( V_140 ) ;
F_19 ( V_2 , & V_5 ) ;
if ( V_4 -> V_179 )
F_94 ( V_4 ) ;
F_95 ( V_65 -> V_178 , V_19 ) ;
return 0 ;
}
static void F_96 ( struct V_44 * V_61 ,
unsigned int V_2 , unsigned int V_140 ,
struct V_180 * V_181 , T_2 V_36 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_13 = 0 ;
int V_182 ;
V_4 = F_1 ( V_2 ) ;
V_182 = F_17 ( V_2 , & V_13 ) ;
F_97 ( V_182 == - 1 ) ;
F_86 ( & V_5 , V_4 -> V_139 , V_140 ) ;
if ( V_61 )
F_36 ( & V_5 , V_61 ) ;
else
F_34 ( & V_5 , V_36 ) ;
F_19 ( V_2 , & V_5 ) ;
V_181 -> V_183 = V_184 ;
V_181 -> V_65 = V_13 ;
V_181 -> V_185 = V_186 | V_187 |
V_188 |
F_98 ( V_182 ) |
F_99 ( V_182 ) ;
}
static int F_100 ( struct V_44 * V_45 , int V_2 , int V_189 )
{
struct V_16 * V_11 ;
int V_9 ;
F_31 ( & V_55 ) ;
V_11 = F_24 ( V_45 ) ;
if ( ! V_11 ) {
F_10 ( V_21
L_44 , F_101 ( V_45 ) ) ;
V_9 = - V_190 ;
} else {
V_9 = F_6 ( V_11 , V_2 , V_189 ) ;
if ( V_9 < 0 ) {
F_10 ( V_21
L_45 ,
V_189 , F_101 ( V_45 ) ) ;
V_9 = - V_191 ;
}
}
F_32 ( & V_55 ) ;
return V_9 ;
}
static int F_102 ( struct V_44 * V_61 , unsigned int V_2 ,
int V_9 , int V_13 )
{
struct V_16 * V_11 ;
int V_108 = - V_190 ;
F_31 ( & V_55 ) ;
V_11 = F_24 ( V_61 ) ;
if ( V_11 ) {
F_18 ( V_2 , V_11 , V_9 , V_13 ) ;
V_108 = 0 ;
}
F_32 ( & V_55 ) ;
return V_108 ;
}
static int F_103 ( unsigned int V_2 , unsigned int V_40 )
{
int V_108 = - 1 ;
struct V_16 * V_11 ;
int V_9 ;
F_31 ( & V_55 ) ;
V_11 = F_22 ( V_40 ) ;
if ( V_11 ) {
V_9 = F_6 ( V_11 , V_2 , 1 ) ;
if ( V_9 >= 0 )
V_108 = 0 ;
}
F_32 ( & V_55 ) ;
return V_108 ;
}
