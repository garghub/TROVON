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
case V_21 :
* V_8 = V_17 | V_22 ;
case V_23 :
return 0 ;
}
#endif
if ( F_7 ( V_12 . V_24 ) <= V_2 -> V_5 )
return F_7 ( V_12 . V_24 ) ;
}
return 0 ;
}
static inline struct V_3 * F_11 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = V_26 -> V_27 ;
V_26 -> V_27 = V_4 -> V_28 ;
V_4 -> V_28 = NULL ;
return V_4 ;
}
static inline void F_12 ( struct V_25 * V_26 ,
struct V_3 * V_4 )
{
if ( V_26 -> V_27 == NULL )
V_26 -> V_27 = V_4 ;
else
V_26 -> V_29 -> V_28 = V_4 ;
V_26 -> V_29 = V_4 ;
V_4 -> V_28 = NULL ;
}
static unsigned int F_13 ( struct V_6 * V_7 , unsigned int V_30 ,
struct V_3 * * V_31 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 ;
unsigned int V_32 = 0 , V_33 = 0 , V_34 , V_35 ;
struct V_25 * V_26 ;
unsigned int V_36 ;
unsigned int V_37 = 0 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_5 ; V_34 ++ ) {
if ( V_2 -> V_38 [ V_34 ] > V_32 ) {
V_32 = V_2 -> V_38 [ V_34 ] ;
V_33 = V_34 ;
}
}
V_36 = V_32 >> 1 ;
V_26 = & V_2 -> V_39 [ V_33 ] ;
V_35 = 0 ;
V_34 = 0 ;
do {
V_4 = F_11 ( V_26 ) ;
V_35 += F_14 ( V_4 ) ;
V_37 += F_15 ( V_4 ) -> V_40 ;
F_16 ( V_4 , V_31 ) ;
} while ( ++ V_34 < V_30 && V_35 < V_36 );
V_26 -> V_41 += V_34 ;
V_2 -> V_38 [ V_33 ] -= V_35 ;
V_2 -> V_42 -= V_37 ;
V_7 -> V_43 . V_44 += V_34 ;
V_7 -> V_43 . V_45 -= V_35 ;
V_7 -> V_2 . V_46 -= V_34 ;
return V_33 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_3 * * V_31 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_33 , V_47 , V_48 ;
struct V_25 * V_26 ;
int V_49 ( V_50 ) ;
unsigned int V_51 ;
bool V_52 ;
V_33 = F_4 ( V_4 , V_7 , & V_50 ) ;
if ( V_33 == 0 ) {
if ( V_50 & V_18 )
F_18 ( V_7 ) ;
F_16 ( V_4 , V_31 ) ;
return V_50 ;
}
V_33 -- ;
F_19 ( V_4 ) ;
V_26 = & V_2 -> V_39 [ V_33 ] ;
F_12 ( V_26 , V_4 ) ;
V_2 -> V_38 [ V_33 ] += F_14 ( V_4 ) ;
F_20 ( V_7 , V_4 ) ;
if ( F_21 ( & V_26 -> V_53 ) ) {
F_22 ( & V_26 -> V_53 , & V_2 -> V_54 ) ;
V_2 -> V_55 ++ ;
V_26 -> V_56 = V_2 -> V_57 ;
V_26 -> V_41 = 0 ;
}
F_15 ( V_4 ) -> V_40 = V_4 -> V_58 ;
V_2 -> V_42 += F_15 ( V_4 ) -> V_40 ;
V_52 = V_2 -> V_42 > V_2 -> V_59 ;
if ( ++ V_7 -> V_2 . V_46 <= V_7 -> V_60 && ! V_52 )
return V_17 ;
V_47 = V_7 -> V_43 . V_45 ;
V_48 = V_7 -> V_2 . V_46 ;
V_51 = F_14 ( V_4 ) ;
V_50 = F_13 ( V_7 , V_2 -> V_61 , V_31 ) ;
V_48 -= V_7 -> V_2 . V_46 ;
V_47 -= V_7 -> V_43 . V_45 ;
V_2 -> V_62 += V_48 ;
if ( V_52 )
V_2 -> V_63 += V_48 ;
if ( V_50 == V_33 ) {
F_23 ( V_7 , V_48 - 1 ,
V_47 - V_51 ) ;
return V_64 ;
}
F_23 ( V_7 , V_48 , V_47 ) ;
return V_17 ;
}
static struct V_3 * F_24 ( struct V_65 * V_66 , void * V_67 )
{
struct V_6 * V_7 = V_67 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_25 * V_26 ;
struct V_3 * V_4 = NULL ;
V_26 = F_25 ( V_66 , struct V_25 , V_68 ) ;
if ( V_26 -> V_27 ) {
V_4 = F_11 ( V_26 ) ;
V_2 -> V_38 [ V_26 - V_2 -> V_39 ] -= F_14 ( V_4 ) ;
V_2 -> V_42 -= F_15 ( V_4 ) -> V_40 ;
V_7 -> V_2 . V_46 -- ;
V_7 -> V_43 . V_45 -= F_14 ( V_4 ) ;
}
return V_4 ;
}
static void F_26 ( struct V_3 * V_4 , void * V_67 )
{
struct V_6 * V_7 = V_67 ;
F_27 ( V_4 ) ;
F_18 ( V_7 ) ;
}
static struct V_3 * F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_3 * V_4 ;
struct V_25 * V_26 ;
struct V_69 * V_27 ;
T_1 V_70 , V_71 ;
V_72:
V_27 = & V_2 -> V_54 ;
if ( F_21 ( V_27 ) ) {
V_27 = & V_2 -> V_73 ;
if ( F_21 ( V_27 ) )
return NULL ;
}
V_26 = F_29 ( V_27 , struct V_25 , V_53 ) ;
if ( V_26 -> V_56 <= 0 ) {
V_26 -> V_56 += V_2 -> V_57 ;
F_30 ( & V_26 -> V_53 , & V_2 -> V_73 ) ;
goto V_72;
}
V_70 = V_2 -> V_74 . V_75 ;
V_71 = V_2 -> V_74 . V_76 ;
V_4 = F_31 ( V_7 , & V_7 -> V_43 . V_45 , & V_2 -> V_77 ,
& V_26 -> V_68 , & V_2 -> V_74 , F_14 ,
V_78 , F_26 , F_24 ) ;
V_26 -> V_41 += V_2 -> V_74 . V_75 - V_70 ;
V_26 -> V_41 += V_2 -> V_74 . V_76 - V_71 ;
if ( ! V_4 ) {
if ( ( V_27 == & V_2 -> V_54 ) && ! F_21 ( & V_2 -> V_73 ) )
F_30 ( & V_26 -> V_53 , & V_2 -> V_73 ) ;
else
F_32 ( & V_26 -> V_53 ) ;
goto V_72;
}
F_33 ( V_7 , V_4 ) ;
V_26 -> V_56 -= F_14 ( V_4 ) ;
if ( V_2 -> V_74 . V_75 && V_7 -> V_2 . V_46 ) {
F_23 ( V_7 , V_2 -> V_74 . V_75 ,
V_2 -> V_74 . V_79 ) ;
V_2 -> V_74 . V_75 = 0 ;
V_2 -> V_74 . V_79 = 0 ;
}
return V_4 ;
}
static void F_34 ( struct V_25 * V_26 )
{
F_35 ( V_26 -> V_27 , V_26 -> V_29 ) ;
V_26 -> V_27 = NULL ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_34 ;
F_37 ( & V_2 -> V_54 ) ;
F_37 ( & V_2 -> V_73 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_5 ; V_34 ++ ) {
struct V_25 * V_26 = V_2 -> V_39 + V_34 ;
F_34 ( V_26 ) ;
F_37 ( & V_26 -> V_53 ) ;
F_38 ( & V_26 -> V_68 ) ;
}
memset ( V_2 -> V_38 , 0 , V_2 -> V_5 * sizeof( T_1 ) ) ;
V_7 -> V_2 . V_46 = 0 ;
V_7 -> V_43 . V_45 = 0 ;
V_2 -> V_42 = 0 ;
}
static int F_39 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_80 * V_82 [ V_83 + 1 ] ;
int V_84 ;
if ( ! V_81 )
return - V_85 ;
V_84 = F_40 ( V_82 , V_83 , V_81 , V_86 ,
NULL ) ;
if ( V_84 < 0 )
return V_84 ;
if ( V_82 [ V_87 ] ) {
if ( V_2 -> V_39 )
return - V_85 ;
V_2 -> V_5 = F_41 ( V_82 [ V_87 ] ) ;
if ( ! V_2 -> V_5 ||
V_2 -> V_5 > 65536 )
return - V_85 ;
}
F_42 ( V_7 ) ;
if ( V_82 [ V_88 ] ) {
T_2 V_89 = F_41 ( V_82 [ V_88 ] ) ;
V_2 -> V_77 . V_89 = ( V_89 * V_90 ) >> V_91 ;
}
if ( V_82 [ V_92 ] ) {
T_2 V_93 = F_41 ( V_82 [ V_92 ] ) ;
V_2 -> V_77 . V_94 = ( V_93 * V_90 ) >> V_91 ;
}
if ( V_82 [ V_95 ] ) {
T_2 V_96 = F_41 ( V_82 [ V_95 ] ) ;
V_2 -> V_77 . V_96 = ( V_96 * V_90 ) >> V_91 ;
}
if ( V_82 [ V_97 ] )
V_7 -> V_60 = F_41 ( V_82 [ V_97 ] ) ;
if ( V_82 [ V_98 ] )
V_2 -> V_77 . V_99 = ! ! F_41 ( V_82 [ V_98 ] ) ;
if ( V_82 [ V_100 ] )
V_2 -> V_57 = F_43 ( 256U , F_41 ( V_82 [ V_100 ] ) ) ;
if ( V_82 [ V_101 ] )
V_2 -> V_61 = F_44 ( 1U , F_41 ( V_82 [ V_101 ] ) ) ;
if ( V_82 [ V_102 ] )
V_2 -> V_59 = F_44 ( 1U << 31 , F_41 ( V_82 [ V_102 ] ) ) ;
while ( V_7 -> V_2 . V_46 > V_7 -> V_60 ||
V_2 -> V_42 > V_2 -> V_59 ) {
struct V_3 * V_4 = F_28 ( V_7 ) ;
V_2 -> V_74 . V_79 += F_14 ( V_4 ) ;
F_35 ( V_4 , V_4 ) ;
V_2 -> V_74 . V_75 ++ ;
}
F_23 ( V_7 , V_2 -> V_74 . V_75 , V_2 -> V_74 . V_79 ) ;
V_2 -> V_74 . V_75 = 0 ;
V_2 -> V_74 . V_79 = 0 ;
F_45 ( V_7 ) ;
return 0 ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_47 ( V_2 -> V_103 ) ;
F_48 ( V_2 -> V_38 ) ;
F_48 ( V_2 -> V_39 ) ;
}
static int F_49 ( struct V_6 * V_7 , struct V_80 * V_81 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
int V_34 ;
int V_84 ;
V_7 -> V_60 = 10 * 1024 ;
V_2 -> V_5 = 1024 ;
V_2 -> V_59 = 32 << 20 ;
V_2 -> V_61 = 64 ;
V_2 -> V_57 = F_50 ( F_51 ( V_7 ) ) ;
F_37 ( & V_2 -> V_54 ) ;
F_37 ( & V_2 -> V_73 ) ;
F_52 ( & V_2 -> V_77 ) ;
F_53 ( & V_2 -> V_74 ) ;
V_2 -> V_77 . V_99 = true ;
V_2 -> V_77 . V_104 = F_50 ( F_51 ( V_7 ) ) ;
if ( V_81 ) {
int V_84 = F_39 ( V_7 , V_81 ) ;
if ( V_84 )
return V_84 ;
}
V_84 = F_54 ( & V_2 -> V_103 , & V_2 -> V_16 ) ;
if ( V_84 )
return V_84 ;
if ( ! V_2 -> V_39 ) {
V_2 -> V_39 = F_55 ( V_2 -> V_5 *
sizeof( struct V_25 ) , V_105 ) ;
if ( ! V_2 -> V_39 )
return - V_106 ;
V_2 -> V_38 = F_55 ( V_2 -> V_5 * sizeof( T_1 ) , V_105 ) ;
if ( ! V_2 -> V_38 )
return - V_106 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_5 ; V_34 ++ ) {
struct V_25 * V_26 = V_2 -> V_39 + V_34 ;
F_37 ( & V_26 -> V_53 ) ;
F_38 ( & V_26 -> V_68 ) ;
}
}
if ( V_7 -> V_60 >= 1 )
V_7 -> V_107 |= V_108 ;
else
V_7 -> V_107 &= ~ V_108 ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_80 * V_109 ;
V_109 = F_57 ( V_4 , V_110 ) ;
if ( V_109 == NULL )
goto V_111;
if ( F_58 ( V_4 , V_88 ,
F_59 ( V_2 -> V_77 . V_89 ) ) ||
F_58 ( V_4 , V_97 ,
V_7 -> V_60 ) ||
F_58 ( V_4 , V_95 ,
F_59 ( V_2 -> V_77 . V_96 ) ) ||
F_58 ( V_4 , V_98 ,
V_2 -> V_77 . V_99 ) ||
F_58 ( V_4 , V_100 ,
V_2 -> V_57 ) ||
F_58 ( V_4 , V_101 ,
V_2 -> V_61 ) ||
F_58 ( V_4 , V_102 ,
V_2 -> V_59 ) ||
F_58 ( V_4 , V_87 ,
V_2 -> V_5 ) )
goto V_111;
if ( V_2 -> V_77 . V_94 != V_112 &&
F_58 ( V_4 , V_92 ,
F_59 ( V_2 -> V_77 . V_94 ) ) )
goto V_111;
return F_60 ( V_4 , V_109 ) ;
V_111:
return - 1 ;
}
static int F_61 ( struct V_6 * V_7 , struct V_113 * V_114 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
struct V_115 V_116 = {
. type = V_117 ,
} ;
struct V_69 * V_118 ;
V_116 . V_119 . V_120 = V_2 -> V_74 . V_120 ;
V_116 . V_119 . V_62 = V_2 -> V_62 ;
V_116 . V_119 . V_76 = V_2 -> V_74 . V_76 ;
V_116 . V_119 . V_55 = V_2 -> V_55 ;
V_116 . V_119 . V_121 = V_2 -> V_74 . V_121 ;
V_116 . V_119 . V_42 = V_2 -> V_42 ;
V_116 . V_119 . V_63 = V_2 -> V_63 ;
F_42 ( V_7 ) ;
F_62 (pos, &q->new_flows)
V_116 . V_119 . V_122 ++ ;
F_62 (pos, &q->old_flows)
V_116 . V_119 . V_123 ++ ;
F_45 ( V_7 ) ;
return F_63 ( V_114 , & V_116 , sizeof( V_116 ) ) ;
}
static struct V_6 * F_64 ( struct V_6 * V_7 , unsigned long V_124 )
{
return NULL ;
}
static unsigned long F_65 ( struct V_6 * V_7 , T_1 V_24 )
{
return 0 ;
}
static unsigned long F_66 ( struct V_6 * V_7 , unsigned long V_125 ,
T_1 V_24 )
{
V_7 -> V_107 &= ~ V_108 ;
return 0 ;
}
static void F_67 ( struct V_6 * V_2 , unsigned long V_126 )
{
}
static struct V_127 * F_68 ( struct V_6 * V_7 , unsigned long V_126 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
if ( V_126 )
return NULL ;
return V_2 -> V_103 ;
}
static int F_69 ( struct V_6 * V_7 , unsigned long V_126 ,
struct V_3 * V_4 , struct V_128 * V_129 )
{
V_129 -> V_130 |= F_7 ( V_126 ) ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 , unsigned long V_126 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_33 = V_126 - 1 ;
struct V_131 V_132 = { 0 } ;
struct V_115 V_133 ;
if ( V_33 < V_2 -> V_5 ) {
const struct V_25 * V_26 = & V_2 -> V_39 [ V_33 ] ;
const struct V_3 * V_4 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . type = V_134 ;
V_133 . V_135 . V_56 = V_26 -> V_56 ;
V_133 . V_135 . V_136 =
F_59 ( V_26 -> V_68 . V_136 ) ;
V_133 . V_135 . V_137 = V_26 -> V_68 . V_137 ;
V_133 . V_135 . V_138 = V_26 -> V_68 . V_138 ;
V_133 . V_135 . V_139 = V_26 -> V_68 . V_139 ;
if ( V_26 -> V_68 . V_139 ) {
T_3 V_140 = V_26 -> V_68 . V_141 -
F_71 () ;
V_133 . V_135 . V_141 = ( V_140 >= 0 ) ?
F_59 ( V_140 ) :
- F_59 ( - V_140 ) ;
}
if ( V_26 -> V_27 ) {
F_42 ( V_7 ) ;
V_4 = V_26 -> V_27 ;
while ( V_4 ) {
V_132 . V_46 ++ ;
V_4 = V_4 -> V_28 ;
}
F_45 ( V_7 ) ;
}
V_132 . V_45 = V_2 -> V_38 [ V_33 ] ;
V_132 . V_44 = V_26 -> V_41 ;
}
if ( F_72 ( V_114 , NULL , & V_132 , V_132 . V_46 ) < 0 )
return - 1 ;
if ( V_33 < V_2 -> V_5 )
return F_63 ( V_114 , & V_133 , sizeof( V_133 ) ) ;
return 0 ;
}
static void F_73 ( struct V_6 * V_7 , struct V_142 * V_124 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_34 ;
if ( V_124 -> V_143 )
return;
for ( V_34 = 0 ; V_34 < V_2 -> V_5 ; V_34 ++ ) {
if ( F_21 ( & V_2 -> V_39 [ V_34 ] . V_53 ) ||
V_124 -> V_137 < V_124 -> V_144 ) {
V_124 -> V_137 ++ ;
continue;
}
if ( V_124 -> V_145 ( V_7 , V_34 + 1 , V_124 ) < 0 ) {
V_124 -> V_143 = 1 ;
break;
}
V_124 -> V_137 ++ ;
}
}
static int T_4 F_74 ( void )
{
return F_75 ( & V_146 ) ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_146 ) ;
}
