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
static void F_80 ( struct V_76 * V_71 )
{
struct V_72 * V_77 = F_81 ( V_71 ,
struct V_72 , V_71 ) ;
F_82 ( V_77 ) ;
}
static T_1 F_83 ( struct V_53 * V_54 ,
struct V_52 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_60 , V_38 ;
struct V_72 * V_77 , * V_78 ;
static F_63 ( V_79 ) ;
int V_80 ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
V_80 = F_11 ( V_8 , 0 , & V_38 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_38 ) {
V_60 = V_38 - 1 ;
while ( ( V_60 | ( V_60 >> 1 ) ) != V_60 )
V_60 |= ( V_60 >> 1 ) ;
#if V_81 > 32
if ( V_60 > ( unsigned long ) ( V_82 ) V_60 )
return - V_11 ;
#else
if ( V_60 > ( V_83 - F_84 ( 1 ) )
/ sizeof( struct V_84 ) ) {
return - V_11 ;
}
#endif
V_77 = F_85 ( F_84 ( V_60 + 1 ) ) ;
if ( ! V_77 )
return - V_63 ;
V_77 -> V_60 = V_60 ;
for ( V_38 = 0 ; V_38 <= V_60 ; V_38 ++ )
V_77 -> V_85 [ V_38 ] . V_67 = V_86 ;
} else
V_77 = NULL ;
F_71 ( & V_79 ) ;
V_78 = F_72 ( V_54 -> V_75 ,
F_73 ( & V_79 ) ) ;
F_74 ( V_54 -> V_75 , V_77 ) ;
F_75 ( & V_79 ) ;
if ( V_78 )
F_86 ( & V_78 -> V_71 , F_80 ) ;
return V_13 ;
}
static void F_87 ( struct V_49 * V_50 )
{
struct V_53 * V_54 = F_52 ( V_50 ) ;
struct V_58 * V_59 ;
struct V_72 * V_73 ;
V_59 = F_72 ( V_54 -> V_58 , 1 ) ;
if ( V_59 ) {
F_88 ( V_54 -> V_58 , NULL ) ;
F_77 ( V_59 , V_71 ) ;
}
V_73 = F_72 ( V_54 -> V_75 , 1 ) ;
if ( V_73 ) {
F_88 ( V_54 -> V_75 , NULL ) ;
F_86 ( & V_73 -> V_71 , F_80 ) ;
}
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_89 ( V_54 -> V_2 ) ;
}
static int F_90 ( struct V_1 * V_9 , int V_87 )
{
struct V_53 * V_54 = V_9 -> V_88 + V_87 ;
struct V_49 * V_50 = & V_54 -> V_50 ;
int error = 0 ;
V_50 -> V_89 = V_9 -> V_90 ;
error = F_91 ( V_50 , & V_91 , NULL ,
L_7 , V_87 ) ;
if ( error ) {
F_92 ( V_50 ) ;
return error ;
}
F_93 ( V_50 , V_92 ) ;
F_94 ( V_54 -> V_2 ) ;
return error ;
}
int
F_95 ( struct V_1 * V_9 , int V_93 , int V_94 )
{
#ifdef F_96
int V_61 ;
int error = 0 ;
for ( V_61 = V_93 ; V_61 < V_94 ; V_61 ++ ) {
error = F_90 ( V_9 , V_61 ) ;
if ( error ) {
V_94 = V_93 ;
break;
}
}
while ( -- V_61 >= V_94 )
F_92 ( & V_9 -> V_88 [ V_61 ] . V_50 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_97 ( struct V_49 * V_50 ,
struct V_51 * V_7 , char * V_8 )
{
struct V_95 * V_51 = F_98 ( V_7 ) ;
struct V_96 * V_54 = F_99 ( V_50 ) ;
if ( ! V_51 -> V_55 )
return - V_56 ;
return V_51 -> V_55 ( V_54 , V_51 , V_8 ) ;
}
static T_1 F_100 ( struct V_49 * V_50 ,
struct V_51 * V_7 ,
const char * V_8 , T_2 V_38 )
{
struct V_95 * V_51 = F_98 ( V_7 ) ;
struct V_96 * V_54 = F_99 ( V_50 ) ;
if ( ! V_51 -> V_57 )
return - V_56 ;
return V_51 -> V_57 ( V_54 , V_51 , V_8 , V_38 ) ;
}
static T_1 F_101 ( struct V_96 * V_54 ,
struct V_95 * V_51 ,
char * V_8 )
{
unsigned long V_97 ;
F_102 ( & V_54 -> V_98 ) ;
V_97 = V_54 -> V_97 ;
F_103 ( & V_54 -> V_98 ) ;
return sprintf ( V_8 , L_8 , V_97 ) ;
}
static T_1 F_104 ( char * V_8 , unsigned int V_99 )
{
return sprintf ( V_8 , L_9 , V_99 ) ;
}
static T_1 F_105 ( const char * V_8 , const T_2 V_38 ,
unsigned int * V_100 )
{
unsigned int V_99 ;
int V_19 ;
if ( ! strcmp ( V_8 , L_10 ) || ! strcmp ( V_8 , L_11 ) )
V_99 = V_101 ;
else {
V_19 = F_106 ( V_8 , 10 , & V_99 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_99 > V_101 )
return - V_11 ;
}
* V_100 = V_99 ;
return V_38 ;
}
static T_1 F_107 ( struct V_96 * V_54 ,
struct V_95 * V_7 ,
char * V_8 )
{
struct V_102 * V_102 = & V_54 -> V_102 ;
return sprintf ( V_8 , L_9 , F_108 ( V_102 -> V_103 ) ) ;
}
static T_1 F_109 ( struct V_96 * V_54 ,
struct V_95 * V_51 ,
const char * V_8 , T_2 V_13 )
{
struct V_102 * V_102 = & V_54 -> V_102 ;
unsigned int V_99 ;
int V_19 ;
V_19 = F_106 ( V_8 , 10 , & V_99 ) ;
if ( V_19 < 0 )
return V_19 ;
V_102 -> V_103 = F_110 ( V_99 ) ;
return V_13 ;
}
static T_1 F_111 ( struct V_96 * V_54 ,
struct V_95 * V_7 ,
char * V_8 )
{
struct V_102 * V_102 = & V_54 -> V_102 ;
return sprintf ( V_8 , L_9 , V_102 -> V_104 - V_102 -> V_105 ) ;
}
static inline unsigned int F_112 ( struct V_96 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_106 ; V_61 ++ )
if ( V_54 == & V_2 -> V_107 [ V_61 ] )
break;
F_113 ( V_61 >= V_2 -> V_106 ) ;
return V_61 ;
}
static T_1 F_114 ( struct V_96 * V_54 ,
struct V_95 * V_51 , char * V_8 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_108 * V_109 ;
T_3 V_60 ;
unsigned long V_87 ;
T_2 V_13 = 0 ;
int V_61 ;
if ( ! F_55 ( & V_60 , V_62 ) )
return - V_63 ;
V_87 = F_112 ( V_54 ) ;
F_56 () ;
V_109 = F_57 ( V_2 -> V_110 ) ;
if ( V_109 ) {
F_115 (i) {
struct V_111 * V_59 =
F_57 ( V_109 -> V_112 [ V_61 ] ) ;
if ( V_59 ) {
int V_113 ;
for ( V_113 = 0 ; V_113 < V_59 -> V_13 ; V_113 ++ ) {
if ( V_59 -> V_114 [ V_113 ] == V_87 ) {
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
static T_1 F_116 ( struct V_96 * V_54 ,
struct V_95 * V_51 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
unsigned long V_87 ;
T_3 V_60 ;
int V_19 ;
if ( ! F_40 ( V_17 ) )
return - V_18 ;
if ( ! F_64 ( & V_60 , V_62 ) )
return - V_63 ;
V_87 = F_112 ( V_54 ) ;
V_19 = F_65 ( V_8 , V_13 , F_66 ( V_60 ) , V_69 ) ;
if ( V_19 ) {
F_61 ( V_60 ) ;
return V_19 ;
}
V_19 = F_117 ( V_2 , V_60 , V_87 ) ;
F_61 ( V_60 ) ;
return V_19 ? : V_13 ;
}
static void F_118 ( struct V_49 * V_50 )
{
struct V_96 * V_54 = F_99 ( V_50 ) ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_89 ( V_54 -> V_2 ) ;
}
static int F_119 ( struct V_1 * V_9 , int V_87 )
{
struct V_96 * V_54 = V_9 -> V_107 + V_87 ;
struct V_49 * V_50 = & V_54 -> V_50 ;
int error = 0 ;
V_50 -> V_89 = V_9 -> V_90 ;
error = F_91 ( V_50 , & V_115 , NULL ,
L_12 , V_87 ) ;
if ( error )
goto exit;
#ifdef F_120
error = F_121 ( V_50 , & V_116 ) ;
if ( error )
goto exit;
#endif
F_93 ( V_50 , V_92 ) ;
F_94 ( V_54 -> V_2 ) ;
return 0 ;
exit:
F_92 ( V_50 ) ;
return error ;
}
int
F_122 ( struct V_1 * V_9 , int V_93 , int V_94 )
{
#ifdef F_123
int V_61 ;
int error = 0 ;
for ( V_61 = V_93 ; V_61 < V_94 ; V_61 ++ ) {
error = F_119 ( V_9 , V_61 ) ;
if ( error ) {
V_94 = V_93 ;
break;
}
}
while ( -- V_61 >= V_94 ) {
struct V_96 * V_54 = V_9 -> V_107 + V_61 ;
#ifdef F_120
F_124 ( & V_54 -> V_50 , & V_116 ) ;
#endif
F_92 ( & V_54 -> V_50 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_125 ( struct V_1 * V_9 )
{
int error = 0 , V_117 = 0 , V_118 = 0 , V_119 = 0 , V_120 = 0 ;
#ifdef F_123
V_9 -> V_90 = F_126 ( L_13 ,
NULL , & V_9 -> V_2 . V_50 ) ;
if ( ! V_9 -> V_90 )
return - V_63 ;
#endif
#ifdef F_96
V_119 = V_9 -> V_121 ;
#endif
V_120 = V_9 -> V_122 ;
error = F_95 ( V_9 , 0 , V_119 ) ;
if ( error )
goto error;
V_118 = V_119 ;
error = F_122 ( V_9 , 0 , V_120 ) ;
if ( error )
goto error;
V_117 = V_120 ;
return 0 ;
error:
F_122 ( V_9 , V_117 , 0 ) ;
F_95 ( V_9 , V_118 , 0 ) ;
return error ;
}
static void F_127 ( struct V_1 * V_9 )
{
int V_119 = 0 , V_120 = 0 ;
#ifdef F_96
V_119 = V_9 -> V_121 ;
#endif
V_120 = V_9 -> V_122 ;
F_95 ( V_9 , V_119 , 0 ) ;
F_122 ( V_9 , V_120 , 0 ) ;
#ifdef F_123
F_128 ( V_9 -> V_90 ) ;
#endif
}
static void * F_129 ( void )
{
struct V_9 * V_123 = V_124 -> V_125 -> V_126 ;
#ifdef F_130
if ( V_123 )
F_131 ( & V_123 -> V_127 ) ;
#endif
return V_123 ;
}
static const void * F_132 ( void )
{
return & V_128 ;
}
static const void * F_133 ( struct V_129 * V_130 )
{
return F_134 ( V_130 ) ;
}
static int F_135 ( struct V_5 * V_41 , struct V_131 * V_132 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
int V_133 ;
V_133 = F_136 ( V_132 , L_14 , V_2 -> V_134 ) ;
if ( V_133 )
goto exit;
V_133 = F_136 ( V_132 , L_15 , V_2 -> V_135 ) ;
exit:
return V_133 ;
}
static void F_137 ( struct V_5 * V_41 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
F_113 ( V_2 -> V_3 != V_136 ) ;
F_70 ( V_2 -> V_39 ) ;
F_70 ( ( char * ) V_2 - V_2 -> V_137 ) ;
}
static const void * F_138 ( struct V_5 * V_41 )
{
struct V_1 * V_2 ;
V_2 = F_81 ( V_41 , struct V_1 , V_2 ) ;
return F_9 ( V_2 ) ;
}
void F_139 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_140 ( & V_2 -> V_50 ) ;
F_127 ( V_9 ) ;
F_141 ( V_2 , false ) ;
F_142 ( V_2 ) ;
}
int F_143 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_138 * * V_139 = V_9 -> V_140 ;
int error = 0 ;
F_144 ( V_2 ) ;
V_2 -> V_141 = & V_142 ;
V_2 -> V_143 = V_9 ;
V_2 -> V_139 = V_139 ;
F_145 ( V_2 , L_16 , V_9 -> V_134 ) ;
#ifdef F_123
if ( * V_139 )
V_139 ++ ;
* V_139 ++ = & V_144 ;
#if F_146 ( V_145 ) || F_146 ( V_146 )
if ( V_9 -> V_147 )
* V_139 ++ = & V_148 ;
#if F_146 ( V_145 )
else if ( V_9 -> V_149 )
* V_139 ++ = & V_148 ;
#endif
#endif
#endif
error = F_147 ( V_2 ) ;
if ( error )
return error ;
error = F_125 ( V_9 ) ;
if ( error ) {
F_142 ( V_2 ) ;
return error ;
}
F_141 ( V_2 , true ) ;
return error ;
}
int F_148 ( struct V_150 * V_151 )
{
return F_149 ( & V_142 , V_151 ) ;
}
void F_150 ( struct V_150 * V_151 )
{
F_151 ( & V_142 , V_151 ) ;
}
int F_152 ( void )
{
F_153 ( & V_152 ) ;
return F_154 ( & V_142 ) ;
}
