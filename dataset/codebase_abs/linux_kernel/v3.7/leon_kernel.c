static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( & V_2 -> V_3 [ V_1 ] ) & 0x1f ;
}
static void F_3 ( unsigned int V_4 , struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_8 * V_9 ;
int V_1 = F_4 () ;
V_7 = F_1 ( V_1 ) ;
V_9 = V_10 [ V_7 ] ;
if ( ( V_7 & 0x10 ) && V_9 && V_9 -> V_4 )
F_5 ( V_9 -> V_4 ) ;
}
void F_6 ( unsigned int V_7 )
{
unsigned long V_11 , V_12 ;
unsigned int V_13 ;
if ( V_7 < 1 || V_7 > 0xf ) {
F_7 ( V_14 L_1 , V_7 ) ;
return;
}
V_13 = F_8 ( V_7 , F_3 , L_2 , 0 ) ;
F_9 ( V_13 ) ;
V_11 = 1 << V_7 ;
V_12 = F_2 ( F_10 ( V_15 ) ) ;
F_11 ( F_10 ( V_15 ) , ( V_12 | V_11 ) ) ;
V_16 = V_7 ;
}
unsigned long F_12 ( unsigned int V_4 )
{
unsigned long V_11 ;
if ( ! V_4 || ( ( V_4 > 0xf ) && ! V_16 )
|| ( ( V_4 > 0x1f ) && V_16 ) ) {
F_7 ( V_14
L_3 , V_4 ) ;
V_11 = 0 ;
} else {
V_11 = F_13 ( V_4 ) ;
}
return V_11 ;
}
static int F_14 ( const struct V_17 * V_18 )
{
T_1 V_11 ;
F_15 ( & V_11 , V_19 , V_18 ) ;
if ( F_16 ( & V_11 , V_19 ) || F_17 ( & V_11 ) )
return V_15 ;
else
return F_18 ( & V_11 ) ;
}
static int F_19 ( struct V_20 * V_21 , const struct V_17 * V_22 ,
bool V_23 )
{
unsigned long V_11 , V_12 , V_24 ;
int V_25 , V_26 ;
V_11 = ( unsigned long ) V_21 -> V_27 ;
V_25 = F_14 ( V_21 -> V_18 ) ;
V_26 = F_14 ( V_22 ) ;
if ( V_25 == V_26 )
goto V_28;
F_20 ( & V_29 , V_24 ) ;
V_12 = F_2 ( F_10 ( V_25 ) ) ;
F_11 ( F_10 ( V_25 ) , ( V_12 & ~ V_11 ) ) ;
V_12 = F_2 ( F_10 ( V_26 ) ) ;
F_11 ( F_10 ( V_26 ) , ( V_12 | V_11 ) ) ;
F_21 ( & V_29 , V_24 ) ;
V_28:
return V_30 ;
}
static void F_22 ( struct V_20 * V_21 )
{
unsigned long V_11 , V_12 , V_24 ;
int V_1 ;
V_11 = ( unsigned long ) V_21 -> V_27 ;
V_1 = F_14 ( V_21 -> V_18 ) ;
F_20 ( & V_29 , V_24 ) ;
V_12 = F_2 ( F_10 ( V_1 ) ) ;
F_11 ( F_10 ( V_1 ) , ( V_12 | V_11 ) ) ;
F_21 ( & V_29 , V_24 ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
unsigned long V_11 , V_12 , V_24 ;
int V_1 ;
V_11 = ( unsigned long ) V_21 -> V_27 ;
V_1 = F_14 ( V_21 -> V_18 ) ;
F_20 ( & V_29 , V_24 ) ;
V_12 = F_2 ( F_10 ( V_1 ) ) ;
F_11 ( F_10 ( V_1 ) , ( V_12 & ~ V_11 ) ) ;
F_21 ( & V_29 , V_24 ) ;
}
static unsigned int F_24 ( struct V_20 * V_21 )
{
F_9 ( V_21 -> V_4 ) ;
F_22 ( V_21 ) ;
return 0 ;
}
static void F_25 ( struct V_20 * V_21 )
{
F_23 ( V_21 ) ;
F_26 ( V_21 -> V_4 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
unsigned long V_11 = ( unsigned long ) V_21 -> V_27 ;
if ( V_11 & V_31 )
F_11 ( V_32 , V_11 & ~ V_31 ) ;
}
unsigned int F_8 ( unsigned int V_33 ,
T_2 V_34 ,
const char * V_35 , int V_36 )
{
unsigned int V_4 ;
unsigned long V_11 ;
V_4 = 0 ;
V_11 = F_12 ( V_33 ) ;
if ( V_11 == 0 )
goto V_28;
V_4 = F_28 ( V_33 , V_33 ) ;
if ( V_4 == 0 )
goto V_28;
if ( V_36 )
V_11 |= V_31 ;
F_29 ( V_4 , & V_37 ,
V_34 , V_35 ) ;
F_30 ( V_4 , ( void * ) V_11 ) ;
V_28:
return V_4 ;
}
static unsigned int F_31 ( struct V_38 * V_39 ,
unsigned int V_33 )
{
return F_8 ( V_33 , V_40 , L_4 , 0 ) ;
}
void F_32 ( unsigned int V_41 ,
T_2 V_34 ,
const char * V_35 , int V_36 )
{
unsigned long V_11 = ( unsigned long ) F_33 ( V_41 ) ;
V_11 &= ~ V_31 ;
if ( V_36 )
V_11 |= V_31 ;
F_29 ( V_41 , & V_37 ,
V_34 , V_35 ) ;
F_30 ( V_41 , ( void * ) V_11 ) ;
}
static T_3 F_34 ( void )
{
T_3 V_42 , V_43 , V_44 ;
V_42 = F_2 ( & V_45 -> V_46 [ V_47 ] . V_42 ) ;
V_43 = F_2 ( & V_45 -> V_46 [ V_47 ] . V_43 ) ;
V_44 = V_42 - V_43 ;
return V_42 - V_43 ;
}
T_4 F_35 ( int V_4 , void * V_48 )
{
struct V_49 * V_50 ;
int V_1 = F_36 () ;
F_37 ( V_1 ) ;
V_50 = & F_38 ( V_51 , V_1 ) ;
F_39 () ;
if ( V_50 -> V_52 )
V_50 -> V_52 ( V_50 ) ;
F_40 () ;
return V_53 ;
}
void T_5 F_41 ( void )
{
int V_4 , V_7 ;
struct V_54 * V_55 , * V_56 , * V_57 ;
struct V_58 * V_59 ;
int V_60 ;
int V_61 ;
int V_62 ;
int V_63 ;
V_64 . V_65 = F_34 ;
V_64 . V_66 = 1000000 / V_67 ;
V_64 . V_68 |= V_69 ;
#ifndef F_42
V_64 . V_68 |= V_70 ;
#endif
V_71 = 0 ;
V_72 = 0 ;
V_73 = ( unsigned int * ) & V_74 ;
V_74 = 0 ;
V_55 = F_43 ( L_5 ) ;
if ( ! V_55 )
goto V_75;
V_59 = F_44 ( V_55 , L_6 , & V_60 ) ;
if ( V_59 )
V_76 = * ( unsigned long * ) V_59 -> V_77 ;
V_56 = F_45 ( V_55 , L_7 ) ;
if ( ! V_56 ) {
V_56 = F_45 ( V_55 , L_8 ) ;
if ( ! V_56 )
goto V_75;
}
V_59 = F_44 ( V_56 , L_9 , & V_60 ) ;
if ( ! V_59 )
goto V_75;
V_2 = * (struct V_78 * * ) V_59 -> V_77 ;
V_57 = V_55 ;
do {
V_56 = F_45 ( V_57 , L_10 ) ;
if ( ! V_56 ) {
V_56 = F_45 ( V_57 , L_11 ) ;
if ( ! V_56 )
goto V_75;
}
V_62 = 0 ;
V_59 = F_44 ( V_56 , L_12 , & V_60 ) ;
if ( V_59 ) {
V_62 = * ( int * ) V_59 -> V_77 ;
if ( V_62 == 0 ) {
V_57 = V_56 ;
continue;
}
}
V_47 = V_62 & 0x7 ;
V_59 = F_44 ( V_56 , L_9 , & V_60 ) ;
if ( V_59 )
V_45 = * (struct V_79 * * )
V_59 -> V_77 ;
V_59 = F_44 ( V_56 , L_13 , & V_60 ) ;
if ( V_59 )
V_80 = * ( unsigned int * ) V_59 -> V_77 ;
} while ( 0 );
if ( ! ( V_45 && V_2 && V_80 ) )
goto V_75;
F_11 ( & V_45 -> V_46 [ V_47 ] . V_43 , 0 ) ;
F_11 ( & V_45 -> V_46 [ V_47 ] . V_42 ,
( ( ( 1000000 / V_67 ) - 1 ) ) ) ;
F_11 (
& V_45 -> V_46 [ V_47 ] . V_81 , 0 ) ;
#ifdef F_42
V_82 = V_80 + 1 + V_47 ;
if ( ! ( F_2 ( & V_45 -> V_83 ) &
( 1 << V_84 ) ) ) {
F_7 ( V_14 L_14 ) ;
F_46 () ;
}
F_11 ( & V_45 -> V_46 [ V_47 + 1 ] . V_43 ,
0 ) ;
F_11 ( & V_45 -> V_46 [ V_47 + 1 ] . V_42 ,
( ( ( 1000000 / V_67 ) - 1 ) ) ) ;
F_11 ( & V_45 -> V_46 [ V_47 + 1 ] . V_81 ,
0 ) ;
#endif
V_61 = F_2 ( & V_2 -> V_61 [ V_15 / 8 ] ) ;
V_61 = ( V_61 >> ( ( 7 - ( V_15 & 0x7 ) ) * 4 ) ) & 0xf ;
V_2 += V_61 ;
F_11 ( & V_2 -> V_11 [ V_15 ] , 0 ) ;
V_7 = ( F_2 ( & V_2 -> V_85 )
>> 16 ) & 0xf ;
if ( V_7 != 0 )
F_6 ( V_7 ) ;
V_4 = F_31 ( NULL , V_80 + V_47 ) ;
V_63 = F_47 ( V_4 , V_86 , V_87 , L_15 , NULL ) ;
if ( V_63 ) {
F_7 ( V_14 L_16 , V_4 ) ;
F_48 () ;
}
#ifdef F_42
{
unsigned long V_24 ;
F_49 ( V_24 ) ;
V_88 [ 0 ] = 0x01000000 ;
V_89 -> V_90 () ;
F_50 ( V_24 ) ;
}
#endif
F_11 ( & V_45 -> V_46 [ V_47 ] . V_81 ,
V_91 |
V_92 |
V_93 |
V_94 ) ;
#ifdef F_42
V_4 = F_8 ( V_82 , V_95 ,
L_17 , 0 ) ;
V_63 = F_47 ( V_4 , F_35 ,
V_96 | V_87 , L_18 ,
NULL ) ;
if ( V_63 ) {
F_7 ( V_14 L_19 , V_4 ) ;
F_48 () ;
}
F_11 ( & V_45 -> V_46 [ V_47 + 1 ] . V_81 ,
V_91 |
V_92 |
V_93 |
V_94 ) ;
#endif
return;
V_75:
F_7 ( V_14 L_20 ) ;
F_46 () ;
return;
}
static void F_51 ( void )
{
}
static void F_52 ( int V_1 , unsigned int V_97 )
{
}
void T_5 F_53 ( struct V_54 * V_98 )
{
if ( strcmp ( V_98 -> type , L_21 ) == 0 && strcmp ( V_98 -> V_35 , L_22 ) == 0 ) {
struct V_58 * V_9 ;
V_9 = F_44 ( V_98 , L_23 , ( void * ) 0 ) ;
if ( V_9 ) {
int V_99 ;
V_98 -> V_35 = F_54 ( 5 + 1 ) ;
memcpy ( & V_99 , V_9 -> V_77 , V_9 -> V_100 ) ;
sprintf ( ( char * ) V_98 -> V_35 , L_24 , V_99 ) ;
}
}
}
void F_37 ( int V_1 )
{
}
void F_55 ( unsigned int V_101 , unsigned int V_1 )
{
unsigned long V_11 , V_24 , * V_102 ;
V_11 = F_12 ( V_101 ) ;
F_20 ( & V_29 , V_24 ) ;
V_102 = ( unsigned long * ) F_10 ( V_1 ) ;
F_11 ( V_102 , ( F_2 ( V_102 ) | V_11 ) ) ;
F_21 ( & V_29 , V_24 ) ;
}
void T_5 F_56 ( void )
{
V_64 . V_103 = F_41 ;
V_64 . V_104 = F_31 ;
V_64 . V_105 = 1000000 ;
V_64 . V_106 = F_51 ;
V_64 . V_107 = F_52 ;
}
