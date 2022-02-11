static inline T_1 F_1 ( struct V_1 * V_2 )
{
return V_3 + ( V_2 - V_4 ) * sizeof( struct V_1 ) ;
}
static inline struct V_1 * F_2 ( T_1 V_5 )
{
return V_4 + ( V_5 - V_3 ) / sizeof( struct V_1 ) ;
}
static inline T_2 F_3 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_8 , struct V_9 , V_10 ) -> V_11 ;
}
static inline T_2 F_5 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_8 , struct V_9 , V_10 ) -> V_12 ;
}
static inline const struct V_13 * F_6 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_8 , struct V_9 , V_10 ) -> V_14 ;
}
static int F_7 ( void )
{
struct V_15 * V_16 = & V_17 -> V_16 ;
F_8 ( sizeof( struct V_1 ) != 64 ) ;
V_4 = F_9 ( V_16 ,
V_18 * sizeof( struct V_1 ) ,
& V_3 , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
memset ( V_4 , 0 , V_18 * sizeof( struct V_1 ) ) ;
return 0 ;
}
static struct V_1 * F_10 ( void )
{
int V_21 ;
static int V_22 = 0 ;
unsigned long V_23 ;
F_11 ( & V_24 , V_23 ) ;
if ( F_12 ( ! V_4 ) )
F_7 () ;
if ( F_12 ( ! V_4 ) ) {
F_13 ( & V_24 , V_23 ) ;
return NULL ;
}
V_21 = V_22 ;
if ( V_4 [ V_21 ] . V_25 == V_26 ) {
if ( ++ V_22 >= V_18 )
V_22 = 0 ;
V_4 [ V_21 ] . V_25 = V_27 ;
F_13 ( & V_24 , V_23 ) ;
return V_4 + V_21 ;
} else {
F_13 ( & V_24 , V_23 ) ;
return NULL ;
}
}
static struct V_1 * F_14 ( void )
{
int V_21 ;
static int V_22 = V_18 ;
struct V_1 * V_28 ;
unsigned long V_23 ;
V_28 = F_10 () ;
if ( V_28 )
return V_28 ;
if ( F_12 ( ! V_4 ) )
return NULL ;
F_11 ( & V_29 , V_23 ) ;
V_21 = V_22 ;
if ( V_4 [ V_21 ] . V_25 == V_26 ) {
if ( ++ V_22 >= V_30 )
V_22 = V_18 ;
V_4 [ V_21 ] . V_25 = V_27 ;
F_13 ( & V_29 , V_23 ) ;
return V_4 + V_21 ;
} else {
F_13 ( & V_29 , V_23 ) ;
return NULL ;
}
}
static void F_15 ( struct V_15 * V_16 , struct V_31 * V_32 , T_2 V_5 )
{
while ( V_32 ) {
struct V_31 * V_33 ;
T_2 V_34 ;
V_33 = V_32 -> V_35 ;
V_34 = V_32 -> V_36 ;
F_16 ( V_16 , V_32 -> V_36 , V_32 -> V_37 , V_32 -> V_38 ) ;
F_17 ( V_39 , V_32 , V_5 ) ;
V_32 = V_33 ;
V_5 = V_34 ;
}
}
static void F_18 ( struct V_1 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_43 . V_44 ;
struct V_45 * V_46 = F_19 ( V_42 ) ;
struct V_47 * V_7 = F_20 ( V_42 ) ;
int V_48 = F_21 ( V_7 ) ;
int V_49 = V_42 -> V_50 + V_42 -> V_51 - V_48 ;
if ( V_46 -> V_52 ) {
F_22 ( V_46 -> V_53 ,
V_42 -> V_54 , V_49 , V_48 , 1 ) ;
}
F_17 ( V_39 , V_46 -> V_53 , V_40 -> V_55 ) ;
}
static void F_23 ( T_1 V_5 )
{
struct V_15 * V_16 = & V_17 -> V_16 ;
struct V_1 * V_40 ;
struct V_56 * V_57 ;
int V_58 ;
V_58 = V_5 & 0x1 ? - V_59 : 0 ;
V_5 &= ~ 0x3 ;
V_40 = F_2 ( V_5 ) ;
switch ( V_40 -> V_25 & V_60 ) {
case V_61 : {
struct V_41 * V_42 = V_40 -> V_43 . V_44 ;
struct V_45 * V_46 = F_19 ( V_42 ) ;
F_15 ( V_16 , V_46 -> V_62 , V_40 -> V_63 ) ;
F_15 ( V_16 , V_46 -> V_54 , V_40 -> V_64 ) ;
if ( V_46 -> V_53 ) {
F_18 ( V_40 ) ;
}
V_42 -> V_65 . V_66 ( & V_42 -> V_65 , V_58 ) ;
break;
}
case V_67 : {
struct V_68 * V_42 = V_40 -> V_43 . V_69 ;
struct V_70 * V_46 = F_24 ( V_42 ) ;
if ( V_46 -> V_54 ) {
F_15 ( V_16 , V_46 -> V_54 , V_40 -> V_64 ) ;
}
F_15 ( V_16 , V_46 -> V_62 , V_40 -> V_63 ) ;
V_42 -> V_65 . V_66 ( & V_42 -> V_65 , V_58 ) ;
break;
}
case V_71 :
V_57 = F_25 ( V_40 -> V_43 . V_7 ) ;
F_17 ( V_72 , V_40 -> V_73 ,
V_40 -> V_74 -> V_75 ) ;
F_17 ( V_39 , V_40 -> V_74 , V_40 -> V_63 ) ;
if ( F_26 ( & V_57 -> V_76 ) )
V_66 ( & V_57 -> V_77 ) ;
break;
case V_78 :
V_57 = F_25 ( V_40 -> V_43 . V_7 ) ;
* ( T_2 * ) V_57 -> V_79 . V_80 &= F_27 ( ~ V_81 ) ;
if ( F_26 ( & V_57 -> V_76 ) )
V_66 ( & V_57 -> V_77 ) ;
break;
default:
F_28 () ;
}
V_40 -> V_25 = V_26 ;
}
static void F_29 ( void * V_82 )
{
F_30 ( & V_83 ) ;
}
static void F_31 ( unsigned long V_84 )
{
int V_21 ;
for( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
T_1 V_5 = F_32 ( V_85 ) ;
if ( ! V_5 )
return;
F_23 ( V_5 ) ;
}
F_30 ( & V_83 ) ;
}
static int F_33 ( struct V_15 * V_16 )
{
int V_86 = - V_87 ;
T_2 V_88 [ 2 ] = { 0 , 0 } ;
if ( ! ( ~ ( * V_89 ) & ( V_90 |
V_91 | V_92 ) ) ) {
F_34 ( V_93 L_1 ) ;
return V_86 ;
}
V_94 = F_35 ( V_95 ) ;
if ( ! V_94 )
return V_86 ;
if ( ! F_36 ( V_94 ) ) {
V_86 = F_37 ( V_94 , F_38 ( V_94 ) , V_16 ) ;
if ( V_86 )
goto V_96;
if ( F_39 ( V_94 , V_88 , L_2 ) )
goto V_97;
} else {
if ( F_40 ( V_94 , V_88 , L_2 ) )
goto V_97;
if ( F_39 ( V_94 , V_88 , L_2 ) )
goto V_97;
}
switch ( ( V_88 [ 1 ] >> 16 ) & 0xff ) {
case 3 :
F_34 ( V_98 L_3 ,
F_38 ( V_94 ) ) ;
V_99 = 0 ;
break;
case 4 :
case 5 :
V_99 = 1 ;
break;
default:
F_34 ( V_93 L_4 ,
F_38 ( V_94 ) ) ;
V_86 = - V_87 ;
goto V_96;
}
F_8 ( V_100 > sizeof( struct V_31 ) ) ;
V_39 = F_41 ( L_5 , V_16 ,
sizeof( struct V_31 ) , 32 , 0 ) ;
V_86 = - V_20 ;
if ( ! V_39 ) {
goto V_101;
}
V_72 = F_41 ( L_6 , V_16 ,
V_102 , 16 , 0 ) ;
if ( ! V_72 ) {
goto V_101;
}
V_86 = F_42 ( V_103 , V_30 , 0 , 0 ,
L_7 , NULL ) ;
if ( V_86 )
goto V_101;
V_86 = F_42 ( V_85 , V_18 , 0 , 0 ,
L_8 , NULL ) ;
if ( V_86 ) {
F_43 ( V_103 ) ;
goto V_101;
}
F_44 ( V_85 , V_104 , F_29 , NULL ) ;
F_45 ( & V_83 , F_31 , 0 ) ;
F_46 ( V_85 ) ;
return 0 ;
V_97:
F_34 ( V_93 L_9 , F_38 ( V_94 ) ) ;
V_86 = - V_105 ;
V_101:
F_47 ( V_72 ) ;
F_47 ( V_39 ) ;
V_96:
V_96 ( V_94 ) ;
return V_86 ;
}
static void F_48 ( struct V_15 * V_16 )
{
F_49 ( V_85 ) ;
F_50 ( & V_83 ) ;
F_43 ( V_103 ) ;
F_43 ( V_85 ) ;
F_47 ( V_72 ) ;
F_47 ( V_39 ) ;
V_96 ( V_94 ) ;
if ( V_4 ) {
F_51 ( V_16 ,
V_30 * sizeof( struct V_1 ) ,
V_4 , V_3 ) ;
}
return;
}
static void F_52 ( struct V_106 * V_38 )
{
memset ( V_38 -> V_80 , 0 , V_102 ) ;
V_38 -> V_107 = 0 ;
V_38 -> V_108 = 0 ;
}
static int F_53 ( struct V_106 * V_38 )
{
V_38 -> V_80 = F_54 ( V_72 , V_109 , & V_38 -> V_110 ) ;
if ( ! V_38 -> V_80 ) {
return - V_20 ;
}
F_52 ( V_38 ) ;
return 0 ;
}
static void F_55 ( struct V_106 * V_38 )
{
memset ( V_38 -> V_80 , 0 , V_102 ) ;
F_17 ( V_72 , V_38 -> V_80 , V_38 -> V_110 ) ;
}
static int F_56 ( struct V_6 * V_7 )
{
struct V_56 * V_57 = F_25 ( V_7 ) ;
int V_86 ;
F_57 ( & V_57 -> V_76 , 0 ) ;
V_86 = F_53 ( & V_57 -> V_52 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_53 ( & V_57 -> V_79 ) ;
if ( V_86 ) {
F_55 ( & V_57 -> V_52 ) ;
}
return V_86 ;
}
static int F_58 ( struct V_6 * V_7 )
{
V_7 -> V_111 . V_112 = sizeof( struct V_70 ) ;
return F_56 ( V_7 ) ;
}
static int F_59 ( struct V_47 * V_7 )
{
F_60 ( V_7 , sizeof( struct V_45 ) ) ;
return F_56 ( F_61 ( V_7 ) ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_56 * V_57 = F_25 ( V_7 ) ;
F_55 ( & V_57 -> V_52 ) ;
F_55 ( & V_57 -> V_79 ) ;
}
static void F_63 ( struct V_47 * V_7 )
{
F_62 ( F_61 ( V_7 ) ) ;
}
static int F_64 ( struct V_6 * V_7 , T_3 V_113 , T_2 V_114 ,
int V_115 , T_2 V_116 , const T_3 * V_117 , int V_118 )
{
struct V_56 * V_57 = F_25 ( V_7 ) ;
struct V_1 * V_40 ;
struct V_31 * V_32 ;
int V_21 ;
T_3 * V_119 ;
T_2 V_120 , V_121 ;
F_8 ( V_102 < V_122 ) ;
V_119 = F_54 ( V_72 , V_109 , & V_120 ) ;
if ( ! V_119 )
return - V_20 ;
V_32 = F_54 ( V_39 , V_109 , & V_121 ) ;
if ( ! V_32 ) {
F_17 ( V_72 , V_119 , V_120 ) ;
return - V_20 ;
}
V_40 = F_14 () ;
if ( ! V_40 ) {
F_17 ( V_72 , V_119 , V_120 ) ;
F_17 ( V_39 , V_32 , V_121 ) ;
return - V_123 ;
}
memcpy ( V_119 , V_117 , V_118 ) ;
memset ( V_119 + V_118 , 0 , V_122 - V_118 ) ;
for ( V_21 = 0 ; V_21 < V_122 ; V_21 ++ ) {
V_119 [ V_21 ] ^= V_113 ;
}
V_40 -> V_43 . V_7 = V_7 ;
V_40 -> V_73 = V_119 ;
V_40 -> V_74 = V_32 ;
V_40 -> V_124 = 0 ;
V_40 -> V_125 = V_122 ;
V_40 -> V_126 = V_116 ;
V_40 -> V_63 = V_121 ;
V_40 -> V_55 = V_114 ;
V_40 -> V_127 = V_128 ;
V_40 -> V_115 = V_115 ;
V_40 -> V_25 |= V_71 ;
V_32 -> V_35 = 0 ;
V_32 -> V_37 = V_122 ;
V_32 -> V_129 = 0 ;
V_32 -> V_75 = V_120 ;
F_65 ( & V_57 -> V_76 ) ;
F_66 ( V_103 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_103 ) ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 , int V_52 , unsigned V_48 ,
const T_3 * V_117 , int V_118 , unsigned V_130 )
{
T_2 V_131 , V_132 , V_133 ;
unsigned char * V_134 ;
int V_115 , V_86 = 0 ;
T_2 V_135 ;
struct V_106 * V_38 ;
struct V_56 * V_57 = F_25 ( V_7 ) ;
const struct V_13 * V_136 ;
V_38 = V_52 ? & V_57 -> V_52 : & V_57 -> V_79 ;
V_134 = V_38 -> V_80 + V_38 -> V_107 ;
V_136 = F_6 ( V_7 ) ;
V_135 = V_136 -> V_135 | ( V_48 << 6 ) ;
#ifndef F_70
V_135 ^= 0xAA000000 ;
#endif
* ( T_2 * ) V_134 = F_27 ( V_135 ) ;
V_134 += sizeof( V_135 ) ;
memcpy ( V_134 , V_136 -> V_137 , V_130 ) ;
V_134 += V_130 ;
V_131 = V_38 -> V_110 + V_38 -> V_107
+ sizeof( V_136 -> V_135 ) ;
V_132 = V_131 + V_130 ;
V_115 = V_134 - ( V_38 -> V_80 + V_38 -> V_107 ) ;
V_133 = V_38 -> V_110 + V_38 -> V_107 ;
V_38 -> V_107 += V_115 ;
V_38 -> V_108 |= V_138 ;
if ( ! V_52 )
V_38 -> V_108 |= V_139 ;
V_86 = F_64 ( V_7 , V_140 , V_132 ,
V_115 , V_133 , V_117 , V_118 ) ;
if ( V_86 )
return V_86 ;
return F_64 ( V_7 , V_141 , V_131 ,
V_115 , V_133 , V_117 , V_118 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_40 ;
struct V_56 * V_57 = F_25 ( V_7 ) ;
struct V_106 * V_38 = & V_57 -> V_79 ;
V_40 = F_14 () ;
if ( ! V_40 ) {
return - V_123 ;
}
* ( T_2 * ) V_38 -> V_80 |= F_27 ( V_81 ) ;
V_40 -> V_43 . V_7 = V_7 ;
V_40 -> V_142 = 0 ;
V_40 -> V_143 = V_144 ;
V_40 -> V_63 = 0 ;
V_40 -> V_126 = V_38 -> V_110 ;
V_40 -> V_55 = V_38 -> V_110 + sizeof( T_2 ) ;
V_40 -> V_127 = V_145 ;
V_40 -> V_115 = V_38 -> V_107 ;
V_40 -> V_25 |= V_78 ;
F_65 ( & V_57 -> V_76 ) ;
F_66 ( V_103 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_103 ) ) ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 , int V_52 ,
const T_3 * V_117 , int V_118 )
{
T_3 * V_134 ;
T_2 V_146 ;
T_2 V_147 = 0 ;
struct V_106 * V_38 ;
struct V_56 * V_57 = F_25 ( V_7 ) ;
T_2 * V_23 = & V_7 -> V_148 ;
V_38 = V_52 ? & V_57 -> V_52 : & V_57 -> V_79 ;
V_134 = V_38 -> V_80 ;
if ( V_52 ) {
V_146 = F_3 ( V_7 ) ;
V_38 -> V_108 |= V_149 ;
} else {
V_146 = F_5 ( V_7 ) ;
}
if ( V_146 & V_150 ) {
switch ( V_118 ) {
case 16 : V_147 = V_151 ; break;
case 24 : V_147 = V_152 ; break;
case 32 : V_147 = V_153 ; break;
default:
* V_23 |= V_154 ;
return - V_155 ;
}
V_146 |= V_147 ;
} else if ( V_146 & V_156 ) {
const T_2 * V_157 = ( const T_2 * ) V_117 ;
if ( F_12 ( ! ( ( V_157 [ 0 ] ^ V_157 [ 2 ] ) | ( V_157 [ 1 ] ^ V_157 [ 3 ] ) ) ||
! ( ( V_157 [ 2 ] ^ V_157 [ 4 ] ) | ( V_157 [ 3 ] ^ V_157 [ 5 ] ) ) ) )
{
* V_23 |= V_158 ;
return - V_155 ;
}
} else {
T_2 V_159 [ V_160 ] ;
if ( F_73 ( V_159 , V_117 ) == 0 ) {
* V_23 |= V_161 ;
}
}
* ( T_2 * ) V_134 = F_27 ( V_146 ) ;
V_134 += sizeof( V_146 ) ;
memcpy ( V_134 , V_117 , V_118 ) ;
if ( V_118 < V_162 && ! ( V_146 & V_150 ) ) {
memset ( V_134 + V_118 , 0 , V_162 - V_118 ) ;
V_118 = V_162 ;
}
V_38 -> V_107 = sizeof( V_146 ) + V_118 ;
V_38 -> V_108 |= V_163 ;
if ( ( V_146 & V_150 ) && ! V_52 ) {
return F_71 ( V_7 ) ;
}
return 0 ;
}
static struct V_31 * F_74 ( struct V_15 * V_16 ,
struct V_164 * V_165 , unsigned V_166 ,
struct V_31 * V_32 , T_4 V_23 ,
enum V_167 V_38 )
{
for (; V_166 > 0 ; V_165 = F_75 ( V_165 ) ) {
unsigned V_168 = F_76 ( V_166 , V_165 -> V_169 ) ;
struct V_31 * V_170 ;
T_2 V_171 ;
void * V_172 ;
V_166 -= V_168 ;
V_172 = F_77 ( F_78 ( V_165 ) ) + V_165 -> V_173 ;
V_170 = F_54 ( V_39 , V_23 , & V_171 ) ;
if ( ! V_170 ) {
V_32 = NULL ;
break;
}
F_79 ( V_165 ) = F_80 ( V_16 , V_172 , V_168 , V_38 ) ;
V_32 -> V_35 = V_170 ;
V_32 -> V_36 = V_171 ;
V_32 = V_170 ;
V_32 -> V_75 = F_79 ( V_165 ) ;
V_32 -> V_37 = V_168 ;
V_32 -> V_38 = V_38 ;
}
V_32 -> V_35 = NULL ;
V_32 -> V_36 = 0 ;
return V_32 ;
}
static int F_81 ( struct V_174 * V_7 , const T_3 * V_117 ,
unsigned int V_118 )
{
struct V_56 * V_57 = F_82 ( V_7 ) ;
T_2 * V_23 = & V_7 -> V_65 . V_148 ;
int V_86 ;
F_83 ( & V_57 -> V_77 ) ;
F_65 ( & V_57 -> V_76 ) ;
F_52 ( & V_57 -> V_52 ) ;
F_52 ( & V_57 -> V_79 ) ;
V_57 -> V_52 . V_108 = V_175 ;
V_57 -> V_79 . V_108 = V_175 ;
V_86 = F_72 ( & V_7 -> V_65 , 0 , V_117 , V_118 ) ;
if ( V_86 )
goto V_176;
V_86 = F_72 ( & V_7 -> V_65 , 1 , V_117 , V_118 ) ;
if ( V_86 )
goto V_176;
if ( * V_23 & V_161 ) {
if ( * V_23 & V_177 ) {
V_86 = - V_155 ;
} else {
* V_23 &= ~ V_161 ;
}
}
V_176:
if ( ! F_26 ( & V_57 -> V_76 ) )
F_84 ( & V_57 -> V_77 ) ;
return V_86 ;
}
static int F_85 ( struct V_174 * V_7 , const T_3 * V_117 ,
unsigned int V_118 )
{
struct V_56 * V_57 = F_82 ( V_7 ) ;
if ( V_118 < V_178 )
return - V_155 ;
memcpy ( V_57 -> V_179 , V_117 + ( V_118 - V_178 ) ,
V_178 ) ;
V_118 -= V_178 ;
return F_81 ( V_7 , V_117 , V_118 ) ;
}
static int F_86 ( struct V_68 * V_42 , int V_52 )
{
struct V_174 * V_7 = F_87 ( V_42 ) ;
struct V_56 * V_57 = F_82 ( V_7 ) ;
unsigned V_180 = F_88 ( V_7 ) ;
struct V_106 * V_38 ;
struct V_1 * V_40 ;
unsigned int V_166 = V_42 -> V_166 ;
enum V_167 V_181 = V_182 ;
struct V_70 * V_46 = F_24 ( V_42 ) ;
struct V_31 V_183 ;
struct V_15 * V_16 = & V_17 -> V_16 ;
T_4 V_23 = V_42 -> V_65 . V_23 & V_184 ?
V_109 : V_19 ;
if ( F_89 ( V_103 ) )
return - V_123 ;
if ( F_90 ( & V_57 -> V_76 ) )
return - V_123 ;
V_38 = V_52 ? & V_57 -> V_52 : & V_57 -> V_79 ;
V_40 = F_10 () ;
if ( ! V_40 )
return - V_20 ;
V_40 -> V_43 . V_69 = V_42 ;
V_40 -> V_126 = V_38 -> V_110 ;
V_40 -> V_127 = V_38 -> V_108 ;
V_40 -> V_115 = V_38 -> V_107 ;
V_40 -> V_142 = 0 ;
V_40 -> V_143 = V_166 ;
F_67 ( V_180 && ! V_42 -> V_185 ) ;
memcpy ( V_40 -> V_186 , V_42 -> V_185 , V_180 ) ;
if ( V_42 -> V_62 != V_42 -> V_54 ) {
struct V_31 V_187 ;
V_40 -> V_127 |= V_188 ;
V_46 -> V_54 = NULL ;
if ( ! F_74 ( V_16 , V_42 -> V_54 , V_166 , & V_187 ,
V_23 , V_189 ) )
goto V_190;
V_181 = V_191 ;
V_46 -> V_54 = V_187 . V_35 ;
V_40 -> V_64 = V_187 . V_36 ;
} else {
V_46 -> V_54 = NULL ;
}
V_46 -> V_62 = NULL ;
if ( ! F_74 ( V_16 , V_42 -> V_62 , V_166 , & V_183 ,
V_23 , V_181 ) )
goto V_192;
V_46 -> V_62 = V_183 . V_35 ;
V_40 -> V_63 = V_183 . V_36 ;
V_40 -> V_25 |= V_67 ;
F_66 ( V_103 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_103 ) ) ;
return - V_193 ;
V_192:
F_15 ( V_16 , V_46 -> V_62 , V_40 -> V_63 ) ;
V_190:
if ( V_42 -> V_62 != V_42 -> V_54 ) {
F_15 ( V_16 , V_46 -> V_54 , V_40 -> V_64 ) ;
}
V_40 -> V_25 = V_26 ;
return - V_20 ;
}
static int F_91 ( struct V_68 * V_42 )
{
return F_86 ( V_42 , 1 ) ;
}
static int F_92 ( struct V_68 * V_42 )
{
return F_86 ( V_42 , 0 ) ;
}
static int F_93 ( struct V_68 * V_42 )
{
struct V_174 * V_7 = F_87 ( V_42 ) ;
struct V_56 * V_57 = F_82 ( V_7 ) ;
T_3 V_186 [ V_194 ] ;
T_3 * V_185 = V_42 -> V_185 ;
int V_86 ;
memcpy ( V_186 , V_57 -> V_179 , V_178 ) ;
memcpy ( V_186 + V_178 , V_185 , V_195 ) ;
* ( V_196 * ) ( V_186 + V_178 + V_195 ) =
F_27 ( 1 ) ;
V_42 -> V_185 = V_186 ;
V_86 = F_86 ( V_42 , 1 ) ;
V_42 -> V_185 = V_185 ;
return V_86 ;
}
static int F_94 ( struct V_41 * V_42 , int V_52 ,
int V_197 , int V_198 , T_3 * V_186 )
{
struct V_47 * V_7 = F_20 ( V_42 ) ;
struct V_56 * V_57 = F_95 ( V_7 ) ;
unsigned V_180 = F_96 ( V_7 ) ;
unsigned V_48 = F_21 ( V_7 ) ;
struct V_106 * V_38 ;
struct V_1 * V_40 ;
unsigned int V_51 ;
struct V_31 * V_32 , V_183 ;
struct V_45 * V_46 = F_19 ( V_42 ) ;
struct V_15 * V_16 = & V_17 -> V_16 ;
T_4 V_23 = V_42 -> V_65 . V_23 & V_184 ?
V_109 : V_19 ;
enum V_167 V_181 = V_182 ;
unsigned int V_199 ;
if ( F_89 ( V_103 ) )
return - V_123 ;
if ( F_90 ( & V_57 -> V_76 ) )
return - V_123 ;
if ( V_52 ) {
V_38 = & V_57 -> V_52 ;
V_51 = V_42 -> V_51 ;
} else {
V_38 = & V_57 -> V_79 ;
V_51 = V_42 -> V_51 - V_48 ;
V_198 -= V_48 ;
}
V_40 = F_10 () ;
if ( ! V_40 )
return - V_20 ;
V_40 -> V_43 . V_44 = V_42 ;
V_40 -> V_126 = V_38 -> V_110 ;
V_40 -> V_127 = V_38 -> V_108 ;
V_40 -> V_115 = V_38 -> V_107 ;
V_40 -> V_142 = V_197 ;
V_40 -> V_143 = V_198 ;
V_40 -> V_124 = 0 ;
V_40 -> V_125 = V_42 -> V_50 + V_51 ;
F_67 ( V_180 && ! V_42 -> V_186 ) ;
memcpy ( V_40 -> V_186 , V_42 -> V_186 , V_180 ) ;
V_32 = F_74 ( V_16 , V_42 -> V_62 , V_40 -> V_125 ,
& V_183 , V_23 , V_181 ) ;
V_46 -> V_62 = V_183 . V_35 ;
V_40 -> V_63 = V_183 . V_36 ;
if ( ! V_32 )
goto V_192;
V_199 = V_32 -> V_37 ;
if ( V_199 >= V_48 )
V_40 -> V_55 = V_32 -> V_75 +
V_32 -> V_37 - V_48 ;
V_46 -> V_54 = NULL ;
if ( V_42 -> V_62 != V_42 -> V_54 ) {
struct V_31 V_187 ;
V_40 -> V_127 |= V_188 ;
V_181 = V_191 ;
V_32 = F_74 ( V_16 , V_42 -> V_54 , V_40 -> V_125 ,
& V_187 , V_23 , V_189 ) ;
V_46 -> V_54 = V_187 . V_35 ;
V_40 -> V_64 = V_187 . V_36 ;
if ( ! V_32 )
goto V_200;
if ( V_52 ) {
V_199 = V_32 -> V_37 ;
if ( V_199 >= V_48 )
V_40 -> V_55 = V_32 -> V_75 +
V_32 -> V_37 - V_48 ;
}
}
if ( F_12 ( V_199 < V_48 ) ) {
V_46 -> V_53 = F_54 ( V_39 , V_23 ,
& V_40 -> V_55 ) ;
if ( F_12 ( ! V_46 -> V_53 ) )
goto V_192;
if ( ! V_52 ) {
F_22 ( V_46 -> V_53 ,
V_42 -> V_62 , V_51 , V_48 , 0 ) ;
}
V_46 -> V_52 = V_52 ;
} else {
V_46 -> V_53 = NULL ;
}
V_40 -> V_25 |= V_61 ;
F_66 ( V_103 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_103 ) ) ;
return - V_193 ;
V_192:
F_15 ( V_16 , V_46 -> V_62 , V_40 -> V_63 ) ;
V_200:
F_15 ( V_16 , V_46 -> V_54 , V_40 -> V_64 ) ;
V_40 -> V_25 = V_26 ;
return - V_20 ;
}
static int F_97 ( struct V_47 * V_7 , unsigned int V_48 )
{
struct V_56 * V_57 = F_95 ( V_7 ) ;
T_2 * V_23 = & V_7 -> V_65 . V_148 ;
unsigned V_130 = F_98 ( V_7 ) ;
int V_86 ;
if ( ! V_57 -> V_201 && ! V_57 -> V_202 )
return 0 ;
F_83 ( & V_57 -> V_77 ) ;
F_65 ( & V_57 -> V_76 ) ;
F_52 ( & V_57 -> V_52 ) ;
F_52 ( & V_57 -> V_79 ) ;
V_86 = F_72 ( & V_7 -> V_65 , 0 , V_57 -> V_203 , V_57 -> V_201 ) ;
if ( V_86 )
goto V_176;
V_86 = F_72 ( & V_7 -> V_65 , 1 , V_57 -> V_203 , V_57 -> V_201 ) ;
if ( V_86 )
goto V_176;
V_86 = F_69 ( & V_7 -> V_65 , 0 , V_48 , V_57 -> V_204 ,
V_57 -> V_202 , V_130 ) ;
if ( V_86 )
goto V_176;
V_86 = F_69 ( & V_7 -> V_65 , 1 , V_48 , V_57 -> V_204 ,
V_57 -> V_202 , V_130 ) ;
if ( V_86 )
goto V_176;
if ( * V_23 & V_161 ) {
if ( * V_23 & V_177 ) {
V_86 = - V_155 ;
goto V_176;
} else {
* V_23 &= ~ V_161 ;
}
}
V_176:
if ( ! F_26 ( & V_57 -> V_76 ) )
F_84 ( & V_57 -> V_77 ) ;
return V_86 ;
}
static int F_99 ( struct V_47 * V_7 , unsigned int V_48 )
{
int V_205 = F_98 ( V_7 ) >> 2 ;
if ( ( V_48 >> 2 ) < 1 || ( V_48 >> 2 ) > V_205 || ( V_48 & 3 ) )
return - V_155 ;
return F_97 ( V_7 , V_48 ) ;
}
static int F_100 ( struct V_47 * V_7 , const T_3 * V_117 ,
unsigned int V_206 )
{
struct V_56 * V_57 = F_95 ( V_7 ) ;
struct V_207 V_208 ;
if ( F_101 ( & V_208 , V_117 , V_206 ) != 0 )
goto V_209;
if ( V_208 . V_210 > sizeof( V_57 -> V_204 ) )
goto V_209;
if ( V_208 . V_211 > sizeof( V_57 -> V_203 ) )
goto V_209;
memcpy ( V_57 -> V_204 , V_208 . V_204 , V_208 . V_210 ) ;
memcpy ( V_57 -> V_203 , V_208 . V_203 , V_208 . V_211 ) ;
V_57 -> V_202 = V_208 . V_210 ;
V_57 -> V_201 = V_208 . V_211 ;
return F_97 ( V_7 , F_21 ( V_7 ) ) ;
V_209:
F_102 ( V_7 , V_154 ) ;
return - V_155 ;
}
static int F_103 ( struct V_41 * V_42 )
{
return F_94 ( V_42 , 1 , V_42 -> V_50 , V_42 -> V_51 , V_42 -> V_186 ) ;
}
static int F_104 ( struct V_41 * V_42 )
{
return F_94 ( V_42 , 0 , V_42 -> V_50 , V_42 -> V_51 , V_42 -> V_186 ) ;
}
static int T_5 F_105 ( void )
{
int V_212 = F_106 ( V_213 ) ;
int V_21 , V_101 ;
V_17 = F_107 ( & V_214 ) ;
if ( F_108 ( V_17 ) )
return F_109 ( V_17 ) ;
F_110 ( & V_24 ) ;
F_110 ( & V_29 ) ;
V_101 = F_33 ( & V_17 -> V_16 ) ;
if ( V_101 ) {
F_111 ( V_17 ) ;
return V_101 ;
}
for ( V_21 = 0 ; V_21 < V_212 ; V_21 ++ ) {
struct V_215 * V_216 = & V_213 [ V_21 ] . V_10 ;
if ( snprintf ( V_216 -> V_217 , V_218 ,
L_10 V_219 , V_216 -> V_220 ) >=
V_218 )
{
continue;
}
if ( ! V_99 && ( V_213 [ V_21 ] . V_11 & V_150 ) ) {
continue;
}
V_216 -> V_221 = & V_222 ;
V_216 -> V_223 = V_224 |
V_225 |
V_226 ;
if ( ! V_216 -> V_227 . V_228 )
V_216 -> V_227 . V_228 = F_81 ;
if ( ! V_216 -> V_227 . V_52 )
V_216 -> V_227 . V_52 = F_91 ;
if ( ! V_216 -> V_227 . V_79 )
V_216 -> V_227 . V_79 = F_92 ;
V_216 -> V_229 = F_58 ;
V_216 -> V_230 = sizeof( struct V_56 ) ;
V_216 -> V_231 = V_232 ;
V_216 -> V_233 = 3 ;
V_216 -> V_234 = 300 ;
V_216 -> V_235 = F_62 ;
if ( F_112 ( V_216 ) )
F_34 ( V_93 L_11 ,
V_216 -> V_220 ) ;
else
V_213 [ V_21 ] . V_236 = 1 ;
}
for ( V_21 = 0 ; V_21 < F_106 ( V_237 ) ; V_21 ++ ) {
struct V_238 * V_216 = & V_237 [ V_21 ] . V_10 ;
if ( snprintf ( V_216 -> V_65 . V_217 , V_218 ,
L_10 V_219 , V_216 -> V_65 . V_220 ) >=
V_218 )
continue;
if ( ! V_99 && ( V_213 [ V_21 ] . V_11 & V_150 ) )
continue;
V_216 -> V_65 . V_223 = V_225 |
V_226 ;
V_216 -> V_228 = F_100 ;
V_216 -> V_239 = F_99 ;
V_216 -> V_52 = F_103 ;
V_216 -> V_79 = F_104 ;
V_216 -> V_240 = F_59 ;
V_216 -> exit = F_63 ;
V_216 -> V_65 . V_230 = sizeof( struct V_56 ) ;
V_216 -> V_65 . V_231 = V_232 ;
V_216 -> V_65 . V_233 = 3 ;
V_216 -> V_65 . V_234 = 300 ;
if ( F_113 ( V_216 ) )
F_34 ( V_93 L_11 ,
V_216 -> V_65 . V_217 ) ;
else
V_237 [ V_21 ] . V_236 = 1 ;
}
return 0 ;
}
static void T_6 F_114 ( void )
{
int V_212 = F_106 ( V_213 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_106 ( V_237 ) ; V_21 ++ ) {
if ( V_237 [ V_21 ] . V_236 )
F_115 ( & V_237 [ V_21 ] . V_10 ) ;
}
for ( V_21 = 0 ; V_21 < V_212 ; V_21 ++ ) {
if ( V_213 [ V_21 ] . V_236 )
F_116 ( & V_213 [ V_21 ] . V_10 ) ;
}
F_48 ( & V_17 -> V_16 ) ;
F_111 ( V_17 ) ;
}
