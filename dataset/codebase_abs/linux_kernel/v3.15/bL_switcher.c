static int F_1 ( void )
{
unsigned int V_1 ;
asm volatile ("mrc p15, 0, %0, c0, c0, 5" : "=r" (id));
return V_1 & V_2 ;
}
static T_1 F_2 ( void )
{
struct V_3 V_4 ;
F_3 ( & V_4 ) ;
return F_4 ( & V_4 ) ;
}
static void F_5 ( void * V_5 )
{
unsigned V_6 , V_7 , V_8 ;
long volatile V_9 , * * V_10 = V_5 ;
F_6 ( L_1 , V_11 ) ;
V_6 = F_7 ( F_8 () ) ;
V_7 = F_9 ( V_6 , 0 ) ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( V_10 ) {
V_9 = 0 ;
* V_10 = & V_9 ;
} else
V_9 = - 1 ;
F_10 ( V_7 , V_8 , V_12 ) ;
F_11 () ;
while ( ! V_9 ) {
F_12 () ;
F_13 () ;
}
F_14 () ;
F_15 () ;
}
static int F_16 ( unsigned long V_5 )
{
unsigned int V_13 = F_1 () ;
unsigned int V_14 = F_9 ( V_13 , 1 ) ;
void * V_15 = F_17 () + 1 ;
V_15 = F_18 ( V_15 , V_16 ) ;
V_15 += V_14 * V_17 + V_17 ;
F_19 ( F_5 , ( void * ) V_5 , V_15 ) ;
F_15 () ;
}
static int F_20 ( unsigned int V_18 )
{
unsigned int V_13 , V_19 , V_20 ;
unsigned int V_21 , V_22 , V_23 , V_6 , V_7 , V_8 ;
struct V_24 V_25 ;
struct V_26 * V_27 ;
enum V_28 V_29 ;
long volatile * V_10 ;
int V_30 , V_31 ;
V_19 = F_8 () ;
V_21 = F_1 () ;
V_22 = F_9 ( V_21 , 0 ) ;
V_23 = F_9 ( V_21 , 1 ) ;
F_21 ( F_7 ( V_19 ) != V_21 ) ;
if ( V_18 == V_23 )
return 0 ;
V_20 = V_32 [ V_19 ] ;
V_6 = F_7 ( V_20 ) ;
V_7 = F_9 ( V_6 , 0 ) ;
V_8 = F_9 ( V_6 , 1 ) ;
F_6 ( L_2 ,
V_19 , V_21 , V_6 ) ;
V_19 = F_8 () ;
F_10 ( V_22 , V_23 , NULL ) ;
F_10 ( V_7 , V_8 , NULL ) ;
F_22 ( & V_25 ) ;
V_30 = F_23 ( & V_25 , V_19 ) ;
V_30 |= ( ( 1 << 16 ) << V_33 [ V_22 ] [ V_23 ] ) ;
F_24 ( V_7 , V_8 , F_25 () , V_30 ) ;
V_31 = F_26 ( V_7 , V_8 ) ;
if ( V_31 ) {
F_27 ( L_3 , V_11 , V_31 ) ;
return V_31 ;
}
F_28 ( V_33 [ V_7 ] [ V_8 ] , 0 ) ;
F_29 ( & V_25 ) ;
F_24 ( V_7 , V_8 , 0 , 0 ) ;
F_30 () ;
F_31 () ;
F_32 ( F_2 () , V_21 ) ;
F_33 ( V_33 [ V_7 ] [ V_8 ] ) ;
V_27 = F_34 ( V_19 ) ;
if ( V_27 && ! F_35 ( V_27 -> V_34 -> V_35 , F_36 ( V_19 ) ) )
V_27 = NULL ;
if ( V_27 ) {
V_29 = V_27 -> V_34 -> V_36 ;
F_37 ( V_27 -> V_34 , V_37 ) ;
}
V_31 = F_38 () ;
if ( V_31 )
F_39 ( L_4 , V_11 , V_31 ) ;
F_7 ( V_19 ) = V_6 ;
F_7 ( V_20 ) = V_21 ;
V_31 = F_40 ( ( unsigned long ) & V_10 , F_16 ) ;
if ( V_31 > 0 )
F_39 ( L_5 , V_11 , V_31 ) ;
V_13 = F_1 () ;
F_6 ( L_6 , V_19 , V_13 ) ;
F_21 ( V_13 != V_6 ) ;
F_41 () ;
V_31 = F_42 () ;
if ( V_27 ) {
F_37 ( V_27 -> V_34 , V_29 ) ;
F_43 ( V_27 -> V_34 ,
V_27 -> V_34 -> V_38 , 1 ) ;
}
F_44 ( F_2 () , V_6 ) ;
F_45 () ;
F_46 () ;
* V_10 = 1 ;
F_47 () ;
if ( V_31 )
F_27 ( L_7 , V_11 , V_31 ) ;
return V_31 ;
}
static int F_48 ( void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_42 V_43 = { . V_44 = 1 } ;
int V_45 ;
T_2 V_46 ;
void * V_47 ;
F_49 ( V_48 , V_49 , & V_43 ) ;
F_50 ( & V_41 -> V_50 ) ;
do {
if ( F_51 ( V_48 ) )
F_52 ( V_48 ) ;
F_53 ( V_41 -> V_51 ,
V_41 -> V_52 != - 1 ||
F_54 () ) ;
F_55 ( & V_41 -> V_53 ) ;
V_45 = V_41 -> V_52 ;
V_46 = V_41 -> V_46 ;
V_47 = V_41 -> V_47 ;
V_41 -> V_52 = - 1 ;
V_41 -> V_46 = NULL ;
F_56 ( & V_41 -> V_53 ) ;
if ( V_45 != - 1 ) {
F_20 ( V_45 ) ;
if ( V_46 )
V_46 ( V_47 ) ;
}
} while ( ! F_54 () );
return 0 ;
}
static struct V_54 * F_57 ( int V_55 , void * V_39 )
{
struct V_54 * V_56 ;
V_56 = F_58 ( F_48 , V_39 ,
F_59 ( V_55 ) , L_8 , V_55 ) ;
if ( ! F_60 ( V_56 ) ) {
F_61 ( V_56 , V_55 ) ;
F_62 ( V_56 ) ;
} else
F_27 ( L_9 , V_11 , V_55 ) ;
return V_56 ;
}
int F_63 ( unsigned int V_55 , unsigned int V_18 ,
T_2 V_46 ,
void * V_47 )
{
struct V_40 * V_41 ;
if ( V_55 >= F_64 ( V_57 ) ) {
F_27 ( L_10 , V_11 , V_55 ) ;
return - V_58 ;
}
V_41 = & V_57 [ V_55 ] ;
if ( F_60 ( V_41 -> V_56 ) )
return F_65 ( V_41 -> V_56 ) ;
if ( ! V_41 -> V_56 )
return - V_59 ;
F_55 ( & V_41 -> V_53 ) ;
if ( V_41 -> V_46 ) {
F_56 ( & V_41 -> V_53 ) ;
return - V_60 ;
}
V_41 -> V_46 = V_46 ;
V_41 -> V_47 = V_47 ;
V_41 -> V_52 = V_18 ;
F_56 ( & V_41 -> V_53 ) ;
F_66 ( & V_41 -> V_51 ) ;
return 0 ;
}
int F_67 ( struct V_61 * V_62 )
{
return F_68 ( & V_63 , V_62 ) ;
}
int F_69 ( struct V_61 * V_62 )
{
return F_70 ( & V_63 , V_62 ) ;
}
static int F_71 ( unsigned long V_64 )
{
int V_31 ;
V_31 = F_72 ( & V_63 , V_64 , NULL ) ;
if ( V_31 & V_65 )
F_27 ( L_11 ,
V_11 , V_31 ) ;
return F_73 ( V_31 ) ;
}
static void F_74 ( void )
{
int V_66 ;
F_75 (i, &bL_switcher_removed_logical_cpus) {
struct V_67 * V_68 = F_76 ( V_66 ) ;
int V_31 = F_77 ( V_68 ) ;
if ( V_31 )
F_78 ( V_68 , L_12 ) ;
}
}
static int F_79 ( void )
{
int V_66 , V_69 , V_70 , V_71 , V_31 ;
unsigned int V_55 , V_45 , V_72 ;
T_3 V_73 ;
V_72 = 0 ;
F_80 (i) {
V_55 = F_9 ( F_7 ( V_66 ) , 0 ) ;
V_45 = F_9 ( F_7 ( V_66 ) , 1 ) ;
if ( V_45 >= 2 ) {
F_27 ( L_13 , V_11 ) ;
return - V_58 ;
}
if ( F_81 ( V_55 >= V_74 ) )
return - V_58 ;
V_72 |= ( 1 << V_45 ) ;
}
if ( V_72 != 3 ) {
F_27 ( L_14 , V_11 ) ;
return - V_58 ;
}
memset ( V_32 , - 1 , sizeof( V_32 ) ) ;
F_82 ( & V_73 , V_75 ) ;
V_70 = - 1 ;
F_75 (i, &available_cpus) {
int V_76 = - 1 ;
V_45 = F_9 ( F_7 ( V_66 ) , 1 ) ;
if ( V_70 == - 1 )
V_70 = V_45 ;
if ( V_45 != V_70 )
continue;
F_83 ( V_66 , & V_73 ) ;
F_75 (j, &available_cpus) {
V_45 = F_9 ( F_7 ( V_69 ) , 1 ) ;
if ( V_45 != V_70 )
V_76 = V_69 ;
}
if ( V_76 != - 1 ) {
V_32 [ V_66 ] = V_76 ;
F_83 ( V_76 , & V_73 ) ;
F_84 ( L_15 , V_66 , V_76 ) ;
}
}
F_85 ( & V_77 ) ;
F_80 (i) {
V_55 = F_9 ( F_7 ( V_66 ) , 0 ) ;
V_45 = F_9 ( F_7 ( V_66 ) , 1 ) ;
V_71 = F_86 ( V_66 ) ;
if ( V_71 < 0 ) {
F_27 ( L_16 , V_11 , V_66 ) ;
F_74 () ;
return - V_58 ;
}
V_33 [ V_55 ] [ V_45 ] = V_71 ;
F_84 ( L_17 ,
V_55 , V_45 , V_71 ) ;
if ( V_32 [ V_66 ] != - 1 ) {
V_78 [ V_66 ] = V_45 ;
continue;
}
V_31 = F_87 ( F_76 ( V_66 ) ) ;
if ( V_31 ) {
F_74 () ;
return V_31 ;
}
F_88 ( V_66 , & V_77 ) ;
}
return 0 ;
}
int F_89 ( T_4 V_13 )
{
int V_55 ;
if ( ! V_79 )
return - V_80 ;
V_13 &= V_2 ;
F_80 (cpu) {
int V_81 = V_32 [ V_55 ] ;
if ( V_81 == - 1 )
continue;
if ( ( V_13 == F_7 ( V_55 ) ) ||
( V_13 == F_7 ( V_81 ) ) )
return V_55 ;
}
return - V_58 ;
}
static void F_90 ( void * T_5 V_82 )
{
F_91 ( F_2 () , F_1 () ) ;
}
int F_92 ( void )
{
int V_31 ;
F_93 () ;
F_90 ( NULL ) ;
V_31 = F_94 ( F_90 , NULL , true ) ;
F_95 () ;
return V_31 ;
}
static int F_96 ( void )
{
int V_55 , V_31 ;
F_97 ( & V_83 ) ;
F_98 () ;
if ( V_79 ) {
F_99 () ;
F_100 ( & V_83 ) ;
return 0 ;
}
F_84 ( L_18 ) ;
V_31 = F_71 ( V_84 ) ;
if ( V_31 )
goto error;
V_31 = F_79 () ;
if ( V_31 )
goto error;
F_92 () ;
F_80 (cpu) {
struct V_40 * V_41 = & V_57 [ V_55 ] ;
F_101 ( & V_41 -> V_53 ) ;
F_102 ( & V_41 -> V_51 ) ;
F_22 ( & V_41 -> V_50 ) ;
V_41 -> V_52 = - 1 ;
V_41 -> V_56 = F_57 ( V_55 , V_41 ) ;
}
V_79 = 1 ;
F_71 ( V_85 ) ;
F_84 ( L_19 ) ;
goto V_86;
error:
F_103 ( L_20 ) ;
F_71 ( V_87 ) ;
V_86:
F_99 () ;
F_100 ( & V_83 ) ;
return V_31 ;
}
static void F_104 ( void )
{
unsigned int V_55 , V_45 ;
struct V_40 * V_41 ;
struct V_54 * V_56 ;
F_97 ( & V_83 ) ;
F_98 () ;
if ( ! V_79 )
goto V_86;
if ( F_71 ( V_88 ) != 0 ) {
F_71 ( V_85 ) ;
goto V_86;
}
V_79 = 0 ;
F_80 (cpu) {
V_41 = & V_57 [ V_55 ] ;
V_56 = V_41 -> V_56 ;
V_41 -> V_56 = NULL ;
if ( ! V_56 || F_60 ( V_56 ) )
continue;
F_105 ( V_56 ) ;
V_45 = F_9 ( F_7 ( V_55 ) , 1 ) ;
if ( V_45 == V_78 [ V_55 ] )
continue;
F_22 ( & V_41 -> V_50 ) ;
V_41 -> V_52 = V_78 [ V_55 ] ;
V_56 = F_57 ( V_55 , V_41 ) ;
if ( ! F_60 ( V_56 ) ) {
F_29 ( & V_41 -> V_50 ) ;
F_105 ( V_56 ) ;
V_45 = F_9 ( F_7 ( V_55 ) , 1 ) ;
if ( V_45 == V_78 [ V_55 ] )
continue;
}
F_106 ( L_21 ,
V_11 , V_55 ) ;
F_106 ( L_22 ,
V_11 , V_32 [ V_55 ] ) ;
F_83 ( V_32 [ V_55 ] ,
& V_77 ) ;
}
F_74 () ;
F_92 () ;
F_71 ( V_87 ) ;
V_86:
F_99 () ;
F_100 ( & V_83 ) ;
}
static T_6 F_107 ( struct V_89 * V_90 ,
struct V_91 * V_92 , char * V_93 )
{
return sprintf ( V_93 , L_23 , V_79 ) ;
}
static T_6 F_108 ( struct V_89 * V_90 ,
struct V_91 * V_92 , const char * V_93 , T_7 V_94 )
{
int V_31 ;
switch ( V_93 [ 0 ] ) {
case '0' :
F_104 () ;
V_31 = 0 ;
break;
case '1' :
V_31 = F_96 () ;
break;
default:
V_31 = - V_58 ;
}
return ( V_31 >= 0 ) ? V_94 : V_31 ;
}
static T_6 F_109 ( struct V_89 * V_90 ,
struct V_91 * V_92 , const char * V_93 , T_7 V_94 )
{
int V_31 = F_92 () ;
return V_31 ? V_31 : V_94 ;
}
static int T_8 F_110 ( void )
{
int V_31 ;
V_95 = F_111 ( L_24 , V_96 ) ;
if ( ! V_95 )
return - V_97 ;
V_31 = F_112 ( V_95 , & V_98 ) ;
if ( V_31 )
F_113 ( V_95 ) ;
return V_31 ;
}
bool F_114 ( void )
{
F_97 ( & V_83 ) ;
return V_79 ;
}
void F_115 ( void )
{
F_100 ( & V_83 ) ;
}
static int F_116 ( struct V_61 * V_99 ,
unsigned long V_100 , void * V_101 )
{
if ( V_79 ) {
int V_81 = V_32 [ ( unsigned long ) V_101 ] ;
switch ( V_100 & 0xf ) {
case V_102 :
case V_103 :
if ( V_81 == - 1 )
return V_104 ;
}
}
return V_105 ;
}
static int T_8 F_117 ( void )
{
int V_31 ;
if ( ! F_118 () )
return - V_106 ;
F_119 ( F_116 , 0 ) ;
if ( ! V_107 ) {
V_31 = F_96 () ;
if ( V_31 )
return V_31 ;
}
#ifdef F_120
V_31 = F_110 () ;
if ( V_31 )
F_27 ( L_25 , V_11 ) ;
#endif
return 0 ;
}
