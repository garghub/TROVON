static void F_1 ( struct V_1 * clock )
{
T_1 V_2 ;
T_2 V_3 , V_4 ;
V_5 . clock = clock ;
clock -> V_6 = clock -> V_7 ( clock ) ;
V_3 = V_8 ;
V_3 <<= clock -> V_9 ;
V_4 = V_3 ;
V_3 += clock -> V_10 / 2 ;
F_2 ( V_3 , clock -> V_10 ) ;
if ( V_3 == 0 )
V_3 = 1 ;
V_2 = ( T_1 ) V_3 ;
V_5 . V_11 = V_2 ;
V_5 . V_12 = ( T_2 ) V_2 * clock -> V_10 ;
V_5 . V_13 = V_4 - V_5 . V_12 ;
V_5 . V_14 =
( ( T_2 ) V_2 * clock -> V_10 ) >> clock -> V_9 ;
V_5 . V_15 = 0 ;
V_5 . V_9 = clock -> V_9 ;
V_5 . V_16 = 0 ;
V_5 . V_17 = V_18 - clock -> V_9 ;
V_5 . V_10 = clock -> V_10 ;
}
static inline T_3 F_3 ( void )
{
T_1 V_19 , V_20 ;
struct V_1 * clock ;
clock = V_5 . clock ;
V_19 = clock -> V_7 ( clock ) ;
V_20 = ( V_19 - clock -> V_6 ) & clock -> V_21 ;
return F_4 ( V_20 , V_5 . V_10 ,
V_5 . V_9 ) ;
}
static inline T_3 F_5 ( void )
{
T_1 V_19 , V_20 ;
struct V_1 * clock ;
clock = V_5 . clock ;
V_19 = clock -> V_7 ( clock ) ;
V_20 = ( V_19 - clock -> V_6 ) & clock -> V_21 ;
return F_4 ( V_20 , clock -> V_10 , clock -> V_9 ) ;
}
static void F_6 ( void )
{
struct V_22 V_3 , * V_23 = & V_5 . V_24 ;
F_7 ( & V_3 , - V_23 -> V_25 , - V_23 -> V_26 ) ;
V_5 . V_27 = F_8 ( V_3 ) ;
}
static void F_9 ( bool V_28 )
{
if ( V_28 ) {
V_5 . V_16 = 0 ;
F_10 () ;
}
F_6 () ;
F_11 ( & V_5 . V_29 , & V_5 . V_24 ,
V_5 . clock , V_5 . V_10 ) ;
}
static void F_12 ( void )
{
T_1 V_19 , V_20 ;
struct V_1 * clock ;
T_3 V_30 ;
clock = V_5 . clock ;
V_19 = clock -> V_7 ( clock ) ;
V_20 = ( V_19 - clock -> V_6 ) & clock -> V_21 ;
clock -> V_6 = V_19 ;
V_30 = F_4 ( V_20 , V_5 . V_10 ,
V_5 . V_9 ) ;
V_30 += F_13 () ;
F_14 ( & V_5 . V_29 , V_30 ) ;
V_30 = F_4 ( V_20 , clock -> V_10 , clock -> V_9 ) ;
F_14 ( & V_5 . V_31 , V_30 ) ;
}
void F_15 ( struct V_22 * V_32 )
{
unsigned long V_33 ;
T_3 V_34 ;
F_16 ( V_35 ) ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
* V_32 = V_5 . V_29 ;
V_34 = F_3 () ;
V_34 += F_13 () ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
F_14 ( V_32 , V_34 ) ;
}
T_4 F_19 ( void )
{
unsigned int V_33 ;
T_3 V_37 , V_34 ;
F_16 ( V_35 ) ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_37 = V_5 . V_29 . V_25 +
V_5 . V_24 . V_25 ;
V_34 = V_5 . V_29 . V_26 +
V_5 . V_24 . V_26 ;
V_34 += F_3 () ;
V_34 += F_13 () ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
return F_20 ( F_21 ( V_37 , 0 ) , V_34 ) ;
}
void F_22 ( struct V_22 * V_32 )
{
struct V_22 V_38 ;
unsigned int V_33 ;
T_3 V_34 ;
F_16 ( V_35 ) ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
* V_32 = V_5 . V_29 ;
V_38 = V_5 . V_24 ;
V_34 = F_3 () ;
V_34 += F_13 () ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
F_7 ( V_32 , V_32 -> V_25 + V_38 . V_25 ,
V_32 -> V_26 + V_38 . V_26 + V_34 ) ;
}
void F_23 ( struct V_22 * V_39 , struct V_22 * V_40 )
{
unsigned long V_33 ;
T_3 V_41 , V_42 ;
F_24 ( V_35 ) ;
do {
T_5 V_43 ;
V_33 = F_17 ( & V_5 . V_36 ) ;
* V_39 = V_5 . V_31 ;
* V_40 = V_5 . V_29 ;
V_41 = F_5 () ;
V_42 = F_3 () ;
V_43 = F_13 () ;
V_41 += V_43 ;
V_42 += V_43 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
F_14 ( V_39 , V_41 ) ;
F_14 ( V_40 , V_42 ) ;
}
void F_25 ( struct V_44 * V_45 )
{
struct V_22 V_46 ;
F_15 ( & V_46 ) ;
V_45 -> V_25 = V_46 . V_25 ;
V_45 -> V_47 = V_46 . V_26 / 1000 ;
}
int F_26 ( const struct V_22 * V_45 )
{
struct V_22 V_48 ;
unsigned long V_49 ;
if ( ( unsigned long ) V_45 -> V_26 >= V_50 )
return - V_51 ;
F_27 ( & V_5 . V_36 , V_49 ) ;
F_12 () ;
V_48 . V_25 = V_45 -> V_25 - V_5 . V_29 . V_25 ;
V_48 . V_26 = V_45 -> V_26 - V_5 . V_29 . V_26 ;
V_5 . V_24 =
F_28 ( V_5 . V_24 , V_48 ) ;
V_5 . V_29 = * V_45 ;
F_9 ( true ) ;
F_29 ( & V_5 . V_36 , V_49 ) ;
F_30 () ;
return 0 ;
}
int F_31 ( struct V_22 * V_32 )
{
unsigned long V_49 ;
if ( ( unsigned long ) V_32 -> V_26 >= V_50 )
return - V_51 ;
F_27 ( & V_5 . V_36 , V_49 ) ;
F_12 () ;
V_5 . V_29 = F_32 ( V_5 . V_29 , * V_32 ) ;
V_5 . V_24 =
F_28 ( V_5 . V_24 , * V_32 ) ;
F_9 ( true ) ;
F_29 ( & V_5 . V_36 , V_49 ) ;
F_30 () ;
return 0 ;
}
static int F_33 ( void * V_52 )
{
struct V_1 * V_53 , * V_54 ;
unsigned long V_49 ;
V_53 = (struct V_1 * ) V_52 ;
F_27 ( & V_5 . V_36 , V_49 ) ;
F_12 () ;
if ( ! V_53 -> V_55 || V_53 -> V_55 ( V_53 ) == 0 ) {
V_54 = V_5 . clock ;
F_1 ( V_53 ) ;
if ( V_54 -> V_56 )
V_54 -> V_56 ( V_54 ) ;
}
F_9 ( true ) ;
F_29 ( & V_5 . V_36 , V_49 ) ;
return 0 ;
}
void F_34 ( struct V_1 * clock )
{
if ( V_5 . clock == clock )
return;
F_35 ( F_33 , clock , NULL ) ;
F_36 () ;
}
T_4 F_37 ( void )
{
struct V_22 V_46 ;
F_15 ( & V_46 ) ;
return F_8 ( V_46 ) ;
}
void F_38 ( struct V_22 * V_32 )
{
unsigned long V_33 ;
T_3 V_34 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_34 = F_5 () ;
* V_32 = V_5 . V_31 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
F_14 ( V_32 , V_34 ) ;
}
int F_39 ( void )
{
unsigned long V_33 ;
int V_57 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_57 = V_5 . clock -> V_49 & V_58 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
return V_57 ;
}
T_2 F_40 ( void )
{
unsigned long V_33 ;
T_2 V_57 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_57 = V_5 . clock -> V_59 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
return V_57 ;
}
void T_6 F_41 ( void )
{
struct V_1 * clock ;
unsigned long V_49 ;
struct V_22 V_46 , V_60 ;
F_42 ( & V_46 ) ;
F_43 ( & V_60 ) ;
F_44 ( & V_5 . V_36 ) ;
F_45 () ;
F_27 ( & V_5 . V_36 , V_49 ) ;
clock = F_46 () ;
if ( clock -> V_55 )
clock -> V_55 ( clock ) ;
F_1 ( clock ) ;
V_5 . V_29 . V_25 = V_46 . V_25 ;
V_5 . V_29 . V_26 = V_46 . V_26 ;
V_5 . V_31 . V_25 = 0 ;
V_5 . V_31 . V_26 = 0 ;
if ( V_60 . V_25 == 0 && V_60 . V_26 == 0 ) {
V_60 . V_25 = V_5 . V_29 . V_25 ;
V_60 . V_26 = V_5 . V_29 . V_26 ;
}
F_7 ( & V_5 . V_24 ,
- V_60 . V_25 , - V_60 . V_26 ) ;
F_6 () ;
V_5 . V_61 . V_25 = 0 ;
V_5 . V_61 . V_26 = 0 ;
F_29 ( & V_5 . V_36 , V_49 ) ;
}
static void F_47 ( struct V_22 V_62 )
{
V_5 . V_61 = V_62 ;
V_5 . V_63 = F_8 ( V_62 ) ;
}
static void F_48 ( struct V_22 * V_64 )
{
if ( ! F_49 ( V_64 ) ) {
F_50 ( V_65 L_1
L_2 ) ;
return;
}
V_5 . V_29 = F_32 ( V_5 . V_29 , * V_64 ) ;
V_5 . V_24 =
F_28 ( V_5 . V_24 , * V_64 ) ;
F_47 ( F_32 ( V_5 . V_61 , * V_64 ) ) ;
}
void F_51 ( struct V_22 * V_64 )
{
unsigned long V_49 ;
struct V_22 V_32 ;
F_42 ( & V_32 ) ;
if ( ! ( V_32 . V_25 == 0 && V_32 . V_26 == 0 ) )
return;
F_27 ( & V_5 . V_36 , V_49 ) ;
F_12 () ;
F_48 ( V_64 ) ;
F_9 ( true ) ;
F_29 ( & V_5 . V_36 , V_49 ) ;
F_30 () ;
}
static void F_52 ( void )
{
unsigned long V_49 ;
struct V_22 V_32 ;
F_42 ( & V_32 ) ;
F_53 () ;
F_27 ( & V_5 . V_36 , V_49 ) ;
if ( F_54 ( & V_32 , & V_66 ) > 0 ) {
V_32 = F_28 ( V_32 , V_66 ) ;
F_48 ( & V_32 ) ;
}
V_5 . clock -> V_6 = V_5 . clock -> V_7 ( V_5 . clock ) ;
V_5 . V_16 = 0 ;
V_35 = 0 ;
F_9 ( false ) ;
F_29 ( & V_5 . V_36 , V_49 ) ;
F_55 () ;
F_56 ( V_67 , NULL ) ;
F_57 () ;
}
static int F_58 ( void )
{
unsigned long V_49 ;
struct V_22 V_64 , V_68 ;
static struct V_22 V_69 ;
F_42 ( & V_66 ) ;
F_27 ( & V_5 . V_36 , V_49 ) ;
F_12 () ;
V_35 = 1 ;
V_64 = F_28 ( V_5 . V_29 , V_66 ) ;
V_68 = F_28 ( V_64 , V_69 ) ;
if ( abs ( V_68 . V_25 ) >= 2 ) {
V_69 = V_64 ;
} else {
V_66 =
F_32 ( V_66 , V_68 ) ;
}
F_29 ( & V_5 . V_36 , V_49 ) ;
F_56 ( V_70 , NULL ) ;
F_59 () ;
return 0 ;
}
static int T_6 F_60 ( void )
{
F_61 ( & V_71 ) ;
return 0 ;
}
static T_7 int F_62 ( T_3 error , T_3 * V_2 ,
T_3 * V_72 )
{
T_3 V_73 , V_74 ;
T_5 V_75 , V_76 ;
T_8 V_77 , V_10 ;
V_77 = V_5 . V_16 >> ( V_18 + 22 - 2 * V_78 ) ;
V_77 = abs ( V_77 ) ;
for ( V_75 = 0 ; V_77 > 0 ; V_75 ++ )
V_77 >>= 2 ;
V_73 = F_63 () >> ( V_5 . V_17 + 1 ) ;
V_73 -= V_5 . V_12 >> 1 ;
error = ( ( error - V_73 ) >> V_75 ) + V_73 ;
V_74 = * V_2 ;
V_10 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_2 = - * V_2 ;
* V_72 = - * V_72 ;
V_10 = - 1 ;
}
for ( V_76 = 0 ; error > V_74 ; V_76 ++ )
error >>= 1 ;
* V_2 <<= V_76 ;
* V_72 <<= V_76 ;
return V_10 << V_76 ;
}
static void F_64 ( T_3 V_72 )
{
T_3 error , V_2 = V_5 . V_11 ;
int V_76 ;
error = V_5 . V_16 >> ( V_5 . V_17 - 1 ) ;
if ( error > V_2 ) {
error >>= 2 ;
if ( F_65 ( error <= V_2 ) )
V_76 = 1 ;
else
V_76 = F_62 ( error , & V_2 , & V_72 ) ;
} else if ( error < - V_2 ) {
error >>= 2 ;
if ( F_65 ( error >= - V_2 ) ) {
V_76 = - 1 ;
V_2 = - V_2 ;
V_72 = - V_72 ;
} else
V_76 = F_62 ( error , & V_2 , & V_72 ) ;
} else
return;
if ( F_66 ( V_5 . clock -> V_79 &&
( V_5 . V_10 + V_76 >
V_5 . clock -> V_10 + V_5 . clock -> V_79 ) ) ) {
F_67 ( V_65
L_3 ,
V_5 . clock -> V_80 , ( long ) V_5 . V_10 + V_76 ,
( long ) V_5 . clock -> V_10 +
V_5 . clock -> V_79 ) ;
}
V_5 . V_10 += V_76 ;
V_5 . V_12 += V_2 ;
V_5 . V_15 -= V_72 ;
V_5 . V_16 -= ( V_2 - V_72 ) <<
V_5 . V_17 ;
}
static T_1 F_68 ( T_1 V_72 , int V_9 )
{
T_2 V_81 = ( T_2 ) V_50 << V_5 . V_9 ;
T_2 V_82 ;
if ( V_72 < V_5 . V_11 << V_9 )
return V_72 ;
V_72 -= V_5 . V_11 << V_9 ;
V_5 . clock -> V_6 += V_5 . V_11 << V_9 ;
V_5 . V_15 += V_5 . V_12 << V_9 ;
while ( V_5 . V_15 >= V_81 ) {
int V_83 ;
V_5 . V_15 -= V_81 ;
V_5 . V_29 . V_25 ++ ;
V_83 = F_69 ( V_5 . V_29 . V_25 ) ;
V_5 . V_29 . V_25 += V_83 ;
V_5 . V_24 . V_25 -= V_83 ;
if ( V_83 )
F_70 () ;
}
V_82 = V_5 . V_14 << V_9 ;
V_82 += V_5 . V_31 . V_26 ;
if ( V_82 >= V_50 ) {
T_2 V_84 = V_82 ;
V_82 = F_2 ( V_84 , V_50 ) ;
V_5 . V_31 . V_25 += V_84 ;
}
V_5 . V_31 . V_26 = V_82 ;
V_5 . V_16 += F_63 () << V_9 ;
V_5 . V_16 -=
( V_5 . V_12 + V_5 . V_13 ) <<
( V_5 . V_17 + V_9 ) ;
return V_72 ;
}
static void F_71 ( void )
{
struct V_1 * clock ;
T_1 V_72 ;
int V_9 = 0 , V_85 ;
unsigned long V_49 ;
F_27 ( & V_5 . V_36 , V_49 ) ;
if ( F_66 ( V_35 ) )
goto V_86;
clock = V_5 . clock ;
#ifdef F_72
V_72 = V_5 . V_11 ;
#else
V_72 = ( clock -> V_7 ( clock ) - clock -> V_6 ) & clock -> V_21 ;
#endif
V_5 . V_15 = ( T_3 ) V_5 . V_29 . V_26 <<
V_5 . V_9 ;
V_9 = F_73 ( V_72 ) - F_73 ( V_5 . V_11 ) ;
V_9 = F_74 ( 0 , V_9 ) ;
V_85 = ( 64 - ( F_73 ( F_63 () ) + 1 ) ) - 1 ;
V_9 = F_75 ( V_9 , V_85 ) ;
while ( V_72 >= V_5 . V_11 ) {
V_72 = F_68 ( V_72 , V_9 ) ;
if( V_72 < V_5 . V_11 << V_9 )
V_9 -- ;
}
F_64 ( V_72 ) ;
if ( F_66 ( ( T_3 ) V_5 . V_15 < 0 ) ) {
T_3 V_87 = - ( T_3 ) V_5 . V_15 ;
V_5 . V_15 = 0 ;
V_5 . V_16 += V_87 << V_5 . V_17 ;
}
V_5 . V_29 . V_26 = ( ( T_3 ) V_5 . V_15 >>
V_5 . V_9 ) + 1 ;
V_5 . V_15 -= ( T_3 ) V_5 . V_29 . V_26 <<
V_5 . V_9 ;
V_5 . V_16 += V_5 . V_15 <<
V_5 . V_17 ;
if ( F_66 ( V_5 . V_29 . V_26 >= V_50 ) ) {
int V_83 ;
V_5 . V_29 . V_26 -= V_50 ;
V_5 . V_29 . V_25 ++ ;
V_83 = F_69 ( V_5 . V_29 . V_25 ) ;
V_5 . V_29 . V_25 += V_83 ;
V_5 . V_24 . V_25 -= V_83 ;
if ( V_83 )
F_70 () ;
}
F_9 ( false ) ;
V_86:
F_29 ( & V_5 . V_36 , V_49 ) ;
}
void F_76 ( struct V_22 * V_32 )
{
struct V_22 V_88 = {
. V_25 = V_5 . V_24 . V_25 +
V_5 . V_61 . V_25 ,
. V_26 = V_5 . V_24 . V_26 +
V_5 . V_61 . V_26
} ;
F_7 ( V_32 , - V_88 . V_25 , - V_88 . V_26 ) ;
}
void F_77 ( struct V_22 * V_32 )
{
struct V_22 V_38 , V_89 ;
unsigned int V_33 ;
T_3 V_34 ;
F_16 ( V_35 ) ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
* V_32 = V_5 . V_29 ;
V_38 = V_5 . V_24 ;
V_89 = V_5 . V_61 ;
V_34 = F_3 () ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
F_7 ( V_32 , V_32 -> V_25 + V_38 . V_25 + V_89 . V_25 ,
V_32 -> V_26 + V_38 . V_26 + V_89 . V_26 + V_34 ) ;
}
T_4 F_78 ( void )
{
struct V_22 V_32 ;
F_77 ( & V_32 ) ;
return F_8 ( V_32 ) ;
}
void F_79 ( struct V_22 * V_32 )
{
* V_32 = F_32 ( * V_32 , V_5 . V_61 ) ;
}
unsigned long F_80 ( void )
{
return V_5 . V_29 . V_25 ;
}
struct V_22 F_81 ( void )
{
return V_5 . V_29 ;
}
struct V_22 F_82 ( void )
{
struct V_22 V_46 ;
unsigned long V_33 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_46 = V_5 . V_29 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
return V_46 ;
}
struct V_22 F_83 ( void )
{
struct V_22 V_46 , V_90 ;
unsigned long V_33 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_46 = V_5 . V_29 ;
V_90 = V_5 . V_24 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
F_7 ( & V_46 , V_46 . V_25 + V_90 . V_25 ,
V_46 . V_26 + V_90 . V_26 ) ;
return V_46 ;
}
void F_84 ( unsigned long V_91 )
{
V_92 += V_91 ;
F_71 () ;
F_85 ( V_91 ) ;
}
void F_86 ( struct V_22 * V_93 ,
struct V_22 * V_94 , struct V_22 * V_89 )
{
unsigned long V_33 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
* V_93 = V_5 . V_29 ;
* V_94 = V_5 . V_24 ;
* V_89 = V_5 . V_61 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
}
T_4 F_87 ( T_4 * V_27 , T_4 * V_63 )
{
T_4 V_46 ;
unsigned int V_33 ;
T_2 V_37 , V_34 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_37 = V_5 . V_29 . V_25 ;
V_34 = V_5 . V_29 . V_26 ;
V_34 += F_3 () ;
V_34 += F_13 () ;
* V_27 = V_5 . V_27 ;
* V_63 = V_5 . V_63 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
V_46 = F_20 ( F_21 ( V_37 , 0 ) , V_34 ) ;
V_46 = F_88 ( V_46 , * V_27 ) ;
return V_46 ;
}
T_4 F_89 ( void )
{
unsigned long V_33 ;
struct V_22 V_94 ;
do {
V_33 = F_17 ( & V_5 . V_36 ) ;
V_94 = V_5 . V_24 ;
} while ( F_18 ( & V_5 . V_36 , V_33 ) );
return F_8 ( V_94 ) ;
}
void F_90 ( unsigned long V_91 )
{
F_91 ( & V_95 ) ;
F_84 ( V_91 ) ;
F_92 ( & V_95 ) ;
}
