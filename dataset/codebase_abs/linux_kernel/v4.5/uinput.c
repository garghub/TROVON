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
struct V_11 * V_12 )
{
V_6 -> V_17 [ V_12 -> V_13 ] = NULL ;
F_12 ( & V_6 -> V_18 ) ;
F_13 ( & V_12 -> V_19 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
int V_20 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_6 -> V_22 != V_23 ) {
V_20 = - V_24 ;
goto V_25;
}
F_16 ( & V_12 -> V_19 ) ;
F_1 ( V_6 -> V_2 , V_26 , V_12 -> V_3 , V_12 -> V_13 ) ;
V_25:
F_17 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
int error ;
error = F_9 ( V_6 , V_12 ) ;
if ( error )
return error ;
error = F_14 ( V_6 , V_12 ) ;
if ( error ) {
F_11 ( V_6 , V_12 ) ;
return error ;
}
F_19 ( & V_12 -> V_19 ) ;
return V_12 -> V_20 ;
}
static void F_20 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
int V_27 ;
F_6 ( & V_6 -> V_15 ) ;
for ( V_27 = 0 ; V_27 < V_16 ; V_27 ++ ) {
V_12 = V_6 -> V_17 [ V_27 ] ;
if ( V_12 ) {
V_12 -> V_20 = - V_24 ;
F_11 ( V_6 , V_12 ) ;
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
return F_18 ( V_6 , & V_12 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_11 V_12 ;
if ( ! F_26 ( V_29 , V_2 -> V_45 ) )
return - V_46 ;
V_12 . V_3 = V_47 ;
V_12 . V_38 . V_33 = V_33 ;
return F_18 ( V_6 , & V_12 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
const char * V_48 , * V_49 ;
struct V_1 * V_2 = V_6 -> V_2 ;
enum V_50 V_51 = V_6 -> V_22 ;
V_6 -> V_22 = V_52 ;
if ( V_2 ) {
V_48 = V_2 -> V_48 ;
V_49 = V_2 -> V_49 ;
if ( V_51 == V_23 ) {
F_20 ( V_6 ) ;
F_28 ( V_2 ) ;
} else {
F_29 ( V_2 ) ;
}
F_30 ( V_48 ) ;
F_30 ( V_49 ) ;
V_6 -> V_2 = NULL ;
}
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int error , V_53 ;
if ( V_6 -> V_22 != V_54 ) {
F_32 ( V_55 L_1 , V_56 ) ;
return - V_42 ;
}
if ( F_26 ( V_57 , V_2 -> V_58 ) ) {
V_53 = F_33 ( V_2 , V_57 ) + 1 ;
error = F_34 ( V_2 , V_53 , 0 ) ;
if ( error )
goto V_59;
} else if ( F_26 ( V_60 , V_2 -> V_58 ) ) {
F_35 ( V_2 , 60 ) ;
}
if ( F_26 ( V_29 , V_2 -> V_45 ) && ! V_6 -> V_61 ) {
F_32 ( V_55 L_2 ,
V_56 ) ;
error = - V_42 ;
goto V_59;
}
if ( V_6 -> V_61 ) {
error = F_36 ( V_2 , V_6 -> V_61 ) ;
if ( error )
goto V_59;
V_2 -> V_62 -> V_44 = F_24 ;
V_2 -> V_62 -> V_63 = F_25 ;
V_2 -> V_62 -> V_64 = F_23 ;
V_2 -> V_62 -> V_65 = F_21 ;
V_2 -> V_62 -> V_66 = F_22 ;
}
error = F_37 ( V_6 -> V_2 ) ;
if ( error )
goto V_67;
V_6 -> V_22 = V_23 ;
return 0 ;
V_67: F_38 ( V_2 ) ;
V_59: F_27 ( V_6 ) ;
return error ;
}
static int F_39 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_5 * V_70 ;
V_70 = F_40 ( sizeof( struct V_5 ) , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
F_41 ( & V_70 -> V_21 ) ;
F_42 ( & V_70 -> V_15 ) ;
F_43 ( & V_70 -> V_18 ) ;
F_43 ( & V_70 -> V_10 ) ;
V_70 -> V_22 = V_52 ;
V_69 -> V_73 = V_70 ;
F_44 ( V_68 , V_69 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , unsigned int V_3 ,
const struct V_74 * abs )
{
int V_75 , V_76 ;
V_75 = abs -> V_77 ;
V_76 = abs -> V_78 ;
if ( ( V_75 != 0 || V_76 != 0 ) && V_76 <= V_75 ) {
F_32 ( V_55
L_3 ,
V_56 , V_3 , V_75 , V_76 ) ;
return - V_42 ;
}
if ( abs -> V_79 > V_76 - V_75 ) {
F_32 ( V_55
L_4 ,
V_56 , V_3 , abs -> V_79 , V_75 , V_76 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
unsigned int V_80 ;
int error ;
if ( ! F_26 ( V_81 , V_2 -> V_45 ) )
return 0 ;
F_47 (cnt, dev->absbit, ABS_CNT) {
if ( ! V_2 -> V_82 )
return - V_42 ;
error = F_45 ( V_2 , V_80 , & V_2 -> V_82 [ V_80 ] ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_48 ( struct V_5 * V_6 )
{
V_6 -> V_2 = F_49 () ;
if ( ! V_6 -> V_2 )
return - V_72 ;
V_6 -> V_2 -> V_83 = F_1 ;
F_50 ( V_6 -> V_2 , V_6 ) ;
return 0 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_84 T_2 * V_85 )
{
struct V_84 V_86 ;
struct V_1 * V_2 ;
if ( V_6 -> V_22 == V_23 )
return - V_42 ;
if ( F_52 ( & V_86 , V_85 , sizeof( V_86 ) ) )
return - V_87 ;
if ( ! V_86 . V_48 [ 0 ] )
return - V_42 ;
V_2 = V_6 -> V_2 ;
V_2 -> V_13 = V_86 . V_13 ;
V_6 -> V_61 = V_86 . V_61 ;
F_30 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_53 ( V_86 . V_48 , V_88 , V_71 ) ;
if ( ! V_2 -> V_48 )
return - V_72 ;
V_6 -> V_22 = V_54 ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_84 T_2 * V_85 , T_3 V_89 )
{
struct F_54 V_86 = {} ;
struct V_1 * V_2 ;
int error ;
if ( V_89 > sizeof( V_86 ) )
return - V_90 ;
if ( V_6 -> V_22 == V_23 )
return - V_42 ;
if ( F_52 ( & V_86 , V_85 , V_89 ) )
return - V_87 ;
if ( V_86 . V_3 > V_91 )
return - V_92 ;
V_2 = V_6 -> V_2 ;
error = F_45 ( V_2 , V_86 . V_3 , & V_86 . V_82 ) ;
if ( error )
return error ;
F_55 ( V_2 ) ;
if ( ! V_2 -> V_82 )
return - V_72 ;
F_56 ( V_86 . V_3 , V_2 -> V_58 ) ;
V_2 -> V_82 [ V_86 . V_3 ] = V_86 . V_82 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
const char T_2 * V_93 , T_3 V_94 )
{
struct V_95 * V_96 ;
struct V_1 * V_2 ;
int V_27 ;
int V_20 ;
if ( V_94 != sizeof( struct V_95 ) )
return - V_42 ;
if ( ! V_6 -> V_2 ) {
V_20 = F_48 ( V_6 ) ;
if ( V_20 )
return V_20 ;
}
V_2 = V_6 -> V_2 ;
V_96 = F_58 ( V_93 , sizeof( struct V_95 ) ) ;
if ( F_59 ( V_96 ) )
return F_60 ( V_96 ) ;
V_6 -> V_61 = V_96 -> V_61 ;
if ( ! V_96 -> V_48 [ 0 ] ) {
V_20 = - V_42 ;
goto exit;
}
F_30 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_53 ( V_96 -> V_48 , V_88 ,
V_71 ) ;
if ( ! V_2 -> V_48 ) {
V_20 = - V_72 ;
goto exit;
}
V_2 -> V_13 . V_97 = V_96 -> V_13 . V_97 ;
V_2 -> V_13 . V_98 = V_96 -> V_13 . V_98 ;
V_2 -> V_13 . V_99 = V_96 -> V_13 . V_99 ;
V_2 -> V_13 . V_100 = V_96 -> V_13 . V_100 ;
for ( V_27 = 0 ; V_27 < V_101 ; V_27 ++ ) {
F_61 ( V_2 , V_27 , V_96 -> V_102 [ V_27 ] ) ;
F_62 ( V_2 , V_27 , V_96 -> V_103 [ V_27 ] ) ;
F_63 ( V_2 , V_27 , V_96 -> V_104 [ V_27 ] ) ;
F_64 ( V_2 , V_27 , V_96 -> V_105 [ V_27 ] ) ;
}
V_20 = F_46 ( V_2 ) ;
if ( V_20 < 0 )
goto exit;
V_6 -> V_22 = V_54 ;
V_20 = V_94 ;
exit:
F_30 ( V_96 ) ;
return V_20 ;
}
static T_4 F_65 ( struct V_5 * V_6 ,
const char T_2 * V_93 , T_3 V_94 )
{
struct V_106 V_107 ;
T_3 V_108 = 0 ;
if ( V_94 != 0 && V_94 < F_66 () )
return - V_42 ;
while ( V_108 + F_66 () <= V_94 ) {
if ( F_67 ( V_93 + V_108 , & V_107 ) )
return - V_87 ;
V_106 ( V_6 -> V_2 , V_107 . type , V_107 . V_3 , V_107 . V_4 ) ;
V_108 += F_66 () ;
}
return V_108 ;
}
static T_4 F_68 ( struct V_69 * V_69 , const char T_2 * V_93 ,
T_3 V_94 , T_5 * V_109 )
{
struct V_5 * V_6 = V_69 -> V_73 ;
int V_20 ;
if ( V_94 == 0 )
return 0 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_6 -> V_22 == V_23 ?
F_65 ( V_6 , V_93 , V_94 ) :
F_57 ( V_6 , V_93 , V_94 ) ;
F_17 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static bool F_69 ( struct V_5 * V_6 ,
struct V_106 * V_83 )
{
bool V_110 ;
F_70 ( & V_6 -> V_2 -> V_111 ) ;
V_110 = V_6 -> V_8 != V_6 -> V_112 ;
if ( V_110 ) {
* V_83 = V_6 -> V_7 [ V_6 -> V_112 ] ;
V_6 -> V_112 = ( V_6 -> V_112 + 1 ) % V_9 ;
}
F_71 ( & V_6 -> V_2 -> V_111 ) ;
return V_110 ;
}
static T_4 F_72 ( struct V_5 * V_6 ,
char T_2 * V_93 , T_3 V_94 )
{
struct V_106 V_83 ;
T_3 V_113 = 0 ;
while ( V_113 + F_66 () <= V_94 &&
F_69 ( V_6 , & V_83 ) ) {
if ( F_73 ( V_93 + V_113 , & V_83 ) )
return - V_87 ;
V_113 += F_66 () ;
}
return V_113 ;
}
static T_4 F_74 ( struct V_69 * V_69 , char T_2 * V_93 ,
T_3 V_94 , T_5 * V_109 )
{
struct V_5 * V_6 = V_69 -> V_73 ;
T_4 V_20 ;
if ( V_94 != 0 && V_94 < F_66 () )
return - V_42 ;
do {
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( V_6 -> V_22 != V_23 )
V_20 = - V_24 ;
else if ( V_6 -> V_8 == V_6 -> V_112 &&
( V_69 -> V_114 & V_115 ) )
V_20 = - V_116 ;
else
V_20 = F_72 ( V_6 , V_93 , V_94 ) ;
F_17 ( & V_6 -> V_21 ) ;
if ( V_20 || V_94 == 0 )
break;
if ( ! ( V_69 -> V_114 & V_115 ) )
V_20 = F_10 ( V_6 -> V_10 ,
V_6 -> V_8 != V_6 -> V_112 ||
V_6 -> V_22 != V_23 ) ;
} while ( V_20 == 0 );
return V_20 ;
}
static unsigned int F_75 ( struct V_69 * V_69 , T_6 * V_117 )
{
struct V_5 * V_6 = V_69 -> V_73 ;
F_76 ( V_69 , & V_6 -> V_10 , V_117 ) ;
if ( V_6 -> V_8 != V_6 -> V_112 )
return V_118 | V_119 ;
return 0 ;
}
static int F_77 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_5 * V_6 = V_69 -> V_73 ;
F_27 ( V_6 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
static int F_78 ( char T_2 * V_93 ,
const struct V_120 * V_121 )
{
if ( V_122 ) {
struct V_123 V_124 ;
V_124 . V_125 = V_121 -> V_125 ;
V_124 . V_20 = V_121 -> V_20 ;
memcpy ( & V_124 . V_35 , & V_121 -> V_35 ,
sizeof( struct V_126 ) ) ;
memcpy ( & V_124 . V_36 , & V_121 -> V_36 ,
sizeof( struct V_126 ) ) ;
if ( F_79 ( V_93 , & V_124 ,
sizeof( struct V_123 ) ) )
return - V_87 ;
} else {
if ( F_79 ( V_93 , V_121 ,
sizeof( struct V_120 ) ) )
return - V_87 ;
}
return 0 ;
}
static int F_80 ( const char T_2 * V_93 ,
struct V_120 * V_121 )
{
if ( V_122 ) {
struct V_123 V_124 ;
if ( F_52 ( & V_124 , V_93 ,
sizeof( struct V_123 ) ) )
return - V_87 ;
V_121 -> V_125 = V_124 . V_125 ;
V_121 -> V_20 = V_124 . V_20 ;
memcpy ( & V_121 -> V_35 , & V_124 . V_35 ,
sizeof( struct V_126 ) ) ;
memcpy ( & V_121 -> V_36 , & V_124 . V_36 ,
sizeof( struct V_126 ) ) ;
} else {
if ( F_52 ( V_121 , V_93 ,
sizeof( struct V_120 ) ) )
return - V_87 ;
}
return 0 ;
}
static int F_78 ( char T_2 * V_93 ,
const struct V_120 * V_121 )
{
if ( F_79 ( V_93 , V_121 , sizeof( struct V_120 ) ) )
return - V_87 ;
return 0 ;
}
static int F_80 ( const char T_2 * V_93 ,
struct V_120 * V_121 )
{
if ( F_52 ( V_121 , V_93 , sizeof( struct V_120 ) ) )
return - V_87 ;
return 0 ;
}
static int F_81 ( void T_2 * V_127 , const char * V_128 ,
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
V_132 = F_79 ( V_130 , V_128 , V_131 ) ;
if ( V_132 )
return - V_87 ;
V_132 = F_82 ( 0 , V_130 + V_131 - 1 ) ;
return V_132 ? - V_87 : V_131 ;
}
static long F_83 ( struct V_69 * V_69 , unsigned int V_134 ,
unsigned long V_85 , void T_2 * V_130 )
{
int V_20 ;
struct V_5 * V_6 = V_69 -> V_73 ;
struct V_120 V_121 ;
struct V_135 V_136 ;
struct V_11 * V_137 ;
char * V_49 ;
const char * V_48 ;
unsigned int V_89 ;
V_20 = F_15 ( & V_6 -> V_21 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_6 -> V_2 ) {
V_20 = F_48 ( V_6 ) ;
if ( V_20 )
goto V_25;
}
switch ( V_134 ) {
case V_138 :
if ( F_82 ( V_139 ,
( unsigned int T_2 * ) V_130 ) )
V_20 = - V_87 ;
goto V_25;
case V_140 :
V_20 = F_31 ( V_6 ) ;
goto V_25;
case V_141 :
F_27 ( V_6 ) ;
goto V_25;
case V_142 :
V_20 = F_51 ( V_6 , V_130 ) ;
goto V_25;
case V_143 :
V_20 = F_84 ( V_85 , V_45 , V_144 ) ;
goto V_25;
case V_145 :
V_20 = F_84 ( V_85 , V_146 , V_147 ) ;
goto V_25;
case V_148 :
V_20 = F_84 ( V_85 , V_149 , V_150 ) ;
goto V_25;
case V_151 :
V_20 = F_84 ( V_85 , V_58 , V_91 ) ;
goto V_25;
case V_152 :
V_20 = F_84 ( V_85 , V_153 , V_154 ) ;
goto V_25;
case V_155 :
V_20 = F_84 ( V_85 , V_156 , V_157 ) ;
goto V_25;
case V_158 :
V_20 = F_84 ( V_85 , V_159 , V_160 ) ;
goto V_25;
case V_161 :
V_20 = F_84 ( V_85 , V_162 , V_163 ) ;
goto V_25;
case V_164 :
V_20 = F_84 ( V_85 , V_165 , V_166 ) ;
goto V_25;
case V_167 :
V_20 = F_84 ( V_85 , V_168 , V_169 ) ;
goto V_25;
case V_170 :
if ( V_6 -> V_22 == V_23 ) {
V_20 = - V_42 ;
goto V_25;
}
V_49 = F_85 ( V_130 , 1024 ) ;
if ( F_59 ( V_49 ) ) {
V_20 = F_60 ( V_49 ) ;
goto V_25;
}
F_30 ( V_6 -> V_2 -> V_49 ) ;
V_6 -> V_2 -> V_49 = V_49 ;
goto V_25;
case V_171 :
V_20 = F_80 ( V_130 , & V_121 ) ;
if ( V_20 )
goto V_25;
V_137 = F_8 ( V_6 , V_121 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_43 ||
! V_137 -> V_38 . V_44 . V_35 ) {
V_20 = - V_42 ;
goto V_25;
}
V_121 . V_20 = 0 ;
V_121 . V_35 = * V_137 -> V_38 . V_44 . V_35 ;
if ( V_137 -> V_38 . V_44 . V_36 )
V_121 . V_36 = * V_137 -> V_38 . V_44 . V_36 ;
else
memset ( & V_121 . V_36 , 0 , sizeof( struct V_34 ) ) ;
V_20 = F_78 ( V_130 , & V_121 ) ;
goto V_25;
case V_172 :
if ( F_52 ( & V_136 , V_130 , sizeof( V_136 ) ) ) {
V_20 = - V_87 ;
goto V_25;
}
V_137 = F_8 ( V_6 , V_136 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_47 ) {
V_20 = - V_42 ;
goto V_25;
}
V_136 . V_20 = 0 ;
V_136 . V_33 = V_137 -> V_38 . V_33 ;
if ( F_79 ( V_130 , & V_136 , sizeof( V_136 ) ) ) {
V_20 = - V_87 ;
goto V_25;
}
goto V_25;
case V_173 :
V_20 = F_80 ( V_130 , & V_121 ) ;
if ( V_20 )
goto V_25;
V_137 = F_8 ( V_6 , V_121 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_43 ||
! V_137 -> V_38 . V_44 . V_35 ) {
V_20 = - V_42 ;
goto V_25;
}
V_137 -> V_20 = V_121 . V_20 ;
F_11 ( V_6 , V_137 ) ;
goto V_25;
case V_174 :
if ( F_52 ( & V_136 , V_130 , sizeof( V_136 ) ) ) {
V_20 = - V_87 ;
goto V_25;
}
V_137 = F_8 ( V_6 , V_136 . V_125 ) ;
if ( ! V_137 || V_137 -> V_3 != V_47 ) {
V_20 = - V_42 ;
goto V_25;
}
V_137 -> V_20 = V_136 . V_20 ;
F_11 ( V_6 , V_137 ) ;
goto V_25;
}
V_89 = F_86 ( V_134 ) ;
switch ( V_134 & ~ V_175 ) {
case F_87 ( 0 ) :
if ( V_6 -> V_22 != V_23 ) {
V_20 = - V_133 ;
goto V_25;
}
V_48 = F_88 ( & V_6 -> V_2 -> V_2 ) ;
V_20 = F_81 ( V_130 , V_48 , V_89 ) ;
goto V_25;
case V_176 & ~ V_175 :
V_20 = F_54 ( V_6 , V_130 , V_89 ) ;
goto V_25;
}
V_20 = - V_42 ;
V_25:
F_17 ( & V_6 -> V_21 ) ;
return V_20 ;
}
static long F_89 ( struct V_69 * V_69 , unsigned int V_134 , unsigned long V_85 )
{
return F_83 ( V_69 , V_134 , V_85 , ( void T_2 * ) V_85 ) ;
}
static long F_90 ( struct V_69 * V_69 ,
unsigned int V_134 , unsigned long V_85 )
{
return F_83 ( V_69 , V_134 , V_85 , F_91 ( V_85 ) ) ;
}
static int T_7 F_92 ( void )
{
return F_93 ( & V_177 ) ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_177 ) ;
}
