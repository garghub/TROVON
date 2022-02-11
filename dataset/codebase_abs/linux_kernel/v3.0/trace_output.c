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
V_7 = F_6 ( V_4 , V_17 -> V_18 , V_17 -> V_19 ) ;
if ( ! V_7 )
return V_20 ;
return V_21 ;
}
enum V_9 F_7 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_22 * V_17 ;
int V_7 ;
F_5 ( V_17 , V_14 ) ;
V_7 = F_8 ( V_4 , L_1 , V_17 -> V_19 ) ;
if ( ! V_7 )
return V_20 ;
return V_21 ;
}
int
F_8 ( struct V_3 * V_4 , const char * V_18 , ... )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
T_1 V_23 ;
int V_7 ;
if ( V_4 -> V_24 || ! V_5 )
return 0 ;
va_start ( V_23 , V_18 ) ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_18 , V_23 ) ;
va_end ( V_23 ) ;
if ( V_7 >= V_5 ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_7 ;
return 1 ;
}
int
F_9 ( struct V_3 * V_4 , const char * V_18 , T_1 args )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
int V_7 ;
if ( V_4 -> V_24 || ! V_5 )
return 0 ;
V_7 = vsnprintf ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_18 , args ) ;
if ( V_7 >= V_5 ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_7 ;
return V_5 ;
}
int F_6 ( struct V_3 * V_4 , const char * V_18 , const T_2 * V_25 )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
int V_7 ;
if ( V_4 -> V_24 || ! V_5 )
return 0 ;
V_7 = F_10 ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_18 , V_25 ) ;
if ( V_7 >= V_5 ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
V_4 -> V_5 += V_7 ;
return V_5 ;
}
int F_11 ( struct V_3 * V_4 , const char * V_26 )
{
int V_5 = strlen ( V_26 ) ;
if ( V_4 -> V_24 )
return 0 ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_8 + V_4 -> V_5 , V_26 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
int F_12 ( struct V_3 * V_4 , unsigned char V_27 )
{
if ( V_4 -> V_24 )
return 0 ;
if ( V_4 -> V_5 >= ( V_6 - 1 ) ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
V_4 -> V_8 [ V_4 -> V_5 ++ ] = V_27 ;
return 1 ;
}
int F_13 ( struct V_3 * V_4 , const void * V_28 , T_3 V_5 )
{
if ( V_4 -> V_24 )
return 0 ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_8 + V_4 -> V_5 , V_28 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
void * F_14 ( struct V_3 * V_4 , T_3 V_5 )
{
void * V_7 ;
if ( V_4 -> V_24 )
return NULL ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_24 = 1 ;
return NULL ;
}
V_7 = V_4 -> V_8 + V_4 -> V_5 ;
V_4 -> V_5 += V_5 ;
return V_7 ;
}
int F_15 ( struct V_3 * V_4 , struct V_29 * V_29 )
{
unsigned char * V_30 ;
if ( V_4 -> V_24 )
return 0 ;
if ( V_4 -> V_5 >= ( V_6 - 1 ) ) {
V_4 -> V_24 = 1 ;
return 0 ;
}
V_30 = F_16 ( V_29 , V_4 -> V_8 + V_4 -> V_5 , V_6 - V_4 -> V_5 ) ;
if ( ! F_17 ( V_30 ) ) {
V_30 = F_18 ( V_4 -> V_8 + V_4 -> V_5 , V_30 , L_2 ) ;
if ( V_30 ) {
V_4 -> V_5 = V_30 - V_4 -> V_8 ;
return 1 ;
}
} else {
V_4 -> V_8 [ V_4 -> V_5 ++ ] = '?' ;
return 1 ;
}
V_4 -> V_24 = 1 ;
return 0 ;
}
const char *
F_19 ( struct V_3 * V_30 , const char * V_31 ,
unsigned long V_32 ,
const struct V_33 * V_34 )
{
unsigned long V_35 ;
const char * V_26 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
int V_36 ;
for ( V_36 = 0 ; V_34 [ V_36 ] . V_37 && V_32 ; V_36 ++ ) {
V_35 = V_34 [ V_36 ] . V_35 ;
if ( ( V_32 & V_35 ) != V_35 )
continue;
V_26 = V_34 [ V_36 ] . V_37 ;
V_32 &= ~ V_35 ;
if ( V_30 -> V_5 && V_31 )
F_11 ( V_30 , V_31 ) ;
F_11 ( V_30 , V_26 ) ;
}
if ( V_32 ) {
if ( V_30 -> V_5 && V_31 )
F_11 ( V_30 , V_31 ) ;
F_8 ( V_30 , L_3 , V_32 ) ;
}
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
const char *
F_20 ( struct V_3 * V_30 , unsigned long V_38 ,
const struct V_33 * V_39 )
{
int V_36 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
for ( V_36 = 0 ; V_39 [ V_36 ] . V_37 ; V_36 ++ ) {
if ( V_38 != V_39 [ V_36 ] . V_35 )
continue;
F_11 ( V_30 , V_39 [ V_36 ] . V_37 ) ;
break;
}
if ( ! V_30 -> V_5 )
F_8 ( V_30 , L_3 , V_38 ) ;
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
const char *
F_21 ( struct V_3 * V_30 , unsigned long long V_38 ,
const struct V_40 * V_39 )
{
int V_36 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
for ( V_36 = 0 ; V_39 [ V_36 ] . V_37 ; V_36 ++ ) {
if ( V_38 != V_39 [ V_36 ] . V_35 )
continue;
F_11 ( V_30 , V_39 [ V_36 ] . V_37 ) ;
break;
}
if ( ! V_30 -> V_5 )
F_8 ( V_30 , L_4 , V_38 ) ;
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
const char *
F_22 ( struct V_3 * V_30 , const unsigned char * V_19 , int V_41 )
{
int V_36 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
for ( V_36 = 0 ; V_36 < V_41 ; V_36 ++ )
F_8 ( V_30 , L_5 , V_36 == 0 ? L_6 : L_7 , V_19 [ V_36 ] ) ;
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
static inline const char * F_23 ( const char * V_37 )
{
static const char V_42 [] = L_8 ;
int V_43 = sizeof( V_42 ) ;
if ( strncmp ( V_42 , V_37 , V_43 ) == 0 )
return L_9 ;
return V_37 ;
}
static inline const char * F_23 ( const char * V_37 )
{
return V_37 ;
}
static int
F_24 ( struct V_3 * V_4 , const char * V_18 , unsigned long V_44 )
{
#ifdef F_25
char V_26 [ V_45 ] ;
const char * V_37 ;
F_26 ( V_44 , NULL , NULL , NULL , V_26 ) ;
V_37 = F_23 ( V_26 ) ;
return F_8 ( V_4 , V_18 , V_37 ) ;
#endif
return 1 ;
}
static int
F_27 ( struct V_3 * V_4 , const char * V_18 ,
unsigned long V_44 )
{
#ifdef F_25
char V_26 [ V_45 ] ;
const char * V_37 ;
F_28 ( V_26 , V_44 ) ;
V_37 = F_23 ( V_26 ) ;
return F_8 ( V_4 , V_18 , V_37 ) ;
#endif
return 1 ;
}
int F_29 ( struct V_3 * V_4 , struct V_46 * V_47 ,
unsigned long V_48 , unsigned long V_49 )
{
struct V_50 * V_50 = NULL ;
unsigned long V_51 = 0 ;
int V_7 = 1 ;
if ( V_4 -> V_24 )
return 0 ;
if ( V_47 ) {
const struct V_52 * V_53 ;
F_30 ( & V_47 -> V_54 ) ;
V_53 = F_31 ( V_47 , V_48 ) ;
if ( V_53 ) {
V_50 = V_53 -> V_55 ;
V_51 = V_53 -> V_56 ;
}
if ( V_50 ) {
V_7 = F_15 ( V_4 , & V_50 -> V_57 ) ;
if ( V_7 )
V_7 = F_8 ( V_4 , L_10 ,
V_48 - V_51 ) ;
}
F_32 ( & V_47 -> V_54 ) ;
}
if ( V_7 && ( ( V_49 & V_58 ) || ! V_50 ) )
V_7 = F_8 ( V_4 , L_11 V_59 L_12 , V_48 ) ;
return V_7 ;
}
int
F_33 ( const struct V_60 * V_14 , struct V_3 * V_4 ,
unsigned long V_49 )
{
struct V_46 * V_47 = NULL ;
int V_7 = 1 ;
unsigned int V_36 ;
if ( V_61 & V_62 ) {
struct V_63 * V_64 ;
F_34 () ;
V_64 = F_35 ( V_14 -> V_65 ) ;
if ( V_64 )
V_47 = F_36 ( V_64 ) ;
F_37 () ;
}
for ( V_36 = 0 ; V_36 < V_66 ; V_36 ++ ) {
unsigned long V_48 = V_14 -> V_67 [ V_36 ] ;
if ( V_48 == V_68 || ! V_7 )
break;
if ( V_7 )
V_7 = F_11 ( V_4 , L_13 ) ;
if ( ! V_48 ) {
if ( V_7 )
V_7 = F_11 ( V_4 , L_14 ) ;
if ( V_7 )
V_7 = F_11 ( V_4 , L_2 ) ;
continue;
}
if ( ! V_7 )
break;
if ( V_7 )
V_7 = F_29 ( V_4 , V_47 , V_48 , V_49 ) ;
V_7 = F_11 ( V_4 , L_2 ) ;
}
if ( V_47 )
F_38 ( V_47 ) ;
return V_7 ;
}
int
F_39 ( struct V_3 * V_4 , unsigned long V_48 , unsigned long V_49 )
{
int V_7 ;
if ( ! V_48 )
return F_8 ( V_4 , L_15 ) ;
if ( V_49 & V_69 )
V_7 = F_27 ( V_4 , L_1 , V_48 ) ;
else
V_7 = F_24 ( V_4 , L_1 , V_48 ) ;
if ( ! V_7 )
return 0 ;
if ( V_49 & V_58 )
V_7 = F_8 ( V_4 , L_11 V_59 L_12 , V_48 ) ;
return V_7 ;
}
int F_40 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
char V_70 ;
char V_71 ;
char V_72 ;
int V_73 ;
int V_74 ;
int V_7 ;
V_73 = V_14 -> V_32 & V_75 ;
V_74 = V_14 -> V_32 & V_76 ;
V_72 =
( V_14 -> V_32 & V_77 ) ? 'd' :
( V_14 -> V_32 & V_78 ) ? 'X' :
'.' ;
V_71 =
( V_14 -> V_32 & V_79 ) ? 'N' : '.' ;
V_70 =
( V_73 && V_74 ) ? 'H' :
V_73 ? 'h' :
V_74 ? 's' :
'.' ;
if ( ! F_8 ( V_4 , L_16 ,
V_72 , V_71 , V_70 ) )
return 0 ;
if ( V_14 -> V_80 )
V_7 = F_8 ( V_4 , L_17 , V_14 -> V_80 ) ;
else
V_7 = F_12 ( V_4 , '.' ) ;
return V_7 ;
}
static int
F_41 ( struct V_3 * V_4 , struct V_13 * V_14 , int V_81 )
{
char V_82 [ V_83 ] ;
F_42 ( V_14 -> V_84 , V_82 ) ;
if ( ! F_8 ( V_4 , L_18 ,
V_82 , V_14 -> V_84 , V_81 ) )
return 0 ;
return F_40 ( V_4 , V_14 ) ;
}
static int
F_43 ( struct V_3 * V_4 , T_4 V_85 ,
unsigned long V_86 )
{
return F_8 ( V_4 , L_19 , V_85 ,
V_86 > V_87 ? '!' :
V_86 > 1 ? '+' : ' ' ) ;
}
int F_44 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned long long V_88 = F_45 ( V_11 -> V_89 ) ;
unsigned long V_90 = F_46 ( V_88 , V_91 ) ;
unsigned long V_92 = ( unsigned long ) V_88 ;
char V_82 [ V_83 ] ;
F_42 ( V_14 -> V_84 , V_82 ) ;
return F_8 ( V_4 , L_20 ,
V_82 , V_14 -> V_84 , V_11 -> V_81 , V_92 , V_90 ) ;
}
int F_47 ( struct V_10 * V_11 )
{
T_4 V_93 ;
int V_7 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ,
* V_94 = F_48 ( V_11 , NULL ,
& V_93 ) ;
unsigned long V_95 = ( V_61 & V_96 ) ;
unsigned long V_85 = F_45 ( V_11 -> V_89 - V_11 -> V_97 -> V_98 ) ;
unsigned long V_86 ;
if ( ! V_94 )
V_93 = V_11 -> V_89 ;
V_86 = F_45 ( V_93 - V_11 -> V_89 ) ;
if ( V_95 ) {
char V_82 [ V_83 ] ;
F_42 ( V_14 -> V_84 , V_82 ) ;
V_7 = F_8 ( V_4 , L_21
L_22 , V_82 ,
V_14 -> V_84 , V_11 -> V_81 , V_14 -> V_32 ,
V_14 -> V_80 , V_11 -> V_99 ,
F_45 ( V_11 -> V_89 ) ,
V_85 / V_100 ,
V_85 % V_100 ,
V_86 / V_100 ,
V_86 % V_100 ) ;
} else {
V_7 = F_41 ( V_4 , V_14 , V_11 -> V_81 ) ;
if ( V_7 )
V_7 = F_43 ( V_4 , V_85 , V_86 ) ;
}
return V_7 ;
}
static int F_49 ( unsigned long V_101 )
{
int V_102 = V_101 ? F_50 ( V_101 ) + 1 : 0 ;
return V_102 < sizeof( V_103 ) - 1 ? V_103 [ V_102 ] : '?' ;
}
struct V_104 * F_51 ( int type )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
unsigned V_108 ;
V_108 = type & ( V_109 - 1 ) ;
F_52 (event, n, &event_hash[key], node) {
if ( V_105 -> type == type )
return V_105 ;
}
return NULL ;
}
static int F_53 ( struct V_110 * * V_111 )
{
struct V_104 * V_112 ;
int V_113 = V_114 ;
if ( F_54 ( & V_115 ) ) {
* V_111 = & V_115 ;
return V_113 + 1 ;
}
F_55 (e, &ftrace_event_list, list) {
if ( V_112 -> type != V_113 + 1 )
break;
V_113 ++ ;
}
if ( ( V_113 + 1 ) > V_116 )
return 0 ;
* V_111 = & V_112 -> V_111 ;
return V_113 + 1 ;
}
void F_56 ( void )
{
F_30 ( & V_117 ) ;
}
void F_57 ( void )
{
F_32 ( & V_117 ) ;
}
int F_58 ( struct V_104 * V_105 )
{
unsigned V_108 ;
int V_7 = 0 ;
F_59 ( & V_117 ) ;
if ( F_60 ( ! V_105 ) )
goto V_118;
if ( F_60 ( ! V_105 -> V_119 ) )
goto V_118;
F_61 ( & V_105 -> V_111 ) ;
if ( ! V_105 -> type ) {
struct V_110 * V_111 = NULL ;
if ( V_120 > V_116 ) {
V_105 -> type = F_53 ( & V_111 ) ;
if ( ! V_105 -> type )
goto V_118;
} else {
V_105 -> type = V_120 ++ ;
V_111 = & V_115 ;
}
if ( F_60 ( F_51 ( V_105 -> type ) ) )
goto V_118;
F_62 ( & V_105 -> V_111 , V_111 ) ;
} else if ( V_105 -> type > V_114 ) {
F_63 ( V_121 L_23 ) ;
F_60 ( 1 ) ;
goto V_118;
} else {
if ( F_51 ( V_105 -> type ) )
goto V_118;
}
if ( V_105 -> V_119 -> V_122 == NULL )
V_105 -> V_119 -> V_122 = V_123 ;
if ( V_105 -> V_119 -> V_124 == NULL )
V_105 -> V_119 -> V_124 = V_123 ;
if ( V_105 -> V_119 -> V_125 == NULL )
V_105 -> V_119 -> V_125 = V_123 ;
if ( V_105 -> V_119 -> V_25 == NULL )
V_105 -> V_119 -> V_25 = V_123 ;
V_108 = V_105 -> type & ( V_109 - 1 ) ;
F_64 ( & V_105 -> V_126 , & V_127 [ V_108 ] ) ;
V_7 = V_105 -> type ;
V_118:
F_65 ( & V_117 ) ;
return V_7 ;
}
int F_66 ( struct V_104 * V_105 )
{
F_67 ( & V_105 -> V_126 ) ;
F_68 ( & V_105 -> V_111 ) ;
return 0 ;
}
int F_69 ( struct V_104 * V_105 )
{
F_59 ( & V_117 ) ;
F_66 ( V_105 ) ;
F_65 ( & V_117 ) ;
return 0 ;
}
enum V_9 V_123 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
if ( ! F_8 ( & V_11 -> V_12 , L_24 , V_11 -> V_15 -> type ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_70 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_128 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_39 ( V_4 , V_17 -> V_48 , V_32 ) )
goto V_129;
if ( ( V_32 & V_130 ) && V_17 -> V_131 ) {
if ( ! F_8 ( V_4 , L_25 ) )
goto V_129;
if ( ! F_39 ( V_4 ,
V_17 -> V_131 ,
V_32 ) )
goto V_129;
}
if ( ! F_8 ( V_4 , L_2 ) )
goto V_129;
return V_21 ;
V_129:
return V_20 ;
}
static enum V_9 F_71 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_128 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_8 ( & V_11 -> V_12 , L_26 ,
V_17 -> V_48 ,
V_17 -> V_131 ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_72 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_128 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_73 ( V_4 , V_17 -> V_48 ) ;
F_73 ( V_4 , V_17 -> V_131 ) ;
return V_21 ;
}
static enum V_9 F_74 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_128 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_75 ( V_4 , V_17 -> V_48 ) ;
F_75 ( V_4 , V_17 -> V_131 ) ;
return V_21 ;
}
static enum V_9 F_76 ( struct V_10 * V_11 ,
char * V_31 )
{
struct V_132 * V_17 ;
char V_82 [ V_83 ] ;
int V_133 , V_134 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_134 = F_49 ( V_17 -> V_135 ) ;
V_133 = F_49 ( V_17 -> V_136 ) ;
F_42 ( V_17 -> V_137 , V_82 ) ;
if ( ! F_8 ( & V_11 -> V_12 ,
L_27 ,
V_17 -> V_138 ,
V_17 -> V_139 ,
V_133 , V_31 ,
V_17 -> V_140 ,
V_17 -> V_137 ,
V_17 -> V_141 ,
V_134 , V_82 ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_77 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
return F_76 ( V_11 , L_28 ) ;
}
static enum V_9 F_78 ( struct V_10 * V_11 ,
int V_32 , struct V_104 * V_105 )
{
return F_76 ( V_11 , L_29 ) ;
}
static int F_79 ( struct V_10 * V_11 , char V_133 )
{
struct V_132 * V_17 ;
int V_134 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_133 )
V_133 = F_49 ( V_17 -> V_136 ) ;
V_134 = F_49 ( V_17 -> V_135 ) ;
if ( ! F_8 ( & V_11 -> V_12 , L_30 ,
V_17 -> V_138 ,
V_17 -> V_139 ,
V_133 ,
V_17 -> V_140 ,
V_17 -> V_137 ,
V_17 -> V_141 ,
V_134 ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_80 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
return F_79 ( V_11 , 0 ) ;
}
static enum V_9 F_81 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
return F_79 ( V_11 , '+' ) ;
}
static int F_82 ( struct V_10 * V_11 , char V_133 )
{
struct V_132 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
int V_134 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_133 )
V_133 = F_49 ( V_17 -> V_136 ) ;
V_134 = F_49 ( V_17 -> V_135 ) ;
F_73 ( V_4 , V_17 -> V_138 ) ;
F_73 ( V_4 , V_17 -> V_139 ) ;
F_73 ( V_4 , V_133 ) ;
F_73 ( V_4 , V_17 -> V_140 ) ;
F_73 ( V_4 , V_17 -> V_137 ) ;
F_73 ( V_4 , V_17 -> V_141 ) ;
F_73 ( V_4 , V_134 ) ;
return V_21 ;
}
static enum V_9 F_83 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
return F_82 ( V_11 , 0 ) ;
}
static enum V_9 F_84 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
return F_82 ( V_11 , '+' ) ;
}
static enum V_9 F_85 ( struct V_10 * V_11 ,
int V_32 , struct V_104 * V_105 )
{
struct V_132 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_75 ( V_4 , V_17 -> V_138 ) ;
F_75 ( V_4 , V_17 -> V_139 ) ;
F_75 ( V_4 , V_17 -> V_136 ) ;
F_75 ( V_4 , V_17 -> V_137 ) ;
F_75 ( V_4 , V_17 -> V_141 ) ;
F_75 ( V_4 , V_17 -> V_135 ) ;
return V_21 ;
}
static enum V_9 F_86 ( struct V_10 * V_11 ,
int V_32 , struct V_104 * V_105 )
{
struct V_142 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
int V_36 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_11 ( V_4 , L_31 ) )
goto V_129;
for ( V_36 = 0 ; V_36 < V_66 ; V_36 ++ ) {
if ( ! V_17 -> V_67 [ V_36 ] || ( V_17 -> V_67 [ V_36 ] == V_68 ) )
break;
if ( ! F_11 ( V_4 , L_13 ) )
goto V_129;
if ( ! F_39 ( V_4 , V_17 -> V_67 [ V_36 ] , V_32 ) )
goto V_129;
if ( ! F_11 ( V_4 , L_2 ) )
goto V_129;
}
return V_21 ;
V_129:
return V_20 ;
}
static enum V_9 F_87 ( struct V_10 * V_11 ,
int V_32 , struct V_104 * V_105 )
{
struct V_60 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_11 ( V_4 , L_32 ) )
goto V_129;
if ( ! F_33 ( V_17 , V_4 , V_32 ) )
goto V_129;
return V_21 ;
V_129:
return V_20 ;
}
static enum V_9
F_88 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_16 * V_17 ;
F_5 ( V_17 , V_14 ) ;
if ( ! F_39 ( V_4 , V_17 -> V_48 , V_32 ) )
goto V_129;
if ( ! F_11 ( V_4 , L_33 ) )
goto V_129;
if ( ! F_6 ( V_4 , V_17 -> V_18 , V_17 -> V_19 ) )
goto V_129;
return V_21 ;
V_129:
return V_20 ;
}
static enum V_9
F_89 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_8 ( V_4 , L_34 , V_17 -> V_48 ) )
goto V_129;
if ( ! F_6 ( V_4 , V_17 -> V_18 , V_17 -> V_19 ) )
goto V_129;
return V_21 ;
V_129:
return V_20 ;
}
static enum V_9 F_90 ( struct V_10 * V_11 ,
int V_32 , struct V_104 * V_105 )
{
struct V_22 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_39 ( V_4 , V_17 -> V_48 , V_32 ) )
goto V_129;
if ( ! F_8 ( V_4 , L_35 , V_17 -> V_19 ) )
goto V_129;
return V_21 ;
V_129:
return V_20 ;
}
static enum V_9 F_91 ( struct V_10 * V_11 , int V_32 ,
struct V_104 * V_105 )
{
struct V_22 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_8 ( & V_11 -> V_12 , L_36 , V_17 -> V_48 , V_17 -> V_19 ) )
goto V_129;
return V_21 ;
V_129:
return V_20 ;
}
T_5 static int F_92 ( void )
{
struct V_104 * V_105 ;
int V_36 , V_7 ;
for ( V_36 = 0 ; V_143 [ V_36 ] ; V_36 ++ ) {
V_105 = V_143 [ V_36 ] ;
V_7 = F_58 ( V_105 ) ;
if ( ! V_7 ) {
F_63 ( V_121 L_37 ,
V_105 -> type ) ;
F_93 ( 1 ) ;
}
}
return 0 ;
}
