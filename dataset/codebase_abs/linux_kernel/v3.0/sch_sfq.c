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
if ( V_18 -> V_24 & F_5 ( V_25 | V_26 ) )
break;
V_19 = F_8 ( V_18 -> V_15 ) ;
if ( V_19 >= 0 &&
F_6 ( V_13 , V_18 -> V_27 * 4 + 4 + V_19 ) ) {
V_18 = F_7 ( V_13 ) ;
V_14 ^= * ( T_2 * ) ( ( void * ) V_18 + V_18 -> V_27 * 4 + V_19 ) ;
}
break;
}
case F_5 ( V_28 ) :
{
const struct V_29 * V_18 ;
int V_19 ;
if ( ! F_6 ( V_13 , sizeof( * V_18 ) ) )
goto V_20;
V_18 = F_9 ( V_13 ) ;
V_8 = ( V_21 T_2 ) V_18 -> V_22 . V_30 [ 3 ] ;
V_14 = ( V_21 T_2 ) V_18 -> V_23 . V_30 [ 3 ] ^ V_18 -> V_31 ;
V_19 = F_8 ( V_18 -> V_31 ) ;
if ( V_19 >= 0 &&
F_6 ( V_13 , sizeof( * V_18 ) + 4 + V_19 ) ) {
V_18 = F_9 ( V_13 ) ;
V_14 ^= * ( T_2 * ) ( ( void * ) V_18 + sizeof( * V_18 ) + V_19 ) ;
}
break;
}
default:
V_20:
V_8 = ( unsigned long ) F_10 ( V_13 ) ^ ( V_21 T_2 ) V_13 -> V_15 ;
V_14 = ( unsigned long ) V_13 -> V_32 ;
}
return F_2 ( V_3 , V_8 , V_14 ) ;
}
static unsigned int F_11 ( struct V_12 * V_13 , struct V_33 * V_34 ,
int * V_35 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_36 V_37 ;
int V_38 ;
if ( F_13 ( V_13 -> V_39 ) == V_34 -> V_40 &&
F_14 ( V_13 -> V_39 ) > 0 &&
F_14 ( V_13 -> V_39 ) <= V_3 -> V_11 )
return F_14 ( V_13 -> V_39 ) ;
if ( ! V_3 -> V_41 )
return F_4 ( V_3 , V_13 ) + 1 ;
* V_35 = V_42 | V_43 ;
V_38 = F_15 ( V_13 , V_3 -> V_41 , & V_37 ) ;
if ( V_38 >= 0 ) {
#ifdef F_16
switch ( V_38 ) {
case V_44 :
case V_45 :
* V_35 = V_42 | V_46 ;
case V_47 :
return 0 ;
}
#endif
if ( F_14 ( V_37 . V_48 ) <= V_3 -> V_11 )
return F_14 ( V_37 . V_48 ) ;
}
return 0 ;
}
static inline void F_17 ( struct V_2 * V_3 , T_1 V_49 )
{
T_1 V_50 , V_51 ;
int V_52 = V_3 -> V_6 [ V_49 ] . V_52 ;
V_50 = V_52 + V_5 ;
V_51 = V_3 -> V_7 [ V_52 ] . V_53 ;
V_3 -> V_6 [ V_49 ] . V_7 . V_53 = V_51 ;
V_3 -> V_6 [ V_49 ] . V_7 . V_54 = V_50 ;
V_3 -> V_7 [ V_52 ] . V_53 = V_49 ;
F_1 ( V_3 , V_51 ) -> V_54 = V_49 ;
}
static inline void F_18 ( struct V_2 * V_3 , T_1 V_49 )
{
T_1 V_50 , V_51 ;
int V_55 ;
F_19 ( V_3 , V_49 , V_51 , V_50 ) ;
V_55 = V_3 -> V_6 [ V_49 ] . V_52 -- ;
if ( V_51 == V_50 && V_3 -> V_56 == V_55 )
V_3 -> V_56 -- ;
F_17 ( V_3 , V_49 ) ;
}
static inline void F_20 ( struct V_2 * V_3 , T_1 V_49 )
{
T_1 V_50 , V_51 ;
int V_55 ;
F_19 ( V_3 , V_49 , V_51 , V_50 ) ;
V_55 = ++ V_3 -> V_6 [ V_49 ] . V_52 ;
if ( V_3 -> V_56 < V_55 )
V_3 -> V_56 = V_55 ;
F_17 ( V_3 , V_49 ) ;
}
static inline struct V_12 * F_21 ( struct V_57 * V_58 )
{
struct V_12 * V_13 = V_58 -> V_59 ;
V_58 -> V_59 = V_13 -> V_54 ;
V_13 -> V_54 -> V_53 = (struct V_12 * ) V_58 ;
V_13 -> V_53 = V_13 -> V_54 = NULL ;
return V_13 ;
}
static inline struct V_12 * F_22 ( struct V_57 * V_58 )
{
struct V_12 * V_13 = V_58 -> V_60 ;
V_58 -> V_60 = V_13 -> V_53 ;
V_13 -> V_53 -> V_54 = (struct V_12 * ) V_58 ;
V_13 -> V_53 = V_13 -> V_54 = NULL ;
return V_13 ;
}
static inline void F_23 ( struct V_57 * V_58 )
{
V_58 -> V_59 = V_58 -> V_60 = (struct V_12 * ) V_58 ;
}
static inline void F_24 ( struct V_57 * V_58 , struct V_12 * V_13 )
{
V_13 -> V_54 = V_58 -> V_59 ;
V_13 -> V_53 = (struct V_12 * ) V_58 ;
V_58 -> V_59 -> V_53 = V_13 ;
V_58 -> V_59 = V_13 ;
}
static unsigned int F_25 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
T_1 V_49 , V_55 = V_3 -> V_56 ;
struct V_12 * V_13 ;
unsigned int V_61 ;
struct V_57 * V_58 ;
if ( V_55 > 1 ) {
V_49 = V_3 -> V_7 [ V_55 ] . V_53 ;
V_58 = & V_3 -> V_6 [ V_49 ] ;
V_62:
V_13 = F_21 ( V_58 ) ;
V_61 = F_26 ( V_13 ) ;
F_18 ( V_3 , V_49 ) ;
F_27 ( V_13 ) ;
V_34 -> V_3 . V_52 -- ;
V_34 -> V_63 . V_64 ++ ;
V_34 -> V_63 . V_65 -= V_61 ;
return V_61 ;
}
if ( V_55 == 1 ) {
V_49 = V_3 -> V_66 -> V_53 ;
V_58 = & V_3 -> V_6 [ V_49 ] ;
V_3 -> V_66 -> V_53 = V_58 -> V_53 ;
V_3 -> V_67 [ V_58 -> V_68 ] = V_69 ;
goto V_62;
}
return 0 ;
}
static int
F_28 ( struct V_12 * V_13 , struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned int V_68 ;
T_1 V_49 , V_52 ;
struct V_57 * V_58 ;
int V_70 ( V_71 ) ;
V_68 = F_11 ( V_13 , V_34 , & V_71 ) ;
if ( V_68 == 0 ) {
if ( V_71 & V_43 )
V_34 -> V_63 . V_64 ++ ;
F_27 ( V_13 ) ;
return V_71 ;
}
V_68 -- ;
V_49 = V_3 -> V_67 [ V_68 ] ;
V_58 = & V_3 -> V_6 [ V_49 ] ;
if ( V_49 == V_69 ) {
V_49 = V_3 -> V_7 [ 0 ] . V_53 ;
V_3 -> V_67 [ V_68 ] = V_49 ;
V_58 = & V_3 -> V_6 [ V_49 ] ;
V_58 -> V_68 = V_68 ;
}
if ( V_58 -> V_52 >= V_3 -> V_72 )
return F_29 ( V_13 , V_34 ) ;
V_34 -> V_63 . V_65 += F_26 ( V_13 ) ;
F_24 ( V_58 , V_13 ) ;
F_20 ( V_3 , V_49 ) ;
if ( V_58 -> V_52 == 1 ) {
if ( V_3 -> V_66 == NULL ) {
V_58 -> V_53 = V_49 ;
} else {
V_58 -> V_53 = V_3 -> V_66 -> V_53 ;
V_3 -> V_66 -> V_53 = V_49 ;
}
V_3 -> V_66 = V_58 ;
V_58 -> V_73 = V_3 -> V_74 ;
}
if ( ++ V_34 -> V_3 . V_52 <= V_3 -> V_72 )
return V_42 ;
V_52 = V_58 -> V_52 ;
F_25 ( V_34 ) ;
return ( V_52 != V_58 -> V_52 ) ? V_75 : V_42 ;
}
static struct V_12 *
F_30 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_12 * V_13 ;
T_1 V_76 , V_77 ;
struct V_57 * V_58 ;
if ( V_3 -> V_66 == NULL )
return NULL ;
V_78:
V_76 = V_3 -> V_66 -> V_53 ;
V_58 = & V_3 -> V_6 [ V_76 ] ;
if ( V_58 -> V_73 <= 0 ) {
V_3 -> V_66 = V_58 ;
V_58 -> V_73 += V_3 -> V_74 ;
goto V_78;
}
V_13 = F_22 ( V_58 ) ;
F_18 ( V_3 , V_76 ) ;
F_31 ( V_34 , V_13 ) ;
V_34 -> V_3 . V_52 -- ;
V_34 -> V_63 . V_65 -= F_26 ( V_13 ) ;
if ( V_58 -> V_52 == 0 ) {
V_3 -> V_67 [ V_58 -> V_68 ] = V_69 ;
V_77 = V_58 -> V_53 ;
if ( V_76 == V_77 ) {
V_3 -> V_66 = NULL ;
return V_13 ;
}
V_3 -> V_66 -> V_53 = V_77 ;
} else {
V_58 -> V_73 -= F_32 ( F_26 ( V_13 ) ) ;
}
return V_13 ;
}
static void
F_33 ( struct V_33 * V_34 )
{
struct V_12 * V_13 ;
while ( ( V_13 = F_30 ( V_34 ) ) != NULL )
F_27 ( V_13 ) ;
}
static void F_34 ( unsigned long V_79 )
{
struct V_33 * V_34 = (struct V_33 * ) V_79 ;
struct V_2 * V_3 = F_12 ( V_34 ) ;
V_3 -> V_10 = F_35 () ;
if ( V_3 -> V_80 )
F_36 ( & V_3 -> V_81 , V_82 + V_3 -> V_80 ) ;
}
static int F_37 ( struct V_33 * V_34 , struct V_83 * V_84 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
struct V_85 * V_86 = F_38 ( V_84 ) ;
unsigned int V_52 ;
if ( V_84 -> V_87 < F_39 ( sizeof( * V_86 ) ) )
return - V_88 ;
if ( V_86 -> V_11 &&
( ! F_40 ( V_86 -> V_11 ) || V_86 -> V_11 > 65536 ) )
return - V_88 ;
F_41 ( V_34 ) ;
V_3 -> V_89 = V_86 -> V_89 ? : F_42 ( F_43 ( V_34 ) ) ;
V_3 -> V_74 = F_32 ( V_3 -> V_89 ) ;
V_3 -> V_80 = V_86 -> V_80 * V_90 ;
if ( V_86 -> V_72 )
V_3 -> V_72 = F_44 ( T_2 , V_86 -> V_72 , V_91 - 1 ) ;
if ( V_86 -> V_11 )
V_3 -> V_11 = V_86 -> V_11 ;
V_52 = V_34 -> V_3 . V_52 ;
while ( V_34 -> V_3 . V_52 > V_3 -> V_72 )
F_25 ( V_34 ) ;
F_45 ( V_34 , V_52 - V_34 -> V_3 . V_52 ) ;
F_46 ( & V_3 -> V_81 ) ;
if ( V_3 -> V_80 ) {
F_36 ( & V_3 -> V_81 , V_82 + V_3 -> V_80 ) ;
V_3 -> V_10 = F_35 () ;
}
F_47 ( V_34 ) ;
return 0 ;
}
static int F_48 ( struct V_33 * V_34 , struct V_83 * V_84 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
T_3 V_92 ;
int V_93 ;
V_3 -> V_81 . V_94 = F_34 ;
V_3 -> V_81 . V_95 = ( unsigned long ) V_34 ;
F_49 ( & V_3 -> V_81 ) ;
for ( V_93 = 0 ; V_93 < V_91 ; V_93 ++ ) {
V_3 -> V_7 [ V_93 ] . V_53 = V_93 + V_5 ;
V_3 -> V_7 [ V_93 ] . V_54 = V_93 + V_5 ;
}
V_3 -> V_72 = V_91 - 1 ;
V_3 -> V_56 = 0 ;
V_3 -> V_66 = NULL ;
V_3 -> V_11 = V_96 ;
if ( V_84 == NULL ) {
V_3 -> V_89 = F_42 ( F_43 ( V_34 ) ) ;
V_3 -> V_74 = F_32 ( V_3 -> V_89 ) ;
V_3 -> V_80 = 0 ;
V_3 -> V_10 = F_35 () ;
} else {
int V_20 = F_37 ( V_34 , V_84 ) ;
if ( V_20 )
return V_20 ;
}
V_92 = sizeof( V_3 -> V_67 [ 0 ] ) * V_3 -> V_11 ;
V_3 -> V_67 = F_50 ( V_92 , V_97 ) ;
if ( ! V_3 -> V_67 && V_92 > V_98 )
V_3 -> V_67 = F_51 ( V_92 ) ;
if ( ! V_3 -> V_67 )
return - V_99 ;
for ( V_93 = 0 ; V_93 < V_3 -> V_11 ; V_93 ++ )
V_3 -> V_67 [ V_93 ] = V_69 ;
for ( V_93 = 0 ; V_93 < V_5 ; V_93 ++ ) {
F_23 ( & V_3 -> V_6 [ V_93 ] ) ;
F_17 ( V_3 , V_93 ) ;
}
if ( V_3 -> V_72 >= 1 )
V_34 -> V_100 |= V_101 ;
else
V_34 -> V_100 &= ~ V_101 ;
return 0 ;
}
static void F_52 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
F_53 ( & V_3 -> V_41 ) ;
V_3 -> V_80 = 0 ;
F_54 ( & V_3 -> V_81 ) ;
if ( F_55 ( V_3 -> V_67 ) )
F_56 ( V_3 -> V_67 ) ;
else
F_57 ( V_3 -> V_67 ) ;
}
static int F_58 ( struct V_33 * V_34 , struct V_12 * V_13 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned char * V_102 = F_59 ( V_13 ) ;
struct V_85 V_84 ;
V_84 . V_89 = V_3 -> V_89 ;
V_84 . V_80 = V_3 -> V_80 / V_90 ;
V_84 . V_72 = V_3 -> V_72 ;
V_84 . V_11 = V_3 -> V_11 ;
V_84 . V_103 = V_3 -> V_72 ;
F_60 ( V_13 , V_104 , sizeof( V_84 ) , & V_84 ) ;
return V_13 -> V_61 ;
V_105:
F_61 ( V_13 , V_102 ) ;
return - 1 ;
}
static struct V_33 * F_62 ( struct V_33 * V_34 , unsigned long V_79 )
{
return NULL ;
}
static unsigned long F_63 ( struct V_33 * V_34 , T_2 V_48 )
{
return 0 ;
}
static unsigned long F_64 ( struct V_33 * V_34 , unsigned long V_106 ,
T_2 V_48 )
{
V_34 -> V_100 &= ~ V_101 ;
return 0 ;
}
static void F_65 ( struct V_33 * V_3 , unsigned long V_107 )
{
}
static struct V_108 * * F_66 ( struct V_33 * V_34 , unsigned long V_107 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
if ( V_107 )
return NULL ;
return & V_3 -> V_41 ;
}
static int F_67 ( struct V_33 * V_34 , unsigned long V_107 ,
struct V_12 * V_13 , struct V_109 * V_110 )
{
V_110 -> V_111 |= F_14 ( V_107 ) ;
return 0 ;
}
static int F_68 ( struct V_33 * V_34 , unsigned long V_107 ,
struct V_112 * V_55 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
T_1 V_113 = V_3 -> V_67 [ V_107 - 1 ] ;
struct V_114 V_115 = { 0 } ;
struct V_116 V_117 = { 0 } ;
struct V_12 * V_13 ;
if ( V_113 != V_69 ) {
const struct V_57 * V_58 = & V_3 -> V_6 [ V_113 ] ;
V_117 . V_73 = V_58 -> V_73 << V_118 ;
V_115 . V_52 = V_58 -> V_52 ;
F_69 (slot, skb)
V_115 . V_65 += F_26 ( V_13 ) ;
}
if ( F_70 ( V_55 , & V_115 ) < 0 )
return - 1 ;
return F_71 ( V_55 , & V_117 , sizeof( V_117 ) ) ;
}
static void F_72 ( struct V_33 * V_34 , struct V_119 * V_79 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned int V_93 ;
if ( V_79 -> V_120 )
return;
for ( V_93 = 0 ; V_93 < V_3 -> V_11 ; V_93 ++ ) {
if ( V_3 -> V_67 [ V_93 ] == V_69 ||
V_79 -> V_121 < V_79 -> V_122 ) {
V_79 -> V_121 ++ ;
continue;
}
if ( V_79 -> V_123 ( V_34 , V_93 + 1 , V_79 ) < 0 ) {
V_79 -> V_120 = 1 ;
break;
}
V_79 -> V_121 ++ ;
}
}
static int T_4 F_73 ( void )
{
return F_74 ( & V_124 ) ;
}
static void T_5 F_75 ( void )
{
F_76 ( & V_124 ) ;
}
