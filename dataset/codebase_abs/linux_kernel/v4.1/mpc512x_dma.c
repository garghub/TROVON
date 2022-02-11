static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_2 ( V_6 , struct V_5 , V_7 [ V_3 -> V_8 ] ) ;
}
static void F_4 ( struct V_1 * V_6 )
{
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_12 = NULL ;
struct V_10 * V_13 ;
int V_14 = V_6 -> V_4 . V_8 ;
while ( ! F_5 ( & V_6 -> V_15 ) ) {
V_13 = F_6 ( & V_6 -> V_15 ,
struct V_10 , V_16 ) ;
if ( V_13 -> V_17 ) {
if ( F_5 ( & V_6 -> V_18 ) )
F_7 ( & V_13 -> V_16 , & V_6 -> V_18 ) ;
break;
} else {
F_7 ( & V_13 -> V_16 , & V_6 -> V_18 ) ;
}
}
F_8 (mdesc, &mchan->active, node) {
if ( ! V_11 )
V_11 = V_13 ;
if ( ! V_12 ) {
V_12 = V_13 ;
continue;
}
V_12 -> V_19 -> V_20 = V_13 -> V_21 ;
V_12 -> V_19 -> V_22 = 1 ;
V_13 -> V_19 -> V_23 = 1 ;
V_12 = V_13 ;
}
V_12 -> V_19 -> V_24 = 1 ;
F_9 ( & V_9 -> V_19 [ V_14 ] , V_11 -> V_19 , sizeof( struct V_25 ) ) ;
if ( V_11 != V_12 )
V_9 -> V_19 [ V_14 ] . V_22 = 1 ;
if ( V_9 -> V_26 ) {
F_10 ( & V_9 -> V_27 -> V_28 , V_14 ) ;
} else if ( V_11 -> V_17 ) {
F_10 ( & V_9 -> V_27 -> V_29 , V_14 ) ;
} else {
F_10 ( & V_9 -> V_27 -> V_28 , V_14 ) ;
}
}
static void F_11 ( struct V_5 * V_9 , T_1 V_30 , T_1 V_31 , int V_32 )
{
struct V_1 * V_6 ;
struct V_10 * V_13 ;
T_1 V_33 = V_30 | V_31 ;
int V_34 ;
while ( ( V_34 = F_12 ( V_33 ) - 1 ) >= 0 ) {
V_33 &= ~ ( 1 << V_34 ) ;
V_6 = & V_9 -> V_7 [ V_34 + V_32 ] ;
F_13 ( & V_6 -> V_35 ) ;
F_10 ( & V_9 -> V_27 -> V_36 , V_34 + V_32 ) ;
F_10 ( & V_9 -> V_27 -> V_37 , V_34 + V_32 ) ;
if ( V_31 & ( 1 << V_34 ) )
F_8 (mdesc, &mchan->active, node)
V_13 -> error = - V_38 ;
F_14 ( & V_6 -> V_18 , & V_6 -> V_39 ) ;
if ( ! F_5 ( & V_6 -> V_15 ) )
F_4 ( V_6 ) ;
F_15 ( & V_6 -> V_35 ) ;
}
}
static T_2 F_16 ( int V_40 , void * V_41 )
{
struct V_5 * V_9 = V_41 ;
T_3 V_31 ;
V_31 = F_17 ( & V_9 -> V_27 -> V_42 ) ;
F_13 ( & V_9 -> V_43 ) ;
if ( ( V_31 & V_44 ) && V_9 -> V_45 == 0 )
V_9 -> V_45 = V_31 ;
F_15 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_46 . V_47 > 32 ) {
F_11 ( V_9 , F_17 ( & V_9 -> V_27 -> V_48 ) ,
F_17 ( & V_9 -> V_27 -> V_49 ) , 32 ) ;
}
F_11 ( V_9 , F_17 ( & V_9 -> V_27 -> V_50 ) ,
F_17 ( & V_9 -> V_27 -> V_51 ) , 0 ) ;
F_18 ( & V_9 -> V_52 ) ;
return V_53 ;
}
static void F_19 ( struct V_5 * V_9 )
{
T_4 V_54 = 0 ;
struct V_1 * V_6 ;
struct V_10 * V_13 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
F_20 ( V_58 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_9 -> V_46 . V_47 ; V_59 ++ ) {
V_6 = & V_9 -> V_7 [ V_59 ] ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
if ( ! F_5 ( & V_6 -> V_39 ) )
F_14 ( & V_6 -> V_39 , & V_58 ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
if ( F_5 ( & V_58 ) )
continue;
F_8 (mdesc, &list, node) {
V_56 = & V_13 -> V_56 ;
if ( V_56 -> V_60 )
V_56 -> V_60 ( V_56 -> V_61 ) ;
V_54 = V_56 -> V_62 ;
F_23 ( V_56 ) ;
}
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_14 ( & V_58 , & V_6 -> free ) ;
V_6 -> V_4 . V_63 = V_54 ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
}
}
static void F_24 ( unsigned long V_41 )
{
struct V_5 * V_9 = ( void * ) V_41 ;
unsigned long V_57 ;
T_3 V_31 ;
F_21 ( & V_9 -> V_43 , V_57 ) ;
V_31 = V_9 -> V_45 ;
V_9 -> V_45 = 0 ;
F_22 ( & V_9 -> V_43 , V_57 ) ;
if ( V_31 ) {
F_25 ( V_9 -> V_46 . V_64 ,
L_1 ,
F_26 ( V_31 ) ) ;
if ( V_31 & V_65 )
F_25 ( V_9 -> V_46 . V_64 , L_2 ) ;
if ( V_31 & V_66 )
F_25 ( V_9 -> V_46 . V_64 , L_3 ) ;
if ( V_31 & V_67 )
F_25 ( V_9 -> V_46 . V_64 , L_4 ) ;
if ( V_31 & V_68 )
F_25 ( V_9 -> V_46 . V_64 , L_5
L_6 ) ;
if ( V_31 & V_69 )
F_25 ( V_9 -> V_46 . V_64 , L_7
L_8 ) ;
if ( V_31 & V_70 )
F_25 ( V_9 -> V_46 . V_64 , L_9
L_6 ) ;
if ( V_31 & V_71 )
F_25 ( V_9 -> V_46 . V_64 , L_10
L_6 ) ;
if ( V_31 & V_72 )
F_25 ( V_9 -> V_46 . V_64 , L_11
L_6 ) ;
if ( V_31 & V_73 )
F_25 ( V_9 -> V_46 . V_64 , L_12 ) ;
if ( V_31 & V_74 )
F_25 ( V_9 -> V_46 . V_64 , L_13 ) ;
}
F_19 ( V_9 ) ;
}
static T_4 F_27 ( struct V_55 * V_75 )
{
struct V_1 * V_6 = F_1 ( V_75 -> V_4 ) ;
struct V_10 * V_13 ;
unsigned long V_57 ;
T_4 V_62 ;
V_13 = F_2 ( V_75 , struct V_10 , V_56 ) ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_7 ( & V_13 -> V_16 , & V_6 -> V_15 ) ;
if ( F_5 ( & V_6 -> V_18 ) )
F_4 ( V_6 ) ;
V_62 = F_28 ( V_75 ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
return V_62 ;
}
static int F_29 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 ;
struct V_25 * V_19 ;
T_5 V_21 ;
unsigned long V_57 ;
F_20 ( V_76 ) ;
int V_59 ;
V_19 = F_30 ( V_9 -> V_46 . V_64 ,
V_77 * sizeof( struct V_25 ) ,
& V_21 , V_78 ) ;
if ( ! V_19 )
return - V_79 ;
for ( V_59 = 0 ; V_59 < V_77 ; V_59 ++ ) {
V_13 = F_31 ( sizeof( struct V_10 ) , V_78 ) ;
if ( ! V_13 ) {
F_32 ( V_9 -> V_46 . V_64 , L_14
L_15 , V_59 ) ;
break;
}
F_33 ( & V_13 -> V_56 , V_4 ) ;
V_13 -> V_56 . V_57 = V_80 ;
V_13 -> V_56 . V_81 = F_27 ;
V_13 -> V_19 = & V_19 [ V_59 ] ;
V_13 -> V_21 = V_21 + ( V_59 * sizeof( struct V_25 ) ) ;
F_34 ( & V_13 -> V_16 , & V_76 ) ;
}
if ( V_59 == 0 ) {
F_35 ( V_9 -> V_46 . V_64 ,
V_77 * sizeof( struct V_25 ) ,
V_19 , V_21 ) ;
return - V_79 ;
}
F_21 ( & V_6 -> V_35 , V_57 ) ;
V_6 -> V_19 = V_19 ;
V_6 -> V_21 = V_21 ;
F_14 ( & V_76 , & V_6 -> free ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
F_10 ( & V_9 -> V_27 -> V_82 , V_4 -> V_8 ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 , * V_83 ;
struct V_25 * V_19 ;
T_5 V_21 ;
unsigned long V_57 ;
F_20 ( V_76 ) ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_37 ( ! F_5 ( & V_6 -> V_84 ) ) ;
F_37 ( ! F_5 ( & V_6 -> V_15 ) ) ;
F_37 ( ! F_5 ( & V_6 -> V_18 ) ) ;
F_37 ( ! F_5 ( & V_6 -> V_39 ) ) ;
F_14 ( & V_6 -> free , & V_76 ) ;
V_19 = V_6 -> V_19 ;
V_21 = V_6 -> V_21 ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
F_35 ( V_9 -> V_46 . V_64 ,
V_77 * sizeof( struct V_25 ) ,
V_19 , V_21 ) ;
F_38 (mdesc, tmp, &descs, node)
F_39 ( V_13 ) ;
F_10 ( & V_9 -> V_27 -> V_85 , V_4 -> V_8 ) ;
}
static void F_40 ( struct V_2 * V_4 )
{
}
static enum V_86
F_41 ( struct V_2 * V_4 , T_4 V_62 ,
struct V_87 * V_88 )
{
return F_42 ( V_4 , V_62 , V_88 ) ;
}
static struct V_55 *
F_43 ( struct V_2 * V_4 , T_5 V_89 , T_5 V_90 ,
T_6 V_91 , unsigned long V_57 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 = NULL ;
struct V_25 * V_19 ;
unsigned long V_92 ;
F_21 ( & V_6 -> V_35 , V_92 ) ;
if ( ! F_5 ( & V_6 -> free ) ) {
V_13 = F_6 ( & V_6 -> free , struct V_10 ,
V_16 ) ;
F_44 ( & V_13 -> V_16 ) ;
}
F_22 ( & V_6 -> V_35 , V_92 ) ;
if ( ! V_13 ) {
F_19 ( V_9 ) ;
return NULL ;
}
V_13 -> error = 0 ;
V_13 -> V_17 = 0 ;
V_19 = V_13 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_25 ) ) ;
if ( F_45 ( V_90 | V_89 | V_91 , 32 ) ) {
V_19 -> V_93 = V_94 ;
V_19 -> V_95 = V_94 ;
V_19 -> V_96 = 32 ;
V_19 -> V_97 = 32 ;
} else if ( ! V_9 -> V_26 && F_45 ( V_90 | V_89 | V_91 , 16 ) ) {
V_19 -> V_93 = V_98 ;
V_19 -> V_95 = V_98 ;
V_19 -> V_96 = 16 ;
V_19 -> V_97 = 16 ;
} else if ( F_45 ( V_90 | V_89 | V_91 , 4 ) ) {
V_19 -> V_93 = V_99 ;
V_19 -> V_95 = V_99 ;
V_19 -> V_96 = 4 ;
V_19 -> V_97 = 4 ;
} else if ( F_45 ( V_90 | V_89 | V_91 , 2 ) ) {
V_19 -> V_93 = V_100 ;
V_19 -> V_95 = V_100 ;
V_19 -> V_96 = 2 ;
V_19 -> V_97 = 2 ;
} else {
V_19 -> V_93 = V_101 ;
V_19 -> V_95 = V_101 ;
V_19 -> V_96 = 1 ;
V_19 -> V_97 = 1 ;
}
V_19 -> V_102 = V_90 ;
V_19 -> V_103 = V_89 ;
V_19 -> V_104 = V_91 ;
V_19 -> V_105 = 1 ;
V_19 -> V_106 = 1 ;
F_21 ( & V_6 -> V_35 , V_92 ) ;
F_34 ( & V_13 -> V_16 , & V_6 -> V_84 ) ;
F_22 ( & V_6 -> V_35 , V_92 ) ;
return & V_13 -> V_56 ;
}
static struct V_55 *
F_46 ( struct V_2 * V_4 , struct V_107 * V_108 ,
unsigned int V_109 , enum V_110 V_111 ,
unsigned long V_57 , void * V_112 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 = NULL ;
T_5 V_113 ;
T_1 V_114 ;
struct V_25 * V_19 ;
unsigned long V_92 ;
struct V_107 * V_115 ;
T_6 V_91 ;
int V_116 , V_59 ;
if ( V_109 != 1 )
return NULL ;
if ( ! F_47 ( V_111 ) )
return NULL ;
F_48 (sgl, sg, sg_len, i) {
F_21 ( & V_6 -> V_35 , V_92 ) ;
V_13 = F_6 ( & V_6 -> free ,
struct V_10 , V_16 ) ;
if ( ! V_13 ) {
F_22 ( & V_6 -> V_35 , V_92 ) ;
F_19 ( V_9 ) ;
return NULL ;
}
F_44 ( & V_13 -> V_16 ) ;
if ( V_111 == V_117 ) {
V_113 = V_6 -> V_118 ;
V_114 = V_6 -> V_119 ;
} else {
V_113 = V_6 -> V_120 ;
V_114 = V_6 -> V_121 ;
}
F_22 ( & V_6 -> V_35 , V_92 ) ;
if ( V_113 == 0 || V_114 == 0 )
goto V_122;
V_13 -> error = 0 ;
V_13 -> V_17 = 1 ;
V_19 = V_13 -> V_19 ;
memset ( V_19 , 0 , sizeof( struct V_25 ) ) ;
if ( ! F_45 ( F_49 ( V_115 ) , 4 ) )
goto V_122;
if ( V_111 == V_117 ) {
V_19 -> V_102 = V_113 ;
V_19 -> V_103 = F_49 ( V_115 ) ;
V_19 -> V_96 = 0 ;
V_19 -> V_97 = 4 ;
} else {
V_19 -> V_102 = F_49 ( V_115 ) ;
V_19 -> V_103 = V_113 ;
V_19 -> V_96 = 4 ;
V_19 -> V_97 = 0 ;
}
V_19 -> V_93 = V_99 ;
V_19 -> V_95 = V_99 ;
V_91 = F_50 ( V_115 ) ;
V_19 -> V_104 = V_114 * 4 ;
if ( ! F_45 ( V_91 , V_19 -> V_104 ) )
goto V_122;
V_116 = V_91 / V_19 -> V_104 ;
if ( V_116 >= 1 << 15 ) {
goto V_122;
}
V_19 -> V_105 = V_116 & 0x1ff ;
V_19 -> V_123 = V_116 >> 9 ;
V_19 -> V_106 = V_19 -> V_105 ;
V_19 -> V_124 = V_19 -> V_123 ;
V_19 -> V_22 = 0 ;
V_19 -> V_125 = 1 ;
F_21 ( & V_6 -> V_35 , V_92 ) ;
F_34 ( & V_13 -> V_16 , & V_6 -> V_84 ) ;
F_22 ( & V_6 -> V_35 , V_92 ) ;
}
return & V_13 -> V_56 ;
V_122:
F_21 ( & V_6 -> V_35 , V_92 ) ;
F_34 ( & V_13 -> V_16 , & V_6 -> free ) ;
F_22 ( & V_6 -> V_35 , V_92 ) ;
return NULL ;
}
static int F_51 ( struct V_2 * V_4 ,
struct V_126 * V_127 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_57 ;
if ( V_127 -> V_128 != V_129 ||
V_127 -> V_130 != V_129 ||
! F_45 ( V_127 -> V_131 , 4 ) ||
! F_45 ( V_127 -> V_132 , 4 ) ) {
return - V_133 ;
}
F_21 ( & V_6 -> V_35 , V_57 ) ;
V_6 -> V_118 = V_127 -> V_131 ;
V_6 -> V_119 = V_127 -> V_134 ;
V_6 -> V_120 = V_127 -> V_132 ;
V_6 -> V_121 = V_127 -> V_135 ;
if ( V_6 -> V_119 == 0 )
V_6 -> V_119 = 1 ;
if ( V_6 -> V_121 == 0 )
V_6 -> V_121 = 1 ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( V_4 ) ;
unsigned long V_57 ;
F_21 ( & V_6 -> V_35 , V_57 ) ;
F_10 ( & V_9 -> V_27 -> V_136 , V_4 -> V_8 ) ;
F_14 ( & V_6 -> V_84 , & V_6 -> free ) ;
F_14 ( & V_6 -> V_15 , & V_6 -> free ) ;
F_14 ( & V_6 -> V_18 , & V_6 -> free ) ;
F_22 ( & V_6 -> V_35 , V_57 ) ;
return 0 ;
}
static int F_53 ( struct V_137 * V_138 )
{
struct V_139 * V_140 = V_138 -> V_64 . V_141 ;
struct V_142 * V_64 = & V_138 -> V_64 ;
struct V_143 * V_46 ;
struct V_5 * V_9 ;
struct V_1 * V_6 ;
struct V_144 V_145 ;
T_7 V_146 , V_147 ;
int V_148 , V_59 ;
T_8 V_47 ;
V_9 = F_54 ( V_64 , sizeof( struct V_5 ) , V_78 ) ;
if ( ! V_9 ) {
F_25 ( V_64 , L_16 ) ;
V_148 = - V_79 ;
goto V_149;
}
V_9 -> V_40 = F_55 ( V_140 , 0 ) ;
if ( V_9 -> V_40 == V_150 ) {
F_25 ( V_64 , L_17 ) ;
V_148 = - V_133 ;
goto V_149;
}
if ( F_56 ( V_140 , L_18 ) ) {
V_9 -> V_26 = 1 ;
V_9 -> V_151 = F_55 ( V_140 , 1 ) ;
if ( V_9 -> V_151 == V_150 ) {
F_25 ( V_64 , L_17 ) ;
V_148 = - V_133 ;
goto V_152;
}
}
V_148 = F_57 ( V_140 , 0 , & V_145 ) ;
if ( V_148 ) {
F_25 ( V_64 , L_19 ) ;
goto V_153;
}
V_146 = V_145 . V_23 ;
V_147 = F_58 ( & V_145 ) ;
if ( ! F_59 ( V_64 , V_146 , V_147 , V_154 ) ) {
F_25 ( V_64 , L_20 ) ;
V_148 = - V_155 ;
goto V_153;
}
V_9 -> V_27 = F_60 ( V_64 , V_146 , V_147 ) ;
if ( ! V_9 -> V_27 ) {
F_25 ( V_64 , L_21 ) ;
V_148 = - V_79 ;
goto V_153;
}
V_9 -> V_19 = (struct V_25 * ) ( ( T_8 * ) ( V_9 -> V_27 )
+ V_156 ) ;
V_148 = F_61 ( V_9 -> V_40 , & F_16 , 0 , V_154 , V_9 ) ;
if ( V_148 ) {
F_25 ( V_64 , L_22 ) ;
V_148 = - V_133 ;
goto V_153;
}
if ( V_9 -> V_26 ) {
V_148 = F_61 ( V_9 -> V_151 , & F_16 , 0 ,
V_154 , V_9 ) ;
if ( V_148 ) {
F_25 ( V_64 , L_23 ) ;
V_148 = - V_133 ;
goto V_157;
}
}
F_62 ( & V_9 -> V_43 ) ;
V_46 = & V_9 -> V_46 ;
V_46 -> V_64 = V_64 ;
V_46 -> V_158 = F_29 ;
V_46 -> V_159 = F_36 ;
V_46 -> V_160 = F_40 ;
V_46 -> V_161 = F_41 ;
V_46 -> V_162 = F_43 ;
V_46 -> V_163 = F_46 ;
V_46 -> V_164 = F_51 ;
V_46 -> V_165 = F_52 ;
F_63 ( & V_46 -> V_7 ) ;
F_64 ( V_166 , V_46 -> V_167 ) ;
F_64 ( V_168 , V_46 -> V_167 ) ;
if ( V_9 -> V_26 )
V_47 = V_169 ;
else
V_47 = V_170 ;
for ( V_59 = 0 ; V_59 < V_47 ; V_59 ++ ) {
V_6 = & V_9 -> V_7 [ V_59 ] ;
V_6 -> V_4 . V_142 = V_46 ;
F_65 ( & V_6 -> V_4 ) ;
F_63 ( & V_6 -> free ) ;
F_63 ( & V_6 -> V_84 ) ;
F_63 ( & V_6 -> V_15 ) ;
F_63 ( & V_6 -> V_18 ) ;
F_63 ( & V_6 -> V_39 ) ;
F_62 ( & V_6 -> V_35 ) ;
F_34 ( & V_6 -> V_4 . V_139 , & V_46 -> V_7 ) ;
}
F_66 ( & V_9 -> V_52 , F_24 , ( unsigned long ) V_9 ) ;
if ( V_9 -> V_26 ) {
F_67 ( & V_9 -> V_27 -> V_171 , V_172 ) ;
F_67 ( & V_9 -> V_27 -> V_173 , V_174 ) ;
F_67 ( & V_9 -> V_27 -> V_175 , 0 ) ;
F_67 ( & V_9 -> V_27 -> V_50 , 0xFFFF ) ;
F_67 ( & V_9 -> V_27 -> V_51 , 0xFFFF ) ;
} else {
F_67 ( & V_9 -> V_27 -> V_171 , V_176 |
V_177 | V_172 ) ;
F_67 ( & V_9 -> V_27 -> V_178 , 0 ) ;
F_67 ( & V_9 -> V_27 -> V_179 , 0 ) ;
F_67 ( & V_9 -> V_27 -> V_180 , 0 ) ;
F_67 ( & V_9 -> V_27 -> V_175 , 0 ) ;
F_67 ( & V_9 -> V_27 -> V_48 , 0xFFFFFFFF ) ;
F_67 ( & V_9 -> V_27 -> V_50 , 0xFFFFFFFF ) ;
F_67 ( & V_9 -> V_27 -> V_49 , 0xFFFFFFFF ) ;
F_67 ( & V_9 -> V_27 -> V_51 , 0xFFFFFFFF ) ;
F_67 ( & V_9 -> V_27 -> V_181 , 0 ) ;
F_67 ( & V_9 -> V_27 -> V_182 , 0 ) ;
}
F_68 ( V_64 , V_9 ) ;
V_148 = F_69 ( V_46 ) ;
if ( V_148 )
goto V_183;
if ( V_64 -> V_141 ) {
V_148 = F_70 ( V_64 -> V_141 ,
V_184 , V_9 ) ;
if ( V_148 )
F_71 ( V_64 , L_24 ) ;
}
return 0 ;
V_183:
if ( V_9 -> V_26 )
F_72 ( V_9 -> V_151 , V_9 ) ;
V_157:
F_72 ( V_9 -> V_40 , V_9 ) ;
V_153:
if ( V_9 -> V_26 )
F_73 ( V_9 -> V_151 ) ;
V_152:
F_73 ( V_9 -> V_40 ) ;
V_149:
return V_148 ;
}
static int F_74 ( struct V_137 * V_138 )
{
struct V_142 * V_64 = & V_138 -> V_64 ;
struct V_5 * V_9 = F_75 ( V_64 ) ;
if ( V_64 -> V_141 )
F_76 ( V_64 -> V_141 ) ;
F_77 ( & V_9 -> V_46 ) ;
if ( V_9 -> V_26 ) {
F_72 ( V_9 -> V_151 , V_9 ) ;
F_73 ( V_9 -> V_151 ) ;
}
F_72 ( V_9 -> V_40 , V_9 ) ;
F_73 ( V_9 -> V_40 ) ;
return 0 ;
}
