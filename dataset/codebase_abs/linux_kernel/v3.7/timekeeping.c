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
static void F_15 ( struct V_1 * V_2 , bool V_40 )
{
if ( V_40 ) {
V_2 -> V_33 = 0 ;
F_16 () ;
}
F_17 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
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
F_19 ( & V_2 -> V_41 , V_38 ) ;
}
void F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
T_2 V_43 = 0 ;
F_21 ( V_44 ) ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_43 = F_11 ( V_2 ) ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
V_9 -> V_11 = 0 ;
F_19 ( V_9 , V_43 ) ;
}
T_3 F_24 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_42 ;
T_2 V_46 , V_43 ;
F_21 ( V_44 ) ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_46 = V_2 -> V_7 + V_2 -> V_14 . V_10 ;
V_43 = F_11 ( V_2 ) + V_2 -> V_14 . V_11 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
return F_25 ( F_26 ( V_46 , 0 ) , V_43 ) ;
}
void F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_47 ;
T_2 V_38 ;
unsigned int V_42 ;
F_21 ( V_44 ) ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_38 = F_11 ( V_2 ) ;
V_47 = V_2 -> V_14 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
V_9 -> V_10 += V_47 . V_10 ;
V_9 -> V_11 = 0 ;
F_19 ( V_9 , V_38 + V_47 . V_11 ) ;
}
void F_28 ( struct V_8 * V_48 , struct V_8 * V_49 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
T_2 V_50 , V_51 ;
F_6 ( V_44 ) ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
* V_48 = V_2 -> V_41 ;
V_49 -> V_10 = V_2 -> V_7 ;
V_49 -> V_11 = 0 ;
V_50 = F_13 ( V_2 ) ;
V_51 = F_11 ( V_2 ) ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
F_19 ( V_48 , V_50 ) ;
F_19 ( V_49 , V_51 ) ;
}
void F_29 ( struct V_52 * V_53 )
{
struct V_8 V_54 ;
F_20 ( & V_54 ) ;
V_53 -> V_10 = V_54 . V_10 ;
V_53 -> V_55 = V_54 . V_11 / 1000 ;
}
int F_30 ( const struct V_8 * V_53 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_56 , V_57 ;
unsigned long V_58 ;
if ( ! F_31 ( V_53 ) )
return - V_59 ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
F_18 ( V_2 ) ;
V_57 = F_33 ( V_2 ) ;
V_56 . V_10 = V_53 -> V_10 - V_57 . V_10 ;
V_56 . V_11 = V_53 -> V_11 - V_57 . V_11 ;
F_4 ( V_2 , F_34 ( V_2 -> V_14 , V_56 ) ) ;
F_2 ( V_2 , V_53 ) ;
F_15 ( V_2 , true ) ;
F_35 ( & V_2 -> V_45 , V_58 ) ;
F_36 () ;
return 0 ;
}
int F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_13 ;
int V_60 = 0 ;
if ( ( unsigned long ) V_9 -> V_11 >= V_5 )
return - V_59 ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
F_18 ( V_2 ) ;
V_13 = F_38 ( F_33 ( V_2 ) , * V_9 ) ;
if ( ! F_31 ( & V_13 ) ) {
V_60 = - V_59 ;
goto error;
}
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 , F_34 ( V_2 -> V_14 , * V_9 ) ) ;
error:
F_15 ( V_2 , true ) ;
F_35 ( & V_2 -> V_45 , V_58 ) ;
F_36 () ;
return V_60 ;
}
static int F_39 ( void * V_61 )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * V_62 , * V_63 ;
unsigned long V_58 ;
V_62 = (struct V_20 * ) V_61 ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
F_18 ( V_2 ) ;
if ( ! V_62 -> V_64 || V_62 -> V_64 ( V_62 ) == 0 ) {
V_63 = V_2 -> clock ;
F_9 ( V_2 , V_62 ) ;
if ( V_63 -> V_65 )
V_63 -> V_65 ( V_63 ) ;
}
F_15 ( V_2 , true ) ;
F_35 ( & V_2 -> V_45 , V_58 ) ;
return 0 ;
}
void F_40 ( struct V_20 * clock )
{
struct V_1 * V_2 = & V_1 ;
if ( V_2 -> clock == clock )
return;
F_41 ( F_39 , clock , NULL ) ;
F_42 () ;
}
T_3 F_43 ( void )
{
struct V_8 V_54 ;
F_20 ( & V_54 ) ;
return F_7 ( V_54 ) ;
}
void F_44 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
T_2 V_43 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_43 = F_13 ( V_2 ) ;
* V_9 = V_2 -> V_41 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
F_19 ( V_9 , V_43 ) ;
}
int F_45 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
int V_60 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_60 = V_2 -> clock -> V_58 & V_66 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
return V_60 ;
}
V_4 F_46 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
V_4 V_60 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_60 = V_2 -> clock -> V_67 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
return V_60 ;
}
void T_4 F_47 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * clock ;
unsigned long V_58 ;
struct V_8 V_54 , V_68 , V_13 ;
F_48 ( & V_54 ) ;
if ( ! F_31 ( & V_54 ) ) {
F_49 ( L_1
L_2 ) ;
V_54 . V_10 = 0 ;
V_54 . V_11 = 0 ;
}
F_50 ( & V_68 ) ;
if ( ! F_31 ( & V_68 ) ) {
F_49 ( L_3
L_2 ) ;
V_68 . V_10 = 0 ;
V_68 . V_11 = 0 ;
}
F_51 ( & V_2 -> V_45 ) ;
F_52 () ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
clock = F_53 () ;
if ( clock -> V_64 )
clock -> V_64 ( clock ) ;
F_9 ( V_2 , clock ) ;
F_2 ( V_2 , & V_54 ) ;
V_2 -> V_41 . V_10 = 0 ;
V_2 -> V_41 . V_11 = 0 ;
if ( V_68 . V_10 == 0 && V_68 . V_11 == 0 )
V_68 = F_33 ( V_2 ) ;
F_5 ( & V_13 , - V_68 . V_10 , - V_68 . V_11 ) ;
F_4 ( V_2 , V_13 ) ;
V_13 . V_10 = 0 ;
V_13 . V_11 = 0 ;
F_8 ( V_2 , V_13 ) ;
F_35 ( & V_2 -> V_45 , V_58 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_8 * V_69 )
{
if ( ! F_31 ( V_69 ) ) {
F_55 ( V_70 L_4
L_5 ) ;
return;
}
F_3 ( V_2 , V_69 ) ;
F_4 ( V_2 , F_34 ( V_2 -> V_14 , * V_69 ) ) ;
F_8 ( V_2 , F_38 ( V_2 -> V_19 , * V_69 ) ) ;
}
void F_56 ( struct V_8 * V_69 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_9 ;
F_48 ( & V_9 ) ;
if ( ! ( V_9 . V_10 == 0 && V_9 . V_11 == 0 ) )
return;
F_32 ( & V_2 -> V_45 , V_58 ) ;
F_18 ( V_2 ) ;
F_54 ( V_2 , V_69 ) ;
F_15 ( V_2 , true ) ;
F_35 ( & V_2 -> V_45 , V_58 ) ;
F_36 () ;
}
static void F_57 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_9 ;
F_48 ( & V_9 ) ;
F_58 () ;
F_59 () ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
if ( F_60 ( & V_9 , & V_71 ) > 0 ) {
V_9 = F_34 ( V_9 , V_71 ) ;
F_54 ( V_2 , & V_9 ) ;
}
V_2 -> clock -> V_24 = V_2 -> clock -> V_25 ( V_2 -> clock ) ;
V_2 -> V_33 = 0 ;
V_44 = 0 ;
F_15 ( V_2 , false ) ;
F_35 ( & V_2 -> V_45 , V_58 ) ;
F_61 () ;
F_62 ( V_72 , NULL ) ;
F_63 () ;
}
static int F_64 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_69 , V_73 ;
static struct V_8 V_74 ;
F_48 ( & V_71 ) ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
F_18 ( V_2 ) ;
V_44 = 1 ;
V_69 = F_34 ( F_33 ( V_2 ) , V_71 ) ;
V_73 = F_34 ( V_69 , V_74 ) ;
if ( abs ( V_73 . V_10 ) >= 2 ) {
V_74 = V_69 ;
} else {
V_71 =
F_38 ( V_71 , V_73 ) ;
}
F_35 ( & V_2 -> V_45 , V_58 ) ;
F_62 ( V_75 , NULL ) ;
F_65 () ;
F_66 () ;
return 0 ;
}
static int T_4 F_67 ( void )
{
F_68 ( & V_76 ) ;
return 0 ;
}
static T_5 int F_69 ( struct V_1 * V_2 ,
T_2 error , T_2 * V_21 ,
T_2 * V_77 )
{
T_2 V_78 , V_79 ;
T_6 V_80 , V_81 ;
T_7 V_82 , V_27 ;
V_82 = V_2 -> V_33 >> ( V_35 + 22 - 2 * V_83 ) ;
V_82 = abs ( V_82 ) ;
for ( V_80 = 0 ; V_82 > 0 ; V_80 ++ )
V_82 >>= 2 ;
V_78 = F_70 () >> ( V_2 -> V_34 + 1 ) ;
V_78 -= V_2 -> V_29 >> 1 ;
error = ( ( error - V_78 ) >> V_80 ) + V_78 ;
V_79 = * V_21 ;
V_27 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_21 = - * V_21 ;
* V_77 = - * V_77 ;
V_27 = - 1 ;
}
for ( V_81 = 0 ; error > V_79 ; V_81 ++ )
error >>= 1 ;
* V_21 <<= V_81 ;
* V_77 <<= V_81 ;
return V_27 << V_81 ;
}
static void F_71 ( struct V_1 * V_2 , T_2 V_77 )
{
T_2 error , V_21 = V_2 -> V_28 ;
int V_81 ;
error = V_2 -> V_33 >> ( V_2 -> V_34 - 1 ) ;
if ( error > V_21 ) {
error >>= 2 ;
if ( F_72 ( error <= V_21 ) )
V_81 = 1 ;
else
V_81 = F_69 ( V_2 , error , & V_21 , & V_77 ) ;
} else {
if ( error < - V_21 ) {
error >>= 2 ;
if ( F_72 ( error >= - V_21 ) ) {
V_81 = - 1 ;
V_21 = - V_21 ;
V_77 = - V_77 ;
} else {
V_81 = F_69 ( V_2 , error , & V_21 , & V_77 ) ;
}
} else {
goto V_84;
}
}
if ( F_73 ( V_2 -> clock -> V_85 &&
( V_2 -> V_27 + V_81 > V_2 -> clock -> V_27 + V_2 -> clock -> V_85 ) ) ) {
F_74 ( V_70
L_6 ,
V_2 -> clock -> V_86 , ( long ) V_2 -> V_27 + V_81 ,
( long ) V_2 -> clock -> V_27 + V_2 -> clock -> V_85 ) ;
}
V_2 -> V_27 += V_81 ;
V_2 -> V_29 += V_21 ;
V_2 -> V_3 -= V_77 ;
V_2 -> V_33 -= ( V_21 - V_77 ) << V_2 -> V_34 ;
V_84:
if ( F_73 ( ( T_2 ) V_2 -> V_3 < 0 ) ) {
T_2 V_87 = - ( T_2 ) V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_33 += V_87 << V_2 -> V_34 ;
}
}
static inline void F_75 ( struct V_1 * V_2 )
{
V_4 V_88 = ( V_4 ) V_5 << V_2 -> V_6 ;
while ( V_2 -> V_3 >= V_88 ) {
int V_89 ;
V_2 -> V_3 -= V_88 ;
V_2 -> V_7 ++ ;
V_89 = F_76 ( V_2 -> V_7 ) ;
if ( F_73 ( V_89 ) ) {
struct V_8 V_9 ;
V_2 -> V_7 += V_89 ;
V_9 . V_10 = V_89 ;
V_9 . V_11 = 0 ;
F_4 ( V_2 ,
F_34 ( V_2 -> V_14 , V_9 ) ) ;
F_77 () ;
}
}
}
static T_1 F_78 ( struct V_1 * V_2 , T_1 V_77 ,
T_6 V_6 )
{
V_4 V_90 ;
if ( V_77 < V_2 -> V_28 << V_6 )
return V_77 ;
V_77 -= V_2 -> V_28 << V_6 ;
V_2 -> clock -> V_24 += V_2 -> V_28 << V_6 ;
V_2 -> V_3 += V_2 -> V_29 << V_6 ;
F_75 ( V_2 ) ;
V_90 = ( V_4 ) V_2 -> V_31 << V_6 ;
V_90 += V_2 -> V_41 . V_11 ;
if ( V_90 >= V_5 ) {
V_4 V_91 = V_90 ;
V_90 = F_10 ( V_91 , V_5 ) ;
V_2 -> V_41 . V_10 += V_91 ;
}
V_2 -> V_41 . V_11 = V_90 ;
V_2 -> V_33 += F_70 () << V_6 ;
V_2 -> V_33 -= ( V_2 -> V_29 + V_2 -> V_30 ) <<
( V_2 -> V_34 + V_6 ) ;
return V_77 ;
}
static inline void F_79 ( struct V_1 * V_2 )
{
T_2 V_92 ;
V_92 = V_2 -> V_3 & ( ( 1ULL << V_2 -> V_6 ) - 1 ) ;
V_2 -> V_3 -= V_92 ;
V_2 -> V_3 += 1ULL << V_2 -> V_6 ;
V_2 -> V_33 += V_92 << V_2 -> V_34 ;
}
static void F_80 ( void )
{
struct V_20 * clock ;
struct V_1 * V_2 = & V_1 ;
T_1 V_77 ;
int V_6 = 0 , V_93 ;
unsigned long V_58 ;
F_32 ( & V_2 -> V_45 , V_58 ) ;
if ( F_73 ( V_44 ) )
goto V_94;
clock = V_2 -> clock ;
#ifdef F_81
V_77 = V_2 -> V_28 ;
#else
V_77 = ( clock -> V_25 ( clock ) - clock -> V_24 ) & clock -> V_39 ;
#endif
if ( V_77 < V_2 -> V_28 )
goto V_94;
V_6 = F_82 ( V_77 ) - F_82 ( V_2 -> V_28 ) ;
V_6 = F_83 ( 0 , V_6 ) ;
V_93 = ( 64 - ( F_82 ( F_70 () ) + 1 ) ) - 1 ;
V_6 = F_84 ( V_6 , V_93 ) ;
while ( V_77 >= V_2 -> V_28 ) {
V_77 = F_78 ( V_2 , V_77 , V_6 ) ;
if ( V_77 < V_2 -> V_28 << V_6 )
V_6 -- ;
}
F_71 ( V_2 , V_77 ) ;
F_79 ( V_2 ) ;
F_75 ( V_2 ) ;
F_15 ( V_2 , false ) ;
V_94:
F_35 ( & V_2 -> V_45 , V_58 ) ;
}
void F_85 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_95 = {
. V_10 = V_2 -> V_14 . V_10 +
V_2 -> V_19 . V_10 ,
. V_11 = V_2 -> V_14 . V_11 +
V_2 -> V_19 . V_11
} ;
F_5 ( V_9 , - V_95 . V_10 , - V_95 . V_11 ) ;
}
void F_86 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_47 , V_96 ;
T_2 V_38 ;
unsigned int V_42 ;
F_21 ( V_44 ) ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_38 = F_11 ( V_2 ) ;
V_47 = V_2 -> V_14 ;
V_96 = V_2 -> V_19 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
V_9 -> V_10 += V_47 . V_10 + V_96 . V_10 ;
V_9 -> V_11 = 0 ;
F_19 ( V_9 , V_38 + V_47 . V_11 + V_96 . V_11 ) ;
}
T_3 F_87 ( void )
{
struct V_8 V_9 ;
F_86 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_88 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
* V_9 = F_38 ( * V_9 , V_2 -> V_19 ) ;
}
unsigned long F_89 ( void )
{
struct V_1 * V_2 = & V_1 ;
return V_2 -> V_7 ;
}
struct V_8 F_90 ( void )
{
struct V_1 * V_2 = & V_1 ;
return F_33 ( V_2 ) ;
}
struct V_8 F_91 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_54 ;
unsigned long V_42 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_54 = F_33 ( V_2 ) ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
return V_54 ;
}
struct V_8 F_92 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_54 , V_97 ;
unsigned long V_42 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_54 = F_33 ( V_2 ) ;
V_97 = V_2 -> V_14 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
F_5 ( & V_54 , V_54 . V_10 + V_97 . V_10 ,
V_54 . V_11 + V_97 . V_11 ) ;
return V_54 ;
}
void F_93 ( unsigned long V_98 )
{
V_99 += V_98 ;
F_80 () ;
F_94 ( V_98 ) ;
}
void F_95 ( struct V_8 * V_100 ,
struct V_8 * V_101 , struct V_8 * V_96 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
* V_100 = F_33 ( V_2 ) ;
* V_101 = V_2 -> V_14 ;
* V_96 = V_2 -> V_19 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
}
T_3 F_96 ( T_3 * V_15 , T_3 * V_18 )
{
struct V_1 * V_2 = & V_1 ;
T_3 V_54 ;
unsigned int V_42 ;
V_4 V_46 , V_43 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_46 = V_2 -> V_7 ;
V_43 = F_11 ( V_2 ) ;
* V_15 = V_2 -> V_15 ;
* V_18 = V_2 -> V_18 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
V_54 = F_25 ( F_26 ( V_46 , 0 ) , V_43 ) ;
V_54 = F_97 ( V_54 , * V_15 ) ;
return V_54 ;
}
T_3 F_98 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_42 ;
struct V_8 V_101 ;
do {
V_42 = F_22 ( & V_2 -> V_45 ) ;
V_101 = V_2 -> V_14 ;
} while ( F_23 ( & V_2 -> V_45 , V_42 ) );
return F_7 ( V_101 ) ;
}
void F_99 ( unsigned long V_98 )
{
F_100 ( & V_102 ) ;
F_93 ( V_98 ) ;
F_101 ( & V_102 ) ;
}
