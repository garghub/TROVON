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
if ( V_5 -> V_29 -> V_86 )
V_5 -> V_87 [ 1 ] = ( V_5 -> V_87 [ 1 ] & 0x1f ) |
( V_5 -> V_29 -> V_88 << 5 & 0xe0 ) ;
F_41 ( V_5 ) ;
if ( V_5 -> V_89 > V_5 -> V_29 -> V_28 -> V_90 ) {
F_57 ( 3 , F_43 ( V_63 , V_5 ,
L_21
L_22 ,
V_5 -> V_89 , V_5 -> V_29 -> V_28 -> V_90 ) ) ;
V_5 -> V_68 = ( V_91 << 16 ) ;
goto V_84;
}
if ( F_10 ( V_28 -> V_92 == V_93 ) ) {
V_5 -> V_68 = ( V_83 << 16 ) ;
goto V_84;
}
F_58 ( V_5 ) ;
V_79 = V_28 -> V_36 -> V_64 ( V_28 , V_5 ) ;
if ( V_79 ) {
F_59 ( V_5 , V_79 ) ;
if ( V_79 != V_85 &&
V_79 != V_94 )
V_79 = V_95 ;
F_57 ( 3 , F_43 ( V_63 , V_5 ,
L_23 ) ) ;
}
return V_79 ;
V_84:
V_5 -> V_96 ( V_5 ) ;
return 0 ;
}
void F_60 ( struct V_4 * V_5 )
{
struct V_26 * V_97 = V_5 -> V_29 ;
struct V_98 * V_99 = V_98 ( V_97 ) ;
struct V_2 * V_3 = V_97 -> V_28 ;
struct V_100 * V_101 ;
unsigned int V_102 ;
F_61 ( V_97 ) ;
if ( F_52 ( & V_3 -> V_103 ) )
F_62 ( & V_3 -> V_103 , 0 ) ;
if ( F_52 ( & V_99 -> V_104 ) )
F_62 ( & V_99 -> V_104 , 0 ) ;
if ( F_52 ( & V_97 -> V_105 ) )
F_62 ( & V_97 -> V_105 , 0 ) ;
if ( F_63 ( V_5 ) )
V_5 -> V_68 |= ( V_106 << 24 ) ;
F_64 ( 4 , F_65 ( V_63 , V_97 ,
L_24
L_25 , V_5 -> V_68 ) ) ;
V_102 = F_47 ( V_5 ) ;
if ( V_5 -> V_107 -> V_108 != V_109 ) {
int V_110 = V_102 ;
V_101 = F_66 ( V_5 ) ;
if ( V_101 -> V_84 )
V_102 = V_101 -> V_84 ( V_5 ) ;
if ( V_102 == V_110 )
V_102 -= F_67 ( V_5 ) ;
}
F_68 ( V_5 , V_102 ) ;
}
void F_69 ( struct V_26 * V_97 , int V_111 , int V_112 )
{
unsigned long V_19 ;
if ( V_112 <= 0 )
return;
F_11 ( V_97 -> V_113 -> V_114 , V_19 ) ;
if ( ! F_70 ( V_97 -> V_28 ) && ! V_97 -> V_28 -> V_115 ) {
if ( F_71 ( V_97 -> V_113 ) &&
F_72 ( V_97 -> V_113 , V_112 ) != 0 )
goto V_52;
}
V_97 -> V_116 = V_112 ;
switch ( V_111 ) {
case 0 :
V_97 -> V_117 = 0 ;
V_97 -> V_118 = 0 ;
break;
case V_119 :
V_97 -> V_117 = 1 ;
V_97 -> V_118 = 1 ;
break;
case V_120 :
V_97 -> V_117 = 0 ;
V_97 -> V_118 = 1 ;
break;
default:
V_97 -> V_117 = 0 ;
V_97 -> V_118 = 0 ;
F_65 ( V_121 , V_97 ,
L_26
L_27 ) ;
}
V_52:
F_16 ( V_97 -> V_113 -> V_114 , V_19 ) ;
}
int F_73 ( struct V_26 * V_97 , int V_122 )
{
if ( ( V_35 >> 4 ) == ( V_97 -> V_123 >> 4 ) )
return 0 ;
V_97 -> V_123 = V_35 ;
if ( V_97 -> V_124 != V_122 ) {
V_97 -> V_125 = 1 ;
V_97 -> V_124 = V_122 ;
} else {
V_97 -> V_125 ++ ;
}
if ( V_97 -> V_125 <= 10 )
return 0 ;
if ( V_97 -> V_124 < 8 ) {
F_69 ( V_97 , 0 , V_97 -> V_28 -> V_126 ) ;
return - 1 ;
}
if ( V_97 -> V_117 )
F_69 ( V_97 , V_119 , V_122 ) ;
else
F_69 ( V_97 , V_120 , V_122 ) ;
return V_122 ;
}
static int F_74 ( struct V_26 * V_97 , unsigned char * V_127 ,
T_3 V_128 , unsigned V_129 )
{
int V_68 ;
unsigned char V_5 [ 16 ] ;
if ( V_129 < 4 )
return - V_130 ;
V_5 [ 0 ] = V_131 ;
V_5 [ 1 ] = 1 ;
V_5 [ 2 ] = V_128 ;
V_5 [ 3 ] = V_129 >> 8 ;
V_5 [ 4 ] = V_129 & 0xff ;
V_5 [ 5 ] = 0 ;
V_68 = F_75 ( V_97 , V_5 , V_132 , V_127 ,
V_129 , NULL , 30 * V_133 , 3 , NULL ) ;
if ( V_68 )
return - V_134 ;
if ( V_127 [ 1 ] != V_128 )
return - V_134 ;
return F_76 ( & V_127 [ 2 ] ) + 4 ;
}
int F_77 ( struct V_26 * V_97 , T_3 V_128 , unsigned char * V_24 ,
int V_135 )
{
int V_136 , V_68 ;
if ( V_97 -> V_137 )
goto V_15;
V_68 = F_74 ( V_97 , V_24 , 0 , V_135 ) ;
if ( V_68 < 4 )
goto V_15;
if ( V_128 == 0 )
return 0 ;
for ( V_136 = 4 ; V_136 < F_78 ( V_68 , V_135 ) ; V_136 ++ )
if ( V_24 [ V_136 ] == V_128 )
goto V_138;
if ( V_136 < V_68 && V_136 >= V_135 )
goto V_138;
goto V_15;
V_138:
V_68 = F_74 ( V_97 , V_24 , V_128 , V_135 ) ;
if ( V_68 < 0 )
goto V_15;
return 0 ;
V_15:
return - V_130 ;
}
void F_79 ( struct V_26 * V_97 )
{
int V_68 , V_136 ;
int V_139 = V_140 ;
int V_141 = 0 ;
int V_142 = 0 ;
unsigned char * V_143 ;
if ( V_97 -> V_137 )
return;
V_144:
V_143 = F_80 ( V_139 , V_44 ) ;
if ( ! V_143 )
return;
V_68 = F_74 ( V_97 , V_143 , 0 , V_139 ) ;
if ( V_68 < 0 ) {
F_28 ( V_143 ) ;
return;
}
if ( V_68 > V_139 ) {
V_139 = V_68 ;
F_28 ( V_143 ) ;
goto V_144;
}
for ( V_136 = 4 ; V_136 < V_68 ; V_136 ++ ) {
if ( V_143 [ V_136 ] == 0x80 )
V_141 = 1 ;
if ( V_143 [ V_136 ] == 0x83 )
V_142 = 1 ;
}
F_28 ( V_143 ) ;
V_139 = V_140 ;
if ( V_141 ) {
V_145:
V_143 = F_80 ( V_139 , V_44 ) ;
if ( ! V_143 )
return;
V_68 = F_74 ( V_97 , V_143 , 0x80 , V_139 ) ;
if ( V_68 < 0 ) {
F_28 ( V_143 ) ;
return;
}
if ( V_68 > V_139 ) {
V_139 = V_68 ;
F_28 ( V_143 ) ;
goto V_145;
}
V_97 -> V_146 = V_68 ;
V_97 -> V_147 = V_143 ;
V_139 = V_140 ;
}
if ( V_142 ) {
V_148:
V_143 = F_80 ( V_139 , V_44 ) ;
if ( ! V_143 )
return;
V_68 = F_74 ( V_97 , V_143 , 0x83 , V_139 ) ;
if ( V_68 < 0 ) {
F_28 ( V_143 ) ;
return;
}
if ( V_68 > V_139 ) {
V_139 = V_68 ;
F_28 ( V_143 ) ;
goto V_148;
}
V_97 -> V_149 = V_68 ;
V_97 -> V_150 = V_143 ;
}
}
int F_81 ( struct V_26 * V_97 , unsigned char * V_127 ,
unsigned int V_129 , unsigned char V_151 )
{
unsigned char V_5 [ 16 ] ;
struct V_152 V_153 ;
int V_68 ;
if ( V_97 -> V_154 || V_97 -> V_155 < V_156 )
return - V_130 ;
memset ( V_5 , 0 , 16 ) ;
V_5 [ 0 ] = V_157 ;
V_5 [ 1 ] = V_158 ;
V_5 [ 2 ] = 1 ;
V_5 [ 3 ] = V_151 ;
F_82 ( V_129 , & V_5 [ 6 ] ) ;
memset ( V_127 , 0 , V_129 ) ;
V_68 = F_75 ( V_97 , V_5 , V_132 , V_127 , V_129 ,
& V_153 , 30 * V_133 , 3 , NULL ) ;
if ( V_68 && F_83 ( & V_153 ) &&
V_153 . V_159 == V_160 &&
( V_153 . V_161 == 0x20 || V_153 . V_161 == 0x24 ) && V_153 . V_162 == 0x00 )
return - V_130 ;
if ( ( V_127 [ 1 ] & 3 ) == 3 )
return 1 ;
return 0 ;
}
int F_84 ( struct V_26 * V_97 )
{
if ( V_97 -> V_81 == V_82 )
return - V_163 ;
if ( ! F_85 ( & V_97 -> V_164 ) )
return - V_163 ;
F_86 ( V_97 -> V_28 -> V_36 -> V_165 ) ;
return 0 ;
}
void F_87 ( struct V_26 * V_97 )
{
#ifdef F_88
struct V_165 * V_165 = V_97 -> V_28 -> V_36 -> V_165 ;
if ( V_165 && F_89 ( V_165 ) != 0 )
F_90 ( V_165 ) ;
#endif
F_91 ( & V_97 -> V_164 ) ;
}
struct V_26 * F_92 ( struct V_2 * V_3 ,
struct V_26 * V_166 )
{
struct V_167 * V_23 = ( V_166 ? & V_166 -> V_168 : & V_3 -> V_169 ) ;
struct V_26 * V_22 = NULL ;
unsigned long V_19 ;
F_11 ( V_3 -> V_170 , V_19 ) ;
while ( V_23 -> V_22 != & V_3 -> V_169 ) {
V_22 = F_14 ( V_23 -> V_22 , struct V_26 , V_168 ) ;
if ( ! F_84 ( V_22 ) )
break;
V_22 = NULL ;
V_23 = V_23 -> V_22 ;
}
F_16 ( V_3 -> V_170 , V_19 ) ;
if ( V_166 )
F_87 ( V_166 ) ;
return V_22 ;
}
void F_93 ( struct V_98 * V_99 , void * V_171 ,
void (* F_94)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_95 ( V_99 -> V_27 . V_172 ) ;
struct V_26 * V_97 ;
F_96 (sdev, shost) {
if ( ( V_97 -> V_173 == V_99 -> V_173 ) &&
( V_97 -> V_174 == V_99 -> V_174 ) )
F_94 ( V_97 , V_171 ) ;
}
}
void F_97 ( struct V_98 * V_99 , void * V_171 ,
void (* F_94)( struct V_26 * , void * ) )
{
struct V_2 * V_3 = F_95 ( V_99 -> V_27 . V_172 ) ;
struct V_26 * V_97 ;
F_98 (sdev, shost) {
if ( ( V_97 -> V_173 == V_99 -> V_173 ) &&
( V_97 -> V_174 == V_99 -> V_174 ) )
F_94 ( V_97 , V_171 ) ;
}
}
struct V_26 * F_99 ( struct V_98 * V_99 ,
T_4 V_88 )
{
struct V_26 * V_97 ;
F_100 (sdev, &starget->devices, same_target_siblings) {
if ( V_97 -> V_81 == V_82 )
continue;
if ( V_97 -> V_88 == V_88 )
return V_97 ;
}
return NULL ;
}
struct V_26 * F_101 ( struct V_98 * V_99 ,
T_4 V_88 )
{
struct V_26 * V_97 ;
struct V_2 * V_3 = F_95 ( V_99 -> V_27 . V_172 ) ;
unsigned long V_19 ;
F_11 ( V_3 -> V_170 , V_19 ) ;
V_97 = F_99 ( V_99 , V_88 ) ;
if ( V_97 && F_84 ( V_97 ) )
V_97 = NULL ;
F_16 ( V_3 -> V_170 , V_19 ) ;
return V_97 ;
}
struct V_26 * F_102 ( struct V_2 * V_3 ,
T_5 V_173 , T_5 V_174 , T_4 V_88 )
{
struct V_26 * V_97 ;
F_100 (sdev, &shost->__devices, siblings) {
if ( V_97 -> V_173 == V_173 && V_97 -> V_174 == V_174 &&
V_97 -> V_88 == V_88 )
return V_97 ;
}
return NULL ;
}
struct V_26 * F_103 ( struct V_2 * V_3 ,
T_5 V_173 , T_5 V_174 , T_4 V_88 )
{
struct V_26 * V_97 ;
unsigned long V_19 ;
F_11 ( V_3 -> V_170 , V_19 ) ;
V_97 = F_102 ( V_3 , V_173 , V_174 , V_88 ) ;
if ( V_97 && F_84 ( V_97 ) )
V_97 = NULL ;
F_16 ( V_3 -> V_170 , V_19 ) ;
return V_97 ;
}
static int T_6 F_104 ( void )
{
int error ;
error = F_105 () ;
if ( error )
return error ;
error = F_106 () ;
if ( error )
goto V_175;
error = F_107 () ;
if ( error )
goto V_176;
error = F_108 () ;
if ( error )
goto V_177;
error = F_109 () ;
if ( error )
goto V_178;
error = F_110 () ;
if ( error )
goto V_179;
F_111 () ;
F_44 ( V_180 L_28 ) ;
return 0 ;
V_179:
F_112 () ;
V_178:
F_113 () ;
V_177:
F_114 () ;
V_176:
F_115 () ;
V_175:
F_116 () ;
F_44 ( V_181 L_29 ,
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
F_120 ( & V_182 ) ;
}
