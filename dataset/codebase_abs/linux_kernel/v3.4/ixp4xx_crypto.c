static void F_1 ( struct V_1 * V_2 )
{
return;
}
static inline T_1 F_2 ( struct V_3 * V_4 )
{
return V_5 + ( V_4 - V_6 ) * sizeof( struct V_3 ) ;
}
static inline struct V_3 * F_3 ( T_1 V_7 )
{
return V_6 + ( V_7 - V_5 ) / sizeof( struct V_3 ) ;
}
static inline T_2 F_4 ( struct V_8 * V_9 )
{
return F_5 ( V_9 -> V_10 , struct V_11 , V_12 ) -> V_13 ;
}
static inline T_2 F_6 ( struct V_8 * V_9 )
{
return F_5 ( V_9 -> V_10 , struct V_11 , V_12 ) -> V_14 ;
}
static inline const struct V_15 * F_7 ( struct V_8 * V_9 )
{
return F_5 ( V_9 -> V_10 , struct V_11 , V_12 ) -> V_16 ;
}
static int F_8 ( void )
{
F_9 ( sizeof( struct V_3 ) != 64 ) ;
V_6 = F_10 ( V_2 ,
V_17 * sizeof( struct V_3 ) ,
& V_5 , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
memset ( V_6 , 0 , V_17 * sizeof( struct V_3 ) ) ;
return 0 ;
}
static struct V_3 * F_11 ( void )
{
int V_20 ;
static int V_21 = 0 ;
unsigned long V_22 ;
F_12 ( & V_23 , V_22 ) ;
if ( F_13 ( ! V_6 ) )
F_8 () ;
if ( F_13 ( ! V_6 ) ) {
F_14 ( & V_23 , V_22 ) ;
return NULL ;
}
V_20 = V_21 ;
if ( V_6 [ V_20 ] . V_24 == V_25 ) {
if ( ++ V_21 >= V_17 )
V_21 = 0 ;
V_6 [ V_20 ] . V_24 = V_26 ;
F_14 ( & V_23 , V_22 ) ;
return V_6 + V_20 ;
} else {
F_14 ( & V_23 , V_22 ) ;
return NULL ;
}
}
static struct V_3 * F_15 ( void )
{
int V_20 ;
static int V_21 = V_17 ;
struct V_3 * V_27 ;
unsigned long V_22 ;
V_27 = F_11 () ;
if ( V_27 )
return V_27 ;
if ( F_13 ( ! V_6 ) )
return NULL ;
F_12 ( & V_28 , V_22 ) ;
V_20 = V_21 ;
if ( V_6 [ V_20 ] . V_24 == V_25 ) {
if ( ++ V_21 >= V_29 )
V_21 = V_17 ;
V_6 [ V_20 ] . V_24 = V_26 ;
F_14 ( & V_28 , V_22 ) ;
return V_6 + V_20 ;
} else {
F_14 ( & V_28 , V_22 ) ;
return NULL ;
}
}
static void F_16 ( struct V_1 * V_2 , struct V_30 * V_31 , T_2 V_7 )
{
while ( V_31 ) {
struct V_30 * V_32 ;
T_2 V_33 ;
V_32 = V_31 -> V_34 ;
V_33 = V_31 -> V_35 ;
F_17 ( V_2 , V_31 -> V_35 , V_31 -> V_36 , V_31 -> V_37 ) ;
F_18 ( V_38 , V_31 , V_7 ) ;
V_31 = V_32 ;
V_7 = V_33 ;
}
}
static void F_19 ( struct V_3 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_42 . V_43 ;
struct V_44 * V_45 = F_20 ( V_41 ) ;
struct V_46 * V_9 = F_21 ( V_41 ) ;
int V_47 = F_22 ( V_9 ) ;
int V_48 = V_41 -> V_49 - V_47 ;
if ( V_45 -> V_50 ) {
F_23 ( V_45 -> V_51 ,
V_41 -> V_52 , V_48 , V_47 , 1 ) ;
}
F_18 ( V_38 , V_45 -> V_51 , V_39 -> V_53 ) ;
}
static void F_24 ( T_1 V_7 )
{
struct V_3 * V_39 ;
struct V_54 * V_55 ;
int V_56 ;
V_56 = V_7 & 0x1 ? - V_57 : 0 ;
V_7 &= ~ 0x3 ;
V_39 = F_3 ( V_7 ) ;
switch ( V_39 -> V_24 & V_58 ) {
case V_59 : {
struct V_40 * V_41 = V_39 -> V_42 . V_43 ;
struct V_44 * V_45 = F_20 ( V_41 ) ;
F_16 ( V_2 , V_45 -> V_60 , V_39 -> V_61 ) ;
if ( V_45 -> V_51 ) {
F_19 ( V_39 ) ;
}
V_41 -> V_62 . V_63 ( & V_41 -> V_62 , V_56 ) ;
break;
}
case V_64 : {
struct V_65 * V_41 = V_39 -> V_42 . V_66 ;
struct V_67 * V_45 = F_25 ( V_41 ) ;
if ( V_45 -> V_68 ) {
F_16 ( V_2 , V_45 -> V_68 , V_39 -> V_69 ) ;
}
F_16 ( V_2 , V_45 -> V_52 , V_39 -> V_61 ) ;
V_41 -> V_62 . V_63 ( & V_41 -> V_62 , V_56 ) ;
break;
}
case V_70 :
V_55 = F_26 ( V_39 -> V_42 . V_9 ) ;
F_18 ( V_71 , V_39 -> V_72 ,
V_39 -> V_73 -> V_74 ) ;
F_18 ( V_38 , V_39 -> V_73 , V_39 -> V_61 ) ;
if ( F_27 ( & V_55 -> V_75 ) )
V_63 ( & V_55 -> V_76 ) ;
break;
case V_77 :
V_55 = F_26 ( V_39 -> V_42 . V_9 ) ;
* ( T_2 * ) V_55 -> V_78 . V_79 &= F_28 ( ~ V_80 ) ;
if ( F_27 ( & V_55 -> V_75 ) )
V_63 ( & V_55 -> V_76 ) ;
break;
default:
F_29 () ;
}
V_39 -> V_24 = V_25 ;
}
static void F_30 ( void * V_81 )
{
F_31 ( & V_82 ) ;
}
static void F_32 ( unsigned long V_83 )
{
int V_20 ;
for( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
T_1 V_7 = F_33 ( V_84 ) ;
if ( ! V_7 )
return;
F_24 ( V_7 ) ;
}
F_31 ( & V_82 ) ;
}
static int F_34 ( void )
{
int V_85 = - V_86 ;
T_2 V_87 [ 2 ] = { 0 , 0 } ;
if ( ! ( ~ ( * V_88 ) & ( V_89 |
V_90 | V_91 ) ) ) {
F_35 ( V_92 L_1 ) ;
return V_85 ;
}
V_93 = F_36 ( V_94 ) ;
if ( ! V_93 )
return V_85 ;
if ( ! F_37 ( V_93 ) ) {
V_85 = F_38 ( V_93 , F_39 ( V_93 ) , V_2 ) ;
if ( V_85 ) {
return V_85 ;
}
if ( F_40 ( V_93 , V_87 , L_2 ) )
goto V_95;
} else {
if ( F_41 ( V_93 , V_87 , L_2 ) )
goto V_95;
if ( F_40 ( V_93 , V_87 , L_2 ) )
goto V_95;
}
switch ( ( V_87 [ 1 ] >> 16 ) & 0xff ) {
case 3 :
F_35 ( V_96 L_3 ,
F_39 ( V_93 ) ) ;
V_97 = 0 ;
break;
case 4 :
case 5 :
V_97 = 1 ;
break;
default:
F_35 ( V_92 L_4 ,
F_39 ( V_93 ) ) ;
return - V_86 ;
}
F_9 ( V_98 > sizeof( struct V_30 ) ) ;
V_38 = F_42 ( L_5 , V_2 ,
sizeof( struct V_30 ) , 32 , 0 ) ;
V_85 = - V_19 ;
if ( ! V_38 ) {
goto V_99;
}
V_71 = F_42 ( L_6 , V_2 ,
V_100 , 16 , 0 ) ;
if ( ! V_71 ) {
goto V_99;
}
V_85 = F_43 ( V_101 , V_29 , 0 , 0 ,
L_7 , NULL ) ;
if ( V_85 )
goto V_99;
V_85 = F_43 ( V_84 , V_17 , 0 , 0 ,
L_8 , NULL ) ;
if ( V_85 ) {
F_44 ( V_101 ) ;
goto V_99;
}
F_45 ( V_84 , V_102 , F_30 , NULL ) ;
F_46 ( & V_82 , F_32 , 0 ) ;
F_47 ( V_84 ) ;
return 0 ;
V_95:
F_35 ( V_92 L_9 , F_39 ( V_93 ) ) ;
V_85 = - V_103 ;
V_99:
if ( V_71 )
F_48 ( V_71 ) ;
if ( V_38 )
F_48 ( V_38 ) ;
F_49 ( V_93 ) ;
return V_85 ;
}
static void F_50 ( void )
{
F_51 ( V_84 ) ;
F_52 ( & V_82 ) ;
F_44 ( V_101 ) ;
F_44 ( V_84 ) ;
F_48 ( V_71 ) ;
F_48 ( V_38 ) ;
F_49 ( V_93 ) ;
if ( V_6 ) {
F_53 ( V_2 ,
V_29 * sizeof( struct V_3 ) ,
V_6 , V_5 ) ;
}
return;
}
static void F_54 ( struct V_104 * V_37 )
{
memset ( V_37 -> V_79 , 0 , V_100 ) ;
V_37 -> V_105 = 0 ;
V_37 -> V_106 = 0 ;
}
static int F_55 ( struct V_104 * V_37 )
{
V_37 -> V_79 = F_56 ( V_71 , V_107 , & V_37 -> V_108 ) ;
if ( ! V_37 -> V_79 ) {
return - V_19 ;
}
F_54 ( V_37 ) ;
return 0 ;
}
static void F_57 ( struct V_104 * V_37 )
{
memset ( V_37 -> V_79 , 0 , V_100 ) ;
F_18 ( V_71 , V_37 -> V_79 , V_37 -> V_108 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_54 * V_55 = F_26 ( V_9 ) ;
int V_85 ;
F_59 ( & V_55 -> V_75 , 0 ) ;
V_85 = F_55 ( & V_55 -> V_50 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_55 ( & V_55 -> V_78 ) ;
if ( V_85 ) {
F_57 ( & V_55 -> V_50 ) ;
}
return V_85 ;
}
static int F_60 ( struct V_8 * V_9 )
{
V_9 -> V_109 . V_110 = sizeof( struct V_67 ) ;
return F_58 ( V_9 ) ;
}
static int F_61 ( struct V_8 * V_9 )
{
V_9 -> V_111 . V_110 = sizeof( struct V_44 ) ;
return F_58 ( V_9 ) ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_54 * V_55 = F_26 ( V_9 ) ;
F_57 ( & V_55 -> V_50 ) ;
F_57 ( & V_55 -> V_78 ) ;
}
static int F_63 ( struct V_8 * V_9 , T_3 V_112 , T_2 V_113 ,
int V_114 , T_2 V_115 , const T_3 * V_116 , int V_117 )
{
struct V_54 * V_55 = F_26 ( V_9 ) ;
struct V_3 * V_39 ;
struct V_30 * V_31 ;
int V_20 ;
T_3 * V_118 ;
T_2 V_119 , V_120 ;
F_9 ( V_100 < V_121 ) ;
V_118 = F_56 ( V_71 , V_107 , & V_119 ) ;
if ( ! V_118 )
return - V_19 ;
V_31 = F_56 ( V_38 , V_107 , & V_120 ) ;
if ( ! V_31 ) {
F_18 ( V_71 , V_118 , V_119 ) ;
return - V_19 ;
}
V_39 = F_15 () ;
if ( ! V_39 ) {
F_18 ( V_71 , V_118 , V_119 ) ;
F_18 ( V_38 , V_31 , V_120 ) ;
return - V_122 ;
}
memcpy ( V_118 , V_116 , V_117 ) ;
memset ( V_118 + V_117 , 0 , V_121 - V_117 ) ;
for ( V_20 = 0 ; V_20 < V_121 ; V_20 ++ ) {
V_118 [ V_20 ] ^= V_112 ;
}
V_39 -> V_42 . V_9 = V_9 ;
V_39 -> V_72 = V_118 ;
V_39 -> V_73 = V_31 ;
V_39 -> V_123 = 0 ;
V_39 -> V_124 = V_121 ;
V_39 -> V_125 = V_115 ;
V_39 -> V_61 = V_120 ;
V_39 -> V_53 = V_113 ;
V_39 -> V_126 = V_127 ;
V_39 -> V_114 = V_114 ;
V_39 -> V_24 |= V_70 ;
V_31 -> V_34 = 0 ;
V_31 -> V_36 = V_121 ;
V_31 -> V_128 = 0 ;
V_31 -> V_74 = V_119 ;
F_64 ( & V_55 -> V_75 ) ;
F_65 ( V_101 , F_2 ( V_39 ) ) ;
F_66 ( F_67 ( V_101 ) ) ;
return 0 ;
}
static int F_68 ( struct V_8 * V_9 , int V_50 , unsigned V_47 ,
const T_3 * V_116 , int V_117 , unsigned V_129 )
{
T_2 V_130 , V_131 , V_132 ;
unsigned char * V_133 ;
int V_114 , V_85 = 0 ;
T_2 V_134 ;
struct V_104 * V_37 ;
struct V_54 * V_55 = F_26 ( V_9 ) ;
const struct V_15 * V_135 ;
V_37 = V_50 ? & V_55 -> V_50 : & V_55 -> V_78 ;
V_133 = V_37 -> V_79 + V_37 -> V_105 ;
V_135 = F_7 ( V_9 ) ;
V_134 = V_135 -> V_134 | ( V_47 << 6 ) ;
#ifndef F_69
V_134 ^= 0xAA000000 ;
#endif
* ( T_2 * ) V_133 = F_28 ( V_134 ) ;
V_133 += sizeof( V_134 ) ;
memcpy ( V_133 , V_135 -> V_136 , V_129 ) ;
V_133 += V_129 ;
V_130 = V_37 -> V_108 + V_37 -> V_105
+ sizeof( V_135 -> V_134 ) ;
V_131 = V_130 + V_129 ;
V_114 = V_133 - ( V_37 -> V_79 + V_37 -> V_105 ) ;
V_132 = V_37 -> V_108 + V_37 -> V_105 ;
V_37 -> V_105 += V_114 ;
V_37 -> V_106 |= V_137 ;
if ( ! V_50 )
V_37 -> V_106 |= V_138 ;
V_85 = F_63 ( V_9 , V_139 , V_131 ,
V_114 , V_132 , V_116 , V_117 ) ;
if ( V_85 )
return V_85 ;
return F_63 ( V_9 , V_140 , V_130 ,
V_114 , V_132 , V_116 , V_117 ) ;
}
static int F_70 ( struct V_8 * V_9 )
{
struct V_3 * V_39 ;
struct V_54 * V_55 = F_26 ( V_9 ) ;
struct V_104 * V_37 = & V_55 -> V_78 ;
V_39 = F_15 () ;
if ( ! V_39 ) {
return - V_122 ;
}
* ( T_2 * ) V_37 -> V_79 |= F_28 ( V_80 ) ;
V_39 -> V_42 . V_9 = V_9 ;
V_39 -> V_141 = 0 ;
V_39 -> V_142 = V_143 ;
V_39 -> V_61 = 0 ;
V_39 -> V_125 = V_37 -> V_108 ;
V_39 -> V_53 = V_37 -> V_108 + sizeof( T_2 ) ;
V_39 -> V_126 = V_144 ;
V_39 -> V_114 = V_37 -> V_105 ;
V_39 -> V_24 |= V_77 ;
F_64 ( & V_55 -> V_75 ) ;
F_65 ( V_101 , F_2 ( V_39 ) ) ;
F_66 ( F_67 ( V_101 ) ) ;
return 0 ;
}
static int F_71 ( struct V_8 * V_9 , int V_50 ,
const T_3 * V_116 , int V_117 )
{
T_3 * V_133 ;
T_2 V_145 ;
T_2 V_146 = 0 ;
struct V_104 * V_37 ;
struct V_54 * V_55 = F_26 ( V_9 ) ;
T_2 * V_22 = & V_9 -> V_147 ;
V_37 = V_50 ? & V_55 -> V_50 : & V_55 -> V_78 ;
V_133 = V_37 -> V_79 ;
if ( V_50 ) {
V_145 = F_4 ( V_9 ) ;
V_37 -> V_106 |= V_148 ;
} else {
V_145 = F_6 ( V_9 ) ;
}
if ( V_145 & V_149 ) {
switch ( V_117 ) {
case 16 : V_146 = V_150 | V_151 ; break;
case 24 : V_146 = V_152 | V_153 ; break;
case 32 : V_146 = V_154 | V_155 ; break;
default:
* V_22 |= V_156 ;
return - V_157 ;
}
V_145 |= V_146 ;
} else if ( V_145 & V_158 ) {
const T_2 * V_159 = ( const T_2 * ) V_116 ;
if ( F_13 ( ! ( ( V_159 [ 0 ] ^ V_159 [ 2 ] ) | ( V_159 [ 1 ] ^ V_159 [ 3 ] ) ) ||
! ( ( V_159 [ 2 ] ^ V_159 [ 4 ] ) | ( V_159 [ 3 ] ^ V_159 [ 5 ] ) ) ) )
{
* V_22 |= V_160 ;
return - V_157 ;
}
} else {
T_2 V_161 [ V_162 ] ;
if ( F_72 ( V_161 , V_116 ) == 0 ) {
* V_22 |= V_163 ;
}
}
* ( T_2 * ) V_133 = F_28 ( V_145 ) ;
V_133 += sizeof( V_145 ) ;
memcpy ( V_133 , V_116 , V_117 ) ;
if ( V_117 < V_164 && ! ( V_145 & V_149 ) ) {
memset ( V_133 + V_117 , 0 , V_164 - V_117 ) ;
V_117 = V_164 ;
}
V_37 -> V_105 = sizeof( V_145 ) + V_117 ;
V_37 -> V_106 |= V_165 ;
if ( ( V_145 & V_149 ) && ! V_50 ) {
return F_70 ( V_9 ) ;
}
return 0 ;
}
static struct V_30 * F_73 ( struct V_1 * V_2 ,
struct V_166 * V_167 , unsigned V_168 ,
struct V_30 * V_31 , T_4 V_22 ,
enum V_169 V_37 )
{
for (; V_168 > 0 ; V_167 = F_74 ( V_167 ) ) {
unsigned V_170 = F_75 ( V_168 , V_167 -> V_171 ) ;
struct V_30 * V_172 ;
T_2 V_173 ;
void * V_174 ;
V_168 -= V_170 ;
V_174 = F_76 ( F_77 ( V_167 ) ) + V_167 -> V_175 ;
V_172 = F_56 ( V_38 , V_22 , & V_173 ) ;
if ( ! V_172 ) {
V_31 = NULL ;
break;
}
F_78 ( V_167 ) = F_79 ( V_2 , V_174 , V_170 , V_37 ) ;
V_31 -> V_34 = V_172 ;
V_31 -> V_35 = V_173 ;
V_31 = V_172 ;
V_31 -> V_74 = F_78 ( V_167 ) ;
V_31 -> V_36 = V_170 ;
V_31 -> V_37 = V_37 ;
}
V_31 -> V_34 = NULL ;
V_31 -> V_35 = 0 ;
return V_31 ;
}
static int F_80 ( struct V_176 * V_9 , const T_3 * V_116 ,
unsigned int V_117 )
{
struct V_54 * V_55 = F_81 ( V_9 ) ;
T_2 * V_22 = & V_9 -> V_62 . V_147 ;
int V_85 ;
F_82 ( & V_55 -> V_76 ) ;
F_64 ( & V_55 -> V_75 ) ;
F_54 ( & V_55 -> V_50 ) ;
F_54 ( & V_55 -> V_78 ) ;
V_55 -> V_50 . V_106 = V_177 ;
V_55 -> V_78 . V_106 = V_177 ;
V_85 = F_71 ( & V_9 -> V_62 , 0 , V_116 , V_117 ) ;
if ( V_85 )
goto V_178;
V_85 = F_71 ( & V_9 -> V_62 , 1 , V_116 , V_117 ) ;
if ( V_85 )
goto V_178;
if ( * V_22 & V_163 ) {
if ( * V_22 & V_179 ) {
V_85 = - V_157 ;
} else {
* V_22 &= ~ V_163 ;
}
}
V_178:
if ( ! F_27 ( & V_55 -> V_75 ) )
F_83 ( & V_55 -> V_76 ) ;
return V_85 ;
}
static int F_84 ( struct V_176 * V_9 , const T_3 * V_116 ,
unsigned int V_117 )
{
struct V_54 * V_55 = F_81 ( V_9 ) ;
if ( V_117 < V_180 )
return - V_157 ;
memcpy ( V_55 -> V_181 , V_116 + ( V_117 - V_180 ) ,
V_180 ) ;
V_117 -= V_180 ;
return F_80 ( V_9 , V_116 , V_117 ) ;
}
static int F_85 ( struct V_65 * V_41 , int V_50 )
{
struct V_176 * V_9 = F_86 ( V_41 ) ;
struct V_54 * V_55 = F_81 ( V_9 ) ;
unsigned V_182 = F_87 ( V_9 ) ;
struct V_104 * V_37 ;
struct V_3 * V_39 ;
unsigned int V_168 = V_41 -> V_168 ;
enum V_169 V_183 = V_184 ;
struct V_67 * V_45 = F_25 ( V_41 ) ;
struct V_30 V_185 ;
T_4 V_22 = V_41 -> V_62 . V_22 & V_186 ?
V_107 : V_18 ;
if ( F_88 ( V_101 ) )
return - V_122 ;
if ( F_89 ( & V_55 -> V_75 ) )
return - V_122 ;
V_37 = V_50 ? & V_55 -> V_50 : & V_55 -> V_78 ;
V_39 = F_11 () ;
if ( ! V_39 )
return - V_19 ;
V_39 -> V_42 . V_66 = V_41 ;
V_39 -> V_125 = V_37 -> V_108 ;
V_39 -> V_126 = V_37 -> V_106 ;
V_39 -> V_114 = V_37 -> V_105 ;
V_39 -> V_141 = 0 ;
V_39 -> V_142 = V_168 ;
F_66 ( V_182 && ! V_41 -> V_187 ) ;
memcpy ( V_39 -> V_188 , V_41 -> V_187 , V_182 ) ;
if ( V_41 -> V_52 != V_41 -> V_68 ) {
struct V_30 V_189 ;
V_39 -> V_126 |= V_190 ;
F_66 ( V_41 -> V_68 -> V_171 < V_168 ) ;
V_45 -> V_68 = NULL ;
if ( ! F_73 ( V_2 , V_41 -> V_68 , V_168 , & V_189 ,
V_22 , V_191 ) )
goto V_192;
V_183 = V_193 ;
V_45 -> V_68 = V_189 . V_34 ;
V_39 -> V_69 = V_189 . V_35 ;
} else {
V_45 -> V_68 = NULL ;
}
V_45 -> V_52 = NULL ;
if ( ! F_73 ( V_2 , V_41 -> V_52 , V_168 , & V_185 ,
V_22 , V_183 ) )
goto V_194;
V_45 -> V_52 = V_185 . V_34 ;
V_39 -> V_61 = V_185 . V_35 ;
V_39 -> V_24 |= V_64 ;
F_65 ( V_101 , F_2 ( V_39 ) ) ;
F_66 ( F_67 ( V_101 ) ) ;
return - V_195 ;
V_194:
F_16 ( V_2 , V_45 -> V_52 , V_39 -> V_61 ) ;
V_192:
if ( V_41 -> V_52 != V_41 -> V_68 ) {
F_16 ( V_2 , V_45 -> V_68 , V_39 -> V_69 ) ;
}
V_39 -> V_24 = V_25 ;
return - V_19 ;
}
static int F_90 ( struct V_65 * V_41 )
{
return F_85 ( V_41 , 1 ) ;
}
static int F_91 ( struct V_65 * V_41 )
{
return F_85 ( V_41 , 0 ) ;
}
static int F_92 ( struct V_65 * V_41 )
{
struct V_176 * V_9 = F_86 ( V_41 ) ;
struct V_54 * V_55 = F_81 ( V_9 ) ;
T_3 V_188 [ V_196 ] ;
T_3 * V_187 = V_41 -> V_187 ;
int V_85 ;
memcpy ( V_188 , V_55 -> V_181 , V_180 ) ;
memcpy ( V_188 + V_180 , V_187 , V_197 ) ;
* ( V_198 * ) ( V_188 + V_180 + V_197 ) =
F_28 ( 1 ) ;
V_41 -> V_187 = V_188 ;
V_85 = F_85 ( V_41 , 1 ) ;
V_41 -> V_187 = V_187 ;
return V_85 ;
}
static int F_93 ( struct V_166 * V_167 , unsigned V_199 ,
unsigned int V_168 )
{
int V_175 = 0 ;
if ( ! V_168 )
return 0 ;
for (; ; ) {
if ( V_199 < V_175 + V_167 -> V_171 )
break;
V_175 += V_167 -> V_171 ;
V_167 = F_74 ( V_167 ) ;
}
return ( V_199 + V_168 > V_175 + V_167 -> V_171 ) ;
}
static int F_94 ( struct V_40 * V_41 , int V_50 ,
int V_200 , int V_201 , T_3 * V_188 )
{
struct V_46 * V_9 = F_21 ( V_41 ) ;
struct V_54 * V_55 = F_95 ( V_9 ) ;
unsigned V_182 = F_96 ( V_9 ) ;
unsigned V_47 = F_22 ( V_9 ) ;
struct V_104 * V_37 ;
struct V_3 * V_39 ;
unsigned int V_49 ;
struct V_30 * V_31 , V_185 ;
struct V_44 * V_45 = F_20 ( V_41 ) ;
T_4 V_22 = V_41 -> V_62 . V_22 & V_186 ?
V_107 : V_18 ;
if ( F_88 ( V_101 ) )
return - V_122 ;
if ( F_89 ( & V_55 -> V_75 ) )
return - V_122 ;
if ( V_50 ) {
V_37 = & V_55 -> V_50 ;
V_49 = V_41 -> V_49 ;
} else {
V_37 = & V_55 -> V_78 ;
V_49 = V_41 -> V_49 - V_47 ;
V_201 -= V_47 ;
}
V_39 = F_11 () ;
if ( ! V_39 )
return - V_19 ;
V_39 -> V_42 . V_43 = V_41 ;
V_39 -> V_125 = V_37 -> V_108 ;
V_39 -> V_126 = V_37 -> V_106 ;
V_39 -> V_114 = V_37 -> V_105 ;
V_39 -> V_141 = V_200 ;
V_39 -> V_142 = V_201 ;
V_39 -> V_123 = 0 ;
V_39 -> V_124 = V_41 -> V_202 + V_182 + V_49 ;
F_66 ( V_182 && ! V_41 -> V_188 ) ;
memcpy ( V_39 -> V_188 , V_41 -> V_188 , V_182 ) ;
if ( V_41 -> V_52 != V_41 -> V_68 ) {
F_29 () ;
}
V_31 = F_73 ( V_2 , V_41 -> V_203 , V_41 -> V_202 , & V_185 ,
V_22 , V_193 ) ;
V_45 -> V_60 = V_185 . V_34 ;
V_39 -> V_61 = V_185 . V_35 ;
if ( ! V_31 )
goto V_178;
F_97 ( & V_45 -> V_204 , 1 ) ;
F_98 ( & V_45 -> V_204 , V_188 , V_182 ) ;
V_31 = F_73 ( V_2 , & V_45 -> V_204 , V_182 , V_31 , V_22 ,
V_184 ) ;
if ( ! V_31 )
goto V_205;
if ( F_13 ( F_93 ( V_41 -> V_52 , V_49 , V_47 ) ) ) {
V_45 -> V_51 = F_56 ( V_38 , V_22 ,
& V_39 -> V_53 ) ;
if ( F_13 ( ! V_45 -> V_51 ) )
goto V_205;
if ( ! V_50 ) {
F_23 ( V_45 -> V_51 ,
V_41 -> V_52 , V_49 , V_47 , 0 ) ;
}
V_45 -> V_50 = V_50 ;
} else {
V_45 -> V_51 = NULL ;
}
V_31 = F_73 ( V_2 , V_41 -> V_52 , V_49 + V_47 , V_31 , V_22 ,
V_184 ) ;
if ( ! V_31 )
goto V_206;
if ( ! V_45 -> V_51 ) {
V_39 -> V_53 = V_31 -> V_74 + V_31 -> V_36 - V_47 ;
}
V_39 -> V_24 |= V_59 ;
F_65 ( V_101 , F_2 ( V_39 ) ) ;
F_66 ( F_67 ( V_101 ) ) ;
return - V_195 ;
V_206:
if ( V_45 -> V_51 ) {
F_18 ( V_38 , V_45 -> V_51 ,
V_39 -> V_53 ) ;
}
V_205:
F_16 ( V_2 , V_45 -> V_60 , V_39 -> V_61 ) ;
V_178:
V_39 -> V_24 = V_25 ;
return - V_19 ;
}
static int F_99 ( struct V_46 * V_9 , unsigned int V_47 )
{
struct V_54 * V_55 = F_95 ( V_9 ) ;
T_2 * V_22 = & V_9 -> V_62 . V_147 ;
unsigned V_129 = F_100 ( V_9 ) -> V_207 ;
int V_85 ;
if ( ! V_55 -> V_208 && ! V_55 -> V_209 )
return 0 ;
F_82 ( & V_55 -> V_76 ) ;
F_64 ( & V_55 -> V_75 ) ;
F_54 ( & V_55 -> V_50 ) ;
F_54 ( & V_55 -> V_78 ) ;
V_85 = F_71 ( & V_9 -> V_62 , 0 , V_55 -> V_210 , V_55 -> V_208 ) ;
if ( V_85 )
goto V_178;
V_85 = F_71 ( & V_9 -> V_62 , 1 , V_55 -> V_210 , V_55 -> V_208 ) ;
if ( V_85 )
goto V_178;
V_85 = F_68 ( & V_9 -> V_62 , 0 , V_47 , V_55 -> V_211 ,
V_55 -> V_209 , V_129 ) ;
if ( V_85 )
goto V_178;
V_85 = F_68 ( & V_9 -> V_62 , 1 , V_47 , V_55 -> V_211 ,
V_55 -> V_209 , V_129 ) ;
if ( V_85 )
goto V_178;
if ( * V_22 & V_163 ) {
if ( * V_22 & V_179 ) {
V_85 = - V_157 ;
goto V_178;
} else {
* V_22 &= ~ V_163 ;
}
}
V_178:
if ( ! F_27 ( & V_55 -> V_75 ) )
F_83 ( & V_55 -> V_76 ) ;
return V_85 ;
}
static int F_101 ( struct V_46 * V_9 , unsigned int V_47 )
{
int V_212 = F_100 ( V_9 ) -> V_207 >> 2 ;
if ( ( V_47 >> 2 ) < 1 || ( V_47 >> 2 ) > V_212 || ( V_47 & 3 ) )
return - V_157 ;
return F_99 ( V_9 , V_47 ) ;
}
static int F_102 ( struct V_46 * V_9 , const T_3 * V_116 ,
unsigned int V_213 )
{
struct V_54 * V_55 = F_95 ( V_9 ) ;
struct V_214 * V_215 = (struct V_214 * ) V_116 ;
struct V_216 * V_217 ;
if ( ! F_103 ( V_215 , V_213 ) )
goto V_218;
if ( V_215 -> V_219 != V_220 )
goto V_218;
if ( F_104 ( V_215 ) < sizeof( * V_217 ) )
goto V_218;
V_217 = F_105 ( V_215 ) ;
V_55 -> V_208 = F_106 ( V_217 -> V_221 ) ;
V_116 += F_107 ( V_215 -> V_222 ) ;
V_213 -= F_107 ( V_215 -> V_222 ) ;
if ( V_213 < V_55 -> V_208 )
goto V_218;
V_55 -> V_209 = V_213 - V_55 -> V_208 ;
memcpy ( V_55 -> V_210 , V_116 + V_55 -> V_209 , V_55 -> V_208 ) ;
memcpy ( V_55 -> V_211 , V_116 , V_55 -> V_209 ) ;
return F_99 ( V_9 , F_22 ( V_9 ) ) ;
V_218:
V_55 -> V_208 = 0 ;
F_108 ( V_9 , V_156 ) ;
return - V_157 ;
}
static int F_109 ( struct V_40 * V_41 )
{
unsigned V_182 = F_96 ( F_21 ( V_41 ) ) ;
return F_94 ( V_41 , 1 , V_41 -> V_202 + V_182 ,
V_41 -> V_49 , V_41 -> V_188 ) ;
}
static int F_110 ( struct V_40 * V_41 )
{
unsigned V_182 = F_96 ( F_21 ( V_41 ) ) ;
return F_94 ( V_41 , 0 , V_41 -> V_202 + V_182 ,
V_41 -> V_49 , V_41 -> V_188 ) ;
}
static int F_111 ( struct V_223 * V_41 )
{
struct V_46 * V_9 = F_112 ( V_41 ) ;
struct V_54 * V_55 = F_95 ( V_9 ) ;
unsigned V_170 , V_182 = F_96 ( V_9 ) ;
T_5 V_224 ;
if ( ! V_55 -> V_225 ) {
F_113 ( V_55 -> V_226 , V_182 ) ;
V_55 -> V_225 = 1 ;
}
memcpy ( V_41 -> V_227 . V_188 , V_55 -> V_226 , V_182 ) ;
V_170 = V_182 ;
if ( V_182 > sizeof( V_228 ) ) {
memset ( V_41 -> V_229 , 0 , V_182 - sizeof( V_228 ) ) ;
V_170 = sizeof( V_228 ) ;
}
V_224 = F_114 ( V_41 -> V_224 ) ;
memcpy ( V_41 -> V_229 + V_182 - V_170 , & V_224 , V_170 ) ;
return F_94 ( & V_41 -> V_227 , 1 , V_41 -> V_227 . V_202 ,
V_41 -> V_227 . V_49 + V_182 , V_41 -> V_229 ) ;
}
static int T_6 F_115 ( void )
{
int V_230 = F_116 ( V_231 ) ;
int V_20 , V_99 ;
if ( F_117 ( & V_232 ) )
return - V_86 ;
F_118 ( & V_23 ) ;
F_118 ( & V_28 ) ;
V_99 = F_34 () ;
if ( V_99 ) {
F_119 ( & V_232 ) ;
return V_99 ;
}
for ( V_20 = 0 ; V_20 < V_230 ; V_20 ++ ) {
struct V_233 * V_234 = & V_231 [ V_20 ] . V_12 ;
if ( snprintf ( V_234 -> V_235 , V_236 ,
L_10 V_237 , V_234 -> V_238 ) >=
V_236 )
{
continue;
}
if ( ! V_97 && ( V_231 [ V_20 ] . V_13 & V_149 ) ) {
continue;
}
if ( ! V_231 [ V_20 ] . V_16 ) {
V_234 -> V_239 = & V_240 ;
V_234 -> V_241 = V_242 |
V_243 |
V_244 ;
if ( ! V_234 -> V_245 . V_246 )
V_234 -> V_245 . V_246 = F_80 ;
if ( ! V_234 -> V_245 . V_50 )
V_234 -> V_245 . V_50 = F_90 ;
if ( ! V_234 -> V_245 . V_78 )
V_234 -> V_245 . V_78 = F_91 ;
V_234 -> V_247 = F_60 ;
} else {
V_234 -> V_239 = & V_248 ;
V_234 -> V_241 = V_249 |
V_243 |
V_244 ;
V_234 -> V_250 . V_246 = F_102 ;
V_234 -> V_250 . V_251 = F_101 ;
V_234 -> V_250 . V_50 = F_109 ;
V_234 -> V_250 . V_78 = F_110 ;
V_234 -> V_250 . V_252 = F_111 ;
V_234 -> V_247 = F_61 ;
}
V_234 -> V_253 = sizeof( struct V_54 ) ;
V_234 -> V_254 = V_255 ;
V_234 -> V_256 = 3 ;
V_234 -> V_257 = 300 ;
V_234 -> V_258 = F_62 ;
if ( F_120 ( V_234 ) )
F_35 ( V_92 L_11 ,
V_234 -> V_238 ) ;
else
V_231 [ V_20 ] . V_259 = 1 ;
}
return 0 ;
}
static void T_7 F_121 ( void )
{
int V_230 = F_116 ( V_231 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_230 ; V_20 ++ ) {
if ( V_231 [ V_20 ] . V_259 )
F_122 ( & V_231 [ V_20 ] . V_12 ) ;
}
F_50 () ;
F_119 ( & V_232 ) ;
}
