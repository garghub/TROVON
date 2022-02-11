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
static int F_34 ( struct V_57 * V_58 )
{
T_7 V_59 ;
if ( ! V_58 )
return 0 ;
F_35 ( V_58 , V_60 , 2 , & V_59 ) ;
if ( ! ( V_59 & V_61 ) )
return 0 ;
return V_62 ;
}
static int F_36 ( struct V_57 * V_58 , int V_63 )
{
int V_64 = F_34 ( V_58 ) ;
int V_65 = 48 ;
T_7 V_66 ;
if ( ! V_64 )
return 0 ;
while ( V_65 -- ) {
F_35 ( V_58 , V_64 , 1 , & V_64 ) ;
if ( V_64 < 0x40 )
break;
V_64 &= ~ 3 ;
F_35 ( V_58 , V_64 + V_67 , 1 , & V_66 ) ;
if ( V_66 == 0xff )
break;
if ( V_66 == V_63 )
return V_64 ;
V_64 += V_68 ;
}
return 0 ;
}
static int F_37 ( struct V_57 * V_58 , int V_63 )
{
struct V_24 * V_25 = F_38 ( V_58 ) ;
T_7 V_69 ;
int V_64 = 256 , V_70 = ( 4096 - 256 ) / 8 ;
if ( ! V_25 || ! V_25 -> V_71 )
return 0 ;
if ( F_35 ( V_58 , V_64 , 4 , & V_69 ) != V_72 )
return 0 ;
else if ( ! V_69 )
return 0 ;
while ( V_70 -- > 0 ) {
if ( F_39 ( V_69 ) == V_63 && V_64 )
return V_64 ;
V_64 = F_40 ( V_69 ) ;
if ( V_64 < 256 )
break;
if ( F_35 ( V_58 , V_64 , 4 , & V_69 ) != V_72 )
break;
}
return 0 ;
}
static void * F_41 ( struct V_57 * V_58 , void * V_17 )
{
struct V_1 * V_2 = V_58 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_24 * V_25 = F_38 ( V_58 ) ;
T_8 V_73 ;
int V_33 ;
if ( ! V_25 || V_25 -> V_27 )
return NULL ;
if ( ( V_58 -> V_74 >> 8 ) == V_75 )
return NULL ;
V_25 -> V_74 = V_58 -> V_74 ;
V_25 -> V_76 &= 0xFFFFFF00 ;
V_25 -> V_77 = F_36 ( V_58 , V_78 ) ;
V_25 -> V_71 = F_36 ( V_58 , V_79 ) ;
V_25 -> V_80 = F_37 ( V_58 , V_81 ) ;
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
V_33 = F_42 ( V_25 ) ;
if ( V_33 ) {
F_3 ( L_10 ,
V_6 , V_2 -> V_94 , V_58 -> V_91 ,
F_43 ( V_58 -> V_92 ) , F_44 ( V_58 -> V_92 ) , V_33 ) ;
return NULL ;
}
if ( ( V_58 -> V_95 == V_96 &&
V_58 -> V_97 == 0x1657 ) ||
( V_58 -> V_95 == V_96 &&
V_58 -> V_97 == 0x168e ) )
V_25 -> V_27 -> V_98 |= V_99 ;
if ( ! V_25 -> V_27 -> V_100 )
V_25 -> V_27 -> V_100 = F_45 ( V_2 -> V_94 ,
V_58 -> V_91 ) ;
F_4 ( V_101 ) ;
F_46 ( V_25 ) ;
return NULL ;
}
static int F_47 ( struct V_26 * V_27 , int V_102 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_3 * V_4 = V_2 -> V_9 ;
bool V_103 = false ;
int V_104 , V_33 = 0 ;
T_9 V_105 ;
switch ( V_102 ) {
case V_106 :
return - V_107 ;
case V_108 :
return 0 ;
case V_109 :
V_104 = V_110 ;
break;
case V_111 :
V_104 = V_112 ;
break;
case V_113 :
V_103 = true ;
V_104 = V_114 ;
break;
default:
F_3 ( L_11 , V_6 , V_102 ) ;
return - V_7 ;
}
if ( V_103 ) {
if ( V_4 -> V_103 ) {
V_4 -> V_103 ( V_4 , V_27 -> V_30 ) ;
} else {
V_105 = F_48 ( V_4 -> V_115 ,
V_27 -> V_30 , V_104 ) ;
if ( V_105 != V_116 ) {
F_3 ( L_12
L_13 ,
V_6 , V_105 ,
V_4 -> V_2 -> V_94 , V_27 -> V_30 ) ;
V_33 = - V_117 ;
}
}
} else {
if ( V_4 -> V_118 ) {
V_33 = V_4 -> V_118 ( V_4 , V_27 -> V_30 , V_104 ) ;
} else {
V_105 = F_49 ( V_4 -> V_115 ,
V_27 -> V_30 , V_104 ) ;
if ( V_105 != V_116 ) {
F_3 ( L_14
L_15 ,
V_6 , V_105 , V_102 ,
V_4 -> V_2 -> V_94 , V_27 -> V_30 ) ;
V_33 = - V_117 ;
}
}
}
return V_33 ;
}
static int F_50 ( struct V_26 * V_27 )
{
return V_27 -> V_30 ;
}
static void F_51 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_9 V_105 ;
V_105 = F_52 ( V_4 -> V_115 , V_27 -> V_17 ,
V_119 ) ;
if ( V_105 != V_116 )
F_3 ( L_16 ,
V_6 , V_105 , V_27 -> V_4 -> V_94 ) ;
}
static int F_53 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_10 V_120 ;
T_11 V_121 ;
T_9 V_105 ;
int V_122 = 0 ;
V_105 = F_54 ( V_4 -> V_115 ,
V_27 -> V_30 ,
& V_120 ,
& V_121 ,
NULL ) ;
if ( V_105 != V_116 ) {
F_3 ( L_17 ,
V_6 , V_105 , V_4 -> V_2 -> V_94 ) ;
return V_123 ;
}
if ( F_55 ( V_121 ) != V_124 ) {
V_122 = ( V_125 |
V_126 |
V_127 |
V_128 ) ;
} else if ( ! ( V_27 -> V_98 & V_129 ) ) {
F_56 ( V_27 , V_129 ) ;
F_51 ( V_27 ) ;
if ( F_57 ( V_130 ) )
F_58 ( V_27 -> V_4 , V_27 -> V_17 ) ;
}
return V_122 ;
}
static int F_59 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_4 -> V_9 ;
T_10 V_120 ;
T_11 V_121 ;
T_9 V_105 ;
int V_122 ;
if ( V_27 -> V_98 & V_131 ) {
V_122 = ( V_125 |
V_126 |
V_127 |
V_128 ) ;
return V_122 ;
}
if ( V_4 -> V_132 ) {
V_120 = V_4 -> V_132 ( V_4 , V_27 -> V_30 ) ;
} else {
V_105 = F_54 ( V_4 -> V_115 ,
V_27 -> V_30 ,
& V_120 ,
& V_121 ,
NULL ) ;
if ( V_105 != V_116 ) {
F_3 ( L_18 ,
V_6 , V_105 , V_4 -> V_2 -> V_94 ,
V_27 -> V_30 ) ;
return V_123 ;
}
}
switch ( V_120 ) {
case V_133 :
V_122 = ( V_125 |
V_126 |
V_127 |
V_128 ) ;
break;
case V_134 :
V_122 = ( V_126 |
V_128 ) ;
break;
case V_135 :
V_122 = ( V_125 |
V_127 ) ;
break;
case V_136 :
V_122 = 0 ;
break;
case V_137 :
V_122 = V_138 ;
break;
case V_139 :
V_122 = V_140 ;
break;
case V_141 :
V_122 = V_123 ;
break;
default:
V_122 = V_123 ;
F_3 ( L_19 ,
V_6 , V_4 -> V_2 -> V_94 ,
V_27 -> V_30 , V_120 ) ;
}
if ( ! ( V_122 & V_123 ) &&
! ( V_122 & V_140 ) &&
! ( V_122 & V_125 ) &&
! ( V_122 & V_126 ) &&
! ( V_27 -> V_98 & V_129 ) ) {
if ( V_4 -> V_103 )
V_4 -> V_103 ( V_4 , V_27 -> V_30 ) ;
F_56 ( V_27 , V_129 ) ;
F_51 ( V_27 ) ;
if ( F_57 ( V_130 ) )
F_58 ( V_27 -> V_4 , V_27 -> V_17 ) ;
}
return V_122 ;
}
static int F_60 ( struct V_26 * V_27 , int * V_142 )
{
int V_33 ;
if ( V_27 -> type & V_143 )
V_33 = F_53 ( V_27 ) ;
else
V_33 = F_59 ( V_27 ) ;
if ( ! V_142 )
return V_33 ;
* V_142 = 0 ;
if ( V_33 & V_140 )
* V_142 = 1000 ;
return V_33 ;
}
static T_9 F_61 ( struct V_3 * V_4 )
{
T_9 V_105 = V_144 ;
while ( 1 ) {
V_105 = F_62 ( V_4 -> V_115 ) ;
if ( V_105 <= 0 )
break;
if ( V_145 < V_146 )
F_63 ( 1000 * V_105 ) ;
else
F_64 ( V_105 ) ;
}
return V_105 ;
}
int F_65 ( struct V_1 * V_2 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_105 = V_144 ;
F_66 ( L_20 ,
V_6 , V_2 -> V_94 , V_102 ) ;
if ( V_102 == V_147 ||
V_102 == V_148 )
V_105 = F_67 ( V_4 -> V_115 ,
V_149 ,
V_150 ) ;
else if ( V_102 == V_151 )
V_105 = F_67 ( V_4 -> V_115 ,
V_149 ,
V_152 ) ;
if ( V_105 < 0 )
goto V_153;
V_105 = F_61 ( V_4 ) ;
if ( V_102 == V_151 ) {
if ( V_145 < V_146 )
F_63 ( 1000 * V_154 ) ;
else
F_64 ( V_154 ) ;
}
V_153:
if ( V_105 != V_116 )
return - V_117 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_102 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
T_9 V_105 = V_144 ;
F_66 ( L_20 ,
V_6 , V_2 -> V_94 , V_102 ) ;
if ( V_102 == V_147 )
V_105 = F_67 ( V_4 -> V_115 ,
V_155 ,
V_150 ) ;
else if ( V_102 == V_148 )
V_105 = F_67 ( V_4 -> V_115 ,
V_156 ,
V_150 ) ;
else if ( V_102 == V_151 )
V_105 = F_67 ( V_4 -> V_115 ,
V_156 ,
V_152 ) ;
if ( V_105 < 0 )
goto V_153;
V_105 = F_61 ( V_4 ) ;
if ( V_102 == V_151 )
F_64 ( V_154 ) ;
V_153:
if ( V_105 != V_116 )
return - V_117 ;
return 0 ;
}
static int F_69 ( struct V_157 * V_158 , int V_102 )
{
struct V_57 * V_58 = F_70 ( V_158 -> V_100 , V_158 -> V_92 ) ;
struct V_24 * V_25 = F_38 ( V_58 ) ;
int V_159 = V_25 ? V_25 -> V_80 : 0 ;
T_7 V_160 ;
F_66 ( L_21 ,
V_6 , F_71 ( V_158 -> V_100 ) ,
V_158 -> V_100 -> V_161 , V_102 ) ;
switch ( V_102 ) {
case V_147 :
case V_148 :
if ( V_159 ) {
V_34 -> V_162 ( V_58 , V_159 + V_163 ,
4 , & V_160 ) ;
V_160 |= V_164 ;
V_34 -> V_165 ( V_58 , V_159 + V_163 ,
4 , V_160 ) ;
}
V_34 -> V_162 ( V_58 , V_166 , 2 , & V_160 ) ;
V_160 |= V_167 ;
V_34 -> V_165 ( V_58 , V_166 , 2 , V_160 ) ;
F_64 ( V_168 ) ;
break;
case V_151 :
V_34 -> V_162 ( V_58 , V_166 , 2 , & V_160 ) ;
V_160 &= ~ V_167 ;
V_34 -> V_165 ( V_58 , V_166 , 2 , V_160 ) ;
F_64 ( V_154 ) ;
if ( V_159 ) {
V_34 -> V_162 ( V_58 , V_159 + V_163 ,
4 , & V_160 ) ;
V_160 &= ~ V_164 ;
V_34 -> V_165 ( V_58 , V_159 + V_163 ,
4 , V_160 ) ;
}
break;
}
return 0 ;
}
void F_72 ( struct V_157 * V_158 )
{
struct V_1 * V_2 ;
if ( F_73 ( V_158 -> V_100 ) ) {
V_2 = F_74 ( V_158 -> V_100 ) ;
F_68 ( V_2 , V_148 ) ;
F_68 ( V_2 , V_151 ) ;
} else {
F_69 ( V_158 , V_148 ) ;
F_69 ( V_158 , V_151 ) ;
}
}
static int F_75 ( struct V_26 * V_27 , int V_102 )
{
struct V_1 * V_2 = V_27 -> V_4 ;
struct V_169 * V_100 ;
int V_33 ;
if ( V_27 -> type & V_143 ) {
V_33 = F_65 ( V_2 , V_102 ) ;
} else {
struct V_3 * V_4 ;
T_9 V_105 ;
V_4 = V_2 -> V_9 ;
if ( V_4 -> V_10 == V_11 &&
( V_102 == V_148 ||
V_102 == V_147 ) ) {
V_105 = F_67 ( V_4 -> V_115 ,
V_170 ,
V_150 ) ;
if ( V_105 != V_116 ) {
F_3 ( L_22
L_23 ,
V_6 , V_105 ) ;
return - V_117 ;
}
}
V_100 = F_76 ( V_27 ) ;
if ( F_73 ( V_100 ) ||
F_73 ( V_100 -> V_171 ) )
V_33 = F_68 ( V_2 , V_102 ) ;
else
V_33 = F_69 ( V_100 -> V_172 , V_102 ) ;
}
return V_33 ;
}
static int F_77 ( struct V_26 * V_27 , int V_173 )
{
int V_33 ;
int V_174 ;
while ( 1 ) {
V_33 = F_60 ( V_27 , & V_174 ) ;
if ( V_33 != V_140 )
return V_33 ;
if ( V_173 <= 0 ) {
F_3 ( L_24 ,
V_6 , V_27 -> V_30 , V_173 ) ;
return V_123 ;
}
V_173 -= V_174 ;
F_64 ( V_174 ) ;
}
return V_123 ;
}
static int F_78 ( struct V_26 * V_27 , int V_175 ,
char * V_176 , unsigned long V_177 )
{
if ( ! F_57 ( V_130 ) )
F_58 ( V_27 -> V_4 , V_27 -> V_17 ) ;
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
T_9 V_105 ;
if ( type != V_178 &&
type != V_179 ) {
F_3 ( L_25 ,
V_6 , type ) ;
return - V_180 ;
}
if ( V_29 < V_181 ||
V_29 > V_182 ) {
F_3 ( L_26 ,
V_6 , V_29 ) ;
return - V_180 ;
}
if ( ! F_81 ( V_183 ) ) {
F_3 ( L_27 ,
V_6 ) ;
return - V_36 ;
}
V_105 = F_82 ( V_4 -> V_115 , V_27 -> V_30 ,
type , V_29 , V_30 , V_31 ) ;
if ( V_105 != V_116 ) {
F_3 ( L_28
L_29 ,
V_6 , V_105 , type , V_29 ,
V_2 -> V_94 , V_27 -> V_30 ) ;
return - V_117 ;
}
return 0 ;
}
static inline bool F_83 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_38 ( V_58 ) ;
if ( ! V_25 || ! V_25 -> V_27 )
return false ;
if ( V_25 -> V_27 -> V_98 & V_184 )
return true ;
return false ;
}
static int F_84 ( struct V_57 * V_58 ,
int V_185 , int V_186 , T_7 * V_43 )
{
if ( ! V_58 )
return V_187 ;
if ( F_83 ( V_58 ) ) {
* V_43 = 0xFFFFFFFF ;
return V_188 ;
}
return F_35 ( V_58 , V_185 , V_186 , V_43 ) ;
}
static int F_85 ( struct V_57 * V_58 ,
int V_185 , int V_186 , T_7 V_43 )
{
if ( ! V_58 )
return V_187 ;
if ( F_83 ( V_58 ) )
return V_188 ;
return F_86 ( V_58 , V_185 , V_186 , V_43 ) ;
}
static void F_87 ( struct V_189 * V_17 )
{
if ( V_17 -> V_190 || V_17 -> V_191 ||
V_17 -> V_192 || V_17 -> V_193 || V_17 -> V_194 )
F_88 ( L_30 ,
F_89 ( V_17 -> V_190 ) ,
F_89 ( V_17 -> V_191 ) ,
F_89 ( V_17 -> V_192 ) ,
F_89 ( V_17 -> V_193 ) ,
F_89 ( V_17 -> V_194 ) ) ;
if ( V_17 -> V_195 || V_17 -> V_196 ||
V_17 -> V_197 || V_17 -> V_198 || V_17 -> V_199 )
F_88 ( L_31 ,
F_89 ( V_17 -> V_195 ) ,
F_89 ( V_17 -> V_196 ) ,
F_89 ( V_17 -> V_197 ) ,
F_89 ( V_17 -> V_198 ) ,
F_89 ( V_17 -> V_199 ) ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_189 * V_17 = & V_4 -> V_200 . V_201 ;
long V_105 ;
V_105 = F_91 ( V_4 -> V_202 , V_17 , sizeof( * V_17 ) ) ;
if ( V_105 != V_116 ) {
F_3 ( L_32 ,
V_6 , V_4 -> V_202 , V_105 ) ;
return;
}
switch ( V_17 -> type ) {
case V_203 :
F_88 ( L_33 ) ;
F_87 ( V_17 ) ;
if ( V_17 -> V_204 . V_205 || V_17 -> V_204 . V_206 )
F_88 ( L_34 ,
F_89 ( V_17 -> V_204 . V_205 ) ,
F_89 ( V_17 -> V_204 . V_206 ) ) ;
break;
case V_207 :
F_88 ( L_35 ,
V_17 -> V_208 . V_209 ? L_36 : L_37 ) ;
F_87 ( V_17 ) ;
if ( V_17 -> V_208 . V_210 || V_17 -> V_208 . V_211 ||
V_17 -> V_208 . V_212 || V_17 -> V_208 . V_213 )
F_88 ( L_38 ,
F_89 ( V_17 -> V_208 . V_210 ) ,
F_89 ( V_17 -> V_208 . V_211 ) ,
F_89 ( V_17 -> V_208 . V_212 ) ,
F_89 ( V_17 -> V_208 . V_213 ) ) ;
break;
case V_214 :
F_88 ( L_39 ,
V_17 -> V_215 . V_216 ) ;
F_87 ( V_17 ) ;
if ( V_17 -> V_215 . V_217 || V_17 -> V_215 . V_218 )
F_88 ( L_40 ,
F_89 ( V_17 -> V_215 . V_217 ) ,
F_89 ( V_17 -> V_215 . V_218 ) ) ;
break;
case V_219 :
F_88 ( L_41 ) ;
F_87 ( V_17 ) ;
break;
case V_220 :
F_88 ( L_42 ) ;
F_87 ( V_17 ) ;
break;
default:
F_3 ( L_43 ,
V_6 , V_4 -> V_202 , V_17 -> type ) ;
}
}
static int F_92 ( struct V_1 * V_2 ,
T_12 V_28 , struct V_26 * * V_27 )
{
struct V_3 * V_4 = V_2 -> V_9 ;
struct V_221 * V_222 ;
struct V_26 * V_223 ;
struct V_24 V_25 ;
V_222 = & V_4 -> V_13 . V_224 [ V_28 ] ;
if ( V_222 -> V_49 & V_225 ) {
V_222 = V_222 -> V_226 ;
F_93 ( ! V_222 ||
! ( V_222 -> V_49 & V_227 ) ) ;
V_28 = V_222 -> V_228 ;
}
memset ( & V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 . V_4 = V_2 ;
V_25 . V_40 = V_28 ;
V_223 = F_13 ( & V_25 ) ;
if ( ! V_223 )
return - V_229 ;
* V_27 = V_223 ;
if ( ! ( V_223 -> V_98 & V_129 ) )
V_4 -> V_103 ( V_4 , V_28 ) ;
V_223 = V_223 -> V_171 ;
while ( V_223 && ! ( V_223 -> type & V_143 ) ) {
int V_33 ;
int V_230 = ( V_125 |
V_126 ) ;
V_33 = V_34 -> V_231 ( V_223 , NULL ) ;
if ( V_33 <= 0 || ( V_33 & V_230 ) == V_230 ) {
V_223 = V_223 -> V_171 ;
continue;
}
* V_27 = V_223 ;
if ( ! ( V_223 -> V_98 & V_129 ) )
V_4 -> V_103 ( V_4 , V_223 -> V_30 ) ;
V_223 = V_223 -> V_171 ;
}
return 0 ;
}
static int F_94 ( struct V_26 * * V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_26 * V_232 , * V_233 ;
T_13 V_234 ;
T_11 V_235 , V_175 ;
int V_230 = ( V_125 | V_126 ) ;
long V_105 ;
int V_98 , V_33 = V_236 ;
F_95 ( NULL , false ) ;
F_5 (hose, &hose_list, list_node) {
V_4 = V_2 -> V_9 ;
V_232 = F_96 ( V_2 ) ;
if ( ! V_232 || ( V_232 -> V_98 & V_129 ) )
continue;
V_105 = F_97 ( V_4 -> V_115 ,
& V_234 , & V_235 , & V_175 ) ;
if ( V_105 != V_116 ) {
F_98 ( L_44
L_45 ,
V_6 , V_2 -> V_94 , V_105 ) ;
continue;
}
if ( F_55 ( V_235 ) == V_237 ||
F_55 ( V_175 ) == V_238 ) {
F_98 ( L_46 ,
V_6 , V_2 -> V_94 ) ;
continue;
}
F_98 ( L_47 ,
V_6 , F_55 ( V_235 ) ,
F_55 ( V_175 ) , F_89 ( V_234 ) ,
V_2 -> V_94 ) ;
switch ( F_55 ( V_235 ) ) {
case V_239 :
if ( F_55 ( V_175 ) == V_240 ) {
F_28 ( L_48 ) ;
V_33 = V_241 ;
} else if ( F_55 ( V_175 ) == V_242 ) {
F_88 ( L_49
L_50 ) ;
F_90 ( V_2 ) ;
V_33 = V_236 ;
}
break;
case V_124 :
if ( F_55 ( V_175 ) == V_243 ) {
* V_27 = V_232 ;
F_28 ( L_51
L_52 ,
V_2 -> V_94 ,
F_99 ( V_232 ) ) ;
V_33 = V_244 ;
} else if ( F_55 ( V_175 ) ==
V_245 ) {
* V_27 = V_232 ;
F_28 ( L_53
L_52 ,
V_2 -> V_94 ,
F_99 ( V_232 ) ) ;
V_33 = V_246 ;
} else if ( F_55 ( V_175 ) == V_242 ) {
F_88 ( L_54
L_55 ,
V_2 -> V_94 ,
F_99 ( V_232 ) ) ;
F_51 ( V_232 ) ;
F_58 ( V_2 , V_232 -> V_17 ) ;
V_33 = V_236 ;
}
break;
case V_247 :
if ( F_92 ( V_2 ,
F_89 ( V_234 ) , V_27 ) ) {
F_88 ( L_56 ,
V_2 -> V_94 , F_89 ( V_234 ) ) ;
F_88 ( L_57 ,
F_99 ( V_232 ) ) ;
V_105 = F_52 ( V_4 -> V_115 ,
V_4 -> V_200 . V_248 , V_119 ) ;
if ( V_105 == V_116 )
F_58 ( V_2 ,
V_4 -> V_200 . V_248 ) ;
F_49 ( V_4 -> V_115 ,
V_234 ,
V_249 ) ;
V_33 = V_236 ;
} else if ( ( * V_27 ) -> V_98 & V_129 ||
F_100 ( * V_27 ) ) {
V_33 = V_236 ;
} else {
F_28 ( L_58
L_59 ,
( * V_27 ) -> V_30 ,
( * V_27 ) -> V_4 -> V_94 ) ;
F_28 ( L_60
L_61 ,
F_99 ( * V_27 ) ,
F_99 ( V_232 ) ) ;
V_33 = V_250 ;
}
break;
default:
F_3 ( L_62 ,
V_6 , F_55 ( V_235 ) ) ;
}
if ( ( V_33 == V_250 ||
V_33 == V_246 ) &&
! ( ( * V_27 ) -> V_98 & V_129 ) ) {
F_56 ( * V_27 , V_129 ) ;
F_51 ( * V_27 ) ;
if ( F_57 ( V_130 ) )
F_58 ( ( * V_27 ) -> V_4 ,
( * V_27 ) -> V_17 ) ;
}
if ( V_33 == V_250 ) {
V_233 = ( * V_27 ) -> V_171 ;
while ( V_233 ) {
if ( V_233 -> type & V_143 )
break;
V_98 = V_34 -> V_231 ( V_233 , NULL ) ;
if ( V_98 > 0 &&
( V_98 & V_230 ) != V_230 )
* V_27 = V_233 ;
V_233 = V_233 -> V_171 ;
}
F_56 ( * V_27 , V_129 ) ;
}
if ( V_33 > V_251 )
break;
}
if ( V_33 == V_236 && F_8 () )
F_101 ( V_46 ) ;
return V_33 ;
}
static int F_102 ( struct V_57 * V_58 )
{
struct V_24 * V_25 = F_38 ( V_58 ) ;
struct V_3 * V_4 ;
T_9 V_33 ;
if ( ! V_25 )
return - V_229 ;
V_4 = V_25 -> V_4 -> V_9 ;
V_33 = F_103 ( V_4 -> V_115 ,
V_252 , V_25 -> V_90 ) ;
if ( V_33 ) {
F_3 ( L_63 ,
V_6 , V_25 -> V_90 , V_33 ) ;
return - V_117 ;
}
return 0 ;
}
static int T_14 F_104 ( void )
{
int V_33 = - V_7 ;
F_105 ( V_119 ) ;
V_33 = F_106 ( & V_253 ) ;
if ( ! V_33 )
F_88 ( L_64 ) ;
else
F_88 ( L_65 , V_33 ) ;
return V_33 ;
}
