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
F_16 ( V_13 , V_49 ) ;
V_6 -> V_50 ( V_6 ) ;
F_17 ( & V_17 -> V_51 ) ;
}
static void F_18 ( struct V_9 * V_10 ,
struct V_52 * V_53 ,
void (* F_19)( struct V_9 * V_10 , void * V_11 ) )
{
void * V_11 ;
unsigned int V_54 ;
unsigned long V_55 ;
struct V_56 * V_57 = V_53 -> V_57 ;
F_20 ( & V_53 -> V_58 , V_55 ) ;
do {
F_21 ( V_57 ) ;
while ( ( V_11 = F_22 ( V_57 , & V_54 ) ) != NULL )
F_19 ( V_10 , V_11 ) ;
} while ( ! F_23 ( V_57 ) );
F_24 ( & V_53 -> V_58 , V_55 ) ;
}
static void F_25 ( struct V_56 * V_57 )
{
struct V_1 * V_59 = F_1 ( V_57 -> V_3 ) ;
struct V_9 * V_10 = F_26 ( V_59 ) ;
int V_60 = V_57 -> V_60 - V_61 ;
struct V_52 * V_62 = & V_10 -> V_63 [ V_60 ] ;
F_27 () ;
F_18 ( V_10 , V_62 , F_8 ) ;
}
static void F_28 ( struct V_9 * V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
if ( V_13 -> V_64 )
F_29 ( V_13 -> V_64 ) ;
else
F_16 ( V_13 , V_49 ) ;
}
static void F_30 ( struct V_56 * V_57 )
{
struct V_1 * V_59 = F_1 ( V_57 -> V_3 ) ;
struct V_9 * V_10 = F_26 ( V_59 ) ;
F_18 ( V_10 , & V_10 -> V_65 , F_28 ) ;
}
static int F_31 ( struct V_9 * V_10 ,
struct V_66 * V_67 )
{
int V_68 ;
struct V_69 V_70 ;
unsigned long V_55 ;
F_32 ( & V_70 , & V_67 -> V_71 , sizeof( struct V_72 ) ) ;
F_20 ( & V_10 -> V_73 . V_58 , V_55 ) ;
V_68 = F_33 ( V_10 -> V_73 . V_57 , & V_70 , 1 , V_67 ,
V_74 ) ;
if ( ! V_68 )
F_34 ( V_10 -> V_73 . V_57 ) ;
F_24 ( & V_10 -> V_73 . V_58 , V_55 ) ;
return V_68 ;
}
static int F_35 ( struct V_9 * V_10 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
V_10 -> V_77 [ V_75 ] . V_10 = V_10 ;
F_31 ( V_10 , & V_10 -> V_77 [ V_75 ] ) ;
}
return 0 ;
}
static void F_36 ( struct V_9 * V_10 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
F_37 ( & V_10 -> V_77 [ V_75 ] . V_78 ) ;
}
static void F_38 ( struct V_9 * V_10 ,
struct V_72 * V_71 )
{
struct V_79 * V_80 ;
struct V_1 * V_81 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_82 = V_71 -> V_83 [ 1 ] ;
unsigned int V_83 = ( V_71 -> V_83 [ 2 ] << 8 ) | V_71 -> V_83 [ 3 ] ;
switch ( V_71 -> V_84 ) {
case V_85 :
F_39 ( V_81 , 0 , V_82 , V_83 ) ;
break;
case V_86 :
V_80 = F_40 ( V_81 , 0 , V_82 , V_83 ) ;
if ( V_80 ) {
F_41 ( V_80 ) ;
F_42 ( V_80 ) ;
} else {
F_43 ( L_3 ,
V_81 -> V_87 , V_82 , V_83 ) ;
}
break;
default:
F_44 ( L_4 , V_71 -> V_84 ) ;
}
}
static void F_45 ( struct V_9 * V_10 ,
struct V_72 * V_71 )
{
struct V_79 * V_80 ;
struct V_1 * V_81 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_82 = V_71 -> V_83 [ 1 ] ;
unsigned int V_83 = ( V_71 -> V_83 [ 2 ] << 8 ) | V_71 -> V_83 [ 3 ] ;
T_2 V_88 = V_71 -> V_84 & 255 ;
T_2 V_89 = V_71 -> V_84 >> 8 ;
V_80 = F_40 ( V_81 , 0 , V_82 , V_83 ) ;
if ( ! V_80 ) {
F_43 ( L_3 ,
V_81 -> V_87 , V_82 , V_83 ) ;
return;
}
if ( V_88 == 0x2a && ( V_89 == 0x00 || V_89 == 0x01 || V_89 == 0x09 ) )
F_46 ( & V_80 -> V_20 ) ;
F_42 ( V_80 ) ;
}
static void F_47 ( struct V_90 * V_78 )
{
struct V_66 * V_67 =
F_48 ( V_78 , struct V_66 , V_78 ) ;
struct V_9 * V_10 = V_67 -> V_10 ;
struct V_72 * V_71 = & V_67 -> V_71 ;
if ( V_71 -> V_71 & V_91 ) {
V_71 -> V_71 &= ~ V_91 ;
F_49 ( F_1 ( V_10 -> V_3 ) ) ;
}
switch ( V_71 -> V_71 ) {
case V_92 :
break;
case V_93 :
F_38 ( V_10 , V_71 ) ;
break;
case V_94 :
F_45 ( V_10 , V_71 ) ;
break;
default:
F_43 ( L_5 , V_71 -> V_71 ) ;
}
F_31 ( V_10 , V_67 ) ;
}
static void F_50 ( struct V_9 * V_10 , void * V_11 )
{
struct V_66 * V_67 = V_11 ;
F_51 ( & V_67 -> V_78 , F_47 ) ;
F_52 ( & V_67 -> V_78 ) ;
}
static void F_53 ( struct V_56 * V_57 )
{
struct V_1 * V_59 = F_1 ( V_57 -> V_3 ) ;
struct V_9 * V_10 = F_26 ( V_59 ) ;
F_18 ( V_10 , & V_10 -> V_73 , F_50 ) ;
}
static int F_54 ( struct V_56 * V_57 ,
struct V_12 * V_13 ,
T_3 V_95 , T_3 V_96 , T_4 V_97 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_69 * V_98 [ 4 ] , V_99 , V_15 ;
struct V_100 * V_101 , * V_102 ;
unsigned V_103 = 0 , V_104 = 0 ;
V_101 = V_102 = NULL ;
if ( V_6 && V_6 -> V_105 != V_106 ) {
if ( V_6 -> V_105 != V_107 )
V_101 = & F_7 ( V_6 ) -> V_108 ;
if ( V_6 -> V_105 != V_109 )
V_102 = & F_5 ( V_6 ) -> V_108 ;
}
F_32 ( & V_99 , & V_13 -> V_99 , V_95 ) ;
V_98 [ V_103 ++ ] = & V_99 ;
if ( V_101 )
V_98 [ V_103 ++ ] = V_101 -> V_110 ;
F_32 ( & V_15 , & V_13 -> V_15 , V_96 ) ;
V_98 [ V_103 + V_104 ++ ] = & V_15 ;
if ( V_102 )
V_98 [ V_103 + V_104 ++ ] = V_102 -> V_110 ;
return F_55 ( V_57 , V_98 , V_103 , V_104 , V_13 , V_97 ) ;
}
static int F_56 ( struct V_52 * V_57 ,
struct V_12 * V_13 ,
T_3 V_95 , T_3 V_96 , T_4 V_97 )
{
unsigned long V_55 ;
int V_68 ;
bool V_111 = false ;
F_20 ( & V_57 -> V_58 , V_55 ) ;
V_68 = F_54 ( V_57 -> V_57 , V_13 , V_95 , V_96 , V_97 ) ;
if ( ! V_68 )
V_111 = F_57 ( V_57 -> V_57 ) ;
F_24 ( & V_57 -> V_58 , V_55 ) ;
if ( V_111 )
F_58 ( V_57 -> V_57 ) ;
return V_68 ;
}
static int F_59 ( struct V_9 * V_10 ,
struct V_52 * V_62 ,
struct V_5 * V_6 )
{
struct V_12 * V_13 ;
int V_112 ;
struct V_1 * V_81 = F_1 ( V_10 -> V_3 ) ;
F_60 ( F_61 ( V_6 ) > V_81 -> V_113 ) ;
F_60 ( V_6 -> V_105 == V_114 ) ;
F_10 ( & V_6 -> V_18 -> V_20 ,
L_6 , V_6 , V_6 -> V_115 [ 0 ] ) ;
V_112 = V_116 ;
V_13 = F_62 ( V_49 , V_74 ) ;
if ( ! V_13 )
goto V_101;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_99 . V_13 = (struct V_117 ) {
. V_83 [ 0 ] = 1 ,
. V_83 [ 1 ] = V_6 -> V_18 -> V_118 ,
. V_83 [ 2 ] = ( V_6 -> V_18 -> V_83 >> 8 ) | 0x40 ,
. V_83 [ 3 ] = V_6 -> V_18 -> V_83 & 0xff ,
. V_119 = ( unsigned long ) V_6 ,
. V_120 = V_121 ,
. V_122 = 0 ,
. V_123 = 0 ,
} ;
F_60 ( V_6 -> V_124 > V_125 ) ;
memcpy ( V_13 -> V_99 . V_13 . V_126 , V_6 -> V_115 , V_6 -> V_124 ) ;
if ( F_56 ( V_62 , V_13 ,
sizeof V_13 -> V_99 . V_13 , sizeof V_13 -> V_15 . V_13 ,
V_74 ) == 0 )
V_112 = 0 ;
else
F_16 ( V_13 , V_49 ) ;
V_101:
return V_112 ;
}
static int F_63 ( struct V_1 * V_59 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
F_64 ( & V_17 -> V_51 ) ;
return F_59 ( V_10 , & V_10 -> V_63 [ 0 ] , V_6 ) ;
}
static struct V_52 * F_65 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
struct V_52 * V_57 ;
unsigned long V_55 ;
T_1 V_127 ;
F_20 ( & V_17 -> V_128 , V_55 ) ;
if ( F_66 ( & V_17 -> V_51 ) > 1 )
V_57 = F_67 ( V_17 -> V_62 ) ;
else {
V_127 = F_68 () ;
while ( F_69 ( V_127 >= V_10 -> V_129 ) )
V_127 -= V_10 -> V_129 ;
V_17 -> V_62 = V_57 = & V_10 -> V_63 [ V_127 ] ;
}
F_24 ( & V_17 -> V_128 , V_55 ) ;
return V_57 ;
}
static int F_70 ( struct V_1 * V_59 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_26 ( V_59 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
struct V_52 * V_62 = F_65 ( V_10 , V_17 ) ;
return F_59 ( V_10 , V_62 , V_6 ) ;
}
static int F_71 ( struct V_9 * V_10 , struct V_12 * V_13 )
{
F_72 ( V_64 ) ;
int V_112 = V_130 ;
V_13 -> V_64 = & V_64 ;
if ( F_56 ( & V_10 -> V_65 , V_13 ,
sizeof V_13 -> V_99 . V_131 , sizeof V_13 -> V_15 . V_131 ,
V_132 ) < 0 )
goto V_101;
F_73 ( & V_64 ) ;
if ( V_13 -> V_15 . V_131 . V_21 == V_25 ||
V_13 -> V_15 . V_131 . V_21 == V_133 )
V_112 = V_134 ;
V_101:
F_16 ( V_13 , V_49 ) ;
return V_112 ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_26 ( V_6 -> V_18 -> V_135 ) ;
struct V_12 * V_13 ;
F_75 ( V_136 , V_6 -> V_18 , L_7 ) ;
V_13 = F_62 ( V_49 , V_132 ) ;
if ( ! V_13 )
return V_130 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_99 . V_131 = (struct V_137 ) {
. type = V_138 ,
. V_139 = V_140 ,
. V_83 [ 0 ] = 1 ,
. V_83 [ 1 ] = V_6 -> V_18 -> V_118 ,
. V_83 [ 2 ] = ( V_6 -> V_18 -> V_83 >> 8 ) | 0x40 ,
. V_83 [ 3 ] = V_6 -> V_18 -> V_83 & 0xff ,
} ;
return F_71 ( V_10 , V_13 ) ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_26 ( V_6 -> V_18 -> V_135 ) ;
struct V_12 * V_13 ;
F_12 ( V_136 , V_6 , L_8 ) ;
V_13 = F_62 ( V_49 , V_132 ) ;
if ( ! V_13 )
return V_130 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_99 . V_131 = (struct V_137 ) {
. type = V_138 ,
. V_139 = V_141 ,
. V_83 [ 0 ] = 1 ,
. V_83 [ 1 ] = V_6 -> V_18 -> V_118 ,
. V_83 [ 2 ] = ( V_6 -> V_18 -> V_83 >> 8 ) | 0x40 ,
. V_83 [ 3 ] = V_6 -> V_18 -> V_83 & 0xff ,
. V_119 = ( unsigned long ) V_6 ,
} ;
return F_71 ( V_10 , V_13 ) ;
}
static int F_77 ( struct F_9 * V_142 )
{
struct V_16 * V_17 =
F_78 ( sizeof( * V_17 ) , V_143 ) ;
if ( ! V_17 )
return - V_144 ;
F_79 ( & V_17 -> V_128 ) ;
F_80 ( & V_17 -> V_51 , 0 ) ;
V_17 -> V_62 = NULL ;
V_142 -> V_19 = V_17 ;
return 0 ;
}
static void F_81 ( struct F_9 * V_142 )
{
struct V_16 * V_17 = V_142 -> V_19 ;
F_82 ( V_17 ) ;
}
static void F_83 ( struct V_9 * V_10 , bool V_145 )
{
int V_75 ;
int V_146 ;
if ( ( V_10 -> V_129 == 1 ||
V_10 -> V_129 != F_84 () ) && V_145 ) {
if ( V_10 -> V_147 )
V_145 = false ;
else
return;
}
if ( V_145 ) {
V_75 = 0 ;
F_85 (cpu) {
F_86 ( V_10 -> V_63 [ V_75 ] . V_57 , V_146 ) ;
V_75 ++ ;
}
V_10 -> V_147 = true ;
} else {
for ( V_75 = 0 ; V_75 < V_10 -> V_129 ; V_75 ++ )
F_86 ( V_10 -> V_63 [ V_75 ] . V_57 , - 1 ) ;
V_10 -> V_147 = false ;
}
}
static void F_87 ( struct V_9 * V_10 , bool V_145 )
{
F_88 () ;
F_83 ( V_10 , V_145 ) ;
F_89 () ;
}
static int F_90 ( struct V_148 * V_149 ,
unsigned long V_150 , void * V_151 )
{
struct V_9 * V_10 = F_48 ( V_149 , struct V_9 , V_152 ) ;
switch( V_150 ) {
case V_153 :
case V_154 :
case V_155 :
case V_156 :
F_83 ( V_10 , true ) ;
break;
default:
break;
}
return V_157 ;
}
static void F_91 ( struct V_52 * V_53 ,
struct V_56 * V_57 )
{
F_79 ( & V_53 -> V_58 ) ;
V_53 -> V_57 = V_57 ;
}
static void F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_81 = (struct V_1 * ) V_3 -> V_4 ;
F_49 ( V_81 ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_26 ( V_59 ) ;
F_87 ( V_10 , false ) ;
V_3 -> V_158 -> V_159 ( V_3 ) ;
V_3 -> V_158 -> V_160 ( V_3 ) ;
}
static int F_94 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
int V_68 ;
T_1 V_75 ;
T_1 V_161 ;
T_5 * * V_162 ;
const char * * V_163 ;
struct V_56 * * V_164 ;
V_161 = V_10 -> V_129 + V_61 ;
V_164 = F_78 ( V_161 * sizeof( struct V_56 * ) , V_143 ) ;
V_162 = F_78 ( V_161 * sizeof( T_5 * ) , V_143 ) ;
V_163 = F_78 ( V_161 * sizeof( char * ) , V_143 ) ;
if ( ! V_162 || ! V_164 || ! V_163 ) {
V_68 = - V_144 ;
goto V_101;
}
V_162 [ 0 ] = F_30 ;
V_162 [ 1 ] = F_53 ;
V_163 [ 0 ] = L_9 ;
V_163 [ 1 ] = L_10 ;
for ( V_75 = V_61 ; V_75 < V_161 ; V_75 ++ ) {
V_162 [ V_75 ] = F_25 ;
V_163 [ V_75 ] = L_11 ;
}
V_68 = V_3 -> V_158 -> V_165 ( V_3 , V_161 , V_164 , V_162 , V_163 ) ;
if ( V_68 )
goto V_101;
F_91 ( & V_10 -> V_65 , V_164 [ 0 ] ) ;
F_91 ( & V_10 -> V_73 , V_164 [ 1 ] ) ;
for ( V_75 = V_61 ; V_75 < V_161 ; V_75 ++ )
F_91 ( & V_10 -> V_63 [ V_75 - V_61 ] ,
V_164 [ V_75 ] ) ;
F_87 ( V_10 , true ) ;
F_95 ( V_3 , V_166 , V_125 ) ;
F_95 ( V_3 , V_167 , V_45 ) ;
if ( F_96 ( V_3 , V_168 ) )
F_35 ( V_10 ) ;
V_68 = 0 ;
V_101:
F_82 ( V_163 ) ;
F_82 ( V_162 ) ;
F_82 ( V_164 ) ;
if ( V_68 )
F_93 ( V_3 ) ;
return V_68 ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_81 ;
struct V_9 * V_10 ;
int V_68 ;
T_1 V_169 , V_170 ;
T_1 V_171 ;
T_1 V_129 ;
struct V_172 * V_173 ;
V_129 = F_98 ( V_3 , V_129 ) ? : 1 ;
V_170 = F_98 ( V_3 , V_174 ) + 1 ;
if ( V_129 == 1 )
V_173 = & V_175 ;
else
V_173 = & V_176 ;
V_81 = F_99 ( V_173 ,
sizeof( * V_10 ) + sizeof( V_10 -> V_63 [ 0 ] ) * V_129 ) ;
if ( ! V_81 )
return - V_144 ;
V_169 = F_98 ( V_3 , V_177 ) ? : 1 ;
V_81 -> V_113 = V_169 ;
V_10 = F_26 ( V_81 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_129 = V_129 ;
V_3 -> V_4 = V_81 ;
V_68 = F_94 ( V_3 , V_10 ) ;
if ( V_68 )
goto V_178;
V_10 -> V_152 . V_179 = & F_90 ;
V_68 = F_100 ( & V_10 -> V_152 ) ;
if ( V_68 ) {
F_43 ( L_12 ) ;
goto V_180;
}
V_171 = F_98 ( V_3 , V_171 ) ? : 1 ;
V_81 -> V_171 = F_14 ( T_1 , V_171 , V_81 -> V_181 ) ;
V_81 -> V_182 = F_98 ( V_3 , V_182 ) ? : 0xFFFF ;
V_81 -> V_183 = F_98 ( V_3 , V_183 ) + 1 + 0x4000 ;
V_81 -> V_184 = V_170 ;
V_81 -> V_185 = 0 ;
V_81 -> V_186 = V_125 ;
V_68 = F_101 ( V_81 , & V_3 -> V_187 ) ;
if ( V_68 )
goto V_180;
return 0 ;
V_180:
V_3 -> V_158 -> V_160 ( V_3 ) ;
V_178:
F_102 ( V_81 ) ;
return V_68 ;
}
static void F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_81 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_26 ( V_81 ) ;
if ( F_96 ( V_3 , V_168 ) )
F_36 ( V_10 ) ;
F_104 ( V_81 ) ;
F_105 ( & V_10 -> V_152 ) ;
F_93 ( V_3 ) ;
F_102 ( V_81 ) ;
}
static int F_106 ( struct V_2 * V_3 )
{
F_93 ( V_3 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_59 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_26 ( V_59 ) ;
return F_94 ( V_3 , V_10 ) ;
}
static int T_6 F_108 ( void )
{
int V_112 = - V_144 ;
V_188 = F_109 ( V_12 , 0 ) ;
if ( ! V_188 ) {
F_43 ( L_13 ) ;
goto error;
}
V_49 =
F_110 ( V_189 ,
V_188 ) ;
if ( ! V_49 ) {
F_43 ( L_14 ) ;
goto error;
}
V_112 = F_111 ( & V_190 ) ;
if ( V_112 < 0 )
goto error;
return 0 ;
error:
if ( V_49 ) {
F_112 ( V_49 ) ;
V_49 = NULL ;
}
if ( V_188 ) {
F_113 ( V_188 ) ;
V_188 = NULL ;
}
return V_112 ;
}
static void T_7 F_114 ( void )
{
F_115 ( & V_190 ) ;
F_112 ( V_49 ) ;
F_113 ( V_188 ) ;
}
