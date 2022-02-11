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
V_7 = F_10 ( V_4 , L_1 , V_17 -> V_23 ) ;
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
F_11 ( struct V_3 * V_4 , const char * V_22 , T_1 args )
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
int F_8 ( struct V_3 * V_4 , const char * V_22 , const T_2 * V_27 )
{
int V_5 = ( V_6 - 1 ) - V_4 -> V_5 ;
int V_7 ;
if ( V_4 -> V_26 || ! V_5 )
return 0 ;
V_7 = F_12 ( V_4 -> V_8 + V_4 -> V_5 , V_5 , V_22 , V_27 ) ;
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
int F_13 ( struct V_3 * V_4 , unsigned char V_28 )
{
if ( V_4 -> V_26 )
return 0 ;
if ( V_4 -> V_5 >= ( V_6 - 1 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_4 -> V_8 [ V_4 -> V_5 ++ ] = V_28 ;
return 1 ;
}
int F_14 ( struct V_3 * V_4 , const void * V_29 , T_3 V_5 )
{
if ( V_4 -> V_26 )
return 0 ;
if ( V_5 > ( ( V_6 - 1 ) - V_4 -> V_5 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
memcpy ( V_4 -> V_8 + V_4 -> V_5 , V_29 , V_5 ) ;
V_4 -> V_5 += V_5 ;
return V_5 ;
}
void * F_15 ( struct V_3 * V_4 , T_3 V_5 )
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
int F_16 ( struct V_3 * V_4 , const struct V_30 * V_30 )
{
unsigned char * V_31 ;
if ( V_4 -> V_26 )
return 0 ;
if ( V_4 -> V_5 >= ( V_6 - 1 ) ) {
V_4 -> V_26 = 1 ;
return 0 ;
}
V_31 = F_17 ( V_30 , V_4 -> V_8 + V_4 -> V_5 , V_6 - V_4 -> V_5 ) ;
if ( ! F_18 ( V_31 ) ) {
V_31 = F_19 ( V_4 -> V_8 + V_4 -> V_5 , V_31 , L_2 ) ;
if ( V_31 ) {
V_4 -> V_5 = V_31 - V_4 -> V_8 ;
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
F_20 ( struct V_3 * V_31 , const char * V_32 ,
unsigned long V_33 ,
const struct V_34 * V_35 )
{
unsigned long V_36 ;
const char * V_18 ;
const char * V_7 = V_31 -> V_8 + V_31 -> V_5 ;
int V_37 , V_38 = 1 ;
for ( V_37 = 0 ; V_35 [ V_37 ] . V_39 && V_33 ; V_37 ++ ) {
V_36 = V_35 [ V_37 ] . V_36 ;
if ( ( V_33 & V_36 ) != V_36 )
continue;
V_18 = V_35 [ V_37 ] . V_39 ;
V_33 &= ~ V_36 ;
if ( ! V_38 && V_32 )
F_6 ( V_31 , V_32 ) ;
else
V_38 = 0 ;
F_6 ( V_31 , V_18 ) ;
}
if ( V_33 ) {
if ( ! V_38 && V_32 )
F_6 ( V_31 , V_32 ) ;
F_10 ( V_31 , L_3 , V_33 ) ;
}
F_13 ( V_31 , 0 ) ;
return V_7 ;
}
const char *
F_21 ( struct V_3 * V_31 , unsigned long V_40 ,
const struct V_34 * V_41 )
{
int V_37 ;
const char * V_7 = V_31 -> V_8 + V_31 -> V_5 ;
for ( V_37 = 0 ; V_41 [ V_37 ] . V_39 ; V_37 ++ ) {
if ( V_40 != V_41 [ V_37 ] . V_36 )
continue;
F_6 ( V_31 , V_41 [ V_37 ] . V_39 ) ;
break;
}
if ( V_7 == ( const char * ) ( V_31 -> V_8 + V_31 -> V_5 ) )
F_10 ( V_31 , L_3 , V_40 ) ;
F_13 ( V_31 , 0 ) ;
return V_7 ;
}
const char *
F_22 ( struct V_3 * V_31 , unsigned long long V_40 ,
const struct V_42 * V_41 )
{
int V_37 ;
const char * V_7 = V_31 -> V_8 + V_31 -> V_5 ;
for ( V_37 = 0 ; V_41 [ V_37 ] . V_39 ; V_37 ++ ) {
if ( V_40 != V_41 [ V_37 ] . V_36 )
continue;
F_6 ( V_31 , V_41 [ V_37 ] . V_39 ) ;
break;
}
if ( V_7 == ( const char * ) ( V_31 -> V_8 + V_31 -> V_5 ) )
F_10 ( V_31 , L_4 , V_40 ) ;
F_13 ( V_31 , 0 ) ;
return V_7 ;
}
const char *
F_23 ( struct V_3 * V_31 , const unsigned char * V_23 , int V_43 )
{
int V_37 ;
const char * V_7 = V_31 -> V_8 + V_31 -> V_5 ;
for ( V_37 = 0 ; V_37 < V_43 ; V_37 ++ )
F_10 ( V_31 , L_5 , V_37 == 0 ? L_6 : L_7 , V_23 [ V_37 ] ) ;
F_13 ( V_31 , 0 ) ;
return V_7 ;
}
int F_24 ( struct V_10 * V_11 ,
struct V_44 * V_44 )
{
struct V_45 * V_46 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_3 * V_31 = & V_11 -> V_47 ;
struct V_13 * V_14 ;
int V_7 ;
V_46 = F_25 ( V_44 , struct V_45 , V_46 ) ;
V_14 = V_11 -> V_15 ;
if ( V_14 -> type != V_46 -> V_46 . type ) {
F_26 ( 1 ) ;
return V_48 ;
}
F_3 ( V_31 ) ;
V_7 = F_10 ( V_4 , L_8 , V_46 -> V_39 ) ;
if ( ! V_7 )
return V_19 ;
return 0 ;
}
static inline const char * F_27 ( const char * V_39 )
{
static const char V_49 [] = L_9 ;
int V_50 = sizeof( V_49 ) ;
if ( strncmp ( V_49 , V_39 , V_50 ) == 0 )
return L_10 ;
return V_39 ;
}
static inline const char * F_27 ( const char * V_39 )
{
return V_39 ;
}
static int
F_28 ( struct V_3 * V_4 , const char * V_22 , unsigned long V_51 )
{
#ifdef F_29
char V_18 [ V_52 ] ;
const char * V_39 ;
F_30 ( V_51 , NULL , NULL , NULL , V_18 ) ;
V_39 = F_27 ( V_18 ) ;
return F_10 ( V_4 , V_22 , V_39 ) ;
#endif
return 1 ;
}
static int
F_31 ( struct V_3 * V_4 , const char * V_22 ,
unsigned long V_51 )
{
#ifdef F_29
char V_18 [ V_52 ] ;
const char * V_39 ;
F_32 ( V_18 , V_51 ) ;
V_39 = F_27 ( V_18 ) ;
return F_10 ( V_4 , V_22 , V_39 ) ;
#endif
return 1 ;
}
int F_33 ( struct V_3 * V_4 , struct V_53 * V_54 ,
unsigned long V_55 , unsigned long V_56 )
{
struct V_57 * V_57 = NULL ;
unsigned long V_58 = 0 ;
int V_7 = 1 ;
if ( V_4 -> V_26 )
return 0 ;
if ( V_54 ) {
const struct V_59 * V_60 ;
F_34 ( & V_54 -> V_61 ) ;
V_60 = F_35 ( V_54 , V_55 ) ;
if ( V_60 ) {
V_57 = V_60 -> V_62 ;
V_58 = V_60 -> V_63 ;
}
if ( V_57 ) {
V_7 = F_16 ( V_4 , & V_57 -> V_64 ) ;
if ( V_7 )
V_7 = F_10 ( V_4 , L_11 ,
V_55 - V_58 ) ;
}
F_36 ( & V_54 -> V_61 ) ;
}
if ( V_7 && ( ( V_56 & V_65 ) || ! V_57 ) )
V_7 = F_10 ( V_4 , L_12 V_66 L_13 , V_55 ) ;
return V_7 ;
}
int
F_37 ( const struct V_67 * V_14 , struct V_3 * V_4 ,
unsigned long V_56 )
{
struct V_53 * V_54 = NULL ;
int V_7 = 1 ;
unsigned int V_37 ;
if ( V_68 & V_69 ) {
struct V_70 * V_71 ;
F_38 () ;
V_71 = F_39 ( V_14 -> V_72 ) ;
if ( V_71 )
V_54 = F_40 ( V_71 ) ;
F_41 () ;
}
for ( V_37 = 0 ; V_37 < V_73 ; V_37 ++ ) {
unsigned long V_55 = V_14 -> V_74 [ V_37 ] ;
if ( V_55 == V_75 || ! V_7 )
break;
if ( V_7 )
V_7 = F_6 ( V_4 , L_14 ) ;
if ( ! V_55 ) {
if ( V_7 )
V_7 = F_6 ( V_4 , L_15 ) ;
if ( V_7 )
V_7 = F_6 ( V_4 , L_2 ) ;
continue;
}
if ( ! V_7 )
break;
if ( V_7 )
V_7 = F_33 ( V_4 , V_54 , V_55 , V_56 ) ;
V_7 = F_6 ( V_4 , L_2 ) ;
}
if ( V_54 )
F_42 ( V_54 ) ;
return V_7 ;
}
int
F_43 ( struct V_3 * V_4 , unsigned long V_55 , unsigned long V_56 )
{
int V_7 ;
if ( ! V_55 )
return F_10 ( V_4 , L_16 ) ;
if ( V_56 & V_76 )
V_7 = F_31 ( V_4 , L_1 , V_55 ) ;
else
V_7 = F_28 ( V_4 , L_1 , V_55 ) ;
if ( ! V_7 )
return 0 ;
if ( V_56 & V_65 )
V_7 = F_10 ( V_4 , L_12 V_66 L_13 , V_55 ) ;
return V_7 ;
}
int F_44 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
char V_77 ;
char V_78 ;
char V_79 ;
int V_80 ;
int V_81 ;
int V_7 ;
V_80 = V_14 -> V_33 & V_82 ;
V_81 = V_14 -> V_33 & V_83 ;
V_79 =
( V_14 -> V_33 & V_84 ) ? 'd' :
( V_14 -> V_33 & V_85 ) ? 'X' :
'.' ;
V_78 =
( V_14 -> V_33 & V_86 ) ? 'N' : '.' ;
V_77 =
( V_80 && V_81 ) ? 'H' :
V_80 ? 'h' :
V_81 ? 's' :
'.' ;
if ( ! F_10 ( V_4 , L_17 ,
V_79 , V_78 , V_77 ) )
return 0 ;
if ( V_14 -> V_87 )
V_7 = F_10 ( V_4 , L_18 , V_14 -> V_87 ) ;
else
V_7 = F_13 ( V_4 , '.' ) ;
return V_7 ;
}
static int
F_45 ( struct V_3 * V_4 , struct V_13 * V_14 , int V_88 )
{
char V_89 [ V_90 ] ;
F_46 ( V_14 -> V_91 , V_89 ) ;
if ( ! F_10 ( V_4 , L_19 ,
V_89 , V_14 -> V_91 , V_88 ) )
return 0 ;
return F_44 ( V_4 , V_14 ) ;
}
static int
F_47 ( struct V_10 * V_11 , T_4 V_92 )
{
unsigned long V_93 = V_68 & V_94 ;
unsigned long V_95 = V_11 -> V_96 & V_97 ;
unsigned long long V_98 = V_11 -> V_99 - V_11 -> V_100 -> V_101 ;
unsigned long long V_102 = V_92 - V_11 -> V_99 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
if ( V_95 ) {
V_98 = F_48 ( V_98 ) ;
V_102 = F_48 ( V_102 ) ;
}
if ( V_93 && V_95 ) {
unsigned long V_103 = F_49 ( V_98 , V_104 ) ;
unsigned long V_105 = ( unsigned long ) V_98 ;
unsigned long V_106 = F_49 ( V_102 , V_104 ) ;
unsigned long V_107 = ( unsigned long ) V_102 ;
return F_10 (
V_4 , L_20 ,
F_48 ( V_11 -> V_99 ) ,
V_105 , V_103 ,
V_107 , V_106 ) ;
} else if ( V_93 && ! V_95 ) {
return F_10 (
V_4 , L_21 ,
V_11 -> V_99 , V_98 , V_102 ) ;
} else if ( ! V_93 && V_95 ) {
return F_10 (
V_4 , L_22 ,
V_98 ,
V_102 > V_108 ? '!' :
V_102 > 1 ? '+' : ' ' ) ;
} else {
return F_10 ( V_4 , L_23 , V_98 ) ;
}
}
int F_50 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned long long V_109 ;
unsigned long V_110 , V_111 ;
char V_89 [ V_90 ] ;
int V_7 ;
F_46 ( V_14 -> V_91 , V_89 ) ;
V_7 = F_10 ( V_4 , L_24 ,
V_89 , V_14 -> V_91 , V_11 -> V_88 ) ;
if ( ! V_7 )
return 0 ;
if ( V_68 & V_112 ) {
V_7 = F_44 ( V_4 , V_14 ) ;
if ( ! V_7 )
return 0 ;
}
if ( V_11 -> V_96 & V_97 ) {
V_109 = F_48 ( V_11 -> V_99 ) ;
V_111 = F_49 ( V_109 , V_113 ) ;
V_110 = ( unsigned long ) V_109 ;
return F_10 ( V_4 , L_25 , V_110 , V_111 ) ;
} else
return F_10 ( V_4 , L_26 , V_11 -> V_99 ) ;
}
int F_51 ( struct V_10 * V_11 )
{
T_4 V_92 ;
int V_7 ;
int V_114 = V_11 -> V_114 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 ,
* V_115 = F_52 ( V_11 , NULL ,
& V_92 ) ;
unsigned long V_93 = ( V_68 & V_94 ) ;
V_11 -> V_114 = V_114 ;
if ( ! V_115 )
V_92 = V_11 -> V_99 ;
if ( V_93 ) {
char V_89 [ V_90 ] ;
F_46 ( V_14 -> V_91 , V_89 ) ;
V_7 = F_10 (
V_4 , L_27 ,
V_89 , V_14 -> V_91 , V_11 -> V_88 , V_14 -> V_33 ,
V_14 -> V_87 , V_11 -> V_116 ) ;
} else {
V_7 = F_45 ( V_4 , V_14 , V_11 -> V_88 ) ;
}
if ( V_7 )
V_7 = F_47 ( V_11 , V_92 ) ;
return V_7 ;
}
static int F_53 ( unsigned long V_117 )
{
int V_118 = V_117 ? F_54 ( V_117 ) + 1 : 0 ;
return V_118 < sizeof( V_119 ) - 1 ? V_119 [ V_118 ] : '?' ;
}
struct V_44 * F_55 ( int type )
{
struct V_44 * V_46 ;
unsigned V_120 ;
V_120 = type & ( V_121 - 1 ) ;
F_56 (event, &event_hash[key], node) {
if ( V_46 -> type == type )
return V_46 ;
}
return NULL ;
}
static int F_57 ( struct V_122 * * V_123 )
{
struct V_44 * V_124 ;
int V_125 = V_126 ;
if ( F_58 ( & V_127 ) ) {
* V_123 = & V_127 ;
return V_125 + 1 ;
}
F_59 (e, &ftrace_event_list, list) {
if ( V_124 -> type != V_125 + 1 )
break;
V_125 ++ ;
}
if ( ( V_125 + 1 ) > V_128 )
return 0 ;
* V_123 = & V_124 -> V_123 ;
return V_125 + 1 ;
}
void F_60 ( void )
{
F_34 ( & V_129 ) ;
}
void F_61 ( void )
{
F_36 ( & V_129 ) ;
}
int F_62 ( struct V_44 * V_46 )
{
unsigned V_120 ;
int V_7 = 0 ;
F_63 ( & V_129 ) ;
if ( F_64 ( ! V_46 ) )
goto V_130;
if ( F_64 ( ! V_46 -> V_131 ) )
goto V_130;
F_65 ( & V_46 -> V_123 ) ;
if ( ! V_46 -> type ) {
struct V_122 * V_123 = NULL ;
if ( V_132 > V_128 ) {
V_46 -> type = F_57 ( & V_123 ) ;
if ( ! V_46 -> type )
goto V_130;
} else {
V_46 -> type = V_132 ++ ;
V_123 = & V_127 ;
}
if ( F_64 ( F_55 ( V_46 -> type ) ) )
goto V_130;
F_66 ( & V_46 -> V_123 , V_123 ) ;
} else if ( V_46 -> type > V_126 ) {
F_67 ( V_133 L_28 ) ;
F_64 ( 1 ) ;
goto V_130;
} else {
if ( F_55 ( V_46 -> type ) )
goto V_130;
}
if ( V_46 -> V_131 -> V_134 == NULL )
V_46 -> V_131 -> V_134 = V_135 ;
if ( V_46 -> V_131 -> V_136 == NULL )
V_46 -> V_131 -> V_136 = V_135 ;
if ( V_46 -> V_131 -> V_137 == NULL )
V_46 -> V_131 -> V_137 = V_135 ;
if ( V_46 -> V_131 -> V_27 == NULL )
V_46 -> V_131 -> V_27 = V_135 ;
V_120 = V_46 -> type & ( V_121 - 1 ) ;
F_68 ( & V_46 -> V_138 , & V_139 [ V_120 ] ) ;
V_7 = V_46 -> type ;
V_130:
F_69 ( & V_129 ) ;
return V_7 ;
}
int F_70 ( struct V_44 * V_46 )
{
F_71 ( & V_46 -> V_138 ) ;
F_72 ( & V_46 -> V_123 ) ;
return 0 ;
}
int F_73 ( struct V_44 * V_46 )
{
F_63 ( & V_129 ) ;
F_70 ( V_46 ) ;
F_69 ( & V_129 ) ;
return 0 ;
}
enum V_9 V_135 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
if ( ! F_10 ( & V_11 -> V_12 , L_29 , V_11 -> V_15 -> type ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_74 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_140 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_43 ( V_4 , V_17 -> V_55 , V_33 ) )
goto V_141;
if ( ( V_33 & V_142 ) && V_17 -> V_143 ) {
if ( ! F_10 ( V_4 , L_30 ) )
goto V_141;
if ( ! F_43 ( V_4 ,
V_17 -> V_143 ,
V_33 ) )
goto V_141;
}
if ( ! F_10 ( V_4 , L_2 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9 F_75 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_140 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( & V_11 -> V_12 , L_31 ,
V_17 -> V_55 ,
V_17 -> V_143 ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_76 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_140 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_77 ( V_4 , V_17 -> V_55 ) ;
F_77 ( V_4 , V_17 -> V_143 ) ;
return V_20 ;
}
static enum V_9 F_78 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_140 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_79 ( V_4 , V_17 -> V_55 ) ;
F_79 ( V_4 , V_17 -> V_143 ) ;
return V_20 ;
}
static enum V_9 F_80 ( struct V_10 * V_11 ,
char * V_32 )
{
struct V_144 * V_17 ;
char V_89 [ V_90 ] ;
int V_145 , V_146 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_146 = F_53 ( V_17 -> V_147 ) ;
V_145 = F_53 ( V_17 -> V_148 ) ;
F_46 ( V_17 -> V_149 , V_89 ) ;
if ( ! F_10 ( & V_11 -> V_12 ,
L_32 ,
V_17 -> V_150 ,
V_17 -> V_151 ,
V_145 , V_32 ,
V_17 -> V_152 ,
V_17 -> V_149 ,
V_17 -> V_153 ,
V_146 , V_89 ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_81 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
return F_80 ( V_11 , L_33 ) ;
}
static enum V_9 F_82 ( struct V_10 * V_11 ,
int V_33 , struct V_44 * V_46 )
{
return F_80 ( V_11 , L_34 ) ;
}
static int F_83 ( struct V_10 * V_11 , char V_145 )
{
struct V_144 * V_17 ;
int V_146 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_145 )
V_145 = F_53 ( V_17 -> V_148 ) ;
V_146 = F_53 ( V_17 -> V_147 ) ;
if ( ! F_10 ( & V_11 -> V_12 , L_35 ,
V_17 -> V_150 ,
V_17 -> V_151 ,
V_145 ,
V_17 -> V_152 ,
V_17 -> V_149 ,
V_17 -> V_153 ,
V_146 ) )
return V_19 ;
return V_20 ;
}
static enum V_9 F_84 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
return F_83 ( V_11 , 0 ) ;
}
static enum V_9 F_85 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
return F_83 ( V_11 , '+' ) ;
}
static int F_86 ( struct V_10 * V_11 , char V_145 )
{
struct V_144 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
int V_146 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! V_145 )
V_145 = F_53 ( V_17 -> V_148 ) ;
V_146 = F_53 ( V_17 -> V_147 ) ;
F_77 ( V_4 , V_17 -> V_150 ) ;
F_77 ( V_4 , V_17 -> V_151 ) ;
F_77 ( V_4 , V_145 ) ;
F_77 ( V_4 , V_17 -> V_152 ) ;
F_77 ( V_4 , V_17 -> V_149 ) ;
F_77 ( V_4 , V_17 -> V_153 ) ;
F_77 ( V_4 , V_146 ) ;
return V_20 ;
}
static enum V_9 F_87 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
return F_86 ( V_11 , 0 ) ;
}
static enum V_9 F_88 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
return F_86 ( V_11 , '+' ) ;
}
static enum V_9 F_89 ( struct V_10 * V_11 ,
int V_33 , struct V_44 * V_46 )
{
struct V_144 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
F_79 ( V_4 , V_17 -> V_150 ) ;
F_79 ( V_4 , V_17 -> V_151 ) ;
F_79 ( V_4 , V_17 -> V_148 ) ;
F_79 ( V_4 , V_17 -> V_149 ) ;
F_79 ( V_4 , V_17 -> V_153 ) ;
F_79 ( V_4 , V_17 -> V_147 ) ;
return V_20 ;
}
static enum V_9 F_90 ( struct V_10 * V_11 ,
int V_33 , struct V_44 * V_46 )
{
struct V_154 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
unsigned long * V_31 ;
unsigned long * V_155 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
V_155 = ( unsigned long * ) ( ( long ) V_11 -> V_15 + V_11 -> V_114 ) ;
if ( ! F_6 ( V_4 , L_36 ) )
goto V_141;
for ( V_31 = V_17 -> V_74 ; V_31 && * V_31 != V_75 && V_31 < V_155 ; V_31 ++ ) {
if ( ! F_6 ( V_4 , L_14 ) )
goto V_141;
if ( ! F_43 ( V_4 , * V_31 , V_33 ) )
goto V_141;
if ( ! F_6 ( V_4 , L_2 ) )
goto V_141;
}
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9 F_91 ( struct V_10 * V_11 ,
int V_33 , struct V_44 * V_46 )
{
struct V_67 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_6 ( V_4 , L_37 ) )
goto V_141;
if ( ! F_37 ( V_17 , V_4 , V_33 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9
F_92 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_16 * V_17 ;
F_5 ( V_17 , V_14 ) ;
if ( ! F_43 ( V_4 , V_17 -> V_55 , V_33 ) )
goto V_141;
if ( ! F_6 ( V_4 , L_38 ) )
goto V_141;
if ( ! F_6 ( V_4 , V_17 -> V_18 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9
F_93 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( V_4 , L_39 , V_17 -> V_55 ) )
goto V_141;
if ( ! F_6 ( V_4 , V_17 -> V_18 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9
F_94 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
struct V_21 * V_17 ;
F_5 ( V_17 , V_14 ) ;
if ( ! F_43 ( V_4 , V_17 -> V_55 , V_33 ) )
goto V_141;
if ( ! F_6 ( V_4 , L_38 ) )
goto V_141;
if ( ! F_8 ( V_4 , V_17 -> V_22 , V_17 -> V_23 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9
F_95 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_21 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( V_4 , L_39 , V_17 -> V_55 ) )
goto V_141;
if ( ! F_8 ( V_4 , V_17 -> V_22 , V_17 -> V_23 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9 F_96 ( struct V_10 * V_11 ,
int V_33 , struct V_44 * V_46 )
{
struct V_24 * V_17 ;
struct V_3 * V_4 = & V_11 -> V_12 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_43 ( V_4 , V_17 -> V_55 , V_33 ) )
goto V_141;
if ( ! F_10 ( V_4 , L_40 , V_17 -> V_23 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
static enum V_9 F_97 ( struct V_10 * V_11 , int V_33 ,
struct V_44 * V_46 )
{
struct V_24 * V_17 ;
F_5 ( V_17 , V_11 -> V_15 ) ;
if ( ! F_10 ( & V_11 -> V_12 , L_41 , V_17 -> V_55 , V_17 -> V_23 ) )
goto V_141;
return V_20 ;
V_141:
return V_19 ;
}
T_5 static int F_98 ( void )
{
struct V_44 * V_46 ;
int V_37 , V_7 ;
for ( V_37 = 0 ; V_156 [ V_37 ] ; V_37 ++ ) {
V_46 = V_156 [ V_37 ] ;
V_7 = F_62 ( V_46 ) ;
if ( ! V_7 ) {
F_67 ( V_133 L_42 ,
V_46 -> type ) ;
F_26 ( 1 ) ;
}
}
return 0 ;
}
