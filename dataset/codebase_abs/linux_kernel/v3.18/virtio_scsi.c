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
F_39 ( & V_10 -> V_77 . V_57 ) ;
V_10 -> V_81 = true ;
F_40 ( & V_10 -> V_77 . V_57 ) ;
for ( V_63 = 0 ; V_63 < V_79 ; V_63 ++ )
F_41 ( & V_10 -> V_80 [ V_63 ] . V_73 ) ;
}
static void F_42 ( struct V_9 * V_10 ,
struct V_76 * V_75 )
{
struct V_82 * V_83 ;
struct V_1 * V_84 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_85 = V_75 -> V_86 [ 1 ] ;
unsigned int V_86 = ( V_75 -> V_86 [ 2 ] << 8 ) | V_75 -> V_86 [ 3 ] ;
switch ( V_75 -> V_87 ) {
case V_88 :
F_43 ( V_84 , 0 , V_85 , V_86 ) ;
break;
case V_89 :
V_83 = F_44 ( V_84 , 0 , V_85 , V_86 ) ;
if ( V_83 ) {
F_45 ( V_83 ) ;
F_46 ( V_83 ) ;
} else {
F_47 ( L_3 ,
V_84 -> V_90 , V_85 , V_86 ) ;
}
break;
default:
F_48 ( L_4 , V_75 -> V_87 ) ;
}
}
static void F_49 ( struct V_9 * V_10 ,
struct V_76 * V_75 )
{
struct V_82 * V_83 ;
struct V_1 * V_84 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_85 = V_75 -> V_86 [ 1 ] ;
unsigned int V_86 = ( V_75 -> V_86 [ 2 ] << 8 ) | V_75 -> V_86 [ 3 ] ;
T_2 V_91 = V_75 -> V_87 & 255 ;
T_2 V_92 = V_75 -> V_87 >> 8 ;
V_83 = F_44 ( V_84 , 0 , V_85 , V_86 ) ;
if ( ! V_83 ) {
F_47 ( L_3 ,
V_84 -> V_90 , V_85 , V_86 ) ;
return;
}
if ( V_91 == 0x2a && ( V_92 == 0x00 || V_92 == 0x01 || V_92 == 0x09 ) )
F_50 ( & V_83 -> V_20 ) ;
F_46 ( V_83 ) ;
}
static void V_74 ( struct V_93 * V_73 )
{
struct V_68 * V_69 =
F_51 ( V_73 , struct V_68 , V_73 ) ;
struct V_9 * V_10 = V_69 -> V_10 ;
struct V_76 * V_75 = & V_69 -> V_75 ;
if ( V_75 -> V_75 & V_94 ) {
V_75 -> V_75 &= ~ V_94 ;
F_52 ( F_1 ( V_10 -> V_3 ) ) ;
}
switch ( V_75 -> V_75 ) {
case V_95 :
break;
case V_96 :
F_42 ( V_10 , V_75 ) ;
break;
case V_97 :
F_49 ( V_10 , V_75 ) ;
break;
default:
F_47 ( L_5 , V_75 -> V_75 ) ;
}
F_32 ( V_10 , V_69 ) ;
}
static void F_53 ( struct V_9 * V_10 , void * V_11 )
{
struct V_68 * V_69 = V_11 ;
if ( ! V_10 -> V_81 )
F_54 ( V_98 , & V_69 -> V_73 ) ;
}
static void F_55 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_17 ( V_10 , & V_10 -> V_77 , F_53 ) ;
}
static int F_56 ( struct V_55 * V_56 ,
struct V_12 * V_13 ,
T_3 V_99 , T_3 V_100 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_71 * V_101 [ 6 ] , V_102 , V_15 ;
struct V_103 * V_104 , * V_105 ;
unsigned V_106 = 0 , V_107 = 0 ;
V_104 = V_105 = NULL ;
if ( V_6 && V_6 -> V_108 != V_109 ) {
if ( V_6 -> V_108 != V_110 )
V_104 = & F_7 ( V_6 ) -> V_111 ;
if ( V_6 -> V_108 != V_112 )
V_105 = & F_5 ( V_6 ) -> V_111 ;
}
F_34 ( & V_102 , & V_13 -> V_102 , V_99 ) ;
V_101 [ V_106 ++ ] = & V_102 ;
if ( V_104 ) {
if ( F_57 ( V_6 ) )
V_101 [ V_106 ++ ] = F_58 ( V_6 ) ;
V_101 [ V_106 ++ ] = V_104 -> V_113 ;
}
F_34 ( & V_15 , & V_13 -> V_15 , V_100 ) ;
V_101 [ V_106 + V_107 ++ ] = & V_15 ;
if ( V_105 ) {
if ( F_57 ( V_6 ) )
V_101 [ V_106 + V_107 ++ ] = F_58 ( V_6 ) ;
V_101 [ V_106 + V_107 ++ ] = V_105 -> V_113 ;
}
return F_59 ( V_56 , V_101 , V_106 , V_107 , V_13 , V_78 ) ;
}
static int F_60 ( struct V_51 * V_56 ,
struct V_12 * V_13 ,
T_3 V_99 , T_3 V_100 )
{
unsigned long V_54 ;
int V_70 ;
bool V_114 = false ;
F_19 ( & V_56 -> V_57 , V_54 ) ;
V_70 = F_56 ( V_56 -> V_56 , V_13 , V_99 , V_100 ) ;
if ( ! V_70 )
V_114 = F_61 ( V_56 -> V_56 ) ;
F_25 ( & V_56 -> V_57 , V_54 ) ;
if ( V_114 )
F_62 ( V_56 -> V_56 ) ;
return V_70 ;
}
static void F_63 ( struct V_115 * V_13 ,
struct V_5 * V_6 )
{
V_13 -> V_86 [ 0 ] = 1 ;
V_13 -> V_86 [ 1 ] = V_6 -> V_18 -> V_116 ;
V_13 -> V_86 [ 2 ] = ( V_6 -> V_18 -> V_86 >> 8 ) | 0x40 ;
V_13 -> V_86 [ 3 ] = V_6 -> V_18 -> V_86 & 0xff ;
V_13 -> V_117 = ( unsigned long ) V_6 ;
V_13 -> V_118 = V_119 ;
V_13 -> V_120 = 0 ;
V_13 -> V_121 = 0 ;
}
static void F_64 ( struct V_122 * V_123 ,
struct V_5 * V_6 )
{
struct V_124 * V_125 = V_6 -> V_124 ;
struct V_126 * V_127 ;
F_63 ( (struct V_115 * ) V_123 , V_6 ) ;
if ( ! V_125 || ! F_57 ( V_6 ) )
return;
V_127 = F_65 ( V_125 -> V_128 ) ;
if ( V_6 -> V_108 == V_112 )
V_123 -> V_129 = F_66 ( V_125 ) * V_127 -> V_130 ;
else if ( V_6 -> V_108 == V_110 )
V_123 -> V_131 = F_66 ( V_125 ) * V_127 -> V_130 ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_51 * V_61 ,
struct V_5 * V_6 )
{
struct V_1 * V_84 = F_1 ( V_10 -> V_3 ) ;
struct V_12 * V_13 = F_68 ( V_6 ) ;
int V_99 ;
F_69 ( F_70 ( V_6 ) > V_84 -> V_132 ) ;
F_69 ( V_6 -> V_108 == V_133 ) ;
F_10 ( & V_6 -> V_18 -> V_20 ,
L_6 , V_6 , V_6 -> V_134 [ 0 ] ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
F_69 ( V_6 -> V_135 > V_136 ) ;
if ( F_71 ( V_10 -> V_3 , V_137 ) ) {
F_64 ( & V_13 -> V_102 . V_123 , V_6 ) ;
memcpy ( V_13 -> V_102 . V_123 . V_138 , V_6 -> V_134 , V_6 -> V_135 ) ;
V_99 = sizeof( V_13 -> V_102 . V_123 ) ;
} else {
F_63 ( & V_13 -> V_102 . V_13 , V_6 ) ;
memcpy ( V_13 -> V_102 . V_13 . V_138 , V_6 -> V_134 , V_6 -> V_135 ) ;
V_99 = sizeof( V_13 -> V_102 . V_13 ) ;
}
if ( F_60 ( V_61 , V_13 , V_99 , sizeof( V_13 -> V_15 . V_13 ) ) != 0 )
return V_139 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_58 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_58 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
F_73 ( & V_17 -> V_50 ) ;
return F_67 ( V_10 , & V_10 -> V_62 [ 0 ] , V_6 ) ;
}
static struct V_51 * F_74 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
struct V_51 * V_56 ;
unsigned long V_54 ;
T_1 V_140 ;
F_75 ( V_54 ) ;
if ( F_76 ( & V_17 -> V_50 ) > 1 ) {
unsigned long V_141 ;
do {
V_141 = F_77 ( & V_17 -> V_142 ) ;
V_56 = V_17 -> V_61 ;
} while ( F_78 ( & V_17 -> V_142 , V_141 ) );
} else {
F_79 ( & V_17 -> V_142 ) ;
if ( F_22 ( F_80 ( & V_17 -> V_50 ) > 1 ) ) {
V_56 = V_17 -> V_61 ;
goto V_143;
}
V_140 = F_81 () ;
while ( F_22 ( V_140 >= V_10 -> V_65 ) )
V_140 -= V_10 -> V_65 ;
V_17 -> V_61 = V_56 = & V_10 -> V_62 [ V_140 ] ;
V_143:
F_82 ( & V_17 -> V_142 ) ;
}
F_83 ( V_54 ) ;
return V_56 ;
}
static int F_84 ( struct V_1 * V_58 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_58 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
struct V_51 * V_61 = F_74 ( V_10 , V_17 ) ;
return F_67 ( V_10 , V_61 , V_6 ) ;
}
static int F_85 ( struct V_9 * V_10 , struct V_12 * V_13 )
{
F_86 ( V_66 ) ;
int V_144 = V_145 ;
V_13 -> V_66 = & V_66 ;
if ( F_60 ( & V_10 -> V_67 , V_13 ,
sizeof V_13 -> V_102 . V_146 , sizeof V_13 -> V_15 . V_146 ) < 0 )
goto V_104;
F_87 ( & V_66 ) ;
if ( V_13 -> V_15 . V_146 . V_21 == V_25 ||
V_13 -> V_15 . V_146 . V_21 == V_147 )
V_144 = V_148 ;
F_28 ( V_10 ) ;
V_104:
F_88 ( V_13 , V_149 ) ;
return V_144 ;
}
static int F_89 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_6 -> V_18 -> V_150 ) ;
struct V_12 * V_13 ;
F_90 ( V_151 , V_6 -> V_18 , L_7 ) ;
V_13 = F_91 ( V_149 , V_152 ) ;
if ( ! V_13 )
return V_145 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_102 . V_146 = (struct V_153 ) {
. type = V_154 ,
. V_155 = V_156 ,
. V_86 [ 0 ] = 1 ,
. V_86 [ 1 ] = V_6 -> V_18 -> V_116 ,
. V_86 [ 2 ] = ( V_6 -> V_18 -> V_86 >> 8 ) | 0x40 ,
. V_86 [ 3 ] = V_6 -> V_18 -> V_86 & 0xff ,
} ;
return F_85 ( V_10 , V_13 ) ;
}
static int F_92 ( struct V_82 * V_83 ,
int V_157 ,
int V_87 )
{
struct V_1 * V_84 = V_83 -> V_150 ;
int V_158 = V_84 -> V_159 ;
switch ( V_87 ) {
case V_160 :
F_93 ( V_83 , V_157 ) ;
break;
case V_161 :
case V_162 :
F_94 ( V_83 ,
F_95 ( V_83 ) ,
F_6 ( V_158 , V_157 ) ) ;
break;
default:
return - V_163 ;
}
return V_83 -> V_164 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_27 ( V_6 -> V_18 -> V_150 ) ;
struct V_12 * V_13 ;
F_12 ( V_151 , V_6 , L_8 ) ;
V_13 = F_91 ( V_149 , V_152 ) ;
if ( ! V_13 )
return V_145 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_102 . V_146 = (struct V_153 ) {
. type = V_154 ,
. V_155 = V_165 ,
. V_86 [ 0 ] = 1 ,
. V_86 [ 1 ] = V_6 -> V_18 -> V_116 ,
. V_86 [ 2 ] = ( V_6 -> V_18 -> V_86 >> 8 ) | 0x40 ,
. V_86 [ 3 ] = V_6 -> V_18 -> V_86 & 0xff ,
. V_117 = ( unsigned long ) V_6 ,
} ;
return F_85 ( V_10 , V_13 ) ;
}
static int F_97 ( struct F_9 * V_166 )
{
struct V_1 * V_58 = F_98 ( V_166 -> V_167 . V_168 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
struct V_16 * V_17 =
F_99 ( sizeof( * V_17 ) , V_169 ) ;
if ( ! V_17 )
return - V_170 ;
F_100 ( & V_17 -> V_142 ) ;
F_101 ( & V_17 -> V_50 , 0 ) ;
V_17 -> V_61 = & V_10 -> V_62 [ 0 ] ;
V_166 -> V_19 = V_17 ;
return 0 ;
}
static void F_102 ( struct F_9 * V_166 )
{
struct V_16 * V_17 = V_166 -> V_19 ;
F_103 ( V_17 ) ;
}
static void F_104 ( struct V_9 * V_10 , bool V_171 )
{
int V_63 ;
int V_172 ;
if ( ( V_10 -> V_65 == 1 ||
V_10 -> V_65 != F_105 () ) && V_171 ) {
if ( V_10 -> V_173 )
V_171 = false ;
else
return;
}
if ( V_171 ) {
V_63 = 0 ;
F_106 (cpu) {
F_107 ( V_10 -> V_62 [ V_63 ] . V_56 , V_172 ) ;
V_63 ++ ;
}
V_10 -> V_173 = true ;
} else {
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( ! V_10 -> V_62 [ V_63 ] . V_56 )
continue;
F_107 ( V_10 -> V_62 [ V_63 ] . V_56 , - 1 ) ;
}
V_10 -> V_173 = false ;
}
}
static void F_108 ( struct V_9 * V_10 , bool V_171 )
{
F_109 () ;
F_104 ( V_10 , V_171 ) ;
F_110 () ;
}
static int F_111 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_177 )
{
struct V_9 * V_10 = F_51 ( V_175 , struct V_9 , V_178 ) ;
switch( V_176 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
F_104 ( V_10 , true ) ;
break;
default:
break;
}
return V_183 ;
}
static void F_112 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
F_113 ( & V_52 -> V_57 ) ;
V_52 -> V_56 = V_56 ;
}
static void F_114 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_108 ( V_10 , false ) ;
V_3 -> V_184 -> V_185 ( V_3 ) ;
V_3 -> V_184 -> V_186 ( V_3 ) ;
}
static int F_115 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
int V_70 ;
T_1 V_63 ;
T_1 V_64 ;
T_4 * * V_187 ;
const char * * V_188 ;
struct V_55 * * V_189 ;
V_64 = V_10 -> V_65 + V_60 ;
V_189 = F_99 ( V_64 * sizeof( struct V_55 * ) , V_169 ) ;
V_187 = F_99 ( V_64 * sizeof( T_4 * ) , V_169 ) ;
V_188 = F_99 ( V_64 * sizeof( char * ) , V_169 ) ;
if ( ! V_187 || ! V_189 || ! V_188 ) {
V_70 = - V_170 ;
goto V_104;
}
V_187 [ 0 ] = F_31 ;
V_187 [ 1 ] = F_55 ;
V_188 [ 0 ] = L_9 ;
V_188 [ 1 ] = L_10 ;
for ( V_63 = V_60 ; V_63 < V_64 ; V_63 ++ ) {
V_187 [ V_63 ] = F_26 ;
V_188 [ V_63 ] = L_11 ;
}
V_70 = V_3 -> V_184 -> V_190 ( V_3 , V_64 , V_189 , V_187 , V_188 ) ;
if ( V_70 )
goto V_104;
F_112 ( & V_10 -> V_67 , V_189 [ 0 ] ) ;
F_112 ( & V_10 -> V_77 , V_189 [ 1 ] ) ;
for ( V_63 = V_60 ; V_63 < V_64 ; V_63 ++ )
F_112 ( & V_10 -> V_62 [ V_63 - V_60 ] ,
V_189 [ V_63 ] ) ;
F_108 ( V_10 , true ) ;
F_116 ( V_3 , V_191 , V_136 ) ;
F_116 ( V_3 , V_192 , V_45 ) ;
V_70 = 0 ;
V_104:
F_103 ( V_188 ) ;
F_103 ( V_187 ) ;
F_103 ( V_189 ) ;
if ( V_70 )
F_114 ( V_3 ) ;
return V_70 ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_1 * V_84 ;
struct V_9 * V_10 ;
int V_70 , V_193 ;
T_1 V_194 , V_195 ;
T_1 V_159 ;
T_1 V_65 ;
struct V_196 * V_197 ;
V_65 = F_118 ( V_3 , V_65 ) ? : 1 ;
V_195 = F_118 ( V_3 , V_198 ) + 1 ;
if ( V_65 == 1 )
V_197 = & V_199 ;
else
V_197 = & V_200 ;
V_84 = F_119 ( V_197 ,
sizeof( * V_10 ) + sizeof( V_10 -> V_62 [ 0 ] ) * V_65 ) ;
if ( ! V_84 )
return - V_170 ;
V_194 = F_118 ( V_3 , V_201 ) ? : 1 ;
V_84 -> V_132 = V_194 ;
V_10 = F_27 ( V_84 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_65 = V_65 ;
V_3 -> V_4 = V_84 ;
V_70 = F_115 ( V_3 , V_10 ) ;
if ( V_70 )
goto V_202;
V_10 -> V_178 . V_203 = & F_111 ;
V_70 = F_120 ( & V_10 -> V_178 ) ;
if ( V_70 ) {
F_47 ( L_12 ) ;
goto V_204;
}
V_159 = F_118 ( V_3 , V_159 ) ? : 1 ;
V_84 -> V_159 = F_14 ( T_1 , V_159 , V_84 -> V_205 ) ;
V_84 -> V_206 = F_118 ( V_3 , V_206 ) ? : 0xFFFF ;
V_84 -> V_207 = F_118 ( V_3 , V_207 ) + 1 + 0x4000 ;
V_84 -> V_208 = V_195 ;
V_84 -> V_209 = 0 ;
V_84 -> V_210 = V_136 ;
if ( F_71 ( V_3 , V_137 ) ) {
V_193 = V_211 | V_212 |
V_213 | V_214 |
V_215 | V_216 ;
F_121 ( V_84 , V_193 ) ;
F_122 ( V_84 , V_217 ) ;
}
V_70 = F_123 ( V_84 , & V_3 -> V_167 ) ;
if ( V_70 )
goto V_204;
F_124 ( V_3 ) ;
if ( F_71 ( V_3 , V_218 ) )
F_37 ( V_10 ) ;
F_52 ( V_84 ) ;
return 0 ;
V_204:
V_3 -> V_184 -> V_186 ( V_3 ) ;
V_202:
F_125 ( V_84 ) ;
return V_70 ;
}
static void F_126 ( struct V_2 * V_3 )
{
struct V_1 * V_84 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_84 ) ;
if ( F_71 ( V_3 , V_218 ) )
F_38 ( V_10 ) ;
F_127 ( V_84 ) ;
F_128 ( & V_10 -> V_178 ) ;
F_114 ( V_3 ) ;
F_125 ( V_84 ) ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
F_128 ( & V_10 -> V_178 ) ;
F_114 ( V_3 ) ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_27 ( V_58 ) ;
int V_70 ;
V_70 = F_115 ( V_3 , V_10 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_120 ( & V_10 -> V_178 ) ;
if ( V_70 ) {
V_3 -> V_184 -> V_186 ( V_3 ) ;
return V_70 ;
}
F_124 ( V_3 ) ;
if ( F_71 ( V_3 , V_218 ) )
F_37 ( V_10 ) ;
return V_70 ;
}
static int T_5 F_131 ( void )
{
int V_144 = - V_170 ;
V_219 = F_132 ( V_12 , 0 ) ;
if ( ! V_219 ) {
F_47 ( L_13 ) ;
goto error;
}
V_149 =
F_133 ( V_220 ,
V_219 ) ;
if ( ! V_149 ) {
F_47 ( L_14 ) ;
goto error;
}
V_144 = F_134 ( & V_221 ) ;
if ( V_144 < 0 )
goto error;
return 0 ;
error:
if ( V_149 ) {
F_135 ( V_149 ) ;
V_149 = NULL ;
}
if ( V_219 ) {
F_136 ( V_219 ) ;
V_219 = NULL ;
}
return V_144 ;
}
static void T_6 F_137 ( void )
{
F_138 ( & V_221 ) ;
F_135 ( V_149 ) ;
F_136 ( V_219 ) ;
}
