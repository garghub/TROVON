void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
memset ( & V_2 -> V_5 , 0 , sizeof( struct V_6 ) ) ;
V_2 -> V_5 . V_7 = F_2 ( V_3 , 120 , 8 ) ;
V_2 -> V_5 . V_8 = F_2 ( V_3 , 104 , 16 ) ;
V_2 -> V_5 . V_9 [ 0 ] = F_2 ( V_3 , 96 , 8 ) ;
V_2 -> V_5 . V_9 [ 1 ] = F_2 ( V_3 , 88 , 8 ) ;
V_2 -> V_5 . V_9 [ 2 ] = F_2 ( V_3 , 80 , 8 ) ;
V_2 -> V_5 . V_9 [ 3 ] = F_2 ( V_3 , 72 , 8 ) ;
V_2 -> V_5 . V_9 [ 4 ] = F_2 ( V_3 , 64 , 8 ) ;
V_2 -> V_5 . V_10 = F_2 ( V_3 , 60 , 4 ) ;
V_2 -> V_5 . V_11 = F_2 ( V_3 , 56 , 4 ) ;
V_2 -> V_5 . V_12 = F_2 ( V_3 , 24 , 32 ) ;
V_2 -> V_5 . V_13 = F_2 ( V_3 , 12 , 8 ) ;
V_2 -> V_5 . V_14 = F_2 ( V_3 , 8 , 4 ) ;
V_2 -> V_5 . V_13 += 2000 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned int V_17 , V_18 , V_19 ;
T_1 * V_3 = V_2 -> V_20 ;
V_19 = F_2 ( V_3 , 126 , 2 ) ;
switch ( V_19 ) {
case 0 :
V_18 = F_2 ( V_3 , 115 , 4 ) ;
V_17 = F_2 ( V_3 , 112 , 3 ) ;
V_16 -> V_21 = ( V_22 [ V_17 ] * V_23 [ V_18 ] + 9 ) / 10 ;
V_16 -> V_24 = F_2 ( V_3 , 104 , 8 ) * 100 ;
V_18 = F_2 ( V_3 , 99 , 4 ) ;
V_17 = F_2 ( V_3 , 96 , 3 ) ;
V_16 -> V_25 = V_26 [ V_17 ] * V_27 [ V_18 ] ;
V_16 -> V_28 = F_2 ( V_3 , 84 , 12 ) ;
V_17 = F_2 ( V_3 , 47 , 3 ) ;
V_18 = F_2 ( V_3 , 62 , 12 ) ;
V_16 -> V_29 = ( 1 + V_18 ) << ( V_17 + 2 ) ;
V_16 -> V_30 = F_2 ( V_3 , 80 , 4 ) ;
V_16 -> V_31 = F_2 ( V_3 , 79 , 1 ) ;
V_16 -> V_32 = F_2 ( V_3 , 78 , 1 ) ;
V_16 -> V_33 = F_2 ( V_3 , 77 , 1 ) ;
V_16 -> V_34 = F_2 ( V_3 , 26 , 3 ) ;
V_16 -> V_35 = F_2 ( V_3 , 22 , 4 ) ;
V_16 -> V_36 = F_2 ( V_3 , 21 , 1 ) ;
if ( F_2 ( V_3 , 46 , 1 ) ) {
V_16 -> V_37 = 1 ;
} else if ( V_16 -> V_35 >= 9 ) {
V_16 -> V_37 = F_2 ( V_3 , 39 , 7 ) + 1 ;
V_16 -> V_37 <<= V_16 -> V_35 - 9 ;
}
break;
case 1 :
F_4 ( V_2 ) ;
V_16 -> V_21 = 0 ;
V_16 -> V_24 = 0 ;
V_18 = F_2 ( V_3 , 99 , 4 ) ;
V_17 = F_2 ( V_3 , 96 , 3 ) ;
V_16 -> V_25 = V_26 [ V_17 ] * V_27 [ V_18 ] ;
V_16 -> V_28 = F_2 ( V_3 , 84 , 12 ) ;
V_16 -> V_38 = F_2 ( V_3 , 48 , 22 ) ;
if ( V_16 -> V_38 >= 0xFFFF )
F_5 ( V_2 ) ;
V_18 = F_2 ( V_3 , 48 , 22 ) ;
V_16 -> V_29 = ( 1 + V_18 ) << 10 ;
V_16 -> V_30 = 9 ;
V_16 -> V_31 = 0 ;
V_16 -> V_32 = 0 ;
V_16 -> V_33 = 0 ;
V_16 -> V_34 = 4 ;
V_16 -> V_35 = 9 ;
V_16 -> V_36 = 0 ;
V_16 -> V_37 = 1 ;
break;
default:
F_6 ( L_1 ,
F_7 ( V_2 -> V_39 ) , V_19 ) ;
return - V_40 ;
}
V_2 -> V_37 = V_16 -> V_37 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_42 ;
unsigned int V_43 ;
T_1 V_3 [ 4 ] ;
V_3 [ 3 ] = V_2 -> V_44 [ 1 ] ;
V_3 [ 2 ] = V_2 -> V_44 [ 0 ] ;
V_43 = F_2 ( V_3 , 60 , 4 ) ;
if ( V_43 != 0 ) {
F_6 ( L_2 ,
F_7 ( V_2 -> V_39 ) , V_43 ) ;
return - V_40 ;
}
V_42 -> V_45 = F_2 ( V_3 , 56 , 4 ) ;
V_42 -> V_46 = F_2 ( V_3 , 48 , 4 ) ;
if ( V_42 -> V_45 == V_47 )
V_42 -> V_48 = F_2 ( V_3 , 47 , 1 ) ;
if ( F_2 ( V_3 , 55 , 1 ) )
V_2 -> V_49 = 0xFF ;
else
V_2 -> V_49 = 0x0 ;
if ( V_42 -> V_48 )
V_42 -> V_50 = F_2 ( V_3 , 32 , 2 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_51 , V_52 , V_53 , V_54 ;
int V_55 , V_56 , V_57 ;
T_1 * V_58 ;
if ( ! ( V_2 -> V_16 . V_28 & V_59 ) ) {
F_10 ( L_3
L_4 , F_7 ( V_2 -> V_39 ) ) ;
return 0 ;
}
V_58 = F_11 ( 64 , V_60 ) ;
if ( ! V_58 )
return - V_61 ;
V_55 = F_12 ( V_2 , V_58 ) ;
if ( V_55 ) {
F_10 ( L_5
L_6 , F_7 ( V_2 -> V_39 ) ) ;
V_55 = 0 ;
goto V_62;
}
for ( V_56 = 0 ; V_56 < 16 ; V_56 ++ )
V_58 [ V_56 ] = F_13 ( V_58 [ V_56 ] ) ;
V_57 = V_2 -> V_42 . V_48 ? 0xF : 0x9 ;
V_51 = F_2 ( V_58 , 428 - 384 , 4 ) ;
if ( V_51 > 0 && V_51 <= V_57 ) {
V_2 -> V_58 . V_51 = 1 << ( V_51 + 4 ) ;
V_52 = F_2 ( V_58 , 408 - 384 , 16 ) ;
V_53 = F_2 ( V_58 , 402 - 384 , 6 ) ;
V_54 = F_2 ( V_58 , 400 - 384 , 2 ) ;
if ( V_52 && V_53 ) {
V_2 -> V_58 . V_63 = ( V_53 * 1000 ) / V_52 ;
V_2 -> V_58 . V_64 = V_54 * 1000 ;
}
} else {
F_10 ( L_7
L_8 , F_7 ( V_2 -> V_39 ) ) ;
}
V_62:
F_14 ( V_58 ) ;
return V_55 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_55 ;
T_2 * V_65 ;
if ( V_2 -> V_42 . V_45 < V_66 )
return 0 ;
if ( ! ( V_2 -> V_16 . V_28 & V_67 ) ) {
F_10 ( L_9
L_10 ,
F_7 ( V_2 -> V_39 ) ) ;
return 0 ;
}
V_55 = - V_68 ;
V_65 = F_11 ( 64 , V_60 ) ;
if ( ! V_65 ) {
F_6 ( L_11
L_12 ,
F_7 ( V_2 -> V_39 ) ) ;
return - V_61 ;
}
V_55 = F_16 ( V_2 , 0 , 0 , 0 , V_65 ) ;
if ( V_55 ) {
if ( V_55 != - V_40 && V_55 != - V_69 && V_55 != - V_70 )
goto V_62;
F_10 ( L_13 ,
F_7 ( V_2 -> V_39 ) ) ;
V_55 = 0 ;
goto V_62;
}
if ( V_65 [ 13 ] & V_71 )
V_2 -> V_72 . V_73 = V_74 ;
if ( V_2 -> V_42 . V_48 ) {
V_2 -> V_72 . V_75 = V_65 [ 13 ] ;
V_2 -> V_72 . V_76 = V_65 [ 9 ] ;
}
V_62:
F_14 ( V_65 ) ;
return V_55 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_55 ;
T_2 * V_65 ;
if ( V_2 -> V_42 . V_45 < V_66 )
return 0 ;
if ( ! ( V_2 -> V_16 . V_28 & V_67 ) )
return 0 ;
if ( ! ( V_2 -> V_39 -> V_77 & V_78 ) )
return 0 ;
if ( V_2 -> V_72 . V_73 == 0 )
return 0 ;
V_55 = - V_68 ;
V_65 = F_11 ( 64 , V_60 ) ;
if ( ! V_65 ) {
F_6 ( L_11
L_12 , F_7 ( V_2 -> V_39 ) ) ;
return - V_61 ;
}
V_55 = F_16 ( V_2 , 1 , 0 , 1 , V_65 ) ;
if ( V_55 )
goto V_62;
if ( ( V_65 [ 16 ] & 0xF ) != 1 ) {
F_10 ( L_14
L_15 ,
F_7 ( V_2 -> V_39 ) ) ;
V_55 = 0 ;
} else {
V_55 = 1 ;
}
V_62:
F_14 ( V_65 ) ;
return V_55 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_65 )
{
int V_79 = V_80 ;
int V_81 = V_80 ;
int V_82 ;
int V_55 ;
if ( ! ( V_2 -> V_39 -> V_77 & ( V_83 | V_84
| V_85 ) ) )
return 0 ;
if ( ! V_2 -> V_39 -> V_86 -> V_87 )
return 0 ;
if ( V_2 -> V_39 -> V_77 & V_83 )
V_79 |= V_88 ;
if ( V_2 -> V_39 -> V_77 & V_84 )
V_79 |= V_89 ;
if ( V_2 -> V_39 -> V_77 & V_85 )
V_79 |= V_90 ;
if ( V_2 -> V_72 . V_76 & V_88 )
V_81 |= V_88 ;
if ( V_2 -> V_72 . V_76 & V_89 )
V_81 |= V_89 ;
if ( V_2 -> V_72 . V_76 & V_90 )
V_81 |= V_90 ;
F_19 ( V_2 -> V_39 ) ;
V_82 = V_2 -> V_39 -> V_86 -> V_87 (
V_2 -> V_72 . V_91 ,
V_79 , V_81 ) ;
F_20 ( V_2 -> V_39 ) ;
V_55 = F_16 ( V_2 , 1 , 2 , V_82 , V_65 ) ;
if ( V_55 )
return V_55 ;
if ( ( V_65 [ 15 ] & 0xF ) != V_82 ) {
F_10 ( L_16 ,
F_7 ( V_2 -> V_39 ) ) ;
return 0 ;
}
F_21 ( V_2 -> V_39 , V_82 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( ! F_23 ( V_2 -> V_39 ) ) {
V_2 -> V_92 = 0 ;
return;
}
if ( ( V_2 -> V_39 -> V_77 & V_93 ) &&
( V_2 -> V_72 . V_75 & V_94 ) ) {
V_2 -> V_92 = V_95 ;
} else if ( ( V_2 -> V_39 -> V_77 & V_96 ) &&
( V_2 -> V_72 . V_75 & V_97 ) ) {
V_2 -> V_92 = V_98 ;
} else if ( ( V_2 -> V_39 -> V_77 & ( V_93 |
V_99 ) ) && ( V_2 -> V_72 . V_75 &
V_100 ) ) {
V_2 -> V_92 = V_101 ;
} else if ( ( V_2 -> V_39 -> V_77 & ( V_93 |
V_99 | V_102 ) ) &&
( V_2 -> V_72 . V_75 & V_103 ) ) {
V_2 -> V_92 = V_104 ;
} else if ( ( V_2 -> V_39 -> V_77 & ( V_93 |
V_99 | V_102 |
V_105 ) ) && ( V_2 -> V_72 . V_75 &
V_106 ) ) {
V_2 -> V_92 = V_107 ;
}
}
static int F_24 ( struct V_1 * V_2 , T_2 * V_65 )
{
int V_55 ;
unsigned int V_108 = 0 ;
switch ( V_2 -> V_92 ) {
case V_95 :
V_108 = V_109 ;
V_2 -> V_72 . V_91 = V_110 ;
break;
case V_98 :
V_108 = V_111 ;
V_2 -> V_72 . V_91 = V_112 ;
break;
case V_101 :
V_108 = V_113 ;
V_2 -> V_72 . V_91 = V_114 ;
break;
case V_104 :
V_108 = V_115 ;
V_2 -> V_72 . V_91 = V_116 ;
break;
case V_107 :
V_108 = V_117 ;
V_2 -> V_72 . V_91 = V_118 ;
break;
default:
return 0 ;
}
V_55 = F_16 ( V_2 , 1 , 0 , V_2 -> V_92 , V_65 ) ;
if ( V_55 )
return V_55 ;
if ( ( V_65 [ 16 ] & 0xF ) != V_2 -> V_92 )
F_10 ( L_17 ,
F_7 ( V_2 -> V_39 ) ) ;
else {
F_25 ( V_2 -> V_39 , V_108 ) ;
F_26 ( V_2 -> V_39 , V_2 -> V_72 . V_91 ) ;
}
return 0 ;
}
static T_1 F_27 ( struct V_119 * V_39 )
{
T_1 V_120 , V_121 ;
V_120 = 1 << V_39 -> V_122 . V_123 ;
switch ( V_120 ) {
case V_124 :
V_121 = V_39 -> V_125 ;
break;
case V_126 :
case V_127 :
V_121 = V_39 -> V_128 ;
break;
case V_129 :
case V_130 :
V_121 = V_39 -> V_131 ;
break;
default:
V_121 = 0 ;
}
return V_121 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 * V_65 )
{
int V_132 = V_133 ;
int V_55 ;
T_1 V_121 ;
if ( ( V_2 -> V_92 != V_101 ) &&
( V_2 -> V_92 != V_95 ) &&
( V_2 -> V_92 != V_98 ) )
return 0 ;
V_121 = F_27 ( V_2 -> V_39 ) ;
if ( V_121 >= 800 )
V_132 = V_134 ;
else if ( V_121 >= 600 )
V_132 = V_135 ;
else if ( V_121 >= 400 )
V_132 = V_136 ;
else if ( V_121 >= 200 )
V_132 = V_137 ;
if ( V_132 != V_133 ) {
V_55 = F_16 ( V_2 , 1 , 3 , V_132 , V_65 ) ;
if ( V_55 )
return V_55 ;
if ( ( ( V_65 [ 15 ] >> 4 ) & 0x0F ) != V_132 )
F_10 ( L_18 ,
F_7 ( V_2 -> V_39 ) ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_55 ;
T_2 * V_65 ;
if ( ! V_2 -> V_42 . V_48 )
return 0 ;
if ( ! ( V_2 -> V_16 . V_28 & V_67 ) )
return 0 ;
V_65 = F_11 ( 64 , V_60 ) ;
if ( ! V_65 ) {
F_6 ( L_11
L_12 , F_7 ( V_2 -> V_39 ) ) ;
return - V_61 ;
}
if ( ( V_2 -> V_39 -> V_77 & V_138 ) &&
( V_2 -> V_42 . V_46 & V_139 ) ) {
V_55 = F_30 ( V_2 , V_140 ) ;
if ( V_55 )
goto V_62;
F_31 ( V_2 -> V_39 , V_140 ) ;
}
F_22 ( V_2 ) ;
V_55 = F_18 ( V_2 , V_65 ) ;
if ( V_55 )
goto V_62;
V_55 = F_28 ( V_2 , V_65 ) ;
if ( V_55 )
goto V_62;
V_55 = F_24 ( V_2 , V_65 ) ;
if ( V_55 )
goto V_62;
if ( ! F_32 ( V_2 -> V_39 ) && V_2 -> V_39 -> V_86 -> V_141 &&
( V_2 -> V_92 == V_101 ||
V_2 -> V_92 == V_95 ) ) {
F_19 ( V_2 -> V_39 ) ;
V_55 = V_2 -> V_39 -> V_86 -> V_141 ( V_2 -> V_39 ,
V_142 ) ;
F_20 ( V_2 -> V_39 ) ;
}
V_62:
F_14 ( V_65 ) ;
return V_55 ;
}
int F_33 ( struct V_119 * V_39 , T_1 V_143 , T_1 * V_5 , T_1 * V_144 )
{
int V_55 ;
T_1 V_121 ;
int V_145 = 10 ;
V_146:
if ( ! V_145 ) {
V_143 &= ~ V_147 ;
F_10 ( L_19 ,
F_7 ( V_39 ) ) ;
}
F_34 ( V_39 ) ;
V_55 = F_35 ( V_39 , V_143 ) ;
if ( ! V_55 )
V_143 |= V_148 ;
if ( V_145 && F_23 ( V_39 ) )
V_143 |= V_147 ;
V_121 = F_27 ( V_39 ) ;
if ( V_121 > 150 )
V_143 |= V_149 ;
V_55 = F_36 ( V_39 , V_143 , V_144 ) ;
if ( V_55 )
return V_55 ;
if ( ! F_32 ( V_39 ) && V_144 &&
( ( * V_144 & 0x41000000 ) == 0x41000000 ) ) {
V_55 = F_37 ( V_39 , V_150 ) ;
if ( V_55 == - V_151 ) {
V_145 -- ;
goto V_146;
} else if ( V_55 ) {
V_145 = 0 ;
goto V_146;
}
}
if ( F_32 ( V_39 ) )
V_55 = F_38 ( V_39 , V_5 ) ;
else
V_55 = F_39 ( V_39 , V_5 ) ;
return V_55 ;
}
int F_40 ( struct V_119 * V_39 , struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_41 ( V_2 , V_2 -> V_20 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_3 ( V_2 ) ;
if ( V_55 )
return V_55 ;
return 0 ;
}
int F_42 ( struct V_119 * V_39 , struct V_1 * V_2 ,
bool V_152 )
{
int V_55 ;
if ( ! V_152 ) {
V_55 = F_43 ( V_2 , V_2 -> V_44 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_8 ( V_2 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_9 ( V_2 ) ;
if ( V_55 )
return V_55 ;
F_44 ( V_2 ) ;
V_55 = F_15 ( V_2 ) ;
if ( V_55 )
return V_55 ;
}
if ( F_32 ( V_39 ) ) {
V_55 = F_45 ( V_39 , V_153 ) ;
if ( V_55 )
return V_55 ;
}
if ( ! V_152 ) {
int V_154 = - 1 ;
if ( V_39 -> V_86 -> V_155 ) {
F_19 ( V_2 -> V_39 ) ;
V_154 = V_39 -> V_86 -> V_155 ( V_39 ) ;
F_20 ( V_2 -> V_39 ) ;
}
if ( V_154 < 0 ) {
F_10 ( L_20
L_21
L_22 ,
F_7 ( V_39 ) ) ;
} else if ( V_154 > 0 ) {
F_46 ( V_2 ) ;
}
}
return 0 ;
}
unsigned F_47 ( struct V_1 * V_2 )
{
unsigned V_25 = ( unsigned int ) - 1 ;
if ( F_48 ( V_2 ) ) {
if ( V_25 > V_2 -> V_72 . V_73 )
V_25 = V_2 -> V_72 . V_73 ;
} else if ( V_25 > V_2 -> V_16 . V_25 ) {
V_25 = V_2 -> V_16 . V_25 ;
}
return V_25 ;
}
void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
F_25 ( V_2 -> V_39 , V_156 ) ;
}
static int F_51 ( struct V_119 * V_39 , T_1 V_143 ,
struct V_1 * V_157 )
{
struct V_1 * V_2 ;
int V_55 ;
T_1 V_5 [ 4 ] ;
T_1 V_144 = 0 ;
F_52 ( ! V_39 ) ;
F_53 ( ! V_39 -> V_158 ) ;
V_55 = F_33 ( V_39 , V_143 , V_5 , & V_144 ) ;
if ( V_55 )
return V_55 ;
if ( V_157 ) {
if ( memcmp ( V_5 , V_157 -> V_4 , sizeof( V_5 ) ) != 0 )
return - V_159 ;
V_2 = V_157 ;
} else {
V_2 = F_54 ( V_39 , & V_160 ) ;
if ( F_55 ( V_2 ) )
return F_56 ( V_2 ) ;
V_2 -> type = V_161 ;
memcpy ( V_2 -> V_4 , V_5 , sizeof( V_2 -> V_4 ) ) ;
}
if ( ! F_32 ( V_39 ) ) {
V_55 = F_57 ( V_39 , & V_2 -> V_162 ) ;
if ( V_55 )
goto V_163;
}
if ( ! V_157 ) {
V_55 = F_40 ( V_39 , V_2 ) ;
if ( V_55 )
goto V_163;
F_1 ( V_2 ) ;
}
if ( ! F_32 ( V_39 ) ) {
V_55 = F_58 ( V_2 ) ;
if ( V_55 )
goto V_163;
}
V_55 = F_42 ( V_39 , V_2 , V_157 != NULL ) ;
if ( V_55 )
goto V_163;
if ( V_144 & V_164 ) {
V_55 = F_29 ( V_2 ) ;
if ( V_55 )
goto V_163;
F_59 ( V_2 ) ;
} else {
V_55 = F_17 ( V_2 ) ;
if ( V_55 > 0 )
F_49 ( V_2 ) ;
else if ( V_55 )
goto V_163;
F_26 ( V_39 , F_47 ( V_2 ) ) ;
if ( ( V_39 -> V_77 & V_138 ) &&
( V_2 -> V_42 . V_46 & V_139 ) ) {
V_55 = F_30 ( V_2 , V_140 ) ;
if ( V_55 )
goto V_163;
F_31 ( V_39 , V_140 ) ;
}
}
V_39 -> V_2 = V_2 ;
return 0 ;
V_163:
if ( ! V_157 )
F_60 ( V_2 ) ;
return V_55 ;
}
static void F_61 ( struct V_119 * V_39 )
{
F_52 ( ! V_39 ) ;
F_52 ( ! V_39 -> V_2 ) ;
F_60 ( V_39 -> V_2 ) ;
V_39 -> V_2 = NULL ;
}
static int F_62 ( struct V_119 * V_39 )
{
return F_63 ( V_39 -> V_2 , NULL ) ;
}
static void F_64 ( struct V_119 * V_39 )
{
int V_55 ;
F_52 ( ! V_39 ) ;
F_52 ( ! V_39 -> V_2 ) ;
F_65 ( V_39 -> V_2 ) ;
V_55 = F_66 ( V_39 ) ;
F_67 ( V_39 -> V_2 ) ;
if ( V_55 ) {
F_61 ( V_39 ) ;
F_68 ( V_39 ) ;
F_69 ( V_39 ) ;
F_70 ( V_39 ) ;
F_71 ( V_39 ) ;
}
}
static int F_72 ( struct V_119 * V_39 )
{
int V_55 = 0 ;
F_52 ( ! V_39 ) ;
F_52 ( ! V_39 -> V_2 ) ;
F_68 ( V_39 ) ;
if ( ! F_32 ( V_39 ) )
V_55 = F_73 ( V_39 ) ;
V_39 -> V_2 -> V_165 &= ~ V_166 ;
if ( ! V_55 )
F_70 ( V_39 ) ;
F_71 ( V_39 ) ;
return V_55 ;
}
static int F_74 ( struct V_119 * V_39 )
{
int V_55 ;
F_52 ( ! V_39 ) ;
F_52 ( ! V_39 -> V_2 ) ;
F_68 ( V_39 ) ;
F_75 ( V_39 ) ;
F_76 ( V_39 , V_39 -> V_143 ) ;
V_55 = F_51 ( V_39 , V_39 -> V_143 , V_39 -> V_2 ) ;
F_71 ( V_39 ) ;
return V_55 ;
}
static int F_77 ( struct V_119 * V_39 )
{
int V_55 ;
if ( ! ( V_39 -> V_77 & V_167 ) )
return 0 ;
F_68 ( V_39 ) ;
V_55 = F_72 ( V_39 ) ;
if ( V_55 ) {
F_6 ( L_23 ,
F_7 ( V_39 ) , V_55 ) ;
goto V_62;
}
F_70 ( V_39 ) ;
V_62:
F_71 ( V_39 ) ;
return V_55 ;
}
static int F_78 ( struct V_119 * V_39 )
{
int V_55 ;
if ( ! ( V_39 -> V_77 & V_167 ) )
return 0 ;
F_68 ( V_39 ) ;
F_75 ( V_39 ) ;
V_55 = F_74 ( V_39 ) ;
if ( V_55 )
F_6 ( L_24 ,
F_7 ( V_39 ) , V_55 ) ;
F_71 ( V_39 ) ;
return 0 ;
}
static int F_79 ( struct V_119 * V_39 )
{
int V_168 ;
V_39 -> V_2 -> V_165 &= ~ V_166 ;
F_68 ( V_39 ) ;
V_168 = F_51 ( V_39 , V_39 -> V_143 , V_39 -> V_2 ) ;
F_71 ( V_39 ) ;
return V_168 ;
}
static void F_80 ( struct V_119 * V_39 )
{
const struct V_169 * V_170 ;
if ( ! F_81 ( V_39 ) )
V_170 = & V_171 ;
else
V_170 = & V_172 ;
F_82 ( V_39 , V_170 ) ;
}
int F_83 ( struct V_119 * V_39 )
{
int V_55 ;
T_1 V_143 ;
F_52 ( ! V_39 ) ;
F_53 ( ! V_39 -> V_158 ) ;
V_55 = F_36 ( V_39 , 0 , & V_143 ) ;
if ( V_55 )
return V_55 ;
F_80 ( V_39 ) ;
if ( V_39 -> V_173 )
V_39 -> V_174 = V_39 -> V_173 ;
if ( F_32 ( V_39 ) ) {
F_34 ( V_39 ) ;
V_55 = F_84 ( V_39 , 0 , & V_143 ) ;
if ( V_55 )
goto V_55;
}
if ( V_143 & 0x7F ) {
F_10 ( L_25
L_26 ,
F_7 ( V_39 ) ) ;
V_143 &= ~ 0x7F ;
}
if ( ( V_143 & V_124 ) &&
! ( V_39 -> V_173 & V_124 ) ) {
F_10 ( L_27
L_28
L_29 , F_7 ( V_39 ) ) ;
V_143 &= ~ V_124 ;
}
V_39 -> V_143 = F_76 ( V_39 , V_143 ) ;
if ( ! V_39 -> V_143 ) {
V_55 = - V_40 ;
goto V_55;
}
V_55 = F_51 ( V_39 , V_39 -> V_143 , NULL ) ;
if ( V_55 )
goto V_55;
F_71 ( V_39 ) ;
V_55 = F_85 ( V_39 -> V_2 ) ;
F_68 ( V_39 ) ;
if ( V_55 )
goto V_175;
return 0 ;
V_175:
F_71 ( V_39 ) ;
F_60 ( V_39 -> V_2 ) ;
V_39 -> V_2 = NULL ;
F_68 ( V_39 ) ;
V_55:
F_69 ( V_39 ) ;
F_6 ( L_30 ,
F_7 ( V_39 ) , V_55 ) ;
return V_55 ;
}
