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
V_2 -> V_17 = F_8 ( V_2 -> V_15 , F_9 ( V_2 -> V_18 , 0 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_8 V_19 )
{
F_6 ( V_2 -> V_20 . V_16 != F_7 ( V_2 -> V_21 ) . V_16 ) ;
V_2 -> V_21 = V_19 ;
V_2 -> V_20 = F_7 ( V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_22 * clock )
{
T_1 V_23 ;
V_4 V_13 , V_24 ;
struct V_22 * V_25 ;
V_25 = V_2 -> clock ;
V_2 -> clock = clock ;
V_2 -> V_26 = clock -> V_26 = clock -> V_27 ( clock ) ;
V_13 = V_28 ;
V_13 <<= clock -> V_6 ;
V_24 = V_13 ;
V_13 += clock -> V_29 / 2 ;
F_12 ( V_13 , clock -> V_29 ) ;
if ( V_13 == 0 )
V_13 = 1 ;
V_23 = ( T_1 ) V_13 ;
V_2 -> V_30 = V_23 ;
V_2 -> V_31 = ( V_4 ) V_23 * clock -> V_29 ;
V_2 -> V_32 = V_24 - V_2 -> V_31 ;
V_2 -> V_33 =
( ( V_4 ) V_23 * clock -> V_29 ) >> clock -> V_6 ;
if ( V_25 ) {
int V_34 = clock -> V_6 - V_25 -> V_6 ;
if ( V_34 < 0 )
V_2 -> V_3 >>= - V_34 ;
else
V_2 -> V_3 <<= V_34 ;
}
V_2 -> V_6 = clock -> V_6 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = V_37 - clock -> V_6 ;
V_2 -> V_29 = clock -> V_29 ;
}
T_2 F_13 ( void )
{
if ( F_14 ( V_38 ) )
return V_38 () ;
return 0 ;
}
static inline T_2 F_13 ( void ) { return 0 ; }
static inline T_3 F_15 ( struct V_1 * V_2 )
{
T_1 V_39 , V_40 ;
struct V_22 * clock ;
T_3 V_41 ;
clock = V_2 -> clock ;
V_39 = clock -> V_27 ( clock ) ;
V_40 = ( V_39 - clock -> V_26 ) & clock -> V_42 ;
V_41 = V_40 * V_2 -> V_29 + V_2 -> V_3 ;
V_41 >>= V_2 -> V_6 ;
return V_41 + F_13 () ;
}
static inline T_3 F_16 ( struct V_1 * V_2 )
{
T_1 V_39 , V_40 ;
struct V_22 * clock ;
T_3 V_41 ;
clock = V_2 -> clock ;
V_39 = clock -> V_27 ( clock ) ;
V_40 = ( V_39 - clock -> V_26 ) & clock -> V_42 ;
V_41 = F_17 ( V_40 , clock -> V_29 , clock -> V_6 ) ;
return V_41 + F_13 () ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_43 , 0 , V_2 ) ;
}
int F_20 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_46 ;
int V_47 ;
F_21 ( & V_48 , V_46 ) ;
V_47 = F_22 ( & V_43 , V_45 ) ;
F_18 ( V_2 ) ;
F_23 ( & V_48 , V_46 ) ;
return V_47 ;
}
int F_24 ( struct V_44 * V_45 )
{
unsigned long V_46 ;
int V_47 ;
F_21 ( & V_48 , V_46 ) ;
V_47 = F_25 ( & V_43 , V_45 ) ;
F_23 ( & V_48 , V_46 ) ;
return V_47 ;
}
static void F_26 ( struct V_1 * V_2 , bool V_49 , bool V_50 )
{
if ( V_49 ) {
V_2 -> V_35 = 0 ;
F_27 () ;
}
F_28 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( V_50 )
memcpy ( & V_51 , & V_1 , sizeof( V_1 ) ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_39 , V_40 ;
struct V_22 * clock ;
T_3 V_41 ;
clock = V_2 -> clock ;
V_39 = clock -> V_27 ( clock ) ;
V_40 = ( V_39 - clock -> V_26 ) & clock -> V_42 ;
V_2 -> V_26 = clock -> V_26 = V_39 ;
V_2 -> V_3 += V_40 * V_2 -> V_29 ;
V_2 -> V_3 += ( V_4 ) F_13 () << V_2 -> V_6 ;
F_1 ( V_2 ) ;
V_41 = F_17 ( V_40 , clock -> V_29 , clock -> V_6 ) ;
F_30 ( & V_2 -> V_52 , V_41 ) ;
}
int F_31 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
T_3 V_54 = 0 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_54 = F_15 ( V_2 ) ;
} while ( F_33 ( & V_55 , V_53 ) );
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_54 ) ;
if ( F_34 ( V_56 ) )
return - V_57 ;
return 0 ;
}
void F_35 ( struct V_8 * V_9 )
{
F_36 ( F_31 ( V_9 ) ) ;
}
T_4 F_37 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_53 ;
T_3 V_58 , V_54 ;
F_36 ( V_56 ) ;
do {
V_53 = F_32 ( & V_55 ) ;
V_58 = V_2 -> V_7 + V_2 -> V_14 . V_10 ;
V_54 = F_15 ( V_2 ) + V_2 -> V_14 . V_11 ;
} while ( F_33 ( & V_55 , V_53 ) );
return F_38 ( F_9 ( V_58 , 0 ) , V_54 ) ;
}
void F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_59 ;
T_3 V_41 ;
unsigned int V_53 ;
F_36 ( V_56 ) ;
do {
V_53 = F_32 ( & V_55 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_41 = F_15 ( V_2 ) ;
V_59 = V_2 -> V_14 ;
} while ( F_33 ( & V_55 , V_53 ) );
V_9 -> V_10 += V_59 . V_10 ;
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_41 + V_59 . V_11 ) ;
}
void F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
V_4 V_54 ;
F_36 ( V_56 ) ;
do {
V_53 = F_32 ( & V_55 ) ;
V_9 -> V_10 = V_2 -> V_7 + V_2 -> V_18 ;
V_54 = F_15 ( V_2 ) ;
} while ( F_33 ( & V_55 , V_53 ) );
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_54 ) ;
}
T_4 F_41 ( void )
{
struct V_8 V_9 ;
F_40 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_42 ( struct V_8 * V_60 , struct V_8 * V_61 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
T_3 V_62 , V_63 ;
F_6 ( V_56 ) ;
do {
V_53 = F_32 ( & V_55 ) ;
* V_60 = V_2 -> V_52 ;
V_61 -> V_10 = V_2 -> V_7 ;
V_61 -> V_11 = 0 ;
V_62 = F_16 ( V_2 ) ;
V_63 = F_15 ( V_2 ) ;
} while ( F_33 ( & V_55 , V_53 ) );
F_30 ( V_60 , V_62 ) ;
F_30 ( V_61 , V_63 ) ;
}
void F_43 ( struct V_64 * V_65 )
{
struct V_8 V_66 ;
F_35 ( & V_66 ) ;
V_65 -> V_10 = V_66 . V_10 ;
V_65 -> V_67 = V_66 . V_11 / 1000 ;
}
int F_44 ( const struct V_8 * V_65 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_68 , V_69 ;
unsigned long V_46 ;
if ( ! F_45 ( V_65 ) )
return - V_70 ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_29 ( V_2 ) ;
V_69 = F_47 ( V_2 ) ;
V_68 . V_10 = V_65 -> V_10 - V_69 . V_10 ;
V_68 . V_11 = V_65 -> V_11 - V_69 . V_11 ;
F_4 ( V_2 , F_48 ( V_2 -> V_14 , V_68 ) ) ;
F_2 ( V_2 , V_65 ) ;
F_26 ( V_2 , true , true ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
F_50 () ;
return 0 ;
}
int F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_46 ;
struct V_8 V_13 ;
int V_47 = 0 ;
if ( ( unsigned long ) V_9 -> V_11 >= V_5 )
return - V_70 ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_29 ( V_2 ) ;
V_13 = F_52 ( F_47 ( V_2 ) , * V_9 ) ;
if ( ! F_45 ( & V_13 ) ) {
V_47 = - V_70 ;
goto error;
}
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 , F_48 ( V_2 -> V_14 , * V_9 ) ) ;
error:
F_26 ( V_2 , true , true ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
F_50 () ;
return V_47 ;
}
T_5 F_53 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_53 ;
T_5 V_47 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_47 = V_2 -> V_18 ;
} while ( F_33 ( & V_55 , V_53 ) );
return V_47 ;
}
static void F_54 ( struct V_1 * V_2 , T_5 V_18 )
{
V_2 -> V_18 = V_18 ;
V_2 -> V_17 = F_8 ( V_2 -> V_15 , F_9 ( V_18 , 0 ) ) ;
}
void F_55 ( T_5 V_18 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_46 ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_54 ( V_2 , V_18 ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
F_50 () ;
}
static int F_56 ( void * V_71 )
{
struct V_1 * V_2 = & V_1 ;
struct V_22 * V_72 , * V_73 ;
unsigned long V_46 ;
V_72 = (struct V_22 * ) V_71 ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_29 ( V_2 ) ;
if ( ! V_72 -> V_74 || V_72 -> V_74 ( V_72 ) == 0 ) {
V_73 = V_2 -> clock ;
F_11 ( V_2 , V_72 ) ;
if ( V_73 -> V_75 )
V_73 -> V_75 ( V_73 ) ;
}
F_26 ( V_2 , true , true ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
return 0 ;
}
void F_57 ( struct V_22 * clock )
{
struct V_1 * V_2 = & V_1 ;
if ( V_2 -> clock == clock )
return;
F_58 ( F_56 , clock , NULL ) ;
F_59 () ;
}
T_4 F_60 ( void )
{
struct V_8 V_66 ;
F_35 ( & V_66 ) ;
return F_7 ( V_66 ) ;
}
void F_61 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
T_3 V_54 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_54 = F_16 ( V_2 ) ;
* V_9 = V_2 -> V_52 ;
} while ( F_33 ( & V_55 , V_53 ) );
F_30 ( V_9 , V_54 ) ;
}
int F_62 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
int V_47 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_47 = V_2 -> clock -> V_46 & V_76 ;
} while ( F_33 ( & V_55 , V_53 ) );
return V_47 ;
}
V_4 F_63 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
V_4 V_47 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_47 = V_2 -> clock -> V_77 ;
} while ( F_33 ( & V_55 , V_53 ) );
return V_47 ;
}
void T_6 F_64 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_22 * clock ;
unsigned long V_46 ;
struct V_8 V_66 , V_78 , V_13 ;
F_65 ( & V_66 ) ;
if ( ! F_45 ( & V_66 ) ) {
F_66 ( L_1
L_2 ) ;
V_66 . V_10 = 0 ;
V_66 . V_11 = 0 ;
} else if ( V_66 . V_10 || V_66 . V_11 )
V_79 = true ;
F_67 ( & V_78 ) ;
if ( ! F_45 ( & V_78 ) ) {
F_66 ( L_3
L_2 ) ;
V_78 . V_10 = 0 ;
V_78 . V_11 = 0 ;
}
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_68 () ;
clock = F_69 () ;
if ( clock -> V_74 )
clock -> V_74 ( clock ) ;
F_11 ( V_2 , clock ) ;
F_2 ( V_2 , & V_66 ) ;
V_2 -> V_52 . V_10 = 0 ;
V_2 -> V_52 . V_11 = 0 ;
if ( V_78 . V_10 == 0 && V_78 . V_11 == 0 )
V_78 = F_47 ( V_2 ) ;
F_5 ( & V_13 , - V_78 . V_10 , - V_78 . V_11 ) ;
F_4 ( V_2 , V_13 ) ;
V_13 . V_10 = 0 ;
V_13 . V_11 = 0 ;
F_10 ( V_2 , V_13 ) ;
memcpy ( & V_51 , & V_1 , sizeof( V_1 ) ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_8 * V_80 )
{
if ( ! F_45 ( V_80 ) ) {
F_71 ( V_81 L_4
L_5 ) ;
return;
}
F_3 ( V_2 , V_80 ) ;
F_4 ( V_2 , F_48 ( V_2 -> V_14 , * V_80 ) ) ;
F_10 ( V_2 , F_52 ( V_2 -> V_21 , * V_80 ) ) ;
}
void F_72 ( struct V_8 * V_80 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_46 ;
if ( F_73 () )
return;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_29 ( V_2 ) ;
F_70 ( V_2 , V_80 ) ;
F_26 ( V_2 , true , true ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
F_50 () ;
}
static void F_74 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_22 * clock = V_2 -> clock ;
unsigned long V_46 ;
struct V_8 V_82 , V_68 ;
T_1 V_39 , V_40 ;
bool V_83 = false ;
F_65 ( & V_82 ) ;
F_75 () ;
F_76 () ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
V_39 = clock -> V_27 ( clock ) ;
if ( ( clock -> V_46 & V_84 ) &&
V_39 > clock -> V_26 ) {
V_4 V_85 , V_86 = V_87 ;
T_2 V_29 = clock -> V_29 ;
T_2 V_6 = clock -> V_6 ;
T_3 V_41 = 0 ;
V_40 = ( V_39 - clock -> V_26 ) & clock -> V_42 ;
F_12 ( V_86 , V_29 ) ;
if ( V_40 > V_86 ) {
V_85 = F_77 ( V_40 , V_86 ) ;
V_41 = ( ( ( V_4 ) V_86 * V_29 ) >> V_6 ) * V_85 ;
V_40 -= V_85 * V_86 ;
}
V_41 += ( ( V_4 ) V_40 * V_29 ) >> V_6 ;
V_68 = F_78 ( V_41 ) ;
V_83 = true ;
} else if ( F_79 ( & V_82 , & V_88 ) > 0 ) {
V_68 = F_48 ( V_82 , V_88 ) ;
V_83 = true ;
}
if ( V_83 )
F_70 ( V_2 , & V_68 ) ;
V_2 -> V_26 = clock -> V_26 = V_39 ;
V_2 -> V_35 = 0 ;
V_56 = 0 ;
F_26 ( V_2 , false , true ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
F_80 () ;
F_81 ( V_89 , NULL ) ;
F_82 () ;
}
static int F_83 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_46 ;
struct V_8 V_80 , V_90 ;
static struct V_8 V_91 ;
F_65 ( & V_88 ) ;
if ( V_88 . V_10 || V_88 . V_11 )
V_79 = true ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_29 ( V_2 ) ;
V_56 = 1 ;
V_80 = F_48 ( F_47 ( V_2 ) , V_88 ) ;
V_90 = F_48 ( V_80 , V_91 ) ;
if ( abs ( V_90 . V_10 ) >= 2 ) {
V_91 = V_80 ;
} else {
V_88 =
F_52 ( V_88 , V_90 ) ;
}
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
F_81 ( V_92 , NULL ) ;
F_84 () ;
F_85 () ;
return 0 ;
}
static int T_6 F_86 ( void )
{
F_87 ( & V_93 ) ;
return 0 ;
}
static T_7 int F_88 ( struct V_1 * V_2 ,
T_3 error , T_3 * V_23 ,
T_3 * V_94 )
{
T_3 V_95 , V_96 ;
T_2 V_97 , V_98 ;
T_5 V_99 , V_29 ;
V_99 = V_2 -> V_35 >> ( V_37 + 22 - 2 * V_100 ) ;
V_99 = abs ( V_99 ) ;
for ( V_97 = 0 ; V_99 > 0 ; V_97 ++ )
V_99 >>= 2 ;
V_95 = F_89 () >> ( V_2 -> V_36 + 1 ) ;
V_95 -= V_2 -> V_31 >> 1 ;
error = ( ( error - V_95 ) >> V_97 ) + V_95 ;
V_96 = * V_23 ;
V_29 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_23 = - * V_23 ;
* V_94 = - * V_94 ;
V_29 = - 1 ;
}
for ( V_98 = 0 ; error > V_96 ; V_98 ++ )
error >>= 1 ;
* V_23 <<= V_98 ;
* V_94 <<= V_98 ;
return V_29 << V_98 ;
}
static void F_90 ( struct V_1 * V_2 , T_3 V_94 )
{
T_3 error , V_23 = V_2 -> V_30 ;
int V_98 ;
error = V_2 -> V_35 >> ( V_2 -> V_36 - 1 ) ;
if ( error > V_23 ) {
error >>= 2 ;
if ( F_14 ( error <= V_23 ) )
V_98 = 1 ;
else
V_98 = F_88 ( V_2 , error , & V_23 , & V_94 ) ;
} else {
if ( error < - V_23 ) {
error >>= 2 ;
if ( F_14 ( error >= - V_23 ) ) {
V_98 = - 1 ;
V_23 = - V_23 ;
V_94 = - V_94 ;
} else {
V_98 = F_88 ( V_2 , error , & V_23 , & V_94 ) ;
}
} else {
goto V_101;
}
}
if ( F_34 ( V_2 -> clock -> V_102 &&
( V_2 -> V_29 + V_98 > V_2 -> clock -> V_29 + V_2 -> clock -> V_102 ) ) ) {
F_91 ( V_81
L_6 ,
V_2 -> clock -> V_103 , ( long ) V_2 -> V_29 + V_98 ,
( long ) V_2 -> clock -> V_29 + V_2 -> clock -> V_102 ) ;
}
V_2 -> V_29 += V_98 ;
V_2 -> V_31 += V_23 ;
V_2 -> V_3 -= V_94 ;
V_2 -> V_35 -= ( V_23 - V_94 ) << V_2 -> V_36 ;
V_101:
if ( F_34 ( ( T_3 ) V_2 -> V_3 < 0 ) ) {
T_3 V_104 = - ( T_3 ) V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_35 += V_104 << V_2 -> V_36 ;
}
}
static inline void F_92 ( struct V_1 * V_2 )
{
V_4 V_105 = ( V_4 ) V_5 << V_2 -> V_6 ;
while ( V_2 -> V_3 >= V_105 ) {
int V_106 ;
V_2 -> V_3 -= V_105 ;
V_2 -> V_7 ++ ;
V_106 = F_93 ( V_2 -> V_7 ) ;
if ( F_34 ( V_106 ) ) {
struct V_8 V_9 ;
V_2 -> V_7 += V_106 ;
V_9 . V_10 = V_106 ;
V_9 . V_11 = 0 ;
F_4 ( V_2 ,
F_48 ( V_2 -> V_14 , V_9 ) ) ;
F_54 ( V_2 , V_2 -> V_18 - V_106 ) ;
F_94 () ;
}
}
}
static T_1 F_95 ( struct V_1 * V_2 , T_1 V_94 ,
T_2 V_6 )
{
T_1 V_23 = V_2 -> V_30 << V_6 ;
V_4 V_107 ;
if ( V_94 < V_23 )
return V_94 ;
V_94 -= V_23 ;
V_2 -> V_26 += V_23 ;
V_2 -> V_3 += V_2 -> V_31 << V_6 ;
F_92 ( V_2 ) ;
V_107 = ( V_4 ) V_2 -> V_33 << V_6 ;
V_107 += V_2 -> V_52 . V_11 ;
if ( V_107 >= V_5 ) {
V_4 V_108 = V_107 ;
V_107 = F_12 ( V_108 , V_5 ) ;
V_2 -> V_52 . V_10 += V_108 ;
}
V_2 -> V_52 . V_11 = V_107 ;
V_2 -> V_35 += F_89 () << V_6 ;
V_2 -> V_35 -= ( V_2 -> V_31 + V_2 -> V_32 ) <<
( V_2 -> V_36 + V_6 ) ;
return V_94 ;
}
static inline void F_96 ( struct V_1 * V_2 )
{
T_3 V_109 ;
V_109 = V_2 -> V_3 & ( ( 1ULL << V_2 -> V_6 ) - 1 ) ;
V_2 -> V_3 -= V_109 ;
V_2 -> V_3 += 1ULL << V_2 -> V_6 ;
V_2 -> V_35 += V_109 << V_2 -> V_36 ;
}
static void F_97 ( void )
{
struct V_22 * clock ;
struct V_1 * V_110 = & V_1 ;
struct V_1 * V_2 = & V_51 ;
T_1 V_94 ;
int V_6 = 0 , V_111 ;
unsigned long V_46 ;
F_21 ( & V_48 , V_46 ) ;
if ( F_34 ( V_56 ) )
goto V_112;
clock = V_110 -> clock ;
#ifdef F_98
V_94 = V_110 -> V_30 ;
#else
V_94 = ( clock -> V_27 ( clock ) - clock -> V_26 ) & clock -> V_42 ;
#endif
if ( V_94 < V_110 -> V_30 )
goto V_112;
V_6 = F_99 ( V_94 ) - F_99 ( V_2 -> V_30 ) ;
V_6 = V_86 ( 0 , V_6 ) ;
V_111 = ( 64 - ( F_99 ( F_89 () ) + 1 ) ) - 1 ;
V_6 = F_100 ( V_6 , V_111 ) ;
while ( V_94 >= V_2 -> V_30 ) {
V_94 = F_95 ( V_2 , V_94 , V_6 ) ;
if ( V_94 < V_2 -> V_30 << V_6 )
V_6 -- ;
}
F_90 ( V_2 , V_94 ) ;
F_96 ( V_2 ) ;
F_92 ( V_2 ) ;
F_46 ( & V_55 ) ;
clock -> V_26 = V_2 -> V_26 ;
memcpy ( V_110 , V_2 , sizeof( * V_2 ) ) ;
F_26 ( V_110 , false , false ) ;
F_49 ( & V_55 ) ;
V_112:
F_23 ( & V_48 , V_46 ) ;
}
void F_101 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_113 = {
. V_10 = V_2 -> V_14 . V_10 +
V_2 -> V_21 . V_10 ,
. V_11 = V_2 -> V_14 . V_11 +
V_2 -> V_21 . V_11
} ;
F_5 ( V_9 , - V_113 . V_10 , - V_113 . V_11 ) ;
}
void F_102 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_59 , V_114 ;
T_3 V_41 ;
unsigned int V_53 ;
F_36 ( V_56 ) ;
do {
V_53 = F_32 ( & V_55 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_41 = F_15 ( V_2 ) ;
V_59 = V_2 -> V_14 ;
V_114 = V_2 -> V_21 ;
} while ( F_33 ( & V_55 , V_53 ) );
V_9 -> V_10 += V_59 . V_10 + V_114 . V_10 ;
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_41 + V_59 . V_11 + V_114 . V_11 ) ;
}
T_4 F_103 ( void )
{
struct V_8 V_9 ;
F_102 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_104 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
* V_9 = F_52 ( * V_9 , V_2 -> V_21 ) ;
}
unsigned long F_105 ( void )
{
struct V_1 * V_2 = & V_1 ;
return V_2 -> V_7 ;
}
struct V_8 F_106 ( void )
{
struct V_1 * V_2 = & V_1 ;
return F_47 ( V_2 ) ;
}
struct V_8 F_107 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_66 ;
unsigned long V_53 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_66 = F_47 ( V_2 ) ;
} while ( F_33 ( & V_55 , V_53 ) );
return V_66 ;
}
struct V_8 F_108 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_66 , V_115 ;
unsigned long V_53 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_66 = F_47 ( V_2 ) ;
V_115 = V_2 -> V_14 ;
} while ( F_33 ( & V_55 , V_53 ) );
F_5 ( & V_66 , V_66 . V_10 + V_115 . V_10 ,
V_66 . V_11 + V_115 . V_11 ) ;
return V_66 ;
}
void F_109 ( unsigned long V_116 )
{
V_117 += V_116 ;
F_97 () ;
F_110 ( V_116 ) ;
}
void F_111 ( struct V_8 * V_118 ,
struct V_8 * V_119 , struct V_8 * V_114 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
do {
V_53 = F_32 ( & V_55 ) ;
* V_118 = F_47 ( V_2 ) ;
* V_119 = V_2 -> V_14 ;
* V_114 = V_2 -> V_21 ;
} while ( F_33 ( & V_55 , V_53 ) );
}
T_4 F_112 ( T_4 * V_15 , T_4 * V_20 ,
T_4 * V_17 )
{
struct V_1 * V_2 = & V_1 ;
T_4 V_66 ;
unsigned int V_53 ;
V_4 V_58 , V_54 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_58 = V_2 -> V_7 ;
V_54 = F_15 ( V_2 ) ;
* V_15 = V_2 -> V_15 ;
* V_20 = V_2 -> V_20 ;
* V_17 = V_2 -> V_17 ;
} while ( F_33 ( & V_55 , V_53 ) );
V_66 = F_38 ( F_9 ( V_58 , 0 ) , V_54 ) ;
V_66 = F_8 ( V_66 , * V_15 ) ;
return V_66 ;
}
T_4 F_113 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_53 ;
struct V_8 V_119 ;
do {
V_53 = F_32 ( & V_55 ) ;
V_119 = V_2 -> V_14 ;
} while ( F_33 ( & V_55 , V_53 ) );
return F_7 ( V_119 ) ;
}
int F_114 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_46 ;
struct V_8 V_9 ;
T_5 V_122 , V_123 ;
int V_47 ;
V_47 = F_115 ( V_121 ) ;
if ( V_47 )
return V_47 ;
if ( V_121 -> V_124 & V_125 ) {
struct V_8 V_80 ;
V_80 . V_10 = V_121 -> time . V_10 ;
V_80 . V_11 = V_121 -> time . V_67 ;
if ( ! ( V_121 -> V_124 & V_126 ) )
V_80 . V_11 *= 1000 ;
V_47 = F_51 ( & V_80 ) ;
if ( V_47 )
return V_47 ;
}
F_35 ( & V_9 ) ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
V_122 = V_123 = V_2 -> V_18 ;
V_47 = F_116 ( V_121 , & V_9 , & V_123 ) ;
if ( V_123 != V_122 ) {
F_54 ( V_2 , V_123 ) ;
F_94 () ;
}
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
return V_47 ;
}
void F_117 ( const struct V_8 * V_127 , const struct V_8 * V_128 )
{
unsigned long V_46 ;
F_21 ( & V_48 , V_46 ) ;
F_46 ( & V_55 ) ;
F_118 ( V_127 , V_128 ) ;
F_49 ( & V_55 ) ;
F_23 ( & V_48 , V_46 ) ;
}
void F_119 ( unsigned long V_116 )
{
F_120 ( & V_129 ) ;
F_109 ( V_116 ) ;
F_121 ( & V_129 ) ;
}
