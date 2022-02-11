int F_1 ( void T_1 * V_1 , int V_2 , T_2 * V_3 )
{
if ( ( V_4 ) V_1 & ( V_2 - 1 ) ) {
* V_3 = 0 ;
return V_5 ;
}
if ( V_2 == 4 )
* V_3 = F_2 ( V_1 ) ;
else if ( V_2 == 2 )
* V_3 = F_3 ( V_1 ) ;
else if ( V_2 == 1 )
* V_3 = F_4 ( V_1 ) ;
else {
* V_3 = 0 ;
return V_5 ;
}
return V_6 ;
}
int F_5 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
if ( ( V_4 ) V_1 & ( V_2 - 1 ) )
return V_5 ;
if ( V_2 == 4 )
F_6 ( V_3 , V_1 ) ;
else if ( V_2 == 2 )
F_7 ( V_3 , V_1 ) ;
else if ( V_2 == 1 )
F_8 ( V_3 , V_1 ) ;
else
return V_5 ;
return V_6 ;
}
static inline void F_9 ( struct V_7 * V_8 , T_2 V_9 , T_2 * V_3 )
{
if ( V_8 -> V_10 -> V_11 )
V_8 -> V_10 -> V_11 ( V_8 , V_8 -> V_12 + V_9 , V_3 ) ;
else
* V_3 = F_2 ( V_8 -> V_12 + V_9 ) ;
}
static inline void F_10 ( struct V_7 * V_8 , T_2 V_3 , T_2 V_9 )
{
if ( V_8 -> V_10 -> V_13 )
V_8 -> V_10 -> V_13 ( V_8 , V_3 , V_8 -> V_12 + V_9 ) ;
else
F_6 ( V_3 , V_8 -> V_12 + V_9 ) ;
}
static int F_11 ( struct V_7 * V_8 , int V_14 , int V_2 ,
T_2 * V_3 )
{
if ( V_8 -> V_10 -> V_15 )
return V_8 -> V_10 -> V_15 ( V_8 , V_14 , V_2 , V_3 ) ;
return F_1 ( V_8 -> V_12 + V_14 , V_2 , V_3 ) ;
}
static int F_12 ( struct V_7 * V_8 , int V_14 , int V_2 ,
T_2 V_3 )
{
if ( V_8 -> V_10 -> V_16 )
return V_8 -> V_10 -> V_16 ( V_8 , V_14 , V_2 , V_3 ) ;
return F_5 ( V_8 -> V_12 + V_14 , V_2 , V_3 ) ;
}
static void F_13 ( struct V_7 * V_8 , int V_17 ,
int type , T_3 V_18 , T_3 V_19 , T_2 V_2 )
{
T_2 V_3 ;
F_10 ( V_8 , V_20 | V_17 ,
V_21 ) ;
F_10 ( V_8 , F_14 ( V_18 ) , V_22 ) ;
F_10 ( V_8 , F_15 ( V_18 ) , V_23 ) ;
F_10 ( V_8 , F_14 ( V_18 + V_2 - 1 ) ,
V_24 ) ;
F_10 ( V_8 , F_14 ( V_19 ) , V_25 ) ;
F_10 ( V_8 , F_15 ( V_19 ) , V_26 ) ;
F_10 ( V_8 , type , V_27 ) ;
F_10 ( V_8 , V_28 , V_29 ) ;
F_9 ( V_8 , V_29 , & V_3 ) ;
}
T_4 F_16 ( struct V_7 * V_8 )
{
unsigned long V_3 ;
int V_30 , V_31 , V_32 ;
T_4 V_33 = V_34 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
F_11 ( V_8 , V_36 + V_30 * 12 , 4 ,
( T_2 * ) & V_3 ) ;
if ( V_3 ) {
V_33 = V_37 ;
V_31 = 0 ;
while ( ( V_31 = F_17 ( & V_3 , 32 , V_31 ) ) != 32 ) {
V_32 = F_18 ( V_8 -> V_38 ,
V_30 * 32 + V_31 ) ;
F_12 ( V_8 ,
V_36 + V_30 * 12 ,
4 , 1 << V_31 ) ;
F_19 ( V_32 ) ;
V_31 ++ ;
}
}
}
return V_33 ;
}
void F_20 ( struct V_7 * V_8 )
{
T_3 V_39 ;
V_8 -> V_40 = F_21 ( V_41 , 0 ) ;
V_39 = F_22 ( ( void * ) V_8 -> V_40 ) ;
F_12 ( V_8 , V_42 , 4 ,
( T_2 ) ( V_39 & 0xffffffff ) ) ;
F_12 ( V_8 , V_43 , 4 ,
( T_2 ) ( V_39 >> 32 & 0xffffffff ) ) ;
}
static void F_23 ( struct V_7 * V_8 , int V_32 )
{
unsigned int V_44 , V_45 , V_3 ;
V_44 = ( V_32 / 32 ) * 12 ;
V_45 = V_32 % 32 ;
F_11 ( V_8 , V_46 + V_44 , 4 , & V_3 ) ;
V_3 &= ~ ( 1 << V_45 ) ;
F_12 ( V_8 , V_46 + V_44 , 4 , V_3 ) ;
}
static void F_24 ( struct V_7 * V_8 , unsigned int V_47 ,
unsigned int V_48 , unsigned int V_31 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_48 ; V_30 ++ ) {
F_25 ( V_47 , V_30 , NULL ) ;
if ( V_8 -> V_10 -> V_49 )
V_8 -> V_10 -> V_49 ( V_8 , V_31 + V_30 ) ;
else
F_23 ( V_8 , V_31 + V_30 ) ;
}
F_26 ( V_8 -> V_50 , V_31 , F_27 ( V_48 ) ) ;
}
static void F_28 ( struct V_7 * V_8 , int V_32 )
{
unsigned int V_44 , V_45 , V_3 ;
V_44 = ( V_32 / 32 ) * 12 ;
V_45 = V_32 % 32 ;
F_11 ( V_8 , V_46 + V_44 , 4 , & V_3 ) ;
V_3 |= 1 << V_45 ;
F_12 ( V_8 , V_46 + V_44 , 4 , V_3 ) ;
}
static int F_29 ( int V_51 , struct V_52 * V_53 , int * V_31 )
{
int V_32 , V_54 , V_30 ;
struct V_7 * V_8 = (struct V_7 * ) F_30 ( V_53 ) ;
V_54 = F_31 ( V_8 -> V_50 , V_55 ,
F_27 ( V_51 ) ) ;
if ( V_54 < 0 )
goto V_56;
V_32 = F_18 ( V_8 -> V_38 , V_54 ) ;
if ( ! V_32 )
goto V_56;
for ( V_30 = 0 ; V_30 < V_51 ; V_30 ++ ) {
if ( F_25 ( V_32 , V_30 , V_53 ) != 0 ) {
F_24 ( V_8 , V_32 , V_30 , V_54 ) ;
goto V_56;
}
if ( V_8 -> V_10 -> V_57 )
V_8 -> V_10 -> V_57 ( V_8 , V_54 + V_30 ) ;
else
F_28 ( V_8 , V_54 + V_30 ) ;
}
* V_31 = V_54 ;
V_53 -> V_58 = V_51 ;
V_53 -> V_59 . V_60 = F_27 ( V_51 ) ;
return V_32 ;
V_56:
* V_31 = V_54 ;
return - V_61 ;
}
static void F_32 ( struct V_7 * V_8 , unsigned int V_32 , T_2 V_31 )
{
struct V_62 V_63 ;
T_3 V_39 ;
if ( V_8 -> V_10 -> V_64 )
V_39 = V_8 -> V_10 -> V_64 ( V_8 ) ;
else
V_39 = F_22 ( ( void * ) V_8 -> V_40 ) ;
V_63 . V_65 = ( T_2 ) ( V_39 & 0xffffffff ) ;
V_63 . V_66 = ( T_2 ) ( V_39 >> 32 & 0xffffffff ) ;
if ( V_8 -> V_10 -> V_67 )
V_63 . V_68 = V_8 -> V_10 -> V_67 ( V_8 , V_31 ) ;
else
V_63 . V_68 = V_31 ;
F_33 ( V_32 , & V_63 ) ;
}
static int F_34 ( struct V_69 * V_70 , struct V_71 * V_72 ,
struct V_52 * V_53 )
{
int V_32 , V_31 ;
struct V_7 * V_8 = V_72 -> V_73 -> V_74 ;
if ( V_53 -> V_59 . V_75 )
return - V_76 ;
V_32 = F_29 ( 1 , V_53 , & V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
F_32 ( V_8 , V_32 , V_31 ) ;
return 0 ;
}
static int F_35 ( struct V_69 * V_70 , struct V_71 * V_72 ,
int V_48 , int type )
{
#ifdef F_36
int V_32 , V_31 ;
struct V_52 * V_53 ;
struct V_7 * V_8 = V_72 -> V_73 -> V_74 ;
if ( type == V_77 )
return - V_76 ;
F_37 ( ! F_38 ( & V_72 -> V_78 . V_79 ) ) ;
V_53 = F_39 ( V_72 -> V_78 . V_79 . V_80 , struct V_52 , V_81 ) ;
V_32 = F_29 ( V_48 , V_53 , & V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
F_32 ( V_8 , V_32 , V_31 ) ;
return 0 ;
#else
return - V_76 ;
#endif
}
static void F_40 ( struct V_69 * V_70 , unsigned int V_32 )
{
struct V_82 * V_68 = F_41 ( V_32 ) ;
struct V_52 * V_83 = F_42 ( V_68 ) ;
struct V_7 * V_8 = (struct V_7 * ) F_30 ( V_83 ) ;
F_24 ( V_8 , V_32 , 1 , V_68 -> V_84 ) ;
}
int F_43 ( struct V_7 * V_8 )
{
if ( V_8 -> V_10 -> V_85 )
return V_8 -> V_10 -> V_85 ( V_8 ) ;
return 0 ;
}
static int F_44 ( struct V_38 * V_86 , unsigned int V_32 ,
T_5 V_84 )
{
F_45 ( V_32 , & V_87 , V_88 ) ;
F_46 ( V_32 , V_86 -> V_89 ) ;
return 0 ;
}
int F_47 ( struct V_7 * V_8 )
{
struct V_90 * V_91 = V_8 -> V_78 -> V_92 ;
struct V_93 * V_72 = F_48 ( V_8 -> V_78 ) ;
struct V_94 * V_73 , * V_95 ;
struct V_96 * V_97 ;
T_2 V_3 ;
int V_30 , V_33 ;
F_49 ( V_44 ) ;
struct V_98 * V_99 ;
V_97 = F_50 ( V_72 , V_100 , L_1 ) ;
if ( V_97 ) {
V_8 -> V_101 = F_51 ( V_97 ) / 2 ;
V_8 -> V_102 = F_51 ( V_97 ) / 2 ;
V_8 -> V_103 = V_97 -> V_104 ;
V_8 -> V_105 = V_97 -> V_104 + V_8 -> V_101 ;
} else if ( ! V_8 -> V_106 ) {
F_52 ( V_8 -> V_78 , L_2 ) ;
}
V_33 = F_53 ( V_91 , 0 , 0xff , & V_44 , & V_8 -> V_107 ) ;
if ( V_33 )
return V_33 ;
F_54 (win, &res) {
switch ( F_55 ( V_99 -> V_44 ) ) {
case V_108 :
V_8 -> V_109 = V_99 -> V_44 ;
V_8 -> V_109 -> V_110 = L_3 ;
V_8 -> V_111 = F_51 ( V_8 -> V_109 ) ;
V_8 -> V_112 = V_8 -> V_109 -> V_104 - V_99 -> V_113 ;
V_33 = F_56 ( V_8 -> V_109 , V_8 -> V_107 ) ;
if ( V_33 ) {
F_57 ( V_8 -> V_78 , L_4 ,
V_33 , V_8 -> V_109 ) ;
continue;
}
break;
case V_100 :
V_8 -> V_114 = V_99 -> V_44 ;
V_8 -> V_114 -> V_110 = L_5 ;
V_8 -> V_115 = F_51 ( V_8 -> V_114 ) ;
V_8 -> V_116 = V_8 -> V_114 -> V_104 - V_99 -> V_113 ;
break;
case 0 :
V_8 -> V_117 = V_99 -> V_44 ;
V_8 -> V_101 = F_51 ( V_8 -> V_117 ) / 2 ;
V_8 -> V_102 = F_51 ( V_8 -> V_117 ) / 2 ;
V_8 -> V_103 = V_8 -> V_117 -> V_104 ;
V_8 -> V_105 = V_8 -> V_117 -> V_104 + V_8 -> V_101 ;
break;
case V_118 :
V_8 -> V_119 = V_99 -> V_44 ;
break;
default:
continue;
}
}
if ( ! V_8 -> V_12 ) {
V_8 -> V_12 = F_58 ( V_8 -> V_78 , V_8 -> V_117 -> V_104 ,
F_51 ( V_8 -> V_117 ) ) ;
if ( ! V_8 -> V_12 ) {
F_52 ( V_8 -> V_78 , L_6 ) ;
return - V_120 ;
}
}
V_8 -> V_121 = V_8 -> V_114 -> V_104 ;
if ( ! V_8 -> V_106 ) {
V_8 -> V_106 = F_58 ( V_8 -> V_78 , V_8 -> V_103 ,
V_8 -> V_101 ) ;
if ( ! V_8 -> V_106 ) {
F_52 ( V_8 -> V_78 , L_7 ) ;
return - V_120 ;
}
}
if ( ! V_8 -> V_122 ) {
V_8 -> V_122 = F_58 ( V_8 -> V_78 , V_8 -> V_105 ,
V_8 -> V_102 ) ;
if ( ! V_8 -> V_122 ) {
F_52 ( V_8 -> V_78 , L_6 ) ;
return - V_120 ;
}
}
V_33 = F_59 ( V_91 , L_8 , & V_8 -> V_123 ) ;
if ( V_33 )
V_8 -> V_123 = 0 ;
if ( F_60 ( F_36 ) ) {
if ( ! V_8 -> V_10 -> V_124 ) {
V_8 -> V_38 = F_61 ( V_8 -> V_78 -> V_92 ,
V_55 , & V_125 ,
& V_126 ) ;
if ( ! V_8 -> V_38 ) {
F_52 ( V_8 -> V_78 , L_9 ) ;
return - V_127 ;
}
for ( V_30 = 0 ; V_30 < V_55 ; V_30 ++ )
F_62 ( V_8 -> V_38 , V_30 ) ;
} else {
V_33 = V_8 -> V_10 -> V_124 ( V_8 , & V_126 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
if ( V_8 -> V_10 -> V_128 )
V_8 -> V_10 -> V_128 ( V_8 ) ;
if ( ! V_8 -> V_10 -> V_129 )
F_13 ( V_8 , V_130 ,
V_131 , V_8 -> V_121 ,
V_8 -> V_116 , V_8 -> V_115 ) ;
F_12 ( V_8 , V_132 , 4 , 0 ) ;
F_12 ( V_8 , V_133 , 2 , V_134 ) ;
F_11 ( V_8 , V_135 , 4 , & V_3 ) ;
V_3 |= V_136 ;
F_12 ( V_8 , V_135 , 4 , V_3 ) ;
V_8 -> V_137 = V_8 -> V_119 -> V_104 ;
if ( F_60 ( F_36 ) ) {
V_73 = F_63 ( V_8 -> V_78 , V_8 -> V_137 ,
& V_138 , V_8 , & V_44 ,
& V_126 ) ;
V_126 . V_78 = V_8 -> V_78 ;
} else
V_73 = F_64 ( V_8 -> V_78 , V_8 -> V_137 , & V_138 ,
V_8 , & V_44 ) ;
if ( ! V_73 )
return - V_120 ;
if ( V_8 -> V_10 -> V_139 )
V_8 -> V_10 -> V_139 ( V_8 ) ;
#ifdef F_65
F_66 ( V_140 , V_141 ) ;
#endif
if ( ! F_67 ( V_142 ) ) {
F_68 ( V_73 ) ;
F_69 ( V_73 ) ;
F_70 (child, &bus->children, node)
F_71 ( V_95 ) ;
}
F_72 ( V_73 ) ;
return 0 ;
}
static int F_73 ( struct V_7 * V_8 , struct V_94 * V_73 ,
T_2 V_143 , int V_14 , int V_2 , T_2 * V_3 )
{
int V_33 , type ;
T_2 V_144 , V_145 ;
T_3 V_18 ;
void T_1 * V_146 ;
if ( V_8 -> V_10 -> V_129 )
return V_8 -> V_10 -> V_129 ( V_8 , V_73 , V_143 , V_14 , V_2 , V_3 ) ;
V_144 = F_74 ( V_73 -> V_147 ) | F_75 ( F_76 ( V_143 ) ) |
F_77 ( F_78 ( V_143 ) ) ;
if ( V_73 -> V_148 -> V_147 == V_8 -> V_137 ) {
type = V_149 ;
V_18 = V_8 -> V_103 ;
V_145 = V_8 -> V_101 ;
V_146 = V_8 -> V_106 ;
} else {
type = V_150 ;
V_18 = V_8 -> V_105 ;
V_145 = V_8 -> V_102 ;
V_146 = V_8 -> V_122 ;
}
F_13 ( V_8 , V_151 ,
type , V_18 ,
V_144 , V_145 ) ;
V_33 = F_1 ( V_146 + V_14 , V_2 , V_3 ) ;
F_13 ( V_8 , V_151 ,
V_152 , V_8 -> V_107 ,
V_8 -> V_112 , V_8 -> V_111 ) ;
return V_33 ;
}
static int F_79 ( struct V_7 * V_8 , struct V_94 * V_73 ,
T_2 V_143 , int V_14 , int V_2 , T_2 V_3 )
{
int V_33 , type ;
T_2 V_144 , V_145 ;
T_3 V_18 ;
void T_1 * V_146 ;
if ( V_8 -> V_10 -> V_153 )
return V_8 -> V_10 -> V_153 ( V_8 , V_73 , V_143 , V_14 , V_2 , V_3 ) ;
V_144 = F_74 ( V_73 -> V_147 ) | F_75 ( F_76 ( V_143 ) ) |
F_77 ( F_78 ( V_143 ) ) ;
if ( V_73 -> V_148 -> V_147 == V_8 -> V_137 ) {
type = V_149 ;
V_18 = V_8 -> V_103 ;
V_145 = V_8 -> V_101 ;
V_146 = V_8 -> V_106 ;
} else {
type = V_150 ;
V_18 = V_8 -> V_105 ;
V_145 = V_8 -> V_102 ;
V_146 = V_8 -> V_122 ;
}
F_13 ( V_8 , V_151 ,
type , V_18 ,
V_144 , V_145 ) ;
V_33 = F_5 ( V_146 + V_14 , V_2 , V_3 ) ;
F_13 ( V_8 , V_151 ,
V_152 , V_8 -> V_107 ,
V_8 -> V_112 , V_8 -> V_111 ) ;
return V_33 ;
}
static int F_80 ( struct V_7 * V_8 ,
struct V_94 * V_73 , int V_78 )
{
if ( V_73 -> V_147 != V_8 -> V_137 ) {
if ( ! F_43 ( V_8 ) )
return 0 ;
}
if ( V_73 -> V_147 == V_8 -> V_137 && V_78 > 0 )
return 0 ;
if ( V_73 -> V_154 == V_8 -> V_137 && V_78 > 0 )
return 0 ;
return 1 ;
}
static int F_81 ( struct V_94 * V_73 , T_2 V_143 , int V_14 ,
int V_2 , T_2 * V_3 )
{
struct V_7 * V_8 = V_73 -> V_74 ;
if ( F_80 ( V_8 , V_73 , F_76 ( V_143 ) ) == 0 ) {
* V_3 = 0xffffffff ;
return V_155 ;
}
if ( V_73 -> V_147 == V_8 -> V_137 )
return F_11 ( V_8 , V_14 , V_2 , V_3 ) ;
return F_73 ( V_8 , V_73 , V_143 , V_14 , V_2 , V_3 ) ;
}
static int F_82 ( struct V_94 * V_73 , T_2 V_143 ,
int V_14 , int V_2 , T_2 V_3 )
{
struct V_7 * V_8 = V_73 -> V_74 ;
if ( F_80 ( V_8 , V_73 , F_76 ( V_143 ) ) == 0 )
return V_155 ;
if ( V_73 -> V_147 == V_8 -> V_137 )
return F_12 ( V_8 , V_14 , V_2 , V_3 ) ;
return F_79 ( V_8 , V_73 , V_143 , V_14 , V_2 , V_3 ) ;
}
void F_83 ( struct V_7 * V_8 )
{
T_2 V_3 ;
T_2 V_156 ;
T_2 V_157 ;
F_9 ( V_8 , V_158 , & V_3 ) ;
V_3 &= ~ V_159 ;
switch ( V_8 -> V_123 ) {
case 1 :
V_3 |= V_160 ;
break;
case 2 :
V_3 |= V_161 ;
break;
case 4 :
V_3 |= V_162 ;
break;
case 8 :
V_3 |= V_163 ;
break;
default:
F_52 ( V_8 -> V_78 , L_10 , V_8 -> V_123 ) ;
return;
}
F_10 ( V_8 , V_3 , V_158 ) ;
F_9 ( V_8 , V_135 , & V_3 ) ;
V_3 &= ~ V_164 ;
switch ( V_8 -> V_123 ) {
case 1 :
V_3 |= V_165 ;
break;
case 2 :
V_3 |= V_166 ;
break;
case 4 :
V_3 |= V_167 ;
break;
case 8 :
V_3 |= V_168 ;
break;
}
F_10 ( V_8 , V_3 , V_135 ) ;
F_10 ( V_8 , 0x00000004 , V_132 ) ;
F_10 ( V_8 , 0x00000000 , V_169 ) ;
F_9 ( V_8 , V_170 , & V_3 ) ;
V_3 &= 0xffff00ff ;
V_3 |= 0x00000100 ;
F_10 ( V_8 , V_3 , V_170 ) ;
F_9 ( V_8 , V_171 , & V_3 ) ;
V_3 &= 0xff000000 ;
V_3 |= 0x00010100 ;
F_10 ( V_8 , V_3 , V_171 ) ;
V_156 = ( ( T_2 ) V_8 -> V_121 & 0xfff00000 ) >> 16 ;
V_157 = ( V_8 -> V_115 + ( T_2 ) V_8 -> V_121 ) & 0xfff00000 ;
V_3 = V_157 | V_156 ;
F_10 ( V_8 , V_3 , V_172 ) ;
F_9 ( V_8 , V_173 , & V_3 ) ;
V_3 &= 0xffff0000 ;
V_3 |= V_174 | V_175 |
V_176 | V_177 ;
F_10 ( V_8 , V_3 , V_173 ) ;
}
