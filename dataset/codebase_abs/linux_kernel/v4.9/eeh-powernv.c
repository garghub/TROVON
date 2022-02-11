static int F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
if ( ! F_2 ( V_5 ) ) {
F_3 ( L_1 ,
V_6 ) ;
return - V_7 ;
}
F_4 ( V_8 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 )
F_4 ( V_12 ) ;
if ( V_4 -> V_13 . V_14 != 0 )
F_4 ( V_15 ) ;
break;
}
return 0 ;
}
static T_1 F_6 ( int V_16 , void * V_17 )
{
F_7 ( V_16 ) ;
if ( F_8 () )
F_9 ( NULL ) ;
return V_18 ;
}
static T_2 F_10 ( struct V_19 * V_20 ,
const char T_3 * V_21 ,
T_4 V_22 , T_5 * V_23 )
{
struct V_1 * V_2 = V_20 -> V_9 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 , type , V_29 ;
unsigned long V_30 , V_31 ;
char V_32 [ 50 ] ;
int V_33 ;
if ( ! V_34 || ! V_34 -> V_35 )
return - V_36 ;
V_33 = F_11 ( V_32 , sizeof( V_32 ) , V_23 , V_21 , V_22 ) ;
if ( ! V_33 )
return - V_37 ;
V_33 = sscanf ( V_32 , L_2 ,
& V_28 , & type , & V_29 , & V_30 , & V_31 ) ;
if ( V_33 != 5 )
return - V_7 ;
V_25 = F_12 ( sizeof( * V_25 ) , V_38 ) ;
if ( ! V_25 )
return - V_39 ;
V_25 -> V_4 = V_2 ;
V_25 -> V_40 = V_28 ;
V_27 = F_13 ( V_25 ) ;
F_14 ( V_25 ) ;
if ( ! V_27 )
return - V_41 ;
V_33 = V_34 -> V_35 ( V_27 , type , V_29 , V_30 , V_31 ) ;
return V_33 < 0 ? V_33 : V_22 ;
}
static int F_15 ( void * V_17 , int V_42 , T_6 V_43 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 = V_2 -> V_9 ;
F_16 ( V_4 -> V_44 + V_42 , V_43 ) ;
return 0 ;
}
static int F_17 ( void * V_17 , int V_42 , T_6 * V_43 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 = V_2 -> V_9 ;
* V_43 = F_18 ( V_4 -> V_44 + V_42 ) ;
return 0 ;
}
static int F_19 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
if ( ! V_45 ) {
V_46 = F_20 ( F_21 ( V_47 ) ) ;
if ( V_46 < 0 ) {
F_22 ( L_3 ,
V_6 , V_46 ) ;
return V_46 ;
}
V_33 = F_23 ( V_46 , F_6 ,
V_48 , L_4 , NULL ) ;
if ( V_33 < 0 ) {
F_24 ( V_46 ) ;
F_22 ( L_5 ,
V_6 , V_46 ) ;
return V_33 ;
}
V_45 = true ;
}
if ( ! F_8 () )
F_25 ( V_46 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( F_8 () )
V_4 -> V_49 |= V_50 ;
else
V_4 -> V_49 &= ~ V_50 ;
#ifdef F_26
if ( V_4 -> V_51 || ! V_4 -> V_52 )
continue;
V_4 -> V_51 = 1 ;
F_27 ( L_6 , 0200 ,
V_4 -> V_52 , V_2 ,
& V_53 ) ;
F_27 ( L_7 , 0600 ,
V_4 -> V_52 , V_2 ,
& V_54 ) ;
F_27 ( L_8 , 0600 ,
V_4 -> V_52 , V_2 ,
& V_55 ) ;
F_27 ( L_9 , 0600 ,
V_4 -> V_52 , V_2 ,
& V_56 ) ;
#endif
}
return V_33 ;
}
static int F_28 ( struct V_57 * V_58 , int V_59 )
{
int V_60 = V_61 ;
int V_62 = 48 ;
T_7 V_63 , V_64 ;
if ( ! V_58 )
return 0 ;
F_29 ( V_58 , V_65 , 2 , & V_63 ) ;
if ( ! ( V_63 & V_66 ) )
return 0 ;
while ( V_62 -- ) {
F_29 ( V_58 , V_60 , 1 , & V_60 ) ;
if ( V_60 < 0x40 )
break;
V_60 &= ~ 3 ;
F_29 ( V_58 , V_60 + V_67 , 1 , & V_64 ) ;
if ( V_64 == 0xff )
break;
if ( V_64 == V_59 )
return V_60 ;
V_60 += V_68 ;
}
return 0 ;
}
static int F_30 ( struct V_57 * V_58 , int V_59 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_69 ;
int V_60 = 256 , V_70 = ( 4096 - 256 ) / 8 ;
if ( ! V_25 || ! V_25 -> V_71 )
return 0 ;
if ( F_29 ( V_58 , V_60 , 4 , & V_69 ) != V_72 )
return 0 ;
else if ( ! V_69 )
return 0 ;
while ( V_70 -- > 0 ) {
if ( F_32 ( V_69 ) == V_59 && V_60 )
return V_60 ;
V_60 = F_33 ( V_69 ) ;
if ( V_60 < 256 )
break;
if ( F_29 ( V_58 , V_60 , 4 , & V_69 ) != V_72 )
break;
}
return 0 ;
}
static void * F_34 ( struct V_57 * V_58 , void * V_17 )
{
struct V_1 * V_2 = V_58 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_8 V_73 ;
int V_33 ;
if ( ! V_25 || V_25 -> V_27 )
return NULL ;
if ( ( V_58 -> V_74 >> 8 ) == V_75 )
return NULL ;
V_25 -> V_74 = V_58 -> V_74 ;
V_25 -> V_76 &= 0xFFFFFF00 ;
V_25 -> V_77 = F_28 ( V_58 , V_78 ) ;
V_25 -> V_71 = F_28 ( V_58 , V_79 ) ;
V_25 -> V_80 = F_28 ( V_58 , V_81 ) ;
V_25 -> V_82 = F_30 ( V_58 , V_83 ) ;
if ( ( V_25 -> V_74 >> 8 ) == V_84 ) {
V_25 -> V_76 |= V_85 ;
if ( V_25 -> V_71 ) {
F_29 ( V_58 , V_25 -> V_71 + V_86 ,
2 , & V_73 ) ;
V_73 = ( V_73 & V_87 ) >> 4 ;
if ( V_73 == V_88 )
V_25 -> V_76 |= V_89 ;
else if ( V_73 == V_90 )
V_25 -> V_76 |= V_91 ;
}
}
V_25 -> V_92 = ( V_58 -> V_93 << 8 ) | ( V_58 -> V_94 ) ;
V_25 -> V_40 = V_4 -> V_13 . V_95 [ V_25 -> V_92 ] ;
V_33 = F_35 ( V_25 ) ;
if ( V_33 ) {
F_3 ( L_10 ,
V_6 , V_2 -> V_96 , V_58 -> V_93 ,
F_36 ( V_58 -> V_94 ) , F_37 ( V_58 -> V_94 ) , V_33 ) ;
return NULL ;
}
if ( ( V_58 -> V_97 == V_98 &&
V_58 -> V_99 == 0x1657 ) ||
( V_58 -> V_97 == V_98 &&
V_58 -> V_99 == 0x168a ) ||
( V_58 -> V_97 == V_98 &&
V_58 -> V_99 == 0x168e ) )
V_25 -> V_27 -> V_100 |= V_101 ;
if ( ! ( V_25 -> V_27 -> V_100 & V_102 ) ) {
V_25 -> V_27 -> V_103 = F_38 ( V_2 -> V_96 ,
V_58 -> V_93 ) ;
if ( V_25 -> V_27 -> V_103 )
V_25 -> V_27 -> V_100 |= V_102 ;
}
F_4 ( V_104 ) ;
F_39 ( V_25 ) ;
return NULL ;
}
static int F_40 ( struct V_26 * V_27 , int V_105 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
bool V_106 = false ;
int V_107 ;
T_9 V_108 ;
switch ( V_105 ) {
case V_109 :
return - V_110 ;
case V_111 :
return 0 ;
case V_112 :
V_107 = V_113 ;
break;
case V_114 :
V_107 = V_115 ;
break;
case V_116 :
V_106 = true ;
V_107 = V_117 ;
break;
default:
F_3 ( L_11 , V_6 , V_105 ) ;
return - V_7 ;
}
if ( V_106 ) {
if ( V_4 -> V_106 ) {
V_4 -> V_106 ( V_4 , V_27 -> V_30 ) ;
return 0 ;
}
V_108 = F_41 ( V_4 -> V_118 , V_27 -> V_30 , V_107 ) ;
if ( V_108 != V_119 ) {
F_3 ( L_12 ,
V_6 , V_108 , V_4 -> V_2 -> V_96 ,
V_27 -> V_30 ) ;
return - V_120 ;
}
return 0 ;
}
if ( V_4 -> V_121 )
return V_4 -> V_121 ( V_4 , V_27 -> V_30 , V_107 ) ;
V_108 = F_42 ( V_4 -> V_118 , V_27 -> V_30 , V_107 ) ;
if ( V_108 != V_119 ) {
F_3 ( L_13 ,
V_6 , V_108 , V_105 , V_4 -> V_2 -> V_96 ,
V_27 -> V_30 ) ;
return - V_120 ;
}
return 0 ;
}
static int F_43 ( struct V_26 * V_27 )
{
return V_27 -> V_30 ;
}
static void F_44 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_9 V_108 ;
V_108 = F_45 ( V_4 -> V_118 , V_27 -> V_17 ,
V_122 ) ;
if ( V_108 != V_119 )
F_3 ( L_14 ,
V_6 , V_108 , V_27 -> V_4 -> V_96 ) ;
}
static int F_46 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_10 V_123 ;
T_11 V_124 ;
T_9 V_108 ;
int V_125 = 0 ;
V_108 = F_47 ( V_4 -> V_118 ,
V_27 -> V_30 ,
& V_123 ,
& V_124 ,
NULL ) ;
if ( V_108 != V_119 ) {
F_3 ( L_15 ,
V_6 , V_108 , V_4 -> V_2 -> V_96 ) ;
return V_126 ;
}
if ( F_48 ( V_124 ) != V_127 ) {
V_125 = ( V_128 |
V_129 |
V_130 |
V_131 ) ;
} else if ( ! ( V_27 -> V_100 & V_132 ) ) {
F_49 ( V_27 , V_132 ) ;
F_44 ( V_27 ) ;
if ( F_50 ( V_133 ) )
F_51 ( V_27 -> V_4 , V_27 -> V_17 ) ;
}
return V_125 ;
}
static int F_52 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_10 V_123 ;
T_11 V_124 ;
T_9 V_108 ;
int V_125 ;
if ( V_27 -> V_100 & V_134 ) {
V_125 = ( V_128 |
V_129 |
V_130 |
V_131 ) ;
return V_125 ;
}
if ( V_4 -> V_135 ) {
V_123 = V_4 -> V_135 ( V_4 , V_27 -> V_30 ) ;
} else {
V_108 = F_47 ( V_4 -> V_118 ,
V_27 -> V_30 ,
& V_123 ,
& V_124 ,
NULL ) ;
if ( V_108 != V_119 ) {
F_3 ( L_16 ,
V_6 , V_108 , V_4 -> V_2 -> V_96 ,
V_27 -> V_30 ) ;
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
V_6 , V_4 -> V_2 -> V_96 ,
V_27 -> V_30 , V_123 ) ;
}
if ( ! ( V_125 & V_126 ) &&
! ( V_125 & V_143 ) &&
! ( V_125 & V_128 ) &&
! ( V_125 & V_129 ) &&
! ( V_27 -> V_100 & V_132 ) ) {
if ( V_4 -> V_106 )
V_4 -> V_106 ( V_4 , V_27 -> V_30 ) ;
F_49 ( V_27 , V_132 ) ;
F_44 ( V_27 ) ;
if ( F_50 ( V_133 ) )
F_51 ( V_27 -> V_4 , V_27 -> V_17 ) ;
}
return V_125 ;
}
static int F_53 ( struct V_26 * V_27 , int * V_145 )
{
int V_33 ;
if ( V_27 -> type & V_146 )
V_33 = F_46 ( V_27 ) ;
else
V_33 = F_52 ( V_27 ) ;
if ( ! V_145 )
return V_33 ;
* V_145 = 0 ;
if ( V_33 & V_143 )
* V_145 = 1000 ;
return V_33 ;
}
static T_9 F_54 ( unsigned long V_64 )
{
T_9 V_108 = V_147 ;
while ( 1 ) {
V_108 = F_55 ( V_64 ) ;
if ( V_108 <= 0 )
break;
if ( V_148 < V_149 )
F_56 ( 1000 * V_108 ) ;
else
F_57 ( V_108 ) ;
}
return V_108 ;
}
int F_58 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_108 = V_147 ;
F_59 ( L_18 ,
V_6 , V_2 -> V_96 , V_105 ) ;
if ( V_105 == V_150 ||
V_105 == V_151 )
V_108 = F_60 ( V_4 -> V_118 ,
V_152 ,
V_153 ) ;
else if ( V_105 == V_154 )
V_108 = F_60 ( V_4 -> V_118 ,
V_152 ,
V_155 ) ;
if ( V_108 < 0 )
goto V_156;
if ( V_108 > 0 )
V_108 = F_54 ( V_4 -> V_118 ) ;
if ( V_105 == V_154 ) {
if ( V_148 < V_149 )
F_56 ( 1000 * V_157 ) ;
else
F_57 ( V_157 ) ;
}
V_156:
if ( V_108 != V_119 )
return - V_120 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_105 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_108 = V_147 ;
F_59 ( L_18 ,
V_6 , V_2 -> V_96 , V_105 ) ;
if ( V_105 == V_150 )
V_108 = F_60 ( V_4 -> V_118 ,
V_158 ,
V_153 ) ;
else if ( V_105 == V_151 )
V_108 = F_60 ( V_4 -> V_118 ,
V_159 ,
V_153 ) ;
else if ( V_105 == V_154 )
V_108 = F_60 ( V_4 -> V_118 ,
V_159 ,
V_155 ) ;
if ( V_108 < 0 )
goto V_156;
if ( V_108 > 0 )
V_108 = F_54 ( V_4 -> V_118 ) ;
if ( V_105 == V_154 )
F_57 ( V_157 ) ;
V_156:
if ( V_108 != V_119 )
return - V_120 ;
return 0 ;
}
static int F_62 ( struct V_160 * V_161 , int V_105 )
{
struct V_57 * V_58 = F_63 ( V_161 -> V_103 , V_161 -> V_94 ) ;
struct V_24 * V_25 = F_31 ( V_58 ) ;
int V_162 = V_25 ? V_25 -> V_82 : 0 ;
T_7 V_163 ;
F_59 ( L_19 ,
V_6 , F_64 ( V_161 -> V_103 ) ,
V_161 -> V_103 -> V_164 , V_105 ) ;
switch ( V_105 ) {
case V_150 :
case V_151 :
if ( V_162 ) {
V_34 -> V_165 ( V_58 , V_162 + V_166 ,
4 , & V_163 ) ;
V_163 |= V_167 ;
V_34 -> V_168 ( V_58 , V_162 + V_166 ,
4 , V_163 ) ;
}
V_34 -> V_165 ( V_58 , V_169 , 2 , & V_163 ) ;
V_163 |= V_170 ;
V_34 -> V_168 ( V_58 , V_169 , 2 , V_163 ) ;
F_57 ( V_171 ) ;
break;
case V_154 :
V_34 -> V_165 ( V_58 , V_169 , 2 , & V_163 ) ;
V_163 &= ~ V_170 ;
V_34 -> V_168 ( V_58 , V_169 , 2 , V_163 ) ;
F_57 ( V_157 ) ;
if ( V_162 ) {
V_34 -> V_165 ( V_58 , V_162 + V_166 ,
4 , & V_163 ) ;
V_163 &= ~ V_167 ;
V_34 -> V_168 ( V_58 , V_162 + V_166 ,
4 , V_163 ) ;
}
break;
}
return 0 ;
}
static int F_65 ( struct V_160 * V_172 , int V_105 )
{
struct V_1 * V_2 = F_66 ( V_172 -> V_103 ) ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_173 * V_174 = F_67 ( V_172 ) ;
T_12 V_64 = F_68 ( V_4 -> V_118 ,
( V_172 -> V_103 -> V_164 << 8 ) | V_172 -> V_94 ) ;
T_13 V_175 ;
T_14 V_108 ;
if ( ! V_174 || ! F_69 ( V_174 , L_20 , NULL ) )
return F_62 ( V_172 , V_105 ) ;
switch ( V_105 ) {
case V_150 :
V_175 = V_158 ;
break;
case V_151 :
V_175 = V_159 ;
break;
case V_154 :
return 0 ;
default:
F_70 ( & V_172 -> V_161 , L_21 ,
V_6 , V_105 ) ;
return - V_7 ;
}
V_108 = F_60 ( V_64 , V_175 , V_153 ) ;
if ( V_108 <= V_119 )
goto V_156;
V_108 = F_54 ( V_64 ) ;
V_156:
return ( V_108 == V_119 ) ? 0 : - V_120 ;
}
void F_71 ( struct V_160 * V_161 )
{
struct V_1 * V_2 ;
if ( F_72 ( V_161 -> V_103 ) ) {
V_2 = F_66 ( V_161 -> V_103 ) ;
F_61 ( V_2 , V_151 ) ;
F_61 ( V_2 , V_154 ) ;
} else {
F_65 ( V_161 , V_151 ) ;
F_65 ( V_161 , V_154 ) ;
}
}
static void F_73 ( struct V_57 * V_58 , const char * type ,
int V_60 , T_15 V_31 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
int V_176 , V_63 = 0 ;
for ( V_176 = 0 ; V_176 < 4 ; V_176 ++ ) {
V_34 -> V_165 ( V_58 , V_60 , 2 , & V_63 ) ;
if ( ! ( V_63 & V_31 ) )
return;
F_57 ( ( 1 << V_176 ) * 100 ) ;
}
F_3 ( L_22 ,
V_6 , type ,
V_25 -> V_4 -> V_96 , V_58 -> V_93 ,
F_36 ( V_58 -> V_94 ) , F_37 ( V_58 -> V_94 ) ) ;
}
static int F_74 ( struct V_57 * V_58 , int V_105 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_177 = 0 ;
if ( F_75 ( ! V_25 -> V_71 ) )
return - V_178 ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_179 , 4 , & V_177 ) ;
if ( ! ( V_177 & V_180 ) )
return - V_178 ;
switch ( V_105 ) {
case V_151 :
case V_150 :
F_73 ( V_58 , L_23 ,
V_25 -> V_71 + V_181 ,
V_182 ) ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_183 ,
4 , & V_177 ) ;
V_177 |= V_184 ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_183 ,
4 , V_177 ) ;
F_57 ( V_171 ) ;
break;
case V_154 :
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_183 ,
4 , & V_177 ) ;
V_177 &= ~ V_184 ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_183 ,
4 , V_177 ) ;
F_57 ( V_157 ) ;
break;
}
return 0 ;
}
static int F_76 ( struct V_57 * V_58 , int V_105 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_59 = 0 ;
if ( F_75 ( ! V_25 -> V_80 ) )
return - V_178 ;
V_34 -> V_165 ( V_58 , V_25 -> V_80 + V_185 , 1 , & V_59 ) ;
if ( ! ( V_59 & V_186 ) || ! ( V_59 & V_187 ) )
return - V_178 ;
switch ( V_105 ) {
case V_151 :
case V_150 :
F_73 ( V_58 , L_24 ,
V_25 -> V_80 + V_188 ,
V_189 << 8 ) ;
V_34 -> V_168 ( V_58 , V_25 -> V_80 + V_188 ,
1 , V_190 ) ;
F_57 ( V_171 ) ;
break;
case V_154 :
V_34 -> V_168 ( V_58 , V_25 -> V_80 + V_188 , 1 , 0 ) ;
F_57 ( V_157 ) ;
break;
}
return 0 ;
}
static int F_77 ( struct V_26 * V_27 , int V_105 )
{
struct V_24 * V_25 ;
struct V_57 * V_58 ;
int V_33 ;
V_25 = F_78 ( & V_27 -> V_191 , struct V_24 , V_192 ) ;
V_58 = F_79 ( V_25 ) ;
if ( ! V_58 )
return - V_36 ;
V_33 = F_74 ( V_58 , V_105 ) ;
if ( ! V_33 )
return V_33 ;
return F_76 ( V_58 , V_105 ) ;
}
static int F_80 ( struct V_26 * V_27 , int V_105 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 ;
struct V_193 * V_103 ;
T_14 V_108 ;
if ( V_27 -> type & V_146 )
return F_58 ( V_2 , V_105 ) ;
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 &&
( V_105 == V_151 ||
V_105 == V_150 ) ) {
V_108 = F_60 ( V_4 -> V_118 ,
V_194 ,
V_153 ) ;
if ( V_108 != V_119 ) {
F_3 ( L_25 ,
V_6 , V_108 ) ;
return - V_120 ;
}
}
if ( V_27 -> type & V_195 )
return F_77 ( V_27 , V_105 ) ;
V_103 = F_81 ( V_27 ) ;
if ( ! V_103 ) {
F_22 ( L_26 ,
V_6 , V_27 -> V_4 -> V_96 , V_27 -> V_30 ) ;
return - V_120 ;
}
if ( F_72 ( V_103 ) ||
F_72 ( V_103 -> V_196 ) )
return F_61 ( V_2 , V_105 ) ;
return F_65 ( V_103 -> V_197 , V_105 ) ;
}
static int F_82 ( struct V_26 * V_27 , int V_198 )
{
int V_33 ;
int V_199 ;
while ( 1 ) {
V_33 = F_53 ( V_27 , & V_199 ) ;
if ( V_33 != V_143 )
return V_33 ;
if ( V_198 <= 0 ) {
F_3 ( L_27 ,
V_6 , V_27 -> V_30 , V_198 ) ;
return V_126 ;
}
V_198 -= V_199 ;
F_57 ( V_199 ) ;
}
return V_126 ;
}
static int F_83 ( struct V_26 * V_27 , int V_200 ,
char * V_201 , unsigned long V_202 )
{
if ( ! F_50 ( V_133 ) )
F_51 ( V_27 -> V_4 , V_27 -> V_17 ) ;
return 0 ;
}
static int F_84 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_85 ( struct V_26 * V_27 , int type , int V_29 ,
unsigned long V_30 , unsigned long V_31 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_108 ;
if ( type != V_203 &&
type != V_204 ) {
F_3 ( L_28 ,
V_6 , type ) ;
return - V_205 ;
}
if ( V_29 < V_206 ||
V_29 > V_207 ) {
F_3 ( L_29 ,
V_6 , V_29 ) ;
return - V_205 ;
}
if ( ! F_86 ( V_208 ) ) {
F_3 ( L_30 ,
V_6 ) ;
return - V_36 ;
}
V_108 = F_87 ( V_4 -> V_118 , V_27 -> V_30 ,
type , V_29 , V_30 , V_31 ) ;
if ( V_108 != V_119 ) {
F_3 ( L_31
L_32 ,
V_6 , V_108 , type , V_29 ,
V_2 -> V_96 , V_27 -> V_30 ) ;
return - V_120 ;
}
return 0 ;
}
static inline bool F_88 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
if ( ! V_25 || ! V_25 -> V_27 )
return false ;
if ( V_25 -> V_209 && ( V_25 -> V_27 -> V_100 & V_134 ) )
return false ;
if ( V_25 -> V_27 -> V_100 & V_210 )
return true ;
return false ;
}
static int F_89 ( struct V_57 * V_58 ,
int V_211 , int V_212 , T_7 * V_43 )
{
if ( ! V_58 )
return V_213 ;
if ( F_88 ( V_58 ) ) {
* V_43 = 0xFFFFFFFF ;
return V_214 ;
}
return F_29 ( V_58 , V_211 , V_212 , V_43 ) ;
}
static int F_90 ( struct V_57 * V_58 ,
int V_211 , int V_212 , T_7 V_43 )
{
if ( ! V_58 )
return V_213 ;
if ( F_88 ( V_58 ) )
return V_214 ;
return F_91 ( V_58 , V_211 , V_212 , V_43 ) ;
}
static void F_92 ( struct V_215 * V_17 )
{
if ( V_17 -> V_216 || V_17 -> V_217 ||
V_17 -> V_218 || V_17 -> V_219 || V_17 -> V_220 )
F_93 ( L_33 ,
F_94 ( V_17 -> V_216 ) ,
F_94 ( V_17 -> V_217 ) ,
F_94 ( V_17 -> V_218 ) ,
F_94 ( V_17 -> V_219 ) ,
F_94 ( V_17 -> V_220 ) ) ;
if ( V_17 -> V_221 || V_17 -> V_222 ||
V_17 -> V_223 || V_17 -> V_224 || V_17 -> V_225 )
F_93 ( L_34 ,
F_94 ( V_17 -> V_221 ) ,
F_94 ( V_17 -> V_222 ) ,
F_94 ( V_17 -> V_223 ) ,
F_94 ( V_17 -> V_224 ) ,
F_94 ( V_17 -> V_225 ) ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_215 * V_17 = & V_4 -> V_226 . V_227 ;
long V_108 ;
V_108 = F_96 ( V_4 -> V_228 , V_17 , sizeof( * V_17 ) ) ;
if ( V_108 != V_119 ) {
F_3 ( L_35 ,
V_6 , V_4 -> V_228 , V_108 ) ;
return;
}
switch ( F_48 ( V_17 -> type ) ) {
case V_229 :
F_93 ( L_36 ) ;
F_92 ( V_17 ) ;
if ( V_17 -> V_230 . V_231 || V_17 -> V_230 . V_232 )
F_93 ( L_37 ,
F_94 ( V_17 -> V_230 . V_231 ) ,
F_94 ( V_17 -> V_230 . V_232 ) ) ;
break;
case V_233 :
F_93 ( L_38 ,
V_17 -> V_234 . V_235 ? L_39 : L_40 ) ;
F_92 ( V_17 ) ;
if ( V_17 -> V_234 . V_236 || V_17 -> V_234 . V_237 ||
V_17 -> V_234 . V_238 || V_17 -> V_234 . V_239 )
F_93 ( L_41 ,
F_94 ( V_17 -> V_234 . V_236 ) ,
F_94 ( V_17 -> V_234 . V_237 ) ,
F_94 ( V_17 -> V_234 . V_238 ) ,
F_94 ( V_17 -> V_234 . V_239 ) ) ;
break;
case V_240 :
F_93 ( L_42 ,
V_17 -> V_241 . V_242 ) ;
F_92 ( V_17 ) ;
if ( V_17 -> V_241 . V_243 || V_17 -> V_241 . V_244 )
F_93 ( L_43 ,
F_94 ( V_17 -> V_241 . V_243 ) ,
F_94 ( V_17 -> V_241 . V_244 ) ) ;
break;
case V_245 :
F_93 ( L_44 ) ;
F_92 ( V_17 ) ;
break;
case V_246 :
F_93 ( L_45 ) ;
F_92 ( V_17 ) ;
break;
default:
F_3 ( L_46 ,
V_6 , V_4 -> V_228 , V_17 -> type ) ;
}
}
static int F_97 ( struct V_1 * V_2 ,
T_15 V_28 , struct V_26 * * V_27 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_247 * V_248 ;
struct V_26 * V_249 ;
struct V_24 V_25 ;
V_248 = & V_4 -> V_13 . V_250 [ V_28 ] ;
if ( V_248 -> V_49 & V_251 ) {
V_248 = V_248 -> V_252 ;
F_75 ( ! V_248 ||
! ( V_248 -> V_49 & V_253 ) ) ;
V_28 = V_248 -> V_254 ;
}
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 . V_4 = V_2 ;
V_25 . V_40 = V_28 ;
V_249 = F_13 ( & V_25 ) ;
if ( ! V_249 )
return - V_255 ;
* V_27 = V_249 ;
if ( ! ( V_249 -> V_100 & V_132 ) )
V_4 -> V_106 ( V_4 , V_28 ) ;
V_249 = V_249 -> V_196 ;
while ( V_249 && ! ( V_249 -> type & V_146 ) ) {
int V_33 ;
int V_256 = ( V_128 |
V_129 ) ;
V_33 = V_34 -> V_257 ( V_249 , NULL ) ;
if ( V_33 <= 0 || ( V_33 & V_256 ) == V_256 ) {
V_249 = V_249 -> V_196 ;
continue;
}
* V_27 = V_249 ;
if ( ! ( V_249 -> V_100 & V_132 ) )
V_4 -> V_106 ( V_4 , V_249 -> V_30 ) ;
V_249 = V_249 -> V_196 ;
}
return 0 ;
}
static int F_98 ( struct V_26 * * V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_26 * V_258 , * V_259 ;
T_16 V_260 ;
T_11 V_261 , V_200 ;
int V_256 = ( V_128 | V_129 ) ;
long V_108 ;
int V_100 , V_33 = V_262 ;
F_99 ( NULL , false ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
V_258 = F_100 ( V_2 ) ;
if ( ! V_258 || ( V_258 -> V_100 & V_132 ) )
continue;
V_108 = F_101 ( V_4 -> V_118 ,
& V_260 , & V_261 , & V_200 ) ;
if ( V_108 != V_119 ) {
F_102 ( L_47
L_48 ,
V_6 , V_2 -> V_96 , V_108 ) ;
continue;
}
if ( F_48 ( V_261 ) == V_263 ||
F_48 ( V_200 ) == V_264 ) {
F_102 ( L_49 ,
V_6 , V_2 -> V_96 ) ;
continue;
}
F_102 ( L_50 ,
V_6 , F_48 ( V_261 ) ,
F_48 ( V_200 ) , F_94 ( V_260 ) ,
V_2 -> V_96 ) ;
switch ( F_48 ( V_261 ) ) {
case V_265 :
if ( F_48 ( V_200 ) == V_266 ) {
F_22 ( L_51 ) ;
V_33 = V_267 ;
} else if ( F_48 ( V_200 ) == V_268 ) {
F_93 ( L_52
L_53 ) ;
F_95 ( V_2 ) ;
V_33 = V_262 ;
}
break;
case V_127 :
if ( F_48 ( V_200 ) == V_269 ) {
* V_27 = V_258 ;
F_22 ( L_54
L_55 ,
V_2 -> V_96 ,
F_103 ( V_258 ) ) ;
V_33 = V_270 ;
} else if ( F_48 ( V_200 ) ==
V_271 ) {
* V_27 = V_258 ;
F_22 ( L_56
L_55 ,
V_2 -> V_96 ,
F_103 ( V_258 ) ) ;
V_33 = V_272 ;
} else if ( F_48 ( V_200 ) == V_268 ) {
F_93 ( L_57
L_58 ,
V_2 -> V_96 ,
F_103 ( V_258 ) ) ;
F_44 ( V_258 ) ;
F_51 ( V_2 , V_258 -> V_17 ) ;
V_33 = V_262 ;
}
break;
case V_273 :
if ( F_97 ( V_2 ,
F_94 ( V_260 ) , V_27 ) ) {
F_93 ( L_59 ,
V_2 -> V_96 , F_94 ( V_260 ) ) ;
F_93 ( L_60 ,
F_103 ( V_258 ) ) ;
V_108 = F_45 ( V_4 -> V_118 ,
V_4 -> V_226 . V_274 , V_122 ) ;
if ( V_108 == V_119 )
F_51 ( V_2 ,
V_4 -> V_226 . V_274 ) ;
F_42 ( V_4 -> V_118 ,
F_94 ( V_260 ) ,
V_275 ) ;
V_33 = V_262 ;
} else if ( ( * V_27 ) -> V_100 & V_132 ||
F_104 ( * V_27 ) ) {
V_33 = V_262 ;
} else {
F_22 ( L_61
L_62 ,
( * V_27 ) -> V_30 ,
( * V_27 ) -> V_4 -> V_96 ) ;
F_22 ( L_63
L_64 ,
F_103 ( * V_27 ) ,
F_103 ( V_258 ) ) ;
V_33 = V_276 ;
}
break;
default:
F_3 ( L_65 ,
V_6 , F_48 ( V_261 ) ) ;
}
if ( ( V_33 == V_276 ||
V_33 == V_272 ) &&
! ( ( * V_27 ) -> V_100 & V_132 ) ) {
F_49 ( * V_27 , V_132 ) ;
F_44 ( * V_27 ) ;
if ( F_50 ( V_133 ) )
F_51 ( ( * V_27 ) -> V_4 ,
( * V_27 ) -> V_17 ) ;
}
if ( V_33 == V_276 ) {
V_259 = ( * V_27 ) -> V_196 ;
while ( V_259 ) {
if ( V_259 -> type & V_146 )
break;
V_100 = V_34 -> V_257 ( V_259 , NULL ) ;
if ( V_100 > 0 &&
( V_100 & V_256 ) != V_256 )
* V_27 = V_259 ;
V_259 = V_259 -> V_196 ;
}
F_49 ( * V_27 , V_132 ) ;
}
if ( V_33 > V_277 )
break;
}
if ( V_33 == V_262 && F_8 () )
F_105 ( V_46 ) ;
return V_33 ;
}
static int F_106 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_278 , V_279 , V_280 , V_281 ;
int V_282 ;
if ( V_25 -> V_71 ) {
V_282 = ( F_107 ( V_58 -> V_283 ) - 8 ) << 5 ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_183 ,
2 , & V_278 ) ;
V_278 &= ~ V_284 ;
V_278 |= V_282 ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_183 ,
2 , V_278 ) ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_285 ,
4 , & V_280 ) ;
if ( V_280 & 0x10 ) {
V_34 -> V_165 ( V_58 ,
V_25 -> V_71 + V_286 ,
4 , & V_280 ) ;
V_280 |= 0x10 ;
V_34 -> V_168 ( V_58 ,
V_25 -> V_71 + V_286 ,
4 , V_280 ) ;
}
}
V_34 -> V_165 ( V_58 , V_287 , 2 , & V_279 ) ;
V_279 |= ( V_288 | V_289 ) ;
V_34 -> V_168 ( V_58 , V_287 , 2 , V_279 ) ;
if ( V_25 -> V_71 ) {
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_183 ,
2 , & V_278 ) ;
V_278 &= ~ V_290 ;
V_278 |= ( V_291 |
V_292 |
V_293 ) ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_183 ,
2 , V_278 ) ;
}
if ( V_25 -> V_71 && V_25 -> V_82 ) {
V_34 -> V_165 ( V_58 , V_25 -> V_82 + V_294 ,
4 , & V_281 ) ;
V_281 |= ( V_295 | V_296 ) ;
V_34 -> V_168 ( V_58 , V_25 -> V_82 + V_294 ,
4 , V_281 ) ;
}
return 0 ;
}
static int F_108 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
struct V_3 * V_4 ;
T_9 V_33 ;
if ( ! V_25 )
return - V_255 ;
if ( V_25 -> V_209 ) {
V_33 = F_106 ( V_58 ) ;
} else {
V_4 = V_25 -> V_4 -> V_9 ;
V_33 = F_109 ( V_4 -> V_118 ,
V_297 , V_25 -> V_92 ) ;
}
if ( V_33 ) {
F_3 ( L_66 ,
V_6 , V_25 -> V_92 , V_33 ) ;
return - V_120 ;
}
return 0 ;
}
void F_110 ( struct V_160 * V_172 )
{
struct V_57 * V_58 = F_111 ( V_172 ) ;
if ( ! V_172 -> V_298 )
return;
F_112 ( V_58 ) ;
F_113 ( V_172 ) ;
F_114 ( V_172 ) ;
}
static void F_115 ( struct V_160 * V_172 )
{
struct V_57 * V_58 = F_111 ( V_172 ) ;
int V_299 ;
if ( ! V_172 -> V_298 )
return;
V_299 = F_116 ( V_172 -> V_209 ) ;
if ( ( 128 << V_172 -> V_300 ) >= V_299 )
F_117 ( V_172 , V_299 ) ;
V_58 -> V_283 = F_116 ( V_172 ) ;
}
static int T_17 F_118 ( void )
{
int V_33 = - V_7 ;
F_119 ( V_122 ) ;
V_33 = F_120 ( & V_301 ) ;
if ( ! V_33 )
F_93 ( L_67 ) ;
else
F_93 ( L_68 , V_33 ) ;
return V_33 ;
}
