static unsigned int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return F_2 ( V_3 ) ;
case V_4 :
return F_3 ( V_3 ) ;
case V_5 :
return F_4 ( V_3 ) ;
}
return 0 ;
}
static void F_5 ( int V_1 , int V_6 )
{
switch ( V_1 ) {
case V_2 :
F_6 ( V_3 , V_6 ) ;
break;
case V_5 :
F_7 ( V_3 , V_6 ) ;
break;
case V_4 :
F_8 ( L_1 ) ;
break;
}
}
static unsigned int F_9 ( void )
{
return F_1 ( V_7 ) & V_8 ;
}
static unsigned int F_10 ( void )
{
return F_1 ( V_9 ) & V_10 ;
}
static void F_11 ( void )
{
F_5 ( V_11 , V_12 ) ;
}
static void F_12 ( void )
{
F_5 ( V_11 , 0 ) ;
}
static unsigned int F_13 ( void )
{
T_1 V_13 , V_14 , V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
int V_20 = 0 ;
V_13 = F_14 () ;
V_15 = F_15 ( V_13 , V_21 ) ;
V_16 = F_9 () ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
V_20 ++ ;
V_16 = V_17 ;
V_14 = F_14 () ;
} while ( V_20 < 1000 && ( F_16 ( V_14 , V_15 ) ) );
V_18 = F_17 ( V_14 , V_13 ) ;
if ( V_20 >= 1000 && V_18 > 0 ) {
if ( V_22 == 0 ) {
V_19 = ( 1000000 * V_20 ) / V_18 ;
F_8 ( L_2 , V_19 ) ;
return V_19 ;
}
V_19 = ( 1000000 * V_20 ) / V_18 ;
if ( abs ( V_19 - V_22 ) > V_22 / 10 ) {
F_18 ( L_3 , V_19 ) ;
F_18 ( L_4 ,
V_22 ) ;
return V_22 ;
}
F_8 ( L_2 , V_19 ) ;
return V_19 ;
}
F_18 ( L_5 ) ;
return 0 ;
}
static int F_19 ( void )
{
if ( F_20 ( V_23 ) != 0 ) {
F_21 ( L_6 ) ;
F_21 ( L_7 ) ;
if ( F_22 ( V_23 ) < 0 ) {
F_18 ( L_8 ) ;
return 0 ;
}
}
F_5 ( V_5 , V_24 | V_25 ) ;
V_26 = 1 ;
return 1 ;
}
static void F_23 ( int signal )
{
unsigned int V_27 ;
V_27 = ( V_28 + 1 ) & ( V_29 - 1 ) ;
if ( V_27 == V_30 ) {
V_31 ++ ;
F_18 ( L_9 ) ;
return;
}
V_32 [ V_28 ] = signal ;
V_28 = V_27 ;
}
static void F_24 ( void * V_33 )
{
T_1 V_13 , V_34 ;
static T_1 V_35 ;
static int V_36 ;
long signal ;
int V_37 ;
unsigned int V_16 , V_17 ;
unsigned int V_15 ;
if ( ! V_38 )
return;
if ( ! V_26 )
return;
#if 0
disable_irq(irq);
out(LIRC_PORT_IRQ, in(LIRC_PORT_IRQ) & (~LP_PINTEN));
#endif
if ( V_39 && ( F_1 ( 1 ) & V_40 ) )
return;
#ifdef F_25
if ( V_36 ) {
V_13 = F_14 () ;
V_34 = F_26 ( V_13 , V_35 ) ;
if ( F_27 ( V_34 , F_28 ( 15 , 0 ) ) > 0 )
V_37 = V_41 ;
else
V_37 = ( int ) ( F_29 ( V_34 ) + V_42 ) ;
F_23 ( V_37 ) ;
} else {
if ( V_43 == 0 ) {
V_43 = F_13 () ;
return;
}
V_36 = 1 ;
}
V_15 = V_43 / 10 ;
signal = 1 ;
V_16 = F_9 () ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
signal ++ ;
V_16 = V_17 ;
if ( signal > V_15
|| ( V_39 && ( F_1 ( 1 ) & V_40 ) ) ) {
signal = 0 ;
F_18 ( L_10 ) ;
break;
}
} while ( F_10 () );
if ( signal != 0 ) {
T_2 V_44 ;
V_44 = ( ( T_2 ) signal ) * 1000000 ;
F_30 ( V_44 , V_43 ) ;
signal = ( long ) V_44 ;
if ( signal > V_42 )
V_37 = signal - V_42 ;
else
V_37 = 1 ;
F_23 ( V_45 | V_37 ) ;
}
V_35 = F_14 () ;
#else
#endif
F_31 ( & V_46 ) ;
}
static T_3 F_32 ( struct V_47 * V_48 , T_3 V_1 , int V_49 )
{
return - V_50 ;
}
static T_4 F_33 ( struct V_47 * V_48 , char T_5 * V_51 , T_6 V_52 ,
T_3 * V_53 )
{
int V_54 = 0 ;
int V_20 = 0 ;
F_34 ( V_55 , V_56 ) ;
if ( V_52 % sizeof( int ) )
return - V_57 ;
F_35 ( & V_46 , & V_55 ) ;
F_36 ( V_58 ) ;
while ( V_20 < V_52 ) {
if ( V_30 != V_28 ) {
if ( F_37 ( V_51 + V_20 , & V_32 [ V_30 ] ,
sizeof( int ) ) ) {
V_54 = - V_59 ;
break;
}
V_30 = ( V_30 + 1 ) & ( V_29 - 1 ) ;
V_20 += sizeof( int ) ;
} else {
if ( V_48 -> V_60 & V_61 ) {
V_54 = - V_62 ;
break;
}
if ( F_38 ( V_56 ) ) {
V_54 = - V_63 ;
break;
}
F_39 () ;
F_36 ( V_58 ) ;
}
}
F_40 ( & V_46 , & V_55 ) ;
F_36 ( V_64 ) ;
return V_20 ? V_20 : V_54 ;
}
static T_4 F_41 ( struct V_47 * V_48 , const char T_5 * V_51 , T_6 V_52 ,
T_3 * V_53 )
{
int V_20 ;
unsigned int V_65 ;
unsigned int V_16 , V_17 ;
unsigned long V_66 ;
int V_67 ;
int * V_68 ;
T_4 V_69 ;
if ( ! V_26 )
return - V_70 ;
V_20 = V_52 / sizeof( int ) ;
if ( V_52 % sizeof( int ) || V_20 % 2 == 0 )
return - V_57 ;
V_68 = F_42 ( V_51 , V_52 ) ;
if ( F_43 ( V_68 ) )
return F_44 ( V_68 ) ;
#ifdef F_25
if ( V_43 == 0 ) {
V_43 = F_13 () ;
if ( V_43 == 0 ) {
V_69 = - V_71 ;
goto F_5;
}
}
for ( V_65 = 0 ; V_65 < V_20 ; V_65 ++ ) {
T_2 V_44 ;
V_44 = ( ( T_2 ) V_68 [ V_65 ] ) * V_43 ;
F_30 ( V_44 , 1000000 ) ;
V_68 [ V_65 ] = ( int ) V_44 ;
}
F_45 ( V_66 ) ;
V_65 = 0 ;
while ( V_65 < V_20 ) {
V_16 = F_9 () ;
V_67 = 0 ;
F_11 () ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
V_67 ++ ;
V_16 = V_17 ;
if ( V_39 && ( F_1 ( 1 ) & V_40 ) ) {
F_12 () ;
F_46 ( V_66 ) ;
V_69 = - V_71 ;
goto F_5;
}
} while ( V_67 < V_68 [ V_65 ] );
V_65 ++ ;
F_12 () ;
if ( V_65 == V_20 )
break;
V_67 = 0 ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
V_67 ++ ;
V_16 = V_17 ;
if ( V_39 && ( F_1 ( 1 ) & V_40 ) ) {
F_46 ( V_66 ) ;
V_69 = - V_71 ;
goto F_5;
}
} while ( V_67 < V_68 [ V_65 ] );
V_65 ++ ;
}
F_46 ( V_66 ) ;
#else
#endif
V_69 = V_52 ;
F_5:
F_47 ( V_68 ) ;
return V_69 ;
}
static unsigned int F_48 ( struct V_47 * V_47 , T_7 * V_55 )
{
F_49 ( V_47 , & V_46 , V_55 ) ;
if ( V_30 != V_28 )
return V_72 | V_73 ;
return 0 ;
}
static long F_50 ( struct V_47 * V_48 , unsigned int V_74 , unsigned long V_75 )
{
int V_54 ;
T_8 T_5 * V_76 = ( T_8 T_5 * ) V_75 ;
T_8 V_77 = V_78 |
V_79 | V_80 ;
T_8 V_81 ;
T_8 V_6 ;
switch ( V_74 ) {
case V_82 :
V_54 = F_51 ( V_77 , V_76 ) ;
if ( V_54 )
return V_54 ;
break;
case V_83 :
V_54 = F_51 ( V_84 , V_76 ) ;
if ( V_54 )
return V_54 ;
break;
case V_85 :
V_54 = F_51 ( V_86 , V_76 ) ;
if ( V_54 )
return V_54 ;
break;
case V_87 :
V_54 = F_52 ( V_81 , V_76 ) ;
if ( V_54 )
return V_54 ;
if ( V_81 != V_84 )
return - V_57 ;
break;
case V_88 :
V_54 = F_52 ( V_81 , V_76 ) ;
if ( V_54 )
return V_54 ;
if ( V_81 != V_86 )
return - V_89 ;
break;
case V_90 :
V_54 = F_52 ( V_6 , V_76 ) ;
if ( V_54 )
return V_54 ;
if ( ( V_6 & V_91 ) != V_6 )
return V_92 ;
V_12 = V_6 ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static int F_53 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
if ( V_38 || ! F_19 () )
return - V_70 ;
F_54 ( V_3 ) ;
V_30 = 0 ;
V_28 = 0 ;
V_31 = 0 ;
V_38 = 1 ;
return 0 ;
}
static int F_55 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
if ( V_26 ) {
V_26 = 0 ;
F_56 ( V_23 ) ;
}
V_38 = 0 ;
return 0 ;
}
static int F_57 ( void * V_37 )
{
return 0 ;
}
static void F_58 ( void * V_37 )
{
}
static int F_59 ( struct V_96 * V_97 )
{
return 0 ;
}
static int F_60 ( struct V_96 * V_97 )
{
return 0 ;
}
static int F_61 ( struct V_96 * V_97 ,
T_9 V_98 )
{
return 0 ;
}
static int F_62 ( struct V_96 * V_97 )
{
return 0 ;
}
static int F_63 ( void * V_99 )
{
F_64 ( V_3 ) ;
V_26 = 0 ;
return 0 ;
}
static void F_65 ( void * V_99 )
{
if ( ! V_38 )
return;
if ( ! F_19 () )
return;
F_54 ( V_3 ) ;
F_12 () ;
}
static int T_10 F_66 ( void )
{
int V_54 ;
V_54 = F_67 ( & V_100 ) ;
if ( V_54 ) {
F_18 ( L_11 , V_54 ) ;
return V_54 ;
}
V_101 = F_68 ( V_102 , 0 ) ;
if ( ! V_101 ) {
V_54 = - V_103 ;
goto V_104;
}
V_54 = F_69 ( V_101 ) ;
if ( V_54 )
goto V_105;
V_3 = F_70 ( V_106 ) ;
if ( ! V_3 ) {
F_18 ( L_12 , V_106 ) ;
V_54 = - V_107 ;
goto V_105;
}
V_23 = F_71 ( V_3 , V_102 ,
F_63 , F_65 , F_24 , 0 ,
NULL ) ;
F_72 ( V_3 ) ;
if ( ! V_23 ) {
F_18 ( L_13 ) ;
V_54 = - V_107 ;
goto V_105;
}
if ( F_20 ( V_23 ) != 0 )
goto V_108;
V_26 = 1 ;
F_5 ( V_5 , V_24 | V_25 ) ;
#ifdef F_25
if ( V_109 )
F_5 ( V_11 , V_12 ) ;
V_43 = F_13 () ;
#if 0
if (timer == 0) {
is_claimed = 0;
parport_release(pport);
parport_unregister_device(ppdevice);
result = -EIO;
goto exit_device_put;
}
#endif
if ( V_109 )
F_5 ( V_11 , 0 ) ;
#endif
V_26 = 0 ;
F_56 ( V_23 ) ;
V_108:
V_110 . V_97 = & V_101 -> V_97 ;
V_110 . V_111 = F_73 ( & V_110 ) ;
if ( V_110 . V_111 < 0 ) {
F_18 ( L_14 ) ;
F_74 ( V_23 ) ;
V_54 = - V_71 ;
goto V_105;
}
F_8 ( L_15 , V_106 , V_112 ) ;
return 0 ;
V_105:
F_75 ( V_101 ) ;
V_104:
F_76 ( & V_100 ) ;
return V_54 ;
}
static void T_11 F_77 ( void )
{
F_74 ( V_23 ) ;
F_78 ( V_110 . V_111 ) ;
F_79 ( V_101 ) ;
F_76 ( & V_100 ) ;
}
