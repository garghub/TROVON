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
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
if ( F_10 ( V_3 ) && ! ( V_3 -> V_13 & V_14 ) )
V_9 . V_29 = 0x01 ;
else
V_9 . V_29 = 0x00 ;
F_2 ( V_3 , V_30 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_31 V_9 ;
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_3 -> V_32 < V_33 )
return;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_34 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_35 V_9 ;
V_9 . V_36 = V_37 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
F_2 ( V_2 -> V_3 , V_38 , sizeof( V_9 ) , & V_9 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_39 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_40 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_42 , sizeof( V_9 ) , & V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_43 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_40 ;
V_9 . V_44 = F_15 ( V_2 -> V_41 ) ;
V_9 . V_36 = V_36 ;
F_2 ( V_2 -> V_3 , V_45 ,
sizeof( V_9 ) , & V_9 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_46 V_9 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_41 = F_8 ( V_41 ) ;
V_9 . V_28 = F_8 ( V_2 -> V_28 ) ;
F_2 ( V_3 , V_47 , sizeof( V_9 ) , & V_9 ) ;
}
bool F_17 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_48 V_9 ;
const struct V_49 * V_50 ;
F_4 ( L_1 , V_2 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = true ;
V_2 -> V_15 ++ ;
V_9 . V_41 = F_8 ( V_41 ) ;
V_9 . V_51 = F_18 ( 0x00001f40 ) ;
V_9 . V_52 = F_18 ( 0x00001f40 ) ;
V_9 . V_53 = F_8 ( V_2 -> V_54 ) ;
switch ( V_2 -> V_54 & V_55 ) {
case V_56 :
if ( V_2 -> V_15 > F_19 ( V_57 ) )
return false ;
V_9 . V_58 = 0x02 ;
V_50 = & V_57 [ V_2 -> V_15 - 1 ] ;
break;
case V_59 :
if ( V_2 -> V_15 > F_19 ( V_60 ) )
return false ;
V_9 . V_58 = 0x01 ;
V_50 = & V_60 [ V_2 -> V_15 - 1 ] ;
break;
default:
return false ;
}
V_9 . V_28 = F_20 ( V_50 -> V_28 ) ;
V_9 . V_61 = F_20 ( V_50 -> V_61 ) ;
if ( F_2 ( V_3 , V_62 , sizeof( V_9 ) , & V_9 ) < 0 )
return false ;
return true ;
}
void F_21 ( struct V_1 * V_2 , T_3 V_63 , T_3 V_64 ,
T_3 V_65 , T_3 V_66 )
{
struct V_67 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_68 = F_8 ( V_63 ) ;
V_9 . V_69 = F_8 ( V_64 ) ;
V_9 . V_70 = F_8 ( V_65 ) ;
V_9 . V_71 = F_8 ( V_66 ) ;
V_9 . V_72 = F_8 ( 0x0000 ) ;
V_9 . V_73 = F_8 ( 0x0000 ) ;
F_2 ( V_3 , V_74 , sizeof( V_9 ) , & V_9 ) ;
}
void F_22 ( struct V_1 * V_2 , T_4 V_75 , T_5 rand ,
T_1 V_76 [ 16 ] )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_77 V_9 ;
F_4 ( L_1 , V_2 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . rand = rand ;
V_9 . V_75 = V_75 ;
memcpy ( V_9 . V_76 , V_76 , sizeof( V_9 . V_76 ) ) ;
F_2 ( V_3 , V_78 , sizeof( V_9 ) , & V_9 ) ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_1 * V_80 = V_2 -> V_81 ;
if ( ! V_80 )
return;
F_4 ( L_1 , V_2 ) ;
if ( ! V_79 ) {
if ( F_24 ( V_2 -> V_3 ) )
F_17 ( V_80 , V_2 -> V_41 ) ;
else
F_16 ( V_80 , V_2 -> V_41 ) ;
} else {
F_25 ( V_80 , V_79 ) ;
F_26 ( V_80 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_36 = F_28 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_82 :
F_14 ( V_2 , V_36 ) ;
break;
default:
F_13 ( V_2 , V_36 ) ;
break;
}
}
static void F_29 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
V_85 . V_84 ) ;
F_4 ( L_2 , V_2 , F_31 ( V_2 -> V_10 ) ) ;
if ( F_32 ( & V_2 -> V_86 ) )
return;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_87 :
if ( V_2 -> V_12 ) {
if ( V_2 -> type == V_88 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_89 )
F_1 ( V_2 ) ;
} else if ( V_2 -> type == V_90 || V_2 -> type == V_91 ) {
F_12 ( V_2 ) ;
}
break;
case V_92 :
case V_93 :
F_27 ( V_2 ) ;
break;
default:
V_2 -> V_10 = V_94 ;
break;
}
}
static void F_33 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
V_95 . V_84 ) ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_34 ( V_97 , & V_3 -> V_27 ) )
return;
if ( ! F_35 ( V_3 ) || ! F_35 ( V_2 ) )
return;
if ( V_2 -> V_96 != V_98 || ! ( V_2 -> V_16 & V_99 ) )
return;
if ( F_36 ( V_3 ) && F_36 ( V_2 ) ) {
struct V_100 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_61 = F_8 ( 0 ) ;
V_9 . V_101 = F_8 ( 0 ) ;
V_9 . V_102 = F_8 ( 0 ) ;
F_2 ( V_3 , V_103 , sizeof( V_9 ) , & V_9 ) ;
}
if ( ! F_37 ( V_104 , & V_2 -> V_27 ) ) {
struct V_105 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_106 = F_8 ( V_3 -> V_107 ) ;
V_9 . V_108 = F_8 ( V_3 -> V_109 ) ;
V_9 . V_15 = F_8 ( 4 ) ;
V_9 . V_110 = F_8 ( 1 ) ;
F_2 ( V_3 , V_111 , sizeof( V_9 ) , & V_9 ) ;
}
}
static void F_38 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
V_112 . V_84 ) ;
F_2 ( V_2 -> V_3 , V_113 , sizeof( V_2 -> V_18 ) ,
& V_2 -> V_18 ) ;
}
static void F_39 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_30 ( V_84 , struct V_1 ,
F_39 . V_84 ) ;
F_4 ( L_4 ) ;
F_1 ( V_2 ) ;
}
struct V_1 * F_40 ( struct V_5 * V_3 , int type , T_6 * V_18 )
{
struct V_1 * V_2 ;
F_4 ( L_5 , V_3 -> V_114 , V_18 ) ;
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
if ( F_24 ( V_3 ) )
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
F_44 ( & V_2 -> V_85 , F_29 ) ;
F_44 ( & V_2 -> V_112 , F_38 ) ;
F_44 ( & V_2 -> V_95 , F_33 ) ;
F_44 ( & V_2 -> F_39 , F_39 ) ;
F_45 ( & V_2 -> V_86 , 0 ) ;
F_46 ( V_3 ) ;
F_47 ( V_3 , V_2 ) ;
if ( V_3 -> V_133 )
V_3 -> V_133 ( V_3 , V_134 ) ;
F_48 ( V_2 ) ;
return V_2 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_6 , V_3 -> V_114 , V_2 , V_2 -> V_41 ) ;
F_49 ( & V_2 -> V_85 ) ;
F_49 ( & V_2 -> V_112 ) ;
F_49 ( & V_2 -> V_95 ) ;
if ( V_2 -> type == V_88 ) {
struct V_1 * V_80 = V_2 -> V_81 ;
if ( V_80 )
V_80 -> V_81 = NULL ;
V_3 -> V_135 += V_2 -> V_136 ;
} else if ( V_2 -> type == V_89 ) {
F_49 ( & V_2 -> F_39 ) ;
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
struct V_5 * F_58 ( T_6 * V_18 , T_6 * V_116 )
{
int V_142 = F_59 ( V_116 , V_143 ) ;
struct V_5 * V_3 = NULL , * V_144 ;
F_4 ( L_7 , V_116 , V_18 ) ;
F_60 ( & V_145 ) ;
F_61 (d, &hci_dev_list, list) {
if ( ! F_34 ( V_146 , & V_144 -> V_27 ) ||
F_34 ( V_97 , & V_144 -> V_27 ) ||
F_34 ( V_147 , & V_144 -> V_148 ) ||
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
void F_63 ( struct V_1 * V_2 , T_7 V_79 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
V_2 -> V_10 = V_94 ;
F_64 ( V_3 , & V_2 -> V_18 , V_2 -> type , V_2 -> V_151 ,
V_79 ) ;
F_25 ( V_2 , V_79 ) ;
F_26 ( V_2 ) ;
F_65 ( V_3 ) ;
}
static void F_66 ( struct V_5 * V_3 , T_7 V_79 )
{
struct V_1 * V_2 ;
if ( V_79 == 0 )
return;
F_67 ( L_8 ,
V_79 ) ;
F_68 ( V_3 ) ;
V_2 = F_69 ( V_3 , V_89 , V_11 ) ;
if ( ! V_2 )
goto V_152;
F_63 ( V_2 , V_79 ) ;
V_152:
F_70 ( V_3 ) ;
}
static void F_71 ( struct V_153 * V_154 ,
struct V_1 * V_2 )
{
struct V_155 V_9 ;
struct V_5 * V_3 = V_2 -> V_3 ;
T_7 V_156 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
if ( F_72 ( V_154 , false , & V_156 ) )
return;
V_2 -> V_157 = V_156 ;
V_9 . V_158 = F_8 ( V_3 -> V_159 ) ;
V_9 . V_160 = F_8 ( V_3 -> V_161 ) ;
F_5 ( & V_9 . V_162 , & V_2 -> V_18 ) ;
V_9 . V_163 = V_2 -> V_151 ;
V_9 . V_164 = V_156 ;
V_9 . V_68 = F_8 ( V_2 -> V_165 ) ;
V_9 . V_69 = F_8 ( V_2 -> V_166 ) ;
V_9 . V_71 = F_8 ( 0x002a ) ;
V_9 . V_72 = F_8 ( 0x0000 ) ;
V_9 . V_73 = F_8 ( 0x0000 ) ;
F_73 ( V_154 , V_167 , sizeof( V_9 ) , & V_9 ) ;
V_2 -> V_10 = V_11 ;
}
struct V_1 * F_74 ( struct V_5 * V_3 , T_6 * V_18 ,
T_7 V_151 , T_7 V_168 , T_7 V_118 )
{
struct V_169 * V_170 ;
struct V_1 * V_2 ;
struct V_171 * V_172 ;
struct V_153 V_154 ;
int V_173 ;
if ( F_34 ( V_174 , & V_3 -> V_27 ) )
return F_75 ( - V_175 ) ;
V_2 = F_76 ( V_3 , V_89 , V_18 ) ;
if ( V_2 ) {
V_2 -> V_176 = V_168 ;
V_2 -> V_118 = V_118 ;
goto V_152;
}
V_2 = F_69 ( V_3 , V_89 , V_11 ) ;
if ( V_2 )
return F_75 ( - V_177 ) ;
V_172 = F_77 ( V_3 , V_18 , V_151 ) ;
if ( V_172 && F_59 ( & V_172 -> V_178 , V_143 ) ) {
V_18 = & V_172 -> V_178 ;
V_151 = V_179 ;
}
V_2 = F_40 ( V_3 , V_89 , V_18 ) ;
if ( ! V_2 )
return F_75 ( - V_180 ) ;
V_2 -> V_151 = V_151 ;
V_2 -> V_12 = true ;
V_2 -> V_13 |= V_14 ;
V_2 -> V_168 = V_181 ;
V_2 -> V_176 = V_168 ;
V_2 -> V_118 = V_118 ;
V_170 = F_78 ( V_3 , & V_2 -> V_18 , V_2 -> V_151 ) ;
if ( V_170 ) {
V_2 -> V_165 = V_170 -> V_182 ;
V_2 -> V_166 = V_170 -> V_183 ;
} else {
V_2 -> V_165 = V_3 -> V_165 ;
V_2 -> V_166 = V_3 -> V_166 ;
}
F_79 ( & V_154 , V_3 ) ;
if ( F_34 ( V_184 , & V_3 -> V_148 ) ) {
F_80 ( & V_154 ) ;
F_9 ( V_185 , & V_3 -> V_148 ) ;
}
F_71 ( & V_154 , V_2 ) ;
V_173 = F_81 ( & V_154 , F_66 ) ;
if ( V_173 ) {
F_26 ( V_2 ) ;
return F_75 ( V_173 ) ;
}
V_152:
F_82 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_83 ( struct V_5 * V_3 , T_6 * V_18 ,
T_7 V_168 , T_7 V_118 )
{
struct V_1 * V_139 ;
if ( ! F_34 ( V_186 , & V_3 -> V_148 ) )
return F_75 ( - V_175 ) ;
V_139 = F_76 ( V_3 , V_88 , V_18 ) ;
if ( ! V_139 ) {
V_139 = F_40 ( V_3 , V_88 , V_18 ) ;
if ( ! V_139 )
return F_75 ( - V_180 ) ;
}
F_82 ( V_139 ) ;
if ( V_139 -> V_10 == V_117 || V_139 -> V_10 == V_94 ) {
V_139 -> V_168 = V_181 ;
V_139 -> V_176 = V_168 ;
V_139 -> V_118 = V_118 ;
F_3 ( V_139 ) ;
}
return V_139 ;
}
struct V_1 * F_84 ( struct V_5 * V_3 , int type , T_6 * V_18 ,
T_2 V_54 )
{
struct V_1 * V_139 ;
struct V_1 * V_80 ;
V_139 = F_83 ( V_3 , V_18 , V_181 , V_187 ) ;
if ( F_85 ( V_139 ) )
return V_139 ;
V_80 = F_76 ( V_3 , type , V_18 ) ;
if ( ! V_80 ) {
V_80 = F_40 ( V_3 , type , V_18 ) ;
if ( ! V_80 ) {
F_50 ( V_139 ) ;
return F_75 ( - V_180 ) ;
}
}
V_139 -> V_81 = V_80 ;
V_80 -> V_81 = V_139 ;
F_82 ( V_80 ) ;
V_80 -> V_54 = V_54 ;
if ( V_139 -> V_10 == V_93 &&
( V_80 -> V_10 == V_117 || V_80 -> V_10 == V_94 ) ) {
F_9 ( V_123 , & V_139 -> V_27 ) ;
F_86 ( V_139 , V_188 ) ;
if ( F_34 ( V_104 , & V_139 -> V_27 ) ) {
F_9 ( V_189 , & V_139 -> V_27 ) ;
return V_80 ;
}
F_23 ( V_139 , 0x00 ) ;
}
return V_80 ;
}
int F_87 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( F_34 ( V_190 , & V_2 -> V_3 -> V_27 ) ) {
if ( ! F_88 ( V_2 ) ||
! F_34 ( V_191 , & V_2 -> V_27 ) ||
V_2 -> V_122 != V_192 )
return 0 ;
}
if ( F_89 ( V_2 ) && ! ( V_2 -> V_13 & V_193 ) )
return 0 ;
return 1 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 V_168 , T_1 V_118 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> V_176 > V_168 )
V_168 = V_2 -> V_176 ;
if ( V_168 > V_2 -> V_168 )
V_2 -> V_176 = V_168 ;
else if ( V_2 -> V_13 & V_194 )
return 1 ;
V_118 |= ( V_2 -> V_118 & 0x01 ) ;
V_2 -> V_118 = V_118 ;
if ( ! F_37 ( V_195 , & V_2 -> V_27 ) ) {
struct V_196 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
F_2 ( V_2 -> V_3 , V_197 ,
sizeof( V_9 ) , & V_9 ) ;
if ( V_2 -> V_122 != 0xff )
F_9 ( V_198 , & V_2 -> V_27 ) ;
else
F_9 ( V_199 , & V_2 -> V_27 ) ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_37 ( V_199 , & V_2 -> V_27 ) ) {
struct V_200 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
V_9 . V_201 = 0x01 ;
F_2 ( V_2 -> V_3 , V_202 , sizeof( V_9 ) ,
& V_9 ) ;
}
}
int F_92 ( struct V_1 * V_2 , T_1 V_168 , T_1 V_118 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_89 )
return F_93 ( V_2 , V_168 ) ;
if ( V_168 == V_203 )
return 1 ;
if ( V_168 == V_181 && ! F_89 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_13 & V_194 ) )
goto V_204;
if ( V_2 -> V_122 == V_192 &&
V_168 == V_205 )
goto V_201;
if ( ( V_2 -> V_122 == V_206 ||
V_2 -> V_122 == V_192 ) &&
V_168 == V_207 )
goto V_201;
if ( ( V_2 -> V_122 == V_208 ||
V_2 -> V_122 == V_209 ) &&
( V_168 == V_210 || V_168 == V_181 ) )
goto V_201;
if ( V_2 -> V_122 == V_211 &&
( V_168 == V_210 || V_168 == V_181 ||
V_2 -> V_212 == 16 ) )
goto V_201;
V_204:
if ( F_34 ( V_199 , & V_2 -> V_27 ) )
return 0 ;
if ( ! F_90 ( V_2 , V_168 , V_118 ) )
return 0 ;
V_201:
if ( V_2 -> V_13 & V_193 )
return 1 ;
F_91 ( V_2 ) ;
return 0 ;
}
int F_94 ( struct V_1 * V_2 , T_1 V_168 )
{
F_4 ( L_1 , V_2 ) ;
if ( V_168 != V_207 && V_168 != V_205 )
return 1 ;
if ( V_2 -> V_168 == V_207 ||
V_2 -> V_168 == V_205 )
return 1 ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! F_37 ( V_195 , & V_2 -> V_27 ) ) {
struct V_213 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
F_2 ( V_2 -> V_3 , V_214 ,
sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
int F_96 ( struct V_1 * V_2 , T_1 V_215 )
{
F_4 ( L_1 , V_2 ) ;
if ( ! V_215 && V_2 -> V_13 & V_14 )
return 1 ;
if ( ! F_37 ( V_216 , & V_2 -> V_27 ) ) {
struct V_217 V_9 ;
F_5 ( & V_9 . V_17 , & V_2 -> V_18 ) ;
V_9 . V_215 = V_215 ;
F_2 ( V_2 -> V_3 , V_218 , sizeof( V_9 ) , & V_9 ) ;
}
return 0 ;
}
void F_86 ( struct V_1 * V_2 , T_1 V_219 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_34 ( V_97 , & V_3 -> V_27 ) )
return;
if ( V_2 -> V_96 != V_220 )
goto V_221;
if ( ! F_34 ( V_123 , & V_2 -> V_27 ) && ! V_219 )
goto V_221;
if ( ! F_37 ( V_104 , & V_2 -> V_27 ) ) {
struct V_222 V_9 ;
V_9 . V_41 = F_8 ( V_2 -> V_41 ) ;
F_2 ( V_3 , V_223 , sizeof( V_9 ) , & V_9 ) ;
}
V_221:
if ( V_3 -> V_224 > 0 )
F_97 ( V_3 -> V_225 , & V_2 -> V_95 ,
F_98 ( V_3 -> V_224 ) ) ;
}
void F_99 ( struct V_5 * V_3 )
{
struct V_226 * V_227 = & V_3 -> V_228 ;
struct V_1 * V_229 , * V_230 ;
F_4 ( L_9 , V_3 -> V_114 ) ;
F_100 (c, n, &h->list, list) {
V_229 -> V_10 = V_94 ;
F_101 ( V_229 , V_231 ) ;
F_26 ( V_229 ) ;
}
}
void F_102 ( struct V_5 * V_3 )
{
struct V_1 * V_2 ;
F_4 ( L_9 , V_3 -> V_114 ) ;
F_68 ( V_3 ) ;
V_2 = F_69 ( V_3 , V_88 , V_87 ) ;
if ( V_2 )
F_3 ( V_2 ) ;
F_70 ( V_3 ) ;
}
int F_103 ( void T_8 * V_232 )
{
struct V_1 * V_229 ;
struct V_233 V_154 , * V_234 ;
struct V_235 * V_236 ;
struct V_5 * V_3 ;
int V_230 = 0 , V_237 , V_173 ;
if ( F_104 ( & V_154 , V_232 , sizeof( V_154 ) ) )
return - V_238 ;
if ( ! V_154 . V_239 || V_154 . V_239 > ( V_240 * 2 ) / sizeof( * V_236 ) )
return - V_241 ;
V_237 = sizeof( V_154 ) + V_154 . V_239 * sizeof( * V_236 ) ;
V_234 = F_105 ( V_237 , V_115 ) ;
if ( ! V_234 )
return - V_180 ;
V_3 = F_106 ( V_154 . V_242 ) ;
if ( ! V_3 ) {
F_107 ( V_234 ) ;
return - V_243 ;
}
V_236 = V_234 -> V_244 ;
F_68 ( V_3 ) ;
F_61 (c, &hdev->conn_hash.list, list) {
F_5 ( & ( V_236 + V_230 ) -> V_17 , & V_229 -> V_18 ) ;
( V_236 + V_230 ) -> V_41 = V_229 -> V_41 ;
( V_236 + V_230 ) -> type = V_229 -> type ;
( V_236 + V_230 ) -> V_12 = V_229 -> V_12 ;
( V_236 + V_230 ) -> V_10 = V_229 -> V_10 ;
( V_236 + V_230 ) -> V_13 = V_229 -> V_13 ;
if ( ++ V_230 >= V_154 . V_239 )
break;
}
F_70 ( V_3 ) ;
V_234 -> V_242 = V_3 -> V_245 ;
V_234 -> V_239 = V_230 ;
V_237 = sizeof( V_154 ) + V_230 * sizeof( * V_236 ) ;
F_56 ( V_3 ) ;
V_173 = F_108 ( V_232 , V_234 , V_237 ) ;
F_107 ( V_234 ) ;
return V_173 ? - V_238 : 0 ;
}
int F_109 ( struct V_5 * V_3 , void T_8 * V_232 )
{
struct V_246 V_154 ;
struct V_235 V_236 ;
struct V_1 * V_2 ;
char T_8 * V_247 = V_232 + sizeof( V_154 ) ;
if ( F_104 ( & V_154 , V_232 , sizeof( V_154 ) ) )
return - V_238 ;
F_68 ( V_3 ) ;
V_2 = F_76 ( V_3 , V_154 . type , & V_154 . V_17 ) ;
if ( V_2 ) {
F_5 ( & V_236 . V_17 , & V_2 -> V_18 ) ;
V_236 . V_41 = V_2 -> V_41 ;
V_236 . type = V_2 -> type ;
V_236 . V_12 = V_2 -> V_12 ;
V_236 . V_10 = V_2 -> V_10 ;
V_236 . V_13 = V_2 -> V_13 ;
}
F_70 ( V_3 ) ;
if ( ! V_2 )
return - V_248 ;
return F_108 ( V_247 , & V_236 , sizeof( V_236 ) ) ? - V_238 : 0 ;
}
int F_110 ( struct V_5 * V_3 , void T_8 * V_232 )
{
struct V_249 V_154 ;
struct V_1 * V_2 ;
if ( F_104 ( & V_154 , V_232 , sizeof( V_154 ) ) )
return - V_238 ;
F_68 ( V_3 ) ;
V_2 = F_76 ( V_3 , V_88 , & V_154 . V_17 ) ;
if ( V_2 )
V_154 . type = V_2 -> V_118 ;
F_70 ( V_3 ) ;
if ( ! V_2 )
return - V_248 ;
return F_108 ( V_232 , & V_154 , sizeof( V_154 ) ) ? - V_238 : 0 ;
}
struct V_250 * F_111 ( struct V_1 * V_2 )
{
struct V_5 * V_3 = V_2 -> V_3 ;
struct V_250 * V_251 ;
F_4 ( L_10 , V_3 -> V_114 , V_2 ) ;
V_251 = F_41 ( sizeof( struct V_250 ) , V_115 ) ;
if ( ! V_251 )
return NULL ;
V_251 -> V_2 = V_2 ;
F_42 ( & V_251 -> V_131 ) ;
V_251 -> V_10 = V_93 ;
F_112 ( & V_251 -> V_252 , & V_2 -> V_132 ) ;
return V_251 ;
}
void F_113 ( struct V_250 * V_251 )
{
struct V_1 * V_2 = V_251 -> V_2 ;
struct V_5 * V_3 = V_2 -> V_3 ;
F_4 ( L_11 , V_3 -> V_114 , V_2 , V_251 ) ;
F_114 ( & V_251 -> V_252 ) ;
F_115 () ;
F_50 ( V_2 ) ;
F_54 ( & V_251 -> V_131 ) ;
F_107 ( V_251 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_250 * V_251 , * V_230 ;
F_4 ( L_1 , V_2 ) ;
F_100 (chan, n, &conn->chan_list, list)
F_113 ( V_251 ) ;
}
static struct V_250 * F_116 ( struct V_1 * V_253 ,
T_2 V_41 )
{
struct V_250 * V_254 ;
F_61 (hchan, &hcon->chan_list, list) {
if ( V_254 -> V_41 == V_41 )
return V_254 ;
}
return NULL ;
}
struct V_250 * F_117 ( struct V_5 * V_3 , T_2 V_41 )
{
struct V_226 * V_227 = & V_3 -> V_228 ;
struct V_1 * V_253 ;
struct V_250 * V_254 = NULL ;
F_118 () ;
F_119 (hcon, &h->list, list) {
V_254 = F_116 ( V_253 , V_41 ) ;
if ( V_254 )
break;
}
F_120 () ;
return V_254 ;
}
