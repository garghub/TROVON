static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return F_2 ( F_3 ( V_4 ) , V_2 -> V_5 ) ;
}
static unsigned int F_4 ( struct V_3 * V_4 , struct V_6 * V_7 ,
int * V_8 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
int V_13 ;
if ( F_6 ( V_4 -> V_14 ) == V_7 -> V_15 &&
F_7 ( V_4 -> V_14 ) > 0 &&
F_7 ( V_4 -> V_14 ) <= V_2 -> V_5 )
return F_7 ( V_4 -> V_14 ) ;
V_10 = F_8 ( V_2 -> V_16 ) ;
if ( ! V_10 )
return F_1 ( V_2 , V_4 ) + 1 ;
* V_8 = V_17 | V_18 ;
V_13 = F_9 ( V_4 , V_10 , & V_12 , false ) ;
if ( V_13 >= 0 ) {
#ifdef F_10
switch ( V_13 ) {
case V_19 :
case V_20 :
* V_8 = V_17 | V_21 ;
case V_22 :
return 0 ;
}
#endif
if ( F_7 ( V_12 . V_23 ) <= V_2 -> V_5 )
return F_7 ( V_12 . V_23 ) ;
}
return 0 ;
}
static inline struct V_3 * F_11 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = V_25 -> V_26 ;
V_25 -> V_26 = V_4 -> V_27 ;
V_4 -> V_27 = NULL ;
return V_4 ;
}
static inline void F_12 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
if ( V_25 -> V_26 == NULL )
V_25 -> V_26 = V_4 ;
else
V_25 -> V_28 -> V_27 = V_4 ;
V_25 -> V_28 = V_4 ;
V_4 -> V_27 = NULL ;
}
static unsigned int F_13 ( struct V_6 * V_7 , unsigned int V_29 ,
struct V_3 * * V_30 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 ;
unsigned int V_31 = 0 , V_32 = 0 , V_33 , V_34 ;
struct V_24 * V_25 ;
unsigned int V_35 ;
unsigned int V_36 = 0 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_5 ; V_33 ++ ) {
if ( V_2 -> V_37 [ V_33 ] > V_31 ) {
V_31 = V_2 -> V_37 [ V_33 ] ;
V_32 = V_33 ;
}
}
V_35 = V_31 >> 1 ;
V_25 = & V_2 -> V_38 [ V_32 ] ;
V_34 = 0 ;
V_33 = 0 ;
do {
V_4 = F_11 ( V_25 ) ;
V_34 += F_14 ( V_4 ) ;
V_36 += F_15 ( V_4 ) -> V_39 ;
F_16 ( V_4 , V_30 ) ;
} while ( ++ V_33 < V_29 && V_34 < V_35 );
V_25 -> V_40 += V_33 ;
V_2 -> V_37 [ V_32 ] -= V_34 ;
V_2 -> V_41 -= V_36 ;
V_7 -> V_42 . V_43 += V_33 ;
V_7 -> V_42 . V_44 -= V_34 ;
V_7 -> V_2 . V_45 -= V_33 ;
return V_32 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_3 * * V_30 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_32 , V_46 , V_47 ;
struct V_24 * V_25 ;
int V_48 ( V_49 ) ;
unsigned int V_50 ;
bool V_51 ;
V_32 = F_4 ( V_4 , V_7 , & V_49 ) ;
if ( V_32 == 0 ) {
if ( V_49 & V_18 )
F_18 ( V_7 ) ;
F_16 ( V_4 , V_30 ) ;
return V_49 ;
}
V_32 -- ;
F_19 ( V_4 ) ;
V_25 = & V_2 -> V_38 [ V_32 ] ;
F_12 ( V_25 , V_4 ) ;
V_2 -> V_37 [ V_32 ] += F_14 ( V_4 ) ;
F_20 ( V_7 , V_4 ) ;
if ( F_21 ( & V_25 -> V_52 ) ) {
F_22 ( & V_25 -> V_52 , & V_2 -> V_53 ) ;
V_2 -> V_54 ++ ;
V_25 -> V_55 = V_2 -> V_56 ;
V_25 -> V_40 = 0 ;
}
F_15 ( V_4 ) -> V_39 = V_4 -> V_57 ;
V_2 -> V_41 += F_15 ( V_4 ) -> V_39 ;
V_51 = V_2 -> V_41 > V_2 -> V_58 ;
if ( ++ V_7 -> V_2 . V_45 <= V_7 -> V_59 && ! V_51 )
return V_17 ;
V_46 = V_7 -> V_42 . V_44 ;
V_47 = V_7 -> V_2 . V_45 ;
V_50 = F_14 ( V_4 ) ;
V_49 = F_13 ( V_7 , V_2 -> V_60 , V_30 ) ;
V_47 -= V_7 -> V_2 . V_45 ;
V_46 -= V_7 -> V_42 . V_44 ;
V_2 -> V_61 += V_47 ;
if ( V_51 )
V_2 -> V_62 += V_47 ;
if ( V_49 == V_32 ) {
F_23 ( V_7 , V_47 - 1 ,
V_46 - V_50 ) ;
return V_63 ;
}
F_23 ( V_7 , V_47 , V_46 ) ;
return V_17 ;
}
static struct V_3 * F_24 ( struct V_64 * V_65 , void * V_66 )
{
struct V_6 * V_7 = V_66 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_24 * V_25 ;
struct V_3 * V_4 = NULL ;
V_25 = F_25 ( V_65 , struct V_24 , V_67 ) ;
if ( V_25 -> V_26 ) {
V_4 = F_11 ( V_25 ) ;
V_2 -> V_37 [ V_25 - V_2 -> V_38 ] -= F_14 ( V_4 ) ;
V_2 -> V_41 -= F_15 ( V_4 ) -> V_39 ;
V_7 -> V_2 . V_45 -- ;
V_7 -> V_42 . V_44 -= F_14 ( V_4 ) ;
}
return V_4 ;
}
static void F_26 ( struct V_3 * V_4 , void * V_66 )
{
struct V_6 * V_7 = V_66 ;
F_27 ( V_4 ) ;
F_18 ( V_7 ) ;
}
static struct V_3 * F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 ;
struct V_24 * V_25 ;
struct V_68 * V_26 ;
T_1 V_69 , V_70 ;
unsigned int V_46 ;
V_71:
V_26 = & V_2 -> V_53 ;
if ( F_21 ( V_26 ) ) {
V_26 = & V_2 -> V_72 ;
if ( F_21 ( V_26 ) )
return NULL ;
}
V_25 = F_29 ( V_26 , struct V_24 , V_52 ) ;
if ( V_25 -> V_55 <= 0 ) {
V_25 -> V_55 += V_2 -> V_56 ;
F_30 ( & V_25 -> V_52 , & V_2 -> V_72 ) ;
goto V_71;
}
V_69 = V_2 -> V_73 . V_74 ;
V_70 = V_2 -> V_73 . V_75 ;
V_46 = V_7 -> V_42 . V_44 ;
V_4 = F_31 ( V_7 , & V_7 -> V_42 . V_44 , & V_2 -> V_76 ,
& V_25 -> V_67 , & V_2 -> V_73 , F_14 ,
V_77 , F_26 , F_24 ) ;
V_25 -> V_40 += V_2 -> V_73 . V_74 - V_69 ;
V_25 -> V_40 += V_2 -> V_73 . V_75 - V_70 ;
if ( ! V_4 ) {
if ( ( V_26 == & V_2 -> V_53 ) && ! F_21 ( & V_2 -> V_72 ) )
F_30 ( & V_25 -> V_52 , & V_2 -> V_72 ) ;
else
F_32 ( & V_25 -> V_52 ) ;
goto V_71;
}
F_33 ( V_7 , V_4 ) ;
V_25 -> V_55 -= F_14 ( V_4 ) ;
if ( V_2 -> V_73 . V_74 && V_7 -> V_2 . V_45 ) {
F_23 ( V_7 , V_2 -> V_73 . V_74 ,
V_2 -> V_73 . V_78 ) ;
V_2 -> V_73 . V_74 = 0 ;
V_2 -> V_73 . V_78 = 0 ;
}
return V_4 ;
}
static void F_34 ( struct V_24 * V_25 )
{
F_35 ( V_25 -> V_26 , V_25 -> V_28 ) ;
V_25 -> V_26 = NULL ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_33 ;
F_37 ( & V_2 -> V_53 ) ;
F_37 ( & V_2 -> V_72 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_5 ; V_33 ++ ) {
struct V_24 * V_25 = V_2 -> V_38 + V_33 ;
F_34 ( V_25 ) ;
F_37 ( & V_25 -> V_52 ) ;
F_38 ( & V_25 -> V_67 ) ;
}
memset ( V_2 -> V_37 , 0 , V_2 -> V_5 * sizeof( T_1 ) ) ;
V_7 -> V_2 . V_45 = 0 ;
V_7 -> V_42 . V_44 = 0 ;
V_2 -> V_41 = 0 ;
}
static int F_39 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_79 * V_81 [ V_82 + 1 ] ;
int V_83 ;
if ( ! V_80 )
return - V_84 ;
V_83 = F_40 ( V_81 , V_82 , V_80 , V_85 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_81 [ V_86 ] ) {
if ( V_2 -> V_38 )
return - V_84 ;
V_2 -> V_5 = F_41 ( V_81 [ V_86 ] ) ;
if ( ! V_2 -> V_5 ||
V_2 -> V_5 > 65536 )
return - V_84 ;
}
F_42 ( V_7 ) ;
if ( V_81 [ V_87 ] ) {
T_2 V_88 = F_41 ( V_81 [ V_87 ] ) ;
V_2 -> V_76 . V_88 = ( V_88 * V_89 ) >> V_90 ;
}
if ( V_81 [ V_91 ] ) {
T_2 V_92 = F_41 ( V_81 [ V_91 ] ) ;
V_2 -> V_76 . V_93 = ( V_92 * V_89 ) >> V_90 ;
}
if ( V_81 [ V_94 ] ) {
T_2 V_95 = F_41 ( V_81 [ V_94 ] ) ;
V_2 -> V_76 . V_95 = ( V_95 * V_89 ) >> V_90 ;
}
if ( V_81 [ V_96 ] )
V_7 -> V_59 = F_41 ( V_81 [ V_96 ] ) ;
if ( V_81 [ V_97 ] )
V_2 -> V_76 . V_98 = ! ! F_41 ( V_81 [ V_97 ] ) ;
if ( V_81 [ V_99 ] )
V_2 -> V_56 = F_43 ( 256U , F_41 ( V_81 [ V_99 ] ) ) ;
if ( V_81 [ V_100 ] )
V_2 -> V_60 = F_44 ( 1U , F_41 ( V_81 [ V_100 ] ) ) ;
if ( V_81 [ V_101 ] )
V_2 -> V_58 = F_44 ( 1U << 31 , F_41 ( V_81 [ V_101 ] ) ) ;
while ( V_7 -> V_2 . V_45 > V_7 -> V_59 ||
V_2 -> V_41 > V_2 -> V_58 ) {
struct V_3 * V_4 = F_28 ( V_7 ) ;
V_2 -> V_73 . V_78 += F_14 ( V_4 ) ;
F_35 ( V_4 , V_4 ) ;
V_2 -> V_73 . V_74 ++ ;
}
F_23 ( V_7 , V_2 -> V_73 . V_74 , V_2 -> V_73 . V_78 ) ;
V_2 -> V_73 . V_74 = 0 ;
V_2 -> V_73 . V_78 = 0 ;
F_45 ( V_7 ) ;
return 0 ;
}
static void * F_46 ( T_3 V_102 )
{
void * V_103 = F_47 ( V_102 , V_104 | V_105 ) ;
if ( ! V_103 )
V_103 = F_48 ( V_102 ) ;
return V_103 ;
}
static void F_49 ( void * V_106 )
{
F_50 ( V_106 ) ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_52 ( & V_2 -> V_16 ) ;
F_49 ( V_2 -> V_37 ) ;
F_49 ( V_2 -> V_38 ) ;
}
static int F_53 ( struct V_6 * V_7 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_33 ;
V_7 -> V_59 = 10 * 1024 ;
V_2 -> V_5 = 1024 ;
V_2 -> V_58 = 32 << 20 ;
V_2 -> V_60 = 64 ;
V_2 -> V_56 = F_54 ( F_55 ( V_7 ) ) ;
F_37 ( & V_2 -> V_53 ) ;
F_37 ( & V_2 -> V_72 ) ;
F_56 ( & V_2 -> V_76 ) ;
F_57 ( & V_2 -> V_73 ) ;
V_2 -> V_76 . V_98 = true ;
V_2 -> V_76 . V_107 = F_54 ( F_55 ( V_7 ) ) ;
if ( V_80 ) {
int V_83 = F_39 ( V_7 , V_80 ) ;
if ( V_83 )
return V_83 ;
}
if ( ! V_2 -> V_38 ) {
V_2 -> V_38 = F_46 ( V_2 -> V_5 *
sizeof( struct V_24 ) ) ;
if ( ! V_2 -> V_38 )
return - V_108 ;
V_2 -> V_37 = F_46 ( V_2 -> V_5 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_37 ) {
F_49 ( V_2 -> V_38 ) ;
return - V_108 ;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_5 ; V_33 ++ ) {
struct V_24 * V_25 = V_2 -> V_38 + V_33 ;
F_37 ( & V_25 -> V_52 ) ;
F_38 ( & V_25 -> V_67 ) ;
}
}
if ( V_7 -> V_59 >= 1 )
V_7 -> V_109 |= V_110 ;
else
V_7 -> V_109 &= ~ V_110 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_79 * V_111 ;
V_111 = F_59 ( V_4 , V_112 ) ;
if ( V_111 == NULL )
goto V_113;
if ( F_60 ( V_4 , V_87 ,
F_61 ( V_2 -> V_76 . V_88 ) ) ||
F_60 ( V_4 , V_96 ,
V_7 -> V_59 ) ||
F_60 ( V_4 , V_94 ,
F_61 ( V_2 -> V_76 . V_95 ) ) ||
F_60 ( V_4 , V_97 ,
V_2 -> V_76 . V_98 ) ||
F_60 ( V_4 , V_99 ,
V_2 -> V_56 ) ||
F_60 ( V_4 , V_100 ,
V_2 -> V_60 ) ||
F_60 ( V_4 , V_101 ,
V_2 -> V_58 ) ||
F_60 ( V_4 , V_86 ,
V_2 -> V_5 ) )
goto V_113;
if ( V_2 -> V_76 . V_93 != V_114 &&
F_60 ( V_4 , V_91 ,
F_61 ( V_2 -> V_76 . V_93 ) ) )
goto V_113;
return F_62 ( V_4 , V_111 ) ;
V_113:
return - 1 ;
}
static int F_63 ( struct V_6 * V_7 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_117 V_118 = {
. type = V_119 ,
} ;
struct V_68 * V_120 ;
V_118 . V_121 . V_122 = V_2 -> V_73 . V_122 ;
V_118 . V_121 . V_61 = V_2 -> V_61 ;
V_118 . V_121 . V_75 = V_2 -> V_73 . V_75 ;
V_118 . V_121 . V_54 = V_2 -> V_54 ;
V_118 . V_121 . V_123 = V_2 -> V_73 . V_123 ;
V_118 . V_121 . V_41 = V_2 -> V_41 ;
V_118 . V_121 . V_62 = V_2 -> V_62 ;
F_42 ( V_7 ) ;
F_64 (pos, &q->new_flows)
V_118 . V_121 . V_124 ++ ;
F_64 (pos, &q->old_flows)
V_118 . V_121 . V_125 ++ ;
F_45 ( V_7 ) ;
return F_65 ( V_116 , & V_118 , sizeof( V_118 ) ) ;
}
static struct V_6 * F_66 ( struct V_6 * V_7 , unsigned long V_126 )
{
return NULL ;
}
static unsigned long F_67 ( struct V_6 * V_7 , T_1 V_23 )
{
return 0 ;
}
static unsigned long F_68 ( struct V_6 * V_7 , unsigned long V_127 ,
T_1 V_23 )
{
V_7 -> V_109 &= ~ V_110 ;
return 0 ;
}
static void F_69 ( struct V_6 * V_2 , unsigned long V_128 )
{
}
static struct V_9 T_4 * * F_70 ( struct V_6 * V_7 ,
unsigned long V_128 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
if ( V_128 )
return NULL ;
return & V_2 -> V_16 ;
}
static int F_71 ( struct V_6 * V_7 , unsigned long V_128 ,
struct V_3 * V_4 , struct V_129 * V_130 )
{
V_130 -> V_131 |= F_7 ( V_128 ) ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 , unsigned long V_128 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_32 = V_128 - 1 ;
struct V_132 V_133 = { 0 } ;
struct V_117 V_134 ;
if ( V_32 < V_2 -> V_5 ) {
const struct V_24 * V_25 = & V_2 -> V_38 [ V_32 ] ;
const struct V_3 * V_4 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . type = V_135 ;
V_134 . V_136 . V_55 = V_25 -> V_55 ;
V_134 . V_136 . V_137 =
F_61 ( V_25 -> V_67 . V_137 ) ;
V_134 . V_136 . V_138 = V_25 -> V_67 . V_138 ;
V_134 . V_136 . V_139 = V_25 -> V_67 . V_139 ;
V_134 . V_136 . V_140 = V_25 -> V_67 . V_140 ;
if ( V_25 -> V_67 . V_140 ) {
T_5 V_141 = V_25 -> V_67 . V_142 -
F_73 () ;
V_134 . V_136 . V_142 = ( V_141 >= 0 ) ?
F_61 ( V_141 ) :
- F_61 ( - V_141 ) ;
}
if ( V_25 -> V_26 ) {
F_42 ( V_7 ) ;
V_4 = V_25 -> V_26 ;
while ( V_4 ) {
V_133 . V_45 ++ ;
V_4 = V_4 -> V_27 ;
}
F_45 ( V_7 ) ;
}
V_133 . V_44 = V_2 -> V_37 [ V_32 ] ;
V_133 . V_43 = V_25 -> V_40 ;
}
if ( F_74 ( V_116 , NULL , & V_133 , V_133 . V_45 ) < 0 )
return - 1 ;
if ( V_32 < V_2 -> V_5 )
return F_65 ( V_116 , & V_134 , sizeof( V_134 ) ) ;
return 0 ;
}
static void F_75 ( struct V_6 * V_7 , struct V_143 * V_126 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_33 ;
if ( V_126 -> V_144 )
return;
for ( V_33 = 0 ; V_33 < V_2 -> V_5 ; V_33 ++ ) {
if ( F_21 ( & V_2 -> V_38 [ V_33 ] . V_52 ) ||
V_126 -> V_138 < V_126 -> V_145 ) {
V_126 -> V_138 ++ ;
continue;
}
if ( V_126 -> V_146 ( V_7 , V_33 + 1 , V_126 ) < 0 ) {
V_126 -> V_144 = 1 ;
break;
}
V_126 -> V_138 ++ ;
}
}
static int T_6 F_76 ( void )
{
return F_77 ( & V_147 ) ;
}
static void T_7 F_78 ( void )
{
F_79 ( & V_147 ) ;
}
