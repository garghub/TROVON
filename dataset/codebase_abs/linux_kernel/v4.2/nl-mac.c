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
F_26 () ;
V_33 = V_10 -> V_38 -> V_33 ;
V_34 = V_10 -> V_38 -> V_34 ;
F_27 () ;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_16 ( V_2 , V_39 , F_28 ( V_30 ) ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_18 ( V_2 , V_19 , V_20 ,
V_10 -> V_21 ) ||
F_7 ( V_2 , V_40 , V_33 ) ||
F_7 ( V_2 , V_41 , V_34 ) )
goto V_23;
if ( V_32 -> V_42 ) {
struct V_43 V_44 ;
F_26 () ;
V_32 -> V_42 ( V_10 , & V_44 ) ;
F_27 () ;
if ( F_29 ( V_2 , V_45 ,
V_44 . V_46 / 100 ) ||
F_19 ( V_2 , V_47 , V_44 . V_48 ) ||
F_19 ( V_2 , V_49 ,
V_44 . V_50 . V_51 ) ||
F_30 ( V_2 , V_52 ,
V_44 . V_53 / 100 ) ||
F_19 ( V_2 , V_54 ,
V_44 . V_55 ) ||
F_19 ( V_2 , V_56 ,
V_44 . V_57 ) ||
F_19 ( V_2 , V_58 ,
V_44 . V_59 ) ||
F_29 ( V_2 , V_60 ,
V_44 . V_61 ) )
goto V_23;
}
F_31 ( V_30 ) ;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_31 ( V_30 ) ;
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_62 ;
}
static struct V_9 * F_34 ( struct V_63 * V_64 )
{
struct V_9 * V_10 ;
if ( V_64 -> V_65 [ V_15 ] ) {
char V_16 [ V_66 + 1 ] ;
F_35 ( V_16 , V_64 -> V_65 [ V_15 ] ,
sizeof( V_16 ) ) ;
V_10 = F_36 ( & V_67 , V_16 ) ;
} else if ( V_64 -> V_65 [ V_17 ] ) {
V_10 = F_37 ( & V_67 ,
F_38 ( V_64 -> V_65 [ V_17 ] ) ) ;
} else {
return NULL ;
}
if ( ! V_10 )
return NULL ;
if ( V_10 -> type != V_68 ) {
F_39 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
int F_40 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 ;
struct V_70 V_8 ;
T_3 V_71 ;
int V_72 = - V_73 ;
if ( ! V_64 -> V_65 [ V_74 ] ||
! V_64 -> V_65 [ V_75 ] ||
( ! V_64 -> V_65 [ V_76 ] &&
! V_64 -> V_65 [ V_77 ] ) ||
! V_64 -> V_65 [ V_78 ] )
return - V_79 ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( ! V_31 ( V_10 ) -> V_81 )
goto V_37;
if ( V_64 -> V_65 [ V_76 ] ) {
V_8 . V_51 = V_82 ;
V_8 . V_83 = F_4 (
V_64 -> V_65 [ V_76 ] ) ;
} else {
V_8 . V_51 = V_84 ;
V_8 . V_33 = F_10 (
V_64 -> V_65 [ V_77 ] ) ;
}
V_8 . V_34 = F_10 (
V_64 -> V_65 [ V_75 ] ) ;
if ( V_64 -> V_65 [ V_85 ] )
V_71 = F_41 ( V_64 -> V_65 [ V_85 ] ) ;
else
V_71 = 0 ;
V_72 = V_31 ( V_10 ) -> V_81 ( V_10 , & V_8 ,
F_41 ( V_64 -> V_65 [ V_74 ] ) ,
V_71 ,
F_41 ( V_64 -> V_65 [ V_78 ] ) ) ;
V_37:
F_39 ( V_10 ) ;
return V_72 ;
}
int F_42 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 ;
struct V_70 V_8 ;
int V_72 = - V_73 ;
if ( ! V_64 -> V_65 [ V_22 ] ||
! V_64 -> V_65 [ V_86 ] ||
! V_64 -> V_65 [ V_87 ] )
return - V_79 ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( ! V_31 ( V_10 ) -> V_88 )
goto V_37;
V_8 . V_51 = V_82 ;
V_8 . V_83 = F_4 (
V_64 -> V_65 [ V_86 ] ) ;
F_26 () ;
V_8 . V_34 = V_10 -> V_38 -> V_34 ;
F_27 () ;
V_72 = V_31 ( V_10 ) -> V_88 ( V_10 , & V_8 ,
F_10 ( V_64 -> V_65 [ V_87 ] ) ,
F_41 ( V_64 -> V_65 [ V_22 ] ) ) ;
V_37:
F_39 ( V_10 ) ;
return V_72 ;
}
int F_43 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 ;
struct V_70 V_8 ;
int V_72 = - V_73 ;
if ( ( ! V_64 -> V_65 [ V_86 ] &&
! V_64 -> V_65 [ V_87 ] ) ||
! V_64 -> V_65 [ V_89 ] )
return - V_79 ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( ! V_31 ( V_10 ) -> V_90 )
goto V_37;
if ( V_64 -> V_65 [ V_86 ] ) {
V_8 . V_51 = V_82 ;
V_8 . V_83 = F_4 (
V_64 -> V_65 [ V_86 ] ) ;
} else {
V_8 . V_51 = V_84 ;
V_8 . V_33 = F_10 (
V_64 -> V_65 [ V_87 ] ) ;
}
F_26 () ;
V_8 . V_34 = V_10 -> V_38 -> V_34 ;
F_27 () ;
V_72 = V_31 ( V_10 ) -> V_90 ( V_10 , & V_8 ,
F_41 ( V_64 -> V_65 [ V_89 ] ) ) ;
V_37:
F_39 ( V_10 ) ;
return V_72 ;
}
int F_44 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 ;
struct V_70 V_8 ;
T_3 V_91 , V_92 , V_93 ;
T_3 V_71 ;
int V_94 , V_95 , V_96 ;
int V_72 = - V_97 ;
if ( ! V_64 -> V_65 [ V_75 ] ||
! V_64 -> V_65 [ V_77 ] ||
! V_64 -> V_65 [ V_74 ] ||
! V_64 -> V_65 [ V_98 ] ||
! V_64 -> V_65 [ V_99 ] ||
! V_64 -> V_65 [ V_100 ] ||
! V_64 -> V_65 [ V_101 ] ||
! V_64 -> V_65 [ V_102 ]
)
return - V_79 ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( F_45 ( V_10 ) )
goto V_37;
if ( ! V_31 ( V_10 ) -> V_103 ) {
V_72 = - V_73 ;
goto V_37;
}
V_8 . V_51 = V_84 ;
V_8 . V_33 = F_10 (
V_64 -> V_65 [ V_77 ] ) ;
V_8 . V_34 = F_10 (
V_64 -> V_65 [ V_75 ] ) ;
V_91 = F_41 ( V_64 -> V_65 [ V_74 ] ) ;
V_92 = F_41 ( V_64 -> V_65 [ V_98 ] ) ;
V_93 = F_41 ( V_64 -> V_65 [ V_99 ] ) ;
V_94 = F_41 ( V_64 -> V_65 [ V_100 ] ) ;
V_95 = F_41 ( V_64 -> V_65 [ V_101 ] ) ;
V_96 = F_41 ( V_64 -> V_65 [ V_102 ] ) ;
if ( V_64 -> V_65 [ V_85 ] )
V_71 = F_41 ( V_64 -> V_65 [ V_85 ] ) ;
else
V_71 = 0 ;
if ( V_8 . V_33 == F_11 ( V_104 ) ) {
F_13 ( V_10 , V_105 ) ;
F_39 ( V_10 ) ;
return - V_79 ;
}
F_26 () ;
V_72 = V_31 ( V_10 ) -> V_103 ( V_10 , & V_8 , V_91 , V_71 ,
V_92 , V_93 , V_94 , V_95 , V_96 ) ;
F_27 () ;
F_13 ( V_10 , V_106 ) ;
V_37:
F_39 ( V_10 ) ;
return V_72 ;
}
int F_46 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 ;
int V_72 = - V_73 ;
T_3 type ;
T_4 V_107 ;
T_3 V_108 ;
T_3 V_71 ;
if ( ! V_64 -> V_65 [ V_109 ] ||
! V_64 -> V_65 [ V_110 ] ||
! V_64 -> V_65 [ V_111 ] )
return - V_79 ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( ! V_31 ( V_10 ) -> V_112 )
goto V_37;
type = F_41 ( V_64 -> V_65 [ V_109 ] ) ;
V_107 = F_38 ( V_64 -> V_65 [ V_110 ] ) ;
V_108 = F_41 ( V_64 -> V_65 [ V_111 ] ) ;
if ( V_64 -> V_65 [ V_85 ] )
V_71 = F_41 ( V_64 -> V_65 [ V_85 ] ) ;
else
V_71 = 0 ;
V_72 = V_31 ( V_10 ) -> V_112 ( V_10 , type , V_107 ,
V_71 , V_108 ) ;
V_37:
F_39 ( V_10 ) ;
return V_72 ;
}
int F_47 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
int V_113 = - V_14 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
V_2 = F_48 ( V_114 , V_115 ) ;
if ( ! V_2 )
goto V_116;
V_113 = F_22 ( V_2 , V_64 -> V_117 , V_64 -> V_118 ,
0 , V_10 ) ;
if ( V_113 < 0 )
goto V_119;
F_39 ( V_10 ) ;
return F_49 ( V_2 , V_64 ) ;
V_119:
F_21 ( V_2 ) ;
V_116:
F_39 ( V_10 ) ;
return V_113 ;
}
int F_50 ( struct V_1 * V_69 , struct V_120 * V_121 )
{
struct V_122 * V_122 = F_51 ( V_69 -> V_123 ) ;
struct V_9 * V_10 ;
int V_124 ;
int V_125 = V_121 -> args [ 0 ] ;
F_14 ( L_1 , V_12 ) ;
V_124 = 0 ;
F_52 (net, dev) {
if ( V_124 < V_125 || V_10 -> type != V_68 )
goto V_126;
if ( F_22 ( V_69 , F_53 ( V_121 -> V_69 ) . V_25 ,
V_121 -> V_127 -> V_128 ,
V_129 , V_10 ) < 0 )
break;
V_126:
V_124 ++ ;
}
V_121 -> args [ 0 ] = V_124 ;
return V_69 -> V_130 ;
}
int F_54 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 = NULL ;
struct V_31 * V_32 ;
struct V_43 V_44 ;
struct V_29 * V_30 ;
int V_113 = - V_79 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
V_32 = V_31 ( V_10 ) ;
if ( ! V_32 -> V_42 || ! V_32 -> V_131 ) {
V_113 = - V_73 ;
goto V_37;
}
if ( F_45 ( V_10 ) ) {
V_113 = - V_97 ;
goto V_37;
}
if ( ! V_64 -> V_65 [ V_47 ] &&
! V_64 -> V_65 [ V_49 ] &&
! V_64 -> V_65 [ V_52 ] &&
! V_64 -> V_65 [ V_54 ] &&
! V_64 -> V_65 [ V_56 ] &&
! V_64 -> V_65 [ V_58 ] &&
! V_64 -> V_65 [ V_60 ] )
goto V_37;
V_30 = V_10 -> V_38 -> V_29 ;
F_25 ( & V_30 -> V_10 ) ;
F_26 () ;
V_32 -> V_42 ( V_10 , & V_44 ) ;
if ( V_64 -> V_65 [ V_45 ] )
V_44 . V_46 = F_55 ( V_64 -> V_65 [ V_45 ] ) * 100 ;
if ( V_64 -> V_65 [ V_47 ] )
V_44 . V_48 = F_41 ( V_64 -> V_65 [ V_47 ] ) ;
if ( V_64 -> V_65 [ V_49 ] )
V_44 . V_50 . V_51 = F_41 ( V_64 -> V_65 [ V_49 ] ) ;
if ( V_64 -> V_65 [ V_52 ] )
V_44 . V_53 = F_56 ( V_64 -> V_65 [ V_52 ] ) * 100 ;
if ( V_64 -> V_65 [ V_54 ] )
V_44 . V_55 = F_41 ( V_64 -> V_65 [ V_54 ] ) ;
if ( V_64 -> V_65 [ V_56 ] )
V_44 . V_57 = F_41 ( V_64 -> V_65 [ V_56 ] ) ;
if ( V_64 -> V_65 [ V_58 ] )
V_44 . V_59 = F_41 ( V_64 -> V_65 [ V_58 ] ) ;
if ( V_64 -> V_65 [ V_60 ] )
V_44 . V_61 = F_55 ( V_64 -> V_65 [ V_60 ] ) ;
V_113 = V_32 -> V_131 ( V_10 , & V_44 ) ;
F_27 () ;
F_31 ( V_30 ) ;
F_39 ( V_10 ) ;
return 0 ;
V_37:
F_39 ( V_10 ) ;
return V_113 ;
}
static int
F_57 ( struct V_63 * V_64 ,
struct V_132 * V_133 )
{
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
if ( ! V_64 -> V_65 [ V_134 ] )
return - V_79 ;
V_133 -> V_51 = F_41 ( V_64 -> V_65 [ V_134 ] ) ;
if ( V_133 -> V_51 == V_135 ) {
if ( ! V_64 -> V_65 [ V_41 ] &&
! ( V_64 -> V_65 [ V_40 ] ||
V_64 -> V_65 [ V_19 ] ) )
return - V_79 ;
V_133 -> V_136 . V_34 = F_10 ( V_64 -> V_65 [ V_41 ] ) ;
if ( V_64 -> V_65 [ V_40 ] ) {
V_133 -> V_136 . V_51 = V_84 ;
V_133 -> V_136 . V_33 = F_10 ( V_64 -> V_65 [ V_40 ] ) ;
} else {
V_133 -> V_136 . V_51 = V_82 ;
V_133 -> V_136 . V_83 = F_4 ( V_64 -> V_65 [ V_19 ] ) ;
}
}
if ( V_133 -> V_51 != V_135 &&
! V_64 -> V_65 [ V_137 ] )
return - V_79 ;
if ( V_133 -> V_51 == V_138 &&
! V_64 -> V_65 [ V_139 ] )
return - V_79 ;
if ( V_133 -> V_51 == V_140 &&
! V_64 -> V_65 [ V_141 ] )
return - V_79 ;
if ( V_133 -> V_51 != V_135 )
V_133 -> V_142 = F_41 ( V_64 -> V_65 [ V_137 ] ) ;
switch ( V_133 -> V_51 ) {
case V_138 :
{
T_4 V_143 = F_38 ( V_64 -> V_65 [ V_139 ] ) ;
V_133 -> V_144 = F_58 ( V_143 ) ;
break;
}
case V_140 :
V_133 -> V_145 = F_4 ( V_64 -> V_65 [ V_141 ] ) ;
break;
}
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 ,
const struct V_132 * V_133 )
{
if ( F_19 ( V_2 , V_134 , V_133 -> V_51 ) )
return - V_62 ;
if ( V_133 -> V_51 == V_135 ) {
if ( F_7 ( V_2 , V_41 ,
V_133 -> V_136 . V_34 ) )
return - V_62 ;
if ( V_133 -> V_136 . V_51 == V_84 &&
F_7 ( V_2 , V_40 ,
V_133 -> V_136 . V_33 ) )
return - V_62 ;
if ( V_133 -> V_136 . V_51 == V_82 &&
F_1 ( V_2 , V_19 ,
V_133 -> V_136 . V_83 ) )
return - V_62 ;
}
if ( V_133 -> V_51 != V_135 &&
F_19 ( V_2 , V_137 , V_133 -> V_142 ) )
return - V_62 ;
if ( V_133 -> V_51 == V_138 &&
F_17 ( V_2 , V_139 ,
F_60 ( V_133 -> V_144 ) ) )
return - V_62 ;
if ( V_133 -> V_51 == V_140 &&
F_1 ( V_2 , V_141 ,
V_133 -> V_145 ) )
return - V_62 ;
return 0 ;
}
int F_61 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
int V_113 = - V_14 ;
struct V_31 * V_32 ;
void * V_28 ;
struct V_146 V_44 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
V_32 = V_31 ( V_10 ) ;
if ( ! V_32 -> V_147 ) {
V_113 = - V_73 ;
goto V_116;
}
V_2 = F_48 ( V_114 , V_115 ) ;
if ( ! V_2 )
goto V_116;
V_28 = F_23 ( V_2 , 0 , V_64 -> V_118 , & V_35 , 0 ,
V_148 ) ;
if ( ! V_28 )
goto V_119;
V_113 = V_32 -> V_147 -> V_149 ( V_10 , & V_44 ) ;
if ( V_113 < 0 )
goto V_119;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_19 ( V_2 , V_150 , V_44 . V_151 ) ||
F_19 ( V_2 , V_152 , V_44 . V_153 ) ||
F_17 ( V_2 , V_154 ,
F_62 ( V_44 . V_155 ) ) ||
F_59 ( V_2 , & V_44 . V_156 ) )
goto V_119;
F_39 ( V_10 ) ;
return F_63 ( V_2 , V_64 ) ;
V_119:
F_21 ( V_2 ) ;
V_116:
F_39 ( V_10 ) ;
return V_113 ;
}
int F_64 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
struct V_9 * V_10 = NULL ;
int V_113 = - V_79 ;
struct V_31 * V_32 ;
struct V_146 V_44 ;
int V_157 = 0 ;
F_14 ( L_1 , V_12 ) ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( ! V_64 -> V_65 [ V_150 ] &&
! V_64 -> V_65 [ V_134 ] &&
! V_64 -> V_65 [ V_152 ] )
goto V_37;
V_32 = V_31 ( V_10 ) ;
if ( ! V_32 -> V_147 ) {
V_113 = - V_73 ;
goto V_37;
}
if ( V_64 -> V_65 [ V_152 ] &&
F_41 ( V_64 -> V_65 [ V_152 ] ) > 7 )
goto V_37;
if ( V_64 -> V_65 [ V_150 ] ) {
V_44 . V_151 = F_41 ( V_64 -> V_65 [ V_150 ] ) ;
V_157 |= V_158 ;
}
if ( V_64 -> V_65 [ V_134 ] ) {
if ( F_57 ( V_64 , & V_44 . V_156 ) )
goto V_37;
V_157 |= V_159 ;
}
if ( V_64 -> V_65 [ V_152 ] ) {
V_44 . V_153 = F_41 ( V_64 -> V_65 [ V_152 ] ) ;
V_157 |= V_160 ;
}
if ( V_64 -> V_65 [ V_154 ] ) {
T_4 V_161 = F_38 ( V_64 -> V_65 [ V_154 ] ) ;
V_44 . V_155 = F_65 ( V_161 ) ;
V_157 |= V_162 ;
}
V_113 = V_32 -> V_147 -> V_163 ( V_10 , & V_44 , V_157 ) ;
F_39 ( V_10 ) ;
return V_113 ;
V_37:
F_39 ( V_10 ) ;
return V_113 ;
}
static int
F_66 ( struct V_1 * V_69 , struct V_120 * V_121 ,
int (* F_67)( struct V_164 * ) )
{
struct V_122 * V_122 = F_51 ( V_69 -> V_123 ) ;
struct V_9 * V_10 ;
struct V_164 V_165 ;
int V_124 = 0 ;
int V_166 = V_121 -> args [ 0 ] ;
int V_113 ;
F_52 (net, dev) {
if ( V_124 < V_166 || V_10 -> type != V_68 )
goto V_167;
V_165 . V_32 = V_31 ( V_10 ) ;
if ( ! V_165 . V_32 -> V_147 )
goto V_167;
V_165 . V_69 = V_69 ;
V_165 . V_125 = V_121 -> args [ 1 ] ;
V_165 . V_168 = V_121 -> args [ 2 ] ;
V_165 . V_10 = V_10 ;
V_165 . V_25 = F_53 ( V_121 -> V_69 ) . V_25 ;
V_165 . V_128 = V_121 -> V_127 -> V_128 ;
V_165 . V_32 -> V_147 -> V_169 ( V_10 ) ;
V_165 . V_32 -> V_147 -> V_170 ( V_165 . V_10 , & V_165 . V_171 ) ;
V_113 = F_67 ( & V_165 ) ;
V_165 . V_32 -> V_147 -> V_172 ( V_10 ) ;
if ( V_113 < 0 )
break;
V_167:
V_124 ++ ;
}
V_121 -> args [ 0 ] = V_124 ;
return V_69 -> V_130 ;
}
static int
F_68 ( struct V_1 * V_69 , struct V_63 * V_64 ,
int (* F_69)( struct V_9 * , struct V_63 * ) )
{
struct V_9 * V_10 = NULL ;
int V_113 = - V_79 ;
V_10 = F_34 ( V_64 ) ;
if ( ! V_10 )
return - V_80 ;
if ( ! V_31 ( V_10 ) -> V_147 )
V_113 = - V_73 ;
else
V_113 = F_69 ( V_10 , V_64 ) ;
F_39 ( V_10 ) ;
return V_113 ;
}
static int
F_70 ( struct V_63 * V_64 ,
struct V_173 * V_174 )
{
T_3 V_175 ;
T_4 V_176 [ 256 / 32 ] ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
if ( ! V_64 -> V_65 [ V_177 ] ||
! V_64 -> V_65 [ V_178 ] )
return - V_79 ;
V_175 = F_41 ( V_64 -> V_65 [ V_177 ] ) ;
if ( ( V_175 & F_71 ( V_179 ) ) &&
! V_64 -> V_65 [ V_180 ] )
return - V_79 ;
if ( V_64 -> V_65 [ V_180 ] ) {
F_72 ( V_176 ,
V_64 -> V_65 [ V_180 ] ,
256 / 8 ) ;
if ( V_176 [ 0 ] || V_176 [ 1 ] || V_176 [ 2 ] || V_176 [ 3 ] ||
V_176 [ 4 ] || V_176 [ 5 ] || V_176 [ 6 ] ||
V_176 [ 7 ] >= F_71 ( V_181 + 1 ) )
return - V_79 ;
V_174 -> V_182 = V_176 [ 7 ] ;
}
V_174 -> V_183 = V_175 ;
F_72 ( V_174 -> V_174 , V_64 -> V_65 [ V_178 ] ,
V_184 ) ;
return 0 ;
}
static int F_73 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_173 V_174 ;
struct V_132 V_142 ;
if ( F_70 ( V_64 , & V_174 ) ||
F_57 ( V_64 , & V_142 ) )
return - V_79 ;
return V_32 -> V_147 -> V_185 ( V_10 , & V_142 , & V_174 ) ;
}
int F_74 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
if ( ( V_64 -> V_186 -> V_187 & ( V_188 | V_189 ) ) !=
( V_188 | V_189 ) )
return - V_79 ;
return F_68 ( V_69 , V_64 , F_73 ) ;
}
static int F_75 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_132 V_142 ;
if ( F_57 ( V_64 , & V_142 ) )
return - V_79 ;
return V_32 -> V_147 -> V_190 ( V_10 , & V_142 ) ;
}
int F_76 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
return F_68 ( V_69 , V_64 , F_75 ) ;
}
static int
F_77 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
const struct V_191 * V_174 ,
const struct V_9 * V_10 )
{
void * V_28 ;
T_4 V_176 [ 256 / 32 ] ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_129 ,
V_192 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_59 ( V_2 , & V_174 -> V_142 ) ||
F_19 ( V_2 , V_177 ,
V_174 -> V_174 -> V_183 ) )
goto V_23;
if ( V_174 -> V_174 -> V_183 & F_71 ( V_179 ) ) {
memset ( V_176 , 0 , sizeof( V_176 ) ) ;
V_176 [ 7 ] = V_174 -> V_174 -> V_182 ;
if ( F_18 ( V_2 , V_180 ,
sizeof( V_176 ) , V_176 ) )
goto V_23;
}
if ( F_18 ( V_2 , V_178 ,
V_184 , V_174 -> V_174 -> V_174 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_62 ;
}
static int F_78 ( struct V_164 * V_165 )
{
struct V_191 * V_193 ;
int V_113 = 0 , V_124 = 0 ;
F_79 (pos, &data->table->keys, list) {
if ( V_124 ++ < V_165 -> V_125 )
continue;
if ( F_77 ( V_165 -> V_69 , V_165 -> V_25 ,
V_165 -> V_128 , V_193 , V_165 -> V_10 ) ) {
V_113 = - V_62 ;
break;
}
V_165 -> V_125 ++ ;
}
return V_113 ;
}
int F_80 ( struct V_1 * V_69 , struct V_120 * V_121 )
{
return F_66 ( V_69 , V_121 , F_78 ) ;
}
static int
F_81 ( struct V_63 * V_64 ,
struct V_194 * V_10 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( ! V_64 -> V_65 [ V_154 ] ||
! V_64 -> V_65 [ V_19 ] ||
! V_64 -> V_65 [ V_195 ] ||
! V_64 -> V_65 [ V_196 ] ||
( ! ! V_64 -> V_65 [ V_41 ] !=
! ! V_64 -> V_65 [ V_40 ] ) )
return - V_79 ;
if ( V_64 -> V_65 [ V_41 ] ) {
V_10 -> V_34 = F_10 ( V_64 -> V_65 [ V_41 ] ) ;
V_10 -> V_33 = F_10 ( V_64 -> V_65 [ V_40 ] ) ;
} else {
V_10 -> V_33 = F_11 ( V_197 ) ;
}
V_10 -> V_3 = F_4 ( V_64 -> V_65 [ V_19 ] ) ;
V_10 -> V_155 = F_38 ( V_64 -> V_65 [ V_154 ] ) ;
V_10 -> V_198 = ! ! F_41 ( V_64 -> V_65 [ V_195 ] ) ;
V_10 -> V_199 = F_41 ( V_64 -> V_65 [ V_196 ] ) ;
if ( V_10 -> V_199 >= V_200 )
return - V_79 ;
return 0 ;
}
static int F_82 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_194 V_133 ;
if ( F_81 ( V_64 , & V_133 ) )
return - V_79 ;
return V_32 -> V_147 -> V_201 ( V_10 , & V_133 ) ;
}
int F_83 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
if ( ( V_64 -> V_186 -> V_187 & ( V_188 | V_189 ) ) !=
( V_188 | V_189 ) )
return - V_79 ;
return F_68 ( V_69 , V_64 , F_82 ) ;
}
static int F_84 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
T_1 V_202 ;
if ( ! V_64 -> V_65 [ V_19 ] )
return - V_79 ;
V_202 = F_4 ( V_64 -> V_65 [ V_19 ] ) ;
return V_32 -> V_147 -> V_203 ( V_10 , V_202 ) ;
}
int F_85 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
return F_68 ( V_69 , V_64 , F_84 ) ;
}
static int
F_86 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
const struct V_194 * V_133 ,
const struct V_9 * V_10 )
{
void * V_28 ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_129 ,
V_204 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_7 ( V_2 , V_41 , V_133 -> V_34 ) ||
F_7 ( V_2 , V_40 ,
V_133 -> V_33 ) ||
F_1 ( V_2 , V_19 , V_133 -> V_3 ) ||
F_17 ( V_2 , V_154 ,
V_133 -> V_155 ) ||
F_19 ( V_2 , V_195 ,
V_133 -> V_198 ) ||
F_19 ( V_2 , V_196 , V_133 -> V_199 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_62 ;
}
static int F_87 ( struct V_164 * V_165 )
{
struct V_194 * V_193 ;
int V_113 = 0 , V_124 = 0 ;
F_79 (pos, &data->table->devices, list) {
if ( V_124 ++ < V_165 -> V_125 )
continue;
if ( F_86 ( V_165 -> V_69 , V_165 -> V_25 ,
V_165 -> V_128 , V_193 , V_165 -> V_10 ) ) {
V_113 = - V_62 ;
break;
}
V_165 -> V_125 ++ ;
}
return V_113 ;
}
int F_88 ( struct V_1 * V_69 , struct V_120 * V_121 )
{
return F_66 ( V_69 , V_121 , F_87 ) ;
}
static int F_89 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_205 V_174 ;
T_1 V_202 ;
if ( ! V_64 -> V_65 [ V_154 ] ||
! V_64 -> V_65 [ V_19 ] ||
F_57 ( V_64 , & V_174 . V_206 ) )
return - V_79 ;
V_202 = F_4 ( V_64 -> V_65 [ V_19 ] ) ;
V_174 . V_155 = F_38 ( V_64 -> V_65 [ V_154 ] ) ;
return V_32 -> V_147 -> V_207 ( V_10 , V_202 , & V_174 ) ;
}
int F_90 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
if ( ( V_64 -> V_186 -> V_187 & ( V_188 | V_189 ) ) !=
( V_188 | V_189 ) )
return - V_79 ;
return F_68 ( V_69 , V_64 , F_89 ) ;
}
static int F_91 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_205 V_174 ;
T_1 V_202 ;
if ( ! V_64 -> V_65 [ V_19 ] ||
F_57 ( V_64 , & V_174 . V_206 ) )
return - V_79 ;
V_202 = F_4 ( V_64 -> V_65 [ V_19 ] ) ;
return V_32 -> V_147 -> V_208 ( V_10 , V_202 , & V_174 ) ;
}
int F_92 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
return F_68 ( V_69 , V_64 , F_91 ) ;
}
static int
F_93 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
T_1 V_202 ,
const struct V_205 * V_209 ,
const struct V_9 * V_10 )
{
void * V_28 ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_129 ,
V_210 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_1 ( V_2 , V_19 , V_202 ) ||
F_17 ( V_2 , V_154 ,
V_209 -> V_155 ) ||
F_59 ( V_2 , & V_209 -> V_206 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_62 ;
}
static int F_94 ( struct V_164 * V_165 )
{
struct V_194 * V_211 ;
struct V_205 * V_212 ;
int V_113 = 0 , V_124 = 0 , V_213 ;
F_79 (dpos, &data->table->devices, list) {
if ( V_124 ++ < V_165 -> V_125 )
continue;
V_213 = 0 ;
F_79 (kpos, &dpos->keys, list) {
if ( V_213 ++ < V_165 -> V_168 )
continue;
if ( F_93 ( V_165 -> V_69 , V_165 -> V_25 ,
V_165 -> V_128 ,
V_211 -> V_3 , V_212 ,
V_165 -> V_10 ) ) {
return V_113 = - V_62 ;
}
V_165 -> V_168 ++ ;
}
V_165 -> V_125 ++ ;
}
return V_113 ;
}
int F_95 ( struct V_1 * V_69 ,
struct V_120 * V_121 )
{
return F_66 ( V_69 , V_121 , F_94 ) ;
}
static int
F_96 ( struct V_63 * V_64 ,
struct V_214 * V_215 )
{
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
if ( ! V_64 -> V_65 [ V_216 ] ||
! V_64 -> V_65 [ V_217 ] ||
! V_64 -> V_65 [ V_195 ] )
return - V_79 ;
V_215 -> V_218 = F_41 ( V_64 -> V_65 [ V_216 ] ) ;
if ( V_215 -> V_218 == V_179 ) {
if ( ! V_64 -> V_65 [ V_219 ] )
return - V_79 ;
V_215 -> V_220 = F_41 ( V_64 -> V_65 [ V_219 ] ) ;
}
V_215 -> V_221 = F_41 ( V_64 -> V_65 [ V_217 ] ) ;
V_215 -> V_222 = F_41 ( V_64 -> V_65 [ V_195 ] ) ;
return 0 ;
}
static int F_97 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_214 V_215 ;
if ( F_96 ( V_64 , & V_215 ) )
return - V_79 ;
return V_32 -> V_147 -> V_223 ( V_10 , & V_215 ) ;
}
int F_98 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
if ( ( V_64 -> V_186 -> V_187 & ( V_188 | V_189 ) ) !=
( V_188 | V_189 ) )
return - V_79 ;
return F_68 ( V_69 , V_64 , F_97 ) ;
}
static int F_99 ( struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_31 * V_32 = V_31 ( V_10 ) ;
struct V_214 V_215 ;
if ( F_96 ( V_64 , & V_215 ) )
return - V_79 ;
return V_32 -> V_147 -> V_224 ( V_10 , & V_215 ) ;
}
int F_100 ( struct V_1 * V_69 , struct V_63 * V_64 )
{
return F_68 ( V_69 , V_64 , F_99 ) ;
}
static int
F_101 ( struct V_1 * V_2 , T_4 V_25 , T_4 V_26 ,
const struct V_214 * V_215 ,
const struct V_9 * V_10 )
{
void * V_28 ;
V_28 = F_23 ( V_2 , 0 , V_26 , & V_35 , V_129 ,
V_225 ) ;
if ( ! V_28 )
goto V_37;
if ( F_16 ( V_2 , V_15 , V_10 -> V_16 ) ||
F_17 ( V_2 , V_17 , V_10 -> V_18 ) ||
F_19 ( V_2 , V_216 , V_215 -> V_218 ) ||
F_19 ( V_2 , V_217 , V_215 -> V_221 ) ||
F_19 ( V_2 , V_195 ,
V_215 -> V_222 ) )
goto V_23;
if ( V_215 -> V_218 == V_179 &&
F_19 ( V_2 , V_219 ,
V_215 -> V_220 ) )
goto V_23;
F_32 ( V_2 , V_28 ) ;
return 0 ;
V_23:
F_33 ( V_2 , V_28 ) ;
V_37:
return - V_62 ;
}
static int F_102 ( struct V_164 * V_165 )
{
struct V_214 * V_193 ;
int V_113 = 0 , V_124 = 0 ;
F_79 (pos, &data->table->security_levels, list) {
if ( V_124 ++ < V_165 -> V_125 )
continue;
if ( F_101 ( V_165 -> V_69 , V_165 -> V_25 ,
V_165 -> V_128 , V_193 ,
V_165 -> V_10 ) ) {
V_113 = - V_62 ;
break;
}
V_165 -> V_125 ++ ;
}
return V_113 ;
}
int F_103 ( struct V_1 * V_69 ,
struct V_120 * V_121 )
{
return F_66 ( V_69 , V_121 , F_102 ) ;
}
