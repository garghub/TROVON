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
static int F_19 ( void * V_17 , T_6 V_43 )
{
return F_15 ( V_17 , 0xD10 , V_43 ) ;
}
static int F_20 ( void * V_17 , T_6 * V_43 )
{
return F_17 ( V_17 , 0xD10 , V_43 ) ;
}
static int F_21 ( void * V_17 , T_6 V_43 )
{
return F_15 ( V_17 , 0xD90 , V_43 ) ;
}
static int F_22 ( void * V_17 , T_6 * V_43 )
{
return F_17 ( V_17 , 0xD90 , V_43 ) ;
}
static int F_23 ( void * V_17 , T_6 V_43 )
{
return F_15 ( V_17 , 0xE10 , V_43 ) ;
}
static int F_24 ( void * V_17 , T_6 * V_43 )
{
return F_17 ( V_17 , 0xE10 , V_43 ) ;
}
static int F_25 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_33 = 0 ;
if ( ! V_45 ) {
V_46 = F_26 ( F_27 ( V_47 ) ) ;
if ( V_46 < 0 ) {
F_28 ( L_3 ,
V_6 , V_46 ) ;
return V_46 ;
}
V_33 = F_29 ( V_46 , F_6 ,
V_48 , L_4 , NULL ) ;
if ( V_33 < 0 ) {
F_30 ( V_46 ) ;
F_28 ( L_5 ,
V_6 , V_46 ) ;
return V_33 ;
}
V_45 = true ;
}
if ( ! F_8 () )
F_31 ( V_46 ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( F_8 () )
V_4 -> V_49 |= V_50 ;
else
V_4 -> V_49 &= ~ V_50 ;
#ifdef F_32
if ( V_4 -> V_51 || ! V_4 -> V_52 )
continue;
V_4 -> V_51 = 1 ;
F_33 ( L_6 , 0200 ,
V_4 -> V_52 , V_2 ,
& V_53 ) ;
F_33 ( L_7 , 0600 ,
V_4 -> V_52 , V_2 ,
& V_54 ) ;
F_33 ( L_8 , 0600 ,
V_4 -> V_52 , V_2 ,
& V_55 ) ;
F_33 ( L_9 , 0600 ,
V_4 -> V_52 , V_2 ,
& V_56 ) ;
#endif
}
return V_33 ;
}
static int F_34 ( struct V_57 * V_58 , int V_59 )
{
int V_60 = V_61 ;
int V_62 = 48 ;
T_7 V_63 , V_64 ;
if ( ! V_58 )
return 0 ;
F_35 ( V_58 , V_65 , 2 , & V_63 ) ;
if ( ! ( V_63 & V_66 ) )
return 0 ;
while ( V_62 -- ) {
F_35 ( V_58 , V_60 , 1 , & V_60 ) ;
if ( V_60 < 0x40 )
break;
V_60 &= ~ 3 ;
F_35 ( V_58 , V_60 + V_67 , 1 , & V_64 ) ;
if ( V_64 == 0xff )
break;
if ( V_64 == V_59 )
return V_60 ;
V_60 += V_68 ;
}
return 0 ;
}
static int F_36 ( struct V_57 * V_58 , int V_59 )
{
struct V_24 * V_25 = F_37 ( V_58 ) ;
T_7 V_69 ;
int V_60 = 256 , V_70 = ( 4096 - 256 ) / 8 ;
if ( ! V_25 || ! V_25 -> V_71 )
return 0 ;
if ( F_35 ( V_58 , V_60 , 4 , & V_69 ) != V_72 )
return 0 ;
else if ( ! V_69 )
return 0 ;
while ( V_70 -- > 0 ) {
if ( F_38 ( V_69 ) == V_59 && V_60 )
return V_60 ;
V_60 = F_39 ( V_69 ) ;
if ( V_60 < 256 )
break;
if ( F_35 ( V_58 , V_60 , 4 , & V_69 ) != V_72 )
break;
}
return 0 ;
}
static void * F_40 ( struct V_57 * V_58 , void * V_17 )
{
struct V_1 * V_2 = V_58 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_24 * V_25 = F_37 ( V_58 ) ;
T_8 V_73 ;
int V_33 ;
if ( ! V_25 || V_25 -> V_27 )
return NULL ;
if ( ( V_58 -> V_74 >> 8 ) == V_75 )
return NULL ;
V_25 -> V_74 = V_58 -> V_74 ;
V_25 -> V_76 &= 0xFFFFFF00 ;
V_25 -> V_77 = F_34 ( V_58 , V_78 ) ;
V_25 -> V_71 = F_34 ( V_58 , V_79 ) ;
V_25 -> V_80 = F_36 ( V_58 , V_81 ) ;
if ( ( V_25 -> V_74 >> 8 ) == V_82 ) {
V_25 -> V_76 |= V_83 ;
if ( V_25 -> V_71 ) {
F_35 ( V_58 , V_25 -> V_71 + V_84 ,
2 , & V_73 ) ;
V_73 = ( V_73 & V_85 ) >> 4 ;
if ( V_73 == V_86 )
V_25 -> V_76 |= V_87 ;
else if ( V_73 == V_88 )
V_25 -> V_76 |= V_89 ;
}
}
V_25 -> V_90 = ( V_58 -> V_91 << 8 ) | ( V_58 -> V_92 ) ;
V_25 -> V_40 = V_4 -> V_13 . V_93 [ V_25 -> V_90 ] ;
V_33 = F_41 ( V_25 ) ;
if ( V_33 ) {
F_3 ( L_10 ,
V_6 , V_2 -> V_94 , V_58 -> V_91 ,
F_42 ( V_58 -> V_92 ) , F_43 ( V_58 -> V_92 ) , V_33 ) ;
return NULL ;
}
if ( ( V_58 -> V_95 == V_96 &&
V_58 -> V_97 == 0x1657 ) ||
( V_58 -> V_95 == V_96 &&
V_58 -> V_97 == 0x168a ) ||
( V_58 -> V_95 == V_96 &&
V_58 -> V_97 == 0x168e ) )
V_25 -> V_27 -> V_98 |= V_99 ;
if ( ! ( V_25 -> V_27 -> V_98 & V_100 ) ) {
V_25 -> V_27 -> V_101 = F_44 ( V_2 -> V_94 ,
V_58 -> V_91 ) ;
if ( V_25 -> V_27 -> V_101 )
V_25 -> V_27 -> V_98 |= V_100 ;
}
F_4 ( V_102 ) ;
F_45 ( V_25 ) ;
return NULL ;
}
static int F_46 ( struct V_26 * V_27 , int V_103 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
bool V_104 = false ;
int V_105 ;
T_9 V_106 ;
switch ( V_103 ) {
case V_107 :
return - V_108 ;
case V_109 :
return 0 ;
case V_110 :
V_105 = V_111 ;
break;
case V_112 :
V_105 = V_113 ;
break;
case V_114 :
V_104 = true ;
V_105 = V_115 ;
break;
default:
F_3 ( L_11 , V_6 , V_103 ) ;
return - V_7 ;
}
if ( V_104 ) {
if ( V_4 -> V_104 ) {
V_4 -> V_104 ( V_4 , V_27 -> V_30 ) ;
return 0 ;
}
V_106 = F_47 ( V_4 -> V_116 , V_27 -> V_30 , V_105 ) ;
if ( V_106 != V_117 ) {
F_3 ( L_12 ,
V_6 , V_106 , V_4 -> V_2 -> V_94 ,
V_27 -> V_30 ) ;
return - V_118 ;
}
return 0 ;
}
if ( V_4 -> V_119 )
return V_4 -> V_119 ( V_4 , V_27 -> V_30 , V_105 ) ;
V_106 = F_48 ( V_4 -> V_116 , V_27 -> V_30 , V_105 ) ;
if ( V_106 != V_117 ) {
F_3 ( L_13 ,
V_6 , V_106 , V_103 , V_4 -> V_2 -> V_94 ,
V_27 -> V_30 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_49 ( struct V_26 * V_27 )
{
return V_27 -> V_30 ;
}
static void F_50 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_9 V_106 ;
V_106 = F_51 ( V_4 -> V_116 , V_27 -> V_17 ,
V_120 ) ;
if ( V_106 != V_117 )
F_3 ( L_14 ,
V_6 , V_106 , V_27 -> V_4 -> V_94 ) ;
}
static int F_52 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_10 V_121 ;
T_11 V_122 ;
T_9 V_106 ;
int V_123 = 0 ;
V_106 = F_53 ( V_4 -> V_116 ,
V_27 -> V_30 ,
& V_121 ,
& V_122 ,
NULL ) ;
if ( V_106 != V_117 ) {
F_3 ( L_15 ,
V_6 , V_106 , V_4 -> V_2 -> V_94 ) ;
return V_124 ;
}
if ( F_54 ( V_122 ) != V_125 ) {
V_123 = ( V_126 |
V_127 |
V_128 |
V_129 ) ;
} else if ( ! ( V_27 -> V_98 & V_130 ) ) {
F_55 ( V_27 , V_130 ) ;
F_50 ( V_27 ) ;
if ( F_56 ( V_131 ) )
F_57 ( V_27 -> V_4 , V_27 -> V_17 ) ;
}
return V_123 ;
}
static int F_58 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_10 V_121 ;
T_11 V_122 ;
T_9 V_106 ;
int V_123 ;
if ( V_27 -> V_98 & V_132 ) {
V_123 = ( V_126 |
V_127 |
V_128 |
V_129 ) ;
return V_123 ;
}
if ( V_4 -> V_133 ) {
V_121 = V_4 -> V_133 ( V_4 , V_27 -> V_30 ) ;
} else {
V_106 = F_53 ( V_4 -> V_116 ,
V_27 -> V_30 ,
& V_121 ,
& V_122 ,
NULL ) ;
if ( V_106 != V_117 ) {
F_3 ( L_16 ,
V_6 , V_106 , V_4 -> V_2 -> V_94 ,
V_27 -> V_30 ) ;
return V_124 ;
}
}
switch ( V_121 ) {
case V_134 :
V_123 = ( V_126 |
V_127 |
V_128 |
V_129 ) ;
break;
case V_135 :
V_123 = ( V_127 |
V_129 ) ;
break;
case V_136 :
V_123 = ( V_126 |
V_128 ) ;
break;
case V_137 :
V_123 = 0 ;
break;
case V_138 :
V_123 = V_139 ;
break;
case V_140 :
V_123 = V_141 ;
break;
case V_142 :
V_123 = V_124 ;
break;
default:
V_123 = V_124 ;
F_3 ( L_17 ,
V_6 , V_4 -> V_2 -> V_94 ,
V_27 -> V_30 , V_121 ) ;
}
if ( ! ( V_123 & V_124 ) &&
! ( V_123 & V_141 ) &&
! ( V_123 & V_126 ) &&
! ( V_123 & V_127 ) &&
! ( V_27 -> V_98 & V_130 ) ) {
if ( V_4 -> V_104 )
V_4 -> V_104 ( V_4 , V_27 -> V_30 ) ;
F_55 ( V_27 , V_130 ) ;
F_50 ( V_27 ) ;
if ( F_56 ( V_131 ) )
F_57 ( V_27 -> V_4 , V_27 -> V_17 ) ;
}
return V_123 ;
}
static int F_59 ( struct V_26 * V_27 , int * V_143 )
{
int V_33 ;
if ( V_27 -> type & V_144 )
V_33 = F_52 ( V_27 ) ;
else
V_33 = F_58 ( V_27 ) ;
if ( ! V_143 )
return V_33 ;
* V_143 = 0 ;
if ( V_33 & V_141 )
* V_143 = 1000 ;
return V_33 ;
}
static T_9 F_60 ( struct V_3 * V_4 )
{
T_9 V_106 = V_145 ;
while ( 1 ) {
V_106 = F_61 ( V_4 -> V_116 ) ;
if ( V_106 <= 0 )
break;
if ( V_146 < V_147 )
F_62 ( 1000 * V_106 ) ;
else
F_63 ( V_106 ) ;
}
return V_106 ;
}
int F_64 ( struct V_1 * V_2 , int V_103 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_106 = V_145 ;
F_65 ( L_18 ,
V_6 , V_2 -> V_94 , V_103 ) ;
if ( V_103 == V_148 ||
V_103 == V_149 )
V_106 = F_66 ( V_4 -> V_116 ,
V_150 ,
V_151 ) ;
else if ( V_103 == V_152 )
V_106 = F_66 ( V_4 -> V_116 ,
V_150 ,
V_153 ) ;
if ( V_106 < 0 )
goto V_154;
V_106 = F_60 ( V_4 ) ;
if ( V_103 == V_152 ) {
if ( V_146 < V_147 )
F_62 ( 1000 * V_155 ) ;
else
F_63 ( V_155 ) ;
}
V_154:
if ( V_106 != V_117 )
return - V_118 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , int V_103 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_106 = V_145 ;
F_65 ( L_18 ,
V_6 , V_2 -> V_94 , V_103 ) ;
if ( V_103 == V_148 )
V_106 = F_66 ( V_4 -> V_116 ,
V_156 ,
V_151 ) ;
else if ( V_103 == V_149 )
V_106 = F_66 ( V_4 -> V_116 ,
V_157 ,
V_151 ) ;
else if ( V_103 == V_152 )
V_106 = F_66 ( V_4 -> V_116 ,
V_157 ,
V_153 ) ;
if ( V_106 < 0 )
goto V_154;
V_106 = F_60 ( V_4 ) ;
if ( V_103 == V_152 )
F_63 ( V_155 ) ;
V_154:
if ( V_106 != V_117 )
return - V_118 ;
return 0 ;
}
static int F_68 ( struct V_158 * V_159 , int V_103 )
{
struct V_57 * V_58 = F_69 ( V_159 -> V_101 , V_159 -> V_92 ) ;
struct V_24 * V_25 = F_37 ( V_58 ) ;
int V_160 = V_25 ? V_25 -> V_80 : 0 ;
T_7 V_161 ;
F_65 ( L_19 ,
V_6 , F_70 ( V_159 -> V_101 ) ,
V_159 -> V_101 -> V_162 , V_103 ) ;
switch ( V_103 ) {
case V_148 :
case V_149 :
if ( V_160 ) {
V_34 -> V_163 ( V_58 , V_160 + V_164 ,
4 , & V_161 ) ;
V_161 |= V_165 ;
V_34 -> V_166 ( V_58 , V_160 + V_164 ,
4 , V_161 ) ;
}
V_34 -> V_163 ( V_58 , V_167 , 2 , & V_161 ) ;
V_161 |= V_168 ;
V_34 -> V_166 ( V_58 , V_167 , 2 , V_161 ) ;
F_63 ( V_169 ) ;
break;
case V_152 :
V_34 -> V_163 ( V_58 , V_167 , 2 , & V_161 ) ;
V_161 &= ~ V_168 ;
V_34 -> V_166 ( V_58 , V_167 , 2 , V_161 ) ;
F_63 ( V_155 ) ;
if ( V_160 ) {
V_34 -> V_163 ( V_58 , V_160 + V_164 ,
4 , & V_161 ) ;
V_161 &= ~ V_165 ;
V_34 -> V_166 ( V_58 , V_160 + V_164 ,
4 , V_161 ) ;
}
break;
}
return 0 ;
}
void F_71 ( struct V_158 * V_159 )
{
struct V_1 * V_2 ;
if ( F_72 ( V_159 -> V_101 ) ) {
V_2 = F_73 ( V_159 -> V_101 ) ;
F_67 ( V_2 , V_149 ) ;
F_67 ( V_2 , V_152 ) ;
} else {
F_68 ( V_159 , V_149 ) ;
F_68 ( V_159 , V_152 ) ;
}
}
static int F_74 ( struct V_26 * V_27 , int V_103 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_170 * V_101 ;
int V_33 ;
if ( V_27 -> type & V_144 ) {
V_33 = F_64 ( V_2 , V_103 ) ;
} else {
struct V_3 * V_4 ;
T_9 V_106 ;
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 &&
( V_103 == V_149 ||
V_103 == V_148 ) ) {
V_106 = F_66 ( V_4 -> V_116 ,
V_171 ,
V_151 ) ;
if ( V_106 != V_117 ) {
F_3 ( L_20
L_21 ,
V_6 , V_106 ) ;
return - V_118 ;
}
}
V_101 = F_75 ( V_27 ) ;
if ( F_72 ( V_101 ) ||
F_72 ( V_101 -> V_172 ) )
V_33 = F_67 ( V_2 , V_103 ) ;
else
V_33 = F_68 ( V_101 -> V_173 , V_103 ) ;
}
return V_33 ;
}
static int F_76 ( struct V_26 * V_27 , int V_174 )
{
int V_33 ;
int V_175 ;
while ( 1 ) {
V_33 = F_59 ( V_27 , & V_175 ) ;
if ( V_33 != V_141 )
return V_33 ;
if ( V_174 <= 0 ) {
F_3 ( L_22 ,
V_6 , V_27 -> V_30 , V_174 ) ;
return V_124 ;
}
V_174 -= V_175 ;
F_63 ( V_175 ) ;
}
return V_124 ;
}
static int F_77 ( struct V_26 * V_27 , int V_176 ,
char * V_177 , unsigned long V_178 )
{
if ( ! F_56 ( V_131 ) )
F_57 ( V_27 -> V_4 , V_27 -> V_17 ) ;
return 0 ;
}
static int F_78 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_79 ( struct V_26 * V_27 , int type , int V_29 ,
unsigned long V_30 , unsigned long V_31 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_106 ;
if ( type != V_179 &&
type != V_180 ) {
F_3 ( L_23 ,
V_6 , type ) ;
return - V_181 ;
}
if ( V_29 < V_182 ||
V_29 > V_183 ) {
F_3 ( L_24 ,
V_6 , V_29 ) ;
return - V_181 ;
}
if ( ! F_80 ( V_184 ) ) {
F_3 ( L_25 ,
V_6 ) ;
return - V_36 ;
}
V_106 = F_81 ( V_4 -> V_116 , V_27 -> V_30 ,
type , V_29 , V_30 , V_31 ) ;
if ( V_106 != V_117 ) {
F_3 ( L_26
L_27 ,
V_6 , V_106 , type , V_29 ,
V_2 -> V_94 , V_27 -> V_30 ) ;
return - V_118 ;
}
return 0 ;
}
static inline bool F_82 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_37 ( V_58 ) ;
if ( ! V_25 || ! V_25 -> V_27 )
return false ;
if ( V_25 -> V_27 -> V_98 & V_185 )
return true ;
return false ;
}
static int F_83 ( struct V_57 * V_58 ,
int V_186 , int V_187 , T_7 * V_43 )
{
if ( ! V_58 )
return V_188 ;
if ( F_82 ( V_58 ) ) {
* V_43 = 0xFFFFFFFF ;
return V_189 ;
}
return F_35 ( V_58 , V_186 , V_187 , V_43 ) ;
}
static int F_84 ( struct V_57 * V_58 ,
int V_186 , int V_187 , T_7 V_43 )
{
if ( ! V_58 )
return V_188 ;
if ( F_82 ( V_58 ) )
return V_189 ;
return F_85 ( V_58 , V_186 , V_187 , V_43 ) ;
}
static void F_86 ( struct V_190 * V_17 )
{
if ( V_17 -> V_191 || V_17 -> V_192 ||
V_17 -> V_193 || V_17 -> V_194 || V_17 -> V_195 )
F_87 ( L_28 ,
F_88 ( V_17 -> V_191 ) ,
F_88 ( V_17 -> V_192 ) ,
F_88 ( V_17 -> V_193 ) ,
F_88 ( V_17 -> V_194 ) ,
F_88 ( V_17 -> V_195 ) ) ;
if ( V_17 -> V_196 || V_17 -> V_197 ||
V_17 -> V_198 || V_17 -> V_199 || V_17 -> V_200 )
F_87 ( L_29 ,
F_88 ( V_17 -> V_196 ) ,
F_88 ( V_17 -> V_197 ) ,
F_88 ( V_17 -> V_198 ) ,
F_88 ( V_17 -> V_199 ) ,
F_88 ( V_17 -> V_200 ) ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_190 * V_17 = & V_4 -> V_201 . V_202 ;
long V_106 ;
V_106 = F_90 ( V_4 -> V_203 , V_17 , sizeof( * V_17 ) ) ;
if ( V_106 != V_117 ) {
F_3 ( L_30 ,
V_6 , V_4 -> V_203 , V_106 ) ;
return;
}
switch ( V_17 -> type ) {
case V_204 :
F_87 ( L_31 ) ;
F_86 ( V_17 ) ;
if ( V_17 -> V_205 . V_206 || V_17 -> V_205 . V_207 )
F_87 ( L_32 ,
F_88 ( V_17 -> V_205 . V_206 ) ,
F_88 ( V_17 -> V_205 . V_207 ) ) ;
break;
case V_208 :
F_87 ( L_33 ,
V_17 -> V_209 . V_210 ? L_34 : L_35 ) ;
F_86 ( V_17 ) ;
if ( V_17 -> V_209 . V_211 || V_17 -> V_209 . V_212 ||
V_17 -> V_209 . V_213 || V_17 -> V_209 . V_214 )
F_87 ( L_36 ,
F_88 ( V_17 -> V_209 . V_211 ) ,
F_88 ( V_17 -> V_209 . V_212 ) ,
F_88 ( V_17 -> V_209 . V_213 ) ,
F_88 ( V_17 -> V_209 . V_214 ) ) ;
break;
case V_215 :
F_87 ( L_37 ,
V_17 -> V_216 . V_217 ) ;
F_86 ( V_17 ) ;
if ( V_17 -> V_216 . V_218 || V_17 -> V_216 . V_219 )
F_87 ( L_38 ,
F_88 ( V_17 -> V_216 . V_218 ) ,
F_88 ( V_17 -> V_216 . V_219 ) ) ;
break;
case V_220 :
F_87 ( L_39 ) ;
F_86 ( V_17 ) ;
break;
case V_221 :
F_87 ( L_40 ) ;
F_86 ( V_17 ) ;
break;
default:
F_3 ( L_41 ,
V_6 , V_4 -> V_203 , V_17 -> type ) ;
}
}
static int F_91 ( struct V_1 * V_2 ,
T_12 V_28 , struct V_26 * * V_27 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_222 * V_223 ;
struct V_26 * V_224 ;
struct V_24 V_25 ;
V_223 = & V_4 -> V_13 . V_225 [ V_28 ] ;
if ( V_223 -> V_49 & V_226 ) {
V_223 = V_223 -> V_227 ;
F_92 ( ! V_223 ||
! ( V_223 -> V_49 & V_228 ) ) ;
V_28 = V_223 -> V_229 ;
}
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 . V_4 = V_2 ;
V_25 . V_40 = V_28 ;
V_224 = F_13 ( & V_25 ) ;
if ( ! V_224 )
return - V_230 ;
* V_27 = V_224 ;
if ( ! ( V_224 -> V_98 & V_130 ) )
V_4 -> V_104 ( V_4 , V_28 ) ;
V_224 = V_224 -> V_172 ;
while ( V_224 && ! ( V_224 -> type & V_144 ) ) {
int V_33 ;
int V_231 = ( V_126 |
V_127 ) ;
V_33 = V_34 -> V_232 ( V_224 , NULL ) ;
if ( V_33 <= 0 || ( V_33 & V_231 ) == V_231 ) {
V_224 = V_224 -> V_172 ;
continue;
}
* V_27 = V_224 ;
if ( ! ( V_224 -> V_98 & V_130 ) )
V_4 -> V_104 ( V_4 , V_224 -> V_30 ) ;
V_224 = V_224 -> V_172 ;
}
return 0 ;
}
static int F_93 ( struct V_26 * * V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_26 * V_233 , * V_234 ;
T_13 V_235 ;
T_11 V_236 , V_176 ;
int V_231 = ( V_126 | V_127 ) ;
long V_106 ;
int V_98 , V_33 = V_237 ;
F_94 ( NULL , false ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
V_233 = F_95 ( V_2 ) ;
if ( ! V_233 || ( V_233 -> V_98 & V_130 ) )
continue;
V_106 = F_96 ( V_4 -> V_116 ,
& V_235 , & V_236 , & V_176 ) ;
if ( V_106 != V_117 ) {
F_97 ( L_42
L_43 ,
V_6 , V_2 -> V_94 , V_106 ) ;
continue;
}
if ( F_54 ( V_236 ) == V_238 ||
F_54 ( V_176 ) == V_239 ) {
F_97 ( L_44 ,
V_6 , V_2 -> V_94 ) ;
continue;
}
F_97 ( L_45 ,
V_6 , F_54 ( V_236 ) ,
F_54 ( V_176 ) , F_88 ( V_235 ) ,
V_2 -> V_94 ) ;
switch ( F_54 ( V_236 ) ) {
case V_240 :
if ( F_54 ( V_176 ) == V_241 ) {
F_28 ( L_46 ) ;
V_33 = V_242 ;
} else if ( F_54 ( V_176 ) == V_243 ) {
F_87 ( L_47
L_48 ) ;
F_89 ( V_2 ) ;
V_33 = V_237 ;
}
break;
case V_125 :
if ( F_54 ( V_176 ) == V_244 ) {
* V_27 = V_233 ;
F_28 ( L_49
L_50 ,
V_2 -> V_94 ,
F_98 ( V_233 ) ) ;
V_33 = V_245 ;
} else if ( F_54 ( V_176 ) ==
V_246 ) {
* V_27 = V_233 ;
F_28 ( L_51
L_50 ,
V_2 -> V_94 ,
F_98 ( V_233 ) ) ;
V_33 = V_247 ;
} else if ( F_54 ( V_176 ) == V_243 ) {
F_87 ( L_52
L_53 ,
V_2 -> V_94 ,
F_98 ( V_233 ) ) ;
F_50 ( V_233 ) ;
F_57 ( V_2 , V_233 -> V_17 ) ;
V_33 = V_237 ;
}
break;
case V_248 :
if ( F_91 ( V_2 ,
F_88 ( V_235 ) , V_27 ) ) {
F_87 ( L_54 ,
V_2 -> V_94 , F_88 ( V_235 ) ) ;
F_87 ( L_55 ,
F_98 ( V_233 ) ) ;
V_106 = F_51 ( V_4 -> V_116 ,
V_4 -> V_201 . V_249 , V_120 ) ;
if ( V_106 == V_117 )
F_57 ( V_2 ,
V_4 -> V_201 . V_249 ) ;
F_48 ( V_4 -> V_116 ,
V_235 ,
V_250 ) ;
V_33 = V_237 ;
} else if ( ( * V_27 ) -> V_98 & V_130 ||
F_99 ( * V_27 ) ) {
V_33 = V_237 ;
} else {
F_28 ( L_56
L_57 ,
( * V_27 ) -> V_30 ,
( * V_27 ) -> V_4 -> V_94 ) ;
F_28 ( L_58
L_59 ,
F_98 ( * V_27 ) ,
F_98 ( V_233 ) ) ;
V_33 = V_251 ;
}
break;
default:
F_3 ( L_60 ,
V_6 , F_54 ( V_236 ) ) ;
}
if ( ( V_33 == V_251 ||
V_33 == V_247 ) &&
! ( ( * V_27 ) -> V_98 & V_130 ) ) {
F_55 ( * V_27 , V_130 ) ;
F_50 ( * V_27 ) ;
if ( F_56 ( V_131 ) )
F_57 ( ( * V_27 ) -> V_4 ,
( * V_27 ) -> V_17 ) ;
}
if ( V_33 == V_251 ) {
V_234 = ( * V_27 ) -> V_172 ;
while ( V_234 ) {
if ( V_234 -> type & V_144 )
break;
V_98 = V_34 -> V_232 ( V_234 , NULL ) ;
if ( V_98 > 0 &&
( V_98 & V_231 ) != V_231 )
* V_27 = V_234 ;
V_234 = V_234 -> V_172 ;
}
F_55 ( * V_27 , V_130 ) ;
}
if ( V_33 > V_252 )
break;
}
if ( V_33 == V_237 && F_8 () )
F_100 ( V_46 ) ;
return V_33 ;
}
static int F_101 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_37 ( V_58 ) ;
struct V_3 * V_4 ;
T_9 V_33 ;
if ( ! V_25 )
return - V_230 ;
V_4 = V_25 -> V_4 -> V_9 ;
V_33 = F_102 ( V_4 -> V_116 ,
V_253 , V_25 -> V_90 ) ;
if ( V_33 ) {
F_3 ( L_61 ,
V_6 , V_25 -> V_90 , V_33 ) ;
return - V_118 ;
}
return 0 ;
}
static int T_14 F_103 ( void )
{
int V_33 = - V_7 ;
F_104 ( V_120 ) ;
V_33 = F_105 ( & V_254 ) ;
if ( ! V_33 )
F_87 ( L_62 ) ;
else
F_87 ( L_63 , V_33 ) ;
return V_33 ;
}
