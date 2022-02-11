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
int V_85 ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ ) {
if ( F_44 ( V_8 ) ) {
F_45 ( V_8 -> V_78 , L_1 ) ;
return 0 ;
}
F_46 ( V_87 , V_88 ) ;
}
F_47 ( V_8 -> V_78 , L_2 ) ;
return - V_89 ;
}
int F_44 ( struct V_7 * V_8 )
{
T_2 V_3 ;
if ( V_8 -> V_10 -> V_90 )
return V_8 -> V_10 -> V_90 ( V_8 ) ;
V_3 = F_2 ( V_8 -> V_12 + V_91 ) ;
return V_3 & V_92 ;
}
static int F_48 ( struct V_38 * V_93 , unsigned int V_32 ,
T_5 V_84 )
{
F_49 ( V_32 , & V_94 , V_95 ) ;
F_50 ( V_32 , V_93 -> V_96 ) ;
return 0 ;
}
int F_51 ( struct V_7 * V_8 )
{
struct V_97 * V_98 = V_8 -> V_78 -> V_99 ;
struct V_100 * V_72 = F_52 ( V_8 -> V_78 ) ;
struct V_101 * V_73 , * V_102 ;
struct V_103 * V_104 ;
int V_30 , V_33 ;
F_53 ( V_44 ) ;
struct V_105 * V_106 ;
V_104 = F_54 ( V_72 , V_107 , L_3 ) ;
if ( V_104 ) {
V_8 -> V_108 = F_55 ( V_104 ) / 2 ;
V_8 -> V_109 = F_55 ( V_104 ) / 2 ;
V_8 -> V_110 = V_104 -> V_111 ;
V_8 -> V_112 = V_104 -> V_111 + V_8 -> V_108 ;
} else if ( ! V_8 -> V_113 ) {
F_47 ( V_8 -> V_78 , L_4 ) ;
}
V_33 = F_56 ( V_98 , 0 , 0xff , & V_44 , & V_8 -> V_114 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_57 ( & V_72 -> V_78 , & V_44 ) ;
if ( V_33 )
goto error;
F_58 (win, &res) {
switch ( F_59 ( V_106 -> V_44 ) ) {
case V_115 :
V_8 -> V_116 = V_106 -> V_44 ;
V_8 -> V_116 -> V_117 = L_5 ;
V_8 -> V_118 = F_55 ( V_8 -> V_116 ) ;
V_8 -> V_119 = V_8 -> V_116 -> V_111 - V_106 -> V_120 ;
V_33 = F_60 ( V_8 -> V_116 , V_8 -> V_114 ) ;
if ( V_33 )
F_61 ( V_8 -> V_78 , L_6 ,
V_33 , V_8 -> V_116 ) ;
break;
case V_107 :
V_8 -> V_121 = V_106 -> V_44 ;
V_8 -> V_121 -> V_117 = L_7 ;
V_8 -> V_122 = F_55 ( V_8 -> V_121 ) ;
V_8 -> V_123 = V_8 -> V_121 -> V_111 - V_106 -> V_120 ;
break;
case 0 :
V_8 -> V_124 = V_106 -> V_44 ;
V_8 -> V_108 = F_55 ( V_8 -> V_124 ) / 2 ;
V_8 -> V_109 = F_55 ( V_8 -> V_124 ) / 2 ;
V_8 -> V_110 = V_8 -> V_124 -> V_111 ;
V_8 -> V_112 = V_8 -> V_124 -> V_111 + V_8 -> V_108 ;
break;
case V_125 :
V_8 -> V_126 = V_106 -> V_44 ;
break;
}
}
if ( ! V_8 -> V_12 ) {
V_8 -> V_12 = F_62 ( V_8 -> V_78 , V_8 -> V_124 -> V_111 ,
F_55 ( V_8 -> V_124 ) ) ;
if ( ! V_8 -> V_12 ) {
F_47 ( V_8 -> V_78 , L_8 ) ;
V_33 = - V_127 ;
goto error;
}
}
V_8 -> V_128 = V_8 -> V_121 -> V_111 ;
if ( ! V_8 -> V_113 ) {
V_8 -> V_113 = F_62 ( V_8 -> V_78 , V_8 -> V_110 ,
V_8 -> V_108 ) ;
if ( ! V_8 -> V_113 ) {
F_47 ( V_8 -> V_78 , L_9 ) ;
V_33 = - V_127 ;
goto error;
}
}
if ( ! V_8 -> V_129 ) {
V_8 -> V_129 = F_62 ( V_8 -> V_78 , V_8 -> V_112 ,
V_8 -> V_109 ) ;
if ( ! V_8 -> V_129 ) {
F_47 ( V_8 -> V_78 , L_8 ) ;
V_33 = - V_127 ;
goto error;
}
}
V_33 = F_63 ( V_98 , L_10 , & V_8 -> V_130 ) ;
if ( V_33 )
V_8 -> V_130 = 0 ;
if ( F_64 ( F_36 ) ) {
if ( ! V_8 -> V_10 -> V_131 ) {
V_8 -> V_38 = F_65 ( V_8 -> V_78 -> V_99 ,
V_55 , & V_132 ,
& V_133 ) ;
if ( ! V_8 -> V_38 ) {
F_47 ( V_8 -> V_78 , L_11 ) ;
V_33 = - V_134 ;
goto error;
}
for ( V_30 = 0 ; V_30 < V_55 ; V_30 ++ )
F_66 ( V_8 -> V_38 , V_30 ) ;
} else {
V_33 = V_8 -> V_10 -> V_131 ( V_8 , & V_133 ) ;
if ( V_33 < 0 )
goto error;
}
}
if ( V_8 -> V_10 -> V_135 )
V_8 -> V_10 -> V_135 ( V_8 ) ;
V_8 -> V_136 = V_8 -> V_126 -> V_111 ;
if ( F_64 ( F_36 ) ) {
V_73 = F_67 ( V_8 -> V_78 , V_8 -> V_136 ,
& V_137 , V_8 , & V_44 ,
& V_133 ) ;
V_133 . V_78 = V_8 -> V_78 ;
} else
V_73 = F_68 ( V_8 -> V_78 , V_8 -> V_136 , & V_137 ,
V_8 , & V_44 ) ;
if ( ! V_73 ) {
V_33 = - V_127 ;
goto error;
}
if ( V_8 -> V_10 -> V_138 )
V_8 -> V_10 -> V_138 ( V_8 ) ;
#ifdef F_69
F_70 ( V_139 , V_140 ) ;
#endif
F_71 ( V_73 ) ;
F_72 ( V_73 ) ;
F_73 (child, &bus->children, node)
F_74 ( V_102 ) ;
F_75 ( V_73 ) ;
return 0 ;
error:
F_76 ( & V_44 ) ;
return V_33 ;
}
static int F_77 ( struct V_7 * V_8 , struct V_101 * V_73 ,
T_2 V_141 , int V_14 , int V_2 , T_2 * V_3 )
{
int V_33 , type ;
T_2 V_142 , V_143 ;
T_3 V_18 ;
void T_1 * V_144 ;
if ( V_8 -> V_10 -> V_145 )
return V_8 -> V_10 -> V_145 ( V_8 , V_73 , V_141 , V_14 , V_2 , V_3 ) ;
V_142 = F_78 ( V_73 -> V_146 ) | F_79 ( F_80 ( V_141 ) ) |
F_81 ( F_82 ( V_141 ) ) ;
if ( V_73 -> V_147 -> V_146 == V_8 -> V_136 ) {
type = V_148 ;
V_18 = V_8 -> V_110 ;
V_143 = V_8 -> V_108 ;
V_144 = V_8 -> V_113 ;
} else {
type = V_149 ;
V_18 = V_8 -> V_112 ;
V_143 = V_8 -> V_109 ;
V_144 = V_8 -> V_129 ;
}
F_13 ( V_8 , V_150 ,
type , V_18 ,
V_142 , V_143 ) ;
V_33 = F_1 ( V_144 + V_14 , V_2 , V_3 ) ;
F_13 ( V_8 , V_150 ,
V_151 , V_8 -> V_114 ,
V_8 -> V_119 , V_8 -> V_118 ) ;
return V_33 ;
}
static int F_83 ( struct V_7 * V_8 , struct V_101 * V_73 ,
T_2 V_141 , int V_14 , int V_2 , T_2 V_3 )
{
int V_33 , type ;
T_2 V_142 , V_143 ;
T_3 V_18 ;
void T_1 * V_144 ;
if ( V_8 -> V_10 -> V_152 )
return V_8 -> V_10 -> V_152 ( V_8 , V_73 , V_141 , V_14 , V_2 , V_3 ) ;
V_142 = F_78 ( V_73 -> V_146 ) | F_79 ( F_80 ( V_141 ) ) |
F_81 ( F_82 ( V_141 ) ) ;
if ( V_73 -> V_147 -> V_146 == V_8 -> V_136 ) {
type = V_148 ;
V_18 = V_8 -> V_110 ;
V_143 = V_8 -> V_108 ;
V_144 = V_8 -> V_113 ;
} else {
type = V_149 ;
V_18 = V_8 -> V_112 ;
V_143 = V_8 -> V_109 ;
V_144 = V_8 -> V_129 ;
}
F_13 ( V_8 , V_150 ,
type , V_18 ,
V_142 , V_143 ) ;
V_33 = F_5 ( V_144 + V_14 , V_2 , V_3 ) ;
F_13 ( V_8 , V_150 ,
V_151 , V_8 -> V_114 ,
V_8 -> V_119 , V_8 -> V_118 ) ;
return V_33 ;
}
static int F_84 ( struct V_7 * V_8 ,
struct V_101 * V_73 , int V_78 )
{
if ( V_73 -> V_146 != V_8 -> V_136 ) {
if ( ! F_44 ( V_8 ) )
return 0 ;
}
if ( V_73 -> V_146 == V_8 -> V_136 && V_78 > 0 )
return 0 ;
if ( V_73 -> V_153 == V_8 -> V_136 && V_78 > 0 )
return 0 ;
return 1 ;
}
static int F_85 ( struct V_101 * V_73 , T_2 V_141 , int V_14 ,
int V_2 , T_2 * V_3 )
{
struct V_7 * V_8 = V_73 -> V_74 ;
if ( F_84 ( V_8 , V_73 , F_80 ( V_141 ) ) == 0 ) {
* V_3 = 0xffffffff ;
return V_154 ;
}
if ( V_73 -> V_146 == V_8 -> V_136 )
return F_11 ( V_8 , V_14 , V_2 , V_3 ) ;
return F_77 ( V_8 , V_73 , V_141 , V_14 , V_2 , V_3 ) ;
}
static int F_86 ( struct V_101 * V_73 , T_2 V_141 ,
int V_14 , int V_2 , T_2 V_3 )
{
struct V_7 * V_8 = V_73 -> V_74 ;
if ( F_84 ( V_8 , V_73 , F_80 ( V_141 ) ) == 0 )
return V_154 ;
if ( V_73 -> V_146 == V_8 -> V_136 )
return F_12 ( V_8 , V_14 , V_2 , V_3 ) ;
return F_83 ( V_8 , V_73 , V_141 , V_14 , V_2 , V_3 ) ;
}
void F_87 ( struct V_7 * V_8 )
{
T_2 V_3 ;
F_9 ( V_8 , V_155 , & V_3 ) ;
V_3 &= ~ V_156 ;
switch ( V_8 -> V_130 ) {
case 1 :
V_3 |= V_157 ;
break;
case 2 :
V_3 |= V_158 ;
break;
case 4 :
V_3 |= V_159 ;
break;
case 8 :
V_3 |= V_160 ;
break;
default:
F_47 ( V_8 -> V_78 , L_12 , V_8 -> V_130 ) ;
return;
}
F_10 ( V_8 , V_3 , V_155 ) ;
F_9 ( V_8 , V_161 , & V_3 ) ;
V_3 &= ~ V_162 ;
switch ( V_8 -> V_130 ) {
case 1 :
V_3 |= V_163 ;
break;
case 2 :
V_3 |= V_164 ;
break;
case 4 :
V_3 |= V_165 ;
break;
case 8 :
V_3 |= V_166 ;
break;
}
F_10 ( V_8 , V_3 , V_161 ) ;
F_10 ( V_8 , 0x00000004 , V_167 ) ;
F_10 ( V_8 , 0x00000000 , V_168 ) ;
F_9 ( V_8 , V_169 , & V_3 ) ;
V_3 &= 0xffff00ff ;
V_3 |= 0x00000100 ;
F_10 ( V_8 , V_3 , V_169 ) ;
F_9 ( V_8 , V_170 , & V_3 ) ;
V_3 &= 0xff000000 ;
V_3 |= 0x00010100 ;
F_10 ( V_8 , V_3 , V_170 ) ;
F_9 ( V_8 , V_171 , & V_3 ) ;
V_3 &= 0xffff0000 ;
V_3 |= V_172 | V_173 |
V_174 | V_175 ;
F_10 ( V_8 , V_3 , V_171 ) ;
if ( ! V_8 -> V_10 -> V_145 )
F_13 ( V_8 , V_176 ,
V_177 , V_8 -> V_128 ,
V_8 -> V_123 , V_8 -> V_122 ) ;
F_12 ( V_8 , V_167 , 4 , 0 ) ;
F_12 ( V_8 , V_178 , 2 , V_179 ) ;
F_11 ( V_8 , V_161 , 4 , & V_3 ) ;
V_3 |= V_180 ;
F_12 ( V_8 , V_161 , 4 , V_3 ) ;
}
