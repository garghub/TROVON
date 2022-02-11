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
V_10 = sprintf ( V_8 , V_21 , F_30 ( & V_29 ) ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_31 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_23 ( V_14 ) ) {
struct V_28 V_29 ;
if ( ! F_29 ( V_14 , & V_29 ) ) {
const char * V_30 ;
switch ( V_29 . V_30 ) {
case V_31 :
V_30 = L_1 ;
break;
case V_32 :
V_30 = L_2 ;
break;
default:
V_30 = L_3 ;
break;
}
V_10 = sprintf ( V_8 , L_4 , V_30 ) ;
}
}
F_14 () ;
return V_10 ;
}
static T_1 F_32 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_23 ( V_14 ) )
return sprintf ( V_8 , V_21 , ! ! F_33 ( V_14 ) ) ;
return - V_11 ;
}
static T_1 F_34 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
unsigned char V_33 ;
F_5 ( & V_12 ) ;
V_33 = V_14 -> V_33 ;
if ( ! F_23 ( V_14 ) )
V_33 = V_34 ;
F_6 ( & V_12 ) ;
if ( V_33 >= F_35 ( V_35 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_35 [ V_33 ] ) ;
}
static T_1 F_36 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
return sprintf ( V_8 , V_21 ,
F_37 ( & V_14 -> V_36 ) ) ;
}
static int F_38 ( struct V_1 * V_2 , unsigned long V_37 )
{
return F_39 ( V_2 , ( int ) V_37 ) ;
}
static T_1 F_40 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_38 ) ;
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_38 )
{
return F_42 ( V_2 , ( unsigned int ) V_38 ) ;
}
static T_1 F_43 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_41 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned long V_39 )
{
V_2 -> V_40 = V_39 ;
return 0 ;
}
static T_1 F_45 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_46 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_44 ) ;
}
static int F_47 ( struct V_1 * V_2 , unsigned long V_41 )
{
V_2 -> V_42 = V_41 ;
return 0 ;
}
static T_1 F_48 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_46 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_47 ) ;
}
static T_1 F_49 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_15 * V_15 = F_9 ( V_14 ) ;
T_2 V_43 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_43 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_50 ( V_14 , V_8 , V_43 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_51 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_44 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_44 ) ;
F_14 () ;
return V_10 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned long V_45 )
{
F_53 ( V_2 , ( int ) V_45 ) ;
return 0 ;
}
static T_1 F_54 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_52 ) ;
}
static int F_55 ( struct V_1 * V_2 , unsigned long V_46 )
{
return F_56 ( V_2 , ( bool ) V_46 ) ;
}
static T_1 F_57 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_55 ) ;
}
static T_1 F_58 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_47 V_48 ;
V_10 = F_59 ( V_14 , & V_48 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_48 . V_49 , V_48 . V_50 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_60 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
char V_51 [ V_52 ] ;
V_10 = F_61 ( V_14 , V_51 , sizeof( V_51 ) ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_4 , V_51 ) ;
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
struct V_53 V_7 = {
. V_54 = V_14 ,
. V_50 = V_55 ,
. V_56 = V_57 ,
} ;
V_10 = F_63 ( V_14 , & V_7 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_7 . V_58 . V_48 . V_49 ,
V_7 . V_58 . V_48 . V_50 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_64 ( const struct V_5 * V_59 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_60 )
{
struct V_1 * V_2 = F_4 ( V_59 ) ;
T_1 V_10 = - V_11 ;
F_65 ( V_60 > sizeof( struct V_61 ) ||
V_60 % sizeof( V_62 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_61 V_63 ;
const struct V_61 * V_64 = F_66 ( V_2 , & V_63 ) ;
V_10 = sprintf ( V_8 , V_65 , * ( V_62 * ) ( ( ( V_66 * ) V_64 ) + V_60 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_67 ( struct V_67 * V_68 , struct V_69 * V_7 ,
char * V_8 )
{
struct V_70 * V_69 = F_68 ( V_7 ) ;
struct V_71 * V_72 = F_69 ( V_68 ) ;
if ( ! V_69 -> V_73 )
return - V_74 ;
return V_69 -> V_73 ( V_72 , V_69 , V_8 ) ;
}
static T_1 F_70 ( struct V_67 * V_68 , struct V_69 * V_7 ,
const char * V_8 , T_2 V_43 )
{
struct V_70 * V_69 = F_68 ( V_7 ) ;
struct V_71 * V_72 = F_69 ( V_68 ) ;
if ( ! V_69 -> V_75 )
return - V_74 ;
return V_69 -> V_75 ( V_72 , V_69 , V_8 , V_43 ) ;
}
static T_1 F_71 ( struct V_71 * V_72 ,
struct V_70 * V_69 , char * V_8 )
{
struct V_76 * V_77 ;
T_3 V_78 ;
int V_79 , V_13 ;
if ( ! F_72 ( & V_78 , V_80 ) )
return - V_81 ;
F_73 () ;
V_77 = F_74 ( V_72 -> V_76 ) ;
if ( V_77 )
for ( V_79 = 0 ; V_79 < V_77 -> V_13 ; V_79 ++ )
F_75 ( V_77 -> V_82 [ V_79 ] , V_78 ) ;
V_13 = snprintf ( V_8 , V_83 , L_6 , F_76 ( V_78 ) ) ;
F_77 () ;
F_78 ( V_78 ) ;
return V_13 < V_83 ? V_13 : - V_11 ;
}
static T_1 F_79 ( struct V_71 * V_72 ,
struct V_70 * V_69 ,
const char * V_8 , T_2 V_13 )
{
struct V_76 * V_84 , * V_77 ;
T_3 V_78 ;
int V_20 , V_85 , V_79 ;
static F_80 ( V_86 ) ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
if ( ! F_81 ( & V_78 , V_80 ) )
return - V_81 ;
V_20 = F_82 ( V_8 , V_13 , F_83 ( V_78 ) , V_87 ) ;
if ( V_20 ) {
F_78 ( V_78 ) ;
return V_20 ;
}
V_77 = F_84 ( F_85 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_80 ) ;
if ( ! V_77 ) {
F_78 ( V_78 ) ;
return - V_81 ;
}
V_79 = 0 ;
F_86 (cpu, mask, cpu_online_mask)
V_77 -> V_82 [ V_79 ++ ] = V_85 ;
if ( V_79 )
V_77 -> V_13 = V_79 ;
else {
F_87 ( V_77 ) ;
V_77 = NULL ;
}
F_88 ( & V_86 ) ;
V_84 = F_89 ( V_72 -> V_76 ,
F_90 ( & V_86 ) ) ;
F_91 ( V_72 -> V_76 , V_77 ) ;
if ( V_77 )
F_92 ( & V_88 ) ;
if ( V_84 )
F_93 ( & V_88 ) ;
F_94 ( & V_86 ) ;
if ( V_84 )
F_95 ( V_84 , V_89 ) ;
F_78 ( V_78 ) ;
return V_13 ;
}
static T_1 F_96 ( struct V_71 * V_72 ,
struct V_70 * V_7 ,
char * V_8 )
{
struct V_90 * V_91 ;
unsigned long V_41 = 0 ;
F_73 () ;
V_91 = F_74 ( V_72 -> V_92 ) ;
if ( V_91 )
V_41 = ( unsigned long ) V_91 -> V_78 + 1 ;
F_77 () ;
return sprintf ( V_8 , L_7 , V_41 ) ;
}
static void F_97 ( struct V_93 * V_89 )
{
struct V_90 * V_94 = F_98 ( V_89 ,
struct V_90 , V_89 ) ;
F_99 ( V_94 ) ;
}
static T_1 F_100 ( struct V_71 * V_72 ,
struct V_70 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_78 , V_43 ;
struct V_90 * V_94 , * V_95 ;
static F_101 ( V_96 ) ;
int V_97 ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
V_97 = F_11 ( V_8 , 0 , & V_43 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( V_43 ) {
V_78 = V_43 - 1 ;
while ( ( V_78 | ( V_78 >> 1 ) ) != V_78 )
V_78 |= ( V_78 >> 1 ) ;
#if V_98 > 32
if ( V_78 > ( unsigned long ) ( V_99 ) V_78 )
return - V_11 ;
#else
if ( V_78 > ( V_100 - F_102 ( 1 ) )
/ sizeof( struct V_101 ) ) {
return - V_11 ;
}
#endif
V_94 = F_103 ( F_102 ( V_78 + 1 ) ) ;
if ( ! V_94 )
return - V_81 ;
V_94 -> V_78 = V_78 ;
for ( V_43 = 0 ; V_43 <= V_78 ; V_43 ++ )
V_94 -> V_102 [ V_43 ] . V_85 = V_103 ;
} else
V_94 = NULL ;
F_104 ( & V_96 ) ;
V_95 = F_89 ( V_72 -> V_92 ,
F_105 ( & V_96 ) ) ;
F_91 ( V_72 -> V_92 , V_94 ) ;
F_106 ( & V_96 ) ;
if ( V_95 )
F_107 ( & V_95 -> V_89 , F_97 ) ;
return V_13 ;
}
static void F_108 ( struct V_67 * V_68 )
{
struct V_71 * V_72 = F_69 ( V_68 ) ;
#ifdef F_109
struct V_76 * V_77 ;
struct V_90 * V_91 ;
V_77 = F_89 ( V_72 -> V_76 , 1 ) ;
if ( V_77 ) {
F_110 ( V_72 -> V_76 , NULL ) ;
F_95 ( V_77 , V_89 ) ;
}
V_91 = F_89 ( V_72 -> V_92 , 1 ) ;
if ( V_91 ) {
F_110 ( V_72 -> V_92 , NULL ) ;
F_107 ( & V_91 -> V_89 , F_97 ) ;
}
#endif
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
F_111 ( V_72 -> V_2 ) ;
}
static const void * F_112 ( struct V_67 * V_68 )
{
struct V_71 * V_72 = F_69 ( V_68 ) ;
struct V_5 * V_2 = & V_72 -> V_2 -> V_2 ;
const void * V_104 = NULL ;
if ( V_2 -> V_105 && V_2 -> V_105 -> V_106 )
V_104 = V_2 -> V_105 -> V_107 ( V_2 ) ;
return V_104 ;
}
static int F_113 ( struct V_1 * V_2 , int V_108 )
{
struct V_71 * V_72 = V_2 -> V_109 + V_108 ;
struct V_67 * V_68 = & V_72 -> V_68 ;
int error = 0 ;
V_68 -> V_110 = V_2 -> V_111 ;
error = F_114 ( V_68 , & V_112 , NULL ,
L_8 , V_108 ) ;
if ( error )
goto exit;
if ( V_2 -> V_113 ) {
error = F_115 ( V_68 , V_2 -> V_113 ) ;
if ( error )
goto exit;
}
F_116 ( V_68 , V_114 ) ;
F_117 ( V_72 -> V_2 ) ;
return error ;
exit:
F_118 ( V_68 ) ;
return error ;
}
int
F_119 ( struct V_1 * V_2 , int V_115 , int V_116 )
{
#ifdef F_120
int V_79 ;
int error = 0 ;
#ifndef F_109
if ( ! V_2 -> V_113 )
return 0 ;
#endif
for ( V_79 = V_115 ; V_79 < V_116 ; V_79 ++ ) {
error = F_113 ( V_2 , V_79 ) ;
if ( error ) {
V_116 = V_115 ;
break;
}
}
while ( -- V_79 >= V_116 ) {
if ( V_2 -> V_113 )
F_121 ( & V_2 -> V_109 [ V_79 ] . V_68 ,
V_2 -> V_113 ) ;
F_118 ( & V_2 -> V_109 [ V_79 ] . V_68 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_122 ( struct V_67 * V_68 ,
struct V_69 * V_7 , char * V_8 )
{
struct V_117 * V_69 = F_123 ( V_7 ) ;
struct V_118 * V_72 = F_124 ( V_68 ) ;
if ( ! V_69 -> V_73 )
return - V_74 ;
return V_69 -> V_73 ( V_72 , V_69 , V_8 ) ;
}
static T_1 F_125 ( struct V_67 * V_68 ,
struct V_69 * V_7 ,
const char * V_8 , T_2 V_43 )
{
struct V_117 * V_69 = F_123 ( V_7 ) ;
struct V_118 * V_72 = F_124 ( V_68 ) ;
if ( ! V_69 -> V_75 )
return - V_74 ;
return V_69 -> V_75 ( V_72 , V_69 , V_8 , V_43 ) ;
}
static T_1 F_126 ( struct V_118 * V_72 ,
struct V_117 * V_69 ,
char * V_8 )
{
unsigned long V_119 ;
F_127 ( & V_72 -> V_120 ) ;
V_119 = V_72 -> V_119 ;
F_128 ( & V_72 -> V_120 ) ;
return sprintf ( V_8 , L_9 , V_119 ) ;
}
static unsigned int F_129 ( struct V_118 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned int V_79 ;
V_79 = V_72 - V_2 -> V_121 ;
F_130 ( V_79 >= V_2 -> V_122 ) ;
return V_79 ;
}
static T_1 F_131 ( struct V_118 * V_72 ,
struct V_117 * V_69 ,
char * V_8 )
{
return sprintf ( V_8 , L_7 , V_72 -> V_123 ) ;
}
static T_1 F_132 ( struct V_118 * V_72 ,
struct V_117 * V_69 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
int V_20 , V_108 = F_129 ( V_72 ) ;
V_99 V_124 = 0 ;
V_20 = F_133 ( V_8 , 10 , & V_124 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! F_12 () )
return F_13 () ;
V_20 = - V_125 ;
if ( V_2 -> V_126 -> V_127 )
V_20 = V_2 -> V_126 -> V_127 ( V_2 , V_108 , V_124 ) ;
F_14 () ;
if ( ! V_20 ) {
V_72 -> V_123 = V_124 ;
return V_13 ;
}
return V_20 ;
}
static T_1 F_134 ( char * V_8 , unsigned int V_128 )
{
return sprintf ( V_8 , L_10 , V_128 ) ;
}
static T_1 F_135 ( const char * V_8 , const T_2 V_43 ,
unsigned int * V_129 )
{
unsigned int V_128 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_128 = V_130 ;
else {
V_20 = F_136 ( V_8 , 10 , & V_128 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_128 > V_130 )
return - V_11 ;
}
* V_129 = V_128 ;
return V_43 ;
}
static T_1 F_137 ( struct V_118 * V_72 ,
struct V_117 * V_7 ,
char * V_8 )
{
struct V_131 * V_131 = & V_72 -> V_131 ;
return sprintf ( V_8 , L_10 , F_138 ( V_131 -> V_132 ) ) ;
}
static T_1 F_139 ( struct V_118 * V_72 ,
struct V_117 * V_69 ,
const char * V_8 , T_2 V_13 )
{
struct V_131 * V_131 = & V_72 -> V_131 ;
unsigned int V_128 ;
int V_20 ;
V_20 = F_136 ( V_8 , 10 , & V_128 ) ;
if ( V_20 < 0 )
return V_20 ;
V_131 -> V_132 = F_140 ( V_128 ) ;
return V_13 ;
}
static T_1 F_141 ( struct V_118 * V_72 ,
struct V_117 * V_7 ,
char * V_8 )
{
struct V_131 * V_131 = & V_72 -> V_131 ;
return sprintf ( V_8 , L_10 , V_131 -> V_133 - V_131 -> V_134 ) ;
}
static T_1 F_142 ( struct V_118 * V_72 ,
struct V_117 * V_69 , char * V_8 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
struct V_135 * V_136 ;
T_3 V_78 ;
unsigned long V_108 ;
int V_79 , V_13 ;
if ( ! F_72 ( & V_78 , V_80 ) )
return - V_81 ;
V_108 = F_129 ( V_72 ) ;
F_73 () ;
V_136 = F_74 ( V_2 -> V_137 ) ;
if ( V_136 ) {
F_143 (i) {
struct V_138 * V_77 =
F_74 ( V_136 -> V_139 [ V_79 ] ) ;
if ( V_77 ) {
int V_140 ;
for ( V_140 = 0 ; V_140 < V_77 -> V_13 ; V_140 ++ ) {
if ( V_77 -> V_141 [ V_140 ] == V_108 ) {
F_75 ( V_79 , V_78 ) ;
break;
}
}
}
}
}
F_77 () ;
V_13 = snprintf ( V_8 , V_83 , L_6 , F_76 ( V_78 ) ) ;
F_78 ( V_78 ) ;
return V_13 < V_83 ? V_13 : - V_11 ;
}
static T_1 F_144 ( struct V_118 * V_72 ,
struct V_117 * V_69 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
unsigned long V_108 ;
T_3 V_78 ;
int V_20 ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
if ( ! F_81 ( & V_78 , V_80 ) )
return - V_81 ;
V_108 = F_129 ( V_72 ) ;
V_20 = F_82 ( V_8 , V_13 , F_83 ( V_78 ) , V_87 ) ;
if ( V_20 ) {
F_78 ( V_78 ) ;
return V_20 ;
}
V_20 = F_145 ( V_2 , V_78 , V_108 ) ;
F_78 ( V_78 ) ;
return V_20 ? : V_13 ;
}
static void F_146 ( struct V_67 * V_68 )
{
struct V_118 * V_72 = F_124 ( V_68 ) ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
F_111 ( V_72 -> V_2 ) ;
}
static const void * F_147 ( struct V_67 * V_68 )
{
struct V_118 * V_72 = F_124 ( V_68 ) ;
struct V_5 * V_2 = & V_72 -> V_2 -> V_2 ;
const void * V_104 = NULL ;
if ( V_2 -> V_105 && V_2 -> V_105 -> V_106 )
V_104 = V_2 -> V_105 -> V_107 ( V_2 ) ;
return V_104 ;
}
static int F_148 ( struct V_1 * V_2 , int V_108 )
{
struct V_118 * V_72 = V_2 -> V_121 + V_108 ;
struct V_67 * V_68 = & V_72 -> V_68 ;
int error = 0 ;
V_68 -> V_110 = V_2 -> V_111 ;
error = F_114 ( V_68 , & V_142 , NULL ,
L_13 , V_108 ) ;
if ( error )
goto exit;
#ifdef F_149
error = F_115 ( V_68 , & V_143 ) ;
if ( error )
goto exit;
#endif
F_116 ( V_68 , V_114 ) ;
F_117 ( V_72 -> V_2 ) ;
return 0 ;
exit:
F_118 ( V_68 ) ;
return error ;
}
int
F_150 ( struct V_1 * V_2 , int V_115 , int V_116 )
{
#ifdef F_120
int V_79 ;
int error = 0 ;
for ( V_79 = V_115 ; V_79 < V_116 ; V_79 ++ ) {
error = F_148 ( V_2 , V_79 ) ;
if ( error ) {
V_116 = V_115 ;
break;
}
}
while ( -- V_79 >= V_116 ) {
struct V_118 * V_72 = V_2 -> V_121 + V_79 ;
#ifdef F_149
F_121 ( & V_72 -> V_68 , & V_143 ) ;
#endif
F_118 ( & V_72 -> V_68 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_151 ( struct V_1 * V_2 )
{
int error = 0 , V_144 = 0 , V_145 = 0 , V_146 = 0 , V_147 = 0 ;
#ifdef F_120
V_2 -> V_111 = F_152 ( L_14 ,
NULL , & V_2 -> V_2 . V_68 ) ;
if ( ! V_2 -> V_111 )
return - V_81 ;
V_146 = V_2 -> V_148 ;
#endif
V_147 = V_2 -> V_149 ;
error = F_119 ( V_2 , 0 , V_146 ) ;
if ( error )
goto error;
V_145 = V_146 ;
error = F_150 ( V_2 , 0 , V_147 ) ;
if ( error )
goto error;
V_144 = V_147 ;
return 0 ;
error:
F_150 ( V_2 , V_144 , 0 ) ;
F_119 ( V_2 , V_145 , 0 ) ;
return error ;
}
static void F_153 ( struct V_1 * V_2 )
{
int V_146 = 0 , V_147 = 0 ;
#ifdef F_120
V_146 = V_2 -> V_148 ;
#endif
V_147 = V_2 -> V_149 ;
F_119 ( V_2 , V_146 , 0 ) ;
F_150 ( V_2 , V_147 , 0 ) ;
#ifdef F_120
F_154 ( V_2 -> V_111 ) ;
#endif
}
static bool F_155 ( void )
{
struct V_15 * V_15 = V_150 -> V_151 -> V_152 ;
return F_10 ( V_15 -> V_17 , V_153 ) ;
}
static void * F_156 ( void )
{
struct V_15 * V_104 = V_150 -> V_151 -> V_152 ;
#ifdef F_157
if ( V_104 )
F_158 ( & V_104 -> V_154 ) ;
#endif
return V_104 ;
}
static const void * F_159 ( void )
{
return & V_155 ;
}
static const void * F_160 ( struct V_156 * V_157 )
{
return F_161 ( V_157 ) ;
}
static int F_162 ( struct V_5 * V_59 , struct V_158 * V_159 )
{
struct V_1 * V_2 = F_4 ( V_59 ) ;
int V_160 ;
V_160 = F_163 ( V_159 , L_15 , V_2 -> V_51 ) ;
if ( V_160 )
goto exit;
V_160 = F_163 ( V_159 , L_16 , V_2 -> V_161 ) ;
exit:
return V_160 ;
}
static void F_164 ( struct V_5 * V_59 )
{
struct V_1 * V_2 = F_4 ( V_59 ) ;
F_130 ( V_2 -> V_3 != V_162 ) ;
F_87 ( V_2 -> V_44 ) ;
F_165 ( V_2 ) ;
}
static const void * F_166 ( struct V_5 * V_59 )
{
struct V_1 * V_2 = F_4 ( V_59 ) ;
return F_9 ( V_2 ) ;
}
static int F_167 ( struct V_5 * V_2 , const void * V_163 )
{
int V_10 = 0 ;
if ( V_2 -> V_164 )
V_10 = V_2 -> V_164 -> V_165 == V_163 ;
return V_10 == 0 ? V_2 -> V_165 == V_163 : V_10 ;
}
struct V_1 * F_168 ( struct V_166 * V_167 )
{
struct V_5 * V_2 ;
V_2 = F_169 ( & V_168 , NULL , V_167 , F_167 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
void F_170 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_171 ( & V_2 -> V_68 ) ;
F_153 ( V_9 ) ;
F_172 ( V_2 , false ) ;
F_173 ( V_2 ) ;
}
int F_174 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_169 * * V_170 = V_9 -> V_171 ;
int error = 0 ;
F_175 ( V_2 ) ;
V_2 -> V_105 = & V_168 ;
V_2 -> V_172 = V_9 ;
V_2 -> V_170 = V_170 ;
F_176 ( V_2 , L_17 , V_9 -> V_51 ) ;
#ifdef F_120
if ( * V_170 )
V_170 ++ ;
* V_170 ++ = & V_173 ;
#if F_177 ( V_174 ) || F_177 ( V_175 )
if ( V_9 -> V_176 )
* V_170 ++ = & V_177 ;
#if F_177 ( V_174 )
else if ( V_9 -> V_178 )
* V_170 ++ = & V_177 ;
#endif
#endif
#endif
error = F_178 ( V_2 ) ;
if ( error )
return error ;
error = F_151 ( V_9 ) ;
if ( error ) {
F_173 ( V_2 ) ;
return error ;
}
F_172 ( V_2 , true ) ;
return error ;
}
int F_179 ( struct V_179 * V_180 ,
const void * V_104 )
{
return F_180 ( & V_168 , V_180 , V_104 ) ;
}
void F_181 ( struct V_179 * V_180 ,
const void * V_104 )
{
F_182 ( & V_168 , V_180 , V_104 ) ;
}
int T_4 F_183 ( void )
{
F_184 ( & V_181 ) ;
return F_185 ( & V_168 ) ;
}
