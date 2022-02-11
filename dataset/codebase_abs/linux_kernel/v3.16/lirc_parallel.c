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
struct V_13 V_14 , V_15 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
int V_20 = 0 ;
F_14 ( & V_14 ) ;
V_14 . V_21 ++ ;
V_16 = F_9 () ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
V_20 ++ ;
V_16 = V_17 ;
F_14 ( & V_15 ) ;
} while ( V_20 < 1000 && ( V_15 . V_21 < V_14 . V_21
|| ( V_15 . V_21 == V_14 . V_21
&& V_15 . V_22 < V_14 . V_22 ) ) );
V_18 = ( ( V_15 . V_21 + 1 - V_14 . V_21 ) * 1000000
+ ( V_15 . V_22 - V_14 . V_22 ) ) ;
if ( V_20 >= 1000 && V_18 > 0 ) {
if ( V_23 == 0 ) {
V_19 = ( 1000000 * V_20 ) / V_18 ;
F_8 ( L_2 , V_19 ) ;
return V_19 ;
} else {
V_19 = ( 1000000 * V_20 ) / V_18 ;
if ( abs ( V_19 - V_23 ) > V_23 / 10 ) {
F_15 ( L_3 , V_19 ) ;
F_15 ( L_4 ,
V_23 ) ;
return V_23 ;
} else {
F_8 ( L_2 , V_19 ) ;
return V_19 ;
}
}
} else {
F_15 ( L_5 ) ;
return 0 ;
}
}
static int F_16 ( void )
{
if ( F_17 ( V_24 ) != 0 ) {
F_18 ( L_6 ) ;
F_18 ( L_7 ) ;
if ( F_19 ( V_24 ) < 0 ) {
F_15 ( L_8 ) ;
return 0 ;
}
}
F_5 ( V_5 , V_25 | V_26 ) ;
V_27 = 1 ;
return 1 ;
}
static void F_20 ( int signal )
{
unsigned int V_28 ;
V_28 = ( V_29 + 1 ) & ( V_30 - 1 ) ;
if ( V_28 == V_31 ) {
V_32 ++ ;
F_15 ( L_9 ) ;
return;
}
V_33 [ V_29 ] = signal ;
V_29 = V_28 ;
}
static void F_21 ( void * V_34 )
{
struct V_13 V_14 ;
static struct V_13 V_35 ;
static int V_36 ;
long signal ;
int V_37 ;
unsigned int V_16 , V_17 ;
unsigned int V_38 ;
if ( ! V_39 )
return;
if ( ! V_27 )
return;
#if 0
disable_irq(irq);
out(LIRC_PORT_IRQ, in(LIRC_PORT_IRQ) & (~LP_PINTEN));
#endif
if ( V_40 && ( F_1 ( 1 ) & V_41 ) )
return;
#ifdef F_22
if ( V_36 ) {
F_14 ( & V_14 ) ;
signal = V_14 . V_21 - V_35 . V_21 ;
if ( signal > 15 )
V_37 = V_42 ;
else
V_37 = ( int ) ( signal * 1000000 +
V_14 . V_22 - V_35 . V_22 +
V_43 ) ;
F_20 ( V_37 ) ;
} else {
if ( V_44 == 0 ) {
V_44 = F_13 () ;
return;
}
V_36 = 1 ;
}
V_38 = V_44 / 10 ;
signal = 1 ;
V_16 = F_9 () ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
signal ++ ;
V_16 = V_17 ;
if ( signal > V_38
|| ( V_40 && ( F_1 ( 1 ) & V_41 ) ) ) {
signal = 0 ;
F_15 ( L_10 ) ;
break;
}
} while ( F_10 () );
if ( signal != 0 ) {
T_1 V_45 ;
V_45 = ( ( T_1 ) signal ) * 1000000 ;
F_23 ( V_45 , V_44 ) ;
signal = ( long ) V_45 ;
if ( signal > V_43 )
V_37 = signal - V_43 ;
else
V_37 = 1 ;
F_20 ( V_46 | V_37 ) ;
}
F_14 ( & V_35 ) ;
#else
#endif
F_24 ( & V_47 ) ;
}
static T_2 F_25 ( struct V_48 * V_49 , T_2 V_1 , int V_50 )
{
return - V_51 ;
}
static T_3 F_26 ( struct V_48 * V_49 , char T_4 * V_52 , T_5 V_53 ,
T_2 * V_54 )
{
int V_55 = 0 ;
int V_20 = 0 ;
F_27 ( V_56 , V_57 ) ;
if ( V_53 % sizeof( int ) )
return - V_58 ;
F_28 ( & V_47 , & V_56 ) ;
F_29 ( V_59 ) ;
while ( V_20 < V_53 ) {
if ( V_31 != V_29 ) {
if ( F_30 ( V_52 + V_20 , ( char * ) & V_33 [ V_31 ] ,
sizeof( int ) ) ) {
V_55 = - V_60 ;
break;
}
V_31 = ( V_31 + 1 ) & ( V_30 - 1 ) ;
V_20 += sizeof( int ) ;
} else {
if ( V_49 -> V_61 & V_62 ) {
V_55 = - V_63 ;
break;
}
if ( F_31 ( V_57 ) ) {
V_55 = - V_64 ;
break;
}
F_32 () ;
F_29 ( V_59 ) ;
}
}
F_33 ( & V_47 , & V_56 ) ;
F_29 ( V_65 ) ;
return V_20 ? V_20 : V_55 ;
}
static T_3 F_34 ( struct V_48 * V_49 , const char T_4 * V_52 , T_5 V_53 ,
T_2 * V_54 )
{
int V_20 ;
unsigned int V_66 ;
unsigned int V_16 , V_17 ;
unsigned long V_67 ;
int V_68 ;
int * V_69 ;
T_3 V_70 ;
if ( ! V_27 )
return - V_71 ;
V_20 = V_53 / sizeof( int ) ;
if ( V_53 % sizeof( int ) || V_20 % 2 == 0 )
return - V_58 ;
V_69 = F_35 ( V_52 , V_53 ) ;
if ( F_36 ( V_69 ) )
return F_37 ( V_69 ) ;
#ifdef F_22
if ( V_44 == 0 ) {
V_44 = F_13 () ;
if ( V_44 == 0 ) {
V_70 = - V_72 ;
goto F_5;
}
}
for ( V_66 = 0 ; V_66 < V_20 ; V_66 ++ ) {
T_1 V_45 ;
V_45 = ( ( T_1 ) V_69 [ V_66 ] ) * V_44 ;
F_23 ( V_45 , 1000000 ) ;
V_69 [ V_66 ] = ( int ) V_45 ;
}
F_38 ( V_67 ) ;
V_66 = 0 ;
while ( V_66 < V_20 ) {
V_16 = F_9 () ;
V_68 = 0 ;
F_11 () ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
V_68 ++ ;
V_16 = V_17 ;
if ( V_40 && ( F_1 ( 1 ) & V_41 ) ) {
F_12 () ;
F_39 ( V_67 ) ;
V_70 = - V_72 ;
goto F_5;
}
} while ( V_68 < V_69 [ V_66 ] );
V_66 ++ ;
F_12 () ;
if ( V_66 == V_20 )
break;
V_68 = 0 ;
do {
V_17 = F_9 () ;
if ( V_16 == 0 && V_17 != 0 )
V_68 ++ ;
V_16 = V_17 ;
if ( V_40 && ( F_1 ( 1 ) & V_41 ) ) {
F_39 ( V_67 ) ;
V_70 = - V_72 ;
goto F_5;
}
} while ( V_68 < V_69 [ V_66 ] );
V_66 ++ ;
}
F_39 ( V_67 ) ;
#else
#endif
V_70 = V_53 ;
F_5:
F_40 ( V_69 ) ;
return V_70 ;
}
static unsigned int F_41 ( struct V_48 * V_48 , T_6 * V_56 )
{
F_42 ( V_48 , & V_47 , V_56 ) ;
if ( V_31 != V_29 )
return V_73 | V_74 ;
return 0 ;
}
static long F_43 ( struct V_48 * V_49 , unsigned int V_75 , unsigned long V_76 )
{
int V_55 ;
T_7 T_4 * V_77 = ( T_7 T_4 * ) V_76 ;
T_7 V_78 = V_79 |
V_80 | V_81 ;
T_7 V_82 ;
T_7 V_6 ;
switch ( V_75 ) {
case V_83 :
V_55 = F_44 ( V_78 , V_77 ) ;
if ( V_55 )
return V_55 ;
break;
case V_84 :
V_55 = F_44 ( V_85 , V_77 ) ;
if ( V_55 )
return V_55 ;
break;
case V_86 :
V_55 = F_44 ( V_87 , V_77 ) ;
if ( V_55 )
return V_55 ;
break;
case V_88 :
V_55 = F_45 ( V_82 , V_77 ) ;
if ( V_55 )
return V_55 ;
if ( V_82 != V_85 )
return - V_58 ;
break;
case V_89 :
V_55 = F_45 ( V_82 , V_77 ) ;
if ( V_55 )
return V_55 ;
if ( V_82 != V_87 )
return - V_90 ;
break;
case V_91 :
V_55 = F_45 ( V_6 , V_77 ) ;
if ( V_55 )
return V_55 ;
if ( ( V_6 & V_92 ) != V_6 )
return V_93 ;
V_12 = V_6 ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static int F_46 ( struct V_95 * V_96 , struct V_48 * V_49 )
{
if ( V_39 || ! F_16 () )
return - V_71 ;
F_47 ( V_3 ) ;
V_31 = 0 ;
V_29 = 0 ;
V_32 = 0 ;
V_39 = 1 ;
return 0 ;
}
static int F_48 ( struct V_95 * V_96 , struct V_48 * V_49 )
{
if ( V_27 ) {
V_27 = 0 ;
F_49 ( V_24 ) ;
}
V_39 = 0 ;
return 0 ;
}
static int F_50 ( void * V_37 )
{
return 0 ;
}
static void F_51 ( void * V_37 )
{
}
static int F_52 ( struct V_97 * V_98 )
{
return 0 ;
}
static int F_53 ( struct V_97 * V_98 )
{
return 0 ;
}
static int F_54 ( struct V_97 * V_98 ,
T_8 V_99 )
{
return 0 ;
}
static int F_55 ( struct V_97 * V_98 )
{
return 0 ;
}
static int F_56 ( void * V_100 )
{
F_57 ( V_3 ) ;
V_27 = 0 ;
return 0 ;
}
static void F_58 ( void * V_100 )
{
if ( ! V_39 )
return;
if ( ! F_16 () )
return;
F_47 ( V_3 ) ;
F_12 () ;
}
static int T_9 F_59 ( void )
{
int V_55 ;
V_55 = F_60 ( & V_101 ) ;
if ( V_55 ) {
F_15 ( L_11 , V_55 ) ;
return V_55 ;
}
V_102 = F_61 ( V_103 , 0 ) ;
if ( ! V_102 ) {
V_55 = - V_104 ;
goto V_105;
}
V_55 = F_62 ( V_102 ) ;
if ( V_55 )
goto V_106;
V_3 = F_63 ( V_107 ) ;
if ( V_3 == NULL ) {
F_15 ( L_12 , V_107 ) ;
V_55 = - V_108 ;
goto V_106;
}
V_24 = F_64 ( V_3 , V_103 ,
F_56 , F_58 , F_21 , 0 , NULL ) ;
F_65 ( V_3 ) ;
if ( V_24 == NULL ) {
F_15 ( L_13 ) ;
V_55 = - V_108 ;
goto V_106;
}
if ( F_17 ( V_24 ) != 0 )
goto V_109;
V_27 = 1 ;
F_5 ( V_5 , V_25 | V_26 ) ;
#ifdef F_22
if ( V_110 )
F_5 ( V_11 , V_12 ) ;
V_44 = F_13 () ;
#if 0
if (timer == 0) {
is_claimed = 0;
parport_release(pport);
parport_unregister_device(ppdevice);
result = -EIO;
goto exit_device_put;
}
#endif
if ( V_110 )
F_5 ( V_11 , 0 ) ;
#endif
V_27 = 0 ;
F_49 ( V_24 ) ;
V_109:
V_111 . V_98 = & V_102 -> V_98 ;
V_111 . V_112 = F_66 ( & V_111 ) ;
if ( V_111 . V_112 < 0 ) {
F_15 ( L_14 ) ;
F_67 ( V_24 ) ;
V_55 = - V_72 ;
goto V_106;
}
F_8 ( L_15 , V_107 , V_113 ) ;
return 0 ;
V_106:
F_68 ( V_102 ) ;
V_105:
F_69 ( & V_101 ) ;
return V_55 ;
}
static void T_10 F_70 ( void )
{
F_67 ( V_24 ) ;
F_71 ( V_111 . V_112 ) ;
F_72 ( V_102 ) ;
F_69 ( & V_101 ) ;
}
