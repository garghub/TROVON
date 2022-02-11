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
static void F_18 ( struct V_1 * V_2 , bool V_43 )
{
F_19 ( & V_44 , V_43 , V_2 ) ;
}
int F_20 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_47 ;
int V_48 ;
F_21 ( & V_49 , V_47 ) ;
V_48 = F_22 ( & V_44 , V_46 ) ;
F_18 ( V_2 , true ) ;
F_23 ( & V_49 , V_47 ) ;
return V_48 ;
}
int F_24 ( struct V_45 * V_46 )
{
unsigned long V_47 ;
int V_48 ;
F_21 ( & V_49 , V_47 ) ;
V_48 = F_25 ( & V_44 , V_46 ) ;
F_23 ( & V_49 , V_47 ) ;
return V_48 ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_50 )
{
if ( V_50 & V_51 ) {
V_2 -> V_35 = 0 ;
F_27 () ;
}
F_28 ( V_2 ) ;
F_18 ( V_2 , V_50 & V_52 ) ;
if ( V_50 & V_53 )
memcpy ( & V_54 , & V_1 , sizeof( V_1 ) ) ;
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
F_30 ( & V_2 -> V_55 , V_41 ) ;
}
int F_31 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
T_3 V_57 = 0 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_57 = F_15 ( V_2 ) ;
} while ( F_33 ( & V_58 , V_56 ) );
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_57 ) ;
if ( F_34 ( V_59 ) )
return - V_60 ;
return 0 ;
}
void F_35 ( struct V_8 * V_9 )
{
F_36 ( F_31 ( V_9 ) ) ;
}
T_4 F_37 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_56 ;
T_3 V_61 , V_57 ;
F_36 ( V_59 ) ;
do {
V_56 = F_32 ( & V_58 ) ;
V_61 = V_2 -> V_7 + V_2 -> V_14 . V_10 ;
V_57 = F_15 ( V_2 ) + V_2 -> V_14 . V_11 ;
} while ( F_33 ( & V_58 , V_56 ) );
return F_38 ( F_9 ( V_61 , 0 ) , V_57 ) ;
}
void F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_62 ;
T_3 V_41 ;
unsigned int V_56 ;
F_36 ( V_59 ) ;
do {
V_56 = F_32 ( & V_58 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_41 = F_15 ( V_2 ) ;
V_62 = V_2 -> V_14 ;
} while ( F_33 ( & V_58 , V_56 ) );
V_9 -> V_10 += V_62 . V_10 ;
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_41 + V_62 . V_11 ) ;
}
void F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
V_4 V_57 ;
F_36 ( V_59 ) ;
do {
V_56 = F_32 ( & V_58 ) ;
V_9 -> V_10 = V_2 -> V_7 + V_2 -> V_18 ;
V_57 = F_15 ( V_2 ) ;
} while ( F_33 ( & V_58 , V_56 ) );
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_57 ) ;
}
T_4 F_41 ( void )
{
struct V_8 V_9 ;
F_40 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_42 ( struct V_8 * V_63 , struct V_8 * V_64 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
T_3 V_65 , V_66 ;
F_6 ( V_59 ) ;
do {
V_56 = F_32 ( & V_58 ) ;
* V_63 = V_2 -> V_55 ;
V_64 -> V_10 = V_2 -> V_7 ;
V_64 -> V_11 = 0 ;
V_65 = F_16 ( V_2 ) ;
V_66 = F_15 ( V_2 ) ;
} while ( F_33 ( & V_58 , V_56 ) );
F_30 ( V_63 , V_65 ) ;
F_30 ( V_64 , V_66 ) ;
}
void F_43 ( struct V_67 * V_68 )
{
struct V_8 V_69 ;
F_35 ( & V_69 ) ;
V_68 -> V_10 = V_69 . V_10 ;
V_68 -> V_70 = V_69 . V_11 / 1000 ;
}
int F_44 ( const struct V_8 * V_68 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_71 , V_72 ;
unsigned long V_47 ;
if ( ! F_45 ( V_68 ) )
return - V_73 ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_29 ( V_2 ) ;
V_72 = F_47 ( V_2 ) ;
V_71 . V_10 = V_68 -> V_10 - V_72 . V_10 ;
V_71 . V_11 = V_68 -> V_11 - V_72 . V_11 ;
F_4 ( V_2 , F_48 ( V_2 -> V_14 , V_71 ) ) ;
F_2 ( V_2 , V_68 ) ;
F_26 ( V_2 , V_51 | V_53 | V_52 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_50 () ;
return 0 ;
}
int F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_47 ;
struct V_8 V_13 ;
int V_48 = 0 ;
if ( ( unsigned long ) V_9 -> V_11 >= V_5 )
return - V_73 ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_29 ( V_2 ) ;
V_13 = F_52 ( F_47 ( V_2 ) , * V_9 ) ;
if ( ! F_45 ( & V_13 ) ) {
V_48 = - V_73 ;
goto error;
}
F_3 ( V_2 , V_9 ) ;
F_4 ( V_2 , F_48 ( V_2 -> V_14 , * V_9 ) ) ;
error:
F_26 ( V_2 , V_51 | V_53 | V_52 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_50 () ;
return V_48 ;
}
T_5 F_53 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned int V_56 ;
T_5 V_48 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_48 = V_2 -> V_18 ;
} while ( F_33 ( & V_58 , V_56 ) );
return V_48 ;
}
static void F_54 ( struct V_1 * V_2 , T_5 V_18 )
{
V_2 -> V_18 = V_18 ;
V_2 -> V_17 = F_8 ( V_2 -> V_15 , F_9 ( V_18 , 0 ) ) ;
}
void F_55 ( T_5 V_18 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_47 ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_54 ( V_2 , V_18 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_50 () ;
}
static int F_56 ( void * V_74 )
{
struct V_1 * V_2 = & V_1 ;
struct V_22 * V_75 , * V_76 ;
unsigned long V_47 ;
V_75 = (struct V_22 * ) V_74 ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_29 ( V_2 ) ;
if ( F_57 ( V_75 -> V_77 ) ) {
if ( ! V_75 -> V_78 || V_75 -> V_78 ( V_75 ) == 0 ) {
V_76 = V_2 -> clock ;
F_11 ( V_2 , V_75 ) ;
if ( V_76 -> V_79 )
V_76 -> V_79 ( V_76 ) ;
F_58 ( V_76 -> V_77 ) ;
} else {
F_58 ( V_75 -> V_77 ) ;
}
}
F_26 ( V_2 , V_51 | V_53 | V_52 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
return 0 ;
}
int F_59 ( struct V_22 * clock )
{
struct V_1 * V_2 = & V_1 ;
if ( V_2 -> clock == clock )
return 0 ;
F_60 ( F_56 , clock , NULL ) ;
F_61 () ;
return V_2 -> clock == clock ? 0 : - 1 ;
}
T_4 F_62 ( void )
{
struct V_8 V_69 ;
F_35 ( & V_69 ) ;
return F_7 ( V_69 ) ;
}
void F_63 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
T_3 V_57 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_57 = F_16 ( V_2 ) ;
* V_9 = V_2 -> V_55 ;
} while ( F_33 ( & V_58 , V_56 ) );
F_30 ( V_9 , V_57 ) ;
}
int F_64 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
int V_48 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_48 = V_2 -> clock -> V_47 & V_80 ;
} while ( F_33 ( & V_58 , V_56 ) );
return V_48 ;
}
V_4 F_65 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
V_4 V_48 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_48 = V_2 -> clock -> V_81 ;
} while ( F_33 ( & V_58 , V_56 ) );
return V_48 ;
}
void T_6 F_66 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_22 * clock ;
unsigned long V_47 ;
struct V_8 V_69 , V_82 , V_13 ;
F_67 ( & V_69 ) ;
if ( ! F_45 ( & V_69 ) ) {
F_68 ( L_1
L_2 ) ;
V_69 . V_10 = 0 ;
V_69 . V_11 = 0 ;
} else if ( V_69 . V_10 || V_69 . V_11 )
V_83 = true ;
F_69 ( & V_82 ) ;
if ( ! F_45 ( & V_82 ) ) {
F_68 ( L_3
L_2 ) ;
V_82 . V_10 = 0 ;
V_82 . V_11 = 0 ;
}
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_70 () ;
clock = F_71 () ;
if ( clock -> V_78 )
clock -> V_78 ( clock ) ;
F_11 ( V_2 , clock ) ;
F_2 ( V_2 , & V_69 ) ;
V_2 -> V_55 . V_10 = 0 ;
V_2 -> V_55 . V_11 = 0 ;
if ( V_82 . V_10 == 0 && V_82 . V_11 == 0 )
V_82 = F_47 ( V_2 ) ;
F_5 ( & V_13 , - V_82 . V_10 , - V_82 . V_11 ) ;
F_4 ( V_2 , V_13 ) ;
V_13 . V_10 = 0 ;
V_13 . V_11 = 0 ;
F_10 ( V_2 , V_13 ) ;
memcpy ( & V_54 , & V_1 , sizeof( V_1 ) ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_8 * V_84 )
{
if ( ! F_45 ( V_84 ) ) {
F_73 ( V_85 L_4
L_5 ) ;
return;
}
F_3 ( V_2 , V_84 ) ;
F_4 ( V_2 , F_48 ( V_2 -> V_14 , * V_84 ) ) ;
F_10 ( V_2 , F_52 ( V_2 -> V_21 , * V_84 ) ) ;
F_74 ( V_84 ) ;
}
void F_75 ( struct V_8 * V_84 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_47 ;
if ( F_76 () )
return;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_29 ( V_2 ) ;
F_72 ( V_2 , V_84 ) ;
F_26 ( V_2 , V_51 | V_53 | V_52 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_50 () ;
}
static void F_77 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_22 * clock = V_2 -> clock ;
unsigned long V_47 ;
struct V_8 V_86 , V_71 ;
T_1 V_39 , V_40 ;
bool V_87 = false ;
F_67 ( & V_86 ) ;
F_78 () ;
F_79 () ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
V_39 = clock -> V_27 ( clock ) ;
if ( ( clock -> V_47 & V_88 ) &&
V_39 > clock -> V_26 ) {
V_4 V_89 , V_90 = V_91 ;
T_2 V_29 = clock -> V_29 ;
T_2 V_6 = clock -> V_6 ;
T_3 V_41 = 0 ;
V_40 = ( V_39 - clock -> V_26 ) & clock -> V_42 ;
F_12 ( V_90 , V_29 ) ;
if ( V_40 > V_90 ) {
V_89 = F_80 ( V_40 , V_90 ) ;
V_41 = ( ( ( V_4 ) V_90 * V_29 ) >> V_6 ) * V_89 ;
V_40 -= V_89 * V_90 ;
}
V_41 += ( ( V_4 ) V_40 * V_29 ) >> V_6 ;
V_71 = F_81 ( V_41 ) ;
V_87 = true ;
} else if ( F_82 ( & V_86 , & V_92 ) > 0 ) {
V_71 = F_48 ( V_86 , V_92 ) ;
V_87 = true ;
}
if ( V_87 )
F_72 ( V_2 , & V_71 ) ;
V_2 -> V_26 = clock -> V_26 = V_39 ;
V_2 -> V_35 = 0 ;
V_59 = 0 ;
F_26 ( V_2 , V_53 | V_52 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_83 () ;
F_84 ( V_93 , NULL ) ;
F_85 () ;
}
static int F_86 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_47 ;
struct V_8 V_84 , V_94 ;
static struct V_8 V_95 ;
F_67 ( & V_92 ) ;
if ( V_92 . V_10 || V_92 . V_11 )
V_83 = true ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_29 ( V_2 ) ;
V_59 = 1 ;
V_84 = F_48 ( F_47 ( V_2 ) , V_92 ) ;
V_94 = F_48 ( V_84 , V_95 ) ;
if ( abs ( V_94 . V_10 ) >= 2 ) {
V_95 = V_84 ;
} else {
V_92 =
F_52 ( V_92 , V_94 ) ;
}
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_84 ( V_96 , NULL ) ;
F_87 () ;
F_88 () ;
return 0 ;
}
static int T_6 F_89 ( void )
{
F_90 ( & V_97 ) ;
return 0 ;
}
static T_7 int F_91 ( struct V_1 * V_2 ,
T_3 error , T_3 * V_23 ,
T_3 * V_98 )
{
T_3 V_99 , V_100 ;
T_2 V_101 , V_102 ;
T_5 V_103 , V_29 ;
V_103 = V_2 -> V_35 >> ( V_37 + 22 - 2 * V_104 ) ;
V_103 = abs ( V_103 ) ;
for ( V_101 = 0 ; V_103 > 0 ; V_101 ++ )
V_103 >>= 2 ;
V_99 = F_92 () >> ( V_2 -> V_36 + 1 ) ;
V_99 -= V_2 -> V_31 >> 1 ;
error = ( ( error - V_99 ) >> V_101 ) + V_99 ;
V_100 = * V_23 ;
V_29 = 1 ;
if ( error < 0 ) {
error = - error ;
* V_23 = - * V_23 ;
* V_98 = - * V_98 ;
V_29 = - 1 ;
}
for ( V_102 = 0 ; error > V_100 ; V_102 ++ )
error >>= 1 ;
* V_23 <<= V_102 ;
* V_98 <<= V_102 ;
return V_29 << V_102 ;
}
static void F_93 ( struct V_1 * V_2 , T_3 V_98 )
{
T_3 error , V_23 = V_2 -> V_30 ;
int V_102 ;
error = V_2 -> V_35 >> ( V_2 -> V_36 - 1 ) ;
if ( error > V_23 ) {
error >>= 2 ;
if ( F_14 ( error <= V_23 ) )
V_102 = 1 ;
else
V_102 = F_91 ( V_2 , error , & V_23 , & V_98 ) ;
} else {
if ( error < - V_23 ) {
error >>= 2 ;
if ( F_14 ( error >= - V_23 ) ) {
V_102 = - 1 ;
V_23 = - V_23 ;
V_98 = - V_98 ;
} else {
V_102 = F_91 ( V_2 , error , & V_23 , & V_98 ) ;
}
} else {
goto V_105;
}
}
if ( F_34 ( V_2 -> clock -> V_106 &&
( V_2 -> V_29 + V_102 > V_2 -> clock -> V_29 + V_2 -> clock -> V_106 ) ) ) {
F_94 ( V_85
L_6 ,
V_2 -> clock -> V_107 , ( long ) V_2 -> V_29 + V_102 ,
( long ) V_2 -> clock -> V_29 + V_2 -> clock -> V_106 ) ;
}
V_2 -> V_29 += V_102 ;
V_2 -> V_31 += V_23 ;
V_2 -> V_3 -= V_98 ;
V_2 -> V_35 -= ( V_23 - V_98 ) << V_2 -> V_36 ;
V_105:
if ( F_34 ( ( T_3 ) V_2 -> V_3 < 0 ) ) {
T_3 V_108 = - ( T_3 ) V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
V_2 -> V_35 += V_108 << V_2 -> V_36 ;
}
}
static inline unsigned int F_95 ( struct V_1 * V_2 )
{
V_4 V_109 = ( V_4 ) V_5 << V_2 -> V_6 ;
unsigned int V_50 = 0 ;
while ( V_2 -> V_3 >= V_109 ) {
int V_110 ;
V_2 -> V_3 -= V_109 ;
V_2 -> V_7 ++ ;
V_110 = F_96 ( V_2 -> V_7 ) ;
if ( F_34 ( V_110 ) ) {
struct V_8 V_9 ;
V_2 -> V_7 += V_110 ;
V_9 . V_10 = V_110 ;
V_9 . V_11 = 0 ;
F_4 ( V_2 ,
F_48 ( V_2 -> V_14 , V_9 ) ) ;
F_54 ( V_2 , V_2 -> V_18 - V_110 ) ;
F_97 () ;
V_50 = V_52 ;
}
}
return V_50 ;
}
static T_1 F_98 ( struct V_1 * V_2 , T_1 V_98 ,
T_2 V_6 )
{
T_1 V_23 = V_2 -> V_30 << V_6 ;
V_4 V_111 ;
if ( V_98 < V_23 )
return V_98 ;
V_98 -= V_23 ;
V_2 -> V_26 += V_23 ;
V_2 -> V_3 += V_2 -> V_31 << V_6 ;
F_95 ( V_2 ) ;
V_111 = ( V_4 ) V_2 -> V_33 << V_6 ;
V_111 += V_2 -> V_55 . V_11 ;
if ( V_111 >= V_5 ) {
V_4 V_112 = V_111 ;
V_111 = F_12 ( V_112 , V_5 ) ;
V_2 -> V_55 . V_10 += V_112 ;
}
V_2 -> V_55 . V_11 = V_111 ;
V_2 -> V_35 += F_92 () << V_6 ;
V_2 -> V_35 -= ( V_2 -> V_31 + V_2 -> V_32 ) <<
( V_2 -> V_36 + V_6 ) ;
return V_98 ;
}
static inline void F_99 ( struct V_1 * V_2 )
{
T_3 V_113 ;
V_113 = V_2 -> V_3 & ( ( 1ULL << V_2 -> V_6 ) - 1 ) ;
V_2 -> V_3 -= V_113 ;
V_2 -> V_3 += 1ULL << V_2 -> V_6 ;
V_2 -> V_35 += V_113 << V_2 -> V_36 ;
}
static void F_100 ( void )
{
struct V_22 * clock ;
struct V_1 * V_114 = & V_1 ;
struct V_1 * V_2 = & V_54 ;
T_1 V_98 ;
int V_6 = 0 , V_115 ;
unsigned int V_50 ;
unsigned long V_47 ;
F_21 ( & V_49 , V_47 ) ;
if ( F_34 ( V_59 ) )
goto V_116;
clock = V_114 -> clock ;
#ifdef F_101
V_98 = V_114 -> V_30 ;
#else
V_98 = ( clock -> V_27 ( clock ) - clock -> V_26 ) & clock -> V_42 ;
#endif
if ( V_98 < V_114 -> V_30 )
goto V_116;
V_6 = F_102 ( V_98 ) - F_102 ( V_2 -> V_30 ) ;
V_6 = V_90 ( 0 , V_6 ) ;
V_115 = ( 64 - ( F_102 ( F_92 () ) + 1 ) ) - 1 ;
V_6 = F_103 ( V_6 , V_115 ) ;
while ( V_98 >= V_2 -> V_30 ) {
V_98 = F_98 ( V_2 , V_98 , V_6 ) ;
if ( V_98 < V_2 -> V_30 << V_6 )
V_6 -- ;
}
F_93 ( V_2 , V_98 ) ;
F_99 ( V_2 ) ;
V_50 = F_95 ( V_2 ) ;
F_46 ( & V_58 ) ;
clock -> V_26 = V_2 -> V_26 ;
memcpy ( V_114 , V_2 , sizeof( * V_2 ) ) ;
F_26 ( V_114 , V_50 ) ;
F_49 ( & V_58 ) ;
V_116:
F_23 ( & V_49 , V_47 ) ;
}
void F_104 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_117 = {
. V_10 = V_2 -> V_14 . V_10 +
V_2 -> V_21 . V_10 ,
. V_11 = V_2 -> V_14 . V_11 +
V_2 -> V_21 . V_11
} ;
F_5 ( V_9 , - V_117 . V_10 , - V_117 . V_11 ) ;
}
void F_105 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_62 , V_118 ;
T_3 V_41 ;
unsigned int V_56 ;
F_36 ( V_59 ) ;
do {
V_56 = F_32 ( & V_58 ) ;
V_9 -> V_10 = V_2 -> V_7 ;
V_41 = F_15 ( V_2 ) ;
V_62 = V_2 -> V_14 ;
V_118 = V_2 -> V_21 ;
} while ( F_33 ( & V_58 , V_56 ) );
V_9 -> V_10 += V_62 . V_10 + V_118 . V_10 ;
V_9 -> V_11 = 0 ;
F_30 ( V_9 , V_41 + V_62 . V_11 + V_118 . V_11 ) ;
}
T_4 F_106 ( void )
{
struct V_8 V_9 ;
F_105 ( & V_9 ) ;
return F_7 ( V_9 ) ;
}
void F_107 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_1 ;
* V_9 = F_52 ( * V_9 , V_2 -> V_21 ) ;
}
unsigned long F_108 ( void )
{
struct V_1 * V_2 = & V_1 ;
return V_2 -> V_7 ;
}
struct V_8 F_109 ( void )
{
struct V_1 * V_2 = & V_1 ;
return F_47 ( V_2 ) ;
}
struct V_8 F_110 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_69 ;
unsigned long V_56 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_69 = F_47 ( V_2 ) ;
} while ( F_33 ( & V_58 , V_56 ) );
return V_69 ;
}
struct V_8 F_111 ( void )
{
struct V_1 * V_2 = & V_1 ;
struct V_8 V_69 , V_119 ;
unsigned long V_56 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_69 = F_47 ( V_2 ) ;
V_119 = V_2 -> V_14 ;
} while ( F_33 ( & V_58 , V_56 ) );
F_5 ( & V_69 , V_69 . V_10 + V_119 . V_10 ,
V_69 . V_11 + V_119 . V_11 ) ;
return V_69 ;
}
void F_112 ( unsigned long V_120 )
{
V_121 += V_120 ;
F_100 () ;
F_113 ( V_120 ) ;
}
void F_114 ( struct V_8 * V_122 ,
struct V_8 * V_123 , struct V_8 * V_118 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
do {
V_56 = F_32 ( & V_58 ) ;
* V_122 = F_47 ( V_2 ) ;
* V_123 = V_2 -> V_14 ;
* V_118 = V_2 -> V_21 ;
} while ( F_33 ( & V_58 , V_56 ) );
}
T_4 F_115 ( T_4 * V_15 , T_4 * V_20 ,
T_4 * V_17 )
{
struct V_1 * V_2 = & V_1 ;
T_4 V_69 ;
unsigned int V_56 ;
V_4 V_61 , V_57 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_61 = V_2 -> V_7 ;
V_57 = F_15 ( V_2 ) ;
* V_15 = V_2 -> V_15 ;
* V_20 = V_2 -> V_20 ;
* V_17 = V_2 -> V_17 ;
} while ( F_33 ( & V_58 , V_56 ) );
V_69 = F_38 ( F_9 ( V_61 , 0 ) , V_57 ) ;
V_69 = F_8 ( V_69 , * V_15 ) ;
return V_69 ;
}
T_4 F_116 ( void )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_56 ;
struct V_8 V_123 ;
do {
V_56 = F_32 ( & V_58 ) ;
V_123 = V_2 -> V_14 ;
} while ( F_33 ( & V_58 , V_56 ) );
return F_7 ( V_123 ) ;
}
int F_117 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_47 ;
struct V_8 V_9 ;
T_5 V_126 , V_127 ;
int V_48 ;
V_48 = F_118 ( V_125 ) ;
if ( V_48 )
return V_48 ;
if ( V_125 -> V_128 & V_129 ) {
struct V_8 V_84 ;
V_84 . V_10 = V_125 -> time . V_10 ;
V_84 . V_11 = V_125 -> time . V_70 ;
if ( ! ( V_125 -> V_128 & V_130 ) )
V_84 . V_11 *= 1000 ;
V_48 = F_51 ( & V_84 ) ;
if ( V_48 )
return V_48 ;
}
F_35 ( & V_9 ) ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
V_126 = V_127 = V_2 -> V_18 ;
V_48 = F_119 ( V_125 , & V_9 , & V_127 ) ;
if ( V_127 != V_126 ) {
F_54 ( V_2 , V_127 ) ;
F_18 ( V_2 , true ) ;
F_97 () ;
}
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
F_120 () ;
return V_48 ;
}
void F_121 ( const struct V_8 * V_131 , const struct V_8 * V_132 )
{
unsigned long V_47 ;
F_21 ( & V_49 , V_47 ) ;
F_46 ( & V_58 ) ;
F_122 ( V_131 , V_132 ) ;
F_49 ( & V_58 ) ;
F_23 ( & V_49 , V_47 ) ;
}
void F_123 ( unsigned long V_120 )
{
F_124 ( & V_133 ) ;
F_112 ( V_120 ) ;
F_125 ( & V_133 ) ;
}
