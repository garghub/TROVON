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
F_7 ( & V_3 -> V_28 ) ;
if ( F_8 ( V_3 -> V_29 != V_30 ) ) {
switch ( V_3 -> V_29 ) {
case V_31 :
V_27 = V_32 ;
break;
case V_33 :
V_27 = V_34 ;
break;
default:
F_9 ( 1 ) ;
V_27 = 0 ;
}
V_26 . V_27 = F_10 ( V_27 ) ;
goto V_35;
}
V_27 = V_36 . V_37 ? V_38 : V_39 ;
V_26 . V_27 = F_10 ( V_27 ) ;
if ( V_40 )
V_26 . V_41 |=
F_10 ( V_42 ) ;
if ( F_11 ( V_3 ) )
V_26 . V_41 |= F_10 ( V_43 ) ;
if ( F_12 ( V_3 ) )
V_26 . V_41 |= F_10 ( V_44 ) ;
V_26 . V_41 |= F_10 ( V_45 ) ;
V_35:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
return F_13 ( V_3 , V_46 , 0 , sizeof( V_26 ) , & V_26 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_3 V_47 ,
bool V_48 )
{
struct V_49 V_50 = {} ;
struct V_51 * V_52 ;
T_2 V_53 ;
int V_8 ;
V_52 = F_15 ( V_3 , V_47 ) ;
if ( ! V_52 )
return 0 ;
if ( V_52 -> V_54 == V_48 )
return 0 ;
V_53 = V_52 -> V_47 ;
if ( V_48 )
V_53 |= V_55 ;
F_16 ( V_3 , L_1 ,
V_48 ? L_2 : L_3 , V_47 ) ;
V_50 . V_56 = F_10 ( V_53 ) ;
V_52 -> V_54 = V_48 ;
V_8 = F_13 ( V_3 , V_57 , V_58 ,
sizeof( V_50 ) , & V_50 ) ;
return V_8 ;
}
static inline
void F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_48 , int V_59 )
{
struct V_60 * V_61 = F_18 ( V_5 ) ;
V_61 -> V_62 . V_63 = V_59 ;
V_61 -> V_62 . V_64 =
V_48 ? - V_65 : 0 ;
V_61 -> V_62 . V_66 =
V_48 ? - V_67 : 0 ;
}
static void F_19 ( void * V_68 , T_3 * V_69 ,
struct V_4 * V_5 )
{
struct V_60 * V_61 = F_18 ( V_5 ) ;
struct V_70 * V_71 = V_68 ;
struct V_2 * V_3 = V_71 -> V_3 ;
struct V_6 * V_7 ;
enum V_72 V_73 = V_74 ;
T_2 V_75 ;
int V_76 ;
F_7 ( & V_3 -> V_28 ) ;
switch ( V_5 -> type ) {
case V_77 :
break;
case V_78 :
if ( ! V_61 -> V_79 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_77 ) {
F_20 ( V_3 , V_5 , V_80 ,
V_73 ) ;
F_14 ( V_3 , V_61 -> V_81 ,
false ) ;
F_17 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_75 = F_5 ( V_71 -> V_82 -> V_75 ) ;
if ( V_75 >= V_83 )
V_73 = V_84 ;
else if ( V_75 >= V_85 )
V_73 = V_86 ;
if ( ! V_5 -> V_87 . V_88 )
V_73 = V_74 ;
if ( V_61 -> V_89 &&
F_21 ( V_3 -> V_22 . V_90 ,
V_61 -> V_89 -> V_91 ) )
V_73 = V_74 ;
F_16 ( V_71 -> V_3 ,
L_4 ,
V_61 -> V_91 , V_75 , V_73 ) ;
if ( V_5 -> type == V_77 )
F_20 ( V_3 , V_5 , V_80 ,
V_73 ) ;
if ( F_22 ( V_61 ) ) {
V_71 -> V_92 = true ;
V_71 -> V_93 = V_71 -> V_94 ;
V_71 -> V_94 = V_7 ;
}
if ( V_5 -> type == V_78 ) {
if ( ! V_61 -> V_79 )
return;
if ( V_7 == V_71 -> V_94 )
return;
if ( ! V_71 -> V_92 ) {
V_71 -> V_93 = V_71 -> V_94 ;
V_71 -> V_94 = V_7 ;
} else {
V_71 -> V_93 = V_7 ;
}
return;
}
if ( ! V_71 -> V_94 || V_71 -> V_94 == V_7 )
V_71 -> V_94 = V_7 ;
else if ( ! V_71 -> V_93 )
V_71 -> V_93 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_95 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_87 . V_88 ||
F_5 ( V_3 -> V_22 . V_75 ) == V_96 ) {
F_14 ( V_3 , V_61 -> V_81 , false ) ;
F_17 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_76 = V_61 -> V_62 . V_97 ;
if ( ! V_76 )
V_76 = - 100 ;
if ( V_76 > - V_65 ) {
if ( F_14 ( V_3 , V_61 -> V_81 , true ) )
F_23 ( V_3 , L_5 ) ;
} else if ( V_76 < - V_67 ) {
if ( F_14 ( V_3 , V_61 -> V_81 , false ) )
F_23 ( V_3 , L_5 ) ;
}
F_17 ( V_3 , V_5 , true , V_76 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_70 V_71 = {
. V_3 = V_3 ,
. V_82 = & V_3 -> V_22 ,
} ;
struct V_98 V_50 = {} ;
T_3 V_99 ;
if ( F_8 ( V_3 -> V_29 != V_30 ) )
return;
F_2 () ;
F_25 (
V_3 -> V_100 , V_101 ,
F_19 , & V_71 ) ;
if ( V_71 . V_94 ) {
struct V_6 * V_13 = V_71 . V_94 ;
if ( F_9 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_102 < V_103 ) {
V_99 = 0 ;
} else {
if ( V_13 -> V_12 . V_104 >
V_13 -> V_12 . V_13 -> V_105 )
V_99 = 2 ;
else
V_99 = 1 ;
}
V_50 . V_106 =
V_107 [ V_13 -> V_12 . V_13 -> V_108 ] [ V_99 ] ;
V_50 . V_10 =
F_10 ( * ( ( T_1 * ) V_71 . V_94 -> V_20 ) ) ;
}
if ( V_71 . V_93 ) {
struct V_6 * V_13 = V_71 . V_93 ;
if ( F_9 ( ! V_71 . V_93 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_102 < V_103 ) {
V_99 = 0 ;
} else {
if ( V_13 -> V_12 . V_104 >
V_13 -> V_12 . V_13 -> V_105 )
V_99 = 2 ;
else
V_99 = 1 ;
}
V_50 . V_109 =
V_107 [ V_13 -> V_12 . V_13 -> V_108 ] [ V_99 ] ;
V_50 . V_11 =
F_10 ( * ( ( T_1 * ) V_71 . V_93 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_50 , & V_3 -> V_21 , sizeof( V_50 ) ) ) {
if ( F_13 ( V_3 , V_110 , 0 ,
sizeof( V_50 ) , & V_50 ) )
F_23 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_50 , sizeof( V_50 ) ) ;
}
}
void F_26 ( struct V_2 * V_3 ,
struct V_111 * V_112 )
{
struct V_113 * V_114 = F_27 ( V_112 ) ;
struct V_115 * V_82 = ( void * ) V_114 -> V_71 ;
F_16 ( V_3 , L_7 ) ;
F_16 ( V_3 , L_8 , V_82 -> V_116 ) ;
F_16 ( V_3 , L_9 ,
F_5 ( V_82 -> V_23 ) ) ;
F_16 ( V_3 , L_10 ,
F_5 ( V_82 -> V_24 ) ) ;
F_16 ( V_3 , L_11 ,
F_5 ( V_82 -> V_75 ) ) ;
memcpy ( & V_3 -> V_22 , V_82 , sizeof( V_3 -> V_22 ) ) ;
F_24 ( V_3 ) ;
}
void F_28 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_117 V_118 )
{
struct V_60 * V_61 = F_18 ( V_5 ) ;
int V_8 ;
F_7 ( & V_3 -> V_28 ) ;
if ( F_8 ( V_3 -> V_29 != V_30 ) )
return;
if ( V_61 -> V_81 == V_119 )
return;
if ( F_5 ( V_3 -> V_22 . V_75 ) == V_96 )
return;
F_16 ( V_3 , L_12 , V_5 -> V_87 . V_120 ,
V_118 == V_121 ? L_13 : L_14 ) ;
if ( V_118 == V_122 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_95 )
V_8 = F_14 ( V_3 , V_61 -> V_81 ,
false ) ;
else
V_8 = F_14 ( V_3 , V_61 -> V_81 , true ) ;
if ( V_8 )
F_23 ( V_3 , L_15 ) ;
}
T_1 F_29 ( struct V_2 * V_3 ,
struct V_123 * V_124 )
{
struct V_51 * V_52 = F_30 ( V_124 ) ;
struct V_60 * V_61 = F_18 ( V_52 -> V_5 ) ;
struct V_125 * V_89 = V_61 -> V_89 ;
enum V_1 V_126 ;
if ( F_31 ( V_3 -> V_22 . V_90 , V_89 -> V_91 ) )
return V_127 ;
if ( F_5 ( V_3 -> V_22 . V_75 ) <
V_83 )
return V_127 ;
V_126 = F_1 ( V_3 , V_52 -> V_5 ) ;
if ( V_126 == V_95 || V_126 == V_16 )
return V_127 ;
return V_128 ;
}
bool F_32 ( struct V_2 * V_3 ,
struct V_123 * V_124 )
{
struct V_51 * V_52 = F_30 ( V_124 ) ;
struct V_60 * V_61 = F_18 ( V_52 -> V_5 ) ;
struct V_125 * V_89 = V_61 -> V_89 ;
enum V_1 V_126 ;
if ( F_31 ( V_3 -> V_22 . V_90 , V_89 -> V_91 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_75 ) <
V_83 )
return true ;
V_126 = F_1 ( V_3 , V_52 -> V_5 ) ;
return V_126 != V_95 ;
}
bool F_33 ( struct V_2 * V_3 , T_3 V_129 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( V_129 & V_3 -> V_18 -> V_130 )
return true ;
return F_5 ( V_3 -> V_22 . V_75 ) <
V_83 ;
}
bool F_34 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
return F_5 ( V_3 -> V_22 . V_75 ) < V_83 ;
}
bool F_35 ( struct V_2 * V_3 ,
enum V_131 V_14 )
{
T_2 V_132 = F_5 ( V_3 -> V_22 . V_75 ) ;
if ( V_14 != V_15 )
return false ;
return V_132 >= V_85 ;
}
T_3 F_36 ( struct V_2 * V_3 , struct V_133 * V_134 ,
struct V_135 * V_136 , T_3 V_137 )
{
T_4 V_138 = V_134 -> V_139 ;
bool V_140 = F_12 ( V_3 ) ;
if ( V_136 -> V_14 != V_15 )
return 0 ;
if ( F_8 ( V_3 -> V_141 ) )
return V_3 -> V_141 - 1 ;
if ( F_37 ( F_38 ( V_138 ) ) ) {
if ( F_37 ( F_39 ( V_138 ) ) ) {
switch ( V_137 ) {
case V_142 :
return V_140 ? 1 : 0 ;
case V_143 :
return V_140 ? 2 : 3 ;
case V_144 :
return 3 ;
default:
return 0 ;
}
} else if ( F_40 ( V_134 -> V_145 ) ) {
return 3 ;
} else
return 0 ;
} else if ( F_41 ( V_138 ) ) {
return F_42 ( V_138 ) ? 0 : 3 ;
} else if ( F_43 ( V_138 ) ) {
return 3 ;
}
return 0 ;
}
void F_44 ( struct V_2 * V_3 )
{
F_24 ( V_3 ) ;
}
void F_45 ( struct V_2 * V_3 ,
struct V_111 * V_112 )
{
struct V_113 * V_114 = F_27 ( V_112 ) ;
T_2 V_146 = F_46 ( ( void * ) V_114 -> V_71 ) ;
struct V_147 V_50 = {} ;
T_3 T_5 V_148 , V_149 ;
T_3 V_150 ;
if ( ! F_11 ( V_3 ) )
return;
F_7 ( & V_3 -> V_28 ) ;
if ( F_8 ( V_3 -> V_29 != V_30 ) )
return;
if ( V_146 == V_3 -> V_151 )
return;
for ( V_150 = 0 ; V_150 < F_47 ( V_152 ) - 1 ; V_150 ++ )
if ( V_146 < V_152 [ V_150 + 1 ] . V_153 )
break;
V_148 = V_152 [ V_150 ] . V_153 ;
if ( V_150 < F_47 ( V_152 ) - 1 )
V_149 = V_152 [ V_150 + 1 ] . V_153 ;
else
V_149 = V_152 [ V_150 ] . V_153 ;
F_16 ( V_3 , L_16 ,
V_146 , V_148 , V_149 , V_150 ) ;
V_3 -> V_151 = V_146 ;
if ( V_3 -> V_154 == V_150 )
return;
V_3 -> V_154 = V_150 ;
memcpy ( & V_50 . V_155 , V_152 [ V_150 ] . V_156 ,
sizeof( V_50 . V_155 ) ) ;
memcpy ( & V_50 . V_157 , V_152 [ V_150 ] . V_156 ,
sizeof( V_50 . V_157 ) ) ;
if ( F_13 ( V_3 , V_158 , 0 ,
sizeof( V_50 ) , & V_50 ) )
F_23 ( V_3 ,
L_17 ) ;
}
