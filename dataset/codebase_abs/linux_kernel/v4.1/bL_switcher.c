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
long volatile * V_8 ;
int V_24 , V_25 ;
V_17 = F_5 () ;
V_19 = F_1 () ;
V_20 = F_6 ( V_19 , 0 ) ;
V_21 = F_6 ( V_19 , 1 ) ;
F_18 ( F_4 ( V_17 ) != V_19 ) ;
if ( V_16 == V_21 )
return 0 ;
V_18 = V_26 [ V_17 ] ;
V_4 = F_4 ( V_18 ) ;
V_5 = F_6 ( V_4 , 0 ) ;
V_6 = F_6 ( V_4 , 1 ) ;
F_3 ( L_2 ,
V_17 , V_19 , V_4 ) ;
V_17 = F_5 () ;
F_7 ( V_20 , V_21 , NULL ) ;
F_7 ( V_5 , V_6 , NULL ) ;
F_19 ( & V_23 ) ;
V_24 = F_20 ( & V_23 , V_17 ) ;
V_24 |= ( ( 1 << 16 ) << V_27 [ V_20 ] [ V_21 ] ) ;
F_21 ( V_5 , V_6 , F_22 () , V_24 ) ;
V_25 = F_23 ( V_5 , V_6 ) ;
if ( V_25 ) {
F_24 ( L_3 , V_9 , V_25 ) ;
return V_25 ;
}
F_25 ( V_27 [ V_5 ] [ V_6 ] , 0 ) ;
F_26 ( & V_23 ) ;
F_21 ( V_5 , V_6 , 0 , 0 ) ;
F_27 () ;
F_28 () ;
F_29 ( F_30 () , V_19 ) ;
F_31 ( V_27 [ V_5 ] [ V_6 ] ) ;
F_32 () ;
V_25 = F_33 () ;
if ( V_25 )
F_34 ( L_4 , V_9 , V_25 ) ;
F_4 ( V_17 ) = V_4 ;
F_4 ( V_18 ) = V_19 ;
V_25 = F_35 ( ( unsigned long ) & V_8 , F_13 ) ;
if ( V_25 > 0 )
F_34 ( L_5 , V_9 , V_25 ) ;
V_11 = F_1 () ;
F_3 ( L_6 , V_17 , V_11 ) ;
F_18 ( V_11 != V_4 ) ;
F_36 () ;
V_25 = F_37 () ;
F_38 () ;
F_39 ( F_30 () , V_4 ) ;
F_40 () ;
F_41 () ;
* V_8 = 1 ;
F_42 () ;
if ( V_25 )
F_24 ( L_7 , V_9 , V_25 ) ;
return V_25 ;
}
static int F_43 ( void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_31 V_32 = { . V_33 = 1 } ;
int V_34 ;
T_1 V_35 ;
void * V_36 ;
F_44 ( V_37 , V_38 , & V_32 ) ;
F_45 ( & V_30 -> V_39 ) ;
do {
if ( F_46 ( V_37 ) )
F_47 ( V_37 ) ;
F_48 ( V_30 -> V_40 ,
V_30 -> V_41 != - 1 ||
F_49 () ) ;
F_50 ( & V_30 -> V_42 ) ;
V_34 = V_30 -> V_41 ;
V_35 = V_30 -> V_35 ;
V_36 = V_30 -> V_36 ;
V_30 -> V_41 = - 1 ;
V_30 -> V_35 = NULL ;
F_51 ( & V_30 -> V_42 ) ;
if ( V_34 != - 1 ) {
F_17 ( V_34 ) ;
if ( V_35 )
V_35 ( V_36 ) ;
}
} while ( ! F_49 () );
return 0 ;
}
static struct V_43 * F_52 ( int V_44 , void * V_28 )
{
struct V_43 * V_45 ;
V_45 = F_53 ( F_43 , V_28 ,
F_54 ( V_44 ) , L_8 , V_44 ) ;
if ( ! F_55 ( V_45 ) ) {
F_56 ( V_45 , V_44 ) ;
F_57 ( V_45 ) ;
} else
F_24 ( L_9 , V_9 , V_44 ) ;
return V_45 ;
}
int F_58 ( unsigned int V_44 , unsigned int V_16 ,
T_1 V_35 ,
void * V_36 )
{
struct V_29 * V_30 ;
if ( V_44 >= F_59 ( V_46 ) ) {
F_24 ( L_10 , V_9 , V_44 ) ;
return - V_47 ;
}
V_30 = & V_46 [ V_44 ] ;
if ( F_55 ( V_30 -> V_45 ) )
return F_60 ( V_30 -> V_45 ) ;
if ( ! V_30 -> V_45 )
return - V_48 ;
F_50 ( & V_30 -> V_42 ) ;
if ( V_30 -> V_35 ) {
F_51 ( & V_30 -> V_42 ) ;
return - V_49 ;
}
V_30 -> V_35 = V_35 ;
V_30 -> V_36 = V_36 ;
V_30 -> V_41 = V_16 ;
F_51 ( & V_30 -> V_42 ) ;
F_61 ( & V_30 -> V_40 ) ;
return 0 ;
}
int F_62 ( struct V_50 * V_51 )
{
return F_63 ( & V_52 , V_51 ) ;
}
int F_64 ( struct V_50 * V_51 )
{
return F_65 ( & V_52 , V_51 ) ;
}
static int F_66 ( unsigned long V_53 )
{
int V_25 ;
V_25 = F_67 ( & V_52 , V_53 , NULL ) ;
if ( V_25 & V_54 )
F_24 ( L_11 ,
V_9 , V_25 ) ;
return F_68 ( V_25 ) ;
}
static void F_69 ( void )
{
int V_55 ;
F_70 (i, &bL_switcher_removed_logical_cpus) {
struct V_56 * V_57 = F_71 ( V_55 ) ;
int V_25 = F_72 ( V_57 ) ;
if ( V_25 )
F_73 ( V_57 , L_12 ) ;
}
}
static int F_74 ( void )
{
int V_55 , V_58 , V_59 , V_60 , V_25 ;
unsigned int V_44 , V_34 , V_61 ;
T_2 V_62 ;
V_61 = 0 ;
F_75 (i) {
V_44 = F_6 ( F_4 ( V_55 ) , 0 ) ;
V_34 = F_6 ( F_4 ( V_55 ) , 1 ) ;
if ( V_34 >= 2 ) {
F_24 ( L_13 , V_9 ) ;
return - V_47 ;
}
if ( F_76 ( V_44 >= V_63 ) )
return - V_47 ;
V_61 |= ( 1 << V_34 ) ;
}
if ( V_61 != 3 ) {
F_24 ( L_14 , V_9 ) ;
return - V_47 ;
}
memset ( V_26 , - 1 , sizeof( V_26 ) ) ;
F_77 ( & V_62 , V_64 ) ;
V_59 = - 1 ;
F_70 (i, &available_cpus) {
int V_65 = - 1 ;
V_34 = F_6 ( F_4 ( V_55 ) , 1 ) ;
if ( V_59 == - 1 )
V_59 = V_34 ;
if ( V_34 != V_59 )
continue;
F_78 ( V_55 , & V_62 ) ;
F_70 (j, &available_cpus) {
V_34 = F_6 ( F_4 ( V_58 ) , 1 ) ;
if ( V_34 != V_59 )
V_65 = V_58 ;
}
if ( V_65 != - 1 ) {
V_26 [ V_55 ] = V_65 ;
F_78 ( V_65 , & V_62 ) ;
F_79 ( L_15 , V_55 , V_65 ) ;
}
}
F_80 ( & V_66 ) ;
F_75 (i) {
V_44 = F_6 ( F_4 ( V_55 ) , 0 ) ;
V_34 = F_6 ( F_4 ( V_55 ) , 1 ) ;
V_60 = F_81 ( V_55 ) ;
if ( V_60 < 0 ) {
F_24 ( L_16 , V_9 , V_55 ) ;
F_69 () ;
return - V_47 ;
}
V_27 [ V_44 ] [ V_34 ] = V_60 ;
F_79 ( L_17 ,
V_44 , V_34 , V_60 ) ;
if ( V_26 [ V_55 ] != - 1 ) {
V_67 [ V_55 ] = V_34 ;
continue;
}
V_25 = F_82 ( F_71 ( V_55 ) ) ;
if ( V_25 ) {
F_69 () ;
return V_25 ;
}
F_83 ( V_55 , & V_66 ) ;
}
return 0 ;
}
int F_84 ( T_3 V_11 )
{
int V_44 ;
if ( ! V_68 )
return - V_69 ;
V_11 &= V_2 ;
F_75 (cpu) {
int V_70 = V_26 [ V_44 ] ;
if ( V_70 == - 1 )
continue;
if ( ( V_11 == F_4 ( V_44 ) ) ||
( V_11 == F_4 ( V_70 ) ) )
return V_44 ;
}
return - V_47 ;
}
static void F_85 ( void * T_4 V_71 )
{
F_86 ( F_30 () , F_1 () ) ;
}
int F_87 ( void )
{
int V_25 ;
F_88 () ;
F_85 ( NULL ) ;
V_25 = F_89 ( F_85 , NULL , true ) ;
F_90 () ;
return V_25 ;
}
static int F_91 ( void )
{
int V_44 , V_25 ;
F_92 ( & V_72 ) ;
F_93 () ;
if ( V_68 ) {
F_94 () ;
F_95 ( & V_72 ) ;
return 0 ;
}
F_79 ( L_18 ) ;
V_25 = F_66 ( V_73 ) ;
if ( V_25 )
goto error;
V_25 = F_74 () ;
if ( V_25 )
goto error;
F_87 () ;
F_75 (cpu) {
struct V_29 * V_30 = & V_46 [ V_44 ] ;
F_96 ( & V_30 -> V_42 ) ;
F_97 ( & V_30 -> V_40 ) ;
F_19 ( & V_30 -> V_39 ) ;
V_30 -> V_41 = - 1 ;
V_30 -> V_45 = F_52 ( V_44 , V_30 ) ;
}
V_68 = 1 ;
F_66 ( V_74 ) ;
F_79 ( L_19 ) ;
goto V_75;
error:
F_98 ( L_20 ) ;
F_66 ( V_76 ) ;
V_75:
F_94 () ;
F_95 ( & V_72 ) ;
return V_25 ;
}
static void F_99 ( void )
{
unsigned int V_44 , V_34 ;
struct V_29 * V_30 ;
struct V_43 * V_45 ;
F_92 ( & V_72 ) ;
F_93 () ;
if ( ! V_68 )
goto V_75;
if ( F_66 ( V_77 ) != 0 ) {
F_66 ( V_74 ) ;
goto V_75;
}
V_68 = 0 ;
F_75 (cpu) {
V_30 = & V_46 [ V_44 ] ;
V_45 = V_30 -> V_45 ;
V_30 -> V_45 = NULL ;
if ( ! V_45 || F_55 ( V_45 ) )
continue;
F_100 ( V_45 ) ;
V_34 = F_6 ( F_4 ( V_44 ) , 1 ) ;
if ( V_34 == V_67 [ V_44 ] )
continue;
F_19 ( & V_30 -> V_39 ) ;
V_30 -> V_41 = V_67 [ V_44 ] ;
V_45 = F_52 ( V_44 , V_30 ) ;
if ( ! F_55 ( V_45 ) ) {
F_26 ( & V_30 -> V_39 ) ;
F_100 ( V_45 ) ;
V_34 = F_6 ( F_4 ( V_44 ) , 1 ) ;
if ( V_34 == V_67 [ V_44 ] )
continue;
}
F_101 ( L_21 ,
V_9 , V_44 ) ;
F_101 ( L_22 ,
V_9 , V_26 [ V_44 ] ) ;
F_78 ( V_26 [ V_44 ] ,
& V_66 ) ;
}
F_69 () ;
F_87 () ;
F_66 ( V_76 ) ;
V_75:
F_94 () ;
F_95 ( & V_72 ) ;
}
static T_5 F_102 ( struct V_78 * V_79 ,
struct V_80 * V_81 , char * V_82 )
{
return sprintf ( V_82 , L_23 , V_68 ) ;
}
static T_5 F_103 ( struct V_78 * V_79 ,
struct V_80 * V_81 , const char * V_82 , T_6 V_83 )
{
int V_25 ;
switch ( V_82 [ 0 ] ) {
case '0' :
F_99 () ;
V_25 = 0 ;
break;
case '1' :
V_25 = F_91 () ;
break;
default:
V_25 = - V_47 ;
}
return ( V_25 >= 0 ) ? V_83 : V_25 ;
}
static T_5 F_104 ( struct V_78 * V_79 ,
struct V_80 * V_81 , const char * V_82 , T_6 V_83 )
{
int V_25 = F_87 () ;
return V_25 ? V_25 : V_83 ;
}
static int T_7 F_105 ( void )
{
int V_25 ;
V_84 = F_106 ( L_24 , V_85 ) ;
if ( ! V_84 )
return - V_86 ;
V_25 = F_107 ( V_84 , & V_87 ) ;
if ( V_25 )
F_108 ( V_84 ) ;
return V_25 ;
}
bool F_109 ( void )
{
F_92 ( & V_72 ) ;
return V_68 ;
}
void F_110 ( void )
{
F_95 ( & V_72 ) ;
}
static int F_111 ( struct V_50 * V_88 ,
unsigned long V_89 , void * V_90 )
{
if ( V_68 ) {
int V_70 = V_26 [ ( unsigned long ) V_90 ] ;
switch ( V_89 & 0xf ) {
case V_91 :
case V_92 :
if ( V_70 == - 1 )
return V_93 ;
}
}
return V_94 ;
}
static int T_7 F_112 ( void )
{
int V_25 ;
if ( ! F_113 () )
return - V_95 ;
F_114 ( F_111 , 0 ) ;
if ( ! V_96 ) {
V_25 = F_91 () ;
if ( V_25 )
return V_25 ;
}
#ifdef F_115
V_25 = F_105 () ;
if ( V_25 )
F_24 ( L_25 , V_9 ) ;
#endif
return 0 ;
}
