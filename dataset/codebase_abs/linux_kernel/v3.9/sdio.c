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
if ( F_15 ( V_5 -> V_32 ) ) {
if ( V_4 & V_54 )
V_5 -> V_50 . V_51
|= V_55 ;
if ( V_4 & V_56 )
V_5 -> V_50 . V_51
|= V_57 ;
if ( V_4 & V_58 )
V_5 -> V_50 . V_51
|= V_59 ;
}
V_3 = F_3 ( V_5 , 0 , 0 ,
V_60 , 0 , & V_4 ) ;
if ( V_3 )
goto V_10;
if ( V_4 & V_61 )
V_5 -> V_50 . V_52 |= V_62 ;
if ( V_4 & V_63 )
V_5 -> V_50 . V_52 |= V_64 ;
if ( V_4 & V_65 )
V_5 -> V_50 . V_52 |= V_66 ;
}
if ( ! V_5 -> V_50 . V_51 ) {
if ( V_27 & V_67 ) {
V_5 -> V_28 . V_68 = 1 ;
V_5 -> V_50 . V_69 = 50000000 ;
} else {
V_5 -> V_28 . V_68 = 0 ;
V_5 -> V_50 . V_69 = 25000000 ;
}
}
}
V_10:
return V_3 ;
}
static int F_16 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_70 ;
if ( ! ( V_5 -> V_32 -> V_71 & V_72 ) )
return 0 ;
if ( V_5 -> V_28 . V_39 && ! V_5 -> V_28 . V_41 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_73 , 0 , & V_70 ) ;
if ( V_3 )
return V_3 ;
if ( ( V_70 & V_74 ) == V_75 )
F_17 ( L_2 ,
F_14 ( V_5 -> V_32 ) , V_70 ) ;
V_70 &= ~ V_74 ;
V_70 |= V_76 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_73 , V_70 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_18 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_70 ;
if ( ! F_19 ( V_5 ) )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_73 , 0 , & V_70 ) ;
if ( V_3 )
return V_3 ;
V_70 |= V_77 ;
return F_3 ( V_5 , 1 , 0 , V_73 , V_70 , NULL ) ;
}
static int F_20 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_70 ;
if ( ! ( V_5 -> V_32 -> V_71 & V_72 ) )
return 0 ;
if ( V_5 -> V_28 . V_39 && ! V_5 -> V_28 . V_41 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_73 , 0 , & V_70 ) ;
if ( V_3 )
return V_3 ;
if ( ! ( V_70 & V_76 ) )
return 0 ;
V_70 &= ~ V_76 ;
V_70 |= V_78 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_73 , V_70 , NULL ) ;
if ( V_3 )
return V_3 ;
F_21 ( V_5 -> V_32 , V_79 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_5 )
{
int V_80 ;
if ( V_5 -> type == V_81 )
return F_16 ( V_5 ) ;
if ( ( V_5 -> V_32 -> V_71 & V_72 ) &&
( V_5 -> V_48 . V_82 & V_83 ) ) {
V_80 = F_23 ( V_5 , V_84 ) ;
if ( V_80 )
return V_80 ;
} else
return 0 ;
V_80 = F_16 ( V_5 ) ;
if ( V_80 <= 0 )
F_23 ( V_5 , V_79 ) ;
return V_80 ;
}
static int F_24 ( struct V_12 * V_5 , int V_85 )
{
int V_3 ;
T_2 V_27 ;
if ( ! ( V_5 -> V_32 -> V_71 & V_86 ) )
return 0 ;
if ( ! V_5 -> V_28 . V_68 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_3 )
return V_3 ;
if ( V_85 )
V_27 |= V_87 ;
else
V_27 &= ~ V_87 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_47 , V_27 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_25 ( struct V_12 * V_5 )
{
int V_3 ;
V_3 = F_24 ( V_5 , true ) ;
if ( V_3 <= 0 || V_5 -> type == V_81 )
return V_3 ;
V_3 = F_26 ( V_5 ) ;
if ( V_3 <= 0 )
F_24 ( V_5 , false ) ;
return V_3 ;
}
static unsigned F_27 ( struct V_12 * V_5 )
{
unsigned V_88 ;
if ( F_28 ( V_5 ) ) {
V_88 = 50000000 ;
} else {
V_88 = V_5 -> V_19 . V_88 ;
}
if ( V_5 -> type == V_89 )
V_88 = F_29 ( V_88 , F_30 ( V_5 ) ) ;
return V_88 ;
}
static unsigned char F_31 ( int V_90 )
{
switch ( V_90 ) {
case V_91 :
return V_92 ;
case V_93 :
return V_94 ;
case V_95 :
return V_96 ;
case V_97 :
return V_98 ;
default:
return V_94 ;
}
}
static void F_32 ( struct V_12 * V_5 )
{
int V_99 = V_100 ;
int V_101 = V_100 ;
int V_102 ;
unsigned char V_103 ;
int V_80 ;
if ( ! ( V_5 -> V_32 -> V_71 &
( V_104 |
V_105 |
V_106 ) ) )
return;
if ( ! V_5 -> V_32 -> V_107 -> V_108 )
return;
if ( V_5 -> V_32 -> V_71 & V_104 )
V_99 |= V_62 ;
if ( V_5 -> V_32 -> V_71 & V_105 )
V_99 |= V_64 ;
if ( V_5 -> V_32 -> V_71 & V_106 )
V_99 |= V_66 ;
if ( V_5 -> V_50 . V_52 & V_62 )
V_101 |= V_62 ;
if ( V_5 -> V_50 . V_52 & V_64 )
V_101 |= V_64 ;
if ( V_5 -> V_50 . V_52 & V_66 )
V_101 |= V_66 ;
V_102 = V_5 -> V_32 -> V_107 -> V_108 (
V_5 -> V_50 . V_109 ,
V_99 , V_101 ) ;
V_80 = F_3 ( V_5 , 0 , 0 , V_60 , 0 ,
& V_103 ) ;
if ( V_80 )
return;
V_103 &= ~ ( V_110 << V_111 ) ;
V_103 |= F_31 ( V_102 ) ;
V_80 = F_3 ( V_5 , 1 , 0 , V_60 ,
V_103 , NULL ) ;
if ( ! V_80 )
F_33 ( V_5 -> V_32 , V_102 ) ;
}
static int F_34 ( struct V_12 * V_5 )
{
unsigned int V_112 , V_113 ;
int V_80 ;
unsigned char V_27 ;
if ( ! F_15 ( V_5 -> V_32 ) )
return 0 ;
V_112 = V_114 ;
V_113 = V_115 ;
if ( ( V_5 -> V_32 -> V_71 & V_116 ) &&
( V_5 -> V_50 . V_51 & V_59 ) ) {
V_112 = V_117 ;
V_113 = V_118 ;
V_5 -> V_50 . V_109 = V_119 ;
V_5 -> V_120 = V_121 ;
} else if ( ( V_5 -> V_32 -> V_71 & V_122 ) &&
( V_5 -> V_50 . V_51 & V_55 ) ) {
V_112 = V_123 ;
V_113 = V_124 ;
V_5 -> V_50 . V_109 = V_125 ;
V_5 -> V_120 = V_126 ;
} else if ( ( V_5 -> V_32 -> V_71 & ( V_116 |
V_127 ) ) && ( V_5 -> V_50 . V_51 &
V_57 ) ) {
V_112 = V_128 ;
V_113 = V_129 ;
V_5 -> V_50 . V_109 = V_130 ;
V_5 -> V_120 = V_131 ;
} else if ( ( V_5 -> V_32 -> V_71 & ( V_116 |
V_127 | V_132 ) ) &&
( V_5 -> V_50 . V_51 & V_133 ) ) {
V_112 = V_134 ;
V_113 = V_135 ;
V_5 -> V_50 . V_109 = V_136 ;
V_5 -> V_120 = V_137 ;
} else if ( ( V_5 -> V_32 -> V_71 & ( V_116 |
V_127 | V_132 |
V_138 ) ) && ( V_5 -> V_50 . V_51 &
V_139 ) ) {
V_112 = V_114 ;
V_113 = V_115 ;
V_5 -> V_50 . V_109 = V_140 ;
V_5 -> V_120 = V_141 ;
}
V_80 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_80 )
return V_80 ;
V_27 &= ~ V_142 ;
V_27 |= V_112 ;
V_80 = F_3 ( V_5 , 1 , 0 , V_47 , V_27 , NULL ) ;
if ( V_80 )
return V_80 ;
if ( V_112 ) {
F_35 ( V_5 -> V_32 , V_113 ) ;
F_36 ( V_5 -> V_32 , V_5 -> V_50 . V_109 ) ;
}
return 0 ;
}
static int F_37 ( struct V_12 * V_5 )
{
int V_80 ;
if ( ! V_5 -> V_48 . V_49 )
return 0 ;
if ( V_5 -> V_32 -> V_71 & V_72 ) {
V_80 = F_22 ( V_5 ) ;
if ( V_80 > 0 ) {
F_21 ( V_5 -> V_32 , V_84 ) ;
V_80 = 0 ;
}
}
F_32 ( V_5 ) ;
V_80 = F_34 ( V_5 ) ;
if ( V_80 )
goto V_10;
if ( ! F_38 ( V_5 -> V_32 ) && V_5 -> V_32 -> V_107 -> V_143 )
V_80 = V_5 -> V_32 -> V_107 -> V_143 ( V_5 -> V_32 ,
V_144 ) ;
V_10:
return V_80 ;
}
static int F_39 ( struct V_145 * V_32 , T_1 V_23 ,
struct V_12 * V_146 , int V_147 )
{
struct V_12 * V_5 ;
int V_80 ;
int V_148 = 10 ;
F_6 ( ! V_32 ) ;
F_40 ( ! V_32 -> V_149 ) ;
V_150:
if ( ! V_148 ) {
F_17 ( L_3 ,
F_14 ( V_32 ) ) ;
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
if ( ! V_147 ) {
V_80 = F_41 ( V_32 , V_32 -> V_23 , & V_23 ) ;
if ( V_80 )
goto V_80;
}
if ( F_38 ( V_32 ) ) {
V_80 = F_42 ( V_32 , V_151 ) ;
if ( V_80 )
goto V_80;
}
V_5 = F_43 ( V_32 , NULL ) ;
if ( F_8 ( V_5 ) ) {
V_80 = F_9 ( V_5 ) ;
goto V_80;
}
if ( ( V_23 & V_152 ) &&
F_44 ( V_32 , V_32 -> V_23 & V_23 , V_5 -> V_153 , NULL ) == 0 ) {
V_5 -> type = V_89 ;
if ( V_146 && ( V_146 -> type != V_89 ||
memcmp ( V_5 -> V_153 , V_146 -> V_153 , sizeof( V_5 -> V_153 ) ) != 0 ) ) {
F_45 ( V_5 ) ;
return - V_154 ;
}
} else {
V_5 -> type = V_81 ;
if ( V_146 && V_146 -> type != V_81 ) {
F_45 ( V_5 ) ;
return - V_154 ;
}
}
if ( V_32 -> V_107 -> V_155 )
V_32 -> V_107 -> V_155 ( V_32 , V_5 ) ;
if ( ! V_147 && ( V_23 & V_26 ) && F_15 ( V_32 ) ) {
V_80 = F_46 ( V_32 , V_156 ) ;
if ( V_80 == - V_157 ) {
F_47 ( V_32 ) ;
F_48 ( V_32 ) ;
F_49 ( V_32 , V_32 -> V_158 ) ;
F_45 ( V_5 ) ;
V_148 -- ;
goto V_150;
} else if ( V_80 ) {
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
V_80 = 0 ;
} else {
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
if ( ! V_147 && ! F_38 ( V_32 ) ) {
V_80 = F_50 ( V_32 , & V_5 -> V_159 ) ;
if ( V_80 )
goto remove;
if ( V_146 )
V_146 -> V_159 = V_5 -> V_159 ;
}
if ( ! V_146 && V_5 -> type == V_89 ) {
V_80 = F_51 ( V_32 , V_5 ) ;
if ( V_80 )
return V_80 ;
F_52 ( V_5 ) ;
}
if ( ! V_147 && ! F_38 ( V_32 ) ) {
V_80 = F_53 ( V_5 ) ;
if ( V_80 )
goto remove;
}
if ( V_5 -> V_15 & V_16 ) {
F_36 ( V_32 , V_5 -> V_19 . V_88 ) ;
if ( V_5 -> V_28 . V_68 ) {
F_54 ( V_5 ) ;
F_35 ( V_5 -> V_32 , V_160 ) ;
}
goto V_161;
}
V_80 = F_12 ( V_5 , V_23 ) ;
if ( V_80 )
goto remove;
V_80 = F_55 ( V_5 ) ;
if ( V_80 )
goto remove;
if ( V_146 ) {
int V_162 = ( V_5 -> V_19 . V_18 == V_146 -> V_19 . V_18 &&
V_5 -> V_19 . V_20 == V_146 -> V_19 . V_20 ) ;
F_45 ( V_5 ) ;
if ( ! V_162 )
return - V_154 ;
V_5 = V_146 ;
}
F_56 ( V_5 , NULL ) ;
if ( V_5 -> type == V_89 ) {
V_80 = F_57 ( V_32 , V_5 , V_146 != NULL ) ;
if ( V_80 ) {
F_48 ( V_32 ) ;
if ( F_38 ( V_32 ) )
F_42 ( V_32 , V_151 ) ;
V_5 -> type = V_81 ;
} else
V_5 -> V_163 . type = & V_164 ;
}
V_80 = F_18 ( V_5 ) ;
if ( V_80 )
goto remove;
if ( ( V_23 & V_26 ) && V_5 -> V_50 . V_51 ) {
V_80 = F_37 ( V_5 ) ;
if ( V_80 )
goto remove;
F_58 ( V_5 ) ;
} else {
V_80 = F_25 ( V_5 ) ;
if ( V_80 > 0 )
F_59 ( V_5 ) ;
else if ( V_80 )
goto remove;
F_36 ( V_32 , F_27 ( V_5 ) ) ;
V_80 = F_22 ( V_5 ) ;
if ( V_80 > 0 )
F_21 ( V_5 -> V_32 , V_84 ) ;
else if ( V_80 )
goto remove;
}
V_161:
if ( ! V_146 )
V_32 -> V_5 = V_5 ;
return 0 ;
remove:
if ( ! V_146 )
F_45 ( V_5 ) ;
V_80:
return V_80 ;
}
static void F_60 ( struct V_145 * V_32 )
{
int V_165 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
for ( V_165 = 0 ; V_165 < V_32 -> V_5 -> V_166 ; V_165 ++ ) {
if ( V_32 -> V_5 -> V_1 [ V_165 ] ) {
F_11 ( V_32 -> V_5 -> V_1 [ V_165 ] ) ;
V_32 -> V_5 -> V_1 [ V_165 ] = NULL ;
}
}
F_45 ( V_32 -> V_5 ) ;
V_32 -> V_5 = NULL ;
}
static int F_61 ( struct V_145 * V_32 )
{
return F_53 ( V_32 -> V_5 ) ;
}
static void F_62 ( struct V_145 * V_32 )
{
int V_80 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
if ( V_32 -> V_71 & V_167 ) {
V_80 = F_63 ( & V_32 -> V_5 -> V_163 ) ;
if ( V_80 < 0 )
goto V_10;
}
F_64 ( V_32 ) ;
V_80 = F_65 ( V_32 ) ;
F_66 ( V_32 ) ;
if ( V_32 -> V_71 & V_167 )
F_67 ( & V_32 -> V_5 -> V_163 ) ;
V_10:
if ( V_80 ) {
F_60 ( V_32 ) ;
F_64 ( V_32 ) ;
F_68 ( V_32 ) ;
F_69 ( V_32 ) ;
F_66 ( V_32 ) ;
}
}
static int F_70 ( struct V_145 * V_32 )
{
int V_165 , V_80 = 0 ;
for ( V_165 = 0 ; V_165 < V_32 -> V_5 -> V_166 ; V_165 ++ ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_165 ] ;
if ( V_2 && F_71 ( V_2 ) && V_2 -> V_163 . V_168 ) {
const struct V_169 * V_170 = V_2 -> V_163 . V_168 -> V_171 ;
if ( ! V_170 || ! V_170 -> V_172 || ! V_170 -> V_173 ) {
V_80 = - V_174 ;
} else
V_80 = V_170 -> V_172 ( & V_2 -> V_163 ) ;
if ( V_80 )
break;
}
}
while ( V_80 && -- V_165 >= 0 ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_165 ] ;
if ( V_2 && F_71 ( V_2 ) && V_2 -> V_163 . V_168 ) {
const struct V_169 * V_170 = V_2 -> V_163 . V_168 -> V_171 ;
V_170 -> V_173 ( & V_2 -> V_163 ) ;
}
}
if ( ! V_80 && F_72 ( V_32 ) && F_73 ( V_32 ) ) {
F_64 ( V_32 ) ;
F_20 ( V_32 -> V_5 ) ;
F_66 ( V_32 ) ;
}
return V_80 ;
}
static int F_74 ( struct V_145 * V_32 )
{
int V_165 , V_80 = 0 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
F_64 ( V_32 ) ;
if ( F_75 ( V_32 ) || ! F_72 ( V_32 ) ) {
F_47 ( V_32 ) ;
F_48 ( V_32 ) ;
V_80 = F_39 ( V_32 , V_32 -> V_23 , V_32 -> V_5 ,
F_72 ( V_32 ) ) ;
} else if ( F_72 ( V_32 ) && F_73 ( V_32 ) ) {
V_80 = F_22 ( V_32 -> V_5 ) ;
if ( V_80 > 0 ) {
F_21 ( V_32 , V_84 ) ;
V_80 = 0 ;
}
}
if ( ! V_80 && V_32 -> V_175 )
F_76 ( V_32 -> V_176 ) ;
F_66 ( V_32 ) ;
for ( V_165 = 0 ; ! V_80 && V_165 < V_32 -> V_5 -> V_166 ; V_165 ++ ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_165 ] ;
if ( V_2 && F_71 ( V_2 ) && V_2 -> V_163 . V_168 ) {
const struct V_169 * V_170 = V_2 -> V_163 . V_168 -> V_171 ;
V_80 = V_170 -> V_173 ( & V_2 -> V_163 ) ;
}
}
return V_80 ;
}
static int F_77 ( struct V_145 * V_32 )
{
int V_3 ;
T_1 V_23 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
F_64 ( V_32 ) ;
F_47 ( V_32 ) ;
F_48 ( V_32 ) ;
F_49 ( V_32 , V_32 -> V_158 ) ;
V_3 = F_41 ( V_32 , 0 , & V_23 ) ;
if ( V_3 )
goto V_10;
if ( V_32 -> V_177 )
V_32 -> V_158 = V_32 -> V_177 ;
V_32 -> V_23 = F_78 ( V_32 , V_23 & ~ 0x7F ) ;
if ( ! V_32 -> V_23 ) {
V_3 = - V_33 ;
goto V_10;
}
if ( F_15 ( V_32 ) )
V_32 -> V_23 |= V_26 ;
V_3 = F_39 ( V_32 , V_32 -> V_23 , V_32 -> V_5 ,
F_72 ( V_32 ) ) ;
if ( ! V_3 && V_32 -> V_175 )
F_79 ( V_32 ) ;
V_10:
F_66 ( V_32 ) ;
return V_3 ;
}
int F_80 ( struct V_145 * V_32 )
{
int V_80 , V_165 , V_178 ;
T_1 V_23 ;
struct V_12 * V_5 ;
F_6 ( ! V_32 ) ;
F_40 ( ! V_32 -> V_149 ) ;
V_80 = F_41 ( V_32 , 0 , & V_23 ) ;
if ( V_80 )
return V_80 ;
F_81 ( V_32 , & V_179 ) ;
if ( V_32 -> V_177 )
V_32 -> V_158 = V_32 -> V_177 ;
if ( V_23 & 0x7F ) {
F_17 ( L_4
L_5 ,
F_14 ( V_32 ) ) ;
V_23 &= ~ 0x7F ;
}
V_32 -> V_23 = F_78 ( V_32 , V_23 ) ;
if ( ! V_32 -> V_23 ) {
V_80 = - V_33 ;
goto V_80;
}
if ( F_15 ( V_32 ) )
V_32 -> V_23 |= V_26 ;
V_80 = F_39 ( V_32 , V_32 -> V_23 , NULL , 0 ) ;
if ( V_80 ) {
if ( V_80 == - V_157 ) {
V_32 -> V_23 &= ~ V_26 ;
V_80 = F_39 ( V_32 , V_32 -> V_23 , NULL , 0 ) ;
}
if ( V_80 )
goto V_80;
}
V_5 = V_32 -> V_5 ;
if ( V_32 -> V_71 & V_167 ) {
V_80 = F_82 ( & V_5 -> V_163 ) ;
if ( V_80 )
goto remove;
F_83 ( & V_5 -> V_163 ) ;
}
V_178 = ( V_23 & 0x70000000 ) >> 28 ;
V_5 -> V_166 = 0 ;
for ( V_165 = 0 ; V_165 < V_178 ; V_165 ++ , V_5 -> V_166 ++ ) {
V_80 = F_5 ( V_32 -> V_5 , V_165 + 1 ) ;
if ( V_80 )
goto remove;
if ( V_32 -> V_71 & V_167 )
F_83 ( & V_5 -> V_1 [ V_165 ] -> V_163 ) ;
}
F_66 ( V_32 ) ;
V_80 = F_84 ( V_32 -> V_5 ) ;
if ( V_80 )
goto V_180;
for ( V_165 = 0 ; V_165 < V_178 ; V_165 ++ ) {
V_80 = F_85 ( V_32 -> V_5 -> V_1 [ V_165 ] ) ;
if ( V_80 )
goto V_180;
}
F_64 ( V_32 ) ;
return 0 ;
V_180:
F_60 ( V_32 ) ;
F_64 ( V_32 ) ;
remove:
F_66 ( V_32 ) ;
if ( V_32 -> V_5 )
F_60 ( V_32 ) ;
F_64 ( V_32 ) ;
V_80:
F_68 ( V_32 ) ;
F_13 ( L_6 ,
F_14 ( V_32 ) , V_80 ) ;
return V_80 ;
}
