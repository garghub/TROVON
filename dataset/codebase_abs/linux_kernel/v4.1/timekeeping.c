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
if ( V_25 ) {
if ( V_26 - V_27 > V_28 ) {
F_13 ( L_5 , V_24 ) ;
F_13 ( L_6 ) ;
F_13 ( L_7 ) ;
V_27 = V_26 ;
}
V_25 = 0 ;
}
if ( V_29 ) {
if ( V_26 - V_27 > V_28 ) {
F_13 ( L_8 , V_24 ) ;
F_13 ( L_6 ) ;
F_13 ( L_7 ) ;
V_27 = V_26 ;
}
V_29 = 0 ;
}
}
static inline T_2 F_14 ( struct V_30 * V_31 )
{
T_2 V_32 , V_33 , V_34 , V_35 , V_20 ;
unsigned int V_36 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_32 = V_31 -> V_38 ( V_31 -> clock ) ;
V_33 = V_31 -> V_39 ;
V_34 = V_31 -> V_34 ;
V_35 = V_31 -> clock -> V_23 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
V_20 = F_17 ( V_32 , V_33 , V_34 ) ;
if ( F_18 ( ( ~ V_20 & V_34 ) < ( V_34 >> 3 ) ) ) {
V_25 = 1 ;
V_20 = 0 ;
}
if ( F_18 ( V_20 > V_35 ) ) {
V_29 = 1 ;
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
V_20 = F_17 ( V_40 , V_31 -> V_39 , V_31 -> V_34 ) ;
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
V_2 -> V_3 . V_34 = clock -> V_34 ;
V_2 -> V_3 . V_39 = V_2 -> V_3 . V_38 ( clock ) ;
V_2 -> V_45 . clock = clock ;
V_2 -> V_45 . V_38 = clock -> V_38 ;
V_2 -> V_45 . V_34 = clock -> V_34 ;
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
F_25 ( & V_60 -> V_36 ) ;
memcpy ( V_61 , V_31 , sizeof( * V_61 ) ) ;
F_25 ( & V_60 -> V_36 ) ;
memcpy ( V_61 + 1 , V_61 , sizeof( * V_61 ) ) ;
}
static T_5 V_5 F_26 ( struct V_59 * V_60 )
{
struct V_30 * V_31 ;
unsigned int V_36 ;
V_5 V_32 ;
do {
V_36 = F_27 ( & V_60 -> V_36 ) ;
V_31 = V_60 -> V_61 + ( V_36 & 0x01 ) ;
V_32 = F_28 ( V_31 -> V_61 ) + F_23 ( V_31 ) ;
} while ( F_16 ( & V_60 -> V_36 , V_36 ) );
return V_32 ;
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
struct V_1 * V_2 = & V_37 . V_1 ;
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
V_5 V_78 ;
T_3 V_58 ;
V_78 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_58 = ( T_3 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_61 = F_46 ( V_78 * V_6 + V_58 ) ;
V_2 -> V_45 . V_61 = F_8 ( V_2 -> V_79 ) ;
V_58 += ( T_3 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_58 >= V_6 )
V_78 ++ ;
V_2 -> V_80 = V_78 ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_81 )
{
if ( V_81 & V_82 ) {
V_2 -> V_53 = 0 ;
F_48 () ;
}
F_45 ( V_2 ) ;
F_33 ( V_2 ) ;
F_37 ( V_2 , V_81 & V_83 ) ;
if ( V_81 & V_84 )
memcpy ( & V_85 , & V_37 . V_1 ,
sizeof( V_37 . V_1 ) ) ;
F_24 ( & V_2 -> V_3 , & V_62 ) ;
F_24 ( & V_2 -> V_45 , & V_63 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_41 * clock = V_2 -> V_3 . clock ;
T_2 V_40 , V_20 ;
T_4 V_58 ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
V_20 = F_17 ( V_40 , V_2 -> V_3 . V_39 , V_2 -> V_3 . V_34 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_3 . V_4 += V_20 * V_2 -> V_3 . V_47 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_22 () << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
V_58 = F_50 ( V_20 , V_2 -> V_45 . V_47 , V_2 -> V_45 . V_7 ) ;
F_51 ( & V_2 -> V_79 , V_58 ) ;
}
int F_52 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_36 ;
T_4 V_86 = 0 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_86 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
V_10 -> V_12 = 0 ;
F_51 ( V_10 , V_86 ) ;
if ( F_18 ( V_87 ) )
return - V_88 ;
return 0 ;
}
void F_53 ( struct V_9 * V_10 )
{
F_54 ( F_52 ( V_10 ) ) ;
}
T_1 F_55 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned int V_36 ;
T_1 V_61 ;
T_4 V_86 ;
F_54 ( V_87 ) ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_61 = V_2 -> V_3 . V_61 ;
V_86 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return F_56 ( V_61 , V_86 ) ;
}
T_1 F_57 ( enum V_89 V_90 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned int V_36 ;
T_1 V_61 , * V_22 = V_91 [ V_90 ] ;
T_4 V_86 ;
F_54 ( V_87 ) ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_61 = F_9 ( V_2 -> V_3 . V_61 , * V_22 ) ;
V_86 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return F_56 ( V_61 , V_86 ) ;
}
T_1 F_58 ( T_1 V_92 , enum V_89 V_90 )
{
T_1 * V_22 = V_91 [ V_90 ] ;
unsigned long V_36 ;
T_1 V_93 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_93 = F_9 ( V_92 , * V_22 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return V_93 ;
}
T_1 F_59 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned int V_36 ;
T_1 V_61 ;
T_4 V_86 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_61 = V_2 -> V_45 . V_61 ;
V_86 = F_23 ( & V_2 -> V_45 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return F_56 ( V_61 , V_86 ) ;
}
void F_60 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_9 V_94 ;
T_4 V_58 ;
unsigned int V_36 ;
F_54 ( V_87 ) ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_58 = F_23 ( & V_2 -> V_3 ) ;
V_94 = V_2 -> V_15 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
V_10 -> V_11 += V_94 . V_11 ;
V_10 -> V_12 = 0 ;
F_51 ( V_10 , V_58 + V_94 . V_12 ) ;
}
T_6 F_61 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
F_54 ( V_87 ) ;
return V_2 -> V_80 ;
}
T_6 F_62 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
T_6 V_78 ;
unsigned int V_36 ;
if ( F_63 ( V_95 ) )
return V_2 -> V_8 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_78 = V_2 -> V_8 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return V_78 ;
}
void F_64 ( struct V_67 * V_96 , struct V_67 * V_97 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_36 ;
T_4 V_98 , V_99 ;
F_7 ( V_87 ) ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
* V_96 = F_34 ( V_2 -> V_79 ) ;
V_97 -> V_11 = V_2 -> V_8 ;
V_97 -> V_12 = 0 ;
V_98 = F_23 ( & V_2 -> V_45 ) ;
V_99 = F_23 ( & V_2 -> V_3 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
F_65 ( V_96 , V_98 ) ;
F_65 ( V_97 , V_99 ) ;
}
void F_66 ( struct V_100 * V_101 )
{
struct V_9 V_32 ;
F_53 ( & V_32 ) ;
V_101 -> V_11 = V_32 . V_11 ;
V_101 -> V_102 = V_32 . V_12 / 1000 ;
}
int F_67 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_9 V_103 , V_68 ;
unsigned long V_75 ;
if ( ! F_68 ( V_10 ) )
return - V_104 ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_49 ( V_2 ) ;
V_68 = F_2 ( V_2 ) ;
V_103 . V_11 = V_10 -> V_11 - V_68 . V_11 ;
V_103 . V_12 = V_10 -> V_12 - V_68 . V_12 ;
F_5 ( V_2 , F_70 ( V_2 -> V_15 , V_103 ) ) ;
F_3 ( V_2 , V_10 ) ;
F_47 ( V_2 , V_82 | V_84 | V_83 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
F_72 () ;
return 0 ;
}
int F_73 ( struct V_67 * V_10 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_75 ;
struct V_9 V_105 , V_14 ;
int V_76 = 0 ;
if ( ( unsigned long ) V_10 -> V_12 >= V_6 )
return - V_104 ;
V_105 = F_74 ( * V_10 ) ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_49 ( V_2 ) ;
V_14 = F_75 ( F_2 ( V_2 ) , V_105 ) ;
if ( ! F_68 ( & V_14 ) ) {
V_76 = - V_104 ;
goto error;
}
F_4 ( V_2 , & V_105 ) ;
F_5 ( V_2 , F_70 ( V_2 -> V_15 , V_105 ) ) ;
error:
F_47 ( V_2 , V_82 | V_84 | V_83 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
F_72 () ;
return V_76 ;
}
T_7 F_76 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned int V_36 ;
T_7 V_76 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_76 = V_2 -> V_19 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return V_76 ;
}
static void F_77 ( struct V_1 * V_2 , T_7 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_78 ( T_7 V_19 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_77 ( V_2 , V_19 ) ;
F_47 ( V_2 , V_84 | V_83 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
F_72 () ;
}
static int F_79 ( void * V_106 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_41 * V_107 , * V_108 ;
unsigned long V_75 ;
V_107 = (struct V_41 * ) V_106 ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_49 ( V_2 ) ;
if ( F_80 ( V_107 -> V_109 ) ) {
if ( ! V_107 -> V_110 || V_107 -> V_110 ( V_107 ) == 0 ) {
V_108 = V_2 -> V_3 . clock ;
F_19 ( V_2 , V_107 ) ;
if ( V_108 -> V_111 )
V_108 -> V_111 ( V_108 ) ;
F_81 ( V_108 -> V_109 ) ;
} else {
F_81 ( V_107 -> V_109 ) ;
}
}
F_47 ( V_2 , V_82 | V_84 | V_83 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
return 0 ;
}
int F_82 ( struct V_41 * clock )
{
struct V_1 * V_2 = & V_37 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_83 ( F_79 , clock , NULL ) ;
F_84 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_85 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_9 V_105 ;
unsigned long V_36 ;
T_4 V_86 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_86 = F_23 ( & V_2 -> V_45 ) ;
V_105 = V_2 -> V_79 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
F_51 ( & V_105 , V_86 ) ;
* V_10 = V_105 ;
}
int F_86 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_36 ;
int V_76 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_76 = V_2 -> V_3 . clock -> V_75 & V_112 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return V_76 ;
}
V_5 F_87 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_36 ;
V_5 V_76 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_76 = V_2 -> V_3 . clock -> V_113 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return V_76 ;
}
void __weak F_88 ( struct V_67 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_89 ( struct V_9 * V_105 )
{
struct V_67 V_10 ;
F_88 ( & V_10 ) ;
* V_105 = F_74 ( V_10 ) ;
}
void __weak F_90 ( struct V_67 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_91 ( struct V_9 * V_105 )
{
struct V_67 V_10 ;
F_90 ( & V_10 ) ;
* V_105 = F_74 ( V_10 ) ;
}
void T_8 F_92 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_41 * clock ;
unsigned long V_75 ;
struct V_9 V_32 , V_114 , V_14 ;
F_89 ( & V_32 ) ;
if ( ! F_68 ( & V_32 ) ) {
F_93 ( L_9
L_10 ) ;
V_32 . V_11 = 0 ;
V_32 . V_12 = 0 ;
} else if ( V_32 . V_11 || V_32 . V_12 )
V_115 = true ;
F_91 ( & V_114 ) ;
if ( ! F_68 ( & V_114 ) ) {
F_93 ( L_11
L_10 ) ;
V_114 . V_11 = 0 ;
V_114 . V_12 = 0 ;
}
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_94 () ;
clock = F_95 () ;
if ( clock -> V_110 )
clock -> V_110 ( clock ) ;
F_19 ( V_2 , clock ) ;
F_3 ( V_2 , & V_32 ) ;
V_2 -> V_79 . V_11 = 0 ;
V_2 -> V_79 . V_12 = 0 ;
if ( V_114 . V_11 == 0 && V_114 . V_12 == 0 )
V_114 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_114 . V_11 , - V_114 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_47 ( V_2 , V_84 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_68 ( V_20 ) ) {
F_13 ( V_116
L_12
L_13 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_70 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_97 ( V_20 ) ;
}
bool F_98 ( void )
{
return V_117 ;
}
bool F_99 ( void )
{
return V_115 ;
}
void F_100 ( struct V_9 * V_20 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_49 ( V_2 ) ;
F_96 ( V_2 , V_20 ) ;
F_47 ( V_2 , V_82 | V_84 | V_83 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
F_72 () ;
}
void F_101 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_41 * clock = V_2 -> V_3 . clock ;
unsigned long V_75 ;
struct V_9 V_118 , V_103 ;
T_2 V_40 , V_119 ;
V_117 = false ;
F_89 ( & V_118 ) ;
F_102 () ;
F_103 () ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
V_40 = V_2 -> V_3 . V_38 ( clock ) ;
if ( ( clock -> V_75 & V_120 ) &&
V_40 > V_2 -> V_3 . V_39 ) {
V_5 V_121 , V_35 = V_122 ;
T_3 V_47 = clock -> V_47 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_58 = 0 ;
V_119 = F_17 ( V_40 , V_2 -> V_3 . V_39 ,
V_2 -> V_3 . V_34 ) ;
F_20 ( V_35 , V_47 ) ;
if ( V_119 > V_35 ) {
V_121 = F_104 ( V_119 , V_35 ) ;
V_58 = ( ( ( V_5 ) V_35 * V_47 ) >> V_7 ) * V_121 ;
V_119 -= V_121 * V_35 ;
}
V_58 += ( ( V_5 ) V_119 * V_47 ) >> V_7 ;
V_103 = F_105 ( V_58 ) ;
V_117 = true ;
} else if ( F_106 ( & V_118 , & V_123 ) > 0 ) {
V_103 = F_70 ( V_118 , V_123 ) ;
V_117 = true ;
}
if ( V_117 )
F_96 ( V_2 , & V_103 ) ;
V_2 -> V_3 . V_39 = V_40 ;
V_2 -> V_45 . V_39 = V_40 ;
V_2 -> V_53 = 0 ;
V_87 = 0 ;
F_47 ( V_2 , V_84 | V_83 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
F_107 () ;
F_108 () ;
F_109 () ;
}
int F_110 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_75 ;
struct V_9 V_20 , V_124 ;
static struct V_9 V_125 ;
F_89 ( & V_123 ) ;
if ( V_123 . V_11 || V_123 . V_12 )
V_115 = true ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_49 ( V_2 ) ;
V_87 = 1 ;
if ( V_115 ) {
V_20 = F_70 ( F_2 ( V_2 ) , V_123 ) ;
V_124 = F_70 ( V_20 , V_125 ) ;
if ( abs ( V_124 . V_11 ) >= 2 ) {
V_125 = V_20 ;
} else {
V_123 =
F_75 ( V_123 , V_124 ) ;
}
}
F_47 ( V_2 , V_84 ) ;
F_32 ( V_2 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
F_111 () ;
F_112 () ;
F_113 () ;
return 0 ;
}
static int T_8 F_114 ( void )
{
F_115 ( & V_126 ) ;
return 0 ;
}
static T_5 void F_116 ( struct V_1 * V_2 ,
T_4 V_22 ,
bool V_127 ,
int V_128 )
{
T_4 V_42 = V_2 -> V_48 ;
T_7 V_129 = 1 ;
if ( V_127 ) {
V_129 = - V_129 ;
V_42 = - V_42 ;
V_22 = - V_22 ;
}
V_129 <<= V_128 ;
V_42 <<= V_128 ;
V_22 <<= V_128 ;
if ( ( V_129 > 0 ) && ( V_2 -> V_3 . V_47 + V_129 < V_129 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_47 += V_129 ;
V_2 -> V_49 += V_42 ;
V_2 -> V_3 . V_4 -= V_22 ;
V_2 -> V_53 -= ( V_42 - V_22 ) << V_2 -> V_54 ;
}
static T_5 void F_117 ( struct V_1 * V_2 ,
T_4 V_22 )
{
T_4 V_42 = V_2 -> V_48 ;
T_4 V_130 = V_2 -> V_49 ;
T_4 V_131 ;
bool V_127 ;
T_3 V_132 ;
if ( V_2 -> V_57 )
V_130 -= V_2 -> V_48 ;
V_2 -> V_56 = F_118 () ;
V_131 = F_118 () >> V_2 -> V_54 ;
V_131 -= ( V_130 + V_2 -> V_50 ) ;
if ( F_119 ( ( V_131 >= 0 ) && ( V_131 <= V_42 ) ) )
return;
V_127 = ( V_131 < 0 ) ;
V_131 = abs ( V_131 ) ;
for ( V_132 = 0 ; V_131 > V_42 ; V_132 ++ )
V_131 >>= 1 ;
F_116 ( V_2 , V_22 , V_127 , V_132 ) ;
}
static void F_120 ( struct V_1 * V_2 , T_4 V_22 )
{
F_117 ( V_2 , V_22 ) ;
if ( ! V_2 -> V_57 && ( V_2 -> V_53 > 0 ) ) {
V_2 -> V_57 = 1 ;
F_116 ( V_2 , V_22 , 0 , 0 ) ;
} else if ( V_2 -> V_57 && ( V_2 -> V_53 <= 0 ) ) {
F_116 ( V_2 , V_22 , 1 , 0 ) ;
V_2 -> V_57 = 0 ;
}
if ( F_18 ( V_2 -> V_3 . clock -> V_133 &&
( abs ( V_2 -> V_3 . V_47 - V_2 -> V_3 . clock -> V_47 )
> V_2 -> V_3 . clock -> V_133 ) ) ) {
F_121 ( V_116
L_14 ,
V_2 -> V_3 . clock -> V_24 , ( long ) V_2 -> V_3 . V_47 ,
( long ) V_2 -> V_3 . clock -> V_47 + V_2 -> V_3 . clock -> V_133 ) ;
}
if ( F_18 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_134 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_53 += V_134 << V_2 -> V_54 ;
}
}
static inline unsigned int F_122 ( struct V_1 * V_2 )
{
V_5 V_135 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_136 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_135 ) {
int V_137 ;
V_2 -> V_3 . V_4 -= V_135 ;
V_2 -> V_8 ++ ;
V_137 = F_123 ( V_2 -> V_8 ) ;
if ( F_18 ( V_137 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_137 ;
V_10 . V_11 = V_137 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_70 ( V_2 -> V_15 , V_10 ) ) ;
F_77 ( V_2 , V_2 -> V_19 - V_137 ) ;
V_136 = V_83 ;
}
}
return V_136 ;
}
static T_2 F_124 ( struct V_1 * V_2 , T_2 V_22 ,
T_3 V_7 ,
unsigned int * V_136 )
{
T_2 V_42 = V_2 -> V_48 << V_7 ;
V_5 V_138 ;
if ( V_22 < V_42 )
return V_22 ;
V_22 -= V_42 ;
V_2 -> V_3 . V_39 += V_42 ;
V_2 -> V_45 . V_39 += V_42 ;
V_2 -> V_3 . V_4 += V_2 -> V_49 << V_7 ;
* V_136 |= F_122 ( V_2 ) ;
V_138 = ( V_5 ) V_2 -> V_51 << V_7 ;
V_138 += V_2 -> V_79 . V_12 ;
if ( V_138 >= V_6 ) {
V_5 V_139 = V_138 ;
V_138 = F_20 ( V_139 , V_6 ) ;
V_2 -> V_79 . V_11 += V_139 ;
}
V_2 -> V_79 . V_12 = V_138 ;
V_2 -> V_53 += V_2 -> V_56 << V_7 ;
V_2 -> V_53 -= ( V_2 -> V_49 + V_2 -> V_50 ) <<
( V_2 -> V_54 + V_7 ) ;
return V_22 ;
}
void F_125 ( void )
{
struct V_1 * V_140 = & V_37 . V_1 ;
struct V_1 * V_2 = & V_85 ;
T_2 V_22 ;
int V_7 = 0 , V_141 ;
unsigned int V_136 = 0 ;
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
if ( F_18 ( V_87 ) )
goto V_142;
#ifdef F_126
V_22 = V_140 -> V_48 ;
#else
V_22 = F_17 ( V_2 -> V_3 . V_38 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_39 , V_2 -> V_3 . V_34 ) ;
#endif
if ( V_22 < V_140 -> V_48 )
goto V_142;
F_12 ( V_140 , V_22 ) ;
V_7 = F_127 ( V_22 ) - F_127 ( V_2 -> V_48 ) ;
V_7 = V_35 ( 0 , V_7 ) ;
V_141 = ( 64 - ( F_127 ( F_118 () ) + 1 ) ) - 1 ;
V_7 = F_128 ( V_7 , V_141 ) ;
while ( V_22 >= V_2 -> V_48 ) {
V_22 = F_124 ( V_2 , V_22 , V_7 ,
& V_136 ) ;
if ( V_22 < V_2 -> V_48 << V_7 )
V_7 -- ;
}
F_120 ( V_2 , V_22 ) ;
F_36 ( V_2 ) ;
V_136 |= F_122 ( V_2 ) ;
F_69 ( & V_37 . V_36 ) ;
memcpy ( V_140 , V_2 , sizeof( * V_2 ) ) ;
F_47 ( V_140 , V_136 ) ;
F_71 ( & V_37 . V_36 ) ;
V_142:
F_42 ( & V_77 , V_75 ) ;
if ( V_136 )
F_129 () ;
}
void F_130 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
T_1 V_143 = F_131 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_132 ( V_143 ) ;
}
unsigned long F_133 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
return V_2 -> V_8 ;
}
struct V_67 F_134 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
return F_34 ( F_2 ( V_2 ) ) ;
}
struct V_67 F_135 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_9 V_32 ;
unsigned long V_36 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_32 = F_2 ( V_2 ) ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return F_34 ( V_32 ) ;
}
struct V_9 F_136 ( void )
{
struct V_1 * V_2 = & V_37 . V_1 ;
struct V_9 V_32 , V_144 ;
unsigned long V_36 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_32 = F_2 ( V_2 ) ;
V_144 = V_2 -> V_15 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
F_6 ( & V_32 , V_32 . V_11 + V_144 . V_11 ,
V_32 . V_12 + V_144 . V_12 ) ;
return V_32 ;
}
void F_137 ( unsigned long V_145 )
{
V_146 += V_145 ;
F_138 ( V_145 ) ;
}
T_1 F_139 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned int V_36 ;
T_1 V_61 ;
V_5 V_86 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_61 = V_2 -> V_3 . V_61 ;
V_86 = V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return F_56 ( V_61 , V_86 ) ;
}
T_1 F_140 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned int V_36 ;
T_1 V_61 ;
V_5 V_86 ;
do {
V_36 = F_15 ( & V_37 . V_36 ) ;
V_61 = V_2 -> V_3 . V_61 ;
V_86 = F_23 ( & V_2 -> V_3 ) ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_16 ( & V_37 . V_36 , V_36 ) );
return F_56 ( V_61 , V_86 ) ;
}
int F_141 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = & V_37 . V_1 ;
unsigned long V_75 ;
struct V_9 V_10 ;
T_7 V_149 , V_150 ;
int V_76 ;
V_76 = F_142 ( V_148 ) ;
if ( V_76 )
return V_76 ;
if ( V_148 -> V_151 & V_152 ) {
struct V_67 V_20 ;
V_20 . V_11 = V_148 -> time . V_11 ;
V_20 . V_12 = V_148 -> time . V_102 ;
if ( ! ( V_148 -> V_151 & V_153 ) )
V_20 . V_12 *= 1000 ;
V_76 = F_73 ( & V_20 ) ;
if ( V_76 )
return V_76 ;
}
F_53 ( & V_10 ) ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
V_149 = V_150 = V_2 -> V_19 ;
V_76 = F_143 ( V_148 , & V_10 , & V_150 ) ;
if ( V_150 != V_149 ) {
F_77 ( V_2 , V_150 ) ;
F_47 ( V_2 , V_84 | V_83 ) ;
}
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
if ( V_150 != V_149 )
F_72 () ;
F_144 () ;
return V_76 ;
}
void F_145 ( const struct V_67 * V_154 , const struct V_67 * V_155 )
{
unsigned long V_75 ;
F_40 ( & V_77 , V_75 ) ;
F_69 ( & V_37 . V_36 ) ;
F_146 ( V_154 , V_155 ) ;
F_71 ( & V_37 . V_36 ) ;
F_42 ( & V_77 , V_75 ) ;
}
void F_147 ( unsigned long V_145 )
{
F_148 ( & V_156 ) ;
F_137 ( V_145 ) ;
F_149 ( & V_156 ) ;
F_125 () ;
}
