static int F_1 ( struct V_1 * V_2 , int type , T_1 V_3 )
{
return F_2 ( V_2 , type , F_3 ( ( V_4 V_5 ) V_3 ) ) ;
}
static T_1 F_4 ( const struct V_6 * V_7 )
{
return F_5 ( F_6 ( V_7 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , int type , T_2 V_8 )
{
return F_8 ( V_2 , type , F_9 ( V_8 ) ) ;
}
static T_2 F_10 ( const struct V_6 * V_7 )
{
return F_11 ( F_12 ( V_7 ) ) ;
}
static int F_13 ( struct V_9 * V_10 , T_3 V_11 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_12 ) ;
V_2 = F_15 ( 0 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_18 ( V_2 , V_19 , V_20 ,
V_10 -> V_21 ) ||
F_19 ( V_2 , V_22 , V_11 ) )
goto V_23;
return F_20 ( V_2 , V_24 ) ;
V_23:
F_21 ( V_2 ) ;
return - V_14 ;
}
static int F_22 ( struct V_1 * V_2 , T_4 V_25 ,
T_4 V_26 , int V_27 , struct V_9 * V_10 )
{
void * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_2 V_33 , V_34 ;
F_14 ( L_1 , V_12 ) ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_27 ,
V_36 ) ;
if ( ! V_28 )
goto V_37;
V_32 = V_31 ( V_10 ) ;
V_30 = V_10 -> V_38 -> V_29 ;
F_24 ( ! V_30 ) ;
F_25 ( & V_30 -> V_10 ) ;
V_33 = V_32 -> V_39 ( V_10 ) ;
V_34 = V_32 -> V_40 ( V_10 ) ;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_16 ( V_2 , V_41 , F_26 ( V_30 ) ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_18 ( V_2 , V_19 , V_20 ,
V_10 -> V_21 ) ||
F_7 ( V_2 , V_42 , V_33 ) ||
F_7 ( V_2 , V_43 , V_34 ) )
goto V_23;
if ( V_32 -> V_44 ) {
struct V_45 V_46 ;
F_27 () ;
V_32 -> V_44 ( V_10 , & V_46 ) ;
F_28 () ;
if ( F_29 ( V_2 , V_47 ,
V_46 . V_48 ) ||
F_19 ( V_2 , V_49 , V_46 . V_50 ) ||
F_19 ( V_2 , V_51 ,
V_46 . V_52 ) ||
F_30 ( V_2 , V_53 ,
V_46 . V_54 ) ||
F_19 ( V_2 , V_55 ,
V_46 . V_56 ) ||
F_19 ( V_2 , V_57 ,
V_46 . V_58 ) ||
F_19 ( V_2 , V_59 ,
V_46 . V_60 ) ||
F_29 ( V_2 , V_61 ,
V_46 . V_62 ) )
goto V_23;
}
F_31 ( V_30 ) ;
return F_32 ( V_2 , V_28 ) ;
V_23:
F_31 ( V_30 ) ;
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_63 ;
}
static struct V_9 * F_34 ( struct V_64 * V_65 )
{
struct V_9 * V_10 ;
if ( V_65 -> V_66 [ V_15 ] ) {
char V_16 [ V_67 + 1 ] ;
F_35 ( V_16 , V_65 -> V_66 [ V_15 ] ,
sizeof( V_16 ) ) ;
V_10 = F_36 ( & V_68 , V_16 ) ;
} else if ( V_65 -> V_66 [ V_17 ] ) {
V_10 = F_37 ( & V_68 ,
F_38 ( V_65 -> V_66 [ V_17 ] ) ) ;
} else {
return NULL ;
}
if ( ! V_10 )
return NULL ;
if ( V_10 -> type != V_69 || V_10 -> V_70 != V_71 ) {
F_39 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
int F_40 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 ;
struct V_73 V_8 ;
T_3 V_74 ;
int V_75 = - V_76 ;
if ( ! V_65 -> V_66 [ V_77 ] ||
! V_65 -> V_66 [ V_78 ] ||
( ! V_65 -> V_66 [ V_79 ] &&
! V_65 -> V_66 [ V_80 ] ) ||
! V_65 -> V_66 [ V_81 ] )
return - V_82 ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( ! V_31 ( V_10 ) -> V_84 )
goto V_37;
if ( V_65 -> V_66 [ V_79 ] ) {
V_8 . V_85 = V_86 ;
V_8 . V_87 = F_4 (
V_65 -> V_66 [ V_79 ] ) ;
} else {
V_8 . V_85 = V_88 ;
V_8 . V_33 = F_10 (
V_65 -> V_66 [ V_80 ] ) ;
}
V_8 . V_34 = F_10 (
V_65 -> V_66 [ V_78 ] ) ;
if ( V_65 -> V_66 [ V_89 ] )
V_74 = F_41 ( V_65 -> V_66 [ V_89 ] ) ;
else
V_74 = 0 ;
V_75 = V_31 ( V_10 ) -> V_84 ( V_10 , & V_8 ,
F_41 ( V_65 -> V_66 [ V_77 ] ) ,
V_74 ,
F_41 ( V_65 -> V_66 [ V_81 ] ) ) ;
V_37:
F_39 ( V_10 ) ;
return V_75 ;
}
int F_42 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 ;
struct V_73 V_8 ;
int V_75 = - V_76 ;
if ( ! V_65 -> V_66 [ V_22 ] ||
! V_65 -> V_66 [ V_90 ] ||
! V_65 -> V_66 [ V_91 ] )
return - V_82 ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( ! V_31 ( V_10 ) -> V_92 )
goto V_37;
V_8 . V_85 = V_86 ;
V_8 . V_87 = F_4 (
V_65 -> V_66 [ V_90 ] ) ;
V_8 . V_34 = V_31 ( V_10 ) -> V_40 ( V_10 ) ;
V_75 = V_31 ( V_10 ) -> V_92 ( V_10 , & V_8 ,
F_10 ( V_65 -> V_66 [ V_91 ] ) ,
F_41 ( V_65 -> V_66 [ V_22 ] ) ) ;
V_37:
F_39 ( V_10 ) ;
return V_75 ;
}
int F_43 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 ;
struct V_73 V_8 ;
int V_75 = - V_76 ;
if ( ( ! V_65 -> V_66 [ V_90 ] &&
! V_65 -> V_66 [ V_91 ] ) ||
! V_65 -> V_66 [ V_93 ] )
return - V_82 ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( ! V_31 ( V_10 ) -> V_94 )
goto V_37;
if ( V_65 -> V_66 [ V_90 ] ) {
V_8 . V_85 = V_86 ;
V_8 . V_87 = F_4 (
V_65 -> V_66 [ V_90 ] ) ;
} else {
V_8 . V_85 = V_88 ;
V_8 . V_33 = F_10 (
V_65 -> V_66 [ V_91 ] ) ;
}
V_8 . V_34 = V_31 ( V_10 ) -> V_40 ( V_10 ) ;
V_75 = V_31 ( V_10 ) -> V_94 ( V_10 , & V_8 ,
F_41 ( V_65 -> V_66 [ V_93 ] ) ) ;
V_37:
F_39 ( V_10 ) ;
return V_75 ;
}
int F_44 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 ;
struct V_73 V_8 ;
T_3 V_95 , V_96 , V_97 ;
T_3 V_74 ;
int V_98 , V_99 , V_100 ;
int V_75 = - V_101 ;
if ( ! V_65 -> V_66 [ V_78 ] ||
! V_65 -> V_66 [ V_80 ] ||
! V_65 -> V_66 [ V_77 ] ||
! V_65 -> V_66 [ V_102 ] ||
! V_65 -> V_66 [ V_103 ] ||
! V_65 -> V_66 [ V_104 ] ||
! V_65 -> V_66 [ V_105 ] ||
! V_65 -> V_66 [ V_106 ]
)
return - V_82 ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( F_45 ( V_10 ) )
goto V_37;
if ( ! V_31 ( V_10 ) -> V_107 ) {
V_75 = - V_76 ;
goto V_37;
}
V_8 . V_85 = V_88 ;
V_8 . V_33 = F_10 (
V_65 -> V_66 [ V_80 ] ) ;
V_8 . V_34 = F_10 (
V_65 -> V_66 [ V_78 ] ) ;
V_95 = F_41 ( V_65 -> V_66 [ V_77 ] ) ;
V_96 = F_41 ( V_65 -> V_66 [ V_102 ] ) ;
V_97 = F_41 ( V_65 -> V_66 [ V_103 ] ) ;
V_98 = F_41 ( V_65 -> V_66 [ V_104 ] ) ;
V_99 = F_41 ( V_65 -> V_66 [ V_105 ] ) ;
V_100 = F_41 ( V_65 -> V_66 [ V_106 ] ) ;
if ( V_65 -> V_66 [ V_89 ] )
V_74 = F_41 ( V_65 -> V_66 [ V_89 ] ) ;
else
V_74 = 0 ;
if ( V_8 . V_33 == F_11 ( V_108 ) ) {
F_13 ( V_10 , V_109 ) ;
F_39 ( V_10 ) ;
return - V_82 ;
}
F_27 () ;
V_75 = V_31 ( V_10 ) -> V_107 ( V_10 , & V_8 , V_95 , V_74 ,
V_96 , V_97 , V_98 , V_99 , V_100 ) ;
F_28 () ;
F_13 ( V_10 , V_110 ) ;
V_37:
F_39 ( V_10 ) ;
return V_75 ;
}
int F_46 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 ;
int V_75 = - V_76 ;
T_3 type ;
T_4 V_111 ;
T_3 V_112 ;
T_3 V_74 ;
if ( ! V_65 -> V_66 [ V_113 ] ||
! V_65 -> V_66 [ V_114 ] ||
! V_65 -> V_66 [ V_115 ] )
return - V_82 ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( ! V_31 ( V_10 ) -> V_116 )
goto V_37;
type = F_41 ( V_65 -> V_66 [ V_113 ] ) ;
V_111 = F_38 ( V_65 -> V_66 [ V_114 ] ) ;
V_112 = F_41 ( V_65 -> V_66 [ V_115 ] ) ;
if ( V_65 -> V_66 [ V_89 ] )
V_74 = F_41 ( V_65 -> V_66 [ V_89 ] ) ;
else
V_74 = 0 ;
V_75 = V_31 ( V_10 ) -> V_116 ( V_10 , type , V_111 ,
V_74 , V_112 ) ;
V_37:
F_39 ( V_10 ) ;
return V_75 ;
}
int F_47 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
int V_117 = - V_14 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
V_2 = F_48 ( V_118 , V_119 ) ;
if ( ! V_2 )
goto V_120;
V_117 = F_22 ( V_2 , V_65 -> V_121 , V_65 -> V_122 ,
0 , V_10 ) ;
if ( V_117 < 0 )
goto V_123;
F_39 ( V_10 ) ;
return F_49 ( V_2 , V_65 ) ;
V_123:
F_21 ( V_2 ) ;
V_120:
F_39 ( V_10 ) ;
return V_117 ;
}
int F_50 ( struct V_1 * V_72 , struct V_124 * V_125 )
{
struct V_126 * V_126 = F_51 ( V_72 -> V_127 ) ;
struct V_9 * V_10 ;
int V_128 ;
int V_129 = V_125 -> args [ 0 ] ;
F_14 ( L_1 , V_12 ) ;
V_128 = 0 ;
F_52 (net, dev) {
if ( V_128 < V_129 || V_10 -> type != V_69 ||
V_10 -> V_70 != V_71 )
goto V_130;
if ( F_22 ( V_72 , F_53 ( V_125 -> V_72 ) . V_25 ,
V_125 -> V_131 -> V_132 ,
V_133 , V_10 ) < 0 )
break;
V_130:
V_128 ++ ;
}
V_125 -> args [ 0 ] = V_128 ;
return V_72 -> V_134 ;
}
int F_54 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 = NULL ;
struct V_31 * V_32 ;
struct V_45 V_46 ;
struct V_29 * V_30 ;
int V_117 = - V_82 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
V_32 = V_31 ( V_10 ) ;
if ( ! V_32 -> V_44 || ! V_32 -> V_135 ) {
V_117 = - V_76 ;
goto V_37;
}
if ( F_45 ( V_10 ) ) {
V_117 = - V_101 ;
goto V_37;
}
if ( ! V_65 -> V_66 [ V_49 ] &&
! V_65 -> V_66 [ V_51 ] &&
! V_65 -> V_66 [ V_53 ] &&
! V_65 -> V_66 [ V_55 ] &&
! V_65 -> V_66 [ V_57 ] &&
! V_65 -> V_66 [ V_59 ] &&
! V_65 -> V_66 [ V_61 ] )
goto V_37;
V_30 = V_10 -> V_38 -> V_29 ;
F_25 ( & V_30 -> V_10 ) ;
F_27 () ;
V_32 -> V_44 ( V_10 , & V_46 ) ;
if ( V_65 -> V_66 [ V_47 ] )
V_46 . V_48 = F_55 ( V_65 -> V_66 [ V_47 ] ) ;
if ( V_65 -> V_66 [ V_49 ] )
V_46 . V_50 = F_41 ( V_65 -> V_66 [ V_49 ] ) ;
if ( V_65 -> V_66 [ V_51 ] )
V_46 . V_52 = F_41 ( V_65 -> V_66 [ V_51 ] ) ;
if ( V_65 -> V_66 [ V_53 ] )
V_46 . V_54 = F_56 ( V_65 -> V_66 [ V_53 ] ) ;
if ( V_65 -> V_66 [ V_55 ] )
V_46 . V_56 = F_41 ( V_65 -> V_66 [ V_55 ] ) ;
if ( V_65 -> V_66 [ V_57 ] )
V_46 . V_58 = F_41 ( V_65 -> V_66 [ V_57 ] ) ;
if ( V_65 -> V_66 [ V_59 ] )
V_46 . V_60 = F_41 ( V_65 -> V_66 [ V_59 ] ) ;
if ( V_65 -> V_66 [ V_61 ] )
V_46 . V_62 = F_55 ( V_65 -> V_66 [ V_61 ] ) ;
V_117 = V_32 -> V_135 ( V_10 , & V_46 ) ;
F_28 () ;
F_31 ( V_30 ) ;
F_39 ( V_10 ) ;
return 0 ;
V_37:
F_39 ( V_10 ) ;
return V_117 ;
}
static int
F_57 ( struct V_64 * V_65 ,
struct V_136 * V_137 )
{
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
if ( ! V_65 -> V_66 [ V_138 ] )
return - V_82 ;
V_137 -> V_85 = F_41 ( V_65 -> V_66 [ V_138 ] ) ;
if ( V_137 -> V_85 == V_139 ) {
if ( ! V_65 -> V_66 [ V_43 ] &&
! ( V_65 -> V_66 [ V_42 ] ||
V_65 -> V_66 [ V_19 ] ) )
return - V_82 ;
V_137 -> V_140 . V_34 = F_10 ( V_65 -> V_66 [ V_43 ] ) ;
if ( V_65 -> V_66 [ V_42 ] ) {
V_137 -> V_140 . V_85 = V_88 ;
V_137 -> V_140 . V_33 = F_10 ( V_65 -> V_66 [ V_42 ] ) ;
} else {
V_137 -> V_140 . V_85 = V_86 ;
V_137 -> V_140 . V_87 = F_4 ( V_65 -> V_66 [ V_19 ] ) ;
}
}
if ( V_137 -> V_85 != V_139 &&
! V_65 -> V_66 [ V_141 ] )
return - V_82 ;
if ( V_137 -> V_85 == V_142 &&
! V_65 -> V_66 [ V_143 ] )
return - V_82 ;
if ( V_137 -> V_85 == V_144 &&
! V_65 -> V_66 [ V_145 ] )
return - V_82 ;
if ( V_137 -> V_85 != V_139 )
V_137 -> V_146 = F_41 ( V_65 -> V_66 [ V_141 ] ) ;
switch ( V_137 -> V_85 ) {
case V_142 :
{
T_4 V_147 = F_38 ( V_65 -> V_66 [ V_143 ] ) ;
V_137 -> V_148 = F_58 ( V_147 ) ;
break;
}
case V_144 :
V_137 -> V_149 = F_4 ( V_65 -> V_66 [ V_145 ] ) ;
break;
}
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 ,
const struct V_136 * V_137 )
{
if ( F_19 ( V_2 , V_138 , V_137 -> V_85 ) )
return - V_63 ;
if ( V_137 -> V_85 == V_139 ) {
if ( F_7 ( V_2 , V_43 ,
V_137 -> V_140 . V_34 ) )
return - V_63 ;
if ( V_137 -> V_140 . V_85 == V_88 &&
F_7 ( V_2 , V_42 ,
V_137 -> V_140 . V_33 ) )
return - V_63 ;
if ( V_137 -> V_140 . V_85 == V_86 &&
F_1 ( V_2 , V_19 ,
V_137 -> V_140 . V_87 ) )
return - V_63 ;
}
if ( V_137 -> V_85 != V_139 &&
F_19 ( V_2 , V_141 , V_137 -> V_146 ) )
return - V_63 ;
if ( V_137 -> V_85 == V_142 &&
F_17 ( V_2 , V_143 ,
F_60 ( V_137 -> V_148 ) ) )
return - V_63 ;
if ( V_137 -> V_85 == V_144 &&
F_1 ( V_2 , V_145 ,
V_137 -> V_149 ) )
return - V_63 ;
return 0 ;
}
int F_61 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
int V_117 = - V_14 ;
struct V_31 * V_32 ;
void * V_28 ;
struct V_150 V_46 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
V_32 = V_31 ( V_10 ) ;
if ( ! V_32 -> V_151 ) {
V_117 = - V_76 ;
goto V_120;
}
V_2 = F_48 ( V_118 , V_119 ) ;
if ( ! V_2 )
goto V_120;
V_28 = F_23 ( V_2 , 0 , V_65 -> V_122 , & V_35 , 0 ,
V_152 ) ;
if ( ! V_28 )
goto V_123;
V_117 = V_32 -> V_151 -> V_153 ( V_10 , & V_46 ) ;
if ( V_117 < 0 )
goto V_123;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_19 ( V_2 , V_154 , V_46 . V_155 ) ||
F_19 ( V_2 , V_156 , V_46 . V_157 ) ||
F_17 ( V_2 , V_158 ,
F_62 ( V_46 . V_159 ) ) ||
F_59 ( V_2 , & V_46 . V_160 ) )
goto V_123;
F_39 ( V_10 ) ;
return F_63 ( V_2 , V_65 ) ;
V_123:
F_21 ( V_2 ) ;
V_120:
F_39 ( V_10 ) ;
return V_117 ;
}
int F_64 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
struct V_9 * V_10 = NULL ;
int V_117 = - V_82 ;
struct V_31 * V_32 ;
struct V_150 V_46 ;
int V_161 = 0 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( ! V_65 -> V_66 [ V_154 ] &&
! V_65 -> V_66 [ V_138 ] &&
! V_65 -> V_66 [ V_156 ] )
goto V_37;
V_32 = V_31 ( V_10 ) ;
if ( ! V_32 -> V_151 ) {
V_117 = - V_76 ;
goto V_37;
}
if ( V_65 -> V_66 [ V_156 ] &&
F_41 ( V_65 -> V_66 [ V_156 ] ) > 7 )
goto V_37;
if ( V_65 -> V_66 [ V_154 ] ) {
V_46 . V_155 = F_41 ( V_65 -> V_66 [ V_154 ] ) ;
V_161 |= V_162 ;
}
if ( V_65 -> V_66 [ V_138 ] ) {
if ( F_57 ( V_65 , & V_46 . V_160 ) )
goto V_37;
V_161 |= V_163 ;
}
if ( V_65 -> V_66 [ V_156 ] ) {
V_46 . V_157 = F_41 ( V_65 -> V_66 [ V_156 ] ) ;
V_161 |= V_164 ;
}
if ( V_65 -> V_66 [ V_158 ] ) {
T_4 V_165 = F_38 ( V_65 -> V_66 [ V_158 ] ) ;
V_46 . V_159 = F_65 ( V_165 ) ;
V_161 |= V_166 ;
}
V_117 = V_32 -> V_151 -> V_167 ( V_10 , & V_46 , V_161 ) ;
F_39 ( V_10 ) ;
return V_117 ;
V_37:
F_39 ( V_10 ) ;
return V_117 ;
}
static int
F_66 ( struct V_1 * V_72 , struct V_124 * V_125 ,
int (* F_67)( struct V_168 * ) )
{
struct V_126 * V_126 = F_51 ( V_72 -> V_127 ) ;
struct V_9 * V_10 ;
struct V_168 V_169 ;
int V_128 = 0 ;
int V_170 = V_125 -> args [ 0 ] ;
int V_117 ;
F_52 (net, dev) {
if ( V_128 < V_170 || V_10 -> type != V_69 ||
V_10 -> V_70 != V_71 )
goto V_171;
V_169 . V_32 = V_31 ( V_10 ) ;
if ( ! V_169 . V_32 -> V_151 )
goto V_171;
V_169 . V_72 = V_72 ;
V_169 . V_129 = V_125 -> args [ 1 ] ;
V_169 . V_172 = V_125 -> args [ 2 ] ;
V_169 . V_10 = V_10 ;
V_169 . V_25 = F_53 ( V_125 -> V_72 ) . V_25 ;
V_169 . V_132 = V_125 -> V_131 -> V_132 ;
V_169 . V_32 -> V_151 -> V_173 ( V_10 ) ;
V_169 . V_32 -> V_151 -> V_174 ( V_169 . V_10 , & V_169 . V_175 ) ;
V_117 = F_67 ( & V_169 ) ;
V_169 . V_32 -> V_151 -> V_176 ( V_10 ) ;
if ( V_117 < 0 )
break;
V_171:
V_128 ++ ;
}
V_125 -> args [ 0 ] = V_128 ;
return V_72 -> V_134 ;
}
static int
F_68 ( struct V_1 * V_72 , struct V_64 * V_65 ,
int (* F_69)( struct V_9 * , struct V_64 * ) )
{
struct V_9 * V_10 = NULL ;
int V_117 = - V_82 ;
V_10 = F_34 ( V_65 ) ;
if ( ! V_10 )
return - V_83 ;
if ( ! V_31 ( V_10 ) -> V_151 )
V_117 = - V_76 ;
else
V_117 = F_69 ( V_10 , V_65 ) ;
F_39 ( V_10 ) ;
return V_117 ;
}
static int
F_70 ( struct V_64 * V_65 ,
struct V_177 * V_178 )
{
T_3 V_179 ;
T_4 V_180 [ 256 / 32 ] ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
if ( ! V_65 -> V_66 [ V_181 ] ||
! V_65 -> V_66 [ V_182 ] )
return - V_82 ;
V_179 = F_41 ( V_65 -> V_66 [ V_181 ] ) ;
if ( ( V_179 & F_71 ( V_183 ) ) &&
! V_65 -> V_66 [ V_184 ] )
return - V_82 ;
if ( V_65 -> V_66 [ V_184 ] ) {
F_72 ( V_180 ,
V_65 -> V_66 [ V_184 ] ,
256 / 8 ) ;
if ( V_180 [ 0 ] || V_180 [ 1 ] || V_180 [ 2 ] || V_180 [ 3 ] ||
V_180 [ 4 ] || V_180 [ 5 ] || V_180 [ 6 ] ||
V_180 [ 7 ] >= F_71 ( V_185 + 1 ) )
return - V_82 ;
V_178 -> V_186 = V_180 [ 7 ] ;
}
V_178 -> V_187 = V_179 ;
F_72 ( V_178 -> V_178 , V_65 -> V_66 [ V_182 ] ,
V_188 ) ;
return 0 ;
}
static int F_73 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_177 V_178 ;
struct V_136 V_146 ;
if ( F_70 ( V_65 , & V_178 ) ||
F_57 ( V_65 , & V_146 ) )
return - V_82 ;
return V_32 -> V_151 -> V_189 ( V_10 , & V_146 , & V_178 ) ;
}
int F_74 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_190 -> V_191 & ( V_192 | V_193 ) ) !=
( V_192 | V_193 ) )
return - V_82 ;
return F_68 ( V_72 , V_65 , F_73 ) ;
}
static int F_75 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_136 V_146 ;
if ( F_57 ( V_65 , & V_146 ) )
return - V_82 ;
return V_32 -> V_151 -> V_194 ( V_10 , & V_146 ) ;
}
int F_76 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
return F_68 ( V_72 , V_65 , F_75 ) ;
}
static int
F_77 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
const struct V_195 * V_178 ,
const struct V_9 * V_10 )
{
void * V_28 ;
T_4 V_180 [ 256 / 32 ] ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_133 ,
V_196 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_59 ( V_2 , & V_178 -> V_146 ) ||
F_19 ( V_2 , V_181 ,
V_178 -> V_178 -> V_187 ) )
goto V_23;
if ( V_178 -> V_178 -> V_187 & F_71 ( V_183 ) ) {
memset ( V_180 , 0 , sizeof( V_180 ) ) ;
V_180 [ 7 ] = V_178 -> V_178 -> V_186 ;
if ( F_18 ( V_2 , V_184 ,
sizeof( V_180 ) , V_180 ) )
goto V_23;
}
if ( F_18 ( V_2 , V_182 ,
V_188 , V_178 -> V_178 -> V_178 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_63 ;
}
static int F_78 ( struct V_168 * V_169 )
{
struct V_195 * V_197 ;
int V_117 = 0 , V_128 = 0 ;
F_79 (pos, &data->table->keys, list) {
if ( V_128 ++ < V_169 -> V_129 )
continue;
if ( F_77 ( V_169 -> V_72 , V_169 -> V_25 ,
V_169 -> V_132 , V_197 , V_169 -> V_10 ) ) {
V_117 = - V_63 ;
break;
}
V_169 -> V_129 ++ ;
}
return V_117 ;
}
int F_80 ( struct V_1 * V_72 , struct V_124 * V_125 )
{
return F_66 ( V_72 , V_125 , F_78 ) ;
}
static int
F_81 ( struct V_64 * V_65 ,
struct V_198 * V_10 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( ! V_65 -> V_66 [ V_158 ] ||
! V_65 -> V_66 [ V_19 ] ||
! V_65 -> V_66 [ V_199 ] ||
! V_65 -> V_66 [ V_200 ] ||
( ! ! V_65 -> V_66 [ V_43 ] !=
! ! V_65 -> V_66 [ V_42 ] ) )
return - V_82 ;
if ( V_65 -> V_66 [ V_43 ] ) {
V_10 -> V_34 = F_10 ( V_65 -> V_66 [ V_43 ] ) ;
V_10 -> V_33 = F_10 ( V_65 -> V_66 [ V_42 ] ) ;
} else {
V_10 -> V_33 = F_11 ( V_201 ) ;
}
V_10 -> V_3 = F_4 ( V_65 -> V_66 [ V_19 ] ) ;
V_10 -> V_159 = F_38 ( V_65 -> V_66 [ V_158 ] ) ;
V_10 -> V_202 = ! ! F_41 ( V_65 -> V_66 [ V_199 ] ) ;
V_10 -> V_203 = F_41 ( V_65 -> V_66 [ V_200 ] ) ;
if ( V_10 -> V_203 >= V_204 )
return - V_82 ;
return 0 ;
}
static int F_82 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_198 V_137 ;
if ( F_81 ( V_65 , & V_137 ) )
return - V_82 ;
return V_32 -> V_151 -> V_205 ( V_10 , & V_137 ) ;
}
int F_83 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_190 -> V_191 & ( V_192 | V_193 ) ) !=
( V_192 | V_193 ) )
return - V_82 ;
return F_68 ( V_72 , V_65 , F_82 ) ;
}
static int F_84 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
T_1 V_206 ;
if ( ! V_65 -> V_66 [ V_19 ] )
return - V_82 ;
V_206 = F_4 ( V_65 -> V_66 [ V_19 ] ) ;
return V_32 -> V_151 -> V_207 ( V_10 , V_206 ) ;
}
int F_85 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
return F_68 ( V_72 , V_65 , F_84 ) ;
}
static int
F_86 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
const struct V_198 * V_137 ,
const struct V_9 * V_10 )
{
void * V_28 ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_133 ,
V_208 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_7 ( V_2 , V_43 , V_137 -> V_34 ) ||
F_7 ( V_2 , V_42 ,
V_137 -> V_33 ) ||
F_1 ( V_2 , V_19 , V_137 -> V_3 ) ||
F_17 ( V_2 , V_158 ,
V_137 -> V_159 ) ||
F_19 ( V_2 , V_199 ,
V_137 -> V_202 ) ||
F_19 ( V_2 , V_200 , V_137 -> V_203 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_63 ;
}
static int F_87 ( struct V_168 * V_169 )
{
struct V_198 * V_197 ;
int V_117 = 0 , V_128 = 0 ;
F_79 (pos, &data->table->devices, list) {
if ( V_128 ++ < V_169 -> V_129 )
continue;
if ( F_86 ( V_169 -> V_72 , V_169 -> V_25 ,
V_169 -> V_132 , V_197 , V_169 -> V_10 ) ) {
V_117 = - V_63 ;
break;
}
V_169 -> V_129 ++ ;
}
return V_117 ;
}
int F_88 ( struct V_1 * V_72 , struct V_124 * V_125 )
{
return F_66 ( V_72 , V_125 , F_87 ) ;
}
static int F_89 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_209 V_178 ;
T_1 V_206 ;
if ( ! V_65 -> V_66 [ V_158 ] ||
! V_65 -> V_66 [ V_19 ] ||
F_57 ( V_65 , & V_178 . V_210 ) )
return - V_82 ;
V_206 = F_4 ( V_65 -> V_66 [ V_19 ] ) ;
V_178 . V_159 = F_38 ( V_65 -> V_66 [ V_158 ] ) ;
return V_32 -> V_151 -> V_211 ( V_10 , V_206 , & V_178 ) ;
}
int F_90 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_190 -> V_191 & ( V_192 | V_193 ) ) !=
( V_192 | V_193 ) )
return - V_82 ;
return F_68 ( V_72 , V_65 , F_89 ) ;
}
static int F_91 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_209 V_178 ;
T_1 V_206 ;
if ( ! V_65 -> V_66 [ V_19 ] ||
F_57 ( V_65 , & V_178 . V_210 ) )
return - V_82 ;
V_206 = F_4 ( V_65 -> V_66 [ V_19 ] ) ;
return V_32 -> V_151 -> V_212 ( V_10 , V_206 , & V_178 ) ;
}
int F_92 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
return F_68 ( V_72 , V_65 , F_91 ) ;
}
static int
F_93 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
T_1 V_206 ,
const struct V_209 * V_213 ,
const struct V_9 * V_10 )
{
void * V_28 ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_133 ,
V_214 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_1 ( V_2 , V_19 , V_206 ) ||
F_17 ( V_2 , V_158 ,
V_213 -> V_159 ) ||
F_59 ( V_2 , & V_213 -> V_210 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_63 ;
}
static int F_94 ( struct V_168 * V_169 )
{
struct V_198 * V_215 ;
struct V_209 * V_216 ;
int V_117 = 0 , V_128 = 0 , V_217 ;
F_79 (dpos, &data->table->devices, list) {
if ( V_128 ++ < V_169 -> V_129 )
continue;
V_217 = 0 ;
F_79 (kpos, &dpos->keys, list) {
if ( V_217 ++ < V_169 -> V_172 )
continue;
if ( F_93 ( V_169 -> V_72 , V_169 -> V_25 ,
V_169 -> V_132 ,
V_215 -> V_3 , V_216 ,
V_169 -> V_10 ) ) {
return V_117 = - V_63 ;
}
V_169 -> V_172 ++ ;
}
V_169 -> V_129 ++ ;
}
return V_117 ;
}
int F_95 ( struct V_1 * V_72 ,
struct V_124 * V_125 )
{
return F_66 ( V_72 , V_125 , F_94 ) ;
}
static int
F_96 ( struct V_64 * V_65 ,
struct V_218 * V_219 )
{
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
if ( ! V_65 -> V_66 [ V_220 ] ||
! V_65 -> V_66 [ V_221 ] ||
! V_65 -> V_66 [ V_199 ] )
return - V_82 ;
V_219 -> V_222 = F_41 ( V_65 -> V_66 [ V_220 ] ) ;
if ( V_219 -> V_222 == V_183 ) {
if ( ! V_65 -> V_66 [ V_223 ] )
return - V_82 ;
V_219 -> V_224 = F_41 ( V_65 -> V_66 [ V_223 ] ) ;
}
V_219 -> V_225 = F_41 ( V_65 -> V_66 [ V_221 ] ) ;
V_219 -> V_226 = F_41 ( V_65 -> V_66 [ V_199 ] ) ;
return 0 ;
}
static int F_97 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_218 V_219 ;
if ( F_96 ( V_65 , & V_219 ) )
return - V_82 ;
return V_32 -> V_151 -> V_227 ( V_10 , & V_219 ) ;
}
int F_98 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_190 -> V_191 & ( V_192 | V_193 ) ) !=
( V_192 | V_193 ) )
return - V_82 ;
return F_68 ( V_72 , V_65 , F_97 ) ;
}
static int F_99 ( struct V_9 * V_10 , struct V_64 * V_65 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_218 V_219 ;
if ( F_96 ( V_65 , & V_219 ) )
return - V_82 ;
return V_32 -> V_151 -> V_228 ( V_10 , & V_219 ) ;
}
int F_100 ( struct V_1 * V_72 , struct V_64 * V_65 )
{
return F_68 ( V_72 , V_65 , F_99 ) ;
}
static int
F_101 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
const struct V_218 * V_219 ,
const struct V_9 * V_10 )
{
void * V_28 ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_133 ,
V_229 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_19 ( V_2 , V_220 , V_219 -> V_222 ) ||
F_19 ( V_2 , V_221 , V_219 -> V_225 ) ||
F_19 ( V_2 , V_199 ,
V_219 -> V_226 ) )
goto V_23;
if ( V_219 -> V_222 == V_183 &&
F_19 ( V_2 , V_223 ,
V_219 -> V_224 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_63 ;
}
static int F_102 ( struct V_168 * V_169 )
{
struct V_218 * V_197 ;
int V_117 = 0 , V_128 = 0 ;
F_79 (pos, &data->table->security_levels, list) {
if ( V_128 ++ < V_169 -> V_129 )
continue;
if ( F_101 ( V_169 -> V_72 , V_169 -> V_25 ,
V_169 -> V_132 , V_197 ,
V_169 -> V_10 ) ) {
V_117 = - V_63 ;
break;
}
V_169 -> V_129 ++ ;
}
return V_117 ;
}
int F_103 ( struct V_1 * V_72 ,
struct V_124 * V_125 )
{
return F_66 ( V_72 , V_125 , F_102 ) ;
}
