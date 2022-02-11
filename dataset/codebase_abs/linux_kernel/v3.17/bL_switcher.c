static int F_1 ( void )
{
unsigned int V_1 ;
asm volatile ("mrc p15, 0, %0, c0, c0, 5" : "=r" (id));
return V_1 & V_2 ;
}
static void F_2 ( void * V_3 )
{
unsigned V_4 , V_5 , V_6 ;
long volatile V_7 , * * V_8 = V_3 ;
F_3 ( L_1 , V_9 ) ;
V_4 = F_4 ( F_5 () ) ;
V_5 = F_6 ( V_4 , 0 ) ;
V_6 = F_6 ( V_4 , 1 ) ;
if ( V_8 ) {
V_7 = 0 ;
* V_8 = & V_7 ;
} else
V_7 = - 1 ;
F_7 ( V_5 , V_6 , V_10 ) ;
F_8 () ;
while ( ! V_7 ) {
F_9 () ;
F_10 () ;
}
F_11 () ;
F_12 () ;
}
static int F_13 ( unsigned long V_3 )
{
unsigned int V_11 = F_1 () ;
unsigned int V_12 = F_6 ( V_11 , 1 ) ;
void * V_13 = F_14 () + 1 ;
V_13 = F_15 ( V_13 , V_14 ) ;
V_13 += V_12 * V_15 + V_15 ;
F_16 ( F_2 , ( void * ) V_3 , V_13 ) ;
F_12 () ;
}
static int F_17 ( unsigned int V_16 )
{
unsigned int V_11 , V_17 , V_18 ;
unsigned int V_19 , V_20 , V_21 , V_4 , V_5 , V_6 ;
struct V_22 V_23 ;
struct V_24 * V_25 ;
enum V_26 V_27 ;
long volatile * V_8 ;
int V_28 , V_29 ;
V_17 = F_5 () ;
V_19 = F_1 () ;
V_20 = F_6 ( V_19 , 0 ) ;
V_21 = F_6 ( V_19 , 1 ) ;
F_18 ( F_4 ( V_17 ) != V_19 ) ;
if ( V_16 == V_21 )
return 0 ;
V_18 = V_30 [ V_17 ] ;
V_4 = F_4 ( V_18 ) ;
V_5 = F_6 ( V_4 , 0 ) ;
V_6 = F_6 ( V_4 , 1 ) ;
F_3 ( L_2 ,
V_17 , V_19 , V_4 ) ;
V_17 = F_5 () ;
F_7 ( V_20 , V_21 , NULL ) ;
F_7 ( V_5 , V_6 , NULL ) ;
F_19 ( & V_23 ) ;
V_28 = F_20 ( & V_23 , V_17 ) ;
V_28 |= ( ( 1 << 16 ) << V_31 [ V_20 ] [ V_21 ] ) ;
F_21 ( V_5 , V_6 , F_22 () , V_28 ) ;
V_29 = F_23 ( V_5 , V_6 ) ;
if ( V_29 ) {
F_24 ( L_3 , V_9 , V_29 ) ;
return V_29 ;
}
F_25 ( V_31 [ V_5 ] [ V_6 ] , 0 ) ;
F_26 ( & V_23 ) ;
F_21 ( V_5 , V_6 , 0 , 0 ) ;
F_27 () ;
F_28 () ;
F_29 ( F_30 () , V_19 ) ;
F_31 ( V_31 [ V_5 ] [ V_6 ] ) ;
V_25 = F_32 ( V_17 ) ;
if ( V_25 && ! F_33 ( V_25 -> V_32 -> V_33 , F_34 ( V_17 ) ) )
V_25 = NULL ;
if ( V_25 ) {
V_27 = V_25 -> V_32 -> V_34 ;
F_35 ( V_25 -> V_32 , V_35 ) ;
}
V_29 = F_36 () ;
if ( V_29 )
F_37 ( L_4 , V_9 , V_29 ) ;
F_4 ( V_17 ) = V_4 ;
F_4 ( V_18 ) = V_19 ;
V_29 = F_38 ( ( unsigned long ) & V_8 , F_13 ) ;
if ( V_29 > 0 )
F_37 ( L_5 , V_9 , V_29 ) ;
V_11 = F_1 () ;
F_3 ( L_6 , V_17 , V_11 ) ;
F_18 ( V_11 != V_4 ) ;
F_39 () ;
V_29 = F_40 () ;
if ( V_25 ) {
F_35 ( V_25 -> V_32 , V_27 ) ;
F_41 ( V_25 -> V_32 ,
V_25 -> V_32 -> V_36 , 1 ) ;
}
F_42 ( F_30 () , V_4 ) ;
F_43 () ;
F_44 () ;
* V_8 = 1 ;
F_45 () ;
if ( V_29 )
F_24 ( L_7 , V_9 , V_29 ) ;
return V_29 ;
}
static int F_46 ( void * V_37 )
{
struct V_38 * V_39 = V_37 ;
struct V_40 V_41 = { . V_42 = 1 } ;
int V_43 ;
T_1 V_44 ;
void * V_45 ;
F_47 ( V_46 , V_47 , & V_41 ) ;
F_48 ( & V_39 -> V_48 ) ;
do {
if ( F_49 ( V_46 ) )
F_50 ( V_46 ) ;
F_51 ( V_39 -> V_49 ,
V_39 -> V_50 != - 1 ||
F_52 () ) ;
F_53 ( & V_39 -> V_51 ) ;
V_43 = V_39 -> V_50 ;
V_44 = V_39 -> V_44 ;
V_45 = V_39 -> V_45 ;
V_39 -> V_50 = - 1 ;
V_39 -> V_44 = NULL ;
F_54 ( & V_39 -> V_51 ) ;
if ( V_43 != - 1 ) {
F_17 ( V_43 ) ;
if ( V_44 )
V_44 ( V_45 ) ;
}
} while ( ! F_52 () );
return 0 ;
}
static struct V_52 * F_55 ( int V_53 , void * V_37 )
{
struct V_52 * V_54 ;
V_54 = F_56 ( F_46 , V_37 ,
F_57 ( V_53 ) , L_8 , V_53 ) ;
if ( ! F_58 ( V_54 ) ) {
F_59 ( V_54 , V_53 ) ;
F_60 ( V_54 ) ;
} else
F_24 ( L_9 , V_9 , V_53 ) ;
return V_54 ;
}
int F_61 ( unsigned int V_53 , unsigned int V_16 ,
T_1 V_44 ,
void * V_45 )
{
struct V_38 * V_39 ;
if ( V_53 >= F_62 ( V_55 ) ) {
F_24 ( L_10 , V_9 , V_53 ) ;
return - V_56 ;
}
V_39 = & V_55 [ V_53 ] ;
if ( F_58 ( V_39 -> V_54 ) )
return F_63 ( V_39 -> V_54 ) ;
if ( ! V_39 -> V_54 )
return - V_57 ;
F_53 ( & V_39 -> V_51 ) ;
if ( V_39 -> V_44 ) {
F_54 ( & V_39 -> V_51 ) ;
return - V_58 ;
}
V_39 -> V_44 = V_44 ;
V_39 -> V_45 = V_45 ;
V_39 -> V_50 = V_16 ;
F_54 ( & V_39 -> V_51 ) ;
F_64 ( & V_39 -> V_49 ) ;
return 0 ;
}
int F_65 ( struct V_59 * V_60 )
{
return F_66 ( & V_61 , V_60 ) ;
}
int F_67 ( struct V_59 * V_60 )
{
return F_68 ( & V_61 , V_60 ) ;
}
static int F_69 ( unsigned long V_62 )
{
int V_29 ;
V_29 = F_70 ( & V_61 , V_62 , NULL ) ;
if ( V_29 & V_63 )
F_24 ( L_11 ,
V_9 , V_29 ) ;
return F_71 ( V_29 ) ;
}
static void F_72 ( void )
{
int V_64 ;
F_73 (i, &bL_switcher_removed_logical_cpus) {
struct V_65 * V_66 = F_74 ( V_64 ) ;
int V_29 = F_75 ( V_66 ) ;
if ( V_29 )
F_76 ( V_66 , L_12 ) ;
}
}
static int F_77 ( void )
{
int V_64 , V_67 , V_68 , V_69 , V_29 ;
unsigned int V_53 , V_43 , V_70 ;
T_2 V_71 ;
V_70 = 0 ;
F_78 (i) {
V_53 = F_6 ( F_4 ( V_64 ) , 0 ) ;
V_43 = F_6 ( F_4 ( V_64 ) , 1 ) ;
if ( V_43 >= 2 ) {
F_24 ( L_13 , V_9 ) ;
return - V_56 ;
}
if ( F_79 ( V_53 >= V_72 ) )
return - V_56 ;
V_70 |= ( 1 << V_43 ) ;
}
if ( V_70 != 3 ) {
F_24 ( L_14 , V_9 ) ;
return - V_56 ;
}
memset ( V_30 , - 1 , sizeof( V_30 ) ) ;
F_80 ( & V_71 , V_73 ) ;
V_68 = - 1 ;
F_73 (i, &available_cpus) {
int V_74 = - 1 ;
V_43 = F_6 ( F_4 ( V_64 ) , 1 ) ;
if ( V_68 == - 1 )
V_68 = V_43 ;
if ( V_43 != V_68 )
continue;
F_81 ( V_64 , & V_71 ) ;
F_73 (j, &available_cpus) {
V_43 = F_6 ( F_4 ( V_67 ) , 1 ) ;
if ( V_43 != V_68 )
V_74 = V_67 ;
}
if ( V_74 != - 1 ) {
V_30 [ V_64 ] = V_74 ;
F_81 ( V_74 , & V_71 ) ;
F_82 ( L_15 , V_64 , V_74 ) ;
}
}
F_83 ( & V_75 ) ;
F_78 (i) {
V_53 = F_6 ( F_4 ( V_64 ) , 0 ) ;
V_43 = F_6 ( F_4 ( V_64 ) , 1 ) ;
V_69 = F_84 ( V_64 ) ;
if ( V_69 < 0 ) {
F_24 ( L_16 , V_9 , V_64 ) ;
F_72 () ;
return - V_56 ;
}
V_31 [ V_53 ] [ V_43 ] = V_69 ;
F_82 ( L_17 ,
V_53 , V_43 , V_69 ) ;
if ( V_30 [ V_64 ] != - 1 ) {
V_76 [ V_64 ] = V_43 ;
continue;
}
V_29 = F_85 ( F_74 ( V_64 ) ) ;
if ( V_29 ) {
F_72 () ;
return V_29 ;
}
F_86 ( V_64 , & V_75 ) ;
}
return 0 ;
}
int F_87 ( T_3 V_11 )
{
int V_53 ;
if ( ! V_77 )
return - V_78 ;
V_11 &= V_2 ;
F_78 (cpu) {
int V_79 = V_30 [ V_53 ] ;
if ( V_79 == - 1 )
continue;
if ( ( V_11 == F_4 ( V_53 ) ) ||
( V_11 == F_4 ( V_79 ) ) )
return V_53 ;
}
return - V_56 ;
}
static void F_88 ( void * T_4 V_80 )
{
F_89 ( F_30 () , F_1 () ) ;
}
int F_90 ( void )
{
int V_29 ;
F_91 () ;
F_88 ( NULL ) ;
V_29 = F_92 ( F_88 , NULL , true ) ;
F_93 () ;
return V_29 ;
}
static int F_94 ( void )
{
int V_53 , V_29 ;
F_95 ( & V_81 ) ;
F_96 () ;
if ( V_77 ) {
F_97 () ;
F_98 ( & V_81 ) ;
return 0 ;
}
F_82 ( L_18 ) ;
V_29 = F_69 ( V_82 ) ;
if ( V_29 )
goto error;
V_29 = F_77 () ;
if ( V_29 )
goto error;
F_90 () ;
F_78 (cpu) {
struct V_38 * V_39 = & V_55 [ V_53 ] ;
F_99 ( & V_39 -> V_51 ) ;
F_100 ( & V_39 -> V_49 ) ;
F_19 ( & V_39 -> V_48 ) ;
V_39 -> V_50 = - 1 ;
V_39 -> V_54 = F_55 ( V_53 , V_39 ) ;
}
V_77 = 1 ;
F_69 ( V_83 ) ;
F_82 ( L_19 ) ;
goto V_84;
error:
F_101 ( L_20 ) ;
F_69 ( V_85 ) ;
V_84:
F_97 () ;
F_98 ( & V_81 ) ;
return V_29 ;
}
static void F_102 ( void )
{
unsigned int V_53 , V_43 ;
struct V_38 * V_39 ;
struct V_52 * V_54 ;
F_95 ( & V_81 ) ;
F_96 () ;
if ( ! V_77 )
goto V_84;
if ( F_69 ( V_86 ) != 0 ) {
F_69 ( V_83 ) ;
goto V_84;
}
V_77 = 0 ;
F_78 (cpu) {
V_39 = & V_55 [ V_53 ] ;
V_54 = V_39 -> V_54 ;
V_39 -> V_54 = NULL ;
if ( ! V_54 || F_58 ( V_54 ) )
continue;
F_103 ( V_54 ) ;
V_43 = F_6 ( F_4 ( V_53 ) , 1 ) ;
if ( V_43 == V_76 [ V_53 ] )
continue;
F_19 ( & V_39 -> V_48 ) ;
V_39 -> V_50 = V_76 [ V_53 ] ;
V_54 = F_55 ( V_53 , V_39 ) ;
if ( ! F_58 ( V_54 ) ) {
F_26 ( & V_39 -> V_48 ) ;
F_103 ( V_54 ) ;
V_43 = F_6 ( F_4 ( V_53 ) , 1 ) ;
if ( V_43 == V_76 [ V_53 ] )
continue;
}
F_104 ( L_21 ,
V_9 , V_53 ) ;
F_104 ( L_22 ,
V_9 , V_30 [ V_53 ] ) ;
F_81 ( V_30 [ V_53 ] ,
& V_75 ) ;
}
F_72 () ;
F_90 () ;
F_69 ( V_85 ) ;
V_84:
F_97 () ;
F_98 ( & V_81 ) ;
}
static T_5 F_105 ( struct V_87 * V_88 ,
struct V_89 * V_90 , char * V_91 )
{
return sprintf ( V_91 , L_23 , V_77 ) ;
}
static T_5 F_106 ( struct V_87 * V_88 ,
struct V_89 * V_90 , const char * V_91 , T_6 V_92 )
{
int V_29 ;
switch ( V_91 [ 0 ] ) {
case '0' :
F_102 () ;
V_29 = 0 ;
break;
case '1' :
V_29 = F_94 () ;
break;
default:
V_29 = - V_56 ;
}
return ( V_29 >= 0 ) ? V_92 : V_29 ;
}
static T_5 F_107 ( struct V_87 * V_88 ,
struct V_89 * V_90 , const char * V_91 , T_6 V_92 )
{
int V_29 = F_90 () ;
return V_29 ? V_29 : V_92 ;
}
static int T_7 F_108 ( void )
{
int V_29 ;
V_93 = F_109 ( L_24 , V_94 ) ;
if ( ! V_93 )
return - V_95 ;
V_29 = F_110 ( V_93 , & V_96 ) ;
if ( V_29 )
F_111 ( V_93 ) ;
return V_29 ;
}
bool F_112 ( void )
{
F_95 ( & V_81 ) ;
return V_77 ;
}
void F_113 ( void )
{
F_98 ( & V_81 ) ;
}
static int F_114 ( struct V_59 * V_97 ,
unsigned long V_98 , void * V_99 )
{
if ( V_77 ) {
int V_79 = V_30 [ ( unsigned long ) V_99 ] ;
switch ( V_98 & 0xf ) {
case V_100 :
case V_101 :
if ( V_79 == - 1 )
return V_102 ;
}
}
return V_103 ;
}
static int T_7 F_115 ( void )
{
int V_29 ;
if ( ! F_116 () )
return - V_104 ;
F_117 ( F_114 , 0 ) ;
if ( ! V_105 ) {
V_29 = F_94 () ;
if ( V_29 )
return V_29 ;
}
#ifdef F_118
V_29 = F_108 () ;
if ( V_29 )
F_24 ( L_25 , V_9 ) ;
#endif
return 0 ;
}
