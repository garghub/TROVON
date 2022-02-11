static inline T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_3 )
return V_2 -> V_4 . V_5 ;
return V_6 ;
}
static inline struct V_7 * F_2 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
if ( V_2 -> type == V_3 )
return & V_2 -> V_4 ;
return NULL ;
}
static struct V_1 * F_3 ( enum V_11 type )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_12 ) ;
if ( V_2 ) {
F_5 ( & V_2 -> V_13 ) ;
F_6 ( & V_2 -> V_14 ) ;
V_2 -> type = type ;
}
return V_2 ;
}
int F_7 ( void )
{
return F_8 () ;
}
int F_9 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 )
return - V_15 ;
V_9 -> V_10 = F_3 ( V_3 ) ;
if ( ! V_9 -> V_10 )
return - V_16 ;
return 0 ;
}
int F_10 ( struct V_8 * V_9 , T_2 V_17 )
{
struct V_1 * V_2 ;
if ( V_9 -> type != V_18 )
return - V_19 ;
if ( V_9 -> V_10 )
return - V_15 ;
V_2 = F_3 ( V_20 ) ;
if ( ! V_2 )
return - V_16 ;
V_2 -> V_21 = V_17 ;
V_9 -> V_10 = V_2 ;
return 0 ;
}
void F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
struct V_22 * V_23 , * V_24 ;
if ( ! V_2 )
return;
if ( V_2 -> type == V_3 && V_2 -> V_4 . V_5 )
F_12 ( & V_2 -> V_4 ) ;
F_13 (msi, tmp, &cookie->msi_page_list, list) {
F_14 ( & V_23 -> V_25 ) ;
F_15 ( V_23 ) ;
}
F_15 ( V_2 ) ;
V_9 -> V_10 = NULL ;
}
static void F_16 ( struct V_26 * V_27 ,
struct V_7 * V_4 )
{
struct V_28 * V_29 = F_17 ( V_27 -> V_30 ) ;
struct V_31 * V_32 ;
unsigned long V_33 , V_34 ;
F_18 (window, &bridge->windows) {
if ( F_19 ( V_32 -> V_35 ) != V_36 &&
F_19 ( V_32 -> V_35 ) != V_37 )
continue;
V_33 = F_20 ( V_4 , V_32 -> V_35 -> V_38 - V_32 -> V_39 ) ;
V_34 = F_20 ( V_4 , V_32 -> V_35 -> V_40 - V_32 -> V_39 ) ;
F_21 ( V_4 , V_33 , V_34 ) ;
}
}
int F_22 ( struct V_8 * V_9 , T_2 V_17 ,
T_3 V_41 , struct V_42 * V_27 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
struct V_7 * V_4 = & V_2 -> V_4 ;
unsigned long V_43 , V_44 , V_45 ;
bool V_46 = V_27 && F_23 ( V_27 ) ;
if ( ! V_2 || V_2 -> type != V_3 )
return - V_19 ;
V_43 = F_24 ( V_9 -> V_47 ) ;
V_44 = F_25 (unsigned long, 1 , base >> order) ;
V_45 = ( V_17 + V_41 - 1 ) >> V_43 ;
if ( V_9 -> V_48 . V_49 ) {
if ( V_17 > V_9 -> V_48 . V_50 ||
V_17 + V_41 <= V_9 -> V_48 . V_51 ) {
F_26 ( L_1 ) ;
return - V_52 ;
}
V_44 = F_25 (unsigned long, base_pfn,
domain->geometry.aperture_start >> order) ;
V_45 = F_27 (unsigned long, end_pfn,
domain->geometry.aperture_end >> order) ;
}
if ( V_46 )
V_45 &= F_28 ( 32 ) >> V_43 ;
if ( V_4 -> V_53 ) {
if ( 1UL << V_43 != V_4 -> V_5 ||
V_44 != V_4 -> V_53 ) {
F_26 ( L_2 ) ;
return - V_52 ;
}
V_4 -> V_54 = F_29 ( V_45 , V_4 -> V_54 ) ;
} else {
F_30 ( V_4 , 1UL << V_43 , V_44 , V_45 ) ;
if ( V_46 )
F_16 ( F_31 ( V_27 ) , V_4 ) ;
}
return 0 ;
}
int F_32 ( enum V_55 V_56 , bool V_57 ,
unsigned long V_58 )
{
int V_59 = V_57 ? V_60 : 0 ;
if ( V_58 & V_61 )
V_59 |= V_62 ;
switch ( V_56 ) {
case V_63 :
return V_59 | V_64 | V_65 ;
case V_66 :
return V_59 | V_64 ;
case V_67 :
return V_59 | V_65 ;
default:
return 0 ;
}
}
static struct V_68 * F_33 ( struct V_8 * V_9 , T_1 V_41 ,
T_2 V_69 , struct V_42 * V_27 )
{
struct V_7 * V_4 = F_2 ( V_9 ) ;
unsigned long V_70 = F_34 ( V_4 ) ;
unsigned long V_71 = F_35 ( V_4 , V_41 ) >> V_70 ;
struct V_68 * V_68 = NULL ;
if ( V_9 -> V_48 . V_49 )
V_69 = F_29 ( V_69 , V_9 -> V_48 . V_50 ) ;
if ( V_69 > F_28 ( 32 ) && F_23 ( V_27 ) )
V_68 = F_36 ( V_4 , V_71 , F_28 ( 32 ) >> V_70 ,
true ) ;
if ( ! V_68 )
V_68 = F_36 ( V_4 , V_71 , V_69 >> V_70 , true ) ;
return V_68 ;
}
static void F_37 ( struct V_8 * V_9 , T_2 V_72 )
{
struct V_7 * V_4 = F_2 ( V_9 ) ;
unsigned long V_70 = F_34 ( V_4 ) ;
unsigned long V_73 = V_72 >> V_70 ;
struct V_68 * V_68 = F_38 ( V_4 , V_73 ) ;
T_1 V_41 ;
if ( F_39 ( ! V_68 ) )
return;
V_41 = F_40 ( V_68 ) << V_70 ;
V_41 -= F_41 ( V_9 , V_73 << V_70 , V_41 ) ;
F_39 ( V_41 > 0 ) ;
F_42 ( V_4 , V_68 ) ;
}
static void F_43 ( struct V_74 * * V_75 , int V_76 )
{
while ( V_76 -- )
F_44 ( V_75 [ V_76 ] ) ;
F_45 ( V_75 ) ;
}
static struct V_74 * * F_46 ( unsigned int V_76 ,
unsigned long V_77 , T_4 V_78 )
{
struct V_74 * * V_75 ;
unsigned int V_79 = 0 , V_80 = V_76 * sizeof( * V_75 ) ;
V_77 &= ( 2U << V_81 ) - 1 ;
if ( ! V_77 )
return NULL ;
if ( V_80 <= V_6 )
V_75 = F_4 ( V_80 , V_12 ) ;
else
V_75 = F_47 ( V_80 ) ;
if ( ! V_75 )
return NULL ;
V_78 |= V_82 | V_83 ;
while ( V_76 ) {
struct V_74 * V_74 = NULL ;
unsigned int V_84 ;
for ( V_77 &= ( 2U << F_48 ( V_76 ) ) - 1 ;
V_77 ; V_77 &= ~ V_84 ) {
unsigned int V_43 = F_48 ( V_77 ) ;
V_84 = 1U << V_43 ;
V_74 = F_49 ( ( V_77 - V_84 ) ?
V_78 | V_85 : V_78 , V_43 ) ;
if ( ! V_74 )
continue;
if ( ! V_43 )
break;
if ( ! F_50 ( V_74 ) ) {
F_51 ( V_74 , V_43 ) ;
break;
} else if ( ! F_52 ( V_74 ) ) {
break;
}
F_53 ( V_74 , V_43 ) ;
}
if ( ! V_74 ) {
F_43 ( V_75 , V_79 ) ;
return NULL ;
}
V_76 -= V_84 ;
while ( V_84 -- )
V_75 [ V_79 ++ ] = V_74 ++ ;
}
return V_75 ;
}
void F_54 ( struct V_42 * V_27 , struct V_74 * * V_75 , T_1 V_41 ,
T_2 * V_86 )
{
F_37 ( F_55 ( V_27 ) , * V_86 ) ;
F_43 ( V_75 , F_56 ( V_41 ) >> V_87 ) ;
* V_86 = V_88 ;
}
struct V_74 * * F_57 ( struct V_42 * V_27 , T_1 V_41 , T_4 V_78 ,
unsigned long V_58 , int V_59 , T_2 * V_86 ,
void (* F_58)( struct V_42 * , const void * , T_5 ) )
{
struct V_8 * V_9 = F_55 ( V_27 ) ;
struct V_7 * V_4 = F_2 ( V_9 ) ;
struct V_68 * V_68 ;
struct V_74 * * V_75 ;
struct V_89 V_90 ;
T_2 V_72 ;
unsigned int V_76 , V_91 , V_92 = V_9 -> V_47 ;
* V_86 = V_88 ;
V_91 = V_92 & - V_92 ;
if ( V_91 < V_6 ) {
V_91 = V_6 ;
V_92 |= V_6 ;
} else {
V_41 = F_59 ( V_41 , V_91 ) ;
}
if ( V_58 & V_93 )
V_92 = V_91 ;
V_76 = F_56 ( V_41 ) >> V_87 ;
V_75 = F_46 ( V_76 , V_92 >> V_87 , V_78 ) ;
if ( ! V_75 )
return NULL ;
V_68 = F_33 ( V_9 , V_41 , V_27 -> V_94 , V_27 ) ;
if ( ! V_68 )
goto V_95;
V_41 = F_35 ( V_4 , V_41 ) ;
if ( F_60 ( & V_90 , V_75 , V_76 , 0 , V_41 , V_12 ) )
goto V_96;
if ( ! ( V_59 & V_60 ) ) {
struct V_97 V_98 ;
F_61 ( & V_98 , V_90 . V_99 , V_90 . V_100 , V_101 ) ;
while ( F_62 ( & V_98 ) )
F_58 ( V_27 , V_98 . V_102 , F_63 ( V_98 . V_74 ) ) ;
F_64 ( & V_98 ) ;
}
V_72 = F_65 ( V_4 , V_68 ) ;
if ( F_66 ( V_9 , V_72 , V_90 . V_99 , V_90 . V_100 , V_59 )
< V_41 )
goto V_103;
* V_86 = V_72 ;
F_67 ( & V_90 ) ;
return V_75 ;
V_103:
F_67 ( & V_90 ) ;
V_96:
F_42 ( V_4 , V_68 ) ;
V_95:
F_43 ( V_75 , V_76 ) ;
return NULL ;
}
int F_68 ( struct V_74 * * V_75 , T_1 V_41 , struct V_104 * V_105 )
{
unsigned long V_106 = V_105 -> V_107 ;
unsigned int V_79 , V_76 = F_56 ( V_41 ) >> V_87 ;
int V_108 = - V_109 ;
for ( V_79 = V_105 -> V_110 ; V_79 < V_76 && V_106 < V_105 -> V_111 ; V_79 ++ ) {
V_108 = F_69 ( V_105 , V_106 , V_75 [ V_79 ] ) ;
if ( V_108 )
break;
V_106 += V_6 ;
}
return V_108 ;
}
static T_2 F_70 ( struct V_42 * V_27 , T_5 V_112 ,
T_1 V_41 , int V_59 )
{
T_2 V_72 ;
struct V_8 * V_9 = F_55 ( V_27 ) ;
struct V_7 * V_4 = F_2 ( V_9 ) ;
T_1 V_113 = F_71 ( V_4 , V_112 ) ;
T_1 V_114 = F_35 ( V_4 , V_41 + V_113 ) ;
struct V_68 * V_68 = F_33 ( V_9 , V_114 , F_72 ( V_27 ) , V_27 ) ;
if ( ! V_68 )
return V_88 ;
V_72 = F_65 ( V_4 , V_68 ) ;
if ( F_73 ( V_9 , V_72 , V_112 - V_113 , V_114 , V_59 ) ) {
F_42 ( V_4 , V_68 ) ;
return V_88 ;
}
return V_72 + V_113 ;
}
T_2 F_74 ( struct V_42 * V_27 , struct V_74 * V_74 ,
unsigned long V_39 , T_1 V_41 , int V_59 )
{
return F_70 ( V_27 , F_63 ( V_74 ) + V_39 , V_41 , V_59 ) ;
}
void F_75 ( struct V_42 * V_27 , T_2 V_86 , T_1 V_41 ,
enum V_55 V_56 , unsigned long V_58 )
{
F_37 ( F_55 ( V_27 ) , V_86 ) ;
}
static int F_76 ( struct V_42 * V_27 , struct V_115 * V_116 , int V_117 ,
T_2 V_72 )
{
struct V_115 * V_118 , * V_119 = V_116 ;
unsigned long V_120 = F_77 ( V_27 ) ;
unsigned int V_121 = 0 , V_122 = F_78 ( V_27 ) ;
int V_79 , V_76 = 0 ;
F_79 (sg, s, nents, i) {
unsigned int V_123 = F_80 ( V_118 ) ;
unsigned int V_124 = F_81 ( V_118 ) ;
unsigned int V_125 = V_118 -> V_71 ;
V_118 -> V_39 += V_123 ;
V_118 -> V_71 = V_124 ;
F_80 ( V_118 ) = V_88 ;
F_81 ( V_118 ) = 0 ;
if ( V_121 && ! V_123 && ( V_72 & V_120 ) &&
( V_121 + V_124 <= V_122 ) ) {
V_121 += V_124 ;
} else {
if ( V_79 > 0 )
V_119 = F_82 ( V_119 ) ;
V_121 = V_124 ;
V_76 ++ ;
F_80 ( V_119 ) = V_72 + V_123 ;
}
F_81 ( V_119 ) = V_121 ;
V_72 += V_125 ;
if ( V_124 + V_123 < V_125 )
V_121 = 0 ;
}
return V_76 ;
}
static void F_83 ( struct V_115 * V_116 , int V_117 )
{
struct V_115 * V_118 ;
int V_79 ;
F_79 (sg, s, nents, i) {
if ( F_80 ( V_118 ) != V_88 )
V_118 -> V_39 += F_80 ( V_118 ) ;
if ( F_81 ( V_118 ) )
V_118 -> V_71 = F_81 ( V_118 ) ;
F_80 ( V_118 ) = V_88 ;
F_81 ( V_118 ) = 0 ;
}
}
int F_84 ( struct V_42 * V_27 , struct V_115 * V_116 ,
int V_117 , int V_59 )
{
struct V_8 * V_9 = F_55 ( V_27 ) ;
struct V_7 * V_4 = F_2 ( V_9 ) ;
struct V_68 * V_68 ;
struct V_115 * V_118 , * V_126 = NULL ;
T_2 V_72 ;
T_1 V_127 = 0 ;
unsigned long V_128 = F_77 ( V_27 ) ;
int V_79 ;
F_79 (sg, s, nents, i) {
T_1 V_123 = F_71 ( V_4 , V_118 -> V_39 ) ;
T_1 V_124 = V_118 -> V_71 ;
T_1 V_129 = ( V_128 - V_127 + 1 ) & V_128 ;
F_80 ( V_118 ) = V_123 ;
F_81 ( V_118 ) = V_124 ;
V_118 -> V_39 -= V_123 ;
V_124 = F_35 ( V_4 , V_124 + V_123 ) ;
V_118 -> V_71 = V_124 ;
if ( V_129 && V_129 < V_124 - 1 ) {
V_126 -> V_71 += V_129 ;
V_127 += V_129 ;
}
V_127 += V_124 ;
V_126 = V_118 ;
}
V_68 = F_33 ( V_9 , V_127 , F_72 ( V_27 ) , V_27 ) ;
if ( ! V_68 )
goto V_130;
V_72 = F_65 ( V_4 , V_68 ) ;
if ( F_66 ( V_9 , V_72 , V_116 , V_117 , V_59 ) < V_127 )
goto V_96;
return F_76 ( V_27 , V_116 , V_117 , V_72 ) ;
V_96:
F_42 ( V_4 , V_68 ) ;
V_130:
F_83 ( V_116 , V_117 ) ;
return 0 ;
}
void F_85 ( struct V_42 * V_27 , struct V_115 * V_116 , int V_117 ,
enum V_55 V_56 , unsigned long V_58 )
{
F_37 ( F_55 ( V_27 ) , F_80 ( V_116 ) ) ;
}
T_2 F_86 ( struct V_42 * V_27 , T_5 V_112 ,
T_1 V_41 , enum V_55 V_56 , unsigned long V_58 )
{
return F_70 ( V_27 , V_112 , V_41 ,
F_32 ( V_56 , false , V_58 ) | V_131 ) ;
}
void F_87 ( struct V_42 * V_27 , T_2 V_86 ,
T_1 V_41 , enum V_55 V_56 , unsigned long V_58 )
{
F_37 ( F_55 ( V_27 ) , V_86 ) ;
}
int F_88 ( struct V_42 * V_27 , T_2 V_72 )
{
return V_72 == V_88 ;
}
static struct V_22 * F_89 ( struct V_42 * V_27 ,
T_5 V_132 , struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
struct V_22 * V_133 ;
struct V_7 * V_4 = F_2 ( V_9 ) ;
struct V_68 * V_68 ;
int V_59 = V_65 | V_134 | V_131 ;
T_1 V_41 = F_1 ( V_2 ) ;
V_132 &= ~ ( T_5 ) ( V_41 - 1 ) ;
F_90 (msi_page, &cookie->msi_page_list, list)
if ( V_133 -> V_112 == V_132 )
return V_133 ;
V_133 = F_4 ( sizeof( * V_133 ) , V_135 ) ;
if ( ! V_133 )
return NULL ;
V_133 -> V_112 = V_132 ;
if ( V_4 ) {
V_68 = F_33 ( V_9 , V_41 , F_72 ( V_27 ) , V_27 ) ;
if ( ! V_68 )
goto V_136;
V_133 -> V_68 = F_65 ( V_4 , V_68 ) ;
} else {
V_133 -> V_68 = V_2 -> V_21 ;
V_2 -> V_21 += V_41 ;
}
if ( F_73 ( V_9 , V_133 -> V_68 , V_132 , V_41 , V_59 ) )
goto V_96;
F_6 ( & V_133 -> V_25 ) ;
F_91 ( & V_133 -> V_25 , & V_2 -> V_14 ) ;
return V_133 ;
V_96:
if ( V_4 )
F_42 ( V_4 , V_68 ) ;
else
V_2 -> V_21 -= V_41 ;
V_136:
F_15 ( V_133 ) ;
return NULL ;
}
void F_92 ( int V_137 , struct V_138 * V_139 )
{
struct V_42 * V_27 = F_93 ( F_94 ( V_137 ) ) ;
struct V_8 * V_9 = F_55 ( V_27 ) ;
struct V_1 * V_2 ;
struct V_22 * V_133 ;
T_5 V_132 = ( T_3 ) V_139 -> V_140 << 32 | V_139 -> V_141 ;
unsigned long V_142 ;
if ( ! V_9 || ! V_9 -> V_10 )
return;
V_2 = V_9 -> V_10 ;
F_95 ( & V_2 -> V_13 , V_142 ) ;
V_133 = F_89 ( V_27 , V_132 , V_9 ) ;
F_96 ( & V_2 -> V_13 , V_142 ) ;
if ( F_39 ( ! V_133 ) ) {
V_139 -> V_140 = ~ 0U ;
V_139 -> V_141 = ~ 0U ;
V_139 -> V_143 = ~ 0U ;
} else {
V_139 -> V_140 = F_97 ( V_133 -> V_68 ) ;
V_139 -> V_141 &= F_1 ( V_2 ) - 1 ;
V_139 -> V_141 += F_98 ( V_133 -> V_68 ) ;
}
}
