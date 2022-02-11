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
if ( V_35 > 1 << 30 ) {
return - V_11 ;
}
V_35 = F_84 ( V_35 ) ;
V_77 = F_85 ( F_86 ( V_35 ) ) ;
if ( ! V_77 )
return - V_62 ;
V_77 -> V_59 = V_35 - 1 ;
for ( V_60 = 0 ; V_60 < V_35 ; V_60 ++ )
V_77 -> V_82 [ V_60 ] . V_66 = V_83 ;
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
V_58 = F_89 ( V_53 -> V_57 ) ;
if ( V_58 ) {
F_90 ( V_53 -> V_57 , NULL ) ;
F_75 ( V_58 , V_70 ) ;
}
V_72 = F_89 ( V_53 -> V_74 ) ;
if ( V_72 ) {
F_90 ( V_53 -> V_74 , NULL ) ;
F_87 ( & V_72 -> V_70 , F_80 ) ;
}
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_91 ( V_53 -> V_2 ) ;
}
static int F_92 ( struct V_1 * V_9 , int V_84 )
{
struct V_52 * V_53 = V_9 -> V_85 + V_84 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_86 = V_9 -> V_87 ;
error = F_93 ( V_49 , & V_88 , NULL ,
L_6 , V_84 ) ;
if ( error ) {
F_94 ( V_49 ) ;
return error ;
}
F_95 ( V_49 , V_89 ) ;
F_96 ( V_53 -> V_2 ) ;
return error ;
}
int
F_97 ( struct V_1 * V_9 , int V_90 , int V_91 )
{
#ifdef F_98
int V_60 ;
int error = 0 ;
for ( V_60 = V_90 ; V_60 < V_91 ; V_60 ++ ) {
error = F_92 ( V_9 , V_60 ) ;
if ( error ) {
V_91 = V_90 ;
break;
}
}
while ( -- V_60 >= V_91 )
F_94 ( & V_9 -> V_85 [ V_60 ] . V_49 ) ;
return error ;
#else
return 0 ;
#endif
}
static T_1 F_99 ( struct V_48 * V_49 ,
struct V_50 * V_7 , char * V_8 )
{
struct V_92 * V_50 = F_100 ( V_7 ) ;
struct V_93 * V_53 = F_101 ( V_49 ) ;
if ( ! V_50 -> V_54 )
return - V_55 ;
return V_50 -> V_54 ( V_53 , V_50 , V_8 ) ;
}
static T_1 F_102 ( struct V_48 * V_49 ,
struct V_50 * V_7 ,
const char * V_8 , T_2 V_35 )
{
struct V_92 * V_50 = F_100 ( V_7 ) ;
struct V_93 * V_53 = F_101 ( V_49 ) ;
if ( ! V_50 -> V_56 )
return - V_55 ;
return V_50 -> V_56 ( V_53 , V_50 , V_8 , V_35 ) ;
}
static inline unsigned int F_103 ( struct V_93 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_94 ; V_60 ++ )
if ( V_53 == & V_2 -> V_95 [ V_60 ] )
break;
F_104 ( V_60 >= V_2 -> V_94 ) ;
return V_60 ;
}
static T_1 F_105 ( struct V_93 * V_53 ,
struct V_92 * V_50 , char * V_8 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_96 * V_97 ;
T_3 V_59 ;
unsigned long V_84 ;
T_2 V_13 = 0 ;
int V_60 ;
if ( ! F_52 ( & V_59 , V_61 ) )
return - V_62 ;
V_84 = F_103 ( V_53 ) ;
F_53 () ;
V_97 = F_54 ( V_2 -> V_98 ) ;
if ( V_97 ) {
F_106 (i) {
struct V_99 * V_58 =
F_54 ( V_97 -> V_100 [ V_60 ] ) ;
if ( V_58 ) {
int V_101 ;
for ( V_101 = 0 ; V_101 < V_58 -> V_13 ; V_101 ++ ) {
if ( V_58 -> V_102 [ V_101 ] == V_84 ) {
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
static T_1 F_107 ( struct V_93 * V_53 ,
struct V_92 * V_50 ,
const char * V_8 , T_2 V_13 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_3 V_59 ;
int V_18 , V_60 , V_66 , V_103 , V_104 , V_105 , V_106 ;
unsigned long V_84 ;
struct V_99 * V_58 , * V_107 ;
struct V_96 * V_97 , * V_108 ;
int V_109 = 0 ;
int V_110 = - 2 ;
if ( ! F_9 ( V_16 ) )
return - V_17 ;
if ( ! F_61 ( & V_59 , V_61 ) )
return - V_62 ;
V_84 = F_103 ( V_53 ) ;
V_18 = F_62 ( V_8 , V_13 , F_63 ( V_59 ) , V_68 ) ;
if ( V_18 ) {
F_58 ( V_59 ) ;
return V_18 ;
}
V_108 = F_64 ( F_65 ( unsigned ,
V_111 , V_69 ) , V_61 ) ;
if ( ! V_108 ) {
F_58 ( V_59 ) ;
return - V_62 ;
}
F_108 ( & V_112 ) ;
V_97 = F_109 ( V_2 -> V_98 ) ;
F_106 (cpu) {
V_58 = V_97 ?
F_109 ( V_97 -> V_100 [ V_66 ] ) : NULL ;
V_107 = V_58 ;
if ( V_58 ) {
for ( V_103 = 0 ; V_103 < V_58 -> V_13 ; V_103 ++ )
if ( V_58 -> V_102 [ V_103 ] == V_84 )
break;
V_104 = V_58 -> V_13 ;
V_105 = V_58 -> V_105 ;
} else
V_103 = V_104 = V_105 = 0 ;
V_106 = F_110 ( V_66 , V_59 ) && F_111 ( V_66 ) ;
#ifdef F_112
if ( V_106 ) {
if ( V_110 == - 2 )
V_110 = F_113 ( V_66 ) ;
else if ( V_110 != F_113 ( V_66 ) )
V_110 = - 1 ;
}
#endif
if ( V_106 && V_103 >= V_104 ) {
if ( V_104 >= V_105 ) {
V_105 = V_105 ?
2 * V_105 : V_113 ;
V_107 = F_114 ( F_115 ( V_105 ) ,
V_61 ,
F_113 ( V_66 ) ) ;
if ( ! V_107 )
goto error;
V_107 -> V_105 = V_105 ;
for ( V_60 = 0 ; V_60 < V_104 ; V_60 ++ )
V_107 -> V_102 [ V_60 ] = V_58 -> V_102 [ V_60 ] ;
V_107 -> V_13 = V_104 ;
}
V_107 -> V_102 [ V_107 -> V_13 ++ ] = V_84 ;
} else if ( ! V_106 && V_103 < V_104 ) {
if ( V_104 > 1 )
V_107 -> V_102 [ V_103 ] =
V_107 -> V_102 [ -- V_107 -> V_13 ] ;
else
V_107 = NULL ;
}
F_90 ( V_108 -> V_100 [ V_66 ] , V_107 ) ;
}
F_106 (cpu) {
V_58 = V_97 ?
F_109 ( V_97 -> V_100 [ V_66 ] ) : NULL ;
if ( V_58 && F_109 ( V_108 -> V_100 [ V_66 ] ) != V_58 )
F_75 ( V_58 , V_70 ) ;
if ( V_108 -> V_100 [ V_66 ] )
V_109 = 1 ;
}
if ( V_109 )
F_73 ( V_2 -> V_98 , V_108 ) ;
else {
F_69 ( V_108 ) ;
F_73 ( V_2 -> V_98 , NULL ) ;
}
if ( V_97 )
F_75 ( V_97 , V_70 ) ;
F_116 ( V_53 , ( V_110 >= 0 ) ? V_110 :
V_114 ) ;
F_117 ( & V_112 ) ;
F_58 ( V_59 ) ;
return V_13 ;
error:
F_117 ( & V_112 ) ;
if ( V_108 )
F_106 (i)
F_69 ( F_71 (
V_108 -> V_100 [ V_60 ] ,
1 ) ) ;
F_69 ( V_108 ) ;
F_58 ( V_59 ) ;
return - V_62 ;
}
static void F_118 ( struct V_48 * V_49 )
{
struct V_93 * V_53 = F_101 ( V_49 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_96 * V_97 ;
struct V_99 * V_58 ;
unsigned long V_84 ;
int V_60 , V_103 , V_109 = 0 ;
V_84 = F_103 ( V_53 ) ;
F_108 ( & V_112 ) ;
V_97 = F_109 ( V_2 -> V_98 ) ;
if ( V_97 ) {
F_106 (i) {
V_58 = F_109 ( V_97 -> V_100 [ V_60 ] ) ;
if ( ! V_58 )
continue;
for ( V_103 = 0 ; V_103 < V_58 -> V_13 ; V_103 ++ )
if ( V_58 -> V_102 [ V_103 ] == V_84 )
break;
if ( V_103 < V_58 -> V_13 ) {
if ( V_58 -> V_13 > 1 )
V_58 -> V_102 [ V_103 ] =
V_58 -> V_102 [ -- V_58 -> V_13 ] ;
else {
F_90 ( V_97 -> V_100 [ V_60 ] ,
NULL ) ;
F_75 ( V_58 , V_70 ) ;
V_58 = NULL ;
}
}
if ( V_58 )
V_109 = 1 ;
}
if ( ! V_109 ) {
F_90 ( V_2 -> V_98 , NULL ) ;
F_75 ( V_97 , V_70 ) ;
}
}
F_117 ( & V_112 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_91 ( V_53 -> V_2 ) ;
}
static int F_119 ( struct V_1 * V_9 , int V_84 )
{
struct V_93 * V_53 = V_9 -> V_95 + V_84 ;
struct V_48 * V_49 = & V_53 -> V_49 ;
int error = 0 ;
V_49 -> V_86 = V_9 -> V_87 ;
error = F_93 ( V_49 , & V_115 , NULL ,
L_7 , V_84 ) ;
if ( error ) {
F_94 ( V_49 ) ;
return error ;
}
F_95 ( V_49 , V_89 ) ;
F_96 ( V_53 -> V_2 ) ;
return error ;
}
int
F_120 ( struct V_1 * V_9 , int V_90 , int V_91 )
{
#ifdef F_121
int V_60 ;
int error = 0 ;
for ( V_60 = V_90 ; V_60 < V_91 ; V_60 ++ ) {
error = F_119 ( V_9 , V_60 ) ;
if ( error ) {
V_91 = V_90 ;
break;
}
}
while ( -- V_60 >= V_91 )
F_94 ( & V_9 -> V_95 [ V_60 ] . V_49 ) ;
return error ;
#else
return 0 ;
#endif
}
static int F_122 ( struct V_1 * V_9 )
{
int error = 0 , V_116 = 0 , V_117 = 0 , V_118 = 0 , V_119 = 0 ;
#if F_123 ( F_98 ) || F_123 ( F_121 )
V_9 -> V_87 = F_124 ( L_8 ,
NULL , & V_9 -> V_2 . V_49 ) ;
if ( ! V_9 -> V_87 )
return - V_62 ;
#endif
#ifdef F_98
V_118 = V_9 -> V_120 ;
#endif
V_119 = V_9 -> V_121 ;
error = F_97 ( V_9 , 0 , V_118 ) ;
if ( error )
goto error;
V_117 = V_118 ;
error = F_120 ( V_9 , 0 , V_119 ) ;
if ( error )
goto error;
V_116 = V_119 ;
return 0 ;
error:
F_120 ( V_9 , V_116 , 0 ) ;
F_97 ( V_9 , V_117 , 0 ) ;
return error ;
}
static void F_125 ( struct V_1 * V_9 )
{
int V_118 = 0 , V_119 = 0 ;
#ifdef F_98
V_118 = V_9 -> V_120 ;
#endif
V_119 = V_9 -> V_121 ;
F_97 ( V_9 , V_118 , 0 ) ;
F_120 ( V_9 , V_119 , 0 ) ;
#if F_123 ( F_98 ) || F_123 ( F_121 )
F_126 ( V_9 -> V_87 ) ;
#endif
}
static void * F_127 ( void )
{
struct V_9 * V_122 = V_123 -> V_124 -> V_125 ;
#ifdef F_128
if ( V_122 )
F_129 ( & V_122 -> V_126 ) ;
#endif
return V_122 ;
}
static const void * F_130 ( void )
{
return & V_127 ;
}
static const void * F_131 ( struct V_128 * V_129 )
{
return F_132 ( V_129 ) ;
}
static int F_133 ( struct V_5 * V_38 , struct V_130 * V_131 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
int V_132 ;
V_132 = F_134 ( V_131 , L_9 , V_2 -> V_133 ) ;
if ( V_132 )
goto exit;
V_132 = F_134 ( V_131 , L_10 , V_2 -> V_134 ) ;
exit:
return V_132 ;
}
static void F_135 ( struct V_5 * V_38 )
{
struct V_1 * V_2 = F_4 ( V_38 ) ;
F_104 ( V_2 -> V_3 != V_135 ) ;
F_69 ( V_2 -> V_36 ) ;
F_69 ( ( char * ) V_2 - V_2 -> V_136 ) ;
}
static const void * F_136 ( struct V_5 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_38 , struct V_1 , V_2 ) ;
return F_137 ( V_2 ) ;
}
void F_138 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
F_139 ( & V_2 -> V_49 ) ;
F_125 ( V_9 ) ;
F_140 ( V_2 ) ;
}
int F_141 ( struct V_1 * V_9 )
{
struct V_5 * V_2 = & ( V_9 -> V_2 ) ;
const struct V_137 * * V_138 = V_9 -> V_139 ;
int error = 0 ;
F_142 ( V_2 ) ;
V_2 -> V_140 = & V_141 ;
V_2 -> V_142 = V_9 ;
V_2 -> V_138 = V_138 ;
F_143 ( V_2 , L_11 , V_9 -> V_133 ) ;
#ifdef F_144
if ( * V_138 )
V_138 ++ ;
* V_138 ++ = & V_143 ;
#ifdef F_145
if ( V_9 -> V_144 )
* V_138 ++ = & V_145 ;
#ifdef F_146
else if ( V_9 -> V_146 )
* V_138 ++ = & V_145 ;
#endif
#endif
#endif
error = F_147 ( V_2 ) ;
if ( error )
return error ;
error = F_122 ( V_9 ) ;
if ( error ) {
F_140 ( V_2 ) ;
return error ;
}
return error ;
}
int F_148 ( struct V_147 * V_148 )
{
return F_149 ( & V_141 , V_148 ) ;
}
void F_150 ( struct V_147 * V_148 )
{
F_151 ( & V_141 , V_148 ) ;
}
int F_152 ( void )
{
F_153 ( & V_149 ) ;
return F_154 ( & V_141 ) ;
}
