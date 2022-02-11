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
if ( ( V_10 = (* F_8)( V_14 , V_16 ) ) == 0 )
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
if ( F_23 ( V_14 ) ) {
return sprintf ( V_8 , V_21 , ! ! F_27 ( V_14 ) ) ;
}
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
int V_42 , V_43 = V_2 -> V_44 ;
if ( V_41 != V_43 ) {
V_2 -> V_44 = V_41 ;
V_42 = F_44 ( V_45 , V_2 ) ;
V_42 = F_45 ( V_42 ) ;
if ( V_42 ) {
F_46 ( V_2 ,
L_5 ) ;
V_2 -> V_44 = V_43 ;
return - V_46 ;
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
static int F_49 ( struct V_1 * V_2 , unsigned long V_47 )
{
V_2 -> V_48 = V_47 ;
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
T_2 V_49 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_49 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_52 ( V_14 , V_8 , V_49 ) ;
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
if ( V_14 -> V_50 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_50 ) ;
F_14 () ;
return V_10 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned long V_51 )
{
F_55 ( V_2 , ( int ) V_51 ) ;
return 0 ;
}
static T_1 F_56 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_54 ) ;
}
static int F_57 ( struct V_1 * V_2 , unsigned long V_52 )
{
return F_58 ( V_2 , ( bool ) V_52 ) ;
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
struct V_53 V_54 ;
V_10 = F_61 ( V_14 , & V_54 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_6 , V_54 . V_55 , V_54 . V_56 ) ;
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
char V_57 [ V_58 ] ;
V_10 = F_63 ( V_14 , V_57 , sizeof( V_57 ) ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_4 , V_57 ) ;
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
struct V_59 V_7 = {
. V_60 = V_14 ,
. V_56 = V_61 ,
. V_62 = V_63 ,
} ;
V_10 = F_65 ( V_14 , & V_7 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_6 , V_7 . V_64 . V_54 . V_55 ,
V_7 . V_64 . V_54 . V_56 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_66 ( const struct V_5 * V_65 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_66 )
{
struct V_1 * V_2 = F_4 ( V_65 ) ;
T_1 V_10 = - V_11 ;
F_67 ( V_66 > sizeof( struct V_67 ) ||
V_66 % sizeof( V_68 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_67 V_69 ;
const struct V_67 * V_70 = F_68 ( V_2 , & V_69 ) ;
V_10 = sprintf ( V_8 , V_71 , * ( V_68 * ) ( ( ( V_72 * ) V_70 ) + V_66 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_69 ( struct V_73 * V_74 , struct V_75 * V_7 ,
char * V_8 )
{
struct V_76 * V_75 = F_70 ( V_7 ) ;
struct V_77 * V_78 = F_71 ( V_74 ) ;
if ( ! V_75 -> V_79 )
return - V_80 ;
return V_75 -> V_79 ( V_78 , V_75 , V_8 ) ;
}
static T_1 F_72 ( struct V_73 * V_74 , struct V_75 * V_7 ,
const char * V_8 , T_2 V_49 )
{
struct V_76 * V_75 = F_70 ( V_7 ) ;
struct V_77 * V_78 = F_71 ( V_74 ) ;
if ( ! V_75 -> V_81 )
return - V_80 ;
return V_75 -> V_81 ( V_78 , V_75 , V_8 , V_49 ) ;
}
static T_1 F_73 ( struct V_77 * V_78 ,
struct V_76 * V_75 , char * V_8 )
{
struct V_82 * V_83 ;
T_3 V_84 ;
int V_85 , V_13 ;
if ( ! F_74 ( & V_84 , V_86 ) )
return - V_87 ;
F_75 () ;
V_83 = F_76 ( V_78 -> V_82 ) ;
if ( V_83 )
for ( V_85 = 0 ; V_85 < V_83 -> V_13 ; V_85 ++ )
F_77 ( V_83 -> V_88 [ V_85 ] , V_84 ) ;
V_13 = snprintf ( V_8 , V_89 , L_7 , F_78 ( V_84 ) ) ;
F_79 () ;
F_80 ( V_84 ) ;
return V_13 < V_89 ? V_13 : - V_11 ;
}
static T_1 F_81 ( struct V_77 * V_78 ,
struct V_76 * V_75 ,
const char * V_8 , T_2 V_13 )
{
struct V_82 * V_90 , * V_83 ;
T_3 V_84 ;
int V_20 , V_91 , V_85 ;
static F_82 ( V_92 ) ;
if ( ! F_48 ( V_18 ) )
return - V_19 ;
if ( ! F_83 ( & V_84 , V_86 ) )
return - V_87 ;
V_20 = F_84 ( V_8 , V_13 , F_85 ( V_84 ) , V_93 ) ;
if ( V_20 ) {
F_80 ( V_84 ) ;
return V_20 ;
}
V_83 = F_86 ( F_87 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_86 ) ;
if ( ! V_83 ) {
F_80 ( V_84 ) ;
return - V_87 ;
}
V_85 = 0 ;
F_88 (cpu, mask, cpu_online_mask)
V_83 -> V_88 [ V_85 ++ ] = V_91 ;
if ( V_85 )
V_83 -> V_13 = V_85 ;
else {
F_89 ( V_83 ) ;
V_83 = NULL ;
}
F_90 ( & V_92 ) ;
V_90 = F_91 ( V_78 -> V_82 ,
F_92 ( & V_92 ) ) ;
F_93 ( V_78 -> V_82 , V_83 ) ;
if ( V_83 )
F_94 ( & V_94 ) ;
if ( V_90 )
F_95 ( & V_94 ) ;
F_96 ( & V_92 ) ;
if ( V_90 )
F_97 ( V_90 , V_95 ) ;
F_80 ( V_84 ) ;
return V_13 ;
}
static T_1 F_98 ( struct V_77 * V_78 ,
struct V_76 * V_7 ,
char * V_8 )
{
struct V_96 * V_97 ;
unsigned long V_47 = 0 ;
F_75 () ;
V_97 = F_76 ( V_78 -> V_98 ) ;
if ( V_97 )
V_47 = ( unsigned long ) V_97 -> V_84 + 1 ;
F_79 () ;
return sprintf ( V_8 , L_8 , V_47 ) ;
}
static void F_99 ( struct V_99 * V_95 )
{
struct V_96 * V_100 = F_100 ( V_95 ,
struct V_96 , V_95 ) ;
F_101 ( V_100 ) ;
}
static T_1 F_102 ( struct V_77 * V_78 ,
struct V_76 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_84 , V_49 ;
struct V_96 * V_100 , * V_101 ;
static F_103 ( V_102 ) ;
int V_103 ;
if ( ! F_48 ( V_18 ) )
return - V_19 ;
V_103 = F_11 ( V_8 , 0 , & V_49 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_49 ) {
V_84 = V_49 - 1 ;
while ( ( V_84 | ( V_84 >> 1 ) ) != V_84 )
V_84 |= ( V_84 >> 1 ) ;
#if V_104 > 32
if ( V_84 > ( unsigned long ) ( V_105 ) V_84 )
return - V_11 ;
#else
if ( V_84 > ( V_106 - F_104 ( 1 ) )
/ sizeof( struct V_107 ) ) {
return - V_11 ;
}
#endif
V_100 = F_105 ( F_104 ( V_84 + 1 ) ) ;
if ( ! V_100 )
return - V_87 ;
V_100 -> V_84 = V_84 ;
for ( V_49 = 0 ; V_49 <= V_84 ; V_49 ++ )
V_100 -> V_108 [ V_49 ] . V_91 = V_109 ;
} else
V_100 = NULL ;
F_106 ( & V_102 ) ;
V_101 = F_91 ( V_78 -> V_98 ,
F_107 ( & V_102 ) ) ;
F_93 ( V_78 -> V_98 , V_100 ) ;
F_108 ( & V_102 ) ;
if ( V_101 )
F_109 ( & V_101 -> V_95 , F_99 ) ;
return V_13 ;
}
static void F_110 ( struct V_73 * V_74 )
{
struct V_77 * V_78 = F_71 ( V_74 ) ;
#ifdef F_111
struct V_82 * V_83 ;
struct V_96 * V_97 ;
V_83 = F_91 ( V_78 -> V_82 , 1 ) ;
if ( V_83 ) {
F_112 ( V_78 -> V_82 , NULL ) ;
F_97 ( V_83 , V_95 ) ;
}
V_97 = F_91 ( V_78 -> V_98 , 1 ) ;
if ( V_97 ) {
F_112 ( V_78 -> V_98 , NULL ) ;
F_109 ( & V_97 -> V_95 , F_99 ) ;
}
#endif
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
F_113 ( V_78 -> V_2 ) ;
}
static const void * F_114 ( struct V_73 * V_74 )
{
struct V_77 * V_78 = F_71 ( V_74 ) ;
struct V_5 * V_2 = & V_78 -> V_2 -> V_2 ;
const void * V_110 = NULL ;
if ( V_2 -> V_111 && V_2 -> V_111 -> V_112 )
V_110 = V_2 -> V_111 -> V_113 ( V_2 ) ;
return V_110 ;
}
static int F_115 ( struct V_1 * V_2 , int V_114 )
{
struct V_77 * V_78 = V_2 -> V_115 + V_114 ;
struct V_73 * V_74 = & V_78 -> V_74 ;
int error = 0 ;
V_74 -> V_116 = V_2 -> V_117 ;
error = F_116 ( V_74 , & V_118 , NULL ,
L_9 , V_114 ) ;
if ( error )
goto exit;
if ( V_2 -> V_119 ) {
error = F_117 ( V_74 , V_2 -> V_119 ) ;
if ( error )
goto exit;
}
F_118 ( V_74 , V_120 ) ;
F_119 ( V_78 -> V_2 ) ;
return error ;
exit:
F_120 ( V_74 ) ;
return error ;
}
int
F_121 ( struct V_1 * V_2 , int V_121 , int V_122 )
{
#ifdef F_122
int V_85 ;
int error = 0 ;
#ifndef F_111
if ( ! V_2 -> V_119 )
return 0 ;
#endif
for ( V_85 = V_121 ; V_85 < V_122 ; V_85 ++ ) {
error = F_115 ( V_2 , V_85 ) ;
if ( error ) {
V_122 = V_121 ;
break;
}
}
while ( -- V_85 >= V_122 ) {
struct V_73 * V_74 = & V_2 -> V_115 [ V_85 ] . V_74 ;
if ( ! F_123 ( & F_9 ( V_2 ) -> V_123 ) )
V_74 -> V_124 = 1 ;
if ( V_2 -> V_119 )
F_124 ( V_74 , V_2 -> V_119 ) ;
F_120 ( V_74 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_125 ( struct V_73 * V_74 ,
struct V_75 * V_7 , char * V_8 )
{
struct V_125 * V_75 = F_126 ( V_7 ) ;
struct V_126 * V_78 = F_127 ( V_74 ) ;
if ( ! V_75 -> V_79 )
return - V_80 ;
return V_75 -> V_79 ( V_78 , V_75 , V_8 ) ;
}
static T_1 F_128 ( struct V_73 * V_74 ,
struct V_75 * V_7 ,
const char * V_8 , T_2 V_49 )
{
struct V_125 * V_75 = F_126 ( V_7 ) ;
struct V_126 * V_78 = F_127 ( V_74 ) ;
if ( ! V_75 -> V_81 )
return - V_80 ;
return V_75 -> V_81 ( V_78 , V_75 , V_8 , V_49 ) ;
}
static T_1 F_129 ( struct V_126 * V_78 ,
struct V_125 * V_75 ,
char * V_8 )
{
unsigned long V_127 ;
F_130 ( & V_78 -> V_128 ) ;
V_127 = V_78 -> V_127 ;
F_131 ( & V_78 -> V_128 ) ;
return sprintf ( V_8 , L_10 , V_127 ) ;
}
static unsigned int F_132 ( struct V_126 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
unsigned int V_85 ;
V_85 = V_78 - V_2 -> V_129 ;
F_133 ( V_85 >= V_2 -> V_130 ) ;
return V_85 ;
}
static T_1 F_134 ( struct V_126 * V_78 ,
struct V_125 * V_75 ,
char * V_8 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_114 = F_132 ( V_78 ) ;
int V_131 = F_135 ( V_2 , V_114 ) ;
if ( V_131 < 0 )
return - V_11 ;
return sprintf ( V_8 , L_11 , V_131 ) ;
}
static T_1 F_136 ( struct V_126 * V_78 ,
struct V_125 * V_75 ,
char * V_8 )
{
return sprintf ( V_8 , L_8 , V_78 -> V_132 ) ;
}
static T_1 F_137 ( struct V_126 * V_78 ,
struct V_125 * V_75 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_20 , V_114 = F_132 ( V_78 ) ;
V_105 V_133 = 0 ;
V_20 = F_138 ( V_8 , 10 , & V_133 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! F_12 () )
return F_13 () ;
V_20 = - V_134 ;
if ( V_2 -> V_135 -> V_136 )
V_20 = V_2 -> V_135 -> V_136 ( V_2 , V_114 , V_133 ) ;
F_14 () ;
if ( ! V_20 ) {
V_78 -> V_132 = V_133 ;
return V_13 ;
}
return V_20 ;
}
static T_1 F_139 ( char * V_8 , unsigned int V_137 )
{
return sprintf ( V_8 , L_11 , V_137 ) ;
}
static T_1 F_140 ( const char * V_8 , const T_2 V_49 ,
unsigned int * V_138 )
{
unsigned int V_137 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_12 ) || ! strcmp ( V_8 , L_13 ) )
V_137 = V_139 ;
else {
V_20 = F_141 ( V_8 , 10 , & V_137 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_137 > V_139 )
return - V_11 ;
}
* V_138 = V_137 ;
return V_49 ;
}
static T_1 F_142 ( struct V_126 * V_78 ,
struct V_125 * V_7 ,
char * V_8 )
{
struct V_140 * V_140 = & V_78 -> V_140 ;
return sprintf ( V_8 , L_11 , F_143 ( V_140 -> V_141 ) ) ;
}
static T_1 F_144 ( struct V_126 * V_78 ,
struct V_125 * V_75 ,
const char * V_8 , T_2 V_13 )
{
struct V_140 * V_140 = & V_78 -> V_140 ;
unsigned int V_137 ;
int V_20 ;
V_20 = F_141 ( V_8 , 10 , & V_137 ) ;
if ( V_20 < 0 )
return V_20 ;
V_140 -> V_141 = F_145 ( V_137 ) ;
return V_13 ;
}
static T_1 F_146 ( struct V_126 * V_78 ,
struct V_125 * V_7 ,
char * V_8 )
{
struct V_140 * V_140 = & V_78 -> V_140 ;
return sprintf ( V_8 , L_11 , V_140 -> V_142 - V_140 -> V_143 ) ;
}
static T_1 F_147 ( struct V_126 * V_78 ,
struct V_125 * V_75 , char * V_8 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_91 , V_13 , V_144 = 1 , V_131 = 0 ;
struct V_145 * V_146 ;
T_3 V_84 ;
unsigned long V_114 ;
if ( ! F_74 ( & V_84 , V_86 ) )
return - V_87 ;
V_114 = F_132 ( V_78 ) ;
if ( V_2 -> V_144 ) {
V_144 = V_2 -> V_144 ;
V_131 = F_135 ( V_2 , V_114 ) ;
if ( V_131 < 0 )
return - V_11 ;
}
F_75 () ;
V_146 = F_76 ( V_2 -> V_147 ) ;
if ( V_146 ) {
F_148 (cpu) {
int V_85 , V_148 = V_91 * V_144 + V_131 ;
struct V_149 * V_83 ;
V_83 = F_76 ( V_146 -> V_150 [ V_148 ] ) ;
if ( ! V_83 )
continue;
for ( V_85 = V_83 -> V_13 ; V_85 -- ; ) {
if ( V_83 -> V_151 [ V_85 ] == V_114 ) {
F_77 ( V_91 , V_84 ) ;
break;
}
}
}
}
F_79 () ;
V_13 = snprintf ( V_8 , V_89 , L_7 , F_78 ( V_84 ) ) ;
F_80 ( V_84 ) ;
return V_13 < V_89 ? V_13 : - V_11 ;
}
static T_1 F_149 ( struct V_126 * V_78 ,
struct V_125 * V_75 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
unsigned long V_114 ;
T_3 V_84 ;
int V_20 ;
if ( ! F_48 ( V_18 ) )
return - V_19 ;
if ( ! F_83 ( & V_84 , V_86 ) )
return - V_87 ;
V_114 = F_132 ( V_78 ) ;
V_20 = F_84 ( V_8 , V_13 , F_85 ( V_84 ) , V_93 ) ;
if ( V_20 ) {
F_80 ( V_84 ) ;
return V_20 ;
}
V_20 = F_150 ( V_2 , V_84 , V_114 ) ;
F_80 ( V_84 ) ;
return V_20 ? : V_13 ;
}
static void F_151 ( struct V_73 * V_74 )
{
struct V_126 * V_78 = F_127 ( V_74 ) ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
F_113 ( V_78 -> V_2 ) ;
}
static const void * F_152 ( struct V_73 * V_74 )
{
struct V_126 * V_78 = F_127 ( V_74 ) ;
struct V_5 * V_2 = & V_78 -> V_2 -> V_2 ;
const void * V_110 = NULL ;
if ( V_2 -> V_111 && V_2 -> V_111 -> V_112 )
V_110 = V_2 -> V_111 -> V_113 ( V_2 ) ;
return V_110 ;
}
static int F_153 ( struct V_1 * V_2 , int V_114 )
{
struct V_126 * V_78 = V_2 -> V_129 + V_114 ;
struct V_73 * V_74 = & V_78 -> V_74 ;
int error = 0 ;
V_74 -> V_116 = V_2 -> V_117 ;
error = F_116 ( V_74 , & V_152 , NULL ,
L_14 , V_114 ) ;
if ( error )
goto exit;
#ifdef F_154
error = F_117 ( V_74 , & V_153 ) ;
if ( error )
goto exit;
#endif
F_118 ( V_74 , V_120 ) ;
F_119 ( V_78 -> V_2 ) ;
return 0 ;
exit:
F_120 ( V_74 ) ;
return error ;
}
int
F_155 ( struct V_1 * V_2 , int V_121 , int V_122 )
{
#ifdef F_122
int V_85 ;
int error = 0 ;
for ( V_85 = V_121 ; V_85 < V_122 ; V_85 ++ ) {
error = F_153 ( V_2 , V_85 ) ;
if ( error ) {
V_122 = V_121 ;
break;
}
}
while ( -- V_85 >= V_122 ) {
struct V_126 * V_78 = V_2 -> V_129 + V_85 ;
if ( ! F_123 ( & F_9 ( V_2 ) -> V_123 ) )
V_78 -> V_74 . V_124 = 1 ;
#ifdef F_154
F_124 ( & V_78 -> V_74 , & V_153 ) ;
#endif
F_120 ( & V_78 -> V_74 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_156 ( struct V_1 * V_2 )
{
int error = 0 , V_154 = 0 , V_155 = 0 , V_156 = 0 , V_157 = 0 ;
#ifdef F_122
V_2 -> V_117 = F_157 ( L_15 ,
NULL , & V_2 -> V_2 . V_74 ) ;
if ( ! V_2 -> V_117 )
return - V_87 ;
V_156 = V_2 -> V_158 ;
#endif
V_157 = V_2 -> V_159 ;
error = F_121 ( V_2 , 0 , V_156 ) ;
if ( error )
goto error;
V_155 = V_156 ;
error = F_155 ( V_2 , 0 , V_157 ) ;
if ( error )
goto error;
V_154 = V_157 ;
return 0 ;
error:
F_155 ( V_2 , V_154 , 0 ) ;
F_121 ( V_2 , V_155 , 0 ) ;
return error ;
}
static void F_158 ( struct V_1 * V_2 )
{
int V_156 = 0 , V_157 = 0 ;
#ifdef F_122
V_156 = V_2 -> V_158 ;
#endif
V_157 = V_2 -> V_159 ;
F_121 ( V_2 , V_156 , 0 ) ;
F_155 ( V_2 , V_157 , 0 ) ;
#ifdef F_122
F_159 ( V_2 -> V_117 ) ;
#endif
}
static bool F_160 ( void )
{
struct V_15 * V_15 = V_160 -> V_161 -> V_162 ;
return F_10 ( V_15 -> V_17 , V_163 ) ;
}
static void * F_161 ( void )
{
struct V_15 * V_110 = V_160 -> V_161 -> V_162 ;
#ifdef F_162
if ( V_110 )
F_163 ( & V_110 -> V_164 ) ;
#endif
return V_110 ;
}
static const void * F_164 ( void )
{
return & V_165 ;
}
static const void * F_165 ( struct V_166 * V_167 )
{
return F_166 ( V_167 ) ;
}
static int F_167 ( struct V_5 * V_65 , struct V_168 * V_169 )
{
struct V_1 * V_2 = F_4 ( V_65 ) ;
int V_170 ;
V_170 = F_168 ( V_169 , L_16 , V_2 -> V_57 ) ;
if ( V_170 )
goto exit;
V_170 = F_168 ( V_169 , L_17 , V_2 -> V_171 ) ;
exit:
return V_170 ;
}
static void F_169 ( struct V_5 * V_65 )
{
struct V_1 * V_2 = F_4 ( V_65 ) ;
F_133 ( V_2 -> V_3 != V_172 ) ;
F_89 ( V_2 -> V_50 ) ;
F_170 ( V_2 ) ;
}
static const void * F_171 ( struct V_5 * V_65 )
{
struct V_1 * V_2 = F_4 ( V_65 ) ;
return F_9 ( V_2 ) ;
}
static int F_172 ( struct V_5 * V_2 , const void * V_173 )
{
int V_10 = 0 ;
if ( V_2 -> V_174 )
V_10 = V_2 -> V_174 -> V_175 == V_173 ;
return V_10 == 0 ? V_2 -> V_175 == V_173 : V_10 ;
}
struct V_1 * F_173 ( struct V_176 * V_177 )
{
struct V_5 * V_2 ;
V_2 = F_174 ( & V_178 , NULL , V_177 , F_172 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
void F_175 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
if ( ! F_123 ( & F_9 ( V_9 ) -> V_123 ) )
F_176 ( V_2 , 1 ) ;
F_177 ( & V_2 -> V_74 ) ;
F_158 ( V_9 ) ;
F_178 ( V_2 , false ) ;
F_179 ( V_2 ) ;
}
int F_180 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_179 * * V_180 = V_9 -> V_181 ;
int error = 0 ;
F_181 ( V_2 ) ;
V_2 -> V_111 = & V_178 ;
V_2 -> V_182 = V_9 ;
V_2 -> V_180 = V_180 ;
F_182 ( V_2 , L_18 , V_9 -> V_57 ) ;
#ifdef F_122
if ( * V_180 )
V_180 ++ ;
* V_180 ++ = & V_183 ;
#if F_183 ( V_184 ) || F_183 ( V_185 )
if ( V_9 -> V_186 )
* V_180 ++ = & V_187 ;
#if F_183 ( V_184 )
else if ( V_9 -> V_188 )
* V_180 ++ = & V_187 ;
#endif
#endif
#endif
error = F_184 ( V_2 ) ;
if ( error )
return error ;
error = F_156 ( V_9 ) ;
if ( error ) {
F_179 ( V_2 ) ;
return error ;
}
F_178 ( V_2 , true ) ;
return error ;
}
int F_185 ( struct V_189 * V_190 ,
const void * V_110 )
{
return F_186 ( & V_178 , V_190 , V_110 ) ;
}
void F_187 ( struct V_189 * V_190 ,
const void * V_110 )
{
F_188 ( & V_178 , V_190 , V_110 ) ;
}
int T_4 F_189 ( void )
{
F_190 ( & V_191 ) ;
return F_191 ( & V_178 ) ;
}
