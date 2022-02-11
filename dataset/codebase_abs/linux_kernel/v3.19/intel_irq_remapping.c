static struct V_1 * V_1 ( unsigned int V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
return V_4 ? & V_4 -> V_1 : NULL ;
}
static int F_1 ( int V_2 , struct V_5 * V_6 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_6 || ! V_7 )
return - 1 ;
F_2 ( & V_10 , V_8 ) ;
if ( F_3 ( ! V_7 -> V_11 ) ) {
F_4 ( & V_10 , V_8 ) ;
return - 1 ;
}
V_9 = V_7 -> V_12 + V_7 -> V_13 ;
* V_6 = * ( V_7 -> V_11 -> V_14 -> V_15 + V_9 ) ;
F_4 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_16 * V_11 , int V_2 , T_1 V_17 )
{
struct V_14 * V_18 = V_11 -> V_14 ;
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
unsigned int V_19 = 0 ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_17 || ! V_7 )
return - 1 ;
if ( V_17 > 1 ) {
V_17 = F_6 ( V_17 ) ;
V_19 = F_7 ( V_17 ) ;
}
if ( V_19 > F_8 ( V_11 -> V_20 ) ) {
F_9 ( V_21
L_1
L_2 , V_19 ,
F_8 ( V_11 -> V_20 ) ) ;
return - 1 ;
}
F_2 ( & V_10 , V_8 ) ;
V_9 = F_10 ( V_18 -> V_22 ,
V_23 , V_19 ) ;
if ( V_9 < 0 ) {
F_11 ( L_3 , V_11 -> V_24 ) ;
} else {
V_4 -> V_25 = 1 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_12 = V_9 ;
V_7 -> V_13 = 0 ;
V_7 -> V_26 = V_19 ;
}
F_4 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_12 ( struct V_16 * V_11 , int V_9 , int V_19 )
{
struct V_27 V_28 ;
V_28 . V_29 = F_13 ( V_9 ) | V_30 | F_14 ( V_19 )
| V_31 ;
V_28 . V_32 = 0 ;
return F_15 ( & V_28 , V_11 ) ;
}
static int F_16 ( int V_2 , T_1 * V_13 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_9 ;
if ( ! V_7 )
return - 1 ;
F_2 ( & V_10 , V_8 ) ;
* V_13 = V_7 -> V_13 ;
V_9 = V_7 -> V_12 ;
F_4 ( & V_10 , V_8 ) ;
return V_9 ;
}
static int F_17 ( int V_2 , struct V_16 * V_11 , T_1 V_9 , T_1 V_33 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
unsigned long V_8 ;
if ( ! V_7 )
return - 1 ;
F_2 ( & V_10 , V_8 ) ;
V_4 -> V_25 = 1 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_12 = V_9 ;
V_7 -> V_13 = V_33 ;
V_7 -> V_26 = 0 ;
F_4 ( & V_10 , V_8 ) ;
return 0 ;
}
static int F_18 ( int V_2 , struct V_5 * V_34 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
struct V_16 * V_11 ;
unsigned long V_8 ;
struct V_5 * V_5 ;
int V_35 , V_9 ;
if ( ! V_7 )
return - 1 ;
F_2 ( & V_10 , V_8 ) ;
V_11 = V_7 -> V_11 ;
V_9 = V_7 -> V_12 + V_7 -> V_13 ;
V_5 = & V_11 -> V_14 -> V_15 [ V_9 ] ;
F_19 ( & V_5 -> V_29 , V_34 -> V_29 ) ;
F_19 ( & V_5 -> V_32 , V_34 -> V_32 ) ;
F_20 ( V_11 , V_5 , sizeof( * V_5 ) ) ;
V_35 = F_12 ( V_11 , V_9 , 0 ) ;
F_4 ( & V_10 , V_8 ) ;
return V_35 ;
}
static struct V_16 * F_21 ( T_2 V_36 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_39 [ V_37 ] . V_40 == V_36 && V_39 [ V_37 ] . V_11 )
return V_39 [ V_37 ] . V_11 ;
return NULL ;
}
static struct V_16 * F_22 ( int V_41 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ )
if ( V_43 [ V_37 ] . V_40 == V_41 && V_43 [ V_37 ] . V_11 )
return V_43 [ V_37 ] . V_11 ;
return NULL ;
}
static struct V_16 * F_23 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
V_47 = F_24 ( V_45 ) ;
if ( ! V_47 )
return NULL ;
return V_47 -> V_11 ;
}
static int F_25 ( struct V_1 * V_7 )
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
F_19 ( & V_6 -> V_29 , 0 ) ;
F_19 ( & V_6 -> V_32 , 0 ) ;
}
F_26 ( V_11 -> V_14 -> V_22 , V_9 ,
V_7 -> V_26 ) ;
return F_12 ( V_11 , V_9 , V_7 -> V_26 ) ;
}
static int F_27 ( int V_2 )
{
struct V_1 * V_7 = V_1 ( V_2 ) ;
unsigned long V_8 ;
int V_35 ;
if ( ! V_7 )
return - 1 ;
F_2 ( & V_10 , V_8 ) ;
V_35 = F_25 ( V_7 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
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
if ( V_43 [ V_37 ] . V_11 && V_43 [ V_37 ] . V_40 == V_41 ) {
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
if ( V_39 [ V_37 ] . V_11 && V_39 [ V_37 ] . V_40 == V_40 ) {
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
static int F_34 ( struct V_44 * V_61 , T_1 V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
V_65 -> V_61 = V_61 ;
V_65 -> V_62 = V_62 ;
return 0 ;
}
static int F_35 ( struct V_5 * V_5 , struct V_44 * V_45 )
{
struct V_64 V_65 ;
if ( ! V_5 || ! V_45 )
return - 1 ;
F_36 ( V_45 , F_34 , & V_65 ) ;
if ( F_37 ( V_65 . V_62 ) != V_65 . V_61 -> V_56 -> V_66 )
F_28 ( V_5 , V_67 , V_59 ,
F_38 ( F_37 ( V_65 . V_62 ) ,
V_45 -> V_56 -> V_66 ) ) ;
else if ( V_65 . V_61 -> V_56 -> V_66 != V_45 -> V_56 -> V_66 )
F_28 ( V_5 , V_58 , V_59 , V_65 . V_62 ) ;
else
F_28 ( V_5 , V_58 , V_59 ,
F_38 ( V_45 -> V_56 -> V_66 , V_45 -> V_57 ) ) ;
return 0 ;
}
static void F_39 ( struct V_16 * V_11 , int V_68 )
{
T_3 V_69 ;
T_4 V_70 ;
unsigned long V_8 ;
V_69 = F_40 ( ( void * ) V_11 -> V_14 -> V_15 ) ;
F_2 ( & V_11 -> V_71 , V_8 ) ;
F_41 ( V_11 -> V_72 + V_73 ,
( V_69 ) | F_42 ( V_68 ) | V_74 ) ;
F_43 ( V_11 -> V_75 | V_76 , V_11 -> V_72 + V_77 ) ;
F_44 ( V_11 , V_78 ,
V_79 , ( V_70 & V_80 ) , V_70 ) ;
F_4 ( & V_11 -> V_71 , V_8 ) ;
F_45 ( V_11 ) ;
F_2 ( & V_11 -> V_71 , V_8 ) ;
V_11 -> V_75 |= V_81 ;
V_11 -> V_75 &= ~ V_82 ;
F_43 ( V_11 -> V_75 , V_11 -> V_72 + V_77 ) ;
F_44 ( V_11 , V_78 ,
V_79 , ( V_70 & V_83 ) , V_70 ) ;
if ( V_70 & V_84 )
F_46 ( 1 , V_85
L_6
L_7 ) ;
F_4 ( & V_11 -> V_71 , V_8 ) ;
}
static int F_47 ( struct V_16 * V_11 )
{
struct V_14 * V_14 ;
struct V_86 * V_87 ;
unsigned long * V_22 ;
if ( V_11 -> V_14 )
return 0 ;
V_14 = F_48 ( sizeof( struct V_14 ) , V_88 ) ;
if ( ! V_14 )
return - V_89 ;
V_87 = F_49 ( V_11 -> V_90 , V_88 | V_91 ,
V_92 ) ;
if ( ! V_87 ) {
F_50 ( L_8 ,
V_11 -> V_24 , V_92 ) ;
goto V_93;
}
V_22 = F_51 ( F_52 ( V_23 ) ,
sizeof( long ) , V_88 ) ;
if ( V_22 == NULL ) {
F_50 ( L_9 , V_11 -> V_24 ) ;
goto V_94;
}
V_14 -> V_15 = F_53 ( V_87 ) ;
V_14 -> V_22 = V_22 ;
V_11 -> V_14 = V_14 ;
return 0 ;
V_94:
F_54 ( V_87 , V_92 ) ;
V_93:
F_55 ( V_14 ) ;
return - V_89 ;
}
static void F_56 ( struct V_16 * V_11 )
{
if ( V_11 && V_11 -> V_14 ) {
F_57 ( ( unsigned long ) V_11 -> V_14 -> V_15 ,
V_92 ) ;
F_55 ( V_11 -> V_14 -> V_22 ) ;
F_55 ( V_11 -> V_14 ) ;
V_11 -> V_14 = NULL ;
}
}
static void F_58 ( struct V_16 * V_11 )
{
unsigned long V_8 ;
T_4 V_70 ;
if ( ! F_59 ( V_11 -> V_20 ) )
return;
F_45 ( V_11 ) ;
F_2 ( & V_11 -> V_71 , V_8 ) ;
V_70 = F_60 ( V_11 -> V_72 + V_78 ) ;
if ( ! ( V_70 & V_83 ) )
goto V_49;
V_11 -> V_75 &= ~ V_81 ;
F_43 ( V_11 -> V_75 , V_11 -> V_72 + V_77 ) ;
F_44 ( V_11 , V_78 ,
V_79 , ! ( V_70 & V_83 ) , V_70 ) ;
V_49:
F_4 ( & V_11 -> V_71 , V_8 ) ;
}
static int T_5 F_61 ( void )
{
struct V_95 * V_96 ;
V_96 = (struct V_95 * ) V_97 ;
if ( ! V_96 || V_98 )
return 0 ;
return V_96 -> V_8 & V_99 ;
}
static int T_5 F_62 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
if ( V_100 )
return 0 ;
if ( V_101 ) {
F_9 ( V_85
L_10
L_11
L_12
L_13
L_14 ) ;
F_63 ( V_102 , V_103 ) ;
V_100 = 1 ;
return 0 ;
}
if ( ! F_64 () )
return 0 ;
F_65 (iommu, drhd)
if ( ! F_59 ( V_11 -> V_20 ) )
return 0 ;
return 1 ;
}
static int T_5 F_66 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
bool V_104 ;
int V_105 = 0 ;
int V_106 = 0 ;
V_104 = F_67 () ;
if ( F_68 () != 1 ) {
F_9 ( V_107 L_15 ) ;
goto error;
}
if ( V_104 ) {
F_69 ( L_16 ) ;
V_106 = ! F_61 () ;
if ( ! V_106 )
F_9 ( V_85
L_17
L_18
L_19 ) ;
}
F_65 (iommu, drhd) {
if ( V_11 -> V_108 )
continue;
F_70 ( - 1 , V_11 ) ;
F_58 ( V_11 ) ;
F_71 ( V_11 ) ;
}
F_65 (iommu, drhd) {
if ( ! F_59 ( V_11 -> V_20 ) )
continue;
if ( V_106 && ! F_72 ( V_11 -> V_20 ) ) {
F_9 ( V_107 L_20
L_21 , V_47 -> V_109 , V_11 -> V_20 ) ;
goto error;
}
}
F_65 (iommu, drhd) {
int V_110 = F_73 ( V_11 ) ;
if ( V_110 ) {
F_9 ( V_21 L_22
L_23 ,
V_47 -> V_109 , V_11 -> V_20 , V_110 ) ;
goto error;
}
}
F_65 (iommu, drhd) {
if ( ! F_59 ( V_11 -> V_20 ) )
continue;
if ( F_47 ( V_11 ) )
goto error;
F_39 ( V_11 , V_106 ) ;
V_105 = 1 ;
}
if ( ! V_105 )
goto error;
V_111 = 1 ;
V_112 . V_113 = V_114 ;
F_69 ( L_24 , V_106 ? L_25 : L_26 ) ;
return V_106 ? V_115 : V_116 ;
error:
F_65 (iommu, drhd)
if ( F_59 ( V_11 -> V_20 ) ) {
F_58 ( V_11 ) ;
F_56 ( V_11 ) ;
}
if ( V_104 )
F_11 ( L_27 ) ;
return - 1 ;
}
static int F_74 ( struct V_117 * V_118 ,
struct V_16 * V_11 ,
struct V_119 * V_47 )
{
struct V_120 * V_121 ;
T_2 V_56 ;
int V_17 , free = - 1 ;
V_56 = V_118 -> V_56 ;
V_121 = (struct V_120 * ) ( V_118 + 1 ) ;
V_17 = ( V_118 -> V_122 - sizeof( struct V_117 ) )
/ sizeof( struct V_120 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_75 ( V_56 , V_121 -> V_123 , V_121 -> V_124 ,
V_125 ) ;
V_121 ++ ;
}
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
if ( V_39 [ V_17 ] . V_11 == V_11 &&
V_39 [ V_17 ] . V_40 == V_118 -> V_126 )
return 0 ;
else if ( V_39 [ V_17 ] . V_11 == NULL && free == - 1 )
free = V_17 ;
}
if ( free == - 1 ) {
F_11 ( L_28 ) ;
return - V_127 ;
}
V_39 [ free ] . V_11 = V_11 ;
V_39 [ free ] . V_40 = V_118 -> V_126 ;
V_39 [ free ] . V_56 = V_56 ;
V_39 [ free ] . V_57 = F_76 ( V_121 -> V_123 , V_121 -> V_124 ) ;
F_69 ( L_29 ,
V_118 -> V_126 , V_47 -> V_128 ) ;
return 0 ;
}
static int F_77 ( struct V_117 * V_118 ,
struct V_16 * V_11 ,
struct V_119 * V_47 )
{
struct V_120 * V_121 ;
T_2 V_56 ;
int V_17 , free = - 1 ;
V_56 = V_118 -> V_56 ;
V_121 = (struct V_120 * ) ( V_118 + 1 ) ;
V_17 = ( V_118 -> V_122 - sizeof( struct V_117 ) )
/ sizeof( struct V_120 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_75 ( V_56 , V_121 -> V_123 , V_121 -> V_124 ,
V_125 ) ;
V_121 ++ ;
}
for ( V_17 = 0 ; V_17 < V_42 ; V_17 ++ ) {
if ( V_43 [ V_17 ] . V_11 == V_11 &&
V_43 [ V_17 ] . V_40 == V_118 -> V_126 )
return 0 ;
else if ( V_43 [ V_17 ] . V_11 == NULL && free == - 1 )
free = V_17 ;
}
if ( free == - 1 ) {
F_11 ( L_30 ) ;
return - V_127 ;
}
V_43 [ free ] . V_56 = V_56 ;
V_43 [ free ] . V_57 = F_76 ( V_121 -> V_123 , V_121 -> V_124 ) ;
V_43 [ free ] . V_11 = V_11 ;
V_43 [ free ] . V_40 = V_118 -> V_126 ;
F_69 ( L_31 ,
V_118 -> V_126 , V_47 -> V_128 , V_11 -> V_24 ) ;
return 0 ;
}
static int F_78 ( struct V_129 * V_130 ,
struct V_16 * V_11 )
{
int V_110 = 0 ;
struct V_119 * V_47 ;
struct V_117 * V_118 ;
void * V_48 , * V_49 ;
V_47 = (struct V_119 * ) V_130 ;
V_48 = ( void * ) ( V_47 + 1 ) ;
V_49 = ( ( void * ) V_47 ) + V_130 -> V_122 ;
while ( V_48 < V_49 && V_110 == 0 ) {
V_118 = V_48 ;
if ( V_118 -> V_131 == V_132 )
V_110 = F_77 ( V_118 , V_11 , V_47 ) ;
else if ( V_118 -> V_131 == V_133 )
V_110 = F_74 ( V_118 , V_11 , V_47 ) ;
V_48 += V_118 -> V_122 ;
}
return V_110 ;
}
static void F_79 ( struct V_16 * V_11 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_39 [ V_37 ] . V_11 == V_11 )
V_39 [ V_37 ] . V_11 = NULL ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ )
if ( V_43 [ V_37 ] . V_11 == V_11 )
V_43 [ V_37 ] . V_11 = NULL ;
}
static int T_5 F_68 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
int V_134 = 0 ;
int V_135 ;
F_65 (iommu, drhd)
if ( F_59 ( V_11 -> V_20 ) ) {
if ( F_78 ( V_47 -> V_136 , V_11 ) )
return - 1 ;
V_134 = 1 ;
}
if ( ! V_134 )
return 0 ;
for ( V_135 = 0 ; V_135 < V_137 ; V_135 ++ ) {
int V_138 = F_80 ( V_135 ) ;
if ( ! F_22 ( V_138 ) ) {
F_50 ( V_139 L_32
L_33 ,
V_138 ) ;
return - 1 ;
}
}
return 1 ;
}
static int T_5 F_81 ( void )
{
int V_110 ;
if ( ! V_111 )
return 0 ;
F_82 ( & V_55 ) ;
V_110 = F_83 () ;
F_84 ( & V_55 ) ;
return V_110 ;
}
static void F_85 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 = NULL ;
F_65 (iommu, drhd) {
if ( ! F_59 ( V_11 -> V_20 ) )
continue;
F_58 ( V_11 ) ;
}
}
static int F_86 ( int V_106 )
{
struct V_46 * V_47 ;
int V_105 = 0 ;
struct V_16 * V_11 = NULL ;
F_65 (iommu, drhd)
if ( V_11 -> V_108 )
F_87 ( V_11 ) ;
F_65 (iommu, drhd) {
if ( ! F_59 ( V_11 -> V_20 ) )
continue;
F_39 ( V_11 , V_106 ) ;
V_105 = 1 ;
}
if ( ! V_105 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_88 ( struct V_5 * V_5 , int V_140 ,
unsigned int V_141 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_142 = 1 ;
V_5 -> V_143 = V_41 -> V_144 ;
V_5 -> V_145 = 0 ;
V_5 -> V_146 = V_41 -> V_147 ;
V_5 -> V_140 = V_140 ;
V_5 -> V_148 = F_89 ( V_141 ) ;
V_5 -> V_149 = 1 ;
}
static int F_90 ( int V_2 ,
struct V_150 * V_151 ,
unsigned int V_152 , int V_140 ,
struct V_153 * V_154 )
{
int V_138 = F_80 ( V_154 -> V_155 ) ;
struct V_16 * V_11 ;
struct V_156 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_11 = F_22 ( V_138 ) ;
if ( ! V_11 ) {
F_11 ( L_34 , V_138 ) ;
V_9 = - V_157 ;
} else {
V_9 = F_5 ( V_11 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_11 ( L_35 ,
V_138 ) ;
V_9 = - V_89 ;
}
}
F_31 ( & V_55 ) ;
if ( V_9 < 0 )
return V_9 ;
F_88 ( & V_5 , V_140 , V_152 ) ;
F_29 ( & V_5 , V_138 ) ;
F_18 ( V_2 , & V_5 ) ;
F_91 ( V_158 , V_159 L_36
L_37
L_38
L_39
L_40 ,
V_154 -> V_155 , V_5 . V_142 , V_5 . V_160 , V_5 . V_143 ,
V_5 . V_149 , V_5 . V_145 , V_5 . V_146 ,
V_5 . V_161 , V_5 . V_140 , V_5 . V_148 ,
V_5 . V_52 , V_5 . V_51 , V_5 . V_50 ) ;
V_6 = (struct V_156 * ) V_151 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_162 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_163 = 0 ;
V_6 -> V_164 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_140 = V_154 -> V_165 ;
V_6 -> V_19 = 0 ;
V_6 -> V_166 = V_154 -> V_166 ;
V_6 -> V_167 = V_154 -> V_167 ;
if ( V_154 -> V_166 )
V_6 -> V_19 = 1 ;
return 0 ;
}
static int
F_92 ( struct V_168 * V_65 , const struct V_169 * V_19 ,
bool V_170 )
{
struct V_3 * V_4 = F_93 ( V_65 ) ;
unsigned int V_141 , V_2 = V_65 -> V_2 ;
struct V_5 V_5 ;
int V_171 ;
if ( ! F_94 ( V_172 ) )
return - V_173 ;
if ( ! F_95 ( V_19 , V_174 ) )
return - V_173 ;
if ( F_1 ( V_2 , & V_5 ) )
return - V_175 ;
V_171 = F_96 ( V_2 , V_4 , V_19 ) ;
if ( V_171 )
return V_171 ;
V_171 = V_41 -> V_176 ( V_4 -> V_177 , V_19 , & V_141 ) ;
if ( V_171 ) {
if ( F_96 ( V_2 , V_4 , V_65 -> V_178 ) )
F_50 ( L_41 , V_2 ) ;
return V_171 ;
}
V_5 . V_140 = V_4 -> V_140 ;
V_5 . V_148 = F_89 ( V_141 ) ;
F_18 ( V_2 , & V_5 ) ;
if ( V_4 -> V_179 )
F_97 ( V_4 ) ;
F_98 ( V_65 -> V_178 , V_19 ) ;
return 0 ;
}
static void F_99 ( struct V_44 * V_61 ,
unsigned int V_2 , unsigned int V_141 ,
struct V_180 * V_181 , T_2 V_36 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_13 = 0 ;
int V_182 ;
V_4 = V_3 ( V_2 ) ;
V_182 = F_16 ( V_2 , & V_13 ) ;
F_100 ( V_182 == - 1 ) ;
F_88 ( & V_5 , V_4 -> V_140 , V_141 ) ;
if ( V_61 )
F_35 ( & V_5 , V_61 ) ;
else
F_33 ( & V_5 , V_36 ) ;
F_18 ( V_2 , & V_5 ) ;
V_181 -> V_183 = V_184 ;
V_181 -> V_65 = V_13 ;
V_181 -> V_185 = V_186 | V_187 |
V_188 |
F_101 ( V_182 ) |
F_102 ( V_182 ) ;
}
static int F_103 ( struct V_44 * V_45 , int V_2 , int V_189 )
{
struct V_16 * V_11 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_11 = F_23 ( V_45 ) ;
if ( ! V_11 ) {
F_9 ( V_21
L_42 , F_104 ( V_45 ) ) ;
V_9 = - V_190 ;
} else {
V_9 = F_5 ( V_11 , V_2 , V_189 ) ;
if ( V_9 < 0 ) {
F_9 ( V_21
L_43 ,
V_189 , F_104 ( V_45 ) ) ;
V_9 = - V_127 ;
}
}
F_31 ( & V_55 ) ;
return V_9 ;
}
static int F_105 ( struct V_44 * V_61 , unsigned int V_2 ,
int V_9 , int V_13 )
{
struct V_16 * V_11 ;
int V_110 = - V_190 ;
F_30 ( & V_55 ) ;
V_11 = F_23 ( V_61 ) ;
if ( V_11 ) {
F_17 ( V_2 , V_11 , V_9 , V_13 ) ;
V_110 = 0 ;
}
F_31 ( & V_55 ) ;
return V_110 ;
}
static int F_106 ( unsigned int V_2 , unsigned int V_40 )
{
int V_110 = - 1 ;
struct V_16 * V_11 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_11 = F_21 ( V_40 ) ;
if ( V_11 ) {
V_9 = F_5 ( V_11 , V_2 , 1 ) ;
if ( V_9 >= 0 )
V_110 = 0 ;
}
F_31 ( & V_55 ) ;
return V_110 ;
}
static int F_107 ( struct V_46 * V_191 , struct V_16 * V_11 )
{
int V_110 ;
int V_106 = F_108 () ;
if ( V_106 && ! F_72 ( V_11 -> V_20 ) ) {
F_69 ( L_44 ,
V_11 -> V_192 , V_11 -> V_20 ) ;
return - V_157 ;
}
if ( F_78 ( V_191 -> V_136 , V_11 ) ) {
F_11 ( L_45 ,
V_11 -> V_192 ) ;
return - V_157 ;
}
V_110 = F_47 ( V_11 ) ;
if ( V_110 ) {
F_50 ( L_46 ,
V_11 -> V_192 ) ;
F_79 ( V_11 ) ;
return V_110 ;
}
if ( ! V_11 -> V_108 ) {
F_70 ( - 1 , V_11 ) ;
F_58 ( V_11 ) ;
F_71 ( V_11 ) ;
}
V_110 = F_73 ( V_11 ) ;
if ( ! V_110 ) {
F_39 ( V_11 , V_106 ) ;
} else {
F_50 ( L_47 ,
V_11 -> V_192 , V_11 -> V_20 , V_110 ) ;
F_56 ( V_11 ) ;
F_79 ( V_11 ) ;
}
return V_110 ;
}
int F_109 ( struct V_46 * V_191 , bool V_193 )
{
int V_110 = 0 ;
struct V_16 * V_11 = V_191 -> V_11 ;
if ( ! V_111 )
return 0 ;
if ( V_11 == NULL )
return - V_173 ;
if ( ! F_59 ( V_11 -> V_20 ) )
return 0 ;
if ( V_193 ) {
if ( ! V_11 -> V_14 )
V_110 = F_107 ( V_191 , V_11 ) ;
} else {
if ( V_11 -> V_14 ) {
if ( ! F_110 ( V_11 -> V_14 -> V_22 ,
V_23 ) ) {
V_110 = - V_175 ;
} else {
F_58 ( V_11 ) ;
F_56 ( V_11 ) ;
F_79 ( V_11 ) ;
}
}
}
return V_110 ;
}
