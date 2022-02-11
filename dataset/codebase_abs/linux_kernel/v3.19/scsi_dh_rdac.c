static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static struct V_6 * F_3 ( struct V_2 * V_3 ,
void * V_7 , unsigned V_8 , int V_9 )
{
struct V_6 * V_10 ;
struct V_11 * V_12 = V_3 -> V_11 ;
V_10 = F_4 ( V_12 , V_9 , V_13 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_14 , V_3 ,
L_1 ) ;
return NULL ;
}
F_7 ( V_10 ) ;
if ( V_8 && F_8 ( V_12 , V_10 , V_7 , V_8 , V_13 ) ) {
F_9 ( V_10 ) ;
F_6 ( V_14 , V_3 ,
L_2 ) ;
return NULL ;
}
V_10 -> V_15 |= V_16 | V_17 |
V_18 ;
V_10 -> V_19 = V_20 ;
V_10 -> V_21 = V_22 ;
return V_10 ;
}
static struct V_6 * F_10 ( struct V_2 * V_3 ,
struct V_1 * V_23 , struct V_24 * V_25 )
{
struct V_6 * V_10 ;
struct V_26 * V_27 ;
unsigned V_28 ;
struct V_29 * V_30 ;
T_1 * V_31 ;
if ( V_23 -> V_32 -> V_33 ) {
struct V_34 * V_35 ;
V_28 = sizeof( struct V_34 ) ;
V_35 = & V_23 -> V_32 -> V_36 . V_37 ;
memset ( V_35 , 0 , V_28 ) ;
V_27 = & V_35 -> V_27 ;
V_35 -> V_38 = V_39 + 0x40 ;
V_35 -> V_40 = 0x1 ;
V_35 -> V_41 [ 0 ] = 0x01 ;
V_35 -> V_41 [ 1 ] = 0x28 ;
V_31 = V_35 -> V_31 ;
} else {
struct V_42 * V_35 ;
V_28 = sizeof( struct V_42 ) ;
V_35 = & V_23 -> V_32 -> V_36 . V_43 ;
memset ( V_35 , 0 , V_28 ) ;
V_27 = & V_35 -> V_27 ;
V_35 -> V_38 = V_39 ;
V_35 -> V_41 = 0x68 ;
V_31 = V_35 -> V_31 ;
}
V_27 -> V_44 [ 1 ] = V_45 ;
V_27 -> V_46 = V_47 ;
V_27 -> V_48 = V_49 ;
F_11 (qdata, list, entry) {
V_31 [ V_30 -> V_23 -> V_50 ] = 0x81 ;
}
V_10 = F_3 ( V_3 , & V_23 -> V_32 -> V_36 , V_28 , V_51 ) ;
if ( ! V_10 )
return NULL ;
if ( V_23 -> V_32 -> V_33 ) {
V_10 -> V_52 [ 0 ] = V_53 ;
V_10 -> V_52 [ 7 ] = V_28 >> 8 ;
V_10 -> V_52 [ 8 ] = V_28 & 0xff ;
} else {
V_10 -> V_52 [ 0 ] = V_54 ;
V_10 -> V_52 [ 4 ] = V_28 ;
}
V_10 -> V_55 = F_12 ( V_10 -> V_52 [ 0 ] ) ;
V_10 -> V_56 = V_23 -> V_56 ;
memset ( V_10 -> V_56 , 0 , V_57 ) ;
V_10 -> V_58 = 0 ;
return V_10 ;
}
static void F_13 ( struct V_59 * V_59 )
{
struct V_60 * V_32 ;
V_32 = F_2 ( V_59 , struct V_60 , V_59 ) ;
F_14 ( & V_32 -> V_61 ) ;
F_15 ( V_32 ) ;
}
static struct V_60 * F_16 ( int V_62 , char * V_63 ,
T_1 * V_64 , struct V_2 * V_3 )
{
struct V_60 * V_32 , * V_65 ;
F_11 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_65 -> V_64 , V_64 , V_66 ) == 0 ) &&
( V_65 -> V_62 == V_62 ) &&
( V_65 -> V_67 == V_3 -> V_67 ) ) {
F_17 ( & V_65 -> V_59 ) ;
return V_65 ;
}
}
V_32 = F_18 ( sizeof( * V_32 ) , V_68 ) ;
if ( ! V_32 )
return NULL ;
memcpy ( V_32 -> V_64 , V_64 , V_66 ) ;
V_32 -> V_62 = V_62 ;
V_32 -> V_67 = V_3 -> V_67 ;
memcpy ( V_32 -> V_63 , V_63 , V_69 ) ;
F_19 ( & V_32 -> V_59 ) ;
V_32 -> V_33 = - 1 ;
V_32 -> V_70 = 0 ;
V_32 -> V_71 = NULL ;
F_20 ( & V_32 -> V_72 ) ;
F_21 ( & V_32 -> V_73 , V_74 ) ;
F_22 ( & V_32 -> V_75 ) ;
F_23 ( & V_32 -> V_61 , & V_76 ) ;
return V_32 ;
}
static int F_24 ( struct V_2 * V_3 , int V_38 ,
unsigned int V_77 , struct V_1 * V_23 )
{
struct V_6 * V_10 ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_78 = V_79 ;
V_10 = F_3 ( V_3 , & V_23 -> V_80 , V_77 , V_81 ) ;
if ( ! V_10 )
goto V_82;
V_10 -> V_52 [ 0 ] = V_83 ;
V_10 -> V_52 [ 1 ] = 1 ;
V_10 -> V_52 [ 2 ] = V_38 ;
V_10 -> V_52 [ 4 ] = V_77 ;
V_10 -> V_55 = F_12 ( V_83 ) ;
V_10 -> V_56 = V_23 -> V_56 ;
memset ( V_10 -> V_56 , 0 , V_57 ) ;
V_10 -> V_58 = 0 ;
V_78 = F_25 ( V_12 , NULL , V_10 , 1 ) ;
if ( V_78 == - V_84 )
V_78 = V_85 ;
F_9 ( V_10 ) ;
V_82:
return V_78 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_1 * V_23 ,
char * V_63 , T_1 * V_64 )
{
int V_78 , V_86 ;
struct V_87 * V_88 ;
V_78 = F_24 ( V_3 , 0xC8 , sizeof( struct V_87 ) , V_23 ) ;
if ( V_78 == V_89 ) {
V_88 = & V_23 -> V_80 . V_90 ;
if ( V_88 -> V_38 != 0xc8 )
return V_91 ;
if ( V_88 -> V_92 [ 0 ] != 'e' || V_88 -> V_92 [ 1 ] != 'd' ||
V_88 -> V_92 [ 2 ] != 'i' || V_88 -> V_92 [ 3 ] != 'd' )
return V_91 ;
V_23 -> V_50 = V_88 -> V_50 [ 7 ] ;
for( V_86 = 0 ; V_86 < V_69 - 1 ; ++ V_86 )
* ( V_63 + V_86 ) = V_88 -> V_93 [ ( 2 * V_86 ) + 1 ] ;
* ( V_63 + V_69 - 1 ) = '\0' ;
memset ( V_64 , 0 , V_66 ) ;
memcpy ( V_64 , V_88 -> V_94 , V_88 -> V_95 ) ;
}
return V_78 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_1 * V_23 )
{
int V_78 ;
struct V_96 * V_88 ;
V_23 -> V_97 = V_98 ;
V_78 = F_24 ( V_3 , 0xC9 , sizeof( struct V_96 ) , V_23 ) ;
if ( V_78 == V_89 ) {
V_88 = & V_23 -> V_80 . V_99 ;
if ( ( V_88 -> V_100 >> 5 ) & 0x1 )
V_23 -> V_101 = V_102 ;
else if ( V_88 -> V_100 >> 7 )
V_23 -> V_101 = V_103 ;
else
V_23 -> V_101 = V_104 ;
if ( V_88 -> V_100 & 0x1 )
V_23 -> V_105 = V_106 ;
else {
V_23 -> V_105 = V_107 ;
if ( V_23 -> V_101 == V_104 )
V_23 -> V_97 = V_108 ;
}
if ( V_88 -> V_109 & 0x1 )
V_23 -> V_110 = V_111 ;
else
V_23 -> V_110 = V_112 ;
}
return V_78 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * V_23 , char * V_63 , T_1 * V_64 )
{
int V_78 , V_62 ;
struct V_113 * V_88 ;
V_78 = F_24 ( V_3 , 0xC4 , sizeof( struct V_113 ) , V_23 ) ;
if ( V_78 == V_89 ) {
V_88 = & V_23 -> V_80 . V_114 ;
if ( V_88 -> V_115 [ 1 ] == 0x31 )
V_62 = 0 ;
else
V_62 = 1 ;
F_29 ( & V_116 ) ;
V_23 -> V_32 = F_16 ( V_62 , V_63 , V_64 , V_3 ) ;
if ( ! V_23 -> V_32 )
V_78 = V_79 ;
F_30 ( & V_116 ) ;
}
return V_78 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_23 )
{
int V_78 ;
struct V_117 * V_88 ;
V_78 = F_24 ( V_3 , 0xC2 , sizeof( struct V_117 ) , V_23 ) ;
if ( V_78 == V_89 ) {
V_88 = & V_23 -> V_80 . V_118 ;
if ( V_88 -> V_119 >= V_120 )
V_23 -> V_32 -> V_33 = 1 ;
else
V_23 -> V_32 -> V_33 = 0 ;
}
return V_78 ;
}
static int F_32 ( struct V_2 * V_3 ,
unsigned char * V_121 )
{
struct V_122 V_123 ;
int V_78 = V_85 , V_124 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
V_124 = F_33 ( V_121 , V_57 , & V_123 ) ;
if ( ! V_124 )
goto V_82;
switch ( V_123 . V_125 ) {
case V_126 :
case V_127 :
case V_128 :
V_78 = V_129 ;
break;
case V_130 :
if ( V_123 . V_131 == 0x04 && V_123 . V_132 == 0x01 )
V_78 = V_129 ;
break;
case V_133 :
if ( V_123 . V_131 == 0x91 && V_123 . V_132 == 0x36 )
V_78 = V_129 ;
break;
default:
break;
}
F_34 ( V_134 , V_3 , L_3
L_4 ,
( char * ) V_23 -> V_32 -> V_63 , V_23 -> V_32 -> V_62 ,
V_123 . V_125 , V_123 . V_131 , V_123 . V_132 ) ;
V_82:
return V_78 ;
}
static void V_74 ( struct V_135 * V_136 )
{
struct V_60 * V_32 =
F_2 ( V_136 , struct V_60 , V_73 ) ;
struct V_6 * V_10 ;
struct V_2 * V_3 = V_32 -> V_71 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_78 , V_137 = V_138 ;
struct V_29 * V_65 , * V_30 ;
F_35 ( V_25 ) ;
F_29 ( & V_32 -> V_72 ) ;
F_36 ( & V_32 -> V_75 , & V_25 ) ;
V_32 -> V_70 = 0 ;
V_32 -> V_71 = NULL ;
F_30 ( & V_32 -> V_72 ) ;
V_139:
V_78 = V_79 ;
V_10 = F_10 ( V_3 , V_23 , & V_25 ) ;
if ( ! V_10 )
goto V_82;
F_34 ( V_134 , V_3 , L_3
L_5 ,
( char * ) V_23 -> V_32 -> V_63 , V_23 -> V_32 -> V_62 ,
( V_137 == V_138 ) ? L_6 : L_7 ) ;
V_78 = F_25 ( V_12 , NULL , V_10 , 1 ) ;
F_9 ( V_10 ) ;
if ( V_78 != V_89 ) {
V_78 = F_32 ( V_3 , V_23 -> V_56 ) ;
if ( V_78 == V_129 && V_137 -- )
goto V_139;
}
if ( V_78 == V_89 ) {
V_23 -> V_97 = V_98 ;
F_34 ( V_134 , V_3 , L_3
L_8 ,
( char * ) V_23 -> V_32 -> V_63 , V_23 -> V_32 -> V_62 ) ;
}
V_82:
F_37 (qdata, tmp, &list, entry) {
F_14 ( & V_30 -> V_140 ) ;
if ( V_78 == V_89 )
V_30 -> V_23 -> V_97 = V_98 ;
if ( V_30 -> V_141 )
V_30 -> V_141 ( V_30 -> V_142 , V_78 ) ;
F_15 ( V_30 ) ;
}
return;
}
static int F_38 ( struct V_2 * V_3 ,
T_2 V_143 , void * V_144 )
{
struct V_29 * V_30 ;
struct V_60 * V_32 ;
V_30 = F_39 ( sizeof( * V_30 ) , V_145 ) ;
if ( ! V_30 )
return V_129 ;
V_30 -> V_23 = F_1 ( V_3 ) ;
V_30 -> V_141 = V_143 ;
V_30 -> V_142 = V_144 ;
V_32 = V_30 -> V_23 -> V_32 ;
F_29 ( & V_32 -> V_72 ) ;
F_40 ( & V_30 -> V_140 , & V_32 -> V_75 ) ;
if ( ! V_32 -> V_70 ) {
V_32 -> V_70 = 1 ;
V_32 -> V_71 = V_3 ;
F_41 ( V_146 , & V_32 -> V_73 ) ;
}
F_30 ( & V_32 -> V_72 ) ;
return V_89 ;
}
static int F_42 ( struct V_2 * V_3 ,
T_2 V_143 , void * V_144 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
int V_78 = V_89 ;
int V_147 = 0 ;
V_78 = F_27 ( V_3 , V_23 ) ;
if ( V_78 != V_89 )
goto V_82;
switch ( V_23 -> V_101 ) {
case V_104 :
if ( V_23 -> V_105 == V_107 )
V_147 = 1 ;
break;
case V_102 :
if ( ( V_23 -> V_105 == V_107 ) &&
( V_23 -> V_110 == V_111 ) )
V_147 = 1 ;
break;
default:
break;
}
if ( V_147 ) {
V_78 = F_38 ( V_3 , V_143 , V_144 ) ;
if ( V_78 == V_89 )
return 0 ;
}
V_82:
if ( V_143 )
V_143 ( V_144 , V_78 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_6 * V_148 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
int V_124 = V_149 ;
if ( V_23 -> V_97 != V_98 ) {
V_124 = V_150 ;
V_148 -> V_15 |= V_151 ;
}
return V_124 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_122 * V_123 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_34 ( V_152 , V_3 , L_3
L_9 ,
( char * ) V_23 -> V_32 -> V_63 , V_23 -> V_32 -> V_62 ,
V_123 -> V_125 , V_123 -> V_131 , V_123 -> V_132 ) ;
switch ( V_123 -> V_125 ) {
case V_130 :
if ( V_123 -> V_131 == 0x04 && V_123 -> V_132 == 0x01 )
return V_153 ;
if ( V_123 -> V_131 == 0x04 && V_123 -> V_132 == 0x81 )
return V_154 ;
if ( V_123 -> V_131 == 0x04 && V_123 -> V_132 == 0xA1 )
return V_153 ;
if ( V_123 -> V_131 == 0xA1 && V_123 -> V_132 == 0x02 )
return V_153 ;
break;
case V_133 :
if ( V_123 -> V_131 == 0x94 && V_123 -> V_132 == 0x01 ) {
V_23 -> V_97 = V_108 ;
return V_154 ;
}
break;
case V_128 :
if ( V_123 -> V_131 == 0x29 && V_123 -> V_132 == 0x00 )
return V_153 ;
if ( V_123 -> V_131 == 0x8b && V_123 -> V_132 == 0x02 )
return V_153 ;
break;
}
return V_155 ;
}
static bool F_45 ( struct V_2 * V_3 )
{
int V_86 ;
if ( F_46 ( V_3 ) )
return false ;
for ( V_86 = 0 ; V_156 [ V_86 ] . V_157 ; V_86 ++ ) {
if ( ! strncmp ( V_3 -> V_157 , V_156 [ V_86 ] . V_157 ,
strlen ( V_156 [ V_86 ] . V_157 ) ) &&
! strncmp ( V_3 -> V_158 , V_156 [ V_86 ] . V_158 ,
strlen ( V_156 [ V_86 ] . V_158 ) ) ) {
return true ;
}
}
return false ;
}
static struct V_4 * F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_23 ;
int V_78 ;
char V_63 [ V_69 ] ;
char V_64 [ V_66 ] ;
V_23 = F_39 ( sizeof( * V_23 ) , V_145 ) ;
if ( ! V_23 )
return F_48 ( - V_159 ) ;
V_23 -> V_50 = V_160 ;
V_23 -> V_97 = V_98 ;
V_78 = F_26 ( V_3 , V_23 , V_63 , V_64 ) ;
if ( V_78 != V_89 )
goto V_161;
V_78 = F_28 ( V_3 , V_23 , V_63 , V_64 ) ;
if ( V_78 != V_89 )
goto V_161;
V_78 = F_27 ( V_3 , V_23 ) ;
if ( V_78 != V_89 )
goto V_162;
V_78 = F_31 ( V_3 , V_23 ) ;
if ( V_78 != V_89 )
goto V_162;
F_6 ( V_163 , V_3 ,
L_10 ,
V_164 , V_23 -> V_50 , V_101 [ ( int ) V_23 -> V_101 ] ,
V_105 [ ( int ) V_23 -> V_105 ] ) ;
return & V_23 -> V_5 ;
V_162:
F_29 ( & V_116 ) ;
F_49 ( & V_23 -> V_32 -> V_59 , F_13 ) ;
F_30 ( & V_116 ) ;
V_161:
F_15 ( V_23 ) ;
return F_48 ( - V_165 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
if ( V_23 -> V_32 && V_23 -> V_32 -> V_70 )
F_51 ( V_146 ) ;
F_29 ( & V_116 ) ;
if ( V_23 -> V_32 )
F_49 ( & V_23 -> V_32 -> V_59 , F_13 ) ;
F_30 ( & V_116 ) ;
F_15 ( V_23 ) ;
}
static int T_3 F_52 ( void )
{
int V_166 ;
V_166 = F_53 ( & V_167 ) ;
if ( V_166 != 0 ) {
F_54 ( V_168 L_11 ) ;
goto V_82;
}
V_146 = F_55 ( L_12 ) ;
if ( ! V_146 ) {
F_56 ( & V_167 ) ;
F_54 ( V_168 L_13 ) ;
V_166 = - V_165 ;
}
V_82:
return V_166 ;
}
static void T_4 F_57 ( void )
{
F_58 ( V_146 ) ;
F_56 ( & V_167 ) ;
}
