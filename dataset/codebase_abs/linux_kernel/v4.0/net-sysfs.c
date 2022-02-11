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
static T_1 F_15 ( const struct V_1 * V_2 , char * V_8 )
{
return sprintf ( V_8 , V_21 , V_2 -> V_22 ) ;
}
static T_1 F_16 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( V_9 -> V_22 != V_23 )
V_10 = F_2 ( V_2 , V_7 , V_8 , F_15 ) ;
return V_10 ;
}
static T_1 F_17 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = F_18 ( V_8 , V_9 -> V_24 , V_9 -> V_25 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_19 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
if ( F_1 ( V_9 ) )
return F_18 ( V_8 , V_9 -> V_26 , V_9 -> V_25 ) ;
return - V_11 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned long V_27 )
{
if ( ! F_21 ( V_2 ) )
return - V_11 ;
return F_22 ( V_2 , ( bool ) V_27 ) ;
}
static T_1 F_23 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_20 ) ;
}
static T_1 F_24 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_21 ( V_14 ) ) {
return sprintf ( V_8 , V_21 , ! ! F_25 ( V_14 ) ) ;
}
return - V_11 ;
}
static T_1 F_26 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_21 ( V_14 ) ) {
struct V_28 V_29 ;
if ( ! F_27 ( V_14 , & V_29 ) )
V_10 = sprintf ( V_8 , V_30 , F_28 ( & V_29 ) ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_29 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_21 ( V_14 ) ) {
struct V_28 V_29 ;
if ( ! F_27 ( V_14 , & V_29 ) ) {
const char * V_31 ;
switch ( V_29 . V_31 ) {
case V_32 :
V_31 = L_1 ;
break;
case V_33 :
V_31 = L_2 ;
break;
default:
V_31 = L_3 ;
break;
}
V_10 = sprintf ( V_8 , L_4 , V_31 ) ;
}
}
F_14 () ;
return V_10 ;
}
static T_1 F_30 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_21 ( V_14 ) )
return sprintf ( V_8 , V_21 , ! ! F_31 ( V_14 ) ) ;
return - V_11 ;
}
static T_1 F_32 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
unsigned char V_34 ;
F_5 ( & V_12 ) ;
V_34 = V_14 -> V_34 ;
if ( ! F_21 ( V_14 ) )
V_34 = V_35 ;
F_6 ( & V_12 ) ;
if ( V_34 >= F_33 ( V_36 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_36 [ V_34 ] ) ;
}
static T_1 F_34 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
return sprintf ( V_8 , V_21 ,
F_35 ( & V_14 -> V_37 ) ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned long V_38 )
{
return F_37 ( V_2 , ( int ) V_38 ) ;
}
static T_1 F_38 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_36 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_39 )
{
return F_40 ( V_2 , ( unsigned int ) V_39 ) ;
}
static T_1 F_41 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_39 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned long V_40 )
{
V_2 -> V_41 = V_40 ;
return 0 ;
}
static T_1 F_43 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_44 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_42 ) ;
}
static int F_45 ( struct V_1 * V_2 , unsigned long V_42 )
{
V_2 -> V_43 = V_42 ;
return 0 ;
}
static T_1 F_46 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_44 ( V_18 ) )
return - V_19 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_45 ) ;
}
static T_1 F_47 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_15 * V_15 = F_9 ( V_14 ) ;
T_2 V_44 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_44 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_48 ( V_14 , V_8 , V_44 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_49 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_45 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_45 ) ;
F_14 () ;
return V_10 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned long V_46 )
{
F_51 ( V_2 , ( int ) V_46 ) ;
return 0 ;
}
static T_1 F_52 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_50 ) ;
}
static T_1 F_53 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_47 V_48 ;
V_10 = F_54 ( V_14 , & V_48 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_48 . V_49 , V_48 . V_50 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_55 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_47 V_48 ;
V_10 = F_56 ( V_14 , & V_48 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_48 . V_49 , V_48 . V_50 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_57 ( const struct V_5 * V_51 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_52 )
{
struct V_1 * V_2 = F_4 ( V_51 ) ;
T_1 V_10 = - V_11 ;
F_58 ( V_52 > sizeof( struct V_53 ) ||
V_52 % sizeof( V_54 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_53 V_55 ;
const struct V_53 * V_56 = F_59 ( V_2 , & V_55 ) ;
V_10 = sprintf ( V_8 , V_57 , * ( V_54 * ) ( ( ( V_58 * ) V_56 ) + V_52 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_60 ( struct V_59 * V_60 , struct V_61 * V_7 ,
char * V_8 )
{
struct V_62 * V_61 = F_61 ( V_7 ) ;
struct V_63 * V_64 = F_62 ( V_60 ) ;
if ( ! V_61 -> V_65 )
return - V_66 ;
return V_61 -> V_65 ( V_64 , V_61 , V_8 ) ;
}
static T_1 F_63 ( struct V_59 * V_60 , struct V_61 * V_7 ,
const char * V_8 , T_2 V_44 )
{
struct V_62 * V_61 = F_61 ( V_7 ) ;
struct V_63 * V_64 = F_62 ( V_60 ) ;
if ( ! V_61 -> V_67 )
return - V_66 ;
return V_61 -> V_67 ( V_64 , V_61 , V_8 , V_44 ) ;
}
static T_1 F_64 ( struct V_63 * V_64 ,
struct V_62 * V_61 , char * V_8 )
{
struct V_68 * V_69 ;
T_3 V_70 ;
int V_71 , V_13 ;
if ( ! F_65 ( & V_70 , V_72 ) )
return - V_73 ;
F_66 () ;
V_69 = F_67 ( V_64 -> V_68 ) ;
if ( V_69 )
for ( V_71 = 0 ; V_71 < V_69 -> V_13 ; V_71 ++ )
F_68 ( V_69 -> V_74 [ V_71 ] , V_70 ) ;
V_13 = snprintf ( V_8 , V_75 , L_6 , F_69 ( V_70 ) ) ;
F_70 () ;
F_71 ( V_70 ) ;
return V_13 < V_75 ? V_13 : - V_11 ;
}
static T_1 F_72 ( struct V_63 * V_64 ,
struct V_62 * V_61 ,
const char * V_8 , T_2 V_13 )
{
struct V_68 * V_76 , * V_69 ;
T_3 V_70 ;
int V_20 , V_77 , V_71 ;
static F_73 ( V_78 ) ;
if ( ! F_44 ( V_18 ) )
return - V_19 ;
if ( ! F_74 ( & V_70 , V_72 ) )
return - V_73 ;
V_20 = F_75 ( V_8 , V_13 , F_76 ( V_70 ) , V_79 ) ;
if ( V_20 ) {
F_71 ( V_70 ) ;
return V_20 ;
}
V_69 = F_77 ( F_78 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_72 ) ;
if ( ! V_69 ) {
F_71 ( V_70 ) ;
return - V_73 ;
}
V_71 = 0 ;
F_79 (cpu, mask, cpu_online_mask)
V_69 -> V_74 [ V_71 ++ ] = V_77 ;
if ( V_71 )
V_69 -> V_13 = V_71 ;
else {
F_80 ( V_69 ) ;
V_69 = NULL ;
}
F_81 ( & V_78 ) ;
V_76 = F_82 ( V_64 -> V_68 ,
F_83 ( & V_78 ) ) ;
F_84 ( V_64 -> V_68 , V_69 ) ;
F_85 ( & V_78 ) ;
if ( V_69 )
F_86 ( & V_80 ) ;
if ( V_76 ) {
F_87 ( V_76 , V_81 ) ;
F_88 ( & V_80 ) ;
}
F_71 ( V_70 ) ;
return V_13 ;
}
static T_1 F_89 ( struct V_63 * V_64 ,
struct V_62 * V_7 ,
char * V_8 )
{
struct V_82 * V_83 ;
unsigned long V_42 = 0 ;
F_66 () ;
V_83 = F_67 ( V_64 -> V_84 ) ;
if ( V_83 )
V_42 = ( unsigned long ) V_83 -> V_70 + 1 ;
F_70 () ;
return sprintf ( V_8 , L_7 , V_42 ) ;
}
static void F_90 ( struct V_85 * V_81 )
{
struct V_82 * V_86 = F_91 ( V_81 ,
struct V_82 , V_81 ) ;
F_92 ( V_86 ) ;
}
static T_1 F_93 ( struct V_63 * V_64 ,
struct V_62 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_70 , V_44 ;
struct V_82 * V_86 , * V_87 ;
static F_73 ( V_88 ) ;
int V_89 ;
if ( ! F_44 ( V_18 ) )
return - V_19 ;
V_89 = F_11 ( V_8 , 0 , & V_44 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_44 ) {
V_70 = V_44 - 1 ;
while ( ( V_70 | ( V_70 >> 1 ) ) != V_70 )
V_70 |= ( V_70 >> 1 ) ;
#if V_90 > 32
if ( V_70 > ( unsigned long ) ( V_91 ) V_70 )
return - V_11 ;
#else
if ( V_70 > ( V_92 - F_94 ( 1 ) )
/ sizeof( struct V_93 ) ) {
return - V_11 ;
}
#endif
V_86 = F_95 ( F_94 ( V_70 + 1 ) ) ;
if ( ! V_86 )
return - V_73 ;
V_86 -> V_70 = V_70 ;
for ( V_44 = 0 ; V_44 <= V_70 ; V_44 ++ )
V_86 -> V_94 [ V_44 ] . V_77 = V_95 ;
} else
V_86 = NULL ;
F_81 ( & V_88 ) ;
V_87 = F_82 ( V_64 -> V_84 ,
F_83 ( & V_88 ) ) ;
F_84 ( V_64 -> V_84 , V_86 ) ;
F_85 ( & V_88 ) ;
if ( V_87 )
F_96 ( & V_87 -> V_81 , F_90 ) ;
return V_13 ;
}
static void F_97 ( struct V_59 * V_60 )
{
struct V_63 * V_64 = F_62 ( V_60 ) ;
#ifdef F_98
struct V_68 * V_69 ;
struct V_82 * V_83 ;
V_69 = F_82 ( V_64 -> V_68 , 1 ) ;
if ( V_69 ) {
F_99 ( V_64 -> V_68 , NULL ) ;
F_87 ( V_69 , V_81 ) ;
}
V_83 = F_82 ( V_64 -> V_84 , 1 ) ;
if ( V_83 ) {
F_99 ( V_64 -> V_84 , NULL ) ;
F_96 ( & V_83 -> V_81 , F_90 ) ;
}
#endif
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_100 ( V_64 -> V_2 ) ;
}
static const void * F_101 ( struct V_59 * V_60 )
{
struct V_63 * V_64 = F_62 ( V_60 ) ;
struct V_5 * V_2 = & V_64 -> V_2 -> V_2 ;
const void * V_96 = NULL ;
if ( V_2 -> V_97 && V_2 -> V_97 -> V_98 )
V_96 = V_2 -> V_97 -> V_99 ( V_2 ) ;
return V_96 ;
}
static int F_102 ( struct V_1 * V_2 , int V_100 )
{
struct V_63 * V_64 = V_2 -> V_101 + V_100 ;
struct V_59 * V_60 = & V_64 -> V_60 ;
int error = 0 ;
V_60 -> V_102 = V_2 -> V_103 ;
error = F_103 ( V_60 , & V_104 , NULL ,
L_8 , V_100 ) ;
if ( error )
goto exit;
if ( V_2 -> V_105 ) {
error = F_104 ( V_60 , V_2 -> V_105 ) ;
if ( error )
goto exit;
}
F_105 ( V_60 , V_106 ) ;
F_106 ( V_64 -> V_2 ) ;
return error ;
exit:
F_107 ( V_60 ) ;
return error ;
}
int
F_108 ( struct V_1 * V_2 , int V_107 , int V_108 )
{
#ifdef F_109
int V_71 ;
int error = 0 ;
#ifndef F_98
if ( ! V_2 -> V_105 )
return 0 ;
#endif
for ( V_71 = V_107 ; V_71 < V_108 ; V_71 ++ ) {
error = F_102 ( V_2 , V_71 ) ;
if ( error ) {
V_108 = V_107 ;
break;
}
}
while ( -- V_71 >= V_108 ) {
if ( V_2 -> V_105 )
F_110 ( & V_2 -> V_101 [ V_71 ] . V_60 ,
V_2 -> V_105 ) ;
F_107 ( & V_2 -> V_101 [ V_71 ] . V_60 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_111 ( struct V_59 * V_60 ,
struct V_61 * V_7 , char * V_8 )
{
struct V_109 * V_61 = F_112 ( V_7 ) ;
struct V_110 * V_64 = F_113 ( V_60 ) ;
if ( ! V_61 -> V_65 )
return - V_66 ;
return V_61 -> V_65 ( V_64 , V_61 , V_8 ) ;
}
static T_1 F_114 ( struct V_59 * V_60 ,
struct V_61 * V_7 ,
const char * V_8 , T_2 V_44 )
{
struct V_109 * V_61 = F_112 ( V_7 ) ;
struct V_110 * V_64 = F_113 ( V_60 ) ;
if ( ! V_61 -> V_67 )
return - V_66 ;
return V_61 -> V_67 ( V_64 , V_61 , V_8 , V_44 ) ;
}
static T_1 F_115 ( struct V_110 * V_64 ,
struct V_109 * V_61 ,
char * V_8 )
{
unsigned long V_111 ;
F_116 ( & V_64 -> V_112 ) ;
V_111 = V_64 -> V_111 ;
F_117 ( & V_64 -> V_112 ) ;
return sprintf ( V_8 , L_9 , V_111 ) ;
}
static T_1 F_118 ( char * V_8 , unsigned int V_113 )
{
return sprintf ( V_8 , L_10 , V_113 ) ;
}
static T_1 F_119 ( const char * V_8 , const T_2 V_44 ,
unsigned int * V_114 )
{
unsigned int V_113 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_113 = V_115 ;
else {
V_20 = F_120 ( V_8 , 10 , & V_113 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_113 > V_115 )
return - V_11 ;
}
* V_114 = V_113 ;
return V_44 ;
}
static T_1 F_121 ( struct V_110 * V_64 ,
struct V_109 * V_7 ,
char * V_8 )
{
struct V_116 * V_116 = & V_64 -> V_116 ;
return sprintf ( V_8 , L_10 , F_122 ( V_116 -> V_117 ) ) ;
}
static T_1 F_123 ( struct V_110 * V_64 ,
struct V_109 * V_61 ,
const char * V_8 , T_2 V_13 )
{
struct V_116 * V_116 = & V_64 -> V_116 ;
unsigned int V_113 ;
int V_20 ;
V_20 = F_120 ( V_8 , 10 , & V_113 ) ;
if ( V_20 < 0 )
return V_20 ;
V_116 -> V_117 = F_124 ( V_113 ) ;
return V_13 ;
}
static T_1 F_125 ( struct V_110 * V_64 ,
struct V_109 * V_7 ,
char * V_8 )
{
struct V_116 * V_116 = & V_64 -> V_116 ;
return sprintf ( V_8 , L_10 , V_116 -> V_118 - V_116 -> V_119 ) ;
}
static unsigned int F_126 ( struct V_110 * V_64 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
unsigned int V_71 ;
V_71 = V_64 - V_2 -> V_120 ;
F_127 ( V_71 >= V_2 -> V_121 ) ;
return V_71 ;
}
static T_1 F_128 ( struct V_110 * V_64 ,
struct V_109 * V_61 , char * V_8 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_122 * V_123 ;
T_3 V_70 ;
unsigned long V_100 ;
int V_71 , V_13 ;
if ( ! F_65 ( & V_70 , V_72 ) )
return - V_73 ;
V_100 = F_126 ( V_64 ) ;
F_66 () ;
V_123 = F_67 ( V_2 -> V_124 ) ;
if ( V_123 ) {
F_129 (i) {
struct V_125 * V_69 =
F_67 ( V_123 -> V_126 [ V_71 ] ) ;
if ( V_69 ) {
int V_127 ;
for ( V_127 = 0 ; V_127 < V_69 -> V_13 ; V_127 ++ ) {
if ( V_69 -> V_128 [ V_127 ] == V_100 ) {
F_68 ( V_71 , V_70 ) ;
break;
}
}
}
}
}
F_70 () ;
V_13 = snprintf ( V_8 , V_75 , L_6 , F_69 ( V_70 ) ) ;
F_71 ( V_70 ) ;
return V_13 < V_75 ? V_13 : - V_11 ;
}
static T_1 F_130 ( struct V_110 * V_64 ,
struct V_109 * V_61 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
unsigned long V_100 ;
T_3 V_70 ;
int V_20 ;
if ( ! F_44 ( V_18 ) )
return - V_19 ;
if ( ! F_74 ( & V_70 , V_72 ) )
return - V_73 ;
V_100 = F_126 ( V_64 ) ;
V_20 = F_75 ( V_8 , V_13 , F_76 ( V_70 ) , V_79 ) ;
if ( V_20 ) {
F_71 ( V_70 ) ;
return V_20 ;
}
V_20 = F_131 ( V_2 , V_70 , V_100 ) ;
F_71 ( V_70 ) ;
return V_20 ? : V_13 ;
}
static void F_132 ( struct V_59 * V_60 )
{
struct V_110 * V_64 = F_113 ( V_60 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_100 ( V_64 -> V_2 ) ;
}
static const void * F_133 ( struct V_59 * V_60 )
{
struct V_110 * V_64 = F_113 ( V_60 ) ;
struct V_5 * V_2 = & V_64 -> V_2 -> V_2 ;
const void * V_96 = NULL ;
if ( V_2 -> V_97 && V_2 -> V_97 -> V_98 )
V_96 = V_2 -> V_97 -> V_99 ( V_2 ) ;
return V_96 ;
}
static int F_134 ( struct V_1 * V_2 , int V_100 )
{
struct V_110 * V_64 = V_2 -> V_120 + V_100 ;
struct V_59 * V_60 = & V_64 -> V_60 ;
int error = 0 ;
V_60 -> V_102 = V_2 -> V_103 ;
error = F_103 ( V_60 , & V_129 , NULL ,
L_13 , V_100 ) ;
if ( error )
goto exit;
#ifdef F_135
error = F_104 ( V_60 , & V_130 ) ;
if ( error )
goto exit;
#endif
F_105 ( V_60 , V_106 ) ;
F_106 ( V_64 -> V_2 ) ;
return 0 ;
exit:
F_107 ( V_60 ) ;
return error ;
}
int
F_136 ( struct V_1 * V_2 , int V_107 , int V_108 )
{
#ifdef F_109
int V_71 ;
int error = 0 ;
for ( V_71 = V_107 ; V_71 < V_108 ; V_71 ++ ) {
error = F_134 ( V_2 , V_71 ) ;
if ( error ) {
V_108 = V_107 ;
break;
}
}
while ( -- V_71 >= V_108 ) {
struct V_110 * V_64 = V_2 -> V_120 + V_71 ;
#ifdef F_135
F_110 ( & V_64 -> V_60 , & V_130 ) ;
#endif
F_107 ( & V_64 -> V_60 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_137 ( struct V_1 * V_2 )
{
int error = 0 , V_131 = 0 , V_132 = 0 , V_133 = 0 , V_134 = 0 ;
#ifdef F_109
V_2 -> V_103 = F_138 ( L_14 ,
NULL , & V_2 -> V_2 . V_60 ) ;
if ( ! V_2 -> V_103 )
return - V_73 ;
V_133 = V_2 -> V_135 ;
#endif
V_134 = V_2 -> V_136 ;
error = F_108 ( V_2 , 0 , V_133 ) ;
if ( error )
goto error;
V_132 = V_133 ;
error = F_136 ( V_2 , 0 , V_134 ) ;
if ( error )
goto error;
V_131 = V_134 ;
return 0 ;
error:
F_136 ( V_2 , V_131 , 0 ) ;
F_108 ( V_2 , V_132 , 0 ) ;
return error ;
}
static void F_139 ( struct V_1 * V_2 )
{
int V_133 = 0 , V_134 = 0 ;
#ifdef F_109
V_133 = V_2 -> V_135 ;
#endif
V_134 = V_2 -> V_136 ;
F_108 ( V_2 , V_133 , 0 ) ;
F_136 ( V_2 , V_134 , 0 ) ;
#ifdef F_109
F_140 ( V_2 -> V_103 ) ;
#endif
}
static bool F_141 ( void )
{
struct V_15 * V_15 = V_137 -> V_138 -> V_139 ;
return F_10 ( V_15 -> V_17 , V_140 ) ;
}
static void * F_142 ( void )
{
struct V_15 * V_96 = V_137 -> V_138 -> V_139 ;
#ifdef F_143
if ( V_96 )
F_144 ( & V_96 -> V_141 ) ;
#endif
return V_96 ;
}
static const void * F_145 ( void )
{
return & V_142 ;
}
static const void * F_146 ( struct V_143 * V_144 )
{
return F_147 ( V_144 ) ;
}
static int F_148 ( struct V_5 * V_51 , struct V_145 * V_146 )
{
struct V_1 * V_2 = F_4 ( V_51 ) ;
int V_147 ;
V_147 = F_149 ( V_146 , L_15 , V_2 -> V_148 ) ;
if ( V_147 )
goto exit;
V_147 = F_149 ( V_146 , L_16 , V_2 -> V_149 ) ;
exit:
return V_147 ;
}
static void F_150 ( struct V_5 * V_51 )
{
struct V_1 * V_2 = F_4 ( V_51 ) ;
F_127 ( V_2 -> V_3 != V_150 ) ;
F_80 ( V_2 -> V_45 ) ;
F_151 ( V_2 ) ;
}
static const void * F_152 ( struct V_5 * V_51 )
{
struct V_1 * V_2 ;
V_2 = F_91 ( V_51 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_153 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_154 ( & V_2 -> V_60 ) ;
F_139 ( V_9 ) ;
F_155 ( V_2 , false ) ;
F_156 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_151 * * V_152 = V_9 -> V_153 ;
int error = 0 ;
F_158 ( V_2 ) ;
V_2 -> V_97 = & V_154 ;
V_2 -> V_155 = V_9 ;
V_2 -> V_152 = V_152 ;
F_159 ( V_2 , L_17 , V_9 -> V_148 ) ;
#ifdef F_109
if ( * V_152 )
V_152 ++ ;
* V_152 ++ = & V_156 ;
#if F_160 ( V_157 ) || F_160 ( V_158 )
if ( V_9 -> V_159 )
* V_152 ++ = & V_160 ;
#if F_160 ( V_157 )
else if ( V_9 -> V_161 )
* V_152 ++ = & V_160 ;
#endif
#endif
#endif
error = F_161 ( V_2 ) ;
if ( error )
return error ;
error = F_137 ( V_9 ) ;
if ( error ) {
F_156 ( V_2 ) ;
return error ;
}
F_155 ( V_2 , true ) ;
return error ;
}
int F_162 ( struct V_162 * V_163 ,
const void * V_96 )
{
return F_163 ( & V_154 , V_163 , V_96 ) ;
}
void F_164 ( struct V_162 * V_163 ,
const void * V_96 )
{
F_165 ( & V_154 , V_163 , V_96 ) ;
}
int T_4 F_166 ( void )
{
F_167 ( & V_164 ) ;
return F_168 ( & V_154 ) ;
}
