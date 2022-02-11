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
int F_13 ( struct V_9 * V_10 ,
struct V_11 * V_8 ,
T_3 V_12 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
if ( V_8 -> V_14 != V_15 ) {
F_15 ( L_2 , V_13 ) ;
return - V_16 ;
}
V_2 = F_16 ( 0 , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_1 ( V_2 , V_26 ,
V_8 -> V_27 ) ||
F_20 ( V_2 , V_28 , V_12 ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
int F_23 ( struct V_9 * V_10 , T_2 V_31 ,
T_3 V_32 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_16 ( 0 , V_33 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_7 ( V_2 , V_34 , V_31 ) ||
F_20 ( V_2 , V_35 , V_32 ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
int F_24 ( struct V_9 * V_10 ,
struct V_11 * V_8 ,
T_3 V_36 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_16 ( 0 , V_37 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) )
goto V_29;
if ( V_8 -> V_14 == V_15 ) {
if ( F_1 ( V_2 , V_26 ,
V_8 -> V_27 ) )
goto V_29;
} else {
if ( F_7 ( V_2 , V_38 ,
V_8 -> V_31 ) )
goto V_29;
}
if ( F_20 ( V_2 , V_39 , V_36 ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
int F_25 ( struct V_9 * V_10 , T_3 V_32 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_16 ( 0 , V_40 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_20 ( V_2 , V_35 , V_32 ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
int F_26 ( struct V_9 * V_10 , T_2 V_41 ,
T_2 V_42 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_16 ( 0 , V_43 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_7 ( V_2 , V_44 ,
V_42 ) ||
F_7 ( V_2 , V_45 , V_41 ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
int F_27 ( struct V_9 * V_10 ,
T_3 V_32 , T_3 V_46 ,
T_4 V_47 , T_3 V_48 ,
T_3 * V_49 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_16 ( 0 , V_50 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_20 ( V_2 , V_35 , V_32 ) ||
F_20 ( V_2 , V_51 , V_46 ) ||
F_18 ( V_2 , V_52 , V_47 ) ||
F_20 ( V_2 , V_53 , V_48 ) ||
( V_49 &&
F_19 ( V_2 , V_54 , 27 , V_49 ) ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
int F_28 ( struct V_9 * V_10 , T_3 V_32 )
{
struct V_1 * V_2 ;
F_14 ( L_1 , V_13 ) ;
V_2 = F_16 ( 0 , V_55 ) ;
if ( ! V_2 )
return - V_18 ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_20 ( V_2 , V_35 , V_32 ) )
goto V_29;
return F_21 ( V_2 , V_30 ) ;
V_29:
F_22 ( V_2 ) ;
return - V_18 ;
}
static int F_29 ( struct V_1 * V_2 , T_4 V_56 ,
T_4 V_57 , int V_58 , struct V_9 * V_10 )
{
void * V_59 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
T_2 V_31 , V_64 ;
F_14 ( L_1 , V_13 ) ;
V_59 = F_30 ( V_2 , 0 , V_57 , & V_65 , V_58 ,
V_66 ) ;
if ( ! V_59 )
goto V_67;
V_63 = V_62 ( V_10 ) ;
V_61 = V_63 -> V_68 ( V_10 ) ;
F_31 ( ! V_61 ) ;
V_31 = V_63 -> V_69 ( V_10 ) ;
V_64 = V_63 -> V_70 ( V_10 ) ;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_17 ( V_2 , V_71 , F_32 ( V_61 ) ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_19 ( V_2 , V_23 , V_24 ,
V_10 -> V_25 ) ||
F_7 ( V_2 , V_34 , V_31 ) ||
F_7 ( V_2 , V_72 , V_64 ) )
goto V_29;
if ( V_63 -> V_73 ) {
struct V_74 V_75 ;
V_63 -> V_73 ( V_10 , & V_75 ) ;
if ( F_33 ( V_2 , V_76 ,
V_75 . V_77 ) ||
F_20 ( V_2 , V_78 , V_75 . V_79 ) ||
F_20 ( V_2 , V_80 ,
V_75 . V_81 ) ||
F_34 ( V_2 , V_82 ,
V_75 . V_83 ) ||
F_20 ( V_2 , V_84 ,
V_75 . V_85 ) ||
F_20 ( V_2 , V_86 ,
V_75 . V_87 ) ||
F_20 ( V_2 , V_88 ,
V_75 . V_89 ) ||
F_33 ( V_2 , V_90 ,
V_75 . V_91 ) )
goto V_29;
}
F_35 ( V_61 ) ;
return F_36 ( V_2 , V_59 ) ;
V_29:
F_35 ( V_61 ) ;
F_37 ( V_2 , V_59 ) ;
V_67:
return - V_92 ;
}
static struct V_9 * F_38 ( struct V_93 * V_94 )
{
struct V_9 * V_10 ;
if ( V_94 -> V_95 [ V_19 ] ) {
char V_20 [ V_96 + 1 ] ;
F_39 ( V_20 , V_94 -> V_95 [ V_19 ] ,
sizeof( V_20 ) ) ;
V_10 = F_40 ( & V_97 , V_20 ) ;
} else if ( V_94 -> V_95 [ V_21 ] ) {
V_10 = F_41 ( & V_97 ,
F_42 ( V_94 -> V_95 [ V_21 ] ) ) ;
} else {
return NULL ;
}
if ( ! V_10 )
return NULL ;
if ( V_10 -> type != V_98 ) {
F_43 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
int F_44 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 ;
struct V_11 V_8 ;
T_3 V_48 ;
int V_100 = - V_101 ;
if ( ! V_94 -> V_95 [ V_102 ] ||
! V_94 -> V_95 [ V_45 ] ||
( ! V_94 -> V_95 [ V_103 ] &&
! V_94 -> V_95 [ V_44 ] ) ||
! V_94 -> V_95 [ V_28 ] )
return - V_16 ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_62 ( V_10 ) -> V_105 )
goto V_67;
if ( V_94 -> V_95 [ V_103 ] ) {
V_8 . V_14 = V_15 ;
V_8 . V_27 = F_4 (
V_94 -> V_95 [ V_103 ] ) ;
} else {
V_8 . V_14 = V_106 ;
V_8 . V_31 = F_10 (
V_94 -> V_95 [ V_44 ] ) ;
}
V_8 . V_64 = F_10 (
V_94 -> V_95 [ V_45 ] ) ;
if ( V_94 -> V_95 [ V_53 ] )
V_48 = F_45 ( V_94 -> V_95 [ V_53 ] ) ;
else
V_48 = 0 ;
V_100 = V_62 ( V_10 ) -> V_105 ( V_10 , & V_8 ,
F_45 ( V_94 -> V_95 [ V_102 ] ) ,
V_48 ,
F_45 ( V_94 -> V_95 [ V_28 ] ) ) ;
V_67:
F_43 ( V_10 ) ;
return V_100 ;
}
int F_46 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 ;
struct V_11 V_8 ;
int V_100 = - V_101 ;
if ( ! V_94 -> V_95 [ V_35 ] ||
! V_94 -> V_95 [ V_107 ] ||
! V_94 -> V_95 [ V_108 ] )
return - V_16 ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_62 ( V_10 ) -> V_109 )
goto V_67;
V_8 . V_14 = V_15 ;
V_8 . V_27 = F_4 (
V_94 -> V_95 [ V_107 ] ) ;
V_8 . V_64 = V_62 ( V_10 ) -> V_70 ( V_10 ) ;
V_100 = V_62 ( V_10 ) -> V_109 ( V_10 , & V_8 ,
F_10 ( V_94 -> V_95 [ V_108 ] ) ,
F_45 ( V_94 -> V_95 [ V_35 ] ) ) ;
V_67:
F_43 ( V_10 ) ;
return V_100 ;
}
int F_47 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 ;
struct V_11 V_8 ;
int V_100 = - V_101 ;
if ( ( ! V_94 -> V_95 [ V_107 ] &&
! V_94 -> V_95 [ V_108 ] ) ||
! V_94 -> V_95 [ V_39 ] )
return - V_16 ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_62 ( V_10 ) -> V_110 )
goto V_67;
if ( V_94 -> V_95 [ V_107 ] ) {
V_8 . V_14 = V_15 ;
V_8 . V_27 = F_4 (
V_94 -> V_95 [ V_107 ] ) ;
} else {
V_8 . V_14 = V_106 ;
V_8 . V_31 = F_10 (
V_94 -> V_95 [ V_108 ] ) ;
}
V_8 . V_64 = V_62 ( V_10 ) -> V_70 ( V_10 ) ;
V_100 = V_62 ( V_10 ) -> V_110 ( V_10 , & V_8 ,
F_45 ( V_94 -> V_95 [ V_39 ] ) ) ;
V_67:
F_43 ( V_10 ) ;
return V_100 ;
}
int F_48 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 ;
struct V_11 V_8 ;
T_3 V_111 , V_112 , V_113 ;
T_3 V_48 ;
int V_114 , V_115 , V_116 ;
int V_100 = - V_101 ;
if ( ! V_94 -> V_95 [ V_45 ] ||
! V_94 -> V_95 [ V_44 ] ||
! V_94 -> V_95 [ V_102 ] ||
! V_94 -> V_95 [ V_117 ] ||
! V_94 -> V_95 [ V_118 ] ||
! V_94 -> V_95 [ V_119 ] ||
! V_94 -> V_95 [ V_120 ] ||
! V_94 -> V_95 [ V_121 ]
)
return - V_16 ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_62 ( V_10 ) -> V_122 )
goto V_67;
V_8 . V_14 = V_106 ;
V_8 . V_31 = F_10 (
V_94 -> V_95 [ V_44 ] ) ;
V_8 . V_64 = F_10 (
V_94 -> V_95 [ V_45 ] ) ;
V_111 = F_45 ( V_94 -> V_95 [ V_102 ] ) ;
V_112 = F_45 ( V_94 -> V_95 [ V_117 ] ) ;
V_113 = F_45 ( V_94 -> V_95 [ V_118 ] ) ;
V_114 = F_45 ( V_94 -> V_95 [ V_119 ] ) ;
V_115 = F_45 ( V_94 -> V_95 [ V_120 ] ) ;
V_116 = F_45 ( V_94 -> V_95 [ V_121 ] ) ;
if ( V_94 -> V_95 [ V_53 ] )
V_48 = F_45 ( V_94 -> V_95 [ V_53 ] ) ;
else
V_48 = 0 ;
if ( V_8 . V_31 == F_11 ( V_123 ) ) {
F_28 ( V_10 , V_124 ) ;
F_43 ( V_10 ) ;
return - V_16 ;
}
V_100 = V_62 ( V_10 ) -> V_122 ( V_10 , & V_8 , V_111 , V_48 ,
V_112 , V_113 , V_114 , V_115 , V_116 ) ;
V_67:
F_43 ( V_10 ) ;
return V_100 ;
}
int F_49 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 ;
int V_100 = - V_101 ;
T_3 type ;
T_4 V_125 ;
T_3 V_126 ;
T_3 V_48 ;
if ( ! V_94 -> V_95 [ V_51 ] ||
! V_94 -> V_95 [ V_52 ] ||
! V_94 -> V_95 [ V_127 ] )
return - V_16 ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_62 ( V_10 ) -> V_128 )
goto V_67;
type = F_45 ( V_94 -> V_95 [ V_51 ] ) ;
V_125 = F_42 ( V_94 -> V_95 [ V_52 ] ) ;
V_126 = F_45 ( V_94 -> V_95 [ V_127 ] ) ;
if ( V_94 -> V_95 [ V_53 ] )
V_48 = F_45 ( V_94 -> V_95 [ V_53 ] ) ;
else
V_48 = 0 ;
V_100 = V_62 ( V_10 ) -> V_128 ( V_10 , type , V_125 ,
V_48 , V_126 ) ;
V_67:
F_43 ( V_10 ) ;
return V_100 ;
}
int F_50 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
int V_129 = - V_18 ;
F_14 ( L_1 , V_13 ) ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
V_2 = F_51 ( V_130 , V_131 ) ;
if ( ! V_2 )
goto V_132;
V_129 = F_29 ( V_2 , V_94 -> V_133 , V_94 -> V_134 ,
0 , V_10 ) ;
if ( V_129 < 0 )
goto V_135;
F_43 ( V_10 ) ;
return F_52 ( V_2 , V_94 ) ;
V_135:
F_22 ( V_2 ) ;
V_132:
F_43 ( V_10 ) ;
return V_129 ;
}
int F_53 ( struct V_1 * V_99 , struct V_136 * V_137 )
{
struct V_138 * V_138 = F_54 ( V_99 -> V_139 ) ;
struct V_9 * V_10 ;
int V_140 ;
int V_141 = V_137 -> args [ 0 ] ;
F_14 ( L_1 , V_13 ) ;
V_140 = 0 ;
F_55 (net, dev) {
if ( V_140 < V_141 || ( V_10 -> type != V_98 ) )
goto V_142;
if ( F_29 ( V_99 , F_56 ( V_137 -> V_99 ) . V_56 ,
V_137 -> V_143 -> V_144 ,
V_145 , V_10 ) < 0 )
break;
V_142:
V_140 ++ ;
}
V_137 -> args [ 0 ] = V_140 ;
return V_99 -> V_146 ;
}
int F_57 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 = NULL ;
struct V_62 * V_63 ;
struct V_74 V_75 ;
struct V_60 * V_61 ;
int V_129 = - V_16 ;
F_14 ( L_1 , V_13 ) ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
V_63 = V_62 ( V_10 ) ;
if ( ! V_63 -> V_73 || ! V_63 -> V_147 ) {
V_129 = - V_101 ;
goto V_67;
}
if ( F_58 ( V_10 ) ) {
V_129 = - V_148 ;
goto V_67;
}
if ( ! V_94 -> V_95 [ V_78 ] &&
! V_94 -> V_95 [ V_80 ] &&
! V_94 -> V_95 [ V_82 ] &&
! V_94 -> V_95 [ V_84 ] &&
! V_94 -> V_95 [ V_86 ] &&
! V_94 -> V_95 [ V_88 ] &&
! V_94 -> V_95 [ V_90 ] )
goto V_67;
V_61 = V_63 -> V_68 ( V_10 ) ;
if ( ( ! V_61 -> V_149 && V_94 -> V_95 [ V_78 ] ) ||
( ! V_61 -> V_150 && V_94 -> V_95 [ V_80 ] ) ||
( ! V_61 -> V_151 &&
V_94 -> V_95 [ V_82 ] ) ||
( ! V_61 -> V_152 &&
( V_94 -> V_95 [ V_84 ] ||
V_94 -> V_95 [ V_86 ] ||
V_94 -> V_95 [ V_88 ] ) ) ||
( ! V_61 -> V_153 &&
V_94 -> V_95 [ V_90 ] ) ) {
V_129 = - V_101 ;
goto V_154;
}
V_63 -> V_73 ( V_10 , & V_75 ) ;
if ( V_94 -> V_95 [ V_76 ] )
V_75 . V_77 = F_59 ( V_94 -> V_95 [ V_76 ] ) ;
if ( V_94 -> V_95 [ V_78 ] )
V_75 . V_79 = F_45 ( V_94 -> V_95 [ V_78 ] ) ;
if ( V_94 -> V_95 [ V_80 ] )
V_75 . V_81 = F_45 ( V_94 -> V_95 [ V_80 ] ) ;
if ( V_94 -> V_95 [ V_82 ] )
V_75 . V_83 = F_60 ( V_94 -> V_95 [ V_82 ] ) ;
if ( V_94 -> V_95 [ V_84 ] )
V_75 . V_85 = F_45 ( V_94 -> V_95 [ V_84 ] ) ;
if ( V_94 -> V_95 [ V_86 ] )
V_75 . V_87 = F_45 ( V_94 -> V_95 [ V_86 ] ) ;
if ( V_94 -> V_95 [ V_88 ] )
V_75 . V_89 = F_45 ( V_94 -> V_95 [ V_88 ] ) ;
if ( V_94 -> V_95 [ V_90 ] )
V_75 . V_91 = F_59 ( V_94 -> V_95 [ V_90 ] ) ;
V_129 = V_63 -> V_147 ( V_10 , & V_75 ) ;
F_35 ( V_61 ) ;
F_43 ( V_10 ) ;
return V_129 ;
V_154:
F_35 ( V_61 ) ;
V_67:
F_43 ( V_10 ) ;
return V_129 ;
}
static int
F_61 ( struct V_93 * V_94 ,
struct V_155 * V_156 )
{
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
if ( ! V_94 -> V_95 [ V_157 ] )
return - V_16 ;
V_156 -> V_14 = F_45 ( V_94 -> V_95 [ V_157 ] ) ;
if ( V_156 -> V_14 == V_158 ) {
if ( ! V_94 -> V_95 [ V_72 ] &&
! ( V_94 -> V_95 [ V_34 ] ||
V_94 -> V_95 [ V_23 ] ) )
return - V_16 ;
V_156 -> V_159 . V_64 = F_10 ( V_94 -> V_95 [ V_72 ] ) ;
if ( V_94 -> V_95 [ V_34 ] ) {
V_156 -> V_159 . V_14 = V_106 ;
V_156 -> V_159 . V_31 = F_10 ( V_94 -> V_95 [ V_34 ] ) ;
} else {
V_156 -> V_159 . V_14 = V_15 ;
V_156 -> V_159 . V_27 = F_4 ( V_94 -> V_95 [ V_23 ] ) ;
}
}
if ( V_156 -> V_14 != V_158 &&
! V_94 -> V_95 [ V_160 ] )
return - V_16 ;
if ( V_156 -> V_14 == V_161 &&
! V_94 -> V_95 [ V_162 ] )
return - V_16 ;
if ( V_156 -> V_14 == V_163 &&
! V_94 -> V_95 [ V_164 ] )
return - V_16 ;
if ( V_156 -> V_14 != V_158 )
V_156 -> V_165 = F_45 ( V_94 -> V_95 [ V_160 ] ) ;
switch ( V_156 -> V_14 ) {
case V_161 :
{
T_4 V_166 = F_42 ( V_94 -> V_95 [ V_162 ] ) ;
V_156 -> V_167 = F_62 ( V_166 ) ;
break;
}
case V_163 :
V_156 -> V_168 = F_4 ( V_94 -> V_95 [ V_164 ] ) ;
break;
}
return 0 ;
}
static int
F_63 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
if ( F_20 ( V_2 , V_157 , V_156 -> V_14 ) )
return - V_92 ;
if ( V_156 -> V_14 == V_158 ) {
if ( F_7 ( V_2 , V_72 ,
V_156 -> V_159 . V_64 ) )
return - V_92 ;
if ( V_156 -> V_159 . V_14 == V_106 &&
F_7 ( V_2 , V_34 ,
V_156 -> V_159 . V_31 ) )
return - V_92 ;
if ( V_156 -> V_159 . V_14 == V_15 &&
F_1 ( V_2 , V_23 ,
V_156 -> V_159 . V_27 ) )
return - V_92 ;
}
if ( V_156 -> V_14 != V_158 &&
F_20 ( V_2 , V_160 , V_156 -> V_165 ) )
return - V_92 ;
if ( V_156 -> V_14 == V_161 &&
F_18 ( V_2 , V_162 ,
F_64 ( V_156 -> V_167 ) ) )
return - V_92 ;
if ( V_156 -> V_14 == V_163 &&
F_1 ( V_2 , V_164 ,
V_156 -> V_168 ) )
return - V_92 ;
return 0 ;
}
int F_65 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = NULL ;
int V_129 = - V_18 ;
struct V_62 * V_63 ;
void * V_59 ;
struct V_169 V_75 ;
F_14 ( L_1 , V_13 ) ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
V_63 = V_62 ( V_10 ) ;
if ( ! V_63 -> V_170 ) {
V_129 = - V_101 ;
goto V_132;
}
V_2 = F_51 ( V_130 , V_131 ) ;
if ( ! V_2 )
goto V_132;
V_59 = F_30 ( V_2 , 0 , V_94 -> V_134 , & V_65 , 0 ,
V_171 ) ;
if ( ! V_59 )
goto V_135;
V_129 = V_63 -> V_170 -> V_172 ( V_10 , & V_75 ) ;
if ( V_129 < 0 )
goto V_135;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_20 ( V_2 , V_173 , V_75 . V_174 ) ||
F_20 ( V_2 , V_175 , V_75 . V_176 ) ||
F_18 ( V_2 , V_177 ,
F_66 ( V_75 . V_178 ) ) ||
F_63 ( V_2 , & V_75 . V_179 ) )
goto V_135;
F_43 ( V_10 ) ;
return F_67 ( V_2 , V_94 ) ;
V_135:
F_22 ( V_2 ) ;
V_132:
F_43 ( V_10 ) ;
return V_129 ;
}
int F_68 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
struct V_9 * V_10 = NULL ;
int V_129 = - V_16 ;
struct V_62 * V_63 ;
struct V_169 V_75 ;
int V_180 = 0 ;
F_14 ( L_1 , V_13 ) ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_94 -> V_95 [ V_173 ] &&
! V_94 -> V_95 [ V_157 ] &&
! V_94 -> V_95 [ V_175 ] )
goto V_67;
V_63 = V_62 ( V_10 ) ;
if ( ! V_63 -> V_170 ) {
V_129 = - V_101 ;
goto V_67;
}
if ( V_94 -> V_95 [ V_175 ] &&
F_45 ( V_94 -> V_95 [ V_175 ] ) > 7 )
goto V_67;
if ( V_94 -> V_95 [ V_173 ] ) {
V_75 . V_174 = F_45 ( V_94 -> V_95 [ V_173 ] ) ;
V_180 |= V_181 ;
}
if ( V_94 -> V_95 [ V_157 ] ) {
if ( F_61 ( V_94 , & V_75 . V_179 ) )
goto V_67;
V_180 |= V_182 ;
}
if ( V_94 -> V_95 [ V_175 ] ) {
V_75 . V_176 = F_45 ( V_94 -> V_95 [ V_175 ] ) ;
V_180 |= V_183 ;
}
if ( V_94 -> V_95 [ V_177 ] ) {
T_4 V_184 = F_42 ( V_94 -> V_95 [ V_177 ] ) ;
V_75 . V_178 = F_69 ( V_184 ) ;
V_180 |= V_185 ;
}
V_129 = V_63 -> V_170 -> V_186 ( V_10 , & V_75 , V_180 ) ;
F_43 ( V_10 ) ;
return V_129 ;
V_67:
F_43 ( V_10 ) ;
return V_129 ;
}
static int
F_70 ( struct V_1 * V_99 , struct V_136 * V_137 ,
int (* F_71)( struct V_187 * ) )
{
struct V_138 * V_138 = F_54 ( V_99 -> V_139 ) ;
struct V_9 * V_10 ;
struct V_187 V_188 ;
int V_140 = 0 ;
int V_189 = V_137 -> args [ 0 ] ;
int V_129 ;
F_55 (net, dev) {
if ( V_140 < V_189 || V_10 -> type != V_98 )
goto V_190;
V_188 . V_63 = V_62 ( V_10 ) ;
if ( ! V_188 . V_63 -> V_170 )
goto V_190;
V_188 . V_99 = V_99 ;
V_188 . V_141 = V_137 -> args [ 1 ] ;
V_188 . V_191 = V_137 -> args [ 2 ] ;
V_188 . V_10 = V_10 ;
V_188 . V_56 = F_56 ( V_137 -> V_99 ) . V_56 ;
V_188 . V_144 = V_137 -> V_143 -> V_144 ;
V_188 . V_63 -> V_170 -> V_192 ( V_10 ) ;
V_188 . V_63 -> V_170 -> V_193 ( V_188 . V_10 , & V_188 . V_194 ) ;
V_129 = F_71 ( & V_188 ) ;
V_188 . V_63 -> V_170 -> V_195 ( V_10 ) ;
if ( V_129 < 0 )
break;
V_190:
V_140 ++ ;
}
V_137 -> args [ 0 ] = V_140 ;
return V_99 -> V_146 ;
}
static int
F_72 ( struct V_1 * V_99 , struct V_93 * V_94 ,
int (* F_73)( struct V_9 * , struct V_93 * ) )
{
struct V_9 * V_10 = NULL ;
int V_129 = - V_16 ;
V_10 = F_38 ( V_94 ) ;
if ( ! V_10 )
return - V_104 ;
if ( ! V_62 ( V_10 ) -> V_170 )
V_129 = - V_101 ;
else
V_129 = F_73 ( V_10 , V_94 ) ;
F_43 ( V_10 ) ;
return V_129 ;
}
static int
F_74 ( struct V_93 * V_94 ,
struct V_196 * V_197 )
{
T_3 V_198 ;
T_4 V_199 [ 256 / 32 ] ;
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
if ( ! V_94 -> V_95 [ V_200 ] ||
! V_94 -> V_95 [ V_201 ] )
return - V_16 ;
V_198 = F_45 ( V_94 -> V_95 [ V_200 ] ) ;
if ( ( V_198 & F_75 ( V_202 ) ) &&
! V_94 -> V_95 [ V_203 ] )
return - V_16 ;
if ( V_94 -> V_95 [ V_203 ] ) {
F_76 ( V_199 ,
V_94 -> V_95 [ V_203 ] ,
256 / 8 ) ;
if ( V_199 [ 0 ] || V_199 [ 1 ] || V_199 [ 2 ] || V_199 [ 3 ] ||
V_199 [ 4 ] || V_199 [ 5 ] || V_199 [ 6 ] ||
V_199 [ 7 ] >= F_75 ( V_204 + 1 ) )
return - V_16 ;
V_197 -> V_205 = V_199 [ 7 ] ;
}
V_197 -> V_206 = V_198 ;
F_76 ( V_197 -> V_197 , V_94 -> V_95 [ V_201 ] ,
V_207 ) ;
return 0 ;
}
static int F_77 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_196 V_197 ;
struct V_155 V_165 ;
if ( F_74 ( V_94 , & V_197 ) ||
F_61 ( V_94 , & V_165 ) )
return - V_16 ;
return V_63 -> V_170 -> V_208 ( V_10 , & V_165 , & V_197 ) ;
}
int F_78 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
if ( ( V_94 -> V_209 -> V_210 & ( V_211 | V_212 ) ) !=
( V_211 | V_212 ) )
return - V_16 ;
return F_72 ( V_99 , V_94 , F_77 ) ;
}
static int F_79 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_155 V_165 ;
if ( F_61 ( V_94 , & V_165 ) )
return - V_16 ;
return V_63 -> V_170 -> V_213 ( V_10 , & V_165 ) ;
}
int F_80 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
return F_72 ( V_99 , V_94 , F_79 ) ;
}
static int
F_81 ( struct V_1 * V_2 , T_4 V_56 , T_4 V_57 ,
const struct V_214 * V_197 ,
const struct V_9 * V_10 )
{
void * V_59 ;
T_4 V_199 [ 256 / 32 ] ;
V_59 = F_30 ( V_2 , 0 , V_57 , & V_65 , V_145 ,
V_215 ) ;
if ( ! V_59 )
goto V_67;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_63 ( V_2 , & V_197 -> V_165 ) ||
F_20 ( V_2 , V_200 ,
V_197 -> V_197 -> V_206 ) )
goto V_29;
if ( V_197 -> V_197 -> V_206 & F_75 ( V_202 ) ) {
memset ( V_199 , 0 , sizeof( V_199 ) ) ;
V_199 [ 7 ] = V_197 -> V_197 -> V_205 ;
if ( F_19 ( V_2 , V_203 ,
sizeof( V_199 ) , V_199 ) )
goto V_29;
}
if ( F_19 ( V_2 , V_201 ,
V_207 , V_197 -> V_197 -> V_197 ) )
goto V_29;
F_36 ( V_2 , V_59 ) ;
return 0 ;
V_29:
F_37 ( V_2 , V_59 ) ;
V_67:
return - V_92 ;
}
static int F_82 ( struct V_187 * V_188 )
{
struct V_214 * V_216 ;
int V_129 = 0 , V_140 = 0 ;
F_83 (pos, &data->table->keys, list) {
if ( V_140 ++ < V_188 -> V_141 )
continue;
if ( F_81 ( V_188 -> V_99 , V_188 -> V_56 ,
V_188 -> V_144 , V_216 , V_188 -> V_10 ) ) {
V_129 = - V_92 ;
break;
}
V_188 -> V_141 ++ ;
}
return V_129 ;
}
int F_84 ( struct V_1 * V_99 , struct V_136 * V_137 )
{
return F_70 ( V_99 , V_137 , F_82 ) ;
}
static int
F_85 ( struct V_93 * V_94 ,
struct V_217 * V_10 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( ! V_94 -> V_95 [ V_177 ] ||
! V_94 -> V_95 [ V_23 ] ||
! V_94 -> V_95 [ V_218 ] ||
! V_94 -> V_95 [ V_219 ] ||
( ! ! V_94 -> V_95 [ V_72 ] !=
! ! V_94 -> V_95 [ V_34 ] ) )
return - V_16 ;
if ( V_94 -> V_95 [ V_72 ] ) {
V_10 -> V_64 = F_10 ( V_94 -> V_95 [ V_72 ] ) ;
V_10 -> V_31 = F_10 ( V_94 -> V_95 [ V_34 ] ) ;
} else {
V_10 -> V_31 = F_11 ( V_220 ) ;
}
V_10 -> V_3 = F_4 ( V_94 -> V_95 [ V_23 ] ) ;
V_10 -> V_178 = F_42 ( V_94 -> V_95 [ V_177 ] ) ;
V_10 -> V_221 = ! ! F_45 ( V_94 -> V_95 [ V_218 ] ) ;
V_10 -> V_222 = F_45 ( V_94 -> V_95 [ V_219 ] ) ;
if ( V_10 -> V_222 >= V_223 )
return - V_16 ;
return 0 ;
}
static int F_86 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_217 V_156 ;
if ( F_85 ( V_94 , & V_156 ) )
return - V_16 ;
return V_63 -> V_170 -> V_224 ( V_10 , & V_156 ) ;
}
int F_87 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
if ( ( V_94 -> V_209 -> V_210 & ( V_211 | V_212 ) ) !=
( V_211 | V_212 ) )
return - V_16 ;
return F_72 ( V_99 , V_94 , F_86 ) ;
}
static int F_88 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
T_1 V_225 ;
if ( ! V_94 -> V_95 [ V_23 ] )
return - V_16 ;
V_225 = F_4 ( V_94 -> V_95 [ V_23 ] ) ;
return V_63 -> V_170 -> V_226 ( V_10 , V_225 ) ;
}
int F_89 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
return F_72 ( V_99 , V_94 , F_88 ) ;
}
static int
F_90 ( struct V_1 * V_2 , T_4 V_56 , T_4 V_57 ,
const struct V_217 * V_156 ,
const struct V_9 * V_10 )
{
void * V_59 ;
V_59 = F_30 ( V_2 , 0 , V_57 , & V_65 , V_145 ,
V_227 ) ;
if ( ! V_59 )
goto V_67;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_7 ( V_2 , V_72 , V_156 -> V_64 ) ||
F_7 ( V_2 , V_34 ,
V_156 -> V_31 ) ||
F_1 ( V_2 , V_23 , V_156 -> V_3 ) ||
F_18 ( V_2 , V_177 ,
V_156 -> V_178 ) ||
F_20 ( V_2 , V_218 ,
V_156 -> V_221 ) ||
F_20 ( V_2 , V_219 , V_156 -> V_222 ) )
goto V_29;
F_36 ( V_2 , V_59 ) ;
return 0 ;
V_29:
F_37 ( V_2 , V_59 ) ;
V_67:
return - V_92 ;
}
static int F_91 ( struct V_187 * V_188 )
{
struct V_217 * V_216 ;
int V_129 = 0 , V_140 = 0 ;
F_83 (pos, &data->table->devices, list) {
if ( V_140 ++ < V_188 -> V_141 )
continue;
if ( F_90 ( V_188 -> V_99 , V_188 -> V_56 ,
V_188 -> V_144 , V_216 , V_188 -> V_10 ) ) {
V_129 = - V_92 ;
break;
}
V_188 -> V_141 ++ ;
}
return V_129 ;
}
int F_92 ( struct V_1 * V_99 , struct V_136 * V_137 )
{
return F_70 ( V_99 , V_137 , F_91 ) ;
}
static int F_93 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_228 V_197 ;
T_1 V_225 ;
if ( ! V_94 -> V_95 [ V_177 ] ||
! V_94 -> V_95 [ V_23 ] ||
F_61 ( V_94 , & V_197 . V_229 ) )
return - V_16 ;
V_225 = F_4 ( V_94 -> V_95 [ V_23 ] ) ;
V_197 . V_178 = F_42 ( V_94 -> V_95 [ V_177 ] ) ;
return V_63 -> V_170 -> V_230 ( V_10 , V_225 , & V_197 ) ;
}
int F_94 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
if ( ( V_94 -> V_209 -> V_210 & ( V_211 | V_212 ) ) !=
( V_211 | V_212 ) )
return - V_16 ;
return F_72 ( V_99 , V_94 , F_93 ) ;
}
static int F_95 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_228 V_197 ;
T_1 V_225 ;
if ( ! V_94 -> V_95 [ V_23 ] ||
F_61 ( V_94 , & V_197 . V_229 ) )
return - V_16 ;
V_225 = F_4 ( V_94 -> V_95 [ V_23 ] ) ;
return V_63 -> V_170 -> V_231 ( V_10 , V_225 , & V_197 ) ;
}
int F_96 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
return F_72 ( V_99 , V_94 , F_95 ) ;
}
static int
F_97 ( struct V_1 * V_2 , T_4 V_56 , T_4 V_57 ,
T_1 V_225 ,
const struct V_228 * V_232 ,
const struct V_9 * V_10 )
{
void * V_59 ;
V_59 = F_30 ( V_2 , 0 , V_57 , & V_65 , V_145 ,
V_233 ) ;
if ( ! V_59 )
goto V_67;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_1 ( V_2 , V_23 , V_225 ) ||
F_18 ( V_2 , V_177 ,
V_232 -> V_178 ) ||
F_63 ( V_2 , & V_232 -> V_229 ) )
goto V_29;
F_36 ( V_2 , V_59 ) ;
return 0 ;
V_29:
F_37 ( V_2 , V_59 ) ;
V_67:
return - V_92 ;
}
static int F_98 ( struct V_187 * V_188 )
{
struct V_217 * V_234 ;
struct V_228 * V_235 ;
int V_129 = 0 , V_140 = 0 , V_236 ;
F_83 (dpos, &data->table->devices, list) {
if ( V_140 ++ < V_188 -> V_141 )
continue;
V_236 = 0 ;
F_83 (kpos, &dpos->keys, list) {
if ( V_236 ++ < V_188 -> V_191 )
continue;
if ( F_97 ( V_188 -> V_99 , V_188 -> V_56 ,
V_188 -> V_144 ,
V_234 -> V_3 , V_235 ,
V_188 -> V_10 ) ) {
return V_129 = - V_92 ;
}
V_188 -> V_191 ++ ;
}
V_188 -> V_141 ++ ;
}
return V_129 ;
}
int F_99 ( struct V_1 * V_99 ,
struct V_136 * V_137 )
{
return F_70 ( V_99 , V_137 , F_98 ) ;
}
static int
F_100 ( struct V_93 * V_94 ,
struct V_237 * V_238 )
{
memset ( V_238 , 0 , sizeof( * V_238 ) ) ;
if ( ! V_94 -> V_95 [ V_239 ] ||
! V_94 -> V_95 [ V_240 ] ||
! V_94 -> V_95 [ V_218 ] )
return - V_16 ;
V_238 -> V_241 = F_45 ( V_94 -> V_95 [ V_239 ] ) ;
if ( V_238 -> V_241 == V_202 ) {
if ( ! V_94 -> V_95 [ V_242 ] )
return - V_16 ;
V_238 -> V_243 = F_45 ( V_94 -> V_95 [ V_242 ] ) ;
}
V_238 -> V_244 = F_45 ( V_94 -> V_95 [ V_240 ] ) ;
V_238 -> V_245 = F_45 ( V_94 -> V_95 [ V_218 ] ) ;
return 0 ;
}
static int F_101 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_237 V_238 ;
if ( F_100 ( V_94 , & V_238 ) )
return - V_16 ;
return V_63 -> V_170 -> V_246 ( V_10 , & V_238 ) ;
}
int F_102 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
if ( ( V_94 -> V_209 -> V_210 & ( V_211 | V_212 ) ) !=
( V_211 | V_212 ) )
return - V_16 ;
return F_72 ( V_99 , V_94 , F_101 ) ;
}
static int F_103 ( struct V_9 * V_10 , struct V_93 * V_94 )
{
struct V_62 * V_63 = V_62 ( V_10 ) ;
struct V_237 V_238 ;
if ( F_100 ( V_94 , & V_238 ) )
return - V_16 ;
return V_63 -> V_170 -> V_247 ( V_10 , & V_238 ) ;
}
int F_104 ( struct V_1 * V_99 , struct V_93 * V_94 )
{
return F_72 ( V_99 , V_94 , F_103 ) ;
}
static int
F_105 ( struct V_1 * V_2 , T_4 V_56 , T_4 V_57 ,
const struct V_237 * V_238 ,
const struct V_9 * V_10 )
{
void * V_59 ;
V_59 = F_30 ( V_2 , 0 , V_57 , & V_65 , V_145 ,
V_248 ) ;
if ( ! V_59 )
goto V_67;
if ( F_17 ( V_2 , V_19 , V_10 -> V_20 ) ||
F_18 ( V_2 , V_21 , V_10 -> V_22 ) ||
F_20 ( V_2 , V_239 , V_238 -> V_241 ) ||
F_20 ( V_2 , V_240 , V_238 -> V_244 ) ||
F_20 ( V_2 , V_218 ,
V_238 -> V_245 ) )
goto V_29;
if ( V_238 -> V_241 == V_202 &&
F_20 ( V_2 , V_242 ,
V_238 -> V_243 ) )
goto V_29;
F_36 ( V_2 , V_59 ) ;
return 0 ;
V_29:
F_37 ( V_2 , V_59 ) ;
V_67:
return - V_92 ;
}
static int F_106 ( struct V_187 * V_188 )
{
struct V_237 * V_216 ;
int V_129 = 0 , V_140 = 0 ;
F_83 (pos, &data->table->security_levels, list) {
if ( V_140 ++ < V_188 -> V_141 )
continue;
if ( F_105 ( V_188 -> V_99 , V_188 -> V_56 ,
V_188 -> V_144 , V_216 ,
V_188 -> V_10 ) ) {
V_129 = - V_92 ;
break;
}
V_188 -> V_141 ++ ;
}
return V_129 ;
}
int F_107 ( struct V_1 * V_99 ,
struct V_136 * V_137 )
{
return F_70 ( V_99 , V_137 , F_106 ) ;
}
