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
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_9 * V_9 = F_9 ( V_14 ) ;
unsigned long V_15 ;
int V_10 = - V_11 ;
if ( ! F_10 ( V_9 -> V_16 , V_17 ) )
return - V_18 ;
V_10 = F_11 ( V_8 , 0 , & V_15 ) ;
if ( V_10 )
goto V_19;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
if ( ( V_10 = (* F_8)( V_14 , V_15 ) ) == 0 )
V_10 = V_13 ;
}
F_14 () ;
V_19:
return V_10 ;
}
static T_1 F_15 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = F_16 ( V_8 , V_9 -> V_20 , V_9 -> V_21 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_17 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
if ( F_1 ( V_9 ) )
return F_16 ( V_8 , V_9 -> V_22 , V_9 -> V_21 ) ;
return - V_11 ;
}
static T_1 F_18 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_19 ( V_14 ) ) {
return sprintf ( V_8 , V_23 , ! ! F_20 ( V_14 ) ) ;
}
return - V_11 ;
}
static T_1 F_21 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_19 ( V_14 ) ) {
struct V_24 V_25 ;
if ( ! F_22 ( V_14 , & V_25 ) )
V_10 = sprintf ( V_8 , V_26 , F_23 ( & V_25 ) ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_24 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_19 ( V_14 ) ) {
struct V_24 V_25 ;
if ( ! F_22 ( V_14 , & V_25 ) ) {
const char * V_27 ;
switch ( V_25 . V_27 ) {
case V_28 :
V_27 = L_1 ;
break;
case V_29 :
V_27 = L_2 ;
break;
default:
V_27 = L_3 ;
break;
}
V_10 = sprintf ( V_8 , L_4 , V_27 ) ;
}
}
F_14 () ;
return V_10 ;
}
static T_1 F_25 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_19 ( V_14 ) )
return sprintf ( V_8 , V_23 , ! ! F_26 ( V_14 ) ) ;
return - V_11 ;
}
static T_1 F_27 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
unsigned char V_30 ;
F_5 ( & V_12 ) ;
V_30 = V_14 -> V_30 ;
if ( ! F_19 ( V_14 ) )
V_30 = V_31 ;
F_6 ( & V_12 ) ;
if ( V_30 >= F_28 ( V_32 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_32 [ V_30 ] ) ;
}
static int F_29 ( struct V_1 * V_9 , unsigned long V_33 )
{
return F_30 ( V_9 , ( int ) V_33 ) ;
}
static T_1 F_31 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_29 ) ;
}
static int F_32 ( struct V_1 * V_9 , unsigned long V_34 )
{
return F_33 ( V_9 , ( unsigned int ) V_34 ) ;
}
static T_1 F_34 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_32 ) ;
}
static int F_35 ( struct V_1 * V_9 , unsigned long V_35 )
{
V_9 -> V_36 = V_35 ;
return 0 ;
}
static T_1 F_36 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_37 ( V_17 ) )
return - V_18 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_35 ) ;
}
static T_1 F_38 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_9 * V_9 = F_9 ( V_14 ) ;
T_2 V_37 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_9 -> V_16 , V_17 ) )
return - V_18 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_37 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_39 ( V_14 , V_8 , V_37 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_40 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_38 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_38 ) ;
F_14 () ;
return V_10 ;
}
static int F_41 ( struct V_1 * V_9 , unsigned long V_39 )
{
F_42 ( V_9 , ( int ) V_39 ) ;
return 0 ;
}
static T_1 F_43 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_41 ) ;
}
static T_1 F_44 ( const struct V_5 * V_40 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_41 )
{
struct V_1 * V_2 = F_4 ( V_40 ) ;
T_1 V_10 = - V_11 ;
F_45 ( V_41 > sizeof( struct V_42 ) ||
V_41 % sizeof( V_43 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_42 V_44 ;
const struct V_42 * V_45 = F_46 ( V_2 , & V_44 ) ;
V_10 = sprintf ( V_8 , V_46 , * ( V_43 * ) ( ( ( V_47 * ) V_45 ) + V_41 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_47 ( struct V_48 * V_49 , struct V_50 * V_7 ,
char * V_8 )
{
struct V_51 * V_50 = F_48 ( V_7 ) ;
struct V_52 * V_53 = F_49 ( V_49 ) ;
if ( ! V_50 -> V_54 )
return - V_55 ;
return V_50 -> V_54 ( V_53 , V_50 , V_8 ) ;
}
static T_1 F_50 ( struct V_48 * V_49 , struct V_50 * V_7 ,
const char * V_8 , T_2 V_37 )
{
struct V_51 * V_50 = F_48 ( V_7 ) ;
struct V_52 * V_53 = F_49 ( V_49 ) ;
if ( ! V_50 -> V_56 )
return - V_55 ;
return V_50 -> V_56 ( V_53 , V_50 , V_8 , V_37 ) ;
}
static T_1 F_51 ( struct V_52 * V_53 ,
struct V_51 * V_50 , char * V_8 )
{
struct V_57 * V_58 ;
T_3 V_59 ;
T_2 V_13 = 0 ;
int V_60 ;
if ( ! F_52 ( & V_59 , V_61 ) )
return - V_62 ;
F_53 () ;
V_58 = F_54 ( V_53 -> V_57 ) ;
if ( V_58 )
for ( V_60 = 0 ; V_60 < V_58 -> V_13 ; V_60 ++ )
F_55 ( V_58 -> V_63 [ V_60 ] , V_59 ) ;
V_13 += F_56 ( V_8 + V_13 , V_64 , V_59 ) ;
if ( V_64 - V_13 < 3 ) {
F_57 () ;
F_58 ( V_59 ) ;
return - V_11 ;
}
F_57 () ;
F_58 ( V_59 ) ;
V_13 += sprintf ( V_8 + V_13 , L_5 ) ;
return V_13 ;
}
static T_1 F_59 ( struct V_52 * V_53 ,
struct V_51 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_57 * V_65 , * V_58 ;
T_3 V_59 ;
int V_19 , V_66 , V_60 ;
static F_60 ( V_67 ) ;
if ( ! F_37 ( V_17 ) )
return - V_18 ;
if ( ! F_61 ( & V_59 , V_61 ) )
return - V_62 ;
V_19 = F_62 ( V_8 , V_13 , F_63 ( V_59 ) , V_68 ) ;
if ( V_19 ) {
F_58 ( V_59 ) ;
return V_19 ;
}
V_58 = F_64 ( F_65 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_61 ) ;
if ( ! V_58 ) {
F_58 ( V_59 ) ;
return - V_62 ;
}
V_60 = 0 ;
F_66 (cpu, mask, cpu_online_mask)
V_58 -> V_63 [ V_60 ++ ] = V_66 ;
if ( V_60 )
V_58 -> V_13 = V_60 ;
else {
F_67 ( V_58 ) ;
V_58 = NULL ;
}
F_68 ( & V_67 ) ;
V_65 = F_69 ( V_53 -> V_57 ,
F_70 ( & V_67 ) ) ;
F_71 ( V_53 -> V_57 , V_58 ) ;
F_72 ( & V_67 ) ;
if ( V_58 )
F_73 ( & V_69 ) ;
if ( V_65 ) {
F_74 ( V_65 , V_70 ) ;
F_75 ( & V_69 ) ;
}
F_58 ( V_59 ) ;
return V_13 ;
}
static T_1 F_76 ( struct V_52 * V_53 ,
struct V_51 * V_7 ,
char * V_8 )
{
struct V_71 * V_72 ;
unsigned long V_73 = 0 ;
F_53 () ;
V_72 = F_54 ( V_53 -> V_74 ) ;
if ( V_72 )
V_73 = ( unsigned long ) V_72 -> V_59 + 1 ;
F_57 () ;
return sprintf ( V_8 , L_6 , V_73 ) ;
}
static void F_77 ( struct V_75 * V_76 )
{
struct V_71 * V_77 = F_78 ( V_76 ,
struct V_71 , V_78 ) ;
F_79 ( V_77 ) ;
}
static void F_80 ( struct V_79 * V_70 )
{
struct V_71 * V_77 = F_78 ( V_70 ,
struct V_71 , V_70 ) ;
F_81 ( & V_77 -> V_78 , F_77 ) ;
F_82 ( & V_77 -> V_78 ) ;
}
static T_1 F_83 ( struct V_52 * V_53 ,
struct V_51 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_59 , V_37 ;
struct V_71 * V_77 , * V_80 ;
static F_60 ( V_81 ) ;
int V_82 ;
if ( ! F_37 ( V_17 ) )
return - V_18 ;
V_82 = F_11 ( V_8 , 0 , & V_37 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_37 ) {
V_59 = V_37 - 1 ;
while ( ( V_59 | ( V_59 >> 1 ) ) != V_59 )
V_59 |= ( V_59 >> 1 ) ;
#if V_83 > 32
if ( V_59 > ( unsigned long ) ( V_84 ) V_59 )
return - V_11 ;
#else
if ( V_59 > ( V_85 - F_84 ( 1 ) )
/ sizeof( struct V_86 ) ) {
return - V_11 ;
}
#endif
V_77 = F_85 ( F_84 ( V_59 + 1 ) ) ;
if ( ! V_77 )
return - V_62 ;
V_77 -> V_59 = V_59 ;
for ( V_37 = 0 ; V_37 <= V_59 ; V_37 ++ )
V_77 -> V_87 [ V_37 ] . V_66 = V_88 ;
} else
V_77 = NULL ;
F_68 ( & V_81 ) ;
V_80 = F_69 ( V_53 -> V_74 ,
F_70 ( & V_81 ) ) ;
F_71 ( V_53 -> V_74 , V_77 ) ;
F_72 ( & V_81 ) ;
if ( V_80 )
F_86 ( & V_80 -> V_70 , F_80 ) ;
return V_13 ;
}
static void F_87 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = F_49 ( V_49 ) ;
struct V_57 * V_58 ;
struct V_71 * V_72 ;
V_58 = F_69 ( V_53 -> V_57 , 1 ) ;
if ( V_58 ) {
F_88 ( V_53 -> V_57 , NULL ) ;
F_74 ( V_58 , V_70 ) ;
}
V_72 = F_69 ( V_53 -> V_74 , 1 ) ;
if ( V_72 ) {
F_88 ( V_53 -> V_74 , NULL ) ;
F_86 ( & V_72 -> V_70 , F_80 ) ;
}
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_89 ( V_53 -> V_2 ) ;
}
static int F_90 ( struct V_1 * V_9 , int V_89 )
{
struct V_52 * V_53 = V_9 -> V_90 + V_89 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_91 = V_9 -> V_92 ;
error = F_91 ( V_49 , & V_93 , NULL ,
L_7 , V_89 ) ;
if ( error ) {
F_92 ( V_49 ) ;
return error ;
}
F_93 ( V_49 , V_94 ) ;
F_94 ( V_53 -> V_2 ) ;
return error ;
}
int
F_95 ( struct V_1 * V_9 , int V_95 , int V_96 )
{
#ifdef F_96
int V_60 ;
int error = 0 ;
for ( V_60 = V_95 ; V_60 < V_96 ; V_60 ++ ) {
error = F_90 ( V_9 , V_60 ) ;
if ( error ) {
V_96 = V_95 ;
break;
}
}
while ( -- V_60 >= V_96 )
F_92 ( & V_9 -> V_90 [ V_60 ] . V_49 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_97 ( struct V_48 * V_49 ,
struct V_50 * V_7 , char * V_8 )
{
struct V_97 * V_50 = F_98 ( V_7 ) ;
struct V_98 * V_53 = F_99 ( V_49 ) ;
if ( ! V_50 -> V_54 )
return - V_55 ;
return V_50 -> V_54 ( V_53 , V_50 , V_8 ) ;
}
static T_1 F_100 ( struct V_48 * V_49 ,
struct V_50 * V_7 ,
const char * V_8 , T_2 V_37 )
{
struct V_97 * V_50 = F_98 ( V_7 ) ;
struct V_98 * V_53 = F_99 ( V_49 ) ;
if ( ! V_50 -> V_56 )
return - V_55 ;
return V_50 -> V_56 ( V_53 , V_50 , V_8 , V_37 ) ;
}
static T_1 F_101 ( struct V_98 * V_53 ,
struct V_97 * V_50 ,
char * V_8 )
{
unsigned long V_99 ;
F_102 ( & V_53 -> V_100 ) ;
V_99 = V_53 -> V_99 ;
F_103 ( & V_53 -> V_100 ) ;
return sprintf ( V_8 , L_8 , V_99 ) ;
}
static T_1 F_104 ( char * V_8 , unsigned int V_101 )
{
return sprintf ( V_8 , L_9 , V_101 ) ;
}
static T_1 F_105 ( const char * V_8 , const T_2 V_37 ,
unsigned int * V_102 )
{
unsigned int V_101 ;
int V_19 ;
if ( ! strcmp ( V_8 , L_10 ) || ! strcmp ( V_8 , L_11 ) )
V_101 = V_103 ;
else {
V_19 = F_106 ( V_8 , 10 , & V_101 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_101 > V_103 )
return - V_11 ;
}
* V_102 = V_101 ;
return V_37 ;
}
static T_1 F_107 ( struct V_98 * V_53 ,
struct V_97 * V_7 ,
char * V_8 )
{
struct V_104 * V_104 = & V_53 -> V_104 ;
return sprintf ( V_8 , L_9 , F_108 ( V_104 -> V_105 ) ) ;
}
static T_1 F_109 ( struct V_98 * V_53 ,
struct V_97 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_104 * V_104 = & V_53 -> V_104 ;
unsigned int V_101 ;
int V_19 ;
V_19 = F_106 ( V_8 , 10 , & V_101 ) ;
if ( V_19 < 0 )
return V_19 ;
V_104 -> V_105 = F_110 ( V_101 ) ;
return V_13 ;
}
static T_1 F_111 ( struct V_98 * V_53 ,
struct V_97 * V_7 ,
char * V_8 )
{
struct V_104 * V_104 = & V_53 -> V_104 ;
return sprintf ( V_8 , L_9 , V_104 -> V_106 - V_104 -> V_107 ) ;
}
static inline unsigned int F_112 ( struct V_98 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_108 ; V_60 ++ )
if ( V_53 == & V_2 -> V_109 [ V_60 ] )
break;
F_113 ( V_60 >= V_2 -> V_108 ) ;
return V_60 ;
}
static T_1 F_114 ( struct V_98 * V_53 ,
struct V_97 * V_50 , char * V_8 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_110 * V_111 ;
T_3 V_59 ;
unsigned long V_89 ;
T_2 V_13 = 0 ;
int V_60 ;
if ( ! F_52 ( & V_59 , V_61 ) )
return - V_62 ;
V_89 = F_112 ( V_53 ) ;
F_53 () ;
V_111 = F_54 ( V_2 -> V_112 ) ;
if ( V_111 ) {
F_115 (i) {
struct V_113 * V_58 =
F_54 ( V_111 -> V_114 [ V_60 ] ) ;
if ( V_58 ) {
int V_115 ;
for ( V_115 = 0 ; V_115 < V_58 -> V_13 ; V_115 ++ ) {
if ( V_58 -> V_116 [ V_115 ] == V_89 ) {
F_55 ( V_60 , V_59 ) ;
break;
}
}
}
}
}
F_57 () ;
V_13 += F_56 ( V_8 + V_13 , V_64 , V_59 ) ;
if ( V_64 - V_13 < 3 ) {
F_58 ( V_59 ) ;
return - V_11 ;
}
F_58 ( V_59 ) ;
V_13 += sprintf ( V_8 + V_13 , L_5 ) ;
return V_13 ;
}
static void F_116 ( struct V_98 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_110 * V_111 ;
struct V_113 * V_58 ;
unsigned long V_89 ;
int V_60 , V_117 , V_118 = 0 ;
V_89 = F_112 ( V_53 ) ;
F_117 ( & V_119 ) ;
V_111 = F_118 ( V_2 -> V_112 ) ;
if ( V_111 ) {
F_115 (i) {
V_58 = F_118 ( V_111 -> V_114 [ V_60 ] ) ;
if ( ! V_58 )
continue;
for ( V_117 = 0 ; V_117 < V_58 -> V_13 ; V_117 ++ )
if ( V_58 -> V_116 [ V_117 ] == V_89 )
break;
if ( V_117 < V_58 -> V_13 ) {
if ( V_58 -> V_13 > 1 )
V_58 -> V_116 [ V_117 ] =
V_58 -> V_116 [ -- V_58 -> V_13 ] ;
else {
F_88 ( V_111 -> V_114 [ V_60 ] ,
NULL ) ;
F_74 ( V_58 , V_70 ) ;
V_58 = NULL ;
}
}
if ( V_58 )
V_118 = 1 ;
}
if ( ! V_118 ) {
F_88 ( V_2 -> V_112 , NULL ) ;
F_74 ( V_111 , V_70 ) ;
}
}
F_119 ( & V_119 ) ;
}
static T_1 F_120 ( struct V_98 * V_53 ,
struct V_97 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_3 V_59 ;
int V_19 , V_60 , V_66 , V_117 , V_120 , V_121 , V_122 ;
unsigned long V_89 ;
struct V_113 * V_58 , * V_123 ;
struct V_110 * V_111 , * V_124 ;
int V_118 = 0 ;
int V_125 = - 2 ;
if ( ! F_37 ( V_17 ) )
return - V_18 ;
if ( ! F_61 ( & V_59 , V_61 ) )
return - V_62 ;
V_89 = F_112 ( V_53 ) ;
V_19 = F_62 ( V_8 , V_13 , F_63 ( V_59 ) , V_68 ) ;
if ( V_19 ) {
F_58 ( V_59 ) ;
return V_19 ;
}
V_124 = F_64 ( F_65 (unsigned int,
XPS_DEV_MAPS_SIZE, L1_CACHE_BYTES) , V_61 ) ;
if ( ! V_124 ) {
F_58 ( V_59 ) ;
return - V_62 ;
}
F_117 ( & V_119 ) ;
V_111 = F_118 ( V_2 -> V_112 ) ;
F_115 (cpu) {
V_58 = V_111 ?
F_118 ( V_111 -> V_114 [ V_66 ] ) : NULL ;
V_123 = V_58 ;
if ( V_58 ) {
for ( V_117 = 0 ; V_117 < V_58 -> V_13 ; V_117 ++ )
if ( V_58 -> V_116 [ V_117 ] == V_89 )
break;
V_120 = V_58 -> V_13 ;
V_121 = V_58 -> V_121 ;
} else
V_117 = V_120 = V_121 = 0 ;
V_122 = F_121 ( V_66 , V_59 ) && F_122 ( V_66 ) ;
#ifdef F_123
if ( V_122 ) {
if ( V_125 == - 2 )
V_125 = F_124 ( V_66 ) ;
else if ( V_125 != F_124 ( V_66 ) )
V_125 = - 1 ;
}
#endif
if ( V_122 && V_117 >= V_120 ) {
if ( V_120 >= V_121 ) {
V_121 = V_121 ?
2 * V_121 : V_126 ;
V_123 = F_125 ( F_126 ( V_121 ) ,
V_61 ,
F_124 ( V_66 ) ) ;
if ( ! V_123 )
goto error;
V_123 -> V_121 = V_121 ;
for ( V_60 = 0 ; V_60 < V_120 ; V_60 ++ )
V_123 -> V_116 [ V_60 ] = V_58 -> V_116 [ V_60 ] ;
V_123 -> V_13 = V_120 ;
}
V_123 -> V_116 [ V_123 -> V_13 ++ ] = V_89 ;
} else if ( ! V_122 && V_117 < V_120 ) {
if ( V_120 > 1 )
V_123 -> V_116 [ V_117 ] =
V_123 -> V_116 [ -- V_123 -> V_13 ] ;
else
V_123 = NULL ;
}
F_88 ( V_124 -> V_114 [ V_66 ] , V_123 ) ;
}
F_115 (cpu) {
V_58 = V_111 ?
F_118 ( V_111 -> V_114 [ V_66 ] ) : NULL ;
if ( V_58 && F_118 ( V_124 -> V_114 [ V_66 ] ) != V_58 )
F_74 ( V_58 , V_70 ) ;
if ( V_124 -> V_114 [ V_66 ] )
V_118 = 1 ;
}
if ( V_118 ) {
F_71 ( V_2 -> V_112 , V_124 ) ;
} else {
F_67 ( V_124 ) ;
F_88 ( V_2 -> V_112 , NULL ) ;
}
if ( V_111 )
F_74 ( V_111 , V_70 ) ;
F_127 ( V_53 , ( V_125 >= 0 ) ? V_125 :
V_127 ) ;
F_119 ( & V_119 ) ;
F_58 ( V_59 ) ;
return V_13 ;
error:
F_119 ( & V_119 ) ;
if ( V_124 )
F_115 (i)
F_67 ( F_69 (
V_124 -> V_114 [ V_60 ] ,
1 ) ) ;
F_67 ( V_124 ) ;
F_58 ( V_59 ) ;
return - V_62 ;
}
static void F_128 ( struct V_48 * V_49 )
{
struct V_98 * V_53 = F_99 ( V_49 ) ;
#ifdef F_129
F_116 ( V_53 ) ;
#endif
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_89 ( V_53 -> V_2 ) ;
}
static int F_130 ( struct V_1 * V_9 , int V_89 )
{
struct V_98 * V_53 = V_9 -> V_109 + V_89 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_91 = V_9 -> V_92 ;
error = F_91 ( V_49 , & V_128 , NULL ,
L_12 , V_89 ) ;
if ( error )
goto exit;
#ifdef F_131
error = F_132 ( V_49 , & V_129 ) ;
if ( error )
goto exit;
#endif
F_93 ( V_49 , V_94 ) ;
F_94 ( V_53 -> V_2 ) ;
return 0 ;
exit:
F_92 ( V_49 ) ;
return error ;
}
int
F_133 ( struct V_1 * V_9 , int V_95 , int V_96 )
{
#ifdef F_134
int V_60 ;
int error = 0 ;
for ( V_60 = V_95 ; V_60 < V_96 ; V_60 ++ ) {
error = F_130 ( V_9 , V_60 ) ;
if ( error ) {
V_96 = V_95 ;
break;
}
}
while ( -- V_60 >= V_96 ) {
struct V_98 * V_53 = V_9 -> V_109 + V_60 ;
#ifdef F_131
F_135 ( & V_53 -> V_49 , & V_129 ) ;
#endif
F_92 ( & V_53 -> V_49 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_136 ( struct V_1 * V_9 )
{
int error = 0 , V_130 = 0 , V_131 = 0 , V_132 = 0 , V_133 = 0 ;
#ifdef F_134
V_9 -> V_92 = F_137 ( L_13 ,
NULL , & V_9 -> V_2 . V_49 ) ;
if ( ! V_9 -> V_92 )
return - V_62 ;
#endif
#ifdef F_96
V_132 = V_9 -> V_134 ;
#endif
V_133 = V_9 -> V_135 ;
error = F_95 ( V_9 , 0 , V_132 ) ;
if ( error )
goto error;
V_131 = V_132 ;
error = F_133 ( V_9 , 0 , V_133 ) ;
if ( error )
goto error;
V_130 = V_133 ;
return 0 ;
error:
F_133 ( V_9 , V_130 , 0 ) ;
F_95 ( V_9 , V_131 , 0 ) ;
return error ;
}
static void F_138 ( struct V_1 * V_9 )
{
int V_132 = 0 , V_133 = 0 ;
#ifdef F_96
V_132 = V_9 -> V_134 ;
#endif
V_133 = V_9 -> V_135 ;
F_95 ( V_9 , V_132 , 0 ) ;
F_133 ( V_9 , V_133 , 0 ) ;
#ifdef F_134
F_139 ( V_9 -> V_92 ) ;
#endif
}
static void * F_140 ( void )
{
struct V_9 * V_136 = V_137 -> V_138 -> V_139 ;
#ifdef F_141
if ( V_136 )
F_142 ( & V_136 -> V_140 ) ;
#endif
return V_136 ;
}
static const void * F_143 ( void )
{
return & V_141 ;
}
static const void * F_144 ( struct V_142 * V_143 )
{
return F_145 ( V_143 ) ;
}
static int F_146 ( struct V_5 * V_40 , struct V_144 * V_145 )
{
struct V_1 * V_2 = F_4 ( V_40 ) ;
int V_146 ;
V_146 = F_147 ( V_145 , L_14 , V_2 -> V_147 ) ;
if ( V_146 )
goto exit;
V_146 = F_147 ( V_145 , L_15 , V_2 -> V_148 ) ;
exit:
return V_146 ;
}
static void F_148 ( struct V_5 * V_40 )
{
struct V_1 * V_2 = F_4 ( V_40 ) ;
F_113 ( V_2 -> V_3 != V_149 ) ;
F_67 ( V_2 -> V_38 ) ;
F_67 ( ( char * ) V_2 - V_2 -> V_150 ) ;
}
static const void * F_149 ( struct V_5 * V_40 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_40 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_150 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_151 ( & V_2 -> V_49 ) ;
F_138 ( V_9 ) ;
F_152 ( V_2 ) ;
}
int F_153 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_151 * * V_152 = V_9 -> V_153 ;
int error = 0 ;
F_154 ( V_2 ) ;
V_2 -> V_154 = & V_155 ;
V_2 -> V_156 = V_9 ;
V_2 -> V_152 = V_152 ;
F_155 ( V_2 , L_16 , V_9 -> V_147 ) ;
#ifdef F_134
if ( * V_152 )
V_152 ++ ;
* V_152 ++ = & V_157 ;
#if F_156 ( V_158 ) || F_156 ( V_159 )
if ( V_9 -> V_160 )
* V_152 ++ = & V_161 ;
#if F_156 ( V_158 )
else if ( V_9 -> V_162 )
* V_152 ++ = & V_161 ;
#endif
#endif
#endif
error = F_157 ( V_2 ) ;
if ( error )
return error ;
error = F_136 ( V_9 ) ;
if ( error ) {
F_152 ( V_2 ) ;
return error ;
}
return error ;
}
int F_158 ( struct V_163 * V_164 )
{
return F_159 ( & V_155 , V_164 ) ;
}
void F_160 ( struct V_163 * V_164 )
{
F_161 ( & V_155 , V_164 ) ;
}
int F_162 ( void )
{
F_163 ( & V_165 ) ;
return F_164 ( & V_155 ) ;
}
