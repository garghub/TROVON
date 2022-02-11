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
int F_15 ( struct V_3 * V_4 , const struct V_29 * V_29 )
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
int V_36 , V_37 = 1 ;
for ( V_36 = 0 ; V_34 [ V_36 ] . V_38 && V_32 ; V_36 ++ ) {
V_35 = V_34 [ V_36 ] . V_35 ;
if ( ( V_32 & V_35 ) != V_35 )
continue;
V_26 = V_34 [ V_36 ] . V_38 ;
V_32 &= ~ V_35 ;
if ( ! V_37 && V_31 )
F_11 ( V_30 , V_31 ) ;
else
V_37 = 0 ;
F_11 ( V_30 , V_26 ) ;
}
if ( V_32 ) {
if ( ! V_37 && V_31 )
F_11 ( V_30 , V_31 ) ;
F_8 ( V_30 , L_3 , V_32 ) ;
}
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
const char *
F_20 ( struct V_3 * V_30 , unsigned long V_39 ,
const struct V_33 * V_40 )
{
int V_36 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
for ( V_36 = 0 ; V_40 [ V_36 ] . V_38 ; V_36 ++ ) {
if ( V_39 != V_40 [ V_36 ] . V_35 )
continue;
F_11 ( V_30 , V_40 [ V_36 ] . V_38 ) ;
break;
}
if ( V_7 == ( const char * ) ( V_30 -> V_8 + V_30 -> V_5 ) )
F_8 ( V_30 , L_3 , V_39 ) ;
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
const char *
F_21 ( struct V_3 * V_30 , unsigned long long V_39 ,
const struct V_41 * V_40 )
{
int V_36 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
for ( V_36 = 0 ; V_40 [ V_36 ] . V_38 ; V_36 ++ ) {
if ( V_39 != V_40 [ V_36 ] . V_35 )
continue;
F_11 ( V_30 , V_40 [ V_36 ] . V_38 ) ;
break;
}
if ( V_7 == ( const char * ) ( V_30 -> V_8 + V_30 -> V_5 ) )
F_8 ( V_30 , L_4 , V_39 ) ;
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
const char *
F_22 ( struct V_3 * V_30 , const unsigned char * V_19 , int V_42 )
{
int V_36 ;
const char * V_7 = V_30 -> V_8 + V_30 -> V_5 ;
for ( V_36 = 0 ; V_36 < V_42 ; V_36 ++ )
F_8 ( V_30 , L_5 , V_36 == 0 ? L_6 : L_7 , V_19 [ V_36 ] ) ;
F_12 ( V_30 , 0 ) ;
return V_7 ;
}
static inline const char * F_23 ( const char * V_38 )
{
static const char V_43 [] = L_8 ;
int V_44 = sizeof( V_43 ) ;
if ( strncmp ( V_43 , V_38 , V_44 ) == 0 )
return L_9 ;
return V_38 ;
}
static inline const char * F_23 ( const char * V_38 )
{
return V_38 ;
}
static int
F_24 ( struct V_3 * V_4 , const char * V_18 , unsigned long V_45 )
{
#ifdef F_25
char V_26 [ V_46 ] ;
const char * V_38 ;
F_26 ( V_45 , NULL , NULL , NULL , V_26 ) ;
V_38 = F_23 ( V_26 ) ;
return F_8 ( V_4 , V_18 , V_38 ) ;
#endif
return 1 ;
}
static int
F_27 ( struct V_3 * V_4 , const char * V_18 ,
unsigned long V_45 )
{
#ifdef F_25
char V_26 [ V_46 ] ;
const char * V_38 ;
F_28 ( V_26 , V_45 ) ;
V_38 = F_23 ( V_26 ) ;
return F_8 ( V_4 , V_18 , V_38 ) ;
#endif
return 1 ;
}
int F_29 ( struct V_3 * V_4 , struct V_47 * V_48 ,
unsigned long V_49 , unsigned long V_50 )
{
struct V_51 * V_51 = NULL ;
unsigned long V_52 = 0 ;
int V_7 = 1 ;
if ( V_4 -> V_24 )
return 0 ;
if ( V_48 ) {
const struct V_53 * V_54 ;
F_30 ( & V_48 -> V_55 ) ;
V_54 = F_31 ( V_48 , V_49 ) ;
if ( V_54 ) {
V_51 = V_54 -> V_56 ;
V_52 = V_54 -> V_57 ;
}
if ( V_51 ) {
V_7 = F_15 ( V_4 , & V_51 -> V_58 ) ;
if ( V_7 )
V_7 = F_8 ( V_4 , L_10 ,
V_49 - V_52 ) ;
}
F_32 ( & V_48 -> V_55 ) ;
}
if ( V_7 && ( ( V_50 & V_59 ) || ! V_51 ) )
V_7 = F_8 ( V_4 , L_11 V_60 L_12 , V_49 ) ;
return V_7 ;
}
int
F_33 ( const struct V_61 * V_14 , struct V_3 * V_4 ,
unsigned long V_50 )
{
struct V_47 * V_48 = NULL ;
int V_7 = 1 ;
unsigned int V_36 ;
if ( V_62 & V_63 ) {
struct V_64 * V_65 ;
F_34 () ;
V_65 = F_35 ( V_14 -> V_66 ) ;
if ( V_65 )
V_48 = F_36 ( V_65 ) ;
F_37 () ;
}
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
unsigned long V_49 = V_14 -> V_68 [ V_36 ] ;
if ( V_49 == V_69 || ! V_7 )
break;
if ( V_7 )
V_7 = F_11 ( V_4 , L_13 ) ;
if ( ! V_49 ) {
if ( V_7 )
V_7 = F_11 ( V_4 , L_14 ) ;
if ( V_7 )
V_7 = F_11 ( V_4 , L_2 ) ;
continue;
}
if ( ! V_7 )
break;
if ( V_7 )
V_7 = F_29 ( V_4 , V_48 , V_49 , V_50 ) ;
V_7 = F_11 ( V_4 , L_2 ) ;
}
if ( V_48 )
F_38 ( V_48 ) ;
return V_7 ;
}
int
F_39 ( struct V_3 * V_4 , unsigned long V_49 , unsigned long V_50 )
{
int V_7 ;
if ( ! V_49 )
return F_8 ( V_4 , L_15 ) ;
if ( V_50 & V_70 )
V_7 = F_27 ( V_4 , L_1 , V_49 ) ;
else
V_7 = F_24 ( V_4 , L_1 , V_49 ) ;
if ( ! V_7 )
return 0 ;
if ( V_50 & V_59 )
V_7 = F_8 ( V_4 , L_11 V_60 L_12 , V_49 ) ;
return V_7 ;
}
int F_40 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
char V_71 ;
char V_72 ;
char V_73 ;
int V_74 ;
int V_75 ;
int V_7 ;
V_74 = V_14 -> V_32 & V_76 ;
V_75 = V_14 -> V_32 & V_77 ;
V_73 =
( V_14 -> V_32 & V_78 ) ? 'd' :
( V_14 -> V_32 & V_79 ) ? 'X' :
'.' ;
V_72 =
( V_14 -> V_32 & V_80 ) ? 'N' : '.' ;
V_71 =
( V_74 && V_75 ) ? 'H' :
V_74 ? 'h' :
V_75 ? 's' :
'.' ;
if ( ! F_8 ( V_4 , L_16 ,
V_73 , V_72 , V_71 ) )
return 0 ;
if ( V_14 -> V_81 )
V_7 = F_8 ( V_4 , L_17 , V_14 -> V_81 ) ;
else
V_7 = F_12 ( V_4 , '.' ) ;
return V_7 ;
}
static int
F_41 ( struct V_3 * V_4 , struct V_13 * V_14 , int V_82 )
{
char V_83 [ V_84 ] ;
F_42 ( V_14 -> V_85 , V_83 ) ;
if ( ! F_8 ( V_4 , L_18 ,
V_83 , V_14 -> V_85 , V_82 ) )
return 0 ;
return F_40 ( V_4 , V_14 ) ;
}
static int
F_43 ( struct V_10 * V_11 , T_4 V_86 )
{
unsigned long V_87 = V_62 & V_88 ;
unsigned long V_89 = V_11 -> V_90 & V_91 ;
unsigned long long V_92 = V_11 -> V_93 - V_11 -> V_94 -> V_95 ;
unsigned long long V_96 = V_86 - V_11 -> V_93 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
if ( V_89 ) {
V_92 = F_44 ( V_92 ) ;
V_96 = F_44 ( V_96 ) ;
}
if ( V_87 && V_89 ) {
unsigned long V_97 = F_45 ( V_92 , V_98 ) ;
unsigned long V_99 = ( unsigned long ) V_92 ;
unsigned long V_100 = F_45 ( V_96 , V_98 ) ;
unsigned long V_101 = ( unsigned long ) V_96 ;
return F_8 (
V_4 , L_19 ,
F_44 ( V_11 -> V_93 ) ,
V_99 , V_97 ,
V_101 , V_100 ) ;
} else if ( V_87 && ! V_89 ) {
return F_8 (
V_4 , L_20 ,
V_11 -> V_93 , V_92 , V_96 ) ;
} else if ( ! V_87 && V_89 ) {
return F_8 (
V_4 , L_21 ,
V_92 ,
V_96 > V_102 ? '!' :
V_96 > 1 ? '+' : ' ' ) ;
} else {
return F_8 ( V_4 , L_22 , V_92 ) ;
}
}
int F_46 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned long long V_103 ;
unsigned long V_104 , V_105 ;
char V_83 [ V_84 ] ;
int V_7 ;
F_42 ( V_14 -> V_85 , V_83 ) ;
V_7 = F_8 ( V_4 , L_23 ,
V_83 , V_14 -> V_85 , V_11 -> V_82 ) ;
if ( ! V_7 )
return 0 ;
if ( V_62 & V_106 ) {
V_7 = F_40 ( V_4 , V_14 ) ;
if ( ! V_7 )
return 0 ;
}
if ( V_11 -> V_90 & V_91 ) {
V_103 = F_44 ( V_11 -> V_93 ) ;
V_105 = F_45 ( V_103 , V_107 ) ;
V_104 = ( unsigned long ) V_103 ;
return F_8 ( V_4 , L_24 , V_104 , V_105 ) ;
} else
return F_8 ( V_4 , L_25 , V_11 -> V_93 ) ;
}
int F_47 ( struct V_10 * V_11 )
{
T_4 V_86 ;
int V_7 ;
int V_108 = V_11 -> V_108 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ,
* V_109 = F_48 ( V_11 , NULL ,
& V_86 ) ;
unsigned long V_87 = ( V_62 & V_88 ) ;
V_11 -> V_108 = V_108 ;
if ( ! V_109 )
V_86 = V_11 -> V_93 ;
if ( V_87 ) {
char V_83 [ V_84 ] ;
F_42 ( V_14 -> V_85 , V_83 ) ;
V_7 = F_8 (
V_4 , L_26 ,
V_83 , V_14 -> V_85 , V_11 -> V_82 , V_14 -> V_32 ,
V_14 -> V_81 , V_11 -> V_110 ) ;
} else {
V_7 = F_41 ( V_4 , V_14 , V_11 -> V_82 ) ;
}
if ( V_7 )
V_7 = F_43 ( V_11 , V_86 ) ;
return V_7 ;
}
static int F_49 ( unsigned long V_111 )
{
int V_112 = V_111 ? F_50 ( V_111 ) + 1 : 0 ;
return V_112 < sizeof( V_113 ) - 1 ? V_113 [ V_112 ] : '?' ;
}
struct V_114 * F_51 ( int type )
{
struct V_114 * V_115 ;
unsigned V_116 ;
V_116 = type & ( V_117 - 1 ) ;
F_52 (event, &event_hash[key], node) {
if ( V_115 -> type == type )
return V_115 ;
}
return NULL ;
}
static int F_53 ( struct V_118 * * V_119 )
{
struct V_114 * V_120 ;
int V_121 = V_122 ;
if ( F_54 ( & V_123 ) ) {
* V_119 = & V_123 ;
return V_121 + 1 ;
}
F_55 (e, &ftrace_event_list, list) {
if ( V_120 -> type != V_121 + 1 )
break;
V_121 ++ ;
}
if ( ( V_121 + 1 ) > V_124 )
return 0 ;
* V_119 = & V_120 -> V_119 ;
return V_121 + 1 ;
}
void F_56 ( void )
{
F_30 ( & V_125 ) ;
}
void F_57 ( void )
{
F_32 ( & V_125 ) ;
}
int F_58 ( struct V_114 * V_115 )
{
unsigned V_116 ;
int V_7 = 0 ;
F_59 ( & V_125 ) ;
if ( F_60 ( ! V_115 ) )
goto V_126;
if ( F_60 ( ! V_115 -> V_127 ) )
goto V_126;
F_61 ( & V_115 -> V_119 ) ;
if ( ! V_115 -> type ) {
struct V_118 * V_119 = NULL ;
if ( V_128 > V_124 ) {
V_115 -> type = F_53 ( & V_119 ) ;
if ( ! V_115 -> type )
goto V_126;
} else {
V_115 -> type = V_128 ++ ;
V_119 = & V_123 ;
}
if ( F_60 ( F_51 ( V_115 -> type ) ) )
goto V_126;
F_62 ( & V_115 -> V_119 , V_119 ) ;
} else if ( V_115 -> type > V_122 ) {
F_63 ( V_129 L_27 ) ;
F_60 ( 1 ) ;
goto V_126;
} else {
if ( F_51 ( V_115 -> type ) )
goto V_126;
}
if ( V_115 -> V_127 -> V_130 == NULL )
V_115 -> V_127 -> V_130 = V_131 ;
if ( V_115 -> V_127 -> V_132 == NULL )
V_115 -> V_127 -> V_132 = V_131 ;
if ( V_115 -> V_127 -> V_133 == NULL )
V_115 -> V_127 -> V_133 = V_131 ;
if ( V_115 -> V_127 -> V_25 == NULL )
V_115 -> V_127 -> V_25 = V_131 ;
V_116 = V_115 -> type & ( V_117 - 1 ) ;
F_64 ( & V_115 -> V_134 , & V_135 [ V_116 ] ) ;
V_7 = V_115 -> type ;
V_126:
F_65 ( & V_125 ) ;
return V_7 ;
}
int F_66 ( struct V_114 * V_115 )
{
F_67 ( & V_115 -> V_134 ) ;
F_68 ( & V_115 -> V_119 ) ;
return 0 ;
}
int F_69 ( struct V_114 * V_115 )
{
F_59 ( & V_125 ) ;
F_66 ( V_115 ) ;
F_65 ( & V_125 ) ;
return 0 ;
}
enum V_9 V_131 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
if ( ! F_8 ( & V_11 -> V_12 , L_28 , V_11 -> V_15 -> type ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_70 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_136 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_39 ( V_4 , V_17 -> V_49 , V_32 ) )
goto V_137;
if ( ( V_32 & V_138 ) && V_17 -> V_139 ) {
if ( ! F_8 ( V_4 , L_29 ) )
goto V_137;
if ( ! F_39 ( V_4 ,
V_17 -> V_139 ,
V_32 ) )
goto V_137;
}
if ( ! F_8 ( V_4 , L_2 ) )
goto V_137;
return V_21 ;
V_137:
return V_20 ;
}
static enum V_9 F_71 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_136 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_8 ( & V_11 -> V_12 , L_30 ,
V_17 -> V_49 ,
V_17 -> V_139 ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_72 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_136 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_73 ( V_4 , V_17 -> V_49 ) ;
F_73 ( V_4 , V_17 -> V_139 ) ;
return V_21 ;
}
static enum V_9 F_74 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_136 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_75 ( V_4 , V_17 -> V_49 ) ;
F_75 ( V_4 , V_17 -> V_139 ) ;
return V_21 ;
}
static enum V_9 F_76 ( struct V_10 * V_11 ,
char * V_31 )
{
struct V_140 * V_17 ;
char V_83 [ V_84 ] ;
int V_141 , V_142 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_142 = F_49 ( V_17 -> V_143 ) ;
V_141 = F_49 ( V_17 -> V_144 ) ;
F_42 ( V_17 -> V_145 , V_83 ) ;
if ( ! F_8 ( & V_11 -> V_12 ,
L_31 ,
V_17 -> V_146 ,
V_17 -> V_147 ,
V_141 , V_31 ,
V_17 -> V_148 ,
V_17 -> V_145 ,
V_17 -> V_149 ,
V_142 , V_83 ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_77 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
return F_76 ( V_11 , L_32 ) ;
}
static enum V_9 F_78 ( struct V_10 * V_11 ,
int V_32 , struct V_114 * V_115 )
{
return F_76 ( V_11 , L_33 ) ;
}
static int F_79 ( struct V_10 * V_11 , char V_141 )
{
struct V_140 * V_17 ;
int V_142 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_141 )
V_141 = F_49 ( V_17 -> V_144 ) ;
V_142 = F_49 ( V_17 -> V_143 ) ;
if ( ! F_8 ( & V_11 -> V_12 , L_34 ,
V_17 -> V_146 ,
V_17 -> V_147 ,
V_141 ,
V_17 -> V_148 ,
V_17 -> V_145 ,
V_17 -> V_149 ,
V_142 ) )
return V_20 ;
return V_21 ;
}
static enum V_9 F_80 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
return F_79 ( V_11 , 0 ) ;
}
static enum V_9 F_81 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
return F_79 ( V_11 , '+' ) ;
}
static int F_82 ( struct V_10 * V_11 , char V_141 )
{
struct V_140 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
int V_142 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_141 )
V_141 = F_49 ( V_17 -> V_144 ) ;
V_142 = F_49 ( V_17 -> V_143 ) ;
F_73 ( V_4 , V_17 -> V_146 ) ;
F_73 ( V_4 , V_17 -> V_147 ) ;
F_73 ( V_4 , V_141 ) ;
F_73 ( V_4 , V_17 -> V_148 ) ;
F_73 ( V_4 , V_17 -> V_145 ) ;
F_73 ( V_4 , V_17 -> V_149 ) ;
F_73 ( V_4 , V_142 ) ;
return V_21 ;
}
static enum V_9 F_83 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
return F_82 ( V_11 , 0 ) ;
}
static enum V_9 F_84 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
return F_82 ( V_11 , '+' ) ;
}
static enum V_9 F_85 ( struct V_10 * V_11 ,
int V_32 , struct V_114 * V_115 )
{
struct V_140 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_75 ( V_4 , V_17 -> V_146 ) ;
F_75 ( V_4 , V_17 -> V_147 ) ;
F_75 ( V_4 , V_17 -> V_144 ) ;
F_75 ( V_4 , V_17 -> V_145 ) ;
F_75 ( V_4 , V_17 -> V_149 ) ;
F_75 ( V_4 , V_17 -> V_143 ) ;
return V_21 ;
}
static enum V_9 F_86 ( struct V_10 * V_11 ,
int V_32 , struct V_114 * V_115 )
{
struct V_150 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
unsigned long * V_30 ;
unsigned long * V_151 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_151 = ( unsigned long * ) ( ( long ) V_11 -> V_15 + V_11 -> V_108 ) ;
if ( ! F_11 ( V_4 , L_35 ) )
goto V_137;
for ( V_30 = V_17 -> V_68 ; V_30 && * V_30 != V_69 && V_30 < V_151 ; V_30 ++ ) {
if ( ! F_11 ( V_4 , L_13 ) )
goto V_137;
if ( ! F_39 ( V_4 , * V_30 , V_32 ) )
goto V_137;
if ( ! F_11 ( V_4 , L_2 ) )
goto V_137;
}
return V_21 ;
V_137:
return V_20 ;
}
static enum V_9 F_87 ( struct V_10 * V_11 ,
int V_32 , struct V_114 * V_115 )
{
struct V_61 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_11 ( V_4 , L_36 ) )
goto V_137;
if ( ! F_33 ( V_17 , V_4 , V_32 ) )
goto V_137;
return V_21 ;
V_137:
return V_20 ;
}
static enum V_9
F_88 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_16 * V_17 ;
F_5 ( V_17 , V_14 ) ;
if ( ! F_39 ( V_4 , V_17 -> V_49 , V_32 ) )
goto V_137;
if ( ! F_11 ( V_4 , L_37 ) )
goto V_137;
if ( ! F_6 ( V_4 , V_17 -> V_18 , V_17 -> V_19 ) )
goto V_137;
return V_21 ;
V_137:
return V_20 ;
}
static enum V_9
F_89 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_8 ( V_4 , L_38 , V_17 -> V_49 ) )
goto V_137;
if ( ! F_6 ( V_4 , V_17 -> V_18 , V_17 -> V_19 ) )
goto V_137;
return V_21 ;
V_137:
return V_20 ;
}
static enum V_9 F_90 ( struct V_10 * V_11 ,
int V_32 , struct V_114 * V_115 )
{
struct V_22 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_39 ( V_4 , V_17 -> V_49 , V_32 ) )
goto V_137;
if ( ! F_8 ( V_4 , L_39 , V_17 -> V_19 ) )
goto V_137;
return V_21 ;
V_137:
return V_20 ;
}
static enum V_9 F_91 ( struct V_10 * V_11 , int V_32 ,
struct V_114 * V_115 )
{
struct V_22 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_8 ( & V_11 -> V_12 , L_40 , V_17 -> V_49 , V_17 -> V_19 ) )
goto V_137;
return V_21 ;
V_137:
return V_20 ;
}
T_5 static int F_92 ( void )
{
struct V_114 * V_115 ;
int V_36 , V_7 ;
for ( V_36 = 0 ; V_152 [ V_36 ] ; V_36 ++ ) {
V_115 = V_152 [ V_36 ] ;
V_7 = F_58 ( V_115 ) ;
if ( ! V_7 ) {
F_63 ( V_129 L_41 ,
V_115 -> type ) ;
F_93 ( 1 ) ;
}
}
return 0 ;
}
