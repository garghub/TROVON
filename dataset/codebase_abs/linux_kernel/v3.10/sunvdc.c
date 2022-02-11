static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_1 * V_14 = V_12 -> V_15 ;
V_10 -> V_16 = ( V_17 ) V_14 -> V_18 . V_19 ;
V_10 -> V_20 = ( V_17 ) V_14 -> V_18 . V_21 ;
V_10 -> V_22 = V_14 -> V_18 . V_23 ;
return 0 ;
}
static void F_6 ( struct V_2 * V_3 , int V_24 , int V_25 )
{
if ( V_3 -> V_26 &&
( V_25 == - 1 ||
V_3 -> V_26 -> V_25 == V_25 ) ) {
V_3 -> V_26 -> V_24 = V_24 ;
F_7 ( & V_3 -> V_26 -> V_27 ) ;
V_3 -> V_26 = NULL ;
}
}
static void F_8 ( struct V_2 * V_3 )
{
F_6 ( V_3 , 0 , V_28 ) ;
}
static int F_9 ( struct V_1 * V_14 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
F_10 (KERN_ERR PFX L_1 ,
pkt->type, pkt->stype, pkt->stype_env, pkt->sid) ;
F_10 (KERN_ERR PFX L_2 ) ;
F_11 ( V_14 -> V_3 . V_32 ) ;
return - V_33 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_34 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_35 . type = V_36 ;
V_31 . V_35 . V_37 = V_38 ;
V_31 . V_35 . V_39 = V_40 ;
V_31 . V_35 . V_41 = F_13 ( V_3 ) ;
V_31 . V_42 = V_43 ;
V_31 . V_44 = V_14 -> V_44 ;
V_31 . V_45 = V_14 -> V_45 ;
F_14 ( V_46 , L_3 ,
V_31 . V_42 , V_31 . V_44 , V_31 . V_45 ) ;
return F_15 ( & V_14 -> V_3 , & V_31 , sizeof( V_31 ) ) ;
}
static int F_16 ( struct V_2 * V_3 , void * V_29 )
{
struct V_1 * V_14 = F_1 ( V_3 ) ;
struct V_34 * V_31 = V_29 ;
F_14 ( V_46 , L_4
L_5 ,
V_31 -> V_35 . V_37 , V_31 -> V_47 ,
V_31 -> V_48 , V_31 -> V_49 ,
V_31 -> V_42 , V_31 -> V_44 ,
V_31 -> V_45 ) ;
if ( V_31 -> V_35 . V_37 == V_50 ) {
switch ( V_31 -> V_49 ) {
case V_51 :
case V_52 :
break;
default:
F_10 (KERN_ERR PFX L_6 ,
vio->name, pkt->vdisk_type) ;
return - V_33 ;
}
if ( V_31 -> V_44 > V_14 -> V_44 ) {
F_10 (KERN_ERR PFX L_7
L_8 ,
vio->name,
port->vdisk_block_size, pkt->vdisk_block_size) ;
return - V_33 ;
}
V_14 -> V_47 = V_31 -> V_47 ;
V_14 -> V_48 = V_31 -> V_48 ;
V_14 -> V_49 = V_31 -> V_49 ;
if ( V_31 -> V_45 < V_14 -> V_45 )
V_14 -> V_45 = V_31 -> V_45 ;
V_14 -> V_44 = V_31 -> V_44 ;
return 0 ;
} else {
F_10 (KERN_ERR PFX L_9 , vio->name) ;
return - V_33 ;
}
}
static void F_17 ( struct V_1 * V_14 , struct V_53 * V_54 )
{
int V_24 = V_54 -> V_55 ;
F_6 ( & V_14 -> V_3 , - V_24 , V_56 ) ;
}
static void F_18 ( struct V_1 * V_14 , struct V_4 * V_5 ,
unsigned int V_57 )
{
struct V_53 * V_54 = F_19 ( V_5 , V_57 ) ;
struct V_58 * V_59 = & V_14 -> V_60 [ V_57 ] ;
struct V_61 * V_62 ;
if ( F_20 ( V_54 -> V_63 . V_64 != V_65 ) )
return;
F_21 ( V_14 -> V_3 . V_32 , V_54 -> V_66 , V_54 -> V_67 ) ;
V_54 -> V_63 . V_64 = V_68 ;
V_5 -> V_69 = ( V_57 + 1 ) & ( V_6 - 1 ) ;
V_62 = V_59 -> V_62 ;
if ( V_62 == NULL ) {
F_17 ( V_14 , V_54 ) ;
return;
}
V_59 -> V_62 = NULL ;
F_22 ( V_62 , ( V_54 -> V_55 ? - V_70 : 0 ) , V_54 -> V_71 ) ;
if ( F_23 ( V_14 -> V_12 -> V_72 ) )
F_24 ( V_14 -> V_12 -> V_72 ) ;
}
static int F_25 ( struct V_1 * V_14 , void * V_73 )
{
struct V_4 * V_5 = & V_14 -> V_3 . V_74 [ V_75 ] ;
struct V_76 * V_31 = V_73 ;
if ( F_20 ( V_31 -> V_77 != V_5 -> V_78 ||
V_31 -> V_79 != V_31 -> V_80 ||
V_31 -> V_79 >= V_6 ) )
return 0 ;
F_18 ( V_14 , V_5 , V_31 -> V_79 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_14 , void * V_73 )
{
return 0 ;
}
static void F_27 ( void * V_29 , int V_81 )
{
struct V_1 * V_14 = V_29 ;
struct V_2 * V_3 = & V_14 -> V_3 ;
unsigned long V_82 ;
int V_24 ;
F_28 ( & V_3 -> V_83 , V_82 ) ;
if ( F_20 ( V_81 == V_84 ||
V_81 == V_85 ) ) {
F_29 ( V_3 , V_81 ) ;
F_30 ( & V_3 -> V_83 , V_82 ) ;
return;
}
if ( F_20 ( V_81 != V_86 ) ) {
F_10 (KERN_WARNING PFX L_10 , event) ;
F_30 ( & V_3 -> V_83 , V_82 ) ;
return;
}
V_24 = 0 ;
while ( 1 ) {
union {
struct V_30 V_35 ;
T_2 V_87 [ 8 ] ;
} V_73 ;
V_24 = F_31 ( V_3 -> V_32 , & V_73 , sizeof( V_73 ) ) ;
if ( F_20 ( V_24 < 0 ) ) {
if ( V_24 == - V_33 )
F_32 ( V_3 ) ;
break;
}
if ( V_24 == 0 )
break;
F_14 ( V_88 , L_11 ,
V_73 . V_35 . type ,
V_73 . V_35 . V_37 ,
V_73 . V_35 . V_39 ,
V_73 . V_35 . V_41 ) ;
V_24 = F_33 ( V_3 , & V_73 . V_35 ) ;
if ( V_24 < 0 )
break;
if ( F_34 ( V_73 . V_35 . type == V_89 ) ) {
if ( V_73 . V_35 . V_37 == V_50 )
V_24 = F_25 ( V_14 , & V_73 ) ;
else if ( V_73 . V_35 . V_37 == V_90 )
V_24 = F_26 ( V_14 , & V_73 ) ;
else
V_24 = F_9 ( V_14 , & V_73 ) ;
} else if ( V_73 . V_35 . type == V_36 ) {
V_24 = F_35 ( V_3 , & V_73 ) ;
} else {
V_24 = F_9 ( V_14 , & V_73 ) ;
}
if ( V_24 < 0 )
break;
}
if ( V_24 < 0 )
F_6 ( & V_14 -> V_3 , V_24 , V_91 ) ;
F_30 ( & V_3 -> V_83 , V_82 ) ;
}
static int F_36 ( struct V_1 * V_14 )
{
struct V_4 * V_5 = & V_14 -> V_3 . V_74 [ V_75 ] ;
struct V_76 V_63 = {
. V_35 = {
. type = V_89 ,
. V_37 = V_38 ,
. V_39 = V_92 ,
. V_41 = F_13 ( & V_14 -> V_3 ) ,
} ,
. V_77 = V_5 -> V_78 ,
. V_79 = V_5 -> V_93 ,
. V_80 = V_5 -> V_93 ,
} ;
int V_24 , V_94 ;
V_63 . V_95 = V_5 -> V_96 ;
V_94 = 1 ;
do {
V_24 = F_15 ( & V_14 -> V_3 , & V_63 , sizeof( V_63 ) ) ;
if ( V_24 > 0 ) {
V_5 -> V_96 ++ ;
break;
}
F_37 ( V_94 ) ;
if ( ( V_94 <<= 1 ) > 128 )
V_94 = 128 ;
} while ( V_24 == - V_97 );
return V_24 ;
}
static int F_38 ( struct V_61 * V_62 )
{
struct V_1 * V_14 = V_62 -> V_98 -> V_15 ;
struct V_4 * V_5 = & V_14 -> V_3 . V_74 [ V_75 ] ;
struct V_99 V_100 [ V_14 -> V_101 ] ;
struct V_58 * V_59 ;
struct V_53 * V_54 ;
unsigned int V_102 ;
int V_103 , V_24 , V_104 ;
T_2 V_105 ;
V_17 V_106 ;
V_102 = V_107 | V_108 | V_109 ;
if ( F_39 ( V_62 ) == V_110 ) {
V_102 |= V_111 ;
V_106 = V_112 ;
} else {
V_102 |= V_113 ;
V_106 = V_114 ;
}
F_40 ( V_100 , V_14 -> V_101 ) ;
V_103 = F_41 ( V_62 -> V_115 , V_62 , V_100 ) ;
V_105 = 0 ;
for ( V_104 = 0 ; V_104 < V_103 ; V_104 ++ )
V_105 += V_100 [ V_104 ] . V_116 ;
if ( F_20 ( F_3 ( V_5 ) < 1 ) ) {
F_42 ( V_14 -> V_12 -> V_72 ) ;
V_24 = - V_117 ;
goto V_118;
}
V_54 = F_43 ( V_5 ) ;
V_24 = F_44 ( V_14 -> V_3 . V_32 , V_100 , V_103 ,
V_54 -> V_66 , V_14 -> V_101 ,
V_102 ) ;
if ( V_24 < 0 ) {
F_10 (KERN_ERR PFX L_12 , err) ;
return V_24 ;
}
V_59 = & V_14 -> V_60 [ V_5 -> V_93 ] ;
V_59 -> V_62 = V_62 ;
V_54 -> V_63 . V_119 = V_120 ;
V_54 -> V_121 = V_14 -> V_121 ;
V_54 -> V_122 = V_106 ;
if ( V_14 -> V_49 == V_51 ) {
V_54 -> V_123 = 0xff ;
} else {
V_54 -> V_123 = 0 ;
}
V_54 -> V_55 = ~ 0 ;
V_54 -> V_124 = ( F_45 ( V_62 ) << 9 ) / V_14 -> V_44 ;
V_54 -> V_71 = V_105 ;
V_54 -> V_67 = V_24 ;
F_46 () ;
V_54 -> V_63 . V_64 = V_125 ;
V_24 = F_36 ( V_14 ) ;
if ( V_24 < 0 ) {
F_10 (KERN_ERR PFX L_13 , err) ;
} else {
V_14 -> V_121 ++ ;
V_5 -> V_93 = ( V_5 -> V_93 + 1 ) & ( V_6 - 1 ) ;
}
V_118:
return V_24 ;
}
static void F_47 ( struct V_126 * V_115 )
{
while ( 1 ) {
struct V_61 * V_62 = F_48 ( V_115 ) ;
if ( ! V_62 )
break;
if ( F_38 ( V_62 ) < 0 )
F_49 ( V_62 , - V_70 ) ;
}
}
static int F_50 ( struct V_1 * V_14 , V_17 V_106 , void * V_127 , int V_105 )
{
struct V_4 * V_5 ;
struct V_128 V_129 ;
struct V_53 * V_54 ;
unsigned int V_102 ;
unsigned long V_82 ;
int V_130 , V_24 ;
void * V_131 ;
if ( ! ( ( ( T_2 ) 1 << ( T_2 ) V_106 ) & V_14 -> V_47 ) )
return - V_132 ;
switch ( V_106 ) {
case V_112 :
case V_114 :
default:
return - V_133 ;
case V_134 :
V_130 = 0 ;
V_102 = 0 ;
break;
case V_135 :
V_130 = sizeof( T_1 ) ;
V_102 = V_111 ;
break;
case V_136 :
V_130 = sizeof( T_1 ) ;
V_102 = V_113 ;
break;
case V_137 :
V_130 = sizeof( struct V_138 ) ;
V_102 = V_111 ;
break;
case V_139 :
V_130 = sizeof( struct V_138 ) ;
V_102 = V_113 ;
break;
case V_140 :
V_130 = sizeof( struct V_141 ) ;
V_102 = V_111 ;
break;
case V_142 :
V_130 = sizeof( struct V_141 ) ;
V_102 = V_113 ;
break;
case V_143 :
V_130 = 16 ;
V_102 = V_144 ;
break;
case V_145 :
V_130 = sizeof( struct V_146 ) ;
V_102 = V_111 ;
break;
case V_147 :
case V_148 :
return - V_132 ;
break;
} ;
V_102 |= V_107 | V_108 | V_109 ;
V_130 = ( V_130 + 7 ) & ~ 7 ;
V_131 = F_51 ( V_130 , V_149 ) ;
if ( ! V_131 )
return - V_117 ;
if ( V_105 > V_130 )
V_105 = V_130 ;
if ( V_102 & V_113 )
memcpy ( V_131 , V_127 , V_105 ) ;
F_28 ( & V_14 -> V_3 . V_83 , V_82 ) ;
V_5 = & V_14 -> V_3 . V_74 [ V_75 ] ;
V_54 = F_43 ( V_5 ) ;
V_24 = F_52 ( V_14 -> V_3 . V_32 , V_131 , V_130 ,
V_54 -> V_66 , V_14 -> V_101 ,
V_102 ) ;
if ( V_24 < 0 ) {
F_30 ( & V_14 -> V_3 . V_83 , V_82 ) ;
F_53 ( V_131 ) ;
return V_24 ;
}
F_54 ( & V_129 . V_27 ) ;
V_129 . V_25 = V_56 ;
V_14 -> V_3 . V_26 = & V_129 ;
V_54 -> V_63 . V_119 = V_120 ;
V_54 -> V_121 = V_14 -> V_121 ;
V_54 -> V_122 = V_106 ;
V_54 -> V_123 = 0 ;
V_54 -> V_55 = ~ 0 ;
V_54 -> V_124 = 0 ;
V_54 -> V_71 = V_130 ;
V_54 -> V_67 = V_24 ;
F_46 () ;
V_54 -> V_63 . V_64 = V_125 ;
V_24 = F_36 ( V_14 ) ;
if ( V_24 >= 0 ) {
V_14 -> V_121 ++ ;
V_5 -> V_93 = ( V_5 -> V_93 + 1 ) & ( V_6 - 1 ) ;
F_30 ( & V_14 -> V_3 . V_83 , V_82 ) ;
F_55 ( & V_129 . V_27 ) ;
V_24 = V_129 . V_24 ;
} else {
V_14 -> V_3 . V_26 = NULL ;
F_30 ( & V_14 -> V_3 . V_83 , V_82 ) ;
}
if ( V_102 & V_111 )
memcpy ( V_127 , V_131 , V_105 ) ;
F_53 ( V_131 ) ;
return V_24 ;
}
static int F_56 ( struct V_1 * V_14 )
{
struct V_4 * V_5 = & V_14 -> V_3 . V_74 [ V_75 ] ;
unsigned long V_105 , V_150 ;
int V_67 ;
void * V_151 ;
V_150 = sizeof( struct V_53 ) +
( sizeof( struct V_152 ) * V_14 -> V_101 ) ;
V_105 = ( V_6 * V_150 ) ;
V_67 = V_153 ;
V_151 = F_57 ( V_14 -> V_3 . V_32 , V_105 ,
V_5 -> V_66 , & V_67 ,
( V_107 |
V_108 |
V_144 ) ) ;
if ( F_58 ( V_151 ) )
return F_59 ( V_151 ) ;
V_5 -> V_154 = V_151 ;
V_5 -> V_150 = V_150 ;
V_5 -> V_155 = V_6 ;
V_5 -> V_93 = V_5 -> V_69 = 0 ;
V_5 -> V_156 = V_6 ;
V_5 -> V_67 = V_67 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_14 )
{
struct V_4 * V_5 = & V_14 -> V_3 . V_74 [ V_75 ] ;
if ( V_5 -> V_154 ) {
F_61 ( V_14 -> V_3 . V_32 , V_5 -> V_154 ,
( V_5 -> V_150 * V_5 -> V_155 ) ,
V_5 -> V_66 , V_5 -> V_67 ) ;
V_5 -> V_154 = NULL ;
V_5 -> V_150 = 0 ;
V_5 -> V_155 = 0 ;
V_5 -> V_156 = 0 ;
V_5 -> V_67 = 0 ;
}
}
static int F_62 ( struct V_1 * V_14 )
{
struct V_128 V_129 ;
struct V_126 * V_115 ;
struct V_11 * V_157 ;
int V_24 ;
F_54 ( & V_129 . V_27 ) ;
V_129 . V_24 = 0 ;
V_129 . V_25 = V_28 ;
V_14 -> V_3 . V_26 = & V_129 ;
F_63 ( & V_14 -> V_3 ) ;
F_55 ( & V_129 . V_27 ) ;
if ( V_129 . V_24 )
return V_129 . V_24 ;
V_24 = F_50 ( V_14 , V_137 ,
& V_14 -> V_158 , sizeof( V_14 -> V_158 ) ) ;
if ( V_24 < 0 ) {
F_10 (KERN_ERR PFX L_14 , err) ;
return V_24 ;
}
V_24 = F_50 ( V_14 , V_140 ,
& V_14 -> V_18 , sizeof( V_14 -> V_18 ) ) ;
if ( V_24 < 0 ) {
F_10 (KERN_ERR PFX L_15
L_16 , err) ;
return V_24 ;
}
V_14 -> V_48 = ( ( T_2 ) V_14 -> V_18 . V_23 *
( T_2 ) V_14 -> V_18 . V_19 *
( T_2 ) V_14 -> V_18 . V_21 ) ;
V_115 = F_64 ( F_47 , & V_14 -> V_3 . V_83 ) ;
if ( ! V_115 ) {
F_10 (KERN_ERR PFX L_17 ,
port->vio.name) ;
return - V_117 ;
}
V_157 = F_65 ( 1 << V_159 ) ;
if ( ! V_157 ) {
F_10 (KERN_ERR PFX L_18 ,
port->vio.name) ;
F_66 ( V_115 ) ;
return - V_117 ;
}
V_14 -> V_12 = V_157 ;
F_67 ( V_115 , V_14 -> V_101 ) ;
F_68 ( V_115 , V_14 -> V_45 ) ;
V_157 -> V_160 = V_161 ;
V_157 -> V_162 = V_14 -> V_3 . V_163 -> V_164 << V_159 ;
strcpy ( V_157 -> V_165 , V_14 -> V_165 ) ;
V_157 -> V_166 = & V_167 ;
V_157 -> V_72 = V_115 ;
V_157 -> V_15 = V_14 ;
V_157 -> V_168 = & V_14 -> V_3 . V_163 -> V_169 ;
F_69 ( V_157 , V_14 -> V_48 ) ;
F_10 (KERN_INFO PFX L_19 ,
g->disk_name,
port->vdisk_size, (port->vdisk_size >> (20 - 9))) ;
F_70 ( V_157 ) ;
return 0 ;
}
static void F_71 ( void )
{
static int V_170 ;
if ( V_170 ++ == 0 )
F_10 ( V_171 L_20 , V_172 ) ;
}
static int F_72 ( struct V_173 * V_163 , const struct V_174 * V_175 )
{
struct V_176 * V_177 ;
struct V_1 * V_14 ;
int V_24 ;
F_71 () ;
V_177 = F_73 () ;
V_24 = - V_178 ;
if ( ( V_163 -> V_164 << V_159 ) & ~ ( T_2 ) V_179 ) {
F_10 (KERN_ERR PFX L_21 ,
vdev->dev_no) ;
goto V_180;
}
V_14 = F_51 ( sizeof( * V_14 ) , V_149 ) ;
V_24 = - V_117 ;
if ( ! V_14 ) {
F_10 (KERN_ERR PFX L_22 ) ;
goto V_180;
}
if ( V_163 -> V_164 >= 26 )
snprintf ( V_14 -> V_165 , sizeof( V_14 -> V_165 ) ,
V_181 L_23 ,
'a' + ( ( int ) V_163 -> V_164 / 26 ) - 1 ,
'a' + ( ( int ) V_163 -> V_164 % 26 ) ) ;
else
snprintf ( V_14 -> V_165 , sizeof( V_14 -> V_165 ) ,
V_181 L_24 , 'a' + ( ( int ) V_163 -> V_164 % 26 ) ) ;
V_24 = F_74 ( & V_14 -> V_3 , V_163 , V_182 ,
V_183 , F_75 ( V_183 ) ,
& V_184 , V_14 -> V_165 ) ;
if ( V_24 )
goto V_185;
V_14 -> V_44 = 512 ;
V_14 -> V_45 = ( ( 128 * 1024 ) / V_14 -> V_44 ) ;
V_14 -> V_101 = ( ( V_14 -> V_45 *
V_14 -> V_44 ) / V_186 ) + 2 ;
V_24 = F_76 ( & V_14 -> V_3 , & V_187 , V_14 ) ;
if ( V_24 )
goto V_185;
V_24 = F_56 ( V_14 ) ;
if ( V_24 )
goto V_188;
V_24 = F_62 ( V_14 ) ;
if ( V_24 )
goto V_189;
F_77 ( & V_163 -> V_169 , V_14 ) ;
F_78 ( V_177 ) ;
return 0 ;
V_189:
F_60 ( V_14 ) ;
V_188:
F_79 ( & V_14 -> V_3 ) ;
V_185:
F_53 ( V_14 ) ;
V_180:
F_78 ( V_177 ) ;
return V_24 ;
}
static int F_80 ( struct V_173 * V_163 )
{
struct V_1 * V_14 = F_81 ( & V_163 -> V_169 ) ;
if ( V_14 ) {
F_82 ( & V_14 -> V_3 . V_190 ) ;
F_60 ( V_14 ) ;
F_79 ( & V_14 -> V_3 ) ;
F_77 ( & V_163 -> V_169 , NULL ) ;
F_53 ( V_14 ) ;
}
return 0 ;
}
static int T_3 F_83 ( void )
{
int V_24 ;
V_24 = F_84 ( 0 , V_181 ) ;
if ( V_24 < 0 )
goto V_191;
V_161 = V_24 ;
V_24 = F_85 ( & V_192 ) ;
if ( V_24 )
goto V_193;
return 0 ;
V_193:
F_86 ( V_161 , V_181 ) ;
V_161 = 0 ;
V_191:
return V_24 ;
}
static void T_4 F_87 ( void )
{
F_88 ( & V_192 ) ;
F_86 ( V_161 , V_181 ) ;
}
