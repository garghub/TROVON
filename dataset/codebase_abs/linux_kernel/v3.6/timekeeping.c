static inline void F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 >= ( ( V_4 ) V_5 << V_2 -> V_6 ) ) {
V_2 -> V_3 -= ( V_4 ) V_5 << V_2 -> V_6 ;
V_2 -> V_7 ++ ;
}
}
static struct V_8 F_2 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
V_9 . V_10 = V_2 -> V_7 ;
V_9 . V_11 = ( long ) ( V_2 -> V_3 >> V_2 -> V_6 ) ;
return V_9 ;
}
static void F_3 ( struct V_1 * V_2 , const struct V_8 * V_9 )
{
V_2 -> V_7 = V_9 -> V_10 ;
V_2 -> V_3 = ( V_4 ) V_9 -> V_11 << V_2 -> V_6 ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_8 * V_9 )
{
V_2 -> V_7 += V_9 -> V_10 ;
V_2 -> V_3 += ( V_4 ) V_9 -> V_11 << V_2 -> V_6 ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 V_12 )
{
struct V_8 V_13 ;
F_6 ( & V_13 , - V_2 -> V_14 . V_10 ,
- V_2 -> V_14 . V_11 ) ;
F_7 ( V_2 -> V_15 . V_16 != F_8 ( V_13 ) . V_16 ) ;
V_2 -> V_14 = V_12 ;
F_6 ( & V_13 , - V_12 . V_10 , - V_12 . V_11 ) ;
V_2 -> V_15 = F_8 ( V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_8 V_17 )
{
F_7 ( V_2 -> V_18 . V_16 != F_8 ( V_2 -> V_19 ) . V_16 ) ;
V_2 -> V_19 = V_17 ;
V_2 -> V_18 = F_8 ( V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_20 * clock )
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
F_11 ( V_13 , clock -> V_27 ) ;
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
static inline T_2 F_12 ( struct V_1 * V_2 )
{
T_1 V_36 , V_37 ;
struct V_20 * clock ;
T_2 V_38 ;
clock = V_2 -> clock ;
V_36 = clock -> V_25 ( clock ) ;
V_37 = ( V_36 - clock -> V_24 ) & clock -> V_39 ;
V_38 = V_37 * V_2 -> V_27 + V_2 -> V_3 ;
V_38 >>= V_2 -> V_6 ;
return V_38 + F_13 () ;
}
static inline T_2 F_14 ( struct V_1 * V_2 )
{
T_1 V_36 , V_37 ;
struct V_20 * clock ;
T_2 V_38 ;
clock = V_2 -> clock ;
V_36 = clock -> V_25 ( clock ) ;
V_37 = ( V_36 - clock -> V_24 ) & clock -> V_39 ;
V_38 = F_15 ( V_37 , clock -> V_27 , clock -> V_6 ) ;
return V_38 + F_13 () ;
}
static void F_16 ( struct V_1 * V_2 , bool V_40 )
{
struct V_8 V_41 ;
if ( V_40 ) {
V_2 -> V_33 = 0 ;
F_17 () ;
}
V_41 = F_2 ( V_2 ) ;
F_18 ( & V_41 , & V_2 -> V_14 , V_2 -> clock , V_2 -> V_27 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_36 , V_37 ;
struct V_20 * clock ;
T_2 V_38 ;
clock = V_2 -> clock ;
V_36 = clock -> V_25 ( clock ) ;
V_37 = ( V_36 - clock -> V_24 ) & clock -> V_39 ;
clock -> V_24 = V_36 ;
V_2 -> V_3 += V_37 * V_2 -> V_27 ;
V_2 -> V_3 += ( V_4 ) F_13 () << V_2 -> V_6 ;
F_1 ( V_2 ) ;
V_38 = F_15 ( V_37 , clock -> V_27 , clock -> V_6 ) ;
F_20 ( & V_2 -> V_42 , V_38 ) ;
}
void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
T_2 V_44 = 0 ;
F_22 ( V_45 ) ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_44 = F_12 ( V_2 ) ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
V_9 -> V_11 = 0 ;
F_20 ( V_9 , V_44 ) ;
}
T_3 F_25 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_43 ;
T_2 V_47 , V_44 ;
F_22 ( V_45 ) ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_47 = V_2 -> V_7 + V_2 -> V_14 . V_10 ;
V_44 = F_12 ( V_2 ) + V_2 -> V_14 . V_11 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
return F_26 ( F_27 ( V_47 , 0 ) , V_44 ) ;
}
void F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_48 ;
T_2 V_38 ;
unsigned int V_43 ;
F_22 ( V_45 ) ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_38 = F_12 ( V_2 ) ;
V_48 = V_2 -> V_14 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
V_9 -> V_10 += V_48 . V_10 ;
V_9 -> V_11 = 0 ;
F_20 ( V_9 , V_38 + V_48 . V_11 ) ;
}
void F_29 ( struct V_8 * V_49 , struct V_8 * V_50 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
T_2 V_51 , V_52 ;
F_7 ( V_45 ) ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
* V_49 = V_2 -> V_42 ;
V_50 -> V_10 = V_2 -> V_7 ;
V_50 -> V_11 = 0 ;
V_51 = F_14 ( V_2 ) ;
V_52 = F_12 ( V_2 ) ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
F_20 ( V_49 , V_51 ) ;
F_20 ( V_50 , V_52 ) ;
}
void F_30 ( struct V_53 * V_54 )
{
struct V_8 V_55 ;
F_21 ( & V_55 ) ;
V_54 -> V_10 = V_55 . V_10 ;
V_54 -> V_56 = V_55 . V_11 / 1000 ;
}
int F_31 ( const struct V_8 * V_54 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_57 , V_41 ;
unsigned long V_58 ;
if ( ! F_32 ( V_54 ) )
return - V_59 ;
F_33 ( & V_2 -> V_46 , V_58 ) ;
F_19 ( V_2 ) ;
V_41 = F_2 ( V_2 ) ;
V_57 . V_10 = V_54 -> V_10 - V_41 . V_10 ;
V_57 . V_11 = V_54 -> V_11 - V_41 . V_11 ;
F_5 ( V_2 , F_34 ( V_2 -> V_14 , V_57 ) ) ;
F_3 ( V_2 , V_54 ) ;
F_16 ( V_2 , true ) ;
F_35 ( & V_2 -> V_46 , V_58 ) ;
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
F_33 ( & V_2 -> V_46 , V_58 ) ;
F_19 ( V_2 ) ;
V_13 = F_38 ( F_2 ( V_2 ) , * V_9 ) ;
if ( ! F_32 ( & V_13 ) ) {
V_60 = - V_59 ;
goto error;
}
F_4 ( V_2 , V_9 ) ;
F_5 ( V_2 , F_34 ( V_2 -> V_14 , * V_9 ) ) ;
error:
F_16 ( V_2 , true ) ;
F_35 ( & V_2 -> V_46 , V_58 ) ;
F_36 () ;
return V_60 ;
}
static int F_39 ( void * V_61 )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * V_62 , * V_63 ;
unsigned long V_58 ;
V_62 = (struct V_20 * ) V_61 ;
F_33 ( & V_2 -> V_46 , V_58 ) ;
F_19 ( V_2 ) ;
if ( ! V_62 -> V_64 || V_62 -> V_64 ( V_62 ) == 0 ) {
V_63 = V_2 -> clock ;
F_10 ( V_2 , V_62 ) ;
if ( V_63 -> V_65 )
V_63 -> V_65 ( V_63 ) ;
}
F_16 ( V_2 , true ) ;
F_35 ( & V_2 -> V_46 , V_58 ) ;
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
struct V_8 V_55 ;
F_21 ( & V_55 ) ;
return F_8 ( V_55 ) ;
}
void F_44 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
T_2 V_44 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_44 = F_14 ( V_2 ) ;
* V_9 = V_2 -> V_42 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
F_20 ( V_9 , V_44 ) ;
}
int F_45 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
int V_60 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_60 = V_2 -> clock -> V_58 & V_66 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
return V_60 ;
}
V_4 F_46 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
V_4 V_60 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_60 = V_2 -> clock -> V_67 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
return V_60 ;
}
void T_4 F_47 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * clock ;
unsigned long V_58 ;
struct V_8 V_55 , V_68 , V_13 ;
F_48 ( & V_55 ) ;
if ( ! F_32 ( & V_55 ) ) {
F_49 ( L_1
L_2 ) ;
V_55 . V_10 = 0 ;
V_55 . V_11 = 0 ;
}
F_50 ( & V_68 ) ;
if ( ! F_32 ( & V_68 ) ) {
F_49 ( L_3
L_2 ) ;
V_68 . V_10 = 0 ;
V_68 . V_11 = 0 ;
}
F_51 ( & V_2 -> V_46 ) ;
F_52 () ;
F_33 ( & V_2 -> V_46 , V_58 ) ;
clock = F_53 () ;
if ( clock -> V_64 )
clock -> V_64 ( clock ) ;
F_10 ( V_2 , clock ) ;
F_3 ( V_2 , & V_55 ) ;
V_2 -> V_42 . V_10 = 0 ;
V_2 -> V_42 . V_11 = 0 ;
if ( V_68 . V_10 == 0 && V_68 . V_11 == 0 )
V_68 = F_2 ( V_2 ) ;
F_6 ( & V_13 , - V_68 . V_10 , - V_68 . V_11 ) ;
F_5 ( V_2 , V_13 ) ;
V_13 . V_10 = 0 ;
V_13 . V_11 = 0 ;
F_9 ( V_2 , V_13 ) ;
F_35 ( & V_2 -> V_46 , V_58 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_8 * V_69 )
{
if ( ! F_32 ( V_69 ) ) {
F_55 ( V_70 L_4
L_5 ) ;
return;
}
F_4 ( V_2 , V_69 ) ;
F_5 ( V_2 , F_34 ( V_2 -> V_14 , * V_69 ) ) ;
F_9 ( V_2 , F_38 ( V_2 -> V_19 , * V_69 ) ) ;
}
void F_56 ( struct V_8 * V_69 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_9 ;
F_48 ( & V_9 ) ;
if ( ! ( V_9 . V_10 == 0 && V_9 . V_11 == 0 ) )
return;
F_33 ( & V_2 -> V_46 , V_58 ) ;
F_19 ( V_2 ) ;
F_54 ( V_2 , V_69 ) ;
F_16 ( V_2 , true ) ;
F_35 ( & V_2 -> V_46 , V_58 ) ;
F_36 () ;
}
static void F_57 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_9 ;
F_48 ( & V_9 ) ;
F_58 () ;
F_33 ( & V_2 -> V_46 , V_58 ) ;
if ( F_59 ( & V_9 , & V_71 ) > 0 ) {
V_9 = F_34 ( V_9 , V_71 ) ;
F_54 ( V_2 , & V_9 ) ;
}
V_2 -> clock -> V_24 = V_2 -> clock -> V_25 ( V_2 -> clock ) ;
V_2 -> V_33 = 0 ;
V_45 = 0 ;
F_16 ( V_2 , false ) ;
F_35 ( & V_2 -> V_46 , V_58 ) ;
F_60 () ;
F_61 ( V_72 , NULL ) ;
F_62 () ;
}
static int F_63 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_58 ;
struct V_8 V_69 , V_73 ;
static struct V_8 V_74 ;
F_48 ( & V_71 ) ;
F_33 ( & V_2 -> V_46 , V_58 ) ;
F_19 ( V_2 ) ;
V_45 = 1 ;
V_69 = F_34 ( F_2 ( V_2 ) , V_71 ) ;
V_73 = F_34 ( V_69 , V_74 ) ;
if ( abs ( V_73 . V_10 ) >= 2 ) {
V_74 = V_69 ;
} else {
V_71 =
F_38 ( V_71 , V_73 ) ;
}
F_35 ( & V_2 -> V_46 , V_58 ) ;
F_61 ( V_75 , NULL ) ;
F_64 () ;
return 0 ;
}
static int T_4 F_65 ( void )
{
F_66 ( & V_76 ) ;
return 0 ;
}
static T_5 int F_67 ( struct V_1 * V_2 ,
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
V_78 = F_68 () >> ( V_2 -> V_34 + 1 ) ;
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
static void F_69 ( struct V_1 * V_2 , T_2 V_77 )
{
T_2 error , V_21 = V_2 -> V_28 ;
int V_81 ;
error = V_2 -> V_33 >> ( V_2 -> V_34 - 1 ) ;
if ( error > V_21 ) {
error >>= 2 ;
if ( F_70 ( error <= V_21 ) )
V_81 = 1 ;
else
V_81 = F_67 ( V_2 , error , & V_21 , & V_77 ) ;
} else {
if ( error < - V_21 ) {
error >>= 2 ;
if ( F_70 ( error >= - V_21 ) ) {
V_81 = - 1 ;
V_21 = - V_21 ;
V_77 = - V_77 ;
} else {
V_81 = F_67 ( V_2 , error , & V_21 , & V_77 ) ;
}
} else {
goto V_84;
}
}
if ( F_71 ( V_2 -> clock -> V_85 &&
( V_2 -> V_27 + V_81 > V_2 -> clock -> V_27 + V_2 -> clock -> V_85 ) ) ) {
F_72 ( V_70
L_6 ,
V_2 -> clock -> V_86 , ( long ) V_2 -> V_27 + V_81 ,
( long ) V_2 -> clock -> V_27 + V_2 -> clock -> V_85 ) ;
}
V_2 -> V_27 += V_81 ;
V_2 -> V_29 += V_21 ;
V_2 -> V_3 -= V_77 ;
V_2 -> V_33 -= ( V_21 - V_77 ) << V_2 -> V_34 ;
V_84:
if ( F_71 ( ( T_2 ) V_2 -> V_3 < 0 ) ) {
T_2 V_87 = - ( T_2 ) V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_33 += V_87 << V_2 -> V_34 ;
}
}
static inline void F_73 ( struct V_1 * V_2 )
{
V_4 V_88 = ( V_4 ) V_5 << V_2 -> V_6 ;
while ( V_2 -> V_3 >= V_88 ) {
int V_89 ;
V_2 -> V_3 -= V_88 ;
V_2 -> V_7 ++ ;
V_89 = F_74 ( V_2 -> V_7 ) ;
if ( F_71 ( V_89 ) ) {
struct V_8 V_9 ;
V_2 -> V_7 += V_89 ;
V_9 . V_10 = V_89 ;
V_9 . V_11 = 0 ;
F_5 ( V_2 ,
F_34 ( V_2 -> V_14 , V_9 ) ) ;
F_75 () ;
}
}
}
static T_1 F_76 ( struct V_1 * V_2 , T_1 V_77 ,
T_6 V_6 )
{
V_4 V_90 ;
if ( V_77 < V_2 -> V_28 << V_6 )
return V_77 ;
V_77 -= V_2 -> V_28 << V_6 ;
V_2 -> clock -> V_24 += V_2 -> V_28 << V_6 ;
V_2 -> V_3 += V_2 -> V_29 << V_6 ;
F_73 ( V_2 ) ;
V_90 = V_2 -> V_31 << V_6 ;
V_90 += V_2 -> V_42 . V_11 ;
if ( V_90 >= V_5 ) {
V_4 V_91 = V_90 ;
V_90 = F_11 ( V_91 , V_5 ) ;
V_2 -> V_42 . V_10 += V_91 ;
}
V_2 -> V_42 . V_11 = V_90 ;
V_2 -> V_33 += F_68 () << V_6 ;
V_2 -> V_33 -= ( V_2 -> V_29 + V_2 -> V_30 ) <<
( V_2 -> V_34 + V_6 ) ;
return V_77 ;
}
static void F_77 ( void )
{
struct V_20 * clock ;
struct V_1 * V_2 = & V_1 ;
T_1 V_77 ;
int V_6 = 0 , V_92 ;
unsigned long V_58 ;
T_2 V_93 ;
F_33 ( & V_2 -> V_46 , V_58 ) ;
if ( F_71 ( V_45 ) )
goto V_94;
clock = V_2 -> clock ;
#ifdef F_78
V_77 = V_2 -> V_28 ;
#else
V_77 = ( clock -> V_25 ( clock ) - clock -> V_24 ) & clock -> V_39 ;
#endif
if ( V_77 < V_2 -> V_28 )
goto V_94;
V_6 = F_79 ( V_77 ) - F_79 ( V_2 -> V_28 ) ;
V_6 = F_80 ( 0 , V_6 ) ;
V_92 = ( 64 - ( F_79 ( F_68 () ) + 1 ) ) - 1 ;
V_6 = F_81 ( V_6 , V_92 ) ;
while ( V_77 >= V_2 -> V_28 ) {
V_77 = F_76 ( V_2 , V_77 , V_6 ) ;
if ( V_77 < V_2 -> V_28 << V_6 )
V_6 -- ;
}
F_69 ( V_2 , V_77 ) ;
V_93 = V_2 -> V_3 & ( ( 1ULL << V_2 -> V_6 ) - 1 ) ;
V_2 -> V_3 -= V_93 ;
V_2 -> V_3 += 1ULL << V_2 -> V_6 ;
V_2 -> V_33 += V_93 << V_2 -> V_34 ;
F_73 ( V_2 ) ;
F_16 ( V_2 , false ) ;
V_94:
F_35 ( & V_2 -> V_46 , V_58 ) ;
}
void F_82 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_95 = {
. V_10 = V_2 -> V_14 . V_10 +
V_2 -> V_19 . V_10 ,
. V_11 = V_2 -> V_14 . V_11 +
V_2 -> V_19 . V_11
} ;
F_6 ( V_9 , - V_95 . V_10 , - V_95 . V_11 ) ;
}
void F_83 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_48 , V_96 ;
T_2 V_38 ;
unsigned int V_43 ;
F_22 ( V_45 ) ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_38 = F_12 ( V_2 ) ;
V_48 = V_2 -> V_14 ;
V_96 = V_2 -> V_19 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
V_9 -> V_10 += V_48 . V_10 + V_96 . V_10 ;
V_9 -> V_11 = 0 ;
F_20 ( V_9 , V_38 + V_48 . V_11 + V_96 . V_11 ) ;
}
T_3 F_84 ( void )
{
struct V_8 V_9 ;
F_83 ( & V_9 ) ;
return F_8 ( V_9 ) ;
}
void F_85 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
* V_9 = F_38 ( * V_9 , V_2 -> V_19 ) ;
}
unsigned long F_86 ( void )
{
struct V_1 * V_2 = & V_1 ;
return V_2 -> V_7 ;
}
struct V_8 F_87 ( void )
{
struct V_1 * V_2 = & V_1 ;
return F_2 ( V_2 ) ;
}
struct V_8 F_88 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_55 ;
unsigned long V_43 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_55 = F_2 ( V_2 ) ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
return V_55 ;
}
struct V_8 F_89 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_55 , V_97 ;
unsigned long V_43 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_55 = F_2 ( V_2 ) ;
V_97 = V_2 -> V_14 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
F_6 ( & V_55 , V_55 . V_10 + V_97 . V_10 ,
V_55 . V_11 + V_97 . V_11 ) ;
return V_55 ;
}
void F_90 ( unsigned long V_98 )
{
V_99 += V_98 ;
F_77 () ;
F_91 ( V_98 ) ;
}
void F_92 ( struct V_8 * V_100 ,
struct V_8 * V_101 , struct V_8 * V_96 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
* V_100 = F_2 ( V_2 ) ;
* V_101 = V_2 -> V_14 ;
* V_96 = V_2 -> V_19 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
}
T_3 F_93 ( T_3 * V_15 , T_3 * V_18 )
{
struct V_1 * V_2 = & V_1 ;
T_3 V_55 ;
unsigned int V_43 ;
V_4 V_47 , V_44 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_47 = V_2 -> V_7 ;
V_44 = F_12 ( V_2 ) ;
* V_15 = V_2 -> V_15 ;
* V_18 = V_2 -> V_18 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
V_55 = F_26 ( F_27 ( V_47 , 0 ) , V_44 ) ;
V_55 = F_94 ( V_55 , * V_15 ) ;
return V_55 ;
}
T_3 F_95 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_43 ;
struct V_8 V_101 ;
do {
V_43 = F_23 ( & V_2 -> V_46 ) ;
V_101 = V_2 -> V_14 ;
} while ( F_24 ( & V_2 -> V_46 , V_43 ) );
return F_8 ( V_101 ) ;
}
void F_96 ( unsigned long V_98 )
{
F_97 ( & V_102 ) ;
F_90 ( V_98 ) ;
F_98 ( & V_102 ) ;
}
