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
sizeof( long ) , V_94 ) ;
if ( V_22 == NULL ) {
F_50 ( L_9 , V_11 -> V_24 ) ;
goto V_95;
}
V_14 -> V_15 = F_53 ( V_87 ) ;
V_14 -> V_22 = V_22 ;
V_11 -> V_14 = V_14 ;
return 0 ;
V_95:
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
struct V_96 * V_97 ;
V_97 = (struct V_96 * ) V_98 ;
if ( ! V_97 || V_99 )
return 0 ;
return V_97 -> V_8 & V_100 ;
}
static void T_5 F_62 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
F_63 (iommu, drhd) {
if ( F_59 ( V_11 -> V_20 ) ) {
F_58 ( V_11 ) ;
F_56 ( V_11 ) ;
}
}
if ( F_64 () )
F_11 ( L_10 ) ;
}
static int T_5 F_65 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
if ( V_101 ) {
F_9 ( V_85
L_11
L_12
L_13
L_14
L_15 ) ;
F_66 ( V_102 , V_103 ) ;
return - V_104 ;
}
if ( F_67 () < 0 )
return - V_104 ;
if ( ! F_68 () )
return - V_104 ;
if ( F_69 () != 1 ) {
F_9 ( V_105 L_16 ) ;
goto error;
}
F_63 (iommu, drhd)
if ( ! F_59 ( V_11 -> V_20 ) )
goto error;
F_63 (iommu, drhd)
if ( F_47 ( V_11 ) )
goto error;
return 0 ;
error:
F_62 () ;
return - V_104 ;
}
static int T_5 F_70 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
int V_106 = 0 ;
int V_107 = 0 ;
if ( F_64 () ) {
V_107 = ! F_61 () ;
if ( ! V_107 )
F_9 ( V_85
L_17
L_18
L_19 ) ;
}
F_63 (iommu, drhd) {
if ( V_11 -> V_108 )
continue;
F_71 ( - 1 , V_11 ) ;
F_58 ( V_11 ) ;
F_72 ( V_11 ) ;
}
F_63 (iommu, drhd)
if ( V_107 && ! F_73 ( V_11 -> V_20 ) ) {
F_9 ( V_105 L_20
L_21 , V_47 -> V_109 , V_11 -> V_20 ) ;
V_107 = 0 ;
}
V_110 = V_107 ;
if ( V_107 )
F_74 ( L_22 ) ;
F_63 (iommu, drhd) {
int V_111 = F_75 ( V_11 ) ;
if ( V_111 ) {
F_9 ( V_21 L_23
L_24 ,
V_47 -> V_109 , V_11 -> V_20 , V_111 ) ;
goto error;
}
}
F_63 (iommu, drhd) {
F_39 ( V_11 , V_107 ) ;
V_106 = 1 ;
}
if ( ! V_106 )
goto error;
V_112 = 1 ;
V_113 . V_114 = V_115 ;
F_74 ( L_25 , V_107 ? L_26 : L_27 ) ;
return V_107 ? V_116 : V_117 ;
error:
F_62 () ;
return - 1 ;
}
static int F_76 ( struct V_118 * V_119 ,
struct V_16 * V_11 ,
struct V_120 * V_47 )
{
struct V_121 * V_122 ;
T_2 V_56 ;
int V_17 , free = - 1 ;
V_56 = V_119 -> V_56 ;
V_122 = (struct V_121 * ) ( V_119 + 1 ) ;
V_17 = ( V_119 -> V_123 - sizeof( struct V_118 ) )
/ sizeof( struct V_121 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_77 ( V_56 , V_122 -> V_124 , V_122 -> V_125 ,
V_126 ) ;
V_122 ++ ;
}
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
if ( V_39 [ V_17 ] . V_11 == V_11 &&
V_39 [ V_17 ] . V_40 == V_119 -> V_127 )
return 0 ;
else if ( V_39 [ V_17 ] . V_11 == NULL && free == - 1 )
free = V_17 ;
}
if ( free == - 1 ) {
F_11 ( L_28 ) ;
return - V_128 ;
}
V_39 [ free ] . V_11 = V_11 ;
V_39 [ free ] . V_40 = V_119 -> V_127 ;
V_39 [ free ] . V_56 = V_56 ;
V_39 [ free ] . V_57 = F_78 ( V_122 -> V_124 , V_122 -> V_125 ) ;
F_74 ( L_29 ,
V_119 -> V_127 , V_47 -> V_129 ) ;
return 0 ;
}
static int F_79 ( struct V_118 * V_119 ,
struct V_16 * V_11 ,
struct V_120 * V_47 )
{
struct V_121 * V_122 ;
T_2 V_56 ;
int V_17 , free = - 1 ;
V_56 = V_119 -> V_56 ;
V_122 = (struct V_121 * ) ( V_119 + 1 ) ;
V_17 = ( V_119 -> V_123 - sizeof( struct V_118 ) )
/ sizeof( struct V_121 ) ;
while ( -- V_17 > 0 ) {
V_56 = F_77 ( V_56 , V_122 -> V_124 , V_122 -> V_125 ,
V_126 ) ;
V_122 ++ ;
}
for ( V_17 = 0 ; V_17 < V_42 ; V_17 ++ ) {
if ( V_43 [ V_17 ] . V_11 == V_11 &&
V_43 [ V_17 ] . V_40 == V_119 -> V_127 )
return 0 ;
else if ( V_43 [ V_17 ] . V_11 == NULL && free == - 1 )
free = V_17 ;
}
if ( free == - 1 ) {
F_11 ( L_30 ) ;
return - V_128 ;
}
V_43 [ free ] . V_56 = V_56 ;
V_43 [ free ] . V_57 = F_78 ( V_122 -> V_124 , V_122 -> V_125 ) ;
V_43 [ free ] . V_11 = V_11 ;
V_43 [ free ] . V_40 = V_119 -> V_127 ;
F_74 ( L_31 ,
V_119 -> V_127 , V_47 -> V_129 , V_11 -> V_24 ) ;
return 0 ;
}
static int F_80 ( struct V_130 * V_131 ,
struct V_16 * V_11 )
{
int V_111 = 0 ;
struct V_120 * V_47 ;
struct V_118 * V_119 ;
void * V_48 , * V_49 ;
V_47 = (struct V_120 * ) V_131 ;
V_48 = ( void * ) ( V_47 + 1 ) ;
V_49 = ( ( void * ) V_47 ) + V_131 -> V_123 ;
while ( V_48 < V_49 && V_111 == 0 ) {
V_119 = V_48 ;
if ( V_119 -> V_132 == V_133 )
V_111 = F_79 ( V_119 , V_11 , V_47 ) ;
else if ( V_119 -> V_132 == V_134 )
V_111 = F_76 ( V_119 , V_11 , V_47 ) ;
V_48 += V_119 -> V_123 ;
}
return V_111 ;
}
static void F_81 ( struct V_16 * V_11 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_39 [ V_37 ] . V_11 == V_11 )
V_39 [ V_37 ] . V_11 = NULL ;
for ( V_37 = 0 ; V_37 < V_42 ; V_37 ++ )
if ( V_43 [ V_37 ] . V_11 == V_11 )
V_43 [ V_37 ] . V_11 = NULL ;
}
static int T_5 F_69 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 ;
int V_135 = 0 ;
int V_136 ;
F_63 (iommu, drhd)
if ( F_59 ( V_11 -> V_20 ) ) {
if ( F_80 ( V_47 -> V_137 , V_11 ) )
return - 1 ;
V_135 = 1 ;
}
if ( ! V_135 )
return 0 ;
for ( V_136 = 0 ; V_136 < V_138 ; V_136 ++ ) {
int V_139 = F_82 ( V_136 ) ;
if ( ! F_22 ( V_139 ) ) {
F_50 ( V_140 L_32
L_33 ,
V_139 ) ;
return - 1 ;
}
}
return 1 ;
}
static int T_5 F_83 ( void )
{
int V_111 ;
if ( ! V_112 )
return 0 ;
F_84 ( & V_55 ) ;
V_111 = F_85 () ;
F_86 ( & V_55 ) ;
return V_111 ;
}
static void F_87 ( void )
{
struct V_46 * V_47 ;
struct V_16 * V_11 = NULL ;
F_63 (iommu, drhd) {
if ( ! F_59 ( V_11 -> V_20 ) )
continue;
F_58 ( V_11 ) ;
}
}
static int F_88 ( int V_107 )
{
struct V_46 * V_47 ;
int V_106 = 0 ;
struct V_16 * V_11 = NULL ;
F_63 (iommu, drhd)
if ( V_11 -> V_108 )
F_89 ( V_11 ) ;
F_63 (iommu, drhd) {
if ( ! F_59 ( V_11 -> V_20 ) )
continue;
F_39 ( V_11 , V_107 ) ;
V_106 = 1 ;
}
if ( ! V_106 )
goto error;
return 0 ;
error:
return - 1 ;
}
static void F_90 ( struct V_5 * V_5 , int V_141 ,
unsigned int V_142 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_143 = 1 ;
V_5 -> V_144 = V_41 -> V_145 ;
V_5 -> V_146 = 0 ;
V_5 -> V_147 = V_41 -> V_148 ;
V_5 -> V_141 = V_141 ;
V_5 -> V_149 = F_91 ( V_142 ) ;
V_5 -> V_150 = 1 ;
}
static int F_92 ( int V_2 ,
struct V_151 * V_152 ,
unsigned int V_153 , int V_141 ,
struct V_154 * V_155 )
{
int V_139 = F_82 ( V_155 -> V_156 ) ;
struct V_16 * V_11 ;
struct V_157 * V_6 ;
struct V_5 V_5 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_11 = F_22 ( V_139 ) ;
if ( ! V_11 ) {
F_11 ( L_34 , V_139 ) ;
V_9 = - V_104 ;
} else {
V_9 = F_5 ( V_11 , V_2 , 1 ) ;
if ( V_9 < 0 ) {
F_11 ( L_35 ,
V_139 ) ;
V_9 = - V_89 ;
}
}
F_31 ( & V_55 ) ;
if ( V_9 < 0 )
return V_9 ;
F_90 ( & V_5 , V_141 , V_153 ) ;
F_29 ( & V_5 , V_139 ) ;
F_18 ( V_2 , & V_5 ) ;
F_93 ( V_158 , V_159 L_36
L_37
L_38
L_39
L_40 ,
V_155 -> V_156 , V_5 . V_143 , V_5 . V_160 , V_5 . V_144 ,
V_5 . V_150 , V_5 . V_146 , V_5 . V_147 ,
V_5 . V_161 , V_5 . V_141 , V_5 . V_149 ,
V_5 . V_52 , V_5 . V_51 , V_5 . V_50 ) ;
V_6 = (struct V_157 * ) V_152 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_162 = ( V_9 >> 15 ) & 0x1 ;
V_6 -> V_163 = 0 ;
V_6 -> V_164 = 1 ;
V_6 -> V_9 = ( V_9 & 0x7fff ) ;
V_6 -> V_141 = V_155 -> V_165 ;
V_6 -> V_19 = 0 ;
V_6 -> V_166 = V_155 -> V_166 ;
V_6 -> V_167 = V_155 -> V_167 ;
if ( V_155 -> V_166 )
V_6 -> V_19 = 1 ;
return 0 ;
}
static int
F_94 ( struct V_168 * V_65 , const struct V_169 * V_19 ,
bool V_170 )
{
struct V_3 * V_4 = F_95 ( V_65 ) ;
unsigned int V_142 , V_2 = V_65 -> V_2 ;
struct V_5 V_5 ;
int V_171 ;
if ( ! F_96 ( V_172 ) )
return - V_173 ;
if ( ! F_97 ( V_19 , V_174 ) )
return - V_173 ;
if ( F_1 ( V_2 , & V_5 ) )
return - V_175 ;
V_171 = F_98 ( V_2 , V_4 , V_19 ) ;
if ( V_171 )
return V_171 ;
V_171 = V_41 -> V_176 ( V_4 -> V_177 , V_19 , & V_142 ) ;
if ( V_171 ) {
if ( F_98 ( V_2 , V_4 , V_65 -> V_178 ) )
F_50 ( L_41 , V_2 ) ;
return V_171 ;
}
V_5 . V_141 = V_4 -> V_141 ;
V_5 . V_149 = F_91 ( V_142 ) ;
F_18 ( V_2 , & V_5 ) ;
if ( V_4 -> V_179 )
F_99 ( V_4 ) ;
F_100 ( V_65 -> V_178 , V_19 ) ;
return 0 ;
}
static void F_101 ( struct V_44 * V_61 ,
unsigned int V_2 , unsigned int V_142 ,
struct V_180 * V_181 , T_2 V_36 )
{
struct V_3 * V_4 ;
struct V_5 V_5 ;
T_1 V_13 = 0 ;
int V_182 ;
V_4 = V_3 ( V_2 ) ;
V_182 = F_16 ( V_2 , & V_13 ) ;
F_102 ( V_182 == - 1 ) ;
F_90 ( & V_5 , V_4 -> V_141 , V_142 ) ;
if ( V_61 )
F_35 ( & V_5 , V_61 ) ;
else
F_33 ( & V_5 , V_36 ) ;
F_18 ( V_2 , & V_5 ) ;
V_181 -> V_183 = V_184 ;
V_181 -> V_65 = V_13 ;
V_181 -> V_185 = V_186 | V_187 |
V_188 |
F_103 ( V_182 ) |
F_104 ( V_182 ) ;
}
static int F_105 ( struct V_44 * V_45 , int V_2 , int V_189 )
{
struct V_16 * V_11 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_11 = F_23 ( V_45 ) ;
if ( ! V_11 ) {
F_9 ( V_21
L_42 , F_106 ( V_45 ) ) ;
V_9 = - V_190 ;
} else {
V_9 = F_5 ( V_11 , V_2 , V_189 ) ;
if ( V_9 < 0 ) {
F_9 ( V_21
L_43 ,
V_189 , F_106 ( V_45 ) ) ;
V_9 = - V_128 ;
}
}
F_31 ( & V_55 ) ;
return V_9 ;
}
static int F_107 ( struct V_44 * V_61 , unsigned int V_2 ,
int V_9 , int V_13 )
{
struct V_16 * V_11 ;
int V_111 = - V_190 ;
F_30 ( & V_55 ) ;
V_11 = F_23 ( V_61 ) ;
if ( V_11 ) {
F_17 ( V_2 , V_11 , V_9 , V_13 ) ;
V_111 = 0 ;
}
F_31 ( & V_55 ) ;
return V_111 ;
}
static int F_108 ( unsigned int V_2 , unsigned int V_40 )
{
int V_111 = - 1 ;
struct V_16 * V_11 ;
int V_9 ;
F_30 ( & V_55 ) ;
V_11 = F_21 ( V_40 ) ;
if ( V_11 ) {
V_9 = F_5 ( V_11 , V_2 , 1 ) ;
if ( V_9 >= 0 )
V_111 = 0 ;
}
F_31 ( & V_55 ) ;
return V_111 ;
}
static int F_109 ( struct V_46 * V_191 , struct V_16 * V_11 )
{
int V_111 ;
int V_107 = F_110 () ;
if ( V_107 && ! F_73 ( V_11 -> V_20 ) ) {
F_74 ( L_44 ,
V_11 -> V_192 , V_11 -> V_20 ) ;
return - V_104 ;
}
if ( F_80 ( V_191 -> V_137 , V_11 ) ) {
F_11 ( L_45 ,
V_11 -> V_192 ) ;
return - V_104 ;
}
V_111 = F_47 ( V_11 ) ;
if ( V_111 ) {
F_50 ( L_46 ,
V_11 -> V_192 ) ;
F_81 ( V_11 ) ;
return V_111 ;
}
if ( ! V_11 -> V_108 ) {
F_71 ( - 1 , V_11 ) ;
F_58 ( V_11 ) ;
F_72 ( V_11 ) ;
}
V_111 = F_75 ( V_11 ) ;
if ( ! V_111 ) {
F_39 ( V_11 , V_107 ) ;
} else {
F_50 ( L_47 ,
V_11 -> V_192 , V_11 -> V_20 , V_111 ) ;
F_56 ( V_11 ) ;
F_81 ( V_11 ) ;
}
return V_111 ;
}
int F_111 ( struct V_46 * V_191 , bool V_193 )
{
int V_111 = 0 ;
struct V_16 * V_11 = V_191 -> V_11 ;
if ( ! V_112 )
return 0 ;
if ( V_11 == NULL )
return - V_173 ;
if ( ! F_59 ( V_11 -> V_20 ) )
return 0 ;
if ( V_193 ) {
if ( ! V_11 -> V_14 )
V_111 = F_109 ( V_191 , V_11 ) ;
} else {
if ( V_11 -> V_14 ) {
if ( ! F_112 ( V_11 -> V_14 -> V_22 ,
V_23 ) ) {
V_111 = - V_175 ;
} else {
F_58 ( V_11 ) ;
F_56 ( V_11 ) ;
F_81 ( V_11 ) ;
}
}
}
return V_111 ;
}
