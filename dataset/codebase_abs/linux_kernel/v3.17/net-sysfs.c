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
static T_1 F_45 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_15 * V_15 = F_9 ( V_14 ) ;
T_2 V_42 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_42 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_46 ( V_14 , V_8 , V_42 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_47 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_43 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_43 ) ;
F_14 () ;
return V_10 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned long V_44 )
{
F_49 ( V_2 , ( int ) V_44 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_48 ) ;
}
static T_1 F_51 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_45 V_46 ;
V_10 = F_52 ( V_14 , & V_46 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_46 . V_47 , V_46 . V_48 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_53 ( const struct V_5 * V_49 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_50 )
{
struct V_1 * V_2 = F_4 ( V_49 ) ;
T_1 V_10 = - V_11 ;
F_54 ( V_50 > sizeof( struct V_51 ) ||
V_50 % sizeof( V_52 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_51 V_53 ;
const struct V_51 * V_54 = F_55 ( V_2 , & V_53 ) ;
V_10 = sprintf ( V_8 , V_55 , * ( V_52 * ) ( ( ( V_56 * ) V_54 ) + V_50 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_56 ( struct V_57 * V_58 , struct V_59 * V_7 ,
char * V_8 )
{
struct V_60 * V_59 = F_57 ( V_7 ) ;
struct V_61 * V_62 = F_58 ( V_58 ) ;
if ( ! V_59 -> V_63 )
return - V_64 ;
return V_59 -> V_63 ( V_62 , V_59 , V_8 ) ;
}
static T_1 F_59 ( struct V_57 * V_58 , struct V_59 * V_7 ,
const char * V_8 , T_2 V_42 )
{
struct V_60 * V_59 = F_57 ( V_7 ) ;
struct V_61 * V_62 = F_58 ( V_58 ) ;
if ( ! V_59 -> V_65 )
return - V_64 ;
return V_59 -> V_65 ( V_62 , V_59 , V_8 , V_42 ) ;
}
static T_1 F_60 ( struct V_61 * V_62 ,
struct V_60 * V_59 , char * V_8 )
{
struct V_66 * V_67 ;
T_3 V_68 ;
T_2 V_13 = 0 ;
int V_69 ;
if ( ! F_61 ( & V_68 , V_70 ) )
return - V_71 ;
F_62 () ;
V_67 = F_63 ( V_62 -> V_66 ) ;
if ( V_67 )
for ( V_69 = 0 ; V_69 < V_67 -> V_13 ; V_69 ++ )
F_64 ( V_67 -> V_72 [ V_69 ] , V_68 ) ;
V_13 += F_65 ( V_8 + V_13 , V_73 , V_68 ) ;
if ( V_73 - V_13 < 3 ) {
F_66 () ;
F_67 ( V_68 ) ;
return - V_11 ;
}
F_66 () ;
F_67 ( V_68 ) ;
V_13 += sprintf ( V_8 + V_13 , L_6 ) ;
return V_13 ;
}
static T_1 F_68 ( struct V_61 * V_62 ,
struct V_60 * V_59 ,
const char * V_8 , T_2 V_13 )
{
struct V_66 * V_74 , * V_67 ;
T_3 V_68 ;
int V_20 , V_75 , V_69 ;
static F_69 ( V_76 ) ;
if ( ! F_44 ( V_18 ) )
return - V_19 ;
if ( ! F_70 ( & V_68 , V_70 ) )
return - V_71 ;
V_20 = F_71 ( V_8 , V_13 , F_72 ( V_68 ) , V_77 ) ;
if ( V_20 ) {
F_67 ( V_68 ) ;
return V_20 ;
}
V_67 = F_73 ( F_74 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_70 ) ;
if ( ! V_67 ) {
F_67 ( V_68 ) ;
return - V_71 ;
}
V_69 = 0 ;
F_75 (cpu, mask, cpu_online_mask)
V_67 -> V_72 [ V_69 ++ ] = V_75 ;
if ( V_69 )
V_67 -> V_13 = V_69 ;
else {
F_76 ( V_67 ) ;
V_67 = NULL ;
}
F_77 ( & V_76 ) ;
V_74 = F_78 ( V_62 -> V_66 ,
F_79 ( & V_76 ) ) ;
F_80 ( V_62 -> V_66 , V_67 ) ;
F_81 ( & V_76 ) ;
if ( V_67 )
F_82 ( & V_78 ) ;
if ( V_74 ) {
F_83 ( V_74 , V_79 ) ;
F_84 ( & V_78 ) ;
}
F_67 ( V_68 ) ;
return V_13 ;
}
static T_1 F_85 ( struct V_61 * V_62 ,
struct V_60 * V_7 ,
char * V_8 )
{
struct V_80 * V_81 ;
unsigned long V_82 = 0 ;
F_62 () ;
V_81 = F_63 ( V_62 -> V_83 ) ;
if ( V_81 )
V_82 = ( unsigned long ) V_81 -> V_68 + 1 ;
F_66 () ;
return sprintf ( V_8 , L_7 , V_82 ) ;
}
static void F_86 ( struct V_84 * V_79 )
{
struct V_80 * V_85 = F_87 ( V_79 ,
struct V_80 , V_79 ) ;
F_88 ( V_85 ) ;
}
static T_1 F_89 ( struct V_61 * V_62 ,
struct V_60 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_68 , V_42 ;
struct V_80 * V_85 , * V_86 ;
static F_69 ( V_87 ) ;
int V_88 ;
if ( ! F_44 ( V_18 ) )
return - V_19 ;
V_88 = F_11 ( V_8 , 0 , & V_42 ) ;
if ( V_88 < 0 )
return V_88 ;
if ( V_42 ) {
V_68 = V_42 - 1 ;
while ( ( V_68 | ( V_68 >> 1 ) ) != V_68 )
V_68 |= ( V_68 >> 1 ) ;
#if V_89 > 32
if ( V_68 > ( unsigned long ) ( V_90 ) V_68 )
return - V_11 ;
#else
if ( V_68 > ( V_91 - F_90 ( 1 ) )
/ sizeof( struct V_92 ) ) {
return - V_11 ;
}
#endif
V_85 = F_91 ( F_90 ( V_68 + 1 ) ) ;
if ( ! V_85 )
return - V_71 ;
V_85 -> V_68 = V_68 ;
for ( V_42 = 0 ; V_42 <= V_68 ; V_42 ++ )
V_85 -> V_93 [ V_42 ] . V_75 = V_94 ;
} else
V_85 = NULL ;
F_77 ( & V_87 ) ;
V_86 = F_78 ( V_62 -> V_83 ,
F_79 ( & V_87 ) ) ;
F_80 ( V_62 -> V_83 , V_85 ) ;
F_81 ( & V_87 ) ;
if ( V_86 )
F_92 ( & V_86 -> V_79 , F_86 ) ;
return V_13 ;
}
static void F_93 ( struct V_57 * V_58 )
{
struct V_61 * V_62 = F_58 ( V_58 ) ;
#ifdef F_94
struct V_66 * V_67 ;
struct V_80 * V_81 ;
V_67 = F_78 ( V_62 -> V_66 , 1 ) ;
if ( V_67 ) {
F_95 ( V_62 -> V_66 , NULL ) ;
F_83 ( V_67 , V_79 ) ;
}
V_81 = F_78 ( V_62 -> V_83 , 1 ) ;
if ( V_81 ) {
F_95 ( V_62 -> V_83 , NULL ) ;
F_92 ( & V_81 -> V_79 , F_86 ) ;
}
#endif
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_96 ( V_62 -> V_2 ) ;
}
static const void * F_97 ( struct V_57 * V_58 )
{
struct V_61 * V_62 = F_58 ( V_58 ) ;
struct V_5 * V_2 = & V_62 -> V_2 -> V_2 ;
const void * V_95 = NULL ;
if ( V_2 -> V_96 && V_2 -> V_96 -> V_97 )
V_95 = V_2 -> V_96 -> V_98 ( V_2 ) ;
return V_95 ;
}
static int F_98 ( struct V_1 * V_2 , int V_99 )
{
struct V_61 * V_62 = V_2 -> V_100 + V_99 ;
struct V_57 * V_58 = & V_62 -> V_58 ;
int error = 0 ;
V_58 -> V_101 = V_2 -> V_102 ;
error = F_99 ( V_58 , & V_103 , NULL ,
L_8 , V_99 ) ;
if ( error )
goto exit;
if ( V_2 -> V_104 ) {
error = F_100 ( V_58 , V_2 -> V_104 ) ;
if ( error )
goto exit;
}
F_101 ( V_58 , V_105 ) ;
F_102 ( V_62 -> V_2 ) ;
return error ;
exit:
F_103 ( V_58 ) ;
return error ;
}
int
F_104 ( struct V_1 * V_2 , int V_106 , int V_107 )
{
#ifdef F_105
int V_69 ;
int error = 0 ;
#ifndef F_94
if ( ! V_2 -> V_104 )
return 0 ;
#endif
for ( V_69 = V_106 ; V_69 < V_107 ; V_69 ++ ) {
error = F_98 ( V_2 , V_69 ) ;
if ( error ) {
V_107 = V_106 ;
break;
}
}
while ( -- V_69 >= V_107 ) {
if ( V_2 -> V_104 )
F_106 ( & V_2 -> V_100 [ V_69 ] . V_58 ,
V_2 -> V_104 ) ;
F_103 ( & V_2 -> V_100 [ V_69 ] . V_58 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_107 ( struct V_57 * V_58 ,
struct V_59 * V_7 , char * V_8 )
{
struct V_108 * V_59 = F_108 ( V_7 ) ;
struct V_109 * V_62 = F_109 ( V_58 ) ;
if ( ! V_59 -> V_63 )
return - V_64 ;
return V_59 -> V_63 ( V_62 , V_59 , V_8 ) ;
}
static T_1 F_110 ( struct V_57 * V_58 ,
struct V_59 * V_7 ,
const char * V_8 , T_2 V_42 )
{
struct V_108 * V_59 = F_108 ( V_7 ) ;
struct V_109 * V_62 = F_109 ( V_58 ) ;
if ( ! V_59 -> V_65 )
return - V_64 ;
return V_59 -> V_65 ( V_62 , V_59 , V_8 , V_42 ) ;
}
static T_1 F_111 ( struct V_109 * V_62 ,
struct V_108 * V_59 ,
char * V_8 )
{
unsigned long V_110 ;
F_112 ( & V_62 -> V_111 ) ;
V_110 = V_62 -> V_110 ;
F_113 ( & V_62 -> V_111 ) ;
return sprintf ( V_8 , L_9 , V_110 ) ;
}
static T_1 F_114 ( char * V_8 , unsigned int V_112 )
{
return sprintf ( V_8 , L_10 , V_112 ) ;
}
static T_1 F_115 ( const char * V_8 , const T_2 V_42 ,
unsigned int * V_113 )
{
unsigned int V_112 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_112 = V_114 ;
else {
V_20 = F_116 ( V_8 , 10 , & V_112 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_112 > V_114 )
return - V_11 ;
}
* V_113 = V_112 ;
return V_42 ;
}
static T_1 F_117 ( struct V_109 * V_62 ,
struct V_108 * V_7 ,
char * V_8 )
{
struct V_115 * V_115 = & V_62 -> V_115 ;
return sprintf ( V_8 , L_10 , F_118 ( V_115 -> V_116 ) ) ;
}
static T_1 F_119 ( struct V_109 * V_62 ,
struct V_108 * V_59 ,
const char * V_8 , T_2 V_13 )
{
struct V_115 * V_115 = & V_62 -> V_115 ;
unsigned int V_112 ;
int V_20 ;
V_20 = F_116 ( V_8 , 10 , & V_112 ) ;
if ( V_20 < 0 )
return V_20 ;
V_115 -> V_116 = F_120 ( V_112 ) ;
return V_13 ;
}
static T_1 F_121 ( struct V_109 * V_62 ,
struct V_108 * V_7 ,
char * V_8 )
{
struct V_115 * V_115 = & V_62 -> V_115 ;
return sprintf ( V_8 , L_10 , V_115 -> V_117 - V_115 -> V_118 ) ;
}
static unsigned int F_122 ( struct V_109 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
unsigned int V_69 ;
V_69 = V_62 - V_2 -> V_119 ;
F_123 ( V_69 >= V_2 -> V_120 ) ;
return V_69 ;
}
static T_1 F_124 ( struct V_109 * V_62 ,
struct V_108 * V_59 , char * V_8 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_121 * V_122 ;
T_3 V_68 ;
unsigned long V_99 ;
T_2 V_13 = 0 ;
int V_69 ;
if ( ! F_61 ( & V_68 , V_70 ) )
return - V_71 ;
V_99 = F_122 ( V_62 ) ;
F_62 () ;
V_122 = F_63 ( V_2 -> V_123 ) ;
if ( V_122 ) {
F_125 (i) {
struct V_124 * V_67 =
F_63 ( V_122 -> V_125 [ V_69 ] ) ;
if ( V_67 ) {
int V_126 ;
for ( V_126 = 0 ; V_126 < V_67 -> V_13 ; V_126 ++ ) {
if ( V_67 -> V_127 [ V_126 ] == V_99 ) {
F_64 ( V_69 , V_68 ) ;
break;
}
}
}
}
}
F_66 () ;
V_13 += F_65 ( V_8 + V_13 , V_73 , V_68 ) ;
if ( V_73 - V_13 < 3 ) {
F_67 ( V_68 ) ;
return - V_11 ;
}
F_67 ( V_68 ) ;
V_13 += sprintf ( V_8 + V_13 , L_6 ) ;
return V_13 ;
}
static T_1 F_126 ( struct V_109 * V_62 ,
struct V_108 * V_59 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
unsigned long V_99 ;
T_3 V_68 ;
int V_20 ;
if ( ! F_44 ( V_18 ) )
return - V_19 ;
if ( ! F_70 ( & V_68 , V_70 ) )
return - V_71 ;
V_99 = F_122 ( V_62 ) ;
V_20 = F_71 ( V_8 , V_13 , F_72 ( V_68 ) , V_77 ) ;
if ( V_20 ) {
F_67 ( V_68 ) ;
return V_20 ;
}
V_20 = F_127 ( V_2 , V_68 , V_99 ) ;
F_67 ( V_68 ) ;
return V_20 ? : V_13 ;
}
static void F_128 ( struct V_57 * V_58 )
{
struct V_109 * V_62 = F_109 ( V_58 ) ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_96 ( V_62 -> V_2 ) ;
}
static const void * F_129 ( struct V_57 * V_58 )
{
struct V_109 * V_62 = F_109 ( V_58 ) ;
struct V_5 * V_2 = & V_62 -> V_2 -> V_2 ;
const void * V_95 = NULL ;
if ( V_2 -> V_96 && V_2 -> V_96 -> V_97 )
V_95 = V_2 -> V_96 -> V_98 ( V_2 ) ;
return V_95 ;
}
static int F_130 ( struct V_1 * V_2 , int V_99 )
{
struct V_109 * V_62 = V_2 -> V_119 + V_99 ;
struct V_57 * V_58 = & V_62 -> V_58 ;
int error = 0 ;
V_58 -> V_101 = V_2 -> V_102 ;
error = F_99 ( V_58 , & V_128 , NULL ,
L_13 , V_99 ) ;
if ( error )
goto exit;
#ifdef F_131
error = F_100 ( V_58 , & V_129 ) ;
if ( error )
goto exit;
#endif
F_101 ( V_58 , V_105 ) ;
F_102 ( V_62 -> V_2 ) ;
return 0 ;
exit:
F_103 ( V_58 ) ;
return error ;
}
int
F_132 ( struct V_1 * V_2 , int V_106 , int V_107 )
{
#ifdef F_105
int V_69 ;
int error = 0 ;
for ( V_69 = V_106 ; V_69 < V_107 ; V_69 ++ ) {
error = F_130 ( V_2 , V_69 ) ;
if ( error ) {
V_107 = V_106 ;
break;
}
}
while ( -- V_69 >= V_107 ) {
struct V_109 * V_62 = V_2 -> V_119 + V_69 ;
#ifdef F_131
F_106 ( & V_62 -> V_58 , & V_129 ) ;
#endif
F_103 ( & V_62 -> V_58 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_133 ( struct V_1 * V_2 )
{
int error = 0 , V_130 = 0 , V_131 = 0 , V_132 = 0 , V_133 = 0 ;
#ifdef F_105
V_2 -> V_102 = F_134 ( L_14 ,
NULL , & V_2 -> V_2 . V_58 ) ;
if ( ! V_2 -> V_102 )
return - V_71 ;
V_132 = V_2 -> V_134 ;
#endif
V_133 = V_2 -> V_135 ;
error = F_104 ( V_2 , 0 , V_132 ) ;
if ( error )
goto error;
V_131 = V_132 ;
error = F_132 ( V_2 , 0 , V_133 ) ;
if ( error )
goto error;
V_130 = V_133 ;
return 0 ;
error:
F_132 ( V_2 , V_130 , 0 ) ;
F_104 ( V_2 , V_131 , 0 ) ;
return error ;
}
static void F_135 ( struct V_1 * V_2 )
{
int V_132 = 0 , V_133 = 0 ;
#ifdef F_105
V_132 = V_2 -> V_134 ;
#endif
V_133 = V_2 -> V_135 ;
F_104 ( V_2 , V_132 , 0 ) ;
F_132 ( V_2 , V_133 , 0 ) ;
#ifdef F_105
F_136 ( V_2 -> V_102 ) ;
#endif
}
static bool F_137 ( void )
{
struct V_15 * V_15 = V_136 -> V_137 -> V_138 ;
return F_10 ( V_15 -> V_17 , V_139 ) ;
}
static void * F_138 ( void )
{
struct V_15 * V_95 = V_136 -> V_137 -> V_138 ;
#ifdef F_139
if ( V_95 )
F_140 ( & V_95 -> V_140 ) ;
#endif
return V_95 ;
}
static const void * F_141 ( void )
{
return & V_141 ;
}
static const void * F_142 ( struct V_142 * V_143 )
{
return F_143 ( V_143 ) ;
}
static int F_144 ( struct V_5 * V_49 , struct V_144 * V_145 )
{
struct V_1 * V_2 = F_4 ( V_49 ) ;
int V_146 ;
V_146 = F_145 ( V_145 , L_15 , V_2 -> V_147 ) ;
if ( V_146 )
goto exit;
V_146 = F_145 ( V_145 , L_16 , V_2 -> V_148 ) ;
exit:
return V_146 ;
}
static void F_146 ( struct V_5 * V_49 )
{
struct V_1 * V_2 = F_4 ( V_49 ) ;
F_123 ( V_2 -> V_3 != V_149 ) ;
F_76 ( V_2 -> V_43 ) ;
F_147 ( V_2 ) ;
}
static const void * F_148 ( struct V_5 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_87 ( V_49 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_149 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_150 ( & V_2 -> V_58 ) ;
F_135 ( V_9 ) ;
F_151 ( V_2 , false ) ;
F_152 ( V_2 ) ;
}
int F_153 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_150 * * V_151 = V_9 -> V_152 ;
int error = 0 ;
F_154 ( V_2 ) ;
V_2 -> V_96 = & V_153 ;
V_2 -> V_154 = V_9 ;
V_2 -> V_151 = V_151 ;
F_155 ( V_2 , L_17 , V_9 -> V_147 ) ;
#ifdef F_105
if ( * V_151 )
V_151 ++ ;
* V_151 ++ = & V_155 ;
#if F_156 ( V_156 ) || F_156 ( V_157 )
if ( V_9 -> V_158 )
* V_151 ++ = & V_159 ;
#if F_156 ( V_156 )
else if ( V_9 -> V_160 )
* V_151 ++ = & V_159 ;
#endif
#endif
#endif
error = F_157 ( V_2 ) ;
if ( error )
return error ;
error = F_133 ( V_9 ) ;
if ( error ) {
F_152 ( V_2 ) ;
return error ;
}
F_151 ( V_2 , true ) ;
return error ;
}
int F_158 ( struct V_161 * V_162 ,
const void * V_95 )
{
return F_159 ( & V_153 , V_162 , V_95 ) ;
}
void F_160 ( struct V_161 * V_162 ,
const void * V_95 )
{
F_161 ( & V_153 , V_162 , V_95 ) ;
}
int T_4 F_162 ( void )
{
F_163 ( & V_163 ) ;
return F_164 ( & V_153 ) ;
}
