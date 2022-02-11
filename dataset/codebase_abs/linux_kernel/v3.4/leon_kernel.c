static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( & V_2 -> V_3 [ V_1 ] ) & 0x1f ;
}
static void F_3 ( unsigned int V_4 , struct V_5 * V_6 )
{
unsigned int V_7 ;
int V_1 = F_4 () ;
V_7 = F_1 ( V_1 ) ;
if ( ( V_7 & 0x10 ) && V_8 [ V_7 ] -> V_4 )
F_5 ( V_8 [ V_7 ] -> V_4 ) ;
}
void F_6 ( unsigned int V_7 )
{
unsigned long V_9 , V_10 ;
unsigned int V_11 ;
if ( V_7 < 1 || V_7 > 0xf ) {
F_7 ( V_12 L_1 , V_7 ) ;
return;
}
V_11 = F_8 ( V_7 , F_3 , L_2 , 0 ) ;
F_9 ( V_11 ) ;
V_9 = 1 << V_7 ;
V_10 = F_2 ( F_10 ( V_13 ) ) ;
F_11 ( F_10 ( V_13 ) , ( V_10 | V_9 ) ) ;
V_14 = V_7 ;
}
static inline unsigned long F_12 ( unsigned int V_4 )
{
unsigned long V_9 ;
if ( ! V_4 || ( ( V_4 > 0xf ) && ! V_14 )
|| ( ( V_4 > 0x1f ) && V_14 ) ) {
F_7 ( V_12
L_3 , V_4 ) ;
V_9 = 0 ;
} else {
V_9 = F_13 ( V_4 ) ;
}
return V_9 ;
}
static int F_14 ( const struct V_15 * V_16 )
{
T_1 V_9 ;
F_15 ( & V_9 , V_17 , V_16 ) ;
if ( F_16 ( & V_9 , V_17 ) || F_17 ( & V_9 ) )
return V_13 ;
else
return F_18 ( & V_9 ) ;
}
static int F_19 ( struct V_18 * V_19 , const struct V_15 * V_20 ,
bool V_21 )
{
unsigned long V_9 , V_10 , V_22 ;
int V_23 , V_24 ;
V_9 = ( unsigned long ) V_19 -> V_25 ;
V_23 = F_14 ( V_19 -> V_16 ) ;
V_24 = F_14 ( V_20 ) ;
if ( V_23 == V_24 )
goto V_26;
F_20 ( & V_27 , V_22 ) ;
V_10 = F_2 ( F_10 ( V_23 ) ) ;
F_11 ( F_10 ( V_23 ) , ( V_10 & ~ V_9 ) ) ;
V_10 = F_2 ( F_10 ( V_24 ) ) ;
F_11 ( F_10 ( V_24 ) , ( V_10 | V_9 ) ) ;
F_21 ( & V_27 , V_22 ) ;
V_26:
return V_28 ;
}
static void F_22 ( struct V_18 * V_19 )
{
unsigned long V_9 , V_10 , V_22 ;
int V_1 ;
V_9 = ( unsigned long ) V_19 -> V_25 ;
V_1 = F_14 ( V_19 -> V_16 ) ;
F_20 ( & V_27 , V_22 ) ;
V_10 = F_2 ( F_10 ( V_1 ) ) ;
F_11 ( F_10 ( V_1 ) , ( V_10 | V_9 ) ) ;
F_21 ( & V_27 , V_22 ) ;
}
static void F_23 ( struct V_18 * V_19 )
{
unsigned long V_9 , V_10 , V_22 ;
int V_1 ;
V_9 = ( unsigned long ) V_19 -> V_25 ;
V_1 = F_14 ( V_19 -> V_16 ) ;
F_20 ( & V_27 , V_22 ) ;
V_10 = F_2 ( F_10 ( V_1 ) ) ;
F_11 ( F_10 ( V_1 ) , ( V_10 & ~ V_9 ) ) ;
F_21 ( & V_27 , V_22 ) ;
}
static unsigned int F_24 ( struct V_18 * V_19 )
{
F_9 ( V_19 -> V_4 ) ;
F_22 ( V_19 ) ;
return 0 ;
}
static void F_25 ( struct V_18 * V_19 )
{
F_23 ( V_19 ) ;
F_26 ( V_19 -> V_4 ) ;
}
static void F_27 ( struct V_18 * V_19 )
{
unsigned long V_9 = ( unsigned long ) V_19 -> V_25 ;
if ( V_9 & V_29 )
F_11 ( V_30 , V_9 & ~ V_29 ) ;
}
unsigned int F_8 ( unsigned int V_31 ,
T_2 V_32 ,
const char * V_33 , int V_34 )
{
unsigned int V_4 ;
unsigned long V_9 ;
V_4 = 0 ;
V_9 = F_12 ( V_31 ) ;
if ( V_9 == 0 )
goto V_26;
V_4 = F_28 ( V_31 , V_31 ) ;
if ( V_4 == 0 )
goto V_26;
if ( V_34 )
V_9 |= V_29 ;
F_29 ( V_4 , & V_35 ,
V_32 , V_33 ) ;
F_30 ( V_4 , ( void * ) V_9 ) ;
V_26:
return V_4 ;
}
static unsigned int F_31 ( struct V_36 * V_37 ,
unsigned int V_31 )
{
return F_8 ( V_31 , V_38 , L_4 , 0 ) ;
}
void F_32 ( unsigned int V_39 ,
T_2 V_32 ,
const char * V_33 , int V_34 )
{
unsigned long V_9 = ( unsigned long ) F_33 ( V_39 ) ;
V_9 &= ~ V_29 ;
if ( V_34 )
V_9 |= V_29 ;
F_29 ( V_39 , & V_35 ,
V_32 , V_33 ) ;
F_30 ( V_39 , ( void * ) V_9 ) ;
}
void T_3 F_34 ( T_4 V_40 )
{
int V_4 , V_7 ;
struct V_41 * V_42 , * V_43 , * V_44 ;
struct V_45 * V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
int V_50 ;
V_51 = 0 ;
V_52 = 0 ;
V_53 = ( unsigned int * ) & V_54 ;
V_54 = 0 ;
V_42 = F_35 ( L_5 ) ;
if ( ! V_42 )
goto V_55;
V_46 = F_36 ( V_42 , L_6 , & V_47 ) ;
if ( V_46 )
V_56 = * ( unsigned long * ) V_46 -> V_57 ;
V_43 = F_37 ( V_42 , L_7 ) ;
if ( ! V_43 ) {
V_43 = F_37 ( V_42 , L_8 ) ;
if ( ! V_43 )
goto V_55;
}
V_46 = F_36 ( V_43 , L_9 , & V_47 ) ;
if ( ! V_46 )
goto V_55;
V_2 = * (struct V_58 * * ) V_46 -> V_57 ;
V_44 = V_42 ;
do {
V_43 = F_37 ( V_44 , L_10 ) ;
if ( ! V_43 ) {
V_43 = F_37 ( V_44 , L_11 ) ;
if ( ! V_43 )
goto V_55;
}
V_49 = 0 ;
V_46 = F_36 ( V_43 , L_12 , & V_47 ) ;
if ( V_46 ) {
V_49 = * ( int * ) V_46 -> V_57 ;
if ( V_49 == 0 ) {
V_44 = V_43 ;
continue;
}
}
V_59 = V_49 & 0x7 ;
V_46 = F_36 ( V_43 , L_9 , & V_47 ) ;
if ( V_46 )
V_60 = * (struct V_61 * * )
V_46 -> V_57 ;
V_46 = F_36 ( V_43 , L_13 , & V_47 ) ;
if ( V_46 )
V_62 = * ( unsigned int * ) V_46 -> V_57 ;
} while ( 0 );
if ( ! ( V_60 && V_2 && V_62 ) )
goto V_55;
F_11 ( & V_60 -> V_63 [ V_59 ] . V_64 , 0 ) ;
F_11 ( & V_60 -> V_63 [ V_59 ] . V_65 ,
( ( ( 1000000 / V_66 ) - 1 ) ) ) ;
F_11 (
& V_60 -> V_63 [ V_59 ] . V_67 , 0 ) ;
#ifdef F_38
V_68 = V_62 + 1 + V_59 ;
if ( ! ( F_2 ( & V_60 -> V_69 ) &
( 1 << V_70 ) ) ) {
F_7 ( V_12 L_14 ) ;
F_39 () ;
}
F_11 ( & V_60 -> V_63 [ V_59 + 1 ] . V_64 ,
0 ) ;
F_11 ( & V_60 -> V_63 [ V_59 + 1 ] . V_65 ,
( ( ( 1000000 / V_66 ) - 1 ) ) ) ;
F_11 ( & V_60 -> V_63 [ V_59 + 1 ] . V_67 ,
0 ) ;
#endif
V_48 = F_2 ( & V_2 -> V_48 [ V_13 / 8 ] ) ;
V_48 = ( V_48 >> ( ( 7 - ( V_13 & 0x7 ) ) * 4 ) ) & 0xf ;
V_2 += V_48 ;
F_11 ( & V_2 -> V_9 [ V_13 ] , 0 ) ;
V_7 = ( F_2 ( & V_2 -> V_71 )
>> 16 ) & 0xf ;
if ( V_7 != 0 )
F_6 ( V_7 ) ;
V_4 = F_31 ( NULL , V_62 + V_59 ) ;
V_50 = F_40 ( V_4 , V_40 , V_72 , L_15 , NULL ) ;
if ( V_50 ) {
F_7 ( V_12 L_16 , V_4 ) ;
F_41 () ;
}
#ifdef F_38
{
unsigned long V_22 ;
F_42 ( V_22 ) ;
V_73 [ 0 ] = 0x01000000 ;
F_43 () ;
F_44 ( V_22 ) ;
}
#endif
F_11 ( & V_60 -> V_63 [ V_59 ] . V_67 ,
V_74 |
V_75 |
V_76 |
V_77 ) ;
#ifdef F_38
V_4 = F_8 ( V_68 , V_78 ,
L_17 , 0 ) ;
V_50 = F_40 ( V_4 , V_79 ,
V_80 | V_72 , L_18 ,
NULL ) ;
if ( V_50 ) {
F_7 ( V_12 L_19 , V_4 ) ;
F_41 () ;
}
F_11 ( & V_60 -> V_63 [ V_59 + 1 ] . V_67 ,
V_74 |
V_75 |
V_76 |
V_77 ) ;
#endif
return;
V_55:
F_7 ( V_12 L_20 ) ;
F_39 () ;
return;
}
void F_45 ( void )
{
}
void F_46 ( int V_1 , unsigned int V_81 )
{
F_39 () ;
}
void T_3 F_47 ( struct V_41 * V_82 )
{
if ( strcmp ( V_82 -> type , L_21 ) == 0 && strcmp ( V_82 -> V_33 , L_22 ) == 0 ) {
struct V_45 * V_83 ;
V_83 = F_36 ( V_82 , L_23 , ( void * ) 0 ) ;
if ( V_83 ) {
int V_84 ;
V_82 -> V_33 = F_48 ( 5 + 1 ) ;
memcpy ( & V_84 , V_83 -> V_57 , V_83 -> V_85 ) ;
sprintf ( ( char * ) V_82 -> V_33 , L_24 , V_84 ) ;
}
}
}
void T_3 F_49 ( struct V_41 * V_82 , struct V_41 * * * V_86 )
{
if ( V_87 &&
strcmp ( V_82 -> type , L_25 ) == 0 &&
strcmp ( V_82 -> V_33 , L_26 ) == 0 ) {
V_87 ( V_82 , V_86 ) ;
}
}
void F_50 ( int V_1 , int V_88 )
{
unsigned long V_9 ;
V_9 = F_12 ( V_88 ) ;
F_11 ( & V_2 -> V_21 [ V_1 ] , V_9 ) ;
}
static void F_51 ( int V_1 , int V_88 )
{
unsigned long V_9 ;
V_9 = F_12 ( V_88 ) ;
F_11 ( & V_2 -> V_21 [ V_1 ] , V_9 << 16 ) ;
}
static void F_52 ( int V_1 )
{
}
void F_53 ( int V_1 )
{
}
void F_54 ( unsigned int V_89 , unsigned int V_1 )
{
unsigned long V_9 , V_22 , * V_90 ;
V_9 = F_12 ( V_89 ) ;
F_20 ( & V_27 , V_22 ) ;
V_90 = ( unsigned long * ) F_10 ( V_1 ) ;
F_11 ( V_90 , ( F_2 ( V_90 ) | V_9 ) ) ;
F_21 ( & V_27 , V_22 ) ;
}
void T_3 F_55 ( void )
{
V_91 . V_92 = F_34 ;
V_91 . V_93 = F_31 ;
F_56 ( V_94 , F_45 ,
V_95 ) ;
F_56 ( V_96 , F_46 ,
V_97 ) ;
#ifdef F_38
F_56 ( V_98 , F_50 , V_95 ) ;
F_56 ( V_99 , F_51 , V_95 ) ;
F_56 ( V_100 , F_52 , V_95 ) ;
#endif
}
void T_3 F_57 ( void )
{
V_101 = & F_49 ;
}
