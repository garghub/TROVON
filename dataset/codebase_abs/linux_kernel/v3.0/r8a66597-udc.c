static inline T_1 F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , V_2 ) & V_3 ;
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
F_5 ( V_1 , V_8 | V_10 , V_7 ) ;
F_5 ( V_1 , V_12 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
F_4 ( V_1 , V_11 , V_7 ) ;
F_4 ( V_1 , V_8 | V_10 , V_7 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
V_1 -> V_15 . V_16 = V_17 ;
F_10 ( & V_1 -> V_14 ) ;
V_1 -> V_18 -> V_19 ( & V_1 -> V_15 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_5 ( V_1 , V_20 , V_7 ) ;
F_14 ( & V_1 -> V_21 [ 0 ] . V_22 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_23 = 0 ;
unsigned long V_24 ;
if ( V_4 == 0 )
V_23 = F_2 ( V_1 , V_25 ) & V_26 ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
V_23 = F_2 ( V_1 , V_24 ) & V_26 ;
} else
F_17 ( V_28 L_1 , V_4 ) ;
return V_23 ;
}
static inline void F_18 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_23 )
{
unsigned long V_24 ;
if ( V_4 == 0 )
F_19 ( V_1 , V_23 , V_26 , V_25 ) ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_19 ( V_1 , V_23 , V_26 , V_24 ) ;
} else
F_17 ( V_28 L_1 , V_4 ) ;
}
static inline void F_20 ( struct V_1 * V_1 , T_1 V_4 )
{
F_18 ( V_1 , V_4 , V_29 ) ;
}
static inline void F_21 ( struct V_1 * V_1 , T_1 V_4 )
{
F_18 ( V_1 , V_4 , V_30 ) ;
}
static inline void F_22 ( struct V_1 * V_1 , T_1 V_4 )
{
F_18 ( V_1 , V_4 , V_31 ) ;
}
static inline T_1 F_23 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_32 = 0 ;
unsigned long V_24 ;
if ( V_4 == 0 )
V_32 = F_2 ( V_1 , V_25 ) ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
V_32 = F_2 ( V_1 , V_24 ) ;
} else
F_17 ( V_28 L_1 , V_4 ) ;
return V_32 ;
}
static inline void F_24 ( struct V_1 * V_1 , T_1 V_4 )
{
unsigned long V_24 ;
F_21 ( V_1 , V_4 ) ;
if ( V_4 == 0 )
F_5 ( V_1 , V_33 , V_25 ) ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_5 ( V_1 , V_33 , V_24 ) ;
} else
F_17 ( V_28 L_2 , V_4 ) ;
}
static inline int F_25 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_6 ;
int V_34 ;
if ( V_4 == 0 ) {
V_6 = F_2 ( V_1 , V_35 ) ;
if ( ( V_6 & V_36 ) != 0 )
V_34 = 256 ;
else {
V_6 = F_2 ( V_1 , V_37 ) ;
V_34 = V_6 & V_38 ;
}
} else {
F_6 ( V_1 , V_4 , V_39 ) ;
V_6 = F_2 ( V_1 , V_40 ) ;
if ( ( V_6 & V_36 ) != 0 ) {
V_6 = F_2 ( V_1 , V_41 ) ;
V_34 = ( ( V_6 >> 10 ) + 1 ) * 64 ;
} else {
V_6 = F_2 ( V_1 , V_42 ) ;
V_34 = V_6 & V_43 ;
}
}
return V_34 ;
}
static inline unsigned short F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_44 -> V_45 )
return V_46 ;
else
return V_47 ;
}
static inline void F_27 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_48 * V_21 = V_1 -> V_49 [ V_4 ] ;
if ( V_21 -> V_50 )
return;
F_19 ( V_1 , V_4 , V_51 , V_21 -> V_52 ) ;
F_28 ( 450 ) ;
F_5 ( V_1 , F_26 ( V_1 ) , V_21 -> V_52 ) ;
}
static int F_29 ( struct V_1 * V_1 ,
struct V_53 * V_54 )
{
T_1 V_55 = 0 , V_56 = 0 ;
T_1 V_57 = 0 ;
if ( V_54 -> V_58 == 0 )
return - V_59 ;
F_6 ( V_1 , V_54 -> V_58 , V_39 ) ;
if ( V_54 -> V_60 )
V_57 |= V_61 ;
V_57 |= V_54 -> type ;
V_57 |= V_54 -> V_62 ;
switch ( V_54 -> type ) {
case V_63 :
V_55 = 4 + ( V_54 -> V_58 - V_64 ) ;
V_56 = 0 ;
break;
case V_65 :
if ( V_54 -> V_58 >= V_66 )
V_55 = V_54 -> V_58 - V_66 ;
else
V_55 = V_54 -> V_58 - V_67 ;
V_55 = V_68 + ( V_55 * 16 ) ;
V_56 = 7 ;
V_57 |= V_69 ;
if ( ! V_54 -> V_60 )
V_57 |= V_70 ;
break;
case V_71 :
V_55 = V_68 +
( V_54 -> V_58 - V_67 ) * 16 ;
V_56 = 7 ;
break;
}
if ( V_56 && ( ( V_55 + 16 ) >= V_72 ) ) {
F_30 ( L_3 ) ;
return - V_73 ;
}
F_6 ( V_1 , V_57 , V_40 ) ;
F_6 ( V_1 , ( V_56 << 10 ) | ( V_55 ) , V_41 ) ;
F_6 ( V_1 , V_54 -> V_74 , V_42 ) ;
if ( V_54 -> V_75 )
V_54 -> V_75 -- ;
F_6 ( V_1 , V_54 -> V_75 , V_76 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_1 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_58 == 0 )
return;
if ( F_32 ( V_54 -> V_58 ) )
V_1 -> V_77 -- ;
else if ( F_33 ( V_54 -> V_58 ) )
V_1 -> V_78 -- ;
else if ( F_34 ( V_54 -> V_58 ) ) {
V_1 -> V_79 -- ;
if ( V_54 -> type == V_65 )
V_1 -> V_77 -- ;
} else
F_17 ( V_28 L_4 ,
V_54 -> V_58 ) ;
}
static void F_35 ( struct V_48 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_19 ( V_1 , 0 , V_51 , V_21 -> V_52 ) ;
F_6 ( V_1 , V_80 , V_21 -> V_81 ) ;
F_6 ( V_1 , 0 , V_21 -> V_81 ) ;
F_6 ( V_1 , V_33 , V_21 -> V_81 ) ;
if ( V_21 -> V_50 ) {
F_19 ( V_1 , V_21 -> V_4 , V_51 , V_21 -> V_52 ) ;
F_28 ( 450 ) ;
F_5 ( V_1 , F_26 ( V_1 ) , V_21 -> V_52 ) ;
}
}
static void F_36 ( struct V_1 * V_1 ,
struct V_48 * V_21 ,
const struct V_82 * V_83 ,
T_1 V_4 , int V_84 )
{
V_21 -> V_50 = 0 ;
V_21 -> V_85 = V_86 ;
V_21 -> V_52 = V_87 ;
V_21 -> V_88 = V_89 ;
V_21 -> V_90 = 0 ;
V_21 -> V_81 = F_16 ( V_4 ) ;
V_21 -> V_4 = V_4 ;
V_21 -> V_21 . V_74 = F_37 ( V_83 -> V_91 ) ;
V_1 -> V_49 [ V_4 ] = V_21 ;
V_1 -> V_92 [ V_83 -> V_93 & V_94 ]
= V_21 ;
F_14 ( & V_21 -> V_22 ) ;
}
static void F_38 ( struct V_48 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_4 == 0 )
return;
if ( V_21 -> V_50 )
V_1 -> V_95 -- ;
V_21 -> V_4 = 0 ;
V_21 -> V_96 = 0 ;
V_21 -> V_50 = 0 ;
}
static int F_39 ( struct V_48 * V_21 ,
const struct V_82 * V_83 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_53 V_54 ;
int V_84 = 0 ;
unsigned char * V_97 ;
int V_32 ;
V_21 -> V_83 = V_83 ;
if ( V_21 -> V_4 )
return 0 ;
switch ( V_83 -> V_98 & V_99 ) {
case V_100 :
if ( V_1 -> V_77 >= V_101 ) {
if ( V_1 -> V_79 >= V_102 ) {
F_17 ( V_28 L_5 ) ;
return - V_103 ;
} else {
V_54 . V_58 = V_67
+ V_1 -> V_79 ;
V_97 = & V_1 -> V_79 ;
}
} else {
V_54 . V_58 = V_66 + V_1 -> V_77 ;
V_97 = & V_1 -> V_77 ;
}
V_54 . type = V_65 ;
V_84 = 1 ;
break;
case V_104 :
if ( V_1 -> V_78 >= V_105 ) {
F_17 ( V_28 L_6 ) ;
return - V_103 ;
}
V_54 . V_58 = V_64 + V_1 -> V_78 ;
V_54 . type = V_63 ;
V_97 = & V_1 -> V_78 ;
break;
case V_106 :
if ( V_1 -> V_79 >= V_102 ) {
F_17 ( V_28 L_7 ) ;
return - V_103 ;
}
V_54 . V_58 = V_67 + V_1 -> V_79 ;
V_54 . type = V_71 ;
V_97 = & V_1 -> V_79 ;
break;
default:
F_17 ( V_28 L_8 ) ;
return - V_59 ;
}
V_21 -> type = V_54 . type ;
V_54 . V_62 = V_83 -> V_93 & V_94 ;
V_54 . V_74 = F_37 ( V_83 -> V_91 ) ;
V_54 . V_75 = V_83 -> V_107 ;
if ( V_83 -> V_93 & V_108 )
V_54 . V_60 = 1 ;
else
V_54 . V_60 = 0 ;
V_32 = F_29 ( V_1 , & V_54 ) ;
if ( V_32 < 0 ) {
F_17 ( V_28 L_9 ) ;
return V_32 ;
}
( * V_97 ) ++ ;
if ( ( V_97 == & V_1 -> V_79 ) && V_54 . type == V_65 )
V_1 -> V_77 ++ ;
F_36 ( V_1 , V_21 , V_83 , V_54 . V_58 , V_84 ) ;
F_35 ( V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_48 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_53 V_54 ;
V_54 . V_58 = V_21 -> V_4 ;
V_54 . type = V_21 -> type ;
F_31 ( V_1 , & V_54 ) ;
F_38 ( V_21 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 , T_1 V_4 )
{
F_42 ( V_1 , V_4 ) ;
F_43 ( V_1 , V_4 ) ;
}
static void F_44 ( struct V_1 * V_1 , T_1 V_4 )
{
F_45 ( V_1 , V_4 ) ;
F_46 ( V_1 , V_4 ) ;
}
static void F_47 ( struct V_1 * V_1 , unsigned V_109 )
{
V_1 -> V_21 [ 0 ] . V_110 = V_109 ;
F_20 ( V_1 , 0 ) ;
F_5 ( V_1 , V_111 , V_25 ) ;
}
static void F_48 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_27 ( V_1 , V_21 -> V_4 ) ;
F_19 ( V_1 , V_114 , ( V_114 | V_51 ) , V_87 ) ;
F_6 ( V_1 , V_115 , V_21 -> V_88 ) ;
if ( V_113 -> V_113 . V_116 == 0 ) {
F_5 ( V_1 , V_117 , V_21 -> V_88 ) ;
F_20 ( V_1 , 0 ) ;
F_49 ( V_21 , V_113 , 0 ) ;
} else {
F_6 ( V_1 , ~ V_118 , V_119 ) ;
F_50 ( V_21 , V_113 ) ;
}
}
static void F_51 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_6 ;
F_27 ( V_1 , V_21 -> V_4 ) ;
F_52 ( V_1 , V_21 -> V_4 ) ;
F_20 ( V_1 , V_21 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( F_53 ( ( V_6 & V_120 ) == 0 ) )
F_41 ( V_1 , V_21 -> V_4 ) ;
else
F_54 ( V_21 , V_113 ) ;
}
static void F_55 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_21 -> V_4 == 0 ) {
F_19 ( V_1 , 0 , ( V_114 | V_51 ) , V_87 ) ;
F_6 ( V_1 , V_115 , V_21 -> V_88 ) ;
F_20 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
} else {
if ( V_21 -> V_50 ) {
F_5 ( V_1 , V_121 , V_21 -> V_52 ) ;
F_27 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_122 , V_21 -> V_52 ) ;
F_6 ( V_1 ,
( V_113 -> V_113 . V_116 + V_21 -> V_21 . V_74 - 1 )
/ V_21 -> V_21 . V_74 ,
V_21 -> V_90 ) ;
}
F_20 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
}
}
static void F_56 ( struct V_48 * V_21 , struct V_112 * V_113 )
{
if ( V_21 -> V_83 -> V_93 & V_123 )
F_51 ( V_21 , V_113 ) ;
else
F_55 ( V_21 , V_113 ) ;
}
static void F_57 ( struct V_48 * V_21 , struct V_112 * V_113 )
{
T_1 V_124 ;
V_124 = F_2 ( V_21 -> V_1 , V_125 ) & V_126 ;
switch ( V_124 ) {
case V_127 :
F_48 ( V_21 , V_113 ) ;
break;
case V_128 :
F_55 ( V_21 , V_113 ) ;
break;
case V_129 :
F_47 ( V_21 -> V_1 , 0 ) ;
break;
default:
F_17 ( V_28 L_10 , V_124 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_130 = V_1 -> V_44 -> V_130 ? V_131 : 0 ;
T_1 V_132 = V_1 -> V_133 ? V_134 : 0 ;
T_1 V_135 = V_1 -> V_44 -> V_135 ? V_136 : 0 ;
if ( V_1 -> V_44 -> V_45 ) {
F_5 ( V_1 , 0x04 , V_137 ) ;
F_5 ( V_1 , V_138 , V_13 ) ;
F_4 ( V_1 , V_139 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_139 , V_13 ) ;
F_5 ( V_1 , V_140 , V_13 ) ;
F_5 ( V_1 , V_132 , V_141 ) ;
F_6 ( V_1 , V_142 | V_143 ,
V_144 ) ;
} else {
F_5 ( V_1 , V_130 | V_135 , V_145 ) ;
F_5 ( V_1 , V_138 , V_13 ) ;
F_19 ( V_1 , F_58 ( V_1 -> V_44 ) ,
V_146 , V_13 ) ;
F_4 ( V_1 , V_139 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_139 , V_13 ) ;
F_5 ( V_1 , V_147 , V_13 ) ;
F_59 ( 3 ) ;
F_5 ( V_1 , V_148 , V_13 ) ;
F_59 ( 1 ) ;
F_5 ( V_1 , V_140 , V_13 ) ;
F_5 ( V_1 , V_132 , V_141 ) ;
F_6 ( V_1 , V_142 | V_143 ,
V_144 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
if ( V_1 -> V_44 -> V_45 ) {
F_5 ( V_1 , V_140 , V_13 ) ;
F_6 ( V_1 , 0 , V_7 ) ;
F_6 ( V_1 , 0 , V_141 ) ;
F_6 ( V_1 , 0 , V_149 ) ;
F_6 ( V_1 , 0 , V_150 ) ;
F_6 ( V_1 , 0 , V_151 ) ;
F_6 ( V_1 , 0 , V_152 ) ;
F_6 ( V_1 , 0 , V_153 ) ;
F_6 ( V_1 , 0 , V_119 ) ;
F_4 ( V_1 , V_139 , V_13 ) ;
F_4 ( V_1 , V_140 , V_13 ) ;
} else {
F_4 ( V_1 , V_140 , V_13 ) ;
F_60 ( 1 ) ;
F_4 ( V_1 , V_148 , V_13 ) ;
F_60 ( 1 ) ;
F_60 ( 1 ) ;
F_4 ( V_1 , V_147 , V_13 ) ;
}
}
static void F_61 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_44 -> V_45 ) {
V_6 = F_2 ( V_1 , V_13 ) ;
if ( ! ( V_6 & V_147 ) )
F_5 ( V_1 , V_147 , V_13 ) ;
}
}
static struct V_112 * F_62 ( struct V_48 * V_21 )
{
return F_63 ( V_21 -> V_22 . V_154 , struct V_112 , V_22 ) ;
}
static void F_49 ( struct V_48 * V_21 ,
struct V_112 * V_113 , int V_155 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
int V_156 = 0 ;
if ( F_53 ( V_21 -> V_4 == 0 ) ) {
if ( V_21 -> V_110 ) {
V_21 -> V_110 = 0 ;
return;
}
}
F_64 ( & V_113 -> V_22 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
V_113 -> V_113 . V_155 = - V_157 ;
else
V_113 -> V_113 . V_155 = V_155 ;
if ( ! F_65 ( & V_21 -> V_22 ) )
V_156 = 1 ;
F_10 ( & V_21 -> V_1 -> V_14 ) ;
V_113 -> V_113 . V_158 ( & V_21 -> V_21 , & V_113 -> V_113 ) ;
F_11 ( & V_21 -> V_1 -> V_14 ) ;
if ( V_156 ) {
V_113 = F_62 ( V_21 ) ;
if ( V_21 -> V_83 )
F_56 ( V_21 , V_113 ) ;
}
}
static void F_50 ( struct V_48 * V_21 , struct V_112 * V_113 )
{
int V_159 ;
T_1 V_6 ;
unsigned V_160 ;
T_2 V_34 ;
void * V_161 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_27 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_114 , V_21 -> V_52 ) ;
V_159 = 0 ;
do {
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( V_159 ++ > 100000 ) {
F_17 ( V_28 L_11
L_12 ) ;
return;
}
F_28 ( 1 ) ;
} while ( ( V_6 & V_120 ) == 0 );
V_160 = F_25 ( V_1 , V_4 ) ;
V_161 = V_113 -> V_113 . V_161 + V_113 -> V_113 . V_162 ;
V_34 = F_66 ( V_160 , V_113 -> V_113 . V_116 - V_113 -> V_113 . V_162 ) ;
if ( V_113 -> V_113 . V_161 ) {
if ( V_34 > 0 )
F_67 ( V_1 , V_21 -> V_85 , V_161 , V_34 ) ;
if ( ( V_34 == 0 ) || ( ( V_34 % V_21 -> V_21 . V_74 ) != 0 ) )
F_5 ( V_1 , V_117 , V_21 -> V_88 ) ;
}
V_113 -> V_113 . V_162 += V_34 ;
if ( ( ! V_113 -> V_113 . V_163 && ( V_113 -> V_113 . V_162 == V_113 -> V_113 . V_116 ) )
|| ( V_34 % V_21 -> V_21 . V_74 )
|| ( V_34 == 0 ) ) {
F_45 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 ) ;
} else {
F_45 ( V_1 , V_4 ) ;
F_68 ( V_1 , V_4 ) ;
}
F_20 ( V_1 , V_4 ) ;
}
static void F_54 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
T_1 V_6 ;
unsigned V_160 ;
T_2 V_34 ;
void * V_161 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_27 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( F_53 ( ( V_6 & V_120 ) == 0 ) ) {
F_21 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
F_17 ( V_28 L_13 , V_4 ) ;
return;
}
V_160 = F_25 ( V_1 , V_4 ) ;
V_161 = V_113 -> V_113 . V_161 + V_113 -> V_113 . V_162 ;
V_34 = F_66 ( V_160 , V_113 -> V_113 . V_116 - V_113 -> V_113 . V_162 ) ;
if ( V_113 -> V_113 . V_161 ) {
F_67 ( V_1 , V_21 -> V_85 , V_161 , V_34 ) ;
if ( ( V_34 == 0 )
|| ( ( V_34 % V_21 -> V_21 . V_74 ) != 0 )
|| ( ( V_160 != V_21 -> V_21 . V_74 )
&& ( V_160 > V_34 ) ) )
F_5 ( V_1 , V_117 , V_21 -> V_88 ) ;
}
V_113 -> V_113 . V_162 += V_34 ;
if ( ( ! V_113 -> V_113 . V_163 && ( V_113 -> V_113 . V_162 == V_113 -> V_113 . V_116 ) )
|| ( V_34 % V_21 -> V_21 . V_74 )
|| ( V_34 == 0 ) ) {
F_45 ( V_1 , V_4 ) ;
F_68 ( V_1 , V_4 ) ;
} else {
F_52 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
}
}
static void F_69 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
T_1 V_6 ;
int V_164 , V_160 , V_165 ;
int V_34 ;
void * V_161 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_166 = 0 ;
F_27 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( F_53 ( ( V_6 & V_120 ) == 0 ) ) {
V_113 -> V_113 . V_155 = - V_167 ;
F_21 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
F_17 ( V_28 L_14 ) ;
return;
}
V_164 = V_6 & V_168 ;
V_160 = F_25 ( V_1 , V_4 ) ;
V_161 = V_113 -> V_113 . V_161 + V_113 -> V_113 . V_162 ;
V_165 = V_113 -> V_113 . V_116 - V_113 -> V_113 . V_162 ;
if ( V_164 < V_160 )
V_34 = F_66 ( V_164 , V_165 ) ;
else
V_34 = F_66 ( V_160 , V_165 ) ;
V_113 -> V_113 . V_162 += V_34 ;
if ( ( ! V_113 -> V_113 . V_163 && ( V_113 -> V_113 . V_162 == V_113 -> V_113 . V_116 ) )
|| ( V_34 % V_21 -> V_21 . V_74 )
|| ( V_34 == 0 ) ) {
F_21 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
V_166 = 1 ;
}
if ( V_113 -> V_113 . V_161 ) {
if ( V_34 == 0 )
F_6 ( V_1 , V_115 , V_21 -> V_88 ) ;
else
F_70 ( V_1 , V_21 -> V_85 , V_161 , V_34 ) ;
}
if ( ( V_21 -> V_4 != 0 ) && V_166 )
F_49 ( V_21 , V_113 , 0 ) ;
}
static void F_71 ( struct V_1 * V_1 , T_1 V_155 , T_1 V_169 )
{
T_1 V_170 ;
T_1 V_4 ;
struct V_48 * V_21 ;
struct V_112 * V_113 ;
if ( ( V_155 & V_171 ) && ( V_169 & V_171 ) ) {
F_6 ( V_1 , ~ V_171 , V_152 ) ;
F_19 ( V_1 , 0 , V_51 , V_87 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_113 = F_62 ( V_21 ) ;
F_69 ( V_21 , V_113 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_170 = 1 << V_4 ;
if ( ( V_155 & V_170 ) && ( V_169 & V_170 ) ) {
F_6 ( V_1 , ~ V_170 , V_152 ) ;
V_21 = V_1 -> V_49 [ V_4 ] ;
V_113 = F_62 ( V_21 ) ;
if ( V_21 -> V_83 -> V_93 & V_123 )
F_54 ( V_21 , V_113 ) ;
else
F_69 ( V_21 , V_113 ) ;
}
}
}
}
static void F_72 ( struct V_1 * V_1 , T_1 V_155 , T_1 V_169 )
{
T_1 V_6 ;
T_1 V_170 ;
T_1 V_4 ;
struct V_48 * V_21 ;
struct V_112 * V_113 ;
if ( ( V_155 & V_118 ) && ( V_169 & V_118 ) ) {
F_6 ( V_1 , ~ V_118 , V_119 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_113 = F_62 ( V_21 ) ;
F_50 ( V_21 , V_113 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_170 = 1 << V_4 ;
if ( ( V_155 & V_170 ) && ( V_169 & V_170 ) ) {
F_6 ( V_1 , ~ V_170 , V_119 ) ;
V_6 = F_23 ( V_1 , V_4 ) ;
if ( ( V_6 & V_172 ) == 0 ) {
F_52 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
F_21 ( V_1 , V_4 ) ;
V_21 = V_1 -> V_49 [ V_4 ] ;
V_113 = F_62 ( V_21 ) ;
if ( ! F_65 ( & V_21 -> V_22 ) )
F_49 ( V_21 , V_113 , 0 ) ;
}
}
}
}
}
static void F_73 ( struct V_1 * V_1 , struct V_173 * V_174 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_48 * V_21 ;
T_1 V_23 ;
T_1 V_155 = 0 ;
T_1 V_175 = F_37 ( V_174 -> V_176 ) ;
switch ( V_174 -> V_177 & V_178 ) {
case V_179 :
V_155 = 1 << V_180 ;
break;
case V_181 :
V_155 = 0 ;
break;
case V_182 :
V_21 = V_1 -> V_92 [ V_175 & V_94 ] ;
V_23 = F_15 ( V_1 , V_21 -> V_4 ) ;
if ( V_23 == V_31 )
V_155 = 1 << V_183 ;
else
V_155 = 0 ;
break;
default:
F_22 ( V_1 , 0 ) ;
return;
}
V_1 -> V_184 = F_74 ( V_155 ) ;
V_1 -> V_185 -> V_161 = & V_1 -> V_184 ;
V_1 -> V_185 -> V_116 = 2 ;
F_10 ( & V_1 -> V_14 ) ;
F_75 ( V_1 -> V_15 . V_186 , V_1 -> V_185 , V_187 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
static void F_76 ( struct V_1 * V_1 ,
struct V_173 * V_174 )
{
switch ( V_174 -> V_177 & V_178 ) {
case V_179 :
F_47 ( V_1 , 1 ) ;
break;
case V_181 :
F_47 ( V_1 , 1 ) ;
break;
case V_182 : {
struct V_48 * V_21 ;
struct V_112 * V_113 ;
T_1 V_175 = F_37 ( V_174 -> V_176 ) ;
V_21 = V_1 -> V_92 [ V_175 & V_94 ] ;
if ( ! V_21 -> V_188 ) {
F_21 ( V_1 , V_21 -> V_4 ) ;
F_24 ( V_1 , V_21 -> V_4 ) ;
F_10 ( & V_1 -> V_14 ) ;
F_77 ( & V_21 -> V_21 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
F_47 ( V_1 , 1 ) ;
V_113 = F_62 ( V_21 ) ;
if ( V_21 -> V_96 ) {
V_21 -> V_96 = 0 ;
if ( F_65 ( & V_21 -> V_22 ) )
break;
F_56 ( V_21 , V_113 ) ;
} else if ( ! F_65 ( & V_21 -> V_22 ) )
F_20 ( V_1 , V_21 -> V_4 ) ;
}
break;
default:
F_22 ( V_1 , 0 ) ;
break;
}
}
static void F_78 ( struct V_1 * V_1 , struct V_173 * V_174 )
{
switch ( V_174 -> V_177 & V_178 ) {
case V_179 :
F_47 ( V_1 , 1 ) ;
break;
case V_181 :
F_47 ( V_1 , 1 ) ;
break;
case V_182 : {
struct V_48 * V_21 ;
T_1 V_175 = F_37 ( V_174 -> V_176 ) ;
V_21 = V_1 -> V_92 [ V_175 & V_94 ] ;
F_22 ( V_1 , V_21 -> V_4 ) ;
F_47 ( V_1 , 1 ) ;
}
break;
default:
F_22 ( V_1 , 0 ) ;
break;
}
}
static int F_79 ( struct V_1 * V_1 , struct V_173 * V_174 )
{
T_1 * V_189 = ( T_1 * ) V_174 ;
unsigned long V_24 = V_190 ;
int V_159 , V_32 = 0 ;
F_6 ( V_1 , ~ V_191 , V_125 ) ;
for ( V_159 = 0 ; V_159 < 4 ; V_159 ++ )
V_189 [ V_159 ] = F_2 ( V_1 , V_24 + V_159 * 2 ) ;
if ( ( V_174 -> V_177 & V_192 ) == V_193 ) {
switch ( V_174 -> V_194 ) {
case V_195 :
F_73 ( V_1 , V_174 ) ;
break;
case V_196 :
F_76 ( V_1 , V_174 ) ;
break;
case V_197 :
F_78 ( V_1 , V_174 ) ;
break;
default:
V_32 = 1 ;
break;
}
} else
V_32 = 1 ;
return V_32 ;
}
static void F_80 ( struct V_1 * V_1 )
{
T_1 V_16 = F_1 ( V_1 ) ;
switch ( V_16 ) {
case V_198 :
V_1 -> V_15 . V_16 = V_199 ;
break;
case V_200 :
V_1 -> V_15 . V_16 = V_201 ;
break;
default:
V_1 -> V_15 . V_16 = V_17 ;
F_17 ( V_28 L_15 ) ;
}
}
static void F_81 ( struct V_1 * V_1 )
{
T_1 V_202 ;
V_202 = F_2 ( V_1 , V_125 ) & V_203 ;
F_6 ( V_1 , ~ V_204 , V_125 ) ;
if ( V_202 == V_205 ) {
F_10 ( & V_1 -> V_14 ) ;
V_1 -> V_18 -> V_19 ( & V_1 -> V_15 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_80 ( V_1 ) ;
}
if ( V_1 -> V_206 == V_207 && V_202 != V_207 )
F_80 ( V_1 ) ;
if ( ( V_202 == V_207 || V_202 == V_208 )
&& V_1 -> V_15 . V_16 == V_17 )
F_80 ( V_1 ) ;
V_1 -> V_206 = V_202 ;
}
static void F_82 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_173 V_174 ;
T_1 V_124 ;
V_124 = F_2 ( V_1 , V_125 ) & V_126 ;
F_6 ( V_1 , ~ V_209 , V_125 ) ;
switch ( V_124 ) {
case V_210 : {
struct V_48 * V_21 ;
struct V_112 * V_113 ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_113 = F_62 ( V_21 ) ;
F_49 ( V_21 , V_113 , 0 ) ;
}
break;
case V_127 :
case V_128 :
case V_129 :
if ( F_79 ( V_1 , & V_174 ) ) {
F_10 ( & V_1 -> V_14 ) ;
if ( V_1 -> V_18 -> V_211 ( & V_1 -> V_15 , & V_174 )
< 0 )
F_22 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
break;
case V_212 :
case V_213 :
F_47 ( V_1 , 0 ) ;
break;
default:
F_17 ( V_28 L_16 , V_124 ) ;
break;
}
}
static T_3 F_83 ( int V_214 , void * V_215 )
{
struct V_1 * V_1 = V_215 ;
T_1 V_216 ;
T_1 V_217 ;
T_1 V_218 , V_219 , V_220 ;
T_1 V_221 , V_222 , V_223 ;
T_1 V_224 ;
T_1 V_225 ;
F_11 ( & V_1 -> V_14 ) ;
V_216 = F_2 ( V_1 , V_125 ) ;
V_217 = F_2 ( V_1 , V_7 ) ;
V_224 = F_2 ( V_1 , V_87 ) ;
V_225 = V_216 & V_217 ;
if ( V_225 ) {
V_218 = F_2 ( V_1 , V_152 ) ;
V_219 = F_2 ( V_1 , V_153 ) ;
V_220 = F_2 ( V_1 , V_119 ) ;
V_221 = F_2 ( V_1 , V_149 ) ;
V_222 = F_2 ( V_1 , V_151 ) ;
V_223 = F_2 ( V_1 , V_150 ) ;
if ( V_225 & V_226 ) {
F_6 ( V_1 , 0xffff & ~ V_226 ,
V_125 ) ;
F_61 ( V_1 ) ;
V_1 -> V_227 = F_2 ( V_1 , V_125 )
& V_228 ;
V_1 -> V_229 = V_230 ;
F_84 ( & V_1 -> V_231 ,
V_232 + F_85 ( 50 ) ) ;
}
if ( V_216 & V_203 )
F_81 ( V_1 ) ;
if ( ( V_216 & V_233 ) && ( V_217 & V_10 )
&& ( V_218 & V_221 ) )
F_71 ( V_1 , V_218 , V_221 ) ;
if ( ( V_216 & V_234 ) && ( V_217 & V_8 )
&& ( V_220 & V_223 ) )
F_72 ( V_1 , V_220 , V_223 ) ;
if ( V_216 & V_209 )
F_82 ( V_1 ) ;
}
F_6 ( V_1 , V_224 , V_87 ) ;
F_10 ( & V_1 -> V_14 ) ;
return V_235 ;
}
static void F_86 ( unsigned long V_215 )
{
struct V_1 * V_1 = (struct V_1 * ) V_215 ;
unsigned long V_236 ;
T_1 V_6 ;
F_87 ( & V_1 -> V_14 , V_236 ) ;
V_6 = F_2 ( V_1 , V_13 ) ;
if ( V_1 -> V_229 > 0 ) {
V_6 = F_2 ( V_1 , V_125 ) & V_228 ;
if ( V_6 == V_1 -> V_227 ) {
V_1 -> V_229 -- ;
if ( V_1 -> V_229 == 0 ) {
if ( V_6 == V_228 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_84 ( & V_1 -> V_231 ,
V_232 + F_85 ( 50 ) ) ;
}
} else {
V_1 -> V_229 = V_230 ;
V_1 -> V_227 = V_6 ;
F_84 ( & V_1 -> V_231 ,
V_232 + F_85 ( 50 ) ) ;
}
}
F_88 ( & V_1 -> V_14 , V_236 ) ;
}
static int F_89 ( struct V_237 * V_238 ,
const struct V_82 * V_83 )
{
struct V_48 * V_21 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
return F_39 ( V_21 , V_83 ) ;
}
static int F_91 ( struct V_237 * V_238 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_236 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
F_92 ( ! V_21 ) ;
while ( ! F_65 ( & V_21 -> V_22 ) ) {
V_113 = F_62 ( V_21 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
F_49 ( V_21 , V_113 , - V_239 ) ;
F_88 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
}
F_44 ( V_21 -> V_1 , V_21 -> V_4 ) ;
return F_40 ( V_21 ) ;
}
static struct V_240 * F_93 ( struct V_237 * V_238 ,
T_4 V_241 )
{
struct V_112 * V_113 ;
V_113 = F_94 ( sizeof( struct V_112 ) , V_241 ) ;
if ( ! V_113 )
return NULL ;
F_14 ( & V_113 -> V_22 ) ;
return & V_113 -> V_113 ;
}
static void F_95 ( struct V_237 * V_238 , struct V_240 * V_242 )
{
struct V_112 * V_113 ;
V_113 = F_90 ( V_242 , struct V_112 , V_113 ) ;
F_96 ( V_113 ) ;
}
static int F_75 ( struct V_237 * V_238 , struct V_240 * V_242 ,
T_4 V_241 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_236 ;
int V_243 = 0 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
V_113 = F_90 ( V_242 , struct V_112 , V_113 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
return - V_157 ;
F_87 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
if ( F_65 ( & V_21 -> V_22 ) )
V_243 = 1 ;
F_97 ( & V_113 -> V_22 , & V_21 -> V_22 ) ;
V_113 -> V_113 . V_162 = 0 ;
V_113 -> V_113 . V_155 = - V_244 ;
if ( V_21 -> V_83 == NULL )
F_57 ( V_21 , V_113 ) ;
else {
if ( V_243 && ! V_21 -> V_96 )
F_56 ( V_21 , V_113 ) ;
}
F_88 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
return 0 ;
}
static int F_98 ( struct V_237 * V_238 , struct V_240 * V_242 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_236 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
V_113 = F_90 ( V_242 , struct V_112 , V_113 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
if ( ! F_65 ( & V_21 -> V_22 ) )
F_49 ( V_21 , V_113 , - V_239 ) ;
F_88 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
return 0 ;
}
static int F_99 ( struct V_237 * V_238 , int V_245 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_236 ;
int V_32 = 0 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
V_113 = F_62 ( V_21 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
if ( ! F_65 ( & V_21 -> V_22 ) ) {
V_32 = - V_246 ;
goto V_247;
}
if ( V_245 ) {
V_21 -> V_96 = 1 ;
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
} else {
V_21 -> V_96 = 0 ;
V_21 -> V_188 = 0 ;
F_21 ( V_21 -> V_1 , V_21 -> V_4 ) ;
}
V_247:
F_88 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
return V_32 ;
}
static int F_100 ( struct V_237 * V_238 )
{
struct V_48 * V_21 ;
unsigned long V_236 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
if ( ! V_21 || ! V_21 -> V_83 )
return - V_59 ;
F_87 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
V_21 -> V_188 = 1 ;
F_88 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
return F_101 ( V_238 ) ;
}
static void F_102 ( struct V_237 * V_238 )
{
struct V_48 * V_21 ;
unsigned long V_236 ;
V_21 = F_90 ( V_238 , struct V_48 , V_21 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
if ( F_65 ( & V_21 -> V_22 ) && ! V_21 -> V_96 ) {
F_21 ( V_21 -> V_1 , V_21 -> V_4 ) ;
F_4 ( V_21 -> V_1 , V_115 , V_21 -> V_88 ) ;
}
F_88 ( & V_21 -> V_1 -> V_14 , V_236 ) ;
}
int F_103 ( struct V_248 * V_18 ,
int (* F_104)( struct V_249 * ) )
{
struct V_1 * V_1 = V_250 ;
int V_251 ;
if ( ! V_18
|| V_18 -> V_16 != V_199
|| ! F_104
|| ! V_18 -> V_211 )
return - V_59 ;
if ( ! V_1 )
return - V_103 ;
if ( V_1 -> V_18 )
return - V_252 ;
V_18 -> V_18 . V_253 = NULL ;
V_1 -> V_18 = V_18 ;
V_1 -> V_15 . V_254 . V_18 = & V_18 -> V_18 ;
V_251 = F_105 ( & V_1 -> V_15 . V_254 ) ;
if ( V_251 ) {
F_17 ( V_28 L_17 , V_251 ) ;
goto error;
}
V_251 = F_104 ( & V_1 -> V_15 ) ;
if ( V_251 ) {
F_17 ( V_28 L_18 , V_251 ) ;
F_106 ( & V_1 -> V_15 . V_254 ) ;
goto error;
}
F_5 ( V_1 , V_20 , V_7 ) ;
if ( F_2 ( V_1 , V_125 ) & V_228 ) {
F_61 ( V_1 ) ;
V_1 -> V_227 = F_2 ( V_1 ,
V_125 ) & V_228 ;
V_1 -> V_229 = V_230 ;
F_84 ( & V_1 -> V_231 , V_232 + F_85 ( 50 ) ) ;
}
return 0 ;
error:
V_1 -> V_18 = NULL ;
V_1 -> V_15 . V_254 . V_18 = NULL ;
return V_251 ;
}
int F_107 ( struct V_248 * V_18 )
{
struct V_1 * V_1 = V_250 ;
unsigned long V_236 ;
if ( V_18 != V_1 -> V_18 || ! V_18 -> V_255 )
return - V_59 ;
F_87 ( & V_1 -> V_14 , V_236 ) ;
if ( V_1 -> V_15 . V_16 != V_17 )
F_9 ( V_1 ) ;
F_88 ( & V_1 -> V_14 , V_236 ) ;
F_4 ( V_1 , V_20 , V_7 ) ;
V_18 -> V_255 ( & V_1 -> V_15 ) ;
F_13 ( V_1 ) ;
F_12 ( V_1 ) ;
F_106 ( & V_1 -> V_15 . V_254 ) ;
V_1 -> V_18 = NULL ;
return 0 ;
}
static int F_108 ( struct V_249 * V_256 )
{
struct V_1 * V_1 = F_109 ( V_256 ) ;
return F_2 ( V_1 , V_257 ) & 0x03FF ;
}
static int T_5 F_110 ( struct V_258 * V_259 )
{
struct V_1 * V_1 = F_111 ( & V_259 -> V_254 ) ;
F_112 ( & V_1 -> V_231 ) ;
F_113 ( V_1 -> V_5 ) ;
F_114 ( F_115 ( V_259 , 0 ) , V_1 ) ;
F_95 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_185 ) ;
#ifdef F_116
if ( V_1 -> V_44 -> V_45 ) {
F_117 ( V_1 -> V_260 ) ;
F_118 ( V_1 -> V_260 ) ;
}
#endif
F_96 ( V_1 ) ;
return 0 ;
}
static void F_119 ( struct V_237 * V_21 , struct V_240 * V_261 )
{
}
static int T_6 F_120 ( struct V_258 * V_259 )
{
#ifdef F_116
char V_262 [ 8 ] ;
#endif
struct V_263 * V_264 , * V_265 ;
int V_214 ;
void T_7 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
int V_32 = 0 ;
int V_159 ;
unsigned long V_266 ;
V_264 = F_121 ( V_259 , V_267 , 0 ) ;
if ( ! V_264 ) {
V_32 = - V_103 ;
F_17 ( V_28 L_19 ) ;
goto V_268;
}
V_265 = F_121 ( V_259 , V_269 , 0 ) ;
V_214 = V_265 -> V_270 ;
V_266 = V_265 -> V_236 & V_271 ;
if ( V_214 < 0 ) {
V_32 = - V_103 ;
F_17 ( V_28 L_20 ) ;
goto V_268;
}
V_5 = F_122 ( V_264 -> V_270 , F_123 ( V_264 ) ) ;
if ( V_5 == NULL ) {
V_32 = - V_73 ;
F_17 ( V_28 L_21 ) ;
goto V_268;
}
V_1 = F_94 ( sizeof( struct V_1 ) , V_187 ) ;
if ( V_1 == NULL ) {
V_32 = - V_73 ;
F_17 ( V_28 L_22 ) ;
goto V_268;
}
F_124 ( & V_1 -> V_14 ) ;
F_125 ( & V_259 -> V_254 , V_1 ) ;
V_1 -> V_44 = V_259 -> V_254 . V_272 ;
V_1 -> V_133 = V_266 == V_273 ;
V_1 -> V_15 . V_274 = & V_275 ;
F_126 ( & V_1 -> V_15 . V_254 ) ;
F_127 ( & V_1 -> V_15 . V_254 , L_23 ) ;
V_1 -> V_15 . V_276 = 1 ;
V_1 -> V_15 . V_254 . V_277 = & V_259 -> V_254 ;
V_1 -> V_15 . V_254 . V_278 = V_259 -> V_254 . V_278 ;
V_1 -> V_15 . V_254 . V_279 = V_259 -> V_254 . V_279 ;
V_1 -> V_15 . V_280 = V_281 ;
F_128 ( & V_1 -> V_231 ) ;
V_1 -> V_231 . V_282 = F_86 ;
V_1 -> V_231 . V_283 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
#ifdef F_116
if ( V_1 -> V_44 -> V_45 ) {
snprintf ( V_262 , sizeof( V_262 ) , L_24 , V_259 -> V_284 ) ;
V_1 -> V_260 = F_129 ( & V_259 -> V_254 , V_262 ) ;
if ( F_130 ( V_1 -> V_260 ) ) {
F_131 ( & V_259 -> V_254 , L_25 ,
V_262 ) ;
V_32 = F_132 ( V_1 -> V_260 ) ;
goto V_268;
}
F_133 ( V_1 -> V_260 ) ;
}
#endif
F_12 ( V_1 ) ;
V_32 = F_134 ( V_214 , F_83 , V_285 | V_286 ,
V_281 , V_1 ) ;
if ( V_32 < 0 ) {
F_17 ( V_28 L_26 , V_32 ) ;
goto V_287;
}
F_14 ( & V_1 -> V_15 . V_288 ) ;
V_1 -> V_15 . V_186 = & V_1 -> V_21 [ 0 ] . V_21 ;
F_14 ( & V_1 -> V_15 . V_186 -> V_288 ) ;
for ( V_159 = 0 ; V_159 < V_27 ; V_159 ++ ) {
struct V_48 * V_21 = & V_1 -> V_21 [ V_159 ] ;
if ( V_159 != 0 ) {
F_14 ( & V_1 -> V_21 [ V_159 ] . V_21 . V_288 ) ;
F_97 ( & V_1 -> V_21 [ V_159 ] . V_21 . V_288 ,
& V_1 -> V_15 . V_288 ) ;
}
V_21 -> V_1 = V_1 ;
F_14 ( & V_21 -> V_22 ) ;
V_21 -> V_21 . V_280 = V_289 [ V_159 ] ;
V_21 -> V_21 . V_274 = & V_290 ;
V_21 -> V_21 . V_74 = 512 ;
}
V_1 -> V_21 [ 0 ] . V_21 . V_74 = 64 ;
V_1 -> V_21 [ 0 ] . V_4 = 0 ;
V_1 -> V_21 [ 0 ] . V_85 = V_86 ;
V_1 -> V_21 [ 0 ] . V_52 = V_87 ;
V_1 -> V_21 [ 0 ] . V_88 = V_89 ;
V_1 -> V_21 [ 0 ] . V_90 = 0 ;
V_1 -> V_21 [ 0 ] . V_81 = F_16 ( 0 ) ;
V_1 -> V_49 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_1 -> V_92 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_250 = V_1 ;
V_1 -> V_185 = F_93 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_187 ) ;
if ( V_1 -> V_185 == NULL )
goto V_291;
V_1 -> V_185 -> V_158 = F_119 ;
F_13 ( V_1 ) ;
F_135 ( & V_259 -> V_254 , L_27 , V_292 ) ;
return 0 ;
V_291:
F_114 ( V_214 , V_1 ) ;
V_287:
#ifdef F_116
if ( V_1 -> V_44 -> V_45 ) {
F_117 ( V_1 -> V_260 ) ;
F_118 ( V_1 -> V_260 ) ;
}
#endif
V_268:
if ( V_1 ) {
if ( V_1 -> V_185 )
F_95 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_1 -> V_185 ) ;
F_96 ( V_1 ) ;
}
if ( V_5 )
F_113 ( V_5 ) ;
return V_32 ;
}
static int T_6 F_136 ( void )
{
return F_137 ( & V_293 , F_120 ) ;
}
static void T_5 F_138 ( void )
{
F_139 ( & V_293 ) ;
}
