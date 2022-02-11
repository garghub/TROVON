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
static int F_18 ( struct V_1 * V_9 , unsigned long V_23 )
{
if ( ! F_19 ( V_9 ) )
return - V_11 ;
return F_20 ( V_9 , ( bool ) V_23 ) ;
}
static T_1 F_21 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_18 ) ;
}
static T_1 F_22 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_19 ( V_14 ) ) {
return sprintf ( V_8 , V_24 , ! ! F_23 ( V_14 ) ) ;
}
return - V_11 ;
}
static T_1 F_24 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_19 ( V_14 ) ) {
struct V_25 V_26 ;
if ( ! F_25 ( V_14 , & V_26 ) )
V_10 = sprintf ( V_8 , V_27 , F_26 ( & V_26 ) ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_27 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_19 ( V_14 ) ) {
struct V_25 V_26 ;
if ( ! F_25 ( V_14 , & V_26 ) ) {
const char * V_28 ;
switch ( V_26 . V_28 ) {
case V_29 :
V_28 = L_1 ;
break;
case V_30 :
V_28 = L_2 ;
break;
default:
V_28 = L_3 ;
break;
}
V_10 = sprintf ( V_8 , L_4 , V_28 ) ;
}
}
F_14 () ;
return V_10 ;
}
static T_1 F_28 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
if ( F_19 ( V_14 ) )
return sprintf ( V_8 , V_24 , ! ! F_29 ( V_14 ) ) ;
return - V_11 ;
}
static T_1 F_30 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
unsigned char V_31 ;
F_5 ( & V_12 ) ;
V_31 = V_14 -> V_31 ;
if ( ! F_19 ( V_14 ) )
V_31 = V_32 ;
F_6 ( & V_12 ) ;
if ( V_31 >= F_31 ( V_33 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_33 [ V_31 ] ) ;
}
static T_1 F_32 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
return sprintf ( V_8 , V_24 ,
F_33 ( & V_14 -> V_34 ) ) ;
}
static int F_34 ( struct V_1 * V_9 , unsigned long V_35 )
{
return F_35 ( V_9 , ( int ) V_35 ) ;
}
static T_1 F_36 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_34 ) ;
}
static int F_37 ( struct V_1 * V_9 , unsigned long V_36 )
{
return F_38 ( V_9 , ( unsigned int ) V_36 ) ;
}
static T_1 F_39 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_37 ) ;
}
static int F_40 ( struct V_1 * V_9 , unsigned long V_37 )
{
V_9 -> V_38 = V_37 ;
return 0 ;
}
static T_1 F_41 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_42 ( V_17 ) )
return - V_18 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_40 ) ;
}
static T_1 F_43 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_9 * V_9 = F_9 ( V_14 ) ;
T_2 V_39 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_9 -> V_16 , V_17 ) )
return - V_18 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_39 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_44 ( V_14 , V_8 , V_39 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_45 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_40 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_40 ) ;
F_14 () ;
return V_10 ;
}
static int F_46 ( struct V_1 * V_9 , unsigned long V_41 )
{
F_47 ( V_9 , ( int ) V_41 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_46 ) ;
}
static T_1 F_49 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_42 V_43 ;
V_10 = F_50 ( V_14 , & V_43 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_43 . V_44 , V_43 . V_45 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_51 ( const struct V_5 * V_46 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_47 )
{
struct V_1 * V_2 = F_4 ( V_46 ) ;
T_1 V_10 = - V_11 ;
F_52 ( V_47 > sizeof( struct V_48 ) ||
V_47 % sizeof( V_49 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_48 V_50 ;
const struct V_48 * V_51 = F_53 ( V_2 , & V_50 ) ;
V_10 = sprintf ( V_8 , V_52 , * ( V_49 * ) ( ( ( V_53 * ) V_51 ) + V_47 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_54 ( struct V_54 * V_55 , struct V_56 * V_7 ,
char * V_8 )
{
struct V_57 * V_56 = F_55 ( V_7 ) ;
struct V_58 * V_59 = F_56 ( V_55 ) ;
if ( ! V_56 -> V_60 )
return - V_61 ;
return V_56 -> V_60 ( V_59 , V_56 , V_8 ) ;
}
static T_1 F_57 ( struct V_54 * V_55 , struct V_56 * V_7 ,
const char * V_8 , T_2 V_39 )
{
struct V_57 * V_56 = F_55 ( V_7 ) ;
struct V_58 * V_59 = F_56 ( V_55 ) ;
if ( ! V_56 -> V_62 )
return - V_61 ;
return V_56 -> V_62 ( V_59 , V_56 , V_8 , V_39 ) ;
}
static T_1 F_58 ( struct V_58 * V_59 ,
struct V_57 * V_56 , char * V_8 )
{
struct V_63 * V_64 ;
T_3 V_65 ;
T_2 V_13 = 0 ;
int V_66 ;
if ( ! F_59 ( & V_65 , V_67 ) )
return - V_68 ;
F_60 () ;
V_64 = F_61 ( V_59 -> V_63 ) ;
if ( V_64 )
for ( V_66 = 0 ; V_66 < V_64 -> V_13 ; V_66 ++ )
F_62 ( V_64 -> V_69 [ V_66 ] , V_65 ) ;
V_13 += F_63 ( V_8 + V_13 , V_70 , V_65 ) ;
if ( V_70 - V_13 < 3 ) {
F_64 () ;
F_65 ( V_65 ) ;
return - V_11 ;
}
F_64 () ;
F_65 ( V_65 ) ;
V_13 += sprintf ( V_8 + V_13 , L_6 ) ;
return V_13 ;
}
static T_1 F_66 ( struct V_58 * V_59 ,
struct V_57 * V_56 ,
const char * V_8 , T_2 V_13 )
{
struct V_63 * V_71 , * V_64 ;
T_3 V_65 ;
int V_19 , V_72 , V_66 ;
static F_67 ( V_73 ) ;
if ( ! F_42 ( V_17 ) )
return - V_18 ;
if ( ! F_68 ( & V_65 , V_67 ) )
return - V_68 ;
V_19 = F_69 ( V_8 , V_13 , F_70 ( V_65 ) , V_74 ) ;
if ( V_19 ) {
F_65 ( V_65 ) ;
return V_19 ;
}
V_64 = F_71 ( F_72 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_67 ) ;
if ( ! V_64 ) {
F_65 ( V_65 ) ;
return - V_68 ;
}
V_66 = 0 ;
F_73 (cpu, mask, cpu_online_mask)
V_64 -> V_69 [ V_66 ++ ] = V_72 ;
if ( V_66 )
V_64 -> V_13 = V_66 ;
else {
F_74 ( V_64 ) ;
V_64 = NULL ;
}
F_75 ( & V_73 ) ;
V_71 = F_76 ( V_59 -> V_63 ,
F_77 ( & V_73 ) ) ;
F_78 ( V_59 -> V_63 , V_64 ) ;
F_79 ( & V_73 ) ;
if ( V_64 )
F_80 ( & V_75 ) ;
if ( V_71 ) {
F_81 ( V_71 , V_76 ) ;
F_82 ( & V_75 ) ;
}
F_65 ( V_65 ) ;
return V_13 ;
}
static T_1 F_83 ( struct V_58 * V_59 ,
struct V_57 * V_7 ,
char * V_8 )
{
struct V_77 * V_78 ;
unsigned long V_79 = 0 ;
F_60 () ;
V_78 = F_61 ( V_59 -> V_80 ) ;
if ( V_78 )
V_79 = ( unsigned long ) V_78 -> V_65 + 1 ;
F_64 () ;
return sprintf ( V_8 , L_7 , V_79 ) ;
}
static void F_84 ( struct V_81 * V_76 )
{
struct V_77 * V_82 = F_85 ( V_76 ,
struct V_77 , V_76 ) ;
F_86 ( V_82 ) ;
}
static T_1 F_87 ( struct V_58 * V_59 ,
struct V_57 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_65 , V_39 ;
struct V_77 * V_82 , * V_83 ;
static F_67 ( V_84 ) ;
int V_85 ;
if ( ! F_42 ( V_17 ) )
return - V_18 ;
V_85 = F_11 ( V_8 , 0 , & V_39 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( V_39 ) {
V_65 = V_39 - 1 ;
while ( ( V_65 | ( V_65 >> 1 ) ) != V_65 )
V_65 |= ( V_65 >> 1 ) ;
#if V_86 > 32
if ( V_65 > ( unsigned long ) ( V_87 ) V_65 )
return - V_11 ;
#else
if ( V_65 > ( V_88 - F_88 ( 1 ) )
/ sizeof( struct V_89 ) ) {
return - V_11 ;
}
#endif
V_82 = F_89 ( F_88 ( V_65 + 1 ) ) ;
if ( ! V_82 )
return - V_68 ;
V_82 -> V_65 = V_65 ;
for ( V_39 = 0 ; V_39 <= V_65 ; V_39 ++ )
V_82 -> V_90 [ V_39 ] . V_72 = V_91 ;
} else
V_82 = NULL ;
F_75 ( & V_84 ) ;
V_83 = F_76 ( V_59 -> V_80 ,
F_77 ( & V_84 ) ) ;
F_78 ( V_59 -> V_80 , V_82 ) ;
F_79 ( & V_84 ) ;
if ( V_83 )
F_90 ( & V_83 -> V_76 , F_84 ) ;
return V_13 ;
}
static void F_91 ( struct V_54 * V_55 )
{
struct V_58 * V_59 = F_56 ( V_55 ) ;
#ifdef F_92
struct V_63 * V_64 ;
struct V_77 * V_78 ;
V_64 = F_76 ( V_59 -> V_63 , 1 ) ;
if ( V_64 ) {
F_93 ( V_59 -> V_63 , NULL ) ;
F_81 ( V_64 , V_76 ) ;
}
V_78 = F_76 ( V_59 -> V_80 , 1 ) ;
if ( V_78 ) {
F_93 ( V_59 -> V_80 , NULL ) ;
F_90 ( & V_78 -> V_76 , F_84 ) ;
}
#endif
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
F_94 ( V_59 -> V_2 ) ;
}
static const void * F_95 ( struct V_54 * V_55 )
{
struct V_58 * V_59 = F_56 ( V_55 ) ;
struct V_5 * V_2 = & V_59 -> V_2 -> V_2 ;
const void * V_92 = NULL ;
if ( V_2 -> V_93 && V_2 -> V_93 -> V_94 )
V_92 = V_2 -> V_93 -> V_95 ( V_2 ) ;
return V_92 ;
}
static int F_96 ( struct V_1 * V_9 , int V_96 )
{
struct V_58 * V_59 = V_9 -> V_97 + V_96 ;
struct V_54 * V_55 = & V_59 -> V_55 ;
int error = 0 ;
V_55 -> V_98 = V_9 -> V_99 ;
error = F_97 ( V_55 , & V_100 , NULL ,
L_8 , V_96 ) ;
if ( error )
goto exit;
if ( V_9 -> V_101 ) {
error = F_98 ( V_55 , V_9 -> V_101 ) ;
if ( error )
goto exit;
}
F_99 ( V_55 , V_102 ) ;
F_100 ( V_59 -> V_2 ) ;
return error ;
exit:
F_101 ( V_55 ) ;
return error ;
}
int
F_102 ( struct V_1 * V_9 , int V_103 , int V_104 )
{
#ifdef F_103
int V_66 ;
int error = 0 ;
#ifndef F_92
if ( ! V_9 -> V_101 )
return 0 ;
#endif
for ( V_66 = V_103 ; V_66 < V_104 ; V_66 ++ ) {
error = F_96 ( V_9 , V_66 ) ;
if ( error ) {
V_104 = V_103 ;
break;
}
}
while ( -- V_66 >= V_104 ) {
if ( V_9 -> V_101 )
F_104 ( & V_9 -> V_97 [ V_66 ] . V_55 ,
V_9 -> V_101 ) ;
F_101 ( & V_9 -> V_97 [ V_66 ] . V_55 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_105 ( struct V_54 * V_55 ,
struct V_56 * V_7 , char * V_8 )
{
struct V_105 * V_56 = F_106 ( V_7 ) ;
struct V_106 * V_59 = F_107 ( V_55 ) ;
if ( ! V_56 -> V_60 )
return - V_61 ;
return V_56 -> V_60 ( V_59 , V_56 , V_8 ) ;
}
static T_1 F_108 ( struct V_54 * V_55 ,
struct V_56 * V_7 ,
const char * V_8 , T_2 V_39 )
{
struct V_105 * V_56 = F_106 ( V_7 ) ;
struct V_106 * V_59 = F_107 ( V_55 ) ;
if ( ! V_56 -> V_62 )
return - V_61 ;
return V_56 -> V_62 ( V_59 , V_56 , V_8 , V_39 ) ;
}
static T_1 F_109 ( struct V_106 * V_59 ,
struct V_105 * V_56 ,
char * V_8 )
{
unsigned long V_107 ;
F_110 ( & V_59 -> V_108 ) ;
V_107 = V_59 -> V_107 ;
F_111 ( & V_59 -> V_108 ) ;
return sprintf ( V_8 , L_9 , V_107 ) ;
}
static T_1 F_112 ( char * V_8 , unsigned int V_109 )
{
return sprintf ( V_8 , L_10 , V_109 ) ;
}
static T_1 F_113 ( const char * V_8 , const T_2 V_39 ,
unsigned int * V_110 )
{
unsigned int V_109 ;
int V_19 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_109 = V_111 ;
else {
V_19 = F_114 ( V_8 , 10 , & V_109 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_109 > V_111 )
return - V_11 ;
}
* V_110 = V_109 ;
return V_39 ;
}
static T_1 F_115 ( struct V_106 * V_59 ,
struct V_105 * V_7 ,
char * V_8 )
{
struct V_112 * V_112 = & V_59 -> V_112 ;
return sprintf ( V_8 , L_10 , F_116 ( V_112 -> V_113 ) ) ;
}
static T_1 F_117 ( struct V_106 * V_59 ,
struct V_105 * V_56 ,
const char * V_8 , T_2 V_13 )
{
struct V_112 * V_112 = & V_59 -> V_112 ;
unsigned int V_109 ;
int V_19 ;
V_19 = F_114 ( V_8 , 10 , & V_109 ) ;
if ( V_19 < 0 )
return V_19 ;
V_112 -> V_113 = F_118 ( V_109 ) ;
return V_13 ;
}
static T_1 F_119 ( struct V_106 * V_59 ,
struct V_105 * V_7 ,
char * V_8 )
{
struct V_112 * V_112 = & V_59 -> V_112 ;
return sprintf ( V_8 , L_10 , V_112 -> V_114 - V_112 -> V_115 ) ;
}
static unsigned int F_120 ( struct V_106 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
unsigned int V_66 ;
V_66 = V_59 - V_2 -> V_116 ;
F_121 ( V_66 >= V_2 -> V_117 ) ;
return V_66 ;
}
static T_1 F_122 ( struct V_106 * V_59 ,
struct V_105 * V_56 , char * V_8 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_118 * V_119 ;
T_3 V_65 ;
unsigned long V_96 ;
T_2 V_13 = 0 ;
int V_66 ;
if ( ! F_59 ( & V_65 , V_67 ) )
return - V_68 ;
V_96 = F_120 ( V_59 ) ;
F_60 () ;
V_119 = F_61 ( V_2 -> V_120 ) ;
if ( V_119 ) {
F_123 (i) {
struct V_121 * V_64 =
F_61 ( V_119 -> V_122 [ V_66 ] ) ;
if ( V_64 ) {
int V_123 ;
for ( V_123 = 0 ; V_123 < V_64 -> V_13 ; V_123 ++ ) {
if ( V_64 -> V_124 [ V_123 ] == V_96 ) {
F_62 ( V_66 , V_65 ) ;
break;
}
}
}
}
}
F_64 () ;
V_13 += F_63 ( V_8 + V_13 , V_70 , V_65 ) ;
if ( V_70 - V_13 < 3 ) {
F_65 ( V_65 ) ;
return - V_11 ;
}
F_65 ( V_65 ) ;
V_13 += sprintf ( V_8 + V_13 , L_6 ) ;
return V_13 ;
}
static T_1 F_124 ( struct V_106 * V_59 ,
struct V_105 * V_56 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
unsigned long V_96 ;
T_3 V_65 ;
int V_19 ;
if ( ! F_42 ( V_17 ) )
return - V_18 ;
if ( ! F_68 ( & V_65 , V_67 ) )
return - V_68 ;
V_96 = F_120 ( V_59 ) ;
V_19 = F_69 ( V_8 , V_13 , F_70 ( V_65 ) , V_74 ) ;
if ( V_19 ) {
F_65 ( V_65 ) ;
return V_19 ;
}
V_19 = F_125 ( V_2 , V_65 , V_96 ) ;
F_65 ( V_65 ) ;
return V_19 ? : V_13 ;
}
static void F_126 ( struct V_54 * V_55 )
{
struct V_106 * V_59 = F_107 ( V_55 ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
F_94 ( V_59 -> V_2 ) ;
}
static const void * F_127 ( struct V_54 * V_55 )
{
struct V_106 * V_59 = F_107 ( V_55 ) ;
struct V_5 * V_2 = & V_59 -> V_2 -> V_2 ;
const void * V_92 = NULL ;
if ( V_2 -> V_93 && V_2 -> V_93 -> V_94 )
V_92 = V_2 -> V_93 -> V_95 ( V_2 ) ;
return V_92 ;
}
static int F_128 ( struct V_1 * V_9 , int V_96 )
{
struct V_106 * V_59 = V_9 -> V_116 + V_96 ;
struct V_54 * V_55 = & V_59 -> V_55 ;
int error = 0 ;
V_55 -> V_98 = V_9 -> V_99 ;
error = F_97 ( V_55 , & V_125 , NULL ,
L_13 , V_96 ) ;
if ( error )
goto exit;
#ifdef F_129
error = F_98 ( V_55 , & V_126 ) ;
if ( error )
goto exit;
#endif
F_99 ( V_55 , V_102 ) ;
F_100 ( V_59 -> V_2 ) ;
return 0 ;
exit:
F_101 ( V_55 ) ;
return error ;
}
int
F_130 ( struct V_1 * V_9 , int V_103 , int V_104 )
{
#ifdef F_103
int V_66 ;
int error = 0 ;
for ( V_66 = V_103 ; V_66 < V_104 ; V_66 ++ ) {
error = F_128 ( V_9 , V_66 ) ;
if ( error ) {
V_104 = V_103 ;
break;
}
}
while ( -- V_66 >= V_104 ) {
struct V_106 * V_59 = V_9 -> V_116 + V_66 ;
#ifdef F_129
F_104 ( & V_59 -> V_55 , & V_126 ) ;
#endif
F_101 ( & V_59 -> V_55 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_131 ( struct V_1 * V_9 )
{
int error = 0 , V_127 = 0 , V_128 = 0 , V_129 = 0 , V_130 = 0 ;
#ifdef F_103
V_9 -> V_99 = F_132 ( L_14 ,
NULL , & V_9 -> V_2 . V_55 ) ;
if ( ! V_9 -> V_99 )
return - V_68 ;
V_129 = V_9 -> V_131 ;
#endif
V_130 = V_9 -> V_132 ;
error = F_102 ( V_9 , 0 , V_129 ) ;
if ( error )
goto error;
V_128 = V_129 ;
error = F_130 ( V_9 , 0 , V_130 ) ;
if ( error )
goto error;
V_127 = V_130 ;
return 0 ;
error:
F_130 ( V_9 , V_127 , 0 ) ;
F_102 ( V_9 , V_128 , 0 ) ;
return error ;
}
static void F_133 ( struct V_1 * V_9 )
{
int V_129 = 0 , V_130 = 0 ;
#ifdef F_103
V_129 = V_9 -> V_131 ;
#endif
V_130 = V_9 -> V_132 ;
F_102 ( V_9 , V_129 , 0 ) ;
F_130 ( V_9 , V_130 , 0 ) ;
#ifdef F_103
F_134 ( V_9 -> V_99 ) ;
#endif
}
static bool F_135 ( void )
{
struct V_9 * V_9 = V_133 -> V_134 -> V_135 ;
return F_10 ( V_9 -> V_16 , V_136 ) ;
}
static void * F_136 ( void )
{
struct V_9 * V_92 = V_133 -> V_134 -> V_135 ;
#ifdef F_137
if ( V_92 )
F_138 ( & V_92 -> V_137 ) ;
#endif
return V_92 ;
}
static const void * F_139 ( void )
{
return & V_138 ;
}
static const void * F_140 ( struct V_139 * V_140 )
{
return F_141 ( V_140 ) ;
}
static int F_142 ( struct V_5 * V_46 , struct V_141 * V_142 )
{
struct V_1 * V_2 = F_4 ( V_46 ) ;
int V_143 ;
V_143 = F_143 ( V_142 , L_15 , V_2 -> V_144 ) ;
if ( V_143 )
goto exit;
V_143 = F_143 ( V_142 , L_16 , V_2 -> V_145 ) ;
exit:
return V_143 ;
}
static void F_144 ( struct V_5 * V_46 )
{
struct V_1 * V_2 = F_4 ( V_46 ) ;
F_121 ( V_2 -> V_3 != V_146 ) ;
F_74 ( V_2 -> V_40 ) ;
F_145 ( V_2 ) ;
}
static const void * F_146 ( struct V_5 * V_46 )
{
struct V_1 * V_2 ;
V_2 = F_85 ( V_46 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_147 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_148 ( & V_2 -> V_55 ) ;
F_133 ( V_9 ) ;
F_149 ( V_2 , false ) ;
F_150 ( V_2 ) ;
}
int F_151 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_147 * * V_148 = V_9 -> V_149 ;
int error = 0 ;
F_152 ( V_2 ) ;
V_2 -> V_93 = & V_150 ;
V_2 -> V_151 = V_9 ;
V_2 -> V_148 = V_148 ;
F_153 ( V_2 , L_17 , V_9 -> V_144 ) ;
#ifdef F_103
if ( * V_148 )
V_148 ++ ;
* V_148 ++ = & V_152 ;
#if F_154 ( V_153 ) || F_154 ( V_154 )
if ( V_9 -> V_155 )
* V_148 ++ = & V_156 ;
#if F_154 ( V_153 )
else if ( V_9 -> V_157 )
* V_148 ++ = & V_156 ;
#endif
#endif
#endif
error = F_155 ( V_2 ) ;
if ( error )
return error ;
error = F_131 ( V_9 ) ;
if ( error ) {
F_150 ( V_2 ) ;
return error ;
}
F_149 ( V_2 , true ) ;
return error ;
}
int F_156 ( struct V_158 * V_159 ,
const void * V_92 )
{
return F_157 ( & V_150 , V_159 , V_92 ) ;
}
void F_158 ( struct V_158 * V_159 ,
const void * V_92 )
{
F_159 ( & V_150 , V_159 , V_92 ) ;
}
int T_4 F_160 ( void )
{
F_161 ( & V_160 ) ;
return F_162 ( & V_150 ) ;
}
