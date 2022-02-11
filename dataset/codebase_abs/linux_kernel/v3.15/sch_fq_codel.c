static unsigned int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 ;
unsigned int V_7 ;
F_2 ( V_4 , & V_6 ) ;
V_7 = F_3 ( ( V_8 V_9 ) V_6 . V_10 ,
( V_8 V_9 ) V_6 . V_11 ^ V_6 . V_12 ,
( V_8 V_9 ) V_6 . V_13 , V_2 -> V_14 ) ;
return ( ( V_15 ) V_7 * V_2 -> V_16 ) >> 32 ;
}
static unsigned int F_4 ( struct V_3 * V_4 , struct V_17 * V_18 ,
int * V_19 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_20 V_21 ;
int V_22 ;
if ( F_6 ( V_4 -> V_23 ) == V_18 -> V_24 &&
F_7 ( V_4 -> V_23 ) > 0 &&
F_7 ( V_4 -> V_23 ) <= V_2 -> V_16 )
return F_7 ( V_4 -> V_23 ) ;
if ( ! V_2 -> V_25 )
return F_1 ( V_2 , V_4 ) + 1 ;
* V_19 = V_26 | V_27 ;
V_22 = F_8 ( V_4 , V_2 -> V_25 , & V_21 ) ;
if ( V_22 >= 0 ) {
#ifdef F_9
switch ( V_22 ) {
case V_28 :
case V_29 :
* V_19 = V_26 | V_30 ;
case V_31 :
return 0 ;
}
#endif
if ( F_7 ( V_21 . V_32 ) <= V_2 -> V_16 )
return F_7 ( V_21 . V_32 ) ;
}
return 0 ;
}
static inline struct V_3 * F_10 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = V_34 -> V_35 ;
V_34 -> V_35 = V_4 -> V_36 ;
V_4 -> V_36 = NULL ;
return V_4 ;
}
static inline void F_11 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
if ( V_34 -> V_35 == NULL )
V_34 -> V_35 = V_4 ;
else
V_34 -> V_37 -> V_36 = V_4 ;
V_34 -> V_37 = V_4 ;
V_4 -> V_36 = NULL ;
}
static unsigned int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_3 * V_4 ;
unsigned int V_38 = 0 , V_39 = 0 , V_40 , V_41 ;
struct V_33 * V_34 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_16 ; V_40 ++ ) {
if ( V_2 -> V_42 [ V_40 ] > V_38 ) {
V_38 = V_2 -> V_42 [ V_40 ] ;
V_39 = V_40 ;
}
}
V_34 = & V_2 -> V_43 [ V_39 ] ;
V_4 = F_10 ( V_34 ) ;
V_41 = F_13 ( V_4 ) ;
V_2 -> V_42 [ V_39 ] -= V_41 ;
F_14 ( V_4 ) ;
V_18 -> V_2 . V_44 -- ;
V_18 -> V_45 . V_46 ++ ;
V_18 -> V_45 . V_47 -= V_41 ;
V_34 -> V_48 ++ ;
return V_39 ;
}
static int F_15 ( struct V_3 * V_4 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
unsigned int V_39 ;
struct V_33 * V_34 ;
int V_49 ( V_50 ) ;
V_39 = F_4 ( V_4 , V_18 , & V_50 ) ;
if ( V_39 == 0 ) {
if ( V_50 & V_27 )
V_18 -> V_45 . V_46 ++ ;
F_14 ( V_4 ) ;
return V_50 ;
}
V_39 -- ;
F_16 ( V_4 ) ;
V_34 = & V_2 -> V_43 [ V_39 ] ;
F_11 ( V_34 , V_4 ) ;
V_2 -> V_42 [ V_39 ] += F_13 ( V_4 ) ;
V_18 -> V_45 . V_47 += F_13 ( V_4 ) ;
if ( F_17 ( & V_34 -> V_51 ) ) {
F_18 ( & V_34 -> V_51 , & V_2 -> V_52 ) ;
V_2 -> V_53 ++ ;
V_34 -> V_54 = V_2 -> V_55 ;
V_34 -> V_48 = 0 ;
}
if ( ++ V_18 -> V_2 . V_44 <= V_18 -> V_56 )
return V_26 ;
V_2 -> V_57 ++ ;
if ( F_12 ( V_18 ) == V_39 )
return V_58 ;
F_19 ( V_18 , 1 ) ;
return V_26 ;
}
static struct V_3 * F_20 ( struct V_59 * V_60 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_33 * V_34 ;
struct V_3 * V_4 = NULL ;
V_34 = F_21 ( V_60 , struct V_33 , V_61 ) ;
if ( V_34 -> V_35 ) {
V_4 = F_10 ( V_34 ) ;
V_2 -> V_42 [ V_34 - V_2 -> V_43 ] -= F_13 ( V_4 ) ;
V_18 -> V_2 . V_44 -- ;
}
return V_4 ;
}
static struct V_3 * F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_3 * V_4 ;
struct V_33 * V_34 ;
struct V_62 * V_35 ;
V_9 V_63 , V_64 ;
V_65:
V_35 = & V_2 -> V_52 ;
if ( F_17 ( V_35 ) ) {
V_35 = & V_2 -> V_66 ;
if ( F_17 ( V_35 ) )
return NULL ;
}
V_34 = F_23 ( V_35 , struct V_33 , V_51 ) ;
if ( V_34 -> V_54 <= 0 ) {
V_34 -> V_54 += V_2 -> V_55 ;
F_24 ( & V_34 -> V_51 , & V_2 -> V_66 ) ;
goto V_65;
}
V_63 = V_2 -> V_67 . V_68 ;
V_64 = V_2 -> V_67 . V_69 ;
V_4 = F_25 ( V_18 , & V_2 -> V_70 , & V_34 -> V_61 , & V_2 -> V_67 ,
F_20 ) ;
V_34 -> V_48 += V_2 -> V_67 . V_68 - V_63 ;
V_34 -> V_48 += V_2 -> V_67 . V_69 - V_64 ;
if ( ! V_4 ) {
if ( ( V_35 == & V_2 -> V_52 ) && ! F_17 ( & V_2 -> V_66 ) )
F_24 ( & V_34 -> V_51 , & V_2 -> V_66 ) ;
else
F_26 ( & V_34 -> V_51 ) ;
goto V_65;
}
F_27 ( V_18 , V_4 ) ;
V_34 -> V_54 -= F_13 ( V_4 ) ;
if ( V_2 -> V_67 . V_68 && V_18 -> V_2 . V_44 ) {
F_19 ( V_18 , V_2 -> V_67 . V_68 ) ;
V_2 -> V_67 . V_68 = 0 ;
}
return V_4 ;
}
static void F_28 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_22 ( V_18 ) ) != NULL )
F_14 ( V_4 ) ;
}
static int F_29 ( struct V_17 * V_18 , struct V_71 * V_72 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_71 * V_73 [ V_74 + 1 ] ;
int V_75 ;
if ( ! V_72 )
return - V_76 ;
V_75 = F_30 ( V_73 , V_74 , V_72 , V_77 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_73 [ V_78 ] ) {
if ( V_2 -> V_43 )
return - V_76 ;
V_2 -> V_16 = F_31 ( V_73 [ V_78 ] ) ;
if ( ! V_2 -> V_16 ||
V_2 -> V_16 > 65536 )
return - V_76 ;
}
F_32 ( V_18 ) ;
if ( V_73 [ V_79 ] ) {
V_15 V_80 = F_31 ( V_73 [ V_79 ] ) ;
V_2 -> V_70 . V_80 = ( V_80 * V_81 ) >> V_82 ;
}
if ( V_73 [ V_83 ] ) {
V_15 V_84 = F_31 ( V_73 [ V_83 ] ) ;
V_2 -> V_70 . V_84 = ( V_84 * V_81 ) >> V_82 ;
}
if ( V_73 [ V_85 ] )
V_18 -> V_56 = F_31 ( V_73 [ V_85 ] ) ;
if ( V_73 [ V_86 ] )
V_2 -> V_70 . V_87 = ! ! F_31 ( V_73 [ V_86 ] ) ;
if ( V_73 [ V_88 ] )
V_2 -> V_55 = F_33 ( 256U , F_31 ( V_73 [ V_88 ] ) ) ;
while ( V_18 -> V_2 . V_44 > V_18 -> V_56 ) {
struct V_3 * V_4 = F_22 ( V_18 ) ;
F_14 ( V_4 ) ;
V_2 -> V_67 . V_68 ++ ;
}
F_19 ( V_18 , V_2 -> V_67 . V_68 ) ;
V_2 -> V_67 . V_68 = 0 ;
F_34 ( V_18 ) ;
return 0 ;
}
static void * F_35 ( T_1 V_89 )
{
void * V_90 = F_36 ( V_89 , V_91 | V_92 ) ;
if ( ! V_90 )
V_90 = F_37 ( V_89 ) ;
return V_90 ;
}
static void F_38 ( void * V_93 )
{
if ( V_93 ) {
if ( F_39 ( V_93 ) )
F_40 ( V_93 ) ;
else
F_41 ( V_93 ) ;
}
}
static void F_42 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
F_43 ( & V_2 -> V_25 ) ;
F_38 ( V_2 -> V_42 ) ;
F_38 ( V_2 -> V_43 ) ;
}
static int F_44 ( struct V_17 * V_18 , struct V_71 * V_72 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
int V_40 ;
V_18 -> V_56 = 10 * 1024 ;
V_2 -> V_16 = 1024 ;
V_2 -> V_55 = F_45 ( F_46 ( V_18 ) ) ;
V_2 -> V_14 = F_47 () ;
F_48 ( & V_2 -> V_52 ) ;
F_48 ( & V_2 -> V_66 ) ;
F_49 ( & V_2 -> V_70 ) ;
F_50 ( & V_2 -> V_67 ) ;
V_2 -> V_70 . V_87 = true ;
if ( V_72 ) {
int V_75 = F_29 ( V_18 , V_72 ) ;
if ( V_75 )
return V_75 ;
}
if ( ! V_2 -> V_43 ) {
V_2 -> V_43 = F_35 ( V_2 -> V_16 *
sizeof( struct V_33 ) ) ;
if ( ! V_2 -> V_43 )
return - V_94 ;
V_2 -> V_42 = F_35 ( V_2 -> V_16 * sizeof( V_9 ) ) ;
if ( ! V_2 -> V_42 ) {
F_38 ( V_2 -> V_43 ) ;
return - V_94 ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_16 ; V_40 ++ ) {
struct V_33 * V_34 = V_2 -> V_43 + V_40 ;
F_48 ( & V_34 -> V_51 ) ;
F_51 ( & V_34 -> V_61 ) ;
}
}
if ( V_18 -> V_56 >= 1 )
V_18 -> V_95 |= V_96 ;
else
V_18 -> V_95 &= ~ V_96 ;
return 0 ;
}
static int F_52 ( struct V_17 * V_18 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_71 * V_97 ;
V_97 = F_53 ( V_4 , V_98 ) ;
if ( V_97 == NULL )
goto V_99;
if ( F_54 ( V_4 , V_79 ,
F_55 ( V_2 -> V_70 . V_80 ) ) ||
F_54 ( V_4 , V_85 ,
V_18 -> V_56 ) ||
F_54 ( V_4 , V_83 ,
F_55 ( V_2 -> V_70 . V_84 ) ) ||
F_54 ( V_4 , V_86 ,
V_2 -> V_70 . V_87 ) ||
F_54 ( V_4 , V_88 ,
V_2 -> V_55 ) ||
F_54 ( V_4 , V_78 ,
V_2 -> V_16 ) )
goto V_99;
return F_56 ( V_4 , V_97 ) ;
V_99:
return - 1 ;
}
static int F_57 ( struct V_17 * V_18 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
struct V_102 V_103 = {
. type = V_104 ,
} ;
struct V_62 * V_105 ;
V_103 . V_106 . V_107 = V_2 -> V_67 . V_107 ;
V_103 . V_106 . V_57 = V_2 -> V_57 ;
V_103 . V_106 . V_69 = V_2 -> V_67 . V_69 ;
V_103 . V_106 . V_53 = V_2 -> V_53 ;
F_58 (pos, &q->new_flows)
V_103 . V_106 . V_108 ++ ;
F_58 (pos, &q->old_flows)
V_103 . V_106 . V_109 ++ ;
return F_59 ( V_101 , & V_103 , sizeof( V_103 ) ) ;
}
static struct V_17 * F_60 ( struct V_17 * V_18 , unsigned long V_110 )
{
return NULL ;
}
static unsigned long F_61 ( struct V_17 * V_18 , V_9 V_32 )
{
return 0 ;
}
static unsigned long F_62 ( struct V_17 * V_18 , unsigned long V_111 ,
V_9 V_32 )
{
V_18 -> V_95 &= ~ V_96 ;
return 0 ;
}
static void F_63 ( struct V_17 * V_2 , unsigned long V_112 )
{
}
static struct V_113 * * F_64 ( struct V_17 * V_18 , unsigned long V_112 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
if ( V_112 )
return NULL ;
return & V_2 -> V_25 ;
}
static int F_65 ( struct V_17 * V_18 , unsigned long V_112 ,
struct V_3 * V_4 , struct V_114 * V_115 )
{
V_115 -> V_116 |= F_7 ( V_112 ) ;
return 0 ;
}
static int F_66 ( struct V_17 * V_18 , unsigned long V_112 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
V_9 V_39 = V_112 - 1 ;
struct V_117 V_118 = { 0 } ;
struct V_102 V_119 ;
if ( V_39 < V_2 -> V_16 ) {
const struct V_33 * V_34 = & V_2 -> V_43 [ V_39 ] ;
const struct V_3 * V_4 = V_34 -> V_35 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . type = V_120 ;
V_119 . V_121 . V_54 = V_34 -> V_54 ;
V_119 . V_121 . V_122 =
F_55 ( V_34 -> V_61 . V_122 ) ;
V_119 . V_121 . V_123 = V_34 -> V_61 . V_123 ;
V_119 . V_121 . V_124 = V_34 -> V_61 . V_124 ;
V_119 . V_121 . V_125 = V_34 -> V_61 . V_125 ;
if ( V_34 -> V_61 . V_125 ) {
T_2 V_126 = V_34 -> V_61 . V_127 -
F_67 () ;
V_119 . V_121 . V_127 = ( V_126 >= 0 ) ?
F_55 ( V_126 ) :
- F_55 ( - V_126 ) ;
}
while ( V_4 ) {
V_118 . V_44 ++ ;
V_4 = V_4 -> V_36 ;
}
V_118 . V_47 = V_2 -> V_42 [ V_39 ] ;
V_118 . V_46 = V_34 -> V_48 ;
}
if ( F_68 ( V_101 , & V_118 ) < 0 )
return - 1 ;
if ( V_39 < V_2 -> V_16 )
return F_59 ( V_101 , & V_119 , sizeof( V_119 ) ) ;
return 0 ;
}
static void F_69 ( struct V_17 * V_18 , struct V_128 * V_110 )
{
struct V_1 * V_2 = F_5 ( V_18 ) ;
unsigned int V_40 ;
if ( V_110 -> V_129 )
return;
for ( V_40 = 0 ; V_40 < V_2 -> V_16 ; V_40 ++ ) {
if ( F_17 ( & V_2 -> V_43 [ V_40 ] . V_51 ) ||
V_110 -> V_123 < V_110 -> V_130 ) {
V_110 -> V_123 ++ ;
continue;
}
if ( V_110 -> V_131 ( V_18 , V_40 + 1 , V_110 ) < 0 ) {
V_110 -> V_129 = 1 ;
break;
}
V_110 -> V_123 ++ ;
}
}
static int T_3 F_70 ( void )
{
return F_71 ( & V_132 ) ;
}
static void T_4 F_72 ( void )
{
F_73 ( & V_132 ) ;
}
