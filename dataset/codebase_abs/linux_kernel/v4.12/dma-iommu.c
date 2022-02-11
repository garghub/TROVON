static inline T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> type == V_3 )
return V_2 -> V_4 . V_5 ;
return V_6 ;
}
static struct V_1 * F_2 ( enum V_7 type )
{
struct V_1 * V_2 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_8 ) ;
if ( V_2 ) {
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
V_2 -> type = type ;
}
return V_2 ;
}
int F_6 ( void )
{
return F_7 () ;
}
int F_8 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 )
return - V_14 ;
V_12 -> V_13 = F_2 ( V_3 ) ;
if ( ! V_12 -> V_13 )
return - V_15 ;
return 0 ;
}
int F_9 ( struct V_11 * V_12 , T_2 V_16 )
{
struct V_1 * V_2 ;
if ( V_12 -> type != V_17 )
return - V_18 ;
if ( V_12 -> V_13 )
return - V_14 ;
V_2 = F_2 ( V_19 ) ;
if ( ! V_2 )
return - V_15 ;
V_2 -> V_20 = V_16 ;
V_12 -> V_13 = V_2 ;
return 0 ;
}
void F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_21 * V_22 , * V_23 ;
if ( ! V_2 )
return;
if ( V_2 -> type == V_3 && V_2 -> V_4 . V_5 )
F_11 ( & V_2 -> V_4 ) ;
F_12 (msi, tmp, &cookie->msi_page_list, list) {
F_13 ( & V_22 -> V_24 ) ;
F_14 ( V_22 ) ;
}
F_14 ( V_2 ) ;
V_12 -> V_13 = NULL ;
}
void F_15 ( struct V_25 * V_26 , struct V_27 * V_24 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
if ( ! F_16 ( V_26 ) )
return;
V_29 = F_17 ( F_18 ( V_26 ) -> V_32 ) ;
F_19 (window, &bridge->windows) {
struct V_33 * V_34 ;
T_3 V_35 ;
T_1 V_36 ;
if ( F_20 ( V_31 -> V_37 ) != V_38 )
continue;
V_35 = V_31 -> V_37 -> V_35 - V_31 -> V_39 ;
V_36 = V_31 -> V_37 -> V_40 - V_31 -> V_37 -> V_35 + 1 ;
V_34 = F_21 ( V_35 , V_36 , 0 ,
V_41 ) ;
if ( ! V_34 )
return;
F_22 ( & V_34 -> V_24 , V_24 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
T_3 V_35 , T_3 V_40 )
{
struct V_42 * V_4 = & V_2 -> V_4 ;
struct V_21 * V_43 ;
int V_44 , V_45 ;
V_35 -= F_24 ( V_4 , V_35 ) ;
V_45 = F_25 ( V_4 , V_40 - V_35 ) >> F_26 ( V_4 ) ;
V_43 = F_27 ( V_45 , sizeof( * V_43 ) , V_8 ) ;
if ( ! V_43 )
return - V_15 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
V_43 [ V_44 ] . V_46 = V_35 ;
V_43 [ V_44 ] . V_47 = V_35 ;
F_5 ( & V_43 [ V_44 ] . V_24 ) ;
F_28 ( & V_43 [ V_44 ] . V_24 , & V_2 -> V_10 ) ;
V_35 += V_4 -> V_5 ;
}
return 0 ;
}
static int F_29 ( struct V_25 * V_26 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_42 * V_4 = & V_2 -> V_4 ;
struct V_33 * V_34 ;
F_30 ( V_48 ) ;
int V_49 = 0 ;
F_31 ( V_26 , & V_48 ) ;
F_32 (region, &resv_regions, list) {
unsigned long V_50 , V_51 ;
if ( V_34 -> type == V_52 )
continue;
V_50 = F_33 ( V_4 , V_34 -> V_35 ) ;
V_51 = F_33 ( V_4 , V_34 -> V_35 + V_34 -> V_36 - 1 ) ;
F_34 ( V_4 , V_50 , V_51 ) ;
if ( V_34 -> type == V_53 )
V_49 = F_23 ( V_2 , V_34 -> V_35 ,
V_34 -> V_35 + V_34 -> V_36 ) ;
if ( V_49 )
break;
}
F_35 ( V_26 , & V_48 ) ;
return V_49 ;
}
int F_36 ( struct V_11 * V_12 , T_2 V_16 ,
T_4 V_54 , struct V_25 * V_26 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_42 * V_4 = & V_2 -> V_4 ;
unsigned long V_55 , V_56 , V_57 ;
if ( ! V_2 || V_2 -> type != V_3 )
return - V_18 ;
V_55 = F_37 ( V_12 -> V_58 ) ;
V_56 = F_38 (unsigned long, 1 , base >> order) ;
V_57 = ( V_16 + V_54 - 1 ) >> V_55 ;
if ( V_12 -> V_59 . V_60 ) {
if ( V_16 > V_12 -> V_59 . V_61 ||
V_16 + V_54 <= V_12 -> V_59 . V_62 ) {
F_39 ( L_1 ) ;
return - V_63 ;
}
V_56 = F_38 (unsigned long, base_pfn,
domain->geometry.aperture_start >> order) ;
V_57 = F_40 (unsigned long, end_pfn,
domain->geometry.aperture_end >> order) ;
}
if ( V_26 && F_16 ( V_26 ) )
V_57 &= F_41 ( 32 ) >> V_55 ;
if ( V_4 -> V_64 ) {
if ( 1UL << V_55 != V_4 -> V_5 ||
V_56 != V_4 -> V_64 ) {
F_39 ( L_2 ) ;
return - V_63 ;
}
V_4 -> V_65 = F_42 ( V_57 , V_4 -> V_65 ) ;
return 0 ;
}
F_43 ( V_4 , 1UL << V_55 , V_56 , V_57 ) ;
if ( ! V_26 )
return 0 ;
return F_29 ( V_26 , V_12 ) ;
}
int F_44 ( enum V_66 V_67 , bool V_68 ,
unsigned long V_69 )
{
int V_70 = V_68 ? V_71 : 0 ;
if ( V_69 & V_72 )
V_70 |= V_73 ;
switch ( V_67 ) {
case V_74 :
return V_70 | V_75 | V_76 ;
case V_77 :
return V_70 | V_75 ;
case V_78 :
return V_70 | V_76 ;
default:
return 0 ;
}
}
static T_2 F_45 ( struct V_11 * V_12 ,
T_1 V_54 , T_2 V_79 , struct V_25 * V_26 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_42 * V_4 = & V_2 -> V_4 ;
unsigned long V_80 , V_81 , V_47 = 0 ;
if ( V_2 -> type == V_19 ) {
V_2 -> V_20 += V_54 ;
return V_2 -> V_20 - V_54 ;
}
V_80 = F_26 ( V_4 ) ;
V_81 = V_54 >> V_80 ;
if ( V_81 < ( 1 << ( V_82 - 1 ) ) )
V_81 = F_46 ( V_81 ) ;
if ( V_12 -> V_59 . V_60 )
V_79 = F_42 ( V_79 , V_12 -> V_59 . V_61 ) ;
if ( V_79 > F_41 ( 32 ) && F_16 ( V_26 ) )
V_47 = F_47 ( V_4 , V_81 , F_41 ( 32 ) >> V_80 ) ;
if ( ! V_47 )
V_47 = F_47 ( V_4 , V_81 , V_79 >> V_80 ) ;
return ( T_2 ) V_47 << V_80 ;
}
static void F_48 ( struct V_1 * V_2 ,
T_2 V_47 , T_1 V_54 )
{
struct V_42 * V_4 = & V_2 -> V_4 ;
if ( V_2 -> type == V_19 )
V_2 -> V_20 -= V_54 ;
else
F_49 ( V_4 , F_33 ( V_4 , V_47 ) ,
V_54 >> F_26 ( V_4 ) ) ;
}
static void F_50 ( struct V_11 * V_12 , T_2 V_83 ,
T_1 V_54 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_42 * V_4 = & V_2 -> V_4 ;
T_1 V_84 = F_24 ( V_4 , V_83 ) ;
V_83 -= V_84 ;
V_54 = F_25 ( V_4 , V_54 + V_84 ) ;
F_51 ( F_52 ( V_12 , V_83 , V_54 ) != V_54 ) ;
F_48 ( V_2 , V_83 , V_54 ) ;
}
static void F_53 ( struct V_85 * * V_86 , int V_87 )
{
while ( V_87 -- )
F_54 ( V_86 [ V_87 ] ) ;
F_55 ( V_86 ) ;
}
static struct V_85 * * F_56 ( unsigned int V_87 ,
unsigned long V_88 , T_5 V_89 )
{
struct V_85 * * V_86 ;
unsigned int V_44 = 0 , V_90 = V_87 * sizeof( * V_86 ) ;
V_88 &= ( 2U << V_91 ) - 1 ;
if ( ! V_88 )
return NULL ;
if ( V_90 <= V_6 )
V_86 = F_3 ( V_90 , V_8 ) ;
else
V_86 = F_57 ( V_90 ) ;
if ( ! V_86 )
return NULL ;
V_89 |= V_92 | V_93 ;
while ( V_87 ) {
struct V_85 * V_85 = NULL ;
unsigned int V_94 ;
for ( V_88 &= ( 2U << F_58 ( V_87 ) ) - 1 ;
V_88 ; V_88 &= ~ V_94 ) {
unsigned int V_55 = F_58 ( V_88 ) ;
V_94 = 1U << V_55 ;
V_85 = F_59 ( ( V_88 - V_94 ) ?
V_89 | V_95 : V_89 , V_55 ) ;
if ( ! V_85 )
continue;
if ( ! V_55 )
break;
if ( ! F_60 ( V_85 ) ) {
F_61 ( V_85 , V_55 ) ;
break;
} else if ( ! F_62 ( V_85 ) ) {
break;
}
F_63 ( V_85 , V_55 ) ;
}
if ( ! V_85 ) {
F_53 ( V_86 , V_44 ) ;
return NULL ;
}
V_87 -= V_94 ;
while ( V_94 -- )
V_86 [ V_44 ++ ] = V_85 ++ ;
}
return V_86 ;
}
void F_64 ( struct V_25 * V_26 , struct V_85 * * V_86 , T_1 V_54 ,
T_2 * V_96 )
{
F_50 ( F_65 ( V_26 ) , * V_96 , V_54 ) ;
F_53 ( V_86 , F_66 ( V_54 ) >> V_97 ) ;
* V_96 = V_98 ;
}
struct V_85 * * F_67 ( struct V_25 * V_26 , T_1 V_54 , T_5 V_89 ,
unsigned long V_69 , int V_70 , T_2 * V_96 ,
void (* F_68)( struct V_25 * , const void * , T_3 ) )
{
struct V_11 * V_12 = F_65 ( V_26 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_42 * V_4 = & V_2 -> V_4 ;
struct V_85 * * V_86 ;
struct V_99 V_100 ;
T_2 V_47 ;
unsigned int V_87 , V_101 , V_102 = V_12 -> V_58 ;
* V_96 = V_98 ;
V_101 = V_102 & - V_102 ;
if ( V_101 < V_6 ) {
V_101 = V_6 ;
V_102 |= V_6 ;
} else {
V_54 = F_69 ( V_54 , V_101 ) ;
}
if ( V_69 & V_103 )
V_102 = V_101 ;
V_87 = F_66 ( V_54 ) >> V_97 ;
V_86 = F_56 ( V_87 , V_102 >> V_97 , V_89 ) ;
if ( ! V_86 )
return NULL ;
V_54 = F_25 ( V_4 , V_54 ) ;
V_47 = F_45 ( V_12 , V_54 , V_26 -> V_104 , V_26 ) ;
if ( ! V_47 )
goto V_105;
if ( F_70 ( & V_100 , V_86 , V_87 , 0 , V_54 , V_8 ) )
goto V_106;
if ( ! ( V_70 & V_71 ) ) {
struct V_107 V_108 ;
F_71 ( & V_108 , V_100 . V_109 , V_100 . V_110 , V_111 ) ;
while ( F_72 ( & V_108 ) )
F_68 ( V_26 , V_108 . V_112 , F_73 ( V_108 . V_85 ) ) ;
F_74 ( & V_108 ) ;
}
if ( F_75 ( V_12 , V_47 , V_100 . V_109 , V_100 . V_110 , V_70 )
< V_54 )
goto V_113;
* V_96 = V_47 ;
F_76 ( & V_100 ) ;
return V_86 ;
V_113:
F_76 ( & V_100 ) ;
V_106:
F_48 ( V_2 , V_47 , V_54 ) ;
V_105:
F_53 ( V_86 , V_87 ) ;
return NULL ;
}
int F_77 ( struct V_85 * * V_86 , T_1 V_54 , struct V_114 * V_115 )
{
unsigned long V_116 = V_115 -> V_117 ;
unsigned int V_44 , V_87 = F_66 ( V_54 ) >> V_97 ;
int V_49 = - V_118 ;
for ( V_44 = V_115 -> V_119 ; V_44 < V_87 && V_116 < V_115 -> V_120 ; V_44 ++ ) {
V_49 = F_78 ( V_115 , V_116 , V_86 [ V_44 ] ) ;
if ( V_49 )
break;
V_116 += V_6 ;
}
return V_49 ;
}
static T_2 F_79 ( struct V_25 * V_26 , T_3 V_46 ,
T_1 V_54 , int V_70 )
{
struct V_11 * V_12 = F_65 ( V_26 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
T_1 V_84 = 0 ;
T_2 V_47 ;
if ( V_2 -> type == V_3 ) {
V_84 = F_24 ( & V_2 -> V_4 , V_46 ) ;
V_54 = F_25 ( & V_2 -> V_4 , V_54 + V_84 ) ;
}
V_47 = F_45 ( V_12 , V_54 , F_80 ( V_26 ) , V_26 ) ;
if ( ! V_47 )
return V_98 ;
if ( F_81 ( V_12 , V_47 , V_46 - V_84 , V_54 , V_70 ) ) {
F_48 ( V_2 , V_47 , V_54 ) ;
return V_98 ;
}
return V_47 + V_84 ;
}
T_2 F_82 ( struct V_25 * V_26 , struct V_85 * V_85 ,
unsigned long V_39 , T_1 V_54 , int V_70 )
{
return F_79 ( V_26 , F_73 ( V_85 ) + V_39 , V_54 , V_70 ) ;
}
void F_83 ( struct V_25 * V_26 , T_2 V_96 , T_1 V_54 ,
enum V_66 V_67 , unsigned long V_69 )
{
F_50 ( F_65 ( V_26 ) , V_96 , V_54 ) ;
}
static int F_84 ( struct V_25 * V_26 , struct V_121 * V_122 , int V_123 ,
T_2 V_83 )
{
struct V_121 * V_124 , * V_125 = V_122 ;
unsigned long V_126 = F_85 ( V_26 ) ;
unsigned int V_127 = 0 , V_128 = F_86 ( V_26 ) ;
int V_44 , V_87 = 0 ;
F_87 (sg, s, nents, i) {
unsigned int V_129 = F_88 ( V_124 ) ;
unsigned int V_130 = F_89 ( V_124 ) ;
unsigned int V_131 = V_124 -> V_36 ;
V_124 -> V_39 += V_129 ;
V_124 -> V_36 = V_130 ;
F_88 ( V_124 ) = V_98 ;
F_89 ( V_124 ) = 0 ;
if ( V_127 && ! V_129 && ( V_83 & V_126 ) &&
( V_127 + V_130 <= V_128 ) ) {
V_127 += V_130 ;
} else {
if ( V_44 > 0 )
V_125 = F_90 ( V_125 ) ;
V_127 = V_130 ;
V_87 ++ ;
F_88 ( V_125 ) = V_83 + V_129 ;
}
F_89 ( V_125 ) = V_127 ;
V_83 += V_131 ;
if ( V_130 + V_129 < V_131 )
V_127 = 0 ;
}
return V_87 ;
}
static void F_91 ( struct V_121 * V_122 , int V_123 )
{
struct V_121 * V_124 ;
int V_44 ;
F_87 (sg, s, nents, i) {
if ( F_88 ( V_124 ) != V_98 )
V_124 -> V_39 += F_88 ( V_124 ) ;
if ( F_89 ( V_124 ) )
V_124 -> V_36 = F_89 ( V_124 ) ;
F_88 ( V_124 ) = V_98 ;
F_89 ( V_124 ) = 0 ;
}
}
int F_92 ( struct V_25 * V_26 , struct V_121 * V_122 ,
int V_123 , int V_70 )
{
struct V_11 * V_12 = F_65 ( V_26 ) ;
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_42 * V_4 = & V_2 -> V_4 ;
struct V_121 * V_124 , * V_132 = NULL ;
T_2 V_47 ;
T_1 V_81 = 0 ;
unsigned long V_133 = F_85 ( V_26 ) ;
int V_44 ;
F_87 (sg, s, nents, i) {
T_1 V_129 = F_24 ( V_4 , V_124 -> V_39 ) ;
T_1 V_130 = V_124 -> V_36 ;
T_1 V_134 = ( V_133 - V_81 + 1 ) & V_133 ;
F_88 ( V_124 ) = V_129 ;
F_89 ( V_124 ) = V_130 ;
V_124 -> V_39 -= V_129 ;
V_130 = F_25 ( V_4 , V_130 + V_129 ) ;
V_124 -> V_36 = V_130 ;
if ( V_134 && V_134 < V_130 - 1 ) {
V_132 -> V_36 += V_134 ;
V_81 += V_134 ;
}
V_81 += V_130 ;
V_132 = V_124 ;
}
V_47 = F_45 ( V_12 , V_81 , F_80 ( V_26 ) , V_26 ) ;
if ( ! V_47 )
goto V_135;
if ( F_75 ( V_12 , V_47 , V_122 , V_123 , V_70 ) < V_81 )
goto V_106;
return F_84 ( V_26 , V_122 , V_123 , V_47 ) ;
V_106:
F_48 ( V_2 , V_47 , V_81 ) ;
V_135:
F_91 ( V_122 , V_123 ) ;
return 0 ;
}
void F_93 ( struct V_25 * V_26 , struct V_121 * V_122 , int V_123 ,
enum V_66 V_67 , unsigned long V_69 )
{
T_2 V_35 , V_40 ;
struct V_121 * V_23 ;
int V_44 ;
V_35 = F_88 ( V_122 ) ;
F_87 (sg_next(sg), tmp, nents - 1 , i) {
if ( F_89 ( V_23 ) == 0 )
break;
V_122 = V_23 ;
}
V_40 = F_88 ( V_122 ) + F_89 ( V_122 ) ;
F_50 ( F_65 ( V_26 ) , V_35 , V_40 - V_35 ) ;
}
T_2 F_94 ( struct V_25 * V_26 , T_3 V_46 ,
T_1 V_54 , enum V_66 V_67 , unsigned long V_69 )
{
return F_79 ( V_26 , V_46 , V_54 ,
F_44 ( V_67 , false , V_69 ) | V_136 ) ;
}
void F_95 ( struct V_25 * V_26 , T_2 V_96 ,
T_1 V_54 , enum V_66 V_67 , unsigned long V_69 )
{
F_50 ( F_65 ( V_26 ) , V_96 , V_54 ) ;
}
int F_96 ( struct V_25 * V_26 , T_2 V_83 )
{
return V_83 == V_98 ;
}
static struct V_21 * F_97 ( struct V_25 * V_26 ,
T_3 V_137 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
struct V_21 * V_43 ;
T_2 V_47 ;
int V_70 = V_76 | V_138 | V_136 ;
T_1 V_54 = F_1 ( V_2 ) ;
V_137 &= ~ ( T_3 ) ( V_54 - 1 ) ;
F_32 (msi_page, &cookie->msi_page_list, list)
if ( V_43 -> V_46 == V_137 )
return V_43 ;
V_43 = F_3 ( sizeof( * V_43 ) , V_139 ) ;
if ( ! V_43 )
return NULL ;
V_47 = F_79 ( V_26 , V_137 , V_54 , V_70 ) ;
if ( F_96 ( V_26 , V_47 ) )
goto V_140;
F_5 ( & V_43 -> V_24 ) ;
V_43 -> V_46 = V_137 ;
V_43 -> V_47 = V_47 ;
F_28 ( & V_43 -> V_24 , & V_2 -> V_10 ) ;
return V_43 ;
V_140:
F_14 ( V_43 ) ;
return NULL ;
}
void F_98 ( int V_141 , struct V_142 * V_143 )
{
struct V_25 * V_26 = F_99 ( F_100 ( V_141 ) ) ;
struct V_11 * V_12 = F_65 ( V_26 ) ;
struct V_1 * V_2 ;
struct V_21 * V_43 ;
T_3 V_137 = ( T_4 ) V_143 -> V_144 << 32 | V_143 -> V_145 ;
unsigned long V_146 ;
if ( ! V_12 || ! V_12 -> V_13 )
return;
V_2 = V_12 -> V_13 ;
F_101 ( & V_2 -> V_9 , V_146 ) ;
V_43 = F_97 ( V_26 , V_137 , V_12 ) ;
F_102 ( & V_2 -> V_9 , V_146 ) ;
if ( F_51 ( ! V_43 ) ) {
V_143 -> V_144 = ~ 0U ;
V_143 -> V_145 = ~ 0U ;
V_143 -> V_147 = ~ 0U ;
} else {
V_143 -> V_144 = F_103 ( V_43 -> V_47 ) ;
V_143 -> V_145 &= F_1 ( V_2 ) - 1 ;
V_143 -> V_145 += F_104 ( V_43 -> V_47 ) ;
}
}
