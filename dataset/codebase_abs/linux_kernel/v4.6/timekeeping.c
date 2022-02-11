static inline void F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 . V_4 >= ( ( V_5 ) V_6 << V_2 -> V_3 . V_7 ) ) {
V_2 -> V_3 . V_4 -= ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
V_2 -> V_8 ++ ;
}
}
static inline struct V_9 F_2 ( struct V_1 * V_2 )
{
struct V_9 V_10 ;
V_10 . V_11 = V_2 -> V_8 ;
V_10 . V_12 = ( long ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
return V_10 ;
}
static void F_3 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
V_2 -> V_8 = V_10 -> V_11 ;
V_2 -> V_3 . V_4 = ( V_5 ) V_10 -> V_12 << V_2 -> V_3 . V_7 ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
V_2 -> V_8 += V_10 -> V_11 ;
V_2 -> V_3 . V_4 += ( V_5 ) V_10 -> V_12 << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_9 V_13 )
{
struct V_9 V_14 ;
F_6 ( & V_14 , - V_2 -> V_15 . V_11 ,
- V_2 -> V_15 . V_12 ) ;
F_7 ( V_2 -> V_16 . V_17 != F_8 ( V_14 ) . V_17 ) ;
V_2 -> V_15 = V_13 ;
F_6 ( & V_14 , - V_13 . V_11 , - V_13 . V_12 ) ;
V_2 -> V_16 = F_8 ( V_14 ) ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_2 -> V_19 , 0 ) ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_20 )
{
V_2 -> V_21 = F_9 ( V_2 -> V_21 , V_20 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_2 V_22 )
{
T_2 V_23 = V_2 -> V_3 . clock -> V_23 ;
const char * V_24 = V_2 -> V_3 . clock -> V_24 ;
if ( V_22 > V_23 ) {
F_13 ( L_1 ,
V_22 , V_24 , V_23 ) ;
F_13 ( L_2 ) ;
} else {
if ( V_22 > ( V_23 >> 1 ) ) {
F_13 ( L_3 ,
V_22 , V_24 , V_23 >> 1 ) ;
F_13 ( L_4 ) ;
}
}
if ( V_2 -> V_25 ) {
if ( V_26 - V_2 -> V_27 > V_28 ) {
F_13 ( L_5 , V_24 ) ;
F_13 ( L_6 ) ;
F_13 ( L_7 ) ;
V_2 -> V_27 = V_26 ;
}
V_2 -> V_25 = 0 ;
}
if ( V_2 -> V_29 ) {
if ( V_26 - V_2 -> V_27 > V_28 ) {
F_13 ( L_8 , V_24 ) ;
F_13 ( L_6 ) ;
F_13 ( L_7 ) ;
V_2 -> V_27 = V_26 ;
}
V_2 -> V_29 = 0 ;
}
}
static inline T_2 F_14 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
T_2 V_33 , V_34 , V_35 , V_36 , V_20 ;
unsigned int V_37 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_33 = V_31 -> V_38 ( V_31 -> clock ) ;
V_34 = V_31 -> V_39 ;
V_35 = V_31 -> V_35 ;
V_36 = V_31 -> clock -> V_23 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_20 = F_17 ( V_33 , V_34 , V_35 ) ;
if ( F_18 ( ( ~ V_20 & V_35 ) < ( V_35 >> 3 ) ) ) {
V_2 -> V_25 = 1 ;
V_20 = 0 ;
}
if ( F_18 ( V_20 > V_36 ) ) {
V_2 -> V_29 = 1 ;
V_20 = V_31 -> clock -> V_23 ;
}
return V_20 ;
}
static inline void F_12 ( struct V_1 * V_2 , T_2 V_22 )
{
}
static inline T_2 F_14 ( struct V_30 * V_31 )
{
T_2 V_40 , V_20 ;
V_40 = V_31 -> V_38 ( V_31 -> clock ) ;
V_20 = F_17 ( V_40 , V_31 -> V_39 , V_31 -> V_35 ) ;
return V_20 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_41 * clock )
{
T_2 V_42 ;
V_5 V_14 , V_43 ;
struct V_41 * V_44 ;
++ V_2 -> V_45 ;
V_44 = V_2 -> V_3 . clock ;
V_2 -> V_3 . clock = clock ;
V_2 -> V_3 . V_38 = clock -> V_38 ;
V_2 -> V_3 . V_35 = clock -> V_35 ;
V_2 -> V_3 . V_39 = V_2 -> V_3 . V_38 ( clock ) ;
V_2 -> V_46 . clock = clock ;
V_2 -> V_46 . V_38 = clock -> V_38 ;
V_2 -> V_46 . V_35 = clock -> V_35 ;
V_2 -> V_46 . V_39 = V_2 -> V_3 . V_39 ;
V_14 = V_47 ;
V_14 <<= clock -> V_7 ;
V_43 = V_14 ;
V_14 += clock -> V_48 / 2 ;
F_20 ( V_14 , clock -> V_48 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
V_42 = ( T_2 ) V_14 ;
V_2 -> V_49 = V_42 ;
V_2 -> V_50 = ( V_5 ) V_42 * clock -> V_48 ;
V_2 -> V_51 = V_43 - V_2 -> V_50 ;
V_2 -> V_52 =
( ( V_5 ) V_42 * clock -> V_48 ) >> clock -> V_7 ;
if ( V_44 ) {
int V_53 = clock -> V_7 - V_44 -> V_7 ;
if ( V_53 < 0 )
V_2 -> V_3 . V_4 >>= - V_53 ;
else
V_2 -> V_3 . V_4 <<= V_53 ;
}
V_2 -> V_46 . V_4 = 0 ;
V_2 -> V_3 . V_7 = clock -> V_7 ;
V_2 -> V_46 . V_7 = clock -> V_7 ;
V_2 -> V_54 = 0 ;
V_2 -> V_55 = V_56 - clock -> V_7 ;
V_2 -> V_57 = V_43 << V_2 -> V_55 ;
V_2 -> V_3 . V_48 = clock -> V_48 ;
V_2 -> V_46 . V_48 = clock -> V_48 ;
V_2 -> V_58 = 0 ;
}
static T_3 F_21 ( void ) { return 0 ; }
static inline T_3 F_22 ( void ) { return 0 ; }
static inline T_4 F_23 ( struct V_30 * V_31 ,
T_2 V_20 )
{
T_4 V_59 ;
V_59 = V_20 * V_31 -> V_48 + V_31 -> V_4 ;
V_59 >>= V_31 -> V_7 ;
return V_59 + F_22 () ;
}
static inline T_4 F_24 ( struct V_30 * V_31 )
{
T_2 V_20 ;
V_20 = F_14 ( V_31 ) ;
return F_23 ( V_31 , V_20 ) ;
}
static inline T_4 F_25 ( struct V_30 * V_31 ,
T_2 V_60 )
{
T_2 V_20 ;
V_20 = F_17 ( V_60 , V_31 -> V_39 , V_31 -> V_35 ) ;
return F_23 ( V_31 , V_20 ) ;
}
static void F_26 ( struct V_30 * V_31 , struct V_61 * V_62 )
{
struct V_30 * V_63 = V_62 -> V_63 ;
F_27 ( & V_62 -> V_37 ) ;
memcpy ( V_63 , V_31 , sizeof( * V_63 ) ) ;
F_27 ( & V_62 -> V_37 ) ;
memcpy ( V_63 + 1 , V_63 , sizeof( * V_63 ) ) ;
}
static T_5 V_5 F_28 ( struct V_61 * V_62 )
{
struct V_30 * V_31 ;
unsigned int V_37 ;
V_5 V_33 ;
do {
V_37 = F_29 ( & V_62 -> V_37 ) ;
V_31 = V_62 -> V_63 + ( V_37 & 0x01 ) ;
V_33 = F_30 ( V_31 -> V_63 ) + F_24 ( V_31 ) ;
} while ( F_16 ( & V_62 -> V_37 , V_37 ) );
return V_33 ;
}
V_5 F_31 ( void )
{
return F_28 ( & V_64 ) ;
}
V_5 F_32 ( void )
{
return F_28 ( & V_65 ) ;
}
static T_2 F_33 ( struct V_41 * V_66 )
{
return V_67 ;
}
static void F_34 ( struct V_1 * V_2 )
{
static struct V_30 V_68 ;
struct V_30 * V_31 = & V_2 -> V_3 ;
memcpy ( & V_68 , V_31 , sizeof( V_68 ) ) ;
V_67 = V_31 -> V_38 ( V_31 -> clock ) ;
V_68 . V_38 = F_33 ;
F_26 ( & V_68 , & V_64 ) ;
V_31 = & V_2 -> V_46 ;
memcpy ( & V_68 , V_31 , sizeof( V_68 ) ) ;
V_68 . V_38 = F_33 ;
F_26 ( & V_68 , & V_65 ) ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
struct V_69 V_70 , V_71 ;
V_70 = F_36 ( F_2 ( V_2 ) ) ;
V_71 = F_36 ( V_2 -> V_15 ) ;
F_37 ( & V_70 , & V_71 , V_2 -> V_3 . clock , V_2 -> V_3 . V_48 ,
V_2 -> V_3 . V_39 ) ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
T_4 V_72 ;
V_72 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
V_2 -> V_3 . V_4 -= V_72 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_54 += V_72 << V_2 -> V_55 ;
V_2 -> V_54 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_55 ;
}
static void F_39 ( struct V_1 * V_2 , bool V_73 )
{
F_40 ( & V_74 , V_73 , V_2 ) ;
}
int F_41 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_77 ;
int V_78 ;
F_42 ( & V_79 , V_77 ) ;
V_78 = F_43 ( & V_74 , V_76 ) ;
F_39 ( V_2 , true ) ;
F_44 ( & V_79 , V_77 ) ;
return V_78 ;
}
int F_45 ( struct V_75 * V_76 )
{
unsigned long V_77 ;
int V_78 ;
F_42 ( & V_79 , V_77 ) ;
V_78 = F_46 ( & V_74 , V_76 ) ;
F_44 ( & V_79 , V_77 ) ;
return V_78 ;
}
static inline void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_80 = F_48 () ;
if ( V_2 -> V_80 . V_17 != V_81 )
V_2 -> V_80 = F_49 ( V_2 -> V_80 , V_2 -> V_16 ) ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
V_5 V_82 ;
T_3 V_59 ;
V_82 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_59 = ( T_3 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_63 = F_51 ( V_82 * V_6 + V_59 ) ;
V_2 -> V_46 . V_63 = F_8 ( V_2 -> V_83 ) ;
V_59 += ( T_3 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_59 >= V_6 )
V_82 ++ ;
V_2 -> V_84 = V_82 ;
}
static void F_52 ( struct V_1 * V_2 , unsigned int V_85 )
{
if ( V_85 & V_86 ) {
V_2 -> V_54 = 0 ;
F_53 () ;
}
F_47 ( V_2 ) ;
F_50 ( V_2 ) ;
F_35 ( V_2 ) ;
F_39 ( V_2 , V_85 & V_87 ) ;
F_26 ( & V_2 -> V_3 , & V_64 ) ;
F_26 ( & V_2 -> V_46 , & V_65 ) ;
if ( V_85 & V_87 )
V_2 -> V_88 ++ ;
if ( V_85 & V_89 )
memcpy ( & V_90 , & V_32 . V_1 ,
sizeof( V_32 . V_1 ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_41 * clock = V_2 -> V_3 . clock ;
T_2 V_40 , V_20 ;
T_4 V_59 ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
V_20 = F_17 ( V_40 , V_2 -> V_3 . V_39 , V_2 -> V_3 . V_35 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_46 . V_39 = V_40 ;
V_2 -> V_3 . V_4 += V_20 * V_2 -> V_3 . V_48 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_22 () << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
V_59 = F_55 ( V_20 , V_2 -> V_46 . V_48 , V_2 -> V_46 . V_7 ) ;
F_56 ( & V_2 -> V_83 , V_59 ) ;
}
int F_57 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
T_4 V_91 = 0 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_91 = F_24 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_10 -> V_12 = 0 ;
F_56 ( V_10 , V_91 ) ;
if ( F_18 ( V_92 ) )
return - V_93 ;
return 0 ;
}
void F_58 ( struct V_9 * V_10 )
{
F_59 ( F_57 ( V_10 ) ) ;
}
T_1 F_60 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_63 ;
T_4 V_91 ;
F_59 ( V_92 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_63 = V_2 -> V_3 . V_63 ;
V_91 = F_24 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_61 ( V_63 , V_91 ) ;
}
T_3 F_62 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_3 V_91 ;
F_59 ( V_92 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_91 = V_2 -> V_3 . V_48 >> V_2 -> V_3 . V_7 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_91 ;
}
T_1 F_63 ( enum V_94 V_95 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_63 , * V_22 = V_96 [ V_95 ] ;
T_4 V_91 ;
F_59 ( V_92 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_63 = F_9 ( V_2 -> V_3 . V_63 , * V_22 ) ;
V_91 = F_24 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_61 ( V_63 , V_91 ) ;
}
T_1 F_64 ( T_1 V_97 , enum V_94 V_95 )
{
T_1 * V_22 = V_96 [ V_95 ] ;
unsigned long V_37 ;
T_1 V_98 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_98 = F_9 ( V_97 , * V_22 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_98 ;
}
T_1 F_65 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_63 ;
T_4 V_91 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_63 = V_2 -> V_46 . V_63 ;
V_91 = F_24 ( & V_2 -> V_46 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_61 ( V_63 , V_91 ) ;
}
void F_66 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_99 ;
T_4 V_59 ;
unsigned int V_37 ;
F_59 ( V_92 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_59 = F_24 ( & V_2 -> V_3 ) ;
V_99 = V_2 -> V_15 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_10 -> V_11 += V_99 . V_11 ;
V_10 -> V_12 = 0 ;
F_56 ( V_10 , V_59 + V_99 . V_12 ) ;
}
T_6 F_67 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
F_59 ( V_92 ) ;
return V_2 -> V_84 ;
}
T_6 F_68 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
T_6 V_82 ;
unsigned int V_37 ;
if ( F_69 ( V_100 ) )
return V_2 -> V_8 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_82 = V_2 -> V_8 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_82 ;
}
T_6 F_70 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return V_2 -> V_8 ;
}
void F_71 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
T_1 V_103 ;
T_1 V_104 ;
T_4 V_105 ;
T_4 V_106 ;
T_2 V_33 ;
F_7 ( V_92 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_33 = V_2 -> V_3 . V_38 ( V_2 -> V_3 . clock ) ;
V_102 -> V_45 = V_2 -> V_45 ;
V_102 -> V_88 = V_2 -> V_88 ;
V_104 = F_9 ( V_2 -> V_3 . V_63 ,
V_32 . V_1 . V_16 ) ;
V_103 = V_2 -> V_46 . V_63 ;
V_106 = F_25 ( & V_2 -> V_3 , V_33 ) ;
V_105 = F_25 ( & V_2 -> V_46 , V_33 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_102 -> V_60 = V_33 ;
V_102 -> V_107 = F_61 ( V_104 , V_106 ) ;
V_102 -> V_108 = F_61 ( V_103 , V_105 ) ;
}
static int F_72 ( V_5 V_48 , V_5 div , V_5 * V_63 )
{
V_5 V_14 , V_109 ;
V_14 = F_73 ( * V_63 , div , & V_109 ) ;
if ( ( ( int ) sizeof( V_5 ) * 8 - F_74 ( V_48 ) < F_74 ( V_14 ) ) ||
( ( int ) sizeof( V_5 ) * 8 - F_74 ( V_48 ) < F_74 ( V_109 ) ) )
return - V_110 ;
V_14 *= V_48 ;
V_109 *= V_48 ;
F_20 ( V_109 , div ) ;
* V_63 = V_14 + V_109 ;
return 0 ;
}
static int F_75 ( struct V_101 * V_111 ,
T_2 V_112 ,
T_2 V_113 ,
bool V_114 ,
struct V_115 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
V_5 V_116 , V_117 ;
bool V_118 ;
int V_78 ;
if ( V_113 == 0 || V_112 == 0 )
return 0 ;
V_118 = V_112 > V_113 / 2 ?
true : false ;
V_112 = V_118 ?
V_113 - V_112 :
V_112 ;
V_116 = ( V_5 ) F_30 (
F_49 ( V_10 -> V_119 , V_111 -> V_108 ) ) ;
V_78 = F_72 ( V_112 ,
V_113 , & V_116 ) ;
if ( V_78 )
return V_78 ;
if ( V_114 ) {
V_117 = F_76
( V_116 , V_2 -> V_3 . V_48 , V_2 -> V_46 . V_48 ) ;
} else {
V_117 = ( V_5 ) F_30 (
F_49 ( V_10 -> V_120 , V_111 -> V_107 ) ) ;
V_78 = F_72 ( V_112 ,
V_113 , & V_117 ) ;
if ( V_78 )
return V_78 ;
}
if ( V_118 ) {
V_10 -> V_119 = F_61 ( V_111 -> V_108 , V_116 ) ;
V_10 -> V_120 = F_61 ( V_111 -> V_107 , V_117 ) ;
} else {
V_10 -> V_119 = F_77 ( V_10 -> V_119 , V_116 ) ;
V_10 -> V_120 = F_77 ( V_10 -> V_120 , V_117 ) ;
}
return 0 ;
}
static bool F_78 ( T_2 V_121 , T_2 V_122 , T_2 V_123 )
{
if ( V_122 > V_121 && V_122 < V_123 )
return true ;
if ( V_122 < V_121 && V_121 > V_123 )
return true ;
return false ;
}
int F_79 ( int (* F_80)
( T_1 * V_124 ,
struct V_125 * V_126 ,
void * V_127 ) ,
void * V_127 ,
struct V_101 * V_128 ,
struct V_115 * V_129 )
{
struct V_125 V_130 ;
struct V_1 * V_2 = & V_32 . V_1 ;
T_2 V_60 , V_33 , V_131 ;
unsigned int V_88 = 0 ;
T_1 V_104 , V_103 ;
T_4 V_106 , V_105 ;
T_7 V_45 ;
unsigned long V_37 ;
bool V_132 ;
int V_78 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_78 = F_80 ( & V_129 -> V_133 , & V_130 , V_127 ) ;
if ( V_78 )
return V_78 ;
if ( V_2 -> V_3 . clock != V_130 . V_66 )
return - V_134 ;
V_60 = V_130 . V_60 ;
V_33 = V_2 -> V_3 . V_38 ( V_2 -> V_3 . clock ) ;
V_131 = V_2 -> V_3 . V_39 ;
if ( ! F_78 ( V_131 , V_60 , V_33 ) ) {
V_88 = V_2 -> V_88 ;
V_45 = V_2 -> V_45 ;
V_60 = V_131 ;
V_132 = true ;
} else {
V_132 = false ;
}
V_104 = F_9 ( V_2 -> V_3 . V_63 ,
V_32 . V_1 . V_16 ) ;
V_103 = V_2 -> V_46 . V_63 ;
V_106 = F_25 ( & V_2 -> V_3 ,
V_130 . V_60 ) ;
V_105 = F_25 ( & V_2 -> V_46 ,
V_130 . V_60 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_129 -> V_120 = F_61 ( V_104 , V_106 ) ;
V_129 -> V_119 = F_61 ( V_103 , V_105 ) ;
if ( V_132 ) {
T_2 V_112 , V_113 ;
bool V_114 ;
if ( ! V_128 ||
! F_78 ( V_128 -> V_60 ,
V_130 . V_60 , V_60 ) ||
V_128 -> V_45 != V_45 )
return - V_135 ;
V_112 = V_60 - V_130 . V_60 ;
V_113 = V_60 - V_128 -> V_60 ;
V_114 =
V_128 -> V_88 != V_88 ;
V_78 = F_75 ( V_128 ,
V_112 ,
V_113 ,
V_114 , V_129 ) ;
if ( V_78 )
return V_78 ;
}
return 0 ;
}
void F_81 ( struct V_136 * V_137 )
{
struct V_9 V_33 ;
F_58 ( & V_33 ) ;
V_137 -> V_11 = V_33 . V_11 ;
V_137 -> V_138 = V_33 . V_12 / 1000 ;
}
int F_82 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_139 , V_70 ;
unsigned long V_77 ;
int V_78 = 0 ;
if ( ! F_83 ( V_10 ) )
return - V_135 ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_54 ( V_2 ) ;
V_70 = F_2 ( V_2 ) ;
V_139 . V_11 = V_10 -> V_11 - V_70 . V_11 ;
V_139 . V_12 = V_10 -> V_12 - V_70 . V_12 ;
if ( F_85 ( & V_2 -> V_15 , & V_139 ) > 0 ) {
V_78 = - V_135 ;
goto V_140;
}
F_5 ( V_2 , F_86 ( V_2 -> V_15 , V_139 ) ) ;
F_3 ( V_2 , V_10 ) ;
V_140:
F_52 ( V_2 , V_86 | V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
F_88 () ;
return V_78 ;
}
int F_89 ( struct V_69 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_77 ;
struct V_9 V_141 , V_14 ;
int V_78 = 0 ;
if ( ! F_90 ( V_10 ) )
return - V_135 ;
V_141 = F_91 ( * V_10 ) ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_54 ( V_2 ) ;
V_14 = F_92 ( F_2 ( V_2 ) , V_141 ) ;
if ( F_85 ( & V_2 -> V_15 , & V_141 ) > 0 ||
! F_83 ( & V_14 ) ) {
V_78 = - V_135 ;
goto error;
}
F_4 ( V_2 , & V_141 ) ;
F_5 ( V_2 , F_86 ( V_2 -> V_15 , V_141 ) ) ;
error:
F_52 ( V_2 , V_86 | V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
F_88 () ;
return V_78 ;
}
T_8 F_93 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_8 V_78 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_78 = V_2 -> V_19 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_78 ;
}
static void F_94 ( struct V_1 * V_2 , T_8 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_95 ( T_8 V_19 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_77 ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_94 ( V_2 , V_19 ) ;
F_52 ( V_2 , V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
F_88 () ;
}
static int F_96 ( void * V_142 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * V_143 , * V_144 ;
unsigned long V_77 ;
V_143 = (struct V_41 * ) V_142 ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_54 ( V_2 ) ;
if ( F_97 ( V_143 -> V_145 ) ) {
if ( ! V_143 -> V_146 || V_143 -> V_146 ( V_143 ) == 0 ) {
V_144 = V_2 -> V_3 . clock ;
F_19 ( V_2 , V_143 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 ( V_144 ) ;
F_98 ( V_144 -> V_145 ) ;
} else {
F_98 ( V_143 -> V_145 ) ;
}
}
F_52 ( V_2 , V_86 | V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
return 0 ;
}
int F_99 ( struct V_41 * clock )
{
struct V_1 * V_2 = & V_32 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_100 ( F_96 , clock , NULL ) ;
F_101 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_102 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_141 ;
unsigned long V_37 ;
T_4 V_91 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_91 = F_24 ( & V_2 -> V_46 ) ;
V_141 = V_2 -> V_83 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
F_56 ( & V_141 , V_91 ) ;
* V_10 = V_141 ;
}
int F_103 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
int V_78 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_78 = V_2 -> V_3 . clock -> V_77 & V_148 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_78 ;
}
V_5 F_104 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
V_5 V_78 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_78 = V_2 -> V_3 . clock -> V_149 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_78 ;
}
void __weak F_105 ( struct V_69 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_106 ( struct V_9 * V_141 )
{
struct V_69 V_10 ;
F_105 ( & V_10 ) ;
* V_141 = F_91 ( V_10 ) ;
}
void __weak F_107 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_9 F_108 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * clock ;
unsigned long V_77 ;
struct V_9 V_33 , V_150 , V_14 ;
F_106 ( & V_33 ) ;
if ( ! F_83 ( & V_33 ) ) {
F_109 ( L_9
L_10 ) ;
V_33 . V_11 = 0 ;
V_33 . V_12 = 0 ;
} else if ( V_33 . V_11 || V_33 . V_12 )
V_151 = true ;
F_107 ( & V_150 ) ;
if ( ! F_83 ( & V_150 ) ) {
F_109 ( L_11
L_10 ) ;
V_150 . V_11 = 0 ;
V_150 . V_12 = 0 ;
}
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_110 () ;
clock = F_111 () ;
if ( clock -> V_146 )
clock -> V_146 ( clock ) ;
F_19 ( V_2 , clock ) ;
F_3 ( V_2 , & V_33 ) ;
V_2 -> V_83 . V_11 = 0 ;
V_2 -> V_83 . V_12 = 0 ;
if ( V_150 . V_11 == 0 && V_150 . V_12 == 0 )
V_150 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_150 . V_11 , - V_150 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_52 ( V_2 , V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_83 ( V_20 ) ) {
F_13 ( V_152
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_86 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_113 ( V_20 ) ;
}
bool F_114 ( void )
{
return V_153 ;
}
bool F_115 ( void )
{
return V_151 ;
}
void F_116 ( struct V_9 * V_20 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_77 ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_54 ( V_2 ) ;
F_112 ( V_2 , V_20 ) ;
F_52 ( V_2 , V_86 | V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
F_88 () ;
}
void F_117 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * clock = V_2 -> V_3 . clock ;
unsigned long V_77 ;
struct V_9 V_154 , V_139 ;
T_2 V_40 , V_155 ;
V_153 = false ;
F_106 ( & V_154 ) ;
F_118 () ;
F_119 () ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
if ( ( clock -> V_77 & V_156 ) &&
V_40 > V_2 -> V_3 . V_39 ) {
V_5 V_157 , V_36 = V_158 ;
T_3 V_48 = clock -> V_48 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_59 = 0 ;
V_155 = F_17 ( V_40 , V_2 -> V_3 . V_39 ,
V_2 -> V_3 . V_35 ) ;
F_20 ( V_36 , V_48 ) ;
if ( V_155 > V_36 ) {
V_157 = F_120 ( V_155 , V_36 ) ;
V_59 = ( ( ( V_5 ) V_36 * V_48 ) >> V_7 ) * V_157 ;
V_155 -= V_157 * V_36 ;
}
V_59 += ( ( V_5 ) V_155 * V_48 ) >> V_7 ;
V_139 = F_121 ( V_59 ) ;
V_153 = true ;
} else if ( F_85 ( & V_154 , & V_159 ) > 0 ) {
V_139 = F_86 ( V_154 , V_159 ) ;
V_153 = true ;
}
if ( V_153 )
F_112 ( V_2 , & V_139 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_46 . V_39 = V_40 ;
V_2 -> V_54 = 0 ;
V_92 = 0 ;
F_52 ( V_2 , V_89 | V_87 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
F_122 () ;
F_123 () ;
F_124 () ;
}
int F_125 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_77 ;
struct V_9 V_20 , V_160 ;
static struct V_9 V_161 ;
F_106 ( & V_159 ) ;
if ( V_159 . V_11 || V_159 . V_12 )
V_151 = true ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_54 ( V_2 ) ;
V_92 = 1 ;
if ( V_151 ) {
V_20 = F_86 ( F_2 ( V_2 ) , V_159 ) ;
V_160 = F_86 ( V_20 , V_161 ) ;
if ( abs ( V_160 . V_11 ) >= 2 ) {
V_161 = V_20 ;
} else {
V_159 =
F_92 ( V_159 , V_160 ) ;
}
}
F_52 ( V_2 , V_89 ) ;
F_34 ( V_2 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
F_126 () ;
F_127 () ;
F_128 () ;
return 0 ;
}
static int T_9 F_129 ( void )
{
F_130 ( & V_162 ) ;
return 0 ;
}
static T_5 void F_131 ( struct V_1 * V_2 ,
T_4 V_22 ,
bool V_163 ,
int V_164 )
{
T_4 V_42 = V_2 -> V_49 ;
T_8 V_165 = 1 ;
if ( V_163 ) {
V_165 = - V_165 ;
V_42 = - V_42 ;
V_22 = - V_22 ;
}
V_165 <<= V_164 ;
V_42 <<= V_164 ;
V_22 <<= V_164 ;
if ( ( V_165 > 0 ) && ( V_2 -> V_3 . V_48 + V_165 < V_165 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_48 += V_165 ;
V_2 -> V_50 += V_42 ;
V_2 -> V_3 . V_4 -= V_22 ;
V_2 -> V_54 -= ( V_42 - V_22 ) << V_2 -> V_55 ;
}
static T_5 void F_132 ( struct V_1 * V_2 ,
T_4 V_22 )
{
T_4 V_42 = V_2 -> V_49 ;
T_4 V_166 = V_2 -> V_50 ;
T_3 V_63 = V_2 -> V_3 . clock -> V_48 ;
T_3 V_36 = V_2 -> V_3 . clock -> V_167 ;
T_3 V_168 = V_2 -> V_3 . V_48 ;
T_4 V_169 ;
bool V_163 ;
T_3 V_164 ;
if ( V_2 -> V_58 )
V_166 -= V_2 -> V_49 ;
V_2 -> V_57 = F_133 () ;
V_169 = F_133 () >> V_2 -> V_55 ;
V_169 -= ( V_166 + V_2 -> V_51 ) ;
if ( F_134 ( ( V_169 >= 0 ) && ( V_169 <= V_42 ) ) )
return;
V_163 = ( V_169 < 0 ) ;
if ( V_163 && ( V_168 - 1 ) <= ( V_63 - V_36 ) )
return;
if ( ! V_163 && ( V_168 + 1 ) >= ( V_63 + V_36 ) )
return;
V_164 = 0 ;
V_169 = abs ( V_169 ) ;
while ( V_169 > V_42 ) {
T_3 V_170 = 1 << ( V_164 + 1 ) ;
if ( V_163 && ( V_168 - V_170 ) <= ( V_63 - V_36 ) )
break;
if ( ! V_163 && ( V_168 + V_170 ) >= ( V_63 + V_36 ) )
break;
V_164 ++ ;
V_169 >>= 1 ;
}
F_131 ( V_2 , V_22 , V_163 , V_164 ) ;
}
static void F_135 ( struct V_1 * V_2 , T_4 V_22 )
{
F_132 ( V_2 , V_22 ) ;
if ( ! V_2 -> V_58 && ( V_2 -> V_54 > 0 ) ) {
V_2 -> V_58 = 1 ;
F_131 ( V_2 , V_22 , 0 , 0 ) ;
} else if ( V_2 -> V_58 && ( V_2 -> V_54 <= 0 ) ) {
F_131 ( V_2 , V_22 , 1 , 0 ) ;
V_2 -> V_58 = 0 ;
}
if ( F_18 ( V_2 -> V_3 . clock -> V_167 &&
( abs ( V_2 -> V_3 . V_48 - V_2 -> V_3 . clock -> V_48 )
> V_2 -> V_3 . clock -> V_167 ) ) ) {
F_136 ( V_152
L_14 ,
V_2 -> V_3 . clock -> V_24 , ( long ) V_2 -> V_3 . V_48 ,
( long ) V_2 -> V_3 . clock -> V_48 + V_2 -> V_3 . clock -> V_167 ) ;
}
if ( F_18 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_171 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_54 += V_171 << V_2 -> V_55 ;
}
}
static inline unsigned int F_137 ( struct V_1 * V_2 )
{
V_5 V_172 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_173 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_172 ) {
int V_174 ;
V_2 -> V_3 . V_4 -= V_172 ;
V_2 -> V_8 ++ ;
V_174 = F_138 ( V_2 -> V_8 ) ;
if ( F_18 ( V_174 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_174 ;
V_10 . V_11 = V_174 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_86 ( V_2 -> V_15 , V_10 ) ) ;
F_94 ( V_2 , V_2 -> V_19 - V_174 ) ;
V_173 = V_87 ;
}
}
return V_173 ;
}
static T_2 F_139 ( struct V_1 * V_2 , T_2 V_22 ,
T_3 V_7 ,
unsigned int * V_173 )
{
T_2 V_42 = V_2 -> V_49 << V_7 ;
V_5 V_175 ;
if ( V_22 < V_42 )
return V_22 ;
V_22 -= V_42 ;
V_2 -> V_3 . V_39 += V_42 ;
V_2 -> V_46 . V_39 += V_42 ;
V_2 -> V_3 . V_4 += V_2 -> V_50 << V_7 ;
* V_173 |= F_137 ( V_2 ) ;
V_175 = ( V_5 ) V_2 -> V_52 << V_7 ;
V_175 += V_2 -> V_83 . V_12 ;
if ( V_175 >= V_6 ) {
V_5 V_176 = V_175 ;
V_175 = F_20 ( V_176 , V_6 ) ;
V_2 -> V_83 . V_11 += V_176 ;
}
V_2 -> V_83 . V_12 = V_175 ;
V_2 -> V_54 += V_2 -> V_57 << V_7 ;
V_2 -> V_54 -= ( V_2 -> V_50 + V_2 -> V_51 ) <<
( V_2 -> V_55 + V_7 ) ;
return V_22 ;
}
void F_140 ( void )
{
struct V_1 * V_177 = & V_32 . V_1 ;
struct V_1 * V_2 = & V_90 ;
T_2 V_22 ;
int V_7 = 0 , V_178 ;
unsigned int V_173 = 0 ;
unsigned long V_77 ;
F_42 ( & V_79 , V_77 ) ;
if ( F_18 ( V_92 ) )
goto V_140;
#ifdef F_141
V_22 = V_177 -> V_49 ;
#else
V_22 = F_17 ( V_2 -> V_3 . V_38 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_39 , V_2 -> V_3 . V_35 ) ;
#endif
if ( V_22 < V_177 -> V_49 )
goto V_140;
F_12 ( V_177 , V_22 ) ;
V_7 = F_142 ( V_22 ) - F_142 ( V_2 -> V_49 ) ;
V_7 = V_36 ( 0 , V_7 ) ;
V_178 = ( 64 - ( F_142 ( F_133 () ) + 1 ) ) - 1 ;
V_7 = F_143 ( V_7 , V_178 ) ;
while ( V_22 >= V_2 -> V_49 ) {
V_22 = F_139 ( V_2 , V_22 , V_7 ,
& V_173 ) ;
if ( V_22 < V_2 -> V_49 << V_7 )
V_7 -- ;
}
F_135 ( V_2 , V_22 ) ;
F_38 ( V_2 ) ;
V_173 |= F_137 ( V_2 ) ;
F_84 ( & V_32 . V_37 ) ;
F_52 ( V_2 , V_173 ) ;
memcpy ( V_177 , V_2 , sizeof( * V_2 ) ) ;
F_87 ( & V_32 . V_37 ) ;
V_140:
F_44 ( & V_79 , V_77 ) ;
if ( V_173 )
F_144 () ;
}
void F_145 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
T_1 V_179 = F_49 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_146 ( V_179 ) ;
}
unsigned long F_147 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return V_2 -> V_8 ;
}
struct V_69 F_148 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return F_36 ( F_2 ( V_2 ) ) ;
}
struct V_9 F_149 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_33 ;
unsigned long V_37 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_33 = F_2 ( V_2 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_33 ;
}
struct V_9 F_150 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_33 , V_180 ;
unsigned long V_37 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_33 = F_2 ( V_2 ) ;
V_180 = V_2 -> V_15 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
F_6 ( & V_33 , V_33 . V_11 + V_180 . V_11 ,
V_33 . V_12 + V_180 . V_12 ) ;
return V_33 ;
}
void F_151 ( unsigned long V_181 )
{
V_182 += V_181 ;
F_152 ( V_181 ) ;
}
T_1 F_153 ( unsigned int * V_183 , T_1 * V_16 ,
T_1 * V_21 , T_1 * V_18 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_63 ;
V_5 V_91 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_63 = V_2 -> V_3 . V_63 ;
V_91 = F_24 ( & V_2 -> V_3 ) ;
V_63 = F_61 ( V_63 , V_91 ) ;
if ( * V_183 != V_2 -> V_88 ) {
* V_183 = V_2 -> V_88 ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
}
if ( F_18 ( V_63 . V_17 >= V_2 -> V_80 . V_17 ) )
* V_16 = F_49 ( V_2 -> V_16 , F_10 ( 1 , 0 ) ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_63 ;
}
int F_154 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_77 ;
struct V_9 V_10 ;
T_8 V_186 , V_187 ;
int V_78 ;
V_78 = F_155 ( V_185 ) ;
if ( V_78 )
return V_78 ;
if ( V_185 -> V_188 & V_189 ) {
struct V_69 V_20 ;
V_20 . V_11 = V_185 -> time . V_11 ;
V_20 . V_12 = V_185 -> time . V_138 ;
if ( ! ( V_185 -> V_188 & V_190 ) )
V_20 . V_12 *= 1000 ;
V_78 = F_89 ( & V_20 ) ;
if ( V_78 )
return V_78 ;
}
F_58 ( & V_10 ) ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
V_186 = V_187 = V_2 -> V_19 ;
V_78 = F_156 ( V_185 , & V_10 , & V_187 ) ;
if ( V_187 != V_186 ) {
F_94 ( V_2 , V_187 ) ;
F_52 ( V_2 , V_89 | V_87 ) ;
}
F_47 ( V_2 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
if ( V_187 != V_186 )
F_88 () ;
F_157 () ;
return V_78 ;
}
void F_158 ( const struct V_9 * V_191 , const struct V_9 * V_192 )
{
unsigned long V_77 ;
F_42 ( & V_79 , V_77 ) ;
F_84 ( & V_32 . V_37 ) ;
F_159 ( V_191 , V_192 ) ;
F_87 ( & V_32 . V_37 ) ;
F_44 ( & V_79 , V_77 ) ;
}
void F_160 ( unsigned long V_181 )
{
F_161 ( & V_193 ) ;
F_151 ( V_181 ) ;
F_162 ( & V_193 ) ;
F_140 () ;
}
