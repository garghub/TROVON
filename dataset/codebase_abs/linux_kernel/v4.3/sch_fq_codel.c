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
static unsigned int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
unsigned int V_31 = 0 , V_32 = 0 , V_33 , V_34 ;
struct V_26 * V_27 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_7 ; V_33 ++ ) {
if ( V_2 -> V_35 [ V_33 ] > V_31 ) {
V_31 = V_2 -> V_35 [ V_33 ] ;
V_32 = V_33 ;
}
}
V_27 = & V_2 -> V_36 [ V_32 ] ;
V_4 = F_11 ( V_27 ) ;
V_34 = F_14 ( V_4 ) ;
V_2 -> V_35 [ V_32 ] -= V_34 ;
V_9 -> V_2 . V_37 -- ;
F_15 ( V_9 ) ;
F_16 ( V_9 , V_4 ) ;
F_17 ( V_4 ) ;
V_27 -> V_38 ++ ;
return V_32 ;
}
static unsigned int F_18 ( struct V_8 * V_9 )
{
unsigned int V_39 ;
V_39 = V_9 -> V_40 . V_41 ;
F_13 ( V_9 ) ;
return V_39 - V_9 -> V_40 . V_41 ;
}
static int F_19 ( struct V_3 * V_4 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_32 ;
struct V_26 * V_27 ;
int V_42 ( V_43 ) ;
V_32 = F_4 ( V_4 , V_9 , & V_43 ) ;
if ( V_32 == 0 ) {
if ( V_43 & V_20 )
F_15 ( V_9 ) ;
F_17 ( V_4 ) ;
return V_43 ;
}
V_32 -- ;
F_20 ( V_4 ) ;
V_27 = & V_2 -> V_36 [ V_32 ] ;
F_12 ( V_27 , V_4 ) ;
V_2 -> V_35 [ V_32 ] += F_14 ( V_4 ) ;
F_21 ( V_9 , V_4 ) ;
if ( F_22 ( & V_27 -> V_44 ) ) {
F_23 ( & V_27 -> V_44 , & V_2 -> V_45 ) ;
V_2 -> V_46 ++ ;
V_27 -> V_47 = V_2 -> V_48 ;
V_27 -> V_38 = 0 ;
}
if ( ++ V_9 -> V_2 . V_37 <= V_9 -> V_49 )
return V_19 ;
V_2 -> V_50 ++ ;
if ( F_13 ( V_9 ) == V_32 )
return V_51 ;
F_24 ( V_9 , 1 ) ;
return V_19 ;
}
static struct V_3 * F_25 ( struct V_52 * V_53 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_26 * V_27 ;
struct V_3 * V_4 = NULL ;
V_27 = F_26 ( V_53 , struct V_26 , V_54 ) ;
if ( V_27 -> V_28 ) {
V_4 = F_11 ( V_27 ) ;
V_2 -> V_35 [ V_27 - V_2 -> V_36 ] -= F_14 ( V_4 ) ;
V_9 -> V_2 . V_37 -- ;
}
return V_4 ;
}
static struct V_3 * F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_3 * V_4 ;
struct V_26 * V_27 ;
struct V_55 * V_28 ;
T_1 V_56 , V_57 ;
V_58:
V_28 = & V_2 -> V_45 ;
if ( F_22 ( V_28 ) ) {
V_28 = & V_2 -> V_59 ;
if ( F_22 ( V_28 ) )
return NULL ;
}
V_27 = F_28 ( V_28 , struct V_26 , V_44 ) ;
if ( V_27 -> V_47 <= 0 ) {
V_27 -> V_47 += V_2 -> V_48 ;
F_29 ( & V_27 -> V_44 , & V_2 -> V_59 ) ;
goto V_58;
}
V_56 = V_2 -> V_60 . V_61 ;
V_57 = V_2 -> V_60 . V_62 ;
V_4 = F_30 ( V_9 , & V_2 -> V_63 , & V_27 -> V_54 , & V_2 -> V_60 ,
F_25 ) ;
V_27 -> V_38 += V_2 -> V_60 . V_61 - V_56 ;
V_27 -> V_38 += V_2 -> V_60 . V_62 - V_57 ;
if ( ! V_4 ) {
if ( ( V_28 == & V_2 -> V_45 ) && ! F_22 ( & V_2 -> V_59 ) )
F_29 ( & V_27 -> V_44 , & V_2 -> V_59 ) ;
else
F_31 ( & V_27 -> V_44 ) ;
goto V_58;
}
F_32 ( V_9 , V_4 ) ;
V_27 -> V_47 -= F_14 ( V_4 ) ;
if ( V_2 -> V_60 . V_61 && V_9 -> V_2 . V_37 ) {
F_24 ( V_9 , V_2 -> V_60 . V_61 ) ;
V_2 -> V_60 . V_61 = 0 ;
}
return V_4 ;
}
static void F_33 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_33 ;
F_34 ( & V_2 -> V_45 ) ;
F_34 ( & V_2 -> V_59 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_7 ; V_33 ++ ) {
struct V_26 * V_27 = V_2 -> V_36 + V_33 ;
while ( V_27 -> V_28 ) {
struct V_3 * V_4 = F_11 ( V_27 ) ;
F_16 ( V_9 , V_4 ) ;
F_17 ( V_4 ) ;
}
F_34 ( & V_27 -> V_44 ) ;
F_35 ( & V_27 -> V_54 ) ;
}
memset ( V_2 -> V_35 , 0 , V_2 -> V_7 * sizeof( T_1 ) ) ;
V_9 -> V_2 . V_37 = 0 ;
}
static int F_36 ( struct V_8 * V_9 , struct V_64 * V_65 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_64 * V_66 [ V_67 + 1 ] ;
int V_68 ;
if ( ! V_65 )
return - V_69 ;
V_68 = F_37 ( V_66 , V_67 , V_65 , V_70 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_66 [ V_71 ] ) {
if ( V_2 -> V_36 )
return - V_69 ;
V_2 -> V_7 = F_38 ( V_66 [ V_71 ] ) ;
if ( ! V_2 -> V_7 ||
V_2 -> V_7 > 65536 )
return - V_69 ;
}
F_39 ( V_9 ) ;
if ( V_66 [ V_72 ] ) {
T_2 V_73 = F_38 ( V_66 [ V_72 ] ) ;
V_2 -> V_63 . V_73 = ( V_73 * V_74 ) >> V_75 ;
}
if ( V_66 [ V_76 ] ) {
T_2 V_77 = F_38 ( V_66 [ V_76 ] ) ;
V_2 -> V_63 . V_78 = ( V_77 * V_74 ) >> V_75 ;
}
if ( V_66 [ V_79 ] ) {
T_2 V_80 = F_38 ( V_66 [ V_79 ] ) ;
V_2 -> V_63 . V_80 = ( V_80 * V_74 ) >> V_75 ;
}
if ( V_66 [ V_81 ] )
V_9 -> V_49 = F_38 ( V_66 [ V_81 ] ) ;
if ( V_66 [ V_82 ] )
V_2 -> V_63 . V_83 = ! ! F_38 ( V_66 [ V_82 ] ) ;
if ( V_66 [ V_84 ] )
V_2 -> V_48 = F_40 ( 256U , F_38 ( V_66 [ V_84 ] ) ) ;
while ( V_9 -> V_2 . V_37 > V_9 -> V_49 ) {
struct V_3 * V_4 = F_27 ( V_9 ) ;
F_17 ( V_4 ) ;
V_2 -> V_60 . V_61 ++ ;
}
F_24 ( V_9 , V_2 -> V_60 . V_61 ) ;
V_2 -> V_60 . V_61 = 0 ;
F_41 ( V_9 ) ;
return 0 ;
}
static void * F_42 ( T_3 V_85 )
{
void * V_86 = F_43 ( V_85 , V_87 | V_88 ) ;
if ( ! V_86 )
V_86 = F_44 ( V_85 ) ;
return V_86 ;
}
static void F_45 ( void * V_89 )
{
F_46 ( V_89 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_48 ( & V_2 -> V_18 ) ;
F_45 ( V_2 -> V_35 ) ;
F_45 ( V_2 -> V_36 ) ;
}
static int F_49 ( struct V_8 * V_9 , struct V_64 * V_65 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_33 ;
V_9 -> V_49 = 10 * 1024 ;
V_2 -> V_7 = 1024 ;
V_2 -> V_48 = F_50 ( F_51 ( V_9 ) ) ;
V_2 -> V_6 = F_52 () ;
F_34 ( & V_2 -> V_45 ) ;
F_34 ( & V_2 -> V_59 ) ;
F_53 ( & V_2 -> V_63 , V_9 ) ;
F_54 ( & V_2 -> V_60 ) ;
V_2 -> V_63 . V_83 = true ;
if ( V_65 ) {
int V_68 = F_36 ( V_9 , V_65 ) ;
if ( V_68 )
return V_68 ;
}
if ( ! V_2 -> V_36 ) {
V_2 -> V_36 = F_42 ( V_2 -> V_7 *
sizeof( struct V_26 ) ) ;
if ( ! V_2 -> V_36 )
return - V_90 ;
V_2 -> V_35 = F_42 ( V_2 -> V_7 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_35 ) {
F_45 ( V_2 -> V_36 ) ;
return - V_90 ;
}
for ( V_33 = 0 ; V_33 < V_2 -> V_7 ; V_33 ++ ) {
struct V_26 * V_27 = V_2 -> V_36 + V_33 ;
F_34 ( & V_27 -> V_44 ) ;
F_35 ( & V_27 -> V_54 ) ;
}
}
if ( V_9 -> V_49 >= 1 )
V_9 -> V_91 |= V_92 ;
else
V_9 -> V_91 &= ~ V_92 ;
return 0 ;
}
static int F_55 ( struct V_8 * V_9 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_64 * V_93 ;
V_93 = F_56 ( V_4 , V_94 ) ;
if ( V_93 == NULL )
goto V_95;
if ( F_57 ( V_4 , V_72 ,
F_58 ( V_2 -> V_63 . V_73 ) ) ||
F_57 ( V_4 , V_81 ,
V_9 -> V_49 ) ||
F_57 ( V_4 , V_79 ,
F_58 ( V_2 -> V_63 . V_80 ) ) ||
F_57 ( V_4 , V_82 ,
V_2 -> V_63 . V_83 ) ||
F_57 ( V_4 , V_84 ,
V_2 -> V_48 ) ||
F_57 ( V_4 , V_71 ,
V_2 -> V_7 ) )
goto V_95;
if ( V_2 -> V_63 . V_78 != V_96 &&
F_57 ( V_4 , V_76 ,
F_58 ( V_2 -> V_63 . V_78 ) ) )
goto V_95;
return F_59 ( V_4 , V_93 ) ;
V_95:
return - 1 ;
}
static int F_60 ( struct V_8 * V_9 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_99 V_100 = {
. type = V_101 ,
} ;
struct V_55 * V_102 ;
V_100 . V_103 . V_104 = V_2 -> V_60 . V_104 ;
V_100 . V_103 . V_50 = V_2 -> V_50 ;
V_100 . V_103 . V_62 = V_2 -> V_60 . V_62 ;
V_100 . V_103 . V_46 = V_2 -> V_46 ;
V_100 . V_103 . V_105 = V_2 -> V_60 . V_105 ;
F_61 (pos, &q->new_flows)
V_100 . V_103 . V_106 ++ ;
F_61 (pos, &q->old_flows)
V_100 . V_103 . V_107 ++ ;
return F_62 ( V_98 , & V_100 , sizeof( V_100 ) ) ;
}
static struct V_8 * F_63 ( struct V_8 * V_9 , unsigned long V_108 )
{
return NULL ;
}
static unsigned long F_64 ( struct V_8 * V_9 , T_1 V_25 )
{
return 0 ;
}
static unsigned long F_65 ( struct V_8 * V_9 , unsigned long V_109 ,
T_1 V_25 )
{
V_9 -> V_91 &= ~ V_92 ;
return 0 ;
}
static void F_66 ( struct V_8 * V_2 , unsigned long V_110 )
{
}
static struct V_11 T_4 * * F_67 ( struct V_8 * V_9 ,
unsigned long V_110 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_110 )
return NULL ;
return & V_2 -> V_18 ;
}
static int F_68 ( struct V_8 * V_9 , unsigned long V_110 ,
struct V_3 * V_4 , struct V_111 * V_112 )
{
V_112 -> V_113 |= F_7 ( V_110 ) ;
return 0 ;
}
static int F_69 ( struct V_8 * V_9 , unsigned long V_110 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
T_1 V_32 = V_110 - 1 ;
struct V_114 V_115 = { 0 } ;
struct V_99 V_116 ;
if ( V_32 < V_2 -> V_7 ) {
const struct V_26 * V_27 = & V_2 -> V_36 [ V_32 ] ;
const struct V_3 * V_4 = V_27 -> V_28 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . type = V_117 ;
V_116 . V_118 . V_47 = V_27 -> V_47 ;
V_116 . V_118 . V_119 =
F_58 ( V_27 -> V_54 . V_119 ) ;
V_116 . V_118 . V_120 = V_27 -> V_54 . V_120 ;
V_116 . V_118 . V_121 = V_27 -> V_54 . V_121 ;
V_116 . V_118 . V_122 = V_27 -> V_54 . V_122 ;
if ( V_27 -> V_54 . V_122 ) {
T_5 V_123 = V_27 -> V_54 . V_124 -
F_70 () ;
V_116 . V_118 . V_124 = ( V_123 >= 0 ) ?
F_58 ( V_123 ) :
- F_58 ( - V_123 ) ;
}
while ( V_4 ) {
V_115 . V_37 ++ ;
V_4 = V_4 -> V_29 ;
}
V_115 . V_41 = V_2 -> V_35 [ V_32 ] ;
V_115 . V_125 = V_27 -> V_38 ;
}
if ( F_71 ( V_98 , NULL , & V_115 , 0 ) < 0 )
return - 1 ;
if ( V_32 < V_2 -> V_7 )
return F_62 ( V_98 , & V_116 , sizeof( V_116 ) ) ;
return 0 ;
}
static void F_72 ( struct V_8 * V_9 , struct V_126 * V_108 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_33 ;
if ( V_108 -> V_127 )
return;
for ( V_33 = 0 ; V_33 < V_2 -> V_7 ; V_33 ++ ) {
if ( F_22 ( & V_2 -> V_36 [ V_33 ] . V_44 ) ||
V_108 -> V_120 < V_108 -> V_128 ) {
V_108 -> V_120 ++ ;
continue;
}
if ( V_108 -> V_129 ( V_9 , V_33 + 1 , V_108 ) < 0 ) {
V_108 -> V_127 = 1 ;
break;
}
V_108 -> V_120 ++ ;
}
}
static int T_6 F_73 ( void )
{
return F_74 ( & V_130 ) ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_130 ) ;
}
