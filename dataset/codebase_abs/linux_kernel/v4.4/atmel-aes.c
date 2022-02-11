static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_8 ;
struct V_3 * V_9 ;
V_7 = 0 ;
V_9 = V_4 ;
V_5 = V_2 -> V_6 ;
while ( V_5 ) {
V_8 = F_2 ( V_9 -> V_10 , V_5 ) ;
V_7 ++ ;
V_5 -= V_8 ;
V_9 = F_3 ( V_9 ) ;
if ( ! V_9 )
V_5 = 0 ;
}
return V_7 ;
}
static int F_4 ( struct V_3 * * V_4 , T_1 * V_11 ,
void * V_12 , T_1 V_13 , T_1 V_5 , int V_14 )
{
unsigned int V_15 , V_16 = 0 ;
while ( V_13 && V_5 ) {
V_15 = F_2 ( ( * V_4 ) -> V_10 - * V_11 , V_5 ) ;
V_15 = F_2 ( V_15 , V_13 ) ;
if ( ! V_15 )
return V_16 ;
F_5 ( V_12 + V_16 , * V_4 , * V_11 , V_15 , V_14 ) ;
V_16 += V_15 ;
V_13 -= V_15 ;
* V_11 += V_15 ;
V_5 -= V_15 ;
if ( * V_11 == ( * V_4 ) -> V_10 ) {
* V_4 = F_3 ( * V_4 ) ;
if ( * V_4 )
* V_11 = 0 ;
else
V_5 = 0 ;
}
}
return V_16 ;
}
static inline T_2 F_6 ( struct V_17 * V_18 , T_2 V_11 )
{
return F_7 ( V_18 -> V_19 + V_11 ) ;
}
static inline void F_8 ( struct V_17 * V_18 ,
T_2 V_11 , T_2 V_20 )
{
F_9 ( V_20 , V_18 -> V_19 + V_11 ) ;
}
static void F_10 ( struct V_17 * V_18 , T_2 V_11 ,
T_2 * V_20 , int V_15 )
{
for (; V_15 -- ; V_20 ++ , V_11 += 4 )
* V_20 = F_6 ( V_18 , V_11 ) ;
}
static void F_11 ( struct V_17 * V_18 , T_2 V_11 ,
T_2 * V_20 , int V_15 )
{
for (; V_15 -- ; V_20 ++ , V_11 += 4 )
F_8 ( V_18 , V_11 , * V_20 ) ;
}
static struct V_17 * F_12 ( struct V_21 * V_22 )
{
struct V_17 * V_23 = NULL ;
struct V_17 * V_24 ;
F_13 ( & V_25 . V_26 ) ;
if ( ! V_22 -> V_18 ) {
F_14 (tmp, &atmel_aes.dev_list, list) {
V_23 = V_24 ;
break;
}
V_22 -> V_18 = V_23 ;
} else {
V_23 = V_22 -> V_18 ;
}
F_15 ( & V_25 . V_26 ) ;
return V_23 ;
}
static int F_16 ( struct V_17 * V_18 )
{
int V_27 ;
V_27 = F_17 ( V_18 -> V_28 ) ;
if ( V_27 )
return V_27 ;
if ( ! ( V_18 -> V_29 & V_30 ) ) {
F_8 ( V_18 , V_31 , V_32 ) ;
F_8 ( V_18 , V_33 , 0xE << V_34 ) ;
V_18 -> V_29 |= V_30 ;
V_18 -> V_27 = 0 ;
}
return 0 ;
}
static inline unsigned int F_18 ( struct V_17 * V_18 )
{
return F_6 ( V_18 , V_35 ) & 0x00000fff ;
}
static void F_19 ( struct V_17 * V_18 )
{
F_16 ( V_18 ) ;
V_18 -> V_36 = F_18 ( V_18 ) ;
F_20 ( V_18 -> V_37 ,
L_1 , V_18 -> V_36 ) ;
F_21 ( V_18 -> V_28 ) ;
}
static void F_22 ( struct V_17 * V_18 , int V_27 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
F_21 ( V_18 -> V_28 ) ;
V_18 -> V_29 &= ~ V_38 ;
V_2 -> V_39 . V_40 ( & V_2 -> V_39 , V_27 ) ;
}
static void F_23 ( void * V_41 )
{
struct V_17 * V_18 = V_41 ;
F_24 ( & V_18 -> V_42 ) ;
}
static int F_25 ( struct V_17 * V_18 ,
T_3 V_43 , T_3 V_44 , int V_10 )
{
struct V_3 V_4 [ 2 ] ;
struct V_45 * V_46 , * V_47 ;
V_18 -> V_48 = V_10 ;
F_26 ( V_18 -> V_37 , V_43 , V_10 ,
V_49 ) ;
F_26 ( V_18 -> V_37 , V_44 , V_10 ,
V_50 ) ;
if ( V_18 -> V_29 & V_51 ) {
V_18 -> V_52 . V_53 . V_54 =
V_55 ;
V_18 -> V_56 . V_53 . V_57 =
V_55 ;
} else if ( V_18 -> V_29 & V_58 ) {
V_18 -> V_52 . V_53 . V_54 =
V_59 ;
V_18 -> V_56 . V_53 . V_57 =
V_59 ;
} else {
V_18 -> V_52 . V_53 . V_54 =
V_60 ;
V_18 -> V_56 . V_53 . V_57 =
V_60 ;
}
if ( V_18 -> V_29 & ( V_51 | V_58 |
V_61 | V_62 ) ) {
V_18 -> V_52 . V_53 . V_63 = 1 ;
V_18 -> V_52 . V_53 . V_64 = 1 ;
V_18 -> V_56 . V_53 . V_63 = 1 ;
V_18 -> V_56 . V_53 . V_64 = 1 ;
} else {
V_18 -> V_52 . V_53 . V_63 = V_18 -> V_65 . V_66 ;
V_18 -> V_52 . V_53 . V_64 = V_18 -> V_65 . V_66 ;
V_18 -> V_56 . V_53 . V_63 = V_18 -> V_65 . V_66 ;
V_18 -> V_56 . V_53 . V_64 = V_18 -> V_65 . V_66 ;
}
F_27 ( V_18 -> V_52 . V_67 , & V_18 -> V_52 . V_53 ) ;
F_27 ( V_18 -> V_56 . V_67 , & V_18 -> V_56 . V_53 ) ;
V_18 -> V_29 |= V_68 ;
F_28 ( & V_4 [ 0 ] , 1 ) ;
F_29 ( & V_4 [ 0 ] ) = V_43 ;
F_30 ( & V_4 [ 0 ] ) = V_10 ;
F_28 ( & V_4 [ 1 ] , 1 ) ;
F_29 ( & V_4 [ 1 ] ) = V_44 ;
F_30 ( & V_4 [ 1 ] ) = V_10 ;
V_46 = F_31 ( V_18 -> V_52 . V_67 , & V_4 [ 0 ] ,
1 , V_69 ,
V_70 | V_71 ) ;
if ( ! V_46 )
return - V_72 ;
V_47 = F_31 ( V_18 -> V_56 . V_67 , & V_4 [ 1 ] ,
1 , V_73 ,
V_70 | V_71 ) ;
if ( ! V_47 )
return - V_72 ;
V_47 -> V_74 = F_23 ;
V_47 -> V_75 = V_18 ;
F_32 ( V_47 ) ;
F_33 ( V_18 -> V_56 . V_67 ) ;
F_32 ( V_46 ) ;
F_33 ( V_18 -> V_52 . V_67 ) ;
return 0 ;
}
static int F_34 ( struct V_17 * V_18 )
{
V_18 -> V_29 &= ~ V_68 ;
F_35 ( V_18 -> V_37 , V_18 -> V_43 ,
V_18 -> V_48 , V_49 ) ;
F_35 ( V_18 -> V_37 , V_18 -> V_44 ,
V_18 -> V_48 , V_50 ) ;
V_18 -> V_76 = F_1 ( V_18 -> V_2 , V_18 -> V_77 ) ;
if ( ! V_18 -> V_76 )
return - V_72 ;
V_18 -> V_78 = F_1 ( V_18 -> V_2 , V_18 -> V_79 ) ;
if ( ! V_18 -> V_78 )
return - V_72 ;
V_18 -> V_80 = F_36 ( V_18 -> V_77 , V_18 -> V_76 ,
V_18 -> V_81 , V_18 -> V_5 ) ;
if ( ! V_18 -> V_80 )
return - V_72 ;
V_18 -> V_5 -= V_18 -> V_80 ;
F_8 ( V_18 , V_82 , V_83 ) ;
F_11 ( V_18 , F_37 ( 0 ) , ( T_2 * ) V_18 -> V_81 ,
V_18 -> V_80 >> 2 ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 )
{
int V_27 , V_84 = 0 , V_85 , V_14 ;
T_1 V_15 ;
T_3 V_86 , V_87 ;
if ( ( ! V_18 -> V_88 ) && ( ! V_18 -> V_89 ) ) {
V_85 = F_39 ( ( T_2 ) V_18 -> V_77 -> V_11 , sizeof( T_2 ) ) &&
F_39 ( V_18 -> V_77 -> V_10 , V_18 -> V_22 -> V_90 ) ;
V_14 = F_39 ( ( T_2 ) V_18 -> V_79 -> V_11 , sizeof( T_2 ) ) &&
F_39 ( V_18 -> V_79 -> V_10 , V_18 -> V_22 -> V_90 ) ;
V_84 = V_85 && V_14 ;
if ( F_30 ( V_18 -> V_77 ) != F_30 ( V_18 -> V_79 ) )
V_84 = 0 ;
}
if ( V_84 ) {
V_15 = F_2 ( V_18 -> V_5 , F_30 ( V_18 -> V_77 ) ) ;
V_15 = F_2 ( V_15 , F_30 ( V_18 -> V_79 ) ) ;
V_27 = F_40 ( V_18 -> V_37 , V_18 -> V_77 , 1 , V_49 ) ;
if ( ! V_27 ) {
F_41 ( V_18 -> V_37 , L_2 ) ;
return - V_72 ;
}
V_27 = F_40 ( V_18 -> V_37 , V_18 -> V_79 , 1 ,
V_50 ) ;
if ( ! V_27 ) {
F_41 ( V_18 -> V_37 , L_2 ) ;
F_42 ( V_18 -> V_37 , V_18 -> V_77 , 1 ,
V_49 ) ;
return - V_72 ;
}
V_86 = F_29 ( V_18 -> V_77 ) ;
V_87 = F_29 ( V_18 -> V_79 ) ;
V_18 -> V_29 |= V_91 ;
} else {
F_35 ( V_18 -> V_37 , V_18 -> V_43 ,
V_18 -> V_48 , V_49 ) ;
V_15 = F_4 ( & V_18 -> V_77 , & V_18 -> V_88 ,
V_18 -> V_81 , V_18 -> V_13 , V_18 -> V_5 , 0 ) ;
V_86 = V_18 -> V_43 ;
V_87 = V_18 -> V_44 ;
V_18 -> V_29 &= ~ V_91 ;
}
V_18 -> V_5 -= V_15 ;
V_27 = F_25 ( V_18 , V_86 , V_87 , V_15 ) ;
if ( V_27 && ( V_18 -> V_29 & V_91 ) ) {
F_42 ( V_18 -> V_37 , V_18 -> V_77 , 1 , V_49 ) ;
F_42 ( V_18 -> V_37 , V_18 -> V_79 , 1 , V_49 ) ;
}
return V_27 ;
}
static int F_43 ( struct V_17 * V_18 )
{
int V_27 ;
T_2 V_92 = 0 , V_93 = 0 ;
V_27 = F_16 ( V_18 ) ;
if ( V_27 )
return V_27 ;
if ( V_18 -> V_22 -> V_94 == V_95 )
V_93 |= V_96 ;
else if ( V_18 -> V_22 -> V_94 == V_97 )
V_93 |= V_98 ;
else
V_93 |= V_99 ;
if ( V_18 -> V_29 & V_100 ) {
V_93 |= V_101 ;
} else if ( V_18 -> V_29 & V_102 ) {
V_93 |= V_103 ;
if ( V_18 -> V_29 & V_51 )
V_93 |= V_104 ;
else if ( V_18 -> V_29 & V_58 )
V_93 |= V_105 ;
else if ( V_18 -> V_29 & V_61 )
V_93 |= V_106 ;
else if ( V_18 -> V_29 & V_62 )
V_93 |= V_107 ;
else if ( V_18 -> V_29 & V_108 )
V_93 |= V_109 ;
} else if ( V_18 -> V_29 & V_110 ) {
V_93 |= V_111 ;
} else if ( V_18 -> V_29 & V_112 ) {
V_93 |= V_113 ;
} else {
V_93 |= V_114 ;
}
if ( V_18 -> V_29 & V_115 )
V_93 |= V_116 ;
if ( V_18 -> V_5 > V_117 ) {
V_93 |= V_118 ;
if ( V_18 -> V_65 . V_119 )
V_93 |= V_120 ;
} else {
V_93 |= V_121 ;
}
F_8 ( V_18 , V_31 , V_92 ) ;
F_8 ( V_18 , V_33 , V_93 ) ;
F_11 ( V_18 , F_44 ( 0 ) , V_18 -> V_22 -> V_122 ,
V_18 -> V_22 -> V_94 >> 2 ) ;
if ( ( ( V_18 -> V_29 & V_100 ) || ( V_18 -> V_29 & V_102 ) ||
( V_18 -> V_29 & V_110 ) || ( V_18 -> V_29 & V_112 ) ) &&
V_18 -> V_2 -> V_123 ) {
F_11 ( V_18 , F_45 ( 0 ) , V_18 -> V_2 -> V_123 , 4 ) ;
}
return 0 ;
}
static int F_46 ( struct V_17 * V_18 ,
struct V_1 * V_2 )
{
struct V_124 * V_125 , * V_126 ;
struct V_21 * V_22 ;
struct V_127 * V_128 ;
unsigned long V_29 ;
int V_27 , V_129 = 0 ;
F_47 ( & V_18 -> V_26 , V_29 ) ;
if ( V_2 )
V_129 = F_48 ( & V_18 -> V_130 , V_2 ) ;
if ( V_18 -> V_29 & V_38 ) {
F_49 ( & V_18 -> V_26 , V_29 ) ;
return V_129 ;
}
V_126 = F_50 ( & V_18 -> V_130 ) ;
V_125 = F_51 ( & V_18 -> V_130 ) ;
if ( V_125 )
V_18 -> V_29 |= V_38 ;
F_49 ( & V_18 -> V_26 , V_29 ) ;
if ( ! V_125 )
return V_129 ;
if ( V_126 )
V_126 -> V_40 ( V_126 , - V_131 ) ;
V_2 = F_52 ( V_125 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_5 = V_2 -> V_6 ;
V_18 -> V_88 = 0 ;
V_18 -> V_77 = V_2 -> V_132 ;
V_18 -> V_89 = 0 ;
V_18 -> V_79 = V_2 -> V_133 ;
V_128 = F_53 ( V_2 ) ;
V_22 = F_54 ( F_55 ( V_2 ) ) ;
V_128 -> V_134 &= V_135 ;
V_18 -> V_29 = ( V_18 -> V_29 & ~ V_135 ) | V_128 -> V_134 ;
V_18 -> V_22 = V_22 ;
V_22 -> V_18 = V_18 ;
V_27 = F_43 ( V_18 ) ;
if ( ! V_27 ) {
if ( V_18 -> V_5 > V_117 )
V_27 = F_38 ( V_18 ) ;
else
V_27 = F_34 ( V_18 ) ;
}
if ( V_27 ) {
F_22 ( V_18 , V_27 ) ;
F_24 ( & V_18 -> V_136 ) ;
}
return V_129 ;
}
static int F_56 ( struct V_17 * V_18 )
{
int V_27 = - V_72 ;
T_1 V_15 ;
if ( V_18 -> V_29 & V_68 ) {
V_27 = 0 ;
if ( V_18 -> V_29 & V_91 ) {
F_42 ( V_18 -> V_37 , V_18 -> V_79 , 1 , V_50 ) ;
F_42 ( V_18 -> V_37 , V_18 -> V_77 , 1 , V_49 ) ;
} else {
F_35 ( V_18 -> V_37 , V_18 -> V_44 ,
V_18 -> V_48 , V_50 ) ;
V_15 = F_4 ( & V_18 -> V_79 , & V_18 -> V_89 ,
V_18 -> V_137 , V_18 -> V_13 , V_18 -> V_48 , 1 ) ;
if ( V_15 != V_18 -> V_48 ) {
V_27 = - V_72 ;
F_57 ( L_3 , V_15 ) ;
}
}
}
return V_27 ;
}
static int F_58 ( struct V_17 * V_18 )
{
int V_27 = - V_138 ;
V_18 -> V_81 = ( void * ) F_59 ( V_139 , 0 ) ;
V_18 -> V_137 = ( void * ) F_59 ( V_139 , 0 ) ;
V_18 -> V_13 = V_140 ;
V_18 -> V_13 &= ~ ( V_141 - 1 ) ;
if ( ! V_18 -> V_81 || ! V_18 -> V_137 ) {
F_41 ( V_18 -> V_37 , L_4 ) ;
goto V_142;
}
V_18 -> V_43 = F_60 ( V_18 -> V_37 , V_18 -> V_81 ,
V_18 -> V_13 , V_49 ) ;
if ( F_61 ( V_18 -> V_37 , V_18 -> V_43 ) ) {
F_41 ( V_18 -> V_37 , L_5 , V_18 -> V_13 ) ;
V_27 = - V_72 ;
goto V_143;
}
V_18 -> V_44 = F_60 ( V_18 -> V_37 , V_18 -> V_137 ,
V_18 -> V_13 , V_50 ) ;
if ( F_61 ( V_18 -> V_37 , V_18 -> V_44 ) ) {
F_41 ( V_18 -> V_37 , L_5 , V_18 -> V_13 ) ;
V_27 = - V_72 ;
goto V_144;
}
return 0 ;
V_144:
F_62 ( V_18 -> V_37 , V_18 -> V_43 , V_18 -> V_13 ,
V_49 ) ;
V_143:
V_142:
F_63 ( ( unsigned long ) V_18 -> V_137 ) ;
F_63 ( ( unsigned long ) V_18 -> V_81 ) ;
if ( V_27 )
F_57 ( L_6 , V_27 ) ;
return V_27 ;
}
static void F_64 ( struct V_17 * V_18 )
{
F_62 ( V_18 -> V_37 , V_18 -> V_44 , V_18 -> V_13 ,
V_50 ) ;
F_62 ( V_18 -> V_37 , V_18 -> V_43 , V_18 -> V_13 ,
V_49 ) ;
F_63 ( ( unsigned long ) V_18 -> V_137 ) ;
F_63 ( ( unsigned long ) V_18 -> V_81 ) ;
}
static int F_65 ( struct V_1 * V_2 , unsigned long V_134 )
{
struct V_21 * V_22 = F_54 (
F_55 ( V_2 ) ) ;
struct V_127 * V_128 = F_53 ( V_2 ) ;
struct V_17 * V_18 ;
if ( V_134 & V_51 ) {
if ( ! F_39 ( V_2 -> V_6 , V_145 ) ) {
F_57 ( L_7 ) ;
return - V_72 ;
}
V_22 -> V_90 = V_145 ;
} else if ( V_134 & V_58 ) {
if ( ! F_39 ( V_2 -> V_6 , V_146 ) ) {
F_57 ( L_8 ) ;
return - V_72 ;
}
V_22 -> V_90 = V_146 ;
} else if ( V_134 & V_61 ) {
if ( ! F_39 ( V_2 -> V_6 , V_147 ) ) {
F_57 ( L_9 ) ;
return - V_72 ;
}
V_22 -> V_90 = V_147 ;
} else if ( V_134 & V_62 ) {
if ( ! F_39 ( V_2 -> V_6 , V_148 ) ) {
F_57 ( L_10 ) ;
return - V_72 ;
}
V_22 -> V_90 = V_148 ;
} else {
if ( ! F_39 ( V_2 -> V_6 , V_141 ) ) {
F_57 ( L_11 ) ;
return - V_72 ;
}
V_22 -> V_90 = V_141 ;
}
V_18 = F_12 ( V_22 ) ;
if ( ! V_18 )
return - V_149 ;
V_128 -> V_134 = V_134 ;
return F_46 ( V_18 , V_2 ) ;
}
static bool F_66 ( struct V_150 * V_67 , void * V_151 )
{
struct V_152 * V_153 = V_151 ;
if ( V_153 && V_153 -> V_154 == V_67 -> V_155 -> V_37 ) {
V_67 -> V_156 = V_153 ;
return true ;
} else {
return false ;
}
}
static int F_67 ( struct V_17 * V_18 ,
struct V_157 * V_158 )
{
int V_27 = - V_138 ;
T_4 V_159 ;
F_68 ( V_159 ) ;
F_69 ( V_160 , V_159 ) ;
V_18 -> V_52 . V_67 = F_70 ( V_159 ,
F_66 , & V_158 -> V_161 -> V_162 , V_18 -> V_37 , L_12 ) ;
if ( ! V_18 -> V_52 . V_67 )
goto V_163;
V_18 -> V_52 . V_53 . V_164 = V_69 ;
V_18 -> V_52 . V_53 . V_165 = V_18 -> V_166 +
F_37 ( 0 ) ;
V_18 -> V_52 . V_53 . V_63 = V_18 -> V_65 . V_66 ;
V_18 -> V_52 . V_53 . V_57 =
V_60 ;
V_18 -> V_52 . V_53 . V_64 = V_18 -> V_65 . V_66 ;
V_18 -> V_52 . V_53 . V_54 =
V_60 ;
V_18 -> V_52 . V_53 . V_167 = false ;
V_18 -> V_56 . V_67 = F_70 ( V_159 ,
F_66 , & V_158 -> V_161 -> V_168 , V_18 -> V_37 , L_13 ) ;
if ( ! V_18 -> V_56 . V_67 )
goto V_169;
V_18 -> V_56 . V_53 . V_164 = V_73 ;
V_18 -> V_56 . V_53 . V_170 = V_18 -> V_166 +
F_71 ( 0 ) ;
V_18 -> V_56 . V_53 . V_63 = V_18 -> V_65 . V_66 ;
V_18 -> V_56 . V_53 . V_57 =
V_60 ;
V_18 -> V_56 . V_53 . V_64 = V_18 -> V_65 . V_66 ;
V_18 -> V_56 . V_53 . V_54 =
V_60 ;
V_18 -> V_56 . V_53 . V_167 = false ;
return 0 ;
V_169:
F_72 ( V_18 -> V_52 . V_67 ) ;
V_163:
F_73 ( V_18 -> V_37 , L_14 ) ;
return V_27 ;
}
static void F_74 ( struct V_17 * V_18 )
{
F_72 ( V_18 -> V_52 . V_67 ) ;
F_72 ( V_18 -> V_56 . V_67 ) ;
}
static int F_75 ( struct V_171 * V_172 , const T_5 * V_122 ,
unsigned int V_94 )
{
struct V_21 * V_22 = F_54 ( V_172 ) ;
if ( V_94 != V_95 && V_94 != V_97 &&
V_94 != V_173 ) {
F_76 ( V_172 , V_174 ) ;
return - V_72 ;
}
memcpy ( V_22 -> V_122 , V_122 , V_94 ) ;
V_22 -> V_94 = V_94 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
0 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_100 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_100 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_110 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_110 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_102 | V_108 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_102 | V_108 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_102 | V_62 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_102 | V_62 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_102 | V_61 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_102 | V_61 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_102 | V_58 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_102 | V_58 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_102 | V_51 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_102 | V_51 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_115 | V_112 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
return F_65 ( V_2 ,
V_112 ) ;
}
static int F_95 ( struct V_175 * V_172 )
{
V_172 -> V_176 . V_177 = sizeof( struct V_127 ) ;
return 0 ;
}
static void F_96 ( struct V_175 * V_172 )
{
}
static void F_97 ( unsigned long V_41 )
{
struct V_17 * V_18 = (struct V_17 * ) V_41 ;
F_46 ( V_18 , NULL ) ;
}
static void F_98 ( unsigned long V_41 )
{
struct V_17 * V_18 = (struct V_17 * ) V_41 ;
int V_27 ;
if ( ! ( V_18 -> V_29 & V_68 ) ) {
F_10 ( V_18 , F_71 ( 0 ) , ( T_2 * ) V_18 -> V_137 ,
V_18 -> V_80 >> 2 ) ;
if ( F_99 ( V_18 -> V_79 , V_18 -> V_78 ,
V_18 -> V_137 , V_18 -> V_80 ) )
V_27 = 0 ;
else
V_27 = - V_72 ;
goto V_178;
}
V_27 = F_56 ( V_18 ) ;
V_27 = V_18 -> V_27 ? : V_27 ;
if ( V_18 -> V_5 && ! V_27 ) {
if ( V_18 -> V_29 & V_91 ) {
V_18 -> V_77 = F_3 ( V_18 -> V_77 ) ;
V_18 -> V_79 = F_3 ( V_18 -> V_79 ) ;
if ( ! V_18 -> V_77 || ! V_18 -> V_79 )
V_27 = - V_72 ;
}
if ( ! V_27 )
V_27 = F_38 ( V_18 ) ;
if ( ! V_27 )
return;
}
V_178:
F_22 ( V_18 , V_27 ) ;
F_46 ( V_18 , NULL ) ;
}
static T_6 F_100 ( int V_179 , void * V_180 )
{
struct V_17 * V_23 = V_180 ;
T_2 V_181 ;
V_181 = F_6 ( V_23 , V_182 ) ;
if ( V_181 & F_6 ( V_23 , V_183 ) ) {
F_8 ( V_23 , V_184 , V_181 ) ;
if ( V_38 & V_23 -> V_29 )
F_24 ( & V_23 -> V_42 ) ;
else
F_73 ( V_23 -> V_37 , L_15 ) ;
return V_185 ;
}
return V_186 ;
}
static void F_101 ( struct V_17 * V_18 )
{
int V_187 ;
for ( V_187 = 0 ; V_187 < F_102 ( V_188 ) ; V_187 ++ )
F_103 ( & V_188 [ V_187 ] ) ;
if ( V_18 -> V_65 . V_189 )
F_103 ( & V_190 ) ;
}
static int F_104 ( struct V_17 * V_18 )
{
int V_27 , V_187 , V_191 ;
for ( V_187 = 0 ; V_187 < F_102 ( V_188 ) ; V_187 ++ ) {
V_27 = F_105 ( & V_188 [ V_187 ] ) ;
if ( V_27 )
goto V_192;
}
if ( V_18 -> V_65 . V_189 ) {
V_27 = F_105 ( & V_190 ) ;
if ( V_27 )
goto V_193;
}
return 0 ;
V_193:
V_187 = F_102 ( V_188 ) ;
V_192:
for ( V_191 = 0 ; V_191 < V_187 ; V_191 ++ )
F_103 ( & V_188 [ V_191 ] ) ;
return V_27 ;
}
static void F_106 ( struct V_17 * V_18 )
{
V_18 -> V_65 . V_119 = 0 ;
V_18 -> V_65 . V_189 = 0 ;
V_18 -> V_65 . V_66 = 1 ;
switch ( V_18 -> V_36 & 0xff0 ) {
case 0x200 :
V_18 -> V_65 . V_119 = 1 ;
V_18 -> V_65 . V_189 = 1 ;
V_18 -> V_65 . V_66 = 4 ;
break;
case 0x130 :
V_18 -> V_65 . V_119 = 1 ;
V_18 -> V_65 . V_189 = 1 ;
V_18 -> V_65 . V_66 = 4 ;
break;
case 0x120 :
break;
default:
F_73 ( V_18 -> V_37 ,
L_16 ) ;
break;
}
}
static struct V_157 * F_107 ( struct V_194 * V_195 )
{
struct V_196 * V_197 = V_195 -> V_37 . V_198 ;
struct V_157 * V_158 ;
if ( ! V_197 ) {
F_41 ( & V_195 -> V_37 , L_17 ) ;
return F_108 ( - V_72 ) ;
}
V_158 = F_109 ( & V_195 -> V_37 , sizeof( * V_158 ) , V_139 ) ;
if ( ! V_158 ) {
F_41 ( & V_195 -> V_37 , L_18 ) ;
return F_108 ( - V_138 ) ;
}
V_158 -> V_161 = F_109 ( & V_195 -> V_37 ,
sizeof( * ( V_158 -> V_161 ) ) ,
V_139 ) ;
if ( ! V_158 -> V_161 ) {
F_41 ( & V_195 -> V_37 , L_19 ) ;
F_110 ( & V_195 -> V_37 , V_158 ) ;
return F_108 ( - V_138 ) ;
}
return V_158 ;
}
static inline struct V_157 * F_107 ( struct V_194 * V_195 )
{
return F_108 ( - V_72 ) ;
}
static int F_111 ( struct V_194 * V_195 )
{
struct V_17 * V_23 ;
struct V_157 * V_158 ;
struct V_155 * V_37 = & V_195 -> V_37 ;
struct V_199 * V_200 ;
int V_27 ;
V_158 = V_195 -> V_37 . V_201 ;
if ( ! V_158 ) {
V_158 = F_107 ( V_195 ) ;
if ( F_112 ( V_158 ) ) {
V_27 = F_113 ( V_158 ) ;
goto V_202;
}
}
if ( ! V_158 -> V_161 ) {
V_27 = - V_203 ;
goto V_202;
}
V_23 = F_109 ( & V_195 -> V_37 , sizeof( * V_23 ) , V_139 ) ;
if ( V_23 == NULL ) {
F_41 ( V_37 , L_20 ) ;
V_27 = - V_138 ;
goto V_202;
}
V_23 -> V_37 = V_37 ;
F_114 ( V_195 , V_23 ) ;
F_115 ( & V_23 -> V_204 ) ;
F_116 ( & V_23 -> V_26 ) ;
F_117 ( & V_23 -> V_42 , F_98 ,
( unsigned long ) V_23 ) ;
F_117 ( & V_23 -> V_136 , F_97 ,
( unsigned long ) V_23 ) ;
F_118 ( & V_23 -> V_130 , V_205 ) ;
V_23 -> V_179 = - 1 ;
V_200 = F_119 ( V_195 , V_206 , 0 ) ;
if ( ! V_200 ) {
F_41 ( V_37 , L_21 ) ;
V_27 = - V_149 ;
goto V_207;
}
V_23 -> V_166 = V_200 -> V_208 ;
V_23 -> V_179 = F_120 ( V_195 , 0 ) ;
if ( V_23 -> V_179 < 0 ) {
F_41 ( V_37 , L_22 ) ;
V_27 = V_23 -> V_179 ;
goto V_207;
}
V_27 = F_121 ( & V_195 -> V_37 , V_23 -> V_179 , F_100 ,
V_209 , L_23 , V_23 ) ;
if ( V_27 ) {
F_41 ( V_37 , L_24 ) ;
goto V_207;
}
V_23 -> V_28 = F_122 ( & V_195 -> V_37 , L_25 ) ;
if ( F_112 ( V_23 -> V_28 ) ) {
F_41 ( V_37 , L_26 ) ;
V_27 = F_113 ( V_23 -> V_28 ) ;
goto V_207;
}
V_23 -> V_19 = F_123 ( & V_195 -> V_37 , V_200 ) ;
if ( ! V_23 -> V_19 ) {
F_41 ( V_37 , L_27 ) ;
V_27 = - V_138 ;
goto V_207;
}
F_19 ( V_23 ) ;
F_106 ( V_23 ) ;
V_27 = F_58 ( V_23 ) ;
if ( V_27 )
goto V_210;
V_27 = F_67 ( V_23 , V_158 ) ;
if ( V_27 )
goto V_211;
F_124 ( & V_25 . V_26 ) ;
F_125 ( & V_23 -> V_204 , & V_25 . V_212 ) ;
F_126 ( & V_25 . V_26 ) ;
V_27 = F_104 ( V_23 ) ;
if ( V_27 )
goto V_213;
F_20 ( V_37 , L_28 ,
F_127 ( V_23 -> V_52 . V_67 ) ,
F_127 ( V_23 -> V_56 . V_67 ) ) ;
return 0 ;
V_213:
F_124 ( & V_25 . V_26 ) ;
F_128 ( & V_23 -> V_204 ) ;
F_126 ( & V_25 . V_26 ) ;
F_74 ( V_23 ) ;
V_211:
F_64 ( V_23 ) ;
V_210:
V_207:
F_129 ( & V_23 -> V_42 ) ;
F_129 ( & V_23 -> V_136 ) ;
V_202:
F_41 ( V_37 , L_29 ) ;
return V_27 ;
}
static int F_130 ( struct V_194 * V_195 )
{
static struct V_17 * V_23 ;
V_23 = F_131 ( V_195 ) ;
if ( ! V_23 )
return - V_149 ;
F_124 ( & V_25 . V_26 ) ;
F_128 ( & V_23 -> V_204 ) ;
F_126 ( & V_25 . V_26 ) ;
F_101 ( V_23 ) ;
F_129 ( & V_23 -> V_42 ) ;
F_129 ( & V_23 -> V_136 ) ;
F_74 ( V_23 ) ;
return 0 ;
}
