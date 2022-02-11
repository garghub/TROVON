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
T_5 V_53 ;
if ( ! V_47 ) return;
V_53 = ( F_27 ( V_47 ) >> 2 ) & 3 ;
if ( V_53 == 1 ) {
V_35 -> V_49 |= 1 << V_54 ;
}
if ( V_53 == 2 ) {
V_35 -> V_49 |= 1 << V_54 ;
V_35 -> V_49 |= 1 << V_55 ;
}
V_35 -> V_49 |= 1 << V_56 ;
}
static void F_35 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
struct V_38 * V_57 ;
int V_58 ;
if ( ! V_47 ) return;
F_36 (nl_mode, tb, rem_mode) {
if ( F_37 ( V_57 ) == V_59 )
V_35 -> V_60 = 1 ;
}
}
static void F_38 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
struct V_38 * V_61 ;
struct V_38 * V_62 [ V_63 + 1 ] ;
static struct V_64 V_65 [ V_63 + 1 ] = {
{ V_66 , 0 , 0 } ,
{ V_67 , 0 , 0 } ,
{ V_68 , 0 , 0 } ,
{ V_68 , 0 , 0 } ,
{ V_68 , 0 , 0 } ,
{ V_68 , 0 , 0 } ,
{ V_67 , 0 , 0 }
} ;
int V_69 ;
if ( ! V_47 ) return;
F_36 (nl_freq, tb, rem_freq) {
T_6 V_70 ;
F_24 ( V_62 , V_63 ,
(struct V_38 * ) F_39 ( V_61 ) ,
F_40 ( V_61 ) , V_65 ) ;
if ( ! V_62 [ V_71 ] )
continue;
if ( V_62 [ V_72 ] )
continue;
V_70 = F_27 ( V_62 [ V_71 ] ) ;
F_41 ( V_35 -> V_73 , V_70 ) ;
}
}
static void F_42 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
struct V_38 * V_74 ;
struct V_38 * V_75 [ V_76 + 1 ] ;
int V_77 = 1 ;
int V_78 ;
if ( ! V_47 ) return;
F_36 (nl_band, tb, rem_band) {
V_77 ++ ;
F_24 ( V_75 , V_76 ,
(struct V_38 * ) F_39 ( V_74 ) ,
F_40 ( V_74 ) , NULL ) ;
#ifdef F_43
F_32 ( V_35 , V_75 [ F_43 ] ) ;
#endif
#ifdef F_44
F_34 ( V_35 , V_75 [ V_79 ] ) ;
#endif
F_38 ( V_35 , V_75 [ V_80 ] ) ;
}
}
static void F_45 ( struct V_31 * V_35 ,
struct V_38 * V_47 )
{
#ifdef F_46
int V_81 ;
struct V_38 * V_82 ;
if ( ! V_47 ) return;
F_36 (nl_cmd, tb, cmd) {
if( F_27 ( V_82 ) == V_83 )
V_35 -> V_84 = TRUE ;
}
#else
V_35 -> V_84 = TRUE ;
#endif
}
static int F_47 ( struct V_23 * T_2 , void * V_20 )
{
struct V_38 * V_39 [ V_40 + 1 ] ;
struct V_41 * V_42 = (struct V_41 * ) F_22 ( F_23 ( T_2 ) ) ;
struct V_85 * V_86 = (struct V_85 * ) V_20 ;
struct V_31 * V_35 ;
char * V_33 ;
int V_87 = 0 ;
F_24 ( V_39 , V_40 , F_25 ( V_42 , 0 ) ,
F_26 ( V_42 , 0 ) , NULL ) ;
if ( ! V_39 [ V_88 ] )
return V_24 ;
V_33 = F_48 ( L_6 , F_49 ( V_39 [ V_88 ] ) ) ;
V_35 = F_19 ( V_86 -> V_32 , V_33 ) ;
if ( ! V_35 ) {
V_35 = (struct V_31 * ) F_50 ( sizeof( * V_35 ) ) ;
if ( ! V_35 ) {
F_51 ( V_33 ) ;
return V_24 ;
}
V_87 = 1 ;
V_35 -> V_33 = V_33 ;
V_35 -> V_73 = F_52 ( FALSE , FALSE , sizeof( T_6 ) ) ;
V_35 -> V_49 = 1 << V_89 ;
} else {
F_51 ( V_33 ) ;
}
F_35 ( V_35 , V_39 [ V_90 ] ) ;
F_42 ( V_35 , V_39 [ V_91 ] ) ;
F_45 ( V_35 , V_39 [ V_92 ] ) ;
if ( V_87 )
F_41 ( V_86 -> V_32 , V_35 ) ;
return V_24 ;
}
static int F_53 ( T_3 * V_32 )
{
struct V_85 V_86 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
int V_21 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
V_86 . V_32 = V_32 ;
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
V_93 , V_94 , 0 ) ;
#ifdef F_6
if ( V_8 . V_16 ) {
F_54 ( T_2 , V_95 ) ;
}
#endif
F_16 ( V_26 , V_46 , V_28 , F_47 , & V_86 ) ;
V_21 = F_13 ( T_2 , V_26 ) ;
F_31 ( T_2 ) ;
return V_21 ;
#ifdef F_6
V_96:
F_31 ( T_2 ) ;
fprintf ( V_9 , L_7 ) ;
return - 1 ;
#endif
}
static int F_55 ( const char * V_33 )
{
int V_97 ;
int V_21 = - 1 ;
struct {
char V_98 [ V_99 ] ;
T_7 V_100 ;
T_8 V_101 ;
T_9 V_34 ;
T_9 V_102 ;
} V_103 ;
V_97 = F_56 ( V_104 , V_105 , 0 ) ;
if ( V_97 == - 1 )
return - 1 ;
F_57 ( V_103 . V_98 , V_33 , V_99 ) ;
if ( F_58 ( V_97 , 0x8B05 , & V_103 ) == 0 ) {
if ( V_103 . V_101 == 6 )
V_21 = V_103 . V_100 ;
}
F_59 ( V_97 ) ;
return V_21 ;
}
static int F_60 ( struct V_23 * T_2 , void * V_20 )
{
struct V_41 * V_42 = (struct V_41 * ) F_22 ( F_23 ( T_2 ) ) ;
struct V_38 * V_39 [ V_40 + 1 ] ;
struct V_106 * V_107 = (struct V_106 * ) V_20 ;
F_24 ( V_39 , V_40 , F_25 ( V_42 , 0 ) ,
F_26 ( V_42 , 0 ) , NULL ) ;
if ( V_39 [ V_108 ] ) {
V_107 -> type = F_27 ( V_39 [ V_108 ] ) ;
}
if ( V_39 [ V_109 ] ) {
V_107 -> V_110 = F_27 ( V_39 [ V_109 ] ) ;
}
if ( V_39 [ V_111 ] ) {
T_4 V_112 = FALSE ;
V_107 -> V_113 -> V_114 = F_27 ( V_39 [ V_111 ] ) ;
V_107 -> V_113 -> V_115 = V_89 ;
#ifdef F_44
if ( V_39 [ V_116 ] ) {
switch ( F_27 ( V_39 [ V_116 ] ) ) {
case V_117 :
V_107 -> V_113 -> V_115 = V_56 ;
V_112 = TRUE ;
break;
case V_118 :
V_107 -> V_113 -> V_115 = V_55 ;
V_112 = TRUE ;
break;
case V_119 :
V_107 -> V_113 -> V_115 = V_54 ;
V_112 = TRUE ;
break;
}
}
if ( V_39 [ V_120 ] ) {
V_107 -> V_113 -> V_121 =
F_27 ( V_39 [ V_120 ] ) ;
}
if ( V_39 [ V_122 ] ) {
V_107 -> V_113 -> V_123 =
F_27 ( V_39 [ V_122 ] ) ;
}
#endif
if ( ! V_112 && V_39 [ V_124 ] ) {
switch ( F_27 ( V_39 [ V_124 ] ) ) {
case V_125 :
V_107 -> V_113 -> V_115 = V_89 ;
break;
case V_126 :
V_107 -> V_113 -> V_115 = V_50 ;
break;
case V_127 :
V_107 -> V_113 -> V_115 = V_51 ;
break;
case V_128 :
V_107 -> V_113 -> V_115 = V_52 ;
break;
}
}
}
return V_24 ;
}
static int F_61 ( const char * V_129 , struct V_106 * V_107 )
{
int V_130 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
V_130 = F_62 ( V_129 ) ;
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_131 , 0 ) ;
F_63 ( T_2 , V_132 , V_130 ) ;
F_16 ( V_26 , V_46 , V_28 , F_60 , V_107 ) ;
if ( F_13 ( T_2 , V_26 ) ) {
F_31 ( T_2 ) ;
return - 1 ;
}
if ( V_107 -> V_113 -> V_114 == - 1 )
V_107 -> V_113 -> V_114 = F_55 ( V_129 ) ;
F_31 ( T_2 ) ;
return 0 ;
V_96:
F_31 ( T_2 ) ;
fprintf ( V_9 , L_7 ) ;
return - 1 ;
}
int F_64 ( const char * V_129 , struct V_133 * V_107 )
{
struct V_106 V_106 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_106 . V_113 = V_107 ;
V_106 . type = - 1 ;
V_106 . V_110 = - 1 ;
V_106 . V_113 -> V_114 = - 1 ;
V_106 . V_113 -> V_115 = V_89 ;
return F_61 ( V_129 , & V_106 ) ;
}
static int F_65 ( T_3 * V_32 )
{
unsigned int V_134 ;
struct V_31 * V_35 ;
V_135:
for ( V_134 = 0 ; V_134 < V_32 -> V_36 ; V_134 ++ ) {
V_35 = F_20 ( V_32 , struct V_31 * , V_134 ) ;
if ( ! V_35 -> V_60 ) {
F_66 ( V_32 , V_134 ) ;
F_67 ( V_35 -> V_73 , TRUE ) ;
F_51 ( V_35 -> V_33 ) ;
F_51 ( V_35 ) ;
goto V_135;
}
}
return 0 ;
}
static int F_68 ( T_3 * V_32 )
{
T_10 * V_136 ;
char line [ 200 ] ;
char * V_137 ;
T_11 * V_138 ;
char * V_21 ;
int V_34 ;
unsigned int V_134 ;
struct V_133 V_113 = { - 1 , V_89 , - 1 , - 1 , V_139 } ;
struct V_106 V_107 ;
struct V_31 * V_35 ;
F_53 ( V_32 ) ;
F_65 ( V_32 ) ;
V_136 = F_69 ( L_8 , L_9 ) ;
if( ! V_136 ) {
fprintf ( V_9 , L_10 ) ;
return - V_14 ;
}
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
V_21 = fgets ( line , sizeof( line ) , V_136 ) ;
if ( V_21 == NULL ) {
fprintf ( V_9 , L_11 ) ;
fclose ( V_136 ) ;
return - 1 ;
}
}
while( fgets ( line , sizeof( line ) , V_136 ) ) {
V_137 = F_70 ( line , ':' ) ;
if ( ! V_137 )
continue;
* V_137 = 0 ;
V_137 = line ;
while ( * V_137 && * V_137 == ' ' )
V_137 ++ ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_113 = & V_113 ;
F_61 ( V_137 , & V_107 ) ;
if ( V_107 . type == V_59 ) {
for ( V_134 = 0 ; V_134 < V_32 -> V_36 ; V_134 ++ ) {
V_35 = F_20 ( V_32 , struct V_31 * , V_134 ) ;
V_138 = F_48 ( L_12 , V_107 . V_110 ) ;
if ( V_138 ) {
if ( ! strcmp ( V_138 , V_35 -> V_33 ) ) {
F_51 ( V_35 -> V_33 ) ;
V_35 -> V_33 = F_71 ( V_137 ) ;
}
F_51 ( V_138 ) ;
}
}
}
}
fclose ( V_136 ) ;
return 0 ;
}
static int F_72 ( const char * V_33 )
{
int V_140 ;
struct V_141 V_141 ;
V_140 = F_56 ( V_142 , V_143 , 0 ) ;
if ( V_140 == - 1 )
return - 1 ;
F_57 ( V_141 . V_144 , V_33 , sizeof( V_141 . V_144 ) ) ;
if ( F_58 ( V_140 , V_145 , & V_141 ) )
goto V_146;
V_141 . V_147 |= V_148 ;
if ( F_58 ( V_140 , V_149 , & V_141 ) )
goto V_146;
F_59 ( V_140 ) ;
return 0 ;
V_146:
F_59 ( V_140 ) ;
return - 1 ;
}
static int F_73 ( const char * V_129 )
{
int V_130 , V_110 , V_4 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
V_130 = F_62 ( V_129 ) ;
if ( V_130 )
return F_72 ( V_129 ) ;
if ( sscanf ( V_129 , L_12 , & V_110 ) != 1 )
return - V_150 ;
V_26 = F_29 ( V_44 ) ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_151 , 0 ) ;
F_63 ( T_2 , V_109 , V_110 ) ;
F_74 ( T_2 , V_152 , V_129 ) ;
F_63 ( T_2 , V_108 , V_59 ) ;
V_4 = F_13 ( T_2 , V_26 ) ;
F_31 ( T_2 ) ;
if ( V_4 )
return V_4 ;
return F_72 ( V_129 ) ;
V_96:
F_31 ( T_2 ) ;
fprintf ( V_9 , L_7 ) ;
return 2 ;
}
int F_75 ( const char * V_129 , T_5 V_70 , int V_153 , T_5 V_18 V_154 , T_5 V_18 V_155 )
{
int V_130 , V_4 ;
struct V_23 * T_2 ;
struct V_25 * V_26 ;
V_4 = F_73 ( V_129 ) ;
if ( V_4 )
return V_4 ;
T_2 = F_28 () ;
if ( ! T_2 ) {
fprintf ( V_9 , L_5 ) ;
return 2 ;
}
V_26 = F_29 ( V_44 ) ;
V_130 = F_62 ( V_129 ) ;
#ifdef F_46
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_83 , 0 ) ;
#else
F_30 ( T_2 , 0 , 0 , V_8 . V_13 , 0 ,
0 , V_156 , 0 ) ;
#endif
F_63 ( T_2 , V_132 , V_130 ) ;
F_63 ( T_2 , V_111 , V_70 ) ;
switch ( V_153 ) {
#ifdef F_43
case V_89 :
F_63 ( T_2 , V_124 , V_125 ) ;
break;
case V_50 :
F_63 ( T_2 , V_124 , V_126 ) ;
break;
case V_51 :
F_63 ( T_2 , V_124 , V_127 ) ;
break;
case V_52 :
F_63 ( T_2 , V_124 , V_128 ) ;
break;
#endif
#ifdef F_44
case V_56 :
F_63 ( T_2 , V_116 , V_117 ) ;
F_63 ( T_2 , V_120 , V_154 ) ;
break;
case V_55 :
F_63 ( T_2 , V_116 , V_118 ) ;
F_63 ( T_2 , V_120 , V_154 ) ;
F_63 ( T_2 , V_122 , V_155 ) ;
break;
case V_54 :
F_63 ( T_2 , V_116 , V_119 ) ;
F_63 ( T_2 , V_120 , V_154 ) ;
break;
#endif
default:
break;
}
V_4 = F_13 ( T_2 , V_26 ) ;
F_31 ( T_2 ) ;
return V_4 ;
V_96:
F_31 ( T_2 ) ;
fprintf ( V_9 , L_7 ) ;
return 2 ;
}
T_3 * F_76 ( void )
{
T_3 * V_32 ;
if ( ! V_8 . V_2 )
return NULL ;
V_32 = F_52 ( FALSE , FALSE , sizeof( struct V_31 * ) ) ;
if ( ! V_32 )
return NULL ;
if ( F_68 ( V_32 ) ) {
F_77 ( V_32 ) ;
return NULL ;
}
return V_32 ;
}
int
F_78 ( const T_11 * V_157 )
{
int V_21 = - 1 ;
if ( ! V_157 )
return - 1 ;
if ( ! strcmp ( V_157 , V_158 ) )
V_21 = V_89 ;
if ( ! strcmp ( V_157 , V_159 ) )
V_21 = V_50 ;
if ( ! strcmp ( V_157 , V_160 ) )
V_21 = V_51 ;
if ( ! strcmp ( V_157 , V_161 ) )
V_21 = V_52 ;
if ( ! strcmp ( V_157 , V_162 ) )
V_21 = V_56 ;
if ( ! strcmp ( V_157 , V_163 ) )
V_21 = V_55 ;
if ( ! strcmp ( V_157 , V_164 ) )
V_21 = V_54 ;
return V_21 ;
}
const T_11
* F_79 ( int type )
{
switch ( type ) {
case V_89 :
return V_158 ;
case V_50 :
return V_159 ;
case V_51 :
return V_160 ;
case V_52 :
return V_161 ;
case V_56 :
return V_162 ;
case V_55 :
return V_163 ;
case V_54 :
return V_164 ;
}
return NULL ;
}
T_4 F_80 ( void )
{
return FALSE ;
}
int F_81 ( const char * V_129 V_18 , enum V_165 T_12 V_18 )
{
return - 1 ;
}
const char * F_82 ( void ) {
if ( F_83 ( V_166 , V_167 ) ) {
return V_166 ;
}
return NULL ;
}
int F_5 ( void )
{
if ( F_84 () == V_168 ) {
return 0 ;
}
return - 1 ;
}
T_3 * F_76 ( void )
{
T_3 * V_32 ;
T_13 * V_169 , * V_170 ;
int V_4 ;
T_11 * V_171 = NULL ;
V_32 = F_52 ( FALSE , FALSE , sizeof( struct V_31 * ) ) ;
if ( ! V_32 )
return NULL ;
V_169 = F_85 ( & V_4 , & V_171 ) ;
if ( V_169 == NULL || F_86 ( V_169 ) == 0 ) {
F_51 ( V_171 ) ;
F_67 ( V_32 , TRUE ) ;
return NULL ;
}
for ( V_170 = V_169 ; V_170 ; V_170 = F_87 ( V_170 ) ) {
struct V_31 * V_35 ;
T_14 * V_172 = ( T_14 * ) V_170 -> V_173 ;
char * V_33 ;
T_5 V_174 ;
T_5 V_34 ;
if ( ! V_172 ) continue;
V_33 = V_172 -> V_129 ;
if ( strlen ( V_33 ) > 4 && F_88 ( V_33 , V_175 ) ) V_33 += 4 ;
V_35 = (struct V_31 * ) F_50 ( sizeof( * V_35 ) ) ;
V_35 -> V_33 = F_71 ( V_33 ) ;
V_35 -> V_84 = TRUE ;
V_35 -> V_73 = F_52 ( FALSE , FALSE , sizeof( T_5 ) ) ;
V_35 -> V_49 = 1 << V_89 ;
for ( V_34 = 0 ; V_34 < V_172 -> V_176 ; V_34 ++ ) {
if ( V_172 -> V_177 [ V_34 ] . V_178 & V_179 ) {
V_35 -> V_49 |= 1 << V_51 ;
V_35 -> V_49 |= 1 << V_52 ;
break;
}
}
V_35 -> V_60 = 1 ;
for ( V_174 = 0 ; V_174 < V_172 -> V_176 ; V_174 ++ ) {
F_41 ( V_35 -> V_73 , V_172 -> V_177 [ V_174 ] . V_180 ) ;
}
F_41 ( V_32 , V_35 ) ;
}
return V_32 ;
}
int F_64 ( const char * V_129 , struct V_133 * V_107 )
{
T_13 * V_169 ;
int V_4 ;
T_11 * V_171 = NULL ;
T_14 * V_172 ;
if ( ! V_107 ) return - 1 ;
V_169 = F_85 ( & V_4 , & V_171 ) ;
if ( V_169 == NULL || F_86 ( V_169 ) == 0 ) {
F_51 ( V_171 ) ;
return - 1 ;
}
V_172 = F_89 ( V_169 , V_129 ) ;
if ( ! V_172 ) {
F_90 ( V_169 ) ;
return - 1 ;
}
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
V_107 -> V_114 = V_172 -> V_181 . V_180 ;
switch ( V_172 -> V_181 . V_182 ) {
case 0 :
V_107 -> V_115 = V_89 ;
break;
case - 1 :
V_107 -> V_115 = V_51 ;
break;
case 1 :
V_107 -> V_115 = V_52 ;
break;
default:
return - 1 ;
}
switch ( V_172 -> V_183 ) {
case V_184 :
V_107 -> V_185 = V_186 ;
break;
case V_187 :
V_107 -> V_185 = V_188 ;
break;
default:
V_107 -> V_185 = V_139 ;
break;
}
return 0 ;
}
int F_75 ( const char * V_129 , T_5 V_70 , int V_153 , T_5 V_18 V_154 , T_5 V_18 V_155 )
{
T_13 * V_169 ;
int V_4 ;
T_11 * V_171 = NULL ;
T_14 * V_172 ;
T_11 V_189 [ V_190 ] ;
T_15 V_191 ;
int V_192 = - 1 ;
V_169 = F_85 ( & V_4 , & V_171 ) ;
if ( V_169 == NULL || F_86 ( V_169 ) == 0 ) {
F_51 ( V_171 ) ;
return V_192 ;
}
V_172 = F_89 ( V_169 , V_129 ) ;
if ( ! V_172 ) {
F_90 ( V_169 ) ;
return V_192 ;
}
V_191 = F_91 ( V_172 -> V_129 , V_189 ) ;
if ( V_191 ) {
V_172 -> V_181 . V_180 = V_70 ;
switch ( V_153 ) {
case V_51 :
V_172 -> V_181 . V_182 = - 1 ;
break;
case V_52 :
V_172 -> V_181 . V_182 = 1 ;
break;
default:
V_172 -> V_181 . V_182 = 0 ;
break;
}
if ( F_92 ( V_191 , V_172 -> V_181 ) ) {
V_192 = 0 ;
}
F_93 ( V_191 ) ;
}
F_90 ( V_169 ) ;
return V_192 ;
}
int F_78 ( const T_11 * V_157 V_18 )
{
return - 1 ;
}
const T_11 * F_79 ( int type V_18 )
{
return NULL ;
}
T_4 F_80 ( void )
{
return TRUE ;
}
int F_81 ( const char * V_129 , enum V_165 T_12 )
{
T_13 * V_169 ;
int V_4 ;
T_11 * V_171 = NULL ;
T_14 * V_172 ;
T_11 V_189 [ V_190 ] ;
T_15 V_191 ;
int V_192 = - 1 ;
V_169 = F_85 ( & V_4 , & V_171 ) ;
if ( V_169 == NULL || F_86 ( V_169 ) == 0 ) {
F_51 ( V_171 ) ;
return V_192 ;
}
V_172 = F_89 ( V_169 , V_129 ) ;
if ( ! V_172 ) {
F_90 ( V_169 ) ;
return V_192 ;
}
V_191 = F_91 ( V_172 -> V_129 , V_189 ) ;
if ( V_191 ) {
T_16 V_193 = V_194 ;
switch ( T_12 ) {
case V_186 :
V_193 = V_184 ;
break;
case V_188 :
V_193 = V_187 ;
break;
default:
break;
}
if ( F_94 ( V_191 , V_193 ) ) {
F_95 ( V_191 ) ;
V_192 = 0 ;
}
F_93 ( V_191 ) ;
}
F_90 ( V_169 ) ;
return V_192 ;
}
const char * F_82 ( void )
{
T_17 V_195 = NULL ;
if ( ! V_196 && F_96 ( V_197 , F_97 ( L_13 ) , 0 , V_198 | V_199 , & V_195 ) == V_200 ) {
T_18 V_201 ;
T_19 V_202 [ V_203 ] ;
T_18 V_204 = sizeof( V_202 ) / sizeof( T_19 ) ;
V_201 = F_98 ( V_195 , NULL , NULL , NULL ,
( V_205 ) & V_202 , & V_204 ) ;
if ( V_201 == V_200 ) {
V_202 [ V_204 - 1 ] = V_206 '\0' ;
F_51 ( V_196 ) ;
V_196 = F_48 ( L_14 , F_99 ( V_202 ) ) ;
if ( ! F_83 ( V_196 , V_167 ) ) {
F_51 ( V_196 ) ;
V_196 = NULL ;
}
}
}
return V_196 ;
}
int F_5 ( void )
{
return - 1 ;
}
T_3 * F_76 ( void )
{
return NULL ;
}
int F_64 ( const char * V_129 V_18 , struct V_133 * V_107 V_18 )
{
return - 1 ;
}
int F_75 ( const char * V_129 V_18 , T_5 V_70 V_18 , int V_18 V_153 , T_5 V_18 V_154 , T_5 V_18 V_155 )
{
return - 1 ;
}
int F_78 ( const T_11 * V_157 V_18 )
{
return - 1 ;
}
const T_11 * F_79 ( int type V_18 )
{
return NULL ;
}
T_4 F_80 ( void )
{
return FALSE ;
}
int F_81 ( const char * V_129 V_18 , enum V_165 T_12 V_18 )
{
return - 1 ;
}
const char * F_82 ( void ) {
return NULL ;
}
void F_77 ( T_3 * V_32 )
{
struct V_31 * V_35 ;
if ( ! V_32 )
return;
while ( V_32 -> V_36 ) {
V_35 = F_20 ( V_32 , struct V_31 * , 0 ) ;
F_66 ( V_32 , 0 ) ;
F_67 ( V_35 -> V_73 , TRUE ) ;
F_51 ( V_35 -> V_33 ) ;
F_51 ( V_35 ) ;
}
F_67 ( V_32 , TRUE ) ;
}
