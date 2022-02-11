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
char * V_14 ;
unsigned long V_15 ;
int V_10 = - V_11 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
V_15 = F_10 ( V_8 , & V_14 , 0 ) ;
if ( V_14 == V_8 )
goto V_18;
if ( ! F_11 () )
return F_12 () ;
if ( F_1 ( V_9 ) ) {
if ( ( V_10 = (* F_8)( V_9 , V_15 ) ) == 0 )
V_10 = V_13 ;
}
F_13 () ;
V_18:
return V_10 ;
}
static T_1 F_14 ( struct V_5 * V_2 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
T_1 V_10 = - V_11 ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_9 ) )
V_10 = F_15 ( V_8 , V_9 -> V_19 , V_9 -> V_20 ) ;
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_16 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_4 ( V_2 ) ;
if ( F_1 ( V_9 ) )
return F_15 ( V_8 , V_9 -> V_21 , V_9 -> V_20 ) ;
return - V_11 ;
}
static T_1 F_17 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_22 = F_4 ( V_2 ) ;
if ( F_18 ( V_22 ) ) {
return sprintf ( V_8 , V_23 , ! ! F_19 ( V_22 ) ) ;
}
return - V_11 ;
}
static T_1 F_20 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_22 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_18 ( V_22 ) ) {
struct V_24 V_25 ;
if ( ! F_21 ( V_22 , & V_25 ) )
V_10 = sprintf ( V_8 , V_26 , F_22 ( & V_25 ) ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_23 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_22 = F_4 ( V_2 ) ;
int V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_18 ( V_22 ) ) {
struct V_24 V_25 ;
if ( ! F_21 ( V_22 , & V_25 ) )
V_10 = sprintf ( V_8 , L_1 ,
V_25 . V_27 ? L_2 : L_3 ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_24 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_22 = F_4 ( V_2 ) ;
if ( F_18 ( V_22 ) )
return sprintf ( V_8 , V_23 , ! ! F_25 ( V_22 ) ) ;
return - V_11 ;
}
static T_1 F_26 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_22 = F_4 ( V_2 ) ;
unsigned char V_28 ;
F_5 ( & V_12 ) ;
V_28 = V_22 -> V_28 ;
if ( ! F_18 ( V_22 ) )
V_28 = V_29 ;
F_6 ( & V_12 ) ;
if ( V_28 >= F_27 ( V_30 ) )
return - V_11 ;
return sprintf ( V_8 , L_1 , V_30 [ V_28 ] ) ;
}
static int F_28 ( struct V_1 * V_9 , unsigned long V_31 )
{
return F_29 ( V_9 , ( int ) V_31 ) ;
}
static T_1 F_30 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_28 ) ;
}
static int F_31 ( struct V_1 * V_9 , unsigned long V_32 )
{
return F_32 ( V_9 , ( unsigned ) V_32 ) ;
}
static T_1 F_33 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_31 ) ;
}
static int F_34 ( struct V_1 * V_9 , unsigned long V_33 )
{
V_9 -> V_34 = V_33 ;
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
struct V_1 * V_22 = F_4 ( V_2 ) ;
T_2 V_35 = V_13 ;
T_1 V_10 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( V_13 > 0 && V_8 [ V_13 - 1 ] == '\n' )
-- V_35 ;
if ( ! F_11 () )
return F_12 () ;
V_10 = F_37 ( V_22 , V_8 , V_35 ) ;
F_13 () ;
return V_10 < 0 ? V_10 : V_13 ;
}
static T_1 F_38 ( struct V_5 * V_2 ,
struct V_6 * V_7 , char * V_8 )
{
const struct V_1 * V_22 = F_4 ( V_2 ) ;
T_1 V_10 = 0 ;
if ( ! F_11 () )
return F_12 () ;
if ( V_22 -> V_36 )
V_10 = sprintf ( V_8 , L_1 , V_22 -> V_36 ) ;
F_13 () ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_9 , unsigned long V_37 )
{
F_40 ( V_9 , ( int ) V_37 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_5 * V_2 , struct V_6 * V_7 ,
const char * V_8 , T_2 V_13 )
{
return F_7 ( V_2 , V_7 , V_8 , V_13 , F_39 ) ;
}
static T_1 F_42 ( const struct V_5 * V_38 ,
struct V_6 * V_7 , char * V_8 ,
unsigned long V_39 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
T_1 V_10 = - V_11 ;
F_43 ( V_39 > sizeof( struct V_40 ) ||
V_39 % sizeof( V_41 ) != 0 ) ;
F_5 ( & V_12 ) ;
if ( F_1 ( V_2 ) ) {
struct V_40 V_42 ;
const struct V_40 * V_43 = F_44 ( V_2 , & V_42 ) ;
V_10 = sprintf ( V_8 , V_44 , * ( V_41 * ) ( ( ( V_45 * ) V_43 ) + V_39 ) ) ;
}
F_6 ( & V_12 ) ;
return V_10 ;
}
static T_1 F_45 ( struct V_5 * V_38 , char * V_8 ,
T_1 (* F_3)( const struct V_46 * ,
char * ) )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
const struct V_46 * V_47 ;
T_1 V_10 = - V_11 ;
if ( ! F_11 () )
return F_12 () ;
if ( F_1 ( V_2 ) ) {
V_47 = F_46 ( V_2 ) ;
if ( V_47 )
V_10 = (* F_3)( V_47 , V_8 ) ;
}
F_13 () ;
return V_10 ;
}
static T_1 F_47 ( struct V_48 * V_49 , struct V_50 * V_7 ,
char * V_8 )
{
struct V_51 * V_50 = F_48 ( V_7 ) ;
struct V_52 * V_53 = F_49 ( V_49 ) ;
if ( ! V_50 -> V_54 )
return - V_55 ;
return V_50 -> V_54 ( V_53 , V_50 , V_8 ) ;
}
static T_1 F_50 ( struct V_48 * V_49 , struct V_50 * V_7 ,
const char * V_8 , T_2 V_35 )
{
struct V_51 * V_50 = F_48 ( V_7 ) ;
struct V_52 * V_53 = F_49 ( V_49 ) ;
if ( ! V_50 -> V_56 )
return - V_55 ;
return V_50 -> V_56 ( V_53 , V_50 , V_8 , V_35 ) ;
}
static T_1 F_51 ( struct V_52 * V_53 ,
struct V_51 * V_50 , char * V_8 )
{
struct V_57 * V_58 ;
T_3 V_59 ;
T_2 V_13 = 0 ;
int V_60 ;
if ( ! F_52 ( & V_59 , V_61 ) )
return - V_62 ;
F_53 () ;
V_58 = F_54 ( V_53 -> V_57 ) ;
if ( V_58 )
for ( V_60 = 0 ; V_60 < V_58 -> V_13 ; V_60 ++ )
F_55 ( V_58 -> V_63 [ V_60 ] , V_59 ) ;
V_13 += F_56 ( V_8 + V_13 , V_64 , V_59 ) ;
if ( V_64 - V_13 < 3 ) {
F_57 () ;
F_58 ( V_59 ) ;
return - V_11 ;
}
F_57 () ;
F_58 ( V_59 ) ;
V_13 += sprintf ( V_8 + V_13 , L_4 ) ;
return V_13 ;
}
static T_1 F_59 ( struct V_52 * V_53 ,
struct V_51 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_57 * V_65 , * V_58 ;
T_3 V_59 ;
int V_18 , V_66 , V_60 ;
static F_60 ( V_67 ) ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( ! F_61 ( & V_59 , V_61 ) )
return - V_62 ;
V_18 = F_62 ( V_8 , V_13 , F_63 ( V_59 ) , V_68 ) ;
if ( V_18 ) {
F_58 ( V_59 ) ;
return V_18 ;
}
V_58 = F_64 ( F_65 ( unsigned ,
F_66 ( F_67 ( V_59 ) ) , V_69 ) ,
V_61 ) ;
if ( ! V_58 ) {
F_58 ( V_59 ) ;
return - V_62 ;
}
V_60 = 0 ;
F_68 (cpu, mask, cpu_online_mask)
V_58 -> V_63 [ V_60 ++ ] = V_66 ;
if ( V_60 )
V_58 -> V_13 = V_60 ;
else {
F_69 ( V_58 ) ;
V_58 = NULL ;
}
F_70 ( & V_67 ) ;
V_65 = F_71 ( V_53 -> V_57 ,
F_72 ( & V_67 ) ) ;
F_73 ( V_53 -> V_57 , V_58 ) ;
F_74 ( & V_67 ) ;
if ( V_58 )
F_75 ( & V_70 ) ;
if ( V_65 ) {
F_76 ( V_65 , V_71 ) ;
F_77 ( & V_70 ) ;
}
F_58 ( V_59 ) ;
return V_13 ;
}
static T_1 F_78 ( struct V_52 * V_53 ,
struct V_51 * V_7 ,
char * V_8 )
{
struct V_72 * V_73 ;
unsigned long V_74 = 0 ;
F_53 () ;
V_73 = F_54 ( V_53 -> V_75 ) ;
if ( V_73 )
V_74 = ( unsigned long ) V_73 -> V_59 + 1 ;
F_57 () ;
return sprintf ( V_8 , L_5 , V_74 ) ;
}
static void F_79 ( struct V_76 * V_77 )
{
struct V_72 * V_78 = F_80 ( V_77 ,
struct V_72 , V_79 ) ;
F_81 ( V_78 ) ;
}
static void F_82 ( struct V_80 * V_71 )
{
struct V_72 * V_78 = F_80 ( V_71 ,
struct V_72 , V_71 ) ;
F_83 ( & V_78 -> V_79 , F_79 ) ;
F_84 ( & V_78 -> V_79 ) ;
}
static T_1 F_85 ( struct V_52 * V_53 ,
struct V_51 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned long V_59 , V_35 ;
struct V_72 * V_78 , * V_81 ;
static F_60 ( V_82 ) ;
int V_83 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
V_83 = F_86 ( V_8 , 0 , & V_35 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_35 ) {
V_59 = V_35 - 1 ;
while ( ( V_59 | ( V_59 >> 1 ) ) != V_59 )
V_59 |= ( V_59 >> 1 ) ;
#if V_84 > 32
if ( V_59 > ( unsigned long ) ( V_85 ) V_59 )
return - V_11 ;
#else
if ( V_59 > ( V_86 - F_87 ( 1 ) )
/ sizeof( struct V_87 ) ) {
return - V_11 ;
}
#endif
V_78 = F_88 ( F_87 ( V_59 + 1 ) ) ;
if ( ! V_78 )
return - V_62 ;
V_78 -> V_59 = V_59 ;
for ( V_35 = 0 ; V_35 <= V_59 ; V_35 ++ )
V_78 -> V_88 [ V_35 ] . V_66 = V_89 ;
} else
V_78 = NULL ;
F_70 ( & V_82 ) ;
V_81 = F_71 ( V_53 -> V_75 ,
F_72 ( & V_82 ) ) ;
F_73 ( V_53 -> V_75 , V_78 ) ;
F_74 ( & V_82 ) ;
if ( V_81 )
F_89 ( & V_81 -> V_71 , F_82 ) ;
return V_13 ;
}
static void F_90 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = F_49 ( V_49 ) ;
struct V_57 * V_58 ;
struct V_72 * V_73 ;
V_58 = F_71 ( V_53 -> V_57 , 1 ) ;
if ( V_58 ) {
F_91 ( V_53 -> V_57 , NULL ) ;
F_76 ( V_58 , V_71 ) ;
}
V_73 = F_71 ( V_53 -> V_75 , 1 ) ;
if ( V_73 ) {
F_91 ( V_53 -> V_75 , NULL ) ;
F_89 ( & V_73 -> V_71 , F_82 ) ;
}
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_92 ( V_53 -> V_2 ) ;
}
static int F_93 ( struct V_1 * V_9 , int V_90 )
{
struct V_52 * V_53 = V_9 -> V_91 + V_90 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_92 = V_9 -> V_93 ;
error = F_94 ( V_49 , & V_94 , NULL ,
L_6 , V_90 ) ;
if ( error ) {
F_95 ( V_49 ) ;
return error ;
}
F_96 ( V_49 , V_95 ) ;
F_97 ( V_53 -> V_2 ) ;
return error ;
}
int
F_98 ( struct V_1 * V_9 , int V_96 , int V_97 )
{
#ifdef F_99
int V_60 ;
int error = 0 ;
for ( V_60 = V_96 ; V_60 < V_97 ; V_60 ++ ) {
error = F_93 ( V_9 , V_60 ) ;
if ( error ) {
V_97 = V_96 ;
break;
}
}
while ( -- V_60 >= V_97 )
F_95 ( & V_9 -> V_91 [ V_60 ] . V_49 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_100 ( struct V_48 * V_49 ,
struct V_50 * V_7 , char * V_8 )
{
struct V_98 * V_50 = F_101 ( V_7 ) ;
struct V_99 * V_53 = F_102 ( V_49 ) ;
if ( ! V_50 -> V_54 )
return - V_55 ;
return V_50 -> V_54 ( V_53 , V_50 , V_8 ) ;
}
static T_1 F_103 ( struct V_48 * V_49 ,
struct V_50 * V_7 ,
const char * V_8 , T_2 V_35 )
{
struct V_98 * V_50 = F_101 ( V_7 ) ;
struct V_99 * V_53 = F_102 ( V_49 ) ;
if ( ! V_50 -> V_56 )
return - V_55 ;
return V_50 -> V_56 ( V_53 , V_50 , V_8 , V_35 ) ;
}
static T_1 F_104 ( struct V_99 * V_53 ,
struct V_98 * V_50 ,
char * V_8 )
{
unsigned long V_100 ;
F_105 ( & V_53 -> V_101 ) ;
V_100 = V_53 -> V_100 ;
F_106 ( & V_53 -> V_101 ) ;
return sprintf ( V_8 , L_7 , V_100 ) ;
}
static T_1 F_107 ( char * V_8 , unsigned int V_102 )
{
return sprintf ( V_8 , L_8 , V_102 ) ;
}
static T_1 F_108 ( const char * V_8 , const T_2 V_35 ,
unsigned int * V_103 )
{
unsigned int V_102 ;
int V_18 ;
if ( ! strcmp ( V_8 , L_9 ) || ! strcmp ( V_8 , L_10 ) )
V_102 = V_104 ;
else {
V_18 = F_109 ( V_8 , 10 , & V_102 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_102 > V_104 )
return - V_11 ;
}
* V_103 = V_102 ;
return V_35 ;
}
static T_1 F_110 ( struct V_99 * V_53 ,
struct V_98 * V_7 ,
char * V_8 )
{
struct V_105 * V_105 = & V_53 -> V_105 ;
return sprintf ( V_8 , L_8 , F_111 ( V_105 -> V_106 ) ) ;
}
static T_1 F_112 ( struct V_99 * V_53 ,
struct V_98 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_105 * V_105 = & V_53 -> V_105 ;
unsigned V_102 ;
int V_18 ;
V_18 = F_109 ( V_8 , 10 , & V_102 ) ;
if ( V_18 < 0 )
return V_18 ;
V_105 -> V_106 = F_113 ( V_102 ) ;
return V_13 ;
}
static T_1 F_114 ( struct V_99 * V_53 ,
struct V_98 * V_7 ,
char * V_8 )
{
struct V_105 * V_105 = & V_53 -> V_105 ;
return sprintf ( V_8 , L_8 , V_105 -> V_107 - V_105 -> V_108 ) ;
}
static inline unsigned int F_115 ( struct V_99 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_109 ; V_60 ++ )
if ( V_53 == & V_2 -> V_110 [ V_60 ] )
break;
F_116 ( V_60 >= V_2 -> V_109 ) ;
return V_60 ;
}
static T_1 F_117 ( struct V_99 * V_53 ,
struct V_98 * V_50 , char * V_8 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_111 * V_112 ;
T_3 V_59 ;
unsigned long V_90 ;
T_2 V_13 = 0 ;
int V_60 ;
if ( ! F_52 ( & V_59 , V_61 ) )
return - V_62 ;
V_90 = F_115 ( V_53 ) ;
F_53 () ;
V_112 = F_54 ( V_2 -> V_113 ) ;
if ( V_112 ) {
F_118 (i) {
struct V_114 * V_58 =
F_54 ( V_112 -> V_115 [ V_60 ] ) ;
if ( V_58 ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_58 -> V_13 ; V_116 ++ ) {
if ( V_58 -> V_117 [ V_116 ] == V_90 ) {
F_55 ( V_60 , V_59 ) ;
break;
}
}
}
}
}
F_57 () ;
V_13 += F_56 ( V_8 + V_13 , V_64 , V_59 ) ;
if ( V_64 - V_13 < 3 ) {
F_58 ( V_59 ) ;
return - V_11 ;
}
F_58 ( V_59 ) ;
V_13 += sprintf ( V_8 + V_13 , L_4 ) ;
return V_13 ;
}
static void F_119 ( struct V_99 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_111 * V_112 ;
struct V_114 * V_58 ;
unsigned long V_90 ;
int V_60 , V_118 , V_119 = 0 ;
V_90 = F_115 ( V_53 ) ;
F_120 ( & V_120 ) ;
V_112 = F_121 ( V_2 -> V_113 ) ;
if ( V_112 ) {
F_118 (i) {
V_58 = F_121 ( V_112 -> V_115 [ V_60 ] ) ;
if ( ! V_58 )
continue;
for ( V_118 = 0 ; V_118 < V_58 -> V_13 ; V_118 ++ )
if ( V_58 -> V_117 [ V_118 ] == V_90 )
break;
if ( V_118 < V_58 -> V_13 ) {
if ( V_58 -> V_13 > 1 )
V_58 -> V_117 [ V_118 ] =
V_58 -> V_117 [ -- V_58 -> V_13 ] ;
else {
F_91 ( V_112 -> V_115 [ V_60 ] ,
NULL ) ;
F_76 ( V_58 , V_71 ) ;
V_58 = NULL ;
}
}
if ( V_58 )
V_119 = 1 ;
}
if ( ! V_119 ) {
F_91 ( V_2 -> V_113 , NULL ) ;
F_76 ( V_112 , V_71 ) ;
}
}
F_122 ( & V_120 ) ;
}
static T_1 F_123 ( struct V_99 * V_53 ,
struct V_98 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_3 V_59 ;
int V_18 , V_60 , V_66 , V_118 , V_121 , V_122 , V_123 ;
unsigned long V_90 ;
struct V_114 * V_58 , * V_124 ;
struct V_111 * V_112 , * V_125 ;
int V_119 = 0 ;
int V_126 = - 2 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( ! F_61 ( & V_59 , V_61 ) )
return - V_62 ;
V_90 = F_115 ( V_53 ) ;
V_18 = F_62 ( V_8 , V_13 , F_63 ( V_59 ) , V_68 ) ;
if ( V_18 ) {
F_58 ( V_59 ) ;
return V_18 ;
}
V_125 = F_64 ( F_65 ( unsigned ,
V_127 , V_69 ) , V_61 ) ;
if ( ! V_125 ) {
F_58 ( V_59 ) ;
return - V_62 ;
}
F_120 ( & V_120 ) ;
V_112 = F_121 ( V_2 -> V_113 ) ;
F_118 (cpu) {
V_58 = V_112 ?
F_121 ( V_112 -> V_115 [ V_66 ] ) : NULL ;
V_124 = V_58 ;
if ( V_58 ) {
for ( V_118 = 0 ; V_118 < V_58 -> V_13 ; V_118 ++ )
if ( V_58 -> V_117 [ V_118 ] == V_90 )
break;
V_121 = V_58 -> V_13 ;
V_122 = V_58 -> V_122 ;
} else
V_118 = V_121 = V_122 = 0 ;
V_123 = F_124 ( V_66 , V_59 ) && F_125 ( V_66 ) ;
#ifdef F_126
if ( V_123 ) {
if ( V_126 == - 2 )
V_126 = F_127 ( V_66 ) ;
else if ( V_126 != F_127 ( V_66 ) )
V_126 = - 1 ;
}
#endif
if ( V_123 && V_118 >= V_121 ) {
if ( V_121 >= V_122 ) {
V_122 = V_122 ?
2 * V_122 : V_128 ;
V_124 = F_128 ( F_129 ( V_122 ) ,
V_61 ,
F_127 ( V_66 ) ) ;
if ( ! V_124 )
goto error;
V_124 -> V_122 = V_122 ;
for ( V_60 = 0 ; V_60 < V_121 ; V_60 ++ )
V_124 -> V_117 [ V_60 ] = V_58 -> V_117 [ V_60 ] ;
V_124 -> V_13 = V_121 ;
}
V_124 -> V_117 [ V_124 -> V_13 ++ ] = V_90 ;
} else if ( ! V_123 && V_118 < V_121 ) {
if ( V_121 > 1 )
V_124 -> V_117 [ V_118 ] =
V_124 -> V_117 [ -- V_124 -> V_13 ] ;
else
V_124 = NULL ;
}
F_91 ( V_125 -> V_115 [ V_66 ] , V_124 ) ;
}
F_118 (cpu) {
V_58 = V_112 ?
F_121 ( V_112 -> V_115 [ V_66 ] ) : NULL ;
if ( V_58 && F_121 ( V_125 -> V_115 [ V_66 ] ) != V_58 )
F_76 ( V_58 , V_71 ) ;
if ( V_125 -> V_115 [ V_66 ] )
V_119 = 1 ;
}
if ( V_119 ) {
F_73 ( V_2 -> V_113 , V_125 ) ;
} else {
F_69 ( V_125 ) ;
F_91 ( V_2 -> V_113 , NULL ) ;
}
if ( V_112 )
F_76 ( V_112 , V_71 ) ;
F_130 ( V_53 , ( V_126 >= 0 ) ? V_126 :
V_129 ) ;
F_122 ( & V_120 ) ;
F_58 ( V_59 ) ;
return V_13 ;
error:
F_122 ( & V_120 ) ;
if ( V_125 )
F_118 (i)
F_69 ( F_71 (
V_125 -> V_115 [ V_60 ] ,
1 ) ) ;
F_69 ( V_125 ) ;
F_58 ( V_59 ) ;
return - V_62 ;
}
static void F_131 ( struct V_48 * V_49 )
{
struct V_99 * V_53 = F_102 ( V_49 ) ;
#ifdef F_132
F_119 ( V_53 ) ;
#endif
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_92 ( V_53 -> V_2 ) ;
}
static int F_133 ( struct V_1 * V_9 , int V_90 )
{
struct V_99 * V_53 = V_9 -> V_110 + V_90 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_92 = V_9 -> V_93 ;
error = F_94 ( V_49 , & V_130 , NULL ,
L_11 , V_90 ) ;
if ( error )
goto exit;
#ifdef F_134
error = F_135 ( V_49 , & V_131 ) ;
if ( error )
goto exit;
#endif
F_96 ( V_49 , V_95 ) ;
F_97 ( V_53 -> V_2 ) ;
return 0 ;
exit:
F_95 ( V_49 ) ;
return error ;
}
int
F_136 ( struct V_1 * V_9 , int V_96 , int V_97 )
{
#ifdef F_137
int V_60 ;
int error = 0 ;
for ( V_60 = V_96 ; V_60 < V_97 ; V_60 ++ ) {
error = F_133 ( V_9 , V_60 ) ;
if ( error ) {
V_97 = V_96 ;
break;
}
}
while ( -- V_60 >= V_97 ) {
struct V_99 * V_53 = V_9 -> V_110 + V_60 ;
#ifdef F_134
F_138 ( & V_53 -> V_49 , & V_131 ) ;
#endif
F_95 ( & V_53 -> V_49 ) ;
}
return error ;
#else
return 0 ;
#endif
}
static int F_139 ( struct V_1 * V_9 )
{
int error = 0 , V_132 = 0 , V_133 = 0 , V_134 = 0 , V_135 = 0 ;
#ifdef F_137
V_9 -> V_93 = F_140 ( L_12 ,
NULL , & V_9 -> V_2 . V_49 ) ;
if ( ! V_9 -> V_93 )
return - V_62 ;
#endif
#ifdef F_99
V_134 = V_9 -> V_136 ;
#endif
V_135 = V_9 -> V_137 ;
error = F_98 ( V_9 , 0 , V_134 ) ;
if ( error )
goto error;
V_133 = V_134 ;
error = F_136 ( V_9 , 0 , V_135 ) ;
if ( error )
goto error;
V_132 = V_135 ;
return 0 ;
error:
F_136 ( V_9 , V_132 , 0 ) ;
F_98 ( V_9 , V_133 , 0 ) ;
return error ;
}
static void F_141 ( struct V_1 * V_9 )
{
int V_134 = 0 , V_135 = 0 ;
#ifdef F_99
V_134 = V_9 -> V_136 ;
#endif
V_135 = V_9 -> V_137 ;
F_98 ( V_9 , V_134 , 0 ) ;
F_136 ( V_9 , V_135 , 0 ) ;
#ifdef F_137
F_142 ( V_9 -> V_93 ) ;
#endif
}
static void * F_143 ( void )
{
struct V_9 * V_138 = V_139 -> V_140 -> V_141 ;
#ifdef F_144
if ( V_138 )
F_145 ( & V_138 -> V_142 ) ;
#endif
return V_138 ;
}
static const void * F_146 ( void )
{
return & V_143 ;
}
static const void * F_147 ( struct V_144 * V_145 )
{
return F_148 ( V_145 ) ;
}
static int F_149 ( struct V_5 * V_38 , struct V_146 * V_147 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
int V_148 ;
V_148 = F_150 ( V_147 , L_13 , V_2 -> V_149 ) ;
if ( V_148 )
goto exit;
V_148 = F_150 ( V_147 , L_14 , V_2 -> V_150 ) ;
exit:
return V_148 ;
}
static void F_151 ( struct V_5 * V_38 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
F_116 ( V_2 -> V_3 != V_151 ) ;
F_69 ( V_2 -> V_36 ) ;
F_69 ( ( char * ) V_2 - V_2 -> V_152 ) ;
}
static const void * F_152 ( struct V_5 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_80 ( V_38 , struct V_1 , V_2 ) ;
return F_153 ( V_2 ) ;
}
void F_154 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_155 ( & V_2 -> V_49 ) ;
F_141 ( V_9 ) ;
F_156 ( V_2 ) ;
}
int F_157 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_153 * * V_154 = V_9 -> V_155 ;
int error = 0 ;
F_158 ( V_2 ) ;
V_2 -> V_156 = & V_157 ;
V_2 -> V_158 = V_9 ;
V_2 -> V_154 = V_154 ;
F_159 ( V_2 , L_15 , V_9 -> V_149 ) ;
#ifdef F_137
if ( * V_154 )
V_154 ++ ;
* V_154 ++ = & V_159 ;
#ifdef F_160
if ( V_9 -> V_160 )
* V_154 ++ = & V_161 ;
#ifdef F_161
else if ( V_9 -> V_162 )
* V_154 ++ = & V_161 ;
#endif
#endif
#endif
error = F_162 ( V_2 ) ;
if ( error )
return error ;
error = F_139 ( V_9 ) ;
if ( error ) {
F_156 ( V_2 ) ;
return error ;
}
return error ;
}
int F_163 ( struct V_163 * V_164 )
{
return F_164 ( & V_157 , V_164 ) ;
}
void F_165 ( struct V_163 * V_164 )
{
F_166 ( & V_157 , V_164 ) ;
}
int F_167 ( void )
{
F_168 ( & V_165 ) ;
return F_169 ( & V_157 ) ;
}
