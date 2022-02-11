static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 ;
if ( F_2 ( V_2 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
return 0 ;
}
V_3 = F_3 ( V_2 -> V_5 , 0 , 0 ,
F_4 ( V_2 -> V_8 ) + V_9 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
V_4 &= 0x0f ;
if ( V_4 == 0x0f ) {
V_3 = F_3 ( V_2 -> V_5 , 0 , 0 ,
F_4 ( V_2 -> V_8 ) + V_11 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
}
V_2 -> V_6 = V_4 ;
V_10:
return V_3 ;
}
static int F_5 ( struct V_12 * V_5 , unsigned int V_13 )
{
int V_3 ;
struct V_1 * V_2 ;
F_6 ( V_13 > V_14 ) ;
V_2 = F_7 ( V_5 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_2 -> V_8 = V_13 ;
if ( ! ( V_5 -> V_15 & V_16 ) ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_17;
V_3 = F_10 ( V_2 ) ;
if ( V_3 )
goto V_17;
} else {
V_2 -> V_18 = V_2 -> V_5 -> V_19 . V_18 ;
V_2 -> V_20 = V_2 -> V_5 -> V_19 . V_20 ;
V_2 -> V_21 = V_2 -> V_5 -> V_19 . V_22 ;
}
V_5 -> V_1 [ V_13 - 1 ] = V_2 ;
return 0 ;
V_17:
F_11 ( V_2 ) ;
return V_3 ;
}
static int F_12 ( struct V_12 * V_5 , T_1 V_23 )
{
int V_3 ;
int V_24 ;
int V_25 = V_23 & V_26 ;
unsigned char V_4 ;
unsigned char V_27 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_28 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
V_24 = V_4 & 0x0f ;
if ( V_24 > V_29 ) {
F_13 ( L_1 ,
F_14 ( V_5 -> V_30 ) , V_24 ) ;
return - V_31 ;
}
V_5 -> V_32 . V_33 = ( V_4 & 0xf0 ) >> 4 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_34 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_35 )
V_5 -> V_32 . V_36 = 1 ;
if ( V_4 & V_37 )
V_5 -> V_32 . V_38 = 1 ;
if ( V_4 & V_39 )
V_5 -> V_32 . V_40 = 1 ;
if ( V_24 >= V_41 ) {
V_3 = F_3 ( V_5 , 0 , 0 , V_42 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_43 )
V_5 -> V_32 . V_44 = 1 ;
}
if ( V_24 >= V_45 ) {
V_3 = F_3 ( V_5 , 0 , 0 , V_46 , 0 , & V_27 ) ;
if ( V_3 )
goto V_10;
V_5 -> V_47 . V_48 = 0 ;
V_5 -> V_49 . V_50 = 0 ;
V_5 -> V_49 . V_51 = 0 ;
if ( V_24 >= V_29 && V_25 ) {
V_5 -> V_47 . V_48 = 1 ;
V_3 = F_3 ( V_5 , 0 , 0 ,
V_52 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( F_15 ( V_5 -> V_30 ) ) {
if ( V_4 & V_53 )
V_5 -> V_49 . V_50
|= V_54 ;
if ( V_4 & V_55 )
V_5 -> V_49 . V_50
|= V_56 ;
if ( V_4 & V_57 )
V_5 -> V_49 . V_50
|= V_58 ;
}
V_3 = F_3 ( V_5 , 0 , 0 ,
V_59 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_60 )
V_5 -> V_49 . V_51 |= V_61 ;
if ( V_4 & V_62 )
V_5 -> V_49 . V_51 |= V_63 ;
if ( V_4 & V_64 )
V_5 -> V_49 . V_51 |= V_65 ;
}
if ( ! V_5 -> V_49 . V_50 ) {
if ( V_27 & V_66 ) {
V_5 -> V_32 . V_67 = 1 ;
V_5 -> V_49 . V_68 = 50000000 ;
} else {
V_5 -> V_32 . V_67 = 0 ;
V_5 -> V_49 . V_68 = 25000000 ;
}
}
}
V_10:
return V_3 ;
}
static int F_16 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_69 ;
if ( ! ( V_5 -> V_30 -> V_70 & V_71 ) )
return 0 ;
if ( V_5 -> V_32 . V_38 && ! V_5 -> V_32 . V_40 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_72 , 0 , & V_69 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_69 & V_73 ) == V_74 )
F_17 ( L_2 ,
F_14 ( V_5 -> V_30 ) , V_69 ) ;
V_69 &= ~ V_73 ;
V_69 |= V_75 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_72 , V_69 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_18 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_69 ;
if ( ! F_19 ( V_5 ) )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_72 , 0 , & V_69 ) ;
if ( V_3 )
return V_3 ;
V_69 |= V_76 ;
return F_3 ( V_5 , 1 , 0 , V_72 , V_69 , NULL ) ;
}
static int F_20 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_69 ;
if ( ! ( V_5 -> V_30 -> V_70 & V_71 ) )
return 0 ;
if ( V_5 -> V_32 . V_38 && ! V_5 -> V_32 . V_40 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_72 , 0 , & V_69 ) ;
if ( V_3 )
return V_3 ;
if ( ! ( V_69 & V_75 ) )
return 0 ;
V_69 &= ~ V_75 ;
V_69 |= V_77 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_72 , V_69 , NULL ) ;
if ( V_3 )
return V_3 ;
F_21 ( V_5 -> V_30 , V_78 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_5 )
{
int V_79 ;
if ( V_5 -> type == V_80 )
V_79 = F_16 ( V_5 ) ;
else if ( ( V_5 -> V_30 -> V_70 & V_71 ) &&
( V_5 -> V_47 . V_81 & V_82 ) ) {
V_79 = F_23 ( V_5 , V_83 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_16 ( V_5 ) ;
if ( V_79 <= 0 )
F_23 ( V_5 , V_78 ) ;
} else
return 0 ;
if ( V_79 > 0 ) {
F_21 ( V_5 -> V_30 , V_83 ) ;
V_79 = 0 ;
}
return V_79 ;
}
static int F_24 ( struct V_12 * V_5 , int V_84 )
{
int V_3 ;
T_2 V_27 ;
if ( ! ( V_5 -> V_30 -> V_70 & V_85 ) )
return 0 ;
if ( ! V_5 -> V_32 . V_67 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_46 , 0 , & V_27 ) ;
if ( V_3 )
return V_3 ;
if ( V_84 )
V_27 |= V_86 ;
else
V_27 &= ~ V_86 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_46 , V_27 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_25 ( struct V_12 * V_5 )
{
int V_3 ;
V_3 = F_24 ( V_5 , true ) ;
if ( V_3 <= 0 || V_5 -> type == V_80 )
return V_3 ;
V_3 = F_26 ( V_5 ) ;
if ( V_3 <= 0 )
F_24 ( V_5 , false ) ;
return V_3 ;
}
static unsigned F_27 ( struct V_12 * V_5 )
{
unsigned V_87 ;
if ( F_28 ( V_5 ) ) {
V_87 = 50000000 ;
} else {
V_87 = V_5 -> V_19 . V_87 ;
}
if ( V_5 -> type == V_88 )
V_87 = F_29 ( V_87 , F_30 ( V_5 ) ) ;
return V_87 ;
}
static unsigned char F_31 ( int V_89 )
{
switch ( V_89 ) {
case V_90 :
return V_91 ;
case V_92 :
return V_93 ;
case V_94 :
return V_95 ;
case V_96 :
return V_97 ;
default:
return V_93 ;
}
}
static void F_32 ( struct V_12 * V_5 )
{
int V_98 , V_99 , V_100 ;
unsigned char V_101 ;
int V_79 ;
V_5 -> V_99 = 0 ;
V_98 = V_5 -> V_49 . V_51 | V_102 ;
V_99 = F_33 ( V_5 ,
V_5 -> V_49 . V_103 ,
V_98 , & V_100 ) ;
if ( V_99 ) {
V_79 = F_3 ( V_5 , 0 , 0 , V_59 , 0 ,
& V_101 ) ;
if ( V_79 )
return;
V_101 &= ~ ( V_104 << V_105 ) ;
V_101 |= F_31 ( V_99 ) ;
V_79 = F_3 ( V_5 , 1 , 0 , V_59 ,
V_101 , NULL ) ;
if ( V_79 )
return;
V_5 -> V_99 = V_99 ;
}
if ( V_100 )
F_34 ( V_5 -> V_30 , V_100 ) ;
}
static int F_35 ( struct V_12 * V_5 )
{
unsigned int V_106 , V_107 ;
int V_79 ;
unsigned char V_27 ;
if ( ! F_15 ( V_5 -> V_30 ) )
return 0 ;
V_106 = V_108 ;
V_107 = V_109 ;
if ( ( V_5 -> V_30 -> V_70 & V_110 ) &&
( V_5 -> V_49 . V_50 & V_58 ) ) {
V_106 = V_111 ;
V_107 = V_112 ;
V_5 -> V_49 . V_103 = V_113 ;
V_5 -> V_114 = V_115 ;
} else if ( ( V_5 -> V_30 -> V_70 & V_116 ) &&
( V_5 -> V_49 . V_50 & V_54 ) ) {
V_106 = V_117 ;
V_107 = V_118 ;
V_5 -> V_49 . V_103 = V_119 ;
V_5 -> V_114 = V_120 ;
} else if ( ( V_5 -> V_30 -> V_70 & ( V_110 |
V_121 ) ) && ( V_5 -> V_49 . V_50 &
V_56 ) ) {
V_106 = V_122 ;
V_107 = V_123 ;
V_5 -> V_49 . V_103 = V_124 ;
V_5 -> V_114 = V_125 ;
} else if ( ( V_5 -> V_30 -> V_70 & ( V_110 |
V_121 | V_126 ) ) &&
( V_5 -> V_49 . V_50 & V_127 ) ) {
V_106 = V_128 ;
V_107 = V_129 ;
V_5 -> V_49 . V_103 = V_130 ;
V_5 -> V_114 = V_131 ;
} else if ( ( V_5 -> V_30 -> V_70 & ( V_110 |
V_121 | V_126 |
V_132 ) ) && ( V_5 -> V_49 . V_50 &
V_133 ) ) {
V_106 = V_108 ;
V_107 = V_109 ;
V_5 -> V_49 . V_103 = V_134 ;
V_5 -> V_114 = V_135 ;
}
V_79 = F_3 ( V_5 , 0 , 0 , V_46 , 0 , & V_27 ) ;
if ( V_79 )
return V_79 ;
V_27 &= ~ V_136 ;
V_27 |= V_106 ;
V_79 = F_3 ( V_5 , 1 , 0 , V_46 , V_27 , NULL ) ;
if ( V_79 )
return V_79 ;
if ( V_106 ) {
F_36 ( V_5 -> V_30 , V_107 ) ;
F_37 ( V_5 -> V_30 , V_5 -> V_49 . V_103 ) ;
}
return 0 ;
}
static int F_38 ( struct V_12 * V_5 )
{
int V_79 ;
if ( ! V_5 -> V_47 . V_48 )
return 0 ;
if ( V_5 -> V_30 -> V_70 & V_71 )
V_79 = F_22 ( V_5 ) ;
F_32 ( V_5 ) ;
V_79 = F_35 ( V_5 ) ;
if ( V_79 )
goto V_10;
if ( ! F_39 ( V_5 -> V_30 ) &&
( ( V_5 -> V_30 -> V_137 . V_107 == V_123 ) ||
( V_5 -> V_30 -> V_137 . V_107 == V_112 ) ) )
V_79 = F_40 ( V_5 ) ;
V_10:
return V_79 ;
}
static int F_41 ( struct V_138 * V_30 , T_1 V_23 ,
struct V_12 * V_139 , int V_140 )
{
struct V_12 * V_5 ;
int V_79 ;
int V_141 = 10 ;
T_1 V_142 = 0 ;
T_1 V_143 = V_23 ;
F_6 ( ! V_30 ) ;
F_42 ( ! V_30 -> V_144 ) ;
if ( F_15 ( V_30 ) )
V_23 |= V_26 ;
V_145:
if ( ! V_141 ) {
F_17 ( L_3 , F_14 ( V_30 ) ) ;
V_23 &= ~ V_26 ;
}
if ( ! V_140 ) {
V_79 = F_43 ( V_30 , V_23 , & V_142 ) ;
if ( V_79 )
goto V_79;
}
if ( F_39 ( V_30 ) ) {
V_79 = F_44 ( V_30 , V_146 ) ;
if ( V_79 )
goto V_79;
}
V_5 = F_45 ( V_30 , NULL ) ;
if ( F_8 ( V_5 ) ) {
V_79 = F_9 ( V_5 ) ;
goto V_79;
}
if ( ( V_142 & V_147 ) &&
F_46 ( V_30 , V_23 & V_142 , V_5 -> V_148 , NULL ) == 0 ) {
V_5 -> type = V_88 ;
if ( V_139 && ( V_139 -> type != V_88 ||
memcmp ( V_5 -> V_148 , V_139 -> V_148 , sizeof( V_5 -> V_148 ) ) != 0 ) ) {
F_47 ( V_5 ) ;
return - V_149 ;
}
} else {
V_5 -> type = V_80 ;
if ( V_139 && V_139 -> type != V_80 ) {
F_47 ( V_5 ) ;
return - V_149 ;
}
}
if ( V_30 -> V_150 -> V_151 )
V_30 -> V_150 -> V_151 ( V_30 , V_5 ) ;
if ( ! V_140 && ( V_142 & V_23 & V_26 ) ) {
V_79 = F_48 ( V_30 , V_152 ,
V_143 ) ;
if ( V_79 == - V_153 ) {
F_49 ( V_30 ) ;
F_50 ( V_30 ) ;
F_51 ( V_30 , V_30 -> V_154 ) ;
F_47 ( V_5 ) ;
V_141 -- ;
goto V_145;
} else if ( V_79 ) {
V_23 &= ~ V_26 ;
}
V_79 = 0 ;
} else {
V_23 &= ~ V_26 ;
}
if ( ! V_140 && ! F_39 ( V_30 ) ) {
V_79 = F_52 ( V_30 , & V_5 -> V_155 ) ;
if ( V_79 )
goto remove;
if ( V_139 )
V_139 -> V_155 = V_5 -> V_155 ;
}
if ( ! V_139 && V_5 -> type == V_88 ) {
V_79 = F_53 ( V_30 , V_5 ) ;
if ( V_79 )
return V_79 ;
F_54 ( V_5 ) ;
}
if ( ! V_140 && ! F_39 ( V_30 ) ) {
V_79 = F_55 ( V_5 ) ;
if ( V_79 )
goto remove;
}
if ( V_5 -> V_15 & V_16 ) {
F_37 ( V_30 , V_5 -> V_19 . V_87 ) ;
if ( V_5 -> V_32 . V_67 ) {
F_36 ( V_5 -> V_30 , V_156 ) ;
}
goto V_157;
}
V_79 = F_12 ( V_5 , V_23 ) ;
if ( V_79 )
goto remove;
V_79 = F_56 ( V_5 ) ;
if ( V_79 )
goto remove;
if ( V_139 ) {
int V_158 = ( V_5 -> V_19 . V_18 == V_139 -> V_19 . V_18 &&
V_5 -> V_19 . V_20 == V_139 -> V_19 . V_20 ) ;
F_47 ( V_5 ) ;
if ( ! V_158 )
return - V_149 ;
V_5 = V_139 ;
}
V_5 -> V_23 = V_143 ;
F_57 ( V_5 , NULL ) ;
if ( V_5 -> type == V_88 ) {
V_79 = F_58 ( V_30 , V_5 , V_139 != NULL ) ;
if ( V_79 ) {
F_50 ( V_30 ) ;
if ( F_39 ( V_30 ) )
F_44 ( V_30 , V_146 ) ;
V_5 -> type = V_80 ;
} else
V_5 -> V_159 . type = & V_160 ;
}
V_79 = F_18 ( V_5 ) ;
if ( V_79 )
goto remove;
if ( ( V_23 & V_26 ) && V_5 -> V_49 . V_50 ) {
V_79 = F_38 ( V_5 ) ;
if ( V_79 )
goto remove;
} else {
V_79 = F_25 ( V_5 ) ;
if ( V_79 > 0 )
F_36 ( V_5 -> V_30 , V_156 ) ;
else if ( V_79 )
goto remove;
F_37 ( V_30 , F_27 ( V_5 ) ) ;
V_79 = F_22 ( V_5 ) ;
if ( V_79 )
goto remove;
}
V_157:
if ( ! V_139 )
V_30 -> V_5 = V_5 ;
return 0 ;
remove:
if ( ! V_139 )
F_47 ( V_5 ) ;
V_79:
return V_79 ;
}
static void F_59 ( struct V_138 * V_30 )
{
int V_161 ;
F_6 ( ! V_30 ) ;
F_6 ( ! V_30 -> V_5 ) ;
for ( V_161 = 0 ; V_161 < V_30 -> V_5 -> V_162 ; V_161 ++ ) {
if ( V_30 -> V_5 -> V_1 [ V_161 ] ) {
F_11 ( V_30 -> V_5 -> V_1 [ V_161 ] ) ;
V_30 -> V_5 -> V_1 [ V_161 ] = NULL ;
}
}
F_47 ( V_30 -> V_5 ) ;
V_30 -> V_5 = NULL ;
}
static int F_60 ( struct V_138 * V_30 )
{
return F_55 ( V_30 -> V_5 ) ;
}
static void F_61 ( struct V_138 * V_30 )
{
int V_79 ;
F_6 ( ! V_30 ) ;
F_6 ( ! V_30 -> V_5 ) ;
if ( V_30 -> V_70 & V_163 ) {
V_79 = F_62 ( & V_30 -> V_5 -> V_159 ) ;
if ( V_79 < 0 ) {
F_63 ( & V_30 -> V_5 -> V_159 ) ;
goto V_10;
}
}
F_64 ( V_30 ) ;
V_79 = F_65 ( V_30 ) ;
F_66 ( V_30 ) ;
if ( V_30 -> V_70 & V_163 )
F_67 ( & V_30 -> V_5 -> V_159 ) ;
V_10:
if ( V_79 ) {
F_59 ( V_30 ) ;
F_64 ( V_30 ) ;
F_68 ( V_30 ) ;
F_69 ( V_30 ) ;
F_66 ( V_30 ) ;
}
}
static int F_70 ( struct V_138 * V_30 )
{
int V_161 , V_79 = 0 ;
for ( V_161 = 0 ; V_161 < V_30 -> V_5 -> V_162 ; V_161 ++ ) {
struct V_1 * V_2 = V_30 -> V_5 -> V_1 [ V_161 ] ;
if ( V_2 && F_71 ( V_2 ) && V_2 -> V_159 . V_164 ) {
const struct V_165 * V_166 = V_2 -> V_159 . V_164 -> V_167 ;
if ( ! V_166 || ! V_166 -> V_168 || ! V_166 -> V_169 ) {
V_79 = - V_170 ;
break;
}
}
}
return V_79 ;
}
static int F_72 ( struct V_138 * V_30 )
{
F_64 ( V_30 ) ;
if ( F_73 ( V_30 ) && F_74 ( V_30 ) )
F_20 ( V_30 -> V_5 ) ;
if ( ! F_73 ( V_30 ) ) {
F_69 ( V_30 ) ;
} else if ( V_30 -> V_171 ) {
F_75 ( V_30 ) ;
F_76 ( V_30 ) ;
}
F_66 ( V_30 ) ;
return 0 ;
}
static int F_77 ( struct V_138 * V_30 )
{
int V_79 = 0 ;
F_6 ( ! V_30 ) ;
F_6 ( ! V_30 -> V_5 ) ;
F_64 ( V_30 ) ;
if ( ! F_73 ( V_30 ) ) {
F_78 ( V_30 , V_30 -> V_5 -> V_23 ) ;
if ( V_30 -> V_70 & V_163 ) {
F_79 ( & V_30 -> V_5 -> V_159 ) ;
F_80 ( & V_30 -> V_5 -> V_159 ) ;
F_81 ( & V_30 -> V_5 -> V_159 ) ;
}
}
if ( F_82 ( V_30 ) || ! F_73 ( V_30 ) ) {
F_49 ( V_30 ) ;
F_50 ( V_30 ) ;
F_51 ( V_30 , V_30 -> V_5 -> V_23 ) ;
V_79 = F_43 ( V_30 , 0 , NULL ) ;
if ( ! V_79 )
V_79 = F_41 ( V_30 , V_30 -> V_5 -> V_23 ,
V_30 -> V_5 ,
F_73 ( V_30 ) ) ;
} else if ( F_73 ( V_30 ) && F_74 ( V_30 ) ) {
V_79 = F_22 ( V_30 -> V_5 ) ;
}
if ( ! V_79 && V_30 -> V_172 ) {
if ( ! ( V_30 -> V_173 & V_174 ) )
F_83 ( V_30 -> V_175 ) ;
else if ( V_30 -> V_70 & V_176 )
V_30 -> V_150 -> V_177 ( V_30 , 1 ) ;
}
F_66 ( V_30 ) ;
V_30 -> V_178 &= ~ V_179 ;
return V_79 ;
}
static int F_84 ( struct V_138 * V_30 )
{
int V_3 ;
F_6 ( ! V_30 ) ;
F_6 ( ! V_30 -> V_5 ) ;
F_64 ( V_30 ) ;
F_49 ( V_30 ) ;
F_50 ( V_30 ) ;
F_51 ( V_30 , V_30 -> V_5 -> V_23 ) ;
V_3 = F_43 ( V_30 , 0 , NULL ) ;
if ( V_3 )
goto V_10;
V_3 = F_41 ( V_30 , V_30 -> V_5 -> V_23 , V_30 -> V_5 ,
F_73 ( V_30 ) ) ;
if ( ! V_3 && V_30 -> V_172 )
F_85 ( V_30 ) ;
V_10:
F_66 ( V_30 ) ;
return V_3 ;
}
static int F_86 ( struct V_138 * V_30 )
{
F_64 ( V_30 ) ;
F_69 ( V_30 ) ;
F_66 ( V_30 ) ;
return 0 ;
}
static int F_87 ( struct V_138 * V_30 )
{
int V_3 ;
F_64 ( V_30 ) ;
F_78 ( V_30 , V_30 -> V_5 -> V_23 ) ;
V_3 = F_84 ( V_30 ) ;
F_66 ( V_30 ) ;
return V_3 ;
}
static int F_88 ( struct V_138 * V_30 )
{
F_89 ( V_30 , V_30 -> V_5 -> V_23 ) ;
return F_84 ( V_30 ) ;
}
int F_90 ( struct V_138 * V_30 )
{
int V_79 , V_161 , V_180 ;
T_1 V_23 , V_142 ;
struct V_12 * V_5 ;
F_6 ( ! V_30 ) ;
F_42 ( ! V_30 -> V_144 ) ;
V_79 = F_43 ( V_30 , 0 , & V_23 ) ;
if ( V_79 )
return V_79 ;
F_91 ( V_30 , & V_181 ) ;
if ( V_30 -> V_182 )
V_30 -> V_154 = V_30 -> V_182 ;
V_142 = F_92 ( V_30 , V_23 ) ;
if ( ! V_142 ) {
V_79 = - V_31 ;
goto V_79;
}
V_79 = F_41 ( V_30 , V_142 , NULL , 0 ) ;
if ( V_79 )
goto V_79;
V_5 = V_30 -> V_5 ;
if ( V_30 -> V_70 & V_163 ) {
V_79 = F_80 ( & V_5 -> V_159 ) ;
if ( V_79 )
goto remove;
F_81 ( & V_5 -> V_159 ) ;
}
V_180 = ( V_23 & 0x70000000 ) >> 28 ;
V_5 -> V_162 = 0 ;
for ( V_161 = 0 ; V_161 < V_180 ; V_161 ++ , V_5 -> V_162 ++ ) {
V_79 = F_5 ( V_30 -> V_5 , V_161 + 1 ) ;
if ( V_79 )
goto remove;
if ( V_30 -> V_70 & V_163 )
F_81 ( & V_5 -> V_1 [ V_161 ] -> V_159 ) ;
}
F_66 ( V_30 ) ;
V_79 = F_93 ( V_30 -> V_5 ) ;
if ( V_79 )
goto V_183;
for ( V_161 = 0 ; V_161 < V_180 ; V_161 ++ ) {
V_79 = F_94 ( V_30 -> V_5 -> V_1 [ V_161 ] ) ;
if ( V_79 )
goto V_183;
}
F_64 ( V_30 ) ;
return 0 ;
V_183:
F_59 ( V_30 ) ;
F_64 ( V_30 ) ;
remove:
F_66 ( V_30 ) ;
if ( V_30 -> V_5 )
F_59 ( V_30 ) ;
F_64 ( V_30 ) ;
V_79:
F_68 ( V_30 ) ;
F_13 ( L_4 ,
F_14 ( V_30 ) , V_79 ) ;
return V_79 ;
}
