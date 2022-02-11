static inline void F_1 ( void )
{
unsigned long V_1 = 0 ;
unsigned int V_2 , V_3 ;
unsigned long V_4 ;
F_2 ( L_1 ) ;
V_4 = 0 ;
V_3 = V_5 ? V_6 : V_7 ;
V_8:
V_1 = 0 ;
V_2 = F_3 ( V_9 ) ;
V_2 |= V_3 ;
F_4 ( V_9 , V_2 ) ;
while ( ( F_3 ( V_9 ) & V_3 ) && V_1 < ( 1L << V_4 ) )
V_1 ++ ;
if ( V_1 == ( 1L << V_4 ) ) {
if ( V_4 < 4 ) {
V_4 ++ ;
V_2 = F_3 ( V_9 ) ;
V_2 &= ~ V_3 ;
F_4 ( V_9 , V_2 ) ;
goto V_8;
} else
F_5 ( L_2
L_3 ) ;
}
}
static inline void F_6 ( unsigned long V_10 )
{
unsigned int V_2 ;
unsigned int V_1 , V_4 ;
V_2 = V_11 | V_12 |
( V_10 & V_13 ) ;
F_4 ( V_9 , V_2 ) ;
V_4 = 0 ;
V_14:
V_1 = 0 ;
while ( ( F_3 ( V_9 ) & V_12 ) && V_1 < ( 1L << V_4 ) ) {
F_7 () ;
V_1 ++ ;
}
if ( V_1 == ( 1L << V_4 ) ) {
if ( V_4 < 4 ) {
V_4 ++ ;
goto V_14;
} else
F_5 ( L_2
L_4 ) ;
}
}
static void F_8 ( struct V_15 * V_16 )
{
F_9 () ;
if ( V_17 ) {
F_1 () ;
V_17 = 0 ;
}
}
static int F_10 ( struct V_15 * V_16 , long V_18 ,
long V_19 , unsigned long V_20 ,
enum V_21 V_22 ,
struct V_23 * V_24 )
{
unsigned int * V_25 ;
unsigned int V_26 ;
long V_1 ;
F_2 ( L_5 , V_18 , V_19 , V_20 ) ;
V_25 = ( ( unsigned int * ) V_16 -> V_27 ) + V_18 ;
V_1 = V_19 ;
while ( V_1 -- ) {
V_26 = F_11 ( V_20 ) >> V_28 ;
* ( V_25 ++ ) = V_29 | ( V_26 & V_30 ) ;
V_20 += V_31 ;
}
F_9 () ;
F_12 ( ( unsigned V_32 * ) V_25 ) ;
F_9 () ;
if ( V_5 ) {
V_26 = V_18 ;
while ( V_19 -- )
F_6 ( V_26 ++ ) ;
} else {
V_17 = 1 ;
}
return 0 ;
}
static void F_13 ( struct V_15 * V_16 , long V_18 , long V_19 )
{
unsigned int * V_25 ;
F_2 ( L_6 , V_18 , V_19 ) ;
V_25 = ( ( unsigned int * ) V_16 -> V_27 ) + V_18 ;
while ( V_19 -- )
* ( V_25 ++ ) = V_33 ;
}
static int T_1 F_14 ( struct V_34 * V_35 )
{
unsigned int V_36 ;
unsigned long V_37 , V_38 , V_39 ;
struct V_40 V_41 ;
if ( V_42 == 0 || V_43 == 0 ) {
F_15 ( V_44 L_7
L_8 ) ;
return - V_45 ;
}
if ( F_16 ( V_35 , 0 , & V_41 ) )
F_5 ( L_9 ) ;
F_17 ( V_42 ,
V_42 + V_43 ) ;
V_37 = F_18 ( V_31 , V_31 ) ;
V_33 = V_29 | ( ( V_37 >> V_28 ) &
V_30 ) ;
V_46 = F_19 ( V_41 . V_47 , F_20 ( & V_41 ) ) ;
if ( V_46 == NULL )
F_5 ( L_10 ) ;
V_48 = F_19 ( F_11 ( V_42 ) , V_43 ) ;
for ( V_36 = 0 ; V_36 < V_43 / 4 ; V_36 ++ )
V_48 [ V_36 ] = V_33 ;
V_38 = V_42 >> V_28 ;
V_39 = V_43 >> V_28 ;
if ( V_5 ) {
V_39 &= V_49 ;
F_4 ( V_50 , V_38 ) ;
F_4 ( V_51 , V_39 ) ;
F_4 ( V_9 , V_11 ) ;
} else {
V_39 &= V_52 ;
F_4 ( V_9 ,
V_53 |
( V_38 << V_54 ) |
( V_39 << V_55 ) ) ;
}
F_1 () ;
F_15 ( V_44 L_11 ,
V_5 ? L_12 : L_13 ) ;
return 0 ;
}
static void F_21 ( void )
{
V_56 . V_57 = 0 ;
V_56 . V_58 = 0 ;
V_56 . V_59 = V_43 / sizeof( V_60 ) ;
V_56 . V_27 = ( unsigned long ) V_48 ;
V_56 . V_61 = 0 ;
V_56 . V_62 = 1 ;
F_22 ( & V_56 , - 1 ) ;
F_23 ( V_56 . V_59 - 1 , V_56 . V_63 ) ;
}
static void F_24 ( struct V_64 * V_65 )
{
if ( F_25 ( V_65 ) == & V_66 )
F_26 ( V_65 , V_67 ) ;
else
F_27 ( V_65 , & V_56 ) ;
}
static void F_28 ( struct V_68 * V_65 )
{
F_24 ( & V_65 -> V_65 ) ;
}
static void F_29 ( struct V_69 * V_70 )
{
if ( ! V_71 ) {
V_71 = 1 ;
F_21 () ;
}
}
static bool F_30 ( struct V_64 * V_65 )
{
struct V_34 * V_72 = F_31 ( V_65 -> V_73 ) ;
while( V_72 ) {
if ( F_32 ( V_72 , L_14 ) ||
F_32 ( V_72 , L_15 ) ) {
F_33 ( V_72 ) ;
return true ;
}
V_72 = F_34 ( V_72 ) ;
}
return false ;
}
static int F_35 ( struct V_64 * V_65 , T_2 V_74 )
{
if ( ! V_65 -> V_74 || ! F_36 ( V_65 , V_74 ) )
return - V_75 ;
if ( F_30 ( V_65 ) && V_74 >= F_37 ( 40 ) ) {
F_38 ( V_65 , L_16 ) ;
F_39 ( V_65 , & V_66 ) ;
} else {
F_38 ( V_65 , L_17 ) ;
F_39 ( V_65 , & V_76 ) ;
}
F_24 ( V_65 ) ;
* V_65 -> V_74 = V_74 ;
return 0 ;
}
void T_1 F_40 ( void )
{
struct V_34 * V_77 ;
V_77 = F_41 ( NULL , L_18 , L_19 ) ;
if ( V_77 == NULL ) {
V_77 = F_41 ( NULL , L_18 , L_20 ) ;
if ( V_77 == NULL )
return;
V_5 = 1 ;
}
if ( F_14 ( V_77 ) != 0 )
goto V_78;
V_79 . V_80 = F_10 ;
V_79 . V_81 = F_13 ;
V_79 . V_82 = F_8 ;
if ( V_5 )
V_79 . V_83 = F_35 ;
V_79 . V_84 = F_28 ;
V_79 . V_85 = F_29 ;
F_42 ( & V_76 ) ;
return;
V_78:
V_79 . V_84 = NULL ;
V_79 . V_85 = NULL ;
F_42 ( & V_66 ) ;
}
static void F_43 ( void )
{
memcpy ( V_86 , V_48 , 2 * 1024 * 1024 ) ;
}
static void F_44 ( void )
{
memcpy ( V_48 , V_86 , 2 * 1024 * 1024 ) ;
F_1 () ;
}
static int T_1 F_45 ( void )
{
unsigned long V_87 ;
struct V_88 * V_89 ;
if ( ! V_42 )
return 0 ;
V_87 = F_46 ( V_42 ) >> V_90 ;
F_47 ( V_87 ,
V_87 + ( ( 1 << 24 ) >> V_90 ) ) ;
V_89 = F_48 ( V_91 , 21 - V_90 ) ;
F_49 ( ! V_89 ) ;
V_86 = F_50 ( V_89 ) ;
V_79 . V_92 = F_43 ;
V_79 . V_93 = F_44 ;
return 0 ;
}
void T_1 F_51 ( void )
{
if ( V_94 )
return;
if ( ! V_95 && F_52 () <= 0x40000000ull )
return;
V_43 = 1UL << 21 ;
V_42 = ( unsigned long )
F_53 ( F_54 ( 1UL << 24 , 1UL << 24 , 0x80000000L ) ) ;
F_15 ( V_44 L_21 , V_42 ) ;
}
