static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 = V_2 -> V_6 ;
return V_5 && V_5 -> V_4 == V_4 && ! V_2 -> V_7 ;
}
static struct V_1 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = V_2 -> V_6 , * V_4 = V_5 -> V_4 ;
struct V_8 * V_9 = V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 ;
F_3 ( & V_9 -> V_14 ) ;
while ( 1 ) {
V_13 = F_4 ( & V_2 -> V_15 . V_13 ) ;
if ( ! V_13 )
goto V_16;
V_2 = F_5 ( V_13 , struct V_1 , V_15 . V_13 ) ;
if ( F_1 ( V_2 , V_4 ) )
goto V_17;
}
V_16:
V_2 = NULL ;
V_17:
F_6 ( & V_9 -> V_14 ) ;
return V_2 ;
}
static struct V_1 * F_7 ( struct V_8 * V_9 ,
T_1 V_18 , T_1 V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
F_3 ( & V_9 -> V_14 ) ;
V_2 = F_8 ( & V_9 -> V_20 , V_18 , V_19 ) ;
if ( ! V_2 )
goto V_17;
while ( 1 ) {
if ( F_1 ( V_2 , V_4 ) )
goto V_17;
V_13 = F_4 ( & V_2 -> V_15 . V_13 ) ;
if ( ! V_13 )
goto V_16;
V_2 = F_5 ( V_13 , struct V_1 , V_15 . V_13 ) ;
if ( F_9 ( V_2 -> V_10 ) > V_18 + V_19 )
goto V_16;
}
V_16:
V_2 = NULL ;
V_17:
F_6 ( & V_9 -> V_14 ) ;
return V_2 ;
}
void F_10 ( struct V_21 * V_22 , T_2 V_23 ,
T_2 V_24 , struct V_3 * V_5 , int V_25 )
{
struct V_26 * V_27 = V_5 -> V_28 . V_27 ;
struct V_8 * V_9 = V_27 -> V_29 -> V_11 ;
struct V_30 * V_31 = F_11 ( V_27 -> V_32 ) ;
struct V_1 * V_2 ;
unsigned long V_33 ;
int V_34 ;
if ( V_25 & V_35 ) {
for ( V_34 = 0 ; V_34 < V_24 ; V_34 ++ , V_22 ++ ) {
V_22 -> V_36 = F_12 ( V_37 ) ;
V_22 -> V_38 = F_12 ( V_31 -> V_39 ) ;
V_22 -> V_33 = 0 ;
}
return;
}
V_2 = F_7 ( V_9 , V_23 * V_37 ,
V_24 * V_37 , V_5 ) ;
for ( V_34 = 0 ; V_34 < V_24 ; V_34 ++ , V_22 ++ ) {
V_22 -> V_36 = F_12 ( V_37 ) ;
V_33 = ( V_23 + V_34 ) * V_37 ;
if ( V_2 && V_2 -> V_10 -> V_40 == V_33 ) {
struct V_3 * V_41 = V_2 -> V_6 ;
V_22 -> V_38 = F_12 ( V_41 -> V_28 . V_42 ) ;
V_2 = F_2 ( V_2 ) ;
} else {
V_22 -> V_38 = F_12 ( V_31 -> V_39 ) ;
}
F_13 ( V_31 , L_1 ,
V_34 , V_33 , F_14 ( V_22 -> V_38 ) ) ;
}
}
static void F_15 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_16 ( V_44 , struct V_1 , V_44 ) ;
int V_45 = F_9 ( V_2 -> V_10 ) >> V_46 ;
struct V_3 * V_5 = V_2 -> V_6 , * V_47 = V_5 -> V_4 ;
V_5 -> V_4 = NULL ;
F_17 ( & V_5 -> V_31 -> V_48 ) ;
F_18 ( V_2 -> V_10 ) ;
if ( V_47 -> V_49 )
F_19 ( V_47 , V_45 , 1 , 0 ,
V_50 |
V_51 ) ;
F_20 ( V_5 -> V_31 , V_5 ) ;
if ( F_21 ( & V_47 -> V_52 ) )
F_22 ( & V_47 -> V_53 ) ;
}
void F_23 ( struct V_54 * V_10 , unsigned long V_18 ,
unsigned long V_17 )
{
struct V_3 * V_5 ;
const T_1 V_55 = ( V_56 /
sizeof( struct V_57 ) ) - 1 ;
T_1 V_45 = 0 , V_58 = 0 ;
int V_59 = 0 ;
T_1 V_60 ;
if ( ! V_10 || ! V_10 -> V_61 ) {
F_24 ( L_2 ) ;
return;
}
V_5 = V_10 -> V_61 -> V_6 ;
if ( ! V_5 || ! V_5 -> V_28 . V_27 )
return;
V_18 = F_25 ( T_1 , F_9 ( V_10 ) , V_18 ) ;
V_17 = F_26 ( T_1 , F_27 ( V_10 ) , V_17 ) ;
for ( V_60 = V_18 ; V_60 < V_17 ; V_60 += F_28 ( V_10 -> V_62 ) ) {
V_45 = ( V_60 - F_9 ( V_10 ) ) >> V_10 -> V_62 ;
if ( V_10 -> V_61 -> V_63 [ V_45 ] &
( V_64 | V_65 ) ) {
if ( ! V_59 ) {
V_58 = V_45 ;
V_59 = 1 ;
}
} else {
T_1 V_66 = V_45 & V_55 ;
if ( V_59 && V_66 == 0 ) {
F_19 ( V_5 , V_58 ,
V_45 - V_58 , 0 ,
V_35 |
V_51 ) ;
V_59 = 0 ;
}
}
}
if ( V_59 )
F_19 ( V_5 , V_58 ,
V_45 - V_58 + 1 , 0 ,
V_35 |
V_51 ) ;
F_29 ( V_10 , V_18 , V_17 ) ;
if ( F_30 ( ! V_10 -> V_67 && V_5 -> V_4 &&
! V_10 -> V_61 -> V_7 ) ) {
F_31 ( V_10 -> V_61 -> V_7 , 1 ) ;
F_32 ( & V_5 -> V_4 -> V_52 ) ;
F_33 ( & V_10 -> V_61 -> V_44 ) ;
}
}
void F_34 ( struct V_30 * V_31 )
{
struct V_68 * V_69 = & V_31 -> V_70 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
if ( ! F_35 ( V_31 -> V_71 , V_72 ) )
return;
V_69 -> V_73 = V_74 ;
if ( F_35 ( V_31 -> V_71 , V_75 ) )
V_31 -> V_76 = V_77 ;
else
V_31 -> V_76 = F_36 ( V_78 + V_79 ) ;
if ( F_37 ( V_31 -> V_71 , V_80 . V_81 ) )
V_69 -> V_82 . V_80 |= V_83 ;
if ( F_37 ( V_31 -> V_71 , V_84 . V_81 ) )
V_69 -> V_82 . V_84 |= V_83 ;
if ( F_37 ( V_31 -> V_71 , V_84 . V_85 ) )
V_69 -> V_82 . V_84 |= V_86 ;
if ( F_37 ( V_31 -> V_71 , V_84 . V_87 ) )
V_69 -> V_82 . V_84 |= V_88 ;
if ( F_37 ( V_31 -> V_71 , V_84 . V_89 ) )
V_69 -> V_82 . V_84 |= V_90 ;
if ( F_37 ( V_31 -> V_71 , V_84 . V_91 ) )
V_69 -> V_82 . V_84 |= V_92 ;
if ( F_35 ( V_31 -> V_71 , V_93 ) &&
F_35 ( V_31 -> V_71 , V_39 ) &&
F_35 ( V_31 -> V_71 , V_75 ) )
V_69 -> V_73 |= V_94 ;
return;
}
static void F_38 ( struct V_30 * V_31 ,
struct V_95 * V_96 ,
int error )
{
int V_97 = V_96 -> V_98 == V_99 ?
V_96 -> V_100 . V_97 : V_96 -> V_101 ;
int V_102 = F_39 ( V_31 -> V_71 ,
V_96 -> V_101 ,
V_97 ,
V_96 -> type ,
error ) ;
if ( V_102 )
F_40 ( V_31 , L_3 ,
V_97 ) ;
}
static struct V_3 * F_41 ( struct V_26 * V_27 ,
struct V_54 * V_10 ,
bool V_103 , int V_104 )
{
struct V_30 * V_31 = F_11 ( V_27 -> V_32 ) ;
struct V_3 * V_5 ;
int V_105 ;
V_5 = F_42 ( V_31 , V_103 ? V_106 :
V_107 ) ;
if ( F_43 ( V_5 ) )
return V_5 ;
V_5 -> V_28 . V_27 = V_27 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_104 = V_104 ;
V_5 -> V_108 . V_109 = 0 ;
V_5 -> V_10 = V_10 ;
if ( V_103 ) {
V_105 = F_19 ( V_5 , 0 ,
V_110 ,
V_111 ,
V_50 |
V_35 |
V_112 ) ;
} else {
V_105 = F_19 ( V_5 , 0 ,
V_113 ,
V_79 ,
V_35 |
V_112 |
V_51 ) ;
}
if ( V_105 )
goto V_114;
V_5 -> V_28 . V_42 = V_5 -> V_108 . V_38 ;
V_5 -> V_28 . V_115 = V_5 -> V_108 . V_38 ;
V_5 -> V_49 = 1 ;
F_13 ( V_31 , L_4 ,
V_5 -> V_108 . V_38 , V_31 -> V_71 , V_5 ) ;
return V_5 ;
V_114:
F_40 ( V_31 , L_5 , V_105 ) ;
F_20 ( V_31 , V_5 ) ;
return F_44 ( V_105 ) ;
}
static struct V_1 * F_45 ( struct V_3 * V_5 ,
T_1 V_116 , T_2 V_117 )
{
struct V_8 * V_9 = V_5 -> V_28 . V_27 -> V_29 -> V_11 ;
struct V_30 * V_31 = F_11 ( V_5 -> V_28 . V_27 -> V_32 ) ;
struct V_1 * V_2 , * V_118 = NULL ;
T_1 V_60 = V_116 & V_119 ;
int V_24 = 0 , V_120 = 0 , V_102 ;
struct V_3 * V_41 ;
struct V_54 * V_10 ;
F_46 ( & V_5 -> V_10 -> V_61 -> V_121 ) ;
V_2 = F_7 ( V_9 , V_60 , 1 , V_5 ) ;
F_13 ( V_31 , L_6 ,
V_116 , V_117 , V_60 , V_2 ) ;
V_122:
if ( F_47 ( V_2 ) ) {
if ( V_24 )
V_24 ++ ;
} else {
V_10 = F_48 ( V_9 , V_60 , V_37 ) ;
if ( F_43 ( V_10 ) ) {
F_49 ( & V_5 -> V_10 -> V_61 -> V_121 ) ;
return F_50 ( V_10 ) ;
}
V_41 = F_41 ( V_5 -> V_28 . V_27 , V_10 , 0 , V_5 -> V_104 ) ;
if ( F_43 ( V_41 ) ) {
F_49 ( & V_5 -> V_10 -> V_61 -> V_121 ) ;
F_18 ( V_10 ) ;
return F_50 ( V_41 ) ;
}
V_2 = V_10 -> V_61 ;
V_2 -> V_6 = V_41 ;
V_41 -> V_10 = V_10 ;
V_41 -> V_108 . V_109 = V_60 ;
V_41 -> V_4 = V_5 ;
F_51 ( & V_2 -> V_44 , F_15 ) ;
if ( ! V_24 )
V_120 = V_60 >> V_46 ;
V_24 ++ ;
}
if ( F_47 ( ! V_118 ) )
V_118 = V_2 ;
V_60 += V_37 ;
if ( F_30 ( V_60 < V_116 + V_117 ) ) {
V_2 = F_2 ( V_2 ) ;
if ( V_2 && V_2 -> V_10 -> V_40 != V_60 )
V_2 = NULL ;
goto V_122;
}
if ( F_30 ( V_24 ) ) {
V_102 = F_19 ( V_5 , V_120 , V_24 , 0 ,
V_50 |
V_51 ) ;
if ( V_102 ) {
F_40 ( V_31 , L_7 ) ;
V_118 = F_44 ( V_102 ) ;
}
}
F_49 ( & V_5 -> V_10 -> V_61 -> V_121 ) ;
return V_118 ;
}
struct V_3 * F_52 ( struct V_123 * V_27 ,
int V_104 )
{
struct V_8 * V_9 = V_27 -> V_124 . V_29 -> V_11 ;
struct V_3 * V_47 ;
struct V_54 * V_10 ;
V_10 = F_53 ( V_9 , 0 , 0 , V_125 , 0 ) ;
if ( F_43 ( V_10 ) )
return F_50 ( V_10 ) ;
V_47 = F_41 ( & V_27 -> V_124 , V_10 , 1 , V_104 ) ;
if ( F_43 ( V_47 ) ) {
F_18 ( V_10 ) ;
return F_50 ( V_47 ) ;
}
V_47 -> V_10 = V_10 ;
F_54 ( & V_47 -> V_53 ) ;
F_55 ( & V_47 -> V_52 , 0 ) ;
return V_47 ;
}
static int F_56 ( struct V_54 * V_10 , T_1 V_18 ,
T_1 V_17 , void * V_126 )
{
struct V_3 * V_5 = V_10 -> V_61 -> V_6 , * V_47 = V_126 ;
if ( V_5 -> V_4 != V_47 )
return 0 ;
F_29 ( V_10 ,
F_9 ( V_10 ) ,
F_27 ( V_10 ) ) ;
if ( V_10 -> V_61 -> V_7 )
return 0 ;
F_31 ( V_10 -> V_61 -> V_7 , 1 ) ;
F_32 ( & V_47 -> V_52 ) ;
F_33 ( & V_10 -> V_61 -> V_44 ) ;
return 0 ;
}
void F_57 ( struct V_3 * V_47 )
{
struct V_8 * V_9 = V_47 -> V_28 . V_27 -> V_29 -> V_11 ;
F_3 ( & V_9 -> V_14 ) ;
F_58 ( & V_9 -> V_20 , 0 , V_127 ,
F_56 , V_47 ) ;
F_6 ( & V_9 -> V_14 ) ;
F_59 ( V_47 -> V_53 , ! F_60 ( & V_47 -> V_52 ) ) ;
}
static int F_61 ( struct V_30 * V_31 , struct V_3 * V_5 ,
T_1 V_116 , T_2 V_117 , T_3 * V_128 )
{
T_1 V_129 = V_64 ;
int V_67 = 0 , V_62 , V_130 ;
T_1 V_120 , V_131 ;
struct V_1 * V_2 ;
int V_132 ;
T_2 V_133 ;
int V_102 ;
if ( ! V_5 -> V_10 -> V_61 -> V_134 ) {
V_2 = F_45 ( V_5 , V_116 , V_117 ) ;
if ( F_43 ( V_2 ) )
return F_62 ( V_2 ) ;
V_5 = V_2 -> V_6 ;
} else {
V_2 = V_5 -> V_10 -> V_61 ;
}
V_122:
V_133 = F_26 ( T_2 , V_117 , F_27 ( V_2 -> V_10 ) - V_116 ) ;
V_62 = V_5 -> V_10 -> V_62 ;
V_131 = ~ ( F_28 ( V_62 ) - 1 ) ;
V_120 = ( V_116 - ( V_5 -> V_108 . V_109 & V_131 ) ) >> V_62 ;
if ( V_5 -> V_10 -> V_135 )
V_129 |= V_65 ;
V_132 = F_63 ( V_2 -> V_136 ) ;
F_64 () ;
V_102 = F_65 ( V_5 -> V_10 , V_116 , V_133 ,
V_129 , V_132 ) ;
if ( V_102 < 0 )
goto V_137;
V_130 = V_102 ;
F_46 ( & V_2 -> V_121 ) ;
if ( ! F_66 ( V_5 -> V_10 , V_132 ) ) {
V_102 = F_19 ( V_5 , V_120 , V_130 ,
V_62 , V_51 ) ;
} else {
V_102 = - V_138 ;
}
F_49 ( & V_2 -> V_121 ) ;
if ( V_102 < 0 ) {
if ( V_102 != - V_138 )
F_40 ( V_31 , L_8 ) ;
goto V_137;
}
if ( V_128 ) {
T_3 V_139 = ( V_130 << V_62 ) -
( V_116 - F_67 ( V_116 , 1 << V_62 ) ) ;
* V_128 += F_26 ( T_3 , V_139 , V_133 ) ;
}
V_67 += V_130 << ( V_62 - V_79 ) ;
V_117 -= V_133 ;
if ( F_30 ( V_117 ) ) {
struct V_1 * V_140 ;
V_116 += V_133 ;
V_140 = F_2 ( V_2 ) ;
if ( F_30 ( ! V_140 || V_140 -> V_10 -> V_40 != V_116 ) ) {
F_13 ( V_31 , L_9 ,
V_116 , V_140 ) ;
return - V_138 ;
}
V_2 = V_140 ;
V_5 = V_2 -> V_6 ;
goto V_122;
}
return V_67 ;
V_137:
if ( V_102 == - V_138 ) {
if ( V_5 -> V_4 || ! V_2 -> V_7 ) {
unsigned long V_141 =
F_68 ( V_142 ) ;
if ( ! F_69 (
& V_2 -> V_143 ,
V_141 ) ) {
F_70 ( V_31 , L_10 ,
V_132 , V_2 -> V_136 ) ;
}
} else {
V_102 = - V_144 ;
}
}
return V_102 ;
}
static int F_71 ( struct V_30 * V_31 ,
T_3 V_38 , T_1 V_116 , T_2 V_117 ,
T_3 * V_145 ,
T_3 * V_128 )
{
int V_67 = 0 , V_146 , V_102 , V_34 , V_147 , V_148 = 0 , V_149 = 0 ;
struct V_150 * V_151 = NULL , * V_152 ;
struct V_153 * V_108 ;
struct V_154 * V_155 ;
struct V_3 * V_5 ;
struct V_21 * V_22 ;
T_3 * V_137 = NULL ;
T_2 V_23 ;
V_146 = F_72 ( & V_31 -> V_48 ) ;
V_116 += * V_145 ;
V_117 -= * V_145 ;
V_122:
V_108 = F_73 ( V_31 -> V_71 , F_74 ( V_38 ) ) ;
if ( ! V_108 || V_108 -> V_38 != V_38 ) {
F_13 ( V_31 , L_11 , V_38 ) ;
V_102 = - V_144 ;
goto V_156;
}
switch ( V_108 -> type ) {
case V_157 :
V_5 = F_16 ( V_108 , struct V_3 , V_108 ) ;
if ( ! V_5 -> V_49 || ! V_5 -> V_28 . V_27 ) {
F_13 ( V_31 , L_12 ) ;
V_102 = - V_144 ;
goto V_156;
}
V_102 = F_61 ( V_31 , V_5 , V_116 , V_117 , V_128 ) ;
if ( V_102 < 0 )
goto V_156;
V_67 += V_102 ;
V_102 = 0 ;
break;
case V_158 :
V_155 = F_16 ( V_108 , struct V_154 , V_108 ) ;
if ( V_149 >= F_35 ( V_31 -> V_71 , V_159 ) ) {
F_13 ( V_31 , L_13 ) ;
V_102 = - V_144 ;
goto V_156;
}
V_147 = F_75 ( V_160 ) +
sizeof( * V_22 ) * ( V_155 -> V_161 - 2 ) ;
if ( V_147 > V_148 ) {
F_76 ( V_137 ) ;
V_137 = F_77 ( V_147 , V_162 ) ;
if ( ! V_137 ) {
V_102 = - V_163 ;
goto V_156;
}
V_148 = V_147 ;
}
V_22 = (struct V_21 * ) F_78 ( V_160 , V_137 ,
V_164 ) ;
V_102 = F_79 ( V_31 -> V_71 , & V_155 -> V_108 , V_137 , V_147 ) ;
if ( V_102 )
goto V_156;
V_23 = V_116 - F_80 ( V_160 , V_137 ,
V_165 . V_166 ) ;
for ( V_34 = 0 ; V_117 && V_34 < V_155 -> V_161 ; V_34 ++ , V_22 ++ ) {
if ( V_23 >= F_14 ( V_22 -> V_36 ) ) {
V_23 -= F_14 ( V_22 -> V_36 ) ;
continue;
}
V_152 = F_77 ( sizeof( * V_152 ) , V_162 ) ;
if ( ! V_152 ) {
V_102 = - V_163 ;
goto V_156;
}
V_152 -> V_38 = F_14 ( V_22 -> V_38 ) ;
V_152 -> V_116 = F_81 ( V_22 -> V_33 ) + V_23 ;
V_152 -> V_117 = F_26 ( T_2 , V_117 ,
F_14 ( V_22 -> V_36 ) - V_23 ) ;
V_152 -> V_149 = V_149 + 1 ;
V_152 -> V_140 = V_151 ;
V_151 = V_152 ;
V_117 -= V_152 -> V_117 ;
}
break;
default:
F_13 ( V_31 , L_14 , V_108 -> type ) ;
V_102 = - V_144 ;
goto V_156;
}
if ( V_151 ) {
V_152 = V_151 ;
V_151 = V_152 -> V_140 ;
V_38 = V_152 -> V_38 ;
V_116 = V_152 -> V_116 ;
V_117 = V_152 -> V_117 ;
V_149 = V_152 -> V_149 ;
F_76 ( V_152 ) ;
goto V_122;
}
V_156:
while ( V_151 ) {
V_152 = V_151 ;
V_151 = V_152 -> V_140 ;
F_76 ( V_152 ) ;
}
F_76 ( V_137 ) ;
F_82 ( & V_31 -> V_48 , V_146 ) ;
* V_145 = 0 ;
return V_102 ? V_102 : V_67 ;
}
static int F_83 ( struct V_30 * V_31 ,
struct V_95 * V_96 ,
struct V_167 * V_168 , void * V_100 ,
void * V_169 , T_3 * V_128 ,
T_3 * V_170 , int V_171 )
{
int V_102 = 0 , V_67 = 0 ;
T_1 V_116 ;
T_3 V_38 ;
T_3 V_172 ;
T_2 V_117 ;
int V_173 ;
if ( V_171 && V_168 -> V_174 . V_175 )
V_100 += sizeof( struct V_176 ) ;
if ( V_128 )
* V_128 = 0 ;
if ( V_170 )
* V_170 = 0 ;
while ( V_100 < V_169 ) {
struct V_177 * V_178 = V_100 ;
V_116 = F_81 ( V_178 -> V_60 ) ;
V_38 = F_14 ( V_178 -> V_42 ) ;
V_172 = F_14 ( V_178 -> V_172 ) ;
V_173 = ! ! ( V_172 & V_179 ) ;
V_117 = V_172 & ~ V_179 ;
if ( V_173 ) {
V_117 = V_117 & V_180 ;
V_100 += F_84 ( sizeof( struct V_181 ) + V_117 ,
16 ) ;
} else {
V_100 += sizeof( * V_178 ) ;
}
if ( V_171 && V_117 == 0 && V_38 == V_182 &&
V_116 == 0 )
break;
if ( ! V_173 && V_170 ) {
* V_170 += V_117 - F_26 ( T_2 , V_117 ,
V_96 -> V_145 ) ;
}
if ( V_117 == 0 )
V_117 = 1U << 31 ;
if ( V_173 || V_117 <= V_96 -> V_145 ) {
V_96 -> V_145 -=
F_26 ( T_2 , V_117 ,
V_96 -> V_145 ) ;
continue;
}
V_102 = F_71 ( V_31 , V_38 , V_116 , V_117 ,
& V_96 -> V_145 ,
V_128 ) ;
if ( V_102 < 0 )
break;
V_67 += V_102 ;
}
return V_102 < 0 ? V_102 : V_67 ;
}
static int F_85 (
struct V_30 * V_31 , struct V_95 * V_96 ,
struct V_167 * V_168 , void * * V_100 , void * * V_169 , int V_183 )
{
struct V_184 * V_185 = * V_100 ;
T_4 V_186 = V_96 -> V_100 . V_186 ;
T_3 V_187 ;
struct V_188 * V_189 ;
unsigned V_190 , V_191 ;
#if F_86 ( V_192 )
T_3 V_193 , V_194 ;
#endif
T_3 V_195 = V_168 -> V_196 . V_197 . V_198 . V_195 ;
V_190 = F_14 ( V_185 -> V_199 ) & V_200 ;
if ( V_190 * V_201 > V_183 ) {
F_40 ( V_31 , L_15 ,
V_190 , V_183 ) ;
return - V_144 ;
}
if ( V_190 == 0 ) {
F_40 ( V_31 , L_16 ,
V_186 , V_195 ) ;
return - V_144 ;
}
#if F_86 ( V_192 )
V_193 = ( F_14 ( V_185 -> V_202 ) &
V_203 ) >>
V_204 ;
if ( V_186 != V_193 ) {
F_40 ( V_31 , L_17 ,
V_186 , V_195 ,
V_193 ) ;
return - V_144 ;
}
V_194 = ( F_14 ( V_185 -> V_199 ) & V_205 ) >>
V_206 ;
if ( V_195 != V_194 ) {
F_40 ( V_31 , L_18 ,
V_186 , V_195 ,
V_194 ) ;
return - V_144 ;
}
#endif
* V_169 = * V_100 + V_190 * V_201 ;
* V_100 += sizeof( * V_185 ) ;
V_191 = F_14 ( V_185 -> V_202 ) &
V_207 ;
switch ( V_168 -> V_174 . V_208 ) {
case V_209 :
V_187 = V_31 -> V_70 . V_82 . V_84 ;
break;
case V_210 :
V_187 = V_31 -> V_70 . V_82 . V_80 ;
break;
default:
F_40 ( V_31 , L_19 ,
V_168 -> V_174 . V_208 ) ;
return - V_144 ;
}
if ( F_30 ( V_191 >= sizeof( V_211 ) /
sizeof( V_211 [ 0 ] ) ||
! ( V_187 & V_211 [ V_191 ] ) ) ) {
F_40 ( V_31 , L_20 ,
V_191 ) ;
return - V_144 ;
}
if ( V_168 -> V_174 . V_208 != V_209 ) {
V_189 = * V_100 ;
if ( V_189 -> V_212 & F_12 ( V_213 ) )
* V_100 += sizeof( struct V_214 ) ;
else
* V_100 += sizeof( struct V_188 ) ;
}
switch ( V_191 ) {
case V_215 :
case V_216 :
case V_217 :
* V_100 += sizeof( struct V_218 ) ;
break;
case V_219 :
case V_220 :
* V_100 += sizeof( struct V_218 ) ;
* V_100 += sizeof( struct V_221 ) ;
break;
}
return 0 ;
}
static int F_87 (
struct V_30 * V_31 , struct V_95 * V_96 ,
struct V_167 * V_168 , void * * V_100 , void * * V_169 , int V_183 )
{
struct V_222 * V_223 = & V_168 -> V_224 ;
int V_225 = 1 << V_223 -> V_226 ;
if ( V_168 -> V_174 . V_175 ) {
F_40 ( V_31 , L_21 ) ;
return - V_144 ;
}
if ( V_168 -> V_227 ) {
F_40 ( V_31 , L_22 ) ;
return - V_144 ;
}
if ( V_225 > V_183 ) {
F_40 ( V_31 , L_23 ) ;
return - V_144 ;
}
switch ( V_168 -> V_174 . V_208 ) {
case V_209 :
if ( ! ( V_31 -> V_70 . V_82 . V_84 &
V_86 ) )
goto V_228;
break;
default:
V_228:
F_40 ( V_31 , L_24 ,
V_168 -> V_174 . V_208 ) ;
return - V_144 ;
}
* V_169 = * V_100 + V_225 ;
return 0 ;
}
static struct V_167 * F_88 ( struct V_30 * V_31 ,
T_3 V_97 )
{
struct V_229 * V_198 = F_89 ( V_31 -> V_71 , V_97 ) ;
if ( ! V_198 ) {
F_40 ( V_31 , L_25 , V_97 ) ;
return NULL ;
}
return F_90 ( V_198 ) ;
}
static void F_91 ( struct V_30 * V_31 ,
struct V_95 * V_96 )
{
int V_102 ;
void * V_100 , * V_169 ;
T_3 V_128 , V_170 ;
char * V_230 = NULL ;
int V_231 = 1 ;
T_4 V_186 = V_96 -> V_100 . V_186 ;
int V_232 = V_96 -> type & V_233 ;
struct V_167 * V_168 ;
V_230 = ( char * ) F_92 ( V_162 ) ;
if ( ! V_230 ) {
F_40 ( V_31 , L_26 ) ;
goto V_234;
}
V_168 = F_88 ( V_31 , V_96 -> V_100 . V_97 ) ;
if ( ! V_168 )
goto V_234;
V_102 = F_93 ( V_168 , V_232 , V_186 , V_230 ,
V_235 , & V_168 -> V_196 . V_197 ) ;
if ( V_102 < 0 ) {
F_40 ( V_31 , L_27 ,
V_102 , V_186 , V_96 -> V_101 ) ;
goto V_234;
}
V_100 = V_230 ;
if ( V_232 )
V_102 = F_85 ( V_31 , V_96 , V_168 , & V_100 ,
& V_169 , V_102 ) ;
else
V_102 = F_87 ( V_31 , V_96 , V_168 , & V_100 ,
& V_169 , V_102 ) ;
if ( V_102 < 0 )
goto V_234;
if ( V_100 >= V_169 ) {
F_40 ( V_31 , L_28 ) ;
goto V_234;
}
V_102 = F_83 ( V_31 , V_96 , V_168 , V_100 , V_169 ,
& V_128 , & V_170 ,
! V_232 ) ;
if ( V_102 == - V_138 ) {
V_231 = 0 ;
goto V_234;
} else if ( V_102 < 0 || V_170 > V_128 ) {
goto V_234;
}
V_231 = 0 ;
V_234:
F_38 ( V_31 , V_96 , V_231 ) ;
F_13 ( V_31 , L_29 ,
V_96 -> V_100 . V_97 , V_231 ,
V_96 -> type ) ;
F_94 ( ( unsigned long ) V_230 ) ;
}
static int F_95 ( T_1 V_40 , T_3 V_19 )
{
return ( F_84 ( V_40 + V_19 , V_235 ) -
( V_40 & V_236 ) ) >> V_79 ;
}
static void F_96 ( struct V_30 * V_31 ,
struct V_95 * V_96 )
{
T_1 V_40 ;
T_3 V_19 ;
T_3 V_237 = V_96 -> V_145 ;
int V_238 = 0 ;
T_3 V_115 = V_96 -> V_239 . V_240 ;
int V_102 ;
V_96 -> V_239 . V_241 += V_96 -> V_145 ;
V_96 -> V_239 . V_242 -= F_97 ( V_96 -> V_145 ,
V_96 -> V_239 . V_242 ) ;
V_96 -> V_145 = 0 ;
V_40 = V_96 -> V_239 . V_241 ;
V_19 = V_96 -> V_239 . V_242 ;
if ( V_19 == 0 ) {
V_238 = 1 ;
V_19 = V_96 -> V_239 . V_243 ;
V_237 = F_97 ( V_244 , V_237 ) ;
}
V_102 = F_71 ( V_31 , V_115 , V_40 , V_19 ,
& V_96 -> V_145 , NULL ) ;
if ( V_102 == - V_138 ) {
V_238 = 0 ;
} else if ( V_102 < 0 || F_95 ( V_40, V_19 ) > V_102 ) {
F_38 ( V_31 , V_96 , 1 ) ;
if ( V_102 != - V_245 )
F_13 ( V_31 , L_30 ,
V_102 , V_96 -> V_101 , V_96 -> type ) ;
return;
}
F_38 ( V_31 , V_96 , 0 ) ;
F_13 ( V_31 , L_31 ,
V_96 -> V_101 , V_96 -> type ,
V_238 ) ;
if ( V_238 ) {
T_3 V_145 = 0 ;
V_102 = F_71 ( V_31 , V_115 , V_40 ,
V_237 ,
& V_145 , NULL ) ;
if ( V_102 < 0 && V_102 != - V_138 ) {
F_13 ( V_31 , L_32 ,
V_102 , V_96 -> V_101 , V_40 , V_237 ) ;
}
}
}
void F_98 ( struct V_246 * V_71 , void * V_11 ,
struct V_95 * V_96 )
{
struct V_30 * V_31 = V_11 ;
T_5 V_98 = V_96 -> V_98 ;
switch ( V_98 ) {
case V_99 :
F_91 ( V_31 , V_96 ) ;
break;
case V_247 :
F_96 ( V_31 , V_96 ) ;
break;
default:
F_40 ( V_31 , L_33 ,
V_98 ) ;
F_38 ( V_31 , V_96 , 1 ) ;
}
}
void F_99 ( struct V_248 * V_249 )
{
if ( ! ( V_249 -> V_31 -> V_70 . V_73 & V_94 ) )
return;
switch ( V_249 -> V_250 - 2 ) {
case V_107 :
V_249 -> V_251 = V_79 ;
V_249 -> V_252 = V_113 *
sizeof( struct V_57 ) /
V_253 ;
V_249 -> V_254 = V_255 ;
V_249 -> V_256 = 0 ;
break;
case V_106 :
V_249 -> V_251 = V_111 ;
V_249 -> V_252 = V_110 *
sizeof( struct V_21 ) /
V_253 ;
V_249 -> V_254 = V_257 ;
V_249 -> V_256 = 0 ;
break;
}
}
int F_100 ( struct V_30 * V_31 )
{
int V_102 ;
V_102 = F_101 ( & V_31 -> V_48 ) ;
if ( V_102 )
return V_102 ;
if ( V_31 -> V_70 . V_73 & V_94 ) {
V_102 = F_102 ( V_31 -> V_71 , & V_31 -> V_39 ) ;
if ( V_102 ) {
F_40 ( V_31 , L_34 , V_102 ) ;
return V_102 ;
}
}
return 0 ;
}
void F_103 ( struct V_30 * V_31 )
{
F_104 ( & V_31 -> V_48 ) ;
}
int F_105 ( void )
{
V_110 = F_36 ( F_106 ( V_258 ) -
V_259 ) ;
return 0 ;
}
