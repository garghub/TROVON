static int F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 = V_6 ;
if ( ! F_2 ( V_7 ) ) {
F_3 ( L_1 ,
V_8 ) ;
return - V_9 ;
}
F_4 ( V_10 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_11 ;
if ( V_4 -> V_12 == V_13 )
F_4 ( V_14 ) ;
if ( V_4 -> V_15 > V_5 )
V_5 = V_4 -> V_15 ;
if ( V_4 -> V_16 . V_17 != 0 )
F_4 ( V_18 ) ;
break;
}
F_6 ( V_5 ) ;
return 0 ;
}
static T_1 F_7 ( int V_19 , void * V_20 )
{
F_8 ( V_19 ) ;
if ( F_9 () )
F_10 ( NULL ) ;
return V_21 ;
}
static T_2 F_11 ( struct V_22 * V_23 ,
const char T_3 * V_24 ,
T_4 V_25 , T_5 * V_26 )
{
struct V_1 * V_2 = V_23 -> V_11 ;
struct V_27 * V_28 ;
int V_29 , type , V_30 ;
unsigned long V_31 , V_32 ;
char V_33 [ 50 ] ;
int V_34 ;
if ( ! V_35 || ! V_35 -> V_36 )
return - V_37 ;
V_34 = F_12 ( V_33 , sizeof( V_33 ) , V_26 , V_24 , V_25 ) ;
if ( ! V_34 )
return - V_38 ;
V_34 = sscanf ( V_33 , L_2 ,
& V_29 , & type , & V_30 , & V_31 , & V_32 ) ;
if ( V_34 != 5 )
return - V_9 ;
V_28 = F_13 ( V_2 , V_29 , 0 ) ;
if ( ! V_28 )
return - V_39 ;
V_34 = V_35 -> V_36 ( V_28 , type , V_30 , V_31 , V_32 ) ;
return V_34 < 0 ? V_34 : V_25 ;
}
static int F_14 ( void * V_20 , int V_40 , T_6 V_41 )
{
struct V_1 * V_2 = V_20 ;
struct V_3 * V_4 = V_2 -> V_11 ;
F_15 ( V_4 -> V_42 + V_40 , V_41 ) ;
return 0 ;
}
static int F_16 ( void * V_20 , int V_40 , T_6 * V_41 )
{
struct V_1 * V_2 = V_20 ;
struct V_3 * V_4 = V_2 -> V_11 ;
* V_41 = F_17 ( V_4 -> V_42 + V_40 ) ;
return 0 ;
}
static int F_18 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_34 = 0 ;
if ( ! V_43 ) {
V_44 = F_19 ( F_20 ( V_45 ) ) ;
if ( V_44 < 0 ) {
F_21 ( L_3 ,
V_8 , V_44 ) ;
return V_44 ;
}
V_34 = F_22 ( V_44 , F_7 ,
V_46 , L_4 , NULL ) ;
if ( V_34 < 0 ) {
F_23 ( V_44 ) ;
F_21 ( L_5 ,
V_8 , V_44 ) ;
return V_34 ;
}
V_43 = true ;
}
if ( ! F_9 () )
F_24 ( V_44 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_11 ;
if ( F_9 () )
V_4 -> V_47 |= V_48 ;
else
V_4 -> V_47 &= ~ V_48 ;
#ifdef F_25
if ( V_4 -> V_49 || ! V_4 -> V_50 )
continue;
V_4 -> V_49 = 1 ;
F_26 ( L_6 , 0200 ,
V_4 -> V_50 , V_2 ,
& V_51 ) ;
F_26 ( L_7 , 0600 ,
V_4 -> V_50 , V_2 ,
& V_52 ) ;
F_26 ( L_8 , 0600 ,
V_4 -> V_50 , V_2 ,
& V_53 ) ;
F_26 ( L_9 , 0600 ,
V_4 -> V_50 , V_2 ,
& V_54 ) ;
#endif
}
return V_34 ;
}
static int F_27 ( struct V_55 * V_56 , int V_57 )
{
int V_58 = V_59 ;
int V_60 = 48 ;
T_7 V_61 , V_62 ;
if ( ! V_56 )
return 0 ;
F_28 ( V_56 , V_63 , 2 , & V_61 ) ;
if ( ! ( V_61 & V_64 ) )
return 0 ;
while ( V_60 -- ) {
F_28 ( V_56 , V_58 , 1 , & V_58 ) ;
if ( V_58 < 0x40 )
break;
V_58 &= ~ 3 ;
F_28 ( V_56 , V_58 + V_65 , 1 , & V_62 ) ;
if ( V_62 == 0xff )
break;
if ( V_62 == V_57 )
return V_58 ;
V_58 += V_66 ;
}
return 0 ;
}
static int F_29 ( struct V_55 * V_56 , int V_57 )
{
struct V_67 * V_68 = F_30 ( V_56 ) ;
T_7 V_69 ;
int V_58 = 256 , V_70 = ( 4096 - 256 ) / 8 ;
if ( ! V_68 || ! V_68 -> V_71 )
return 0 ;
if ( F_28 ( V_56 , V_58 , 4 , & V_69 ) != V_72 )
return 0 ;
else if ( ! V_69 )
return 0 ;
while ( V_70 -- > 0 ) {
if ( F_31 ( V_69 ) == V_57 && V_58 )
return V_58 ;
V_58 = F_32 ( V_69 ) ;
if ( V_58 < 256 )
break;
if ( F_28 ( V_56 , V_58 , 4 , & V_69 ) != V_72 )
break;
}
return 0 ;
}
static void * F_33 ( struct V_55 * V_56 , void * V_20 )
{
struct V_1 * V_2 = V_56 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_67 * V_68 = F_30 ( V_56 ) ;
T_8 V_73 ;
int V_34 ;
int V_74 = ( V_56 -> V_75 << 8 ) | ( V_56 -> V_76 ) ;
if ( ! V_68 || V_68 -> V_28 )
return NULL ;
if ( ( V_56 -> V_77 >> 8 ) == V_78 )
return NULL ;
V_68 -> V_77 = V_56 -> V_77 ;
V_68 -> V_79 &= 0xFFFFFF00 ;
V_68 -> V_80 = F_27 ( V_56 , V_81 ) ;
V_68 -> V_71 = F_27 ( V_56 , V_82 ) ;
V_68 -> V_83 = F_27 ( V_56 , V_84 ) ;
V_68 -> V_85 = F_29 ( V_56 , V_86 ) ;
if ( ( V_68 -> V_77 >> 8 ) == V_87 ) {
V_68 -> V_79 |= V_88 ;
if ( V_68 -> V_71 ) {
F_28 ( V_56 , V_68 -> V_71 + V_89 ,
2 , & V_73 ) ;
V_73 = ( V_73 & V_90 ) >> 4 ;
if ( V_73 == V_91 )
V_68 -> V_79 |= V_92 ;
else if ( V_73 == V_93 )
V_68 -> V_79 |= V_94 ;
}
}
V_68 -> V_95 = V_4 -> V_16 . V_96 [ V_74 ] ;
V_34 = F_34 ( V_68 ) ;
if ( V_34 ) {
F_3 ( L_10 ,
V_8 , V_2 -> V_97 , V_56 -> V_75 ,
F_35 ( V_56 -> V_76 ) , F_36 ( V_56 -> V_76 ) , V_34 ) ;
return NULL ;
}
if ( ( V_56 -> V_98 == V_99 &&
V_56 -> V_100 == 0x1656 ) ||
( V_56 -> V_98 == V_99 &&
V_56 -> V_100 == 0x1657 ) ||
( V_56 -> V_98 == V_99 &&
V_56 -> V_100 == 0x168a ) ||
( V_56 -> V_98 == V_99 &&
V_56 -> V_100 == 0x168e ) )
V_68 -> V_28 -> V_101 |= V_102 ;
if ( ! ( V_68 -> V_28 -> V_101 & V_103 ) ) {
V_68 -> V_28 -> V_104 = F_37 ( V_2 -> V_97 ,
V_56 -> V_75 ) ;
if ( V_68 -> V_28 -> V_104 )
V_68 -> V_28 -> V_101 |= V_103 ;
}
F_4 ( V_105 ) ;
F_38 ( V_68 ) ;
return NULL ;
}
static int F_39 ( struct V_27 * V_28 , int V_106 )
{
struct V_1 * V_2 = V_28 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_11 ;
bool V_107 = false ;
int V_108 ;
T_9 V_109 ;
switch ( V_106 ) {
case V_110 :
return - V_111 ;
case V_112 :
return 0 ;
case V_113 :
V_108 = V_114 ;
break;
case V_115 :
V_108 = V_116 ;
break;
case V_117 :
V_107 = true ;
V_108 = V_118 ;
break;
default:
F_3 ( L_11 , V_8 , V_106 ) ;
return - V_9 ;
}
if ( V_107 ) {
if ( V_4 -> V_107 ) {
V_4 -> V_107 ( V_4 , V_28 -> V_31 ) ;
return 0 ;
}
V_109 = F_40 ( V_4 -> V_119 , V_28 -> V_31 , V_108 ) ;
if ( V_109 != V_120 ) {
F_3 ( L_12 ,
V_8 , V_109 , V_4 -> V_2 -> V_97 ,
V_28 -> V_31 ) ;
return - V_121 ;
}
return 0 ;
}
if ( V_4 -> V_122 )
return V_4 -> V_122 ( V_4 , V_28 -> V_31 , V_108 ) ;
V_109 = F_41 ( V_4 -> V_119 , V_28 -> V_31 , V_108 ) ;
if ( V_109 != V_120 ) {
F_3 ( L_13 ,
V_8 , V_109 , V_106 , V_4 -> V_2 -> V_97 ,
V_28 -> V_31 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_42 ( struct V_27 * V_28 )
{
return V_28 -> V_31 ;
}
static void F_43 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = V_28 -> V_4 -> V_11 ;
T_9 V_109 ;
V_109 = F_44 ( V_4 -> V_119 , V_28 -> V_20 ,
V_4 -> V_15 ) ;
if ( V_109 != V_120 )
F_3 ( L_14 ,
V_8 , V_109 , V_28 -> V_4 -> V_97 ) ;
}
static int F_45 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = V_28 -> V_4 -> V_11 ;
T_10 V_123 ;
T_11 V_124 ;
T_9 V_109 ;
int V_125 = 0 ;
V_109 = F_46 ( V_4 -> V_119 ,
V_28 -> V_31 ,
& V_123 ,
& V_124 ,
NULL ) ;
if ( V_109 != V_120 ) {
F_3 ( L_15 ,
V_8 , V_109 , V_4 -> V_2 -> V_97 ) ;
return V_126 ;
}
if ( F_47 ( V_124 ) != V_127 ) {
V_125 = ( V_128 |
V_129 |
V_130 |
V_131 ) ;
} else if ( ! ( V_28 -> V_101 & V_132 ) ) {
F_48 ( V_28 , V_132 ) ;
F_43 ( V_28 ) ;
if ( F_49 ( V_133 ) )
F_50 ( V_28 -> V_4 , V_28 -> V_20 ) ;
}
return V_125 ;
}
static int F_51 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = V_28 -> V_4 -> V_11 ;
T_10 V_123 ;
T_11 V_124 ;
T_9 V_109 ;
int V_125 ;
if ( V_28 -> V_101 & V_134 ) {
V_125 = ( V_128 |
V_129 |
V_130 |
V_131 ) ;
return V_125 ;
}
if ( V_4 -> V_135 ) {
V_123 = V_4 -> V_135 ( V_4 , V_28 -> V_31 ) ;
} else {
V_109 = F_46 ( V_4 -> V_119 ,
V_28 -> V_31 ,
& V_123 ,
& V_124 ,
NULL ) ;
if ( V_109 != V_120 ) {
F_3 ( L_16 ,
V_8 , V_109 , V_4 -> V_2 -> V_97 ,
V_28 -> V_31 ) ;
return V_126 ;
}
}
switch ( V_123 ) {
case V_136 :
V_125 = ( V_128 |
V_129 |
V_130 |
V_131 ) ;
break;
case V_137 :
V_125 = ( V_129 |
V_131 ) ;
break;
case V_138 :
V_125 = ( V_128 |
V_130 ) ;
break;
case V_139 :
V_125 = 0 ;
break;
case V_140 :
V_125 = V_141 ;
break;
case V_142 :
V_125 = V_143 ;
break;
case V_144 :
V_125 = V_126 ;
break;
default:
V_125 = V_126 ;
F_3 ( L_17 ,
V_8 , V_4 -> V_2 -> V_97 ,
V_28 -> V_31 , V_123 ) ;
}
if ( ! ( V_125 & V_126 ) &&
! ( V_125 & V_143 ) &&
! ( V_125 & V_128 ) &&
! ( V_125 & V_129 ) &&
! ( V_28 -> V_101 & V_132 ) ) {
if ( V_4 -> V_107 )
V_4 -> V_107 ( V_4 , V_28 -> V_31 ) ;
F_48 ( V_28 , V_132 ) ;
F_43 ( V_28 ) ;
if ( F_49 ( V_133 ) )
F_50 ( V_28 -> V_4 , V_28 -> V_20 ) ;
}
return V_125 ;
}
static int F_52 ( struct V_27 * V_28 , int * V_145 )
{
int V_34 ;
if ( V_28 -> type & V_146 )
V_34 = F_45 ( V_28 ) ;
else
V_34 = F_51 ( V_28 ) ;
if ( ! V_145 )
return V_34 ;
* V_145 = 0 ;
if ( V_34 & V_143 )
* V_145 = 1000 ;
return V_34 ;
}
static T_9 F_53 ( unsigned long V_62 )
{
T_9 V_109 = V_147 ;
while ( 1 ) {
V_109 = F_54 ( V_62 ) ;
if ( V_109 <= 0 )
break;
if ( V_148 < V_149 )
F_55 ( 1000 * V_109 ) ;
else
F_56 ( V_109 ) ;
}
return V_109 ;
}
int F_57 ( struct V_1 * V_2 , int V_106 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
T_9 V_109 = V_147 ;
F_58 ( L_18 ,
V_8 , V_2 -> V_97 , V_106 ) ;
if ( V_106 == V_150 ||
V_106 == V_151 )
V_109 = F_59 ( V_4 -> V_119 ,
V_152 ,
V_153 ) ;
else if ( V_106 == V_154 )
V_109 = F_59 ( V_4 -> V_119 ,
V_152 ,
V_155 ) ;
if ( V_109 < 0 )
goto V_156;
if ( V_109 > 0 )
V_109 = F_53 ( V_4 -> V_119 ) ;
if ( V_106 == V_154 ) {
if ( V_148 < V_149 )
F_55 ( 1000 * V_157 ) ;
else
F_56 ( V_157 ) ;
}
V_156:
if ( V_109 != V_120 )
return - V_121 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_106 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
T_9 V_109 = V_147 ;
F_58 ( L_18 ,
V_8 , V_2 -> V_97 , V_106 ) ;
if ( V_106 == V_150 )
V_109 = F_59 ( V_4 -> V_119 ,
V_158 ,
V_153 ) ;
else if ( V_106 == V_151 )
V_109 = F_59 ( V_4 -> V_119 ,
V_159 ,
V_153 ) ;
else if ( V_106 == V_154 )
V_109 = F_59 ( V_4 -> V_119 ,
V_159 ,
V_155 ) ;
if ( V_109 < 0 )
goto V_156;
if ( V_109 > 0 )
V_109 = F_53 ( V_4 -> V_119 ) ;
if ( V_106 == V_154 )
F_56 ( V_157 ) ;
V_156:
if ( V_109 != V_120 )
return - V_121 ;
return 0 ;
}
static int F_61 ( struct V_160 * V_161 , int V_106 )
{
struct V_55 * V_56 = F_62 ( V_161 -> V_104 , V_161 -> V_76 ) ;
struct V_67 * V_68 = F_30 ( V_56 ) ;
int V_162 = V_68 ? V_68 -> V_85 : 0 ;
T_7 V_163 ;
F_58 ( L_19 ,
V_8 , F_63 ( V_161 -> V_104 ) ,
V_161 -> V_104 -> V_164 , V_106 ) ;
switch ( V_106 ) {
case V_150 :
case V_151 :
if ( V_162 ) {
V_35 -> V_165 ( V_56 , V_162 + V_166 ,
4 , & V_163 ) ;
V_163 |= V_167 ;
V_35 -> V_168 ( V_56 , V_162 + V_166 ,
4 , V_163 ) ;
}
V_35 -> V_165 ( V_56 , V_169 , 2 , & V_163 ) ;
V_163 |= V_170 ;
V_35 -> V_168 ( V_56 , V_169 , 2 , V_163 ) ;
F_56 ( V_171 ) ;
break;
case V_154 :
V_35 -> V_165 ( V_56 , V_169 , 2 , & V_163 ) ;
V_163 &= ~ V_170 ;
V_35 -> V_168 ( V_56 , V_169 , 2 , V_163 ) ;
F_56 ( V_157 ) ;
if ( V_162 ) {
V_35 -> V_165 ( V_56 , V_162 + V_166 ,
4 , & V_163 ) ;
V_163 &= ~ V_167 ;
V_35 -> V_168 ( V_56 , V_162 + V_166 ,
4 , V_163 ) ;
}
break;
}
return 0 ;
}
static int F_64 ( struct V_160 * V_172 , int V_106 )
{
struct V_1 * V_2 = F_65 ( V_172 -> V_104 ) ;
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_173 * V_174 = F_66 ( V_172 ) ;
T_12 V_62 = F_67 ( V_4 -> V_119 ,
( V_172 -> V_104 -> V_164 << 8 ) | V_172 -> V_76 ) ;
T_13 V_175 ;
T_14 V_109 ;
if ( ! V_174 || ! F_68 ( V_174 , L_20 , NULL ) )
return F_61 ( V_172 , V_106 ) ;
switch ( V_106 ) {
case V_150 :
V_175 = V_158 ;
break;
case V_151 :
V_175 = V_159 ;
break;
case V_154 :
return 0 ;
default:
F_69 ( & V_172 -> V_161 , L_21 ,
V_8 , V_106 ) ;
return - V_9 ;
}
V_109 = F_59 ( V_62 , V_175 , V_153 ) ;
if ( V_109 <= V_120 )
goto V_156;
V_109 = F_53 ( V_62 ) ;
V_156:
return ( V_109 == V_120 ) ? 0 : - V_121 ;
}
void F_70 ( struct V_160 * V_161 )
{
struct V_1 * V_2 ;
if ( F_71 ( V_161 -> V_104 ) ) {
V_2 = F_65 ( V_161 -> V_104 ) ;
F_60 ( V_2 , V_151 ) ;
F_60 ( V_2 , V_154 ) ;
} else {
F_64 ( V_161 , V_151 ) ;
F_64 ( V_161 , V_154 ) ;
}
}
static void F_72 ( struct V_55 * V_56 , const char * type ,
int V_58 , T_15 V_32 )
{
int V_176 , V_61 = 0 ;
for ( V_176 = 0 ; V_176 < 4 ; V_176 ++ ) {
V_35 -> V_165 ( V_56 , V_58 , 2 , & V_61 ) ;
if ( ! ( V_61 & V_32 ) )
return;
F_56 ( ( 1 << V_176 ) * 100 ) ;
}
F_3 ( L_22 ,
V_8 , type ,
V_56 -> V_4 -> V_97 , V_56 -> V_75 ,
F_35 ( V_56 -> V_76 ) , F_36 ( V_56 -> V_76 ) ) ;
}
static int F_73 ( struct V_55 * V_56 , int V_106 )
{
struct V_67 * V_68 = F_30 ( V_56 ) ;
T_7 V_177 = 0 ;
if ( F_74 ( ! V_68 -> V_71 ) )
return - V_178 ;
V_35 -> V_165 ( V_56 , V_68 -> V_71 + V_179 , 4 , & V_177 ) ;
if ( ! ( V_177 & V_180 ) )
return - V_178 ;
switch ( V_106 ) {
case V_151 :
case V_150 :
F_72 ( V_56 , L_23 ,
V_68 -> V_71 + V_181 ,
V_182 ) ;
V_35 -> V_165 ( V_56 , V_68 -> V_71 + V_183 ,
4 , & V_177 ) ;
V_177 |= V_184 ;
V_35 -> V_168 ( V_56 , V_68 -> V_71 + V_183 ,
4 , V_177 ) ;
F_56 ( V_171 ) ;
break;
case V_154 :
V_35 -> V_165 ( V_56 , V_68 -> V_71 + V_183 ,
4 , & V_177 ) ;
V_177 &= ~ V_184 ;
V_35 -> V_168 ( V_56 , V_68 -> V_71 + V_183 ,
4 , V_177 ) ;
F_56 ( V_157 ) ;
break;
}
return 0 ;
}
static int F_75 ( struct V_55 * V_56 , int V_106 )
{
struct V_67 * V_68 = F_30 ( V_56 ) ;
T_7 V_57 = 0 ;
if ( F_74 ( ! V_68 -> V_83 ) )
return - V_178 ;
V_35 -> V_165 ( V_56 , V_68 -> V_83 + V_185 , 1 , & V_57 ) ;
if ( ! ( V_57 & V_186 ) || ! ( V_57 & V_187 ) )
return - V_178 ;
switch ( V_106 ) {
case V_151 :
case V_150 :
F_72 ( V_56 , L_24 ,
V_68 -> V_83 + V_188 ,
V_189 << 8 ) ;
V_35 -> V_168 ( V_56 , V_68 -> V_83 + V_188 ,
1 , V_190 ) ;
F_56 ( V_171 ) ;
break;
case V_154 :
V_35 -> V_168 ( V_56 , V_68 -> V_83 + V_188 , 1 , 0 ) ;
F_56 ( V_157 ) ;
break;
}
return 0 ;
}
static int F_76 ( struct V_27 * V_28 , int V_106 )
{
struct V_67 * V_68 ;
struct V_55 * V_56 ;
int V_34 ;
V_68 = F_77 ( & V_28 -> V_191 , struct V_67 , V_192 ) ;
V_56 = F_78 ( V_68 ) ;
if ( ! V_56 )
return - V_37 ;
V_34 = F_73 ( V_56 , V_106 ) ;
if ( ! V_34 )
return V_34 ;
return F_75 ( V_56 , V_106 ) ;
}
static int F_79 ( struct V_27 * V_28 , int V_106 )
{
struct V_1 * V_2 = V_28 -> V_4 ;
struct V_3 * V_4 ;
struct V_193 * V_104 ;
T_14 V_109 ;
if ( V_28 -> type & V_146 )
return F_57 ( V_2 , V_106 ) ;
V_4 = V_2 -> V_11 ;
if ( V_4 -> V_12 == V_13 &&
( V_106 == V_151 ||
V_106 == V_150 ) ) {
V_109 = F_59 ( V_4 -> V_119 ,
V_194 ,
V_153 ) ;
if ( V_109 != V_120 ) {
F_3 ( L_25 ,
V_8 , V_109 ) ;
return - V_121 ;
}
}
if ( V_28 -> type & V_195 )
return F_76 ( V_28 , V_106 ) ;
V_104 = F_80 ( V_28 ) ;
if ( ! V_104 ) {
F_21 ( L_26 ,
V_8 , V_28 -> V_4 -> V_97 , V_28 -> V_31 ) ;
return - V_121 ;
}
if ( F_71 ( V_104 ) ||
F_71 ( V_104 -> V_196 ) )
return F_60 ( V_2 , V_106 ) ;
return F_64 ( V_104 -> V_197 , V_106 ) ;
}
static int F_81 ( struct V_27 * V_28 , int V_198 )
{
int V_34 ;
int V_199 ;
while ( 1 ) {
V_34 = F_52 ( V_28 , & V_199 ) ;
if ( V_34 != V_143 )
return V_34 ;
if ( V_198 <= 0 ) {
F_3 ( L_27 ,
V_8 , V_28 -> V_31 , V_198 ) ;
return V_126 ;
}
V_198 -= V_199 ;
F_56 ( V_199 ) ;
}
return V_126 ;
}
static int F_82 ( struct V_27 * V_28 , int V_200 ,
char * V_201 , unsigned long V_202 )
{
if ( ! F_49 ( V_133 ) )
F_50 ( V_28 -> V_4 , V_28 -> V_20 ) ;
return 0 ;
}
static int F_83 ( struct V_27 * V_28 )
{
return 0 ;
}
static int F_84 ( struct V_27 * V_28 , int type , int V_30 ,
unsigned long V_31 , unsigned long V_32 )
{
struct V_1 * V_2 = V_28 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_11 ;
T_9 V_109 ;
if ( type != V_203 &&
type != V_204 ) {
F_3 ( L_28 ,
V_8 , type ) ;
return - V_205 ;
}
if ( V_30 < V_206 ||
V_30 > V_207 ) {
F_3 ( L_29 ,
V_8 , V_30 ) ;
return - V_205 ;
}
if ( ! F_85 ( V_208 ) ) {
F_3 ( L_30 ,
V_8 ) ;
return - V_37 ;
}
V_109 = F_86 ( V_4 -> V_119 , V_28 -> V_31 ,
type , V_30 , V_31 , V_32 ) ;
if ( V_109 != V_120 ) {
F_3 ( L_31
L_32 ,
V_8 , V_109 , type , V_30 ,
V_2 -> V_97 , V_28 -> V_31 ) ;
return - V_121 ;
}
return 0 ;
}
static inline bool F_87 ( struct V_55 * V_56 )
{
struct V_67 * V_68 = F_30 ( V_56 ) ;
if ( ! V_68 || ! V_68 -> V_28 )
return false ;
if ( V_68 -> V_209 && ( V_68 -> V_28 -> V_101 & V_134 ) )
return false ;
if ( V_68 -> V_28 -> V_101 & V_210 )
return true ;
return false ;
}
static int F_88 ( struct V_55 * V_56 ,
int V_211 , int V_212 , T_7 * V_41 )
{
if ( ! V_56 )
return V_213 ;
if ( F_87 ( V_56 ) ) {
* V_41 = 0xFFFFFFFF ;
return V_214 ;
}
return F_28 ( V_56 , V_211 , V_212 , V_41 ) ;
}
static int F_89 ( struct V_55 * V_56 ,
int V_211 , int V_212 , T_7 V_41 )
{
if ( ! V_56 )
return V_213 ;
if ( F_87 ( V_56 ) )
return V_214 ;
return F_90 ( V_56 , V_211 , V_212 , V_41 ) ;
}
static void F_91 ( struct V_215 * V_20 )
{
if ( V_20 -> V_216 || V_20 -> V_217 ||
V_20 -> V_218 || V_20 -> V_219 || V_20 -> V_220 )
F_92 ( L_33 ,
F_93 ( V_20 -> V_216 ) ,
F_93 ( V_20 -> V_217 ) ,
F_93 ( V_20 -> V_218 ) ,
F_93 ( V_20 -> V_219 ) ,
F_93 ( V_20 -> V_220 ) ) ;
if ( V_20 -> V_221 || V_20 -> V_222 ||
V_20 -> V_223 || V_20 -> V_224 || V_20 -> V_225 )
F_92 ( L_34 ,
F_93 ( V_20 -> V_221 ) ,
F_93 ( V_20 -> V_222 ) ,
F_93 ( V_20 -> V_223 ) ,
F_93 ( V_20 -> V_224 ) ,
F_93 ( V_20 -> V_225 ) ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_215 * V_20 =
(struct V_215 * ) V_4 -> V_226 ;
long V_109 ;
V_109 = F_95 ( V_4 -> V_227 , V_20 , sizeof( * V_20 ) ) ;
if ( V_109 != V_120 ) {
F_3 ( L_35 ,
V_8 , V_4 -> V_227 , V_109 ) ;
return;
}
switch ( F_47 ( V_20 -> type ) ) {
case V_228 :
F_92 ( L_36 ) ;
F_91 ( V_20 ) ;
if ( V_20 -> V_229 . V_230 || V_20 -> V_229 . V_231 )
F_92 ( L_37 ,
F_93 ( V_20 -> V_229 . V_230 ) ,
F_93 ( V_20 -> V_229 . V_231 ) ) ;
break;
case V_232 :
F_92 ( L_38 ,
V_20 -> V_233 . V_234 ? L_39 : L_40 ) ;
F_91 ( V_20 ) ;
if ( V_20 -> V_233 . V_235 || V_20 -> V_233 . V_236 ||
V_20 -> V_233 . V_237 || V_20 -> V_233 . V_238 )
F_92 ( L_41 ,
F_93 ( V_20 -> V_233 . V_235 ) ,
F_93 ( V_20 -> V_233 . V_236 ) ,
F_93 ( V_20 -> V_233 . V_237 ) ,
F_93 ( V_20 -> V_233 . V_238 ) ) ;
break;
case V_239 :
F_92 ( L_42 ,
V_20 -> V_240 . V_241 ) ;
F_91 ( V_20 ) ;
if ( V_20 -> V_240 . V_242 || V_20 -> V_240 . V_243 )
F_92 ( L_43 ,
F_93 ( V_20 -> V_240 . V_242 ) ,
F_93 ( V_20 -> V_240 . V_243 ) ) ;
break;
case V_244 :
F_92 ( L_44 ) ;
F_91 ( V_20 ) ;
break;
case V_245 :
F_92 ( L_45 ) ;
F_91 ( V_20 ) ;
break;
default:
F_3 ( L_46 ,
V_8 , V_4 -> V_227 , V_20 -> type ) ;
}
}
static int F_96 ( struct V_1 * V_2 ,
T_15 V_29 , struct V_27 * * V_28 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_246 * V_247 ;
struct V_27 * V_248 ;
V_247 = & V_4 -> V_16 . V_249 [ V_29 ] ;
if ( V_247 -> V_47 & V_250 ) {
V_247 = V_247 -> V_251 ;
F_74 ( ! V_247 ||
! ( V_247 -> V_47 & V_252 ) ) ;
V_29 = V_247 -> V_253 ;
}
V_248 = F_13 ( V_2 , V_29 , 0 ) ;
if ( ! V_248 )
return - V_254 ;
* V_28 = V_248 ;
if ( ! ( V_248 -> V_101 & V_132 ) )
V_4 -> V_107 ( V_4 , V_29 ) ;
V_248 = V_248 -> V_196 ;
while ( V_248 && ! ( V_248 -> type & V_146 ) ) {
int V_34 ;
int V_255 = ( V_128 |
V_129 ) ;
V_34 = V_35 -> V_256 ( V_248 , NULL ) ;
if ( V_34 <= 0 || ( V_34 & V_255 ) == V_255 ) {
V_248 = V_248 -> V_196 ;
continue;
}
* V_28 = V_248 ;
if ( ! ( V_248 -> V_101 & V_132 ) )
V_4 -> V_107 ( V_4 , V_248 -> V_31 ) ;
V_248 = V_248 -> V_196 ;
}
return 0 ;
}
static int F_97 ( struct V_27 * * V_28 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_27 * V_257 , * V_258 ;
T_16 V_259 ;
T_11 V_260 , V_200 ;
int V_255 = ( V_128 | V_129 ) ;
long V_109 ;
int V_101 , V_34 = V_261 ;
F_98 ( NULL , false ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_11 ;
V_257 = F_99 ( V_2 ) ;
if ( ! V_257 || ( V_257 -> V_101 & V_132 ) )
continue;
V_109 = F_100 ( V_4 -> V_119 ,
& V_259 , & V_260 , & V_200 ) ;
if ( V_109 != V_120 ) {
F_101 ( L_47
L_48 ,
V_8 , V_2 -> V_97 , V_109 ) ;
continue;
}
if ( F_47 ( V_260 ) == V_262 ||
F_47 ( V_200 ) == V_263 ) {
F_101 ( L_49 ,
V_8 , V_2 -> V_97 ) ;
continue;
}
F_101 ( L_50 ,
V_8 , F_47 ( V_260 ) ,
F_47 ( V_200 ) , F_93 ( V_259 ) ,
V_2 -> V_97 ) ;
switch ( F_47 ( V_260 ) ) {
case V_264 :
if ( F_47 ( V_200 ) == V_265 ) {
F_21 ( L_51 ) ;
V_34 = V_266 ;
} else if ( F_47 ( V_200 ) == V_267 ) {
F_92 ( L_52
L_53 ) ;
F_94 ( V_2 ) ;
V_34 = V_261 ;
}
break;
case V_127 :
if ( F_47 ( V_200 ) == V_268 ) {
* V_28 = V_257 ;
F_21 ( L_54
L_55 ,
V_2 -> V_97 ,
F_102 ( V_257 ) ) ;
V_34 = V_269 ;
} else if ( F_47 ( V_200 ) ==
V_270 ) {
* V_28 = V_257 ;
F_21 ( L_56
L_55 ,
V_2 -> V_97 ,
F_102 ( V_257 ) ) ;
V_34 = V_271 ;
} else if ( F_47 ( V_200 ) == V_267 ) {
F_92 ( L_57
L_58 ,
V_2 -> V_97 ,
F_102 ( V_257 ) ) ;
F_43 ( V_257 ) ;
F_50 ( V_2 , V_257 -> V_20 ) ;
V_34 = V_261 ;
}
break;
case V_272 :
if ( F_96 ( V_2 ,
F_93 ( V_259 ) , V_28 ) ) {
F_92 ( L_59 ,
V_2 -> V_97 , F_93 ( V_259 ) ) ;
F_92 ( L_60 ,
F_102 ( V_257 ) ) ;
V_109 = F_44 ( V_4 -> V_119 ,
V_4 -> V_226 , V_4 -> V_15 ) ;
if ( V_109 == V_120 )
F_50 ( V_2 ,
V_4 -> V_226 ) ;
F_41 ( V_4 -> V_119 ,
F_93 ( V_259 ) ,
V_273 ) ;
V_34 = V_261 ;
} else if ( ( * V_28 ) -> V_101 & V_132 ||
F_103 ( * V_28 ) ) {
V_34 = V_261 ;
} else {
F_21 ( L_61
L_62 ,
( * V_28 ) -> V_31 ,
( * V_28 ) -> V_4 -> V_97 ) ;
F_21 ( L_63
L_64 ,
F_102 ( * V_28 ) ,
F_102 ( V_257 ) ) ;
V_34 = V_274 ;
}
break;
default:
F_3 ( L_65 ,
V_8 , F_47 ( V_260 ) ) ;
}
if ( ( V_34 == V_274 ||
V_34 == V_271 ) &&
! ( ( * V_28 ) -> V_101 & V_132 ) ) {
F_48 ( * V_28 , V_132 ) ;
F_43 ( * V_28 ) ;
if ( F_49 ( V_133 ) )
F_50 ( ( * V_28 ) -> V_4 ,
( * V_28 ) -> V_20 ) ;
}
if ( V_34 == V_274 ) {
V_258 = ( * V_28 ) -> V_196 ;
while ( V_258 ) {
if ( V_258 -> type & V_146 )
break;
V_101 = V_35 -> V_256 ( V_258 , NULL ) ;
if ( V_101 > 0 &&
( V_101 & V_255 ) != V_255 )
* V_28 = V_258 ;
V_258 = V_258 -> V_196 ;
}
F_48 ( * V_28 , V_132 ) ;
}
if ( V_34 > V_275 )
break;
}
if ( V_34 == V_261 && F_9 () )
F_104 ( V_44 ) ;
return V_34 ;
}
static int F_105 ( struct V_55 * V_56 )
{
struct V_67 * V_68 = F_30 ( V_56 ) ;
T_7 V_276 , V_277 , V_278 , V_279 ;
int V_280 ;
if ( V_68 -> V_71 ) {
V_280 = ( F_106 ( V_56 -> V_281 ) - 8 ) << 5 ;
V_35 -> V_165 ( V_56 , V_68 -> V_71 + V_183 ,
2 , & V_276 ) ;
V_276 &= ~ V_282 ;
V_276 |= V_280 ;
V_35 -> V_168 ( V_56 , V_68 -> V_71 + V_183 ,
2 , V_276 ) ;
V_35 -> V_165 ( V_56 , V_68 -> V_71 + V_283 ,
4 , & V_278 ) ;
if ( V_278 & 0x10 ) {
V_35 -> V_165 ( V_56 ,
V_68 -> V_71 + V_284 ,
4 , & V_278 ) ;
V_278 |= 0x10 ;
V_35 -> V_168 ( V_56 ,
V_68 -> V_71 + V_284 ,
4 , V_278 ) ;
}
}
V_35 -> V_165 ( V_56 , V_285 , 2 , & V_277 ) ;
V_277 |= ( V_286 | V_287 ) ;
V_35 -> V_168 ( V_56 , V_285 , 2 , V_277 ) ;
if ( V_68 -> V_71 ) {
V_35 -> V_165 ( V_56 , V_68 -> V_71 + V_183 ,
2 , & V_276 ) ;
V_276 &= ~ V_288 ;
V_276 |= ( V_289 |
V_290 |
V_291 ) ;
V_35 -> V_168 ( V_56 , V_68 -> V_71 + V_183 ,
2 , V_276 ) ;
}
if ( V_68 -> V_71 && V_68 -> V_85 ) {
V_35 -> V_165 ( V_56 , V_68 -> V_85 + V_292 ,
4 , & V_279 ) ;
V_279 |= ( V_293 | V_294 ) ;
V_35 -> V_168 ( V_56 , V_68 -> V_85 + V_292 ,
4 , V_279 ) ;
}
return 0 ;
}
static int F_107 ( struct V_55 * V_56 )
{
struct V_67 * V_68 = F_30 ( V_56 ) ;
struct V_3 * V_4 ;
T_9 V_34 ;
int V_74 = ( V_56 -> V_75 << 8 ) | ( V_56 -> V_76 ) ;
if ( ! V_68 )
return - V_254 ;
if ( V_68 -> V_209 ) {
V_34 = F_105 ( V_56 ) ;
} else {
V_4 = V_56 -> V_4 -> V_11 ;
V_34 = F_108 ( V_4 -> V_119 ,
V_295 , V_74 ) ;
}
if ( V_34 ) {
F_3 ( L_66 ,
V_8 , V_74 , V_34 ) ;
return - V_121 ;
}
return 0 ;
}
void F_109 ( struct V_160 * V_172 )
{
struct V_55 * V_56 = F_110 ( V_172 ) ;
if ( ! V_172 -> V_296 )
return;
F_111 ( V_56 ) ;
F_112 ( V_172 ) ;
F_113 ( V_172 ) ;
}
static void F_114 ( struct V_160 * V_172 )
{
struct V_55 * V_56 = F_110 ( V_172 ) ;
int V_297 ;
if ( ! V_172 -> V_296 )
return;
V_297 = F_115 ( V_172 -> V_209 ) ;
if ( ( 128 << V_172 -> V_298 ) >= V_297 )
F_116 ( V_172 , V_297 ) ;
V_56 -> V_281 = F_115 ( V_172 ) ;
}
static int T_17 F_117 ( void )
{
int V_34 = - V_9 ;
V_34 = F_118 ( & V_299 ) ;
if ( ! V_34 )
F_92 ( L_67 ) ;
else
F_92 ( L_68 , V_34 ) ;
return V_34 ;
}
