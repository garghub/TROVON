static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , 0 , NULL ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 ++ ;
V_2 -> V_16 = V_3 -> V_16 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_19 = 0x02 ;
V_7 = F_6 ( V_3 , & V_2 -> V_18 ) ;
if ( V_7 ) {
if ( F_7 ( V_7 ) <= V_20 ) {
V_9 . V_19 = V_7 -> V_21 . V_19 ;
V_9 . V_22 = V_7 -> V_21 . V_22 ;
V_9 . V_23 = V_7 -> V_21 . V_23 |
F_8 ( 0x8000 ) ;
}
memcpy ( V_2 -> V_24 , V_7 -> V_21 . V_24 , 3 ) ;
if ( V_7 -> V_21 . V_25 > 0 )
F_9 ( V_26 , & V_2 -> V_27 ) ;
}
V_9 . V_28 = F_10 ( V_2 -> V_28 ) ;
if ( F_11 ( V_3 ) && ! ( V_3 -> V_13 & V_14 ) )
V_9 . V_29 = 0x01 ;
else
V_9 . V_29 = 0x00 ;
F_2 ( V_3 , V_30 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_31 V_9 ;
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_3 -> V_32 < V_33 )
return;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_34 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_35 V_9 ;
V_9 . V_36 = V_37 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_38 , sizeof( V_9 ) , & V_9 ) ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_39 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_40 ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
V_9 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_42 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_43 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_40 ;
V_9 . V_44 = F_16 ( V_2 -> V_41 ) ;
V_9 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_45 ,
sizeof( V_9 ) , & V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_46 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_41 = F_10 ( V_41 ) ;
V_9 . V_28 = F_10 ( V_2 -> V_28 ) ;
F_2 ( V_3 , V_47 , sizeof( V_9 ) , & V_9 ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_48 V_9 ;
const struct V_49 * V_50 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_41 = F_10 ( V_41 ) ;
V_9 . V_51 = F_19 ( 0x00001f40 ) ;
V_9 . V_52 = F_19 ( 0x00001f40 ) ;
V_9 . V_53 = F_10 ( V_2 -> V_54 ) ;
switch ( V_2 -> V_54 & V_55 ) {
case V_56 :
if ( V_2 -> V_15 > F_20 ( V_57 ) )
return false ;
V_9 . V_58 = 0x02 ;
V_50 = & V_57 [ V_2 -> V_15 - 1 ] ;
break;
case V_59 :
if ( V_2 -> V_15 > F_20 ( V_60 ) )
return false ;
V_9 . V_58 = 0x01 ;
V_50 = & V_60 [ V_2 -> V_15 - 1 ] ;
break;
default:
return false ;
}
V_9 . V_28 = F_21 ( V_50 -> V_28 ) ;
V_9 . V_61 = F_21 ( V_50 -> V_61 ) ;
if ( F_2 ( V_3 , V_62 , sizeof( V_9 ) , & V_9 ) < 0 )
return false ;
return true ;
}
void F_22 ( struct V_1 * V_2 , T_3 V_63 , T_3 V_64 ,
T_3 V_65 , T_3 V_66 )
{
struct V_67 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
V_9 . V_68 = F_10 ( V_63 ) ;
V_9 . V_69 = F_10 ( V_64 ) ;
V_9 . V_70 = F_10 ( V_65 ) ;
V_9 . V_71 = F_10 ( V_66 ) ;
V_9 . V_72 = F_8 ( 0x0001 ) ;
V_9 . V_73 = F_8 ( 0x0001 ) ;
F_2 ( V_3 , V_74 , sizeof( V_9 ) , & V_9 ) ;
}
void F_23 ( struct V_1 * V_2 , T_4 V_75 , T_1 rand [ 8 ] ,
T_1 V_76 [ 16 ] )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_77 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
memcpy ( V_9 . V_76 , V_76 , sizeof( V_9 . V_76 ) ) ;
V_9 . V_75 = V_75 ;
memcpy ( V_9 . rand , rand , sizeof( V_9 . rand ) ) ;
F_2 ( V_3 , V_78 , sizeof( V_9 ) , & V_9 ) ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_1 * V_80 = V_2 -> V_81 ;
if ( ! V_80 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_79 ) {
if ( F_25 ( V_2 -> V_3 ) )
F_18 ( V_80 , V_2 -> V_41 ) ;
else
F_17 ( V_80 , V_2 -> V_41 ) ;
} else {
F_26 ( V_80 , V_79 ) ;
F_27 ( V_80 ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_36 = F_29 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_82 :
F_15 ( V_2 , V_36 ) ;
break;
default:
F_14 ( V_2 , V_36 ) ;
break;
}
}
static void F_30 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_31 ( V_84 , struct V_1 ,
V_85 . V_84 ) ;
F_4 ( L_2 , V_2 , F_32 ( V_2 -> V_10 ) ) ;
if ( F_33 ( & V_2 -> V_86 ) )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_87 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_88 )
F_12 ( V_2 ) ;
else if ( V_2 -> type == V_89 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_90 || V_2 -> type == V_91 ) {
F_13 ( V_2 ) ;
}
break;
case V_92 :
case V_93 :
F_28 ( V_2 ) ;
break;
default:
V_2 -> V_10 = V_94 ;
break;
}
}
static void F_34 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_31 ( V_84 , struct V_1 ,
V_95 . V_84 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_35 ( V_97 , & V_3 -> V_27 ) )
return;
if ( ! F_36 ( V_3 ) || ! F_36 ( V_2 ) )
return;
if ( V_2 -> V_96 != V_98 || ! ( V_2 -> V_16 & V_99 ) )
return;
if ( F_37 ( V_3 ) && F_37 ( V_2 ) ) {
struct V_100 V_9 ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
V_9 . V_61 = F_8 ( 0 ) ;
V_9 . V_101 = F_8 ( 0 ) ;
V_9 . V_102 = F_8 ( 0 ) ;
F_2 ( V_3 , V_103 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_38 ( V_104 , & V_2 -> V_27 ) ) {
struct V_105 V_9 ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
V_9 . V_106 = F_10 ( V_3 -> V_107 ) ;
V_9 . V_108 = F_10 ( V_3 -> V_109 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_110 = F_8 ( 1 ) ;
F_2 ( V_3 , V_111 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_39 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_31 ( V_84 , struct V_1 ,
V_112 . V_84 ) ;
F_2 ( V_2 -> V_3 , V_113 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
struct V_1 * F_40 ( struct V_5 * V_3 , int type , T_5 * V_18 )
{
struct V_1 * V_2 ;
F_4 ( L_4 , V_3 -> V_114 , V_18 ) ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_18 , V_18 ) ;
F_5 ( & V_2 -> V_116 , & V_3 -> V_17 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> type = type ;
V_2 -> V_96 = V_98 ;
V_2 -> V_10 = V_117 ;
V_2 -> V_118 = V_119 ;
V_2 -> V_120 = V_3 -> V_120 ;
V_2 -> V_121 = 0xff ;
V_2 -> V_122 = 0xff ;
F_9 ( V_123 , & V_2 -> V_27 ) ;
V_2 -> V_124 = V_125 ;
switch ( type ) {
case V_88 :
V_2 -> V_28 = V_3 -> V_28 & V_126 ;
break;
case V_90 :
if ( F_25 ( V_3 ) )
V_2 -> V_28 = ( V_3 -> V_127 & V_128 ) |
( V_3 -> V_127 & V_129 ) ;
else
V_2 -> V_28 = V_3 -> V_28 & V_130 ;
break;
case V_91 :
V_2 -> V_28 = V_3 -> V_127 & ~ V_129 ;
break;
}
F_42 ( & V_2 -> V_131 ) ;
F_43 ( & V_2 -> V_132 ) ;
F_44 ( & V_2 -> V_85 , F_30 ) ;
F_44 ( & V_2 -> V_112 , F_39 ) ;
F_44 ( & V_2 -> V_95 , F_34 ) ;
F_45 ( & V_2 -> V_86 , 0 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 , V_2 ) ;
if ( V_3 -> V_133 )
V_3 -> V_133 ( V_3 , V_134 ) ;
F_48 ( V_2 ) ;
return V_2 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_5 , V_3 -> V_114 , V_2 , V_2 -> V_41 ) ;
F_49 ( & V_2 -> V_85 ) ;
F_49 ( & V_2 -> V_112 ) ;
F_49 ( & V_2 -> V_95 ) ;
if ( V_2 -> type == V_88 ) {
struct V_1 * V_80 = V_2 -> V_81 ;
if ( V_80 )
V_80 -> V_81 = NULL ;
V_3 -> V_135 += V_2 -> V_136 ;
} else if ( V_2 -> type == V_89 ) {
if ( V_3 -> V_137 )
V_3 -> V_138 += V_2 -> V_136 ;
else
V_3 -> V_135 += V_2 -> V_136 ;
} else {
struct V_1 * V_139 = V_2 -> V_81 ;
if ( V_139 ) {
V_139 -> V_81 = NULL ;
F_50 ( V_139 ) ;
}
}
F_51 ( V_2 ) ;
if ( V_2 -> V_140 )
F_52 ( V_2 -> V_140 ) ;
F_53 ( V_3 , V_2 ) ;
if ( V_3 -> V_133 )
V_3 -> V_133 ( V_3 , V_141 ) ;
F_54 ( & V_2 -> V_131 ) ;
F_55 ( V_2 ) ;
F_56 ( V_3 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
struct V_5 * F_58 ( T_5 * V_18 , T_5 * V_116 )
{
int V_142 = F_59 ( V_116 , V_143 ) ;
struct V_5 * V_3 = NULL , * V_144 ;
F_4 ( L_6 , V_116 , V_18 ) ;
F_60 ( & V_145 ) ;
F_61 (d, &hci_dev_list, list) {
if ( ! F_35 ( V_146 , & V_144 -> V_27 ) ||
F_35 ( V_97 , & V_144 -> V_27 ) ||
F_35 ( V_147 , & V_144 -> V_148 ) ||
V_144 -> V_149 != V_150 )
continue;
if ( V_142 ) {
if ( ! F_59 ( & V_144 -> V_17 , V_116 ) ) {
V_3 = V_144 ; break;
}
} else {
if ( F_59 ( & V_144 -> V_17 , V_18 ) ) {
V_3 = V_144 ; break;
}
}
}
if ( V_3 )
V_3 = F_46 ( V_3 ) ;
F_62 ( & V_145 ) ;
return V_3 ;
}
static void F_63 ( struct V_5 * V_3 , T_6 V_79 )
{
struct V_1 * V_2 ;
if ( V_79 == 0 )
return;
F_64 ( L_7 ,
V_79 ) ;
F_65 ( V_3 ) ;
V_2 = F_66 ( V_3 , V_89 , V_11 ) ;
if ( ! V_2 )
goto V_151;
V_2 -> V_10 = V_94 ;
F_67 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_152 ,
V_79 ) ;
F_26 ( V_2 , V_79 ) ;
F_27 ( V_2 ) ;
V_151:
F_68 ( V_3 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_153 V_9 ;
struct V_154 V_155 ;
int V_156 ;
F_70 ( & V_155 , V_3 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_157 = F_10 ( V_3 -> V_158 ) ;
V_9 . V_159 = F_10 ( V_3 -> V_160 ) ;
F_5 ( & V_9 . V_161 , & V_2 -> V_18 ) ;
V_9 . V_162 = V_2 -> V_152 ;
V_9 . V_163 = V_2 -> V_164 ;
V_9 . V_68 = F_10 ( V_3 -> V_165 ) ;
V_9 . V_69 = F_10 ( V_3 -> V_166 ) ;
V_9 . V_71 = F_8 ( 0x002a ) ;
V_9 . V_72 = F_8 ( 0x0000 ) ;
V_9 . V_73 = F_8 ( 0x0000 ) ;
F_71 ( & V_155 , V_167 , sizeof( V_9 ) , & V_9 ) ;
V_156 = F_72 ( & V_155 , F_63 ) ;
if ( V_156 ) {
F_27 ( V_2 ) ;
return V_156 ;
}
return 0 ;
}
static struct V_1 * F_73 ( struct V_5 * V_3 , T_5 * V_18 ,
T_6 V_152 , T_6 V_168 , T_6 V_118 )
{
struct V_1 * V_2 ;
int V_156 ;
if ( F_35 ( V_169 , & V_3 -> V_27 ) )
return F_74 ( - V_170 ) ;
V_2 = F_75 ( V_3 , V_89 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_171 = V_168 ;
V_2 -> V_118 = V_118 ;
goto V_151;
}
V_2 = F_66 ( V_3 , V_89 , V_11 ) ;
if ( V_2 )
return F_74 ( - V_172 ) ;
V_2 = F_40 ( V_3 , V_89 , V_18 ) ;
if ( ! V_2 )
return F_74 ( - V_173 ) ;
if ( V_152 == V_174 )
V_2 -> V_152 = V_175 ;
else
V_2 -> V_152 = V_176 ;
V_2 -> V_164 = V_3 -> V_177 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_13 |= V_14 ;
V_2 -> V_168 = V_178 ;
V_2 -> V_171 = V_168 ;
V_2 -> V_118 = V_118 ;
V_156 = F_69 ( V_2 ) ;
if ( V_156 )
return F_74 ( V_156 ) ;
V_151:
F_76 ( V_2 ) ;
return V_2 ;
}
static struct V_1 * F_77 ( struct V_5 * V_3 , T_5 * V_18 ,
T_6 V_168 , T_6 V_118 )
{
struct V_1 * V_139 ;
if ( ! F_35 ( V_179 , & V_3 -> V_148 ) )
return F_74 ( - V_170 ) ;
V_139 = F_75 ( V_3 , V_88 , V_18 ) ;
if ( ! V_139 ) {
V_139 = F_40 ( V_3 , V_88 , V_18 ) ;
if ( ! V_139 )
return F_74 ( - V_173 ) ;
}
F_76 ( V_139 ) ;
if ( V_139 -> V_10 == V_117 || V_139 -> V_10 == V_94 ) {
V_139 -> V_168 = V_178 ;
V_139 -> V_171 = V_168 ;
V_139 -> V_118 = V_118 ;
F_3 ( V_139 ) ;
}
return V_139 ;
}
struct V_1 * F_78 ( struct V_5 * V_3 , int type , T_5 * V_18 ,
T_2 V_54 )
{
struct V_1 * V_139 ;
struct V_1 * V_80 ;
V_139 = F_77 ( V_3 , V_18 , V_178 , V_180 ) ;
if ( F_79 ( V_139 ) )
return V_139 ;
V_80 = F_75 ( V_3 , type , V_18 ) ;
if ( ! V_80 ) {
V_80 = F_40 ( V_3 , type , V_18 ) ;
if ( ! V_80 ) {
F_50 ( V_139 ) ;
return F_74 ( - V_173 ) ;
}
}
V_139 -> V_81 = V_80 ;
V_80 -> V_81 = V_139 ;
F_76 ( V_80 ) ;
V_80 -> V_54 = V_54 ;
if ( V_139 -> V_10 == V_93 &&
( V_80 -> V_10 == V_117 || V_80 -> V_10 == V_94 ) ) {
F_9 ( V_123 , & V_139 -> V_27 ) ;
F_80 ( V_139 , V_181 ) ;
if ( F_35 ( V_104 , & V_139 -> V_27 ) ) {
F_9 ( V_182 , & V_139 -> V_27 ) ;
return V_80 ;
}
F_24 ( V_139 , 0x00 ) ;
}
return V_80 ;
}
struct V_1 * F_81 ( struct V_5 * V_3 , int type , T_5 * V_18 ,
T_1 V_152 , T_1 V_168 , T_1 V_118 )
{
F_4 ( L_8 , V_3 -> V_114 , V_18 , type ) ;
switch ( type ) {
case V_89 :
return F_73 ( V_3 , V_18 , V_152 , V_168 , V_118 ) ;
case V_88 :
return F_77 ( V_3 , V_18 , V_168 , V_118 ) ;
}
return F_74 ( - V_183 ) ;
}
int F_82 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_83 ( V_2 ) && ! ( V_2 -> V_13 & V_184 ) )
return 0 ;
return 1 ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_168 , T_1 V_118 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_171 > V_168 )
V_168 = V_2 -> V_171 ;
if ( V_168 > V_2 -> V_168 )
V_2 -> V_171 = V_168 ;
else if ( V_2 -> V_13 & V_185 )
return 1 ;
V_118 |= ( V_2 -> V_118 & 0x01 ) ;
V_2 -> V_118 = V_118 ;
if ( ! F_38 ( V_186 , & V_2 -> V_27 ) ) {
struct V_187 V_9 ;
F_9 ( V_188 , & V_2 -> V_27 ) ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
F_2 ( V_2 -> V_3 , V_189 ,
sizeof( V_9 ) , & V_9 ) ;
if ( V_2 -> V_122 != 0xff )
F_9 ( V_190 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_38 ( V_188 , & V_2 -> V_27 ) ) {
struct V_191 V_9 ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
V_9 . V_192 = 0x01 ;
F_2 ( V_2 -> V_3 , V_193 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_86 ( struct V_1 * V_2 , T_1 V_168 , T_1 V_118 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_89 )
return F_87 ( V_2 , V_168 ) ;
if ( V_168 == V_194 )
return 1 ;
if ( V_168 == V_178 && ! F_83 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_13 & V_185 ) )
goto V_195;
if ( V_2 -> V_122 == V_196 )
goto V_192;
if ( V_2 -> V_122 == V_197 &&
( V_168 == V_198 || V_168 == V_178 ) )
goto V_192;
if ( V_2 -> V_122 == V_199 &&
( V_168 != V_200 || V_2 -> V_201 == 16 ) )
goto V_192;
V_195:
if ( F_35 ( V_188 , & V_2 -> V_27 ) )
return 0 ;
if ( ! F_84 ( V_2 , V_168 , V_118 ) )
return 0 ;
V_192:
if ( V_2 -> V_13 & V_184 )
return 1 ;
F_85 ( V_2 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , T_1 V_168 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_168 != V_200 )
return 1 ;
if ( V_2 -> V_168 == V_200 )
return 1 ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_38 ( V_186 , & V_2 -> V_27 ) ) {
struct V_202 V_9 ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
F_2 ( V_2 -> V_3 , V_203 ,
sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_204 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! V_204 && V_2 -> V_13 & V_14 )
return 1 ;
if ( ! F_38 ( V_205 , & V_2 -> V_27 ) ) {
struct V_206 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_204 = V_204 ;
F_2 ( V_2 -> V_3 , V_207 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_2 , T_1 V_208 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_35 ( V_97 , & V_3 -> V_27 ) )
return;
if ( V_2 -> V_96 != V_209 )
goto V_210;
if ( ! F_35 ( V_123 , & V_2 -> V_27 ) && ! V_208 )
goto V_210;
if ( ! F_38 ( V_104 , & V_2 -> V_27 ) ) {
struct V_211 V_9 ;
V_9 . V_41 = F_10 ( V_2 -> V_41 ) ;
F_2 ( V_3 , V_212 , sizeof( V_9 ) , & V_9 ) ;
}
V_210:
if ( V_3 -> V_213 > 0 )
F_91 ( V_3 -> V_214 , & V_2 -> V_95 ,
F_92 ( V_3 -> V_213 ) ) ;
}
void F_93 ( struct V_5 * V_3 )
{
struct V_215 * V_216 = & V_3 -> V_217 ;
struct V_1 * V_218 , * V_219 ;
F_4 ( L_9 , V_3 -> V_114 ) ;
F_94 (c, n, &h->list, list) {
V_218 -> V_10 = V_94 ;
F_95 ( V_218 , V_220 ) ;
F_27 ( V_218 ) ;
}
}
void F_96 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_114 ) ;
F_65 ( V_3 ) ;
V_2 = F_66 ( V_3 , V_88 , V_87 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_68 ( V_3 ) ;
}
int F_97 ( void T_7 * V_221 )
{
struct V_1 * V_218 ;
struct V_222 V_155 , * V_223 ;
struct V_224 * V_225 ;
struct V_5 * V_3 ;
int V_219 = 0 , V_226 , V_156 ;
if ( F_98 ( & V_155 , V_221 , sizeof( V_155 ) ) )
return - V_227 ;
if ( ! V_155 . V_228 || V_155 . V_228 > ( V_229 * 2 ) / sizeof( * V_225 ) )
return - V_183 ;
V_226 = sizeof( V_155 ) + V_155 . V_228 * sizeof( * V_225 ) ;
V_223 = F_99 ( V_226 , V_115 ) ;
if ( ! V_223 )
return - V_173 ;
V_3 = F_100 ( V_155 . V_230 ) ;
if ( ! V_3 ) {
F_101 ( V_223 ) ;
return - V_231 ;
}
V_225 = V_223 -> V_232 ;
F_65 ( V_3 ) ;
F_61 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_225 + V_219 ) -> V_17 , & V_218 -> V_18 ) ;
( V_225 + V_219 ) -> V_41 = V_218 -> V_41 ;
( V_225 + V_219 ) -> type = V_218 -> type ;
( V_225 + V_219 ) -> V_12 = V_218 -> V_12 ;
( V_225 + V_219 ) -> V_10 = V_218 -> V_10 ;
( V_225 + V_219 ) -> V_13 = V_218 -> V_13 ;
if ( ++ V_219 >= V_155 . V_228 )
break;
}
F_68 ( V_3 ) ;
V_223 -> V_230 = V_3 -> V_233 ;
V_223 -> V_228 = V_219 ;
V_226 = sizeof( V_155 ) + V_219 * sizeof( * V_225 ) ;
F_56 ( V_3 ) ;
V_156 = F_102 ( V_221 , V_223 , V_226 ) ;
F_101 ( V_223 ) ;
return V_156 ? - V_227 : 0 ;
}
int F_103 ( struct V_5 * V_3 , void T_7 * V_221 )
{
struct V_234 V_155 ;
struct V_224 V_225 ;
struct V_1 * V_2 ;
char T_7 * V_235 = V_221 + sizeof( V_155 ) ;
if ( F_98 ( & V_155 , V_221 , sizeof( V_155 ) ) )
return - V_227 ;
F_65 ( V_3 ) ;
V_2 = F_75 ( V_3 , V_155 . type , & V_155 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_225 . V_17 , & V_2 -> V_18 ) ;
V_225 . V_41 = V_2 -> V_41 ;
V_225 . type = V_2 -> type ;
V_225 . V_12 = V_2 -> V_12 ;
V_225 . V_10 = V_2 -> V_10 ;
V_225 . V_13 = V_2 -> V_13 ;
}
F_68 ( V_3 ) ;
if ( ! V_2 )
return - V_236 ;
return F_102 ( V_235 , & V_225 , sizeof( V_225 ) ) ? - V_227 : 0 ;
}
int F_104 ( struct V_5 * V_3 , void T_7 * V_221 )
{
struct V_237 V_155 ;
struct V_1 * V_2 ;
if ( F_98 ( & V_155 , V_221 , sizeof( V_155 ) ) )
return - V_227 ;
F_65 ( V_3 ) ;
V_2 = F_75 ( V_3 , V_88 , & V_155 . V_17 ) ;
if ( V_2 )
V_155 . type = V_2 -> V_118 ;
F_68 ( V_3 ) ;
if ( ! V_2 )
return - V_236 ;
return F_102 ( V_221 , & V_155 , sizeof( V_155 ) ) ? - V_227 : 0 ;
}
struct V_238 * F_105 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_238 * V_239 ;
F_4 ( L_10 , V_3 -> V_114 , V_2 ) ;
V_239 = F_41 ( sizeof( struct V_238 ) , V_115 ) ;
if ( ! V_239 )
return NULL ;
V_239 -> V_2 = V_2 ;
F_42 ( & V_239 -> V_131 ) ;
V_239 -> V_10 = V_93 ;
F_106 ( & V_239 -> V_240 , & V_2 -> V_132 ) ;
return V_239 ;
}
void F_107 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = V_239 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_11 , V_3 -> V_114 , V_2 , V_239 ) ;
F_108 ( & V_239 -> V_240 ) ;
F_109 () ;
F_50 ( V_2 ) ;
F_54 ( & V_239 -> V_131 ) ;
F_101 ( V_239 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_238 * V_239 , * V_219 ;
F_4 ( L_1 , V_2 ) ;
F_94 (chan, n, &conn->chan_list, list)
F_107 ( V_239 ) ;
}
static struct V_238 * F_110 ( struct V_1 * V_241 ,
T_2 V_41 )
{
struct V_238 * V_242 ;
F_61 (hchan, &hcon->chan_list, list) {
if ( V_242 -> V_41 == V_41 )
return V_242 ;
}
return NULL ;
}
struct V_238 * F_111 ( struct V_5 * V_3 , T_2 V_41 )
{
struct V_215 * V_216 = & V_3 -> V_217 ;
struct V_1 * V_241 ;
struct V_238 * V_242 = NULL ;
F_112 () ;
F_113 (hcon, &h->list, list) {
V_242 = F_110 ( V_241 , V_41 ) ;
if ( V_242 )
break;
}
F_114 () ;
return V_242 ;
}
