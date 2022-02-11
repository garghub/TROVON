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
#if F_19 ( V_37 )
if ( ( V_33 -> V_38 == 1 ) || ( V_34 -> V_38 == 1 ) ) {
bool V_39 ;
V_39 = F_20 ( & V_33 -> V_29 , & V_33 -> V_32 ,
V_33 -> V_29 , V_33 -> V_32 ,
V_34 -> V_29 , V_34 -> V_32 ) ;
F_21 ( ! V_39 ) ;
} else
#endif
{
F_22 ( & V_33 -> V_29 , V_34 -> V_29 ) ;
F_22 ( & V_33 -> V_32 , V_34 -> V_32 ) ;
}
F_23 ( V_2 , V_33 , sizeof( * V_33 ) ) ;
V_35 = F_14 ( V_2 , V_16 , 0 ) ;
V_11 -> V_25 = V_33 -> V_38 ? V_40 : V_26 ;
F_13 ( & V_18 , V_3 ) ;
return V_35 ;
}
static struct V_1 * F_24 ( T_3 V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
if ( V_44 [ V_42 ] . V_45 == V_41 && V_44 [ V_42 ] . V_2 )
return V_44 [ V_42 ] . V_2 ;
return NULL ;
}
static struct V_1 * F_25 ( int V_46 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ )
if ( V_48 [ V_42 ] . V_45 == V_46 && V_48 [ V_42 ] . V_2 )
return V_48 [ V_42 ] . V_2 ;
return NULL ;
}
static struct V_1 * F_26 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
V_52 = F_27 ( V_50 ) ;
if ( ! V_52 )
return NULL ;
return V_52 -> V_2 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_33 * V_53 , * V_54 , * V_55 ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_11 -> V_23 )
return 0 ;
V_2 = V_11 -> V_2 ;
V_16 = V_11 -> V_22 ;
V_53 = V_2 -> V_13 -> V_36 + V_16 ;
V_55 = V_53 + ( 1 << V_11 -> V_24 ) ;
for ( V_54 = V_53 ; V_54 < V_55 ; V_54 ++ ) {
F_22 ( & V_54 -> V_29 , 0 ) ;
F_22 ( & V_54 -> V_32 , 0 ) ;
}
F_29 ( V_2 -> V_13 -> V_19 , V_16 ,
V_11 -> V_24 ) ;
return F_14 ( V_2 , V_16 , V_11 -> V_24 ) ;
}
static void F_30 ( struct V_33 * V_33 , unsigned int V_56 ,
unsigned int V_57 , unsigned int V_58 )
{
if ( V_59 )
V_56 = V_60 ;
V_33 -> V_56 = V_56 ;
V_33 -> V_57 = V_57 ;
V_33 -> V_58 = V_58 ;
}
static int F_31 ( struct V_33 * V_33 , int V_46 )
{
int V_42 ;
T_2 V_58 = 0 ;
if ( ! V_33 )
return - 1 ;
F_32 ( & V_61 ) ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ ) {
if ( V_48 [ V_42 ] . V_2 && V_48 [ V_42 ] . V_45 == V_46 ) {
V_58 = ( V_48 [ V_42 ] . V_62 << 8 ) | V_48 [ V_42 ] . V_63 ;
break;
}
}
F_33 ( & V_61 ) ;
if ( V_58 == 0 ) {
F_12 ( L_4 , V_46 ) ;
return - 1 ;
}
F_30 ( V_33 , V_64 , V_65 , V_58 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_33 , T_3 V_45 )
{
int V_42 ;
T_2 V_58 = 0 ;
if ( ! V_33 )
return - 1 ;
F_32 ( & V_61 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_44 [ V_42 ] . V_2 && V_44 [ V_42 ] . V_45 == V_45 ) {
V_58 = ( V_44 [ V_42 ] . V_62 << 8 ) | V_44 [ V_42 ] . V_63 ;
break;
}
}
F_33 ( & V_61 ) ;
if ( V_58 == 0 ) {
F_12 ( L_5 , V_45 ) ;
return - 1 ;
}
F_30 ( V_33 , V_64 , V_66 , V_58 ) ;
return 0 ;
}
static int F_35 ( struct V_49 * V_67 , T_2 V_68 , void * V_69 )
{
struct V_70 * V_71 = V_69 ;
V_71 -> V_67 = V_67 ;
V_71 -> V_68 = V_68 ;
return 0 ;
}
static int F_36 ( struct V_33 * V_33 , struct V_49 * V_50 )
{
struct V_70 V_71 ;
if ( ! V_33 || ! V_50 )
return - 1 ;
F_37 ( V_50 , F_35 , & V_71 ) ;
if ( F_38 ( V_71 . V_68 ) != V_71 . V_67 -> V_62 -> V_72 )
F_30 ( V_33 , V_73 , V_65 ,
F_39 ( F_38 ( V_71 . V_68 ) ,
V_50 -> V_62 -> V_72 ) ) ;
else if ( V_71 . V_67 -> V_62 -> V_72 != V_50 -> V_62 -> V_72 )
F_30 ( V_33 , V_64 , V_65 , V_71 . V_68 ) ;
else
F_30 ( V_33 , V_64 , V_65 ,
F_39 ( V_50 -> V_62 -> V_72 , V_50 -> V_63 ) ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_33 * V_74 ;
T_4 V_75 ;
unsigned int V_42 ;
T_5 V_76 ;
T_6 V_77 ;
V_77 = F_41 ( V_2 -> V_6 + V_78 ) ;
if ( ( V_77 & V_79 )
!= V_80 )
return - V_81 ;
V_75 = V_77 & V_82 ;
V_76 = V_20 * sizeof( struct V_33 ) ;
V_74 = F_42 ( V_75 , V_76 , V_83 ) ;
if ( ! V_74 )
return - V_84 ;
memcpy ( V_2 -> V_13 -> V_36 , V_74 , V_76 ) ;
F_23 ( V_2 , V_2 -> V_13 -> V_36 , V_76 ) ;
for ( V_42 = 0 ; V_42 < V_20 ; V_42 ++ ) {
if ( V_2 -> V_13 -> V_36 [ V_42 ] . V_85 )
F_43 ( V_2 -> V_13 -> V_19 , V_42 , 1 ) ;
}
F_44 ( V_74 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , int V_25 )
{
unsigned long V_3 ;
T_6 V_86 ;
T_1 V_87 ;
V_86 = F_46 ( ( void * ) V_2 -> V_13 -> V_36 ) ;
F_10 ( & V_2 -> V_88 , V_3 ) ;
F_47 ( V_2 -> V_6 + V_78 ,
( V_86 ) | F_48 ( V_25 ) | V_80 ) ;
F_49 ( V_2 -> V_89 | V_90 , V_2 -> V_6 + V_91 ) ;
F_50 ( V_2 , V_7 ,
F_4 , ( V_87 & V_92 ) , V_87 ) ;
F_13 ( & V_2 -> V_88 , V_3 ) ;
F_51 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_87 ;
F_10 ( & V_2 -> V_88 , V_3 ) ;
V_2 -> V_89 |= V_93 ;
V_2 -> V_89 &= ~ V_94 ;
F_49 ( V_2 -> V_89 , V_2 -> V_6 + V_91 ) ;
F_50 ( V_2 , V_7 ,
F_4 , ( V_87 & V_8 ) , V_87 ) ;
if ( V_87 & V_95 )
F_53 ( 1 , V_96
L_6
L_7 ) ;
F_13 ( & V_2 -> V_88 , V_3 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_13 * V_13 ;
struct V_97 * V_98 ;
unsigned long * V_19 ;
if ( V_2 -> V_13 )
return 0 ;
V_13 = F_55 ( sizeof( struct V_13 ) , V_99 ) ;
if ( ! V_13 )
return - V_84 ;
V_98 = F_56 ( V_2 -> V_100 , V_99 | V_101 ,
V_102 ) ;
if ( ! V_98 ) {
F_9 ( L_8 ,
V_2 -> V_21 , V_102 ) ;
goto V_103;
}
V_19 = F_57 ( F_58 ( V_20 ) ,
sizeof( long ) , V_104 ) ;
if ( V_19 == NULL ) {
F_9 ( L_9 , V_2 -> V_21 ) ;
goto V_105;
}
V_2 -> V_106 = F_59 ( F_60 () ,
0 , V_20 ,
NULL , & V_107 ,
V_2 ) ;
if ( ! V_2 -> V_106 ) {
F_9 ( L_10 , V_2 -> V_21 ) ;
goto V_108;
}
V_2 -> V_109 = F_61 ( V_2 -> V_106 ) ;
V_13 -> V_36 = F_62 ( V_98 ) ;
V_13 -> V_19 = V_19 ;
V_2 -> V_13 = V_13 ;
if ( ! V_2 -> V_110 ) {
F_63 ( - 1 , V_2 ) ;
F_64 ( V_2 ) ;
if ( F_65 ( V_2 ) ) {
F_9 ( L_11 ) ;
goto V_108;
}
}
F_3 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
if ( ! F_66 () ) {
F_12 ( L_12 ,
V_2 -> V_111 ) ;
F_2 ( V_2 ) ;
F_67 ( V_2 ) ;
} else if ( F_40 ( V_2 ) )
F_9 ( L_13 ,
V_2 -> V_111 ) ;
else
F_68 ( L_14 ,
V_2 -> V_111 ) ;
}
F_45 ( V_2 , V_112 ) ;
return 0 ;
V_108:
F_69 ( V_19 ) ;
V_105:
F_70 ( V_98 , V_102 ) ;
V_103:
F_69 ( V_13 ) ;
V_2 -> V_13 = NULL ;
return - V_84 ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_13 ) {
if ( V_2 -> V_109 ) {
F_72 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
}
if ( V_2 -> V_106 ) {
F_72 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
}
F_73 ( ( unsigned long ) V_2 -> V_13 -> V_36 ,
V_102 ) ;
F_69 ( V_2 -> V_13 -> V_19 ) ;
F_69 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_87 ;
if ( ! F_74 ( V_2 -> V_17 ) )
return;
F_51 ( V_2 ) ;
F_10 ( & V_2 -> V_88 , V_3 ) ;
V_87 = F_4 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_87 & V_8 ) )
goto V_55;
V_2 -> V_89 &= ~ V_93 ;
F_49 ( V_2 -> V_89 , V_2 -> V_6 + V_91 ) ;
F_50 ( V_2 , V_7 ,
F_4 , ! ( V_87 & V_8 ) , V_87 ) ;
V_55:
F_13 ( & V_2 -> V_88 , V_3 ) ;
}
static int T_7 F_75 ( void )
{
struct V_113 * V_114 ;
V_114 = (struct V_113 * ) V_115 ;
if ( ! V_114 || V_116 )
return 0 ;
return V_114 -> V_3 & V_117 ;
}
static void T_7 F_76 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
F_77 (iommu, drhd) {
if ( F_74 ( V_2 -> V_17 ) ) {
F_67 ( V_2 ) ;
F_71 ( V_2 ) ;
}
}
if ( F_78 () )
F_12 ( L_15 ) ;
}
static int T_7 F_79 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
int V_118 = 0 ;
if ( V_119 ) {
F_12 ( L_16
L_17
L_18
L_19
L_20 ) ;
F_80 ( V_120 , V_121 ) ;
return - V_122 ;
}
if ( F_81 () < 0 )
return - V_122 ;
if ( ! F_82 () )
return - V_122 ;
if ( F_83 () ) {
F_68 ( L_21 ) ;
goto error;
}
F_77 (iommu, drhd)
if ( ! F_74 ( V_2 -> V_17 ) )
goto error;
if ( F_78 () ) {
V_118 = ! F_75 () ;
if ( ! V_118 ) {
F_68 ( L_22 ) ;
F_68 ( L_23 ) ;
}
}
F_77 (iommu, drhd) {
if ( V_118 && ! F_84 ( V_2 -> V_17 ) ) {
F_68 ( L_24 , V_2 -> V_111 ) ;
V_118 = 0 ;
}
}
V_112 = V_118 ;
if ( V_118 )
F_68 ( L_25 ) ;
F_77 (iommu, drhd) {
if ( F_54 ( V_2 ) ) {
F_9 ( L_26 ,
V_2 -> V_111 ) ;
goto error;
}
}
return 0 ;
error:
F_76 () ;
return - V_122 ;
}
static inline void F_85 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
if ( ! V_123 ) {
if ( F_86 ( V_124 ) )
V_125 . V_126 |= 1 << V_127 ;
F_77 (iommu, drhd)
if ( ! F_87 ( V_2 -> V_128 ) ) {
V_125 . V_126 &=
~ ( 1 << V_127 ) ;
break;
}
}
}
static int T_7 F_88 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
bool V_129 = false ;
F_77 (iommu, drhd) {
if ( ! F_1 ( V_2 ) )
F_52 ( V_2 ) ;
V_129 = true ;
}
if ( ! V_129 )
goto error;
V_130 = 1 ;
F_85 () ;
F_68 ( L_27 , V_112 ? L_28 : L_29 ) ;
return V_112 ? V_131 : V_132 ;
error:
F_76 () ;
return - 1 ;
}
static int F_89 ( struct V_133 * V_134 ,
struct V_1 * V_2 ,
struct V_135 * V_52 )
{
struct V_136 * V_137 ;
T_3 V_62 ;
int V_12 , free = - 1 ;
V_62 = V_134 -> V_62 ;
V_137 = (struct V_136 * ) ( V_134 + 1 ) ;
V_12 = ( V_134 -> V_138 - sizeof( struct V_133 ) )
/ sizeof( struct V_136 ) ;
while ( -- V_12 > 0 ) {
V_62 = F_90 ( V_62 , V_137 -> V_139 , V_137 -> V_140 ,
V_141 ) ;
V_137 ++ ;
}
for ( V_12 = 0 ; V_12 < V_43 ; V_12 ++ ) {
if ( V_44 [ V_12 ] . V_2 == V_2 &&
V_44 [ V_12 ] . V_45 == V_134 -> V_142 )
return 0 ;
else if ( V_44 [ V_12 ] . V_2 == NULL && free == - 1 )
free = V_12 ;
}
if ( free == - 1 ) {
F_12 ( L_30 ) ;
return - V_143 ;
}
V_44 [ free ] . V_2 = V_2 ;
V_44 [ free ] . V_45 = V_134 -> V_142 ;
V_44 [ free ] . V_62 = V_62 ;
V_44 [ free ] . V_63 = F_91 ( V_137 -> V_139 , V_137 -> V_140 ) ;
F_68 ( L_31 ,
V_134 -> V_142 , V_52 -> V_144 ) ;
return 0 ;
}
static int F_92 ( struct V_133 * V_134 ,
struct V_1 * V_2 ,
struct V_135 * V_52 )
{
struct V_136 * V_137 ;
T_3 V_62 ;
int V_12 , free = - 1 ;
V_62 = V_134 -> V_62 ;
V_137 = (struct V_136 * ) ( V_134 + 1 ) ;
V_12 = ( V_134 -> V_138 - sizeof( struct V_133 ) )
/ sizeof( struct V_136 ) ;
while ( -- V_12 > 0 ) {
V_62 = F_90 ( V_62 , V_137 -> V_139 , V_137 -> V_140 ,
V_141 ) ;
V_137 ++ ;
}
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ ) {
if ( V_48 [ V_12 ] . V_2 == V_2 &&
V_48 [ V_12 ] . V_45 == V_134 -> V_142 )
return 0 ;
else if ( V_48 [ V_12 ] . V_2 == NULL && free == - 1 )
free = V_12 ;
}
if ( free == - 1 ) {
F_12 ( L_32 ) ;
return - V_143 ;
}
V_48 [ free ] . V_62 = V_62 ;
V_48 [ free ] . V_63 = F_91 ( V_137 -> V_139 , V_137 -> V_140 ) ;
V_48 [ free ] . V_2 = V_2 ;
V_48 [ free ] . V_45 = V_134 -> V_142 ;
F_68 ( L_33 ,
V_134 -> V_142 , V_52 -> V_144 , V_2 -> V_21 ) ;
return 0 ;
}
static int F_93 ( struct V_145 * V_146 ,
struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_135 * V_52 ;
struct V_133 * V_134 ;
void * V_53 , * V_55 ;
V_52 = (struct V_135 * ) V_146 ;
V_53 = ( void * ) ( V_52 + 1 ) ;
V_55 = ( ( void * ) V_52 ) + V_146 -> V_138 ;
while ( V_53 < V_55 && V_39 == 0 ) {
V_134 = V_53 ;
if ( V_134 -> V_147 == V_148 )
V_39 = F_92 ( V_134 , V_2 , V_52 ) ;
else if ( V_134 -> V_147 == V_149 )
V_39 = F_89 ( V_134 , V_2 , V_52 ) ;
V_53 += V_134 -> V_138 ;
}
return V_39 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
if ( V_44 [ V_42 ] . V_2 == V_2 )
V_44 [ V_42 ] . V_2 = NULL ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ )
if ( V_48 [ V_42 ] . V_2 == V_2 )
V_48 [ V_42 ] . V_2 = NULL ;
}
static int T_7 F_83 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
bool V_150 = false ;
int V_151 ;
F_77 (iommu, drhd) {
int V_39 ;
if ( ! F_74 ( V_2 -> V_17 ) )
continue;
V_39 = F_93 ( V_52 -> V_152 , V_2 ) ;
if ( V_39 )
return V_39 ;
V_150 = true ;
}
if ( ! V_150 )
return - V_122 ;
for ( V_151 = 0 ; V_151 < V_153 ; V_151 ++ ) {
int V_154 = F_95 ( V_151 ) ;
if ( ! F_25 ( V_154 ) ) {
F_9 ( V_155 L_34
L_35 ,
V_154 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_7 F_96 ( void )
{
int V_39 ;
if ( ! V_130 )
return 0 ;
F_97 ( & V_61 ) ;
V_39 = F_98 () ;
F_99 ( & V_61 ) ;
return V_39 ;
}
static void F_100 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 = NULL ;
F_77 (iommu, drhd) {
if ( ! F_74 ( V_2 -> V_17 ) )
continue;
F_67 ( V_2 ) ;
}
if ( ! V_123 )
V_125 . V_126 &= ~ ( 1 << V_127 ) ;
}
static int F_101 ( int V_118 )
{
struct V_51 * V_52 ;
bool V_129 = false ;
struct V_1 * V_2 = NULL ;
F_77 (iommu, drhd)
if ( V_2 -> V_110 )
F_102 ( V_2 ) ;
F_77 (iommu, drhd) {
if ( ! F_74 ( V_2 -> V_17 ) )
continue;
F_45 ( V_2 , V_118 ) ;
F_52 ( V_2 ) ;
V_129 = true ;
}
if ( ! V_129 )
goto error;
F_85 () ;
return 0 ;
error:
return - 1 ;
}
static void F_103 ( struct V_33 * V_33 , int V_156 , unsigned int V_157 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_85 = 1 ;
V_33 -> V_158 = V_46 -> V_159 ;
V_33 -> V_160 = 0 ;
V_33 -> V_161 = V_46 -> V_162 ;
V_33 -> V_156 = V_156 ;
V_33 -> V_163 = F_104 ( V_157 ) ;
V_33 -> V_164 = 1 ;
}
static struct V_165 * F_105 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_167 )
return NULL ;
switch ( V_167 -> type ) {
case V_168 :
V_2 = F_25 ( V_167 -> V_154 ) ;
break;
case V_169 :
V_2 = F_24 ( V_167 -> V_41 ) ;
break;
case V_170 :
case V_171 :
V_2 = F_26 ( V_167 -> V_172 ) ;
break;
default:
F_106 ( 1 ) ;
break;
}
return V_2 ? V_2 -> V_106 : NULL ;
}
static struct V_165 * F_107 ( struct V_166 * V_167 )
{
struct V_1 * V_2 ;
if ( ! V_167 )
return NULL ;
switch ( V_167 -> type ) {
case V_170 :
case V_171 :
V_2 = F_26 ( V_167 -> V_172 ) ;
if ( V_2 )
return V_2 -> V_109 ;
break;
default:
break;
}
return NULL ;
}
static int
F_108 ( struct V_173 * V_71 , const struct V_174 * V_15 ,
bool V_175 )
{
struct V_176 * V_177 = V_71 -> V_178 ;
struct V_33 * V_33 = & V_177 -> V_179 ;
struct V_180 * V_181 = F_109 ( V_71 ) ;
struct V_173 * V_182 = V_71 -> V_183 ;
int V_39 ;
V_39 = V_182 -> V_184 -> V_185 ( V_182 , V_15 , V_175 ) ;
if ( V_39 < 0 || V_39 == V_186 )
return V_39 ;
V_33 -> V_156 = V_181 -> V_156 ;
V_33 -> V_163 = F_104 ( V_181 -> V_187 ) ;
if ( V_177 -> V_10 . V_25 == V_26 )
F_18 ( & V_177 -> V_10 , V_33 ) ;
F_110 ( V_181 ) ;
return V_186 ;
}
static void F_111 ( struct V_173 * V_173 ,
struct V_188 * V_189 )
{
struct V_176 * V_177 = V_173 -> V_178 ;
* V_189 = V_177 -> V_190 ;
}
static int F_112 ( struct V_173 * V_71 , void * V_167 )
{
struct V_176 * V_177 = V_71 -> V_178 ;
struct V_191 * V_192 = V_167 ;
if ( ! V_192 ) {
F_18 ( & V_177 -> V_10 , & V_177 -> V_179 ) ;
} else {
struct V_33 V_193 ;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
F_113 ( & V_193 , & V_177 -> V_179 ) ;
V_193 . V_194 = 1 ;
V_193 . V_195 = 0 ;
V_193 . V_196 = V_192 -> V_156 ;
V_193 . V_197 = ( V_192 -> V_198 >>
( 32 - V_199 ) ) & ~ ( - 1UL << V_199 ) ;
V_193 . V_200 = ( V_192 -> V_198 >> 32 ) &
~ ( - 1UL << V_201 ) ;
F_18 ( & V_177 -> V_10 , & V_193 ) ;
}
return 0 ;
}
static void F_114 ( struct V_176 * V_71 ,
struct V_180 * V_180 ,
struct V_166 * V_167 ,
int V_16 , int V_23 )
{
struct V_202 * V_54 ;
struct V_33 * V_33 = & V_71 -> V_179 ;
struct V_188 * V_189 = & V_71 -> V_190 ;
F_103 ( V_33 , V_180 -> V_156 , V_180 -> V_187 ) ;
switch ( V_167 -> type ) {
case V_168 :
F_31 ( V_33 , V_167 -> V_154 ) ;
F_115 ( V_203 , V_204 L_36 ,
V_167 -> V_154 , V_33 -> V_85 , V_33 -> V_205 ,
V_33 -> V_158 , V_33 -> V_164 ,
V_33 -> V_160 , V_33 -> V_161 ,
V_33 -> V_206 , V_33 -> V_156 , V_33 -> V_163 ,
V_33 -> V_58 , V_33 -> V_57 , V_33 -> V_56 ) ;
V_54 = (struct V_202 * ) V_167 -> V_207 ;
V_167 -> V_207 = NULL ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_208 = ( V_16 >> 15 ) & 0x1 ;
V_54 -> V_209 = 0 ;
V_54 -> V_210 = 1 ;
V_54 -> V_16 = ( V_16 & 0x7fff ) ;
V_54 -> V_156 = V_167 -> V_211 ;
V_54 -> V_15 = 0 ;
V_54 -> V_212 = V_167 -> V_213 ;
V_54 -> V_214 = V_167 -> V_215 ;
if ( V_167 -> V_213 )
V_54 -> V_15 = 1 ;
break;
case V_169 :
case V_170 :
case V_171 :
if ( V_167 -> type == V_169 )
F_34 ( V_33 , V_167 -> V_41 ) ;
else
F_36 ( V_33 , V_167 -> V_172 ) ;
V_189 -> V_216 = V_217 ;
V_189 -> V_71 = V_23 ;
V_189 -> V_218 = V_219 | V_220 |
V_221 |
F_116 ( V_16 ) |
F_117 ( V_16 ) ;
break;
default:
F_106 ( 1 ) ;
break;
}
}
static void F_118 ( struct V_165 * V_222 ,
unsigned int V_223 , unsigned int V_224 )
{
struct V_173 * V_173 ;
struct V_176 * V_71 ;
struct V_10 * V_11 ;
unsigned long V_3 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_224 ; V_42 ++ ) {
V_173 = F_119 ( V_222 , V_223 + V_42 ) ;
if ( V_173 && V_173 -> V_178 ) {
V_71 = V_173 -> V_178 ;
V_11 = & V_71 -> V_10 ;
F_10 ( & V_18 , V_3 ) ;
F_28 ( V_11 ) ;
F_13 ( & V_18 , V_3 ) ;
F_120 ( V_173 ) ;
F_69 ( V_71 ) ;
}
}
}
static int F_121 ( struct V_165 * V_222 ,
unsigned int V_223 , unsigned int V_224 ,
void * V_225 )
{
struct V_1 * V_2 = V_222 -> V_226 ;
struct V_166 * V_167 = V_225 ;
struct V_176 * V_71 , * V_227 ;
struct V_173 * V_173 ;
struct V_180 * V_180 ;
int V_42 , V_39 , V_16 ;
if ( ! V_167 || ! V_2 )
return - V_81 ;
if ( V_224 > 1 && V_167 -> type != V_170 &&
V_167 -> type != V_171 )
return - V_81 ;
if ( V_167 -> type == V_170 )
V_167 -> V_3 &= ~ V_228 ;
V_39 = F_122 ( V_222 , V_223 , V_224 , V_225 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = - V_84 ;
V_71 = F_55 ( sizeof( * V_71 ) , V_99 ) ;
if ( ! V_71 )
goto V_229;
F_32 ( & V_61 ) ;
V_16 = F_5 ( V_2 , V_223 , & V_71 -> V_10 , V_224 ) ;
F_33 ( & V_61 ) ;
if ( V_16 < 0 ) {
F_12 ( L_37 ) ;
F_69 ( V_71 ) ;
goto V_229;
}
for ( V_42 = 0 ; V_42 < V_224 ; V_42 ++ ) {
V_173 = F_119 ( V_222 , V_223 + V_42 ) ;
V_180 = F_109 ( V_173 ) ;
if ( ! V_173 || ! V_180 ) {
V_39 = - V_81 ;
goto V_230;
}
if ( V_42 > 0 ) {
V_227 = F_55 ( sizeof( * V_227 ) , V_99 ) ;
if ( ! V_227 )
goto V_230;
V_227 -> V_10 = V_71 -> V_10 ;
V_227 -> V_10 . V_23 = V_42 ;
} else {
V_227 = V_71 ;
}
V_173 -> V_231 = ( V_16 << 16 ) + V_42 ;
V_173 -> V_178 = V_227 ;
V_173 -> V_184 = & V_232 ;
F_114 ( V_227 , V_180 , V_167 , V_16 , V_42 ) ;
F_123 ( V_223 + V_42 , V_233 ) ;
}
return 0 ;
V_230:
F_118 ( V_222 , V_223 , V_42 ) ;
V_229:
F_124 ( V_222 , V_223 , V_224 ) ;
return V_39 ;
}
static void F_125 ( struct V_165 * V_222 ,
unsigned int V_223 , unsigned int V_224 )
{
F_118 ( V_222 , V_223 , V_224 ) ;
F_124 ( V_222 , V_223 , V_224 ) ;
}
static void F_126 ( struct V_165 * V_222 ,
struct V_173 * V_173 )
{
struct V_176 * V_71 = V_173 -> V_178 ;
F_18 ( & V_71 -> V_10 , & V_71 -> V_179 ) ;
}
static void F_127 ( struct V_165 * V_222 ,
struct V_173 * V_173 )
{
struct V_176 * V_71 = V_173 -> V_178 ;
struct V_33 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_18 ( & V_71 -> V_10 , & V_54 ) ;
}
static int F_128 ( struct V_51 * V_234 , struct V_1 * V_2 )
{
int V_39 ;
int V_118 = F_129 () ;
if ( V_118 && ! F_84 ( V_2 -> V_17 ) ) {
F_68 ( L_38 ,
V_2 -> V_235 , V_2 -> V_17 ) ;
return - V_122 ;
}
if ( F_93 ( V_234 -> V_152 , V_2 ) ) {
F_12 ( L_39 ,
V_2 -> V_235 ) ;
return - V_122 ;
}
V_39 = F_54 ( V_2 ) ;
if ( V_39 ) {
F_9 ( L_26 ,
V_2 -> V_111 ) ;
F_71 ( V_2 ) ;
F_94 ( V_2 ) ;
} else {
F_52 ( V_2 ) ;
}
return V_39 ;
}
int F_130 ( struct V_51 * V_234 , bool V_236 )
{
int V_39 = 0 ;
struct V_1 * V_2 = V_234 -> V_2 ;
if ( ! V_130 )
return 0 ;
if ( V_2 == NULL )
return - V_81 ;
if ( ! F_74 ( V_2 -> V_17 ) )
return 0 ;
if ( F_131 ( V_127 ) &&
! F_87 ( V_2 -> V_128 ) )
return - V_237 ;
if ( V_236 ) {
if ( ! V_2 -> V_13 )
V_39 = F_128 ( V_234 , V_2 ) ;
} else {
if ( V_2 -> V_13 ) {
if ( ! F_132 ( V_2 -> V_13 -> V_19 ,
V_20 ) ) {
V_39 = - V_237 ;
} else {
F_67 ( V_2 ) ;
F_71 ( V_2 ) ;
F_94 ( V_2 ) ;
}
}
}
return V_39 ;
}
