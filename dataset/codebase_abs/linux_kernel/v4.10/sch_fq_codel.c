static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_4 , V_2 -> V_6 ) ;
return F_3 ( V_5 , V_2 -> V_7 ) ;
}
static unsigned int F_4 ( struct V_3 * V_4 , struct V_8 * V_9 ,
int * V_10 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_11 * V_12 ;
struct V_13 V_14 ;
int V_15 ;
if ( F_6 ( V_4 -> V_16 ) == V_9 -> V_17 &&
F_7 ( V_4 -> V_16 ) > 0 &&
F_7 ( V_4 -> V_16 ) <= V_2 -> V_7 )
return F_7 ( V_4 -> V_16 ) ;
V_12 = F_8 ( V_2 -> V_18 ) ;
if ( ! V_12 )
return F_1 ( V_2 , V_4 ) + 1 ;
* V_10 = V_19 | V_20 ;
V_15 = F_9 ( V_4 , V_12 , & V_14 , false ) ;
if ( V_15 >= 0 ) {
#ifdef F_10
switch ( V_15 ) {
case V_21 :
case V_22 :
* V_10 = V_19 | V_23 ;
case V_24 :
return 0 ;
}
#endif
if ( F_7 ( V_14 . V_25 ) <= V_2 -> V_7 )
return F_7 ( V_14 . V_25 ) ;
}
return 0 ;
}
static inline struct V_3 * F_11 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_28 ;
V_27 -> V_28 = V_4 -> V_29 ;
V_4 -> V_29 = NULL ;
return V_4 ;
}
static inline void F_12 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
if ( V_27 -> V_28 == NULL )
V_27 -> V_28 = V_4 ;
else
V_27 -> V_30 -> V_29 = V_4 ;
V_27 -> V_30 = V_4 ;
V_4 -> V_29 = NULL ;
}
static unsigned int F_13 ( struct V_8 * V_9 , unsigned int V_31 ,
struct V_3 * * V_32 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
unsigned int V_33 = 0 , V_34 = 0 , V_35 , V_36 ;
struct V_26 * V_27 ;
unsigned int V_37 ;
unsigned int V_38 = 0 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_7 ; V_35 ++ ) {
if ( V_2 -> V_39 [ V_35 ] > V_33 ) {
V_33 = V_2 -> V_39 [ V_35 ] ;
V_34 = V_35 ;
}
}
V_37 = V_33 >> 1 ;
V_27 = & V_2 -> V_40 [ V_34 ] ;
V_36 = 0 ;
V_35 = 0 ;
do {
V_4 = F_11 ( V_27 ) ;
V_36 += F_14 ( V_4 ) ;
V_38 += F_15 ( V_4 ) -> V_41 ;
F_16 ( V_4 , V_32 ) ;
} while ( ++ V_35 < V_31 && V_36 < V_37 );
V_27 -> V_42 += V_35 ;
V_2 -> V_39 [ V_34 ] -= V_36 ;
V_2 -> V_43 -= V_38 ;
V_9 -> V_44 . V_45 += V_35 ;
V_9 -> V_44 . V_46 -= V_36 ;
V_9 -> V_2 . V_47 -= V_35 ;
return V_34 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_8 * V_9 ,
struct V_3 * * V_32 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_34 , V_48 , V_49 ;
struct V_26 * V_27 ;
int V_50 ( V_51 ) ;
unsigned int V_52 ;
bool V_53 ;
V_34 = F_4 ( V_4 , V_9 , & V_51 ) ;
if ( V_34 == 0 ) {
if ( V_51 & V_20 )
F_18 ( V_9 ) ;
F_16 ( V_4 , V_32 ) ;
return V_51 ;
}
V_34 -- ;
F_19 ( V_4 ) ;
V_27 = & V_2 -> V_40 [ V_34 ] ;
F_12 ( V_27 , V_4 ) ;
V_2 -> V_39 [ V_34 ] += F_14 ( V_4 ) ;
F_20 ( V_9 , V_4 ) ;
if ( F_21 ( & V_27 -> V_54 ) ) {
F_22 ( & V_27 -> V_54 , & V_2 -> V_55 ) ;
V_2 -> V_56 ++ ;
V_27 -> V_57 = V_2 -> V_58 ;
V_27 -> V_42 = 0 ;
}
F_15 ( V_4 ) -> V_41 = V_4 -> V_59 ;
V_2 -> V_43 += F_15 ( V_4 ) -> V_41 ;
V_53 = V_2 -> V_43 > V_2 -> V_60 ;
if ( ++ V_9 -> V_2 . V_47 <= V_9 -> V_61 && ! V_53 )
return V_19 ;
V_48 = V_9 -> V_44 . V_46 ;
V_49 = V_9 -> V_2 . V_47 ;
V_52 = F_14 ( V_4 ) ;
V_51 = F_13 ( V_9 , V_2 -> V_62 , V_32 ) ;
V_49 -= V_9 -> V_2 . V_47 ;
V_48 -= V_9 -> V_44 . V_46 ;
V_2 -> V_63 += V_49 ;
if ( V_53 )
V_2 -> V_64 += V_49 ;
if ( V_51 == V_34 ) {
F_23 ( V_9 , V_49 - 1 ,
V_48 - V_52 ) ;
return V_65 ;
}
F_23 ( V_9 , V_49 , V_48 ) ;
return V_19 ;
}
static struct V_3 * F_24 ( struct V_66 * V_67 , void * V_68 )
{
struct V_8 * V_9 = V_68 ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_26 * V_27 ;
struct V_3 * V_4 = NULL ;
V_27 = F_25 ( V_67 , struct V_26 , V_69 ) ;
if ( V_27 -> V_28 ) {
V_4 = F_11 ( V_27 ) ;
V_2 -> V_39 [ V_27 - V_2 -> V_40 ] -= F_14 ( V_4 ) ;
V_2 -> V_43 -= F_15 ( V_4 ) -> V_41 ;
V_9 -> V_2 . V_47 -- ;
V_9 -> V_44 . V_46 -= F_14 ( V_4 ) ;
}
return V_4 ;
}
static void F_26 ( struct V_3 * V_4 , void * V_68 )
{
struct V_8 * V_9 = V_68 ;
F_27 ( V_4 ) ;
F_18 ( V_9 ) ;
}
static struct V_3 * F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
struct V_26 * V_27 ;
struct V_70 * V_28 ;
T_1 V_71 , V_72 ;
unsigned int V_48 ;
V_73:
V_28 = & V_2 -> V_55 ;
if ( F_21 ( V_28 ) ) {
V_28 = & V_2 -> V_74 ;
if ( F_21 ( V_28 ) )
return NULL ;
}
V_27 = F_29 ( V_28 , struct V_26 , V_54 ) ;
if ( V_27 -> V_57 <= 0 ) {
V_27 -> V_57 += V_2 -> V_58 ;
F_30 ( & V_27 -> V_54 , & V_2 -> V_74 ) ;
goto V_73;
}
V_71 = V_2 -> V_75 . V_76 ;
V_72 = V_2 -> V_75 . V_77 ;
V_48 = V_9 -> V_44 . V_46 ;
V_4 = F_31 ( V_9 , & V_9 -> V_44 . V_46 , & V_2 -> V_78 ,
& V_27 -> V_69 , & V_2 -> V_75 , F_14 ,
V_79 , F_26 , F_24 ) ;
V_27 -> V_42 += V_2 -> V_75 . V_76 - V_71 ;
V_27 -> V_42 += V_2 -> V_75 . V_77 - V_72 ;
if ( ! V_4 ) {
if ( ( V_28 == & V_2 -> V_55 ) && ! F_21 ( & V_2 -> V_74 ) )
F_30 ( & V_27 -> V_54 , & V_2 -> V_74 ) ;
else
F_32 ( & V_27 -> V_54 ) ;
goto V_73;
}
F_33 ( V_9 , V_4 ) ;
V_27 -> V_57 -= F_14 ( V_4 ) ;
if ( V_2 -> V_75 . V_76 && V_9 -> V_2 . V_47 ) {
F_23 ( V_9 , V_2 -> V_75 . V_76 ,
V_2 -> V_75 . V_80 ) ;
V_2 -> V_75 . V_76 = 0 ;
V_2 -> V_75 . V_80 = 0 ;
}
return V_4 ;
}
static void F_34 ( struct V_26 * V_27 )
{
F_35 ( V_27 -> V_28 , V_27 -> V_30 ) ;
V_27 -> V_28 = NULL ;
}
static void F_36 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_35 ;
F_37 ( & V_2 -> V_55 ) ;
F_37 ( & V_2 -> V_74 ) ;
for ( V_35 = 0 ; V_35 < V_2 -> V_7 ; V_35 ++ ) {
struct V_26 * V_27 = V_2 -> V_40 + V_35 ;
F_34 ( V_27 ) ;
F_37 ( & V_27 -> V_54 ) ;
F_38 ( & V_27 -> V_69 ) ;
}
memset ( V_2 -> V_39 , 0 , V_2 -> V_7 * sizeof( T_1 ) ) ;
V_9 -> V_2 . V_47 = 0 ;
V_9 -> V_44 . V_46 = 0 ;
V_2 -> V_43 = 0 ;
}
static int F_39 ( struct V_8 * V_9 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_81 * V_83 [ V_84 + 1 ] ;
int V_85 ;
if ( ! V_82 )
return - V_86 ;
V_85 = F_40 ( V_83 , V_84 , V_82 , V_87 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( V_83 [ V_88 ] ) {
if ( V_2 -> V_40 )
return - V_86 ;
V_2 -> V_7 = F_41 ( V_83 [ V_88 ] ) ;
if ( ! V_2 -> V_7 ||
V_2 -> V_7 > 65536 )
return - V_86 ;
}
F_42 ( V_9 ) ;
if ( V_83 [ V_89 ] ) {
T_2 V_90 = F_41 ( V_83 [ V_89 ] ) ;
V_2 -> V_78 . V_90 = ( V_90 * V_91 ) >> V_92 ;
}
if ( V_83 [ V_93 ] ) {
T_2 V_94 = F_41 ( V_83 [ V_93 ] ) ;
V_2 -> V_78 . V_95 = ( V_94 * V_91 ) >> V_92 ;
}
if ( V_83 [ V_96 ] ) {
T_2 V_97 = F_41 ( V_83 [ V_96 ] ) ;
V_2 -> V_78 . V_97 = ( V_97 * V_91 ) >> V_92 ;
}
if ( V_83 [ V_98 ] )
V_9 -> V_61 = F_41 ( V_83 [ V_98 ] ) ;
if ( V_83 [ V_99 ] )
V_2 -> V_78 . V_100 = ! ! F_41 ( V_83 [ V_99 ] ) ;
if ( V_83 [ V_101 ] )
V_2 -> V_58 = F_43 ( 256U , F_41 ( V_83 [ V_101 ] ) ) ;
if ( V_83 [ V_102 ] )
V_2 -> V_62 = F_44 ( 1U , F_41 ( V_83 [ V_102 ] ) ) ;
if ( V_83 [ V_103 ] )
V_2 -> V_60 = F_44 ( 1U << 31 , F_41 ( V_83 [ V_103 ] ) ) ;
while ( V_9 -> V_2 . V_47 > V_9 -> V_61 ||
V_2 -> V_43 > V_2 -> V_60 ) {
struct V_3 * V_4 = F_28 ( V_9 ) ;
V_2 -> V_75 . V_80 += F_14 ( V_4 ) ;
F_35 ( V_4 , V_4 ) ;
V_2 -> V_75 . V_76 ++ ;
}
F_23 ( V_9 , V_2 -> V_75 . V_76 , V_2 -> V_75 . V_80 ) ;
V_2 -> V_75 . V_76 = 0 ;
V_2 -> V_75 . V_80 = 0 ;
F_45 ( V_9 ) ;
return 0 ;
}
static void * F_46 ( T_3 V_104 )
{
void * V_105 = F_47 ( V_104 , V_106 | V_107 ) ;
if ( ! V_105 )
V_105 = F_48 ( V_104 ) ;
return V_105 ;
}
static void F_49 ( void * V_108 )
{
F_50 ( V_108 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_52 ( & V_2 -> V_18 ) ;
F_49 ( V_2 -> V_39 ) ;
F_49 ( V_2 -> V_40 ) ;
}
static int F_53 ( struct V_8 * V_9 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_35 ;
V_9 -> V_61 = 10 * 1024 ;
V_2 -> V_7 = 1024 ;
V_2 -> V_60 = 32 << 20 ;
V_2 -> V_62 = 64 ;
V_2 -> V_58 = F_54 ( F_55 ( V_9 ) ) ;
V_2 -> V_6 = F_56 () ;
F_37 ( & V_2 -> V_55 ) ;
F_37 ( & V_2 -> V_74 ) ;
F_57 ( & V_2 -> V_78 ) ;
F_58 ( & V_2 -> V_75 ) ;
V_2 -> V_78 . V_100 = true ;
V_2 -> V_78 . V_109 = F_54 ( F_55 ( V_9 ) ) ;
if ( V_82 ) {
int V_85 = F_39 ( V_9 , V_82 ) ;
if ( V_85 )
return V_85 ;
}
if ( ! V_2 -> V_40 ) {
V_2 -> V_40 = F_46 ( V_2 -> V_7 *
sizeof( struct V_26 ) ) ;
if ( ! V_2 -> V_40 )
return - V_110 ;
V_2 -> V_39 = F_46 ( V_2 -> V_7 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_39 ) {
F_49 ( V_2 -> V_40 ) ;
return - V_110 ;
}
for ( V_35 = 0 ; V_35 < V_2 -> V_7 ; V_35 ++ ) {
struct V_26 * V_27 = V_2 -> V_40 + V_35 ;
F_37 ( & V_27 -> V_54 ) ;
F_38 ( & V_27 -> V_69 ) ;
}
}
if ( V_9 -> V_61 >= 1 )
V_9 -> V_111 |= V_112 ;
else
V_9 -> V_111 &= ~ V_112 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_81 * V_113 ;
V_113 = F_60 ( V_4 , V_114 ) ;
if ( V_113 == NULL )
goto V_115;
if ( F_61 ( V_4 , V_89 ,
F_62 ( V_2 -> V_78 . V_90 ) ) ||
F_61 ( V_4 , V_98 ,
V_9 -> V_61 ) ||
F_61 ( V_4 , V_96 ,
F_62 ( V_2 -> V_78 . V_97 ) ) ||
F_61 ( V_4 , V_99 ,
V_2 -> V_78 . V_100 ) ||
F_61 ( V_4 , V_101 ,
V_2 -> V_58 ) ||
F_61 ( V_4 , V_102 ,
V_2 -> V_62 ) ||
F_61 ( V_4 , V_103 ,
V_2 -> V_60 ) ||
F_61 ( V_4 , V_88 ,
V_2 -> V_7 ) )
goto V_115;
if ( V_2 -> V_78 . V_95 != V_116 &&
F_61 ( V_4 , V_93 ,
F_62 ( V_2 -> V_78 . V_95 ) ) )
goto V_115;
return F_63 ( V_4 , V_113 ) ;
V_115:
return - 1 ;
}
static int F_64 ( struct V_8 * V_9 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_119 V_120 = {
. type = V_121 ,
} ;
struct V_70 * V_122 ;
V_120 . V_123 . V_124 = V_2 -> V_75 . V_124 ;
V_120 . V_123 . V_63 = V_2 -> V_63 ;
V_120 . V_123 . V_77 = V_2 -> V_75 . V_77 ;
V_120 . V_123 . V_56 = V_2 -> V_56 ;
V_120 . V_123 . V_125 = V_2 -> V_75 . V_125 ;
V_120 . V_123 . V_43 = V_2 -> V_43 ;
V_120 . V_123 . V_64 = V_2 -> V_64 ;
F_42 ( V_9 ) ;
F_65 (pos, &q->new_flows)
V_120 . V_123 . V_126 ++ ;
F_65 (pos, &q->old_flows)
V_120 . V_123 . V_127 ++ ;
F_45 ( V_9 ) ;
return F_66 ( V_118 , & V_120 , sizeof( V_120 ) ) ;
}
static struct V_8 * F_67 ( struct V_8 * V_9 , unsigned long V_128 )
{
return NULL ;
}
static unsigned long F_68 ( struct V_8 * V_9 , T_1 V_25 )
{
return 0 ;
}
static unsigned long F_69 ( struct V_8 * V_9 , unsigned long V_129 ,
T_1 V_25 )
{
V_9 -> V_111 &= ~ V_112 ;
return 0 ;
}
static void F_70 ( struct V_8 * V_2 , unsigned long V_130 )
{
}
static struct V_11 T_4 * * F_71 ( struct V_8 * V_9 ,
unsigned long V_130 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_130 )
return NULL ;
return & V_2 -> V_18 ;
}
static int F_72 ( struct V_8 * V_9 , unsigned long V_130 ,
struct V_3 * V_4 , struct V_131 * V_132 )
{
V_132 -> V_133 |= F_7 ( V_130 ) ;
return 0 ;
}
static int F_73 ( struct V_8 * V_9 , unsigned long V_130 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
T_1 V_34 = V_130 - 1 ;
struct V_134 V_135 = { 0 } ;
struct V_119 V_136 ;
if ( V_34 < V_2 -> V_7 ) {
const struct V_26 * V_27 = & V_2 -> V_40 [ V_34 ] ;
const struct V_3 * V_4 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . type = V_137 ;
V_136 . V_138 . V_57 = V_27 -> V_57 ;
V_136 . V_138 . V_139 =
F_62 ( V_27 -> V_69 . V_139 ) ;
V_136 . V_138 . V_140 = V_27 -> V_69 . V_140 ;
V_136 . V_138 . V_141 = V_27 -> V_69 . V_141 ;
V_136 . V_138 . V_142 = V_27 -> V_69 . V_142 ;
if ( V_27 -> V_69 . V_142 ) {
T_5 V_143 = V_27 -> V_69 . V_144 -
F_74 () ;
V_136 . V_138 . V_144 = ( V_143 >= 0 ) ?
F_62 ( V_143 ) :
- F_62 ( - V_143 ) ;
}
if ( V_27 -> V_28 ) {
F_42 ( V_9 ) ;
V_4 = V_27 -> V_28 ;
while ( V_4 ) {
V_135 . V_47 ++ ;
V_4 = V_4 -> V_29 ;
}
F_45 ( V_9 ) ;
}
V_135 . V_46 = V_2 -> V_39 [ V_34 ] ;
V_135 . V_45 = V_27 -> V_42 ;
}
if ( F_75 ( V_118 , NULL , & V_135 , V_135 . V_47 ) < 0 )
return - 1 ;
if ( V_34 < V_2 -> V_7 )
return F_66 ( V_118 , & V_136 , sizeof( V_136 ) ) ;
return 0 ;
}
static void F_76 ( struct V_8 * V_9 , struct V_145 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_35 ;
if ( V_128 -> V_146 )
return;
for ( V_35 = 0 ; V_35 < V_2 -> V_7 ; V_35 ++ ) {
if ( F_21 ( & V_2 -> V_40 [ V_35 ] . V_54 ) ||
V_128 -> V_140 < V_128 -> V_147 ) {
V_128 -> V_140 ++ ;
continue;
}
if ( V_128 -> V_148 ( V_9 , V_35 + 1 , V_128 ) < 0 ) {
V_128 -> V_146 = 1 ;
break;
}
V_128 -> V_140 ++ ;
}
}
static int T_6 F_77 ( void )
{
return F_78 ( & V_149 ) ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_149 ) ;
}
