static inline void F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 . V_4 >= ( ( V_5 ) V_6 << V_2 -> V_3 . V_7 ) ) {
V_2 -> V_3 . V_4 -= ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
V_2 -> V_8 ++ ;
}
while ( V_2 -> V_9 . V_4 >= ( ( V_5 ) V_6 << V_2 -> V_9 . V_7 ) ) {
V_2 -> V_9 . V_4 -= ( V_5 ) V_6 << V_2 -> V_9 . V_7 ;
V_2 -> V_10 ++ ;
}
}
static inline struct V_11 F_2 ( struct V_1 * V_2 )
{
struct V_11 V_12 ;
V_12 . V_13 = V_2 -> V_8 ;
V_12 . V_14 = ( long ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
return V_12 ;
}
static void F_3 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
V_2 -> V_8 = V_12 -> V_13 ;
V_2 -> V_3 . V_4 = ( V_5 ) V_12 -> V_14 << V_2 -> V_3 . V_7 ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_11 * V_12 )
{
V_2 -> V_8 += V_12 -> V_13 ;
V_2 -> V_3 . V_4 += ( V_5 ) V_12 -> V_14 << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_11 V_15 )
{
struct V_11 V_16 ;
F_6 ( & V_16 , - V_2 -> V_17 . V_13 ,
- V_2 -> V_17 . V_14 ) ;
F_7 ( V_2 -> V_18 != F_8 ( V_16 ) ) ;
V_2 -> V_17 = V_15 ;
F_6 ( & V_16 , - V_15 . V_13 , - V_15 . V_14 ) ;
V_2 -> V_18 = F_8 ( V_16 ) ;
V_2 -> V_19 = F_9 ( V_2 -> V_18 , F_10 ( V_2 -> V_20 , 0 ) ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_21 )
{
V_2 -> V_22 = F_9 ( V_2 -> V_22 , V_21 ) ;
}
static inline V_5 F_12 ( struct V_23 * V_24 )
{
struct V_25 * clock = F_13 ( V_24 -> clock ) ;
return clock -> V_26 ( clock ) ;
}
static void F_14 ( struct V_1 * V_2 , V_5 V_27 )
{
V_5 V_28 = V_2 -> V_3 . clock -> V_28 ;
const char * V_29 = V_2 -> V_3 . clock -> V_29 ;
if ( V_27 > V_28 ) {
F_15 ( L_1 ,
V_27 , V_29 , V_28 ) ;
F_15 ( L_2 ) ;
} else {
if ( V_27 > ( V_28 >> 1 ) ) {
F_15 ( L_3 ,
V_27 , V_29 , V_28 >> 1 ) ;
F_15 ( L_4 ) ;
}
}
if ( V_2 -> V_30 ) {
if ( V_31 - V_2 -> V_32 > V_33 ) {
F_15 ( L_5 , V_29 ) ;
F_15 ( L_6 ) ;
F_15 ( L_7 ) ;
V_2 -> V_32 = V_31 ;
}
V_2 -> V_30 = 0 ;
}
if ( V_2 -> V_34 ) {
if ( V_31 - V_2 -> V_32 > V_33 ) {
F_15 ( L_8 , V_29 ) ;
F_15 ( L_6 ) ;
F_15 ( L_7 ) ;
V_2 -> V_32 = V_31 ;
}
V_2 -> V_34 = 0 ;
}
}
static inline V_5 F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
V_5 V_36 , V_37 , V_38 , V_39 , V_21 ;
unsigned int V_40 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_36 = F_12 ( V_24 ) ;
V_37 = V_24 -> V_41 ;
V_38 = V_24 -> V_38 ;
V_39 = V_24 -> clock -> V_28 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
V_21 = F_19 ( V_36 , V_37 , V_38 ) ;
if ( F_20 ( ( ~ V_21 & V_38 ) < ( V_38 >> 3 ) ) ) {
V_2 -> V_30 = 1 ;
V_21 = 0 ;
}
if ( F_20 ( V_21 > V_39 ) ) {
V_2 -> V_34 = 1 ;
V_21 = V_24 -> clock -> V_28 ;
}
return V_21 ;
}
static inline void F_14 ( struct V_1 * V_2 , V_5 V_27 )
{
}
static inline V_5 F_16 ( struct V_23 * V_24 )
{
V_5 V_42 , V_21 ;
V_42 = F_12 ( V_24 ) ;
V_21 = F_19 ( V_42 , V_24 -> V_41 , V_24 -> V_38 ) ;
return V_21 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_25 * clock )
{
V_5 V_43 ;
V_5 V_16 , V_44 ;
struct V_25 * V_45 ;
++ V_2 -> V_46 ;
V_45 = V_2 -> V_3 . clock ;
V_2 -> V_3 . clock = clock ;
V_2 -> V_3 . V_38 = clock -> V_38 ;
V_2 -> V_3 . V_41 = F_12 ( & V_2 -> V_3 ) ;
V_2 -> V_9 . clock = clock ;
V_2 -> V_9 . V_38 = clock -> V_38 ;
V_2 -> V_9 . V_41 = V_2 -> V_3 . V_41 ;
V_16 = V_47 ;
V_16 <<= clock -> V_7 ;
V_44 = V_16 ;
V_16 += clock -> V_48 / 2 ;
F_22 ( V_16 , clock -> V_48 ) ;
if ( V_16 == 0 )
V_16 = 1 ;
V_43 = ( V_5 ) V_16 ;
V_2 -> V_49 = V_43 ;
V_2 -> V_50 = V_43 * clock -> V_48 ;
V_2 -> V_51 = V_44 - V_2 -> V_50 ;
V_2 -> V_52 = V_43 * clock -> V_48 ;
if ( V_45 ) {
int V_53 = clock -> V_7 - V_45 -> V_7 ;
if ( V_53 < 0 ) {
V_2 -> V_3 . V_4 >>= - V_53 ;
V_2 -> V_9 . V_4 >>= - V_53 ;
} else {
V_2 -> V_3 . V_4 <<= V_53 ;
V_2 -> V_9 . V_4 <<= V_53 ;
}
}
V_2 -> V_3 . V_7 = clock -> V_7 ;
V_2 -> V_9 . V_7 = clock -> V_7 ;
V_2 -> V_54 = 0 ;
V_2 -> V_55 = V_56 - clock -> V_7 ;
V_2 -> V_57 = V_44 << V_2 -> V_55 ;
V_2 -> V_3 . V_48 = clock -> V_48 ;
V_2 -> V_9 . V_48 = clock -> V_48 ;
V_2 -> V_58 = 0 ;
}
static T_2 F_23 ( void ) { return 0 ; }
static inline T_2 F_24 ( void ) { return 0 ; }
static inline V_5 F_25 ( struct V_23 * V_24 , V_5 V_21 )
{
V_5 V_59 ;
V_59 = V_21 * V_24 -> V_48 + V_24 -> V_4 ;
V_59 >>= V_24 -> V_7 ;
return V_59 + F_24 () ;
}
static inline V_5 F_26 ( struct V_23 * V_24 )
{
V_5 V_21 ;
V_21 = F_16 ( V_24 ) ;
return F_25 ( V_24 , V_21 ) ;
}
static inline V_5 F_27 ( struct V_23 * V_24 , V_5 V_60 )
{
V_5 V_21 ;
V_21 = F_19 ( V_60 , V_24 -> V_41 , V_24 -> V_38 ) ;
return F_25 ( V_24 , V_21 ) ;
}
static void F_28 ( struct V_23 * V_24 , struct V_61 * V_62 )
{
struct V_23 * V_63 = V_62 -> V_63 ;
F_29 ( & V_62 -> V_40 ) ;
memcpy ( V_63 , V_24 , sizeof( * V_63 ) ) ;
F_29 ( & V_62 -> V_40 ) ;
memcpy ( V_63 + 1 , V_63 , sizeof( * V_63 ) ) ;
}
static T_3 V_5 F_30 ( struct V_61 * V_62 )
{
struct V_23 * V_24 ;
unsigned int V_40 ;
V_5 V_36 ;
do {
V_40 = F_31 ( & V_62 -> V_40 ) ;
V_24 = V_62 -> V_63 + ( V_40 & 0x01 ) ;
V_36 = F_32 ( V_24 -> V_63 ) ;
V_36 += F_25 ( V_24 ,
F_19 (
F_12 ( V_24 ) ,
V_24 -> V_41 ,
V_24 -> V_38 ) ) ;
} while ( F_18 ( & V_62 -> V_40 , V_40 ) );
return V_36 ;
}
V_5 F_33 ( void )
{
return F_30 ( & V_64 ) ;
}
V_5 F_34 ( void )
{
return F_30 ( & V_65 ) ;
}
V_5 T_4 F_35 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
return ( F_33 () + F_32 ( V_2 -> V_22 ) ) ;
}
static V_5 F_36 ( struct V_25 * V_66 )
{
return V_67 ;
}
static void F_37 ( struct V_1 * V_2 )
{
static struct V_23 V_68 ;
struct V_23 * V_24 = & V_2 -> V_3 ;
memcpy ( & V_68 , V_24 , sizeof( V_68 ) ) ;
V_67 = F_12 ( V_24 ) ;
V_68 . clock = & V_69 ;
F_28 ( & V_68 , & V_64 ) ;
V_24 = & V_2 -> V_9 ;
memcpy ( & V_68 , V_24 , sizeof( V_68 ) ) ;
V_68 . clock = & V_69 ;
F_28 ( & V_68 , & V_65 ) ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
struct V_70 V_71 , V_72 ;
V_71 = F_39 ( F_2 ( V_2 ) ) ;
V_72 = F_39 ( V_2 -> V_17 ) ;
F_40 ( & V_71 , & V_72 , V_2 -> V_3 . clock , V_2 -> V_3 . V_48 ,
V_2 -> V_3 . V_41 ) ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
T_5 V_73 ;
V_73 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
if ( V_73 != 0 ) {
V_2 -> V_3 . V_4 -= V_73 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_54 += V_73 << V_2 -> V_55 ;
V_2 -> V_54 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_55 ;
}
}
static void F_42 ( struct V_1 * V_2 , bool V_74 )
{
F_43 ( & V_75 , V_74 , V_2 ) ;
}
int F_44 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_78 ;
int V_79 ;
F_45 ( & V_80 , V_78 ) ;
V_79 = F_46 ( & V_75 , V_77 ) ;
F_42 ( V_2 , true ) ;
F_47 ( & V_80 , V_78 ) ;
return V_79 ;
}
int F_48 ( struct V_76 * V_77 )
{
unsigned long V_78 ;
int V_79 ;
F_45 ( & V_80 , V_78 ) ;
V_79 = F_49 ( & V_75 , V_77 ) ;
F_47 ( & V_80 , V_78 ) ;
return V_79 ;
}
static inline void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_81 = F_51 () ;
if ( V_2 -> V_81 != V_82 )
V_2 -> V_81 = F_52 ( V_2 -> V_81 , V_2 -> V_18 ) ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
V_5 V_83 ;
T_2 V_59 ;
V_83 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_17 . V_13 ) ;
V_59 = ( T_2 ) V_2 -> V_17 . V_14 ;
V_2 -> V_3 . V_63 = F_54 ( V_83 * V_6 + V_59 ) ;
V_59 += ( T_2 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_59 >= V_6 )
V_83 ++ ;
V_2 -> V_84 = V_83 ;
V_2 -> V_9 . V_63 = F_54 ( V_2 -> V_10 * V_6 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_85 )
{
if ( V_85 & V_86 ) {
V_2 -> V_54 = 0 ;
F_56 () ;
}
F_50 ( V_2 ) ;
F_53 ( V_2 ) ;
F_38 ( V_2 ) ;
F_42 ( V_2 , V_85 & V_87 ) ;
F_28 ( & V_2 -> V_3 , & V_64 ) ;
F_28 ( & V_2 -> V_9 , & V_65 ) ;
if ( V_85 & V_87 )
V_2 -> V_88 ++ ;
if ( V_85 & V_89 )
memcpy ( & V_90 , & V_35 . V_1 ,
sizeof( V_35 . V_1 ) ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
V_5 V_42 , V_21 ;
V_42 = F_12 ( & V_2 -> V_3 ) ;
V_21 = F_19 ( V_42 , V_2 -> V_3 . V_41 , V_2 -> V_3 . V_38 ) ;
V_2 -> V_3 . V_41 = V_42 ;
V_2 -> V_9 . V_41 = V_42 ;
V_2 -> V_3 . V_4 += V_21 * V_2 -> V_3 . V_48 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_24 () << V_2 -> V_3 . V_7 ;
V_2 -> V_9 . V_4 += V_21 * V_2 -> V_9 . V_48 ;
V_2 -> V_9 . V_4 += ( V_5 ) F_24 () << V_2 -> V_9 . V_7 ;
F_1 ( V_2 ) ;
}
int F_58 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_40 ;
V_5 V_91 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_12 -> V_13 = V_2 -> V_8 ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
V_12 -> V_14 = 0 ;
F_59 ( V_12 , V_91 ) ;
if ( F_20 ( V_92 ) )
return - V_93 ;
return 0 ;
}
void F_60 ( struct V_11 * V_12 )
{
F_61 ( F_58 ( V_12 ) ) ;
}
T_1 F_62 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned int V_40 ;
T_1 V_63 ;
V_5 V_91 ;
F_61 ( V_92 ) ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_63 = V_2 -> V_3 . V_63 ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return F_63 ( V_63 , V_91 ) ;
}
T_2 F_64 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned int V_40 ;
T_2 V_91 ;
F_61 ( V_92 ) ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_91 = V_2 -> V_3 . V_48 >> V_2 -> V_3 . V_7 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_91 ;
}
T_1 F_65 ( enum V_94 V_95 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned int V_40 ;
T_1 V_63 , * V_27 = V_96 [ V_95 ] ;
V_5 V_91 ;
F_61 ( V_92 ) ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_63 = F_9 ( V_2 -> V_3 . V_63 , * V_27 ) ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return F_63 ( V_63 , V_91 ) ;
}
T_1 F_66 ( T_1 V_97 , enum V_94 V_95 )
{
T_1 * V_27 = V_96 [ V_95 ] ;
unsigned long V_40 ;
T_1 V_98 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_98 = F_9 ( V_97 , * V_27 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_98 ;
}
T_1 F_67 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned int V_40 ;
T_1 V_63 ;
V_5 V_91 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_63 = V_2 -> V_9 . V_63 ;
V_91 = F_26 ( & V_2 -> V_9 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return F_63 ( V_63 , V_91 ) ;
}
void F_68 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_11 V_99 ;
unsigned int V_40 ;
V_5 V_59 ;
F_61 ( V_92 ) ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_12 -> V_13 = V_2 -> V_8 ;
V_59 = F_26 ( & V_2 -> V_3 ) ;
V_99 = V_2 -> V_17 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
V_12 -> V_13 += V_99 . V_13 ;
V_12 -> V_14 = 0 ;
F_59 ( V_12 , V_59 + V_99 . V_14 ) ;
}
T_6 F_69 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
F_61 ( V_92 ) ;
return V_2 -> V_84 ;
}
T_6 F_70 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
T_6 V_83 ;
unsigned int V_40 ;
if ( F_71 ( V_100 ) )
return V_2 -> V_8 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_83 = V_2 -> V_8 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_83 ;
}
T_6 F_72 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
return V_2 -> V_8 ;
}
void F_73 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_40 ;
T_1 V_103 ;
T_1 V_104 ;
V_5 V_105 ;
V_5 V_106 ;
V_5 V_36 ;
F_7 ( V_92 ) ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_36 = F_12 ( & V_2 -> V_3 ) ;
V_102 -> V_46 = V_2 -> V_46 ;
V_102 -> V_88 = V_2 -> V_88 ;
V_104 = F_9 ( V_2 -> V_3 . V_63 ,
V_35 . V_1 . V_18 ) ;
V_103 = V_2 -> V_9 . V_63 ;
V_106 = F_27 ( & V_2 -> V_3 , V_36 ) ;
V_105 = F_27 ( & V_2 -> V_9 , V_36 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
V_102 -> V_60 = V_36 ;
V_102 -> V_107 = F_63 ( V_104 , V_106 ) ;
V_102 -> V_108 = F_63 ( V_103 , V_105 ) ;
}
static int F_74 ( V_5 V_48 , V_5 div , V_5 * V_63 )
{
V_5 V_16 , V_109 ;
V_16 = F_75 ( * V_63 , div , & V_109 ) ;
if ( ( ( int ) sizeof( V_5 ) * 8 - F_76 ( V_48 ) < F_76 ( V_16 ) ) ||
( ( int ) sizeof( V_5 ) * 8 - F_76 ( V_48 ) < F_76 ( V_109 ) ) )
return - V_110 ;
V_16 *= V_48 ;
V_109 *= V_48 ;
F_22 ( V_109 , div ) ;
* V_63 = V_16 + V_109 ;
return 0 ;
}
static int F_77 ( struct V_101 * V_111 ,
V_5 V_112 ,
V_5 V_113 ,
bool V_114 ,
struct V_115 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
V_5 V_116 , V_117 ;
bool V_118 ;
int V_79 ;
if ( V_113 == 0 || V_112 == 0 )
return 0 ;
V_118 = V_112 > V_113 / 2 ;
V_112 = V_118 ?
V_113 - V_112 :
V_112 ;
V_116 = ( V_5 ) F_32 (
F_52 ( V_12 -> V_119 , V_111 -> V_108 ) ) ;
V_79 = F_74 ( V_112 ,
V_113 , & V_116 ) ;
if ( V_79 )
return V_79 ;
if ( V_114 ) {
V_117 = F_78
( V_116 , V_2 -> V_3 . V_48 , V_2 -> V_9 . V_48 ) ;
} else {
V_117 = ( V_5 ) F_32 (
F_52 ( V_12 -> V_120 , V_111 -> V_107 ) ) ;
V_79 = F_74 ( V_112 ,
V_113 , & V_117 ) ;
if ( V_79 )
return V_79 ;
}
if ( V_118 ) {
V_12 -> V_119 = F_63 ( V_111 -> V_108 , V_116 ) ;
V_12 -> V_120 = F_63 ( V_111 -> V_107 , V_117 ) ;
} else {
V_12 -> V_119 = F_79 ( V_12 -> V_119 , V_116 ) ;
V_12 -> V_120 = F_79 ( V_12 -> V_120 , V_117 ) ;
}
return 0 ;
}
static bool F_80 ( V_5 V_121 , V_5 V_122 , V_5 V_123 )
{
if ( V_122 > V_121 && V_122 < V_123 )
return true ;
if ( V_122 < V_121 && V_121 > V_123 )
return true ;
return false ;
}
int F_81 ( int (* F_82)
( T_1 * V_124 ,
struct V_125 * V_126 ,
void * V_127 ) ,
void * V_127 ,
struct V_101 * V_128 ,
struct V_115 * V_129 )
{
struct V_125 V_130 ;
struct V_1 * V_2 = & V_35 . V_1 ;
V_5 V_60 , V_36 , V_131 ;
unsigned int V_88 = 0 ;
T_1 V_104 , V_103 ;
V_5 V_106 , V_105 ;
T_7 V_46 ;
unsigned long V_40 ;
bool V_132 ;
int V_79 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_79 = F_82 ( & V_129 -> V_133 , & V_130 , V_127 ) ;
if ( V_79 )
return V_79 ;
if ( V_2 -> V_3 . clock != V_130 . V_66 )
return - V_134 ;
V_60 = V_130 . V_60 ;
V_36 = F_12 ( & V_2 -> V_3 ) ;
V_131 = V_2 -> V_3 . V_41 ;
if ( ! F_80 ( V_131 , V_60 , V_36 ) ) {
V_88 = V_2 -> V_88 ;
V_46 = V_2 -> V_46 ;
V_60 = V_131 ;
V_132 = true ;
} else {
V_132 = false ;
}
V_104 = F_9 ( V_2 -> V_3 . V_63 ,
V_35 . V_1 . V_18 ) ;
V_103 = V_2 -> V_9 . V_63 ;
V_106 = F_27 ( & V_2 -> V_3 ,
V_130 . V_60 ) ;
V_105 = F_27 ( & V_2 -> V_9 ,
V_130 . V_60 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
V_129 -> V_120 = F_63 ( V_104 , V_106 ) ;
V_129 -> V_119 = F_63 ( V_103 , V_105 ) ;
if ( V_132 ) {
V_5 V_112 , V_113 ;
bool V_114 ;
if ( ! V_128 ||
! F_80 ( V_128 -> V_60 ,
V_130 . V_60 , V_60 ) ||
V_128 -> V_46 != V_46 )
return - V_135 ;
V_112 = V_60 - V_130 . V_60 ;
V_113 = V_60 - V_128 -> V_60 ;
V_114 =
V_128 -> V_88 != V_88 ;
V_79 = F_77 ( V_128 ,
V_112 ,
V_113 ,
V_114 , V_129 ) ;
if ( V_79 )
return V_79 ;
}
return 0 ;
}
void F_83 ( struct V_136 * V_137 )
{
struct V_11 V_36 ;
F_60 ( & V_36 ) ;
V_137 -> V_13 = V_36 . V_13 ;
V_137 -> V_138 = V_36 . V_14 / 1000 ;
}
int F_84 ( const struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_11 V_139 , V_71 ;
unsigned long V_78 ;
int V_79 = 0 ;
if ( ! F_85 ( V_12 ) )
return - V_135 ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_57 ( V_2 ) ;
V_71 = F_2 ( V_2 ) ;
V_139 . V_13 = V_12 -> V_13 - V_71 . V_13 ;
V_139 . V_14 = V_12 -> V_14 - V_71 . V_14 ;
if ( F_87 ( & V_2 -> V_17 , & V_139 ) > 0 ) {
V_79 = - V_135 ;
goto V_140;
}
F_5 ( V_2 , F_88 ( V_2 -> V_17 , V_139 ) ) ;
F_3 ( V_2 , V_12 ) ;
V_140:
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
F_90 () ;
return V_79 ;
}
int F_91 ( struct V_70 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_78 ;
struct V_11 V_141 , V_16 ;
int V_79 = 0 ;
if ( ! F_92 ( V_12 ) )
return - V_135 ;
V_141 = F_93 ( * V_12 ) ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_57 ( V_2 ) ;
V_16 = F_94 ( F_2 ( V_2 ) , V_141 ) ;
if ( F_87 ( & V_2 -> V_17 , & V_141 ) > 0 ||
! F_85 ( & V_16 ) ) {
V_79 = - V_135 ;
goto error;
}
F_4 ( V_2 , & V_141 ) ;
F_5 ( V_2 , F_88 ( V_2 -> V_17 , V_141 ) ) ;
error:
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
F_90 () ;
return V_79 ;
}
static void F_95 ( struct V_1 * V_2 , T_8 V_20 )
{
V_2 -> V_20 = V_20 ;
V_2 -> V_19 = F_9 ( V_2 -> V_18 , F_10 ( V_20 , 0 ) ) ;
}
static int F_96 ( void * V_142 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_25 * V_143 , * V_144 ;
unsigned long V_78 ;
V_143 = (struct V_25 * ) V_142 ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_57 ( V_2 ) ;
if ( F_97 ( V_143 -> V_145 ) ) {
if ( ! V_143 -> V_146 || V_143 -> V_146 ( V_143 ) == 0 ) {
V_144 = V_2 -> V_3 . clock ;
F_21 ( V_2 , V_143 ) ;
if ( V_144 -> V_147 )
V_144 -> V_147 ( V_144 ) ;
F_98 ( V_144 -> V_145 ) ;
} else {
F_98 ( V_143 -> V_145 ) ;
}
}
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
return 0 ;
}
int F_99 ( struct V_25 * clock )
{
struct V_1 * V_2 = & V_35 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_100 ( F_96 , clock , NULL ) ;
F_101 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_102 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_40 ;
V_5 V_91 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_12 -> V_13 = V_2 -> V_10 ;
V_91 = F_26 ( & V_2 -> V_9 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
V_12 -> V_14 = 0 ;
F_59 ( V_12 , V_91 ) ;
}
int F_103 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_40 ;
int V_79 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_79 = V_2 -> V_3 . clock -> V_78 & V_148 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_79 ;
}
V_5 F_104 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_40 ;
V_5 V_79 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_79 = V_2 -> V_3 . clock -> V_149 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_79 ;
}
void __weak F_105 ( struct V_70 * V_12 )
{
V_12 -> V_13 = 0 ;
V_12 -> V_14 = 0 ;
}
void __weak F_106 ( struct V_11 * V_141 )
{
struct V_70 V_12 ;
F_105 ( & V_12 ) ;
* V_141 = F_93 ( V_12 ) ;
}
void __weak F_107 ( struct V_11 * V_12 )
{
V_12 -> V_13 = 0 ;
V_12 -> V_14 = 0 ;
}
void T_9 F_108 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_25 * clock ;
unsigned long V_78 ;
struct V_11 V_36 , V_150 , V_16 ;
F_106 ( & V_36 ) ;
if ( ! F_85 ( & V_36 ) ) {
F_109 ( L_9
L_10 ) ;
V_36 . V_13 = 0 ;
V_36 . V_14 = 0 ;
} else if ( V_36 . V_13 || V_36 . V_14 )
V_151 = true ;
F_107 ( & V_150 ) ;
if ( ! F_85 ( & V_150 ) ) {
F_109 ( L_11
L_10 ) ;
V_150 . V_13 = 0 ;
V_150 . V_14 = 0 ;
}
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_110 () ;
clock = F_111 () ;
if ( clock -> V_146 )
clock -> V_146 ( clock ) ;
F_21 ( V_2 , clock ) ;
F_3 ( V_2 , & V_36 ) ;
V_2 -> V_10 = 0 ;
if ( V_150 . V_13 == 0 && V_150 . V_14 == 0 )
V_150 = F_2 ( V_2 ) ;
F_6 ( & V_16 , - V_150 . V_13 , - V_150 . V_14 ) ;
F_5 ( V_2 , V_16 ) ;
F_55 ( V_2 , V_89 | V_87 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_11 * V_21 )
{
if ( ! F_85 ( V_21 ) ) {
F_15 ( V_152
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_21 ) ;
F_5 ( V_2 , F_88 ( V_2 -> V_17 , * V_21 ) ) ;
F_11 ( V_2 , F_8 ( * V_21 ) ) ;
F_113 ( V_21 ) ;
}
bool F_114 ( void )
{
return V_153 ;
}
bool F_115 ( void )
{
return V_151 ;
}
void F_116 ( struct V_11 * V_21 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_78 ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_57 ( V_2 ) ;
F_112 ( V_2 , V_21 ) ;
F_55 ( V_2 , V_86 | V_89 | V_87 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
F_90 () ;
}
void F_117 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_25 * clock = V_2 -> V_3 . clock ;
unsigned long V_78 ;
struct V_11 V_154 , V_139 ;
V_5 V_42 ;
V_153 = false ;
F_106 ( & V_154 ) ;
F_118 () ;
F_119 () ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
V_42 = F_12 ( & V_2 -> V_3 ) ;
if ( ( clock -> V_78 & V_155 ) &&
V_42 > V_2 -> V_3 . V_41 ) {
V_5 V_59 , V_156 ;
V_156 = F_19 ( V_42 , V_2 -> V_3 . V_41 ,
V_2 -> V_3 . V_38 ) ;
V_59 = F_120 ( V_156 , clock -> V_48 , clock -> V_7 ) ;
V_139 = F_121 ( V_59 ) ;
V_153 = true ;
} else if ( F_87 ( & V_154 , & V_157 ) > 0 ) {
V_139 = F_88 ( V_154 , V_157 ) ;
V_153 = true ;
}
if ( V_153 )
F_112 ( V_2 , & V_139 ) ;
V_2 -> V_3 . V_41 = V_42 ;
V_2 -> V_9 . V_41 = V_42 ;
V_2 -> V_54 = 0 ;
V_92 = 0 ;
F_55 ( V_2 , V_89 | V_87 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
F_122 () ;
F_123 () ;
F_124 () ;
}
int F_125 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_78 ;
struct V_11 V_21 , V_158 ;
static struct V_11 V_159 ;
F_106 ( & V_157 ) ;
if ( V_157 . V_13 || V_157 . V_14 )
V_151 = true ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_57 ( V_2 ) ;
V_92 = 1 ;
if ( V_151 ) {
V_21 = F_88 ( F_2 ( V_2 ) , V_157 ) ;
V_158 = F_88 ( V_21 , V_159 ) ;
if ( abs ( V_158 . V_13 ) >= 2 ) {
V_159 = V_21 ;
} else {
V_157 =
F_94 ( V_157 , V_158 ) ;
}
}
F_55 ( V_2 , V_89 ) ;
F_37 ( V_2 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
F_126 () ;
F_127 () ;
F_128 () ;
return 0 ;
}
static int T_9 F_129 ( void )
{
F_130 ( & V_160 ) ;
return 0 ;
}
static T_3 void F_131 ( struct V_1 * V_2 ,
T_5 V_27 ,
bool V_161 ,
int V_162 )
{
T_5 V_43 = V_2 -> V_49 ;
T_8 V_163 = 1 ;
if ( V_161 ) {
V_163 = - V_163 ;
V_43 = - V_43 ;
V_27 = - V_27 ;
}
V_163 <<= V_162 ;
V_43 <<= V_162 ;
V_27 <<= V_162 ;
if ( ( V_163 > 0 ) && ( V_2 -> V_3 . V_48 + V_163 < V_163 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_48 += V_163 ;
V_2 -> V_50 += V_43 ;
V_2 -> V_3 . V_4 -= V_27 ;
V_2 -> V_54 -= ( V_43 - V_27 ) << V_2 -> V_55 ;
}
static T_3 void F_132 ( struct V_1 * V_2 ,
T_5 V_27 )
{
T_5 V_43 = V_2 -> V_49 ;
T_5 V_164 = V_2 -> V_50 ;
T_2 V_63 = V_2 -> V_3 . clock -> V_48 ;
T_2 V_39 = V_2 -> V_3 . clock -> V_165 ;
T_2 V_166 = V_2 -> V_3 . V_48 ;
T_5 V_167 ;
bool V_161 ;
T_2 V_162 ;
if ( V_2 -> V_58 )
V_164 -= V_2 -> V_49 ;
V_2 -> V_57 = F_133 () ;
V_167 = F_133 () >> V_2 -> V_55 ;
V_167 -= ( V_164 + V_2 -> V_51 ) ;
if ( F_134 ( ( V_167 >= 0 ) && ( V_167 <= V_43 ) ) )
return;
V_161 = ( V_167 < 0 ) ;
if ( V_161 && ( V_166 - 1 ) <= ( V_63 - V_39 ) )
return;
if ( ! V_161 && ( V_166 + 1 ) >= ( V_63 + V_39 ) )
return;
V_162 = 0 ;
V_167 = abs ( V_167 ) ;
while ( V_167 > V_43 ) {
T_2 V_168 = 1 << ( V_162 + 1 ) ;
if ( V_161 && ( V_166 - V_168 ) <= ( V_63 - V_39 ) )
break;
if ( ! V_161 && ( V_166 + V_168 ) >= ( V_63 + V_39 ) )
break;
V_162 ++ ;
V_167 >>= 1 ;
}
F_131 ( V_2 , V_27 , V_161 , V_162 ) ;
}
static void F_135 ( struct V_1 * V_2 , T_5 V_27 )
{
F_132 ( V_2 , V_27 ) ;
if ( ! V_2 -> V_58 && ( V_2 -> V_54 > 0 ) ) {
V_2 -> V_58 = 1 ;
F_131 ( V_2 , V_27 , 0 , 0 ) ;
} else if ( V_2 -> V_58 && ( V_2 -> V_54 <= 0 ) ) {
F_131 ( V_2 , V_27 , 1 , 0 ) ;
V_2 -> V_58 = 0 ;
}
if ( F_20 ( V_2 -> V_3 . clock -> V_165 &&
( abs ( V_2 -> V_3 . V_48 - V_2 -> V_3 . clock -> V_48 )
> V_2 -> V_3 . clock -> V_165 ) ) ) {
F_136 ( V_152
L_14 ,
V_2 -> V_3 . clock -> V_29 , ( long ) V_2 -> V_3 . V_48 ,
( long ) V_2 -> V_3 . clock -> V_48 + V_2 -> V_3 . clock -> V_165 ) ;
}
if ( F_20 ( ( T_5 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_5 V_169 = - ( T_5 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_54 += V_169 << V_2 -> V_55 ;
}
}
static inline unsigned int F_137 ( struct V_1 * V_2 )
{
V_5 V_170 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_171 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_170 ) {
int V_172 ;
V_2 -> V_3 . V_4 -= V_170 ;
V_2 -> V_8 ++ ;
V_172 = F_138 ( V_2 -> V_8 ) ;
if ( F_20 ( V_172 ) ) {
struct V_11 V_12 ;
V_2 -> V_8 += V_172 ;
V_12 . V_13 = V_172 ;
V_12 . V_14 = 0 ;
F_5 ( V_2 ,
F_88 ( V_2 -> V_17 , V_12 ) ) ;
F_95 ( V_2 , V_2 -> V_20 - V_172 ) ;
V_171 = V_87 ;
}
}
return V_171 ;
}
static V_5 F_139 ( struct V_1 * V_2 , V_5 V_27 ,
T_2 V_7 , unsigned int * V_171 )
{
V_5 V_43 = V_2 -> V_49 << V_7 ;
V_5 V_173 ;
if ( V_27 < V_43 )
return V_27 ;
V_27 -= V_43 ;
V_2 -> V_3 . V_41 += V_43 ;
V_2 -> V_9 . V_41 += V_43 ;
V_2 -> V_3 . V_4 += V_2 -> V_50 << V_7 ;
* V_171 |= F_137 ( V_2 ) ;
V_2 -> V_9 . V_4 += V_2 -> V_52 << V_7 ;
V_173 = ( V_5 ) V_6 << V_2 -> V_9 . V_7 ;
while ( V_2 -> V_9 . V_4 >= V_173 ) {
V_2 -> V_9 . V_4 -= V_173 ;
V_2 -> V_10 ++ ;
}
V_2 -> V_54 += V_2 -> V_57 << V_7 ;
V_2 -> V_54 -= ( V_2 -> V_50 + V_2 -> V_51 ) <<
( V_2 -> V_55 + V_7 ) ;
return V_27 ;
}
void F_140 ( void )
{
struct V_1 * V_174 = & V_35 . V_1 ;
struct V_1 * V_2 = & V_90 ;
V_5 V_27 ;
int V_7 = 0 , V_175 ;
unsigned int V_171 = 0 ;
unsigned long V_78 ;
F_45 ( & V_80 , V_78 ) ;
if ( F_20 ( V_92 ) )
goto V_140;
#ifdef F_141
V_27 = V_174 -> V_49 ;
#else
V_27 = F_19 ( F_12 ( & V_2 -> V_3 ) ,
V_2 -> V_3 . V_41 , V_2 -> V_3 . V_38 ) ;
#endif
if ( V_27 < V_174 -> V_49 )
goto V_140;
F_14 ( V_174 , V_27 ) ;
V_7 = F_142 ( V_27 ) - F_142 ( V_2 -> V_49 ) ;
V_7 = V_39 ( 0 , V_7 ) ;
V_175 = ( 64 - ( F_142 ( F_133 () ) + 1 ) ) - 1 ;
V_7 = F_143 ( V_7 , V_175 ) ;
while ( V_27 >= V_2 -> V_49 ) {
V_27 = F_139 ( V_2 , V_27 , V_7 ,
& V_171 ) ;
if ( V_27 < V_2 -> V_49 << V_7 )
V_7 -- ;
}
F_135 ( V_2 , V_27 ) ;
F_41 ( V_2 ) ;
V_171 |= F_137 ( V_2 ) ;
F_86 ( & V_35 . V_40 ) ;
F_55 ( V_2 , V_171 ) ;
memcpy ( V_174 , V_2 , sizeof( * V_2 ) ) ;
F_89 ( & V_35 . V_40 ) ;
V_140:
F_47 ( & V_80 , V_78 ) ;
if ( V_171 )
F_144 () ;
}
void F_145 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
T_1 V_176 = F_52 ( V_2 -> V_18 , V_2 -> V_22 ) ;
* V_12 = F_146 ( V_176 ) ;
}
unsigned long F_147 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
return V_2 -> V_8 ;
}
struct V_70 F_148 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
return F_39 ( F_2 ( V_2 ) ) ;
}
struct V_11 F_149 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_11 V_36 ;
unsigned long V_40 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_36 = F_2 ( V_2 ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_36 ;
}
struct V_11 F_150 ( void )
{
struct V_1 * V_2 = & V_35 . V_1 ;
struct V_11 V_36 , V_177 ;
unsigned long V_40 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_36 = F_2 ( V_2 ) ;
V_177 = V_2 -> V_17 ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
F_6 ( & V_36 , V_36 . V_13 + V_177 . V_13 ,
V_36 . V_14 + V_177 . V_14 ) ;
return V_36 ;
}
void F_151 ( unsigned long V_178 )
{
V_179 += V_178 ;
F_152 ( V_178 ) ;
}
T_1 F_153 ( unsigned int * V_180 , T_1 * V_18 ,
T_1 * V_22 , T_1 * V_19 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned int V_40 ;
T_1 V_63 ;
V_5 V_91 ;
do {
V_40 = F_17 ( & V_35 . V_40 ) ;
V_63 = V_2 -> V_3 . V_63 ;
V_91 = F_26 ( & V_2 -> V_3 ) ;
V_63 = F_63 ( V_63 , V_91 ) ;
if ( * V_180 != V_2 -> V_88 ) {
* V_180 = V_2 -> V_88 ;
* V_18 = V_2 -> V_18 ;
* V_22 = V_2 -> V_22 ;
* V_19 = V_2 -> V_19 ;
}
if ( F_20 ( V_63 >= V_2 -> V_81 ) )
* V_18 = F_52 ( V_2 -> V_18 , F_10 ( 1 , 0 ) ) ;
} while ( F_18 ( & V_35 . V_40 , V_40 ) );
return V_63 ;
}
int F_154 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = & V_35 . V_1 ;
unsigned long V_78 ;
struct V_11 V_12 ;
T_8 V_183 , V_184 ;
int V_79 ;
V_79 = F_155 ( V_182 ) ;
if ( V_79 )
return V_79 ;
if ( V_182 -> V_185 & V_186 ) {
struct V_70 V_21 ;
V_21 . V_13 = V_182 -> time . V_13 ;
V_21 . V_14 = V_182 -> time . V_138 ;
if ( ! ( V_182 -> V_185 & V_187 ) )
V_21 . V_14 *= 1000 ;
V_79 = F_91 ( & V_21 ) ;
if ( V_79 )
return V_79 ;
}
F_60 ( & V_12 ) ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
V_183 = V_184 = V_2 -> V_20 ;
V_79 = F_156 ( V_182 , & V_12 , & V_184 ) ;
if ( V_184 != V_183 ) {
F_95 ( V_2 , V_184 ) ;
F_55 ( V_2 , V_89 | V_87 ) ;
}
F_50 ( V_2 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
if ( V_184 != V_183 )
F_90 () ;
F_157 () ;
return V_79 ;
}
void F_158 ( const struct V_11 * V_188 , const struct V_11 * V_189 )
{
unsigned long V_78 ;
F_45 ( & V_80 , V_78 ) ;
F_86 ( & V_35 . V_40 ) ;
F_159 ( V_188 , V_189 ) ;
F_89 ( & V_35 . V_40 ) ;
F_47 ( & V_80 , V_78 ) ;
}
void F_160 ( unsigned long V_178 )
{
F_161 ( & V_190 ) ;
F_151 ( V_178 ) ;
F_162 ( & V_190 ) ;
F_140 () ;
}
