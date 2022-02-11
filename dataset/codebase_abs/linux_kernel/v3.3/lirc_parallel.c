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
F_8 ( V_7 L_1 ,
V_8 ) ;
break;
}
}
static unsigned int F_9 ( void )
{
return F_1 ( V_9 ) & V_10 ;
}
static unsigned int F_10 ( void )
{
return F_1 ( V_11 ) & V_12 ;
}
static void F_11 ( void )
{
F_5 ( V_13 , V_14 ) ;
}
static void F_12 ( void )
{
F_5 ( V_13 , 0 ) ;
}
static unsigned int F_13 ( void )
{
struct V_15 V_16 , V_17 ;
unsigned int V_18 , V_19 , V_20 , V_21 ;
int V_22 = 0 ;
F_14 ( & V_16 ) ;
V_16 . V_23 ++ ;
V_18 = F_9 () ;
do {
V_19 = F_9 () ;
if ( V_18 == 0 && V_19 != 0 )
V_22 ++ ;
V_18 = V_19 ;
F_14 ( & V_17 ) ;
} while ( V_22 < 1000 && ( V_17 . V_23 < V_16 . V_23
|| ( V_17 . V_23 == V_16 . V_23
&& V_17 . V_24 < V_16 . V_24 ) ) );
V_20 = ( ( V_17 . V_23 + 1 - V_16 . V_23 ) * 1000000
+ ( V_17 . V_24 - V_16 . V_24 ) ) ;
if ( V_22 >= 1000 && V_20 > 0 ) {
if ( V_25 == 0 ) {
V_21 = ( 1000000 * V_22 ) / V_20 ;
F_8 ( V_7 L_2 ,
V_8 , V_21 ) ;
return V_21 ;
} else {
V_21 = ( 1000000 * V_22 ) / V_20 ;
if ( abs ( V_21 - V_25 ) > V_25 / 10 ) {
F_8 ( V_26 L_3 ,
V_8 , V_21 ) ;
F_8 ( V_26 L_4
L_5 ,
V_8 , V_25 ) ;
return V_25 ;
} else {
F_8 ( V_7 L_2 ,
V_8 , V_21 ) ;
return V_21 ;
}
}
} else {
F_8 ( V_26 L_6 , V_8 ) ;
return 0 ;
}
}
static int F_15 ( void )
{
if ( F_16 ( V_27 ) != 0 ) {
F_8 ( V_28 L_7 ,
V_8 ) ;
F_8 ( V_28 L_8
L_9 , V_8 ) ;
if ( F_17 ( V_27 ) < 0 ) {
F_8 ( V_26 L_10
L_11 , V_8 ) ;
return 0 ;
}
}
F_5 ( V_5 , V_29 | V_30 ) ;
V_31 = 1 ;
return 1 ;
}
static void F_18 ( int signal )
{
unsigned int V_32 ;
V_32 = ( V_33 + 1 ) & ( V_34 - 1 ) ;
if ( V_32 == V_35 ) {
V_36 ++ ;
F_8 ( V_26 L_12 , V_8 ) ;
return;
}
V_37 [ V_33 ] = signal ;
V_33 = V_32 ;
}
static void F_19 ( void * V_38 )
{
struct V_15 V_16 ;
static struct V_15 V_39 ;
static int V_40 ;
long signal ;
int V_41 ;
unsigned int V_18 , V_19 ;
unsigned int V_42 ;
if ( ! V_43 )
return;
if ( ! V_31 )
return;
#if 0
disable_irq(irq);
out(LIRC_PORT_IRQ, in(LIRC_PORT_IRQ) & (~LP_PINTEN));
#endif
if ( V_44 && ( F_1 ( 1 ) & V_45 ) )
return;
#ifdef F_20
if ( V_40 ) {
F_14 ( & V_16 ) ;
signal = V_16 . V_23 - V_39 . V_23 ;
if ( signal > 15 )
V_41 = V_46 ;
else
V_41 = ( int ) ( signal * 1000000 +
V_16 . V_24 - V_39 . V_24 +
V_47 ) ;
F_18 ( V_41 ) ;
} else {
if ( V_48 == 0 ) {
V_48 = F_13 () ;
return;
}
V_40 = 1 ;
}
V_42 = V_48 / 10 ;
signal = 1 ;
V_18 = F_9 () ;
do {
V_19 = F_9 () ;
if ( V_18 == 0 && V_19 != 0 )
signal ++ ;
V_18 = V_19 ;
if ( signal > V_42
|| ( V_44 && ( F_1 ( 1 ) & V_45 ) ) ) {
signal = 0 ;
F_8 ( V_26 L_13 , V_8 ) ;
break;
}
} while ( F_10 () );
if ( signal != 0 ) {
T_1 V_49 ;
V_49 = ( ( T_1 ) signal ) * 1000000 ;
F_21 ( V_49 , V_48 ) ;
signal = ( long ) V_49 ;
if ( signal > V_47 )
V_41 = signal - V_47 ;
else
V_41 = 1 ;
F_18 ( V_50 | V_41 ) ;
}
F_14 ( & V_39 ) ;
#else
#endif
F_22 ( & V_51 ) ;
}
static T_2 F_23 ( struct V_52 * V_53 , T_2 V_1 , int V_54 )
{
return - V_55 ;
}
static T_3 F_24 ( struct V_52 * V_53 , char * V_56 , T_4 V_57 , T_2 * V_58 )
{
int V_59 = 0 ;
int V_22 = 0 ;
F_25 ( V_60 , V_61 ) ;
if ( V_57 % sizeof( int ) )
return - V_62 ;
F_26 ( & V_51 , & V_60 ) ;
F_27 ( V_63 ) ;
while ( V_22 < V_57 ) {
if ( V_35 != V_33 ) {
if ( F_28 ( V_56 + V_22 , ( char * ) & V_37 [ V_35 ] ,
sizeof( int ) ) ) {
V_59 = - V_64 ;
break;
}
V_35 = ( V_35 + 1 ) & ( V_34 - 1 ) ;
V_22 += sizeof( int ) ;
} else {
if ( V_53 -> V_65 & V_66 ) {
V_59 = - V_67 ;
break;
}
if ( F_29 ( V_61 ) ) {
V_59 = - V_68 ;
break;
}
F_30 () ;
F_27 ( V_63 ) ;
}
}
F_31 ( & V_51 , & V_60 ) ;
F_27 ( V_69 ) ;
return V_22 ? V_22 : V_59 ;
}
static T_3 F_32 ( struct V_52 * V_53 , const char * V_56 , T_4 V_57 ,
T_2 * V_58 )
{
int V_22 ;
unsigned int V_70 ;
unsigned int V_18 , V_19 ;
unsigned long V_71 ;
int V_72 ;
int * V_73 ;
T_3 V_74 ;
if ( ! V_31 )
return - V_75 ;
V_22 = V_57 / sizeof( int ) ;
if ( V_57 % sizeof( int ) || V_22 % 2 == 0 )
return - V_62 ;
V_73 = F_33 ( V_56 , V_57 ) ;
if ( F_34 ( V_73 ) )
return F_35 ( V_73 ) ;
#ifdef F_20
if ( V_48 == 0 ) {
V_48 = F_13 () ;
if ( V_48 == 0 ) {
V_74 = - V_76 ;
goto F_5;
}
}
for ( V_70 = 0 ; V_70 < V_22 ; V_70 ++ ) {
T_1 V_49 ;
V_49 = ( ( T_1 ) V_73 [ V_70 ] ) * V_48 ;
F_21 ( V_49 , 1000000 ) ;
V_73 [ V_70 ] = ( int ) V_49 ;
}
F_36 ( V_71 ) ;
V_70 = 0 ;
while ( V_70 < V_22 ) {
V_18 = F_9 () ;
V_72 = 0 ;
F_11 () ;
do {
V_19 = F_9 () ;
if ( V_18 == 0 && V_19 != 0 )
V_72 ++ ;
V_18 = V_19 ;
if ( V_44 && ( F_1 ( 1 ) & V_45 ) ) {
F_12 () ;
F_37 ( V_71 ) ;
V_74 = - V_76 ;
goto F_5;
}
} while ( V_72 < V_73 [ V_70 ] );
V_70 ++ ;
F_12 () ;
if ( V_70 == V_22 )
break;
V_72 = 0 ;
do {
V_19 = F_9 () ;
if ( V_18 == 0 && V_19 != 0 )
V_72 ++ ;
V_18 = V_19 ;
if ( V_44 && ( F_1 ( 1 ) & V_45 ) ) {
F_37 ( V_71 ) ;
V_74 = - V_76 ;
goto F_5;
}
} while ( V_72 < V_73 [ V_70 ] );
V_70 ++ ;
}
F_37 ( V_71 ) ;
#else
#endif
V_74 = V_57 ;
F_5:
F_38 ( V_73 ) ;
return V_74 ;
}
static unsigned int F_39 ( struct V_52 * V_52 , T_5 * V_60 )
{
F_40 ( V_52 , & V_51 , V_60 ) ;
if ( V_35 != V_33 )
return V_77 | V_78 ;
return 0 ;
}
static long F_41 ( struct V_52 * V_53 , unsigned int V_79 , unsigned long V_80 )
{
int V_59 ;
T_6 V_81 = V_82 |
V_83 | V_84 ;
T_6 V_85 ;
T_6 V_6 ;
switch ( V_79 ) {
case V_86 :
V_59 = F_42 ( V_81 , ( T_6 * ) V_80 ) ;
if ( V_59 )
return V_59 ;
break;
case V_87 :
V_59 = F_42 ( V_88 , ( T_6 * ) V_80 ) ;
if ( V_59 )
return V_59 ;
break;
case V_89 :
V_59 = F_42 ( V_90 , ( T_6 * ) V_80 ) ;
if ( V_59 )
return V_59 ;
break;
case V_91 :
V_59 = F_43 ( V_85 , ( T_6 * ) V_80 ) ;
if ( V_59 )
return V_59 ;
if ( V_85 != V_88 )
return - V_62 ;
break;
case V_92 :
V_59 = F_43 ( V_85 , ( T_6 * ) V_80 ) ;
if ( V_59 )
return V_59 ;
if ( V_85 != V_90 )
return - V_93 ;
break;
case V_94 :
V_59 = F_43 ( V_6 , ( T_6 * ) V_80 ) ;
if ( V_59 )
return V_59 ;
if ( ( V_6 & V_95 ) != V_6 )
return V_96 ;
V_14 = V_6 ;
break;
default:
return - V_97 ;
}
return 0 ;
}
static int F_44 ( struct V_98 * V_99 , struct V_52 * V_53 )
{
if ( V_43 || ! F_15 () )
return - V_75 ;
F_45 ( V_3 ) ;
V_35 = 0 ;
V_33 = 0 ;
V_36 = 0 ;
V_43 = 1 ;
return 0 ;
}
static int F_46 ( struct V_98 * V_99 , struct V_52 * V_53 )
{
if ( V_31 ) {
V_31 = 0 ;
F_47 ( V_27 ) ;
}
V_43 = 0 ;
return 0 ;
}
static int F_48 ( void * V_41 )
{
return 0 ;
}
static void F_49 ( void * V_41 )
{
}
static int T_7 F_50 ( struct V_100 * V_101 )
{
return 0 ;
}
static int T_8 F_51 ( struct V_100 * V_101 )
{
return 0 ;
}
static int F_52 ( struct V_100 * V_101 ,
T_9 V_102 )
{
return 0 ;
}
static int F_53 ( struct V_100 * V_101 )
{
return 0 ;
}
static int F_54 ( void * V_103 )
{
F_55 ( V_3 ) ;
V_31 = 0 ;
return 0 ;
}
static void F_56 ( void * V_103 )
{
if ( ! V_43 )
return;
if ( ! F_15 () )
return;
F_45 ( V_3 ) ;
F_12 () ;
}
static int T_10 F_57 ( void )
{
int V_59 ;
V_59 = F_58 ( & V_104 ) ;
if ( V_59 ) {
F_8 ( V_26 L_14
L_15 , V_59 ) ;
return V_59 ;
}
V_105 = F_59 ( V_8 , 0 ) ;
if ( ! V_105 ) {
V_59 = - V_106 ;
goto V_107;
}
V_59 = F_60 ( V_105 ) ;
if ( V_59 )
goto V_108;
V_3 = F_61 ( V_109 ) ;
if ( V_3 == NULL ) {
F_8 ( V_26 L_16 ,
V_8 , V_109 ) ;
V_59 = - V_110 ;
goto V_108;
}
V_27 = F_62 ( V_3 , V_8 ,
F_54 , F_56 , F_19 , 0 , NULL ) ;
F_63 ( V_3 ) ;
if ( V_27 == NULL ) {
F_8 ( V_26 L_17 ,
V_8 ) ;
V_59 = - V_110 ;
goto V_108;
}
if ( F_16 ( V_27 ) != 0 )
goto V_111;
V_31 = 1 ;
F_5 ( V_5 , V_29 | V_30 ) ;
#ifdef F_20
if ( V_112 )
F_5 ( V_13 , V_14 ) ;
V_48 = F_13 () ;
#if 0
if (timer == 0) {
is_claimed = 0;
parport_release(pport);
parport_unregister_device(ppdevice);
result = -EIO;
goto exit_device_put;
}
#endif
if ( V_112 )
F_5 ( V_13 , 0 ) ;
#endif
V_31 = 0 ;
F_47 ( V_27 ) ;
V_111:
V_113 . V_101 = & V_105 -> V_101 ;
V_113 . V_114 = F_64 ( & V_113 ) ;
if ( V_113 . V_114 < 0 ) {
F_8 ( V_26 L_18 ,
V_8 ) ;
F_65 ( V_27 ) ;
V_59 = - V_76 ;
goto V_108;
}
F_8 ( V_7 L_19 ,
V_8 , V_109 , V_115 ) ;
return 0 ;
V_108:
F_66 ( V_105 ) ;
V_107:
F_67 ( & V_104 ) ;
return V_59 ;
}
static void T_11 F_68 ( void )
{
F_65 ( V_27 ) ;
F_69 ( V_113 . V_114 ) ;
F_70 ( V_105 ) ;
F_67 ( & V_104 ) ;
}
