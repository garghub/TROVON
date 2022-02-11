static int F_1 ( struct V_1 * V_2 , int type , T_1 V_3 ,
int V_4 )
{
return F_2 ( V_2 , type , F_3 ( ( V_5 V_6 ) V_3 ) ,
V_4 ) ;
}
static T_1 F_4 ( const struct V_7 * V_8 )
{
return F_5 ( F_6 ( V_8 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , int type , T_2 V_9 )
{
return F_8 ( V_2 , type , F_9 ( V_9 ) ) ;
}
static T_2 F_10 ( const struct V_7 * V_8 )
{
return F_11 ( F_12 ( V_8 ) ) ;
}
static int F_13 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_15 ( 0 , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_18 ( V_2 , V_20 , V_21 ,
V_11 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_12 ) )
goto V_24;
return F_20 ( V_2 , V_25 ) ;
V_24:
F_21 ( V_2 ) ;
return - V_15 ;
}
static int F_22 ( struct V_1 * V_2 , T_4 V_26 ,
T_4 V_27 , int V_28 , struct V_10 * V_11 )
{
void * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_2 V_34 , V_35 ;
F_14 ( L_1 , V_13 ) ;
V_29 = F_23 ( V_2 , 0 , V_27 , & V_36 , V_28 ,
V_37 ) ;
if ( ! V_29 )
goto V_38;
V_33 = V_32 ( V_11 ) ;
V_31 = V_11 -> V_39 -> V_30 ;
F_24 ( ! V_31 ) ;
F_25 ( & V_31 -> V_11 ) ;
F_26 () ;
V_34 = V_11 -> V_39 -> V_34 ;
V_35 = V_11 -> V_39 -> V_35 ;
F_27 () ;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_16 ( V_2 , V_40 , F_28 ( V_31 ) ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_18 ( V_2 , V_20 , V_21 ,
V_11 -> V_22 ) ||
F_7 ( V_2 , V_41 , V_34 ) ||
F_7 ( V_2 , V_42 , V_35 ) )
goto V_24;
if ( V_33 -> V_43 ) {
struct V_44 V_45 ;
F_26 () ;
V_33 -> V_43 ( V_11 , & V_45 ) ;
F_27 () ;
if ( F_29 ( V_2 , V_46 ,
V_45 . V_47 / 100 ) ||
F_19 ( V_2 , V_48 , V_45 . V_49 ) ||
F_19 ( V_2 , V_50 ,
V_45 . V_51 . V_52 ) ||
F_30 ( V_2 , V_53 ,
V_45 . V_54 / 100 ) ||
F_19 ( V_2 , V_55 ,
V_45 . V_56 ) ||
F_19 ( V_2 , V_57 ,
V_45 . V_58 ) ||
F_19 ( V_2 , V_59 ,
V_45 . V_60 ) ||
F_29 ( V_2 , V_61 ,
V_45 . V_62 ) )
goto V_24;
}
F_31 ( V_31 ) ;
F_32 ( V_2 , V_29 ) ;
return 0 ;
V_24:
F_31 ( V_31 ) ;
F_33 ( V_2 , V_29 ) ;
V_38:
return - V_63 ;
}
static struct V_10 * F_34 ( struct V_64 * V_65 )
{
struct V_10 * V_11 ;
if ( V_65 -> V_66 [ V_16 ] ) {
char V_17 [ V_67 + 1 ] ;
F_35 ( V_17 , V_65 -> V_66 [ V_16 ] ,
sizeof( V_17 ) ) ;
V_11 = F_36 ( & V_68 , V_17 ) ;
} else if ( V_65 -> V_66 [ V_18 ] ) {
V_11 = F_37 ( & V_68 ,
F_38 ( V_65 -> V_66 [ V_18 ] ) ) ;
} else {
return NULL ;
}
if ( ! V_11 )
return NULL ;
if ( V_11 -> type != V_69 ) {
F_39 ( V_11 ) ;
return NULL ;
}
return V_11 ;
}
int F_40 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 ;
struct V_71 V_9 ;
T_3 V_72 ;
int V_73 = - V_74 ;
if ( ! V_65 -> V_66 [ V_75 ] ||
! V_65 -> V_66 [ V_76 ] ||
( ! V_65 -> V_66 [ V_77 ] &&
! V_65 -> V_66 [ V_78 ] ) ||
! V_65 -> V_66 [ V_79 ] )
return - V_80 ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_32 ( V_11 ) -> V_82 )
goto V_38;
if ( V_65 -> V_66 [ V_77 ] ) {
V_9 . V_52 = V_83 ;
V_9 . V_84 = F_4 (
V_65 -> V_66 [ V_77 ] ) ;
} else {
V_9 . V_52 = V_85 ;
V_9 . V_34 = F_10 (
V_65 -> V_66 [ V_78 ] ) ;
}
V_9 . V_35 = F_10 (
V_65 -> V_66 [ V_76 ] ) ;
if ( V_65 -> V_66 [ V_86 ] )
V_72 = F_41 ( V_65 -> V_66 [ V_86 ] ) ;
else
V_72 = 0 ;
V_73 = V_32 ( V_11 ) -> V_82 ( V_11 , & V_9 ,
F_41 ( V_65 -> V_66 [ V_75 ] ) ,
V_72 ,
F_41 ( V_65 -> V_66 [ V_79 ] ) ) ;
V_38:
F_39 ( V_11 ) ;
return V_73 ;
}
int F_42 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 ;
struct V_71 V_9 ;
int V_73 = - V_74 ;
if ( ! V_65 -> V_66 [ V_23 ] ||
! V_65 -> V_66 [ V_87 ] ||
! V_65 -> V_66 [ V_88 ] )
return - V_80 ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_32 ( V_11 ) -> V_89 )
goto V_38;
V_9 . V_52 = V_83 ;
V_9 . V_84 = F_4 (
V_65 -> V_66 [ V_87 ] ) ;
F_26 () ;
V_9 . V_35 = V_11 -> V_39 -> V_35 ;
F_27 () ;
V_73 = V_32 ( V_11 ) -> V_89 ( V_11 , & V_9 ,
F_10 ( V_65 -> V_66 [ V_88 ] ) ,
F_41 ( V_65 -> V_66 [ V_23 ] ) ) ;
V_38:
F_39 ( V_11 ) ;
return V_73 ;
}
int F_43 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 ;
struct V_71 V_9 ;
int V_73 = - V_74 ;
if ( ( ! V_65 -> V_66 [ V_87 ] &&
! V_65 -> V_66 [ V_88 ] ) ||
! V_65 -> V_66 [ V_90 ] )
return - V_80 ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_32 ( V_11 ) -> V_91 )
goto V_38;
if ( V_65 -> V_66 [ V_87 ] ) {
V_9 . V_52 = V_83 ;
V_9 . V_84 = F_4 (
V_65 -> V_66 [ V_87 ] ) ;
} else {
V_9 . V_52 = V_85 ;
V_9 . V_34 = F_10 (
V_65 -> V_66 [ V_88 ] ) ;
}
F_26 () ;
V_9 . V_35 = V_11 -> V_39 -> V_35 ;
F_27 () ;
V_73 = V_32 ( V_11 ) -> V_91 ( V_11 , & V_9 ,
F_41 ( V_65 -> V_66 [ V_90 ] ) ) ;
V_38:
F_39 ( V_11 ) ;
return V_73 ;
}
int F_44 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 ;
struct V_71 V_9 ;
T_3 V_92 , V_93 , V_94 ;
T_3 V_72 ;
int V_95 , V_96 , V_97 ;
int V_73 = - V_98 ;
if ( ! V_65 -> V_66 [ V_76 ] ||
! V_65 -> V_66 [ V_78 ] ||
! V_65 -> V_66 [ V_75 ] ||
! V_65 -> V_66 [ V_99 ] ||
! V_65 -> V_66 [ V_100 ] ||
! V_65 -> V_66 [ V_101 ] ||
! V_65 -> V_66 [ V_102 ] ||
! V_65 -> V_66 [ V_103 ]
)
return - V_80 ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( F_45 ( V_11 ) )
goto V_38;
if ( ! V_32 ( V_11 ) -> V_104 ) {
V_73 = - V_74 ;
goto V_38;
}
V_9 . V_52 = V_85 ;
V_9 . V_34 = F_10 (
V_65 -> V_66 [ V_78 ] ) ;
V_9 . V_35 = F_10 (
V_65 -> V_66 [ V_76 ] ) ;
V_92 = F_41 ( V_65 -> V_66 [ V_75 ] ) ;
V_93 = F_41 ( V_65 -> V_66 [ V_99 ] ) ;
V_94 = F_41 ( V_65 -> V_66 [ V_100 ] ) ;
V_95 = F_41 ( V_65 -> V_66 [ V_101 ] ) ;
V_96 = F_41 ( V_65 -> V_66 [ V_102 ] ) ;
V_97 = F_41 ( V_65 -> V_66 [ V_103 ] ) ;
if ( V_65 -> V_66 [ V_86 ] )
V_72 = F_41 ( V_65 -> V_66 [ V_86 ] ) ;
else
V_72 = 0 ;
if ( V_9 . V_34 == F_11 ( V_105 ) ) {
F_13 ( V_11 , V_106 ) ;
F_39 ( V_11 ) ;
return - V_80 ;
}
F_26 () ;
V_73 = V_32 ( V_11 ) -> V_104 ( V_11 , & V_9 , V_92 , V_72 ,
V_93 , V_94 , V_95 , V_96 , V_97 ) ;
F_27 () ;
F_13 ( V_11 , V_107 ) ;
V_38:
F_39 ( V_11 ) ;
return V_73 ;
}
int F_46 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 ;
int V_73 = - V_74 ;
T_3 type ;
T_4 V_108 ;
T_3 V_109 ;
T_3 V_72 ;
if ( ! V_65 -> V_66 [ V_110 ] ||
! V_65 -> V_66 [ V_111 ] ||
! V_65 -> V_66 [ V_112 ] )
return - V_80 ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_32 ( V_11 ) -> V_113 )
goto V_38;
type = F_41 ( V_65 -> V_66 [ V_110 ] ) ;
V_108 = F_38 ( V_65 -> V_66 [ V_111 ] ) ;
V_109 = F_41 ( V_65 -> V_66 [ V_112 ] ) ;
if ( V_65 -> V_66 [ V_86 ] )
V_72 = F_41 ( V_65 -> V_66 [ V_86 ] ) ;
else
V_72 = 0 ;
V_73 = V_32 ( V_11 ) -> V_113 ( V_11 , type , V_108 ,
V_72 , V_109 ) ;
V_38:
F_39 ( V_11 ) ;
return V_73 ;
}
int F_47 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = NULL ;
int V_114 = - V_15 ;
F_14 ( L_1 , V_13 ) ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
V_2 = F_48 ( V_115 , V_116 ) ;
if ( ! V_2 )
goto V_117;
V_114 = F_22 ( V_2 , V_65 -> V_118 , V_65 -> V_119 ,
0 , V_11 ) ;
if ( V_114 < 0 )
goto V_120;
F_39 ( V_11 ) ;
return F_49 ( V_2 , V_65 ) ;
V_120:
F_21 ( V_2 ) ;
V_117:
F_39 ( V_11 ) ;
return V_114 ;
}
int F_50 ( struct V_1 * V_70 , struct V_121 * V_122 )
{
struct V_123 * V_123 = F_51 ( V_70 -> V_124 ) ;
struct V_10 * V_11 ;
int V_125 ;
int V_126 = V_122 -> args [ 0 ] ;
F_14 ( L_1 , V_13 ) ;
V_125 = 0 ;
F_52 (net, dev) {
if ( V_125 < V_126 || V_11 -> type != V_69 )
goto V_127;
if ( F_22 ( V_70 , F_53 ( V_122 -> V_70 ) . V_26 ,
V_122 -> V_128 -> V_129 ,
V_130 , V_11 ) < 0 )
break;
V_127:
V_125 ++ ;
}
V_122 -> args [ 0 ] = V_125 ;
return V_70 -> V_131 ;
}
int F_54 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 = NULL ;
struct V_32 * V_33 ;
struct V_44 V_45 ;
struct V_30 * V_31 ;
int V_114 = - V_80 ;
F_14 ( L_1 , V_13 ) ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
V_33 = V_32 ( V_11 ) ;
if ( ! V_33 -> V_43 || ! V_33 -> V_132 ) {
V_114 = - V_74 ;
goto V_38;
}
if ( F_45 ( V_11 ) ) {
V_114 = - V_98 ;
goto V_38;
}
if ( ! V_65 -> V_66 [ V_48 ] &&
! V_65 -> V_66 [ V_50 ] &&
! V_65 -> V_66 [ V_53 ] &&
! V_65 -> V_66 [ V_55 ] &&
! V_65 -> V_66 [ V_57 ] &&
! V_65 -> V_66 [ V_59 ] &&
! V_65 -> V_66 [ V_61 ] )
goto V_38;
V_31 = V_11 -> V_39 -> V_30 ;
F_25 ( & V_31 -> V_11 ) ;
F_26 () ;
V_33 -> V_43 ( V_11 , & V_45 ) ;
if ( V_65 -> V_66 [ V_46 ] )
V_45 . V_47 = F_55 ( V_65 -> V_66 [ V_46 ] ) * 100 ;
if ( V_65 -> V_66 [ V_48 ] )
V_45 . V_49 = F_41 ( V_65 -> V_66 [ V_48 ] ) ;
if ( V_65 -> V_66 [ V_50 ] )
V_45 . V_51 . V_52 = F_41 ( V_65 -> V_66 [ V_50 ] ) ;
if ( V_65 -> V_66 [ V_53 ] )
V_45 . V_54 = F_56 ( V_65 -> V_66 [ V_53 ] ) * 100 ;
if ( V_65 -> V_66 [ V_55 ] )
V_45 . V_56 = F_41 ( V_65 -> V_66 [ V_55 ] ) ;
if ( V_65 -> V_66 [ V_57 ] )
V_45 . V_58 = F_41 ( V_65 -> V_66 [ V_57 ] ) ;
if ( V_65 -> V_66 [ V_59 ] )
V_45 . V_60 = F_41 ( V_65 -> V_66 [ V_59 ] ) ;
if ( V_65 -> V_66 [ V_61 ] )
V_45 . V_62 = F_55 ( V_65 -> V_66 [ V_61 ] ) ;
V_114 = V_33 -> V_132 ( V_11 , & V_45 ) ;
F_27 () ;
F_31 ( V_31 ) ;
F_39 ( V_11 ) ;
return 0 ;
V_38:
F_39 ( V_11 ) ;
return V_114 ;
}
static int
F_57 ( struct V_64 * V_65 ,
struct V_133 * V_134 )
{
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
if ( ! V_65 -> V_66 [ V_135 ] )
return - V_80 ;
V_134 -> V_52 = F_41 ( V_65 -> V_66 [ V_135 ] ) ;
if ( V_134 -> V_52 == V_136 ) {
if ( ! V_65 -> V_66 [ V_42 ] &&
! ( V_65 -> V_66 [ V_41 ] ||
V_65 -> V_66 [ V_20 ] ) )
return - V_80 ;
V_134 -> V_137 . V_35 = F_10 ( V_65 -> V_66 [ V_42 ] ) ;
if ( V_65 -> V_66 [ V_41 ] ) {
V_134 -> V_137 . V_52 = V_85 ;
V_134 -> V_137 . V_34 = F_10 ( V_65 -> V_66 [ V_41 ] ) ;
} else {
V_134 -> V_137 . V_52 = V_83 ;
V_134 -> V_137 . V_84 = F_4 ( V_65 -> V_66 [ V_20 ] ) ;
}
}
if ( V_134 -> V_52 != V_136 &&
! V_65 -> V_66 [ V_138 ] )
return - V_80 ;
if ( V_134 -> V_52 == V_139 &&
! V_65 -> V_66 [ V_140 ] )
return - V_80 ;
if ( V_134 -> V_52 == V_141 &&
! V_65 -> V_66 [ V_142 ] )
return - V_80 ;
if ( V_134 -> V_52 != V_136 )
V_134 -> V_143 = F_41 ( V_65 -> V_66 [ V_138 ] ) ;
switch ( V_134 -> V_52 ) {
case V_139 :
{
T_4 V_144 = F_38 ( V_65 -> V_66 [ V_140 ] ) ;
V_134 -> V_145 = F_58 ( V_144 ) ;
break;
}
case V_141 :
V_134 -> V_146 = F_4 ( V_65 -> V_66 [ V_142 ] ) ;
break;
}
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 ,
const struct V_133 * V_134 )
{
if ( F_19 ( V_2 , V_135 , V_134 -> V_52 ) )
return - V_63 ;
if ( V_134 -> V_52 == V_136 ) {
if ( F_7 ( V_2 , V_42 ,
V_134 -> V_137 . V_35 ) )
return - V_63 ;
if ( V_134 -> V_137 . V_52 == V_85 &&
F_7 ( V_2 , V_41 ,
V_134 -> V_137 . V_34 ) )
return - V_63 ;
if ( V_134 -> V_137 . V_52 == V_83 &&
F_1 ( V_2 , V_20 ,
V_134 -> V_137 . V_84 ,
V_147 ) )
return - V_63 ;
}
if ( V_134 -> V_52 != V_136 &&
F_19 ( V_2 , V_138 , V_134 -> V_143 ) )
return - V_63 ;
if ( V_134 -> V_52 == V_139 &&
F_17 ( V_2 , V_140 ,
F_60 ( V_134 -> V_145 ) ) )
return - V_63 ;
if ( V_134 -> V_52 == V_141 &&
F_1 ( V_2 , V_142 ,
V_134 -> V_146 , V_147 ) )
return - V_63 ;
return 0 ;
}
int F_61 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = NULL ;
int V_114 = - V_15 ;
struct V_32 * V_33 ;
void * V_29 ;
struct V_148 V_45 ;
F_14 ( L_1 , V_13 ) ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
V_33 = V_32 ( V_11 ) ;
if ( ! V_33 -> V_149 ) {
V_114 = - V_74 ;
goto V_117;
}
V_2 = F_48 ( V_115 , V_116 ) ;
if ( ! V_2 )
goto V_117;
V_29 = F_23 ( V_2 , 0 , V_65 -> V_119 , & V_36 , 0 ,
V_150 ) ;
if ( ! V_29 )
goto V_120;
V_114 = V_33 -> V_149 -> V_151 ( V_11 , & V_45 ) ;
if ( V_114 < 0 )
goto V_120;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_19 ( V_2 , V_152 , V_45 . V_153 ) ||
F_19 ( V_2 , V_154 , V_45 . V_155 ) ||
F_17 ( V_2 , V_156 ,
F_62 ( V_45 . V_157 ) ) ||
F_59 ( V_2 , & V_45 . V_158 ) )
goto V_120;
F_39 ( V_11 ) ;
return F_63 ( V_2 , V_65 ) ;
V_120:
F_21 ( V_2 ) ;
V_117:
F_39 ( V_11 ) ;
return V_114 ;
}
int F_64 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
struct V_10 * V_11 = NULL ;
int V_114 = - V_80 ;
struct V_32 * V_33 ;
struct V_148 V_45 ;
int V_159 = 0 ;
F_14 ( L_1 , V_13 ) ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_65 -> V_66 [ V_152 ] &&
! V_65 -> V_66 [ V_135 ] &&
! V_65 -> V_66 [ V_154 ] )
goto V_38;
V_33 = V_32 ( V_11 ) ;
if ( ! V_33 -> V_149 ) {
V_114 = - V_74 ;
goto V_38;
}
if ( V_65 -> V_66 [ V_154 ] &&
F_41 ( V_65 -> V_66 [ V_154 ] ) > 7 )
goto V_38;
if ( V_65 -> V_66 [ V_152 ] ) {
V_45 . V_153 = F_41 ( V_65 -> V_66 [ V_152 ] ) ;
V_159 |= V_160 ;
}
if ( V_65 -> V_66 [ V_135 ] ) {
if ( F_57 ( V_65 , & V_45 . V_158 ) )
goto V_38;
V_159 |= V_161 ;
}
if ( V_65 -> V_66 [ V_154 ] ) {
V_45 . V_155 = F_41 ( V_65 -> V_66 [ V_154 ] ) ;
V_159 |= V_162 ;
}
if ( V_65 -> V_66 [ V_156 ] ) {
T_4 V_163 = F_38 ( V_65 -> V_66 [ V_156 ] ) ;
V_45 . V_157 = F_65 ( V_163 ) ;
V_159 |= V_164 ;
}
V_114 = V_33 -> V_149 -> V_165 ( V_11 , & V_45 , V_159 ) ;
F_39 ( V_11 ) ;
return V_114 ;
V_38:
F_39 ( V_11 ) ;
return V_114 ;
}
static int
F_66 ( struct V_1 * V_70 , struct V_121 * V_122 ,
int (* F_67)( struct V_166 * ) )
{
struct V_123 * V_123 = F_51 ( V_70 -> V_124 ) ;
struct V_10 * V_11 ;
struct V_166 V_167 ;
int V_125 = 0 ;
int V_168 = V_122 -> args [ 0 ] ;
int V_114 ;
F_52 (net, dev) {
if ( V_125 < V_168 || V_11 -> type != V_69 )
goto V_169;
V_167 . V_33 = V_32 ( V_11 ) ;
if ( ! V_167 . V_33 -> V_149 )
goto V_169;
V_167 . V_70 = V_70 ;
V_167 . V_126 = V_122 -> args [ 1 ] ;
V_167 . V_170 = V_122 -> args [ 2 ] ;
V_167 . V_11 = V_11 ;
V_167 . V_26 = F_53 ( V_122 -> V_70 ) . V_26 ;
V_167 . V_129 = V_122 -> V_128 -> V_129 ;
V_167 . V_33 -> V_149 -> V_171 ( V_11 ) ;
V_167 . V_33 -> V_149 -> V_172 ( V_167 . V_11 , & V_167 . V_173 ) ;
V_114 = F_67 ( & V_167 ) ;
V_167 . V_33 -> V_149 -> V_174 ( V_11 ) ;
if ( V_114 < 0 )
break;
V_169:
V_125 ++ ;
}
V_122 -> args [ 0 ] = V_125 ;
return V_70 -> V_131 ;
}
static int
F_68 ( struct V_1 * V_70 , struct V_64 * V_65 ,
int (* F_69)( struct V_10 * , struct V_64 * ) )
{
struct V_10 * V_11 = NULL ;
int V_114 = - V_80 ;
V_11 = F_34 ( V_65 ) ;
if ( ! V_11 )
return - V_81 ;
if ( ! V_32 ( V_11 ) -> V_149 )
V_114 = - V_74 ;
else
V_114 = F_69 ( V_11 , V_65 ) ;
F_39 ( V_11 ) ;
return V_114 ;
}
static int
F_70 ( struct V_64 * V_65 ,
struct V_175 * V_176 )
{
T_3 V_177 ;
T_4 V_178 [ 256 / 32 ] ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
if ( ! V_65 -> V_66 [ V_179 ] ||
! V_65 -> V_66 [ V_180 ] )
return - V_80 ;
V_177 = F_41 ( V_65 -> V_66 [ V_179 ] ) ;
if ( ( V_177 & F_71 ( V_181 ) ) &&
! V_65 -> V_66 [ V_182 ] )
return - V_80 ;
if ( V_65 -> V_66 [ V_182 ] ) {
F_72 ( V_178 ,
V_65 -> V_66 [ V_182 ] ,
256 / 8 ) ;
if ( V_178 [ 0 ] || V_178 [ 1 ] || V_178 [ 2 ] || V_178 [ 3 ] ||
V_178 [ 4 ] || V_178 [ 5 ] || V_178 [ 6 ] ||
V_178 [ 7 ] >= F_71 ( V_183 + 1 ) )
return - V_80 ;
V_176 -> V_184 = V_178 [ 7 ] ;
}
V_176 -> V_185 = V_177 ;
F_72 ( V_176 -> V_176 , V_65 -> V_66 [ V_180 ] ,
V_186 ) ;
return 0 ;
}
static int F_73 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_175 V_176 ;
struct V_133 V_143 ;
if ( F_70 ( V_65 , & V_176 ) ||
F_57 ( V_65 , & V_143 ) )
return - V_80 ;
return V_33 -> V_149 -> V_187 ( V_11 , & V_143 , & V_176 ) ;
}
int F_74 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_188 -> V_189 & ( V_190 | V_191 ) ) !=
( V_190 | V_191 ) )
return - V_80 ;
return F_68 ( V_70 , V_65 , F_73 ) ;
}
static int F_75 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_133 V_143 ;
if ( F_57 ( V_65 , & V_143 ) )
return - V_80 ;
return V_33 -> V_149 -> V_192 ( V_11 , & V_143 ) ;
}
int F_76 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
return F_68 ( V_70 , V_65 , F_75 ) ;
}
static int
F_77 ( struct V_1 * V_2 , T_4 V_26 , T_4 V_27 ,
const struct V_193 * V_176 ,
const struct V_10 * V_11 )
{
void * V_29 ;
T_4 V_178 [ 256 / 32 ] ;
V_29 = F_23 ( V_2 , 0 , V_27 , & V_36 , V_130 ,
V_194 ) ;
if ( ! V_29 )
goto V_38;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_59 ( V_2 , & V_176 -> V_143 ) ||
F_19 ( V_2 , V_179 ,
V_176 -> V_176 -> V_185 ) )
goto V_24;
if ( V_176 -> V_176 -> V_185 & F_71 ( V_181 ) ) {
memset ( V_178 , 0 , sizeof( V_178 ) ) ;
V_178 [ 7 ] = V_176 -> V_176 -> V_184 ;
if ( F_18 ( V_2 , V_182 ,
sizeof( V_178 ) , V_178 ) )
goto V_24;
}
if ( F_18 ( V_2 , V_180 ,
V_186 , V_176 -> V_176 -> V_176 ) )
goto V_24;
F_32 ( V_2 , V_29 ) ;
return 0 ;
V_24:
F_33 ( V_2 , V_29 ) ;
V_38:
return - V_63 ;
}
static int F_78 ( struct V_166 * V_167 )
{
struct V_193 * V_195 ;
int V_114 = 0 , V_125 = 0 ;
F_79 (pos, &data->table->keys, list) {
if ( V_125 ++ < V_167 -> V_126 )
continue;
if ( F_77 ( V_167 -> V_70 , V_167 -> V_26 ,
V_167 -> V_129 , V_195 , V_167 -> V_11 ) ) {
V_114 = - V_63 ;
break;
}
V_167 -> V_126 ++ ;
}
return V_114 ;
}
int F_80 ( struct V_1 * V_70 , struct V_121 * V_122 )
{
return F_66 ( V_70 , V_122 , F_78 ) ;
}
static int
F_81 ( struct V_64 * V_65 ,
struct V_196 * V_11 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
if ( ! V_65 -> V_66 [ V_156 ] ||
! V_65 -> V_66 [ V_20 ] ||
! V_65 -> V_66 [ V_197 ] ||
! V_65 -> V_66 [ V_198 ] ||
( ! ! V_65 -> V_66 [ V_42 ] !=
! ! V_65 -> V_66 [ V_41 ] ) )
return - V_80 ;
if ( V_65 -> V_66 [ V_42 ] ) {
V_11 -> V_35 = F_10 ( V_65 -> V_66 [ V_42 ] ) ;
V_11 -> V_34 = F_10 ( V_65 -> V_66 [ V_41 ] ) ;
} else {
V_11 -> V_34 = F_11 ( V_199 ) ;
}
V_11 -> V_3 = F_4 ( V_65 -> V_66 [ V_20 ] ) ;
V_11 -> V_157 = F_38 ( V_65 -> V_66 [ V_156 ] ) ;
V_11 -> V_200 = ! ! F_41 ( V_65 -> V_66 [ V_197 ] ) ;
V_11 -> V_201 = F_41 ( V_65 -> V_66 [ V_198 ] ) ;
if ( V_11 -> V_201 >= V_202 )
return - V_80 ;
return 0 ;
}
static int F_82 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_196 V_134 ;
if ( F_81 ( V_65 , & V_134 ) )
return - V_80 ;
return V_33 -> V_149 -> V_203 ( V_11 , & V_134 ) ;
}
int F_83 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_188 -> V_189 & ( V_190 | V_191 ) ) !=
( V_190 | V_191 ) )
return - V_80 ;
return F_68 ( V_70 , V_65 , F_82 ) ;
}
static int F_84 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
T_1 V_204 ;
if ( ! V_65 -> V_66 [ V_20 ] )
return - V_80 ;
V_204 = F_4 ( V_65 -> V_66 [ V_20 ] ) ;
return V_33 -> V_149 -> V_205 ( V_11 , V_204 ) ;
}
int F_85 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
return F_68 ( V_70 , V_65 , F_84 ) ;
}
static int
F_86 ( struct V_1 * V_2 , T_4 V_26 , T_4 V_27 ,
const struct V_196 * V_134 ,
const struct V_10 * V_11 )
{
void * V_29 ;
V_29 = F_23 ( V_2 , 0 , V_27 , & V_36 , V_130 ,
V_206 ) ;
if ( ! V_29 )
goto V_38;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_7 ( V_2 , V_42 , V_134 -> V_35 ) ||
F_7 ( V_2 , V_41 ,
V_134 -> V_34 ) ||
F_1 ( V_2 , V_20 , V_134 -> V_3 ,
V_147 ) ||
F_17 ( V_2 , V_156 ,
V_134 -> V_157 ) ||
F_19 ( V_2 , V_197 ,
V_134 -> V_200 ) ||
F_19 ( V_2 , V_198 , V_134 -> V_201 ) )
goto V_24;
F_32 ( V_2 , V_29 ) ;
return 0 ;
V_24:
F_33 ( V_2 , V_29 ) ;
V_38:
return - V_63 ;
}
static int F_87 ( struct V_166 * V_167 )
{
struct V_196 * V_195 ;
int V_114 = 0 , V_125 = 0 ;
F_79 (pos, &data->table->devices, list) {
if ( V_125 ++ < V_167 -> V_126 )
continue;
if ( F_86 ( V_167 -> V_70 , V_167 -> V_26 ,
V_167 -> V_129 , V_195 , V_167 -> V_11 ) ) {
V_114 = - V_63 ;
break;
}
V_167 -> V_126 ++ ;
}
return V_114 ;
}
int F_88 ( struct V_1 * V_70 , struct V_121 * V_122 )
{
return F_66 ( V_70 , V_122 , F_87 ) ;
}
static int F_89 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_207 V_176 ;
T_1 V_204 ;
if ( ! V_65 -> V_66 [ V_156 ] ||
! V_65 -> V_66 [ V_20 ] ||
F_57 ( V_65 , & V_176 . V_208 ) )
return - V_80 ;
V_204 = F_4 ( V_65 -> V_66 [ V_20 ] ) ;
V_176 . V_157 = F_38 ( V_65 -> V_66 [ V_156 ] ) ;
return V_33 -> V_149 -> V_209 ( V_11 , V_204 , & V_176 ) ;
}
int F_90 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_188 -> V_189 & ( V_190 | V_191 ) ) !=
( V_190 | V_191 ) )
return - V_80 ;
return F_68 ( V_70 , V_65 , F_89 ) ;
}
static int F_91 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_207 V_176 ;
T_1 V_204 ;
if ( ! V_65 -> V_66 [ V_20 ] ||
F_57 ( V_65 , & V_176 . V_208 ) )
return - V_80 ;
V_204 = F_4 ( V_65 -> V_66 [ V_20 ] ) ;
return V_33 -> V_149 -> V_210 ( V_11 , V_204 , & V_176 ) ;
}
int F_92 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
return F_68 ( V_70 , V_65 , F_91 ) ;
}
static int
F_93 ( struct V_1 * V_2 , T_4 V_26 , T_4 V_27 ,
T_1 V_204 ,
const struct V_207 * V_211 ,
const struct V_10 * V_11 )
{
void * V_29 ;
V_29 = F_23 ( V_2 , 0 , V_27 , & V_36 , V_130 ,
V_212 ) ;
if ( ! V_29 )
goto V_38;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_1 ( V_2 , V_20 , V_204 ,
V_147 ) ||
F_17 ( V_2 , V_156 ,
V_211 -> V_157 ) ||
F_59 ( V_2 , & V_211 -> V_208 ) )
goto V_24;
F_32 ( V_2 , V_29 ) ;
return 0 ;
V_24:
F_33 ( V_2 , V_29 ) ;
V_38:
return - V_63 ;
}
static int F_94 ( struct V_166 * V_167 )
{
struct V_196 * V_213 ;
struct V_207 * V_214 ;
int V_114 = 0 , V_125 = 0 , V_215 ;
F_79 (dpos, &data->table->devices, list) {
if ( V_125 ++ < V_167 -> V_126 )
continue;
V_215 = 0 ;
F_79 (kpos, &dpos->keys, list) {
if ( V_215 ++ < V_167 -> V_170 )
continue;
if ( F_93 ( V_167 -> V_70 , V_167 -> V_26 ,
V_167 -> V_129 ,
V_213 -> V_3 , V_214 ,
V_167 -> V_11 ) ) {
return V_114 = - V_63 ;
}
V_167 -> V_170 ++ ;
}
V_167 -> V_126 ++ ;
}
return V_114 ;
}
int F_95 ( struct V_1 * V_70 ,
struct V_121 * V_122 )
{
return F_66 ( V_70 , V_122 , F_94 ) ;
}
static int
F_96 ( struct V_64 * V_65 ,
struct V_216 * V_217 )
{
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
if ( ! V_65 -> V_66 [ V_218 ] ||
! V_65 -> V_66 [ V_219 ] ||
! V_65 -> V_66 [ V_197 ] )
return - V_80 ;
V_217 -> V_220 = F_41 ( V_65 -> V_66 [ V_218 ] ) ;
if ( V_217 -> V_220 == V_181 ) {
if ( ! V_65 -> V_66 [ V_221 ] )
return - V_80 ;
V_217 -> V_222 = F_41 ( V_65 -> V_66 [ V_221 ] ) ;
}
V_217 -> V_223 = F_41 ( V_65 -> V_66 [ V_219 ] ) ;
V_217 -> V_224 = F_41 ( V_65 -> V_66 [ V_197 ] ) ;
return 0 ;
}
static int F_97 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_216 V_217 ;
if ( F_96 ( V_65 , & V_217 ) )
return - V_80 ;
return V_33 -> V_149 -> V_225 ( V_11 , & V_217 ) ;
}
int F_98 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
if ( ( V_65 -> V_188 -> V_189 & ( V_190 | V_191 ) ) !=
( V_190 | V_191 ) )
return - V_80 ;
return F_68 ( V_70 , V_65 , F_97 ) ;
}
static int F_99 ( struct V_10 * V_11 , struct V_64 * V_65 )
{
struct V_32 * V_33 = V_32 ( V_11 ) ;
struct V_216 V_217 ;
if ( F_96 ( V_65 , & V_217 ) )
return - V_80 ;
return V_33 -> V_149 -> V_226 ( V_11 , & V_217 ) ;
}
int F_100 ( struct V_1 * V_70 , struct V_64 * V_65 )
{
return F_68 ( V_70 , V_65 , F_99 ) ;
}
static int
F_101 ( struct V_1 * V_2 , T_4 V_26 , T_4 V_27 ,
const struct V_216 * V_217 ,
const struct V_10 * V_11 )
{
void * V_29 ;
V_29 = F_23 ( V_2 , 0 , V_27 , & V_36 , V_130 ,
V_227 ) ;
if ( ! V_29 )
goto V_38;
if ( F_16 ( V_2 , V_16 , V_11 -> V_17 ) ||
F_17 ( V_2 , V_18 , V_11 -> V_19 ) ||
F_19 ( V_2 , V_218 , V_217 -> V_220 ) ||
F_19 ( V_2 , V_219 , V_217 -> V_223 ) ||
F_19 ( V_2 , V_197 ,
V_217 -> V_224 ) )
goto V_24;
if ( V_217 -> V_220 == V_181 &&
F_19 ( V_2 , V_221 ,
V_217 -> V_222 ) )
goto V_24;
F_32 ( V_2 , V_29 ) ;
return 0 ;
V_24:
F_33 ( V_2 , V_29 ) ;
V_38:
return - V_63 ;
}
static int F_102 ( struct V_166 * V_167 )
{
struct V_216 * V_195 ;
int V_114 = 0 , V_125 = 0 ;
F_79 (pos, &data->table->security_levels, list) {
if ( V_125 ++ < V_167 -> V_126 )
continue;
if ( F_101 ( V_167 -> V_70 , V_167 -> V_26 ,
V_167 -> V_129 , V_195 ,
V_167 -> V_11 ) ) {
V_114 = - V_63 ;
break;
}
V_167 -> V_126 ++ ;
}
return V_114 ;
}
int F_103 ( struct V_1 * V_70 ,
struct V_121 * V_122 )
{
return F_66 ( V_70 , V_122 , F_102 ) ;
}
