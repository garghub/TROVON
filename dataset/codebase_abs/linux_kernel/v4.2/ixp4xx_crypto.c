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
int V_49 = V_42 -> V_50 - V_48 ;
if ( V_46 -> V_51 ) {
F_22 ( V_46 -> V_52 ,
V_42 -> V_53 , V_49 , V_48 , 1 ) ;
}
F_17 ( V_39 , V_46 -> V_52 , V_40 -> V_54 ) ;
}
static void F_23 ( T_1 V_5 )
{
struct V_15 * V_16 = & V_17 -> V_16 ;
struct V_1 * V_40 ;
struct V_55 * V_56 ;
int V_57 ;
V_57 = V_5 & 0x1 ? - V_58 : 0 ;
V_5 &= ~ 0x3 ;
V_40 = F_2 ( V_5 ) ;
switch ( V_40 -> V_25 & V_59 ) {
case V_60 : {
struct V_41 * V_42 = V_40 -> V_43 . V_44 ;
struct V_45 * V_46 = F_19 ( V_42 ) ;
F_15 ( V_16 , V_46 -> V_61 , V_40 -> V_62 ) ;
if ( V_46 -> V_52 ) {
F_18 ( V_40 ) ;
}
V_42 -> V_63 . V_64 ( & V_42 -> V_63 , V_57 ) ;
break;
}
case V_65 : {
struct V_66 * V_42 = V_40 -> V_43 . V_67 ;
struct V_68 * V_46 = F_24 ( V_42 ) ;
if ( V_46 -> V_69 ) {
F_15 ( V_16 , V_46 -> V_69 , V_40 -> V_70 ) ;
}
F_15 ( V_16 , V_46 -> V_53 , V_40 -> V_62 ) ;
V_42 -> V_63 . V_64 ( & V_42 -> V_63 , V_57 ) ;
break;
}
case V_71 :
V_56 = F_25 ( V_40 -> V_43 . V_7 ) ;
F_17 ( V_72 , V_40 -> V_73 ,
V_40 -> V_74 -> V_75 ) ;
F_17 ( V_39 , V_40 -> V_74 , V_40 -> V_62 ) ;
if ( F_26 ( & V_56 -> V_76 ) )
V_64 ( & V_56 -> V_77 ) ;
break;
case V_78 :
V_56 = F_25 ( V_40 -> V_43 . V_7 ) ;
* ( T_2 * ) V_56 -> V_79 . V_80 &= F_27 ( ~ V_81 ) ;
if ( F_26 ( & V_56 -> V_76 ) )
V_64 ( & V_56 -> V_77 ) ;
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
if ( V_86 ) {
return V_86 ;
}
if ( F_39 ( V_94 , V_88 , L_2 ) )
goto V_96;
} else {
if ( F_40 ( V_94 , V_88 , L_2 ) )
goto V_96;
if ( F_39 ( V_94 , V_88 , L_2 ) )
goto V_96;
}
switch ( ( V_88 [ 1 ] >> 16 ) & 0xff ) {
case 3 :
F_34 ( V_97 L_3 ,
F_38 ( V_94 ) ) ;
V_98 = 0 ;
break;
case 4 :
case 5 :
V_98 = 1 ;
break;
default:
F_34 ( V_93 L_4 ,
F_38 ( V_94 ) ) ;
return - V_87 ;
}
F_8 ( V_99 > sizeof( struct V_31 ) ) ;
V_39 = F_41 ( L_5 , V_16 ,
sizeof( struct V_31 ) , 32 , 0 ) ;
V_86 = - V_20 ;
if ( ! V_39 ) {
goto V_100;
}
V_72 = F_41 ( L_6 , V_16 ,
V_101 , 16 , 0 ) ;
if ( ! V_72 ) {
goto V_100;
}
V_86 = F_42 ( V_102 , V_30 , 0 , 0 ,
L_7 , NULL ) ;
if ( V_86 )
goto V_100;
V_86 = F_42 ( V_85 , V_18 , 0 , 0 ,
L_8 , NULL ) ;
if ( V_86 ) {
F_43 ( V_102 ) ;
goto V_100;
}
F_44 ( V_85 , V_103 , F_29 , NULL ) ;
F_45 ( & V_83 , F_31 , 0 ) ;
F_46 ( V_85 ) ;
return 0 ;
V_96:
F_34 ( V_93 L_9 , F_38 ( V_94 ) ) ;
V_86 = - V_104 ;
V_100:
if ( V_72 )
F_47 ( V_72 ) ;
if ( V_39 )
F_47 ( V_39 ) ;
F_48 ( V_94 ) ;
return V_86 ;
}
static void F_49 ( struct V_15 * V_16 )
{
F_50 ( V_85 ) ;
F_51 ( & V_83 ) ;
F_43 ( V_102 ) ;
F_43 ( V_85 ) ;
F_47 ( V_72 ) ;
F_47 ( V_39 ) ;
F_48 ( V_94 ) ;
if ( V_4 ) {
F_52 ( V_16 ,
V_30 * sizeof( struct V_1 ) ,
V_4 , V_3 ) ;
}
return;
}
static void F_53 ( struct V_105 * V_38 )
{
memset ( V_38 -> V_80 , 0 , V_101 ) ;
V_38 -> V_106 = 0 ;
V_38 -> V_107 = 0 ;
}
static int F_54 ( struct V_105 * V_38 )
{
V_38 -> V_80 = F_55 ( V_72 , V_108 , & V_38 -> V_109 ) ;
if ( ! V_38 -> V_80 ) {
return - V_20 ;
}
F_53 ( V_38 ) ;
return 0 ;
}
static void F_56 ( struct V_105 * V_38 )
{
memset ( V_38 -> V_80 , 0 , V_101 ) ;
F_17 ( V_72 , V_38 -> V_80 , V_38 -> V_109 ) ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_55 * V_56 = F_25 ( V_7 ) ;
int V_86 ;
F_58 ( & V_56 -> V_76 , 0 ) ;
V_86 = F_54 ( & V_56 -> V_51 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_54 ( & V_56 -> V_79 ) ;
if ( V_86 ) {
F_56 ( & V_56 -> V_51 ) ;
}
return V_86 ;
}
static int F_59 ( struct V_6 * V_7 )
{
V_7 -> V_110 . V_111 = sizeof( struct V_68 ) ;
return F_57 ( V_7 ) ;
}
static int F_60 ( struct V_6 * V_7 )
{
F_61 ( F_62 ( V_7 ) ,
sizeof( struct V_45 ) ) ;
return F_57 ( V_7 ) ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_55 * V_56 = F_25 ( V_7 ) ;
F_56 ( & V_56 -> V_51 ) ;
F_56 ( & V_56 -> V_79 ) ;
}
static int F_64 ( struct V_6 * V_7 , T_3 V_112 , T_2 V_113 ,
int V_114 , T_2 V_115 , const T_3 * V_116 , int V_117 )
{
struct V_55 * V_56 = F_25 ( V_7 ) ;
struct V_1 * V_40 ;
struct V_31 * V_32 ;
int V_21 ;
T_3 * V_118 ;
T_2 V_119 , V_120 ;
F_8 ( V_101 < V_121 ) ;
V_118 = F_55 ( V_72 , V_108 , & V_119 ) ;
if ( ! V_118 )
return - V_20 ;
V_32 = F_55 ( V_39 , V_108 , & V_120 ) ;
if ( ! V_32 ) {
F_17 ( V_72 , V_118 , V_119 ) ;
return - V_20 ;
}
V_40 = F_14 () ;
if ( ! V_40 ) {
F_17 ( V_72 , V_118 , V_119 ) ;
F_17 ( V_39 , V_32 , V_120 ) ;
return - V_122 ;
}
memcpy ( V_118 , V_116 , V_117 ) ;
memset ( V_118 + V_117 , 0 , V_121 - V_117 ) ;
for ( V_21 = 0 ; V_21 < V_121 ; V_21 ++ ) {
V_118 [ V_21 ] ^= V_112 ;
}
V_40 -> V_43 . V_7 = V_7 ;
V_40 -> V_73 = V_118 ;
V_40 -> V_74 = V_32 ;
V_40 -> V_123 = 0 ;
V_40 -> V_124 = V_121 ;
V_40 -> V_125 = V_115 ;
V_40 -> V_62 = V_120 ;
V_40 -> V_54 = V_113 ;
V_40 -> V_126 = V_127 ;
V_40 -> V_114 = V_114 ;
V_40 -> V_25 |= V_71 ;
V_32 -> V_35 = 0 ;
V_32 -> V_37 = V_121 ;
V_32 -> V_128 = 0 ;
V_32 -> V_75 = V_119 ;
F_65 ( & V_56 -> V_76 ) ;
F_66 ( V_102 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_102 ) ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 , int V_51 , unsigned V_48 ,
const T_3 * V_116 , int V_117 , unsigned V_129 )
{
T_2 V_130 , V_131 , V_132 ;
unsigned char * V_133 ;
int V_114 , V_86 = 0 ;
T_2 V_134 ;
struct V_105 * V_38 ;
struct V_55 * V_56 = F_25 ( V_7 ) ;
const struct V_13 * V_135 ;
V_38 = V_51 ? & V_56 -> V_51 : & V_56 -> V_79 ;
V_133 = V_38 -> V_80 + V_38 -> V_106 ;
V_135 = F_6 ( V_7 ) ;
V_134 = V_135 -> V_134 | ( V_48 << 6 ) ;
#ifndef F_70
V_134 ^= 0xAA000000 ;
#endif
* ( T_2 * ) V_133 = F_27 ( V_134 ) ;
V_133 += sizeof( V_134 ) ;
memcpy ( V_133 , V_135 -> V_136 , V_129 ) ;
V_133 += V_129 ;
V_130 = V_38 -> V_109 + V_38 -> V_106
+ sizeof( V_135 -> V_134 ) ;
V_131 = V_130 + V_129 ;
V_114 = V_133 - ( V_38 -> V_80 + V_38 -> V_106 ) ;
V_132 = V_38 -> V_109 + V_38 -> V_106 ;
V_38 -> V_106 += V_114 ;
V_38 -> V_107 |= V_137 ;
if ( ! V_51 )
V_38 -> V_107 |= V_138 ;
V_86 = F_64 ( V_7 , V_139 , V_131 ,
V_114 , V_132 , V_116 , V_117 ) ;
if ( V_86 )
return V_86 ;
return F_64 ( V_7 , V_140 , V_130 ,
V_114 , V_132 , V_116 , V_117 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_40 ;
struct V_55 * V_56 = F_25 ( V_7 ) ;
struct V_105 * V_38 = & V_56 -> V_79 ;
V_40 = F_14 () ;
if ( ! V_40 ) {
return - V_122 ;
}
* ( T_2 * ) V_38 -> V_80 |= F_27 ( V_81 ) ;
V_40 -> V_43 . V_7 = V_7 ;
V_40 -> V_141 = 0 ;
V_40 -> V_142 = V_143 ;
V_40 -> V_62 = 0 ;
V_40 -> V_125 = V_38 -> V_109 ;
V_40 -> V_54 = V_38 -> V_109 + sizeof( T_2 ) ;
V_40 -> V_126 = V_144 ;
V_40 -> V_114 = V_38 -> V_106 ;
V_40 -> V_25 |= V_78 ;
F_65 ( & V_56 -> V_76 ) ;
F_66 ( V_102 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_102 ) ) ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 , int V_51 ,
const T_3 * V_116 , int V_117 )
{
T_3 * V_133 ;
T_2 V_145 ;
T_2 V_146 = 0 ;
struct V_105 * V_38 ;
struct V_55 * V_56 = F_25 ( V_7 ) ;
T_2 * V_23 = & V_7 -> V_147 ;
V_38 = V_51 ? & V_56 -> V_51 : & V_56 -> V_79 ;
V_133 = V_38 -> V_80 ;
if ( V_51 ) {
V_145 = F_3 ( V_7 ) ;
V_38 -> V_107 |= V_148 ;
} else {
V_145 = F_5 ( V_7 ) ;
}
if ( V_145 & V_149 ) {
switch ( V_117 ) {
case 16 : V_146 = V_150 ; break;
case 24 : V_146 = V_151 ; break;
case 32 : V_146 = V_152 ; break;
default:
* V_23 |= V_153 ;
return - V_154 ;
}
V_145 |= V_146 ;
} else if ( V_145 & V_155 ) {
const T_2 * V_156 = ( const T_2 * ) V_116 ;
if ( F_12 ( ! ( ( V_156 [ 0 ] ^ V_156 [ 2 ] ) | ( V_156 [ 1 ] ^ V_156 [ 3 ] ) ) ||
! ( ( V_156 [ 2 ] ^ V_156 [ 4 ] ) | ( V_156 [ 3 ] ^ V_156 [ 5 ] ) ) ) )
{
* V_23 |= V_157 ;
return - V_154 ;
}
} else {
T_2 V_158 [ V_159 ] ;
if ( F_73 ( V_158 , V_116 ) == 0 ) {
* V_23 |= V_160 ;
}
}
* ( T_2 * ) V_133 = F_27 ( V_145 ) ;
V_133 += sizeof( V_145 ) ;
memcpy ( V_133 , V_116 , V_117 ) ;
if ( V_117 < V_161 && ! ( V_145 & V_149 ) ) {
memset ( V_133 + V_117 , 0 , V_161 - V_117 ) ;
V_117 = V_161 ;
}
V_38 -> V_106 = sizeof( V_145 ) + V_117 ;
V_38 -> V_107 |= V_162 ;
if ( ( V_145 & V_149 ) && ! V_51 ) {
return F_71 ( V_7 ) ;
}
return 0 ;
}
static struct V_31 * F_74 ( struct V_15 * V_16 ,
struct V_163 * V_164 , unsigned V_165 ,
struct V_31 * V_32 , T_4 V_23 ,
enum V_166 V_38 )
{
for (; V_165 > 0 ; V_164 = F_75 ( V_164 ) ) {
unsigned V_167 = F_76 ( V_165 , V_164 -> V_168 ) ;
struct V_31 * V_169 ;
T_2 V_170 ;
void * V_171 ;
V_165 -= V_167 ;
V_171 = F_77 ( F_78 ( V_164 ) ) + V_164 -> V_172 ;
V_169 = F_55 ( V_39 , V_23 , & V_170 ) ;
if ( ! V_169 ) {
V_32 = NULL ;
break;
}
F_79 ( V_164 ) = F_80 ( V_16 , V_171 , V_167 , V_38 ) ;
V_32 -> V_35 = V_169 ;
V_32 -> V_36 = V_170 ;
V_32 = V_169 ;
V_32 -> V_75 = F_79 ( V_164 ) ;
V_32 -> V_37 = V_167 ;
V_32 -> V_38 = V_38 ;
}
V_32 -> V_35 = NULL ;
V_32 -> V_36 = 0 ;
return V_32 ;
}
static int F_81 ( struct V_173 * V_7 , const T_3 * V_116 ,
unsigned int V_117 )
{
struct V_55 * V_56 = F_82 ( V_7 ) ;
T_2 * V_23 = & V_7 -> V_63 . V_147 ;
int V_86 ;
F_83 ( & V_56 -> V_77 ) ;
F_65 ( & V_56 -> V_76 ) ;
F_53 ( & V_56 -> V_51 ) ;
F_53 ( & V_56 -> V_79 ) ;
V_56 -> V_51 . V_107 = V_174 ;
V_56 -> V_79 . V_107 = V_174 ;
V_86 = F_72 ( & V_7 -> V_63 , 0 , V_116 , V_117 ) ;
if ( V_86 )
goto V_175;
V_86 = F_72 ( & V_7 -> V_63 , 1 , V_116 , V_117 ) ;
if ( V_86 )
goto V_175;
if ( * V_23 & V_160 ) {
if ( * V_23 & V_176 ) {
V_86 = - V_154 ;
} else {
* V_23 &= ~ V_160 ;
}
}
V_175:
if ( ! F_26 ( & V_56 -> V_76 ) )
F_84 ( & V_56 -> V_77 ) ;
return V_86 ;
}
static int F_85 ( struct V_173 * V_7 , const T_3 * V_116 ,
unsigned int V_117 )
{
struct V_55 * V_56 = F_82 ( V_7 ) ;
if ( V_117 < V_177 )
return - V_154 ;
memcpy ( V_56 -> V_178 , V_116 + ( V_117 - V_177 ) ,
V_177 ) ;
V_117 -= V_177 ;
return F_81 ( V_7 , V_116 , V_117 ) ;
}
static int F_86 ( struct V_66 * V_42 , int V_51 )
{
struct V_173 * V_7 = F_87 ( V_42 ) ;
struct V_55 * V_56 = F_82 ( V_7 ) ;
unsigned V_179 = F_88 ( V_7 ) ;
struct V_105 * V_38 ;
struct V_1 * V_40 ;
unsigned int V_165 = V_42 -> V_165 ;
enum V_166 V_180 = V_181 ;
struct V_68 * V_46 = F_24 ( V_42 ) ;
struct V_31 V_182 ;
struct V_15 * V_16 = & V_17 -> V_16 ;
T_4 V_23 = V_42 -> V_63 . V_23 & V_183 ?
V_108 : V_19 ;
if ( F_89 ( V_102 ) )
return - V_122 ;
if ( F_90 ( & V_56 -> V_76 ) )
return - V_122 ;
V_38 = V_51 ? & V_56 -> V_51 : & V_56 -> V_79 ;
V_40 = F_10 () ;
if ( ! V_40 )
return - V_20 ;
V_40 -> V_43 . V_67 = V_42 ;
V_40 -> V_125 = V_38 -> V_109 ;
V_40 -> V_126 = V_38 -> V_107 ;
V_40 -> V_114 = V_38 -> V_106 ;
V_40 -> V_141 = 0 ;
V_40 -> V_142 = V_165 ;
F_67 ( V_179 && ! V_42 -> V_184 ) ;
memcpy ( V_40 -> V_185 , V_42 -> V_184 , V_179 ) ;
if ( V_42 -> V_53 != V_42 -> V_69 ) {
struct V_31 V_186 ;
V_40 -> V_126 |= V_187 ;
V_46 -> V_69 = NULL ;
if ( ! F_74 ( V_16 , V_42 -> V_69 , V_165 , & V_186 ,
V_23 , V_188 ) )
goto V_189;
V_180 = V_190 ;
V_46 -> V_69 = V_186 . V_35 ;
V_40 -> V_70 = V_186 . V_36 ;
} else {
V_46 -> V_69 = NULL ;
}
V_46 -> V_53 = NULL ;
if ( ! F_74 ( V_16 , V_42 -> V_53 , V_165 , & V_182 ,
V_23 , V_180 ) )
goto V_191;
V_46 -> V_53 = V_182 . V_35 ;
V_40 -> V_62 = V_182 . V_36 ;
V_40 -> V_25 |= V_65 ;
F_66 ( V_102 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_102 ) ) ;
return - V_192 ;
V_191:
F_15 ( V_16 , V_46 -> V_53 , V_40 -> V_62 ) ;
V_189:
if ( V_42 -> V_53 != V_42 -> V_69 ) {
F_15 ( V_16 , V_46 -> V_69 , V_40 -> V_70 ) ;
}
V_40 -> V_25 = V_26 ;
return - V_20 ;
}
static int F_91 ( struct V_66 * V_42 )
{
return F_86 ( V_42 , 1 ) ;
}
static int F_92 ( struct V_66 * V_42 )
{
return F_86 ( V_42 , 0 ) ;
}
static int F_93 ( struct V_66 * V_42 )
{
struct V_173 * V_7 = F_87 ( V_42 ) ;
struct V_55 * V_56 = F_82 ( V_7 ) ;
T_3 V_185 [ V_193 ] ;
T_3 * V_184 = V_42 -> V_184 ;
int V_86 ;
memcpy ( V_185 , V_56 -> V_178 , V_177 ) ;
memcpy ( V_185 + V_177 , V_184 , V_194 ) ;
* ( V_195 * ) ( V_185 + V_177 + V_194 ) =
F_27 ( 1 ) ;
V_42 -> V_184 = V_185 ;
V_86 = F_86 ( V_42 , 1 ) ;
V_42 -> V_184 = V_184 ;
return V_86 ;
}
static int F_94 ( struct V_163 * V_164 , unsigned V_196 ,
unsigned int V_165 )
{
int V_172 = 0 ;
if ( ! V_165 )
return 0 ;
for (; ; ) {
if ( V_196 < V_172 + V_164 -> V_168 )
break;
V_172 += V_164 -> V_168 ;
V_164 = F_75 ( V_164 ) ;
}
return ( V_196 + V_165 > V_172 + V_164 -> V_168 ) ;
}
static int F_95 ( struct V_41 * V_42 , int V_51 ,
int V_197 , int V_198 , T_3 * V_185 )
{
struct V_47 * V_7 = F_20 ( V_42 ) ;
struct V_55 * V_56 = F_96 ( V_7 ) ;
unsigned V_179 = F_97 ( V_7 ) ;
unsigned V_48 = F_21 ( V_7 ) ;
struct V_105 * V_38 ;
struct V_1 * V_40 ;
unsigned int V_50 ;
struct V_31 * V_32 , V_182 ;
struct V_45 * V_46 = F_19 ( V_42 ) ;
struct V_15 * V_16 = & V_17 -> V_16 ;
T_4 V_23 = V_42 -> V_63 . V_23 & V_183 ?
V_108 : V_19 ;
if ( F_89 ( V_102 ) )
return - V_122 ;
if ( F_90 ( & V_56 -> V_76 ) )
return - V_122 ;
if ( V_51 ) {
V_38 = & V_56 -> V_51 ;
V_50 = V_42 -> V_50 ;
} else {
V_38 = & V_56 -> V_79 ;
V_50 = V_42 -> V_50 - V_48 ;
V_198 -= V_48 ;
}
V_40 = F_10 () ;
if ( ! V_40 )
return - V_20 ;
V_40 -> V_43 . V_44 = V_42 ;
V_40 -> V_125 = V_38 -> V_109 ;
V_40 -> V_126 = V_38 -> V_107 ;
V_40 -> V_114 = V_38 -> V_106 ;
V_40 -> V_141 = V_197 ;
V_40 -> V_142 = V_198 ;
V_40 -> V_123 = 0 ;
V_40 -> V_124 = V_42 -> V_199 + V_179 + V_50 ;
F_67 ( V_179 && ! V_42 -> V_185 ) ;
memcpy ( V_40 -> V_185 , V_42 -> V_185 , V_179 ) ;
if ( V_42 -> V_53 != V_42 -> V_69 ) {
F_28 () ;
}
V_32 = F_74 ( V_16 , V_42 -> V_200 , V_42 -> V_199 , & V_182 ,
V_23 , V_190 ) ;
V_46 -> V_61 = V_182 . V_35 ;
V_40 -> V_62 = V_182 . V_36 ;
if ( ! V_32 )
goto V_175;
F_98 ( & V_46 -> V_201 , 1 ) ;
F_99 ( & V_46 -> V_201 , V_185 , V_179 ) ;
V_32 = F_74 ( V_16 , & V_46 -> V_201 , V_179 , V_32 , V_23 ,
V_181 ) ;
if ( ! V_32 )
goto V_202;
if ( F_12 ( F_94 ( V_42 -> V_53 , V_50 , V_48 ) ) ) {
V_46 -> V_52 = F_55 ( V_39 , V_23 ,
& V_40 -> V_54 ) ;
if ( F_12 ( ! V_46 -> V_52 ) )
goto V_202;
if ( ! V_51 ) {
F_22 ( V_46 -> V_52 ,
V_42 -> V_53 , V_50 , V_48 , 0 ) ;
}
V_46 -> V_51 = V_51 ;
} else {
V_46 -> V_52 = NULL ;
}
V_32 = F_74 ( V_16 , V_42 -> V_53 , V_50 + V_48 , V_32 , V_23 ,
V_181 ) ;
if ( ! V_32 )
goto V_203;
if ( ! V_46 -> V_52 ) {
V_40 -> V_54 = V_32 -> V_75 + V_32 -> V_37 - V_48 ;
}
V_40 -> V_25 |= V_60 ;
F_66 ( V_102 , F_1 ( V_40 ) ) ;
F_67 ( F_68 ( V_102 ) ) ;
return - V_192 ;
V_203:
if ( V_46 -> V_52 ) {
F_17 ( V_39 , V_46 -> V_52 ,
V_40 -> V_54 ) ;
}
V_202:
F_15 ( V_16 , V_46 -> V_61 , V_40 -> V_62 ) ;
V_175:
V_40 -> V_25 = V_26 ;
return - V_20 ;
}
static int F_100 ( struct V_47 * V_7 , unsigned int V_48 )
{
struct V_55 * V_56 = F_96 ( V_7 ) ;
T_2 * V_23 = & V_7 -> V_63 . V_147 ;
unsigned V_129 = F_101 ( V_7 ) ;
int V_86 ;
if ( ! V_56 -> V_204 && ! V_56 -> V_205 )
return 0 ;
F_83 ( & V_56 -> V_77 ) ;
F_65 ( & V_56 -> V_76 ) ;
F_53 ( & V_56 -> V_51 ) ;
F_53 ( & V_56 -> V_79 ) ;
V_86 = F_72 ( & V_7 -> V_63 , 0 , V_56 -> V_206 , V_56 -> V_204 ) ;
if ( V_86 )
goto V_175;
V_86 = F_72 ( & V_7 -> V_63 , 1 , V_56 -> V_206 , V_56 -> V_204 ) ;
if ( V_86 )
goto V_175;
V_86 = F_69 ( & V_7 -> V_63 , 0 , V_48 , V_56 -> V_207 ,
V_56 -> V_205 , V_129 ) ;
if ( V_86 )
goto V_175;
V_86 = F_69 ( & V_7 -> V_63 , 1 , V_48 , V_56 -> V_207 ,
V_56 -> V_205 , V_129 ) ;
if ( V_86 )
goto V_175;
if ( * V_23 & V_160 ) {
if ( * V_23 & V_176 ) {
V_86 = - V_154 ;
goto V_175;
} else {
* V_23 &= ~ V_160 ;
}
}
V_175:
if ( ! F_26 ( & V_56 -> V_76 ) )
F_84 ( & V_56 -> V_77 ) ;
return V_86 ;
}
static int F_102 ( struct V_47 * V_7 , unsigned int V_48 )
{
int V_208 = F_101 ( V_7 ) >> 2 ;
if ( ( V_48 >> 2 ) < 1 || ( V_48 >> 2 ) > V_208 || ( V_48 & 3 ) )
return - V_154 ;
return F_100 ( V_7 , V_48 ) ;
}
static int F_103 ( struct V_47 * V_7 , const T_3 * V_116 ,
unsigned int V_209 )
{
struct V_55 * V_56 = F_96 ( V_7 ) ;
struct V_210 V_211 ;
if ( F_104 ( & V_211 , V_116 , V_209 ) != 0 )
goto V_212;
if ( V_211 . V_213 > sizeof( V_56 -> V_207 ) )
goto V_212;
if ( V_211 . V_214 > sizeof( V_56 -> V_206 ) )
goto V_212;
memcpy ( V_56 -> V_207 , V_211 . V_207 , V_211 . V_213 ) ;
memcpy ( V_56 -> V_206 , V_211 . V_206 , V_211 . V_214 ) ;
V_56 -> V_205 = V_211 . V_213 ;
V_56 -> V_204 = V_211 . V_214 ;
return F_100 ( V_7 , F_21 ( V_7 ) ) ;
V_212:
F_105 ( V_7 , V_153 ) ;
return - V_154 ;
}
static int F_106 ( struct V_41 * V_42 )
{
unsigned V_179 = F_97 ( F_20 ( V_42 ) ) ;
return F_95 ( V_42 , 1 , V_42 -> V_199 + V_179 ,
V_42 -> V_50 , V_42 -> V_185 ) ;
}
static int F_107 ( struct V_41 * V_42 )
{
unsigned V_179 = F_97 ( F_20 ( V_42 ) ) ;
return F_95 ( V_42 , 0 , V_42 -> V_199 + V_179 ,
V_42 -> V_50 , V_42 -> V_185 ) ;
}
static int F_108 ( struct V_215 * V_42 )
{
struct V_47 * V_7 = F_109 ( V_42 ) ;
struct V_55 * V_56 = F_96 ( V_7 ) ;
unsigned V_167 , V_179 = F_97 ( V_7 ) ;
T_5 V_216 ;
if ( ! V_56 -> V_217 ) {
F_110 ( V_56 -> V_218 , V_179 ) ;
V_56 -> V_217 = 1 ;
}
memcpy ( V_42 -> V_219 . V_185 , V_56 -> V_218 , V_179 ) ;
V_167 = V_179 ;
if ( V_179 > sizeof( V_220 ) ) {
memset ( V_42 -> V_221 , 0 , V_179 - sizeof( V_220 ) ) ;
V_167 = sizeof( V_220 ) ;
}
V_216 = F_111 ( V_42 -> V_216 ) ;
memcpy ( V_42 -> V_221 + V_179 - V_167 , & V_216 , V_167 ) ;
return F_95 ( & V_42 -> V_219 , 1 , V_42 -> V_219 . V_199 ,
V_42 -> V_219 . V_50 + V_179 , V_42 -> V_221 ) ;
}
static int T_6 F_112 ( void )
{
int V_222 = F_113 ( V_223 ) ;
int V_21 , V_100 ;
V_17 = F_114 ( & V_224 ) ;
if ( F_115 ( V_17 ) )
return F_116 ( V_17 ) ;
F_117 ( & V_24 ) ;
F_117 ( & V_29 ) ;
V_100 = F_33 ( & V_17 -> V_16 ) ;
if ( V_100 ) {
F_118 ( V_17 ) ;
return V_100 ;
}
for ( V_21 = 0 ; V_21 < V_222 ; V_21 ++ ) {
struct V_225 * V_226 = & V_223 [ V_21 ] . V_10 ;
if ( snprintf ( V_226 -> V_227 , V_228 ,
L_10 V_229 , V_226 -> V_230 ) >=
V_228 )
{
continue;
}
if ( ! V_98 && ( V_223 [ V_21 ] . V_11 & V_149 ) ) {
continue;
}
if ( ! V_223 [ V_21 ] . V_14 ) {
V_226 -> V_231 = & V_232 ;
V_226 -> V_233 = V_234 |
V_235 |
V_236 ;
if ( ! V_226 -> V_237 . V_238 )
V_226 -> V_237 . V_238 = F_81 ;
if ( ! V_226 -> V_237 . V_51 )
V_226 -> V_237 . V_51 = F_91 ;
if ( ! V_226 -> V_237 . V_79 )
V_226 -> V_237 . V_79 = F_92 ;
V_226 -> V_239 = F_59 ;
} else {
V_226 -> V_231 = & V_240 ;
V_226 -> V_233 = V_241 |
V_235 |
V_236 ;
V_226 -> V_242 . V_238 = F_103 ;
V_226 -> V_242 . V_243 = F_102 ;
V_226 -> V_242 . V_51 = F_106 ;
V_226 -> V_242 . V_79 = F_107 ;
V_226 -> V_242 . V_244 = F_108 ;
V_226 -> V_239 = F_60 ;
}
V_226 -> V_245 = sizeof( struct V_55 ) ;
V_226 -> V_246 = V_247 ;
V_226 -> V_248 = 3 ;
V_226 -> V_249 = 300 ;
V_226 -> V_250 = F_63 ;
if ( F_119 ( V_226 ) )
F_34 ( V_93 L_11 ,
V_226 -> V_230 ) ;
else
V_223 [ V_21 ] . V_251 = 1 ;
}
return 0 ;
}
static void T_7 F_120 ( void )
{
int V_222 = F_113 ( V_223 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_222 ; V_21 ++ ) {
if ( V_223 [ V_21 ] . V_251 )
F_121 ( & V_223 [ V_21 ] . V_10 ) ;
}
F_49 ( & V_17 -> V_16 ) ;
F_118 ( V_17 ) ;
}
