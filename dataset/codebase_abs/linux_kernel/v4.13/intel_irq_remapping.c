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
struct V_99 * V_100 ;
if ( V_2 -> V_13 )
return 0 ;
V_13 = F_55 ( sizeof( struct V_13 ) , V_101 ) ;
if ( ! V_13 )
return - V_84 ;
V_100 = F_56 ( V_2 -> V_102 , V_101 | V_103 ,
V_104 ) ;
if ( ! V_100 ) {
F_9 ( L_8 ,
V_2 -> V_21 , V_104 ) ;
goto V_105;
}
V_19 = F_57 ( F_58 ( V_20 ) ,
sizeof( long ) , V_106 ) ;
if ( V_19 == NULL ) {
F_9 ( L_9 , V_2 -> V_21 ) ;
goto V_107;
}
V_98 = F_59 ( L_10 , V_2 -> V_21 ) ;
if ( ! V_98 )
goto V_108;
V_2 -> V_109 =
F_60 ( F_61 () ,
0 , V_20 ,
V_98 , & V_110 ,
V_2 ) ;
F_62 ( V_98 ) ;
if ( ! V_2 -> V_109 ) {
F_9 ( L_11 , V_2 -> V_21 ) ;
goto V_108;
}
V_2 -> V_111 =
F_63 ( V_2 -> V_109 ,
L_12 ,
V_2 -> V_21 ) ;
V_13 -> V_36 = F_64 ( V_100 ) ;
V_13 -> V_19 = V_19 ;
V_2 -> V_13 = V_13 ;
if ( ! V_2 -> V_112 ) {
F_65 ( - 1 , V_2 ) ;
F_66 ( V_2 ) ;
if ( F_67 ( V_2 ) ) {
F_9 ( L_13 ) ;
goto V_108;
}
}
F_3 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
if ( ! F_68 () ) {
F_12 ( L_14 ,
V_2 -> V_113 ) ;
F_2 ( V_2 ) ;
F_69 ( V_2 ) ;
} else if ( F_40 ( V_2 ) )
F_9 ( L_15 ,
V_2 -> V_113 ) ;
else
F_70 ( L_16 ,
V_2 -> V_113 ) ;
}
F_45 ( V_2 , V_114 ) ;
return 0 ;
V_108:
F_71 ( V_19 ) ;
V_107:
F_72 ( V_100 , V_104 ) ;
V_105:
F_71 ( V_13 ) ;
V_2 -> V_13 = NULL ;
return - V_84 ;
}
static void F_73 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_13 ) {
if ( V_2 -> V_111 ) {
F_74 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
}
if ( V_2 -> V_109 ) {
F_74 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
}
F_75 ( ( unsigned long ) V_2 -> V_13 -> V_36 ,
V_104 ) ;
F_71 ( V_2 -> V_13 -> V_19 ) ;
F_71 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_87 ;
if ( ! F_76 ( V_2 -> V_17 ) )
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
static int T_7 F_77 ( void )
{
struct V_115 * V_116 ;
V_116 = (struct V_115 * ) V_117 ;
if ( ! V_116 || V_118 )
return 0 ;
return V_116 -> V_3 & V_119 ;
}
static void T_7 F_78 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
F_79 (iommu, drhd) {
if ( F_76 ( V_2 -> V_17 ) ) {
F_69 ( V_2 ) ;
F_73 ( V_2 ) ;
}
}
if ( F_80 () )
F_12 ( L_17 ) ;
}
static int T_7 F_81 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
int V_120 = 0 ;
if ( V_121 ) {
F_12 ( L_18
L_19
L_20
L_21
L_22 ) ;
F_82 ( V_122 , V_123 ) ;
return - V_124 ;
}
if ( F_83 () < 0 )
return - V_124 ;
if ( ! F_84 () )
return - V_124 ;
if ( F_85 () ) {
F_70 ( L_23 ) ;
goto error;
}
F_79 (iommu, drhd)
if ( ! F_76 ( V_2 -> V_17 ) )
goto error;
if ( F_80 () ) {
V_120 = ! F_77 () ;
if ( ! V_120 ) {
F_70 ( L_24 ) ;
F_70 ( L_25 ) ;
}
}
F_79 (iommu, drhd) {
if ( V_120 && ! F_86 ( V_2 -> V_17 ) ) {
F_70 ( L_26 , V_2 -> V_113 ) ;
V_120 = 0 ;
}
}
V_114 = V_120 ;
if ( V_120 )
F_70 ( L_27 ) ;
F_79 (iommu, drhd) {
if ( F_54 ( V_2 ) ) {
F_9 ( L_28 ,
V_2 -> V_113 ) ;
goto error;
}
}
return 0 ;
error:
F_78 () ;
return - V_124 ;
}
static inline void F_87 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
if ( ! V_125 ) {
if ( F_88 ( V_126 ) )
V_127 . V_128 |= 1 << V_129 ;
F_79 (iommu, drhd)
if ( ! F_89 ( V_2 -> V_130 ) ) {
V_127 . V_128 &=
~ ( 1 << V_129 ) ;
break;
}
}
}
static int T_7 F_90 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
bool V_131 = false ;
F_79 (iommu, drhd) {
if ( ! F_1 ( V_2 ) )
F_52 ( V_2 ) ;
V_131 = true ;
}
if ( ! V_131 )
goto error;
V_132 = 1 ;
F_87 () ;
F_70 ( L_29 , V_114 ? L_30 : L_31 ) ;
return V_114 ? V_133 : V_134 ;
error:
F_78 () ;
return - 1 ;
}
static int F_91 ( struct V_135 * V_136 ,
struct V_1 * V_2 ,
struct V_137 * V_52 )
{
struct V_138 * V_139 ;
T_3 V_62 ;
int V_12 , free = - 1 ;
V_62 = V_136 -> V_62 ;
V_139 = (struct V_138 * ) ( V_136 + 1 ) ;
V_12 = ( V_136 -> V_140 - sizeof( struct V_135 ) )
/ sizeof( struct V_138 ) ;
while ( -- V_12 > 0 ) {
V_62 = F_92 ( V_62 , V_139 -> V_141 , V_139 -> V_142 ,
V_143 ) ;
V_139 ++ ;
}
for ( V_12 = 0 ; V_12 < V_43 ; V_12 ++ ) {
if ( V_44 [ V_12 ] . V_2 == V_2 &&
V_44 [ V_12 ] . V_45 == V_136 -> V_144 )
return 0 ;
else if ( V_44 [ V_12 ] . V_2 == NULL && free == - 1 )
free = V_12 ;
}
if ( free == - 1 ) {
F_12 ( L_32 ) ;
return - V_145 ;
}
V_44 [ free ] . V_2 = V_2 ;
V_44 [ free ] . V_45 = V_136 -> V_144 ;
V_44 [ free ] . V_62 = V_62 ;
V_44 [ free ] . V_63 = F_93 ( V_139 -> V_141 , V_139 -> V_142 ) ;
F_70 ( L_33 ,
V_136 -> V_144 , V_52 -> V_146 ) ;
return 0 ;
}
static int F_94 ( struct V_135 * V_136 ,
struct V_1 * V_2 ,
struct V_137 * V_52 )
{
struct V_138 * V_139 ;
T_3 V_62 ;
int V_12 , free = - 1 ;
V_62 = V_136 -> V_62 ;
V_139 = (struct V_138 * ) ( V_136 + 1 ) ;
V_12 = ( V_136 -> V_140 - sizeof( struct V_135 ) )
/ sizeof( struct V_138 ) ;
while ( -- V_12 > 0 ) {
V_62 = F_92 ( V_62 , V_139 -> V_141 , V_139 -> V_142 ,
V_143 ) ;
V_139 ++ ;
}
for ( V_12 = 0 ; V_12 < V_47 ; V_12 ++ ) {
if ( V_48 [ V_12 ] . V_2 == V_2 &&
V_48 [ V_12 ] . V_45 == V_136 -> V_144 )
return 0 ;
else if ( V_48 [ V_12 ] . V_2 == NULL && free == - 1 )
free = V_12 ;
}
if ( free == - 1 ) {
F_12 ( L_34 ) ;
return - V_145 ;
}
V_48 [ free ] . V_62 = V_62 ;
V_48 [ free ] . V_63 = F_93 ( V_139 -> V_141 , V_139 -> V_142 ) ;
V_48 [ free ] . V_2 = V_2 ;
V_48 [ free ] . V_45 = V_136 -> V_144 ;
F_70 ( L_35 ,
V_136 -> V_144 , V_52 -> V_146 , V_2 -> V_21 ) ;
return 0 ;
}
static int F_95 ( struct V_147 * V_148 ,
struct V_1 * V_2 )
{
int V_39 = 0 ;
struct V_137 * V_52 ;
struct V_135 * V_136 ;
void * V_53 , * V_55 ;
V_52 = (struct V_137 * ) V_148 ;
V_53 = ( void * ) ( V_52 + 1 ) ;
V_55 = ( ( void * ) V_52 ) + V_148 -> V_140 ;
while ( V_53 < V_55 && V_39 == 0 ) {
V_136 = V_53 ;
if ( V_136 -> V_149 == V_150 )
V_39 = F_94 ( V_136 , V_2 , V_52 ) ;
else if ( V_136 -> V_149 == V_151 )
V_39 = F_91 ( V_136 , V_2 , V_52 ) ;
V_53 += V_136 -> V_140 ;
}
return V_39 ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ )
if ( V_44 [ V_42 ] . V_2 == V_2 )
V_44 [ V_42 ] . V_2 = NULL ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ )
if ( V_48 [ V_42 ] . V_2 == V_2 )
V_48 [ V_42 ] . V_2 = NULL ;
}
static int T_7 F_85 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
bool V_152 = false ;
int V_153 ;
F_79 (iommu, drhd) {
int V_39 ;
if ( ! F_76 ( V_2 -> V_17 ) )
continue;
V_39 = F_95 ( V_52 -> V_154 , V_2 ) ;
if ( V_39 )
return V_39 ;
V_152 = true ;
}
if ( ! V_152 )
return - V_124 ;
for ( V_153 = 0 ; V_153 < V_155 ; V_153 ++ ) {
int V_156 = F_97 ( V_153 ) ;
if ( ! F_25 ( V_156 ) ) {
F_9 ( V_157 L_36
L_37 ,
V_156 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_7 F_98 ( void )
{
int V_39 ;
if ( ! V_132 )
return 0 ;
F_99 ( & V_61 ) ;
V_39 = F_100 () ;
F_101 ( & V_61 ) ;
return V_39 ;
}
static void F_102 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_2 = NULL ;
F_79 (iommu, drhd) {
if ( ! F_76 ( V_2 -> V_17 ) )
continue;
F_69 ( V_2 ) ;
}
if ( ! V_125 )
V_127 . V_128 &= ~ ( 1 << V_129 ) ;
}
static int F_103 ( int V_120 )
{
struct V_51 * V_52 ;
bool V_131 = false ;
struct V_1 * V_2 = NULL ;
F_79 (iommu, drhd)
if ( V_2 -> V_112 )
F_104 ( V_2 ) ;
F_79 (iommu, drhd) {
if ( ! F_76 ( V_2 -> V_17 ) )
continue;
F_45 ( V_2 , V_120 ) ;
F_52 ( V_2 ) ;
V_131 = true ;
}
if ( ! V_131 )
goto error;
F_87 () ;
return 0 ;
error:
return - 1 ;
}
static void F_105 ( struct V_33 * V_33 , int V_158 , unsigned int V_159 )
{
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_85 = 1 ;
V_33 -> V_160 = V_46 -> V_161 ;
V_33 -> V_162 = 0 ;
V_33 -> V_163 = V_46 -> V_164 ;
V_33 -> V_158 = V_158 ;
V_33 -> V_165 = F_106 ( V_159 ) ;
V_33 -> V_166 = 1 ;
}
static struct V_167 * F_107 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_169 )
return NULL ;
switch ( V_169 -> type ) {
case V_170 :
V_2 = F_25 ( V_169 -> V_156 ) ;
break;
case V_171 :
V_2 = F_24 ( V_169 -> V_41 ) ;
break;
case V_172 :
case V_173 :
V_2 = F_26 ( V_169 -> V_174 ) ;
break;
default:
F_108 ( 1 ) ;
break;
}
return V_2 ? V_2 -> V_109 : NULL ;
}
static struct V_167 * F_109 ( struct V_168 * V_169 )
{
struct V_1 * V_2 ;
if ( ! V_169 )
return NULL ;
switch ( V_169 -> type ) {
case V_172 :
case V_173 :
V_2 = F_26 ( V_169 -> V_174 ) ;
if ( V_2 )
return V_2 -> V_111 ;
break;
default:
break;
}
return NULL ;
}
static int
F_110 ( struct V_175 * V_71 , const struct V_176 * V_15 ,
bool V_177 )
{
struct V_178 * V_179 = V_71 -> V_180 ;
struct V_33 * V_33 = & V_179 -> V_181 ;
struct V_182 * V_183 = F_111 ( V_71 ) ;
struct V_175 * V_184 = V_71 -> V_185 ;
int V_39 ;
V_39 = V_184 -> V_186 -> V_187 ( V_184 , V_15 , V_177 ) ;
if ( V_39 < 0 || V_39 == V_188 )
return V_39 ;
V_33 -> V_158 = V_183 -> V_158 ;
V_33 -> V_165 = F_106 ( V_183 -> V_189 ) ;
if ( V_179 -> V_10 . V_25 == V_26 )
F_18 ( & V_179 -> V_10 , V_33 ) ;
F_112 ( V_183 ) ;
return V_188 ;
}
static void F_113 ( struct V_175 * V_175 ,
struct V_190 * V_191 )
{
struct V_178 * V_179 = V_175 -> V_180 ;
* V_191 = V_179 -> V_192 ;
}
static int F_114 ( struct V_175 * V_71 , void * V_169 )
{
struct V_178 * V_179 = V_71 -> V_180 ;
struct V_193 * V_194 = V_169 ;
if ( ! V_194 ) {
F_18 ( & V_179 -> V_10 , & V_179 -> V_181 ) ;
} else {
struct V_33 V_195 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
F_115 ( & V_195 , & V_179 -> V_181 ) ;
V_195 . V_196 = 1 ;
V_195 . V_197 = 0 ;
V_195 . V_198 = V_194 -> V_158 ;
V_195 . V_199 = ( V_194 -> V_200 >>
( 32 - V_201 ) ) & ~ ( - 1UL << V_201 ) ;
V_195 . V_202 = ( V_194 -> V_200 >> 32 ) &
~ ( - 1UL << V_203 ) ;
F_18 ( & V_179 -> V_10 , & V_195 ) ;
}
return 0 ;
}
static void F_116 ( struct V_178 * V_71 ,
struct V_182 * V_182 ,
struct V_168 * V_169 ,
int V_16 , int V_23 )
{
struct V_204 * V_54 ;
struct V_33 * V_33 = & V_71 -> V_181 ;
struct V_190 * V_191 = & V_71 -> V_192 ;
F_105 ( V_33 , V_182 -> V_158 , V_182 -> V_189 ) ;
switch ( V_169 -> type ) {
case V_170 :
F_31 ( V_33 , V_169 -> V_156 ) ;
F_117 ( V_205 , V_206 L_38 ,
V_169 -> V_156 , V_33 -> V_85 , V_33 -> V_207 ,
V_33 -> V_160 , V_33 -> V_166 ,
V_33 -> V_162 , V_33 -> V_163 ,
V_33 -> V_208 , V_33 -> V_158 , V_33 -> V_165 ,
V_33 -> V_58 , V_33 -> V_57 , V_33 -> V_56 ) ;
V_54 = (struct V_204 * ) V_169 -> V_209 ;
V_169 -> V_209 = NULL ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_210 = ( V_16 >> 15 ) & 0x1 ;
V_54 -> V_211 = 0 ;
V_54 -> V_212 = 1 ;
V_54 -> V_16 = ( V_16 & 0x7fff ) ;
V_54 -> V_158 = V_169 -> V_213 ;
V_54 -> V_15 = 0 ;
V_54 -> V_214 = V_169 -> V_215 ;
V_54 -> V_216 = V_169 -> V_217 ;
if ( V_169 -> V_215 )
V_54 -> V_15 = 1 ;
break;
case V_171 :
case V_172 :
case V_173 :
if ( V_169 -> type == V_171 )
F_34 ( V_33 , V_169 -> V_41 ) ;
else
F_36 ( V_33 , V_169 -> V_174 ) ;
V_191 -> V_218 = V_219 ;
V_191 -> V_71 = V_23 ;
V_191 -> V_220 = V_221 | V_222 |
V_223 |
F_118 ( V_16 ) |
F_119 ( V_16 ) ;
break;
default:
F_108 ( 1 ) ;
break;
}
}
static void F_120 ( struct V_167 * V_224 ,
unsigned int V_225 , unsigned int V_226 )
{
struct V_175 * V_175 ;
struct V_178 * V_71 ;
struct V_10 * V_11 ;
unsigned long V_3 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_226 ; V_42 ++ ) {
V_175 = F_121 ( V_224 , V_225 + V_42 ) ;
if ( V_175 && V_175 -> V_180 ) {
V_71 = V_175 -> V_180 ;
V_11 = & V_71 -> V_10 ;
F_10 ( & V_18 , V_3 ) ;
F_28 ( V_11 ) ;
F_13 ( & V_18 , V_3 ) ;
F_122 ( V_175 ) ;
F_71 ( V_71 ) ;
}
}
}
static int F_123 ( struct V_167 * V_224 ,
unsigned int V_225 , unsigned int V_226 ,
void * V_227 )
{
struct V_1 * V_2 = V_224 -> V_228 ;
struct V_168 * V_169 = V_227 ;
struct V_178 * V_71 , * V_229 ;
struct V_175 * V_175 ;
struct V_182 * V_182 ;
int V_42 , V_39 , V_16 ;
if ( ! V_169 || ! V_2 )
return - V_81 ;
if ( V_226 > 1 && V_169 -> type != V_172 &&
V_169 -> type != V_173 )
return - V_81 ;
if ( V_169 -> type == V_172 )
V_169 -> V_3 &= ~ V_230 ;
V_39 = F_124 ( V_224 , V_225 , V_226 , V_227 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = - V_84 ;
V_71 = F_55 ( sizeof( * V_71 ) , V_101 ) ;
if ( ! V_71 )
goto V_231;
F_32 ( & V_61 ) ;
V_16 = F_5 ( V_2 , V_225 , & V_71 -> V_10 , V_226 ) ;
F_33 ( & V_61 ) ;
if ( V_16 < 0 ) {
F_12 ( L_39 ) ;
F_71 ( V_71 ) ;
goto V_231;
}
for ( V_42 = 0 ; V_42 < V_226 ; V_42 ++ ) {
V_175 = F_121 ( V_224 , V_225 + V_42 ) ;
V_182 = F_111 ( V_175 ) ;
if ( ! V_175 || ! V_182 ) {
V_39 = - V_81 ;
goto V_232;
}
if ( V_42 > 0 ) {
V_229 = F_55 ( sizeof( * V_229 ) , V_101 ) ;
if ( ! V_229 )
goto V_232;
V_229 -> V_10 = V_71 -> V_10 ;
V_229 -> V_10 . V_23 = V_42 ;
} else {
V_229 = V_71 ;
}
V_175 -> V_233 = ( V_16 << 16 ) + V_42 ;
V_175 -> V_180 = V_229 ;
V_175 -> V_186 = & V_234 ;
F_116 ( V_229 , V_182 , V_169 , V_16 , V_42 ) ;
F_125 ( V_225 + V_42 , V_235 ) ;
}
return 0 ;
V_232:
F_120 ( V_224 , V_225 , V_42 ) ;
V_231:
F_126 ( V_224 , V_225 , V_226 ) ;
return V_39 ;
}
static void F_127 ( struct V_167 * V_224 ,
unsigned int V_225 , unsigned int V_226 )
{
F_120 ( V_224 , V_225 , V_226 ) ;
F_126 ( V_224 , V_225 , V_226 ) ;
}
static void F_128 ( struct V_167 * V_224 ,
struct V_175 * V_175 )
{
struct V_178 * V_71 = V_175 -> V_180 ;
F_18 ( & V_71 -> V_10 , & V_71 -> V_181 ) ;
}
static void F_129 ( struct V_167 * V_224 ,
struct V_175 * V_175 )
{
struct V_178 * V_71 = V_175 -> V_180 ;
struct V_33 V_54 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_18 ( & V_71 -> V_10 , & V_54 ) ;
}
static int F_130 ( struct V_51 * V_236 , struct V_1 * V_2 )
{
int V_39 ;
int V_120 = F_131 () ;
if ( V_120 && ! F_86 ( V_2 -> V_17 ) ) {
F_70 ( L_40 ,
V_2 -> V_237 , V_2 -> V_17 ) ;
return - V_124 ;
}
if ( F_95 ( V_236 -> V_154 , V_2 ) ) {
F_12 ( L_41 ,
V_2 -> V_237 ) ;
return - V_124 ;
}
V_39 = F_54 ( V_2 ) ;
if ( V_39 ) {
F_9 ( L_28 ,
V_2 -> V_113 ) ;
F_73 ( V_2 ) ;
F_96 ( V_2 ) ;
} else {
F_52 ( V_2 ) ;
}
return V_39 ;
}
int F_132 ( struct V_51 * V_236 , bool V_238 )
{
int V_39 = 0 ;
struct V_1 * V_2 = V_236 -> V_2 ;
if ( ! V_132 )
return 0 ;
if ( V_2 == NULL )
return - V_81 ;
if ( ! F_76 ( V_2 -> V_17 ) )
return 0 ;
if ( F_133 ( V_129 ) &&
! F_89 ( V_2 -> V_130 ) )
return - V_239 ;
if ( V_238 ) {
if ( ! V_2 -> V_13 )
V_39 = F_130 ( V_236 , V_2 ) ;
} else {
if ( V_2 -> V_13 ) {
if ( ! F_134 ( V_2 -> V_13 -> V_19 ,
V_20 ) ) {
V_39 = - V_239 ;
} else {
F_69 ( V_2 ) ;
F_73 ( V_2 ) ;
F_96 ( V_2 ) ;
}
}
}
return V_39 ;
}
