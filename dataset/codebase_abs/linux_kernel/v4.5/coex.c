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
if ( F_14 ( V_3 ) )
V_26 . V_44 |= F_12 ( V_47 ) ;
V_26 . V_44 |= F_12 ( V_48 ) ;
V_38:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
return F_15 ( V_3 , V_49 , 0 , sizeof( V_26 ) , & V_26 ) ;
}
static int F_16 ( struct V_2 * V_3 , T_3 V_50 ,
bool V_51 )
{
struct V_52 V_53 = {} ;
struct V_54 * V_55 ;
T_2 V_56 ;
int V_8 ;
V_55 = F_17 ( V_3 , V_50 ) ;
if ( ! V_55 )
return 0 ;
if ( V_55 -> V_57 == V_51 )
return 0 ;
V_56 = V_55 -> V_50 ;
if ( V_51 )
V_56 |= V_58 ;
F_18 ( V_3 , L_1 ,
V_51 ? L_2 : L_3 , V_50 ) ;
V_53 . V_59 = F_12 ( V_56 ) ;
V_55 -> V_57 = V_51 ;
V_8 = F_15 ( V_3 , V_60 , V_61 ,
sizeof( V_53 ) , & V_53 ) ;
return V_8 ;
}
static inline
void F_19 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_51 , int V_62 )
{
struct V_63 * V_64 = F_20 ( V_5 ) ;
V_64 -> V_65 . V_66 = V_62 ;
V_64 -> V_65 . V_67 =
V_51 ? - V_68 : 0 ;
V_64 -> V_65 . V_69 =
V_51 ? - V_70 : 0 ;
}
static void F_21 ( void * V_71 , T_3 * V_72 ,
struct V_4 * V_5 )
{
struct V_63 * V_64 = F_20 ( V_5 ) ;
struct V_73 * V_74 = V_71 ;
struct V_2 * V_3 = V_74 -> V_3 ;
struct V_6 * V_7 ;
enum V_75 V_76 = V_77 ;
T_2 V_78 ;
int V_79 ;
F_9 ( & V_3 -> V_31 ) ;
switch ( V_5 -> type ) {
case V_80 :
break;
case V_81 :
if ( ! V_64 -> V_82 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_80 ) {
F_22 ( V_3 , V_5 , V_83 ,
V_76 ) ;
F_16 ( V_3 , V_64 -> V_84 ,
false ) ;
F_19 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_78 = F_5 ( V_74 -> V_85 -> V_78 ) ;
if ( V_78 >= V_86 )
V_76 = V_87 ;
else if ( V_78 >= V_88 )
V_76 = V_89 ;
if ( ! V_5 -> V_90 . V_91 )
V_76 = V_77 ;
if ( V_64 -> V_92 &&
F_23 ( V_3 -> V_22 . V_93 ,
V_64 -> V_92 -> V_94 ) )
V_76 = V_77 ;
F_18 ( V_74 -> V_3 ,
L_4 ,
V_64 -> V_94 , V_78 , V_76 ) ;
if ( V_5 -> type == V_80 )
F_22 ( V_3 , V_5 , V_83 ,
V_76 ) ;
if ( F_24 ( V_64 ) ) {
V_74 -> V_95 = true ;
V_74 -> V_96 = V_74 -> V_97 ;
V_74 -> V_97 = V_7 ;
}
if ( V_5 -> type == V_81 ) {
if ( ! V_64 -> V_82 )
return;
if ( V_7 == V_74 -> V_97 )
return;
if ( ! V_74 -> V_95 ) {
V_74 -> V_96 = V_74 -> V_97 ;
V_74 -> V_97 = V_7 ;
} else {
V_74 -> V_96 = V_7 ;
}
return;
}
if ( ! V_74 -> V_97 || V_74 -> V_97 == V_7 )
V_74 -> V_97 = V_7 ;
else if ( ! V_74 -> V_96 )
V_74 -> V_96 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_98 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_90 . V_91 ||
F_5 ( V_3 -> V_22 . V_78 ) == V_99 ) {
F_16 ( V_3 , V_64 -> V_84 , false ) ;
F_19 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_79 = V_64 -> V_65 . V_100 ;
if ( ! V_79 )
V_79 = - 100 ;
if ( V_79 > - V_68 ) {
if ( F_16 ( V_3 , V_64 -> V_84 , true ) )
F_25 ( V_3 , L_5 ) ;
} else if ( V_79 < - V_70 ) {
if ( F_16 ( V_3 , V_64 -> V_84 , false ) )
F_25 ( V_3 , L_5 ) ;
}
F_19 ( V_3 , V_5 , true , V_79 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_73 V_74 = {
. V_3 = V_3 ,
. V_85 = & V_3 -> V_22 ,
} ;
struct V_101 V_53 = {} ;
T_3 V_102 ;
if ( F_10 ( V_3 -> V_32 != V_33 ) )
return;
F_2 () ;
F_27 (
V_3 -> V_103 , V_104 ,
F_21 , & V_74 ) ;
if ( V_74 . V_97 ) {
struct V_6 * V_13 = V_74 . V_97 ;
if ( F_11 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_105 < V_106 ) {
V_102 = 0 ;
} else {
if ( V_13 -> V_12 . V_107 >
V_13 -> V_12 . V_13 -> V_108 )
V_102 = 2 ;
else
V_102 = 1 ;
}
V_53 . V_109 =
V_110 [ V_13 -> V_12 . V_13 -> V_111 ] [ V_102 ] ;
V_53 . V_10 =
F_12 ( * ( ( T_1 * ) V_74 . V_97 -> V_20 ) ) ;
}
if ( V_74 . V_96 ) {
struct V_6 * V_13 = V_74 . V_96 ;
if ( F_11 ( ! V_74 . V_96 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_105 < V_106 ) {
V_102 = 0 ;
} else {
if ( V_13 -> V_12 . V_107 >
V_13 -> V_12 . V_13 -> V_108 )
V_102 = 2 ;
else
V_102 = 1 ;
}
V_53 . V_112 =
V_110 [ V_13 -> V_12 . V_13 -> V_111 ] [ V_102 ] ;
V_53 . V_11 =
F_12 ( * ( ( T_1 * ) V_74 . V_96 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_53 , & V_3 -> V_21 , sizeof( V_53 ) ) ) {
if ( F_15 ( V_3 , V_113 , 0 ,
sizeof( V_53 ) , & V_53 ) )
F_25 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_53 , sizeof( V_53 ) ) ;
}
}
void F_28 ( struct V_2 * V_3 ,
struct V_114 * V_115 )
{
struct V_116 * V_117 = F_29 ( V_115 ) ;
struct V_118 * V_85 = ( void * ) V_117 -> V_74 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 ,
V_30 ) ) {
F_30 ( V_3 , V_115 ) ;
return;
}
F_18 ( V_3 , L_7 ) ;
F_18 ( V_3 , L_8 , V_85 -> V_119 ) ;
F_18 ( V_3 , L_9 ,
F_5 ( V_85 -> V_23 ) ) ;
F_18 ( V_3 , L_10 ,
F_5 ( V_85 -> V_24 ) ) ;
F_18 ( V_3 , L_11 ,
F_5 ( V_85 -> V_78 ) ) ;
memcpy ( & V_3 -> V_22 , V_85 , sizeof( V_3 -> V_22 ) ) ;
F_26 ( V_3 ) ;
}
void F_31 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_120 V_121 )
{
struct V_63 * V_64 = F_20 ( V_5 ) ;
int V_8 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 ,
V_30 ) ) {
F_32 ( V_3 , V_5 , V_121 ) ;
return;
}
F_9 ( & V_3 -> V_31 ) ;
if ( F_10 ( V_3 -> V_32 != V_33 ) )
return;
if ( V_64 -> V_84 == V_122 )
return;
if ( F_5 ( V_3 -> V_22 . V_78 ) == V_99 )
return;
F_18 ( V_3 , L_12 , V_5 -> V_90 . V_123 ,
V_121 == V_124 ? L_13 : L_14 ) ;
if ( V_121 == V_125 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_98 )
V_8 = F_16 ( V_3 , V_64 -> V_84 ,
false ) ;
else
V_8 = F_16 ( V_3 , V_64 -> V_84 , true ) ;
if ( V_8 )
F_25 ( V_3 , L_15 ) ;
}
T_1 F_33 ( struct V_2 * V_3 ,
struct V_126 * V_127 )
{
struct V_54 * V_55 = F_34 ( V_127 ) ;
struct V_63 * V_64 = F_20 ( V_55 -> V_5 ) ;
struct V_128 * V_92 = V_64 -> V_92 ;
enum V_1 V_129 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_35 ( V_3 , V_127 ) ;
if ( F_36 ( V_3 -> V_22 . V_93 , V_92 -> V_94 ) )
return V_130 ;
if ( F_5 ( V_3 -> V_22 . V_78 ) <
V_86 )
return V_130 ;
V_129 = F_1 ( V_3 , V_55 -> V_5 ) ;
if ( V_129 == V_98 || V_129 == V_16 )
return V_130 ;
return V_131 ;
}
bool F_37 ( struct V_2 * V_3 ,
struct V_126 * V_127 )
{
struct V_54 * V_55 = F_34 ( V_127 ) ;
struct V_63 * V_64 = F_20 ( V_55 -> V_5 ) ;
struct V_128 * V_92 = V_64 -> V_92 ;
enum V_1 V_129 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_38 ( V_3 , V_127 ) ;
if ( F_36 ( V_3 -> V_22 . V_93 , V_92 -> V_94 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_78 ) <
V_86 )
return true ;
V_129 = F_1 ( V_3 , V_55 -> V_5 ) ;
return V_129 != V_98 ;
}
bool F_39 ( struct V_2 * V_3 , T_3 V_132 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( V_132 & V_3 -> V_18 -> V_133 )
return true ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_40 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_78 ) <
V_86 ;
}
bool F_41 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_40 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_78 ) < V_86 ;
}
bool F_42 ( struct V_2 * V_3 ,
enum V_134 V_14 )
{
T_2 V_135 = F_5 ( V_3 -> V_22 . V_78 ) ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 , V_30 ) )
return F_43 ( V_3 , V_14 ) ;
if ( V_14 != V_15 )
return false ;
return V_135 >= V_88 ;
}
T_3 F_44 ( struct V_2 * V_3 , struct V_136 * V_137 ,
struct V_138 * V_139 , T_3 V_140 )
{
T_4 V_141 = V_137 -> V_142 ;
bool V_143 = F_14 ( V_3 ) ;
if ( V_139 -> V_14 != V_15 )
return 0 ;
if ( F_10 ( V_3 -> V_144 ) )
return V_3 -> V_144 - 1 ;
if ( F_45 ( F_46 ( V_141 ) ) ) {
if ( F_45 ( F_47 ( V_141 ) ) ) {
switch ( V_140 ) {
case V_145 :
return V_143 ? 1 : 0 ;
case V_146 :
return V_143 ? 2 : 3 ;
case V_147 :
return 3 ;
default:
return 0 ;
}
} else if ( F_48 ( V_137 -> V_148 ) ) {
return 3 ;
} else
return 0 ;
} else if ( F_49 ( V_141 ) ) {
return F_50 ( V_141 ) ? 0 : 3 ;
} else if ( F_51 ( V_141 ) ) {
return 3 ;
}
return 0 ;
}
void F_52 ( struct V_2 * V_3 )
{
if ( ! F_7 ( & V_3 -> V_28 -> V_29 ,
V_30 ) ) {
F_53 ( V_3 ) ;
return;
}
F_26 ( V_3 ) ;
}
void F_54 ( struct V_2 * V_3 ,
struct V_114 * V_115 )
{
struct V_116 * V_117 = F_29 ( V_115 ) ;
T_2 V_149 = F_55 ( ( void * ) V_117 -> V_74 ) ;
struct V_150 V_53 = {} ;
T_3 T_5 V_151 , V_152 ;
T_3 V_153 ;
if ( ! F_7 ( & V_3 -> V_28 -> V_29 ,
V_30 ) ) {
F_56 ( V_3 , V_115 ) ;
return;
}
if ( ! F_13 ( V_3 ) )
return;
F_9 ( & V_3 -> V_31 ) ;
if ( F_10 ( V_3 -> V_32 != V_33 ) )
return;
if ( V_149 == V_3 -> V_154 )
return;
for ( V_153 = 0 ; V_153 < F_57 ( V_155 ) - 1 ; V_153 ++ )
if ( V_149 < V_155 [ V_153 + 1 ] . V_156 )
break;
V_151 = V_155 [ V_153 ] . V_156 ;
if ( V_153 < F_57 ( V_155 ) - 1 )
V_152 = V_155 [ V_153 + 1 ] . V_156 ;
else
V_152 = V_155 [ V_153 ] . V_156 ;
F_18 ( V_3 , L_16 ,
V_149 , V_151 , V_152 , V_153 ) ;
V_3 -> V_154 = V_149 ;
if ( V_3 -> V_157 == V_153 )
return;
V_3 -> V_157 = V_153 ;
memcpy ( & V_53 . V_158 , V_155 [ V_153 ] . V_159 ,
sizeof( V_53 . V_158 ) ) ;
memcpy ( & V_53 . V_160 , V_155 [ V_153 ] . V_159 ,
sizeof( V_53 . V_160 ) ) ;
if ( F_15 ( V_3 , V_161 , 0 ,
sizeof( V_53 ) , & V_53 ) )
F_25 ( V_3 ,
L_17 ) ;
}
