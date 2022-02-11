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
static void F_12 ( struct V_2 * V_3 , int V_35 , int V_36 )
{
if ( V_3 -> V_37 &&
( V_36 == - 1 ||
V_3 -> V_37 -> V_36 == V_36 ) ) {
V_3 -> V_37 -> V_35 = V_35 ;
F_13 ( & V_3 -> V_37 -> V_38 ) ;
V_3 -> V_37 = NULL ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
F_12 ( V_3 , 0 , V_39 ) ;
}
static int F_15 ( struct V_1 * V_4 , void * V_40 )
{
struct V_41 * V_42 = V_40 ;
F_16 (KERN_ERR PFX L_3 ,
pkt->type, pkt->stype, pkt->stype_env, pkt->sid) ;
F_16 (KERN_ERR PFX L_4 ) ;
F_17 ( V_4 -> V_3 . V_43 ) ;
return - V_44 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_45 V_42 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_46 . type = V_47 ;
V_42 . V_46 . V_48 = V_49 ;
V_42 . V_46 . V_50 = V_51 ;
V_42 . V_46 . V_52 = F_19 ( V_3 ) ;
V_42 . V_53 = V_54 ;
V_42 . V_55 = V_4 -> V_55 ;
V_42 . V_56 = V_4 -> V_56 ;
F_20 ( V_57 , L_5 ,
V_42 . V_53 , V_42 . V_55 , V_42 . V_56 ) ;
return F_21 ( & V_4 -> V_3 , & V_42 , sizeof( V_42 ) ) ;
}
static int F_22 ( struct V_2 * V_3 , void * V_40 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_45 * V_42 = V_40 ;
F_20 ( V_57 , L_6
L_7 ,
V_42 -> V_46 . V_48 , V_42 -> V_58 ,
V_42 -> V_59 , V_42 -> V_60 , V_42 -> V_61 ,
V_42 -> V_53 , V_42 -> V_55 ,
V_42 -> V_56 ) ;
if ( V_42 -> V_46 . V_48 == V_62 ) {
switch ( V_42 -> V_60 ) {
case V_63 :
case V_64 :
break;
default:
F_16 (KERN_ERR PFX L_8 ,
vio->name, pkt->vdisk_type) ;
return - V_44 ;
}
if ( V_42 -> V_55 > V_4 -> V_55 ) {
F_16 (KERN_ERR PFX L_9
L_10 ,
vio->name,
port->vdisk_block_size, pkt->vdisk_block_size) ;
return - V_44 ;
}
V_4 -> V_58 = V_42 -> V_58 ;
V_4 -> V_60 = V_42 -> V_60 ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
V_4 -> V_59 = V_42 -> V_59 ;
V_4 -> V_61 = V_42 -> V_61 ;
}
if ( V_42 -> V_56 < V_4 -> V_56 )
V_4 -> V_56 = V_42 -> V_56 ;
V_4 -> V_55 = V_42 -> V_55 ;
return 0 ;
} else {
F_16 (KERN_ERR PFX L_11 , vio->name) ;
return - V_44 ;
}
}
static void F_23 ( struct V_1 * V_4 , struct V_65 * V_66 )
{
int V_35 = V_66 -> V_67 ;
F_12 ( & V_4 -> V_3 , - V_35 , V_68 ) ;
}
static void F_24 ( struct V_1 * V_4 , struct V_8 * V_9 ,
unsigned int V_69 )
{
struct V_65 * V_66 = F_25 ( V_9 , V_69 ) ;
struct V_70 * V_71 = & V_4 -> V_72 [ V_69 ] ;
struct V_73 * V_74 ;
if ( F_26 ( V_66 -> V_75 . V_76 != V_77 ) )
return;
F_27 ( V_4 -> V_3 . V_43 , V_66 -> V_78 , V_66 -> V_79 ) ;
V_66 -> V_75 . V_76 = V_80 ;
V_9 -> V_81 = ( V_69 + 1 ) & ( V_10 - 1 ) ;
V_74 = V_71 -> V_74 ;
if ( V_74 == NULL ) {
F_23 ( V_4 , V_66 ) ;
return;
}
V_71 -> V_74 = NULL ;
F_28 ( V_74 , ( V_66 -> V_67 ? - V_82 : 0 ) , V_66 -> V_83 ) ;
if ( F_29 ( V_4 -> V_16 -> V_84 ) &&
F_4 ( V_9 ) * 100 / V_10 >= 50 )
F_30 ( V_4 -> V_16 -> V_84 ) ;
}
static int F_31 ( struct V_1 * V_4 , void * V_85 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
struct V_88 * V_42 = V_85 ;
if ( F_26 ( V_42 -> V_89 != V_9 -> V_90 ||
V_42 -> V_91 != V_42 -> V_92 ||
V_42 -> V_91 >= V_10 ) )
return 0 ;
F_24 ( V_4 , V_9 , V_42 -> V_91 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_4 , void * V_85 )
{
return 0 ;
}
static void F_33 ( void * V_40 , int V_93 )
{
struct V_1 * V_4 = V_40 ;
struct V_2 * V_3 = & V_4 -> V_3 ;
unsigned long V_32 ;
int V_35 ;
F_34 ( & V_3 -> V_94 , V_32 ) ;
if ( F_26 ( V_93 == V_95 ||
V_93 == V_96 ) ) {
F_35 ( V_3 , V_93 ) ;
F_36 ( & V_3 -> V_94 , V_32 ) ;
return;
}
if ( F_26 ( V_93 != V_97 ) ) {
F_16 (KERN_WARNING PFX L_12 , event) ;
F_36 ( & V_3 -> V_94 , V_32 ) ;
return;
}
V_35 = 0 ;
while ( 1 ) {
union {
struct V_41 V_46 ;
T_5 V_98 [ 8 ] ;
} V_85 ;
V_35 = F_37 ( V_3 -> V_43 , & V_85 , sizeof( V_85 ) ) ;
if ( F_26 ( V_35 < 0 ) ) {
if ( V_35 == - V_44 )
F_38 ( V_3 ) ;
break;
}
if ( V_35 == 0 )
break;
F_20 ( V_99 , L_13 ,
V_85 . V_46 . type ,
V_85 . V_46 . V_48 ,
V_85 . V_46 . V_50 ,
V_85 . V_46 . V_52 ) ;
V_35 = F_39 ( V_3 , & V_85 . V_46 ) ;
if ( V_35 < 0 )
break;
if ( F_40 ( V_85 . V_46 . type == V_100 ) ) {
if ( V_85 . V_46 . V_48 == V_62 )
V_35 = F_31 ( V_4 , & V_85 ) ;
else if ( V_85 . V_46 . V_48 == V_101 )
V_35 = F_32 ( V_4 , & V_85 ) ;
else
V_35 = F_15 ( V_4 , & V_85 ) ;
} else if ( V_85 . V_46 . type == V_47 ) {
V_35 = F_41 ( V_3 , & V_85 ) ;
} else {
V_35 = F_15 ( V_4 , & V_85 ) ;
}
if ( V_35 < 0 )
break;
}
if ( V_35 < 0 )
F_12 ( & V_4 -> V_3 , V_35 , V_102 ) ;
F_36 ( & V_3 -> V_94 , V_32 ) ;
}
static int F_42 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
struct V_88 V_75 = {
. V_46 = {
. type = V_100 ,
. V_48 = V_49 ,
. V_50 = V_103 ,
. V_52 = F_19 ( & V_4 -> V_3 ) ,
} ,
. V_89 = V_9 -> V_90 ,
. V_91 = V_9 -> V_104 ,
. V_92 = V_9 -> V_104 ,
} ;
int V_35 , V_105 ;
V_75 . V_106 = V_9 -> V_107 ;
V_105 = 1 ;
do {
V_35 = F_21 ( & V_4 -> V_3 , & V_75 , sizeof( V_75 ) ) ;
if ( V_35 > 0 ) {
V_9 -> V_107 ++ ;
break;
}
F_43 ( V_105 ) ;
if ( ( V_105 <<= 1 ) > 128 )
V_105 = 128 ;
} while ( V_35 == - V_108 );
return V_35 ;
}
static int F_44 ( struct V_73 * V_74 )
{
struct V_1 * V_4 = V_74 -> V_109 -> V_110 ;
struct V_8 * V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
struct V_111 V_112 [ V_4 -> V_113 ] ;
struct V_70 * V_71 ;
struct V_65 * V_66 ;
unsigned int V_114 ;
int V_115 , V_35 , V_25 ;
T_5 V_116 ;
T_6 V_117 ;
V_114 = V_118 | V_119 | V_120 ;
if ( F_45 ( V_74 ) == V_121 ) {
V_114 |= V_122 ;
V_117 = V_123 ;
} else {
V_114 |= V_124 ;
V_117 = V_125 ;
}
F_46 ( V_112 , V_4 -> V_113 ) ;
V_115 = F_47 ( V_74 -> V_126 , V_74 , V_112 ) ;
V_116 = 0 ;
for ( V_25 = 0 ; V_25 < V_115 ; V_25 ++ )
V_116 += V_112 [ V_25 ] . V_127 ;
V_66 = F_48 ( V_9 ) ;
V_35 = F_49 ( V_4 -> V_3 . V_43 , V_112 , V_115 ,
V_66 -> V_78 , V_4 -> V_113 ,
V_114 ) ;
if ( V_35 < 0 ) {
F_16 (KERN_ERR PFX L_14 , err) ;
return V_35 ;
}
V_71 = & V_4 -> V_72 [ V_9 -> V_104 ] ;
V_71 -> V_74 = V_74 ;
V_66 -> V_75 . V_128 = V_129 ;
V_66 -> V_130 = V_4 -> V_130 ;
V_66 -> V_131 = V_117 ;
if ( V_4 -> V_60 == V_63 ) {
V_66 -> V_132 = 0xff ;
} else {
V_66 -> V_132 = 0 ;
}
V_66 -> V_67 = ~ 0 ;
V_66 -> V_133 = ( F_50 ( V_74 ) << 9 ) / V_4 -> V_55 ;
V_66 -> V_83 = V_116 ;
V_66 -> V_79 = V_35 ;
F_51 () ;
V_66 -> V_75 . V_76 = V_134 ;
V_35 = F_42 ( V_4 ) ;
if ( V_35 < 0 ) {
F_16 (KERN_ERR PFX L_15 , err) ;
} else {
V_4 -> V_130 ++ ;
V_9 -> V_104 = ( V_9 -> V_104 + 1 ) & ( V_10 - 1 ) ;
}
return V_35 ;
}
static void F_52 ( struct V_135 * V_136 )
{
struct V_73 * V_74 ;
while ( ( V_74 = F_53 ( V_136 ) ) != NULL ) {
struct V_1 * V_4 ;
struct V_8 * V_9 ;
V_4 = V_74 -> V_109 -> V_110 ;
V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
if ( F_26 ( F_4 ( V_9 ) < 1 ) )
goto V_137;
F_54 ( V_74 ) ;
if ( F_44 ( V_74 ) < 0 ) {
F_55 ( V_136 , V_74 ) ;
V_137:
F_56 ( V_136 ) ;
break;
}
}
}
static int F_57 ( struct V_1 * V_4 , T_6 V_117 , void * V_138 , int V_116 )
{
struct V_8 * V_9 ;
struct V_139 V_140 ;
struct V_65 * V_66 ;
unsigned int V_114 ;
unsigned long V_32 ;
int V_141 , V_35 ;
void * V_142 ;
if ( ! ( ( ( T_5 ) 1 << ( T_5 ) V_117 ) & V_4 -> V_58 ) )
return - V_143 ;
switch ( V_117 ) {
case V_123 :
case V_125 :
default:
return - V_34 ;
case V_144 :
V_141 = 0 ;
V_114 = 0 ;
break;
case V_145 :
V_141 = sizeof( T_2 ) ;
V_114 = V_122 ;
break;
case V_146 :
V_141 = sizeof( T_2 ) ;
V_114 = V_124 ;
break;
case V_147 :
V_141 = sizeof( struct V_148 ) ;
V_114 = V_122 ;
break;
case V_149 :
V_141 = sizeof( struct V_148 ) ;
V_114 = V_124 ;
break;
case V_150 :
V_141 = sizeof( struct V_151 ) ;
V_114 = V_122 ;
break;
case V_152 :
V_141 = sizeof( struct V_151 ) ;
V_114 = V_124 ;
break;
case V_153 :
V_141 = 16 ;
V_114 = V_154 ;
break;
case V_155 :
V_141 = sizeof( struct V_156 ) ;
V_114 = V_122 ;
break;
case V_157 :
case V_158 :
return - V_143 ;
break;
} ;
V_114 |= V_118 | V_119 | V_120 ;
V_141 = ( V_141 + 7 ) & ~ 7 ;
V_142 = F_58 ( V_141 , V_159 ) ;
if ( ! V_142 )
return - V_160 ;
if ( V_116 > V_141 )
V_116 = V_141 ;
if ( V_114 & V_124 )
memcpy ( V_142 , V_138 , V_116 ) ;
F_34 ( & V_4 -> V_3 . V_94 , V_32 ) ;
V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
V_66 = F_48 ( V_9 ) ;
V_35 = F_59 ( V_4 -> V_3 . V_43 , V_142 , V_141 ,
V_66 -> V_78 , V_4 -> V_113 ,
V_114 ) ;
if ( V_35 < 0 ) {
F_36 ( & V_4 -> V_3 . V_94 , V_32 ) ;
F_60 ( V_142 ) ;
return V_35 ;
}
F_61 ( & V_140 . V_38 ) ;
V_140 . V_36 = V_68 ;
V_4 -> V_3 . V_37 = & V_140 ;
V_66 -> V_75 . V_128 = V_129 ;
V_66 -> V_130 = V_4 -> V_130 ;
V_66 -> V_131 = V_117 ;
V_66 -> V_132 = 0 ;
V_66 -> V_67 = ~ 0 ;
V_66 -> V_133 = 0 ;
V_66 -> V_83 = V_141 ;
V_66 -> V_79 = V_35 ;
F_51 () ;
V_66 -> V_75 . V_76 = V_134 ;
V_35 = F_42 ( V_4 ) ;
if ( V_35 >= 0 ) {
V_4 -> V_130 ++ ;
V_9 -> V_104 = ( V_9 -> V_104 + 1 ) & ( V_10 - 1 ) ;
F_36 ( & V_4 -> V_3 . V_94 , V_32 ) ;
F_62 ( & V_140 . V_38 ) ;
V_35 = V_140 . V_35 ;
} else {
V_4 -> V_3 . V_37 = NULL ;
F_36 ( & V_4 -> V_3 . V_94 , V_32 ) ;
}
if ( V_114 & V_122 )
memcpy ( V_138 , V_142 , V_116 ) ;
F_60 ( V_142 ) ;
return V_35 ;
}
static int F_63 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
unsigned long V_116 , V_161 ;
int V_79 ;
void * V_162 ;
V_161 = sizeof( struct V_65 ) +
( sizeof( struct V_163 ) * V_4 -> V_113 ) ;
V_116 = ( V_10 * V_161 ) ;
V_79 = V_164 ;
V_162 = F_64 ( V_4 -> V_3 . V_43 , V_116 ,
V_9 -> V_78 , & V_79 ,
( V_118 |
V_119 |
V_154 ) ) ;
if ( F_65 ( V_162 ) )
return F_66 ( V_162 ) ;
V_9 -> V_165 = V_162 ;
V_9 -> V_161 = V_161 ;
V_9 -> V_166 = V_10 ;
V_9 -> V_104 = V_9 -> V_81 = 0 ;
V_9 -> V_167 = V_10 ;
V_9 -> V_79 = V_79 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_3 . V_86 [ V_87 ] ;
if ( V_9 -> V_165 ) {
F_68 ( V_4 -> V_3 . V_43 , V_9 -> V_165 ,
( V_9 -> V_161 * V_9 -> V_166 ) ,
V_9 -> V_78 , V_9 -> V_79 ) ;
V_9 -> V_165 = NULL ;
V_9 -> V_161 = 0 ;
V_9 -> V_166 = 0 ;
V_9 -> V_167 = 0 ;
V_9 -> V_79 = 0 ;
}
}
static int F_69 ( struct V_1 * V_4 )
{
struct V_139 V_140 ;
struct V_135 * V_126 ;
struct V_15 * V_168 ;
int V_35 ;
F_61 ( & V_140 . V_38 ) ;
V_140 . V_35 = 0 ;
V_140 . V_36 = V_39 ;
V_4 -> V_3 . V_37 = & V_140 ;
F_70 ( & V_4 -> V_3 ) ;
F_62 ( & V_140 . V_38 ) ;
if ( V_140 . V_35 )
return V_140 . V_35 ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
if ( V_4 -> V_59 == - 1 )
return - V_169 ;
} else {
struct V_151 V_170 ;
V_35 = F_57 ( V_4 , V_150 ,
& V_170 , sizeof( V_170 ) ) ;
if ( V_35 < 0 ) {
F_16 (KERN_ERR PFX L_16
L_17 , err) ;
return V_35 ;
}
V_4 -> V_59 = ( ( T_5 ) V_170 . V_171 *
( T_5 ) V_170 . V_172 *
( T_5 ) V_170 . V_173 ) ;
}
V_126 = F_71 ( F_52 , & V_4 -> V_3 . V_94 ) ;
if ( ! V_126 ) {
F_16 (KERN_ERR PFX L_18 ,
port->vio.name) ;
return - V_160 ;
}
V_168 = F_72 ( 1 << V_174 ) ;
if ( ! V_168 ) {
F_16 (KERN_ERR PFX L_19 ,
port->vio.name) ;
F_73 ( V_126 ) ;
return - V_160 ;
}
V_4 -> V_16 = V_168 ;
F_74 ( V_126 , V_175 - 1 ) ;
F_75 ( V_126 , V_175 ) ;
F_76 ( V_126 , V_4 -> V_113 ) ;
F_77 ( V_126 , V_4 -> V_56 ) ;
V_168 -> V_5 = V_176 ;
V_168 -> V_177 = V_4 -> V_3 . V_178 -> V_179 << V_174 ;
strcpy ( V_168 -> V_180 , V_4 -> V_180 ) ;
V_168 -> V_181 = & V_182 ;
V_168 -> V_84 = V_126 ;
V_168 -> V_110 = V_4 ;
V_168 -> V_183 = & V_4 -> V_3 . V_178 -> V_184 ;
F_78 ( V_168 , V_4 -> V_59 ) ;
if ( F_3 ( V_4 , 1 , 1 ) ) {
switch ( V_4 -> V_61 ) {
case V_185 :
F_79 ( V_27 L_20 , V_4 -> V_180 ) ;
V_168 -> V_32 |= V_33 ;
V_168 -> V_32 |= V_186 ;
F_80 ( V_168 , 1 ) ;
break;
case V_187 :
F_79 ( V_27 L_21 , V_4 -> V_180 ) ;
V_168 -> V_32 |= V_33 ;
V_168 -> V_32 |= V_186 ;
F_80 ( V_168 , 1 ) ;
break;
case V_188 :
F_79 ( V_27 L_22 , V_4 -> V_180 ) ;
break;
}
}
F_79 ( V_27 L_23 ,
V_168 -> V_180 ,
V_4 -> V_59 , ( V_4 -> V_59 >> ( 20 - 9 ) ) ,
V_4 -> V_3 . V_7 . V_5 , V_4 -> V_3 . V_7 . V_6 ) ;
F_81 ( V_168 ) ;
return 0 ;
}
static void F_82 ( void )
{
static int V_189 ;
if ( V_189 ++ == 0 )
F_16 ( V_190 L_24 , V_191 ) ;
}
static int F_83 ( struct V_192 * V_178 , const struct V_193 * V_194 )
{
struct V_195 * V_196 ;
struct V_1 * V_4 ;
int V_35 ;
F_82 () ;
V_196 = F_84 () ;
V_35 = - V_169 ;
if ( ( V_178 -> V_179 << V_174 ) & ~ ( T_5 ) V_197 ) {
F_16 (KERN_ERR PFX L_25 ,
vdev->dev_no) ;
goto V_198;
}
V_4 = F_58 ( sizeof( * V_4 ) , V_159 ) ;
V_35 = - V_160 ;
if ( ! V_4 ) {
F_16 (KERN_ERR PFX L_26 ) ;
goto V_198;
}
if ( V_178 -> V_179 >= 26 )
snprintf ( V_4 -> V_180 , sizeof( V_4 -> V_180 ) ,
V_199 L_27 ,
'a' + ( ( int ) V_178 -> V_179 / 26 ) - 1 ,
'a' + ( ( int ) V_178 -> V_179 % 26 ) ) ;
else
snprintf ( V_4 -> V_180 , sizeof( V_4 -> V_180 ) ,
V_199 L_28 , 'a' + ( ( int ) V_178 -> V_179 % 26 ) ) ;
V_4 -> V_59 = - 1 ;
V_35 = F_85 ( & V_4 -> V_3 , V_178 , V_200 ,
V_201 , F_86 ( V_201 ) ,
& V_202 , V_4 -> V_180 ) ;
if ( V_35 )
goto V_203;
V_4 -> V_55 = 512 ;
V_4 -> V_56 = ( ( 128 * 1024 ) / V_4 -> V_55 ) ;
V_4 -> V_113 = ( ( V_4 -> V_56 *
V_4 -> V_55 ) / V_175 ) + 2 ;
V_35 = F_87 ( & V_4 -> V_3 , & V_204 , V_4 ) ;
if ( V_35 )
goto V_203;
V_35 = F_63 ( V_4 ) ;
if ( V_35 )
goto V_205;
V_35 = F_69 ( V_4 ) ;
if ( V_35 )
goto V_206;
F_88 ( & V_178 -> V_184 , V_4 ) ;
F_89 ( V_196 ) ;
return 0 ;
V_206:
F_67 ( V_4 ) ;
V_205:
F_90 ( & V_4 -> V_3 ) ;
V_203:
F_60 ( V_4 ) ;
V_198:
F_89 ( V_196 ) ;
return V_35 ;
}
static int F_91 ( struct V_192 * V_178 )
{
struct V_1 * V_4 = F_92 ( & V_178 -> V_184 ) ;
if ( V_4 ) {
F_93 ( & V_4 -> V_3 . V_207 ) ;
F_67 ( V_4 ) ;
F_90 ( & V_4 -> V_3 ) ;
F_88 ( & V_178 -> V_184 , NULL ) ;
F_60 ( V_4 ) ;
}
return 0 ;
}
static int T_7 F_94 ( void )
{
int V_35 ;
V_35 = F_95 ( 0 , V_199 ) ;
if ( V_35 < 0 )
goto V_208;
V_176 = V_35 ;
V_35 = F_96 ( & V_209 ) ;
if ( V_35 )
goto V_210;
return 0 ;
V_210:
F_97 ( V_176 , V_199 ) ;
V_176 = 0 ;
V_208:
return V_35 ;
}
static void T_8 F_98 ( void )
{
F_99 ( & V_209 ) ;
F_97 ( V_176 , V_199 ) ;
}
