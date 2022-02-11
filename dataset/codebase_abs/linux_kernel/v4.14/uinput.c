static int F_1 ( struct V_1 * V_2 ,
unsigned int type , unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 [ V_6 -> V_8 ] . type = type ;
V_6 -> V_7 [ V_6 -> V_8 ] . V_3 = V_3 ;
V_6 -> V_7 [ V_6 -> V_8 ] . V_4 = V_4 ;
F_3 ( & V_6 -> V_7 [ V_6 -> V_8 ] . time ) ;
V_6 -> V_8 = ( V_6 -> V_8 + 1 ) % V_9 ;
F_4 ( & V_6 -> V_10 ) ;
return 0 ;
}
static bool F_5 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
unsigned int V_13 ;
bool V_14 = false ;
F_6 ( & V_6 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( ! V_6 -> V_17 [ V_13 ] ) {
V_12 -> V_13 = V_13 ;
V_6 -> V_17 [ V_13 ] = V_12 ;
V_14 = true ;
break;
}
}
F_7 ( & V_6 -> V_15 ) ;
return V_14 ;
}
static struct V_11 * F_8 ( struct V_5 * V_6 ,
unsigned int V_13 )
{
if ( V_13 >= V_16 )
return NULL ;
return V_6 -> V_17 [ V_13 ] ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
return F_10 ( V_6 -> V_18 ,
F_5 ( V_6 , V_12 ) ) ;
}
static void F_11 ( struct V_5 * V_6 ,
unsigned int V_13 )
{
F_6 ( & V_6 -> V_15 ) ;
V_6 -> V_17 [ V_13 ] = NULL ;
F_7 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_18 ) ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
int V_19 ;
V_19 = F_14 ( & V_6 -> V_20 ) ;
if ( V_19 )
return V_19 ;
if ( V_6 -> V_21 != V_22 ) {
V_19 = - V_23 ;
goto V_24;
}
F_15 ( & V_12 -> V_25 ) ;
F_1 ( V_6 -> V_2 , V_26 , V_12 -> V_3 , V_12 -> V_13 ) ;
V_24:
F_16 ( & V_6 -> V_20 ) ;
return V_19 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
int V_19 ;
V_19 = F_9 ( V_6 , V_12 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( V_6 , V_12 ) ;
if ( V_19 )
goto V_24;
F_18 ( & V_12 -> V_25 ) ;
V_19 = V_12 -> V_19 ;
V_24:
F_11 ( V_6 , V_12 -> V_13 ) ;
return V_19 ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
int V_27 ;
F_6 ( & V_6 -> V_15 ) ;
for ( V_27 = 0 ; V_27 < V_16 ; V_27 ++ ) {
V_12 = V_6 -> V_17 [ V_27 ] ;
if ( V_12 ) {
V_12 -> V_19 = - V_23 ;
F_20 ( & V_12 -> V_25 ) ;
}
}
F_7 ( & V_6 -> V_15 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_28 )
{
F_1 ( V_2 , V_29 , V_30 , V_28 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_31 )
{
F_1 ( V_2 , V_29 , V_32 , V_31 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_33 , int V_4 )
{
return F_1 ( V_2 , V_29 , V_33 , V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_34 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
if ( V_35 -> type == V_37 &&
V_35 -> V_38 . V_39 . V_40 == V_41 )
return - V_42 ;
V_12 . V_3 = V_43 ;
V_12 . V_38 . V_44 . V_35 = V_35 ;
V_12 . V_38 . V_44 . V_36 = V_36 ;
return F_17 ( V_6 , & V_12 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
if ( ! F_26 ( V_29 , V_2 -> V_45 ) )
return - V_46 ;
V_12 . V_3 = V_47 ;
V_12 . V_38 . V_33 = V_33 ;
return F_17 ( V_6 , & V_12 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_48 * V_48 )
{
return V_48 ? F_28 ( V_2 , V_48 ) : 0 ;
}
static void F_29 ( struct V_5 * V_6 )
{
const char * V_49 , * V_50 ;
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_51 V_52 = V_6 -> V_21 ;
V_6 -> V_21 = V_53 ;
if ( V_2 ) {
V_49 = V_2 -> V_49 ;
V_50 = V_2 -> V_50 ;
if ( V_52 == V_22 ) {
F_19 ( V_6 ) ;
F_30 ( V_2 ) ;
} else {
F_31 ( V_2 ) ;
}
F_32 ( V_49 ) ;
F_32 ( V_50 ) ;
V_6 -> V_2 = NULL ;
}
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int error , V_54 ;
if ( V_6 -> V_21 != V_55 ) {
F_34 ( V_56 L_1 , V_57 ) ;
return - V_42 ;
}
if ( F_26 ( V_58 , V_2 -> V_45 ) ) {
F_35 ( V_2 ) ;
if ( ! V_2 -> V_59 ) {
error = - V_42 ;
goto V_60;
}
if ( F_26 ( V_61 , V_2 -> V_62 ) ) {
V_54 = F_36 ( V_2 , V_61 ) + 1 ;
error = F_37 ( V_2 , V_54 , 0 ) ;
if ( error )
goto V_60;
} else if ( F_26 ( V_63 , V_2 -> V_62 ) ) {
F_38 ( V_2 , 60 ) ;
}
}
if ( F_26 ( V_29 , V_2 -> V_45 ) && ! V_6 -> V_64 ) {
F_34 ( V_56 L_2 ,
V_57 ) ;
error = - V_42 ;
goto V_60;
}
if ( V_6 -> V_64 ) {
error = F_39 ( V_2 , V_6 -> V_64 ) ;
if ( error )
goto V_60;
V_2 -> V_65 -> V_44 = F_24 ;
V_2 -> V_65 -> V_66 = F_25 ;
V_2 -> V_65 -> V_67 = F_23 ;
V_2 -> V_65 -> V_68 = F_21 ;
V_2 -> V_65 -> V_69 = F_22 ;
V_2 -> V_70 = F_27 ;
}
error = F_40 ( V_6 -> V_2 ) ;
if ( error )
goto V_71;
V_6 -> V_21 = V_22 ;
return 0 ;
V_71: F_41 ( V_2 ) ;
V_60: F_29 ( V_6 ) ;
return error ;
}
static int F_42 ( struct V_72 * V_72 , struct V_48 * V_48 )
{
struct V_5 * V_73 ;
V_73 = F_43 ( sizeof( struct V_5 ) , V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_44 ( & V_73 -> V_20 ) ;
F_45 ( & V_73 -> V_15 ) ;
F_46 ( & V_73 -> V_18 ) ;
F_46 ( & V_73 -> V_10 ) ;
V_73 -> V_21 = V_53 ;
V_48 -> V_76 = V_73 ;
F_47 ( V_72 , V_48 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned int V_3 ,
const struct V_77 * abs )
{
int V_78 , V_79 ;
V_78 = abs -> V_80 ;
V_79 = abs -> V_81 ;
if ( ( V_78 != 0 || V_79 != 0 ) && V_79 <= V_78 ) {
F_34 ( V_56
L_3 ,
V_57 , V_3 , V_78 , V_79 ) ;
return - V_42 ;
}
if ( abs -> V_82 > V_79 - V_78 ) {
F_34 ( V_56
L_4 ,
V_57 , V_3 , abs -> V_82 , V_78 , V_79 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned int V_83 ;
int error ;
if ( ! F_26 ( V_58 , V_2 -> V_45 ) )
return 0 ;
F_50 (cnt, dev->absbit, ABS_CNT) {
if ( ! V_2 -> V_59 )
return - V_42 ;
error = F_48 ( V_2 , V_83 , & V_2 -> V_59 [ V_83 ] ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_51 ( struct V_5 * V_6 )
{
V_6 -> V_2 = F_52 () ;
if ( ! V_6 -> V_2 )
return - V_75 ;
V_6 -> V_2 -> V_84 = F_1 ;
F_53 ( V_6 -> V_2 , V_6 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_85 T_2 * V_86 )
{
struct V_85 V_87 ;
struct V_1 * V_2 ;
if ( V_6 -> V_21 == V_22 )
return - V_42 ;
if ( F_55 ( & V_87 , V_86 , sizeof( V_87 ) ) )
return - V_88 ;
if ( ! V_87 . V_49 [ 0 ] )
return - V_42 ;
V_2 = V_6 -> V_2 ;
V_2 -> V_13 = V_87 . V_13 ;
V_6 -> V_64 = V_87 . V_64 ;
F_32 ( V_2 -> V_49 ) ;
V_2 -> V_49 = F_56 ( V_87 . V_49 , V_89 , V_74 ) ;
if ( ! V_2 -> V_49 )
return - V_75 ;
V_6 -> V_21 = V_55 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_85 T_2 * V_86 , T_3 V_90 )
{
struct F_57 V_87 = {} ;
struct V_1 * V_2 ;
int error ;
if ( V_90 > sizeof( V_87 ) )
return - V_91 ;
if ( V_6 -> V_21 == V_22 )
return - V_42 ;
if ( F_55 ( & V_87 , V_86 , V_90 ) )
return - V_88 ;
if ( V_87 . V_3 > V_92 )
return - V_93 ;
V_2 = V_6 -> V_2 ;
error = F_48 ( V_2 , V_87 . V_3 , & V_87 . V_59 ) ;
if ( error )
return error ;
F_35 ( V_2 ) ;
if ( ! V_2 -> V_59 )
return - V_75 ;
F_58 ( V_87 . V_3 , V_2 -> V_62 ) ;
V_2 -> V_59 [ V_87 . V_3 ] = V_87 . V_59 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
const char T_2 * V_94 , T_3 V_95 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
int V_27 ;
int V_19 ;
if ( V_95 != sizeof( struct V_96 ) )
return - V_42 ;
if ( ! V_6 -> V_2 ) {
V_19 = F_51 ( V_6 ) ;
if ( V_19 )
return V_19 ;
}
V_2 = V_6 -> V_2 ;
V_97 = F_60 ( V_94 , sizeof( struct V_96 ) ) ;
if ( F_61 ( V_97 ) )
return F_62 ( V_97 ) ;
V_6 -> V_64 = V_97 -> V_64 ;
if ( ! V_97 -> V_49 [ 0 ] ) {
V_19 = - V_42 ;
goto exit;
}
F_32 ( V_2 -> V_49 ) ;
V_2 -> V_49 = F_56 ( V_97 -> V_49 , V_89 ,
V_74 ) ;
if ( ! V_2 -> V_49 ) {
V_19 = - V_75 ;
goto exit;
}
V_2 -> V_13 . V_98 = V_97 -> V_13 . V_98 ;
V_2 -> V_13 . V_99 = V_97 -> V_13 . V_99 ;
V_2 -> V_13 . V_100 = V_97 -> V_13 . V_100 ;
V_2 -> V_13 . V_101 = V_97 -> V_13 . V_101 ;
for ( V_27 = 0 ; V_27 < V_102 ; V_27 ++ ) {
F_63 ( V_2 , V_27 , V_97 -> V_103 [ V_27 ] ) ;
F_64 ( V_2 , V_27 , V_97 -> V_104 [ V_27 ] ) ;
F_65 ( V_2 , V_27 , V_97 -> V_105 [ V_27 ] ) ;
F_66 ( V_2 , V_27 , V_97 -> V_106 [ V_27 ] ) ;
}
V_19 = F_49 ( V_2 ) ;
if ( V_19 < 0 )
goto exit;
V_6 -> V_21 = V_55 ;
V_19 = V_95 ;
exit:
F_32 ( V_97 ) ;
return V_19 ;
}
static T_4 F_67 ( struct V_5 * V_6 ,
const char T_2 * V_94 , T_3 V_95 )
{
struct V_107 V_108 ;
T_3 V_109 = 0 ;
if ( V_95 != 0 && V_95 < F_68 () )
return - V_42 ;
while ( V_109 + F_68 () <= V_95 ) {
if ( F_69 ( V_94 + V_109 , & V_108 ) )
return - V_88 ;
V_107 ( V_6 -> V_2 , V_108 . type , V_108 . V_3 , V_108 . V_4 ) ;
V_109 += F_68 () ;
}
return V_109 ;
}
static T_4 F_70 ( struct V_48 * V_48 , const char T_2 * V_94 ,
T_3 V_95 , T_5 * V_110 )
{
struct V_5 * V_6 = V_48 -> V_76 ;
int V_19 ;
if ( V_95 == 0 )
return 0 ;
V_19 = F_14 ( & V_6 -> V_20 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_6 -> V_21 == V_22 ?
F_67 ( V_6 , V_94 , V_95 ) :
F_59 ( V_6 , V_94 , V_95 ) ;
F_16 ( & V_6 -> V_20 ) ;
return V_19 ;
}
static bool F_71 ( struct V_5 * V_6 ,
struct V_107 * V_84 )
{
bool V_111 ;
F_72 ( & V_6 -> V_2 -> V_112 ) ;
V_111 = V_6 -> V_8 != V_6 -> V_113 ;
if ( V_111 ) {
* V_84 = V_6 -> V_7 [ V_6 -> V_113 ] ;
V_6 -> V_113 = ( V_6 -> V_113 + 1 ) % V_9 ;
}
F_73 ( & V_6 -> V_2 -> V_112 ) ;
return V_111 ;
}
static T_4 F_74 ( struct V_5 * V_6 ,
char T_2 * V_94 , T_3 V_95 )
{
struct V_107 V_84 ;
T_3 V_114 = 0 ;
while ( V_114 + F_68 () <= V_95 &&
F_71 ( V_6 , & V_84 ) ) {
if ( F_75 ( V_94 + V_114 , & V_84 ) )
return - V_88 ;
V_114 += F_68 () ;
}
return V_114 ;
}
static T_4 F_76 ( struct V_48 * V_48 , char T_2 * V_94 ,
T_3 V_95 , T_5 * V_110 )
{
struct V_5 * V_6 = V_48 -> V_76 ;
T_4 V_19 ;
if ( V_95 != 0 && V_95 < F_68 () )
return - V_42 ;
do {
V_19 = F_14 ( & V_6 -> V_20 ) ;
if ( V_19 )
return V_19 ;
if ( V_6 -> V_21 != V_22 )
V_19 = - V_23 ;
else if ( V_6 -> V_8 == V_6 -> V_113 &&
( V_48 -> V_115 & V_116 ) )
V_19 = - V_117 ;
else
V_19 = F_74 ( V_6 , V_94 , V_95 ) ;
F_16 ( & V_6 -> V_20 ) ;
if ( V_19 || V_95 == 0 )
break;
if ( ! ( V_48 -> V_115 & V_116 ) )
V_19 = F_10 ( V_6 -> V_10 ,
V_6 -> V_8 != V_6 -> V_113 ||
V_6 -> V_21 != V_22 ) ;
} while ( V_19 == 0 );
return V_19 ;
}
static unsigned int F_77 ( struct V_48 * V_48 , T_6 * V_118 )
{
struct V_5 * V_6 = V_48 -> V_76 ;
F_78 ( V_48 , & V_6 -> V_10 , V_118 ) ;
if ( V_6 -> V_8 != V_6 -> V_113 )
return V_119 | V_120 ;
return 0 ;
}
static int F_79 ( struct V_72 * V_72 , struct V_48 * V_48 )
{
struct V_5 * V_6 = V_48 -> V_76 ;
F_29 ( V_6 ) ;
F_32 ( V_6 ) ;
return 0 ;
}
static int F_80 ( char T_2 * V_94 ,
const struct V_121 * V_122 )
{
if ( F_81 () ) {
struct V_123 V_124 ;
V_124 . V_125 = V_122 -> V_125 ;
V_124 . V_19 = V_122 -> V_19 ;
memcpy ( & V_124 . V_35 , & V_122 -> V_35 ,
sizeof( struct V_126 ) ) ;
memcpy ( & V_124 . V_36 , & V_122 -> V_36 ,
sizeof( struct V_126 ) ) ;
if ( F_82 ( V_94 , & V_124 ,
sizeof( struct V_123 ) ) )
return - V_88 ;
} else {
if ( F_82 ( V_94 , V_122 ,
sizeof( struct V_121 ) ) )
return - V_88 ;
}
return 0 ;
}
static int F_83 ( const char T_2 * V_94 ,
struct V_121 * V_122 )
{
if ( F_81 () ) {
struct V_123 V_124 ;
if ( F_55 ( & V_124 , V_94 ,
sizeof( struct V_123 ) ) )
return - V_88 ;
V_122 -> V_125 = V_124 . V_125 ;
V_122 -> V_19 = V_124 . V_19 ;
memcpy ( & V_122 -> V_35 , & V_124 . V_35 ,
sizeof( struct V_126 ) ) ;
memcpy ( & V_122 -> V_36 , & V_124 . V_36 ,
sizeof( struct V_126 ) ) ;
} else {
if ( F_55 ( V_122 , V_94 ,
sizeof( struct V_121 ) ) )
return - V_88 ;
}
return 0 ;
}
static int F_80 ( char T_2 * V_94 ,
const struct V_121 * V_122 )
{
if ( F_82 ( V_94 , V_122 , sizeof( struct V_121 ) ) )
return - V_88 ;
return 0 ;
}
static int F_83 ( const char T_2 * V_94 ,
struct V_121 * V_122 )
{
if ( F_55 ( V_122 , V_94 , sizeof( struct V_121 ) ) )
return - V_88 ;
return 0 ;
}
static int F_84 ( void T_2 * V_127 , const char * V_128 ,
unsigned int V_129 )
{
char T_2 * V_130 = V_127 ;
int V_131 , V_132 ;
if ( ! V_128 )
return - V_133 ;
if ( V_129 == 0 )
return - V_42 ;
V_131 = strlen ( V_128 ) + 1 ;
if ( V_131 > V_129 )
V_131 = V_129 ;
V_132 = F_82 ( V_130 , V_128 , V_131 ) ;
if ( V_132 )
return - V_88 ;
V_132 = F_85 ( 0 , V_130 + V_131 - 1 ) ;
return V_132 ? - V_88 : V_131 ;
}
static long F_86 ( struct V_48 * V_48 , unsigned int V_134 ,
unsigned long V_86 , void T_2 * V_130 )
{
int V_19 ;
struct V_5 * V_6 = V_48 -> V_76 ;
struct V_121 V_122 ;
struct V_135 V_136 ;
struct V_11 * V_137 ;
char * V_50 ;
const char * V_49 ;
unsigned int V_90 ;
V_19 = F_14 ( & V_6 -> V_20 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_6 -> V_2 ) {
V_19 = F_51 ( V_6 ) ;
if ( V_19 )
goto V_24;
}
switch ( V_134 ) {
case V_138 :
if ( F_85 ( V_139 ,
( unsigned int T_2 * ) V_130 ) )
V_19 = - V_88 ;
goto V_24;
case V_140 :
V_19 = F_33 ( V_6 ) ;
goto V_24;
case V_141 :
F_29 ( V_6 ) ;
goto V_24;
case V_142 :
V_19 = F_54 ( V_6 , V_130 ) ;
goto V_24;
case V_143 :
V_19 = F_87 ( V_86 , V_45 , V_144 ) ;
goto V_24;
case V_145 :
V_19 = F_87 ( V_86 , V_146 , V_147 ) ;
goto V_24;
case V_148 :
V_19 = F_87 ( V_86 , V_149 , V_150 ) ;
goto V_24;
case V_151 :
V_19 = F_87 ( V_86 , V_62 , V_92 ) ;
goto V_24;
case V_152 :
V_19 = F_87 ( V_86 , V_153 , V_154 ) ;
goto V_24;
case V_155 :
V_19 = F_87 ( V_86 , V_156 , V_157 ) ;
goto V_24;
case V_158 :
V_19 = F_87 ( V_86 , V_159 , V_160 ) ;
goto V_24;
case V_161 :
V_19 = F_87 ( V_86 , V_162 , V_163 ) ;
goto V_24;
case V_164 :
V_19 = F_87 ( V_86 , V_165 , V_166 ) ;
goto V_24;
case V_167 :
V_19 = F_87 ( V_86 , V_168 , V_169 ) ;
goto V_24;
case V_170 :
if ( V_6 -> V_21 == V_22 ) {
V_19 = - V_42 ;
goto V_24;
}
V_50 = F_88 ( V_130 , 1024 ) ;
if ( F_61 ( V_50 ) ) {
V_19 = F_62 ( V_50 ) ;
goto V_24;
}
F_32 ( V_6 -> V_2 -> V_50 ) ;
V_6 -> V_2 -> V_50 = V_50 ;
goto V_24;
case V_171 :
V_19 = F_83 ( V_130 , & V_122 ) ;
if ( V_19 )
goto V_24;
V_137 = F_8 ( V_6 , V_122 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_43 ||
! V_137 -> V_38 . V_44 . V_35 ) {
V_19 = - V_42 ;
goto V_24;
}
V_122 . V_19 = 0 ;
V_122 . V_35 = * V_137 -> V_38 . V_44 . V_35 ;
if ( V_137 -> V_38 . V_44 . V_36 )
V_122 . V_36 = * V_137 -> V_38 . V_44 . V_36 ;
else
memset ( & V_122 . V_36 , 0 , sizeof( struct V_34 ) ) ;
V_19 = F_80 ( V_130 , & V_122 ) ;
goto V_24;
case V_172 :
if ( F_55 ( & V_136 , V_130 , sizeof( V_136 ) ) ) {
V_19 = - V_88 ;
goto V_24;
}
V_137 = F_8 ( V_6 , V_136 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_47 ) {
V_19 = - V_42 ;
goto V_24;
}
V_136 . V_19 = 0 ;
V_136 . V_33 = V_137 -> V_38 . V_33 ;
if ( F_82 ( V_130 , & V_136 , sizeof( V_136 ) ) ) {
V_19 = - V_88 ;
goto V_24;
}
goto V_24;
case V_173 :
V_19 = F_83 ( V_130 , & V_122 ) ;
if ( V_19 )
goto V_24;
V_137 = F_8 ( V_6 , V_122 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_43 ||
! V_137 -> V_38 . V_44 . V_35 ) {
V_19 = - V_42 ;
goto V_24;
}
V_137 -> V_19 = V_122 . V_19 ;
F_20 ( & V_137 -> V_25 ) ;
goto V_24;
case V_174 :
if ( F_55 ( & V_136 , V_130 , sizeof( V_136 ) ) ) {
V_19 = - V_88 ;
goto V_24;
}
V_137 = F_8 ( V_6 , V_136 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_47 ) {
V_19 = - V_42 ;
goto V_24;
}
V_137 -> V_19 = V_136 . V_19 ;
F_20 ( & V_137 -> V_25 ) ;
goto V_24;
}
V_90 = F_89 ( V_134 ) ;
switch ( V_134 & ~ V_175 ) {
case F_90 ( 0 ) :
if ( V_6 -> V_21 != V_22 ) {
V_19 = - V_133 ;
goto V_24;
}
V_49 = F_91 ( & V_6 -> V_2 -> V_2 ) ;
V_19 = F_84 ( V_130 , V_49 , V_90 ) ;
goto V_24;
case V_176 & ~ V_175 :
V_19 = F_57 ( V_6 , V_130 , V_90 ) ;
goto V_24;
}
V_19 = - V_42 ;
V_24:
F_16 ( & V_6 -> V_20 ) ;
return V_19 ;
}
static long F_92 ( struct V_48 * V_48 , unsigned int V_134 , unsigned long V_86 )
{
return F_86 ( V_48 , V_134 , V_86 , ( void T_2 * ) V_86 ) ;
}
static long F_93 ( struct V_48 * V_48 ,
unsigned int V_134 , unsigned long V_86 )
{
if ( V_134 == V_177 )
V_134 = V_170 ;
return F_86 ( V_48 , V_134 , V_86 , F_94 ( V_86 ) ) ;
}
