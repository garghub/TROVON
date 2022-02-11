static unsigned int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 ;
unsigned int V_7 ;
F_2 ( V_4 , & V_6 ) ;
V_7 = F_3 ( ( V_8 V_9 ) V_6 . V_10 ,
( V_8 V_9 ) V_6 . V_11 ^ V_6 . V_12 ,
( V_8 V_9 ) V_6 . V_13 , V_2 -> V_14 ) ;
return F_4 ( V_7 , V_2 -> V_15 ) ;
}
static unsigned int F_5 ( struct V_3 * V_4 , struct V_16 * V_17 ,
int * V_18 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_19 * V_20 ;
struct V_21 V_22 ;
int V_23 ;
if ( F_7 ( V_4 -> V_24 ) == V_17 -> V_25 &&
F_8 ( V_4 -> V_24 ) > 0 &&
F_8 ( V_4 -> V_24 ) <= V_2 -> V_15 )
return F_8 ( V_4 -> V_24 ) ;
V_20 = F_9 ( V_2 -> V_26 ) ;
if ( ! V_20 )
return F_1 ( V_2 , V_4 ) + 1 ;
* V_18 = V_27 | V_28 ;
V_23 = F_10 ( V_4 , V_20 , & V_22 ) ;
if ( V_23 >= 0 ) {
#ifdef F_11
switch ( V_23 ) {
case V_29 :
case V_30 :
* V_18 = V_27 | V_31 ;
case V_32 :
return 0 ;
}
#endif
if ( F_8 ( V_22 . V_33 ) <= V_2 -> V_15 )
return F_8 ( V_22 . V_33 ) ;
}
return 0 ;
}
static inline struct V_3 * F_12 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = V_35 -> V_36 ;
V_35 -> V_36 = V_4 -> V_37 ;
V_4 -> V_37 = NULL ;
return V_4 ;
}
static inline void F_13 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
if ( V_35 -> V_36 == NULL )
V_35 -> V_36 = V_4 ;
else
V_35 -> V_38 -> V_37 = V_4 ;
V_35 -> V_38 = V_4 ;
V_4 -> V_37 = NULL ;
}
static unsigned int F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_3 * V_4 ;
unsigned int V_39 = 0 , V_40 = 0 , V_41 , V_42 ;
struct V_34 * V_35 ;
for ( V_41 = 0 ; V_41 < V_2 -> V_15 ; V_41 ++ ) {
if ( V_2 -> V_43 [ V_41 ] > V_39 ) {
V_39 = V_2 -> V_43 [ V_41 ] ;
V_40 = V_41 ;
}
}
V_35 = & V_2 -> V_44 [ V_40 ] ;
V_4 = F_12 ( V_35 ) ;
V_42 = F_15 ( V_4 ) ;
V_2 -> V_43 [ V_40 ] -= V_42 ;
F_16 ( V_4 ) ;
V_17 -> V_2 . V_45 -- ;
F_17 ( V_17 ) ;
F_18 ( V_17 , V_4 ) ;
V_35 -> V_46 ++ ;
return V_40 ;
}
static int F_19 ( struct V_3 * V_4 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
unsigned int V_40 ;
struct V_34 * V_35 ;
int V_47 ( V_48 ) ;
V_40 = F_5 ( V_4 , V_17 , & V_48 ) ;
if ( V_40 == 0 ) {
if ( V_48 & V_28 )
F_17 ( V_17 ) ;
F_16 ( V_4 ) ;
return V_48 ;
}
V_40 -- ;
F_20 ( V_4 ) ;
V_35 = & V_2 -> V_44 [ V_40 ] ;
F_13 ( V_35 , V_4 ) ;
V_2 -> V_43 [ V_40 ] += F_15 ( V_4 ) ;
F_21 ( V_17 , V_4 ) ;
if ( F_22 ( & V_35 -> V_49 ) ) {
F_23 ( & V_35 -> V_49 , & V_2 -> V_50 ) ;
V_2 -> V_51 ++ ;
V_35 -> V_52 = V_2 -> V_53 ;
V_35 -> V_46 = 0 ;
}
if ( ++ V_17 -> V_2 . V_45 <= V_17 -> V_54 )
return V_27 ;
V_2 -> V_55 ++ ;
if ( F_14 ( V_17 ) == V_40 )
return V_56 ;
F_24 ( V_17 , 1 ) ;
return V_27 ;
}
static struct V_3 * F_25 ( struct V_57 * V_58 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_34 * V_35 ;
struct V_3 * V_4 = NULL ;
V_35 = F_26 ( V_58 , struct V_34 , V_59 ) ;
if ( V_35 -> V_36 ) {
V_4 = F_12 ( V_35 ) ;
V_2 -> V_43 [ V_35 - V_2 -> V_44 ] -= F_15 ( V_4 ) ;
V_17 -> V_2 . V_45 -- ;
}
return V_4 ;
}
static struct V_3 * F_27 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
struct V_60 * V_36 ;
V_9 V_61 , V_62 ;
V_63:
V_36 = & V_2 -> V_50 ;
if ( F_22 ( V_36 ) ) {
V_36 = & V_2 -> V_64 ;
if ( F_22 ( V_36 ) )
return NULL ;
}
V_35 = F_28 ( V_36 , struct V_34 , V_49 ) ;
if ( V_35 -> V_52 <= 0 ) {
V_35 -> V_52 += V_2 -> V_53 ;
F_29 ( & V_35 -> V_49 , & V_2 -> V_64 ) ;
goto V_63;
}
V_61 = V_2 -> V_65 . V_66 ;
V_62 = V_2 -> V_65 . V_67 ;
V_4 = F_30 ( V_17 , & V_2 -> V_68 , & V_35 -> V_59 , & V_2 -> V_65 ,
F_25 ) ;
V_35 -> V_46 += V_2 -> V_65 . V_66 - V_61 ;
V_35 -> V_46 += V_2 -> V_65 . V_67 - V_62 ;
if ( ! V_4 ) {
if ( ( V_36 == & V_2 -> V_50 ) && ! F_22 ( & V_2 -> V_64 ) )
F_29 ( & V_35 -> V_49 , & V_2 -> V_64 ) ;
else
F_31 ( & V_35 -> V_49 ) ;
goto V_63;
}
F_32 ( V_17 , V_4 ) ;
V_35 -> V_52 -= F_15 ( V_4 ) ;
if ( V_2 -> V_65 . V_66 && V_17 -> V_2 . V_45 ) {
F_24 ( V_17 , V_2 -> V_65 . V_66 ) ;
V_2 -> V_65 . V_66 = 0 ;
}
return V_4 ;
}
static void F_33 ( struct V_16 * V_17 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_27 ( V_17 ) ) != NULL )
F_16 ( V_4 ) ;
}
static int F_34 ( struct V_16 * V_17 , struct V_69 * V_70 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_69 * V_71 [ V_72 + 1 ] ;
int V_73 ;
if ( ! V_70 )
return - V_74 ;
V_73 = F_35 ( V_71 , V_72 , V_70 , V_75 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_71 [ V_76 ] ) {
if ( V_2 -> V_44 )
return - V_74 ;
V_2 -> V_15 = F_36 ( V_71 [ V_76 ] ) ;
if ( ! V_2 -> V_15 ||
V_2 -> V_15 > 65536 )
return - V_74 ;
}
F_37 ( V_17 ) ;
if ( V_71 [ V_77 ] ) {
T_1 V_78 = F_36 ( V_71 [ V_77 ] ) ;
V_2 -> V_68 . V_78 = ( V_78 * V_79 ) >> V_80 ;
}
if ( V_71 [ V_81 ] ) {
T_1 V_82 = F_36 ( V_71 [ V_81 ] ) ;
V_2 -> V_68 . V_82 = ( V_82 * V_79 ) >> V_80 ;
}
if ( V_71 [ V_83 ] )
V_17 -> V_54 = F_36 ( V_71 [ V_83 ] ) ;
if ( V_71 [ V_84 ] )
V_2 -> V_68 . V_85 = ! ! F_36 ( V_71 [ V_84 ] ) ;
if ( V_71 [ V_86 ] )
V_2 -> V_53 = F_38 ( 256U , F_36 ( V_71 [ V_86 ] ) ) ;
while ( V_17 -> V_2 . V_45 > V_17 -> V_54 ) {
struct V_3 * V_4 = F_27 ( V_17 ) ;
F_16 ( V_4 ) ;
V_2 -> V_65 . V_66 ++ ;
}
F_24 ( V_17 , V_2 -> V_65 . V_66 ) ;
V_2 -> V_65 . V_66 = 0 ;
F_39 ( V_17 ) ;
return 0 ;
}
static void * F_40 ( T_2 V_87 )
{
void * V_88 = F_41 ( V_87 , V_89 | V_90 ) ;
if ( ! V_88 )
V_88 = F_42 ( V_87 ) ;
return V_88 ;
}
static void F_43 ( void * V_91 )
{
F_44 ( V_91 ) ;
}
static void F_45 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
F_46 ( & V_2 -> V_26 ) ;
F_43 ( V_2 -> V_43 ) ;
F_43 ( V_2 -> V_44 ) ;
}
static int F_47 ( struct V_16 * V_17 , struct V_69 * V_70 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
int V_41 ;
V_17 -> V_54 = 10 * 1024 ;
V_2 -> V_15 = 1024 ;
V_2 -> V_53 = F_48 ( F_49 ( V_17 ) ) ;
V_2 -> V_14 = F_50 () ;
F_51 ( & V_2 -> V_50 ) ;
F_51 ( & V_2 -> V_64 ) ;
F_52 ( & V_2 -> V_68 ) ;
F_53 ( & V_2 -> V_65 ) ;
V_2 -> V_68 . V_85 = true ;
if ( V_70 ) {
int V_73 = F_34 ( V_17 , V_70 ) ;
if ( V_73 )
return V_73 ;
}
if ( ! V_2 -> V_44 ) {
V_2 -> V_44 = F_40 ( V_2 -> V_15 *
sizeof( struct V_34 ) ) ;
if ( ! V_2 -> V_44 )
return - V_92 ;
V_2 -> V_43 = F_40 ( V_2 -> V_15 * sizeof( V_9 ) ) ;
if ( ! V_2 -> V_43 ) {
F_43 ( V_2 -> V_44 ) ;
return - V_92 ;
}
for ( V_41 = 0 ; V_41 < V_2 -> V_15 ; V_41 ++ ) {
struct V_34 * V_35 = V_2 -> V_44 + V_41 ;
F_51 ( & V_35 -> V_49 ) ;
F_54 ( & V_35 -> V_59 ) ;
}
}
if ( V_17 -> V_54 >= 1 )
V_17 -> V_93 |= V_94 ;
else
V_17 -> V_93 &= ~ V_94 ;
return 0 ;
}
static int F_55 ( struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_69 * V_95 ;
V_95 = F_56 ( V_4 , V_96 ) ;
if ( V_95 == NULL )
goto V_97;
if ( F_57 ( V_4 , V_77 ,
F_58 ( V_2 -> V_68 . V_78 ) ) ||
F_57 ( V_4 , V_83 ,
V_17 -> V_54 ) ||
F_57 ( V_4 , V_81 ,
F_58 ( V_2 -> V_68 . V_82 ) ) ||
F_57 ( V_4 , V_84 ,
V_2 -> V_68 . V_85 ) ||
F_57 ( V_4 , V_86 ,
V_2 -> V_53 ) ||
F_57 ( V_4 , V_76 ,
V_2 -> V_15 ) )
goto V_97;
return F_59 ( V_4 , V_95 ) ;
V_97:
return - 1 ;
}
static int F_60 ( struct V_16 * V_17 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
struct V_100 V_101 = {
. type = V_102 ,
} ;
struct V_60 * V_103 ;
V_101 . V_104 . V_105 = V_2 -> V_65 . V_105 ;
V_101 . V_104 . V_55 = V_2 -> V_55 ;
V_101 . V_104 . V_67 = V_2 -> V_65 . V_67 ;
V_101 . V_104 . V_51 = V_2 -> V_51 ;
F_61 (pos, &q->new_flows)
V_101 . V_104 . V_106 ++ ;
F_61 (pos, &q->old_flows)
V_101 . V_104 . V_107 ++ ;
return F_62 ( V_99 , & V_101 , sizeof( V_101 ) ) ;
}
static struct V_16 * F_63 ( struct V_16 * V_17 , unsigned long V_108 )
{
return NULL ;
}
static unsigned long F_64 ( struct V_16 * V_17 , V_9 V_33 )
{
return 0 ;
}
static unsigned long F_65 ( struct V_16 * V_17 , unsigned long V_109 ,
V_9 V_33 )
{
V_17 -> V_93 &= ~ V_94 ;
return 0 ;
}
static void F_66 ( struct V_16 * V_2 , unsigned long V_110 )
{
}
static struct V_19 T_3 * * F_67 ( struct V_16 * V_17 ,
unsigned long V_110 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
if ( V_110 )
return NULL ;
return & V_2 -> V_26 ;
}
static int F_68 ( struct V_16 * V_17 , unsigned long V_110 ,
struct V_3 * V_4 , struct V_111 * V_112 )
{
V_112 -> V_113 |= F_8 ( V_110 ) ;
return 0 ;
}
static int F_69 ( struct V_16 * V_17 , unsigned long V_110 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
V_9 V_40 = V_110 - 1 ;
struct V_114 V_115 = { 0 } ;
struct V_100 V_116 ;
if ( V_40 < V_2 -> V_15 ) {
const struct V_34 * V_35 = & V_2 -> V_44 [ V_40 ] ;
const struct V_3 * V_4 = V_35 -> V_36 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . type = V_117 ;
V_116 . V_118 . V_52 = V_35 -> V_52 ;
V_116 . V_118 . V_119 =
F_58 ( V_35 -> V_59 . V_119 ) ;
V_116 . V_118 . V_120 = V_35 -> V_59 . V_120 ;
V_116 . V_118 . V_121 = V_35 -> V_59 . V_121 ;
V_116 . V_118 . V_122 = V_35 -> V_59 . V_122 ;
if ( V_35 -> V_59 . V_122 ) {
T_4 V_123 = V_35 -> V_59 . V_124 -
F_70 () ;
V_116 . V_118 . V_124 = ( V_123 >= 0 ) ?
F_58 ( V_123 ) :
- F_58 ( - V_123 ) ;
}
while ( V_4 ) {
V_115 . V_45 ++ ;
V_4 = V_4 -> V_37 ;
}
V_115 . V_125 = V_2 -> V_43 [ V_40 ] ;
V_115 . V_126 = V_35 -> V_46 ;
}
if ( F_71 ( V_99 , NULL , & V_115 , 0 ) < 0 )
return - 1 ;
if ( V_40 < V_2 -> V_15 )
return F_62 ( V_99 , & V_116 , sizeof( V_116 ) ) ;
return 0 ;
}
static void F_72 ( struct V_16 * V_17 , struct V_127 * V_108 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
unsigned int V_41 ;
if ( V_108 -> V_128 )
return;
for ( V_41 = 0 ; V_41 < V_2 -> V_15 ; V_41 ++ ) {
if ( F_22 ( & V_2 -> V_44 [ V_41 ] . V_49 ) ||
V_108 -> V_120 < V_108 -> V_129 ) {
V_108 -> V_120 ++ ;
continue;
}
if ( V_108 -> V_130 ( V_17 , V_41 + 1 , V_108 ) < 0 ) {
V_108 -> V_128 = 1 ;
break;
}
V_108 -> V_120 ++ ;
}
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_131 ) ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_131 ) ;
}
