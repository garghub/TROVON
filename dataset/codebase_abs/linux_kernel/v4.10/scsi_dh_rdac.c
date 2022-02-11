static struct V_1 * F_1 ( struct V_2 * V_3 ,
void * V_4 , unsigned V_5 , int V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 = V_3 -> V_8 ;
V_7 = F_2 ( V_9 , V_6 , V_10 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( V_11 , V_3 ,
L_1 ) ;
return NULL ;
}
F_5 ( V_7 ) ;
if ( V_5 && F_6 ( V_9 , V_7 , V_4 , V_5 , V_10 ) ) {
F_7 ( V_7 ) ;
F_4 ( V_11 , V_3 ,
L_2 ) ;
return NULL ;
}
V_7 -> V_12 |= V_13 | V_14 |
V_15 ;
V_7 -> V_16 = V_17 ;
V_7 -> V_18 = V_19 ;
return V_7 ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 ,
struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_7 ;
struct V_24 * V_25 ;
unsigned V_26 ;
struct V_27 * V_28 ;
T_1 * V_29 ;
if ( V_21 -> V_30 -> V_31 ) {
struct V_32 * V_33 ;
V_26 = sizeof( struct V_32 ) ;
V_33 = & V_21 -> V_30 -> V_34 . V_35 ;
memset ( V_33 , 0 , V_26 ) ;
V_25 = & V_33 -> V_25 ;
V_33 -> V_36 = V_37 + 0x40 ;
V_33 -> V_38 = 0x1 ;
V_33 -> V_39 [ 0 ] = 0x01 ;
V_33 -> V_39 [ 1 ] = 0x28 ;
V_29 = V_33 -> V_29 ;
} else {
struct V_40 * V_33 ;
V_26 = sizeof( struct V_40 ) ;
V_33 = & V_21 -> V_30 -> V_34 . V_41 ;
memset ( V_33 , 0 , V_26 ) ;
V_25 = & V_33 -> V_25 ;
V_33 -> V_36 = V_37 ;
V_33 -> V_39 = 0x68 ;
V_29 = V_33 -> V_29 ;
}
V_25 -> V_42 [ 1 ] = V_43 ;
V_25 -> V_44 = V_45 ;
V_25 -> V_46 = V_47 ;
F_9 (qdata, list, entry) {
V_29 [ V_28 -> V_21 -> V_48 ] = 0x81 ;
}
V_7 = F_1 ( V_3 , & V_21 -> V_30 -> V_34 , V_26 , V_49 ) ;
if ( ! V_7 )
return NULL ;
if ( V_21 -> V_30 -> V_31 ) {
V_7 -> V_50 [ 0 ] = V_51 ;
V_7 -> V_50 [ 7 ] = V_26 >> 8 ;
V_7 -> V_50 [ 8 ] = V_26 & 0xff ;
} else {
V_7 -> V_50 [ 0 ] = V_52 ;
V_7 -> V_50 [ 4 ] = V_26 ;
}
V_7 -> V_53 = F_10 ( V_7 -> V_50 [ 0 ] ) ;
V_7 -> V_54 = V_21 -> V_54 ;
memset ( V_7 -> V_54 , 0 , V_55 ) ;
V_7 -> V_56 = 0 ;
return V_7 ;
}
static void F_11 ( struct V_57 * V_57 )
{
struct V_58 * V_30 ;
V_30 = F_12 ( V_57 , struct V_58 , V_57 ) ;
F_13 ( & V_30 -> V_59 ) ;
F_14 ( V_30 ) ;
}
static struct V_58 * F_15 ( int V_60 , char * V_61 ,
T_1 * V_62 , struct V_2 * V_3 )
{
struct V_58 * V_30 , * V_63 ;
F_9 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_63 -> V_62 , V_62 , V_64 ) == 0 ) &&
( V_63 -> V_60 == V_60 ) &&
( V_63 -> V_65 == V_3 -> V_65 ) ) {
F_16 ( & V_63 -> V_57 ) ;
return V_63 ;
}
}
V_30 = F_17 ( sizeof( * V_30 ) , V_66 ) ;
if ( ! V_30 )
return NULL ;
memcpy ( V_30 -> V_62 , V_62 , V_64 ) ;
V_30 -> V_60 = V_60 ;
V_30 -> V_65 = V_3 -> V_65 ;
memcpy ( V_30 -> V_61 , V_61 , V_67 ) ;
F_18 ( & V_30 -> V_57 ) ;
V_30 -> V_31 = - 1 ;
V_30 -> V_68 = 0 ;
V_30 -> V_69 = NULL ;
F_19 ( & V_30 -> V_70 ) ;
F_20 ( & V_30 -> V_71 , V_72 ) ;
F_21 ( & V_30 -> V_73 ) ;
F_22 ( & V_30 -> V_59 , & V_74 ) ;
F_21 ( & V_30 -> V_75 ) ;
return V_30 ;
}
static int F_23 ( struct V_2 * V_3 , int V_36 ,
unsigned int V_76 , struct V_20 * V_21 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 = V_3 -> V_8 ;
int V_77 = V_78 ;
V_7 = F_1 ( V_3 , & V_21 -> V_79 , V_76 , V_80 ) ;
if ( ! V_7 )
goto V_81;
V_7 -> V_50 [ 0 ] = V_82 ;
V_7 -> V_50 [ 1 ] = 1 ;
V_7 -> V_50 [ 2 ] = V_36 ;
V_7 -> V_50 [ 4 ] = V_76 ;
V_7 -> V_53 = F_10 ( V_82 ) ;
V_7 -> V_54 = V_21 -> V_54 ;
memset ( V_7 -> V_54 , 0 , V_55 ) ;
V_7 -> V_56 = 0 ;
V_77 = F_24 ( V_9 , NULL , V_7 , 1 ) ;
if ( V_77 == - V_83 )
V_77 = V_84 ;
F_7 ( V_7 ) ;
V_81:
return V_77 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_20 * V_21 ,
char * V_61 , T_1 * V_62 )
{
int V_77 , V_85 ;
struct V_86 * V_87 ;
V_77 = F_23 ( V_3 , 0xC8 , sizeof( struct V_86 ) , V_21 ) ;
if ( V_77 == V_88 ) {
V_87 = & V_21 -> V_79 . V_89 ;
if ( V_87 -> V_36 != 0xc8 )
return V_90 ;
if ( V_87 -> V_91 [ 0 ] != 'e' || V_87 -> V_91 [ 1 ] != 'd' ||
V_87 -> V_91 [ 2 ] != 'i' || V_87 -> V_91 [ 3 ] != 'd' )
return V_90 ;
V_21 -> V_48 = V_87 -> V_48 [ 7 ] ;
for( V_85 = 0 ; V_85 < V_67 - 1 ; ++ V_85 )
* ( V_61 + V_85 ) = V_87 -> V_92 [ ( 2 * V_85 ) + 1 ] ;
* ( V_61 + V_67 - 1 ) = '\0' ;
memset ( V_62 , 0 , V_64 ) ;
memcpy ( V_62 , V_87 -> V_93 , V_87 -> V_94 ) ;
}
return V_77 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
int V_77 , V_95 ;
struct V_20 * V_63 ;
struct V_96 * V_87 ;
V_21 -> V_97 = V_98 ;
V_77 = F_23 ( V_3 , 0xC9 , sizeof( struct V_96 ) , V_21 ) ;
if ( V_77 == V_88 ) {
V_87 = & V_21 -> V_79 . V_99 ;
if ( ( V_87 -> V_100 >> 5 ) & 0x1 )
V_21 -> V_101 = V_102 ;
else if ( V_87 -> V_100 >> 7 )
V_21 -> V_101 = V_103 ;
else
V_21 -> V_101 = V_104 ;
if ( V_87 -> V_100 & 0x1 ) {
V_21 -> V_105 = V_106 ;
V_95 = V_107 ;
} else {
V_21 -> V_105 = V_108 ;
if ( V_21 -> V_101 == V_104 ) {
V_21 -> V_97 = V_109 ;
V_95 = V_110 ;
} else
V_95 = V_111 ;
}
if ( V_87 -> V_112 & 0x1 ) {
V_21 -> V_113 = V_114 ;
V_95 |= V_115 ;
} else
V_21 -> V_113 = V_116 ;
F_27 () ;
F_28 (tmp, &h->ctlr->dh_list, node) {
F_29 ( ! V_63 -> V_3 ) ;
V_63 -> V_3 -> V_95 = V_95 ;
}
F_30 () ;
}
return V_77 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_20 * V_21 , char * V_61 , T_1 * V_62 )
{
int V_77 , V_60 ;
struct V_117 * V_87 ;
V_77 = F_23 ( V_3 , 0xC4 , sizeof( struct V_117 ) , V_21 ) ;
if ( V_77 == V_88 ) {
V_87 = & V_21 -> V_79 . V_118 ;
if ( V_87 -> V_119 [ 1 ] == 0x31 )
V_60 = 0 ;
else
V_60 = 1 ;
F_32 ( & V_120 ) ;
V_21 -> V_30 = F_15 ( V_60 , V_61 , V_62 , V_3 ) ;
if ( ! V_21 -> V_30 )
V_77 = V_78 ;
else {
F_33 ( & V_21 -> V_59 , & V_21 -> V_30 -> V_75 ) ;
V_21 -> V_3 = V_3 ;
}
F_34 ( & V_120 ) ;
}
return V_77 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
int V_77 ;
struct V_121 * V_87 ;
V_77 = F_23 ( V_3 , 0xC2 , sizeof( struct V_121 ) , V_21 ) ;
if ( V_77 == V_88 ) {
V_87 = & V_21 -> V_79 . V_122 ;
if ( V_87 -> V_123 >= V_124 )
V_21 -> V_30 -> V_31 = 1 ;
else
V_21 -> V_30 -> V_31 = 0 ;
}
return V_77 ;
}
static int F_36 ( struct V_2 * V_3 ,
unsigned char * V_125 )
{
struct V_126 V_127 ;
int V_77 = V_84 , V_128 ;
struct V_20 * V_21 = V_3 -> V_129 ;
V_128 = F_37 ( V_125 , V_55 , & V_127 ) ;
if ( ! V_128 )
goto V_81;
switch ( V_127 . V_130 ) {
case V_131 :
case V_132 :
case V_133 :
V_77 = V_134 ;
break;
case V_135 :
if ( V_127 . V_136 == 0x04 && V_127 . V_137 == 0x01 )
V_77 = V_134 ;
break;
case V_138 :
if ( V_127 . V_136 == 0x91 && V_127 . V_137 == 0x36 )
V_77 = V_139 ;
break;
default:
break;
}
F_38 ( V_140 , V_3 , L_3
L_4 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,
V_127 . V_130 , V_127 . V_136 , V_127 . V_137 ) ;
V_81:
return V_77 ;
}
static void V_72 ( struct V_141 * V_142 )
{
struct V_58 * V_30 =
F_12 ( V_142 , struct V_58 , V_71 ) ;
struct V_1 * V_7 ;
struct V_2 * V_3 = V_30 -> V_69 ;
struct V_20 * V_21 = V_3 -> V_129 ;
struct V_8 * V_9 = V_3 -> V_8 ;
int V_77 , V_143 = V_144 ;
struct V_27 * V_63 , * V_28 ;
F_39 ( V_23 ) ;
F_32 ( & V_30 -> V_70 ) ;
F_40 ( & V_30 -> V_73 , & V_23 ) ;
V_30 -> V_68 = 0 ;
V_30 -> V_69 = NULL ;
F_34 ( & V_30 -> V_70 ) ;
V_145:
V_77 = V_78 ;
V_7 = F_8 ( V_3 , V_21 , & V_23 ) ;
if ( ! V_7 )
goto V_81;
F_38 ( V_140 , V_3 , L_3
L_5 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,
( V_143 == V_144 ) ? L_6 : L_7 ) ;
V_77 = F_24 ( V_9 , NULL , V_7 , 1 ) ;
F_7 ( V_7 ) ;
if ( V_77 != V_88 ) {
V_77 = F_36 ( V_3 , V_21 -> V_54 ) ;
if ( V_77 == V_134 && V_143 -- )
goto V_145;
if ( V_77 == V_139 )
goto V_145;
}
if ( V_77 == V_88 ) {
V_21 -> V_97 = V_98 ;
F_38 ( V_140 , V_3 , L_3
L_8 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ) ;
}
V_81:
F_41 (qdata, tmp, &list, entry) {
F_13 ( & V_28 -> V_146 ) ;
if ( V_77 == V_88 )
V_28 -> V_21 -> V_97 = V_98 ;
if ( V_28 -> V_147 )
V_28 -> V_147 ( V_28 -> V_148 , V_77 ) ;
F_14 ( V_28 ) ;
}
return;
}
static int F_42 ( struct V_2 * V_3 ,
T_2 V_149 , void * V_150 )
{
struct V_27 * V_28 ;
struct V_58 * V_30 ;
V_28 = F_43 ( sizeof( * V_28 ) , V_151 ) ;
if ( ! V_28 )
return V_134 ;
V_28 -> V_21 = V_3 -> V_129 ;
V_28 -> V_147 = V_149 ;
V_28 -> V_148 = V_150 ;
V_30 = V_28 -> V_21 -> V_30 ;
F_32 ( & V_30 -> V_70 ) ;
F_44 ( & V_28 -> V_146 , & V_30 -> V_73 ) ;
if ( ! V_30 -> V_68 ) {
V_30 -> V_68 = 1 ;
V_30 -> V_69 = V_3 ;
F_45 ( V_152 , & V_30 -> V_71 ) ;
}
F_34 ( & V_30 -> V_70 ) ;
return V_88 ;
}
static int F_46 ( struct V_2 * V_3 ,
T_2 V_149 , void * V_150 )
{
struct V_20 * V_21 = V_3 -> V_129 ;
int V_77 = V_88 ;
int V_153 = 0 ;
V_77 = F_26 ( V_3 , V_21 ) ;
if ( V_77 != V_88 )
goto V_81;
switch ( V_21 -> V_101 ) {
case V_104 :
if ( V_21 -> V_105 == V_108 )
V_153 = 1 ;
break;
case V_102 :
if ( ( V_21 -> V_105 == V_108 ) &&
( V_21 -> V_113 == V_114 ) )
V_153 = 1 ;
break;
default:
break;
}
if ( V_153 ) {
V_77 = F_42 ( V_3 , V_149 , V_150 ) ;
if ( V_77 == V_88 )
return 0 ;
}
V_81:
if ( V_149 )
V_149 ( V_150 , V_77 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_1 * V_154 )
{
struct V_20 * V_21 = V_3 -> V_129 ;
int V_128 = V_155 ;
if ( V_21 -> V_97 != V_98 ) {
V_128 = V_156 ;
V_154 -> V_157 |= V_158 ;
}
return V_128 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_126 * V_127 )
{
struct V_20 * V_21 = V_3 -> V_129 ;
F_38 ( V_159 , V_3 , L_3
L_9 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,
V_127 -> V_130 , V_127 -> V_136 , V_127 -> V_137 ) ;
switch ( V_127 -> V_130 ) {
case V_135 :
if ( V_127 -> V_136 == 0x04 && V_127 -> V_137 == 0x01 )
return V_160 ;
if ( V_127 -> V_136 == 0x04 && V_127 -> V_137 == 0x81 )
return V_161 ;
if ( V_127 -> V_136 == 0x04 && V_127 -> V_137 == 0xA1 )
return V_160 ;
if ( V_127 -> V_136 == 0xA1 && V_127 -> V_137 == 0x02 )
return V_160 ;
break;
case V_138 :
if ( V_127 -> V_136 == 0x94 && V_127 -> V_137 == 0x01 ) {
V_21 -> V_97 = V_109 ;
return V_161 ;
}
break;
case V_133 :
if ( V_127 -> V_136 == 0x29 && V_127 -> V_137 == 0x00 )
return V_160 ;
if ( V_127 -> V_136 == 0x8b && V_127 -> V_137 == 0x02 )
return V_160 ;
break;
}
return V_162 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
int V_77 ;
char V_61 [ V_67 ] ;
char V_62 [ V_64 ] ;
V_21 = F_43 ( sizeof( * V_21 ) , V_151 ) ;
if ( ! V_21 )
return - V_163 ;
V_21 -> V_48 = V_164 ;
V_21 -> V_97 = V_98 ;
V_77 = F_25 ( V_3 , V_21 , V_61 , V_62 ) ;
if ( V_77 != V_88 )
goto V_165;
V_77 = F_31 ( V_3 , V_21 , V_61 , V_62 ) ;
if ( V_77 != V_88 )
goto V_165;
V_77 = F_26 ( V_3 , V_21 ) ;
if ( V_77 != V_88 )
goto V_166;
V_77 = F_35 ( V_3 , V_21 ) ;
if ( V_77 != V_88 )
goto V_166;
F_4 ( V_167 , V_3 ,
L_10 ,
V_168 , V_21 -> V_48 , V_101 [ ( int ) V_21 -> V_101 ] ,
V_105 [ ( int ) V_21 -> V_105 ] ) ;
V_3 -> V_129 = V_21 ;
return 0 ;
V_166:
F_32 ( & V_120 ) ;
F_50 ( & V_21 -> V_30 -> V_57 , F_11 ) ;
F_34 ( & V_120 ) ;
V_165:
F_14 ( V_21 ) ;
return - V_169 ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_129 ;
if ( V_21 -> V_30 && V_21 -> V_30 -> V_68 )
F_52 ( V_152 ) ;
F_32 ( & V_120 ) ;
if ( V_21 -> V_30 ) {
F_53 ( & V_21 -> V_59 ) ;
V_21 -> V_3 = NULL ;
F_50 ( & V_21 -> V_30 -> V_57 , F_11 ) ;
}
F_34 ( & V_120 ) ;
V_3 -> V_129 = NULL ;
F_14 ( V_21 ) ;
}
static int T_3 F_54 ( void )
{
int V_170 ;
V_170 = F_55 ( & V_171 ) ;
if ( V_170 != 0 ) {
F_56 ( V_172 L_11 ) ;
goto V_81;
}
V_152 = F_57 ( L_12 ) ;
if ( ! V_152 ) {
F_58 ( & V_171 ) ;
F_56 ( V_172 L_13 ) ;
V_170 = - V_169 ;
}
V_81:
return V_170 ;
}
static void T_4 F_59 ( void )
{
F_60 ( V_152 ) ;
F_58 ( & V_171 ) ;
}
