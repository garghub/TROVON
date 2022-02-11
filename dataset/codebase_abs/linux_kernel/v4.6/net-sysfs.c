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
V_2 -> V_42 = V_41 ;
return 0 ;
}
static T_1 F_44 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_45 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_43 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned long V_43 )
{
V_2 -> V_44 = V_43 ;
return 0 ;
}
static T_1 F_47 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_45 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_46 ) ;
}
static T_1 F_48 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_15 * V_15 = F_9 ( V_14 ) ;
T_2 V_45 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_45 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_49 ( V_14 , V_8 , V_45 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_50 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_46 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_46 ) ;
F_14 () ;
return V_10 ;
}
static int F_51 ( struct V_1 * V_2 , unsigned long V_47 )
{
F_52 ( V_2 , ( int ) V_47 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_51 ) ;
}
static int F_54 ( struct V_1 * V_2 , unsigned long V_48 )
{
return F_55 ( V_2 , ( bool ) V_48 ) ;
}
static T_1 F_56 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_54 ) ;
}
static T_1 F_57 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_49 V_50 ;
V_10 = F_58 ( V_14 , & V_50 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_50 . V_51 , V_50 . V_52 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_59 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
char V_53 [ V_54 ] ;
V_10 = F_60 ( V_14 , V_53 , sizeof( V_53 ) ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_4 , V_53 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_61 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_55 V_7 = {
. V_56 = V_14 ,
. V_52 = V_57 ,
. V_58 = V_59 ,
} ;
V_10 = F_62 ( V_14 , & V_7 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_7 . V_60 . V_50 . V_51 ,
V_7 . V_60 . V_50 . V_52 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_63 ( const struct V_5 * V_61 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_62 )
{
struct V_1 * V_2 = F_4 ( V_61 ) ;
T_1 V_10 = - V_11 ;
F_64 ( V_62 > sizeof( struct V_63 ) ||
V_62 % sizeof( V_64 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_63 V_65 ;
const struct V_63 * V_66 = F_65 ( V_2 , & V_65 ) ;
V_10 = sprintf ( V_8 , V_67 , * ( V_64 * ) ( ( ( V_68 * ) V_66 ) + V_62 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_66 ( struct V_69 * V_70 , struct V_71 * V_7 ,
char * V_8 )
{
struct V_72 * V_71 = F_67 ( V_7 ) ;
struct V_73 * V_74 = F_68 ( V_70 ) ;
if ( ! V_71 -> V_75 )
return - V_76 ;
return V_71 -> V_75 ( V_74 , V_71 , V_8 ) ;
}
static T_1 F_69 ( struct V_69 * V_70 , struct V_71 * V_7 ,
const char * V_8 , T_2 V_45 )
{
struct V_72 * V_71 = F_67 ( V_7 ) ;
struct V_73 * V_74 = F_68 ( V_70 ) ;
if ( ! V_71 -> V_77 )
return - V_76 ;
return V_71 -> V_77 ( V_74 , V_71 , V_8 , V_45 ) ;
}
static T_1 F_70 ( struct V_73 * V_74 ,
struct V_72 * V_71 , char * V_8 )
{
struct V_78 * V_79 ;
T_3 V_80 ;
int V_81 , V_13 ;
if ( ! F_71 ( & V_80 , V_82 ) )
return - V_83 ;
F_72 () ;
V_79 = F_73 ( V_74 -> V_78 ) ;
if ( V_79 )
for ( V_81 = 0 ; V_81 < V_79 -> V_13 ; V_81 ++ )
F_74 ( V_79 -> V_84 [ V_81 ] , V_80 ) ;
V_13 = snprintf ( V_8 , V_85 , L_6 , F_75 ( V_80 ) ) ;
F_76 () ;
F_77 ( V_80 ) ;
return V_13 < V_85 ? V_13 : - V_11 ;
}
static T_1 F_78 ( struct V_73 * V_74 ,
struct V_72 * V_71 ,
const char * V_8 , T_2 V_13 )
{
struct V_78 * V_86 , * V_79 ;
T_3 V_80 ;
int V_20 , V_87 , V_81 ;
static F_79 ( V_88 ) ;
if ( ! F_45 ( V_18 ) )
return - V_19 ;
if ( ! F_80 ( & V_80 , V_82 ) )
return - V_83 ;
V_20 = F_81 ( V_8 , V_13 , F_82 ( V_80 ) , V_89 ) ;
if ( V_20 ) {
F_77 ( V_80 ) ;
return V_20 ;
}
V_79 = F_83 ( F_84 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_82 ) ;
if ( ! V_79 ) {
F_77 ( V_80 ) ;
return - V_83 ;
}
V_81 = 0 ;
F_85 (cpu, mask, cpu_online_mask)
V_79 -> V_84 [ V_81 ++ ] = V_87 ;
if ( V_81 )
V_79 -> V_13 = V_81 ;
else {
F_86 ( V_79 ) ;
V_79 = NULL ;
}
F_87 ( & V_88 ) ;
V_86 = F_88 ( V_74 -> V_78 ,
F_89 ( & V_88 ) ) ;
F_90 ( V_74 -> V_78 , V_79 ) ;
if ( V_79 )
F_91 ( & V_90 ) ;
if ( V_86 )
F_92 ( & V_90 ) ;
F_93 ( & V_88 ) ;
if ( V_86 )
F_94 ( V_86 , V_91 ) ;
F_77 ( V_80 ) ;
return V_13 ;
}
static T_1 F_95 ( struct V_73 * V_74 ,
struct V_72 * V_7 ,
char * V_8 )
{
struct V_92 * V_93 ;
unsigned long V_43 = 0 ;
F_72 () ;
V_93 = F_73 ( V_74 -> V_94 ) ;
if ( V_93 )
V_43 = ( unsigned long ) V_93 -> V_80 + 1 ;
F_76 () ;
return sprintf ( V_8 , L_7 , V_43 ) ;
}
static void F_96 ( struct V_95 * V_91 )
{
struct V_92 * V_96 = F_97 ( V_91 ,
struct V_92 , V_91 ) ;
F_98 ( V_96 ) ;
}
static T_1 F_99 ( struct V_73 * V_74 ,
struct V_72 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_80 , V_45 ;
struct V_92 * V_96 , * V_97 ;
static F_100 ( V_98 ) ;
int V_99 ;
if ( ! F_45 ( V_18 ) )
return - V_19 ;
V_99 = F_11 ( V_8 , 0 , & V_45 ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_45 ) {
V_80 = V_45 - 1 ;
while ( ( V_80 | ( V_80 >> 1 ) ) != V_80 )
V_80 |= ( V_80 >> 1 ) ;
#if V_100 > 32
if ( V_80 > ( unsigned long ) ( V_101 ) V_80 )
return - V_11 ;
#else
if ( V_80 > ( V_102 - F_101 ( 1 ) )
/ sizeof( struct V_103 ) ) {
return - V_11 ;
}
#endif
V_96 = F_102 ( F_101 ( V_80 + 1 ) ) ;
if ( ! V_96 )
return - V_83 ;
V_96 -> V_80 = V_80 ;
for ( V_45 = 0 ; V_45 <= V_80 ; V_45 ++ )
V_96 -> V_104 [ V_45 ] . V_87 = V_105 ;
} else
V_96 = NULL ;
F_103 ( & V_98 ) ;
V_97 = F_88 ( V_74 -> V_94 ,
F_104 ( & V_98 ) ) ;
F_90 ( V_74 -> V_94 , V_96 ) ;
F_105 ( & V_98 ) ;
if ( V_97 )
F_106 ( & V_97 -> V_91 , F_96 ) ;
return V_13 ;
}
static void F_107 ( struct V_69 * V_70 )
{
struct V_73 * V_74 = F_68 ( V_70 ) ;
#ifdef F_108
struct V_78 * V_79 ;
struct V_92 * V_93 ;
V_79 = F_88 ( V_74 -> V_78 , 1 ) ;
if ( V_79 ) {
F_109 ( V_74 -> V_78 , NULL ) ;
F_94 ( V_79 , V_91 ) ;
}
V_93 = F_88 ( V_74 -> V_94 , 1 ) ;
if ( V_93 ) {
F_109 ( V_74 -> V_94 , NULL ) ;
F_106 ( & V_93 -> V_91 , F_96 ) ;
}
#endif
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
F_110 ( V_74 -> V_2 ) ;
}
static const void * F_111 ( struct V_69 * V_70 )
{
struct V_73 * V_74 = F_68 ( V_70 ) ;
struct V_5 * V_2 = & V_74 -> V_2 -> V_2 ;
const void * V_106 = NULL ;
if ( V_2 -> V_107 && V_2 -> V_107 -> V_108 )
V_106 = V_2 -> V_107 -> V_109 ( V_2 ) ;
return V_106 ;
}
static int F_112 ( struct V_1 * V_2 , int V_110 )
{
struct V_73 * V_74 = V_2 -> V_111 + V_110 ;
struct V_69 * V_70 = & V_74 -> V_70 ;
int error = 0 ;
V_70 -> V_112 = V_2 -> V_113 ;
error = F_113 ( V_70 , & V_114 , NULL ,
L_8 , V_110 ) ;
if ( error )
goto exit;
if ( V_2 -> V_115 ) {
error = F_114 ( V_70 , V_2 -> V_115 ) ;
if ( error )
goto exit;
}
F_115 ( V_70 , V_116 ) ;
F_116 ( V_74 -> V_2 ) ;
return error ;
exit:
F_117 ( V_70 ) ;
return error ;
}
int
F_118 ( struct V_1 * V_2 , int V_117 , int V_118 )
{
#ifdef F_119
int V_81 ;
int error = 0 ;
#ifndef F_108
if ( ! V_2 -> V_115 )
return 0 ;
#endif
for ( V_81 = V_117 ; V_81 < V_118 ; V_81 ++ ) {
error = F_112 ( V_2 , V_81 ) ;
if ( error ) {
V_118 = V_117 ;
break;
}
}
while ( -- V_81 >= V_118 ) {
if ( V_2 -> V_115 )
F_120 ( & V_2 -> V_111 [ V_81 ] . V_70 ,
V_2 -> V_115 ) ;
F_117 ( & V_2 -> V_111 [ V_81 ] . V_70 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_121 ( struct V_69 * V_70 ,
struct V_71 * V_7 , char * V_8 )
{
struct V_119 * V_71 = F_122 ( V_7 ) ;
struct V_120 * V_74 = F_123 ( V_70 ) ;
if ( ! V_71 -> V_75 )
return - V_76 ;
return V_71 -> V_75 ( V_74 , V_71 , V_8 ) ;
}
static T_1 F_124 ( struct V_69 * V_70 ,
struct V_71 * V_7 ,
const char * V_8 , T_2 V_45 )
{
struct V_119 * V_71 = F_122 ( V_7 ) ;
struct V_120 * V_74 = F_123 ( V_70 ) ;
if ( ! V_71 -> V_77 )
return - V_76 ;
return V_71 -> V_77 ( V_74 , V_71 , V_8 , V_45 ) ;
}
static T_1 F_125 ( struct V_120 * V_74 ,
struct V_119 * V_71 ,
char * V_8 )
{
unsigned long V_121 ;
F_126 ( & V_74 -> V_122 ) ;
V_121 = V_74 -> V_121 ;
F_127 ( & V_74 -> V_122 ) ;
return sprintf ( V_8 , L_9 , V_121 ) ;
}
static unsigned int F_128 ( struct V_120 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
unsigned int V_81 ;
V_81 = V_74 - V_2 -> V_123 ;
F_129 ( V_81 >= V_2 -> V_124 ) ;
return V_81 ;
}
static T_1 F_130 ( struct V_120 * V_74 ,
struct V_119 * V_71 ,
char * V_8 )
{
return sprintf ( V_8 , L_7 , V_74 -> V_125 ) ;
}
static T_1 F_131 ( struct V_120 * V_74 ,
struct V_119 * V_71 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
int V_20 , V_110 = F_128 ( V_74 ) ;
V_101 V_126 = 0 ;
V_20 = F_132 ( V_8 , 10 , & V_126 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! F_12 () )
return F_13 () ;
V_20 = - V_127 ;
if ( V_2 -> V_128 -> V_129 )
V_20 = V_2 -> V_128 -> V_129 ( V_2 , V_110 , V_126 ) ;
F_14 () ;
if ( ! V_20 ) {
V_74 -> V_125 = V_126 ;
return V_13 ;
}
return V_20 ;
}
static T_1 F_133 ( char * V_8 , unsigned int V_130 )
{
return sprintf ( V_8 , L_10 , V_130 ) ;
}
static T_1 F_134 ( const char * V_8 , const T_2 V_45 ,
unsigned int * V_131 )
{
unsigned int V_130 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_130 = V_132 ;
else {
V_20 = F_135 ( V_8 , 10 , & V_130 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_130 > V_132 )
return - V_11 ;
}
* V_131 = V_130 ;
return V_45 ;
}
static T_1 F_136 ( struct V_120 * V_74 ,
struct V_119 * V_7 ,
char * V_8 )
{
struct V_133 * V_133 = & V_74 -> V_133 ;
return sprintf ( V_8 , L_10 , F_137 ( V_133 -> V_134 ) ) ;
}
static T_1 F_138 ( struct V_120 * V_74 ,
struct V_119 * V_71 ,
const char * V_8 , T_2 V_13 )
{
struct V_133 * V_133 = & V_74 -> V_133 ;
unsigned int V_130 ;
int V_20 ;
V_20 = F_135 ( V_8 , 10 , & V_130 ) ;
if ( V_20 < 0 )
return V_20 ;
V_133 -> V_134 = F_139 ( V_130 ) ;
return V_13 ;
}
static T_1 F_140 ( struct V_120 * V_74 ,
struct V_119 * V_7 ,
char * V_8 )
{
struct V_133 * V_133 = & V_74 -> V_133 ;
return sprintf ( V_8 , L_10 , V_133 -> V_135 - V_133 -> V_136 ) ;
}
static T_1 F_141 ( struct V_120 * V_74 ,
struct V_119 * V_71 , char * V_8 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
struct V_137 * V_138 ;
T_3 V_80 ;
unsigned long V_110 ;
int V_81 , V_13 ;
if ( ! F_71 ( & V_80 , V_82 ) )
return - V_83 ;
V_110 = F_128 ( V_74 ) ;
F_72 () ;
V_138 = F_73 ( V_2 -> V_139 ) ;
if ( V_138 ) {
F_142 (i) {
struct V_140 * V_79 =
F_73 ( V_138 -> V_141 [ V_81 ] ) ;
if ( V_79 ) {
int V_142 ;
for ( V_142 = 0 ; V_142 < V_79 -> V_13 ; V_142 ++ ) {
if ( V_79 -> V_143 [ V_142 ] == V_110 ) {
F_74 ( V_81 , V_80 ) ;
break;
}
}
}
}
}
F_76 () ;
V_13 = snprintf ( V_8 , V_85 , L_6 , F_75 ( V_80 ) ) ;
F_77 ( V_80 ) ;
return V_13 < V_85 ? V_13 : - V_11 ;
}
static T_1 F_143 ( struct V_120 * V_74 ,
struct V_119 * V_71 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_74 -> V_2 ;
unsigned long V_110 ;
T_3 V_80 ;
int V_20 ;
if ( ! F_45 ( V_18 ) )
return - V_19 ;
if ( ! F_80 ( & V_80 , V_82 ) )
return - V_83 ;
V_110 = F_128 ( V_74 ) ;
V_20 = F_81 ( V_8 , V_13 , F_82 ( V_80 ) , V_89 ) ;
if ( V_20 ) {
F_77 ( V_80 ) ;
return V_20 ;
}
V_20 = F_144 ( V_2 , V_80 , V_110 ) ;
F_77 ( V_80 ) ;
return V_20 ? : V_13 ;
}
static void F_145 ( struct V_69 * V_70 )
{
struct V_120 * V_74 = F_123 ( V_70 ) ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
F_110 ( V_74 -> V_2 ) ;
}
static const void * F_146 ( struct V_69 * V_70 )
{
struct V_120 * V_74 = F_123 ( V_70 ) ;
struct V_5 * V_2 = & V_74 -> V_2 -> V_2 ;
const void * V_106 = NULL ;
if ( V_2 -> V_107 && V_2 -> V_107 -> V_108 )
V_106 = V_2 -> V_107 -> V_109 ( V_2 ) ;
return V_106 ;
}
static int F_147 ( struct V_1 * V_2 , int V_110 )
{
struct V_120 * V_74 = V_2 -> V_123 + V_110 ;
struct V_69 * V_70 = & V_74 -> V_70 ;
int error = 0 ;
V_70 -> V_112 = V_2 -> V_113 ;
error = F_113 ( V_70 , & V_144 , NULL ,
L_13 , V_110 ) ;
if ( error )
goto exit;
#ifdef F_148
error = F_114 ( V_70 , & V_145 ) ;
if ( error )
goto exit;
#endif
F_115 ( V_70 , V_116 ) ;
F_116 ( V_74 -> V_2 ) ;
return 0 ;
exit:
F_117 ( V_70 ) ;
return error ;
}
int
F_149 ( struct V_1 * V_2 , int V_117 , int V_118 )
{
#ifdef F_119
int V_81 ;
int error = 0 ;
for ( V_81 = V_117 ; V_81 < V_118 ; V_81 ++ ) {
error = F_147 ( V_2 , V_81 ) ;
if ( error ) {
V_118 = V_117 ;
break;
}
}
while ( -- V_81 >= V_118 ) {
struct V_120 * V_74 = V_2 -> V_123 + V_81 ;
#ifdef F_148
F_120 ( & V_74 -> V_70 , & V_145 ) ;
#endif
F_117 ( & V_74 -> V_70 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_150 ( struct V_1 * V_2 )
{
int error = 0 , V_146 = 0 , V_147 = 0 , V_148 = 0 , V_149 = 0 ;
#ifdef F_119
V_2 -> V_113 = F_151 ( L_14 ,
NULL , & V_2 -> V_2 . V_70 ) ;
if ( ! V_2 -> V_113 )
return - V_83 ;
V_148 = V_2 -> V_150 ;
#endif
V_149 = V_2 -> V_151 ;
error = F_118 ( V_2 , 0 , V_148 ) ;
if ( error )
goto error;
V_147 = V_148 ;
error = F_149 ( V_2 , 0 , V_149 ) ;
if ( error )
goto error;
V_146 = V_149 ;
return 0 ;
error:
F_149 ( V_2 , V_146 , 0 ) ;
F_118 ( V_2 , V_147 , 0 ) ;
return error ;
}
static void F_152 ( struct V_1 * V_2 )
{
int V_148 = 0 , V_149 = 0 ;
#ifdef F_119
V_148 = V_2 -> V_150 ;
#endif
V_149 = V_2 -> V_151 ;
F_118 ( V_2 , V_148 , 0 ) ;
F_149 ( V_2 , V_149 , 0 ) ;
#ifdef F_119
F_153 ( V_2 -> V_113 ) ;
#endif
}
static bool F_154 ( void )
{
struct V_15 * V_15 = V_152 -> V_153 -> V_154 ;
return F_10 ( V_15 -> V_17 , V_155 ) ;
}
static void * F_155 ( void )
{
struct V_15 * V_106 = V_152 -> V_153 -> V_154 ;
#ifdef F_156
if ( V_106 )
F_157 ( & V_106 -> V_156 ) ;
#endif
return V_106 ;
}
static const void * F_158 ( void )
{
return & V_157 ;
}
static const void * F_159 ( struct V_158 * V_159 )
{
return F_160 ( V_159 ) ;
}
static int F_161 ( struct V_5 * V_61 , struct V_160 * V_161 )
{
struct V_1 * V_2 = F_4 ( V_61 ) ;
int V_162 ;
V_162 = F_162 ( V_161 , L_15 , V_2 -> V_53 ) ;
if ( V_162 )
goto exit;
V_162 = F_162 ( V_161 , L_16 , V_2 -> V_163 ) ;
exit:
return V_162 ;
}
static void F_163 ( struct V_5 * V_61 )
{
struct V_1 * V_2 = F_4 ( V_61 ) ;
F_129 ( V_2 -> V_3 != V_164 ) ;
F_86 ( V_2 -> V_46 ) ;
F_164 ( V_2 ) ;
}
static const void * F_165 ( struct V_5 * V_61 )
{
struct V_1 * V_2 = F_4 ( V_61 ) ;
return F_9 ( V_2 ) ;
}
static int F_166 ( struct V_5 * V_2 , const void * V_165 )
{
int V_10 = 0 ;
if ( V_2 -> V_166 )
V_10 = V_2 -> V_166 -> V_167 == V_165 ;
return V_10 == 0 ? V_2 -> V_167 == V_165 : V_10 ;
}
struct V_1 * F_167 ( struct V_168 * V_169 )
{
struct V_5 * V_2 ;
V_2 = F_168 ( & V_170 , NULL , V_169 , F_166 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
void F_169 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_170 ( & V_2 -> V_70 ) ;
F_152 ( V_9 ) ;
F_171 ( V_2 , false ) ;
F_172 ( V_2 ) ;
}
int F_173 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_171 * * V_172 = V_9 -> V_173 ;
int error = 0 ;
F_174 ( V_2 ) ;
V_2 -> V_107 = & V_170 ;
V_2 -> V_174 = V_9 ;
V_2 -> V_172 = V_172 ;
F_175 ( V_2 , L_17 , V_9 -> V_53 ) ;
#ifdef F_119
if ( * V_172 )
V_172 ++ ;
* V_172 ++ = & V_175 ;
#if F_176 ( V_176 ) || F_176 ( V_177 )
if ( V_9 -> V_178 )
* V_172 ++ = & V_179 ;
#if F_176 ( V_176 )
else if ( V_9 -> V_180 )
* V_172 ++ = & V_179 ;
#endif
#endif
#endif
error = F_177 ( V_2 ) ;
if ( error )
return error ;
error = F_150 ( V_9 ) ;
if ( error ) {
F_172 ( V_2 ) ;
return error ;
}
F_171 ( V_2 , true ) ;
return error ;
}
int F_178 ( struct V_181 * V_182 ,
const void * V_106 )
{
return F_179 ( & V_170 , V_182 , V_106 ) ;
}
void F_180 ( struct V_181 * V_182 ,
const void * V_106 )
{
F_181 ( & V_170 , V_182 , V_106 ) ;
}
int T_4 F_182 ( void )
{
F_183 ( & V_183 ) ;
return F_184 ( & V_170 ) ;
}
