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
V_46 = F_19 ( V_41 . V_47 , V_41 . V_48 - V_41 . V_47 + 1 ) ;
if ( V_46 == NULL )
F_5 ( L_10 ) ;
V_49 = F_19 ( F_11 ( V_42 ) , V_43 ) ;
for ( V_36 = 0 ; V_36 < V_43 / 4 ; V_36 ++ )
V_49 [ V_36 ] = V_33 ;
V_38 = V_42 >> V_28 ;
V_39 = V_43 >> V_28 ;
if ( V_5 ) {
V_39 &= V_50 ;
F_4 ( V_51 , V_38 ) ;
F_4 ( V_52 , V_39 ) ;
F_4 ( V_9 , V_11 ) ;
} else {
V_39 &= V_53 ;
F_4 ( V_9 ,
V_54 |
( V_38 << V_55 ) |
( V_39 << V_56 ) ) ;
}
F_1 () ;
F_15 ( V_44 L_11 ,
V_5 ? L_12 : L_13 ) ;
return 0 ;
}
static void F_20 ( void )
{
V_57 . V_58 = 0 ;
V_57 . V_59 = 0 ;
V_57 . V_60 = V_43 / sizeof( V_61 ) ;
V_57 . V_27 = ( unsigned long ) V_49 ;
V_57 . V_62 = 0 ;
V_57 . V_63 = 1 ;
F_21 ( & V_57 , - 1 ) ;
F_22 ( V_57 . V_60 - 1 , V_57 . V_64 ) ;
}
static void F_23 ( struct V_65 * V_66 )
{
if ( F_24 ( V_66 ) == & V_67 )
F_25 ( V_66 , V_68 ) ;
else
F_26 ( V_66 , & V_57 ) ;
}
static void F_27 ( struct V_69 * V_66 )
{
F_23 ( & V_66 -> V_66 ) ;
}
static void F_28 ( struct V_70 * V_71 )
{
if ( ! V_72 ) {
V_72 = 1 ;
F_20 () ;
}
}
static bool F_29 ( struct V_65 * V_66 )
{
struct V_34 * V_73 = F_30 ( V_66 -> V_74 ) ;
while( V_73 ) {
if ( F_31 ( V_73 , L_14 ) ||
F_31 ( V_73 , L_15 ) ) {
F_32 ( V_73 ) ;
return true ;
}
V_73 = F_33 ( V_73 ) ;
}
return false ;
}
static int F_34 ( struct V_65 * V_66 , T_2 V_75 )
{
if ( ! V_66 -> V_75 || ! F_35 ( V_66 , V_75 ) )
return - V_76 ;
if ( F_29 ( V_66 ) && V_75 >= F_36 ( 40 ) ) {
F_37 ( V_66 , L_16 ) ;
F_38 ( V_66 , & V_67 ) ;
} else {
F_37 ( V_66 , L_17 ) ;
F_38 ( V_66 , & V_77 ) ;
}
F_23 ( V_66 ) ;
* V_66 -> V_75 = V_75 ;
return 0 ;
}
void T_1 F_39 ( void )
{
struct V_34 * V_78 ;
V_78 = F_40 ( NULL , L_18 , L_19 ) ;
if ( V_78 == NULL ) {
V_78 = F_40 ( NULL , L_18 , L_20 ) ;
if ( V_78 == NULL )
return;
V_5 = 1 ;
}
if ( F_14 ( V_78 ) != 0 )
goto V_79;
V_80 . V_81 = F_10 ;
V_80 . V_82 = F_13 ;
V_80 . V_83 = F_8 ;
if ( V_5 )
V_80 . V_84 = F_34 ;
V_80 . V_85 = F_27 ;
V_80 . V_86 = F_28 ;
F_41 ( & V_77 ) ;
return;
V_79:
V_80 . V_85 = NULL ;
V_80 . V_86 = NULL ;
F_41 ( & V_67 ) ;
}
static void F_42 ( void )
{
memcpy ( V_87 , V_49 , 2 * 1024 * 1024 ) ;
}
static void F_43 ( void )
{
memcpy ( V_49 , V_87 , 2 * 1024 * 1024 ) ;
F_1 () ;
}
static int T_1 F_44 ( void )
{
unsigned long V_88 ;
struct V_89 * V_90 ;
if ( ! V_42 )
return 0 ;
V_88 = F_45 ( V_42 ) >> V_91 ;
F_46 ( V_88 ,
V_88 + ( ( 1 << 24 ) >> V_91 ) ) ;
V_90 = F_47 ( V_92 , 21 - V_91 ) ;
F_48 ( ! V_90 ) ;
V_87 = F_49 ( V_90 ) ;
V_80 . V_93 = F_42 ;
V_80 . V_94 = F_43 ;
return 0 ;
}
void T_1 F_50 ( void )
{
if ( V_95 )
return;
if ( ! V_96 && F_51 () <= 0x40000000ull )
return;
V_43 = 1UL << 21 ;
V_42 = ( unsigned long )
F_52 ( F_53 ( 1UL << 24 , 1UL << 24 , 0x80000000L ) ) ;
F_15 ( V_44 L_21 , V_42 ) ;
}
