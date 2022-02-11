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
F_7 ( V_2 -> V_16 != F_8 ( V_14 ) ) ;
V_2 -> V_15 = V_13 ;
F_6 ( & V_14 , - V_13 . V_11 , - V_13 . V_12 ) ;
V_2 -> V_16 = F_8 ( V_14 ) ;
V_2 -> V_17 = F_9 ( V_2 -> V_16 , F_10 ( V_2 -> V_18 , 0 ) ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_19 )
{
V_2 -> V_20 = F_9 ( V_2 -> V_20 , V_19 ) ;
}
static inline V_5 F_12 ( struct V_21 * V_22 )
{
struct V_23 * clock = F_13 ( V_22 -> clock ) ;
return clock -> V_24 ( clock ) ;
}
static void F_14 ( struct V_1 * V_2 , V_5 V_25 )
{
V_5 V_26 = V_2 -> V_3 . clock -> V_26 ;
const char * V_27 = V_2 -> V_3 . clock -> V_27 ;
if ( V_25 > V_26 ) {
F_15 ( L_1 ,
V_25 , V_27 , V_26 ) ;
F_15 ( L_2 ) ;
} else {
if ( V_25 > ( V_26 >> 1 ) ) {
F_15 ( L_3 ,
V_25 , V_27 , V_26 >> 1 ) ;
F_15 ( L_4 ) ;
}
}
if ( V_2 -> V_28 ) {
if ( V_29 - V_2 -> V_30 > V_31 ) {
F_15 ( L_5 , V_27 ) ;
F_15 ( L_6 ) ;
F_15 ( L_7 ) ;
V_2 -> V_30 = V_29 ;
}
V_2 -> V_28 = 0 ;
}
if ( V_2 -> V_32 ) {
if ( V_29 - V_2 -> V_30 > V_31 ) {
F_15 ( L_8 , V_27 ) ;
F_15 ( L_6 ) ;
F_15 ( L_7 ) ;
V_2 -> V_30 = V_29 ;
}
V_2 -> V_32 = 0 ;
}
}
static inline V_5 F_16 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
V_5 V_34 , V_35 , V_36 , V_37 , V_19 ;
unsigned int V_38 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_34 = F_12 ( V_22 ) ;
V_35 = V_22 -> V_39 ;
V_36 = V_22 -> V_36 ;
V_37 = V_22 -> clock -> V_26 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
V_19 = F_19 ( V_34 , V_35 , V_36 ) ;
if ( F_20 ( ( ~ V_19 & V_36 ) < ( V_36 >> 3 ) ) ) {
V_2 -> V_28 = 1 ;
V_19 = 0 ;
}
if ( F_20 ( V_19 > V_37 ) ) {
V_2 -> V_32 = 1 ;
V_19 = V_22 -> clock -> V_26 ;
}
return V_19 ;
}
static inline void F_14 ( struct V_1 * V_2 , V_5 V_25 )
{
}
static inline V_5 F_16 ( struct V_21 * V_22 )
{
V_5 V_40 , V_19 ;
V_40 = F_12 ( V_22 ) ;
V_19 = F_19 ( V_40 , V_22 -> V_39 , V_22 -> V_36 ) ;
return V_19 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_23 * clock )
{
V_5 V_41 ;
V_5 V_14 , V_42 ;
struct V_23 * V_43 ;
++ V_2 -> V_44 ;
V_43 = V_2 -> V_3 . clock ;
V_2 -> V_3 . clock = clock ;
V_2 -> V_3 . V_36 = clock -> V_36 ;
V_2 -> V_3 . V_39 = F_12 ( & V_2 -> V_3 ) ;
V_2 -> V_45 . clock = clock ;
V_2 -> V_45 . V_36 = clock -> V_36 ;
V_2 -> V_45 . V_39 = V_2 -> V_3 . V_39 ;
V_14 = V_46 ;
V_14 <<= clock -> V_7 ;
V_42 = V_14 ;
V_14 += clock -> V_47 / 2 ;
F_22 ( V_14 , clock -> V_47 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
V_41 = ( V_5 ) V_14 ;
V_2 -> V_48 = V_41 ;
V_2 -> V_49 = V_41 * clock -> V_47 ;
V_2 -> V_50 = V_42 - V_2 -> V_49 ;
V_2 -> V_51 = V_41 * clock -> V_47 ;
if ( V_43 ) {
int V_52 = clock -> V_7 - V_43 -> V_7 ;
if ( V_52 < 0 )
V_2 -> V_3 . V_4 >>= - V_52 ;
else
V_2 -> V_3 . V_4 <<= V_52 ;
}
V_2 -> V_45 . V_4 = 0 ;
V_2 -> V_3 . V_7 = clock -> V_7 ;
V_2 -> V_45 . V_7 = clock -> V_7 ;
V_2 -> V_53 = 0 ;
V_2 -> V_54 = V_55 - clock -> V_7 ;
V_2 -> V_56 = V_42 << V_2 -> V_54 ;
V_2 -> V_3 . V_47 = clock -> V_47 ;
V_2 -> V_45 . V_47 = clock -> V_47 ;
V_2 -> V_57 = 0 ;
}
static T_2 F_23 ( void ) { return 0 ; }
static inline T_2 F_24 ( void ) { return 0 ; }
static inline V_5 F_25 ( struct V_21 * V_22 , V_5 V_19 )
{
V_5 V_58 ;
V_58 = V_19 * V_22 -> V_47 + V_22 -> V_4 ;
V_58 >>= V_22 -> V_7 ;
return V_58 + F_24 () ;
}
static inline V_5 F_26 ( struct V_21 * V_22 )
{
V_5 V_19 ;
V_19 = F_16 ( V_22 ) ;
return F_25 ( V_22 , V_19 ) ;
}
static inline V_5 F_27 ( struct V_21 * V_22 , V_5 V_59 )
{
V_5 V_19 ;
V_19 = F_19 ( V_59 , V_22 -> V_39 , V_22 -> V_36 ) ;
return F_25 ( V_22 , V_19 ) ;
}
static void F_28 ( struct V_21 * V_22 , struct V_60 * V_61 )
{
struct V_21 * V_62 = V_61 -> V_62 ;
F_29 ( & V_61 -> V_38 ) ;
memcpy ( V_62 , V_22 , sizeof( * V_62 ) ) ;
F_29 ( & V_61 -> V_38 ) ;
memcpy ( V_62 + 1 , V_62 , sizeof( * V_62 ) ) ;
}
static T_3 V_5 F_30 ( struct V_60 * V_61 )
{
struct V_21 * V_22 ;
unsigned int V_38 ;
V_5 V_34 ;
do {
V_38 = F_31 ( & V_61 -> V_38 ) ;
V_22 = V_61 -> V_62 + ( V_38 & 0x01 ) ;
V_34 = F_32 ( V_22 -> V_62 ) ;
V_34 += F_25 ( V_22 ,
F_19 (
F_12 ( V_22 ) ,
V_22 -> V_39 ,
V_22 -> V_36 ) ) ;
} while ( F_18 ( & V_61 -> V_38 , V_38 ) );
return V_34 ;
}
V_5 F_33 ( void )
{
return F_30 ( & V_63 ) ;
}
V_5 F_34 ( void )
{
return F_30 ( & V_64 ) ;
}
V_5 T_4 F_35 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
return ( F_33 () + F_32 ( V_2 -> V_20 ) ) ;
}
static V_5 F_36 ( struct V_23 * V_65 )
{
return V_66 ;
}
static void F_37 ( struct V_1 * V_2 )
{
static struct V_21 V_67 ;
struct V_21 * V_22 = & V_2 -> V_3 ;
memcpy ( & V_67 , V_22 , sizeof( V_67 ) ) ;
V_66 = F_12 ( V_22 ) ;
V_67 . clock = & V_68 ;
F_28 ( & V_67 , & V_63 ) ;
V_22 = & V_2 -> V_45 ;
memcpy ( & V_67 , V_22 , sizeof( V_67 ) ) ;
V_67 . clock = & V_68 ;
F_28 ( & V_67 , & V_64 ) ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
struct V_69 V_70 , V_71 ;
V_70 = F_39 ( F_2 ( V_2 ) ) ;
V_71 = F_39 ( V_2 -> V_15 ) ;
F_40 ( & V_70 , & V_71 , V_2 -> V_3 . clock , V_2 -> V_3 . V_47 ,
V_2 -> V_3 . V_39 ) ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
T_5 V_72 ;
V_72 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
if ( V_72 != 0 ) {
V_2 -> V_3 . V_4 -= V_72 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_53 += V_72 << V_2 -> V_54 ;
V_2 -> V_53 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_54 ;
}
}
static void F_42 ( struct V_1 * V_2 , bool V_73 )
{
F_43 ( & V_74 , V_73 , V_2 ) ;
}
int F_44 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_77 ;
int V_78 ;
F_45 ( & V_79 , V_77 ) ;
V_78 = F_46 ( & V_74 , V_76 ) ;
F_42 ( V_2 , true ) ;
F_47 ( & V_79 , V_77 ) ;
return V_78 ;
}
int F_48 ( struct V_75 * V_76 )
{
unsigned long V_77 ;
int V_78 ;
F_45 ( & V_79 , V_77 ) ;
V_78 = F_49 ( & V_74 , V_76 ) ;
F_47 ( & V_79 , V_77 ) ;
return V_78 ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_80 = F_51 () ;
if ( V_2 -> V_80 != V_81 )
V_2 -> V_80 = F_52 ( V_2 -> V_80 , V_2 -> V_16 ) ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
V_5 V_82 ;
T_2 V_58 ;
V_82 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_58 = ( T_2 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_62 = F_54 ( V_82 * V_6 + V_58 ) ;
V_2 -> V_45 . V_62 = F_8 ( V_2 -> V_83 ) ;
V_58 += ( T_2 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_58 >= V_6 )
V_82 ++ ;
V_2 -> V_84 = V_82 ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_85 )
{
if ( V_85 & V_86 ) {
V_2 -> V_53 = 0 ;
F_56 () ;
}
F_50 ( V_2 ) ;
F_53 ( V_2 ) ;
F_38 ( V_2 ) ;
F_42 ( V_2 , V_85 & V_87 ) ;
F_28 ( & V_2 -> V_3 , & V_63 ) ;
F_28 ( & V_2 -> V_45 , & V_64 ) ;
if ( V_85 & V_87 )
V_2 -> V_88 ++ ;
if ( V_85 & V_89 )
memcpy ( & V_90 , & V_33 . V_1 ,
sizeof( V_33 . V_1 ) ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
V_5 V_40 , V_19 ;
V_5 V_58 ;
V_40 = F_12 ( & V_2 -> V_3 ) ;
V_19 = F_19 ( V_40 , V_2 -> V_3 . V_39 , V_2 -> V_3 . V_36 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_3 . V_4 += V_19 * V_2 -> V_3 . V_47 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_24 () << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
V_58 = F_58 ( V_19 , V_2 -> V_45 . V_47 , V_2 -> V_45 . V_7 ) ;
F_59 ( & V_2 -> V_83 , V_58 ) ;
}
int F_60 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_38 ;
V_5 V_91 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
V_10 -> V_12 = 0 ;
F_59 ( V_10 , V_91 ) ;
if ( F_20 ( V_92 ) )
return - V_93 ;
return 0 ;
}
void F_61 ( struct V_9 * V_10 )
{
F_62 ( F_60 ( V_10 ) ) ;
}
T_1 F_63 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned int V_38 ;
T_1 V_62 ;
V_5 V_91 ;
F_62 ( V_92 ) ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_62 = V_2 -> V_3 . V_62 ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return F_64 ( V_62 , V_91 ) ;
}
T_2 F_65 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned int V_38 ;
T_2 V_91 ;
F_62 ( V_92 ) ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_91 = V_2 -> V_3 . V_47 >> V_2 -> V_3 . V_7 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_91 ;
}
T_1 F_66 ( enum V_94 V_95 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned int V_38 ;
T_1 V_62 , * V_25 = V_96 [ V_95 ] ;
V_5 V_91 ;
F_62 ( V_92 ) ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_62 = F_9 ( V_2 -> V_3 . V_62 , * V_25 ) ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return F_64 ( V_62 , V_91 ) ;
}
T_1 F_67 ( T_1 V_97 , enum V_94 V_95 )
{
T_1 * V_25 = V_96 [ V_95 ] ;
unsigned long V_38 ;
T_1 V_98 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_98 = F_9 ( V_97 , * V_25 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_98 ;
}
T_1 F_68 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned int V_38 ;
T_1 V_62 ;
V_5 V_91 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_62 = V_2 -> V_45 . V_62 ;
V_91 = F_26 ( & V_2 -> V_45 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return F_64 ( V_62 , V_91 ) ;
}
void F_69 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_9 V_99 ;
unsigned int V_38 ;
V_5 V_58 ;
F_62 ( V_92 ) ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_58 = F_26 ( & V_2 -> V_3 ) ;
V_99 = V_2 -> V_15 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
V_10 -> V_11 += V_99 . V_11 ;
V_10 -> V_12 = 0 ;
F_59 ( V_10 , V_58 + V_99 . V_12 ) ;
}
T_6 F_70 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
F_62 ( V_92 ) ;
return V_2 -> V_84 ;
}
T_6 F_71 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
T_6 V_82 ;
unsigned int V_38 ;
if ( F_72 ( V_100 ) )
return V_2 -> V_8 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_82 = V_2 -> V_8 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_82 ;
}
T_6 F_73 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
return V_2 -> V_8 ;
}
void F_74 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_38 ;
T_1 V_103 ;
T_1 V_104 ;
V_5 V_105 ;
V_5 V_106 ;
V_5 V_34 ;
F_7 ( V_92 ) ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_34 = F_12 ( & V_2 -> V_3 ) ;
V_102 -> V_44 = V_2 -> V_44 ;
V_102 -> V_88 = V_2 -> V_88 ;
V_104 = F_9 ( V_2 -> V_3 . V_62 ,
V_33 . V_1 . V_16 ) ;
V_103 = V_2 -> V_45 . V_62 ;
V_106 = F_27 ( & V_2 -> V_3 , V_34 ) ;
V_105 = F_27 ( & V_2 -> V_45 , V_34 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
V_102 -> V_59 = V_34 ;
V_102 -> V_107 = F_64 ( V_104 , V_106 ) ;
V_102 -> V_108 = F_64 ( V_103 , V_105 ) ;
}
static int F_75 ( V_5 V_47 , V_5 div , V_5 * V_62 )
{
V_5 V_14 , V_109 ;
V_14 = F_76 ( * V_62 , div , & V_109 ) ;
if ( ( ( int ) sizeof( V_5 ) * 8 - F_77 ( V_47 ) < F_77 ( V_14 ) ) ||
( ( int ) sizeof( V_5 ) * 8 - F_77 ( V_47 ) < F_77 ( V_109 ) ) )
return - V_110 ;
V_14 *= V_47 ;
V_109 *= V_47 ;
F_22 ( V_109 , div ) ;
* V_62 = V_14 + V_109 ;
return 0 ;
}
static int F_78 ( struct V_101 * V_111 ,
V_5 V_112 ,
V_5 V_113 ,
bool V_114 ,
struct V_115 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
V_5 V_116 , V_117 ;
bool V_118 ;
int V_78 ;
if ( V_113 == 0 || V_112 == 0 )
return 0 ;
V_118 = V_112 > V_113 / 2 ;
V_112 = V_118 ?
V_113 - V_112 :
V_112 ;
V_116 = ( V_5 ) F_32 (
F_52 ( V_10 -> V_119 , V_111 -> V_108 ) ) ;
V_78 = F_75 ( V_112 ,
V_113 , & V_116 ) ;
if ( V_78 )
return V_78 ;
if ( V_114 ) {
V_117 = F_79
( V_116 , V_2 -> V_3 . V_47 , V_2 -> V_45 . V_47 ) ;
} else {
V_117 = ( V_5 ) F_32 (
F_52 ( V_10 -> V_120 , V_111 -> V_107 ) ) ;
V_78 = F_75 ( V_112 ,
V_113 , & V_117 ) ;
if ( V_78 )
return V_78 ;
}
if ( V_118 ) {
V_10 -> V_119 = F_64 ( V_111 -> V_108 , V_116 ) ;
V_10 -> V_120 = F_64 ( V_111 -> V_107 , V_117 ) ;
} else {
V_10 -> V_119 = F_80 ( V_10 -> V_119 , V_116 ) ;
V_10 -> V_120 = F_80 ( V_10 -> V_120 , V_117 ) ;
}
return 0 ;
}
static bool F_81 ( V_5 V_121 , V_5 V_122 , V_5 V_123 )
{
if ( V_122 > V_121 && V_122 < V_123 )
return true ;
if ( V_122 < V_121 && V_121 > V_123 )
return true ;
return false ;
}
int F_82 ( int (* F_83)
( T_1 * V_124 ,
struct V_125 * V_126 ,
void * V_127 ) ,
void * V_127 ,
struct V_101 * V_128 ,
struct V_115 * V_129 )
{
struct V_125 V_130 ;
struct V_1 * V_2 = & V_33 . V_1 ;
V_5 V_59 , V_34 , V_131 ;
unsigned int V_88 = 0 ;
T_1 V_104 , V_103 ;
V_5 V_106 , V_105 ;
T_7 V_44 ;
unsigned long V_38 ;
bool V_132 ;
int V_78 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_78 = F_83 ( & V_129 -> V_133 , & V_130 , V_127 ) ;
if ( V_78 )
return V_78 ;
if ( V_2 -> V_3 . clock != V_130 . V_65 )
return - V_134 ;
V_59 = V_130 . V_59 ;
V_34 = F_12 ( & V_2 -> V_3 ) ;
V_131 = V_2 -> V_3 . V_39 ;
if ( ! F_81 ( V_131 , V_59 , V_34 ) ) {
V_88 = V_2 -> V_88 ;
V_44 = V_2 -> V_44 ;
V_59 = V_131 ;
V_132 = true ;
} else {
V_132 = false ;
}
V_104 = F_9 ( V_2 -> V_3 . V_62 ,
V_33 . V_1 . V_16 ) ;
V_103 = V_2 -> V_45 . V_62 ;
V_106 = F_27 ( & V_2 -> V_3 ,
V_130 . V_59 ) ;
V_105 = F_27 ( & V_2 -> V_45 ,
V_130 . V_59 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
V_129 -> V_120 = F_64 ( V_104 , V_106 ) ;
V_129 -> V_119 = F_64 ( V_103 , V_105 ) ;
if ( V_132 ) {
V_5 V_112 , V_113 ;
bool V_114 ;
if ( ! V_128 ||
! F_81 ( V_128 -> V_59 ,
V_130 . V_59 , V_59 ) ||
V_128 -> V_44 != V_44 )
return - V_135 ;
V_112 = V_59 - V_130 . V_59 ;
V_113 = V_59 - V_128 -> V_59 ;
V_114 =
V_128 -> V_88 != V_88 ;
V_78 = F_78 ( V_128 ,
V_112 ,
V_113 ,
V_114 , V_129 ) ;
if ( V_78 )
return V_78 ;
}
return 0 ;
}
void F_84 ( struct V_136 * V_137 )
{
struct V_9 V_34 ;
F_61 ( & V_34 ) ;
V_137 -> V_11 = V_34 . V_11 ;
V_137 -> V_138 = V_34 . V_12 / 1000 ;
}
int F_85 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_9 V_139 , V_70 ;
unsigned long V_77 ;
int V_78 = 0 ;
if ( ! F_86 ( V_10 ) )
return - V_135 ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_57 ( V_2 ) ;
V_70 = F_2 ( V_2 ) ;
V_139 . V_11 = V_10 -> V_11 - V_70 . V_11 ;
V_139 . V_12 = V_10 -> V_12 - V_70 . V_12 ;
if ( F_88 ( & V_2 -> V_15 , & V_139 ) > 0 ) {
V_78 = - V_135 ;
goto V_140;
}
F_5 ( V_2 , F_89 ( V_2 -> V_15 , V_139 ) ) ;
F_3 ( V_2 , V_10 ) ;
V_140:
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
F_91 () ;
return V_78 ;
}
int F_92 ( struct V_69 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_77 ;
struct V_9 V_141 , V_14 ;
int V_78 = 0 ;
if ( ! F_93 ( V_10 ) )
return - V_135 ;
V_141 = F_94 ( * V_10 ) ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_57 ( V_2 ) ;
V_14 = F_95 ( F_2 ( V_2 ) , V_141 ) ;
if ( F_88 ( & V_2 -> V_15 , & V_141 ) > 0 ||
! F_86 ( & V_14 ) ) {
V_78 = - V_135 ;
goto error;
}
F_4 ( V_2 , & V_141 ) ;
F_5 ( V_2 , F_89 ( V_2 -> V_15 , V_141 ) ) ;
error:
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
F_91 () ;
return V_78 ;
}
static void F_96 ( struct V_1 * V_2 , T_8 V_18 )
{
V_2 -> V_18 = V_18 ;
V_2 -> V_17 = F_9 ( V_2 -> V_16 , F_10 ( V_18 , 0 ) ) ;
}
static int F_97 ( void * V_142 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_23 * V_143 , * V_144 ;
unsigned long V_77 ;
V_143 = (struct V_23 * ) V_142 ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_57 ( V_2 ) ;
if ( F_98 ( V_143 -> V_145 ) ) {
if ( ! V_143 -> V_146 || V_143 -> V_146 ( V_143 ) == 0 ) {
V_144 = V_2 -> V_3 . clock ;
F_21 ( V_2 , V_143 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 ( V_144 ) ;
F_99 ( V_144 -> V_145 ) ;
} else {
F_99 ( V_143 -> V_145 ) ;
}
}
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
return 0 ;
}
int F_100 ( struct V_23 * clock )
{
struct V_1 * V_2 = & V_33 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_101 ( F_97 , clock , NULL ) ;
F_102 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_103 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_9 V_141 ;
unsigned long V_38 ;
V_5 V_91 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_91 = F_26 ( & V_2 -> V_45 ) ;
V_141 = V_2 -> V_83 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
F_59 ( & V_141 , V_91 ) ;
* V_10 = V_141 ;
}
int F_104 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_38 ;
int V_78 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_78 = V_2 -> V_3 . clock -> V_77 & V_148 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_78 ;
}
V_5 F_105 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_38 ;
V_5 V_78 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_78 = V_2 -> V_3 . clock -> V_149 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_78 ;
}
void __weak F_106 ( struct V_69 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_107 ( struct V_9 * V_141 )
{
struct V_69 V_10 ;
F_106 ( & V_10 ) ;
* V_141 = F_94 ( V_10 ) ;
}
void __weak F_108 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_9 F_109 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_23 * clock ;
unsigned long V_77 ;
struct V_9 V_34 , V_150 , V_14 ;
F_107 ( & V_34 ) ;
if ( ! F_86 ( & V_34 ) ) {
F_110 ( L_9
L_10 ) ;
V_34 . V_11 = 0 ;
V_34 . V_12 = 0 ;
} else if ( V_34 . V_11 || V_34 . V_12 )
V_151 = true ;
F_108 ( & V_150 ) ;
if ( ! F_86 ( & V_150 ) ) {
F_110 ( L_11
L_10 ) ;
V_150 . V_11 = 0 ;
V_150 . V_12 = 0 ;
}
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_111 () ;
clock = F_112 () ;
if ( clock -> V_146 )
clock -> V_146 ( clock ) ;
F_21 ( V_2 , clock ) ;
F_3 ( V_2 , & V_34 ) ;
V_2 -> V_83 . V_11 = 0 ;
V_2 -> V_83 . V_12 = 0 ;
if ( V_150 . V_11 == 0 && V_150 . V_12 == 0 )
V_150 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_150 . V_11 , - V_150 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_55 ( V_2 , V_89 | V_87 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_9 * V_19 )
{
if ( ! F_86 ( V_19 ) ) {
F_15 ( V_152
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_19 ) ;
F_5 ( V_2 , F_89 ( V_2 -> V_15 , * V_19 ) ) ;
F_11 ( V_2 , F_8 ( * V_19 ) ) ;
F_114 ( V_19 ) ;
}
bool F_115 ( void )
{
return V_153 ;
}
bool F_116 ( void )
{
return V_151 ;
}
void F_117 ( struct V_9 * V_19 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_77 ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_57 ( V_2 ) ;
F_113 ( V_2 , V_19 ) ;
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
F_91 () ;
}
void F_118 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_23 * clock = V_2 -> V_3 . clock ;
unsigned long V_77 ;
struct V_9 V_154 , V_139 ;
V_5 V_40 ;
V_153 = false ;
F_107 ( & V_154 ) ;
F_119 () ;
F_120 () ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
V_40 = F_12 ( & V_2 -> V_3 ) ;
if ( ( clock -> V_77 & V_155 ) &&
V_40 > V_2 -> V_3 . V_39 ) {
V_5 V_58 , V_156 ;
V_156 = F_19 ( V_40 , V_2 -> V_3 . V_39 ,
V_2 -> V_3 . V_36 ) ;
V_58 = F_121 ( V_156 , clock -> V_47 , clock -> V_7 ) ;
V_139 = F_122 ( V_58 ) ;
V_153 = true ;
} else if ( F_88 ( & V_154 , & V_157 ) > 0 ) {
V_139 = F_89 ( V_154 , V_157 ) ;
V_153 = true ;
}
if ( V_153 )
F_113 ( V_2 , & V_139 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_53 = 0 ;
V_92 = 0 ;
F_55 ( V_2 , V_89 | V_87 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
F_123 () ;
F_124 () ;
F_125 () ;
}
int F_126 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_77 ;
struct V_9 V_19 , V_158 ;
static struct V_9 V_159 ;
F_107 ( & V_157 ) ;
if ( V_157 . V_11 || V_157 . V_12 )
V_151 = true ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_57 ( V_2 ) ;
V_92 = 1 ;
if ( V_151 ) {
V_19 = F_89 ( F_2 ( V_2 ) , V_157 ) ;
V_158 = F_89 ( V_19 , V_159 ) ;
if ( abs ( V_158 . V_11 ) >= 2 ) {
V_159 = V_19 ;
} else {
V_157 =
F_95 ( V_157 , V_158 ) ;
}
}
F_55 ( V_2 , V_89 ) ;
F_37 ( V_2 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
F_127 () ;
F_128 () ;
F_129 () ;
return 0 ;
}
static int T_9 F_130 ( void )
{
F_131 ( & V_160 ) ;
return 0 ;
}
static T_3 void F_132 ( struct V_1 * V_2 ,
T_5 V_25 ,
bool V_161 ,
int V_162 )
{
T_5 V_41 = V_2 -> V_48 ;
T_8 V_163 = 1 ;
if ( V_161 ) {
V_163 = - V_163 ;
V_41 = - V_41 ;
V_25 = - V_25 ;
}
V_163 <<= V_162 ;
V_41 <<= V_162 ;
V_25 <<= V_162 ;
if ( ( V_163 > 0 ) && ( V_2 -> V_3 . V_47 + V_163 < V_163 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_47 += V_163 ;
V_2 -> V_49 += V_41 ;
V_2 -> V_3 . V_4 -= V_25 ;
V_2 -> V_53 -= ( V_41 - V_25 ) << V_2 -> V_54 ;
}
static T_3 void F_133 ( struct V_1 * V_2 ,
T_5 V_25 )
{
T_5 V_41 = V_2 -> V_48 ;
T_5 V_164 = V_2 -> V_49 ;
T_2 V_62 = V_2 -> V_3 . clock -> V_47 ;
T_2 V_37 = V_2 -> V_3 . clock -> V_165 ;
T_2 V_166 = V_2 -> V_3 . V_47 ;
T_5 V_167 ;
bool V_161 ;
T_2 V_162 ;
if ( V_2 -> V_57 )
V_164 -= V_2 -> V_48 ;
V_2 -> V_56 = F_134 () ;
V_167 = F_134 () >> V_2 -> V_54 ;
V_167 -= ( V_164 + V_2 -> V_50 ) ;
if ( F_135 ( ( V_167 >= 0 ) && ( V_167 <= V_41 ) ) )
return;
V_161 = ( V_167 < 0 ) ;
if ( V_161 && ( V_166 - 1 ) <= ( V_62 - V_37 ) )
return;
if ( ! V_161 && ( V_166 + 1 ) >= ( V_62 + V_37 ) )
return;
V_162 = 0 ;
V_167 = abs ( V_167 ) ;
while ( V_167 > V_41 ) {
T_2 V_168 = 1 << ( V_162 + 1 ) ;
if ( V_161 && ( V_166 - V_168 ) <= ( V_62 - V_37 ) )
break;
if ( ! V_161 && ( V_166 + V_168 ) >= ( V_62 + V_37 ) )
break;
V_162 ++ ;
V_167 >>= 1 ;
}
F_132 ( V_2 , V_25 , V_161 , V_162 ) ;
}
static void F_136 ( struct V_1 * V_2 , T_5 V_25 )
{
F_133 ( V_2 , V_25 ) ;
if ( ! V_2 -> V_57 && ( V_2 -> V_53 > 0 ) ) {
V_2 -> V_57 = 1 ;
F_132 ( V_2 , V_25 , 0 , 0 ) ;
} else if ( V_2 -> V_57 && ( V_2 -> V_53 <= 0 ) ) {
F_132 ( V_2 , V_25 , 1 , 0 ) ;
V_2 -> V_57 = 0 ;
}
if ( F_20 ( V_2 -> V_3 . clock -> V_165 &&
( abs ( V_2 -> V_3 . V_47 - V_2 -> V_3 . clock -> V_47 )
> V_2 -> V_3 . clock -> V_165 ) ) ) {
F_137 ( V_152
L_14 ,
V_2 -> V_3 . clock -> V_27 , ( long ) V_2 -> V_3 . V_47 ,
( long ) V_2 -> V_3 . clock -> V_47 + V_2 -> V_3 . clock -> V_165 ) ;
}
if ( F_20 ( ( T_5 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_5 V_169 = - ( T_5 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_53 += V_169 << V_2 -> V_54 ;
}
}
static inline unsigned int F_138 ( struct V_1 * V_2 )
{
V_5 V_170 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_171 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_170 ) {
int V_172 ;
V_2 -> V_3 . V_4 -= V_170 ;
V_2 -> V_8 ++ ;
V_172 = F_139 ( V_2 -> V_8 ) ;
if ( F_20 ( V_172 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_172 ;
V_10 . V_11 = V_172 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_89 ( V_2 -> V_15 , V_10 ) ) ;
F_96 ( V_2 , V_2 -> V_18 - V_172 ) ;
V_171 = V_87 ;
}
}
return V_171 ;
}
static V_5 F_140 ( struct V_1 * V_2 , V_5 V_25 ,
T_2 V_7 , unsigned int * V_171 )
{
V_5 V_41 = V_2 -> V_48 << V_7 ;
V_5 V_173 ;
if ( V_25 < V_41 )
return V_25 ;
V_25 -= V_41 ;
V_2 -> V_3 . V_39 += V_41 ;
V_2 -> V_45 . V_39 += V_41 ;
V_2 -> V_3 . V_4 += V_2 -> V_49 << V_7 ;
* V_171 |= F_138 ( V_2 ) ;
V_2 -> V_45 . V_4 += ( V_5 ) V_2 -> V_83 . V_12 << V_2 -> V_45 . V_7 ;
V_2 -> V_45 . V_4 += V_2 -> V_51 << V_7 ;
V_173 = ( V_5 ) V_6 << V_2 -> V_45 . V_7 ;
while ( V_2 -> V_45 . V_4 >= V_173 ) {
V_2 -> V_45 . V_4 -= V_173 ;
V_2 -> V_83 . V_11 ++ ;
}
V_2 -> V_83 . V_12 = V_2 -> V_45 . V_4 >> V_2 -> V_45 . V_7 ;
V_2 -> V_45 . V_4 -= ( V_5 ) V_2 -> V_83 . V_12 << V_2 -> V_45 . V_7 ;
V_2 -> V_53 += V_2 -> V_56 << V_7 ;
V_2 -> V_53 -= ( V_2 -> V_49 + V_2 -> V_50 ) <<
( V_2 -> V_54 + V_7 ) ;
return V_25 ;
}
void F_141 ( void )
{
struct V_1 * V_174 = & V_33 . V_1 ;
struct V_1 * V_2 = & V_90 ;
V_5 V_25 ;
int V_7 = 0 , V_175 ;
unsigned int V_171 = 0 ;
unsigned long V_77 ;
F_45 ( & V_79 , V_77 ) ;
if ( F_20 ( V_92 ) )
goto V_140;
#ifdef F_142
V_25 = V_174 -> V_48 ;
#else
V_25 = F_19 ( F_12 ( & V_2 -> V_3 ) ,
V_2 -> V_3 . V_39 , V_2 -> V_3 . V_36 ) ;
#endif
if ( V_25 < V_174 -> V_48 )
goto V_140;
F_14 ( V_174 , V_25 ) ;
V_7 = F_143 ( V_25 ) - F_143 ( V_2 -> V_48 ) ;
V_7 = V_37 ( 0 , V_7 ) ;
V_175 = ( 64 - ( F_143 ( F_134 () ) + 1 ) ) - 1 ;
V_7 = F_144 ( V_7 , V_175 ) ;
while ( V_25 >= V_2 -> V_48 ) {
V_25 = F_140 ( V_2 , V_25 , V_7 ,
& V_171 ) ;
if ( V_25 < V_2 -> V_48 << V_7 )
V_7 -- ;
}
F_136 ( V_2 , V_25 ) ;
F_41 ( V_2 ) ;
V_171 |= F_138 ( V_2 ) ;
F_87 ( & V_33 . V_38 ) ;
F_55 ( V_2 , V_171 ) ;
memcpy ( V_174 , V_2 , sizeof( * V_2 ) ) ;
F_90 ( & V_33 . V_38 ) ;
V_140:
F_47 ( & V_79 , V_77 ) ;
if ( V_171 )
F_145 () ;
}
void F_146 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
T_1 V_176 = F_52 ( V_2 -> V_16 , V_2 -> V_20 ) ;
* V_10 = F_147 ( V_176 ) ;
}
unsigned long F_148 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
return V_2 -> V_8 ;
}
struct V_69 F_149 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
return F_39 ( F_2 ( V_2 ) ) ;
}
struct V_9 F_150 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_9 V_34 ;
unsigned long V_38 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_34 = F_2 ( V_2 ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_34 ;
}
struct V_9 F_151 ( void )
{
struct V_1 * V_2 = & V_33 . V_1 ;
struct V_9 V_34 , V_177 ;
unsigned long V_38 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_34 = F_2 ( V_2 ) ;
V_177 = V_2 -> V_15 ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
F_6 ( & V_34 , V_34 . V_11 + V_177 . V_11 ,
V_34 . V_12 + V_177 . V_12 ) ;
return V_34 ;
}
void F_152 ( unsigned long V_178 )
{
V_179 += V_178 ;
F_153 ( V_178 ) ;
}
T_1 F_154 ( unsigned int * V_180 , T_1 * V_16 ,
T_1 * V_20 , T_1 * V_17 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned int V_38 ;
T_1 V_62 ;
V_5 V_91 ;
do {
V_38 = F_17 ( & V_33 . V_38 ) ;
V_62 = V_2 -> V_3 . V_62 ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
V_62 = F_64 ( V_62 , V_91 ) ;
if ( * V_180 != V_2 -> V_88 ) {
* V_180 = V_2 -> V_88 ;
* V_16 = V_2 -> V_16 ;
* V_20 = V_2 -> V_20 ;
* V_17 = V_2 -> V_17 ;
}
if ( F_20 ( V_62 >= V_2 -> V_80 ) )
* V_16 = F_52 ( V_2 -> V_16 , F_10 ( 1 , 0 ) ) ;
} while ( F_18 ( & V_33 . V_38 , V_38 ) );
return V_62 ;
}
int F_155 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = & V_33 . V_1 ;
unsigned long V_77 ;
struct V_9 V_10 ;
T_8 V_183 , V_184 ;
int V_78 ;
V_78 = F_156 ( V_182 ) ;
if ( V_78 )
return V_78 ;
if ( V_182 -> V_185 & V_186 ) {
struct V_69 V_19 ;
V_19 . V_11 = V_182 -> time . V_11 ;
V_19 . V_12 = V_182 -> time . V_138 ;
if ( ! ( V_182 -> V_185 & V_187 ) )
V_19 . V_12 *= 1000 ;
V_78 = F_92 ( & V_19 ) ;
if ( V_78 )
return V_78 ;
}
F_61 ( & V_10 ) ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
V_183 = V_184 = V_2 -> V_18 ;
V_78 = F_157 ( V_182 , & V_10 , & V_184 ) ;
if ( V_184 != V_183 ) {
F_96 ( V_2 , V_184 ) ;
F_55 ( V_2 , V_89 | V_87 ) ;
}
F_50 ( V_2 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
if ( V_184 != V_183 )
F_91 () ;
F_158 () ;
return V_78 ;
}
void F_159 ( const struct V_9 * V_188 , const struct V_9 * V_189 )
{
unsigned long V_77 ;
F_45 ( & V_79 , V_77 ) ;
F_87 ( & V_33 . V_38 ) ;
F_160 ( V_188 , V_189 ) ;
F_90 ( & V_33 . V_38 ) ;
F_47 ( & V_79 , V_77 ) ;
}
void F_161 ( unsigned long V_178 )
{
F_162 ( & V_190 ) ;
F_152 ( V_178 ) ;
F_163 ( & V_190 ) ;
F_141 () ;
}
