static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , L_1 ) ;
if ( V_5 >= 0 ) {
V_5 = F_2 ( V_2 -> V_6 , L_2 ) ;
if ( V_5 >= 0 )
return 0 ;
}
return - V_7 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
T_1 V_14 ;
unsigned int V_15 ;
V_9 = V_2 -> V_16 -> V_17 ;
for ( V_15 = 0 ; V_15 < V_9 -> V_18 . V_19 ; V_15 ++ ) {
V_11 = & V_9 -> V_11 [ V_15 ] . V_18 ;
if ( F_5 ( V_11 ) )
++ V_12 ;
if ( F_6 ( V_11 ) )
++ V_13 ;
}
V_14 = V_20 + 1 ;
if ( V_12 < V_14 || V_13 < V_14 )
return - V_21 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
T_2 * V_31 ;
T_2 * V_32 ;
V_23 = V_2 -> V_33 [ V_20 ] ;
V_28 = F_8 ( V_2 -> V_6 ,
V_23 -> V_34 ) ;
V_31 = F_9 ( 2 , V_35 ) ;
if ( ! V_31 )
goto V_36;
V_31 [ 0 ] = V_37 ;
V_31 [ 1 ] = 0 ;
V_32 = F_9 ( sizeof( * V_27 ) + 1 , V_35 ) ;
if ( ! V_32 )
goto V_38;
F_10 ( V_2 -> V_6 , V_28 ) ;
V_29 = F_11 ( V_2 -> V_6 , V_28 , V_31 , 2 ,
& V_30 , V_39 ) ;
if ( V_29 ) {
F_12 ( & V_2 -> V_6 -> V_6 , L_3 ,
V_2 -> type -> V_40 , V_29 ) ;
goto V_41;
} else if ( V_30 != 2 ) {
F_12 ( & V_2 -> V_6 -> V_6 , L_4 ,
V_2 -> type -> V_40 , V_30 ) ;
goto V_41;
}
V_28 = F_13 ( V_2 -> V_6 ,
V_23 -> V_42 ) ;
F_10 ( V_2 -> V_6 , V_28 ) ;
V_29 = F_11 ( V_2 -> V_6 , V_28 , V_32 ,
sizeof( * V_27 ) + 1 , & V_30 , V_39 ) ;
if ( V_29 ) {
F_12 ( & V_2 -> V_6 -> V_6 , L_5 ,
V_2 -> type -> V_40 , V_29 ) ;
goto V_41;
} else if ( V_30 != sizeof( * V_27 ) + 1 ) {
F_12 ( & V_2 -> V_6 -> V_6 , L_6 ,
V_2 -> type -> V_40 , V_30 ) ;
goto V_41;
} else if ( V_32 [ 0 ] != V_31 [ 0 ] ) {
F_12 ( & V_2 -> V_6 -> V_6 , L_7 ,
V_2 -> type -> V_40 , V_32 [ 0 ] ) ;
goto V_41;
}
V_27 = (struct V_26 * ) & V_32 [ 1 ] ;
F_14 ( & V_2 -> V_6 -> V_6 , L_8 ,
V_2 -> type -> V_40 ,
V_27 -> V_43 , V_27 -> V_44 ) ;
V_25 = F_9 ( sizeof( struct V_24 ) ,
V_35 ) ;
if ( ! V_25 )
goto V_45;
F_15 ( & V_25 -> V_46 ) ;
V_25 -> V_47 = 0 ;
F_16 ( & V_25 -> V_48 ) ;
F_17 ( V_23 , V_25 ) ;
V_23 -> V_49 -> V_50 = V_51 ;
V_23 -> V_52 -> V_50 = V_53 ;
F_18 ( V_32 ) ;
F_18 ( V_31 ) ;
return 0 ;
V_41:
F_12 ( & V_2 -> V_6 -> V_6 ,
L_9 ,
V_2 -> type -> V_40 ) ;
F_12 ( & V_2 -> V_6 -> V_6 ,
L_10 ,
V_2 -> type -> V_40 ) ;
F_12 ( & V_2 -> V_6 -> V_6 ,
L_11 ,
V_2 -> type -> V_40 ) ;
F_18 ( V_32 ) ;
F_18 ( V_31 ) ;
return - V_21 ;
V_45:
F_18 ( V_32 ) ;
V_38:
F_18 ( V_31 ) ;
V_36:
return - V_54 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = V_2 -> V_33 [ V_20 ] ;
F_18 ( F_20 ( V_23 ) ) ;
}
static int F_21 ( struct V_22 * V_33 )
{
struct V_55 * V_56 ;
V_56 = F_22 ( sizeof( * V_56 ) , V_35 ) ;
if ( ! V_56 )
return - V_54 ;
F_17 ( V_33 , V_56 ) ;
return 0 ;
}
static int F_23 ( struct V_22 * V_33 )
{
struct V_55 * V_56 ;
V_56 = F_20 ( V_33 ) ;
F_18 ( V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 , struct V_22 * V_33 )
{
int V_59 ;
V_59 = F_25 ( V_33 -> V_2 ) ;
if ( V_59 )
goto exit;
V_59 = F_26 ( V_33 ) ;
if ( V_59 ) {
F_27 ( V_33 -> V_2 ) ;
goto exit;
}
V_59 = F_28 ( V_33 , V_60 | V_61 ) ;
if ( V_59 ) {
F_29 ( V_33 ) ;
F_27 ( V_33 -> V_2 ) ;
goto exit;
}
if ( V_58 )
F_30 ( V_58 ) ;
F_10 ( V_33 -> V_2 -> V_6 , V_33 -> V_52 -> V_28 ) ;
F_10 ( V_33 -> V_2 -> V_6 , V_33 -> V_49 -> V_28 ) ;
V_59 = F_31 ( V_58 , V_33 ) ;
if ( V_59 ) {
F_29 ( V_33 ) ;
F_27 ( V_33 -> V_2 ) ;
goto exit;
}
exit:
return V_59 ;
}
static void F_32 ( struct V_22 * V_33 )
{
F_33 ( V_33 ) ;
F_29 ( V_33 ) ;
F_34 ( V_33 ) ;
F_27 ( V_33 -> V_2 ) ;
}
static int F_35 ( struct V_57 * V_58 )
{
struct V_22 * V_33 = V_58 -> V_62 ;
struct V_55 * V_56 = F_20 ( V_33 ) ;
unsigned int V_63 = 0 ;
F_36 ( V_33 ) ;
if ( V_56 -> V_64 & V_65 )
V_63 |= V_66 ;
if ( V_56 -> V_64 & V_67 )
V_63 |= V_68 ;
return V_63 ;
}
static int F_37 ( struct V_57 * V_58 ,
unsigned int V_69 , unsigned int V_70 )
{
struct V_22 * V_33 = V_58 -> V_62 ;
struct V_55 * V_56 = F_20 ( V_33 ) ;
if ( V_69 & V_68 )
V_56 -> V_64 |= V_67 ;
if ( V_69 & V_66 )
V_56 -> V_64 |= V_65 ;
if ( V_70 & V_68 )
V_56 -> V_64 &= ~ V_67 ;
if ( V_70 & V_66 )
V_56 -> V_64 &= ~ V_65 ;
F_38 ( V_33 , V_56 -> V_64 & V_65 ) ;
F_39 ( V_33 , V_56 -> V_64 & V_67 ) ;
return 0 ;
}
static int F_40 ( struct V_57 * V_58 ,
unsigned int V_71 , unsigned long V_72 )
{
struct V_22 * V_33 = V_58 -> V_62 ;
struct V_73 V_74 ;
void T_3 * V_75 = ( void T_3 * ) V_72 ;
switch ( V_71 ) {
case V_76 :
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . type = V_77 ;
V_74 . line = V_33 -> V_78 ;
V_74 . V_33 = V_33 -> V_79 ;
V_74 . V_80 = F_41 ( & V_33 -> V_81 ) ;
V_74 . V_82 = 0 ;
V_74 . V_83 = 460800 ;
V_74 . V_84 = V_85 ;
V_74 . V_86 = V_85 ;
if ( F_42 ( V_75 , & V_74 , sizeof( V_74 ) ) )
return - V_87 ;
break;
default:
break;
}
return - V_88 ;
}
static void F_43 ( struct V_57 * V_58 ,
struct V_22 * V_33 , struct V_89 * V_90 )
{
F_30 ( V_58 ) ;
}
static void F_44 ( struct V_57 * V_58 , int V_91 )
{
struct V_22 * V_33 = V_58 -> V_62 ;
F_45 ( V_33 , V_91 ) ;
}
static void V_51 ( struct V_92 * V_92 )
{
int V_93 = V_92 -> V_93 ;
if ( V_93 ) {
F_46 ( & V_92 -> V_6 -> V_6 , L_12 , V_93 ) ;
return;
}
}
static void V_53 ( struct V_92 * V_92 )
{
struct V_22 * V_23 = V_92 -> V_94 ;
struct V_24 * V_25 ;
int V_93 = V_92 -> V_93 ;
unsigned char * V_95 = V_92 -> V_96 ;
int V_32 ;
V_25 = F_20 ( V_23 ) ;
if ( ! V_25 ) {
F_46 ( & V_92 -> V_6 -> V_6 , L_13 , V_97 ) ;
return;
}
if ( ! V_92 -> V_98 ) {
F_46 ( & V_92 -> V_6 -> V_6 , L_14 , V_97 ) ;
return;
}
if ( V_93 ) {
F_46 ( & V_92 -> V_6 -> V_6 , L_15 , V_97 , V_93 ) ;
if ( V_93 != - V_7 )
V_25 -> V_99 = V_100 ;
F_47 ( & V_25 -> V_48 ) ;
return;
}
F_48 ( & V_23 -> V_6 , V_97 , V_92 -> V_98 , V_95 ) ;
if ( V_95 [ 0 ] == V_101 ) {
V_25 -> V_99 = V_101 ;
F_47 ( & V_25 -> V_48 ) ;
} else if ( V_95 [ 0 ] == V_100 ) {
V_25 -> V_99 = V_100 ;
F_47 ( & V_25 -> V_48 ) ;
} else if ( V_95 [ 0 ] == V_102 ) {
F_46 ( & V_92 -> V_6 -> V_6 , L_16 , V_97 ) ;
} else if ( ( V_95 [ 0 ] == V_103 ) &&
( V_92 -> V_98 - 1 <= sizeof( V_25 -> V_104 ) ) ) {
memcpy ( V_25 -> V_104 , & V_95 [ 1 ] ,
V_92 -> V_98 - 1 ) ;
V_25 -> V_99 = V_101 ;
F_47 ( & V_25 -> V_48 ) ;
} else
F_46 ( & V_92 -> V_6 -> V_6 , L_17 , V_97 ) ;
V_32 = F_49 ( V_23 -> V_52 , V_105 ) ;
if ( V_32 )
F_46 ( & V_92 -> V_6 -> V_6 , L_18 ,
V_97 , V_32 ) ;
}
static int F_50 ( struct V_22 * V_33 , T_2 V_31 ,
T_2 * V_95 , T_2 V_106 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_55 * V_56 ;
struct V_107 * V_6 = & V_33 -> V_6 ;
T_2 * V_96 ;
int V_59 = 0 ;
int V_108 ;
F_46 ( V_6 , L_19 , V_97 , V_31 ) ;
V_23 = V_33 -> V_2 -> V_33 [ V_20 ] ;
V_25 = F_20 ( V_23 ) ;
F_51 ( & V_25 -> V_46 ) ;
V_25 -> V_99 = false ;
V_96 = ( T_2 * ) V_23 -> V_49 -> V_96 ;
V_96 [ 0 ] = V_31 ;
memcpy ( & V_96 [ 1 ] , V_95 , V_106 ) ;
V_23 -> V_49 -> V_109 = V_106 + 1 ;
V_59 = F_49 ( V_23 -> V_49 , V_110 ) ;
if ( V_59 ) {
F_46 ( V_6 , L_20 , V_97 ) ;
goto exit;
}
V_108 = F_52 ( V_25 -> V_48 ,
( bool ) V_25 -> V_99 , V_111 ) ;
if ( ! V_108 )
F_53 ( V_23 -> V_49 ) ;
if ( V_25 -> V_99 == false ) {
F_46 ( V_6 , L_21 , V_97 ) ;
V_59 = - V_112 ;
goto exit;
}
if ( V_25 -> V_99 == V_100 ) {
F_46 ( V_6 , L_22 , V_97 ) ;
V_59 = - V_113 ;
goto exit;
}
if ( V_25 -> V_99 == V_101 ) {
F_46 ( V_6 , L_23 , V_97 ) ;
switch ( V_31 ) {
case V_103 :
V_56 = F_20 ( V_33 ) ;
memcpy ( & V_56 -> V_64 , V_25 -> V_104 ,
sizeof( struct V_114 ) ) ;
break;
}
}
exit:
F_54 ( & V_25 -> V_46 ) ;
return V_59 ;
}
static int F_26 ( struct V_22 * V_33 )
{
struct V_115 V_116 ;
V_116 . V_33 = V_33 -> V_79 + 1 ;
return F_50 ( V_33 , V_117 ,
( T_2 * ) & V_116 , sizeof( V_116 ) ) ;
}
static int F_29 ( struct V_22 * V_33 )
{
struct V_115 V_118 ;
V_118 . V_33 = V_33 -> V_79 + 1 ;
return F_50 ( V_33 , V_119 ,
( T_2 * ) & V_118 , sizeof( V_118 ) ) ;
}
static void F_30 ( struct V_57 * V_58 )
{
struct V_22 * V_33 = V_58 -> V_62 ;
struct V_107 * V_6 = & V_33 -> V_6 ;
struct V_120 V_121 ;
unsigned int V_122 = V_58 -> V_123 . V_124 ;
V_121 . V_33 = V_33 -> V_79 + 1 ;
switch ( V_122 & V_125 ) {
case V_126 : V_121 . V_127 = 5 ; break;
case V_128 : V_121 . V_127 = 6 ; break;
case V_129 : V_121 . V_127 = 7 ; break;
default:
case V_130 : V_121 . V_127 = 8 ; break;
}
F_46 ( V_6 , L_24 , V_97 , V_121 . V_127 ) ;
if ( V_122 & V_131 )
if ( V_122 & V_132 )
if ( V_122 & V_133 )
V_121 . V_134 = V_135 ;
else
V_121 . V_134 = V_136 ;
else
if ( V_122 & V_133 )
V_121 . V_134 = V_137 ;
else
V_121 . V_134 = V_138 ;
else
V_121 . V_134 = V_139 ;
F_46 ( V_6 , L_25 , V_97 , V_121 . V_134 ) ;
if ( V_122 & V_140 )
V_121 . V_141 = 2 ;
else
V_121 . V_141 = 1 ;
F_46 ( V_6 , L_26 , V_97 , V_121 . V_141 ) ;
if ( V_122 & V_142 )
V_121 . V_143 = ( V_144 |
V_145 ) ;
else
V_121 . V_143 = V_146 ;
F_46 ( V_6 , L_27 , V_97 ,
( V_121 . V_143 & V_144 ) ? L_28 : L_29 ,
( V_121 . V_143 & V_145 ) ? L_30 : L_29 ,
( V_121 . V_143 & V_147 ) ? L_31 : L_29 ,
( V_121 . V_143 & V_148 ) ? L_32 : L_29 ) ;
if ( F_55 ( V_58 ) )
V_121 . V_149 = V_150 ;
else
V_121 . V_149 = V_151 ;
F_46 ( V_6 , L_33 , V_97 , V_121 . V_149 ) ;
V_121 . V_152 = F_56 ( V_58 ) ;
V_121 . V_153 = F_57 ( V_58 ) ;
F_46 ( V_6 , L_34 , V_97 , V_121 . V_152 , V_121 . V_153 ) ;
V_121 . V_154 = F_58 ( V_58 ) ;
F_46 ( V_6 , L_35 , V_97 , V_121 . V_154 ) ;
F_59 ( V_58 , V_121 . V_154 , V_121 . V_154 ) ;
V_121 . V_155 = 0 ;
F_50 ( V_33 , V_156 ,
( T_2 * ) & V_121 , sizeof( V_121 ) ) ;
}
static int F_39 ( struct V_22 * V_33 , T_2 V_157 )
{
struct V_158 V_159 ;
V_159 . V_33 = V_33 -> V_79 + 1 ;
V_159 . V_160 = V_157 ;
return F_50 ( V_33 , V_161 ,
( T_2 * ) & V_159 , sizeof( V_159 ) ) ;
}
static int F_38 ( struct V_22 * V_33 , T_2 V_157 )
{
struct V_158 V_162 ;
V_162 . V_33 = V_33 -> V_79 + 1 ;
V_162 . V_160 = V_157 ;
return F_50 ( V_33 , V_163 ,
( T_2 * ) & V_162 , sizeof( V_162 ) ) ;
}
static int F_45 ( struct V_22 * V_33 , T_2 V_157 )
{
struct V_158 V_164 ;
V_164 . V_33 = V_33 -> V_79 + 1 ;
V_164 . V_160 = V_157 ;
return F_50 ( V_33 , V_165 ,
( T_2 * ) & V_164 , sizeof( V_164 ) ) ;
}
static int F_28 ( struct V_22 * V_33 , T_2 V_166 )
{
struct V_167 V_168 ;
V_168 . V_33 = V_33 -> V_79 + 1 ;
V_168 . V_169 = V_166 ;
return F_50 ( V_33 , V_170 ,
( T_2 * ) & V_168 , sizeof( V_168 ) ) ;
}
static int F_36 ( struct V_22 * V_33 )
{
struct V_115 V_171 ;
V_171 . V_33 = V_33 -> V_79 + 1 ;
return F_50 ( V_33 , V_103 ,
( T_2 * ) & V_171 , sizeof( V_171 ) ) ;
}
static int F_33 ( struct V_22 * V_33 )
{
struct V_115 V_118 ;
V_118 . V_33 = V_33 -> V_79 + 1 ;
return F_50 ( V_33 , V_172 ,
( T_2 * ) & V_118 , sizeof( V_118 ) ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_59 = 0 ;
V_23 = V_2 -> V_33 [ V_20 ] ;
V_25 = F_20 ( V_23 ) ;
F_51 ( & V_25 -> V_46 ) ;
if ( ! V_25 -> V_47 ) {
F_10 ( V_2 -> V_6 , V_23 -> V_52 -> V_28 ) ;
V_59 = F_49 ( V_23 -> V_52 , V_35 ) ;
if ( V_59 ) {
F_12 ( & V_2 -> V_6 -> V_6 ,
L_36 ,
V_97 , V_59 ) ;
goto exit;
}
}
V_25 -> V_47 ++ ;
exit:
F_54 ( & V_25 -> V_46 ) ;
return V_59 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = V_2 -> V_33 [ V_20 ] ;
V_25 = F_20 ( V_23 ) ;
F_51 ( & V_25 -> V_46 ) ;
V_25 -> V_47 -- ;
if ( ! V_25 -> V_47 )
F_53 ( V_23 -> V_52 ) ;
F_54 ( & V_25 -> V_46 ) ;
}
