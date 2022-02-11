static enum V_1
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 ;
enum V_1 V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
F_2 () ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) {
F_4 () ;
return V_16 ;
}
V_8 = V_17 ;
if ( V_3 -> V_18 -> V_19 ) {
F_4 () ;
return V_8 ;
}
V_9 = * ( ( T_1 * ) V_7 -> V_20 ) ;
V_10 = F_5 ( V_3 -> V_21 . V_10 ) ;
V_11 =
F_5 ( V_3 -> V_21 . V_11 ) ;
if ( V_10 == V_9 )
V_8 = F_5 ( V_3 -> V_22 . V_23 ) ;
else if ( V_11 == V_9 )
V_8 = F_5 ( V_3 -> V_22 . V_24 ) ;
F_4 () ;
return V_8 ;
}
int F_6 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_27 V_28 = {
. V_29 = V_30 ,
. V_31 = { sizeof( * V_26 ) , } ,
. V_32 = { V_33 , } ,
} ;
int V_8 ;
T_2 V_34 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_7 ( V_3 ) ;
V_26 = F_8 ( sizeof( * V_26 ) , V_39 ) ;
if ( ! V_26 )
return - V_40 ;
V_28 . V_41 [ 0 ] = V_26 ;
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) ) {
switch ( V_3 -> V_43 ) {
case V_45 :
V_34 = V_46 ;
break;
case V_47 :
V_34 = V_48 ;
break;
default:
F_11 ( 1 ) ;
V_34 = 0 ;
}
V_26 -> V_34 = F_12 ( V_34 ) ;
goto V_49;
}
V_34 = V_50 . V_51 ? V_52 : V_53 ;
V_26 -> V_34 = F_12 ( V_34 ) ;
if ( V_54 )
V_26 -> V_55 |=
F_12 ( V_56 ) ;
if ( F_13 ( V_3 ) )
V_26 -> V_55 |= F_12 ( V_57 ) ;
if ( V_58 ) {
V_26 -> V_55 |= F_12 ( V_59 ) ;
V_26 -> V_55 |=
F_12 ( V_60 ) ;
}
V_26 -> V_55 |= F_12 ( V_61 ) ;
V_49:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
V_8 = F_14 ( V_3 , & V_28 ) ;
F_15 ( V_26 ) ;
return V_8 ;
}
static int F_16 ( struct V_2 * V_3 , T_3 V_62 ,
bool V_63 )
{
struct V_64 V_28 = {} ;
struct V_65 * V_66 ;
T_2 V_67 ;
int V_8 ;
V_66 = F_17 ( V_3 , V_62 ) ;
if ( ! V_66 )
return 0 ;
if ( V_66 -> V_68 == V_63 )
return 0 ;
V_67 = V_66 -> V_62 ;
if ( V_63 )
V_67 |= V_69 ;
F_18 ( V_3 , L_1 ,
V_63 ? L_2 : L_3 , V_62 ) ;
V_28 . V_70 = F_12 ( V_67 ) ;
V_66 -> V_68 = V_63 ;
V_8 = F_19 ( V_3 , V_71 , V_72 ,
sizeof( V_28 ) , & V_28 ) ;
return V_8 ;
}
static inline
void F_20 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_63 , int V_73 )
{
struct V_74 * V_75 = F_21 ( V_5 ) ;
V_75 -> V_76 . V_77 = V_73 ;
V_75 -> V_76 . V_78 =
V_63 ? - V_79 : 0 ;
V_75 -> V_76 . V_80 =
V_63 ? - V_81 : 0 ;
}
static void F_22 ( void * V_82 , T_3 * V_83 ,
struct V_4 * V_5 )
{
struct V_74 * V_75 = F_21 ( V_5 ) ;
struct V_84 * V_41 = V_82 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_6 * V_7 ;
enum V_85 V_86 = V_87 ;
T_2 V_88 ;
int V_89 ;
F_9 ( & V_3 -> V_42 ) ;
switch ( V_5 -> type ) {
case V_90 :
break;
case V_91 :
if ( ! V_75 -> V_92 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_90 ) {
F_23 ( V_3 , V_5 , V_93 ,
V_86 ) ;
F_16 ( V_3 , V_75 -> V_94 ,
false ) ;
F_20 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_88 = F_5 ( V_41 -> V_95 -> V_88 ) ;
if ( V_88 >= V_96 )
V_86 = V_97 ;
else if ( V_88 >= V_98 )
V_86 = V_99 ;
if ( ! V_5 -> V_100 . V_101 )
V_86 = V_87 ;
if ( V_75 -> V_102 &&
F_24 ( V_3 -> V_22 . V_103 ,
V_75 -> V_102 -> V_29 ) )
V_86 = V_87 ;
F_18 ( V_41 -> V_3 ,
L_4 ,
V_75 -> V_29 , V_88 , V_86 ) ;
if ( V_5 -> type == V_90 )
F_23 ( V_3 , V_5 , V_93 ,
V_86 ) ;
if ( F_25 ( V_75 ) ) {
V_41 -> V_104 = true ;
V_41 -> V_105 = V_41 -> V_106 ;
V_41 -> V_106 = V_7 ;
}
if ( V_5 -> type == V_91 ) {
if ( ! V_75 -> V_92 )
return;
if ( V_7 == V_41 -> V_106 )
return;
if ( ! V_41 -> V_104 ) {
V_41 -> V_105 = V_41 -> V_106 ;
V_41 -> V_106 = V_7 ;
} else {
V_41 -> V_105 = V_7 ;
}
return;
}
if ( ! V_41 -> V_106 || V_41 -> V_106 == V_7 )
V_41 -> V_106 = V_7 ;
else if ( ! V_41 -> V_105 )
V_41 -> V_105 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_107 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_100 . V_101 ||
F_5 ( V_3 -> V_22 . V_88 ) == V_108 ) {
F_16 ( V_3 , V_75 -> V_94 , false ) ;
F_20 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_89 = V_75 -> V_76 . V_109 ;
if ( ! V_89 )
V_89 = - 100 ;
if ( V_89 > - V_79 ) {
if ( F_16 ( V_3 , V_75 -> V_94 , true ) )
F_26 ( V_3 , L_5 ) ;
} else if ( V_89 < - V_81 ) {
if ( F_16 ( V_3 , V_75 -> V_94 , false ) )
F_26 ( V_3 , L_5 ) ;
}
F_20 ( V_3 , V_5 , true , V_89 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_84 V_41 = {
. V_3 = V_3 ,
. V_95 = & V_3 -> V_22 ,
} ;
struct V_110 V_28 = {} ;
T_3 V_111 ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return;
F_2 () ;
F_28 (
V_3 -> V_112 , V_113 ,
F_22 , & V_41 ) ;
if ( V_41 . V_106 ) {
struct V_6 * V_13 = V_41 . V_106 ;
if ( F_11 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_114 < V_115 ) {
V_111 = 0 ;
} else {
if ( V_13 -> V_12 . V_116 >
V_13 -> V_12 . V_13 -> V_117 )
V_111 = 2 ;
else
V_111 = 1 ;
}
V_28 . V_118 =
V_119 [ V_13 -> V_12 . V_13 -> V_120 ] [ V_111 ] ;
V_28 . V_10 =
F_12 ( * ( ( T_1 * ) V_41 . V_106 -> V_20 ) ) ;
}
if ( V_41 . V_105 ) {
struct V_6 * V_13 = V_41 . V_105 ;
if ( F_11 ( ! V_41 . V_105 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_114 < V_115 ) {
V_111 = 0 ;
} else {
if ( V_13 -> V_12 . V_116 >
V_13 -> V_12 . V_13 -> V_117 )
V_111 = 2 ;
else
V_111 = 1 ;
}
V_28 . V_121 =
V_119 [ V_13 -> V_12 . V_13 -> V_120 ] [ V_111 ] ;
V_28 . V_11 =
F_12 ( * ( ( T_1 * ) V_41 . V_105 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_28 , & V_3 -> V_21 , sizeof( V_28 ) ) ) {
if ( F_19 ( V_3 , V_122 , 0 ,
sizeof( V_28 ) , & V_28 ) )
F_26 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_28 , sizeof( V_28 ) ) ;
}
}
int F_29 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 = F_30 ( V_124 ) ;
struct V_129 * V_95 = ( void * ) V_128 -> V_41 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_31 ( V_3 , V_124 , V_126 ) ;
F_18 ( V_3 , L_7 ) ;
F_18 ( V_3 , L_8 , V_95 -> V_130 ) ;
F_18 ( V_3 , L_9 ,
F_5 ( V_95 -> V_23 ) ) ;
F_18 ( V_3 , L_10 ,
F_5 ( V_95 -> V_24 ) ) ;
F_18 ( V_3 , L_11 ,
F_5 ( V_95 -> V_88 ) ) ;
memcpy ( & V_3 -> V_22 , V_95 , sizeof( V_3 -> V_22 ) ) ;
F_27 ( V_3 ) ;
return 0 ;
}
static void F_32 ( void * V_82 , T_3 * V_83 ,
struct V_4 * V_5 )
{
struct V_74 * V_75 = F_21 ( V_5 ) ;
struct V_84 * V_41 = V_82 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_131 * V_132 ;
struct V_65 * V_66 ;
struct V_6 * V_7 ;
F_2 () ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) {
F_4 () ;
return;
}
F_4 () ;
if ( V_5 -> type != V_90 ||
V_75 -> V_94 == V_133 )
return;
V_132 = F_33 ( V_3 -> V_134 [ V_75 -> V_94 ] ,
F_34 ( & V_3 -> V_42 ) ) ;
if ( F_35 ( V_132 ) )
return;
V_66 = F_36 ( V_132 ) ;
}
void F_37 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_135 V_136 )
{
struct V_74 * V_75 = F_21 ( V_5 ) ;
struct V_84 V_41 = {
. V_3 = V_3 ,
} ;
int V_8 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) ) {
F_38 ( V_3 , V_5 , V_136 ) ;
return;
}
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return;
if ( V_75 -> V_94 == V_133 )
return;
if ( F_5 ( V_3 -> V_22 . V_88 ) == V_108 )
return;
F_18 ( V_3 , L_12 , V_5 -> V_100 . V_137 ,
V_136 == V_138 ? L_13 : L_14 ) ;
if ( V_136 == V_139 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_107 )
V_8 = F_16 ( V_3 , V_75 -> V_94 ,
false ) ;
else
V_8 = F_16 ( V_3 , V_75 -> V_94 , true ) ;
if ( V_8 )
F_26 ( V_3 , L_15 ) ;
F_28 (
V_3 -> V_112 , V_113 ,
F_32 , & V_41 ) ;
}
T_1 F_39 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
struct V_65 * V_66 = F_36 ( V_132 ) ;
struct V_74 * V_75 = F_21 ( V_66 -> V_5 ) ;
struct V_140 * V_102 = V_75 -> V_102 ;
enum V_1 V_141 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_40 ( V_3 , V_132 ) ;
if ( F_41 ( V_3 -> V_22 . V_103 , V_102 -> V_29 ) )
return V_142 ;
if ( F_5 ( V_3 -> V_22 . V_88 ) <
V_96 )
return V_142 ;
V_141 = F_1 ( V_3 , V_66 -> V_5 ) ;
if ( V_141 == V_107 || V_141 == V_16 )
return V_142 ;
return V_143 ;
}
bool F_42 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
struct V_65 * V_66 = F_36 ( V_132 ) ;
struct V_74 * V_75 = F_21 ( V_66 -> V_5 ) ;
struct V_140 * V_102 = V_75 -> V_102 ;
enum V_1 V_141 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_43 ( V_3 , V_132 ) ;
if ( F_41 ( V_3 -> V_22 . V_103 , V_102 -> V_29 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_88 ) <
V_96 )
return true ;
V_141 = F_1 ( V_3 , V_66 -> V_5 ) ;
return V_141 != V_107 ;
}
bool F_44 ( struct V_2 * V_3 , T_3 V_144 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( V_144 & V_3 -> V_18 -> V_145 )
return true ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_45 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_88 ) <
V_96 ;
}
bool F_46 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_45 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_88 ) == V_108 ;
}
bool F_47 ( struct V_2 * V_3 ,
enum V_146 V_14 )
{
T_2 V_147 = F_5 ( V_3 -> V_22 . V_88 ) ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_48 ( V_3 , V_14 ) ;
if ( V_14 != V_15 )
return false ;
return V_147 >= V_98 ;
}
T_3 F_49 ( struct V_2 * V_3 , struct V_148 * V_149 ,
struct V_150 * V_151 , T_3 V_152 )
{
T_4 V_153 = V_149 -> V_154 ;
if ( V_151 -> V_14 != V_15 )
return 0 ;
if ( F_10 ( V_3 -> V_155 ) )
return V_3 -> V_155 - 1 ;
if ( V_151 -> V_156 . V_157 & V_158 ||
F_50 ( V_149 -> V_159 ) ||
F_51 ( V_153 ) || F_52 ( V_153 ) ||
F_53 ( V_153 ) || F_54 ( V_153 ) )
return 3 ;
switch ( V_152 ) {
case V_160 :
return 1 ;
case V_161 :
return 3 ;
case V_162 :
return 2 ;
default:
break;
}
return 0 ;
}
void F_55 ( struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) ) {
F_56 ( V_3 ) ;
return;
}
F_27 ( V_3 ) ;
}
int F_57 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 = F_30 ( V_124 ) ;
T_2 V_163 = F_58 ( ( void * ) V_128 -> V_41 ) ;
struct V_164 V_28 = {} ;
T_3 T_5 V_165 , V_166 ;
T_3 V_167 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_59 ( V_3 , V_124 , V_126 ) ;
if ( ! F_13 ( V_3 ) )
return 0 ;
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return 0 ;
if ( V_163 == V_3 -> V_168 )
return 0 ;
for ( V_167 = 0 ; V_167 < F_60 ( V_169 ) - 1 ; V_167 ++ )
if ( V_163 < V_169 [ V_167 + 1 ] . V_170 )
break;
V_165 = V_169 [ V_167 ] . V_170 ;
if ( V_167 < F_60 ( V_169 ) - 1 )
V_166 = V_169 [ V_167 + 1 ] . V_170 ;
else
V_166 = V_169 [ V_167 ] . V_170 ;
F_18 ( V_3 , L_16 ,
V_163 , V_165 , V_166 , V_167 ) ;
V_3 -> V_168 = V_163 ;
if ( V_3 -> V_171 == V_167 )
return 0 ;
V_3 -> V_171 = V_167 ;
memcpy ( & V_28 . V_172 , V_169 [ V_167 ] . V_173 ,
sizeof( V_28 . V_172 ) ) ;
memcpy ( & V_28 . V_174 , V_169 [ V_167 ] . V_173 ,
sizeof( V_28 . V_174 ) ) ;
return F_19 ( V_3 , V_175 , 0 ,
sizeof( V_28 ) , & V_28 ) ;
}
