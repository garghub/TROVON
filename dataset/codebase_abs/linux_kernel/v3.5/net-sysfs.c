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
if ( ! F_21 ( V_21 , & V_24 ) )
V_10 = sprintf ( V_8 , L_1 ,
V_24 . V_26 ? L_2 : L_3 ) ;
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
unsigned char V_27 ;
F_5 ( & V_12 ) ;
V_27 = V_21 -> V_27 ;
if ( ! F_18 ( V_21 ) )
V_27 = V_28 ;
F_6 ( & V_12 ) ;
if ( V_27 >= F_27 ( V_29 ) )
return - V_11 ;
return sprintf ( V_8 , L_1 , V_29 [ V_27 ] ) ;
}
static int F_28 ( struct V_1 * V_9 , unsigned long V_30 )
{
return F_29 ( V_9 , ( int ) V_30 ) ;
}
static T_1 F_30 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_28 ) ;
}
static int F_31 ( struct V_1 * V_9 , unsigned long V_31 )
{
return F_32 ( V_9 , ( unsigned int ) V_31 ) ;
}
static T_1 F_33 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_31 ) ;
}
static int F_34 ( struct V_1 * V_9 , unsigned long V_32 )
{
V_9 -> V_33 = V_32 ;
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
T_2 V_34 = V_13 ;
T_1 V_10 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_34 ;
if ( ! F_11 () )
return F_12 () ;
V_10 = F_37 ( V_21 , V_8 , V_34 ) ;
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
if ( V_21 -> V_35 )
V_10 = sprintf ( V_8 , L_1 , V_21 -> V_35 ) ;
F_13 () ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_9 , unsigned long V_36 )
{
F_40 ( V_9 , ( int ) V_36 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_39 ) ;
}
static T_1 F_42 ( const struct V_5 * V_37 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_38 )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
T_1 V_10 = - V_11 ;
F_43 ( V_38 > sizeof( struct V_39 ) ||
V_38 % sizeof( V_40 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_39 V_41 ;
const struct V_39 * V_42 = F_44 ( V_2 , & V_41 ) ;
V_10 = sprintf ( V_8 , V_43 , * ( V_40 * ) ( ( ( V_44 * ) V_42 ) + V_38 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_45 ( struct V_5 * V_37 , char * V_8 ,
T_1 (* F_3)( const struct V_45 * ,
char * ) )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
const struct V_45 * V_46 ;
T_1 V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_1 ( V_2 ) ) {
V_46 = F_46 ( V_2 ) ;
if ( V_46 )
V_10 = (* F_3)( V_46 , V_8 ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_47 ( struct V_47 * V_48 , struct V_49 * V_7 ,
char * V_8 )
{
struct V_50 * V_49 = F_48 ( V_7 ) ;
struct V_51 * V_52 = F_49 ( V_48 ) ;
if ( ! V_49 -> V_53 )
return - V_54 ;
return V_49 -> V_53 ( V_52 , V_49 , V_8 ) ;
}
static T_1 F_50 ( struct V_47 * V_48 , struct V_49 * V_7 ,
const char * V_8 , T_2 V_34 )
{
struct V_50 * V_49 = F_48 ( V_7 ) ;
struct V_51 * V_52 = F_49 ( V_48 ) ;
if ( ! V_49 -> V_55 )
return - V_54 ;
return V_49 -> V_55 ( V_52 , V_49 , V_8 , V_34 ) ;
}
static T_1 F_51 ( struct V_51 * V_52 ,
struct V_50 * V_49 , char * V_8 )
{
struct V_56 * V_57 ;
T_3 V_58 ;
T_2 V_13 = 0 ;
int V_59 ;
if ( ! F_52 ( & V_58 , V_60 ) )
return - V_61 ;
F_53 () ;
V_57 = F_54 ( V_52 -> V_56 ) ;
if ( V_57 )
for ( V_59 = 0 ; V_59 < V_57 -> V_13 ; V_59 ++ )
F_55 ( V_57 -> V_62 [ V_59 ] , V_58 ) ;
V_13 += F_56 ( V_8 + V_13 , V_63 , V_58 ) ;
if ( V_63 - V_13 < 3 ) {
F_57 () ;
F_58 ( V_58 ) ;
return - V_11 ;
}
F_57 () ;
F_58 ( V_58 ) ;
V_13 += sprintf ( V_8 + V_13 , L_4 ) ;
return V_13 ;
}
static T_1 F_59 ( struct V_51 * V_52 ,
struct V_50 * V_49 ,
const char * V_8 , T_2 V_13 )
{
struct V_56 * V_64 , * V_57 ;
T_3 V_58 ;
int V_17 , V_65 , V_59 ;
static F_60 ( V_66 ) ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( ! F_61 ( & V_58 , V_60 ) )
return - V_61 ;
V_17 = F_62 ( V_8 , V_13 , F_63 ( V_58 ) , V_67 ) ;
if ( V_17 ) {
F_58 ( V_58 ) ;
return V_17 ;
}
V_57 = F_64 ( F_65 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_60 ) ;
if ( ! V_57 ) {
F_58 ( V_58 ) ;
return - V_61 ;
}
V_59 = 0 ;
F_66 (cpu, mask, cpu_online_mask)
V_57 -> V_62 [ V_59 ++ ] = V_65 ;
if ( V_59 )
V_57 -> V_13 = V_59 ;
else {
F_67 ( V_57 ) ;
V_57 = NULL ;
}
F_68 ( & V_66 ) ;
V_64 = F_69 ( V_52 -> V_56 ,
F_70 ( & V_66 ) ) ;
F_71 ( V_52 -> V_56 , V_57 ) ;
F_72 ( & V_66 ) ;
if ( V_57 )
F_73 ( & V_68 ) ;
if ( V_64 ) {
F_74 ( V_64 , V_69 ) ;
F_75 ( & V_68 ) ;
}
F_58 ( V_58 ) ;
return V_13 ;
}
static T_1 F_76 ( struct V_51 * V_52 ,
struct V_50 * V_7 ,
char * V_8 )
{
struct V_70 * V_71 ;
unsigned long V_72 = 0 ;
F_53 () ;
V_71 = F_54 ( V_52 -> V_73 ) ;
if ( V_71 )
V_72 = ( unsigned long ) V_71 -> V_58 + 1 ;
F_57 () ;
return sprintf ( V_8 , L_5 , V_72 ) ;
}
static void F_77 ( struct V_74 * V_75 )
{
struct V_70 * V_76 = F_78 ( V_75 ,
struct V_70 , V_77 ) ;
F_79 ( V_76 ) ;
}
static void F_80 ( struct V_78 * V_69 )
{
struct V_70 * V_76 = F_78 ( V_69 ,
struct V_70 , V_69 ) ;
F_81 ( & V_76 -> V_77 , F_77 ) ;
F_82 ( & V_76 -> V_77 ) ;
}
static T_1 F_83 ( struct V_51 * V_52 ,
struct V_50 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_58 , V_34 ;
struct V_70 * V_76 , * V_79 ;
static F_60 ( V_80 ) ;
int V_81 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
V_81 = F_10 ( V_8 , 0 , & V_34 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_34 ) {
V_58 = V_34 - 1 ;
while ( ( V_58 | ( V_58 >> 1 ) ) != V_58 )
V_58 |= ( V_58 >> 1 ) ;
#if V_82 > 32
if ( V_58 > ( unsigned long ) ( V_83 ) V_58 )
return - V_11 ;
#else
if ( V_58 > ( V_84 - F_84 ( 1 ) )
/ sizeof( struct V_85 ) ) {
return - V_11 ;
}
#endif
V_76 = F_85 ( F_84 ( V_58 + 1 ) ) ;
if ( ! V_76 )
return - V_61 ;
V_76 -> V_58 = V_58 ;
for ( V_34 = 0 ; V_34 <= V_58 ; V_34 ++ )
V_76 -> V_86 [ V_34 ] . V_65 = V_87 ;
} else
V_76 = NULL ;
F_68 ( & V_80 ) ;
V_79 = F_69 ( V_52 -> V_73 ,
F_70 ( & V_80 ) ) ;
F_71 ( V_52 -> V_73 , V_76 ) ;
F_72 ( & V_80 ) ;
if ( V_79 )
F_86 ( & V_79 -> V_69 , F_80 ) ;
return V_13 ;
}
static void F_87 ( struct V_47 * V_48 )
{
struct V_51 * V_52 = F_49 ( V_48 ) ;
struct V_56 * V_57 ;
struct V_70 * V_71 ;
V_57 = F_69 ( V_52 -> V_56 , 1 ) ;
if ( V_57 ) {
F_88 ( V_52 -> V_56 , NULL ) ;
F_74 ( V_57 , V_69 ) ;
}
V_71 = F_69 ( V_52 -> V_73 , 1 ) ;
if ( V_71 ) {
F_88 ( V_52 -> V_73 , NULL ) ;
F_86 ( & V_71 -> V_69 , F_80 ) ;
}
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_89 ( V_52 -> V_2 ) ;
}
static int F_90 ( struct V_1 * V_9 , int V_88 )
{
struct V_51 * V_52 = V_9 -> V_89 + V_88 ;
struct V_47 * V_48 = & V_52 -> V_48 ;
int error = 0 ;
V_48 -> V_90 = V_9 -> V_91 ;
error = F_91 ( V_48 , & V_92 , NULL ,
L_6 , V_88 ) ;
if ( error ) {
F_92 ( V_48 ) ;
return error ;
}
F_93 ( V_48 , V_93 ) ;
F_94 ( V_52 -> V_2 ) ;
return error ;
}
int
F_95 ( struct V_1 * V_9 , int V_94 , int V_95 )
{
#ifdef F_96
int V_59 ;
int error = 0 ;
for ( V_59 = V_94 ; V_59 < V_95 ; V_59 ++ ) {
error = F_90 ( V_9 , V_59 ) ;
if ( error ) {
V_95 = V_94 ;
break;
}
}
while ( -- V_59 >= V_95 )
F_92 ( & V_9 -> V_89 [ V_59 ] . V_48 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_97 ( struct V_47 * V_48 ,
struct V_49 * V_7 , char * V_8 )
{
struct V_96 * V_49 = F_98 ( V_7 ) ;
struct V_97 * V_52 = F_99 ( V_48 ) ;
if ( ! V_49 -> V_53 )
return - V_54 ;
return V_49 -> V_53 ( V_52 , V_49 , V_8 ) ;
}
static T_1 F_100 ( struct V_47 * V_48 ,
struct V_49 * V_7 ,
const char * V_8 , T_2 V_34 )
{
struct V_96 * V_49 = F_98 ( V_7 ) ;
struct V_97 * V_52 = F_99 ( V_48 ) ;
if ( ! V_49 -> V_55 )
return - V_54 ;
return V_49 -> V_55 ( V_52 , V_49 , V_8 , V_34 ) ;
}
static T_1 F_101 ( struct V_97 * V_52 ,
struct V_96 * V_49 ,
char * V_8 )
{
unsigned long V_98 ;
F_102 ( & V_52 -> V_99 ) ;
V_98 = V_52 -> V_98 ;
F_103 ( & V_52 -> V_99 ) ;
return sprintf ( V_8 , L_7 , V_98 ) ;
}
static T_1 F_104 ( char * V_8 , unsigned int V_100 )
{
return sprintf ( V_8 , L_8 , V_100 ) ;
}
static T_1 F_105 ( const char * V_8 , const T_2 V_34 ,
unsigned int * V_101 )
{
unsigned int V_100 ;
int V_17 ;
if ( ! strcmp ( V_8 , L_9 ) || ! strcmp ( V_8 , L_10 ) )
V_100 = V_102 ;
else {
V_17 = F_106 ( V_8 , 10 , & V_100 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_100 > V_102 )
return - V_11 ;
}
* V_101 = V_100 ;
return V_34 ;
}
static T_1 F_107 ( struct V_97 * V_52 ,
struct V_96 * V_7 ,
char * V_8 )
{
struct V_103 * V_103 = & V_52 -> V_103 ;
return sprintf ( V_8 , L_8 , F_108 ( V_103 -> V_104 ) ) ;
}
static T_1 F_109 ( struct V_97 * V_52 ,
struct V_96 * V_49 ,
const char * V_8 , T_2 V_13 )
{
struct V_103 * V_103 = & V_52 -> V_103 ;
unsigned int V_100 ;
int V_17 ;
V_17 = F_106 ( V_8 , 10 , & V_100 ) ;
if ( V_17 < 0 )
return V_17 ;
V_103 -> V_104 = F_110 ( V_100 ) ;
return V_13 ;
}
static T_1 F_111 ( struct V_97 * V_52 ,
struct V_96 * V_7 ,
char * V_8 )
{
struct V_103 * V_103 = & V_52 -> V_103 ;
return sprintf ( V_8 , L_8 , V_103 -> V_105 - V_103 -> V_106 ) ;
}
static inline unsigned int F_112 ( struct V_97 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_107 ; V_59 ++ )
if ( V_52 == & V_2 -> V_108 [ V_59 ] )
break;
F_113 ( V_59 >= V_2 -> V_107 ) ;
return V_59 ;
}
static T_1 F_114 ( struct V_97 * V_52 ,
struct V_96 * V_49 , char * V_8 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_109 * V_110 ;
T_3 V_58 ;
unsigned long V_88 ;
T_2 V_13 = 0 ;
int V_59 ;
if ( ! F_52 ( & V_58 , V_60 ) )
return - V_61 ;
V_88 = F_112 ( V_52 ) ;
F_53 () ;
V_110 = F_54 ( V_2 -> V_111 ) ;
if ( V_110 ) {
F_115 (i) {
struct V_112 * V_57 =
F_54 ( V_110 -> V_113 [ V_59 ] ) ;
if ( V_57 ) {
int V_114 ;
for ( V_114 = 0 ; V_114 < V_57 -> V_13 ; V_114 ++ ) {
if ( V_57 -> V_115 [ V_114 ] == V_88 ) {
F_55 ( V_59 , V_58 ) ;
break;
}
}
}
}
}
F_57 () ;
V_13 += F_56 ( V_8 + V_13 , V_63 , V_58 ) ;
if ( V_63 - V_13 < 3 ) {
F_58 ( V_58 ) ;
return - V_11 ;
}
F_58 ( V_58 ) ;
V_13 += sprintf ( V_8 + V_13 , L_4 ) ;
return V_13 ;
}
static void F_116 ( struct V_97 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_109 * V_110 ;
struct V_112 * V_57 ;
unsigned long V_88 ;
int V_59 , V_116 , V_117 = 0 ;
V_88 = F_112 ( V_52 ) ;
F_117 ( & V_118 ) ;
V_110 = F_118 ( V_2 -> V_111 ) ;
if ( V_110 ) {
F_115 (i) {
V_57 = F_118 ( V_110 -> V_113 [ V_59 ] ) ;
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
F_88 ( V_110 -> V_113 [ V_59 ] ,
NULL ) ;
F_74 ( V_57 , V_69 ) ;
V_57 = NULL ;
}
}
if ( V_57 )
V_117 = 1 ;
}
if ( ! V_117 ) {
F_88 ( V_2 -> V_111 , NULL ) ;
F_74 ( V_110 , V_69 ) ;
}
}
F_119 ( & V_118 ) ;
}
static T_1 F_120 ( struct V_97 * V_52 ,
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
if ( ! F_61 ( & V_58 , V_60 ) )
return - V_61 ;
V_88 = F_112 ( V_52 ) ;
V_17 = F_62 ( V_8 , V_13 , F_63 ( V_58 ) , V_67 ) ;
if ( V_17 ) {
F_58 ( V_58 ) ;
return V_17 ;
}
V_123 = F_64 ( F_65 (unsigned int,
XPS_DEV_MAPS_SIZE, L1_CACHE_BYTES) , V_60 ) ;
if ( ! V_123 ) {
F_58 ( V_58 ) ;
return - V_61 ;
}
F_117 ( & V_118 ) ;
V_110 = F_118 ( V_2 -> V_111 ) ;
F_115 (cpu) {
V_57 = V_110 ?
F_118 ( V_110 -> V_113 [ V_65 ] ) : NULL ;
V_122 = V_57 ;
if ( V_57 ) {
for ( V_116 = 0 ; V_116 < V_57 -> V_13 ; V_116 ++ )
if ( V_57 -> V_115 [ V_116 ] == V_88 )
break;
V_119 = V_57 -> V_13 ;
V_120 = V_57 -> V_120 ;
} else
V_116 = V_119 = V_120 = 0 ;
V_121 = F_121 ( V_65 , V_58 ) && F_122 ( V_65 ) ;
#ifdef F_123
if ( V_121 ) {
if ( V_124 == - 2 )
V_124 = F_124 ( V_65 ) ;
else if ( V_124 != F_124 ( V_65 ) )
V_124 = - 1 ;
}
#endif
if ( V_121 && V_116 >= V_119 ) {
if ( V_119 >= V_120 ) {
V_120 = V_120 ?
2 * V_120 : V_125 ;
V_122 = F_125 ( F_126 ( V_120 ) ,
V_60 ,
F_124 ( V_65 ) ) ;
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
F_88 ( V_123 -> V_113 [ V_65 ] , V_122 ) ;
}
F_115 (cpu) {
V_57 = V_110 ?
F_118 ( V_110 -> V_113 [ V_65 ] ) : NULL ;
if ( V_57 && F_118 ( V_123 -> V_113 [ V_65 ] ) != V_57 )
F_74 ( V_57 , V_69 ) ;
if ( V_123 -> V_113 [ V_65 ] )
V_117 = 1 ;
}
if ( V_117 ) {
F_71 ( V_2 -> V_111 , V_123 ) ;
} else {
F_67 ( V_123 ) ;
F_88 ( V_2 -> V_111 , NULL ) ;
}
if ( V_110 )
F_74 ( V_110 , V_69 ) ;
F_127 ( V_52 , ( V_124 >= 0 ) ? V_124 :
V_126 ) ;
F_119 ( & V_118 ) ;
F_58 ( V_58 ) ;
return V_13 ;
error:
F_119 ( & V_118 ) ;
if ( V_123 )
F_115 (i)
F_67 ( F_69 (
V_123 -> V_113 [ V_59 ] ,
1 ) ) ;
F_67 ( V_123 ) ;
F_58 ( V_58 ) ;
return - V_61 ;
}
static void F_128 ( struct V_47 * V_48 )
{
struct V_97 * V_52 = F_99 ( V_48 ) ;
#ifdef F_129
F_116 ( V_52 ) ;
#endif
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_89 ( V_52 -> V_2 ) ;
}
static int F_130 ( struct V_1 * V_9 , int V_88 )
{
struct V_97 * V_52 = V_9 -> V_108 + V_88 ;
struct V_47 * V_48 = & V_52 -> V_48 ;
int error = 0 ;
V_48 -> V_90 = V_9 -> V_91 ;
error = F_91 ( V_48 , & V_127 , NULL ,
L_11 , V_88 ) ;
if ( error )
goto exit;
#ifdef F_131
error = F_132 ( V_48 , & V_128 ) ;
if ( error )
goto exit;
#endif
F_93 ( V_48 , V_93 ) ;
F_94 ( V_52 -> V_2 ) ;
return 0 ;
exit:
F_92 ( V_48 ) ;
return error ;
}
int
F_133 ( struct V_1 * V_9 , int V_94 , int V_95 )
{
#ifdef F_134
int V_59 ;
int error = 0 ;
for ( V_59 = V_94 ; V_59 < V_95 ; V_59 ++ ) {
error = F_130 ( V_9 , V_59 ) ;
if ( error ) {
V_95 = V_94 ;
break;
}
}
while ( -- V_59 >= V_95 ) {
struct V_97 * V_52 = V_9 -> V_108 + V_59 ;
#ifdef F_131
F_135 ( & V_52 -> V_48 , & V_128 ) ;
#endif
F_92 ( & V_52 -> V_48 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_136 ( struct V_1 * V_9 )
{
int error = 0 , V_129 = 0 , V_130 = 0 , V_131 = 0 , V_132 = 0 ;
#ifdef F_134
V_9 -> V_91 = F_137 ( L_12 ,
NULL , & V_9 -> V_2 . V_48 ) ;
if ( ! V_9 -> V_91 )
return - V_61 ;
#endif
#ifdef F_96
V_131 = V_9 -> V_133 ;
#endif
V_132 = V_9 -> V_134 ;
error = F_95 ( V_9 , 0 , V_131 ) ;
if ( error )
goto error;
V_130 = V_131 ;
error = F_133 ( V_9 , 0 , V_132 ) ;
if ( error )
goto error;
V_129 = V_132 ;
return 0 ;
error:
F_133 ( V_9 , V_129 , 0 ) ;
F_95 ( V_9 , V_130 , 0 ) ;
return error ;
}
static void F_138 ( struct V_1 * V_9 )
{
int V_131 = 0 , V_132 = 0 ;
#ifdef F_96
V_131 = V_9 -> V_133 ;
#endif
V_132 = V_9 -> V_134 ;
F_95 ( V_9 , V_131 , 0 ) ;
F_133 ( V_9 , V_132 , 0 ) ;
#ifdef F_134
F_139 ( V_9 -> V_91 ) ;
#endif
}
static void * F_140 ( void )
{
struct V_9 * V_135 = V_136 -> V_137 -> V_138 ;
#ifdef F_141
if ( V_135 )
F_142 ( & V_135 -> V_139 ) ;
#endif
return V_135 ;
}
static const void * F_143 ( void )
{
return & V_140 ;
}
static const void * F_144 ( struct V_141 * V_142 )
{
return F_145 ( V_142 ) ;
}
static int F_146 ( struct V_5 * V_37 , struct V_143 * V_144 )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
int V_145 ;
V_145 = F_147 ( V_144 , L_13 , V_2 -> V_146 ) ;
if ( V_145 )
goto exit;
V_145 = F_147 ( V_144 , L_14 , V_2 -> V_147 ) ;
exit:
return V_145 ;
}
static void F_148 ( struct V_5 * V_37 )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
F_113 ( V_2 -> V_3 != V_148 ) ;
F_67 ( V_2 -> V_35 ) ;
F_67 ( ( char * ) V_2 - V_2 -> V_149 ) ;
}
static const void * F_149 ( struct V_5 * V_37 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_37 , struct V_1 , V_2 ) ;
return F_150 ( V_2 ) ;
}
void F_151 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_152 ( & V_2 -> V_48 ) ;
F_138 ( V_9 ) ;
F_153 ( V_2 ) ;
}
int F_154 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_150 * * V_151 = V_9 -> V_152 ;
int error = 0 ;
F_155 ( V_2 ) ;
V_2 -> V_153 = & V_154 ;
V_2 -> V_155 = V_9 ;
V_2 -> V_151 = V_151 ;
F_156 ( V_2 , L_15 , V_9 -> V_146 ) ;
#ifdef F_134
if ( * V_151 )
V_151 ++ ;
* V_151 ++ = & V_156 ;
#ifdef F_157
if ( V_9 -> V_157 )
* V_151 ++ = & V_158 ;
#ifdef F_158
else if ( V_9 -> V_159 )
* V_151 ++ = & V_158 ;
#endif
#endif
#endif
error = F_159 ( V_2 ) ;
if ( error )
return error ;
error = F_136 ( V_9 ) ;
if ( error ) {
F_153 ( V_2 ) ;
return error ;
}
return error ;
}
int F_160 ( struct V_160 * V_161 )
{
return F_161 ( & V_154 , V_161 ) ;
}
void F_162 ( struct V_160 * V_161 )
{
F_163 ( & V_154 , V_161 ) ;
}
int F_164 ( void )
{
F_165 ( & V_162 ) ;
return F_166 ( & V_154 ) ;
}
