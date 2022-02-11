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
static T_9 F_54 ( struct V_3 * V_4 )
{
T_9 V_108 = V_147 ;
while ( 1 ) {
V_108 = F_55 ( V_4 -> V_118 ) ;
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
V_108 = F_54 ( V_4 ) ;
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
V_108 = F_54 ( V_4 ) ;
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
void F_65 ( struct V_160 * V_161 )
{
struct V_1 * V_2 ;
if ( F_66 ( V_161 -> V_103 ) ) {
V_2 = F_67 ( V_161 -> V_103 ) ;
F_61 ( V_2 , V_151 ) ;
F_61 ( V_2 , V_154 ) ;
} else {
F_62 ( V_161 , V_151 ) ;
F_62 ( V_161 , V_154 ) ;
}
}
static void F_68 ( struct V_57 * V_58 , const char * type ,
int V_60 , T_12 V_31 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
int V_172 , V_63 = 0 ;
for ( V_172 = 0 ; V_172 < 4 ; V_172 ++ ) {
V_34 -> V_165 ( V_58 , V_60 , 2 , & V_63 ) ;
if ( ! ( V_63 & V_31 ) )
return;
F_57 ( ( 1 << V_172 ) * 100 ) ;
}
F_3 ( L_20 ,
V_6 , type ,
V_25 -> V_4 -> V_96 , V_58 -> V_93 ,
F_36 ( V_58 -> V_94 ) , F_37 ( V_58 -> V_94 ) ) ;
}
static int F_69 ( struct V_57 * V_58 , int V_105 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_173 = 0 ;
if ( F_70 ( ! V_25 -> V_71 ) )
return - V_174 ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_175 , 4 , & V_173 ) ;
if ( ! ( V_173 & V_176 ) )
return - V_174 ;
switch ( V_105 ) {
case V_151 :
case V_150 :
F_68 ( V_58 , L_21 ,
V_25 -> V_71 + V_177 ,
V_178 ) ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_179 ,
4 , & V_173 ) ;
V_173 |= V_180 ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_179 ,
4 , V_173 ) ;
F_57 ( V_171 ) ;
break;
case V_154 :
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_179 ,
4 , & V_173 ) ;
V_173 &= ~ V_180 ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_179 ,
4 , V_173 ) ;
F_57 ( V_157 ) ;
break;
}
return 0 ;
}
static int F_71 ( struct V_57 * V_58 , int V_105 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_59 = 0 ;
if ( F_70 ( ! V_25 -> V_80 ) )
return - V_174 ;
V_34 -> V_165 ( V_58 , V_25 -> V_80 + V_181 , 1 , & V_59 ) ;
if ( ! ( V_59 & V_182 ) || ! ( V_59 & V_183 ) )
return - V_174 ;
switch ( V_105 ) {
case V_151 :
case V_150 :
F_68 ( V_58 , L_22 ,
V_25 -> V_80 + V_184 ,
V_185 << 8 ) ;
V_34 -> V_168 ( V_58 , V_25 -> V_80 + V_184 ,
1 , V_186 ) ;
F_57 ( V_171 ) ;
break;
case V_154 :
V_34 -> V_168 ( V_58 , V_25 -> V_80 + V_184 , 1 , 0 ) ;
F_57 ( V_157 ) ;
break;
}
return 0 ;
}
static int F_72 ( struct V_26 * V_27 , int V_105 )
{
struct V_24 * V_25 ;
struct V_57 * V_58 ;
int V_33 ;
V_25 = F_73 ( & V_27 -> V_187 , struct V_24 , V_188 ) ;
V_58 = F_74 ( V_25 ) ;
if ( ! V_58 )
return - V_36 ;
V_33 = F_69 ( V_58 , V_105 ) ;
if ( ! V_33 )
return V_33 ;
return F_71 ( V_58 , V_105 ) ;
}
static int F_75 ( struct V_26 * V_27 , int V_105 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 ;
struct V_189 * V_103 ;
T_13 V_108 ;
if ( V_27 -> type & V_146 )
return F_58 ( V_2 , V_105 ) ;
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 &&
( V_105 == V_151 ||
V_105 == V_150 ) ) {
V_108 = F_60 ( V_4 -> V_118 ,
V_190 ,
V_153 ) ;
if ( V_108 != V_119 ) {
F_3 ( L_23 ,
V_6 , V_108 ) ;
return - V_120 ;
}
}
V_103 = F_76 ( V_27 ) ;
if ( V_27 -> type & V_191 )
return F_72 ( V_27 , V_105 ) ;
if ( F_66 ( V_103 ) ||
F_66 ( V_103 -> V_192 ) )
return F_61 ( V_2 , V_105 ) ;
return F_62 ( V_103 -> V_193 , V_105 ) ;
}
static int F_77 ( struct V_26 * V_27 , int V_194 )
{
int V_33 ;
int V_195 ;
while ( 1 ) {
V_33 = F_53 ( V_27 , & V_195 ) ;
if ( V_33 != V_143 )
return V_33 ;
if ( V_194 <= 0 ) {
F_3 ( L_24 ,
V_6 , V_27 -> V_30 , V_194 ) ;
return V_126 ;
}
V_194 -= V_195 ;
F_57 ( V_195 ) ;
}
return V_126 ;
}
static int F_78 ( struct V_26 * V_27 , int V_196 ,
char * V_197 , unsigned long V_198 )
{
if ( ! F_50 ( V_133 ) )
F_51 ( V_27 -> V_4 , V_27 -> V_17 ) ;
return 0 ;
}
static int F_79 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_80 ( struct V_26 * V_27 , int type , int V_29 ,
unsigned long V_30 , unsigned long V_31 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_108 ;
if ( type != V_199 &&
type != V_200 ) {
F_3 ( L_25 ,
V_6 , type ) ;
return - V_201 ;
}
if ( V_29 < V_202 ||
V_29 > V_203 ) {
F_3 ( L_26 ,
V_6 , V_29 ) ;
return - V_201 ;
}
if ( ! F_81 ( V_204 ) ) {
F_3 ( L_27 ,
V_6 ) ;
return - V_36 ;
}
V_108 = F_82 ( V_4 -> V_118 , V_27 -> V_30 ,
type , V_29 , V_30 , V_31 ) ;
if ( V_108 != V_119 ) {
F_3 ( L_28
L_29 ,
V_6 , V_108 , type , V_29 ,
V_2 -> V_96 , V_27 -> V_30 ) ;
return - V_120 ;
}
return 0 ;
}
static inline bool F_83 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
if ( ! V_25 || ! V_25 -> V_27 )
return false ;
if ( V_25 -> V_205 && ( V_25 -> V_27 -> V_100 & V_134 ) )
return false ;
if ( V_25 -> V_27 -> V_100 & V_206 )
return true ;
return false ;
}
static int F_84 ( struct V_57 * V_58 ,
int V_207 , int V_208 , T_7 * V_43 )
{
if ( ! V_58 )
return V_209 ;
if ( F_83 ( V_58 ) ) {
* V_43 = 0xFFFFFFFF ;
return V_210 ;
}
return F_29 ( V_58 , V_207 , V_208 , V_43 ) ;
}
static int F_85 ( struct V_57 * V_58 ,
int V_207 , int V_208 , T_7 V_43 )
{
if ( ! V_58 )
return V_209 ;
if ( F_83 ( V_58 ) )
return V_210 ;
return F_86 ( V_58 , V_207 , V_208 , V_43 ) ;
}
static void F_87 ( struct V_211 * V_17 )
{
if ( V_17 -> V_212 || V_17 -> V_213 ||
V_17 -> V_214 || V_17 -> V_215 || V_17 -> V_216 )
F_88 ( L_30 ,
F_89 ( V_17 -> V_212 ) ,
F_89 ( V_17 -> V_213 ) ,
F_89 ( V_17 -> V_214 ) ,
F_89 ( V_17 -> V_215 ) ,
F_89 ( V_17 -> V_216 ) ) ;
if ( V_17 -> V_217 || V_17 -> V_218 ||
V_17 -> V_219 || V_17 -> V_220 || V_17 -> V_221 )
F_88 ( L_31 ,
F_89 ( V_17 -> V_217 ) ,
F_89 ( V_17 -> V_218 ) ,
F_89 ( V_17 -> V_219 ) ,
F_89 ( V_17 -> V_220 ) ,
F_89 ( V_17 -> V_221 ) ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_211 * V_17 = & V_4 -> V_222 . V_223 ;
long V_108 ;
V_108 = F_91 ( V_4 -> V_224 , V_17 , sizeof( * V_17 ) ) ;
if ( V_108 != V_119 ) {
F_3 ( L_32 ,
V_6 , V_4 -> V_224 , V_108 ) ;
return;
}
switch ( V_17 -> type ) {
case V_225 :
F_88 ( L_33 ) ;
F_87 ( V_17 ) ;
if ( V_17 -> V_226 . V_227 || V_17 -> V_226 . V_228 )
F_88 ( L_34 ,
F_89 ( V_17 -> V_226 . V_227 ) ,
F_89 ( V_17 -> V_226 . V_228 ) ) ;
break;
case V_229 :
F_88 ( L_35 ,
V_17 -> V_230 . V_231 ? L_36 : L_37 ) ;
F_87 ( V_17 ) ;
if ( V_17 -> V_230 . V_232 || V_17 -> V_230 . V_233 ||
V_17 -> V_230 . V_234 || V_17 -> V_230 . V_235 )
F_88 ( L_38 ,
F_89 ( V_17 -> V_230 . V_232 ) ,
F_89 ( V_17 -> V_230 . V_233 ) ,
F_89 ( V_17 -> V_230 . V_234 ) ,
F_89 ( V_17 -> V_230 . V_235 ) ) ;
break;
case V_236 :
F_88 ( L_39 ,
V_17 -> V_237 . V_238 ) ;
F_87 ( V_17 ) ;
if ( V_17 -> V_237 . V_239 || V_17 -> V_237 . V_240 )
F_88 ( L_40 ,
F_89 ( V_17 -> V_237 . V_239 ) ,
F_89 ( V_17 -> V_237 . V_240 ) ) ;
break;
case V_241 :
F_88 ( L_41 ) ;
F_87 ( V_17 ) ;
break;
case V_242 :
F_88 ( L_42 ) ;
F_87 ( V_17 ) ;
break;
default:
F_3 ( L_43 ,
V_6 , V_4 -> V_224 , V_17 -> type ) ;
}
}
static int F_92 ( struct V_1 * V_2 ,
T_12 V_28 , struct V_26 * * V_27 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_243 * V_244 ;
struct V_26 * V_245 ;
struct V_24 V_25 ;
V_244 = & V_4 -> V_13 . V_246 [ V_28 ] ;
if ( V_244 -> V_49 & V_247 ) {
V_244 = V_244 -> V_248 ;
F_70 ( ! V_244 ||
! ( V_244 -> V_49 & V_249 ) ) ;
V_28 = V_244 -> V_250 ;
}
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 . V_4 = V_2 ;
V_25 . V_40 = V_28 ;
V_245 = F_13 ( & V_25 ) ;
if ( ! V_245 )
return - V_251 ;
* V_27 = V_245 ;
if ( ! ( V_245 -> V_100 & V_132 ) )
V_4 -> V_106 ( V_4 , V_28 ) ;
V_245 = V_245 -> V_192 ;
while ( V_245 && ! ( V_245 -> type & V_146 ) ) {
int V_33 ;
int V_252 = ( V_128 |
V_129 ) ;
V_33 = V_34 -> V_253 ( V_245 , NULL ) ;
if ( V_33 <= 0 || ( V_33 & V_252 ) == V_252 ) {
V_245 = V_245 -> V_192 ;
continue;
}
* V_27 = V_245 ;
if ( ! ( V_245 -> V_100 & V_132 ) )
V_4 -> V_106 ( V_4 , V_245 -> V_30 ) ;
V_245 = V_245 -> V_192 ;
}
return 0 ;
}
static int F_93 ( struct V_26 * * V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_26 * V_254 , * V_255 ;
T_14 V_256 ;
T_11 V_257 , V_196 ;
int V_252 = ( V_128 | V_129 ) ;
long V_108 ;
int V_100 , V_33 = V_258 ;
F_94 ( NULL , false ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
V_254 = F_95 ( V_2 ) ;
if ( ! V_254 || ( V_254 -> V_100 & V_132 ) )
continue;
V_108 = F_96 ( V_4 -> V_118 ,
& V_256 , & V_257 , & V_196 ) ;
if ( V_108 != V_119 ) {
F_97 ( L_44
L_45 ,
V_6 , V_2 -> V_96 , V_108 ) ;
continue;
}
if ( F_48 ( V_257 ) == V_259 ||
F_48 ( V_196 ) == V_260 ) {
F_97 ( L_46 ,
V_6 , V_2 -> V_96 ) ;
continue;
}
F_97 ( L_47 ,
V_6 , F_48 ( V_257 ) ,
F_48 ( V_196 ) , F_89 ( V_256 ) ,
V_2 -> V_96 ) ;
switch ( F_48 ( V_257 ) ) {
case V_261 :
if ( F_48 ( V_196 ) == V_262 ) {
F_22 ( L_48 ) ;
V_33 = V_263 ;
} else if ( F_48 ( V_196 ) == V_264 ) {
F_88 ( L_49
L_50 ) ;
F_90 ( V_2 ) ;
V_33 = V_258 ;
}
break;
case V_127 :
if ( F_48 ( V_196 ) == V_265 ) {
* V_27 = V_254 ;
F_22 ( L_51
L_52 ,
V_2 -> V_96 ,
F_98 ( V_254 ) ) ;
V_33 = V_266 ;
} else if ( F_48 ( V_196 ) ==
V_267 ) {
* V_27 = V_254 ;
F_22 ( L_53
L_52 ,
V_2 -> V_96 ,
F_98 ( V_254 ) ) ;
V_33 = V_268 ;
} else if ( F_48 ( V_196 ) == V_264 ) {
F_88 ( L_54
L_55 ,
V_2 -> V_96 ,
F_98 ( V_254 ) ) ;
F_44 ( V_254 ) ;
F_51 ( V_2 , V_254 -> V_17 ) ;
V_33 = V_258 ;
}
break;
case V_269 :
if ( F_92 ( V_2 ,
F_89 ( V_256 ) , V_27 ) ) {
F_88 ( L_56 ,
V_2 -> V_96 , F_89 ( V_256 ) ) ;
F_88 ( L_57 ,
F_98 ( V_254 ) ) ;
V_108 = F_45 ( V_4 -> V_118 ,
V_4 -> V_222 . V_270 , V_122 ) ;
if ( V_108 == V_119 )
F_51 ( V_2 ,
V_4 -> V_222 . V_270 ) ;
F_42 ( V_4 -> V_118 ,
V_256 ,
V_271 ) ;
V_33 = V_258 ;
} else if ( ( * V_27 ) -> V_100 & V_132 ||
F_99 ( * V_27 ) ) {
V_33 = V_258 ;
} else {
F_22 ( L_58
L_59 ,
( * V_27 ) -> V_30 ,
( * V_27 ) -> V_4 -> V_96 ) ;
F_22 ( L_60
L_61 ,
F_98 ( * V_27 ) ,
F_98 ( V_254 ) ) ;
V_33 = V_272 ;
}
break;
default:
F_3 ( L_62 ,
V_6 , F_48 ( V_257 ) ) ;
}
if ( ( V_33 == V_272 ||
V_33 == V_268 ) &&
! ( ( * V_27 ) -> V_100 & V_132 ) ) {
F_49 ( * V_27 , V_132 ) ;
F_44 ( * V_27 ) ;
if ( F_50 ( V_133 ) )
F_51 ( ( * V_27 ) -> V_4 ,
( * V_27 ) -> V_17 ) ;
}
if ( V_33 == V_272 ) {
V_255 = ( * V_27 ) -> V_192 ;
while ( V_255 ) {
if ( V_255 -> type & V_146 )
break;
V_100 = V_34 -> V_253 ( V_255 , NULL ) ;
if ( V_100 > 0 &&
( V_100 & V_252 ) != V_252 )
* V_27 = V_255 ;
V_255 = V_255 -> V_192 ;
}
F_49 ( * V_27 , V_132 ) ;
}
if ( V_33 > V_273 )
break;
}
if ( V_33 == V_258 && F_8 () )
F_100 ( V_46 ) ;
return V_33 ;
}
static int F_101 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
T_7 V_274 , V_275 , V_276 , V_277 ;
int V_278 ;
if ( V_25 -> V_71 ) {
V_278 = ( F_102 ( V_58 -> V_279 ) - 8 ) << 5 ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_179 ,
2 , & V_274 ) ;
V_274 &= ~ V_280 ;
V_274 |= V_278 ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_179 ,
2 , V_274 ) ;
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_281 ,
4 , & V_276 ) ;
if ( V_276 & 0x10 ) {
V_34 -> V_165 ( V_58 ,
V_25 -> V_71 + V_282 ,
4 , & V_276 ) ;
V_276 |= 0x10 ;
V_34 -> V_168 ( V_58 ,
V_25 -> V_71 + V_282 ,
4 , V_276 ) ;
}
}
V_34 -> V_165 ( V_58 , V_283 , 2 , & V_275 ) ;
V_275 |= ( V_284 | V_285 ) ;
V_34 -> V_168 ( V_58 , V_283 , 2 , V_275 ) ;
if ( V_25 -> V_71 ) {
V_34 -> V_165 ( V_58 , V_25 -> V_71 + V_179 ,
2 , & V_274 ) ;
V_274 &= ~ V_286 ;
V_274 |= ( V_287 |
V_288 |
V_289 ) ;
V_34 -> V_168 ( V_58 , V_25 -> V_71 + V_179 ,
2 , V_274 ) ;
}
if ( V_25 -> V_71 && V_25 -> V_82 ) {
V_34 -> V_165 ( V_58 , V_25 -> V_82 + V_290 ,
4 , & V_277 ) ;
V_277 |= ( V_291 | V_292 ) ;
V_34 -> V_168 ( V_58 , V_25 -> V_82 + V_290 ,
4 , V_277 ) ;
}
return 0 ;
}
static int F_103 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_31 ( V_58 ) ;
struct V_3 * V_4 ;
T_9 V_33 ;
if ( ! V_25 )
return - V_251 ;
if ( V_25 -> V_205 ) {
V_33 = F_101 ( V_58 ) ;
} else {
V_4 = V_25 -> V_4 -> V_9 ;
V_33 = F_104 ( V_4 -> V_118 ,
V_293 , V_25 -> V_92 ) ;
}
if ( V_33 ) {
F_3 ( L_63 ,
V_6 , V_25 -> V_92 , V_33 ) ;
return - V_120 ;
}
return 0 ;
}
void F_105 ( struct V_160 * V_294 )
{
struct V_57 * V_58 = F_106 ( V_294 ) ;
if ( ! V_294 -> V_295 )
return;
F_107 ( V_58 ) ;
F_108 ( V_294 ) ;
F_109 ( V_294 ) ;
}
static void F_110 ( struct V_160 * V_294 )
{
struct V_57 * V_58 = F_106 ( V_294 ) ;
int V_296 ;
if ( ! V_294 -> V_295 )
return;
V_296 = F_111 ( V_294 -> V_205 ) ;
if ( ( 128 << V_294 -> V_297 ) >= V_296 )
F_112 ( V_294 , V_296 ) ;
V_58 -> V_279 = F_111 ( V_294 ) ;
}
static int T_15 F_113 ( void )
{
int V_33 = - V_7 ;
F_114 ( V_122 ) ;
V_33 = F_115 ( & V_298 ) ;
if ( ! V_33 )
F_88 ( L_64 ) ;
else
F_88 ( L_65 , V_33 ) ;
return V_33 ;
}
