static int F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 , V_5 , V_6 , V_7 , V_8 ;
int V_9 , V_10 , V_11 , V_12 ;
if ( V_1 < 3333 || V_1 > 200000 )
return - 1 ;
V_10 = 1000000 ;
for ( V_6 = 1 ; V_6 <= 8 ; ++ V_6 ) {
for ( V_7 = 1 ; V_7 <= V_6 ; ++ V_7 ) {
V_8 = V_6 * V_7 ;
V_9 = F_2 ( V_1 , V_8 ) ;
if ( V_9 < 1666 || V_9 > 2857 )
continue;
for ( V_4 = 1 ; V_4 <= 64 ; ++ V_4 ) {
V_12 = V_4 * V_3 -> V_13 ;
if ( V_12 > 500000 )
break;
V_5 = V_12 * V_8 / V_1 ;
if ( V_5 < 3 || V_5 > 160 )
continue;
V_11 = V_3 -> V_13 * V_4 * V_8 / V_5 ;
V_11 -= V_1 ;
if ( V_11 >= 0 && V_11 < V_10 ) {
V_3 -> V_14 = V_4 ;
V_3 -> V_15 = V_5 ;
V_3 -> V_16 = V_6 ;
V_3 -> V_17 = V_7 ;
V_10 = V_11 ;
}
}
}
}
if ( V_10 == 1000000 )
return - 1 ;
return 0 ;
}
static int F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_13 * V_3 -> V_14 * V_3 -> V_16 * V_3 -> V_17
/ V_3 -> V_15 ;
}
static int F_4 ( struct V_18 * V_19 ,
struct V_2 * V_3 )
{
if ( V_19 -> V_20 + V_19 -> V_21 > V_19 -> V_22 ||
V_19 -> V_23 + V_19 -> V_24 > V_19 -> V_25 ||
V_19 -> V_22 > 4096 )
return - V_26 ;
if ( ( V_19 -> V_27 & V_28 ) != V_29 )
return - V_26 ;
if ( F_1 ( V_19 -> V_30 , V_3 ) < 0 )
return - V_26 ;
switch ( V_19 -> V_31 ) {
case 32 :
if ( V_19 -> V_32 . V_33 )
V_3 -> V_34 = V_35 ;
else
V_3 -> V_34 = V_36 ;
break;
case 24 :
V_3 -> V_34 = V_36 ;
break;
case 16 :
if ( V_19 -> V_37 . V_33 == 5 )
V_3 -> V_34 = V_38 ;
else
V_3 -> V_34 = V_39 ;
break;
case 8 :
V_3 -> V_34 = V_40 ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static void F_5 ( struct V_18 * V_19 ,
int V_34 )
{
V_19 -> V_31 = V_41 [ V_34 ] * 8 ;
V_19 -> V_42 = V_43 ;
V_19 -> V_37 = V_43 ;
V_19 -> V_44 = V_43 ;
V_19 -> V_32 = V_45 ;
switch ( V_34 ) {
case V_39 :
V_19 -> V_42 . V_33 = 5 ;
V_19 -> V_37 . V_33 = 6 ;
V_19 -> V_44 . V_33 = 5 ;
break;
case V_38 :
V_19 -> V_42 . V_33 = 5 ;
V_19 -> V_37 . V_33 = 5 ;
V_19 -> V_44 . V_33 = 5 ;
V_19 -> V_32 . V_33 = 1 ;
break;
case V_35 :
V_19 -> V_32 . V_33 = 8 ;
break;
}
if ( V_34 != V_40 ) {
V_19 -> V_37 . V_46 = V_19 -> V_42 . V_33 ;
V_19 -> V_44 . V_46 = V_19 -> V_37 . V_46 + V_19 -> V_37 . V_33 ;
if ( V_19 -> V_32 . V_33 )
V_19 -> V_32 . V_46 =
V_19 -> V_44 . V_46 + V_19 -> V_44 . V_33 ;
}
}
static int F_6 ( struct V_18 * V_19 ,
struct V_47 * V_48 )
{
struct V_2 V_3 ;
int V_49 ;
V_3 = * (struct V_2 * ) V_48 -> V_3 ;
V_49 = F_4 ( V_19 , & V_3 ) ;
if ( ! V_49 ) {
V_19 -> V_30 = F_3 ( & V_3 ) ;
F_5 ( V_19 , V_3 . V_34 ) ;
}
return V_49 ;
}
static int F_7 ( struct V_47 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_3 ;
struct V_18 * V_19 = & V_48 -> V_19 ;
int V_49 ;
T_1 V_50 , V_51 ;
unsigned int V_52 , V_34 , V_53 ;
unsigned int V_54 , V_55 ;
unsigned int V_56 , V_57 ;
struct V_2 V_58 ;
V_58 = * V_3 ;
V_49 = F_4 ( V_19 , V_3 ) ;
if ( V_49 ) {
* V_3 = V_58 ;
return V_49 ;
}
V_50 = F_8 ( V_3 , V_59 ) ;
V_50 &= ~ ( V_60 | V_61 ) ;
F_9 ( V_3 , V_59 , V_50 ) ;
V_51 = F_8 ( V_3 , V_62 ) & ~ 0x7f ;
if ( V_3 -> V_15 < 38 )
V_51 |= 0x29 ;
if ( V_3 -> V_15 < 69 )
V_51 |= 0x35 ;
else if ( V_3 -> V_15 < 100 )
V_51 |= 0x76 ;
else
V_51 |= 0x7e ;
F_9 ( V_3 , V_62 , V_51 ) ;
F_9 ( V_3 , V_63 , V_64 [ V_3 -> V_14 - 1 ] ) ;
F_9 ( V_3 , V_65 , V_66 [ V_3 -> V_15 - 2 ] ) ;
V_51 = ( ( 8 - V_3 -> V_17 ) << 3 ) | ( 8 - V_3 -> V_16 ) ;
if ( V_3 -> V_16 == 8 || V_3 -> V_17 == 8 ) {
F_9 ( V_3 , V_67 , V_51 | 0x9 ) ;
F_10 ( 1 ) ;
}
F_9 ( V_3 , V_67 , V_51 ) ;
F_11 ( 20 ) ;
F_9 ( V_3 , V_68 , V_69 ) ;
F_9 ( V_3 , V_70 , V_71 | ( V_71 << 16 ) ) ;
F_10 ( 10 ) ;
F_9 ( V_3 , V_70 , V_71 << 16 ) ;
V_57 = V_19 -> V_20 + V_19 -> V_72 + V_19 -> V_73 +
V_19 -> V_74 ;
F_9 ( V_3 , V_75 , V_57 - 1 ) ;
F_9 ( V_3 , V_76 , V_19 -> V_20 - 1 ) ;
F_9 ( V_3 , V_77 , V_19 -> V_20 + V_19 -> V_73 - 1 ) ;
F_9 ( V_3 , V_78 ,
V_19 -> V_20 + V_19 -> V_73 + V_19 -> V_74 - 1 ) ;
F_9 ( V_3 , V_79 ,
V_19 -> V_20 + V_19 -> V_73 + V_19 -> V_74 - 1 ) ;
F_9 ( V_3 , V_80 ,
V_19 -> V_23 + V_19 -> V_81 + V_19 -> V_82 +
V_19 -> V_83 - 1 ) ;
F_9 ( V_3 , V_84 , V_19 -> V_23 - 1 ) ;
F_9 ( V_3 , V_85 , V_19 -> V_23 + V_19 -> V_82 - 1 ) ;
F_9 ( V_3 , V_86 ,
V_19 -> V_23 + V_19 -> V_82 + V_19 -> V_83 - 1 ) ;
V_56 = 3300000 / V_19 -> V_30 ;
if ( V_56 >= V_57 )
V_56 = V_57 - 1 ;
F_9 ( V_3 , V_87 , V_57 - V_56 - 1 ) ;
V_50 |= V_60 | V_61 ;
F_9 ( V_3 , V_59 , V_50 ) ;
if ( V_19 -> V_22 > 2048 ) {
V_53 = 4096 ;
V_52 = V_88 ;
} else if ( V_19 -> V_22 > 1024 ) {
V_53 = 2048 ;
V_52 = V_89 ;
} else {
V_53 = 1024 ;
V_52 = V_90 ;
}
V_54 = ( V_19 -> V_22 + 63 ) >> 6 ;
F_9 ( V_3 , V_91 , V_92 | ( V_54 << 16 ) | 0 ) ;
F_9 ( V_3 , V_93 , V_92 | ( V_54 << 16 ) | 0 ) ;
F_9 ( V_3 , V_94 , V_92 | ( V_54 << 16 ) | 0 ) ;
F_9 ( V_3 , V_95 , V_92 | ( V_54 << 16 ) | 0 ) ;
F_9 ( V_3 , V_96 , ( V_19 -> V_21 << 16 ) | V_19 -> V_24 ) ;
F_9 ( V_3 , V_97 , ( V_19 -> V_20 << 16 ) | V_19 -> V_23 ) ;
V_34 = V_3 -> V_34 ;
V_52 |= V_98 | V_34 ;
F_9 ( V_3 , V_99 , V_52 ) ;
for ( V_55 = 0 ; V_55 < 32 ; ++ V_55 ) {
F_9 ( V_3 , V_100 + ( V_55 << 4 ) , V_101 [ V_34 ] ) ;
F_9 ( V_3 , V_102 + ( V_55 << 4 ) , 0 ) ;
F_9 ( V_3 , V_103 + ( V_55 << 4 ) , 0 ) ;
F_9 ( V_3 , V_104 + ( V_55 << 4 ) , V_105 ) ;
}
V_50 = F_8 ( V_3 , V_106 ) &
~ ( V_107 | V_108 |
V_109 ) ;
if ( V_19 -> V_110 & V_111 )
V_50 |= V_107 ;
if ( ! ( V_19 -> V_110 & V_112 ) )
V_50 |= V_108 ;
if ( ! ( V_19 -> V_110 & V_113 ) )
V_50 |= V_109 ;
F_9 ( V_3 , V_106 , V_50 ) ;
V_48 -> V_114 . V_115 = V_53 * V_41 [ V_34 ] ;
V_48 -> V_114 . V_116 = ( V_34 == V_40 ) ? V_117 :
V_118 ;
return 0 ;
}
static int F_12 ( unsigned int V_119 , unsigned int V_42 ,
unsigned int V_37 , unsigned int V_44 ,
unsigned int V_32 , struct V_47 * V_48 )
{
T_1 V_120 ;
struct V_2 * V_3 = V_48 -> V_3 ;
if ( V_119 > 1023 )
return 1 ;
V_120 = ( ( V_32 & 0xff00 ) << 16 ) | ( ( V_42 & 0xff00 ) << 8 ) |
( V_37 & 0xff00 ) | ( V_44 >> 8 ) ;
F_9 ( V_3 , V_121 + V_119 * 4 , V_120 ) ;
if ( V_119 < 16 && V_3 -> V_34 != V_40 ) {
T_1 * V_122 = V_48 -> V_123 ;
T_1 V_124 = V_119 ;
switch ( V_3 -> V_34 ) {
case V_39 :
V_124 |= ( V_119 << 11 ) | ( V_119 << 6 ) ;
break;
case V_38 :
V_124 |= ( V_119 << 10 ) | ( V_119 << 5 ) ;
break;
case V_35 :
V_124 |= ( V_119 << 24 ) ;
case V_36 :
V_124 |= ( V_119 << 16 ) | ( V_119 << 8 ) ;
break;
}
V_122 [ V_119 ] = V_124 ;
}
return 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
struct V_47 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_3 ;
if ( V_19 -> V_21 & 7 )
return - V_26 ;
if ( V_19 -> V_21 + V_48 -> V_19 . V_20 > V_48 -> V_19 . V_22 ||
V_19 -> V_24 + V_48 -> V_19 . V_23 > V_48 -> V_19 . V_25 )
return - V_26 ;
F_9 ( V_3 , V_96 , ( V_19 -> V_21 << 16 ) | V_19 -> V_24 ) ;
return 0 ;
}
static int F_14 ( int V_125 , struct V_47 * V_48 )
{
struct V_2 * V_3 = V_48 -> V_3 ;
int V_126 , V_127 ;
V_126 = F_8 ( V_3 , V_106 ) ;
V_126 &= ~ ( V_128 | V_129 | V_130 ) ;
V_127 = F_8 ( V_3 , V_131 ) ;
V_127 |= V_132 ;
switch ( V_125 ) {
case V_133 :
V_127 &= ~ V_132 ;
break;
case V_134 :
V_126 |= V_128 ;
break;
case V_135 :
V_126 |= V_129 ;
break;
case V_136 :
V_126 |= V_130 ;
break;
default: ;
}
F_9 ( V_3 , V_106 , V_126 ) ;
F_9 ( V_3 , V_131 , V_127 ) ;
return 0 ;
}
static int F_15 ( struct V_137 * V_138 , const struct V_139 * V_140 )
{
int V_49 ;
unsigned long V_141 , V_142 ;
struct V_2 * V_3 ;
struct V_47 * V_48 ;
struct V_18 V_19 ;
enum V_143 V_144 ;
V_49 = F_16 ( V_138 ) ;
if ( V_49 ) {
F_17 ( & V_138 -> V_145 , L_1 ,
V_49 ) ;
return V_49 ;
}
V_141 = F_18 ( V_138 , 0 ) ;
if ( ! F_19 ( V_141 , F_20 ( V_138 , 0 ) ,
L_2 ) ) {
F_17 ( & V_138 -> V_145 , L_3 ) ;
goto V_146;
}
V_142 = F_18 ( V_138 , 1 ) ;
if ( ! F_19 ( V_142 , F_20 ( V_138 , 1 ) ,
L_4 ) ) {
F_17 ( & V_138 -> V_145 , L_5 ) ;
goto V_147;
}
V_48 = F_21 ( sizeof( struct V_2 ) , & V_138 -> V_145 ) ;
if ( ! V_48 ) {
F_17 ( & V_138 -> V_145 , L_6 ) ;
goto V_148;
}
V_3 = V_48 -> V_3 ;
V_144 = V_140 -> V_149 ;
V_3 -> V_13 = V_150 [ V_144 ] . V_13 ;
V_48 -> V_114 = V_151 ;
F_22 ( V_48 -> V_114 . V_152 , V_150 [ V_144 ] . V_153 ,
sizeof( V_48 -> V_114 . V_152 ) ) ;
V_48 -> V_123 = V_3 -> V_123 ;
V_48 -> V_114 . V_154 = V_141 ;
V_3 -> V_155 = F_23 ( V_138 , 0 ) ;
if ( ! V_3 -> V_155 ) {
F_17 ( & V_138 -> V_145 , L_7 ) ;
goto V_156;
}
V_48 -> V_114 . V_157 = V_142 ;
V_48 -> V_114 . V_158 = F_20 ( V_138 , 1 ) ;
V_48 -> V_159 = F_23 ( V_138 , 1 ) ;
if ( ! V_48 -> V_159 ) {
F_17 ( & V_138 -> V_145 , L_8 ) ;
goto V_160;
}
F_24 ( V_138 , V_48 ) ;
F_25 ( V_138 , V_161 , 0x333300 ) ;
V_48 -> V_162 = & V_163 ;
V_48 -> V_164 = V_165 ;
V_49 = F_26 ( & V_48 -> V_166 , 256 , 0 ) ;
if ( V_49 ) {
F_17 ( & V_138 -> V_145 , L_9 ) ;
goto V_167;
}
F_14 ( V_133 , V_48 ) ;
if ( ! F_27 ( & V_19 , V_48 , V_168 , NULL , 0 , & V_169 , 8 ) ) {
F_17 ( & V_138 -> V_145 , L_10 ) ;
goto V_170;
}
V_48 -> V_19 = V_19 ;
if ( F_7 ( V_48 ) ) {
F_28 ( V_171 L_11 ) ;
goto V_170;
}
if ( F_29 ( V_48 ) < 0 ) {
F_17 ( & V_138 -> V_145 , L_12 ) ;
goto V_170;
}
F_28 ( V_172 L_13 ,
V_48 -> V_173 , V_48 -> V_114 . V_152 ) ;
return 0 ;
V_170:
F_30 ( & V_48 -> V_166 ) ;
V_167:
F_31 ( V_48 -> V_159 ) ;
V_160:
F_31 ( V_3 -> V_155 ) ;
V_156:
F_32 ( V_48 ) ;
V_148:
F_33 ( V_142 , F_20 ( V_138 , 1 ) ) ;
V_147:
F_33 ( V_141 , F_20 ( V_138 , 0 ) ) ;
V_146:
return - V_174 ;
}
static void F_34 ( struct V_137 * V_138 )
{
struct V_47 * V_48 = F_35 ( V_138 ) ;
struct V_2 * V_3 ;
if ( ! V_48 )
return;
V_3 = V_48 -> V_3 ;
F_36 ( V_48 ) ;
F_30 ( & V_48 -> V_166 ) ;
F_31 ( V_3 -> V_155 ) ;
F_31 ( V_48 -> V_159 ) ;
F_33 ( F_18 ( V_138 , 0 ) ,
F_20 ( V_138 , 0 ) ) ;
F_33 ( F_18 ( V_138 , 1 ) ,
F_20 ( V_138 , 1 ) ) ;
F_32 ( V_48 ) ;
}
static int F_37 ( void )
{
#ifndef F_38
if ( F_39 ( L_14 , & V_168 ) )
return - V_174 ;
#endif
return F_40 ( & V_175 ) ;
}
static void T_2 F_41 ( void )
{
F_42 ( & V_175 ) ;
}
