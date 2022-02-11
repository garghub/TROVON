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
static int F_32 ( struct V_1 * V_9 , unsigned long V_34 )
{
return F_33 ( V_9 , ( int ) V_34 ) ;
}
static T_1 F_34 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_32 ) ;
}
static int F_35 ( struct V_1 * V_9 , unsigned long V_35 )
{
return F_36 ( V_9 , ( unsigned int ) V_35 ) ;
}
static T_1 F_37 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_35 ) ;
}
static int F_38 ( struct V_1 * V_9 , unsigned long V_36 )
{
V_9 -> V_37 = V_36 ;
return 0 ;
}
static T_1 F_39 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
if ( ! F_40 ( V_17 ) )
return - V_18 ;
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_38 ) ;
}
static T_1 F_41 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
struct V_9 * V_9 = F_9 ( V_14 ) ;
T_2 V_38 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_9 -> V_16 , V_17 ) )
return - V_18 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_38 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_42 ( V_14 , V_8 , V_38 ) ;
F_14 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_43 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_12 () )
return F_13 () ;
if ( V_14 -> V_39 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_39 ) ;
F_14 () ;
return V_10 ;
}
static int F_44 ( struct V_1 * V_9 , unsigned long V_40 )
{
F_45 ( V_9 , ( int ) V_40 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_44 ) ;
}
static T_1 F_47 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
struct V_41 V_42 ;
V_10 = F_48 ( V_14 , & V_42 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_42 . V_43 , V_42 . V_44 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_49 ( const struct V_5 * V_45 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_46 )
{
struct V_1 * V_2 = F_4 ( V_45 ) ;
T_1 V_10 = - V_11 ;
F_50 ( V_46 > sizeof( struct V_47 ) ||
V_46 % sizeof( V_48 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_47 V_49 ;
const struct V_47 * V_50 = F_51 ( V_2 , & V_49 ) ;
V_10 = sprintf ( V_8 , V_51 , * ( V_48 * ) ( ( ( V_52 * ) V_50 ) + V_46 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_52 ( struct V_53 * V_54 , struct V_55 * V_7 ,
char * V_8 )
{
struct V_56 * V_55 = F_53 ( V_7 ) ;
struct V_57 * V_58 = F_54 ( V_54 ) ;
if ( ! V_55 -> V_59 )
return - V_60 ;
return V_55 -> V_59 ( V_58 , V_55 , V_8 ) ;
}
static T_1 F_55 ( struct V_53 * V_54 , struct V_55 * V_7 ,
const char * V_8 , T_2 V_38 )
{
struct V_56 * V_55 = F_53 ( V_7 ) ;
struct V_57 * V_58 = F_54 ( V_54 ) ;
if ( ! V_55 -> V_61 )
return - V_60 ;
return V_55 -> V_61 ( V_58 , V_55 , V_8 , V_38 ) ;
}
static T_1 F_56 ( struct V_57 * V_58 ,
struct V_56 * V_55 , char * V_8 )
{
struct V_62 * V_63 ;
T_3 V_64 ;
T_2 V_13 = 0 ;
int V_65 ;
if ( ! F_57 ( & V_64 , V_66 ) )
return - V_67 ;
F_58 () ;
V_63 = F_59 ( V_58 -> V_62 ) ;
if ( V_63 )
for ( V_65 = 0 ; V_65 < V_63 -> V_13 ; V_65 ++ )
F_60 ( V_63 -> V_68 [ V_65 ] , V_64 ) ;
V_13 += F_61 ( V_8 + V_13 , V_69 , V_64 ) ;
if ( V_69 - V_13 < 3 ) {
F_62 () ;
F_63 ( V_64 ) ;
return - V_11 ;
}
F_62 () ;
F_63 ( V_64 ) ;
V_13 += sprintf ( V_8 + V_13 , L_6 ) ;
return V_13 ;
}
static T_1 F_64 ( struct V_57 * V_58 ,
struct V_56 * V_55 ,
const char * V_8 , T_2 V_13 )
{
struct V_62 * V_70 , * V_63 ;
T_3 V_64 ;
int V_19 , V_71 , V_65 ;
static F_65 ( V_72 ) ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
if ( ! F_66 ( & V_64 , V_66 ) )
return - V_67 ;
V_19 = F_67 ( V_8 , V_13 , F_68 ( V_64 ) , V_73 ) ;
if ( V_19 ) {
F_63 ( V_64 ) ;
return V_19 ;
}
V_63 = F_69 ( F_70 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_66 ) ;
if ( ! V_63 ) {
F_63 ( V_64 ) ;
return - V_67 ;
}
V_65 = 0 ;
F_71 (cpu, mask, cpu_online_mask)
V_63 -> V_68 [ V_65 ++ ] = V_71 ;
if ( V_65 )
V_63 -> V_13 = V_65 ;
else {
F_72 ( V_63 ) ;
V_63 = NULL ;
}
F_73 ( & V_72 ) ;
V_70 = F_74 ( V_58 -> V_62 ,
F_75 ( & V_72 ) ) ;
F_76 ( V_58 -> V_62 , V_63 ) ;
F_77 ( & V_72 ) ;
if ( V_63 )
F_78 ( & V_74 ) ;
if ( V_70 ) {
F_79 ( V_70 , V_75 ) ;
F_80 ( & V_74 ) ;
}
F_63 ( V_64 ) ;
return V_13 ;
}
static T_1 F_81 ( struct V_57 * V_58 ,
struct V_56 * V_7 ,
char * V_8 )
{
struct V_76 * V_77 ;
unsigned long V_78 = 0 ;
F_58 () ;
V_77 = F_59 ( V_58 -> V_79 ) ;
if ( V_77 )
V_78 = ( unsigned long ) V_77 -> V_64 + 1 ;
F_62 () ;
return sprintf ( V_8 , L_7 , V_78 ) ;
}
static void F_82 ( struct V_80 * V_75 )
{
struct V_76 * V_81 = F_83 ( V_75 ,
struct V_76 , V_75 ) ;
F_84 ( V_81 ) ;
}
static T_1 F_85 ( struct V_57 * V_58 ,
struct V_56 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_64 , V_38 ;
struct V_76 * V_81 , * V_82 ;
static F_65 ( V_83 ) ;
int V_84 ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
V_84 = F_11 ( V_8 , 0 , & V_38 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( V_38 ) {
V_64 = V_38 - 1 ;
while ( ( V_64 | ( V_64 >> 1 ) ) != V_64 )
V_64 |= ( V_64 >> 1 ) ;
#if V_85 > 32
if ( V_64 > ( unsigned long ) ( V_86 ) V_64 )
return - V_11 ;
#else
if ( V_64 > ( V_87 - F_86 ( 1 ) )
/ sizeof( struct V_88 ) ) {
return - V_11 ;
}
#endif
V_81 = F_87 ( F_86 ( V_64 + 1 ) ) ;
if ( ! V_81 )
return - V_67 ;
V_81 -> V_64 = V_64 ;
for ( V_38 = 0 ; V_38 <= V_64 ; V_38 ++ )
V_81 -> V_89 [ V_38 ] . V_71 = V_90 ;
} else
V_81 = NULL ;
F_73 ( & V_83 ) ;
V_82 = F_74 ( V_58 -> V_79 ,
F_75 ( & V_83 ) ) ;
F_76 ( V_58 -> V_79 , V_81 ) ;
F_77 ( & V_83 ) ;
if ( V_82 )
F_88 ( & V_82 -> V_75 , F_82 ) ;
return V_13 ;
}
static void F_89 ( struct V_53 * V_54 )
{
struct V_57 * V_58 = F_54 ( V_54 ) ;
#ifdef F_90
struct V_62 * V_63 ;
struct V_76 * V_77 ;
V_63 = F_74 ( V_58 -> V_62 , 1 ) ;
if ( V_63 ) {
F_91 ( V_58 -> V_62 , NULL ) ;
F_79 ( V_63 , V_75 ) ;
}
V_77 = F_74 ( V_58 -> V_79 , 1 ) ;
if ( V_77 ) {
F_91 ( V_58 -> V_79 , NULL ) ;
F_88 ( & V_77 -> V_75 , F_82 ) ;
}
#endif
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
F_92 ( V_58 -> V_2 ) ;
}
static const void * F_93 ( struct V_53 * V_54 )
{
struct V_57 * V_58 = F_54 ( V_54 ) ;
struct V_5 * V_2 = & V_58 -> V_2 -> V_2 ;
const void * V_91 = NULL ;
if ( V_2 -> V_92 && V_2 -> V_92 -> V_93 )
V_91 = V_2 -> V_92 -> V_94 ( V_2 ) ;
return V_91 ;
}
static int F_94 ( struct V_1 * V_9 , int V_95 )
{
struct V_57 * V_58 = V_9 -> V_96 + V_95 ;
struct V_53 * V_54 = & V_58 -> V_54 ;
int error = 0 ;
V_54 -> V_97 = V_9 -> V_98 ;
error = F_95 ( V_54 , & V_99 , NULL ,
L_8 , V_95 ) ;
if ( error )
goto exit;
if ( V_9 -> V_100 ) {
error = F_96 ( V_54 , V_9 -> V_100 ) ;
if ( error )
goto exit;
}
F_97 ( V_54 , V_101 ) ;
F_98 ( V_58 -> V_2 ) ;
return error ;
exit:
F_99 ( V_54 ) ;
return error ;
}
int
F_100 ( struct V_1 * V_9 , int V_102 , int V_103 )
{
#ifdef F_101
int V_65 ;
int error = 0 ;
#ifndef F_90
if ( ! V_9 -> V_100 )
return 0 ;
#endif
for ( V_65 = V_102 ; V_65 < V_103 ; V_65 ++ ) {
error = F_94 ( V_9 , V_65 ) ;
if ( error ) {
V_103 = V_102 ;
break;
}
}
while ( -- V_65 >= V_103 ) {
if ( V_9 -> V_100 )
F_102 ( & V_9 -> V_96 [ V_65 ] . V_54 ,
V_9 -> V_100 ) ;
F_99 ( & V_9 -> V_96 [ V_65 ] . V_54 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_103 ( struct V_53 * V_54 ,
struct V_55 * V_7 , char * V_8 )
{
struct V_104 * V_55 = F_104 ( V_7 ) ;
struct V_105 * V_58 = F_105 ( V_54 ) ;
if ( ! V_55 -> V_59 )
return - V_60 ;
return V_55 -> V_59 ( V_58 , V_55 , V_8 ) ;
}
static T_1 F_106 ( struct V_53 * V_54 ,
struct V_55 * V_7 ,
const char * V_8 , T_2 V_38 )
{
struct V_104 * V_55 = F_104 ( V_7 ) ;
struct V_105 * V_58 = F_105 ( V_54 ) ;
if ( ! V_55 -> V_61 )
return - V_60 ;
return V_55 -> V_61 ( V_58 , V_55 , V_8 , V_38 ) ;
}
static T_1 F_107 ( struct V_105 * V_58 ,
struct V_104 * V_55 ,
char * V_8 )
{
unsigned long V_106 ;
F_108 ( & V_58 -> V_107 ) ;
V_106 = V_58 -> V_106 ;
F_109 ( & V_58 -> V_107 ) ;
return sprintf ( V_8 , L_9 , V_106 ) ;
}
static T_1 F_110 ( char * V_8 , unsigned int V_108 )
{
return sprintf ( V_8 , L_10 , V_108 ) ;
}
static T_1 F_111 ( const char * V_8 , const T_2 V_38 ,
unsigned int * V_109 )
{
unsigned int V_108 ;
int V_19 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_108 = V_110 ;
else {
V_19 = F_112 ( V_8 , 10 , & V_108 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_108 > V_110 )
return - V_11 ;
}
* V_109 = V_108 ;
return V_38 ;
}
static T_1 F_113 ( struct V_105 * V_58 ,
struct V_104 * V_7 ,
char * V_8 )
{
struct V_111 * V_111 = & V_58 -> V_111 ;
return sprintf ( V_8 , L_10 , F_114 ( V_111 -> V_112 ) ) ;
}
static T_1 F_115 ( struct V_105 * V_58 ,
struct V_104 * V_55 ,
const char * V_8 , T_2 V_13 )
{
struct V_111 * V_111 = & V_58 -> V_111 ;
unsigned int V_108 ;
int V_19 ;
V_19 = F_112 ( V_8 , 10 , & V_108 ) ;
if ( V_19 < 0 )
return V_19 ;
V_111 -> V_112 = F_116 ( V_108 ) ;
return V_13 ;
}
static T_1 F_117 ( struct V_105 * V_58 ,
struct V_104 * V_7 ,
char * V_8 )
{
struct V_111 * V_111 = & V_58 -> V_111 ;
return sprintf ( V_8 , L_10 , V_111 -> V_113 - V_111 -> V_114 ) ;
}
static inline unsigned int F_118 ( struct V_105 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_115 ; V_65 ++ )
if ( V_58 == & V_2 -> V_116 [ V_65 ] )
break;
F_119 ( V_65 >= V_2 -> V_115 ) ;
return V_65 ;
}
static T_1 F_120 ( struct V_105 * V_58 ,
struct V_104 * V_55 , char * V_8 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_117 * V_118 ;
T_3 V_64 ;
unsigned long V_95 ;
T_2 V_13 = 0 ;
int V_65 ;
if ( ! F_57 ( & V_64 , V_66 ) )
return - V_67 ;
V_95 = F_118 ( V_58 ) ;
F_58 () ;
V_118 = F_59 ( V_2 -> V_119 ) ;
if ( V_118 ) {
F_121 (i) {
struct V_120 * V_63 =
F_59 ( V_118 -> V_121 [ V_65 ] ) ;
if ( V_63 ) {
int V_122 ;
for ( V_122 = 0 ; V_122 < V_63 -> V_13 ; V_122 ++ ) {
if ( V_63 -> V_123 [ V_122 ] == V_95 ) {
F_60 ( V_65 , V_64 ) ;
break;
}
}
}
}
}
F_62 () ;
V_13 += F_61 ( V_8 + V_13 , V_69 , V_64 ) ;
if ( V_69 - V_13 < 3 ) {
F_63 ( V_64 ) ;
return - V_11 ;
}
F_63 ( V_64 ) ;
V_13 += sprintf ( V_8 + V_13 , L_6 ) ;
return V_13 ;
}
static T_1 F_122 ( struct V_105 * V_58 ,
struct V_104 * V_55 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
unsigned long V_95 ;
T_3 V_64 ;
int V_19 ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
if ( ! F_66 ( & V_64 , V_66 ) )
return - V_67 ;
V_95 = F_118 ( V_58 ) ;
V_19 = F_67 ( V_8 , V_13 , F_68 ( V_64 ) , V_73 ) ;
if ( V_19 ) {
F_63 ( V_64 ) ;
return V_19 ;
}
V_19 = F_123 ( V_2 , V_64 , V_95 ) ;
F_63 ( V_64 ) ;
return V_19 ? : V_13 ;
}
static void F_124 ( struct V_53 * V_54 )
{
struct V_105 * V_58 = F_105 ( V_54 ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
F_92 ( V_58 -> V_2 ) ;
}
static const void * F_125 ( struct V_53 * V_54 )
{
struct V_105 * V_58 = F_105 ( V_54 ) ;
struct V_5 * V_2 = & V_58 -> V_2 -> V_2 ;
const void * V_91 = NULL ;
if ( V_2 -> V_92 && V_2 -> V_92 -> V_93 )
V_91 = V_2 -> V_92 -> V_94 ( V_2 ) ;
return V_91 ;
}
static int F_126 ( struct V_1 * V_9 , int V_95 )
{
struct V_105 * V_58 = V_9 -> V_116 + V_95 ;
struct V_53 * V_54 = & V_58 -> V_54 ;
int error = 0 ;
V_54 -> V_97 = V_9 -> V_98 ;
error = F_95 ( V_54 , & V_124 , NULL ,
L_13 , V_95 ) ;
if ( error )
goto exit;
#ifdef F_127
error = F_96 ( V_54 , & V_125 ) ;
if ( error )
goto exit;
#endif
F_97 ( V_54 , V_101 ) ;
F_98 ( V_58 -> V_2 ) ;
return 0 ;
exit:
F_99 ( V_54 ) ;
return error ;
}
int
F_128 ( struct V_1 * V_9 , int V_102 , int V_103 )
{
#ifdef F_101
int V_65 ;
int error = 0 ;
for ( V_65 = V_102 ; V_65 < V_103 ; V_65 ++ ) {
error = F_126 ( V_9 , V_65 ) ;
if ( error ) {
V_103 = V_102 ;
break;
}
}
while ( -- V_65 >= V_103 ) {
struct V_105 * V_58 = V_9 -> V_116 + V_65 ;
#ifdef F_127
F_102 ( & V_58 -> V_54 , & V_125 ) ;
#endif
F_99 ( & V_58 -> V_54 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_129 ( struct V_1 * V_9 )
{
int error = 0 , V_126 = 0 , V_127 = 0 , V_128 = 0 , V_129 = 0 ;
#ifdef F_101
V_9 -> V_98 = F_130 ( L_14 ,
NULL , & V_9 -> V_2 . V_54 ) ;
if ( ! V_9 -> V_98 )
return - V_67 ;
V_128 = V_9 -> V_130 ;
#endif
V_129 = V_9 -> V_131 ;
error = F_100 ( V_9 , 0 , V_128 ) ;
if ( error )
goto error;
V_127 = V_128 ;
error = F_128 ( V_9 , 0 , V_129 ) ;
if ( error )
goto error;
V_126 = V_129 ;
return 0 ;
error:
F_128 ( V_9 , V_126 , 0 ) ;
F_100 ( V_9 , V_127 , 0 ) ;
return error ;
}
static void F_131 ( struct V_1 * V_9 )
{
int V_128 = 0 , V_129 = 0 ;
#ifdef F_101
V_128 = V_9 -> V_130 ;
#endif
V_129 = V_9 -> V_131 ;
F_100 ( V_9 , V_128 , 0 ) ;
F_128 ( V_9 , V_129 , 0 ) ;
#ifdef F_101
F_132 ( V_9 -> V_98 ) ;
#endif
}
static bool F_133 ( void )
{
struct V_9 * V_9 = V_132 -> V_133 -> V_134 ;
return F_10 ( V_9 -> V_16 , V_135 ) ;
}
static void * F_134 ( void )
{
struct V_9 * V_91 = V_132 -> V_133 -> V_134 ;
#ifdef F_135
if ( V_91 )
F_136 ( & V_91 -> V_136 ) ;
#endif
return V_91 ;
}
static const void * F_137 ( void )
{
return & V_137 ;
}
static const void * F_138 ( struct V_138 * V_139 )
{
return F_139 ( V_139 ) ;
}
static int F_140 ( struct V_5 * V_45 , struct V_140 * V_141 )
{
struct V_1 * V_2 = F_4 ( V_45 ) ;
int V_142 ;
V_142 = F_141 ( V_141 , L_15 , V_2 -> V_143 ) ;
if ( V_142 )
goto exit;
V_142 = F_141 ( V_141 , L_16 , V_2 -> V_144 ) ;
exit:
return V_142 ;
}
static void F_142 ( struct V_5 * V_45 )
{
struct V_1 * V_2 = F_4 ( V_45 ) ;
F_119 ( V_2 -> V_3 != V_145 ) ;
F_72 ( V_2 -> V_39 ) ;
F_143 ( V_2 ) ;
}
static const void * F_144 ( struct V_5 * V_45 )
{
struct V_1 * V_2 ;
V_2 = F_83 ( V_45 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_145 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_146 ( & V_2 -> V_54 ) ;
F_131 ( V_9 ) ;
F_147 ( V_2 , false ) ;
F_148 ( V_2 ) ;
}
int F_149 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_146 * * V_147 = V_9 -> V_148 ;
int error = 0 ;
F_150 ( V_2 ) ;
V_2 -> V_92 = & V_149 ;
V_2 -> V_150 = V_9 ;
V_2 -> V_147 = V_147 ;
F_151 ( V_2 , L_17 , V_9 -> V_143 ) ;
#ifdef F_101
if ( * V_147 )
V_147 ++ ;
* V_147 ++ = & V_151 ;
#if F_152 ( V_152 ) || F_152 ( V_153 )
if ( V_9 -> V_154 )
* V_147 ++ = & V_155 ;
#if F_152 ( V_152 )
else if ( V_9 -> V_156 )
* V_147 ++ = & V_155 ;
#endif
#endif
#endif
error = F_153 ( V_2 ) ;
if ( error )
return error ;
error = F_129 ( V_9 ) ;
if ( error ) {
F_148 ( V_2 ) ;
return error ;
}
F_147 ( V_2 , true ) ;
return error ;
}
int F_154 ( struct V_157 * V_158 ,
const void * V_91 )
{
return F_155 ( & V_149 , V_158 , V_91 ) ;
}
void F_156 ( struct V_157 * V_158 ,
const void * V_91 )
{
F_157 ( & V_149 , V_158 , V_91 ) ;
}
int T_4 F_158 ( void )
{
F_159 ( & V_159 ) ;
return F_160 ( & V_149 ) ;
}
