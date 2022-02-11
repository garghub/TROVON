static inline int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 <= V_4 ;
}
static T_1 F_2 ( const struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 ,
T_1 (* F_3)( const struct V_1 * , char * ) )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = (* F_3)( V_9 , V_8 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_7 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 ,
int (* F_8)( struct V_1 * , unsigned long ) )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
unsigned long V_14 ;
int V_10 = - V_11 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
V_10 = F_10 ( V_8 , 0 , & V_14 ) ;
if ( V_10 )
goto V_17;
if ( ! F_11 () )
return F_12 () ;
if ( F_1 ( V_9 ) ) {
if ( ( V_10 = (* F_8)( V_9 , V_14 ) ) == 0 )
V_10 = V_13 ;
}
F_13 () ;
V_17:
return V_10 ;
}
static T_1 F_14 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = F_15 ( V_8 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_16 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
if ( F_1 ( V_9 ) )
return F_15 ( V_8 , V_9 -> V_20 , V_9 -> V_19 ) ;
return - V_11 ;
}
static T_1 F_17 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
if ( F_18 ( V_21 ) ) {
return sprintf ( V_8 , V_22 , ! ! F_19 ( V_21 ) ) ;
}
return - V_11 ;
}
static T_1 F_20 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_18 ( V_21 ) ) {
struct V_23 V_24 ;
if ( ! F_21 ( V_21 , & V_24 ) )
V_10 = sprintf ( V_8 , V_25 , F_22 ( & V_24 ) ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_23 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_18 ( V_21 ) ) {
struct V_23 V_24 ;
if ( ! F_21 ( V_21 , & V_24 ) ) {
const char * V_26 ;
switch ( V_24 . V_26 ) {
case V_27 :
V_26 = L_1 ;
break;
case V_28 :
V_26 = L_2 ;
break;
default:
V_26 = L_3 ;
break;
}
V_10 = sprintf ( V_8 , L_4 , V_26 ) ;
}
}
F_13 () ;
return V_10 ;
}
static T_1 F_24 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
if ( F_18 ( V_21 ) )
return sprintf ( V_8 , V_22 , ! ! F_25 ( V_21 ) ) ;
return - V_11 ;
}
static T_1 F_26 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_21 = F_4 ( V_2 ) ;
unsigned char V_29 ;
F_5 ( & V_12 ) ;
V_29 = V_21 -> V_29 ;
if ( ! F_18 ( V_21 ) )
V_29 = V_30 ;
F_6 ( & V_12 ) ;
if ( V_29 >= F_27 ( V_31 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_31 [ V_29 ] ) ;
}
static int F_28 ( struct V_1 * V_9 , unsigned long V_32 )
{
return F_29 ( V_9 , ( int ) V_32 ) ;
}
static T_1 F_30 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_28 ) ;
}
static int F_31 ( struct V_1 * V_9 , unsigned long V_33 )
{
return F_32 ( V_9 , ( unsigned int ) V_33 ) ;
}
static T_1 F_33 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_31 ) ;
}
static int F_34 ( struct V_1 * V_9 , unsigned long V_34 )
{
V_9 -> V_35 = V_34 ;
return 0 ;
}
static T_1 F_35 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_34 ) ;
}
static T_1 F_36 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
T_2 V_36 = V_13 ;
T_1 V_10 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_36 ;
if ( ! F_11 () )
return F_12 () ;
V_10 = F_37 ( V_21 , V_8 , V_36 ) ;
F_13 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_38 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_21 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_11 () )
return F_12 () ;
if ( V_21 -> V_37 )
V_10 = sprintf ( V_8 , L_4 , V_21 -> V_37 ) ;
F_13 () ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_9 , unsigned long V_38 )
{
F_40 ( V_9 , ( int ) V_38 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_39 ) ;
}
static T_1 F_42 ( const struct V_5 * V_39 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_40 )
{
struct V_1 * V_2 = F_4 ( V_39 ) ;
T_1 V_10 = - V_11 ;
F_43 ( V_40 > sizeof( struct V_41 ) ||
V_40 % sizeof( V_42 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_41 V_43 ;
const struct V_41 * V_44 = F_44 ( V_2 , & V_43 ) ;
V_10 = sprintf ( V_8 , V_45 , * ( V_42 * ) ( ( ( V_46 * ) V_44 ) + V_40 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_45 ( struct V_47 * V_48 , struct V_49 * V_7 ,
char * V_8 )
{
struct V_50 * V_49 = F_46 ( V_7 ) ;
struct V_51 * V_52 = F_47 ( V_48 ) ;
if ( ! V_49 -> V_53 )
return - V_54 ;
return V_49 -> V_53 ( V_52 , V_49 , V_8 ) ;
}
static T_1 F_48 ( struct V_47 * V_48 , struct V_49 * V_7 ,
const char * V_8 , T_2 V_36 )
{
struct V_50 * V_49 = F_46 ( V_7 ) ;
struct V_51 * V_52 = F_47 ( V_48 ) ;
if ( ! V_49 -> V_55 )
return - V_54 ;
return V_49 -> V_55 ( V_52 , V_49 , V_8 , V_36 ) ;
}
static T_1 F_49 ( struct V_51 * V_52 ,
struct V_50 * V_49 , char * V_8 )
{
struct V_56 * V_57 ;
T_3 V_58 ;
T_2 V_13 = 0 ;
int V_59 ;
if ( ! F_50 ( & V_58 , V_60 ) )
return - V_61 ;
F_51 () ;
V_57 = F_52 ( V_52 -> V_56 ) ;
if ( V_57 )
for ( V_59 = 0 ; V_59 < V_57 -> V_13 ; V_59 ++ )
F_53 ( V_57 -> V_62 [ V_59 ] , V_58 ) ;
V_13 += F_54 ( V_8 + V_13 , V_63 , V_58 ) ;
if ( V_63 - V_13 < 3 ) {
F_55 () ;
F_56 ( V_58 ) ;
return - V_11 ;
}
F_55 () ;
F_56 ( V_58 ) ;
V_13 += sprintf ( V_8 + V_13 , L_5 ) ;
return V_13 ;
}
static T_1 F_57 ( struct V_51 * V_52 ,
struct V_50 * V_49 ,
const char * V_8 , T_2 V_13 )
{
struct V_56 * V_64 , * V_57 ;
T_3 V_58 ;
int V_17 , V_65 , V_59 ;
static F_58 ( V_66 ) ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( ! F_59 ( & V_58 , V_60 ) )
return - V_61 ;
V_17 = F_60 ( V_8 , V_13 , F_61 ( V_58 ) , V_67 ) ;
if ( V_17 ) {
F_56 ( V_58 ) ;
return V_17 ;
}
V_57 = F_62 ( F_63 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_60 ) ;
if ( ! V_57 ) {
F_56 ( V_58 ) ;
return - V_61 ;
}
V_59 = 0 ;
F_64 (cpu, mask, cpu_online_mask)
V_57 -> V_62 [ V_59 ++ ] = V_65 ;
if ( V_59 )
V_57 -> V_13 = V_59 ;
else {
F_65 ( V_57 ) ;
V_57 = NULL ;
}
F_66 ( & V_66 ) ;
V_64 = F_67 ( V_52 -> V_56 ,
F_68 ( & V_66 ) ) ;
F_69 ( V_52 -> V_56 , V_57 ) ;
F_70 ( & V_66 ) ;
if ( V_57 )
F_71 ( & V_68 ) ;
if ( V_64 ) {
F_72 ( V_64 , V_69 ) ;
F_73 ( & V_68 ) ;
}
F_56 ( V_58 ) ;
return V_13 ;
}
static T_1 F_74 ( struct V_51 * V_52 ,
struct V_50 * V_7 ,
char * V_8 )
{
struct V_70 * V_71 ;
unsigned long V_72 = 0 ;
F_51 () ;
V_71 = F_52 ( V_52 -> V_73 ) ;
if ( V_71 )
V_72 = ( unsigned long ) V_71 -> V_58 + 1 ;
F_55 () ;
return sprintf ( V_8 , L_6 , V_72 ) ;
}
static void F_75 ( struct V_74 * V_75 )
{
struct V_70 * V_76 = F_76 ( V_75 ,
struct V_70 , V_77 ) ;
F_77 ( V_76 ) ;
}
static void F_78 ( struct V_78 * V_69 )
{
struct V_70 * V_76 = F_76 ( V_69 ,
struct V_70 , V_69 ) ;
F_79 ( & V_76 -> V_77 , F_75 ) ;
F_80 ( & V_76 -> V_77 ) ;
}
static T_1 F_81 ( struct V_51 * V_52 ,
struct V_50 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_58 , V_36 ;
struct V_70 * V_76 , * V_79 ;
static F_58 ( V_80 ) ;
int V_81 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
V_81 = F_10 ( V_8 , 0 , & V_36 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_36 ) {
V_58 = V_36 - 1 ;
while ( ( V_58 | ( V_58 >> 1 ) ) != V_58 )
V_58 |= ( V_58 >> 1 ) ;
#if V_82 > 32
if ( V_58 > ( unsigned long ) ( V_83 ) V_58 )
return - V_11 ;
#else
if ( V_58 > ( V_84 - F_82 ( 1 ) )
/ sizeof( struct V_85 ) ) {
return - V_11 ;
}
#endif
V_76 = F_83 ( F_82 ( V_58 + 1 ) ) ;
if ( ! V_76 )
return - V_61 ;
V_76 -> V_58 = V_58 ;
for ( V_36 = 0 ; V_36 <= V_58 ; V_36 ++ )
V_76 -> V_86 [ V_36 ] . V_65 = V_87 ;
} else
V_76 = NULL ;
F_66 ( & V_80 ) ;
V_79 = F_67 ( V_52 -> V_73 ,
F_68 ( & V_80 ) ) ;
F_69 ( V_52 -> V_73 , V_76 ) ;
F_70 ( & V_80 ) ;
if ( V_79 )
F_84 ( & V_79 -> V_69 , F_78 ) ;
return V_13 ;
}
static void F_85 ( struct V_47 * V_48 )
{
struct V_51 * V_52 = F_47 ( V_48 ) ;
struct V_56 * V_57 ;
struct V_70 * V_71 ;
V_57 = F_67 ( V_52 -> V_56 , 1 ) ;
if ( V_57 ) {
F_86 ( V_52 -> V_56 , NULL ) ;
F_72 ( V_57 , V_69 ) ;
}
V_71 = F_67 ( V_52 -> V_73 , 1 ) ;
if ( V_71 ) {
F_86 ( V_52 -> V_73 , NULL ) ;
F_84 ( & V_71 -> V_69 , F_78 ) ;
}
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_87 ( V_52 -> V_2 ) ;
}
static int F_88 ( struct V_1 * V_9 , int V_88 )
{
struct V_51 * V_52 = V_9 -> V_89 + V_88 ;
struct V_47 * V_48 = & V_52 -> V_48 ;
int error = 0 ;
V_48 -> V_90 = V_9 -> V_91 ;
error = F_89 ( V_48 , & V_92 , NULL ,
L_7 , V_88 ) ;
if ( error ) {
F_90 ( V_48 ) ;
return error ;
}
F_91 ( V_48 , V_93 ) ;
F_92 ( V_52 -> V_2 ) ;
return error ;
}
int
F_93 ( struct V_1 * V_9 , int V_94 , int V_95 )
{
#ifdef F_94
int V_59 ;
int error = 0 ;
for ( V_59 = V_94 ; V_59 < V_95 ; V_59 ++ ) {
error = F_88 ( V_9 , V_59 ) ;
if ( error ) {
V_95 = V_94 ;
break;
}
}
while ( -- V_59 >= V_95 )
F_90 ( & V_9 -> V_89 [ V_59 ] . V_48 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_95 ( struct V_47 * V_48 ,
struct V_49 * V_7 , char * V_8 )
{
struct V_96 * V_49 = F_96 ( V_7 ) ;
struct V_97 * V_52 = F_97 ( V_48 ) ;
if ( ! V_49 -> V_53 )
return - V_54 ;
return V_49 -> V_53 ( V_52 , V_49 , V_8 ) ;
}
static T_1 F_98 ( struct V_47 * V_48 ,
struct V_49 * V_7 ,
const char * V_8 , T_2 V_36 )
{
struct V_96 * V_49 = F_96 ( V_7 ) ;
struct V_97 * V_52 = F_97 ( V_48 ) ;
if ( ! V_49 -> V_55 )
return - V_54 ;
return V_49 -> V_55 ( V_52 , V_49 , V_8 , V_36 ) ;
}
static T_1 F_99 ( struct V_97 * V_52 ,
struct V_96 * V_49 ,
char * V_8 )
{
unsigned long V_98 ;
F_100 ( & V_52 -> V_99 ) ;
V_98 = V_52 -> V_98 ;
F_101 ( & V_52 -> V_99 ) ;
return sprintf ( V_8 , L_8 , V_98 ) ;
}
static T_1 F_102 ( char * V_8 , unsigned int V_100 )
{
return sprintf ( V_8 , L_9 , V_100 ) ;
}
static T_1 F_103 ( const char * V_8 , const T_2 V_36 ,
unsigned int * V_101 )
{
unsigned int V_100 ;
int V_17 ;
if ( ! strcmp ( V_8 , L_10 ) || ! strcmp ( V_8 , L_11 ) )
V_100 = V_102 ;
else {
V_17 = F_104 ( V_8 , 10 , & V_100 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_100 > V_102 )
return - V_11 ;
}
* V_101 = V_100 ;
return V_36 ;
}
static T_1 F_105 ( struct V_97 * V_52 ,
struct V_96 * V_7 ,
char * V_8 )
{
struct V_103 * V_103 = & V_52 -> V_103 ;
return sprintf ( V_8 , L_9 , F_106 ( V_103 -> V_104 ) ) ;
}
static T_1 F_107 ( struct V_97 * V_52 ,
struct V_96 * V_49 ,
const char * V_8 , T_2 V_13 )
{
struct V_103 * V_103 = & V_52 -> V_103 ;
unsigned int V_100 ;
int V_17 ;
V_17 = F_104 ( V_8 , 10 , & V_100 ) ;
if ( V_17 < 0 )
return V_17 ;
V_103 -> V_104 = F_108 ( V_100 ) ;
return V_13 ;
}
static T_1 F_109 ( struct V_97 * V_52 ,
struct V_96 * V_7 ,
char * V_8 )
{
struct V_103 * V_103 = & V_52 -> V_103 ;
return sprintf ( V_8 , L_9 , V_103 -> V_105 - V_103 -> V_106 ) ;
}
static inline unsigned int F_110 ( struct V_97 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_107 ; V_59 ++ )
if ( V_52 == & V_2 -> V_108 [ V_59 ] )
break;
F_111 ( V_59 >= V_2 -> V_107 ) ;
return V_59 ;
}
static T_1 F_112 ( struct V_97 * V_52 ,
struct V_96 * V_49 , char * V_8 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_109 * V_110 ;
T_3 V_58 ;
unsigned long V_88 ;
T_2 V_13 = 0 ;
int V_59 ;
if ( ! F_50 ( & V_58 , V_60 ) )
return - V_61 ;
V_88 = F_110 ( V_52 ) ;
F_51 () ;
V_110 = F_52 ( V_2 -> V_111 ) ;
if ( V_110 ) {
F_113 (i) {
struct V_112 * V_57 =
F_52 ( V_110 -> V_113 [ V_59 ] ) ;
if ( V_57 ) {
int V_114 ;
for ( V_114 = 0 ; V_114 < V_57 -> V_13 ; V_114 ++ ) {
if ( V_57 -> V_115 [ V_114 ] == V_88 ) {
F_53 ( V_59 , V_58 ) ;
break;
}
}
}
}
}
F_55 () ;
V_13 += F_54 ( V_8 + V_13 , V_63 , V_58 ) ;
if ( V_63 - V_13 < 3 ) {
F_56 ( V_58 ) ;
return - V_11 ;
}
F_56 ( V_58 ) ;
V_13 += sprintf ( V_8 + V_13 , L_5 ) ;
return V_13 ;
}
static void F_114 ( struct V_97 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_109 * V_110 ;
struct V_112 * V_57 ;
unsigned long V_88 ;
int V_59 , V_116 , V_117 = 0 ;
V_88 = F_110 ( V_52 ) ;
F_115 ( & V_118 ) ;
V_110 = F_116 ( V_2 -> V_111 ) ;
if ( V_110 ) {
F_113 (i) {
V_57 = F_116 ( V_110 -> V_113 [ V_59 ] ) ;
if ( ! V_57 )
continue;
for ( V_116 = 0 ; V_116 < V_57 -> V_13 ; V_116 ++ )
if ( V_57 -> V_115 [ V_116 ] == V_88 )
break;
if ( V_116 < V_57 -> V_13 ) {
if ( V_57 -> V_13 > 1 )
V_57 -> V_115 [ V_116 ] =
V_57 -> V_115 [ -- V_57 -> V_13 ] ;
else {
F_86 ( V_110 -> V_113 [ V_59 ] ,
NULL ) ;
F_72 ( V_57 , V_69 ) ;
V_57 = NULL ;
}
}
if ( V_57 )
V_117 = 1 ;
}
if ( ! V_117 ) {
F_86 ( V_2 -> V_111 , NULL ) ;
F_72 ( V_110 , V_69 ) ;
}
}
F_117 ( & V_118 ) ;
}
static T_1 F_118 ( struct V_97 * V_52 ,
struct V_96 * V_49 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_3 V_58 ;
int V_17 , V_59 , V_65 , V_116 , V_119 , V_120 , V_121 ;
unsigned long V_88 ;
struct V_112 * V_57 , * V_122 ;
struct V_109 * V_110 , * V_123 ;
int V_117 = 0 ;
int V_124 = - 2 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( ! F_59 ( & V_58 , V_60 ) )
return - V_61 ;
V_88 = F_110 ( V_52 ) ;
V_17 = F_60 ( V_8 , V_13 , F_61 ( V_58 ) , V_67 ) ;
if ( V_17 ) {
F_56 ( V_58 ) ;
return V_17 ;
}
V_123 = F_62 ( F_63 (unsigned int,
XPS_DEV_MAPS_SIZE, L1_CACHE_BYTES) , V_60 ) ;
if ( ! V_123 ) {
F_56 ( V_58 ) ;
return - V_61 ;
}
F_115 ( & V_118 ) ;
V_110 = F_116 ( V_2 -> V_111 ) ;
F_113 (cpu) {
V_57 = V_110 ?
F_116 ( V_110 -> V_113 [ V_65 ] ) : NULL ;
V_122 = V_57 ;
if ( V_57 ) {
for ( V_116 = 0 ; V_116 < V_57 -> V_13 ; V_116 ++ )
if ( V_57 -> V_115 [ V_116 ] == V_88 )
break;
V_119 = V_57 -> V_13 ;
V_120 = V_57 -> V_120 ;
} else
V_116 = V_119 = V_120 = 0 ;
V_121 = F_119 ( V_65 , V_58 ) && F_120 ( V_65 ) ;
#ifdef F_121
if ( V_121 ) {
if ( V_124 == - 2 )
V_124 = F_122 ( V_65 ) ;
else if ( V_124 != F_122 ( V_65 ) )
V_124 = - 1 ;
}
#endif
if ( V_121 && V_116 >= V_119 ) {
if ( V_119 >= V_120 ) {
V_120 = V_120 ?
2 * V_120 : V_125 ;
V_122 = F_123 ( F_124 ( V_120 ) ,
V_60 ,
F_122 ( V_65 ) ) ;
if ( ! V_122 )
goto error;
V_122 -> V_120 = V_120 ;
for ( V_59 = 0 ; V_59 < V_119 ; V_59 ++ )
V_122 -> V_115 [ V_59 ] = V_57 -> V_115 [ V_59 ] ;
V_122 -> V_13 = V_119 ;
}
V_122 -> V_115 [ V_122 -> V_13 ++ ] = V_88 ;
} else if ( ! V_121 && V_116 < V_119 ) {
if ( V_119 > 1 )
V_122 -> V_115 [ V_116 ] =
V_122 -> V_115 [ -- V_122 -> V_13 ] ;
else
V_122 = NULL ;
}
F_86 ( V_123 -> V_113 [ V_65 ] , V_122 ) ;
}
F_113 (cpu) {
V_57 = V_110 ?
F_116 ( V_110 -> V_113 [ V_65 ] ) : NULL ;
if ( V_57 && F_116 ( V_123 -> V_113 [ V_65 ] ) != V_57 )
F_72 ( V_57 , V_69 ) ;
if ( V_123 -> V_113 [ V_65 ] )
V_117 = 1 ;
}
if ( V_117 ) {
F_69 ( V_2 -> V_111 , V_123 ) ;
} else {
F_65 ( V_123 ) ;
F_86 ( V_2 -> V_111 , NULL ) ;
}
if ( V_110 )
F_72 ( V_110 , V_69 ) ;
F_125 ( V_52 , ( V_124 >= 0 ) ? V_124 :
V_126 ) ;
F_117 ( & V_118 ) ;
F_56 ( V_58 ) ;
return V_13 ;
error:
F_117 ( & V_118 ) ;
if ( V_123 )
F_113 (i)
F_65 ( F_67 (
V_123 -> V_113 [ V_59 ] ,
1 ) ) ;
F_65 ( V_123 ) ;
F_56 ( V_58 ) ;
return - V_61 ;
}
static void F_126 ( struct V_47 * V_48 )
{
struct V_97 * V_52 = F_97 ( V_48 ) ;
#ifdef F_127
F_114 ( V_52 ) ;
#endif
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_87 ( V_52 -> V_2 ) ;
}
static int F_128 ( struct V_1 * V_9 , int V_88 )
{
struct V_97 * V_52 = V_9 -> V_108 + V_88 ;
struct V_47 * V_48 = & V_52 -> V_48 ;
int error = 0 ;
V_48 -> V_90 = V_9 -> V_91 ;
error = F_89 ( V_48 , & V_127 , NULL ,
L_12 , V_88 ) ;
if ( error )
goto exit;
#ifdef F_129
error = F_130 ( V_48 , & V_128 ) ;
if ( error )
goto exit;
#endif
F_91 ( V_48 , V_93 ) ;
F_92 ( V_52 -> V_2 ) ;
return 0 ;
exit:
F_90 ( V_48 ) ;
return error ;
}
int
F_131 ( struct V_1 * V_9 , int V_94 , int V_95 )
{
#ifdef F_132
int V_59 ;
int error = 0 ;
for ( V_59 = V_94 ; V_59 < V_95 ; V_59 ++ ) {
error = F_128 ( V_9 , V_59 ) ;
if ( error ) {
V_95 = V_94 ;
break;
}
}
while ( -- V_59 >= V_95 ) {
struct V_97 * V_52 = V_9 -> V_108 + V_59 ;
#ifdef F_129
F_133 ( & V_52 -> V_48 , & V_128 ) ;
#endif
F_90 ( & V_52 -> V_48 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_134 ( struct V_1 * V_9 )
{
int error = 0 , V_129 = 0 , V_130 = 0 , V_131 = 0 , V_132 = 0 ;
#ifdef F_132
V_9 -> V_91 = F_135 ( L_13 ,
NULL , & V_9 -> V_2 . V_48 ) ;
if ( ! V_9 -> V_91 )
return - V_61 ;
#endif
#ifdef F_94
V_131 = V_9 -> V_133 ;
#endif
V_132 = V_9 -> V_134 ;
error = F_93 ( V_9 , 0 , V_131 ) ;
if ( error )
goto error;
V_130 = V_131 ;
error = F_131 ( V_9 , 0 , V_132 ) ;
if ( error )
goto error;
V_129 = V_132 ;
return 0 ;
error:
F_131 ( V_9 , V_129 , 0 ) ;
F_93 ( V_9 , V_130 , 0 ) ;
return error ;
}
static void F_136 ( struct V_1 * V_9 )
{
int V_131 = 0 , V_132 = 0 ;
#ifdef F_94
V_131 = V_9 -> V_133 ;
#endif
V_132 = V_9 -> V_134 ;
F_93 ( V_9 , V_131 , 0 ) ;
F_131 ( V_9 , V_132 , 0 ) ;
#ifdef F_132
F_137 ( V_9 -> V_91 ) ;
#endif
}
static void * F_138 ( void )
{
struct V_9 * V_135 = V_136 -> V_137 -> V_138 ;
#ifdef F_139
if ( V_135 )
F_140 ( & V_135 -> V_139 ) ;
#endif
return V_135 ;
}
static const void * F_141 ( void )
{
return & V_140 ;
}
static const void * F_142 ( struct V_141 * V_142 )
{
return F_143 ( V_142 ) ;
}
static int F_144 ( struct V_5 * V_39 , struct V_143 * V_144 )
{
struct V_1 * V_2 = F_4 ( V_39 ) ;
int V_145 ;
V_145 = F_145 ( V_144 , L_14 , V_2 -> V_146 ) ;
if ( V_145 )
goto exit;
V_145 = F_145 ( V_144 , L_15 , V_2 -> V_147 ) ;
exit:
return V_145 ;
}
static void F_146 ( struct V_5 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_39 ) ;
F_111 ( V_2 -> V_3 != V_148 ) ;
F_65 ( V_2 -> V_37 ) ;
F_65 ( ( char * ) V_2 - V_2 -> V_149 ) ;
}
static const void * F_147 ( struct V_5 * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_39 , struct V_1 , V_2 ) ;
return F_148 ( V_2 ) ;
}
void F_149 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_150 ( & V_2 -> V_48 ) ;
F_136 ( V_9 ) ;
F_151 ( V_2 ) ;
}
int F_152 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_150 * * V_151 = V_9 -> V_152 ;
int error = 0 ;
F_153 ( V_2 ) ;
V_2 -> V_153 = & V_154 ;
V_2 -> V_155 = V_9 ;
V_2 -> V_151 = V_151 ;
F_154 ( V_2 , L_16 , V_9 -> V_146 ) ;
#ifdef F_132
if ( * V_151 )
V_151 ++ ;
* V_151 ++ = & V_156 ;
#if F_155 ( V_157 ) || F_155 ( V_158 )
if ( V_9 -> V_159 )
* V_151 ++ = & V_160 ;
#if F_155 ( V_157 )
else if ( V_9 -> V_161 )
* V_151 ++ = & V_160 ;
#endif
#endif
#endif
error = F_156 ( V_2 ) ;
if ( error )
return error ;
error = F_134 ( V_9 ) ;
if ( error ) {
F_151 ( V_2 ) ;
return error ;
}
return error ;
}
int F_157 ( struct V_162 * V_163 )
{
return F_158 ( & V_154 , V_163 ) ;
}
void F_159 ( struct V_162 * V_163 )
{
F_160 ( & V_154 , V_163 ) ;
}
int F_161 ( void )
{
F_162 ( & V_164 ) ;
return F_163 ( & V_154 ) ;
}
