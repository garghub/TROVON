static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 , L_1 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
return F_5 ( V_2 , V_3 , V_6 ) ;
}
static int F_6 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
return ! ! ( F_1 ( V_11 -> V_2 , V_16 + V_13 ) &
V_15 ) ;
}
static void F_10 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
F_11 ( & V_11 -> V_17 ) ;
if ( V_6 )
V_11 -> V_18 [ V_13 ] |= V_15 ;
else
V_11 -> V_18 [ V_13 ] &= ~ V_15 ;
F_4 ( V_11 -> V_2 , V_19 + V_13 ,
V_11 -> V_18 [ V_13 ] ) ;
F_12 ( & V_11 -> V_17 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
int V_4 ;
F_11 ( & V_11 -> V_17 ) ;
V_11 -> V_20 [ V_13 ] &= ~ V_15 ;
V_4 = F_4 ( V_11 -> V_2 , V_21 + V_13 ,
V_11 -> V_20 [ V_13 ] ) ;
F_12 ( & V_11 -> V_17 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
struct V_10 * V_11 = F_7 ( V_8 , struct V_10 , V_12 ) ;
unsigned int V_13 = F_8 ( V_11 -> V_14 [ V_9 ] ) ;
unsigned int V_15 = F_9 ( V_11 -> V_14 [ V_9 ] ) ;
int V_4 ;
F_11 ( & V_11 -> V_17 ) ;
V_11 -> V_20 [ V_13 ] |= V_15 ;
if ( V_6 )
V_11 -> V_18 [ V_13 ] |= V_15 ;
else
V_11 -> V_18 [ V_13 ] &= ~ V_15 ;
V_4 = F_4 ( V_11 -> V_2 , V_19 + V_13 ,
V_11 -> V_18 [ V_13 ] ) ;
V_4 |= F_4 ( V_11 -> V_2 , V_21 + V_13 ,
V_11 -> V_20 [ V_13 ] ) ;
F_12 ( & V_11 -> V_17 ) ;
return V_4 ;
}
static int T_2 F_15 ( struct V_10 * V_11 ,
const struct V_22 * V_23 )
{
bool V_24 [ V_25 ] ;
int V_26 = 0 ;
int V_27 ;
memset ( V_24 , false , sizeof( V_24 ) ) ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ )
if ( V_23 -> V_28 & ( 1 << V_27 ) )
V_24 [ V_27 ] = true ;
for ( V_27 = 0 ; V_27 < V_11 -> V_29 ; V_27 ++ )
V_24 [ V_11 -> V_30 [ V_27 ] . V_31 - V_32 ] = true ;
if ( V_11 -> V_33 & V_34 )
V_24 [ 4 ] = true ;
if ( V_11 -> V_33 & V_35 )
V_24 [ 12 ] = true ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ )
if ( ! V_24 [ V_27 ] )
V_11 -> V_14 [ V_26 ++ ] = V_27 ;
return V_26 ;
}
static int T_2 F_16 ( struct V_10 * V_11 )
{
struct V_36 * V_5 = & V_11 -> V_2 -> V_5 ;
const struct V_22 * V_23 = V_5 -> V_37 ;
const struct V_38 * V_39 = V_23 -> V_39 ;
int V_27 , error ;
if ( ! V_39 )
return 0 ;
V_11 -> V_12 . V_40 = F_15 ( V_11 , V_23 ) ;
if ( V_11 -> V_12 . V_40 == 0 ) {
F_17 ( V_5 , L_2 ) ;
return 0 ;
}
V_11 -> V_41 = true ;
V_11 -> V_12 . V_42 = F_13 ;
V_11 -> V_12 . V_43 = F_14 ;
V_11 -> V_12 . V_44 = F_6 ;
V_11 -> V_12 . V_45 = F_10 ;
V_11 -> V_12 . V_46 = 1 ;
V_11 -> V_12 . V_47 = V_39 -> V_48 ;
V_11 -> V_12 . V_49 = V_11 -> V_2 -> V_50 ;
V_11 -> V_12 . V_51 = V_52 ;
F_18 ( & V_11 -> V_17 ) ;
error = F_19 ( & V_11 -> V_12 ) ;
if ( error ) {
F_3 ( V_5 , L_3 , error ) ;
return error ;
}
for ( V_27 = 0 ; V_27 <= F_8 ( V_25 ) ; V_27 ++ ) {
V_11 -> V_18 [ V_27 ] = F_1 ( V_11 -> V_2 ,
V_19 + V_27 ) ;
V_11 -> V_20 [ V_27 ] = F_1 ( V_11 -> V_2 ,
V_21 + V_27 ) ;
}
if ( V_39 -> V_53 ) {
error = V_39 -> V_53 ( V_11 -> V_2 ,
V_11 -> V_12 . V_47 , V_11 -> V_12 . V_40 ,
V_39 -> V_54 ) ;
if ( error )
F_20 ( V_5 , L_4 , error ) ;
}
return 0 ;
}
static void T_3 F_21 ( struct V_10 * V_11 )
{
struct V_36 * V_5 = & V_11 -> V_2 -> V_5 ;
const struct V_22 * V_23 = V_5 -> V_37 ;
const struct V_38 * V_39 = V_23 -> V_39 ;
int error ;
if ( ! V_11 -> V_41 )
return;
if ( V_39 -> V_55 ) {
error = V_39 -> V_55 ( V_11 -> V_2 ,
V_11 -> V_12 . V_47 , V_11 -> V_12 . V_40 ,
V_39 -> V_54 ) ;
if ( error )
F_20 ( V_5 , L_5 , error ) ;
}
error = F_22 ( & V_11 -> V_12 ) ;
if ( error )
F_20 ( V_5 , L_6 , error ) ;
}
static inline int F_16 ( struct V_10 * V_11 )
{
return 0 ;
}
static inline void F_21 ( struct V_10 * V_11 )
{
}
static void F_23 ( struct V_10 * V_11 ,
int V_56 , int V_57 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_11 -> V_29 ; V_27 ++ ) {
if ( V_57 == V_11 -> V_30 [ V_27 ] . V_31 ) {
F_24 ( V_11 -> V_58 ,
V_11 -> V_30 [ V_27 ] . V_59 ,
V_56 & V_60 ) ;
break;
}
}
}
static void F_25 ( struct V_10 * V_11 , int V_61 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_61 ; V_27 ++ ) {
int V_56 = F_1 ( V_11 -> V_2 , V_62 + V_27 ) ;
int V_57 = V_56 & V_63 ;
if ( V_57 >= V_32 &&
V_57 <= V_64 ) {
F_23 ( V_11 , V_56 , V_57 ) ;
} else {
F_26 ( V_11 -> V_58 ,
V_11 -> V_65 [ V_57 - 1 ] ,
V_56 & V_60 ) ;
}
}
}
static T_4 F_27 ( int V_66 , void * V_67 )
{
struct V_10 * V_11 = V_67 ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_68 , V_61 ;
V_68 = F_1 ( V_2 , V_69 ) ;
if ( V_68 & V_70 )
F_3 ( & V_2 -> V_5 , L_7 ) ;
if ( V_68 & V_71 ) {
V_61 = F_1 ( V_2 , V_72 ) & V_73 ;
if ( V_61 ) {
F_25 ( V_11 , V_61 ) ;
F_28 ( V_11 -> V_58 ) ;
}
}
F_4 ( V_2 , V_69 , V_68 ) ;
return V_74 ;
}
static int T_2 F_29 ( struct V_10 * V_11 , unsigned short V_56 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_75 ; V_27 ++ )
if ( V_56 == V_11 -> V_65 [ V_27 ] )
return ( V_27 + 1 ) | V_60 ;
F_3 ( & V_11 -> V_2 -> V_5 , L_8 ) ;
return - V_76 ;
}
static int T_2 F_30 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
const struct V_22 * V_23 =
V_2 -> V_5 . V_37 ;
int V_27 , V_4 ;
unsigned char V_77 = 0 , V_78 = 0 , V_79 = 0 ;
unsigned char V_80 = 0 ;
V_4 = F_4 ( V_2 , V_81 ,
V_23 -> V_28 & 0xFF ) ;
V_4 |= F_4 ( V_2 , V_82 ,
( V_23 -> V_28 >> 8 ) & 0xFF ) ;
V_4 |= F_4 ( V_2 , V_83 ,
( V_23 -> V_28 >> 16 ) & 0xFF ) ;
if ( V_23 -> V_84 ) {
V_4 |= F_4 ( V_2 , V_85 ,
V_23 -> V_86 ) ;
V_4 |= F_4 ( V_2 , V_87 ,
V_23 -> V_88 ) ;
V_4 |= F_4 ( V_2 , V_89 ,
V_23 -> V_90 & V_91 ) ;
V_4 |= F_4 ( V_2 , V_92 , V_93 ) ;
}
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ )
V_4 |= F_1 ( V_2 , V_62 + V_27 ) ;
for ( V_27 = 0 ; V_27 < V_23 -> V_29 ; V_27 ++ ) {
unsigned short V_31 = V_23 -> V_30 [ V_27 ] . V_31 ;
if ( V_31 <= V_95 ) {
V_77 |= ( 1 << ( V_31 - V_96 ) ) ;
} else {
V_78 |=
( ( 1 << ( V_31 - V_97 ) ) & 0xFF ) ;
V_79 |=
( ( 1 << ( V_31 - V_97 ) ) >> 8 ) ;
}
}
if ( V_23 -> V_29 ) {
V_4 |= F_4 ( V_2 , V_98 , V_77 ) ;
V_4 |= F_4 ( V_2 , V_99 , V_78 ) ;
V_4 |= F_4 ( V_2 , V_100 , V_79 ) ;
}
if ( V_23 -> V_101 & V_23 -> V_102 &
V_23 -> V_103 & V_23 -> V_104 )
F_20 ( & V_2 -> V_5 , L_9 ) ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ ) {
unsigned V_6 = 0 ;
if ( V_23 -> V_103 & ( 1 << V_27 ) )
V_6 = 0 ;
else if ( V_23 -> V_104 & ( 1 << V_27 ) )
V_6 = 1 ;
else if ( V_23 -> V_102 & ( 1 << V_27 ) )
V_6 = 2 ;
else if ( V_23 -> V_101 & ( 1 << V_27 ) )
V_6 = 3 ;
V_80 |= V_6 << ( 2 * ( V_27 & 0x3 ) ) ;
if ( ( V_27 & 0x3 ) == 0x3 || V_27 == V_25 - 1 ) {
V_4 |= F_4 ( V_2 ,
V_105 + ( V_27 >> 2 ) ,
V_80 ) ;
V_80 = 0 ;
}
}
if ( V_23 -> V_106 && V_23 -> V_107 && V_23 -> V_108 ) {
V_4 |= F_4 ( V_2 , V_109 ,
F_29 ( V_11 ,
V_23 -> V_106 ) ) ;
V_4 |= F_4 ( V_2 , V_110 ,
F_29 ( V_11 ,
V_23 -> V_107 ) ) ;
V_4 |= F_4 ( V_2 , V_111 ,
F_29 ( V_11 ,
V_23 -> V_108 ) ) ;
V_11 -> V_33 |= V_34 ;
}
if ( V_23 -> V_112 && V_23 -> V_113 ) {
V_4 |= F_4 ( V_2 , V_114 ,
F_29 ( V_11 ,
V_23 -> V_112 ) ) ;
V_4 |= F_4 ( V_2 , V_115 ,
F_29 ( V_11 ,
V_23 -> V_113 ) ) ;
V_11 -> V_33 |= V_35 ;
}
if ( V_11 -> V_33 ) {
V_4 |= F_4 ( V_2 , V_116 ,
V_23 -> V_117 ) ;
V_4 |= F_4 ( V_2 , V_118 ,
V_11 -> V_33 ) ;
}
for ( V_27 = 0 ; V_27 <= F_8 ( V_25 ) ; V_27 ++ )
V_4 |= F_4 ( V_2 , V_119 + V_27 ,
V_23 -> V_120 >> ( V_27 * 8 ) ) ;
V_4 |= F_4 ( V_2 , V_121 ,
V_23 -> V_122 & V_123 ) ;
V_4 |= F_4 ( V_2 , V_69 , V_124 |
V_125 | V_70 | V_126 |
V_127 | V_71 ) ;
V_4 |= F_4 ( V_2 , V_128 ,
V_129 | V_130 | F_31 ( 3 ) ) ;
V_4 |= F_4 ( V_2 , V_131 ,
V_132 | V_133 | V_134 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 , L_10 ) ;
return V_4 ;
}
return 0 ;
}
static void T_2 F_32 ( struct V_10 * V_11 )
{
int V_135 = F_1 ( V_11 -> V_2 , V_16 ) ;
int V_136 = F_1 ( V_11 -> V_2 , V_137 ) ;
int V_138 = F_1 ( V_11 -> V_2 , V_139 ) ;
int V_140 , V_141 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_11 -> V_29 ; V_27 ++ ) {
unsigned short V_31 = V_11 -> V_30 [ V_27 ] . V_31 ;
if ( V_31 <= V_95 ) {
V_140 = V_135 ;
V_141 = V_31 - V_96 ;
} else if ( ( V_31 - V_97 ) < 8 ) {
V_140 = V_136 ;
V_141 = V_31 - V_97 ;
} else {
V_140 = V_138 ;
V_141 = V_31 - V_97 - 8 ;
}
if ( V_140 < 0 ) {
F_3 ( & V_11 -> V_2 -> V_5 ,
L_11
L_12 , V_31 ) ;
V_140 = 0 ;
}
F_24 ( V_11 -> V_58 ,
V_11 -> V_30 [ V_27 ] . V_59 ,
! ( V_140 & ( 1 << V_141 ) ) ) ;
}
F_28 ( V_11 -> V_58 ) ;
}
static int T_2 F_33 ( struct V_1 * V_2 ,
const struct V_142 * V_143 )
{
struct V_10 * V_11 ;
const struct V_22 * V_23 ;
struct V_144 * V_58 ;
unsigned int V_145 ;
int V_4 , V_27 ;
int error ;
if ( ! F_34 ( V_2 -> V_146 ,
V_147 ) ) {
F_3 ( & V_2 -> V_5 , L_13 ) ;
return - V_148 ;
}
V_23 = V_2 -> V_5 . V_37 ;
if ( ! V_23 ) {
F_3 ( & V_2 -> V_5 , L_14 ) ;
return - V_76 ;
}
if ( ! ( ( V_23 -> V_28 & 0xFF ) &&
( V_23 -> V_28 >> 8 ) ) || ! V_23 -> V_149 ) {
F_3 ( & V_2 -> V_5 , L_15 ) ;
return - V_76 ;
}
if ( V_23 -> V_150 != V_75 ) {
F_3 ( & V_2 -> V_5 , L_16 ) ;
return - V_76 ;
}
if ( ! V_23 -> V_30 && V_23 -> V_29 ) {
F_3 ( & V_2 -> V_5 , L_17 ) ;
return - V_76 ;
}
if ( V_23 -> V_29 > V_151 ) {
F_3 ( & V_2 -> V_5 , L_18 ) ;
return - V_76 ;
}
for ( V_27 = 0 ; V_27 < V_23 -> V_29 ; V_27 ++ ) {
unsigned short V_31 = V_23 -> V_30 [ V_27 ] . V_31 ;
if ( V_31 < V_32 || V_31 > V_64 ) {
F_3 ( & V_2 -> V_5 , L_19 ) ;
return - V_76 ;
}
if ( ( 1 << ( V_31 - V_96 ) ) &
V_23 -> V_28 ) {
F_3 ( & V_2 -> V_5 , L_20 ) ;
return - V_76 ;
}
}
if ( ! V_2 -> V_66 ) {
F_3 ( & V_2 -> V_5 , L_21 ) ;
return - V_76 ;
}
V_11 = F_35 ( sizeof( * V_11 ) , V_152 ) ;
V_58 = F_36 () ;
if ( ! V_11 || ! V_58 ) {
error = - V_153 ;
goto V_154;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_58 = V_58 ;
V_4 = F_1 ( V_2 , V_155 ) ;
if ( V_4 < 0 ) {
error = V_4 ;
goto V_154;
}
V_145 = ( T_1 ) V_4 & V_156 ;
V_58 -> V_50 = V_2 -> V_50 ;
V_58 -> V_157 = L_22 ;
V_58 -> V_5 . V_158 = & V_2 -> V_5 ;
F_37 ( V_58 , V_11 ) ;
V_58 -> V_143 . V_159 = V_160 ;
V_58 -> V_143 . V_161 = 0x0001 ;
V_58 -> V_143 . V_162 = 0x0001 ;
V_58 -> V_143 . V_163 = V_145 ;
V_58 -> V_164 = sizeof( V_11 -> V_65 [ 0 ] ) ;
V_58 -> V_165 = V_23 -> V_150 ;
V_58 -> V_65 = V_11 -> V_65 ;
memcpy ( V_11 -> V_65 , V_23 -> V_149 ,
V_23 -> V_150 * V_58 -> V_164 ) ;
V_11 -> V_30 = V_23 -> V_30 ;
V_11 -> V_29 = V_23 -> V_29 ;
F_38 ( V_166 , V_58 -> V_167 ) ;
if ( V_23 -> V_168 )
F_38 ( V_169 , V_58 -> V_167 ) ;
for ( V_27 = 0 ; V_27 < V_58 -> V_165 ; V_27 ++ )
F_38 ( V_11 -> V_65 [ V_27 ] & V_170 , V_58 -> V_171 ) ;
F_39 ( V_172 , V_58 -> V_171 ) ;
if ( V_11 -> V_29 )
F_38 ( V_173 , V_58 -> V_167 ) ;
for ( V_27 = 0 ; V_27 < V_11 -> V_29 ; V_27 ++ )
F_38 ( V_11 -> V_30 [ V_27 ] . V_59 , V_58 -> V_174 ) ;
error = F_40 ( V_58 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 , L_23 ) ;
goto V_154;
}
error = F_41 ( V_2 -> V_66 , NULL , F_27 ,
V_175 | V_176 ,
V_2 -> V_5 . V_177 -> V_50 , V_11 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 , L_24 , V_2 -> V_66 ) ;
goto V_178;
}
error = F_30 ( V_11 ) ;
if ( error )
goto V_179;
if ( V_11 -> V_29 )
F_32 ( V_11 ) ;
error = F_16 ( V_11 ) ;
if ( error )
goto V_179;
F_42 ( & V_2 -> V_5 , 1 ) ;
F_43 ( V_2 , V_11 ) ;
F_17 ( & V_2 -> V_5 , L_25 , V_145 , V_2 -> V_66 ) ;
return 0 ;
V_179:
F_44 ( V_2 -> V_66 , V_11 ) ;
V_178:
F_45 ( V_58 ) ;
V_58 = NULL ;
V_154:
F_46 ( V_58 ) ;
F_47 ( V_11 ) ;
return error ;
}
static int T_3 F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_49 ( V_2 ) ;
F_4 ( V_2 , V_128 , 0 ) ;
F_44 ( V_2 -> V_66 , V_11 ) ;
F_45 ( V_11 -> V_58 ) ;
F_21 ( V_11 ) ;
F_47 ( V_11 ) ;
return 0 ;
}
static int F_50 ( struct V_36 * V_5 )
{
struct V_10 * V_11 = F_51 ( V_5 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_52 ( V_2 -> V_66 ) ;
if ( F_53 ( & V_2 -> V_5 ) )
F_54 ( V_2 -> V_66 ) ;
return 0 ;
}
static int F_55 ( struct V_36 * V_5 )
{
struct V_10 * V_11 = F_51 ( V_5 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( F_53 ( & V_2 -> V_5 ) )
F_56 ( V_2 -> V_66 ) ;
F_57 ( V_2 -> V_66 ) ;
return 0 ;
}
static int T_5 F_58 ( void )
{
return F_59 ( & V_180 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_180 ) ;
}
