static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 |= V_3 ;
F_3 ( V_2 , V_5 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = sscanf ( V_2 -> V_7 . V_8 + 4 , L_1 ,
& V_2 -> V_7 . V_9 [ 0 ] , & V_2 -> V_7 . V_9 [ 1 ] ,
& V_2 -> V_7 . V_9 [ 2 ] , & V_2 -> V_7 . V_9 [ 3 ] ,
& V_2 -> V_7 . V_9 [ 4 ] ) ;
if ( V_6 != 5 ) {
F_5 ( L_2 ) ;
memset ( V_2 -> V_7 . V_9 , 0 , sizeof( V_2 -> V_7 . V_9 ) ) ;
return;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_10 V_11 ;
F_7 ( V_2 , V_2 -> V_12 , & V_11 , sizeof( V_11 ) ,
false ) ;
strncpy ( V_2 -> V_7 . V_8 , V_11 . V_13 ,
sizeof( V_2 -> V_7 . V_8 ) ) ;
V_2 -> V_7 . V_8 [ sizeof( V_2 -> V_7 . V_8 ) - 1 ] = '\0' ;
F_4 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_14 ,
T_2 V_15 , T_1 V_16 )
{
struct V_17 V_18 ;
int V_19 , V_20 , V_21 ;
T_3 * V_22 , * V_23 ;
F_9 ( V_24 , L_3 ) ;
F_9 ( V_24 , L_4 ,
V_15 , V_25 ) ;
if ( ( V_15 % 4 ) != 0 ) {
F_10 ( L_5 ) ;
return - V_26 ;
}
V_23 = F_11 ( V_25 , V_27 ) ;
if ( ! V_23 ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
memcpy ( & V_18 , & V_29 [ V_30 ] , sizeof( V_18 ) ) ;
V_18 . V_31 . V_32 = V_16 ;
F_12 ( V_2 , & V_18 ) ;
V_20 = 0 ;
V_21 = V_29 [ V_30 ] . V_31 . V_33 ;
while ( V_20 < V_15 / V_25 ) {
V_19 = V_16 + ( V_20 + 2 ) * V_25 ;
if ( V_19 > V_21 ) {
V_19 = V_16 + V_20 * V_25 ;
V_21 = V_20 * V_25 +
V_29 [ V_30 ] . V_31 . V_33 ;
V_18 . V_31 . V_32 = V_19 ;
F_12 ( V_2 , & V_18 ) ;
}
V_19 = V_16 + V_20 * V_25 ;
V_22 = V_14 + V_20 * V_25 ;
memcpy ( V_23 , V_22 , V_25 ) ;
F_9 ( V_24 , L_7 ,
V_22 , V_19 ) ;
F_13 ( V_2 , V_19 , V_23 , V_25 , false ) ;
V_20 ++ ;
}
V_19 = V_16 + V_20 * V_25 ;
V_22 = V_14 + V_20 * V_25 ;
memcpy ( V_23 , V_22 , V_15 % V_25 ) ;
F_9 ( V_24 , L_8 ,
V_15 % V_25 , V_22 , V_19 ) ;
F_13 ( V_2 , V_19 , V_23 , V_15 % V_25 , false ) ;
F_14 ( V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_34 , V_19 , V_35 ;
int V_6 = 0 ;
T_3 * V_36 ;
V_36 = V_2 -> V_36 ;
V_34 = F_16 ( ( V_37 * ) V_36 ) ;
V_36 += sizeof( T_1 ) ;
F_9 ( V_24 , L_9 , V_34 ) ;
while ( V_34 -- ) {
V_19 = F_16 ( ( V_37 * ) V_36 ) ;
V_36 += sizeof( T_1 ) ;
V_35 = F_16 ( ( V_37 * ) V_36 ) ;
V_36 += sizeof( T_1 ) ;
if ( V_35 > 300000 ) {
F_17 ( L_10 , V_35 ) ;
return - V_38 ;
}
F_9 ( V_24 , L_11 ,
V_34 , V_19 , V_35 ) ;
V_6 = F_8 ( V_2 , V_36 , V_35 , V_19 ) ;
if ( V_6 != 0 )
break;
V_36 += V_35 ;
}
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 V_39 , V_40 ;
int V_41 ;
T_1 V_42 , V_43 ;
T_3 * V_44 , * V_45 ;
if ( V_2 -> V_46 == NULL )
return - V_47 ;
if ( V_2 -> V_7 . V_48 == V_49 ) {
struct V_50 * V_46 = (struct V_50 * ) V_2 -> V_46 ;
if ( V_2 -> V_39 == sizeof( struct V_50 ) ) {
if ( V_46 -> V_51 . V_52 )
V_2 -> V_53 = true ;
} else {
F_10 ( L_12 ,
V_2 -> V_39 ,
sizeof( struct V_50 ) ) ;
F_14 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
V_2 -> V_39 = 0 ;
return - V_54 ;
}
V_39 = sizeof( V_46 -> V_46 ) ;
V_44 = ( T_3 * ) V_46 -> V_46 ;
} else {
struct V_55 * V_46 =
(struct V_55 * ) V_2 -> V_46 ;
if ( V_2 -> V_39 == sizeof( struct V_55 ) ||
V_2 -> V_39 == V_56 ) {
if ( V_2 -> V_57 != V_58 &&
V_46 -> V_51 . V_52 )
V_2 -> V_53 = true ;
}
if ( V_2 -> V_39 != sizeof( struct V_55 ) &&
( V_2 -> V_39 != V_56 ||
V_2 -> V_53 ) ) {
F_10 ( L_12 ,
V_2 -> V_39 , sizeof( struct V_55 ) ) ;
F_14 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
V_2 -> V_39 = 0 ;
return - V_54 ;
}
V_39 = sizeof( V_46 -> V_46 ) ;
V_44 = ( T_3 * ) V_46 -> V_46 ;
}
V_44 [ 11 ] = V_2 -> V_59 [ 0 ] ;
V_44 [ 10 ] = V_2 -> V_59 [ 1 ] ;
V_44 [ 6 ] = V_2 -> V_59 [ 2 ] ;
V_44 [ 5 ] = V_2 -> V_59 [ 3 ] ;
V_44 [ 4 ] = V_2 -> V_59 [ 4 ] ;
V_44 [ 3 ] = V_2 -> V_59 [ 5 ] ;
while ( V_44 [ 0 ] ) {
V_40 = V_44 [ 0 ] ;
V_42 = ( V_44 [ 1 ] & 0xfe ) | ( ( T_1 ) ( V_44 [ 2 ] << 8 ) ) ;
V_42 += V_60 ;
V_44 += 3 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
V_43 = ( V_44 [ 0 ] | ( V_44 [ 1 ] << 8 )
| ( V_44 [ 2 ] << 16 ) | ( V_44 [ 3 ] << 24 ) ) ;
F_9 ( V_24 ,
L_13 ,
V_42 , V_43 ) ;
F_3 ( V_2 , V_42 , V_43 ) ;
V_44 += 4 ;
V_42 += 4 ;
}
}
V_44 = ( T_3 * ) V_2 -> V_46 +
F_19 ( V_44 - ( T_3 * ) V_2 -> V_46 + 7 , 4 ) ;
V_39 -= V_44 - ( T_3 * ) V_2 -> V_46 ;
F_12 ( V_2 , & V_29 [ V_61 ] ) ;
V_45 = F_20 ( V_44 , V_39 , V_27 ) ;
if ( ! V_45 )
return - V_28 ;
F_13 ( V_2 , V_62 , V_45 , V_39 , false ) ;
F_14 ( V_45 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_3 ( V_2 , V_63 ,
V_64 & ~ ( V_65 ) ) ;
F_3 ( V_2 , V_66 , V_67 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
T_1 V_69 ;
F_3 ( V_2 , V_70 , V_71 ) ;
V_68 = V_72 + F_24 ( V_73 ) ;
while ( 1 ) {
V_69 = F_2 ( V_2 , V_70 ) ;
F_9 ( V_24 , L_14 , V_69 ) ;
if ( ( V_69 & V_71 ) == 0 )
break;
if ( F_25 ( V_72 , V_68 ) ) {
F_10 ( L_15 ) ;
return - 1 ;
}
F_26 ( V_74 ) ;
}
F_3 ( V_2 , V_75 , 0x0 ) ;
F_3 ( V_2 , V_76 , 0xffff ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_77 , V_6 ;
T_1 V_78 , V_79 ;
F_1 ( V_2 , V_80 ) ;
V_78 = F_2 ( V_2 , V_81 ) ;
F_9 ( V_24 , L_16 , V_78 ) ;
if ( V_78 != V_2 -> V_7 . V_48 ) {
F_10 ( L_17 ) ;
return - V_26 ;
}
V_77 = 0 ;
while ( V_77 ++ < V_82 ) {
F_26 ( V_83 ) ;
V_79 = F_2 ( V_2 , V_84 ) ;
if ( V_79 == 0xffffffff ) {
F_10 ( L_18
L_19 ) ;
return - V_26 ;
}
else if ( V_79 & V_85 ) {
F_3 ( V_2 , V_86 ,
V_85 ) ;
break;
}
}
if ( V_77 > V_82 ) {
F_10 ( L_20
L_21 ) ;
return - V_26 ;
}
V_2 -> V_12 = F_2 ( V_2 , V_87 ) ;
V_2 -> V_88 = F_2 ( V_2 , V_89 ) ;
F_12 ( V_2 , & V_29 [ V_61 ] ) ;
F_9 ( V_90 , L_22 ,
V_2 -> V_12 , V_2 -> V_88 ) ;
F_6 ( V_2 ) ;
V_2 -> V_91 = V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 ;
if ( V_2 -> V_57 == V_58 )
V_2 -> V_91 |= V_102 ;
else
V_2 -> V_91 |= V_103 ;
V_6 = F_28 ( V_2 ) ;
if ( V_6 < 0 ) {
F_10 ( L_23 ) ;
return V_6 ;
}
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_104 ;
V_104 = F_31 ( V_2 , V_105 ) ;
V_104 &= ~ V_106 ;
F_32 ( V_2 , V_105 , V_104 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_107 ;
V_107 = F_31 ( V_2 , V_108 ) ;
V_107 = ( V_107 & V_109 ) >> V_110 ;
V_2 -> V_111 = ( V_112 ) V_107 ;
if ( ( ( V_2 -> V_111 & V_113 ) >> V_114 ) < 3 )
V_2 -> V_115 |= V_116 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_4 V_117 ;
V_117 = F_31 ( V_2 , V_118 ) ;
if ( V_117 == 0xFFFF )
return - V_119 ;
V_117 |= ( F_35 ( 3 ) | F_35 ( 5 ) | F_35 ( 6 ) ) ;
F_32 ( V_2 , V_118 , V_117 ) ;
F_32 ( V_2 , V_120 ,
V_121 | V_122 ) ;
F_36 ( 15 ) ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_2 )
{
T_4 V_123 ;
V_123 = F_31 ( V_2 , V_124 ) ;
if ( V_123 & V_125 )
return false ;
return true ;
}
static bool F_38 ( struct V_1 * V_2 )
{
T_4 V_126 ;
V_126 = F_31 ( V_2 , V_127 ) ;
if ( V_126 & V_128 )
return false ;
return true ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_32 ( V_2 , V_129 , V_130 ) ;
F_32 ( V_2 , V_131 , V_132 ) ;
F_32 ( V_2 , V_133 , V_134 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_135 )
{
T_4 V_117 ;
T_4 V_136 ;
T_3 V_137 ;
V_117 = F_31 ( V_2 , V_118 ) ;
if ( V_117 == 0xFFFF )
return - V_119 ;
V_117 |= F_35 ( 2 ) ;
F_32 ( V_2 , V_118 , V_117 ) ;
if ( V_2 -> V_138 == V_139 ||
V_2 -> V_138 == V_140 )
return F_39 ( V_2 ) ;
V_137 = ( V_135 & 1 ) + 1 ;
V_136 = F_31 ( V_2 , V_133 ) ;
if ( V_136 == 0xFFFF )
return - V_119 ;
V_136 |= ( V_137 << V_141 ) ;
V_136 |= V_142 ;
F_32 ( V_2 , V_133 , V_136 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int * V_143 )
{
T_4 V_144 ;
if ( V_2 -> V_145 == V_146 ||
V_2 -> V_145 == V_147 ) {
if ( ! F_34 ( V_2 ) )
return - V_38 ;
goto V_148;
}
V_144 = F_31 ( V_2 , V_120 ) ;
if ( V_144 == 0xFFFF )
return - V_38 ;
if ( V_144 & V_149 )
goto V_148;
if ( V_2 -> V_138 == V_150 ||
V_2 -> V_138 == V_151 ) {
if ( ! F_34 ( V_2 ) )
return - V_38 ;
goto V_148;
}
if ( ! F_37 ( V_2 ) )
return - V_38 ;
* V_143 = V_2 -> V_138 ;
goto V_152;
V_148:
if ( ! F_38 ( V_2 ) )
return - V_38 ;
* V_143 = V_2 -> V_145 ;
V_152:
return F_40 ( V_2 , * V_143 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_1 V_153 ;
T_1 V_135 ;
F_33 ( V_2 ) ;
if ( V_2 -> V_145 == V_154 ||
V_2 -> V_145 == V_155 ||
V_2 -> V_145 == V_156 )
V_135 = 0x3 ;
else if ( V_2 -> V_145 == V_157 ||
V_2 -> V_145 == V_158 )
V_135 = 0x5 ;
else
return - V_38 ;
if ( V_2 -> V_145 != V_154 ) {
T_4 V_43 ;
V_43 = F_31 ( V_2 , V_159 ) ;
V_43 &= V_160 ;
F_32 ( V_2 , V_159 , V_43 ) ;
V_43 = F_31 ( V_2 , V_161 ) ;
V_43 |= V_162 ;
F_32 ( V_2 , V_161 , V_43 ) ;
} else {
T_4 V_43 ;
V_43 = F_31 ( V_2 , V_163 ) ;
V_43 &= V_164 ;
V_43 |= V_165 ;
F_32 ( V_2 , V_163 , V_43 ) ;
}
F_3 ( V_2 , V_166 , V_135 ) ;
V_153 = F_2 ( V_2 , V_166 ) ;
F_9 ( V_24 , L_24 , V_153 ) ;
V_153 &= ~ ( V_167 ) ;
V_153 |= V_167 ;
F_3 ( V_2 , V_168 , V_153 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_169 , V_135 ;
int V_143 = - 1 ;
if ( V_2 -> V_7 . V_48 == V_49 ) {
V_6 = F_41 ( V_2 , & V_143 ) ;
if ( V_6 < 0 )
goto V_170;
} else {
V_6 = F_42 ( V_2 ) ;
if ( V_6 < 0 )
goto V_170;
}
F_3 ( V_2 , V_171 , V_172 ) ;
F_26 ( 500 ) ;
F_12 ( V_2 , & V_29 [ V_173 ] ) ;
F_9 ( V_24 , L_25 , V_174 ) ;
V_135 = F_2 ( V_2 , V_174 ) ;
F_9 ( V_24 , L_26 , V_135 ) ;
if ( V_2 -> V_7 . V_48 == V_49 ) {
V_135 |= ( ( V_143 & 0x3 ) << 1 ) << 4 ;
} else {
V_135 |= ( V_2 -> V_145 << 1 ) << 4 ;
}
F_3 ( V_2 , V_174 , V_135 ) ;
F_12 ( V_2 , & V_29 [ V_61 ] ) ;
F_3 ( V_2 , V_63 , V_64 ) ;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
goto V_170;
V_6 = F_18 ( V_2 ) ;
if ( V_6 < 0 )
goto V_170;
F_9 ( V_24 , L_27 ) ;
F_3 ( V_2 , V_175 , V_175 ) ;
V_169 = F_2 ( V_2 , V_81 ) ;
F_9 ( V_24 , L_28 , V_169 ) ;
V_169 = F_2 ( V_2 , V_176 ) ;
if ( V_2 -> V_7 . V_48 == V_49 )
F_32 ( V_2 , V_177 , V_2 -> V_178 . V_179 ) ;
V_6 = F_15 ( V_2 ) ;
if ( V_6 < 0 )
goto V_170;
V_170:
return V_6 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_43 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_27 ( V_2 ) ;
if ( V_6 < 0 )
goto V_170;
V_6 = F_30 ( V_2 ) ;
if ( V_6 < 0 )
goto V_170;
F_3 ( V_2 , V_63 ,
V_180 ) ;
F_21 ( V_2 ) ;
F_45 ( V_2 ) ;
F_29 ( V_2 ) ;
V_170:
return V_6 ;
}
