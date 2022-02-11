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
V_23 -> V_23 . V_76 = F_34 ( V_85 ) ;
V_1 -> V_46 [ V_4 ] = V_23 ;
V_1 -> V_102 [ V_85 -> V_103 & V_104 ] = V_23 ;
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
V_23 -> V_105 = 0 ;
V_23 -> V_48 = 0 ;
}
static int F_36 ( struct V_45 * V_23 ,
const struct V_84 * V_85 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
struct V_55 V_56 ;
int V_86 = 0 ;
int * V_106 ;
int V_33 ;
V_23 -> V_23 . V_85 = V_85 ;
F_37 ( V_23 -> V_4 ) ;
switch ( V_85 -> V_107 & V_108 ) {
case V_109 :
if ( V_1 -> V_79 >= V_110 ) {
if ( V_1 -> V_81 >= V_111 ) {
F_16 ( L_5 ) ;
return - V_112 ;
} else {
V_56 . V_60 = V_69
+ V_1 -> V_81 ;
V_106 = & V_1 -> V_81 ;
}
} else {
V_56 . V_60 = V_68 + V_1 -> V_79 ;
V_106 = & V_1 -> V_79 ;
}
V_56 . type = V_67 ;
V_86 = 1 ;
break;
case V_113 :
if ( V_1 -> V_80 >= V_114 ) {
F_16 ( L_6 ) ;
return - V_112 ;
}
V_56 . V_60 = V_66 + V_1 -> V_80 ;
V_56 . type = V_65 ;
V_106 = & V_1 -> V_80 ;
break;
case V_115 :
if ( V_1 -> V_81 >= V_111 ) {
F_16 ( L_7 ) ;
return - V_112 ;
}
V_56 . V_60 = V_69 + V_1 -> V_81 ;
V_56 . type = V_73 ;
V_106 = & V_1 -> V_81 ;
break;
default:
F_16 ( L_8 ) ;
return - V_61 ;
}
V_23 -> type = V_56 . type ;
V_56 . V_64 = V_85 -> V_103 & V_104 ;
V_56 . V_76 = F_34 ( V_85 ) ;
V_56 . V_77 = V_85 -> V_116 ;
if ( V_85 -> V_103 & V_117 )
V_56 . V_62 = 1 ;
else
V_56 . V_62 = 0 ;
V_33 = F_27 ( V_1 , & V_56 ) ;
if ( V_33 < 0 ) {
F_16 ( L_9 ) ;
return V_33 ;
}
( * V_106 ) ++ ;
if ( ( V_106 == & V_1 -> V_81 ) && V_56 . type == V_67 )
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
static void F_45 ( struct V_1 * V_1 , unsigned V_118 )
{
V_1 -> V_23 [ 0 ] . V_119 = V_118 ;
F_19 ( V_1 , 0 ) ;
F_5 ( V_1 , V_120 , V_27 ) ;
}
static void F_46 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
F_25 ( V_1 , V_23 -> V_4 ) ;
F_18 ( V_1 , V_123 | V_124 ,
( V_123 | V_49 ) ,
V_100 ) ;
F_6 ( V_1 , V_125 , V_23 -> V_91 ) ;
if ( V_122 -> V_122 . V_126 == 0 ) {
F_5 ( V_1 , V_127 , V_23 -> V_91 ) ;
F_19 ( V_1 , 0 ) ;
F_47 ( V_23 , V_122 , 0 ) ;
} else {
F_6 ( V_1 , ~ V_128 , V_129 ) ;
F_48 ( V_23 , V_122 ) ;
}
}
static void F_49 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
T_1 V_6 ;
F_25 ( V_1 , V_23 -> V_4 ) ;
F_50 ( V_1 , V_23 -> V_4 ) ;
F_19 ( V_1 , V_23 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( F_51 ( ( V_6 & V_130 ) == 0 ) )
F_39 ( V_1 , V_23 -> V_4 ) ;
else
F_52 ( V_23 , V_122 ) ;
}
static void F_53 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
struct V_1 * V_1 = V_23 -> V_1 ;
T_1 V_4 = V_23 -> V_4 ;
if ( V_23 -> V_4 == 0 ) {
F_18 ( V_1 , V_124 ,
( V_123 | V_49 ) ,
V_100 ) ;
F_6 ( V_1 , V_125 , V_23 -> V_91 ) ;
F_19 ( V_1 , V_4 ) ;
F_39 ( V_1 , V_4 ) ;
} else {
if ( V_23 -> V_48 ) {
F_5 ( V_1 , V_131 , V_23 -> V_50 ) ;
F_25 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_132 , V_23 -> V_50 ) ;
F_6 ( V_1 ,
( V_122 -> V_122 . V_126 + V_23 -> V_23 . V_76 - 1 )
/ V_23 -> V_23 . V_76 ,
V_23 -> V_93 ) ;
}
F_19 ( V_1 , V_4 ) ;
F_39 ( V_1 , V_4 ) ;
}
}
static void F_54 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
if ( V_23 -> V_23 . V_85 -> V_103 & V_133 )
F_49 ( V_23 , V_122 ) ;
else
F_53 ( V_23 , V_122 ) ;
}
static void F_55 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
T_1 V_134 ;
V_134 = F_2 ( V_23 -> V_1 , V_135 ) & V_136 ;
switch ( V_134 ) {
case V_137 :
F_46 ( V_23 , V_122 ) ;
break;
case V_138 :
F_53 ( V_23 , V_122 ) ;
break;
case V_139 :
F_45 ( V_23 -> V_1 , 0 ) ;
break;
default:
F_16 ( L_10 , V_134 ) ;
break;
}
}
static void F_56 ( struct V_1 * V_1 )
{
unsigned int V_140 ;
if ( V_1 -> V_51 -> V_52 ) {
if ( V_1 -> V_51 -> V_140 )
V_140 = 0 ;
else
V_140 = V_141 ;
F_5 ( V_1 , V_142 , V_16 ) ;
F_4 ( V_1 , V_143 , V_16 ) ;
F_4 ( V_1 , V_15 , V_16 ) ;
F_5 ( V_1 , V_143 , V_16 ) ;
F_5 ( V_1 , 0x8000 , V_2 ) ;
F_5 ( V_1 , 0x1000 , V_144 ) ;
F_4 ( V_1 , 0x8000 , V_2 ) ;
F_5 ( V_1 , V_145 , V_146 ) ;
F_6 ( V_1 , 0 , V_147 ) ;
F_6 ( V_1 , 0 , V_148 ) ;
F_5 ( V_1 , V_140 , V_147 ) ;
F_5 ( V_1 , V_140 , V_148 ) ;
} else {
unsigned int clock , V_149 , V_150 ;
if ( V_1 -> V_51 -> V_140 )
V_140 = V_151 ;
else
V_140 = 0 ;
if ( V_1 -> V_51 -> V_149 )
V_149 = V_152 ;
else
V_149 = 0 ;
switch ( V_1 -> V_51 -> V_153 ) {
case V_154 :
clock = V_155 ;
break;
case V_156 :
clock = V_157 ;
break;
case V_158 :
clock = V_159 ;
break;
default:
F_57 ( L_11 ) ;
clock = 0 ;
}
switch ( V_1 -> V_160 ) {
case V_161 :
V_150 = V_145 ;
break;
case V_162 :
V_150 = 0 ;
break;
default:
F_57 ( L_12 ) ;
V_150 = 0 ;
}
F_5 ( V_1 ,
( V_149 & V_152 ) | ( V_140 & V_151 ) ,
V_163 ) ;
F_5 ( V_1 , V_142 , V_16 ) ;
F_18 ( V_1 , clock & V_164 , V_164 ,
V_16 ) ;
F_4 ( V_1 , V_143 , V_16 ) ;
F_4 ( V_1 , V_15 , V_16 ) ;
F_5 ( V_1 , V_143 , V_16 ) ;
F_5 ( V_1 , V_165 , V_16 ) ;
F_58 ( 3 ) ;
F_5 ( V_1 , V_166 | V_167 , V_16 ) ;
F_58 ( 1 ) ;
F_5 ( V_1 , V_168 , V_16 ) ;
F_5 ( V_1 , V_150 & V_145 , V_146 ) ;
F_6 ( V_1 , V_169 | V_170 ,
V_171 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
F_4 ( V_1 , V_172 , V_144 ) ;
if ( ! V_1 -> V_51 -> V_52 ) {
F_4 ( V_1 , V_168 , V_16 ) ;
F_59 ( 1 ) ;
F_4 ( V_1 , V_167 , V_16 ) ;
F_59 ( 1 ) ;
F_4 ( V_1 , V_166 , V_16 ) ;
F_59 ( 1 ) ;
F_4 ( V_1 , V_165 , V_16 ) ;
}
}
static void F_60 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_51 -> V_52 ) {
V_6 = F_2 ( V_1 , V_16 ) ;
if ( ! ( V_6 & V_165 ) )
F_5 ( V_1 , V_165 , V_16 ) ;
}
}
static void F_47 ( struct V_45 * V_23 ,
struct V_121 * V_122 , int V_173 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
int V_174 = 0 ;
if ( F_51 ( V_23 -> V_4 == 0 ) ) {
if ( V_23 -> V_119 ) {
V_23 -> V_119 = 0 ;
return;
}
}
F_61 ( & V_122 -> V_24 ) ;
if ( V_23 -> V_1 -> V_18 . V_19 == V_20 )
V_122 -> V_122 . V_173 = - V_175 ;
else
V_122 -> V_122 . V_173 = V_173 ;
if ( ! F_62 ( & V_23 -> V_24 ) )
V_174 = 1 ;
F_10 ( & V_23 -> V_1 -> V_17 ) ;
F_63 ( & V_23 -> V_23 , & V_122 -> V_122 ) ;
F_11 ( & V_23 -> V_1 -> V_17 ) ;
if ( V_174 ) {
V_122 = F_64 ( V_23 -> V_24 . V_176 , struct V_121 , V_24 ) ;
if ( V_23 -> V_23 . V_85 )
F_54 ( V_23 , V_122 ) ;
}
}
static void F_48 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
int V_177 ;
T_1 V_6 ;
unsigned V_178 ;
T_2 V_35 ;
void * V_179 ;
T_1 V_4 = V_23 -> V_4 ;
struct V_1 * V_1 = V_23 -> V_1 ;
F_25 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_123 , V_23 -> V_50 ) ;
V_177 = 0 ;
do {
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( V_177 ++ > 100000 ) {
F_16 ( L_13
L_14 ) ;
return;
}
F_26 ( 1 ) ;
} while ( ( V_6 & V_130 ) == 0 );
V_178 = F_24 ( V_1 , V_4 ) ;
V_179 = V_122 -> V_122 . V_179 + V_122 -> V_122 . V_180 ;
V_35 = F_65 ( V_178 , V_122 -> V_122 . V_126 - V_122 -> V_122 . V_180 ) ;
if ( V_122 -> V_122 . V_179 ) {
if ( V_35 > 0 )
F_66 ( V_1 , V_23 , V_179 , V_35 ) ;
if ( ( V_35 == 0 ) || ( ( V_35 % V_23 -> V_23 . V_76 ) != 0 ) )
F_5 ( V_1 , V_127 , V_23 -> V_91 ) ;
}
V_122 -> V_122 . V_180 += V_35 ;
if ( ( ! V_122 -> V_122 . V_181 && ( V_122 -> V_122 . V_180 == V_122 -> V_122 . V_126 ) )
|| ( V_35 % V_23 -> V_23 . V_76 )
|| ( V_35 == 0 ) ) {
F_43 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 ) ;
} else {
F_43 ( V_1 , V_4 ) ;
F_67 ( V_1 , V_4 ) ;
}
F_19 ( V_1 , V_4 ) ;
}
static void F_52 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
T_1 V_6 ;
unsigned V_178 ;
T_2 V_35 ;
void * V_179 ;
T_1 V_4 = V_23 -> V_4 ;
struct V_1 * V_1 = V_23 -> V_1 ;
F_25 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( F_51 ( ( V_6 & V_130 ) == 0 ) ) {
F_20 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
F_16 ( L_15 , V_4 ) ;
return;
}
V_178 = F_24 ( V_1 , V_4 ) ;
V_179 = V_122 -> V_122 . V_179 + V_122 -> V_122 . V_180 ;
V_35 = F_65 ( V_178 , V_122 -> V_122 . V_126 - V_122 -> V_122 . V_180 ) ;
if ( V_122 -> V_122 . V_179 ) {
F_66 ( V_1 , V_23 , V_179 , V_35 ) ;
if ( ( V_35 == 0 )
|| ( ( V_35 % V_23 -> V_23 . V_76 ) != 0 )
|| ( ( V_178 != V_23 -> V_23 . V_76 )
&& ( V_178 > V_35 ) ) )
F_5 ( V_1 , V_127 , V_23 -> V_91 ) ;
}
V_122 -> V_122 . V_180 += V_35 ;
if ( ( ! V_122 -> V_122 . V_181 && ( V_122 -> V_122 . V_180 == V_122 -> V_122 . V_126 ) )
|| ( V_35 % V_23 -> V_23 . V_76 )
|| ( V_35 == 0 ) ) {
F_43 ( V_1 , V_4 ) ;
F_67 ( V_1 , V_4 ) ;
} else {
F_50 ( V_1 , V_4 ) ;
F_39 ( V_1 , V_4 ) ;
}
}
static void F_68 ( struct V_45 * V_23 , struct V_121 * V_122 )
{
T_1 V_6 ;
int V_182 , V_178 , V_183 ;
int V_35 ;
void * V_179 ;
T_1 V_4 = V_23 -> V_4 ;
struct V_1 * V_1 = V_23 -> V_1 ;
int V_184 = 0 ;
F_25 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_23 -> V_91 ) ;
if ( F_51 ( ( V_6 & V_130 ) == 0 ) ) {
V_122 -> V_122 . V_173 = - V_185 ;
F_20 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
F_16 ( L_16 ) ;
return;
}
V_182 = V_6 & V_186 ;
V_178 = F_24 ( V_1 , V_4 ) ;
V_179 = V_122 -> V_122 . V_179 + V_122 -> V_122 . V_180 ;
V_183 = V_122 -> V_122 . V_126 - V_122 -> V_122 . V_180 ;
if ( V_182 < V_178 )
V_35 = F_65 ( V_182 , V_183 ) ;
else
V_35 = F_65 ( V_178 , V_183 ) ;
V_122 -> V_122 . V_180 += V_35 ;
if ( ( ! V_122 -> V_122 . V_181 && ( V_122 -> V_122 . V_180 == V_122 -> V_122 . V_126 ) )
|| ( V_35 % V_23 -> V_23 . V_76 )
|| ( V_35 == 0 ) ) {
F_20 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
V_184 = 1 ;
}
if ( V_122 -> V_122 . V_179 ) {
if ( V_35 == 0 )
F_6 ( V_1 , V_125 , V_23 -> V_91 ) ;
else
F_69 ( V_1 , V_23 -> V_88 , V_179 , V_35 ) ;
}
if ( ( V_23 -> V_4 != 0 ) && V_184 )
F_47 ( V_23 , V_122 , 0 ) ;
}
static void F_70 ( struct V_1 * V_1 , T_1 V_173 , T_1 V_187 )
{
T_1 V_188 ;
T_1 V_4 ;
struct V_45 * V_23 ;
struct V_121 * V_122 ;
if ( ( V_173 & V_189 ) && ( V_187 & V_189 ) ) {
F_6 ( V_1 , ~ V_189 , V_190 ) ;
F_18 ( V_1 , V_124 , V_49 ,
V_100 ) ;
V_23 = & V_1 -> V_23 [ 0 ] ;
V_122 = F_64 ( V_23 -> V_24 . V_176 , struct V_121 , V_24 ) ;
F_68 ( V_23 , V_122 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_29 ; V_4 ++ ) {
V_188 = 1 << V_4 ;
if ( ( V_173 & V_188 ) && ( V_187 & V_188 ) ) {
F_6 ( V_1 , ~ V_188 , V_190 ) ;
V_23 = V_1 -> V_46 [ V_4 ] ;
V_122 = F_64 ( V_23 -> V_24 . V_176 ,
struct V_121 , V_24 ) ;
if ( V_23 -> V_23 . V_85 -> V_103 & V_133 )
F_52 ( V_23 , V_122 ) ;
else
F_68 ( V_23 , V_122 ) ;
}
}
}
}
static void F_71 ( struct V_1 * V_1 , T_1 V_173 , T_1 V_187 )
{
T_1 V_6 ;
T_1 V_188 ;
T_1 V_4 ;
struct V_45 * V_23 ;
struct V_121 * V_122 ;
if ( ( V_173 & V_128 ) && ( V_187 & V_128 ) ) {
F_6 ( V_1 , ~ V_128 , V_129 ) ;
V_23 = & V_1 -> V_23 [ 0 ] ;
V_122 = F_64 ( V_23 -> V_24 . V_176 , struct V_121 , V_24 ) ;
F_48 ( V_23 , V_122 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_29 ; V_4 ++ ) {
V_188 = 1 << V_4 ;
if ( ( V_173 & V_188 ) && ( V_187 & V_188 ) ) {
F_6 ( V_1 , ~ V_188 , V_129 ) ;
V_6 = F_22 ( V_1 , V_4 ) ;
if ( ( V_6 & V_191 ) == 0 ) {
F_50 ( V_1 , V_4 ) ;
F_42 ( V_1 , V_4 ) ;
F_20 ( V_1 , V_4 ) ;
V_23 = V_1 -> V_46 [ V_4 ] ;
V_122 = F_64 ( V_23 -> V_24 . V_176 ,
struct V_121 ,
V_24 ) ;
if ( ! F_62 ( & V_23 -> V_24 ) )
F_47 ( V_23 , V_122 , 0 ) ;
}
}
}
}
}
static void F_72 ( struct V_1 * V_1 , struct V_192 * V_193 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
struct V_45 * V_23 ;
T_1 V_25 ;
T_1 V_173 = 0 ;
T_1 V_194 = F_73 ( V_193 -> V_195 ) ;
switch ( V_193 -> V_196 & V_197 ) {
case V_198 :
V_173 = 1 << V_199 ;
break;
case V_200 :
V_173 = 0 ;
break;
case V_201 :
V_23 = V_1 -> V_102 [ V_194 & V_104 ] ;
V_25 = F_14 ( V_1 , V_23 -> V_4 ) ;
if ( V_25 == V_32 )
V_173 = 1 << V_202 ;
else
V_173 = 0 ;
break;
default:
F_21 ( V_1 , 0 ) ;
return;
}
V_1 -> V_203 = F_74 ( V_173 ) ;
V_1 -> V_204 -> V_179 = & V_1 -> V_203 ;
V_1 -> V_204 -> V_126 = 2 ;
F_10 ( & V_1 -> V_17 ) ;
F_75 ( V_1 -> V_18 . V_205 , V_1 -> V_204 , V_206 ) ;
F_11 ( & V_1 -> V_17 ) ;
}
static void F_76 ( struct V_1 * V_1 , struct V_192 * V_193 )
{
switch ( V_193 -> V_196 & V_197 ) {
case V_198 :
F_45 ( V_1 , 1 ) ;
break;
case V_200 :
F_45 ( V_1 , 1 ) ;
break;
case V_201 : {
struct V_45 * V_23 ;
struct V_121 * V_122 ;
T_1 V_194 = F_73 ( V_193 -> V_195 ) ;
V_23 = V_1 -> V_102 [ V_194 & V_104 ] ;
F_20 ( V_1 , V_23 -> V_4 ) ;
F_23 ( V_1 , V_23 -> V_4 ) ;
F_45 ( V_1 , 1 ) ;
V_122 = F_64 ( V_23 -> V_24 . V_176 ,
struct V_121 , V_24 ) ;
if ( V_23 -> V_105 ) {
V_23 -> V_105 = 0 ;
if ( F_62 ( & V_23 -> V_24 ) )
break;
F_54 ( V_23 , V_122 ) ;
} else if ( ! F_62 ( & V_23 -> V_24 ) )
F_19 ( V_1 , V_23 -> V_4 ) ;
}
break;
default:
F_21 ( V_1 , 0 ) ;
break;
}
}
static void F_77 ( struct V_1 * V_1 , struct V_192 * V_193 )
{
T_1 V_6 ;
int V_207 = 3000 ;
switch ( V_193 -> V_196 & V_197 ) {
case V_198 :
switch ( F_73 ( V_193 -> V_208 ) ) {
case V_209 :
F_45 ( V_1 , 1 ) ;
do {
V_6 = F_2 ( V_1 , V_135 ) &
V_136 ;
F_59 ( 1 ) ;
} while ( V_6 != V_210 && V_207 -- > 0 );
if ( V_6 == V_210 )
F_5 ( V_1 ,
F_73 ( V_193 -> V_195 >> 8 ) ,
V_144 ) ;
break;
default:
F_21 ( V_1 , 0 ) ;
break;
}
break;
case V_200 :
F_45 ( V_1 , 1 ) ;
break;
case V_201 : {
struct V_45 * V_23 ;
T_1 V_194 = F_73 ( V_193 -> V_195 ) ;
V_23 = V_1 -> V_102 [ V_194 & V_104 ] ;
F_21 ( V_1 , V_23 -> V_4 ) ;
F_45 ( V_1 , 1 ) ;
}
break;
default:
F_21 ( V_1 , 0 ) ;
break;
}
}
static int F_78 ( struct V_1 * V_1 , struct V_192 * V_193 )
{
T_1 * V_211 = ( T_1 * ) V_193 ;
unsigned long V_26 = V_212 ;
int V_177 , V_33 = 0 ;
F_6 ( V_1 , ~ V_213 , V_135 ) ;
for ( V_177 = 0 ; V_177 < 4 ; V_177 ++ )
V_211 [ V_177 ] = F_2 ( V_1 , V_26 + V_177 * 2 ) ;
if ( ( V_193 -> V_196 & V_214 ) == V_215 ) {
switch ( V_193 -> V_216 ) {
case V_217 :
F_72 ( V_1 , V_193 ) ;
break;
case V_218 :
F_76 ( V_1 , V_193 ) ;
break;
case V_219 :
F_77 ( V_1 , V_193 ) ;
break;
default:
V_33 = 1 ;
break;
}
} else
V_33 = 1 ;
return V_33 ;
}
static void F_79 ( struct V_1 * V_1 )
{
T_1 V_19 = F_1 ( V_1 ) ;
switch ( V_19 ) {
case V_220 :
V_1 -> V_18 . V_19 = V_221 ;
break;
case V_222 :
V_1 -> V_18 . V_19 = V_223 ;
break;
default:
V_1 -> V_18 . V_19 = V_20 ;
F_16 ( L_17 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
T_1 V_224 ;
V_224 = F_2 ( V_1 , V_135 ) & V_225 ;
F_6 ( V_1 , ~ V_226 , V_135 ) ;
if ( V_224 == V_227 ) {
F_81 ( & V_1 -> V_18 , V_1 -> V_21 ) ;
F_79 ( V_1 ) ;
}
if ( V_1 -> V_228 == V_229 && V_224 != V_229 )
F_79 ( V_1 ) ;
if ( ( V_224 == V_229 || V_224 == V_230 )
&& V_1 -> V_18 . V_19 == V_20 )
F_79 ( V_1 ) ;
V_1 -> V_228 = V_224 ;
}
static void F_82 ( struct V_1 * V_1 )
__releases( V_1 -> V_17 )
__acquires( V_1 -> V_17 )
{
struct V_192 V_193 ;
T_1 V_134 ;
V_134 = F_2 ( V_1 , V_135 ) & V_136 ;
F_6 ( V_1 , ~ V_231 , V_135 ) ;
switch ( V_134 ) {
case V_210 : {
struct V_45 * V_23 ;
struct V_121 * V_122 ;
V_23 = & V_1 -> V_23 [ 0 ] ;
V_122 = F_64 ( V_23 -> V_24 . V_176 , struct V_121 , V_24 ) ;
F_47 ( V_23 , V_122 , 0 ) ;
}
break;
case V_137 :
case V_138 :
case V_139 :
if ( F_78 ( V_1 , & V_193 ) ) {
F_10 ( & V_1 -> V_17 ) ;
if ( V_1 -> V_21 -> V_232 ( & V_1 -> V_18 , & V_193 ) < 0 )
F_21 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_17 ) ;
}
break;
case V_233 :
case V_234 :
F_45 ( V_1 , 0 ) ;
break;
default:
F_16 ( L_18 , V_134 ) ;
break;
}
}
static T_3 F_83 ( int V_235 , void * V_236 )
{
struct V_1 * V_1 = V_236 ;
T_1 V_237 ;
T_1 V_238 ;
T_1 V_239 , V_240 , V_241 ;
T_1 V_242 , V_243 , V_244 ;
T_1 V_245 ;
T_1 V_246 ;
F_11 ( & V_1 -> V_17 ) ;
V_237 = F_2 ( V_1 , V_135 ) ;
V_238 = F_2 ( V_1 , V_7 ) ;
if ( V_1 -> V_51 -> V_52 && ! V_237 && ! V_238 ) {
F_60 ( V_1 ) ;
V_237 = F_2 ( V_1 , V_135 ) ;
V_238 = F_2 ( V_1 , V_7 ) ;
}
V_245 = F_2 ( V_1 , V_100 ) ;
V_246 = V_237 & V_238 ;
if ( V_246 ) {
V_239 = F_2 ( V_1 , V_190 ) ;
V_240 = F_2 ( V_1 , V_247 ) ;
V_241 = F_2 ( V_1 , V_129 ) ;
V_242 = F_2 ( V_1 , V_248 ) ;
V_243 = F_2 ( V_1 , V_249 ) ;
V_244 = F_2 ( V_1 , V_250 ) ;
if ( V_246 & V_251 ) {
F_6 ( V_1 , 0xffff & ~ V_251 ,
V_135 ) ;
F_60 ( V_1 ) ;
V_1 -> V_252 = F_2 ( V_1 , V_135 )
& V_253 ;
V_1 -> V_254 = V_255 ;
F_84 ( & V_1 -> V_256 ,
V_257 + F_85 ( 50 ) ) ;
}
if ( V_237 & V_225 )
F_80 ( V_1 ) ;
if ( ( V_237 & V_258 ) && ( V_238 & V_10 )
&& ( V_239 & V_242 ) ) {
F_70 ( V_1 , V_239 , V_242 ) ;
}
if ( ( V_237 & V_259 ) && ( V_238 & V_8 )
&& ( V_241 & V_244 ) ) {
F_71 ( V_1 , V_241 , V_244 ) ;
}
if ( V_237 & V_231 )
F_82 ( V_1 ) ;
}
F_6 ( V_1 , V_245 , V_100 ) ;
F_10 ( & V_1 -> V_17 ) ;
return V_260 ;
}
static void F_86 ( unsigned long V_236 )
{
struct V_1 * V_1 = (struct V_1 * ) V_236 ;
unsigned long V_261 ;
T_1 V_6 ;
F_87 ( & V_1 -> V_17 , V_261 ) ;
V_6 = F_2 ( V_1 , V_16 ) ;
if ( ! ( V_6 & V_166 ) ) {
F_5 ( V_1 , V_166 | V_167 , V_16 ) ;
F_59 ( 10 ) ;
F_5 ( V_1 , V_168 , V_16 ) ;
}
if ( V_1 -> V_254 > 0 ) {
V_6 = F_2 ( V_1 , V_135 ) & V_253 ;
if ( V_6 == V_1 -> V_252 ) {
V_1 -> V_254 -- ;
if ( V_1 -> V_254 == 0 ) {
if ( V_6 == V_253 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_84 ( & V_1 -> V_256 ,
V_257 + F_85 ( 50 ) ) ;
}
} else {
V_1 -> V_254 = V_255 ;
V_1 -> V_252 = V_6 ;
F_84 ( & V_1 -> V_256 ,
V_257 + F_85 ( 50 ) ) ;
}
}
F_88 ( & V_1 -> V_17 , V_261 ) ;
}
static int F_89 ( struct V_262 * V_263 ,
const struct V_84 * V_85 )
{
struct V_45 * V_23 ;
V_23 = F_90 ( V_263 , struct V_45 , V_23 ) ;
return F_36 ( V_23 , V_85 ) ;
}
static int F_91 ( struct V_262 * V_263 )
{
struct V_45 * V_23 ;
struct V_121 * V_122 ;
unsigned long V_261 ;
V_23 = F_90 ( V_263 , struct V_45 , V_23 ) ;
F_37 ( ! V_23 ) ;
while ( ! F_62 ( & V_23 -> V_24 ) ) {
V_122 = F_64 ( V_23 -> V_24 . V_176 , struct V_121 , V_24 ) ;
F_87 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
F_47 ( V_23 , V_122 , - V_264 ) ;
F_88 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
}
F_42 ( V_23 -> V_1 , V_23 -> V_4 ) ;
return F_38 ( V_23 ) ;
}
static struct V_265 * F_92 ( struct V_262 * V_263 ,
T_4 V_266 )
{
struct V_121 * V_122 ;
V_122 = F_93 ( sizeof( struct V_121 ) , V_266 ) ;
if ( ! V_122 )
return NULL ;
F_13 ( & V_122 -> V_24 ) ;
return & V_122 -> V_122 ;
}
static void F_94 ( struct V_262 * V_263 , struct V_265 * V_267 )
{
struct V_121 * V_122 ;
V_122 = F_90 ( V_267 , struct V_121 , V_122 ) ;
F_95 ( V_122 ) ;
}
static int F_75 ( struct V_262 * V_263 , struct V_265 * V_267 ,
T_4 V_266 )
{
struct V_45 * V_23 ;
struct V_121 * V_122 ;
unsigned long V_261 ;
int V_268 = 0 ;
V_23 = F_90 ( V_263 , struct V_45 , V_23 ) ;
V_122 = F_90 ( V_267 , struct V_121 , V_122 ) ;
if ( V_23 -> V_1 -> V_18 . V_19 == V_20 )
return - V_175 ;
F_87 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
if ( F_62 ( & V_23 -> V_24 ) )
V_268 = 1 ;
F_96 ( & V_122 -> V_24 , & V_23 -> V_24 ) ;
V_122 -> V_122 . V_180 = 0 ;
V_122 -> V_122 . V_173 = - V_269 ;
if ( V_23 -> V_23 . V_85 == NULL )
F_55 ( V_23 , V_122 ) ;
else {
if ( V_268 && ! V_23 -> V_105 )
F_54 ( V_23 , V_122 ) ;
}
F_88 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
return 0 ;
}
static int F_97 ( struct V_262 * V_263 , struct V_265 * V_267 )
{
struct V_45 * V_23 ;
struct V_121 * V_122 ;
unsigned long V_261 ;
V_23 = F_90 ( V_263 , struct V_45 , V_23 ) ;
V_122 = F_90 ( V_267 , struct V_121 , V_122 ) ;
F_87 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
if ( ! F_62 ( & V_23 -> V_24 ) )
F_47 ( V_23 , V_122 , - V_264 ) ;
F_88 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
return 0 ;
}
static int F_98 ( struct V_262 * V_263 , int V_270 )
{
struct V_45 * V_23 ;
struct V_121 * V_122 ;
unsigned long V_261 ;
int V_33 = 0 ;
V_23 = F_90 ( V_263 , struct V_45 , V_23 ) ;
V_122 = F_64 ( V_23 -> V_24 . V_176 , struct V_121 , V_24 ) ;
F_87 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
if ( ! F_62 ( & V_23 -> V_24 ) ) {
V_33 = - V_271 ;
goto V_272;
}
if ( V_270 ) {
V_23 -> V_105 = 1 ;
F_21 ( V_23 -> V_1 , V_23 -> V_4 ) ;
} else {
V_23 -> V_105 = 0 ;
F_20 ( V_23 -> V_1 , V_23 -> V_4 ) ;
}
V_272:
F_88 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
return V_33 ;
}
static void F_99 ( struct V_262 * V_263 )
{
struct V_45 * V_23 ;
unsigned long V_261 ;
V_23 = F_90 ( V_263 , struct V_45 , V_23 ) ;
F_87 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
if ( F_62 ( & V_23 -> V_24 ) && ! V_23 -> V_105 ) {
F_20 ( V_23 -> V_1 , V_23 -> V_4 ) ;
F_4 ( V_23 -> V_1 , V_125 , V_23 -> V_91 ) ;
}
F_88 ( & V_23 -> V_1 -> V_17 , V_261 ) ;
}
static int F_100 ( struct V_273 * V_274 ,
struct V_275 * V_21 )
{
struct V_1 * V_1 = F_101 ( V_274 ) ;
V_21 -> V_21 . V_276 = NULL ;
V_1 -> V_21 = V_21 ;
F_5 ( V_1 , V_277 | V_278 , V_7 ) ;
if ( F_2 ( V_1 , V_135 ) & V_253 ) {
F_60 ( V_1 ) ;
V_1 -> V_252 = F_2 ( V_1 ,
V_135 ) & V_253 ;
V_1 -> V_254 = V_255 ;
F_84 ( & V_1 -> V_256 , V_257 + F_85 ( 50 ) ) ;
}
return 0 ;
}
static int F_102 ( struct V_273 * V_274 )
{
struct V_1 * V_1 = F_101 ( V_274 ) ;
F_4 ( V_1 , V_277 | V_278 , V_7 ) ;
F_56 ( V_1 ) ;
F_12 ( V_1 ) ;
V_1 -> V_21 = NULL ;
return 0 ;
}
static int F_103 ( struct V_273 * V_279 )
{
struct V_1 * V_1 = F_104 ( V_279 ) ;
return F_2 ( V_1 , V_280 ) & 0x03FF ;
}
static int F_105 ( struct V_273 * V_18 , int V_281 )
{
struct V_1 * V_1 = F_104 ( V_18 ) ;
unsigned long V_261 ;
F_87 ( & V_1 -> V_17 , V_261 ) ;
if ( V_281 )
F_5 ( V_1 , V_15 , V_16 ) ;
else
F_4 ( V_1 , V_15 , V_16 ) ;
F_88 ( & V_1 -> V_17 , V_261 ) ;
return 0 ;
}
static int F_106 ( struct V_282 * V_283 )
{
struct V_1 * V_1 = F_107 ( V_283 ) ;
F_108 ( & V_1 -> V_18 ) ;
F_109 ( & V_1 -> V_256 ) ;
F_110 ( V_1 -> V_5 ) ;
F_111 ( F_112 ( V_283 , 0 ) , V_1 ) ;
F_94 ( & V_1 -> V_23 [ 0 ] . V_23 , V_1 -> V_204 ) ;
if ( V_1 -> V_51 -> V_52 ) {
F_113 ( V_1 -> V_284 ) ;
F_114 ( V_1 -> V_284 ) ;
}
F_95 ( V_1 ) ;
return 0 ;
}
static void F_115 ( struct V_262 * V_23 , struct V_265 * V_285 )
{
}
static int F_116 ( struct V_282 * V_283 )
{
struct V_286 * V_287 , * V_288 ;
void T_5 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
char V_289 [ 8 ] ;
int V_33 = 0 ;
int V_177 ;
V_287 = F_117 ( V_283 , V_290 , 0 ) ;
if ( ! V_287 ) {
V_33 = - V_112 ;
F_16 ( L_19 ) ;
goto V_291;
}
V_288 = F_117 ( V_283 , V_292 , 0 ) ;
if ( ! V_288 ) {
V_33 = - V_112 ;
F_118 ( & V_283 -> V_293 ,
L_20 ) ;
goto V_291;
}
V_5 = F_119 ( V_287 -> V_294 , F_120 ( V_287 ) ) ;
if ( V_5 == NULL ) {
V_33 = - V_75 ;
F_16 ( L_21 ) ;
goto V_291;
}
if ( F_121 ( & V_283 -> V_293 ) == NULL ) {
F_118 ( & V_283 -> V_293 , L_22 ) ;
V_33 = - V_112 ;
goto V_291;
}
V_1 = F_93 ( sizeof( struct V_1 ) , V_206 ) ;
if ( V_1 == NULL ) {
V_33 = - V_75 ;
goto V_291;
}
V_1 -> V_51 = F_121 ( & V_283 -> V_293 ) ;
V_1 -> V_160 = V_288 -> V_261 & V_295 ;
F_122 ( & V_1 -> V_17 ) ;
F_123 ( V_283 , V_1 ) ;
V_1 -> V_18 . V_296 = & V_297 ;
V_1 -> V_18 . V_298 = V_221 ;
V_1 -> V_18 . V_299 = V_300 ;
F_124 ( & V_1 -> V_256 ) ;
V_1 -> V_256 . V_301 = F_86 ;
V_1 -> V_256 . V_302 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
V_33 = F_125 ( V_288 -> V_294 , F_83 , V_303 ,
V_300 , V_1 ) ;
if ( V_33 < 0 ) {
F_16 ( L_23 , V_33 ) ;
goto V_291;
}
if ( V_1 -> V_51 -> V_52 ) {
snprintf ( V_289 , sizeof( V_289 ) , L_24 , V_283 -> V_304 ) ;
V_1 -> V_284 = F_126 ( & V_283 -> V_293 , V_289 ) ;
if ( F_127 ( V_1 -> V_284 ) ) {
F_118 ( & V_283 -> V_293 , L_25 ,
V_289 ) ;
V_33 = F_128 ( V_1 -> V_284 ) ;
goto V_305;
}
F_129 ( V_1 -> V_284 ) ;
}
F_13 ( & V_1 -> V_18 . V_306 ) ;
V_1 -> V_18 . V_205 = & V_1 -> V_23 [ 0 ] . V_23 ;
F_13 ( & V_1 -> V_18 . V_205 -> V_306 ) ;
for ( V_177 = 0 ; V_177 < V_29 ; V_177 ++ ) {
struct V_45 * V_23 = & V_1 -> V_23 [ V_177 ] ;
if ( V_177 != 0 ) {
F_13 ( & V_1 -> V_23 [ V_177 ] . V_23 . V_306 ) ;
F_96 ( & V_1 -> V_23 [ V_177 ] . V_23 . V_306 ,
& V_1 -> V_18 . V_306 ) ;
}
V_23 -> V_1 = V_1 ;
F_13 ( & V_23 -> V_24 ) ;
V_23 -> V_23 . V_299 = V_307 [ V_177 ] ;
V_23 -> V_23 . V_296 = & V_308 ;
F_130 ( & V_23 -> V_23 , 512 ) ;
if ( V_177 == 0 ) {
V_23 -> V_23 . V_309 . V_310 = true ;
} else {
V_23 -> V_23 . V_309 . V_311 = true ;
V_23 -> V_23 . V_309 . V_312 = true ;
V_23 -> V_23 . V_309 . V_313 = true ;
}
V_23 -> V_23 . V_309 . V_62 = true ;
V_23 -> V_23 . V_309 . V_314 = true ;
}
F_130 ( & V_1 -> V_23 [ 0 ] . V_23 , 64 ) ;
V_1 -> V_23 [ 0 ] . V_4 = 0 ;
V_1 -> V_23 [ 0 ] . V_88 = V_99 ;
V_1 -> V_23 [ 0 ] . V_50 = V_100 ;
V_1 -> V_23 [ 0 ] . V_91 = V_101 ;
V_1 -> V_23 [ 0 ] . V_93 = 0 ;
V_1 -> V_23 [ 0 ] . V_83 = F_15 ( 0 ) ;
V_1 -> V_46 [ 0 ] = & V_1 -> V_23 [ 0 ] ;
V_1 -> V_102 [ 0 ] = & V_1 -> V_23 [ 0 ] ;
V_1 -> V_204 = F_92 ( & V_1 -> V_23 [ 0 ] . V_23 , V_206 ) ;
if ( V_1 -> V_204 == NULL ) {
V_33 = - V_75 ;
goto V_315;
}
V_1 -> V_204 -> V_316 = F_115 ;
F_56 ( V_1 ) ;
V_33 = F_131 ( & V_283 -> V_293 , & V_1 -> V_18 ) ;
if ( V_33 )
goto V_317;
F_132 ( & V_283 -> V_293 , L_26 , V_318 ) ;
return 0 ;
V_317:
F_94 ( & V_1 -> V_23 [ 0 ] . V_23 , V_1 -> V_204 ) ;
V_315:
if ( V_1 -> V_51 -> V_52 ) {
F_113 ( V_1 -> V_284 ) ;
F_114 ( V_1 -> V_284 ) ;
}
V_305:
F_111 ( V_288 -> V_294 , V_1 ) ;
V_291:
if ( V_1 ) {
if ( V_1 -> V_204 )
F_94 ( & V_1 -> V_23 [ 0 ] . V_23 , V_1 -> V_204 ) ;
F_95 ( V_1 ) ;
}
if ( V_5 )
F_110 ( V_5 ) ;
return V_33 ;
}
