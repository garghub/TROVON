static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
F_2 ( V_4 == NULL ) ;
return ( (struct V_1 * ) V_4 -> V_5 ) ;
}
static struct V_6 * F_3 ( struct V_2 * V_3 ,
void * V_7 , unsigned V_8 , int V_9 )
{
struct V_6 * V_10 ;
struct V_11 * V_12 = V_3 -> V_11 ;
V_10 = F_4 ( V_12 , V_9 , V_13 ) ;
if ( ! V_10 ) {
F_5 ( V_14 , V_3 ,
L_1 ) ;
return NULL ;
}
if ( V_8 && F_6 ( V_12 , V_10 , V_7 , V_8 , V_13 ) ) {
F_7 ( V_10 ) ;
F_5 ( V_14 , V_3 ,
L_2 ) ;
return NULL ;
}
V_10 -> V_15 = V_16 ;
V_10 -> V_17 |= V_18 | V_19 |
V_20 ;
V_10 -> V_21 = V_22 ;
V_10 -> V_23 = V_24 ;
return V_10 ;
}
static struct V_6 * F_8 ( struct V_2 * V_3 ,
struct V_1 * V_25 , struct V_26 * V_27 )
{
struct V_6 * V_10 ;
struct V_28 * V_29 ;
unsigned V_30 ;
struct V_31 * V_32 ;
T_1 * V_33 ;
if ( V_25 -> V_34 -> V_35 ) {
struct V_36 * V_37 ;
V_30 = sizeof( struct V_36 ) ;
V_37 = & V_25 -> V_34 -> V_38 . V_39 ;
memset ( V_37 , 0 , V_30 ) ;
V_29 = & V_37 -> V_29 ;
V_37 -> V_40 = V_41 + 0x40 ;
V_37 -> V_42 = 0x1 ;
V_37 -> V_43 [ 0 ] = 0x01 ;
V_37 -> V_43 [ 1 ] = 0x28 ;
V_33 = V_37 -> V_33 ;
} else {
struct V_44 * V_37 ;
V_30 = sizeof( struct V_44 ) ;
V_37 = & V_25 -> V_34 -> V_38 . V_45 ;
memset ( V_37 , 0 , V_30 ) ;
V_29 = & V_37 -> V_29 ;
V_37 -> V_40 = V_41 ;
V_37 -> V_43 = 0x68 ;
V_33 = V_37 -> V_33 ;
}
V_29 -> V_46 [ 1 ] = V_47 ;
V_29 -> V_48 = V_49 ;
V_29 -> V_50 = V_51 ;
F_9 (qdata, list, entry) {
V_33 [ V_32 -> V_25 -> V_52 ] = 0x81 ;
}
V_10 = F_3 ( V_3 , & V_25 -> V_34 -> V_38 , V_30 , V_53 ) ;
if ( ! V_10 )
return NULL ;
if ( V_25 -> V_34 -> V_35 ) {
V_10 -> V_54 [ 0 ] = V_55 ;
V_10 -> V_54 [ 7 ] = V_30 >> 8 ;
V_10 -> V_54 [ 8 ] = V_30 & 0xff ;
} else {
V_10 -> V_54 [ 0 ] = V_56 ;
V_10 -> V_54 [ 4 ] = V_30 ;
}
V_10 -> V_57 = F_10 ( V_10 -> V_54 [ 0 ] ) ;
V_10 -> V_58 = V_25 -> V_58 ;
memset ( V_10 -> V_58 , 0 , V_59 ) ;
V_10 -> V_60 = 0 ;
return V_10 ;
}
static void F_11 ( struct V_61 * V_61 )
{
struct V_62 * V_34 ;
V_34 = F_12 ( V_61 , struct V_62 , V_61 ) ;
F_13 ( & V_34 -> V_63 ) ;
F_14 ( V_34 ) ;
}
static struct V_62 * F_15 ( int V_64 , char * V_65 ,
T_1 * V_66 , struct V_2 * V_3 )
{
struct V_62 * V_34 , * V_67 ;
F_9 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_67 -> V_66 , V_66 , V_68 ) == 0 ) &&
( V_67 -> V_64 == V_64 ) &&
( V_67 -> V_69 == V_3 -> V_69 ) ) {
F_16 ( & V_67 -> V_61 ) ;
return V_67 ;
}
}
V_34 = F_17 ( sizeof( * V_34 ) , V_70 ) ;
if ( ! V_34 )
return NULL ;
memcpy ( V_34 -> V_66 , V_66 , V_68 ) ;
V_34 -> V_64 = V_64 ;
V_34 -> V_69 = V_3 -> V_69 ;
memcpy ( V_34 -> V_65 , V_65 , V_71 ) ;
F_18 ( & V_34 -> V_61 ) ;
V_34 -> V_35 = - 1 ;
V_34 -> V_72 = 0 ;
V_34 -> V_73 = NULL ;
F_19 ( & V_34 -> V_74 ) ;
F_20 ( & V_34 -> V_75 , V_76 ) ;
F_21 ( & V_34 -> V_77 ) ;
F_22 ( & V_34 -> V_63 , & V_78 ) ;
return V_34 ;
}
static int F_23 ( struct V_2 * V_3 , int V_40 ,
unsigned int V_79 , struct V_1 * V_25 )
{
struct V_6 * V_10 ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_80 = V_81 ;
V_10 = F_3 ( V_3 , & V_25 -> V_82 , V_79 , V_83 ) ;
if ( ! V_10 )
goto V_84;
V_10 -> V_54 [ 0 ] = V_85 ;
V_10 -> V_54 [ 1 ] = 1 ;
V_10 -> V_54 [ 2 ] = V_40 ;
V_10 -> V_54 [ 4 ] = V_79 ;
V_10 -> V_57 = F_10 ( V_85 ) ;
V_10 -> V_58 = V_25 -> V_58 ;
memset ( V_10 -> V_58 , 0 , V_59 ) ;
V_10 -> V_60 = 0 ;
V_80 = F_24 ( V_12 , NULL , V_10 , 1 ) ;
if ( V_80 == - V_86 )
V_80 = V_87 ;
F_7 ( V_10 ) ;
V_84:
return V_80 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_1 * V_25 ,
char * V_65 , T_1 * V_66 )
{
int V_80 , V_88 ;
struct V_89 * V_90 ;
V_80 = F_23 ( V_3 , 0xC8 , sizeof( struct V_89 ) , V_25 ) ;
if ( V_80 == V_91 ) {
V_90 = & V_25 -> V_82 . V_92 ;
if ( V_90 -> V_40 != 0xc8 )
return V_93 ;
if ( V_90 -> V_94 [ 0 ] != 'e' || V_90 -> V_94 [ 1 ] != 'd' ||
V_90 -> V_94 [ 2 ] != 'i' || V_90 -> V_94 [ 3 ] != 'd' )
return V_93 ;
V_25 -> V_52 = V_90 -> V_52 [ 7 ] ;
for( V_88 = 0 ; V_88 < V_71 - 1 ; ++ V_88 )
* ( V_65 + V_88 ) = V_90 -> V_95 [ ( 2 * V_88 ) + 1 ] ;
* ( V_65 + V_71 - 1 ) = '\0' ;
memset ( V_66 , 0 , V_68 ) ;
memcpy ( V_66 , V_90 -> V_96 , V_90 -> V_97 ) ;
}
return V_80 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_1 * V_25 )
{
int V_80 ;
struct V_98 * V_90 ;
V_25 -> V_99 = V_100 ;
V_80 = F_23 ( V_3 , 0xC9 , sizeof( struct V_98 ) , V_25 ) ;
if ( V_80 == V_91 ) {
V_90 = & V_25 -> V_82 . V_101 ;
if ( ( V_90 -> V_102 >> 5 ) & 0x1 )
V_25 -> V_103 = V_104 ;
else if ( V_90 -> V_102 >> 7 )
V_25 -> V_103 = V_105 ;
else
V_25 -> V_103 = V_106 ;
if ( V_90 -> V_102 & 0x1 )
V_25 -> V_107 = V_108 ;
else {
V_25 -> V_107 = V_109 ;
if ( V_25 -> V_103 == V_106 )
V_25 -> V_99 = V_110 ;
}
if ( V_90 -> V_111 & 0x1 )
V_25 -> V_112 = V_113 ;
else
V_25 -> V_112 = V_114 ;
}
return V_80 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_1 * V_25 , char * V_65 , T_1 * V_66 )
{
int V_80 , V_64 ;
struct V_115 * V_90 ;
V_80 = F_23 ( V_3 , 0xC4 , sizeof( struct V_115 ) , V_25 ) ;
if ( V_80 == V_91 ) {
V_90 = & V_25 -> V_82 . V_116 ;
if ( V_90 -> V_117 [ 1 ] == 0x31 )
V_64 = 0 ;
else
V_64 = 1 ;
F_28 ( & V_118 ) ;
V_25 -> V_34 = F_15 ( V_64 , V_65 , V_66 , V_3 ) ;
if ( ! V_25 -> V_34 )
V_80 = V_81 ;
F_29 ( & V_118 ) ;
}
return V_80 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_1 * V_25 )
{
int V_80 ;
struct V_119 * V_90 ;
V_80 = F_23 ( V_3 , 0xC2 , sizeof( struct V_119 ) , V_25 ) ;
if ( V_80 == V_91 ) {
V_90 = & V_25 -> V_82 . V_120 ;
if ( V_90 -> V_121 >= V_122 )
V_25 -> V_34 -> V_35 = 1 ;
else
V_25 -> V_34 -> V_35 = 0 ;
}
return V_80 ;
}
static int F_31 ( struct V_2 * V_3 ,
unsigned char * V_123 )
{
struct V_124 V_125 ;
int V_80 = V_87 , V_126 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_126 = F_32 ( V_123 , V_59 , & V_125 ) ;
if ( ! V_126 )
goto V_84;
switch ( V_125 . V_127 ) {
case V_128 :
case V_129 :
case V_130 :
V_80 = V_131 ;
break;
case V_132 :
if ( V_125 . V_133 == 0x04 && V_125 . V_134 == 0x01 )
V_80 = V_131 ;
break;
case V_135 :
if ( V_125 . V_133 == 0x91 && V_125 . V_134 == 0x36 )
V_80 = V_131 ;
break;
default:
break;
}
F_33 ( V_136 , V_3 , L_3
L_4 ,
( char * ) V_25 -> V_34 -> V_65 , V_25 -> V_34 -> V_64 ,
V_125 . V_127 , V_125 . V_133 , V_125 . V_134 ) ;
V_84:
return V_80 ;
}
static void V_76 ( struct V_137 * V_138 )
{
struct V_62 * V_34 =
F_12 ( V_138 , struct V_62 , V_75 ) ;
struct V_6 * V_10 ;
struct V_2 * V_3 = V_34 -> V_73 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_80 , V_139 = V_140 ;
struct V_31 * V_67 , * V_32 ;
F_34 ( V_27 ) ;
F_28 ( & V_34 -> V_74 ) ;
F_35 ( & V_34 -> V_77 , & V_27 ) ;
V_34 -> V_72 = 0 ;
V_34 -> V_73 = NULL ;
F_29 ( & V_34 -> V_74 ) ;
V_141:
V_80 = V_81 ;
V_10 = F_8 ( V_3 , V_25 , & V_27 ) ;
if ( ! V_10 )
goto V_84;
F_33 ( V_136 , V_3 , L_3
L_5 ,
( char * ) V_25 -> V_34 -> V_65 , V_25 -> V_34 -> V_64 ,
( V_139 == V_140 ) ? L_6 : L_7 ) ;
V_80 = F_24 ( V_12 , NULL , V_10 , 1 ) ;
F_7 ( V_10 ) ;
if ( V_80 != V_91 ) {
V_80 = F_31 ( V_3 , V_25 -> V_58 ) ;
if ( V_80 == V_131 && V_139 -- )
goto V_141;
}
if ( V_80 == V_91 ) {
V_25 -> V_99 = V_100 ;
F_33 ( V_136 , V_3 , L_3
L_8 ,
( char * ) V_25 -> V_34 -> V_65 , V_25 -> V_34 -> V_64 ) ;
}
V_84:
F_36 (qdata, tmp, &list, entry) {
F_13 ( & V_32 -> V_142 ) ;
if ( V_80 == V_91 )
V_32 -> V_25 -> V_99 = V_100 ;
if ( V_32 -> V_143 )
V_32 -> V_143 ( V_32 -> V_144 , V_80 ) ;
F_14 ( V_32 ) ;
}
return;
}
static int F_37 ( struct V_2 * V_3 ,
T_2 V_145 , void * V_146 )
{
struct V_31 * V_32 ;
struct V_62 * V_34 ;
V_32 = F_38 ( sizeof( * V_32 ) , V_147 ) ;
if ( ! V_32 )
return V_131 ;
V_32 -> V_25 = F_1 ( V_3 ) ;
V_32 -> V_143 = V_145 ;
V_32 -> V_144 = V_146 ;
V_34 = V_32 -> V_25 -> V_34 ;
F_28 ( & V_34 -> V_74 ) ;
F_39 ( & V_32 -> V_142 , & V_34 -> V_77 ) ;
if ( ! V_34 -> V_72 ) {
V_34 -> V_72 = 1 ;
V_34 -> V_73 = V_3 ;
F_40 ( V_148 , & V_34 -> V_75 ) ;
}
F_29 ( & V_34 -> V_74 ) ;
return V_91 ;
}
static int F_41 ( struct V_2 * V_3 ,
T_2 V_145 , void * V_146 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_80 = V_91 ;
int V_149 = 0 ;
V_80 = F_26 ( V_3 , V_25 ) ;
if ( V_80 != V_91 )
goto V_84;
switch ( V_25 -> V_103 ) {
case V_106 :
if ( V_25 -> V_107 == V_109 )
V_149 = 1 ;
break;
case V_104 :
if ( ( V_25 -> V_107 == V_109 ) &&
( V_25 -> V_112 == V_113 ) )
V_149 = 1 ;
break;
default:
break;
}
if ( V_149 ) {
V_80 = F_37 ( V_3 , V_145 , V_146 ) ;
if ( V_80 == V_91 )
return 0 ;
}
V_84:
if ( V_145 )
V_145 ( V_146 , V_80 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_6 * V_150 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_126 = V_151 ;
if ( V_25 -> V_99 != V_100 ) {
V_126 = V_152 ;
V_150 -> V_17 |= V_153 ;
}
return V_126 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_124 * V_125 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_33 ( V_154 , V_3 , L_3
L_9 ,
( char * ) V_25 -> V_34 -> V_65 , V_25 -> V_34 -> V_64 ,
V_125 -> V_127 , V_125 -> V_133 , V_125 -> V_134 ) ;
switch ( V_125 -> V_127 ) {
case V_132 :
if ( V_125 -> V_133 == 0x04 && V_125 -> V_134 == 0x01 )
return V_155 ;
if ( V_125 -> V_133 == 0x04 && V_125 -> V_134 == 0x81 )
return V_156 ;
if ( V_125 -> V_133 == 0x04 && V_125 -> V_134 == 0xA1 )
return V_155 ;
if ( V_125 -> V_133 == 0xA1 && V_125 -> V_134 == 0x02 )
return V_155 ;
break;
case V_135 :
if ( V_125 -> V_133 == 0x94 && V_125 -> V_134 == 0x01 ) {
V_25 -> V_99 = V_110 ;
return V_156 ;
}
break;
case V_130 :
if ( V_125 -> V_133 == 0x29 && V_125 -> V_134 == 0x00 )
return V_155 ;
if ( V_125 -> V_133 == 0x8b && V_125 -> V_134 == 0x02 )
return V_155 ;
break;
}
return V_157 ;
}
static bool F_44 ( struct V_2 * V_3 )
{
int V_88 ;
if ( F_45 ( V_3 ) )
return false ;
for ( V_88 = 0 ; V_158 [ V_88 ] . V_159 ; V_88 ++ ) {
if ( ! strncmp ( V_3 -> V_159 , V_158 [ V_88 ] . V_159 ,
strlen ( V_158 [ V_88 ] . V_159 ) ) &&
! strncmp ( V_3 -> V_160 , V_158 [ V_88 ] . V_160 ,
strlen ( V_158 [ V_88 ] . V_160 ) ) ) {
return true ;
}
}
return false ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_25 ;
unsigned long V_161 ;
int V_80 ;
char V_65 [ V_71 ] ;
char V_66 [ V_68 ] ;
V_4 = F_38 ( sizeof( * V_4 )
+ sizeof( * V_25 ) , V_147 ) ;
if ( ! V_4 ) {
F_5 ( V_162 , V_3 , L_10 ,
V_163 ) ;
return - V_164 ;
}
V_4 -> V_165 = & V_166 ;
V_25 = (struct V_1 * ) V_4 -> V_5 ;
V_25 -> V_52 = V_167 ;
V_25 -> V_99 = V_100 ;
V_80 = F_25 ( V_3 , V_25 , V_65 , V_66 ) ;
if ( V_80 != V_91 )
goto V_168;
V_80 = F_27 ( V_3 , V_25 , V_65 , V_66 ) ;
if ( V_80 != V_91 )
goto V_168;
V_80 = F_26 ( V_3 , V_25 ) ;
if ( V_80 != V_91 )
goto V_169;
V_80 = F_30 ( V_3 , V_25 ) ;
if ( V_80 != V_91 )
goto V_169;
if ( ! F_47 ( V_170 ) )
goto V_169;
F_48 ( V_3 -> V_11 -> V_171 , V_161 ) ;
V_3 -> V_4 = V_4 ;
F_49 ( V_3 -> V_11 -> V_171 , V_161 ) ;
F_5 ( V_172 , V_3 ,
L_11 ,
V_163 , V_25 -> V_52 , V_103 [ ( int ) V_25 -> V_103 ] ,
V_107 [ ( int ) V_25 -> V_107 ] ) ;
return 0 ;
V_169:
F_28 ( & V_118 ) ;
F_50 ( & V_25 -> V_34 -> V_61 , F_11 ) ;
F_29 ( & V_118 ) ;
V_168:
F_14 ( V_4 ) ;
F_5 ( V_162 , V_3 , L_12 ,
V_163 ) ;
return - V_173 ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_25 ;
unsigned long V_161 ;
V_4 = V_3 -> V_4 ;
V_25 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_25 -> V_34 && V_25 -> V_34 -> V_72 )
F_52 ( V_148 ) ;
F_48 ( V_3 -> V_11 -> V_171 , V_161 ) ;
V_3 -> V_4 = NULL ;
F_49 ( V_3 -> V_11 -> V_171 , V_161 ) ;
F_28 ( & V_118 ) ;
if ( V_25 -> V_34 )
F_50 ( & V_25 -> V_34 -> V_61 , F_11 ) ;
F_29 ( & V_118 ) ;
F_14 ( V_4 ) ;
F_53 ( V_170 ) ;
F_5 ( V_172 , V_3 , L_13 , V_163 ) ;
}
static int T_3 F_54 ( void )
{
int V_174 ;
V_174 = F_55 ( & V_166 ) ;
if ( V_174 != 0 ) {
F_56 ( V_162 L_14 ) ;
goto V_84;
}
V_148 = F_57 ( L_15 ) ;
if ( ! V_148 ) {
F_58 ( & V_166 ) ;
F_56 ( V_162 L_16 ) ;
V_174 = - V_173 ;
}
V_84:
return V_174 ;
}
static void T_4 F_59 ( void )
{
F_60 ( V_148 ) ;
F_58 ( & V_166 ) ;
}
