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
static int F_6 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
T_1 V_20 = ( T_1 ) V_19 ;
if ( ! ( V_20 & V_21 ) ||
! ( V_18 & V_21 ) )
return 0 ;
if ( F_7 () )
F_8 ( NULL ) ;
else
F_9 ( V_21 , 0x0ul ) ;
return 0 ;
}
static T_2 F_10 ( struct V_22 * V_23 ,
const char T_3 * V_24 ,
T_4 V_25 , T_5 * V_26 )
{
struct V_1 * V_2 = V_23 -> V_9 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 , type , V_32 ;
unsigned long V_33 , V_34 ;
char V_35 [ 50 ] ;
int V_36 ;
if ( ! V_37 || ! V_37 -> V_38 )
return - V_39 ;
V_36 = F_11 ( V_35 , sizeof( V_35 ) , V_26 , V_24 , V_25 ) ;
if ( ! V_36 )
return - V_40 ;
V_36 = sscanf ( V_35 , L_2 ,
& V_31 , & type , & V_32 , & V_33 , & V_34 ) ;
if ( V_36 != 5 )
return - V_7 ;
V_28 = F_12 ( sizeof( * V_28 ) , V_41 ) ;
if ( ! V_28 )
return - V_42 ;
V_28 -> V_4 = V_2 ;
V_28 -> V_43 = V_31 ;
V_30 = F_13 ( V_28 ) ;
F_14 ( V_28 ) ;
if ( ! V_30 )
return - V_44 ;
V_36 = V_37 -> V_38 ( V_30 , type , V_32 , V_33 , V_34 ) ;
return V_36 < 0 ? V_36 : V_25 ;
}
static int F_15 ( void * V_45 , int V_46 , T_6 V_47 )
{
struct V_1 * V_2 = V_45 ;
struct V_3 * V_4 = V_2 -> V_9 ;
F_16 ( V_4 -> V_48 + V_46 , V_47 ) ;
return 0 ;
}
static int F_17 ( void * V_45 , int V_46 , T_6 * V_47 )
{
struct V_1 * V_2 = V_45 ;
struct V_3 * V_4 = V_2 -> V_9 ;
* V_47 = F_18 ( V_4 -> V_48 + V_46 ) ;
return 0 ;
}
static int F_19 ( void * V_45 , T_6 V_47 )
{
return F_15 ( V_45 , 0xD10 , V_47 ) ;
}
static int F_20 ( void * V_45 , T_6 * V_47 )
{
return F_17 ( V_45 , 0xD10 , V_47 ) ;
}
static int F_21 ( void * V_45 , T_6 V_47 )
{
return F_15 ( V_45 , 0xD90 , V_47 ) ;
}
static int F_22 ( void * V_45 , T_6 * V_47 )
{
return F_17 ( V_45 , 0xD90 , V_47 ) ;
}
static int F_23 ( void * V_45 , T_6 V_47 )
{
return F_15 ( V_45 , 0xE10 , V_47 ) ;
}
static int F_24 ( void * V_45 , T_6 * V_47 )
{
return F_17 ( V_45 , 0xE10 , V_47 ) ;
}
static int F_25 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_36 = 0 ;
if ( ! V_49 ) {
V_36 = F_26 ( & V_50 ) ;
if ( V_36 ) {
F_3 ( L_3 ,
V_6 , V_36 ) ;
return V_36 ;
}
V_49 = true ;
}
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
if ( F_7 () )
V_4 -> V_51 |= V_52 ;
else
V_4 -> V_51 &= ~ V_52 ;
#ifdef F_27
if ( V_4 -> V_53 || ! V_4 -> V_54 )
continue;
V_4 -> V_53 = 1 ;
F_28 ( L_4 , 0200 ,
V_4 -> V_54 , V_2 ,
& V_55 ) ;
F_28 ( L_5 , 0600 ,
V_4 -> V_54 , V_2 ,
& V_56 ) ;
F_28 ( L_6 , 0600 ,
V_4 -> V_54 , V_2 ,
& V_57 ) ;
F_28 ( L_7 , 0600 ,
V_4 -> V_54 , V_2 ,
& V_58 ) ;
#endif
}
return V_36 ;
}
static int F_29 ( struct V_59 * V_60 )
{
T_7 V_61 ;
if ( ! V_60 )
return 0 ;
F_30 ( V_60 , V_62 , 2 , & V_61 ) ;
if ( ! ( V_61 & V_63 ) )
return 0 ;
return V_64 ;
}
static int F_31 ( struct V_59 * V_60 , int V_65 )
{
int V_66 = F_29 ( V_60 ) ;
int V_67 = 48 ;
T_7 V_68 ;
if ( ! V_66 )
return 0 ;
while ( V_67 -- ) {
F_30 ( V_60 , V_66 , 1 , & V_66 ) ;
if ( V_66 < 0x40 )
break;
V_66 &= ~ 3 ;
F_30 ( V_60 , V_66 + V_69 , 1 , & V_68 ) ;
if ( V_68 == 0xff )
break;
if ( V_68 == V_65 )
return V_66 ;
V_66 += V_70 ;
}
return 0 ;
}
static int F_32 ( struct V_59 * V_60 , int V_65 )
{
struct V_27 * V_28 = F_33 ( V_60 ) ;
T_7 V_71 ;
int V_66 = 256 , V_72 = ( 4096 - 256 ) / 8 ;
if ( ! V_28 || ! V_28 -> V_73 )
return 0 ;
if ( F_30 ( V_60 , V_66 , 4 , & V_71 ) != V_74 )
return 0 ;
else if ( ! V_71 )
return 0 ;
while ( V_72 -- > 0 ) {
if ( F_34 ( V_71 ) == V_65 && V_66 )
return V_66 ;
V_66 = F_35 ( V_71 ) ;
if ( V_66 < 256 )
break;
if ( F_30 ( V_60 , V_66 , 4 , & V_71 ) != V_74 )
break;
}
return 0 ;
}
static void * F_36 ( struct V_59 * V_60 , void * V_45 )
{
struct V_1 * V_2 = V_60 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_27 * V_28 = F_33 ( V_60 ) ;
T_8 V_75 ;
int V_36 ;
if ( ! V_28 || V_28 -> V_30 )
return NULL ;
if ( ( V_60 -> V_76 >> 8 ) == V_77 )
return NULL ;
V_28 -> V_76 = V_60 -> V_76 ;
V_28 -> V_78 &= 0xFFFFFF00 ;
V_28 -> V_79 = F_31 ( V_60 , V_80 ) ;
V_28 -> V_73 = F_31 ( V_60 , V_81 ) ;
V_28 -> V_82 = F_32 ( V_60 , V_83 ) ;
if ( ( V_28 -> V_76 >> 8 ) == V_84 ) {
V_28 -> V_78 |= V_85 ;
if ( V_28 -> V_73 ) {
F_30 ( V_60 , V_28 -> V_73 + V_86 ,
2 , & V_75 ) ;
V_75 = ( V_75 & V_87 ) >> 4 ;
if ( V_75 == V_88 )
V_28 -> V_78 |= V_89 ;
else if ( V_75 == V_90 )
V_28 -> V_78 |= V_91 ;
}
}
V_28 -> V_92 = ( V_60 -> V_93 << 8 ) | ( V_60 -> V_94 ) ;
V_28 -> V_43 = V_4 -> V_13 . V_95 [ V_28 -> V_92 ] ;
V_36 = F_37 ( V_28 ) ;
if ( V_36 ) {
F_3 ( L_8 ,
V_6 , V_2 -> V_96 , V_60 -> V_93 ,
F_38 ( V_60 -> V_94 ) , F_39 ( V_60 -> V_94 ) , V_36 ) ;
return NULL ;
}
if ( ( V_60 -> V_97 == V_98 &&
V_60 -> V_99 == 0x1657 ) ||
( V_60 -> V_97 == V_98 &&
V_60 -> V_99 == 0x168e ) )
V_28 -> V_30 -> V_100 |= V_101 ;
if ( ! V_28 -> V_30 -> V_102 )
V_28 -> V_30 -> V_102 = F_40 ( V_2 -> V_96 ,
V_60 -> V_93 ) ;
F_4 ( V_103 ) ;
F_41 ( V_28 ) ;
return NULL ;
}
static int F_42 ( struct V_29 * V_30 , int V_104 )
{
struct V_1 * V_2 = V_30 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
bool V_105 = false ;
int V_106 , V_36 = 0 ;
T_9 V_107 ;
switch ( V_104 ) {
case V_108 :
return - V_109 ;
case V_110 :
return 0 ;
case V_111 :
V_106 = V_112 ;
break;
case V_113 :
V_106 = V_114 ;
break;
case V_115 :
V_105 = true ;
V_106 = V_116 ;
break;
default:
F_3 ( L_9 , V_6 , V_104 ) ;
return - V_7 ;
}
if ( V_105 ) {
if ( V_4 -> V_105 ) {
V_4 -> V_105 ( V_4 , V_30 -> V_33 ) ;
} else {
V_107 = F_43 ( V_4 -> V_117 ,
V_30 -> V_33 , V_106 ) ;
if ( V_107 != V_118 ) {
F_3 ( L_10
L_11 ,
V_6 , V_107 ,
V_4 -> V_2 -> V_96 , V_30 -> V_33 ) ;
V_36 = - V_119 ;
}
}
} else {
if ( V_4 -> V_120 ) {
V_36 = V_4 -> V_120 ( V_4 , V_30 -> V_33 , V_106 ) ;
} else {
V_107 = F_44 ( V_4 -> V_117 ,
V_30 -> V_33 , V_106 ) ;
if ( V_107 != V_118 ) {
F_3 ( L_12
L_13 ,
V_6 , V_107 , V_104 ,
V_4 -> V_2 -> V_96 , V_30 -> V_33 ) ;
V_36 = - V_119 ;
}
}
}
return V_36 ;
}
static int F_45 ( struct V_29 * V_30 )
{
return V_30 -> V_33 ;
}
static void F_46 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 -> V_9 ;
T_9 V_107 ;
V_107 = F_47 ( V_4 -> V_117 , V_30 -> V_45 ,
V_121 ) ;
if ( V_107 != V_118 )
F_3 ( L_14 ,
V_6 , V_107 , V_30 -> V_4 -> V_96 ) ;
}
static int F_48 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 -> V_9 ;
T_10 V_122 ;
T_11 V_123 ;
T_9 V_107 ;
int V_124 = 0 ;
V_107 = F_49 ( V_4 -> V_117 ,
V_30 -> V_33 ,
& V_122 ,
& V_123 ,
NULL ) ;
if ( V_107 != V_118 ) {
F_3 ( L_15 ,
V_6 , V_107 , V_4 -> V_2 -> V_96 ) ;
return V_125 ;
}
if ( F_50 ( V_123 ) != V_126 ) {
V_124 = ( V_127 |
V_128 |
V_129 |
V_130 ) ;
} else if ( ! ( V_30 -> V_100 & V_131 ) ) {
F_51 ( V_30 , V_131 ) ;
F_46 ( V_30 ) ;
if ( F_52 ( V_132 ) )
F_53 ( V_30 -> V_4 , V_30 -> V_45 ) ;
}
return V_124 ;
}
static int F_54 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 -> V_9 ;
T_10 V_122 ;
T_11 V_123 ;
T_9 V_107 ;
int V_124 ;
if ( V_30 -> V_100 & V_133 ) {
V_124 = ( V_127 |
V_128 |
V_129 |
V_130 ) ;
return V_124 ;
}
if ( V_4 -> V_134 ) {
V_122 = V_4 -> V_134 ( V_4 , V_30 -> V_33 ) ;
} else {
V_107 = F_49 ( V_4 -> V_117 ,
V_30 -> V_33 ,
& V_122 ,
& V_123 ,
NULL ) ;
if ( V_107 != V_118 ) {
F_3 ( L_16 ,
V_6 , V_107 , V_4 -> V_2 -> V_96 ,
V_30 -> V_33 ) ;
return V_125 ;
}
}
switch ( V_122 ) {
case V_135 :
V_124 = ( V_127 |
V_128 |
V_129 |
V_130 ) ;
break;
case V_136 :
V_124 = ( V_128 |
V_130 ) ;
break;
case V_137 :
V_124 = ( V_127 |
V_129 ) ;
break;
case V_138 :
V_124 = 0 ;
break;
case V_139 :
V_124 = V_140 ;
break;
case V_141 :
V_124 = V_142 ;
break;
case V_143 :
V_124 = V_125 ;
break;
default:
V_124 = V_125 ;
F_3 ( L_17 ,
V_6 , V_4 -> V_2 -> V_96 ,
V_30 -> V_33 , V_122 ) ;
}
if ( ! ( V_124 & V_125 ) &&
! ( V_124 & V_142 ) &&
! ( V_124 & V_127 ) &&
! ( V_124 & V_128 ) &&
! ( V_30 -> V_100 & V_131 ) ) {
if ( V_4 -> V_105 )
V_4 -> V_105 ( V_4 , V_30 -> V_33 ) ;
F_51 ( V_30 , V_131 ) ;
F_46 ( V_30 ) ;
if ( F_52 ( V_132 ) )
F_53 ( V_30 -> V_4 , V_30 -> V_45 ) ;
}
return V_124 ;
}
static int F_55 ( struct V_29 * V_30 , int * V_144 )
{
int V_36 ;
if ( V_30 -> type & V_145 )
V_36 = F_48 ( V_30 ) ;
else
V_36 = F_54 ( V_30 ) ;
if ( ! V_144 )
return V_36 ;
* V_144 = 0 ;
if ( V_36 & V_142 )
* V_144 = 1000 ;
return V_36 ;
}
static T_9 F_56 ( struct V_3 * V_4 )
{
T_9 V_107 = V_146 ;
while ( 1 ) {
V_107 = F_57 ( V_4 -> V_117 ) ;
if ( V_107 <= 0 )
break;
if ( V_147 < V_148 )
F_58 ( 1000 * V_107 ) ;
else
F_59 ( V_107 ) ;
}
return V_107 ;
}
int F_60 ( struct V_1 * V_2 , int V_104 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_107 = V_146 ;
F_61 ( L_18 ,
V_6 , V_2 -> V_96 , V_104 ) ;
if ( V_104 == V_149 ||
V_104 == V_150 )
V_107 = F_62 ( V_4 -> V_117 ,
V_151 ,
V_152 ) ;
else if ( V_104 == V_153 )
V_107 = F_62 ( V_4 -> V_117 ,
V_151 ,
V_154 ) ;
if ( V_107 < 0 )
goto V_155;
V_107 = F_56 ( V_4 ) ;
if ( V_104 == V_153 ) {
if ( V_147 < V_148 )
F_58 ( 1000 * V_156 ) ;
else
F_59 ( V_156 ) ;
}
V_155:
if ( V_107 != V_118 )
return - V_119 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , int V_104 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_107 = V_146 ;
F_61 ( L_18 ,
V_6 , V_2 -> V_96 , V_104 ) ;
if ( V_104 == V_149 )
V_107 = F_62 ( V_4 -> V_117 ,
V_157 ,
V_152 ) ;
else if ( V_104 == V_150 )
V_107 = F_62 ( V_4 -> V_117 ,
V_158 ,
V_152 ) ;
else if ( V_104 == V_153 )
V_107 = F_62 ( V_4 -> V_117 ,
V_158 ,
V_154 ) ;
if ( V_107 < 0 )
goto V_155;
V_107 = F_56 ( V_4 ) ;
if ( V_104 == V_153 )
F_59 ( V_156 ) ;
V_155:
if ( V_107 != V_118 )
return - V_119 ;
return 0 ;
}
static int F_64 ( struct V_159 * V_160 , int V_104 )
{
struct V_59 * V_60 = F_65 ( V_160 -> V_102 , V_160 -> V_94 ) ;
struct V_27 * V_28 = F_33 ( V_60 ) ;
int V_161 = V_28 ? V_28 -> V_82 : 0 ;
T_7 V_162 ;
F_61 ( L_19 ,
V_6 , F_66 ( V_160 -> V_102 ) ,
V_160 -> V_102 -> V_163 , V_104 ) ;
switch ( V_104 ) {
case V_149 :
case V_150 :
if ( V_161 ) {
V_37 -> V_164 ( V_60 , V_161 + V_165 ,
4 , & V_162 ) ;
V_162 |= V_166 ;
V_37 -> V_167 ( V_60 , V_161 + V_165 ,
4 , V_162 ) ;
}
V_37 -> V_164 ( V_60 , V_168 , 2 , & V_162 ) ;
V_162 |= V_169 ;
V_37 -> V_167 ( V_60 , V_168 , 2 , V_162 ) ;
F_59 ( V_170 ) ;
break;
case V_153 :
V_37 -> V_164 ( V_60 , V_168 , 2 , & V_162 ) ;
V_162 &= ~ V_169 ;
V_37 -> V_167 ( V_60 , V_168 , 2 , V_162 ) ;
F_59 ( V_156 ) ;
if ( V_161 ) {
V_37 -> V_164 ( V_60 , V_161 + V_165 ,
4 , & V_162 ) ;
V_162 &= ~ V_166 ;
V_37 -> V_167 ( V_60 , V_161 + V_165 ,
4 , V_162 ) ;
}
break;
}
return 0 ;
}
void F_67 ( struct V_159 * V_160 )
{
struct V_1 * V_2 ;
if ( F_68 ( V_160 -> V_102 ) ) {
V_2 = F_69 ( V_160 -> V_102 ) ;
F_63 ( V_2 , V_150 ) ;
F_63 ( V_2 , V_153 ) ;
} else {
F_64 ( V_160 , V_150 ) ;
F_64 ( V_160 , V_153 ) ;
}
}
static int F_70 ( struct V_29 * V_30 , int V_104 )
{
struct V_1 * V_2 = V_30 -> V_4 ;
struct V_171 * V_102 ;
int V_36 ;
if ( V_30 -> type & V_145 ) {
V_36 = F_60 ( V_2 , V_104 ) ;
} else {
struct V_3 * V_4 ;
T_9 V_107 ;
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 &&
( V_104 == V_150 ||
V_104 == V_149 ) ) {
V_107 = F_62 ( V_4 -> V_117 ,
V_172 ,
V_152 ) ;
if ( V_107 != V_118 ) {
F_3 ( L_20
L_21 ,
V_6 , V_107 ) ;
return - V_119 ;
}
}
V_102 = F_71 ( V_30 ) ;
if ( F_68 ( V_102 ) ||
F_68 ( V_102 -> V_173 ) )
V_36 = F_63 ( V_2 , V_104 ) ;
else
V_36 = F_64 ( V_102 -> V_174 , V_104 ) ;
}
return V_36 ;
}
static int F_72 ( struct V_29 * V_30 , int V_175 )
{
int V_36 ;
int V_176 ;
while ( 1 ) {
V_36 = F_55 ( V_30 , & V_176 ) ;
if ( V_36 != V_142 )
return V_36 ;
V_175 -= V_176 ;
if ( V_175 <= 0 ) {
F_3 ( L_22 ,
V_6 , V_30 -> V_33 , V_175 ) ;
return V_125 ;
}
F_59 ( V_176 ) ;
}
return V_125 ;
}
static int F_73 ( struct V_29 * V_30 , int V_177 ,
char * V_178 , unsigned long V_179 )
{
if ( ! F_52 ( V_132 ) )
F_53 ( V_30 -> V_4 , V_30 -> V_45 ) ;
return 0 ;
}
static int F_74 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_75 ( struct V_29 * V_30 , int type , int V_32 ,
unsigned long V_33 , unsigned long V_34 )
{
struct V_1 * V_2 = V_30 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_107 ;
if ( type != V_180 &&
type != V_181 ) {
F_3 ( L_23 ,
V_6 , type ) ;
return - V_182 ;
}
if ( V_32 < V_183 ||
V_32 > V_184 ) {
F_3 ( L_24 ,
V_6 , V_32 ) ;
return - V_182 ;
}
if ( ! F_76 ( V_185 ) ) {
F_3 ( L_25 ,
V_6 ) ;
return - V_39 ;
}
V_107 = F_77 ( V_4 -> V_117 , V_30 -> V_33 ,
type , V_32 , V_33 , V_34 ) ;
if ( V_107 != V_118 ) {
F_3 ( L_26
L_27 ,
V_6 , V_107 , type , V_32 ,
V_2 -> V_96 , V_30 -> V_33 ) ;
return - V_119 ;
}
return 0 ;
}
static inline bool F_78 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = F_33 ( V_60 ) ;
if ( ! V_28 || ! V_28 -> V_30 )
return false ;
if ( V_28 -> V_30 -> V_100 & V_186 )
return true ;
return false ;
}
static int F_79 ( struct V_59 * V_60 ,
int V_187 , int V_188 , T_7 * V_47 )
{
if ( ! V_60 )
return V_189 ;
if ( F_78 ( V_60 ) ) {
* V_47 = 0xFFFFFFFF ;
return V_190 ;
}
return F_30 ( V_60 , V_187 , V_188 , V_47 ) ;
}
static int F_80 ( struct V_59 * V_60 ,
int V_187 , int V_188 , T_7 V_47 )
{
if ( ! V_60 )
return V_189 ;
if ( F_78 ( V_60 ) )
return V_190 ;
return F_81 ( V_60 , V_187 , V_188 , V_47 ) ;
}
static void F_82 ( struct V_191 * V_45 )
{
if ( V_45 -> V_192 || V_45 -> V_193 ||
V_45 -> V_194 || V_45 -> V_195 || V_45 -> V_196 )
F_83 ( L_28 ,
F_84 ( V_45 -> V_192 ) ,
F_84 ( V_45 -> V_193 ) ,
F_84 ( V_45 -> V_194 ) ,
F_84 ( V_45 -> V_195 ) ,
F_84 ( V_45 -> V_196 ) ) ;
if ( V_45 -> V_197 || V_45 -> V_198 ||
V_45 -> V_199 || V_45 -> V_200 || V_45 -> V_201 )
F_83 ( L_29 ,
F_84 ( V_45 -> V_197 ) ,
F_84 ( V_45 -> V_198 ) ,
F_84 ( V_45 -> V_199 ) ,
F_84 ( V_45 -> V_200 ) ,
F_84 ( V_45 -> V_201 ) ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_191 * V_45 = & V_4 -> V_202 . V_203 ;
long V_107 ;
V_107 = F_86 ( V_4 -> V_204 , V_45 , sizeof( * V_45 ) ) ;
if ( V_107 != V_118 ) {
F_3 ( L_30 ,
V_6 , V_4 -> V_204 , V_107 ) ;
return;
}
switch ( V_45 -> type ) {
case V_205 :
F_83 ( L_31 ) ;
F_82 ( V_45 ) ;
if ( V_45 -> V_206 . V_207 || V_45 -> V_206 . V_208 )
F_83 ( L_32 ,
F_84 ( V_45 -> V_206 . V_207 ) ,
F_84 ( V_45 -> V_206 . V_208 ) ) ;
break;
case V_209 :
F_83 ( L_33 ,
V_45 -> V_210 . V_211 ? L_34 : L_35 ) ;
F_82 ( V_45 ) ;
if ( V_45 -> V_210 . V_212 || V_45 -> V_210 . V_213 ||
V_45 -> V_210 . V_214 || V_45 -> V_210 . V_215 )
F_83 ( L_36 ,
F_84 ( V_45 -> V_210 . V_212 ) ,
F_84 ( V_45 -> V_210 . V_213 ) ,
F_84 ( V_45 -> V_210 . V_214 ) ,
F_84 ( V_45 -> V_210 . V_215 ) ) ;
break;
case V_216 :
F_83 ( L_37 ,
V_45 -> V_217 . V_218 ) ;
F_82 ( V_45 ) ;
if ( V_45 -> V_217 . V_219 || V_45 -> V_217 . V_220 )
F_83 ( L_38 ,
F_84 ( V_45 -> V_217 . V_219 ) ,
F_84 ( V_45 -> V_217 . V_220 ) ) ;
break;
case V_221 :
F_83 ( L_39 ) ;
F_82 ( V_45 ) ;
break;
case V_222 :
F_83 ( L_40 ) ;
F_82 ( V_45 ) ;
break;
default:
F_3 ( L_41 ,
V_6 , V_4 -> V_204 , V_45 -> type ) ;
}
}
static int F_87 ( struct V_1 * V_2 ,
T_12 V_31 , struct V_29 * * V_30 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_223 * V_224 ;
struct V_29 * V_225 ;
struct V_27 V_28 ;
V_224 = & V_4 -> V_13 . V_226 [ V_31 ] ;
if ( V_224 -> V_51 & V_227 ) {
V_224 = V_224 -> V_228 ;
F_88 ( ! V_224 ||
! ( V_224 -> V_51 & V_229 ) ) ;
V_31 = V_224 -> V_230 ;
}
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_4 = V_2 ;
V_28 . V_43 = V_31 ;
V_225 = F_13 ( & V_28 ) ;
if ( ! V_225 )
return - V_231 ;
* V_30 = V_225 ;
if ( ! ( V_225 -> V_100 & V_131 ) )
V_4 -> V_105 ( V_4 , V_31 ) ;
V_225 = V_225 -> V_173 ;
while ( V_225 && ! ( V_225 -> type & V_145 ) ) {
int V_36 ;
int V_232 = ( V_127 |
V_128 ) ;
V_36 = V_37 -> V_233 ( V_225 , NULL ) ;
if ( V_36 <= 0 || ( V_36 & V_232 ) == V_232 ) {
V_225 = V_225 -> V_173 ;
continue;
}
* V_30 = V_225 ;
if ( ! ( V_225 -> V_100 & V_131 ) )
V_4 -> V_105 ( V_4 , V_225 -> V_33 ) ;
V_225 = V_225 -> V_173 ;
}
return 0 ;
}
static int F_89 ( struct V_29 * * V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_29 * V_234 , * V_235 ;
T_13 V_236 ;
T_11 V_237 , V_177 ;
int V_232 = ( V_127 | V_128 ) ;
long V_107 ;
int V_100 , V_36 = V_238 ;
F_90 ( NULL , false ) ;
F_9 ( V_21 , 0x0ul ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
V_234 = F_91 ( V_2 ) ;
if ( ! V_234 || ( V_234 -> V_100 & V_131 ) )
continue;
V_107 = F_92 ( V_4 -> V_117 ,
& V_236 , & V_237 , & V_177 ) ;
if ( V_107 != V_118 ) {
F_93 ( L_42
L_43 ,
V_6 , V_2 -> V_96 , V_107 ) ;
continue;
}
if ( F_50 ( V_237 ) == V_239 ||
F_50 ( V_177 ) == V_240 ) {
F_93 ( L_44 ,
V_6 , V_2 -> V_96 ) ;
continue;
}
F_93 ( L_45 ,
V_6 , F_50 ( V_237 ) ,
F_50 ( V_177 ) , F_84 ( V_236 ) ,
V_2 -> V_96 ) ;
switch ( F_50 ( V_237 ) ) {
case V_241 :
if ( F_50 ( V_177 ) == V_242 ) {
F_94 ( L_46 ) ;
V_36 = V_243 ;
} else if ( F_50 ( V_177 ) == V_244 ) {
F_83 ( L_47
L_48 ) ;
F_85 ( V_2 ) ;
V_36 = V_238 ;
}
break;
case V_126 :
if ( F_50 ( V_177 ) == V_245 ) {
* V_30 = V_234 ;
F_94 ( L_49
L_50 ,
V_2 -> V_96 ,
F_95 ( V_234 ) ) ;
V_36 = V_246 ;
} else if ( F_50 ( V_177 ) ==
V_247 ) {
* V_30 = V_234 ;
F_94 ( L_51
L_50 ,
V_2 -> V_96 ,
F_95 ( V_234 ) ) ;
V_36 = V_248 ;
} else if ( F_50 ( V_177 ) == V_244 ) {
F_83 ( L_52
L_53 ,
V_2 -> V_96 ,
F_95 ( V_234 ) ) ;
F_46 ( V_234 ) ;
F_53 ( V_2 , V_234 -> V_45 ) ;
V_36 = V_238 ;
}
break;
case V_249 :
if ( F_87 ( V_2 ,
F_84 ( V_236 ) , V_30 ) ) {
F_83 ( L_54 ,
V_2 -> V_96 , V_236 ) ;
F_83 ( L_55 ,
F_95 ( V_234 ) ) ;
F_44 ( V_4 -> V_117 ,
V_236 ,
V_250 ) ;
V_36 = V_238 ;
} else if ( ( * V_30 ) -> V_100 & V_131 ||
F_96 ( * V_30 ) ) {
V_36 = V_238 ;
} else {
F_94 ( L_56
L_57 ,
( * V_30 ) -> V_33 ,
( * V_30 ) -> V_4 -> V_96 ) ;
F_94 ( L_58
L_59 ,
F_95 ( * V_30 ) ,
F_95 ( V_234 ) ) ;
V_36 = V_251 ;
}
break;
default:
F_3 ( L_60 ,
V_6 , F_50 ( V_237 ) ) ;
}
if ( ( V_36 == V_251 ||
V_36 == V_248 ) &&
! ( ( * V_30 ) -> V_100 & V_131 ) ) {
F_51 ( * V_30 , V_131 ) ;
F_46 ( * V_30 ) ;
if ( F_52 ( V_132 ) )
F_53 ( ( * V_30 ) -> V_4 ,
( * V_30 ) -> V_45 ) ;
}
if ( V_36 == V_251 ) {
V_235 = ( * V_30 ) -> V_173 ;
while ( V_235 ) {
if ( V_235 -> type & V_145 )
break;
V_100 = V_37 -> V_233 ( V_235 , NULL ) ;
if ( V_100 > 0 &&
( V_100 & V_232 ) != V_232 )
* V_30 = V_235 ;
V_235 = V_235 -> V_173 ;
}
F_51 ( * V_30 , V_131 ) ;
}
if ( V_36 > V_252 )
break;
}
return V_36 ;
}
static int F_97 ( struct V_59 * V_60 )
{
struct V_27 * V_28 = F_33 ( V_60 ) ;
struct V_3 * V_4 ;
T_9 V_36 ;
if ( ! V_28 )
return - V_231 ;
V_4 = V_28 -> V_4 -> V_9 ;
V_36 = F_98 ( V_4 -> V_117 ,
V_253 , V_28 -> V_92 ) ;
if ( V_36 ) {
F_3 ( L_61 ,
V_6 , V_28 -> V_92 , V_36 ) ;
return - V_119 ;
}
return 0 ;
}
static int T_14 F_99 ( void )
{
int V_36 = - V_7 ;
F_100 ( V_121 ) ;
V_36 = F_101 ( & V_254 ) ;
if ( ! V_36 )
F_83 ( L_62 ) ;
else
F_83 ( L_63 , V_36 ) ;
return V_36 ;
}
