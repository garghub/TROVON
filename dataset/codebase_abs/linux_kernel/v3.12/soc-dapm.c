static void F_1 ( T_1 V_1 )
{
if ( V_1 )
F_2 ( F_3 ( V_1 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_1 , const char * V_4 , ... )
{
T_2 args ;
char * V_5 ;
if ( ! V_1 )
return;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( V_5 == NULL )
return;
va_start ( args , V_4 ) ;
vsnprintf ( V_5 , V_6 , V_4 , args ) ;
F_6 ( V_3 , L_1 , V_5 ) ;
va_end ( args ) ;
F_7 ( V_5 ) ;
}
static bool F_8 ( struct V_8 * V_9 )
{
return ! F_9 ( & V_9 -> V_10 ) ;
}
void F_10 ( struct V_8 * V_9 , const char * V_11 )
{
if ( ! F_8 ( V_9 ) ) {
F_11 ( V_9 -> V_12 -> V_3 , L_2 ,
V_9 -> V_13 , V_11 ) ;
F_12 ( & V_9 -> V_10 , & V_9 -> V_12 -> V_14 -> V_15 ) ;
}
}
void F_13 ( struct V_16 * V_12 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 (w, &card->widgets, list) {
switch ( V_9 -> V_19 ) {
case V_20 :
case V_21 :
F_10 ( V_9 , L_3 ) ;
break;
default:
break;
}
}
F_16 ( & V_14 -> V_18 ) ;
}
static inline struct V_8 * F_17 (
const struct V_8 * V_22 )
{
return F_18 ( V_22 , sizeof( * V_22 ) , V_7 ) ;
}
static int F_19 ( struct V_8 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_27 = F_20 ( sizeof( * V_27 ) , V_7 ) ;
if ( ! V_27 ) {
F_21 ( V_23 -> V_12 -> V_3 ,
L_4 ,
V_23 -> V_13 ) ;
return - V_30 ;
}
F_22 ( & V_27 -> V_31 ) ;
switch ( V_23 -> V_19 ) {
case V_32 :
case V_33 :
case V_34 :
V_29 = (struct V_28 * ) V_25 -> V_35 ;
if ( V_29 -> V_36 ) {
struct V_8 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_38 = V_29 -> V_38 ;
V_37 . V_39 = ( 1 << F_23 ( V_29 -> V_40 ) ) - 1 ;
V_37 . V_41 = V_29 -> V_41 ;
if ( V_29 -> V_42 )
V_37 . V_43 = V_29 -> V_40 ;
else
V_37 . V_43 = 0 ;
V_37 . V_44 = V_37 . V_43 ;
V_37 . V_19 = V_45 ;
V_37 . V_13 = V_25 -> V_19 . V_13 ;
V_27 -> V_46 = V_37 . V_44 ;
V_27 -> V_23 = F_24 ( V_23 -> V_12 ,
& V_37 ) ;
if ( ! V_27 -> V_23 ) {
F_7 ( V_27 ) ;
return - V_30 ;
}
}
break;
default:
break;
}
V_25 -> V_47 = V_27 ;
return 0 ;
}
static void F_25 ( struct V_24 * V_48 )
{
struct V_26 * V_27 = F_26 ( V_48 ) ;
F_7 ( V_27 -> V_23 ) ;
F_7 ( V_27 -> V_49 ) ;
F_7 ( V_27 ) ;
}
static struct V_50 * F_27 (
const struct V_24 * V_25 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
return V_27 -> V_49 ;
}
static int F_28 ( struct V_24 * V_25 ,
struct V_8 * V_23 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
struct V_50 * V_51 ;
unsigned int V_52 ;
if ( V_27 -> V_49 )
V_52 = V_27 -> V_49 -> V_53 + 1 ;
else
V_52 = 1 ;
V_51 = F_29 ( V_27 -> V_49 ,
sizeof( * V_51 ) + sizeof( V_23 ) * V_52 , V_7 ) ;
if ( ! V_51 )
return - V_30 ;
V_51 -> V_54 [ V_52 - 1 ] = V_23 ;
V_51 -> V_53 = V_52 ;
V_27 -> V_49 = V_51 ;
return 0 ;
}
static void F_30 ( const struct V_24 * V_25 ,
struct V_55 * V_56 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
F_12 ( & V_56 -> V_57 , & V_27 -> V_31 ) ;
if ( V_27 -> V_23 ) {
F_31 ( V_27 -> V_23 -> V_12 , V_27 -> V_23 ,
V_56 -> V_58 , NULL , NULL ) ;
}
}
static bool F_32 ( const struct V_24 * V_25 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
if ( ! V_27 -> V_23 )
return true ;
return V_27 -> V_23 -> V_59 ;
}
static struct V_60 * F_33 (
const struct V_24 * V_25 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
return & V_27 -> V_31 ;
}
static unsigned int F_34 ( const struct V_24 * V_25 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
return V_27 -> V_46 ;
}
static bool F_35 ( const struct V_24 * V_25 ,
unsigned int V_46 )
{
struct V_26 * V_27 = F_26 ( V_25 ) ;
if ( V_27 -> V_46 == V_46 )
return false ;
if ( V_27 -> V_23 )
V_27 -> V_23 -> V_44 = V_46 ;
V_27 -> V_46 = V_46 ;
return true ;
}
struct V_61 * F_36 ( struct V_24 * V_25 )
{
return F_27 ( V_25 ) -> V_54 [ 0 ] -> V_62 ;
}
static void F_37 ( struct V_17 * V_14 )
{
struct V_8 * V_9 ;
memset ( & V_14 -> V_63 , 0 , sizeof( V_14 -> V_63 ) ) ;
F_15 (w, &card->widgets, list) {
V_9 -> V_64 = V_9 -> V_59 ;
V_9 -> V_65 = false ;
V_9 -> V_66 = - 1 ;
V_9 -> V_67 = - 1 ;
}
}
static int F_38 ( struct V_8 * V_9 , int V_38 )
{
if ( V_9 -> V_62 )
return F_39 ( V_9 -> V_62 , V_38 ) ;
else if ( V_9 -> V_68 )
return F_40 ( V_9 -> V_68 , V_38 ) ;
F_21 ( V_9 -> V_12 -> V_3 , L_5 ) ;
return - 1 ;
}
static int F_41 ( struct V_8 * V_9 , int V_38 , int V_69 )
{
if ( V_9 -> V_62 )
return F_42 ( V_9 -> V_62 , V_38 , V_69 ) ;
else if ( V_9 -> V_68 )
return F_43 ( V_9 -> V_68 , V_38 , V_69 ) ;
F_21 ( V_9 -> V_12 -> V_3 , L_6 ) ;
return - 1 ;
}
static inline void F_44 ( struct V_8 * V_9 )
{
if ( V_9 -> V_62 && ! V_9 -> V_62 -> V_70 )
F_14 ( & V_9 -> V_62 -> V_71 ) ;
else if ( V_9 -> V_68 )
F_14 ( & V_9 -> V_68 -> V_71 ) ;
}
static inline void F_45 ( struct V_8 * V_9 )
{
if ( V_9 -> V_62 && ! V_9 -> V_62 -> V_70 )
F_16 ( & V_9 -> V_62 -> V_71 ) ;
else if ( V_9 -> V_68 )
F_16 ( & V_9 -> V_68 -> V_71 ) ;
}
static int F_46 ( struct V_8 * V_9 ,
unsigned short V_38 , unsigned int V_39 , unsigned int V_46 )
{
bool V_72 ;
unsigned int V_73 , V_74 ;
int V_75 ;
if ( V_9 -> V_62 && V_9 -> V_62 -> V_70 ) {
V_75 = F_47 ( V_9 -> V_62 -> V_76 ,
V_38 , V_39 , V_46 , & V_72 ) ;
if ( V_75 != 0 )
return V_75 ;
} else {
F_44 ( V_9 ) ;
V_75 = F_38 ( V_9 , V_38 ) ;
if ( V_75 < 0 ) {
F_45 ( V_9 ) ;
return V_75 ;
}
V_73 = V_75 ;
V_74 = ( V_73 & ~ V_39 ) | ( V_46 & V_39 ) ;
V_72 = V_73 != V_74 ;
if ( V_72 ) {
V_75 = F_41 ( V_9 , V_38 , V_74 ) ;
if ( V_75 < 0 ) {
F_45 ( V_9 ) ;
return V_75 ;
}
}
F_45 ( V_9 ) ;
}
return V_72 ;
}
static int F_48 ( struct V_16 * V_12 ,
enum V_77 V_78 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
int V_75 = 0 ;
F_49 ( V_14 , V_78 ) ;
if ( V_14 && V_14 -> V_79 )
V_75 = V_14 -> V_79 ( V_14 , V_12 , V_78 ) ;
if ( V_75 != 0 )
goto V_80;
if ( V_12 -> V_62 ) {
if ( V_12 -> V_62 -> V_81 -> V_79 )
V_75 = V_12 -> V_62 -> V_81 -> V_79 ( V_12 -> V_62 ,
V_78 ) ;
else
V_12 -> V_82 = V_78 ;
} else if ( ! V_14 || V_12 != & V_14 -> V_12 ) {
V_12 -> V_82 = V_78 ;
}
if ( V_75 != 0 )
goto V_80;
if ( V_14 && V_14 -> V_83 )
V_75 = V_14 -> V_83 ( V_14 , V_12 , V_78 ) ;
V_80:
F_50 ( V_14 , V_78 ) ;
return V_75 ;
}
static void F_51 ( struct V_8 * V_9 ,
struct V_55 * V_84 , int V_85 )
{
switch ( V_9 -> V_19 ) {
case V_32 :
case V_33 :
case V_34 : {
int V_69 ;
struct V_28 * V_29 = (struct V_28 * )
V_9 -> V_86 [ V_85 ] . V_35 ;
unsigned int V_38 = V_29 -> V_38 ;
unsigned int V_41 = V_29 -> V_41 ;
int V_40 = V_29 -> V_40 ;
unsigned int V_39 = ( 1 << F_23 ( V_40 ) ) - 1 ;
unsigned int V_42 = V_29 -> V_42 ;
V_69 = F_38 ( V_9 , V_38 ) ;
V_69 = ( V_69 >> V_41 ) & V_39 ;
if ( V_42 )
V_69 = V_40 - V_69 ;
V_84 -> V_87 = ! ! V_69 ;
}
break;
case V_88 : {
struct V_89 * V_90 = (struct V_89 * )
V_9 -> V_86 [ V_85 ] . V_35 ;
int V_69 , V_91 ;
V_69 = F_38 ( V_9 , V_90 -> V_38 ) ;
V_91 = ( V_69 >> V_90 -> V_92 ) & V_90 -> V_39 ;
if ( V_91 < V_90 -> V_40 && ! strcmp ( V_84 -> V_13 , V_90 -> V_93 [ V_91 ] ) )
V_84 -> V_87 = 1 ;
else
V_84 -> V_87 = 0 ;
}
break;
case V_94 : {
struct V_89 * V_90 = (struct V_89 * )
V_9 -> V_86 [ V_85 ] . V_35 ;
V_84 -> V_87 = 0 ;
if ( ! strcmp ( V_84 -> V_13 , V_90 -> V_93 [ 0 ] ) )
V_84 -> V_87 = 1 ;
}
break;
case V_95 : {
struct V_89 * V_90 = (struct V_89 * )
V_9 -> V_86 [ V_85 ] . V_35 ;
int V_69 , V_91 ;
V_69 = F_38 ( V_9 , V_90 -> V_38 ) ;
V_69 = ( V_69 >> V_90 -> V_92 ) & V_90 -> V_39 ;
for ( V_91 = 0 ; V_91 < V_90 -> V_40 ; V_91 ++ ) {
if ( V_69 == V_90 -> V_96 [ V_91 ] )
break;
}
if ( V_91 < V_90 -> V_40 && ! strcmp ( V_84 -> V_13 , V_90 -> V_93 [ V_91 ] ) )
V_84 -> V_87 = 1 ;
else
V_84 -> V_87 = 0 ;
}
break;
case V_97 :
case V_98 :
case V_21 :
case V_99 :
case V_20 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_45 :
V_84 -> V_87 = 1 ;
break;
case V_116 :
case V_117 :
V_84 -> V_87 = 0 ;
break;
}
}
static int F_52 ( struct V_16 * V_12 ,
struct V_8 * V_118 , struct V_8 * V_119 ,
struct V_55 * V_56 , const char * V_120 ,
const struct V_121 * V_25 )
{
struct V_89 * V_90 = (struct V_89 * ) V_25 -> V_35 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_90 -> V_40 ; V_85 ++ ) {
if ( ! ( strcmp ( V_120 , V_90 -> V_93 [ V_85 ] ) ) ) {
F_53 ( & V_56 -> V_122 , & V_12 -> V_14 -> V_31 ) ;
F_53 ( & V_56 -> V_123 , & V_119 -> V_124 ) ;
F_53 ( & V_56 -> V_125 , & V_118 -> V_126 ) ;
V_56 -> V_13 = ( char * ) V_90 -> V_93 [ V_85 ] ;
F_51 ( V_119 , V_56 , 0 ) ;
return 0 ;
}
}
return - V_127 ;
}
static int F_54 ( struct V_16 * V_12 ,
struct V_8 * V_118 , struct V_8 * V_119 ,
struct V_55 * V_56 , const char * V_120 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_119 -> V_128 ; V_85 ++ ) {
if ( ! strcmp ( V_120 , V_119 -> V_86 [ V_85 ] . V_13 ) ) {
F_53 ( & V_56 -> V_122 , & V_12 -> V_14 -> V_31 ) ;
F_53 ( & V_56 -> V_123 , & V_119 -> V_124 ) ;
F_53 ( & V_56 -> V_125 , & V_118 -> V_126 ) ;
V_56 -> V_13 = V_119 -> V_86 [ V_85 ] . V_13 ;
F_51 ( V_119 , V_56 , V_85 ) ;
return 0 ;
}
}
return - V_127 ;
}
static int F_55 ( struct V_16 * V_12 ,
struct V_8 * V_129 ,
const struct V_121 * V_130 ,
struct V_24 * * V_25 )
{
struct V_8 * V_9 ;
int V_85 ;
* V_25 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 == V_129 || V_9 -> V_12 != V_129 -> V_12 )
continue;
for ( V_85 = 0 ; V_85 < V_9 -> V_128 ; V_85 ++ ) {
if ( & V_9 -> V_86 [ V_85 ] == V_130 ) {
if ( V_9 -> V_131 )
* V_25 = V_9 -> V_131 [ V_85 ] ;
return 1 ;
}
}
}
return 0 ;
}
static int F_56 ( struct V_8 * V_9 ,
int V_132 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_133 * V_14 = V_12 -> V_14 -> V_133 ;
const char * V_134 ;
T_3 V_135 ;
int V_136 ;
struct V_24 * V_25 ;
bool V_137 , V_138 ;
char * V_139 ;
const char * V_13 ;
int V_75 ;
if ( V_12 -> V_62 )
V_134 = V_12 -> V_62 -> V_140 ;
else
V_134 = NULL ;
if ( V_134 )
V_135 = strlen ( V_134 ) + 1 ;
else
V_135 = 0 ;
V_136 = F_55 ( V_12 , V_9 , & V_9 -> V_86 [ V_132 ] ,
& V_25 ) ;
if ( ! V_25 ) {
if ( V_136 ) {
V_137 = false ;
V_138 = true ;
} else {
switch ( V_9 -> V_19 ) {
case V_32 :
case V_33 :
V_137 = true ;
V_138 = true ;
break;
case V_34 :
V_137 = false ;
V_138 = true ;
break;
case V_88 :
case V_94 :
case V_95 :
V_137 = true ;
V_138 = false ;
break;
default:
return - V_141 ;
}
}
if ( V_137 && V_138 ) {
V_139 = F_57 ( V_7 , L_7 ,
V_9 -> V_13 + V_135 ,
V_9 -> V_86 [ V_132 ] . V_13 ) ;
if ( V_139 == NULL )
return - V_30 ;
V_13 = V_139 ;
} else if ( V_137 ) {
V_139 = NULL ;
V_13 = V_9 -> V_13 + V_135 ;
} else {
V_139 = NULL ;
V_13 = V_9 -> V_86 [ V_132 ] . V_13 ;
}
V_25 = F_58 ( & V_9 -> V_86 [ V_132 ] , NULL , V_13 ,
V_134 ) ;
F_7 ( V_139 ) ;
if ( ! V_25 )
return - V_30 ;
V_25 -> V_142 = F_25 ;
V_75 = F_19 ( V_9 , V_25 ) ;
if ( V_75 ) {
F_59 ( V_25 ) ;
return V_75 ;
}
V_75 = F_60 ( V_14 , V_25 ) ;
if ( V_75 < 0 ) {
F_21 ( V_12 -> V_3 ,
L_8 ,
V_9 -> V_13 , V_13 , V_75 ) ;
return V_75 ;
}
}
V_75 = F_28 ( V_25 , V_9 ) ;
if ( V_75 )
return V_75 ;
V_9 -> V_131 [ V_132 ] = V_25 ;
return 0 ;
}
static int F_61 ( struct V_8 * V_9 )
{
int V_85 , V_75 ;
struct V_55 * V_56 ;
for ( V_85 = 0 ; V_85 < V_9 -> V_128 ; V_85 ++ ) {
F_15 (path, &w->sources, list_sink) {
if ( V_56 -> V_13 != ( char * ) V_9 -> V_86 [ V_85 ] . V_13 )
continue;
if ( V_9 -> V_131 [ V_85 ] ) {
F_30 ( V_9 -> V_131 [ V_85 ] , V_56 ) ;
continue;
}
V_75 = F_56 ( V_9 , V_85 ) ;
if ( V_75 < 0 )
return V_75 ;
F_30 ( V_9 -> V_131 [ V_85 ] , V_56 ) ;
}
}
return 0 ;
}
static int F_62 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_55 * V_56 ;
int V_75 ;
if ( V_9 -> V_128 != 1 ) {
F_21 ( V_12 -> V_3 ,
L_9 ,
V_9 -> V_13 ) ;
return - V_141 ;
}
if ( F_9 ( & V_9 -> V_124 ) ) {
F_21 ( V_12 -> V_3 , L_10 , V_9 -> V_13 ) ;
return - V_141 ;
}
V_75 = F_56 ( V_9 , 0 ) ;
if ( V_75 < 0 )
return V_75 ;
F_15 (path, &w->sources, list_sink)
F_30 ( V_9 -> V_131 [ 0 ] , V_56 ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 )
{
if ( V_9 -> V_128 )
F_21 ( V_9 -> V_12 -> V_3 ,
L_11 , V_9 -> V_13 ) ;
return 0 ;
}
static void F_64 ( struct V_16 * V_12 ,
struct V_60 * V_143 )
{
struct V_55 * V_84 ;
F_15 (p, sink, list_source) {
if ( V_84 -> V_144 ) {
V_84 -> V_144 = 0 ;
F_64 ( V_12 , & V_84 -> V_143 -> V_126 ) ;
}
}
}
static void F_65 ( struct V_16 * V_12 ,
struct V_60 * V_58 )
{
struct V_55 * V_84 ;
F_15 (p, source, list_sink) {
if ( V_84 -> V_144 ) {
V_84 -> V_144 = 0 ;
F_65 ( V_12 , & V_84 -> V_58 -> V_124 ) ;
}
}
}
static int F_66 ( struct V_8 * V_23 )
{
int V_78 = F_67 ( V_23 -> V_12 -> V_14 -> V_133 ) ;
switch ( V_78 ) {
case V_145 :
case V_146 :
if ( V_23 -> V_147 )
F_68 ( V_23 -> V_12 -> V_3 , L_12 ,
V_23 -> V_13 ) ;
return V_23 -> V_147 ;
default:
return 1 ;
}
}
static int F_69 ( struct V_50 * * V_122 ,
struct V_8 * V_9 )
{
struct V_50 * V_49 ;
int V_148 , V_149 , V_85 ;
if ( * V_122 == NULL )
return - V_141 ;
V_49 = * V_122 ;
for ( V_85 = 0 ; V_85 < V_49 -> V_53 ; V_85 ++ ) {
if ( V_49 -> V_54 [ V_85 ] == V_9 )
return 0 ;
}
V_149 = V_49 -> V_53 + 1 ;
V_148 = sizeof( struct V_50 ) +
V_149 * sizeof( struct V_8 * ) ;
* V_122 = F_29 ( V_49 , V_148 , V_7 ) ;
if ( * V_122 == NULL ) {
F_21 ( V_9 -> V_12 -> V_3 , L_13 ,
V_9 -> V_13 ) ;
return - V_30 ;
}
V_49 = * V_122 ;
F_68 ( V_9 -> V_12 -> V_3 , L_14 ,
V_9 -> V_13 , V_49 -> V_53 ) ;
V_49 -> V_54 [ V_49 -> V_53 ] = V_9 ;
V_49 -> V_53 ++ ;
return 1 ;
}
static int F_70 ( struct V_8 * V_23 ,
struct V_50 * * V_122 )
{
struct V_55 * V_56 ;
int V_150 = 0 ;
if ( V_23 -> V_67 >= 0 )
return V_23 -> V_67 ;
F_71 ( V_23 , V_151 ) ;
switch ( V_23 -> V_19 ) {
case V_104 :
case V_105 :
case V_106 :
case V_45 :
return 0 ;
default:
break;
}
switch ( V_23 -> V_19 ) {
case V_99 :
case V_108 :
case V_110 :
if ( V_23 -> V_152 ) {
V_23 -> V_67 = F_66 ( V_23 ) ;
return V_23 -> V_67 ;
}
default:
break;
}
if ( V_23 -> V_153 ) {
if ( V_23 -> V_19 == V_21 && ! V_23 -> V_154 ) {
V_23 -> V_67 = F_66 ( V_23 ) ;
return V_23 -> V_67 ;
}
if ( V_23 -> V_19 == V_111 ||
V_23 -> V_19 == V_113 ||
( V_23 -> V_19 == V_114 &&
! F_9 ( & V_23 -> V_124 ) ) ) {
V_23 -> V_67 = F_66 ( V_23 ) ;
return V_23 -> V_67 ;
}
}
F_15 (path, &widget->sinks, list_source) {
F_71 ( V_23 , V_155 ) ;
if ( V_56 -> V_156 )
continue;
if ( V_56 -> V_157 )
return 1 ;
if ( V_56 -> V_144 )
continue;
F_72 ( V_23 , V_56 ) ;
if ( V_56 -> V_143 && V_56 -> V_87 ) {
V_56 -> V_144 = 1 ;
V_56 -> V_157 = 1 ;
if ( V_122 ) {
int V_158 ;
V_158 = F_69 ( V_122 , V_56 -> V_143 ) ;
if ( V_158 < 0 ) {
F_21 ( V_23 -> V_12 -> V_3 ,
L_15 ,
V_23 -> V_13 ) ;
V_56 -> V_157 = 0 ;
return V_150 ;
}
}
V_150 += F_70 ( V_56 -> V_143 , V_122 ) ;
V_56 -> V_157 = 0 ;
}
}
V_23 -> V_67 = V_150 ;
return V_150 ;
}
static int F_73 ( struct V_8 * V_23 ,
struct V_50 * * V_122 )
{
struct V_55 * V_56 ;
int V_150 = 0 ;
if ( V_23 -> V_66 >= 0 )
return V_23 -> V_66 ;
F_71 ( V_23 , V_151 ) ;
switch ( V_23 -> V_19 ) {
case V_104 :
case V_105 :
case V_106 :
case V_45 :
return 0 ;
default:
break;
}
switch ( V_23 -> V_19 ) {
case V_101 :
case V_107 :
case V_109 :
if ( V_23 -> V_152 ) {
V_23 -> V_66 = F_66 ( V_23 ) ;
return V_23 -> V_66 ;
}
default:
break;
}
if ( V_23 -> V_153 ) {
if ( V_23 -> V_19 == V_20 && ! V_23 -> V_154 ) {
V_23 -> V_66 = F_66 ( V_23 ) ;
return V_23 -> V_66 ;
}
if ( V_23 -> V_19 == V_103 ) {
V_23 -> V_66 = F_66 ( V_23 ) ;
return V_23 -> V_66 ;
}
if ( V_23 -> V_19 == V_112 ||
( V_23 -> V_19 == V_114 &&
! F_9 ( & V_23 -> V_126 ) ) ) {
V_23 -> V_66 = F_66 ( V_23 ) ;
return V_23 -> V_66 ;
}
if ( V_23 -> V_19 == V_100 ) {
V_23 -> V_66 = F_66 ( V_23 ) ;
return V_23 -> V_66 ;
}
}
F_15 (path, &widget->sources, list_sink) {
F_71 ( V_23 , V_155 ) ;
if ( V_56 -> V_156 )
continue;
if ( V_56 -> V_157 )
return 1 ;
if ( V_56 -> V_144 )
continue;
F_74 ( V_23 , V_56 ) ;
if ( V_56 -> V_58 && V_56 -> V_87 ) {
V_56 -> V_144 = 1 ;
V_56 -> V_157 = 1 ;
if ( V_122 ) {
int V_158 ;
V_158 = F_69 ( V_122 , V_56 -> V_58 ) ;
if ( V_158 < 0 ) {
F_21 ( V_23 -> V_12 -> V_3 ,
L_15 ,
V_23 -> V_13 ) ;
V_56 -> V_157 = 0 ;
return V_150 ;
}
}
V_150 += F_73 ( V_56 -> V_58 , V_122 ) ;
V_56 -> V_157 = 0 ;
}
}
V_23 -> V_66 = V_150 ;
return V_150 ;
}
int F_75 ( struct V_159 * V_160 , int V_161 ,
struct V_50 * * V_122 )
{
struct V_17 * V_14 = V_160 -> V_14 ;
int V_31 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
F_37 ( V_14 ) ;
if ( V_161 == V_163 ) {
V_31 = F_70 ( V_160 -> V_164 , V_122 ) ;
F_64 ( & V_14 -> V_12 ,
& V_160 -> V_164 -> V_126 ) ;
} else {
V_31 = F_73 ( V_160 -> V_165 , V_122 ) ;
F_65 ( & V_14 -> V_12 ,
& V_160 -> V_165 -> V_124 ) ;
}
F_77 ( V_31 , V_161 ) ;
F_16 ( & V_14 -> V_18 ) ;
return V_31 ;
}
int F_78 ( struct V_8 * V_9 ,
struct V_24 * V_25 , int V_166 )
{
unsigned int V_69 ;
if ( F_79 ( V_166 ) )
V_69 = V_9 -> V_44 ;
else
V_69 = V_9 -> V_43 ;
F_46 ( V_9 , - ( V_9 -> V_38 + 1 ) ,
V_9 -> V_39 << V_9 -> V_41 , V_69 << V_9 -> V_41 ) ;
return 0 ;
}
int F_80 ( struct V_8 * V_9 ,
struct V_24 * V_25 , int V_166 )
{
int V_75 ;
if ( F_79 ( V_166 ) ) {
if ( V_9 -> V_44 & V_167 ) {
V_75 = F_81 ( V_9 -> V_168 , false ) ;
if ( V_75 != 0 )
F_82 ( V_9 -> V_12 -> V_3 ,
L_16 ,
V_9 -> V_13 , V_75 ) ;
}
return F_83 ( V_9 -> V_168 ) ;
} else {
if ( V_9 -> V_44 & V_167 ) {
V_75 = F_81 ( V_9 -> V_168 , true ) ;
if ( V_75 != 0 )
F_82 ( V_9 -> V_12 -> V_3 ,
L_17 ,
V_9 -> V_13 , V_75 ) ;
}
return F_84 ( V_9 -> V_168 , V_9 -> V_41 ) ;
}
}
int F_85 ( struct V_8 * V_9 ,
struct V_24 * V_25 , int V_166 )
{
if ( ! V_9 -> V_169 )
return - V_170 ;
#ifdef F_86
if ( F_79 ( V_166 ) ) {
return F_87 ( V_9 -> V_169 ) ;
} else {
F_88 ( V_9 -> V_169 ) ;
return 0 ;
}
#endif
return 0 ;
}
static int F_89 ( struct V_8 * V_9 )
{
if ( V_9 -> V_65 )
return V_9 -> V_64 ;
if ( V_9 -> V_171 )
V_9 -> V_64 = 1 ;
else
V_9 -> V_64 = V_9 -> V_172 ( V_9 ) ;
V_9 -> V_65 = true ;
return V_9 -> V_64 ;
}
static int F_90 ( struct V_8 * V_9 )
{
int V_173 , V_80 ;
F_71 ( V_9 , V_174 ) ;
V_173 = F_73 ( V_9 , NULL ) ;
F_65 ( V_9 -> V_12 , & V_9 -> V_124 ) ;
V_80 = F_70 ( V_9 , NULL ) ;
F_64 ( V_9 -> V_12 , & V_9 -> V_126 ) ;
return V_80 != 0 && V_173 != 0 ;
}
static int F_91 ( struct V_8 * V_9 )
{
int V_173 ;
F_71 ( V_9 , V_174 ) ;
if ( V_9 -> V_152 ) {
V_173 = F_73 ( V_9 , NULL ) ;
F_65 ( V_9 -> V_12 , & V_9 -> V_124 ) ;
return V_173 != 0 ;
} else {
return F_90 ( V_9 ) ;
}
}
static int F_92 ( struct V_8 * V_9 )
{
int V_80 ;
F_71 ( V_9 , V_174 ) ;
if ( V_9 -> V_152 ) {
V_80 = F_70 ( V_9 , NULL ) ;
F_64 ( V_9 -> V_12 , & V_9 -> V_126 ) ;
return V_80 != 0 ;
} else {
return F_90 ( V_9 ) ;
}
}
static int F_93 ( struct V_8 * V_9 )
{
struct V_55 * V_56 ;
F_71 ( V_9 , V_174 ) ;
F_15 (path, &w->sinks, list_source) {
F_71 ( V_9 , V_155 ) ;
if ( V_56 -> V_156 )
continue;
if ( V_56 -> V_153 &&
! V_56 -> V_153 ( V_56 -> V_58 , V_56 -> V_143 ) )
continue;
if ( ! V_56 -> V_143 )
continue;
if ( F_89 ( V_56 -> V_143 ) )
return 1 ;
}
return 0 ;
}
static int F_94 ( struct V_8 * V_9 )
{
return 1 ;
}
static int F_95 ( struct V_8 * V_175 ,
struct V_8 * V_176 ,
bool V_177 )
{
int * V_178 ;
if ( V_177 )
V_178 = V_179 ;
else
V_178 = V_180 ;
if ( V_178 [ V_175 -> V_19 ] != V_178 [ V_176 -> V_19 ] )
return V_178 [ V_175 -> V_19 ] - V_178 [ V_176 -> V_19 ] ;
if ( V_175 -> V_181 != V_176 -> V_181 ) {
if ( V_177 )
return V_175 -> V_181 - V_176 -> V_181 ;
else
return V_176 -> V_181 - V_175 -> V_181 ;
}
if ( V_175 -> V_38 != V_176 -> V_38 )
return V_175 -> V_38 - V_176 -> V_38 ;
if ( V_175 -> V_12 != V_176 -> V_12 )
return ( unsigned long ) V_175 -> V_12 - ( unsigned long ) V_176 -> V_12 ;
return 0 ;
}
static void F_96 ( struct V_8 * V_182 ,
struct V_60 * V_122 ,
bool V_177 )
{
struct V_8 * V_9 ;
F_15 (w, list, power_list)
if ( F_95 ( V_182 , V_9 , V_177 ) < 0 ) {
F_12 ( & V_182 -> V_183 , & V_9 -> V_183 ) ;
return;
}
F_12 ( & V_182 -> V_183 , V_122 ) ;
}
static void F_97 ( struct V_17 * V_14 ,
struct V_8 * V_9 , int V_166 )
{
const char * V_184 ;
int V_59 , V_75 ;
switch ( V_166 ) {
case V_185 :
V_184 = L_18 ;
V_59 = 1 ;
break;
case V_186 :
V_184 = L_19 ;
V_59 = 1 ;
break;
case V_187 :
V_184 = L_20 ;
V_59 = 0 ;
break;
case V_188 :
V_184 = L_21 ;
V_59 = 0 ;
break;
case V_189 :
V_184 = L_22 ;
V_59 = 1 ;
break;
case V_190 :
V_184 = L_23 ;
V_59 = 0 ;
break;
default:
F_98 () ;
return;
}
if ( V_9 -> V_64 != V_59 )
return;
if ( V_9 -> V_166 && ( V_9 -> V_191 & V_166 ) ) {
F_4 ( V_9 -> V_12 -> V_3 , V_14 -> V_1 , L_24 ,
V_9 -> V_13 , V_184 ) ;
F_99 ( V_9 , V_166 ) ;
V_75 = V_9 -> V_166 ( V_9 , NULL , V_166 ) ;
F_100 ( V_9 , V_166 ) ;
if ( V_75 < 0 )
F_21 ( V_9 -> V_12 -> V_3 , L_25 ,
V_184 , V_9 -> V_13 , V_75 ) ;
}
}
static void F_101 ( struct V_17 * V_14 ,
struct V_60 * V_192 )
{
struct V_8 * V_9 ;
int V_38 ;
unsigned int V_46 = 0 ;
unsigned int V_39 = 0 ;
V_38 = F_102 ( V_192 , struct V_8 ,
V_183 ) -> V_38 ;
F_15 (w, pending, power_list) {
F_103 ( V_38 != V_9 -> V_38 ) ;
V_9 -> V_59 = V_9 -> V_64 ;
V_39 |= V_9 -> V_39 << V_9 -> V_41 ;
if ( V_9 -> V_59 )
V_46 |= V_9 -> V_44 << V_9 -> V_41 ;
else
V_46 |= V_9 -> V_43 << V_9 -> V_41 ;
F_4 ( V_9 -> V_12 -> V_3 , V_14 -> V_1 ,
L_26 ,
V_9 -> V_13 , V_38 , V_46 , V_39 ) ;
F_97 ( V_14 , V_9 , V_185 ) ;
F_97 ( V_14 , V_9 , V_187 ) ;
}
if ( V_38 >= 0 ) {
V_9 = F_102 ( V_192 , struct V_8 ,
V_183 ) ;
F_4 ( V_9 -> V_12 -> V_3 , V_14 -> V_1 ,
L_27 ,
V_46 , V_39 , V_38 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_46 ( V_9 , V_38 , V_39 , V_46 ) ;
}
F_15 (w, pending, power_list) {
F_97 ( V_14 , V_9 , V_186 ) ;
F_97 ( V_14 , V_9 , V_188 ) ;
}
}
static void F_104 ( struct V_17 * V_14 ,
struct V_60 * V_122 , int V_166 , bool V_177 )
{
struct V_8 * V_9 , * V_52 ;
F_105 ( V_192 ) ;
int V_193 = - 1 ;
int V_194 = - 1 ;
int V_195 = V_196 ;
struct V_16 * V_197 = NULL ;
int V_75 , V_85 ;
int * V_178 ;
if ( V_177 )
V_178 = V_179 ;
else
V_178 = V_180 ;
F_106 (w, n, list, power_list) {
V_75 = 0 ;
if ( V_178 [ V_9 -> V_19 ] != V_193 || V_9 -> V_38 != V_195 ||
V_9 -> V_12 != V_197 || V_9 -> V_181 != V_194 ) {
if ( ! F_9 ( & V_192 ) )
F_101 ( V_14 , & V_192 ) ;
if ( V_197 && V_197 -> V_198 ) {
for ( V_85 = 0 ; V_85 < F_107 ( V_179 ) ; V_85 ++ )
if ( V_178 [ V_85 ] == V_193 )
V_197 -> V_198 ( V_197 ,
V_85 ,
V_194 ) ;
}
F_22 ( & V_192 ) ;
V_193 = - 1 ;
V_194 = V_199 ;
V_195 = V_196 ;
V_197 = NULL ;
}
switch ( V_9 -> V_19 ) {
case V_116 :
if ( ! V_9 -> V_166 )
F_108 ( V_9 , V_52 , V_122 ,
V_183 ) ;
if ( V_166 == V_200 )
V_75 = V_9 -> V_166 ( V_9 ,
NULL , V_185 ) ;
else if ( V_166 == V_201 )
V_75 = V_9 -> V_166 ( V_9 ,
NULL , V_187 ) ;
break;
case V_117 :
if ( ! V_9 -> V_166 )
F_108 ( V_9 , V_52 , V_122 ,
V_183 ) ;
if ( V_166 == V_200 )
V_75 = V_9 -> V_166 ( V_9 ,
NULL , V_186 ) ;
else if ( V_166 == V_201 )
V_75 = V_9 -> V_166 ( V_9 ,
NULL , V_188 ) ;
break;
default:
V_193 = V_178 [ V_9 -> V_19 ] ;
V_194 = V_9 -> V_181 ;
V_195 = V_9 -> V_38 ;
V_197 = V_9 -> V_12 ;
F_109 ( & V_9 -> V_183 , & V_192 ) ;
break;
}
if ( V_75 < 0 )
F_21 ( V_9 -> V_12 -> V_3 ,
L_28 , V_75 ) ;
}
if ( ! F_9 ( & V_192 ) )
F_101 ( V_14 , & V_192 ) ;
if ( V_197 && V_197 -> V_198 ) {
for ( V_85 = 0 ; V_85 < F_107 ( V_179 ) ; V_85 ++ )
if ( V_178 [ V_85 ] == V_193 )
V_197 -> V_198 ( V_197 ,
V_85 , V_194 ) ;
}
}
static void F_110 ( struct V_17 * V_14 )
{
struct V_202 * V_203 = V_14 -> V_203 ;
struct V_50 * V_49 ;
struct V_8 * V_9 = NULL ;
unsigned int V_204 ;
int V_75 ;
if ( ! V_203 || ! F_32 ( V_203 -> V_25 ) )
return;
V_49 = F_27 ( V_203 -> V_25 ) ;
for ( V_204 = 0 ; V_204 < V_49 -> V_53 ; V_204 ++ ) {
V_9 = V_49 -> V_54 [ V_204 ] ;
if ( V_9 -> V_166 && ( V_9 -> V_191 & V_205 ) ) {
V_75 = V_9 -> V_166 ( V_9 , V_203 -> V_25 , V_205 ) ;
if ( V_75 != 0 )
F_21 ( V_9 -> V_12 -> V_3 , L_29 ,
V_9 -> V_13 , V_75 ) ;
}
}
if ( ! V_9 )
return;
V_75 = F_46 ( V_9 , V_203 -> V_38 , V_203 -> V_39 ,
V_203 -> V_69 ) ;
if ( V_75 < 0 )
F_21 ( V_9 -> V_12 -> V_3 , L_30 ,
V_9 -> V_13 , V_75 ) ;
for ( V_204 = 0 ; V_204 < V_49 -> V_53 ; V_204 ++ ) {
V_9 = V_49 -> V_54 [ V_204 ] ;
if ( V_9 -> V_166 && ( V_9 -> V_191 & V_206 ) ) {
V_75 = V_9 -> V_166 ( V_9 , V_203 -> V_25 , V_206 ) ;
if ( V_75 != 0 )
F_21 ( V_9 -> V_12 -> V_3 , L_31 ,
V_9 -> V_13 , V_75 ) ;
}
}
}
static void F_111 ( void * V_27 , T_4 V_207 )
{
struct V_16 * V_208 = V_27 ;
int V_75 ;
if ( V_208 -> V_82 == V_209 &&
V_208 -> V_210 != V_209 ) {
if ( V_208 -> V_3 )
F_112 ( V_208 -> V_3 ) ;
V_75 = F_48 ( V_208 , V_211 ) ;
if ( V_75 != 0 )
F_21 ( V_208 -> V_3 ,
L_32 , V_75 ) ;
}
if ( V_208 -> V_82 != V_208 -> V_210 ) {
V_75 = F_48 ( V_208 , V_212 ) ;
if ( V_75 != 0 )
F_21 ( V_208 -> V_3 ,
L_33 , V_75 ) ;
}
}
static void F_113 ( void * V_27 , T_4 V_207 )
{
struct V_16 * V_208 = V_27 ;
int V_75 ;
if ( V_208 -> V_82 == V_212 &&
( V_208 -> V_210 == V_211 ||
V_208 -> V_210 == V_209 ) ) {
V_75 = F_48 ( V_208 , V_211 ) ;
if ( V_75 != 0 )
F_21 ( V_208 -> V_3 , L_34 ,
V_75 ) ;
}
if ( V_208 -> V_82 == V_211 &&
V_208 -> V_210 == V_209 ) {
V_75 = F_48 ( V_208 , V_209 ) ;
if ( V_75 != 0 )
F_21 ( V_208 -> V_3 , L_35 ,
V_75 ) ;
if ( V_208 -> V_3 )
F_114 ( V_208 -> V_3 ) ;
}
if ( V_208 -> V_82 == V_212 &&
V_208 -> V_210 == V_213 ) {
V_75 = F_48 ( V_208 , V_213 ) ;
if ( V_75 != 0 )
F_21 ( V_208 -> V_3 , L_36 ,
V_75 ) ;
}
}
static void F_115 ( struct V_8 * V_214 ,
bool V_59 , bool V_87 )
{
if ( ! V_87 )
return;
if ( V_59 != V_214 -> V_59 )
F_10 ( V_214 , L_37 ) ;
}
static void F_116 ( struct V_8 * V_9 , bool V_59 ,
struct V_60 * V_215 ,
struct V_60 * V_216 )
{
struct V_55 * V_56 ;
if ( V_9 -> V_59 == V_59 )
return;
F_117 ( V_9 , V_59 ) ;
F_15 (path, &w->sources, list_sink) {
if ( V_56 -> V_58 ) {
F_115 ( V_56 -> V_58 , V_59 ,
V_56 -> V_87 ) ;
}
}
switch ( V_9 -> V_19 ) {
case V_104 :
case V_105 :
case V_106 :
case V_45 :
break;
default:
F_15 (path, &w->sinks, list_source) {
if ( V_56 -> V_143 ) {
F_115 ( V_56 -> V_143 , V_59 ,
V_56 -> V_87 ) ;
}
}
break;
}
if ( V_59 )
F_96 ( V_9 , V_215 , true ) ;
else
F_96 ( V_9 , V_216 , false ) ;
}
static void F_118 ( struct V_8 * V_9 ,
struct V_60 * V_215 ,
struct V_60 * V_216 )
{
int V_59 ;
switch ( V_9 -> V_19 ) {
case V_116 :
F_96 ( V_9 , V_216 , false ) ;
break;
case V_117 :
F_96 ( V_9 , V_215 , true ) ;
break;
default:
V_59 = F_89 ( V_9 ) ;
F_116 ( V_9 , V_59 , V_215 , V_216 ) ;
break;
}
}
static int F_119 ( struct V_17 * V_14 , int V_166 )
{
struct V_8 * V_9 ;
struct V_16 * V_208 ;
F_105 ( V_215 ) ;
F_105 ( V_216 ) ;
F_120 ( V_217 ) ;
enum V_77 V_218 ;
F_121 ( V_14 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_208 -> V_219 )
V_208 -> V_210 = V_209 ;
else
V_208 -> V_210 = V_211 ;
}
F_37 ( V_14 ) ;
F_15 (w, &card->dapm_dirty, dirty) {
F_118 ( V_9 , & V_215 , & V_216 ) ;
}
F_15 (w, &card->widgets, list) {
switch ( V_9 -> V_19 ) {
case V_116 :
case V_117 :
break;
default:
F_122 ( & V_9 -> V_10 ) ;
break;
}
if ( V_9 -> V_64 ) {
V_208 = V_9 -> V_12 ;
switch ( V_9 -> V_19 ) {
case V_100 :
break;
case V_104 :
case V_105 :
case V_106 :
case V_102 :
if ( V_208 -> V_210 < V_211 )
V_208 -> V_210 = V_211 ;
break;
default:
V_208 -> V_210 = V_213 ;
break;
}
}
}
V_218 = V_209 ;
F_15 (d, &card->dapm_list, list)
if ( V_208 -> V_210 > V_218 )
V_218 = V_208 -> V_210 ;
F_15 (d, &card->dapm_list, list)
if ( ! V_208 -> V_219 )
V_208 -> V_210 = V_218 ;
F_123 ( V_14 ) ;
F_15 (d, &card->dapm_list, list)
F_124 ( F_111 , V_208 ,
& V_217 ) ;
F_125 ( & V_217 ) ;
F_15 (w, &down_list, power_list) {
F_97 ( V_14 , V_9 , V_190 ) ;
}
F_15 (w, &up_list, power_list) {
F_97 ( V_14 , V_9 , V_189 ) ;
}
F_104 ( V_14 , & V_216 , V_166 , false ) ;
F_110 ( V_14 ) ;
F_104 ( V_14 , & V_215 , V_166 , true ) ;
F_15 (d, &card->dapm_list, list)
F_124 ( F_113 , V_208 ,
& V_217 ) ;
F_125 ( & V_217 ) ;
F_15 (d, &card->dapm_list, list) {
if ( V_208 -> V_220 )
V_208 -> V_220 ( V_208 , V_166 ) ;
}
F_4 ( V_14 -> V_3 , V_14 -> V_1 ,
L_38 , V_14 -> V_1 ) ;
F_1 ( V_14 -> V_1 ) ;
F_126 ( V_14 ) ;
return 0 ;
}
static T_5 F_127 ( struct V_221 * V_221 ,
char T_6 * V_222 ,
T_3 V_223 , T_7 * V_224 )
{
struct V_8 * V_9 = V_221 -> V_47 ;
char * V_5 ;
int V_173 , V_80 ;
T_5 V_75 ;
struct V_55 * V_84 = NULL ;
V_5 = F_5 ( V_6 , V_7 ) ;
if ( ! V_5 )
return - V_30 ;
V_173 = F_73 ( V_9 , NULL ) ;
F_65 ( V_9 -> V_12 , & V_9 -> V_124 ) ;
V_80 = F_70 ( V_9 , NULL ) ;
F_64 ( V_9 -> V_12 , & V_9 -> V_126 ) ;
V_75 = snprintf ( V_5 , V_6 , L_39 ,
V_9 -> V_13 , V_9 -> V_59 ? L_40 : L_41 ,
V_9 -> V_171 ? L_42 : L_43 , V_173 , V_80 ) ;
if ( V_9 -> V_38 >= 0 )
V_75 += snprintf ( V_5 + V_75 , V_6 - V_75 ,
L_44 ,
V_9 -> V_38 , V_9 -> V_38 , V_9 -> V_39 << V_9 -> V_41 ) ;
V_75 += snprintf ( V_5 + V_75 , V_6 - V_75 , L_45 ) ;
if ( V_9 -> V_225 )
V_75 += snprintf ( V_5 + V_75 , V_6 - V_75 , L_46 ,
V_9 -> V_225 ,
V_9 -> V_152 ? L_47 : L_48 ) ;
F_15 (p, &w->sources, list_sink) {
if ( V_84 -> V_153 && ! V_84 -> V_153 ( V_9 , V_84 -> V_58 ) )
continue;
if ( V_84 -> V_87 )
V_75 += snprintf ( V_5 + V_75 , V_6 - V_75 ,
L_49 ,
V_84 -> V_13 ? V_84 -> V_13 : L_50 ,
V_84 -> V_58 -> V_13 ) ;
}
F_15 (p, &w->sinks, list_source) {
if ( V_84 -> V_153 && ! V_84 -> V_153 ( V_9 , V_84 -> V_143 ) )
continue;
if ( V_84 -> V_87 )
V_75 += snprintf ( V_5 + V_75 , V_6 - V_75 ,
L_51 ,
V_84 -> V_13 ? V_84 -> V_13 : L_50 ,
V_84 -> V_143 -> V_13 ) ;
}
V_75 = F_128 ( V_222 , V_223 , V_224 , V_5 , V_75 ) ;
F_7 ( V_5 ) ;
return V_75 ;
}
static T_5 F_129 ( struct V_221 * V_221 , char T_6 * V_222 ,
T_3 V_223 , T_7 * V_224 )
{
struct V_16 * V_12 = V_221 -> V_47 ;
char * V_78 ;
switch ( V_12 -> V_82 ) {
case V_213 :
V_78 = L_52 ;
break;
case V_212 :
V_78 = L_53 ;
break;
case V_211 :
V_78 = L_54 ;
break;
case V_209 :
V_78 = L_55 ;
break;
default:
F_98 () ;
V_78 = L_56 ;
break;
}
return F_128 ( V_222 , V_223 , V_224 , V_78 ,
strlen ( V_78 ) ) ;
}
void F_130 ( struct V_16 * V_12 ,
struct V_226 * V_227 )
{
struct V_226 * V_208 ;
V_12 -> V_228 = F_131 ( L_57 , V_227 ) ;
if ( ! V_12 -> V_228 ) {
F_82 ( V_12 -> V_3 ,
L_58 ) ;
return;
}
V_208 = F_132 ( L_59 , 0444 ,
V_12 -> V_228 , V_12 ,
& V_229 ) ;
if ( ! V_208 )
F_82 ( V_12 -> V_3 ,
L_60 ) ;
}
static void F_133 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_226 * V_208 ;
if ( ! V_12 -> V_228 || ! V_9 -> V_13 )
return;
V_208 = F_132 ( V_9 -> V_13 , 0444 ,
V_12 -> V_228 , V_9 ,
& V_230 ) ;
if ( ! V_208 )
F_82 ( V_9 -> V_12 -> V_3 ,
L_61 ,
V_9 -> V_13 ) ;
}
static void F_134 ( struct V_16 * V_12 )
{
F_135 ( V_12 -> V_228 ) ;
}
void F_130 ( struct V_16 * V_12 ,
struct V_226 * V_227 )
{
}
static inline void F_133 ( struct V_8 * V_9 )
{
}
static inline void F_134 ( struct V_16 * V_12 )
{
}
static int F_136 ( struct V_17 * V_14 ,
struct V_24 * V_25 , int V_231 , struct V_89 * V_90 )
{
struct V_55 * V_56 ;
int V_232 = 0 ;
F_137 (path, kcontrol) {
if ( ! V_56 -> V_13 || ! V_90 -> V_93 [ V_231 ] )
continue;
V_232 = 1 ;
if ( ! ( strcmp ( V_56 -> V_13 , V_90 -> V_93 [ V_231 ] ) ) ) {
V_56 -> V_87 = 1 ;
F_10 ( V_56 -> V_58 , L_62 ) ;
} else {
if ( V_56 -> V_87 )
F_10 ( V_56 -> V_58 ,
L_63 ) ;
V_56 -> V_87 = 0 ;
}
F_10 ( V_56 -> V_143 , L_64 ) ;
}
if ( V_232 )
F_119 ( V_14 , V_233 ) ;
return V_232 ;
}
int F_138 ( struct V_16 * V_12 ,
struct V_24 * V_25 , int V_231 , struct V_89 * V_90 ,
struct V_202 * V_203 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
int V_75 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
V_14 -> V_203 = V_203 ;
V_75 = F_136 ( V_14 , V_25 , V_231 , V_90 ) ;
V_14 -> V_203 = NULL ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_75 > 0 )
F_139 ( V_14 ) ;
return V_75 ;
}
static int F_140 ( struct V_17 * V_14 ,
struct V_24 * V_25 , int V_87 )
{
struct V_55 * V_56 ;
int V_232 = 0 ;
F_137 (path, kcontrol) {
V_232 = 1 ;
V_56 -> V_87 = V_87 ;
F_10 ( V_56 -> V_58 , L_65 ) ;
F_10 ( V_56 -> V_143 , L_66 ) ;
}
if ( V_232 )
F_119 ( V_14 , V_233 ) ;
return V_232 ;
}
int F_141 ( struct V_16 * V_12 ,
struct V_24 * V_25 , int V_87 ,
struct V_202 * V_203 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
int V_75 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
V_14 -> V_203 = V_203 ;
V_75 = F_140 ( V_14 , V_25 , V_87 ) ;
V_14 -> V_203 = NULL ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_75 > 0 )
F_139 ( V_14 ) ;
return V_75 ;
}
static T_5 F_142 ( struct V_2 * V_3 ,
struct V_234 * V_235 , char * V_5 )
{
struct V_236 * V_237 = F_143 ( V_3 ) ;
struct V_61 * V_62 = V_237 -> V_62 ;
struct V_8 * V_9 ;
int V_223 = 0 ;
char * V_238 = L_67 ;
F_15 (w, &codec->card->widgets, list) {
if ( V_9 -> V_12 != & V_62 -> V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_102 :
case V_101 :
case V_99 :
case V_97 :
case V_98 :
case V_33 :
case V_34 :
case V_104 :
case V_105 :
case V_106 :
if ( V_9 -> V_13 )
V_223 += sprintf ( V_5 + V_223 , L_68 ,
V_9 -> V_13 , V_9 -> V_59 ? L_40 : L_41 ) ;
break;
default:
break;
}
}
switch ( V_62 -> V_12 . V_82 ) {
case V_213 :
V_238 = L_40 ;
break;
case V_212 :
V_238 = L_69 ;
break;
case V_211 :
V_238 = L_70 ;
break;
case V_209 :
V_238 = L_41 ;
break;
}
V_223 += sprintf ( V_5 + V_223 , L_71 , V_238 ) ;
return V_223 ;
}
int F_144 ( struct V_2 * V_3 )
{
return F_145 ( V_3 , & V_239 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
F_147 ( V_3 , & V_239 ) ;
}
static void F_148 ( struct V_55 * V_56 )
{
F_149 ( & V_56 -> V_123 ) ;
F_149 ( & V_56 -> V_125 ) ;
F_149 ( & V_56 -> V_57 ) ;
F_149 ( & V_56 -> V_122 ) ;
F_7 ( V_56 ) ;
}
static void F_150 ( struct V_16 * V_12 )
{
struct V_8 * V_9 , * V_240 ;
struct V_55 * V_84 , * V_241 ;
F_106 (w, next_w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
F_149 ( & V_9 -> V_122 ) ;
F_106 (p, next_p, &w->sources, list_sink)
F_148 ( V_84 ) ;
F_106 (p, next_p, &w->sinks, list_source)
F_148 ( V_84 ) ;
F_7 ( V_9 -> V_131 ) ;
F_7 ( V_9 -> V_13 ) ;
F_7 ( V_9 ) ;
}
}
static struct V_8 * F_151 (
struct V_16 * V_12 , const char * V_242 ,
bool V_243 )
{
struct V_8 * V_9 ;
struct V_8 * V_244 = NULL ;
F_15 (w, &dapm->card->widgets, list) {
if ( ! strcmp ( V_9 -> V_13 , V_242 ) ) {
if ( V_9 -> V_12 == V_12 )
return V_9 ;
else
V_244 = V_9 ;
}
}
if ( V_243 )
return V_244 ;
return NULL ;
}
static int F_152 ( struct V_16 * V_12 ,
const char * V_242 , int V_245 )
{
struct V_8 * V_9 = F_151 ( V_12 , V_242 , true ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_72 , V_242 ) ;
return - V_141 ;
}
if ( V_9 -> V_153 != V_245 )
F_10 ( V_9 , L_73 ) ;
V_9 -> V_153 = V_245 ;
if ( V_245 == 0 )
V_9 -> V_171 = 0 ;
return 0 ;
}
int F_153 ( struct V_16 * V_12 )
{
int V_75 ;
if ( ! V_12 -> V_14 || ! V_12 -> V_14 -> V_246 )
return 0 ;
F_76 ( & V_12 -> V_14 -> V_18 , V_162 ) ;
V_75 = F_119 ( V_12 -> V_14 , V_233 ) ;
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_75 ;
}
static int F_31 ( struct V_16 * V_12 ,
struct V_8 * V_247 , struct V_8 * V_248 ,
const char * V_249 ,
int (* V_153)( struct V_8 * V_58 ,
struct V_8 * V_143 ) )
{
struct V_55 * V_56 ;
int V_75 ;
V_56 = F_20 ( sizeof( struct V_55 ) , V_7 ) ;
if ( ! V_56 )
return - V_30 ;
V_56 -> V_58 = V_247 ;
V_56 -> V_143 = V_248 ;
V_56 -> V_153 = V_153 ;
F_22 ( & V_56 -> V_122 ) ;
F_22 ( & V_56 -> V_57 ) ;
F_22 ( & V_56 -> V_125 ) ;
F_22 ( & V_56 -> V_123 ) ;
if ( V_248 -> V_19 == V_20 ) {
if ( V_247 -> V_19 == V_102 ||
V_247 -> V_19 == V_112 ||
V_247 -> V_19 == V_114 ||
V_247 -> V_19 == V_21 )
V_248 -> V_154 = 1 ;
}
if ( V_247 -> V_19 == V_21 ) {
if ( V_248 -> V_19 == V_113 ||
V_248 -> V_19 == V_111 ||
V_248 -> V_19 == V_114 ||
V_248 -> V_19 == V_20 )
V_247 -> V_154 = 1 ;
}
F_10 ( V_247 , L_74 ) ;
F_10 ( V_248 , L_74 ) ;
if ( V_249 == NULL ) {
F_53 ( & V_56 -> V_122 , & V_12 -> V_14 -> V_31 ) ;
F_53 ( & V_56 -> V_123 , & V_248 -> V_124 ) ;
F_53 ( & V_56 -> V_125 , & V_247 -> V_126 ) ;
V_56 -> V_87 = 1 ;
return 0 ;
}
switch ( V_248 -> V_19 ) {
case V_99 :
case V_101 :
case V_97 :
case V_98 :
case V_20 :
case V_21 :
case V_100 :
case V_102 :
case V_103 :
case V_116 :
case V_117 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_115 :
case V_45 :
F_53 ( & V_56 -> V_122 , & V_12 -> V_14 -> V_31 ) ;
F_53 ( & V_56 -> V_123 , & V_248 -> V_124 ) ;
F_53 ( & V_56 -> V_125 , & V_247 -> V_126 ) ;
V_56 -> V_87 = 1 ;
return 0 ;
case V_88 :
case V_94 :
case V_95 :
V_75 = F_52 ( V_12 , V_247 , V_248 , V_56 , V_249 ,
& V_248 -> V_86 [ 0 ] ) ;
if ( V_75 != 0 )
goto V_158;
break;
case V_32 :
case V_33 :
case V_34 :
V_75 = F_54 ( V_12 , V_247 , V_248 , V_56 , V_249 ) ;
if ( V_75 != 0 )
goto V_158;
break;
case V_111 :
case V_112 :
case V_114 :
case V_113 :
F_53 ( & V_56 -> V_122 , & V_12 -> V_14 -> V_31 ) ;
F_53 ( & V_56 -> V_123 , & V_248 -> V_124 ) ;
F_53 ( & V_56 -> V_125 , & V_247 -> V_126 ) ;
V_56 -> V_87 = 0 ;
return 0 ;
}
return 0 ;
V_158:
F_7 ( V_56 ) ;
return V_75 ;
}
static int F_154 ( struct V_16 * V_12 ,
const struct V_250 * V_251 )
{
struct V_8 * V_247 = NULL , * V_248 = NULL , * V_9 ;
struct V_8 * V_252 = NULL , * V_253 = NULL ;
const char * V_143 ;
const char * V_58 ;
char V_254 [ 80 ] ;
char V_255 [ 80 ] ;
int V_75 ;
if ( V_12 -> V_62 && V_12 -> V_62 -> V_140 ) {
snprintf ( V_254 , sizeof( V_254 ) , L_7 ,
V_12 -> V_62 -> V_140 , V_251 -> V_143 ) ;
V_143 = V_254 ;
snprintf ( V_255 , sizeof( V_255 ) , L_7 ,
V_12 -> V_62 -> V_140 , V_251 -> V_58 ) ;
V_58 = V_255 ;
} else {
V_143 = V_251 -> V_143 ;
V_58 = V_251 -> V_58 ;
}
F_15 (w, &dapm->card->widgets, list) {
if ( ! V_248 && ! ( strcmp ( V_9 -> V_13 , V_143 ) ) ) {
V_253 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_248 = V_9 ;
continue;
}
if ( ! V_247 && ! ( strcmp ( V_9 -> V_13 , V_58 ) ) ) {
V_252 = V_9 ;
if ( V_9 -> V_12 == V_12 )
V_247 = V_9 ;
}
}
if ( ! V_248 )
V_248 = V_253 ;
if ( ! V_247 )
V_247 = V_252 ;
if ( V_247 == NULL ) {
F_21 ( V_12 -> V_3 , L_75 ,
V_251 -> V_58 ) ;
return - V_127 ;
}
if ( V_248 == NULL ) {
F_21 ( V_12 -> V_3 , L_76 ,
V_251 -> V_143 ) ;
return - V_127 ;
}
V_75 = F_31 ( V_12 , V_247 , V_248 , V_251 -> V_249 ,
V_251 -> V_153 ) ;
if ( V_75 )
goto V_158;
return 0 ;
V_158:
F_82 ( V_12 -> V_3 , L_77 ,
V_58 , V_251 -> V_249 , V_143 ) ;
return V_75 ;
}
static int F_155 ( struct V_16 * V_12 ,
const struct V_250 * V_251 )
{
struct V_55 * V_56 , * V_84 ;
const char * V_143 ;
const char * V_58 ;
char V_254 [ 80 ] ;
char V_255 [ 80 ] ;
if ( V_251 -> V_249 ) {
F_21 ( V_12 -> V_3 ,
L_78 ) ;
return - V_141 ;
}
if ( V_12 -> V_62 && V_12 -> V_62 -> V_140 ) {
snprintf ( V_254 , sizeof( V_254 ) , L_7 ,
V_12 -> V_62 -> V_140 , V_251 -> V_143 ) ;
V_143 = V_254 ;
snprintf ( V_255 , sizeof( V_255 ) , L_7 ,
V_12 -> V_62 -> V_140 , V_251 -> V_58 ) ;
V_58 = V_255 ;
} else {
V_143 = V_251 -> V_143 ;
V_58 = V_251 -> V_58 ;
}
V_56 = NULL ;
F_15 (p, &dapm->card->paths, list) {
if ( strcmp ( V_84 -> V_58 -> V_13 , V_58 ) != 0 )
continue;
if ( strcmp ( V_84 -> V_143 -> V_13 , V_143 ) != 0 )
continue;
V_56 = V_84 ;
break;
}
if ( V_56 ) {
F_10 ( V_56 -> V_58 , L_79 ) ;
F_10 ( V_56 -> V_143 , L_79 ) ;
F_148 ( V_56 ) ;
} else {
F_82 ( V_12 -> V_3 , L_80 ,
V_58 , V_143 ) ;
}
return 0 ;
}
int F_156 ( struct V_16 * V_12 ,
const struct V_250 * V_251 , int V_256 )
{
int V_85 , V_257 , V_75 = 0 ;
F_76 ( & V_12 -> V_14 -> V_18 , V_258 ) ;
for ( V_85 = 0 ; V_85 < V_256 ; V_85 ++ ) {
V_257 = F_154 ( V_12 , V_251 ) ;
if ( V_257 < 0 ) {
F_21 ( V_12 -> V_3 , L_81 ,
V_251 -> V_58 ,
V_251 -> V_249 ? V_251 -> V_249 : L_82 ,
V_251 -> V_143 ) ;
V_75 = V_257 ;
}
V_251 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_75 ;
}
int F_157 ( struct V_16 * V_12 ,
const struct V_250 * V_251 , int V_256 )
{
int V_85 , V_75 = 0 ;
F_76 ( & V_12 -> V_14 -> V_18 , V_258 ) ;
for ( V_85 = 0 ; V_85 < V_256 ; V_85 ++ ) {
F_155 ( V_12 , V_251 ) ;
V_251 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_75 ;
}
static int F_158 ( struct V_16 * V_12 ,
const struct V_250 * V_251 )
{
struct V_8 * V_58 = F_151 ( V_12 ,
V_251 -> V_58 ,
true ) ;
struct V_8 * V_143 = F_151 ( V_12 ,
V_251 -> V_143 ,
true ) ;
struct V_55 * V_56 ;
int V_223 = 0 ;
if ( ! V_58 ) {
F_21 ( V_12 -> V_3 , L_83 ,
V_251 -> V_58 ) ;
return - V_127 ;
}
if ( ! V_143 ) {
F_21 ( V_12 -> V_3 , L_84 ,
V_251 -> V_143 ) ;
return - V_127 ;
}
if ( V_251 -> V_249 || V_251 -> V_153 )
F_82 ( V_12 -> V_3 , L_85 ,
V_251 -> V_58 , V_251 -> V_143 ) ;
F_15 (path, &source->sinks, list_source) {
if ( V_56 -> V_143 == V_143 ) {
V_56 -> V_156 = 1 ;
V_223 ++ ;
}
}
if ( V_223 == 0 )
F_21 ( V_12 -> V_3 , L_86 ,
V_251 -> V_58 , V_251 -> V_143 ) ;
if ( V_223 > 1 )
F_82 ( V_12 -> V_3 , L_87 ,
V_223 , V_251 -> V_58 , V_251 -> V_143 ) ;
return 0 ;
}
int F_159 ( struct V_16 * V_12 ,
const struct V_250 * V_251 , int V_256 )
{
int V_85 , V_158 ;
int V_75 = 0 ;
F_76 ( & V_12 -> V_14 -> V_18 , V_258 ) ;
for ( V_85 = 0 ; V_85 < V_256 ; V_85 ++ ) {
V_158 = F_158 ( V_12 , V_251 ) ;
if ( V_158 )
V_75 = V_158 ;
V_251 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_75 ;
}
int F_160 ( struct V_17 * V_14 )
{
struct V_8 * V_9 ;
unsigned int V_69 ;
F_76 ( & V_14 -> V_18 , V_258 ) ;
F_15 (w, &card->widgets, list)
{
if ( V_9 -> V_74 )
continue;
if ( V_9 -> V_128 ) {
V_9 -> V_131 = F_20 ( V_9 -> V_128 *
sizeof( struct V_24 * ) ,
V_7 ) ;
if ( ! V_9 -> V_131 ) {
F_16 ( & V_14 -> V_18 ) ;
return - V_30 ;
}
}
switch( V_9 -> V_19 ) {
case V_32 :
case V_33 :
case V_34 :
F_61 ( V_9 ) ;
break;
case V_88 :
case V_94 :
case V_95 :
F_62 ( V_9 ) ;
break;
case V_97 :
case V_98 :
F_63 ( V_9 ) ;
break;
default:
break;
}
if ( V_9 -> V_38 >= 0 ) {
V_69 = F_38 ( V_9 , V_9 -> V_38 ) >> V_9 -> V_41 ;
V_69 &= V_9 -> V_39 ;
if ( V_69 == V_9 -> V_44 )
V_9 -> V_59 = 1 ;
}
V_9 -> V_74 = 1 ;
F_10 ( V_9 , L_88 ) ;
F_133 ( V_9 ) ;
}
F_119 ( V_14 , V_233 ) ;
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_161 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_17 * V_14 = V_62 -> V_14 ;
struct V_28 * V_29 =
(struct V_28 * ) V_25 -> V_35 ;
unsigned int V_38 = V_29 -> V_38 ;
unsigned int V_41 = V_29 -> V_41 ;
int V_40 = V_29 -> V_40 ;
unsigned int V_39 = ( 1 << F_23 ( V_40 ) ) - 1 ;
unsigned int V_42 = V_29 -> V_42 ;
unsigned int V_69 ;
if ( F_162 ( V_29 ) )
F_82 ( V_62 -> V_12 . V_3 ,
L_89 ,
V_25 -> V_19 . V_13 ) ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
if ( F_32 ( V_25 ) )
V_69 = ( F_39 ( V_62 , V_38 ) >> V_41 ) & V_39 ;
else
V_69 = F_34 ( V_25 ) ;
F_16 ( & V_14 -> V_18 ) ;
if ( V_42 )
V_260 -> V_46 . integer . V_46 [ 0 ] = V_40 - V_69 ;
else
V_260 -> V_46 . integer . V_46 [ 0 ] = V_69 ;
return 0 ;
}
int F_163 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_17 * V_14 = V_62 -> V_14 ;
struct V_28 * V_29 =
(struct V_28 * ) V_25 -> V_35 ;
unsigned int V_38 = V_29 -> V_38 ;
unsigned int V_41 = V_29 -> V_41 ;
int V_40 = V_29 -> V_40 ;
unsigned int V_39 = ( 1 << F_23 ( V_40 ) ) - 1 ;
unsigned int V_42 = V_29 -> V_42 ;
unsigned int V_69 ;
int V_87 , V_72 ;
struct V_202 V_203 ;
if ( F_162 ( V_29 ) )
F_82 ( V_62 -> V_12 . V_3 ,
L_89 ,
V_25 -> V_19 . V_13 ) ;
V_69 = ( V_260 -> V_46 . integer . V_46 [ 0 ] & V_39 ) ;
V_87 = ! ! V_69 ;
if ( V_42 )
V_69 = V_40 - V_69 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
F_35 ( V_25 , V_69 ) ;
V_39 = V_39 << V_41 ;
V_69 = V_69 << V_41 ;
V_72 = F_164 ( V_62 , V_38 , V_39 , V_69 ) ;
if ( V_72 ) {
V_203 . V_25 = V_25 ;
V_203 . V_38 = V_38 ;
V_203 . V_39 = V_39 ;
V_203 . V_69 = V_69 ;
V_14 -> V_203 = & V_203 ;
F_140 ( V_14 , V_25 , V_87 ) ;
V_14 -> V_203 = NULL ;
}
F_16 ( & V_14 -> V_18 ) ;
return V_72 ;
}
int F_165 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_89 * V_90 = (struct V_89 * ) V_25 -> V_35 ;
unsigned int V_69 ;
V_69 = F_39 ( V_62 , V_90 -> V_38 ) ;
V_260 -> V_46 . V_261 . V_91 [ 0 ] = ( V_69 >> V_90 -> V_92 ) & V_90 -> V_39 ;
if ( V_90 -> V_92 != V_90 -> V_262 )
V_260 -> V_46 . V_261 . V_91 [ 1 ] =
( V_69 >> V_90 -> V_262 ) & V_90 -> V_39 ;
return 0 ;
}
int F_166 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_17 * V_14 = V_62 -> V_14 ;
struct V_89 * V_90 = (struct V_89 * ) V_25 -> V_35 ;
unsigned int V_69 , V_231 , V_72 ;
unsigned int V_39 ;
struct V_202 V_203 ;
if ( V_260 -> V_46 . V_261 . V_91 [ 0 ] > V_90 -> V_40 - 1 )
return - V_141 ;
V_231 = V_260 -> V_46 . V_261 . V_91 [ 0 ] ;
V_69 = V_231 << V_90 -> V_92 ;
V_39 = V_90 -> V_39 << V_90 -> V_92 ;
if ( V_90 -> V_92 != V_90 -> V_262 ) {
if ( V_260 -> V_46 . V_261 . V_91 [ 1 ] > V_90 -> V_40 - 1 )
return - V_141 ;
V_69 |= V_260 -> V_46 . V_261 . V_91 [ 1 ] << V_90 -> V_262 ;
V_39 |= V_90 -> V_39 << V_90 -> V_262 ;
}
F_76 ( & V_14 -> V_18 , V_162 ) ;
V_72 = F_164 ( V_62 , V_90 -> V_38 , V_39 , V_69 ) ;
if ( V_72 ) {
V_203 . V_25 = V_25 ;
V_203 . V_38 = V_90 -> V_38 ;
V_203 . V_39 = V_39 ;
V_203 . V_69 = V_69 ;
V_14 -> V_203 = & V_203 ;
F_136 ( V_14 , V_25 , V_231 , V_90 ) ;
V_14 -> V_203 = NULL ;
}
F_16 ( & V_14 -> V_18 ) ;
return V_72 ;
}
int F_167 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
V_260 -> V_46 . V_261 . V_91 [ 0 ] = F_34 ( V_25 ) ;
return 0 ;
}
int F_168 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_17 * V_14 = V_62 -> V_14 ;
unsigned int V_46 ;
struct V_89 * V_90 =
(struct V_89 * ) V_25 -> V_35 ;
int V_72 ;
if ( V_260 -> V_46 . V_261 . V_91 [ 0 ] >= V_90 -> V_40 )
return - V_141 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
V_46 = V_260 -> V_46 . V_261 . V_91 [ 0 ] ;
V_72 = F_35 ( V_25 , V_46 ) ;
if ( V_72 )
F_136 ( V_14 , V_25 , V_46 , V_90 ) ;
F_16 ( & V_14 -> V_18 ) ;
return V_72 ;
}
int F_169 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_89 * V_90 = (struct V_89 * ) V_25 -> V_35 ;
unsigned int V_263 , V_69 , V_231 ;
V_263 = F_39 ( V_62 , V_90 -> V_38 ) ;
V_69 = ( V_263 >> V_90 -> V_92 ) & V_90 -> V_39 ;
for ( V_231 = 0 ; V_231 < V_90 -> V_40 ; V_231 ++ ) {
if ( V_69 == V_90 -> V_96 [ V_231 ] )
break;
}
V_260 -> V_46 . V_261 . V_91 [ 0 ] = V_231 ;
if ( V_90 -> V_92 != V_90 -> V_262 ) {
V_69 = ( V_263 >> V_90 -> V_262 ) & V_90 -> V_39 ;
for ( V_231 = 0 ; V_231 < V_90 -> V_40 ; V_231 ++ ) {
if ( V_69 == V_90 -> V_96 [ V_231 ] )
break;
}
V_260 -> V_46 . V_261 . V_91 [ 1 ] = V_231 ;
}
return 0 ;
}
int F_170 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_61 * V_62 = F_36 ( V_25 ) ;
struct V_17 * V_14 = V_62 -> V_14 ;
struct V_89 * V_90 = (struct V_89 * ) V_25 -> V_35 ;
unsigned int V_69 , V_231 , V_72 ;
unsigned int V_39 ;
struct V_202 V_203 ;
if ( V_260 -> V_46 . V_261 . V_91 [ 0 ] > V_90 -> V_40 - 1 )
return - V_141 ;
V_231 = V_260 -> V_46 . V_261 . V_91 [ 0 ] ;
V_69 = V_90 -> V_96 [ V_260 -> V_46 . V_261 . V_91 [ 0 ] ] << V_90 -> V_92 ;
V_39 = V_90 -> V_39 << V_90 -> V_92 ;
if ( V_90 -> V_92 != V_90 -> V_262 ) {
if ( V_260 -> V_46 . V_261 . V_91 [ 1 ] > V_90 -> V_40 - 1 )
return - V_141 ;
V_69 |= V_90 -> V_96 [ V_260 -> V_46 . V_261 . V_91 [ 1 ] ] << V_90 -> V_262 ;
V_39 |= V_90 -> V_39 << V_90 -> V_262 ;
}
F_76 ( & V_14 -> V_18 , V_162 ) ;
V_72 = F_164 ( V_62 , V_90 -> V_38 , V_39 , V_69 ) ;
if ( V_72 ) {
V_203 . V_25 = V_25 ;
V_203 . V_38 = V_90 -> V_38 ;
V_203 . V_39 = V_39 ;
V_203 . V_69 = V_69 ;
V_14 -> V_203 = & V_203 ;
F_136 ( V_14 , V_25 , V_231 , V_90 ) ;
V_14 -> V_203 = NULL ;
}
F_16 ( & V_14 -> V_18 ) ;
return V_72 ;
}
int F_171 ( struct V_24 * V_25 ,
struct V_264 * V_265 )
{
V_265 -> type = V_266 ;
V_265 -> V_223 = 1 ;
V_265 -> V_46 . integer . V_267 = 0 ;
V_265 -> V_46 . integer . V_40 = 1 ;
return 0 ;
}
int F_172 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_17 * V_14 = F_26 ( V_25 ) ;
const char * V_242 = ( const char * ) V_25 -> V_35 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
V_260 -> V_46 . integer . V_46 [ 0 ] =
F_173 ( & V_14 -> V_12 , V_242 ) ;
F_16 ( & V_14 -> V_18 ) ;
return 0 ;
}
int F_174 ( struct V_24 * V_25 ,
struct V_259 * V_260 )
{
struct V_17 * V_14 = F_26 ( V_25 ) ;
const char * V_242 = ( const char * ) V_25 -> V_35 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
if ( V_260 -> V_46 . integer . V_46 [ 0 ] )
F_175 ( & V_14 -> V_12 , V_242 ) ;
else
F_176 ( & V_14 -> V_12 , V_242 ) ;
F_16 ( & V_14 -> V_18 ) ;
F_153 ( & V_14 -> V_12 ) ;
return 0 ;
}
static struct V_8 *
F_24 ( struct V_16 * V_12 ,
const struct V_8 * V_23 )
{
struct V_8 * V_9 ;
int V_75 ;
if ( ( V_9 = F_17 ( V_23 ) ) == NULL )
return NULL ;
switch ( V_9 -> V_19 ) {
case V_105 :
V_9 -> V_168 = F_177 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_178 ( V_9 -> V_168 ) ) {
V_75 = F_179 ( V_9 -> V_168 ) ;
F_21 ( V_12 -> V_3 , L_90 ,
V_9 -> V_13 , V_75 ) ;
return NULL ;
}
if ( V_9 -> V_44 & V_167 ) {
V_75 = F_81 ( V_9 -> V_168 , true ) ;
if ( V_75 != 0 )
F_82 ( V_9 -> V_12 -> V_3 ,
L_17 ,
V_9 -> V_13 , V_75 ) ;
}
break;
case V_106 :
#ifdef F_180
V_9 -> V_169 = F_181 ( V_12 -> V_3 , V_9 -> V_13 ) ;
if ( F_178 ( V_9 -> V_169 ) ) {
V_75 = F_179 ( V_9 -> V_169 ) ;
F_21 ( V_12 -> V_3 , L_90 ,
V_9 -> V_13 , V_75 ) ;
return NULL ;
}
#else
return NULL ;
#endif
break;
default:
break;
}
if ( V_12 -> V_62 && V_12 -> V_62 -> V_140 )
V_9 -> V_13 = F_57 ( V_7 , L_7 ,
V_12 -> V_62 -> V_140 , V_23 -> V_13 ) ;
else
V_9 -> V_13 = F_57 ( V_7 , L_1 , V_23 -> V_13 ) ;
if ( V_9 -> V_13 == NULL ) {
F_7 ( V_9 ) ;
return NULL ;
}
switch ( V_9 -> V_19 ) {
case V_32 :
case V_33 :
case V_34 :
V_9 -> V_172 = F_90 ;
break;
case V_88 :
case V_94 :
case V_95 :
V_9 -> V_172 = F_90 ;
break;
case V_110 :
V_9 -> V_172 = F_91 ;
break;
case V_109 :
V_9 -> V_172 = F_92 ;
break;
case V_99 :
case V_108 :
case V_101 :
case V_107 :
case V_97 :
case V_98 :
case V_20 :
case V_21 :
case V_102 :
case V_113 :
case V_111 :
case V_112 :
case V_114 :
case V_115 :
V_9 -> V_172 = F_90 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_45 :
V_9 -> V_172 = F_93 ;
break;
default:
V_9 -> V_172 = F_94 ;
break;
}
V_9 -> V_12 = V_12 ;
V_9 -> V_62 = V_12 -> V_62 ;
V_9 -> V_68 = V_12 -> V_68 ;
F_22 ( & V_9 -> V_124 ) ;
F_22 ( & V_9 -> V_126 ) ;
F_22 ( & V_9 -> V_122 ) ;
F_22 ( & V_9 -> V_10 ) ;
F_53 ( & V_9 -> V_122 , & V_12 -> V_14 -> V_54 ) ;
V_9 -> V_153 = 1 ;
return V_9 ;
}
int F_182 ( struct V_16 * V_12 ,
const struct V_8 * V_23 ,
int V_256 )
{
struct V_8 * V_9 ;
int V_85 ;
int V_75 = 0 ;
F_76 ( & V_12 -> V_14 -> V_18 , V_258 ) ;
for ( V_85 = 0 ; V_85 < V_256 ; V_85 ++ ) {
V_9 = F_24 ( V_12 , V_23 ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 ,
L_91 ,
V_23 -> V_13 ) ;
V_75 = - V_30 ;
break;
}
V_23 ++ ;
}
F_16 ( & V_12 -> V_14 -> V_18 ) ;
return V_75 ;
}
static int F_183 ( struct V_8 * V_9 ,
struct V_24 * V_25 , int V_166 )
{
struct V_55 * V_268 , * V_269 ;
struct V_159 * V_58 , * V_143 ;
const struct V_270 * V_271 = V_9 -> V_272 ;
struct V_273 V_274 ;
struct V_275 * V_272 = NULL ;
T_8 V_4 ;
int V_75 ;
F_103 ( ! V_271 ) ;
F_103 ( F_9 ( & V_9 -> V_124 ) || F_9 ( & V_9 -> V_126 ) ) ;
V_268 = F_102 ( & V_9 -> V_124 , struct V_55 ,
V_123 ) ;
V_269 = F_102 ( & V_9 -> V_126 , struct V_55 ,
V_125 ) ;
F_103 ( ! V_268 || ! V_269 ) ;
F_103 ( ! V_269 -> V_58 || ! V_268 -> V_143 ) ;
F_103 ( ! V_268 -> V_58 || ! V_269 -> V_143 ) ;
V_58 = V_268 -> V_58 -> V_276 ;
V_143 = V_269 -> V_143 -> V_276 ;
if ( V_271 -> V_277 ) {
V_4 = F_184 ( V_271 -> V_277 ) - 1 ;
} else {
F_82 ( V_9 -> V_12 -> V_3 , L_92 ,
V_271 -> V_277 ) ;
V_4 = 0 ;
}
V_272 = F_20 ( sizeof( * V_272 ) , V_7 ) ;
if ( ! V_272 ) {
V_75 = - V_30 ;
goto V_80;
}
F_185 ( F_186 ( V_272 , V_278 ) , V_4 ) ;
F_187 ( V_272 , V_279 ) -> V_267 =
V_271 -> V_280 ;
F_187 ( V_272 , V_279 ) -> V_40 =
V_271 -> V_281 ;
F_187 ( V_272 , V_282 ) -> V_267
= V_271 -> V_283 ;
F_187 ( V_272 , V_282 ) -> V_40
= V_271 -> V_284 ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
switch ( V_166 ) {
case V_185 :
if ( V_58 -> V_81 -> V_285 && V_58 -> V_81 -> V_285 -> V_286 ) {
V_274 . V_161 = V_287 ;
V_75 = V_58 -> V_81 -> V_285 -> V_286 ( & V_274 ,
V_272 , V_58 ) ;
if ( V_75 != 0 ) {
F_21 ( V_58 -> V_3 ,
L_93 , V_75 ) ;
goto V_80;
}
}
if ( V_143 -> V_81 -> V_285 && V_143 -> V_81 -> V_285 -> V_286 ) {
V_274 . V_161 = V_163 ;
V_75 = V_143 -> V_81 -> V_285 -> V_286 ( & V_274 , V_272 ,
V_143 ) ;
if ( V_75 != 0 ) {
F_21 ( V_143 -> V_3 ,
L_93 , V_75 ) ;
goto V_80;
}
}
break;
case V_186 :
V_75 = F_188 ( V_143 , 0 ,
V_163 ) ;
if ( V_75 != 0 && V_75 != - V_288 )
F_82 ( V_143 -> V_3 , L_94 , V_75 ) ;
V_75 = 0 ;
break;
case V_187 :
V_75 = F_188 ( V_143 , 1 ,
V_163 ) ;
if ( V_75 != 0 && V_75 != - V_288 )
F_82 ( V_143 -> V_3 , L_95 , V_75 ) ;
V_75 = 0 ;
break;
default:
F_98 () ;
return - V_141 ;
}
V_80:
F_7 ( V_272 ) ;
return V_75 ;
}
int F_189 ( struct V_17 * V_14 ,
const struct V_270 * V_272 ,
struct V_8 * V_58 ,
struct V_8 * V_143 )
{
struct V_250 V_289 [ 2 ] ;
struct V_8 V_37 ;
struct V_8 * V_9 ;
T_3 V_290 ;
char * V_291 ;
V_290 = strlen ( V_58 -> V_13 ) + strlen ( V_143 -> V_13 ) + 2 ;
V_291 = F_190 ( V_14 -> V_3 , V_290 , V_7 ) ;
if ( ! V_291 )
return - V_30 ;
snprintf ( V_291 , V_290 , L_96 , V_58 -> V_13 , V_143 -> V_13 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_38 = V_196 ;
V_37 . V_19 = V_115 ;
V_37 . V_13 = V_291 ;
V_37 . V_166 = F_183 ;
V_37 . V_191 = V_185 | V_186 |
V_187 ;
F_68 ( V_14 -> V_3 , L_97 , V_291 ) ;
V_9 = F_24 ( & V_14 -> V_12 , & V_37 ) ;
if ( ! V_9 ) {
F_21 ( V_14 -> V_3 , L_98 ,
V_291 ) ;
return - V_30 ;
}
V_9 -> V_272 = V_272 ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
V_289 [ 0 ] . V_58 = V_58 -> V_13 ;
V_289 [ 0 ] . V_143 = V_291 ;
V_289 [ 1 ] . V_58 = V_291 ;
V_289 [ 1 ] . V_143 = V_143 -> V_13 ;
return F_156 ( & V_14 -> V_12 , V_289 ,
F_107 ( V_289 ) ) ;
}
int F_191 ( struct V_16 * V_12 ,
struct V_159 * V_160 )
{
struct V_8 V_37 ;
struct V_8 * V_9 ;
F_192 ( V_12 -> V_3 != V_160 -> V_3 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_38 = V_196 ;
if ( V_160 -> V_81 -> V_292 . V_293 ) {
V_37 . V_19 = V_109 ;
V_37 . V_13 = V_160 -> V_81 -> V_292 . V_293 ;
V_37 . V_225 = V_160 -> V_81 -> V_292 . V_293 ;
F_68 ( V_160 -> V_3 , L_97 ,
V_37 . V_13 ) ;
V_9 = F_24 ( V_12 , & V_37 ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_98 ,
V_160 -> V_81 -> V_292 . V_293 ) ;
return - V_30 ;
}
V_9 -> V_276 = V_160 ;
V_160 -> V_164 = V_9 ;
}
if ( V_160 -> V_81 -> V_294 . V_293 ) {
V_37 . V_19 = V_110 ;
V_37 . V_13 = V_160 -> V_81 -> V_294 . V_293 ;
V_37 . V_225 = V_160 -> V_81 -> V_294 . V_293 ;
F_68 ( V_160 -> V_3 , L_97 ,
V_37 . V_13 ) ;
V_9 = F_24 ( V_12 , & V_37 ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_98 ,
V_160 -> V_81 -> V_294 . V_293 ) ;
return - V_30 ;
}
V_9 -> V_276 = V_160 ;
V_160 -> V_165 = V_9 ;
}
return 0 ;
}
int F_193 ( struct V_17 * V_14 )
{
struct V_8 * V_295 , * V_9 ;
struct V_159 * V_160 ;
F_15 (dai_w, &card->widgets, list) {
switch ( V_295 -> V_19 ) {
case V_109 :
case V_110 :
break;
default:
continue;
}
V_160 = V_295 -> V_276 ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_295 -> V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_109 :
case V_110 :
continue;
default:
break;
}
if ( ! V_9 -> V_225 || ! strstr ( V_9 -> V_225 , V_295 -> V_13 ) )
continue;
if ( V_160 -> V_81 -> V_292 . V_293 &&
strstr ( V_9 -> V_225 ,
V_160 -> V_81 -> V_292 . V_293 ) ) {
F_68 ( V_160 -> V_3 , L_99 ,
V_160 -> V_164 -> V_13 , V_9 -> V_13 ) ;
F_31 ( V_9 -> V_12 ,
V_160 -> V_164 , V_9 , NULL , NULL ) ;
}
if ( V_160 -> V_81 -> V_294 . V_293 &&
strstr ( V_9 -> V_225 ,
V_160 -> V_81 -> V_294 . V_293 ) ) {
F_68 ( V_160 -> V_3 , L_99 ,
V_9 -> V_13 , V_160 -> V_165 -> V_13 ) ;
F_31 ( V_9 -> V_12 , V_9 ,
V_160 -> V_165 , NULL , NULL ) ;
}
}
}
return 0 ;
}
static void F_194 ( struct V_236 * V_237 , int V_161 ,
int V_166 )
{
struct V_8 * V_296 , * V_297 ;
struct V_159 * V_298 = V_237 -> V_298 ;
struct V_159 * V_299 = V_237 -> V_299 ;
if ( V_161 == V_163 ) {
V_296 = V_298 -> V_164 ;
V_297 = V_299 -> V_164 ;
} else {
V_296 = V_298 -> V_165 ;
V_297 = V_299 -> V_165 ;
}
if ( V_296 ) {
F_10 ( V_296 , L_100 ) ;
switch ( V_166 ) {
case V_200 :
V_296 -> V_152 = 1 ;
break;
case V_201 :
V_296 -> V_152 = 0 ;
break;
case V_300 :
case V_301 :
case V_302 :
case V_303 :
break;
}
}
if ( V_297 ) {
F_10 ( V_297 , L_100 ) ;
switch ( V_166 ) {
case V_200 :
V_297 -> V_152 = 1 ;
break;
case V_201 :
V_297 -> V_152 = 0 ;
break;
case V_300 :
case V_301 :
case V_302 :
case V_303 :
break;
}
}
F_119 ( V_237 -> V_14 , V_166 ) ;
}
void F_195 ( struct V_236 * V_237 , int V_161 ,
int V_166 )
{
struct V_17 * V_14 = V_237 -> V_14 ;
F_76 ( & V_14 -> V_18 , V_162 ) ;
F_194 ( V_237 , V_161 , V_166 ) ;
F_16 ( & V_14 -> V_18 ) ;
}
int F_175 ( struct V_16 * V_12 , const char * V_242 )
{
return F_152 ( V_12 , V_242 , 1 ) ;
}
int F_196 ( struct V_16 * V_12 ,
const char * V_242 )
{
struct V_8 * V_9 = F_151 ( V_12 , V_242 , true ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_101 , V_242 ) ;
return - V_141 ;
}
F_68 ( V_9 -> V_12 -> V_3 , L_102 , V_242 ) ;
V_9 -> V_153 = 1 ;
V_9 -> V_171 = 1 ;
F_10 ( V_9 , L_103 ) ;
return 0 ;
}
int F_176 ( struct V_16 * V_12 ,
const char * V_242 )
{
return F_152 ( V_12 , V_242 , 0 ) ;
}
int F_197 ( struct V_16 * V_12 , const char * V_242 )
{
return F_152 ( V_12 , V_242 , 0 ) ;
}
int F_173 ( struct V_16 * V_12 ,
const char * V_242 )
{
struct V_8 * V_9 = F_151 ( V_12 , V_242 , true ) ;
if ( V_9 )
return V_9 -> V_153 ;
return 0 ;
}
int F_198 ( struct V_16 * V_12 ,
const char * V_242 )
{
struct V_8 * V_9 = F_151 ( V_12 , V_242 , false ) ;
if ( ! V_9 ) {
F_21 ( V_12 -> V_3 , L_101 , V_242 ) ;
return - V_141 ;
}
V_9 -> V_147 = 1 ;
return 0 ;
}
static bool F_199 ( struct V_17 * V_14 ,
struct V_8 * V_9 )
{
struct V_55 * V_84 ;
F_15 (p, &card->paths, list) {
if ( ( V_84 -> V_58 == V_9 ) || ( V_84 -> V_143 == V_9 ) ) {
F_68 ( V_14 -> V_3 ,
L_104 ,
V_84 -> V_58 -> V_13 , V_84 -> V_58 -> V_19 , V_84 -> V_58 -> V_12 ,
V_84 -> V_143 -> V_13 , V_84 -> V_143 -> V_19 , V_84 -> V_143 -> V_12 ) ;
if ( V_84 -> V_58 -> V_12 != V_84 -> V_143 -> V_12 )
return true ;
if ( V_84 -> V_143 -> V_19 == V_20 ) {
switch ( V_84 -> V_58 -> V_19 ) {
case V_21 :
case V_102 :
return true ;
default:
break;
}
}
}
}
return false ;
}
void F_200 ( struct V_61 * V_62 )
{
struct V_17 * V_14 = V_62 -> V_14 ;
struct V_16 * V_12 = & V_62 -> V_12 ;
struct V_8 * V_9 ;
F_68 ( V_62 -> V_3 , L_105 ,
& V_14 -> V_12 , & V_62 -> V_12 ) ;
F_15 (w, &card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
switch ( V_9 -> V_19 ) {
case V_20 :
case V_21 :
case V_102 :
F_68 ( V_62 -> V_3 , L_106 ,
V_9 -> V_13 ) ;
if ( ! F_199 ( V_14 , V_9 ) ) {
F_68 ( V_62 -> V_3 ,
L_107 ) ;
F_197 ( V_12 , V_9 -> V_13 ) ;
}
break;
default:
break;
}
}
}
void F_201 ( struct V_16 * V_12 )
{
F_146 ( V_12 -> V_3 ) ;
F_134 ( V_12 ) ;
F_150 ( V_12 ) ;
F_149 ( & V_12 -> V_122 ) ;
}
static void F_202 ( struct V_16 * V_12 )
{
struct V_17 * V_14 = V_12 -> V_14 ;
struct V_8 * V_9 ;
F_105 ( V_216 ) ;
int V_304 = 0 ;
F_14 ( & V_14 -> V_18 ) ;
F_15 (w, &dapm->card->widgets, list) {
if ( V_9 -> V_12 != V_12 )
continue;
if ( V_9 -> V_59 ) {
F_96 ( V_9 , & V_216 , false ) ;
V_9 -> V_59 = 0 ;
V_304 = 1 ;
}
}
if ( V_304 ) {
if ( V_12 -> V_82 == V_213 )
F_48 ( V_12 ,
V_212 ) ;
F_104 ( V_14 , & V_216 , 0 , false ) ;
if ( V_12 -> V_82 == V_212 )
F_48 ( V_12 ,
V_211 ) ;
}
F_16 ( & V_14 -> V_18 ) ;
}
void F_203 ( struct V_17 * V_14 )
{
struct V_61 * V_62 ;
F_15 (codec, &card->codec_dev_list, card_list) {
F_202 ( & V_62 -> V_12 ) ;
if ( V_62 -> V_12 . V_82 == V_211 )
F_48 ( & V_62 -> V_12 ,
V_209 ) ;
}
}
