static int F_1 ( T_1 V_1 )
{
static const int V_2 [] = {
[ V_3 ] = - V_4 ,
[ V_5 ] = - V_6 ,
[ V_7 ] = - V_8 ,
[ V_9 ] = - V_10 ,
[ V_11 ] = - V_12 ,
[ V_13 ] = - V_14 ,
[ V_15 ] = - V_16 ,
[ V_17 ] = - V_12 ,
[ V_18 ] = - V_12 ,
[ V_19 ] = - V_20 ,
[ V_21 ] = - V_22 ,
[ V_23 ] = - V_8 ,
[ V_24 ] = - V_20 ,
[ V_25 ] = - V_14 ,
[ V_26 ] = - V_27 ,
[ V_28 ] = - V_8 ,
[ V_29 ] = - V_16 ,
[ V_30 ] = - V_31 ,
} ;
if ( V_1 >= F_2 ( V_2 ) ||
( V_1 != V_32 && V_2 [ V_1 ] == 0 ) )
return - V_4 ;
return V_2 [ V_1 ] ;
}
static T_1 F_3 ( int V_33 )
{
switch ( V_33 ) {
case - V_6 :
return V_5 ;
case - V_8 :
return V_7 ;
case - V_10 :
return V_9 ;
case - V_14 :
return V_13 ;
case - V_16 :
return V_15 ;
case - V_22 :
return V_21 ;
default:
return V_3 ;
}
}
static int F_4 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
T_2 V_1 = F_5 ( & V_37 -> V_38 . V_39 -> V_40 ) ;
return ( F_6 ( V_1 ) >> 31 ) != V_37 -> V_41 . V_42 ;
}
static void F_7 ( struct V_34 * V_35 , T_1 V_41 , T_3 V_43 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
T_2 V_44 ;
V_37 -> V_41 . V_42 ^= 1 ;
V_44 = V_43 | ( V_41 << 16 ) | ( V_37 -> V_41 . V_42 << 31 ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_44 ) ,
& V_37 -> V_38 . V_39 -> V_46 ) ;
F_10 () ;
}
static int F_11 ( struct V_34 * V_35 , T_1 V_41 , T_3 V_43 ,
unsigned long V_47 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
unsigned long V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
if ( F_4 ( V_35 ) ) {
F_12 ( V_35 , L_1 ,
V_37 -> V_41 . V_42 , V_41 ) ;
return - V_27 ;
}
F_13 ( & V_37 -> V_41 . V_51 ) ;
F_7 ( V_35 , V_41 , V_43 ) ;
V_48 = F_14 ( V_47 ) + V_52 ;
while ( F_4 ( V_35 ) && F_15 ( V_52 , V_48 ) )
F_16 () ;
V_50 = F_4 ( V_35 ) ;
if ( V_50 ) {
if ( ( V_53 == V_41 ) ) {
V_49 = V_54 ;
} else {
F_12 ( V_35 , L_2 ) ;
V_49 = - V_55 ;
}
}
F_17 ( & V_37 -> V_41 . V_51 ) ;
return V_49 ;
}
static int F_18 ( struct V_34 * V_35 , T_1 V_56 ,
T_3 V_43 , unsigned long V_47 )
{
struct V_57 * V_41 = & V_36 ( V_35 ) -> V_41 ;
struct V_58 * V_59 ;
unsigned long V_48 ;
int V_49 = 0 ;
F_13 ( & V_41 -> V_60 ) ;
F_19 ( & V_41 -> V_61 ) ;
F_20 ( V_41 -> V_62 < 0 ) ;
V_59 = & V_41 -> V_59 [ V_41 -> V_62 ] ;
V_59 -> V_63 += V_41 -> V_64 + 1 ;
V_41 -> V_62 = V_59 -> V_65 ;
F_21 ( & V_41 -> V_61 ) ;
F_22 ( & V_59 -> V_66 ) ;
F_7 ( V_35 , V_56 , V_43 ) ;
if ( ! F_23 ( & V_59 -> V_66 ,
F_14 ( V_47 ) ) ) {
F_12 ( V_35 , L_3 ,
V_56 ) ;
V_49 = - V_14 ;
goto V_67;
}
V_49 = V_59 -> V_68 ;
if ( V_49 && V_59 -> V_69 != V_30 ) {
F_24 ( V_35 , L_4 ,
V_56 , V_59 -> V_69 ) ;
goto V_67;
}
V_67:
V_48 = F_14 ( V_47 ) + V_52 ;
while ( F_4 ( V_35 ) && F_15 ( V_52 , V_48 ) )
F_16 () ;
F_19 ( & V_41 -> V_61 ) ;
V_59 -> V_65 = V_41 -> V_62 ;
V_41 -> V_62 = V_59 - V_41 -> V_59 ;
F_21 ( & V_41 -> V_61 ) ;
F_17 ( & V_41 -> V_60 ) ;
return V_49 ;
}
int F_25 ( struct V_34 * V_35 , T_1 V_41 , T_3 V_43 ,
unsigned long V_47 )
{
if ( V_36 ( V_35 ) -> V_41 . V_70 )
return F_18 ( V_35 , V_41 , V_43 , V_47 ) ;
return F_11 ( V_35 , V_41 , V_43 , V_47 ) ;
}
static int F_26 ( struct V_34 * V_35 )
{
T_2 V_1 ;
if ( F_27 ( V_35 -> V_71 ) )
return - V_4 ;
V_1 = F_5 ( V_36 ( V_35 ) -> V_41 . V_72 + V_73 ) ;
return ( V_1 & F_6 ( 1 << V_74 ) ) ||
( V_36 ( V_35 ) -> V_41 . V_75 ==
! ! ( V_1 & F_6 ( 1 << V_76 ) ) ) ;
}
static int F_28 ( struct V_34 * V_35 , T_4 V_77 , T_4 V_78 ,
T_2 V_79 , T_1 V_80 , T_3 V_56 , T_3 V_63 ,
int V_81 )
{
struct V_57 * V_41 = & V_36 ( V_35 ) -> V_41 ;
T_2 T_5 * V_72 = V_41 -> V_72 ;
int V_82 = - V_27 ;
unsigned long V_48 ;
F_29 ( & V_41 -> V_83 ) ;
if ( F_27 ( V_35 -> V_71 ) ) {
V_82 = - V_4 ;
goto V_67;
}
V_48 = V_52 ;
if ( V_81 )
V_48 += F_14 ( V_84 ) ;
while ( F_26 ( V_35 ) ) {
if ( F_27 ( V_35 -> V_71 ) ) {
V_82 = - V_4 ;
goto V_67;
}
if ( F_30 ( V_52 , V_48 ) ) {
F_24 ( V_35 , L_5 , V_85 ) ;
goto V_67;
}
F_16 () ;
}
F_8 ( ( V_45 T_2 ) F_9 ( V_77 >> 32 ) , V_72 + 0 ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_77 & 0xfffffffful ) , V_72 + 1 ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_79 ) , V_72 + 2 ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_78 >> 32 ) , V_72 + 3 ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_78 & 0xfffffffful ) , V_72 + 4 ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_63 << 16 ) , V_72 + 5 ) ;
F_31 () ;
F_8 ( ( V_45 T_2 ) F_9 ( ( 1 << V_74 ) |
( V_41 -> V_75 << V_76 ) |
( V_81 ? ( 1 << V_86 ) : 0 ) |
( V_80 << V_87 ) |
V_56 ) , V_72 + 6 ) ;
F_10 () ;
V_41 -> V_75 = V_41 -> V_75 ^ 1 ;
V_82 = 0 ;
V_67:
F_32 ( & V_41 -> V_83 ) ;
return V_82 ;
}
static int F_33 ( struct V_34 * V_35 , T_4 V_77 , T_4 * V_78 ,
int V_88 , T_2 V_79 , T_1 V_80 ,
T_3 V_56 , unsigned long V_47 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_89 * V_90 = V_37 -> V_38 . V_90 ;
int V_82 ;
F_29 ( & V_37 -> V_41 . V_91 ) ;
V_90 -> V_77 = F_34 ( V_77 ) ;
V_90 -> V_78 = V_78 ? F_34 ( * V_78 ) : 0 ;
V_90 -> V_79 = F_9 ( V_79 ) ;
V_90 -> V_92 = F_35 ( ( ( ( T_3 ) V_80 ) << 12 ) | ( V_56 & 0xfff ) ) ;
V_90 -> V_63 = F_35 ( V_93 ) ;
V_90 -> V_1 = 0 ;
V_90 -> V_94 = ! ! ( V_37 -> V_41 . V_70 ) << 6 ;
if ( F_36 ( V_35 ) ) {
V_82 = F_37 ( V_35 , V_35 -> V_95 . V_96 , V_90 ) ;
if ( ! V_82 ) {
if ( V_88 ) {
if ( V_78 )
* V_78 =
F_38 ( V_90 -> V_78 ) ;
else {
F_24 ( V_35 , L_6 ,
V_56 ) ;
V_90 -> V_1 = V_7 ;
}
}
V_82 = F_1 ( V_90 -> V_1 ) ;
}
} else {
V_82 = F_25 ( V_35 , V_97 , 0 ,
V_98 + V_47 ) ;
if ( ! V_82 ) {
if ( V_88 ) {
if ( V_78 )
* V_78 =
F_38 ( V_90 -> V_78 ) ;
else {
F_24 ( V_35 , L_6 ,
V_56 ) ;
V_90 -> V_1 = V_7 ;
}
}
V_82 = F_1 ( V_90 -> V_1 ) ;
} else
F_24 ( V_35 , L_7 ,
V_56 ) ;
}
F_32 ( & V_37 -> V_41 . V_91 ) ;
return V_82 ;
}
static int F_39 ( struct V_34 * V_35 , T_4 V_77 , T_4 * V_78 ,
int V_88 , T_2 V_79 , T_1 V_80 ,
T_3 V_56 , unsigned long V_47 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
void T_5 * V_72 = V_37 -> V_41 . V_72 ;
int V_49 = 0 ;
unsigned long V_48 ;
T_2 V_99 ;
F_13 ( & V_37 -> V_41 . V_51 ) ;
if ( F_27 ( V_35 -> V_71 ) ) {
V_49 = - V_4 ;
goto V_67;
}
if ( V_88 && ! V_78 ) {
F_24 ( V_35 , L_6 ,
V_56 ) ;
V_49 = - V_8 ;
goto V_67;
}
V_49 = F_28 ( V_35 , V_77 , V_78 ? * V_78 : 0 ,
V_79 , V_80 , V_56 , V_93 , 0 ) ;
if ( V_49 )
goto V_67;
V_48 = F_14 ( V_47 ) + V_52 ;
while ( F_26 ( V_35 ) && F_15 ( V_52 , V_48 ) ) {
if ( F_27 ( V_35 -> V_71 ) ) {
V_49 = - V_4 ;
goto V_67;
}
F_16 () ;
}
if ( F_26 ( V_35 ) ) {
F_12 ( V_35 , L_8 ,
V_56 ) ;
V_49 = - V_55 ;
goto V_67;
}
if ( V_88 )
* V_78 =
( T_4 ) F_40 ( ( V_45 V_100 )
F_41 ( V_72 + V_101 ) ) << 32 |
( T_4 ) F_40 ( ( V_45 V_100 )
F_41 ( V_72 + V_101 + 4 ) ) ;
V_99 = F_40 ( ( V_45 V_100 )
F_41 ( V_72 + V_73 ) ) >> 24 ;
V_49 = F_1 ( V_99 ) ;
if ( V_49 )
F_24 ( V_35 , L_4 ,
V_56 , V_99 ) ;
V_67:
F_17 ( & V_37 -> V_41 . V_51 ) ;
return V_49 ;
}
void F_42 ( struct V_34 * V_35 , T_3 V_63 , T_1 V_1 , T_4 V_78 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_58 * V_59 =
& V_37 -> V_41 . V_59 [ V_63 & V_37 -> V_41 . V_64 ] ;
if ( V_63 != V_59 -> V_63 )
return;
V_59 -> V_69 = V_1 ;
V_59 -> V_68 = F_1 ( V_1 ) ;
V_59 -> V_78 = V_78 ;
F_43 ( & V_59 -> V_66 ) ;
}
static int F_44 ( struct V_34 * V_35 , T_4 V_77 , T_4 * V_78 ,
int V_88 , T_2 V_79 , T_1 V_80 ,
T_3 V_56 , unsigned long V_47 )
{
struct V_57 * V_41 = & V_36 ( V_35 ) -> V_41 ;
struct V_58 * V_59 ;
int V_49 = 0 ;
F_13 ( & V_41 -> V_60 ) ;
F_19 ( & V_41 -> V_61 ) ;
F_20 ( V_41 -> V_62 < 0 ) ;
V_59 = & V_41 -> V_59 [ V_41 -> V_62 ] ;
V_59 -> V_63 += V_41 -> V_64 + 1 ;
V_41 -> V_62 = V_59 -> V_65 ;
F_21 ( & V_41 -> V_61 ) ;
if ( V_88 && ! V_78 ) {
F_24 ( V_35 , L_6 ,
V_56 ) ;
V_49 = - V_8 ;
goto V_67;
}
F_22 ( & V_59 -> V_66 ) ;
F_28 ( V_35 , V_77 , V_78 ? * V_78 : 0 ,
V_79 , V_80 , V_56 , V_59 -> V_63 , 1 ) ;
if ( ! F_23 ( & V_59 -> V_66 ,
F_14 ( V_47 ) ) ) {
F_12 ( V_35 , L_8 ,
V_56 ) ;
V_49 = - V_14 ;
goto V_67;
}
V_49 = V_59 -> V_68 ;
if ( V_49 ) {
if ( V_56 == V_102 && V_79 == 1 &&
V_80 == 0 && V_59 -> V_69 == V_29 )
F_45 ( V_35 , L_4 ,
V_56 , V_59 -> V_69 ) ;
else
F_24 ( V_35 , L_4 ,
V_56 , V_59 -> V_69 ) ;
goto V_67;
}
if ( V_88 )
* V_78 = V_59 -> V_78 ;
V_67:
F_19 ( & V_41 -> V_61 ) ;
V_59 -> V_65 = V_41 -> V_62 ;
V_41 -> V_62 = V_59 - V_41 -> V_59 ;
F_21 ( & V_41 -> V_61 ) ;
F_17 ( & V_41 -> V_60 ) ;
return V_49 ;
}
int F_46 ( struct V_34 * V_35 , T_4 V_77 , T_4 * V_78 ,
int V_88 , T_2 V_79 , T_1 V_80 ,
T_3 V_56 , unsigned long V_47 , int V_103 )
{
if ( F_27 ( V_35 -> V_71 ) )
return - V_4 ;
if ( ! F_47 ( V_35 ) || ( V_103 && F_36 ( V_35 ) ) ) {
if ( V_36 ( V_35 ) -> V_41 . V_70 )
return F_44 ( V_35 , V_77 , V_78 ,
V_88 , V_79 ,
V_80 , V_56 , V_47 ) ;
else
return F_39 ( V_35 , V_77 , V_78 ,
V_88 , V_79 ,
V_80 , V_56 , V_47 ) ;
}
return F_33 ( V_35 , V_77 , V_78 , V_88 ,
V_79 , V_80 , V_56 , V_47 ) ;
}
static int F_48 ( struct V_34 * V_35 )
{
return V_57 ( V_35 , 0 , 0 , 0 , V_104 ,
V_105 , V_106 ) ;
}
static int F_49 ( struct V_34 * V_35 , T_4 V_107 ,
int V_108 , T_4 V_109 ,
int V_110 , int V_111 )
{
T_4 V_77 ;
T_4 V_78 ;
if ( ( V_109 & 0xfff ) | ( V_107 & 0xfff ) |
( V_108 & ~ 0x7f ) | ( V_110 & 0xff ) ) {
F_24 ( V_35 , L_9 ,
V_109 , V_107 , V_108 , V_110 ) ;
return - V_8 ;
}
if ( V_111 ) {
V_77 = ( T_4 ) V_108 | V_109 ;
V_78 = ( T_4 ) V_35 -> V_95 . V_96 | V_107 ;
} else {
V_77 = ( T_4 ) V_35 -> V_95 . V_96 | V_107 ;
V_78 = ( T_4 ) V_108 | V_109 ;
}
return F_50 ( V_35 , V_77 , & V_78 , V_110 , 0 ,
V_112 ,
V_113 , V_106 ) ;
}
static int F_51 ( struct V_34 * V_35 , T_1 V_114 , T_3 V_115 , T_3 * V_116 ,
struct V_117 * V_118 ,
struct V_117 * V_119 )
{
struct V_120 * V_121 = (struct V_120 * ) ( V_118 -> V_122 ) ;
struct V_120 * V_123 = (struct V_120 * ) ( V_119 -> V_122 ) ;
int V_49 ;
int V_124 ;
if ( V_115 & 0x1f )
return - V_8 ;
V_121 -> V_125 = F_9 ( V_115 / 32 ) ;
V_49 = F_52 ( V_35 , V_118 -> V_126 , V_119 -> V_126 , V_114 , 3 ,
V_127 , V_128 ,
V_106 ) ;
if ( V_49 )
return V_49 ;
for ( V_124 = 0 ; V_124 < 32 ; ++ V_124 )
V_116 [ V_124 ] = F_53 ( ( ( V_129 * ) V_123 -> V_130 ) [ V_124 ] ) ;
return V_49 ;
}
static int F_54 ( struct V_34 * V_35 , T_1 V_114 , T_3 * V_131 ,
struct V_117 * V_118 ,
struct V_117 * V_119 )
{
int V_124 ;
int V_49 ;
for ( V_124 = 0 ; V_124 < V_35 -> V_95 . V_132 [ V_114 ] ; V_124 += 32 ) {
V_49 = F_51 ( V_35 , V_114 , V_124 , V_131 + V_124 , V_118 , V_119 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static enum V_133 F_55 ( struct V_34 * V_35 , int V_114 , int V_134 )
{
if ( F_56 ( V_35 , V_134 , V_114 ) == V_135 )
return V_136 ;
else
return V_137 ;
}
static int F_57 ( struct V_34 * V_35 , int V_108 ,
struct V_138 * V_90 ,
struct V_117 * V_118 ,
struct V_117 * V_119 ,
struct V_139 * V_41 )
{
struct V_120 * V_140 = V_118 -> V_122 ;
T_2 V_115 ;
T_1 V_114 ;
T_1 V_141 ;
T_3 * V_131 ;
int V_49 ;
int V_142 , V_143 ;
int V_144 ;
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_120 * V_145 = V_119 -> V_122 ;
V_129 * V_146 = ( V_129 * ) ( V_145 -> V_130 ) ;
V_100 V_147 ;
T_6 V_148 ;
V_114 = V_90 -> V_79 ;
V_141 = V_90 -> V_80 & ~ 0x8 ;
V_144 = ! ! ( V_90 -> V_80 & 0x8 ) ;
if ( V_140 -> V_149 == 1 &&
V_140 -> V_150 == V_151 &&
V_140 -> V_152 == 1 ) {
if ( ! V_144 && V_140 -> V_153 == V_154 ) {
if ( V_140 -> V_155 == V_156 ) {
V_115 = F_40 ( V_140 -> V_125 ) ;
if ( V_114 < 1 || V_114 > V_35 -> V_95 . V_157 )
return - V_8 ;
V_131 = F_58 ( V_35 -> V_95 . V_132 [ V_114 ] , sizeof *V_131 , V_158 ) ;
if ( ! V_131 )
return - V_16 ;
V_49 = F_54 ( V_35 , V_114 , V_131 , V_118 , V_119 ) ;
if ( ! V_49 ) {
for ( V_142 = V_115 * 32 ; V_142 < ( V_115 + 1 ) * 32 ; ++ V_142 ) {
V_143 = V_37 -> V_159 [ V_108 ] [ V_114 - 1 ] [ V_142 ] ;
V_146 [ V_142 % 32 ] = F_35 ( V_131 [ V_143 ] ) ;
}
}
F_59 ( V_131 ) ;
return V_49 ;
}
if ( V_140 -> V_155 == V_160 ) {
V_49 = F_52 ( V_35 , V_118 -> V_126 , V_119 -> V_126 ,
V_90 -> V_79 , V_141 ,
V_90 -> V_56 , V_128 , V_106 ) ;
if ( ! V_49 && V_108 != F_60 ( V_35 ) ) {
T_1 * V_161 = V_145 -> V_130 + V_162 ;
* V_161 = ( * V_161 & 0xf0 ) | F_55 ( V_35 , V_114 , V_108 ) ;
V_147 = V_37 -> V_38 . V_163 . V_164 [ V_108 ] . V_165 [ V_114 ] ;
memcpy ( V_145 -> V_130 + V_166 , & V_147 , 4 ) ;
}
return V_49 ;
}
if ( V_140 -> V_155 == V_167 ) {
V_140 -> V_125 = F_9 ( V_108 / 8 ) ;
V_49 = F_52 ( V_35 , V_118 -> V_126 , V_119 -> V_126 ,
V_90 -> V_79 , V_141 ,
V_90 -> V_56 , V_128 , V_106 ) ;
if ( ! V_49 ) {
if ( V_108 % 8 )
memcpy ( V_145 -> V_130 ,
V_145 -> V_130 + ( V_108 % 8 ) * 8 , 8 ) ;
memset ( V_145 -> V_130 + 8 , 0 , 56 ) ;
}
return V_49 ;
}
if ( V_140 -> V_155 == V_168 ) {
V_49 = F_52 ( V_35 , V_118 -> V_126 , V_119 -> V_126 ,
V_90 -> V_79 , V_141 ,
V_90 -> V_56 , V_128 , V_106 ) ;
if ( ! V_49 ) {
V_148 = F_61 ( V_35 , V_108 ) ;
memcpy ( V_145 -> V_130 + 12 , & V_148 , 8 ) ;
}
return V_49 ;
}
}
}
if ( V_108 != F_60 ( V_35 ) &&
! F_62 ( V_35 , V_108 , V_114 ) ) {
if ( ! ( V_140 -> V_150 == V_151 &&
V_140 -> V_153 == V_154 ) || V_144 ) {
F_24 ( V_35 , L_10 ,
V_108 , V_140 -> V_153 , V_140 -> V_150 ,
V_144 ? L_11 : L_12 ,
F_53 ( V_140 -> V_155 ) ) ;
return - V_6 ;
}
}
return F_52 ( V_35 , V_118 -> V_126 , V_119 -> V_126 ,
V_90 -> V_79 , V_141 ,
V_90 -> V_56 , V_128 , V_106 ) ;
}
static int F_63 ( struct V_34 * V_35 , int V_108 ,
struct V_138 * V_90 ,
struct V_117 * V_118 ,
struct V_117 * V_119 ,
struct V_139 * V_41 )
{
return - V_6 ;
}
int F_64 ( struct V_34 * V_35 , int V_108 ,
struct V_138 * V_90 ,
struct V_117 * V_118 ,
struct V_117 * V_119 ,
struct V_139 * V_41 )
{
T_4 V_77 ;
T_4 V_78 ;
int V_49 ;
V_77 = V_41 -> V_169 ? ( T_4 ) V_118 -> V_126 : V_90 -> V_77 ;
V_78 = V_41 -> V_170 ? ( T_4 ) V_119 -> V_126 : V_90 -> V_78 ;
if ( V_41 -> V_171 ) {
V_77 &= 0xffffffffffffff00ll ;
V_77 |= V_108 ;
}
V_49 = F_46 ( V_35 , V_77 , & V_78 , V_41 -> V_88 ,
V_90 -> V_79 , V_90 -> V_80 , V_90 -> V_56 ,
V_113 , V_106 ) ;
if ( V_41 -> V_88 )
V_90 -> V_78 = V_78 ;
return V_49 ;
}
static int F_37 ( struct V_34 * V_35 , int V_108 ,
struct V_89 * V_172 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_139 * V_41 = NULL ;
struct V_89 * V_173 = V_172 ? V_172 : V_37 -> V_38 . V_90 ;
struct V_138 * V_90 ;
struct V_117 * V_118 = NULL ;
struct V_117 * V_119 = NULL ;
T_4 V_77 ;
T_4 V_78 ;
int V_82 = 0 ;
int V_124 ;
int V_49 = 0 ;
V_90 = F_65 ( sizeof( struct V_138 ) , V_158 ) ;
if ( ! V_90 )
return - V_16 ;
if ( ! V_172 ) {
V_82 = F_49 ( V_35 , V_37 -> V_38 . V_174 , V_108 ,
V_37 -> V_38 . V_163 . V_164 [ V_108 ] . V_174 ,
F_66 ( sizeof( struct V_89 ) ,
V_175 ) , 1 ) ;
if ( V_82 ) {
F_24 ( V_35 , L_13 ,
V_85 , V_82 ) ;
F_59 ( V_90 ) ;
return V_82 ;
}
}
V_90 -> V_77 = F_38 ( V_173 -> V_77 ) ;
V_90 -> V_78 = F_38 ( V_173 -> V_78 ) ;
V_90 -> V_79 = F_40 ( V_173 -> V_79 ) ;
V_90 -> V_63 = F_53 ( V_173 -> V_63 ) ;
V_90 -> V_56 = F_53 ( V_173 -> V_92 ) & 0xfff ;
V_90 -> V_80 = ( T_1 ) ( F_53 ( V_173 -> V_92 ) >> 12 ) ;
V_90 -> V_176 = V_173 -> V_94 & ( 1 << 6 ) ;
for ( V_124 = 0 ; V_124 < F_2 ( V_177 ) ; ++ V_124 ) {
if ( V_90 -> V_56 == V_177 [ V_124 ] . V_92 ) {
V_41 = & V_177 [ V_124 ] ;
break;
}
}
if ( ! V_41 ) {
F_24 ( V_35 , L_14 ,
V_90 -> V_56 , V_108 ) ;
V_173 -> V_1 = V_7 ;
goto V_178;
}
if ( V_41 -> V_169 ) {
V_90 -> V_77 &= V_179 ;
V_118 = F_67 ( V_35 ) ;
if ( F_68 ( V_118 ) ) {
V_173 -> V_1 = V_29 ;
V_118 = NULL ;
goto V_178;
}
if ( F_49 ( V_35 , V_118 -> V_126 , V_108 ,
V_90 -> V_77 ,
V_180 , 1 ) ) {
F_24 ( V_35 , L_15 ,
V_85 , V_41 -> V_92 ) ;
V_173 -> V_1 = V_3 ;
goto V_178;
}
}
if ( V_41 -> V_181 && V_41 -> V_181 ( V_35 , V_108 , V_90 , V_118 ) ) {
F_12 ( V_35 , L_16 ,
V_90 -> V_56 , V_108 , V_90 -> V_79 ) ;
V_173 -> V_1 = V_5 ;
goto V_178;
}
if ( V_41 -> V_170 ) {
V_119 = F_67 ( V_35 ) ;
if ( F_68 ( V_119 ) ) {
V_173 -> V_1 = V_29 ;
V_119 = NULL ;
goto V_178;
}
}
if ( V_41 -> V_182 ) {
V_49 = V_41 -> V_182 ( V_35 , V_108 , V_90 , V_118 , V_119 ,
V_41 ) ;
if ( V_41 -> V_88 )
V_173 -> V_78 = F_34 ( V_90 -> V_78 ) ;
} else {
V_77 = V_41 -> V_169 ? ( T_4 ) V_118 -> V_126 :
V_90 -> V_77 ;
V_78 = V_41 -> V_170 ? ( T_4 ) V_119 -> V_126 :
V_90 -> V_78 ;
V_49 = F_46 ( V_35 , V_77 , & V_78 ,
V_41 -> V_88 , V_90 -> V_79 ,
V_90 -> V_80 , V_90 -> V_56 ,
V_113 ,
V_106 ) ;
if ( V_41 -> V_88 ) {
V_90 -> V_78 = V_78 ;
V_173 -> V_78 = F_34 ( V_90 -> V_78 ) ;
}
}
if ( V_49 ) {
F_12 ( V_35 , L_17 ,
V_90 -> V_56 , V_108 , V_90 -> V_33 , V_49 ) ;
V_173 -> V_1 = F_3 ( V_49 ) ;
goto V_178;
}
if ( V_41 -> V_170 && ! V_173 -> V_1 ) {
V_82 = F_49 ( V_35 , V_119 -> V_126 , V_108 ,
V_90 -> V_78 ,
V_180 , V_183 ) ;
if ( V_82 ) {
F_24 ( V_35 , L_18 , V_85 ) ;
goto V_67;
}
}
V_178:
if ( ! V_172 ) {
V_82 = F_49 ( V_35 , V_37 -> V_38 . V_174 , V_108 ,
V_37 -> V_38 . V_163 . V_164 [ V_108 ] . V_174 ,
F_66 ( sizeof( struct V_138 ) ,
V_175 ) ,
V_183 ) ;
if ( V_82 )
F_24 ( V_35 , L_19 ,
V_85 ) ;
else if ( V_90 -> V_176 &&
F_69 ( V_35 , V_108 , & V_37 -> V_38 . V_163 . V_184 ) )
F_12 ( V_35 , L_20 ,
V_108 ) ;
}
V_67:
F_59 ( V_90 ) ;
F_70 ( V_35 , V_118 ) ;
F_70 ( V_35 , V_119 ) ;
return V_82 ;
}
static int F_71 ( struct V_36 * V_37 ,
int V_108 , int V_114 )
{
struct V_185 * V_186 ;
struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_34 * V_35 = & ( V_37 -> V_35 ) ;
int V_49 ;
int V_191 = V_192 ;
V_186 = & V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_194 [ V_114 ] ;
V_188 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
if ( V_186 -> V_161 . V_196 == V_188 -> V_196 &&
V_186 -> V_161 . V_197 == V_188 -> V_197 &&
V_186 -> V_161 . V_198 == V_188 -> V_198 )
return 0 ;
if ( ! ( V_37 -> V_38 . V_163 . V_164 [ V_108 ] . V_199 &&
V_35 -> V_95 . V_200 & V_201 ) ) {
V_186 -> V_161 . V_198 = V_188 -> V_198 ;
return - 1 ;
}
F_45 ( V_35 , L_21 ,
V_108 , V_114 ) ;
F_45 ( V_35 , L_22 ,
V_188 -> V_196 , V_188 -> V_197 ,
V_188 -> V_198 ) ;
V_190 = F_65 ( sizeof( * V_190 ) , V_158 ) ;
if ( ! V_190 )
return - V_16 ;
if ( V_186 -> V_161 . V_196 != V_188 -> V_196 ) {
if ( V_202 != V_188 -> V_196 ) {
V_49 = F_72 ( & V_37 -> V_35 , V_114 ,
V_188 -> V_196 ,
& V_191 ) ;
if ( V_49 ) {
F_59 ( V_190 ) ;
F_12 ( & V_37 -> V_35 ,
L_23 ,
V_108 , V_114 ) ;
return V_49 ;
}
} else {
V_191 = V_192 ;
}
V_190 -> V_94 |= V_203 ;
F_45 ( & V_37 -> V_35 ,
L_24 ,
( int ) ( V_188 -> V_196 ) ,
V_191 , V_108 , V_114 ) ;
}
V_190 -> V_204 = V_186 -> V_161 . V_196 ;
V_190 -> V_205 = V_186 -> V_206 ;
if ( V_186 -> V_161 . V_197 != V_188 -> V_197 )
V_190 -> V_94 |= V_207 ;
if ( V_190 -> V_94 & V_203 )
V_186 -> V_206 = V_191 ;
V_186 -> V_161 . V_196 = V_188 -> V_196 ;
V_186 -> V_161 . V_197 = V_188 -> V_197 ;
V_186 -> V_161 . V_198 = V_188 -> V_198 ;
if ( V_188 -> V_198 == V_208 )
V_190 -> V_94 |= V_209 ;
V_190 -> V_114 = V_114 ;
V_190 -> V_108 = V_108 ;
V_190 -> V_210 = V_186 -> V_161 . V_197 ;
V_190 -> V_211 = V_186 -> V_161 . V_196 ;
V_190 -> V_212 = V_186 -> V_206 ;
V_190 -> V_37 = V_37 ;
F_73 ( & V_190 -> V_190 , V_213 ) ;
F_74 ( V_37 -> V_38 . V_163 . V_214 , & V_190 -> V_190 ) ;
return 0 ;
}
static int F_75 ( struct V_36 * V_37 , int V_108 )
{
int V_114 , V_49 ;
struct V_187 * V_188 ;
struct V_185 * V_186 ;
struct V_215 V_216 = F_76 (
& V_37 -> V_35 , V_108 ) ;
int V_217 = F_77 ( V_216 . V_218 ,
V_37 -> V_35 . V_95 . V_157 ) + 1 ;
int V_219 = V_217 - 1 +
F_78 ( V_216 . V_218 , V_37 -> V_35 . V_95 . V_157 ) ;
for ( V_114 = V_217 ; V_114 <= V_219 ; V_114 ++ ) {
if ( ! F_79 ( V_114 - 1 , V_216 . V_218 ) )
continue;
V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_220 [ V_114 ] =
V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_221 [ V_114 ] ;
V_186 = & V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_194 [ V_114 ] ;
V_188 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
V_186 -> V_161 = * V_188 ;
if ( V_202 != V_188 -> V_196 ) {
V_49 = F_72 ( & V_37 -> V_35 , V_114 ,
V_188 -> V_196 , & ( V_186 -> V_206 ) ) ;
if ( V_49 ) {
V_186 -> V_206 = V_192 ;
F_12 ( & V_37 -> V_35 ,
L_23 ,
V_108 , V_114 ) ;
return V_49 ;
}
F_45 ( & V_37 -> V_35 , L_24 ,
( int ) ( V_186 -> V_161 . V_196 ) ,
V_186 -> V_206 , V_108 , V_114 ) ;
}
if ( V_188 -> V_222 ) {
V_186 -> V_223 = F_80 ( & V_37 -> V_35 ,
V_114 ,
V_188 -> V_224 ) ;
if ( 0 > V_186 -> V_223 ) {
V_49 = V_186 -> V_223 ;
V_186 -> V_223 = V_192 ;
F_12 ( & V_37 -> V_35 ,
L_25 ,
V_108 , V_114 ) ;
return V_49 ;
}
F_45 ( & V_37 -> V_35 , L_26 ,
V_186 -> V_161 . V_224 , V_186 -> V_223 , V_108 , V_114 ) ;
}
}
return 0 ;
}
static void F_81 ( struct V_36 * V_37 , int V_108 )
{
int V_114 ;
struct V_185 * V_186 ;
struct V_215 V_216 = F_76 (
& V_37 -> V_35 , V_108 ) ;
int V_217 = F_77 ( V_216 . V_218 ,
V_37 -> V_35 . V_95 . V_157 ) + 1 ;
int V_219 = V_217 - 1 +
F_78 ( V_216 . V_218 , V_37 -> V_35 . V_95 . V_157 ) ;
for ( V_114 = V_217 ; V_114 <= V_219 ; V_114 ++ ) {
if ( ! F_79 ( V_114 - 1 , V_216 . V_218 ) )
continue;
V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_220 [ V_114 ] =
V_225 ;
V_186 = & V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_194 [ V_114 ] ;
if ( V_192 != V_186 -> V_206 ) {
F_82 ( & V_37 -> V_35 ,
V_114 , V_186 -> V_161 . V_196 ) ;
V_186 -> V_206 = V_192 ;
}
if ( V_192 != V_186 -> V_223 ) {
F_83 ( & V_37 -> V_35 , V_114 , V_186 -> V_161 . V_224 ) ;
V_186 -> V_223 = V_192 ;
}
}
return;
}
static void F_84 ( struct V_34 * V_35 , int V_108 , T_1 V_41 ,
T_3 V_43 , T_1 V_75 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_226 * V_164 = V_37 -> V_38 . V_163 . V_164 ;
T_2 V_227 ;
T_1 V_228 = 0 ;
int V_124 ;
unsigned long V_94 ;
V_164 [ V_108 ] . V_42 ^= 1 ;
V_227 = ( T_2 ) V_164 [ V_108 ] . V_42 << 31 ;
if ( V_75 != V_164 [ V_108 ] . V_42 ) {
F_12 ( V_35 , L_27 ,
V_75 , V_108 ) ;
goto V_229;
}
if ( V_41 == V_53 ) {
F_12 ( V_35 , L_28 , V_108 ) ;
V_164 [ V_108 ] . V_199 = false ;
V_164 [ V_108 ] . V_230 = false ;
F_81 ( V_37 , V_108 ) ;
for ( V_124 = 0 ; V_124 < V_231 ; ++ V_124 ) {
V_164 [ V_108 ] . V_232 [ V_124 ] . V_233 = - 1 ;
V_164 [ V_108 ] . V_232 [ V_124 ] . V_63 = 0 ;
}
if ( V_234 == V_164 [ V_108 ] . V_235 )
goto V_236;
F_85 ( V_35 , V_237 , V_108 ) ;
V_227 |= F_86 () ;
goto V_229;
}
if ( V_41 != V_53 &&
V_234 == V_164 [ V_108 ] . V_235 ) {
F_12 ( V_35 , L_29 ,
V_108 , V_41 ) ;
return;
}
switch ( V_41 ) {
case V_238 :
if ( V_164 [ V_108 ] . V_235 != V_53 )
goto V_229;
V_164 [ V_108 ] . V_174 = ( ( T_4 ) V_43 ) << 48 ;
V_37 -> V_38 . V_163 . V_164 [ V_108 ] . V_239 = 0 ;
F_87 ( & V_37 -> V_38 . V_163 . V_240 [ V_108 ] ) ;
break;
case V_241 :
if ( V_164 [ V_108 ] . V_235 != V_238 )
goto V_229;
V_164 [ V_108 ] . V_174 |= ( ( T_4 ) V_43 ) << 32 ;
break;
case V_242 :
if ( V_164 [ V_108 ] . V_235 != V_241 )
goto V_229;
V_164 [ V_108 ] . V_174 |= ( ( T_4 ) V_43 ) << 16 ;
break;
case V_243 :
if ( V_164 [ V_108 ] . V_235 != V_242 )
goto V_229;
V_164 [ V_108 ] . V_174 |= V_43 ;
if ( F_75 ( V_37 , V_108 ) )
goto V_229;
V_164 [ V_108 ] . V_199 = true ;
F_85 ( V_35 , V_244 , V_108 ) ;
break;
case V_97 :
if ( ( V_164 [ V_108 ] . V_235 != V_243 ) &&
( V_164 [ V_108 ] . V_235 != V_97 ) )
goto V_229;
F_29 ( & V_37 -> V_41 . V_91 ) ;
if ( F_37 ( V_35 , V_108 , NULL ) ) {
F_24 ( V_35 , L_30 ,
V_108 ) ;
F_32 ( & V_37 -> V_41 . V_91 ) ;
goto V_229;
}
F_32 ( & V_37 -> V_41 . V_91 ) ;
break;
default:
F_12 ( V_35 , L_31 , V_41 , V_108 ) ;
goto V_229;
}
F_88 ( & V_37 -> V_38 . V_163 . V_245 , V_94 ) ;
if ( ! V_164 [ V_108 ] . V_246 )
V_164 [ V_108 ] . V_235 = V_41 ;
else
V_228 = 1 ;
F_89 ( & V_37 -> V_38 . V_163 . V_245 , V_94 ) ;
if ( V_228 ) {
F_12 ( V_35 , L_32 ,
V_41 , V_108 ) ;
return;
}
F_8 ( ( V_45 T_2 ) F_9 ( V_227 ) ,
& V_37 -> V_38 . V_39 [ V_108 ] . V_40 ) ;
F_10 () ;
return;
V_229:
F_90 ( V_35 , V_108 ) ;
F_88 ( & V_37 -> V_38 . V_163 . V_245 , V_94 ) ;
if ( ! V_164 [ V_108 ] . V_246 )
V_164 [ V_108 ] . V_235 = V_53 ;
F_89 ( & V_37 -> V_38 . V_163 . V_245 , V_94 ) ;
V_236:
memset ( & V_164 [ V_108 ] . V_232 , 0 ,
sizeof( struct V_247 ) ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_227 ) ,
& V_37 -> V_38 . V_39 [ V_108 ] . V_40 ) ;
F_31 () ;
}
void F_91 ( struct V_248 * V_190 )
{
struct V_249 * V_163 =
F_92 ( V_190 ,
struct V_249 ,
V_250 ) ;
struct V_251 * V_38 =
F_92 ( V_163 , struct V_251 , V_163 ) ;
struct V_36 * V_37 =
F_92 ( V_38 , struct V_36 , V_38 ) ;
struct V_34 * V_35 = & V_37 -> V_35 ;
V_100 * V_252 ;
T_2 V_253 ;
T_2 V_254 ;
int V_124 , V_255 , V_108 ;
int V_75 ;
int V_256 = 0 ;
int V_257 = 0 ;
T_2 V_258 ;
V_252 = V_163 -> V_259 ;
for ( V_124 = 0 ; V_124 < V_260 ; V_124 ++ ) {
V_254 = F_40 ( V_252 [ V_124 ] ) ;
for ( V_255 = 0 ; V_255 < 32 ; V_255 ++ ) {
if ( ! ( V_254 & ( 1 << V_255 ) ) )
continue;
++ V_257 ;
V_108 = ( V_124 * 32 ) + V_255 ;
V_253 = F_6 ( F_5 (
& V_38 -> V_39 [ V_108 ] . V_46 ) ) ;
V_258 = F_6 ( F_5 ( & V_38 -> V_39 [ V_108 ] . V_40 ) )
>> 31 ;
V_75 = V_253 >> 31 ;
if ( V_75 != V_258 ) {
if ( V_163 -> V_164 [ V_108 ] . V_42
!= V_258 ) {
F_93 ( L_33 ,
V_108 , V_258 ,
V_163 -> V_164 [ V_108 ] . V_42 ) ;
V_163 -> V_164 [ V_108 ] . V_42 =
V_258 ;
}
F_84 ( V_35 , V_108 ,
V_253 >> 16 & 0xff ,
V_253 & 0xffff , V_75 ) ;
++ V_256 ;
}
}
}
if ( V_257 && V_257 != V_256 )
F_12 ( V_35 , L_34 ,
V_257 , V_256 ) ;
if ( F_48 ( V_35 ) )
F_12 ( V_35 , L_35 ) ;
}
static int F_94 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_261 ;
int V_262 ;
unsigned long V_48 ;
V_261 = F_6 ( F_5 ( & V_37 -> V_38 . V_39 -> V_46 ) ) >> 31 ;
V_48 = V_52 + F_14 ( 5000 ) ;
while ( F_15 ( V_52 , V_48 ) ) {
V_262 = F_6 ( F_5 ( & V_37 -> V_38 . V_39 -> V_40 ) ) >> 31 ;
if ( V_262 == V_261 ) {
V_37 -> V_41 . V_42 = V_262 ;
return 0 ;
}
F_16 () ;
}
F_12 ( V_35 , L_36 ) ;
F_8 ( ( V_45 T_2 ) 0 , & V_37 -> V_38 . V_39 -> V_40 ) ;
F_8 ( ( V_45 T_2 ) 0 , & V_37 -> V_38 . V_39 -> V_46 ) ;
V_37 -> V_41 . V_42 = 0 ;
return 0 ;
}
int F_95 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_226 * V_263 ;
int V_124 , V_255 , V_49 , V_114 ;
if ( F_36 ( V_35 ) )
V_37 -> V_38 . V_39 =
F_96 ( F_97 ( V_35 -> V_71 , V_37 -> V_264 . V_265 ) +
V_37 -> V_264 . V_266 , V_267 ) ;
else
V_37 -> V_38 . V_39 =
F_96 ( F_97 ( V_35 -> V_71 , 2 ) +
V_268 , V_267 ) ;
if ( ! V_37 -> V_38 . V_39 ) {
F_24 ( V_35 , L_37 ) ;
goto V_269;
}
if ( F_36 ( V_35 ) ) {
V_37 -> V_38 . V_163 . V_164 =
F_65 ( V_35 -> V_270 *
sizeof( struct V_226 ) , V_158 ) ;
if ( ! V_37 -> V_38 . V_163 . V_164 )
goto V_271;
V_37 -> V_38 . V_163 . V_195 =
F_65 ( V_35 -> V_270 *
sizeof( struct V_272 ) , V_158 ) ;
if ( ! V_37 -> V_38 . V_163 . V_195 )
goto V_273;
V_37 -> V_38 . V_163 . V_193 =
F_65 ( V_35 -> V_270 *
sizeof( struct V_274 ) , V_158 ) ;
if ( ! V_37 -> V_38 . V_163 . V_193 )
goto V_275;
for ( V_124 = 0 ; V_124 < V_35 -> V_270 ; ++ V_124 ) {
V_263 = & V_37 -> V_38 . V_163 . V_164 [ V_124 ] ;
V_263 -> V_235 = V_53 ;
for ( V_255 = 0 ; V_255 < V_231 ; ++ V_255 )
V_263 -> V_232 [ V_255 ] . V_233 = - 1 ;
F_8 ( ( V_45 T_2 ) 0 ,
& V_37 -> V_38 . V_39 [ V_124 ] . V_46 ) ;
F_8 ( ( V_45 T_2 ) 0 ,
& V_37 -> V_38 . V_39 [ V_124 ] . V_40 ) ;
F_10 () ;
for ( V_114 = 1 ; V_114 <= V_276 ; V_114 ++ ) {
V_263 -> V_277 [ V_114 ] =
F_65 ( sizeof( struct V_278 ) ,
V_158 ) ;
if ( ! V_263 -> V_277 [ V_114 ] ) {
if ( -- V_114 )
F_59 ( V_263 -> V_277 [ V_114 ] ) ;
goto V_279;
}
F_98 ( & V_263 -> V_280 [ V_114 ] ) ;
V_37 -> V_38 . V_163 . V_195 [ V_124 ] . V_194 [ V_114 ] . V_196 = V_202 ;
V_37 -> V_38 . V_163 . V_193 [ V_124 ] . V_194 [ V_114 ] . V_161 . V_196 = V_202 ;
V_37 -> V_38 . V_163 . V_193 [ V_124 ] . V_194 [ V_114 ] . V_206 = V_192 ;
V_37 -> V_38 . V_163 . V_193 [ V_124 ] . V_194 [ V_114 ] . V_223 = V_192 ;
}
F_99 ( & V_263 -> V_281 ) ;
}
memset ( & V_37 -> V_38 . V_163 . V_184 , 0 , V_35 -> V_95 . V_282 ) ;
V_37 -> V_38 . V_163 . V_184 . type = V_283 ;
F_73 ( & V_37 -> V_38 . V_163 . V_250 ,
F_91 ) ;
F_73 ( & V_37 -> V_38 . V_163 . V_284 ,
V_285 ) ;
F_73 ( & V_37 -> V_38 . V_163 . V_286 ,
V_287 ) ;
F_99 ( & V_37 -> V_38 . V_163 . V_245 ) ;
F_99 ( & V_37 -> V_38 . V_163 . V_288 . V_289 ) ;
V_37 -> V_38 . V_163 . V_214 =
F_100 ( L_38 ) ;
if ( ! V_37 -> V_38 . V_163 . V_214 )
goto V_279;
if ( F_101 ( V_35 ) )
goto V_290;
V_49 = F_48 ( V_35 ) ;
if ( V_49 ) {
F_24 ( V_35 , L_39 ,
V_49 ) ;
goto V_291;
}
} else {
V_49 = F_94 ( V_35 ) ;
if ( V_49 ) {
F_24 ( V_35 , L_40 ) ;
goto V_271;
}
}
return 0 ;
V_291:
F_102 ( V_35 , V_292 ) ;
V_290:
F_103 ( V_37 -> V_38 . V_163 . V_214 ) ;
F_104 ( V_37 -> V_38 . V_163 . V_214 ) ;
V_279:
while ( -- V_124 ) {
for ( V_114 = 1 ; V_114 <= V_276 ; V_114 ++ )
F_59 ( V_37 -> V_38 . V_163 . V_164 [ V_124 ] . V_277 [ V_114 ] ) ;
}
F_59 ( V_37 -> V_38 . V_163 . V_193 ) ;
V_275:
F_59 ( V_37 -> V_38 . V_163 . V_195 ) ;
V_273:
F_59 ( V_37 -> V_38 . V_163 . V_164 ) ;
V_271:
F_105 ( V_37 -> V_38 . V_39 ) ;
V_269:
F_106 ( & ( V_35 -> V_71 -> V_35 ) , V_293 ,
V_37 -> V_38 . V_90 ,
V_37 -> V_38 . V_174 ) ;
V_37 -> V_38 . V_90 = NULL ;
return - V_16 ;
}
int F_107 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
F_87 ( & V_37 -> V_41 . V_83 ) ;
F_87 ( & V_37 -> V_41 . V_91 ) ;
F_108 ( & V_37 -> V_41 . V_51 , 1 ) ;
V_37 -> V_41 . V_70 = 0 ;
V_37 -> V_41 . V_75 = 1 ;
V_37 -> V_41 . V_72 = NULL ;
V_37 -> V_38 . V_90 = NULL ;
if ( ! F_109 ( V_35 ) ) {
V_37 -> V_41 . V_72 = F_96 ( F_97 ( V_35 -> V_71 , 0 ) +
V_294 , V_295 ) ;
if ( ! V_37 -> V_41 . V_72 ) {
F_24 ( V_35 , L_41 ) ;
return - V_16 ;
}
}
if ( F_47 ( V_35 ) ) {
V_37 -> V_38 . V_90 = F_110 ( & ( V_35 -> V_71 -> V_35 ) , V_293 ,
& V_37 -> V_38 . V_174 ,
V_158 ) ;
if ( ! V_37 -> V_38 . V_90 )
goto V_296;
}
V_37 -> V_41 . V_297 = F_111 ( L_42 , V_35 -> V_71 ,
V_180 ,
V_180 , 0 ) ;
if ( ! V_37 -> V_41 . V_297 )
goto V_269;
return 0 ;
V_269:
if ( F_47 ( V_35 ) )
F_106 ( & ( V_35 -> V_71 -> V_35 ) , V_293 ,
V_37 -> V_38 . V_90 , V_37 -> V_38 . V_174 ) ;
V_37 -> V_38 . V_90 = NULL ;
V_296:
if ( ! F_109 ( V_35 ) )
F_105 ( V_37 -> V_41 . V_72 ) ;
return - V_16 ;
}
void F_112 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_124 , V_114 ;
if ( F_36 ( V_35 ) ) {
F_103 ( V_37 -> V_38 . V_163 . V_214 ) ;
F_104 ( V_37 -> V_38 . V_163 . V_214 ) ;
for ( V_124 = 0 ; V_124 < V_35 -> V_270 ; V_124 ++ ) {
for ( V_114 = 1 ; V_114 <= V_276 ; V_114 ++ )
F_59 ( V_37 -> V_38 . V_163 . V_164 [ V_124 ] . V_277 [ V_114 ] ) ;
}
F_59 ( V_37 -> V_38 . V_163 . V_164 ) ;
F_59 ( V_37 -> V_38 . V_163 . V_195 ) ;
F_59 ( V_37 -> V_38 . V_163 . V_193 ) ;
}
F_105 ( V_37 -> V_38 . V_39 ) ;
}
void F_113 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
F_114 ( V_37 -> V_41 . V_297 ) ;
if ( ! F_109 ( V_35 ) )
F_105 ( V_37 -> V_41 . V_72 ) ;
if ( F_47 ( V_35 ) )
F_106 ( & ( V_35 -> V_71 -> V_35 ) , V_293 ,
V_37 -> V_38 . V_90 , V_37 -> V_38 . V_174 ) ;
V_37 -> V_38 . V_90 = NULL ;
}
int F_115 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_124 ;
int V_49 = 0 ;
V_37 -> V_41 . V_59 = F_116 ( V_37 -> V_41 . V_298 *
sizeof ( struct V_58 ) ,
V_158 ) ;
if ( ! V_37 -> V_41 . V_59 )
return - V_16 ;
for ( V_124 = 0 ; V_124 < V_37 -> V_41 . V_298 ; ++ V_124 ) {
V_37 -> V_41 . V_59 [ V_124 ] . V_63 = V_124 ;
V_37 -> V_41 . V_59 [ V_124 ] . V_65 = V_124 + 1 ;
}
V_37 -> V_41 . V_59 [ V_37 -> V_41 . V_298 - 1 ] . V_65 = - 1 ;
V_37 -> V_41 . V_62 = 0 ;
F_108 ( & V_37 -> V_41 . V_60 , V_37 -> V_41 . V_298 ) ;
F_99 ( & V_37 -> V_41 . V_61 ) ;
for ( V_37 -> V_41 . V_64 = 1 ;
V_37 -> V_41 . V_64 < V_37 -> V_41 . V_298 ;
V_37 -> V_41 . V_64 <<= 1 )
;
-- V_37 -> V_41 . V_64 ;
F_13 ( & V_37 -> V_41 . V_51 ) ;
V_37 -> V_41 . V_70 = 1 ;
return V_49 ;
}
void F_117 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_124 ;
V_37 -> V_41 . V_70 = 0 ;
for ( V_124 = 0 ; V_124 < V_37 -> V_41 . V_298 ; ++ V_124 )
F_13 ( & V_37 -> V_41 . V_60 ) ;
F_59 ( V_37 -> V_41 . V_59 ) ;
F_17 ( & V_37 -> V_41 . V_51 ) ;
}
struct V_117 * F_67 ( struct V_34 * V_35 )
{
struct V_117 * V_299 ;
V_299 = F_116 ( sizeof *V_299 , V_158 ) ;
if ( ! V_299 )
return F_118 ( - V_16 ) ;
V_299 -> V_122 = F_119 ( V_36 ( V_35 ) -> V_41 . V_297 , V_158 ,
& V_299 -> V_126 ) ;
if ( ! V_299 -> V_122 ) {
F_59 ( V_299 ) ;
return F_118 ( - V_16 ) ;
}
memset ( V_299 -> V_122 , 0 , V_180 ) ;
return V_299 ;
}
void F_70 ( struct V_34 * V_35 ,
struct V_117 * V_299 )
{
if ( ! V_299 )
return;
F_120 ( V_36 ( V_35 ) -> V_41 . V_297 , V_299 -> V_122 , V_299 -> V_126 ) ;
F_59 ( V_299 ) ;
}
T_2 F_86 ( void )
{
return ( ( T_2 ) V_300 << 8 ) | ( T_2 ) V_301 ;
}
static int F_121 ( struct V_34 * V_35 , int V_134 )
{
if ( ( V_134 < 0 ) || ( V_134 >= V_35 -> V_302 ) ) {
F_24 ( V_35 , L_43 , V_134 , V_35 -> V_302 ) ;
return - V_8 ;
}
return V_134 + 1 ;
}
int F_122 ( struct V_34 * V_35 , int V_108 )
{
if ( V_108 < 1 || V_108 > V_35 -> V_302 ) {
F_24 ( V_35 ,
L_44 ,
V_108 , V_35 -> V_270 ) ;
return - V_8 ;
}
return V_108 - 1 ;
}
struct V_215 F_76 ( struct V_34 * V_35 , int V_108 )
{
struct V_215 V_216 ;
int V_134 ;
F_123 ( V_216 . V_218 , V_276 ) ;
if ( V_108 == 0 ) {
F_124 ( V_216 . V_218 , V_35 -> V_95 . V_157 ) ;
return V_216 ;
}
V_134 = F_122 ( V_35 , V_108 ) ;
if ( V_134 < 0 )
return V_216 ;
F_125 ( V_216 . V_218 , V_35 -> V_303 [ V_134 ] . V_217 - 1 ,
F_126 ( ( int ) V_35 -> V_303 [ F_122 ( V_35 , V_108 ) ] . V_304 ,
V_35 -> V_95 . V_157 ) ) ;
return V_216 ;
}
int F_127 ( struct V_34 * V_35 , int V_108 , int V_114 )
{
unsigned V_305 ;
struct V_215 V_216 = F_76 ( V_35 , V_108 ) ;
unsigned V_306 = F_78 ( V_216 . V_218 , V_35 -> V_95 . V_157 ) ;
if ( V_114 <= 0 || V_114 > V_306 )
return - V_8 ;
V_305 = F_77 ( V_216 . V_218 , V_35 -> V_95 . V_157 ) ;
if ( V_114 <= V_305 )
V_114 = V_305 + 1 ;
return V_114 ;
}
int F_128 ( struct V_34 * V_35 , int V_108 , int V_114 )
{
struct V_215 V_216 = F_76 ( V_35 , V_108 ) ;
if ( F_79 ( V_114 - 1 , V_216 . V_218 ) )
return V_114 -
F_77 ( V_216 . V_218 , V_35 -> V_95 . V_157 ) ;
return - 1 ;
}
struct V_307 F_129 ( struct V_34 * V_35 ,
int V_114 )
{
unsigned V_124 ;
struct V_307 V_308 ;
F_123 ( V_308 . V_309 , V_310 ) ;
if ( V_114 <= 0 || V_114 > V_35 -> V_95 . V_157 )
return V_308 ;
for ( V_124 = 0 ; V_124 < V_35 -> V_302 + 1 ; V_124 ++ ) {
struct V_215 V_216 =
F_76 ( V_35 , V_124 ) ;
if ( F_79 ( V_114 - 1 , V_216 . V_218 ) )
F_130 ( V_124 , V_308 . V_309 ) ;
}
return V_308 ;
}
struct V_307 F_131 (
struct V_34 * V_35 ,
const struct V_215 * V_311 )
{
unsigned V_124 ;
struct V_307 V_308 ;
F_123 ( V_308 . V_309 , V_310 ) ;
for ( V_124 = 0 ; V_124 < V_35 -> V_302 + 1 ; V_124 ++ ) {
struct V_215 V_216 =
F_76 ( V_35 , V_124 ) ;
if ( F_132 ( V_311 -> V_218 , V_216 . V_218 ,
V_35 -> V_95 . V_157 ) )
F_130 ( V_124 , V_308 . V_309 ) ;
}
return V_308 ;
}
static int F_133 ( struct V_34 * V_35 , int V_108 , int V_114 )
{
struct V_215 V_216 = F_76 ( V_35 , V_108 ) ;
int V_217 = F_77 ( V_216 . V_218 , V_35 -> V_95 . V_157 )
+ 1 ;
int V_219 = V_217 +
F_78 ( V_216 . V_218 , V_35 -> V_95 . V_157 ) ;
if ( V_114 < V_217 )
V_114 = V_217 ;
else if ( V_114 >= V_219 )
V_114 = V_219 - 1 ;
return V_114 ;
}
int F_134 ( struct V_34 * V_35 , int V_114 , int V_134 , T_4 V_224 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_187 * V_312 ;
int V_108 ;
if ( ! F_36 ( V_35 ) )
return - V_313 ;
V_108 = F_121 ( V_35 , V_134 ) ;
if ( V_108 < 0 )
return - V_8 ;
V_114 = F_133 ( V_35 , V_108 , V_114 ) ;
V_312 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
V_312 -> V_224 = V_224 ;
F_135 ( V_35 , L_45 ,
V_134 , V_114 , V_312 -> V_224 ) ;
return 0 ;
}
int F_136 ( struct V_34 * V_35 , int V_114 , int V_134 , T_3 V_314 , T_1 V_210 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_187 * V_195 ;
int V_108 ;
if ( ( ! F_36 ( V_35 ) ) ||
! ( V_35 -> V_95 . V_200 & V_315 ) )
return - V_313 ;
if ( ( V_314 > 4095 ) || ( V_210 > 7 ) )
return - V_8 ;
V_108 = F_121 ( V_35 , V_134 ) ;
if ( V_108 < 0 )
return - V_8 ;
V_114 = F_133 ( V_35 , V_108 , V_114 ) ;
V_195 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
if ( ( 0 == V_314 ) && ( 0 == V_210 ) )
V_195 -> V_196 = V_202 ;
else
V_195 -> V_196 = V_314 ;
V_195 -> V_197 = V_210 ;
if ( F_71 ( V_37 , V_108 , V_114 ) )
F_135 ( V_35 ,
L_46 ,
V_134 , V_114 ) ;
return 0 ;
}
bool F_137 ( struct V_34 * V_35 , int V_114 , int V_108 ,
T_3 * V_314 , T_1 * V_210 )
{
struct V_185 * V_186 ;
struct V_36 * V_37 ;
V_37 = V_36 ( V_35 ) ;
V_114 = F_133 ( V_35 , V_108 , V_114 ) ;
V_186 = & V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_194 [ V_114 ] ;
if ( V_202 != V_186 -> V_161 . V_196 ) {
if ( V_314 )
* V_314 = V_186 -> V_161 . V_196 ;
if ( V_210 )
* V_210 = V_186 -> V_161 . V_197 ;
return true ;
}
return false ;
}
int F_138 ( struct V_34 * V_35 , int V_114 , int V_134 , bool V_316 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_187 * V_312 ;
int V_108 ;
if ( ( ! F_36 ( V_35 ) ) ||
! ( V_35 -> V_95 . V_200 & V_317 ) )
return - V_313 ;
V_108 = F_121 ( V_35 , V_134 ) ;
if ( V_108 < 0 )
return - V_8 ;
V_114 = F_133 ( V_35 , V_108 , V_114 ) ;
V_312 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
V_312 -> V_222 = V_316 ;
return 0 ;
}
int F_139 ( struct V_34 * V_35 , int V_114 , int V_134 , struct V_318 * V_319 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_187 * V_312 ;
int V_108 ;
if ( ! F_36 ( V_35 ) )
return - V_313 ;
V_108 = F_121 ( V_35 , V_134 ) ;
if ( V_108 < 0 )
return - V_8 ;
V_312 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
V_319 -> V_134 = V_134 ;
V_319 -> V_224 [ 0 ] = ( ( V_312 -> V_224 >> ( 5 * 8 ) ) & 0xff ) ;
V_319 -> V_224 [ 1 ] = ( ( V_312 -> V_224 >> ( 4 * 8 ) ) & 0xff ) ;
V_319 -> V_224 [ 2 ] = ( ( V_312 -> V_224 >> ( 3 * 8 ) ) & 0xff ) ;
V_319 -> V_224 [ 3 ] = ( ( V_312 -> V_224 >> ( 2 * 8 ) ) & 0xff ) ;
V_319 -> V_224 [ 4 ] = ( ( V_312 -> V_224 >> ( 1 * 8 ) ) & 0xff ) ;
V_319 -> V_224 [ 5 ] = ( ( V_312 -> V_224 ) & 0xff ) ;
V_319 -> V_314 = V_312 -> V_196 ;
V_319 -> V_210 = V_312 -> V_197 ;
V_319 -> V_320 = V_312 -> V_321 ;
V_319 -> V_322 = 0 ;
V_319 -> V_222 = V_312 -> V_222 ;
V_319 -> V_323 = V_312 -> V_198 ;
return 0 ;
}
int F_140 ( struct V_34 * V_35 , int V_114 , int V_134 , int V_198 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_187 * V_312 ;
int V_108 ;
T_1 V_324 ;
V_108 = F_121 ( V_35 , V_134 ) ;
if ( V_108 < 0 )
return - V_8 ;
V_114 = F_133 ( V_35 , V_108 , V_114 ) ;
switch ( V_198 ) {
case V_325 :
if ( ! V_37 -> V_326 . V_327 [ V_114 ] )
V_324 = V_328 ;
else
V_324 = V_329 ;
break;
case V_330 :
V_324 = V_328 ;
break;
case V_208 :
V_324 = V_329 ;
break;
default:
F_12 ( V_35 , L_47 ,
V_198 , V_108 , V_114 ) ;
return - V_8 ;
} ;
V_312 = & V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_194 [ V_114 ] ;
V_312 -> V_198 = V_198 ;
F_141 ( V_35 , V_108 , V_114 , V_324 ) ;
if ( F_71 ( V_37 , V_108 , V_114 ) )
F_45 ( V_35 ,
L_48 ,
V_134 , V_114 ) ;
return 0 ;
}
int F_62 ( struct V_34 * V_35 , int V_108 , int V_114 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
if ( V_108 < 1 || V_108 >= V_35 -> V_270 ||
V_114 < 1 || V_114 > V_276 )
return 0 ;
return V_37 -> V_38 . V_163 . V_193 [ V_108 ] . V_220 [ V_114 ] ==
V_331 ;
}
int F_142 ( struct V_34 * V_35 , int V_108 , int V_114 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
if ( V_108 == F_60 ( V_35 ) )
return 1 ;
if ( V_108 < 1 || V_108 >= V_35 -> V_270 ||
V_114 < 1 || V_114 > V_276 )
return 0 ;
return V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_221 [ V_114 ] ==
V_331 ;
}
int F_143 ( struct V_34 * V_35 , int V_108 , int V_114 ,
int V_332 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
if ( V_108 == F_60 ( V_35 ) )
return 0 ;
if ( V_108 < 1 || V_108 >= V_35 -> V_270 ||
V_114 < 1 || V_114 > V_276 ||
V_332 < 0 || V_332 > 1 )
return - V_8 ;
V_37 -> V_38 . V_163 . V_195 [ V_108 ] . V_221 [ V_114 ] = V_332 ;
return 0 ;
}
