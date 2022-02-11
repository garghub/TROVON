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
V_76 |= V_79 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_78 , V_76 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_16 ( struct V_12 * V_5 )
{
int V_3 ;
T_2 V_76 ;
if ( ! F_17 ( V_5 ) )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_78 , 0 , & V_76 ) ;
if ( V_3 )
return V_3 ;
V_76 |= V_80 ;
return F_3 ( V_5 , 1 , 0 , V_78 , V_76 , NULL ) ;
}
static int F_18 ( struct V_12 * V_5 )
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
if ( ! ( V_76 & V_79 ) )
return 0 ;
V_76 &= ~ V_79 ;
V_76 |= V_81 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_78 , V_76 , NULL ) ;
if ( V_3 )
return V_3 ;
F_19 ( V_5 -> V_32 , V_82 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_5 )
{
int V_83 ;
if ( V_5 -> type == V_84 )
return F_15 ( V_5 ) ;
if ( ( V_5 -> V_32 -> V_54 & V_77 ) &&
( V_5 -> V_48 . V_85 & V_86 ) ) {
V_83 = F_21 ( V_5 , V_87 ) ;
if ( V_83 )
return V_83 ;
} else
return 0 ;
V_83 = F_15 ( V_5 ) ;
if ( V_83 <= 0 )
F_21 ( V_5 , V_82 ) ;
return V_83 ;
}
static int F_22 ( struct V_12 * V_5 , int V_88 )
{
int V_3 ;
T_2 V_27 ;
if ( ! ( V_5 -> V_32 -> V_54 & V_89 ) )
return 0 ;
if ( ! V_5 -> V_28 . V_74 )
return 0 ;
V_3 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_3 )
return V_3 ;
if ( V_88 )
V_27 |= V_90 ;
else
V_27 &= ~ V_90 ;
V_3 = F_3 ( V_5 , 1 , 0 , V_47 , V_27 , NULL ) ;
if ( V_3 )
return V_3 ;
return 1 ;
}
static int F_23 ( struct V_12 * V_5 )
{
int V_3 ;
V_3 = F_22 ( V_5 , true ) ;
if ( V_3 <= 0 || V_5 -> type == V_84 )
return V_3 ;
V_3 = F_24 ( V_5 ) ;
if ( V_3 <= 0 )
F_22 ( V_5 , false ) ;
return V_3 ;
}
static unsigned F_25 ( struct V_12 * V_5 )
{
unsigned V_91 ;
if ( F_26 ( V_5 ) ) {
V_91 = 50000000 ;
} else {
V_91 = V_5 -> V_19 . V_91 ;
}
if ( V_5 -> type == V_92 )
V_91 = F_27 ( V_91 , F_28 ( V_5 ) ) ;
return V_91 ;
}
static unsigned char F_29 ( int V_93 )
{
switch ( V_93 ) {
case V_94 :
return V_95 ;
case V_96 :
return V_97 ;
case V_98 :
return V_99 ;
case V_100 :
return V_101 ;
default:
return V_97 ;
}
}
static void F_30 ( struct V_12 * V_5 )
{
int V_102 = V_103 ;
int V_104 = V_103 ;
int V_105 ;
unsigned char V_106 ;
int V_83 ;
if ( ! ( V_5 -> V_32 -> V_54 &
( V_107 |
V_108 |
V_109 ) ) )
return;
if ( ! V_5 -> V_32 -> V_110 -> V_111 )
return;
if ( V_5 -> V_32 -> V_54 & V_107 )
V_102 |= V_68 ;
if ( V_5 -> V_32 -> V_54 & V_108 )
V_102 |= V_70 ;
if ( V_5 -> V_32 -> V_54 & V_109 )
V_102 |= V_72 ;
if ( V_5 -> V_50 . V_52 & V_68 )
V_104 |= V_68 ;
if ( V_5 -> V_50 . V_52 & V_70 )
V_104 |= V_70 ;
if ( V_5 -> V_50 . V_52 & V_72 )
V_104 |= V_72 ;
V_105 = V_5 -> V_32 -> V_110 -> V_111 (
V_5 -> V_50 . V_112 ,
V_102 , V_104 ) ;
V_83 = F_3 ( V_5 , 0 , 0 , V_66 , 0 ,
& V_106 ) ;
if ( V_83 )
return;
V_106 &= ~ ( V_113 << V_114 ) ;
V_106 |= F_29 ( V_105 ) ;
V_83 = F_3 ( V_5 , 1 , 0 , V_66 ,
V_106 , NULL ) ;
if ( ! V_83 )
F_31 ( V_5 -> V_32 , V_105 ) ;
}
static int F_32 ( struct V_12 * V_5 )
{
unsigned int V_115 , V_116 ;
int V_83 ;
unsigned char V_27 ;
if ( ! ( V_5 -> V_32 -> V_54 & ( V_55 | V_56 |
V_57 | V_58 | V_59 ) ) )
return 0 ;
V_115 = V_117 ;
V_116 = V_118 ;
if ( ( V_5 -> V_32 -> V_54 & V_58 ) &&
( V_5 -> V_50 . V_51 & V_65 ) ) {
V_115 = V_119 ;
V_116 = V_120 ;
V_5 -> V_50 . V_112 = V_121 ;
} else if ( ( V_5 -> V_32 -> V_54 & V_59 ) &&
( V_5 -> V_50 . V_51 & V_61 ) ) {
V_115 = V_122 ;
V_116 = V_123 ;
V_5 -> V_50 . V_112 = V_124 ;
} else if ( ( V_5 -> V_32 -> V_54 & ( V_58 |
V_57 ) ) && ( V_5 -> V_50 . V_51 &
V_63 ) ) {
V_115 = V_125 ;
V_116 = V_126 ;
V_5 -> V_50 . V_112 = V_127 ;
} else if ( ( V_5 -> V_32 -> V_54 & ( V_58 |
V_57 | V_56 ) ) &&
( V_5 -> V_50 . V_51 & V_128 ) ) {
V_115 = V_129 ;
V_116 = V_130 ;
V_5 -> V_50 . V_112 = V_131 ;
} else if ( ( V_5 -> V_32 -> V_54 & ( V_58 |
V_57 | V_56 |
V_55 ) ) && ( V_5 -> V_50 . V_51 &
V_132 ) ) {
V_115 = V_117 ;
V_116 = V_118 ;
V_5 -> V_50 . V_112 = V_133 ;
}
V_83 = F_3 ( V_5 , 0 , 0 , V_47 , 0 , & V_27 ) ;
if ( V_83 )
return V_83 ;
V_27 &= ~ V_134 ;
V_27 |= V_115 ;
V_83 = F_3 ( V_5 , 1 , 0 , V_47 , V_27 , NULL ) ;
if ( V_83 )
return V_83 ;
if ( V_115 ) {
F_33 ( V_5 -> V_32 , V_116 ) ;
F_34 ( V_5 -> V_32 , V_5 -> V_50 . V_112 ) ;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_5 )
{
int V_83 ;
if ( ! V_5 -> V_48 . V_49 )
return 0 ;
if ( V_5 -> V_32 -> V_54 & V_77 ) {
V_83 = F_20 ( V_5 ) ;
if ( V_83 > 0 ) {
F_19 ( V_5 -> V_32 , V_87 ) ;
V_83 = 0 ;
}
}
F_30 ( V_5 ) ;
V_83 = F_32 ( V_5 ) ;
if ( V_83 )
goto V_10;
if ( ! F_36 ( V_5 -> V_32 ) && V_5 -> V_32 -> V_110 -> V_135 )
V_83 = V_5 -> V_32 -> V_110 -> V_135 ( V_5 -> V_32 ,
V_136 ) ;
V_10:
return V_83 ;
}
static int F_37 ( struct V_137 * V_32 , T_1 V_23 ,
struct V_12 * V_138 , int V_139 )
{
struct V_12 * V_5 ;
int V_83 ;
F_6 ( ! V_32 ) ;
F_38 ( ! V_32 -> V_140 ) ;
if ( ! V_139 ) {
F_39 ( V_32 , V_141 , 0 ) ;
V_83 = F_40 ( V_32 , V_32 -> V_23 , & V_23 ) ;
if ( V_83 )
goto V_83;
}
if ( F_36 ( V_32 ) ) {
V_83 = F_41 ( V_32 , V_142 ) ;
if ( V_83 )
goto V_83;
}
V_5 = F_42 ( V_32 , NULL ) ;
if ( F_8 ( V_5 ) ) {
V_83 = F_9 ( V_5 ) ;
goto V_83;
}
if ( ( V_23 & V_143 ) &&
F_43 ( V_32 , V_32 -> V_23 & V_23 , V_5 -> V_144 , NULL ) == 0 ) {
V_5 -> type = V_92 ;
if ( V_138 && ( V_138 -> type != V_92 ||
memcmp ( V_5 -> V_144 , V_138 -> V_144 , sizeof( V_5 -> V_144 ) ) != 0 ) ) {
F_44 ( V_5 ) ;
return - V_145 ;
}
} else {
V_5 -> type = V_84 ;
if ( V_138 && V_138 -> type != V_84 ) {
F_44 ( V_5 ) ;
return - V_145 ;
}
}
if ( V_32 -> V_110 -> V_146 )
V_32 -> V_110 -> V_146 ( V_32 , V_5 ) ;
if ( ( V_23 & V_26 ) &&
( V_32 -> V_54 &
( V_55 | V_56 |
V_57 | V_58 |
V_59 ) ) ) {
V_83 = F_39 ( V_32 , V_147 ,
true ) ;
if ( V_83 ) {
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
V_83 = 0 ;
} else {
V_23 &= ~ V_26 ;
V_32 -> V_23 &= ~ V_26 ;
}
if ( ! V_139 && ! F_36 ( V_32 ) ) {
V_83 = F_45 ( V_32 , & V_5 -> V_148 ) ;
if ( V_83 )
goto remove;
if ( V_138 )
V_138 -> V_148 = V_5 -> V_148 ;
}
if ( ! V_138 && V_5 -> type == V_92 ) {
V_83 = F_46 ( V_32 , V_5 ) ;
if ( V_83 )
return V_83 ;
F_47 ( V_5 ) ;
}
if ( ! V_139 && ! F_36 ( V_32 ) ) {
V_83 = F_48 ( V_5 ) ;
if ( V_83 )
goto remove;
}
if ( V_5 -> V_15 & V_16 ) {
F_34 ( V_32 , V_5 -> V_19 . V_91 ) ;
if ( V_5 -> V_28 . V_74 ) {
F_49 ( V_5 ) ;
F_33 ( V_5 -> V_32 , V_149 ) ;
}
goto V_150;
}
V_83 = F_12 ( V_5 , V_23 ) ;
if ( V_83 )
goto remove;
V_83 = F_50 ( V_5 ) ;
if ( V_83 )
goto remove;
if ( V_138 ) {
int V_151 = ( V_5 -> V_19 . V_18 == V_138 -> V_19 . V_18 &&
V_5 -> V_19 . V_20 == V_138 -> V_19 . V_20 ) ;
F_44 ( V_5 ) ;
if ( ! V_151 )
return - V_145 ;
V_5 = V_138 ;
}
F_51 ( V_5 , NULL ) ;
if ( V_5 -> type == V_92 ) {
V_83 = F_52 ( V_32 , V_5 , V_138 != NULL ) ;
if ( V_83 ) {
F_53 ( V_32 ) ;
if ( F_36 ( V_32 ) )
F_41 ( V_32 , V_142 ) ;
V_5 -> type = V_84 ;
} else
V_5 -> V_152 . type = & V_153 ;
}
V_83 = F_16 ( V_5 ) ;
if ( V_83 )
goto remove;
if ( ( V_23 & V_26 ) && V_5 -> V_50 . V_51 ) {
V_83 = F_35 ( V_5 ) ;
if ( V_83 )
goto remove;
F_54 ( V_5 ) ;
} else {
V_83 = F_23 ( V_5 ) ;
if ( V_83 > 0 )
F_55 ( V_5 ) ;
else if ( V_83 )
goto remove;
F_34 ( V_32 , F_25 ( V_5 ) ) ;
V_83 = F_20 ( V_5 ) ;
if ( V_83 > 0 )
F_19 ( V_5 -> V_32 , V_87 ) ;
else if ( V_83 )
goto remove;
}
V_150:
if ( ! V_138 )
V_32 -> V_5 = V_5 ;
return 0 ;
remove:
if ( ! V_138 )
F_44 ( V_5 ) ;
V_83:
return V_83 ;
}
static void F_56 ( struct V_137 * V_32 )
{
int V_154 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
for ( V_154 = 0 ; V_154 < V_32 -> V_5 -> V_155 ; V_154 ++ ) {
if ( V_32 -> V_5 -> V_1 [ V_154 ] ) {
F_11 ( V_32 -> V_5 -> V_1 [ V_154 ] ) ;
V_32 -> V_5 -> V_1 [ V_154 ] = NULL ;
}
}
F_44 ( V_32 -> V_5 ) ;
V_32 -> V_5 = NULL ;
}
static int F_57 ( struct V_137 * V_32 )
{
return F_48 ( V_32 -> V_5 ) ;
}
static void F_58 ( struct V_137 * V_32 )
{
int V_83 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
if ( V_32 -> V_54 & V_156 ) {
V_83 = F_59 ( & V_32 -> V_5 -> V_152 ) ;
if ( V_83 < 0 )
goto V_10;
}
F_60 ( V_32 ) ;
V_83 = F_61 ( V_32 ) ;
F_62 ( V_32 ) ;
if ( V_32 -> V_54 & V_156 )
F_63 ( & V_32 -> V_5 -> V_152 ) ;
V_10:
if ( V_83 ) {
F_56 ( V_32 ) ;
F_60 ( V_32 ) ;
F_64 ( V_32 ) ;
F_65 ( V_32 ) ;
F_62 ( V_32 ) ;
}
}
static int F_66 ( struct V_137 * V_32 )
{
int V_154 , V_83 = 0 ;
for ( V_154 = 0 ; V_154 < V_32 -> V_5 -> V_155 ; V_154 ++ ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_154 ] ;
if ( V_2 && F_67 ( V_2 ) && V_2 -> V_152 . V_157 ) {
const struct V_158 * V_159 = V_2 -> V_152 . V_157 -> V_160 ;
if ( ! V_159 || ! V_159 -> V_161 || ! V_159 -> V_162 ) {
V_83 = - V_163 ;
} else
V_83 = V_159 -> V_161 ( & V_2 -> V_152 ) ;
if ( V_83 )
break;
}
}
while ( V_83 && -- V_154 >= 0 ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_154 ] ;
if ( V_2 && F_67 ( V_2 ) && V_2 -> V_152 . V_157 ) {
const struct V_158 * V_159 = V_2 -> V_152 . V_157 -> V_160 ;
V_159 -> V_162 ( & V_2 -> V_152 ) ;
}
}
if ( ! V_83 && F_68 ( V_32 ) && F_69 ( V_32 ) ) {
F_60 ( V_32 ) ;
F_18 ( V_32 -> V_5 ) ;
F_62 ( V_32 ) ;
}
return V_83 ;
}
static int F_70 ( struct V_137 * V_32 )
{
int V_154 , V_83 = 0 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
F_60 ( V_32 ) ;
if ( F_71 ( V_32 ) || ! F_68 ( V_32 ) )
V_83 = F_37 ( V_32 , V_32 -> V_23 , V_32 -> V_5 ,
F_68 ( V_32 ) ) ;
else if ( F_68 ( V_32 ) && F_69 ( V_32 ) ) {
V_83 = F_20 ( V_32 -> V_5 ) ;
if ( V_83 > 0 ) {
F_19 ( V_32 , V_87 ) ;
V_83 = 0 ;
}
}
if ( ! V_83 && V_32 -> V_164 )
F_72 ( V_32 ) ;
F_62 ( V_32 ) ;
for ( V_154 = 0 ; ! V_83 && V_154 < V_32 -> V_5 -> V_155 ; V_154 ++ ) {
struct V_1 * V_2 = V_32 -> V_5 -> V_1 [ V_154 ] ;
if ( V_2 && F_67 ( V_2 ) && V_2 -> V_152 . V_157 ) {
const struct V_158 * V_159 = V_2 -> V_152 . V_157 -> V_160 ;
V_83 = V_159 -> V_162 ( & V_2 -> V_152 ) ;
}
}
return V_83 ;
}
static int F_73 ( struct V_137 * V_32 )
{
int V_3 ;
T_1 V_23 ;
F_6 ( ! V_32 ) ;
F_6 ( ! V_32 -> V_5 ) ;
F_60 ( V_32 ) ;
if ( ! F_68 ( V_32 ) )
F_39 ( V_32 , V_141 , 0 ) ;
F_74 ( V_32 ) ;
F_53 ( V_32 ) ;
F_75 ( V_32 , V_32 -> V_165 ) ;
V_3 = F_40 ( V_32 , 0 , & V_23 ) ;
if ( V_3 )
goto V_10;
if ( V_32 -> V_166 )
V_32 -> V_165 = V_32 -> V_166 ;
V_32 -> V_23 = F_76 ( V_32 , V_23 & ~ 0x7F ) ;
if ( ! V_32 -> V_23 ) {
V_3 = - V_33 ;
goto V_10;
}
V_3 = F_37 ( V_32 , V_32 -> V_23 , V_32 -> V_5 ,
F_68 ( V_32 ) ) ;
if ( ! V_3 && V_32 -> V_164 )
F_72 ( V_32 ) ;
V_10:
F_62 ( V_32 ) ;
return V_3 ;
}
int F_77 ( struct V_137 * V_32 )
{
int V_83 , V_154 , V_167 ;
T_1 V_23 ;
struct V_12 * V_5 ;
F_6 ( ! V_32 ) ;
F_38 ( ! V_32 -> V_140 ) ;
V_83 = F_40 ( V_32 , 0 , & V_23 ) ;
if ( V_83 )
return V_83 ;
F_78 ( V_32 , & V_168 ) ;
if ( V_32 -> V_166 )
V_32 -> V_165 = V_32 -> V_166 ;
if ( V_23 & 0x7F ) {
F_79 ( L_2
L_3 ,
F_14 ( V_32 ) ) ;
V_23 &= ~ 0x7F ;
}
V_32 -> V_23 = F_76 ( V_32 , V_23 ) ;
if ( ! V_32 -> V_23 ) {
V_83 = - V_33 ;
goto V_83;
}
V_83 = F_37 ( V_32 , V_32 -> V_23 , NULL , 0 ) ;
if ( V_83 ) {
if ( V_83 == - V_169 ) {
V_32 -> V_23 &= ~ V_26 ;
V_83 = F_37 ( V_32 , V_32 -> V_23 , NULL , 0 ) ;
}
if ( V_83 )
goto V_83;
}
V_5 = V_32 -> V_5 ;
if ( V_32 -> V_54 & V_156 ) {
V_83 = F_80 ( & V_5 -> V_152 ) ;
if ( V_83 )
goto remove;
F_81 ( & V_5 -> V_152 ) ;
}
V_167 = ( V_23 & 0x70000000 ) >> 28 ;
V_5 -> V_155 = 0 ;
for ( V_154 = 0 ; V_154 < V_167 ; V_154 ++ , V_5 -> V_155 ++ ) {
V_83 = F_5 ( V_32 -> V_5 , V_154 + 1 ) ;
if ( V_83 )
goto remove;
if ( V_32 -> V_54 & V_156 )
F_81 ( & V_5 -> V_1 [ V_154 ] -> V_152 ) ;
}
F_62 ( V_32 ) ;
V_83 = F_82 ( V_32 -> V_5 ) ;
if ( V_83 )
goto V_170;
for ( V_154 = 0 ; V_154 < V_167 ; V_154 ++ ) {
V_83 = F_83 ( V_32 -> V_5 -> V_1 [ V_154 ] ) ;
if ( V_83 )
goto V_170;
}
F_60 ( V_32 ) ;
return 0 ;
V_170:
F_56 ( V_32 ) ;
F_60 ( V_32 ) ;
remove:
F_62 ( V_32 ) ;
if ( V_32 -> V_5 )
F_56 ( V_32 ) ;
F_60 ( V_32 ) ;
V_83:
F_64 ( V_32 ) ;
F_13 ( L_4 ,
F_14 ( V_32 ) , V_83 ) ;
return V_83 ;
}
