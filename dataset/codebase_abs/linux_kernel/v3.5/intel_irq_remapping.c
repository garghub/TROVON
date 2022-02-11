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
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 = 0 ;
V_7 -> V_26 = V_20 ;
F_4 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_10 ( struct V_16 * V_13 , int V_9 , int V_20 )
{
struct V_27 V_28 ;
V_28 . V_29 = F_11 ( V_9 ) | V_30 | F_12 ( V_20 )
| V_31 ;
V_28 . V_32 = 0 ;
return F_13 ( & V_28 , V_13 ) ;
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
static int F_15 ( int V_2 , struct V_16 * V_13 , T_1 V_9 , T_1 V_33 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_9 ;
V_7 -> V_12 = V_33 ;
V_7 -> V_26 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_16 ( int V_2 , struct V_5 * V_34 )
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
F_17 ( & V_5 -> V_29 , V_34 -> V_29 ) ;
F_17 ( & V_5 -> V_32 , V_34 -> V_32 ) ;
F_18 ( V_13 , V_5 , sizeof( * V_5 ) ) ;
V_35 = F_10 ( V_13 , V_9 , 0 ) ;
F_4 ( & V_10 , V_8 ) ;
return V_35 ;
}
static struct V_16 * F_19 ( T_2 V_36 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_37 ; V_21 ++ )
if ( V_38 [ V_21 ] . V_39 == V_36 )
return V_38 [ V_21 ] . V_13 ;
return NULL ;
}
static struct V_16 * F_20 ( int V_40 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_41 ; V_21 ++ )
if ( V_42 [ V_21 ] . V_39 == V_40 )
return V_42 [ V_21 ] . V_13 ;
return NULL ;
}
static struct V_16 * F_21 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
V_46 = F_22 ( V_44 ) ;
if ( ! V_46 )
return NULL ;
return V_46 -> V_13 ;
}
static int F_23 ( struct V_1 * V_7 )
{
struct V_5 * V_47 , * V_6 , * V_48 ;
struct V_16 * V_13 ;
int V_9 ;
if ( V_7 -> V_12 )
return 0 ;
V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_11 + V_7 -> V_12 ;
V_47 = V_13 -> V_14 -> V_15 + V_9 ;
V_48 = V_47 + ( 1 << V_7 -> V_26 ) ;
for ( V_6 = V_47 ; V_6 < V_48 ; V_6 ++ ) {
F_17 ( & V_6 -> V_29 , 0 ) ;
F_17 ( & V_6 -> V_32 , 0 ) ;
}
return F_10 ( V_13 , V_9 , V_7 -> V_26 ) ;
}
static int F_24 ( int V_2 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_35 ;
if ( ! V_7 )
return - 1 ;
F_3 ( & V_10 , V_8 ) ;
V_35 = F_23 ( V_7 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_26 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return V_35 ;
}
static void F_25 ( struct V_5 * V_5 , unsigned int V_49 ,
unsigned int V_50 , unsigned int V_51 )
{
if ( V_52 )
V_49 = V_53 ;
V_5 -> V_49 = V_49 ;
V_5 -> V_50 = V_50 ;
V_5 -> V_51 = V_51 ;
}
static int F_26 ( struct V_5 * V_5 , int V_40 )
{
int V_21 ;
T_1 V_51 = 0 ;
if ( ! V_5 )
return - 1 ;
for ( V_21 = 0 ; V_21 < V_41 ; V_21 ++ ) {
if ( V_42 [ V_21 ] . V_39 == V_40 ) {
V_51 = ( V_42 [ V_21 ] . V_54 << 8 ) | V_42 [ V_21 ] . V_55 ;
break;
}
}
if ( V_51 == 0 ) {
F_27 ( L_4 , V_40 ) ;
return - 1 ;
}
F_25 ( V_5 , 1 , 0 , V_51 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_5 , T_2 V_39 )
{
int V_21 ;
T_1 V_51 = 0 ;
if ( ! V_5 )
return - 1 ;
for ( V_21 = 0 ; V_21 < V_37 ; V_21 ++ ) {
if ( V_38 [ V_21 ] . V_39 == V_39 ) {
V_51 = ( V_38 [ V_21 ] . V_54 << 8 ) | V_38 [ V_21 ] . V_55 ;
break;
}
}
if ( V_51 == 0 ) {
F_27 ( L_5 , V_39 ) ;
return - 1 ;
}
F_25 ( V_5 , V_56 , V_57 , V_51 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_5 , struct V_43 * V_44 )
{
struct V_43 * V_58 ;
if ( ! V_5 || ! V_44 )
return - 1 ;
if ( F_30 ( V_44 ) || ! V_44 -> V_54 -> V_59 ) {
F_25 ( V_5 , V_56 , V_60 ,
( V_44 -> V_54 -> V_61 << 8 ) | V_44 -> V_55 ) ;
return 0 ;
}
V_58 = F_31 ( V_44 ) ;
if ( V_58 ) {
if ( F_30 ( V_58 ) )
F_25 ( V_5 , V_62 , V_60 ,
( V_58 -> V_54 -> V_61 << 8 ) | V_44 -> V_54 -> V_61 ) ;
else
F_25 ( V_5 , V_56 , V_60 ,
( V_58 -> V_54 -> V_61 << 8 ) | V_58 -> V_55 ) ;
}
return 0 ;
}
static void F_32 ( struct V_16 * V_13 , int V_63 )
{
T_3 V_64 ;
T_4 V_65 ;
unsigned long V_8 ;
V_64 = F_33 ( ( void * ) V_13 -> V_14 -> V_15 ) ;
F_3 ( & V_13 -> V_66 , V_8 ) ;
F_34 ( V_13 -> V_67 + V_68 ,
( V_64 ) | F_35 ( V_63 ) | V_69 ) ;
V_13 -> V_70 |= V_71 ;
F_36 ( V_13 -> V_70 , V_13 -> V_67 + V_72 ) ;
F_37 ( V_13 , V_73 ,
V_74 , ( V_65 & V_75 ) , V_65 ) ;
F_4 ( & V_13 -> V_66 , V_8 ) ;
F_38 ( V_13 ) ;
F_3 ( & V_13 -> V_66 , V_8 ) ;
V_13 -> V_70 |= V_76 ;
F_36 ( V_13 -> V_70 , V_13 -> V_67 + V_72 ) ;
F_37 ( V_13 , V_73 ,
V_74 , ( V_65 & V_77 ) , V_65 ) ;
F_4 ( & V_13 -> V_66 , V_8 ) ;
}
static int F_39 ( struct V_16 * V_13 , int V_63 )
{
struct V_14 * V_14 ;
struct V_78 * V_79 ;
V_14 = V_13 -> V_14 = F_40 ( sizeof( struct V_14 ) ,
V_80 ) ;
if ( ! V_13 -> V_14 )
return - V_81 ;
V_79 = F_41 ( V_13 -> V_82 , V_80 | V_83 ,
V_84 ) ;
if ( ! V_79 ) {
F_9 ( V_23 L_6 ,
V_84 ) ;
F_42 ( V_13 -> V_14 ) ;
return - V_81 ;
}
V_14 -> V_15 = F_43 ( V_79 ) ;
F_32 ( V_13 , V_63 ) ;
return 0 ;
}
static void F_44 ( struct V_16 * V_13 )
{
unsigned long V_8 ;
T_4 V_65 ;
if ( ! F_45 ( V_13 -> V_22 ) )
return;
F_38 ( V_13 ) ;
F_3 ( & V_13 -> V_66 , V_8 ) ;
V_65 = F_46 ( V_13 -> V_67 + V_73 ) ;
if ( ! ( V_65 & V_77 ) )
goto V_48;
V_13 -> V_70 &= ~ V_76 ;
F_36 ( V_13 -> V_70 , V_13 -> V_67 + V_72 ) ;
F_37 ( V_13 , V_73 ,
V_74 , ! ( V_65 & V_77 ) , V_65 ) ;
V_48:
F_4 ( & V_13 -> V_66 , V_8 ) ;
}
static int T_5 F_47 ( void )
{
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_87 ;
if ( ! V_86 || V_88 )
return 0 ;
return V_86 -> V_8 & V_89 ;
}
static int T_5 F_48 ( void )
{
struct V_45 * V_46 ;
if ( V_90 )
return 0 ;
if ( ! F_49 () )
return 0 ;
F_50 (drhd) {
struct V_16 * V_13 = V_46 -> V_13 ;
if ( ! F_45 ( V_13 -> V_22 ) )
return 0 ;
}
return 1 ;
}
static int T_5 F_51 ( void )
{
struct V_45 * V_46 ;
int V_91 = 0 ;
int V_92 = 0 ;
if ( F_52 () != 1 ) {
F_9 ( V_93 L_7 ) ;
return - 1 ;
}
if ( F_53 () ) {
V_92 = ! F_47 () ;
F_54 ( ! V_92 , V_94
L_8
L_9
L_10 ) ;
}
F_50 (drhd) {
struct V_16 * V_13 = V_46 -> V_13 ;
if ( V_13 -> V_95 )
continue;
F_55 ( - 1 , V_13 ) ;
F_44 ( V_13 ) ;
F_56 ( V_13 ) ;
}
F_50 (drhd) {
struct V_16 * V_13 = V_46 -> V_13 ;
if ( ! F_45 ( V_13 -> V_22 ) )
continue;
if ( V_92 && ! F_57 ( V_13 -> V_22 ) ) {
F_9 ( V_93 L_11
L_12 , V_46 -> V_96 , V_13 -> V_22 ) ;
return - 1 ;
}
}
F_50 (drhd) {
int V_97 ;
struct V_16 * V_13 = V_46 -> V_13 ;
V_97 = F_58 ( V_13 ) ;
if ( V_97 ) {
F_9 ( V_23 L_13
L_14 ,
V_46 -> V_96 , V_13 -> V_22 , V_97 ) ;
return - 1 ;
}
}
F_50 (drhd) {
struct V_16 * V_13 = V_46 -> V_13 ;
if ( ! F_45 ( V_13 -> V_22 ) )
continue;
if ( F_39 ( V_13 , V_92 ) )
goto error;
V_91 = 1 ;
}
if ( ! V_91 )
goto error;
V_98 = 1 ;
F_59 ( L_15 , V_92 ? L_16 : L_17 ) ;
return V_92 ? V_99 : V_100 ;
error:
return - 1 ;
}
static void F_60 ( struct V_101 * V_102 ,
struct V_16 * V_13 )
{
struct V_103 * V_104 ;
T_2 V_54 ;
int V_17 ;
V_54 = V_102 -> V_54 ;
V_104 = (struct V_103 * ) ( V_102 + 1 ) ;
V_17 = ( V_102 -> V_105 - sizeof( struct V_101 ) )
/ sizeof( struct V_103 ) ;
while ( -- V_17 > 0 ) {
V_54 = F_61 ( V_54 , V_104 -> V_44 , V_104 -> V_106 ,
V_107 ) ;
V_104 ++ ;
}
V_38 [ V_108 ] . V_54 = V_54 ;
V_38 [ V_108 ] . V_55 = F_62 ( V_104 -> V_44 , V_104 -> V_106 ) ;
V_38 [ V_108 ] . V_13 = V_13 ;
V_38 [ V_108 ] . V_39 = V_102 -> V_109 ;
V_108 ++ ;
}
static void F_63 ( struct V_101 * V_102 ,
struct V_16 * V_13 )
{
struct V_103 * V_104 ;
T_2 V_54 ;
int V_17 ;
V_54 = V_102 -> V_54 ;
V_104 = (struct V_103 * ) ( V_102 + 1 ) ;
V_17 = ( V_102 -> V_105 - sizeof( struct V_101 ) )
/ sizeof( struct V_103 ) ;
while ( -- V_17 > 0 ) {
V_54 = F_61 ( V_54 , V_104 -> V_44 , V_104 -> V_106 ,
V_107 ) ;
V_104 ++ ;
}
V_42 [ V_110 ] . V_54 = V_54 ;
V_42 [ V_110 ] . V_55 = F_62 ( V_104 -> V_44 , V_104 -> V_106 ) ;
V_42 [ V_110 ] . V_13 = V_13 ;
V_42 [ V_110 ] . V_39 = V_102 -> V_109 ;
V_110 ++ ;
}
static int F_64 ( struct V_111 * V_112 ,
struct V_16 * V_13 )
{
struct V_113 * V_46 ;
struct V_101 * V_102 ;
void * V_47 , * V_48 ;
V_46 = (struct V_113 * ) V_112 ;
V_47 = ( void * ) ( V_46 + 1 ) ;
V_48 = ( ( void * ) V_46 ) + V_112 -> V_105 ;
while ( V_47 < V_48 ) {
V_102 = V_47 ;
if ( V_102 -> V_114 == V_115 ) {
if ( V_110 == V_41 ) {
F_9 ( V_94 L_18 ) ;
return - 1 ;
}
F_9 ( V_93 L_19
L_20 , V_102 -> V_109 ,
V_46 -> V_116 , V_13 -> V_117 ) ;
F_63 ( V_102 , V_13 ) ;
} else if ( V_102 -> V_114 == V_118 ) {
if ( V_108 == V_37 ) {
F_9 ( V_94 L_21 ) ;
return - 1 ;
}
F_9 ( V_93 L_22
L_23 , V_102 -> V_109 ,
V_46 -> V_116 ) ;
F_60 ( V_102 , V_13 ) ;
}
V_47 += V_102 -> V_105 ;
}
return 0 ;
}
int T_5 F_52 ( void )
{
struct V_45 * V_46 ;
int V_119 = 0 ;
F_50 (drhd) {
struct V_16 * V_13 = V_46 -> V_13 ;
if ( F_45 ( V_13 -> V_22 ) ) {
if ( F_64 ( V_46 -> V_120 , V_13 ) )
return - 1 ;
V_119 = 1 ;
}
}
if ( V_119 && V_110 != V_121 ) {
F_9 ( V_94
L_24 ) ;
return - 1 ;
}
return V_119 ;
}
int T_5 F_65 ( void )
{
if ( ! V_98 )
return 0 ;
return F_66 () ;
}
static void F_67 ( void )
{
struct V_45 * V_46 ;
struct V_16 * V_13 = NULL ;
F_68 (iommu, drhd) {
if ( ! F_45 ( V_13 -> V_22 ) )
continue;
F_44 ( V_13 ) ;
}
}
static int F_69 ( int V_92 )
{
struct V_45 * V_46 ;
int V_91 = 0 ;
struct V_16 * V_13 = NULL ;
F_68 (iommu, drhd)
if ( V_13 -> V_95 )
F_70 ( V_13 ) ;
F_68 (iommu, drhd) {
if ( ! F_45 ( V_13 -> V_22 ) )
continue;
F_32 ( V_13 , V_92 ) ;
V_91 = 1 ;
}
if ( ! V_91 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_71 ( struct V_5 * V_5 , int V_122 ,
unsigned int V_123 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_24 = 1 ;
V_5 -> V_124 = V_40 -> V_125 ;
V_5 -> V_126 = 0 ;
V_5 -> V_127 = V_40 -> V_128 ;
V_5 -> V_122 = V_122 ;
V_5 -> V_129 = F_72 ( V_123 ) ;
V_5 -> V_130 = 1 ;
}
static int F_73 ( int V_2 ,
struct V_131 * V_132 ,
unsigned int V_133 , int V_122 ,
struct V_134 * V_135 )
{
int V_136 = F_74 ( V_135 -> V_137 ) ;
struct V_16 * V_13 = F_20 ( V_136 ) ;
struct V_138 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
if ( ! V_13 ) {
F_75 ( L_25 , V_136 ) ;
return - V_139 ;
}
V_6 = (struct V_138 * ) V_132 ;
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_75 ( L_26 , V_136 ) ;
return - V_81 ;
}
F_71 ( & V_5 , V_122 , V_133 ) ;
F_26 ( & V_5 , V_136 ) ;
F_16 ( V_2 , & V_5 ) ;
F_76 ( V_140 , V_141 L_27
L_28
L_29
L_30
L_31 ,
V_135 -> V_137 , V_5 . V_24 , V_5 . V_142 , V_5 . V_124 ,
V_5 . V_130 , V_5 . V_126 , V_5 . V_127 ,
V_5 . V_143 , V_5 . V_122 , V_5 . V_129 ,
V_5 . V_51 , V_5 . V_50 , V_5 . V_49 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_144 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_145 = 0 ;
V_6 -> V_146 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_122 = V_135 -> V_147 ;
V_6 -> V_20 = 0 ;
V_6 -> V_148 = V_135 -> V_148 ;
V_6 -> V_149 = V_135 -> V_149 ;
if ( V_135 -> V_148 )
V_6 -> V_20 = 1 ;
return 0 ;
}
static int
F_77 ( struct V_150 * V_151 , const struct V_152 * V_20 ,
bool V_153 )
{
struct V_3 * V_4 = V_151 -> V_154 ;
unsigned int V_123 , V_2 = V_151 -> V_2 ;
struct V_5 V_5 ;
if ( ! F_78 ( V_20 , V_155 ) )
return - V_156 ;
if ( F_2 ( V_2 , & V_5 ) )
return - V_157 ;
if ( F_79 ( V_2 , V_4 , V_20 ) )
return - V_157 ;
V_123 = V_40 -> V_158 ( V_4 -> V_159 , V_20 ) ;
V_5 . V_122 = V_4 -> V_122 ;
V_5 . V_129 = F_72 ( V_123 ) ;
F_16 ( V_2 , & V_5 ) ;
if ( V_4 -> V_160 )
F_80 ( V_4 ) ;
F_81 ( V_151 -> V_161 , V_20 ) ;
return 0 ;
}
static void F_82 ( struct V_43 * V_162 ,
unsigned int V_2 , unsigned int V_123 ,
struct V_163 * V_164 , T_2 V_36 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_12 = 0 ;
int V_165 ;
V_4 = F_1 ( V_2 ) ;
V_165 = F_14 ( V_2 , & V_12 ) ;
F_83 ( V_165 == - 1 ) ;
F_71 ( & V_5 , V_4 -> V_122 , V_123 ) ;
if ( V_162 )
F_29 ( & V_5 , V_162 ) ;
else
F_28 ( & V_5 , V_36 ) ;
F_16 ( V_2 , & V_5 ) ;
V_164 -> V_166 = V_167 ;
V_164 -> V_151 = V_12 ;
V_164 -> V_168 = V_169 | V_170 |
V_171 |
F_84 ( V_165 ) |
F_85 ( V_165 ) ;
}
static int F_86 ( struct V_43 * V_44 , int V_2 , int V_172 )
{
struct V_16 * V_13 ;
int V_9 ;
V_13 = F_21 ( V_44 ) ;
if ( ! V_13 ) {
F_9 ( V_23
L_32 , F_87 ( V_44 ) ) ;
return - V_173 ;
}
V_9 = F_5 ( V_13 , V_2 , V_172 ) ;
if ( V_9 < 0 ) {
F_9 ( V_23
L_33 , V_172 ,
F_87 ( V_44 ) ) ;
return - V_174 ;
}
return V_9 ;
}
static int F_88 ( struct V_43 * V_162 , unsigned int V_2 ,
int V_9 , int V_12 )
{
struct V_16 * V_13 ;
V_13 = F_21 ( V_162 ) ;
if ( ! V_13 )
return - V_173 ;
F_15 ( V_2 , V_13 , V_9 , V_12 ) ;
return 0 ;
}
static int F_89 ( unsigned int V_2 , unsigned int V_39 )
{
struct V_16 * V_13 = F_19 ( V_39 ) ;
int V_9 ;
if ( ! V_13 )
return - 1 ;
V_9 = F_5 ( V_13 , V_2 , 1 ) ;
if ( V_9 < 0 )
return - 1 ;
return 0 ;
}
