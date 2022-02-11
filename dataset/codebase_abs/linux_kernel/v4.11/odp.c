static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 = V_2 -> V_6 ;
return V_5 && V_5 -> V_4 == V_4 ;
}
static struct V_1 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = V_2 -> V_6 , * V_4 = V_5 -> V_4 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
struct V_11 * V_12 ;
F_3 ( & V_8 -> V_13 ) ;
while ( 1 ) {
V_12 = F_4 ( & V_2 -> V_14 . V_12 ) ;
if ( ! V_12 )
goto V_15;
V_2 = F_5 ( V_12 , struct V_1 , V_14 . V_12 ) ;
if ( F_1 ( V_2 , V_4 ) )
goto V_16;
}
V_15:
V_2 = NULL ;
V_16:
F_6 ( & V_8 -> V_13 ) ;
return V_2 ;
}
static struct V_1 * F_7 ( struct V_7 * V_8 ,
T_1 V_17 , T_1 V_18 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_3 ( & V_8 -> V_13 ) ;
V_2 = F_8 ( & V_8 -> V_19 , V_17 , V_18 ) ;
if ( ! V_2 )
goto V_16;
while ( 1 ) {
if ( F_1 ( V_2 , V_4 ) )
goto V_16;
V_12 = F_4 ( & V_2 -> V_14 . V_12 ) ;
if ( ! V_12 )
goto V_15;
V_2 = F_5 ( V_12 , struct V_1 , V_14 . V_12 ) ;
if ( F_9 ( V_2 -> V_9 ) > V_17 + V_18 )
goto V_15;
}
V_15:
V_2 = NULL ;
V_16:
F_6 ( & V_8 -> V_13 ) ;
return V_2 ;
}
void F_10 ( struct V_20 * V_21 , T_2 V_22 ,
T_2 V_23 , struct V_3 * V_5 , int V_24 )
{
struct V_25 * V_26 = V_5 -> V_27 . V_26 ;
struct V_7 * V_8 = V_26 -> V_28 -> V_10 ;
struct V_29 * V_30 = F_11 ( V_26 -> V_31 ) ;
struct V_1 * V_2 ;
unsigned long V_32 ;
int V_33 ;
if ( V_24 & V_34 ) {
for ( V_33 = 0 ; V_33 < V_23 ; V_33 ++ , V_21 ++ ) {
V_21 -> V_35 = F_12 ( V_36 ) ;
V_21 -> V_37 = F_12 ( V_30 -> V_38 ) ;
V_21 -> V_32 = 0 ;
}
return;
}
V_2 = F_7 ( V_8 , V_22 * V_36 ,
V_23 * V_36 , V_5 ) ;
for ( V_33 = 0 ; V_33 < V_23 ; V_33 ++ , V_21 ++ ) {
V_21 -> V_35 = F_12 ( V_36 ) ;
V_32 = ( V_22 + V_33 ) * V_36 ;
if ( V_2 && V_2 -> V_9 -> V_39 == V_32 ) {
struct V_3 * V_40 = V_2 -> V_6 ;
V_21 -> V_37 = F_12 ( V_40 -> V_27 . V_41 ) ;
V_2 = F_2 ( V_2 ) ;
} else {
V_21 -> V_37 = F_12 ( V_30 -> V_38 ) ;
}
F_13 ( V_30 , L_1 ,
V_33 , V_32 , F_14 ( V_21 -> V_37 ) ) ;
}
}
static void F_15 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_16 ( V_43 , struct V_1 , V_43 ) ;
int V_44 = F_9 ( V_2 -> V_9 ) >> V_45 ;
struct V_3 * V_5 = V_2 -> V_6 , * V_46 = V_5 -> V_4 ;
V_5 -> V_4 = NULL ;
F_17 ( & V_5 -> V_30 -> V_47 ) ;
if ( ! F_18 ( V_2 -> V_48 ) ) {
V_5 -> V_4 = V_46 ;
if ( F_19 ( & V_46 -> V_49 ) )
F_20 ( & V_46 -> V_50 ) ;
return;
}
F_21 ( V_2 -> V_9 ) ;
if ( V_46 -> V_51 )
F_22 ( V_46 , V_44 , 1 , 0 ,
V_52 |
V_53 ) ;
F_23 ( V_5 -> V_30 , V_5 ) ;
if ( F_19 ( & V_46 -> V_49 ) )
F_20 ( & V_46 -> V_50 ) ;
}
void F_24 ( struct V_54 * V_9 , unsigned long V_17 ,
unsigned long V_16 )
{
struct V_3 * V_5 ;
const T_1 V_55 = ( V_56 /
sizeof( struct V_57 ) ) - 1 ;
T_1 V_44 = 0 , V_58 = 0 ;
int V_59 = 0 ;
T_1 V_60 ;
if ( ! V_9 || ! V_9 -> V_61 ) {
F_25 ( L_2 ) ;
return;
}
V_5 = V_9 -> V_61 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_27 . V_26 )
return;
V_17 = F_26 ( T_1 , F_9 ( V_9 ) , V_17 ) ;
V_16 = F_27 ( T_1 , F_28 ( V_9 ) , V_16 ) ;
for ( V_60 = V_17 ; V_60 < V_16 ; V_60 += ( T_1 ) V_9 -> V_62 ) {
V_44 = ( V_60 - F_9 ( V_9 ) ) / V_63 ;
if ( V_9 -> V_61 -> V_64 [ V_44 ] &
( V_65 | V_66 ) ) {
if ( ! V_59 ) {
V_58 = V_44 ;
V_59 = 1 ;
}
} else {
T_1 V_67 = V_44 & V_55 ;
if ( V_59 && V_67 == 0 ) {
F_22 ( V_5 , V_58 ,
V_44 - V_58 ,
V_68 ,
V_34 |
V_53 ) ;
V_59 = 0 ;
}
}
}
if ( V_59 )
F_22 ( V_5 , V_58 ,
V_44 - V_58 + 1 ,
V_68 ,
V_34 |
V_53 ) ;
F_29 ( V_9 , V_17 , V_16 ) ;
if ( F_30 ( ! V_9 -> V_69 && V_5 -> V_4 &&
! V_9 -> V_61 -> V_48 ) ) {
F_31 ( V_9 -> V_61 -> V_48 , 1 ) ;
F_32 ( & V_5 -> V_4 -> V_49 ) ;
F_33 ( & V_9 -> V_61 -> V_43 ) ;
}
}
void F_34 ( struct V_29 * V_30 )
{
struct V_70 * V_71 = & V_30 -> V_72 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
if ( ! F_35 ( V_30 -> V_73 , V_74 ) )
return;
V_71 -> V_75 = V_76 ;
if ( F_35 ( V_30 -> V_73 , V_77 ) )
V_30 -> V_78 = V_79 ;
else
V_30 -> V_78 = F_36 ( V_80 + V_68 ) ;
if ( F_37 ( V_30 -> V_73 , V_81 . V_82 ) )
V_71 -> V_83 . V_81 |= V_84 ;
if ( F_37 ( V_30 -> V_73 , V_85 . V_82 ) )
V_71 -> V_83 . V_85 |= V_84 ;
if ( F_37 ( V_30 -> V_73 , V_85 . V_86 ) )
V_71 -> V_83 . V_85 |= V_87 ;
if ( F_37 ( V_30 -> V_73 , V_85 . V_88 ) )
V_71 -> V_83 . V_85 |= V_89 ;
if ( F_37 ( V_30 -> V_73 , V_85 . V_90 ) )
V_71 -> V_83 . V_85 |= V_91 ;
if ( F_37 ( V_30 -> V_73 , V_85 . V_92 ) )
V_71 -> V_83 . V_85 |= V_93 ;
if ( F_35 ( V_30 -> V_73 , V_94 ) &&
F_35 ( V_30 -> V_73 , V_38 ) &&
F_35 ( V_30 -> V_73 , V_77 ) )
V_71 -> V_75 |= V_95 ;
return;
}
static struct V_3 * F_38 ( struct V_29 * V_30 ,
T_3 V_37 )
{
T_3 V_96 = F_39 ( V_37 ) ;
struct V_97 * V_98 = F_40 ( V_30 -> V_73 , V_96 ) ;
struct V_3 * V_5 ;
if ( ! V_98 || V_98 -> V_37 != V_37 || V_98 -> type != V_99 )
return NULL ;
V_5 = F_16 ( V_98 , struct V_3 , V_98 ) ;
if ( ! V_5 -> V_51 )
return NULL ;
return F_16 ( V_98 , struct V_3 , V_98 ) ;
}
static void F_41 ( struct V_29 * V_30 ,
struct V_100 * V_101 ,
int error )
{
int V_102 = V_101 -> V_103 == V_104 ?
V_101 -> V_105 . V_102 : V_101 -> V_106 ;
int V_107 = F_42 ( V_30 -> V_73 ,
V_101 -> V_106 ,
V_102 ,
V_101 -> type ,
error ) ;
if ( V_107 )
F_43 ( V_30 , L_3 ,
V_102 ) ;
}
static struct V_3 * F_44 ( struct V_25 * V_26 ,
struct V_54 * V_9 ,
bool V_108 , int V_109 )
{
struct V_29 * V_30 = F_11 ( V_26 -> V_31 ) ;
struct V_3 * V_5 ;
int V_110 ;
V_5 = F_45 ( V_30 , V_108 ? V_111 :
V_112 ) ;
if ( F_46 ( V_5 ) )
return V_5 ;
V_5 -> V_27 . V_26 = V_26 ;
V_5 -> V_30 = V_30 ;
V_5 -> V_109 = V_109 ;
V_5 -> V_98 . V_113 = 0 ;
V_5 -> V_9 = V_9 ;
if ( V_108 ) {
V_110 = F_22 ( V_5 , 0 ,
V_114 ,
V_115 ,
V_52 |
V_34 |
V_116 ) ;
} else {
V_110 = F_22 ( V_5 , 0 ,
V_117 ,
V_68 ,
V_34 |
V_116 |
V_53 ) ;
}
if ( V_110 )
goto V_118;
V_5 -> V_27 . V_41 = V_5 -> V_98 . V_37 ;
V_5 -> V_27 . V_119 = V_5 -> V_98 . V_37 ;
V_5 -> V_51 = 1 ;
F_13 ( V_30 , L_4 ,
V_5 -> V_98 . V_37 , V_30 -> V_73 , V_5 ) ;
return V_5 ;
V_118:
F_43 ( V_30 , L_5 , V_110 ) ;
F_23 ( V_30 , V_5 ) ;
return F_47 ( V_110 ) ;
}
static struct V_1 * F_48 ( struct V_3 * V_5 ,
T_1 V_120 , T_2 V_121 )
{
struct V_7 * V_8 = V_5 -> V_27 . V_26 -> V_28 -> V_10 ;
struct V_29 * V_30 = F_11 ( V_5 -> V_27 . V_26 -> V_31 ) ;
struct V_1 * V_2 , * V_122 = NULL ;
T_1 V_60 = V_120 & V_123 ;
int V_23 = 0 , V_124 = 0 , V_107 ;
struct V_3 * V_40 ;
struct V_54 * V_9 ;
F_49 ( & V_5 -> V_9 -> V_61 -> V_125 ) ;
V_2 = F_7 ( V_8 , V_60 , 1 , V_5 ) ;
F_13 ( V_30 , L_6 ,
V_120 , V_121 , V_60 , V_2 ) ;
V_126:
if ( F_50 ( V_2 ) ) {
if ( V_23 )
V_23 ++ ;
} else {
V_9 = F_51 ( V_8 , V_60 , V_36 ) ;
if ( F_46 ( V_9 ) ) {
F_52 ( & V_5 -> V_9 -> V_61 -> V_125 ) ;
return F_53 ( V_9 ) ;
}
V_40 = F_44 ( V_5 -> V_27 . V_26 , V_9 , 0 , V_5 -> V_109 ) ;
if ( F_46 ( V_40 ) ) {
F_52 ( & V_5 -> V_9 -> V_61 -> V_125 ) ;
F_21 ( V_9 ) ;
return F_53 ( V_40 ) ;
}
V_2 = V_9 -> V_61 ;
V_2 -> V_6 = V_40 ;
V_40 -> V_9 = V_9 ;
V_40 -> V_98 . V_113 = V_60 ;
V_40 -> V_4 = V_5 ;
F_54 ( & V_2 -> V_43 , F_15 ) ;
if ( ! V_23 )
V_124 = V_60 >> V_45 ;
V_23 ++ ;
}
V_2 -> V_48 = 0 ;
if ( F_50 ( ! V_122 ) )
V_122 = V_2 ;
V_60 += V_36 ;
if ( F_30 ( V_60 < V_120 + V_121 ) ) {
V_2 = F_2 ( V_2 ) ;
if ( V_2 && V_2 -> V_9 -> V_39 != V_60 )
V_2 = NULL ;
goto V_126;
}
if ( F_30 ( V_23 ) ) {
V_107 = F_22 ( V_5 , V_124 , V_23 , 0 ,
V_52 |
V_53 ) ;
if ( V_107 ) {
F_43 ( V_30 , L_7 ) ;
V_122 = F_47 ( V_107 ) ;
}
}
F_52 ( & V_5 -> V_9 -> V_61 -> V_125 ) ;
return V_122 ;
}
struct V_3 * F_55 ( struct V_127 * V_26 ,
int V_109 )
{
struct V_7 * V_8 = V_26 -> V_128 . V_28 -> V_10 ;
struct V_3 * V_46 ;
struct V_54 * V_9 ;
V_9 = F_56 ( V_8 , 0 , 0 , V_129 , 0 ) ;
if ( F_46 ( V_9 ) )
return F_53 ( V_9 ) ;
V_46 = F_44 ( & V_26 -> V_128 , V_9 , 1 , V_109 ) ;
if ( F_46 ( V_46 ) ) {
F_21 ( V_9 ) ;
return F_53 ( V_46 ) ;
}
V_46 -> V_9 = V_9 ;
F_57 ( & V_46 -> V_50 ) ;
F_58 ( & V_46 -> V_49 , 0 ) ;
return V_46 ;
}
static int F_59 ( struct V_54 * V_9 , T_1 V_17 ,
T_1 V_16 , void * V_130 )
{
struct V_3 * V_5 = V_9 -> V_61 -> V_6 , * V_46 = V_130 ;
if ( V_5 -> V_4 != V_46 )
return 0 ;
F_29 ( V_9 ,
F_9 ( V_9 ) ,
F_28 ( V_9 ) ) ;
if ( V_9 -> V_61 -> V_48 )
return 0 ;
F_31 ( V_9 -> V_61 -> V_48 , 1 ) ;
F_32 ( & V_46 -> V_49 ) ;
F_33 ( & V_9 -> V_61 -> V_43 ) ;
return 0 ;
}
void F_60 ( struct V_3 * V_46 )
{
struct V_7 * V_8 = V_46 -> V_27 . V_26 -> V_28 -> V_10 ;
F_3 ( & V_8 -> V_13 ) ;
F_61 ( & V_8 -> V_19 , 0 , V_131 ,
F_59 , V_46 ) ;
F_6 ( & V_8 -> V_13 ) ;
F_62 ( V_46 -> V_50 , ! F_63 ( & V_46 -> V_49 ) ) ;
}
static int F_64 ( struct V_29 * V_30 ,
T_3 V_37 , T_1 V_120 , T_2 V_121 ,
T_3 * V_132 ,
T_3 * V_133 )
{
int V_134 ;
unsigned int V_135 = 0 ;
T_1 V_124 ;
int V_69 = 0 , V_107 = 0 ;
struct V_3 * V_5 ;
T_1 V_136 = V_65 ;
struct V_1 * V_2 ;
int V_137 = 0 ;
T_2 V_138 ;
V_134 = F_65 ( & V_30 -> V_47 ) ;
V_5 = F_38 ( V_30 , V_37 ) ;
if ( ! V_5 || ! V_5 -> V_27 . V_26 ) {
F_13 ( V_30 , L_8 ,
V_37 ) ;
V_107 = - V_139 ;
goto V_140;
}
if ( ! V_5 -> V_9 -> V_61 ) {
F_13 ( V_30 , L_9 ,
V_37 ) ;
if ( V_133 )
* V_133 +=
( V_121 - * V_132 ) ;
goto V_140;
}
V_120 += * V_132 ;
V_121 -= * V_132 ;
if ( ! V_5 -> V_9 -> V_61 -> V_141 ) {
V_2 = F_48 ( V_5 , V_120 , V_121 ) ;
if ( F_46 ( V_2 ) ) {
V_107 = F_66 ( V_2 ) ;
goto V_140;
}
V_5 = V_2 -> V_6 ;
V_137 = 1 ;
} else {
V_2 = V_5 -> V_9 -> V_61 ;
}
V_126:
V_135 = F_18 ( V_2 -> V_142 ) ;
F_67 () ;
V_138 = F_27 ( T_2 , V_121 , F_28 ( V_2 -> V_9 ) - V_120 ) ;
V_124 = ( V_120 - ( V_5 -> V_98 . V_113 & V_143 ) ) >> V_68 ;
if ( V_5 -> V_9 -> V_144 )
V_136 |= V_66 ;
V_107 = F_68 ( V_5 -> V_9 , V_120 , V_138 ,
V_136 , V_135 ) ;
if ( V_107 < 0 )
goto V_140;
if ( V_107 > 0 ) {
int V_145 = V_107 ;
F_49 ( & V_2 -> V_125 ) ;
if ( ! F_69 ( V_5 -> V_9 , V_135 ) ) {
V_107 = F_22 ( V_5 , V_124 , V_145 ,
V_68 ,
V_53 ) ;
} else {
V_107 = - V_146 ;
}
F_52 ( & V_2 -> V_125 ) ;
if ( V_107 < 0 ) {
if ( V_107 != - V_146 )
F_43 ( V_30 , L_10 ) ;
goto V_140;
}
if ( V_133 ) {
T_3 V_147 = V_145 * V_63 -
( V_120 - F_70 ( V_120 , V_63 ) ) ;
* V_133 += F_27 ( T_3 , V_147 , V_138 ) ;
}
V_69 += V_145 ;
}
V_121 -= V_138 ;
if ( F_30 ( V_121 ) ) {
struct V_1 * V_148 ;
V_120 += V_138 ;
V_148 = F_2 ( V_2 ) ;
if ( F_30 ( ! V_148 || V_148 -> V_9 -> V_39 != V_120 ) ) {
F_13 ( V_30 , L_11 ,
V_120 , V_148 ) ;
V_107 = - V_146 ;
goto V_149;
}
V_2 = V_148 ;
V_5 = V_2 -> V_6 ;
goto V_126;
}
V_140:
if ( V_107 == - V_146 ) {
if ( V_137 || ! V_2 -> V_48 ) {
unsigned long V_150 =
F_71 ( V_151 ) ;
if ( ! F_72 (
& V_2 -> V_152 ,
V_150 ) ) {
F_73 ( V_30 , L_12 ,
V_135 , V_2 -> V_142 ) ;
}
} else {
V_107 = - V_139 ;
}
}
V_149:
F_74 ( & V_30 -> V_47 , V_134 ) ;
* V_132 = 0 ;
return V_107 ? V_107 : V_69 ;
}
static int F_75 ( struct V_29 * V_30 ,
struct V_100 * V_101 ,
struct V_153 * V_154 , void * V_105 ,
void * V_155 , T_3 * V_133 ,
T_3 * V_156 , int V_157 )
{
int V_107 = 0 , V_69 = 0 ;
T_1 V_120 ;
T_3 V_37 ;
T_3 V_158 ;
T_2 V_121 ;
int V_159 ;
if ( V_157 && V_154 -> V_160 . V_161 )
V_105 += sizeof( struct V_162 ) ;
if ( V_133 )
* V_133 = 0 ;
if ( V_156 )
* V_156 = 0 ;
while ( V_105 < V_155 ) {
struct V_163 * V_164 = V_105 ;
V_120 = F_76 ( V_164 -> V_60 ) ;
V_37 = F_14 ( V_164 -> V_41 ) ;
V_158 = F_14 ( V_164 -> V_158 ) ;
V_159 = ! ! ( V_158 & V_165 ) ;
V_121 = V_158 & ~ V_165 ;
if ( V_159 ) {
V_121 = V_121 & V_166 ;
V_105 += F_77 ( sizeof( struct V_167 ) + V_121 ,
16 ) ;
} else {
V_105 += sizeof( * V_164 ) ;
}
if ( V_157 && V_121 == 0 && V_37 == V_168 &&
V_120 == 0 )
break;
if ( ! V_159 && V_156 ) {
* V_156 += V_121 - F_27 ( T_2 , V_121 ,
V_101 -> V_132 ) ;
}
if ( V_121 == 0 )
V_121 = 1U << 31 ;
if ( V_159 || V_121 <= V_101 -> V_132 ) {
V_101 -> V_132 -=
F_27 ( T_2 , V_121 ,
V_101 -> V_132 ) ;
continue;
}
V_107 = F_64 ( V_30 , V_37 , V_120 , V_121 ,
& V_101 -> V_132 ,
V_133 ) ;
if ( V_107 < 0 )
break;
V_69 += V_107 ;
}
return V_107 < 0 ? V_107 : V_69 ;
}
static int F_78 (
struct V_29 * V_30 , struct V_100 * V_101 ,
struct V_153 * V_154 , void * * V_105 , void * * V_155 , int V_169 )
{
struct V_170 * V_171 = * V_105 ;
T_4 V_172 = V_101 -> V_105 . V_172 ;
T_3 V_173 ;
struct V_174 * V_175 ;
unsigned V_176 , V_177 ;
#if F_79 ( V_178 )
T_3 V_179 , V_180 ;
#endif
T_3 V_181 = V_154 -> V_182 . V_183 . V_184 . V_181 ;
V_176 = F_14 ( V_171 -> V_185 ) & V_186 ;
if ( V_176 * V_187 > V_169 ) {
F_43 ( V_30 , L_13 ,
V_176 , V_169 ) ;
return - V_139 ;
}
if ( V_176 == 0 ) {
F_43 ( V_30 , L_14 ,
V_172 , V_181 ) ;
return - V_139 ;
}
#if F_79 ( V_178 )
V_179 = ( F_14 ( V_171 -> V_188 ) &
V_189 ) >>
V_190 ;
if ( V_172 != V_179 ) {
F_43 ( V_30 , L_15 ,
V_172 , V_181 ,
V_179 ) ;
return - V_139 ;
}
V_180 = ( F_14 ( V_171 -> V_185 ) & V_191 ) >>
V_192 ;
if ( V_181 != V_180 ) {
F_43 ( V_30 , L_16 ,
V_172 , V_181 ,
V_180 ) ;
return - V_139 ;
}
#endif
* V_155 = * V_105 + V_176 * V_187 ;
* V_105 += sizeof( * V_171 ) ;
V_177 = F_14 ( V_171 -> V_188 ) &
V_193 ;
switch ( V_154 -> V_160 . V_194 ) {
case V_195 :
V_173 = V_30 -> V_72 . V_83 . V_85 ;
break;
case V_196 :
V_173 = V_30 -> V_72 . V_83 . V_81 ;
break;
default:
F_43 ( V_30 , L_17 ,
V_154 -> V_160 . V_194 ) ;
return - V_139 ;
}
if ( F_30 ( V_177 >= sizeof( V_197 ) /
sizeof( V_197 [ 0 ] ) ||
! ( V_173 & V_197 [ V_177 ] ) ) ) {
F_43 ( V_30 , L_18 ,
V_177 ) ;
return - V_139 ;
}
if ( V_154 -> V_160 . V_194 != V_195 ) {
V_175 = * V_105 ;
if ( V_175 -> V_198 & F_14 ( V_199 ) )
* V_105 += sizeof( struct V_200 ) ;
else
* V_105 += sizeof( struct V_174 ) ;
}
switch ( V_177 ) {
case V_201 :
case V_202 :
case V_203 :
* V_105 += sizeof( struct V_204 ) ;
break;
case V_205 :
case V_206 :
* V_105 += sizeof( struct V_204 ) ;
* V_105 += sizeof( struct V_207 ) ;
break;
}
return 0 ;
}
static int F_80 (
struct V_29 * V_30 , struct V_100 * V_101 ,
struct V_153 * V_154 , void * * V_105 , void * * V_155 , int V_169 )
{
struct V_208 * V_209 = & V_154 -> V_210 ;
int V_211 = 1 << V_209 -> V_212 ;
if ( V_154 -> V_160 . V_161 ) {
F_43 ( V_30 , L_19 ) ;
return - V_139 ;
}
if ( V_154 -> V_213 ) {
F_43 ( V_30 , L_20 ) ;
return - V_139 ;
}
if ( V_211 > V_169 ) {
F_43 ( V_30 , L_21 ) ;
return - V_139 ;
}
switch ( V_154 -> V_160 . V_194 ) {
case V_195 :
if ( ! ( V_30 -> V_72 . V_83 . V_85 &
V_87 ) )
goto V_214;
break;
default:
V_214:
F_43 ( V_30 , L_22 ,
V_154 -> V_160 . V_194 ) ;
return - V_139 ;
}
* V_155 = * V_105 + V_211 ;
return 0 ;
}
static struct V_153 * F_81 ( struct V_29 * V_30 ,
T_3 V_102 )
{
struct V_215 * V_184 = F_82 ( V_30 -> V_73 , V_102 ) ;
if ( ! V_184 ) {
F_43 ( V_30 , L_23 , V_102 ) ;
return NULL ;
}
return F_83 ( V_184 ) ;
}
static void F_84 ( struct V_29 * V_30 ,
struct V_100 * V_101 )
{
int V_107 ;
void * V_105 , * V_155 ;
T_3 V_133 , V_156 ;
char * V_216 = NULL ;
int V_217 = 1 ;
T_4 V_172 = V_101 -> V_105 . V_172 ;
int V_218 = V_101 -> type & V_219 ;
struct V_153 * V_154 ;
V_216 = ( char * ) F_85 ( V_220 ) ;
if ( ! V_216 ) {
F_43 ( V_30 , L_24 ) ;
goto V_221;
}
V_154 = F_81 ( V_30 , V_101 -> V_105 . V_102 ) ;
if ( ! V_154 )
goto V_221;
V_107 = F_86 ( V_154 , V_218 , V_172 , V_216 ,
V_63 , & V_154 -> V_182 . V_183 ) ;
if ( V_107 < 0 ) {
F_43 ( V_30 , L_25 ,
V_107 , V_172 , V_101 -> V_106 ) ;
goto V_221;
}
V_105 = V_216 ;
if ( V_218 )
V_107 = F_78 ( V_30 , V_101 , V_154 , & V_105 ,
& V_155 , V_107 ) ;
else
V_107 = F_80 ( V_30 , V_101 , V_154 , & V_105 ,
& V_155 , V_107 ) ;
if ( V_107 < 0 )
goto V_221;
if ( V_105 >= V_155 ) {
F_43 ( V_30 , L_26 ) ;
goto V_221;
}
V_107 = F_75 ( V_30 , V_101 , V_154 , V_105 , V_155 ,
& V_133 , & V_156 ,
! V_218 ) ;
if ( V_107 == - V_146 ) {
V_217 = 0 ;
goto V_221;
} else if ( V_107 < 0 || V_156 > V_133 ) {
if ( V_107 != - V_222 )
F_43 ( V_30 , L_27 ,
V_107 , V_101 -> V_105 . V_102 , V_101 -> type ) ;
goto V_221;
}
V_217 = 0 ;
V_221:
F_41 ( V_30 , V_101 , V_217 ) ;
F_13 ( V_30 , L_28 ,
V_101 -> V_105 . V_102 , V_217 ,
V_101 -> type ) ;
F_87 ( ( unsigned long ) V_216 ) ;
}
static int F_88 ( T_1 V_39 , T_3 V_18 )
{
return ( F_77 ( V_39 + V_18 , V_63 ) -
( V_39 & V_143 ) ) >> V_68 ;
}
static void F_89 ( struct V_29 * V_30 ,
struct V_100 * V_101 )
{
T_1 V_39 ;
T_3 V_18 ;
T_3 V_223 = V_101 -> V_132 ;
int V_224 = 0 ;
T_3 V_119 = V_101 -> V_225 . V_226 ;
int V_107 ;
V_101 -> V_225 . V_227 += V_101 -> V_132 ;
V_101 -> V_225 . V_228 -= F_90 ( V_101 -> V_132 ,
V_101 -> V_225 . V_228 ) ;
V_101 -> V_132 = 0 ;
V_39 = V_101 -> V_225 . V_227 ;
V_18 = V_101 -> V_225 . V_228 ;
if ( V_18 == 0 ) {
V_224 = 1 ;
V_18 = V_101 -> V_225 . V_229 ;
V_223 = F_90 ( V_230 , V_223 ) ;
}
V_107 = F_64 ( V_30 , V_119 , V_39 , V_18 ,
& V_101 -> V_132 , NULL ) ;
if ( V_107 == - V_146 ) {
V_224 = 0 ;
} else if ( V_107 < 0 || F_88 ( V_39, V_18 ) > V_107 ) {
F_41 ( V_30 , V_101 , 1 ) ;
if ( V_107 != - V_222 )
F_73 ( V_30 , L_29 ,
V_107 , V_101 -> V_106 , V_101 -> type ) ;
return;
}
F_41 ( V_30 , V_101 , 0 ) ;
F_13 ( V_30 , L_30 ,
V_101 -> V_106 , V_101 -> type ,
V_224 ) ;
if ( V_224 ) {
T_3 V_132 = 0 ;
V_107 = F_64 ( V_30 , V_119 , V_39 ,
V_223 ,
& V_132 , NULL ) ;
if ( V_107 < 0 && V_107 != - V_146 ) {
F_73 ( V_30 , L_31 ,
V_107 , V_101 -> V_106 , V_39 , V_223 ) ;
}
}
}
void F_91 ( struct V_231 * V_73 , void * V_10 ,
struct V_100 * V_101 )
{
struct V_29 * V_30 = V_10 ;
T_5 V_103 = V_101 -> V_103 ;
switch ( V_103 ) {
case V_104 :
F_84 ( V_30 , V_101 ) ;
break;
case V_232 :
F_89 ( V_30 , V_101 ) ;
break;
default:
F_43 ( V_30 , L_32 ,
V_103 ) ;
F_41 ( V_30 , V_101 , 1 ) ;
}
}
void F_92 ( struct V_233 * V_234 )
{
if ( ! ( V_234 -> V_30 -> V_72 . V_75 & V_95 ) )
return;
switch ( V_234 -> V_235 - 2 ) {
case V_112 :
V_234 -> V_236 = V_68 ;
V_234 -> V_237 = V_117 *
sizeof( struct V_57 ) /
V_238 ;
V_234 -> V_239 = V_240 ;
V_234 -> V_241 = 0 ;
break;
case V_111 :
V_234 -> V_236 = V_115 ;
V_234 -> V_237 = V_114 *
sizeof( struct V_20 ) /
V_238 ;
V_234 -> V_239 = V_242 ;
V_234 -> V_241 = 0 ;
break;
}
}
int F_93 ( struct V_29 * V_30 )
{
int V_107 ;
V_107 = F_94 ( & V_30 -> V_47 ) ;
if ( V_107 )
return V_107 ;
if ( V_30 -> V_72 . V_75 & V_95 ) {
V_107 = F_95 ( V_30 -> V_73 , & V_30 -> V_38 ) ;
if ( V_107 ) {
F_43 ( V_30 , L_33 , V_107 ) ;
return V_107 ;
}
}
return 0 ;
}
void F_96 ( struct V_29 * V_30 )
{
F_97 ( & V_30 -> V_47 ) ;
}
int F_98 ( void )
{
V_114 = F_36 ( F_99 ( V_243 ) -
V_244 ) ;
return 0 ;
}
