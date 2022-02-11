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
static void F_6 ( bool V_22 )
{
if ( V_22 ) {
V_5 . V_16 = 0 ;
F_7 () ;
}
F_8 ( & V_5 . V_23 , & V_5 . V_24 ,
V_5 . clock , V_5 . V_10 ) ;
}
static void F_9 ( void )
{
T_1 V_19 , V_20 ;
struct V_1 * clock ;
T_3 V_25 ;
clock = V_5 . clock ;
V_19 = clock -> V_7 ( clock ) ;
V_20 = ( V_19 - clock -> V_6 ) & clock -> V_21 ;
clock -> V_6 = V_19 ;
V_25 = F_4 ( V_20 , V_5 . V_10 ,
V_5 . V_9 ) ;
V_25 += F_10 () ;
F_11 ( & V_5 . V_23 , V_25 ) ;
V_25 = F_4 ( V_20 , clock -> V_10 , clock -> V_9 ) ;
F_11 ( & V_5 . V_26 , V_25 ) ;
}
void F_12 ( struct V_27 * V_28 )
{
unsigned long V_29 ;
T_3 V_30 ;
F_13 ( V_31 ) ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
* V_28 = V_5 . V_23 ;
V_30 = F_3 () ;
V_30 += F_10 () ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
F_11 ( V_28 , V_30 ) ;
}
T_4 F_16 ( void )
{
unsigned int V_29 ;
T_3 V_33 , V_30 ;
F_13 ( V_31 ) ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_33 = V_5 . V_23 . V_34 +
V_5 . V_24 . V_34 ;
V_30 = V_5 . V_23 . V_35 +
V_5 . V_24 . V_35 ;
V_30 += F_3 () ;
V_30 += F_10 () ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
return F_17 ( F_18 ( V_33 , 0 ) , V_30 ) ;
}
void F_19 ( struct V_27 * V_28 )
{
struct V_27 V_36 ;
unsigned int V_29 ;
T_3 V_30 ;
F_13 ( V_31 ) ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
* V_28 = V_5 . V_23 ;
V_36 = V_5 . V_24 ;
V_30 = F_3 () ;
V_30 += F_10 () ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
F_20 ( V_28 , V_28 -> V_34 + V_36 . V_34 ,
V_28 -> V_35 + V_36 . V_35 + V_30 ) ;
}
void F_21 ( struct V_27 * V_37 , struct V_27 * V_38 )
{
unsigned long V_29 ;
T_3 V_39 , V_40 ;
F_22 ( V_31 ) ;
do {
T_5 V_41 ;
V_29 = F_14 ( & V_5 . V_32 ) ;
* V_37 = V_5 . V_26 ;
* V_38 = V_5 . V_23 ;
V_39 = F_5 () ;
V_40 = F_3 () ;
V_41 = F_10 () ;
V_39 += V_41 ;
V_40 += V_41 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
F_11 ( V_37 , V_39 ) ;
F_11 ( V_38 , V_40 ) ;
}
void F_23 ( struct V_42 * V_43 )
{
struct V_27 V_44 ;
F_12 ( & V_44 ) ;
V_43 -> V_34 = V_44 . V_34 ;
V_43 -> V_45 = V_44 . V_35 / 1000 ;
}
int F_24 ( const struct V_27 * V_43 )
{
struct V_27 V_46 ;
unsigned long V_47 ;
if ( ( unsigned long ) V_43 -> V_35 >= V_48 )
return - V_49 ;
F_25 ( & V_5 . V_32 , V_47 ) ;
F_9 () ;
V_46 . V_34 = V_43 -> V_34 - V_5 . V_23 . V_34 ;
V_46 . V_35 = V_43 -> V_35 - V_5 . V_23 . V_35 ;
V_5 . V_24 =
F_26 ( V_5 . V_24 , V_46 ) ;
V_5 . V_23 = * V_43 ;
F_6 ( true ) ;
F_27 ( & V_5 . V_32 , V_47 ) ;
F_28 () ;
return 0 ;
}
int F_29 ( struct V_27 * V_28 )
{
unsigned long V_47 ;
if ( ( unsigned long ) V_28 -> V_35 >= V_48 )
return - V_49 ;
F_25 ( & V_5 . V_32 , V_47 ) ;
F_9 () ;
V_5 . V_23 = F_30 ( V_5 . V_23 , * V_28 ) ;
V_5 . V_24 =
F_26 ( V_5 . V_24 , * V_28 ) ;
F_6 ( true ) ;
F_27 ( & V_5 . V_32 , V_47 ) ;
F_28 () ;
return 0 ;
}
static int F_31 ( void * V_50 )
{
struct V_1 * V_51 , * V_52 ;
unsigned long V_47 ;
V_51 = (struct V_1 * ) V_50 ;
F_25 ( & V_5 . V_32 , V_47 ) ;
F_9 () ;
if ( ! V_51 -> V_53 || V_51 -> V_53 ( V_51 ) == 0 ) {
V_52 = V_5 . clock ;
F_1 ( V_51 ) ;
if ( V_52 -> V_54 )
V_52 -> V_54 ( V_52 ) ;
}
F_6 ( true ) ;
F_27 ( & V_5 . V_32 , V_47 ) ;
return 0 ;
}
void F_32 ( struct V_1 * clock )
{
if ( V_5 . clock == clock )
return;
F_33 ( F_31 , clock , NULL ) ;
F_34 () ;
}
T_4 F_35 ( void )
{
struct V_27 V_44 ;
F_12 ( & V_44 ) ;
return F_36 ( V_44 ) ;
}
void F_37 ( struct V_27 * V_28 )
{
unsigned long V_29 ;
T_3 V_30 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_30 = F_5 () ;
* V_28 = V_5 . V_26 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
F_11 ( V_28 , V_30 ) ;
}
int F_38 ( void )
{
unsigned long V_29 ;
int V_55 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_55 = V_5 . clock -> V_47 & V_56 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
return V_55 ;
}
T_2 F_39 ( void )
{
unsigned long V_29 ;
T_2 V_55 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_55 = V_5 . clock -> V_57 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
return V_55 ;
}
void T_6 F_40 ( void )
{
struct V_1 * clock ;
unsigned long V_47 ;
struct V_27 V_44 , V_58 ;
F_41 ( & V_44 ) ;
F_42 ( & V_58 ) ;
F_43 ( & V_5 . V_32 ) ;
F_44 () ;
F_25 ( & V_5 . V_32 , V_47 ) ;
clock = F_45 () ;
if ( clock -> V_53 )
clock -> V_53 ( clock ) ;
F_1 ( clock ) ;
V_5 . V_23 . V_34 = V_44 . V_34 ;
V_5 . V_23 . V_35 = V_44 . V_35 ;
V_5 . V_26 . V_34 = 0 ;
V_5 . V_26 . V_35 = 0 ;
if ( V_58 . V_34 == 0 && V_58 . V_35 == 0 ) {
V_58 . V_34 = V_5 . V_23 . V_34 ;
V_58 . V_35 = V_5 . V_23 . V_35 ;
}
F_20 ( & V_5 . V_24 ,
- V_58 . V_34 , - V_58 . V_35 ) ;
V_5 . V_59 . V_34 = 0 ;
V_5 . V_59 . V_35 = 0 ;
F_27 ( & V_5 . V_32 , V_47 ) ;
}
static void F_46 ( struct V_27 * V_60 )
{
if ( ! F_47 ( V_60 ) ) {
F_48 ( V_61 L_1
L_2 ) ;
return;
}
V_5 . V_23 = F_30 ( V_5 . V_23 , * V_60 ) ;
V_5 . V_24 =
F_26 ( V_5 . V_24 , * V_60 ) ;
V_5 . V_59 = F_30 (
V_5 . V_59 , * V_60 ) ;
}
void F_49 ( struct V_27 * V_60 )
{
unsigned long V_47 ;
struct V_27 V_28 ;
F_41 ( & V_28 ) ;
if ( ! ( V_28 . V_34 == 0 && V_28 . V_35 == 0 ) )
return;
F_25 ( & V_5 . V_32 , V_47 ) ;
F_9 () ;
F_46 ( V_60 ) ;
F_6 ( true ) ;
F_27 ( & V_5 . V_32 , V_47 ) ;
F_28 () ;
}
static void F_50 ( void )
{
unsigned long V_47 ;
struct V_27 V_28 ;
F_41 ( & V_28 ) ;
F_51 () ;
F_25 ( & V_5 . V_32 , V_47 ) ;
if ( F_52 ( & V_28 , & V_62 ) > 0 ) {
V_28 = F_26 ( V_28 , V_62 ) ;
F_46 ( & V_28 ) ;
}
V_5 . clock -> V_6 = V_5 . clock -> V_7 ( V_5 . clock ) ;
V_5 . V_16 = 0 ;
V_31 = 0 ;
F_27 ( & V_5 . V_32 , V_47 ) ;
F_53 () ;
F_54 ( V_63 , NULL ) ;
F_55 () ;
}
static int F_56 ( void )
{
unsigned long V_47 ;
struct V_27 V_60 , V_64 ;
static struct V_27 V_65 ;
F_41 ( & V_62 ) ;
F_25 ( & V_5 . V_32 , V_47 ) ;
F_9 () ;
V_31 = 1 ;
V_60 = F_26 ( V_5 . V_23 , V_62 ) ;
V_64 = F_26 ( V_60 , V_65 ) ;
if ( abs ( V_64 . V_34 ) >= 2 ) {
V_65 = V_60 ;
} else {
V_62 =
F_30 ( V_62 , V_64 ) ;
}
F_27 ( & V_5 . V_32 , V_47 ) ;
F_54 ( V_66 , NULL ) ;
F_57 () ;
return 0 ;
}
static int T_6 F_58 ( void )
{
F_59 ( & V_67 ) ;
return 0 ;
}
static T_7 int F_60 ( T_3 error , T_3 * V_2 ,
T_3 * V_68 )
{
T_3 V_69 , V_70 ;
T_5 V_71 , V_72 ;
T_8 V_73 , V_10 ;
V_73 = V_5 . V_16 >> ( V_18 + 22 - 2 * V_74 ) ;
V_73 = abs ( V_73 ) ;
for ( V_71 = 0 ; V_73 > 0 ; V_71 ++ )
V_73 >>= 2 ;
V_69 = F_61 () >> ( V_5 . V_17 + 1 ) ;
V_69 -= V_5 . V_12 >> 1 ;
error = ( ( error - V_69 ) >> V_71 ) + V_69 ;
V_70 = * V_2 ;
V_10 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_2 = - * V_2 ;
* V_68 = - * V_68 ;
V_10 = - 1 ;
}
for ( V_72 = 0 ; error > V_70 ; V_72 ++ )
error >>= 1 ;
* V_2 <<= V_72 ;
* V_68 <<= V_72 ;
return V_10 << V_72 ;
}
static void F_62 ( T_3 V_68 )
{
T_3 error , V_2 = V_5 . V_11 ;
int V_72 ;
error = V_5 . V_16 >> ( V_5 . V_17 - 1 ) ;
if ( error > V_2 ) {
error >>= 2 ;
if ( F_63 ( error <= V_2 ) )
V_72 = 1 ;
else
V_72 = F_60 ( error , & V_2 , & V_68 ) ;
} else if ( error < - V_2 ) {
error >>= 2 ;
if ( F_63 ( error >= - V_2 ) ) {
V_72 = - 1 ;
V_2 = - V_2 ;
V_68 = - V_68 ;
} else
V_72 = F_60 ( error , & V_2 , & V_68 ) ;
} else
return;
if ( F_64 ( V_5 . clock -> V_75 &&
( V_5 . V_10 + V_72 >
V_5 . clock -> V_10 + V_5 . clock -> V_75 ) ) ) {
F_65 ( V_61
L_3 ,
V_5 . clock -> V_76 , ( long ) V_5 . V_10 + V_72 ,
( long ) V_5 . clock -> V_10 +
V_5 . clock -> V_75 ) ;
}
V_5 . V_10 += V_72 ;
V_5 . V_12 += V_2 ;
V_5 . V_15 -= V_68 ;
V_5 . V_16 -= ( V_2 - V_68 ) <<
V_5 . V_17 ;
}
static T_1 F_66 ( T_1 V_68 , int V_9 )
{
T_2 V_77 = ( T_2 ) V_48 << V_5 . V_9 ;
T_2 V_78 ;
if ( V_68 < V_5 . V_11 << V_9 )
return V_68 ;
V_68 -= V_5 . V_11 << V_9 ;
V_5 . clock -> V_6 += V_5 . V_11 << V_9 ;
V_5 . V_15 += V_5 . V_12 << V_9 ;
while ( V_5 . V_15 >= V_77 ) {
int V_79 ;
V_5 . V_15 -= V_77 ;
V_5 . V_23 . V_34 ++ ;
V_79 = F_67 ( V_5 . V_23 . V_34 ) ;
V_5 . V_23 . V_34 += V_79 ;
}
V_78 = V_5 . V_14 << V_9 ;
V_78 += V_5 . V_26 . V_35 ;
if ( V_78 >= V_48 ) {
T_2 V_80 = V_78 ;
V_78 = F_2 ( V_80 , V_48 ) ;
V_5 . V_26 . V_34 += V_80 ;
}
V_5 . V_26 . V_35 = V_78 ;
V_5 . V_16 += F_61 () << V_9 ;
V_5 . V_16 -=
( V_5 . V_12 + V_5 . V_13 ) <<
( V_5 . V_17 + V_9 ) ;
return V_68 ;
}
static void F_68 ( void )
{
struct V_1 * clock ;
T_1 V_68 ;
int V_9 = 0 , V_81 ;
unsigned long V_47 ;
F_25 ( & V_5 . V_32 , V_47 ) ;
if ( F_64 ( V_31 ) )
goto V_82;
clock = V_5 . clock ;
#ifdef F_69
V_68 = V_5 . V_11 ;
#else
V_68 = ( clock -> V_7 ( clock ) - clock -> V_6 ) & clock -> V_21 ;
#endif
V_5 . V_15 = ( T_3 ) V_5 . V_23 . V_35 <<
V_5 . V_9 ;
V_9 = F_70 ( V_68 ) - F_70 ( V_5 . V_11 ) ;
V_9 = F_71 ( 0 , V_9 ) ;
V_81 = ( 64 - ( F_70 ( F_61 () ) + 1 ) ) - 1 ;
V_9 = F_72 ( V_9 , V_81 ) ;
while ( V_68 >= V_5 . V_11 ) {
V_68 = F_66 ( V_68 , V_9 ) ;
if( V_68 < V_5 . V_11 << V_9 )
V_9 -- ;
}
F_62 ( V_68 ) ;
if ( F_64 ( ( T_3 ) V_5 . V_15 < 0 ) ) {
T_3 V_83 = - ( T_3 ) V_5 . V_15 ;
V_5 . V_15 = 0 ;
V_5 . V_16 += V_83 << V_5 . V_17 ;
}
V_5 . V_23 . V_35 = ( ( T_3 ) V_5 . V_15 >>
V_5 . V_9 ) + 1 ;
V_5 . V_15 -= ( T_3 ) V_5 . V_23 . V_35 <<
V_5 . V_9 ;
V_5 . V_16 += V_5 . V_15 <<
V_5 . V_17 ;
if ( F_64 ( V_5 . V_23 . V_35 >= V_48 ) ) {
int V_79 ;
V_5 . V_23 . V_35 -= V_48 ;
V_5 . V_23 . V_34 ++ ;
V_79 = F_67 ( V_5 . V_23 . V_34 ) ;
V_5 . V_23 . V_34 += V_79 ;
}
F_6 ( false ) ;
V_82:
F_27 ( & V_5 . V_32 , V_47 ) ;
}
void F_73 ( struct V_27 * V_28 )
{
struct V_27 V_84 = {
. V_34 = V_5 . V_24 . V_34 +
V_5 . V_59 . V_34 ,
. V_35 = V_5 . V_24 . V_35 +
V_5 . V_59 . V_35
} ;
F_20 ( V_28 , - V_84 . V_34 , - V_84 . V_35 ) ;
}
void F_74 ( struct V_27 * V_28 )
{
struct V_27 V_36 , V_85 ;
unsigned int V_29 ;
T_3 V_30 ;
F_13 ( V_31 ) ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
* V_28 = V_5 . V_23 ;
V_36 = V_5 . V_24 ;
V_85 = V_5 . V_59 ;
V_30 = F_3 () ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
F_20 ( V_28 , V_28 -> V_34 + V_36 . V_34 + V_85 . V_34 ,
V_28 -> V_35 + V_36 . V_35 + V_85 . V_35 + V_30 ) ;
}
T_4 F_75 ( void )
{
struct V_27 V_28 ;
F_74 ( & V_28 ) ;
return F_36 ( V_28 ) ;
}
void F_76 ( struct V_27 * V_28 )
{
* V_28 = F_30 ( * V_28 , V_5 . V_59 ) ;
}
unsigned long F_77 ( void )
{
return V_5 . V_23 . V_34 ;
}
struct V_27 F_78 ( void )
{
return V_5 . V_23 ;
}
struct V_27 F_79 ( void )
{
struct V_27 V_44 ;
unsigned long V_29 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_44 = V_5 . V_23 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
return V_44 ;
}
struct V_27 F_80 ( void )
{
struct V_27 V_44 , V_86 ;
unsigned long V_29 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_44 = V_5 . V_23 ;
V_86 = V_5 . V_24 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
F_20 ( & V_44 , V_44 . V_34 + V_86 . V_34 ,
V_44 . V_35 + V_86 . V_35 ) ;
return V_44 ;
}
void F_81 ( unsigned long V_87 )
{
V_88 += V_87 ;
F_68 () ;
F_82 ( V_87 ) ;
}
void F_83 ( struct V_27 * V_89 ,
struct V_27 * V_90 , struct V_27 * V_85 )
{
unsigned long V_29 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
* V_89 = V_5 . V_23 ;
* V_90 = V_5 . V_24 ;
* V_85 = V_5 . V_59 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
}
T_4 F_84 ( void )
{
unsigned long V_29 ;
struct V_27 V_90 ;
do {
V_29 = F_14 ( & V_5 . V_32 ) ;
V_90 = V_5 . V_24 ;
} while ( F_15 ( & V_5 . V_32 , V_29 ) );
return F_36 ( V_90 ) ;
}
void F_85 ( unsigned long V_87 )
{
F_86 ( & V_91 ) ;
F_81 ( V_87 ) ;
F_87 ( & V_91 ) ;
}
