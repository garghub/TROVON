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
T_2 F_11 ( void )
{
if ( F_12 ( V_36 ) )
return V_36 () ;
return 0 ;
}
static inline T_2 F_11 ( void ) { return 0 ; }
static inline T_3 F_13 ( struct V_1 * V_2 )
{
T_1 V_37 , V_38 ;
struct V_20 * clock ;
T_3 V_39 ;
clock = V_2 -> clock ;
V_37 = clock -> V_25 ( clock ) ;
V_38 = ( V_37 - clock -> V_24 ) & clock -> V_40 ;
V_39 = V_38 * V_2 -> V_27 + V_2 -> V_3 ;
V_39 >>= V_2 -> V_6 ;
return V_39 + F_11 () ;
}
static inline T_3 F_14 ( struct V_1 * V_2 )
{
T_1 V_37 , V_38 ;
struct V_20 * clock ;
T_3 V_39 ;
clock = V_2 -> clock ;
V_37 = clock -> V_25 ( clock ) ;
V_38 = ( V_37 - clock -> V_24 ) & clock -> V_40 ;
V_39 = F_15 ( V_38 , clock -> V_27 , clock -> V_6 ) ;
return V_39 + F_11 () ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_41 , 0 , V_2 ) ;
}
int F_18 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_44 ;
int V_45 ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
V_45 = F_20 ( & V_41 , V_43 ) ;
F_16 ( V_2 ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
return V_45 ;
}
int F_22 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_44 ;
int V_45 ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
V_45 = F_23 ( & V_41 , V_43 ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
return V_45 ;
}
static void F_24 ( struct V_1 * V_2 , bool V_47 )
{
if ( V_47 ) {
V_2 -> V_33 = 0 ;
F_25 () ;
}
F_26 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_37 , V_38 ;
struct V_20 * clock ;
T_3 V_39 ;
clock = V_2 -> clock ;
V_37 = clock -> V_25 ( clock ) ;
V_38 = ( V_37 - clock -> V_24 ) & clock -> V_40 ;
clock -> V_24 = V_37 ;
V_2 -> V_3 += V_38 * V_2 -> V_27 ;
V_2 -> V_3 += ( V_4 ) F_11 () << V_2 -> V_6 ;
F_1 ( V_2 ) ;
V_39 = F_15 ( V_38 , clock -> V_27 , clock -> V_6 ) ;
F_28 ( & V_2 -> V_48 , V_39 ) ;
}
int F_29 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
T_3 V_50 = 0 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_50 = F_13 ( V_2 ) ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
V_9 -> V_11 = 0 ;
F_28 ( V_9 , V_50 ) ;
if ( F_32 ( V_51 ) )
return - V_52 ;
return 0 ;
}
void F_33 ( struct V_8 * V_9 )
{
F_34 ( F_29 ( V_9 ) ) ;
}
T_4 F_35 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_49 ;
T_3 V_53 , V_50 ;
F_34 ( V_51 ) ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_53 = V_2 -> V_7 + V_2 -> V_14 . V_10 ;
V_50 = F_13 ( V_2 ) + V_2 -> V_14 . V_11 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
return F_36 ( F_37 ( V_53 , 0 ) , V_50 ) ;
}
void F_38 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_54 ;
T_3 V_39 ;
unsigned int V_49 ;
F_34 ( V_51 ) ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_39 = F_13 ( V_2 ) ;
V_54 = V_2 -> V_14 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
V_9 -> V_10 += V_54 . V_10 ;
V_9 -> V_11 = 0 ;
F_28 ( V_9 , V_39 + V_54 . V_11 ) ;
}
void F_39 ( struct V_8 * V_55 , struct V_8 * V_56 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
T_3 V_57 , V_58 ;
F_6 ( V_51 ) ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
* V_55 = V_2 -> V_48 ;
V_56 -> V_10 = V_2 -> V_7 ;
V_56 -> V_11 = 0 ;
V_57 = F_14 ( V_2 ) ;
V_58 = F_13 ( V_2 ) ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
F_28 ( V_55 , V_57 ) ;
F_28 ( V_56 , V_58 ) ;
}
void F_40 ( struct V_59 * V_60 )
{
struct V_8 V_61 ;
F_33 ( & V_61 ) ;
V_60 -> V_10 = V_61 . V_10 ;
V_60 -> V_62 = V_61 . V_11 / 1000 ;
}
int F_41 ( const struct V_8 * V_60 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_63 , V_64 ;
unsigned long V_44 ;
if ( ! F_42 ( V_60 ) )
return - V_65 ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
F_27 ( V_2 ) ;
V_64 = F_43 ( V_2 ) ;
V_63 . V_10 = V_60 -> V_10 - V_64 . V_10 ;
V_63 . V_11 = V_60 -> V_11 - V_64 . V_11 ;
F_4 ( V_2 , F_44 ( V_2 -> V_14 , V_63 ) ) ;
F_2 ( V_2 , V_60 ) ;
F_24 ( V_2 , true ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
F_45 () ;
return 0 ;
}
int F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_44 ;
struct V_8 V_13 ;
int V_45 = 0 ;
if ( ( unsigned long ) V_9 -> V_11 >= V_5 )
return - V_65 ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
F_27 ( V_2 ) ;
V_13 = F_47 ( F_43 ( V_2 ) , * V_9 ) ;
if ( ! F_42 ( & V_13 ) ) {
V_45 = - V_65 ;
goto error;
}
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 , F_44 ( V_2 -> V_14 , * V_9 ) ) ;
error:
F_24 ( V_2 , true ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
F_45 () ;
return V_45 ;
}
static int F_48 ( void * V_66 )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * V_67 , * V_68 ;
unsigned long V_44 ;
V_67 = (struct V_20 * ) V_66 ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
F_27 ( V_2 ) ;
if ( ! V_67 -> V_69 || V_67 -> V_69 ( V_67 ) == 0 ) {
V_68 = V_2 -> clock ;
F_9 ( V_2 , V_67 ) ;
if ( V_68 -> V_70 )
V_68 -> V_70 ( V_68 ) ;
}
F_24 ( V_2 , true ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
return 0 ;
}
void F_49 ( struct V_20 * clock )
{
struct V_1 * V_2 = & V_1 ;
if ( V_2 -> clock == clock )
return;
F_50 ( F_48 , clock , NULL ) ;
F_51 () ;
}
T_4 F_52 ( void )
{
struct V_8 V_61 ;
F_33 ( & V_61 ) ;
return F_7 ( V_61 ) ;
}
void F_53 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
T_3 V_50 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_50 = F_14 ( V_2 ) ;
* V_9 = V_2 -> V_48 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
F_28 ( V_9 , V_50 ) ;
}
int F_54 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
int V_45 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_45 = V_2 -> clock -> V_44 & V_71 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
return V_45 ;
}
V_4 F_55 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
V_4 V_45 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_45 = V_2 -> clock -> V_72 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
return V_45 ;
}
void T_5 F_56 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_20 * clock ;
unsigned long V_44 ;
struct V_8 V_61 , V_73 , V_13 ;
F_57 ( & V_61 ) ;
if ( ! F_42 ( & V_61 ) ) {
F_58 ( L_1
L_2 ) ;
V_61 . V_10 = 0 ;
V_61 . V_11 = 0 ;
} else if ( V_61 . V_10 || V_61 . V_11 )
V_74 = true ;
F_59 ( & V_73 ) ;
if ( ! F_42 ( & V_73 ) ) {
F_58 ( L_3
L_2 ) ;
V_73 . V_10 = 0 ;
V_73 . V_11 = 0 ;
}
F_60 ( & V_2 -> V_46 ) ;
F_61 () ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
clock = F_62 () ;
if ( clock -> V_69 )
clock -> V_69 ( clock ) ;
F_9 ( V_2 , clock ) ;
F_2 ( V_2 , & V_61 ) ;
V_2 -> V_48 . V_10 = 0 ;
V_2 -> V_48 . V_11 = 0 ;
if ( V_73 . V_10 == 0 && V_73 . V_11 == 0 )
V_73 = F_43 ( V_2 ) ;
F_5 ( & V_13 , - V_73 . V_10 , - V_73 . V_11 ) ;
F_4 ( V_2 , V_13 ) ;
V_13 . V_10 = 0 ;
V_13 . V_11 = 0 ;
F_8 ( V_2 , V_13 ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_8 * V_75 )
{
if ( ! F_42 ( V_75 ) ) {
F_64 ( V_76 L_4
L_5 ) ;
return;
}
F_3 ( V_2 , V_75 ) ;
F_4 ( V_2 , F_44 ( V_2 -> V_14 , * V_75 ) ) ;
F_8 ( V_2 , F_47 ( V_2 -> V_19 , * V_75 ) ) ;
}
void F_65 ( struct V_8 * V_75 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_44 ;
if ( F_66 () )
return;
F_19 ( & V_2 -> V_46 , V_44 ) ;
F_27 ( V_2 ) ;
F_63 ( V_2 , V_75 ) ;
F_24 ( V_2 , true ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
F_45 () ;
}
static void F_67 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_44 ;
struct V_8 V_9 ;
F_57 ( & V_9 ) ;
F_68 () ;
F_69 () ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
if ( F_70 ( & V_9 , & V_77 ) > 0 ) {
V_9 = F_44 ( V_9 , V_77 ) ;
F_63 ( V_2 , & V_9 ) ;
}
V_2 -> clock -> V_24 = V_2 -> clock -> V_25 ( V_2 -> clock ) ;
V_2 -> V_33 = 0 ;
V_51 = 0 ;
F_24 ( V_2 , false ) ;
F_21 ( & V_2 -> V_46 , V_44 ) ;
F_71 () ;
F_72 ( V_78 , NULL ) ;
F_73 () ;
}
static int F_74 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_44 ;
struct V_8 V_75 , V_79 ;
static struct V_8 V_80 ;
F_57 ( & V_77 ) ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
F_27 ( V_2 ) ;
V_51 = 1 ;
V_75 = F_44 ( F_43 ( V_2 ) , V_77 ) ;
V_79 = F_44 ( V_75 , V_80 ) ;
if ( abs ( V_79 . V_10 ) >= 2 ) {
V_80 = V_75 ;
} else {
V_77 =
F_47 ( V_77 , V_79 ) ;
}
F_21 ( & V_2 -> V_46 , V_44 ) ;
F_72 ( V_81 , NULL ) ;
F_75 () ;
F_76 () ;
return 0 ;
}
static int T_5 F_77 ( void )
{
F_78 ( & V_82 ) ;
return 0 ;
}
static T_6 int F_79 ( struct V_1 * V_2 ,
T_3 error , T_3 * V_21 ,
T_3 * V_83 )
{
T_3 V_84 , V_85 ;
T_2 V_86 , V_87 ;
T_7 V_88 , V_27 ;
V_88 = V_2 -> V_33 >> ( V_35 + 22 - 2 * V_89 ) ;
V_88 = abs ( V_88 ) ;
for ( V_86 = 0 ; V_88 > 0 ; V_86 ++ )
V_88 >>= 2 ;
V_84 = F_80 () >> ( V_2 -> V_34 + 1 ) ;
V_84 -= V_2 -> V_29 >> 1 ;
error = ( ( error - V_84 ) >> V_86 ) + V_84 ;
V_85 = * V_21 ;
V_27 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_21 = - * V_21 ;
* V_83 = - * V_83 ;
V_27 = - 1 ;
}
for ( V_87 = 0 ; error > V_85 ; V_87 ++ )
error >>= 1 ;
* V_21 <<= V_87 ;
* V_83 <<= V_87 ;
return V_27 << V_87 ;
}
static void F_81 ( struct V_1 * V_2 , T_3 V_83 )
{
T_3 error , V_21 = V_2 -> V_28 ;
int V_87 ;
error = V_2 -> V_33 >> ( V_2 -> V_34 - 1 ) ;
if ( error > V_21 ) {
error >>= 2 ;
if ( F_12 ( error <= V_21 ) )
V_87 = 1 ;
else
V_87 = F_79 ( V_2 , error , & V_21 , & V_83 ) ;
} else {
if ( error < - V_21 ) {
error >>= 2 ;
if ( F_12 ( error >= - V_21 ) ) {
V_87 = - 1 ;
V_21 = - V_21 ;
V_83 = - V_83 ;
} else {
V_87 = F_79 ( V_2 , error , & V_21 , & V_83 ) ;
}
} else {
goto V_90;
}
}
if ( F_32 ( V_2 -> clock -> V_91 &&
( V_2 -> V_27 + V_87 > V_2 -> clock -> V_27 + V_2 -> clock -> V_91 ) ) ) {
F_82 ( V_76
L_6 ,
V_2 -> clock -> V_92 , ( long ) V_2 -> V_27 + V_87 ,
( long ) V_2 -> clock -> V_27 + V_2 -> clock -> V_91 ) ;
}
V_2 -> V_27 += V_87 ;
V_2 -> V_29 += V_21 ;
V_2 -> V_3 -= V_83 ;
V_2 -> V_33 -= ( V_21 - V_83 ) << V_2 -> V_34 ;
V_90:
if ( F_32 ( ( T_3 ) V_2 -> V_3 < 0 ) ) {
T_3 V_93 = - ( T_3 ) V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_33 += V_93 << V_2 -> V_34 ;
}
}
static inline void F_83 ( struct V_1 * V_2 )
{
V_4 V_94 = ( V_4 ) V_5 << V_2 -> V_6 ;
while ( V_2 -> V_3 >= V_94 ) {
int V_95 ;
V_2 -> V_3 -= V_94 ;
V_2 -> V_7 ++ ;
V_95 = F_84 ( V_2 -> V_7 ) ;
if ( F_32 ( V_95 ) ) {
struct V_8 V_9 ;
V_2 -> V_7 += V_95 ;
V_9 . V_10 = V_95 ;
V_9 . V_11 = 0 ;
F_4 ( V_2 ,
F_44 ( V_2 -> V_14 , V_9 ) ) ;
F_85 () ;
}
}
}
static T_1 F_86 ( struct V_1 * V_2 , T_1 V_83 ,
T_2 V_6 )
{
V_4 V_96 ;
if ( V_83 < V_2 -> V_28 << V_6 )
return V_83 ;
V_83 -= V_2 -> V_28 << V_6 ;
V_2 -> clock -> V_24 += V_2 -> V_28 << V_6 ;
V_2 -> V_3 += V_2 -> V_29 << V_6 ;
F_83 ( V_2 ) ;
V_96 = ( V_4 ) V_2 -> V_31 << V_6 ;
V_96 += V_2 -> V_48 . V_11 ;
if ( V_96 >= V_5 ) {
V_4 V_97 = V_96 ;
V_96 = F_10 ( V_97 , V_5 ) ;
V_2 -> V_48 . V_10 += V_97 ;
}
V_2 -> V_48 . V_11 = V_96 ;
V_2 -> V_33 += F_80 () << V_6 ;
V_2 -> V_33 -= ( V_2 -> V_29 + V_2 -> V_30 ) <<
( V_2 -> V_34 + V_6 ) ;
return V_83 ;
}
static inline void F_87 ( struct V_1 * V_2 )
{
T_3 V_98 ;
V_98 = V_2 -> V_3 & ( ( 1ULL << V_2 -> V_6 ) - 1 ) ;
V_2 -> V_3 -= V_98 ;
V_2 -> V_3 += 1ULL << V_2 -> V_6 ;
V_2 -> V_33 += V_98 << V_2 -> V_34 ;
}
static void F_88 ( void )
{
struct V_20 * clock ;
struct V_1 * V_2 = & V_1 ;
T_1 V_83 ;
int V_6 = 0 , V_99 ;
unsigned long V_44 ;
F_19 ( & V_2 -> V_46 , V_44 ) ;
if ( F_32 ( V_51 ) )
goto V_100;
clock = V_2 -> clock ;
#ifdef F_89
V_83 = V_2 -> V_28 ;
#else
V_83 = ( clock -> V_25 ( clock ) - clock -> V_24 ) & clock -> V_40 ;
#endif
if ( V_83 < V_2 -> V_28 )
goto V_100;
V_6 = F_90 ( V_83 ) - F_90 ( V_2 -> V_28 ) ;
V_6 = F_91 ( 0 , V_6 ) ;
V_99 = ( 64 - ( F_90 ( F_80 () ) + 1 ) ) - 1 ;
V_6 = F_92 ( V_6 , V_99 ) ;
while ( V_83 >= V_2 -> V_28 ) {
V_83 = F_86 ( V_2 , V_83 , V_6 ) ;
if ( V_83 < V_2 -> V_28 << V_6 )
V_6 -- ;
}
F_81 ( V_2 , V_83 ) ;
F_87 ( V_2 ) ;
F_83 ( V_2 ) ;
F_24 ( V_2 , false ) ;
V_100:
F_21 ( & V_2 -> V_46 , V_44 ) ;
}
void F_93 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_101 = {
. V_10 = V_2 -> V_14 . V_10 +
V_2 -> V_19 . V_10 ,
. V_11 = V_2 -> V_14 . V_11 +
V_2 -> V_19 . V_11
} ;
F_5 ( V_9 , - V_101 . V_10 , - V_101 . V_11 ) ;
}
void F_94 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_54 , V_102 ;
T_3 V_39 ;
unsigned int V_49 ;
F_34 ( V_51 ) ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_39 = F_13 ( V_2 ) ;
V_54 = V_2 -> V_14 ;
V_102 = V_2 -> V_19 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
V_9 -> V_10 += V_54 . V_10 + V_102 . V_10 ;
V_9 -> V_11 = 0 ;
F_28 ( V_9 , V_39 + V_54 . V_11 + V_102 . V_11 ) ;
}
T_4 F_95 ( void )
{
struct V_8 V_9 ;
F_94 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_96 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
* V_9 = F_47 ( * V_9 , V_2 -> V_19 ) ;
}
unsigned long F_97 ( void )
{
struct V_1 * V_2 = & V_1 ;
return V_2 -> V_7 ;
}
struct V_8 F_98 ( void )
{
struct V_1 * V_2 = & V_1 ;
return F_43 ( V_2 ) ;
}
struct V_8 F_99 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_61 ;
unsigned long V_49 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_61 = F_43 ( V_2 ) ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
return V_61 ;
}
struct V_8 F_100 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_61 , V_103 ;
unsigned long V_49 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_61 = F_43 ( V_2 ) ;
V_103 = V_2 -> V_14 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
F_5 ( & V_61 , V_61 . V_10 + V_103 . V_10 ,
V_61 . V_11 + V_103 . V_11 ) ;
return V_61 ;
}
void F_101 ( unsigned long V_104 )
{
V_105 += V_104 ;
F_88 () ;
F_102 ( V_104 ) ;
}
void F_103 ( struct V_8 * V_106 ,
struct V_8 * V_107 , struct V_8 * V_102 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
* V_106 = F_43 ( V_2 ) ;
* V_107 = V_2 -> V_14 ;
* V_102 = V_2 -> V_19 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
}
T_4 F_104 ( T_4 * V_15 , T_4 * V_18 )
{
struct V_1 * V_2 = & V_1 ;
T_4 V_61 ;
unsigned int V_49 ;
V_4 V_53 , V_50 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_53 = V_2 -> V_7 ;
V_50 = F_13 ( V_2 ) ;
* V_15 = V_2 -> V_15 ;
* V_18 = V_2 -> V_18 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
V_61 = F_36 ( F_37 ( V_53 , 0 ) , V_50 ) ;
V_61 = F_105 ( V_61 , * V_15 ) ;
return V_61 ;
}
T_4 F_106 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_49 ;
struct V_8 V_107 ;
do {
V_49 = F_30 ( & V_2 -> V_46 ) ;
V_107 = V_2 -> V_14 ;
} while ( F_31 ( & V_2 -> V_46 , V_49 ) );
return F_7 ( V_107 ) ;
}
void F_107 ( unsigned long V_104 )
{
F_108 ( & V_108 ) ;
F_101 ( V_104 ) ;
F_109 ( & V_108 ) ;
}
