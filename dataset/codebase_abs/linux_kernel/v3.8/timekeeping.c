static inline void F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 >= ( ( V_4 ) V_5 << V_2 -> V_6 ) ) {
V_2 -> V_3 -= ( V_4 ) V_5 << V_2 -> V_6 ;
V_2 -> V_7 ++ ;
}
}
static void F_2 ( struct V_1 * V_2 , const struct V_8 * V_9 )
{
V_2 -> V_7 = V_9 -> V_10 ;
V_2 -> V_3 = ( V_4 ) V_9 -> V_11 << V_2 -> V_6 ;
}
static void F_3 ( struct V_1 * V_2 , const struct V_8 * V_9 )
{
V_2 -> V_7 += V_9 -> V_10 ;
V_2 -> V_3 += ( V_4 ) V_9 -> V_11 << V_2 -> V_6 ;
F_1 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_8 V_12 )
{
struct V_8 V_13 ;
F_5 ( & V_13 , - V_2 -> V_14 . V_10 ,
- V_2 -> V_14 . V_11 ) ;
F_6 ( V_2 -> V_15 . V_16 != F_7 ( V_13 ) . V_16 ) ;
V_2 -> V_14 = V_12 ;
F_5 ( & V_13 , - V_12 . V_10 , - V_12 . V_11 ) ;
V_2 -> V_15 = F_7 ( V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_8 V_17 )
{
F_6 ( V_2 -> V_18 . V_16 != F_7 ( V_2 -> V_19 ) . V_16 ) ;
V_2 -> V_19 = V_17 ;
V_2 -> V_18 = F_7 ( V_17 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_20 * clock )
{
T_1 V_21 ;
V_4 V_13 , V_22 ;
struct V_20 * V_23 ;
V_23 = V_2 -> clock ;
V_2 -> clock = clock ;
clock -> V_24 = clock -> V_25 ( clock ) ;
V_13 = V_26 ;
V_13 <<= clock -> V_6 ;
V_22 = V_13 ;
V_13 += clock -> V_27 / 2 ;
F_10 ( V_13 , clock -> V_27 ) ;
if ( V_13 == 0 )
V_13 = 1 ;
V_21 = ( T_1 ) V_13 ;
V_2 -> V_28 = V_21 ;
V_2 -> V_29 = ( V_4 ) V_21 * clock -> V_27 ;
V_2 -> V_30 = V_22 - V_2 -> V_29 ;
V_2 -> V_31 =
( ( V_4 ) V_21 * clock -> V_27 ) >> clock -> V_6 ;
if ( V_23 ) {
int V_32 = clock -> V_6 - V_23 -> V_6 ;
if ( V_32 < 0 )
V_2 -> V_3 >>= - V_32 ;
else
V_2 -> V_3 <<= V_32 ;
}
V_2 -> V_6 = clock -> V_6 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = V_35 - clock -> V_6 ;
V_2 -> V_27 = clock -> V_27 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 )
{
T_1 V_36 , V_37 ;
struct V_20 * clock ;
T_2 V_38 ;
clock = V_2 -> clock ;
V_36 = clock -> V_25 ( clock ) ;
V_37 = ( V_36 - clock -> V_24 ) & clock -> V_39 ;
V_38 = V_37 * V_2 -> V_27 + V_2 -> V_3 ;
V_38 >>= V_2 -> V_6 ;
return V_38 + F_12 () ;
}
static inline T_2 F_13 ( struct V_1 * V_2 )
{
T_1 V_36 , V_37 ;
struct V_20 * clock ;
T_2 V_38 ;
clock = V_2 -> clock ;
V_36 = clock -> V_25 ( clock ) ;
V_37 = ( V_36 - clock -> V_24 ) & clock -> V_39 ;
V_38 = F_14 ( V_37 , clock -> V_27 , clock -> V_6 ) ;
return V_38 + F_12 () ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_40 , 0 , V_2 ) ;
}
int F_17 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
int V_44 ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
V_44 = F_19 ( & V_40 , V_42 ) ;
F_15 ( V_2 ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
return V_44 ;
}
int F_21 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
int V_44 ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
V_44 = F_22 ( & V_40 , V_42 ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
return V_44 ;
}
static void F_23 ( struct V_1 * V_2 , bool V_46 )
{
if ( V_46 ) {
V_2 -> V_33 = 0 ;
F_24 () ;
}
F_25 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_36 , V_37 ;
struct V_20 * clock ;
T_2 V_38 ;
clock = V_2 -> clock ;
V_36 = clock -> V_25 ( clock ) ;
V_37 = ( V_36 - clock -> V_24 ) & clock -> V_39 ;
clock -> V_24 = V_36 ;
V_2 -> V_3 += V_37 * V_2 -> V_27 ;
V_2 -> V_3 += ( V_4 ) F_12 () << V_2 -> V_6 ;
F_1 ( V_2 ) ;
V_38 = F_14 ( V_37 , clock -> V_27 , clock -> V_6 ) ;
F_27 ( & V_2 -> V_47 , V_38 ) ;
}
void F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
T_2 V_49 = 0 ;
F_29 ( V_50 ) ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_49 = F_11 ( V_2 ) ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
V_9 -> V_11 = 0 ;
F_27 ( V_9 , V_49 ) ;
}
T_3 F_32 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_48 ;
T_2 V_51 , V_49 ;
F_29 ( V_50 ) ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_51 = V_2 -> V_7 + V_2 -> V_14 . V_10 ;
V_49 = F_11 ( V_2 ) + V_2 -> V_14 . V_11 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
return F_33 ( F_34 ( V_51 , 0 ) , V_49 ) ;
}
void F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_52 ;
T_2 V_38 ;
unsigned int V_48 ;
F_29 ( V_50 ) ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_38 = F_11 ( V_2 ) ;
V_52 = V_2 -> V_14 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
V_9 -> V_10 += V_52 . V_10 ;
V_9 -> V_11 = 0 ;
F_27 ( V_9 , V_38 + V_52 . V_11 ) ;
}
void F_36 ( struct V_8 * V_53 , struct V_8 * V_54 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
T_2 V_55 , V_56 ;
F_6 ( V_50 ) ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
* V_53 = V_2 -> V_47 ;
V_54 -> V_10 = V_2 -> V_7 ;
V_54 -> V_11 = 0 ;
V_55 = F_13 ( V_2 ) ;
V_56 = F_11 ( V_2 ) ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
F_27 ( V_53 , V_55 ) ;
F_27 ( V_54 , V_56 ) ;
}
void F_37 ( struct V_57 * V_58 )
{
struct V_8 V_59 ;
F_28 ( & V_59 ) ;
V_58 -> V_10 = V_59 . V_10 ;
V_58 -> V_60 = V_59 . V_11 / 1000 ;
}
int F_38 ( const struct V_8 * V_58 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_61 , V_62 ;
unsigned long V_43 ;
if ( ! F_39 ( V_58 ) )
return - V_63 ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
F_26 ( V_2 ) ;
V_62 = F_40 ( V_2 ) ;
V_61 . V_10 = V_58 -> V_10 - V_62 . V_10 ;
V_61 . V_11 = V_58 -> V_11 - V_62 . V_11 ;
F_4 ( V_2 , F_41 ( V_2 -> V_14 , V_61 ) ) ;
F_2 ( V_2 , V_58 ) ;
F_23 ( V_2 , true ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
F_42 () ;
return 0 ;
}
int F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
struct V_8 V_13 ;
int V_44 = 0 ;
if ( ( unsigned long ) V_9 -> V_11 >= V_5 )
return - V_63 ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
F_26 ( V_2 ) ;
V_13 = F_44 ( F_40 ( V_2 ) , * V_9 ) ;
if ( ! F_39 ( & V_13 ) ) {
V_44 = - V_63 ;
goto error;
}
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 , F_41 ( V_2 -> V_14 , * V_9 ) ) ;
error:
F_23 ( V_2 , true ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
F_42 () ;
return V_44 ;
}
static int F_45 ( void * V_64 )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * V_65 , * V_66 ;
unsigned long V_43 ;
V_65 = (struct V_20 * ) V_64 ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
F_26 ( V_2 ) ;
if ( ! V_65 -> V_67 || V_65 -> V_67 ( V_65 ) == 0 ) {
V_66 = V_2 -> clock ;
F_9 ( V_2 , V_65 ) ;
if ( V_66 -> V_68 )
V_66 -> V_68 ( V_66 ) ;
}
F_23 ( V_2 , true ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
return 0 ;
}
void F_46 ( struct V_20 * clock )
{
struct V_1 * V_2 = & V_1 ;
if ( V_2 -> clock == clock )
return;
F_47 ( F_45 , clock , NULL ) ;
F_48 () ;
}
T_3 F_49 ( void )
{
struct V_8 V_59 ;
F_28 ( & V_59 ) ;
return F_7 ( V_59 ) ;
}
void F_50 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
T_2 V_49 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_49 = F_13 ( V_2 ) ;
* V_9 = V_2 -> V_47 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
F_27 ( V_9 , V_49 ) ;
}
int F_51 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
int V_44 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_44 = V_2 -> clock -> V_43 & V_69 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
return V_44 ;
}
V_4 F_52 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
V_4 V_44 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_44 = V_2 -> clock -> V_70 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
return V_44 ;
}
void T_4 F_53 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * clock ;
unsigned long V_43 ;
struct V_8 V_59 , V_71 , V_13 ;
F_54 ( & V_59 ) ;
if ( ! F_39 ( & V_59 ) ) {
F_55 ( L_1
L_2 ) ;
V_59 . V_10 = 0 ;
V_59 . V_11 = 0 ;
}
F_56 ( & V_71 ) ;
if ( ! F_39 ( & V_71 ) ) {
F_55 ( L_3
L_2 ) ;
V_71 . V_10 = 0 ;
V_71 . V_11 = 0 ;
}
F_57 ( & V_2 -> V_45 ) ;
F_58 () ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
clock = F_59 () ;
if ( clock -> V_67 )
clock -> V_67 ( clock ) ;
F_9 ( V_2 , clock ) ;
F_2 ( V_2 , & V_59 ) ;
V_2 -> V_47 . V_10 = 0 ;
V_2 -> V_47 . V_11 = 0 ;
if ( V_71 . V_10 == 0 && V_71 . V_11 == 0 )
V_71 = F_40 ( V_2 ) ;
F_5 ( & V_13 , - V_71 . V_10 , - V_71 . V_11 ) ;
F_4 ( V_2 , V_13 ) ;
V_13 . V_10 = 0 ;
V_13 . V_11 = 0 ;
F_8 ( V_2 , V_13 ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_8 * V_72 )
{
if ( ! F_39 ( V_72 ) ) {
F_61 ( V_73 L_4
L_5 ) ;
return;
}
F_3 ( V_2 , V_72 ) ;
F_4 ( V_2 , F_41 ( V_2 -> V_14 , * V_72 ) ) ;
F_8 ( V_2 , F_44 ( V_2 -> V_19 , * V_72 ) ) ;
}
void F_62 ( struct V_8 * V_72 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
struct V_8 V_9 ;
F_54 ( & V_9 ) ;
if ( ! ( V_9 . V_10 == 0 && V_9 . V_11 == 0 ) )
return;
F_18 ( & V_2 -> V_45 , V_43 ) ;
F_26 ( V_2 ) ;
F_60 ( V_2 , V_72 ) ;
F_23 ( V_2 , true ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
F_42 () ;
}
static void F_63 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
struct V_8 V_9 ;
F_54 ( & V_9 ) ;
F_64 () ;
F_65 () ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
if ( F_66 ( & V_9 , & V_74 ) > 0 ) {
V_9 = F_41 ( V_9 , V_74 ) ;
F_60 ( V_2 , & V_9 ) ;
}
V_2 -> clock -> V_24 = V_2 -> clock -> V_25 ( V_2 -> clock ) ;
V_2 -> V_33 = 0 ;
V_50 = 0 ;
F_23 ( V_2 , false ) ;
F_20 ( & V_2 -> V_45 , V_43 ) ;
F_67 () ;
F_68 ( V_75 , NULL ) ;
F_69 () ;
}
static int F_70 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
struct V_8 V_72 , V_76 ;
static struct V_8 V_77 ;
F_54 ( & V_74 ) ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
F_26 ( V_2 ) ;
V_50 = 1 ;
V_72 = F_41 ( F_40 ( V_2 ) , V_74 ) ;
V_76 = F_41 ( V_72 , V_77 ) ;
if ( abs ( V_76 . V_10 ) >= 2 ) {
V_77 = V_72 ;
} else {
V_74 =
F_44 ( V_74 , V_76 ) ;
}
F_20 ( & V_2 -> V_45 , V_43 ) ;
F_68 ( V_78 , NULL ) ;
F_71 () ;
F_72 () ;
return 0 ;
}
static int T_4 F_73 ( void )
{
F_74 ( & V_79 ) ;
return 0 ;
}
static T_5 int F_75 ( struct V_1 * V_2 ,
T_2 error , T_2 * V_21 ,
T_2 * V_80 )
{
T_2 V_81 , V_82 ;
T_6 V_83 , V_84 ;
T_7 V_85 , V_27 ;
V_85 = V_2 -> V_33 >> ( V_35 + 22 - 2 * V_86 ) ;
V_85 = abs ( V_85 ) ;
for ( V_83 = 0 ; V_85 > 0 ; V_83 ++ )
V_85 >>= 2 ;
V_81 = F_76 () >> ( V_2 -> V_34 + 1 ) ;
V_81 -= V_2 -> V_29 >> 1 ;
error = ( ( error - V_81 ) >> V_83 ) + V_81 ;
V_82 = * V_21 ;
V_27 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_21 = - * V_21 ;
* V_80 = - * V_80 ;
V_27 = - 1 ;
}
for ( V_84 = 0 ; error > V_82 ; V_84 ++ )
error >>= 1 ;
* V_21 <<= V_84 ;
* V_80 <<= V_84 ;
return V_27 << V_84 ;
}
static void F_77 ( struct V_1 * V_2 , T_2 V_80 )
{
T_2 error , V_21 = V_2 -> V_28 ;
int V_84 ;
error = V_2 -> V_33 >> ( V_2 -> V_34 - 1 ) ;
if ( error > V_21 ) {
error >>= 2 ;
if ( F_78 ( error <= V_21 ) )
V_84 = 1 ;
else
V_84 = F_75 ( V_2 , error , & V_21 , & V_80 ) ;
} else {
if ( error < - V_21 ) {
error >>= 2 ;
if ( F_78 ( error >= - V_21 ) ) {
V_84 = - 1 ;
V_21 = - V_21 ;
V_80 = - V_80 ;
} else {
V_84 = F_75 ( V_2 , error , & V_21 , & V_80 ) ;
}
} else {
goto V_87;
}
}
if ( F_79 ( V_2 -> clock -> V_88 &&
( V_2 -> V_27 + V_84 > V_2 -> clock -> V_27 + V_2 -> clock -> V_88 ) ) ) {
F_80 ( V_73
L_6 ,
V_2 -> clock -> V_89 , ( long ) V_2 -> V_27 + V_84 ,
( long ) V_2 -> clock -> V_27 + V_2 -> clock -> V_88 ) ;
}
V_2 -> V_27 += V_84 ;
V_2 -> V_29 += V_21 ;
V_2 -> V_3 -= V_80 ;
V_2 -> V_33 -= ( V_21 - V_80 ) << V_2 -> V_34 ;
V_87:
if ( F_79 ( ( T_2 ) V_2 -> V_3 < 0 ) ) {
T_2 V_90 = - ( T_2 ) V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_33 += V_90 << V_2 -> V_34 ;
}
}
static inline void F_81 ( struct V_1 * V_2 )
{
V_4 V_91 = ( V_4 ) V_5 << V_2 -> V_6 ;
while ( V_2 -> V_3 >= V_91 ) {
int V_92 ;
V_2 -> V_3 -= V_91 ;
V_2 -> V_7 ++ ;
V_92 = F_82 ( V_2 -> V_7 ) ;
if ( F_79 ( V_92 ) ) {
struct V_8 V_9 ;
V_2 -> V_7 += V_92 ;
V_9 . V_10 = V_92 ;
V_9 . V_11 = 0 ;
F_4 ( V_2 ,
F_41 ( V_2 -> V_14 , V_9 ) ) ;
F_83 () ;
}
}
}
static T_1 F_84 ( struct V_1 * V_2 , T_1 V_80 ,
T_6 V_6 )
{
V_4 V_93 ;
if ( V_80 < V_2 -> V_28 << V_6 )
return V_80 ;
V_80 -= V_2 -> V_28 << V_6 ;
V_2 -> clock -> V_24 += V_2 -> V_28 << V_6 ;
V_2 -> V_3 += V_2 -> V_29 << V_6 ;
F_81 ( V_2 ) ;
V_93 = ( V_4 ) V_2 -> V_31 << V_6 ;
V_93 += V_2 -> V_47 . V_11 ;
if ( V_93 >= V_5 ) {
V_4 V_94 = V_93 ;
V_93 = F_10 ( V_94 , V_5 ) ;
V_2 -> V_47 . V_10 += V_94 ;
}
V_2 -> V_47 . V_11 = V_93 ;
V_2 -> V_33 += F_76 () << V_6 ;
V_2 -> V_33 -= ( V_2 -> V_29 + V_2 -> V_30 ) <<
( V_2 -> V_34 + V_6 ) ;
return V_80 ;
}
static inline void F_85 ( struct V_1 * V_2 )
{
T_2 V_95 ;
V_95 = V_2 -> V_3 & ( ( 1ULL << V_2 -> V_6 ) - 1 ) ;
V_2 -> V_3 -= V_95 ;
V_2 -> V_3 += 1ULL << V_2 -> V_6 ;
V_2 -> V_33 += V_95 << V_2 -> V_34 ;
}
static void F_86 ( void )
{
struct V_20 * clock ;
struct V_1 * V_2 = & V_1 ;
T_1 V_80 ;
int V_6 = 0 , V_96 ;
unsigned long V_43 ;
F_18 ( & V_2 -> V_45 , V_43 ) ;
if ( F_79 ( V_50 ) )
goto V_97;
clock = V_2 -> clock ;
#ifdef F_87
V_80 = V_2 -> V_28 ;
#else
V_80 = ( clock -> V_25 ( clock ) - clock -> V_24 ) & clock -> V_39 ;
#endif
if ( V_80 < V_2 -> V_28 )
goto V_97;
V_6 = F_88 ( V_80 ) - F_88 ( V_2 -> V_28 ) ;
V_6 = F_89 ( 0 , V_6 ) ;
V_96 = ( 64 - ( F_88 ( F_76 () ) + 1 ) ) - 1 ;
V_6 = F_90 ( V_6 , V_96 ) ;
while ( V_80 >= V_2 -> V_28 ) {
V_80 = F_84 ( V_2 , V_80 , V_6 ) ;
if ( V_80 < V_2 -> V_28 << V_6 )
V_6 -- ;
}
F_77 ( V_2 , V_80 ) ;
F_85 ( V_2 ) ;
F_81 ( V_2 ) ;
F_23 ( V_2 , false ) ;
V_97:
F_20 ( & V_2 -> V_45 , V_43 ) ;
}
void F_91 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_98 = {
. V_10 = V_2 -> V_14 . V_10 +
V_2 -> V_19 . V_10 ,
. V_11 = V_2 -> V_14 . V_11 +
V_2 -> V_19 . V_11
} ;
F_5 ( V_9 , - V_98 . V_10 , - V_98 . V_11 ) ;
}
void F_92 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_52 , V_99 ;
T_2 V_38 ;
unsigned int V_48 ;
F_29 ( V_50 ) ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_38 = F_11 ( V_2 ) ;
V_52 = V_2 -> V_14 ;
V_99 = V_2 -> V_19 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
V_9 -> V_10 += V_52 . V_10 + V_99 . V_10 ;
V_9 -> V_11 = 0 ;
F_27 ( V_9 , V_38 + V_52 . V_11 + V_99 . V_11 ) ;
}
T_3 F_93 ( void )
{
struct V_8 V_9 ;
F_92 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_94 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
* V_9 = F_44 ( * V_9 , V_2 -> V_19 ) ;
}
unsigned long F_95 ( void )
{
struct V_1 * V_2 = & V_1 ;
return V_2 -> V_7 ;
}
struct V_8 F_96 ( void )
{
struct V_1 * V_2 = & V_1 ;
return F_40 ( V_2 ) ;
}
struct V_8 F_97 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_59 ;
unsigned long V_48 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_59 = F_40 ( V_2 ) ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
return V_59 ;
}
struct V_8 F_98 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_59 , V_100 ;
unsigned long V_48 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_59 = F_40 ( V_2 ) ;
V_100 = V_2 -> V_14 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
F_5 ( & V_59 , V_59 . V_10 + V_100 . V_10 ,
V_59 . V_11 + V_100 . V_11 ) ;
return V_59 ;
}
void F_99 ( unsigned long V_101 )
{
V_102 += V_101 ;
F_86 () ;
F_100 ( V_101 ) ;
}
void F_101 ( struct V_8 * V_103 ,
struct V_8 * V_104 , struct V_8 * V_99 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
* V_103 = F_40 ( V_2 ) ;
* V_104 = V_2 -> V_14 ;
* V_99 = V_2 -> V_19 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
}
T_3 F_102 ( T_3 * V_15 , T_3 * V_18 )
{
struct V_1 * V_2 = & V_1 ;
T_3 V_59 ;
unsigned int V_48 ;
V_4 V_51 , V_49 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_51 = V_2 -> V_7 ;
V_49 = F_11 ( V_2 ) ;
* V_15 = V_2 -> V_15 ;
* V_18 = V_2 -> V_18 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
V_59 = F_33 ( F_34 ( V_51 , 0 ) , V_49 ) ;
V_59 = F_103 ( V_59 , * V_15 ) ;
return V_59 ;
}
T_3 F_104 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_48 ;
struct V_8 V_104 ;
do {
V_48 = F_30 ( & V_2 -> V_45 ) ;
V_104 = V_2 -> V_14 ;
} while ( F_31 ( & V_2 -> V_45 , V_48 ) );
return F_7 ( V_104 ) ;
}
void F_105 ( unsigned long V_101 )
{
F_106 ( & V_105 ) ;
F_99 ( V_101 ) ;
F_107 ( & V_105 ) ;
}
