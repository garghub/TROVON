int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = V_4 -> V_5 >= V_6 ? V_6 - 1 : V_4 -> V_5 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_4 -> V_8 , V_5 ) ;
if ( ! V_7 )
F_3 ( V_4 ) ;
return V_7 ;
}
enum V_9 F_4 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_16 * V_17 ;
int V_7 ;
F_5 ( V_17 , V_14 ) ;
V_7 = F_6 ( V_4 , V_17 -> V_18 ) ;
if ( ! V_7 )
return V_19 ;
return V_20 ;
}
enum V_9 F_7 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_21 * V_17 ;
int V_7 ;
F_5 ( V_17 , V_14 ) ;
V_7 = F_8 ( V_4 , V_17 -> V_22 , V_17 -> V_23 ) ;
if ( ! V_7 )
return V_19 ;
return V_20 ;
}
enum V_9 F_9 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_24 * V_17 ;
int V_7 ;
F_5 ( V_17 , V_14 ) ;
V_7 = F_6 ( V_4 , V_17 -> V_23 ) ;
if ( ! V_7 )
return V_19 ;
return V_20 ;
}
int
F_10 ( struct V_3 * V_4 , const char * V_22 , ... )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
T_1 V_25 ;
int V_7 ;
if ( V_4 -> V_26 || ! V_5 )
return 0 ;
va_start ( V_25 , V_22 ) ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_22 , V_25 ) ;
va_end ( V_25 ) ;
if ( V_7 >= V_5 ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_7 ;
return 1 ;
}
int
F_11 ( struct V_3 * V_4 , const unsigned long * V_27 ,
int V_28 )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
int V_7 ;
if ( V_4 -> V_26 || ! V_5 )
return 0 ;
V_7 = F_12 ( V_4 -> V_8 , V_5 , V_27 , V_28 ) ;
V_4 -> V_5 += V_7 ;
return 1 ;
}
int
F_13 ( struct V_3 * V_4 , const char * V_22 , T_1 args )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
int V_7 ;
if ( V_4 -> V_26 || ! V_5 )
return 0 ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_22 , args ) ;
if ( V_7 >= V_5 ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_7 ;
return V_5 ;
}
int F_8 ( struct V_3 * V_4 , const char * V_22 , const T_2 * V_29 )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
int V_7 ;
if ( V_4 -> V_26 || ! V_5 )
return 0 ;
V_7 = F_14 ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_22 , V_29 ) ;
if ( V_7 >= V_5 ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_7 ;
return V_5 ;
}
int F_6 ( struct V_3 * V_4 , const char * V_18 )
{
int V_5 = strlen ( V_18 ) ;
if ( V_4 -> V_26 )
return 0 ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_8 + V_4 -> V_5 , V_18 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
int F_15 ( struct V_3 * V_4 , unsigned char V_30 )
{
if ( V_4 -> V_26 )
return 0 ;
if ( V_4 -> V_5 >= ( V_6 - 1 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_4 -> V_8 [ V_4 -> V_5 ++ ] = V_30 ;
return 1 ;
}
int F_16 ( struct V_3 * V_4 , const void * V_31 , T_3 V_5 )
{
if ( V_4 -> V_26 )
return 0 ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_8 + V_4 -> V_5 , V_31 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
void * F_17 ( struct V_3 * V_4 , T_3 V_5 )
{
void * V_7 ;
if ( V_4 -> V_26 )
return NULL ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_26 = 1 ;
return NULL ;
}
V_7 = V_4 -> V_8 + V_4 -> V_5 ;
V_4 -> V_5 += V_5 ;
return V_7 ;
}
int F_18 ( struct V_3 * V_4 , const struct V_32 * V_32 )
{
unsigned char * V_33 ;
if ( V_4 -> V_26 )
return 0 ;
if ( V_4 -> V_5 >= ( V_6 - 1 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_33 = F_19 ( V_32 , V_4 -> V_8 + V_4 -> V_5 , V_6 - V_4 -> V_5 ) ;
if ( ! F_20 ( V_33 ) ) {
V_33 = F_21 ( V_4 -> V_8 + V_4 -> V_5 , V_33 , L_1 ) ;
if ( V_33 ) {
V_4 -> V_5 = V_33 - V_4 -> V_8 ;
return 1 ;
}
} else {
V_4 -> V_8 [ V_4 -> V_5 ++ ] = '?' ;
return 1 ;
}
V_4 -> V_26 = 1 ;
return 0 ;
}
const char *
F_22 ( struct V_3 * V_33 , const char * V_34 ,
unsigned long V_35 ,
const struct V_36 * V_37 )
{
unsigned long V_38 ;
const char * V_18 ;
const char * V_7 = V_33 -> V_8 + V_33 -> V_5 ;
int V_39 , V_40 = 1 ;
for ( V_39 = 0 ; V_37 [ V_39 ] . V_41 && V_35 ; V_39 ++ ) {
V_38 = V_37 [ V_39 ] . V_38 ;
if ( ( V_35 & V_38 ) != V_38 )
continue;
V_18 = V_37 [ V_39 ] . V_41 ;
V_35 &= ~ V_38 ;
if ( ! V_40 && V_34 )
F_6 ( V_33 , V_34 ) ;
else
V_40 = 0 ;
F_6 ( V_33 , V_18 ) ;
}
if ( V_35 ) {
if ( ! V_40 && V_34 )
F_6 ( V_33 , V_34 ) ;
F_10 ( V_33 , L_2 , V_35 ) ;
}
F_15 ( V_33 , 0 ) ;
return V_7 ;
}
const char *
F_23 ( struct V_3 * V_33 , unsigned long V_42 ,
const struct V_36 * V_43 )
{
int V_39 ;
const char * V_7 = V_33 -> V_8 + V_33 -> V_5 ;
for ( V_39 = 0 ; V_43 [ V_39 ] . V_41 ; V_39 ++ ) {
if ( V_42 != V_43 [ V_39 ] . V_38 )
continue;
F_6 ( V_33 , V_43 [ V_39 ] . V_41 ) ;
break;
}
if ( V_7 == ( const char * ) ( V_33 -> V_8 + V_33 -> V_5 ) )
F_10 ( V_33 , L_2 , V_42 ) ;
F_15 ( V_33 , 0 ) ;
return V_7 ;
}
const char *
F_24 ( struct V_3 * V_33 , unsigned long long V_42 ,
const struct V_44 * V_43 )
{
int V_39 ;
const char * V_7 = V_33 -> V_8 + V_33 -> V_5 ;
for ( V_39 = 0 ; V_43 [ V_39 ] . V_41 ; V_39 ++ ) {
if ( V_42 != V_43 [ V_39 ] . V_38 )
continue;
F_6 ( V_33 , V_43 [ V_39 ] . V_41 ) ;
break;
}
if ( V_7 == ( const char * ) ( V_33 -> V_8 + V_33 -> V_5 ) )
F_10 ( V_33 , L_3 , V_42 ) ;
F_15 ( V_33 , 0 ) ;
return V_7 ;
}
const char *
F_25 ( struct V_3 * V_33 , void * V_45 ,
unsigned int V_46 )
{
const char * V_7 = V_33 -> V_8 + V_33 -> V_5 ;
F_11 ( V_33 , V_45 , V_46 * 8 ) ;
F_15 ( V_33 , 0 ) ;
return V_7 ;
}
const char *
F_26 ( struct V_3 * V_33 , const unsigned char * V_23 , int V_47 )
{
int V_39 ;
const char * V_7 = V_33 -> V_8 + V_33 -> V_5 ;
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ )
F_10 ( V_33 , L_4 , V_39 == 0 ? L_5 : L_6 , V_23 [ V_39 ] ) ;
F_15 ( V_33 , 0 ) ;
return V_7 ;
}
int F_27 ( struct V_10 * V_11 ,
struct V_48 * V_48 )
{
struct V_49 * V_50 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_3 * V_33 = & V_11 -> V_51 ;
struct V_13 * V_14 ;
int V_7 ;
V_50 = F_28 ( V_48 , struct V_49 , V_50 ) ;
V_14 = V_11 -> V_15 ;
if ( V_14 -> type != V_50 -> V_50 . type ) {
F_29 ( 1 ) ;
return V_52 ;
}
F_3 ( V_33 ) ;
V_7 = F_10 ( V_4 , L_7 , F_30 ( V_50 ) ) ;
if ( ! V_7 )
return V_19 ;
return 0 ;
}
static int F_31 ( struct V_10 * V_11 , char * V_41 ,
char * V_22 , T_1 V_25 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
int V_7 ;
V_7 = F_10 ( V_4 , L_7 , V_41 ) ;
if ( ! V_7 )
return V_19 ;
V_7 = F_13 ( V_4 , V_22 , V_25 ) ;
if ( ! V_7 )
return V_19 ;
return V_20 ;
}
int F_32 ( struct V_10 * V_11 , char * V_41 , char * V_22 , ... )
{
T_1 V_25 ;
int V_7 ;
va_start ( V_25 , V_22 ) ;
V_7 = F_31 ( V_11 , V_41 , V_22 , V_25 ) ;
va_end ( V_25 ) ;
return V_7 ;
}
static inline const char * F_33 ( const char * V_41 )
{
static const char V_53 [] = L_8 ;
int V_54 = sizeof( V_53 ) ;
if ( strncmp ( V_53 , V_41 , V_54 ) == 0 )
return L_9 ;
return V_41 ;
}
static inline const char * F_33 ( const char * V_41 )
{
return V_41 ;
}
static int
F_34 ( struct V_3 * V_4 , const char * V_22 , unsigned long V_55 )
{
#ifdef F_35
char V_18 [ V_56 ] ;
const char * V_41 ;
F_36 ( V_55 , NULL , NULL , NULL , V_18 ) ;
V_41 = F_33 ( V_18 ) ;
return F_10 ( V_4 , V_22 , V_41 ) ;
#endif
return 1 ;
}
static int
F_37 ( struct V_3 * V_4 , const char * V_22 ,
unsigned long V_55 )
{
#ifdef F_35
char V_18 [ V_56 ] ;
const char * V_41 ;
F_38 ( V_18 , V_55 ) ;
V_41 = F_33 ( V_18 ) ;
return F_10 ( V_4 , V_22 , V_41 ) ;
#endif
return 1 ;
}
int F_39 ( struct V_3 * V_4 , struct V_57 * V_58 ,
unsigned long V_59 , unsigned long V_60 )
{
struct V_61 * V_61 = NULL ;
unsigned long V_62 = 0 ;
int V_7 = 1 ;
if ( V_4 -> V_26 )
return 0 ;
if ( V_58 ) {
const struct V_63 * V_64 ;
F_40 ( & V_58 -> V_65 ) ;
V_64 = F_41 ( V_58 , V_59 ) ;
if ( V_64 ) {
V_61 = V_64 -> V_66 ;
V_62 = V_64 -> V_67 ;
}
if ( V_61 ) {
V_7 = F_18 ( V_4 , & V_61 -> V_68 ) ;
if ( V_7 )
V_7 = F_10 ( V_4 , L_10 ,
V_59 - V_62 ) ;
}
F_42 ( & V_58 -> V_65 ) ;
}
if ( V_7 && ( ( V_60 & V_69 ) || ! V_61 ) )
V_7 = F_10 ( V_4 , L_11 V_70 L_12 , V_59 ) ;
return V_7 ;
}
int
F_43 ( const struct V_71 * V_14 , struct V_3 * V_4 ,
unsigned long V_60 )
{
struct V_57 * V_58 = NULL ;
int V_7 = 1 ;
unsigned int V_39 ;
if ( V_72 & V_73 ) {
struct V_74 * V_75 ;
F_44 () ;
V_75 = F_45 ( V_14 -> V_76 ) ;
if ( V_75 )
V_58 = F_46 ( V_75 ) ;
F_47 () ;
}
for ( V_39 = 0 ; V_39 < V_77 ; V_39 ++ ) {
unsigned long V_59 = V_14 -> V_78 [ V_39 ] ;
if ( V_59 == V_79 || ! V_7 )
break;
if ( V_7 )
V_7 = F_6 ( V_4 , L_13 ) ;
if ( ! V_59 ) {
if ( V_7 )
V_7 = F_6 ( V_4 , L_14 ) ;
if ( V_7 )
V_7 = F_15 ( V_4 , '\n' ) ;
continue;
}
if ( ! V_7 )
break;
if ( V_7 )
V_7 = F_39 ( V_4 , V_58 , V_59 , V_60 ) ;
V_7 = F_15 ( V_4 , '\n' ) ;
}
if ( V_58 )
F_48 ( V_58 ) ;
return V_7 ;
}
int
F_49 ( struct V_3 * V_4 , unsigned long V_59 , unsigned long V_60 )
{
int V_7 ;
if ( ! V_59 )
return F_15 ( V_4 , '0' ) ;
if ( V_60 & V_80 )
V_7 = F_37 ( V_4 , L_15 , V_59 ) ;
else
V_7 = F_34 ( V_4 , L_15 , V_59 ) ;
if ( ! V_7 )
return 0 ;
if ( V_60 & V_69 )
V_7 = F_10 ( V_4 , L_11 V_70 L_12 , V_59 ) ;
return V_7 ;
}
int F_50 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
char V_81 ;
char V_82 ;
char V_83 ;
int V_84 ;
int V_85 ;
int V_7 ;
V_84 = V_14 -> V_35 & V_86 ;
V_85 = V_14 -> V_35 & V_87 ;
V_83 =
( V_14 -> V_35 & V_88 ) ? 'd' :
( V_14 -> V_35 & V_89 ) ? 'X' :
'.' ;
switch ( V_14 -> V_35 & ( V_90 |
V_91 ) ) {
case V_90 | V_91 :
V_82 = 'N' ;
break;
case V_90 :
V_82 = 'n' ;
break;
case V_91 :
V_82 = 'p' ;
break;
default:
V_82 = '.' ;
break;
}
V_81 =
( V_84 && V_85 ) ? 'H' :
V_84 ? 'h' :
V_85 ? 's' :
'.' ;
if ( ! F_10 ( V_4 , L_16 ,
V_83 , V_82 , V_81 ) )
return 0 ;
if ( V_14 -> V_92 )
V_7 = F_10 ( V_4 , L_17 , V_14 -> V_92 ) ;
else
V_7 = F_15 ( V_4 , '.' ) ;
return V_7 ;
}
static int
F_51 ( struct V_3 * V_4 , struct V_13 * V_14 , int V_93 )
{
char V_94 [ V_95 ] ;
F_52 ( V_14 -> V_96 , V_94 ) ;
if ( ! F_10 ( V_4 , L_18 ,
V_94 , V_14 -> V_96 , V_93 ) )
return 0 ;
return F_50 ( V_4 , V_14 ) ;
}
static int
F_53 ( struct V_10 * V_11 , T_4 V_97 )
{
unsigned long V_98 = V_72 & V_99 ;
unsigned long V_100 = V_11 -> V_101 & V_102 ;
unsigned long long V_103 = V_11 -> V_104 - V_11 -> V_105 -> V_106 ;
unsigned long long V_107 = V_97 - V_11 -> V_104 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
if ( V_100 ) {
V_103 = F_54 ( V_103 ) ;
V_107 = F_54 ( V_107 ) ;
}
if ( V_98 && V_100 ) {
unsigned long V_108 = F_55 ( V_103 , V_109 ) ;
unsigned long V_110 = ( unsigned long ) V_103 ;
unsigned long V_111 = F_55 ( V_107 , V_109 ) ;
unsigned long V_112 = ( unsigned long ) V_107 ;
return F_10 (
V_4 , L_19 ,
F_54 ( V_11 -> V_104 ) ,
V_110 , V_108 ,
V_112 , V_111 ) ;
} else if ( V_98 && ! V_100 ) {
return F_10 (
V_4 , L_20 ,
V_11 -> V_104 , V_103 , V_107 ) ;
} else if ( ! V_98 && V_100 ) {
return F_10 (
V_4 , L_21 ,
V_103 ,
V_107 > V_113 ? '!' :
V_107 > 1 ? '+' : ' ' ) ;
} else {
return F_10 ( V_4 , L_22 , V_103 ) ;
}
}
int F_56 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned long long V_114 ;
unsigned long V_115 , V_116 ;
char V_94 [ V_95 ] ;
int V_7 ;
F_52 ( V_14 -> V_96 , V_94 ) ;
V_7 = F_10 ( V_4 , L_23 ,
V_94 , V_14 -> V_96 , V_11 -> V_93 ) ;
if ( ! V_7 )
return 0 ;
if ( V_72 & V_117 ) {
V_7 = F_50 ( V_4 , V_14 ) ;
if ( ! V_7 )
return 0 ;
}
if ( V_11 -> V_101 & V_102 ) {
V_114 = F_54 ( V_11 -> V_104 ) ;
V_116 = F_55 ( V_114 , V_118 ) ;
V_115 = ( unsigned long ) V_114 ;
return F_10 ( V_4 , L_24 , V_115 , V_116 ) ;
} else
return F_10 ( V_4 , L_25 , V_11 -> V_104 ) ;
}
int F_57 ( struct V_10 * V_11 )
{
T_4 V_97 ;
int V_7 ;
int V_119 = V_11 -> V_119 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ,
* V_120 = F_58 ( V_11 , NULL ,
& V_97 ) ;
unsigned long V_98 = ( V_72 & V_99 ) ;
V_11 -> V_119 = V_119 ;
if ( ! V_120 )
V_97 = V_11 -> V_104 ;
if ( V_98 ) {
char V_94 [ V_95 ] ;
F_52 ( V_14 -> V_96 , V_94 ) ;
V_7 = F_10 (
V_4 , L_26 ,
V_94 , V_14 -> V_96 , V_11 -> V_93 , V_14 -> V_35 ,
V_14 -> V_92 , V_11 -> V_121 ) ;
} else {
V_7 = F_51 ( V_4 , V_14 , V_11 -> V_93 ) ;
}
if ( V_7 )
V_7 = F_53 ( V_11 , V_97 ) ;
return V_7 ;
}
static int F_59 ( unsigned long V_122 )
{
int V_123 = V_122 ? F_60 ( V_122 ) + 1 : 0 ;
return V_123 < sizeof( V_124 ) - 1 ? V_124 [ V_123 ] : '?' ;
}
struct V_48 * F_61 ( int type )
{
struct V_48 * V_50 ;
unsigned V_125 ;
V_125 = type & ( V_126 - 1 ) ;
F_62 (event, &event_hash[key], node) {
if ( V_50 -> type == type )
return V_50 ;
}
return NULL ;
}
static int F_63 ( struct V_127 * * V_128 )
{
struct V_48 * V_129 ;
int V_130 = V_131 ;
if ( F_64 ( & V_132 ) ) {
* V_128 = & V_132 ;
return V_130 + 1 ;
}
F_65 (e, &ftrace_event_list, list) {
if ( V_129 -> type != V_130 + 1 )
break;
V_130 ++ ;
}
if ( ( V_130 + 1 ) > V_133 )
return 0 ;
* V_128 = & V_129 -> V_128 ;
return V_130 + 1 ;
}
void F_66 ( void )
{
F_40 ( & V_134 ) ;
}
void F_67 ( void )
{
F_42 ( & V_134 ) ;
}
int F_68 ( struct V_48 * V_50 )
{
unsigned V_125 ;
int V_7 = 0 ;
F_69 ( & V_134 ) ;
if ( F_70 ( ! V_50 ) )
goto V_135;
if ( F_70 ( ! V_50 -> V_136 ) )
goto V_135;
F_71 ( & V_50 -> V_128 ) ;
if ( ! V_50 -> type ) {
struct V_127 * V_128 = NULL ;
if ( V_137 > V_133 ) {
V_50 -> type = F_63 ( & V_128 ) ;
if ( ! V_50 -> type )
goto V_135;
} else {
V_50 -> type = V_137 ++ ;
V_128 = & V_132 ;
}
if ( F_70 ( F_61 ( V_50 -> type ) ) )
goto V_135;
F_72 ( & V_50 -> V_128 , V_128 ) ;
} else if ( V_50 -> type > V_131 ) {
F_73 ( V_138 L_27 ) ;
F_70 ( 1 ) ;
goto V_135;
} else {
if ( F_61 ( V_50 -> type ) )
goto V_135;
}
if ( V_50 -> V_136 -> V_139 == NULL )
V_50 -> V_136 -> V_139 = V_140 ;
if ( V_50 -> V_136 -> V_141 == NULL )
V_50 -> V_136 -> V_141 = V_140 ;
if ( V_50 -> V_136 -> V_142 == NULL )
V_50 -> V_136 -> V_142 = V_140 ;
if ( V_50 -> V_136 -> V_29 == NULL )
V_50 -> V_136 -> V_29 = V_140 ;
V_125 = V_50 -> type & ( V_126 - 1 ) ;
F_74 ( & V_50 -> V_143 , & V_144 [ V_125 ] ) ;
V_7 = V_50 -> type ;
V_135:
F_75 ( & V_134 ) ;
return V_7 ;
}
int F_76 ( struct V_48 * V_50 )
{
F_77 ( & V_50 -> V_143 ) ;
F_78 ( & V_50 -> V_128 ) ;
return 0 ;
}
int F_79 ( struct V_48 * V_50 )
{
F_69 ( & V_134 ) ;
F_76 ( V_50 ) ;
F_75 ( & V_134 ) ;
return 0 ;
}
enum V_9 V_140 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
if ( ! F_10 ( & V_11 -> V_12 , L_28 , V_11 -> V_15 -> type ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_80 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_145 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_49 ( V_4 , V_17 -> V_59 , V_35 ) )
goto V_146;
if ( ( V_35 & V_147 ) && V_17 -> V_148 ) {
if ( ! F_6 ( V_4 , L_29 ) )
goto V_146;
if ( ! F_49 ( V_4 ,
V_17 -> V_148 ,
V_35 ) )
goto V_146;
}
if ( ! F_15 ( V_4 , '\n' ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9 F_81 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_145 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( & V_11 -> V_12 , L_30 ,
V_17 -> V_59 ,
V_17 -> V_148 ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_82 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_145 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_83 ( V_4 , V_17 -> V_59 ) ;
F_83 ( V_4 , V_17 -> V_148 ) ;
return V_20 ;
}
static enum V_9 F_84 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_145 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_85 ( V_4 , V_17 -> V_59 ) ;
F_85 ( V_4 , V_17 -> V_148 ) ;
return V_20 ;
}
static enum V_9 F_86 ( struct V_10 * V_11 ,
char * V_34 )
{
struct V_149 * V_17 ;
char V_94 [ V_95 ] ;
int V_150 , V_151 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_151 = F_59 ( V_17 -> V_152 ) ;
V_150 = F_59 ( V_17 -> V_153 ) ;
F_52 ( V_17 -> V_154 , V_94 ) ;
if ( ! F_10 ( & V_11 -> V_12 ,
L_31 ,
V_17 -> V_155 ,
V_17 -> V_156 ,
V_150 , V_34 ,
V_17 -> V_157 ,
V_17 -> V_154 ,
V_17 -> V_158 ,
V_151 , V_94 ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_87 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
return F_86 ( V_11 , L_32 ) ;
}
static enum V_9 F_88 ( struct V_10 * V_11 ,
int V_35 , struct V_48 * V_50 )
{
return F_86 ( V_11 , L_33 ) ;
}
static int F_89 ( struct V_10 * V_11 , char V_150 )
{
struct V_149 * V_17 ;
int V_151 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_150 )
V_150 = F_59 ( V_17 -> V_153 ) ;
V_151 = F_59 ( V_17 -> V_152 ) ;
if ( ! F_10 ( & V_11 -> V_12 , L_34 ,
V_17 -> V_155 ,
V_17 -> V_156 ,
V_150 ,
V_17 -> V_157 ,
V_17 -> V_154 ,
V_17 -> V_158 ,
V_151 ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_90 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
return F_89 ( V_11 , 0 ) ;
}
static enum V_9 F_91 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
return F_89 ( V_11 , '+' ) ;
}
static int F_92 ( struct V_10 * V_11 , char V_150 )
{
struct V_149 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
int V_151 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_150 )
V_150 = F_59 ( V_17 -> V_153 ) ;
V_151 = F_59 ( V_17 -> V_152 ) ;
F_83 ( V_4 , V_17 -> V_155 ) ;
F_83 ( V_4 , V_17 -> V_156 ) ;
F_83 ( V_4 , V_150 ) ;
F_83 ( V_4 , V_17 -> V_157 ) ;
F_83 ( V_4 , V_17 -> V_154 ) ;
F_83 ( V_4 , V_17 -> V_158 ) ;
F_83 ( V_4 , V_151 ) ;
return V_20 ;
}
static enum V_9 F_93 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
return F_92 ( V_11 , 0 ) ;
}
static enum V_9 F_94 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
return F_92 ( V_11 , '+' ) ;
}
static enum V_9 F_95 ( struct V_10 * V_11 ,
int V_35 , struct V_48 * V_50 )
{
struct V_149 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_85 ( V_4 , V_17 -> V_155 ) ;
F_85 ( V_4 , V_17 -> V_156 ) ;
F_85 ( V_4 , V_17 -> V_153 ) ;
F_85 ( V_4 , V_17 -> V_154 ) ;
F_85 ( V_4 , V_17 -> V_158 ) ;
F_85 ( V_4 , V_17 -> V_152 ) ;
return V_20 ;
}
static enum V_9 F_96 ( struct V_10 * V_11 ,
int V_35 , struct V_48 * V_50 )
{
struct V_159 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
unsigned long * V_33 ;
unsigned long * V_160 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_160 = ( unsigned long * ) ( ( long ) V_11 -> V_15 + V_11 -> V_119 ) ;
if ( ! F_6 ( V_4 , L_35 ) )
goto V_146;
for ( V_33 = V_17 -> V_78 ; V_33 && * V_33 != V_79 && V_33 < V_160 ; V_33 ++ ) {
if ( ! F_6 ( V_4 , L_13 ) )
goto V_146;
if ( ! F_49 ( V_4 , * V_33 , V_35 ) )
goto V_146;
if ( ! F_15 ( V_4 , '\n' ) )
goto V_146;
}
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9 F_97 ( struct V_10 * V_11 ,
int V_35 , struct V_48 * V_50 )
{
struct V_71 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_6 ( V_4 , L_36 ) )
goto V_146;
if ( ! F_43 ( V_17 , V_4 , V_35 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9
F_98 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_16 * V_17 ;
F_5 ( V_17 , V_14 ) ;
if ( ! F_49 ( V_4 , V_17 -> V_59 , V_35 ) )
goto V_146;
if ( ! F_6 ( V_4 , L_37 ) )
goto V_146;
if ( ! F_6 ( V_4 , V_17 -> V_18 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9
F_99 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( V_4 , L_38 , V_17 -> V_59 ) )
goto V_146;
if ( ! F_6 ( V_4 , V_17 -> V_18 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9
F_100 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_21 * V_17 ;
F_5 ( V_17 , V_14 ) ;
if ( ! F_49 ( V_4 , V_17 -> V_59 , V_35 ) )
goto V_146;
if ( ! F_6 ( V_4 , L_37 ) )
goto V_146;
if ( ! F_8 ( V_4 , V_17 -> V_22 , V_17 -> V_23 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9
F_101 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_21 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( V_4 , L_38 , V_17 -> V_59 ) )
goto V_146;
if ( ! F_8 ( V_4 , V_17 -> V_22 , V_17 -> V_23 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9 F_102 ( struct V_10 * V_11 ,
int V_35 , struct V_48 * V_50 )
{
struct V_24 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_49 ( V_4 , V_17 -> V_59 , V_35 ) )
goto V_146;
if ( ! F_10 ( V_4 , L_39 , V_17 -> V_23 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
static enum V_9 F_103 ( struct V_10 * V_11 , int V_35 ,
struct V_48 * V_50 )
{
struct V_24 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( & V_11 -> V_12 , L_40 , V_17 -> V_59 , V_17 -> V_23 ) )
goto V_146;
return V_20 ;
V_146:
return V_19 ;
}
T_5 static int F_104 ( void )
{
struct V_48 * V_50 ;
int V_39 , V_7 ;
for ( V_39 = 0 ; V_161 [ V_39 ] ; V_39 ++ ) {
V_50 = V_161 [ V_39 ] ;
V_7 = F_68 ( V_50 ) ;
if ( ! V_7 ) {
F_73 ( V_138 L_41 ,
V_50 -> type ) ;
F_29 ( 1 ) ;
}
}
return 0 ;
}
