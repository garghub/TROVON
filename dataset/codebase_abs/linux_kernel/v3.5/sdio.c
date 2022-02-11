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
memset ( & V_5 -> V_28 , 0 , sizeof( struct V_29 ) ) ;
V_3 = F_3 ( V_5 , 0 , 0 , V_30 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
V_24 = V_4 & 0x0f ;
if ( V_24 > V_31 ) {
F_13 ( L_1 ,
F_14 ( V_5 -> V_32 ) , V_24 ) ;
return - V_33 ;
}
V_5 -> V_28 . V_34 = ( V_4 & 0xf0 ) >> 4 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_35 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_36 )
V_5 -> V_28 . V_37 = 1 ;
if ( V_4 & V_38 )
V_5 -> V_28 . V_39 = 1 ;
if ( V_4 & V_40 )
V_5 -> V_28 . V_41 = 1 ;
if ( V_24 >= V_42 ) {
V_3 = F_3 ( V_5 , 0 , 0 , V_43 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_44 )
V_5 -> V_28 . V_45 = 1 ;
}
if ( V_24 >= V_46 ) {
V_3 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_3 )
goto V_10;
V_5 -> V_48 . V_49 = 0 ;
V_5 -> V_50 . V_51 = 0 ;
V_5 -> V_50 . V_52 = 0 ;
if ( V_24 >= V_31 && V_25 ) {
V_5 -> V_48 . V_49 = 1 ;
V_3 = F_3 ( V_5 , 0 , 0 ,
V_53 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_5 -> V_32 -> V_54 &
( V_55 | V_56 |
V_57 | V_58 |
V_59 ) ) {
if ( V_4 & V_60 )
V_5 -> V_50 . V_51
|= V_61 ;
if ( V_4 & V_62 )
V_5 -> V_50 . V_51
|= V_63 ;
if ( V_4 & V_64 )
V_5 -> V_50 . V_51
|= V_65 ;
}
V_3 = F_3 ( V_5 , 0 , 0 ,
V_66 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_67 )
V_5 -> V_50 . V_52 |= V_68 ;
if ( V_4 & V_69 )
V_5 -> V_50 . V_52 |= V_70 ;
if ( V_4 & V_71 )
V_5 -> V_50 . V_52 |= V_72 ;
}
if ( ! V_5 -> V_50 . V_51 ) {
if ( V_27 & V_73 ) {
V_5 -> V_28 . V_74 = 1 ;
V_5 -> V_50 . V_75 = 50000000 ;
} else {
V_5 -> V_28 . V_74 = 0 ;
V_5 -> V_50 . V_75 = 25000000 ;
}
}
}
V_10:
return V_3 ;
}
static int F_15 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_76 ;
if ( ! ( V_5 -> V_32 -> V_54 & V_77 ) )
return 0 ;
if ( V_5 -> V_28 . V_39 && ! V_5 -> V_28 . V_41 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_78 , 0 , & V_76 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_76 & V_79 ) == V_80 )
F_16 ( L_2 ,
F_14 ( V_5 -> V_32 ) , V_76 ) ;
V_76 &= ~ V_79 ;
V_76 |= V_81 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_78 , V_76 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_17 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_76 ;
if ( ! F_18 ( V_5 ) )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_78 , 0 , & V_76 ) ;
if ( V_3 )
return V_3 ;
V_76 |= V_82 ;
return F_3 ( V_5 , 1 , 0 , V_78 , V_76 , NULL ) ;
}
static int F_19 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_76 ;
if ( ! ( V_5 -> V_32 -> V_54 & V_77 ) )
return 0 ;
if ( V_5 -> V_28 . V_39 && ! V_5 -> V_28 . V_41 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_78 , 0 , & V_76 ) ;
if ( V_3 )
return V_3 ;
if ( ! ( V_76 & V_81 ) )
return 0 ;
V_76 &= ~ V_81 ;
V_76 |= V_83 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_78 , V_76 , NULL ) ;
if ( V_3 )
return V_3 ;
F_20 ( V_5 -> V_32 , V_84 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_5 )
{
int V_85 ;
if ( V_5 -> type == V_86 )
return F_15 ( V_5 ) ;
if ( ( V_5 -> V_32 -> V_54 & V_77 ) &&
( V_5 -> V_48 . V_87 & V_88 ) ) {
V_85 = F_22 ( V_5 , V_89 ) ;
if ( V_85 )
return V_85 ;
} else
return 0 ;
V_85 = F_15 ( V_5 ) ;
if ( V_85 <= 0 )
F_22 ( V_5 , V_84 ) ;
return V_85 ;
}
static int F_23 ( struct V_12 * V_5 , int V_90 )
{
int V_3 ;
T_2 V_27 ;
if ( ! ( V_5 -> V_32 -> V_54 & V_91 ) )
return 0 ;
if ( ! V_5 -> V_28 . V_74 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_3 )
return V_3 ;
if ( V_90 )
V_27 |= V_92 ;
else
V_27 &= ~ V_92 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_47 , V_27 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_24 ( struct V_12 * V_5 )
{
int V_3 ;
V_3 = F_23 ( V_5 , true ) ;
if ( V_3 <= 0 || V_5 -> type == V_86 )
return V_3 ;
V_3 = F_25 ( V_5 ) ;
if ( V_3 <= 0 )
F_23 ( V_5 , false ) ;
return V_3 ;
}
static unsigned F_26 ( struct V_12 * V_5 )
{
unsigned V_93 ;
if ( F_27 ( V_5 ) ) {
V_93 = 50000000 ;
} else {
V_93 = V_5 -> V_19 . V_93 ;
}
if ( V_5 -> type == V_94 )
V_93 = F_28 ( V_93 , F_29 ( V_5 ) ) ;
return V_93 ;
}
static unsigned char F_30 ( int V_95 )
{
switch ( V_95 ) {
case V_96 :
return V_97 ;
case V_98 :
return V_99 ;
case V_100 :
return V_101 ;
case V_102 :
return V_103 ;
default:
return V_99 ;
}
}
static void F_31 ( struct V_12 * V_5 )
{
int V_104 = V_105 ;
int V_106 = V_105 ;
int V_107 ;
unsigned char V_108 ;
int V_85 ;
if ( ! ( V_5 -> V_32 -> V_54 &
( V_109 |
V_110 |
V_111 ) ) )
return;
if ( ! V_5 -> V_32 -> V_112 -> V_113 )
return;
if ( V_5 -> V_32 -> V_54 & V_109 )
V_104 |= V_68 ;
if ( V_5 -> V_32 -> V_54 & V_110 )
V_104 |= V_70 ;
if ( V_5 -> V_32 -> V_54 & V_111 )
V_104 |= V_72 ;
if ( V_5 -> V_50 . V_52 & V_68 )
V_106 |= V_68 ;
if ( V_5 -> V_50 . V_52 & V_70 )
V_106 |= V_70 ;
if ( V_5 -> V_50 . V_52 & V_72 )
V_106 |= V_72 ;
V_107 = V_5 -> V_32 -> V_112 -> V_113 (
V_5 -> V_50 . V_114 ,
V_104 , V_106 ) ;
V_85 = F_3 ( V_5 , 0 , 0 , V_66 , 0 ,
& V_108 ) ;
if ( V_85 )
return;
V_108 &= ~ ( V_115 << V_116 ) ;
V_108 |= F_30 ( V_107 ) ;
V_85 = F_3 ( V_5 , 1 , 0 , V_66 ,
V_108 , NULL ) ;
if ( ! V_85 )
F_32 ( V_5 -> V_32 , V_107 ) ;
}
static int F_33 ( struct V_12 * V_5 )
{
unsigned int V_117 , V_118 ;
int V_85 ;
unsigned char V_27 ;
if ( ! ( V_5 -> V_32 -> V_54 & ( V_55 | V_56 |
V_57 | V_58 | V_59 ) ) )
return 0 ;
V_117 = V_119 ;
V_118 = V_120 ;
if ( ( V_5 -> V_32 -> V_54 & V_58 ) &&
( V_5 -> V_50 . V_51 & V_65 ) ) {
V_117 = V_121 ;
V_118 = V_122 ;
V_5 -> V_50 . V_114 = V_123 ;
} else if ( ( V_5 -> V_32 -> V_54 & V_59 ) &&
( V_5 -> V_50 . V_51 & V_61 ) ) {
V_117 = V_124 ;
V_118 = V_125 ;
V_5 -> V_50 . V_114 = V_126 ;
} else if ( ( V_5 -> V_32 -> V_54 & ( V_58 |
V_57 ) ) && ( V_5 -> V_50 . V_51 &
V_63 ) ) {
V_117 = V_127 ;
V_118 = V_128 ;
V_5 -> V_50 . V_114 = V_129 ;
} else if ( ( V_5 -> V_32 -> V_54 & ( V_58 |
V_57 | V_56 ) ) &&
( V_5 -> V_50 . V_51 & V_130 ) ) {
V_117 = V_131 ;
V_118 = V_132 ;
V_5 -> V_50 . V_114 = V_133 ;
} else if ( ( V_5 -> V_32 -> V_54 & ( V_58 |
V_57 | V_56 |
V_55 ) ) && ( V_5 -> V_50 . V_51 &
V_134 ) ) {
V_117 = V_119 ;
V_118 = V_120 ;
V_5 -> V_50 . V_114 = V_135 ;
}
V_85 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_85 )
return V_85 ;
V_27 &= ~ V_136 ;
V_27 |= V_117 ;
V_85 = F_3 ( V_5 , 1 , 0 , V_47 , V_27 , NULL ) ;
if ( V_85 )
return V_85 ;
if ( V_117 ) {
F_34 ( V_5 -> V_32 , V_118 ) ;
F_35 ( V_5 -> V_32 , V_5 -> V_50 . V_114 ) ;
}
return 0 ;
}
static int F_36 ( struct V_12 * V_5 )
{
int V_85 ;
if ( ! V_5 -> V_48 . V_49 )
return 0 ;
if ( V_5 -> V_32 -> V_54 & V_77 ) {
V_85 = F_21 ( V_5 ) ;
if ( V_85 > 0 ) {
F_20 ( V_5 -> V_32 , V_89 ) ;
V_85 = 0 ;
}
}
F_31 ( V_5 ) ;
V_85 = F_33 ( V_5 ) ;
if ( V_85 )
goto V_10;
if ( ! F_37 ( V_5 -> V_32 ) && V_5 -> V_32 -> V_112 -> V_137 )
V_85 = V_5 -> V_32 -> V_112 -> V_137 ( V_5 -> V_32 ,
V_138 ) ;
V_10:
return V_85 ;
}
static int F_38 ( struct V_139 * V_32 , T_1 V_23 ,
struct V_12 * V_140 , int V_141 )
{
struct V_12 * V_5 ;
int V_85 ;
F_6 ( ! V_32 ) ;
F_39 ( ! V_32 -> V_142 ) ;
if ( ! V_141 ) {
F_40 ( V_32 , V_143 , 0 ) ;
V_85 = F_41 ( V_32 , V_32 -> V_23 , & V_23 ) ;
if ( V_85 )
goto V_85;
}
if ( F_37 ( V_32 ) ) {
V_85 = F_42 ( V_32 , V_144 ) ;
if ( V_85 )
goto V_85;
}
V_5 = F_43 ( V_32 , NULL ) ;
if ( F_8 ( V_5 ) ) {
V_85 = F_9 ( V_5 ) ;
goto V_85;
}
if ( ( V_23 & V_145 ) &&
F_44 ( V_32 , V_32 -> V_23 & V_23 , V_5 -> V_146 , NULL ) == 0 ) {
V_5 -> type = V_94 ;
if ( V_140 && ( V_140 -> type != V_94 ||
memcmp ( V_5 -> V_146 , V_140 -> V_146 , sizeof( V_5 -> V_146 ) ) != 0 ) ) {
F_45 ( V_5 ) ;
return - V_147 ;
}
} else {
V_5 -> type = V_86 ;
if ( V_140 && V_140 -> type != V_86 ) {
F_45 ( V_5 ) ;
return - V_147 ;
}
}
if ( V_32 -> V_112 -> V_148 )
V_32 -> V_112 -> V_148 ( V_32 , V_5 ) ;
if ( ( V_23 & V_26 ) &&
( V_32 -> V_54 &
( V_55 | V_56 |
V_57 | V_58 |
V_59 ) ) ) {
V_85 = F_40 ( V_32 , V_149 ,
true ) ;
if ( V_85 ) {
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
V_85 = 0 ;
} else {
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
if ( ! V_141 && ! F_37 ( V_32 ) ) {
V_85 = F_46 ( V_32 , & V_5 -> V_150 ) ;
if ( V_85 )
goto remove;
if ( V_140 )
V_140 -> V_150 = V_5 -> V_150 ;
}
if ( ! V_140 && V_5 -> type == V_94 ) {
V_85 = F_47 ( V_32 , V_5 ) ;
if ( V_85 )
return V_85 ;
F_48 ( V_5 ) ;
}
if ( ! V_141 && ! F_37 ( V_32 ) ) {
V_85 = F_49 ( V_5 ) ;
if ( V_85 )
goto remove;
}
if ( V_5 -> V_15 & V_16 ) {
F_35 ( V_32 , V_5 -> V_19 . V_93 ) ;
if ( V_5 -> V_28 . V_74 ) {
F_50 ( V_5 ) ;
F_34 ( V_5 -> V_32 , V_151 ) ;
}
goto V_152;
}
V_85 = F_12 ( V_5 , V_23 ) ;
if ( V_85 )
goto remove;
V_85 = F_51 ( V_5 ) ;
if ( V_85 )
goto remove;
if ( V_140 ) {
int V_153 = ( V_5 -> V_19 . V_18 == V_140 -> V_19 . V_18 &&
V_5 -> V_19 . V_20 == V_140 -> V_19 . V_20 ) ;
F_45 ( V_5 ) ;
if ( ! V_153 )
return - V_147 ;
V_5 = V_140 ;
}
F_52 ( V_5 , NULL ) ;
if ( V_5 -> type == V_94 ) {
V_85 = F_53 ( V_32 , V_5 , V_140 != NULL ) ;
if ( V_85 ) {
F_54 ( V_32 ) ;
if ( F_37 ( V_32 ) )
F_42 ( V_32 , V_144 ) ;
V_5 -> type = V_86 ;
} else
V_5 -> V_154 . type = & V_155 ;
}
V_85 = F_17 ( V_5 ) ;
if ( V_85 )
goto remove;
if ( ( V_23 & V_26 ) && V_5 -> V_50 . V_51 ) {
V_85 = F_36 ( V_5 ) ;
if ( V_85 )
goto remove;
F_55 ( V_5 ) ;
} else {
V_85 = F_24 ( V_5 ) ;
if ( V_85 > 0 )
F_56 ( V_5 ) ;
else if ( V_85 )
goto remove;
F_35 ( V_32 , F_26 ( V_5 ) ) ;
V_85 = F_21 ( V_5 ) ;
if ( V_85 > 0 )
F_20 ( V_5 -> V_32 , V_89 ) ;
else if ( V_85 )
goto remove;
}
V_152:
if ( ! V_140 )
V_32 -> V_5 = V_5 ;
return 0 ;
remove:
if ( ! V_140 )
F_45 ( V_5 ) ;
V_85:
return V_85 ;
}
static void F_57 ( struct V_139 * V_32 )
{
int V_156 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
for ( V_156 = 0 ; V_156 < V_32 -> V_5 -> V_157 ; V_156 ++ ) {
if ( V_32 -> V_5 -> V_1 [ V_156 ] ) {
F_11 ( V_32 -> V_5 -> V_1 [ V_156 ] ) ;
V_32 -> V_5 -> V_1 [ V_156 ] = NULL ;
}
}
F_45 ( V_32 -> V_5 ) ;
V_32 -> V_5 = NULL ;
}
static int F_58 ( struct V_139 * V_32 )
{
return F_49 ( V_32 -> V_5 ) ;
}
static void F_59 ( struct V_139 * V_32 )
{
int V_85 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
if ( V_32 -> V_54 & V_158 ) {
V_85 = F_60 ( & V_32 -> V_5 -> V_154 ) ;
if ( V_85 < 0 )
goto V_10;
}
F_61 ( V_32 ) ;
V_85 = F_62 ( V_32 ) ;
F_63 ( V_32 ) ;
if ( V_32 -> V_54 & V_158 )
F_64 ( & V_32 -> V_5 -> V_154 ) ;
V_10:
if ( V_85 ) {
F_57 ( V_32 ) ;
F_61 ( V_32 ) ;
F_65 ( V_32 ) ;
F_66 ( V_32 ) ;
F_63 ( V_32 ) ;
}
}
static int F_67 ( struct V_139 * V_32 )
{
int V_156 , V_85 = 0 ;
for ( V_156 = 0 ; V_156 < V_32 -> V_5 -> V_157 ; V_156 ++ ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_156 ] ;
if ( V_2 && F_68 ( V_2 ) && V_2 -> V_154 . V_159 ) {
const struct V_160 * V_161 = V_2 -> V_154 . V_159 -> V_162 ;
if ( ! V_161 || ! V_161 -> V_163 || ! V_161 -> V_164 ) {
V_85 = - V_165 ;
} else
V_85 = V_161 -> V_163 ( & V_2 -> V_154 ) ;
if ( V_85 )
break;
}
}
while ( V_85 && -- V_156 >= 0 ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_156 ] ;
if ( V_2 && F_68 ( V_2 ) && V_2 -> V_154 . V_159 ) {
const struct V_160 * V_161 = V_2 -> V_154 . V_159 -> V_162 ;
V_161 -> V_164 ( & V_2 -> V_154 ) ;
}
}
if ( ! V_85 && F_69 ( V_32 ) && F_70 ( V_32 ) ) {
F_61 ( V_32 ) ;
F_19 ( V_32 -> V_5 ) ;
F_63 ( V_32 ) ;
}
return V_85 ;
}
static int F_71 ( struct V_139 * V_32 )
{
int V_156 , V_85 = 0 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
F_61 ( V_32 ) ;
if ( F_72 ( V_32 ) || ! F_69 ( V_32 ) )
V_85 = F_38 ( V_32 , V_32 -> V_23 , V_32 -> V_5 ,
F_69 ( V_32 ) ) ;
else if ( F_69 ( V_32 ) && F_70 ( V_32 ) ) {
V_85 = F_21 ( V_32 -> V_5 ) ;
if ( V_85 > 0 ) {
F_20 ( V_32 , V_89 ) ;
V_85 = 0 ;
}
}
if ( ! V_85 && V_32 -> V_166 )
F_73 ( V_32 -> V_167 ) ;
F_63 ( V_32 ) ;
for ( V_156 = 0 ; ! V_85 && V_156 < V_32 -> V_5 -> V_157 ; V_156 ++ ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_156 ] ;
if ( V_2 && F_68 ( V_2 ) && V_2 -> V_154 . V_159 ) {
const struct V_160 * V_161 = V_2 -> V_154 . V_159 -> V_162 ;
V_85 = V_161 -> V_164 ( & V_2 -> V_154 ) ;
}
}
return V_85 ;
}
static int F_74 ( struct V_139 * V_32 )
{
int V_3 ;
T_1 V_23 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
F_61 ( V_32 ) ;
if ( ! F_69 ( V_32 ) )
F_40 ( V_32 , V_143 , 0 ) ;
F_75 ( V_32 ) ;
F_54 ( V_32 ) ;
F_76 ( V_32 , V_32 -> V_168 ) ;
V_3 = F_41 ( V_32 , 0 , & V_23 ) ;
if ( V_3 )
goto V_10;
if ( V_32 -> V_169 )
V_32 -> V_168 = V_32 -> V_169 ;
V_32 -> V_23 = F_77 ( V_32 , V_23 & ~ 0x7F ) ;
if ( ! V_32 -> V_23 ) {
V_3 = - V_33 ;
goto V_10;
}
V_3 = F_38 ( V_32 , V_32 -> V_23 , V_32 -> V_5 ,
F_69 ( V_32 ) ) ;
if ( ! V_3 && V_32 -> V_166 )
F_78 ( V_32 ) ;
V_10:
F_63 ( V_32 ) ;
return V_3 ;
}
int F_79 ( struct V_139 * V_32 )
{
int V_85 , V_156 , V_170 ;
T_1 V_23 ;
struct V_12 * V_5 ;
F_6 ( ! V_32 ) ;
F_39 ( ! V_32 -> V_142 ) ;
V_85 = F_41 ( V_32 , 0 , & V_23 ) ;
if ( V_85 )
return V_85 ;
F_80 ( V_32 , & V_171 ) ;
if ( V_32 -> V_169 )
V_32 -> V_168 = V_32 -> V_169 ;
if ( V_23 & 0x7F ) {
F_16 ( L_3
L_4 ,
F_14 ( V_32 ) ) ;
V_23 &= ~ 0x7F ;
}
V_32 -> V_23 = F_77 ( V_32 , V_23 ) ;
if ( ! V_32 -> V_23 ) {
V_85 = - V_33 ;
goto V_85;
}
V_85 = F_38 ( V_32 , V_32 -> V_23 , NULL , 0 ) ;
if ( V_85 ) {
if ( V_85 == - V_172 ) {
V_32 -> V_23 &= ~ V_26 ;
V_85 = F_38 ( V_32 , V_32 -> V_23 , NULL , 0 ) ;
}
if ( V_85 )
goto V_85;
}
V_5 = V_32 -> V_5 ;
if ( V_32 -> V_54 & V_158 ) {
V_85 = F_81 ( & V_5 -> V_154 ) ;
if ( V_85 )
goto remove;
F_82 ( & V_5 -> V_154 ) ;
}
V_170 = ( V_23 & 0x70000000 ) >> 28 ;
V_5 -> V_157 = 0 ;
for ( V_156 = 0 ; V_156 < V_170 ; V_156 ++ , V_5 -> V_157 ++ ) {
V_85 = F_5 ( V_32 -> V_5 , V_156 + 1 ) ;
if ( V_85 )
goto remove;
if ( V_32 -> V_54 & V_158 )
F_82 ( & V_5 -> V_1 [ V_156 ] -> V_154 ) ;
}
F_63 ( V_32 ) ;
V_85 = F_83 ( V_32 -> V_5 ) ;
if ( V_85 )
goto V_173;
for ( V_156 = 0 ; V_156 < V_170 ; V_156 ++ ) {
V_85 = F_84 ( V_32 -> V_5 -> V_1 [ V_156 ] ) ;
if ( V_85 )
goto V_173;
}
F_61 ( V_32 ) ;
return 0 ;
V_173:
F_57 ( V_32 ) ;
F_61 ( V_32 ) ;
remove:
F_63 ( V_32 ) ;
if ( V_32 -> V_5 )
F_57 ( V_32 ) ;
F_61 ( V_32 ) ;
V_85:
F_65 ( V_32 ) ;
F_13 ( L_5 ,
F_14 ( V_32 ) , V_85 ) ;
return V_85 ;
}
