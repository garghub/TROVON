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
V_10 = sprintf ( V_8 , V_30 , F_30 ( & V_29 ) ) ;
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
unsigned char V_34 ;
F_5 ( & V_12 ) ;
V_34 = V_14 -> V_34 ;
if ( ! F_23 ( V_14 ) )
V_34 = V_35 ;
F_6 ( & V_12 ) ;
if ( V_34 >= F_35 ( V_36 ) )
return - V_11 ;
return sprintf ( V_8 , L_4 , V_36 [ V_34 ] ) ;
}
static T_1 F_36 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
return sprintf ( V_8 , V_21 ,
F_37 ( & V_14 -> V_37 ) ) ;
}
static int F_38 ( struct V_1 * V_2 , unsigned long V_38 )
{
return F_39 ( V_2 , ( int ) V_38 ) ;
}
static T_1 F_40 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_38 ) ;
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_39 )
{
return F_42 ( V_2 , ( unsigned int ) V_39 ) ;
}
static T_1 F_43 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_41 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned long V_40 )
{
V_2 -> V_41 = V_40 ;
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
static int F_47 ( struct V_1 * V_2 , unsigned long V_42 )
{
V_2 -> V_43 = V_42 ;
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
T_2 V_44 = V_13 ;
T_1 V_10 ;
if ( ! F_10 ( V_15 -> V_17 , V_18 ) )
return - V_19 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_44 ;
if ( ! F_12 () )
return F_13 () ;
V_10 = F_50 ( V_14 , V_8 , V_44 ) ;
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
if ( V_14 -> V_45 )
V_10 = sprintf ( V_8 , L_4 , V_14 -> V_45 ) ;
F_14 () ;
return V_10 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned long V_46 )
{
F_53 ( V_2 , ( int ) V_46 ) ;
return 0 ;
}
static T_1 F_54 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_52 ) ;
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
static T_1 F_57 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_14 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( ! F_12 () )
return F_13 () ;
if ( F_1 ( V_14 ) ) {
char V_51 [ V_52 ] ;
V_10 = F_58 ( V_14 , V_51 , sizeof( V_51 ) ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_4 , V_51 ) ;
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
struct V_53 V_7 = {
. V_50 = V_54 ,
. V_55 = V_56 ,
} ;
V_10 = F_60 ( V_14 , & V_7 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_7 . V_57 . V_48 . V_49 ,
V_7 . V_57 . V_48 . V_50 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_61 ( const struct V_5 * V_58 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_59 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
T_1 V_10 = - V_11 ;
F_62 ( V_59 > sizeof( struct V_60 ) ||
V_59 % sizeof( V_61 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_60 V_62 ;
const struct V_60 * V_63 = F_63 ( V_2 , & V_62 ) ;
V_10 = sprintf ( V_8 , V_64 , * ( V_61 * ) ( ( ( V_65 * ) V_63 ) + V_59 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_64 ( struct V_66 * V_67 , struct V_68 * V_7 ,
char * V_8 )
{
struct V_69 * V_68 = F_65 ( V_7 ) ;
struct V_70 * V_71 = F_66 ( V_67 ) ;
if ( ! V_68 -> V_72 )
return - V_73 ;
return V_68 -> V_72 ( V_71 , V_68 , V_8 ) ;
}
static T_1 F_67 ( struct V_66 * V_67 , struct V_68 * V_7 ,
const char * V_8 , T_2 V_44 )
{
struct V_69 * V_68 = F_65 ( V_7 ) ;
struct V_70 * V_71 = F_66 ( V_67 ) ;
if ( ! V_68 -> V_74 )
return - V_73 ;
return V_68 -> V_74 ( V_71 , V_68 , V_8 , V_44 ) ;
}
static T_1 F_68 ( struct V_70 * V_71 ,
struct V_69 * V_68 , char * V_8 )
{
struct V_75 * V_76 ;
T_3 V_77 ;
int V_78 , V_13 ;
if ( ! F_69 ( & V_77 , V_79 ) )
return - V_80 ;
F_70 () ;
V_76 = F_71 ( V_71 -> V_75 ) ;
if ( V_76 )
for ( V_78 = 0 ; V_78 < V_76 -> V_13 ; V_78 ++ )
F_72 ( V_76 -> V_81 [ V_78 ] , V_77 ) ;
V_13 = snprintf ( V_8 , V_82 , L_6 , F_73 ( V_77 ) ) ;
F_74 () ;
F_75 ( V_77 ) ;
return V_13 < V_82 ? V_13 : - V_11 ;
}
static T_1 F_76 ( struct V_70 * V_71 ,
struct V_69 * V_68 ,
const char * V_8 , T_2 V_13 )
{
struct V_75 * V_83 , * V_76 ;
T_3 V_77 ;
int V_20 , V_84 , V_78 ;
static F_77 ( V_85 ) ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
if ( ! F_78 ( & V_77 , V_79 ) )
return - V_80 ;
V_20 = F_79 ( V_8 , V_13 , F_80 ( V_77 ) , V_86 ) ;
if ( V_20 ) {
F_75 ( V_77 ) ;
return V_20 ;
}
V_76 = F_81 ( F_82 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_79 ) ;
if ( ! V_76 ) {
F_75 ( V_77 ) ;
return - V_80 ;
}
V_78 = 0 ;
F_83 (cpu, mask, cpu_online_mask)
V_76 -> V_81 [ V_78 ++ ] = V_84 ;
if ( V_78 )
V_76 -> V_13 = V_78 ;
else {
F_84 ( V_76 ) ;
V_76 = NULL ;
}
F_85 ( & V_85 ) ;
V_83 = F_86 ( V_71 -> V_75 ,
F_87 ( & V_85 ) ) ;
F_88 ( V_71 -> V_75 , V_76 ) ;
F_89 ( & V_85 ) ;
if ( V_76 )
F_90 ( & V_87 ) ;
if ( V_83 ) {
F_91 ( V_83 , V_88 ) ;
F_92 ( & V_87 ) ;
}
F_75 ( V_77 ) ;
return V_13 ;
}
static T_1 F_93 ( struct V_70 * V_71 ,
struct V_69 * V_7 ,
char * V_8 )
{
struct V_89 * V_90 ;
unsigned long V_42 = 0 ;
F_70 () ;
V_90 = F_71 ( V_71 -> V_91 ) ;
if ( V_90 )
V_42 = ( unsigned long ) V_90 -> V_77 + 1 ;
F_74 () ;
return sprintf ( V_8 , L_7 , V_42 ) ;
}
static void F_94 ( struct V_92 * V_88 )
{
struct V_89 * V_93 = F_95 ( V_88 ,
struct V_89 , V_88 ) ;
F_96 ( V_93 ) ;
}
static T_1 F_97 ( struct V_70 * V_71 ,
struct V_69 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_77 , V_44 ;
struct V_89 * V_93 , * V_94 ;
static F_77 ( V_95 ) ;
int V_96 ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
V_96 = F_11 ( V_8 , 0 , & V_44 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_44 ) {
V_77 = V_44 - 1 ;
while ( ( V_77 | ( V_77 >> 1 ) ) != V_77 )
V_77 |= ( V_77 >> 1 ) ;
#if V_97 > 32
if ( V_77 > ( unsigned long ) ( V_98 ) V_77 )
return - V_11 ;
#else
if ( V_77 > ( V_99 - F_98 ( 1 ) )
/ sizeof( struct V_100 ) ) {
return - V_11 ;
}
#endif
V_93 = F_99 ( F_98 ( V_77 + 1 ) ) ;
if ( ! V_93 )
return - V_80 ;
V_93 -> V_77 = V_77 ;
for ( V_44 = 0 ; V_44 <= V_77 ; V_44 ++ )
V_93 -> V_101 [ V_44 ] . V_84 = V_102 ;
} else
V_93 = NULL ;
F_85 ( & V_95 ) ;
V_94 = F_86 ( V_71 -> V_91 ,
F_87 ( & V_95 ) ) ;
F_88 ( V_71 -> V_91 , V_93 ) ;
F_89 ( & V_95 ) ;
if ( V_94 )
F_100 ( & V_94 -> V_88 , F_94 ) ;
return V_13 ;
}
static void F_101 ( struct V_66 * V_67 )
{
struct V_70 * V_71 = F_66 ( V_67 ) ;
#ifdef F_102
struct V_75 * V_76 ;
struct V_89 * V_90 ;
V_76 = F_86 ( V_71 -> V_75 , 1 ) ;
if ( V_76 ) {
F_103 ( V_71 -> V_75 , NULL ) ;
F_91 ( V_76 , V_88 ) ;
}
V_90 = F_86 ( V_71 -> V_91 , 1 ) ;
if ( V_90 ) {
F_103 ( V_71 -> V_91 , NULL ) ;
F_100 ( & V_90 -> V_88 , F_94 ) ;
}
#endif
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
F_104 ( V_71 -> V_2 ) ;
}
static const void * F_105 ( struct V_66 * V_67 )
{
struct V_70 * V_71 = F_66 ( V_67 ) ;
struct V_5 * V_2 = & V_71 -> V_2 -> V_2 ;
const void * V_103 = NULL ;
if ( V_2 -> V_104 && V_2 -> V_104 -> V_105 )
V_103 = V_2 -> V_104 -> V_106 ( V_2 ) ;
return V_103 ;
}
static int F_106 ( struct V_1 * V_2 , int V_107 )
{
struct V_70 * V_71 = V_2 -> V_108 + V_107 ;
struct V_66 * V_67 = & V_71 -> V_67 ;
int error = 0 ;
V_67 -> V_109 = V_2 -> V_110 ;
error = F_107 ( V_67 , & V_111 , NULL ,
L_8 , V_107 ) ;
if ( error )
goto exit;
if ( V_2 -> V_112 ) {
error = F_108 ( V_67 , V_2 -> V_112 ) ;
if ( error )
goto exit;
}
F_109 ( V_67 , V_113 ) ;
F_110 ( V_71 -> V_2 ) ;
return error ;
exit:
F_111 ( V_67 ) ;
return error ;
}
int
F_112 ( struct V_1 * V_2 , int V_114 , int V_115 )
{
#ifdef F_113
int V_78 ;
int error = 0 ;
#ifndef F_102
if ( ! V_2 -> V_112 )
return 0 ;
#endif
for ( V_78 = V_114 ; V_78 < V_115 ; V_78 ++ ) {
error = F_106 ( V_2 , V_78 ) ;
if ( error ) {
V_115 = V_114 ;
break;
}
}
while ( -- V_78 >= V_115 ) {
if ( V_2 -> V_112 )
F_114 ( & V_2 -> V_108 [ V_78 ] . V_67 ,
V_2 -> V_112 ) ;
F_111 ( & V_2 -> V_108 [ V_78 ] . V_67 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_115 ( struct V_66 * V_67 ,
struct V_68 * V_7 , char * V_8 )
{
struct V_116 * V_68 = F_116 ( V_7 ) ;
struct V_117 * V_71 = F_117 ( V_67 ) ;
if ( ! V_68 -> V_72 )
return - V_73 ;
return V_68 -> V_72 ( V_71 , V_68 , V_8 ) ;
}
static T_1 F_118 ( struct V_66 * V_67 ,
struct V_68 * V_7 ,
const char * V_8 , T_2 V_44 )
{
struct V_116 * V_68 = F_116 ( V_7 ) ;
struct V_117 * V_71 = F_117 ( V_67 ) ;
if ( ! V_68 -> V_74 )
return - V_73 ;
return V_68 -> V_74 ( V_71 , V_68 , V_8 , V_44 ) ;
}
static T_1 F_119 ( struct V_117 * V_71 ,
struct V_116 * V_68 ,
char * V_8 )
{
unsigned long V_118 ;
F_120 ( & V_71 -> V_119 ) ;
V_118 = V_71 -> V_118 ;
F_121 ( & V_71 -> V_119 ) ;
return sprintf ( V_8 , L_9 , V_118 ) ;
}
static inline unsigned int F_122 ( struct V_117 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_120 ; V_78 ++ )
if ( V_71 == & V_2 -> V_121 [ V_78 ] )
break;
F_123 ( V_78 >= V_2 -> V_120 ) ;
return V_78 ;
}
static T_1 F_124 ( struct V_117 * V_71 ,
struct V_116 * V_68 ,
char * V_8 )
{
return sprintf ( V_8 , L_7 , V_71 -> V_122 ) ;
}
static T_1 F_125 ( struct V_117 * V_71 ,
struct V_116 * V_68 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
int V_20 , V_107 = F_122 ( V_71 ) ;
V_98 V_123 = 0 ;
V_20 = F_126 ( V_8 , 10 , & V_123 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! F_12 () )
return F_13 () ;
V_20 = - V_124 ;
if ( V_2 -> V_125 -> V_126 )
V_20 = V_2 -> V_125 -> V_126 ( V_2 , V_107 , V_123 ) ;
F_14 () ;
if ( ! V_20 ) {
V_71 -> V_122 = V_123 ;
return V_13 ;
}
return V_20 ;
}
static T_1 F_127 ( char * V_8 , unsigned int V_127 )
{
return sprintf ( V_8 , L_10 , V_127 ) ;
}
static T_1 F_128 ( const char * V_8 , const T_2 V_44 ,
unsigned int * V_128 )
{
unsigned int V_127 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_127 = V_129 ;
else {
V_20 = F_129 ( V_8 , 10 , & V_127 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_127 > V_129 )
return - V_11 ;
}
* V_128 = V_127 ;
return V_44 ;
}
static T_1 F_130 ( struct V_117 * V_71 ,
struct V_116 * V_7 ,
char * V_8 )
{
struct V_130 * V_130 = & V_71 -> V_130 ;
return sprintf ( V_8 , L_10 , F_131 ( V_130 -> V_131 ) ) ;
}
static T_1 F_132 ( struct V_117 * V_71 ,
struct V_116 * V_68 ,
const char * V_8 , T_2 V_13 )
{
struct V_130 * V_130 = & V_71 -> V_130 ;
unsigned int V_127 ;
int V_20 ;
V_20 = F_129 ( V_8 , 10 , & V_127 ) ;
if ( V_20 < 0 )
return V_20 ;
V_130 -> V_131 = F_133 ( V_127 ) ;
return V_13 ;
}
static T_1 F_134 ( struct V_117 * V_71 ,
struct V_116 * V_7 ,
char * V_8 )
{
struct V_130 * V_130 = & V_71 -> V_130 ;
return sprintf ( V_8 , L_10 , V_130 -> V_132 - V_130 -> V_133 ) ;
}
static T_1 F_135 ( struct V_117 * V_71 ,
struct V_116 * V_68 , char * V_8 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_134 * V_135 ;
T_3 V_77 ;
unsigned long V_107 ;
int V_78 , V_13 ;
if ( ! F_69 ( & V_77 , V_79 ) )
return - V_80 ;
V_107 = F_122 ( V_71 ) ;
F_70 () ;
V_135 = F_71 ( V_2 -> V_136 ) ;
if ( V_135 ) {
F_136 (i) {
struct V_137 * V_76 =
F_71 ( V_135 -> V_138 [ V_78 ] ) ;
if ( V_76 ) {
int V_139 ;
for ( V_139 = 0 ; V_139 < V_76 -> V_13 ; V_139 ++ ) {
if ( V_76 -> V_140 [ V_139 ] == V_107 ) {
F_72 ( V_78 , V_77 ) ;
break;
}
}
}
}
}
F_74 () ;
V_13 = snprintf ( V_8 , V_82 , L_6 , F_73 ( V_77 ) ) ;
F_75 ( V_77 ) ;
return V_13 < V_82 ? V_13 : - V_11 ;
}
static T_1 F_137 ( struct V_117 * V_71 ,
struct V_116 * V_68 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
unsigned long V_107 ;
T_3 V_77 ;
int V_20 ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
if ( ! F_78 ( & V_77 , V_79 ) )
return - V_80 ;
V_107 = F_122 ( V_71 ) ;
V_20 = F_79 ( V_8 , V_13 , F_80 ( V_77 ) , V_86 ) ;
if ( V_20 ) {
F_75 ( V_77 ) ;
return V_20 ;
}
V_20 = F_138 ( V_2 , V_77 , V_107 ) ;
F_75 ( V_77 ) ;
return V_20 ? : V_13 ;
}
static void F_139 ( struct V_66 * V_67 )
{
struct V_117 * V_71 = F_117 ( V_67 ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
F_104 ( V_71 -> V_2 ) ;
}
static const void * F_140 ( struct V_66 * V_67 )
{
struct V_117 * V_71 = F_117 ( V_67 ) ;
struct V_5 * V_2 = & V_71 -> V_2 -> V_2 ;
const void * V_103 = NULL ;
if ( V_2 -> V_104 && V_2 -> V_104 -> V_105 )
V_103 = V_2 -> V_104 -> V_106 ( V_2 ) ;
return V_103 ;
}
static int F_141 ( struct V_1 * V_2 , int V_107 )
{
struct V_117 * V_71 = V_2 -> V_121 + V_107 ;
struct V_66 * V_67 = & V_71 -> V_67 ;
int error = 0 ;
V_67 -> V_109 = V_2 -> V_110 ;
error = F_107 ( V_67 , & V_141 , NULL ,
L_13 , V_107 ) ;
if ( error )
goto exit;
#ifdef F_142
error = F_108 ( V_67 , & V_142 ) ;
if ( error )
goto exit;
#endif
F_109 ( V_67 , V_113 ) ;
F_110 ( V_71 -> V_2 ) ;
return 0 ;
exit:
F_111 ( V_67 ) ;
return error ;
}
int
F_143 ( struct V_1 * V_2 , int V_114 , int V_115 )
{
#ifdef F_113
int V_78 ;
int error = 0 ;
for ( V_78 = V_114 ; V_78 < V_115 ; V_78 ++ ) {
error = F_141 ( V_2 , V_78 ) ;
if ( error ) {
V_115 = V_114 ;
break;
}
}
while ( -- V_78 >= V_115 ) {
struct V_117 * V_71 = V_2 -> V_121 + V_78 ;
#ifdef F_142
F_114 ( & V_71 -> V_67 , & V_142 ) ;
#endif
F_111 ( & V_71 -> V_67 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_144 ( struct V_1 * V_2 )
{
int error = 0 , V_143 = 0 , V_144 = 0 , V_145 = 0 , V_146 = 0 ;
#ifdef F_113
V_2 -> V_110 = F_145 ( L_14 ,
NULL , & V_2 -> V_2 . V_67 ) ;
if ( ! V_2 -> V_110 )
return - V_80 ;
V_145 = V_2 -> V_147 ;
#endif
V_146 = V_2 -> V_148 ;
error = F_112 ( V_2 , 0 , V_145 ) ;
if ( error )
goto error;
V_144 = V_145 ;
error = F_143 ( V_2 , 0 , V_146 ) ;
if ( error )
goto error;
V_143 = V_146 ;
return 0 ;
error:
F_143 ( V_2 , V_143 , 0 ) ;
F_112 ( V_2 , V_144 , 0 ) ;
return error ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_145 = 0 , V_146 = 0 ;
#ifdef F_113
V_145 = V_2 -> V_147 ;
#endif
V_146 = V_2 -> V_148 ;
F_112 ( V_2 , V_145 , 0 ) ;
F_143 ( V_2 , V_146 , 0 ) ;
#ifdef F_113
F_147 ( V_2 -> V_110 ) ;
#endif
}
static bool F_148 ( void )
{
struct V_15 * V_15 = V_149 -> V_150 -> V_151 ;
return F_10 ( V_15 -> V_17 , V_152 ) ;
}
static void * F_149 ( void )
{
struct V_15 * V_103 = V_149 -> V_150 -> V_151 ;
#ifdef F_150
if ( V_103 )
F_151 ( & V_103 -> V_153 ) ;
#endif
return V_103 ;
}
static const void * F_152 ( void )
{
return & V_154 ;
}
static const void * F_153 ( struct V_155 * V_156 )
{
return F_154 ( V_156 ) ;
}
static int F_155 ( struct V_5 * V_58 , struct V_157 * V_158 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
int V_159 ;
V_159 = F_156 ( V_158 , L_15 , V_2 -> V_51 ) ;
if ( V_159 )
goto exit;
V_159 = F_156 ( V_158 , L_16 , V_2 -> V_160 ) ;
exit:
return V_159 ;
}
static void F_157 ( struct V_5 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
F_123 ( V_2 -> V_3 != V_161 ) ;
F_84 ( V_2 -> V_45 ) ;
F_158 ( V_2 ) ;
}
static const void * F_159 ( struct V_5 * V_58 )
{
struct V_1 * V_2 ;
V_2 = F_95 ( V_58 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_160 ( struct V_5 * V_2 , const void * V_162 )
{
int V_10 = 0 ;
if ( V_2 -> V_163 )
V_10 = V_2 -> V_163 -> V_164 == V_162 ;
return V_10 == 0 ? V_2 -> V_164 == V_162 : V_10 ;
}
struct V_1 * F_161 ( struct V_165 * V_166 )
{
struct V_5 * V_2 ;
V_2 = F_162 ( & V_167 , NULL , V_166 , F_160 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
void F_163 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_164 ( & V_2 -> V_67 ) ;
F_146 ( V_9 ) ;
F_165 ( V_2 , false ) ;
F_166 ( V_2 ) ;
}
int F_167 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_168 * * V_169 = V_9 -> V_170 ;
int error = 0 ;
F_168 ( V_2 ) ;
V_2 -> V_104 = & V_167 ;
V_2 -> V_171 = V_9 ;
V_2 -> V_169 = V_169 ;
F_169 ( V_2 , L_17 , V_9 -> V_51 ) ;
#ifdef F_113
if ( * V_169 )
V_169 ++ ;
* V_169 ++ = & V_172 ;
#if F_170 ( V_173 ) || F_170 ( V_174 )
if ( V_9 -> V_175 )
* V_169 ++ = & V_176 ;
#if F_170 ( V_173 )
else if ( V_9 -> V_177 )
* V_169 ++ = & V_176 ;
#endif
#endif
#endif
error = F_171 ( V_2 ) ;
if ( error )
return error ;
error = F_144 ( V_9 ) ;
if ( error ) {
F_166 ( V_2 ) ;
return error ;
}
F_165 ( V_2 , true ) ;
return error ;
}
int F_172 ( struct V_178 * V_179 ,
const void * V_103 )
{
return F_173 ( & V_167 , V_179 , V_103 ) ;
}
void F_174 ( struct V_178 * V_179 ,
const void * V_103 )
{
F_175 ( & V_167 , V_179 , V_103 ) ;
}
int T_4 F_176 ( void )
{
F_177 ( & V_180 ) ;
return F_178 ( & V_167 ) ;
}
