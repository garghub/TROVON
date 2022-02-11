int F_1 ( int V_1 , int V_2 , int V_3 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
if ( ( V_5 = F_2 ( sizeof( struct V_4 ) , V_7 ) ) == NULL )
{
F_3 ( L_1 ) ;
return - V_8 ;
}
V_9 [ V_1 ] = V_5 ;
F_4 ( & V_5 -> V_10 ) ;
F_5 ( & V_5 -> V_11 ) ;
if ( V_2 >= 0xA0000 && V_2 <= 0xFFFFF ) {
V_5 -> V_12 = V_2 ;
if ( ! F_6 ( V_5 -> V_12 , 4096 , L_2 ) ) {
F_3 ( V_13
L_3 ,
V_5 -> V_12 , V_5 -> V_12 + 4096 ) ;
F_7 ( V_5 ) ;
V_9 [ V_1 ] = NULL ;
return - V_14 ;
}
V_5 -> V_15 = F_8 ( V_5 -> V_12 , 4096 ) ;
}
else
{
F_3 ( L_4 ) ;
F_7 ( V_5 ) ;
V_9 [ V_1 ] = NULL ;
return - V_14 ;
}
V_5 -> V_16 = F_2 ( sizeof( struct V_17 ) , V_7 ) ;
if ( ! V_5 -> V_16 ) {
F_3 ( L_5 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( V_5 -> V_12 , 4096 ) ;
F_7 ( V_5 ) ;
return - V_8 ;
}
V_5 -> V_18 = F_2 ( sizeof( struct V_17 ) , V_7 ) ;
if ( ! V_5 -> V_18 ) {
F_3 ( L_5 ) ;
F_7 ( V_5 -> V_16 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( V_5 -> V_12 , 4096 ) ;
F_7 ( V_5 ) ;
return - V_8 ;
}
V_5 -> V_18 -> V_19 = 1 ;
F_11 ( & V_5 -> V_20 , V_21 ) ;
if ( F_12 ( V_3 , & V_22 , 0 , V_23 [ V_1 ] , V_5 ) != 0 )
{
F_7 ( V_5 -> V_16 ) ;
F_7 ( V_5 -> V_18 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( V_5 -> V_12 , 4096 ) ;
F_7 ( V_5 ) ;
V_9 [ V_1 ] = NULL ;
return - V_24 ;
}
V_5 -> V_3 = V_3 ;
V_5 -> V_25 = 0 ;
V_5 -> V_26 = 0 ;
V_5 -> V_27 = 0 ;
V_5 -> V_28 = 16 ;
V_6 = F_13 ( sizeof( T_1 ) , V_7 ) ;
if ( ! V_6 ) {
F_14 ( V_3 , V_5 ) ;
F_7 ( V_5 -> V_16 ) ;
F_7 ( V_5 -> V_18 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( V_5 -> V_12 , 4096 ) ;
F_7 ( V_5 ) ;
V_9 [ V_1 ] = NULL ;
return - V_24 ;
}
V_5 -> V_6 = V_6 ;
V_6 -> V_29 = V_30 ;
V_6 -> V_31 = 2 ;
V_6 -> V_32 = ( V_33 | V_34 |
V_35 | V_36 ) ;
V_6 -> V_37 = V_38 ;
V_6 -> V_28 = 16 ;
V_6 -> V_39 = V_40 ;
V_6 -> V_41 = V_42 ;
V_6 -> V_43 = V_44 ;
V_6 -> V_45 = V_46 ;
strcpy ( V_6 -> V_19 , V_23 [ V_1 ] ) ;
if ( ! F_15 ( V_6 ) ) {
F_14 ( V_3 , V_5 ) ;
F_7 ( V_5 -> V_16 ) ;
F_7 ( V_5 -> V_18 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( V_5 -> V_12 , 4096 ) ;
F_7 ( V_5 ) ;
V_9 [ V_1 ] = NULL ;
return - V_24 ;
}
V_5 -> V_19 = V_6 -> V_31 ;
V_5 -> V_47 = V_48 ;
V_5 -> free = 511 ;
return 0 ;
}
void F_16 ( int V_1 )
{
struct V_4 * V_5 ;
V_5 = V_9 [ V_1 ] ;
if ( V_5 ) {
F_14 ( V_5 -> V_3 , V_5 ) ;
F_17 ( V_5 ) ;
F_7 ( V_5 -> V_6 ) ;
if ( V_5 -> V_16 -> V_49 . V_50 )
F_18 ( & V_5 -> V_16 -> V_49 ) ;
if ( V_5 -> V_18 -> V_49 . V_50 )
F_18 ( & V_5 -> V_18 -> V_49 ) ;
F_7 ( V_5 -> V_16 ) ;
F_7 ( V_5 -> V_18 ) ;
F_9 ( V_5 -> V_15 ) ;
F_10 ( V_5 -> V_12 , 4096 ) ;
F_7 ( V_5 ) ;
}
}
static int V_42 ( T_2 * V_51 )
{
struct V_4 * V_5 ;
struct V_17 * V_52 ;
struct V_53 V_54 ;
V_5 = F_19 ( V_51 -> V_55 ) ;
if ( ! V_5 )
{
F_3 ( L_6 ) ;
return - 1 ;
}
V_52 = ( V_51 -> V_56 & 0x0F ) ? V_5 -> V_18 : V_5 -> V_16 ;
switch ( V_51 -> V_41 ) {
case V_57 :
return F_20 ( V_51 ) ;
break;
case V_58 :
V_54 . type = V_59 ;
V_54 . V_60 . V_61 . V_62 = ( char * ) & V_51 -> V_63 . V_61 . V_64 ;
F_21 ( V_5 , V_52 , V_59 , & V_54 ) ;
break;
case V_65 :
F_21 ( V_5 , V_52 , V_66 , NULL ) ;
break;
case V_67 :
F_3 ( L_7 ) ;
break;
case V_68 :
F_21 ( V_5 , V_52 , V_69 , NULL ) ;
break;
case V_70 :
V_52 -> V_71 = ( V_51 -> V_56 >> 8 ) ;
break;
case V_72 :
F_17 ( V_5 ) ;
break;
case V_73 :
F_22 ( V_5 , V_51 -> V_63 . V_74 ) ;
break;
case V_75 :
if ( ( V_51 -> V_56 >> 8 ) != V_76 )
F_3 ( V_77 L_8 ) ;
break;
default:
F_3 ( V_77 L_9 ) ;
break;
} ;
return 0 ;
}
static void F_23 ( unsigned long V_60 )
{
struct V_17 * V_52 ;
struct V_4 * V_5 ;
T_2 V_78 ;
V_52 = (struct V_17 * ) V_60 ;
V_5 = F_24 ( V_52 ) ;
if ( V_5 == NULL ) {
F_3 ( V_77 L_10 ) ;
return;
}
F_18 ( & V_52 -> V_79 ) ;
V_52 -> V_79 . V_50 = NULL ;
#ifdef F_25
F_3 ( V_77 L_11 ) ;
#endif
V_52 -> V_80 = 0 ;
V_78 . V_55 = V_5 -> V_19 ;
V_78 . V_41 = V_81 ;
V_78 . V_56 = V_52 -> V_19 ;
V_5 -> V_6 -> V_82 ( & V_78 ) ;
}
static int V_38 ( int V_55 , int V_83 , int V_84 , struct V_85 * V_86 )
{
T_3 V_87 ;
int V_88 , V_89 ;
struct V_17 * V_52 ;
struct V_4 * V_5 ;
V_5 = F_19 ( V_55 ) ;
if ( V_5 == NULL )
{
F_3 ( L_12 ) ;
return - 1 ;
}
V_52 = V_83 ? V_5 -> V_18 : V_5 -> V_16 ;
if ( V_52 -> V_90 != V_91 )
return - 1 ;
if ( V_52 -> V_80 >= V_92 )
{
#ifdef F_26
F_3 ( V_77
L_13 ,
V_52 -> V_80 ) ;
#endif
#ifdef F_27
if ( V_52 -> V_79 . V_50 == NULL ) {
F_28 ( & V_52 -> V_79 ) ;
V_52 -> V_79 . V_50 = & F_23 ;
V_52 -> V_79 . V_60 = ( long ) V_52 ;
V_52 -> V_79 . V_93 = V_94 + 1 * V_95 ;
F_29 ( & V_52 -> V_79 ) ;
}
#endif
return 0 ;
}
V_52 -> V_80 ++ ;
V_89 = V_86 -> V_89 ;
V_87 = F_30 ( V_52 , V_86 ) ;
V_88 = V_96 ++ & 0x7fffU ;
V_52 -> V_97 = V_88 ;
F_31 ( V_5 , V_98 , V_88 , V_86 , V_87 ) ;
return V_89 ;
}
static int V_44 ( const T_4 T_5 * V_99 , int V_89 , int V_55 , int V_100 )
{
struct V_4 * V_5 ;
int V_101 , V_102 ;
const T_4 * V_103 ;
T_4 * V_104 = NULL ;
T_4 * V_105 ;
int V_106 ;
V_5 = F_19 ( V_55 ) ;
if ( ! V_5 )
{
F_3 ( L_14 ) ;
return - V_107 ;
}
switch ( V_5 -> V_47 ) {
case V_108 :
if ( V_89 < 0 || V_89 > V_109 + 1 || V_89 > 1024 )
{
F_3 ( L_15 , V_89 ) ;
return - V_110 ;
}
V_105 = F_32 ( V_99 , V_89 ) ;
if ( F_33 ( V_105 ) )
return F_34 ( V_105 ) ;
F_35 ( V_5 -> V_15 , V_105 , V_89 ) ;
F_7 ( V_105 ) ;
return V_89 ;
case V_111 :
if ( ( V_104 = F_13 ( V_89 , V_7 ) ) == NULL )
return - V_8 ;
if ( F_36 ( V_104 , V_99 , V_89 ) ) {
F_7 ( V_104 ) ;
return - V_112 ;
}
V_103 = V_104 ;
V_106 = 0 ;
for ( V_101 = 0 ; V_101 < V_89 ; V_101 ++ )
{
for ( V_102 = 0 ; V_102 < V_113 ; V_102 ++ )
if ( ! ( F_37 ( V_5 -> V_15 + V_5 -> V_114 ) ) )
break;
if ( V_102 == V_113 )
{
V_106 = - V_115 ;
F_3 ( L_16 , V_101 ) ;
break;
}
F_38 ( V_103 [ V_101 ] , V_5 -> V_15 + V_5 -> V_114 + 1 ) ;
F_38 ( 0x01 , V_5 -> V_15 + V_5 -> V_114 ) ;
V_5 -> V_114 += 2 ;
if ( V_5 -> V_114 > V_116 )
V_5 -> V_114 = V_117 ;
}
F_7 ( V_104 ) ;
return V_106 ? V_106 : V_89 ;
default:
return - V_118 ;
}
}
void F_39 ( struct V_4 * V_5 , T_6 V_119 ,
struct V_85 * V_86 ,
T_3 V_120 , T_3 V_88 )
{
struct V_17 * V_52 ;
struct V_85 * V_121 ;
unsigned short V_89 ;
struct V_53 V_122 ;
int V_123 , V_124 ;
T_2 V_78 ;
switch ( V_119 ) {
case V_125 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
V_52 -> V_126 = V_86 -> V_60 [ 7 ] ;
F_41 ( V_86 , 8 ) ;
V_5 -> V_6 -> V_127 ( V_5 -> V_19 , V_52 -> V_19 , V_86 ) ;
if ( F_42 ( V_52 , & V_121 ) > 0 )
F_31 ( V_5 , V_128 , V_88 ,
V_121 , V_121 -> V_89 ) ;
return;
break;
case V_129 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
#ifdef F_25
if ( ( * ( ( T_3 * ) ( V_86 -> V_60 + 2 ) ) ) != 0 ) {
F_3 ( V_77 L_18 ) ;
}
#endif
#ifdef F_27
if ( V_52 -> V_80 == V_92 ) {
F_18 ( & V_52 -> V_79 ) ;
V_52 -> V_79 . V_50 = NULL ;
}
#endif
V_52 -> V_80 -- ;
V_78 . V_55 = V_5 -> V_19 ;
V_78 . V_41 = V_81 ;
V_78 . V_56 = V_52 -> V_19 ;
V_5 -> V_6 -> V_82 ( & V_78 ) ;
break;
case V_130 :
if ( ! V_5 -> V_16 -> V_90 )
V_52 = V_5 -> V_16 ;
else if ( ! V_5 -> V_18 -> V_90 )
V_52 = V_5 -> V_18 ;
else {
F_3 ( V_131
L_19 ) ;
if ( ( V_89 = F_43 ( * ( T_3 * ) ( V_86 -> V_60 ) , & V_121 , V_132 ) ) > 0 )
F_31 ( V_5 , V_133 , V_88 , V_121 , V_89 ) ;
break;
}
V_122 . V_60 . V_61 . V_62 = NULL ;
V_122 . V_60 . V_61 . V_134 = NULL ;
F_44 ( V_52 , V_86 , & V_122 ) ;
V_122 . type = V_135 ;
F_21 ( V_5 , V_52 , V_135 , NULL ) ;
if ( F_45 ( V_5 , V_122 . V_60 . V_61 . V_134 ) )
F_21 ( V_5 , V_52 , V_136 , & V_122 ) ;
else
F_21 ( V_5 , V_52 , V_69 , NULL ) ;
F_7 ( V_122 . V_60 . V_61 . V_62 ) ;
F_7 ( V_122 . V_60 . V_61 . V_134 ) ;
break;
case V_137 :
#ifdef F_25
F_3 ( V_77 L_20 , V_88 ,
V_5 -> V_16 -> V_97 ,
V_5 -> V_18 -> V_97 ) ;
#endif
if ( V_5 -> V_16 -> V_90 == V_138 )
V_52 = V_5 -> V_16 ;
else {
if ( V_5 -> V_18 -> V_97 == V_138 )
V_52 = V_5 -> V_18 ;
else {
V_52 = NULL ;
F_3 ( V_13 L_21 ) ;
break;
}
}
if ( F_46 ( V_52 , V_86 , & V_123 ) ) {
F_3 ( V_77 L_22 ) ;
F_21 ( V_5 , V_52 , V_139 , NULL ) ;
}
else
if ( V_123 )
F_21 ( V_5 , V_52 , V_140 , NULL ) ;
else
F_21 ( V_5 , V_52 , V_141 , NULL ) ;
break;
case V_142 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
if ( F_47 ( V_52 , V_86 ) ) {
F_3 ( L_23 ) ;
break;
}
V_52 -> V_126 = V_88 ;
F_21 ( V_5 , V_52 , V_143 , NULL ) ;
break;
case V_144 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
if ( F_48 ( V_52 , V_86 ) == 0 )
F_21 ( V_5 , V_52 , V_145 , NULL ) ;
else
F_3 ( V_77 L_24 ) ;
break;
case V_146 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
if ( ! ( V_124 = F_49 ( V_52 , V_86 ) ) )
F_21 ( V_5 , V_52 , V_147 , NULL ) ;
else {
F_3 ( L_25 , V_124 ) ;
}
break;
case V_148 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
if ( ! F_50 ( V_52 , V_86 ) )
F_21 ( V_5 , V_52 , V_149 , NULL ) ;
break;
case V_150 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
if ( ! F_51 ( V_52 , V_86 ) )
F_21 ( V_5 , V_52 , V_151 , NULL ) ;
else
F_3 ( V_13 L_26 ) ;
break;
case V_152 :
if ( ! ( V_52 = F_40 ( V_5 , V_86 ) ) ) {
F_3 ( V_13
L_17 ) ;
break;
}
if ( ! F_51 ( V_52 , V_86 ) )
F_21 ( V_5 , V_52 , V_153 , NULL ) ;
else
F_3 ( V_13 L_27 ) ;
break;
case V_154 :
#ifdef F_25
F_3 ( V_77 L_28 ) ;
#endif
break;
#ifdef F_25
case V_155 :
F_52 ( V_86 -> V_60 , V_86 -> V_89 ) ;
break;
default:
F_3 ( V_77 L_29 ,
V_119 ) ;
break;
#endif
}
F_53 ( V_86 ) ;
}
static int V_46 ( T_4 T_5 * V_99 , int V_89 , int V_55 , int V_100 )
{
int V_156 ;
V_156 = V_157 - V_158 ;
if ( V_156 < 0 )
V_156 = V_159 - V_158 + V_157 ;
if ( V_89 > V_156 )
V_89 = V_156 ;
if ( V_158 < V_157 )
{
if ( F_54 ( V_99 , V_160 + V_158 , V_89 ) )
return - V_112 ;
V_158 += V_89 ;
}
else
{
if ( V_89 > V_159 - V_158 )
{
if ( F_54 ( V_99 , V_160 + V_158 ,
V_159 - V_158 ) )
return - V_112 ;
if ( F_54 ( V_99 , V_160 ,
V_89 - ( V_159 - V_158 ) ) )
return - V_112 ;
V_158 = V_89 - ( V_159 - V_158 ) ;
}
else
{
if ( F_54 ( V_99 , V_160 + V_158 , V_89 ) )
return - V_112 ;
V_158 += V_89 ;
if ( V_158 == V_159 )
V_158 = 0 ;
}
}
if ( V_158 == V_157 )
V_158 = V_157 = 0 ;
return V_89 ;
}
static void F_55 ( struct V_4 * V_5 , char * V_161 )
{
int V_101 ;
T_2 V_78 ;
for ( V_101 = V_157 ; V_101 < strlen ( V_161 ) ; V_101 ++ )
{
V_160 [ V_101 ] = V_161 [ V_101 ] ;
V_157 = ( V_157 + 1 ) % V_159 ;
if ( V_157 == V_158 )
V_158 = ( V_158 + 1 ) % V_159 ;
}
V_78 . V_41 = V_162 ;
V_78 . V_55 = V_5 -> V_19 ;
V_78 . V_56 = strlen ( V_161 ) ;
V_5 -> V_6 -> V_82 ( & V_78 ) ;
}
void F_56 ( struct V_4 * V_5 , struct V_17 * V_52 ,
unsigned short V_101 , unsigned short V_163 , unsigned short V_164 )
{
char V_99 [ 256 ] ;
sprintf ( V_99 , L_30 ,
V_5 -> V_19 , V_52 -> V_19 ,
V_165 [ V_101 ] , F_57 ( V_163 ) , V_165 [ V_164 ]
) ;
#ifdef F_25
F_3 ( L_31 , V_99 ) ;
#endif
F_55 ( V_5 , V_99 ) ;
}
static void F_58 ( unsigned long V_104 )
{
struct V_4 * V_5 ;
#ifdef F_25
F_3 ( V_77 L_32 ) ;
#endif
V_5 = (struct V_4 * ) V_104 ;
F_59 ( & V_5 -> V_10 ) ;
}
static int F_60 ( struct V_4 * V_5 )
{
T_2 V_51 ;
F_28 ( & V_5 -> V_166 ) ;
V_5 -> V_166 . V_50 = & F_58 ;
V_5 -> V_166 . V_60 = ( T_6 ) V_5 ;
V_5 -> V_166 . V_93 = V_94 + V_167 ;
V_5 -> V_47 = V_168 ;
F_38 ( ( 0x80U | ( ( V_5 -> V_25 & 0x07 ) << 3 ) | ( V_5 -> V_26 & 0x07 ) ) ,
V_5 -> V_15 + V_109 ) ;
F_29 ( & V_5 -> V_166 ) ;
F_61 ( & V_5 -> V_10 ) ;
F_18 ( & V_5 -> V_166 ) ;
if ( V_5 -> V_47 == V_169 )
{
F_3 ( V_77 L_33 ) ;
V_5 -> V_27 = V_5 -> V_26 ;
V_5 -> V_170 = V_5 -> V_15 ;
V_5 -> V_171 = V_5 -> V_15 + V_172 ;
V_51 . V_55 = V_5 -> V_19 ;
V_51 . V_41 = V_173 ;
V_5 -> V_6 -> V_82 ( & V_51 ) ;
}
else
{
F_3 ( V_77 L_34 ) ;
F_3 ( V_77 L_35 ) ;
V_5 -> V_47 = V_48 ;
#ifdef F_25
F_3 ( V_77 L_36 ,
F_37 ( V_5 -> V_15 + V_174 ) ) ;
#endif
F_38 ( 0x40 , V_5 -> V_15 + V_109 ) ;
V_51 . V_55 = V_5 -> V_19 ;
V_51 . V_41 = V_175 ;
V_5 -> V_6 -> V_82 ( & V_51 ) ;
return - V_176 ;
}
return 0 ;
}
static int F_20 ( T_2 * V_51 )
{
struct V_4 * V_5 ;
struct F_20 * V_177 ;
V_5 = F_19 ( V_51 -> V_55 ) ;
if ( ! V_5 )
{
F_3 ( V_77 L_37 ) ;
return - V_107 ;
}
V_177 = (struct F_20 * ) V_51 -> V_63 . V_74 ;
switch ( V_51 -> V_56 ) {
case V_178 :
V_177 -> V_54 . V_179 = V_5 -> V_47 ;
break;
case V_180 :
if ( V_5 -> V_47 == V_169 )
return - V_118 ;
V_5 -> V_27 = V_5 -> V_26 = V_5 -> V_25 = 0 ;
V_5 -> V_170 = V_5 -> V_15 ;
V_5 -> V_171 = V_5 -> V_15 + V_172 ;
V_5 -> V_47 = V_181 ;
break;
case V_182 :
if ( V_5 -> V_47 != V_181 )
return - V_110 ;
V_5 -> V_47 = V_108 ;
break;
case V_183 :
if ( V_5 -> V_47 == V_169 )
return - V_118 ;
V_5 -> V_114 = V_117 ;
V_5 -> V_47 = V_111 ;
break;
case V_184 :
if ( V_5 -> V_47 == V_169 )
return - V_118 ;
V_5 -> V_47 = V_48 ;
break;
case V_185 :
if ( V_5 -> V_47 == V_169 )
return - V_118 ;
if ( V_177 -> V_54 . V_186 . V_187 > V_109 )
return - V_112 ;
F_38 ( V_177 -> V_54 . V_186 . V_188 , V_5 -> V_15 + V_177 -> V_54 . V_186 . V_187 ) ;
break;
case V_189 :
if ( V_5 -> V_47 == V_169 )
return - V_118 ;
if ( V_177 -> V_54 . V_186 . V_187 > V_109 )
{
F_3 ( L_38 , V_177 -> V_54 . V_186 . V_187 ) ;
return - V_112 ;
}
V_177 -> V_54 . V_186 . V_188 = F_37 ( V_5 -> V_15 + V_177 -> V_54 . V_186 . V_187 ) ;
break;
case V_190 :
if ( V_5 -> V_47 == V_169 )
return - V_118 ;
return F_60 ( V_5 ) ;
break;
case V_191 :
if ( V_5 -> V_47 != V_181 )
return - V_110 ;
F_31 ( V_5 , V_192 , 0x0001 , NULL , 0 ) ;
break;
case V_193 :
if ( V_5 -> V_47 != V_181 )
return - V_110 ;
F_31 ( V_5 , V_194 , 0x0001 , NULL , 0 ) ;
break;
case V_195 :
if ( V_5 -> V_47 != V_181 )
return - V_110 ;
F_31 ( V_5 , V_196 , 0x0001 , NULL , 0 ) ;
break;
case V_197 :
V_5 -> V_47 = V_48 ;
F_38 ( 0x40 , V_5 -> V_15 + V_109 ) ;
V_5 -> V_25 = 0 ;
V_5 -> V_26 = 0 ;
V_5 -> V_27 = 0 ;
break;
default:
F_3 ( L_39 ) ;
break;
} ;
return 0 ;
}
static void F_17 ( struct V_4 * V_5 )
{
struct V_198 * V_104 , * V_199 ;
for ( V_104 = V_5 -> V_200 ; V_104 ; )
{
V_199 = V_104 -> V_201 ;
F_7 ( V_104 ) ;
V_104 = V_199 ;
}
V_5 -> V_200 = NULL ;
}
static void F_22 ( struct V_4 * V_5 , char * V_202 )
{
struct V_198 * V_104 ;
struct V_198 * V_199 = NULL ;
char * V_203 , * V_204 ;
int V_89 ;
if ( strlen ( V_202 ) == 0 ) {
V_104 = F_13 ( sizeof( struct V_198 ) , V_205 ) ;
if ( ! V_104 ) {
F_3 ( V_13 L_40 ) ;
return;
}
V_104 -> V_206 = NULL ;
V_104 -> V_201 = V_5 -> V_200 ;
V_5 -> V_200 = V_104 ;
return;
}
if ( V_5 -> V_200 )
for ( V_199 = V_5 -> V_200 ; V_199 -> V_201 ; V_199 = V_199 -> V_201 ) ;
V_204 = V_202 ;
do {
V_203 = strchr ( V_204 , ',' ) ;
if ( V_203 )
V_89 = V_203 - V_204 ;
else
V_89 = strlen ( V_204 ) ;
V_104 = F_13 ( sizeof( struct V_198 ) , V_205 ) ;
if ( ! V_104 ) {
F_3 ( V_13 L_40 ) ;
return;
}
V_104 -> V_201 = NULL ;
V_104 -> V_206 = F_13 ( V_89 , V_205 ) ;
if ( ! V_104 -> V_206 ) {
F_3 ( V_13 L_40 ) ;
F_7 ( V_104 ) ;
return;
}
memcpy ( V_104 -> V_206 , V_204 , V_89 - 1 ) ;
V_104 -> V_206 [ V_89 ] = 0 ;
#ifdef F_25
F_3 ( V_77 L_41 , V_104 -> V_206 ) ;
#endif
if ( V_5 -> V_200 == NULL )
V_5 -> V_200 = V_104 ;
else
V_199 -> V_201 = V_104 ;
V_199 = V_104 ;
V_204 += V_89 ;
} while ( V_203 );
}
static int F_45 ( struct V_4 * V_5 , char * V_206 )
{
struct V_198 * V_104 ;
for ( V_104 = V_5 -> V_200 ; V_104 ; V_104 = V_104 -> V_201 ) {
if ( V_104 -> V_206 == NULL )
return 1 ;
if ( strcmp ( V_104 -> V_206 , V_206 ) == 0 )
return 1 ;
}
return 0 ;
}
