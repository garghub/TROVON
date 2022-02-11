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
V_44 = V_2 -> V_3 . clock ;
V_2 -> V_3 . clock = clock ;
V_2 -> V_3 . V_38 = clock -> V_38 ;
V_2 -> V_3 . V_35 = clock -> V_35 ;
V_2 -> V_3 . V_39 = V_2 -> V_3 . V_38 ( clock ) ;
V_2 -> V_45 . clock = clock ;
V_2 -> V_45 . V_38 = clock -> V_38 ;
V_2 -> V_45 . V_35 = clock -> V_35 ;
V_2 -> V_45 . V_39 = V_2 -> V_3 . V_39 ;
V_14 = V_46 ;
V_14 <<= clock -> V_7 ;
V_43 = V_14 ;
V_14 += clock -> V_47 / 2 ;
F_20 ( V_14 , clock -> V_47 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
V_42 = ( T_2 ) V_14 ;
V_2 -> V_48 = V_42 ;
V_2 -> V_49 = ( V_5 ) V_42 * clock -> V_47 ;
V_2 -> V_50 = V_43 - V_2 -> V_49 ;
V_2 -> V_51 =
( ( V_5 ) V_42 * clock -> V_47 ) >> clock -> V_7 ;
if ( V_44 ) {
int V_52 = clock -> V_7 - V_44 -> V_7 ;
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
V_2 -> V_56 = V_43 << V_2 -> V_54 ;
V_2 -> V_3 . V_47 = clock -> V_47 ;
V_2 -> V_45 . V_47 = clock -> V_47 ;
V_2 -> V_57 = 0 ;
}
static T_3 F_21 ( void ) { return 0 ; }
static inline T_3 F_22 ( void ) { return 0 ; }
static inline T_4 F_23 ( struct V_30 * V_31 )
{
T_2 V_20 ;
T_4 V_58 ;
V_20 = F_14 ( V_31 ) ;
V_58 = V_20 * V_31 -> V_47 + V_31 -> V_4 ;
V_58 >>= V_31 -> V_7 ;
return V_58 + F_22 () ;
}
static void F_24 ( struct V_30 * V_31 , struct V_59 * V_60 )
{
struct V_30 * V_61 = V_60 -> V_61 ;
F_25 ( & V_60 -> V_37 ) ;
memcpy ( V_61 , V_31 , sizeof( * V_61 ) ) ;
F_25 ( & V_60 -> V_37 ) ;
memcpy ( V_61 + 1 , V_61 , sizeof( * V_61 ) ) ;
}
static T_5 V_5 F_26 ( struct V_59 * V_60 )
{
struct V_30 * V_31 ;
unsigned int V_37 ;
V_5 V_33 ;
do {
V_37 = F_27 ( & V_60 -> V_37 ) ;
V_31 = V_60 -> V_61 + ( V_37 & 0x01 ) ;
V_33 = F_28 ( V_31 -> V_61 ) + F_23 ( V_31 ) ;
} while ( F_16 ( & V_60 -> V_37 , V_37 ) );
return V_33 ;
}
V_5 F_29 ( void )
{
return F_26 ( & V_62 ) ;
}
V_5 F_30 ( void )
{
return F_26 ( & V_63 ) ;
}
static T_2 F_31 ( struct V_41 * V_64 )
{
return V_65 ;
}
static void F_32 ( struct V_1 * V_2 )
{
static struct V_30 V_66 ;
struct V_30 * V_31 = & V_2 -> V_3 ;
memcpy ( & V_66 , V_31 , sizeof( V_66 ) ) ;
V_65 = V_31 -> V_38 ( V_31 -> clock ) ;
V_66 . V_38 = F_31 ;
F_24 ( & V_66 , & V_62 ) ;
V_31 = & V_2 -> V_45 ;
memcpy ( & V_66 , V_31 , sizeof( V_66 ) ) ;
V_66 . V_38 = F_31 ;
F_24 ( & V_66 , & V_63 ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
struct V_67 V_68 , V_69 ;
V_68 = F_34 ( F_2 ( V_2 ) ) ;
V_69 = F_34 ( V_2 -> V_15 ) ;
F_35 ( & V_68 , & V_69 , V_2 -> V_3 . clock , V_2 -> V_3 . V_47 ,
V_2 -> V_3 . V_39 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
T_4 V_70 ;
V_70 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
V_2 -> V_3 . V_4 -= V_70 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_53 += V_70 << V_2 -> V_54 ;
V_2 -> V_53 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_54 ;
}
static void F_37 ( struct V_1 * V_2 , bool V_71 )
{
F_38 ( & V_72 , V_71 , V_2 ) ;
}
int F_39 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
int V_76 ;
F_40 ( & V_77 , V_75 ) ;
V_76 = F_41 ( & V_72 , V_74 ) ;
F_37 ( V_2 , true ) ;
F_42 ( & V_77 , V_75 ) ;
return V_76 ;
}
int F_43 ( struct V_73 * V_74 )
{
unsigned long V_75 ;
int V_76 ;
F_40 ( & V_77 , V_75 ) ;
V_76 = F_44 ( & V_72 , V_74 ) ;
F_42 ( & V_77 , V_75 ) ;
return V_76 ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_78 = F_46 () ;
if ( V_2 -> V_78 . V_17 != V_79 )
V_2 -> V_78 = F_47 ( V_2 -> V_78 , V_2 -> V_16 ) ;
}
static inline void F_48 ( struct V_1 * V_2 )
{
V_5 V_80 ;
T_3 V_58 ;
V_80 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_58 = ( T_3 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_61 = F_49 ( V_80 * V_6 + V_58 ) ;
V_2 -> V_45 . V_61 = F_8 ( V_2 -> V_81 ) ;
V_58 += ( T_3 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_58 >= V_6 )
V_80 ++ ;
V_2 -> V_82 = V_80 ;
}
static void F_50 ( struct V_1 * V_2 , unsigned int V_83 )
{
if ( V_83 & V_84 ) {
V_2 -> V_53 = 0 ;
F_51 () ;
}
F_45 ( V_2 ) ;
F_48 ( V_2 ) ;
F_33 ( V_2 ) ;
F_37 ( V_2 , V_83 & V_85 ) ;
F_24 ( & V_2 -> V_3 , & V_62 ) ;
F_24 ( & V_2 -> V_45 , & V_63 ) ;
if ( V_83 & V_85 )
V_2 -> V_86 ++ ;
if ( V_83 & V_87 )
memcpy ( & V_88 , & V_32 . V_1 ,
sizeof( V_32 . V_1 ) ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_41 * clock = V_2 -> V_3 . clock ;
T_2 V_40 , V_20 ;
T_4 V_58 ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
V_20 = F_17 ( V_40 , V_2 -> V_3 . V_39 , V_2 -> V_3 . V_35 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_3 . V_4 += V_20 * V_2 -> V_3 . V_47 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_22 () << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
V_58 = F_53 ( V_20 , V_2 -> V_45 . V_47 , V_2 -> V_45 . V_7 ) ;
F_54 ( & V_2 -> V_81 , V_58 ) ;
}
int F_55 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
T_4 V_89 = 0 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_89 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_10 -> V_12 = 0 ;
F_54 ( V_10 , V_89 ) ;
if ( F_18 ( V_90 ) )
return - V_91 ;
return 0 ;
}
void F_56 ( struct V_9 * V_10 )
{
F_57 ( F_55 ( V_10 ) ) ;
}
T_1 F_58 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_61 ;
T_4 V_89 ;
F_57 ( V_90 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_61 = V_2 -> V_3 . V_61 ;
V_89 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_59 ( V_61 , V_89 ) ;
}
T_3 F_60 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_3 V_89 ;
F_57 ( V_90 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_89 = V_2 -> V_3 . V_47 >> V_2 -> V_3 . V_7 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_89 ;
}
T_1 F_61 ( enum V_92 V_93 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_61 , * V_22 = V_94 [ V_93 ] ;
T_4 V_89 ;
F_57 ( V_90 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_61 = F_9 ( V_2 -> V_3 . V_61 , * V_22 ) ;
V_89 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_59 ( V_61 , V_89 ) ;
}
T_1 F_62 ( T_1 V_95 , enum V_92 V_93 )
{
T_1 * V_22 = V_94 [ V_93 ] ;
unsigned long V_37 ;
T_1 V_96 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_96 = F_9 ( V_95 , * V_22 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_96 ;
}
T_1 F_63 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_61 ;
T_4 V_89 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_61 = V_2 -> V_45 . V_61 ;
V_89 = F_23 ( & V_2 -> V_45 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_59 ( V_61 , V_89 ) ;
}
void F_64 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_97 ;
T_4 V_58 ;
unsigned int V_37 ;
F_57 ( V_90 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_58 = F_23 ( & V_2 -> V_3 ) ;
V_97 = V_2 -> V_15 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
V_10 -> V_11 += V_97 . V_11 ;
V_10 -> V_12 = 0 ;
F_54 ( V_10 , V_58 + V_97 . V_12 ) ;
}
T_6 F_65 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
F_57 ( V_90 ) ;
return V_2 -> V_82 ;
}
T_6 F_66 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
T_6 V_80 ;
unsigned int V_37 ;
if ( F_67 ( V_98 ) )
return V_2 -> V_8 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_80 = V_2 -> V_8 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_80 ;
}
void F_68 ( struct V_67 * V_99 , struct V_67 * V_100 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
T_4 V_101 , V_102 ;
F_7 ( V_90 ) ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
* V_99 = F_34 ( V_2 -> V_81 ) ;
V_100 -> V_11 = V_2 -> V_8 ;
V_100 -> V_12 = 0 ;
V_101 = F_23 ( & V_2 -> V_45 ) ;
V_102 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
F_69 ( V_99 , V_101 ) ;
F_69 ( V_100 , V_102 ) ;
}
void F_70 ( struct V_103 * V_104 )
{
struct V_9 V_33 ;
F_56 ( & V_33 ) ;
V_104 -> V_11 = V_33 . V_11 ;
V_104 -> V_105 = V_33 . V_12 / 1000 ;
}
int F_71 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_106 , V_68 ;
unsigned long V_75 ;
if ( ! F_72 ( V_10 ) )
return - V_107 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
V_68 = F_2 ( V_2 ) ;
V_106 . V_11 = V_10 -> V_11 - V_68 . V_11 ;
V_106 . V_12 = V_10 -> V_12 - V_68 . V_12 ;
F_5 ( V_2 , F_74 ( V_2 -> V_15 , V_106 ) ) ;
F_3 ( V_2 , V_10 ) ;
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_76 () ;
return 0 ;
}
int F_77 ( struct V_67 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
struct V_9 V_108 , V_14 ;
int V_76 = 0 ;
if ( ( unsigned long ) V_10 -> V_12 >= V_6 )
return - V_107 ;
V_108 = F_78 ( * V_10 ) ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
V_14 = F_79 ( F_2 ( V_2 ) , V_108 ) ;
if ( ! F_72 ( & V_14 ) ) {
V_76 = - V_107 ;
goto error;
}
F_4 ( V_2 , & V_108 ) ;
F_5 ( V_2 , F_74 ( V_2 -> V_15 , V_108 ) ) ;
error:
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_76 () ;
return V_76 ;
}
T_7 F_80 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_7 V_76 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_76 = V_2 -> V_19 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_76 ;
}
static void F_81 ( struct V_1 * V_2 , T_7 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_82 ( T_7 V_19 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_81 ( V_2 , V_19 ) ;
F_50 ( V_2 , V_87 | V_85 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_76 () ;
}
static int F_83 ( void * V_109 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * V_110 , * V_111 ;
unsigned long V_75 ;
V_110 = (struct V_41 * ) V_109 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
if ( F_84 ( V_110 -> V_112 ) ) {
if ( ! V_110 -> V_113 || V_110 -> V_113 ( V_110 ) == 0 ) {
V_111 = V_2 -> V_3 . clock ;
F_19 ( V_2 , V_110 ) ;
if ( V_111 -> V_114 )
V_111 -> V_114 ( V_111 ) ;
F_85 ( V_111 -> V_112 ) ;
} else {
F_85 ( V_110 -> V_112 ) ;
}
}
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
return 0 ;
}
int F_86 ( struct V_41 * clock )
{
struct V_1 * V_2 = & V_32 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_87 ( F_83 , clock , NULL ) ;
F_88 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_89 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_108 ;
unsigned long V_37 ;
T_4 V_89 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_89 = F_23 ( & V_2 -> V_45 ) ;
V_108 = V_2 -> V_81 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
F_54 ( & V_108 , V_89 ) ;
* V_10 = V_108 ;
}
int F_90 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
int V_76 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_76 = V_2 -> V_3 . clock -> V_75 & V_115 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_76 ;
}
V_5 F_91 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
V_5 V_76 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_76 = V_2 -> V_3 . clock -> V_116 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_76 ;
}
void __weak F_92 ( struct V_67 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_93 ( struct V_9 * V_108 )
{
struct V_67 V_10 ;
F_92 ( & V_10 ) ;
* V_108 = F_78 ( V_10 ) ;
}
void __weak F_94 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_8 F_95 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * clock ;
unsigned long V_75 ;
struct V_9 V_33 , V_117 , V_14 ;
F_93 ( & V_33 ) ;
if ( ! F_72 ( & V_33 ) ) {
F_96 ( L_9
L_10 ) ;
V_33 . V_11 = 0 ;
V_33 . V_12 = 0 ;
} else if ( V_33 . V_11 || V_33 . V_12 )
V_118 = true ;
F_94 ( & V_117 ) ;
if ( ! F_72 ( & V_117 ) ) {
F_96 ( L_11
L_10 ) ;
V_117 . V_11 = 0 ;
V_117 . V_12 = 0 ;
}
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_97 () ;
clock = F_98 () ;
if ( clock -> V_113 )
clock -> V_113 ( clock ) ;
F_19 ( V_2 , clock ) ;
F_3 ( V_2 , & V_33 ) ;
V_2 -> V_81 . V_11 = 0 ;
V_2 -> V_81 . V_12 = 0 ;
if ( V_117 . V_11 == 0 && V_117 . V_12 == 0 )
V_117 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_117 . V_11 , - V_117 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_50 ( V_2 , V_87 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_72 ( V_20 ) ) {
F_13 ( V_119
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_74 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_100 ( V_20 ) ;
}
bool F_101 ( void )
{
return V_120 ;
}
bool F_102 ( void )
{
return V_118 ;
}
void F_103 ( struct V_9 * V_20 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
F_99 ( V_2 , V_20 ) ;
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_76 () ;
}
void F_104 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * clock = V_2 -> V_3 . clock ;
unsigned long V_75 ;
struct V_9 V_121 , V_106 ;
T_2 V_40 , V_122 ;
V_120 = false ;
F_93 ( & V_121 ) ;
F_105 () ;
F_106 () ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
if ( ( clock -> V_75 & V_123 ) &&
V_40 > V_2 -> V_3 . V_39 ) {
V_5 V_124 , V_36 = V_125 ;
T_3 V_47 = clock -> V_47 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_58 = 0 ;
V_122 = F_17 ( V_40 , V_2 -> V_3 . V_39 ,
V_2 -> V_3 . V_35 ) ;
F_20 ( V_36 , V_47 ) ;
if ( V_122 > V_36 ) {
V_124 = F_107 ( V_122 , V_36 ) ;
V_58 = ( ( ( V_5 ) V_36 * V_47 ) >> V_7 ) * V_124 ;
V_122 -= V_124 * V_36 ;
}
V_58 += ( ( V_5 ) V_122 * V_47 ) >> V_7 ;
V_106 = F_108 ( V_58 ) ;
V_120 = true ;
} else if ( F_109 ( & V_121 , & V_126 ) > 0 ) {
V_106 = F_74 ( V_121 , V_126 ) ;
V_120 = true ;
}
if ( V_120 )
F_99 ( V_2 , & V_106 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_53 = 0 ;
V_90 = 0 ;
F_50 ( V_2 , V_87 | V_85 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_110 () ;
F_111 () ;
F_112 () ;
}
int F_113 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
struct V_9 V_20 , V_127 ;
static struct V_9 V_128 ;
F_93 ( & V_126 ) ;
if ( V_126 . V_11 || V_126 . V_12 )
V_118 = true ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
V_90 = 1 ;
if ( V_118 ) {
V_20 = F_74 ( F_2 ( V_2 ) , V_126 ) ;
V_127 = F_74 ( V_20 , V_128 ) ;
if ( abs ( V_127 . V_11 ) >= 2 ) {
V_128 = V_20 ;
} else {
V_126 =
F_79 ( V_126 , V_127 ) ;
}
}
F_50 ( V_2 , V_87 ) ;
F_32 ( V_2 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_114 () ;
F_115 () ;
F_116 () ;
return 0 ;
}
static int T_8 F_117 ( void )
{
F_118 ( & V_129 ) ;
return 0 ;
}
static T_5 void F_119 ( struct V_1 * V_2 ,
T_4 V_22 ,
bool V_130 ,
int V_131 )
{
T_4 V_42 = V_2 -> V_48 ;
T_7 V_132 = 1 ;
if ( V_130 ) {
V_132 = - V_132 ;
V_42 = - V_42 ;
V_22 = - V_22 ;
}
V_132 <<= V_131 ;
V_42 <<= V_131 ;
V_22 <<= V_131 ;
if ( ( V_132 > 0 ) && ( V_2 -> V_3 . V_47 + V_132 < V_132 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_47 += V_132 ;
V_2 -> V_49 += V_42 ;
V_2 -> V_3 . V_4 -= V_22 ;
V_2 -> V_53 -= ( V_42 - V_22 ) << V_2 -> V_54 ;
}
static T_5 void F_120 ( struct V_1 * V_2 ,
T_4 V_22 )
{
T_4 V_42 = V_2 -> V_48 ;
T_4 V_133 = V_2 -> V_49 ;
T_4 V_134 ;
bool V_130 ;
T_3 V_135 ;
if ( V_2 -> V_57 )
V_133 -= V_2 -> V_48 ;
V_2 -> V_56 = F_121 () ;
V_134 = F_121 () >> V_2 -> V_54 ;
V_134 -= ( V_133 + V_2 -> V_50 ) ;
if ( F_122 ( ( V_134 >= 0 ) && ( V_134 <= V_42 ) ) )
return;
V_130 = ( V_134 < 0 ) ;
V_134 = abs ( V_134 ) ;
for ( V_135 = 0 ; V_134 > V_42 ; V_135 ++ )
V_134 >>= 1 ;
F_119 ( V_2 , V_22 , V_130 , V_135 ) ;
}
static void F_123 ( struct V_1 * V_2 , T_4 V_22 )
{
F_120 ( V_2 , V_22 ) ;
if ( ! V_2 -> V_57 && ( V_2 -> V_53 > 0 ) ) {
V_2 -> V_57 = 1 ;
F_119 ( V_2 , V_22 , 0 , 0 ) ;
} else if ( V_2 -> V_57 && ( V_2 -> V_53 <= 0 ) ) {
F_119 ( V_2 , V_22 , 1 , 0 ) ;
V_2 -> V_57 = 0 ;
}
if ( F_18 ( V_2 -> V_3 . clock -> V_136 &&
( abs ( V_2 -> V_3 . V_47 - V_2 -> V_3 . clock -> V_47 )
> V_2 -> V_3 . clock -> V_136 ) ) ) {
F_124 ( V_119
L_14 ,
V_2 -> V_3 . clock -> V_24 , ( long ) V_2 -> V_3 . V_47 ,
( long ) V_2 -> V_3 . clock -> V_47 + V_2 -> V_3 . clock -> V_136 ) ;
}
if ( F_18 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_137 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_53 += V_137 << V_2 -> V_54 ;
}
}
static inline unsigned int F_125 ( struct V_1 * V_2 )
{
V_5 V_138 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_139 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_138 ) {
int V_140 ;
V_2 -> V_3 . V_4 -= V_138 ;
V_2 -> V_8 ++ ;
V_140 = F_126 ( V_2 -> V_8 ) ;
if ( F_18 ( V_140 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_140 ;
V_10 . V_11 = V_140 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_74 ( V_2 -> V_15 , V_10 ) ) ;
F_81 ( V_2 , V_2 -> V_19 - V_140 ) ;
V_139 = V_85 ;
}
}
return V_139 ;
}
static T_2 F_127 ( struct V_1 * V_2 , T_2 V_22 ,
T_3 V_7 ,
unsigned int * V_139 )
{
T_2 V_42 = V_2 -> V_48 << V_7 ;
V_5 V_141 ;
if ( V_22 < V_42 )
return V_22 ;
V_22 -= V_42 ;
V_2 -> V_3 . V_39 += V_42 ;
V_2 -> V_45 . V_39 += V_42 ;
V_2 -> V_3 . V_4 += V_2 -> V_49 << V_7 ;
* V_139 |= F_125 ( V_2 ) ;
V_141 = ( V_5 ) V_2 -> V_51 << V_7 ;
V_141 += V_2 -> V_81 . V_12 ;
if ( V_141 >= V_6 ) {
V_5 V_142 = V_141 ;
V_141 = F_20 ( V_142 , V_6 ) ;
V_2 -> V_81 . V_11 += V_142 ;
}
V_2 -> V_81 . V_12 = V_141 ;
V_2 -> V_53 += V_2 -> V_56 << V_7 ;
V_2 -> V_53 -= ( V_2 -> V_49 + V_2 -> V_50 ) <<
( V_2 -> V_54 + V_7 ) ;
return V_22 ;
}
void F_128 ( void )
{
struct V_1 * V_143 = & V_32 . V_1 ;
struct V_1 * V_2 = & V_88 ;
T_2 V_22 ;
int V_7 = 0 , V_144 ;
unsigned int V_139 = 0 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
if ( F_18 ( V_90 ) )
goto V_145;
#ifdef F_129
V_22 = V_143 -> V_48 ;
#else
V_22 = F_17 ( V_2 -> V_3 . V_38 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_39 , V_2 -> V_3 . V_35 ) ;
#endif
if ( V_22 < V_143 -> V_48 )
goto V_145;
F_12 ( V_143 , V_22 ) ;
V_7 = F_130 ( V_22 ) - F_130 ( V_2 -> V_48 ) ;
V_7 = V_36 ( 0 , V_7 ) ;
V_144 = ( 64 - ( F_130 ( F_121 () ) + 1 ) ) - 1 ;
V_7 = F_131 ( V_7 , V_144 ) ;
while ( V_22 >= V_2 -> V_48 ) {
V_22 = F_127 ( V_2 , V_22 , V_7 ,
& V_139 ) ;
if ( V_22 < V_2 -> V_48 << V_7 )
V_7 -- ;
}
F_123 ( V_2 , V_22 ) ;
F_36 ( V_2 ) ;
V_139 |= F_125 ( V_2 ) ;
F_73 ( & V_32 . V_37 ) ;
F_50 ( V_2 , V_139 ) ;
memcpy ( V_143 , V_2 , sizeof( * V_2 ) ) ;
F_75 ( & V_32 . V_37 ) ;
V_145:
F_42 ( & V_77 , V_75 ) ;
if ( V_139 )
F_132 () ;
}
void F_133 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
T_1 V_146 = F_47 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_134 ( V_146 ) ;
}
unsigned long F_135 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return V_2 -> V_8 ;
}
struct V_67 F_136 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return F_34 ( F_2 ( V_2 ) ) ;
}
struct V_67 F_137 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_33 ;
unsigned long V_37 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_33 = F_2 ( V_2 ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return F_34 ( V_33 ) ;
}
struct V_9 F_138 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_33 , V_147 ;
unsigned long V_37 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_33 = F_2 ( V_2 ) ;
V_147 = V_2 -> V_15 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
F_6 ( & V_33 , V_33 . V_11 + V_147 . V_11 ,
V_33 . V_12 + V_147 . V_12 ) ;
return V_33 ;
}
void F_139 ( unsigned long V_148 )
{
V_149 += V_148 ;
F_140 ( V_148 ) ;
}
T_1 F_141 ( unsigned int * V_150 , T_1 * V_16 ,
T_1 * V_21 , T_1 * V_18 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned int V_37 ;
T_1 V_61 ;
V_5 V_89 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_61 = V_2 -> V_3 . V_61 ;
V_89 = F_23 ( & V_2 -> V_3 ) ;
V_61 = F_59 ( V_61 , V_89 ) ;
if ( * V_150 != V_2 -> V_86 ) {
* V_150 = V_2 -> V_86 ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
}
if ( F_18 ( V_61 . V_17 >= V_2 -> V_78 . V_17 ) )
* V_16 = F_47 ( V_2 -> V_16 , F_10 ( 1 , 0 ) ) ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_61 ;
}
int F_142 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
struct V_9 V_10 ;
T_7 V_153 , V_154 ;
int V_76 ;
V_76 = F_143 ( V_152 ) ;
if ( V_76 )
return V_76 ;
if ( V_152 -> V_155 & V_156 ) {
struct V_67 V_20 ;
V_20 . V_11 = V_152 -> time . V_11 ;
V_20 . V_12 = V_152 -> time . V_105 ;
if ( ! ( V_152 -> V_155 & V_157 ) )
V_20 . V_12 *= 1000 ;
V_76 = F_77 ( & V_20 ) ;
if ( V_76 )
return V_76 ;
}
F_56 ( & V_10 ) ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
V_153 = V_154 = V_2 -> V_19 ;
V_76 = F_144 ( V_152 , & V_10 , & V_154 ) ;
if ( V_154 != V_153 ) {
F_81 ( V_2 , V_154 ) ;
F_50 ( V_2 , V_87 | V_85 ) ;
}
F_45 ( V_2 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
if ( V_154 != V_153 )
F_76 () ;
F_145 () ;
return V_76 ;
}
void F_146 ( const struct V_67 * V_158 , const struct V_67 * V_159 )
{
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_147 ( V_158 , V_159 ) ;
F_75 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
}
void F_148 ( unsigned long V_148 )
{
F_149 ( & V_160 ) ;
F_139 ( V_148 ) ;
F_150 ( & V_160 ) ;
F_128 () ;
}
