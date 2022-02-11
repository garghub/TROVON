const char * F_1 ( unsigned type )
{
if ( type == 0x1e )
return L_1 ;
if ( type == 0x1f )
return L_2 ;
if ( type >= F_2 ( V_1 ) )
return L_3 ;
return V_1 [ type ] ;
}
static void
F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
if ( V_5 -> V_9 )
F_4 ( V_10 , V_5 -> V_9 ) ;
F_4 ( V_7 -> V_11 , V_5 -> V_12 ) ;
F_4 ( V_7 -> V_13 , V_5 ) ;
}
static struct V_4 *
F_5 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_6 * V_7 = V_3 -> V_8 ;
struct V_4 * V_5 ;
V_5 = F_6 ( V_7 -> V_13 , V_14 | V_7 -> V_14 ) ;
if ( ! V_5 )
goto V_15;
V_5 -> V_12 = F_7 ( V_7 -> V_11 ,
V_14 | V_7 -> V_14 ) ;
if ( ! V_5 -> V_12 )
goto V_16;
if ( F_8 ( V_3 ) >= V_17 ) {
V_5 -> V_9 = F_6 ( V_10 , V_14 ) ;
if ( ! V_5 -> V_9 )
goto V_18;
}
return V_5 ;
V_18:
F_4 ( V_7 -> V_11 , V_5 -> V_12 ) ;
V_16:
F_4 ( V_7 -> V_13 , V_5 ) ;
V_15:
return NULL ;
}
static struct V_4 *
F_9 ( struct V_2 * V_3 , T_1 V_14 )
{
struct V_4 * V_5 = F_5 ( V_3 , V_14 ) ;
if ( F_10 ( ! V_5 ) ) {
unsigned long V_19 ;
F_11 ( & V_3 -> V_20 , V_19 ) ;
if ( F_12 ( ! F_13 ( & V_3 -> V_21 ) ) ) {
V_5 = F_14 ( V_3 -> V_21 . V_22 ,
struct V_4 , V_23 ) ;
F_15 ( & V_5 -> V_23 ) ;
}
F_16 ( & V_3 -> V_20 , V_19 ) ;
if ( V_5 ) {
void * V_24 , * V_25 ;
V_24 = V_5 -> V_12 ;
V_25 = V_5 -> V_9 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_12 = V_24 ;
V_5 -> V_9 = V_25 ;
}
}
return V_5 ;
}
struct V_4 * F_17 ( struct V_26 * V_27 , T_1 V_14 )
{
struct V_4 * V_5 = F_9 ( V_27 -> V_28 , V_14 ) ;
unsigned long V_19 ;
if ( F_10 ( V_5 == NULL ) )
return NULL ;
V_5 -> V_29 = V_27 ;
F_18 ( & V_5 -> V_23 ) ;
F_19 ( & V_5 -> V_30 , V_31 ) ;
F_11 ( & V_27 -> V_32 , V_19 ) ;
F_20 ( & V_5 -> V_23 , & V_27 -> V_33 ) ;
F_16 ( & V_27 -> V_32 , V_19 ) ;
V_5 -> V_34 = V_35 ;
return V_5 ;
}
static void F_21 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_19 ;
if ( F_10 ( F_13 ( & V_3 -> V_21 ) ) ) {
F_11 ( & V_3 -> V_20 , V_19 ) ;
if ( F_13 ( & V_3 -> V_21 ) ) {
F_22 ( & V_5 -> V_23 , & V_3 -> V_21 ) ;
V_5 = NULL ;
}
F_16 ( & V_3 -> V_20 , V_19 ) ;
}
if ( F_12 ( V_5 != NULL ) )
F_3 ( V_3 , V_5 ) ;
}
void F_23 ( struct V_4 * V_5 )
{
unsigned long V_19 ;
F_11 ( & V_5 -> V_29 -> V_32 , V_19 ) ;
F_24 ( F_13 ( & V_5 -> V_23 ) ) ;
F_15 ( & V_5 -> V_23 ) ;
F_16 ( & V_5 -> V_29 -> V_32 , V_19 ) ;
F_24 ( F_25 ( & V_5 -> V_30 ) ) ;
F_21 ( V_5 -> V_29 -> V_28 , V_5 ) ;
}
static struct V_6 *
F_26 ( struct V_2 * V_3 )
{
if ( V_3 -> V_36 -> V_37 )
return V_3 -> V_36 -> V_8 ;
if ( V_3 -> V_38 )
return & V_39 ;
return & V_40 ;
}
static void
F_27 ( struct V_6 * V_7 )
{
F_28 ( V_7 -> V_41 ) ;
F_28 ( V_7 -> V_42 ) ;
F_28 ( V_7 ) ;
}
static struct V_6 *
F_29 ( struct V_2 * V_3 )
{
struct V_43 * V_36 = V_3 -> V_36 ;
struct V_6 * V_7 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_42 = F_31 ( V_44 , L_4 , V_36 -> V_45 ) ;
V_7 -> V_41 = F_31 ( V_44 , L_5 , V_36 -> V_45 ) ;
if ( ! V_7 -> V_42 || ! V_7 -> V_41 ) {
F_27 ( V_7 ) ;
return NULL ;
}
V_7 -> V_46 = V_47 ;
if ( V_3 -> V_38 ) {
V_7 -> V_46 |= V_48 ;
V_7 -> V_14 = V_49 ;
}
if ( V_36 -> V_37 )
V_36 -> V_8 = V_7 ;
return V_7 ;
}
static struct V_6 *
F_32 ( struct V_2 * V_3 )
{
struct V_43 * V_36 = V_3 -> V_36 ;
struct V_6 * V_50 = NULL , * V_7 ;
T_2 V_37 = sizeof( struct V_4 ) + V_36 -> V_37 ;
F_33 ( & V_51 ) ;
V_7 = F_26 ( V_3 ) ;
if ( ! V_7 ) {
V_7 = F_29 ( V_3 ) ;
if ( ! V_7 )
goto V_52;
}
if ( ! V_7 -> V_53 ) {
V_7 -> V_13 = F_34 ( V_7 -> V_42 , V_37 , 0 ,
V_7 -> V_46 , NULL ) ;
if ( ! V_7 -> V_13 )
goto V_54;
V_7 -> V_11 = F_34 ( V_7 -> V_41 ,
V_55 , 0 ,
V_7 -> V_46 , NULL ) ;
if ( ! V_7 -> V_11 )
goto V_56;
}
V_7 -> V_53 ++ ;
V_50 = V_7 ;
V_52:
F_35 ( & V_51 ) ;
return V_50 ;
V_56:
F_36 ( V_7 -> V_13 ) ;
V_54:
if ( V_36 -> V_37 ) {
F_27 ( V_7 ) ;
V_36 -> V_8 = NULL ;
}
goto V_52;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_43 * V_36 = V_3 -> V_36 ;
struct V_6 * V_7 ;
F_33 ( & V_51 ) ;
V_7 = F_26 ( V_3 ) ;
F_24 ( V_7 -> V_53 == 0 ) ;
if ( ! -- V_7 -> V_53 ) {
F_36 ( V_7 -> V_13 ) ;
F_36 ( V_7 -> V_11 ) ;
if ( V_36 -> V_37 ) {
F_27 ( V_7 ) ;
V_36 -> V_8 = NULL ;
}
}
F_35 ( & V_51 ) ;
}
int F_38 ( struct V_2 * V_3 )
{
const T_1 V_14 = V_3 -> V_38 ? V_57 : V_44 ;
struct V_4 * V_5 ;
F_39 ( & V_3 -> V_20 ) ;
F_18 ( & V_3 -> V_21 ) ;
V_3 -> V_8 = F_32 ( V_3 ) ;
if ( ! V_3 -> V_8 )
return - V_58 ;
V_5 = F_5 ( V_3 , V_14 ) ;
if ( ! V_5 ) {
F_37 ( V_3 ) ;
V_3 -> V_8 = NULL ;
return - V_58 ;
}
F_22 ( & V_5 -> V_23 , & V_3 -> V_21 ) ;
return 0 ;
}
void F_40 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 )
return;
while ( ! F_13 ( & V_3 -> V_21 ) ) {
struct V_4 * V_5 ;
V_5 = F_14 ( V_3 -> V_21 . V_22 , struct V_4 , V_23 ) ;
F_15 ( & V_5 -> V_23 ) ;
F_3 ( V_3 , V_5 ) ;
}
V_3 -> V_8 = NULL ;
F_37 ( V_3 ) ;
}
void F_41 ( struct V_4 * V_5 )
{
unsigned int V_59 ;
if ( F_10 ( V_60 ) ) {
V_59 = F_42 ( V_61 ,
V_62 ) ;
if ( V_59 > 1 ) {
F_43 ( V_63 , V_5 , L_6 ) ;
if ( V_59 > 2 )
F_44 ( L_7 , V_5 ) ;
F_44 ( L_8 ) ;
F_45 ( V_5 ) ;
if ( V_59 > 3 ) {
F_44 ( V_63 L_9
L_10 ,
F_46 ( V_5 ) , F_47 ( V_5 ) ,
V_5 -> V_29 -> V_28 -> V_36 -> V_64 ) ;
}
}
}
}
void F_48 ( struct V_4 * V_5 , int V_65 )
{
unsigned int V_59 ;
if ( F_10 ( V_60 ) ) {
V_59 = F_42 ( V_66 ,
V_67 ) ;
if ( ( ( V_59 > 0 ) && ( V_5 -> V_68 || V_65 != V_69 ) ) ||
( V_59 > 1 ) ) {
F_43 ( V_63 , V_5 , L_11 ) ;
if ( V_59 > 2 )
F_44 ( L_7 , V_5 ) ;
switch ( V_65 ) {
case V_69 :
F_44 ( L_12 ) ;
break;
case V_70 :
F_44 ( L_13 ) ;
break;
case V_71 :
F_44 ( L_14 ) ;
break;
case V_72 :
F_44 ( L_15 ) ;
break;
case V_73 :
F_44 ( L_16 ) ;
break;
default:
F_44 ( L_17 ) ;
}
F_49 ( V_5 ) ;
F_45 ( V_5 ) ;
if ( F_50 ( V_5 -> V_68 ) & V_74 )
F_51 ( L_18 , V_5 ) ;
if ( V_59 > 3 )
F_43 ( V_63 , V_5 ,
L_19 ,
F_52 ( & V_5 -> V_29 -> V_28 -> V_75 ) ,
V_5 -> V_29 -> V_28 -> V_76 ) ;
}
}
}
void F_53 ( struct V_2 * V_28 , struct V_4 * V_5 )
{
V_5 -> V_77 = V_28 -> V_78 ++ ;
if ( V_5 -> V_77 == 0 )
V_5 -> V_77 = V_28 -> V_78 ++ ;
}
int F_54 ( struct V_4 * V_5 )
{
struct V_2 * V_28 = V_5 -> V_29 -> V_28 ;
int V_79 = 0 ;
F_55 ( & V_5 -> V_29 -> V_80 ) ;
if ( F_10 ( V_5 -> V_29 -> V_81 == V_82 ) ) {
V_5 -> V_68 = V_83 << 16 ;
goto V_84;
}
if ( F_10 ( F_56 ( V_5 -> V_29 ) ) ) {
F_57 ( 3 , F_43 ( V_63 , V_5 ,
L_20 ) ) ;
return V_85 ;
}
if ( V_5 -> V_29 -> V_86 <= V_87 &&
V_5 -> V_29 -> V_86 != V_88 ) {
V_5 -> V_89 [ 1 ] = ( V_5 -> V_89 [ 1 ] & 0x1f ) |
( V_5 -> V_29 -> V_90 << 5 & 0xe0 ) ;
}
F_41 ( V_5 ) ;
if ( V_5 -> V_91 > V_5 -> V_29 -> V_28 -> V_92 ) {
F_57 ( 3 , F_43 ( V_63 , V_5 ,
L_21
L_22 ,
V_5 -> V_91 , V_5 -> V_29 -> V_28 -> V_92 ) ) ;
V_5 -> V_68 = ( V_93 << 16 ) ;
goto V_84;
}
if ( F_10 ( V_28 -> V_94 == V_95 ) ) {
V_5 -> V_68 = ( V_83 << 16 ) ;
goto V_84;
}
F_58 ( V_5 ) ;
V_79 = V_28 -> V_36 -> V_64 ( V_28 , V_5 ) ;
if ( V_79 ) {
F_59 ( V_5 , V_79 ) ;
if ( V_79 != V_85 &&
V_79 != V_96 )
V_79 = V_97 ;
F_57 ( 3 , F_43 ( V_63 , V_5 ,
L_23 ) ) ;
}
return V_79 ;
V_84:
V_5 -> V_98 ( V_5 ) ;
return 0 ;
}
void F_60 ( struct V_4 * V_5 )
{
struct V_26 * V_99 = V_5 -> V_29 ;
struct V_100 * V_101 = V_100 ( V_99 ) ;
struct V_2 * V_3 = V_99 -> V_28 ;
struct V_102 * V_103 ;
unsigned int V_104 ;
F_61 ( V_99 ) ;
if ( F_52 ( & V_3 -> V_105 ) )
F_62 ( & V_3 -> V_105 , 0 ) ;
if ( F_52 ( & V_101 -> V_106 ) )
F_62 ( & V_101 -> V_106 , 0 ) ;
if ( F_52 ( & V_99 -> V_107 ) )
F_62 ( & V_99 -> V_107 , 0 ) ;
if ( F_63 ( V_5 ) )
V_5 -> V_68 |= ( V_108 << 24 ) ;
F_64 ( 4 , F_65 ( V_63 , V_99 ,
L_24
L_25 , V_5 -> V_68 ) ) ;
V_104 = F_47 ( V_5 ) ;
if ( V_5 -> V_109 -> V_110 != V_111 ) {
int V_112 = V_104 ;
V_103 = F_66 ( V_5 ) ;
if ( V_103 -> V_84 )
V_104 = V_103 -> V_84 ( V_5 ) ;
if ( V_104 == V_112 )
V_104 -= F_67 ( V_5 ) ;
}
F_68 ( V_5 , V_104 ) ;
}
void F_69 ( struct V_26 * V_99 , int V_113 , int V_114 )
{
unsigned long V_19 ;
if ( V_114 <= 0 )
return;
F_11 ( V_99 -> V_115 -> V_116 , V_19 ) ;
if ( ! F_70 ( V_99 -> V_28 ) && ! V_99 -> V_28 -> V_117 ) {
if ( F_71 ( V_99 -> V_115 ) &&
F_72 ( V_99 -> V_115 , V_114 ) != 0 )
goto V_52;
}
V_99 -> V_118 = V_114 ;
switch ( V_113 ) {
case 0 :
V_99 -> V_119 = 0 ;
V_99 -> V_120 = 0 ;
break;
case V_121 :
V_99 -> V_119 = 1 ;
V_99 -> V_120 = 1 ;
break;
case V_122 :
V_99 -> V_119 = 0 ;
V_99 -> V_120 = 1 ;
break;
default:
V_99 -> V_119 = 0 ;
V_99 -> V_120 = 0 ;
F_65 ( V_123 , V_99 ,
L_26
L_27 ) ;
}
V_52:
F_16 ( V_99 -> V_115 -> V_116 , V_19 ) ;
}
int F_73 ( struct V_26 * V_99 , int V_124 )
{
if ( ( V_35 >> 4 ) == ( V_99 -> V_125 >> 4 ) )
return 0 ;
V_99 -> V_125 = V_35 ;
if ( V_99 -> V_126 != V_124 ) {
V_99 -> V_127 = 1 ;
V_99 -> V_126 = V_124 ;
} else {
V_99 -> V_127 ++ ;
}
if ( V_99 -> V_127 <= 10 )
return 0 ;
if ( V_99 -> V_126 < 8 ) {
F_69 ( V_99 , 0 , V_99 -> V_28 -> V_128 ) ;
return - 1 ;
}
if ( V_99 -> V_119 )
F_69 ( V_99 , V_121 , V_124 ) ;
else
F_69 ( V_99 , V_122 , V_124 ) ;
return V_124 ;
}
static int F_74 ( struct V_26 * V_99 , unsigned char * V_129 ,
T_3 V_130 , unsigned V_131 )
{
int V_68 ;
unsigned char V_5 [ 16 ] ;
if ( V_131 < 4 )
return - V_132 ;
V_5 [ 0 ] = V_133 ;
V_5 [ 1 ] = 1 ;
V_5 [ 2 ] = V_130 ;
V_5 [ 3 ] = V_131 >> 8 ;
V_5 [ 4 ] = V_131 & 0xff ;
V_5 [ 5 ] = 0 ;
V_68 = F_75 ( V_99 , V_5 , V_134 , V_129 ,
V_131 , NULL , 30 * V_135 , 3 , NULL ) ;
if ( V_68 )
return - V_136 ;
if ( V_129 [ 1 ] != V_130 )
return - V_136 ;
return F_76 ( & V_129 [ 2 ] ) + 4 ;
}
int F_77 ( struct V_26 * V_99 , T_3 V_130 , unsigned char * V_24 ,
int V_137 )
{
int V_138 , V_68 ;
if ( V_99 -> V_139 )
goto V_15;
V_68 = F_74 ( V_99 , V_24 , 0 , V_137 ) ;
if ( V_68 < 4 )
goto V_15;
if ( V_130 == 0 )
return 0 ;
for ( V_138 = 4 ; V_138 < F_78 ( V_68 , V_137 ) ; V_138 ++ )
if ( V_24 [ V_138 ] == V_130 )
goto V_140;
if ( V_138 < V_68 && V_138 >= V_137 )
goto V_140;
goto V_15;
V_140:
V_68 = F_74 ( V_99 , V_24 , V_130 , V_137 ) ;
if ( V_68 < 0 )
goto V_15;
return 0 ;
V_15:
return - V_132 ;
}
void F_79 ( struct V_26 * V_99 )
{
int V_68 , V_138 ;
int V_141 = V_142 ;
int V_143 = 0 ;
int V_144 = 0 ;
unsigned char * V_145 ;
if ( V_99 -> V_139 )
return;
V_146:
V_145 = F_80 ( V_141 , V_44 ) ;
if ( ! V_145 )
return;
V_68 = F_74 ( V_99 , V_145 , 0 , V_141 ) ;
if ( V_68 < 0 ) {
F_28 ( V_145 ) ;
return;
}
if ( V_68 > V_141 ) {
V_141 = V_68 ;
F_28 ( V_145 ) ;
goto V_146;
}
for ( V_138 = 4 ; V_138 < V_68 ; V_138 ++ ) {
if ( V_145 [ V_138 ] == 0x80 )
V_143 = 1 ;
if ( V_145 [ V_138 ] == 0x83 )
V_144 = 1 ;
}
F_28 ( V_145 ) ;
V_141 = V_142 ;
if ( V_143 ) {
V_147:
V_145 = F_80 ( V_141 , V_44 ) ;
if ( ! V_145 )
return;
V_68 = F_74 ( V_99 , V_145 , 0x80 , V_141 ) ;
if ( V_68 < 0 ) {
F_28 ( V_145 ) ;
return;
}
if ( V_68 > V_141 ) {
V_141 = V_68 ;
F_28 ( V_145 ) ;
goto V_147;
}
V_99 -> V_148 = V_68 ;
V_99 -> V_149 = V_145 ;
V_141 = V_142 ;
}
if ( V_144 ) {
V_150:
V_145 = F_80 ( V_141 , V_44 ) ;
if ( ! V_145 )
return;
V_68 = F_74 ( V_99 , V_145 , 0x83 , V_141 ) ;
if ( V_68 < 0 ) {
F_28 ( V_145 ) ;
return;
}
if ( V_68 > V_141 ) {
V_141 = V_68 ;
F_28 ( V_145 ) ;
goto V_150;
}
V_99 -> V_151 = V_68 ;
V_99 -> V_152 = V_145 ;
}
}
int F_81 ( struct V_26 * V_99 , unsigned char * V_129 ,
unsigned int V_131 , unsigned char V_153 )
{
unsigned char V_5 [ 16 ] ;
struct V_154 V_155 ;
int V_68 ;
if ( V_99 -> V_156 || V_99 -> V_86 < V_157 )
return - V_132 ;
memset ( V_5 , 0 , 16 ) ;
V_5 [ 0 ] = V_158 ;
V_5 [ 1 ] = V_159 ;
V_5 [ 2 ] = 1 ;
V_5 [ 3 ] = V_153 ;
F_82 ( V_131 , & V_5 [ 6 ] ) ;
memset ( V_129 , 0 , V_131 ) ;
V_68 = F_75 ( V_99 , V_5 , V_134 , V_129 , V_131 ,
& V_155 , 30 * V_135 , 3 , NULL ) ;
if ( V_68 && F_83 ( & V_155 ) &&
V_155 . V_160 == V_161 &&
( V_155 . V_162 == 0x20 || V_155 . V_162 == 0x24 ) && V_155 . V_163 == 0x00 )
return - V_132 ;
if ( ( V_129 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_84 ( struct V_26 * V_99 )
{
if ( V_99 -> V_81 == V_82 )
return - V_164 ;
if ( ! F_85 ( & V_99 -> V_165 ) )
return - V_164 ;
F_86 ( V_99 -> V_28 -> V_36 -> V_166 ) ;
return 0 ;
}
void F_87 ( struct V_26 * V_99 )
{
#ifdef F_88
struct V_166 * V_166 = V_99 -> V_28 -> V_36 -> V_166 ;
if ( V_166 && F_89 ( V_166 ) != 0 )
F_90 ( V_166 ) ;
#endif
F_91 ( & V_99 -> V_165 ) ;
}
struct V_26 * F_92 ( struct V_2 * V_3 ,
struct V_26 * V_167 )
{
struct V_168 * V_23 = ( V_167 ? & V_167 -> V_169 : & V_3 -> V_170 ) ;
struct V_26 * V_22 = NULL ;
unsigned long V_19 ;
F_11 ( V_3 -> V_171 , V_19 ) ;
while ( V_23 -> V_22 != & V_3 -> V_170 ) {
V_22 = F_14 ( V_23 -> V_22 , struct V_26 , V_169 ) ;
if ( ! F_84 ( V_22 ) )
break;
V_22 = NULL ;
V_23 = V_23 -> V_22 ;
}
F_16 ( V_3 -> V_171 , V_19 ) ;
if ( V_167 )
F_87 ( V_167 ) ;
return V_22 ;
}
void F_93 ( struct V_100 * V_101 , void * V_172 ,
void (* F_94)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_95 ( V_101 -> V_27 . V_173 ) ;
struct V_26 * V_99 ;
F_96 (sdev, shost) {
if ( ( V_99 -> V_174 == V_101 -> V_174 ) &&
( V_99 -> V_175 == V_101 -> V_175 ) )
F_94 ( V_99 , V_172 ) ;
}
}
void F_97 ( struct V_100 * V_101 , void * V_172 ,
void (* F_94)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_95 ( V_101 -> V_27 . V_173 ) ;
struct V_26 * V_99 ;
F_98 (sdev, shost) {
if ( ( V_99 -> V_174 == V_101 -> V_174 ) &&
( V_99 -> V_175 == V_101 -> V_175 ) )
F_94 ( V_99 , V_172 ) ;
}
}
struct V_26 * F_99 ( struct V_100 * V_101 ,
T_4 V_90 )
{
struct V_26 * V_99 ;
F_100 (sdev, &starget->devices, same_target_siblings) {
if ( V_99 -> V_81 == V_82 )
continue;
if ( V_99 -> V_90 == V_90 )
return V_99 ;
}
return NULL ;
}
struct V_26 * F_101 ( struct V_100 * V_101 ,
T_4 V_90 )
{
struct V_26 * V_99 ;
struct V_2 * V_3 = F_95 ( V_101 -> V_27 . V_173 ) ;
unsigned long V_19 ;
F_11 ( V_3 -> V_171 , V_19 ) ;
V_99 = F_99 ( V_101 , V_90 ) ;
if ( V_99 && F_84 ( V_99 ) )
V_99 = NULL ;
F_16 ( V_3 -> V_171 , V_19 ) ;
return V_99 ;
}
struct V_26 * F_102 ( struct V_2 * V_3 ,
T_5 V_174 , T_5 V_175 , T_4 V_90 )
{
struct V_26 * V_99 ;
F_100 (sdev, &shost->__devices, siblings) {
if ( V_99 -> V_174 == V_174 && V_99 -> V_175 == V_175 &&
V_99 -> V_90 == V_90 )
return V_99 ;
}
return NULL ;
}
struct V_26 * F_103 ( struct V_2 * V_3 ,
T_5 V_174 , T_5 V_175 , T_4 V_90 )
{
struct V_26 * V_99 ;
unsigned long V_19 ;
F_11 ( V_3 -> V_171 , V_19 ) ;
V_99 = F_102 ( V_3 , V_174 , V_175 , V_90 ) ;
if ( V_99 && F_84 ( V_99 ) )
V_99 = NULL ;
F_16 ( V_3 -> V_171 , V_19 ) ;
return V_99 ;
}
static int T_6 F_104 ( void )
{
int error ;
error = F_105 () ;
if ( error )
return error ;
error = F_106 () ;
if ( error )
goto V_176;
error = F_107 () ;
if ( error )
goto V_177;
error = F_108 () ;
if ( error )
goto V_178;
error = F_109 () ;
if ( error )
goto V_179;
error = F_110 () ;
if ( error )
goto V_180;
F_111 () ;
F_44 ( V_181 L_28 ) ;
return 0 ;
V_180:
F_112 () ;
V_179:
F_113 () ;
V_178:
F_114 () ;
V_177:
F_115 () ;
V_176:
F_116 () ;
F_44 ( V_182 L_29 ,
- error ) ;
return error ;
}
static void T_7 F_117 ( void )
{
F_118 () ;
F_119 () ;
F_112 () ;
F_113 () ;
F_114 () ;
F_115 () ;
F_116 () ;
F_120 ( & V_183 ) ;
}
