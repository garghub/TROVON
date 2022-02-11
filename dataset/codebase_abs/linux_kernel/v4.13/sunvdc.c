static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
return V_4 -> V_3 . V_7 . V_5 == V_5 && V_4 -> V_3 . V_7 . V_6 >= V_6 ;
}
static inline T_2 F_4 ( struct V_8 * V_9 )
{
return F_5 ( V_9 , V_10 ) ;
}
static int F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_3 V_18 = F_7 ( V_16 ) ;
T_3 V_19 = V_18 ;
V_14 -> V_20 = 0xff ;
V_14 -> V_21 = 0x3f ;
F_8 ( V_19 , V_14 -> V_20 * V_14 -> V_21 ) ;
V_14 -> V_19 = V_19 ;
if ( ( T_3 ) ( V_14 -> V_19 + 1 ) * V_14 -> V_20 * V_14 -> V_21 < V_18 )
V_14 -> V_19 = 0xffff ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 , T_4 V_22 ,
unsigned V_23 , unsigned long V_24 )
{
int V_25 ;
struct V_15 * V_16 ;
switch ( V_23 ) {
case V_26 :
F_10 ( V_27 L_1 ) ;
for ( V_25 = 0 ; V_25 < sizeof( struct V_28 ) ; V_25 ++ )
if ( F_11 ( 0 , ( char V_29 * ) ( V_24 + V_25 ) ) )
return - V_30 ;
return 0 ;
case V_31 :
V_16 = V_12 -> V_17 ;
if ( V_12 -> V_17 && ( V_16 -> V_32 & V_33 ) )
return 0 ;
return - V_34 ;
default:
F_10 ( V_27 L_2 , V_23 ) ;
return - V_34 ;
}
}
static void F_12 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
if ( V_4 -> V_16 && F_13 ( V_4 -> V_16 -> V_37 ) &&
F_4 ( V_9 ) * 100 / V_10 >= 50 ) {
F_14 ( V_4 -> V_16 -> V_37 ) ;
}
}
static void F_15 ( struct V_2 * V_3 , int V_38 , int V_39 )
{
if ( V_3 -> V_40 &&
( V_39 == - 1 ||
V_3 -> V_40 -> V_39 == V_39 ) ) {
V_3 -> V_40 -> V_38 = V_38 ;
F_16 ( & V_3 -> V_40 -> V_41 ) ;
V_3 -> V_40 = NULL ;
}
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( & V_4 -> V_42 ) ;
F_15 ( V_3 , 0 , V_43 ) ;
F_12 ( V_4 ) ;
}
static int F_19 ( struct V_1 * V_4 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
F_20 (KERN_ERR PFX L_3 ,
pkt->type, pkt->stype, pkt->stype_env, pkt->sid) ;
F_20 (KERN_ERR PFX L_4 ) ;
F_21 ( V_4 -> V_3 . V_47 ) ;
return - V_48 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_49 V_46 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_50 . type = V_51 ;
V_46 . V_50 . V_52 = V_53 ;
V_46 . V_50 . V_54 = V_55 ;
V_46 . V_50 . V_56 = F_23 ( V_3 ) ;
V_46 . V_57 = V_58 ;
V_46 . V_59 = V_4 -> V_59 ;
V_46 . V_60 = V_4 -> V_60 ;
F_24 ( V_61 , L_5 ,
V_46 . V_57 , V_46 . V_59 , V_46 . V_60 ) ;
return F_25 ( & V_4 -> V_3 , & V_46 , sizeof( V_46 ) ) ;
}
static int F_26 ( struct V_2 * V_3 , void * V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_49 * V_46 = V_44 ;
F_24 ( V_61 , L_6
L_7 ,
V_46 -> V_50 . V_52 , V_46 -> V_62 ,
V_46 -> V_63 , V_46 -> V_64 , V_46 -> V_65 ,
V_46 -> V_57 , V_46 -> V_59 ,
V_46 -> V_60 ) ;
if ( V_46 -> V_50 . V_52 == V_66 ) {
switch ( V_46 -> V_64 ) {
case V_67 :
case V_68 :
break;
default:
F_20 (KERN_ERR PFX L_8 ,
vio->name, pkt->vdisk_type) ;
return - V_48 ;
}
if ( V_46 -> V_59 > V_4 -> V_59 ) {
F_20 (KERN_ERR PFX L_9
L_10 ,
vio->name,
port->vdisk_block_size, pkt->vdisk_block_size) ;
return - V_48 ;
}
V_4 -> V_62 = V_46 -> V_62 ;
V_4 -> V_64 = V_46 -> V_64 ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
V_4 -> V_63 = V_46 -> V_63 ;
V_4 -> V_65 = V_46 -> V_65 ;
}
if ( V_46 -> V_60 < V_4 -> V_60 )
V_4 -> V_60 = V_46 -> V_60 ;
V_4 -> V_59 = V_46 -> V_59 ;
V_4 -> V_69 = V_70 ;
if ( F_3 ( V_4 , 1 , 2 ) )
V_4 -> V_69 = V_46 -> V_71 ;
return 0 ;
} else {
F_20 (KERN_ERR PFX L_11 , vio->name) ;
return - V_48 ;
}
}
static void F_27 ( struct V_1 * V_4 , struct V_72 * V_73 )
{
int V_38 = V_73 -> V_74 ;
F_15 ( & V_4 -> V_3 , - V_38 , V_75 ) ;
}
static void F_28 ( struct V_1 * V_4 , struct V_8 * V_9 ,
unsigned int V_76 )
{
struct V_72 * V_73 = F_29 ( V_9 , V_76 ) ;
struct V_77 * V_78 = & V_4 -> V_79 [ V_76 ] ;
struct V_80 * V_81 ;
if ( F_30 ( V_73 -> V_82 . V_83 != V_84 ) )
return;
F_31 ( V_4 -> V_3 . V_47 , V_73 -> V_85 , V_73 -> V_86 ) ;
V_73 -> V_82 . V_83 = V_87 ;
V_9 -> V_88 = F_32 ( V_9 , V_76 ) ;
V_81 = V_78 -> V_81 ;
if ( V_81 == NULL ) {
F_27 ( V_4 , V_73 ) ;
return;
}
V_78 -> V_81 = NULL ;
F_33 ( V_81 , ( V_73 -> V_74 ? V_89 : 0 ) , V_73 -> V_90 ) ;
F_12 ( V_4 ) ;
}
static int F_34 ( struct V_1 * V_4 , void * V_91 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
struct V_92 * V_46 = V_91 ;
if ( F_30 ( V_46 -> V_93 != V_9 -> V_94 ||
V_46 -> V_95 != V_46 -> V_96 ||
V_46 -> V_95 >= V_10 ) )
return 0 ;
F_28 ( V_4 , V_9 , V_46 -> V_95 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_4 , void * V_91 )
{
return 0 ;
}
static void F_36 ( void * V_44 , int V_97 )
{
struct V_1 * V_4 = V_44 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
unsigned long V_32 ;
int V_38 ;
F_37 ( & V_3 -> V_98 , V_32 ) ;
if ( F_30 ( V_97 == V_99 ) ) {
F_38 ( V_3 , V_97 ) ;
F_39 ( V_100 , & V_4 -> V_101 ) ;
goto V_102;
}
if ( F_30 ( V_97 == V_103 ) ) {
F_38 ( V_3 , V_97 ) ;
goto V_102;
}
if ( F_30 ( V_97 != V_104 ) ) {
F_40 ( V_27 L_12 , V_97 ) ;
goto V_102;
}
V_38 = 0 ;
while ( 1 ) {
union {
struct V_45 V_50 ;
T_5 V_105 [ 8 ] ;
} V_91 ;
V_38 = F_41 ( V_3 -> V_47 , & V_91 , sizeof( V_91 ) ) ;
if ( F_30 ( V_38 < 0 ) ) {
if ( V_38 == - V_48 )
F_42 ( V_3 ) ;
break;
}
if ( V_38 == 0 )
break;
F_24 ( V_106 , L_13 ,
V_91 . V_50 . type ,
V_91 . V_50 . V_52 ,
V_91 . V_50 . V_54 ,
V_91 . V_50 . V_56 ) ;
V_38 = F_43 ( V_3 , & V_91 . V_50 ) ;
if ( V_38 < 0 )
break;
if ( F_44 ( V_91 . V_50 . type == V_107 ) ) {
if ( V_91 . V_50 . V_52 == V_66 )
V_38 = F_34 ( V_4 , & V_91 ) ;
else if ( V_91 . V_50 . V_52 == V_108 )
V_38 = F_35 ( V_4 , & V_91 ) ;
else
V_38 = F_19 ( V_4 , & V_91 ) ;
} else if ( V_91 . V_50 . type == V_51 ) {
V_38 = F_45 ( V_3 , & V_91 ) ;
} else {
V_38 = F_19 ( V_4 , & V_91 ) ;
}
if ( V_38 < 0 )
break;
}
if ( V_38 < 0 )
F_15 ( & V_4 -> V_3 , V_38 , V_109 ) ;
V_102:
F_46 ( & V_3 -> V_98 , V_32 ) ;
}
static int F_47 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
struct V_92 V_82 = {
. V_50 = {
. type = V_107 ,
. V_52 = V_53 ,
. V_54 = V_110 ,
. V_56 = F_23 ( & V_4 -> V_3 ) ,
} ,
. V_93 = V_9 -> V_94 ,
. V_95 = V_9 -> V_111 ,
. V_96 = V_9 -> V_111 ,
} ;
int V_38 , V_112 ;
V_82 . V_113 = V_9 -> V_114 ;
V_112 = 1 ;
do {
V_38 = F_25 ( & V_4 -> V_3 , & V_82 , sizeof( V_82 ) ) ;
if ( V_38 > 0 ) {
V_9 -> V_114 ++ ;
break;
}
F_48 ( V_112 ) ;
if ( ( V_112 <<= 1 ) > 128 )
V_112 = 128 ;
} while ( V_38 == - V_115 );
if ( V_38 == - V_116 )
F_49 ( V_4 ) ;
return V_38 ;
}
static int F_50 ( struct V_80 * V_81 )
{
struct V_1 * V_4 = V_81 -> V_117 -> V_118 ;
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
struct V_119 V_120 [ V_4 -> V_121 ] ;
struct V_77 * V_78 ;
struct V_72 * V_73 ;
unsigned int V_122 ;
int V_123 , V_38 , V_25 ;
T_5 V_124 ;
T_6 V_125 ;
V_122 = V_126 | V_127 | V_128 ;
if ( F_51 ( V_81 ) == V_129 ) {
V_122 |= V_130 ;
V_125 = V_131 ;
} else {
V_122 |= V_132 ;
V_125 = V_133 ;
}
F_52 ( V_120 , V_4 -> V_121 ) ;
V_123 = F_53 ( V_81 -> V_134 , V_81 , V_120 ) ;
V_124 = 0 ;
for ( V_25 = 0 ; V_25 < V_123 ; V_25 ++ )
V_124 += V_120 [ V_25 ] . V_135 ;
V_73 = F_54 ( V_9 ) ;
V_38 = F_55 ( V_4 -> V_3 . V_47 , V_120 , V_123 ,
V_73 -> V_85 , V_4 -> V_121 ,
V_122 ) ;
if ( V_38 < 0 ) {
F_20 (KERN_ERR PFX L_14 , err) ;
return V_38 ;
}
V_78 = & V_4 -> V_79 [ V_9 -> V_111 ] ;
V_78 -> V_81 = V_81 ;
V_73 -> V_82 . V_136 = V_137 ;
V_73 -> V_138 = V_4 -> V_138 ;
V_73 -> V_139 = V_125 ;
if ( V_4 -> V_64 == V_67 ) {
V_73 -> V_140 = 0xff ;
} else {
V_73 -> V_140 = 0 ;
}
V_73 -> V_74 = ~ 0 ;
V_73 -> V_141 = ( F_56 ( V_81 ) << 9 ) / V_4 -> V_59 ;
V_73 -> V_90 = V_124 ;
V_73 -> V_86 = V_38 ;
F_57 () ;
V_73 -> V_82 . V_83 = V_142 ;
V_38 = F_47 ( V_4 ) ;
if ( V_38 < 0 ) {
F_20 (KERN_ERR PFX L_15 , err) ;
} else {
V_4 -> V_138 ++ ;
V_9 -> V_111 = F_32 ( V_9 , V_9 -> V_111 ) ;
}
return V_38 ;
}
static void F_58 ( struct V_143 * V_144 )
{
struct V_80 * V_81 ;
while ( ( V_81 = F_59 ( V_144 ) ) != NULL ) {
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_4 = V_81 -> V_117 -> V_118 ;
V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
if ( F_30 ( F_4 ( V_9 ) < 1 ) )
goto V_145;
F_60 ( V_81 ) ;
if ( F_50 ( V_81 ) < 0 ) {
F_61 ( V_144 , V_81 ) ;
V_145:
F_62 ( V_144 ) ;
break;
}
}
}
static int F_63 ( struct V_1 * V_4 , T_6 V_125 , void * V_146 , int V_124 )
{
struct V_8 * V_9 ;
struct V_147 V_148 ;
struct V_72 * V_73 ;
unsigned int V_122 ;
unsigned long V_32 ;
int V_149 , V_38 ;
void * V_150 ;
if ( ! ( ( ( T_5 ) 1 << ( T_5 ) V_125 ) & V_4 -> V_62 ) )
return - V_151 ;
switch ( V_125 ) {
case V_131 :
case V_133 :
default:
return - V_34 ;
case V_152 :
V_149 = 0 ;
V_122 = 0 ;
break;
case V_153 :
V_149 = sizeof( T_2 ) ;
V_122 = V_130 ;
break;
case V_154 :
V_149 = sizeof( T_2 ) ;
V_122 = V_132 ;
break;
case V_155 :
V_149 = sizeof( struct V_156 ) ;
V_122 = V_130 ;
break;
case V_157 :
V_149 = sizeof( struct V_156 ) ;
V_122 = V_132 ;
break;
case V_158 :
V_149 = sizeof( struct V_159 ) ;
V_122 = V_130 ;
break;
case V_160 :
V_149 = sizeof( struct V_159 ) ;
V_122 = V_132 ;
break;
case V_161 :
V_149 = 16 ;
V_122 = V_162 ;
break;
case V_163 :
V_149 = sizeof( struct V_164 ) ;
V_122 = V_130 ;
break;
case V_165 :
case V_166 :
return - V_151 ;
break;
} ;
V_122 |= V_126 | V_127 | V_128 ;
V_149 = ( V_149 + 7 ) & ~ 7 ;
V_150 = F_64 ( V_149 , V_167 ) ;
if ( ! V_150 )
return - V_168 ;
if ( V_124 > V_149 )
V_124 = V_149 ;
if ( V_122 & V_132 )
memcpy ( V_150 , V_146 , V_124 ) ;
F_37 ( & V_4 -> V_3 . V_98 , V_32 ) ;
V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
V_73 = F_54 ( V_9 ) ;
V_38 = F_65 ( V_4 -> V_3 . V_47 , V_150 , V_149 ,
V_73 -> V_85 , V_4 -> V_121 ,
V_122 ) ;
if ( V_38 < 0 ) {
F_46 ( & V_4 -> V_3 . V_98 , V_32 ) ;
F_66 ( V_150 ) ;
return V_38 ;
}
F_67 ( & V_148 . V_41 ) ;
V_148 . V_39 = V_75 ;
V_4 -> V_3 . V_40 = & V_148 ;
V_73 -> V_82 . V_136 = V_137 ;
V_73 -> V_138 = V_4 -> V_138 ;
V_73 -> V_139 = V_125 ;
V_73 -> V_140 = 0 ;
V_73 -> V_74 = ~ 0 ;
V_73 -> V_141 = 0 ;
V_73 -> V_90 = V_149 ;
V_73 -> V_86 = V_38 ;
F_57 () ;
V_73 -> V_82 . V_83 = V_142 ;
V_38 = F_47 ( V_4 ) ;
if ( V_38 >= 0 ) {
V_4 -> V_138 ++ ;
V_9 -> V_111 = F_32 ( V_9 , V_9 -> V_111 ) ;
F_46 ( & V_4 -> V_3 . V_98 , V_32 ) ;
F_68 ( & V_148 . V_41 ) ;
V_38 = V_148 . V_38 ;
} else {
V_4 -> V_3 . V_40 = NULL ;
F_46 ( & V_4 -> V_3 . V_98 , V_32 ) ;
}
if ( V_122 & V_130 )
memcpy ( V_146 , V_150 , V_124 ) ;
F_66 ( V_150 ) ;
return V_38 ;
}
static int F_69 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
unsigned long V_124 , V_169 ;
int V_86 ;
void * V_170 ;
V_169 = sizeof( struct V_72 ) +
( sizeof( struct V_171 ) * V_4 -> V_121 ) ;
V_124 = ( V_10 * V_169 ) ;
V_86 = V_172 ;
V_170 = F_70 ( V_4 -> V_3 . V_47 , V_124 ,
V_9 -> V_85 , & V_86 ,
( V_126 |
V_127 |
V_162 ) ) ;
if ( F_71 ( V_170 ) )
return F_72 ( V_170 ) ;
V_9 -> V_173 = V_170 ;
V_9 -> V_169 = V_169 ;
V_9 -> V_174 = V_10 ;
V_9 -> V_111 = V_9 -> V_88 = 0 ;
V_9 -> V_175 = V_10 ;
V_9 -> V_86 = V_86 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
if ( V_9 -> V_173 ) {
F_74 ( V_4 -> V_3 . V_47 , V_9 -> V_173 ,
( V_9 -> V_169 * V_9 -> V_174 ) ,
V_9 -> V_85 , V_9 -> V_86 ) ;
V_9 -> V_173 = NULL ;
V_9 -> V_169 = 0 ;
V_9 -> V_174 = 0 ;
V_9 -> V_175 = 0 ;
V_9 -> V_86 = 0 ;
}
}
static int F_75 ( struct V_1 * V_4 )
{
struct V_147 V_148 ;
F_67 ( & V_148 . V_41 ) ;
V_148 . V_38 = 0 ;
V_148 . V_39 = V_43 ;
V_4 -> V_3 . V_40 = & V_148 ;
F_76 ( & V_4 -> V_3 ) ;
F_68 ( & V_148 . V_41 ) ;
return V_148 . V_38 ;
}
static void F_77 ( struct V_1 * V_4 )
{
F_21 ( V_4 -> V_3 . V_47 ) ;
F_78 ( V_4 -> V_3 . V_47 ) ;
F_73 ( V_4 ) ;
F_79 ( & V_4 -> V_3 ) ;
}
static int F_80 ( struct V_1 * V_4 )
{
struct V_143 * V_134 ;
struct V_15 * V_176 ;
int V_38 ;
V_38 = F_75 ( V_4 ) ;
if ( V_38 )
return V_38 ;
if ( F_3 ( V_4 , 1 , 2 ) && ! V_4 -> V_69 )
return - V_177 ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
if ( V_4 -> V_63 == - 1 )
return - V_177 ;
} else {
struct V_159 V_178 ;
V_38 = F_63 ( V_4 , V_158 ,
& V_178 , sizeof( V_178 ) ) ;
if ( V_38 < 0 ) {
F_20 (KERN_ERR PFX L_16
L_17 , err) ;
return V_38 ;
}
V_4 -> V_63 = ( ( T_5 ) V_178 . V_179 *
( T_5 ) V_178 . V_180 *
( T_5 ) V_178 . V_181 ) ;
}
V_134 = F_81 ( F_58 , & V_4 -> V_3 . V_98 ) ;
if ( ! V_134 ) {
F_20 (KERN_ERR PFX L_18 ,
port->vio.name) ;
return - V_168 ;
}
V_176 = F_82 ( 1 << V_182 ) ;
if ( ! V_176 ) {
F_20 (KERN_ERR PFX L_19 ,
port->vio.name) ;
F_83 ( V_134 ) ;
return - V_168 ;
}
V_4 -> V_16 = V_176 ;
F_84 ( V_134 , V_183 - 1 ) ;
F_85 ( V_134 , V_183 ) ;
F_86 ( V_134 , V_4 -> V_121 ) ;
F_87 ( V_134 , V_4 -> V_60 ) ;
V_176 -> V_5 = V_184 ;
V_176 -> V_185 = V_4 -> V_3 . V_186 -> V_187 << V_182 ;
strcpy ( V_176 -> V_188 , V_4 -> V_188 ) ;
V_176 -> V_189 = & V_190 ;
V_176 -> V_37 = V_134 ;
V_176 -> V_118 = V_4 ;
F_88 ( V_176 , V_4 -> V_63 ) ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
switch ( V_4 -> V_65 ) {
case V_191 :
F_89 ( V_27 L_20 , V_4 -> V_188 ) ;
V_176 -> V_32 |= V_33 ;
V_176 -> V_32 |= V_192 ;
F_90 ( V_176 , 1 ) ;
break;
case V_193 :
F_89 ( V_27 L_21 , V_4 -> V_188 ) ;
V_176 -> V_32 |= V_33 ;
V_176 -> V_32 |= V_192 ;
F_90 ( V_176 , 1 ) ;
break;
case V_194 :
F_89 ( V_27 L_22 , V_4 -> V_188 ) ;
break;
}
}
F_91 ( V_134 , V_4 -> V_69 ) ;
F_89 ( V_27 L_23 ,
V_176 -> V_188 ,
V_4 -> V_63 , ( V_4 -> V_63 >> ( 20 - 9 ) ) ,
V_4 -> V_3 . V_7 . V_5 , V_4 -> V_3 . V_7 . V_6 ) ;
F_92 ( & V_4 -> V_3 . V_186 -> V_195 , V_176 ) ;
return 0 ;
}
static void F_93 ( void )
{
static int V_196 ;
if ( V_196 ++ == 0 )
F_20 ( V_197 L_24 , V_198 ) ;
}
static int F_94 ( struct V_199 * V_195 , void * V_44 )
{
struct V_200 * V_186 = F_95 ( V_195 ) ;
struct V_201 * V_202 ;
V_202 = (struct V_201 * ) V_44 ;
if ( ( V_186 -> V_187 == V_202 -> V_187 ) &&
( ! ( strcmp ( ( char * ) & V_186 -> type , V_202 -> type ) ) ) &&
F_96 ( V_195 ) ) {
return 1 ;
} else {
return 0 ;
}
}
static bool F_97 ( struct V_200 * V_186 )
{
struct V_201 V_202 ;
struct V_199 * V_195 ;
V_202 . V_187 = V_186 -> V_187 ;
V_202 . type = ( char * ) & V_186 -> type ;
V_195 = F_98 ( V_186 -> V_195 . V_203 , & V_202 ,
F_94 ) ;
if ( V_195 )
return true ;
return false ;
}
static int F_99 ( struct V_200 * V_186 , const struct V_204 * V_205 )
{
struct V_206 * V_207 ;
struct V_1 * V_4 ;
int V_38 ;
const T_5 * V_208 ;
F_93 () ;
V_207 = F_100 () ;
V_38 = - V_177 ;
if ( ( V_186 -> V_187 << V_182 ) & ~ ( T_5 ) V_209 ) {
F_20 (KERN_ERR PFX L_25 ,
vdev->dev_no) ;
goto V_210;
}
if ( F_97 ( V_186 ) ) {
F_20 ( V_211
L_26 ,
F_101 ( & V_186 -> V_195 ) ) ;
goto V_210;
}
V_4 = F_64 ( sizeof( * V_4 ) , V_167 ) ;
V_38 = - V_168 ;
if ( ! V_4 ) {
F_20 (KERN_ERR PFX L_27 ) ;
goto V_210;
}
if ( V_186 -> V_187 >= 26 )
snprintf ( V_4 -> V_188 , sizeof( V_4 -> V_188 ) ,
V_212 L_28 ,
'a' + ( ( int ) V_186 -> V_187 / 26 ) - 1 ,
'a' + ( ( int ) V_186 -> V_187 % 26 ) ) ;
else
snprintf ( V_4 -> V_188 , sizeof( V_4 -> V_188 ) ,
V_212 L_29 , 'a' + ( ( int ) V_186 -> V_187 % 26 ) ) ;
V_4 -> V_63 = - 1 ;
V_208 = F_102 ( V_207 , V_186 -> V_213 , L_30 , NULL ) ;
V_4 -> V_208 = V_208 ? * V_208 : 0 ;
F_103 ( & V_4 -> V_42 , V_214 ,
( unsigned long ) V_4 ) ;
F_104 ( & V_4 -> V_101 , V_215 ) ;
V_38 = F_105 ( & V_4 -> V_3 , V_186 , V_216 ,
V_217 , F_106 ( V_217 ) ,
& V_218 , V_4 -> V_188 ) ;
if ( V_38 )
goto V_219;
V_4 -> V_59 = V_70 ;
V_4 -> V_60 = ( ( 128 * 1024 ) / V_4 -> V_59 ) ;
V_4 -> V_121 = ( ( V_4 -> V_60 *
V_4 -> V_59 ) / V_183 ) + 2 ;
V_38 = F_107 ( & V_4 -> V_3 , & V_220 , V_4 ) ;
if ( V_38 )
goto V_219;
V_38 = F_69 ( V_4 ) ;
if ( V_38 )
goto V_221;
V_38 = F_80 ( V_4 ) ;
if ( V_38 )
goto V_222;
F_108 ( & V_186 -> V_195 , V_4 ) ;
F_109 ( V_207 ) ;
return 0 ;
V_222:
F_73 ( V_4 ) ;
V_221:
F_79 ( & V_4 -> V_3 ) ;
V_219:
F_66 ( V_4 ) ;
V_210:
F_109 ( V_207 ) ;
return V_38 ;
}
static int F_110 ( struct V_200 * V_186 )
{
struct V_1 * V_4 = F_96 ( & V_186 -> V_195 ) ;
if ( V_4 ) {
unsigned long V_32 ;
F_37 ( & V_4 -> V_3 . V_98 , V_32 ) ;
F_62 ( V_4 -> V_16 -> V_37 ) ;
F_46 ( & V_4 -> V_3 . V_98 , V_32 ) ;
F_111 ( & V_4 -> V_101 ) ;
F_112 ( & V_4 -> V_42 ) ;
F_112 ( & V_4 -> V_3 . V_223 ) ;
F_113 ( V_4 -> V_16 ) ;
F_83 ( V_4 -> V_16 -> V_37 ) ;
F_114 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
F_73 ( V_4 ) ;
F_79 ( & V_4 -> V_3 ) ;
F_108 ( & V_186 -> V_195 , NULL ) ;
F_66 ( V_4 ) ;
}
return 0 ;
}
static void F_115 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
T_2 V_224 ;
for ( V_224 = V_9 -> V_88 ; V_224 != V_9 -> V_111 ; V_224 = F_32 ( V_9 , V_224 ) ) {
struct V_72 * V_73 = F_29 ( V_9 , V_224 ) ;
struct V_77 * V_78 = & V_4 -> V_79 [ V_224 ] ;
struct V_80 * V_81 ;
F_31 ( V_4 -> V_3 . V_47 , V_73 -> V_85 , V_73 -> V_86 ) ;
V_73 -> V_82 . V_83 = V_87 ;
V_9 -> V_88 = F_32 ( V_9 , V_224 ) ;
V_81 = V_78 -> V_81 ;
if ( V_81 == NULL ) {
F_27 ( V_4 , V_73 ) ;
continue;
}
V_78 -> V_81 = NULL ;
F_61 ( V_4 -> V_16 -> V_37 , V_81 ) ;
}
}
static void F_116 ( struct V_1 * V_4 )
{
struct V_80 * V_81 ;
while ( ( V_81 = F_117 ( V_4 -> V_16 -> V_37 ) ) != NULL )
F_118 ( V_81 , V_89 ) ;
}
static void V_214 ( unsigned long V_225 )
{
struct V_1 * V_4 = (struct V_1 * ) V_225 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
unsigned long V_32 ;
F_37 ( & V_3 -> V_98 , V_32 ) ;
if ( ! ( V_4 -> V_3 . V_226 & V_227 ) ) {
F_40 ( V_27 L_31 ,
V_4 -> V_188 , V_4 -> V_208 ) ;
F_116 ( V_4 ) ;
F_12 ( V_4 ) ;
}
F_46 ( & V_3 -> V_98 , V_32 ) ;
}
static void V_215 ( struct V_228 * V_229 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
V_4 = F_2 ( V_229 , struct V_1 , V_101 ) ;
V_3 = & V_4 -> V_3 ;
F_37 ( & V_3 -> V_98 , V_32 ) ;
F_49 ( V_4 ) ;
F_46 ( & V_3 -> V_98 , V_32 ) ;
}
static void F_49 ( struct V_1 * V_4 )
{
int V_38 ;
F_119 ( & V_4 -> V_3 . V_98 ) ;
F_40 ( V_27 L_32 , V_4 -> V_188 ) ;
F_62 ( V_4 -> V_16 -> V_37 ) ;
F_115 ( V_4 ) ;
F_77 ( V_4 ) ;
V_38 = F_107 ( & V_4 -> V_3 , & V_220 , V_4 ) ;
if ( V_38 ) {
F_120 ( V_27 L_33 , V_4 -> V_188 , V_38 ) ;
return;
}
V_38 = F_69 ( V_4 ) ;
if ( V_38 ) {
F_120 ( V_27 L_34 , V_4 -> V_188 , V_38 ) ;
goto V_230;
}
if ( V_4 -> V_208 )
F_121 ( & V_4 -> V_42 ,
F_122 ( V_231 + V_232 * V_4 -> V_208 ) ) ;
F_121 ( & V_4 -> V_3 . V_223 , F_122 ( V_231 + V_232 ) ) ;
return;
V_230:
F_79 ( & V_4 -> V_3 ) ;
}
static int T_7 F_123 ( void )
{
int V_38 ;
V_100 = F_124 ( L_35 , 0 , 0 ) ;
if ( ! V_100 )
return - V_168 ;
V_38 = F_125 ( 0 , V_212 ) ;
if ( V_38 < 0 )
goto V_233;
V_184 = V_38 ;
V_38 = F_126 ( & V_234 ) ;
if ( V_38 )
goto V_235;
return 0 ;
V_235:
F_127 ( V_184 , V_212 ) ;
V_184 = 0 ;
V_233:
F_128 ( V_100 ) ;
return V_38 ;
}
static void T_8 F_129 ( void )
{
F_130 ( & V_234 ) ;
F_127 ( V_184 , V_212 ) ;
F_128 ( V_100 ) ;
}
