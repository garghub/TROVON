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
void F_6 ( int V_22 )
{
V_23 . V_24 += V_22 ;
V_25 . V_24 -= V_22 ;
F_7 ( & V_23 , & V_25 , V_5 . clock ,
V_5 . V_10 ) ;
}
static void F_8 ( void )
{
T_1 V_19 , V_20 ;
struct V_1 * clock ;
T_3 V_26 ;
clock = V_5 . clock ;
V_19 = clock -> V_7 ( clock ) ;
V_20 = ( V_19 - clock -> V_6 ) & clock -> V_21 ;
clock -> V_6 = V_19 ;
V_26 = F_4 ( V_20 , V_5 . V_10 ,
V_5 . V_9 ) ;
V_26 += F_9 () ;
F_10 ( & V_23 , V_26 ) ;
V_26 = F_4 ( V_20 , clock -> V_10 , clock -> V_9 ) ;
F_10 ( & V_27 , V_26 ) ;
}
void F_11 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
T_3 V_31 ;
F_12 ( V_32 ) ;
do {
V_30 = F_13 ( & V_33 ) ;
* V_29 = V_23 ;
V_31 = F_3 () ;
V_31 += F_9 () ;
} while ( F_14 ( & V_33 , V_30 ) );
F_10 ( V_29 , V_31 ) ;
}
T_4 F_15 ( void )
{
unsigned int V_30 ;
T_3 V_34 , V_31 ;
F_12 ( V_32 ) ;
do {
V_30 = F_13 ( & V_33 ) ;
V_34 = V_23 . V_24 + V_25 . V_24 ;
V_31 = V_23 . V_35 + V_25 . V_35 ;
V_31 += F_3 () ;
} while ( F_14 ( & V_33 , V_30 ) );
return F_16 ( F_17 ( V_34 , 0 ) , V_31 ) ;
}
void F_18 ( struct V_28 * V_29 )
{
struct V_28 V_36 ;
unsigned int V_30 ;
T_3 V_31 ;
F_12 ( V_32 ) ;
do {
V_30 = F_13 ( & V_33 ) ;
* V_29 = V_23 ;
V_36 = V_25 ;
V_31 = F_3 () ;
} while ( F_14 ( & V_33 , V_30 ) );
F_19 ( V_29 , V_29 -> V_24 + V_36 . V_24 ,
V_29 -> V_35 + V_36 . V_35 + V_31 ) ;
}
void F_20 ( struct V_28 * V_37 , struct V_28 * V_38 )
{
unsigned long V_30 ;
T_3 V_39 , V_40 ;
F_21 ( V_32 ) ;
do {
T_5 V_41 ;
V_30 = F_13 ( & V_33 ) ;
* V_37 = V_27 ;
* V_38 = V_23 ;
V_39 = F_5 () ;
V_40 = F_3 () ;
V_41 = F_9 () ;
V_39 += V_41 ;
V_40 += V_41 ;
} while ( F_14 ( & V_33 , V_30 ) );
F_10 ( V_37 , V_39 ) ;
F_10 ( V_38 , V_40 ) ;
}
void F_22 ( struct V_42 * V_43 )
{
struct V_28 V_44 ;
F_11 ( & V_44 ) ;
V_43 -> V_24 = V_44 . V_24 ;
V_43 -> V_45 = V_44 . V_35 / 1000 ;
}
int F_23 ( const struct V_28 * V_43 )
{
struct V_28 V_46 ;
unsigned long V_47 ;
if ( ( unsigned long ) V_43 -> V_35 >= V_48 )
return - V_49 ;
F_24 ( & V_33 , V_47 ) ;
F_8 () ;
V_46 . V_24 = V_43 -> V_24 - V_23 . V_24 ;
V_46 . V_35 = V_43 -> V_35 - V_23 . V_35 ;
V_25 = F_25 ( V_25 , V_46 ) ;
V_23 = * V_43 ;
V_5 . V_16 = 0 ;
F_26 () ;
F_7 ( & V_23 , & V_25 , V_5 . clock ,
V_5 . V_10 ) ;
F_27 ( & V_33 , V_47 ) ;
F_28 () ;
return 0 ;
}
int F_29 ( struct V_28 * V_29 )
{
unsigned long V_47 ;
if ( ( unsigned long ) V_29 -> V_35 >= V_48 )
return - V_49 ;
F_24 ( & V_33 , V_47 ) ;
F_8 () ;
V_23 = F_30 ( V_23 , * V_29 ) ;
V_25 = F_25 ( V_25 , * V_29 ) ;
V_5 . V_16 = 0 ;
F_26 () ;
F_7 ( & V_23 , & V_25 , V_5 . clock ,
V_5 . V_10 ) ;
F_27 ( & V_33 , V_47 ) ;
F_28 () ;
return 0 ;
}
static int F_31 ( void * V_50 )
{
struct V_1 * V_51 , * V_52 ;
V_51 = (struct V_1 * ) V_50 ;
F_8 () ;
if ( ! V_51 -> V_53 || V_51 -> V_53 ( V_51 ) == 0 ) {
V_52 = V_5 . clock ;
F_1 ( V_51 ) ;
if ( V_52 -> V_54 )
V_52 -> V_54 ( V_52 ) ;
}
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
struct V_28 V_44 ;
F_11 ( & V_44 ) ;
return F_36 ( V_44 ) ;
}
void F_37 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
T_3 V_31 ;
do {
V_30 = F_13 ( & V_33 ) ;
V_31 = F_5 () ;
* V_29 = V_27 ;
} while ( F_14 ( & V_33 , V_30 ) );
F_10 ( V_29 , V_31 ) ;
}
int F_38 ( void )
{
unsigned long V_30 ;
int V_55 ;
do {
V_30 = F_13 ( & V_33 ) ;
V_55 = V_5 . clock -> V_47 & V_56 ;
} while ( F_14 ( & V_33 , V_30 ) );
return V_55 ;
}
T_2 F_39 ( void )
{
return V_5 . clock -> V_57 ;
}
void T_6 F_40 ( void )
{
struct V_1 * clock ;
unsigned long V_47 ;
struct V_28 V_44 , V_58 ;
F_41 ( & V_44 ) ;
F_42 ( & V_58 ) ;
F_24 ( & V_33 , V_47 ) ;
F_43 () ;
clock = F_44 () ;
if ( clock -> V_53 )
clock -> V_53 ( clock ) ;
F_1 ( clock ) ;
V_23 . V_24 = V_44 . V_24 ;
V_23 . V_35 = V_44 . V_35 ;
V_27 . V_24 = 0 ;
V_27 . V_35 = 0 ;
if ( V_58 . V_24 == 0 && V_58 . V_35 == 0 ) {
V_58 . V_24 = V_23 . V_24 ;
V_58 . V_35 = V_23 . V_35 ;
}
F_19 ( & V_25 ,
- V_58 . V_24 , - V_58 . V_35 ) ;
V_59 . V_24 = 0 ;
V_59 . V_35 = 0 ;
F_27 ( & V_33 , V_47 ) ;
}
static void F_45 ( struct V_28 * V_60 )
{
if ( ! F_46 ( V_60 ) ) {
F_47 ( V_61 L_1
L_2 ) ;
return;
}
V_23 = F_30 ( V_23 , * V_60 ) ;
V_25 = F_25 ( V_25 , * V_60 ) ;
V_59 = F_30 ( V_59 , * V_60 ) ;
}
void F_48 ( struct V_28 * V_60 )
{
unsigned long V_47 ;
struct V_28 V_29 ;
F_41 ( & V_29 ) ;
if ( ! ( V_29 . V_24 == 0 && V_29 . V_35 == 0 ) )
return;
F_24 ( & V_33 , V_47 ) ;
F_8 () ;
F_45 ( V_60 ) ;
V_5 . V_16 = 0 ;
F_26 () ;
F_7 ( & V_23 , & V_25 , V_5 . clock ,
V_5 . V_10 ) ;
F_27 ( & V_33 , V_47 ) ;
F_28 () ;
}
static void F_49 ( void )
{
unsigned long V_47 ;
struct V_28 V_29 ;
F_41 ( & V_29 ) ;
F_50 () ;
F_24 ( & V_33 , V_47 ) ;
if ( F_51 ( & V_29 , & V_62 ) > 0 ) {
V_29 = F_25 ( V_29 , V_62 ) ;
F_45 ( & V_29 ) ;
}
V_5 . clock -> V_6 = V_5 . clock -> V_7 ( V_5 . clock ) ;
V_5 . V_16 = 0 ;
V_32 = 0 ;
F_27 ( & V_33 , V_47 ) ;
F_52 () ;
F_53 ( V_63 , NULL ) ;
F_54 () ;
}
static int F_55 ( void )
{
unsigned long V_47 ;
struct V_28 V_60 , V_64 ;
static struct V_28 V_65 ;
F_41 ( & V_62 ) ;
F_24 ( & V_33 , V_47 ) ;
F_8 () ;
V_32 = 1 ;
V_60 = F_25 ( V_23 , V_62 ) ;
V_64 = F_25 ( V_60 , V_65 ) ;
if ( abs ( V_64 . V_24 ) >= 2 ) {
V_65 = V_60 ;
} else {
V_62 =
F_30 ( V_62 , V_64 ) ;
}
F_27 ( & V_33 , V_47 ) ;
F_53 ( V_66 , NULL ) ;
F_56 () ;
return 0 ;
}
static int T_6 F_57 ( void )
{
F_58 ( & V_67 ) ;
return 0 ;
}
static T_7 int F_59 ( T_3 error , T_3 * V_2 ,
T_3 * V_68 )
{
T_3 V_69 , V_70 ;
T_5 V_71 , V_72 ;
T_8 V_73 , V_10 ;
V_73 = V_5 . V_16 >> ( V_18 + 22 - 2 * V_74 ) ;
V_73 = abs ( V_73 ) ;
for ( V_71 = 0 ; V_73 > 0 ; V_71 ++ )
V_73 >>= 2 ;
V_69 = V_75 >> ( V_5 . V_17 + 1 ) ;
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
static void F_60 ( T_3 V_68 )
{
T_3 error , V_2 = V_5 . V_11 ;
int V_72 ;
error = V_5 . V_16 >> ( V_5 . V_17 - 1 ) ;
if ( error > V_2 ) {
error >>= 2 ;
if ( F_61 ( error <= V_2 ) )
V_72 = 1 ;
else
V_72 = F_59 ( error , & V_2 , & V_68 ) ;
} else if ( error < - V_2 ) {
error >>= 2 ;
if ( F_61 ( error >= - V_2 ) ) {
V_72 = - 1 ;
V_2 = - V_2 ;
V_68 = - V_68 ;
} else
V_72 = F_59 ( error , & V_2 , & V_68 ) ;
} else
return;
V_5 . V_10 += V_72 ;
V_5 . V_12 += V_2 ;
V_5 . V_15 -= V_68 ;
V_5 . V_16 -= ( V_2 - V_68 ) <<
V_5 . V_17 ;
}
static T_1 F_62 ( T_1 V_68 , int V_9 )
{
T_2 V_76 = ( T_2 ) V_48 << V_5 . V_9 ;
T_2 V_77 ;
if ( V_68 < V_5 . V_11 << V_9 )
return V_68 ;
V_68 -= V_5 . V_11 << V_9 ;
V_5 . clock -> V_6 += V_5 . V_11 << V_9 ;
V_5 . V_15 += V_5 . V_12 << V_9 ;
while ( V_5 . V_15 >= V_76 ) {
V_5 . V_15 -= V_76 ;
V_23 . V_24 ++ ;
F_63 () ;
}
V_77 = V_5 . V_14 << V_9 ;
V_77 += V_27 . V_35 ;
if ( V_77 >= V_48 ) {
T_2 V_78 = V_77 ;
V_77 = F_2 ( V_78 , V_48 ) ;
V_27 . V_24 += V_78 ;
}
V_27 . V_35 = V_77 ;
V_5 . V_16 += V_75 << V_9 ;
V_5 . V_16 -=
( V_5 . V_12 + V_5 . V_13 ) <<
( V_5 . V_17 + V_9 ) ;
return V_68 ;
}
static void F_64 ( void )
{
struct V_1 * clock ;
T_1 V_68 ;
int V_9 = 0 , V_79 ;
if ( F_65 ( V_32 ) )
return;
clock = V_5 . clock ;
#ifdef F_66
V_68 = V_5 . V_11 ;
#else
V_68 = ( clock -> V_7 ( clock ) - clock -> V_6 ) & clock -> V_21 ;
#endif
V_5 . V_15 = ( T_3 ) V_23 . V_35 << V_5 . V_9 ;
V_9 = F_67 ( V_68 ) - F_67 ( V_5 . V_11 ) ;
V_9 = F_68 ( 0 , V_9 ) ;
V_79 = ( 8 * sizeof( V_75 ) - ( F_67 ( V_75 ) + 1 ) ) - 1 ;
V_9 = F_69 ( V_9 , V_79 ) ;
while ( V_68 >= V_5 . V_11 ) {
V_68 = F_62 ( V_68 , V_9 ) ;
if( V_68 < V_5 . V_11 << V_9 )
V_9 -- ;
}
F_60 ( V_68 ) ;
if ( F_65 ( ( T_3 ) V_5 . V_15 < 0 ) ) {
T_3 V_80 = - ( T_3 ) V_5 . V_15 ;
V_5 . V_15 = 0 ;
V_5 . V_16 += V_80 << V_5 . V_17 ;
}
V_23 . V_35 = ( ( T_3 ) V_5 . V_15 >> V_5 . V_9 ) + 1 ;
V_5 . V_15 -= ( T_3 ) V_23 . V_35 << V_5 . V_9 ;
V_5 . V_16 += V_5 . V_15 <<
V_5 . V_17 ;
if ( F_65 ( V_23 . V_35 >= V_48 ) ) {
V_23 . V_35 -= V_48 ;
V_23 . V_24 ++ ;
F_63 () ;
}
F_7 ( & V_23 , & V_25 , V_5 . clock ,
V_5 . V_10 ) ;
}
void F_70 ( struct V_28 * V_29 )
{
struct V_28 V_81 = {
. V_24 = V_25 . V_24 + V_59 . V_24 ,
. V_35 = V_25 . V_35 + V_59 . V_35
} ;
F_19 ( V_29 , - V_81 . V_24 , - V_81 . V_35 ) ;
}
void F_71 ( struct V_28 * V_29 )
{
struct V_28 V_36 , V_82 ;
unsigned int V_30 ;
T_3 V_31 ;
F_12 ( V_32 ) ;
do {
V_30 = F_13 ( & V_33 ) ;
* V_29 = V_23 ;
V_36 = V_25 ;
V_82 = V_59 ;
V_31 = F_3 () ;
} while ( F_14 ( & V_33 , V_30 ) );
F_19 ( V_29 , V_29 -> V_24 + V_36 . V_24 + V_82 . V_24 ,
V_29 -> V_35 + V_36 . V_35 + V_82 . V_35 + V_31 ) ;
}
T_4 F_72 ( void )
{
struct V_28 V_29 ;
F_71 ( & V_29 ) ;
return F_36 ( V_29 ) ;
}
void F_73 ( struct V_28 * V_29 )
{
* V_29 = F_30 ( * V_29 , V_59 ) ;
}
unsigned long F_74 ( void )
{
return V_23 . V_24 ;
}
struct V_28 F_75 ( void )
{
return V_23 ;
}
struct V_28 F_76 ( void )
{
struct V_28 V_44 ;
unsigned long V_30 ;
do {
V_30 = F_13 ( & V_33 ) ;
V_44 = V_23 ;
} while ( F_14 ( & V_33 , V_30 ) );
return V_44 ;
}
struct V_28 F_77 ( void )
{
struct V_28 V_44 , V_83 ;
unsigned long V_30 ;
do {
V_30 = F_13 ( & V_33 ) ;
V_44 = V_23 ;
V_83 = V_25 ;
} while ( F_14 ( & V_33 , V_30 ) );
F_19 ( & V_44 , V_44 . V_24 + V_83 . V_24 ,
V_44 . V_35 + V_83 . V_35 ) ;
return V_44 ;
}
void F_78 ( unsigned long V_84 )
{
V_85 += V_84 ;
F_64 () ;
F_79 ( V_84 ) ;
}
void F_80 ( struct V_28 * V_86 ,
struct V_28 * V_87 , struct V_28 * V_82 )
{
unsigned long V_30 ;
do {
V_30 = F_13 ( & V_33 ) ;
* V_86 = V_23 ;
* V_87 = V_25 ;
* V_82 = V_59 ;
} while ( F_14 ( & V_33 , V_30 ) );
}
T_4 F_81 ( void )
{
unsigned long V_30 ;
struct V_28 V_87 ;
do {
V_30 = F_13 ( & V_33 ) ;
V_87 = V_25 ;
} while ( F_14 ( & V_33 , V_30 ) );
return F_36 ( V_87 ) ;
}
void F_82 ( unsigned long V_84 )
{
F_83 ( & V_33 ) ;
F_78 ( V_84 ) ;
F_84 ( & V_33 ) ;
}
