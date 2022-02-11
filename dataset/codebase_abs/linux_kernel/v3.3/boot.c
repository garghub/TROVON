static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 |= V_3 ;
F_3 ( V_2 , V_5 , V_4 ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
unsigned int V_6 = 0 ;
unsigned int * V_7 = V_2 -> V_8 . V_7 ;
if ( ( V_7 [ V_9 ] == V_10 ) &&
( V_7 [ V_11 ] < V_12 ) )
V_6 |= V_13 ;
if ( V_7 [ V_9 ] == V_14 )
V_6 |= V_13 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = sscanf ( V_2 -> V_8 . V_16 + 4 , L_1 ,
& V_2 -> V_8 . V_7 [ 0 ] , & V_2 -> V_8 . V_7 [ 1 ] ,
& V_2 -> V_8 . V_7 [ 2 ] , & V_2 -> V_8 . V_7 [ 3 ] ,
& V_2 -> V_8 . V_7 [ 4 ] ) ;
if ( V_15 != 5 ) {
F_6 ( L_2 ) ;
memset ( V_2 -> V_8 . V_7 , 0 , sizeof( V_2 -> V_8 . V_7 ) ) ;
return;
}
V_2 -> V_6 |= F_4 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_17 V_18 ;
F_8 ( V_2 , V_2 -> V_19 , & V_18 , sizeof( V_18 ) ,
false ) ;
strncpy ( V_2 -> V_8 . V_16 , V_18 . V_20 ,
sizeof( V_2 -> V_8 . V_16 ) ) ;
V_2 -> V_8 . V_16 [ sizeof( V_2 -> V_8 . V_16 ) - 1 ] = '\0' ;
F_5 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_21 ,
T_2 V_22 , T_1 V_23 )
{
struct V_24 V_25 ;
int V_26 , V_27 , V_28 ;
T_3 * V_29 , * V_30 ;
F_10 ( V_31 , L_3 ) ;
F_10 ( V_31 , L_4 ,
V_22 , V_32 ) ;
if ( ( V_22 % 4 ) != 0 ) {
F_11 ( L_5 ) ;
return - V_33 ;
}
V_30 = F_12 ( V_32 , V_34 ) ;
if ( ! V_30 ) {
F_11 ( L_6 ) ;
return - V_35 ;
}
memcpy ( & V_25 , & V_36 [ V_37 ] , sizeof( V_25 ) ) ;
V_25 . V_38 . V_39 = V_23 ;
F_13 ( V_2 , & V_25 ) ;
V_27 = 0 ;
V_28 = V_36 [ V_37 ] . V_38 . V_40 ;
while ( V_27 < V_22 / V_32 ) {
V_26 = V_23 + ( V_27 + 2 ) * V_32 ;
if ( V_26 > V_28 ) {
V_26 = V_23 + V_27 * V_32 ;
V_28 = V_27 * V_32 +
V_36 [ V_37 ] . V_38 . V_40 ;
V_25 . V_38 . V_39 = V_26 ;
F_13 ( V_2 , & V_25 ) ;
}
V_26 = V_23 + V_27 * V_32 ;
V_29 = V_21 + V_27 * V_32 ;
memcpy ( V_30 , V_29 , V_32 ) ;
F_10 ( V_31 , L_7 ,
V_29 , V_26 ) ;
F_14 ( V_2 , V_26 , V_30 , V_32 , false ) ;
V_27 ++ ;
}
V_26 = V_23 + V_27 * V_32 ;
V_29 = V_21 + V_27 * V_32 ;
memcpy ( V_30 , V_29 , V_22 % V_32 ) ;
F_10 ( V_31 , L_8 ,
V_22 % V_32 , V_29 , V_26 ) ;
F_14 ( V_2 , V_26 , V_30 , V_22 % V_32 , false ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_41 , V_26 , V_42 ;
int V_15 = 0 ;
T_3 * V_43 ;
V_43 = V_2 -> V_43 ;
V_41 = F_17 ( ( V_44 * ) V_43 ) ;
V_43 += sizeof( T_1 ) ;
F_10 ( V_31 , L_9 , V_41 ) ;
while ( V_41 -- ) {
V_26 = F_17 ( ( V_44 * ) V_43 ) ;
V_43 += sizeof( T_1 ) ;
V_42 = F_17 ( ( V_44 * ) V_43 ) ;
V_43 += sizeof( T_1 ) ;
if ( V_42 > 300000 ) {
F_18 ( L_10 , V_42 ) ;
return - V_45 ;
}
F_10 ( V_31 , L_11 ,
V_41 , V_26 , V_42 ) ;
V_15 = F_9 ( V_2 , V_43 , V_42 , V_26 ) ;
if ( V_15 != 0 )
break;
V_43 += V_42 ;
}
return V_15 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_2 V_46 , V_47 ;
int V_48 ;
T_1 V_49 , V_50 ;
T_3 * V_51 , * V_52 ;
if ( V_2 -> V_53 == NULL )
return - V_54 ;
if ( V_2 -> V_8 . V_55 == V_56 ) {
struct V_57 * V_53 = (struct V_57 * ) V_2 -> V_53 ;
if ( V_2 -> V_46 == sizeof( struct V_57 ) ) {
if ( V_53 -> V_58 . V_59 )
V_2 -> V_60 = true ;
} else {
F_11 ( L_12 ,
V_2 -> V_46 ,
sizeof( struct V_57 ) ) ;
F_15 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
V_2 -> V_46 = 0 ;
return - V_61 ;
}
V_46 = sizeof( V_53 -> V_53 ) ;
V_51 = ( T_3 * ) V_53 -> V_53 ;
} else {
struct V_62 * V_53 =
(struct V_62 * ) V_2 -> V_53 ;
if ( V_2 -> V_46 == sizeof( struct V_62 ) ||
V_2 -> V_46 == V_63 ) {
if ( V_53 -> V_58 . V_59 )
V_2 -> V_60 = true ;
}
if ( V_2 -> V_46 != sizeof( struct V_62 ) &&
( V_2 -> V_46 != V_63 ||
V_2 -> V_60 ) ) {
F_11 ( L_12 ,
V_2 -> V_46 , sizeof( struct V_62 ) ) ;
F_15 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
V_2 -> V_46 = 0 ;
return - V_61 ;
}
V_46 = sizeof( V_53 -> V_53 ) ;
V_51 = ( T_3 * ) V_53 -> V_53 ;
}
V_51 [ 11 ] = V_2 -> V_64 [ 0 ] ;
V_51 [ 10 ] = V_2 -> V_64 [ 1 ] ;
V_51 [ 6 ] = V_2 -> V_64 [ 2 ] ;
V_51 [ 5 ] = V_2 -> V_64 [ 3 ] ;
V_51 [ 4 ] = V_2 -> V_64 [ 4 ] ;
V_51 [ 3 ] = V_2 -> V_64 [ 5 ] ;
while ( V_51 [ 0 ] ) {
V_47 = V_51 [ 0 ] ;
V_49 = ( V_51 [ 1 ] & 0xfe ) | ( ( T_1 ) ( V_51 [ 2 ] << 8 ) ) ;
V_49 += V_65 ;
V_51 += 3 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
if ( V_51 + 3 >= ( T_3 * ) V_2 -> V_53 + V_46 )
goto V_66;
V_50 = ( V_51 [ 0 ] | ( V_51 [ 1 ] << 8 )
| ( V_51 [ 2 ] << 16 ) | ( V_51 [ 3 ] << 24 ) ) ;
F_10 ( V_31 ,
L_13 ,
V_49 , V_50 ) ;
F_3 ( V_2 , V_49 , V_50 ) ;
V_51 += 4 ;
V_49 += 4 ;
}
if ( V_51 >= ( T_3 * ) V_2 -> V_53 + V_46 )
goto V_66;
}
V_51 = ( T_3 * ) V_2 -> V_53 +
F_20 ( V_51 - ( T_3 * ) V_2 -> V_53 + 7 , 4 ) ;
if ( V_51 >= ( T_3 * ) V_2 -> V_53 + V_46 )
goto V_66;
V_46 -= V_51 - ( T_3 * ) V_2 -> V_53 ;
F_13 ( V_2 , & V_36 [ V_67 ] ) ;
V_52 = F_21 ( V_51 , V_46 , V_34 ) ;
if ( ! V_52 )
return - V_35 ;
F_14 ( V_2 , V_68 , V_52 , V_46 , false ) ;
F_15 ( V_52 ) ;
return 0 ;
V_66:
F_11 ( L_14 ) ;
return - V_61 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_3 ( V_2 , V_69 ,
V_70 & ~ ( V_71 ) ) ;
F_3 ( V_2 , V_72 , V_73 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_74 ;
T_1 V_75 ;
F_3 ( V_2 , V_76 , V_77 ) ;
V_74 = V_78 + F_25 ( V_79 ) ;
while ( 1 ) {
V_75 = F_2 ( V_2 , V_76 ) ;
F_10 ( V_31 , L_15 , V_75 ) ;
if ( ( V_75 & V_77 ) == 0 )
break;
if ( F_26 ( V_78 , V_74 ) ) {
F_11 ( L_16 ) ;
return - 1 ;
}
F_27 ( V_80 ) ;
}
F_3 ( V_2 , V_81 , 0x0 ) ;
F_3 ( V_2 , V_82 , 0xffff ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_83 , V_15 ;
T_1 V_84 , V_85 ;
F_1 ( V_2 , V_86 ) ;
V_84 = F_2 ( V_2 , V_87 ) ;
F_10 ( V_31 , L_17 , V_84 ) ;
if ( V_84 != V_2 -> V_8 . V_55 ) {
F_11 ( L_18 ) ;
return - V_33 ;
}
V_83 = 0 ;
while ( V_83 ++ < V_88 ) {
F_27 ( V_89 ) ;
V_85 = F_2 ( V_2 , V_90 ) ;
if ( V_85 == 0xffffffff ) {
F_11 ( L_19
L_20 ) ;
return - V_33 ;
}
else if ( V_85 & V_91 ) {
F_3 ( V_2 , V_92 ,
V_91 ) ;
break;
}
}
if ( V_83 > V_88 ) {
F_11 ( L_21
L_22 ) ;
return - V_33 ;
}
V_2 -> V_19 = F_2 ( V_2 , V_93 ) ;
V_2 -> V_94 = F_2 ( V_2 , V_95 ) ;
F_13 ( V_2 , & V_36 [ V_67 ] ) ;
F_10 ( V_96 , L_23 ,
V_2 -> V_19 , V_2 -> V_94 ) ;
F_7 ( V_2 ) ;
V_2 -> V_97 = V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ;
V_15 = F_29 ( V_2 ) ;
if ( V_15 < 0 ) {
F_11 ( L_24 ) ;
return V_15 ;
}
F_30 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_114 ;
V_114 = F_32 ( V_2 , V_115 ) ;
V_114 &= ~ V_116 ;
F_33 ( V_2 , V_115 , V_114 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_117 ;
if ( V_2 -> V_8 . V_55 == V_56 )
V_117 = F_32 ( V_2 , V_118 ) ;
else
V_117 = F_32 ( V_2 , V_119 ) ;
V_117 = ( V_117 & V_120 ) >> V_121 ;
V_2 -> V_122 = ( V_123 ) V_117 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_4 V_124 ;
V_124 = F_32 ( V_2 , V_125 ) ;
if ( V_124 == 0xFFFF )
return - V_126 ;
V_124 |= ( F_36 ( 3 ) | F_36 ( 5 ) | F_36 ( 6 ) ) ;
F_33 ( V_2 , V_125 , V_124 ) ;
F_33 ( V_2 , V_127 ,
V_128 | V_129 ) ;
F_37 ( 15 ) ;
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
T_4 V_130 ;
V_130 = F_32 ( V_2 , V_131 ) ;
if ( V_130 & V_132 )
return false ;
return true ;
}
static bool F_39 ( struct V_1 * V_2 )
{
T_4 V_133 ;
V_133 = F_32 ( V_2 , V_134 ) ;
if ( V_133 & V_135 )
return false ;
return true ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_136 , V_137 ) ;
F_33 ( V_2 , V_138 , V_139 ) ;
F_33 ( V_2 , V_140 , V_141 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_142 )
{
T_4 V_124 ;
T_4 V_143 ;
T_3 V_144 ;
V_124 = F_32 ( V_2 , V_125 ) ;
if ( V_124 == 0xFFFF )
return - V_126 ;
V_124 |= F_36 ( 2 ) ;
F_33 ( V_2 , V_125 , V_124 ) ;
if ( V_2 -> V_145 == V_146 ||
V_2 -> V_145 == V_147 )
return F_40 ( V_2 ) ;
V_144 = ( V_142 & 1 ) + 1 ;
V_143 = F_32 ( V_2 , V_140 ) ;
if ( V_143 == 0xFFFF )
return - V_126 ;
V_143 |= ( V_144 << V_148 ) ;
V_143 |= V_149 ;
F_33 ( V_2 , V_140 , V_143 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int * V_150 )
{
T_4 V_151 ;
if ( V_2 -> V_152 == V_153 ||
V_2 -> V_152 == V_154 ) {
if ( ! F_35 ( V_2 ) )
return - V_45 ;
goto V_155;
}
V_151 = F_32 ( V_2 , V_127 ) ;
if ( V_151 == 0xFFFF )
return - V_45 ;
if ( V_151 & V_156 )
goto V_155;
if ( V_2 -> V_145 == V_157 ||
V_2 -> V_145 == V_158 ) {
if ( ! F_35 ( V_2 ) )
return - V_45 ;
goto V_155;
}
if ( ! F_38 ( V_2 ) )
return - V_45 ;
* V_150 = V_2 -> V_145 ;
goto V_159;
V_155:
if ( ! F_39 ( V_2 ) )
return - V_45 ;
* V_150 = V_2 -> V_152 ;
V_159:
return F_41 ( V_2 , * V_150 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_1 V_160 ;
T_1 V_142 ;
if ( ( ( V_2 -> V_122 & V_161 ) >> V_162 ) < 3 )
V_2 -> V_6 |= V_163 ;
if ( V_2 -> V_152 == V_164 ||
V_2 -> V_152 == V_165 ||
V_2 -> V_152 == V_166 )
V_142 = 0x3 ;
else if ( V_2 -> V_152 == V_167 ||
V_2 -> V_152 == V_168 )
V_142 = 0x5 ;
else
return - V_45 ;
if ( V_2 -> V_152 != V_164 ) {
T_4 V_50 ;
V_50 = F_32 ( V_2 , V_169 ) ;
V_50 &= V_170 ;
F_33 ( V_2 , V_169 , V_50 ) ;
V_50 = F_32 ( V_2 , V_171 ) ;
V_50 |= V_172 ;
F_33 ( V_2 , V_171 , V_50 ) ;
} else {
T_4 V_50 ;
V_50 = F_32 ( V_2 , V_173 ) ;
V_50 &= V_174 ;
V_50 |= V_175 ;
F_33 ( V_2 , V_173 , V_50 ) ;
}
F_3 ( V_2 , V_176 , V_142 ) ;
V_160 = F_2 ( V_2 , V_176 ) ;
F_10 ( V_31 , L_25 , V_160 ) ;
V_160 &= ~ ( V_177 ) ;
V_160 |= V_177 ;
F_3 ( V_2 , V_178 , V_160 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
T_1 V_179 , V_142 ;
int V_150 = - 1 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_8 . V_55 == V_56 ) {
V_15 = F_42 ( V_2 , & V_150 ) ;
if ( V_15 < 0 )
goto V_180;
} else {
V_15 = F_43 ( V_2 ) ;
if ( V_15 < 0 )
goto V_180;
}
F_3 ( V_2 , V_181 , V_182 ) ;
F_27 ( 500 ) ;
F_13 ( V_2 , & V_36 [ V_183 ] ) ;
F_10 ( V_31 , L_26 , V_184 ) ;
V_142 = F_2 ( V_2 , V_184 ) ;
F_10 ( V_31 , L_27 , V_142 ) ;
if ( V_2 -> V_8 . V_55 == V_56 ) {
V_142 |= ( ( V_150 & 0x3 ) << 1 ) << 4 ;
} else {
V_142 |= ( V_2 -> V_152 << 1 ) << 4 ;
}
F_3 ( V_2 , V_184 , V_142 ) ;
F_13 ( V_2 , & V_36 [ V_67 ] ) ;
F_3 ( V_2 , V_69 , V_70 ) ;
V_15 = F_24 ( V_2 ) ;
if ( V_15 < 0 )
goto V_180;
V_15 = F_19 ( V_2 ) ;
if ( V_15 < 0 )
goto V_180;
F_10 ( V_31 , L_28 ) ;
F_3 ( V_2 , V_185 , V_185 ) ;
V_179 = F_2 ( V_2 , V_87 ) ;
F_10 ( V_31 , L_29 , V_179 ) ;
V_179 = F_2 ( V_2 , V_186 ) ;
if ( V_2 -> V_8 . V_55 == V_56 )
F_33 ( V_2 , V_187 , V_2 -> V_188 . V_189 ) ;
V_15 = F_16 ( V_2 ) ;
if ( V_15 < 0 )
goto V_180;
V_180:
return V_15 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_44 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_28 ( V_2 ) ;
if ( V_15 < 0 )
goto V_180;
V_15 = F_31 ( V_2 ) ;
if ( V_15 < 0 )
goto V_180;
F_3 ( V_2 , V_69 ,
V_190 ) ;
F_22 ( V_2 ) ;
F_30 ( V_2 ) ;
V_180:
return V_15 ;
}
