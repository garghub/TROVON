static inline struct V_1 * F_1 ( void )
{
return F_2 () ;
}
static inline void F_3 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) ;
}
int F_5 ( void )
{
int V_4 ;
#ifdef F_6
int V_5 = 0 ;
#endif
struct V_6 * V_7 = & V_8 ;
V_7 -> V_2 = F_1 () ;
if ( ! V_7 -> V_2 ) {
fprintf ( V_9 , L_1 ) ;
return - V_10 ;
}
if ( F_7 ( V_7 -> V_2 ) ) {
fprintf ( V_9 , L_2 ) ;
V_4 = - V_11 ;
goto V_12;
}
V_7 -> V_13 = F_8 ( V_7 -> V_2 , L_3 ) ;
if ( V_7 -> V_13 < 0 ) {
fprintf ( V_9 , L_4 ) ;
V_4 = - V_14 ;
goto V_12;
}
#ifdef F_6
F_9 ( & V_5 ) ;
if ( V_5 & V_15 )
V_7 -> V_16 = TRUE ;
#endif
return 0 ;
V_12:
F_3 ( V_7 -> V_2 ) ;
V_7 -> V_2 = 0 ;
return V_4 ;
}
static int F_10 ( struct V_17 * T_1 V_18 , struct V_19 * V_4 ,
void * V_20 )
{
int * V_21 = ( int * ) V_20 ;
* V_21 = V_4 -> error ;
return V_22 ;
}
static int F_11 ( struct V_23 * T_2 V_18 , void * V_20 )
{
int * V_21 = ( int * ) V_20 ;
* V_21 = 0 ;
return V_24 ;
}
static int F_12 ( struct V_23 * T_2 V_18 , void * V_20 )
{
int * V_21 = ( int * ) V_20 ;
* V_21 = 0 ;
return V_22 ;
}
static int F_13 ( struct V_23 * T_2 , struct V_25 * V_26 )
{
volatile int V_4 ;
if ( ! V_8 . V_2 )
return - V_11 ;
V_4 = F_14 ( V_8 . V_2 , T_2 ) ;
if ( V_4 < 0 )
goto V_27;
V_4 = 1 ;
F_15 ( V_26 , V_28 , F_10 , ( void * ) & V_4 ) ;
F_16 ( V_26 , V_29 , V_28 , F_11 , ( void * ) & V_4 ) ;
F_16 ( V_26 , V_30 , V_28 , F_12 , ( void * ) & V_4 ) ;
while ( V_4 > 0 )
F_17 ( V_8 . V_2 , V_26 ) ;
V_27:
F_18 ( V_26 ) ;
return V_4 ;
}
static struct V_31 *
F_19 ( T_3 * V_32 ,
char * V_33 )
{
unsigned int V_34 ;
struct V_31 * V_35 ;
for ( V_34 = 0 ; V_34 < V_32 -> V_36 ; V_34 ++ ) {
V_35 = F_20 ( V_32 , struct V_31 * , V_34 ) ;
if ( ! strcmp ( V_35 -> V_33 , V_33 ) )
return V_35 ;
}
return NULL ;
}
static int F_21 ( struct V_23 * T_2 , void * V_20 )
{
int * V_37 = ( int * ) V_20 ;
struct V_38 * V_39 [ V_40 + 1 ] ;
struct V_41 * V_42 = (struct V_41 * ) F_22 ( F_23 ( T_2 ) ) ;
F_24 ( V_39 , V_40 , F_25 ( V_42 , 0 ) ,
F_26 ( V_42 , 0 ) , NULL ) ;
if ( V_39 [ V_43 ] )
* V_37 = F_27 ( V_39 [ V_43 ] ) ;
return V_24 ;
}
static int F_9 ( int * V_5 )
{
struct V_23 * T_2 ;
struct V_25 * V_26 ;
int V_21 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 , 0 ,
V_45 , 0 ) ;
F_16 ( V_26 , V_46 , V_28 , F_21 , V_5 ) ;
V_21 = F_13 ( T_2 , V_26 ) ;
F_31 ( T_2 ) ;
return V_21 ;
}
static void F_32 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
T_4 V_48 ;
if ( ! V_47 ) return;
V_35 -> V_49 |= 1 << V_50 ;
V_48 = ! ! ( F_33 ( V_47 ) & 0x02 ) ;
if ( V_48 ) {
V_35 -> V_49 |= 1 << V_51 ;
V_35 -> V_49 |= 1 << V_52 ;
}
}
static void F_34 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
struct V_38 * V_53 ;
int V_54 ;
if ( ! V_47 ) return;
F_35 (nl_mode, tb, rem_mode) {
if ( F_36 ( V_53 ) == V_55 )
V_35 -> V_56 = 1 ;
}
}
static void F_37 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
struct V_38 * V_57 ;
struct V_38 * V_58 [ V_59 + 1 ] ;
static struct V_60 V_61 [ V_59 + 1 ] = {
{ V_62 , 0 , 0 } ,
{ V_63 , 0 , 0 } ,
{ V_64 , 0 , 0 } ,
{ V_64 , 0 , 0 } ,
{ V_64 , 0 , 0 } ,
{ V_64 , 0 , 0 } ,
{ V_63 , 0 , 0 }
} ;
int V_65 ;
if ( ! V_47 ) return;
F_35 (nl_freq, tb, rem_freq) {
T_5 V_66 ;
F_24 ( V_58 , V_59 ,
(struct V_38 * ) F_38 ( V_57 ) ,
F_39 ( V_57 ) , V_61 ) ;
if ( ! V_58 [ V_67 ] )
continue;
if ( V_58 [ V_68 ] )
continue;
V_66 = F_27 ( V_58 [ V_67 ] ) ;
F_40 ( V_35 -> V_69 , V_66 ) ;
}
}
static void F_41 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
struct V_38 * V_70 ;
struct V_38 * V_71 [ V_72 + 1 ] ;
int V_73 = 1 ;
int V_74 ;
if ( ! V_47 ) return;
F_35 (nl_band, tb, rem_band) {
V_73 ++ ;
F_24 ( V_71 , V_72 ,
(struct V_38 * ) F_38 ( V_70 ) ,
F_39 ( V_70 ) , NULL ) ;
#ifdef F_42
F_32 ( V_35 , V_71 [ F_42 ] ) ;
#endif
F_37 ( V_35 , V_71 [ V_75 ] ) ;
}
}
static void F_43 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
#ifdef F_44
int V_76 ;
struct V_38 * V_77 ;
if ( ! V_47 ) return;
F_35 (nl_cmd, tb, cmd) {
if( F_27 ( V_77 ) == V_78 )
V_35 -> V_79 = TRUE ;
}
#else
V_35 -> V_79 = TRUE ;
#endif
}
static int F_45 ( struct V_23 * T_2 , void * V_20 )
{
struct V_38 * V_39 [ V_40 + 1 ] ;
struct V_41 * V_42 = (struct V_41 * ) F_22 ( F_23 ( T_2 ) ) ;
struct V_80 * V_81 = (struct V_80 * ) V_20 ;
struct V_31 * V_35 ;
char * V_33 ;
int V_82 = 0 ;
F_24 ( V_39 , V_40 , F_25 ( V_42 , 0 ) ,
F_26 ( V_42 , 0 ) , NULL ) ;
if ( ! V_39 [ V_83 ] )
return V_24 ;
V_33 = F_46 ( L_6 , F_47 ( V_39 [ V_83 ] ) ) ;
V_35 = F_19 ( V_81 -> V_32 , V_33 ) ;
if ( ! V_35 ) {
V_35 = (struct V_31 * ) F_48 ( sizeof( * V_35 ) ) ;
if ( ! V_35 ) {
F_49 ( V_33 ) ;
return V_24 ;
}
V_82 = 1 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_69 = F_50 ( FALSE , FALSE , sizeof( T_5 ) ) ;
V_35 -> V_49 = 1 << V_84 ;
} else {
F_49 ( V_33 ) ;
}
F_34 ( V_35 , V_39 [ V_85 ] ) ;
F_41 ( V_35 , V_39 [ V_86 ] ) ;
F_43 ( V_35 , V_39 [ V_87 ] ) ;
if ( V_82 )
F_40 ( V_81 -> V_32 , V_35 ) ;
return V_24 ;
}
static int F_51 ( T_3 * V_32 )
{
struct V_80 V_81 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
int V_21 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
V_81 . V_32 = V_32 ;
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
V_88 , V_89 , 0 ) ;
#ifdef F_6
if ( V_8 . V_16 ) {
F_52 ( T_2 , V_90 ) ;
}
#endif
F_16 ( V_26 , V_46 , V_28 , F_45 , & V_81 ) ;
V_21 = F_13 ( T_2 , V_26 ) ;
F_31 ( T_2 ) ;
return V_21 ;
#ifdef F_6
V_91:
F_31 ( T_2 ) ;
fprintf ( V_9 , L_7 ) ;
return - 1 ;
#endif
}
static int F_53 ( const char * V_33 )
{
int V_92 ;
int V_21 = - 1 ;
struct {
char V_93 [ V_94 ] ;
T_6 V_95 ;
T_7 V_96 ;
T_8 V_34 ;
T_8 V_97 ;
} V_98 ;
V_92 = F_54 ( V_99 , V_100 , 0 ) ;
if ( V_92 == - 1 )
return - 1 ;
F_55 ( V_98 . V_93 , V_33 , V_94 ) ;
if ( F_56 ( V_92 , 0x8B05 , & V_98 ) == 0 ) {
if ( V_98 . V_96 == 6 )
V_21 = V_98 . V_95 ;
}
F_57 ( V_92 ) ;
return V_21 ;
}
static int F_58 ( struct V_23 * T_2 , void * V_20 )
{
struct V_41 * V_42 = (struct V_41 * ) F_22 ( F_23 ( T_2 ) ) ;
struct V_38 * V_39 [ V_40 + 1 ] ;
struct V_101 * V_102 = (struct V_101 * ) V_20 ;
F_24 ( V_39 , V_40 , F_25 ( V_42 , 0 ) ,
F_26 ( V_42 , 0 ) , NULL ) ;
if ( V_39 [ V_103 ] ) {
V_102 -> type = F_27 ( V_39 [ V_103 ] ) ;
}
if ( V_39 [ V_104 ] ) {
V_102 -> V_105 = F_27 ( V_39 [ V_104 ] ) ;
}
if ( V_39 [ V_106 ] ) {
V_102 -> V_107 -> V_108 = F_27 ( V_39 [ V_106 ] ) ;
V_102 -> V_107 -> V_109 = V_84 ;
if ( V_39 [ V_110 ] ) {
switch ( F_27 ( V_39 [ V_110 ] ) ) {
case V_111 :
V_102 -> V_107 -> V_109 = V_84 ;
break;
case V_112 :
V_102 -> V_107 -> V_109 = V_50 ;
break;
case V_113 :
V_102 -> V_107 -> V_109 = V_51 ;
break;
case V_114 :
V_102 -> V_107 -> V_109 = V_52 ;
break;
}
}
}
return V_24 ;
}
static int F_59 ( const char * V_115 , struct V_101 * V_102 )
{
int V_116 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
V_116 = F_60 ( V_115 ) ;
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_117 , 0 ) ;
F_61 ( T_2 , V_118 , V_116 ) ;
F_16 ( V_26 , V_46 , V_28 , F_58 , V_102 ) ;
if ( F_13 ( T_2 , V_26 ) ) {
F_31 ( T_2 ) ;
return - 1 ;
}
if ( V_102 -> V_107 -> V_108 == - 1 )
V_102 -> V_107 -> V_108 = F_53 ( V_115 ) ;
F_31 ( T_2 ) ;
return 0 ;
V_91:
F_31 ( T_2 ) ;
fprintf ( V_9 , L_7 ) ;
return - 1 ;
}
int F_62 ( const char * V_115 , struct V_119 * V_102 )
{
struct V_101 V_101 ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_101 . V_107 = V_102 ;
V_101 . type = - 1 ;
V_101 . V_105 = - 1 ;
V_101 . V_107 -> V_108 = - 1 ;
V_101 . V_107 -> V_109 = V_84 ;
return F_59 ( V_115 , & V_101 ) ;
}
static int F_63 ( T_3 * V_32 )
{
unsigned int V_120 ;
struct V_31 * V_35 ;
V_121:
for ( V_120 = 0 ; V_120 < V_32 -> V_36 ; V_120 ++ ) {
V_35 = F_20 ( V_32 , struct V_31 * , V_120 ) ;
if ( ! V_35 -> V_56 ) {
F_64 ( V_32 , V_120 ) ;
F_65 ( V_35 -> V_69 , TRUE ) ;
F_49 ( V_35 -> V_33 ) ;
F_49 ( V_35 ) ;
goto V_121;
}
}
return 0 ;
}
static int F_66 ( T_3 * V_32 )
{
T_9 * V_122 ;
char line [ 200 ] ;
char * V_123 ;
T_10 * V_124 ;
char * V_21 ;
int V_34 ;
unsigned int V_120 ;
struct V_119 V_107 = { - 1 , V_84 , V_125 } ;
struct V_101 V_102 ;
struct V_31 * V_35 ;
F_51 ( V_32 ) ;
F_63 ( V_32 ) ;
V_122 = F_67 ( L_8 , L_9 ) ;
if( ! V_122 ) {
fprintf ( V_9 , L_10 ) ;
return - V_14 ;
}
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
V_21 = fgets ( line , sizeof( line ) , V_122 ) ;
if ( V_21 == NULL ) {
fprintf ( V_9 , L_11 ) ;
fclose ( V_122 ) ;
return - 1 ;
}
}
while( fgets ( line , sizeof( line ) , V_122 ) ) {
V_123 = F_68 ( line , ':' ) ;
if ( ! V_123 )
continue;
* V_123 = 0 ;
V_123 = line ;
while ( * V_123 && * V_123 == ' ' )
V_123 ++ ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_107 = & V_107 ;
F_59 ( V_123 , & V_102 ) ;
if ( V_102 . type == V_55 ) {
for ( V_120 = 0 ; V_120 < V_32 -> V_36 ; V_120 ++ ) {
V_35 = F_20 ( V_32 , struct V_31 * , V_120 ) ;
V_124 = F_46 ( L_12 , V_102 . V_105 ) ;
if ( V_124 ) {
if ( ! strcmp ( V_124 , V_35 -> V_33 ) ) {
F_49 ( V_35 -> V_33 ) ;
V_35 -> V_33 = F_69 ( V_123 ) ;
}
F_49 ( V_124 ) ;
}
}
}
}
fclose ( V_122 ) ;
return 0 ;
}
static int F_70 ( const char * V_33 )
{
int V_126 ;
struct V_127 V_127 ;
V_126 = F_54 ( V_128 , V_129 , 0 ) ;
if ( V_126 == - 1 )
return - 1 ;
F_55 ( V_127 . V_130 , V_33 , sizeof( V_127 . V_130 ) ) ;
if ( F_56 ( V_126 , V_131 , & V_127 ) )
goto V_132;
V_127 . V_133 |= V_134 ;
if ( F_56 ( V_126 , V_135 , & V_127 ) )
goto V_132;
F_57 ( V_126 ) ;
return 0 ;
V_132:
F_57 ( V_126 ) ;
return - 1 ;
}
static int F_71 ( const char * V_115 )
{
int V_116 , V_105 , V_4 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
V_116 = F_60 ( V_115 ) ;
if ( V_116 )
return F_70 ( V_115 ) ;
if ( sscanf ( V_115 , L_12 , & V_105 ) != 1 )
return - V_136 ;
V_26 = F_29 ( V_44 ) ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_137 , 0 ) ;
F_61 ( T_2 , V_104 , V_105 ) ;
F_72 ( T_2 , V_138 , V_115 ) ;
F_61 ( T_2 , V_103 , V_55 ) ;
V_4 = F_13 ( T_2 , V_26 ) ;
if ( V_4 )
return V_4 ;
return F_70 ( V_115 ) ;
V_91:
fprintf ( V_9 , L_7 ) ;
return 2 ;
}
int F_73 ( const char * V_115 , int V_66 , int V_139 )
{
int V_116 , V_4 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
V_4 = F_71 ( V_115 ) ;
if ( V_4 )
return V_4 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
V_116 = F_60 ( V_115 ) ;
#ifdef F_44
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_78 , 0 ) ;
#else
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_140 , 0 ) ;
#endif
F_61 ( T_2 , V_118 , V_116 ) ;
F_61 ( T_2 , V_106 , V_66 ) ;
switch ( V_139 ) {
#ifdef F_42
case V_84 :
F_61 ( T_2 , V_110 , V_111 ) ;
break;
case V_50 :
F_61 ( T_2 , V_110 , V_112 ) ;
break;
case V_51 :
F_61 ( T_2 , V_110 , V_113 ) ;
break;
case V_52 :
F_61 ( T_2 , V_110 , V_114 ) ;
break;
#endif
default:
break;
}
V_4 = F_13 ( T_2 , V_26 ) ;
return V_4 ;
V_91:
fprintf ( V_9 , L_7 ) ;
return 2 ;
}
T_3 * F_74 ( void )
{
T_3 * V_32 ;
if ( ! V_8 . V_2 )
return NULL ;
V_32 = F_50 ( FALSE , FALSE , sizeof( struct V_31 * ) ) ;
if ( ! V_32 )
return NULL ;
if ( F_66 ( V_32 ) ) {
F_75 ( V_32 ) ;
return NULL ;
}
return V_32 ;
}
int
F_76 ( const T_10 * V_141 )
{
int V_21 = - 1 ;
if ( ! V_141 )
return - 1 ;
if ( ! strcmp ( V_141 , V_142 ) )
V_21 = V_84 ;
if ( ! strcmp ( V_141 , V_143 ) )
V_21 = V_50 ;
if ( ! strcmp ( V_141 , V_144 ) )
V_21 = V_51 ;
if ( ! strcmp ( V_141 , V_145 ) )
V_21 = V_52 ;
return V_21 ;
}
const T_10
* F_77 ( int type )
{
switch ( type ) {
case V_84 :
return V_142 ;
case V_50 :
return V_143 ;
case V_51 :
return V_144 ;
case V_52 :
return V_145 ;
}
return NULL ;
}
T_4 F_78 ( void )
{
return FALSE ;
}
int F_79 ( const char * V_115 V_18 , enum V_146 T_11 V_18 )
{
return - 1 ;
}
const char * F_80 ( void ) {
if ( F_81 ( V_147 , V_148 ) ) {
return V_147 ;
}
return NULL ;
}
int F_5 ( void )
{
if ( F_82 () == V_149 ) {
return 0 ;
}
return - 1 ;
}
T_3 * F_74 ( void )
{
T_3 * V_32 ;
T_12 * V_150 , * V_151 ;
int V_4 ;
T_10 * V_152 = NULL ;
V_32 = F_50 ( FALSE , FALSE , sizeof( struct V_31 * ) ) ;
if ( ! V_32 )
return NULL ;
V_150 = F_83 ( & V_4 , & V_152 ) ;
if ( V_150 == NULL || F_84 ( V_150 ) == 0 ) {
F_49 ( V_152 ) ;
F_65 ( V_32 , TRUE ) ;
return NULL ;
}
for ( V_151 = V_150 ; V_151 ; V_151 = F_85 ( V_151 ) ) {
struct V_31 * V_35 ;
T_13 * V_153 = ( T_13 * ) V_151 -> V_154 ;
char * V_33 ;
T_14 V_155 ;
T_14 V_34 ;
if ( ! V_153 ) continue;
V_33 = V_153 -> V_115 ;
if ( strlen ( V_33 ) > 4 && F_86 ( V_33 , V_156 ) ) V_33 += 4 ;
V_35 = (struct V_31 * ) F_48 ( sizeof( * V_35 ) ) ;
V_35 -> V_33 = F_69 ( V_33 ) ;
V_35 -> V_79 = TRUE ;
V_35 -> V_69 = F_50 ( FALSE , FALSE , sizeof( T_14 ) ) ;
V_35 -> V_49 = 1 << V_84 ;
for ( V_34 = 0 ; V_34 < V_153 -> V_157 ; V_34 ++ ) {
if ( V_153 -> V_158 [ V_34 ] . V_159 & V_160 ) {
V_35 -> V_49 |= 1 << V_51 ;
V_35 -> V_49 |= 1 << V_52 ;
break;
}
}
V_35 -> V_56 = 1 ;
for ( V_155 = 0 ; V_155 < V_153 -> V_157 ; V_155 ++ ) {
F_40 ( V_35 -> V_69 , V_153 -> V_158 [ V_155 ] . V_161 ) ;
}
F_40 ( V_32 , V_35 ) ;
}
return V_32 ;
}
int F_62 ( const char * V_115 , struct V_119 * V_102 )
{
T_12 * V_150 ;
int V_4 ;
T_10 * V_152 = NULL ;
T_13 * V_153 ;
if ( ! V_102 ) return - 1 ;
V_150 = F_83 ( & V_4 , & V_152 ) ;
if ( V_150 == NULL || F_84 ( V_150 ) == 0 ) {
F_49 ( V_152 ) ;
return - 1 ;
}
V_153 = F_87 ( V_150 , V_115 ) ;
if ( ! V_153 ) {
F_88 ( V_150 ) ;
return - 1 ;
}
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_102 -> V_108 = V_153 -> V_162 . V_161 ;
switch ( V_153 -> V_162 . V_163 ) {
case 0 :
V_102 -> V_109 = V_84 ;
break;
case - 1 :
V_102 -> V_109 = V_51 ;
break;
case 1 :
V_102 -> V_109 = V_52 ;
break;
default:
return - 1 ;
}
switch ( V_153 -> V_164 ) {
case V_165 :
V_102 -> V_166 = V_167 ;
break;
case V_168 :
V_102 -> V_166 = V_169 ;
break;
default:
V_102 -> V_166 = V_125 ;
break;
}
return 0 ;
}
int F_73 ( const char * V_115 , int V_66 , int V_139 )
{
T_12 * V_150 ;
int V_4 ;
T_10 * V_152 = NULL ;
T_13 * V_153 ;
T_10 V_170 [ V_171 ] ;
T_15 V_172 ;
int V_173 = - 1 ;
V_150 = F_83 ( & V_4 , & V_152 ) ;
if ( V_150 == NULL || F_84 ( V_150 ) == 0 ) {
F_49 ( V_152 ) ;
return V_173 ;
}
V_153 = F_87 ( V_150 , V_115 ) ;
if ( ! V_153 ) {
F_88 ( V_150 ) ;
return V_173 ;
}
V_172 = F_89 ( V_153 -> V_115 , V_170 ) ;
if ( V_172 ) {
V_153 -> V_162 . V_161 = V_66 ;
switch ( V_139 ) {
case V_51 :
V_153 -> V_162 . V_163 = - 1 ;
break;
case V_52 :
V_153 -> V_162 . V_163 = 1 ;
break;
default:
V_153 -> V_162 . V_163 = 0 ;
break;
}
if ( F_90 ( V_172 , V_153 -> V_162 ) ) {
V_173 = 0 ;
}
F_91 ( V_172 ) ;
}
F_88 ( V_150 ) ;
return V_173 ;
}
int F_76 ( const T_10 * V_141 V_18 )
{
return - 1 ;
}
const T_10 * F_77 ( int type V_18 )
{
return NULL ;
}
T_4 F_78 ( void )
{
return TRUE ;
}
int F_79 ( const char * V_115 , enum V_146 T_11 )
{
T_12 * V_150 ;
int V_4 ;
T_10 * V_152 = NULL ;
T_13 * V_153 ;
T_10 V_170 [ V_171 ] ;
T_15 V_172 ;
int V_173 = - 1 ;
V_150 = F_83 ( & V_4 , & V_152 ) ;
if ( V_150 == NULL || F_84 ( V_150 ) == 0 ) {
F_49 ( V_152 ) ;
return V_173 ;
}
V_153 = F_87 ( V_150 , V_115 ) ;
if ( ! V_153 ) {
F_88 ( V_150 ) ;
return V_173 ;
}
V_172 = F_89 ( V_153 -> V_115 , V_170 ) ;
if ( V_172 ) {
T_16 V_174 = V_175 ;
switch ( T_11 ) {
case V_167 :
V_174 = V_165 ;
break;
case V_169 :
V_174 = V_168 ;
break;
default:
break;
}
if ( F_92 ( V_172 , V_174 ) ) {
F_93 ( V_172 ) ;
V_173 = 0 ;
}
F_91 ( V_172 ) ;
}
F_88 ( V_150 ) ;
return V_173 ;
}
const char * F_80 ( void )
{
T_17 V_176 = NULL ;
if ( ! V_177 && F_94 ( V_178 , F_95 ( L_13 ) , 0 , V_179 | V_180 , & V_176 ) == V_181 ) {
T_18 V_182 ;
T_19 V_183 [ V_184 ] ;
T_18 V_185 = sizeof( V_183 ) / sizeof( T_19 ) ;
V_182 = F_96 ( V_176 , NULL , NULL , NULL ,
( V_186 ) & V_183 , & V_185 ) ;
if ( V_182 == V_181 ) {
V_183 [ V_185 - 1 ] = V_187 '\0' ;
F_49 ( V_177 ) ;
V_177 = F_46 ( L_14 , F_97 ( V_183 ) ) ;
if ( ! F_81 ( V_177 , V_148 ) ) {
F_49 ( V_177 ) ;
V_177 = NULL ;
}
}
}
return V_177 ;
}
int F_5 ( void )
{
return - 1 ;
}
T_3 * F_74 ( void )
{
return NULL ;
}
int F_62 ( const char * V_115 V_18 , struct V_119 * V_102 V_18 )
{
return - 1 ;
}
int F_73 ( const char * V_115 V_18 , int V_66 V_18 , int V_18 V_139 )
{
return - 1 ;
}
int F_76 ( const T_10 * V_141 V_18 )
{
return - 1 ;
}
const T_10 * F_77 ( int type V_18 )
{
return NULL ;
}
T_4 F_78 ( void )
{
return FALSE ;
}
int F_79 ( const char * V_115 V_18 , enum V_146 T_11 V_18 )
{
return - 1 ;
}
const char * F_80 ( void ) {
return NULL ;
}
void F_75 ( T_3 * V_32 )
{
struct V_31 * V_35 ;
if ( ! V_32 )
return;
while ( V_32 -> V_36 ) {
V_35 = F_20 ( V_32 , struct V_31 * , 0 ) ;
F_64 ( V_32 , 0 ) ;
F_65 ( V_35 -> V_69 , TRUE ) ;
F_49 ( V_35 -> V_33 ) ;
F_49 ( V_35 ) ;
}
F_65 ( V_32 , TRUE ) ;
}
int F_98 ( int V_66 )
{
if ( V_66 == 2484 )
return 14 ;
if ( V_66 < 2484 )
return ( V_66 - 2407 ) / 5 ;
if ( V_66 < 5000 )
return V_66 / 5 - 800 ;
return V_66 / 5 - 1000 ;
}
