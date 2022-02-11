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
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
T_1 * V_17 ;
T_1 * V_18 ;
V_9 = V_2 -> V_19 [ V_20 ] ;
V_14 = F_5 ( V_2 -> V_6 ,
V_9 -> V_21 ) ;
V_17 = F_6 ( 2 , V_22 ) ;
if ( ! V_17 )
goto V_23;
V_17 [ 0 ] = V_24 ;
V_17 [ 1 ] = 0 ;
V_18 = F_6 ( sizeof( * V_13 ) + 1 , V_22 ) ;
if ( ! V_18 )
goto V_25;
F_7 ( V_2 -> V_6 , V_14 ) ;
V_15 = F_8 ( V_2 -> V_6 , V_14 , V_17 , 2 ,
& V_16 , V_26 ) ;
if ( V_15 ) {
F_9 ( & V_2 -> V_6 -> V_6 , L_3 ,
V_2 -> type -> V_27 , V_15 ) ;
goto V_28;
} else if ( V_16 != 2 ) {
F_9 ( & V_2 -> V_6 -> V_6 , L_4 ,
V_2 -> type -> V_27 , V_16 ) ;
goto V_28;
}
V_14 = F_10 ( V_2 -> V_6 ,
V_9 -> V_29 ) ;
F_7 ( V_2 -> V_6 , V_14 ) ;
V_15 = F_8 ( V_2 -> V_6 , V_14 , V_18 ,
sizeof( * V_13 ) + 1 , & V_16 , V_26 ) ;
if ( V_15 ) {
F_9 ( & V_2 -> V_6 -> V_6 , L_5 ,
V_2 -> type -> V_27 , V_15 ) ;
goto V_28;
} else if ( V_16 != sizeof( * V_13 ) + 1 ) {
F_9 ( & V_2 -> V_6 -> V_6 , L_6 ,
V_2 -> type -> V_27 , V_16 ) ;
goto V_28;
} else if ( V_18 [ 0 ] != V_17 [ 0 ] ) {
F_9 ( & V_2 -> V_6 -> V_6 , L_7 ,
V_2 -> type -> V_27 , V_18 [ 0 ] ) ;
goto V_28;
}
V_13 = (struct V_12 * ) & V_18 [ 1 ] ;
F_11 ( & V_2 -> V_6 -> V_6 , L_8 ,
V_2 -> type -> V_27 ,
V_13 -> V_30 , V_13 -> V_31 ) ;
V_11 = F_6 ( sizeof( struct V_10 ) ,
V_22 ) ;
if ( ! V_11 )
goto V_32;
F_12 ( & V_11 -> V_33 ) ;
V_11 -> V_34 = 0 ;
F_13 ( & V_11 -> V_35 ) ;
F_14 ( V_9 , V_11 ) ;
V_9 -> V_36 -> V_37 = V_38 ;
V_9 -> V_39 -> V_37 = V_40 ;
F_15 ( V_18 ) ;
F_15 ( V_17 ) ;
return 0 ;
V_28:
F_9 ( & V_2 -> V_6 -> V_6 ,
L_9 ,
V_2 -> type -> V_27 ) ;
F_9 ( & V_2 -> V_6 -> V_6 ,
L_10 ,
V_2 -> type -> V_27 ) ;
F_9 ( & V_2 -> V_6 -> V_6 ,
L_11 ,
V_2 -> type -> V_27 ) ;
F_15 ( V_18 ) ;
F_15 ( V_17 ) ;
return - V_41 ;
V_32:
F_15 ( V_18 ) ;
V_25:
F_15 ( V_17 ) ;
V_23:
return - V_42 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_19 [ V_20 ] ;
F_15 ( F_17 ( V_9 ) ) ;
}
static int F_18 ( struct V_8 * V_19 )
{
struct V_43 * V_44 ;
V_44 = F_19 ( sizeof( * V_44 ) , V_22 ) ;
if ( ! V_44 )
return - V_42 ;
F_14 ( V_19 , V_44 ) ;
return 0 ;
}
static int F_20 ( struct V_8 * V_19 )
{
struct V_43 * V_44 ;
V_44 = F_17 ( V_19 ) ;
F_15 ( V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_45 * V_46 , struct V_8 * V_19 )
{
int V_47 ;
V_47 = F_22 ( V_19 -> V_2 ) ;
if ( V_47 )
goto exit;
V_47 = F_23 ( V_19 ) ;
if ( V_47 ) {
F_24 ( V_19 -> V_2 ) ;
goto exit;
}
V_47 = F_25 ( V_19 , V_48 | V_49 ) ;
if ( V_47 ) {
F_26 ( V_19 ) ;
F_24 ( V_19 -> V_2 ) ;
goto exit;
}
if ( V_46 )
F_27 ( V_46 ) ;
F_7 ( V_19 -> V_2 -> V_6 , V_19 -> V_39 -> V_14 ) ;
F_7 ( V_19 -> V_2 -> V_6 , V_19 -> V_36 -> V_14 ) ;
V_47 = F_28 ( V_46 , V_19 ) ;
if ( V_47 ) {
F_26 ( V_19 ) ;
F_24 ( V_19 -> V_2 ) ;
goto exit;
}
exit:
return V_47 ;
}
static void F_29 ( struct V_8 * V_19 )
{
F_30 ( V_19 ) ;
F_26 ( V_19 ) ;
F_31 ( V_19 ) ;
F_24 ( V_19 -> V_2 ) ;
}
static int F_32 ( struct V_45 * V_46 )
{
struct V_8 * V_19 = V_46 -> V_50 ;
struct V_43 * V_44 = F_17 ( V_19 ) ;
unsigned int V_51 = 0 ;
F_33 ( V_19 ) ;
if ( V_44 -> V_52 & V_53 )
V_51 |= V_54 ;
if ( V_44 -> V_52 & V_55 )
V_51 |= V_56 ;
return V_51 ;
}
static int F_34 ( struct V_45 * V_46 ,
unsigned int V_57 , unsigned int V_58 )
{
struct V_8 * V_19 = V_46 -> V_50 ;
struct V_43 * V_44 = F_17 ( V_19 ) ;
if ( V_57 & V_56 )
V_44 -> V_52 |= V_55 ;
if ( V_57 & V_54 )
V_44 -> V_52 |= V_53 ;
if ( V_58 & V_56 )
V_44 -> V_52 &= ~ V_55 ;
if ( V_58 & V_54 )
V_44 -> V_52 &= ~ V_53 ;
F_35 ( V_19 , V_44 -> V_52 & V_53 ) ;
F_36 ( V_19 , V_44 -> V_52 & V_55 ) ;
return 0 ;
}
static int F_37 ( struct V_45 * V_46 ,
unsigned int V_59 , unsigned long V_60 )
{
struct V_8 * V_19 = V_46 -> V_50 ;
struct V_61 V_62 ;
void T_2 * V_63 = ( void T_2 * ) V_60 ;
switch ( V_59 ) {
case V_64 :
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . type = V_65 ;
V_62 . line = V_19 -> V_66 ;
V_62 . V_19 = V_19 -> V_67 ;
V_62 . V_68 = F_38 ( & V_19 -> V_69 ) ;
V_62 . V_70 = 0 ;
V_62 . V_71 = 460800 ;
V_62 . V_72 = V_73 ;
V_62 . V_74 = V_73 ;
if ( F_39 ( V_63 , & V_62 , sizeof( V_62 ) ) )
return - V_75 ;
break;
default:
break;
}
return - V_76 ;
}
static void F_40 ( struct V_45 * V_46 ,
struct V_8 * V_19 , struct V_77 * V_78 )
{
F_27 ( V_46 ) ;
}
static void F_41 ( struct V_45 * V_46 , int V_79 )
{
struct V_8 * V_19 = V_46 -> V_50 ;
F_42 ( V_19 , V_79 ) ;
}
static void V_38 ( struct V_80 * V_80 )
{
int V_81 = V_80 -> V_81 ;
if ( V_81 ) {
F_43 ( & V_80 -> V_6 -> V_6 , L_12 , V_81 ) ;
return;
}
}
static void V_40 ( struct V_80 * V_80 )
{
struct V_8 * V_9 = V_80 -> V_82 ;
struct V_10 * V_11 ;
int V_81 = V_80 -> V_81 ;
unsigned char * V_83 = V_80 -> V_84 ;
int V_18 ;
V_11 = F_17 ( V_9 ) ;
if ( ! V_11 ) {
F_43 ( & V_80 -> V_6 -> V_6 , L_13 , V_85 ) ;
return;
}
if ( ! V_80 -> V_86 ) {
F_43 ( & V_80 -> V_6 -> V_6 , L_14 , V_85 ) ;
return;
}
if ( V_81 ) {
F_43 ( & V_80 -> V_6 -> V_6 , L_15 , V_85 , V_81 ) ;
if ( V_81 != - V_7 )
V_11 -> V_87 = V_88 ;
F_44 ( & V_11 -> V_35 ) ;
return;
}
F_45 ( & V_9 -> V_6 , V_85 , V_80 -> V_86 , V_83 ) ;
if ( V_83 [ 0 ] == V_89 ) {
V_11 -> V_87 = V_89 ;
F_44 ( & V_11 -> V_35 ) ;
} else if ( V_83 [ 0 ] == V_88 ) {
V_11 -> V_87 = V_88 ;
F_44 ( & V_11 -> V_35 ) ;
} else if ( V_83 [ 0 ] == V_90 ) {
F_43 ( & V_80 -> V_6 -> V_6 , L_16 , V_85 ) ;
} else if ( ( V_83 [ 0 ] == V_91 ) &&
( V_80 -> V_86 - 1 <= sizeof( V_11 -> V_92 ) ) ) {
memcpy ( V_11 -> V_92 , & V_83 [ 1 ] ,
V_80 -> V_86 - 1 ) ;
V_11 -> V_87 = V_89 ;
F_44 ( & V_11 -> V_35 ) ;
} else
F_43 ( & V_80 -> V_6 -> V_6 , L_17 , V_85 ) ;
V_18 = F_46 ( V_9 -> V_39 , V_93 ) ;
if ( V_18 )
F_43 ( & V_80 -> V_6 -> V_6 , L_18 ,
V_85 , V_18 ) ;
}
static int F_47 ( struct V_8 * V_19 , T_1 V_17 ,
T_1 * V_83 , T_1 V_94 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_43 * V_44 ;
struct V_95 * V_6 = & V_19 -> V_6 ;
T_1 * V_84 ;
int V_47 = 0 ;
int V_96 ;
F_43 ( V_6 , L_19 , V_85 , V_17 ) ;
V_9 = V_19 -> V_2 -> V_19 [ V_20 ] ;
V_11 = F_17 ( V_9 ) ;
F_48 ( & V_11 -> V_33 ) ;
V_11 -> V_87 = false ;
V_84 = ( T_1 * ) V_9 -> V_36 -> V_84 ;
V_84 [ 0 ] = V_17 ;
memcpy ( & V_84 [ 1 ] , V_83 , V_94 ) ;
V_9 -> V_36 -> V_97 = V_94 + 1 ;
V_47 = F_46 ( V_9 -> V_36 , V_98 ) ;
if ( V_47 ) {
F_43 ( V_6 , L_20 , V_85 ) ;
goto exit;
}
V_96 = F_49 ( V_11 -> V_35 ,
( bool ) V_11 -> V_87 , V_99 ) ;
if ( ! V_96 )
F_50 ( V_9 -> V_36 ) ;
if ( V_11 -> V_87 == false ) {
F_43 ( V_6 , L_21 , V_85 ) ;
V_47 = - V_100 ;
goto exit;
}
if ( V_11 -> V_87 == V_88 ) {
F_43 ( V_6 , L_22 , V_85 ) ;
V_47 = - V_101 ;
goto exit;
}
if ( V_11 -> V_87 == V_89 ) {
F_43 ( V_6 , L_23 , V_85 ) ;
switch ( V_17 ) {
case V_91 :
V_44 = F_17 ( V_19 ) ;
memcpy ( & V_44 -> V_52 , V_11 -> V_92 ,
sizeof( struct V_102 ) ) ;
break;
}
}
exit:
F_51 ( & V_11 -> V_33 ) ;
return V_47 ;
}
static int F_23 ( struct V_8 * V_19 )
{
struct V_103 V_104 ;
V_104 . V_19 = V_19 -> V_67 + 1 ;
return F_47 ( V_19 , V_105 ,
( T_1 * ) & V_104 , sizeof( V_104 ) ) ;
}
static int F_26 ( struct V_8 * V_19 )
{
struct V_103 V_106 ;
V_106 . V_19 = V_19 -> V_67 + 1 ;
return F_47 ( V_19 , V_107 ,
( T_1 * ) & V_106 , sizeof( V_106 ) ) ;
}
static void F_27 ( struct V_45 * V_46 )
{
struct V_8 * V_19 = V_46 -> V_50 ;
struct V_95 * V_6 = & V_19 -> V_6 ;
struct V_108 V_109 ;
unsigned int V_110 = V_46 -> V_111 . V_112 ;
V_109 . V_19 = V_19 -> V_67 + 1 ;
switch ( V_110 & V_113 ) {
case V_114 : V_109 . V_115 = 5 ; break;
case V_116 : V_109 . V_115 = 6 ; break;
case V_117 : V_109 . V_115 = 7 ; break;
default:
case V_118 : V_109 . V_115 = 8 ; break;
}
F_43 ( V_6 , L_24 , V_85 , V_109 . V_115 ) ;
if ( V_110 & V_119 )
if ( V_110 & V_120 )
if ( V_110 & V_121 )
V_109 . V_122 = V_123 ;
else
V_109 . V_122 = V_124 ;
else
if ( V_110 & V_121 )
V_109 . V_122 = V_125 ;
else
V_109 . V_122 = V_126 ;
else
V_109 . V_122 = V_127 ;
F_43 ( V_6 , L_25 , V_85 , V_109 . V_122 ) ;
if ( V_110 & V_128 )
V_109 . V_129 = 2 ;
else
V_109 . V_129 = 1 ;
F_43 ( V_6 , L_26 , V_85 , V_109 . V_129 ) ;
if ( V_110 & V_130 )
V_109 . V_131 = ( V_132 |
V_133 ) ;
else
V_109 . V_131 = V_134 ;
F_43 ( V_6 , L_27 , V_85 ,
( V_109 . V_131 & V_132 ) ? L_28 : L_29 ,
( V_109 . V_131 & V_133 ) ? L_30 : L_29 ,
( V_109 . V_131 & V_135 ) ? L_31 : L_29 ,
( V_109 . V_131 & V_136 ) ? L_32 : L_29 ) ;
if ( F_52 ( V_46 ) )
V_109 . V_137 = V_138 ;
else
V_109 . V_137 = V_139 ;
F_43 ( V_6 , L_33 , V_85 , V_109 . V_137 ) ;
V_109 . V_140 = F_53 ( V_46 ) ;
V_109 . V_141 = F_54 ( V_46 ) ;
F_43 ( V_6 , L_34 , V_85 , V_109 . V_140 , V_109 . V_141 ) ;
V_109 . V_142 = F_55 ( V_46 ) ;
F_43 ( V_6 , L_35 , V_85 , V_109 . V_142 ) ;
F_56 ( V_46 , V_109 . V_142 , V_109 . V_142 ) ;
V_109 . V_143 = 0 ;
F_47 ( V_19 , V_144 ,
( T_1 * ) & V_109 , sizeof( V_109 ) ) ;
}
static int F_36 ( struct V_8 * V_19 , T_1 V_145 )
{
struct V_146 V_147 ;
V_147 . V_19 = V_19 -> V_67 + 1 ;
V_147 . V_148 = V_145 ;
return F_47 ( V_19 , V_149 ,
( T_1 * ) & V_147 , sizeof( V_147 ) ) ;
}
static int F_35 ( struct V_8 * V_19 , T_1 V_145 )
{
struct V_146 V_150 ;
V_150 . V_19 = V_19 -> V_67 + 1 ;
V_150 . V_148 = V_145 ;
return F_47 ( V_19 , V_151 ,
( T_1 * ) & V_150 , sizeof( V_150 ) ) ;
}
static int F_42 ( struct V_8 * V_19 , T_1 V_145 )
{
struct V_146 V_152 ;
V_152 . V_19 = V_19 -> V_67 + 1 ;
V_152 . V_148 = V_145 ;
return F_47 ( V_19 , V_153 ,
( T_1 * ) & V_152 , sizeof( V_152 ) ) ;
}
static int F_25 ( struct V_8 * V_19 , T_1 V_154 )
{
struct V_155 V_156 ;
V_156 . V_19 = V_19 -> V_67 + 1 ;
V_156 . V_157 = V_154 ;
return F_47 ( V_19 , V_158 ,
( T_1 * ) & V_156 , sizeof( V_156 ) ) ;
}
static int F_33 ( struct V_8 * V_19 )
{
struct V_103 V_159 ;
V_159 . V_19 = V_19 -> V_67 + 1 ;
return F_47 ( V_19 , V_91 ,
( T_1 * ) & V_159 , sizeof( V_159 ) ) ;
}
static int F_30 ( struct V_8 * V_19 )
{
struct V_103 V_106 ;
V_106 . V_19 = V_19 -> V_67 + 1 ;
return F_47 ( V_19 , V_160 ,
( T_1 * ) & V_106 , sizeof( V_106 ) ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_47 = 0 ;
V_9 = V_2 -> V_19 [ V_20 ] ;
V_11 = F_17 ( V_9 ) ;
F_48 ( & V_11 -> V_33 ) ;
if ( ! V_11 -> V_34 ) {
F_7 ( V_2 -> V_6 , V_9 -> V_39 -> V_14 ) ;
V_47 = F_46 ( V_9 -> V_39 , V_22 ) ;
if ( V_47 ) {
F_9 ( & V_2 -> V_6 -> V_6 ,
L_36 ,
V_85 , V_47 ) ;
goto exit;
}
}
V_11 -> V_34 ++ ;
exit:
F_51 ( & V_11 -> V_33 ) ;
return V_47 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = V_2 -> V_19 [ V_20 ] ;
V_11 = F_17 ( V_9 ) ;
F_48 ( & V_11 -> V_33 ) ;
V_11 -> V_34 -- ;
if ( ! V_11 -> V_34 )
F_50 ( V_9 -> V_39 ) ;
F_51 ( & V_11 -> V_33 ) ;
}
