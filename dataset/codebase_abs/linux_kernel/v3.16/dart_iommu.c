static inline void F_1 ( void )
{
unsigned long V_1 = 0 ;
unsigned int V_2 , V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_3 ( L_1 ) ;
V_4 = 0 ;
V_3 = V_7 ? V_8 : V_9 ;
V_10:
V_1 = 0 ;
V_2 = F_4 ( V_11 ) ;
V_2 |= V_3 ;
F_5 ( V_11 , V_2 ) ;
while ( ( F_4 ( V_11 ) & V_3 ) && V_1 < ( 1L << V_4 ) )
V_1 ++ ;
if ( V_1 == ( 1L << V_4 ) ) {
if ( V_4 < 4 ) {
V_4 ++ ;
V_2 = F_4 ( V_11 ) ;
V_2 &= ~ V_3 ;
F_5 ( V_11 , V_2 ) ;
goto V_10;
} else
F_6 ( L_2
L_3 ) ;
}
F_7 ( & V_6 , V_5 ) ;
}
static inline void F_8 ( unsigned long V_12 )
{
unsigned int V_2 ;
unsigned int V_1 , V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
V_2 = V_13 | V_14 |
( V_12 & V_15 ) ;
F_5 ( V_11 , V_2 ) ;
V_4 = 0 ;
V_16:
V_1 = 0 ;
while ( ( F_4 ( V_11 ) & V_14 ) && V_1 < ( 1L << V_4 ) ) {
F_9 () ;
V_1 ++ ;
}
if ( V_1 == ( 1L << V_4 ) ) {
if ( V_4 < 4 ) {
V_4 ++ ;
goto V_16;
} else
F_6 ( L_2
L_4 ) ;
}
F_7 ( & V_6 , V_5 ) ;
}
static void F_10 ( struct V_17 * V_18 )
{
F_11 () ;
if ( V_19 ) {
F_1 () ;
V_19 = 0 ;
}
}
static int F_12 ( struct V_17 * V_18 , long V_20 ,
long V_21 , unsigned long V_22 ,
enum V_23 V_24 ,
struct V_25 * V_26 )
{
unsigned int * V_27 ;
unsigned int V_28 ;
long V_1 ;
F_3 ( L_5 , V_20 , V_21 , V_22 ) ;
V_27 = ( ( unsigned int * ) V_18 -> V_29 ) + V_20 ;
V_1 = V_21 ;
while ( V_1 -- ) {
V_28 = F_13 ( V_22 ) >> V_30 ;
* ( V_27 ++ ) = V_31 | ( V_28 & V_32 ) ;
V_22 += V_33 ;
}
F_11 () ;
F_14 ( ( unsigned V_34 * ) V_27 ) ;
F_11 () ;
if ( V_7 ) {
V_28 = V_20 ;
while ( V_21 -- )
F_8 ( V_28 ++ ) ;
} else {
V_19 = 1 ;
}
return 0 ;
}
static void F_15 ( struct V_17 * V_18 , long V_20 , long V_21 )
{
unsigned int * V_27 ;
F_3 ( L_6 , V_20 , V_21 ) ;
V_27 = ( ( unsigned int * ) V_18 -> V_29 ) + V_20 ;
while ( V_21 -- )
* ( V_27 ++ ) = V_35 ;
}
static int T_1 F_16 ( struct V_36 * V_37 )
{
unsigned int V_38 ;
unsigned long V_39 , V_40 , V_41 ;
struct V_42 V_43 ;
if ( V_44 == 0 || V_45 == 0 ) {
F_17 ( V_46 L_7
L_8 ) ;
return - V_47 ;
}
if ( F_18 ( V_37 , 0 , & V_43 ) )
F_6 ( L_9 ) ;
F_19 ( V_44 ,
V_44 + V_45 ) ;
V_39 = F_20 ( V_33 , V_33 ) ;
V_35 = V_31 | ( ( V_39 >> V_30 ) &
V_32 ) ;
V_48 = F_21 ( V_43 . V_49 , F_22 ( & V_43 ) ) ;
if ( V_48 == NULL )
F_6 ( L_10 ) ;
V_50 = F_21 ( F_13 ( V_44 ) , V_45 ) ;
for ( V_38 = 0 ; V_38 < V_45 / 4 ; V_38 ++ )
V_50 [ V_38 ] = V_35 ;
V_40 = V_44 >> V_30 ;
V_41 = V_45 >> V_30 ;
if ( V_7 ) {
V_41 &= V_51 ;
F_5 ( V_52 , V_40 ) ;
F_5 ( V_53 , V_41 ) ;
F_5 ( V_11 , V_13 ) ;
} else {
V_41 &= V_54 ;
F_5 ( V_11 ,
V_55 |
( V_40 << V_56 ) |
( V_41 << V_57 ) ) ;
}
F_1 () ;
F_17 ( V_46 L_11 ,
V_7 ? L_12 : L_13 ) ;
return 0 ;
}
static void F_23 ( void )
{
V_58 . V_59 = 0 ;
V_58 . V_60 = 0 ;
V_58 . V_61 = V_45 / sizeof( V_62 ) ;
V_58 . V_63 = V_64 ;
V_58 . V_29 = ( unsigned long ) V_50 ;
V_58 . V_65 = 0 ;
V_58 . V_66 = 1 ;
F_24 ( & V_58 , - 1 ) ;
F_25 ( V_58 . V_61 - 1 , V_58 . V_67 ) ;
}
static void F_26 ( struct V_68 * V_69 )
{
if ( F_27 ( V_69 ) == & V_70 )
F_28 ( V_69 , V_71 ) ;
else
F_29 ( V_69 , & V_58 ) ;
}
static void F_30 ( struct V_72 * V_69 )
{
F_26 ( & V_69 -> V_69 ) ;
}
static void F_31 ( struct V_73 * V_74 )
{
if ( ! V_75 ) {
V_75 = 1 ;
F_23 () ;
}
}
static bool F_32 ( struct V_68 * V_69 )
{
struct V_36 * V_76 = F_33 ( V_69 -> V_77 ) ;
while( V_76 ) {
if ( F_34 ( V_76 , L_14 ) ||
F_34 ( V_76 , L_15 ) ) {
F_35 ( V_76 ) ;
return true ;
}
V_76 = F_36 ( V_76 ) ;
}
return false ;
}
static int F_37 ( struct V_68 * V_69 , T_2 V_78 )
{
if ( ! V_69 -> V_78 || ! F_38 ( V_69 , V_78 ) )
return - V_79 ;
if ( F_32 ( V_69 ) && V_78 >= F_39 ( 40 ) ) {
F_40 ( V_69 , L_16 ) ;
F_41 ( V_69 , & V_70 ) ;
} else {
F_40 ( V_69 , L_17 ) ;
F_41 ( V_69 , & V_80 ) ;
}
F_26 ( V_69 ) ;
* V_69 -> V_78 = V_78 ;
return 0 ;
}
void T_1 F_42 ( void )
{
struct V_36 * V_81 ;
V_81 = F_43 ( NULL , L_18 , L_19 ) ;
if ( V_81 == NULL ) {
V_81 = F_43 ( NULL , L_18 , L_20 ) ;
if ( V_81 == NULL )
return;
V_7 = 1 ;
}
if ( F_16 ( V_81 ) != 0 )
goto V_82;
V_83 . V_84 = F_12 ;
V_83 . V_85 = F_15 ;
V_83 . V_86 = F_10 ;
if ( V_7 )
V_83 . V_87 = F_37 ;
V_83 . V_88 = F_30 ;
V_83 . V_89 = F_31 ;
F_44 ( & V_80 ) ;
return;
V_82:
V_83 . V_88 = NULL ;
V_83 . V_89 = NULL ;
F_44 ( & V_70 ) ;
}
static void F_45 ( void )
{
memcpy ( V_90 , V_50 , 2 * 1024 * 1024 ) ;
}
static void F_46 ( void )
{
memcpy ( V_50 , V_90 , 2 * 1024 * 1024 ) ;
F_1 () ;
}
static int T_1 F_47 ( void )
{
unsigned long V_91 ;
struct V_92 * V_93 ;
if ( ! V_44 )
return 0 ;
V_91 = F_13 ( V_44 ) >> V_94 ;
F_48 ( V_91 ,
V_91 + ( ( 1 << 24 ) >> V_94 ) ) ;
V_93 = F_49 ( V_95 , 21 - V_94 ) ;
F_50 ( ! V_93 ) ;
V_90 = F_51 ( V_93 ) ;
V_83 . V_96 = F_45 ;
V_83 . V_97 = F_46 ;
return 0 ;
}
void T_1 F_52 ( void )
{
if ( V_98 )
return;
if ( ! V_99 && F_53 () <= 0x40000000ull )
return;
V_45 = 1UL << 21 ;
V_44 = ( unsigned long )
F_54 ( F_55 ( 1UL << 24 , 1UL << 24 , 0x80000000L ) ) ;
F_56 ( ( void * ) V_44 ) ;
F_17 ( V_46 L_21 , V_44 ) ;
}
