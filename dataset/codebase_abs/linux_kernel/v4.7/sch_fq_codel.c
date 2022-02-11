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
static unsigned int F_13 ( struct V_8 * V_9 , unsigned int V_31 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
unsigned int V_32 = 0 , V_33 = 0 , V_34 , V_35 ;
struct V_26 * V_27 ;
unsigned int V_36 ;
unsigned int V_37 = 0 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_7 ; V_34 ++ ) {
if ( V_2 -> V_38 [ V_34 ] > V_32 ) {
V_32 = V_2 -> V_38 [ V_34 ] ;
V_33 = V_34 ;
}
}
V_36 = V_32 >> 1 ;
V_27 = & V_2 -> V_39 [ V_33 ] ;
V_35 = 0 ;
V_34 = 0 ;
do {
V_4 = F_11 ( V_27 ) ;
V_35 += F_14 ( V_4 ) ;
V_37 += V_4 -> V_40 ;
F_15 ( V_4 ) ;
} while ( ++ V_34 < V_31 && V_35 < V_36 );
V_27 -> V_41 += V_34 ;
V_2 -> V_38 [ V_33 ] -= V_35 ;
V_2 -> V_42 -= V_37 ;
V_9 -> V_43 . V_44 += V_34 ;
V_9 -> V_43 . V_45 -= V_35 ;
V_9 -> V_2 . V_46 -= V_34 ;
return V_33 ;
}
static unsigned int F_16 ( struct V_8 * V_9 )
{
unsigned int V_47 ;
V_47 = V_9 -> V_43 . V_45 ;
F_13 ( V_9 , 1U ) ;
return V_47 - V_9 -> V_43 . V_45 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_33 , V_47 , V_48 ;
struct V_26 * V_27 ;
int V_49 ( V_50 ) ;
unsigned int V_51 ;
bool V_52 ;
V_33 = F_4 ( V_4 , V_9 , & V_50 ) ;
if ( V_33 == 0 ) {
if ( V_50 & V_20 )
F_18 ( V_9 ) ;
F_15 ( V_4 ) ;
return V_50 ;
}
V_33 -- ;
F_19 ( V_4 ) ;
V_27 = & V_2 -> V_39 [ V_33 ] ;
F_12 ( V_27 , V_4 ) ;
V_2 -> V_38 [ V_33 ] += F_14 ( V_4 ) ;
F_20 ( V_9 , V_4 ) ;
if ( F_21 ( & V_27 -> V_53 ) ) {
F_22 ( & V_27 -> V_53 , & V_2 -> V_54 ) ;
V_2 -> V_55 ++ ;
V_27 -> V_56 = V_2 -> V_57 ;
V_27 -> V_41 = 0 ;
}
V_2 -> V_42 += V_4 -> V_40 ;
V_52 = V_2 -> V_42 > V_2 -> V_58 ;
if ( ++ V_9 -> V_2 . V_46 <= V_9 -> V_59 && ! V_52 )
return V_19 ;
V_47 = V_9 -> V_43 . V_45 ;
V_48 = V_9 -> V_2 . V_46 ;
V_51 = F_14 ( V_4 ) ;
V_50 = F_13 ( V_9 , V_2 -> V_60 ) ;
V_48 -= V_9 -> V_2 . V_46 ;
V_47 -= V_9 -> V_43 . V_45 ;
V_2 -> V_61 += V_48 ;
if ( V_52 )
V_2 -> V_62 += V_48 ;
if ( V_50 == V_33 ) {
F_23 ( V_9 , V_48 - 1 ,
V_47 - V_51 ) ;
return V_63 ;
}
F_23 ( V_9 , V_48 , V_47 ) ;
return V_19 ;
}
static struct V_3 * F_24 ( struct V_64 * V_65 , void * V_66 )
{
struct V_8 * V_9 = V_66 ;
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_26 * V_27 ;
struct V_3 * V_4 = NULL ;
V_27 = F_25 ( V_65 , struct V_26 , V_67 ) ;
if ( V_27 -> V_28 ) {
V_4 = F_11 ( V_27 ) ;
V_2 -> V_38 [ V_27 - V_2 -> V_39 ] -= F_14 ( V_4 ) ;
V_2 -> V_42 -= V_4 -> V_40 ;
V_9 -> V_2 . V_46 -- ;
V_9 -> V_43 . V_45 -= F_14 ( V_4 ) ;
}
return V_4 ;
}
static void F_26 ( struct V_3 * V_4 , void * V_66 )
{
struct V_8 * V_9 = V_66 ;
F_27 ( V_4 , V_9 ) ;
}
static struct V_3 * F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
struct V_26 * V_27 ;
struct V_68 * V_28 ;
T_1 V_69 , V_70 ;
unsigned int V_47 ;
V_71:
V_28 = & V_2 -> V_54 ;
if ( F_21 ( V_28 ) ) {
V_28 = & V_2 -> V_72 ;
if ( F_21 ( V_28 ) )
return NULL ;
}
V_27 = F_29 ( V_28 , struct V_26 , V_53 ) ;
if ( V_27 -> V_56 <= 0 ) {
V_27 -> V_56 += V_2 -> V_57 ;
F_30 ( & V_27 -> V_53 , & V_2 -> V_72 ) ;
goto V_71;
}
V_69 = V_2 -> V_73 . V_74 ;
V_70 = V_2 -> V_73 . V_75 ;
V_47 = V_9 -> V_43 . V_45 ;
V_4 = F_31 ( V_9 , & V_9 -> V_43 . V_45 , & V_2 -> V_76 ,
& V_27 -> V_67 , & V_2 -> V_73 , F_14 ,
V_77 , F_26 , F_24 ) ;
V_27 -> V_41 += V_2 -> V_73 . V_74 - V_69 ;
V_27 -> V_41 += V_2 -> V_73 . V_75 - V_70 ;
if ( ! V_4 ) {
if ( ( V_28 == & V_2 -> V_54 ) && ! F_21 ( & V_2 -> V_72 ) )
F_30 ( & V_27 -> V_53 , & V_2 -> V_72 ) ;
else
F_32 ( & V_27 -> V_53 ) ;
goto V_71;
}
F_33 ( V_9 , V_4 ) ;
V_27 -> V_56 -= F_14 ( V_4 ) ;
if ( V_2 -> V_73 . V_74 && V_9 -> V_2 . V_46 ) {
F_23 ( V_9 , V_2 -> V_73 . V_74 ,
V_2 -> V_73 . V_78 ) ;
V_2 -> V_73 . V_74 = 0 ;
V_2 -> V_73 . V_78 = 0 ;
}
return V_4 ;
}
static void F_34 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_34 ;
F_35 ( & V_2 -> V_54 ) ;
F_35 ( & V_2 -> V_72 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_7 ; V_34 ++ ) {
struct V_26 * V_27 = V_2 -> V_39 + V_34 ;
while ( V_27 -> V_28 ) {
struct V_3 * V_4 = F_11 ( V_27 ) ;
F_36 ( V_9 , V_4 ) ;
F_15 ( V_4 ) ;
}
F_35 ( & V_27 -> V_53 ) ;
F_37 ( & V_27 -> V_67 ) ;
}
memset ( V_2 -> V_38 , 0 , V_2 -> V_7 * sizeof( T_1 ) ) ;
V_9 -> V_2 . V_46 = 0 ;
V_2 -> V_42 = 0 ;
}
static int F_38 ( struct V_8 * V_9 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_79 * V_81 [ V_82 + 1 ] ;
int V_83 ;
if ( ! V_80 )
return - V_84 ;
V_83 = F_39 ( V_81 , V_82 , V_80 , V_85 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_81 [ V_86 ] ) {
if ( V_2 -> V_39 )
return - V_84 ;
V_2 -> V_7 = F_40 ( V_81 [ V_86 ] ) ;
if ( ! V_2 -> V_7 ||
V_2 -> V_7 > 65536 )
return - V_84 ;
}
F_41 ( V_9 ) ;
if ( V_81 [ V_87 ] ) {
T_2 V_88 = F_40 ( V_81 [ V_87 ] ) ;
V_2 -> V_76 . V_88 = ( V_88 * V_89 ) >> V_90 ;
}
if ( V_81 [ V_91 ] ) {
T_2 V_92 = F_40 ( V_81 [ V_91 ] ) ;
V_2 -> V_76 . V_93 = ( V_92 * V_89 ) >> V_90 ;
}
if ( V_81 [ V_94 ] ) {
T_2 V_95 = F_40 ( V_81 [ V_94 ] ) ;
V_2 -> V_76 . V_95 = ( V_95 * V_89 ) >> V_90 ;
}
if ( V_81 [ V_96 ] )
V_9 -> V_59 = F_40 ( V_81 [ V_96 ] ) ;
if ( V_81 [ V_97 ] )
V_2 -> V_76 . V_98 = ! ! F_40 ( V_81 [ V_97 ] ) ;
if ( V_81 [ V_99 ] )
V_2 -> V_57 = F_42 ( 256U , F_40 ( V_81 [ V_99 ] ) ) ;
if ( V_81 [ V_100 ] )
V_2 -> V_60 = F_43 ( 1U , F_40 ( V_81 [ V_100 ] ) ) ;
if ( V_81 [ V_101 ] )
V_2 -> V_58 = F_43 ( 1U << 31 , F_40 ( V_81 [ V_101 ] ) ) ;
while ( V_9 -> V_2 . V_46 > V_9 -> V_59 ||
V_2 -> V_42 > V_2 -> V_58 ) {
struct V_3 * V_4 = F_28 ( V_9 ) ;
V_2 -> V_73 . V_78 += F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
V_2 -> V_73 . V_74 ++ ;
}
F_23 ( V_9 , V_2 -> V_73 . V_74 , V_2 -> V_73 . V_78 ) ;
V_2 -> V_73 . V_74 = 0 ;
V_2 -> V_73 . V_78 = 0 ;
F_44 ( V_9 ) ;
return 0 ;
}
static void * F_45 ( T_3 V_102 )
{
void * V_103 = F_46 ( V_102 , V_104 | V_105 ) ;
if ( ! V_103 )
V_103 = F_47 ( V_102 ) ;
return V_103 ;
}
static void F_48 ( void * V_106 )
{
F_49 ( V_106 ) ;
}
static void F_50 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_51 ( & V_2 -> V_18 ) ;
F_48 ( V_2 -> V_38 ) ;
F_48 ( V_2 -> V_39 ) ;
}
static int F_52 ( struct V_8 * V_9 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_34 ;
V_9 -> V_59 = 10 * 1024 ;
V_2 -> V_7 = 1024 ;
V_2 -> V_58 = 32 << 20 ;
V_2 -> V_60 = 64 ;
V_2 -> V_57 = F_53 ( F_54 ( V_9 ) ) ;
V_2 -> V_6 = F_55 () ;
F_35 ( & V_2 -> V_54 ) ;
F_35 ( & V_2 -> V_72 ) ;
F_56 ( & V_2 -> V_76 ) ;
F_57 ( & V_2 -> V_73 ) ;
V_2 -> V_76 . V_98 = true ;
V_2 -> V_76 . V_107 = F_53 ( F_54 ( V_9 ) ) ;
if ( V_80 ) {
int V_83 = F_38 ( V_9 , V_80 ) ;
if ( V_83 )
return V_83 ;
}
if ( ! V_2 -> V_39 ) {
V_2 -> V_39 = F_45 ( V_2 -> V_7 *
sizeof( struct V_26 ) ) ;
if ( ! V_2 -> V_39 )
return - V_108 ;
V_2 -> V_38 = F_45 ( V_2 -> V_7 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_38 ) {
F_48 ( V_2 -> V_39 ) ;
return - V_108 ;
}
for ( V_34 = 0 ; V_34 < V_2 -> V_7 ; V_34 ++ ) {
struct V_26 * V_27 = V_2 -> V_39 + V_34 ;
F_35 ( & V_27 -> V_53 ) ;
F_37 ( & V_27 -> V_67 ) ;
}
}
if ( V_9 -> V_59 >= 1 )
V_9 -> V_109 |= V_110 ;
else
V_9 -> V_109 &= ~ V_110 ;
return 0 ;
}
static int F_58 ( struct V_8 * V_9 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_79 * V_111 ;
V_111 = F_59 ( V_4 , V_112 ) ;
if ( V_111 == NULL )
goto V_113;
if ( F_60 ( V_4 , V_87 ,
F_61 ( V_2 -> V_76 . V_88 ) ) ||
F_60 ( V_4 , V_96 ,
V_9 -> V_59 ) ||
F_60 ( V_4 , V_94 ,
F_61 ( V_2 -> V_76 . V_95 ) ) ||
F_60 ( V_4 , V_97 ,
V_2 -> V_76 . V_98 ) ||
F_60 ( V_4 , V_99 ,
V_2 -> V_57 ) ||
F_60 ( V_4 , V_100 ,
V_2 -> V_60 ) ||
F_60 ( V_4 , V_101 ,
V_2 -> V_58 ) ||
F_60 ( V_4 , V_86 ,
V_2 -> V_7 ) )
goto V_113;
if ( V_2 -> V_76 . V_93 != V_114 &&
F_60 ( V_4 , V_91 ,
F_61 ( V_2 -> V_76 . V_93 ) ) )
goto V_113;
return F_62 ( V_4 , V_111 ) ;
V_113:
return - 1 ;
}
static int F_63 ( struct V_8 * V_9 , struct V_115 * V_116 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_117 V_118 = {
. type = V_119 ,
} ;
struct V_68 * V_120 ;
V_118 . V_121 . V_122 = V_2 -> V_73 . V_122 ;
V_118 . V_121 . V_61 = V_2 -> V_61 ;
V_118 . V_121 . V_75 = V_2 -> V_73 . V_75 ;
V_118 . V_121 . V_55 = V_2 -> V_55 ;
V_118 . V_121 . V_123 = V_2 -> V_73 . V_123 ;
V_118 . V_121 . V_42 = V_2 -> V_42 ;
V_118 . V_121 . V_62 = V_2 -> V_62 ;
F_64 (pos, &q->new_flows)
V_118 . V_121 . V_124 ++ ;
F_64 (pos, &q->old_flows)
V_118 . V_121 . V_125 ++ ;
return F_65 ( V_116 , & V_118 , sizeof( V_118 ) ) ;
}
static struct V_8 * F_66 ( struct V_8 * V_9 , unsigned long V_126 )
{
return NULL ;
}
static unsigned long F_67 ( struct V_8 * V_9 , T_1 V_25 )
{
return 0 ;
}
static unsigned long F_68 ( struct V_8 * V_9 , unsigned long V_127 ,
T_1 V_25 )
{
V_9 -> V_109 &= ~ V_110 ;
return 0 ;
}
static void F_69 ( struct V_8 * V_2 , unsigned long V_128 )
{
}
static struct V_11 T_4 * * F_70 ( struct V_8 * V_9 ,
unsigned long V_128 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_128 )
return NULL ;
return & V_2 -> V_18 ;
}
static int F_71 ( struct V_8 * V_9 , unsigned long V_128 ,
struct V_3 * V_4 , struct V_129 * V_130 )
{
V_130 -> V_131 |= F_7 ( V_128 ) ;
return 0 ;
}
static int F_72 ( struct V_8 * V_9 , unsigned long V_128 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
T_1 V_33 = V_128 - 1 ;
struct V_132 V_133 = { 0 } ;
struct V_117 V_134 ;
if ( V_33 < V_2 -> V_7 ) {
const struct V_26 * V_27 = & V_2 -> V_39 [ V_33 ] ;
const struct V_3 * V_4 = V_27 -> V_28 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . type = V_135 ;
V_134 . V_136 . V_56 = V_27 -> V_56 ;
V_134 . V_136 . V_137 =
F_61 ( V_27 -> V_67 . V_137 ) ;
V_134 . V_136 . V_138 = V_27 -> V_67 . V_138 ;
V_134 . V_136 . V_139 = V_27 -> V_67 . V_139 ;
V_134 . V_136 . V_140 = V_27 -> V_67 . V_140 ;
if ( V_27 -> V_67 . V_140 ) {
T_5 V_141 = V_27 -> V_67 . V_142 -
F_73 () ;
V_134 . V_136 . V_142 = ( V_141 >= 0 ) ?
F_61 ( V_141 ) :
- F_61 ( - V_141 ) ;
}
while ( V_4 ) {
V_133 . V_46 ++ ;
V_4 = V_4 -> V_29 ;
}
V_133 . V_45 = V_2 -> V_38 [ V_33 ] ;
V_133 . V_44 = V_27 -> V_41 ;
}
if ( F_74 ( V_116 , NULL , & V_133 , V_133 . V_46 ) < 0 )
return - 1 ;
if ( V_33 < V_2 -> V_7 )
return F_65 ( V_116 , & V_134 , sizeof( V_134 ) ) ;
return 0 ;
}
static void F_75 ( struct V_8 * V_9 , struct V_143 * V_126 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_34 ;
if ( V_126 -> V_144 )
return;
for ( V_34 = 0 ; V_34 < V_2 -> V_7 ; V_34 ++ ) {
if ( F_21 ( & V_2 -> V_39 [ V_34 ] . V_53 ) ||
V_126 -> V_138 < V_126 -> V_145 ) {
V_126 -> V_138 ++ ;
continue;
}
if ( V_126 -> V_146 ( V_9 , V_34 + 1 , V_126 ) < 0 ) {
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
