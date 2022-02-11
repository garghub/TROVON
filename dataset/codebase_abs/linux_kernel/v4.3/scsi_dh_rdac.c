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
return V_30 ;
}
static int F_23 ( struct V_2 * V_3 , int V_36 ,
unsigned int V_75 , struct V_20 * V_21 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 = V_3 -> V_8 ;
int V_76 = V_77 ;
V_7 = F_1 ( V_3 , & V_21 -> V_78 , V_75 , V_79 ) ;
if ( ! V_7 )
goto V_80;
V_7 -> V_50 [ 0 ] = V_81 ;
V_7 -> V_50 [ 1 ] = 1 ;
V_7 -> V_50 [ 2 ] = V_36 ;
V_7 -> V_50 [ 4 ] = V_75 ;
V_7 -> V_53 = F_10 ( V_81 ) ;
V_7 -> V_54 = V_21 -> V_54 ;
memset ( V_7 -> V_54 , 0 , V_55 ) ;
V_7 -> V_56 = 0 ;
V_76 = F_24 ( V_9 , NULL , V_7 , 1 ) ;
if ( V_76 == - V_82 )
V_76 = V_83 ;
F_7 ( V_7 ) ;
V_80:
return V_76 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_20 * V_21 ,
char * V_61 , T_1 * V_62 )
{
int V_76 , V_84 ;
struct V_85 * V_86 ;
V_76 = F_23 ( V_3 , 0xC8 , sizeof( struct V_85 ) , V_21 ) ;
if ( V_76 == V_87 ) {
V_86 = & V_21 -> V_78 . V_88 ;
if ( V_86 -> V_36 != 0xc8 )
return V_89 ;
if ( V_86 -> V_90 [ 0 ] != 'e' || V_86 -> V_90 [ 1 ] != 'd' ||
V_86 -> V_90 [ 2 ] != 'i' || V_86 -> V_90 [ 3 ] != 'd' )
return V_89 ;
V_21 -> V_48 = V_86 -> V_48 [ 7 ] ;
for( V_84 = 0 ; V_84 < V_67 - 1 ; ++ V_84 )
* ( V_61 + V_84 ) = V_86 -> V_91 [ ( 2 * V_84 ) + 1 ] ;
* ( V_61 + V_67 - 1 ) = '\0' ;
memset ( V_62 , 0 , V_64 ) ;
memcpy ( V_62 , V_86 -> V_92 , V_86 -> V_93 ) ;
}
return V_76 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
int V_76 ;
struct V_94 * V_86 ;
V_21 -> V_95 = V_96 ;
V_76 = F_23 ( V_3 , 0xC9 , sizeof( struct V_94 ) , V_21 ) ;
if ( V_76 == V_87 ) {
V_86 = & V_21 -> V_78 . V_97 ;
if ( ( V_86 -> V_98 >> 5 ) & 0x1 )
V_21 -> V_99 = V_100 ;
else if ( V_86 -> V_98 >> 7 )
V_21 -> V_99 = V_101 ;
else
V_21 -> V_99 = V_102 ;
if ( V_86 -> V_98 & 0x1 )
V_21 -> V_103 = V_104 ;
else {
V_21 -> V_103 = V_105 ;
if ( V_21 -> V_99 == V_102 )
V_21 -> V_95 = V_106 ;
}
if ( V_86 -> V_107 & 0x1 )
V_21 -> V_108 = V_109 ;
else
V_21 -> V_108 = V_110 ;
}
return V_76 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_20 * V_21 , char * V_61 , T_1 * V_62 )
{
int V_76 , V_60 ;
struct V_111 * V_86 ;
V_76 = F_23 ( V_3 , 0xC4 , sizeof( struct V_111 ) , V_21 ) ;
if ( V_76 == V_87 ) {
V_86 = & V_21 -> V_78 . V_112 ;
if ( V_86 -> V_113 [ 1 ] == 0x31 )
V_60 = 0 ;
else
V_60 = 1 ;
F_28 ( & V_114 ) ;
V_21 -> V_30 = F_15 ( V_60 , V_61 , V_62 , V_3 ) ;
if ( ! V_21 -> V_30 )
V_76 = V_77 ;
F_29 ( & V_114 ) ;
}
return V_76 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
int V_76 ;
struct V_115 * V_86 ;
V_76 = F_23 ( V_3 , 0xC2 , sizeof( struct V_115 ) , V_21 ) ;
if ( V_76 == V_87 ) {
V_86 = & V_21 -> V_78 . V_116 ;
if ( V_86 -> V_117 >= V_118 )
V_21 -> V_30 -> V_31 = 1 ;
else
V_21 -> V_30 -> V_31 = 0 ;
}
return V_76 ;
}
static int F_31 ( struct V_2 * V_3 ,
unsigned char * V_119 )
{
struct V_120 V_121 ;
int V_76 = V_83 , V_122 ;
struct V_20 * V_21 = V_3 -> V_123 ;
V_122 = F_32 ( V_119 , V_55 , & V_121 ) ;
if ( ! V_122 )
goto V_80;
switch ( V_121 . V_124 ) {
case V_125 :
case V_126 :
case V_127 :
V_76 = V_128 ;
break;
case V_129 :
if ( V_121 . V_130 == 0x04 && V_121 . V_131 == 0x01 )
V_76 = V_128 ;
break;
case V_132 :
if ( V_121 . V_130 == 0x91 && V_121 . V_131 == 0x36 )
V_76 = V_128 ;
break;
default:
break;
}
F_33 ( V_133 , V_3 , L_3
L_4 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,
V_121 . V_124 , V_121 . V_130 , V_121 . V_131 ) ;
V_80:
return V_76 ;
}
static void V_72 ( struct V_134 * V_135 )
{
struct V_58 * V_30 =
F_12 ( V_135 , struct V_58 , V_71 ) ;
struct V_1 * V_7 ;
struct V_2 * V_3 = V_30 -> V_69 ;
struct V_20 * V_21 = V_3 -> V_123 ;
struct V_8 * V_9 = V_3 -> V_8 ;
int V_76 , V_136 = V_137 ;
struct V_27 * V_63 , * V_28 ;
F_34 ( V_23 ) ;
F_28 ( & V_30 -> V_70 ) ;
F_35 ( & V_30 -> V_73 , & V_23 ) ;
V_30 -> V_68 = 0 ;
V_30 -> V_69 = NULL ;
F_29 ( & V_30 -> V_70 ) ;
V_138:
V_76 = V_77 ;
V_7 = F_8 ( V_3 , V_21 , & V_23 ) ;
if ( ! V_7 )
goto V_80;
F_33 ( V_133 , V_3 , L_3
L_5 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,
( V_136 == V_137 ) ? L_6 : L_7 ) ;
V_76 = F_24 ( V_9 , NULL , V_7 , 1 ) ;
F_7 ( V_7 ) ;
if ( V_76 != V_87 ) {
V_76 = F_31 ( V_3 , V_21 -> V_54 ) ;
if ( V_76 == V_128 && V_136 -- )
goto V_138;
}
if ( V_76 == V_87 ) {
V_21 -> V_95 = V_96 ;
F_33 ( V_133 , V_3 , L_3
L_8 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ) ;
}
V_80:
F_36 (qdata, tmp, &list, entry) {
F_13 ( & V_28 -> V_139 ) ;
if ( V_76 == V_87 )
V_28 -> V_21 -> V_95 = V_96 ;
if ( V_28 -> V_140 )
V_28 -> V_140 ( V_28 -> V_141 , V_76 ) ;
F_14 ( V_28 ) ;
}
return;
}
static int F_37 ( struct V_2 * V_3 ,
T_2 V_142 , void * V_143 )
{
struct V_27 * V_28 ;
struct V_58 * V_30 ;
V_28 = F_38 ( sizeof( * V_28 ) , V_144 ) ;
if ( ! V_28 )
return V_128 ;
V_28 -> V_21 = V_3 -> V_123 ;
V_28 -> V_140 = V_142 ;
V_28 -> V_141 = V_143 ;
V_30 = V_28 -> V_21 -> V_30 ;
F_28 ( & V_30 -> V_70 ) ;
F_39 ( & V_28 -> V_139 , & V_30 -> V_73 ) ;
if ( ! V_30 -> V_68 ) {
V_30 -> V_68 = 1 ;
V_30 -> V_69 = V_3 ;
F_40 ( V_145 , & V_30 -> V_71 ) ;
}
F_29 ( & V_30 -> V_70 ) ;
return V_87 ;
}
static int F_41 ( struct V_2 * V_3 ,
T_2 V_142 , void * V_143 )
{
struct V_20 * V_21 = V_3 -> V_123 ;
int V_76 = V_87 ;
int V_146 = 0 ;
V_76 = F_26 ( V_3 , V_21 ) ;
if ( V_76 != V_87 )
goto V_80;
switch ( V_21 -> V_99 ) {
case V_102 :
if ( V_21 -> V_103 == V_105 )
V_146 = 1 ;
break;
case V_100 :
if ( ( V_21 -> V_103 == V_105 ) &&
( V_21 -> V_108 == V_109 ) )
V_146 = 1 ;
break;
default:
break;
}
if ( V_146 ) {
V_76 = F_37 ( V_3 , V_142 , V_143 ) ;
if ( V_76 == V_87 )
return 0 ;
}
V_80:
if ( V_142 )
V_142 ( V_143 , V_76 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_1 * V_147 )
{
struct V_20 * V_21 = V_3 -> V_123 ;
int V_122 = V_148 ;
if ( V_21 -> V_95 != V_96 ) {
V_122 = V_149 ;
V_147 -> V_12 |= V_150 ;
}
return V_122 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_20 * V_21 = V_3 -> V_123 ;
F_33 ( V_151 , V_3 , L_3
L_9 ,
( char * ) V_21 -> V_30 -> V_61 , V_21 -> V_30 -> V_60 ,
V_121 -> V_124 , V_121 -> V_130 , V_121 -> V_131 ) ;
switch ( V_121 -> V_124 ) {
case V_129 :
if ( V_121 -> V_130 == 0x04 && V_121 -> V_131 == 0x01 )
return V_152 ;
if ( V_121 -> V_130 == 0x04 && V_121 -> V_131 == 0x81 )
return V_153 ;
if ( V_121 -> V_130 == 0x04 && V_121 -> V_131 == 0xA1 )
return V_152 ;
if ( V_121 -> V_130 == 0xA1 && V_121 -> V_131 == 0x02 )
return V_152 ;
break;
case V_132 :
if ( V_121 -> V_130 == 0x94 && V_121 -> V_131 == 0x01 ) {
V_21 -> V_95 = V_106 ;
return V_153 ;
}
break;
case V_127 :
if ( V_121 -> V_130 == 0x29 && V_121 -> V_131 == 0x00 )
return V_152 ;
if ( V_121 -> V_130 == 0x8b && V_121 -> V_131 == 0x02 )
return V_152 ;
break;
}
return V_154 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
int V_76 ;
char V_61 [ V_67 ] ;
char V_62 [ V_64 ] ;
V_21 = F_38 ( sizeof( * V_21 ) , V_144 ) ;
if ( ! V_21 )
return - V_155 ;
V_21 -> V_48 = V_156 ;
V_21 -> V_95 = V_96 ;
V_76 = F_25 ( V_3 , V_21 , V_61 , V_62 ) ;
if ( V_76 != V_87 )
goto V_157;
V_76 = F_27 ( V_3 , V_21 , V_61 , V_62 ) ;
if ( V_76 != V_87 )
goto V_157;
V_76 = F_26 ( V_3 , V_21 ) ;
if ( V_76 != V_87 )
goto V_158;
V_76 = F_30 ( V_3 , V_21 ) ;
if ( V_76 != V_87 )
goto V_158;
F_4 ( V_159 , V_3 ,
L_10 ,
V_160 , V_21 -> V_48 , V_99 [ ( int ) V_21 -> V_99 ] ,
V_103 [ ( int ) V_21 -> V_103 ] ) ;
V_3 -> V_123 = V_21 ;
return 0 ;
V_158:
F_28 ( & V_114 ) ;
F_45 ( & V_21 -> V_30 -> V_57 , F_11 ) ;
F_29 ( & V_114 ) ;
V_157:
F_14 ( V_21 ) ;
return - V_161 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_123 ;
if ( V_21 -> V_30 && V_21 -> V_30 -> V_68 )
F_47 ( V_145 ) ;
F_28 ( & V_114 ) ;
if ( V_21 -> V_30 )
F_45 ( & V_21 -> V_30 -> V_57 , F_11 ) ;
F_29 ( & V_114 ) ;
V_3 -> V_123 = NULL ;
F_14 ( V_21 ) ;
}
static int T_3 F_48 ( void )
{
int V_162 ;
V_162 = F_49 ( & V_163 ) ;
if ( V_162 != 0 ) {
F_50 ( V_164 L_11 ) ;
goto V_80;
}
V_145 = F_51 ( L_12 ) ;
if ( ! V_145 ) {
F_52 ( & V_163 ) ;
F_50 ( V_164 L_13 ) ;
V_162 = - V_161 ;
}
V_80:
return V_162 ;
}
static void T_4 F_53 ( void )
{
F_54 ( V_145 ) ;
F_52 ( & V_163 ) ;
}
