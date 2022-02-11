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
if ( V_65 )
F_75 ( V_65 , V_70 ) ;
F_58 ( V_59 ) ;
return V_13 ;
}
static T_1 F_76 ( struct V_52 * V_53 ,
struct V_51 * V_7 ,
char * V_8 )
{
struct V_71 * V_72 ;
unsigned int V_73 = 0 ;
F_53 () ;
V_72 = F_54 ( V_53 -> V_74 ) ;
if ( V_72 )
V_73 = V_72 -> V_59 + 1 ;
F_57 () ;
return sprintf ( V_8 , L_5 , V_73 ) ;
}
static void F_77 ( struct V_75 * V_76 )
{
struct V_71 * V_77 = F_78 ( V_76 ,
struct V_71 , V_78 ) ;
F_79 ( V_77 ) ;
}
static void F_80 ( struct V_79 * V_70 )
{
struct V_71 * V_77 = F_78 ( V_70 ,
struct V_71 , V_70 ) ;
F_81 ( & V_77 -> V_78 , F_77 ) ;
F_82 ( & V_77 -> V_78 ) ;
}
static T_1 F_83 ( struct V_52 * V_53 ,
struct V_51 * V_7 ,
const char * V_8 , T_2 V_13 )
{
unsigned int V_35 ;
char * V_14 ;
struct V_71 * V_77 , * V_80 ;
static F_60 ( V_81 ) ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
V_35 = F_10 ( V_8 , & V_14 , 0 ) ;
if ( V_14 == V_8 )
return - V_11 ;
if ( V_35 ) {
int V_60 ;
if ( V_35 > V_82 )
return - V_11 ;
V_35 = F_84 ( V_35 ) ;
if ( V_35 > ( V_83 - sizeof( struct V_71 ) )
/ sizeof( struct V_84 ) ) {
return - V_11 ;
}
V_77 = F_85 ( F_86 ( V_35 ) ) ;
if ( ! V_77 )
return - V_62 ;
V_77 -> V_59 = V_35 - 1 ;
for ( V_60 = 0 ; V_60 < V_35 ; V_60 ++ )
V_77 -> V_85 [ V_60 ] . V_66 = V_86 ;
} else
V_77 = NULL ;
F_70 ( & V_81 ) ;
V_80 = F_71 ( V_53 -> V_74 ,
F_72 ( & V_81 ) ) ;
F_73 ( V_53 -> V_74 , V_77 ) ;
F_74 ( & V_81 ) ;
if ( V_80 )
F_87 ( & V_80 -> V_70 , F_80 ) ;
return V_13 ;
}
static void F_88 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = F_49 ( V_49 ) ;
struct V_57 * V_58 ;
struct V_71 * V_72 ;
V_58 = F_71 ( V_53 -> V_57 , 1 ) ;
if ( V_58 ) {
F_89 ( V_53 -> V_57 , NULL ) ;
F_75 ( V_58 , V_70 ) ;
}
V_72 = F_71 ( V_53 -> V_74 , 1 ) ;
if ( V_72 ) {
F_89 ( V_53 -> V_74 , NULL ) ;
F_87 ( & V_72 -> V_70 , F_80 ) ;
}
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_90 ( V_53 -> V_2 ) ;
}
static int F_91 ( struct V_1 * V_9 , int V_87 )
{
struct V_52 * V_53 = V_9 -> V_88 + V_87 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_89 = V_9 -> V_90 ;
error = F_92 ( V_49 , & V_91 , NULL ,
L_6 , V_87 ) ;
if ( error ) {
F_93 ( V_49 ) ;
return error ;
}
F_94 ( V_49 , V_92 ) ;
F_95 ( V_53 -> V_2 ) ;
return error ;
}
int
F_96 ( struct V_1 * V_9 , int V_93 , int V_94 )
{
#ifdef F_97
int V_60 ;
int error = 0 ;
for ( V_60 = V_93 ; V_60 < V_94 ; V_60 ++ ) {
error = F_91 ( V_9 , V_60 ) ;
if ( error ) {
V_94 = V_93 ;
break;
}
}
while ( -- V_60 >= V_94 )
F_93 ( & V_9 -> V_88 [ V_60 ] . V_49 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_98 ( struct V_48 * V_49 ,
struct V_50 * V_7 , char * V_8 )
{
struct V_95 * V_50 = F_99 ( V_7 ) ;
struct V_96 * V_53 = F_100 ( V_49 ) ;
if ( ! V_50 -> V_54 )
return - V_55 ;
return V_50 -> V_54 ( V_53 , V_50 , V_8 ) ;
}
static T_1 F_101 ( struct V_48 * V_49 ,
struct V_50 * V_7 ,
const char * V_8 , T_2 V_35 )
{
struct V_95 * V_50 = F_99 ( V_7 ) ;
struct V_96 * V_53 = F_100 ( V_49 ) ;
if ( ! V_50 -> V_56 )
return - V_55 ;
return V_50 -> V_56 ( V_53 , V_50 , V_8 , V_35 ) ;
}
static inline unsigned int F_102 ( struct V_96 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_97 ; V_60 ++ )
if ( V_53 == & V_2 -> V_98 [ V_60 ] )
break;
F_103 ( V_60 >= V_2 -> V_97 ) ;
return V_60 ;
}
static T_1 F_104 ( struct V_96 * V_53 ,
struct V_95 * V_50 , char * V_8 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_99 * V_100 ;
T_3 V_59 ;
unsigned long V_87 ;
T_2 V_13 = 0 ;
int V_60 ;
if ( ! F_52 ( & V_59 , V_61 ) )
return - V_62 ;
V_87 = F_102 ( V_53 ) ;
F_53 () ;
V_100 = F_54 ( V_2 -> V_101 ) ;
if ( V_100 ) {
F_105 (i) {
struct V_102 * V_58 =
F_54 ( V_100 -> V_103 [ V_60 ] ) ;
if ( V_58 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_58 -> V_13 ; V_104 ++ ) {
if ( V_58 -> V_105 [ V_104 ] == V_87 ) {
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
static T_1 F_106 ( struct V_96 * V_53 ,
struct V_95 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_3 V_59 ;
int V_18 , V_60 , V_66 , V_106 , V_107 , V_108 , V_109 ;
unsigned long V_87 ;
struct V_102 * V_58 , * V_110 ;
struct V_99 * V_100 , * V_111 ;
int V_112 = 0 ;
int V_113 = - 2 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( ! F_61 ( & V_59 , V_61 ) )
return - V_62 ;
V_87 = F_102 ( V_53 ) ;
V_18 = F_62 ( V_8 , V_13 , F_63 ( V_59 ) , V_68 ) ;
if ( V_18 ) {
F_58 ( V_59 ) ;
return V_18 ;
}
V_111 = F_64 ( F_65 ( unsigned ,
V_114 , V_69 ) , V_61 ) ;
if ( ! V_111 ) {
F_58 ( V_59 ) ;
return - V_62 ;
}
F_107 ( & V_115 ) ;
V_100 = F_108 ( V_2 -> V_101 ) ;
F_105 (cpu) {
V_58 = V_100 ?
F_108 ( V_100 -> V_103 [ V_66 ] ) : NULL ;
V_110 = V_58 ;
if ( V_58 ) {
for ( V_106 = 0 ; V_106 < V_58 -> V_13 ; V_106 ++ )
if ( V_58 -> V_105 [ V_106 ] == V_87 )
break;
V_107 = V_58 -> V_13 ;
V_108 = V_58 -> V_108 ;
} else
V_106 = V_107 = V_108 = 0 ;
V_109 = F_109 ( V_66 , V_59 ) && F_110 ( V_66 ) ;
#ifdef F_111
if ( V_109 ) {
if ( V_113 == - 2 )
V_113 = F_112 ( V_66 ) ;
else if ( V_113 != F_112 ( V_66 ) )
V_113 = - 1 ;
}
#endif
if ( V_109 && V_106 >= V_107 ) {
if ( V_107 >= V_108 ) {
V_108 = V_108 ?
2 * V_108 : V_116 ;
V_110 = F_113 ( F_114 ( V_108 ) ,
V_61 ,
F_112 ( V_66 ) ) ;
if ( ! V_110 )
goto error;
V_110 -> V_108 = V_108 ;
for ( V_60 = 0 ; V_60 < V_107 ; V_60 ++ )
V_110 -> V_105 [ V_60 ] = V_58 -> V_105 [ V_60 ] ;
V_110 -> V_13 = V_107 ;
}
V_110 -> V_105 [ V_110 -> V_13 ++ ] = V_87 ;
} else if ( ! V_109 && V_106 < V_107 ) {
if ( V_107 > 1 )
V_110 -> V_105 [ V_106 ] =
V_110 -> V_105 [ -- V_110 -> V_13 ] ;
else
V_110 = NULL ;
}
F_89 ( V_111 -> V_103 [ V_66 ] , V_110 ) ;
}
F_105 (cpu) {
V_58 = V_100 ?
F_108 ( V_100 -> V_103 [ V_66 ] ) : NULL ;
if ( V_58 && F_108 ( V_111 -> V_103 [ V_66 ] ) != V_58 )
F_75 ( V_58 , V_70 ) ;
if ( V_111 -> V_103 [ V_66 ] )
V_112 = 1 ;
}
if ( V_112 )
F_89 ( V_2 -> V_101 , V_111 ) ;
else {
F_69 ( V_111 ) ;
F_89 ( V_2 -> V_101 , NULL ) ;
}
if ( V_100 )
F_75 ( V_100 , V_70 ) ;
F_115 ( V_53 , ( V_113 >= 0 ) ? V_113 :
V_117 ) ;
F_116 ( & V_115 ) ;
F_58 ( V_59 ) ;
return V_13 ;
error:
F_116 ( & V_115 ) ;
if ( V_111 )
F_105 (i)
F_69 ( F_71 (
V_111 -> V_103 [ V_60 ] ,
1 ) ) ;
F_69 ( V_111 ) ;
F_58 ( V_59 ) ;
return - V_62 ;
}
static void F_117 ( struct V_48 * V_49 )
{
struct V_96 * V_53 = F_100 ( V_49 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_99 * V_100 ;
struct V_102 * V_58 ;
unsigned long V_87 ;
int V_60 , V_106 , V_112 = 0 ;
V_87 = F_102 ( V_53 ) ;
F_107 ( & V_115 ) ;
V_100 = F_108 ( V_2 -> V_101 ) ;
if ( V_100 ) {
F_105 (i) {
V_58 = F_108 ( V_100 -> V_103 [ V_60 ] ) ;
if ( ! V_58 )
continue;
for ( V_106 = 0 ; V_106 < V_58 -> V_13 ; V_106 ++ )
if ( V_58 -> V_105 [ V_106 ] == V_87 )
break;
if ( V_106 < V_58 -> V_13 ) {
if ( V_58 -> V_13 > 1 )
V_58 -> V_105 [ V_106 ] =
V_58 -> V_105 [ -- V_58 -> V_13 ] ;
else {
F_89 ( V_100 -> V_103 [ V_60 ] ,
NULL ) ;
F_75 ( V_58 , V_70 ) ;
V_58 = NULL ;
}
}
if ( V_58 )
V_112 = 1 ;
}
if ( ! V_112 ) {
F_89 ( V_2 -> V_101 , NULL ) ;
F_75 ( V_100 , V_70 ) ;
}
}
F_116 ( & V_115 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_90 ( V_53 -> V_2 ) ;
}
static int F_118 ( struct V_1 * V_9 , int V_87 )
{
struct V_96 * V_53 = V_9 -> V_98 + V_87 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_89 = V_9 -> V_90 ;
error = F_92 ( V_49 , & V_118 , NULL ,
L_7 , V_87 ) ;
if ( error ) {
F_93 ( V_49 ) ;
return error ;
}
F_94 ( V_49 , V_92 ) ;
F_95 ( V_53 -> V_2 ) ;
return error ;
}
int
F_119 ( struct V_1 * V_9 , int V_93 , int V_94 )
{
#ifdef F_120
int V_60 ;
int error = 0 ;
for ( V_60 = V_93 ; V_60 < V_94 ; V_60 ++ ) {
error = F_118 ( V_9 , V_60 ) ;
if ( error ) {
V_94 = V_93 ;
break;
}
}
while ( -- V_60 >= V_94 )
F_93 ( & V_9 -> V_98 [ V_60 ] . V_49 ) ;
return error ;
#else
return 0 ;
#endif
}
static int F_121 ( struct V_1 * V_9 )
{
int error = 0 , V_119 = 0 , V_120 = 0 , V_121 = 0 , V_122 = 0 ;
#if F_122 ( F_97 ) || F_122 ( F_120 )
V_9 -> V_90 = F_123 ( L_8 ,
NULL , & V_9 -> V_2 . V_49 ) ;
if ( ! V_9 -> V_90 )
return - V_62 ;
#endif
#ifdef F_97
V_121 = V_9 -> V_123 ;
#endif
V_122 = V_9 -> V_124 ;
error = F_96 ( V_9 , 0 , V_121 ) ;
if ( error )
goto error;
V_120 = V_121 ;
error = F_119 ( V_9 , 0 , V_122 ) ;
if ( error )
goto error;
V_119 = V_122 ;
return 0 ;
error:
F_119 ( V_9 , V_119 , 0 ) ;
F_96 ( V_9 , V_120 , 0 ) ;
return error ;
}
static void F_124 ( struct V_1 * V_9 )
{
int V_121 = 0 , V_122 = 0 ;
#ifdef F_97
V_121 = V_9 -> V_123 ;
#endif
V_122 = V_9 -> V_124 ;
F_96 ( V_9 , V_121 , 0 ) ;
F_119 ( V_9 , V_122 , 0 ) ;
#if F_122 ( F_97 ) || F_122 ( F_120 )
F_125 ( V_9 -> V_90 ) ;
#endif
}
static void * F_126 ( void )
{
struct V_9 * V_125 = V_126 -> V_127 -> V_128 ;
#ifdef F_127
if ( V_125 )
F_128 ( & V_125 -> V_129 ) ;
#endif
return V_125 ;
}
static const void * F_129 ( void )
{
return & V_130 ;
}
static const void * F_130 ( struct V_131 * V_132 )
{
return F_131 ( V_132 ) ;
}
static int F_132 ( struct V_5 * V_38 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
int V_135 ;
V_135 = F_133 ( V_134 , L_9 , V_2 -> V_136 ) ;
if ( V_135 )
goto exit;
V_135 = F_133 ( V_134 , L_10 , V_2 -> V_137 ) ;
exit:
return V_135 ;
}
static void F_134 ( struct V_5 * V_38 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
F_103 ( V_2 -> V_3 != V_138 ) ;
F_69 ( V_2 -> V_36 ) ;
F_69 ( ( char * ) V_2 - V_2 -> V_139 ) ;
}
static const void * F_135 ( struct V_5 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_38 , struct V_1 , V_2 ) ;
return F_136 ( V_2 ) ;
}
void F_137 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_138 ( & V_2 -> V_49 ) ;
F_124 ( V_9 ) ;
F_139 ( V_2 ) ;
}
int F_140 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_140 * * V_141 = V_9 -> V_142 ;
int error = 0 ;
F_141 ( V_2 ) ;
V_2 -> V_143 = & V_144 ;
V_2 -> V_145 = V_9 ;
V_2 -> V_141 = V_141 ;
F_142 ( V_2 , L_11 , V_9 -> V_136 ) ;
#ifdef F_143
if ( * V_141 )
V_141 ++ ;
* V_141 ++ = & V_146 ;
#ifdef F_144
if ( V_9 -> V_147 )
* V_141 ++ = & V_148 ;
#ifdef F_145
else if ( V_9 -> V_149 )
* V_141 ++ = & V_148 ;
#endif
#endif
#endif
error = F_146 ( V_2 ) ;
if ( error )
return error ;
error = F_121 ( V_9 ) ;
if ( error ) {
F_139 ( V_2 ) ;
return error ;
}
return error ;
}
int F_147 ( struct V_150 * V_151 )
{
return F_148 ( & V_144 , V_151 ) ;
}
void F_149 ( struct V_150 * V_151 )
{
F_150 ( & V_144 , V_151 ) ;
}
int F_151 ( void )
{
F_152 ( & V_152 ) ;
return F_153 ( & V_144 ) ;
}
