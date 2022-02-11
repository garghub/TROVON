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
static void F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_44 = V_45 . V_44 ;
F_21 ( & V_45 . V_46 ) ;
memcpy ( V_44 , & V_2 -> V_3 , sizeof( * V_44 ) ) ;
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
static inline void F_26 ( struct V_1 * V_2 )
{
struct V_49 V_50 , V_51 ;
V_50 = F_27 ( F_2 ( V_2 ) ) ;
V_51 = F_27 ( V_2 -> V_15 ) ;
F_28 ( & V_50 , & V_51 , V_2 -> V_3 . clock , V_2 -> V_3 . V_30 ,
V_2 -> V_3 . V_28 ) ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
T_4 V_52 ;
V_52 = V_2 -> V_3 . V_4 & ( ( 1ULL << V_2 -> V_3 . V_7 ) - 1 ) ;
V_2 -> V_3 . V_4 -= V_52 ;
V_2 -> V_3 . V_4 += 1ULL << V_2 -> V_3 . V_7 ;
V_2 -> V_36 += V_52 << V_2 -> V_37 ;
V_2 -> V_36 -= ( 1ULL << V_2 -> V_3 . V_7 ) << V_2 -> V_37 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_53 )
{
F_31 ( & V_54 , V_53 , V_2 ) ;
}
int F_32 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
int V_59 ;
F_33 ( & V_60 , V_58 ) ;
V_59 = F_34 ( & V_54 , V_56 ) ;
F_30 ( V_2 , true ) ;
F_35 ( & V_60 , V_58 ) ;
return V_59 ;
}
int F_36 ( struct V_55 * V_56 )
{
unsigned long V_58 ;
int V_59 ;
F_33 ( & V_60 , V_58 ) ;
V_59 = F_37 ( & V_54 , V_56 ) ;
F_35 ( & V_60 , V_58 ) ;
return V_59 ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
V_5 V_61 ;
T_3 V_43 ;
V_61 = ( V_5 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_43 = ( T_3 ) V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_48 = F_39 ( V_61 * V_6 + V_43 ) ;
V_2 -> V_62 = F_8 ( V_2 -> V_63 ) ;
V_43 += ( T_3 ) ( V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ) ;
if ( V_43 >= V_6 )
V_61 ++ ;
V_2 -> V_64 = V_61 ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_65 )
{
if ( V_65 & V_66 ) {
V_2 -> V_36 = 0 ;
F_41 () ;
}
F_38 ( V_2 ) ;
F_26 ( V_2 ) ;
F_30 ( V_2 , V_65 & V_67 ) ;
if ( V_65 & V_68 )
memcpy ( & V_69 , & V_57 . V_1 ,
sizeof( V_57 . V_1 ) ) ;
F_20 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
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
F_43 ( & V_2 -> V_63 , V_43 ) ;
}
int F_44 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
T_4 V_70 = 0 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_70 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
V_10 -> V_12 = 0 ;
F_43 ( V_10 , V_70 ) ;
if ( F_46 ( V_71 ) )
return - V_72 ;
return 0 ;
}
void F_47 ( struct V_9 * V_10 )
{
F_48 ( F_44 ( V_10 ) ) ;
}
T_1 F_49 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
T_4 V_70 ;
F_48 ( V_71 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_70 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_70 ) ;
}
T_1 F_51 ( enum V_73 V_74 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 , * V_75 = V_76 [ V_74 ] ;
T_4 V_70 ;
F_48 ( V_71 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = F_9 ( V_2 -> V_3 . V_48 , * V_75 ) ;
V_70 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_70 ) ;
}
T_1 F_52 ( T_1 V_77 , enum V_73 V_74 )
{
T_1 * V_75 = V_76 [ V_74 ] ;
unsigned long V_46 ;
T_1 V_78 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_78 = F_9 ( V_77 , * V_75 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_78 ;
}
T_1 F_53 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
T_4 V_70 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_62 ;
V_70 = F_18 ( V_2 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_70 ) ;
}
void F_54 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_79 ;
T_4 V_43 ;
unsigned int V_46 ;
F_48 ( V_71 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_43 = F_16 ( & V_2 -> V_3 ) ;
V_79 = V_2 -> V_15 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
V_10 -> V_11 += V_79 . V_11 ;
V_10 -> V_12 = 0 ;
F_43 ( V_10 , V_43 + V_79 . V_12 ) ;
}
T_6 F_55 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
F_48 ( V_71 ) ;
return V_2 -> V_64 ;
}
T_6 F_56 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
T_6 V_61 ;
unsigned int V_46 ;
if ( F_57 ( V_80 ) )
return V_2 -> V_8 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_61 = V_2 -> V_8 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_61 ;
}
void F_58 ( struct V_49 * V_81 , struct V_49 * V_82 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
T_4 V_83 , V_84 ;
F_7 ( V_71 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
* V_81 = F_27 ( V_2 -> V_63 ) ;
V_82 -> V_11 = V_2 -> V_8 ;
V_82 -> V_12 = 0 ;
V_83 = F_18 ( V_2 ) ;
V_84 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
F_59 ( V_81 , V_83 ) ;
F_59 ( V_82 , V_84 ) ;
}
void F_60 ( struct V_85 * V_86 )
{
struct V_9 V_47 ;
F_47 ( & V_47 ) ;
V_86 -> V_11 = V_47 . V_11 ;
V_86 -> V_87 = V_47 . V_12 / 1000 ;
}
int F_61 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_88 , V_50 ;
unsigned long V_58 ;
if ( ! F_62 ( V_10 ) )
return - V_89 ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_50 = F_2 ( V_2 ) ;
V_88 . V_11 = V_10 -> V_11 - V_50 . V_11 ;
V_88 . V_12 = V_10 -> V_12 - V_50 . V_12 ;
F_5 ( V_2 , F_64 ( V_2 -> V_15 , V_88 ) ) ;
F_3 ( V_2 , V_10 ) ;
F_40 ( V_2 , V_66 | V_68 | V_67 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_66 () ;
return 0 ;
}
int F_67 ( struct V_49 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
struct V_9 V_90 , V_14 ;
int V_59 = 0 ;
if ( ( unsigned long ) V_10 -> V_12 >= V_6 )
return - V_89 ;
V_90 = F_68 ( * V_10 ) ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_14 = F_69 ( F_2 ( V_2 ) , V_90 ) ;
if ( ! F_62 ( & V_14 ) ) {
V_59 = - V_89 ;
goto error;
}
F_4 ( V_2 , & V_90 ) ;
F_5 ( V_2 , F_64 ( V_2 -> V_15 , V_90 ) ) ;
error:
F_40 ( V_2 , V_66 | V_68 | V_67 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_66 () ;
return V_59 ;
}
T_7 F_70 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_7 V_59 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_59 = V_2 -> V_19 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_59 ;
}
static void F_71 ( struct V_1 * V_2 , T_7 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_72 ( T_7 V_19 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_71 ( V_2 , V_19 ) ;
F_40 ( V_2 , V_68 | V_67 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_66 () ;
}
static int F_73 ( void * V_91 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_22 * V_92 , * V_93 ;
unsigned long V_58 ;
V_92 = (struct V_22 * ) V_91 ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
if ( F_74 ( V_92 -> V_94 ) ) {
if ( ! V_92 -> V_95 || V_92 -> V_95 ( V_92 ) == 0 ) {
V_93 = V_2 -> V_3 . clock ;
F_12 ( V_2 , V_92 ) ;
if ( V_93 -> V_96 )
V_93 -> V_96 ( V_93 ) ;
F_75 ( V_93 -> V_94 ) ;
} else {
F_75 ( V_92 -> V_94 ) ;
}
}
F_40 ( V_2 , V_66 | V_68 | V_67 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
return 0 ;
}
int F_76 ( struct V_22 * clock )
{
struct V_1 * V_2 = & V_57 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_77 ( F_73 , clock , NULL ) ;
F_78 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_79 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_90 ;
unsigned long V_46 ;
T_4 V_70 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_70 = F_18 ( V_2 ) ;
V_90 = V_2 -> V_63 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
F_43 ( & V_90 , V_70 ) ;
* V_10 = V_90 ;
}
int F_80 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
int V_59 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_59 = V_2 -> V_3 . clock -> V_58 & V_97 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_59 ;
}
V_5 F_81 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
V_5 V_59 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_59 = V_2 -> V_3 . clock -> V_98 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_59 ;
}
void __weak F_82 ( struct V_49 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_83 ( struct V_49 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_8 F_84 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_22 * clock ;
unsigned long V_58 ;
struct V_9 V_47 , V_99 , V_14 ;
struct V_49 V_10 ;
F_82 ( & V_10 ) ;
V_47 = F_68 ( V_10 ) ;
if ( ! F_62 ( & V_47 ) ) {
F_85 ( L_1
L_2 ) ;
V_47 . V_11 = 0 ;
V_47 . V_12 = 0 ;
} else if ( V_47 . V_11 || V_47 . V_12 )
V_100 = true ;
F_83 ( & V_10 ) ;
V_99 = F_68 ( V_10 ) ;
if ( ! F_62 ( & V_99 ) ) {
F_85 ( L_3
L_2 ) ;
V_99 . V_11 = 0 ;
V_99 . V_12 = 0 ;
}
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_86 () ;
clock = F_87 () ;
if ( clock -> V_95 )
clock -> V_95 ( clock ) ;
F_12 ( V_2 , clock ) ;
F_3 ( V_2 , & V_47 ) ;
V_2 -> V_63 . V_11 = 0 ;
V_2 -> V_63 . V_12 = 0 ;
V_2 -> V_62 . V_17 = 0 ;
if ( V_99 . V_11 == 0 && V_99 . V_12 == 0 )
V_99 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_99 . V_11 , - V_99 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_40 ( V_2 , V_68 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_62 ( V_20 ) ) {
F_89 ( V_101
L_4
L_5 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_64 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_90 ( V_20 ) ;
}
void F_91 ( struct V_9 * V_20 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
if ( F_92 () )
return;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
F_88 ( V_2 , V_20 ) ;
F_40 ( V_2 , V_66 | V_68 | V_67 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_66 () ;
}
static void F_93 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_22 * clock = V_2 -> V_3 . clock ;
unsigned long V_58 ;
struct V_9 V_102 , V_88 ;
struct V_49 V_14 ;
T_2 V_42 , V_103 ;
bool V_104 = false ;
F_82 ( & V_14 ) ;
V_102 = F_68 ( V_14 ) ;
F_94 () ;
F_95 () ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
V_42 = V_2 -> V_3 . V_26 ( clock ) ;
if ( ( clock -> V_58 & V_105 ) &&
V_42 > V_2 -> V_3 . V_28 ) {
V_5 V_106 , V_107 = V_108 ;
T_3 V_30 = clock -> V_30 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_43 = 0 ;
V_103 = F_17 ( V_42 , V_2 -> V_3 . V_28 ,
V_2 -> V_3 . V_27 ) ;
F_13 ( V_107 , V_30 ) ;
if ( V_103 > V_107 ) {
V_106 = F_96 ( V_103 , V_107 ) ;
V_43 = ( ( ( V_5 ) V_107 * V_30 ) >> V_7 ) * V_106 ;
V_103 -= V_106 * V_107 ;
}
V_43 += ( ( V_5 ) V_103 * V_30 ) >> V_7 ;
V_88 = F_97 ( V_43 ) ;
V_104 = true ;
} else if ( F_98 ( & V_102 , & V_109 ) > 0 ) {
V_88 = F_64 ( V_102 , V_109 ) ;
V_104 = true ;
}
if ( V_104 )
F_88 ( V_2 , & V_88 ) ;
V_2 -> V_3 . V_28 = V_42 ;
V_2 -> V_36 = 0 ;
V_71 = 0 ;
F_40 ( V_2 , V_68 | V_67 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_99 () ;
F_100 ( V_110 , NULL ) ;
F_101 () ;
}
static int F_102 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
struct V_9 V_20 , V_111 ;
static struct V_9 V_112 ;
struct V_49 V_14 ;
F_82 ( & V_14 ) ;
V_109 = F_68 ( V_14 ) ;
if ( V_109 . V_11 || V_109 . V_12 )
V_100 = true ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_71 = 1 ;
V_20 = F_64 ( F_2 ( V_2 ) , V_109 ) ;
V_111 = F_64 ( V_20 , V_112 ) ;
if ( abs ( V_111 . V_11 ) >= 2 ) {
V_112 = V_20 ;
} else {
V_109 =
F_69 ( V_109 , V_111 ) ;
}
F_40 ( V_2 , V_68 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_100 ( V_113 , NULL ) ;
F_103 () ;
F_104 () ;
return 0 ;
}
static int T_8 F_105 ( void )
{
F_106 ( & V_114 ) ;
return 0 ;
}
static T_9 void F_107 ( struct V_1 * V_2 ,
T_4 V_75 ,
bool V_115 ,
int V_116 )
{
T_4 V_23 = V_2 -> V_31 ;
T_7 V_117 = 1 ;
if ( V_115 ) {
V_117 = - V_117 ;
V_23 = - V_23 ;
V_75 = - V_75 ;
}
V_117 <<= V_116 ;
V_23 <<= V_116 ;
V_75 <<= V_116 ;
if ( ( V_117 > 0 ) && ( V_2 -> V_3 . V_30 + V_117 < V_117 ) ) {
F_7 ( 1 ) ;
return;
}
V_2 -> V_3 . V_30 += V_117 ;
V_2 -> V_32 += V_23 ;
V_2 -> V_3 . V_4 -= V_75 ;
V_2 -> V_36 -= ( V_23 - V_75 ) << V_2 -> V_37 ;
}
static T_9 void F_108 ( struct V_1 * V_2 ,
T_4 V_75 )
{
T_4 V_23 = V_2 -> V_31 ;
T_4 V_118 = V_2 -> V_32 ;
T_4 V_119 ;
bool V_115 ;
T_3 V_120 ;
if ( V_2 -> V_40 )
V_118 -= V_2 -> V_31 ;
V_2 -> V_39 = F_109 () ;
V_119 = F_109 () >> V_2 -> V_37 ;
V_119 -= ( V_118 + V_2 -> V_33 ) ;
if ( F_110 ( ( V_119 >= 0 ) && ( V_119 <= V_23 ) ) )
return;
V_115 = ( V_119 < 0 ) ;
V_119 = abs ( V_119 ) ;
for ( V_120 = 0 ; V_119 > V_23 ; V_120 ++ )
V_119 >>= 1 ;
F_107 ( V_2 , V_75 , V_115 , V_120 ) ;
}
static void F_111 ( struct V_1 * V_2 , T_4 V_75 )
{
F_108 ( V_2 , V_75 ) ;
if ( ! V_2 -> V_40 && ( V_2 -> V_36 > 0 ) ) {
V_2 -> V_40 = 1 ;
F_107 ( V_2 , V_75 , 0 , 0 ) ;
} else if ( V_2 -> V_40 && ( V_2 -> V_36 <= 0 ) ) {
F_107 ( V_2 , V_75 , 1 , 0 ) ;
V_2 -> V_40 = 0 ;
}
if ( F_46 ( V_2 -> V_3 . clock -> V_121 &&
( abs ( V_2 -> V_3 . V_30 - V_2 -> V_3 . clock -> V_30 )
> V_2 -> V_3 . clock -> V_121 ) ) ) {
F_112 ( V_101
L_6 ,
V_2 -> V_3 . clock -> V_122 , ( long ) V_2 -> V_3 . V_30 ,
( long ) V_2 -> V_3 . clock -> V_30 + V_2 -> V_3 . clock -> V_121 ) ;
}
if ( F_46 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_123 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_36 += V_123 << V_2 -> V_37 ;
}
}
static inline unsigned int F_113 ( struct V_1 * V_2 )
{
V_5 V_124 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_125 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_124 ) {
int V_126 ;
V_2 -> V_3 . V_4 -= V_124 ;
V_2 -> V_8 ++ ;
V_126 = F_114 ( V_2 -> V_8 ) ;
if ( F_46 ( V_126 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_126 ;
V_10 . V_11 = V_126 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_64 ( V_2 -> V_15 , V_10 ) ) ;
F_71 ( V_2 , V_2 -> V_19 - V_126 ) ;
V_125 = V_67 ;
}
}
return V_125 ;
}
static T_2 F_115 ( struct V_1 * V_2 , T_2 V_75 ,
T_3 V_7 ,
unsigned int * V_125 )
{
T_2 V_23 = V_2 -> V_31 << V_7 ;
V_5 V_127 ;
if ( V_75 < V_23 )
return V_75 ;
V_75 -= V_23 ;
V_2 -> V_3 . V_28 += V_23 ;
V_2 -> V_3 . V_4 += V_2 -> V_32 << V_7 ;
* V_125 |= F_113 ( V_2 ) ;
V_127 = ( V_5 ) V_2 -> V_34 << V_7 ;
V_127 += V_2 -> V_63 . V_12 ;
if ( V_127 >= V_6 ) {
V_5 V_128 = V_127 ;
V_127 = F_13 ( V_128 , V_6 ) ;
V_2 -> V_63 . V_11 += V_128 ;
}
V_2 -> V_63 . V_12 = V_127 ;
V_2 -> V_36 += V_2 -> V_39 << V_7 ;
V_2 -> V_36 -= ( V_2 -> V_32 + V_2 -> V_33 ) <<
( V_2 -> V_37 + V_7 ) ;
return V_75 ;
}
void F_116 ( void )
{
struct V_1 * V_129 = & V_57 . V_1 ;
struct V_1 * V_2 = & V_69 ;
T_2 V_75 ;
int V_7 = 0 , V_130 ;
unsigned int V_125 = 0 ;
unsigned long V_58 ;
F_33 ( & V_60 , V_58 ) ;
if ( F_46 ( V_71 ) )
goto V_131;
#ifdef F_117
V_75 = V_129 -> V_31 ;
#else
V_75 = F_17 ( V_2 -> V_3 . V_26 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_28 , V_2 -> V_3 . V_27 ) ;
#endif
if ( V_75 < V_129 -> V_31 )
goto V_131;
V_7 = F_118 ( V_75 ) - F_118 ( V_2 -> V_31 ) ;
V_7 = V_107 ( 0 , V_7 ) ;
V_130 = ( 64 - ( F_118 ( F_109 () ) + 1 ) ) - 1 ;
V_7 = F_119 ( V_7 , V_130 ) ;
while ( V_75 >= V_2 -> V_31 ) {
V_75 = F_115 ( V_2 , V_75 , V_7 ,
& V_125 ) ;
if ( V_75 < V_2 -> V_31 << V_7 )
V_7 -- ;
}
F_111 ( V_2 , V_75 ) ;
F_29 ( V_2 ) ;
V_125 |= F_113 ( V_2 ) ;
F_63 ( & V_57 . V_46 ) ;
memcpy ( V_129 , V_2 , sizeof( * V_2 ) ) ;
F_40 ( V_129 , V_125 ) ;
F_65 ( & V_57 . V_46 ) ;
V_131:
F_35 ( & V_60 , V_58 ) ;
if ( V_125 )
F_120 () ;
}
void F_121 ( struct V_49 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
T_1 V_132 = F_122 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_123 ( V_132 ) ;
}
unsigned long F_124 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
return V_2 -> V_8 ;
}
struct V_49 F_125 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
return F_27 ( F_2 ( V_2 ) ) ;
}
struct V_49 F_126 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_47 ;
unsigned long V_46 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_47 = F_2 ( V_2 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_27 ( V_47 ) ;
}
struct V_9 F_127 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_47 , V_133 ;
unsigned long V_46 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_47 = F_2 ( V_2 ) ;
V_133 = V_2 -> V_15 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
F_6 ( & V_47 , V_47 . V_11 + V_133 . V_11 ,
V_47 . V_12 + V_133 . V_12 ) ;
return V_47 ;
}
void F_128 ( unsigned long V_134 )
{
V_135 += V_134 ;
F_129 ( V_134 ) ;
}
T_1 F_130 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
V_5 V_70 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_70 = V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_70 ) ;
}
T_1 F_131 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
V_5 V_70 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_70 = F_16 ( & V_2 -> V_3 ) ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_70 ) ;
}
int F_132 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
struct V_9 V_10 ;
T_7 V_138 , V_139 ;
int V_59 ;
V_59 = F_133 ( V_137 ) ;
if ( V_59 )
return V_59 ;
if ( V_137 -> V_140 & V_141 ) {
struct V_49 V_20 ;
V_20 . V_11 = V_137 -> time . V_11 ;
V_20 . V_12 = V_137 -> time . V_87 ;
if ( ! ( V_137 -> V_140 & V_142 ) )
V_20 . V_12 *= 1000 ;
V_59 = F_67 ( & V_20 ) ;
if ( V_59 )
return V_59 ;
}
F_47 ( & V_10 ) ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
V_138 = V_139 = V_2 -> V_19 ;
V_59 = F_134 ( V_137 , & V_10 , & V_139 ) ;
if ( V_139 != V_138 ) {
F_71 ( V_2 , V_139 ) ;
F_40 ( V_2 , V_68 | V_67 ) ;
}
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
if ( V_139 != V_138 )
F_66 () ;
F_135 () ;
return V_59 ;
}
void F_136 ( const struct V_49 * V_143 , const struct V_49 * V_144 )
{
unsigned long V_58 ;
F_33 ( & V_60 , V_58 ) ;
F_63 ( & V_57 . V_46 ) ;
F_137 ( V_143 , V_144 ) ;
F_65 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
}
void F_138 ( unsigned long V_134 )
{
F_139 ( & V_145 ) ;
F_128 ( V_134 ) ;
F_140 ( & V_145 ) ;
F_116 () ;
}
