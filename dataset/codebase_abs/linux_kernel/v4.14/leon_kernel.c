static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( & V_2 -> V_3 [ V_1 ] ) & 0x1f ;
}
static void F_3 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
struct V_7 * V_8 ;
int V_1 = F_4 () ;
V_6 = F_1 ( V_1 ) ;
V_8 = V_9 [ V_6 ] ;
if ( ( V_6 & 0x10 ) && V_8 && V_8 -> V_10 )
F_5 ( V_8 -> V_10 ) ;
}
static void F_6 ( unsigned int V_6 )
{
unsigned long V_11 , V_12 ;
unsigned int V_13 ;
if ( V_6 < 1 || V_6 > 0xf ) {
F_7 ( V_14 L_1 , V_6 ) ;
return;
}
V_13 = F_8 ( V_6 , F_3 , L_2 , 0 ) ;
F_9 ( V_13 ) ;
V_11 = 1 << V_6 ;
V_12 = F_2 ( F_10 ( V_15 ) ) ;
F_11 ( F_10 ( V_15 ) , ( V_12 | V_11 ) ) ;
V_16 = V_6 ;
}
unsigned long F_12 ( unsigned int V_10 )
{
unsigned long V_11 ;
if ( ! V_10 || ( ( V_10 > 0xf ) && ! V_16 )
|| ( ( V_10 > 0x1f ) && V_16 ) ) {
F_7 ( V_14
L_3 , V_10 ) ;
V_11 = 0 ;
} else {
V_11 = F_13 ( V_10 ) ;
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
V_25 = F_14 ( F_20 ( V_21 ) ) ;
V_26 = F_14 ( V_22 ) ;
if ( V_25 == V_26 )
goto V_28;
F_21 ( & V_29 , V_24 ) ;
V_12 = F_2 ( F_10 ( V_25 ) ) ;
F_11 ( F_10 ( V_25 ) , ( V_12 & ~ V_11 ) ) ;
V_12 = F_2 ( F_10 ( V_26 ) ) ;
F_11 ( F_10 ( V_26 ) , ( V_12 | V_11 ) ) ;
F_22 ( & V_29 , V_24 ) ;
V_28:
return V_30 ;
}
static void F_23 ( struct V_20 * V_21 )
{
unsigned long V_11 , V_12 , V_24 ;
int V_1 ;
V_11 = ( unsigned long ) V_21 -> V_27 ;
V_1 = F_14 ( F_20 ( V_21 ) ) ;
F_21 ( & V_29 , V_24 ) ;
V_12 = F_2 ( F_10 ( V_1 ) ) ;
F_11 ( F_10 ( V_1 ) , ( V_12 | V_11 ) ) ;
F_22 ( & V_29 , V_24 ) ;
}
static void F_24 ( struct V_20 * V_21 )
{
unsigned long V_11 , V_12 , V_24 ;
int V_1 ;
V_11 = ( unsigned long ) V_21 -> V_27 ;
V_1 = F_14 ( F_20 ( V_21 ) ) ;
F_21 ( & V_29 , V_24 ) ;
V_12 = F_2 ( F_10 ( V_1 ) ) ;
F_11 ( F_10 ( V_1 ) , ( V_12 & ~ V_11 ) ) ;
F_22 ( & V_29 , V_24 ) ;
}
static unsigned int F_25 ( struct V_20 * V_21 )
{
F_9 ( V_21 -> V_10 ) ;
F_23 ( V_21 ) ;
return 0 ;
}
static void F_26 ( struct V_20 * V_21 )
{
F_24 ( V_21 ) ;
F_27 ( V_21 -> V_10 ) ;
}
static void F_28 ( struct V_20 * V_21 )
{
unsigned long V_11 = ( unsigned long ) V_21 -> V_27 ;
if ( V_11 & V_31 )
F_11 ( V_32 , V_11 & ~ V_31 ) ;
}
unsigned int F_8 ( unsigned int V_33 ,
T_2 V_34 ,
const char * V_35 , int V_36 )
{
unsigned int V_10 ;
unsigned long V_11 ;
struct V_4 * V_5 ;
V_10 = 0 ;
V_11 = F_12 ( V_33 ) ;
if ( V_11 == 0 )
goto V_28;
V_10 = F_29 ( V_33 , V_33 ) ;
if ( V_10 == 0 )
goto V_28;
if ( V_36 )
V_11 |= V_31 ;
V_5 = F_30 ( V_10 ) ;
if ( ! V_5 || ! V_5 -> V_37 || V_5 -> V_37 == V_38 ) {
F_31 ( V_10 , & V_39 ,
V_34 , V_35 ) ;
F_32 ( V_10 , ( void * ) V_11 ) ;
}
V_28:
return V_10 ;
}
static unsigned int F_33 ( struct V_40 * V_41 ,
unsigned int V_33 )
{
return F_8 ( V_33 , V_42 , L_4 , 0 ) ;
}
void F_34 ( unsigned int V_43 ,
T_2 V_34 ,
const char * V_35 , int V_36 )
{
unsigned long V_11 = ( unsigned long ) F_35 ( V_43 ) ;
V_11 &= ~ V_31 ;
if ( V_36 )
V_11 |= V_31 ;
F_31 ( V_43 , & V_39 ,
V_34 , V_35 ) ;
F_32 ( V_43 , ( void * ) V_11 ) ;
}
static T_3 F_36 ( void )
{
T_3 V_44 , V_45 , V_46 , V_47 ;
V_44 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_44 ) ;
V_45 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_45 ) ;
V_46 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_46 ) ;
if ( F_37 ( V_46 ) ) {
V_45 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_45 ) ;
V_47 = 2 * V_44 - V_45 ;
} else {
V_47 = V_44 - V_45 ;
}
return V_47 ;
}
static T_4 F_38 ( int V_10 , void * V_51 )
{
struct V_52 * V_53 ;
int V_1 = F_39 () ;
F_40 ( V_1 ) ;
if ( V_1 == V_15 )
F_41 ( V_10 , NULL ) ;
V_53 = & F_42 ( V_54 , V_1 ) ;
F_43 () ;
if ( V_53 -> V_55 )
V_53 -> V_55 ( V_53 ) ;
F_44 () ;
return V_56 ;
}
void T_5 F_45 ( void )
{
int V_10 , V_6 ;
struct V_57 * V_58 , * V_59 , * V_60 ;
struct V_61 * V_62 ;
int V_63 ;
int V_64 ;
int V_65 ;
int V_66 ;
T_3 V_67 ;
T_3 V_46 ;
V_68 . V_69 = F_36 ;
V_68 . V_70 = 1000000 / V_71 ;
V_68 . V_72 |= V_73 ;
#ifndef F_46
V_68 . V_72 |= V_74 ;
#endif
V_75 = 0 ;
V_76 = 0 ;
V_77 = ( T_3 V_78 * ) & V_79 ;
V_79 = 0 ;
V_58 = F_47 ( L_5 ) ;
if ( ! V_58 )
goto V_80;
V_62 = F_48 ( V_58 , L_6 , & V_63 ) ;
if ( V_62 )
V_81 = * ( unsigned long * ) V_62 -> V_82 ;
V_59 = F_49 ( V_58 , L_7 ) ;
if ( ! V_59 ) {
V_59 = F_49 ( V_58 , L_8 ) ;
if ( ! V_59 )
goto V_80;
}
V_62 = F_48 ( V_59 , L_9 , & V_63 ) ;
if ( ! V_62 )
goto V_80;
V_2 = * (struct V_83 * * ) V_62 -> V_82 ;
V_60 = V_58 ;
V_84:
V_59 = F_49 ( V_60 , L_10 ) ;
if ( ! V_59 ) {
V_59 = F_49 ( V_60 , L_11 ) ;
if ( ! V_59 )
goto V_80;
}
V_65 = 0 ;
V_62 = F_48 ( V_59 , L_12 , & V_63 ) ;
if ( V_62 ) {
V_65 = * ( int * ) V_62 -> V_82 ;
if ( V_65 == 0 ) {
V_60 = V_59 ;
goto V_84;
}
}
V_50 = V_65 & 0x7 ;
V_62 = F_48 ( V_59 , L_9 , & V_63 ) ;
if ( V_62 )
V_48 = * (struct V_85 * * )
V_62 -> V_82 ;
V_62 = F_48 ( V_59 , L_13 , & V_63 ) ;
if ( V_62 )
V_86 = * ( unsigned int * ) V_62 -> V_82 ;
if ( ! ( V_48 && V_2 && V_86 ) )
goto V_80;
V_46 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_46 ) ;
F_11 ( & V_48 -> V_49 [ V_50 ] . V_46 ,
V_46 | V_87 ) ;
V_46 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_46 ) ;
if ( ( V_46 & V_87 ) != 0 )
V_88 = ~ V_87 ;
else
V_88 = ~ 0 ;
F_11 ( & V_48 -> V_49 [ V_50 ] . V_45 , 0 ) ;
F_11 ( & V_48 -> V_49 [ V_50 ] . V_44 ,
( ( ( 1000000 / V_71 ) - 1 ) ) ) ;
F_11 (
& V_48 -> V_49 [ V_50 ] . V_46 , 0 ) ;
V_64 = F_2 ( & V_2 -> V_64 [ V_15 / 8 ] ) ;
V_64 = ( V_64 >> ( ( 7 - ( V_15 & 0x7 ) ) * 4 ) ) & 0xf ;
V_2 += V_64 ;
F_11 ( & V_2 -> V_11 [ V_15 ] , 0 ) ;
V_6 = ( F_2 ( & V_2 -> V_89 )
>> 16 ) & 0xf ;
if ( V_6 != 0 )
F_6 ( V_6 ) ;
#ifdef F_46
{
unsigned long V_24 ;
F_50 ( V_24 ) ;
V_90 [ 0 ] = 0x01000000 ;
V_91 -> V_92 () ;
F_51 ( V_24 ) ;
}
#endif
V_67 = F_2 ( & V_48 -> V_67 ) ;
if ( V_67 & ( 1 << V_93 ) )
V_86 += V_50 ;
else if ( ( V_67 & V_94 ) > 1 )
F_52 ( L_14 ) ;
#ifdef F_46
V_10 = F_8 ( V_86 , V_95 ,
L_15 , 0 ) ;
V_66 = F_53 ( V_10 , F_38 ,
V_96 | V_97 , L_16 , NULL ) ;
#else
V_10 = F_33 ( NULL , V_86 ) ;
V_66 = F_53 ( V_10 , F_41 , V_97 , L_16 , NULL ) ;
#endif
if ( V_66 ) {
F_54 ( L_17 , V_10 ) ;
F_55 () ;
}
F_11 ( & V_48 -> V_49 [ V_50 ] . V_46 ,
V_98 |
V_99 |
V_100 |
V_101 ) ;
return;
V_80:
F_7 ( V_14 L_18 ) ;
F_56 () ;
return;
}
static void F_57 ( void )
{
T_3 V_46 ;
V_46 = F_2 ( & V_48 -> V_49 [ V_50 ] . V_46 ) ;
F_11 ( & V_48 -> V_49 [ V_50 ] . V_46 ,
V_46 & V_88 ) ;
}
static void F_58 ( int V_1 , unsigned int V_102 )
{
}
void T_5 F_59 ( struct V_57 * V_103 )
{
if ( strcmp ( V_103 -> type , L_19 ) == 0 && strcmp ( V_103 -> V_35 , L_20 ) == 0 ) {
struct V_61 * V_8 ;
V_8 = F_48 ( V_103 , L_21 , ( void * ) 0 ) ;
if ( V_8 ) {
int V_104 ;
V_103 -> V_35 = F_60 ( 5 + 1 ) ;
memcpy ( & V_104 , V_8 -> V_82 , V_8 -> V_105 ) ;
sprintf ( ( char * ) V_103 -> V_35 , L_22 , V_104 ) ;
}
}
}
void F_40 ( int V_1 )
{
}
void F_61 ( unsigned int V_106 , unsigned int V_1 )
{
unsigned long V_11 , V_24 , * V_107 ;
V_11 = F_12 ( V_106 ) ;
F_21 ( & V_29 , V_24 ) ;
V_107 = ( unsigned long * ) F_10 ( V_1 ) ;
F_11 ( V_107 , ( F_2 ( V_107 ) | V_11 ) ) ;
F_22 ( & V_29 , V_24 ) ;
}
void T_5 F_62 ( void )
{
V_68 . V_108 = F_45 ;
V_68 . V_109 = F_33 ;
V_68 . V_110 = 1000000 ;
V_68 . V_111 = F_57 ;
V_68 . V_112 = F_58 ;
}
