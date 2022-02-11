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
struct V_29 * V_30 ;
int V_31 , type , V_32 ;
unsigned long V_33 , V_34 ;
char V_35 [ 50 ] ;
int V_36 ;
if ( ! V_37 || ! V_37 -> V_38 )
return - V_39 ;
V_36 = F_12 ( V_35 , sizeof( V_35 ) , V_26 , V_24 , V_25 ) ;
if ( ! V_36 )
return - V_40 ;
V_36 = sscanf ( V_35 , L_2 ,
& V_31 , & type , & V_32 , & V_33 , & V_34 ) ;
if ( V_36 != 5 )
return - V_9 ;
V_28 = F_13 ( sizeof( * V_28 ) , V_41 ) ;
if ( ! V_28 )
return - V_42 ;
V_28 -> V_4 = V_2 ;
V_28 -> V_43 = V_31 ;
V_30 = F_14 ( V_28 ) ;
F_15 ( V_28 ) ;
if ( ! V_30 )
return - V_44 ;
V_36 = V_37 -> V_38 ( V_30 , type , V_32 , V_33 , V_34 ) ;
return V_36 < 0 ? V_36 : V_25 ;
}
static int F_16 ( void * V_20 , int V_45 , T_6 V_46 )
{
struct V_1 * V_2 = V_20 ;
struct V_3 * V_4 = V_2 -> V_11 ;
F_17 ( V_4 -> V_47 + V_45 , V_46 ) ;
return 0 ;
}
static int F_18 ( void * V_20 , int V_45 , T_6 * V_46 )
{
struct V_1 * V_2 = V_20 ;
struct V_3 * V_4 = V_2 -> V_11 ;
* V_46 = F_19 ( V_4 -> V_47 + V_45 ) ;
return 0 ;
}
static int F_20 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_36 = 0 ;
if ( ! V_48 ) {
V_49 = F_21 ( F_22 ( V_50 ) ) ;
if ( V_49 < 0 ) {
F_23 ( L_3 ,
V_8 , V_49 ) ;
return V_49 ;
}
V_36 = F_24 ( V_49 , F_7 ,
V_51 , L_4 , NULL ) ;
if ( V_36 < 0 ) {
F_25 ( V_49 ) ;
F_23 ( L_5 ,
V_8 , V_49 ) ;
return V_36 ;
}
V_48 = true ;
}
if ( ! F_9 () )
F_26 ( V_49 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_11 ;
if ( F_9 () )
V_4 -> V_52 |= V_53 ;
else
V_4 -> V_52 &= ~ V_53 ;
#ifdef F_27
if ( V_4 -> V_54 || ! V_4 -> V_55 )
continue;
V_4 -> V_54 = 1 ;
F_28 ( L_6 , 0200 ,
V_4 -> V_55 , V_2 ,
& V_56 ) ;
F_28 ( L_7 , 0600 ,
V_4 -> V_55 , V_2 ,
& V_57 ) ;
F_28 ( L_8 , 0600 ,
V_4 -> V_55 , V_2 ,
& V_58 ) ;
F_28 ( L_9 , 0600 ,
V_4 -> V_55 , V_2 ,
& V_59 ) ;
#endif
}
return V_36 ;
}
static int F_29 ( struct V_60 * V_61 , int V_62 )
{
int V_63 = V_64 ;
int V_65 = 48 ;
T_7 V_66 , V_67 ;
if ( ! V_61 )
return 0 ;
F_30 ( V_61 , V_68 , 2 , & V_66 ) ;
if ( ! ( V_66 & V_69 ) )
return 0 ;
while ( V_65 -- ) {
F_30 ( V_61 , V_63 , 1 , & V_63 ) ;
if ( V_63 < 0x40 )
break;
V_63 &= ~ 3 ;
F_30 ( V_61 , V_63 + V_70 , 1 , & V_67 ) ;
if ( V_67 == 0xff )
break;
if ( V_67 == V_62 )
return V_63 ;
V_63 += V_71 ;
}
return 0 ;
}
static int F_31 ( struct V_60 * V_61 , int V_62 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
T_7 V_72 ;
int V_63 = 256 , V_73 = ( 4096 - 256 ) / 8 ;
if ( ! V_28 || ! V_28 -> V_74 )
return 0 ;
if ( F_30 ( V_61 , V_63 , 4 , & V_72 ) != V_75 )
return 0 ;
else if ( ! V_72 )
return 0 ;
while ( V_73 -- > 0 ) {
if ( F_33 ( V_72 ) == V_62 && V_63 )
return V_63 ;
V_63 = F_34 ( V_72 ) ;
if ( V_63 < 256 )
break;
if ( F_30 ( V_61 , V_63 , 4 , & V_72 ) != V_75 )
break;
}
return 0 ;
}
static void * F_35 ( struct V_60 * V_61 , void * V_20 )
{
struct V_1 * V_2 = V_61 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_27 * V_28 = F_32 ( V_61 ) ;
T_8 V_76 ;
int V_36 ;
if ( ! V_28 || V_28 -> V_30 )
return NULL ;
if ( ( V_61 -> V_77 >> 8 ) == V_78 )
return NULL ;
V_28 -> V_77 = V_61 -> V_77 ;
V_28 -> V_79 &= 0xFFFFFF00 ;
V_28 -> V_80 = F_29 ( V_61 , V_81 ) ;
V_28 -> V_74 = F_29 ( V_61 , V_82 ) ;
V_28 -> V_83 = F_29 ( V_61 , V_84 ) ;
V_28 -> V_85 = F_31 ( V_61 , V_86 ) ;
if ( ( V_28 -> V_77 >> 8 ) == V_87 ) {
V_28 -> V_79 |= V_88 ;
if ( V_28 -> V_74 ) {
F_30 ( V_61 , V_28 -> V_74 + V_89 ,
2 , & V_76 ) ;
V_76 = ( V_76 & V_90 ) >> 4 ;
if ( V_76 == V_91 )
V_28 -> V_79 |= V_92 ;
else if ( V_76 == V_93 )
V_28 -> V_79 |= V_94 ;
}
}
V_28 -> V_95 = ( V_61 -> V_96 << 8 ) | ( V_61 -> V_97 ) ;
V_28 -> V_43 = V_4 -> V_16 . V_98 [ V_28 -> V_95 ] ;
V_36 = F_36 ( V_28 ) ;
if ( V_36 ) {
F_3 ( L_10 ,
V_8 , V_2 -> V_99 , V_61 -> V_96 ,
F_37 ( V_61 -> V_97 ) , F_38 ( V_61 -> V_97 ) , V_36 ) ;
return NULL ;
}
if ( ( V_61 -> V_100 == V_101 &&
V_61 -> V_102 == 0x1656 ) ||
( V_61 -> V_100 == V_101 &&
V_61 -> V_102 == 0x1657 ) ||
( V_61 -> V_100 == V_101 &&
V_61 -> V_102 == 0x168a ) ||
( V_61 -> V_100 == V_101 &&
V_61 -> V_102 == 0x168e ) )
V_28 -> V_30 -> V_103 |= V_104 ;
if ( ! ( V_28 -> V_30 -> V_103 & V_105 ) ) {
V_28 -> V_30 -> V_106 = F_39 ( V_2 -> V_99 ,
V_61 -> V_96 ) ;
if ( V_28 -> V_30 -> V_106 )
V_28 -> V_30 -> V_103 |= V_105 ;
}
F_4 ( V_107 ) ;
F_40 ( V_28 ) ;
return NULL ;
}
static int F_41 ( struct V_29 * V_30 , int V_108 )
{
struct V_1 * V_2 = V_30 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_11 ;
bool V_109 = false ;
int V_110 ;
T_9 V_111 ;
switch ( V_108 ) {
case V_112 :
return - V_113 ;
case V_114 :
return 0 ;
case V_115 :
V_110 = V_116 ;
break;
case V_117 :
V_110 = V_118 ;
break;
case V_119 :
V_109 = true ;
V_110 = V_120 ;
break;
default:
F_3 ( L_11 , V_8 , V_108 ) ;
return - V_9 ;
}
if ( V_109 ) {
if ( V_4 -> V_109 ) {
V_4 -> V_109 ( V_4 , V_30 -> V_33 ) ;
return 0 ;
}
V_111 = F_42 ( V_4 -> V_121 , V_30 -> V_33 , V_110 ) ;
if ( V_111 != V_122 ) {
F_3 ( L_12 ,
V_8 , V_111 , V_4 -> V_2 -> V_99 ,
V_30 -> V_33 ) ;
return - V_123 ;
}
return 0 ;
}
if ( V_4 -> V_124 )
return V_4 -> V_124 ( V_4 , V_30 -> V_33 , V_110 ) ;
V_111 = F_43 ( V_4 -> V_121 , V_30 -> V_33 , V_110 ) ;
if ( V_111 != V_122 ) {
F_3 ( L_13 ,
V_8 , V_111 , V_108 , V_4 -> V_2 -> V_99 ,
V_30 -> V_33 ) ;
return - V_123 ;
}
return 0 ;
}
static int F_44 ( struct V_29 * V_30 )
{
return V_30 -> V_33 ;
}
static void F_45 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 -> V_11 ;
T_9 V_111 ;
V_111 = F_46 ( V_4 -> V_121 , V_30 -> V_20 ,
V_4 -> V_15 ) ;
if ( V_111 != V_122 )
F_3 ( L_14 ,
V_8 , V_111 , V_30 -> V_4 -> V_99 ) ;
}
static int F_47 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 -> V_11 ;
T_10 V_125 ;
T_11 V_126 ;
T_9 V_111 ;
int V_127 = 0 ;
V_111 = F_48 ( V_4 -> V_121 ,
V_30 -> V_33 ,
& V_125 ,
& V_126 ,
NULL ) ;
if ( V_111 != V_122 ) {
F_3 ( L_15 ,
V_8 , V_111 , V_4 -> V_2 -> V_99 ) ;
return V_128 ;
}
if ( F_49 ( V_126 ) != V_129 ) {
V_127 = ( V_130 |
V_131 |
V_132 |
V_133 ) ;
} else if ( ! ( V_30 -> V_103 & V_134 ) ) {
F_50 ( V_30 , V_134 ) ;
F_45 ( V_30 ) ;
if ( F_51 ( V_135 ) )
F_52 ( V_30 -> V_4 , V_30 -> V_20 ) ;
}
return V_127 ;
}
static int F_53 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 -> V_11 ;
T_10 V_125 ;
T_11 V_126 ;
T_9 V_111 ;
int V_127 ;
if ( V_30 -> V_103 & V_136 ) {
V_127 = ( V_130 |
V_131 |
V_132 |
V_133 ) ;
return V_127 ;
}
if ( V_4 -> V_137 ) {
V_125 = V_4 -> V_137 ( V_4 , V_30 -> V_33 ) ;
} else {
V_111 = F_48 ( V_4 -> V_121 ,
V_30 -> V_33 ,
& V_125 ,
& V_126 ,
NULL ) ;
if ( V_111 != V_122 ) {
F_3 ( L_16 ,
V_8 , V_111 , V_4 -> V_2 -> V_99 ,
V_30 -> V_33 ) ;
return V_128 ;
}
}
switch ( V_125 ) {
case V_138 :
V_127 = ( V_130 |
V_131 |
V_132 |
V_133 ) ;
break;
case V_139 :
V_127 = ( V_131 |
V_133 ) ;
break;
case V_140 :
V_127 = ( V_130 |
V_132 ) ;
break;
case V_141 :
V_127 = 0 ;
break;
case V_142 :
V_127 = V_143 ;
break;
case V_144 :
V_127 = V_145 ;
break;
case V_146 :
V_127 = V_128 ;
break;
default:
V_127 = V_128 ;
F_3 ( L_17 ,
V_8 , V_4 -> V_2 -> V_99 ,
V_30 -> V_33 , V_125 ) ;
}
if ( ! ( V_127 & V_128 ) &&
! ( V_127 & V_145 ) &&
! ( V_127 & V_130 ) &&
! ( V_127 & V_131 ) &&
! ( V_30 -> V_103 & V_134 ) ) {
if ( V_4 -> V_109 )
V_4 -> V_109 ( V_4 , V_30 -> V_33 ) ;
F_50 ( V_30 , V_134 ) ;
F_45 ( V_30 ) ;
if ( F_51 ( V_135 ) )
F_52 ( V_30 -> V_4 , V_30 -> V_20 ) ;
}
return V_127 ;
}
static int F_54 ( struct V_29 * V_30 , int * V_147 )
{
int V_36 ;
if ( V_30 -> type & V_148 )
V_36 = F_47 ( V_30 ) ;
else
V_36 = F_53 ( V_30 ) ;
if ( ! V_147 )
return V_36 ;
* V_147 = 0 ;
if ( V_36 & V_145 )
* V_147 = 1000 ;
return V_36 ;
}
static T_9 F_55 ( unsigned long V_67 )
{
T_9 V_111 = V_149 ;
while ( 1 ) {
V_111 = F_56 ( V_67 ) ;
if ( V_111 <= 0 )
break;
if ( V_150 < V_151 )
F_57 ( 1000 * V_111 ) ;
else
F_58 ( V_111 ) ;
}
return V_111 ;
}
int F_59 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
T_9 V_111 = V_149 ;
F_60 ( L_18 ,
V_8 , V_2 -> V_99 , V_108 ) ;
if ( V_108 == V_152 ||
V_108 == V_153 )
V_111 = F_61 ( V_4 -> V_121 ,
V_154 ,
V_155 ) ;
else if ( V_108 == V_156 )
V_111 = F_61 ( V_4 -> V_121 ,
V_154 ,
V_157 ) ;
if ( V_111 < 0 )
goto V_158;
if ( V_111 > 0 )
V_111 = F_55 ( V_4 -> V_121 ) ;
if ( V_108 == V_156 ) {
if ( V_150 < V_151 )
F_57 ( 1000 * V_159 ) ;
else
F_58 ( V_159 ) ;
}
V_158:
if ( V_111 != V_122 )
return - V_123 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_108 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
T_9 V_111 = V_149 ;
F_60 ( L_18 ,
V_8 , V_2 -> V_99 , V_108 ) ;
if ( V_108 == V_152 )
V_111 = F_61 ( V_4 -> V_121 ,
V_160 ,
V_155 ) ;
else if ( V_108 == V_153 )
V_111 = F_61 ( V_4 -> V_121 ,
V_161 ,
V_155 ) ;
else if ( V_108 == V_156 )
V_111 = F_61 ( V_4 -> V_121 ,
V_161 ,
V_157 ) ;
if ( V_111 < 0 )
goto V_158;
if ( V_111 > 0 )
V_111 = F_55 ( V_4 -> V_121 ) ;
if ( V_108 == V_156 )
F_58 ( V_159 ) ;
V_158:
if ( V_111 != V_122 )
return - V_123 ;
return 0 ;
}
static int F_63 ( struct V_162 * V_163 , int V_108 )
{
struct V_60 * V_61 = F_64 ( V_163 -> V_106 , V_163 -> V_97 ) ;
struct V_27 * V_28 = F_32 ( V_61 ) ;
int V_164 = V_28 ? V_28 -> V_85 : 0 ;
T_7 V_165 ;
F_60 ( L_19 ,
V_8 , F_65 ( V_163 -> V_106 ) ,
V_163 -> V_106 -> V_166 , V_108 ) ;
switch ( V_108 ) {
case V_152 :
case V_153 :
if ( V_164 ) {
V_37 -> V_167 ( V_61 , V_164 + V_168 ,
4 , & V_165 ) ;
V_165 |= V_169 ;
V_37 -> V_170 ( V_61 , V_164 + V_168 ,
4 , V_165 ) ;
}
V_37 -> V_167 ( V_61 , V_171 , 2 , & V_165 ) ;
V_165 |= V_172 ;
V_37 -> V_170 ( V_61 , V_171 , 2 , V_165 ) ;
F_58 ( V_173 ) ;
break;
case V_156 :
V_37 -> V_167 ( V_61 , V_171 , 2 , & V_165 ) ;
V_165 &= ~ V_172 ;
V_37 -> V_170 ( V_61 , V_171 , 2 , V_165 ) ;
F_58 ( V_159 ) ;
if ( V_164 ) {
V_37 -> V_167 ( V_61 , V_164 + V_168 ,
4 , & V_165 ) ;
V_165 &= ~ V_169 ;
V_37 -> V_170 ( V_61 , V_164 + V_168 ,
4 , V_165 ) ;
}
break;
}
return 0 ;
}
static int F_66 ( struct V_162 * V_174 , int V_108 )
{
struct V_1 * V_2 = F_67 ( V_174 -> V_106 ) ;
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_175 * V_176 = F_68 ( V_174 ) ;
T_12 V_67 = F_69 ( V_4 -> V_121 ,
( V_174 -> V_106 -> V_166 << 8 ) | V_174 -> V_97 ) ;
T_13 V_177 ;
T_14 V_111 ;
if ( ! V_176 || ! F_70 ( V_176 , L_20 , NULL ) )
return F_63 ( V_174 , V_108 ) ;
switch ( V_108 ) {
case V_152 :
V_177 = V_160 ;
break;
case V_153 :
V_177 = V_161 ;
break;
case V_156 :
return 0 ;
default:
F_71 ( & V_174 -> V_163 , L_21 ,
V_8 , V_108 ) ;
return - V_9 ;
}
V_111 = F_61 ( V_67 , V_177 , V_155 ) ;
if ( V_111 <= V_122 )
goto V_158;
V_111 = F_55 ( V_67 ) ;
V_158:
return ( V_111 == V_122 ) ? 0 : - V_123 ;
}
void F_72 ( struct V_162 * V_163 )
{
struct V_1 * V_2 ;
if ( F_73 ( V_163 -> V_106 ) ) {
V_2 = F_67 ( V_163 -> V_106 ) ;
F_62 ( V_2 , V_153 ) ;
F_62 ( V_2 , V_156 ) ;
} else {
F_66 ( V_163 , V_153 ) ;
F_66 ( V_163 , V_156 ) ;
}
}
static void F_74 ( struct V_60 * V_61 , const char * type ,
int V_63 , T_15 V_34 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
int V_178 , V_66 = 0 ;
for ( V_178 = 0 ; V_178 < 4 ; V_178 ++ ) {
V_37 -> V_167 ( V_61 , V_63 , 2 , & V_66 ) ;
if ( ! ( V_66 & V_34 ) )
return;
F_58 ( ( 1 << V_178 ) * 100 ) ;
}
F_3 ( L_22 ,
V_8 , type ,
V_28 -> V_4 -> V_99 , V_61 -> V_96 ,
F_37 ( V_61 -> V_97 ) , F_38 ( V_61 -> V_97 ) ) ;
}
static int F_75 ( struct V_60 * V_61 , int V_108 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
T_7 V_179 = 0 ;
if ( F_76 ( ! V_28 -> V_74 ) )
return - V_180 ;
V_37 -> V_167 ( V_61 , V_28 -> V_74 + V_181 , 4 , & V_179 ) ;
if ( ! ( V_179 & V_182 ) )
return - V_180 ;
switch ( V_108 ) {
case V_153 :
case V_152 :
F_74 ( V_61 , L_23 ,
V_28 -> V_74 + V_183 ,
V_184 ) ;
V_37 -> V_167 ( V_61 , V_28 -> V_74 + V_185 ,
4 , & V_179 ) ;
V_179 |= V_186 ;
V_37 -> V_170 ( V_61 , V_28 -> V_74 + V_185 ,
4 , V_179 ) ;
F_58 ( V_173 ) ;
break;
case V_156 :
V_37 -> V_167 ( V_61 , V_28 -> V_74 + V_185 ,
4 , & V_179 ) ;
V_179 &= ~ V_186 ;
V_37 -> V_170 ( V_61 , V_28 -> V_74 + V_185 ,
4 , V_179 ) ;
F_58 ( V_159 ) ;
break;
}
return 0 ;
}
static int F_77 ( struct V_60 * V_61 , int V_108 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
T_7 V_62 = 0 ;
if ( F_76 ( ! V_28 -> V_83 ) )
return - V_180 ;
V_37 -> V_167 ( V_61 , V_28 -> V_83 + V_187 , 1 , & V_62 ) ;
if ( ! ( V_62 & V_188 ) || ! ( V_62 & V_189 ) )
return - V_180 ;
switch ( V_108 ) {
case V_153 :
case V_152 :
F_74 ( V_61 , L_24 ,
V_28 -> V_83 + V_190 ,
V_191 << 8 ) ;
V_37 -> V_170 ( V_61 , V_28 -> V_83 + V_190 ,
1 , V_192 ) ;
F_58 ( V_173 ) ;
break;
case V_156 :
V_37 -> V_170 ( V_61 , V_28 -> V_83 + V_190 , 1 , 0 ) ;
F_58 ( V_159 ) ;
break;
}
return 0 ;
}
static int F_78 ( struct V_29 * V_30 , int V_108 )
{
struct V_27 * V_28 ;
struct V_60 * V_61 ;
int V_36 ;
V_28 = F_79 ( & V_30 -> V_193 , struct V_27 , V_194 ) ;
V_61 = F_80 ( V_28 ) ;
if ( ! V_61 )
return - V_39 ;
V_36 = F_75 ( V_61 , V_108 ) ;
if ( ! V_36 )
return V_36 ;
return F_77 ( V_61 , V_108 ) ;
}
static int F_81 ( struct V_29 * V_30 , int V_108 )
{
struct V_1 * V_2 = V_30 -> V_4 ;
struct V_3 * V_4 ;
struct V_195 * V_106 ;
T_14 V_111 ;
if ( V_30 -> type & V_148 )
return F_59 ( V_2 , V_108 ) ;
V_4 = V_2 -> V_11 ;
if ( V_4 -> V_12 == V_13 &&
( V_108 == V_153 ||
V_108 == V_152 ) ) {
V_111 = F_61 ( V_4 -> V_121 ,
V_196 ,
V_155 ) ;
if ( V_111 != V_122 ) {
F_3 ( L_25 ,
V_8 , V_111 ) ;
return - V_123 ;
}
}
if ( V_30 -> type & V_197 )
return F_78 ( V_30 , V_108 ) ;
V_106 = F_82 ( V_30 ) ;
if ( ! V_106 ) {
F_23 ( L_26 ,
V_8 , V_30 -> V_4 -> V_99 , V_30 -> V_33 ) ;
return - V_123 ;
}
if ( F_73 ( V_106 ) ||
F_73 ( V_106 -> V_198 ) )
return F_62 ( V_2 , V_108 ) ;
return F_66 ( V_106 -> V_199 , V_108 ) ;
}
static int F_83 ( struct V_29 * V_30 , int V_200 )
{
int V_36 ;
int V_201 ;
while ( 1 ) {
V_36 = F_54 ( V_30 , & V_201 ) ;
if ( V_36 != V_145 )
return V_36 ;
if ( V_200 <= 0 ) {
F_3 ( L_27 ,
V_8 , V_30 -> V_33 , V_200 ) ;
return V_128 ;
}
V_200 -= V_201 ;
F_58 ( V_201 ) ;
}
return V_128 ;
}
static int F_84 ( struct V_29 * V_30 , int V_202 ,
char * V_203 , unsigned long V_204 )
{
if ( ! F_51 ( V_135 ) )
F_52 ( V_30 -> V_4 , V_30 -> V_20 ) ;
return 0 ;
}
static int F_85 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_86 ( struct V_29 * V_30 , int type , int V_32 ,
unsigned long V_33 , unsigned long V_34 )
{
struct V_1 * V_2 = V_30 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_11 ;
T_9 V_111 ;
if ( type != V_205 &&
type != V_206 ) {
F_3 ( L_28 ,
V_8 , type ) ;
return - V_207 ;
}
if ( V_32 < V_208 ||
V_32 > V_209 ) {
F_3 ( L_29 ,
V_8 , V_32 ) ;
return - V_207 ;
}
if ( ! F_87 ( V_210 ) ) {
F_3 ( L_30 ,
V_8 ) ;
return - V_39 ;
}
V_111 = F_88 ( V_4 -> V_121 , V_30 -> V_33 ,
type , V_32 , V_33 , V_34 ) ;
if ( V_111 != V_122 ) {
F_3 ( L_31
L_32 ,
V_8 , V_111 , type , V_32 ,
V_2 -> V_99 , V_30 -> V_33 ) ;
return - V_123 ;
}
return 0 ;
}
static inline bool F_89 ( struct V_60 * V_61 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
if ( ! V_28 || ! V_28 -> V_30 )
return false ;
if ( V_28 -> V_211 && ( V_28 -> V_30 -> V_103 & V_136 ) )
return false ;
if ( V_28 -> V_30 -> V_103 & V_212 )
return true ;
return false ;
}
static int F_90 ( struct V_60 * V_61 ,
int V_213 , int V_214 , T_7 * V_46 )
{
if ( ! V_61 )
return V_215 ;
if ( F_89 ( V_61 ) ) {
* V_46 = 0xFFFFFFFF ;
return V_216 ;
}
return F_30 ( V_61 , V_213 , V_214 , V_46 ) ;
}
static int F_91 ( struct V_60 * V_61 ,
int V_213 , int V_214 , T_7 V_46 )
{
if ( ! V_61 )
return V_215 ;
if ( F_89 ( V_61 ) )
return V_216 ;
return F_92 ( V_61 , V_213 , V_214 , V_46 ) ;
}
static void F_93 ( struct V_217 * V_20 )
{
if ( V_20 -> V_218 || V_20 -> V_219 ||
V_20 -> V_220 || V_20 -> V_221 || V_20 -> V_222 )
F_94 ( L_33 ,
F_95 ( V_20 -> V_218 ) ,
F_95 ( V_20 -> V_219 ) ,
F_95 ( V_20 -> V_220 ) ,
F_95 ( V_20 -> V_221 ) ,
F_95 ( V_20 -> V_222 ) ) ;
if ( V_20 -> V_223 || V_20 -> V_224 ||
V_20 -> V_225 || V_20 -> V_226 || V_20 -> V_227 )
F_94 ( L_34 ,
F_95 ( V_20 -> V_223 ) ,
F_95 ( V_20 -> V_224 ) ,
F_95 ( V_20 -> V_225 ) ,
F_95 ( V_20 -> V_226 ) ,
F_95 ( V_20 -> V_227 ) ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_217 * V_20 =
(struct V_217 * ) V_4 -> V_228 ;
long V_111 ;
V_111 = F_97 ( V_4 -> V_229 , V_20 , sizeof( * V_20 ) ) ;
if ( V_111 != V_122 ) {
F_3 ( L_35 ,
V_8 , V_4 -> V_229 , V_111 ) ;
return;
}
switch ( F_49 ( V_20 -> type ) ) {
case V_230 :
F_94 ( L_36 ) ;
F_93 ( V_20 ) ;
if ( V_20 -> V_231 . V_232 || V_20 -> V_231 . V_233 )
F_94 ( L_37 ,
F_95 ( V_20 -> V_231 . V_232 ) ,
F_95 ( V_20 -> V_231 . V_233 ) ) ;
break;
case V_234 :
F_94 ( L_38 ,
V_20 -> V_235 . V_236 ? L_39 : L_40 ) ;
F_93 ( V_20 ) ;
if ( V_20 -> V_235 . V_237 || V_20 -> V_235 . V_238 ||
V_20 -> V_235 . V_239 || V_20 -> V_235 . V_240 )
F_94 ( L_41 ,
F_95 ( V_20 -> V_235 . V_237 ) ,
F_95 ( V_20 -> V_235 . V_238 ) ,
F_95 ( V_20 -> V_235 . V_239 ) ,
F_95 ( V_20 -> V_235 . V_240 ) ) ;
break;
case V_241 :
F_94 ( L_42 ,
V_20 -> V_242 . V_243 ) ;
F_93 ( V_20 ) ;
if ( V_20 -> V_242 . V_244 || V_20 -> V_242 . V_245 )
F_94 ( L_43 ,
F_95 ( V_20 -> V_242 . V_244 ) ,
F_95 ( V_20 -> V_242 . V_245 ) ) ;
break;
case V_246 :
F_94 ( L_44 ) ;
F_93 ( V_20 ) ;
break;
case V_247 :
F_94 ( L_45 ) ;
F_93 ( V_20 ) ;
break;
default:
F_3 ( L_46 ,
V_8 , V_4 -> V_229 , V_20 -> type ) ;
}
}
static int F_98 ( struct V_1 * V_2 ,
T_15 V_31 , struct V_29 * * V_30 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_248 * V_249 ;
struct V_29 * V_250 ;
struct V_27 V_28 ;
V_249 = & V_4 -> V_16 . V_251 [ V_31 ] ;
if ( V_249 -> V_52 & V_252 ) {
V_249 = V_249 -> V_253 ;
F_76 ( ! V_249 ||
! ( V_249 -> V_52 & V_254 ) ) ;
V_31 = V_249 -> V_255 ;
}
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_4 = V_2 ;
V_28 . V_43 = V_31 ;
V_250 = F_14 ( & V_28 ) ;
if ( ! V_250 )
return - V_256 ;
* V_30 = V_250 ;
if ( ! ( V_250 -> V_103 & V_134 ) )
V_4 -> V_109 ( V_4 , V_31 ) ;
V_250 = V_250 -> V_198 ;
while ( V_250 && ! ( V_250 -> type & V_148 ) ) {
int V_36 ;
int V_257 = ( V_130 |
V_131 ) ;
V_36 = V_37 -> V_258 ( V_250 , NULL ) ;
if ( V_36 <= 0 || ( V_36 & V_257 ) == V_257 ) {
V_250 = V_250 -> V_198 ;
continue;
}
* V_30 = V_250 ;
if ( ! ( V_250 -> V_103 & V_134 ) )
V_4 -> V_109 ( V_4 , V_250 -> V_33 ) ;
V_250 = V_250 -> V_198 ;
}
return 0 ;
}
static int F_99 ( struct V_29 * * V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_29 * V_259 , * V_260 ;
T_16 V_261 ;
T_11 V_262 , V_202 ;
int V_257 = ( V_130 | V_131 ) ;
long V_111 ;
int V_103 , V_36 = V_263 ;
F_100 ( NULL , false ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_11 ;
V_259 = F_101 ( V_2 ) ;
if ( ! V_259 || ( V_259 -> V_103 & V_134 ) )
continue;
V_111 = F_102 ( V_4 -> V_121 ,
& V_261 , & V_262 , & V_202 ) ;
if ( V_111 != V_122 ) {
F_103 ( L_47
L_48 ,
V_8 , V_2 -> V_99 , V_111 ) ;
continue;
}
if ( F_49 ( V_262 ) == V_264 ||
F_49 ( V_202 ) == V_265 ) {
F_103 ( L_49 ,
V_8 , V_2 -> V_99 ) ;
continue;
}
F_103 ( L_50 ,
V_8 , F_49 ( V_262 ) ,
F_49 ( V_202 ) , F_95 ( V_261 ) ,
V_2 -> V_99 ) ;
switch ( F_49 ( V_262 ) ) {
case V_266 :
if ( F_49 ( V_202 ) == V_267 ) {
F_23 ( L_51 ) ;
V_36 = V_268 ;
} else if ( F_49 ( V_202 ) == V_269 ) {
F_94 ( L_52
L_53 ) ;
F_96 ( V_2 ) ;
V_36 = V_263 ;
}
break;
case V_129 :
if ( F_49 ( V_202 ) == V_270 ) {
* V_30 = V_259 ;
F_23 ( L_54
L_55 ,
V_2 -> V_99 ,
F_104 ( V_259 ) ) ;
V_36 = V_271 ;
} else if ( F_49 ( V_202 ) ==
V_272 ) {
* V_30 = V_259 ;
F_23 ( L_56
L_55 ,
V_2 -> V_99 ,
F_104 ( V_259 ) ) ;
V_36 = V_273 ;
} else if ( F_49 ( V_202 ) == V_269 ) {
F_94 ( L_57
L_58 ,
V_2 -> V_99 ,
F_104 ( V_259 ) ) ;
F_45 ( V_259 ) ;
F_52 ( V_2 , V_259 -> V_20 ) ;
V_36 = V_263 ;
}
break;
case V_274 :
if ( F_98 ( V_2 ,
F_95 ( V_261 ) , V_30 ) ) {
F_94 ( L_59 ,
V_2 -> V_99 , F_95 ( V_261 ) ) ;
F_94 ( L_60 ,
F_104 ( V_259 ) ) ;
V_111 = F_46 ( V_4 -> V_121 ,
V_4 -> V_228 , V_4 -> V_15 ) ;
if ( V_111 == V_122 )
F_52 ( V_2 ,
V_4 -> V_228 ) ;
F_43 ( V_4 -> V_121 ,
F_95 ( V_261 ) ,
V_275 ) ;
V_36 = V_263 ;
} else if ( ( * V_30 ) -> V_103 & V_134 ||
F_105 ( * V_30 ) ) {
V_36 = V_263 ;
} else {
F_23 ( L_61
L_62 ,
( * V_30 ) -> V_33 ,
( * V_30 ) -> V_4 -> V_99 ) ;
F_23 ( L_63
L_64 ,
F_104 ( * V_30 ) ,
F_104 ( V_259 ) ) ;
V_36 = V_276 ;
}
break;
default:
F_3 ( L_65 ,
V_8 , F_49 ( V_262 ) ) ;
}
if ( ( V_36 == V_276 ||
V_36 == V_273 ) &&
! ( ( * V_30 ) -> V_103 & V_134 ) ) {
F_50 ( * V_30 , V_134 ) ;
F_45 ( * V_30 ) ;
if ( F_51 ( V_135 ) )
F_52 ( ( * V_30 ) -> V_4 ,
( * V_30 ) -> V_20 ) ;
}
if ( V_36 == V_276 ) {
V_260 = ( * V_30 ) -> V_198 ;
while ( V_260 ) {
if ( V_260 -> type & V_148 )
break;
V_103 = V_37 -> V_258 ( V_260 , NULL ) ;
if ( V_103 > 0 &&
( V_103 & V_257 ) != V_257 )
* V_30 = V_260 ;
V_260 = V_260 -> V_198 ;
}
F_50 ( * V_30 , V_134 ) ;
}
if ( V_36 > V_277 )
break;
}
if ( V_36 == V_263 && F_9 () )
F_106 ( V_49 ) ;
return V_36 ;
}
static int F_107 ( struct V_60 * V_61 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
T_7 V_278 , V_279 , V_280 , V_281 ;
int V_282 ;
if ( V_28 -> V_74 ) {
V_282 = ( F_108 ( V_61 -> V_283 ) - 8 ) << 5 ;
V_37 -> V_167 ( V_61 , V_28 -> V_74 + V_185 ,
2 , & V_278 ) ;
V_278 &= ~ V_284 ;
V_278 |= V_282 ;
V_37 -> V_170 ( V_61 , V_28 -> V_74 + V_185 ,
2 , V_278 ) ;
V_37 -> V_167 ( V_61 , V_28 -> V_74 + V_285 ,
4 , & V_280 ) ;
if ( V_280 & 0x10 ) {
V_37 -> V_167 ( V_61 ,
V_28 -> V_74 + V_286 ,
4 , & V_280 ) ;
V_280 |= 0x10 ;
V_37 -> V_170 ( V_61 ,
V_28 -> V_74 + V_286 ,
4 , V_280 ) ;
}
}
V_37 -> V_167 ( V_61 , V_287 , 2 , & V_279 ) ;
V_279 |= ( V_288 | V_289 ) ;
V_37 -> V_170 ( V_61 , V_287 , 2 , V_279 ) ;
if ( V_28 -> V_74 ) {
V_37 -> V_167 ( V_61 , V_28 -> V_74 + V_185 ,
2 , & V_278 ) ;
V_278 &= ~ V_290 ;
V_278 |= ( V_291 |
V_292 |
V_293 ) ;
V_37 -> V_170 ( V_61 , V_28 -> V_74 + V_185 ,
2 , V_278 ) ;
}
if ( V_28 -> V_74 && V_28 -> V_85 ) {
V_37 -> V_167 ( V_61 , V_28 -> V_85 + V_294 ,
4 , & V_281 ) ;
V_281 |= ( V_295 | V_296 ) ;
V_37 -> V_170 ( V_61 , V_28 -> V_85 + V_294 ,
4 , V_281 ) ;
}
return 0 ;
}
static int F_109 ( struct V_60 * V_61 )
{
struct V_27 * V_28 = F_32 ( V_61 ) ;
struct V_3 * V_4 ;
T_9 V_36 ;
if ( ! V_28 )
return - V_256 ;
if ( V_28 -> V_211 ) {
V_36 = F_107 ( V_61 ) ;
} else {
V_4 = V_28 -> V_4 -> V_11 ;
V_36 = F_110 ( V_4 -> V_121 ,
V_297 , V_28 -> V_95 ) ;
}
if ( V_36 ) {
F_3 ( L_66 ,
V_8 , V_28 -> V_95 , V_36 ) ;
return - V_123 ;
}
return 0 ;
}
void F_111 ( struct V_162 * V_174 )
{
struct V_60 * V_61 = F_112 ( V_174 ) ;
if ( ! V_174 -> V_298 )
return;
F_113 ( V_61 ) ;
F_114 ( V_174 ) ;
F_115 ( V_174 ) ;
}
static void F_116 ( struct V_162 * V_174 )
{
struct V_60 * V_61 = F_112 ( V_174 ) ;
int V_299 ;
if ( ! V_174 -> V_298 )
return;
V_299 = F_117 ( V_174 -> V_211 ) ;
if ( ( 128 << V_174 -> V_300 ) >= V_299 )
F_118 ( V_174 , V_299 ) ;
V_61 -> V_283 = F_117 ( V_174 ) ;
}
static int T_17 F_119 ( void )
{
int V_36 = - V_9 ;
V_36 = F_120 ( & V_301 ) ;
if ( ! V_36 )
F_94 ( L_67 ) ;
else
F_94 ( L_68 , V_36 ) ;
return V_36 ;
}
