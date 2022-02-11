static int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , 0 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_4 ( V_1 ,
struct V_2 , V_4 ) ;
F_5 ( V_5 , V_3 ) ;
}
static int F_6 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
F_7 ( V_7 , L_1 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
return 1 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_2 * V_3 =
F_4 ( V_15 , struct V_2 , V_15 ) ;
struct V_1 * V_1 = & V_3 -> V_4 ;
struct V_16 * V_17 = V_3 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = NULL ;
T_1 V_26 = 0 , V_27 ;
int V_28 ;
V_21 = * (struct V_20 * * ) F_10 ( V_17 -> V_10 -> V_9 ) ;
V_23 = & V_21 -> V_29 [ V_17 -> V_10 -> V_30 ] ;
if ( ! V_23 -> V_21 ) {
F_11 ( V_17 , V_31 ) ;
goto V_32;
}
if ( V_23 -> V_33 == V_34 ) {
F_11 ( V_17 , V_35 ) ;
goto V_32;
}
V_19 = V_23 -> V_19 ;
if ( ! V_19 ) {
F_12 ( V_36 , V_17 , L_2
L_3 ) ;
F_11 ( V_17 , V_37 ) ;
goto V_32;
}
if ( F_13 ( V_17 ) ) {
struct V_38 * V_39 = F_14 ( V_17 ) ;
V_25 = V_39 -> V_40 . V_41 ;
V_26 = V_39 -> V_40 . V_42 ;
V_1 -> V_43 |= V_44 ;
}
V_27 = F_15 ( V_17 ) ;
if ( ! F_16 ( V_17 ) &&
F_17 ( V_17 ) != V_45 ) {
V_1 -> V_46 = true ;
V_27 = F_18 ( V_17 ) ;
}
V_1 -> V_47 = V_3 -> V_48 ;
V_28 = F_19 ( V_1 , V_19 -> V_49 , V_17 -> V_50 ,
& V_3 -> V_51 [ 0 ] , V_3 -> V_17 -> V_10 -> V_52 ,
V_27 , V_53 ,
V_17 -> V_54 , 0 ,
F_20 ( V_17 ) , F_21 ( V_17 ) ,
V_25 , V_26 ,
F_22 ( V_17 ) , F_16 ( V_17 ) ) ;
if ( V_28 < 0 ) {
F_11 ( V_17 , V_31 ) ;
goto V_32;
}
return;
V_32:
F_5 ( V_5 , V_3 ) ;
V_17 -> V_55 ( V_17 ) ;
return;
}
static int F_23 ( struct V_8 * V_56 , struct V_16 * V_17 )
{
struct V_2 * V_3 ;
F_24 ( L_4
L_5 , V_17 -> V_10 -> V_9 -> V_57 ,
V_17 -> V_10 -> V_30 , V_17 -> V_10 -> V_58 , V_17 -> V_10 -> V_52 ,
V_17 -> V_50 [ 0 ] , F_18 ( V_17 ) ) ;
V_3 = F_25 ( V_5 , V_59 ) ;
if ( ! V_3 ) {
F_26 ( L_6 ) ;
F_11 ( V_17 , V_37 ) ;
V_17 -> V_55 ( V_17 ) ;
return 0 ;
}
V_3 -> V_17 = V_17 ;
V_3 -> V_48 = V_17 -> V_60 -> V_47 ;
F_27 ( & V_3 -> V_15 , F_9 ) ;
F_28 ( V_61 , & V_3 -> V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 ,
T_2 V_52 , int V_62 , enum V_63 V_64 )
{
struct V_1 * V_1 = NULL ;
struct V_65 * V_49 ;
struct V_18 * V_19 ;
struct V_2 * V_3 = NULL ;
int V_66 = V_67 , V_28 ;
V_19 = V_23 -> V_19 ;
if ( ! V_19 ) {
F_26 ( L_7
L_8 ) ;
return V_66 ;
}
V_3 = F_25 ( V_5 , V_68 ) ;
if ( ! V_3 ) {
F_26 ( L_9 ) ;
return V_66 ;
}
F_30 ( & V_3 -> V_69 ) ;
V_1 = & V_3 -> V_4 ;
V_49 = V_23 -> V_19 -> V_49 ;
V_28 = F_31 ( V_1 , V_49 , V_3 -> V_51 , V_52 ,
NULL , V_64 , V_68 , V_62 ,
V_70 ) ;
if ( V_28 < 0 )
goto V_71;
F_32 ( & V_3 -> V_69 ) ;
V_66 = V_1 -> V_72 -> V_73 ;
F_33 ( V_1 ) ;
V_74:
return V_66 ;
V_71:
if ( V_1 )
F_2 ( V_1 , 0 ) ;
else
F_5 ( V_5 , V_3 ) ;
goto V_74;
}
static int F_34 ( struct V_16 * V_17 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_66 = V_75 ;
V_21 = * (struct V_20 * * ) F_10 ( V_17 -> V_10 -> V_9 ) ;
V_23 = & V_21 -> V_29 [ V_17 -> V_10 -> V_30 ] ;
V_66 = F_29 ( V_23 , V_17 -> V_10 -> V_52 ,
V_17 -> V_60 -> V_47 , V_76 ) ;
return ( V_66 == V_77 ) ? V_78 : V_75 ;
}
static int F_35 ( struct V_16 * V_17 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_66 = V_75 ;
V_21 = * (struct V_20 * * ) F_10 ( V_17 -> V_10 -> V_9 ) ;
V_23 = & V_21 -> V_29 [ V_17 -> V_10 -> V_30 ] ;
V_66 = F_29 ( V_23 , V_17 -> V_10 -> V_52 ,
0 , V_79 ) ;
return ( V_66 == V_77 ) ? V_78 : V_75 ;
}
static int F_36 ( struct V_16 * V_17 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_21 = * (struct V_20 * * ) F_10 ( V_17 -> V_10 -> V_9 ) ;
if ( ! V_21 ) {
F_26 ( L_7
L_8 ) ;
return V_75 ;
}
V_23 = & V_21 -> V_29 [ V_17 -> V_10 -> V_30 ] ;
if ( V_23 ) {
V_23 -> V_33 = V_80 ;
return V_78 ;
}
return V_75 ;
}
static int F_37 ( struct V_81 * V_82 )
{
F_38 ( V_83 , & V_82 -> V_84 -> V_85 ) ;
return 0 ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_20 * V_21 ;
struct V_8 * V_56 ;
int error , V_86 ;
V_21 = F_40 ( V_11 ) ;
V_56 = F_41 ( & V_87 ,
sizeof( struct V_20 ) ) ;
if ( ! V_56 ) {
F_26 ( L_10 ) ;
return - V_88 ;
}
V_21 -> V_56 = V_56 ;
* ( (struct V_20 * * ) V_56 -> V_89 ) = V_21 ;
V_56 -> V_90 = 2 ;
V_56 -> V_91 = 0 ;
V_56 -> V_92 = 0 ;
V_56 -> V_93 = V_94 ;
V_86 = V_95 | V_96 |
V_97 | V_98 |
V_99 | V_100 ;
F_42 ( V_56 , V_86 ) ;
F_43 ( V_56 , V_101 ) ;
error = F_44 ( V_56 , & V_21 -> V_11 ) ;
if ( error ) {
F_26 ( L_11 , V_102 ) ;
F_45 ( V_56 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_46 ( struct V_10 * V_11 )
{
struct V_20 * V_21 ;
struct V_8 * V_56 ;
V_21 = F_40 ( V_11 ) ;
V_56 = V_21 -> V_56 ;
F_47 ( V_56 ) ;
F_45 ( V_56 ) ;
return 0 ;
}
static void F_48 ( struct V_10 * V_11 )
{
struct V_20 * V_21 = F_40 ( V_11 ) ;
F_49 ( V_21 ) ;
}
static int F_50 ( struct V_20 * V_21 , int V_103 )
{
int V_66 ;
V_21 -> V_11 . V_104 = & V_105 ;
V_21 -> V_11 . V_106 = V_107 ;
V_21 -> V_11 . V_71 = & F_48 ;
F_51 ( & V_21 -> V_11 , L_12 , V_103 ) ;
V_66 = F_52 ( & V_21 -> V_11 ) ;
if ( V_66 ) {
F_26 ( L_13
L_14 , V_66 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_53 ( void )
{
int V_66 ;
V_107 = F_54 ( L_15 ) ;
if ( F_55 ( V_107 ) ) {
F_26 ( L_16 ) ;
return F_56 ( V_107 ) ;
}
V_66 = F_57 ( & V_105 ) ;
if ( V_66 ) {
F_26 ( L_17 ) ;
goto V_108;
}
V_66 = F_58 ( & V_109 ) ;
if ( V_66 ) {
F_26 ( L_18
L_19 ) ;
goto V_110;
}
F_24 ( L_20 ) ;
return V_66 ;
V_110:
F_59 ( & V_105 ) ;
V_108:
F_60 ( V_107 ) ;
return V_66 ;
}
static void F_61 ( void )
{
F_62 ( & V_109 ) ;
F_59 ( & V_105 ) ;
F_60 ( V_107 ) ;
F_24 ( L_21 ) ;
}
static char * F_63 ( void )
{
return L_22 ;
}
static inline struct V_22 * V_23 ( struct V_111 * V_112 )
{
return F_4 ( V_112 , struct V_22 , V_113 ) ;
}
static char * F_64 ( struct V_111 * V_112 )
{
return & V_23 ( V_112 ) -> V_21 -> V_114 [ 0 ] ;
}
static T_3 F_65 ( struct V_111 * V_112 )
{
return V_23 ( V_112 ) -> V_115 ;
}
static int F_66 ( struct V_111 * V_112 )
{
return 1 ;
}
static int F_67 ( struct V_111 * V_112 )
{
return 0 ;
}
static int F_68 ( struct V_111 * V_112 )
{
return 0 ;
}
static int F_69 ( struct V_111 * V_112 )
{
return 0 ;
}
static int F_70 ( struct V_111 * V_112 )
{
struct V_22 * V_23 = F_4 ( V_112 , struct V_22 ,
V_113 ) ;
return V_23 -> V_116 ;
}
static T_1 F_71 ( struct V_111 * V_112 )
{
return 1 ;
}
static T_1 F_72 ( struct V_65 * V_49 )
{
return 1 ;
}
static void F_73 ( struct V_117 * V_118 )
{
return;
}
static int F_74 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_4 ( V_1 ,
struct V_2 , V_4 ) ;
return V_3 -> V_119 ;
}
static int F_75 ( struct V_1 * V_1 )
{
F_76 ( V_1 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_78 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_4 ( V_1 ,
struct V_2 , V_4 ) ;
struct V_16 * V_17 = V_3 -> V_17 ;
F_24 ( L_23
L_24 , V_17 , V_17 -> V_50 [ 0 ] ) ;
V_17 -> V_120 = V_121 ;
F_11 ( V_17 , V_122 ) ;
if ( ( V_1 -> V_43 & V_123 ) ||
( V_1 -> V_43 & V_124 ) )
F_79 ( V_17 , V_1 -> V_125 ) ;
V_17 -> V_55 ( V_17 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_4 ( V_1 ,
struct V_2 , V_4 ) ;
struct V_16 * V_17 = V_3 -> V_17 ;
F_24 ( L_25
L_24 , V_17 , V_17 -> V_50 [ 0 ] ) ;
if ( V_1 -> V_126 &&
( ( V_1 -> V_43 & V_127 ) ||
( V_1 -> V_43 & V_128 ) ) ) {
memcpy ( V_17 -> V_126 , V_1 -> V_126 ,
V_129 ) ;
V_17 -> V_120 = V_130 ;
F_81 ( V_17 , V_131 ) ;
} else
V_17 -> V_120 = V_1 -> V_132 ;
F_11 ( V_17 , V_122 ) ;
if ( ( V_1 -> V_43 & V_123 ) ||
( V_1 -> V_43 & V_124 ) )
F_79 ( V_17 , V_1 -> V_125 ) ;
V_17 -> V_55 ( V_17 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_4 ( V_1 ,
struct V_2 , V_4 ) ;
F_83 ( & V_3 -> V_69 ) ;
}
static void F_84 ( struct V_1 * V_1 )
{
return;
}
static char * F_85 ( struct V_20 * V_21 )
{
switch ( V_21 -> V_133 ) {
case V_134 :
return L_26 ;
case V_135 :
return L_27 ;
case V_136 :
return L_28 ;
default:
break;
}
return L_29 ;
}
static int F_86 (
struct V_111 * V_112 ,
struct V_137 * V_52 )
{
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
struct V_20 * V_21 = V_23 -> V_21 ;
F_87 ( & V_23 -> V_138 ) ;
F_88 ( V_21 -> V_56 , 0 , V_23 -> V_115 , V_52 -> V_139 ) ;
F_24 ( L_30 ) ;
return 0 ;
}
static void F_89 (
struct V_111 * V_112 ,
struct V_137 * V_137 )
{
struct V_81 * V_82 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_23 = F_4 ( V_112 , struct V_22 , V_113 ) ;
V_21 = V_23 -> V_21 ;
V_82 = F_90 ( V_21 -> V_56 , 0 , V_23 -> V_115 ,
V_137 -> V_139 ) ;
if ( ! V_82 ) {
F_26 ( L_31
L_32 , 0 , V_23 -> V_115 , V_137 -> V_139 ) ;
return;
}
F_91 ( V_82 ) ;
F_92 ( V_82 ) ;
F_93 ( & V_23 -> V_138 ) ;
F_24 ( L_33 ) ;
}
static T_4 F_94 (
struct V_140 * V_141 , char * V_142 )
{
struct V_111 * V_112 = F_95 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 , struct V_22 ,
V_113 ) ;
return sprintf ( V_142 , L_34 , V_23 -> V_116 ) ;
}
static T_4 F_96 (
struct V_140 * V_141 , const char * V_142 , T_5 V_143 )
{
struct V_111 * V_112 = F_95 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 , struct V_22 ,
V_113 ) ;
unsigned long V_144 ;
int V_66 = F_97 ( V_142 , 0 , & V_144 ) ;
if ( V_66 ) {
F_26 ( L_35 , V_66 ) ;
return V_66 ;
}
if ( V_144 != 0 && V_144 != 1 && V_144 != 3 ) {
F_26 ( L_36 , V_144 ) ;
return - V_145 ;
}
V_23 -> V_116 = V_144 ;
return V_143 ;
}
static int F_98 ( struct V_111 * V_112 ,
struct V_65 * V_49 , void * V_146 )
{
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
V_23 -> V_19 = V_146 ;
return 0 ;
}
static int F_99 (
struct V_22 * V_23 ,
const char * V_147 )
{
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_18 * V_19 ;
int V_66 ;
if ( V_23 -> V_19 ) {
F_24 ( L_37 ) ;
return - V_148 ;
}
V_19 = F_100 ( sizeof( struct V_18 ) , V_68 ) ;
if ( ! V_19 ) {
F_26 ( L_38 ) ;
return - V_149 ;
}
V_19 -> V_49 = F_101 ( & V_23 -> V_113 , 0 , 0 ,
V_150 | V_151 ,
V_147 , V_19 , F_98 ) ;
if ( F_55 ( V_19 -> V_49 ) ) {
V_66 = F_56 ( V_19 -> V_49 ) ;
F_49 ( V_19 ) ;
return V_66 ;
}
F_24 ( L_39
L_40 , F_85 ( V_21 ) ,
V_147 ) ;
return 0 ;
}
static int F_102 (
struct V_22 * V_152 )
{
struct V_65 * V_49 ;
struct V_18 * V_19 ;
V_19 = V_152 -> V_19 ;
if ( ! V_19 )
return - V_88 ;
V_49 = V_19 -> V_49 ;
if ( ! V_49 )
return - V_88 ;
if ( F_103 ( & V_152 -> V_138 ) ) {
F_26 ( L_41
L_42 ,
F_103 ( & V_152 -> V_138 ) ) ;
return - V_153 ;
}
F_24 ( L_43
L_40 , F_85 ( V_152 -> V_21 ) ,
V_19 -> V_49 -> V_117 -> V_154 ) ;
F_104 ( V_19 -> V_49 ) ;
V_152 -> V_19 = NULL ;
F_49 ( V_19 ) ;
return 0 ;
}
static T_4 F_105 ( struct V_140 * V_141 , char * V_142 )
{
struct V_111 * V_112 = F_106 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
struct V_18 * V_19 ;
T_4 V_66 ;
V_19 = V_23 -> V_19 ;
if ( ! V_19 )
return - V_88 ;
V_66 = snprintf ( V_142 , V_155 , L_44 ,
V_19 -> V_49 -> V_117 -> V_154 ) ;
return V_66 ;
}
static T_4 F_107 ( struct V_140 * V_141 ,
const char * V_142 , T_5 V_143 )
{
struct V_111 * V_112 = F_106 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
struct V_20 * V_21 = V_23 -> V_21 ;
unsigned char V_156 [ V_157 ] , * V_158 , * V_159 ;
int V_66 ;
if ( ! strncmp ( V_142 , L_45 , 4 ) ) {
V_66 = F_102 ( V_23 ) ;
return ( ! V_66 ) ? V_143 : V_66 ;
}
if ( strlen ( V_142 ) >= V_157 ) {
F_26 ( L_46
L_47 , V_142 , V_157 ) ;
return - V_145 ;
}
snprintf ( & V_156 [ 0 ] , V_157 , L_48 , V_142 ) ;
V_158 = strstr ( V_156 , L_49 ) ;
if ( V_158 ) {
if ( V_21 -> V_133 != V_134 ) {
F_26 ( L_50
L_51 , V_156 ,
F_85 ( V_21 ) ) ;
return - V_145 ;
}
V_159 = & V_156 [ 0 ] ;
goto V_160;
}
V_158 = strstr ( V_156 , L_52 ) ;
if ( V_158 ) {
if ( V_21 -> V_133 != V_135 ) {
F_26 ( L_53
L_51 , V_156 ,
F_85 ( V_21 ) ) ;
return - V_145 ;
}
V_159 = & V_156 [ 3 ] ;
goto V_160;
}
V_158 = strstr ( V_156 , L_54 ) ;
if ( V_158 ) {
if ( V_21 -> V_133 != V_136 ) {
F_26 ( L_55
L_51 , V_156 ,
F_85 ( V_21 ) ) ;
return - V_145 ;
}
V_159 = & V_156 [ 0 ] ;
goto V_160;
}
F_26 ( L_56
L_57 , V_156 ) ;
return - V_145 ;
V_160:
if ( V_156 [ strlen ( V_156 ) - 1 ] == '\n' )
V_156 [ strlen ( V_156 ) - 1 ] = '\0' ;
V_66 = F_99 ( V_23 , V_159 ) ;
if ( V_66 < 0 )
return V_66 ;
return V_143 ;
}
static T_4 F_108 ( struct V_140 * V_141 ,
char * V_142 )
{
struct V_111 * V_112 = F_106 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
const char * V_161 = NULL ;
T_4 V_66 = - V_145 ;
switch ( V_23 -> V_33 ) {
case V_80 :
V_161 = L_58 ;
break;
case V_34 :
V_161 = L_59 ;
break;
default:
break;
}
if ( V_161 )
V_66 = snprintf ( V_142 , V_155 , L_44 , V_161 ) ;
return V_66 ;
}
static T_4 F_109 ( struct V_140 * V_141 ,
const char * V_142 , T_5 V_143 )
{
struct V_111 * V_112 = F_106 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
if ( ! strncmp ( V_142 , L_58 , 6 ) ) {
V_23 -> V_33 = V_80 ;
return V_143 ;
}
if ( ! strncmp ( V_142 , L_59 , 7 ) ) {
V_23 -> V_33 = V_34 ;
if ( V_23 -> V_19 ) {
struct V_65 * V_162 = V_23 -> V_19 -> V_49 ;
F_110 ( V_162 -> V_117 ) ;
}
return V_143 ;
}
return - V_145 ;
}
static T_4 F_111 ( struct V_140 * V_141 ,
char * V_142 )
{
struct V_111 * V_112 = F_106 ( V_141 ) ;
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
struct V_20 * V_21 = V_23 -> V_21 ;
return snprintf ( V_142 , V_155 , L_60 ,
V_21 -> V_56 -> V_57 , V_23 -> V_115 ) ;
}
static struct V_111 * F_112 (
struct V_163 * V_164 ,
struct V_165 * V_166 ,
const char * V_147 )
{
struct V_20 * V_21 = F_4 ( V_164 ,
struct V_20 , V_167 ) ;
struct V_22 * V_23 ;
int V_66 ;
unsigned long V_168 ;
if ( strstr ( V_147 , L_61 ) != V_147 ) {
F_26 ( L_62
L_63 ) ;
return F_113 ( - V_145 ) ;
}
if ( F_97 ( V_147 + 5 , 10 , & V_168 ) )
return F_113 ( - V_145 ) ;
if ( V_168 >= V_169 ) {
F_26 ( L_64
L_65 , V_168 , V_169 ) ;
return F_113 ( - V_145 ) ;
}
V_23 = & V_21 -> V_29 [ V_168 ] ;
V_23 -> V_21 = V_21 ;
V_23 -> V_115 = V_168 ;
V_66 = F_114 ( V_164 , & V_23 -> V_113 , V_21 -> V_133 ) ;
if ( V_66 < 0 )
return F_113 ( - V_149 ) ;
F_24 ( L_66
L_67 , F_85 ( V_21 ) ,
F_115 ( & V_164 -> V_170 . V_171 ) , V_168 ) ;
return & V_23 -> V_113 ;
}
static void F_116 (
struct V_111 * V_112 )
{
struct V_163 * V_164 = V_112 -> V_172 ;
struct V_22 * V_23 = F_4 ( V_112 ,
struct V_22 , V_113 ) ;
struct V_20 * V_21 ;
unsigned short V_168 ;
V_21 = V_23 -> V_21 ;
V_168 = V_23 -> V_115 ;
F_102 ( V_23 ) ;
F_117 ( V_112 ) ;
V_23 -> V_21 = NULL ;
V_23 -> V_115 = 0 ;
F_24 ( L_68
L_69 , F_85 ( V_21 ) ,
F_115 ( & V_164 -> V_170 . V_171 ) , V_168 ) ;
}
static struct V_163 * F_118 (
struct V_173 * V_174 ,
struct V_165 * V_166 ,
const char * V_147 )
{
struct V_20 * V_21 ;
struct V_8 * V_56 ;
char * V_158 ;
int V_66 , V_175 = 0 ;
V_21 = F_100 ( sizeof( struct V_20 ) , V_68 ) ;
if ( ! V_21 ) {
F_26 ( L_70 ) ;
return F_113 ( - V_149 ) ;
}
V_158 = strstr ( V_147 , L_49 ) ;
if ( V_158 ) {
V_21 -> V_133 = V_134 ;
goto V_176;
}
V_158 = strstr ( V_147 , L_52 ) ;
if ( V_158 ) {
V_21 -> V_133 = V_135 ;
V_175 = 3 ;
goto V_176;
}
V_158 = strstr ( V_147 , L_54 ) ;
if ( ! V_158 ) {
F_26 ( L_71
L_72 , V_147 ) ;
V_66 = - V_145 ;
goto V_74;
}
V_21 -> V_133 = V_136 ;
V_176:
if ( strlen ( V_147 ) >= V_157 ) {
F_26 ( L_73
L_47 , V_147 , F_85 ( V_21 ) ,
V_157 ) ;
V_66 = - V_145 ;
goto V_74;
}
snprintf ( & V_21 -> V_114 [ 0 ] , V_157 , L_48 , & V_147 [ V_175 ] ) ;
V_66 = F_50 ( V_21 , V_177 ) ;
if ( V_66 )
goto V_74;
V_56 = V_21 -> V_56 ;
V_177 ++ ;
F_24 ( L_74
L_75 ,
F_85 ( V_21 ) , V_147 , V_56 -> V_57 ) ;
return & V_21 -> V_167 ;
V_74:
F_49 ( V_21 ) ;
return F_113 ( V_66 ) ;
}
static void F_119 (
struct V_163 * V_164 )
{
struct V_20 * V_21 = F_4 ( V_164 ,
struct V_20 , V_167 ) ;
F_24 ( L_76
L_75 ,
F_85 ( V_21 ) , V_21 -> V_114 ,
V_21 -> V_56 -> V_57 ) ;
F_120 ( & V_21 -> V_11 ) ;
}
static T_4 F_121 ( struct V_140 * V_141 , char * V_142 )
{
return sprintf ( V_142 , L_77 , V_178 ) ;
}
static int T_6 F_122 ( void )
{
int V_66 = - V_149 ;
V_61 = F_123 ( L_78 , 0 , 0 ) ;
if ( ! V_61 )
goto V_74;
V_5 = F_124 ( L_79 ,
sizeof( struct V_2 ) ,
F_125 ( struct V_2 ) ,
0 , NULL ) ;
if ( ! V_5 ) {
F_24 ( L_80
L_81 ) ;
goto V_179;
}
V_66 = F_53 () ;
if ( V_66 )
goto V_180;
V_66 = F_126 ( & V_181 ) ;
if ( V_66 )
goto V_182;
return 0 ;
V_182:
F_61 () ;
V_180:
F_127 ( V_5 ) ;
V_179:
F_128 ( V_61 ) ;
V_74:
return V_66 ;
}
static void T_7 F_129 ( void )
{
F_130 ( & V_181 ) ;
F_61 () ;
F_127 ( V_5 ) ;
F_128 ( V_61 ) ;
}
