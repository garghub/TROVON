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
int F_45 ( struct V_34 * V_35 , T_4 V_77 , T_4 * V_78 ,
int V_88 , T_2 V_79 , T_1 V_80 ,
T_3 V_56 , unsigned long V_47 , int V_102 )
{
if ( F_27 ( V_35 -> V_71 ) )
return - V_4 ;
if ( ! F_46 ( V_35 ) || ( V_102 && F_36 ( V_35 ) ) ) {
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
static int F_47 ( struct V_34 * V_35 )
{
return V_57 ( V_35 , 0 , 0 , 0 , V_103 ,
V_104 , V_105 ) ;
}
static int F_48 ( struct V_34 * V_35 , T_4 V_106 ,
int V_107 , T_4 V_108 ,
int V_109 , int V_110 )
{
T_4 V_77 ;
T_4 V_78 ;
if ( ( V_108 & 0xfff ) | ( V_106 & 0xfff ) |
( V_107 & ~ 0x7f ) | ( V_109 & 0xff ) ) {
F_24 ( V_35 , L_9 ,
V_108 , V_106 , V_107 , V_109 ) ;
return - V_8 ;
}
if ( V_110 ) {
V_77 = ( T_4 ) V_107 | V_108 ;
V_78 = ( T_4 ) V_35 -> V_95 . V_96 | V_106 ;
} else {
V_77 = ( T_4 ) V_35 -> V_95 . V_96 | V_106 ;
V_78 = ( T_4 ) V_107 | V_108 ;
}
return F_49 ( V_35 , V_77 , & V_78 , V_109 , 0 ,
V_111 ,
V_112 , V_105 ) ;
}
static int F_50 ( struct V_34 * V_35 , T_1 V_113 , T_3 V_114 , T_3 * V_115 ,
struct V_116 * V_117 ,
struct V_116 * V_118 )
{
struct V_119 * V_120 = (struct V_119 * ) ( V_117 -> V_121 ) ;
struct V_119 * V_122 = (struct V_119 * ) ( V_118 -> V_121 ) ;
int V_49 ;
int V_123 ;
if ( V_114 & 0x1f )
return - V_8 ;
V_120 -> V_124 = F_9 ( V_114 / 32 ) ;
V_49 = F_51 ( V_35 , V_117 -> V_125 , V_118 -> V_125 , V_113 , 3 ,
V_126 , V_127 ,
V_105 ) ;
if ( V_49 )
return V_49 ;
for ( V_123 = 0 ; V_123 < 32 ; ++ V_123 )
V_115 [ V_123 ] = F_52 ( ( ( V_128 * ) V_122 -> V_129 ) [ V_123 ] ) ;
return V_49 ;
}
static int F_53 ( struct V_34 * V_35 , T_1 V_113 , T_3 * V_130 ,
struct V_116 * V_117 ,
struct V_116 * V_118 )
{
int V_123 ;
int V_49 ;
for ( V_123 = 0 ; V_123 < V_35 -> V_95 . V_131 [ V_113 ] ; V_123 += 32 ) {
V_49 = F_50 ( V_35 , V_113 , V_123 , V_130 + V_123 , V_117 , V_118 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static enum V_132 F_54 ( struct V_34 * V_35 , int V_113 , int V_133 )
{
if ( F_55 ( V_35 , V_133 , V_113 ) == V_134 )
return V_135 ;
else
return V_136 ;
}
static int F_56 ( struct V_34 * V_35 , int V_107 ,
struct V_137 * V_90 ,
struct V_116 * V_117 ,
struct V_116 * V_118 ,
struct V_138 * V_41 )
{
struct V_119 * V_139 = V_117 -> V_121 ;
T_2 V_114 ;
T_1 V_113 ;
T_1 V_140 ;
T_3 * V_130 ;
int V_49 ;
int V_141 , V_142 ;
int V_143 ;
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_119 * V_144 = V_118 -> V_121 ;
V_128 * V_145 = ( V_128 * ) ( V_144 -> V_129 ) ;
V_100 V_146 ;
T_6 V_147 ;
V_113 = V_90 -> V_79 ;
V_140 = V_90 -> V_80 & ~ 0x8 ;
V_143 = ! ! ( V_90 -> V_80 & 0x8 ) ;
if ( V_139 -> V_148 == 1 &&
V_139 -> V_149 == V_150 &&
V_139 -> V_151 == 1 ) {
if ( ! V_143 && V_139 -> V_152 == V_153 ) {
if ( V_139 -> V_154 == V_155 ) {
V_114 = F_40 ( V_139 -> V_124 ) ;
if ( V_113 < 1 || V_113 > V_35 -> V_95 . V_156 )
return - V_8 ;
V_130 = F_57 ( V_35 -> V_95 . V_131 [ V_113 ] , sizeof *V_130 , V_157 ) ;
if ( ! V_130 )
return - V_16 ;
V_49 = F_53 ( V_35 , V_113 , V_130 , V_117 , V_118 ) ;
if ( ! V_49 ) {
for ( V_141 = V_114 * 32 ; V_141 < ( V_114 + 1 ) * 32 ; ++ V_141 ) {
V_142 = V_37 -> V_158 [ V_107 ] [ V_113 - 1 ] [ V_141 ] ;
V_145 [ V_141 % 32 ] = F_35 ( V_130 [ V_142 ] ) ;
}
}
F_58 ( V_130 ) ;
return V_49 ;
}
if ( V_139 -> V_154 == V_159 ) {
V_49 = F_51 ( V_35 , V_117 -> V_125 , V_118 -> V_125 ,
V_90 -> V_79 , V_140 ,
V_90 -> V_56 , V_127 , V_105 ) ;
if ( ! V_49 && V_107 != F_59 ( V_35 ) ) {
T_1 * V_160 = V_144 -> V_129 + V_161 ;
* V_160 = ( * V_160 & 0xf0 ) | F_54 ( V_35 , V_113 , V_107 ) ;
V_146 = V_37 -> V_38 . V_162 . V_163 [ V_107 ] . V_164 [ V_113 ] ;
memcpy ( V_144 -> V_129 + V_165 , & V_146 , 4 ) ;
}
return V_49 ;
}
if ( V_139 -> V_154 == V_166 ) {
V_139 -> V_124 = F_9 ( V_107 / 8 ) ;
V_49 = F_51 ( V_35 , V_117 -> V_125 , V_118 -> V_125 ,
V_90 -> V_79 , V_140 ,
V_90 -> V_56 , V_127 , V_105 ) ;
if ( ! V_49 ) {
if ( V_107 % 8 )
memcpy ( V_144 -> V_129 ,
V_144 -> V_129 + ( V_107 % 8 ) * 8 , 8 ) ;
memset ( V_144 -> V_129 + 8 , 0 , 56 ) ;
}
return V_49 ;
}
if ( V_139 -> V_154 == V_167 ) {
V_49 = F_51 ( V_35 , V_117 -> V_125 , V_118 -> V_125 ,
V_90 -> V_79 , V_140 ,
V_90 -> V_56 , V_127 , V_105 ) ;
if ( ! V_49 ) {
V_147 = F_60 ( V_35 , V_107 ) ;
memcpy ( V_144 -> V_129 + 12 , & V_147 , 8 ) ;
}
return V_49 ;
}
}
}
if ( V_107 != F_59 ( V_35 ) &&
! F_61 ( V_35 , V_107 , V_113 ) ) {
if ( ! ( V_139 -> V_149 == V_150 &&
V_139 -> V_152 == V_153 ) || V_143 ) {
F_24 ( V_35 , L_10 ,
V_107 , V_139 -> V_152 , V_139 -> V_149 ,
V_143 ? L_11 : L_12 ,
F_52 ( V_139 -> V_154 ) ) ;
return - V_6 ;
}
}
return F_51 ( V_35 , V_117 -> V_125 , V_118 -> V_125 ,
V_90 -> V_79 , V_140 ,
V_90 -> V_56 , V_127 , V_105 ) ;
}
static int F_62 ( struct V_34 * V_35 , int V_107 ,
struct V_137 * V_90 ,
struct V_116 * V_117 ,
struct V_116 * V_118 ,
struct V_138 * V_41 )
{
return - V_6 ;
}
int F_63 ( struct V_34 * V_35 , int V_107 ,
struct V_137 * V_90 ,
struct V_116 * V_117 ,
struct V_116 * V_118 ,
struct V_138 * V_41 )
{
T_4 V_77 ;
T_4 V_78 ;
int V_49 ;
V_77 = V_41 -> V_168 ? ( T_4 ) V_117 -> V_125 : V_90 -> V_77 ;
V_78 = V_41 -> V_169 ? ( T_4 ) V_118 -> V_125 : V_90 -> V_78 ;
if ( V_41 -> V_170 ) {
V_77 &= 0xffffffffffffff00ll ;
V_77 |= V_107 ;
}
V_49 = F_45 ( V_35 , V_77 , & V_78 , V_41 -> V_88 ,
V_90 -> V_79 , V_90 -> V_80 , V_90 -> V_56 ,
V_112 , V_105 ) ;
if ( V_41 -> V_88 )
V_90 -> V_78 = V_78 ;
return V_49 ;
}
static int F_37 ( struct V_34 * V_35 , int V_107 ,
struct V_89 * V_171 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_138 * V_41 = NULL ;
struct V_89 * V_172 = V_171 ? V_171 : V_37 -> V_38 . V_90 ;
struct V_137 * V_90 ;
struct V_116 * V_117 = NULL ;
struct V_116 * V_118 = NULL ;
T_4 V_77 ;
T_4 V_78 ;
int V_82 = 0 ;
int V_123 ;
int V_49 = 0 ;
V_90 = F_64 ( sizeof( struct V_137 ) , V_157 ) ;
if ( ! V_90 )
return - V_16 ;
if ( ! V_171 ) {
V_82 = F_48 ( V_35 , V_37 -> V_38 . V_173 , V_107 ,
V_37 -> V_38 . V_162 . V_163 [ V_107 ] . V_173 ,
F_65 ( sizeof( struct V_89 ) ,
V_174 ) , 1 ) ;
if ( V_82 ) {
F_24 ( V_35 , L_13 ,
V_85 , V_82 ) ;
F_58 ( V_90 ) ;
return V_82 ;
}
}
V_90 -> V_77 = F_38 ( V_172 -> V_77 ) ;
V_90 -> V_78 = F_38 ( V_172 -> V_78 ) ;
V_90 -> V_79 = F_40 ( V_172 -> V_79 ) ;
V_90 -> V_63 = F_52 ( V_172 -> V_63 ) ;
V_90 -> V_56 = F_52 ( V_172 -> V_92 ) & 0xfff ;
V_90 -> V_80 = ( T_1 ) ( F_52 ( V_172 -> V_92 ) >> 12 ) ;
V_90 -> V_175 = V_172 -> V_94 & ( 1 << 6 ) ;
for ( V_123 = 0 ; V_123 < F_2 ( V_176 ) ; ++ V_123 ) {
if ( V_90 -> V_56 == V_176 [ V_123 ] . V_92 ) {
V_41 = & V_176 [ V_123 ] ;
break;
}
}
if ( ! V_41 ) {
F_24 ( V_35 , L_14 ,
V_90 -> V_56 , V_107 ) ;
V_172 -> V_1 = V_7 ;
goto V_177;
}
if ( V_41 -> V_168 ) {
V_90 -> V_77 &= V_178 ;
V_117 = F_66 ( V_35 ) ;
if ( F_67 ( V_117 ) ) {
V_172 -> V_1 = V_29 ;
V_117 = NULL ;
goto V_177;
}
if ( F_48 ( V_35 , V_117 -> V_125 , V_107 ,
V_90 -> V_77 ,
V_179 , 1 ) ) {
F_24 ( V_35 , L_15 ,
V_85 , V_41 -> V_92 ) ;
V_172 -> V_1 = V_3 ;
goto V_177;
}
}
if ( V_41 -> V_180 && V_41 -> V_180 ( V_35 , V_107 , V_90 , V_117 ) ) {
F_12 ( V_35 , L_16 ,
V_90 -> V_56 , V_107 , V_90 -> V_79 ) ;
V_172 -> V_1 = V_5 ;
goto V_177;
}
if ( V_41 -> V_169 ) {
V_118 = F_66 ( V_35 ) ;
if ( F_67 ( V_118 ) ) {
V_172 -> V_1 = V_29 ;
V_118 = NULL ;
goto V_177;
}
}
if ( V_41 -> V_181 ) {
V_49 = V_41 -> V_181 ( V_35 , V_107 , V_90 , V_117 , V_118 ,
V_41 ) ;
if ( V_41 -> V_88 )
V_172 -> V_78 = F_34 ( V_90 -> V_78 ) ;
} else {
V_77 = V_41 -> V_168 ? ( T_4 ) V_117 -> V_125 :
V_90 -> V_77 ;
V_78 = V_41 -> V_169 ? ( T_4 ) V_118 -> V_125 :
V_90 -> V_78 ;
V_49 = F_45 ( V_35 , V_77 , & V_78 ,
V_41 -> V_88 , V_90 -> V_79 ,
V_90 -> V_80 , V_90 -> V_56 ,
V_112 ,
V_105 ) ;
if ( V_41 -> V_88 ) {
V_90 -> V_78 = V_78 ;
V_172 -> V_78 = F_34 ( V_90 -> V_78 ) ;
}
}
if ( V_49 ) {
F_12 ( V_35 , L_17 ,
V_90 -> V_56 , V_107 , V_90 -> V_33 , V_49 ) ;
V_172 -> V_1 = F_3 ( V_49 ) ;
goto V_177;
}
if ( V_41 -> V_169 && ! V_172 -> V_1 ) {
V_82 = F_48 ( V_35 , V_118 -> V_125 , V_107 ,
V_90 -> V_78 ,
V_179 , V_182 ) ;
if ( V_82 ) {
F_24 ( V_35 , L_18 , V_85 ) ;
goto V_67;
}
}
V_177:
if ( ! V_171 ) {
V_82 = F_48 ( V_35 , V_37 -> V_38 . V_173 , V_107 ,
V_37 -> V_38 . V_162 . V_163 [ V_107 ] . V_173 ,
F_65 ( sizeof( struct V_137 ) ,
V_174 ) ,
V_182 ) ;
if ( V_82 )
F_24 ( V_35 , L_19 ,
V_85 ) ;
else if ( V_90 -> V_175 &&
F_68 ( V_35 , V_107 , & V_37 -> V_38 . V_162 . V_183 ) )
F_12 ( V_35 , L_20 ,
V_107 ) ;
}
V_67:
F_58 ( V_90 ) ;
F_69 ( V_35 , V_117 ) ;
F_69 ( V_35 , V_118 ) ;
return V_82 ;
}
static int F_70 ( struct V_36 * V_37 ,
int V_107 , int V_113 )
{
struct V_184 * V_185 ;
struct V_186 * V_187 ;
struct V_188 * V_189 ;
struct V_34 * V_35 = & ( V_37 -> V_35 ) ;
int V_49 ;
int V_190 = V_191 ;
V_185 = & V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_193 [ V_113 ] ;
V_187 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
if ( V_185 -> V_160 . V_195 == V_187 -> V_195 &&
V_185 -> V_160 . V_196 == V_187 -> V_196 &&
V_185 -> V_160 . V_197 == V_187 -> V_197 )
return 0 ;
if ( ! ( V_37 -> V_38 . V_162 . V_163 [ V_107 ] . V_198 &&
V_35 -> V_95 . V_199 & V_200 ) ) {
V_185 -> V_160 . V_197 = V_187 -> V_197 ;
return - 1 ;
}
F_71 ( V_35 , L_21 ,
V_107 , V_113 ) ;
F_71 ( V_35 , L_22 ,
V_187 -> V_195 , V_187 -> V_196 ,
V_187 -> V_197 ) ;
V_189 = F_64 ( sizeof( * V_189 ) , V_157 ) ;
if ( ! V_189 )
return - V_16 ;
if ( V_185 -> V_160 . V_195 != V_187 -> V_195 ) {
if ( V_201 != V_187 -> V_195 ) {
V_49 = F_72 ( & V_37 -> V_35 , V_113 ,
V_187 -> V_195 ,
& V_190 ) ;
if ( V_49 ) {
F_58 ( V_189 ) ;
F_12 ( & V_37 -> V_35 ,
L_23 ,
V_107 , V_113 ) ;
return V_49 ;
}
} else {
V_190 = V_191 ;
}
V_189 -> V_94 |= V_202 ;
F_71 ( & V_37 -> V_35 ,
L_24 ,
( int ) ( V_187 -> V_195 ) ,
V_190 , V_107 , V_113 ) ;
}
V_189 -> V_203 = V_185 -> V_160 . V_195 ;
V_189 -> V_204 = V_185 -> V_205 ;
if ( V_185 -> V_160 . V_196 != V_187 -> V_196 )
V_189 -> V_94 |= V_206 ;
if ( V_189 -> V_94 & V_202 )
V_185 -> V_205 = V_190 ;
V_185 -> V_160 . V_195 = V_187 -> V_195 ;
V_185 -> V_160 . V_196 = V_187 -> V_196 ;
V_185 -> V_160 . V_197 = V_187 -> V_197 ;
if ( V_187 -> V_197 == V_207 )
V_189 -> V_94 |= V_208 ;
V_189 -> V_113 = V_113 ;
V_189 -> V_107 = V_107 ;
V_189 -> V_209 = V_185 -> V_160 . V_196 ;
V_189 -> V_210 = V_185 -> V_160 . V_195 ;
V_189 -> V_211 = V_185 -> V_205 ;
V_189 -> V_37 = V_37 ;
F_73 ( & V_189 -> V_189 , V_212 ) ;
F_74 ( V_37 -> V_38 . V_162 . V_213 , & V_189 -> V_189 ) ;
return 0 ;
}
static int F_75 ( struct V_36 * V_37 , int V_107 )
{
int V_113 , V_49 ;
struct V_186 * V_187 ;
struct V_184 * V_185 ;
struct V_214 V_215 = F_76 (
& V_37 -> V_35 , V_107 ) ;
int V_216 = F_77 ( V_215 . V_217 ,
V_37 -> V_35 . V_95 . V_156 ) + 1 ;
int V_218 = V_216 - 1 +
F_78 ( V_215 . V_217 , V_37 -> V_35 . V_95 . V_156 ) ;
for ( V_113 = V_216 ; V_113 <= V_218 ; V_113 ++ ) {
if ( ! F_79 ( V_113 - 1 , V_215 . V_217 ) )
continue;
V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_219 [ V_113 ] =
V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_220 [ V_113 ] ;
V_185 = & V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_193 [ V_113 ] ;
V_187 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
V_185 -> V_160 = * V_187 ;
if ( V_201 != V_187 -> V_195 ) {
V_49 = F_72 ( & V_37 -> V_35 , V_113 ,
V_187 -> V_195 , & ( V_185 -> V_205 ) ) ;
if ( V_49 ) {
V_185 -> V_205 = V_191 ;
F_12 ( & V_37 -> V_35 ,
L_25 ,
V_107 , V_113 ) ;
return V_49 ;
}
F_71 ( & V_37 -> V_35 , L_24 ,
( int ) ( V_185 -> V_160 . V_195 ) ,
V_185 -> V_205 , V_107 , V_113 ) ;
}
if ( V_187 -> V_221 ) {
V_185 -> V_222 = F_80 ( & V_37 -> V_35 ,
V_113 ,
V_187 -> V_223 ) ;
if ( 0 > V_185 -> V_222 ) {
V_49 = V_185 -> V_222 ;
V_185 -> V_222 = V_191 ;
F_12 ( & V_37 -> V_35 ,
L_26 ,
V_107 , V_113 ) ;
return V_49 ;
}
F_71 ( & V_37 -> V_35 , L_27 ,
V_185 -> V_160 . V_223 , V_185 -> V_222 , V_107 , V_113 ) ;
}
}
return 0 ;
}
static void F_81 ( struct V_36 * V_37 , int V_107 )
{
int V_113 ;
struct V_184 * V_185 ;
struct V_214 V_215 = F_76 (
& V_37 -> V_35 , V_107 ) ;
int V_216 = F_77 ( V_215 . V_217 ,
V_37 -> V_35 . V_95 . V_156 ) + 1 ;
int V_218 = V_216 - 1 +
F_78 ( V_215 . V_217 , V_37 -> V_35 . V_95 . V_156 ) ;
for ( V_113 = V_216 ; V_113 <= V_218 ; V_113 ++ ) {
if ( ! F_79 ( V_113 - 1 , V_215 . V_217 ) )
continue;
V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_219 [ V_113 ] =
V_224 ;
V_185 = & V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_193 [ V_113 ] ;
if ( V_191 != V_185 -> V_205 ) {
F_82 ( & V_37 -> V_35 ,
V_113 , V_185 -> V_160 . V_195 ) ;
V_185 -> V_205 = V_191 ;
}
if ( V_191 != V_185 -> V_222 ) {
F_83 ( & V_37 -> V_35 , V_113 , V_185 -> V_160 . V_223 ) ;
V_185 -> V_222 = V_191 ;
}
}
return;
}
static void F_84 ( struct V_34 * V_35 , int V_107 , T_1 V_41 ,
T_3 V_43 , T_1 V_75 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_225 * V_163 = V_37 -> V_38 . V_162 . V_163 ;
T_2 V_226 ;
T_1 V_227 = 0 ;
int V_123 ;
unsigned long V_94 ;
V_163 [ V_107 ] . V_42 ^= 1 ;
V_226 = ( T_2 ) V_163 [ V_107 ] . V_42 << 31 ;
if ( V_75 != V_163 [ V_107 ] . V_42 ) {
F_12 ( V_35 , L_28 ,
V_75 , V_107 ) ;
goto V_228;
}
if ( V_41 == V_53 ) {
F_12 ( V_35 , L_29 , V_107 ) ;
V_163 [ V_107 ] . V_198 = false ;
V_163 [ V_107 ] . V_229 = false ;
F_81 ( V_37 , V_107 ) ;
for ( V_123 = 0 ; V_123 < V_230 ; ++ V_123 ) {
V_163 [ V_107 ] . V_231 [ V_123 ] . V_232 = - 1 ;
V_163 [ V_107 ] . V_231 [ V_123 ] . V_63 = 0 ;
}
if ( V_233 == V_163 [ V_107 ] . V_234 )
goto V_235;
F_85 ( V_35 , V_236 , V_107 ) ;
V_226 |= F_86 () ;
goto V_228;
}
if ( V_41 != V_53 &&
V_233 == V_163 [ V_107 ] . V_234 ) {
F_12 ( V_35 , L_30 ,
V_107 , V_41 ) ;
return;
}
switch ( V_41 ) {
case V_237 :
if ( V_163 [ V_107 ] . V_234 != V_53 )
goto V_228;
V_163 [ V_107 ] . V_173 = ( ( T_4 ) V_43 ) << 48 ;
V_37 -> V_38 . V_162 . V_163 [ V_107 ] . V_238 = 0 ;
F_87 ( & V_37 -> V_38 . V_162 . V_239 [ V_107 ] ) ;
break;
case V_240 :
if ( V_163 [ V_107 ] . V_234 != V_237 )
goto V_228;
V_163 [ V_107 ] . V_173 |= ( ( T_4 ) V_43 ) << 32 ;
break;
case V_241 :
if ( V_163 [ V_107 ] . V_234 != V_240 )
goto V_228;
V_163 [ V_107 ] . V_173 |= ( ( T_4 ) V_43 ) << 16 ;
break;
case V_242 :
if ( V_163 [ V_107 ] . V_234 != V_241 )
goto V_228;
V_163 [ V_107 ] . V_173 |= V_43 ;
if ( F_75 ( V_37 , V_107 ) )
goto V_228;
V_163 [ V_107 ] . V_198 = true ;
F_85 ( V_35 , V_243 , V_107 ) ;
break;
case V_97 :
if ( ( V_163 [ V_107 ] . V_234 != V_242 ) &&
( V_163 [ V_107 ] . V_234 != V_97 ) )
goto V_228;
F_29 ( & V_37 -> V_41 . V_91 ) ;
if ( F_37 ( V_35 , V_107 , NULL ) ) {
F_24 ( V_35 , L_31 ,
V_107 ) ;
F_32 ( & V_37 -> V_41 . V_91 ) ;
goto V_228;
}
F_32 ( & V_37 -> V_41 . V_91 ) ;
break;
default:
F_12 ( V_35 , L_32 , V_41 , V_107 ) ;
goto V_228;
}
F_88 ( & V_37 -> V_38 . V_162 . V_244 , V_94 ) ;
if ( ! V_163 [ V_107 ] . V_245 )
V_163 [ V_107 ] . V_234 = V_41 ;
else
V_227 = 1 ;
F_89 ( & V_37 -> V_38 . V_162 . V_244 , V_94 ) ;
if ( V_227 ) {
F_12 ( V_35 , L_33 ,
V_41 , V_107 ) ;
return;
}
F_8 ( ( V_45 T_2 ) F_9 ( V_226 ) ,
& V_37 -> V_38 . V_39 [ V_107 ] . V_40 ) ;
F_10 () ;
return;
V_228:
F_90 ( V_35 , V_107 ) ;
F_88 ( & V_37 -> V_38 . V_162 . V_244 , V_94 ) ;
if ( ! V_163 [ V_107 ] . V_245 )
V_163 [ V_107 ] . V_234 = V_53 ;
F_89 ( & V_37 -> V_38 . V_162 . V_244 , V_94 ) ;
V_235:
memset ( & V_163 [ V_107 ] . V_231 , 0 ,
sizeof( struct V_246 ) ) ;
F_8 ( ( V_45 T_2 ) F_9 ( V_226 ) ,
& V_37 -> V_38 . V_39 [ V_107 ] . V_40 ) ;
F_31 () ;
}
void F_91 ( struct V_247 * V_189 )
{
struct V_248 * V_162 =
F_92 ( V_189 ,
struct V_248 ,
V_249 ) ;
struct V_250 * V_38 =
F_92 ( V_162 , struct V_250 , V_162 ) ;
struct V_36 * V_37 =
F_92 ( V_38 , struct V_36 , V_38 ) ;
struct V_34 * V_35 = & V_37 -> V_35 ;
V_100 * V_251 ;
T_2 V_252 ;
T_2 V_253 ;
int V_123 , V_254 , V_107 ;
int V_75 ;
int V_255 = 0 ;
int V_256 = 0 ;
T_2 V_257 ;
V_251 = V_162 -> V_258 ;
for ( V_123 = 0 ; V_123 < V_259 ; V_123 ++ ) {
V_253 = F_40 ( V_251 [ V_123 ] ) ;
for ( V_254 = 0 ; V_254 < 32 ; V_254 ++ ) {
if ( ! ( V_253 & ( 1 << V_254 ) ) )
continue;
++ V_256 ;
V_107 = ( V_123 * 32 ) + V_254 ;
V_252 = F_6 ( F_5 (
& V_38 -> V_39 [ V_107 ] . V_46 ) ) ;
V_257 = F_6 ( F_5 ( & V_38 -> V_39 [ V_107 ] . V_40 ) )
>> 31 ;
V_75 = V_252 >> 31 ;
if ( V_75 != V_257 ) {
if ( V_162 -> V_163 [ V_107 ] . V_42
!= V_257 ) {
F_93 ( L_34 ,
V_107 , V_257 ,
V_162 -> V_163 [ V_107 ] . V_42 ) ;
V_162 -> V_163 [ V_107 ] . V_42 =
V_257 ;
}
F_84 ( V_35 , V_107 ,
V_252 >> 16 & 0xff ,
V_252 & 0xffff , V_75 ) ;
++ V_255 ;
}
}
}
if ( V_256 && V_256 != V_255 )
F_12 ( V_35 , L_35 ,
V_256 , V_255 ) ;
if ( F_47 ( V_35 ) )
F_12 ( V_35 , L_36 ) ;
}
static int F_94 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_260 ;
int V_261 ;
unsigned long V_48 ;
V_260 = F_6 ( F_5 ( & V_37 -> V_38 . V_39 -> V_46 ) ) >> 31 ;
V_48 = V_52 + F_14 ( 5000 ) ;
while ( F_15 ( V_52 , V_48 ) ) {
V_261 = F_6 ( F_5 ( & V_37 -> V_38 . V_39 -> V_40 ) ) >> 31 ;
if ( V_261 == V_260 ) {
V_37 -> V_41 . V_42 = V_261 ;
return 0 ;
}
F_16 () ;
}
F_12 ( V_35 , L_37 ) ;
F_8 ( ( V_45 T_2 ) 0 , & V_37 -> V_38 . V_39 -> V_40 ) ;
F_8 ( ( V_45 T_2 ) 0 , & V_37 -> V_38 . V_39 -> V_46 ) ;
V_37 -> V_41 . V_42 = 0 ;
return 0 ;
}
int F_95 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_225 * V_262 ;
int V_123 , V_254 , V_49 , V_113 ;
if ( F_36 ( V_35 ) )
V_37 -> V_38 . V_39 =
F_96 ( F_97 ( V_35 -> V_71 , V_37 -> V_263 . V_264 ) +
V_37 -> V_263 . V_265 , V_266 ) ;
else
V_37 -> V_38 . V_39 =
F_96 ( F_97 ( V_35 -> V_71 , 2 ) +
V_267 , V_266 ) ;
if ( ! V_37 -> V_38 . V_39 ) {
F_24 ( V_35 , L_38 ) ;
goto V_268;
}
if ( F_36 ( V_35 ) ) {
V_37 -> V_38 . V_162 . V_163 =
F_64 ( V_35 -> V_269 *
sizeof( struct V_225 ) , V_157 ) ;
if ( ! V_37 -> V_38 . V_162 . V_163 )
goto V_270;
V_37 -> V_38 . V_162 . V_194 =
F_64 ( V_35 -> V_269 *
sizeof( struct V_271 ) , V_157 ) ;
if ( ! V_37 -> V_38 . V_162 . V_194 )
goto V_272;
V_37 -> V_38 . V_162 . V_192 =
F_64 ( V_35 -> V_269 *
sizeof( struct V_273 ) , V_157 ) ;
if ( ! V_37 -> V_38 . V_162 . V_192 )
goto V_274;
for ( V_123 = 0 ; V_123 < V_35 -> V_269 ; ++ V_123 ) {
V_262 = & V_37 -> V_38 . V_162 . V_163 [ V_123 ] ;
V_262 -> V_234 = V_53 ;
for ( V_254 = 0 ; V_254 < V_230 ; ++ V_254 )
V_262 -> V_231 [ V_254 ] . V_232 = - 1 ;
F_8 ( ( V_45 T_2 ) 0 ,
& V_37 -> V_38 . V_39 [ V_123 ] . V_46 ) ;
F_8 ( ( V_45 T_2 ) 0 ,
& V_37 -> V_38 . V_39 [ V_123 ] . V_40 ) ;
F_10 () ;
for ( V_113 = 1 ; V_113 <= V_275 ; V_113 ++ ) {
V_262 -> V_276 [ V_113 ] =
F_64 ( sizeof( struct V_277 ) ,
V_157 ) ;
if ( ! V_262 -> V_276 [ V_113 ] ) {
if ( -- V_113 )
F_58 ( V_262 -> V_276 [ V_113 ] ) ;
goto V_278;
}
F_98 ( & V_262 -> V_279 [ V_113 ] ) ;
V_37 -> V_38 . V_162 . V_194 [ V_123 ] . V_193 [ V_113 ] . V_195 = V_201 ;
V_37 -> V_38 . V_162 . V_192 [ V_123 ] . V_193 [ V_113 ] . V_160 . V_195 = V_201 ;
V_37 -> V_38 . V_162 . V_192 [ V_123 ] . V_193 [ V_113 ] . V_205 = V_191 ;
V_37 -> V_38 . V_162 . V_192 [ V_123 ] . V_193 [ V_113 ] . V_222 = V_191 ;
}
F_99 ( & V_262 -> V_280 ) ;
}
memset ( & V_37 -> V_38 . V_162 . V_183 , 0 , V_35 -> V_95 . V_281 ) ;
V_37 -> V_38 . V_162 . V_183 . type = V_282 ;
F_73 ( & V_37 -> V_38 . V_162 . V_249 ,
F_91 ) ;
F_73 ( & V_37 -> V_38 . V_162 . V_283 ,
V_284 ) ;
F_73 ( & V_37 -> V_38 . V_162 . V_285 ,
V_286 ) ;
F_99 ( & V_37 -> V_38 . V_162 . V_244 ) ;
F_99 ( & V_37 -> V_38 . V_162 . V_287 . V_288 ) ;
V_37 -> V_38 . V_162 . V_213 =
F_100 ( L_39 ) ;
if ( ! V_37 -> V_38 . V_162 . V_213 )
goto V_278;
if ( F_101 ( V_35 ) )
goto V_289;
V_49 = F_47 ( V_35 ) ;
if ( V_49 ) {
F_24 ( V_35 , L_40 ,
V_49 ) ;
goto V_290;
}
} else {
V_49 = F_94 ( V_35 ) ;
if ( V_49 ) {
F_24 ( V_35 , L_41 ) ;
goto V_270;
}
}
return 0 ;
V_290:
F_102 ( V_35 , V_291 ) ;
V_289:
F_103 ( V_37 -> V_38 . V_162 . V_213 ) ;
F_104 ( V_37 -> V_38 . V_162 . V_213 ) ;
V_278:
while ( -- V_123 ) {
for ( V_113 = 1 ; V_113 <= V_275 ; V_113 ++ )
F_58 ( V_37 -> V_38 . V_162 . V_163 [ V_123 ] . V_276 [ V_113 ] ) ;
}
F_58 ( V_37 -> V_38 . V_162 . V_192 ) ;
V_274:
F_58 ( V_37 -> V_38 . V_162 . V_194 ) ;
V_272:
F_58 ( V_37 -> V_38 . V_162 . V_163 ) ;
V_270:
F_105 ( V_37 -> V_38 . V_39 ) ;
V_268:
F_106 ( & ( V_35 -> V_71 -> V_35 ) , V_292 ,
V_37 -> V_38 . V_90 ,
V_37 -> V_38 . V_173 ) ;
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
V_293 , V_294 ) ;
if ( ! V_37 -> V_41 . V_72 ) {
F_24 ( V_35 , L_42 ) ;
return - V_16 ;
}
}
if ( F_46 ( V_35 ) ) {
V_37 -> V_38 . V_90 = F_110 ( & ( V_35 -> V_71 -> V_35 ) , V_292 ,
& V_37 -> V_38 . V_173 ,
V_157 ) ;
if ( ! V_37 -> V_38 . V_90 )
goto V_295;
}
V_37 -> V_41 . V_296 = F_111 ( L_43 , V_35 -> V_71 ,
V_179 ,
V_179 , 0 ) ;
if ( ! V_37 -> V_41 . V_296 )
goto V_268;
return 0 ;
V_268:
if ( F_46 ( V_35 ) )
F_106 ( & ( V_35 -> V_71 -> V_35 ) , V_292 ,
V_37 -> V_38 . V_90 , V_37 -> V_38 . V_173 ) ;
V_37 -> V_38 . V_90 = NULL ;
V_295:
if ( ! F_109 ( V_35 ) )
F_105 ( V_37 -> V_41 . V_72 ) ;
return - V_16 ;
}
void F_112 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_123 , V_113 ;
if ( F_36 ( V_35 ) ) {
F_103 ( V_37 -> V_38 . V_162 . V_213 ) ;
F_104 ( V_37 -> V_38 . V_162 . V_213 ) ;
for ( V_123 = 0 ; V_123 < V_35 -> V_269 ; V_123 ++ ) {
for ( V_113 = 1 ; V_113 <= V_275 ; V_113 ++ )
F_58 ( V_37 -> V_38 . V_162 . V_163 [ V_123 ] . V_276 [ V_113 ] ) ;
}
F_58 ( V_37 -> V_38 . V_162 . V_163 ) ;
F_58 ( V_37 -> V_38 . V_162 . V_194 ) ;
F_58 ( V_37 -> V_38 . V_162 . V_192 ) ;
}
F_105 ( V_37 -> V_38 . V_39 ) ;
}
void F_113 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
F_114 ( V_37 -> V_41 . V_296 ) ;
if ( ! F_109 ( V_35 ) )
F_105 ( V_37 -> V_41 . V_72 ) ;
if ( F_46 ( V_35 ) )
F_106 ( & ( V_35 -> V_71 -> V_35 ) , V_292 ,
V_37 -> V_38 . V_90 , V_37 -> V_38 . V_173 ) ;
V_37 -> V_38 . V_90 = NULL ;
}
int F_115 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
int V_123 ;
int V_49 = 0 ;
V_37 -> V_41 . V_59 = F_116 ( V_37 -> V_41 . V_297 *
sizeof ( struct V_58 ) ,
V_157 ) ;
if ( ! V_37 -> V_41 . V_59 )
return - V_16 ;
for ( V_123 = 0 ; V_123 < V_37 -> V_41 . V_297 ; ++ V_123 ) {
V_37 -> V_41 . V_59 [ V_123 ] . V_63 = V_123 ;
V_37 -> V_41 . V_59 [ V_123 ] . V_65 = V_123 + 1 ;
}
V_37 -> V_41 . V_59 [ V_37 -> V_41 . V_297 - 1 ] . V_65 = - 1 ;
V_37 -> V_41 . V_62 = 0 ;
F_108 ( & V_37 -> V_41 . V_60 , V_37 -> V_41 . V_297 ) ;
F_99 ( & V_37 -> V_41 . V_61 ) ;
for ( V_37 -> V_41 . V_64 = 1 ;
V_37 -> V_41 . V_64 < V_37 -> V_41 . V_297 ;
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
int V_123 ;
V_37 -> V_41 . V_70 = 0 ;
for ( V_123 = 0 ; V_123 < V_37 -> V_41 . V_297 ; ++ V_123 )
F_13 ( & V_37 -> V_41 . V_60 ) ;
F_58 ( V_37 -> V_41 . V_59 ) ;
F_17 ( & V_37 -> V_41 . V_51 ) ;
}
struct V_116 * F_66 ( struct V_34 * V_35 )
{
struct V_116 * V_298 ;
V_298 = F_116 ( sizeof *V_298 , V_157 ) ;
if ( ! V_298 )
return F_118 ( - V_16 ) ;
V_298 -> V_121 = F_119 ( V_36 ( V_35 ) -> V_41 . V_296 , V_157 ,
& V_298 -> V_125 ) ;
if ( ! V_298 -> V_121 ) {
F_58 ( V_298 ) ;
return F_118 ( - V_16 ) ;
}
memset ( V_298 -> V_121 , 0 , V_179 ) ;
return V_298 ;
}
void F_69 ( struct V_34 * V_35 ,
struct V_116 * V_298 )
{
if ( ! V_298 )
return;
F_120 ( V_36 ( V_35 ) -> V_41 . V_296 , V_298 -> V_121 , V_298 -> V_125 ) ;
F_58 ( V_298 ) ;
}
T_2 F_86 ( void )
{
return ( ( T_2 ) V_299 << 8 ) | ( T_2 ) V_300 ;
}
static int F_121 ( struct V_34 * V_35 , int V_133 )
{
if ( ( V_133 < 0 ) || ( V_133 >= V_35 -> V_301 ) ) {
F_24 ( V_35 , L_44 , V_133 , V_35 -> V_301 ) ;
return - V_8 ;
}
return V_133 + 1 ;
}
int F_122 ( struct V_34 * V_35 , int V_107 )
{
if ( V_107 < 1 || V_107 > V_35 -> V_301 ) {
F_24 ( V_35 ,
L_45 ,
V_107 , V_35 -> V_269 ) ;
return - V_8 ;
}
return V_107 - 1 ;
}
struct V_214 F_76 ( struct V_34 * V_35 , int V_107 )
{
struct V_214 V_215 ;
int V_133 ;
F_123 ( V_215 . V_217 , V_275 ) ;
if ( V_107 == 0 ) {
F_124 ( V_215 . V_217 , V_35 -> V_95 . V_156 ) ;
return V_215 ;
}
V_133 = F_122 ( V_35 , V_107 ) ;
if ( V_133 < 0 )
return V_215 ;
F_125 ( V_215 . V_217 , V_35 -> V_302 [ V_133 ] . V_216 - 1 ,
F_126 ( ( int ) V_35 -> V_302 [ F_122 ( V_35 , V_107 ) ] . V_303 ,
V_35 -> V_95 . V_156 ) ) ;
return V_215 ;
}
int F_127 ( struct V_34 * V_35 , int V_107 , int V_113 )
{
unsigned V_304 ;
struct V_214 V_215 = F_76 ( V_35 , V_107 ) ;
unsigned V_305 = F_78 ( V_215 . V_217 , V_35 -> V_95 . V_156 ) ;
if ( V_113 <= 0 || V_113 > V_305 )
return - V_8 ;
V_304 = F_77 ( V_215 . V_217 , V_35 -> V_95 . V_156 ) ;
if ( V_113 <= V_304 )
V_113 = V_304 + 1 ;
return V_113 ;
}
int F_128 ( struct V_34 * V_35 , int V_107 , int V_113 )
{
struct V_214 V_215 = F_76 ( V_35 , V_107 ) ;
if ( F_79 ( V_113 - 1 , V_215 . V_217 ) )
return V_113 -
F_77 ( V_215 . V_217 , V_35 -> V_95 . V_156 ) ;
return - 1 ;
}
struct V_306 F_129 ( struct V_34 * V_35 ,
int V_113 )
{
unsigned V_123 ;
struct V_306 V_307 ;
F_123 ( V_307 . V_308 , V_309 ) ;
if ( V_113 <= 0 || V_113 > V_35 -> V_95 . V_156 )
return V_307 ;
for ( V_123 = 0 ; V_123 < V_35 -> V_301 + 1 ; V_123 ++ ) {
struct V_214 V_215 =
F_76 ( V_35 , V_123 ) ;
if ( F_79 ( V_113 - 1 , V_215 . V_217 ) )
F_130 ( V_123 , V_307 . V_308 ) ;
}
return V_307 ;
}
struct V_306 F_131 (
struct V_34 * V_35 ,
const struct V_214 * V_310 )
{
unsigned V_123 ;
struct V_306 V_307 ;
F_123 ( V_307 . V_308 , V_309 ) ;
for ( V_123 = 0 ; V_123 < V_35 -> V_301 + 1 ; V_123 ++ ) {
struct V_214 V_215 =
F_76 ( V_35 , V_123 ) ;
if ( F_132 ( V_310 -> V_217 , V_215 . V_217 ,
V_35 -> V_95 . V_156 ) )
F_130 ( V_123 , V_307 . V_308 ) ;
}
return V_307 ;
}
static int F_133 ( struct V_34 * V_35 , int V_107 , int V_113 )
{
struct V_214 V_215 = F_76 ( V_35 , V_107 ) ;
int V_216 = F_77 ( V_215 . V_217 , V_35 -> V_95 . V_156 )
+ 1 ;
int V_218 = V_216 +
F_78 ( V_215 . V_217 , V_35 -> V_95 . V_156 ) ;
if ( V_113 < V_216 )
V_113 = V_216 ;
else if ( V_113 >= V_218 )
V_113 = V_218 - 1 ;
return V_113 ;
}
int F_134 ( struct V_34 * V_35 , int V_113 , int V_133 , T_4 V_223 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_186 * V_311 ;
int V_107 ;
if ( ! F_36 ( V_35 ) )
return - V_312 ;
V_107 = F_121 ( V_35 , V_133 ) ;
if ( V_107 < 0 )
return - V_8 ;
V_113 = F_133 ( V_35 , V_107 , V_113 ) ;
V_311 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
V_311 -> V_223 = V_223 ;
F_135 ( V_35 , L_46 ,
V_133 , V_113 , V_311 -> V_223 ) ;
return 0 ;
}
int F_136 ( struct V_34 * V_35 , int V_113 , int V_133 , T_3 V_313 , T_1 V_209 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_186 * V_194 ;
int V_107 ;
if ( ( ! F_36 ( V_35 ) ) ||
! ( V_35 -> V_95 . V_199 & V_314 ) )
return - V_312 ;
if ( ( V_313 > 4095 ) || ( V_209 > 7 ) )
return - V_8 ;
V_107 = F_121 ( V_35 , V_133 ) ;
if ( V_107 < 0 )
return - V_8 ;
V_113 = F_133 ( V_35 , V_107 , V_113 ) ;
V_194 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
if ( ( 0 == V_313 ) && ( 0 == V_209 ) )
V_194 -> V_195 = V_201 ;
else
V_194 -> V_195 = V_313 ;
V_194 -> V_196 = V_209 ;
if ( F_70 ( V_37 , V_107 , V_113 ) )
F_135 ( V_35 ,
L_47 ,
V_133 , V_113 ) ;
return 0 ;
}
bool F_137 ( struct V_34 * V_35 , int V_113 , int V_107 ,
T_3 * V_313 , T_1 * V_209 )
{
struct V_184 * V_185 ;
struct V_36 * V_37 ;
V_37 = V_36 ( V_35 ) ;
V_113 = F_133 ( V_35 , V_107 , V_113 ) ;
V_185 = & V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_193 [ V_113 ] ;
if ( V_201 != V_185 -> V_160 . V_195 ) {
if ( V_313 )
* V_313 = V_185 -> V_160 . V_195 ;
if ( V_209 )
* V_209 = V_185 -> V_160 . V_196 ;
return true ;
}
return false ;
}
int F_138 ( struct V_34 * V_35 , int V_113 , int V_133 , bool V_315 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_186 * V_311 ;
int V_107 ;
if ( ( ! F_36 ( V_35 ) ) ||
! ( V_35 -> V_95 . V_199 & V_316 ) )
return - V_312 ;
V_107 = F_121 ( V_35 , V_133 ) ;
if ( V_107 < 0 )
return - V_8 ;
V_113 = F_133 ( V_35 , V_107 , V_113 ) ;
V_311 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
V_311 -> V_221 = V_315 ;
return 0 ;
}
int F_139 ( struct V_34 * V_35 , int V_113 , int V_133 , struct V_317 * V_318 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_186 * V_311 ;
int V_107 ;
if ( ! F_36 ( V_35 ) )
return - V_312 ;
V_107 = F_121 ( V_35 , V_133 ) ;
if ( V_107 < 0 )
return - V_8 ;
V_311 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
V_318 -> V_133 = V_133 ;
V_318 -> V_223 [ 0 ] = ( ( V_311 -> V_223 >> ( 5 * 8 ) ) & 0xff ) ;
V_318 -> V_223 [ 1 ] = ( ( V_311 -> V_223 >> ( 4 * 8 ) ) & 0xff ) ;
V_318 -> V_223 [ 2 ] = ( ( V_311 -> V_223 >> ( 3 * 8 ) ) & 0xff ) ;
V_318 -> V_223 [ 3 ] = ( ( V_311 -> V_223 >> ( 2 * 8 ) ) & 0xff ) ;
V_318 -> V_223 [ 4 ] = ( ( V_311 -> V_223 >> ( 1 * 8 ) ) & 0xff ) ;
V_318 -> V_223 [ 5 ] = ( ( V_311 -> V_223 ) & 0xff ) ;
V_318 -> V_313 = V_311 -> V_195 ;
V_318 -> V_209 = V_311 -> V_196 ;
V_318 -> V_319 = V_311 -> V_320 ;
V_318 -> V_321 = 0 ;
V_318 -> V_221 = V_311 -> V_221 ;
V_318 -> V_322 = V_311 -> V_197 ;
return 0 ;
}
int F_140 ( struct V_34 * V_35 , int V_113 , int V_133 , int V_197 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
struct V_186 * V_311 ;
int V_107 ;
T_1 V_323 ;
V_107 = F_121 ( V_35 , V_133 ) ;
if ( V_107 < 0 )
return - V_8 ;
V_113 = F_133 ( V_35 , V_107 , V_113 ) ;
switch ( V_197 ) {
case V_324 :
if ( ! V_37 -> V_325 . V_326 [ V_113 ] )
V_323 = V_327 ;
else
V_323 = V_328 ;
break;
case V_329 :
V_323 = V_327 ;
break;
case V_207 :
V_323 = V_328 ;
break;
default:
F_12 ( V_35 , L_48 ,
V_197 , V_107 , V_113 ) ;
return - V_8 ;
} ;
V_311 = & V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_193 [ V_113 ] ;
V_311 -> V_197 = V_197 ;
F_141 ( V_35 , V_107 , V_113 , V_323 ) ;
if ( F_70 ( V_37 , V_107 , V_113 ) )
F_71 ( V_35 ,
L_49 ,
V_133 , V_113 ) ;
return 0 ;
}
int F_61 ( struct V_34 * V_35 , int V_107 , int V_113 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
if ( V_107 < 1 || V_107 >= V_35 -> V_269 ||
V_113 < 1 || V_113 > V_275 )
return 0 ;
return V_37 -> V_38 . V_162 . V_192 [ V_107 ] . V_219 [ V_113 ] ==
V_330 ;
}
int F_142 ( struct V_34 * V_35 , int V_107 , int V_113 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
if ( V_107 == F_59 ( V_35 ) )
return 1 ;
if ( V_107 < 1 || V_107 >= V_35 -> V_269 ||
V_113 < 1 || V_113 > V_275 )
return 0 ;
return V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_220 [ V_113 ] ==
V_330 ;
}
int F_143 ( struct V_34 * V_35 , int V_107 , int V_113 ,
int V_331 )
{
struct V_36 * V_37 = V_36 ( V_35 ) ;
if ( V_107 == F_59 ( V_35 ) )
return 0 ;
if ( V_107 < 1 || V_107 >= V_35 -> V_269 ||
V_113 < 1 || V_113 > V_275 ||
V_331 < 0 || V_331 > 1 )
return - V_8 ;
V_37 -> V_38 . V_162 . V_194 [ V_107 ] . V_220 [ V_113 ] = V_331 ;
return 0 ;
}
