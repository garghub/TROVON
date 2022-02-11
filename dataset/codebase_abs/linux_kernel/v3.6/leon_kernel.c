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
unsigned long F_12 ( unsigned int V_4 )
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
static T_3 F_34 ( void )
{
T_3 V_40 , V_41 , V_42 ;
V_40 = F_2 ( & V_43 -> V_44 [ V_45 ] . V_40 ) ;
V_41 = F_2 ( & V_43 -> V_44 [ V_45 ] . V_41 ) ;
V_42 = V_40 - V_41 ;
return V_40 - V_41 ;
}
T_4 F_35 ( int V_4 , void * V_46 )
{
struct V_47 * V_48 ;
int V_1 = F_36 () ;
F_37 ( V_1 ) ;
V_48 = & F_38 ( V_49 , V_1 ) ;
F_39 () ;
if ( V_48 -> V_50 )
V_48 -> V_50 ( V_48 ) ;
F_40 () ;
return V_51 ;
}
void T_5 F_41 ( void )
{
int V_4 , V_7 ;
struct V_52 * V_53 , * V_54 , * V_55 ;
struct V_56 * V_57 ;
int V_58 ;
int V_59 ;
int V_60 ;
int V_61 ;
V_62 . V_63 = F_34 ;
V_62 . V_64 = 1000000 / V_65 ;
V_62 . V_66 |= V_67 ;
#ifndef F_42
V_62 . V_66 |= V_68 ;
#endif
V_69 = 0 ;
V_70 = 0 ;
V_71 = ( unsigned int * ) & V_72 ;
V_72 = 0 ;
V_53 = F_43 ( L_5 ) ;
if ( ! V_53 )
goto V_73;
V_57 = F_44 ( V_53 , L_6 , & V_58 ) ;
if ( V_57 )
V_74 = * ( unsigned long * ) V_57 -> V_75 ;
V_54 = F_45 ( V_53 , L_7 ) ;
if ( ! V_54 ) {
V_54 = F_45 ( V_53 , L_8 ) ;
if ( ! V_54 )
goto V_73;
}
V_57 = F_44 ( V_54 , L_9 , & V_58 ) ;
if ( ! V_57 )
goto V_73;
V_2 = * (struct V_76 * * ) V_57 -> V_75 ;
V_55 = V_53 ;
do {
V_54 = F_45 ( V_55 , L_10 ) ;
if ( ! V_54 ) {
V_54 = F_45 ( V_55 , L_11 ) ;
if ( ! V_54 )
goto V_73;
}
V_60 = 0 ;
V_57 = F_44 ( V_54 , L_12 , & V_58 ) ;
if ( V_57 ) {
V_60 = * ( int * ) V_57 -> V_75 ;
if ( V_60 == 0 ) {
V_55 = V_54 ;
continue;
}
}
V_45 = V_60 & 0x7 ;
V_57 = F_44 ( V_54 , L_9 , & V_58 ) ;
if ( V_57 )
V_43 = * (struct V_77 * * )
V_57 -> V_75 ;
V_57 = F_44 ( V_54 , L_13 , & V_58 ) ;
if ( V_57 )
V_78 = * ( unsigned int * ) V_57 -> V_75 ;
} while ( 0 );
if ( ! ( V_43 && V_2 && V_78 ) )
goto V_73;
F_11 ( & V_43 -> V_44 [ V_45 ] . V_41 , 0 ) ;
F_11 ( & V_43 -> V_44 [ V_45 ] . V_40 ,
( ( ( 1000000 / V_65 ) - 1 ) ) ) ;
F_11 (
& V_43 -> V_44 [ V_45 ] . V_79 , 0 ) ;
#ifdef F_42
V_80 = V_78 + 1 + V_45 ;
if ( ! ( F_2 ( & V_43 -> V_81 ) &
( 1 << V_82 ) ) ) {
F_7 ( V_12 L_14 ) ;
F_46 () ;
}
F_11 ( & V_43 -> V_44 [ V_45 + 1 ] . V_41 ,
0 ) ;
F_11 ( & V_43 -> V_44 [ V_45 + 1 ] . V_40 ,
( ( ( 1000000 / V_65 ) - 1 ) ) ) ;
F_11 ( & V_43 -> V_44 [ V_45 + 1 ] . V_79 ,
0 ) ;
#endif
V_59 = F_2 ( & V_2 -> V_59 [ V_13 / 8 ] ) ;
V_59 = ( V_59 >> ( ( 7 - ( V_13 & 0x7 ) ) * 4 ) ) & 0xf ;
V_2 += V_59 ;
F_11 ( & V_2 -> V_9 [ V_13 ] , 0 ) ;
V_7 = ( F_2 ( & V_2 -> V_83 )
>> 16 ) & 0xf ;
if ( V_7 != 0 )
F_6 ( V_7 ) ;
V_4 = F_31 ( NULL , V_78 + V_45 ) ;
V_61 = F_47 ( V_4 , V_84 , V_85 , L_15 , NULL ) ;
if ( V_61 ) {
F_7 ( V_12 L_16 , V_4 ) ;
F_48 () ;
}
#ifdef F_42
{
unsigned long V_22 ;
F_49 ( V_22 ) ;
V_86 [ 0 ] = 0x01000000 ;
V_87 -> V_88 () ;
F_50 ( V_22 ) ;
}
#endif
F_11 ( & V_43 -> V_44 [ V_45 ] . V_79 ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
#ifdef F_42
V_4 = F_8 ( V_80 , V_93 ,
L_17 , 0 ) ;
V_61 = F_47 ( V_4 , F_35 ,
V_94 | V_85 , L_18 ,
NULL ) ;
if ( V_61 ) {
F_7 ( V_12 L_19 , V_4 ) ;
F_48 () ;
}
F_11 ( & V_43 -> V_44 [ V_45 + 1 ] . V_79 ,
V_89 |
V_90 |
V_91 |
V_92 ) ;
#endif
return;
V_73:
F_7 ( V_12 L_20 ) ;
F_46 () ;
return;
}
static void F_51 ( void )
{
}
static void F_52 ( int V_1 , unsigned int V_95 )
{
}
void T_5 F_53 ( struct V_52 * V_96 )
{
if ( strcmp ( V_96 -> type , L_21 ) == 0 && strcmp ( V_96 -> V_33 , L_22 ) == 0 ) {
struct V_56 * V_97 ;
V_97 = F_44 ( V_96 , L_23 , ( void * ) 0 ) ;
if ( V_97 ) {
int V_98 ;
V_96 -> V_33 = F_54 ( 5 + 1 ) ;
memcpy ( & V_98 , V_97 -> V_75 , V_97 -> V_99 ) ;
sprintf ( ( char * ) V_96 -> V_33 , L_24 , V_98 ) ;
}
}
}
void F_37 ( int V_1 )
{
}
void F_55 ( unsigned int V_100 , unsigned int V_1 )
{
unsigned long V_9 , V_22 , * V_101 ;
V_9 = F_12 ( V_100 ) ;
F_20 ( & V_27 , V_22 ) ;
V_101 = ( unsigned long * ) F_10 ( V_1 ) ;
F_11 ( V_101 , ( F_2 ( V_101 ) | V_9 ) ) ;
F_21 ( & V_27 , V_22 ) ;
}
void T_5 F_56 ( void )
{
V_62 . V_102 = F_41 ;
V_62 . V_103 = F_31 ;
V_62 . V_104 = 1000000 ;
V_62 . V_105 = F_51 ;
V_62 . V_106 = F_52 ;
}
