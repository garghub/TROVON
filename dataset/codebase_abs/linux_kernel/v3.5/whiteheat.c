static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 , V_6 = - V_7 ;
const struct V_8 * V_9 = NULL , * V_10 = NULL ;
const struct V_11 * V_12 ;
if ( F_2 ( & V_10 , L_1 ,
& V_2 -> V_13 -> V_13 ) ) {
F_3 ( & V_2 -> V_13 -> V_13 ,
L_2 , V_14 ) ;
goto V_15;
}
if ( F_2 ( & V_9 , L_3 ,
& V_2 -> V_13 -> V_13 ) ) {
F_3 ( & V_2 -> V_13 -> V_13 ,
L_4 ,
V_14 ) ;
goto V_15;
}
V_6 = 0 ;
V_5 = F_4 ( V_2 , 1 ) ;
V_12 = ( const struct V_11 * ) V_9 -> V_16 ;
while ( V_12 ) {
V_5 = F_5 ( V_2 , F_6 ( V_12 -> V_17 ) ,
( unsigned char * ) V_12 -> V_16 ,
F_7 ( V_12 -> V_18 ) , 0xa0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_5
L_6 ,
V_14 , V_5 , F_6 ( V_12 -> V_17 ) ,
V_12 -> V_16 , F_7 ( V_12 -> V_18 ) ) ;
break;
}
V_12 = F_8 ( V_12 ) ;
}
V_5 = F_4 ( V_2 , 0 ) ;
V_12 = ( const struct V_11 * ) V_10 -> V_16 ;
while ( V_12 && F_6 ( V_12 -> V_17 ) < 0x1b40 )
V_12 = F_8 ( V_12 ) ;
while ( V_12 ) {
V_5 = F_5 ( V_2 , F_6 ( V_12 -> V_17 ) ,
( unsigned char * ) V_12 -> V_16 ,
F_7 ( V_12 -> V_18 ) , 0xa3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_5
L_7
L_8 , V_14 , V_5 ,
F_6 ( V_12 -> V_17 ) , V_12 -> V_16 ,
F_7 ( V_12 -> V_18 ) ) ;
break;
}
++ V_12 ;
}
V_5 = F_4 ( V_2 , 1 ) ;
V_12 = ( const struct V_11 * ) V_10 -> V_16 ;
while ( V_12 && F_6 ( V_12 -> V_17 ) < 0x1b40 ) {
V_5 = F_5 ( V_2 , F_6 ( V_12 -> V_17 ) ,
( unsigned char * ) V_12 -> V_16 ,
F_7 ( V_12 -> V_18 ) , 0xa0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_5
L_9
L_8 , V_14 , V_5 ,
F_6 ( V_12 -> V_17 ) , V_12 -> V_16 ,
F_7 ( V_12 -> V_18 ) ) ;
break;
}
++ V_12 ;
}
V_6 = 0 ;
V_5 = F_4 ( V_2 , 0 ) ;
V_15:
F_9 ( V_9 ) ;
F_9 ( V_10 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_19 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
int V_6 ;
int V_29 ;
T_1 * V_30 ;
T_1 * V_31 ;
int V_32 ;
V_20 = V_2 -> V_23 [ V_33 ] ;
V_28 = F_12 ( V_2 -> V_13 ,
V_20 -> V_34 ) ;
V_30 = F_13 ( 2 , V_35 ) ;
if ( ! V_30 )
goto V_36;
V_30 [ 0 ] = V_37 ;
V_30 [ 1 ] = 0 ;
V_31 = F_13 ( sizeof( * V_27 ) + 1 , V_35 ) ;
if ( ! V_31 )
goto V_38;
F_14 ( V_2 -> V_13 , V_28 ) ;
V_6 = F_15 ( V_2 -> V_13 , V_28 , V_30 , 2 ,
& V_29 , V_39 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_10 ,
V_2 -> type -> V_40 , V_6 ) ;
goto V_41;
} else if ( V_29 != 2 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_11 ,
V_2 -> type -> V_40 , V_29 ) ;
goto V_41;
}
V_28 = F_16 ( V_2 -> V_13 ,
V_20 -> V_42 ) ;
F_14 ( V_2 -> V_13 , V_28 ) ;
V_6 = F_15 ( V_2 -> V_13 , V_28 , V_31 ,
sizeof( * V_27 ) + 1 , & V_29 , V_39 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_12 ,
V_2 -> type -> V_40 , V_6 ) ;
goto V_41;
} else if ( V_29 != sizeof( * V_27 ) + 1 ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_13 ,
V_2 -> type -> V_40 , V_29 ) ;
goto V_41;
} else if ( V_31 [ 0 ] != V_30 [ 0 ] ) {
F_3 ( & V_2 -> V_13 -> V_13 , L_14 ,
V_2 -> type -> V_40 , V_31 [ 0 ] ) ;
goto V_41;
}
V_27 = (struct V_26 * ) & V_31 [ 1 ] ;
F_17 ( & V_2 -> V_13 -> V_13 , L_15 ,
V_2 -> type -> V_40 ,
V_27 -> V_43 , V_27 -> V_44 ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_45 ; V_32 ++ ) {
V_23 = V_2 -> V_23 [ V_32 ] ;
V_25 = F_13 ( sizeof( struct V_24 ) , V_35 ) ;
if ( V_25 == NULL ) {
F_3 ( & V_23 -> V_13 ,
L_16 ,
V_2 -> type -> V_40 ) ;
goto V_46;
}
V_25 -> V_47 = 0 ;
F_18 ( V_23 , V_25 ) ;
}
V_22 = F_13 ( sizeof( struct V_21 ) ,
V_35 ) ;
if ( V_22 == NULL ) {
F_3 ( & V_2 -> V_13 -> V_13 ,
L_16 ,
V_2 -> type -> V_40 ) ;
goto V_48;
}
F_19 ( & V_22 -> V_49 ) ;
V_22 -> V_50 = 0 ;
F_20 ( & V_22 -> V_51 ) ;
F_18 ( V_20 , V_22 ) ;
V_20 -> V_52 -> V_53 = V_54 ;
V_20 -> V_55 -> V_53 = V_56 ;
F_21 ( V_31 ) ;
F_21 ( V_30 ) ;
return 0 ;
V_41:
F_3 ( & V_2 -> V_13 -> V_13 ,
L_17 ,
V_2 -> type -> V_40 ) ;
F_3 ( & V_2 -> V_13 -> V_13 ,
L_18 ,
V_2 -> type -> V_40 ) ;
F_3 ( & V_2 -> V_13 -> V_13 ,
L_19 ,
V_2 -> type -> V_40 ) ;
F_21 ( V_31 ) ;
return - V_57 ;
V_48:
for ( V_32 = V_2 -> V_45 - 1 ; V_32 >= 0 ; V_32 -- ) {
V_23 = V_2 -> V_23 [ V_32 ] ;
V_25 = F_22 ( V_23 ) ;
F_21 ( V_25 ) ;
V_46:
;
}
F_21 ( V_31 ) ;
V_38:
F_21 ( V_30 ) ;
V_36:
return - V_58 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_24 * V_25 ;
int V_32 ;
V_20 = V_2 -> V_23 [ V_33 ] ;
F_21 ( F_22 ( V_20 ) ) ;
for ( V_32 = 0 ; V_32 < V_2 -> V_45 ; V_32 ++ ) {
V_25 = F_22 ( V_2 -> V_23 [ V_32 ] ) ;
F_21 ( V_25 ) ;
}
}
static int F_24 ( struct V_59 * V_60 , struct V_19 * V_23 )
{
int V_61 ;
V_61 = F_25 ( V_23 -> V_2 ) ;
if ( V_61 )
goto exit;
V_61 = F_26 ( V_23 ) ;
if ( V_61 ) {
F_27 ( V_23 -> V_2 ) ;
goto exit;
}
V_61 = F_28 ( V_23 , V_62 | V_63 ) ;
if ( V_61 ) {
F_29 ( V_23 ) ;
F_27 ( V_23 -> V_2 ) ;
goto exit;
}
if ( V_60 )
F_30 ( V_60 ) ;
F_14 ( V_23 -> V_2 -> V_13 , V_23 -> V_55 -> V_28 ) ;
F_14 ( V_23 -> V_2 -> V_13 , V_23 -> V_52 -> V_28 ) ;
V_61 = F_31 ( V_60 , V_23 ) ;
if ( V_61 ) {
F_29 ( V_23 ) ;
F_27 ( V_23 -> V_2 ) ;
goto exit;
}
exit:
return V_61 ;
}
static void F_32 ( struct V_19 * V_23 )
{
F_33 ( V_23 ) ;
F_29 ( V_23 ) ;
F_34 ( V_23 ) ;
F_27 ( V_23 -> V_2 ) ;
}
static int F_35 ( struct V_59 * V_60 )
{
struct V_19 * V_23 = V_60 -> V_64 ;
struct V_24 * V_25 = F_22 ( V_23 ) ;
unsigned int V_65 = 0 ;
F_36 ( V_23 ) ;
if ( V_25 -> V_47 & V_66 )
V_65 |= V_67 ;
if ( V_25 -> V_47 & V_68 )
V_65 |= V_69 ;
return V_65 ;
}
static int F_37 ( struct V_59 * V_60 ,
unsigned int V_70 , unsigned int V_71 )
{
struct V_19 * V_23 = V_60 -> V_64 ;
struct V_24 * V_25 = F_22 ( V_23 ) ;
if ( V_70 & V_69 )
V_25 -> V_47 |= V_68 ;
if ( V_70 & V_67 )
V_25 -> V_47 |= V_66 ;
if ( V_71 & V_69 )
V_25 -> V_47 &= ~ V_68 ;
if ( V_71 & V_67 )
V_25 -> V_47 &= ~ V_66 ;
F_38 ( V_23 , V_25 -> V_47 & V_66 ) ;
F_39 ( V_23 , V_25 -> V_47 & V_68 ) ;
return 0 ;
}
static int F_40 ( struct V_59 * V_60 ,
unsigned int V_72 , unsigned long V_73 )
{
struct V_19 * V_23 = V_60 -> V_64 ;
struct V_74 V_75 ;
void T_2 * V_76 = ( void T_2 * ) V_73 ;
F_41 ( L_20 , V_14 , V_23 -> V_77 , V_72 ) ;
switch ( V_72 ) {
case V_78 :
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . type = V_79 ;
V_75 . line = V_23 -> V_2 -> V_80 ;
V_75 . V_23 = V_23 -> V_77 ;
V_75 . V_81 = V_82 | V_83 ;
V_75 . V_84 = F_42 ( & V_23 -> V_85 ) ;
V_75 . V_86 = 0 ;
V_75 . V_87 = 460800 ;
V_75 . V_88 = V_89 ;
V_75 . V_90 = V_89 ;
if ( F_43 ( V_76 , & V_75 , sizeof( V_75 ) ) )
return - V_91 ;
break;
default:
break;
}
return - V_92 ;
}
static void F_44 ( struct V_59 * V_60 ,
struct V_19 * V_23 , struct V_93 * V_94 )
{
F_30 ( V_60 ) ;
}
static void F_45 ( struct V_59 * V_60 , int V_95 )
{
struct V_19 * V_23 = V_60 -> V_64 ;
F_46 ( V_23 , V_95 ) ;
}
static void V_54 ( struct V_96 * V_96 )
{
int V_97 = V_96 -> V_97 ;
if ( V_97 ) {
F_41 ( L_21 , V_97 ) ;
return;
}
}
static void V_56 ( struct V_96 * V_96 )
{
struct V_19 * V_20 = V_96 -> V_98 ;
struct V_21 * V_22 ;
int V_97 = V_96 -> V_97 ;
unsigned char * V_16 = V_96 -> V_99 ;
int V_31 ;
V_22 = F_22 ( V_20 ) ;
if ( ! V_22 ) {
F_41 ( L_22 , V_14 ) ;
return;
}
if ( V_97 ) {
F_41 ( L_23 , V_14 , V_97 ) ;
if ( V_97 != - V_7 )
V_22 -> V_100 = V_101 ;
F_47 ( & V_22 -> V_51 ) ;
return;
}
F_48 ( V_102 , & V_20 -> V_13 ,
V_14 , V_96 -> V_103 , V_16 ) ;
if ( V_16 [ 0 ] == V_104 ) {
V_22 -> V_100 = V_104 ;
F_47 ( & V_22 -> V_51 ) ;
} else if ( V_16 [ 0 ] == V_101 ) {
V_22 -> V_100 = V_101 ;
F_47 ( & V_22 -> V_51 ) ;
} else if ( V_16 [ 0 ] == V_105 ) {
F_41 ( L_24 , V_14 ) ;
} else if ( V_16 [ 0 ] == V_106 ) {
memcpy ( V_22 -> V_107 , & V_16 [ 1 ] ,
V_96 -> V_103 - 1 ) ;
V_22 -> V_100 = V_104 ;
F_47 ( & V_22 -> V_51 ) ;
} else
F_41 ( L_25 , V_14 ) ;
V_31 = F_49 ( V_20 -> V_55 , V_108 ) ;
if ( V_31 )
F_41 ( L_26 ,
V_14 , V_31 ) ;
}
static int F_50 ( struct V_19 * V_23 , T_1 V_30 ,
T_1 * V_16 , T_1 V_109 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_24 * V_25 ;
T_1 * V_99 ;
int V_61 = 0 ;
int V_110 ;
F_41 ( L_27 , V_14 , V_30 ) ;
V_20 = V_23 -> V_2 -> V_23 [ V_33 ] ;
V_22 = F_22 ( V_20 ) ;
F_51 ( & V_22 -> V_49 ) ;
V_22 -> V_100 = false ;
V_99 = ( T_1 * ) V_20 -> V_52 -> V_99 ;
V_99 [ 0 ] = V_30 ;
memcpy ( & V_99 [ 1 ] , V_16 , V_109 ) ;
V_20 -> V_52 -> V_111 = V_109 + 1 ;
V_61 = F_49 ( V_20 -> V_52 , V_112 ) ;
if ( V_61 ) {
F_41 ( L_28 , V_14 ) ;
goto exit;
}
V_110 = F_52 ( V_22 -> V_51 ,
( bool ) V_22 -> V_100 , V_113 ) ;
if ( ! V_110 )
F_53 ( V_20 -> V_52 ) ;
if ( V_22 -> V_100 == false ) {
F_41 ( L_29 , V_14 ) ;
V_61 = - V_114 ;
goto exit;
}
if ( V_22 -> V_100 == V_101 ) {
F_41 ( L_30 , V_14 ) ;
V_61 = - V_115 ;
goto exit;
}
if ( V_22 -> V_100 == V_104 ) {
F_41 ( L_31 , V_14 ) ;
switch ( V_30 ) {
case V_106 :
V_25 = F_22 ( V_23 ) ;
memcpy ( & V_25 -> V_47 , V_22 -> V_107 ,
sizeof( struct V_116 ) ) ;
break;
}
}
exit:
F_54 ( & V_22 -> V_49 ) ;
return V_61 ;
}
static int F_26 ( struct V_19 * V_23 )
{
struct V_117 V_118 ;
V_118 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
return F_50 ( V_23 , V_119 ,
( T_1 * ) & V_118 , sizeof( V_118 ) ) ;
}
static int F_29 ( struct V_19 * V_23 )
{
struct V_117 V_120 ;
V_120 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
return F_50 ( V_23 , V_121 ,
( T_1 * ) & V_120 , sizeof( V_120 ) ) ;
}
static void F_30 ( struct V_59 * V_60 )
{
struct V_19 * V_23 = V_60 -> V_64 ;
struct V_122 V_123 ;
unsigned int V_124 = V_60 -> V_125 -> V_126 ;
V_123 . V_23 = V_23 -> V_77 + 1 ;
switch ( V_124 & V_127 ) {
case V_128 : V_123 . V_129 = 5 ; break;
case V_130 : V_123 . V_129 = 6 ; break;
case V_131 : V_123 . V_129 = 7 ; break;
default:
case V_132 : V_123 . V_129 = 8 ; break;
}
F_41 ( L_32 , V_14 , V_123 . V_129 ) ;
if ( V_124 & V_133 )
if ( V_124 & V_134 )
if ( V_124 & V_135 )
V_123 . V_136 = V_137 ;
else
V_123 . V_136 = V_138 ;
else
if ( V_124 & V_135 )
V_123 . V_136 = V_139 ;
else
V_123 . V_136 = V_140 ;
else
V_123 . V_136 = V_141 ;
F_41 ( L_33 , V_14 , V_123 . V_136 ) ;
if ( V_124 & V_142 )
V_123 . V_143 = 2 ;
else
V_123 . V_143 = 1 ;
F_41 ( L_34 , V_14 , V_123 . V_143 ) ;
if ( V_124 & V_144 )
V_123 . V_145 = ( V_146 |
V_147 ) ;
else
V_123 . V_145 = V_148 ;
F_41 ( L_35 , V_14 ,
( V_123 . V_145 & V_146 ) ? L_36 : L_37 ,
( V_123 . V_145 & V_147 ) ? L_38 : L_37 ,
( V_123 . V_145 & V_149 ) ? L_39 : L_37 ,
( V_123 . V_145 & V_150 ) ? L_40 : L_37 ) ;
if ( F_55 ( V_60 ) )
V_123 . V_151 = V_152 ;
else
V_123 . V_151 = V_153 ;
F_41 ( L_41 , V_14 , V_123 . V_151 ) ;
V_123 . V_154 = F_56 ( V_60 ) ;
V_123 . V_155 = F_57 ( V_60 ) ;
F_41 ( L_42 ,
V_14 , V_123 . V_154 , V_123 . V_155 ) ;
V_123 . V_156 = F_58 ( V_60 ) ;
F_41 ( L_43 , V_14 , V_123 . V_156 ) ;
F_59 ( V_60 , V_123 . V_156 , V_123 . V_156 ) ;
V_123 . V_157 = 0 ;
F_50 ( V_23 , V_158 ,
( T_1 * ) & V_123 , sizeof( V_123 ) ) ;
}
static int F_39 ( struct V_19 * V_23 , T_1 V_159 )
{
struct V_160 V_161 ;
V_161 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
V_161 . V_162 = V_159 ;
return F_50 ( V_23 , V_163 ,
( T_1 * ) & V_161 , sizeof( V_161 ) ) ;
}
static int F_38 ( struct V_19 * V_23 , T_1 V_159 )
{
struct V_160 V_164 ;
V_164 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
V_164 . V_162 = V_159 ;
return F_50 ( V_23 , V_165 ,
( T_1 * ) & V_164 , sizeof( V_164 ) ) ;
}
static int F_46 ( struct V_19 * V_23 , T_1 V_159 )
{
struct V_160 V_166 ;
V_166 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
V_166 . V_162 = V_159 ;
return F_50 ( V_23 , V_167 ,
( T_1 * ) & V_166 , sizeof( V_166 ) ) ;
}
static int F_28 ( struct V_19 * V_23 , T_1 V_168 )
{
struct V_169 V_170 ;
V_170 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
V_170 . V_171 = V_168 ;
return F_50 ( V_23 , V_172 ,
( T_1 * ) & V_170 , sizeof( V_170 ) ) ;
}
static int F_36 ( struct V_19 * V_23 )
{
struct V_117 V_173 ;
V_173 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
return F_50 ( V_23 , V_106 ,
( T_1 * ) & V_173 , sizeof( V_173 ) ) ;
}
static int F_33 ( struct V_19 * V_23 )
{
struct V_117 V_120 ;
V_120 . V_23 = V_23 -> V_77 - V_23 -> V_2 -> V_80 + 1 ;
return F_50 ( V_23 , V_174 ,
( T_1 * ) & V_120 , sizeof( V_120 ) ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_61 = 0 ;
V_20 = V_2 -> V_23 [ V_33 ] ;
V_22 = F_22 ( V_20 ) ;
F_51 ( & V_22 -> V_49 ) ;
if ( ! V_22 -> V_50 ) {
F_14 ( V_2 -> V_13 , V_20 -> V_55 -> V_28 ) ;
V_61 = F_49 ( V_20 -> V_55 , V_35 ) ;
if ( V_61 ) {
F_3 ( & V_2 -> V_13 -> V_13 ,
L_44 ,
V_14 , V_61 ) ;
goto exit;
}
}
V_22 -> V_50 ++ ;
exit:
F_54 ( & V_22 -> V_49 ) ;
return V_61 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_20 = V_2 -> V_23 [ V_33 ] ;
V_22 = F_22 ( V_20 ) ;
F_51 ( & V_22 -> V_49 ) ;
V_22 -> V_50 -- ;
if ( ! V_22 -> V_50 )
F_53 ( V_20 -> V_55 ) ;
F_54 ( & V_22 -> V_49 ) ;
}
