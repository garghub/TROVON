static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
if ( V_4 < V_5 )
return & V_3 -> V_6 [ V_4 ] . V_7 ;
return & V_3 -> V_7 [ V_4 - V_5 ] ;
}
static unsigned int F_2 ( struct V_2 * V_3 , T_2 V_8 , T_2 V_9 )
{
return F_3 ( V_8 , V_9 , V_3 -> V_10 ) & ( V_3 -> V_11 - 1 ) ;
}
static unsigned int F_4 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
T_2 V_8 , V_14 ;
switch ( V_13 -> V_15 ) {
case F_5 ( V_16 ) :
{
const struct V_17 * V_18 ;
int V_19 ;
if ( ! F_6 ( V_13 , sizeof( * V_18 ) ) )
goto V_20;
V_18 = F_7 ( V_13 ) ;
V_8 = ( V_21 T_2 ) V_18 -> V_22 ;
V_14 = ( V_21 T_2 ) V_18 -> V_23 ^ V_18 -> V_15 ;
if ( F_8 ( V_18 ) )
break;
V_19 = F_9 ( V_18 -> V_15 ) ;
if ( V_19 >= 0 &&
F_6 ( V_13 , V_18 -> V_24 * 4 + 4 + V_19 ) ) {
V_18 = F_7 ( V_13 ) ;
V_14 ^= * ( T_2 * ) ( ( void * ) V_18 + V_18 -> V_24 * 4 + V_19 ) ;
}
break;
}
case F_5 ( V_25 ) :
{
const struct V_26 * V_18 ;
int V_19 ;
if ( ! F_6 ( V_13 , sizeof( * V_18 ) ) )
goto V_20;
V_18 = F_10 ( V_13 ) ;
V_8 = ( V_21 T_2 ) V_18 -> V_22 . V_27 [ 3 ] ;
V_14 = ( V_21 T_2 ) V_18 -> V_23 . V_27 [ 3 ] ^ V_18 -> V_28 ;
V_19 = F_9 ( V_18 -> V_28 ) ;
if ( V_19 >= 0 &&
F_6 ( V_13 , sizeof( * V_18 ) + 4 + V_19 ) ) {
V_18 = F_10 ( V_13 ) ;
V_14 ^= * ( T_2 * ) ( ( void * ) V_18 + sizeof( * V_18 ) + V_19 ) ;
}
break;
}
default:
V_20:
V_8 = ( unsigned long ) F_11 ( V_13 ) ^ ( V_21 T_2 ) V_13 -> V_15 ;
V_14 = ( unsigned long ) V_13 -> V_29 ;
}
return F_2 ( V_3 , V_8 , V_14 ) ;
}
static unsigned int F_12 ( struct V_12 * V_13 , struct V_30 * V_31 ,
int * V_32 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
struct V_33 V_34 ;
int V_35 ;
if ( F_14 ( V_13 -> V_36 ) == V_31 -> V_37 &&
F_15 ( V_13 -> V_36 ) > 0 &&
F_15 ( V_13 -> V_36 ) <= V_3 -> V_11 )
return F_15 ( V_13 -> V_36 ) ;
if ( ! V_3 -> V_38 )
return F_4 ( V_3 , V_13 ) + 1 ;
* V_32 = V_39 | V_40 ;
V_35 = F_16 ( V_13 , V_3 -> V_38 , & V_34 ) ;
if ( V_35 >= 0 ) {
#ifdef F_17
switch ( V_35 ) {
case V_41 :
case V_42 :
* V_32 = V_39 | V_43 ;
case V_44 :
return 0 ;
}
#endif
if ( F_15 ( V_34 . V_45 ) <= V_3 -> V_11 )
return F_15 ( V_34 . V_45 ) ;
}
return 0 ;
}
static inline void F_18 ( struct V_2 * V_3 , T_1 V_46 )
{
T_1 V_47 , V_48 ;
int V_49 = V_3 -> V_6 [ V_46 ] . V_49 ;
V_47 = V_49 + V_5 ;
V_48 = V_3 -> V_7 [ V_49 ] . V_50 ;
V_3 -> V_6 [ V_46 ] . V_7 . V_50 = V_48 ;
V_3 -> V_6 [ V_46 ] . V_7 . V_51 = V_47 ;
V_3 -> V_7 [ V_49 ] . V_50 = V_46 ;
F_1 ( V_3 , V_48 ) -> V_51 = V_46 ;
}
static inline void F_19 ( struct V_2 * V_3 , T_1 V_46 )
{
T_1 V_47 , V_48 ;
int V_52 ;
F_20 ( V_3 , V_46 , V_48 , V_47 ) ;
V_52 = V_3 -> V_6 [ V_46 ] . V_49 -- ;
if ( V_48 == V_47 && V_3 -> V_53 == V_52 )
V_3 -> V_53 -- ;
F_18 ( V_3 , V_46 ) ;
}
static inline void F_21 ( struct V_2 * V_3 , T_1 V_46 )
{
T_1 V_47 , V_48 ;
int V_52 ;
F_20 ( V_3 , V_46 , V_48 , V_47 ) ;
V_52 = ++ V_3 -> V_6 [ V_46 ] . V_49 ;
if ( V_3 -> V_53 < V_52 )
V_3 -> V_53 = V_52 ;
F_18 ( V_3 , V_46 ) ;
}
static inline struct V_12 * F_22 ( struct V_54 * V_55 )
{
struct V_12 * V_13 = V_55 -> V_56 ;
V_55 -> V_56 = V_13 -> V_51 ;
V_13 -> V_51 -> V_50 = (struct V_12 * ) V_55 ;
V_13 -> V_50 = V_13 -> V_51 = NULL ;
return V_13 ;
}
static inline struct V_12 * F_23 ( struct V_54 * V_55 )
{
struct V_12 * V_13 = V_55 -> V_57 ;
V_55 -> V_57 = V_13 -> V_50 ;
V_13 -> V_50 -> V_51 = (struct V_12 * ) V_55 ;
V_13 -> V_50 = V_13 -> V_51 = NULL ;
return V_13 ;
}
static inline void F_24 ( struct V_54 * V_55 )
{
V_55 -> V_56 = V_55 -> V_57 = (struct V_12 * ) V_55 ;
}
static inline void F_25 ( struct V_54 * V_55 , struct V_12 * V_13 )
{
V_13 -> V_51 = V_55 -> V_56 ;
V_13 -> V_50 = (struct V_12 * ) V_55 ;
V_55 -> V_56 -> V_50 = V_13 ;
V_55 -> V_56 = V_13 ;
}
static unsigned int F_26 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
T_1 V_46 , V_52 = V_3 -> V_53 ;
struct V_12 * V_13 ;
unsigned int V_58 ;
struct V_54 * V_55 ;
if ( V_52 > 1 ) {
V_46 = V_3 -> V_7 [ V_52 ] . V_50 ;
V_55 = & V_3 -> V_6 [ V_46 ] ;
V_59:
V_13 = F_22 ( V_55 ) ;
V_58 = F_27 ( V_13 ) ;
F_19 ( V_3 , V_46 ) ;
F_28 ( V_13 ) ;
V_31 -> V_3 . V_49 -- ;
V_31 -> V_60 . V_61 ++ ;
V_31 -> V_60 . V_62 -= V_58 ;
return V_58 ;
}
if ( V_52 == 1 ) {
V_46 = V_3 -> V_63 -> V_50 ;
V_55 = & V_3 -> V_6 [ V_46 ] ;
V_3 -> V_63 -> V_50 = V_55 -> V_50 ;
V_3 -> V_64 [ V_55 -> V_65 ] = V_66 ;
goto V_59;
}
return 0 ;
}
static int
F_29 ( struct V_12 * V_13 , struct V_30 * V_31 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
unsigned int V_65 ;
T_1 V_46 , V_49 ;
struct V_54 * V_55 ;
int V_67 ( V_68 ) ;
V_65 = F_12 ( V_13 , V_31 , & V_68 ) ;
if ( V_65 == 0 ) {
if ( V_68 & V_40 )
V_31 -> V_60 . V_61 ++ ;
F_28 ( V_13 ) ;
return V_68 ;
}
V_65 -- ;
V_46 = V_3 -> V_64 [ V_65 ] ;
V_55 = & V_3 -> V_6 [ V_46 ] ;
if ( V_46 == V_66 ) {
V_46 = V_3 -> V_7 [ 0 ] . V_50 ;
V_3 -> V_64 [ V_65 ] = V_46 ;
V_55 = & V_3 -> V_6 [ V_46 ] ;
V_55 -> V_65 = V_65 ;
}
if ( V_55 -> V_49 >= V_3 -> V_69 )
return F_30 ( V_13 , V_31 ) ;
V_31 -> V_60 . V_62 += F_27 ( V_13 ) ;
F_25 ( V_55 , V_13 ) ;
F_21 ( V_3 , V_46 ) ;
if ( V_55 -> V_49 == 1 ) {
if ( V_3 -> V_63 == NULL ) {
V_55 -> V_50 = V_46 ;
} else {
V_55 -> V_50 = V_3 -> V_63 -> V_50 ;
V_3 -> V_63 -> V_50 = V_46 ;
}
V_3 -> V_63 = V_55 ;
V_55 -> V_70 = V_3 -> V_71 ;
}
if ( ++ V_31 -> V_3 . V_49 <= V_3 -> V_69 )
return V_39 ;
V_49 = V_55 -> V_49 ;
F_26 ( V_31 ) ;
if ( V_49 != V_55 -> V_49 )
return V_72 ;
F_31 ( V_31 , 1 ) ;
return V_39 ;
}
static struct V_12 *
F_32 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
struct V_12 * V_13 ;
T_1 V_73 , V_74 ;
struct V_54 * V_55 ;
if ( V_3 -> V_63 == NULL )
return NULL ;
V_75:
V_73 = V_3 -> V_63 -> V_50 ;
V_55 = & V_3 -> V_6 [ V_73 ] ;
if ( V_55 -> V_70 <= 0 ) {
V_3 -> V_63 = V_55 ;
V_55 -> V_70 += V_3 -> V_71 ;
goto V_75;
}
V_13 = F_23 ( V_55 ) ;
F_19 ( V_3 , V_73 ) ;
F_33 ( V_31 , V_13 ) ;
V_31 -> V_3 . V_49 -- ;
V_31 -> V_60 . V_62 -= F_27 ( V_13 ) ;
if ( V_55 -> V_49 == 0 ) {
V_3 -> V_64 [ V_55 -> V_65 ] = V_66 ;
V_74 = V_55 -> V_50 ;
if ( V_73 == V_74 ) {
V_3 -> V_63 = NULL ;
return V_13 ;
}
V_3 -> V_63 -> V_50 = V_74 ;
} else {
V_55 -> V_70 -= F_34 ( F_27 ( V_13 ) ) ;
}
return V_13 ;
}
static void
F_35 ( struct V_30 * V_31 )
{
struct V_12 * V_13 ;
while ( ( V_13 = F_32 ( V_31 ) ) != NULL )
F_28 ( V_13 ) ;
}
static void F_36 ( unsigned long V_76 )
{
struct V_30 * V_31 = (struct V_30 * ) V_76 ;
struct V_2 * V_3 = F_13 ( V_31 ) ;
V_3 -> V_10 = F_37 () ;
if ( V_3 -> V_77 )
F_38 ( & V_3 -> V_78 , V_79 + V_3 -> V_77 ) ;
}
static int F_39 ( struct V_30 * V_31 , struct V_80 * V_81 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
struct V_82 * V_83 = F_40 ( V_81 ) ;
unsigned int V_49 ;
if ( V_81 -> V_84 < F_41 ( sizeof( * V_83 ) ) )
return - V_85 ;
if ( V_83 -> V_11 &&
( ! F_42 ( V_83 -> V_11 ) || V_83 -> V_11 > 65536 ) )
return - V_85 ;
F_43 ( V_31 ) ;
V_3 -> V_86 = V_83 -> V_86 ? : F_44 ( F_45 ( V_31 ) ) ;
V_3 -> V_71 = F_34 ( V_3 -> V_86 ) ;
V_3 -> V_77 = V_83 -> V_77 * V_87 ;
if ( V_83 -> V_69 )
V_3 -> V_69 = F_46 ( T_2 , V_83 -> V_69 , V_88 - 1 ) ;
if ( V_83 -> V_11 )
V_3 -> V_11 = V_83 -> V_11 ;
V_49 = V_31 -> V_3 . V_49 ;
while ( V_31 -> V_3 . V_49 > V_3 -> V_69 )
F_26 ( V_31 ) ;
F_31 ( V_31 , V_49 - V_31 -> V_3 . V_49 ) ;
F_47 ( & V_3 -> V_78 ) ;
if ( V_3 -> V_77 ) {
F_38 ( & V_3 -> V_78 , V_79 + V_3 -> V_77 ) ;
V_3 -> V_10 = F_37 () ;
}
F_48 ( V_31 ) ;
return 0 ;
}
static int F_49 ( struct V_30 * V_31 , struct V_80 * V_81 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
T_3 V_89 ;
int V_90 ;
V_3 -> V_78 . V_91 = F_36 ;
V_3 -> V_78 . V_92 = ( unsigned long ) V_31 ;
F_50 ( & V_3 -> V_78 ) ;
for ( V_90 = 0 ; V_90 < V_88 ; V_90 ++ ) {
V_3 -> V_7 [ V_90 ] . V_50 = V_90 + V_5 ;
V_3 -> V_7 [ V_90 ] . V_51 = V_90 + V_5 ;
}
V_3 -> V_69 = V_88 - 1 ;
V_3 -> V_53 = 0 ;
V_3 -> V_63 = NULL ;
V_3 -> V_11 = V_93 ;
if ( V_81 == NULL ) {
V_3 -> V_86 = F_44 ( F_45 ( V_31 ) ) ;
V_3 -> V_71 = F_34 ( V_3 -> V_86 ) ;
V_3 -> V_77 = 0 ;
V_3 -> V_10 = F_37 () ;
} else {
int V_20 = F_39 ( V_31 , V_81 ) ;
if ( V_20 )
return V_20 ;
}
V_89 = sizeof( V_3 -> V_64 [ 0 ] ) * V_3 -> V_11 ;
V_3 -> V_64 = F_51 ( V_89 , V_94 ) ;
if ( ! V_3 -> V_64 && V_89 > V_95 )
V_3 -> V_64 = F_52 ( V_89 ) ;
if ( ! V_3 -> V_64 )
return - V_96 ;
for ( V_90 = 0 ; V_90 < V_3 -> V_11 ; V_90 ++ )
V_3 -> V_64 [ V_90 ] = V_66 ;
for ( V_90 = 0 ; V_90 < V_5 ; V_90 ++ ) {
F_24 ( & V_3 -> V_6 [ V_90 ] ) ;
F_18 ( V_3 , V_90 ) ;
}
if ( V_3 -> V_69 >= 1 )
V_31 -> V_97 |= V_98 ;
else
V_31 -> V_97 &= ~ V_98 ;
return 0 ;
}
static void F_53 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
F_54 ( & V_3 -> V_38 ) ;
V_3 -> V_77 = 0 ;
F_55 ( & V_3 -> V_78 ) ;
if ( F_56 ( V_3 -> V_64 ) )
F_57 ( V_3 -> V_64 ) ;
else
F_58 ( V_3 -> V_64 ) ;
}
static int F_59 ( struct V_30 * V_31 , struct V_12 * V_13 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
unsigned char * V_99 = F_60 ( V_13 ) ;
struct V_82 V_81 ;
V_81 . V_86 = V_3 -> V_86 ;
V_81 . V_77 = V_3 -> V_77 / V_87 ;
V_81 . V_69 = V_3 -> V_69 ;
V_81 . V_11 = V_3 -> V_11 ;
V_81 . V_100 = V_3 -> V_69 ;
F_61 ( V_13 , V_101 , sizeof( V_81 ) , & V_81 ) ;
return V_13 -> V_58 ;
V_102:
F_62 ( V_13 , V_99 ) ;
return - 1 ;
}
static struct V_30 * F_63 ( struct V_30 * V_31 , unsigned long V_76 )
{
return NULL ;
}
static unsigned long F_64 ( struct V_30 * V_31 , T_2 V_45 )
{
return 0 ;
}
static unsigned long F_65 ( struct V_30 * V_31 , unsigned long V_103 ,
T_2 V_45 )
{
V_31 -> V_97 &= ~ V_98 ;
return 0 ;
}
static void F_66 ( struct V_30 * V_3 , unsigned long V_104 )
{
}
static struct V_105 * * F_67 ( struct V_30 * V_31 , unsigned long V_104 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
if ( V_104 )
return NULL ;
return & V_3 -> V_38 ;
}
static int F_68 ( struct V_30 * V_31 , unsigned long V_104 ,
struct V_12 * V_13 , struct V_106 * V_107 )
{
V_107 -> V_108 |= F_15 ( V_104 ) ;
return 0 ;
}
static int F_69 ( struct V_30 * V_31 , unsigned long V_104 ,
struct V_109 * V_52 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
T_1 V_110 = V_3 -> V_64 [ V_104 - 1 ] ;
struct V_111 V_112 = { 0 } ;
struct V_113 V_114 = { 0 } ;
struct V_12 * V_13 ;
if ( V_110 != V_66 ) {
const struct V_54 * V_55 = & V_3 -> V_6 [ V_110 ] ;
V_114 . V_70 = V_55 -> V_70 << V_115 ;
V_112 . V_49 = V_55 -> V_49 ;
F_70 (slot, skb)
V_112 . V_62 += F_27 ( V_13 ) ;
}
if ( F_71 ( V_52 , & V_112 ) < 0 )
return - 1 ;
return F_72 ( V_52 , & V_114 , sizeof( V_114 ) ) ;
}
static void F_73 ( struct V_30 * V_31 , struct V_116 * V_76 )
{
struct V_2 * V_3 = F_13 ( V_31 ) ;
unsigned int V_90 ;
if ( V_76 -> V_117 )
return;
for ( V_90 = 0 ; V_90 < V_3 -> V_11 ; V_90 ++ ) {
if ( V_3 -> V_64 [ V_90 ] == V_66 ||
V_76 -> V_118 < V_76 -> V_119 ) {
V_76 -> V_118 ++ ;
continue;
}
if ( V_76 -> V_120 ( V_31 , V_90 + 1 , V_76 ) < 0 ) {
V_76 -> V_117 = 1 ;
break;
}
V_76 -> V_118 ++ ;
}
}
static int T_4 F_74 ( void )
{
return F_75 ( & V_121 ) ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_121 ) ;
}
