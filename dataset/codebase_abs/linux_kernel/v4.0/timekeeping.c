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
static void F_12 ( struct V_1 * V_2 , struct V_22 * clock )
{
T_2 V_23 ;
V_5 V_14 , V_24 ;
struct V_22 * V_25 ;
V_25 = V_2 -> V_3 . clock ;
V_2 -> V_3 . clock = clock ;
V_2 -> V_3 . V_26 = clock -> V_26 ;
V_2 -> V_3 . V_27 = clock -> V_27 ;
V_2 -> V_3 . V_28 = V_2 -> V_3 . V_26 ( clock ) ;
V_14 = V_29 ;
V_14 <<= clock -> V_7 ;
V_24 = V_14 ;
V_14 += clock -> V_30 / 2 ;
F_13 ( V_14 , clock -> V_30 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
V_23 = ( T_2 ) V_14 ;
V_2 -> V_31 = V_23 ;
V_2 -> V_32 = ( V_5 ) V_23 * clock -> V_30 ;
V_2 -> V_33 = V_24 - V_2 -> V_32 ;
V_2 -> V_34 =
( ( V_5 ) V_23 * clock -> V_30 ) >> clock -> V_7 ;
if ( V_25 ) {
int V_35 = clock -> V_7 - V_25 -> V_7 ;
if ( V_35 < 0 )
V_2 -> V_3 . V_4 >>= - V_35 ;
else
V_2 -> V_3 . V_4 <<= V_35 ;
}
V_2 -> V_3 . V_7 = clock -> V_7 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = V_38 - clock -> V_7 ;
V_2 -> V_39 = V_24 << V_2 -> V_37 ;
V_2 -> V_3 . V_30 = clock -> V_30 ;
V_2 -> V_40 = 0 ;
}
static T_3 F_14 ( void ) { return 0 ; }
static inline T_3 F_15 ( void ) { return 0 ; }
static inline T_4 F_16 ( struct V_41 * V_3 )
{
T_2 V_42 , V_20 ;
T_4 V_43 ;
V_42 = V_3 -> V_26 ( V_3 -> clock ) ;
V_20 = F_17 ( V_42 , V_3 -> V_28 , V_3 -> V_27 ) ;
V_43 = V_20 * V_3 -> V_30 + V_3 -> V_4 ;
V_43 >>= V_3 -> V_7 ;
return V_43 + F_15 () ;
}
static inline T_4 F_18 ( struct V_1 * V_2 )
{
struct V_22 * clock = V_2 -> V_3 . clock ;
T_2 V_42 , V_20 ;
T_4 V_43 ;
V_42 = V_2 -> V_3 . V_26 ( clock ) ;
V_20 = F_17 ( V_42 , V_2 -> V_3 . V_28 , V_2 -> V_3 . V_27 ) ;
V_43 = F_19 ( V_20 , clock -> V_30 , clock -> V_7 ) ;
return V_43 + F_15 () ;
}
static void F_20 ( struct V_41 * V_3 )
{
struct V_41 * V_44 = V_45 . V_44 ;
F_21 ( & V_45 . V_46 ) ;
memcpy ( V_44 , V_3 , sizeof( * V_44 ) ) ;
F_21 ( & V_45 . V_46 ) ;
memcpy ( V_44 + 1 , V_44 , sizeof( * V_44 ) ) ;
}
V_5 T_5 F_22 ( void )
{
struct V_41 * V_3 ;
unsigned int V_46 ;
V_5 V_47 ;
do {
V_46 = F_23 ( & V_45 . V_46 ) ;
V_3 = V_45 . V_44 + ( V_46 & 0x01 ) ;
V_47 = F_24 ( V_3 -> V_48 ) + F_16 ( V_3 ) ;
} while ( F_25 ( & V_45 . V_46 , V_46 ) );
return V_47 ;
}
static T_2 F_26 ( struct V_22 * V_49 )
{
return V_50 ;
}
static void F_27 ( struct V_1 * V_2 )
{
static struct V_41 V_51 ;
struct V_41 * V_3 = & V_2 -> V_3 ;
memcpy ( & V_51 , V_3 , sizeof( V_51 ) ) ;
V_50 = V_3 -> V_26 ( V_3 -> clock ) ;
V_51 . V_26 = F_26 ;
F_20 ( & V_51 ) ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
struct V_52 V_53 , V_54 ;
V_53 = F_29 ( F_2 ( V_2 ) ) ;
V_54 = F_29 ( V_2 -> V_15 ) ;
F_30 ( & V_53 , & V_54 , V_2 -> V_3 . clock , V_2 -> V_3 . V_30 ,
V_2 -> V_3 . V_28 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
T_4 V_55 ;
V_55 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
V_2 -> V_3 . V_4 -= V_55 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_36 += V_55 << V_2 -> V_37 ;
V_2 -> V_36 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_37 ;
}
static void F_32 ( struct V_1 * V_2 , bool V_56 )
{
F_33 ( & V_57 , V_56 , V_2 ) ;
}
int F_34 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_61 ;
int V_62 ;
F_35 ( & V_63 , V_61 ) ;
V_62 = F_36 ( & V_57 , V_59 ) ;
F_32 ( V_2 , true ) ;
F_37 ( & V_63 , V_61 ) ;
return V_62 ;
}
int F_38 ( struct V_58 * V_59 )
{
unsigned long V_61 ;
int V_62 ;
F_35 ( & V_63 , V_61 ) ;
V_62 = F_39 ( & V_57 , V_59 ) ;
F_37 ( & V_63 , V_61 ) ;
return V_62 ;
}
static inline void F_40 ( struct V_1 * V_2 )
{
V_5 V_64 ;
T_3 V_43 ;
V_64 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_43 = ( T_3 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_48 = F_41 ( V_64 * V_6 + V_43 ) ;
V_2 -> V_65 = F_8 ( V_2 -> V_66 ) ;
V_43 += ( T_3 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_43 >= V_6 )
V_64 ++ ;
V_2 -> V_67 = V_64 ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_68 )
{
if ( V_68 & V_69 ) {
V_2 -> V_36 = 0 ;
F_43 () ;
}
F_40 ( V_2 ) ;
F_28 ( V_2 ) ;
F_32 ( V_2 , V_68 & V_70 ) ;
if ( V_68 & V_71 )
memcpy ( & V_72 , & V_60 . V_1 ,
sizeof( V_60 . V_1 ) ) ;
F_20 ( & V_2 -> V_3 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_22 * clock = V_2 -> V_3 . clock ;
T_2 V_42 , V_20 ;
T_4 V_43 ;
V_42 = V_2 -> V_3 . V_26 ( clock ) ;
V_20 = F_17 ( V_42 , V_2 -> V_3 . V_28 , V_2 -> V_3 . V_27 ) ;
V_2 -> V_3 . V_28 = V_42 ;
V_2 -> V_3 . V_4 += V_20 * V_2 -> V_3 . V_30 ;
V_2 -> V_3 . V_4 += ( V_5 ) F_15 () << V_2 -> V_3 . V_7 ;
F_1 ( V_2 ) ;
V_43 = F_19 ( V_20 , clock -> V_30 , clock -> V_7 ) ;
F_45 ( & V_2 -> V_66 , V_43 ) ;
}
int F_46 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_46 ;
T_4 V_73 = 0 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_73 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
V_10 -> V_12 = 0 ;
F_45 ( V_10 , V_73 ) ;
if ( F_48 ( V_74 ) )
return - V_75 ;
return 0 ;
}
void F_49 ( struct V_9 * V_10 )
{
F_50 ( F_46 ( V_10 ) ) ;
}
T_1 F_51 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
T_4 V_73 ;
F_50 ( V_74 ) ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_73 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return F_52 ( V_44 , V_73 ) ;
}
T_1 F_53 ( enum V_76 V_77 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned int V_46 ;
T_1 V_44 , * V_78 = V_79 [ V_77 ] ;
T_4 V_73 ;
F_50 ( V_74 ) ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_44 = F_9 ( V_2 -> V_3 . V_48 , * V_78 ) ;
V_73 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return F_52 ( V_44 , V_73 ) ;
}
T_1 F_54 ( T_1 V_80 , enum V_76 V_77 )
{
T_1 * V_78 = V_79 [ V_77 ] ;
unsigned long V_46 ;
T_1 V_81 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_81 = F_9 ( V_80 , * V_78 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return V_81 ;
}
T_1 F_55 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
T_4 V_73 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_44 = V_2 -> V_65 ;
V_73 = F_18 ( V_2 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return F_52 ( V_44 , V_73 ) ;
}
void F_56 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_9 V_82 ;
T_4 V_43 ;
unsigned int V_46 ;
F_50 ( V_74 ) ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_43 = F_16 ( & V_2 -> V_3 ) ;
V_82 = V_2 -> V_15 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
V_10 -> V_11 += V_82 . V_11 ;
V_10 -> V_12 = 0 ;
F_45 ( V_10 , V_43 + V_82 . V_12 ) ;
}
T_6 F_57 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
F_50 ( V_74 ) ;
return V_2 -> V_67 ;
}
T_6 F_58 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
T_6 V_64 ;
unsigned int V_46 ;
if ( F_59 ( V_83 ) )
return V_2 -> V_8 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_64 = V_2 -> V_8 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return V_64 ;
}
void F_60 ( struct V_52 * V_84 , struct V_52 * V_85 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_46 ;
T_4 V_86 , V_87 ;
F_7 ( V_74 ) ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
* V_84 = F_29 ( V_2 -> V_66 ) ;
V_85 -> V_11 = V_2 -> V_8 ;
V_85 -> V_12 = 0 ;
V_86 = F_18 ( V_2 ) ;
V_87 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
F_61 ( V_84 , V_86 ) ;
F_61 ( V_85 , V_87 ) ;
}
void F_62 ( struct V_88 * V_89 )
{
struct V_9 V_47 ;
F_49 ( & V_47 ) ;
V_89 -> V_11 = V_47 . V_11 ;
V_89 -> V_90 = V_47 . V_12 / 1000 ;
}
int F_63 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_9 V_91 , V_53 ;
unsigned long V_61 ;
if ( ! F_64 ( V_10 ) )
return - V_92 ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_44 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
V_91 . V_11 = V_10 -> V_11 - V_53 . V_11 ;
V_91 . V_12 = V_10 -> V_12 - V_53 . V_12 ;
F_5 ( V_2 , F_66 ( V_2 -> V_15 , V_91 ) ) ;
F_3 ( V_2 , V_10 ) ;
F_42 ( V_2 , V_69 | V_71 | V_70 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
F_68 () ;
return 0 ;
}
int F_69 ( struct V_52 * V_10 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_61 ;
struct V_9 V_93 , V_14 ;
int V_62 = 0 ;
if ( ( unsigned long ) V_10 -> V_12 >= V_6 )
return - V_92 ;
V_93 = F_70 ( * V_10 ) ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_44 ( V_2 ) ;
V_14 = F_71 ( F_2 ( V_2 ) , V_93 ) ;
if ( ! F_64 ( & V_14 ) ) {
V_62 = - V_92 ;
goto error;
}
F_4 ( V_2 , & V_93 ) ;
F_5 ( V_2 , F_66 ( V_2 -> V_15 , V_93 ) ) ;
error:
F_42 ( V_2 , V_69 | V_71 | V_70 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
F_68 () ;
return V_62 ;
}
T_7 F_72 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned int V_46 ;
T_7 V_62 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_62 = V_2 -> V_19 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return V_62 ;
}
static void F_73 ( struct V_1 * V_2 , T_7 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_74 ( T_7 V_19 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_61 ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_73 ( V_2 , V_19 ) ;
F_42 ( V_2 , V_71 | V_70 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
F_68 () ;
}
static int F_75 ( void * V_94 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_22 * V_95 , * V_96 ;
unsigned long V_61 ;
V_95 = (struct V_22 * ) V_94 ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_44 ( V_2 ) ;
if ( F_76 ( V_95 -> V_97 ) ) {
if ( ! V_95 -> V_98 || V_95 -> V_98 ( V_95 ) == 0 ) {
V_96 = V_2 -> V_3 . clock ;
F_12 ( V_2 , V_95 ) ;
if ( V_96 -> V_99 )
V_96 -> V_99 ( V_96 ) ;
F_77 ( V_96 -> V_97 ) ;
} else {
F_77 ( V_95 -> V_97 ) ;
}
}
F_42 ( V_2 , V_69 | V_71 | V_70 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
return 0 ;
}
int F_78 ( struct V_22 * clock )
{
struct V_1 * V_2 = & V_60 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_79 ( F_75 , clock , NULL ) ;
F_80 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_81 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_9 V_93 ;
unsigned long V_46 ;
T_4 V_73 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_73 = F_18 ( V_2 ) ;
V_93 = V_2 -> V_66 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
F_45 ( & V_93 , V_73 ) ;
* V_10 = V_93 ;
}
int F_82 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_46 ;
int V_62 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_62 = V_2 -> V_3 . clock -> V_61 & V_100 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return V_62 ;
}
V_5 F_83 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_46 ;
V_5 V_62 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_62 = V_2 -> V_3 . clock -> V_101 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return V_62 ;
}
void __weak F_84 ( struct V_52 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_85 ( struct V_52 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_8 F_86 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_22 * clock ;
unsigned long V_61 ;
struct V_9 V_47 , V_102 , V_14 ;
struct V_52 V_10 ;
F_84 ( & V_10 ) ;
V_47 = F_70 ( V_10 ) ;
if ( ! F_64 ( & V_47 ) ) {
F_87 ( L_1
L_2 ) ;
V_47 . V_11 = 0 ;
V_47 . V_12 = 0 ;
} else if ( V_47 . V_11 || V_47 . V_12 )
V_103 = true ;
F_85 ( & V_10 ) ;
V_102 = F_70 ( V_10 ) ;
if ( ! F_64 ( & V_102 ) ) {
F_87 ( L_3
L_2 ) ;
V_102 . V_11 = 0 ;
V_102 . V_12 = 0 ;
}
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_88 () ;
clock = F_89 () ;
if ( clock -> V_98 )
clock -> V_98 ( clock ) ;
F_12 ( V_2 , clock ) ;
F_3 ( V_2 , & V_47 ) ;
V_2 -> V_66 . V_11 = 0 ;
V_2 -> V_66 . V_12 = 0 ;
V_2 -> V_65 . V_17 = 0 ;
if ( V_102 . V_11 == 0 && V_102 . V_12 == 0 )
V_102 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_102 . V_11 , - V_102 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_42 ( V_2 , V_71 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_64 ( V_20 ) ) {
F_91 ( V_104
L_4
L_5 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_66 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_92 ( V_20 ) ;
}
void F_93 ( struct V_9 * V_20 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_61 ;
if ( F_94 () )
return;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_44 ( V_2 ) ;
F_90 ( V_2 , V_20 ) ;
F_42 ( V_2 , V_69 | V_71 | V_70 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
F_68 () ;
}
void F_95 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_22 * clock = V_2 -> V_3 . clock ;
unsigned long V_61 ;
struct V_9 V_105 , V_91 ;
struct V_52 V_14 ;
T_2 V_42 , V_106 ;
bool V_107 = false ;
F_84 ( & V_14 ) ;
V_105 = F_70 ( V_14 ) ;
F_96 () ;
F_97 () ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
V_42 = V_2 -> V_3 . V_26 ( clock ) ;
if ( ( clock -> V_61 & V_108 ) &&
V_42 > V_2 -> V_3 . V_28 ) {
V_5 V_109 , V_110 = V_111 ;
T_3 V_30 = clock -> V_30 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_43 = 0 ;
V_106 = F_17 ( V_42 , V_2 -> V_3 . V_28 ,
V_2 -> V_3 . V_27 ) ;
F_13 ( V_110 , V_30 ) ;
if ( V_106 > V_110 ) {
V_109 = F_98 ( V_106 , V_110 ) ;
V_43 = ( ( ( V_5 ) V_110 * V_30 ) >> V_7 ) * V_109 ;
V_106 -= V_109 * V_110 ;
}
V_43 += ( ( V_5 ) V_106 * V_30 ) >> V_7 ;
V_91 = F_99 ( V_43 ) ;
V_107 = true ;
} else if ( F_100 ( & V_105 , & V_112 ) > 0 ) {
V_91 = F_66 ( V_105 , V_112 ) ;
V_107 = true ;
}
if ( V_107 )
F_90 ( V_2 , & V_91 ) ;
V_2 -> V_3 . V_28 = V_42 ;
V_2 -> V_36 = 0 ;
V_74 = 0 ;
F_42 ( V_2 , V_71 | V_70 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
F_101 () ;
F_102 ( V_113 , NULL ) ;
F_103 () ;
}
int F_104 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_61 ;
struct V_9 V_20 , V_114 ;
static struct V_9 V_115 ;
struct V_52 V_14 ;
F_84 ( & V_14 ) ;
V_112 = F_70 ( V_14 ) ;
if ( V_112 . V_11 || V_112 . V_12 )
V_103 = true ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_44 ( V_2 ) ;
V_74 = 1 ;
V_20 = F_66 ( F_2 ( V_2 ) , V_112 ) ;
V_114 = F_66 ( V_20 , V_115 ) ;
if ( abs ( V_114 . V_11 ) >= 2 ) {
V_115 = V_20 ;
} else {
V_112 =
F_71 ( V_112 , V_114 ) ;
}
F_42 ( V_2 , V_71 ) ;
F_27 ( V_2 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
F_102 ( V_116 , NULL ) ;
F_105 () ;
F_106 () ;
return 0 ;
}
static int T_8 F_107 ( void )
{
F_108 ( & V_117 ) ;
return 0 ;
}
static T_9 void F_109 ( struct V_1 * V_2 ,
T_4 V_78 ,
bool V_118 ,
int V_119 )
{
T_4 V_23 = V_2 -> V_31 ;
T_7 V_120 = 1 ;
if ( V_118 ) {
V_120 = - V_120 ;
V_23 = - V_23 ;
V_78 = - V_78 ;
}
V_120 <<= V_119 ;
V_23 <<= V_119 ;
V_78 <<= V_119 ;
if ( ( V_120 > 0 ) && ( V_2 -> V_3 . V_30 + V_120 < V_120 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_30 += V_120 ;
V_2 -> V_32 += V_23 ;
V_2 -> V_3 . V_4 -= V_78 ;
V_2 -> V_36 -= ( V_23 - V_78 ) << V_2 -> V_37 ;
}
static T_9 void F_110 ( struct V_1 * V_2 ,
T_4 V_78 )
{
T_4 V_23 = V_2 -> V_31 ;
T_4 V_121 = V_2 -> V_32 ;
T_4 V_122 ;
bool V_118 ;
T_3 V_123 ;
if ( V_2 -> V_40 )
V_121 -= V_2 -> V_31 ;
V_2 -> V_39 = F_111 () ;
V_122 = F_111 () >> V_2 -> V_37 ;
V_122 -= ( V_121 + V_2 -> V_33 ) ;
if ( F_112 ( ( V_122 >= 0 ) && ( V_122 <= V_23 ) ) )
return;
V_118 = ( V_122 < 0 ) ;
V_122 = abs ( V_122 ) ;
for ( V_123 = 0 ; V_122 > V_23 ; V_123 ++ )
V_122 >>= 1 ;
F_109 ( V_2 , V_78 , V_118 , V_123 ) ;
}
static void F_113 ( struct V_1 * V_2 , T_4 V_78 )
{
F_110 ( V_2 , V_78 ) ;
if ( ! V_2 -> V_40 && ( V_2 -> V_36 > 0 ) ) {
V_2 -> V_40 = 1 ;
F_109 ( V_2 , V_78 , 0 , 0 ) ;
} else if ( V_2 -> V_40 && ( V_2 -> V_36 <= 0 ) ) {
F_109 ( V_2 , V_78 , 1 , 0 ) ;
V_2 -> V_40 = 0 ;
}
if ( F_48 ( V_2 -> V_3 . clock -> V_124 &&
( abs ( V_2 -> V_3 . V_30 - V_2 -> V_3 . clock -> V_30 )
> V_2 -> V_3 . clock -> V_124 ) ) ) {
F_114 ( V_104
L_6 ,
V_2 -> V_3 . clock -> V_125 , ( long ) V_2 -> V_3 . V_30 ,
( long ) V_2 -> V_3 . clock -> V_30 + V_2 -> V_3 . clock -> V_124 ) ;
}
if ( F_48 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_126 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_36 += V_126 << V_2 -> V_37 ;
}
}
static inline unsigned int F_115 ( struct V_1 * V_2 )
{
V_5 V_127 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_128 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_127 ) {
int V_129 ;
V_2 -> V_3 . V_4 -= V_127 ;
V_2 -> V_8 ++ ;
V_129 = F_116 ( V_2 -> V_8 ) ;
if ( F_48 ( V_129 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_129 ;
V_10 . V_11 = V_129 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_66 ( V_2 -> V_15 , V_10 ) ) ;
F_73 ( V_2 , V_2 -> V_19 - V_129 ) ;
V_128 = V_70 ;
}
}
return V_128 ;
}
static T_2 F_117 ( struct V_1 * V_2 , T_2 V_78 ,
T_3 V_7 ,
unsigned int * V_128 )
{
T_2 V_23 = V_2 -> V_31 << V_7 ;
V_5 V_130 ;
if ( V_78 < V_23 )
return V_78 ;
V_78 -= V_23 ;
V_2 -> V_3 . V_28 += V_23 ;
V_2 -> V_3 . V_4 += V_2 -> V_32 << V_7 ;
* V_128 |= F_115 ( V_2 ) ;
V_130 = ( V_5 ) V_2 -> V_34 << V_7 ;
V_130 += V_2 -> V_66 . V_12 ;
if ( V_130 >= V_6 ) {
V_5 V_131 = V_130 ;
V_130 = F_13 ( V_131 , V_6 ) ;
V_2 -> V_66 . V_11 += V_131 ;
}
V_2 -> V_66 . V_12 = V_130 ;
V_2 -> V_36 += V_2 -> V_39 << V_7 ;
V_2 -> V_36 -= ( V_2 -> V_32 + V_2 -> V_33 ) <<
( V_2 -> V_37 + V_7 ) ;
return V_78 ;
}
void F_118 ( void )
{
struct V_1 * V_132 = & V_60 . V_1 ;
struct V_1 * V_2 = & V_72 ;
T_2 V_78 ;
int V_7 = 0 , V_133 ;
unsigned int V_128 = 0 ;
unsigned long V_61 ;
F_35 ( & V_63 , V_61 ) ;
if ( F_48 ( V_74 ) )
goto V_134;
#ifdef F_119
V_78 = V_132 -> V_31 ;
#else
V_78 = F_17 ( V_2 -> V_3 . V_26 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_28 , V_2 -> V_3 . V_27 ) ;
#endif
if ( V_78 < V_132 -> V_31 )
goto V_134;
V_7 = F_120 ( V_78 ) - F_120 ( V_2 -> V_31 ) ;
V_7 = V_110 ( 0 , V_7 ) ;
V_133 = ( 64 - ( F_120 ( F_111 () ) + 1 ) ) - 1 ;
V_7 = F_121 ( V_7 , V_133 ) ;
while ( V_78 >= V_2 -> V_31 ) {
V_78 = F_117 ( V_2 , V_78 , V_7 ,
& V_128 ) ;
if ( V_78 < V_2 -> V_31 << V_7 )
V_7 -- ;
}
F_113 ( V_2 , V_78 ) ;
F_31 ( V_2 ) ;
V_128 |= F_115 ( V_2 ) ;
F_65 ( & V_60 . V_46 ) ;
memcpy ( V_132 , V_2 , sizeof( * V_2 ) ) ;
F_42 ( V_132 , V_128 ) ;
F_67 ( & V_60 . V_46 ) ;
V_134:
F_37 ( & V_63 , V_61 ) ;
if ( V_128 )
F_122 () ;
}
void F_123 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
T_1 V_135 = F_124 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_125 ( V_135 ) ;
}
unsigned long F_126 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
return V_2 -> V_8 ;
}
struct V_52 F_127 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
return F_29 ( F_2 ( V_2 ) ) ;
}
struct V_52 F_128 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_9 V_47 ;
unsigned long V_46 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_47 = F_2 ( V_2 ) ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return F_29 ( V_47 ) ;
}
struct V_9 F_129 ( void )
{
struct V_1 * V_2 = & V_60 . V_1 ;
struct V_9 V_47 , V_136 ;
unsigned long V_46 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_47 = F_2 ( V_2 ) ;
V_136 = V_2 -> V_15 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
F_6 ( & V_47 , V_47 . V_11 + V_136 . V_11 ,
V_47 . V_12 + V_136 . V_12 ) ;
return V_47 ;
}
void F_130 ( unsigned long V_137 )
{
V_138 += V_137 ;
F_131 ( V_137 ) ;
}
T_1 F_132 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
V_5 V_73 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_73 = V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return F_52 ( V_44 , V_73 ) ;
}
T_1 F_133 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
V_5 V_73 ;
do {
V_46 = F_47 ( & V_60 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_73 = F_16 ( & V_2 -> V_3 ) ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_25 ( & V_60 . V_46 , V_46 ) );
return F_52 ( V_44 , V_73 ) ;
}
int F_134 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = & V_60 . V_1 ;
unsigned long V_61 ;
struct V_9 V_10 ;
T_7 V_141 , V_142 ;
int V_62 ;
V_62 = F_135 ( V_140 ) ;
if ( V_62 )
return V_62 ;
if ( V_140 -> V_143 & V_144 ) {
struct V_52 V_20 ;
V_20 . V_11 = V_140 -> time . V_11 ;
V_20 . V_12 = V_140 -> time . V_90 ;
if ( ! ( V_140 -> V_143 & V_145 ) )
V_20 . V_12 *= 1000 ;
V_62 = F_69 ( & V_20 ) ;
if ( V_62 )
return V_62 ;
}
F_49 ( & V_10 ) ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
V_141 = V_142 = V_2 -> V_19 ;
V_62 = F_136 ( V_140 , & V_10 , & V_142 ) ;
if ( V_142 != V_141 ) {
F_73 ( V_2 , V_142 ) ;
F_42 ( V_2 , V_71 | V_70 ) ;
}
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
if ( V_142 != V_141 )
F_68 () ;
F_137 () ;
return V_62 ;
}
void F_138 ( const struct V_52 * V_146 , const struct V_52 * V_147 )
{
unsigned long V_61 ;
F_35 ( & V_63 , V_61 ) ;
F_65 ( & V_60 . V_46 ) ;
F_139 ( V_146 , V_147 ) ;
F_67 ( & V_60 . V_46 ) ;
F_37 ( & V_63 , V_61 ) ;
}
void F_140 ( unsigned long V_137 )
{
F_141 ( & V_148 ) ;
F_130 ( V_137 ) ;
F_142 ( & V_148 ) ;
F_118 () ;
}
