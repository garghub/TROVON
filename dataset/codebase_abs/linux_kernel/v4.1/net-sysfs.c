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
struct V_47 V_48 ;
V_10 = F_60 ( V_14 , & V_48 ) ;
if ( ! V_10 )
V_10 = sprintf ( V_8 , L_5 , V_48 . V_49 , V_48 . V_50 ) ;
}
F_14 () ;
return V_10 ;
}
static T_1 F_61 ( const struct V_5 * V_53 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_54 )
{
struct V_1 * V_2 = F_4 ( V_53 ) ;
T_1 V_10 = - V_11 ;
F_62 ( V_54 > sizeof( struct V_55 ) ||
V_54 % sizeof( V_56 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_55 V_57 ;
const struct V_55 * V_58 = F_63 ( V_2 , & V_57 ) ;
V_10 = sprintf ( V_8 , V_59 , * ( V_56 * ) ( ( ( V_60 * ) V_58 ) + V_54 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_64 ( struct V_61 * V_62 , struct V_63 * V_7 ,
char * V_8 )
{
struct V_64 * V_63 = F_65 ( V_7 ) ;
struct V_65 * V_66 = F_66 ( V_62 ) ;
if ( ! V_63 -> V_67 )
return - V_68 ;
return V_63 -> V_67 ( V_66 , V_63 , V_8 ) ;
}
static T_1 F_67 ( struct V_61 * V_62 , struct V_63 * V_7 ,
const char * V_8 , T_2 V_44 )
{
struct V_64 * V_63 = F_65 ( V_7 ) ;
struct V_65 * V_66 = F_66 ( V_62 ) ;
if ( ! V_63 -> V_69 )
return - V_68 ;
return V_63 -> V_69 ( V_66 , V_63 , V_8 , V_44 ) ;
}
static T_1 F_68 ( struct V_65 * V_66 ,
struct V_64 * V_63 , char * V_8 )
{
struct V_70 * V_71 ;
T_3 V_72 ;
int V_73 , V_13 ;
if ( ! F_69 ( & V_72 , V_74 ) )
return - V_75 ;
F_70 () ;
V_71 = F_71 ( V_66 -> V_70 ) ;
if ( V_71 )
for ( V_73 = 0 ; V_73 < V_71 -> V_13 ; V_73 ++ )
F_72 ( V_71 -> V_76 [ V_73 ] , V_72 ) ;
V_13 = snprintf ( V_8 , V_77 , L_6 , F_73 ( V_72 ) ) ;
F_74 () ;
F_75 ( V_72 ) ;
return V_13 < V_77 ? V_13 : - V_11 ;
}
static T_1 F_76 ( struct V_65 * V_66 ,
struct V_64 * V_63 ,
const char * V_8 , T_2 V_13 )
{
struct V_70 * V_78 , * V_71 ;
T_3 V_72 ;
int V_20 , V_79 , V_73 ;
static F_77 ( V_80 ) ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
if ( ! F_78 ( & V_72 , V_74 ) )
return - V_75 ;
V_20 = F_79 ( V_8 , V_13 , F_80 ( V_72 ) , V_81 ) ;
if ( V_20 ) {
F_75 ( V_72 ) ;
return V_20 ;
}
V_71 = F_81 ( F_82 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_74 ) ;
if ( ! V_71 ) {
F_75 ( V_72 ) ;
return - V_75 ;
}
V_73 = 0 ;
F_83 (cpu, mask, cpu_online_mask)
V_71 -> V_76 [ V_73 ++ ] = V_79 ;
if ( V_73 )
V_71 -> V_13 = V_73 ;
else {
F_84 ( V_71 ) ;
V_71 = NULL ;
}
F_85 ( & V_80 ) ;
V_78 = F_86 ( V_66 -> V_70 ,
F_87 ( & V_80 ) ) ;
F_88 ( V_66 -> V_70 , V_71 ) ;
F_89 ( & V_80 ) ;
if ( V_71 )
F_90 ( & V_82 ) ;
if ( V_78 ) {
F_91 ( V_78 , V_83 ) ;
F_92 ( & V_82 ) ;
}
F_75 ( V_72 ) ;
return V_13 ;
}
static T_1 F_93 ( struct V_65 * V_66 ,
struct V_64 * V_7 ,
char * V_8 )
{
struct V_84 * V_85 ;
unsigned long V_42 = 0 ;
F_70 () ;
V_85 = F_71 ( V_66 -> V_86 ) ;
if ( V_85 )
V_42 = ( unsigned long ) V_85 -> V_72 + 1 ;
F_74 () ;
return sprintf ( V_8 , L_7 , V_42 ) ;
}
static void F_94 ( struct V_87 * V_83 )
{
struct V_84 * V_88 = F_95 ( V_83 ,
struct V_84 , V_83 ) ;
F_96 ( V_88 ) ;
}
static T_1 F_97 ( struct V_65 * V_66 ,
struct V_64 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_72 , V_44 ;
struct V_84 * V_88 , * V_89 ;
static F_77 ( V_90 ) ;
int V_91 ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
V_91 = F_11 ( V_8 , 0 , & V_44 ) ;
if ( V_91 < 0 )
return V_91 ;
if ( V_44 ) {
V_72 = V_44 - 1 ;
while ( ( V_72 | ( V_72 >> 1 ) ) != V_72 )
V_72 |= ( V_72 >> 1 ) ;
#if V_92 > 32
if ( V_72 > ( unsigned long ) ( V_93 ) V_72 )
return - V_11 ;
#else
if ( V_72 > ( V_94 - F_98 ( 1 ) )
/ sizeof( struct V_95 ) ) {
return - V_11 ;
}
#endif
V_88 = F_99 ( F_98 ( V_72 + 1 ) ) ;
if ( ! V_88 )
return - V_75 ;
V_88 -> V_72 = V_72 ;
for ( V_44 = 0 ; V_44 <= V_72 ; V_44 ++ )
V_88 -> V_96 [ V_44 ] . V_79 = V_97 ;
} else
V_88 = NULL ;
F_85 ( & V_90 ) ;
V_89 = F_86 ( V_66 -> V_86 ,
F_87 ( & V_90 ) ) ;
F_88 ( V_66 -> V_86 , V_88 ) ;
F_89 ( & V_90 ) ;
if ( V_89 )
F_100 ( & V_89 -> V_83 , F_94 ) ;
return V_13 ;
}
static void F_101 ( struct V_61 * V_62 )
{
struct V_65 * V_66 = F_66 ( V_62 ) ;
#ifdef F_102
struct V_70 * V_71 ;
struct V_84 * V_85 ;
V_71 = F_86 ( V_66 -> V_70 , 1 ) ;
if ( V_71 ) {
F_103 ( V_66 -> V_70 , NULL ) ;
F_91 ( V_71 , V_83 ) ;
}
V_85 = F_86 ( V_66 -> V_86 , 1 ) ;
if ( V_85 ) {
F_103 ( V_66 -> V_86 , NULL ) ;
F_100 ( & V_85 -> V_83 , F_94 ) ;
}
#endif
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
F_104 ( V_66 -> V_2 ) ;
}
static const void * F_105 ( struct V_61 * V_62 )
{
struct V_65 * V_66 = F_66 ( V_62 ) ;
struct V_5 * V_2 = & V_66 -> V_2 -> V_2 ;
const void * V_98 = NULL ;
if ( V_2 -> V_99 && V_2 -> V_99 -> V_100 )
V_98 = V_2 -> V_99 -> V_101 ( V_2 ) ;
return V_98 ;
}
static int F_106 ( struct V_1 * V_2 , int V_102 )
{
struct V_65 * V_66 = V_2 -> V_103 + V_102 ;
struct V_61 * V_62 = & V_66 -> V_62 ;
int error = 0 ;
V_62 -> V_104 = V_2 -> V_105 ;
error = F_107 ( V_62 , & V_106 , NULL ,
L_8 , V_102 ) ;
if ( error )
goto exit;
if ( V_2 -> V_107 ) {
error = F_108 ( V_62 , V_2 -> V_107 ) ;
if ( error )
goto exit;
}
F_109 ( V_62 , V_108 ) ;
F_110 ( V_66 -> V_2 ) ;
return error ;
exit:
F_111 ( V_62 ) ;
return error ;
}
int
F_112 ( struct V_1 * V_2 , int V_109 , int V_110 )
{
#ifdef F_113
int V_73 ;
int error = 0 ;
#ifndef F_102
if ( ! V_2 -> V_107 )
return 0 ;
#endif
for ( V_73 = V_109 ; V_73 < V_110 ; V_73 ++ ) {
error = F_106 ( V_2 , V_73 ) ;
if ( error ) {
V_110 = V_109 ;
break;
}
}
while ( -- V_73 >= V_110 ) {
if ( V_2 -> V_107 )
F_114 ( & V_2 -> V_103 [ V_73 ] . V_62 ,
V_2 -> V_107 ) ;
F_111 ( & V_2 -> V_103 [ V_73 ] . V_62 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static T_1 F_115 ( struct V_61 * V_62 ,
struct V_63 * V_7 , char * V_8 )
{
struct V_111 * V_63 = F_116 ( V_7 ) ;
struct V_112 * V_66 = F_117 ( V_62 ) ;
if ( ! V_63 -> V_67 )
return - V_68 ;
return V_63 -> V_67 ( V_66 , V_63 , V_8 ) ;
}
static T_1 F_118 ( struct V_61 * V_62 ,
struct V_63 * V_7 ,
const char * V_8 , T_2 V_44 )
{
struct V_111 * V_63 = F_116 ( V_7 ) ;
struct V_112 * V_66 = F_117 ( V_62 ) ;
if ( ! V_63 -> V_69 )
return - V_68 ;
return V_63 -> V_69 ( V_66 , V_63 , V_8 , V_44 ) ;
}
static T_1 F_119 ( struct V_112 * V_66 ,
struct V_111 * V_63 ,
char * V_8 )
{
unsigned long V_113 ;
F_120 ( & V_66 -> V_114 ) ;
V_113 = V_66 -> V_113 ;
F_121 ( & V_66 -> V_114 ) ;
return sprintf ( V_8 , L_9 , V_113 ) ;
}
static inline unsigned int F_122 ( struct V_112 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_115 ; V_73 ++ )
if ( V_66 == & V_2 -> V_116 [ V_73 ] )
break;
F_123 ( V_73 >= V_2 -> V_115 ) ;
return V_73 ;
}
static T_1 F_124 ( struct V_112 * V_66 ,
struct V_111 * V_63 ,
char * V_8 )
{
return sprintf ( V_8 , L_7 , V_66 -> V_117 ) ;
}
static T_1 F_125 ( struct V_112 * V_66 ,
struct V_111 * V_63 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_20 , V_102 = F_122 ( V_66 ) ;
V_93 V_118 = 0 ;
V_20 = F_126 ( V_8 , 10 , & V_118 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( ! F_12 () )
return F_13 () ;
V_20 = - V_119 ;
if ( V_2 -> V_120 -> V_121 )
V_20 = V_2 -> V_120 -> V_121 ( V_2 , V_102 , V_118 ) ;
F_14 () ;
if ( ! V_20 ) {
V_66 -> V_117 = V_118 ;
return V_13 ;
}
return V_20 ;
}
static T_1 F_127 ( char * V_8 , unsigned int V_122 )
{
return sprintf ( V_8 , L_10 , V_122 ) ;
}
static T_1 F_128 ( const char * V_8 , const T_2 V_44 ,
unsigned int * V_123 )
{
unsigned int V_122 ;
int V_20 ;
if ( ! strcmp ( V_8 , L_11 ) || ! strcmp ( V_8 , L_12 ) )
V_122 = V_124 ;
else {
V_20 = F_129 ( V_8 , 10 , & V_122 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_122 > V_124 )
return - V_11 ;
}
* V_123 = V_122 ;
return V_44 ;
}
static T_1 F_130 ( struct V_112 * V_66 ,
struct V_111 * V_7 ,
char * V_8 )
{
struct V_125 * V_125 = & V_66 -> V_125 ;
return sprintf ( V_8 , L_10 , F_131 ( V_125 -> V_126 ) ) ;
}
static T_1 F_132 ( struct V_112 * V_66 ,
struct V_111 * V_63 ,
const char * V_8 , T_2 V_13 )
{
struct V_125 * V_125 = & V_66 -> V_125 ;
unsigned int V_122 ;
int V_20 ;
V_20 = F_129 ( V_8 , 10 , & V_122 ) ;
if ( V_20 < 0 )
return V_20 ;
V_125 -> V_126 = F_133 ( V_122 ) ;
return V_13 ;
}
static T_1 F_134 ( struct V_112 * V_66 ,
struct V_111 * V_7 ,
char * V_8 )
{
struct V_125 * V_125 = & V_66 -> V_125 ;
return sprintf ( V_8 , L_10 , V_125 -> V_127 - V_125 -> V_128 ) ;
}
static T_1 F_135 ( struct V_112 * V_66 ,
struct V_111 * V_63 , char * V_8 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_129 * V_130 ;
T_3 V_72 ;
unsigned long V_102 ;
int V_73 , V_13 ;
if ( ! F_69 ( & V_72 , V_74 ) )
return - V_75 ;
V_102 = F_122 ( V_66 ) ;
F_70 () ;
V_130 = F_71 ( V_2 -> V_131 ) ;
if ( V_130 ) {
F_136 (i) {
struct V_132 * V_71 =
F_71 ( V_130 -> V_133 [ V_73 ] ) ;
if ( V_71 ) {
int V_134 ;
for ( V_134 = 0 ; V_134 < V_71 -> V_13 ; V_134 ++ ) {
if ( V_71 -> V_135 [ V_134 ] == V_102 ) {
F_72 ( V_73 , V_72 ) ;
break;
}
}
}
}
}
F_74 () ;
V_13 = snprintf ( V_8 , V_77 , L_6 , F_73 ( V_72 ) ) ;
F_75 ( V_72 ) ;
return V_13 < V_77 ? V_13 : - V_11 ;
}
static T_1 F_137 ( struct V_112 * V_66 ,
struct V_111 * V_63 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
unsigned long V_102 ;
T_3 V_72 ;
int V_20 ;
if ( ! F_46 ( V_18 ) )
return - V_19 ;
if ( ! F_78 ( & V_72 , V_74 ) )
return - V_75 ;
V_102 = F_122 ( V_66 ) ;
V_20 = F_79 ( V_8 , V_13 , F_80 ( V_72 ) , V_81 ) ;
if ( V_20 ) {
F_75 ( V_72 ) ;
return V_20 ;
}
V_20 = F_138 ( V_2 , V_72 , V_102 ) ;
F_75 ( V_72 ) ;
return V_20 ? : V_13 ;
}
static void F_139 ( struct V_61 * V_62 )
{
struct V_112 * V_66 = F_117 ( V_62 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
F_104 ( V_66 -> V_2 ) ;
}
static const void * F_140 ( struct V_61 * V_62 )
{
struct V_112 * V_66 = F_117 ( V_62 ) ;
struct V_5 * V_2 = & V_66 -> V_2 -> V_2 ;
const void * V_98 = NULL ;
if ( V_2 -> V_99 && V_2 -> V_99 -> V_100 )
V_98 = V_2 -> V_99 -> V_101 ( V_2 ) ;
return V_98 ;
}
static int F_141 ( struct V_1 * V_2 , int V_102 )
{
struct V_112 * V_66 = V_2 -> V_116 + V_102 ;
struct V_61 * V_62 = & V_66 -> V_62 ;
int error = 0 ;
V_62 -> V_104 = V_2 -> V_105 ;
error = F_107 ( V_62 , & V_136 , NULL ,
L_13 , V_102 ) ;
if ( error )
goto exit;
#ifdef F_142
error = F_108 ( V_62 , & V_137 ) ;
if ( error )
goto exit;
#endif
F_109 ( V_62 , V_108 ) ;
F_110 ( V_66 -> V_2 ) ;
return 0 ;
exit:
F_111 ( V_62 ) ;
return error ;
}
int
F_143 ( struct V_1 * V_2 , int V_109 , int V_110 )
{
#ifdef F_113
int V_73 ;
int error = 0 ;
for ( V_73 = V_109 ; V_73 < V_110 ; V_73 ++ ) {
error = F_141 ( V_2 , V_73 ) ;
if ( error ) {
V_110 = V_109 ;
break;
}
}
while ( -- V_73 >= V_110 ) {
struct V_112 * V_66 = V_2 -> V_116 + V_73 ;
#ifdef F_142
F_114 ( & V_66 -> V_62 , & V_137 ) ;
#endif
F_111 ( & V_66 -> V_62 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_144 ( struct V_1 * V_2 )
{
int error = 0 , V_138 = 0 , V_139 = 0 , V_140 = 0 , V_141 = 0 ;
#ifdef F_113
V_2 -> V_105 = F_145 ( L_14 ,
NULL , & V_2 -> V_2 . V_62 ) ;
if ( ! V_2 -> V_105 )
return - V_75 ;
V_140 = V_2 -> V_142 ;
#endif
V_141 = V_2 -> V_143 ;
error = F_112 ( V_2 , 0 , V_140 ) ;
if ( error )
goto error;
V_139 = V_140 ;
error = F_143 ( V_2 , 0 , V_141 ) ;
if ( error )
goto error;
V_138 = V_141 ;
return 0 ;
error:
F_143 ( V_2 , V_138 , 0 ) ;
F_112 ( V_2 , V_139 , 0 ) ;
return error ;
}
static void F_146 ( struct V_1 * V_2 )
{
int V_140 = 0 , V_141 = 0 ;
#ifdef F_113
V_140 = V_2 -> V_142 ;
#endif
V_141 = V_2 -> V_143 ;
F_112 ( V_2 , V_140 , 0 ) ;
F_143 ( V_2 , V_141 , 0 ) ;
#ifdef F_113
F_147 ( V_2 -> V_105 ) ;
#endif
}
static bool F_148 ( void )
{
struct V_15 * V_15 = V_144 -> V_145 -> V_146 ;
return F_10 ( V_15 -> V_17 , V_147 ) ;
}
static void * F_149 ( void )
{
struct V_15 * V_98 = V_144 -> V_145 -> V_146 ;
#ifdef F_150
if ( V_98 )
F_151 ( & V_98 -> V_148 ) ;
#endif
return V_98 ;
}
static const void * F_152 ( void )
{
return & V_149 ;
}
static const void * F_153 ( struct V_150 * V_151 )
{
return F_154 ( V_151 ) ;
}
static int F_155 ( struct V_5 * V_53 , struct V_152 * V_153 )
{
struct V_1 * V_2 = F_4 ( V_53 ) ;
int V_154 ;
V_154 = F_156 ( V_153 , L_15 , V_2 -> V_51 ) ;
if ( V_154 )
goto exit;
V_154 = F_156 ( V_153 , L_16 , V_2 -> V_155 ) ;
exit:
return V_154 ;
}
static void F_157 ( struct V_5 * V_53 )
{
struct V_1 * V_2 = F_4 ( V_53 ) ;
F_123 ( V_2 -> V_3 != V_156 ) ;
F_84 ( V_2 -> V_45 ) ;
F_158 ( V_2 ) ;
}
static const void * F_159 ( struct V_5 * V_53 )
{
struct V_1 * V_2 ;
V_2 = F_95 ( V_53 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_160 ( struct V_5 * V_2 , const void * V_157 )
{
int V_10 = 0 ;
if ( V_2 -> V_158 )
V_10 = V_2 -> V_158 -> V_159 == V_157 ;
return V_10 == 0 ? V_2 -> V_159 == V_157 : V_10 ;
}
struct V_1 * F_161 ( struct V_160 * V_161 )
{
struct V_5 * V_2 ;
V_2 = F_162 ( & V_162 , NULL , V_161 , F_160 ) ;
if ( ! V_2 )
return NULL ;
return F_4 ( V_2 ) ;
}
void F_163 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_164 ( & V_2 -> V_62 ) ;
F_146 ( V_9 ) ;
F_165 ( V_2 , false ) ;
F_166 ( V_2 ) ;
}
int F_167 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_163 * * V_164 = V_9 -> V_165 ;
int error = 0 ;
F_168 ( V_2 ) ;
V_2 -> V_99 = & V_162 ;
V_2 -> V_166 = V_9 ;
V_2 -> V_164 = V_164 ;
F_169 ( V_2 , L_17 , V_9 -> V_51 ) ;
#ifdef F_113
if ( * V_164 )
V_164 ++ ;
* V_164 ++ = & V_167 ;
#if F_170 ( V_168 ) || F_170 ( V_169 )
if ( V_9 -> V_170 )
* V_164 ++ = & V_171 ;
#if F_170 ( V_168 )
else if ( V_9 -> V_172 )
* V_164 ++ = & V_171 ;
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
int F_172 ( struct V_173 * V_174 ,
const void * V_98 )
{
return F_173 ( & V_162 , V_174 , V_98 ) ;
}
void F_174 ( struct V_173 * V_174 ,
const void * V_98 )
{
F_175 ( & V_162 , V_174 , V_98 ) ;
}
int T_4 F_176 ( void )
{
F_177 ( & V_175 ) ;
return F_178 ( & V_162 ) ;
}
