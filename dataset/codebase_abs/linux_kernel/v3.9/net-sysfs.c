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
static T_1 F_47 ( const struct V_5 * V_41 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_42 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
T_1 V_10 = - V_11 ;
F_48 ( V_42 > sizeof( struct V_43 ) ||
V_42 % sizeof( V_44 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_43 V_45 ;
const struct V_43 * V_46 = F_49 ( V_2 , & V_45 ) ;
V_10 = sprintf ( V_8 , V_47 , * ( V_44 * ) ( ( ( V_48 * ) V_46 ) + V_42 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_50 ( struct V_49 * V_50 , struct V_51 * V_7 ,
char * V_8 )
{
struct V_52 * V_51 = F_51 ( V_7 ) ;
struct V_53 * V_54 = F_52 ( V_50 ) ;
if ( ! V_51 -> V_55 )
return - V_56 ;
return V_51 -> V_55 ( V_54 , V_51 , V_8 ) ;
}
static T_1 F_53 ( struct V_49 * V_50 , struct V_51 * V_7 ,
const char * V_8 , T_2 V_38 )
{
struct V_52 * V_51 = F_51 ( V_7 ) ;
struct V_53 * V_54 = F_52 ( V_50 ) ;
if ( ! V_51 -> V_57 )
return - V_56 ;
return V_51 -> V_57 ( V_54 , V_51 , V_8 , V_38 ) ;
}
static T_1 F_54 ( struct V_53 * V_54 ,
struct V_52 * V_51 , char * V_8 )
{
struct V_58 * V_59 ;
T_3 V_60 ;
T_2 V_13 = 0 ;
int V_61 ;
if ( ! F_55 ( & V_60 , V_62 ) )
return - V_63 ;
F_56 () ;
V_59 = F_57 ( V_54 -> V_58 ) ;
if ( V_59 )
for ( V_61 = 0 ; V_61 < V_59 -> V_13 ; V_61 ++ )
F_58 ( V_59 -> V_64 [ V_61 ] , V_60 ) ;
V_13 += F_59 ( V_8 + V_13 , V_65 , V_60 ) ;
if ( V_65 - V_13 < 3 ) {
F_60 () ;
F_61 ( V_60 ) ;
return - V_11 ;
}
F_60 () ;
F_61 ( V_60 ) ;
V_13 += sprintf ( V_8 + V_13 , L_5 ) ;
return V_13 ;
}
static T_1 F_62 ( struct V_53 * V_54 ,
struct V_52 * V_51 ,
const char * V_8 , T_2 V_13 )
{
struct V_58 * V_66 , * V_59 ;
T_3 V_60 ;
int V_19 , V_67 , V_61 ;
static F_63 ( V_68 ) ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
if ( ! F_64 ( & V_60 , V_62 ) )
return - V_63 ;
V_19 = F_65 ( V_8 , V_13 , F_66 ( V_60 ) , V_69 ) ;
if ( V_19 ) {
F_61 ( V_60 ) ;
return V_19 ;
}
V_59 = F_67 ( F_68 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_62 ) ;
if ( ! V_59 ) {
F_61 ( V_60 ) ;
return - V_63 ;
}
V_61 = 0 ;
F_69 (cpu, mask, cpu_online_mask)
V_59 -> V_64 [ V_61 ++ ] = V_67 ;
if ( V_61 )
V_59 -> V_13 = V_61 ;
else {
F_70 ( V_59 ) ;
V_59 = NULL ;
}
F_71 ( & V_68 ) ;
V_66 = F_72 ( V_54 -> V_58 ,
F_73 ( & V_68 ) ) ;
F_74 ( V_54 -> V_58 , V_59 ) ;
F_75 ( & V_68 ) ;
if ( V_59 )
F_76 ( & V_70 ) ;
if ( V_66 ) {
F_77 ( V_66 , V_71 ) ;
F_78 ( & V_70 ) ;
}
F_61 ( V_60 ) ;
return V_13 ;
}
static T_1 F_79 ( struct V_53 * V_54 ,
struct V_52 * V_7 ,
char * V_8 )
{
struct V_72 * V_73 ;
unsigned long V_74 = 0 ;
F_56 () ;
V_73 = F_57 ( V_54 -> V_75 ) ;
if ( V_73 )
V_74 = ( unsigned long ) V_73 -> V_60 + 1 ;
F_60 () ;
return sprintf ( V_8 , L_6 , V_74 ) ;
}
static void F_80 ( struct V_76 * V_77 )
{
struct V_72 * V_78 = F_81 ( V_77 ,
struct V_72 , V_79 ) ;
F_82 ( V_78 ) ;
}
static void F_83 ( struct V_80 * V_71 )
{
struct V_72 * V_78 = F_81 ( V_71 ,
struct V_72 , V_71 ) ;
F_84 ( & V_78 -> V_79 , F_80 ) ;
F_85 ( & V_78 -> V_79 ) ;
}
static T_1 F_86 ( struct V_53 * V_54 ,
struct V_52 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_60 , V_38 ;
struct V_72 * V_78 , * V_81 ;
static F_63 ( V_82 ) ;
int V_83 ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
V_83 = F_11 ( V_8 , 0 , & V_38 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_38 ) {
V_60 = V_38 - 1 ;
while ( ( V_60 | ( V_60 >> 1 ) ) != V_60 )
V_60 |= ( V_60 >> 1 ) ;
#if V_84 > 32
if ( V_60 > ( unsigned long ) ( V_85 ) V_60 )
return - V_11 ;
#else
if ( V_60 > ( V_86 - F_87 ( 1 ) )
/ sizeof( struct V_87 ) ) {
return - V_11 ;
}
#endif
V_78 = F_88 ( F_87 ( V_60 + 1 ) ) ;
if ( ! V_78 )
return - V_63 ;
V_78 -> V_60 = V_60 ;
for ( V_38 = 0 ; V_38 <= V_60 ; V_38 ++ )
V_78 -> V_88 [ V_38 ] . V_67 = V_89 ;
} else
V_78 = NULL ;
F_71 ( & V_82 ) ;
V_81 = F_72 ( V_54 -> V_75 ,
F_73 ( & V_82 ) ) ;
F_74 ( V_54 -> V_75 , V_78 ) ;
F_75 ( & V_82 ) ;
if ( V_81 )
F_89 ( & V_81 -> V_71 , F_83 ) ;
return V_13 ;
}
static void F_90 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = F_52 ( V_50 ) ;
struct V_58 * V_59 ;
struct V_72 * V_73 ;
V_59 = F_72 ( V_54 -> V_58 , 1 ) ;
if ( V_59 ) {
F_91 ( V_54 -> V_58 , NULL ) ;
F_77 ( V_59 , V_71 ) ;
}
V_73 = F_72 ( V_54 -> V_75 , 1 ) ;
if ( V_73 ) {
F_91 ( V_54 -> V_75 , NULL ) ;
F_89 ( & V_73 -> V_71 , F_83 ) ;
}
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_92 ( V_54 -> V_2 ) ;
}
static int F_93 ( struct V_1 * V_9 , int V_90 )
{
struct V_53 * V_54 = V_9 -> V_91 + V_90 ;
struct V_49 * V_50 = & V_54 -> V_50 ;
int error = 0 ;
V_50 -> V_92 = V_9 -> V_93 ;
error = F_94 ( V_50 , & V_94 , NULL ,
L_7 , V_90 ) ;
if ( error ) {
F_95 ( V_50 ) ;
return error ;
}
F_96 ( V_50 , V_95 ) ;
F_97 ( V_54 -> V_2 ) ;
return error ;
}
int
F_98 ( struct V_1 * V_9 , int V_96 , int V_97 )
{
#ifdef F_99
int V_61 ;
int error = 0 ;
for ( V_61 = V_96 ; V_61 < V_97 ; V_61 ++ ) {
error = F_93 ( V_9 , V_61 ) ;
if ( error ) {
V_97 = V_96 ;
break;
}
}
while ( -- V_61 >= V_97 )
F_95 ( & V_9 -> V_91 [ V_61 ] . V_50 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_100 ( struct V_49 * V_50 ,
struct V_51 * V_7 , char * V_8 )
{
struct V_98 * V_51 = F_101 ( V_7 ) ;
struct V_99 * V_54 = F_102 ( V_50 ) ;
if ( ! V_51 -> V_55 )
return - V_56 ;
return V_51 -> V_55 ( V_54 , V_51 , V_8 ) ;
}
static T_1 F_103 ( struct V_49 * V_50 ,
struct V_51 * V_7 ,
const char * V_8 , T_2 V_38 )
{
struct V_98 * V_51 = F_101 ( V_7 ) ;
struct V_99 * V_54 = F_102 ( V_50 ) ;
if ( ! V_51 -> V_57 )
return - V_56 ;
return V_51 -> V_57 ( V_54 , V_51 , V_8 , V_38 ) ;
}
static T_1 F_104 ( struct V_99 * V_54 ,
struct V_98 * V_51 ,
char * V_8 )
{
unsigned long V_100 ;
F_105 ( & V_54 -> V_101 ) ;
V_100 = V_54 -> V_100 ;
F_106 ( & V_54 -> V_101 ) ;
return sprintf ( V_8 , L_8 , V_100 ) ;
}
static T_1 F_107 ( char * V_8 , unsigned int V_102 )
{
return sprintf ( V_8 , L_9 , V_102 ) ;
}
static T_1 F_108 ( const char * V_8 , const T_2 V_38 ,
unsigned int * V_103 )
{
unsigned int V_102 ;
int V_19 ;
if ( ! strcmp ( V_8 , L_10 ) || ! strcmp ( V_8 , L_11 ) )
V_102 = V_104 ;
else {
V_19 = F_109 ( V_8 , 10 , & V_102 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_102 > V_104 )
return - V_11 ;
}
* V_103 = V_102 ;
return V_38 ;
}
static T_1 F_110 ( struct V_99 * V_54 ,
struct V_98 * V_7 ,
char * V_8 )
{
struct V_105 * V_105 = & V_54 -> V_105 ;
return sprintf ( V_8 , L_9 , F_111 ( V_105 -> V_106 ) ) ;
}
static T_1 F_112 ( struct V_99 * V_54 ,
struct V_98 * V_51 ,
const char * V_8 , T_2 V_13 )
{
struct V_105 * V_105 = & V_54 -> V_105 ;
unsigned int V_102 ;
int V_19 ;
V_19 = F_109 ( V_8 , 10 , & V_102 ) ;
if ( V_19 < 0 )
return V_19 ;
V_105 -> V_106 = F_113 ( V_102 ) ;
return V_13 ;
}
static T_1 F_114 ( struct V_99 * V_54 ,
struct V_98 * V_7 ,
char * V_8 )
{
struct V_105 * V_105 = & V_54 -> V_105 ;
return sprintf ( V_8 , L_9 , V_105 -> V_107 - V_105 -> V_108 ) ;
}
static inline unsigned int F_115 ( struct V_99 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_109 ; V_61 ++ )
if ( V_54 == & V_2 -> V_110 [ V_61 ] )
break;
F_116 ( V_61 >= V_2 -> V_109 ) ;
return V_61 ;
}
static T_1 F_117 ( struct V_99 * V_54 ,
struct V_98 * V_51 , char * V_8 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_111 * V_112 ;
T_3 V_60 ;
unsigned long V_90 ;
T_2 V_13 = 0 ;
int V_61 ;
if ( ! F_55 ( & V_60 , V_62 ) )
return - V_63 ;
V_90 = F_115 ( V_54 ) ;
F_56 () ;
V_112 = F_57 ( V_2 -> V_113 ) ;
if ( V_112 ) {
F_118 (i) {
struct V_114 * V_59 =
F_57 ( V_112 -> V_115 [ V_61 ] ) ;
if ( V_59 ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_59 -> V_13 ; V_116 ++ ) {
if ( V_59 -> V_117 [ V_116 ] == V_90 ) {
F_58 ( V_61 , V_60 ) ;
break;
}
}
}
}
}
F_60 () ;
V_13 += F_59 ( V_8 + V_13 , V_65 , V_60 ) ;
if ( V_65 - V_13 < 3 ) {
F_61 ( V_60 ) ;
return - V_11 ;
}
F_61 ( V_60 ) ;
V_13 += sprintf ( V_8 + V_13 , L_5 ) ;
return V_13 ;
}
static T_1 F_119 ( struct V_99 * V_54 ,
struct V_98 * V_51 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
unsigned long V_90 ;
T_3 V_60 ;
int V_19 ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
if ( ! F_64 ( & V_60 , V_62 ) )
return - V_63 ;
V_90 = F_115 ( V_54 ) ;
V_19 = F_65 ( V_8 , V_13 , F_66 ( V_60 ) , V_69 ) ;
if ( V_19 ) {
F_61 ( V_60 ) ;
return V_19 ;
}
V_19 = F_120 ( V_2 , V_60 , V_90 ) ;
F_61 ( V_60 ) ;
return V_19 ? : V_13 ;
}
static void F_121 ( struct V_49 * V_50 )
{
struct V_99 * V_54 = F_102 ( V_50 ) ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_92 ( V_54 -> V_2 ) ;
}
static int F_122 ( struct V_1 * V_9 , int V_90 )
{
struct V_99 * V_54 = V_9 -> V_110 + V_90 ;
struct V_49 * V_50 = & V_54 -> V_50 ;
int error = 0 ;
V_50 -> V_92 = V_9 -> V_93 ;
error = F_94 ( V_50 , & V_118 , NULL ,
L_12 , V_90 ) ;
if ( error )
goto exit;
#ifdef F_123
error = F_124 ( V_50 , & V_119 ) ;
if ( error )
goto exit;
#endif
F_96 ( V_50 , V_95 ) ;
F_97 ( V_54 -> V_2 ) ;
return 0 ;
exit:
F_95 ( V_50 ) ;
return error ;
}
int
F_125 ( struct V_1 * V_9 , int V_96 , int V_97 )
{
#ifdef F_126
int V_61 ;
int error = 0 ;
for ( V_61 = V_96 ; V_61 < V_97 ; V_61 ++ ) {
error = F_122 ( V_9 , V_61 ) ;
if ( error ) {
V_97 = V_96 ;
break;
}
}
while ( -- V_61 >= V_97 ) {
struct V_99 * V_54 = V_9 -> V_110 + V_61 ;
#ifdef F_123
F_127 ( & V_54 -> V_50 , & V_119 ) ;
#endif
F_95 ( & V_54 -> V_50 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_128 ( struct V_1 * V_9 )
{
int error = 0 , V_120 = 0 , V_121 = 0 , V_122 = 0 , V_123 = 0 ;
#ifdef F_126
V_9 -> V_93 = F_129 ( L_13 ,
NULL , & V_9 -> V_2 . V_50 ) ;
if ( ! V_9 -> V_93 )
return - V_63 ;
#endif
#ifdef F_99
V_122 = V_9 -> V_124 ;
#endif
V_123 = V_9 -> V_125 ;
error = F_98 ( V_9 , 0 , V_122 ) ;
if ( error )
goto error;
V_121 = V_122 ;
error = F_125 ( V_9 , 0 , V_123 ) ;
if ( error )
goto error;
V_120 = V_123 ;
return 0 ;
error:
F_125 ( V_9 , V_120 , 0 ) ;
F_98 ( V_9 , V_121 , 0 ) ;
return error ;
}
static void F_130 ( struct V_1 * V_9 )
{
int V_122 = 0 , V_123 = 0 ;
#ifdef F_99
V_122 = V_9 -> V_124 ;
#endif
V_123 = V_9 -> V_125 ;
F_98 ( V_9 , V_122 , 0 ) ;
F_125 ( V_9 , V_123 , 0 ) ;
#ifdef F_126
F_131 ( V_9 -> V_93 ) ;
#endif
}
static void * F_132 ( void )
{
struct V_9 * V_126 = V_127 -> V_128 -> V_129 ;
#ifdef F_133
if ( V_126 )
F_134 ( & V_126 -> V_130 ) ;
#endif
return V_126 ;
}
static const void * F_135 ( void )
{
return & V_131 ;
}
static const void * F_136 ( struct V_132 * V_133 )
{
return F_137 ( V_133 ) ;
}
static int F_138 ( struct V_5 * V_41 , struct V_134 * V_135 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
int V_136 ;
V_136 = F_139 ( V_135 , L_14 , V_2 -> V_137 ) ;
if ( V_136 )
goto exit;
V_136 = F_139 ( V_135 , L_15 , V_2 -> V_138 ) ;
exit:
return V_136 ;
}
static void F_140 ( struct V_5 * V_41 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
F_116 ( V_2 -> V_3 != V_139 ) ;
F_70 ( V_2 -> V_39 ) ;
F_70 ( ( char * ) V_2 - V_2 -> V_140 ) ;
}
static const void * F_141 ( struct V_5 * V_41 )
{
struct V_1 * V_2 ;
V_2 = F_81 ( V_41 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_142 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_143 ( & V_2 -> V_50 ) ;
F_130 ( V_9 ) ;
F_144 ( V_2 , false ) ;
F_145 ( V_2 ) ;
}
int F_146 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_141 * * V_142 = V_9 -> V_143 ;
int error = 0 ;
F_147 ( V_2 ) ;
V_2 -> V_144 = & V_145 ;
V_2 -> V_146 = V_9 ;
V_2 -> V_142 = V_142 ;
F_148 ( V_2 , L_16 , V_9 -> V_137 ) ;
#ifdef F_126
if ( * V_142 )
V_142 ++ ;
* V_142 ++ = & V_147 ;
#if F_149 ( V_148 ) || F_149 ( V_149 )
if ( V_9 -> V_150 )
* V_142 ++ = & V_151 ;
#if F_149 ( V_148 )
else if ( V_9 -> V_152 )
* V_142 ++ = & V_151 ;
#endif
#endif
#endif
error = F_150 ( V_2 ) ;
if ( error )
return error ;
error = F_128 ( V_9 ) ;
if ( error ) {
F_145 ( V_2 ) ;
return error ;
}
F_144 ( V_2 , true ) ;
return error ;
}
int F_151 ( struct V_153 * V_154 )
{
return F_152 ( & V_145 , V_154 ) ;
}
void F_153 ( struct V_153 * V_154 )
{
F_154 ( & V_145 , V_154 ) ;
}
int F_155 ( void )
{
F_156 ( & V_155 ) ;
return F_157 ( & V_145 ) ;
}
