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
struct V_1 * V_9 = F_4 ( V_2 ) ;
unsigned long V_14 ;
int V_10 = - V_11 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
V_10 = F_10 ( V_8 , 0 , & V_14 ) ;
if ( V_10 )
goto V_17;
if ( ! F_11 () )
return F_12 () ;
if ( F_1 ( V_9 ) ) {
if ( ( V_10 = (* F_8)( V_9 , V_14 ) ) == 0 )
V_10 = V_13 ;
}
F_13 () ;
V_17:
return V_10 ;
}
static T_1 F_14 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = F_15 ( V_8 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_16 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
if ( F_1 ( V_9 ) )
return F_15 ( V_8 , V_9 -> V_20 , V_9 -> V_19 ) ;
return - V_11 ;
}
static T_1 F_17 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
if ( F_18 ( V_21 ) ) {
return sprintf ( V_8 , V_22 , ! ! F_19 ( V_21 ) ) ;
}
return - V_11 ;
}
static T_1 F_20 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_18 ( V_21 ) ) {
struct V_23 V_24 ;
if ( ! F_21 ( V_21 , & V_24 ) )
V_10 = sprintf ( V_8 , V_25 , F_22 ( & V_24 ) ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_23 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_18 ( V_21 ) ) {
struct V_23 V_24 ;
if ( ! F_21 ( V_21 , & V_24 ) )
V_10 = sprintf ( V_8 , L_1 ,
V_24 . V_26 ? L_2 : L_3 ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_24 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
if ( F_18 ( V_21 ) )
return sprintf ( V_8 , V_22 , ! ! F_25 ( V_21 ) ) ;
return - V_11 ;
}
static T_1 F_26 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_21 = F_4 ( V_2 ) ;
unsigned char V_27 ;
F_5 ( & V_12 ) ;
V_27 = V_21 -> V_27 ;
if ( ! F_18 ( V_21 ) )
V_27 = V_28 ;
F_6 ( & V_12 ) ;
if ( V_27 >= F_27 ( V_29 ) )
return - V_11 ;
return sprintf ( V_8 , L_1 , V_29 [ V_27 ] ) ;
}
static int F_28 ( struct V_1 * V_9 , unsigned long V_30 )
{
return F_29 ( V_9 , ( int ) V_30 ) ;
}
static T_1 F_30 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_28 ) ;
}
static int F_31 ( struct V_1 * V_9 , unsigned long V_31 )
{
return F_32 ( V_9 , ( unsigned int ) V_31 ) ;
}
static T_1 F_33 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_31 ) ;
}
static int F_34 ( struct V_1 * V_9 , unsigned long V_32 )
{
V_9 -> V_33 = V_32 ;
return 0 ;
}
static T_1 F_35 ( struct V_5 * V_2 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_34 ) ;
}
static T_1 F_36 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_21 = F_4 ( V_2 ) ;
T_2 V_34 = V_13 ;
T_1 V_10 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_34 ;
if ( ! F_11 () )
return F_12 () ;
V_10 = F_37 ( V_21 , V_8 , V_34 ) ;
F_13 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_38 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_21 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_11 () )
return F_12 () ;
if ( V_21 -> V_35 )
V_10 = sprintf ( V_8 , L_1 , V_21 -> V_35 ) ;
F_13 () ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_9 , unsigned long V_36 )
{
F_40 ( V_9 , ( int ) V_36 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_39 ) ;
}
static T_1 F_42 ( const struct V_5 * V_37 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_38 )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
T_1 V_10 = - V_11 ;
F_43 ( V_38 > sizeof( struct V_39 ) ||
V_38 % sizeof( V_40 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_39 V_41 ;
const struct V_39 * V_42 = F_44 ( V_2 , & V_41 ) ;
V_10 = sprintf ( V_8 , V_43 , * ( V_40 * ) ( ( ( V_44 * ) V_42 ) + V_38 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_45 ( struct V_45 * V_46 , struct V_47 * V_7 ,
char * V_8 )
{
struct V_48 * V_47 = F_46 ( V_7 ) ;
struct V_49 * V_50 = F_47 ( V_46 ) ;
if ( ! V_47 -> V_51 )
return - V_52 ;
return V_47 -> V_51 ( V_50 , V_47 , V_8 ) ;
}
static T_1 F_48 ( struct V_45 * V_46 , struct V_47 * V_7 ,
const char * V_8 , T_2 V_34 )
{
struct V_48 * V_47 = F_46 ( V_7 ) ;
struct V_49 * V_50 = F_47 ( V_46 ) ;
if ( ! V_47 -> V_53 )
return - V_52 ;
return V_47 -> V_53 ( V_50 , V_47 , V_8 , V_34 ) ;
}
static T_1 F_49 ( struct V_49 * V_50 ,
struct V_48 * V_47 , char * V_8 )
{
struct V_54 * V_55 ;
T_3 V_56 ;
T_2 V_13 = 0 ;
int V_57 ;
if ( ! F_50 ( & V_56 , V_58 ) )
return - V_59 ;
F_51 () ;
V_55 = F_52 ( V_50 -> V_54 ) ;
if ( V_55 )
for ( V_57 = 0 ; V_57 < V_55 -> V_13 ; V_57 ++ )
F_53 ( V_55 -> V_60 [ V_57 ] , V_56 ) ;
V_13 += F_54 ( V_8 + V_13 , V_61 , V_56 ) ;
if ( V_61 - V_13 < 3 ) {
F_55 () ;
F_56 ( V_56 ) ;
return - V_11 ;
}
F_55 () ;
F_56 ( V_56 ) ;
V_13 += sprintf ( V_8 + V_13 , L_4 ) ;
return V_13 ;
}
static T_1 F_57 ( struct V_49 * V_50 ,
struct V_48 * V_47 ,
const char * V_8 , T_2 V_13 )
{
struct V_54 * V_62 , * V_55 ;
T_3 V_56 ;
int V_17 , V_63 , V_57 ;
static F_58 ( V_64 ) ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( ! F_59 ( & V_56 , V_58 ) )
return - V_59 ;
V_17 = F_60 ( V_8 , V_13 , F_61 ( V_56 ) , V_65 ) ;
if ( V_17 ) {
F_56 ( V_56 ) ;
return V_17 ;
}
V_55 = F_62 ( F_63 (unsigned int,
RPS_MAP_SIZE(cpumask_weight(mask)), L1_CACHE_BYTES) ,
V_58 ) ;
if ( ! V_55 ) {
F_56 ( V_56 ) ;
return - V_59 ;
}
V_57 = 0 ;
F_64 (cpu, mask, cpu_online_mask)
V_55 -> V_60 [ V_57 ++ ] = V_63 ;
if ( V_57 )
V_55 -> V_13 = V_57 ;
else {
F_65 ( V_55 ) ;
V_55 = NULL ;
}
F_66 ( & V_64 ) ;
V_62 = F_67 ( V_50 -> V_54 ,
F_68 ( & V_64 ) ) ;
F_69 ( V_50 -> V_54 , V_55 ) ;
F_70 ( & V_64 ) ;
if ( V_55 )
F_71 ( & V_66 ) ;
if ( V_62 ) {
F_72 ( V_62 , V_67 ) ;
F_73 ( & V_66 ) ;
}
F_56 ( V_56 ) ;
return V_13 ;
}
static T_1 F_74 ( struct V_49 * V_50 ,
struct V_48 * V_7 ,
char * V_8 )
{
struct V_68 * V_69 ;
unsigned long V_70 = 0 ;
F_51 () ;
V_69 = F_52 ( V_50 -> V_71 ) ;
if ( V_69 )
V_70 = ( unsigned long ) V_69 -> V_56 + 1 ;
F_55 () ;
return sprintf ( V_8 , L_5 , V_70 ) ;
}
static void F_75 ( struct V_72 * V_73 )
{
struct V_68 * V_74 = F_76 ( V_73 ,
struct V_68 , V_75 ) ;
F_77 ( V_74 ) ;
}
static void F_78 ( struct V_76 * V_67 )
{
struct V_68 * V_74 = F_76 ( V_67 ,
struct V_68 , V_67 ) ;
F_79 ( & V_74 -> V_75 , F_75 ) ;
F_80 ( & V_74 -> V_75 ) ;
}
static T_1 F_81 ( struct V_49 * V_50 ,
struct V_48 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_56 , V_34 ;
struct V_68 * V_74 , * V_77 ;
static F_58 ( V_78 ) ;
int V_79 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
V_79 = F_10 ( V_8 , 0 , & V_34 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_34 ) {
V_56 = V_34 - 1 ;
while ( ( V_56 | ( V_56 >> 1 ) ) != V_56 )
V_56 |= ( V_56 >> 1 ) ;
#if V_80 > 32
if ( V_56 > ( unsigned long ) ( V_81 ) V_56 )
return - V_11 ;
#else
if ( V_56 > ( V_82 - F_82 ( 1 ) )
/ sizeof( struct V_83 ) ) {
return - V_11 ;
}
#endif
V_74 = F_83 ( F_82 ( V_56 + 1 ) ) ;
if ( ! V_74 )
return - V_59 ;
V_74 -> V_56 = V_56 ;
for ( V_34 = 0 ; V_34 <= V_56 ; V_34 ++ )
V_74 -> V_84 [ V_34 ] . V_63 = V_85 ;
} else
V_74 = NULL ;
F_66 ( & V_78 ) ;
V_77 = F_67 ( V_50 -> V_71 ,
F_68 ( & V_78 ) ) ;
F_69 ( V_50 -> V_71 , V_74 ) ;
F_70 ( & V_78 ) ;
if ( V_77 )
F_84 ( & V_77 -> V_67 , F_78 ) ;
return V_13 ;
}
static void F_85 ( struct V_45 * V_46 )
{
struct V_49 * V_50 = F_47 ( V_46 ) ;
struct V_54 * V_55 ;
struct V_68 * V_69 ;
V_55 = F_67 ( V_50 -> V_54 , 1 ) ;
if ( V_55 ) {
F_86 ( V_50 -> V_54 , NULL ) ;
F_72 ( V_55 , V_67 ) ;
}
V_69 = F_67 ( V_50 -> V_71 , 1 ) ;
if ( V_69 ) {
F_86 ( V_50 -> V_71 , NULL ) ;
F_84 ( & V_69 -> V_67 , F_78 ) ;
}
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
F_87 ( V_50 -> V_2 ) ;
}
static int F_88 ( struct V_1 * V_9 , int V_86 )
{
struct V_49 * V_50 = V_9 -> V_87 + V_86 ;
struct V_45 * V_46 = & V_50 -> V_46 ;
int error = 0 ;
V_46 -> V_88 = V_9 -> V_89 ;
error = F_89 ( V_46 , & V_90 , NULL ,
L_6 , V_86 ) ;
if ( error ) {
F_90 ( V_46 ) ;
return error ;
}
F_91 ( V_46 , V_91 ) ;
F_92 ( V_50 -> V_2 ) ;
return error ;
}
int
F_93 ( struct V_1 * V_9 , int V_92 , int V_93 )
{
#ifdef F_94
int V_57 ;
int error = 0 ;
for ( V_57 = V_92 ; V_57 < V_93 ; V_57 ++ ) {
error = F_88 ( V_9 , V_57 ) ;
if ( error ) {
V_93 = V_92 ;
break;
}
}
while ( -- V_57 >= V_93 )
F_90 ( & V_9 -> V_87 [ V_57 ] . V_46 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_95 ( struct V_45 * V_46 ,
struct V_47 * V_7 , char * V_8 )
{
struct V_94 * V_47 = F_96 ( V_7 ) ;
struct V_95 * V_50 = F_97 ( V_46 ) ;
if ( ! V_47 -> V_51 )
return - V_52 ;
return V_47 -> V_51 ( V_50 , V_47 , V_8 ) ;
}
static T_1 F_98 ( struct V_45 * V_46 ,
struct V_47 * V_7 ,
const char * V_8 , T_2 V_34 )
{
struct V_94 * V_47 = F_96 ( V_7 ) ;
struct V_95 * V_50 = F_97 ( V_46 ) ;
if ( ! V_47 -> V_53 )
return - V_52 ;
return V_47 -> V_53 ( V_50 , V_47 , V_8 , V_34 ) ;
}
static T_1 F_99 ( struct V_95 * V_50 ,
struct V_94 * V_47 ,
char * V_8 )
{
unsigned long V_96 ;
F_100 ( & V_50 -> V_97 ) ;
V_96 = V_50 -> V_96 ;
F_101 ( & V_50 -> V_97 ) ;
return sprintf ( V_8 , L_7 , V_96 ) ;
}
static T_1 F_102 ( char * V_8 , unsigned int V_98 )
{
return sprintf ( V_8 , L_8 , V_98 ) ;
}
static T_1 F_103 ( const char * V_8 , const T_2 V_34 ,
unsigned int * V_99 )
{
unsigned int V_98 ;
int V_17 ;
if ( ! strcmp ( V_8 , L_9 ) || ! strcmp ( V_8 , L_10 ) )
V_98 = V_100 ;
else {
V_17 = F_104 ( V_8 , 10 , & V_98 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_98 > V_100 )
return - V_11 ;
}
* V_99 = V_98 ;
return V_34 ;
}
static T_1 F_105 ( struct V_95 * V_50 ,
struct V_94 * V_7 ,
char * V_8 )
{
struct V_101 * V_101 = & V_50 -> V_101 ;
return sprintf ( V_8 , L_8 , F_106 ( V_101 -> V_102 ) ) ;
}
static T_1 F_107 ( struct V_95 * V_50 ,
struct V_94 * V_47 ,
const char * V_8 , T_2 V_13 )
{
struct V_101 * V_101 = & V_50 -> V_101 ;
unsigned int V_98 ;
int V_17 ;
V_17 = F_104 ( V_8 , 10 , & V_98 ) ;
if ( V_17 < 0 )
return V_17 ;
V_101 -> V_102 = F_108 ( V_98 ) ;
return V_13 ;
}
static T_1 F_109 ( struct V_95 * V_50 ,
struct V_94 * V_7 ,
char * V_8 )
{
struct V_101 * V_101 = & V_50 -> V_101 ;
return sprintf ( V_8 , L_8 , V_101 -> V_103 - V_101 -> V_104 ) ;
}
static inline unsigned int F_110 ( struct V_95 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_105 ; V_57 ++ )
if ( V_50 == & V_2 -> V_106 [ V_57 ] )
break;
F_111 ( V_57 >= V_2 -> V_105 ) ;
return V_57 ;
}
static T_1 F_112 ( struct V_95 * V_50 ,
struct V_94 * V_47 , char * V_8 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_107 * V_108 ;
T_3 V_56 ;
unsigned long V_86 ;
T_2 V_13 = 0 ;
int V_57 ;
if ( ! F_50 ( & V_56 , V_58 ) )
return - V_59 ;
V_86 = F_110 ( V_50 ) ;
F_51 () ;
V_108 = F_52 ( V_2 -> V_109 ) ;
if ( V_108 ) {
F_113 (i) {
struct V_110 * V_55 =
F_52 ( V_108 -> V_111 [ V_57 ] ) ;
if ( V_55 ) {
int V_112 ;
for ( V_112 = 0 ; V_112 < V_55 -> V_13 ; V_112 ++ ) {
if ( V_55 -> V_113 [ V_112 ] == V_86 ) {
F_53 ( V_57 , V_56 ) ;
break;
}
}
}
}
}
F_55 () ;
V_13 += F_54 ( V_8 + V_13 , V_61 , V_56 ) ;
if ( V_61 - V_13 < 3 ) {
F_56 ( V_56 ) ;
return - V_11 ;
}
F_56 ( V_56 ) ;
V_13 += sprintf ( V_8 + V_13 , L_4 ) ;
return V_13 ;
}
static void F_114 ( struct V_95 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
struct V_107 * V_108 ;
struct V_110 * V_55 ;
unsigned long V_86 ;
int V_57 , V_114 , V_115 = 0 ;
V_86 = F_110 ( V_50 ) ;
F_115 ( & V_116 ) ;
V_108 = F_116 ( V_2 -> V_109 ) ;
if ( V_108 ) {
F_113 (i) {
V_55 = F_116 ( V_108 -> V_111 [ V_57 ] ) ;
if ( ! V_55 )
continue;
for ( V_114 = 0 ; V_114 < V_55 -> V_13 ; V_114 ++ )
if ( V_55 -> V_113 [ V_114 ] == V_86 )
break;
if ( V_114 < V_55 -> V_13 ) {
if ( V_55 -> V_13 > 1 )
V_55 -> V_113 [ V_114 ] =
V_55 -> V_113 [ -- V_55 -> V_13 ] ;
else {
F_86 ( V_108 -> V_111 [ V_57 ] ,
NULL ) ;
F_72 ( V_55 , V_67 ) ;
V_55 = NULL ;
}
}
if ( V_55 )
V_115 = 1 ;
}
if ( ! V_115 ) {
F_86 ( V_2 -> V_109 , NULL ) ;
F_72 ( V_108 , V_67 ) ;
}
}
F_117 ( & V_116 ) ;
}
static T_1 F_118 ( struct V_95 * V_50 ,
struct V_94 * V_47 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_50 -> V_2 ;
T_3 V_56 ;
int V_17 , V_57 , V_63 , V_114 , V_117 , V_118 , V_119 ;
unsigned long V_86 ;
struct V_110 * V_55 , * V_120 ;
struct V_107 * V_108 , * V_121 ;
int V_115 = 0 ;
int V_122 = - 2 ;
if ( ! F_9 ( V_15 ) )
return - V_16 ;
if ( ! F_59 ( & V_56 , V_58 ) )
return - V_59 ;
V_86 = F_110 ( V_50 ) ;
V_17 = F_60 ( V_8 , V_13 , F_61 ( V_56 ) , V_65 ) ;
if ( V_17 ) {
F_56 ( V_56 ) ;
return V_17 ;
}
V_121 = F_62 ( F_63 (unsigned int,
XPS_DEV_MAPS_SIZE, L1_CACHE_BYTES) , V_58 ) ;
if ( ! V_121 ) {
F_56 ( V_56 ) ;
return - V_59 ;
}
F_115 ( & V_116 ) ;
V_108 = F_116 ( V_2 -> V_109 ) ;
F_113 (cpu) {
V_55 = V_108 ?
F_116 ( V_108 -> V_111 [ V_63 ] ) : NULL ;
V_120 = V_55 ;
if ( V_55 ) {
for ( V_114 = 0 ; V_114 < V_55 -> V_13 ; V_114 ++ )
if ( V_55 -> V_113 [ V_114 ] == V_86 )
break;
V_117 = V_55 -> V_13 ;
V_118 = V_55 -> V_118 ;
} else
V_114 = V_117 = V_118 = 0 ;
V_119 = F_119 ( V_63 , V_56 ) && F_120 ( V_63 ) ;
#ifdef F_121
if ( V_119 ) {
if ( V_122 == - 2 )
V_122 = F_122 ( V_63 ) ;
else if ( V_122 != F_122 ( V_63 ) )
V_122 = - 1 ;
}
#endif
if ( V_119 && V_114 >= V_117 ) {
if ( V_117 >= V_118 ) {
V_118 = V_118 ?
2 * V_118 : V_123 ;
V_120 = F_123 ( F_124 ( V_118 ) ,
V_58 ,
F_122 ( V_63 ) ) ;
if ( ! V_120 )
goto error;
V_120 -> V_118 = V_118 ;
for ( V_57 = 0 ; V_57 < V_117 ; V_57 ++ )
V_120 -> V_113 [ V_57 ] = V_55 -> V_113 [ V_57 ] ;
V_120 -> V_13 = V_117 ;
}
V_120 -> V_113 [ V_120 -> V_13 ++ ] = V_86 ;
} else if ( ! V_119 && V_114 < V_117 ) {
if ( V_117 > 1 )
V_120 -> V_113 [ V_114 ] =
V_120 -> V_113 [ -- V_120 -> V_13 ] ;
else
V_120 = NULL ;
}
F_86 ( V_121 -> V_111 [ V_63 ] , V_120 ) ;
}
F_113 (cpu) {
V_55 = V_108 ?
F_116 ( V_108 -> V_111 [ V_63 ] ) : NULL ;
if ( V_55 && F_116 ( V_121 -> V_111 [ V_63 ] ) != V_55 )
F_72 ( V_55 , V_67 ) ;
if ( V_121 -> V_111 [ V_63 ] )
V_115 = 1 ;
}
if ( V_115 ) {
F_69 ( V_2 -> V_109 , V_121 ) ;
} else {
F_65 ( V_121 ) ;
F_86 ( V_2 -> V_109 , NULL ) ;
}
if ( V_108 )
F_72 ( V_108 , V_67 ) ;
F_125 ( V_50 , ( V_122 >= 0 ) ? V_122 :
V_124 ) ;
F_117 ( & V_116 ) ;
F_56 ( V_56 ) ;
return V_13 ;
error:
F_117 ( & V_116 ) ;
if ( V_121 )
F_113 (i)
F_65 ( F_67 (
V_121 -> V_111 [ V_57 ] ,
1 ) ) ;
F_65 ( V_121 ) ;
F_56 ( V_56 ) ;
return - V_59 ;
}
static void F_126 ( struct V_45 * V_46 )
{
struct V_95 * V_50 = F_97 ( V_46 ) ;
#ifdef F_127
F_114 ( V_50 ) ;
#endif
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
F_87 ( V_50 -> V_2 ) ;
}
static int F_128 ( struct V_1 * V_9 , int V_86 )
{
struct V_95 * V_50 = V_9 -> V_106 + V_86 ;
struct V_45 * V_46 = & V_50 -> V_46 ;
int error = 0 ;
V_46 -> V_88 = V_9 -> V_89 ;
error = F_89 ( V_46 , & V_125 , NULL ,
L_11 , V_86 ) ;
if ( error )
goto exit;
#ifdef F_129
error = F_130 ( V_46 , & V_126 ) ;
if ( error )
goto exit;
#endif
F_91 ( V_46 , V_91 ) ;
F_92 ( V_50 -> V_2 ) ;
return 0 ;
exit:
F_90 ( V_46 ) ;
return error ;
}
int
F_131 ( struct V_1 * V_9 , int V_92 , int V_93 )
{
#ifdef F_132
int V_57 ;
int error = 0 ;
for ( V_57 = V_92 ; V_57 < V_93 ; V_57 ++ ) {
error = F_128 ( V_9 , V_57 ) ;
if ( error ) {
V_93 = V_92 ;
break;
}
}
while ( -- V_57 >= V_93 ) {
struct V_95 * V_50 = V_9 -> V_106 + V_57 ;
#ifdef F_129
F_133 ( & V_50 -> V_46 , & V_126 ) ;
#endif
F_90 ( & V_50 -> V_46 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_134 ( struct V_1 * V_9 )
{
int error = 0 , V_127 = 0 , V_128 = 0 , V_129 = 0 , V_130 = 0 ;
#ifdef F_132
V_9 -> V_89 = F_135 ( L_12 ,
NULL , & V_9 -> V_2 . V_46 ) ;
if ( ! V_9 -> V_89 )
return - V_59 ;
#endif
#ifdef F_94
V_129 = V_9 -> V_131 ;
#endif
V_130 = V_9 -> V_132 ;
error = F_93 ( V_9 , 0 , V_129 ) ;
if ( error )
goto error;
V_128 = V_129 ;
error = F_131 ( V_9 , 0 , V_130 ) ;
if ( error )
goto error;
V_127 = V_130 ;
return 0 ;
error:
F_131 ( V_9 , V_127 , 0 ) ;
F_93 ( V_9 , V_128 , 0 ) ;
return error ;
}
static void F_136 ( struct V_1 * V_9 )
{
int V_129 = 0 , V_130 = 0 ;
#ifdef F_94
V_129 = V_9 -> V_131 ;
#endif
V_130 = V_9 -> V_132 ;
F_93 ( V_9 , V_129 , 0 ) ;
F_131 ( V_9 , V_130 , 0 ) ;
#ifdef F_132
F_137 ( V_9 -> V_89 ) ;
#endif
}
static void * F_138 ( void )
{
struct V_9 * V_133 = V_134 -> V_135 -> V_136 ;
#ifdef F_139
if ( V_133 )
F_140 ( & V_133 -> V_137 ) ;
#endif
return V_133 ;
}
static const void * F_141 ( void )
{
return & V_138 ;
}
static const void * F_142 ( struct V_139 * V_140 )
{
return F_143 ( V_140 ) ;
}
static int F_144 ( struct V_5 * V_37 , struct V_141 * V_142 )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
int V_143 ;
V_143 = F_145 ( V_142 , L_13 , V_2 -> V_144 ) ;
if ( V_143 )
goto exit;
V_143 = F_145 ( V_142 , L_14 , V_2 -> V_145 ) ;
exit:
return V_143 ;
}
static void F_146 ( struct V_5 * V_37 )
{
struct V_1 * V_2 = F_4 ( V_37 ) ;
F_111 ( V_2 -> V_3 != V_146 ) ;
F_65 ( V_2 -> V_35 ) ;
F_65 ( ( char * ) V_2 - V_2 -> V_147 ) ;
}
static const void * F_147 ( struct V_5 * V_37 )
{
struct V_1 * V_2 ;
V_2 = F_76 ( V_37 , struct V_1 , V_2 ) ;
return F_148 ( V_2 ) ;
}
void F_149 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_150 ( & V_2 -> V_46 ) ;
F_136 ( V_9 ) ;
F_151 ( V_2 ) ;
}
int F_152 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_148 * * V_149 = V_9 -> V_150 ;
int error = 0 ;
F_153 ( V_2 ) ;
V_2 -> V_151 = & V_152 ;
V_2 -> V_153 = V_9 ;
V_2 -> V_149 = V_149 ;
F_154 ( V_2 , L_15 , V_9 -> V_144 ) ;
#ifdef F_132
if ( * V_149 )
V_149 ++ ;
* V_149 ++ = & V_154 ;
#endif
error = F_155 ( V_2 ) ;
if ( error )
return error ;
error = F_134 ( V_9 ) ;
if ( error ) {
F_151 ( V_2 ) ;
return error ;
}
return error ;
}
int F_156 ( struct V_155 * V_156 )
{
return F_157 ( & V_152 , V_156 ) ;
}
void F_158 ( struct V_155 * V_156 )
{
F_159 ( & V_152 , V_156 ) ;
}
int F_160 ( void )
{
F_161 ( & V_157 ) ;
return F_162 ( & V_152 ) ;
}
