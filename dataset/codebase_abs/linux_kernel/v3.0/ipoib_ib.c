struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( sizeof *V_8 , V_9 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_3 = V_3 ;
V_8 -> V_10 = 0 ;
F_3 ( & V_8 -> V_11 ) ;
V_8 -> V_8 = F_4 ( V_5 , V_7 ) ;
if ( F_5 ( V_8 -> V_8 ) ) {
F_6 ( V_8 ) ;
V_8 = NULL ;
} else
F_7 ( F_8 ( V_3 ) , L_1 , V_8 -> V_8 ) ;
return V_8 ;
}
void F_9 ( struct V_12 * V_12 )
{
struct V_1 * V_8 = F_10 ( V_12 , struct V_1 , V_11 ) ;
struct V_13 * V_14 = F_8 ( V_8 -> V_3 ) ;
unsigned long V_15 ;
F_11 ( & V_14 -> V_16 , V_15 ) ;
F_12 ( & V_8 -> V_17 , & V_14 -> V_18 ) ;
F_13 ( & V_14 -> V_16 , V_15 ) ;
}
static void F_14 ( struct V_13 * V_14 ,
T_1 V_19 [ V_20 ] )
{
if ( F_15 ( V_14 -> V_21 ) ) {
F_16 ( V_14 -> V_22 , V_19 [ 0 ] , V_23 ,
V_24 ) ;
F_17 ( V_14 -> V_22 , V_19 [ 1 ] , V_25 ,
V_24 ) ;
} else
F_16 ( V_14 -> V_22 , V_19 [ 0 ] ,
F_18 ( V_14 -> V_21 ) ,
V_24 ) ;
}
static void F_19 ( struct V_13 * V_14 ,
struct V_26 * V_27 ,
unsigned int V_28 )
{
if ( F_15 ( V_14 -> V_21 ) ) {
T_2 * V_29 = & F_20 ( V_27 ) -> V_30 [ 0 ] ;
unsigned int V_31 ;
V_27 -> V_32 += V_23 ;
V_27 -> V_33 += V_28 ;
V_31 = V_28 - V_23 ;
V_29 -> V_31 = V_31 ;
V_27 -> V_34 += V_31 ;
V_27 -> V_35 += V_31 ;
} else
F_21 ( V_27 , V_28 ) ;
}
static int F_22 ( struct V_2 * V_3 , int V_36 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_37 * V_38 ;
int V_39 ;
V_14 -> V_40 . V_41 = V_36 | V_42 ;
V_14 -> V_43 [ 0 ] . V_44 = V_14 -> V_45 [ V_36 ] . V_19 [ 0 ] ;
V_14 -> V_43 [ 1 ] . V_44 = V_14 -> V_45 [ V_36 ] . V_19 [ 1 ] ;
V_39 = F_23 ( V_14 -> V_46 , & V_14 -> V_40 , & V_38 ) ;
if ( F_24 ( V_39 ) ) {
F_25 ( V_14 , L_2 , V_36 , V_39 ) ;
F_14 ( V_14 , V_14 -> V_45 [ V_36 ] . V_19 ) ;
F_26 ( V_14 -> V_45 [ V_36 ] . V_27 ) ;
V_14 -> V_45 [ V_36 ] . V_27 = NULL ;
}
return V_39 ;
}
static struct V_26 * F_27 ( struct V_2 * V_3 , int V_36 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_26 * V_27 ;
int V_47 ;
T_1 * V_19 ;
if ( F_15 ( V_14 -> V_21 ) )
V_47 = V_23 ;
else
V_47 = F_18 ( V_14 -> V_21 ) ;
V_27 = F_28 ( V_47 + 4 ) ;
if ( F_24 ( ! V_27 ) )
return NULL ;
F_29 ( V_27 , 4 ) ;
V_19 = V_14 -> V_45 [ V_36 ] . V_19 ;
V_19 [ 0 ] = F_30 ( V_14 -> V_22 , V_27 -> V_48 , V_47 ,
V_24 ) ;
if ( F_24 ( F_31 ( V_14 -> V_22 , V_19 [ 0 ] ) ) )
goto error;
if ( F_15 ( V_14 -> V_21 ) ) {
struct V_49 * V_49 = F_32 ( V_50 ) ;
if ( ! V_49 )
goto V_51;
F_33 ( V_27 , 0 , V_49 , 0 , V_25 ) ;
V_19 [ 1 ] =
F_34 ( V_14 -> V_22 , F_20 ( V_27 ) -> V_30 [ 0 ] . V_49 ,
0 , V_25 , V_24 ) ;
if ( F_24 ( F_31 ( V_14 -> V_22 , V_19 [ 1 ] ) ) )
goto V_51;
}
V_14 -> V_45 [ V_36 ] . V_27 = V_27 ;
return V_27 ;
V_51:
F_16 ( V_14 -> V_22 , V_19 [ 0 ] , V_47 , V_24 ) ;
error:
F_26 ( V_27 ) ;
return NULL ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 ) {
if ( ! F_27 ( V_3 , V_52 ) ) {
F_25 ( V_14 , L_3 , V_52 ) ;
return - V_54 ;
}
if ( F_22 ( V_3 , V_52 ) ) {
F_25 ( V_14 , L_4 , V_52 ) ;
return - V_55 ;
}
}
return 0 ;
}
static void F_36 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
unsigned int V_41 = V_57 -> V_41 & ~ V_42 ;
struct V_26 * V_27 ;
T_1 V_19 [ V_20 ] ;
union V_58 * V_59 ;
F_37 ( V_14 , L_5 ,
V_41 , V_57 -> V_60 ) ;
if ( F_24 ( V_41 >= V_53 ) ) {
F_25 ( V_14 , L_6 ,
V_41 , V_53 ) ;
return;
}
V_27 = V_14 -> V_45 [ V_41 ] . V_27 ;
if ( F_24 ( V_57 -> V_60 != V_61 ) ) {
if ( V_57 -> V_60 != V_62 )
F_25 ( V_14 , L_7
L_8 ,
V_57 -> V_60 , V_41 , V_57 -> V_63 ) ;
F_14 ( V_14 , V_14 -> V_45 [ V_41 ] . V_19 ) ;
F_26 ( V_27 ) ;
V_14 -> V_45 [ V_41 ] . V_27 = NULL ;
return;
}
if ( V_57 -> V_64 == V_14 -> V_65 && V_57 -> V_66 == V_14 -> V_46 -> V_67 )
goto V_68;
memcpy ( V_19 , V_14 -> V_45 [ V_41 ] . V_19 ,
V_20 * sizeof *V_19 ) ;
if ( F_24 ( ! F_27 ( V_3 , V_41 ) ) ) {
++ V_3 -> V_69 . V_70 ;
goto V_68;
}
F_37 ( V_14 , L_9 ,
V_57 -> V_71 , V_57 -> V_64 ) ;
F_14 ( V_14 , V_19 ) ;
F_19 ( V_14 , V_27 , V_57 -> V_71 ) ;
V_59 = & ( (struct V_72 * ) V_27 -> V_48 ) -> V_59 ;
if ( ! ( V_57 -> V_73 & V_74 ) || V_59 -> V_75 [ 0 ] != 0xff )
V_27 -> V_76 = V_77 ;
else if ( memcmp ( V_59 , V_3 -> V_78 + 4 , sizeof( union V_58 ) ) == 0 )
V_27 -> V_76 = V_79 ;
else
V_27 -> V_76 = V_80 ;
F_38 ( V_27 , V_81 ) ;
V_27 -> V_82 = ( (struct V_83 * ) V_27 -> V_48 ) -> V_84 ;
F_39 ( V_27 ) ;
F_38 ( V_27 , V_85 ) ;
++ V_3 -> V_69 . V_86 ;
V_3 -> V_69 . V_87 += V_27 -> V_33 ;
V_27 -> V_3 = V_3 ;
if ( ( V_3 -> V_88 & V_89 ) && F_40 ( V_57 -> V_90 ) )
V_27 -> V_91 = V_92 ;
F_41 ( & V_14 -> V_93 , V_27 ) ;
V_68:
if ( F_24 ( F_22 ( V_3 , V_41 ) ) )
F_25 ( V_14 , L_10
L_11 , V_41 ) ;
}
static int F_42 ( struct V_94 * V_22 ,
struct V_95 * V_96 )
{
struct V_26 * V_27 = V_96 -> V_27 ;
T_1 * V_19 = V_96 -> V_19 ;
int V_52 ;
int V_97 ;
if ( F_43 ( V_27 ) ) {
V_19 [ 0 ] = F_30 ( V_22 , V_27 -> V_48 , F_43 ( V_27 ) ,
V_98 ) ;
if ( F_24 ( F_31 ( V_22 , V_19 [ 0 ] ) ) )
return - V_55 ;
V_97 = 1 ;
} else
V_97 = 0 ;
for ( V_52 = 0 ; V_52 < F_20 ( V_27 ) -> V_99 ; ++ V_52 ) {
T_2 * V_29 = & F_20 ( V_27 ) -> V_30 [ V_52 ] ;
V_19 [ V_52 + V_97 ] = F_34 ( V_22 , V_29 -> V_49 ,
V_29 -> V_100 , V_29 -> V_31 ,
V_98 ) ;
if ( F_24 ( F_31 ( V_22 , V_19 [ V_52 + V_97 ] ) ) )
goto V_51;
}
return 0 ;
V_51:
for (; V_52 > 0 ; -- V_52 ) {
T_2 * V_29 = & F_20 ( V_27 ) -> V_30 [ V_52 - 1 ] ;
F_17 ( V_22 , V_19 [ V_52 - ! V_97 ] , V_29 -> V_31 , V_98 ) ;
}
if ( V_97 )
F_16 ( V_22 , V_19 [ 0 ] , F_43 ( V_27 ) , V_98 ) ;
return - V_55 ;
}
static void F_44 ( struct V_94 * V_22 ,
struct V_95 * V_96 )
{
struct V_26 * V_27 = V_96 -> V_27 ;
T_1 * V_19 = V_96 -> V_19 ;
int V_52 ;
int V_97 ;
if ( F_43 ( V_27 ) ) {
F_16 ( V_22 , V_19 [ 0 ] , F_43 ( V_27 ) , V_98 ) ;
V_97 = 1 ;
} else
V_97 = 0 ;
for ( V_52 = 0 ; V_52 < F_20 ( V_27 ) -> V_99 ; ++ V_52 ) {
T_2 * V_29 = & F_20 ( V_27 ) -> V_30 [ V_52 ] ;
F_17 ( V_22 , V_19 [ V_52 + V_97 ] , V_29 -> V_31 ,
V_98 ) ;
}
}
static void F_45 ( struct V_2 * V_3 , struct V_56 * V_57 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
unsigned int V_41 = V_57 -> V_41 ;
struct V_95 * V_96 ;
F_37 ( V_14 , L_12 ,
V_41 , V_57 -> V_60 ) ;
if ( F_24 ( V_41 >= V_101 ) ) {
F_25 ( V_14 , L_13 ,
V_41 , V_101 ) ;
return;
}
V_96 = & V_14 -> V_102 [ V_41 ] ;
F_44 ( V_14 -> V_22 , V_96 ) ;
++ V_3 -> V_69 . V_103 ;
V_3 -> V_69 . V_104 += V_96 -> V_27 -> V_33 ;
F_26 ( V_96 -> V_27 ) ;
++ V_14 -> V_105 ;
if ( F_24 ( -- V_14 -> V_106 == V_101 >> 1 ) &&
F_46 ( V_3 ) &&
F_47 ( V_107 , & V_14 -> V_15 ) )
F_48 ( V_3 ) ;
if ( V_57 -> V_60 != V_61 &&
V_57 -> V_60 != V_62 )
F_25 ( V_14 , L_14
L_8 ,
V_57 -> V_60 , V_41 , V_57 -> V_63 ) ;
}
static int F_49 ( struct V_13 * V_14 )
{
int V_108 , V_52 ;
V_108 = F_50 ( V_14 -> V_109 , V_110 , V_14 -> V_111 ) ;
for ( V_52 = 0 ; V_52 < V_108 ; ++ V_52 )
F_45 ( V_14 -> V_3 , V_14 -> V_111 + V_52 ) ;
return V_108 == V_110 ;
}
int F_51 ( struct V_112 * V_93 , int V_113 )
{
struct V_13 * V_14 = F_10 ( V_93 , struct V_13 , V_93 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
int V_114 ;
int V_115 ;
int V_108 , V_52 ;
V_114 = 0 ;
V_116:
while ( V_114 < V_113 ) {
int V_117 = ( V_113 - V_114 ) ;
V_115 = F_52 ( V_118 , V_117 ) ;
V_108 = F_50 ( V_14 -> V_119 , V_115 , V_14 -> V_120 ) ;
for ( V_52 = 0 ; V_52 < V_108 ; V_52 ++ ) {
struct V_56 * V_57 = V_14 -> V_120 + V_52 ;
if ( V_57 -> V_41 & V_42 ) {
++ V_114 ;
if ( V_57 -> V_41 & V_121 )
F_53 ( V_3 , V_57 ) ;
else
F_36 ( V_3 , V_57 ) ;
} else
F_54 ( V_14 -> V_3 , V_57 ) ;
}
if ( V_108 != V_115 )
break;
}
if ( V_114 < V_113 ) {
F_55 ( V_93 ) ;
if ( F_24 ( F_56 ( V_14 -> V_119 ,
V_122 |
V_123 ) ) &&
F_57 ( V_93 ) )
goto V_116;
}
return V_114 ;
}
void F_58 ( struct V_124 * V_125 , void * V_126 )
{
struct V_2 * V_3 = V_126 ;
struct V_13 * V_14 = F_8 ( V_3 ) ;
F_59 ( & V_14 -> V_93 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
F_61 ( V_3 ) ;
while ( F_49 ( V_14 ) )
;
if ( F_46 ( V_3 ) )
F_62 ( & V_14 -> V_127 , V_128 + 1 ) ;
F_63 ( V_3 ) ;
}
void F_64 ( struct V_124 * V_125 , void * V_126 )
{
struct V_13 * V_14 = F_8 ( V_126 ) ;
F_62 ( & V_14 -> V_127 , V_128 ) ;
}
static inline int F_65 ( struct V_13 * V_14 ,
unsigned int V_41 ,
struct V_129 * V_130 , T_3 V_131 ,
struct V_95 * V_96 ,
void * V_132 , int V_133 )
{
struct V_134 * V_38 ;
int V_52 , V_97 ;
struct V_26 * V_27 = V_96 -> V_27 ;
T_2 * V_30 = F_20 ( V_27 ) -> V_30 ;
int V_99 = F_20 ( V_27 ) -> V_99 ;
T_1 * V_19 = V_96 -> V_19 ;
if ( F_43 ( V_27 ) ) {
V_14 -> V_135 [ 0 ] . V_44 = V_19 [ 0 ] ;
V_14 -> V_135 [ 0 ] . V_28 = F_43 ( V_27 ) ;
V_97 = 1 ;
} else
V_97 = 0 ;
for ( V_52 = 0 ; V_52 < V_99 ; ++ V_52 ) {
V_14 -> V_135 [ V_52 + V_97 ] . V_44 = V_19 [ V_52 + V_97 ] ;
V_14 -> V_135 [ V_52 + V_97 ] . V_28 = V_30 [ V_52 ] . V_31 ;
}
V_14 -> V_136 . V_137 = V_99 + V_97 ;
V_14 -> V_136 . V_41 = V_41 ;
V_14 -> V_136 . V_138 . V_139 . V_140 = V_131 ;
V_14 -> V_136 . V_138 . V_139 . V_8 = V_130 ;
if ( V_132 ) {
V_14 -> V_136 . V_138 . V_139 . V_141 = F_20 ( V_27 ) -> V_142 ;
V_14 -> V_136 . V_138 . V_139 . V_143 = V_132 ;
V_14 -> V_136 . V_138 . V_139 . V_133 = V_133 ;
V_14 -> V_136 . V_144 = V_145 ;
} else
V_14 -> V_136 . V_144 = V_146 ;
return F_66 ( V_14 -> V_46 , & V_14 -> V_136 , & V_38 ) ;
}
void F_67 ( struct V_2 * V_3 , struct V_26 * V_27 ,
struct V_1 * V_130 , T_3 V_131 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_95 * V_96 ;
int V_133 , V_147 ;
void * V_148 ;
if ( F_68 ( V_27 ) ) {
V_133 = F_69 ( V_27 ) + F_70 ( V_27 ) ;
V_148 = V_27 -> V_48 ;
if ( F_24 ( ! F_38 ( V_27 , V_133 ) ) ) {
F_25 ( V_14 , L_15 ) ;
++ V_3 -> V_69 . V_149 ;
++ V_3 -> V_69 . V_150 ;
F_26 ( V_27 ) ;
return;
}
} else {
if ( F_24 ( V_27 -> V_33 > V_14 -> V_151 + V_85 ) ) {
F_25 ( V_14 , L_16 ,
V_27 -> V_33 , V_14 -> V_151 + V_85 ) ;
++ V_3 -> V_69 . V_149 ;
++ V_3 -> V_69 . V_150 ;
F_71 ( V_3 , V_27 , V_14 -> V_151 ) ;
return;
}
V_148 = NULL ;
V_133 = 0 ;
}
F_37 ( V_14 , L_17 ,
V_27 -> V_33 , V_130 , V_131 ) ;
V_96 = & V_14 -> V_102 [ V_14 -> V_152 & ( V_101 - 1 ) ] ;
V_96 -> V_27 = V_27 ;
if ( F_24 ( F_42 ( V_14 -> V_22 , V_96 ) ) ) {
++ V_3 -> V_69 . V_150 ;
F_26 ( V_27 ) ;
return;
}
if ( V_27 -> V_91 == V_153 )
V_14 -> V_136 . V_154 |= V_155 ;
else
V_14 -> V_136 . V_154 &= ~ V_155 ;
if ( ++ V_14 -> V_106 == V_101 ) {
F_7 ( V_14 , L_18 ) ;
if ( F_56 ( V_14 -> V_109 , V_122 ) )
F_25 ( V_14 , L_19 ) ;
F_72 ( V_3 ) ;
}
V_147 = F_65 ( V_14 , V_14 -> V_152 & ( V_101 - 1 ) ,
V_130 -> V_8 , V_131 , V_96 , V_148 , V_133 ) ;
if ( F_24 ( V_147 ) ) {
F_25 ( V_14 , L_20 , V_147 ) ;
++ V_3 -> V_69 . V_150 ;
-- V_14 -> V_106 ;
F_44 ( V_14 -> V_22 , V_96 ) ;
F_26 ( V_27 ) ;
if ( F_46 ( V_3 ) )
F_48 ( V_3 ) ;
} else {
V_3 -> V_156 = V_128 ;
V_130 -> V_10 = V_14 -> V_152 ;
++ V_14 -> V_152 ;
F_73 ( V_27 ) ;
}
if ( F_24 ( V_14 -> V_106 > V_110 ) )
while ( F_49 ( V_14 ) )
;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_1 * V_8 , * V_157 ;
F_75 ( V_158 ) ;
unsigned long V_15 ;
F_76 ( V_3 ) ;
F_11 ( & V_14 -> V_16 , V_15 ) ;
F_77 (ah, tah, &priv->dead_ahs, list)
if ( ( int ) V_14 -> V_105 - ( int ) V_8 -> V_10 >= 0 ) {
F_78 ( & V_8 -> V_17 ) ;
F_79 ( V_8 -> V_8 ) ;
F_6 ( V_8 ) ;
}
F_13 ( & V_14 -> V_16 , V_15 ) ;
F_80 ( V_3 ) ;
}
void F_81 ( struct V_159 * V_160 )
{
struct V_13 * V_14 =
F_10 ( V_160 , struct V_13 , V_161 . V_160 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
F_74 ( V_3 ) ;
if ( ! F_47 ( V_162 , & V_14 -> V_15 ) )
F_82 ( V_163 , & V_14 -> V_161 ,
F_83 ( V_164 ) ) ;
}
static void F_84 ( unsigned long V_165 )
{
F_60 ( (struct V_2 * ) V_165 ) ;
}
int F_85 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
int V_39 ;
if ( F_86 ( V_14 -> V_22 , V_14 -> V_166 , V_14 -> V_167 , & V_14 -> V_168 ) ) {
F_25 ( V_14 , L_21 , V_14 -> V_167 ) ;
F_87 ( V_169 , & V_14 -> V_15 ) ;
return - 1 ;
}
F_88 ( V_169 , & V_14 -> V_15 ) ;
V_39 = F_89 ( V_3 ) ;
if ( V_39 ) {
F_25 ( V_14 , L_22 , V_39 ) ;
return - 1 ;
}
V_39 = F_35 ( V_3 ) ;
if ( V_39 ) {
F_25 ( V_14 , L_23 , V_39 ) ;
F_90 ( V_3 , 1 ) ;
return - 1 ;
}
V_39 = F_91 ( V_3 ) ;
if ( V_39 ) {
F_25 ( V_14 , L_24 , V_39 ) ;
F_90 ( V_3 , 1 ) ;
return - 1 ;
}
F_87 ( V_162 , & V_14 -> V_15 ) ;
F_82 ( V_163 , & V_14 -> V_161 ,
F_83 ( V_164 ) ) ;
if ( ! F_92 ( V_170 , & V_14 -> V_15 ) )
F_93 ( & V_14 -> V_93 ) ;
return 0 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
T_4 V_168 = 0 ;
if ( F_86 ( V_14 -> V_22 , V_14 -> V_166 , V_14 -> V_167 , & V_168 ) )
F_87 ( V_169 , & V_14 -> V_15 ) ;
else
F_88 ( V_169 , & V_14 -> V_15 ) ;
}
int F_95 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
F_94 ( V_3 ) ;
if ( ! F_47 ( V_169 , & V_14 -> V_15 ) ) {
F_7 ( V_14 , L_25 ) ;
return 0 ;
}
F_88 ( V_171 , & V_14 -> V_15 ) ;
return F_96 ( V_3 ) ;
}
int F_97 ( struct V_2 * V_3 , int V_172 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
F_7 ( V_14 , L_26 ) ;
F_87 ( V_171 , & V_14 -> V_15 ) ;
F_98 ( V_3 ) ;
if ( ! F_47 ( V_169 , & V_14 -> V_15 ) ) {
F_99 ( & V_173 ) ;
F_88 ( V_174 , & V_14 -> V_15 ) ;
F_100 ( & V_14 -> V_175 ) ;
F_101 ( & V_173 ) ;
if ( V_172 )
F_102 ( V_163 ) ;
}
F_103 ( V_3 , V_172 ) ;
F_104 ( V_3 ) ;
F_105 ( V_3 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
int V_176 = 0 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 )
if ( V_14 -> V_45 [ V_52 ] . V_27 )
++ V_176 ;
return V_176 ;
}
void F_107 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
int V_52 , V_108 ;
F_108 () ;
do {
V_108 = F_50 ( V_14 -> V_119 , V_118 , V_14 -> V_120 ) ;
for ( V_52 = 0 ; V_52 < V_108 ; ++ V_52 ) {
if ( V_14 -> V_120 [ V_52 ] . V_60 == V_61 )
V_14 -> V_120 [ V_52 ] . V_60 = V_62 ;
if ( V_14 -> V_120 [ V_52 ] . V_41 & V_42 ) {
if ( V_14 -> V_120 [ V_52 ] . V_41 & V_121 )
F_53 ( V_3 , V_14 -> V_120 + V_52 ) ;
else
F_36 ( V_3 , V_14 -> V_120 + V_52 ) ;
} else
F_54 ( V_3 , V_14 -> V_120 + V_52 ) ;
}
} while ( V_108 == V_118 );
while ( F_49 ( V_14 ) )
;
F_109 () ;
}
int F_90 ( struct V_2 * V_3 , int V_172 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_177 V_178 ;
unsigned long V_179 ;
struct V_95 * V_96 ;
int V_52 ;
if ( F_110 ( V_170 , & V_14 -> V_15 ) )
F_111 ( & V_14 -> V_93 ) ;
F_112 ( V_3 ) ;
V_178 . V_180 = V_181 ;
if ( F_113 ( V_14 -> V_46 , & V_178 , V_182 ) )
F_25 ( V_14 , L_27 ) ;
V_179 = V_128 ;
while ( V_14 -> V_152 != V_14 -> V_105 || F_106 ( V_3 ) ) {
if ( F_114 ( V_128 , V_179 + 5 * V_164 ) ) {
F_25 ( V_14 , L_28 ,
V_14 -> V_152 - V_14 -> V_105 , F_106 ( V_3 ) ) ;
while ( ( int ) V_14 -> V_105 - ( int ) V_14 -> V_152 < 0 ) {
V_96 = & V_14 -> V_102 [ V_14 -> V_105 &
( V_101 - 1 ) ] ;
F_44 ( V_14 -> V_22 , V_96 ) ;
F_26 ( V_96 -> V_27 ) ;
++ V_14 -> V_105 ;
-- V_14 -> V_106 ;
}
for ( V_52 = 0 ; V_52 < V_53 ; ++ V_52 ) {
struct V_183 * V_184 ;
V_184 = & V_14 -> V_45 [ V_52 ] ;
if ( ! V_184 -> V_27 )
continue;
F_14 ( V_14 ,
V_14 -> V_45 [ V_52 ] . V_19 ) ;
F_26 ( V_184 -> V_27 ) ;
V_184 -> V_27 = NULL ;
}
goto V_185;
}
F_107 ( V_3 ) ;
F_115 ( 1 ) ;
}
F_7 ( V_14 , L_29 ) ;
V_185:
F_116 ( & V_14 -> V_127 ) ;
V_178 . V_180 = V_186 ;
if ( F_113 ( V_14 -> V_46 , & V_178 , V_182 ) )
F_25 ( V_14 , L_30 ) ;
F_88 ( V_162 , & V_14 -> V_15 ) ;
F_100 ( & V_14 -> V_161 ) ;
if ( V_172 )
F_102 ( V_163 ) ;
V_179 = V_128 ;
while ( ! F_117 ( & V_14 -> V_18 ) ) {
F_74 ( V_3 ) ;
if ( F_114 ( V_128 , V_179 + V_164 ) ) {
F_25 ( V_14 , L_31 ) ;
break;
}
F_115 ( 1 ) ;
}
F_56 ( V_14 -> V_119 , V_122 ) ;
return 0 ;
}
int F_118 ( struct V_2 * V_3 , struct V_94 * V_22 , int V_166 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
V_14 -> V_22 = V_22 ;
V_14 -> V_166 = V_166 ;
V_14 -> V_46 = NULL ;
if ( F_119 ( V_3 , V_22 ) ) {
F_120 ( V_187 L_32 , V_22 -> V_188 ) ;
return - V_189 ;
}
F_121 ( & V_14 -> V_127 , F_84 ,
( unsigned long ) V_3 ) ;
if ( V_3 -> V_15 & V_190 ) {
if ( F_85 ( V_3 ) ) {
F_122 ( V_3 ) ;
return - V_189 ;
}
}
return 0 ;
}
static void F_123 ( struct V_13 * V_14 ,
enum V_191 V_192 )
{
struct V_13 * V_193 ;
struct V_2 * V_3 = V_14 -> V_3 ;
T_4 V_194 ;
F_99 ( & V_14 -> V_195 ) ;
F_124 (cpriv, &priv->child_intfs, list)
F_123 ( V_193 , V_192 ) ;
F_101 ( & V_14 -> V_195 ) ;
if ( ! F_47 ( V_170 , & V_14 -> V_15 ) ) {
F_7 ( V_14 , L_33 ) ;
return;
}
if ( ! F_47 ( V_107 , & V_14 -> V_15 ) ) {
F_7 ( V_14 , L_34 ) ;
return;
}
if ( V_192 == V_196 ) {
if ( F_86 ( V_14 -> V_22 , V_14 -> V_166 , V_14 -> V_167 , & V_194 ) ) {
F_87 ( V_169 , & V_14 -> V_15 ) ;
F_97 ( V_3 , 0 ) ;
F_90 ( V_3 , 0 ) ;
if ( F_125 ( V_3 ) )
return;
}
if ( F_92 ( V_169 , & V_14 -> V_15 ) &&
V_194 == V_14 -> V_168 ) {
F_7 ( V_14 , L_35 ) ;
return;
}
V_14 -> V_168 = V_194 ;
}
if ( V_192 == V_197 ) {
F_126 ( V_3 ) ;
F_104 ( V_3 ) ;
}
if ( V_192 >= V_198 )
F_97 ( V_3 , 0 ) ;
if ( V_192 == V_196 ) {
F_90 ( V_3 , 0 ) ;
F_85 ( V_3 ) ;
}
if ( F_47 ( V_107 , & V_14 -> V_15 ) ) {
if ( V_192 >= V_198 )
F_95 ( V_3 ) ;
F_127 ( & V_14 -> V_199 ) ;
}
}
void F_128 ( struct V_159 * V_160 )
{
struct V_13 * V_14 =
F_10 ( V_160 , struct V_13 , V_200 ) ;
F_123 ( V_14 , V_197 ) ;
}
void F_129 ( struct V_159 * V_160 )
{
struct V_13 * V_14 =
F_10 ( V_160 , struct V_13 , V_201 ) ;
F_123 ( V_14 , V_198 ) ;
}
void F_130 ( struct V_159 * V_160 )
{
struct V_13 * V_14 =
F_10 ( V_160 , struct V_13 , V_202 ) ;
F_123 ( V_14 , V_196 ) ;
}
void F_131 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
F_7 ( V_14 , L_36 ) ;
F_103 ( V_3 , 1 ) ;
F_104 ( V_3 ) ;
F_122 ( V_3 ) ;
}
void F_132 ( struct V_159 * V_160 )
{
struct V_13 * V_14 =
F_10 ( V_160 , struct V_13 , V_175 . V_160 ) ;
struct V_2 * V_3 = V_14 -> V_3 ;
F_94 ( V_3 ) ;
if ( F_47 ( V_169 , & V_14 -> V_15 ) )
F_133 ( V_3 ) ;
else {
F_99 ( & V_173 ) ;
if ( ! F_47 ( V_174 , & V_14 -> V_15 ) )
F_82 ( V_163 ,
& V_14 -> V_175 ,
V_164 ) ;
F_101 ( & V_173 ) ;
}
}
int F_125 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
F_94 ( V_3 ) ;
if ( ! F_47 ( V_169 , & V_14 -> V_15 ) ) {
F_99 ( & V_173 ) ;
F_87 ( V_174 , & V_14 -> V_15 ) ;
F_82 ( V_163 ,
& V_14 -> V_175 ,
V_164 ) ;
F_101 ( & V_173 ) ;
return 1 ;
}
return 0 ;
}
