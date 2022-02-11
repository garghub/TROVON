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
T_4 V_43 ;
V_43 = ( T_4 ) ( V_2 -> V_8 + V_2 -> V_15 . V_11 ) ;
V_43 *= V_6 ;
V_43 += V_2 -> V_15 . V_12 ;
V_2 -> V_3 . V_48 = F_39 ( V_43 ) ;
V_2 -> V_61 = F_8 ( V_2 -> V_62 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_63 )
{
if ( V_63 & V_64 ) {
V_2 -> V_36 = 0 ;
F_41 () ;
}
F_38 ( V_2 ) ;
F_26 ( V_2 ) ;
F_30 ( V_2 , V_63 & V_65 ) ;
if ( V_63 & V_66 )
memcpy ( & V_67 , & V_57 . V_1 ,
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
F_43 ( & V_2 -> V_62 , V_43 ) ;
}
int F_44 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
T_4 V_68 = 0 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_68 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
V_10 -> V_12 = 0 ;
F_43 ( V_10 , V_68 ) ;
if ( F_46 ( V_69 ) )
return - V_70 ;
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
T_4 V_68 ;
F_48 ( V_69 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_68 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_68 ) ;
}
T_1 F_51 ( enum V_71 V_72 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 , * V_73 = V_74 [ V_72 ] ;
T_4 V_68 ;
F_48 ( V_69 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = F_9 ( V_2 -> V_3 . V_48 , * V_73 ) ;
V_68 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_68 ) ;
}
T_1 F_52 ( T_1 V_75 , enum V_71 V_72 )
{
T_1 * V_73 = V_74 [ V_72 ] ;
unsigned long V_46 ;
T_1 V_76 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_76 = F_9 ( V_75 , * V_73 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_76 ;
}
T_1 F_53 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
T_4 V_68 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_61 ;
V_68 = F_18 ( V_2 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_68 ) ;
}
void F_54 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_77 ;
T_4 V_43 ;
unsigned int V_46 ;
F_48 ( V_69 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_10 -> V_11 = V_2 -> V_8 ;
V_43 = F_16 ( & V_2 -> V_3 ) ;
V_77 = V_2 -> V_15 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
V_10 -> V_11 += V_77 . V_11 ;
V_10 -> V_12 = 0 ;
F_43 ( V_10 , V_43 + V_77 . V_12 ) ;
}
void F_55 ( struct V_49 * V_78 , struct V_49 * V_79 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
T_4 V_80 , V_81 ;
F_7 ( V_69 ) ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
* V_78 = F_27 ( V_2 -> V_62 ) ;
V_79 -> V_11 = V_2 -> V_8 ;
V_79 -> V_12 = 0 ;
V_80 = F_18 ( V_2 ) ;
V_81 = F_16 ( & V_2 -> V_3 ) ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
F_56 ( V_78 , V_80 ) ;
F_56 ( V_79 , V_81 ) ;
}
void F_57 ( struct V_82 * V_83 )
{
struct V_9 V_47 ;
F_47 ( & V_47 ) ;
V_83 -> V_11 = V_47 . V_11 ;
V_83 -> V_84 = V_47 . V_12 / 1000 ;
}
int F_58 ( const struct V_49 * V_83 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_85 , V_50 , V_14 ;
unsigned long V_58 ;
if ( ! F_59 ( V_83 ) )
return - V_86 ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_50 = F_2 ( V_2 ) ;
V_85 . V_11 = V_83 -> V_11 - V_50 . V_11 ;
V_85 . V_12 = V_83 -> V_12 - V_50 . V_12 ;
F_5 ( V_2 , F_61 ( V_2 -> V_15 , V_85 ) ) ;
V_14 = F_62 ( * V_83 ) ;
F_3 ( V_2 , & V_14 ) ;
F_40 ( V_2 , V_64 | V_66 | V_65 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_64 () ;
return 0 ;
}
int F_65 ( struct V_49 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
struct V_9 V_87 , V_14 ;
int V_59 = 0 ;
if ( ( unsigned long ) V_10 -> V_12 >= V_6 )
return - V_86 ;
V_87 = F_62 ( * V_10 ) ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_14 = F_66 ( F_2 ( V_2 ) , V_87 ) ;
if ( ! F_67 ( & V_14 ) ) {
V_59 = - V_86 ;
goto error;
}
F_4 ( V_2 , & V_87 ) ;
F_5 ( V_2 , F_61 ( V_2 -> V_15 , V_87 ) ) ;
error:
F_40 ( V_2 , V_64 | V_66 | V_65 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_64 () ;
return V_59 ;
}
T_6 F_68 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_6 V_59 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_59 = V_2 -> V_19 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_59 ;
}
static void F_69 ( struct V_1 * V_2 , T_6 V_19 )
{
V_2 -> V_19 = V_19 ;
V_2 -> V_18 = F_9 ( V_2 -> V_16 , F_10 ( V_19 , 0 ) ) ;
}
void F_70 ( T_6 V_19 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_69 ( V_2 , V_19 ) ;
F_40 ( V_2 , V_66 | V_65 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_64 () ;
}
static int F_71 ( void * V_88 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_22 * V_89 , * V_90 ;
unsigned long V_58 ;
V_89 = (struct V_22 * ) V_88 ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
if ( F_72 ( V_89 -> V_91 ) ) {
if ( ! V_89 -> V_92 || V_89 -> V_92 ( V_89 ) == 0 ) {
V_90 = V_2 -> V_3 . clock ;
F_12 ( V_2 , V_89 ) ;
if ( V_90 -> V_93 )
V_90 -> V_93 ( V_90 ) ;
F_73 ( V_90 -> V_91 ) ;
} else {
F_73 ( V_89 -> V_91 ) ;
}
}
F_40 ( V_2 , V_64 | V_66 | V_65 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
return 0 ;
}
int F_74 ( struct V_22 * clock )
{
struct V_1 * V_2 = & V_57 . V_1 ;
if ( V_2 -> V_3 . clock == clock )
return 0 ;
F_75 ( F_71 , clock , NULL ) ;
F_76 () ;
return V_2 -> V_3 . clock == clock ? 0 : - 1 ;
}
void F_77 ( struct V_49 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_87 ;
unsigned long V_46 ;
T_4 V_68 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_68 = F_18 ( V_2 ) ;
V_87 = V_2 -> V_62 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
F_43 ( & V_87 , V_68 ) ;
* V_10 = F_27 ( V_87 ) ;
}
int F_78 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
int V_59 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_59 = V_2 -> V_3 . clock -> V_58 & V_94 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_59 ;
}
V_5 F_79 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_46 ;
V_5 V_59 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_59 = V_2 -> V_3 . clock -> V_95 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return V_59 ;
}
void __weak F_80 ( struct V_49 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void __weak F_81 ( struct V_49 * V_10 )
{
V_10 -> V_11 = 0 ;
V_10 -> V_12 = 0 ;
}
void T_7 F_82 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_22 * clock ;
unsigned long V_58 ;
struct V_9 V_47 , V_96 , V_14 ;
struct V_49 V_10 ;
F_80 ( & V_10 ) ;
V_47 = F_62 ( V_10 ) ;
if ( ! F_67 ( & V_47 ) ) {
F_83 ( L_1
L_2 ) ;
V_47 . V_11 = 0 ;
V_47 . V_12 = 0 ;
} else if ( V_47 . V_11 || V_47 . V_12 )
V_97 = true ;
F_81 ( & V_10 ) ;
V_96 = F_62 ( V_10 ) ;
if ( ! F_67 ( & V_96 ) ) {
F_83 ( L_3
L_2 ) ;
V_96 . V_11 = 0 ;
V_96 . V_12 = 0 ;
}
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_84 () ;
clock = F_85 () ;
if ( clock -> V_92 )
clock -> V_92 ( clock ) ;
F_12 ( V_2 , clock ) ;
F_3 ( V_2 , & V_47 ) ;
V_2 -> V_62 . V_11 = 0 ;
V_2 -> V_62 . V_12 = 0 ;
V_2 -> V_61 . V_17 = 0 ;
if ( V_96 . V_11 == 0 && V_96 . V_12 == 0 )
V_96 = F_2 ( V_2 ) ;
F_6 ( & V_14 , - V_96 . V_11 , - V_96 . V_12 ) ;
F_5 ( V_2 , V_14 ) ;
F_40 ( V_2 , V_66 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_9 * V_20 )
{
if ( ! F_67 ( V_20 ) ) {
F_87 ( V_98
L_4
L_5 ) ;
return;
}
F_4 ( V_2 , V_20 ) ;
F_5 ( V_2 , F_61 ( V_2 -> V_15 , * V_20 ) ) ;
F_11 ( V_2 , F_8 ( * V_20 ) ) ;
F_88 ( V_20 ) ;
}
void F_89 ( struct V_49 * V_20 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_14 ;
unsigned long V_58 ;
if ( F_90 () )
return;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_14 = F_62 ( * V_20 ) ;
F_86 ( V_2 , & V_14 ) ;
F_40 ( V_2 , V_64 | V_66 | V_65 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_64 () ;
}
static void F_91 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_22 * clock = V_2 -> V_3 . clock ;
unsigned long V_58 ;
struct V_9 V_99 , V_85 ;
struct V_49 V_14 ;
T_2 V_42 , V_100 ;
bool V_101 = false ;
F_80 ( & V_14 ) ;
V_99 = F_62 ( V_14 ) ;
F_92 () ;
F_93 () ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
V_42 = V_2 -> V_3 . V_26 ( clock ) ;
if ( ( clock -> V_58 & V_102 ) &&
V_42 > V_2 -> V_3 . V_28 ) {
V_5 V_103 , V_104 = V_105 ;
T_3 V_30 = clock -> V_30 ;
T_3 V_7 = clock -> V_7 ;
T_4 V_43 = 0 ;
V_100 = F_17 ( V_42 , V_2 -> V_3 . V_28 ,
V_2 -> V_3 . V_27 ) ;
F_13 ( V_104 , V_30 ) ;
if ( V_100 > V_104 ) {
V_103 = F_94 ( V_100 , V_104 ) ;
V_43 = ( ( ( V_5 ) V_104 * V_30 ) >> V_7 ) * V_103 ;
V_100 -= V_103 * V_104 ;
}
V_43 += ( ( V_5 ) V_100 * V_30 ) >> V_7 ;
V_85 = F_95 ( V_43 ) ;
V_101 = true ;
} else if ( F_96 ( & V_99 , & V_106 ) > 0 ) {
V_85 = F_61 ( V_99 , V_106 ) ;
V_101 = true ;
}
if ( V_101 )
F_86 ( V_2 , & V_85 ) ;
V_2 -> V_3 . V_28 = V_42 ;
V_2 -> V_36 = 0 ;
V_69 = 0 ;
F_40 ( V_2 , V_66 | V_65 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_97 () ;
F_98 ( V_107 , NULL ) ;
F_99 () ;
}
static int F_100 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
struct V_9 V_20 , V_108 ;
static struct V_9 V_109 ;
struct V_49 V_14 ;
F_80 ( & V_14 ) ;
V_106 = F_62 ( V_14 ) ;
if ( V_106 . V_11 || V_106 . V_12 )
V_97 = true ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_42 ( V_2 ) ;
V_69 = 1 ;
V_20 = F_61 ( F_2 ( V_2 ) , V_106 ) ;
V_108 = F_61 ( V_20 , V_109 ) ;
if ( abs ( V_108 . V_11 ) >= 2 ) {
V_109 = V_20 ;
} else {
V_106 =
F_66 ( V_106 , V_108 ) ;
}
F_40 ( V_2 , V_66 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
F_98 ( V_110 , NULL ) ;
F_101 () ;
F_102 () ;
return 0 ;
}
static int T_7 F_103 ( void )
{
F_104 ( & V_111 ) ;
return 0 ;
}
static T_8 void F_105 ( struct V_1 * V_2 ,
T_4 V_73 ,
bool V_112 ,
int V_113 )
{
T_4 V_23 = V_2 -> V_31 ;
T_6 V_114 = 1 ;
if ( V_112 ) {
V_114 = - V_114 ;
V_23 = - V_23 ;
V_73 = - V_73 ;
}
V_114 <<= V_113 ;
V_23 <<= V_113 ;
V_73 <<= V_113 ;
V_2 -> V_3 . V_30 += V_114 ;
V_2 -> V_32 += V_23 ;
V_2 -> V_3 . V_4 -= V_73 ;
V_2 -> V_36 -= ( V_23 - V_73 ) << V_2 -> V_37 ;
}
static T_8 void F_106 ( struct V_1 * V_2 ,
T_4 V_73 )
{
T_4 V_23 = V_2 -> V_31 ;
T_4 V_115 = V_2 -> V_32 ;
T_4 V_116 ;
bool V_112 ;
T_3 V_117 ;
if ( V_2 -> V_40 )
V_115 -= V_2 -> V_31 ;
V_2 -> V_39 = F_107 () ;
V_116 = F_107 () >> V_2 -> V_37 ;
V_116 -= ( V_115 + V_2 -> V_33 ) ;
if ( F_108 ( ( V_116 >= 0 ) && ( V_116 <= V_23 ) ) )
return;
V_112 = ( V_116 < 0 ) ;
V_116 = abs ( V_116 ) ;
for ( V_117 = 0 ; V_116 > V_23 ; V_117 ++ )
V_116 >>= 1 ;
F_105 ( V_2 , V_73 , V_112 , V_117 ) ;
}
static void F_109 ( struct V_1 * V_2 , T_4 V_73 )
{
F_106 ( V_2 , V_73 ) ;
if ( ! V_2 -> V_40 && ( V_2 -> V_36 > 0 ) ) {
V_2 -> V_40 = 1 ;
F_105 ( V_2 , V_73 , 0 , 0 ) ;
} else if ( V_2 -> V_40 && ( V_2 -> V_36 <= 0 ) ) {
F_105 ( V_2 , V_73 , 1 , 0 ) ;
V_2 -> V_40 = 0 ;
}
if ( F_46 ( V_2 -> V_3 . clock -> V_118 &&
( V_2 -> V_3 . V_30 > V_2 -> V_3 . clock -> V_30 + V_2 -> V_3 . clock -> V_118 ) ) ) {
F_110 ( V_98
L_6 ,
V_2 -> V_3 . clock -> V_119 , ( long ) V_2 -> V_3 . V_30 ,
( long ) V_2 -> V_3 . clock -> V_30 + V_2 -> V_3 . clock -> V_118 ) ;
}
if ( F_46 ( ( T_4 ) V_2 -> V_3 . V_4 < 0 ) ) {
T_4 V_120 = - ( T_4 ) V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_36 += V_120 << V_2 -> V_37 ;
}
}
static inline unsigned int F_111 ( struct V_1 * V_2 )
{
V_5 V_121 = ( V_5 ) V_6 << V_2 -> V_3 . V_7 ;
unsigned int V_122 = 0 ;
while ( V_2 -> V_3 . V_4 >= V_121 ) {
int V_123 ;
V_2 -> V_3 . V_4 -= V_121 ;
V_2 -> V_8 ++ ;
V_123 = F_112 ( V_2 -> V_8 ) ;
if ( F_46 ( V_123 ) ) {
struct V_9 V_10 ;
V_2 -> V_8 += V_123 ;
V_10 . V_11 = V_123 ;
V_10 . V_12 = 0 ;
F_5 ( V_2 ,
F_61 ( V_2 -> V_15 , V_10 ) ) ;
F_69 ( V_2 , V_2 -> V_19 - V_123 ) ;
V_122 = V_65 ;
}
}
return V_122 ;
}
static T_2 F_113 ( struct V_1 * V_2 , T_2 V_73 ,
T_3 V_7 ,
unsigned int * V_122 )
{
T_2 V_23 = V_2 -> V_31 << V_7 ;
V_5 V_124 ;
if ( V_73 < V_23 )
return V_73 ;
V_73 -= V_23 ;
V_2 -> V_3 . V_28 += V_23 ;
V_2 -> V_3 . V_4 += V_2 -> V_32 << V_7 ;
* V_122 |= F_111 ( V_2 ) ;
V_124 = ( V_5 ) V_2 -> V_34 << V_7 ;
V_124 += V_2 -> V_62 . V_12 ;
if ( V_124 >= V_6 ) {
V_5 V_125 = V_124 ;
V_124 = F_13 ( V_125 , V_6 ) ;
V_2 -> V_62 . V_11 += V_125 ;
}
V_2 -> V_62 . V_12 = V_124 ;
V_2 -> V_36 += V_2 -> V_39 << V_7 ;
V_2 -> V_36 -= ( V_2 -> V_32 + V_2 -> V_33 ) <<
( V_2 -> V_37 + V_7 ) ;
return V_73 ;
}
void F_114 ( void )
{
struct V_1 * V_126 = & V_57 . V_1 ;
struct V_1 * V_2 = & V_67 ;
T_2 V_73 ;
int V_7 = 0 , V_127 ;
unsigned int V_122 = 0 ;
unsigned long V_58 ;
F_33 ( & V_60 , V_58 ) ;
if ( F_46 ( V_69 ) )
goto V_128;
#ifdef F_115
V_73 = V_126 -> V_31 ;
#else
V_73 = F_17 ( V_2 -> V_3 . V_26 ( V_2 -> V_3 . clock ) ,
V_2 -> V_3 . V_28 , V_2 -> V_3 . V_27 ) ;
#endif
if ( V_73 < V_126 -> V_31 )
goto V_128;
V_7 = F_116 ( V_73 ) - F_116 ( V_2 -> V_31 ) ;
V_7 = V_104 ( 0 , V_7 ) ;
V_127 = ( 64 - ( F_116 ( F_107 () ) + 1 ) ) - 1 ;
V_7 = F_117 ( V_7 , V_127 ) ;
while ( V_73 >= V_2 -> V_31 ) {
V_73 = F_113 ( V_2 , V_73 , V_7 ,
& V_122 ) ;
if ( V_73 < V_2 -> V_31 << V_7 )
V_7 -- ;
}
F_109 ( V_2 , V_73 ) ;
F_29 ( V_2 ) ;
V_122 |= F_111 ( V_2 ) ;
F_60 ( & V_57 . V_46 ) ;
memcpy ( V_126 , V_2 , sizeof( * V_2 ) ) ;
F_40 ( V_126 , V_122 ) ;
F_63 ( & V_57 . V_46 ) ;
V_128:
F_35 ( & V_60 , V_58 ) ;
if ( V_122 )
F_118 () ;
}
void F_119 ( struct V_49 * V_10 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
T_1 V_129 = F_120 ( V_2 -> V_16 , V_2 -> V_21 ) ;
* V_10 = F_121 ( V_129 ) ;
}
unsigned long F_122 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
return V_2 -> V_8 ;
}
struct V_49 F_123 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
return F_27 ( F_2 ( V_2 ) ) ;
}
struct V_49 F_124 ( void )
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
struct V_49 F_125 ( void )
{
struct V_1 * V_2 = & V_57 . V_1 ;
struct V_9 V_47 , V_130 ;
unsigned long V_46 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_47 = F_2 ( V_2 ) ;
V_130 = V_2 -> V_15 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
F_6 ( & V_47 , V_47 . V_11 + V_130 . V_11 ,
V_47 . V_12 + V_130 . V_12 ) ;
return F_27 ( V_47 ) ;
}
void F_126 ( unsigned long V_131 )
{
V_132 += V_131 ;
F_127 ( V_131 ) ;
}
T_1 F_128 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
V_5 V_68 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_68 = V_2 -> V_3 . V_4 >> V_2 -> V_3 . V_7 ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_68 ) ;
}
T_1 F_129 ( T_1 * V_16 , T_1 * V_21 ,
T_1 * V_18 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned int V_46 ;
T_1 V_44 ;
V_5 V_68 ;
do {
V_46 = F_45 ( & V_57 . V_46 ) ;
V_44 = V_2 -> V_3 . V_48 ;
V_68 = F_16 ( & V_2 -> V_3 ) ;
* V_16 = V_2 -> V_16 ;
* V_21 = V_2 -> V_21 ;
* V_18 = V_2 -> V_18 ;
} while ( F_25 ( & V_57 . V_46 , V_46 ) );
return F_50 ( V_44 , V_68 ) ;
}
int F_130 ( struct V_133 * V_134 )
{
struct V_1 * V_2 = & V_57 . V_1 ;
unsigned long V_58 ;
struct V_9 V_10 ;
T_6 V_135 , V_136 ;
int V_59 ;
V_59 = F_131 ( V_134 ) ;
if ( V_59 )
return V_59 ;
if ( V_134 -> V_137 & V_138 ) {
struct V_49 V_20 ;
V_20 . V_11 = V_134 -> time . V_11 ;
V_20 . V_12 = V_134 -> time . V_84 ;
if ( ! ( V_134 -> V_137 & V_139 ) )
V_20 . V_12 *= 1000 ;
V_59 = F_65 ( & V_20 ) ;
if ( V_59 )
return V_59 ;
}
F_47 ( & V_10 ) ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
V_135 = V_136 = V_2 -> V_19 ;
V_59 = F_132 ( V_134 , & V_10 , & V_136 ) ;
if ( V_136 != V_135 ) {
F_69 ( V_2 , V_136 ) ;
F_40 ( V_2 , V_66 | V_65 ) ;
}
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
if ( V_136 != V_135 )
F_64 () ;
F_133 () ;
return V_59 ;
}
void F_134 ( const struct V_49 * V_140 , const struct V_49 * V_141 )
{
unsigned long V_58 ;
F_33 ( & V_60 , V_58 ) ;
F_60 ( & V_57 . V_46 ) ;
F_135 ( V_140 , V_141 ) ;
F_63 ( & V_57 . V_46 ) ;
F_35 ( & V_60 , V_58 ) ;
}
void F_136 ( unsigned long V_131 )
{
F_137 ( & V_142 ) ;
F_126 ( V_131 ) ;
F_138 ( & V_142 ) ;
F_114 () ;
}
