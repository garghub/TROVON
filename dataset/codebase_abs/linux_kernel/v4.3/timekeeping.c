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
int V_76 = 0 ;
if ( ! F_72 ( V_10 ) )
return - V_107 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
V_68 = F_2 ( V_2 ) ;
V_106 . V_11 = V_10 -> V_11 - V_68 . V_11 ;
V_106 . V_12 = V_10 -> V_12 - V_68 . V_12 ;
if ( F_74 ( & V_2 -> V_15 , & V_106 ) > 0 ) {
V_76 = - V_107 ;
goto V_108;
}
F_5 ( V_2 , F_75 ( V_2 -> V_15 , V_106 ) ) ;
F_3 ( V_2 , V_10 ) ;
V_108:
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_77 () ;
return V_76 ;
}
int F_78 ( struct V_67 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
struct V_9 V_109 , V_14 ;
int V_76 = 0 ;
if ( ( unsigned long ) V_10 -> V_12 >= V_6 )
return - V_107 ;
V_109 = F_79 ( * V_10 ) ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
V_14 = F_80 ( F_2 ( V_2 ) , V_109 ) ;
if ( F_74 ( & V_2 -> V_15 , & V_109 ) > 0 ||
! F_72 ( & V_14 ) ) {
V_76 = - V_107 ;
goto error;
}
F_4 ( V_2 , & V_109 ) ;
F_5 ( V_2 , F_75 ( V_2 -> V_15 , V_109 ) ) ;
error:
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_77 () ;
return V_76 ;
}
T_7 F_81 ( void )
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
static void F_82 ( struct V_1 * V_2 , T_7 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_83 ( T_7 V_19 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_82 ( V_2 , V_19 ) ;
F_50 ( V_2 , V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_77 () ;
}
static int F_84 ( void * V_110 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * V_111 , * V_112 ;
unsigned long V_75 ;
V_111 = (struct V_41 * ) V_110 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
if ( F_85 ( V_111 -> V_113 ) ) {
if ( ! V_111 -> V_114 || V_111 -> V_114 ( V_111 ) == 0 ) {
V_112 = V_2 -> V_3 . clock ;
F_19 ( V_2 , V_111 ) ;
if ( V_112 -> V_115 )
V_112 -> V_115 ( V_112 ) ;
F_86 ( V_112 -> V_113 ) ;
} else {
F_86 ( V_111 -> V_113 ) ;
}
}
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
return 0 ;
}
int F_87 ( struct V_41 * clock )
{
struct V_1 * V_2 = & V_32 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_88 ( F_84 , clock , NULL ) ;
F_89 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_90 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_9 V_109 ;
unsigned long V_37 ;
T_4 V_89 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_89 = F_23 ( & V_2 -> V_45 ) ;
V_109 = V_2 -> V_81 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
F_54 ( & V_109 , V_89 ) ;
* V_10 = V_109 ;
}
int F_91 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
int V_76 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_76 = V_2 -> V_3 . clock -> V_75 & V_116 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_76 ;
}
V_5 F_92 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_37 ;
V_5 V_76 ;
do {
V_37 = F_15 ( & V_32 . V_37 ) ;
V_76 = V_2 -> V_3 . clock -> V_117 ;
} while ( F_16 ( & V_32 . V_37 , V_37 ) );
return V_76 ;
}
void __weak F_93 ( struct V_67 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_94 ( struct V_9 * V_109 )
{
struct V_67 V_10 ;
F_93 ( & V_10 ) ;
* V_109 = F_79 ( V_10 ) ;
}
void __weak F_95 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_8 F_96 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * clock ;
unsigned long V_75 ;
struct V_9 V_33 , V_118 , V_14 ;
F_94 ( & V_33 ) ;
if ( ! F_72 ( & V_33 ) ) {
F_97 ( L_9
L_10 ) ;
V_33 . V_11 = 0 ;
V_33 . V_12 = 0 ;
} else if ( V_33 . V_11 || V_33 . V_12 )
V_119 = true ;
F_95 ( & V_118 ) ;
if ( ! F_72 ( & V_118 ) ) {
F_97 ( L_11
L_10 ) ;
V_118 . V_11 = 0 ;
V_118 . V_12 = 0 ;
}
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_98 () ;
clock = F_99 () ;
if ( clock -> V_114 )
clock -> V_114 ( clock ) ;
F_19 ( V_2 , clock ) ;
F_3 ( V_2 , & V_33 ) ;
V_2 -> V_81 . V_11 = 0 ;
V_2 -> V_81 . V_12 = 0 ;
if ( V_118 . V_11 == 0 && V_118 . V_12 == 0 )
V_118 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_118 . V_11 , - V_118 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_50 ( V_2 , V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_72 ( V_20 ) ) {
F_13 ( V_120
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_75 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_101 ( V_20 ) ;
}
bool F_102 ( void )
{
return V_121 ;
}
bool F_103 ( void )
{
return V_119 ;
}
void F_104 ( struct V_9 * V_20 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
F_100 ( V_2 , V_20 ) ;
F_50 ( V_2 , V_84 | V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_77 () ;
}
void F_105 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
struct V_41 * clock = V_2 -> V_3 . clock ;
unsigned long V_75 ;
struct V_9 V_122 , V_106 ;
T_2 V_40 , V_123 ;
V_121 = false ;
F_94 ( & V_122 ) ;
F_106 () ;
F_107 () ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
if ( ( clock -> V_75 & V_124 ) &&
V_40 > V_2 -> V_3 . V_39 ) {
V_5 V_125 , V_36 = V_126 ;
T_3 V_47 = clock -> V_47 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_58 = 0 ;
V_123 = F_17 ( V_40 , V_2 -> V_3 . V_39 ,
V_2 -> V_3 . V_35 ) ;
F_20 ( V_36 , V_47 ) ;
if ( V_123 > V_36 ) {
V_125 = F_108 ( V_123 , V_36 ) ;
V_58 = ( ( ( V_5 ) V_36 * V_47 ) >> V_7 ) * V_125 ;
V_123 -= V_125 * V_36 ;
}
V_58 += ( ( V_5 ) V_123 * V_47 ) >> V_7 ;
V_106 = F_109 ( V_58 ) ;
V_121 = true ;
} else if ( F_74 ( & V_122 , & V_127 ) > 0 ) {
V_106 = F_75 ( V_122 , V_127 ) ;
V_121 = true ;
}
if ( V_121 )
F_100 ( V_2 , & V_106 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_53 = 0 ;
V_90 = 0 ;
F_50 ( V_2 , V_87 | V_85 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_110 () ;
F_111 () ;
F_112 () ;
}
int F_113 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
struct V_9 V_20 , V_128 ;
static struct V_9 V_129 ;
F_94 ( & V_127 ) ;
if ( V_127 . V_11 || V_127 . V_12 )
V_119 = true ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_52 ( V_2 ) ;
V_90 = 1 ;
if ( V_119 ) {
V_20 = F_75 ( F_2 ( V_2 ) , V_127 ) ;
V_128 = F_75 ( V_20 , V_129 ) ;
if ( abs ( V_128 . V_11 ) >= 2 ) {
V_129 = V_20 ;
} else {
V_127 =
F_80 ( V_127 , V_128 ) ;
}
}
F_50 ( V_2 , V_87 ) ;
F_32 ( V_2 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
F_114 () ;
F_115 () ;
F_116 () ;
return 0 ;
}
static int T_8 F_117 ( void )
{
F_118 ( & V_130 ) ;
return 0 ;
}
static T_5 void F_119 ( struct V_1 * V_2 ,
T_4 V_22 ,
bool V_131 ,
int V_132 )
{
T_4 V_42 = V_2 -> V_48 ;
T_7 V_133 = 1 ;
if ( V_131 ) {
V_133 = - V_133 ;
V_42 = - V_42 ;
V_22 = - V_22 ;
}
V_133 <<= V_132 ;
V_42 <<= V_132 ;
V_22 <<= V_132 ;
if ( ( V_133 > 0 ) && ( V_2 -> V_3 . V_47 + V_133 < V_133 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_47 += V_133 ;
V_2 -> V_49 += V_42 ;
V_2 -> V_3 . V_4 -= V_22 ;
V_2 -> V_53 -= ( V_42 - V_22 ) << V_2 -> V_54 ;
}
static T_5 void F_120 ( struct V_1 * V_2 ,
T_4 V_22 )
{
T_4 V_42 = V_2 -> V_48 ;
T_4 V_134 = V_2 -> V_49 ;
T_4 V_135 ;
bool V_131 ;
T_3 V_136 ;
if ( V_2 -> V_57 )
V_134 -= V_2 -> V_48 ;
V_2 -> V_56 = F_121 () ;
V_135 = F_121 () >> V_2 -> V_54 ;
V_135 -= ( V_134 + V_2 -> V_50 ) ;
if ( F_122 ( ( V_135 >= 0 ) && ( V_135 <= V_42 ) ) )
return;
V_131 = ( V_135 < 0 ) ;
V_135 = F_123 ( V_135 ) ;
for ( V_136 = 0 ; V_135 > V_42 ; V_136 ++ )
V_135 >>= 1 ;
F_119 ( V_2 , V_22 , V_131 , V_136 ) ;
}
static void F_124 ( struct V_1 * V_2 , T_4 V_22 )
{
F_120 ( V_2 , V_22 ) ;
if ( ! V_2 -> V_57 && ( V_2 -> V_53 > 0 ) ) {
V_2 -> V_57 = 1 ;
F_119 ( V_2 , V_22 , 0 , 0 ) ;
} else if ( V_2 -> V_57 && ( V_2 -> V_53 <= 0 ) ) {
F_119 ( V_2 , V_22 , 1 , 0 ) ;
V_2 -> V_57 = 0 ;
}
if ( F_18 ( V_2 -> V_3 . clock -> V_137 &&
( abs ( V_2 -> V_3 . V_47 - V_2 -> V_3 . clock -> V_47 )
> V_2 -> V_3 . clock -> V_137 ) ) ) {
F_125 ( V_120
L_14 ,
V_2 -> V_3 . clock -> V_24 , ( long ) V_2 -> V_3 . V_47 ,
( long ) V_2 -> V_3 . clock -> V_47 + V_2 -> V_3 . clock -> V_137 ) ;
}
if ( F_18 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_138 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_53 += V_138 << V_2 -> V_54 ;
}
}
static inline unsigned int F_126 ( struct V_1 * V_2 )
{
V_5 V_139 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_140 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_139 ) {
int V_141 ;
V_2 -> V_3 . V_4 -= V_139 ;
V_2 -> V_8 ++ ;
V_141 = F_127 ( V_2 -> V_8 ) ;
if ( F_18 ( V_141 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_141 ;
V_10 . V_11 = V_141 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_75 ( V_2 -> V_15 , V_10 ) ) ;
F_82 ( V_2 , V_2 -> V_19 - V_141 ) ;
V_140 = V_85 ;
}
}
return V_140 ;
}
static T_2 F_128 ( struct V_1 * V_2 , T_2 V_22 ,
T_3 V_7 ,
unsigned int * V_140 )
{
T_2 V_42 = V_2 -> V_48 << V_7 ;
V_5 V_142 ;
if ( V_22 < V_42 )
return V_22 ;
V_22 -= V_42 ;
V_2 -> V_3 . V_39 += V_42 ;
V_2 -> V_45 . V_39 += V_42 ;
V_2 -> V_3 . V_4 += V_2 -> V_49 << V_7 ;
* V_140 |= F_126 ( V_2 ) ;
V_142 = ( V_5 ) V_2 -> V_51 << V_7 ;
V_142 += V_2 -> V_81 . V_12 ;
if ( V_142 >= V_6 ) {
V_5 V_143 = V_142 ;
V_142 = F_20 ( V_143 , V_6 ) ;
V_2 -> V_81 . V_11 += V_143 ;
}
V_2 -> V_81 . V_12 = V_142 ;
V_2 -> V_53 += V_2 -> V_56 << V_7 ;
V_2 -> V_53 -= ( V_2 -> V_49 + V_2 -> V_50 ) <<
( V_2 -> V_54 + V_7 ) ;
return V_22 ;
}
void F_129 ( void )
{
struct V_1 * V_144 = & V_32 . V_1 ;
struct V_1 * V_2 = & V_88 ;
T_2 V_22 ;
int V_7 = 0 , V_145 ;
unsigned int V_140 = 0 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
if ( F_18 ( V_90 ) )
goto V_108;
#ifdef F_130
V_22 = V_144 -> V_48 ;
#else
V_22 = F_17 ( V_2 -> V_3 . V_38 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_39 , V_2 -> V_3 . V_35 ) ;
#endif
if ( V_22 < V_144 -> V_48 )
goto V_108;
F_12 ( V_144 , V_22 ) ;
V_7 = F_131 ( V_22 ) - F_131 ( V_2 -> V_48 ) ;
V_7 = V_36 ( 0 , V_7 ) ;
V_145 = ( 64 - ( F_131 ( F_121 () ) + 1 ) ) - 1 ;
V_7 = F_132 ( V_7 , V_145 ) ;
while ( V_22 >= V_2 -> V_48 ) {
V_22 = F_128 ( V_2 , V_22 , V_7 ,
& V_140 ) ;
if ( V_22 < V_2 -> V_48 << V_7 )
V_7 -- ;
}
F_124 ( V_2 , V_22 ) ;
F_36 ( V_2 ) ;
V_140 |= F_126 ( V_2 ) ;
F_73 ( & V_32 . V_37 ) ;
F_50 ( V_2 , V_140 ) ;
memcpy ( V_144 , V_2 , sizeof( * V_2 ) ) ;
F_76 ( & V_32 . V_37 ) ;
V_108:
F_42 ( & V_77 , V_75 ) ;
if ( V_140 )
F_133 () ;
}
void F_134 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
T_1 V_146 = F_47 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_135 ( V_146 ) ;
}
unsigned long F_136 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return V_2 -> V_8 ;
}
struct V_67 F_137 ( void )
{
struct V_1 * V_2 = & V_32 . V_1 ;
return F_34 ( F_2 ( V_2 ) ) ;
}
struct V_9 F_138 ( void )
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
struct V_9 F_139 ( void )
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
void F_140 ( unsigned long V_148 )
{
V_149 += V_148 ;
F_141 ( V_148 ) ;
}
T_1 F_142 ( unsigned int * V_150 , T_1 * V_16 ,
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
int F_143 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = & V_32 . V_1 ;
unsigned long V_75 ;
struct V_9 V_10 ;
T_7 V_153 , V_154 ;
int V_76 ;
V_76 = F_144 ( V_152 ) ;
if ( V_76 )
return V_76 ;
if ( V_152 -> V_155 & V_156 ) {
struct V_67 V_20 ;
V_20 . V_11 = V_152 -> time . V_11 ;
V_20 . V_12 = V_152 -> time . V_105 ;
if ( ! ( V_152 -> V_155 & V_157 ) )
V_20 . V_12 *= 1000 ;
V_76 = F_78 ( & V_20 ) ;
if ( V_76 )
return V_76 ;
}
F_56 ( & V_10 ) ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
V_153 = V_154 = V_2 -> V_19 ;
V_76 = F_145 ( V_152 , & V_10 , & V_154 ) ;
if ( V_154 != V_153 ) {
F_82 ( V_2 , V_154 ) ;
F_50 ( V_2 , V_87 | V_85 ) ;
}
F_45 ( V_2 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
if ( V_154 != V_153 )
F_77 () ;
F_146 () ;
return V_76 ;
}
void F_147 ( const struct V_67 * V_158 , const struct V_67 * V_159 )
{
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_73 ( & V_32 . V_37 ) ;
F_148 ( V_158 , V_159 ) ;
F_76 ( & V_32 . V_37 ) ;
F_42 ( & V_77 , V_75 ) ;
}
void F_149 ( unsigned long V_148 )
{
F_150 ( & V_160 ) ;
F_140 ( V_148 ) ;
F_151 ( & V_160 ) ;
F_129 () ;
}
