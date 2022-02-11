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
return 0 ;
} else {
F_20 (KERN_ERR PFX L_11 , vio->name) ;
return - V_48 ;
}
}
static void F_27 ( struct V_1 * V_4 , struct V_69 * V_70 )
{
int V_38 = V_70 -> V_71 ;
F_15 ( & V_4 -> V_3 , - V_38 , V_72 ) ;
}
static void F_28 ( struct V_1 * V_4 , struct V_8 * V_9 ,
unsigned int V_73 )
{
struct V_69 * V_70 = F_29 ( V_9 , V_73 ) ;
struct V_74 * V_75 = & V_4 -> V_76 [ V_73 ] ;
struct V_77 * V_78 ;
if ( F_30 ( V_70 -> V_79 . V_80 != V_81 ) )
return;
F_31 ( V_4 -> V_3 . V_47 , V_70 -> V_82 , V_70 -> V_83 ) ;
V_70 -> V_79 . V_80 = V_84 ;
V_9 -> V_85 = F_32 ( V_9 , V_73 ) ;
V_78 = V_75 -> V_78 ;
if ( V_78 == NULL ) {
F_27 ( V_4 , V_70 ) ;
return;
}
V_75 -> V_78 = NULL ;
F_33 ( V_78 , ( V_70 -> V_71 ? - V_86 : 0 ) , V_70 -> V_87 ) ;
F_12 ( V_4 ) ;
}
static int F_34 ( struct V_1 * V_4 , void * V_88 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
struct V_89 * V_46 = V_88 ;
if ( F_30 ( V_46 -> V_90 != V_9 -> V_91 ||
V_46 -> V_92 != V_46 -> V_93 ||
V_46 -> V_92 >= V_10 ) )
return 0 ;
F_28 ( V_4 , V_9 , V_46 -> V_92 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_4 , void * V_88 )
{
return 0 ;
}
static void F_36 ( void * V_44 , int V_94 )
{
struct V_1 * V_4 = V_44 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
unsigned long V_32 ;
int V_38 ;
F_37 ( & V_3 -> V_95 , V_32 ) ;
if ( F_30 ( V_94 == V_96 ) ) {
F_38 ( V_3 , V_94 ) ;
F_39 ( V_97 , & V_4 -> V_98 ) ;
goto V_99;
}
if ( F_30 ( V_94 == V_100 ) ) {
F_38 ( V_3 , V_94 ) ;
goto V_99;
}
if ( F_30 ( V_94 != V_101 ) ) {
F_40 ( V_27 L_12 , V_94 ) ;
goto V_99;
}
V_38 = 0 ;
while ( 1 ) {
union {
struct V_45 V_50 ;
T_5 V_102 [ 8 ] ;
} V_88 ;
V_38 = F_41 ( V_3 -> V_47 , & V_88 , sizeof( V_88 ) ) ;
if ( F_30 ( V_38 < 0 ) ) {
if ( V_38 == - V_48 )
F_42 ( V_3 ) ;
break;
}
if ( V_38 == 0 )
break;
F_24 ( V_103 , L_13 ,
V_88 . V_50 . type ,
V_88 . V_50 . V_52 ,
V_88 . V_50 . V_54 ,
V_88 . V_50 . V_56 ) ;
V_38 = F_43 ( V_3 , & V_88 . V_50 ) ;
if ( V_38 < 0 )
break;
if ( F_44 ( V_88 . V_50 . type == V_104 ) ) {
if ( V_88 . V_50 . V_52 == V_66 )
V_38 = F_34 ( V_4 , & V_88 ) ;
else if ( V_88 . V_50 . V_52 == V_105 )
V_38 = F_35 ( V_4 , & V_88 ) ;
else
V_38 = F_19 ( V_4 , & V_88 ) ;
} else if ( V_88 . V_50 . type == V_51 ) {
V_38 = F_45 ( V_3 , & V_88 ) ;
} else {
V_38 = F_19 ( V_4 , & V_88 ) ;
}
if ( V_38 < 0 )
break;
}
if ( V_38 < 0 )
F_15 ( & V_4 -> V_3 , V_38 , V_106 ) ;
V_99:
F_46 ( & V_3 -> V_95 , V_32 ) ;
}
static int F_47 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
struct V_89 V_79 = {
. V_50 = {
. type = V_104 ,
. V_52 = V_53 ,
. V_54 = V_107 ,
. V_56 = F_23 ( & V_4 -> V_3 ) ,
} ,
. V_90 = V_9 -> V_91 ,
. V_92 = V_9 -> V_108 ,
. V_93 = V_9 -> V_108 ,
} ;
int V_38 , V_109 ;
V_79 . V_110 = V_9 -> V_111 ;
V_109 = 1 ;
do {
V_38 = F_25 ( & V_4 -> V_3 , & V_79 , sizeof( V_79 ) ) ;
if ( V_38 > 0 ) {
V_9 -> V_111 ++ ;
break;
}
F_48 ( V_109 ) ;
if ( ( V_109 <<= 1 ) > 128 )
V_109 = 128 ;
} while ( V_38 == - V_112 );
if ( V_38 == - V_113 )
F_49 ( V_4 ) ;
return V_38 ;
}
static int F_50 ( struct V_77 * V_78 )
{
struct V_1 * V_4 = V_78 -> V_114 -> V_115 ;
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
struct V_116 V_117 [ V_4 -> V_118 ] ;
struct V_74 * V_75 ;
struct V_69 * V_70 ;
unsigned int V_119 ;
int V_120 , V_38 , V_25 ;
T_5 V_121 ;
T_6 V_122 ;
V_119 = V_123 | V_124 | V_125 ;
if ( F_51 ( V_78 ) == V_126 ) {
V_119 |= V_127 ;
V_122 = V_128 ;
} else {
V_119 |= V_129 ;
V_122 = V_130 ;
}
F_52 ( V_117 , V_4 -> V_118 ) ;
V_120 = F_53 ( V_78 -> V_131 , V_78 , V_117 ) ;
V_121 = 0 ;
for ( V_25 = 0 ; V_25 < V_120 ; V_25 ++ )
V_121 += V_117 [ V_25 ] . V_132 ;
V_70 = F_54 ( V_9 ) ;
V_38 = F_55 ( V_4 -> V_3 . V_47 , V_117 , V_120 ,
V_70 -> V_82 , V_4 -> V_118 ,
V_119 ) ;
if ( V_38 < 0 ) {
F_20 (KERN_ERR PFX L_14 , err) ;
return V_38 ;
}
V_75 = & V_4 -> V_76 [ V_9 -> V_108 ] ;
V_75 -> V_78 = V_78 ;
V_70 -> V_79 . V_133 = V_134 ;
V_70 -> V_135 = V_4 -> V_135 ;
V_70 -> V_136 = V_122 ;
if ( V_4 -> V_64 == V_67 ) {
V_70 -> V_137 = 0xff ;
} else {
V_70 -> V_137 = 0 ;
}
V_70 -> V_71 = ~ 0 ;
V_70 -> V_138 = ( F_56 ( V_78 ) << 9 ) / V_4 -> V_59 ;
V_70 -> V_87 = V_121 ;
V_70 -> V_83 = V_38 ;
F_57 () ;
V_70 -> V_79 . V_80 = V_139 ;
V_38 = F_47 ( V_4 ) ;
if ( V_38 < 0 ) {
F_20 (KERN_ERR PFX L_15 , err) ;
} else {
V_4 -> V_135 ++ ;
V_9 -> V_108 = F_32 ( V_9 , V_9 -> V_108 ) ;
}
return V_38 ;
}
static void F_58 ( struct V_140 * V_141 )
{
struct V_77 * V_78 ;
while ( ( V_78 = F_59 ( V_141 ) ) != NULL ) {
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_4 = V_78 -> V_114 -> V_115 ;
V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
if ( F_30 ( F_4 ( V_9 ) < 1 ) )
goto V_142;
F_60 ( V_78 ) ;
if ( F_50 ( V_78 ) < 0 ) {
F_61 ( V_141 , V_78 ) ;
V_142:
F_62 ( V_141 ) ;
break;
}
}
}
static int F_63 ( struct V_1 * V_4 , T_6 V_122 , void * V_143 , int V_121 )
{
struct V_8 * V_9 ;
struct V_144 V_145 ;
struct V_69 * V_70 ;
unsigned int V_119 ;
unsigned long V_32 ;
int V_146 , V_38 ;
void * V_147 ;
if ( ! ( ( ( T_5 ) 1 << ( T_5 ) V_122 ) & V_4 -> V_62 ) )
return - V_148 ;
switch ( V_122 ) {
case V_128 :
case V_130 :
default:
return - V_34 ;
case V_149 :
V_146 = 0 ;
V_119 = 0 ;
break;
case V_150 :
V_146 = sizeof( T_2 ) ;
V_119 = V_127 ;
break;
case V_151 :
V_146 = sizeof( T_2 ) ;
V_119 = V_129 ;
break;
case V_152 :
V_146 = sizeof( struct V_153 ) ;
V_119 = V_127 ;
break;
case V_154 :
V_146 = sizeof( struct V_153 ) ;
V_119 = V_129 ;
break;
case V_155 :
V_146 = sizeof( struct V_156 ) ;
V_119 = V_127 ;
break;
case V_157 :
V_146 = sizeof( struct V_156 ) ;
V_119 = V_129 ;
break;
case V_158 :
V_146 = 16 ;
V_119 = V_159 ;
break;
case V_160 :
V_146 = sizeof( struct V_161 ) ;
V_119 = V_127 ;
break;
case V_162 :
case V_163 :
return - V_148 ;
break;
} ;
V_119 |= V_123 | V_124 | V_125 ;
V_146 = ( V_146 + 7 ) & ~ 7 ;
V_147 = F_64 ( V_146 , V_164 ) ;
if ( ! V_147 )
return - V_165 ;
if ( V_121 > V_146 )
V_121 = V_146 ;
if ( V_119 & V_129 )
memcpy ( V_147 , V_143 , V_121 ) ;
F_37 ( & V_4 -> V_3 . V_95 , V_32 ) ;
V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
V_70 = F_54 ( V_9 ) ;
V_38 = F_65 ( V_4 -> V_3 . V_47 , V_147 , V_146 ,
V_70 -> V_82 , V_4 -> V_118 ,
V_119 ) ;
if ( V_38 < 0 ) {
F_46 ( & V_4 -> V_3 . V_95 , V_32 ) ;
F_66 ( V_147 ) ;
return V_38 ;
}
F_67 ( & V_145 . V_41 ) ;
V_145 . V_39 = V_72 ;
V_4 -> V_3 . V_40 = & V_145 ;
V_70 -> V_79 . V_133 = V_134 ;
V_70 -> V_135 = V_4 -> V_135 ;
V_70 -> V_136 = V_122 ;
V_70 -> V_137 = 0 ;
V_70 -> V_71 = ~ 0 ;
V_70 -> V_138 = 0 ;
V_70 -> V_87 = V_146 ;
V_70 -> V_83 = V_38 ;
F_57 () ;
V_70 -> V_79 . V_80 = V_139 ;
V_38 = F_47 ( V_4 ) ;
if ( V_38 >= 0 ) {
V_4 -> V_135 ++ ;
V_9 -> V_108 = F_32 ( V_9 , V_9 -> V_108 ) ;
F_46 ( & V_4 -> V_3 . V_95 , V_32 ) ;
F_68 ( & V_145 . V_41 ) ;
V_38 = V_145 . V_38 ;
} else {
V_4 -> V_3 . V_40 = NULL ;
F_46 ( & V_4 -> V_3 . V_95 , V_32 ) ;
}
if ( V_119 & V_127 )
memcpy ( V_143 , V_147 , V_121 ) ;
F_66 ( V_147 ) ;
return V_38 ;
}
static int F_69 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
unsigned long V_121 , V_166 ;
int V_83 ;
void * V_167 ;
V_166 = sizeof( struct V_69 ) +
( sizeof( struct V_168 ) * V_4 -> V_118 ) ;
V_121 = ( V_10 * V_166 ) ;
V_83 = V_169 ;
V_167 = F_70 ( V_4 -> V_3 . V_47 , V_121 ,
V_9 -> V_82 , & V_83 ,
( V_123 |
V_124 |
V_159 ) ) ;
if ( F_71 ( V_167 ) )
return F_72 ( V_167 ) ;
V_9 -> V_170 = V_167 ;
V_9 -> V_166 = V_166 ;
V_9 -> V_171 = V_10 ;
V_9 -> V_108 = V_9 -> V_85 = 0 ;
V_9 -> V_172 = V_10 ;
V_9 -> V_83 = V_83 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
if ( V_9 -> V_170 ) {
F_74 ( V_4 -> V_3 . V_47 , V_9 -> V_170 ,
( V_9 -> V_166 * V_9 -> V_171 ) ,
V_9 -> V_82 , V_9 -> V_83 ) ;
V_9 -> V_170 = NULL ;
V_9 -> V_166 = 0 ;
V_9 -> V_171 = 0 ;
V_9 -> V_172 = 0 ;
V_9 -> V_83 = 0 ;
}
}
static int F_75 ( struct V_1 * V_4 )
{
struct V_144 V_145 ;
F_67 ( & V_145 . V_41 ) ;
V_145 . V_38 = 0 ;
V_145 . V_39 = V_43 ;
V_4 -> V_3 . V_40 = & V_145 ;
F_76 ( & V_4 -> V_3 ) ;
F_68 ( & V_145 . V_41 ) ;
return V_145 . V_38 ;
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
struct V_140 * V_131 ;
struct V_15 * V_173 ;
int V_38 ;
V_38 = F_75 ( V_4 ) ;
if ( V_38 )
return V_38 ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
if ( V_4 -> V_63 == - 1 )
return - V_174 ;
} else {
struct V_156 V_175 ;
V_38 = F_63 ( V_4 , V_155 ,
& V_175 , sizeof( V_175 ) ) ;
if ( V_38 < 0 ) {
F_20 (KERN_ERR PFX L_16
L_17 , err) ;
return V_38 ;
}
V_4 -> V_63 = ( ( T_5 ) V_175 . V_176 *
( T_5 ) V_175 . V_177 *
( T_5 ) V_175 . V_178 ) ;
}
V_131 = F_81 ( F_58 , & V_4 -> V_3 . V_95 ) ;
if ( ! V_131 ) {
F_20 (KERN_ERR PFX L_18 ,
port->vio.name) ;
return - V_165 ;
}
V_173 = F_82 ( 1 << V_179 ) ;
if ( ! V_173 ) {
F_20 (KERN_ERR PFX L_19 ,
port->vio.name) ;
F_83 ( V_131 ) ;
return - V_165 ;
}
V_4 -> V_16 = V_173 ;
F_84 ( V_131 , V_180 - 1 ) ;
F_85 ( V_131 , V_180 ) ;
F_86 ( V_131 , V_4 -> V_118 ) ;
F_87 ( V_131 , V_4 -> V_60 ) ;
V_173 -> V_5 = V_181 ;
V_173 -> V_182 = V_4 -> V_3 . V_183 -> V_184 << V_179 ;
strcpy ( V_173 -> V_185 , V_4 -> V_185 ) ;
V_173 -> V_186 = & V_187 ;
V_173 -> V_37 = V_131 ;
V_173 -> V_115 = V_4 ;
F_88 ( V_173 , V_4 -> V_63 ) ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
switch ( V_4 -> V_65 ) {
case V_188 :
F_89 ( V_27 L_20 , V_4 -> V_185 ) ;
V_173 -> V_32 |= V_33 ;
V_173 -> V_32 |= V_189 ;
F_90 ( V_173 , 1 ) ;
break;
case V_190 :
F_89 ( V_27 L_21 , V_4 -> V_185 ) ;
V_173 -> V_32 |= V_33 ;
V_173 -> V_32 |= V_189 ;
F_90 ( V_173 , 1 ) ;
break;
case V_191 :
F_89 ( V_27 L_22 , V_4 -> V_185 ) ;
break;
}
}
F_89 ( V_27 L_23 ,
V_173 -> V_185 ,
V_4 -> V_63 , ( V_4 -> V_63 >> ( 20 - 9 ) ) ,
V_4 -> V_3 . V_7 . V_5 , V_4 -> V_3 . V_7 . V_6 ) ;
F_91 ( & V_4 -> V_3 . V_183 -> V_192 , V_173 ) ;
return 0 ;
}
static void F_92 ( void )
{
static int V_193 ;
if ( V_193 ++ == 0 )
F_20 ( V_194 L_24 , V_195 ) ;
}
static int F_93 ( struct V_196 * V_183 , const struct V_197 * V_198 )
{
struct V_199 * V_200 ;
struct V_1 * V_4 ;
int V_38 ;
const T_5 * V_201 ;
F_92 () ;
V_200 = F_94 () ;
V_38 = - V_174 ;
if ( ( V_183 -> V_184 << V_179 ) & ~ ( T_5 ) V_202 ) {
F_20 (KERN_ERR PFX L_25 ,
vdev->dev_no) ;
goto V_203;
}
V_4 = F_64 ( sizeof( * V_4 ) , V_164 ) ;
V_38 = - V_165 ;
if ( ! V_4 ) {
F_20 (KERN_ERR PFX L_26 ) ;
goto V_203;
}
if ( V_183 -> V_184 >= 26 )
snprintf ( V_4 -> V_185 , sizeof( V_4 -> V_185 ) ,
V_204 L_27 ,
'a' + ( ( int ) V_183 -> V_184 / 26 ) - 1 ,
'a' + ( ( int ) V_183 -> V_184 % 26 ) ) ;
else
snprintf ( V_4 -> V_185 , sizeof( V_4 -> V_185 ) ,
V_204 L_28 , 'a' + ( ( int ) V_183 -> V_184 % 26 ) ) ;
V_4 -> V_63 = - 1 ;
V_201 = F_95 ( V_200 , V_183 -> V_205 , L_29 , NULL ) ;
V_4 -> V_201 = V_201 ? * V_201 : 0 ;
F_96 ( & V_4 -> V_42 , V_206 ,
( unsigned long ) V_4 ) ;
F_97 ( & V_4 -> V_98 , V_207 ) ;
V_38 = F_98 ( & V_4 -> V_3 , V_183 , V_208 ,
V_209 , F_99 ( V_209 ) ,
& V_210 , V_4 -> V_185 ) ;
if ( V_38 )
goto V_211;
V_4 -> V_59 = 512 ;
V_4 -> V_60 = ( ( 128 * 1024 ) / V_4 -> V_59 ) ;
V_4 -> V_118 = ( ( V_4 -> V_60 *
V_4 -> V_59 ) / V_180 ) + 2 ;
V_38 = F_100 ( & V_4 -> V_3 , & V_212 , V_4 ) ;
if ( V_38 )
goto V_211;
V_38 = F_69 ( V_4 ) ;
if ( V_38 )
goto V_213;
V_38 = F_80 ( V_4 ) ;
if ( V_38 )
goto V_214;
F_101 ( & V_183 -> V_192 , V_4 ) ;
F_102 ( V_200 ) ;
return 0 ;
V_214:
F_73 ( V_4 ) ;
V_213:
F_79 ( & V_4 -> V_3 ) ;
V_211:
F_66 ( V_4 ) ;
V_203:
F_102 ( V_200 ) ;
return V_38 ;
}
static int F_103 ( struct V_196 * V_183 )
{
struct V_1 * V_4 = F_104 ( & V_183 -> V_192 ) ;
if ( V_4 ) {
unsigned long V_32 ;
F_37 ( & V_4 -> V_3 . V_95 , V_32 ) ;
F_62 ( V_4 -> V_16 -> V_37 ) ;
F_46 ( & V_4 -> V_3 . V_95 , V_32 ) ;
F_105 ( & V_4 -> V_98 ) ;
F_106 ( & V_4 -> V_42 ) ;
F_106 ( & V_4 -> V_3 . V_215 ) ;
F_107 ( V_4 -> V_16 ) ;
F_83 ( V_4 -> V_16 -> V_37 ) ;
F_108 ( V_4 -> V_16 ) ;
V_4 -> V_16 = NULL ;
F_73 ( V_4 ) ;
F_79 ( & V_4 -> V_3 ) ;
F_101 ( & V_183 -> V_192 , NULL ) ;
F_66 ( V_4 ) ;
}
return 0 ;
}
static void F_109 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_35 [ V_36 ] ;
T_2 V_216 ;
for ( V_216 = V_9 -> V_85 ; V_216 != V_9 -> V_108 ; V_216 = F_32 ( V_9 , V_216 ) ) {
struct V_69 * V_70 = F_29 ( V_9 , V_216 ) ;
struct V_74 * V_75 = & V_4 -> V_76 [ V_216 ] ;
struct V_77 * V_78 ;
F_31 ( V_4 -> V_3 . V_47 , V_70 -> V_82 , V_70 -> V_83 ) ;
V_70 -> V_79 . V_80 = V_84 ;
V_9 -> V_85 = F_32 ( V_9 , V_216 ) ;
V_78 = V_75 -> V_78 ;
if ( V_78 == NULL ) {
F_27 ( V_4 , V_70 ) ;
continue;
}
V_75 -> V_78 = NULL ;
F_61 ( V_4 -> V_16 -> V_37 , V_78 ) ;
}
}
static void F_110 ( struct V_1 * V_4 )
{
struct V_77 * V_78 ;
while ( ( V_78 = F_111 ( V_4 -> V_16 -> V_37 ) ) != NULL )
F_112 ( V_78 , - V_86 ) ;
}
static void V_206 ( unsigned long V_217 )
{
struct V_1 * V_4 = (struct V_1 * ) V_217 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
unsigned long V_32 ;
F_37 ( & V_3 -> V_95 , V_32 ) ;
if ( ! ( V_4 -> V_3 . V_218 & V_219 ) ) {
F_40 ( V_27 L_30 ,
V_4 -> V_185 , V_4 -> V_201 ) ;
F_110 ( V_4 ) ;
F_12 ( V_4 ) ;
}
F_46 ( & V_3 -> V_95 , V_32 ) ;
}
static void V_207 ( struct V_220 * V_221 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
unsigned long V_32 ;
V_4 = F_2 ( V_221 , struct V_1 , V_98 ) ;
V_3 = & V_4 -> V_3 ;
F_37 ( & V_3 -> V_95 , V_32 ) ;
F_49 ( V_4 ) ;
F_46 ( & V_3 -> V_95 , V_32 ) ;
}
static void F_49 ( struct V_1 * V_4 )
{
int V_38 ;
F_113 ( & V_4 -> V_3 . V_95 ) ;
F_40 ( V_27 L_31 , V_4 -> V_185 ) ;
F_62 ( V_4 -> V_16 -> V_37 ) ;
F_109 ( V_4 ) ;
F_77 ( V_4 ) ;
V_38 = F_100 ( & V_4 -> V_3 , & V_212 , V_4 ) ;
if ( V_38 ) {
F_114 ( V_27 L_32 , V_4 -> V_185 , V_38 ) ;
return;
}
V_38 = F_69 ( V_4 ) ;
if ( V_38 ) {
F_114 ( V_27 L_33 , V_4 -> V_185 , V_38 ) ;
goto V_222;
}
if ( V_4 -> V_201 )
F_115 ( & V_4 -> V_42 ,
F_116 ( V_223 + V_224 * V_4 -> V_201 ) ) ;
F_115 ( & V_4 -> V_3 . V_215 , F_116 ( V_223 + V_224 ) ) ;
return;
V_222:
F_79 ( & V_4 -> V_3 ) ;
}
static int T_7 F_117 ( void )
{
int V_38 ;
V_97 = F_118 ( L_34 , 0 , 0 ) ;
if ( ! V_97 )
return - V_165 ;
V_38 = F_119 ( 0 , V_204 ) ;
if ( V_38 < 0 )
goto V_225;
V_181 = V_38 ;
V_38 = F_120 ( & V_226 ) ;
if ( V_38 )
goto V_227;
return 0 ;
V_227:
F_121 ( V_181 , V_204 ) ;
V_181 = 0 ;
V_225:
F_122 ( V_97 ) ;
return V_38 ;
}
static void T_8 F_123 ( void )
{
F_124 ( & V_226 ) ;
F_121 ( V_181 , V_204 ) ;
F_122 ( V_97 ) ;
}
