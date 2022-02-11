static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 = ( T_1 ) V_4 ;
if ( ! ( V_5 & V_6 ) ||
! ( V_3 & V_6 ) )
return 0 ;
if ( F_2 () )
F_3 ( NULL ) ;
else
F_4 ( V_6 , 0x0ul ) ;
return 0 ;
}
static T_2 F_5 ( struct V_7 * V_8 ,
const char T_3 * V_9 ,
T_4 V_10 , T_5 * V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_14 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 , type , V_22 ;
unsigned long V_23 , V_24 ;
char V_25 [ 50 ] ;
int V_26 ;
if ( ! V_16 -> V_27 || ! V_16 -> V_27 -> V_28 )
return - V_29 ;
V_26 = F_6 ( V_25 , sizeof( V_25 ) , V_11 , V_9 , V_10 ) ;
if ( ! V_26 )
return - V_30 ;
V_26 = sscanf ( V_25 , L_1 ,
& V_21 , & type , & V_22 , & V_23 , & V_24 ) ;
if ( V_26 != 5 )
return - V_31 ;
V_18 = F_7 ( sizeof( * V_18 ) , V_32 ) ;
if ( ! V_18 )
return - V_33 ;
V_18 -> V_16 = V_13 ;
V_18 -> V_34 = V_21 ;
V_20 = F_8 ( V_18 ) ;
F_9 ( V_18 ) ;
if ( ! V_20 )
return - V_35 ;
V_26 = V_16 -> V_27 -> V_28 ( V_20 , type , V_22 , V_23 , V_24 ) ;
return V_26 < 0 ? V_26 : V_10 ;
}
static int F_10 ( void * V_36 , int V_37 , T_6 V_38 )
{
struct V_12 * V_13 = V_36 ;
struct V_15 * V_16 = V_13 -> V_14 ;
F_11 ( V_16 -> V_39 + V_37 , V_38 ) ;
return 0 ;
}
static int F_12 ( void * V_36 , int V_37 , T_6 * V_38 )
{
struct V_12 * V_13 = V_36 ;
struct V_15 * V_16 = V_13 -> V_14 ;
* V_38 = F_13 ( V_16 -> V_39 + V_37 ) ;
return 0 ;
}
static int F_14 ( void * V_36 , T_6 V_38 )
{
return F_10 ( V_36 , 0xD10 , V_38 ) ;
}
static int F_15 ( void * V_36 , T_6 * V_38 )
{
return F_12 ( V_36 , 0xD10 , V_38 ) ;
}
static int F_16 ( void * V_36 , T_6 V_38 )
{
return F_10 ( V_36 , 0xD90 , V_38 ) ;
}
static int F_17 ( void * V_36 , T_6 * V_38 )
{
return F_12 ( V_36 , 0xD90 , V_38 ) ;
}
static int F_18 ( void * V_36 , T_6 V_38 )
{
return F_10 ( V_36 , 0xE10 , V_38 ) ;
}
static int F_19 ( void * V_36 , T_6 * V_38 )
{
return F_12 ( V_36 , 0xE10 , V_38 ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_14 ;
int V_26 ;
if ( ! V_40 ) {
V_26 = F_21 ( & V_41 ) ;
if ( V_26 ) {
F_22 ( L_2 ,
V_42 , V_26 ) ;
return V_26 ;
}
V_40 = 1 ;
}
#ifdef F_23
if ( ! V_16 -> V_43 && V_16 -> V_44 ) {
V_16 -> V_43 = 1 ;
F_24 ( L_3 , 0200 ,
V_16 -> V_44 , V_13 ,
& V_45 ) ;
F_24 ( L_4 , 0600 ,
V_16 -> V_44 , V_13 ,
& V_46 ) ;
F_24 ( L_5 , 0600 ,
V_16 -> V_44 , V_13 ,
& V_47 ) ;
F_24 ( L_6 , 0600 ,
V_16 -> V_44 , V_13 ,
& V_48 ) ;
}
#endif
if ( F_2 () )
V_16 -> V_49 |= V_50 ;
else
V_16 -> V_49 &= ~ V_50 ;
return 0 ;
}
static int F_25 ( struct V_19 * V_20 , int V_51 )
{
struct V_12 * V_13 = V_20 -> V_16 ;
struct V_15 * V_16 = V_13 -> V_14 ;
bool V_52 = false ;
int V_53 , V_26 = 0 ;
T_7 V_54 ;
if ( V_20 -> V_23 < 0 || V_20 -> V_23 >= V_16 -> V_55 . V_56 ) {
F_22 ( L_7
L_8 ,
V_42 , V_20 -> V_23 , V_16 -> V_55 . V_56 ,
V_13 -> V_57 ) ;
return - V_31 ;
}
switch ( V_51 ) {
case V_58 :
return - V_59 ;
case V_60 :
return 0 ;
case V_61 :
V_53 = V_62 ;
break;
case V_63 :
V_53 = V_64 ;
break;
case V_65 :
V_52 = true ;
V_53 = V_66 ;
break;
default:
F_26 ( L_9 ,
V_42 , V_51 ) ;
return - V_31 ;
}
if ( V_52 ) {
if ( V_16 -> V_52 ) {
V_16 -> V_52 ( V_16 , V_20 -> V_23 ) ;
} else {
V_54 = F_27 ( V_16 -> V_67 ,
V_20 -> V_23 ,
V_53 ) ;
if ( V_54 != V_68 ) {
F_26 ( L_10
L_11 ,
V_42 , V_54 ,
V_16 -> V_13 -> V_57 , V_20 -> V_23 ) ;
V_26 = - V_69 ;
}
}
} else {
if ( V_16 -> V_70 ) {
V_26 = V_16 -> V_70 ( V_16 , V_20 -> V_23 , V_53 ) ;
} else {
V_54 = F_28 ( V_16 -> V_67 ,
V_20 -> V_23 ,
V_53 ) ;
if ( V_54 != V_68 ) {
F_26 ( L_12
L_13 ,
V_42 , V_54 , V_51 ,
V_16 -> V_13 -> V_57 , V_20 -> V_23 ) ;
V_26 = - V_69 ;
}
}
}
return V_26 ;
}
static void F_29 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_16 -> V_14 ;
long V_54 ;
V_54 = F_30 ( V_16 -> V_67 , V_20 -> V_36 ,
V_71 ) ;
if ( V_54 != V_68 )
F_26 ( L_14 ,
V_42 , V_20 -> V_16 -> V_57 , V_54 ) ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_16 -> V_14 ;
T_8 V_72 ;
T_9 V_73 ;
T_7 V_54 ;
int V_74 = 0 ;
V_54 = F_32 ( V_16 -> V_67 ,
V_20 -> V_23 ,
& V_72 ,
& V_73 ,
NULL ) ;
if ( V_54 != V_68 ) {
F_26 ( L_15 ,
V_42 , V_54 , V_16 -> V_13 -> V_57 ) ;
return V_75 ;
}
if ( F_33 ( V_73 ) != V_76 ) {
V_74 = ( V_77 |
V_78 |
V_79 |
V_80 ) ;
} else if ( ! ( V_20 -> V_81 & V_82 ) ) {
F_34 ( V_20 , V_82 ) ;
F_29 ( V_20 ) ;
}
return V_74 ;
}
static int F_35 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_16 -> V_14 ;
T_8 V_72 ;
T_9 V_73 ;
T_7 V_54 ;
int V_74 ;
if ( V_20 -> V_81 & V_83 ) {
V_74 = ( V_77 |
V_78 |
V_79 |
V_80 ) ;
return V_74 ;
}
if ( V_16 -> V_84 ) {
V_72 = V_16 -> V_84 ( V_16 , V_20 -> V_23 ) ;
} else {
V_54 = F_32 ( V_16 -> V_67 ,
V_20 -> V_23 ,
& V_72 ,
& V_73 ,
NULL ) ;
if ( V_54 != V_68 ) {
F_26 ( L_16 ,
V_42 , V_54 , V_16 -> V_13 -> V_57 , V_20 -> V_23 ) ;
return V_75 ;
}
}
switch ( V_72 ) {
case V_85 :
V_74 = ( V_77 |
V_78 |
V_79 |
V_80 ) ;
break;
case V_86 :
V_74 = ( V_78 |
V_80 ) ;
break;
case V_87 :
V_74 = ( V_77 |
V_79 ) ;
break;
case V_88 :
V_74 = 0 ;
break;
case V_89 :
V_74 = V_90 ;
break;
case V_91 :
V_74 = V_92 ;
break;
case V_93 :
V_74 = V_75 ;
break;
default:
V_74 = V_75 ;
F_26 ( L_17 ,
V_42 , V_16 -> V_13 -> V_57 ,
V_20 -> V_23 , V_72 ) ;
}
if ( ! ( V_74 & V_75 ) &&
! ( V_74 & V_92 ) &&
! ( V_74 & V_77 ) &&
! ( V_74 & V_78 ) &&
! ( V_20 -> V_81 & V_82 ) ) {
if ( V_16 -> V_52 )
V_16 -> V_52 ( V_16 , V_20 -> V_23 ) ;
F_34 ( V_20 , V_82 ) ;
F_29 ( V_20 ) ;
}
return V_74 ;
}
static int F_36 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = V_20 -> V_16 -> V_14 ;
if ( V_20 -> V_23 < 0 ||
V_20 -> V_23 >= V_16 -> V_55 . V_56 ) {
F_26 ( L_18 ,
V_42 , V_16 -> V_13 -> V_57 ,
V_20 -> V_23 , V_16 -> V_55 . V_56 ) ;
return V_75 ;
}
if ( V_20 -> type & V_94 )
return F_31 ( V_20 ) ;
return F_35 ( V_20 ) ;
}
static T_7 F_37 ( struct V_15 * V_16 )
{
T_7 V_54 = V_95 ;
while ( 1 ) {
V_54 = F_38 ( V_16 -> V_67 ) ;
if ( V_54 <= 0 )
break;
if ( V_96 < V_97 )
F_39 ( 1000 * V_54 ) ;
else
F_40 ( V_54 ) ;
}
return V_54 ;
}
int F_41 ( struct V_12 * V_13 , int V_51 )
{
struct V_15 * V_16 = V_13 -> V_14 ;
T_7 V_54 = V_95 ;
F_42 ( L_19 ,
V_42 , V_13 -> V_57 , V_51 ) ;
if ( V_51 == V_98 ||
V_51 == V_99 )
V_54 = F_43 ( V_16 -> V_67 ,
V_100 ,
V_101 ) ;
else if ( V_51 == V_102 )
V_54 = F_43 ( V_16 -> V_67 ,
V_100 ,
V_103 ) ;
if ( V_54 < 0 )
goto V_104;
V_54 = F_37 ( V_16 ) ;
if ( V_51 == V_102 ) {
if ( V_96 < V_97 )
F_39 ( 1000 * V_105 ) ;
else
F_40 ( V_105 ) ;
}
V_104:
if ( V_54 != V_68 )
return - V_69 ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 , int V_51 )
{
struct V_15 * V_16 = V_13 -> V_14 ;
T_7 V_54 = V_68 ;
F_42 ( L_19 ,
V_42 , V_13 -> V_57 , V_51 ) ;
if ( V_51 == V_98 )
V_54 = F_43 ( V_16 -> V_67 ,
V_106 ,
V_101 ) ;
else if ( V_51 == V_99 )
V_54 = F_43 ( V_16 -> V_67 ,
V_107 ,
V_101 ) ;
else if ( V_51 == V_102 )
V_54 = F_43 ( V_16 -> V_67 ,
V_107 ,
V_103 ) ;
if ( V_54 < 0 )
goto V_104;
V_54 = F_37 ( V_16 ) ;
if ( V_51 == V_102 )
F_40 ( V_105 ) ;
V_104:
if ( V_54 != V_68 )
return - V_69 ;
return 0 ;
}
static int F_45 ( struct V_108 * V_109 , int V_51 )
{
struct V_110 * V_111 = F_46 ( V_109 ) ;
struct V_17 * V_18 = F_47 ( V_111 ) ;
int V_112 = V_18 ? V_18 -> V_113 : 0 ;
T_10 V_114 ;
F_42 ( L_20 ,
V_42 , F_48 ( V_109 -> V_115 ) ,
V_109 -> V_115 -> V_116 , V_51 ) ;
switch ( V_51 ) {
case V_98 :
case V_99 :
if ( V_112 ) {
V_27 -> V_117 ( V_111 , V_112 + V_118 ,
4 , & V_114 ) ;
V_114 |= V_119 ;
V_27 -> V_120 ( V_111 , V_112 + V_118 ,
4 , V_114 ) ;
}
V_27 -> V_117 ( V_111 , V_121 , 2 , & V_114 ) ;
V_114 |= V_122 ;
V_27 -> V_120 ( V_111 , V_121 , 2 , V_114 ) ;
F_40 ( V_123 ) ;
break;
case V_102 :
V_27 -> V_117 ( V_111 , V_121 , 2 , & V_114 ) ;
V_114 &= ~ V_122 ;
V_27 -> V_120 ( V_111 , V_121 , 2 , V_114 ) ;
F_40 ( V_105 ) ;
if ( V_112 ) {
V_27 -> V_117 ( V_111 , V_112 + V_118 ,
4 , & V_114 ) ;
V_114 &= ~ V_119 ;
V_27 -> V_120 ( V_111 , V_112 + V_118 ,
4 , V_114 ) ;
}
break;
}
return 0 ;
}
void F_49 ( struct V_108 * V_109 )
{
struct V_12 * V_13 ;
if ( F_50 ( V_109 -> V_115 ) ) {
V_13 = F_51 ( V_109 -> V_115 ) ;
F_44 ( V_13 , V_99 ) ;
F_44 ( V_13 , V_102 ) ;
} else {
F_45 ( V_109 , V_99 ) ;
F_45 ( V_109 , V_102 ) ;
}
}
static int F_52 ( struct V_19 * V_20 , int V_51 )
{
struct V_12 * V_13 = V_20 -> V_16 ;
struct V_124 * V_115 ;
int V_26 ;
if ( V_20 -> type & V_94 ) {
V_26 = F_41 ( V_13 , V_51 ) ;
} else {
struct V_15 * V_16 ;
T_7 V_54 ;
V_16 = V_13 -> V_14 ;
if ( V_16 -> V_125 == V_126 &&
( V_51 == V_99 ||
V_51 == V_98 ) ) {
V_54 = F_43 ( V_16 -> V_67 ,
V_127 ,
V_101 ) ;
if ( V_54 != V_68 ) {
F_26 ( L_21
L_22 ,
V_42 , V_54 ) ;
return - V_69 ;
}
}
V_115 = F_53 ( V_20 ) ;
if ( F_50 ( V_115 ) ||
F_50 ( V_115 -> V_128 ) )
V_26 = F_44 ( V_13 , V_51 ) ;
else
V_26 = F_45 ( V_115 -> V_129 , V_51 ) ;
}
return V_26 ;
}
static int F_54 ( struct V_19 * V_20 , int V_130 ,
char * V_131 , unsigned long V_132 )
{
F_55 ( V_20 -> V_16 , V_20 -> V_36 ) ;
return 0 ;
}
static int F_56 ( struct V_19 * V_20 )
{
return 0 ;
}
static int F_57 ( struct V_19 * V_20 , int type , int V_22 ,
unsigned long V_23 , unsigned long V_24 )
{
struct V_12 * V_13 = V_20 -> V_16 ;
struct V_15 * V_16 = V_13 -> V_14 ;
T_7 V_26 ;
if ( type != V_133 &&
type != V_134 ) {
F_26 ( L_23 ,
V_42 , type ) ;
return - V_135 ;
}
if ( V_22 < V_136 ||
V_22 > V_137 ) {
F_26 ( L_24 ,
V_42 , V_22 ) ;
return - V_135 ;
}
if ( ! F_58 ( V_138 ) ) {
F_26 ( L_25 ,
V_42 ) ;
return - V_29 ;
}
V_26 = F_59 ( V_16 -> V_67 , V_20 -> V_23 ,
type , V_22 , V_23 , V_24 ) ;
if ( V_26 != V_68 ) {
F_26 ( L_26
L_27 ,
V_42 , V_26 , type , V_22 ,
V_13 -> V_57 , V_20 -> V_23 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_60 ( struct V_139 * V_36 )
{
if ( V_36 -> V_140 || V_36 -> V_141 ||
V_36 -> V_142 || V_36 -> V_143 || V_36 -> V_144 )
F_61 ( L_28 ,
F_62 ( V_36 -> V_140 ) ,
F_62 ( V_36 -> V_141 ) ,
F_62 ( V_36 -> V_142 ) ,
F_62 ( V_36 -> V_143 ) ,
F_62 ( V_36 -> V_144 ) ) ;
if ( V_36 -> V_145 || V_36 -> V_146 ||
V_36 -> V_147 || V_36 -> V_148 || V_36 -> V_149 )
F_61 ( L_29 ,
F_62 ( V_36 -> V_145 ) ,
F_62 ( V_36 -> V_146 ) ,
F_62 ( V_36 -> V_147 ) ,
F_62 ( V_36 -> V_148 ) ,
F_62 ( V_36 -> V_149 ) ) ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_14 ;
struct V_139 * V_36 = & V_16 -> V_150 . V_151 ;
long V_54 ;
V_54 = F_64 ( V_16 -> V_152 , V_36 , sizeof( * V_36 ) ) ;
if ( V_54 != V_68 ) {
F_26 ( L_30 ,
V_42 , V_16 -> V_152 , V_54 ) ;
return;
}
switch ( V_36 -> type ) {
case V_153 :
F_61 ( L_31 ) ;
F_60 ( V_36 ) ;
if ( V_36 -> V_154 . V_155 || V_36 -> V_154 . V_156 )
F_61 ( L_32 ,
F_62 ( V_36 -> V_154 . V_155 ) ,
F_62 ( V_36 -> V_154 . V_156 ) ) ;
break;
case V_157 :
F_61 ( L_33 ,
V_36 -> V_158 . V_159 ? L_34 : L_35 ) ;
F_60 ( V_36 ) ;
if ( V_36 -> V_158 . V_160 || V_36 -> V_158 . V_161 ||
V_36 -> V_158 . V_162 || V_36 -> V_158 . V_163 )
F_61 ( L_36 ,
F_62 ( V_36 -> V_158 . V_160 ) ,
F_62 ( V_36 -> V_158 . V_161 ) ,
F_62 ( V_36 -> V_158 . V_162 ) ,
F_62 ( V_36 -> V_158 . V_163 ) ) ;
break;
case V_164 :
F_61 ( L_37 ,
V_36 -> V_165 . V_166 ) ;
F_60 ( V_36 ) ;
if ( V_36 -> V_165 . V_167 || V_36 -> V_165 . V_168 )
F_61 ( L_38 ,
F_62 ( V_36 -> V_165 . V_167 ) ,
F_62 ( V_36 -> V_165 . V_168 ) ) ;
break;
case V_169 :
F_61 ( L_39 ) ;
F_60 ( V_36 ) ;
break;
case V_170 :
F_61 ( L_40 ) ;
F_60 ( V_36 ) ;
break;
default:
F_26 ( L_41 ,
V_42 , V_16 -> V_152 , V_36 -> type ) ;
}
}
static int F_65 ( struct V_12 * V_13 ,
T_11 V_21 , struct V_19 * * V_20 )
{
struct V_15 * V_16 = V_13 -> V_14 ;
struct V_171 * V_172 ;
struct V_19 * V_173 ;
struct V_17 V_18 ;
V_172 = & V_16 -> V_55 . V_174 [ V_21 ] ;
if ( V_172 -> V_49 & V_175 ) {
V_172 = V_172 -> V_176 ;
F_66 ( ! V_172 ||
! ( V_172 -> V_49 & V_177 ) ) ;
V_21 = V_172 -> V_178 ;
}
memset ( & V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 . V_16 = V_13 ;
V_18 . V_34 = V_21 ;
V_173 = F_8 ( & V_18 ) ;
if ( ! V_173 )
return - V_179 ;
* V_20 = V_173 ;
if ( ! ( V_173 -> V_81 & V_82 ) )
V_16 -> V_52 ( V_16 , V_21 ) ;
V_173 = V_173 -> V_128 ;
while ( V_173 && ! ( V_173 -> type & V_94 ) ) {
int V_26 ;
int V_180 = ( V_77 |
V_78 ) ;
V_26 = V_27 -> V_181 ( V_173 , NULL ) ;
if ( V_26 <= 0 || ( V_26 & V_180 ) == V_180 ) {
V_173 = V_173 -> V_128 ;
continue;
}
* V_20 = V_173 ;
if ( ! ( V_173 -> V_81 & V_82 ) )
V_16 -> V_52 ( V_16 , V_173 -> V_23 ) ;
V_173 = V_173 -> V_128 ;
}
return 0 ;
}
static int F_67 ( struct V_19 * * V_20 )
{
struct V_12 * V_13 ;
struct V_15 * V_16 ;
struct V_19 * V_182 , * V_183 ;
T_12 V_184 ;
T_9 V_185 , V_130 ;
int V_180 = ( V_77 | V_78 ) ;
long V_54 ;
int V_81 , V_26 = V_186 ;
F_68 ( NULL , false ) ;
F_4 ( V_6 , 0x0ul ) ;
F_69 (hose, &hose_list, list_node) {
V_16 = V_13 -> V_14 ;
V_182 = F_70 ( V_13 ) ;
if ( ! V_182 || ( V_182 -> V_81 & V_82 ) )
continue;
V_54 = F_71 ( V_16 -> V_67 ,
& V_184 , & V_185 , & V_130 ) ;
if ( V_54 != V_68 ) {
F_72 ( L_42
L_43 ,
V_42 , V_13 -> V_57 , V_54 ) ;
continue;
}
if ( F_33 ( V_185 ) == V_187 ||
F_33 ( V_130 ) == V_188 ) {
F_72 ( L_44 ,
V_42 , V_13 -> V_57 ) ;
continue;
}
F_72 ( L_45 ,
V_42 , F_33 ( V_185 ) , F_33 ( V_130 ) ,
F_62 ( V_184 ) , V_13 -> V_57 ) ;
switch ( F_33 ( V_185 ) ) {
case V_189 :
if ( F_33 ( V_130 ) == V_190 ) {
F_22 ( L_46 ) ;
V_26 = V_191 ;
} else if ( F_33 ( V_130 ) == V_192 ) {
F_61 ( L_47
L_48 ) ;
F_63 ( V_13 ) ;
V_26 = V_186 ;
}
break;
case V_76 :
if ( F_33 ( V_130 ) == V_193 ) {
* V_20 = V_182 ;
F_22 ( L_49
L_50 ,
V_13 -> V_57 ,
F_73 ( V_182 ) ) ;
V_26 = V_194 ;
} else if ( F_33 ( V_130 ) ==
V_195 ) {
* V_20 = V_182 ;
F_22 ( L_51
L_50 ,
V_13 -> V_57 ,
F_73 ( V_182 ) ) ;
V_26 = V_196 ;
} else if ( F_33 ( V_130 ) == V_192 ) {
F_61 ( L_52
L_53 ,
V_13 -> V_57 ,
F_73 ( V_182 ) ) ;
F_29 ( V_182 ) ;
F_55 ( V_13 , V_182 -> V_36 ) ;
V_26 = V_186 ;
}
break;
case V_197 :
if ( F_65 ( V_13 ,
F_62 ( V_184 ) , V_20 ) ) {
F_61 ( L_54 ,
V_13 -> V_57 , V_184 ) ;
F_61 ( L_55 ,
F_73 ( V_182 ) ) ;
F_28 ( V_16 -> V_67 , V_184 ,
V_198 ) ;
V_26 = V_186 ;
} else if ( ( * V_20 ) -> V_81 & V_82 ||
F_74 ( * V_20 ) ) {
V_26 = V_186 ;
} else {
F_22 ( L_56 ,
( * V_20 ) -> V_23 , ( * V_20 ) -> V_16 -> V_57 ) ;
F_22 ( L_57 ,
F_73 ( * V_20 ) , F_73 ( V_182 ) ) ;
V_26 = V_199 ;
}
break;
default:
F_26 ( L_58 ,
V_42 , F_33 ( V_185 ) ) ;
}
if ( ( V_26 == V_199 ||
V_26 == V_196 ) &&
! ( ( * V_20 ) -> V_81 & V_82 ) ) {
F_34 ( * V_20 , V_82 ) ;
F_29 ( * V_20 ) ;
}
if ( V_26 == V_199 ) {
V_183 = ( * V_20 ) -> V_128 ;
while ( V_183 ) {
if ( V_183 -> type & V_94 )
break;
V_81 = F_36 ( V_183 ) ;
if ( V_81 > 0 &&
( V_81 & V_180 ) != V_180 )
* V_20 = V_183 ;
V_183 = V_183 -> V_128 ;
}
F_34 ( * V_20 , V_82 ) ;
}
if ( V_26 > V_200 )
break;
}
return V_26 ;
}
