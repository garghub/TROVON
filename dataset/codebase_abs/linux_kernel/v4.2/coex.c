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
struct V_25 V_26 = {} ;
T_2 V_27 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_8 ( V_3 ) ;
F_9 ( & V_3 -> V_31 ) ;
if ( F_10 ( V_3 -> V_32 != V_33 ) ) {
switch ( V_3 -> V_32 ) {
case V_34 :
V_27 = V_35 ;
break;
case V_36 :
V_27 = V_37 ;
break;
default:
F_11 ( 1 ) ;
V_27 = 0 ;
}
V_26 . V_27 = F_12 ( V_27 ) ;
goto V_38;
}
V_27 = V_39 . V_40 ? V_41 : V_42 ;
V_26 . V_27 = F_12 ( V_27 ) ;
if ( V_43 )
V_26 . V_44 |=
F_12 ( V_45 ) ;
if ( F_13 ( V_3 ) )
V_26 . V_44 |= F_12 ( V_46 ) ;
if ( V_47 ) {
V_26 . V_44 |= F_12 ( V_48 ) ;
V_26 . V_44 |=
F_12 ( V_49 ) ;
}
V_26 . V_44 |= F_12 ( V_50 ) ;
V_38:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
return F_14 ( V_3 , V_51 , 0 , sizeof( V_26 ) , & V_26 ) ;
}
static int F_15 ( struct V_2 * V_3 , T_3 V_52 ,
bool V_53 )
{
struct V_54 V_55 = {} ;
struct V_56 * V_57 ;
T_2 V_58 ;
int V_8 ;
V_57 = F_16 ( V_3 , V_52 ) ;
if ( ! V_57 )
return 0 ;
if ( V_57 -> V_59 == V_53 )
return 0 ;
V_58 = V_57 -> V_52 ;
if ( V_53 )
V_58 |= V_60 ;
F_17 ( V_3 , L_1 ,
V_53 ? L_2 : L_3 , V_52 ) ;
V_55 . V_61 = F_12 ( V_58 ) ;
V_57 -> V_59 = V_53 ;
V_8 = F_14 ( V_3 , V_62 , V_63 ,
sizeof( V_55 ) , & V_55 ) ;
return V_8 ;
}
static inline
void F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_53 , int V_64 )
{
struct V_65 * V_66 = F_19 ( V_5 ) ;
V_66 -> V_67 . V_68 = V_64 ;
V_66 -> V_67 . V_69 =
V_53 ? - V_70 : 0 ;
V_66 -> V_67 . V_71 =
V_53 ? - V_72 : 0 ;
}
static void F_20 ( void * V_73 , T_3 * V_74 ,
struct V_4 * V_5 )
{
struct V_65 * V_66 = F_19 ( V_5 ) ;
struct V_75 * V_76 = V_73 ;
struct V_2 * V_3 = V_76 -> V_3 ;
struct V_6 * V_7 ;
enum V_77 V_78 = V_79 ;
T_2 V_80 ;
int V_81 ;
F_9 ( & V_3 -> V_31 ) ;
switch ( V_5 -> type ) {
case V_82 :
break;
case V_83 :
if ( ! V_66 -> V_84 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_82 ) {
F_21 ( V_3 , V_5 , V_85 ,
V_78 ) ;
F_15 ( V_3 , V_66 -> V_86 ,
false ) ;
F_18 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_80 = F_5 ( V_76 -> V_87 -> V_80 ) ;
if ( V_80 >= V_88 )
V_78 = V_89 ;
else if ( V_80 >= V_90 )
V_78 = V_91 ;
if ( ! V_5 -> V_92 . V_93 )
V_78 = V_79 ;
if ( V_66 -> V_94 &&
F_22 ( V_3 -> V_22 . V_95 ,
V_66 -> V_94 -> V_96 ) )
V_78 = V_79 ;
F_17 ( V_76 -> V_3 ,
L_4 ,
V_66 -> V_96 , V_80 , V_78 ) ;
if ( V_5 -> type == V_82 )
F_21 ( V_3 , V_5 , V_85 ,
V_78 ) ;
if ( F_23 ( V_66 ) ) {
V_76 -> V_97 = true ;
V_76 -> V_98 = V_76 -> V_99 ;
V_76 -> V_99 = V_7 ;
}
if ( V_5 -> type == V_83 ) {
if ( ! V_66 -> V_84 )
return;
if ( V_7 == V_76 -> V_99 )
return;
if ( ! V_76 -> V_97 ) {
V_76 -> V_98 = V_76 -> V_99 ;
V_76 -> V_99 = V_7 ;
} else {
V_76 -> V_98 = V_7 ;
}
return;
}
if ( ! V_76 -> V_99 || V_76 -> V_99 == V_7 )
V_76 -> V_99 = V_7 ;
else if ( ! V_76 -> V_98 )
V_76 -> V_98 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_100 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_92 . V_93 ||
F_5 ( V_3 -> V_22 . V_80 ) == V_101 ) {
F_15 ( V_3 , V_66 -> V_86 , false ) ;
F_18 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_81 = V_66 -> V_67 . V_102 ;
if ( ! V_81 )
V_81 = - 100 ;
if ( V_81 > - V_70 ) {
if ( F_15 ( V_3 , V_66 -> V_86 , true ) )
F_24 ( V_3 , L_5 ) ;
} else if ( V_81 < - V_72 ) {
if ( F_15 ( V_3 , V_66 -> V_86 , false ) )
F_24 ( V_3 , L_5 ) ;
}
F_18 ( V_3 , V_5 , true , V_81 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_75 V_76 = {
. V_3 = V_3 ,
. V_87 = & V_3 -> V_22 ,
} ;
struct V_103 V_55 = {} ;
T_3 V_104 ;
if ( F_10 ( V_3 -> V_32 != V_33 ) )
return;
F_2 () ;
F_26 (
V_3 -> V_105 , V_106 ,
F_20 , & V_76 ) ;
if ( V_76 . V_99 ) {
struct V_6 * V_13 = V_76 . V_99 ;
if ( F_11 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_107 < V_108 ) {
V_104 = 0 ;
} else {
if ( V_13 -> V_12 . V_109 >
V_13 -> V_12 . V_13 -> V_110 )
V_104 = 2 ;
else
V_104 = 1 ;
}
V_55 . V_111 =
V_112 [ V_13 -> V_12 . V_13 -> V_113 ] [ V_104 ] ;
V_55 . V_10 =
F_12 ( * ( ( T_1 * ) V_76 . V_99 -> V_20 ) ) ;
}
if ( V_76 . V_98 ) {
struct V_6 * V_13 = V_76 . V_98 ;
if ( F_11 ( ! V_76 . V_98 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_107 < V_108 ) {
V_104 = 0 ;
} else {
if ( V_13 -> V_12 . V_109 >
V_13 -> V_12 . V_13 -> V_110 )
V_104 = 2 ;
else
V_104 = 1 ;
}
V_55 . V_114 =
V_112 [ V_13 -> V_12 . V_13 -> V_113 ] [ V_104 ] ;
V_55 . V_11 =
F_12 ( * ( ( T_1 * ) V_76 . V_98 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_55 , & V_3 -> V_21 , sizeof( V_55 ) ) ) {
if ( F_14 ( V_3 , V_115 , 0 ,
sizeof( V_55 ) , & V_55 ) )
F_24 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_55 , sizeof( V_55 ) ) ;
}
}
int F_27 ( struct V_2 * V_3 ,
struct V_116 * V_117 ,
struct V_118 * V_119 )
{
struct V_120 * V_121 = F_28 ( V_117 ) ;
struct V_122 * V_87 = ( void * ) V_121 -> V_76 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_29 ( V_3 , V_117 , V_119 ) ;
F_17 ( V_3 , L_7 ) ;
F_17 ( V_3 , L_8 , V_87 -> V_123 ) ;
F_17 ( V_3 , L_9 ,
F_5 ( V_87 -> V_23 ) ) ;
F_17 ( V_3 , L_10 ,
F_5 ( V_87 -> V_24 ) ) ;
F_17 ( V_3 , L_11 ,
F_5 ( V_87 -> V_80 ) ) ;
memcpy ( & V_3 -> V_22 , V_87 , sizeof( V_3 -> V_22 ) ) ;
F_25 ( V_3 ) ;
return 0 ;
}
void F_30 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_124 V_125 )
{
struct V_65 * V_66 = F_19 ( V_5 ) ;
int V_8 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 ,
V_30 ) ) {
F_31 ( V_3 , V_5 , V_125 ) ;
return;
}
F_9 ( & V_3 -> V_31 ) ;
if ( F_10 ( V_3 -> V_32 != V_33 ) )
return;
if ( V_66 -> V_86 == V_126 )
return;
if ( F_5 ( V_3 -> V_22 . V_80 ) == V_101 )
return;
F_17 ( V_3 , L_12 , V_5 -> V_92 . V_127 ,
V_125 == V_128 ? L_13 : L_14 ) ;
if ( V_125 == V_129 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_100 )
V_8 = F_15 ( V_3 , V_66 -> V_86 ,
false ) ;
else
V_8 = F_15 ( V_3 , V_66 -> V_86 , true ) ;
if ( V_8 )
F_24 ( V_3 , L_15 ) ;
}
T_1 F_32 ( struct V_2 * V_3 ,
struct V_130 * V_131 )
{
struct V_56 * V_57 = F_33 ( V_131 ) ;
struct V_65 * V_66 = F_19 ( V_57 -> V_5 ) ;
struct V_132 * V_94 = V_66 -> V_94 ;
enum V_1 V_133 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_34 ( V_3 , V_131 ) ;
if ( F_35 ( V_3 -> V_22 . V_95 , V_94 -> V_96 ) )
return V_134 ;
if ( F_5 ( V_3 -> V_22 . V_80 ) <
V_88 )
return V_134 ;
V_133 = F_1 ( V_3 , V_57 -> V_5 ) ;
if ( V_133 == V_100 || V_133 == V_16 )
return V_134 ;
return V_135 ;
}
bool F_36 ( struct V_2 * V_3 ,
struct V_130 * V_131 )
{
struct V_56 * V_57 = F_33 ( V_131 ) ;
struct V_65 * V_66 = F_19 ( V_57 -> V_5 ) ;
struct V_132 * V_94 = V_66 -> V_94 ;
enum V_1 V_133 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_37 ( V_3 , V_131 ) ;
if ( F_35 ( V_3 -> V_22 . V_95 , V_94 -> V_96 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_80 ) <
V_88 )
return true ;
V_133 = F_1 ( V_3 , V_57 -> V_5 ) ;
return V_133 != V_100 ;
}
bool F_38 ( struct V_2 * V_3 , T_3 V_136 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( V_136 & V_3 -> V_18 -> V_137 )
return true ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_39 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_80 ) <
V_88 ;
}
bool F_40 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_39 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_80 ) < V_88 ;
}
bool F_41 ( struct V_2 * V_3 ,
enum V_138 V_14 )
{
T_2 V_139 = F_5 ( V_3 -> V_22 . V_80 ) ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_42 ( V_3 , V_14 ) ;
if ( V_14 != V_15 )
return false ;
return V_139 >= V_90 ;
}
T_3 F_43 ( struct V_2 * V_3 , struct V_140 * V_141 ,
struct V_142 * V_143 , T_3 V_144 )
{
T_4 V_145 = V_141 -> V_146 ;
if ( V_143 -> V_14 != V_15 )
return 0 ;
if ( F_10 ( V_3 -> V_147 ) )
return V_3 -> V_147 - 1 ;
if ( V_143 -> V_148 . V_149 & V_150 ||
F_44 ( V_141 -> V_151 ) ||
F_45 ( V_145 ) || F_46 ( V_145 ) ||
F_47 ( V_145 ) || F_48 ( V_145 ) )
return 3 ;
switch ( V_144 ) {
case V_152 :
return 1 ;
case V_153 :
return 3 ;
case V_154 :
return 2 ;
default:
break;
}
return 0 ;
}
void F_49 ( struct V_2 * V_3 )
{
if ( ! F_7 ( & V_3 -> V_28 -> V_29 ,
V_30 ) ) {
F_50 ( V_3 ) ;
return;
}
F_25 ( V_3 ) ;
}
int F_51 ( struct V_2 * V_3 ,
struct V_116 * V_117 ,
struct V_118 * V_119 )
{
struct V_120 * V_121 = F_28 ( V_117 ) ;
T_2 V_155 = F_52 ( ( void * ) V_121 -> V_76 ) ;
struct V_156 V_55 = {} ;
T_3 T_5 V_157 , V_158 ;
T_3 V_159 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_53 ( V_3 , V_117 , V_119 ) ;
if ( ! F_13 ( V_3 ) )
return 0 ;
F_9 ( & V_3 -> V_31 ) ;
if ( F_10 ( V_3 -> V_32 != V_33 ) )
return 0 ;
if ( V_155 == V_3 -> V_160 )
return 0 ;
for ( V_159 = 0 ; V_159 < F_54 ( V_161 ) - 1 ; V_159 ++ )
if ( V_155 < V_161 [ V_159 + 1 ] . V_162 )
break;
V_157 = V_161 [ V_159 ] . V_162 ;
if ( V_159 < F_54 ( V_161 ) - 1 )
V_158 = V_161 [ V_159 + 1 ] . V_162 ;
else
V_158 = V_161 [ V_159 ] . V_162 ;
F_17 ( V_3 , L_16 ,
V_155 , V_157 , V_158 , V_159 ) ;
V_3 -> V_160 = V_155 ;
if ( V_3 -> V_163 == V_159 )
return 0 ;
V_3 -> V_163 = V_159 ;
memcpy ( & V_55 . V_164 , V_161 [ V_159 ] . V_165 ,
sizeof( V_55 . V_164 ) ) ;
memcpy ( & V_55 . V_166 , V_161 [ V_159 ] . V_165 ,
sizeof( V_55 . V_166 ) ) ;
return F_14 ( V_3 , V_167 , 0 ,
sizeof( V_55 ) , & V_55 ) ;
}
