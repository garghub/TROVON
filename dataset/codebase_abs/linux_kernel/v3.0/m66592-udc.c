static inline T_1 F_1 ( struct V_1 * V_1 )
{
return ( F_2 ( V_1 , V_2 ) & V_3 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_4 ,
unsigned long V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_1 , V_7 ) ;
F_4 ( V_1 , V_8 | V_9 | V_10 ,
V_7 ) ;
F_5 ( V_1 , ( 1 << V_4 ) , V_5 ) ;
F_6 ( V_1 , V_6 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_4 ,
unsigned long V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_1 , V_7 ) ;
F_4 ( V_1 , V_8 | V_9 | V_10 ,
V_7 ) ;
F_4 ( V_1 , ( 1 << V_4 ) , V_5 ) ;
F_6 ( V_1 , V_6 , V_7 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_11 , V_7 ) ;
F_5 ( V_1 , V_12 | V_13 | V_14 ,
V_7 ) ;
F_5 ( V_1 , V_8 | V_10 , V_7 ) ;
F_5 ( V_1 , V_15 , V_16 ) ;
}
static void F_9 ( struct V_1 * V_1 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
F_4 ( V_1 , V_11 , V_7 ) ;
F_4 ( V_1 , V_12 | V_13 | V_14 ,
V_7 ) ;
F_4 ( V_1 , V_8 | V_10 , V_7 ) ;
F_4 ( V_1 , V_15 , V_16 ) ;
V_1 -> V_18 . V_19 = V_20 ;
F_10 ( & V_1 -> V_17 ) ;
V_1 -> V_21 -> V_22 ( & V_1 -> V_18 ) ;
F_11 ( & V_1 -> V_17 ) ;
F_12 ( V_1 ) ;
F_13 ( & V_1 -> V_23 [ 0 ] . V_24 ) ;
}
static inline T_1 F_14 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_25 = 0 ;
unsigned long V_26 ;
if ( V_4 == 0 )
V_25 = F_2 ( V_1 , V_27 ) & V_28 ;
else if ( V_4 < V_29 ) {
V_26 = F_15 ( V_4 ) ;
V_25 = F_2 ( V_1 , V_26 ) & V_28 ;
} else
F_16 ( L_1 , V_4 ) ;
return V_25 ;
}
static inline void F_17 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_25 )
{
unsigned long V_26 ;
if ( V_4 == 0 )
F_18 ( V_1 , V_25 , V_28 , V_27 ) ;
else if ( V_4 < V_29 ) {
V_26 = F_15 ( V_4 ) ;
F_18 ( V_1 , V_25 , V_28 , V_26 ) ;
} else
F_16 ( L_1 , V_4 ) ;
}
static inline void F_19 ( struct V_1 * V_1 , T_1 V_4 )
{
F_17 ( V_1 , V_4 , V_30 ) ;
}
static inline void F_20 ( struct V_1 * V_1 , T_1 V_4 )
{
F_17 ( V_1 , V_4 , V_31 ) ;
}
static inline void F_21 ( struct V_1 * V_1 , T_1 V_4 )
{
F_17 ( V_1 , V_4 , V_32 ) ;
}
static inline T_1 F_22 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_33 = 0 ;
unsigned long V_26 ;
if ( V_4 == 0 )
V_33 = F_2 ( V_1 , V_27 ) ;
else if ( V_4 < V_29 ) {
V_26 = F_15 ( V_4 ) ;
V_33 = F_2 ( V_1 , V_26 ) ;
} else
F_16 ( L_1 , V_4 ) ;
return V_33 ;
}
static inline void F_23 ( struct V_1 * V_1 , T_1 V_4 )
{
unsigned long V_26 ;
F_20 ( V_1 , V_4 ) ;
if ( V_4 == 0 )
F_5 ( V_1 , V_34 , V_27 ) ;
else if ( V_4 < V_29 ) {
V_26 = F_15 ( V_4 ) ;
F_5 ( V_1 , V_34 , V_26 ) ;
} else
F_16 ( L_2 , V_4 ) ;
}
static inline int F_24 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_6 ;
int V_35 ;
if ( V_4 == 0 ) {
V_6 = F_2 ( V_1 , V_36 ) ;
if ( ( V_6 & V_37 ) != 0 )
V_35 = 256 ;
else {
V_6 = F_2 ( V_1 , V_38 ) ;
V_35 = V_6 & V_39 ;
}
} else {
F_6 ( V_1 , V_4 , V_40 ) ;
V_6 = F_2 ( V_1 , V_41 ) ;
if ( ( V_6 & V_37 ) != 0 ) {
V_6 = F_2 ( V_1 , V_42 ) ;
V_35 = ( ( V_6 >> 10 ) + 1 ) * 64 ;
} else {
V_6 = F_2 ( V_1 , V_43 ) ;
V_35 = V_6 & V_44 ;
}
}
return V_35 ;
}
static inline void F_25 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_45 * V_23 = V_1 -> V_46 [ V_4 ] ;
unsigned short V_47 ;
if ( V_23 -> V_48 )
return;
F_18 ( V_1 , V_4 , V_49 , V_23 -> V_50 ) ;
F_26 ( 450 ) ;
if ( V_1 -> V_51 -> V_52 )
V_47 = V_53 ;
else
V_47 = V_54 ;
F_5 ( V_1 , V_47 , V_23 -> V_50 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_55 * V_56 )
{
T_1 V_57 = 0 , V_58 = 0 ;
T_1 V_59 = 0 ;
if ( V_56 -> V_60 == 0 )
return - V_61 ;
F_6 ( V_1 , V_56 -> V_60 , V_40 ) ;
if ( V_56 -> V_62 )
V_59 |= V_63 ;
V_59 |= V_56 -> type ;
V_59 |= V_56 -> V_64 ;
switch ( V_56 -> type ) {
case V_65 :
V_57 = 4 + ( V_56 -> V_60 - V_66 ) ;
V_58 = 0 ;
break;
case V_67 :
if ( V_56 -> V_60 >= V_68 )
V_57 = V_56 -> V_60 - V_68 ;
else
V_57 = V_56 -> V_60 - V_69 ;
V_57 = V_70 + ( V_57 * 16 ) ;
V_58 = 7 ;
V_59 |= V_71 ;
if ( ! V_56 -> V_62 )
V_59 |= V_72 ;
break;
case V_73 :
V_57 = V_70 +
( V_56 -> V_60 - V_69 ) * 16 ;
V_58 = 7 ;
break;
}
if ( V_58 && ( ( V_57 + 16 ) >= V_74 ) ) {
F_16 ( L_3 ) ;
return - V_75 ;
}
F_6 ( V_1 , V_59 , V_41 ) ;
F_6 ( V_1 , ( V_58 << 10 ) | ( V_57 ) , V_42 ) ;
F_6 ( V_1 , V_56 -> V_76 , V_43 ) ;
if ( V_56 -> V_77 )
V_56 -> V_77 -- ;
F_6 ( V_1 , V_56 -> V_77 , V_78 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_1 ,
struct V_55 * V_56 )
{
if ( V_56 -> V_60 == 0 )
return;
if ( F_29 ( V_56 -> V_60 ) ) {
V_1 -> V_79 -- ;
} else if ( F_30 ( V_56 -> V_60 ) )
V_1 -> V_80 -- ;
else if ( F_31 ( V_56 -> V_60 ) ) {
V_1 -> V_81 -- ;
if ( V_56 -> type == V_67 )
V_1 -> V_79 -- ;
} else
F_16 ( L_4 ,
V_56 -> V_60 ) ;
}
static void F_32 ( struct V_45 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
unsigned short V_47 ;
F_18 ( V_1 , 0 , V_49 , V_23 -> V_50 ) ;
F_6 ( V_1 , V_82 , V_23 -> V_83 ) ;
F_6 ( V_1 , 0 , V_23 -> V_83 ) ;
F_6 ( V_1 , V_34 , V_23 -> V_83 ) ;
if ( V_23 -> V_48 ) {
F_18 ( V_1 , V_23 -> V_4 , V_49 , V_23 -> V_50 ) ;
F_26 ( 450 ) ;
if ( V_1 -> V_51 -> V_52 )
V_47 = V_53 ;
else
V_47 = V_54 ;
F_5 ( V_1 , V_47 , V_23 -> V_50 ) ;
}
}
static void F_33 ( struct V_1 * V_1 , struct V_45 * V_23 ,
const struct V_84 * V_85 ,
T_1 V_4 , int V_86 )
{
if ( ( V_4 != 0 ) && V_86 ) {
if ( V_1 -> V_87 == 0 ) {
V_1 -> V_87 ++ ;
V_23 -> V_48 = 1 ;
V_23 -> V_88 = V_89 ;
V_23 -> V_50 = V_90 ;
V_23 -> V_91 = V_92 ;
V_23 -> V_93 = V_94 ;
} else if ( ! V_1 -> V_51 -> V_52 && V_1 -> V_87 == 1 ) {
V_1 -> V_87 ++ ;
V_23 -> V_48 = 1 ;
V_23 -> V_88 = V_95 ;
V_23 -> V_50 = V_96 ;
V_23 -> V_91 = V_97 ;
V_23 -> V_93 = V_98 ;
} else {
V_23 -> V_48 = 0 ;
V_23 -> V_88 = V_99 ;
V_23 -> V_50 = V_100 ;
V_23 -> V_91 = V_101 ;
V_23 -> V_93 = 0 ;
}
} else {
V_23 -> V_48 = 0 ;
V_23 -> V_88 = V_99 ;
V_23 -> V_50 = V_100 ;
V_23 -> V_91 = V_101 ;
V_23 -> V_93 = 0 ;
}
V_23 -> V_83 = F_15 ( V_4 ) ;
V_23 -> V_4 = V_4 ;
V_23 -> V_23 . V_76 = F_34 ( V_85 -> V_102 ) ;
V_1 -> V_46 [ V_4 ] = V_23 ;
V_1 -> V_103 [ V_85 -> V_104 & V_105 ] = V_23 ;
F_13 ( & V_23 -> V_24 ) ;
}
static void F_35 ( struct V_45 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
T_1 V_4 = V_23 -> V_4 ;
if ( V_4 == 0 )
return;
if ( V_23 -> V_48 )
V_1 -> V_87 -- ;
V_23 -> V_4 = 0 ;
V_23 -> V_106 = 0 ;
V_23 -> V_48 = 0 ;
}
static int F_36 ( struct V_45 * V_23 ,
const struct V_84 * V_85 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
struct V_55 V_56 ;
int V_86 = 0 ;
int * V_107 ;
int V_33 ;
V_23 -> V_85 = V_85 ;
F_37 ( V_23 -> V_4 ) ;
switch ( V_85 -> V_108 & V_109 ) {
case V_110 :
if ( V_1 -> V_79 >= V_111 ) {
if ( V_1 -> V_81 >= V_112 ) {
F_16 ( L_5 ) ;
return - V_113 ;
} else {
V_56 . V_60 = V_69
+ V_1 -> V_81 ;
V_107 = & V_1 -> V_81 ;
}
} else {
V_56 . V_60 = V_68 + V_1 -> V_79 ;
V_107 = & V_1 -> V_79 ;
}
V_56 . type = V_67 ;
V_86 = 1 ;
break;
case V_114 :
if ( V_1 -> V_80 >= V_115 ) {
F_16 ( L_6 ) ;
return - V_113 ;
}
V_56 . V_60 = V_66 + V_1 -> V_80 ;
V_56 . type = V_65 ;
V_107 = & V_1 -> V_80 ;
break;
case V_116 :
if ( V_1 -> V_81 >= V_112 ) {
F_16 ( L_7 ) ;
return - V_113 ;
}
V_56 . V_60 = V_69 + V_1 -> V_81 ;
V_56 . type = V_73 ;
V_107 = & V_1 -> V_81 ;
break;
default:
F_16 ( L_8 ) ;
return - V_61 ;
}
V_23 -> type = V_56 . type ;
V_56 . V_64 = V_85 -> V_104 & V_105 ;
V_56 . V_76 = F_34 ( V_85 -> V_102 ) ;
V_56 . V_77 = V_85 -> V_117 ;
if ( V_85 -> V_104 & V_118 )
V_56 . V_62 = 1 ;
else
V_56 . V_62 = 0 ;
V_33 = F_27 ( V_1 , & V_56 ) ;
if ( V_33 < 0 ) {
F_16 ( L_9 ) ;
return V_33 ;
}
( * V_107 ) ++ ;
if ( ( V_107 == & V_1 -> V_81 ) && V_56 . type == V_67 )
V_1 -> V_79 ++ ;
F_33 ( V_1 , V_23 , V_85 , V_56 . V_60 , V_86 ) ;
F_32 ( V_23 ) ;
return 0 ;
}
static int F_38 ( struct V_45 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
struct V_55 V_56 ;
V_56 . V_60 = V_23 -> V_4 ;
V_56 . type = V_23 -> type ;
F_28 ( V_1 , & V_56 ) ;
F_35 ( V_23 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_1 , T_1 V_4 )
{
F_40 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
}
static void F_42 ( struct V_1 * V_1 , T_1 V_4 )
{
F_43 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
}
static void F_45 ( struct V_1 * V_1 , unsigned V_119 )
{
V_1 -> V_23 [ 0 ] . V_120 = V_119 ;
F_19 ( V_1 , 0 ) ;
F_5 ( V_1 , V_121 , V_27 ) ;
}
static void F_46 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
F_25 ( V_1 , V_23 -> V_4 ) ;
F_18 ( V_1 , V_124 | V_125 ,
( V_124 | V_49 ) ,
V_100 ) ;
F_6 ( V_1 , V_126 , V_23 -> V_91 ) ;
if ( V_123 -> V_123 . V_127 == 0 ) {
F_5 ( V_1 , V_128 , V_23 -> V_91 ) ;
F_19 ( V_1 , 0 ) ;
F_47 ( V_23 , V_123 , 0 ) ;
} else {
F_6 ( V_1 , ~ V_129 , V_130 ) ;
F_48 ( V_23 , V_123 ) ;
}
}
static void F_49 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
T_1 V_6 ;
F_25 ( V_1 , V_23 -> V_4 ) ;
F_50 ( V_1 , V_23 -> V_4 ) ;
F_19 ( V_1 , V_23 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( F_51 ( ( V_6 & V_131 ) == 0 ) )
F_39 ( V_1 , V_23 -> V_4 ) ;
else
F_52 ( V_23 , V_123 ) ;
}
static void F_53 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
T_1 V_4 = V_23 -> V_4 ;
if ( V_23 -> V_4 == 0 ) {
F_18 ( V_1 , V_125 ,
( V_124 | V_49 ) ,
V_100 ) ;
F_6 ( V_1 , V_126 , V_23 -> V_91 ) ;
F_19 ( V_1 , V_4 ) ;
F_39 ( V_1 , V_4 ) ;
} else {
if ( V_23 -> V_48 ) {
F_5 ( V_1 , V_132 , V_23 -> V_50 ) ;
F_25 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_133 , V_23 -> V_50 ) ;
F_6 ( V_1 ,
( V_123 -> V_123 . V_127 + V_23 -> V_23 . V_76 - 1 )
/ V_23 -> V_23 . V_76 ,
V_23 -> V_93 ) ;
}
F_19 ( V_1 , V_4 ) ;
F_39 ( V_1 , V_4 ) ;
}
}
static void F_54 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
if ( V_23 -> V_85 -> V_104 & V_134 )
F_49 ( V_23 , V_123 ) ;
else
F_53 ( V_23 , V_123 ) ;
}
static void F_55 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
T_1 V_135 ;
V_135 = F_2 ( V_23 -> V_1 , V_136 ) & V_137 ;
switch ( V_135 ) {
case V_138 :
F_46 ( V_23 , V_123 ) ;
break;
case V_139 :
F_53 ( V_23 , V_123 ) ;
break;
case V_140 :
F_45 ( V_23 -> V_1 , 0 ) ;
break;
default:
F_16 ( L_10 , V_135 ) ;
break;
}
}
static void F_56 ( struct V_1 * V_1 )
{
unsigned int V_141 ;
if ( V_1 -> V_51 -> V_52 ) {
if ( V_1 -> V_51 -> V_141 )
V_141 = 0 ;
else
V_141 = V_142 ;
F_5 ( V_1 , V_143 , V_16 ) ;
F_4 ( V_1 , V_144 , V_16 ) ;
F_4 ( V_1 , V_15 , V_16 ) ;
F_5 ( V_1 , V_144 , V_16 ) ;
F_5 ( V_1 , 0x8000 , V_2 ) ;
F_5 ( V_1 , 0x1000 , V_145 ) ;
F_4 ( V_1 , 0x8000 , V_2 ) ;
F_5 ( V_1 , V_146 , V_147 ) ;
F_6 ( V_1 , 0 , V_148 ) ;
F_6 ( V_1 , 0 , V_149 ) ;
F_5 ( V_1 , V_141 , V_148 ) ;
F_5 ( V_1 , V_141 , V_149 ) ;
} else {
unsigned int clock , V_150 , V_151 ;
if ( V_1 -> V_51 -> V_141 )
V_141 = V_152 ;
else
V_141 = 0 ;
if ( V_1 -> V_51 -> V_150 )
V_150 = V_153 ;
else
V_150 = 0 ;
switch ( V_1 -> V_51 -> V_154 ) {
case V_155 :
clock = V_156 ;
break;
case V_157 :
clock = V_158 ;
break;
case V_159 :
clock = V_160 ;
break;
default:
F_57 ( L_11 ) ;
clock = 0 ;
}
switch ( V_1 -> V_161 ) {
case V_162 :
V_151 = V_146 ;
break;
case V_163 :
V_151 = 0 ;
break;
default:
F_57 ( L_12 ) ;
V_151 = 0 ;
}
F_5 ( V_1 ,
( V_150 & V_153 ) | ( V_141 & V_152 ) ,
V_164 ) ;
F_5 ( V_1 , V_143 , V_16 ) ;
F_18 ( V_1 , clock & V_165 , V_165 ,
V_16 ) ;
F_4 ( V_1 , V_144 , V_16 ) ;
F_4 ( V_1 , V_15 , V_16 ) ;
F_5 ( V_1 , V_144 , V_16 ) ;
F_5 ( V_1 , V_166 , V_16 ) ;
F_58 ( 3 ) ;
F_5 ( V_1 , V_167 | V_168 , V_16 ) ;
F_58 ( 1 ) ;
F_5 ( V_1 , V_169 , V_16 ) ;
F_5 ( V_1 , V_151 & V_146 , V_147 ) ;
F_6 ( V_1 , V_170 | V_171 ,
V_172 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_51 -> V_52 ) {
F_4 ( V_1 , V_169 , V_16 ) ;
F_59 ( 1 ) ;
F_4 ( V_1 , V_168 , V_16 ) ;
F_59 ( 1 ) ;
F_4 ( V_1 , V_167 , V_16 ) ;
F_59 ( 1 ) ;
F_4 ( V_1 , V_166 , V_16 ) ;
}
}
static void F_60 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_51 -> V_52 ) {
V_6 = F_2 ( V_1 , V_16 ) ;
if ( ! ( V_6 & V_166 ) )
F_5 ( V_1 , V_166 , V_16 ) ;
}
}
static void F_47 ( struct V_45 * V_23 ,
struct V_122 * V_123 , int V_173 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
int V_174 = 0 ;
if ( F_51 ( V_23 -> V_4 == 0 ) ) {
if ( V_23 -> V_120 ) {
V_23 -> V_120 = 0 ;
return;
}
}
F_61 ( & V_123 -> V_24 ) ;
if ( V_23 -> V_1 -> V_18 . V_19 == V_20 )
V_123 -> V_123 . V_173 = - V_175 ;
else
V_123 -> V_123 . V_173 = V_173 ;
if ( ! F_62 ( & V_23 -> V_24 ) )
V_174 = 1 ;
F_10 ( & V_23 -> V_1 -> V_17 ) ;
V_123 -> V_123 . V_176 ( & V_23 -> V_23 , & V_123 -> V_123 ) ;
F_11 ( & V_23 -> V_1 -> V_17 ) ;
if ( V_174 ) {
V_123 = F_63 ( V_23 -> V_24 . V_177 , struct V_122 , V_24 ) ;
if ( V_23 -> V_85 )
F_54 ( V_23 , V_123 ) ;
}
}
static void F_48 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
int V_178 ;
T_1 V_6 ;
unsigned V_179 ;
T_2 V_35 ;
void * V_180 ;
T_1 V_4 = V_23 -> V_4 ;
struct V_1 * V_1 = V_23 -> V_1 ;
F_25 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_124 , V_23 -> V_50 ) ;
V_178 = 0 ;
do {
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( V_178 ++ > 100000 ) {
F_16 ( L_13
L_14 ) ;
return;
}
F_26 ( 1 ) ;
} while ( ( V_6 & V_131 ) == 0 );
V_179 = F_24 ( V_1 , V_4 ) ;
V_180 = V_123 -> V_123 . V_180 + V_123 -> V_123 . V_181 ;
V_35 = F_64 ( V_179 , V_123 -> V_123 . V_127 - V_123 -> V_123 . V_181 ) ;
if ( V_123 -> V_123 . V_180 ) {
if ( V_35 > 0 )
F_65 ( V_1 , V_23 -> V_88 , V_180 , V_35 ) ;
if ( ( V_35 == 0 ) || ( ( V_35 % V_23 -> V_23 . V_76 ) != 0 ) )
F_5 ( V_1 , V_128 , V_23 -> V_91 ) ;
}
V_123 -> V_123 . V_181 += V_35 ;
if ( ( ! V_123 -> V_123 . V_182 && ( V_123 -> V_123 . V_181 == V_123 -> V_123 . V_127 ) )
|| ( V_35 % V_23 -> V_23 . V_76 )
|| ( V_35 == 0 ) ) {
F_43 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 ) ;
} else {
F_43 ( V_1 , V_4 ) ;
F_66 ( V_1 , V_4 ) ;
}
F_19 ( V_1 , V_4 ) ;
}
static void F_52 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
T_1 V_6 ;
unsigned V_179 ;
T_2 V_35 ;
void * V_180 ;
T_1 V_4 = V_23 -> V_4 ;
struct V_1 * V_1 = V_23 -> V_1 ;
F_25 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( F_51 ( ( V_6 & V_131 ) == 0 ) ) {
F_20 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
F_16 ( L_15 , V_4 ) ;
return;
}
V_179 = F_24 ( V_1 , V_4 ) ;
V_180 = V_123 -> V_123 . V_180 + V_123 -> V_123 . V_181 ;
V_35 = F_64 ( V_179 , V_123 -> V_123 . V_127 - V_123 -> V_123 . V_181 ) ;
if ( V_123 -> V_123 . V_180 ) {
F_65 ( V_1 , V_23 -> V_88 , V_180 , V_35 ) ;
if ( ( V_35 == 0 )
|| ( ( V_35 % V_23 -> V_23 . V_76 ) != 0 )
|| ( ( V_179 != V_23 -> V_23 . V_76 )
&& ( V_179 > V_35 ) ) )
F_5 ( V_1 , V_128 , V_23 -> V_91 ) ;
}
V_123 -> V_123 . V_181 += V_35 ;
if ( ( ! V_123 -> V_123 . V_182 && ( V_123 -> V_123 . V_181 == V_123 -> V_123 . V_127 ) )
|| ( V_35 % V_23 -> V_23 . V_76 )
|| ( V_35 == 0 ) ) {
F_43 ( V_1 , V_4 ) ;
F_66 ( V_1 , V_4 ) ;
} else {
F_50 ( V_1 , V_4 ) ;
F_39 ( V_1 , V_4 ) ;
}
}
static void F_67 ( struct V_45 * V_23 , struct V_122 * V_123 )
{
T_1 V_6 ;
int V_183 , V_179 , V_184 ;
int V_35 ;
void * V_180 ;
T_1 V_4 = V_23 -> V_4 ;
struct V_1 * V_1 = V_23 -> V_1 ;
int V_185 = 0 ;
F_25 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( F_51 ( ( V_6 & V_131 ) == 0 ) ) {
V_123 -> V_123 . V_173 = - V_186 ;
F_20 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
F_16 ( L_16 ) ;
return;
}
V_183 = V_6 & V_187 ;
V_179 = F_24 ( V_1 , V_4 ) ;
V_180 = V_123 -> V_123 . V_180 + V_123 -> V_123 . V_181 ;
V_184 = V_123 -> V_123 . V_127 - V_123 -> V_123 . V_181 ;
if ( V_183 < V_179 )
V_35 = F_64 ( V_183 , V_184 ) ;
else
V_35 = F_64 ( V_179 , V_184 ) ;
V_123 -> V_123 . V_181 += V_35 ;
if ( ( ! V_123 -> V_123 . V_182 && ( V_123 -> V_123 . V_181 == V_123 -> V_123 . V_127 ) )
|| ( V_35 % V_23 -> V_23 . V_76 )
|| ( V_35 == 0 ) ) {
F_20 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
V_185 = 1 ;
}
if ( V_123 -> V_123 . V_180 ) {
if ( V_35 == 0 )
F_6 ( V_1 , V_126 , V_23 -> V_91 ) ;
else
F_68 ( V_1 , V_23 -> V_88 , V_180 , V_35 ) ;
}
if ( ( V_23 -> V_4 != 0 ) && V_185 )
F_47 ( V_23 , V_123 , 0 ) ;
}
static void F_69 ( struct V_1 * V_1 , T_1 V_173 , T_1 V_188 )
{
T_1 V_189 ;
T_1 V_4 ;
struct V_45 * V_23 ;
struct V_122 * V_123 ;
if ( ( V_173 & V_190 ) && ( V_188 & V_190 ) ) {
F_6 ( V_1 , ~ V_190 , V_191 ) ;
F_18 ( V_1 , V_125 , V_49 ,
V_100 ) ;
V_23 = & V_1 -> V_23 [ 0 ] ;
V_123 = F_63 ( V_23 -> V_24 . V_177 , struct V_122 , V_24 ) ;
F_67 ( V_23 , V_123 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_29 ; V_4 ++ ) {
V_189 = 1 << V_4 ;
if ( ( V_173 & V_189 ) && ( V_188 & V_189 ) ) {
F_6 ( V_1 , ~ V_189 , V_191 ) ;
V_23 = V_1 -> V_46 [ V_4 ] ;
V_123 = F_63 ( V_23 -> V_24 . V_177 ,
struct V_122 , V_24 ) ;
if ( V_23 -> V_85 -> V_104 & V_134 )
F_52 ( V_23 , V_123 ) ;
else
F_67 ( V_23 , V_123 ) ;
}
}
}
}
static void F_70 ( struct V_1 * V_1 , T_1 V_173 , T_1 V_188 )
{
T_1 V_6 ;
T_1 V_189 ;
T_1 V_4 ;
struct V_45 * V_23 ;
struct V_122 * V_123 ;
if ( ( V_173 & V_129 ) && ( V_188 & V_129 ) ) {
F_6 ( V_1 , ~ V_129 , V_130 ) ;
V_23 = & V_1 -> V_23 [ 0 ] ;
V_123 = F_63 ( V_23 -> V_24 . V_177 , struct V_122 , V_24 ) ;
F_48 ( V_23 , V_123 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_29 ; V_4 ++ ) {
V_189 = 1 << V_4 ;
if ( ( V_173 & V_189 ) && ( V_188 & V_189 ) ) {
F_6 ( V_1 , ~ V_189 , V_130 ) ;
V_6 = F_22 ( V_1 , V_4 ) ;
if ( ( V_6 & V_192 ) == 0 ) {
F_50 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
F_20 ( V_1 , V_4 ) ;
V_23 = V_1 -> V_46 [ V_4 ] ;
V_123 = F_63 ( V_23 -> V_24 . V_177 ,
struct V_122 ,
V_24 ) ;
if ( ! F_62 ( & V_23 -> V_24 ) )
F_47 ( V_23 , V_123 , 0 ) ;
}
}
}
}
}
static void F_71 ( struct V_1 * V_1 , struct V_193 * V_194 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
struct V_45 * V_23 ;
T_1 V_25 ;
T_1 V_173 = 0 ;
T_1 V_195 = F_34 ( V_194 -> V_196 ) ;
switch ( V_194 -> V_197 & V_198 ) {
case V_199 :
V_173 = 1 << V_200 ;
break;
case V_201 :
V_173 = 0 ;
break;
case V_202 :
V_23 = V_1 -> V_103 [ V_195 & V_105 ] ;
V_25 = F_14 ( V_1 , V_23 -> V_4 ) ;
if ( V_25 == V_32 )
V_173 = 1 << V_203 ;
else
V_173 = 0 ;
break;
default:
F_21 ( V_1 , 0 ) ;
return;
}
V_1 -> V_204 = F_72 ( V_173 ) ;
V_1 -> V_205 -> V_180 = & V_1 -> V_204 ;
V_1 -> V_205 -> V_127 = 2 ;
F_10 ( & V_1 -> V_17 ) ;
F_73 ( V_1 -> V_18 . V_206 , V_1 -> V_205 , V_207 ) ;
F_11 ( & V_1 -> V_17 ) ;
}
static void F_74 ( struct V_1 * V_1 , struct V_193 * V_194 )
{
switch ( V_194 -> V_197 & V_198 ) {
case V_199 :
F_45 ( V_1 , 1 ) ;
break;
case V_201 :
F_45 ( V_1 , 1 ) ;
break;
case V_202 : {
struct V_45 * V_23 ;
struct V_122 * V_123 ;
T_1 V_195 = F_34 ( V_194 -> V_196 ) ;
V_23 = V_1 -> V_103 [ V_195 & V_105 ] ;
F_20 ( V_1 , V_23 -> V_4 ) ;
F_23 ( V_1 , V_23 -> V_4 ) ;
F_45 ( V_1 , 1 ) ;
V_123 = F_63 ( V_23 -> V_24 . V_177 ,
struct V_122 , V_24 ) ;
if ( V_23 -> V_106 ) {
V_23 -> V_106 = 0 ;
if ( F_62 ( & V_23 -> V_24 ) )
break;
F_54 ( V_23 , V_123 ) ;
} else if ( ! F_62 ( & V_23 -> V_24 ) )
F_19 ( V_1 , V_23 -> V_4 ) ;
}
break;
default:
F_21 ( V_1 , 0 ) ;
break;
}
}
static void F_75 ( struct V_1 * V_1 , struct V_193 * V_194 )
{
switch ( V_194 -> V_197 & V_198 ) {
case V_199 :
F_45 ( V_1 , 1 ) ;
break;
case V_201 :
F_45 ( V_1 , 1 ) ;
break;
case V_202 : {
struct V_45 * V_23 ;
T_1 V_195 = F_34 ( V_194 -> V_196 ) ;
V_23 = V_1 -> V_103 [ V_195 & V_105 ] ;
F_21 ( V_1 , V_23 -> V_4 ) ;
F_45 ( V_1 , 1 ) ;
}
break;
default:
F_21 ( V_1 , 0 ) ;
break;
}
}
static int F_76 ( struct V_1 * V_1 , struct V_193 * V_194 )
{
T_1 * V_208 = ( T_1 * ) V_194 ;
unsigned long V_26 = V_209 ;
int V_178 , V_33 = 0 ;
F_6 ( V_1 , ~ V_210 , V_136 ) ;
for ( V_178 = 0 ; V_178 < 4 ; V_178 ++ )
V_208 [ V_178 ] = F_2 ( V_1 , V_26 + V_178 * 2 ) ;
if ( ( V_194 -> V_197 & V_211 ) == V_212 ) {
switch ( V_194 -> V_213 ) {
case V_214 :
F_71 ( V_1 , V_194 ) ;
break;
case V_215 :
F_74 ( V_1 , V_194 ) ;
break;
case V_216 :
F_75 ( V_1 , V_194 ) ;
break;
default:
V_33 = 1 ;
break;
}
} else
V_33 = 1 ;
return V_33 ;
}
static void F_77 ( struct V_1 * V_1 )
{
T_1 V_19 = F_1 ( V_1 ) ;
switch ( V_19 ) {
case V_217 :
V_1 -> V_18 . V_19 = V_218 ;
break;
case V_219 :
V_1 -> V_18 . V_19 = V_220 ;
break;
default:
V_1 -> V_18 . V_19 = V_20 ;
F_16 ( L_17 ) ;
}
}
static void F_78 ( struct V_1 * V_1 )
{
T_1 V_221 ;
V_221 = F_2 ( V_1 , V_136 ) & V_222 ;
F_6 ( V_1 , ~ V_223 , V_136 ) ;
if ( V_221 == V_224 ) {
V_1 -> V_21 -> V_22 ( & V_1 -> V_18 ) ;
F_77 ( V_1 ) ;
}
if ( V_1 -> V_225 == V_226 && V_221 != V_226 )
F_77 ( V_1 ) ;
if ( ( V_221 == V_226 || V_221 == V_227 )
&& V_1 -> V_18 . V_19 == V_20 )
F_77 ( V_1 ) ;
V_1 -> V_225 = V_221 ;
}
static void F_79 ( struct V_1 * V_1 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
struct V_193 V_194 ;
T_1 V_135 ;
V_135 = F_2 ( V_1 , V_136 ) & V_137 ;
F_6 ( V_1 , ~ V_228 , V_136 ) ;
switch ( V_135 ) {
case V_229 : {
struct V_45 * V_23 ;
struct V_122 * V_123 ;
V_23 = & V_1 -> V_23 [ 0 ] ;
V_123 = F_63 ( V_23 -> V_24 . V_177 , struct V_122 , V_24 ) ;
F_47 ( V_23 , V_123 , 0 ) ;
}
break;
case V_138 :
case V_139 :
case V_140 :
if ( F_76 ( V_1 , & V_194 ) ) {
F_10 ( & V_1 -> V_17 ) ;
if ( V_1 -> V_21 -> V_230 ( & V_1 -> V_18 , & V_194 ) < 0 )
F_21 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_17 ) ;
}
break;
case V_231 :
case V_232 :
F_45 ( V_1 , 0 ) ;
break;
default:
F_16 ( L_18 , V_135 ) ;
break;
}
}
static T_3 F_80 ( int V_233 , void * V_234 )
{
struct V_1 * V_1 = V_234 ;
T_1 V_235 ;
T_1 V_236 ;
T_1 V_237 , V_238 , V_239 ;
T_1 V_240 , V_241 , V_242 ;
T_1 V_243 ;
T_1 V_244 ;
F_11 ( & V_1 -> V_17 ) ;
V_235 = F_2 ( V_1 , V_136 ) ;
V_236 = F_2 ( V_1 , V_7 ) ;
if ( V_1 -> V_51 -> V_52 && ! V_235 && ! V_236 ) {
F_60 ( V_1 ) ;
V_235 = F_2 ( V_1 , V_136 ) ;
V_236 = F_2 ( V_1 , V_7 ) ;
}
V_243 = F_2 ( V_1 , V_100 ) ;
V_244 = V_235 & V_236 ;
if ( V_244 ) {
V_237 = F_2 ( V_1 , V_191 ) ;
V_238 = F_2 ( V_1 , V_245 ) ;
V_239 = F_2 ( V_1 , V_130 ) ;
V_240 = F_2 ( V_1 , V_246 ) ;
V_241 = F_2 ( V_1 , V_247 ) ;
V_242 = F_2 ( V_1 , V_248 ) ;
if ( V_244 & V_249 ) {
F_6 ( V_1 , 0xffff & ~ V_249 ,
V_136 ) ;
F_60 ( V_1 ) ;
V_1 -> V_250 = F_2 ( V_1 , V_136 )
& V_251 ;
V_1 -> V_252 = V_253 ;
F_81 ( & V_1 -> V_254 ,
V_255 + F_82 ( 50 ) ) ;
}
if ( V_235 & V_222 )
F_78 ( V_1 ) ;
if ( ( V_235 & V_256 ) && ( V_236 & V_10 )
&& ( V_237 & V_240 ) ) {
F_69 ( V_1 , V_237 , V_240 ) ;
}
if ( ( V_235 & V_257 ) && ( V_236 & V_8 )
&& ( V_239 & V_242 ) ) {
F_70 ( V_1 , V_239 , V_242 ) ;
}
if ( V_235 & V_228 )
F_79 ( V_1 ) ;
}
F_6 ( V_1 , V_243 , V_100 ) ;
F_10 ( & V_1 -> V_17 ) ;
return V_258 ;
}
static void F_83 ( unsigned long V_234 )
{
struct V_1 * V_1 = (struct V_1 * ) V_234 ;
unsigned long V_259 ;
T_1 V_6 ;
F_84 ( & V_1 -> V_17 , V_259 ) ;
V_6 = F_2 ( V_1 , V_16 ) ;
if ( ! ( V_6 & V_167 ) ) {
F_5 ( V_1 , V_167 | V_168 , V_16 ) ;
F_59 ( 10 ) ;
F_5 ( V_1 , V_169 , V_16 ) ;
}
if ( V_1 -> V_252 > 0 ) {
V_6 = F_2 ( V_1 , V_136 ) & V_251 ;
if ( V_6 == V_1 -> V_250 ) {
V_1 -> V_252 -- ;
if ( V_1 -> V_252 == 0 ) {
if ( V_6 == V_251 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_81 ( & V_1 -> V_254 ,
V_255 + F_82 ( 50 ) ) ;
}
} else {
V_1 -> V_252 = V_253 ;
V_1 -> V_250 = V_6 ;
F_81 ( & V_1 -> V_254 ,
V_255 + F_82 ( 50 ) ) ;
}
}
F_85 ( & V_1 -> V_17 , V_259 ) ;
}
static int F_86 ( struct V_260 * V_261 ,
const struct V_84 * V_85 )
{
struct V_45 * V_23 ;
V_23 = F_87 ( V_261 , struct V_45 , V_23 ) ;
return F_36 ( V_23 , V_85 ) ;
}
static int F_88 ( struct V_260 * V_261 )
{
struct V_45 * V_23 ;
struct V_122 * V_123 ;
unsigned long V_259 ;
V_23 = F_87 ( V_261 , struct V_45 , V_23 ) ;
F_37 ( ! V_23 ) ;
while ( ! F_62 ( & V_23 -> V_24 ) ) {
V_123 = F_63 ( V_23 -> V_24 . V_177 , struct V_122 , V_24 ) ;
F_84 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
F_47 ( V_23 , V_123 , - V_262 ) ;
F_85 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
}
F_42 ( V_23 -> V_1 , V_23 -> V_4 ) ;
return F_38 ( V_23 ) ;
}
static struct V_263 * F_89 ( struct V_260 * V_261 ,
T_4 V_264 )
{
struct V_122 * V_123 ;
V_123 = F_90 ( sizeof( struct V_122 ) , V_264 ) ;
if ( ! V_123 )
return NULL ;
F_13 ( & V_123 -> V_24 ) ;
return & V_123 -> V_123 ;
}
static void F_91 ( struct V_260 * V_261 , struct V_263 * V_265 )
{
struct V_122 * V_123 ;
V_123 = F_87 ( V_265 , struct V_122 , V_123 ) ;
F_92 ( V_123 ) ;
}
static int F_73 ( struct V_260 * V_261 , struct V_263 * V_265 ,
T_4 V_264 )
{
struct V_45 * V_23 ;
struct V_122 * V_123 ;
unsigned long V_259 ;
int V_266 = 0 ;
V_23 = F_87 ( V_261 , struct V_45 , V_23 ) ;
V_123 = F_87 ( V_265 , struct V_122 , V_123 ) ;
if ( V_23 -> V_1 -> V_18 . V_19 == V_20 )
return - V_175 ;
F_84 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
if ( F_62 ( & V_23 -> V_24 ) )
V_266 = 1 ;
F_93 ( & V_123 -> V_24 , & V_23 -> V_24 ) ;
V_123 -> V_123 . V_181 = 0 ;
V_123 -> V_123 . V_173 = - V_267 ;
if ( V_23 -> V_85 == NULL )
F_55 ( V_23 , V_123 ) ;
else {
if ( V_266 && ! V_23 -> V_106 )
F_54 ( V_23 , V_123 ) ;
}
F_85 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
return 0 ;
}
static int F_94 ( struct V_260 * V_261 , struct V_263 * V_265 )
{
struct V_45 * V_23 ;
struct V_122 * V_123 ;
unsigned long V_259 ;
V_23 = F_87 ( V_261 , struct V_45 , V_23 ) ;
V_123 = F_87 ( V_265 , struct V_122 , V_123 ) ;
F_84 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
if ( ! F_62 ( & V_23 -> V_24 ) )
F_47 ( V_23 , V_123 , - V_262 ) ;
F_85 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
return 0 ;
}
static int F_95 ( struct V_260 * V_261 , int V_268 )
{
struct V_45 * V_23 ;
struct V_122 * V_123 ;
unsigned long V_259 ;
int V_33 = 0 ;
V_23 = F_87 ( V_261 , struct V_45 , V_23 ) ;
V_123 = F_63 ( V_23 -> V_24 . V_177 , struct V_122 , V_24 ) ;
F_84 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
if ( ! F_62 ( & V_23 -> V_24 ) ) {
V_33 = - V_269 ;
goto V_270;
}
if ( V_268 ) {
V_23 -> V_106 = 1 ;
F_21 ( V_23 -> V_1 , V_23 -> V_4 ) ;
} else {
V_23 -> V_106 = 0 ;
F_20 ( V_23 -> V_1 , V_23 -> V_4 ) ;
}
V_270:
F_85 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
return V_33 ;
}
static void F_96 ( struct V_260 * V_261 )
{
struct V_45 * V_23 ;
unsigned long V_259 ;
V_23 = F_87 ( V_261 , struct V_45 , V_23 ) ;
F_84 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
if ( F_62 ( & V_23 -> V_24 ) && ! V_23 -> V_106 ) {
F_20 ( V_23 -> V_1 , V_23 -> V_4 ) ;
F_4 ( V_23 -> V_1 , V_126 , V_23 -> V_91 ) ;
}
F_85 ( & V_23 -> V_1 -> V_17 , V_259 ) ;
}
int F_97 ( struct V_271 * V_21 ,
int (* F_98)( struct V_272 * ) )
{
struct V_1 * V_1 = V_273 ;
int V_274 ;
if ( ! V_21
|| V_21 -> V_19 != V_218
|| ! F_98
|| ! V_21 -> V_230 )
return - V_61 ;
if ( ! V_1 )
return - V_113 ;
if ( V_1 -> V_21 )
return - V_275 ;
V_21 -> V_21 . V_276 = NULL ;
V_1 -> V_21 = V_21 ;
V_1 -> V_18 . V_277 . V_21 = & V_21 -> V_21 ;
V_274 = F_99 ( & V_1 -> V_18 . V_277 ) ;
if ( V_274 ) {
F_16 ( L_19 , V_274 ) ;
goto error;
}
V_274 = F_98 ( & V_1 -> V_18 ) ;
if ( V_274 ) {
F_16 ( L_20 , V_274 ) ;
F_100 ( & V_1 -> V_18 . V_277 ) ;
goto error;
}
F_5 ( V_1 , V_278 | V_279 , V_7 ) ;
if ( F_2 ( V_1 , V_136 ) & V_251 ) {
F_60 ( V_1 ) ;
V_1 -> V_250 = F_2 ( V_1 ,
V_136 ) & V_251 ;
V_1 -> V_252 = V_253 ;
F_81 ( & V_1 -> V_254 , V_255 + F_82 ( 50 ) ) ;
}
return 0 ;
error:
V_1 -> V_21 = NULL ;
V_1 -> V_18 . V_277 . V_21 = NULL ;
return V_274 ;
}
int F_101 ( struct V_271 * V_21 )
{
struct V_1 * V_1 = V_273 ;
unsigned long V_259 ;
if ( V_21 != V_1 -> V_21 || ! V_21 -> V_280 )
return - V_61 ;
F_84 ( & V_1 -> V_17 , V_259 ) ;
if ( V_1 -> V_18 . V_19 != V_20 )
F_9 ( V_1 ) ;
F_85 ( & V_1 -> V_17 , V_259 ) ;
F_4 ( V_1 , V_278 | V_279 , V_7 ) ;
V_21 -> V_280 ( & V_1 -> V_18 ) ;
V_1 -> V_18 . V_277 . V_21 = NULL ;
F_56 ( V_1 ) ;
F_12 ( V_1 ) ;
F_100 ( & V_1 -> V_18 . V_277 ) ;
V_1 -> V_21 = NULL ;
return 0 ;
}
static int F_102 ( struct V_272 * V_281 )
{
struct V_1 * V_1 = F_103 ( V_281 ) ;
return F_2 ( V_1 , V_282 ) & 0x03FF ;
}
static int T_5 F_104 ( struct V_283 * V_284 )
{
struct V_1 * V_1 = F_105 ( & V_284 -> V_277 ) ;
F_106 ( & V_1 -> V_254 ) ;
F_107 ( V_1 -> V_5 ) ;
F_108 ( F_109 ( V_284 , 0 ) , V_1 ) ;
F_91 ( & V_1 -> V_23 [ 0 ] . V_23 , V_1 -> V_205 ) ;
#ifdef F_110
if ( V_1 -> V_51 -> V_52 ) {
F_111 ( V_1 -> V_285 ) ;
F_112 ( V_1 -> V_285 ) ;
}
#endif
F_92 ( V_1 ) ;
return 0 ;
}
static void F_113 ( struct V_260 * V_23 , struct V_263 * V_286 )
{
}
static int T_6 F_114 ( struct V_283 * V_284 )
{
struct V_287 * V_288 , * V_289 ;
void T_7 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
#ifdef F_110
char V_290 [ 8 ] ;
#endif
int V_33 = 0 ;
int V_178 ;
V_288 = F_115 ( V_284 , V_291 , 0 ) ;
if ( ! V_288 ) {
V_33 = - V_113 ;
F_16 ( L_21 ) ;
goto V_292;
}
V_289 = F_115 ( V_284 , V_293 , 0 ) ;
if ( ! V_289 ) {
V_33 = - V_113 ;
F_116 ( & V_284 -> V_277 ,
L_22 ) ;
goto V_292;
}
V_5 = F_117 ( V_288 -> V_294 , F_118 ( V_288 ) ) ;
if ( V_5 == NULL ) {
V_33 = - V_75 ;
F_16 ( L_23 ) ;
goto V_292;
}
if ( V_284 -> V_277 . V_295 == NULL ) {
F_116 ( & V_284 -> V_277 , L_24 ) ;
V_33 = - V_113 ;
goto V_292;
}
V_1 = F_90 ( sizeof( struct V_1 ) , V_207 ) ;
if ( V_1 == NULL ) {
V_33 = - V_75 ;
F_16 ( L_25 ) ;
goto V_292;
}
V_1 -> V_51 = V_284 -> V_277 . V_295 ;
V_1 -> V_161 = V_289 -> V_259 & V_296 ;
F_119 ( & V_1 -> V_17 ) ;
F_120 ( & V_284 -> V_277 , V_1 ) ;
V_1 -> V_18 . V_297 = & V_298 ;
F_121 ( & V_1 -> V_18 . V_277 ) ;
F_122 ( & V_1 -> V_18 . V_277 , L_26 ) ;
V_1 -> V_18 . V_299 = 1 ;
V_1 -> V_18 . V_277 . V_300 = & V_284 -> V_277 ;
V_1 -> V_18 . V_277 . V_301 = V_284 -> V_277 . V_301 ;
V_1 -> V_18 . V_277 . V_302 = V_284 -> V_277 . V_302 ;
V_1 -> V_18 . V_303 = V_304 ;
F_123 ( & V_1 -> V_254 ) ;
V_1 -> V_254 . V_305 = F_83 ;
V_1 -> V_254 . V_306 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
V_33 = F_124 ( V_289 -> V_294 , F_80 , V_307 | V_308 ,
V_304 , V_1 ) ;
if ( V_33 < 0 ) {
F_16 ( L_27 , V_33 ) ;
goto V_292;
}
#ifdef F_110
if ( V_1 -> V_51 -> V_52 ) {
snprintf ( V_290 , sizeof( V_290 ) , L_28 , V_284 -> V_309 ) ;
V_1 -> V_285 = F_125 ( & V_284 -> V_277 , V_290 ) ;
if ( F_126 ( V_1 -> V_285 ) ) {
F_116 ( & V_284 -> V_277 , L_29 ,
V_290 ) ;
V_33 = F_127 ( V_1 -> V_285 ) ;
goto V_310;
}
F_128 ( V_1 -> V_285 ) ;
}
#endif
F_13 ( & V_1 -> V_18 . V_311 ) ;
V_1 -> V_18 . V_206 = & V_1 -> V_23 [ 0 ] . V_23 ;
F_13 ( & V_1 -> V_18 . V_206 -> V_311 ) ;
for ( V_178 = 0 ; V_178 < V_29 ; V_178 ++ ) {
struct V_45 * V_23 = & V_1 -> V_23 [ V_178 ] ;
if ( V_178 != 0 ) {
F_13 ( & V_1 -> V_23 [ V_178 ] . V_23 . V_311 ) ;
F_93 ( & V_1 -> V_23 [ V_178 ] . V_23 . V_311 ,
& V_1 -> V_18 . V_311 ) ;
}
V_23 -> V_1 = V_1 ;
F_13 ( & V_23 -> V_24 ) ;
V_23 -> V_23 . V_303 = V_312 [ V_178 ] ;
V_23 -> V_23 . V_297 = & V_313 ;
V_23 -> V_23 . V_76 = 512 ;
}
V_1 -> V_23 [ 0 ] . V_23 . V_76 = 64 ;
V_1 -> V_23 [ 0 ] . V_4 = 0 ;
V_1 -> V_23 [ 0 ] . V_88 = V_99 ;
V_1 -> V_23 [ 0 ] . V_50 = V_100 ;
V_1 -> V_23 [ 0 ] . V_91 = V_101 ;
V_1 -> V_23 [ 0 ] . V_93 = 0 ;
V_1 -> V_23 [ 0 ] . V_83 = F_15 ( 0 ) ;
V_1 -> V_46 [ 0 ] = & V_1 -> V_23 [ 0 ] ;
V_1 -> V_103 [ 0 ] = & V_1 -> V_23 [ 0 ] ;
V_273 = V_1 ;
V_1 -> V_205 = F_89 ( & V_1 -> V_23 [ 0 ] . V_23 , V_207 ) ;
if ( V_1 -> V_205 == NULL )
goto V_314;
V_1 -> V_205 -> V_176 = F_113 ;
F_56 ( V_1 ) ;
F_129 ( & V_284 -> V_277 , L_30 , V_315 ) ;
return 0 ;
V_314:
#ifdef F_110
if ( V_1 -> V_51 -> V_52 ) {
F_111 ( V_1 -> V_285 ) ;
F_112 ( V_1 -> V_285 ) ;
}
V_310:
#endif
F_108 ( V_289 -> V_294 , V_1 ) ;
V_292:
if ( V_1 ) {
if ( V_1 -> V_205 )
F_91 ( & V_1 -> V_23 [ 0 ] . V_23 , V_1 -> V_205 ) ;
F_92 ( V_1 ) ;
}
if ( V_5 )
F_107 ( V_5 ) ;
return V_33 ;
}
static int T_6 F_130 ( void )
{
return F_131 ( & V_316 , F_114 ) ;
}
static void T_5 F_132 ( void )
{
F_133 ( & V_316 ) ;
}
