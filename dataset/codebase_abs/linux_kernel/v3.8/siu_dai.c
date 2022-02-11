static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
F_2 ( V_2 -> V_8 -> V_9 -> V_10 , L_1 , V_11 ) ;
F_3 ( V_6 + V_12 , 0 ) ;
F_4 ( 1 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
F_3 ( V_6 + V_12 , 0x301 ) ;
F_3 ( V_6 + V_15 , 0x40400000 ) ;
F_3 ( V_6 + V_16 , 0 ) ;
F_3 ( V_6 + V_17 , 0 ) ;
F_3 ( V_6 + V_18 , 1 ) ;
F_3 ( V_6 + V_19 , 0 ) ;
F_3 ( V_6 + V_20 , 0x44440000 ) ;
F_3 ( V_6 + V_21 , 0x0c0c0000 ) ;
F_3 ( V_6 + V_22 , V_2 -> V_23 . V_24 ) ;
F_3 ( V_6 + V_25 , V_2 -> V_26 . V_24 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
F_3 ( V_6 + V_12 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
struct V_27 * V_28 = & V_4 -> V_28 ;
T_1 * V_29 = V_28 -> V_30 ;
T_1 V_31 ;
if ( ! V_4 -> V_32 )
V_31 = 1 ;
else
V_31 = 2 ;
V_29 [ 0 ] = ( V_28 -> V_33 [ V_31 ] . V_34 << 16 ) |
( V_28 -> V_33 [ V_31 ] . V_35 << 8 ) |
( V_28 -> V_33 [ V_31 ] . V_36 << 7 ) | 3 ;
V_29 [ 1 ] = V_28 -> V_30 [ 1 ] ;
V_29 [ 2 ] = ( 16 / 2 ) << 24 ;
V_29 [ 3 ] = V_28 -> V_30 [ 3 ] ;
V_29 [ 4 ] = V_28 -> V_30 [ 4 ] ;
V_29 [ 7 ] = V_28 -> V_33 [ V_31 ] . V_37 ;
V_2 -> V_13 |= V_28 -> V_33 [ V_31 ] . V_13 ;
V_2 -> V_14 |= V_28 -> V_33 [ V_31 ] . V_14 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
struct V_27 * V_28 = & V_4 -> V_28 ;
T_1 * V_29 = V_28 -> V_30 ;
T_1 V_31 ;
if ( ! V_4 -> V_32 )
V_31 = 7 ;
else
V_31 = 8 ;
V_29 [ 5 ] = ( V_28 -> V_33 [ V_31 ] . V_34 << 16 ) |
( V_28 -> V_33 [ V_31 ] . V_35 << 8 ) | 1 ;
V_29 [ 6 ] = V_28 -> V_33 [ V_31 ] . V_37 ;
V_2 -> V_13 |= V_28 -> V_33 [ V_31 ] . V_13 ;
V_2 -> V_14 |= V_28 -> V_33 [ V_31 ] . V_14 ;
}
static void F_8 ( struct V_38 * V_38 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
T_1 V_39 , V_40 ;
V_39 = F_9 ( V_6 + V_12 ) ;
V_40 = F_9 ( V_6 + V_20 ) ;
switch ( V_4 -> V_32 ) {
case V_41 :
V_39 |= 0x200 ;
V_40 &= ~ 0xc2 ;
break;
case V_42 :
V_39 |= 0x100 ;
V_40 &= ~ 0x31 ;
break;
}
F_3 ( V_6 + V_12 , V_39 ) ;
F_3 ( V_6 + V_20 , V_40 ) ;
}
static void F_10 ( struct V_38 * V_38 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
T_1 V_43 ;
V_43 = F_9 ( V_6 + V_44 ) ;
switch ( V_4 -> V_32 ) {
case V_41 :
V_43 &= ~ 0xc0000000 ;
break;
case V_42 :
V_43 &= ~ 0x00c00000 ;
break;
}
F_3 ( V_6 + V_44 , V_43 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
struct V_27 * V_28 = & V_4 -> V_28 ;
T_1 * V_29 = V_28 -> V_30 ;
int V_45 ;
T_1 T_2 * V_46 ;
T_1 * V_47 ;
V_47 = V_28 -> V_48 ;
V_46 = V_4 -> V_49 ;
for ( V_45 = 0 ; V_45 < V_50 ; V_45 ++ , V_46 ++ , V_47 ++ )
F_3 ( V_46 , * V_47 ) ;
V_47 = V_28 -> V_51 ;
V_46 = V_4 -> V_49 + ( 0x0100 / sizeof( T_1 ) ) ;
for ( V_45 = 0 ; V_45 < V_52 ; V_45 ++ , V_46 ++ , V_47 ++ )
F_3 ( V_46 , * V_47 ) ;
V_46 = V_4 -> V_53 ;
for ( V_45 = 0 ; V_45 < V_54 + V_55 + V_56 ; V_45 ++ , V_46 ++ )
F_3 ( V_46 , 0 ) ;
V_46 = V_4 -> V_57 ;
for ( V_45 = 0 ; V_45 < V_58 ; V_45 ++ , V_46 ++ )
F_3 ( V_46 , V_29 [ V_45 ] ) ;
V_46 = V_4 -> V_57 + ( 0x0200 / sizeof( T_1 ) ) ;
for ( V_45 = 0 ; V_45 < V_59 ; V_45 ++ , V_46 ++ )
F_3 ( V_46 , V_28 -> V_60 [ V_45 ] ) ;
V_46 = V_4 -> V_57 + ( 0x0600 / sizeof( T_1 ) ) ;
for ( V_45 = 0 ; V_45 < V_61 ; V_45 ++ , V_46 ++ )
F_3 ( V_46 , 0 ) ;
F_3 ( V_6 + V_62 , V_2 -> V_14 ) ;
V_2 -> V_14 = 0x0 ;
F_3 ( V_6 + V_63 , 0 ) ;
F_3 ( V_6 + V_64 , 0xc0000000 ) ;
V_45 = 0x10000 ;
while ( -- V_45 && F_9 ( V_6 + V_64 ) != 0x80000000 )
F_12 () ;
if ( ! V_45 )
return - V_65 ;
F_3 ( V_6 + V_66 , 0x00400000 ) ;
F_3 ( V_6 + V_63 , 0xc0000000 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
F_3 ( V_6 + V_63 , 0 ) ;
F_3 ( V_6 + V_64 , 0 ) ;
V_2 -> V_13 = 0 ;
}
static int F_14 ( struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_15 ( V_68 ) ;
F_2 ( V_2 -> V_8 -> V_9 -> V_10 , L_1 , V_11 ) ;
V_70 -> type = V_71 ;
V_70 -> V_72 = 2 ;
V_70 -> V_73 . integer . V_74 = 0 ;
V_70 -> V_73 . integer . V_75 = V_76 ;
return 0 ;
}
static int F_16 ( struct V_67 * V_68 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_15 ( V_68 ) ;
struct V_79 * V_10 = V_2 -> V_8 -> V_9 -> V_10 ;
T_1 V_80 ;
F_2 ( V_10 , L_1 , V_11 ) ;
switch ( V_68 -> V_81 ) {
case V_82 :
V_80 = V_2 -> V_23 . V_24 ;
V_78 -> V_73 . integer . V_73 [ 0 ] = V_80 & 0xffff ;
V_78 -> V_73 . integer . V_73 [ 1 ] = V_80 >> 16 & 0xffff ;
break;
case V_83 :
V_80 = V_2 -> V_26 . V_24 ;
V_78 -> V_73 . integer . V_73 [ 0 ] = V_80 & 0xffff ;
V_78 -> V_73 . integer . V_73 [ 1 ] = V_80 >> 16 & 0xffff ;
break;
default:
F_17 ( V_10 , L_2 ,
V_11 , V_68 -> V_81 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_18 ( struct V_67 * V_68 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_15 ( V_68 ) ;
struct V_79 * V_10 = V_2 -> V_8 -> V_9 -> V_10 ;
struct V_3 * V_4 = V_5 ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
T_1 V_85 ;
T_1 V_86 ;
F_2 ( V_10 , L_1 , V_11 ) ;
if ( V_78 -> V_73 . integer . V_73 [ 0 ] < 0 ||
V_78 -> V_73 . integer . V_73 [ 0 ] > V_76 ||
V_78 -> V_73 . integer . V_73 [ 1 ] < 0 ||
V_78 -> V_73 . integer . V_73 [ 1 ] > V_76 )
return - V_84 ;
V_85 = V_78 -> V_73 . integer . V_73 [ 0 ] |
V_78 -> V_73 . integer . V_73 [ 1 ] << 16 ;
switch ( V_68 -> V_81 ) {
case V_82 :
V_86 = V_2 -> V_23 . V_24 ;
F_3 ( V_6 + V_22 , V_85 ) ;
V_2 -> V_23 . V_24 = V_85 ;
break;
case V_83 :
V_86 = V_2 -> V_26 . V_24 ;
F_3 ( V_6 + V_25 , V_85 ) ;
V_2 -> V_26 . V_24 = V_85 ;
break;
default:
F_17 ( V_10 , L_2 ,
V_11 , V_68 -> V_81 ) ;
return - V_84 ;
}
if ( V_86 != V_85 )
return 1 ;
return 0 ;
}
int F_19 ( int V_87 , struct V_1 * * V_2 , struct V_88 * V_9 )
{
struct V_79 * V_10 = V_9 -> V_10 ;
struct V_67 * V_68 ;
int V_89 ;
* V_2 = F_20 ( sizeof( * * V_2 ) , V_90 ) ;
if ( ! * V_2 )
return - V_91 ;
F_2 ( V_10 , L_3 , V_11 , V_87 , * V_2 ) ;
( * V_2 ) -> V_23 . V_24 = V_92 ;
( * V_2 ) -> V_26 . V_24 = V_92 ;
V_68 = F_21 ( & V_93 , * V_2 ) ;
V_89 = F_22 ( V_9 , V_68 ) ;
if ( V_89 < 0 )
F_17 ( V_10 ,
L_4 ,
V_68 , V_87 , V_89 ) ;
V_68 = F_21 ( & V_94 , * V_2 ) ;
V_89 = F_22 ( V_9 , V_68 ) ;
if ( V_89 < 0 )
F_17 ( V_10 ,
L_5 ,
V_68 , V_87 , V_89 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_3 * V_4 = F_26 ( V_98 ) ;
struct V_99 * V_100 = V_96 -> V_101 ;
struct V_1 * V_2 = F_27 ( V_96 ) ;
int V_89 ;
F_2 ( V_96 -> V_8 -> V_9 -> V_10 , L_6 , V_11 ,
V_4 -> V_32 , V_2 ) ;
F_28 ( V_96 , & V_102 ) ;
V_89 = F_29 ( V_100 , V_103 ) ;
if ( F_30 ( V_89 < 0 ) )
return V_89 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_3 * V_4 = F_26 ( V_98 ) ;
struct V_1 * V_2 = F_27 ( V_96 ) ;
F_2 ( V_96 -> V_8 -> V_9 -> V_10 , L_6 , V_11 ,
V_4 -> V_32 , V_2 ) ;
if ( V_96 -> V_104 == V_105 )
V_2 -> V_106 &= ~ V_107 ;
else
V_2 -> V_106 &= ~ V_108 ;
if ( ! V_2 -> V_106 ) {
F_32 ( V_2 -> V_23 . V_109 || V_2 -> V_26 . V_109 ) ;
F_13 ( V_2 ) ;
F_5 ( V_2 ) ;
}
}
static int F_33 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_3 * V_4 = F_26 ( V_98 ) ;
struct V_99 * V_100 = V_96 -> V_101 ;
struct V_1 * V_2 = F_27 ( V_96 ) ;
struct V_38 * V_38 ;
int V_110 , V_89 ;
F_2 ( V_96 -> V_8 -> V_9 -> V_10 ,
L_7 ,
V_11 , V_4 -> V_32 , V_2 -> V_106 , V_100 -> V_111 ) ;
if ( V_96 -> V_104 == V_105 ) {
V_110 = V_107 ;
V_38 = & V_2 -> V_23 ;
} else {
V_110 = V_108 ;
V_38 = & V_2 -> V_26 ;
}
if ( ! V_2 -> V_106 ) {
V_38 -> V_109 = 0 ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_38 ) ;
F_10 ( V_38 ) ;
V_89 = F_11 ( V_2 ) ;
if ( V_89 < 0 )
goto V_112;
} else {
V_89 = 0 ;
}
V_2 -> V_106 |= V_110 ;
V_112:
return V_89 ;
}
static int F_34 ( struct V_97 * V_98 ,
unsigned int V_113 )
{
struct V_3 * V_4 = F_26 ( V_98 ) ;
T_1 T_2 * V_6 = V_4 -> V_7 ;
T_1 V_40 ;
F_2 ( V_98 -> V_10 , L_8 ,
V_11 , V_113 , V_4 -> V_32 ) ;
if ( V_4 -> V_32 < 0 )
return - V_114 ;
switch ( V_113 & V_115 ) {
case V_116 :
V_40 = V_117 [ V_4 -> V_32 ] . V_23 . V_118 |
V_117 [ V_4 -> V_32 ] . V_26 . V_118 ;
break;
case V_119 :
V_40 = V_117 [ V_4 -> V_32 ] . V_23 . V_8 |
V_117 [ V_4 -> V_32 ] . V_26 . V_8 ;
break;
default:
return - V_84 ;
}
V_40 |= ~ ( V_117 [ V_4 -> V_32 ] . V_23 . V_120 |
V_117 [ V_4 -> V_32 ] . V_26 . V_120 ) &
F_9 ( V_6 + V_20 ) ;
F_3 ( V_6 + V_20 , V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_97 * V_98 , int V_121 ,
unsigned int V_122 , int V_36 )
{
struct V_123 * V_124 , * V_125 ;
char * V_126 , * V_127 ;
int V_89 ;
if ( V_36 != V_128 )
return - V_84 ;
F_2 ( V_98 -> V_10 , L_9 , V_11 , V_121 ) ;
switch ( V_121 ) {
case V_129 :
V_126 = L_10 ;
V_127 = L_11 ;
break;
case V_130 :
V_126 = L_10 ;
V_127 = L_12 ;
break;
case V_131 :
V_126 = L_13 ;
V_127 = L_11 ;
break;
case V_132 :
V_126 = L_13 ;
V_127 = L_14 ;
break;
default:
return - V_84 ;
}
V_124 = F_36 ( V_98 -> V_10 , V_126 ) ;
if ( F_37 ( V_124 ) ) {
F_17 ( V_98 -> V_10 , L_15 , V_11 ,
F_38 ( V_124 ) ) ;
return F_38 ( V_124 ) ;
}
V_125 = F_36 ( V_98 -> V_10 , V_127 ) ;
if ( F_37 ( V_125 ) ) {
V_89 = F_38 ( V_125 ) ;
F_17 ( V_98 -> V_10 , L_16 , V_89 ) ;
goto V_133;
}
V_89 = F_39 ( V_124 , V_125 ) ;
if ( V_89 < 0 ) {
F_17 ( V_98 -> V_10 , L_17 , V_89 ) ;
goto V_134;
}
V_89 = F_40 ( V_124 , V_122 ) ;
if ( V_89 < 0 )
F_17 ( V_98 -> V_10 , L_18 , V_89 ) ;
V_134:
F_41 ( V_125 ) ;
V_133:
F_41 ( V_124 ) ;
return V_89 ;
}
static int F_42 ( struct V_135 * V_136 )
{
const struct V_137 * V_138 ;
struct V_139 * V_140 , * V_141 ;
struct V_3 * V_4 ;
int V_89 ;
V_4 = F_43 ( sizeof( * V_4 ) , V_90 ) ;
if ( ! V_4 )
return - V_91 ;
V_5 = V_4 ;
V_4 -> V_10 = & V_136 -> V_10 ;
V_89 = F_44 ( & V_138 , L_19 , & V_136 -> V_10 ) ;
if ( V_89 )
goto V_142;
memcpy ( & V_4 -> V_28 , V_138 -> V_143 , V_138 -> V_144 ) ;
F_45 ( V_138 ) ;
V_140 = F_46 ( V_136 , V_145 , 0 ) ;
if ( ! V_140 ) {
V_89 = - V_114 ;
goto V_146;
}
V_141 = F_47 ( V_140 -> V_147 , F_48 ( V_140 ) ,
V_136 -> V_148 ) ;
if ( ! V_141 ) {
F_17 ( & V_136 -> V_10 , L_20 ) ;
V_89 = - V_65 ;
goto V_149;
}
V_89 = - V_91 ;
V_4 -> V_49 = F_49 ( V_140 -> V_147 , V_150 ) ;
if ( ! V_4 -> V_49 )
goto V_151;
V_4 -> V_53 = F_49 ( V_140 -> V_147 + V_152 , V_153 ) ;
if ( ! V_4 -> V_53 )
goto V_154;
V_4 -> V_57 = F_49 ( V_140 -> V_147 + V_155 , V_156 ) ;
if ( ! V_4 -> V_57 )
goto V_157;
V_4 -> V_7 = F_49 ( V_140 -> V_147 + V_158 , F_48 ( V_140 ) -
V_158 ) ;
if ( ! V_4 -> V_7 )
goto V_159;
F_50 ( & V_136 -> V_10 , V_4 ) ;
V_89 = F_51 ( & V_136 -> V_10 , & V_160 , 1 ) ;
if ( V_89 < 0 )
goto V_161;
V_89 = F_52 ( & V_136 -> V_10 , & V_162 ) ;
if ( V_89 < 0 )
goto V_163;
F_53 ( & V_136 -> V_10 ) ;
return V_89 ;
V_163:
F_54 ( & V_136 -> V_10 ) ;
V_161:
F_55 ( V_4 -> V_7 ) ;
V_159:
F_55 ( V_4 -> V_57 ) ;
V_157:
F_55 ( V_4 -> V_53 ) ;
V_154:
F_55 ( V_4 -> V_49 ) ;
V_151:
F_56 ( V_140 -> V_147 , F_48 ( V_140 ) ) ;
V_149:
V_146:
V_142:
F_24 ( V_4 ) ;
return V_89 ;
}
static int F_57 ( struct V_135 * V_136 )
{
struct V_3 * V_4 = F_58 ( & V_136 -> V_10 ) ;
struct V_139 * V_140 ;
F_59 ( & V_136 -> V_10 ) ;
F_60 ( & V_136 -> V_10 ) ;
F_54 ( & V_136 -> V_10 ) ;
F_55 ( V_4 -> V_7 ) ;
F_55 ( V_4 -> V_57 ) ;
F_55 ( V_4 -> V_53 ) ;
F_55 ( V_4 -> V_49 ) ;
V_140 = F_46 ( V_136 , V_145 , 0 ) ;
if ( V_140 )
F_56 ( V_140 -> V_147 , F_48 ( V_140 ) ) ;
F_24 ( V_4 ) ;
return 0 ;
}
