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
F_13 ( V_63 ) ;
F_14 ( & V_64 ) ;
F_15 ( & V_34 -> V_65 ) ;
F_16 ( & V_64 ) ;
F_17 ( V_34 ) ;
}
static struct V_62 * F_18 ( int V_66 , char * V_67 ,
T_1 * V_68 , struct V_2 * V_3 )
{
struct V_62 * V_34 , * V_69 ;
F_14 ( & V_64 ) ;
F_9 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_69 -> V_68 , V_68 , V_70 ) == 0 ) &&
( V_69 -> V_66 == V_66 ) &&
( V_69 -> V_71 == V_3 -> V_71 ) ) {
F_19 ( & V_69 -> V_61 ) ;
F_16 ( & V_64 ) ;
return V_69 ;
}
}
V_34 = F_20 ( sizeof( * V_34 ) , V_72 ) ;
if ( ! V_34 )
goto V_73;
memcpy ( V_34 -> V_68 , V_68 , V_70 ) ;
V_34 -> V_66 = V_66 ;
V_34 -> V_71 = V_3 -> V_71 ;
memcpy ( V_34 -> V_67 , V_67 , V_74 ) ;
F_21 ( & V_34 -> V_61 ) ;
V_34 -> V_35 = - 1 ;
V_34 -> V_75 = 0 ;
V_34 -> V_76 = NULL ;
F_22 ( & V_34 -> V_77 ) ;
F_23 ( & V_34 -> V_78 , V_79 ) ;
F_24 ( & V_34 -> V_80 ) ;
F_25 ( & V_34 -> V_65 , & V_81 ) ;
V_73:
F_16 ( & V_64 ) ;
return V_34 ;
}
static int F_26 ( struct V_2 * V_3 , int V_40 ,
unsigned int V_82 , struct V_1 * V_25 )
{
struct V_6 * V_10 ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_83 = V_84 ;
V_10 = F_3 ( V_3 , & V_25 -> V_85 , V_82 , V_86 ) ;
if ( ! V_10 )
goto V_73;
V_10 -> V_54 [ 0 ] = V_87 ;
V_10 -> V_54 [ 1 ] = 1 ;
V_10 -> V_54 [ 2 ] = V_40 ;
V_10 -> V_54 [ 4 ] = V_82 ;
V_10 -> V_57 = F_10 ( V_87 ) ;
V_10 -> V_58 = V_25 -> V_58 ;
memset ( V_10 -> V_58 , 0 , V_59 ) ;
V_10 -> V_60 = 0 ;
V_83 = F_27 ( V_12 , NULL , V_10 , 1 ) ;
if ( V_83 == - V_88 )
V_83 = V_89 ;
F_7 ( V_10 ) ;
V_73:
return V_83 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_1 * V_25 ,
char * V_67 , T_1 * V_68 )
{
int V_83 , V_90 ;
struct V_91 * V_92 ;
V_83 = F_26 ( V_3 , 0xC8 , sizeof( struct V_91 ) , V_25 ) ;
if ( V_83 == V_93 ) {
V_92 = & V_25 -> V_85 . V_94 ;
if ( V_92 -> V_40 != 0xc8 )
return V_95 ;
if ( V_92 -> V_96 [ 0 ] != 'e' || V_92 -> V_96 [ 1 ] != 'd' ||
V_92 -> V_96 [ 2 ] != 'i' || V_92 -> V_96 [ 3 ] != 'd' )
return V_95 ;
V_25 -> V_52 = V_92 -> V_52 [ 7 ] ;
for( V_90 = 0 ; V_90 < V_74 - 1 ; ++ V_90 )
* ( V_67 + V_90 ) = V_92 -> V_97 [ ( 2 * V_90 ) + 1 ] ;
* ( V_67 + V_74 - 1 ) = '\0' ;
memset ( V_68 , 0 , V_70 ) ;
memcpy ( V_68 , V_92 -> V_98 , V_92 -> V_99 ) ;
}
return V_83 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_1 * V_25 )
{
int V_83 ;
struct V_100 * V_92 ;
V_25 -> V_101 = V_102 ;
V_83 = F_26 ( V_3 , 0xC9 , sizeof( struct V_100 ) , V_25 ) ;
if ( V_83 == V_93 ) {
V_92 = & V_25 -> V_85 . V_103 ;
if ( ( V_92 -> V_104 >> 5 ) & 0x1 )
V_25 -> V_105 = V_106 ;
else if ( V_92 -> V_104 >> 7 )
V_25 -> V_105 = V_107 ;
else
V_25 -> V_105 = V_108 ;
if ( V_92 -> V_104 & 0x1 )
V_25 -> V_109 = V_110 ;
else {
V_25 -> V_109 = V_111 ;
if ( V_25 -> V_105 == V_108 )
V_25 -> V_101 = V_112 ;
}
if ( V_92 -> V_113 & 0x1 )
V_25 -> V_114 = V_115 ;
else
V_25 -> V_114 = V_116 ;
}
return V_83 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_1 * V_25 , char * V_67 , T_1 * V_68 )
{
int V_83 , V_66 ;
struct V_117 * V_92 ;
V_83 = F_26 ( V_3 , 0xC4 , sizeof( struct V_117 ) , V_25 ) ;
if ( V_83 == V_93 ) {
V_92 = & V_25 -> V_85 . V_118 ;
if ( V_92 -> V_119 [ 1 ] == 0x31 )
V_66 = 0 ;
else
V_66 = 1 ;
V_25 -> V_34 = F_18 ( V_66 , V_67 , V_68 , V_3 ) ;
if ( ! V_25 -> V_34 )
V_83 = V_84 ;
}
return V_83 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_25 )
{
int V_83 ;
struct V_120 * V_92 ;
V_83 = F_26 ( V_3 , 0xC2 , sizeof( struct V_120 ) , V_25 ) ;
if ( V_83 == V_93 ) {
V_92 = & V_25 -> V_85 . V_121 ;
if ( V_92 -> V_122 >= V_123 )
V_25 -> V_34 -> V_35 = 1 ;
else
V_25 -> V_34 -> V_35 = 0 ;
}
return V_83 ;
}
static int F_32 ( struct V_2 * V_3 ,
unsigned char * V_124 )
{
struct V_125 V_126 ;
int V_83 = V_89 , V_127 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_127 = F_33 ( V_124 , V_59 , & V_126 ) ;
if ( ! V_127 )
goto V_73;
switch ( V_126 . V_128 ) {
case V_129 :
case V_130 :
case V_131 :
V_83 = V_132 ;
break;
case V_133 :
if ( V_126 . V_134 == 0x04 && V_126 . V_135 == 0x01 )
V_83 = V_132 ;
break;
case V_136 :
if ( V_126 . V_134 == 0x91 && V_126 . V_135 == 0x36 )
V_83 = V_132 ;
break;
default:
break;
}
F_34 ( V_137 , V_3 , L_3
L_4 ,
( char * ) V_25 -> V_34 -> V_67 , V_25 -> V_34 -> V_66 ,
V_126 . V_128 , V_126 . V_134 , V_126 . V_135 ) ;
V_73:
return V_83 ;
}
static void V_79 ( struct V_138 * V_139 )
{
struct V_62 * V_34 =
F_12 ( V_139 , struct V_62 , V_78 ) ;
struct V_6 * V_10 ;
struct V_2 * V_3 = V_34 -> V_76 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_83 , V_140 = V_141 ;
struct V_31 * V_69 , * V_32 ;
F_35 ( V_27 ) ;
F_14 ( & V_34 -> V_77 ) ;
F_36 ( & V_34 -> V_80 , & V_27 ) ;
V_34 -> V_75 = 0 ;
V_34 -> V_76 = NULL ;
F_16 ( & V_34 -> V_77 ) ;
V_142:
V_83 = V_84 ;
V_10 = F_8 ( V_3 , V_25 , & V_27 ) ;
if ( ! V_10 )
goto V_73;
F_34 ( V_137 , V_3 , L_3
L_5 ,
( char * ) V_25 -> V_34 -> V_67 , V_25 -> V_34 -> V_66 ,
( V_140 == V_141 ) ? L_6 : L_7 ) ;
V_83 = F_27 ( V_12 , NULL , V_10 , 1 ) ;
F_7 ( V_10 ) ;
if ( V_83 != V_93 ) {
V_83 = F_32 ( V_3 , V_25 -> V_58 ) ;
if ( V_83 == V_132 && V_140 -- )
goto V_142;
}
if ( V_83 == V_93 ) {
V_25 -> V_101 = V_102 ;
F_34 ( V_137 , V_3 , L_3
L_8 ,
( char * ) V_25 -> V_34 -> V_67 , V_25 -> V_34 -> V_66 ) ;
}
V_73:
F_37 (qdata, tmp, &list, entry) {
F_15 ( & V_32 -> V_143 ) ;
if ( V_83 == V_93 )
V_32 -> V_25 -> V_101 = V_102 ;
if ( V_32 -> V_144 )
V_32 -> V_144 ( V_32 -> V_145 , V_83 ) ;
F_17 ( V_32 ) ;
}
return;
}
static int F_38 ( struct V_2 * V_3 ,
T_2 V_146 , void * V_147 )
{
struct V_31 * V_32 ;
struct V_62 * V_34 ;
V_32 = F_39 ( sizeof( * V_32 ) , V_148 ) ;
if ( ! V_32 )
return V_132 ;
V_32 -> V_25 = F_1 ( V_3 ) ;
V_32 -> V_144 = V_146 ;
V_32 -> V_145 = V_147 ;
V_34 = V_32 -> V_25 -> V_34 ;
F_14 ( & V_34 -> V_77 ) ;
F_40 ( & V_32 -> V_143 , & V_34 -> V_80 ) ;
if ( ! V_34 -> V_75 ) {
V_34 -> V_75 = 1 ;
V_34 -> V_76 = V_3 ;
F_41 ( V_63 , & V_34 -> V_78 ) ;
}
F_16 ( & V_34 -> V_77 ) ;
return V_93 ;
}
static int F_42 ( struct V_2 * V_3 ,
T_2 V_146 , void * V_147 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_83 = V_93 ;
int V_149 = 0 ;
V_83 = F_29 ( V_3 , V_25 ) ;
if ( V_83 != V_93 )
goto V_73;
switch ( V_25 -> V_105 ) {
case V_108 :
if ( V_25 -> V_109 == V_111 )
V_149 = 1 ;
break;
case V_106 :
if ( ( V_25 -> V_109 == V_111 ) &&
( V_25 -> V_114 == V_115 ) )
V_149 = 1 ;
break;
default:
break;
}
if ( V_149 ) {
V_83 = F_38 ( V_3 , V_146 , V_147 ) ;
if ( V_83 == V_93 )
return 0 ;
}
V_73:
if ( V_146 )
V_146 ( V_147 , V_83 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_6 * V_150 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_127 = V_151 ;
if ( V_25 -> V_101 != V_102 ) {
V_127 = V_152 ;
V_150 -> V_17 |= V_153 ;
}
return V_127 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_125 * V_126 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_34 ( V_154 , V_3 , L_3
L_9 ,
( char * ) V_25 -> V_34 -> V_67 , V_25 -> V_34 -> V_66 ,
V_126 -> V_128 , V_126 -> V_134 , V_126 -> V_135 ) ;
switch ( V_126 -> V_128 ) {
case V_133 :
if ( V_126 -> V_134 == 0x04 && V_126 -> V_135 == 0x01 )
return V_155 ;
if ( V_126 -> V_134 == 0x04 && V_126 -> V_135 == 0x81 )
return V_156 ;
if ( V_126 -> V_134 == 0x04 && V_126 -> V_135 == 0xA1 )
return V_155 ;
if ( V_126 -> V_134 == 0xA1 && V_126 -> V_135 == 0x02 )
return V_155 ;
break;
case V_136 :
if ( V_126 -> V_134 == 0x94 && V_126 -> V_135 == 0x01 ) {
V_25 -> V_101 = V_112 ;
return V_156 ;
}
break;
case V_131 :
if ( V_126 -> V_134 == 0x29 && V_126 -> V_135 == 0x00 )
return V_155 ;
if ( V_126 -> V_134 == 0x8b && V_126 -> V_135 == 0x02 )
return V_155 ;
break;
}
return V_157 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_25 ;
unsigned long V_158 ;
int V_83 ;
char V_67 [ V_74 ] ;
char V_68 [ V_70 ] ;
V_4 = F_39 ( sizeof( * V_4 )
+ sizeof( * V_25 ) , V_148 ) ;
if ( ! V_4 ) {
F_5 ( V_159 , V_3 , L_10 ,
V_160 ) ;
return 0 ;
}
V_4 -> V_161 = & V_162 ;
V_25 = (struct V_1 * ) V_4 -> V_5 ;
V_25 -> V_52 = V_163 ;
V_25 -> V_101 = V_102 ;
V_83 = F_28 ( V_3 , V_25 , V_67 , V_68 ) ;
if ( V_83 != V_93 )
goto V_164;
V_83 = F_30 ( V_3 , V_25 , V_67 , V_68 ) ;
if ( V_83 != V_93 )
goto V_164;
V_83 = F_29 ( V_3 , V_25 ) ;
if ( V_83 != V_93 )
goto V_165;
V_83 = F_31 ( V_3 , V_25 ) ;
if ( V_83 != V_93 )
goto V_165;
if ( ! F_46 ( V_166 ) )
goto V_165;
F_47 ( V_3 -> V_11 -> V_167 , V_158 ) ;
V_3 -> V_4 = V_4 ;
F_48 ( V_3 -> V_11 -> V_167 , V_158 ) ;
F_5 ( V_168 , V_3 ,
L_11 ,
V_160 , V_25 -> V_52 , V_105 [ ( int ) V_25 -> V_105 ] ,
V_109 [ ( int ) V_25 -> V_109 ] ) ;
return 0 ;
V_165:
F_49 ( & V_25 -> V_34 -> V_61 , F_11 ) ;
V_164:
F_17 ( V_4 ) ;
F_5 ( V_159 , V_3 , L_12 ,
V_160 ) ;
return - V_169 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_25 ;
unsigned long V_158 ;
F_47 ( V_3 -> V_11 -> V_167 , V_158 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_48 ( V_3 -> V_11 -> V_167 , V_158 ) ;
V_25 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_25 -> V_34 )
F_49 ( & V_25 -> V_34 -> V_61 , F_11 ) ;
F_17 ( V_4 ) ;
F_51 ( V_166 ) ;
F_5 ( V_168 , V_3 , L_13 , V_160 ) ;
}
static int T_3 F_52 ( void )
{
int V_170 ;
V_170 = F_53 ( & V_162 ) ;
if ( V_170 != 0 ) {
F_54 ( V_159 L_14 ) ;
goto V_73;
}
V_63 = F_55 ( L_15 ) ;
if ( ! V_63 ) {
F_56 ( & V_162 ) ;
F_54 ( V_159 L_16 ) ;
}
V_73:
return V_170 ;
}
static void T_4 F_57 ( void )
{
F_58 ( V_63 ) ;
F_56 ( & V_162 ) ;
}
