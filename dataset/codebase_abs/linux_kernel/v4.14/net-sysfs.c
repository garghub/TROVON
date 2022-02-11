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
struct V_15 * V_15 = F_9 ( V_14 ) ;
unsigned long V_16 ;
int V_10 = - V_11 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
V_10 = F_11 ( V_8 , 0 , & V_16 ) ;
if ( V_10 )
goto V_20;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
V_10 = (* F_8)( V_14 , V_16 ) ;
if ( V_10 == 0 )
V_10 = V_13 ;
}
F_14 () ;
V_20:
return V_10 ;
}
static T_1 F_15 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
return sprintf ( V_8 , V_21 , F_16 ( V_9 ) ) ;
}
static T_1 F_17 ( const struct V_1 * V_2 , char * V_8 )
{
return sprintf ( V_8 , V_21 , V_2 -> V_22 ) ;
}
static T_1 F_18 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( V_9 -> V_22 != V_23 )
V_10 = F_2 ( V_2 , V_7 , V_8 , F_17 ) ;
return V_10 ;
}
static T_1 F_19 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = F_20 ( V_8 , V_9 -> V_24 , V_9 -> V_25 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_21 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
if ( F_1 ( V_9 ) )
return F_20 ( V_8 , V_9 -> V_26 , V_9 -> V_25 ) ;
return - V_11 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_27 )
{
if ( ! F_23 ( V_2 ) )
return - V_11 ;
return F_24 ( V_2 , ( bool ) V_27 ) ;
}
static T_1 F_25 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_22 ) ;
}
static T_1 F_26 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_23 ( V_14 ) )
return sprintf ( V_8 , V_21 , ! ! F_27 ( V_14 ) ) ;
return - V_11 ;
}
static T_1 F_28 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_23 ( V_14 ) ) {
struct V_28 V_29 ;
if ( ! F_29 ( V_14 , & V_29 ) )
V_10 = sprintf ( V_8 , V_21 , V_29 . V_30 . V_31 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_30 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_23 ( V_14 ) ) {
struct V_28 V_29 ;
if ( ! F_29 ( V_14 , & V_29 ) ) {
const char * V_32 ;
switch ( V_29 . V_30 . V_32 ) {
case V_33 :
V_32 = L_1 ;
break;
case V_34 :
V_32 = L_2 ;
break;
default:
V_32 = L_3 ;
break;
}
V_10 = sprintf ( V_8 , L_4 , V_32 ) ;
}
}
F_14 () ;
return V_10 ;
}
static T_1 F_31 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_23 ( V_14 ) )
return sprintf ( V_8 , V_21 , ! ! F_32 ( V_14 ) ) ;
return - V_11 ;
}
static T_1 F_33 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
unsigned char V_35 ;
F_5 ( & V_12 ) ;
V_35 = V_14 -> V_35 ;
if ( ! F_23 ( V_14 ) )
V_35 = V_36 ;
F_6 ( & V_12 ) ;
if ( V_35 >= F_34 ( V_37 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_37 [ V_35 ] ) ;
}
static T_1 F_35 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
return sprintf ( V_8 , V_21 ,
F_36 ( & V_14 -> V_38 ) ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned long V_39 )
{
return F_38 ( V_2 , ( int ) V_39 ) ;
}
static T_1 F_39 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_37 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned long V_40 )
{
return F_41 ( V_2 , ( unsigned int ) V_40 ) ;
}
static T_1 F_42 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_40 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned long V_41 )
{
unsigned int V_42 = V_2 -> V_43 ;
int V_44 ;
if ( V_41 != ( unsigned int ) V_41 )
return - V_45 ;
if ( V_41 != V_42 ) {
V_2 -> V_43 = V_41 ;
V_44 = F_44 ( V_46 , V_2 ) ;
V_44 = F_45 ( V_44 ) ;
if ( V_44 ) {
F_46 ( V_2 ,
L_5 ) ;
V_2 -> V_43 = V_42 ;
return - V_47 ;
}
}
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_48 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_43 ) ;
}
static int F_49 ( struct V_1 * V_2 , unsigned long V_48 )
{
V_2 -> V_49 = V_48 ;
return 0 ;
}
static T_1 F_50 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_48 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_49 ) ;
}
static T_1 F_51 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_15 * V_15 = F_9 ( V_14 ) ;
T_2 V_50 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_50 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_52 ( V_14 , V_8 , V_50 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_53 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_51 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_51 ) ;
F_14 () ;
return V_10 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned long V_52 )
{
F_55 ( V_2 , ( int ) V_52 ) ;
return 0 ;
}
static T_1 F_56 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_54 ) ;
}
static int F_57 ( struct V_1 * V_2 , unsigned long V_53 )
{
return F_58 ( V_2 , ( bool ) V_53 ) ;
}
static T_1 F_59 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_57 ) ;
}
static T_1 F_60 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_54 V_55 ;
V_10 = F_61 ( V_14 , & V_55 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_6 , V_55 . V_56 , V_55 . V_57 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_62 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
char V_58 [ V_59 ] ;
V_10 = F_63 ( V_14 , V_58 , sizeof( V_58 ) ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_4 , V_58 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_64 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_60 V_7 = {
. V_61 = V_14 ,
. V_57 = V_62 ,
. V_63 = V_64 ,
} ;
V_10 = F_65 ( V_14 , & V_7 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_6 , V_7 . V_65 . V_55 . V_56 ,
V_7 . V_65 . V_55 . V_57 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_66 ( const struct V_5 * V_66 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_67 )
{
struct V_1 * V_2 = F_4 ( V_66 ) ;
T_1 V_10 = - V_11 ;
F_67 ( V_67 > sizeof( struct V_68 ) ||
V_67 % sizeof( V_69 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_68 V_70 ;
const struct V_68 * V_71 = F_68 ( V_2 , & V_70 ) ;
V_10 = sprintf ( V_8 , V_72 , * ( V_69 * ) ( ( ( V_73 * ) V_71 ) + V_67 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_69 ( struct V_74 * V_75 , struct V_76 * V_7 ,
char * V_8 )
{
const struct V_77 * V_76 = F_70 ( V_7 ) ;
struct V_78 * V_79 = F_71 ( V_75 ) ;
if ( ! V_76 -> V_80 )
return - V_81 ;
return V_76 -> V_80 ( V_79 , V_8 ) ;
}
static T_1 F_72 ( struct V_74 * V_75 , struct V_76 * V_7 ,
const char * V_8 , T_2 V_50 )
{
const struct V_77 * V_76 = F_70 ( V_7 ) ;
struct V_78 * V_79 = F_71 ( V_75 ) ;
if ( ! V_76 -> V_82 )
return - V_81 ;
return V_76 -> V_82 ( V_79 , V_8 , V_50 ) ;
}
static T_1 F_73 ( struct V_78 * V_79 , char * V_8 )
{
struct V_83 * V_84 ;
T_3 V_85 ;
int V_86 , V_13 ;
if ( ! F_74 ( & V_85 , V_87 ) )
return - V_88 ;
F_75 () ;
V_84 = F_76 ( V_79 -> V_83 ) ;
if ( V_84 )
for ( V_86 = 0 ; V_86 < V_84 -> V_13 ; V_86 ++ )
F_77 ( V_84 -> V_89 [ V_86 ] , V_85 ) ;
V_13 = snprintf ( V_8 , V_90 , L_7 , F_78 ( V_85 ) ) ;
F_79 () ;
F_80 ( V_85 ) ;
return V_13 < V_90 ? V_13 : - V_11 ;
}
static T_1 F_81 ( struct V_78 * V_79 ,
const char * V_8 , T_2 V_13 )
{
struct V_83 * V_91 , * V_84 ;
T_3 V_85 ;
int V_20 , V_92 , V_86 ;
static F_82 ( V_93 ) ;
if ( ! F_48 ( V_18 ) )
return - V_19 ;
if ( ! F_83 ( & V_85 , V_87 ) )
return - V_88 ;
V_20 = F_84 ( V_8 , V_13 , F_85 ( V_85 ) , V_94 ) ;
if ( V_20 ) {
F_80 ( V_85 ) ;
return V_20 ;
}
V_84 = F_86 ( F_87 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_87 ) ;
if ( ! V_84 ) {
F_80 ( V_85 ) ;
return - V_88 ;
}
V_86 = 0 ;
F_88 (cpu, mask, cpu_online_mask)
V_84 -> V_89 [ V_86 ++ ] = V_92 ;
if ( V_86 ) {
V_84 -> V_13 = V_86 ;
} else {
F_89 ( V_84 ) ;
V_84 = NULL ;
}
F_90 ( & V_93 ) ;
V_91 = F_91 ( V_79 -> V_83 ,
F_92 ( & V_93 ) ) ;
F_93 ( V_79 -> V_83 , V_84 ) ;
if ( V_84 )
F_94 ( & V_95 ) ;
if ( V_91 )
F_95 ( & V_95 ) ;
F_96 ( & V_93 ) ;
if ( V_91 )
F_97 ( V_91 , V_96 ) ;
F_80 ( V_85 ) ;
return V_13 ;
}
static T_1 F_98 ( struct V_78 * V_79 ,
char * V_8 )
{
struct V_97 * V_98 ;
unsigned long V_48 = 0 ;
F_75 () ;
V_98 = F_76 ( V_79 -> V_99 ) ;
if ( V_98 )
V_48 = ( unsigned long ) V_98 -> V_85 + 1 ;
F_79 () ;
return sprintf ( V_8 , L_8 , V_48 ) ;
}
static void F_99 ( struct V_100 * V_96 )
{
struct V_97 * V_101 = F_100 ( V_96 ,
struct V_97 , V_96 ) ;
F_101 ( V_101 ) ;
}
static T_1 F_102 ( struct V_78 * V_79 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_85 , V_50 ;
struct V_97 * V_101 , * V_102 ;
static F_103 ( V_103 ) ;
int V_104 ;
if ( ! F_48 ( V_18 ) )
return - V_19 ;
V_104 = F_11 ( V_8 , 0 , & V_50 ) ;
if ( V_104 < 0 )
return V_104 ;
if ( V_50 ) {
V_85 = V_50 - 1 ;
while ( ( V_85 | ( V_85 >> 1 ) ) != V_85 )
V_85 |= ( V_85 >> 1 ) ;
#if V_105 > 32
if ( V_85 > ( unsigned long ) ( V_106 ) V_85 )
return - V_11 ;
#else
if ( V_85 > ( V_107 - F_104 ( 1 ) )
/ sizeof( struct V_108 ) ) {
return - V_11 ;
}
#endif
V_101 = F_105 ( F_104 ( V_85 + 1 ) ) ;
if ( ! V_101 )
return - V_88 ;
V_101 -> V_85 = V_85 ;
for ( V_50 = 0 ; V_50 <= V_85 ; V_50 ++ )
V_101 -> V_109 [ V_50 ] . V_92 = V_110 ;
} else {
V_101 = NULL ;
}
F_106 ( & V_103 ) ;
V_102 = F_91 ( V_79 -> V_99 ,
F_107 ( & V_103 ) ) ;
F_93 ( V_79 -> V_99 , V_101 ) ;
F_108 ( & V_103 ) ;
if ( V_102 )
F_109 ( & V_102 -> V_96 , F_99 ) ;
return V_13 ;
}
static void F_110 ( struct V_74 * V_75 )
{
struct V_78 * V_79 = F_71 ( V_75 ) ;
#ifdef F_111
struct V_83 * V_84 ;
struct V_97 * V_98 ;
V_84 = F_91 ( V_79 -> V_83 , 1 ) ;
if ( V_84 ) {
F_112 ( V_79 -> V_83 , NULL ) ;
F_97 ( V_84 , V_96 ) ;
}
V_98 = F_91 ( V_79 -> V_99 , 1 ) ;
if ( V_98 ) {
F_112 ( V_79 -> V_99 , NULL ) ;
F_109 ( & V_98 -> V_96 , F_99 ) ;
}
#endif
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
F_113 ( V_79 -> V_2 ) ;
}
static const void * F_114 ( struct V_74 * V_75 )
{
struct V_78 * V_79 = F_71 ( V_75 ) ;
struct V_5 * V_2 = & V_79 -> V_2 -> V_2 ;
const void * V_111 = NULL ;
if ( V_2 -> V_112 && V_2 -> V_112 -> V_113 )
V_111 = V_2 -> V_112 -> V_114 ( V_2 ) ;
return V_111 ;
}
static int F_115 ( struct V_1 * V_2 , int V_115 )
{
struct V_78 * V_79 = V_2 -> V_116 + V_115 ;
struct V_74 * V_75 = & V_79 -> V_75 ;
int error = 0 ;
V_75 -> V_117 = V_2 -> V_118 ;
error = F_116 ( V_75 , & V_119 , NULL ,
L_9 , V_115 ) ;
if ( error )
return error ;
if ( V_2 -> V_120 ) {
error = F_117 ( V_75 , V_2 -> V_120 ) ;
if ( error ) {
F_118 ( V_75 ) ;
return error ;
}
}
F_119 ( V_75 , V_121 ) ;
F_120 ( V_79 -> V_2 ) ;
return error ;
}
int
F_121 ( struct V_1 * V_2 , int V_122 , int V_123 )
{
#ifdef F_122
int V_86 ;
int error = 0 ;
#ifndef F_111
if ( ! V_2 -> V_120 )
return 0 ;
#endif
for ( V_86 = V_122 ; V_86 < V_123 ; V_86 ++ ) {
error = F_115 ( V_2 , V_86 ) ;
if ( error ) {
V_123 = V_122 ;
break;
}
}
while ( -- V_86 >= V_123 ) {
struct V_74 * V_75 = & V_2 -> V_116 [ V_86 ] . V_75 ;
if ( ! F_36 ( & F_9 ( V_2 ) -> V_50 ) )
V_75 -> V_124 = 1 ;
if ( V_2 -> V_120 )
F_123 ( V_75 , V_2 -> V_120 ) ;
F_118 ( V_75 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_124 ( struct V_74 * V_75 ,
struct V_76 * V_7 , char * V_8 )
{
const struct V_125 * V_76
= F_125 ( V_7 ) ;
struct V_126 * V_79 = F_126 ( V_75 ) ;
if ( ! V_76 -> V_80 )
return - V_81 ;
return V_76 -> V_80 ( V_79 , V_8 ) ;
}
static T_1 F_127 ( struct V_74 * V_75 ,
struct V_76 * V_7 ,
const char * V_8 , T_2 V_50 )
{
const struct V_125 * V_76
= F_125 ( V_7 ) ;
struct V_126 * V_79 = F_126 ( V_75 ) ;
if ( ! V_76 -> V_82 )
return - V_81 ;
return V_76 -> V_82 ( V_79 , V_8 , V_50 ) ;
}
static T_1 F_128 ( struct V_126 * V_79 , char * V_8 )
{
unsigned long V_127 ;
F_129 ( & V_79 -> V_128 ) ;
V_127 = V_79 -> V_127 ;
F_130 ( & V_79 -> V_128 ) ;
return sprintf ( V_8 , L_10 , V_127 ) ;
}
static unsigned int F_131 ( struct V_126 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
unsigned int V_86 ;
V_86 = V_79 - V_2 -> V_129 ;
F_132 ( V_86 >= V_2 -> V_130 ) ;
return V_86 ;
}
static T_1 F_133 ( struct V_126 * V_79 ,
char * V_8 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
int V_115 = F_131 ( V_79 ) ;
int V_131 = F_134 ( V_2 , V_115 ) ;
if ( V_131 < 0 )
return - V_11 ;
return sprintf ( V_8 , L_11 , V_131 ) ;
}
static T_1 F_135 ( struct V_126 * V_79 ,
char * V_8 )
{
return sprintf ( V_8 , L_8 , V_79 -> V_132 ) ;
}
static T_1 F_136 ( struct V_126 * V_79 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
int V_20 , V_115 = F_131 ( V_79 ) ;
V_106 V_133 = 0 ;
V_20 = F_137 ( V_8 , 10 , & V_133 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! F_12 () )
return F_13 () ;
V_20 = - V_134 ;
if ( V_2 -> V_135 -> V_136 )
V_20 = V_2 -> V_135 -> V_136 ( V_2 , V_115 , V_133 ) ;
F_14 () ;
if ( ! V_20 ) {
V_79 -> V_132 = V_133 ;
return V_13 ;
}
return V_20 ;
}
static T_1 F_138 ( char * V_8 , unsigned int V_137 )
{
return sprintf ( V_8 , L_11 , V_137 ) ;
}
static T_1 F_139 ( const char * V_8 , const T_2 V_50 ,
unsigned int * V_138 )
{
unsigned int V_137 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_12 ) || ! strcmp ( V_8 , L_13 ) ) {
V_137 = V_139 ;
} else {
V_20 = F_140 ( V_8 , 10 , & V_137 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_137 > V_139 )
return - V_11 ;
}
* V_138 = V_137 ;
return V_50 ;
}
static T_1 F_141 ( struct V_126 * V_79 ,
char * V_8 )
{
struct V_140 * V_140 = & V_79 -> V_140 ;
return sprintf ( V_8 , L_11 , F_142 ( V_140 -> V_141 ) ) ;
}
static T_1 F_143 ( struct V_126 * V_79 ,
const char * V_8 , T_2 V_13 )
{
struct V_140 * V_140 = & V_79 -> V_140 ;
unsigned int V_137 ;
int V_20 ;
V_20 = F_140 ( V_8 , 10 , & V_137 ) ;
if ( V_20 < 0 )
return V_20 ;
V_140 -> V_141 = F_144 ( V_137 ) ;
return V_13 ;
}
static T_1 F_145 ( struct V_126 * V_79 ,
char * V_8 )
{
struct V_140 * V_140 = & V_79 -> V_140 ;
return sprintf ( V_8 , L_11 , V_140 -> V_142 - V_140 -> V_143 ) ;
}
static T_1 F_146 ( struct V_126 * V_79 ,
char * V_8 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
int V_92 , V_13 , V_144 = 1 , V_131 = 0 ;
struct V_145 * V_146 ;
T_3 V_85 ;
unsigned long V_115 ;
if ( ! F_74 ( & V_85 , V_87 ) )
return - V_88 ;
V_115 = F_131 ( V_79 ) ;
if ( V_2 -> V_144 ) {
V_144 = V_2 -> V_144 ;
V_131 = F_134 ( V_2 , V_115 ) ;
if ( V_131 < 0 )
return - V_11 ;
}
F_75 () ;
V_146 = F_76 ( V_2 -> V_147 ) ;
if ( V_146 ) {
F_147 (cpu) {
int V_86 , V_148 = V_92 * V_144 + V_131 ;
struct V_149 * V_84 ;
V_84 = F_76 ( V_146 -> V_150 [ V_148 ] ) ;
if ( ! V_84 )
continue;
for ( V_86 = V_84 -> V_13 ; V_86 -- ; ) {
if ( V_84 -> V_151 [ V_86 ] == V_115 ) {
F_77 ( V_92 , V_85 ) ;
break;
}
}
}
}
F_79 () ;
V_13 = snprintf ( V_8 , V_90 , L_7 , F_78 ( V_85 ) ) ;
F_80 ( V_85 ) ;
return V_13 < V_90 ? V_13 : - V_11 ;
}
static T_1 F_148 ( struct V_126 * V_79 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_79 -> V_2 ;
unsigned long V_115 ;
T_3 V_85 ;
int V_20 ;
if ( ! F_48 ( V_18 ) )
return - V_19 ;
if ( ! F_83 ( & V_85 , V_87 ) )
return - V_88 ;
V_115 = F_131 ( V_79 ) ;
V_20 = F_84 ( V_8 , V_13 , F_85 ( V_85 ) , V_94 ) ;
if ( V_20 ) {
F_80 ( V_85 ) ;
return V_20 ;
}
V_20 = F_149 ( V_2 , V_85 , V_115 ) ;
F_80 ( V_85 ) ;
return V_20 ? : V_13 ;
}
static void F_150 ( struct V_74 * V_75 )
{
struct V_126 * V_79 = F_126 ( V_75 ) ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
F_113 ( V_79 -> V_2 ) ;
}
static const void * F_151 ( struct V_74 * V_75 )
{
struct V_126 * V_79 = F_126 ( V_75 ) ;
struct V_5 * V_2 = & V_79 -> V_2 -> V_2 ;
const void * V_111 = NULL ;
if ( V_2 -> V_112 && V_2 -> V_112 -> V_113 )
V_111 = V_2 -> V_112 -> V_114 ( V_2 ) ;
return V_111 ;
}
static int F_152 ( struct V_1 * V_2 , int V_115 )
{
struct V_126 * V_79 = V_2 -> V_129 + V_115 ;
struct V_74 * V_75 = & V_79 -> V_75 ;
int error = 0 ;
V_75 -> V_117 = V_2 -> V_118 ;
error = F_116 ( V_75 , & V_152 , NULL ,
L_14 , V_115 ) ;
if ( error )
return error ;
#ifdef F_153
error = F_117 ( V_75 , & V_153 ) ;
if ( error ) {
F_118 ( V_75 ) ;
return error ;
}
#endif
F_119 ( V_75 , V_121 ) ;
F_120 ( V_79 -> V_2 ) ;
return 0 ;
}
int
F_154 ( struct V_1 * V_2 , int V_122 , int V_123 )
{
#ifdef F_122
int V_86 ;
int error = 0 ;
for ( V_86 = V_122 ; V_86 < V_123 ; V_86 ++ ) {
error = F_152 ( V_2 , V_86 ) ;
if ( error ) {
V_123 = V_122 ;
break;
}
}
while ( -- V_86 >= V_123 ) {
struct V_126 * V_79 = V_2 -> V_129 + V_86 ;
if ( ! F_36 ( & F_9 ( V_2 ) -> V_50 ) )
V_79 -> V_75 . V_124 = 1 ;
#ifdef F_153
F_123 ( & V_79 -> V_75 , & V_153 ) ;
#endif
F_118 ( & V_79 -> V_75 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_155 ( struct V_1 * V_2 )
{
int error = 0 , V_154 = 0 , V_155 = 0 , V_156 = 0 , V_157 = 0 ;
#ifdef F_122
V_2 -> V_118 = F_156 ( L_15 ,
NULL , & V_2 -> V_2 . V_75 ) ;
if ( ! V_2 -> V_118 )
return - V_88 ;
V_156 = V_2 -> V_158 ;
#endif
V_157 = V_2 -> V_159 ;
error = F_121 ( V_2 , 0 , V_156 ) ;
if ( error )
goto error;
V_155 = V_156 ;
error = F_154 ( V_2 , 0 , V_157 ) ;
if ( error )
goto error;
V_154 = V_157 ;
return 0 ;
error:
F_154 ( V_2 , V_154 , 0 ) ;
F_121 ( V_2 , V_155 , 0 ) ;
return error ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_156 = 0 , V_157 = 0 ;
#ifdef F_122
V_156 = V_2 -> V_158 ;
#endif
V_157 = V_2 -> V_159 ;
F_121 ( V_2 , V_156 , 0 ) ;
F_154 ( V_2 , V_157 , 0 ) ;
#ifdef F_122
F_158 ( V_2 -> V_118 ) ;
#endif
}
static bool F_159 ( void )
{
struct V_15 * V_15 = V_160 -> V_161 -> V_162 ;
return F_10 ( V_15 -> V_17 , V_163 ) ;
}
static void * F_160 ( void )
{
struct V_15 * V_111 = V_160 -> V_161 -> V_162 ;
#ifdef F_161
if ( V_111 )
F_162 ( & V_111 -> V_164 ) ;
#endif
return V_111 ;
}
static const void * F_163 ( void )
{
return & V_165 ;
}
static const void * F_164 ( struct V_166 * V_167 )
{
return F_165 ( V_167 ) ;
}
static int F_166 ( struct V_5 * V_66 , struct V_168 * V_169 )
{
struct V_1 * V_2 = F_4 ( V_66 ) ;
int V_170 ;
V_170 = F_167 ( V_169 , L_16 , V_2 -> V_58 ) ;
if ( V_170 )
goto exit;
V_170 = F_167 ( V_169 , L_17 , V_2 -> V_171 ) ;
exit:
return V_170 ;
}
static void F_168 ( struct V_5 * V_66 )
{
struct V_1 * V_2 = F_4 ( V_66 ) ;
F_132 ( V_2 -> V_3 != V_172 ) ;
F_89 ( V_2 -> V_51 ) ;
F_169 ( V_2 ) ;
}
static const void * F_170 ( struct V_5 * V_66 )
{
struct V_1 * V_2 = F_4 ( V_66 ) ;
return F_9 ( V_2 ) ;
}
static int F_171 ( struct V_5 * V_2 , const void * V_173 )
{
int V_10 = 0 ;
if ( V_2 -> V_174 )
V_10 = V_2 -> V_174 -> V_175 == V_173 ;
return V_10 == 0 ? V_2 -> V_175 == V_173 : V_10 ;
}
struct V_1 * F_172 ( struct V_176 * V_177 )
{
struct V_5 * V_2 ;
V_2 = F_173 ( & V_178 , NULL , V_177 , F_171 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
void F_174 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & V_9 -> V_2 ;
if ( ! F_36 ( & F_9 ( V_9 ) -> V_50 ) )
F_175 ( V_2 , 1 ) ;
F_176 ( & V_2 -> V_75 ) ;
F_157 ( V_9 ) ;
F_177 ( V_2 , false ) ;
F_178 ( V_2 ) ;
}
int F_179 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & V_9 -> V_2 ;
const struct V_179 * * V_180 = V_9 -> V_181 ;
int error = 0 ;
F_180 ( V_2 ) ;
V_2 -> V_112 = & V_178 ;
V_2 -> V_182 = V_9 ;
V_2 -> V_180 = V_180 ;
F_181 ( V_2 , L_18 , V_9 -> V_58 ) ;
#ifdef F_122
if ( * V_180 )
V_180 ++ ;
* V_180 ++ = & V_183 ;
#if F_182 ( V_184 ) || F_182 ( V_185 )
if ( V_9 -> V_186 )
* V_180 ++ = & V_187 ;
#if F_182 ( V_184 )
else if ( V_9 -> V_188 )
* V_180 ++ = & V_187 ;
#endif
#endif
#endif
error = F_183 ( V_2 ) ;
if ( error )
return error ;
error = F_155 ( V_9 ) ;
if ( error ) {
F_178 ( V_2 ) ;
return error ;
}
F_177 ( V_2 , true ) ;
return error ;
}
int F_184 ( const struct V_189 * V_190 ,
const void * V_111 )
{
return F_185 ( & V_178 , V_190 , V_111 ) ;
}
void F_186 ( const struct V_189 * V_190 ,
const void * V_111 )
{
F_187 ( & V_178 , V_190 , V_111 ) ;
}
int T_4 F_188 ( void )
{
F_189 ( & V_191 ) ;
return F_190 ( & V_178 ) ;
}
