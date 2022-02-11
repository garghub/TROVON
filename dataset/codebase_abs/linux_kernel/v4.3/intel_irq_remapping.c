static bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
if ( V_5 & V_8 )
V_2 -> V_3 |= V_4 ;
}
static int F_5 ( struct V_1 * V_2 , int V_9 ,
struct V_10 * V_11 , T_2 V_12 )
{
struct V_13 * V_14 = V_2 -> V_13 ;
unsigned int V_15 = 0 ;
unsigned long V_3 ;
int V_16 ;
if ( ! V_12 || ! V_11 )
return - 1 ;
if ( V_12 > 1 ) {
V_12 = F_6 ( V_12 ) ;
V_15 = F_7 ( V_12 ) ;
}
if ( V_15 > F_8 ( V_2 -> V_17 ) ) {
F_9 ( L_1
L_2 , V_15 ,
F_8 ( V_2 -> V_17 ) ) ;
return - 1 ;
}
F_10 ( & V_18 , V_3 ) ;
V_16 = F_11 ( V_14 -> V_19 ,
V_20 , V_15 ) ;
if ( V_16 < 0 ) {
F_12 ( L_3 , V_2 -> V_21 ) ;
} else {
V_11 -> V_2 = V_2 ;
V_11 -> V_22 = V_16 ;
V_11 -> V_23 = 0 ;
V_11 -> V_24 = V_15 ;
V_11 -> V_25 = V_26 ;
}
F_13 ( & V_18 , V_3 ) ;
return V_16 ;
}
static int F_14 ( struct V_1 * V_2 , int V_16 , int V_15 )
{
struct V_27 V_28 ;
V_28 . V_29 = F_15 ( V_16 ) | V_30 | F_16 ( V_15 )
| V_31 ;
V_28 . V_32 = 0 ;
return F_17 ( & V_28 , V_2 ) ;
}
static int F_18 ( struct V_10 * V_11 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
struct V_33 * V_33 ;
int V_35 , V_16 ;
if ( ! V_11 )
return - 1 ;
F_10 ( & V_18 , V_3 ) ;
V_2 = V_11 -> V_2 ;
V_16 = V_11 -> V_22 + V_11 -> V_23 ;
V_33 = & V_2 -> V_13 -> V_36 [ V_16 ] ;
F_19 ( & V_33 -> V_29 , V_34 -> V_29 ) ;
F_19 ( & V_33 -> V_32 , V_34 -> V_32 ) ;
F_20 ( V_2 , V_33 , sizeof( * V_33 ) ) ;
V_35 = F_14 ( V_2 , V_16 , 0 ) ;
V_11 -> V_25 = V_33 -> V_37 ? V_38 : V_26 ;
F_13 ( & V_18 , V_3 ) ;
return V_35 ;
}
static struct V_1 * F_21 ( T_3 V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
if ( V_42 [ V_40 ] . V_43 == V_39 && V_42 [ V_40 ] . V_2 )
return V_42 [ V_40 ] . V_2 ;
return NULL ;
}
static struct V_1 * F_22 ( int V_44 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ )
if ( V_46 [ V_40 ] . V_43 == V_44 && V_46 [ V_40 ] . V_2 )
return V_46 [ V_40 ] . V_2 ;
return NULL ;
}
static struct V_1 * F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_24 ( V_48 ) ;
if ( ! V_50 )
return NULL ;
return V_50 -> V_2 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_33 * V_51 , * V_52 , * V_53 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_11 -> V_23 )
return 0 ;
V_2 = V_11 -> V_2 ;
V_16 = V_11 -> V_22 ;
V_51 = V_2 -> V_13 -> V_36 + V_16 ;
V_53 = V_51 + ( 1 << V_11 -> V_24 ) ;
for ( V_52 = V_51 ; V_52 < V_53 ; V_52 ++ ) {
F_19 ( & V_52 -> V_29 , 0 ) ;
F_19 ( & V_52 -> V_32 , 0 ) ;
}
F_26 ( V_2 -> V_13 -> V_19 , V_16 ,
V_11 -> V_24 ) ;
return F_14 ( V_2 , V_16 , V_11 -> V_24 ) ;
}
static void F_27 ( struct V_33 * V_33 , unsigned int V_54 ,
unsigned int V_55 , unsigned int V_56 )
{
if ( V_57 )
V_54 = V_58 ;
V_33 -> V_54 = V_54 ;
V_33 -> V_55 = V_55 ;
V_33 -> V_56 = V_56 ;
}
static int F_28 ( struct V_33 * V_33 , int V_44 )
{
int V_40 ;
T_2 V_56 = 0 ;
if ( ! V_33 )
return - 1 ;
F_29 ( & V_59 ) ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
if ( V_46 [ V_40 ] . V_2 && V_46 [ V_40 ] . V_43 == V_44 ) {
V_56 = ( V_46 [ V_40 ] . V_60 << 8 ) | V_46 [ V_40 ] . V_61 ;
break;
}
}
F_30 ( & V_59 ) ;
if ( V_56 == 0 ) {
F_12 ( L_4 , V_44 ) ;
return - 1 ;
}
F_27 ( V_33 , V_62 , V_63 , V_56 ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_33 , T_3 V_43 )
{
int V_40 ;
T_2 V_56 = 0 ;
if ( ! V_33 )
return - 1 ;
F_29 ( & V_59 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
if ( V_42 [ V_40 ] . V_2 && V_42 [ V_40 ] . V_43 == V_43 ) {
V_56 = ( V_42 [ V_40 ] . V_60 << 8 ) | V_42 [ V_40 ] . V_61 ;
break;
}
}
F_30 ( & V_59 ) ;
if ( V_56 == 0 ) {
F_12 ( L_5 , V_43 ) ;
return - 1 ;
}
F_27 ( V_33 , V_62 , V_64 , V_56 ) ;
return 0 ;
}
static int F_32 ( struct V_47 * V_65 , T_2 V_66 , void * V_67 )
{
struct V_68 * V_69 = V_67 ;
V_69 -> V_65 = V_65 ;
V_69 -> V_66 = V_66 ;
return 0 ;
}
static int F_33 ( struct V_33 * V_33 , struct V_47 * V_48 )
{
struct V_68 V_69 ;
if ( ! V_33 || ! V_48 )
return - 1 ;
F_34 ( V_48 , F_32 , & V_69 ) ;
if ( F_35 ( V_69 . V_66 ) != V_69 . V_65 -> V_60 -> V_70 )
F_27 ( V_33 , V_71 , V_63 ,
F_36 ( F_35 ( V_69 . V_66 ) ,
V_48 -> V_60 -> V_70 ) ) ;
else if ( V_69 . V_65 -> V_60 -> V_70 != V_48 -> V_60 -> V_70 )
F_27 ( V_33 , V_62 , V_63 , V_69 . V_66 ) ;
else
F_27 ( V_33 , V_62 , V_63 ,
F_36 ( V_48 -> V_60 -> V_70 , V_48 -> V_61 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_33 T_4 * V_72 ;
T_5 V_73 ;
unsigned int V_40 ;
T_6 V_74 ;
T_7 V_75 ;
if ( ! F_38 () ) {
F_12 ( L_6 ,
V_2 -> V_76 ) ;
F_2 ( V_2 ) ;
F_39 ( V_2 ) ;
return - V_77 ;
}
V_75 = F_40 ( V_2 -> V_6 + V_78 ) ;
if ( ( V_75 & V_79 )
!= V_80 )
return - V_77 ;
V_73 = V_75 & V_81 ;
V_74 = V_20 * sizeof( struct V_33 ) ;
V_72 = F_41 ( V_73 , V_74 ) ;
if ( ! V_72 )
return - V_82 ;
F_42 ( V_2 -> V_13 -> V_36 , V_72 , V_74 ) ;
F_20 ( V_2 , V_2 -> V_13 -> V_36 , V_74 ) ;
for ( V_40 = 0 ; V_40 < V_20 ; V_40 ++ ) {
if ( V_2 -> V_13 -> V_36 [ V_40 ] . V_83 )
F_43 ( V_2 -> V_13 -> V_19 , V_40 , 1 ) ;
}
F_44 ( V_72 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , int V_25 )
{
unsigned long V_3 ;
T_7 V_84 ;
T_1 V_85 ;
V_84 = F_46 ( ( void * ) V_2 -> V_13 -> V_36 ) ;
F_10 ( & V_2 -> V_86 , V_3 ) ;
F_47 ( V_2 -> V_6 + V_78 ,
( V_84 ) | F_48 ( V_25 ) | V_80 ) ;
F_49 ( V_2 -> V_87 | V_88 , V_2 -> V_6 + V_89 ) ;
F_50 ( V_2 , V_7 ,
F_4 , ( V_85 & V_90 ) , V_85 ) ;
F_13 ( & V_2 -> V_86 , V_3 ) ;
F_51 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_85 ;
F_10 ( & V_2 -> V_86 , V_3 ) ;
V_2 -> V_87 |= V_91 ;
V_2 -> V_87 &= ~ V_92 ;
F_49 ( V_2 -> V_87 , V_2 -> V_6 + V_89 ) ;
F_50 ( V_2 , V_7 ,
F_4 , ( V_85 & V_8 ) , V_85 ) ;
if ( V_85 & V_93 )
F_53 ( 1 , V_94
L_7
L_8 ) ;
F_13 ( & V_2 -> V_86 , V_3 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
struct V_95 * V_96 ;
unsigned long * V_19 ;
if ( V_2 -> V_13 )
return 0 ;
V_13 = F_55 ( sizeof( struct V_13 ) , V_97 ) ;
if ( ! V_13 )
return - V_82 ;
V_96 = F_56 ( V_2 -> V_98 , V_97 | V_99 ,
V_100 ) ;
if ( ! V_96 ) {
F_9 ( L_9 ,
V_2 -> V_21 , V_100 ) ;
goto V_101;
}
V_19 = F_57 ( F_58 ( V_20 ) ,
sizeof( long ) , V_102 ) ;
if ( V_19 == NULL ) {
F_9 ( L_10 , V_2 -> V_21 ) ;
goto V_103;
}
V_2 -> V_104 = F_59 ( F_60 () ,
0 , V_20 ,
NULL , & V_105 ,
V_2 ) ;
if ( ! V_2 -> V_104 ) {
F_9 ( L_11 , V_2 -> V_21 ) ;
goto V_106;
}
V_2 -> V_107 = F_61 ( V_2 -> V_104 ) ;
V_13 -> V_36 = F_62 ( V_96 ) ;
V_13 -> V_19 = V_19 ;
V_2 -> V_13 = V_13 ;
if ( ! V_2 -> V_108 ) {
F_63 ( - 1 , V_2 ) ;
F_64 ( V_2 ) ;
if ( F_65 ( V_2 ) ) {
F_9 ( L_12 ) ;
goto V_106;
}
}
F_3 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_37 ( V_2 ) )
F_9 ( L_13 ,
V_2 -> V_76 ) ;
else
F_66 ( L_14 ,
V_2 -> V_76 ) ;
}
F_45 ( V_2 , V_109 ) ;
return 0 ;
V_106:
F_67 ( V_19 ) ;
V_103:
F_68 ( V_96 , V_100 ) ;
V_101:
F_67 ( V_13 ) ;
V_2 -> V_13 = NULL ;
return - V_82 ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_13 ) {
if ( V_2 -> V_107 ) {
F_70 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
}
if ( V_2 -> V_104 ) {
F_70 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
}
F_71 ( ( unsigned long ) V_2 -> V_13 -> V_36 ,
V_100 ) ;
F_67 ( V_2 -> V_13 -> V_19 ) ;
F_67 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_85 ;
if ( ! F_72 ( V_2 -> V_17 ) )
return;
F_51 ( V_2 ) ;
F_10 ( & V_2 -> V_86 , V_3 ) ;
V_85 = F_40 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_85 & V_8 ) )
goto V_53;
V_2 -> V_87 &= ~ V_91 ;
F_49 ( V_2 -> V_87 , V_2 -> V_6 + V_89 ) ;
F_50 ( V_2 , V_7 ,
F_4 , ! ( V_85 & V_8 ) , V_85 ) ;
V_53:
F_13 ( & V_2 -> V_86 , V_3 ) ;
}
static int T_8 F_73 ( void )
{
struct V_110 * V_111 ;
V_111 = (struct V_110 * ) V_112 ;
if ( ! V_111 || V_113 )
return 0 ;
return V_111 -> V_3 & V_114 ;
}
static void T_8 F_74 ( void )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
F_75 (iommu, drhd) {
if ( F_72 ( V_2 -> V_17 ) ) {
F_39 ( V_2 ) ;
F_69 ( V_2 ) ;
}
}
if ( F_76 () )
F_12 ( L_15 ) ;
}
static int T_8 F_77 ( void )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
int V_115 = 0 ;
if ( V_116 ) {
F_12 ( L_16
L_17
L_18
L_19
L_20 ) ;
F_78 ( V_117 , V_118 ) ;
return - V_119 ;
}
if ( F_79 () < 0 )
return - V_119 ;
if ( ! F_80 () )
return - V_119 ;
if ( F_81 () != 1 ) {
F_66 ( L_21 ) ;
goto error;
}
F_75 (iommu, drhd)
if ( ! F_72 ( V_2 -> V_17 ) )
goto error;
if ( F_76 () ) {
V_115 = ! F_73 () ;
if ( ! V_115 ) {
F_66 ( L_22 ) ;
F_66 ( L_23 ) ;
}
}
F_75 (iommu, drhd) {
if ( V_115 && ! F_82 ( V_2 -> V_17 ) ) {
F_66 ( L_24 , V_2 -> V_76 ) ;
V_115 = 0 ;
}
}
V_109 = V_115 ;
if ( V_115 )
F_66 ( L_25 ) ;
F_75 (iommu, drhd) {
if ( F_54 ( V_2 ) ) {
F_9 ( L_26 ,
V_2 -> V_76 ) ;
goto error;
}
}
return 0 ;
error:
F_74 () ;
return - V_119 ;
}
static inline void F_83 ( void )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
if ( ! V_120 ) {
V_121 . V_122 |= 1 << V_123 ;
F_75 (iommu, drhd)
if ( ! F_84 ( V_2 -> V_124 ) ) {
V_121 . V_122 &=
~ ( 1 << V_123 ) ;
break;
}
}
}
static int T_8 F_85 ( void )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
bool V_125 = false ;
F_75 (iommu, drhd) {
if ( ! F_1 ( V_2 ) )
F_52 ( V_2 ) ;
V_125 = true ;
}
if ( ! V_125 )
goto error;
V_126 = 1 ;
F_83 () ;
F_66 ( L_27 , V_109 ? L_28 : L_29 ) ;
return V_109 ? V_127 : V_128 ;
error:
F_74 () ;
return - 1 ;
}
static int F_86 ( struct V_129 * V_130 ,
struct V_1 * V_2 ,
struct V_131 * V_50 )
{
struct V_132 * V_133 ;
T_3 V_60 ;
int V_12 , free = - 1 ;
V_60 = V_130 -> V_60 ;
V_133 = (struct V_132 * ) ( V_130 + 1 ) ;
V_12 = ( V_130 -> V_134 - sizeof( struct V_129 ) )
/ sizeof( struct V_132 ) ;
while ( -- V_12 > 0 ) {
V_60 = F_87 ( V_60 , V_133 -> V_135 , V_133 -> V_136 ,
V_137 ) ;
V_133 ++ ;
}
for ( V_12 = 0 ; V_12 < V_41 ; V_12 ++ ) {
if ( V_42 [ V_12 ] . V_2 == V_2 &&
V_42 [ V_12 ] . V_43 == V_130 -> V_138 )
return 0 ;
else if ( V_42 [ V_12 ] . V_2 == NULL && free == - 1 )
free = V_12 ;
}
if ( free == - 1 ) {
F_12 ( L_30 ) ;
return - V_139 ;
}
V_42 [ free ] . V_2 = V_2 ;
V_42 [ free ] . V_43 = V_130 -> V_138 ;
V_42 [ free ] . V_60 = V_60 ;
V_42 [ free ] . V_61 = F_88 ( V_133 -> V_135 , V_133 -> V_136 ) ;
F_66 ( L_31 ,
V_130 -> V_138 , V_50 -> V_140 ) ;
return 0 ;
}
static int F_89 ( struct V_129 * V_130 ,
struct V_1 * V_2 ,
struct V_131 * V_50 )
{
struct V_132 * V_133 ;
T_3 V_60 ;
int V_12 , free = - 1 ;
V_60 = V_130 -> V_60 ;
V_133 = (struct V_132 * ) ( V_130 + 1 ) ;
V_12 = ( V_130 -> V_134 - sizeof( struct V_129 ) )
/ sizeof( struct V_132 ) ;
while ( -- V_12 > 0 ) {
V_60 = F_87 ( V_60 , V_133 -> V_135 , V_133 -> V_136 ,
V_137 ) ;
V_133 ++ ;
}
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
if ( V_46 [ V_12 ] . V_2 == V_2 &&
V_46 [ V_12 ] . V_43 == V_130 -> V_138 )
return 0 ;
else if ( V_46 [ V_12 ] . V_2 == NULL && free == - 1 )
free = V_12 ;
}
if ( free == - 1 ) {
F_12 ( L_32 ) ;
return - V_139 ;
}
V_46 [ free ] . V_60 = V_60 ;
V_46 [ free ] . V_61 = F_88 ( V_133 -> V_135 , V_133 -> V_136 ) ;
V_46 [ free ] . V_2 = V_2 ;
V_46 [ free ] . V_43 = V_130 -> V_138 ;
F_66 ( L_33 ,
V_130 -> V_138 , V_50 -> V_140 , V_2 -> V_21 ) ;
return 0 ;
}
static int F_90 ( struct V_141 * V_142 ,
struct V_1 * V_2 )
{
int V_143 = 0 ;
struct V_131 * V_50 ;
struct V_129 * V_130 ;
void * V_51 , * V_53 ;
V_50 = (struct V_131 * ) V_142 ;
V_51 = ( void * ) ( V_50 + 1 ) ;
V_53 = ( ( void * ) V_50 ) + V_142 -> V_134 ;
while ( V_51 < V_53 && V_143 == 0 ) {
V_130 = V_51 ;
if ( V_130 -> V_144 == V_145 )
V_143 = F_89 ( V_130 , V_2 , V_50 ) ;
else if ( V_130 -> V_144 == V_146 )
V_143 = F_86 ( V_130 , V_2 , V_50 ) ;
V_51 += V_130 -> V_134 ;
}
return V_143 ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
if ( V_42 [ V_40 ] . V_2 == V_2 )
V_42 [ V_40 ] . V_2 = NULL ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ )
if ( V_46 [ V_40 ] . V_2 == V_2 )
V_46 [ V_40 ] . V_2 = NULL ;
}
static int T_8 F_81 ( void )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
bool V_147 = false ;
int V_148 ;
F_75 (iommu, drhd)
if ( F_72 ( V_2 -> V_17 ) ) {
if ( F_90 ( V_50 -> V_149 , V_2 ) )
return - 1 ;
V_147 = true ;
}
if ( ! V_147 )
return 0 ;
for ( V_148 = 0 ; V_148 < V_150 ; V_148 ++ ) {
int V_151 = F_92 ( V_148 ) ;
if ( ! F_22 ( V_151 ) ) {
F_9 ( V_152 L_34
L_35 ,
V_151 ) ;
return - 1 ;
}
}
return 1 ;
}
static int T_8 F_93 ( void )
{
int V_143 ;
if ( ! V_126 )
return 0 ;
F_94 ( & V_59 ) ;
V_143 = F_95 () ;
F_96 ( & V_59 ) ;
return V_143 ;
}
static void F_97 ( void )
{
struct V_49 * V_50 ;
struct V_1 * V_2 = NULL ;
F_75 (iommu, drhd) {
if ( ! F_72 ( V_2 -> V_17 ) )
continue;
F_39 ( V_2 ) ;
}
if ( ! V_120 )
V_121 . V_122 &= ~ ( 1 << V_123 ) ;
}
static int F_98 ( int V_115 )
{
struct V_49 * V_50 ;
bool V_125 = false ;
struct V_1 * V_2 = NULL ;
F_75 (iommu, drhd)
if ( V_2 -> V_108 )
F_99 ( V_2 ) ;
F_75 (iommu, drhd) {
if ( ! F_72 ( V_2 -> V_17 ) )
continue;
F_45 ( V_2 , V_115 ) ;
F_52 ( V_2 ) ;
V_125 = true ;
}
if ( ! V_125 )
goto error;
F_83 () ;
return 0 ;
error:
return - 1 ;
}
static void F_100 ( struct V_33 * V_33 , int V_153 , unsigned int V_154 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_83 = 1 ;
V_33 -> V_155 = V_44 -> V_156 ;
V_33 -> V_157 = 0 ;
V_33 -> V_158 = V_44 -> V_159 ;
V_33 -> V_153 = V_153 ;
V_33 -> V_160 = F_101 ( V_154 ) ;
V_33 -> V_161 = 1 ;
}
static struct V_162 * F_102 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_164 )
return NULL ;
switch ( V_164 -> type ) {
case V_165 :
V_2 = F_22 ( V_164 -> V_151 ) ;
break;
case V_166 :
V_2 = F_21 ( V_164 -> V_39 ) ;
break;
case V_167 :
case V_168 :
V_2 = F_23 ( V_164 -> V_169 ) ;
break;
default:
F_103 ( 1 ) ;
break;
}
return V_2 ? V_2 -> V_104 : NULL ;
}
static struct V_162 * F_104 ( struct V_163 * V_164 )
{
struct V_1 * V_2 ;
if ( ! V_164 )
return NULL ;
switch ( V_164 -> type ) {
case V_167 :
case V_168 :
V_2 = F_23 ( V_164 -> V_169 ) ;
if ( V_2 )
return V_2 -> V_107 ;
break;
default:
break;
}
return NULL ;
}
static int
F_105 ( struct V_170 * V_69 , const struct V_171 * V_15 ,
bool V_172 )
{
struct V_173 * V_174 = V_69 -> V_175 ;
struct V_33 * V_33 = & V_174 -> V_176 ;
struct V_177 * V_178 = F_106 ( V_69 ) ;
struct V_170 * V_179 = V_69 -> V_180 ;
int V_143 ;
V_143 = V_179 -> V_181 -> V_182 ( V_179 , V_15 , V_172 ) ;
if ( V_143 < 0 || V_143 == V_183 )
return V_143 ;
V_33 -> V_153 = V_178 -> V_153 ;
V_33 -> V_160 = F_101 ( V_178 -> V_184 ) ;
if ( V_174 -> V_10 . V_25 == V_26 )
F_18 ( & V_174 -> V_10 , V_33 ) ;
F_107 ( V_178 ) ;
return V_183 ;
}
static void F_108 ( struct V_170 * V_170 ,
struct V_185 * V_186 )
{
struct V_173 * V_174 = V_170 -> V_175 ;
* V_186 = V_174 -> V_187 ;
}
static int F_109 ( struct V_170 * V_69 , void * V_164 )
{
struct V_173 * V_174 = V_69 -> V_175 ;
struct V_188 * V_189 = V_164 ;
if ( ! V_189 ) {
F_18 ( & V_174 -> V_10 , & V_174 -> V_176 ) ;
} else {
struct V_33 V_190 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
F_110 ( & V_190 , & V_174 -> V_176 ) ;
V_190 . V_191 = 1 ;
V_190 . V_192 = 0 ;
V_190 . V_193 = V_189 -> V_153 ;
V_190 . V_194 = ( V_189 -> V_195 >>
( 32 - V_196 ) ) & ~ ( - 1UL << V_196 ) ;
V_190 . V_197 = ( V_189 -> V_195 >> 32 ) &
~ ( - 1UL << V_198 ) ;
F_18 ( & V_174 -> V_10 , & V_190 ) ;
}
return 0 ;
}
static void F_111 ( struct V_173 * V_69 ,
struct V_177 * V_177 ,
struct V_163 * V_164 ,
int V_16 , int V_23 )
{
struct V_199 * V_52 ;
struct V_33 * V_33 = & V_69 -> V_176 ;
struct V_185 * V_186 = & V_69 -> V_187 ;
F_100 ( V_33 , V_177 -> V_153 , V_177 -> V_184 ) ;
switch ( V_164 -> type ) {
case V_165 :
F_28 ( V_33 , V_164 -> V_151 ) ;
F_112 ( V_200 , V_201 L_36 ,
V_164 -> V_151 , V_33 -> V_83 , V_33 -> V_202 ,
V_33 -> V_155 , V_33 -> V_161 ,
V_33 -> V_157 , V_33 -> V_158 ,
V_33 -> V_203 , V_33 -> V_153 , V_33 -> V_160 ,
V_33 -> V_56 , V_33 -> V_55 , V_33 -> V_54 ) ;
V_52 = (struct V_199 * ) V_164 -> V_204 ;
V_164 -> V_204 = NULL ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_205 = ( V_16 >> 15 ) & 0x1 ;
V_52 -> V_206 = 0 ;
V_52 -> V_207 = 1 ;
V_52 -> V_16 = ( V_16 & 0x7fff ) ;
V_52 -> V_153 = V_164 -> V_208 ;
V_52 -> V_15 = 0 ;
V_52 -> V_209 = V_164 -> V_210 ;
V_52 -> V_211 = V_164 -> V_212 ;
if ( V_164 -> V_210 )
V_52 -> V_15 = 1 ;
break;
case V_166 :
case V_167 :
case V_168 :
if ( V_164 -> type == V_166 )
F_31 ( V_33 , V_164 -> V_39 ) ;
else
F_33 ( V_33 , V_164 -> V_169 ) ;
V_186 -> V_213 = V_214 ;
V_186 -> V_69 = V_23 ;
V_186 -> V_215 = V_216 | V_217 |
V_218 |
F_113 ( V_16 ) |
F_114 ( V_16 ) ;
break;
default:
F_103 ( 1 ) ;
break;
}
}
static void F_115 ( struct V_162 * V_219 ,
unsigned int V_220 , unsigned int V_221 )
{
struct V_170 * V_170 ;
struct V_173 * V_69 ;
struct V_10 * V_11 ;
unsigned long V_3 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_221 ; V_40 ++ ) {
V_170 = F_116 ( V_219 , V_220 + V_40 ) ;
if ( V_170 && V_170 -> V_175 ) {
V_69 = V_170 -> V_175 ;
V_11 = & V_69 -> V_10 ;
F_10 ( & V_18 , V_3 ) ;
F_25 ( V_11 ) ;
F_13 ( & V_18 , V_3 ) ;
F_117 ( V_170 ) ;
F_67 ( V_69 ) ;
}
}
}
static int F_118 ( struct V_162 * V_219 ,
unsigned int V_220 , unsigned int V_221 ,
void * V_222 )
{
struct V_1 * V_2 = V_219 -> V_223 ;
struct V_163 * V_164 = V_222 ;
struct V_173 * V_69 , * V_224 ;
struct V_170 * V_170 ;
struct V_177 * V_177 ;
int V_40 , V_143 , V_16 ;
if ( ! V_164 || ! V_2 )
return - V_77 ;
if ( V_221 > 1 && V_164 -> type != V_167 &&
V_164 -> type != V_168 )
return - V_77 ;
if ( V_164 -> type == V_167 )
V_164 -> V_3 &= ~ V_225 ;
V_143 = F_119 ( V_219 , V_220 , V_221 , V_222 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = - V_82 ;
V_69 = F_55 ( sizeof( * V_69 ) , V_97 ) ;
if ( ! V_69 )
goto V_226;
F_29 ( & V_59 ) ;
V_16 = F_5 ( V_2 , V_220 , & V_69 -> V_10 , V_221 ) ;
F_30 ( & V_59 ) ;
if ( V_16 < 0 ) {
F_12 ( L_37 ) ;
F_67 ( V_69 ) ;
goto V_226;
}
for ( V_40 = 0 ; V_40 < V_221 ; V_40 ++ ) {
V_170 = F_116 ( V_219 , V_220 + V_40 ) ;
V_177 = F_106 ( V_170 ) ;
if ( ! V_170 || ! V_177 ) {
V_143 = - V_77 ;
goto V_227;
}
if ( V_40 > 0 ) {
V_224 = F_55 ( sizeof( * V_224 ) , V_97 ) ;
if ( ! V_224 )
goto V_227;
V_224 -> V_10 = V_69 -> V_10 ;
V_224 -> V_10 . V_23 = V_40 ;
} else {
V_224 = V_69 ;
}
V_170 -> V_228 = ( V_16 << 16 ) + V_40 ;
V_170 -> V_175 = V_224 ;
V_170 -> V_181 = & V_229 ;
F_111 ( V_224 , V_177 , V_164 , V_16 , V_40 ) ;
F_120 ( V_220 + V_40 , V_230 ) ;
}
return 0 ;
V_227:
F_115 ( V_219 , V_220 , V_40 ) ;
V_226:
F_121 ( V_219 , V_220 , V_221 ) ;
return V_143 ;
}
static void F_122 ( struct V_162 * V_219 ,
unsigned int V_220 , unsigned int V_221 )
{
F_115 ( V_219 , V_220 , V_221 ) ;
F_121 ( V_219 , V_220 , V_221 ) ;
}
static void F_123 ( struct V_162 * V_219 ,
struct V_170 * V_170 )
{
struct V_173 * V_69 = V_170 -> V_175 ;
F_18 ( & V_69 -> V_10 , & V_69 -> V_176 ) ;
}
static void F_124 ( struct V_162 * V_219 ,
struct V_170 * V_170 )
{
struct V_173 * V_69 = V_170 -> V_175 ;
struct V_33 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
F_18 ( & V_69 -> V_10 , & V_52 ) ;
}
static int F_125 ( struct V_49 * V_231 , struct V_1 * V_2 )
{
int V_143 ;
int V_115 = F_126 () ;
if ( V_115 && ! F_82 ( V_2 -> V_17 ) ) {
F_66 ( L_38 ,
V_2 -> V_232 , V_2 -> V_17 ) ;
return - V_119 ;
}
if ( F_90 ( V_231 -> V_149 , V_2 ) ) {
F_12 ( L_39 ,
V_2 -> V_232 ) ;
return - V_119 ;
}
V_143 = F_54 ( V_2 ) ;
if ( V_143 ) {
F_9 ( L_26 ,
V_2 -> V_76 ) ;
F_69 ( V_2 ) ;
F_91 ( V_2 ) ;
} else {
F_52 ( V_2 ) ;
}
return V_143 ;
}
int F_127 ( struct V_49 * V_231 , bool V_233 )
{
int V_143 = 0 ;
struct V_1 * V_2 = V_231 -> V_2 ;
if ( ! V_126 )
return 0 ;
if ( V_2 == NULL )
return - V_77 ;
if ( ! F_72 ( V_2 -> V_17 ) )
return 0 ;
if ( F_128 ( V_123 ) &&
! F_84 ( V_2 -> V_124 ) )
return - V_234 ;
if ( V_233 ) {
if ( ! V_2 -> V_13 )
V_143 = F_125 ( V_231 , V_2 ) ;
} else {
if ( V_2 -> V_13 ) {
if ( ! F_129 ( V_2 -> V_13 -> V_19 ,
V_20 ) ) {
V_143 = - V_234 ;
} else {
F_39 ( V_2 ) ;
F_69 ( V_2 ) ;
F_91 ( V_2 ) ;
}
}
}
return V_143 ;
}
