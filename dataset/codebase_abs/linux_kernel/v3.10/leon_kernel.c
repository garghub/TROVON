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
struct V_5 * V_6 ;
V_4 = 0 ;
V_11 = F_12 ( V_33 ) ;
if ( V_11 == 0 )
goto V_28;
V_4 = F_28 ( V_33 , V_33 ) ;
if ( V_4 == 0 )
goto V_28;
if ( V_36 )
V_11 |= V_31 ;
V_6 = F_29 ( V_4 ) ;
if ( ! V_6 || ! V_6 -> V_37 || V_6 -> V_37 == V_38 ) {
F_30 ( V_4 , & V_39 ,
V_34 , V_35 ) ;
F_31 ( V_4 , ( void * ) V_11 ) ;
}
V_28:
return V_4 ;
}
static unsigned int F_32 ( struct V_40 * V_41 ,
unsigned int V_33 )
{
return F_8 ( V_33 , V_42 , L_4 , 0 ) ;
}
void F_33 ( unsigned int V_43 ,
T_2 V_34 ,
const char * V_35 , int V_36 )
{
unsigned long V_11 = ( unsigned long ) F_34 ( V_43 ) ;
V_11 &= ~ V_31 ;
if ( V_36 )
V_11 |= V_31 ;
F_30 ( V_43 , & V_39 ,
V_34 , V_35 ) ;
F_31 ( V_43 , ( void * ) V_11 ) ;
}
static T_3 F_35 ( void )
{
T_3 V_44 , V_45 , V_46 ;
V_44 = F_2 ( & V_47 -> V_48 [ V_49 ] . V_44 ) ;
V_45 = F_2 ( & V_47 -> V_48 [ V_49 ] . V_45 ) ;
V_46 = V_44 - V_45 ;
return V_44 - V_45 ;
}
T_4 F_36 ( int V_4 , void * V_50 )
{
struct V_51 * V_52 ;
int V_1 = F_37 () ;
F_38 ( V_1 ) ;
if ( V_1 == V_15 )
F_39 ( V_4 , NULL ) ;
V_52 = & F_40 ( V_53 , V_1 ) ;
F_41 () ;
if ( V_52 -> V_54 )
V_52 -> V_54 ( V_52 ) ;
F_42 () ;
return V_55 ;
}
void T_5 F_43 ( void )
{
int V_4 , V_7 ;
struct V_56 * V_57 , * V_58 , * V_59 ;
struct V_60 * V_61 ;
int V_62 ;
int V_63 ;
int V_64 ;
int V_65 ;
T_3 V_66 ;
V_67 . V_68 = F_35 ;
V_67 . V_69 = 1000000 / V_70 ;
V_67 . V_71 |= V_72 ;
#ifndef F_44
V_67 . V_71 |= V_73 ;
#endif
V_74 = 0 ;
V_75 = 0 ;
V_76 = ( unsigned int * ) & V_77 ;
V_77 = 0 ;
V_57 = F_45 ( L_5 ) ;
if ( ! V_57 )
goto V_78;
V_61 = F_46 ( V_57 , L_6 , & V_62 ) ;
if ( V_61 )
V_79 = * ( unsigned long * ) V_61 -> V_80 ;
V_58 = F_47 ( V_57 , L_7 ) ;
if ( ! V_58 ) {
V_58 = F_47 ( V_57 , L_8 ) ;
if ( ! V_58 )
goto V_78;
}
V_61 = F_46 ( V_58 , L_9 , & V_62 ) ;
if ( ! V_61 )
goto V_78;
V_2 = * (struct V_81 * * ) V_61 -> V_80 ;
V_59 = V_57 ;
do {
V_58 = F_47 ( V_59 , L_10 ) ;
if ( ! V_58 ) {
V_58 = F_47 ( V_59 , L_11 ) ;
if ( ! V_58 )
goto V_78;
}
V_64 = 0 ;
V_61 = F_46 ( V_58 , L_12 , & V_62 ) ;
if ( V_61 ) {
V_64 = * ( int * ) V_61 -> V_80 ;
if ( V_64 == 0 ) {
V_59 = V_58 ;
continue;
}
}
V_49 = V_64 & 0x7 ;
V_61 = F_46 ( V_58 , L_9 , & V_62 ) ;
if ( V_61 )
V_47 = * (struct V_82 * * )
V_61 -> V_80 ;
V_61 = F_46 ( V_58 , L_13 , & V_62 ) ;
if ( V_61 )
V_83 = * ( unsigned int * ) V_61 -> V_80 ;
} while ( 0 );
if ( ! ( V_47 && V_2 && V_83 ) )
goto V_78;
F_11 ( & V_47 -> V_48 [ V_49 ] . V_45 , 0 ) ;
F_11 ( & V_47 -> V_48 [ V_49 ] . V_44 ,
( ( ( 1000000 / V_70 ) - 1 ) ) ) ;
F_11 (
& V_47 -> V_48 [ V_49 ] . V_84 , 0 ) ;
V_63 = F_2 ( & V_2 -> V_63 [ V_15 / 8 ] ) ;
V_63 = ( V_63 >> ( ( 7 - ( V_15 & 0x7 ) ) * 4 ) ) & 0xf ;
V_2 += V_63 ;
F_11 ( & V_2 -> V_11 [ V_15 ] , 0 ) ;
V_7 = ( F_2 ( & V_2 -> V_85 )
>> 16 ) & 0xf ;
if ( V_7 != 0 )
F_6 ( V_7 ) ;
#ifdef F_44
{
unsigned long V_24 ;
F_48 ( V_24 ) ;
V_86 [ 0 ] = 0x01000000 ;
V_87 -> V_88 () ;
F_49 ( V_24 ) ;
}
#endif
V_66 = F_2 ( & V_47 -> V_66 ) ;
if ( V_66 & ( 1 << V_89 ) )
V_83 += V_49 ;
else if ( ( V_66 & V_90 ) > 1 )
F_50 ( L_14 ) ;
#ifdef F_44
V_4 = F_8 ( V_83 , V_91 ,
L_15 , 0 ) ;
V_65 = F_51 ( V_4 , F_36 ,
V_92 | V_93 , L_16 , NULL ) ;
#else
V_4 = F_32 ( NULL , V_83 ) ;
V_65 = F_51 ( V_4 , F_39 , V_93 , L_16 , NULL ) ;
#endif
if ( V_65 ) {
F_52 ( L_17 , V_4 ) ;
F_53 () ;
}
F_11 ( & V_47 -> V_48 [ V_49 ] . V_84 ,
V_94 |
V_95 |
V_96 |
V_97 ) ;
return;
V_78:
F_7 ( V_14 L_18 ) ;
F_54 () ;
return;
}
static void F_55 ( void )
{
}
static void F_56 ( int V_1 , unsigned int V_98 )
{
}
void T_5 F_57 ( struct V_56 * V_99 )
{
if ( strcmp ( V_99 -> type , L_19 ) == 0 && strcmp ( V_99 -> V_35 , L_20 ) == 0 ) {
struct V_60 * V_9 ;
V_9 = F_46 ( V_99 , L_21 , ( void * ) 0 ) ;
if ( V_9 ) {
int V_100 ;
V_99 -> V_35 = F_58 ( 5 + 1 ) ;
memcpy ( & V_100 , V_9 -> V_80 , V_9 -> V_101 ) ;
sprintf ( ( char * ) V_99 -> V_35 , L_22 , V_100 ) ;
}
}
}
void F_38 ( int V_1 )
{
}
void F_59 ( unsigned int V_102 , unsigned int V_1 )
{
unsigned long V_11 , V_24 , * V_103 ;
V_11 = F_12 ( V_102 ) ;
F_20 ( & V_29 , V_24 ) ;
V_103 = ( unsigned long * ) F_10 ( V_1 ) ;
F_11 ( V_103 , ( F_2 ( V_103 ) | V_11 ) ) ;
F_21 ( & V_29 , V_24 ) ;
}
void T_5 F_60 ( void )
{
V_67 . V_104 = F_43 ;
V_67 . V_105 = F_32 ;
V_67 . V_106 = 1000000 ;
V_67 . V_107 = F_55 ;
V_67 . V_108 = F_56 ;
}
