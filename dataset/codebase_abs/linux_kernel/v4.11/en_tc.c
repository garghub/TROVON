static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
struct V_11 V_12 = { 0 } ;
struct V_13 V_14 = {
. V_6 = V_6 ,
. V_7 = V_7 ,
. V_15 = 0 ,
} ;
struct V_16 * V_17 = NULL ;
struct V_1 * V_18 ;
bool V_19 = false ;
if ( V_6 & V_20 ) {
V_12 . type = V_21 ;
V_12 . V_22 = V_3 -> V_23 . V_24 . V_22 . V_25 ;
} else if ( V_6 & V_26 ) {
V_17 = F_2 ( V_9 , true ) ;
if ( F_3 ( V_17 ) )
return F_4 ( V_17 ) ;
V_12 . type = V_27 ;
V_12 . V_17 = V_17 ;
}
if ( F_5 ( V_3 -> V_23 . V_28 . V_25 ) ) {
V_3 -> V_23 . V_28 . V_25 =
F_6 ( V_3 -> V_23 . V_29 ,
V_30 ,
V_31 ,
V_32 ,
0 , 0 ) ;
if ( F_3 ( V_3 -> V_23 . V_28 . V_25 ) ) {
F_7 ( V_3 -> V_33 ,
L_1 ) ;
V_18 = F_4 ( V_3 -> V_23 . V_28 . V_25 ) ;
goto V_34;
}
V_19 = true ;
}
V_5 -> V_35 = V_36 ;
V_18 = F_8 ( V_3 -> V_23 . V_28 . V_25 , V_5 , & V_14 , & V_12 , 1 ) ;
if ( F_3 ( V_18 ) )
goto V_37;
return V_18 ;
V_37:
if ( V_19 ) {
F_9 ( V_3 -> V_23 . V_28 . V_25 ) ;
V_3 -> V_23 . V_28 . V_25 = NULL ;
}
V_34:
F_10 ( V_9 , V_17 ) ;
return V_18 ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_16 * V_17 = NULL ;
if ( ! F_3 ( V_39 -> V_18 ) ) {
V_17 = F_12 ( V_39 -> V_18 ) ;
F_13 ( V_39 -> V_18 ) ;
F_10 ( V_3 -> V_10 , V_17 ) ;
}
if ( ! F_14 ( V_3 ) && ( V_3 -> V_23 . V_28 . V_25 ) ) {
F_9 ( V_3 -> V_23 . V_28 . V_25 ) ;
V_3 -> V_23 . V_28 . V_25 = NULL ;
}
}
static struct V_1 *
F_15 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
int V_45 ;
V_45 = F_16 ( V_43 , V_41 ) ;
if ( V_45 )
return F_17 ( V_45 ) ;
return F_18 ( V_43 , V_5 , V_41 ) ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
F_20 ( V_43 , V_39 -> V_18 , V_39 -> V_41 ) ;
F_21 ( V_43 , V_39 -> V_41 ) ;
if ( V_39 -> V_41 -> V_6 & V_46 )
F_22 ( V_3 , V_39 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_47 * V_48 = V_39 -> V_49 . V_48 ;
F_23 ( & V_39 -> V_49 ) ;
if ( F_24 ( V_48 ) ) {
struct V_50 * V_51 ;
V_51 = F_25 ( V_48 , struct V_50 , V_52 ) ;
if ( V_51 -> V_53 ) {
F_26 ( V_3 -> V_10 , V_51 -> V_15 ) ;
F_27 ( V_51 -> V_53 ) ;
}
F_28 ( & V_51 -> V_54 ) ;
F_29 ( V_51 ) ;
}
}
static void F_30 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
if ( V_39 -> V_55 & V_56 )
F_19 ( V_3 , V_39 ) ;
else
F_11 ( V_3 , V_39 ) ;
}
static void F_31 ( struct V_4 * V_5 ,
struct V_57 * V_58 )
{
void * V_59 = F_32 ( V_60 , V_5 -> V_61 ,
V_62 ) ;
void * V_63 = F_32 ( V_60 , V_5 -> V_64 ,
V_62 ) ;
void * V_65 = F_32 ( V_60 , V_5 -> V_61 ,
V_66 ) ;
void * V_67 = F_32 ( V_60 , V_5 -> V_64 ,
V_66 ) ;
F_33 ( V_68 , V_59 , V_69 ) ;
F_34 ( V_68 , V_63 , V_69 , V_70 ) ;
if ( F_35 ( V_58 -> V_71 , V_72 ) ) {
struct V_73 * V_74 =
F_36 ( V_58 -> V_71 ,
V_72 ,
V_58 -> V_74 ) ;
struct V_73 * V_75 =
F_36 ( V_58 -> V_71 ,
V_72 ,
V_58 -> V_75 ) ;
F_34 ( V_76 , V_65 , V_77 ,
F_37 ( V_75 -> V_78 ) ) ;
F_34 ( V_76 , V_67 , V_77 ,
F_37 ( V_74 -> V_78 ) ) ;
}
}
static int F_38 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_57 * V_58 )
{
void * V_59 = F_32 ( V_60 , V_5 -> V_61 ,
V_62 ) ;
void * V_63 = F_32 ( V_60 , V_5 -> V_64 ,
V_62 ) ;
struct V_79 * V_80 =
F_36 ( V_58 -> V_71 ,
V_81 ,
V_58 -> V_74 ) ;
if ( F_35 ( V_58 -> V_71 , V_82 ) ) {
struct V_83 * V_74 =
F_36 ( V_58 -> V_71 ,
V_82 ,
V_58 -> V_74 ) ;
struct V_83 * V_75 =
F_36 ( V_58 -> V_71 ,
V_82 ,
V_58 -> V_75 ) ;
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
struct V_84 * V_85 = F_39 ( V_43 ) ;
struct V_2 * V_86 = F_40 ( V_85 ) ;
if ( F_41 ( & V_75 -> V_87 , 0xff , sizeof( V_75 -> V_87 ) ) )
goto V_88;
if ( F_42 ( V_86 , F_43 ( V_74 -> V_87 ) ) &&
F_44 ( V_3 -> V_10 , V_89 ) )
F_31 ( V_5 , V_58 ) ;
else {
F_45 ( V_3 -> V_33 ,
L_2 , F_43 ( V_74 -> V_87 ) ) ;
return - V_90 ;
}
F_34 ( V_68 , V_59 ,
V_91 , F_46 ( V_75 -> V_87 ) ) ;
F_34 ( V_68 , V_63 ,
V_91 , F_46 ( V_74 -> V_87 ) ) ;
F_34 ( V_68 , V_59 ,
V_92 , F_46 ( V_75 -> V_93 ) ) ;
F_34 ( V_68 , V_63 ,
V_92 , F_46 ( V_74 -> V_93 ) ) ;
} else {
V_88:
F_45 ( V_3 -> V_33 ,
L_3 ) ;
return - V_90 ;
}
if ( V_80 -> V_94 == V_95 ) {
struct V_96 * V_74 =
F_36 ( V_58 -> V_71 ,
V_97 ,
V_58 -> V_74 ) ;
struct V_96 * V_75 =
F_36 ( V_58 -> V_71 ,
V_97 ,
V_58 -> V_75 ) ;
F_34 ( V_68 , V_59 ,
V_98 . V_99 . V_100 ,
F_47 ( V_75 -> V_93 ) ) ;
F_34 ( V_68 , V_63 ,
V_98 . V_99 . V_100 ,
F_47 ( V_74 -> V_93 ) ) ;
F_34 ( V_68 , V_59 ,
V_101 . V_99 . V_100 ,
F_47 ( V_75 -> V_87 ) ) ;
F_34 ( V_68 , V_63 ,
V_101 . V_99 . V_100 ,
F_47 ( V_74 -> V_87 ) ) ;
F_33 ( V_68 , V_59 , V_102 ) ;
F_34 ( V_68 , V_63 , V_102 , V_103 ) ;
} else if ( V_80 -> V_94 == V_104 ) {
struct V_105 * V_74 =
F_36 ( V_58 -> V_71 ,
V_106 ,
V_58 -> V_74 ) ;
struct V_105 * V_75 =
F_36 ( V_58 -> V_71 ,
V_106 ,
V_58 -> V_75 ) ;
memcpy ( F_32 ( V_68 , V_59 ,
V_98 . V_107 . V_108 ) ,
& V_75 -> V_93 , F_48 ( V_107 , V_108 ) ) ;
memcpy ( F_32 ( V_68 , V_63 ,
V_98 . V_107 . V_108 ) ,
& V_74 -> V_93 , F_48 ( V_107 , V_108 ) ) ;
memcpy ( F_32 ( V_68 , V_59 ,
V_101 . V_107 . V_108 ) ,
& V_75 -> V_87 , F_48 ( V_107 , V_108 ) ) ;
memcpy ( F_32 ( V_68 , V_63 ,
V_101 . V_107 . V_108 ) ,
& V_74 -> V_87 , F_48 ( V_107 , V_108 ) ) ;
F_33 ( V_68 , V_59 , V_102 ) ;
F_34 ( V_68 , V_63 , V_102 , V_109 ) ;
}
F_33 ( V_68 , V_59 , V_110 ) ;
F_33 ( V_68 , V_59 , V_111 ) ;
F_49 ( F_32 ( V_68 , V_63 ,
V_110 ) , V_3 -> V_33 -> V_112 ) ;
F_34 ( V_68 , V_59 , V_113 , 1 ) ;
F_34 ( V_68 , V_63 , V_113 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_57 * V_58 ,
T_2 * V_114 )
{
void * V_59 = F_32 ( V_60 , V_5 -> V_61 ,
V_62 ) ;
void * V_63 = F_32 ( V_60 , V_5 -> V_64 ,
V_62 ) ;
T_3 V_94 = 0 ;
T_2 V_115 = 0 ;
* V_114 = V_116 ;
if ( V_58 -> V_71 -> V_117 &
~ ( F_51 ( V_118 ) |
F_51 ( V_119 ) |
F_51 ( V_120 ) |
F_51 ( V_121 ) |
F_51 ( V_95 ) |
F_51 ( V_104 ) |
F_51 ( V_122 ) |
F_51 ( V_72 ) |
F_51 ( V_97 ) |
F_51 ( V_106 ) |
F_51 ( V_82 ) |
F_51 ( V_81 ) ) ) {
F_45 ( V_3 -> V_33 , L_4 ,
V_58 -> V_71 -> V_117 ) ;
return - V_90 ;
}
if ( ( F_35 ( V_58 -> V_71 ,
V_97 ) ||
F_35 ( V_58 -> V_71 , V_72 ) ||
F_35 ( V_58 -> V_71 , V_82 ) ) &&
F_35 ( V_58 -> V_71 , V_81 ) ) {
struct V_79 * V_74 =
F_36 ( V_58 -> V_71 ,
V_81 ,
V_58 -> V_74 ) ;
switch ( V_74 -> V_94 ) {
case V_95 :
case V_104 :
if ( F_38 ( V_3 , V_5 , V_58 ) )
return - V_90 ;
break;
default:
return - V_90 ;
}
V_59 = F_32 ( V_60 , V_5 -> V_61 ,
V_123 ) ;
V_63 = F_32 ( V_60 , V_5 -> V_64 ,
V_123 ) ;
}
if ( F_35 ( V_58 -> V_71 , V_118 ) ) {
struct V_79 * V_74 =
F_36 ( V_58 -> V_71 ,
V_118 ,
V_58 -> V_74 ) ;
struct V_79 * V_75 =
F_36 ( V_58 -> V_71 ,
V_118 ,
V_58 -> V_75 ) ;
V_94 = V_74 -> V_94 ;
if ( V_75 -> V_55 & V_124 ) {
F_34 ( V_68 , V_59 , V_113 , 1 ) ;
F_34 ( V_68 , V_63 , V_113 ,
V_74 -> V_55 & V_124 ) ;
if ( V_74 -> V_55 & V_124 )
* V_114 = V_125 ;
}
}
if ( F_35 ( V_58 -> V_71 , V_119 ) ) {
struct V_126 * V_74 =
F_36 ( V_58 -> V_71 ,
V_119 ,
V_58 -> V_74 ) ;
struct V_126 * V_75 =
F_36 ( V_58 -> V_71 ,
V_119 ,
V_58 -> V_75 ) ;
V_115 = V_74 -> V_115 ;
F_34 ( V_68 , V_59 , V_102 ,
F_46 ( V_75 -> V_127 ) ) ;
F_34 ( V_68 , V_63 , V_102 ,
F_46 ( V_74 -> V_127 ) ) ;
F_34 ( V_68 , V_59 , V_69 ,
V_75 -> V_115 ) ;
F_34 ( V_68 , V_63 , V_69 ,
V_74 -> V_115 ) ;
if ( V_75 -> V_115 )
* V_114 = V_125 ;
}
if ( F_35 ( V_58 -> V_71 , V_120 ) ) {
struct V_128 * V_74 =
F_36 ( V_58 -> V_71 ,
V_120 ,
V_58 -> V_74 ) ;
struct V_128 * V_75 =
F_36 ( V_58 -> V_71 ,
V_120 ,
V_58 -> V_75 ) ;
F_49 ( F_32 ( V_68 , V_59 ,
V_110 ) ,
V_75 -> V_87 ) ;
F_49 ( F_32 ( V_68 , V_63 ,
V_110 ) ,
V_74 -> V_87 ) ;
F_49 ( F_32 ( V_68 , V_59 ,
V_129 ) ,
V_75 -> V_93 ) ;
F_49 ( F_32 ( V_68 , V_63 ,
V_129 ) ,
V_74 -> V_93 ) ;
}
if ( F_35 ( V_58 -> V_71 , V_121 ) ) {
struct V_130 * V_74 =
F_36 ( V_58 -> V_71 ,
V_121 ,
V_58 -> V_74 ) ;
struct V_130 * V_75 =
F_36 ( V_58 -> V_71 ,
V_121 ,
V_58 -> V_75 ) ;
if ( V_75 -> V_131 || V_75 -> V_132 ) {
F_34 ( V_68 , V_59 , V_133 , 1 ) ;
F_34 ( V_68 , V_63 , V_133 , 1 ) ;
F_34 ( V_68 , V_59 , V_134 , V_75 -> V_131 ) ;
F_34 ( V_68 , V_63 , V_134 , V_74 -> V_131 ) ;
F_34 ( V_68 , V_59 , V_135 , V_75 -> V_132 ) ;
F_34 ( V_68 , V_63 , V_135 , V_74 -> V_132 ) ;
}
}
if ( V_94 == V_95 ) {
struct V_96 * V_74 =
F_36 ( V_58 -> V_71 ,
V_95 ,
V_58 -> V_74 ) ;
struct V_96 * V_75 =
F_36 ( V_58 -> V_71 ,
V_95 ,
V_58 -> V_75 ) ;
memcpy ( F_32 ( V_68 , V_59 ,
V_98 . V_99 . V_100 ) ,
& V_75 -> V_93 , sizeof( V_75 -> V_93 ) ) ;
memcpy ( F_32 ( V_68 , V_63 ,
V_98 . V_99 . V_100 ) ,
& V_74 -> V_93 , sizeof( V_74 -> V_93 ) ) ;
memcpy ( F_32 ( V_68 , V_59 ,
V_101 . V_99 . V_100 ) ,
& V_75 -> V_87 , sizeof( V_75 -> V_87 ) ) ;
memcpy ( F_32 ( V_68 , V_63 ,
V_101 . V_99 . V_100 ) ,
& V_74 -> V_87 , sizeof( V_74 -> V_87 ) ) ;
if ( V_75 -> V_93 || V_75 -> V_87 )
* V_114 = V_125 ;
}
if ( V_94 == V_104 ) {
struct V_105 * V_74 =
F_36 ( V_58 -> V_71 ,
V_104 ,
V_58 -> V_74 ) ;
struct V_105 * V_75 =
F_36 ( V_58 -> V_71 ,
V_104 ,
V_58 -> V_75 ) ;
memcpy ( F_32 ( V_68 , V_59 ,
V_98 . V_107 . V_108 ) ,
& V_75 -> V_93 , sizeof( V_75 -> V_93 ) ) ;
memcpy ( F_32 ( V_68 , V_63 ,
V_98 . V_107 . V_108 ) ,
& V_74 -> V_93 , sizeof( V_74 -> V_93 ) ) ;
memcpy ( F_32 ( V_68 , V_59 ,
V_101 . V_107 . V_108 ) ,
& V_75 -> V_87 , sizeof( V_75 -> V_87 ) ) ;
memcpy ( F_32 ( V_68 , V_63 ,
V_101 . V_107 . V_108 ) ,
& V_74 -> V_87 , sizeof( V_74 -> V_87 ) ) ;
if ( F_52 ( & V_75 -> V_93 ) != V_136 ||
F_52 ( & V_75 -> V_87 ) != V_136 )
* V_114 = V_125 ;
}
if ( F_35 ( V_58 -> V_71 , V_122 ) ) {
struct V_83 * V_74 =
F_36 ( V_58 -> V_71 ,
V_122 ,
V_58 -> V_74 ) ;
struct V_83 * V_75 =
F_36 ( V_58 -> V_71 ,
V_122 ,
V_58 -> V_75 ) ;
switch ( V_115 ) {
case V_137 :
F_34 ( V_68 , V_59 ,
V_138 , F_46 ( V_75 -> V_93 ) ) ;
F_34 ( V_68 , V_63 ,
V_138 , F_46 ( V_74 -> V_93 ) ) ;
F_34 ( V_68 , V_59 ,
V_139 , F_46 ( V_75 -> V_87 ) ) ;
F_34 ( V_68 , V_63 ,
V_139 , F_46 ( V_74 -> V_87 ) ) ;
break;
case V_70 :
F_34 ( V_68 , V_59 ,
V_92 , F_46 ( V_75 -> V_93 ) ) ;
F_34 ( V_68 , V_63 ,
V_92 , F_46 ( V_74 -> V_93 ) ) ;
F_34 ( V_68 , V_59 ,
V_91 , F_46 ( V_75 -> V_87 ) ) ;
F_34 ( V_68 , V_63 ,
V_91 , F_46 ( V_74 -> V_87 ) ) ;
break;
default:
F_7 ( V_3 -> V_33 ,
L_5 ) ;
return - V_140 ;
}
if ( V_75 -> V_93 || V_75 -> V_87 )
* V_114 = V_141 ;
}
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
struct V_4 * V_5 ,
struct V_57 * V_58 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
struct V_42 * V_43 = V_9 -> V_3 . V_44 ;
struct V_142 * V_143 = V_3 -> V_144 ;
T_2 V_114 ;
int V_45 ;
V_45 = F_50 ( V_3 , V_5 , V_58 , & V_114 ) ;
if ( ! V_45 && ( V_39 -> V_55 & V_56 ) &&
V_143 -> V_145 != V_146 ) {
if ( V_43 -> V_147 . V_148 != V_149 &&
V_43 -> V_147 . V_148 < V_114 ) {
F_45 ( V_3 -> V_33 ,
L_6 ,
V_114 , V_43 -> V_147 . V_148 ) ;
return - V_90 ;
}
}
return V_45 ;
}
static int F_54 ( struct V_2 * V_3 , struct V_150 * V_151 ,
T_1 * V_6 , T_1 * V_7 )
{
const struct V_152 * V_153 ;
F_55 ( V_154 ) ;
if ( F_56 ( V_151 ) )
return - V_140 ;
* V_7 = V_155 ;
* V_6 = 0 ;
F_57 ( V_151 , & V_154 ) ;
F_58 (a, &actions, list) {
if ( * V_6 )
return - V_140 ;
if ( F_59 ( V_153 ) ) {
* V_6 |= V_156 ;
if ( F_60 ( V_3 -> V_10 ,
V_157 . V_158 ) )
* V_6 |= V_26 ;
continue;
}
if ( F_61 ( V_153 ) ) {
T_1 V_159 = F_62 ( V_153 ) ;
if ( V_159 & ~ V_160 ) {
F_45 ( V_3 -> V_33 , L_7 ,
V_159 ) ;
return - V_140 ;
}
* V_7 = V_159 ;
* V_6 |= V_20 ;
continue;
}
return - V_140 ;
}
return 0 ;
}
static inline int F_63 ( struct V_161 * V_153 ,
struct V_161 * V_162 )
{
return memcmp ( V_153 , V_162 , sizeof( * V_153 ) ) ;
}
static inline int F_64 ( struct V_161 * V_74 )
{
return F_65 ( V_74 , sizeof( * V_74 ) , 0 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_84 * V_163 ,
struct V_84 * * V_164 ,
struct V_165 * V_166 ,
struct V_167 * * V_168 ,
int * V_169 )
{
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
struct V_170 * V_171 ;
struct V_167 * V_53 = NULL ;
#if F_67 ( V_172 )
int V_173 ;
V_171 = F_68 ( F_69 ( V_163 ) , V_166 ) ;
V_173 = F_70 ( V_171 ) ;
if ( V_173 )
return V_173 ;
#else
return - V_90 ;
#endif
if ( ! F_71 ( V_3 -> V_33 , V_171 -> V_87 . V_9 ) )
* V_164 = F_39 ( V_43 ) ;
else
* V_164 = V_171 -> V_87 . V_9 ;
* V_169 = F_72 ( & V_171 -> V_87 ) ;
V_53 = F_73 ( & V_171 -> V_87 , & V_166 -> V_174 ) ;
F_74 ( V_171 ) ;
if ( ! V_53 )
return - V_175 ;
* V_168 = V_53 ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_84 * V_163 ,
struct V_84 * * V_164 ,
struct V_176 * V_177 ,
struct V_167 * * V_168 ,
int * V_169 )
{
struct V_167 * V_53 = NULL ;
struct V_178 * V_87 ;
#if F_67 ( V_172 ) && F_67 ( V_179 )
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
int V_173 ;
V_87 = F_76 ( F_69 ( V_163 ) , NULL , V_177 ) ;
V_173 = V_87 -> error ;
if ( V_173 ) {
F_77 ( V_87 ) ;
return V_173 ;
}
* V_169 = F_78 ( V_87 ) ;
if ( ! F_71 ( V_3 -> V_33 , V_87 -> V_9 ) )
* V_164 = F_39 ( V_43 ) ;
else
* V_164 = V_87 -> V_9 ;
#else
return - V_90 ;
#endif
V_53 = F_73 ( V_87 , & V_177 -> V_174 ) ;
F_77 ( V_87 ) ;
if ( ! V_53 )
return - V_175 ;
* V_168 = V_53 ;
return 0 ;
}
static void F_79 ( struct V_84 * V_164 ,
char V_180 [] , int V_181 ,
unsigned char V_182 [ V_183 ] ,
int V_184 ,
T_4 V_174 ,
T_4 V_185 ,
T_5 V_186 ,
T_4 V_187 )
{
struct V_188 * V_189 = (struct V_188 * ) V_180 ;
struct V_190 * V_191 = (struct V_190 * ) ( ( char * ) V_189 + sizeof( struct V_188 ) ) ;
struct V_192 * V_193 = (struct V_192 * ) ( ( char * ) V_191 + sizeof( struct V_190 ) ) ;
struct V_194 * V_195 = (struct V_194 * ) ( ( char * ) V_193 + sizeof( struct V_192 ) ) ;
memset ( V_180 , 0 , V_181 ) ;
F_49 ( V_189 -> V_182 , V_182 ) ;
F_49 ( V_189 -> V_196 , V_164 -> V_112 ) ;
V_189 -> V_197 = F_80 ( V_103 ) ;
V_191 -> V_174 = V_174 ;
V_191 -> V_185 = V_185 ;
V_191 -> V_184 = V_184 ;
V_191 -> V_198 = V_70 ;
V_191 -> V_199 = 0x4 ;
V_191 -> V_200 = 0x5 ;
V_193 -> V_12 = V_186 ;
V_195 -> V_201 = V_202 ;
V_195 -> V_187 = F_81 ( V_187 ) ;
}
static void F_82 ( struct V_84 * V_164 ,
char V_180 [] , int V_181 ,
unsigned char V_182 [ V_183 ] ,
int V_184 ,
struct V_203 * V_174 ,
struct V_203 * V_185 ,
T_5 V_186 ,
T_4 V_187 )
{
struct V_188 * V_189 = (struct V_188 * ) V_180 ;
struct V_204 * V_205 = (struct V_204 * ) ( ( char * ) V_189 + sizeof( struct V_188 ) ) ;
struct V_192 * V_193 = (struct V_192 * ) ( ( char * ) V_205 + sizeof( struct V_204 ) ) ;
struct V_194 * V_195 = (struct V_194 * ) ( ( char * ) V_193 + sizeof( struct V_192 ) ) ;
memset ( V_180 , 0 , V_181 ) ;
F_49 ( V_189 -> V_182 , V_182 ) ;
F_49 ( V_189 -> V_196 , V_164 -> V_112 ) ;
V_189 -> V_197 = F_80 ( V_109 ) ;
F_83 ( V_205 , 0 , 0 ) ;
V_205 -> V_206 = V_70 ;
V_205 -> V_207 = V_184 ;
V_205 -> V_174 = * V_174 ;
V_205 -> V_185 = * V_185 ;
V_193 -> V_12 = V_186 ;
V_195 -> V_201 = V_202 ;
V_195 -> V_187 = F_81 ( V_187 ) ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_84 * V_163 ,
struct V_50 * V_51 ,
struct V_84 * * V_164 )
{
int V_208 = F_44 ( V_3 -> V_10 , V_209 ) ;
int V_210 = V_211 + sizeof( struct V_190 ) + V_212 ;
struct V_161 * V_213 = & V_51 -> V_214 . V_74 ;
struct V_167 * V_53 = NULL ;
struct V_165 V_166 = {} ;
char * V_215 ;
int V_184 , V_45 ;
if ( V_208 < V_210 ) {
F_85 ( V_3 -> V_10 , L_8 ,
V_210 , V_208 ) ;
return - V_90 ;
}
V_215 = F_86 ( V_210 , V_216 ) ;
if ( ! V_215 )
return - V_175 ;
switch ( V_51 -> V_217 ) {
case V_218 :
V_166 . V_219 = V_70 ;
V_166 . V_220 = V_213 -> V_221 ;
break;
default:
V_45 = - V_90 ;
goto V_222;
}
V_166 . V_223 = V_213 -> V_224 ;
V_166 . V_174 = V_213 -> V_225 . V_100 . V_87 ;
V_166 . V_185 = V_213 -> V_225 . V_100 . V_93 ;
V_45 = F_66 ( V_3 , V_163 , V_164 ,
& V_166 , & V_53 , & V_184 ) ;
if ( V_45 )
goto V_222;
if ( ! ( V_53 -> V_226 & V_227 ) ) {
F_87 ( L_9 , V_228 , & V_166 . V_174 ) ;
V_45 = - V_90 ;
goto V_222;
}
V_51 -> V_53 = V_53 ;
V_51 -> V_164 = * V_164 ;
F_88 ( V_51 -> V_182 , V_53 , * V_164 ) ;
switch ( V_51 -> V_217 ) {
case V_218 :
F_79 ( * V_164 , V_215 ,
V_210 , V_51 -> V_182 , V_184 ,
V_166 . V_174 ,
V_166 . V_185 , V_213 -> V_221 ,
F_89 ( V_213 -> V_229 ) ) ;
break;
default:
V_45 = - V_90 ;
goto V_222;
}
V_45 = F_90 ( V_3 -> V_10 , V_51 -> V_217 ,
V_210 , V_215 , & V_51 -> V_15 ) ;
V_222:
if ( V_45 && V_53 )
F_27 ( V_53 ) ;
F_29 ( V_215 ) ;
return V_45 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_84 * V_163 ,
struct V_50 * V_51 ,
struct V_84 * * V_164 )
{
int V_208 = F_44 ( V_3 -> V_10 , V_209 ) ;
int V_230 = V_211 + sizeof( struct V_204 ) + V_212 ;
struct V_161 * V_213 = & V_51 -> V_214 . V_74 ;
struct V_167 * V_53 = NULL ;
struct V_176 V_177 = {} ;
char * V_215 ;
int V_45 , V_184 = 0 ;
if ( V_208 < V_230 ) {
F_85 ( V_3 -> V_10 , L_8 ,
V_230 , V_208 ) ;
return - V_90 ;
}
V_215 = F_86 ( V_230 , V_216 ) ;
if ( ! V_215 )
return - V_175 ;
switch ( V_51 -> V_217 ) {
case V_218 :
V_177 . V_231 = V_70 ;
V_177 . V_232 = V_213 -> V_221 ;
break;
default:
V_45 = - V_90 ;
goto V_222;
}
V_177 . V_233 = F_92 ( F_93 ( V_213 -> V_224 ) , V_213 -> V_234 ) ;
V_177 . V_174 = V_213 -> V_225 . V_108 . V_87 ;
V_177 . V_185 = V_213 -> V_225 . V_108 . V_93 ;
V_45 = F_75 ( V_3 , V_163 , V_164 ,
& V_177 , & V_53 , & V_184 ) ;
if ( V_45 )
goto V_222;
if ( ! ( V_53 -> V_226 & V_227 ) ) {
F_87 ( L_10 , V_228 , & V_177 . V_174 ) ;
V_45 = - V_90 ;
goto V_222;
}
V_51 -> V_53 = V_53 ;
V_51 -> V_164 = * V_164 ;
F_88 ( V_51 -> V_182 , V_53 , * V_164 ) ;
switch ( V_51 -> V_217 ) {
case V_218 :
F_82 ( * V_164 , V_215 ,
V_230 , V_51 -> V_182 , V_184 ,
& V_177 . V_174 ,
& V_177 . V_185 , V_213 -> V_221 ,
F_89 ( V_213 -> V_229 ) ) ;
break;
default:
V_45 = - V_90 ;
goto V_222;
}
V_45 = F_90 ( V_3 -> V_10 , V_51 -> V_217 ,
V_230 , V_215 , & V_51 -> V_15 ) ;
V_222:
if ( V_45 && V_53 )
F_27 ( V_53 ) ;
F_29 ( V_215 ) ;
return V_45 ;
}
static int F_94 ( struct V_2 * V_3 ,
struct V_235 * V_214 ,
struct V_84 * V_163 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
struct V_84 * V_85 = F_39 ( V_43 ) ;
struct V_2 * V_86 = F_40 ( V_85 ) ;
unsigned short V_236 = F_95 ( V_214 ) ;
struct V_161 * V_74 = & V_214 -> V_74 ;
struct V_50 * V_51 ;
struct V_84 * V_164 ;
int V_217 , V_45 = - V_90 ;
T_6 V_237 ;
bool V_238 = false ;
if ( ! F_41 ( & V_74 -> V_221 , 0 , sizeof( V_74 -> V_221 ) ) )
goto V_239;
if ( F_41 ( & V_74 -> V_240 , 0 , sizeof( V_74 -> V_240 ) ) ) {
V_239:
F_45 ( V_3 -> V_33 ,
L_11 ) ;
return - V_90 ;
}
if ( F_42 ( V_86 , F_43 ( V_74 -> V_221 ) ) &&
F_44 ( V_3 -> V_10 , V_89 ) ) {
V_217 = V_218 ;
} else {
F_45 ( V_3 -> V_33 ,
L_2 , F_43 ( V_74 -> V_221 ) ) ;
return - V_90 ;
}
V_237 = F_64 ( V_74 ) ;
F_96 (esw->offloads.encap_tbl, e,
encap_hlist, hash_key) {
if ( ! F_63 ( & V_51 -> V_214 . V_74 , V_74 ) ) {
V_238 = true ;
break;
}
}
if ( V_238 ) {
V_41 -> V_49 = V_51 ;
return 0 ;
}
V_51 = F_86 ( sizeof( * V_51 ) , V_216 ) ;
if ( ! V_51 )
return - V_175 ;
V_51 -> V_214 = * V_214 ;
V_51 -> V_217 = V_217 ;
F_97 ( & V_51 -> V_52 ) ;
if ( V_236 == V_241 )
V_45 = F_84 ( V_3 , V_163 , V_51 , & V_164 ) ;
else if ( V_236 == V_242 )
V_45 = F_91 ( V_3 , V_163 , V_51 , & V_164 ) ;
if ( V_45 )
goto V_243;
V_41 -> V_49 = V_51 ;
F_98 ( V_43 -> V_147 . V_244 , & V_51 -> V_54 , V_237 ) ;
return V_45 ;
V_243:
F_29 ( V_51 ) ;
return V_45 ;
}
static int F_99 ( struct V_2 * V_3 , struct V_150 * V_151 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
struct V_235 * V_245 = NULL ;
const struct V_152 * V_153 ;
F_55 ( V_154 ) ;
bool V_49 = false ;
int V_45 ;
if ( F_56 ( V_151 ) )
return - V_140 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_246 = V_3 -> V_144 ;
F_57 ( V_151 , & V_154 ) ;
F_58 (a, &actions, list) {
if ( F_59 ( V_153 ) ) {
V_41 -> V_6 |= V_156 |
V_26 ;
continue;
}
if ( F_100 ( V_153 ) ) {
int V_247 = F_101 ( V_153 ) ;
struct V_84 * V_164 ;
struct V_2 * V_248 ;
V_164 = F_102 ( F_69 ( V_3 -> V_33 ) , V_247 ) ;
if ( F_71 ( V_3 -> V_33 ,
V_164 ) ) {
V_41 -> V_6 |= V_20 |
V_26 ;
V_248 = F_40 ( V_164 ) ;
V_41 -> V_249 = V_248 -> V_144 ;
} else if ( V_49 ) {
V_45 = F_94 ( V_3 , V_245 ,
V_164 , V_41 ) ;
if ( V_45 )
return V_45 ;
F_103 ( & V_39 -> V_49 , & V_41 -> V_49 -> V_52 ) ;
V_41 -> V_6 |= V_46 |
V_20 |
V_26 ;
V_248 = F_40 ( V_41 -> V_49 -> V_164 ) ;
V_41 -> V_249 = V_248 -> V_144 ;
} else {
F_104 ( L_12 ,
V_3 -> V_33 -> V_250 , V_164 -> V_250 ) ;
return - V_140 ;
}
continue;
}
if ( F_105 ( V_153 ) ) {
V_245 = F_106 ( V_153 ) ;
if ( V_245 )
V_49 = true ;
else
return - V_90 ;
continue;
}
if ( F_107 ( V_153 ) ) {
if ( F_108 ( V_153 ) == V_251 ) {
V_41 -> V_6 |= V_252 ;
} else if ( F_108 ( V_153 ) == V_253 ) {
if ( F_109 ( V_153 ) != F_80 ( V_254 ) )
return - V_90 ;
V_41 -> V_6 |= V_255 ;
V_41 -> V_24 = F_110 ( V_153 ) ;
} else {
return - V_90 ;
}
continue;
}
if ( F_111 ( V_153 ) ) {
V_41 -> V_6 |= V_256 ;
continue;
}
return - V_140 ;
}
return 0 ;
}
int F_112 ( struct V_2 * V_3 , T_5 V_198 ,
struct V_57 * V_58 )
{
struct V_257 * V_28 = & V_3 -> V_23 . V_28 ;
int V_45 , V_258 = 0 ;
T_1 V_7 , V_6 ;
struct V_38 * V_39 ;
struct V_4 * V_5 ;
struct V_42 * V_43 = V_3 -> V_10 -> V_3 . V_44 ;
T_2 V_259 = 0 ;
if ( V_43 && V_43 -> V_260 == V_261 ) {
V_259 = V_56 ;
V_258 = sizeof( struct V_40 ) ;
}
V_39 = F_86 ( sizeof( * V_39 ) + V_258 , V_216 ) ;
V_5 = F_113 ( sizeof( * V_5 ) ) ;
if ( ! V_5 || ! V_39 ) {
V_45 = - V_175 ;
goto V_262;
}
V_39 -> V_263 = V_58 -> V_263 ;
V_39 -> V_55 = V_259 ;
V_45 = F_53 ( V_3 , V_39 , V_5 , V_58 ) ;
if ( V_45 < 0 )
goto V_262;
if ( V_39 -> V_55 & V_56 ) {
V_39 -> V_41 = (struct V_40 * ) ( V_39 + 1 ) ;
V_45 = F_99 ( V_3 , V_58 -> V_151 , V_39 ) ;
if ( V_45 < 0 )
goto V_262;
V_39 -> V_18 = F_15 ( V_3 , V_5 , V_39 -> V_41 ) ;
} else {
V_45 = F_54 ( V_3 , V_58 -> V_151 , & V_6 , & V_7 ) ;
if ( V_45 < 0 )
goto V_262;
V_39 -> V_18 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
}
if ( F_3 ( V_39 -> V_18 ) ) {
V_45 = F_114 ( V_39 -> V_18 ) ;
goto V_264;
}
V_45 = F_115 ( & V_28 -> V_265 , & V_39 -> V_266 ,
V_28 -> V_267 ) ;
if ( V_45 )
goto V_264;
goto V_222;
V_264:
F_30 ( V_3 , V_39 ) ;
V_262:
F_29 ( V_39 ) ;
V_222:
F_116 ( V_5 ) ;
return V_45 ;
}
int F_117 ( struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_38 * V_39 ;
struct V_257 * V_28 = & V_3 -> V_23 . V_28 ;
V_39 = F_118 ( & V_28 -> V_265 , & V_58 -> V_263 ,
V_28 -> V_267 ) ;
if ( ! V_39 )
return - V_140 ;
F_119 ( & V_28 -> V_265 , & V_39 -> V_266 , V_28 -> V_267 ) ;
F_30 ( V_3 , V_39 ) ;
F_29 ( V_39 ) ;
return 0 ;
}
int F_120 ( struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_257 * V_28 = & V_3 -> V_23 . V_28 ;
struct V_38 * V_39 ;
struct V_152 * V_153 ;
struct V_16 * V_17 ;
F_55 ( V_154 ) ;
T_7 V_268 ;
T_7 V_269 ;
T_7 V_270 ;
V_39 = F_118 ( & V_28 -> V_265 , & V_58 -> V_263 ,
V_28 -> V_267 ) ;
if ( ! V_39 )
return - V_140 ;
V_17 = F_12 ( V_39 -> V_18 ) ;
if ( ! V_17 )
return 0 ;
F_121 ( V_17 , & V_268 , & V_269 , & V_270 ) ;
F_122 () ;
F_57 ( V_58 -> V_151 , & V_154 ) ;
F_58 (a, &actions, list)
F_123 ( V_153 , V_268 , V_269 , V_270 ) ;
F_124 () ;
return 0 ;
}
int F_125 ( struct V_2 * V_3 )
{
struct V_257 * V_28 = & V_3 -> V_23 . V_28 ;
V_28 -> V_267 = V_271 ;
return F_126 ( & V_28 -> V_265 , & V_28 -> V_267 ) ;
}
static void F_127 ( void * V_272 , void * V_273 )
{
struct V_38 * V_39 = V_272 ;
struct V_2 * V_3 = V_273 ;
F_30 ( V_3 , V_39 ) ;
F_29 ( V_39 ) ;
}
void F_128 ( struct V_2 * V_3 )
{
struct V_257 * V_28 = & V_3 -> V_23 . V_28 ;
F_129 ( & V_28 -> V_265 , F_127 , V_3 ) ;
if ( ! F_5 ( V_28 -> V_25 ) ) {
F_9 ( V_28 -> V_25 ) ;
V_28 -> V_25 = NULL ;
}
}
