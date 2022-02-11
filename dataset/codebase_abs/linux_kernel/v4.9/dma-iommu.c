static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( (struct V_4 * ) V_3 -> V_5 ) -> V_6 ;
}
int F_2 ( void )
{
return F_3 () ;
}
int F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_7 ;
if ( V_3 -> V_5 )
return - V_8 ;
V_7 = F_5 ( sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return - V_10 ;
F_6 ( & V_7 -> V_11 ) ;
F_7 ( & V_7 -> V_12 ) ;
V_3 -> V_5 = V_7 ;
return 0 ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_4 * V_7 = V_3 -> V_5 ;
struct V_13 * V_14 , * V_15 ;
if ( ! V_7 )
return;
if ( V_7 -> V_6 . V_16 )
F_9 ( & V_7 -> V_6 ) ;
F_10 (msi, tmp, &cookie->msi_page_list, list) {
F_11 ( & V_14 -> V_17 ) ;
F_12 ( V_14 ) ;
}
F_12 ( V_7 ) ;
V_3 -> V_5 = NULL ;
}
static void F_13 ( struct V_18 * V_19 ,
struct V_1 * V_6 )
{
struct V_20 * V_21 = F_14 ( V_19 -> V_22 ) ;
struct V_23 * V_24 ;
unsigned long V_25 , V_26 ;
F_15 (window, &bridge->windows) {
if ( F_16 ( V_24 -> V_27 ) != V_28 &&
F_16 ( V_24 -> V_27 ) != V_29 )
continue;
V_25 = F_17 ( V_6 , V_24 -> V_27 -> V_30 - V_24 -> V_31 ) ;
V_26 = F_17 ( V_6 , V_24 -> V_27 -> V_32 - V_24 -> V_31 ) ;
F_18 ( V_6 , V_25 , V_26 ) ;
}
}
int F_19 ( struct V_2 * V_3 , T_1 V_33 ,
T_2 V_34 , struct V_35 * V_19 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_36 , V_37 , V_38 ;
if ( ! V_6 )
return - V_39 ;
V_36 = F_20 ( V_3 -> V_40 ) ;
V_37 = F_21 (unsigned long, 1 , base >> order) ;
V_38 = ( V_33 + V_34 - 1 ) >> V_36 ;
if ( V_3 -> V_41 . V_42 ) {
if ( V_33 > V_3 -> V_41 . V_43 ||
V_33 + V_34 <= V_3 -> V_41 . V_44 ) {
F_22 ( L_1 ) ;
return - V_45 ;
}
V_37 = F_21 (unsigned long, base_pfn,
domain->geometry.aperture_start >> order) ;
V_38 = F_23 (unsigned long, end_pfn,
domain->geometry.aperture_end >> order) ;
}
if ( V_6 -> V_46 ) {
if ( 1UL << V_36 != V_6 -> V_16 ||
V_37 != V_6 -> V_46 ||
V_38 < V_6 -> V_47 ) {
F_22 ( L_2 ) ;
return - V_45 ;
}
V_6 -> V_47 = V_38 ;
} else {
F_24 ( V_6 , 1UL << V_36 , V_37 , V_38 ) ;
if ( V_19 && F_25 ( V_19 ) )
F_13 ( F_26 ( V_19 ) , V_6 ) ;
}
return 0 ;
}
int F_27 ( enum V_48 V_49 , bool V_50 )
{
int V_51 = V_50 ? V_52 : 0 ;
switch ( V_49 ) {
case V_53 :
return V_51 | V_54 | V_55 ;
case V_56 :
return V_51 | V_54 ;
case V_57 :
return V_51 | V_55 ;
default:
return 0 ;
}
}
static struct V_58 * F_28 ( struct V_2 * V_3 , T_3 V_34 ,
T_1 V_59 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_60 = F_29 ( V_6 ) ;
unsigned long V_61 = F_30 ( V_6 , V_34 ) >> V_60 ;
if ( V_3 -> V_41 . V_42 )
V_59 = F_31 ( V_59 , V_3 -> V_41 . V_43 ) ;
return F_32 ( V_6 , V_61 , V_59 >> V_60 , true ) ;
}
static void F_33 ( struct V_2 * V_3 , T_1 V_62 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_60 = F_29 ( V_6 ) ;
unsigned long V_63 = V_62 >> V_60 ;
struct V_58 * V_58 = F_34 ( V_6 , V_63 ) ;
T_3 V_34 ;
if ( F_35 ( ! V_58 ) )
return;
V_34 = F_36 ( V_58 ) << V_60 ;
V_34 -= F_37 ( V_3 , V_63 << V_60 , V_34 ) ;
F_35 ( V_34 > 0 ) ;
F_38 ( V_6 , V_58 ) ;
}
static void F_39 ( struct V_64 * * V_65 , int V_66 )
{
while ( V_66 -- )
F_40 ( V_65 [ V_66 ] ) ;
F_41 ( V_65 ) ;
}
static struct V_64 * * F_42 ( unsigned int V_66 ,
unsigned long V_67 , T_4 V_68 )
{
struct V_64 * * V_65 ;
unsigned int V_69 = 0 , V_70 = V_66 * sizeof( * V_65 ) ;
V_67 &= ( 2U << V_71 ) - 1 ;
if ( ! V_67 )
return NULL ;
if ( V_70 <= V_72 )
V_65 = F_5 ( V_70 , V_9 ) ;
else
V_65 = F_43 ( V_70 ) ;
if ( ! V_65 )
return NULL ;
V_68 |= V_73 | V_74 ;
while ( V_66 ) {
struct V_64 * V_64 = NULL ;
unsigned int V_75 ;
for ( V_67 &= ( 2U << F_44 ( V_66 ) ) - 1 ;
V_67 ; V_67 &= ~ V_75 ) {
unsigned int V_36 = F_44 ( V_67 ) ;
V_75 = 1U << V_36 ;
V_64 = F_45 ( ( V_67 - V_75 ) ?
V_68 | V_76 : V_68 , V_36 ) ;
if ( ! V_64 )
continue;
if ( ! V_36 )
break;
if ( ! F_46 ( V_64 ) ) {
F_47 ( V_64 , V_36 ) ;
break;
} else if ( ! F_48 ( V_64 ) ) {
break;
}
F_49 ( V_64 , V_36 ) ;
}
if ( ! V_64 ) {
F_39 ( V_65 , V_69 ) ;
return NULL ;
}
V_66 -= V_75 ;
while ( V_75 -- )
V_65 [ V_69 ++ ] = V_64 ++ ;
}
return V_65 ;
}
void F_50 ( struct V_35 * V_19 , struct V_64 * * V_65 , T_3 V_34 ,
T_1 * V_77 )
{
F_33 ( F_51 ( V_19 ) , * V_77 ) ;
F_39 ( V_65 , F_52 ( V_34 ) >> V_78 ) ;
* V_77 = V_79 ;
}
struct V_64 * * F_53 ( struct V_35 * V_19 , T_3 V_34 , T_4 V_68 ,
unsigned long V_80 , int V_51 , T_1 * V_77 ,
void (* F_54)( struct V_35 * , const void * , T_5 ) )
{
struct V_2 * V_3 = F_51 ( V_19 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_58 * V_58 ;
struct V_64 * * V_65 ;
struct V_81 V_82 ;
T_1 V_62 ;
unsigned int V_66 , V_83 , V_84 = V_3 -> V_40 ;
* V_77 = V_79 ;
V_83 = V_84 & - V_84 ;
if ( V_83 < V_72 ) {
V_83 = V_72 ;
V_84 |= V_72 ;
} else {
V_34 = F_55 ( V_34 , V_83 ) ;
}
if ( V_80 & V_85 )
V_84 = V_83 ;
V_66 = F_52 ( V_34 ) >> V_78 ;
V_65 = F_42 ( V_66 , V_84 >> V_78 , V_68 ) ;
if ( ! V_65 )
return NULL ;
V_58 = F_28 ( V_3 , V_34 , V_19 -> V_86 ) ;
if ( ! V_58 )
goto V_87;
V_34 = F_30 ( V_6 , V_34 ) ;
if ( F_56 ( & V_82 , V_65 , V_66 , 0 , V_34 , V_9 ) )
goto V_88;
if ( ! ( V_51 & V_52 ) ) {
struct V_89 V_90 ;
F_57 ( & V_90 , V_82 . V_91 , V_82 . V_92 , V_93 ) ;
while ( F_58 ( & V_90 ) )
F_54 ( V_19 , V_90 . V_94 , F_59 ( V_90 . V_64 ) ) ;
F_60 ( & V_90 ) ;
}
V_62 = F_61 ( V_6 , V_58 ) ;
if ( F_62 ( V_3 , V_62 , V_82 . V_91 , V_82 . V_92 , V_51 )
< V_34 )
goto V_95;
* V_77 = V_62 ;
F_63 ( & V_82 ) ;
return V_65 ;
V_95:
F_63 ( & V_82 ) ;
V_88:
F_38 ( V_6 , V_58 ) ;
V_87:
F_39 ( V_65 , V_66 ) ;
return NULL ;
}
int F_64 ( struct V_64 * * V_65 , T_3 V_34 , struct V_96 * V_97 )
{
unsigned long V_98 = V_97 -> V_99 ;
unsigned int V_69 , V_66 = F_52 ( V_34 ) >> V_78 ;
int V_100 = - V_101 ;
for ( V_69 = V_97 -> V_102 ; V_69 < V_66 && V_98 < V_97 -> V_103 ; V_69 ++ ) {
V_100 = F_65 ( V_97 , V_98 , V_65 [ V_69 ] ) ;
if ( V_100 )
break;
V_98 += V_72 ;
}
return V_100 ;
}
T_1 F_66 ( struct V_35 * V_19 , struct V_64 * V_64 ,
unsigned long V_31 , T_3 V_34 , int V_51 )
{
T_1 V_62 ;
struct V_2 * V_3 = F_51 ( V_19 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_5 V_104 = F_59 ( V_64 ) + V_31 ;
T_3 V_105 = F_67 ( V_6 , V_104 ) ;
T_3 V_106 = F_30 ( V_6 , V_34 + V_105 ) ;
struct V_58 * V_58 = F_28 ( V_3 , V_106 , F_68 ( V_19 ) ) ;
if ( ! V_58 )
return V_79 ;
V_62 = F_61 ( V_6 , V_58 ) ;
if ( F_69 ( V_3 , V_62 , V_104 - V_105 , V_106 , V_51 ) ) {
F_38 ( V_6 , V_58 ) ;
return V_79 ;
}
return V_62 + V_105 ;
}
void F_70 ( struct V_35 * V_19 , T_1 V_77 , T_3 V_34 ,
enum V_48 V_49 , unsigned long V_80 )
{
F_33 ( F_51 ( V_19 ) , V_77 ) ;
}
static int F_71 ( struct V_35 * V_19 , struct V_107 * V_108 , int V_109 ,
T_1 V_62 )
{
struct V_107 * V_110 , * V_111 = V_108 ;
unsigned long V_112 = F_72 ( V_19 ) ;
unsigned int V_113 = 0 , V_114 = F_73 ( V_19 ) ;
int V_69 , V_66 = 0 ;
F_74 (sg, s, nents, i) {
unsigned int V_115 = F_75 ( V_110 ) ;
unsigned int V_116 = F_76 ( V_110 ) ;
unsigned int V_117 = V_110 -> V_61 ;
V_110 -> V_31 += V_115 ;
V_110 -> V_61 = V_116 ;
F_75 ( V_110 ) = V_79 ;
F_76 ( V_110 ) = 0 ;
if ( V_113 && ! V_115 && ( V_62 & V_112 ) &&
( V_113 + V_116 <= V_114 ) ) {
V_113 += V_116 ;
} else {
if ( V_69 > 0 )
V_111 = F_77 ( V_111 ) ;
V_113 = V_116 ;
V_66 ++ ;
F_75 ( V_111 ) = V_62 + V_115 ;
}
F_76 ( V_111 ) = V_113 ;
V_62 += V_117 ;
if ( V_116 + V_115 < V_117 )
V_113 = 0 ;
}
return V_66 ;
}
static void F_78 ( struct V_107 * V_108 , int V_109 )
{
struct V_107 * V_110 ;
int V_69 ;
F_74 (sg, s, nents, i) {
if ( F_75 ( V_110 ) != V_79 )
V_110 -> V_31 += F_75 ( V_110 ) ;
if ( F_76 ( V_110 ) )
V_110 -> V_61 = F_76 ( V_110 ) ;
F_75 ( V_110 ) = V_79 ;
F_76 ( V_110 ) = 0 ;
}
}
int F_79 ( struct V_35 * V_19 , struct V_107 * V_108 ,
int V_109 , int V_51 )
{
struct V_2 * V_3 = F_51 ( V_19 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_58 * V_58 ;
struct V_107 * V_110 , * V_118 = NULL ;
T_1 V_62 ;
T_3 V_119 = 0 ;
unsigned long V_120 = F_72 ( V_19 ) ;
int V_69 ;
F_74 (sg, s, nents, i) {
T_3 V_115 = F_67 ( V_6 , V_110 -> V_31 ) ;
T_3 V_116 = V_110 -> V_61 ;
T_3 V_121 = ( V_120 - V_119 + 1 ) & V_120 ;
F_75 ( V_110 ) = V_115 ;
F_76 ( V_110 ) = V_116 ;
V_110 -> V_31 -= V_115 ;
V_116 = F_30 ( V_6 , V_116 + V_115 ) ;
V_110 -> V_61 = V_116 ;
if ( V_121 && V_121 < V_116 - 1 ) {
V_118 -> V_61 += V_121 ;
V_119 += V_121 ;
}
V_119 += V_116 ;
V_118 = V_110 ;
}
V_58 = F_28 ( V_3 , V_119 , F_68 ( V_19 ) ) ;
if ( ! V_58 )
goto V_122;
V_62 = F_61 ( V_6 , V_58 ) ;
if ( F_62 ( V_3 , V_62 , V_108 , V_109 , V_51 ) < V_119 )
goto V_88;
return F_71 ( V_19 , V_108 , V_109 , V_62 ) ;
V_88:
F_38 ( V_6 , V_58 ) ;
V_122:
F_78 ( V_108 , V_109 ) ;
return 0 ;
}
void F_80 ( struct V_35 * V_19 , struct V_107 * V_108 , int V_109 ,
enum V_48 V_49 , unsigned long V_80 )
{
F_33 ( F_51 ( V_19 ) , F_75 ( V_108 ) ) ;
}
int F_81 ( struct V_35 * V_19 , T_2 V_120 )
{
return 1 ;
}
int F_82 ( struct V_35 * V_19 , T_1 V_62 )
{
return V_62 == V_79 ;
}
static struct V_13 * F_83 ( struct V_35 * V_19 ,
T_5 V_123 , struct V_2 * V_3 )
{
struct V_4 * V_7 = V_3 -> V_5 ;
struct V_13 * V_124 ;
struct V_1 * V_6 = & V_7 -> V_6 ;
struct V_58 * V_58 ;
int V_51 = V_55 | V_125 | V_126 ;
V_123 &= ~ ( T_5 ) F_84 ( V_6 ) ;
F_85 (msi_page, &cookie->msi_page_list, list)
if ( V_124 -> V_104 == V_123 )
return V_124 ;
V_124 = F_5 ( sizeof( * V_124 ) , V_127 ) ;
if ( ! V_124 )
return NULL ;
V_58 = F_28 ( V_3 , V_6 -> V_16 , F_68 ( V_19 ) ) ;
if ( ! V_58 )
goto V_128;
V_124 -> V_104 = V_123 ;
V_124 -> V_58 = F_61 ( V_6 , V_58 ) ;
if ( F_69 ( V_3 , V_124 -> V_58 , V_123 , V_6 -> V_16 , V_51 ) )
goto V_88;
F_7 ( & V_124 -> V_17 ) ;
F_86 ( & V_124 -> V_17 , & V_7 -> V_12 ) ;
return V_124 ;
V_88:
F_38 ( V_6 , V_58 ) ;
V_128:
F_12 ( V_124 ) ;
return NULL ;
}
void F_87 ( int V_129 , struct V_130 * V_131 )
{
struct V_35 * V_19 = F_88 ( F_89 ( V_129 ) ) ;
struct V_2 * V_3 = F_51 ( V_19 ) ;
struct V_4 * V_7 ;
struct V_13 * V_124 ;
T_5 V_123 = ( T_2 ) V_131 -> V_132 << 32 | V_131 -> V_133 ;
unsigned long V_134 ;
if ( ! V_3 || ! V_3 -> V_5 )
return;
V_7 = V_3 -> V_5 ;
F_90 ( & V_7 -> V_11 , V_134 ) ;
V_124 = F_83 ( V_19 , V_123 , V_3 ) ;
F_91 ( & V_7 -> V_11 , V_134 ) ;
if ( F_35 ( ! V_124 ) ) {
V_131 -> V_132 = ~ 0U ;
V_131 -> V_133 = ~ 0U ;
V_131 -> V_135 = ~ 0U ;
} else {
V_131 -> V_132 = F_92 ( V_124 -> V_58 ) ;
V_131 -> V_133 &= F_84 ( & V_7 -> V_6 ) ;
V_131 -> V_133 += F_93 ( V_124 -> V_58 ) ;
}
}
