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
static struct V_62 * F_18 ( T_1 * V_66 , T_1 * V_67 ,
char * V_68 )
{
struct V_62 * V_34 , * V_69 ;
F_14 ( & V_64 ) ;
F_9 (tmp, &ctlr_list, node) {
if ( ( memcmp ( V_69 -> V_66 , V_66 , V_70 ) == 0 ) &&
( memcmp ( V_69 -> V_67 , V_67 , V_71 ) == 0 ) ) {
F_19 ( & V_69 -> V_61 ) ;
F_16 ( & V_64 ) ;
return V_69 ;
}
}
V_34 = F_20 ( sizeof( * V_34 ) , V_72 ) ;
if ( ! V_34 )
goto V_73;
memcpy ( V_34 -> V_66 , V_66 , V_70 ) ;
memcpy ( V_34 -> V_67 , V_67 , V_71 ) ;
memcpy ( V_34 -> V_68 , V_68 , V_74 ) ;
if ( V_67 [ 1 ] == 0x31 )
V_34 -> V_75 = 0 ;
else
V_34 -> V_75 = 1 ;
F_21 ( & V_34 -> V_61 ) ;
V_34 -> V_35 = - 1 ;
V_34 -> V_76 = 0 ;
V_34 -> V_77 = NULL ;
F_22 ( & V_34 -> V_78 ) ;
F_23 ( & V_34 -> V_79 , V_80 ) ;
F_24 ( & V_34 -> V_81 ) ;
F_25 ( & V_34 -> V_65 , & V_82 ) ;
V_73:
F_16 ( & V_64 ) ;
return V_34 ;
}
static int F_26 ( struct V_2 * V_3 , int V_40 ,
unsigned int V_83 , struct V_1 * V_25 )
{
struct V_6 * V_10 ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_84 = V_85 ;
V_10 = F_3 ( V_3 , & V_25 -> V_86 , V_83 , V_87 ) ;
if ( ! V_10 )
goto V_73;
V_10 -> V_54 [ 0 ] = V_88 ;
V_10 -> V_54 [ 1 ] = 1 ;
V_10 -> V_54 [ 2 ] = V_40 ;
V_10 -> V_54 [ 4 ] = V_83 ;
V_10 -> V_57 = F_10 ( V_88 ) ;
V_10 -> V_58 = V_25 -> V_58 ;
memset ( V_10 -> V_58 , 0 , V_59 ) ;
V_10 -> V_60 = 0 ;
V_84 = F_27 ( V_12 , NULL , V_10 , 1 ) ;
if ( V_84 == - V_89 )
V_84 = V_90 ;
F_7 ( V_10 ) ;
V_73:
return V_84 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_1 * V_25 ,
char * V_68 )
{
int V_84 , V_91 ;
struct V_92 * V_93 ;
V_84 = F_26 ( V_3 , 0xC8 , sizeof( struct V_92 ) , V_25 ) ;
if ( V_84 == V_94 ) {
V_93 = & V_25 -> V_86 . V_95 ;
if ( V_93 -> V_40 != 0xc8 )
return V_96 ;
if ( V_93 -> V_97 [ 0 ] != 'e' || V_93 -> V_97 [ 1 ] != 'd' ||
V_93 -> V_97 [ 2 ] != 'i' || V_93 -> V_97 [ 3 ] != 'd' )
return V_96 ;
V_25 -> V_52 = V_93 -> V_52 [ 7 ] ;
for( V_91 = 0 ; V_91 < V_74 - 1 ; ++ V_91 )
* ( V_68 + V_91 ) = V_93 -> V_98 [ ( 2 * V_91 ) + 1 ] ;
* ( V_68 + V_74 - 1 ) = '\0' ;
}
return V_84 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_1 * V_25 )
{
int V_84 ;
struct V_99 * V_93 ;
V_25 -> V_100 = V_101 ;
V_84 = F_26 ( V_3 , 0xC9 , sizeof( struct V_99 ) , V_25 ) ;
if ( V_84 == V_94 ) {
V_93 = & V_25 -> V_86 . V_102 ;
if ( ( V_93 -> V_103 >> 5 ) & 0x1 )
V_25 -> V_104 = V_105 ;
else if ( V_93 -> V_103 >> 7 )
V_25 -> V_104 = V_106 ;
else
V_25 -> V_104 = V_107 ;
if ( V_93 -> V_103 & 0x1 )
V_25 -> V_108 = V_109 ;
else {
V_25 -> V_108 = V_110 ;
if ( V_25 -> V_104 == V_107 )
V_25 -> V_100 = V_111 ;
}
if ( V_93 -> V_112 & 0x1 )
V_25 -> V_113 = V_114 ;
else
V_25 -> V_113 = V_115 ;
}
return V_84 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_1 * V_25 , char * V_68 )
{
int V_84 ;
struct V_116 * V_93 ;
V_84 = F_26 ( V_3 , 0xC4 , sizeof( struct V_116 ) , V_25 ) ;
if ( V_84 == V_94 ) {
V_93 = & V_25 -> V_86 . V_117 ;
V_25 -> V_34 = F_18 ( V_93 -> V_66 , V_93 -> V_67 ,
V_68 ) ;
if ( ! V_25 -> V_34 )
V_84 = V_85 ;
}
return V_84 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_25 )
{
int V_84 ;
struct V_118 * V_93 ;
V_84 = F_26 ( V_3 , 0xC2 , sizeof( struct V_118 ) , V_25 ) ;
if ( V_84 == V_94 ) {
V_93 = & V_25 -> V_86 . V_119 ;
if ( V_93 -> V_120 >= V_121 )
V_25 -> V_34 -> V_35 = 1 ;
else
V_25 -> V_34 -> V_35 = 0 ;
}
return V_84 ;
}
static int F_32 ( struct V_2 * V_3 ,
unsigned char * V_122 )
{
struct V_123 V_124 ;
int V_84 = V_90 , V_125 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_125 = F_33 ( V_122 , V_59 , & V_124 ) ;
if ( ! V_125 )
goto V_73;
switch ( V_124 . V_126 ) {
case V_127 :
case V_128 :
case V_129 :
V_84 = V_130 ;
break;
case V_131 :
if ( V_124 . V_132 == 0x04 && V_124 . V_133 == 0x01 )
V_84 = V_130 ;
break;
case V_134 :
if ( V_124 . V_132 == 0x91 && V_124 . V_133 == 0x36 )
V_84 = V_130 ;
break;
default:
break;
}
F_34 ( V_135 , V_3 , L_3
L_4 ,
( char * ) V_25 -> V_34 -> V_68 , V_25 -> V_34 -> V_75 ,
V_124 . V_126 , V_124 . V_132 , V_124 . V_133 ) ;
V_73:
return V_84 ;
}
static void V_80 ( struct V_136 * V_137 )
{
struct V_62 * V_34 =
F_12 ( V_137 , struct V_62 , V_79 ) ;
struct V_6 * V_10 ;
struct V_2 * V_3 = V_34 -> V_77 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_11 * V_12 = V_3 -> V_11 ;
int V_84 , V_138 = V_139 ;
struct V_31 * V_69 , * V_32 ;
F_35 ( V_27 ) ;
F_14 ( & V_34 -> V_78 ) ;
F_36 ( & V_34 -> V_81 , & V_27 ) ;
V_34 -> V_76 = 0 ;
V_34 -> V_77 = NULL ;
F_16 ( & V_34 -> V_78 ) ;
V_140:
V_84 = V_85 ;
V_10 = F_8 ( V_3 , V_25 , & V_27 ) ;
if ( ! V_10 )
goto V_73;
F_34 ( V_135 , V_3 , L_3
L_5 ,
( char * ) V_25 -> V_34 -> V_68 , V_25 -> V_34 -> V_75 ,
( V_138 == V_139 ) ? L_6 : L_7 ) ;
V_84 = F_27 ( V_12 , NULL , V_10 , 1 ) ;
F_7 ( V_10 ) ;
if ( V_84 != V_94 ) {
V_84 = F_32 ( V_3 , V_25 -> V_58 ) ;
if ( V_84 == V_130 && V_138 -- )
goto V_140;
}
if ( V_84 == V_94 ) {
V_25 -> V_100 = V_101 ;
F_34 ( V_135 , V_3 , L_3
L_8 ,
( char * ) V_25 -> V_34 -> V_68 , V_25 -> V_34 -> V_75 ) ;
}
V_73:
F_37 (qdata, tmp, &list, entry) {
F_15 ( & V_32 -> V_141 ) ;
if ( V_84 == V_94 )
V_32 -> V_25 -> V_100 = V_101 ;
if ( V_32 -> V_142 )
V_32 -> V_142 ( V_32 -> V_143 , V_84 ) ;
F_17 ( V_32 ) ;
}
return;
}
static int F_38 ( struct V_2 * V_3 ,
T_2 V_144 , void * V_145 )
{
struct V_31 * V_32 ;
struct V_62 * V_34 ;
V_32 = F_39 ( sizeof( * V_32 ) , V_146 ) ;
if ( ! V_32 )
return V_130 ;
V_32 -> V_25 = F_1 ( V_3 ) ;
V_32 -> V_142 = V_144 ;
V_32 -> V_143 = V_145 ;
V_34 = V_32 -> V_25 -> V_34 ;
F_14 ( & V_34 -> V_78 ) ;
F_40 ( & V_32 -> V_141 , & V_34 -> V_81 ) ;
if ( ! V_34 -> V_76 ) {
V_34 -> V_76 = 1 ;
V_34 -> V_77 = V_3 ;
F_41 ( V_63 , & V_34 -> V_79 ) ;
}
F_16 ( & V_34 -> V_78 ) ;
return V_94 ;
}
static int F_42 ( struct V_2 * V_3 ,
T_2 V_144 , void * V_145 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_84 = V_94 ;
int V_147 = 0 ;
V_84 = F_29 ( V_3 , V_25 ) ;
if ( V_84 != V_94 )
goto V_73;
switch ( V_25 -> V_104 ) {
case V_107 :
if ( V_25 -> V_108 == V_110 )
V_147 = 1 ;
break;
case V_105 :
if ( ( V_25 -> V_108 == V_110 ) &&
( V_25 -> V_113 == V_114 ) )
V_147 = 1 ;
break;
default:
break;
}
if ( V_147 ) {
V_84 = F_38 ( V_3 , V_144 , V_145 ) ;
if ( V_84 == V_94 )
return 0 ;
}
V_73:
if ( V_144 )
V_144 ( V_145 , V_84 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_6 * V_148 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_125 = V_149 ;
if ( V_25 -> V_100 != V_101 ) {
V_125 = V_150 ;
V_148 -> V_17 |= V_151 ;
}
return V_125 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_123 * V_124 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_34 ( V_152 , V_3 , L_3
L_9 ,
( char * ) V_25 -> V_34 -> V_68 , V_25 -> V_34 -> V_75 ,
V_124 -> V_126 , V_124 -> V_132 , V_124 -> V_133 ) ;
switch ( V_124 -> V_126 ) {
case V_131 :
if ( V_124 -> V_132 == 0x04 && V_124 -> V_133 == 0x01 )
return V_153 ;
if ( V_124 -> V_132 == 0x04 && V_124 -> V_133 == 0x81 )
return V_154 ;
if ( V_124 -> V_132 == 0x04 && V_124 -> V_133 == 0xA1 )
return V_153 ;
if ( V_124 -> V_132 == 0xA1 && V_124 -> V_133 == 0x02 )
return V_153 ;
break;
case V_134 :
if ( V_124 -> V_132 == 0x94 && V_124 -> V_133 == 0x01 ) {
V_25 -> V_100 = V_111 ;
return V_154 ;
}
break;
case V_129 :
if ( V_124 -> V_132 == 0x29 && V_124 -> V_133 == 0x00 )
return V_153 ;
if ( V_124 -> V_132 == 0x8b && V_124 -> V_133 == 0x02 )
return V_153 ;
break;
}
return V_155 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_25 ;
unsigned long V_156 ;
int V_84 ;
char V_68 [ V_74 ] ;
V_4 = F_39 ( sizeof( * V_4 )
+ sizeof( * V_25 ) , V_146 ) ;
if ( ! V_4 ) {
F_5 ( V_157 , V_3 , L_10 ,
V_158 ) ;
return 0 ;
}
V_4 -> V_159 = & V_160 ;
V_25 = (struct V_1 * ) V_4 -> V_5 ;
V_25 -> V_52 = V_161 ;
V_25 -> V_100 = V_101 ;
V_84 = F_28 ( V_3 , V_25 , V_68 ) ;
if ( V_84 != V_94 )
goto V_162;
V_84 = F_30 ( V_3 , V_25 , V_68 ) ;
if ( V_84 != V_94 )
goto V_162;
V_84 = F_29 ( V_3 , V_25 ) ;
if ( V_84 != V_94 )
goto V_163;
V_84 = F_31 ( V_3 , V_25 ) ;
if ( V_84 != V_94 )
goto V_163;
if ( ! F_46 ( V_164 ) )
goto V_163;
F_47 ( V_3 -> V_11 -> V_165 , V_156 ) ;
V_3 -> V_4 = V_4 ;
F_48 ( V_3 -> V_11 -> V_165 , V_156 ) ;
F_5 ( V_166 , V_3 ,
L_11 ,
V_158 , V_25 -> V_52 , V_104 [ ( int ) V_25 -> V_104 ] ,
V_108 [ ( int ) V_25 -> V_108 ] ) ;
return 0 ;
V_163:
F_49 ( & V_25 -> V_34 -> V_61 , F_11 ) ;
V_162:
F_17 ( V_4 ) ;
F_5 ( V_157 , V_3 , L_12 ,
V_158 ) ;
return - V_167 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_25 ;
unsigned long V_156 ;
F_47 ( V_3 -> V_11 -> V_165 , V_156 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_48 ( V_3 -> V_11 -> V_165 , V_156 ) ;
V_25 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_25 -> V_34 )
F_49 ( & V_25 -> V_34 -> V_61 , F_11 ) ;
F_17 ( V_4 ) ;
F_51 ( V_164 ) ;
F_5 ( V_166 , V_3 , L_13 , V_158 ) ;
}
static int T_3 F_52 ( void )
{
int V_168 ;
V_168 = F_53 ( & V_160 ) ;
if ( V_168 != 0 ) {
F_54 ( V_157 L_14 ) ;
goto V_73;
}
V_63 = F_55 ( L_15 ) ;
if ( ! V_63 ) {
F_56 ( & V_160 ) ;
F_54 ( V_157 L_16 ) ;
}
V_73:
return V_168 ;
}
static void T_4 F_57 ( void )
{
F_58 ( V_63 ) ;
F_56 ( & V_160 ) ;
}
