struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
F_2 ( V_20 , L_1 ) ;
if ( ! V_3 ) {
F_2 ( V_21 , L_2 ) ;
return NULL ;
}
V_10 = V_3 -> V_22 ;
V_13 = V_10 -> V_13 ;
V_8 = V_13 -> V_8 ;
if ( V_4 > V_10 -> V_13 -> V_23 . V_24 ) {
F_3 ( V_25 , V_8 , L_3
L_4
L_5 , V_4 ,
V_10 -> V_13 -> V_23 . V_24 ,
V_10 -> V_13 -> V_23 . V_24 ) ;
V_4 = V_10 -> V_13 -> V_23 . V_24 ;
}
V_11 = F_4 ( & V_26 ,
V_8 , V_4 ,
sizeof( * V_17 ) ,
sizeof( * V_19 ) ,
V_6 , V_27 ) ;
if ( ! V_11 )
return NULL ;
V_15 = V_11 -> V_22 ;
V_17 = V_15 -> V_22 ;
V_17 -> V_28 = F_5 ( L_6 ,
V_13 -> V_29 ,
sizeof( struct V_30 ) ,
64 , 0 ) ;
if ( ! V_17 -> V_28 )
goto V_31;
return V_11 ;
V_31:
F_6 ( V_11 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_22 ;
struct V_16 * V_17 = V_15 -> V_22 ;
F_2 ( V_20 , L_7 ) ;
F_8 ( V_17 -> V_28 ) ;
F_6 ( V_11 ) ;
}
struct V_32 *
F_9 ( struct V_1 * V_11 , T_2 V_33 )
{
struct V_12 * V_13 ;
struct V_7 * V_8 ;
struct V_32 * V_34 ;
struct V_35 * V_35 ;
struct V_36 * V_37 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_2 ( V_20 , L_8
L_9 , V_33 ) ;
V_8 = F_10 ( V_11 ) ;
V_13 = F_11 ( V_8 ) ;
V_34 = F_12 ( V_11 , sizeof( * V_35 ) , V_33 ) ;
if ( ! V_34 )
return NULL ;
V_37 = V_34 -> V_22 ;
V_35 = V_37 -> V_22 ;
V_35 -> V_3 = NULL ;
V_35 -> V_13 = V_13 ;
V_35 -> V_37 = V_37 ;
V_15 = V_11 -> V_22 ;
V_17 = V_15 -> V_22 ;
V_35 -> V_17 = V_17 ;
return V_34 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_35 * V_35 ,
unsigned int V_33 )
{
if ( V_13 -> V_38 [ V_33 ] ) {
F_2 ( V_21 ,
L_10 ) ;
return - V_39 ;
} else {
F_2 ( V_20 , L_11 ,
V_33 , V_35 ) ;
V_13 -> V_38 [ V_33 ] = V_35 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_11 ,
struct V_32 * V_34 ,
T_3 V_40 , int V_41 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
struct V_35 * V_35 = V_37 -> V_22 ;
struct V_7 * V_8 =
(struct V_7 * ) F_10 ( V_11 ) ;
struct V_12 * V_13 = (struct V_12 * ) F_11 ( V_8 ) ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
F_2 ( V_20 , L_12 ) ;
V_3 = F_15 ( V_40 ) ;
if ( ! V_3 )
return - V_39 ;
V_10 = V_3 -> V_22 ;
if ( F_16 ( V_11 , V_34 , V_41 ) )
return - V_39 ;
if ( V_10 -> V_13 != V_13 ) {
F_2 ( V_20 ,
L_13 ,
V_10 -> V_13 , V_13 ) ;
return - V_42 ;
}
V_35 -> V_43 = V_10 -> V_44 ;
V_35 -> V_3 = V_10 ;
V_10 -> V_37 = V_35 ;
F_2 ( V_20 , L_14 ,
V_35 , V_37 , V_10 -> V_44 ) ;
return F_13 ( V_13 , V_35 , V_10 -> V_44 ) ;
}
int F_17 ( struct V_2 * V_3 ,
enum V_45 V_46 , char * V_47 )
{
struct V_9 * V_10 = V_3 -> V_22 ;
int V_48 = 0 ;
F_2 ( V_20 , L_15 , V_46 ) ;
switch ( V_46 ) {
case V_49 :
V_48 = sprintf ( V_47 , L_16 , V_10 -> V_50 ) ;
break;
case V_51 :
if ( V_10 -> V_52 == V_53 )
V_48 = sprintf ( V_47 , L_17 , & V_10 -> V_54 ) ;
else
V_48 = sprintf ( V_47 , L_18 , & V_10 -> V_55 ) ;
break;
default:
return - V_56 ;
}
return V_48 ;
}
int F_18 ( struct V_32 * V_34 ,
enum V_45 V_46 , char * V_47 , int V_57 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
struct V_14 * V_58 = V_37 -> V_58 ;
int V_59 ;
F_2 ( V_20 , L_19 , V_46 ) ;
V_59 = F_19 ( V_34 , V_46 , V_47 , V_57 ) ;
if ( V_59 )
return V_59 ;
switch ( V_46 ) {
case V_60 :
if ( V_58 -> V_61 > 8192 )
V_58 -> V_61 = 8192 ;
break;
case V_62 :
if ( V_37 -> V_63 > 65536 )
V_37 -> V_63 = 65536 ;
break;
case V_64 :
if ( V_58 -> V_65 > 262144 )
V_58 -> V_65 = 262144 ;
break;
case V_66 :
if ( ( V_37 -> V_67 > 65536 ) ||
( V_37 -> V_67 == 0 ) )
V_37 -> V_67 = 65536 ;
default:
return 0 ;
}
return 0 ;
}
int F_20 ( struct V_7 * V_8 ,
enum V_68 V_46 , char * V_47 )
{
struct V_12 * V_13 = (struct V_12 * ) F_11 ( V_8 ) ;
int V_69 = 0 ;
F_2 ( V_20 , L_20 , V_46 ) ;
switch ( V_46 ) {
case V_70 :
V_69 = F_21 ( V_47 , V_13 ) ;
if ( V_69 < 0 ) {
F_2 ( V_21 , L_21 ) ;
return V_69 ;
}
break;
default:
return F_22 ( V_8 , V_46 , V_47 ) ;
}
return V_69 ;
}
int F_21 ( char * V_47 , struct V_12 * V_13 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
unsigned int V_75 , V_76 ;
unsigned short V_69 , V_77 ;
struct V_78 * V_79 = & V_13 -> V_80 . V_81 . V_82 ;
int V_83 ;
if ( V_13 -> V_84 )
return F_23 ( V_47 , V_13 -> V_85 ,
V_86 ) ;
V_75 = F_24 ( V_13 ) ;
if ( ! V_75 ) {
F_2 ( V_21 , L_22 ) ;
return - V_87 ;
} else
F_25 ( V_13 -> V_80 . V_88 [ V_75 ] ,
V_13 -> V_80 . V_89 [ V_75 ] ) ;
V_76 = ( V_13 -> V_80 . V_89 [ V_75 ] & 0x00FF0000 ) >> 16 ;
V_77 = ( V_13 -> V_80 . V_89 [ V_75 ] & 0x0000FF00 ) >> 8 ;
V_69 = V_13 -> V_80 . V_89 [ V_75 ] & 0x000000FF ;
if ( V_69 || V_77 ) {
F_2 ( V_21 , L_23
L_24 ,
V_69 , V_77 ) ;
F_26 ( & V_13 -> V_80 , V_75 ) ;
return - V_90 ;
}
V_74 = F_27 ( V_79 , V_76 ) ;
F_26 ( & V_13 -> V_80 , V_75 ) ;
V_72 = F_28 ( V_74 ) ;
memcpy ( V_13 -> V_85 , V_72 -> V_85 , V_86 ) ;
V_83 = F_23 ( V_47 , V_13 -> V_85 ,
V_86 ) ;
V_13 -> V_84 = 1 ;
return V_83 ;
}
void F_29 ( struct V_32 * V_34 ,
struct V_91 * V_92 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
F_2 ( V_20 , L_25 ) ;
V_92 -> V_93 = V_37 -> V_93 ;
V_92 -> V_94 = V_37 -> V_94 ;
V_92 -> V_95 = V_37 -> V_96 ;
V_92 -> V_97 = V_37 -> V_98 ;
V_92 -> V_99 = V_37 -> V_100 ;
V_92 -> V_101 = V_37 -> V_102 ;
V_92 -> V_103 = V_37 -> V_104 ;
V_92 -> V_105 = V_37 -> V_106 ;
V_92 -> V_107 = V_37 -> V_108 ;
V_92 -> V_109 = 0 ;
V_92 -> V_110 = 0 ;
V_92 -> V_111 = 0 ;
strcpy ( V_92 -> V_112 [ 0 ] . V_113 , L_26 ) ;
V_92 -> V_112 [ 0 ] . V_114 = V_37 -> V_115 ;
}
static void F_30 ( struct V_35 * V_35 ,
struct V_116 * V_23 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_14 * V_58 = V_37 -> V_58 ;
F_31 ( struct V_117 , V_118 ,
V_23 , V_58 -> V_65 ) ;
F_31 ( struct V_117 ,
V_119 , V_23 ,
V_37 -> V_67 ) ;
F_31 ( struct V_117 , V_120 ,
V_23 , V_58 -> V_61 ) ;
F_31 ( struct V_117 , V_121 , V_23 ,
V_58 -> V_121 ) ;
F_31 ( struct V_117 , V_122 , V_23 ,
V_37 -> V_123 ) ;
F_31 ( struct V_117 , V_124 , V_23 ,
V_37 -> V_125 ) ;
F_31 ( struct V_117 , V_126 , V_23 ,
V_58 -> V_127 ) ;
F_31 ( struct V_117 , V_128 , V_23 ,
V_58 -> V_129 ) ;
F_31 ( struct V_117 , V_130 , V_23 ,
( V_37 -> V_130 - 1 ) ) ;
}
int F_32 ( struct V_32 * V_34 )
{
struct V_36 * V_37 = V_34 -> V_22 ;
struct V_35 * V_35 = V_37 -> V_22 ;
struct V_9 * V_10 ;
struct V_116 V_23 ;
F_2 ( V_20 , L_27 ) ;
memset ( & V_23 , 0 , sizeof( struct V_116 ) ) ;
V_10 = V_35 -> V_3 ;
if ( ! V_10 )
F_2 ( V_21 , L_28 ) ;
V_35 -> V_131 = 0 ;
F_30 ( V_35 , & V_23 ) ;
F_33 ( V_35 , & V_23 ) ;
F_34 ( V_34 ) ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 )
{
unsigned short V_33 = 0xFFFF ;
if ( ! V_13 -> V_132 )
return V_33 ;
V_33 = V_13 -> V_133 [ V_13 -> V_134 ++ ] ;
if ( V_13 -> V_134 == V_13 -> V_23 . V_135 )
V_13 -> V_134 = 0 ;
V_13 -> V_132 -- ;
return V_33 ;
}
static void F_36 ( struct V_12 * V_13 , unsigned short V_33 )
{
V_13 -> V_132 ++ ;
V_13 -> V_133 [ V_13 -> V_136 ++ ] = V_33 ;
if ( V_13 -> V_136 == V_13 -> V_23 . V_135 )
V_13 -> V_136 = 0 ;
}
static void F_37 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
F_36 ( V_13 , V_10 -> V_44 ) ;
V_10 -> V_13 = NULL ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_137 * V_138 ,
struct V_137 * V_54 , int V_139 )
{
struct V_9 * V_10 = V_3 -> V_22 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_78 * V_79 = & V_13 -> V_80 . V_81 . V_82 ;
struct V_73 * V_74 ;
struct V_140 * V_141 ;
unsigned short V_69 , V_77 ;
struct V_142 V_143 ;
unsigned int V_75 , V_76 ;
int V_59 = - V_144 ;
F_2 ( V_20 , L_29 ) ;
V_10 -> V_44 = F_35 ( V_13 ) ;
if ( V_10 -> V_44 == 0xFFFF ) {
F_2 ( V_21 , L_30 ) ;
return V_59 ;
}
F_2 ( V_20 , L_31 ,
V_10 -> V_44 ) ;
V_13 -> V_145 [ V_10 -> V_44 -
V_13 -> V_146 . V_147 ] = V_3 ;
if ( V_10 -> V_44 > ( V_13 -> V_146 . V_147 +
V_13 -> V_23 . V_135 * 2 ) ) {
F_2 ( V_21 , L_32 ) ;
goto V_148;
}
V_10 -> V_149 = 0 ;
V_143 . V_150 = F_39 ( V_13 -> V_80 . V_151 ,
sizeof( struct V_152 ) ,
& V_143 . V_153 ) ;
if ( V_143 . V_150 == NULL ) {
F_2 ( V_21 ,
L_33
L_5 ) ;
F_36 ( V_13 , V_10 -> V_44 ) ;
return - V_144 ;
}
V_143 . V_154 = sizeof( struct V_152 ) ;
memset ( V_143 . V_150 , 0 , V_143 . V_154 ) ;
V_75 = F_40 ( V_13 , V_54 , V_10 , & V_143 ) ;
if ( ! V_75 ) {
F_2 ( V_21 ,
L_34 ,
V_10 -> V_44 ) ;
F_36 ( V_13 , V_10 -> V_44 ) ;
F_41 ( V_13 -> V_80 . V_151 , V_143 . V_154 ,
V_143 . V_150 , V_143 . V_153 ) ;
return - V_90 ;
} else {
F_25 ( V_13 -> V_80 . V_88 [ V_75 ] ,
V_13 -> V_80 . V_89 [ V_75 ] ) ;
}
V_76 = ( V_13 -> V_80 . V_89 [ V_75 ] & 0x00FF0000 ) >> 16 ;
V_77 = ( V_13 -> V_80 . V_89 [ V_75 ] & 0x0000FF00 ) >> 8 ;
V_69 = V_13 -> V_80 . V_89 [ V_75 ] & 0x000000FF ;
if ( V_69 || V_77 ) {
F_2 ( V_21 , L_35
L_24 ,
V_69 , V_77 ) ;
F_26 ( & V_13 -> V_80 , V_75 ) ;
F_41 ( V_13 -> V_80 . V_151 , V_143 . V_154 ,
V_143 . V_150 , V_143 . V_153 ) ;
goto V_148;
} else {
V_74 = F_27 ( V_79 , V_76 ) ;
F_26 ( & V_13 -> V_80 , V_75 ) ;
V_141 = F_28 ( V_74 ) ;
V_10 = V_3 -> V_22 ;
V_10 -> V_155 = V_141 -> V_156 ;
V_10 -> V_149 = 1 ;
F_2 ( V_20 , L_36 ) ;
}
F_41 ( V_13 -> V_80 . V_151 , V_143 . V_154 ,
V_143 . V_150 , V_143 . V_153 ) ;
return 0 ;
V_148:
F_37 ( V_10 ) ;
return - V_87 ;
}
struct V_2 *
F_42 ( struct V_7 * V_8 , struct V_137 * V_54 ,
int V_139 )
{
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_2 * V_3 ;
int V_59 ;
F_2 ( V_20 , L_37 ) ;
if ( V_8 )
V_13 = F_11 ( V_8 ) ;
else {
V_59 = - V_157 ;
F_2 ( V_21 , L_38 ) ;
return F_43 ( V_59 ) ;
}
if ( V_13 -> V_158 != V_159 ) {
V_59 = - V_87 ;
F_2 ( V_21 , L_39 ) ;
return F_43 ( V_59 ) ;
}
V_3 = F_44 ( sizeof( struct V_9 ) ) ;
if ( ! V_3 ) {
V_59 = - V_144 ;
return F_43 ( V_59 ) ;
}
V_10 = V_3 -> V_22 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_160 = V_3 ;
V_59 = F_38 ( V_3 , NULL , V_54 , V_139 ) ;
if ( V_59 ) {
F_2 ( V_21 , L_40 ) ;
goto V_148;
}
return V_3 ;
V_148:
F_45 ( V_3 ) ;
return F_43 ( V_59 ) ;
}
int F_46 ( struct V_2 * V_3 , int V_161 )
{
struct V_9 * V_10 = V_3 -> V_22 ;
F_2 ( V_20 , L_41 ) ;
if ( V_10 -> V_149 == 1 )
return 1 ;
else
return 0 ;
}
static int F_47 ( struct V_9 * V_10 , int V_162 )
{
int V_59 = 0 ;
unsigned int V_75 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_75 = F_48 ( V_13 , V_10 -> V_44 , V_162 ) ;
if ( ! V_75 ) {
F_2 ( V_20 , L_42 ,
V_10 -> V_44 ) ;
V_59 = - V_90 ;
} else {
F_25 ( V_13 -> V_80 . V_88 [ V_75 ] ,
V_13 -> V_80 . V_89 [ V_75 ] ) ;
F_26 ( & V_13 -> V_80 , V_75 ) ;
}
return V_59 ;
}
static int F_49 ( struct V_12 * V_13 ,
unsigned int V_33 )
{
if ( V_13 -> V_38 [ V_33 ] )
V_13 -> V_38 [ V_33 ] = NULL ;
else {
F_2 ( V_20 , L_43 ) ;
return - V_39 ;
}
return 0 ;
}
void F_50 ( struct V_2 * V_3 )
{
struct V_35 * V_35 ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
unsigned int V_75 ;
unsigned short V_163 = V_164 ;
V_10 = V_3 -> V_22 ;
V_13 = V_10 -> V_13 ;
F_2 ( V_20 , L_44 ,
V_10 -> V_44 ) ;
if ( ! V_10 -> V_37 ) {
F_2 ( V_20 , L_45
L_46 ) ;
return;
}
V_35 = V_10 -> V_37 ;
F_51 ( V_35 -> V_37 ) ;
F_2 ( V_20 , L_47 ,
V_10 -> V_44 ) ;
V_75 = F_52 ( V_13 , V_10 ,
V_10 -> V_44 , 1 ,
V_163 ) ;
if ( ! V_75 ) {
F_2 ( V_21 ,
L_48 ,
V_10 -> V_44 ) ;
} else {
F_25 ( V_13 -> V_80 . V_88 [ V_75 ] ,
V_13 -> V_80 . V_89 [ V_75 ] ) ;
F_26 ( & V_13 -> V_80 , V_75 ) ;
}
F_47 ( V_10 , V_165 ) ;
F_37 ( V_10 ) ;
F_49 ( V_13 , V_10 -> V_44 ) ;
F_45 ( V_10 -> V_160 ) ;
}
