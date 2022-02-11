static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = V_6 -> V_8 ;
int V_9 ;
V_6 -> V_8 &= ~ V_10 ;
V_9 = F_2 ( V_2 , V_4 -> V_11 , sizeof( * V_6 ) , V_6 ) ;
V_6 -> V_8 = V_7 ;
if ( V_9 )
F_3 ( V_2 , L_1 , V_9 ) ;
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_12 V_13 ;
T_1 V_7 = V_6 -> V_8 ;
T_2 V_14 = V_6 -> V_15 ;
int V_9 ;
F_5 ( V_2 , & V_13 ,
V_16 ,
NULL , NULL ) ;
V_6 -> V_8 &= ~ V_10 ;
V_6 -> V_15 = V_17 ;
V_9 = F_2 ( V_2 , V_4 -> V_11 , sizeof( * V_6 ) , V_6 ) ;
V_6 -> V_8 = V_7 ;
V_6 -> V_15 = V_14 ;
if ( V_9 ) {
F_3 ( V_2 , L_2 , V_9 ) ;
F_6 ( V_2 , & V_13 ) ;
} else {
V_9 = F_7 ( V_2 , & V_13 , V_18 ) ;
if ( V_9 )
F_3 ( V_2 , L_3 ) ;
}
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 ;
if ( ! V_4 -> V_19 )
return;
V_4 -> V_20 . V_21 . V_22 = 0 ;
if ( V_4 -> V_20 . V_23 )
V_4 -> V_20 . V_21 . V_22 |=
V_24 ;
if ( V_4 -> V_25 . V_26 )
V_4 -> V_20 . V_21 . V_22 |= V_27 ;
F_9 ( V_2 , L_4 ,
V_4 -> V_20 . V_23 ,
V_4 -> V_20 . V_21 . V_22 ) ;
V_9 = F_2 ( V_2 , V_4 -> V_28 ,
sizeof( struct V_29 ) ,
& V_4 -> V_20 . V_21 ) ;
if ( V_9 )
F_3 ( V_2 , L_5 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
F_11 ( & V_2 -> V_32 ) ;
F_12 ( V_2 -> V_33 ) ;
V_2 -> V_33 = F_13 ( V_2 -> V_34 , V_31 ) ;
if ( ! V_2 -> V_33 )
return - V_35 ;
return F_14 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 = 0 ;
struct V_36 V_37 ;
const struct V_5 * V_38 = & V_4 -> V_39 ;
const struct V_5 * V_40 = & V_4 -> V_41 ;
if ( ( V_38 -> V_42 == V_40 -> V_42 ) &&
( V_38 -> V_8 == V_40 -> V_8 ) &&
( V_38 -> V_43 == V_40 -> V_43 ) &&
( V_38 -> V_44 ==
V_40 -> V_44 ) &&
( V_38 -> V_45 ==
V_40 -> V_45 ) &&
( V_38 -> V_46 ==
V_40 -> V_46 ) &&
( V_38 -> V_47 == V_40 -> V_47 ) &&
( V_38 -> V_48 == V_40 -> V_48 ) &&
( V_38 -> V_49 == V_40 -> V_49 ) ) {
F_16 ( V_2 , L_6 ) ;
return 0 ;
}
V_37 . V_42 = V_4 -> V_39 . V_42 ;
V_37 . V_8 = V_4 -> V_39 . V_8 ;
V_37 . V_49 = V_4 -> V_39 . V_49 ;
V_37 . V_43 = V_4 -> V_39 . V_43 ;
V_37 . V_50 = 0 ;
V_37 . V_51 = 0 ;
V_37 . V_52 = 0 ;
V_37 . V_44 =
V_4 -> V_39 . V_44 ;
V_37 . V_45 =
V_4 -> V_39 . V_45 ;
V_37 . V_53 = V_4 -> V_39 . V_48 ;
V_37 . V_46 =
V_4 -> V_39 . V_46 ;
V_37 . V_47 = V_4 -> V_39 . V_47 ;
V_9 = F_17 ( V_2 , V_4 -> V_54 ,
sizeof( V_37 ) , & V_37 , NULL ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 ;
struct V_5 * V_41 = ( void * ) & V_4 -> V_41 ;
if ( V_4 -> V_55 == V_56 )
V_9 = F_1 ( V_2 , V_4 , & V_4 -> V_39 ) ;
else
V_9 = F_4 ( V_2 , V_4 , & V_4 -> V_39 ) ;
if ( V_9 )
return V_9 ;
F_19 ( V_2 , V_4 ) ;
F_20 ( V_2 , V_4 ) ;
V_9 = F_21 ( V_2 , V_4 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_7 , V_9 ) ;
return V_9 ;
}
memcpy ( V_41 , & V_4 -> V_39 , sizeof( * V_41 ) ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_9 ;
struct V_5 * V_41 = ( void * ) & V_4 -> V_41 ;
V_9 = F_23 ( V_2 , V_4 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_8 , V_9 ) ;
return V_9 ;
}
F_8 ( V_2 , V_4 ) ;
if ( V_4 -> V_31 && ( V_4 -> V_31 -> type == V_57 ) ) {
V_9 = F_10 ( V_2 , V_4 -> V_31 ) ;
if ( V_9 ) {
F_3 ( V_2 ,
L_9 ,
V_9 ) ;
return V_9 ;
}
}
V_2 -> V_58 = 0 ;
V_9 = F_2 ( V_2 , V_4 -> V_11 ,
sizeof( struct V_5 ) , & V_4 -> V_39 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_10 , V_9 ) ;
return V_9 ;
}
memcpy ( V_41 , & V_4 -> V_39 , sizeof( * V_41 ) ) ;
F_24 ( V_2 , V_4 ) ;
if ( V_4 -> V_31 && ( V_4 -> V_31 -> type == V_59 ) )
if ( F_10 ( V_2 , V_4 -> V_31 ) )
F_3 ( V_2 , L_11 ) ;
F_25 ( V_2 ) ;
V_9 = F_26 ( V_2 , V_2 -> V_60 , true ) ;
if ( V_9 ) {
F_3 ( V_2 , L_12 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_41 = ( void * ) & V_4 -> V_41 ;
bool V_61 = ! ! ( V_4 -> V_39 . V_8 & V_10 ) ;
int V_9 ;
F_11 ( & V_2 -> V_32 ) ;
if ( F_28 ( V_62 , & V_2 -> V_63 ) )
return - V_64 ;
if ( ! F_29 ( V_2 ) )
return - V_65 ;
F_30 ( V_66 != 2 ) ;
if ( ! V_4 -> V_19 )
return 0 ;
V_4 -> V_39 . V_42 |= V_67 ;
if ( V_4 -> V_55 == V_68 && V_2 -> V_69 . V_70 ) {
struct V_71 * V_72 = V_2 -> V_69 . V_70 ;
F_31 ( V_2 , V_72 , V_4 ) ;
F_32 ( V_2 , V_4 , V_72 -> V_73 , NULL ) ;
V_4 -> V_39 . V_8 |=
V_10 |
V_74 |
V_75 ;
V_4 -> V_39 . V_15 = V_17 ;
V_61 = true ;
if ( memcmp ( & V_4 -> V_39 , & V_4 -> V_41 ,
sizeof( V_4 -> V_39 ) ) == 0 )
return 0 ;
}
if ( ! ( V_2 -> V_76 -> V_77 &&
V_2 -> V_76 -> V_77 -> V_78 ) )
V_4 -> V_39 . V_42 |= V_79 ;
if ( ( V_4 -> V_31 && V_4 -> V_31 -> V_80 . V_81 ) ||
! ( V_4 -> V_39 . V_42 & V_82 ) )
V_4 -> V_39 . V_42 |= V_83 ;
else
V_4 -> V_39 . V_42 &= ~ V_83 ;
F_33 ( V_2 , V_4 ) ;
V_9 = F_34 ( V_2 , V_4 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_13 ) ;
return - V_64 ;
}
if ( F_28 ( V_84 , & V_2 -> V_63 ) &&
( V_2 -> V_85 != V_4 -> V_39 . V_86 ) ) {
F_35 ( V_2 , L_14 ,
F_36 ( V_2 -> V_85 ) ) ;
F_37 ( V_2 , false ) ;
}
if ( ! F_38 ( V_2 , V_4 ) ) {
V_9 = F_15 ( V_2 , V_4 ) ;
if ( V_9 ) {
F_3 ( V_2 , L_15 , V_9 ) ;
return V_9 ;
}
memcpy ( V_41 , & V_4 -> V_39 , sizeof( * V_41 ) ) ;
F_26 ( V_2 , V_2 -> V_60 , false ) ;
return 0 ;
}
if ( V_2 -> V_76 -> V_87 -> V_88 -> V_89 ) {
V_9 = V_2 -> V_76 -> V_87 -> V_88 -> V_89 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
F_39 ( V_2 , V_4 , ! V_90 . V_91 ) ;
F_16 ( V_2 ,
L_16
L_17
L_18
L_19 ,
( V_61 ? L_20 : L_21 ) ,
F_36 ( V_4 -> V_39 . V_86 ) ,
V_4 -> V_39 . V_92 ) ;
V_9 = F_18 ( V_2 , V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_61 )
return F_22 ( V_2 , V_4 ) ;
return 0 ;
}
int F_40 ( struct V_93 * V_34 , T_3 V_94 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_4 ;
struct V_95 * V_96 = & V_34 -> V_96 ;
struct V_71 * V_86 = V_96 -> V_86 ;
const struct V_97 * V_98 ;
int V_9 = 0 ;
F_41 ( V_2 , L_22 , V_94 ) ;
F_42 ( & V_2 -> V_32 ) ;
if ( F_43 ( F_28 ( V_99 , & V_2 -> V_63 ) ) ) {
F_41 ( V_2 , L_23 ) ;
goto V_100;
}
if ( ! F_44 ( V_2 ) ) {
F_41 ( V_2 , L_24 ) ;
goto V_100;
}
if ( V_94 & ( V_101 |
V_102 ) ) {
V_2 -> V_103 . V_104 = V_96 -> V_105 ;
if ( V_2 -> V_76 -> V_87 -> V_88 -> V_106 )
F_45 (priv, ctx)
V_2 -> V_76 -> V_87 -> V_88 -> V_106 ( V_2 , V_4 ) ;
}
if ( V_94 & V_102 ) {
unsigned long V_42 ;
V_98 = F_46 ( V_2 , V_86 -> V_73 ,
V_86 -> V_107 ) ;
if ( ! F_47 ( V_98 ) ) {
F_41 ( V_2 , L_25 ) ;
V_9 = - V_64 ;
goto V_100;
}
F_48 ( & V_2 -> V_108 , V_42 ) ;
F_45 (priv, ctx) {
if ( V_4 -> V_25 . V_26 != F_49 ( V_96 ) )
V_4 -> V_25 . V_26 = F_49 ( V_96 ) ;
if ( V_4 -> V_25 . V_26 ) {
if ( F_50 ( V_96 ) ) {
V_4 -> V_25 . V_109 =
V_110 ;
V_4 -> V_25 . V_111 = true ;
} else if ( F_51 ( V_96 ) ) {
V_4 -> V_25 . V_109 =
V_112 ;
V_4 -> V_25 . V_111 = true ;
} else {
V_4 -> V_25 . V_109 =
V_113 ;
V_4 -> V_25 . V_111 = false ;
}
} else
V_4 -> V_25 . V_111 = false ;
V_4 -> V_25 . V_114 = V_115 ;
if ( F_36 ( V_4 -> V_39 . V_86 ) !=
V_86 -> V_107 )
V_4 -> V_39 . V_42 = 0 ;
F_31 ( V_2 , V_86 , V_4 ) ;
F_52 ( V_2 , & V_2 -> V_103 ) ;
F_32 ( V_2 , V_4 , V_86 -> V_73 ,
V_4 -> V_31 ) ;
}
F_53 ( & V_2 -> V_108 , V_42 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
}
if ( V_94 & ( V_116 |
V_117 ) ) {
V_9 = F_56 ( V_2 , false ) ;
if ( V_9 )
F_41 ( V_2 , L_26 ) ;
}
if ( V_94 & V_118 ) {
F_41 ( V_2 , L_27 ,
V_2 -> V_119 , V_96 -> V_120 ) ;
F_26 ( V_2 , V_96 -> V_120 , false ) ;
}
F_45 (priv, ctx) {
if ( ! memcmp ( & V_4 -> V_39 , & V_4 -> V_41 , sizeof( V_4 -> V_39 ) ) )
continue;
F_27 ( V_2 , V_4 ) ;
}
V_100:
F_57 ( & V_2 -> V_32 ) ;
return V_9 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_121 * V_80 )
{
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_3 * V_122 ;
struct V_123 * V_124 ;
struct V_125 * V_126 = & V_2 -> V_103 ;
struct V_127 * V_128 ;
bool V_129 ;
F_11 ( & V_2 -> V_32 ) ;
switch ( V_31 -> type ) {
case V_130 :
F_59 () ;
V_124 = F_60 ( V_31 , V_80 -> V_131 ) ;
if ( ! V_124 ) {
V_129 = false ;
F_61 () ;
break;
}
V_128 = & V_124 -> V_128 ;
V_129 = true ;
if ( V_128 -> V_132 . V_133 [ 1 ] == 0 &&
V_128 -> V_132 . V_133 [ 2 ] == 0 ) {
V_129 = false ;
} else if ( ! ( V_128 -> V_132 . V_134 &
V_135 ) ) {
V_129 = false ;
} else if ( V_128 -> V_132 . V_134 &
V_136 ) {
int V_137 ;
V_137 = ( V_128 -> V_132 . V_134 &
V_138 ) ;
V_137 >>=
V_139 ;
V_137 += 1 ;
if ( V_137 <= 1 )
V_129 = false ;
}
F_61 () ;
break;
case V_59 :
V_129 = false ;
break;
default:
V_129 = true ;
break;
}
V_4 -> V_140 = V_129 ;
if ( ! V_129 ) {
F_45 (priv, tmp) {
if ( ! V_122 -> V_31 )
continue;
if ( V_122 -> V_140 ) {
V_129 = true ;
break;
}
}
}
V_126 -> V_141 = ! V_129 ;
}
void F_62 ( struct V_93 * V_34 ,
struct V_30 * V_31 ,
struct V_121 * V_80 ,
T_3 V_142 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_4 = F_63 ( V_31 ) ;
int V_9 ;
bool V_143 = false ;
F_42 ( & V_2 -> V_32 ) ;
if ( F_43 ( ! F_44 ( V_2 ) ) ) {
F_41 ( V_2 , L_24 ) ;
F_57 ( & V_2 -> V_32 ) ;
return;
}
if ( F_43 ( ! V_4 -> V_31 ) ) {
F_41 ( V_2 , L_28 ) ;
F_57 ( & V_2 -> V_32 ) ;
return;
}
if ( V_142 & V_144 )
V_143 = true ;
if ( V_142 & V_145 ) {
V_4 -> V_20 . V_23 = V_80 -> V_146 ;
F_8 ( V_2 , V_4 ) ;
}
V_4 -> V_39 . V_147 = F_64 ( V_31 -> V_80 . V_148 ) ;
if ( V_31 -> V_80 . V_149 )
V_4 -> V_39 . V_42 |= V_150 ;
else
V_4 -> V_39 . V_42 &= ~ V_150 ;
if ( V_142 & V_151 ) {
if ( V_80 -> V_152 ) {
V_2 -> V_153 = V_80 -> V_153 ;
V_4 -> V_39 . V_8 |= V_10 ;
} else {
if ( V_4 -> V_154 ) {
V_4 -> V_154 = false ;
F_65 ( V_2 , V_4 ) ;
}
V_4 -> V_39 . V_8 &= ~ V_10 ;
}
}
if ( V_4 -> V_25 . V_26 ) {
V_4 -> V_25 . V_114 = V_80 -> V_155 &
V_156 ;
V_4 -> V_25 . V_157 = ! ! ( V_80 -> V_155 &
V_158 ) ;
F_58 ( V_2 , V_4 , V_80 ) ;
F_52 ( V_2 , & V_2 -> V_103 ) ;
}
if ( V_2 -> V_76 -> V_87 -> V_88 -> V_106 )
V_2 -> V_76 -> V_87 -> V_88 -> V_106 ( V_2 , V_4 ) ;
if ( V_80 -> V_159 && ( V_2 -> V_73 != V_160 ) )
V_4 -> V_39 . V_42 |= V_161 ;
else
V_4 -> V_39 . V_42 &= ~ V_161 ;
if ( V_80 -> V_159 )
V_4 -> V_39 . V_42 |= V_79 ;
else
V_4 -> V_39 . V_42 &= ~ V_79 ;
memcpy ( V_4 -> V_39 . V_92 , V_80 -> V_131 , V_162 ) ;
if ( V_31 -> type == V_57 ||
V_31 -> type == V_59 ) {
if ( V_31 -> V_80 . V_163 ) {
V_4 -> V_39 . V_8 |= V_10 ;
V_2 -> V_164 = V_4 ;
} else {
V_4 -> V_39 . V_8 &= ~ V_10 ;
V_2 -> V_164 = NULL ;
}
}
if ( V_143 || memcmp ( & V_4 -> V_39 , & V_4 -> V_41 , sizeof( V_4 -> V_39 ) ) )
F_27 ( V_2 , V_4 ) ;
if ( V_142 & V_151 && V_80 -> V_152 ) {
if ( V_2 -> V_165 . V_166 == V_167 )
F_56 ( V_2 , false ) ;
F_66 ( V_2 ) ;
V_2 -> V_58 = 1 ;
}
if ( V_142 & V_168 ) {
V_9 = F_67 ( V_2 , V_31 ,
V_80 -> V_169 ) ;
if ( V_9 )
F_3 ( V_2 , L_29 ,
V_80 -> V_169 ? L_30 : L_31 ,
V_80 -> V_131 ) ;
}
if ( V_142 & V_170 && V_31 -> type == V_59 &&
V_2 -> V_164 ) {
if ( F_10 ( V_2 , V_31 ) )
F_3 ( V_2 , L_11 ) ;
}
F_57 ( & V_2 -> V_32 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_45 (priv, ctx)
if ( memcmp ( & V_4 -> V_39 , & V_4 -> V_41 , sizeof( V_4 -> V_39 ) ) )
F_27 ( V_2 , V_4 ) ;
if ( V_2 -> V_76 -> V_87 -> V_88 -> V_89 )
V_2 -> V_76 -> V_87 -> V_88 -> V_89 ( V_2 ) ;
}
