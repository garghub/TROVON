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
static inline T_1 F_4 ( struct V_11 * V_12 , T_1 V_13 )
{
return F_5 ( V_12 -> V_14 + V_13 ) ;
}
static inline void F_6 ( struct V_11 * V_12 ,
T_1 V_13 , T_1 V_15 )
{
F_7 ( V_15 , V_12 -> V_14 + V_13 ) ;
}
static void F_8 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 * V_15 , int V_16 )
{
for (; V_16 -- ; V_15 ++ , V_13 += 4 )
* V_15 = F_4 ( V_12 , V_13 ) ;
}
static void F_9 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 * V_15 , int V_16 )
{
for (; V_16 -- ; V_15 ++ , V_13 += 4 )
F_6 ( V_12 , V_13 , * V_15 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_6 ( V_12 , V_17 , V_18 ) ;
if ( F_4 ( V_12 , V_17 ) & V_18 )
V_12 -> V_19 |= V_20 ;
}
static struct V_11 * F_11 ( struct V_21 * V_22 )
{
struct V_11 * V_23 = NULL ;
struct V_11 * V_24 ;
F_12 ( & V_25 . V_26 ) ;
if ( ! V_22 -> V_12 ) {
F_13 (tmp, &atmel_aes.dev_list, list) {
V_23 = V_24 ;
break;
}
V_22 -> V_12 = V_23 ;
} else {
V_23 = V_22 -> V_12 ;
}
F_14 ( & V_25 . V_26 ) ;
return V_23 ;
}
static int F_15 ( struct V_11 * V_12 )
{
F_16 ( V_12 -> V_27 ) ;
if ( ! ( V_12 -> V_19 & V_28 ) ) {
F_6 ( V_12 , V_29 , V_30 ) ;
F_10 ( V_12 ) ;
V_12 -> V_19 |= V_28 ;
V_12 -> V_31 = 0 ;
}
return 0 ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_15 ( V_12 ) ;
V_12 -> V_32 = F_4 ( V_12 , V_33 ) ;
F_18 ( V_12 -> V_27 ) ;
}
static void F_19 ( struct V_11 * V_12 , int V_31 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_18 ( V_12 -> V_27 ) ;
V_12 -> V_19 &= ~ V_34 ;
V_2 -> V_35 . V_36 ( & V_2 -> V_35 , V_31 ) ;
}
static void F_20 ( void * V_37 )
{
struct V_11 * V_12 = V_37 ;
F_21 ( & V_12 -> V_38 ) ;
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_39 * V_40 , * V_41 ;
int V_42 , V_43 ;
V_12 -> V_44 = F_1 ( V_12 -> V_2 , V_12 -> V_45 ) ;
if ( ! V_12 -> V_44 )
goto V_46;
V_42 = F_23 ( V_12 -> V_47 , V_12 -> V_45 , V_12 -> V_44 ,
V_48 ) ;
if ( ! V_42 )
goto V_46;
V_40 = F_24 ( V_12 -> V_49 . V_50 , V_12 -> V_45 ,
V_42 , V_51 ,
V_52 | V_53 ) ;
if ( ! V_40 )
goto V_54;
V_12 -> V_55 = F_1 ( V_12 -> V_2 , V_12 -> V_56 ) ;
if ( ! V_12 -> V_55 )
goto V_54;
V_43 = F_23 ( V_12 -> V_47 , V_12 -> V_56 , V_12 -> V_55 ,
V_57 ) ;
if ( ! V_43 )
goto V_58;
V_41 = F_24 ( V_12 -> V_59 . V_50 , V_12 -> V_56 ,
V_43 , V_60 ,
V_52 | V_53 ) ;
if ( ! V_41 )
goto V_58;
V_41 -> V_61 = F_20 ;
V_41 -> V_62 = V_12 ;
V_12 -> V_5 -= V_12 -> V_2 -> V_6 ;
F_25 ( V_41 ) ;
F_26 ( V_12 -> V_59 . V_50 ) ;
F_25 ( V_40 ) ;
F_26 ( V_12 -> V_49 . V_50 ) ;
return 0 ;
V_58:
F_27 ( V_12 -> V_47 , V_12 -> V_56 , V_12 -> V_55 ,
V_57 ) ;
V_54:
F_27 ( V_12 -> V_47 , V_12 -> V_45 , V_12 -> V_44 ,
V_48 ) ;
V_46:
return - V_63 ;
}
static int F_28 ( struct V_11 * V_12 )
{
V_12 -> V_19 &= ~ V_64 ;
V_12 -> V_44 = F_1 ( V_12 -> V_2 , V_12 -> V_45 ) ;
if ( ! V_12 -> V_44 )
return - V_63 ;
V_12 -> V_55 = F_1 ( V_12 -> V_2 , V_12 -> V_56 ) ;
if ( ! V_12 -> V_55 )
return - V_63 ;
V_12 -> V_65 = F_29 ( V_12 -> V_45 , V_12 -> V_44 ,
V_12 -> V_66 , V_12 -> V_5 ) ;
if ( ! V_12 -> V_65 )
return - V_63 ;
V_12 -> V_5 -= V_12 -> V_65 ;
F_6 ( V_12 , V_67 , V_68 ) ;
F_9 ( V_12 , F_30 ( 0 ) , ( T_1 * ) V_12 -> V_66 ,
V_12 -> V_65 >> 2 ) ;
return 0 ;
}
static int F_31 ( struct V_11 * V_12 )
{
int V_31 ;
if ( V_12 -> V_19 & V_69 ) {
V_12 -> V_49 . V_70 . V_71 =
V_72 ;
V_12 -> V_59 . V_70 . V_73 =
V_72 ;
} else if ( V_12 -> V_19 & V_74 ) {
V_12 -> V_49 . V_70 . V_71 =
V_75 ;
V_12 -> V_59 . V_70 . V_73 =
V_75 ;
} else {
V_12 -> V_49 . V_70 . V_71 =
V_76 ;
V_12 -> V_59 . V_70 . V_73 =
V_76 ;
}
F_32 ( V_12 -> V_49 . V_50 , & V_12 -> V_49 . V_70 ) ;
F_32 ( V_12 -> V_59 . V_50 , & V_12 -> V_59 . V_70 ) ;
V_12 -> V_19 |= V_64 ;
V_31 = F_22 ( V_12 ) ;
return V_31 ;
}
static int F_33 ( struct V_11 * V_12 )
{
int V_31 ;
T_1 V_77 = 0 , V_78 = 0 ;
V_31 = F_15 ( V_12 ) ;
if ( V_31 )
return V_31 ;
if ( V_12 -> V_22 -> V_79 == V_80 )
V_78 |= V_81 ;
else if ( V_12 -> V_22 -> V_79 == V_82 )
V_78 |= V_83 ;
else
V_78 |= V_84 ;
if ( V_12 -> V_19 & V_85 ) {
V_78 |= V_86 ;
} else if ( V_12 -> V_19 & V_87 ) {
V_78 |= V_88 ;
if ( V_12 -> V_19 & V_69 )
V_78 |= V_89 ;
else if ( V_12 -> V_19 & V_74 )
V_78 |= V_90 ;
else if ( V_12 -> V_19 & V_91 )
V_78 |= V_92 ;
else if ( V_12 -> V_19 & V_93 )
V_78 |= V_94 ;
} else if ( V_12 -> V_19 & V_95 ) {
V_78 |= V_96 ;
} else if ( V_12 -> V_19 & V_97 ) {
V_78 |= V_98 ;
} else {
V_78 |= V_99 ;
}
if ( V_12 -> V_19 & V_100 )
V_78 |= V_101 ;
if ( V_12 -> V_5 > V_102 ) {
V_78 |= V_103 ;
if ( V_12 -> V_19 & V_20 )
V_78 |= V_18 ;
} else {
V_78 |= V_104 ;
}
F_6 ( V_12 , V_29 , V_77 ) ;
F_6 ( V_12 , V_17 , V_78 ) ;
F_9 ( V_12 , F_34 ( 0 ) , V_12 -> V_22 -> V_105 ,
V_12 -> V_22 -> V_79 >> 2 ) ;
if ( ( ( V_12 -> V_19 & V_85 ) || ( V_12 -> V_19 & V_87 ) ||
( V_12 -> V_19 & V_95 ) || ( V_12 -> V_19 & V_97 ) ) &&
V_12 -> V_2 -> V_106 ) {
F_9 ( V_12 , F_35 ( 0 ) , V_12 -> V_2 -> V_106 , 4 ) ;
}
return 0 ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_107 * V_108 , * V_109 ;
struct V_21 * V_22 ;
struct V_110 * V_111 ;
unsigned long V_19 ;
int V_31 , V_112 = 0 ;
F_37 ( & V_12 -> V_26 , V_19 ) ;
if ( V_2 )
V_112 = F_38 ( & V_12 -> V_113 , V_2 ) ;
if ( V_12 -> V_19 & V_34 ) {
F_39 ( & V_12 -> V_26 , V_19 ) ;
return V_112 ;
}
V_109 = F_40 ( & V_12 -> V_113 ) ;
V_108 = F_41 ( & V_12 -> V_113 ) ;
if ( V_108 )
V_12 -> V_19 |= V_34 ;
F_39 ( & V_12 -> V_26 , V_19 ) ;
if ( ! V_108 )
return V_112 ;
if ( V_109 )
V_109 -> V_36 ( V_109 , - V_114 ) ;
V_2 = F_42 ( V_108 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_5 = V_2 -> V_6 ;
V_12 -> V_45 = V_2 -> V_115 ;
V_12 -> V_56 = V_2 -> V_116 ;
V_111 = F_43 ( V_2 ) ;
V_22 = F_44 ( F_45 ( V_2 ) ) ;
V_111 -> V_117 &= V_118 ;
V_12 -> V_19 = ( V_12 -> V_19 & ~ V_118 ) | V_111 -> V_117 ;
V_12 -> V_22 = V_22 ;
V_22 -> V_12 = V_12 ;
V_31 = F_33 ( V_12 ) ;
if ( ! V_31 ) {
if ( V_12 -> V_5 > V_102 )
V_31 = F_31 ( V_12 ) ;
else
V_31 = F_28 ( V_12 ) ;
}
if ( V_31 ) {
F_19 ( V_12 , V_31 ) ;
F_21 ( & V_12 -> V_119 ) ;
}
return V_112 ;
}
static int F_46 ( struct V_11 * V_12 )
{
int V_31 = - V_63 ;
if ( V_12 -> V_19 & V_64 ) {
F_27 ( V_12 -> V_47 , V_12 -> V_56 ,
V_12 -> V_55 , V_57 ) ;
F_27 ( V_12 -> V_47 , V_12 -> V_45 ,
V_12 -> V_44 , V_48 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static int F_47 ( struct V_1 * V_2 , unsigned long V_117 )
{
struct V_21 * V_22 = F_44 (
F_45 ( V_2 ) ) ;
struct V_110 * V_111 = F_43 ( V_2 ) ;
struct V_11 * V_12 ;
if ( ! F_48 ( V_2 -> V_6 , V_120 ) ) {
F_49 ( L_1 ) ;
return - V_63 ;
}
V_12 = F_11 ( V_22 ) ;
if ( ! V_12 )
return - V_121 ;
V_111 -> V_117 = V_117 ;
return F_36 ( V_12 , V_2 ) ;
}
static bool F_50 ( struct V_122 * V_50 , void * V_123 )
{
struct V_124 * V_125 = V_123 ;
if ( V_125 && V_125 -> V_126 == V_50 -> V_127 -> V_47 ) {
V_50 -> V_128 = V_125 ;
return true ;
} else {
return false ;
}
}
static int F_51 ( struct V_11 * V_12 )
{
int V_31 = - V_129 ;
struct V_130 * V_131 ;
T_2 V_132 , V_133 ;
V_131 = V_12 -> V_47 -> V_134 ;
if ( V_131 && V_131 -> V_135 -> V_136 . V_126 &&
V_131 -> V_135 -> V_137 . V_126 ) {
F_52 ( V_132 ) ;
F_53 ( V_138 , V_132 ) ;
V_12 -> V_49 . V_50 = F_54 ( V_132 ,
F_50 , & V_131 -> V_135 -> V_137 ) ;
if ( ! V_12 -> V_49 . V_50 )
goto V_139;
V_12 -> V_49 . V_70 . V_140 = V_51 ;
V_12 -> V_49 . V_70 . V_141 = V_12 -> V_142 +
F_30 ( 0 ) ;
V_12 -> V_49 . V_70 . V_143 = 1 ;
V_12 -> V_49 . V_70 . V_144 = 1 ;
V_12 -> V_49 . V_70 . V_145 = false ;
F_52 ( V_133 ) ;
F_53 ( V_138 , V_133 ) ;
V_12 -> V_59 . V_50 = F_54 ( V_133 ,
F_50 , & V_131 -> V_135 -> V_136 ) ;
if ( ! V_12 -> V_59 . V_50 )
goto V_146;
V_12 -> V_59 . V_70 . V_140 = V_60 ;
V_12 -> V_59 . V_70 . V_147 = V_12 -> V_142 +
F_55 ( 0 ) ;
V_12 -> V_59 . V_70 . V_143 = 1 ;
V_12 -> V_59 . V_70 . V_144 = 1 ;
V_12 -> V_59 . V_70 . V_145 = false ;
return 0 ;
} else {
return - V_121 ;
}
V_146:
F_56 ( V_12 -> V_49 . V_50 ) ;
V_139:
return V_31 ;
}
static void F_57 ( struct V_11 * V_12 )
{
F_56 ( V_12 -> V_49 . V_50 ) ;
F_56 ( V_12 -> V_59 . V_50 ) ;
}
static int F_58 ( struct V_148 * V_149 , const T_3 * V_105 ,
unsigned int V_79 )
{
struct V_21 * V_22 = F_44 ( V_149 ) ;
if ( V_79 != V_80 && V_79 != V_82 &&
V_79 != V_150 ) {
F_59 ( V_149 , V_151 ) ;
return - V_63 ;
}
memcpy ( V_22 -> V_105 , V_105 , V_79 ) ;
V_22 -> V_79 = V_79 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
0 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_85 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_85 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_95 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_95 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_87 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_87 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_87 | V_93 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_87 | V_93 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_87 | V_91 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_87 | V_91 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_87 | V_74 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_87 | V_74 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_87 | V_69 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_87 | V_69 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_100 | V_97 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ,
V_97 ) ;
}
static int F_78 ( struct V_152 * V_149 )
{
V_149 -> V_153 . V_154 = sizeof( struct V_110 ) ;
return 0 ;
}
static void F_79 ( struct V_152 * V_149 )
{
}
static void F_80 ( unsigned long V_37 )
{
struct V_11 * V_12 = (struct V_11 * ) V_37 ;
F_36 ( V_12 , NULL ) ;
}
static void F_81 ( unsigned long V_37 )
{
struct V_11 * V_12 = (struct V_11 * ) V_37 ;
int V_31 ;
if ( ! ( V_12 -> V_19 & V_64 ) ) {
F_8 ( V_12 , F_55 ( 0 ) , ( T_1 * ) V_12 -> V_155 ,
V_12 -> V_65 >> 2 ) ;
if ( F_82 ( V_12 -> V_56 , V_12 -> V_55 ,
V_12 -> V_155 , V_12 -> V_65 ) )
V_31 = 0 ;
else
V_31 = - V_63 ;
goto V_156;
}
V_31 = F_46 ( V_12 ) ;
V_31 = V_12 -> V_31 ? : V_31 ;
if ( V_12 -> V_5 && ! V_31 ) {
V_31 = F_31 ( V_12 ) ;
if ( ! V_31 )
return;
}
V_156:
F_19 ( V_12 , V_31 ) ;
F_36 ( V_12 , NULL ) ;
}
static T_4 F_83 ( int V_157 , void * V_158 )
{
struct V_11 * V_23 = V_158 ;
T_1 V_159 ;
V_159 = F_4 ( V_23 , V_160 ) ;
if ( V_159 & F_4 ( V_23 , V_161 ) ) {
F_6 ( V_23 , V_162 , V_159 ) ;
if ( V_34 & V_23 -> V_19 )
F_21 ( & V_23 -> V_38 ) ;
else
F_84 ( V_23 -> V_47 , L_2 ) ;
return V_163 ;
}
return V_164 ;
}
static void F_85 ( struct V_11 * V_12 )
{
int V_165 ;
for ( V_165 = 0 ; V_165 < F_86 ( V_166 ) ; V_165 ++ )
F_87 ( & V_166 [ V_165 ] ) ;
if ( V_12 -> V_32 >= 0x130 )
F_87 ( & V_167 [ 0 ] ) ;
}
static int F_88 ( struct V_11 * V_12 )
{
int V_31 , V_165 , V_168 ;
for ( V_165 = 0 ; V_165 < F_86 ( V_166 ) ; V_165 ++ ) {
V_31 = F_89 ( & V_166 [ V_165 ] ) ;
if ( V_31 )
goto V_169;
}
F_17 ( V_12 ) ;
if ( V_12 -> V_32 >= 0x130 ) {
V_31 = F_89 ( & V_167 [ 0 ] ) ;
if ( V_31 )
goto V_170;
}
return 0 ;
V_170:
V_165 = F_86 ( V_166 ) ;
V_169:
for ( V_168 = 0 ; V_168 < V_165 ; V_168 ++ )
F_87 ( & V_166 [ V_168 ] ) ;
return V_31 ;
}
static int F_90 ( struct V_171 * V_172 )
{
struct V_11 * V_23 ;
struct V_130 * V_131 ;
struct V_127 * V_47 = & V_172 -> V_47 ;
struct V_173 * V_174 ;
unsigned long V_175 ;
int V_31 ;
V_131 = V_172 -> V_47 . V_134 ;
if ( ! V_131 ) {
V_31 = - V_176 ;
goto V_177;
}
V_23 = F_91 ( sizeof( struct V_11 ) , V_178 ) ;
if ( V_23 == NULL ) {
F_92 ( V_47 , L_3 ) ;
V_31 = - V_129 ;
goto V_177;
}
V_23 -> V_47 = V_47 ;
F_93 ( V_172 , V_23 ) ;
F_94 ( & V_23 -> V_179 ) ;
F_95 ( & V_23 -> V_38 , F_81 ,
( unsigned long ) V_23 ) ;
F_95 ( & V_23 -> V_119 , F_80 ,
( unsigned long ) V_23 ) ;
F_96 ( & V_23 -> V_113 , V_180 ) ;
V_23 -> V_157 = - 1 ;
V_174 = F_97 ( V_172 , V_181 , 0 ) ;
if ( ! V_174 ) {
F_92 ( V_47 , L_4 ) ;
V_31 = - V_121 ;
goto V_182;
}
V_23 -> V_142 = V_174 -> V_183 ;
V_175 = F_98 ( V_174 ) ;
V_23 -> V_157 = F_99 ( V_172 , 0 ) ;
if ( V_23 -> V_157 < 0 ) {
F_92 ( V_47 , L_5 ) ;
V_31 = V_23 -> V_157 ;
goto V_184;
}
V_31 = F_100 ( V_23 -> V_157 , F_83 , V_185 , L_6 ,
V_23 ) ;
if ( V_31 ) {
F_92 ( V_47 , L_7 ) ;
goto V_184;
}
V_23 -> V_27 = F_101 ( & V_172 -> V_47 , NULL ) ;
if ( F_102 ( V_23 -> V_27 ) ) {
F_92 ( V_47 , L_8 ) ;
V_31 = F_103 ( V_23 -> V_27 ) ;
goto V_186;
}
V_23 -> V_14 = F_104 ( V_23 -> V_142 , V_175 ) ;
if ( ! V_23 -> V_14 ) {
F_92 ( V_47 , L_9 ) ;
V_31 = - V_129 ;
goto V_187;
}
V_31 = F_51 ( V_23 ) ;
if ( V_31 )
goto V_188;
F_105 ( & V_25 . V_26 ) ;
F_106 ( & V_23 -> V_179 , & V_25 . V_189 ) ;
F_107 ( & V_25 . V_26 ) ;
V_31 = F_88 ( V_23 ) ;
if ( V_31 )
goto V_190;
F_108 ( V_47 , L_10 ) ;
return 0 ;
V_190:
F_105 ( & V_25 . V_26 ) ;
F_109 ( & V_23 -> V_179 ) ;
F_107 ( & V_25 . V_26 ) ;
F_57 ( V_23 ) ;
V_188:
F_110 ( V_23 -> V_14 ) ;
V_187:
F_111 ( V_23 -> V_27 ) ;
V_186:
F_112 ( V_23 -> V_157 , V_23 ) ;
V_184:
V_182:
F_113 ( & V_23 -> V_38 ) ;
F_113 ( & V_23 -> V_119 ) ;
F_114 ( V_23 ) ;
V_23 = NULL ;
V_177:
F_92 ( V_47 , L_11 ) ;
return V_31 ;
}
static int F_115 ( struct V_171 * V_172 )
{
static struct V_11 * V_23 ;
V_23 = F_116 ( V_172 ) ;
if ( ! V_23 )
return - V_121 ;
F_105 ( & V_25 . V_26 ) ;
F_109 ( & V_23 -> V_179 ) ;
F_107 ( & V_25 . V_26 ) ;
F_85 ( V_23 ) ;
F_113 ( & V_23 -> V_38 ) ;
F_113 ( & V_23 -> V_119 ) ;
F_57 ( V_23 ) ;
F_110 ( V_23 -> V_14 ) ;
F_111 ( V_23 -> V_27 ) ;
if ( V_23 -> V_157 > 0 )
F_112 ( V_23 -> V_157 , V_23 ) ;
F_114 ( V_23 ) ;
V_23 = NULL ;
return 0 ;
}
