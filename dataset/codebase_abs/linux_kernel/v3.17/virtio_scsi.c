static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
if ( ! V_7 )
return;
if ( ! F_3 ( V_6 ) ) {
F_4 ( V_6 , V_7 ) ;
return;
}
F_5 ( V_6 ) -> V_7 = F_6 ( V_7 , F_5 ( V_6 ) -> V_8 ) ;
F_7 ( V_6 ) -> V_7 = V_7 - F_5 ( V_6 ) -> V_7 ;
}
static void F_8 ( struct V_9 * V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_14 * V_15 = & V_13 -> V_15 . V_13 ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
F_10 ( & V_6 -> V_18 -> V_20 ,
L_1 ,
V_6 , V_15 -> V_21 , V_15 -> V_22 , V_15 -> V_23 ) ;
V_6 -> V_24 = V_15 -> V_22 ;
F_2 ( V_6 , V_15 -> V_7 ) ;
switch ( V_15 -> V_21 ) {
case V_25 :
F_11 ( V_6 , V_26 ) ;
break;
case V_27 :
F_11 ( V_6 , V_28 ) ;
break;
case V_29 :
F_11 ( V_6 , V_30 ) ;
break;
case V_31 :
F_11 ( V_6 , V_32 ) ;
break;
case V_33 :
F_11 ( V_6 , V_34 ) ;
break;
case V_35 :
F_11 ( V_6 , V_36 ) ;
break;
case V_37 :
F_11 ( V_6 , V_38 ) ;
break;
case V_39 :
F_11 ( V_6 , V_40 ) ;
break;
case V_41 :
F_11 ( V_6 , V_42 ) ;
break;
default:
F_12 ( V_43 , V_6 , L_2 ,
V_15 -> V_21 ) ;
case V_44 :
F_11 ( V_6 , V_28 ) ;
break;
}
F_13 ( V_15 -> V_23 > V_45 ) ;
if ( V_6 -> V_46 ) {
memcpy ( V_6 -> V_46 , V_15 -> V_47 ,
F_14 ( T_1 , V_15 -> V_23 , V_45 ) ) ;
if ( V_15 -> V_23 )
F_15 ( V_6 , V_48 ) ;
}
V_6 -> V_49 ( V_6 ) ;
F_16 ( & V_17 -> V_50 ) ;
}
static void F_17 ( struct V_9 * V_10 ,
struct V_51 * V_52 ,
void (* F_18)( struct V_9 * V_10 , void * V_11 ) )
{
void * V_11 ;
unsigned int V_53 ;
unsigned long V_54 ;
struct V_55 * V_56 = V_52 -> V_56 ;
F_19 ( & V_52 -> V_57 , V_54 ) ;
do {
F_20 ( V_56 ) ;
while ( ( V_11 = F_21 ( V_56 , & V_53 ) ) != NULL )
F_18 ( V_10 , V_11 ) ;
if ( F_22 ( F_23 ( V_56 ) ) )
break;
} while ( ! F_24 ( V_56 ) );
F_25 ( & V_52 -> V_57 , V_54 ) ;
}
static void F_26 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
int V_59 = V_56 -> V_59 - V_60 ;
struct V_51 * V_61 = & V_10 -> V_62 [ V_59 ] ;
F_17 ( V_10 , V_61 , F_8 ) ;
}
static void F_28 ( struct V_9 * V_10 )
{
int V_63 , V_64 ;
V_64 = V_10 -> V_65 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
F_17 ( V_10 , & V_10 -> V_62 [ V_63 ] ,
F_8 ) ;
}
static void F_29 ( struct V_9 * V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
if ( V_13 -> V_66 )
F_30 ( V_13 -> V_66 ) ;
}
static void F_31 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_17 ( V_10 , & V_10 -> V_67 , F_29 ) ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_68 * V_69 )
{
int V_70 ;
struct V_71 V_72 ;
unsigned long V_54 ;
F_33 ( & V_69 -> V_73 , V_74 ) ;
F_34 ( & V_72 , & V_69 -> V_75 , sizeof( struct V_76 ) ) ;
F_19 ( & V_10 -> V_77 . V_57 , V_54 ) ;
V_70 = F_35 ( V_10 -> V_77 . V_56 , & V_72 , 1 , V_69 ,
V_78 ) ;
if ( ! V_70 )
F_36 ( V_10 -> V_77 . V_56 ) ;
F_25 ( & V_10 -> V_77 . V_57 , V_54 ) ;
return V_70 ;
}
static int F_37 ( struct V_9 * V_10 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_79 ; V_63 ++ ) {
V_10 -> V_80 [ V_63 ] . V_10 = V_10 ;
F_32 ( V_10 , & V_10 -> V_80 [ V_63 ] ) ;
}
return 0 ;
}
static void F_38 ( struct V_9 * V_10 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_79 ; V_63 ++ )
F_39 ( & V_10 -> V_80 [ V_63 ] . V_73 ) ;
}
static void F_40 ( struct V_9 * V_10 ,
struct V_76 * V_75 )
{
struct V_81 * V_82 ;
struct V_1 * V_83 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_84 = V_75 -> V_85 [ 1 ] ;
unsigned int V_85 = ( V_75 -> V_85 [ 2 ] << 8 ) | V_75 -> V_85 [ 3 ] ;
switch ( V_75 -> V_86 ) {
case V_87 :
F_41 ( V_83 , 0 , V_84 , V_85 ) ;
break;
case V_88 :
V_82 = F_42 ( V_83 , 0 , V_84 , V_85 ) ;
if ( V_82 ) {
F_43 ( V_82 ) ;
F_44 ( V_82 ) ;
} else {
F_45 ( L_3 ,
V_83 -> V_89 , V_84 , V_85 ) ;
}
break;
default:
F_46 ( L_4 , V_75 -> V_86 ) ;
}
}
static void F_47 ( struct V_9 * V_10 ,
struct V_76 * V_75 )
{
struct V_81 * V_82 ;
struct V_1 * V_83 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_84 = V_75 -> V_85 [ 1 ] ;
unsigned int V_85 = ( V_75 -> V_85 [ 2 ] << 8 ) | V_75 -> V_85 [ 3 ] ;
T_2 V_90 = V_75 -> V_86 & 255 ;
T_2 V_91 = V_75 -> V_86 >> 8 ;
V_82 = F_42 ( V_83 , 0 , V_84 , V_85 ) ;
if ( ! V_82 ) {
F_45 ( L_3 ,
V_83 -> V_89 , V_84 , V_85 ) ;
return;
}
if ( V_90 == 0x2a && ( V_91 == 0x00 || V_91 == 0x01 || V_91 == 0x09 ) )
F_48 ( & V_82 -> V_20 ) ;
F_44 ( V_82 ) ;
}
static void V_74 ( struct V_92 * V_73 )
{
struct V_68 * V_69 =
F_49 ( V_73 , struct V_68 , V_73 ) ;
struct V_9 * V_10 = V_69 -> V_10 ;
struct V_76 * V_75 = & V_69 -> V_75 ;
if ( V_75 -> V_75 & V_93 ) {
V_75 -> V_75 &= ~ V_93 ;
F_50 ( F_1 ( V_10 -> V_3 ) ) ;
}
switch ( V_75 -> V_75 ) {
case V_94 :
break;
case V_95 :
F_40 ( V_10 , V_75 ) ;
break;
case V_96 :
F_47 ( V_10 , V_75 ) ;
break;
default:
F_45 ( L_5 , V_75 -> V_75 ) ;
}
F_32 ( V_10 , V_69 ) ;
}
static void F_51 ( struct V_9 * V_10 , void * V_11 )
{
struct V_68 * V_69 = V_11 ;
F_52 ( & V_69 -> V_73 ) ;
}
static void F_53 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_17 ( V_10 , & V_10 -> V_77 , F_51 ) ;
}
static int F_54 ( struct V_55 * V_56 ,
struct V_12 * V_13 ,
T_3 V_97 , T_3 V_98 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_71 * V_99 [ 6 ] , V_100 , V_15 ;
struct V_101 * V_102 , * V_103 ;
unsigned V_104 = 0 , V_105 = 0 ;
V_102 = V_103 = NULL ;
if ( V_6 && V_6 -> V_106 != V_107 ) {
if ( V_6 -> V_106 != V_108 )
V_102 = & F_7 ( V_6 ) -> V_109 ;
if ( V_6 -> V_106 != V_110 )
V_103 = & F_5 ( V_6 ) -> V_109 ;
}
F_34 ( & V_100 , & V_13 -> V_100 , V_97 ) ;
V_99 [ V_104 ++ ] = & V_100 ;
if ( V_102 ) {
if ( F_55 ( V_6 ) )
V_99 [ V_104 ++ ] = F_56 ( V_6 ) ;
V_99 [ V_104 ++ ] = V_102 -> V_111 ;
}
F_34 ( & V_15 , & V_13 -> V_15 , V_98 ) ;
V_99 [ V_104 + V_105 ++ ] = & V_15 ;
if ( V_103 ) {
if ( F_55 ( V_6 ) )
V_99 [ V_104 + V_105 ++ ] = F_56 ( V_6 ) ;
V_99 [ V_104 + V_105 ++ ] = V_103 -> V_111 ;
}
return F_57 ( V_56 , V_99 , V_104 , V_105 , V_13 , V_78 ) ;
}
static int F_58 ( struct V_51 * V_56 ,
struct V_12 * V_13 ,
T_3 V_97 , T_3 V_98 )
{
unsigned long V_54 ;
int V_70 ;
bool V_112 = false ;
F_19 ( & V_56 -> V_57 , V_54 ) ;
V_70 = F_54 ( V_56 -> V_56 , V_13 , V_97 , V_98 ) ;
if ( ! V_70 )
V_112 = F_59 ( V_56 -> V_56 ) ;
F_25 ( & V_56 -> V_57 , V_54 ) ;
if ( V_112 )
F_60 ( V_56 -> V_56 ) ;
return V_70 ;
}
static void F_61 ( struct V_113 * V_13 ,
struct V_5 * V_6 )
{
V_13 -> V_85 [ 0 ] = 1 ;
V_13 -> V_85 [ 1 ] = V_6 -> V_18 -> V_114 ;
V_13 -> V_85 [ 2 ] = ( V_6 -> V_18 -> V_85 >> 8 ) | 0x40 ;
V_13 -> V_85 [ 3 ] = V_6 -> V_18 -> V_85 & 0xff ;
V_13 -> V_115 = ( unsigned long ) V_6 ;
V_13 -> V_116 = V_117 ;
V_13 -> V_118 = 0 ;
V_13 -> V_119 = 0 ;
}
static void F_62 ( struct V_120 * V_121 ,
struct V_5 * V_6 )
{
struct V_122 * V_123 = V_6 -> V_122 ;
struct V_124 * V_125 ;
F_61 ( (struct V_113 * ) V_121 , V_6 ) ;
if ( ! V_123 || ! F_55 ( V_6 ) )
return;
V_125 = F_63 ( V_123 -> V_126 ) ;
if ( V_6 -> V_106 == V_110 )
V_121 -> V_127 = F_64 ( V_123 ) * V_125 -> V_128 ;
else if ( V_6 -> V_106 == V_108 )
V_121 -> V_129 = F_64 ( V_123 ) * V_125 -> V_128 ;
}
static int F_65 ( struct V_9 * V_10 ,
struct V_51 * V_61 ,
struct V_5 * V_6 )
{
struct V_1 * V_83 = F_1 ( V_10 -> V_3 ) ;
struct V_12 * V_13 = F_66 ( V_6 ) ;
int V_97 ;
F_67 ( F_68 ( V_6 ) > V_83 -> V_130 ) ;
F_67 ( V_6 -> V_106 == V_131 ) ;
F_10 ( & V_6 -> V_18 -> V_20 ,
L_6 , V_6 , V_6 -> V_132 [ 0 ] ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
F_67 ( V_6 -> V_133 > V_134 ) ;
if ( F_69 ( V_10 -> V_3 , V_135 ) ) {
F_62 ( & V_13 -> V_100 . V_121 , V_6 ) ;
memcpy ( V_13 -> V_100 . V_121 . V_136 , V_6 -> V_132 , V_6 -> V_133 ) ;
V_97 = sizeof( V_13 -> V_100 . V_121 ) ;
} else {
F_61 ( & V_13 -> V_100 . V_13 , V_6 ) ;
memcpy ( V_13 -> V_100 . V_13 . V_136 , V_6 -> V_132 , V_6 -> V_133 ) ;
V_97 = sizeof( V_13 -> V_100 . V_13 ) ;
}
if ( F_58 ( V_61 , V_13 , V_97 , sizeof( V_13 -> V_15 . V_13 ) ) != 0 )
return V_137 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_58 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_58 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
F_71 ( & V_17 -> V_50 ) ;
return F_65 ( V_10 , & V_10 -> V_62 [ 0 ] , V_6 ) ;
}
static struct V_51 * F_72 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
struct V_51 * V_56 ;
unsigned long V_54 ;
T_1 V_138 ;
F_73 ( V_54 ) ;
if ( F_74 ( & V_17 -> V_50 ) > 1 ) {
unsigned long V_139 ;
do {
V_139 = F_75 ( & V_17 -> V_140 ) ;
V_56 = V_17 -> V_61 ;
} while ( F_76 ( & V_17 -> V_140 , V_139 ) );
} else {
F_77 ( & V_17 -> V_140 ) ;
if ( F_22 ( F_78 ( & V_17 -> V_50 ) > 1 ) ) {
V_56 = V_17 -> V_61 ;
goto V_141;
}
V_138 = F_79 () ;
while ( F_22 ( V_138 >= V_10 -> V_65 ) )
V_138 -= V_10 -> V_65 ;
V_17 -> V_61 = V_56 = & V_10 -> V_62 [ V_138 ] ;
V_141:
F_80 ( & V_17 -> V_140 ) ;
}
F_81 ( V_54 ) ;
return V_56 ;
}
static int F_82 ( struct V_1 * V_58 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_58 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
struct V_51 * V_61 = F_72 ( V_10 , V_17 ) ;
return F_65 ( V_10 , V_61 , V_6 ) ;
}
static int F_83 ( struct V_9 * V_10 , struct V_12 * V_13 )
{
F_84 ( V_66 ) ;
int V_142 = V_143 ;
V_13 -> V_66 = & V_66 ;
if ( F_58 ( & V_10 -> V_67 , V_13 ,
sizeof V_13 -> V_100 . V_144 , sizeof V_13 -> V_15 . V_144 ) < 0 )
goto V_102;
F_85 ( & V_66 ) ;
if ( V_13 -> V_15 . V_144 . V_21 == V_25 ||
V_13 -> V_15 . V_144 . V_21 == V_145 )
V_142 = V_146 ;
F_28 ( V_10 ) ;
V_102:
F_86 ( V_13 , V_147 ) ;
return V_142 ;
}
static int F_87 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_6 -> V_18 -> V_148 ) ;
struct V_12 * V_13 ;
F_88 ( V_149 , V_6 -> V_18 , L_7 ) ;
V_13 = F_89 ( V_147 , V_150 ) ;
if ( ! V_13 )
return V_143 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_100 . V_144 = (struct V_151 ) {
. type = V_152 ,
. V_153 = V_154 ,
. V_85 [ 0 ] = 1 ,
. V_85 [ 1 ] = V_6 -> V_18 -> V_114 ,
. V_85 [ 2 ] = ( V_6 -> V_18 -> V_85 >> 8 ) | 0x40 ,
. V_85 [ 3 ] = V_6 -> V_18 -> V_85 & 0xff ,
} ;
return F_83 ( V_10 , V_13 ) ;
}
static int F_90 ( struct V_81 * V_82 ,
int V_155 ,
int V_86 )
{
struct V_1 * V_83 = V_82 -> V_148 ;
int V_156 = V_83 -> V_157 ;
switch ( V_86 ) {
case V_158 :
F_91 ( V_82 , V_155 ) ;
break;
case V_159 :
case V_160 :
F_92 ( V_82 ,
F_93 ( V_82 ) ,
F_6 ( V_156 , V_155 ) ) ;
break;
default:
return - V_161 ;
}
return V_82 -> V_162 ;
}
static int F_94 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_6 -> V_18 -> V_148 ) ;
struct V_12 * V_13 ;
F_12 ( V_149 , V_6 , L_8 ) ;
V_13 = F_89 ( V_147 , V_150 ) ;
if ( ! V_13 )
return V_143 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_100 . V_144 = (struct V_151 ) {
. type = V_152 ,
. V_153 = V_163 ,
. V_85 [ 0 ] = 1 ,
. V_85 [ 1 ] = V_6 -> V_18 -> V_114 ,
. V_85 [ 2 ] = ( V_6 -> V_18 -> V_85 >> 8 ) | 0x40 ,
. V_85 [ 3 ] = V_6 -> V_18 -> V_85 & 0xff ,
. V_115 = ( unsigned long ) V_6 ,
} ;
return F_83 ( V_10 , V_13 ) ;
}
static int F_95 ( struct F_9 * V_164 )
{
struct V_1 * V_58 = F_96 ( V_164 -> V_165 . V_166 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
struct V_16 * V_17 =
F_97 ( sizeof( * V_17 ) , V_167 ) ;
if ( ! V_17 )
return - V_168 ;
F_98 ( & V_17 -> V_140 ) ;
F_99 ( & V_17 -> V_50 , 0 ) ;
V_17 -> V_61 = & V_10 -> V_62 [ 0 ] ;
V_164 -> V_19 = V_17 ;
return 0 ;
}
static void F_100 ( struct F_9 * V_164 )
{
struct V_16 * V_17 = V_164 -> V_19 ;
F_101 ( V_17 ) ;
}
static void F_102 ( struct V_9 * V_10 , bool V_169 )
{
int V_63 ;
int V_170 ;
if ( ( V_10 -> V_65 == 1 ||
V_10 -> V_65 != F_103 () ) && V_169 ) {
if ( V_10 -> V_171 )
V_169 = false ;
else
return;
}
if ( V_169 ) {
V_63 = 0 ;
F_104 (cpu) {
F_105 ( V_10 -> V_62 [ V_63 ] . V_56 , V_170 ) ;
V_63 ++ ;
}
V_10 -> V_171 = true ;
} else {
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( ! V_10 -> V_62 [ V_63 ] . V_56 )
continue;
F_105 ( V_10 -> V_62 [ V_63 ] . V_56 , - 1 ) ;
}
V_10 -> V_171 = false ;
}
}
static void F_106 ( struct V_9 * V_10 , bool V_169 )
{
F_107 () ;
F_102 ( V_10 , V_169 ) ;
F_108 () ;
}
static int F_109 ( struct V_172 * V_173 ,
unsigned long V_174 , void * V_175 )
{
struct V_9 * V_10 = F_49 ( V_173 , struct V_9 , V_176 ) ;
switch( V_174 ) {
case V_177 :
case V_178 :
case V_179 :
case V_180 :
F_102 ( V_10 , true ) ;
break;
default:
break;
}
return V_181 ;
}
static void F_110 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
F_111 ( & V_52 -> V_57 ) ;
V_52 -> V_56 = V_56 ;
}
static void F_112 ( struct V_2 * V_3 )
{
struct V_1 * V_83 = (struct V_1 * ) V_3 -> V_4 ;
F_50 ( V_83 ) ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_106 ( V_10 , false ) ;
V_3 -> V_182 -> V_183 ( V_3 ) ;
V_3 -> V_182 -> V_184 ( V_3 ) ;
}
static int F_114 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
int V_70 ;
T_1 V_63 ;
T_1 V_64 ;
T_4 * * V_185 ;
const char * * V_186 ;
struct V_55 * * V_187 ;
V_64 = V_10 -> V_65 + V_60 ;
V_187 = F_97 ( V_64 * sizeof( struct V_55 * ) , V_167 ) ;
V_185 = F_97 ( V_64 * sizeof( T_4 * ) , V_167 ) ;
V_186 = F_97 ( V_64 * sizeof( char * ) , V_167 ) ;
if ( ! V_185 || ! V_187 || ! V_186 ) {
V_70 = - V_168 ;
goto V_102;
}
V_185 [ 0 ] = F_31 ;
V_185 [ 1 ] = F_53 ;
V_186 [ 0 ] = L_9 ;
V_186 [ 1 ] = L_10 ;
for ( V_63 = V_60 ; V_63 < V_64 ; V_63 ++ ) {
V_185 [ V_63 ] = F_26 ;
V_186 [ V_63 ] = L_11 ;
}
V_70 = V_3 -> V_182 -> V_188 ( V_3 , V_64 , V_187 , V_185 , V_186 ) ;
if ( V_70 )
goto V_102;
F_110 ( & V_10 -> V_67 , V_187 [ 0 ] ) ;
F_110 ( & V_10 -> V_77 , V_187 [ 1 ] ) ;
for ( V_63 = V_60 ; V_63 < V_64 ; V_63 ++ )
F_110 ( & V_10 -> V_62 [ V_63 - V_60 ] ,
V_187 [ V_63 ] ) ;
F_106 ( V_10 , true ) ;
F_115 ( V_3 , V_189 , V_134 ) ;
F_115 ( V_3 , V_190 , V_45 ) ;
if ( F_69 ( V_3 , V_191 ) )
F_37 ( V_10 ) ;
V_70 = 0 ;
V_102:
F_101 ( V_186 ) ;
F_101 ( V_185 ) ;
F_101 ( V_187 ) ;
if ( V_70 )
F_113 ( V_3 ) ;
return V_70 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_83 ;
struct V_9 * V_10 ;
int V_70 , V_192 ;
T_1 V_193 , V_194 ;
T_1 V_157 ;
T_1 V_65 ;
struct V_195 * V_196 ;
V_65 = F_117 ( V_3 , V_65 ) ? : 1 ;
V_194 = F_117 ( V_3 , V_197 ) + 1 ;
if ( V_65 == 1 )
V_196 = & V_198 ;
else
V_196 = & V_199 ;
V_83 = F_118 ( V_196 ,
sizeof( * V_10 ) + sizeof( V_10 -> V_62 [ 0 ] ) * V_65 ) ;
if ( ! V_83 )
return - V_168 ;
V_193 = F_117 ( V_3 , V_200 ) ? : 1 ;
V_83 -> V_130 = V_193 ;
V_10 = F_27 ( V_83 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_65 = V_65 ;
V_3 -> V_4 = V_83 ;
V_70 = F_114 ( V_3 , V_10 ) ;
if ( V_70 )
goto V_201;
V_10 -> V_176 . V_202 = & F_109 ;
V_70 = F_119 ( & V_10 -> V_176 ) ;
if ( V_70 ) {
F_45 ( L_12 ) ;
goto V_203;
}
V_157 = F_117 ( V_3 , V_157 ) ? : 1 ;
V_83 -> V_157 = F_14 ( T_1 , V_157 , V_83 -> V_204 ) ;
V_83 -> V_205 = F_117 ( V_3 , V_205 ) ? : 0xFFFF ;
V_83 -> V_206 = F_117 ( V_3 , V_206 ) + 1 + 0x4000 ;
V_83 -> V_207 = V_194 ;
V_83 -> V_208 = 0 ;
V_83 -> V_209 = V_134 ;
if ( F_69 ( V_3 , V_135 ) ) {
V_192 = V_210 | V_211 |
V_212 | V_213 |
V_214 | V_215 ;
F_120 ( V_83 , V_192 ) ;
F_121 ( V_83 , V_216 ) ;
}
V_70 = F_122 ( V_83 , & V_3 -> V_165 ) ;
if ( V_70 )
goto V_203;
return 0 ;
V_203:
V_3 -> V_182 -> V_184 ( V_3 ) ;
V_201:
F_123 ( V_83 ) ;
return V_70 ;
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_1 * V_83 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_83 ) ;
if ( F_69 ( V_3 , V_191 ) )
F_38 ( V_10 ) ;
F_125 ( V_83 ) ;
F_126 ( & V_10 -> V_176 ) ;
F_113 ( V_3 ) ;
F_123 ( V_83 ) ;
}
static int F_127 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_126 ( & V_10 -> V_176 ) ;
F_113 ( V_3 ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
int V_70 ;
V_70 = F_114 ( V_3 , V_10 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_119 ( & V_10 -> V_176 ) ;
if ( V_70 )
V_3 -> V_182 -> V_184 ( V_3 ) ;
return V_70 ;
}
static int T_5 F_129 ( void )
{
int V_142 = - V_168 ;
V_217 = F_130 ( V_12 , 0 ) ;
if ( ! V_217 ) {
F_45 ( L_13 ) ;
goto error;
}
V_147 =
F_131 ( V_218 ,
V_217 ) ;
if ( ! V_147 ) {
F_45 ( L_14 ) ;
goto error;
}
V_142 = F_132 ( & V_219 ) ;
if ( V_142 < 0 )
goto error;
return 0 ;
error:
if ( V_147 ) {
F_133 ( V_147 ) ;
V_147 = NULL ;
}
if ( V_217 ) {
F_134 ( V_217 ) ;
V_217 = NULL ;
}
return V_142 ;
}
static void T_6 F_135 ( void )
{
F_136 ( & V_219 ) ;
F_133 ( V_147 ) ;
F_134 ( V_217 ) ;
}
