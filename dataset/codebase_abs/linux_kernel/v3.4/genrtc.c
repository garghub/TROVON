static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 () ;
if ( V_4 ) {
V_5 = 0 ;
return;
}
if ( V_6 != V_3 ) {
V_6 = V_3 ;
V_7 . V_8 = V_9 ;
V_7 . V_10 = V_11 + V_12 - ( V_12 / 10 ) ;
V_13 = V_7 . V_10 ;
V_14 = 1 ;
V_5 = 0 ;
F_3 ( & V_7 ) ;
F_4 ( 0 ) ;
} else if ( F_5 ( & V_15 ) == 0 )
V_5 = 0 ;
}
static void V_9 ( unsigned long V_16 )
{
V_17 = F_2 () - V_6 ;
if ( V_17 < 0 )
V_17 = 60 - V_17 ;
if ( F_6 ( V_11 , V_13 ) )
F_7 ( V_18 L_1 ,
V_11 - V_13 ) ;
V_14 = 0 ;
V_5 = 1 ;
if ( ( F_5 ( & V_15 ) == 0 ) )
V_5 = 0 ;
}
static void F_4 ( unsigned long V_19 )
{
V_20 += 0x100 ;
V_20 &= ~ 0xff ;
V_20 |= V_21 ;
if ( V_17 ) {
F_7 ( L_2 ) ;
V_20 += ( ( V_17 - 1 ) << 8 ) ;
V_17 = 0 ;
}
F_8 ( & V_22 ) ;
}
static T_1 F_9 ( struct V_23 * V_23 , char T_2 * V_24 ,
T_3 V_25 , T_4 * V_26 )
{
unsigned long V_16 ;
T_1 V_27 ;
if ( V_25 != sizeof ( unsigned int ) && V_25 != sizeof ( unsigned long ) )
return - V_28 ;
if ( V_23 -> V_29 & V_30 && ! V_20 )
return - V_31 ;
V_27 = F_10 ( V_22 ,
( V_16 = F_11 ( & V_20 , 0 ) ) ) ;
if ( V_27 )
goto V_32;
if ( sizeof ( int ) != sizeof ( long ) && V_25 == sizeof ( unsigned int ) ) {
unsigned int V_33 = V_16 ;
V_27 = F_12 ( V_33 , ( unsigned int T_2 * ) V_24 ) ? :
sizeof( unsigned int ) ;
}
else {
V_27 = F_12 ( V_16 , ( unsigned long T_2 * ) V_24 ) ? :
sizeof( unsigned long ) ;
}
V_32:
return V_27 ;
}
static unsigned int F_13 ( struct V_23 * V_23 ,
struct V_34 * V_35 )
{
F_14 ( V_23 , & V_22 , V_35 ) ;
if ( V_20 != 0 )
return V_36 | V_37 ;
return 0 ;
}
static inline void F_15 ( unsigned char V_38 )
{
#ifdef F_16
V_4 = 1 ;
if ( V_14 ) {
F_17 ( & V_7 ) ;
V_14 = 0 ;
}
while ( V_5 )
F_18 () ;
F_19 ( & V_39 ) ;
V_40 = 0 ;
F_20 ( & V_39 ) ;
#endif
}
static inline int F_21 ( unsigned char V_38 )
{
#ifdef F_16
F_19 ( & V_39 ) ;
if ( ! V_40 ) {
V_40 = 1 ;
V_4 = 0 ;
V_17 = 0 ;
F_22 ( & V_15 , F_1 ) ;
V_6 = F_2 () ;
F_23 ( & V_7 ) ;
V_5 = 1 ;
if ( F_5 ( & V_15 ) == 0 ) {
V_5 = 0 ;
}
}
F_20 ( & V_39 ) ;
V_20 = 0 ;
return 0 ;
#else
return - V_28 ;
#endif
}
static int F_24 ( struct V_23 * V_23 ,
unsigned int V_41 , unsigned long V_19 )
{
struct V_42 V_43 ;
struct V_44 V_45 ;
void T_2 * V_46 = ( void T_2 * ) V_19 ;
switch ( V_41 ) {
case V_47 :
if ( F_25 ( & V_45 ) )
return - V_28 ;
else
return F_26 ( V_46 , & V_45 , sizeof V_45 ) ? - V_48 : 0 ;
case V_49 :
if ( ! F_27 ( V_50 ) )
return - V_51 ;
if ( F_28 ( & V_45 , V_46 , sizeof( V_45 ) ) )
return - V_48 ;
return F_29 ( & V_45 ) ;
case V_52 :
F_15 ( V_21 ) ;
return 0 ;
case V_53 :
return F_21 ( V_21 ) ;
case V_54 :
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
F_30 ( & V_43 ) ;
return F_26 ( V_46 , & V_43 , sizeof( V_43 ) ) ? - V_48 : 0 ;
case V_55 :
{
int V_56 ;
unsigned char V_57 ;
if ( ! F_27 ( V_50 ) )
return - V_51 ;
if ( F_28 ( & V_43 , V_46 , sizeof( V_43 ) ) )
return - V_48 ;
V_56 = V_43 . V_58 + 1900 ;
V_57 = ( ( ! ( V_56 % 4 ) && ( V_56 % 100 ) ) ||
! ( V_56 % 400 ) ) ;
if ( ( V_43 . V_59 < 0 || V_43 . V_59 > 11 ) || ( V_43 . V_60 < 1 ) )
return - V_28 ;
if ( V_43 . V_60 < 0 || V_43 . V_60 >
( V_61 [ V_43 . V_59 ] + ( ( V_43 . V_59 == 1 ) && V_57 ) ) )
return - V_28 ;
if ( V_43 . V_62 < 0 || V_43 . V_62 >= 24 ||
V_43 . V_63 < 0 || V_43 . V_63 >= 60 ||
V_43 . V_64 < 0 || V_43 . V_64 >= 60 )
return - V_28 ;
return F_31 ( & V_43 ) ;
}
}
return - V_28 ;
}
static long F_32 ( struct V_23 * V_23 , unsigned int V_41 ,
unsigned long V_19 )
{
int V_65 ;
F_33 ( & V_66 ) ;
V_65 = F_24 ( V_23 , V_41 , V_19 ) ;
F_34 ( & V_66 ) ;
return V_65 ;
}
static int F_35 ( struct V_67 * V_67 , struct V_23 * V_23 )
{
F_33 ( & V_66 ) ;
if ( V_68 & V_69 ) {
F_34 ( & V_66 ) ;
return - V_70 ;
}
V_68 |= V_69 ;
V_20 = 0 ;
V_40 = 0 ;
F_34 ( & V_66 ) ;
return 0 ;
}
static int F_36 ( struct V_67 * V_67 , struct V_23 * V_23 )
{
F_15 ( V_71 | V_72 | V_21 ) ;
V_68 &= ~ V_69 ;
return 0 ;
}
static int F_37 ( char * V_24 )
{
char * V_73 ;
struct V_42 V_74 ;
unsigned int V_75 ;
struct V_44 V_45 ;
V_73 = V_24 ;
V_75 = F_30 ( & V_74 ) ;
V_73 += sprintf ( V_73 ,
L_3
L_4
L_5 ,
V_74 . V_62 , V_74 . V_63 , V_74 . V_64 ,
V_74 . V_58 + 1900 , V_74 . V_59 + 1 , V_74 . V_60 , 1900 ) ;
V_74 . V_62 = V_74 . V_63 = V_74 . V_64 = 0 ;
V_73 += sprintf ( V_73 , L_6 ) ;
if ( V_74 . V_62 <= 24 )
V_73 += sprintf ( V_73 , L_7 , V_74 . V_62 ) ;
else
V_73 += sprintf ( V_73 , L_8 ) ;
if ( V_74 . V_63 <= 59 )
V_73 += sprintf ( V_73 , L_7 , V_74 . V_63 ) ;
else
V_73 += sprintf ( V_73 , L_8 ) ;
if ( V_74 . V_64 <= 59 )
V_73 += sprintf ( V_73 , L_9 , V_74 . V_64 ) ;
else
V_73 += sprintf ( V_73 , L_10 ) ;
V_73 += sprintf ( V_73 ,
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19 ,
( V_75 & V_76 ) ? L_20 : L_21 ,
( V_75 & V_77 ) ? L_21 : L_20 ,
( V_75 & V_78 ) ? L_20 : L_21 ,
( V_75 & V_79 ) ? L_20 : L_21 ,
( V_75 & V_72 ) ? L_20 : L_21 ,
V_40 ? L_20 : L_21 ,
( V_75 & V_71 ) ? L_20 : L_21 ,
0L ,
( V_75 & V_80 ) ? L_22 : L_23 ) ;
if ( ! F_25 ( & V_45 ) )
V_73 += sprintf ( V_73 ,
L_24
L_25
L_26
L_27
L_28
L_29 ,
V_45 . V_81 ,
V_45 . V_82 ,
V_45 . V_83 ,
V_45 . V_84 ,
V_45 . V_85 ,
V_45 . V_86 ) ;
return V_73 - V_24 ;
}
static int F_38 ( char * V_87 , char * * V_88 , T_5 V_89 ,
int V_25 , int * V_90 , void * V_16 )
{
int V_91 = F_37 ( V_87 ) ;
if ( V_91 <= V_89 + V_25 ) * V_90 = 1 ;
* V_88 = V_87 + V_89 ;
V_91 -= V_89 ;
if ( V_91 > V_25 ) V_91 = V_25 ;
if ( V_91 < 0 ) V_91 = 0 ;
return V_91 ;
}
static int T_6 F_39 ( void )
{
struct V_92 * V_93 ;
V_93 = F_40 ( L_30 , 0 , NULL , F_38 , NULL ) ;
if ( ! V_93 )
return - V_94 ;
return 0 ;
}
static inline int F_39 ( void ) { return 0 ; }
static int T_6 F_41 ( void )
{
int V_27 ;
F_7 ( V_18 L_31 , V_95 ) ;
V_27 = F_42 ( & V_96 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_39 () ;
if ( V_27 ) {
F_43 ( & V_96 ) ;
return V_27 ;
}
return 0 ;
}
static void T_7 F_44 ( void )
{
F_45 ( L_30 , NULL ) ;
F_43 ( & V_96 ) ;
}
