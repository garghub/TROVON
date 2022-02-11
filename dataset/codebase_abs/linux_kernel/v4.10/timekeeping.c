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
static void F_12 ( struct V_1 * V_2 , V_5 V_21 )
{
V_5 V_22 = V_2 -> V_3 . clock -> V_22 ;
const char * V_23 = V_2 -> V_3 . clock -> V_23 ;
if ( V_21 > V_22 ) {
F_13 ( L_1 ,
V_21 , V_23 , V_22 ) ;
F_13 ( L_2 ) ;
} else {
if ( V_21 > ( V_22 >> 1 ) ) {
F_13 ( L_3 ,
V_21 , V_23 , V_22 >> 1 ) ;
F_13 ( L_4 ) ;
}
}
if ( V_2 -> V_24 ) {
if ( V_25 - V_2 -> V_26 > V_27 ) {
F_13 ( L_5 , V_23 ) ;
F_13 ( L_6 ) ;
F_13 ( L_7 ) ;
V_2 -> V_26 = V_25 ;
}
V_2 -> V_24 = 0 ;
}
if ( V_2 -> V_28 ) {
if ( V_25 - V_2 -> V_26 > V_27 ) {
F_13 ( L_8 , V_23 ) ;
F_13 ( L_6 ) ;
F_13 ( L_7 ) ;
V_2 -> V_26 = V_25 ;
}
V_2 -> V_28 = 0 ;
}
}
static inline V_5 F_14 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
V_5 V_32 , V_33 , V_34 , V_35 , V_19 ;
unsigned int V_36 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_32 = V_30 -> V_37 ( V_30 -> clock ) ;
V_33 = V_30 -> V_38 ;
V_34 = V_30 -> V_34 ;
V_35 = V_30 -> clock -> V_22 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
V_19 = F_17 ( V_32 , V_33 , V_34 ) ;
if ( F_18 ( ( ~ V_19 & V_34 ) < ( V_34 >> 3 ) ) ) {
V_2 -> V_24 = 1 ;
V_19 = 0 ;
}
if ( F_18 ( V_19 > V_35 ) ) {
V_2 -> V_28 = 1 ;
V_19 = V_30 -> clock -> V_22 ;
}
return V_19 ;
}
static inline void F_12 ( struct V_1 * V_2 , V_5 V_21 )
{
}
static inline V_5 F_14 ( struct V_29 * V_30 )
{
V_5 V_39 , V_19 ;
V_39 = V_30 -> V_37 ( V_30 -> clock ) ;
V_19 = F_17 ( V_39 , V_30 -> V_38 , V_30 -> V_34 ) ;
return V_19 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_40 * clock )
{
V_5 V_41 ;
V_5 V_14 , V_42 ;
struct V_40 * V_43 ;
++ V_2 -> V_44 ;
V_43 = V_2 -> V_3 . clock ;
V_2 -> V_3 . clock = clock ;
V_2 -> V_3 . V_37 = clock -> V_37 ;
V_2 -> V_3 . V_34 = clock -> V_34 ;
V_2 -> V_3 . V_38 = V_2 -> V_3 . V_37 ( clock ) ;
V_2 -> V_45 . clock = clock ;
V_2 -> V_45 . V_37 = clock -> V_37 ;
V_2 -> V_45 . V_34 = clock -> V_34 ;
V_2 -> V_45 . V_38 = V_2 -> V_3 . V_38 ;
V_14 = V_46 ;
V_14 <<= clock -> V_7 ;
V_42 = V_14 ;
V_14 += clock -> V_47 / 2 ;
F_20 ( V_14 , clock -> V_47 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
V_41 = ( V_5 ) V_14 ;
V_2 -> V_48 = V_41 ;
V_2 -> V_49 = V_41 * clock -> V_47 ;
V_2 -> V_50 = V_42 - V_2 -> V_49 ;
V_2 -> V_51 = ( V_41 * clock -> V_47 ) >> clock -> V_7 ;
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
static T_2 F_21 ( void ) { return 0 ; }
static inline T_2 F_22 ( void ) { return 0 ; }
static inline V_5 F_23 ( struct V_29 * V_30 , V_5 V_19 )
{
V_5 V_58 ;
V_58 = V_19 * V_30 -> V_47 + V_30 -> V_4 ;
V_58 >>= V_30 -> V_7 ;
return V_58 + F_22 () ;
}
static inline V_5 F_24 ( struct V_29 * V_30 )
{
V_5 V_19 ;
V_19 = F_14 ( V_30 ) ;
return F_23 ( V_30 , V_19 ) ;
}
static inline V_5 F_25 ( struct V_29 * V_30 , V_5 V_59 )
{
V_5 V_19 ;
V_19 = F_17 ( V_59 , V_30 -> V_38 , V_30 -> V_34 ) ;
return F_23 ( V_30 , V_19 ) ;
}
static void F_26 ( struct V_29 * V_30 , struct V_60 * V_61 )
{
struct V_29 * V_62 = V_61 -> V_62 ;
F_27 ( & V_61 -> V_36 ) ;
memcpy ( V_62 , V_30 , sizeof( * V_62 ) ) ;
F_27 ( & V_61 -> V_36 ) ;
memcpy ( V_62 + 1 , V_62 , sizeof( * V_62 ) ) ;
}
static T_3 V_5 F_28 ( struct V_60 * V_61 )
{
struct V_29 * V_30 ;
unsigned int V_36 ;
V_5 V_32 ;
do {
V_36 = F_29 ( & V_61 -> V_36 ) ;
V_30 = V_61 -> V_62 + ( V_36 & 0x01 ) ;
V_32 = F_30 ( V_30 -> V_62 ) ;
V_32 += F_23 ( V_30 ,
F_17 (
V_30 -> V_37 ( V_30 -> clock ) ,
V_30 -> V_38 ,
V_30 -> V_34 ) ) ;
} while ( F_16 ( & V_61 -> V_36 , V_36 ) );
return V_32 ;
}
V_5 F_31 ( void )
{
return F_28 ( & V_63 ) ;
}
V_5 F_32 ( void )
{
return F_28 ( & V_64 ) ;
}
V_5 T_4 F_33 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
return ( F_31 () + F_30 ( V_2 -> V_20 ) ) ;
}
static V_5 F_34 ( struct V_40 * V_65 )
{
return V_66 ;
}
static void F_35 ( struct V_1 * V_2 )
{
static struct V_29 V_67 ;
struct V_29 * V_30 = & V_2 -> V_3 ;
memcpy ( & V_67 , V_30 , sizeof( V_67 ) ) ;
V_66 = V_30 -> V_37 ( V_30 -> clock ) ;
V_67 . V_37 = F_34 ;
F_26 ( & V_67 , & V_63 ) ;
V_30 = & V_2 -> V_45 ;
memcpy ( & V_67 , V_30 , sizeof( V_67 ) ) ;
V_67 . V_37 = F_34 ;
F_26 ( & V_67 , & V_64 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
struct V_68 V_69 , V_70 ;
V_69 = F_37 ( F_2 ( V_2 ) ) ;
V_70 = F_37 ( V_2 -> V_15 ) ;
F_38 ( & V_69 , & V_70 , V_2 -> V_3 . clock , V_2 -> V_3 . V_47 ,
V_2 -> V_3 . V_38 ) ;
}
static inline void F_39 ( struct V_1 * V_2 )
{
T_5 V_71 ;
V_71 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
if ( V_71 != 0 ) {
V_2 -> V_3 . V_4 -= V_71 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_53 += V_71 << V_2 -> V_54 ;
V_2 -> V_53 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_54 ;
}
}
static void F_40 ( struct V_1 * V_2 , bool V_72 )
{
F_41 ( & V_73 , V_72 , V_2 ) ;
}
int F_42 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_76 ;
int V_77 ;
F_43 ( & V_78 , V_76 ) ;
V_77 = F_44 ( & V_73 , V_75 ) ;
F_40 ( V_2 , true ) ;
F_45 ( & V_78 , V_76 ) ;
return V_77 ;
}
int F_46 ( struct V_74 * V_75 )
{
unsigned long V_76 ;
int V_77 ;
F_43 ( & V_78 , V_76 ) ;
V_77 = F_47 ( & V_73 , V_75 ) ;
F_45 ( & V_78 , V_76 ) ;
return V_77 ;
}
static inline void F_48 ( struct V_1 * V_2 )
{
V_2 -> V_79 = F_49 () ;
if ( V_2 -> V_79 != V_80 )
V_2 -> V_79 = F_50 ( V_2 -> V_79 , V_2 -> V_16 ) ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
V_5 V_81 ;
T_2 V_58 ;
V_81 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_58 = ( T_2 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_62 = F_52 ( V_81 * V_6 + V_58 ) ;
V_2 -> V_45 . V_62 = F_8 ( V_2 -> V_82 ) ;
V_58 += ( T_2 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_58 >= V_6 )
V_81 ++ ;
V_2 -> V_83 = V_81 ;
}
static void F_53 ( struct V_1 * V_2 , unsigned int V_84 )
{
if ( V_84 & V_85 ) {
V_2 -> V_53 = 0 ;
F_54 () ;
}
F_48 ( V_2 ) ;
F_51 ( V_2 ) ;
F_36 ( V_2 ) ;
F_40 ( V_2 , V_84 & V_86 ) ;
F_26 ( & V_2 -> V_3 , & V_63 ) ;
F_26 ( & V_2 -> V_45 , & V_64 ) ;
if ( V_84 & V_86 )
V_2 -> V_87 ++ ;
if ( V_84 & V_88 )
memcpy ( & V_89 , & V_31 . V_1 ,
sizeof( V_31 . V_1 ) ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_40 * clock = V_2 -> V_3 . clock ;
V_5 V_39 , V_19 ;
V_5 V_58 ;
V_39 = V_2 -> V_3 . V_37 ( clock ) ;
V_19 = F_17 ( V_39 , V_2 -> V_3 . V_38 , V_2 -> V_3 . V_34 ) ;
V_2 -> V_3 . V_38 = V_39 ;
V_2 -> V_45 . V_38 = V_39 ;
V_2 -> V_3 . V_4 += V_19 * V_2 -> V_3 . V_47 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_22 () << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
V_58 = F_56 ( V_19 , V_2 -> V_45 . V_47 , V_2 -> V_45 . V_7 ) ;
F_57 ( & V_2 -> V_82 , V_58 ) ;
}
int F_58 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_36 ;
V_5 V_90 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_90 = F_24 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
V_10 -> V_12 = 0 ;
F_57 ( V_10 , V_90 ) ;
if ( F_18 ( V_91 ) )
return - V_92 ;
return 0 ;
}
void F_59 ( struct V_9 * V_10 )
{
F_60 ( F_58 ( V_10 ) ) ;
}
T_1 F_61 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned int V_36 ;
T_1 V_62 ;
V_5 V_90 ;
F_60 ( V_91 ) ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_62 = V_2 -> V_3 . V_62 ;
V_90 = F_24 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return F_62 ( V_62 , V_90 ) ;
}
T_2 F_63 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned int V_36 ;
T_2 V_90 ;
F_60 ( V_91 ) ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_90 = V_2 -> V_3 . V_47 >> V_2 -> V_3 . V_7 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_90 ;
}
T_1 F_64 ( enum V_93 V_94 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned int V_36 ;
T_1 V_62 , * V_21 = V_95 [ V_94 ] ;
V_5 V_90 ;
F_60 ( V_91 ) ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_62 = F_9 ( V_2 -> V_3 . V_62 , * V_21 ) ;
V_90 = F_24 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return F_62 ( V_62 , V_90 ) ;
}
T_1 F_65 ( T_1 V_96 , enum V_93 V_94 )
{
T_1 * V_21 = V_95 [ V_94 ] ;
unsigned long V_36 ;
T_1 V_97 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_97 = F_9 ( V_96 , * V_21 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_97 ;
}
T_1 F_66 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned int V_36 ;
T_1 V_62 ;
V_5 V_90 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_62 = V_2 -> V_45 . V_62 ;
V_90 = F_24 ( & V_2 -> V_45 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return F_62 ( V_62 , V_90 ) ;
}
void F_67 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_9 V_98 ;
unsigned int V_36 ;
V_5 V_58 ;
F_60 ( V_91 ) ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_58 = F_24 ( & V_2 -> V_3 ) ;
V_98 = V_2 -> V_15 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
V_10 -> V_11 += V_98 . V_11 ;
V_10 -> V_12 = 0 ;
F_57 ( V_10 , V_58 + V_98 . V_12 ) ;
}
T_6 F_68 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
F_60 ( V_91 ) ;
return V_2 -> V_83 ;
}
T_6 F_69 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
T_6 V_81 ;
unsigned int V_36 ;
if ( F_70 ( V_99 ) )
return V_2 -> V_8 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_81 = V_2 -> V_8 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_81 ;
}
T_6 F_71 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
return V_2 -> V_8 ;
}
void F_72 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_36 ;
T_1 V_102 ;
T_1 V_103 ;
V_5 V_104 ;
V_5 V_105 ;
V_5 V_32 ;
F_7 ( V_91 ) ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_32 = V_2 -> V_3 . V_37 ( V_2 -> V_3 . clock ) ;
V_101 -> V_44 = V_2 -> V_44 ;
V_101 -> V_87 = V_2 -> V_87 ;
V_103 = F_9 ( V_2 -> V_3 . V_62 ,
V_31 . V_1 . V_16 ) ;
V_102 = V_2 -> V_45 . V_62 ;
V_105 = F_25 ( & V_2 -> V_3 , V_32 ) ;
V_104 = F_25 ( & V_2 -> V_45 , V_32 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
V_101 -> V_59 = V_32 ;
V_101 -> V_106 = F_62 ( V_103 , V_105 ) ;
V_101 -> V_107 = F_62 ( V_102 , V_104 ) ;
}
static int F_73 ( V_5 V_47 , V_5 div , V_5 * V_62 )
{
V_5 V_14 , V_108 ;
V_14 = F_74 ( * V_62 , div , & V_108 ) ;
if ( ( ( int ) sizeof( V_5 ) * 8 - F_75 ( V_47 ) < F_75 ( V_14 ) ) ||
( ( int ) sizeof( V_5 ) * 8 - F_75 ( V_47 ) < F_75 ( V_108 ) ) )
return - V_109 ;
V_14 *= V_47 ;
V_108 *= V_47 ;
F_20 ( V_108 , div ) ;
* V_62 = V_14 + V_108 ;
return 0 ;
}
static int F_76 ( struct V_100 * V_110 ,
V_5 V_111 ,
V_5 V_112 ,
bool V_113 ,
struct V_114 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
V_5 V_115 , V_116 ;
bool V_117 ;
int V_77 ;
if ( V_112 == 0 || V_111 == 0 )
return 0 ;
V_117 = V_111 > V_112 / 2 ?
true : false ;
V_111 = V_117 ?
V_112 - V_111 :
V_111 ;
V_115 = ( V_5 ) F_30 (
F_50 ( V_10 -> V_118 , V_110 -> V_107 ) ) ;
V_77 = F_73 ( V_111 ,
V_112 , & V_115 ) ;
if ( V_77 )
return V_77 ;
if ( V_113 ) {
V_116 = F_77
( V_115 , V_2 -> V_3 . V_47 , V_2 -> V_45 . V_47 ) ;
} else {
V_116 = ( V_5 ) F_30 (
F_50 ( V_10 -> V_119 , V_110 -> V_106 ) ) ;
V_77 = F_73 ( V_111 ,
V_112 , & V_116 ) ;
if ( V_77 )
return V_77 ;
}
if ( V_117 ) {
V_10 -> V_118 = F_62 ( V_110 -> V_107 , V_115 ) ;
V_10 -> V_119 = F_62 ( V_110 -> V_106 , V_116 ) ;
} else {
V_10 -> V_118 = F_78 ( V_10 -> V_118 , V_115 ) ;
V_10 -> V_119 = F_78 ( V_10 -> V_119 , V_116 ) ;
}
return 0 ;
}
static bool F_79 ( V_5 V_120 , V_5 V_121 , V_5 V_122 )
{
if ( V_121 > V_120 && V_121 < V_122 )
return true ;
if ( V_121 < V_120 && V_120 > V_122 )
return true ;
return false ;
}
int F_80 ( int (* F_81)
( T_1 * V_123 ,
struct V_124 * V_125 ,
void * V_126 ) ,
void * V_126 ,
struct V_100 * V_127 ,
struct V_114 * V_128 )
{
struct V_124 V_129 ;
struct V_1 * V_2 = & V_31 . V_1 ;
V_5 V_59 , V_32 , V_130 ;
unsigned int V_87 = 0 ;
T_1 V_103 , V_102 ;
V_5 V_105 , V_104 ;
T_7 V_44 ;
unsigned long V_36 ;
bool V_131 ;
int V_77 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_77 = F_81 ( & V_128 -> V_132 , & V_129 , V_126 ) ;
if ( V_77 )
return V_77 ;
if ( V_2 -> V_3 . clock != V_129 . V_65 )
return - V_133 ;
V_59 = V_129 . V_59 ;
V_32 = V_2 -> V_3 . V_37 ( V_2 -> V_3 . clock ) ;
V_130 = V_2 -> V_3 . V_38 ;
if ( ! F_79 ( V_130 , V_59 , V_32 ) ) {
V_87 = V_2 -> V_87 ;
V_44 = V_2 -> V_44 ;
V_59 = V_130 ;
V_131 = true ;
} else {
V_131 = false ;
}
V_103 = F_9 ( V_2 -> V_3 . V_62 ,
V_31 . V_1 . V_16 ) ;
V_102 = V_2 -> V_45 . V_62 ;
V_105 = F_25 ( & V_2 -> V_3 ,
V_129 . V_59 ) ;
V_104 = F_25 ( & V_2 -> V_45 ,
V_129 . V_59 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
V_128 -> V_119 = F_62 ( V_103 , V_105 ) ;
V_128 -> V_118 = F_62 ( V_102 , V_104 ) ;
if ( V_131 ) {
V_5 V_111 , V_112 ;
bool V_113 ;
if ( ! V_127 ||
! F_79 ( V_127 -> V_59 ,
V_129 . V_59 , V_59 ) ||
V_127 -> V_44 != V_44 )
return - V_134 ;
V_111 = V_59 - V_129 . V_59 ;
V_112 = V_59 - V_127 -> V_59 ;
V_113 =
V_127 -> V_87 != V_87 ;
V_77 = F_76 ( V_127 ,
V_111 ,
V_112 ,
V_113 , V_128 ) ;
if ( V_77 )
return V_77 ;
}
return 0 ;
}
void F_82 ( struct V_135 * V_136 )
{
struct V_9 V_32 ;
F_59 ( & V_32 ) ;
V_136 -> V_11 = V_32 . V_11 ;
V_136 -> V_137 = V_32 . V_12 / 1000 ;
}
int F_83 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_9 V_138 , V_69 ;
unsigned long V_76 ;
int V_77 = 0 ;
if ( ! F_84 ( V_10 ) )
return - V_134 ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_55 ( V_2 ) ;
V_69 = F_2 ( V_2 ) ;
V_138 . V_11 = V_10 -> V_11 - V_69 . V_11 ;
V_138 . V_12 = V_10 -> V_12 - V_69 . V_12 ;
if ( F_86 ( & V_2 -> V_15 , & V_138 ) > 0 ) {
V_77 = - V_134 ;
goto V_139;
}
F_5 ( V_2 , F_87 ( V_2 -> V_15 , V_138 ) ) ;
F_3 ( V_2 , V_10 ) ;
V_139:
F_53 ( V_2 , V_85 | V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
F_89 () ;
return V_77 ;
}
int F_90 ( struct V_68 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_76 ;
struct V_9 V_140 , V_14 ;
int V_77 = 0 ;
if ( ! F_91 ( V_10 ) )
return - V_134 ;
V_140 = F_92 ( * V_10 ) ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_55 ( V_2 ) ;
V_14 = F_93 ( F_2 ( V_2 ) , V_140 ) ;
if ( F_86 ( & V_2 -> V_15 , & V_140 ) > 0 ||
! F_84 ( & V_14 ) ) {
V_77 = - V_134 ;
goto error;
}
F_4 ( V_2 , & V_140 ) ;
F_5 ( V_2 , F_87 ( V_2 -> V_15 , V_140 ) ) ;
error:
F_53 ( V_2 , V_85 | V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
F_89 () ;
return V_77 ;
}
T_8 F_94 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned int V_36 ;
T_8 V_77 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_77 = V_2 -> V_18 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_77 ;
}
static void F_95 ( struct V_1 * V_2 , T_8 V_18 )
{
V_2 -> V_18 = V_18 ;
V_2 -> V_17 = F_9 ( V_2 -> V_16 , F_10 ( V_18 , 0 ) ) ;
}
void F_96 ( T_8 V_18 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_76 ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_95 ( V_2 , V_18 ) ;
F_53 ( V_2 , V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
F_89 () ;
}
static int F_97 ( void * V_141 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_40 * V_142 , * V_143 ;
unsigned long V_76 ;
V_142 = (struct V_40 * ) V_141 ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_55 ( V_2 ) ;
if ( F_98 ( V_142 -> V_144 ) ) {
if ( ! V_142 -> V_145 || V_142 -> V_145 ( V_142 ) == 0 ) {
V_143 = V_2 -> V_3 . clock ;
F_19 ( V_2 , V_142 ) ;
if ( V_143 -> V_146 )
V_143 -> V_146 ( V_143 ) ;
F_99 ( V_143 -> V_144 ) ;
} else {
F_99 ( V_142 -> V_144 ) ;
}
}
F_53 ( V_2 , V_85 | V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
return 0 ;
}
int F_100 ( struct V_40 * clock )
{
struct V_1 * V_2 = & V_31 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_101 ( F_97 , clock , NULL ) ;
F_102 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_103 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_9 V_140 ;
unsigned long V_36 ;
V_5 V_90 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_90 = F_24 ( & V_2 -> V_45 ) ;
V_140 = V_2 -> V_82 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
F_57 ( & V_140 , V_90 ) ;
* V_10 = V_140 ;
}
int F_104 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_36 ;
int V_77 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_77 = V_2 -> V_3 . clock -> V_76 & V_147 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_77 ;
}
V_5 F_105 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_36 ;
V_5 V_77 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_77 = V_2 -> V_3 . clock -> V_148 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_77 ;
}
void __weak F_106 ( struct V_68 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_107 ( struct V_9 * V_140 )
{
struct V_68 V_10 ;
F_106 ( & V_10 ) ;
* V_140 = F_92 ( V_10 ) ;
}
void __weak F_108 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_9 F_109 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_40 * clock ;
unsigned long V_76 ;
struct V_9 V_32 , V_149 , V_14 ;
F_107 ( & V_32 ) ;
if ( ! F_84 ( & V_32 ) ) {
F_110 ( L_9
L_10 ) ;
V_32 . V_11 = 0 ;
V_32 . V_12 = 0 ;
} else if ( V_32 . V_11 || V_32 . V_12 )
V_150 = true ;
F_108 ( & V_149 ) ;
if ( ! F_84 ( & V_149 ) ) {
F_110 ( L_11
L_10 ) ;
V_149 . V_11 = 0 ;
V_149 . V_12 = 0 ;
}
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_111 () ;
clock = F_112 () ;
if ( clock -> V_145 )
clock -> V_145 ( clock ) ;
F_19 ( V_2 , clock ) ;
F_3 ( V_2 , & V_32 ) ;
V_2 -> V_82 . V_11 = 0 ;
V_2 -> V_82 . V_12 = 0 ;
if ( V_149 . V_11 == 0 && V_149 . V_12 == 0 )
V_149 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_149 . V_11 , - V_149 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_53 ( V_2 , V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_9 * V_19 )
{
if ( ! F_84 ( V_19 ) ) {
F_13 ( V_151
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_19 ) ;
F_5 ( V_2 , F_87 ( V_2 -> V_15 , * V_19 ) ) ;
F_11 ( V_2 , F_8 ( * V_19 ) ) ;
F_114 ( V_19 ) ;
}
bool F_115 ( void )
{
return V_152 ;
}
bool F_116 ( void )
{
return V_150 ;
}
void F_117 ( struct V_9 * V_19 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_76 ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_55 ( V_2 ) ;
F_113 ( V_2 , V_19 ) ;
F_53 ( V_2 , V_85 | V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
F_89 () ;
}
void F_118 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_40 * clock = V_2 -> V_3 . clock ;
unsigned long V_76 ;
struct V_9 V_153 , V_138 ;
V_5 V_39 ;
V_152 = false ;
F_107 ( & V_153 ) ;
F_119 () ;
F_120 () ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
V_39 = V_2 -> V_3 . V_37 ( clock ) ;
if ( ( clock -> V_76 & V_154 ) &&
V_39 > V_2 -> V_3 . V_38 ) {
V_5 V_58 , V_155 ;
V_155 = F_17 ( V_39 , V_2 -> V_3 . V_38 ,
V_2 -> V_3 . V_34 ) ;
V_58 = F_121 ( V_155 , clock -> V_47 , clock -> V_7 ) ;
V_138 = F_122 ( V_58 ) ;
V_152 = true ;
} else if ( F_86 ( & V_153 , & V_156 ) > 0 ) {
V_138 = F_87 ( V_153 , V_156 ) ;
V_152 = true ;
}
if ( V_152 )
F_113 ( V_2 , & V_138 ) ;
V_2 -> V_3 . V_38 = V_39 ;
V_2 -> V_45 . V_38 = V_39 ;
V_2 -> V_53 = 0 ;
V_91 = 0 ;
F_53 ( V_2 , V_88 | V_86 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
F_123 () ;
F_124 () ;
F_125 () ;
}
int F_126 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_76 ;
struct V_9 V_19 , V_157 ;
static struct V_9 V_158 ;
F_107 ( & V_156 ) ;
if ( V_156 . V_11 || V_156 . V_12 )
V_150 = true ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_55 ( V_2 ) ;
V_91 = 1 ;
if ( V_150 ) {
V_19 = F_87 ( F_2 ( V_2 ) , V_156 ) ;
V_157 = F_87 ( V_19 , V_158 ) ;
if ( abs ( V_157 . V_11 ) >= 2 ) {
V_158 = V_19 ;
} else {
V_156 =
F_93 ( V_156 , V_157 ) ;
}
}
F_53 ( V_2 , V_88 ) ;
F_35 ( V_2 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
F_127 () ;
F_128 () ;
F_129 () ;
return 0 ;
}
static int T_9 F_130 ( void )
{
F_131 ( & V_159 ) ;
return 0 ;
}
static T_3 void F_132 ( struct V_1 * V_2 ,
T_5 V_21 ,
bool V_160 ,
int V_161 )
{
T_5 V_41 = V_2 -> V_48 ;
T_8 V_162 = 1 ;
if ( V_160 ) {
V_162 = - V_162 ;
V_41 = - V_41 ;
V_21 = - V_21 ;
}
V_162 <<= V_161 ;
V_41 <<= V_161 ;
V_21 <<= V_161 ;
if ( ( V_162 > 0 ) && ( V_2 -> V_3 . V_47 + V_162 < V_162 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_47 += V_162 ;
V_2 -> V_49 += V_41 ;
V_2 -> V_3 . V_4 -= V_21 ;
V_2 -> V_53 -= ( V_41 - V_21 ) << V_2 -> V_54 ;
}
static T_3 void F_133 ( struct V_1 * V_2 ,
T_5 V_21 )
{
T_5 V_41 = V_2 -> V_48 ;
T_5 V_163 = V_2 -> V_49 ;
T_2 V_62 = V_2 -> V_3 . clock -> V_47 ;
T_2 V_35 = V_2 -> V_3 . clock -> V_164 ;
T_2 V_165 = V_2 -> V_3 . V_47 ;
T_5 V_166 ;
bool V_160 ;
T_2 V_161 ;
if ( V_2 -> V_57 )
V_163 -= V_2 -> V_48 ;
V_2 -> V_56 = F_134 () ;
V_166 = F_134 () >> V_2 -> V_54 ;
V_166 -= ( V_163 + V_2 -> V_50 ) ;
if ( F_135 ( ( V_166 >= 0 ) && ( V_166 <= V_41 ) ) )
return;
V_160 = ( V_166 < 0 ) ;
if ( V_160 && ( V_165 - 1 ) <= ( V_62 - V_35 ) )
return;
if ( ! V_160 && ( V_165 + 1 ) >= ( V_62 + V_35 ) )
return;
V_161 = 0 ;
V_166 = abs ( V_166 ) ;
while ( V_166 > V_41 ) {
T_2 V_167 = 1 << ( V_161 + 1 ) ;
if ( V_160 && ( V_165 - V_167 ) <= ( V_62 - V_35 ) )
break;
if ( ! V_160 && ( V_165 + V_167 ) >= ( V_62 + V_35 ) )
break;
V_161 ++ ;
V_166 >>= 1 ;
}
F_132 ( V_2 , V_21 , V_160 , V_161 ) ;
}
static void F_136 ( struct V_1 * V_2 , T_5 V_21 )
{
F_133 ( V_2 , V_21 ) ;
if ( ! V_2 -> V_57 && ( V_2 -> V_53 > 0 ) ) {
V_2 -> V_57 = 1 ;
F_132 ( V_2 , V_21 , 0 , 0 ) ;
} else if ( V_2 -> V_57 && ( V_2 -> V_53 <= 0 ) ) {
F_132 ( V_2 , V_21 , 1 , 0 ) ;
V_2 -> V_57 = 0 ;
}
if ( F_18 ( V_2 -> V_3 . clock -> V_164 &&
( abs ( V_2 -> V_3 . V_47 - V_2 -> V_3 . clock -> V_47 )
> V_2 -> V_3 . clock -> V_164 ) ) ) {
F_137 ( V_151
L_14 ,
V_2 -> V_3 . clock -> V_23 , ( long ) V_2 -> V_3 . V_47 ,
( long ) V_2 -> V_3 . clock -> V_47 + V_2 -> V_3 . clock -> V_164 ) ;
}
if ( F_18 ( ( T_5 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_5 V_168 = - ( T_5 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_53 += V_168 << V_2 -> V_54 ;
}
}
static inline unsigned int F_138 ( struct V_1 * V_2 )
{
V_5 V_169 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_170 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_169 ) {
int V_171 ;
V_2 -> V_3 . V_4 -= V_169 ;
V_2 -> V_8 ++ ;
V_171 = F_139 ( V_2 -> V_8 ) ;
if ( F_18 ( V_171 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_171 ;
V_10 . V_11 = V_171 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_87 ( V_2 -> V_15 , V_10 ) ) ;
F_95 ( V_2 , V_2 -> V_18 - V_171 ) ;
V_170 = V_86 ;
}
}
return V_170 ;
}
static V_5 F_140 ( struct V_1 * V_2 , V_5 V_21 ,
T_2 V_7 , unsigned int * V_170 )
{
V_5 V_41 = V_2 -> V_48 << V_7 ;
V_5 V_172 ;
if ( V_21 < V_41 )
return V_21 ;
V_21 -= V_41 ;
V_2 -> V_3 . V_38 += V_41 ;
V_2 -> V_45 . V_38 += V_41 ;
V_2 -> V_3 . V_4 += V_2 -> V_49 << V_7 ;
* V_170 |= F_138 ( V_2 ) ;
V_172 = ( V_5 ) V_2 -> V_51 << V_7 ;
V_172 += V_2 -> V_82 . V_12 ;
if ( V_172 >= V_6 ) {
V_5 V_173 = V_172 ;
V_172 = F_20 ( V_173 , V_6 ) ;
V_2 -> V_82 . V_11 += V_173 ;
}
V_2 -> V_82 . V_12 = V_172 ;
V_2 -> V_53 += V_2 -> V_56 << V_7 ;
V_2 -> V_53 -= ( V_2 -> V_49 + V_2 -> V_50 ) <<
( V_2 -> V_54 + V_7 ) ;
return V_21 ;
}
void F_141 ( void )
{
struct V_1 * V_174 = & V_31 . V_1 ;
struct V_1 * V_2 = & V_89 ;
V_5 V_21 ;
int V_7 = 0 , V_175 ;
unsigned int V_170 = 0 ;
unsigned long V_76 ;
F_43 ( & V_78 , V_76 ) ;
if ( F_18 ( V_91 ) )
goto V_139;
#ifdef F_142
V_21 = V_174 -> V_48 ;
#else
V_21 = F_17 ( V_2 -> V_3 . V_37 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_38 , V_2 -> V_3 . V_34 ) ;
#endif
if ( V_21 < V_174 -> V_48 )
goto V_139;
F_12 ( V_174 , V_21 ) ;
V_7 = F_143 ( V_21 ) - F_143 ( V_2 -> V_48 ) ;
V_7 = V_35 ( 0 , V_7 ) ;
V_175 = ( 64 - ( F_143 ( F_134 () ) + 1 ) ) - 1 ;
V_7 = F_144 ( V_7 , V_175 ) ;
while ( V_21 >= V_2 -> V_48 ) {
V_21 = F_140 ( V_2 , V_21 , V_7 ,
& V_170 ) ;
if ( V_21 < V_2 -> V_48 << V_7 )
V_7 -- ;
}
F_136 ( V_2 , V_21 ) ;
F_39 ( V_2 ) ;
V_170 |= F_138 ( V_2 ) ;
F_85 ( & V_31 . V_36 ) ;
F_53 ( V_2 , V_170 ) ;
memcpy ( V_174 , V_2 , sizeof( * V_2 ) ) ;
F_88 ( & V_31 . V_36 ) ;
V_139:
F_45 ( & V_78 , V_76 ) ;
if ( V_170 )
F_145 () ;
}
void F_146 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
T_1 V_176 = F_50 ( V_2 -> V_16 , V_2 -> V_20 ) ;
* V_10 = F_147 ( V_176 ) ;
}
unsigned long F_148 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
return V_2 -> V_8 ;
}
struct V_68 F_149 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
return F_37 ( F_2 ( V_2 ) ) ;
}
struct V_9 F_150 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_9 V_32 ;
unsigned long V_36 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_32 = F_2 ( V_2 ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_32 ;
}
struct V_9 F_151 ( void )
{
struct V_1 * V_2 = & V_31 . V_1 ;
struct V_9 V_32 , V_177 ;
unsigned long V_36 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_32 = F_2 ( V_2 ) ;
V_177 = V_2 -> V_15 ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
F_6 ( & V_32 , V_32 . V_11 + V_177 . V_11 ,
V_32 . V_12 + V_177 . V_12 ) ;
return V_32 ;
}
void F_152 ( unsigned long V_178 )
{
V_179 += V_178 ;
F_153 ( V_178 ) ;
}
T_1 F_154 ( unsigned int * V_180 , T_1 * V_16 ,
T_1 * V_20 , T_1 * V_17 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned int V_36 ;
T_1 V_62 ;
V_5 V_90 ;
do {
V_36 = F_15 ( & V_31 . V_36 ) ;
V_62 = V_2 -> V_3 . V_62 ;
V_90 = F_24 ( & V_2 -> V_3 ) ;
V_62 = F_62 ( V_62 , V_90 ) ;
if ( * V_180 != V_2 -> V_87 ) {
* V_180 = V_2 -> V_87 ;
* V_16 = V_2 -> V_16 ;
* V_20 = V_2 -> V_20 ;
* V_17 = V_2 -> V_17 ;
}
if ( F_18 ( V_62 >= V_2 -> V_79 ) )
* V_16 = F_50 ( V_2 -> V_16 , F_10 ( 1 , 0 ) ) ;
} while ( F_16 ( & V_31 . V_36 , V_36 ) );
return V_62 ;
}
int F_155 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = & V_31 . V_1 ;
unsigned long V_76 ;
struct V_9 V_10 ;
T_8 V_183 , V_184 ;
int V_77 ;
V_77 = F_156 ( V_182 ) ;
if ( V_77 )
return V_77 ;
if ( V_182 -> V_185 & V_186 ) {
struct V_68 V_19 ;
V_19 . V_11 = V_182 -> time . V_11 ;
V_19 . V_12 = V_182 -> time . V_137 ;
if ( ! ( V_182 -> V_185 & V_187 ) )
V_19 . V_12 *= 1000 ;
V_77 = F_90 ( & V_19 ) ;
if ( V_77 )
return V_77 ;
}
F_59 ( & V_10 ) ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
V_183 = V_184 = V_2 -> V_18 ;
V_77 = F_157 ( V_182 , & V_10 , & V_184 ) ;
if ( V_184 != V_183 ) {
F_95 ( V_2 , V_184 ) ;
F_53 ( V_2 , V_88 | V_86 ) ;
}
F_48 ( V_2 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
if ( V_184 != V_183 )
F_89 () ;
F_158 () ;
return V_77 ;
}
void F_159 ( const struct V_9 * V_188 , const struct V_9 * V_189 )
{
unsigned long V_76 ;
F_43 ( & V_78 , V_76 ) ;
F_85 ( & V_31 . V_36 ) ;
F_160 ( V_188 , V_189 ) ;
F_88 ( & V_31 . V_36 ) ;
F_45 ( & V_78 , V_76 ) ;
}
void F_161 ( unsigned long V_178 )
{
F_162 ( & V_190 ) ;
F_152 ( V_178 ) ;
F_163 ( & V_190 ) ;
F_141 () ;
}
