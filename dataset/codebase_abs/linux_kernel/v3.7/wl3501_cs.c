static int F_1 ( int V_1 , int V_2 )
{
int V_3 , V_4 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ )
if ( V_1 == V_5 [ V_3 ] . V_1 ) {
V_4 = V_2 >= V_5 [ V_3 ] . V_6 &&
V_2 <= V_5 [ V_3 ] . V_7 ;
break;
}
return V_4 ;
}
static int F_3 ( int V_1 )
{
int V_3 , V_4 = 1 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ )
if ( V_1 == V_5 [ V_3 ] . V_1 ) {
V_4 = V_5 [ V_3 ] . V_8 ;
break;
}
return V_4 ;
}
static void F_4 ( enum V_9 V_10 ,
struct V_11 * V_12 ,
void * V_13 , int V_14 )
{
V_12 -> V_10 = V_10 ;
V_12 -> V_14 = V_14 ;
memcpy ( V_12 -> V_15 , V_13 , V_14 ) ;
}
static void F_5 ( struct V_11 * V_16 ,
struct V_11 * V_17 )
{
F_4 ( V_17 -> V_10 , V_16 , V_17 -> V_15 , V_17 -> V_14 ) ;
}
static inline void F_6 ( struct V_18 * V_19 , T_1 V_20 )
{
F_7 ( V_20 , V_19 -> V_21 + V_22 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
int V_21 = V_19 -> V_21 ;
F_7 ( V_23 , V_21 + V_22 ) ;
F_7 ( 0x00 , V_21 + V_24 ) ;
F_7 ( 0x40 , V_21 + V_25 ) ;
F_9 ( 100 ) ;
V_19 -> V_26 [ 0 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_26 [ 1 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_26 [ 2 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_26 [ 3 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_26 [ 4 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_26 [ 5 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_1 = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
F_7 ( V_28 , V_21 + V_22 ) ;
F_7 ( 0x04 , V_21 + V_24 ) ;
F_7 ( 0x40 , V_21 + V_25 ) ;
F_9 ( 100 ) ;
V_19 -> V_29 [ 0 ] = F_10 ( V_21 + V_27 ) ;
F_9 ( 100 ) ;
V_19 -> V_29 [ 1 ] = F_10 ( V_21 + V_27 ) ;
F_6 ( V_19 , V_30 ) ;
return V_19 -> V_26 [ 0 ] == 0x00 && V_19 -> V_26 [ 1 ] == 0x60 ;
}
static void F_11 ( struct V_18 * V_19 , T_2 V_31 , void * V_32 ,
int V_33 )
{
F_6 ( V_19 , ( V_31 & 0x8000 ) ? V_34 :
V_30 ) ;
F_7 ( V_31 & 0xff , V_19 -> V_21 + V_24 ) ;
F_7 ( ( ( V_31 >> 8 ) & 0x7f ) , V_19 -> V_21 + V_25 ) ;
F_12 ( V_19 -> V_21 + V_27 , V_32 , V_33 ) ;
}
static void F_13 ( struct V_18 * V_19 , T_2 V_32 , void * V_31 ,
int V_33 )
{
F_6 ( V_19 , ( V_32 & 0x8000 ) ? V_34 :
V_30 ) ;
F_7 ( V_32 & 0xff , V_19 -> V_21 + V_24 ) ;
F_7 ( ( V_32 >> 8 ) & 0x7f , V_19 -> V_21 + V_25 ) ;
F_14 ( V_19 -> V_21 + V_27 , V_31 , V_33 ) ;
}
static T_2 F_15 ( struct V_18 * V_19 , T_2 V_14 )
{
T_2 V_35 , V_36 = 0 , V_37 = 0 ;
T_2 V_38 = sizeof( struct V_39 ) + V_14 ;
T_2 V_40 = 0 ;
if ( V_38 > V_19 -> V_41 * 254 )
goto V_42;
V_40 = V_19 -> V_43 ;
while ( V_38 ) {
if ( V_38 < 254 )
V_38 = 0 ;
else
V_38 -= 254 ;
F_13 ( V_19 , V_19 -> V_43 , & V_35 ,
sizeof( V_35 ) ) ;
if ( ! V_38 )
F_11 ( V_19 , V_19 -> V_43 , & V_37 ,
sizeof( V_37 ) ) ;
V_19 -> V_43 = V_35 ;
V_36 ++ ;
if ( ! V_35 && V_38 ) {
V_19 -> V_43 = V_40 ;
V_40 = 0 ;
goto V_42;
}
}
V_19 -> V_41 -= V_36 ;
V_42:
return V_40 ;
}
static void F_16 ( struct V_18 * V_19 , T_2 V_44 )
{
if ( ! V_19 -> V_43 )
V_19 -> V_43 = V_44 ;
else
F_11 ( V_19 , V_19 -> V_45 ,
& V_44 , sizeof( V_44 ) ) ;
while ( V_44 ) {
T_2 V_35 ;
V_19 -> V_41 ++ ;
F_13 ( V_19 , V_44 , & V_35 , sizeof( V_35 ) ) ;
V_19 -> V_45 = V_44 ;
V_44 = V_35 ;
}
}
static int F_17 ( struct V_18 * V_19 )
{
T_1 V_46 = 0 ;
F_13 ( V_19 , V_19 -> V_47 + 3 , & V_46 , sizeof( V_46 ) ) ;
return V_46 & 0x80 ;
}
static void F_18 ( struct V_18 * V_19 , T_2 * V_44 )
{
T_2 V_46 = 0 ;
F_11 ( V_19 , V_19 -> V_47 , V_44 , 2 ) ;
F_11 ( V_19 , V_19 -> V_47 + 2 , & V_46 , sizeof( V_46 ) ) ;
V_19 -> V_47 += 4 ;
if ( V_19 -> V_47 >= V_19 -> V_48 )
V_19 -> V_47 = V_19 -> V_49 ;
}
static int F_19 ( struct V_18 * V_19 , void * V_50 , int V_51 )
{
int V_4 = - V_52 ;
if ( F_17 ( V_19 ) ) {
T_2 V_44 = F_15 ( V_19 , V_51 ) ;
if ( V_44 ) {
F_11 ( V_19 , V_44 , V_50 , V_51 ) ;
F_18 ( V_19 , & V_44 ) ;
V_4 = 0 ;
}
}
return V_4 ;
}
static int F_20 ( struct V_18 * V_19 , T_1 V_53 ,
void * V_54 , int V_33 )
{
struct V_55 V_50 = {
. V_56 = V_57 ,
. V_58 = V_53 ,
} ;
unsigned long V_59 ;
int V_4 = - V_52 ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
if ( F_17 ( V_19 ) ) {
T_2 V_44 = F_15 ( V_19 , sizeof( V_50 ) ) ;
if ( V_44 ) {
F_11 ( V_19 , V_44 , & V_50 , sizeof( V_50 ) ) ;
F_18 ( V_19 , & V_44 ) ;
V_19 -> V_61 . V_62 = 255 ;
F_22 ( & V_19 -> V_60 , V_59 ) ;
V_4 = F_23 ( V_19 -> V_63 ,
V_19 -> V_61 . V_62 != 255 ) ;
if ( ! V_4 )
memcpy ( V_54 , V_19 -> V_61 . V_64 ,
V_33 ) ;
goto V_42;
}
}
F_22 ( & V_19 -> V_60 , V_59 ) ;
V_42:
return V_4 ;
}
static int F_24 ( struct V_18 * V_19 , int V_65 )
{
struct V_66 V_50 = {
. V_56 = V_67 ,
. V_68 = V_65 ,
. V_69 = ! V_65 ,
. V_70 = 10 ,
} ;
unsigned long V_59 ;
int V_4 = - V_52 ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
if ( F_17 ( V_19 ) ) {
T_2 V_44 = F_15 ( V_19 , sizeof( V_50 ) ) ;
if ( V_44 ) {
F_11 ( V_19 , V_44 , & V_50 , sizeof( V_50 ) ) ;
F_18 ( V_19 , & V_44 ) ;
V_19 -> V_71 . V_72 = 255 ;
F_22 ( & V_19 -> V_60 , V_59 ) ;
V_4 = F_23 ( V_19 -> V_63 ,
V_19 -> V_71 . V_72 != 255 ) ;
F_25 ( V_73 L_1 , V_74 ,
V_65 ? L_2 : L_3 ,
V_19 -> V_71 . V_72 ) ;
goto V_42;
}
}
F_22 ( & V_19 -> V_60 , V_59 ) ;
V_42:
return V_4 ;
}
static int F_26 ( struct V_18 * V_19 , T_1 * V_15 , T_2 V_14 )
{
T_2 V_54 , V_75 , V_35 , V_76 , V_77 ;
struct V_78 V_50 = {
. V_56 = V_79 ,
} ;
T_1 * V_80 = ( char * ) V_15 ;
int V_4 = - V_52 ;
if ( F_17 ( V_19 ) ) {
V_75 = F_15 ( V_19 , sizeof( V_50 ) ) ;
V_4 = - V_81 ;
if ( ! V_75 )
goto V_42;
V_54 = F_15 ( V_19 , V_14 + 26 + 24 ) ;
if ( ! V_54 ) {
F_16 ( V_19 , V_75 ) ;
goto V_42;
}
V_4 = 0 ;
memcpy ( & V_50 . V_82 [ 0 ] , V_80 , 12 ) ;
V_77 = V_14 - 12 ;
V_80 += 12 ;
V_50 . V_15 = V_54 ;
if ( ( ( * V_80 ) * 256 + ( * ( V_80 + 1 ) ) ) > 1500 ) {
T_1 V_83 [ V_84 ] = {
[ 0 ] = 0xAA , [ 1 ] = 0xAA , [ 2 ] = 0x03 , [ 4 ] = 0x00 ,
} ;
F_11 ( V_19 , V_54 + 2 +
F_27 ( struct V_85 , V_83 ) ,
V_83 , sizeof( V_83 ) ) ;
V_50 . V_33 = V_77 + 24 + 4 + 6 ;
if ( V_77 > ( 254 - sizeof( struct V_85 ) ) ) {
V_76 = 254 - sizeof( struct V_85 ) ;
V_77 -= V_76 ;
} else {
V_76 = V_77 ;
V_77 = 0 ;
}
F_11 ( V_19 ,
V_54 + 2 + sizeof( struct V_85 ) ,
V_80 , V_76 ) ;
V_80 += V_76 ;
F_13 ( V_19 , V_54 , & V_35 , sizeof( V_35 ) ) ;
V_54 = V_35 ;
} else {
V_50 . V_33 = V_77 + 24 + 4 - 2 ;
V_80 += 2 ;
V_77 -= 2 ;
if ( V_77 > ( 254 - sizeof( struct V_85 ) + 6 ) ) {
V_76 = 254 - sizeof( struct V_85 ) + 6 ;
V_77 -= V_76 ;
} else {
V_76 = V_77 ;
V_77 = 0 ;
}
F_11 ( V_19 , V_54 + 2 +
F_27 ( struct V_85 , V_83 ) ,
V_80 , V_76 ) ;
V_80 += V_76 ;
F_13 ( V_19 , V_54 , & V_35 , sizeof( V_35 ) ) ;
V_54 = V_35 ;
}
while ( V_77 > 0 ) {
if ( V_77 > 254 ) {
V_76 = 254 ;
V_77 -= 254 ;
} else {
V_76 = V_77 ;
V_77 = 0 ;
}
F_11 ( V_19 , V_54 + 2 , V_80 , V_76 ) ;
V_80 += V_76 ;
F_13 ( V_19 , V_54 , & V_35 , sizeof( V_35 ) ) ;
V_54 = V_35 ;
}
F_11 ( V_19 , V_75 , & V_50 , sizeof( V_50 ) ) ;
F_18 ( V_19 , & V_75 ) ;
}
V_42:
return V_4 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_86 V_50 = {
. V_56 = V_87 ,
} ;
return F_19 ( V_19 , & V_50 , sizeof( V_50 ) ) ;
}
static inline int F_29 ( struct V_18 * V_19 )
{
return V_19 -> V_88 == V_89 ? V_90 :
V_91 ;
}
static inline int F_30 ( struct V_18 * V_19 )
{
return V_19 -> V_88 == V_89 ? V_92 :
V_93 ;
}
static int F_31 ( struct V_18 * V_19 , T_2 V_94 )
{
struct V_95 V_50 = {
. V_56 = V_96 ,
. V_97 = V_98 ,
. V_99 = 0x10 ,
. V_100 = V_94 ,
. V_101 = V_94 ,
. V_102 = F_29 ( V_19 ) ,
} ;
V_19 -> V_103 = V_19 -> V_104 = 0 ;
return F_19 ( V_19 , & V_50 , sizeof( V_50 ) ) ;
}
static int F_32 ( struct V_18 * V_19 , T_2 V_105 )
{
struct V_106 V_50 = {
. V_56 = V_107 ,
. V_108 = 10 ,
. V_109 = {
. V_12 = {
. V_10 = V_110 ,
. V_14 = 1 ,
} ,
. V_111 = V_19 -> V_111 ,
} ,
} ;
memcpy ( & V_50 . V_112 , & V_19 -> V_113 [ V_105 ] . V_112 , 72 ) ;
return F_19 ( V_19 , & V_50 , sizeof( V_50 ) ) ;
}
static int F_33 ( struct V_18 * V_19 )
{
struct V_114 V_50 = {
. V_56 = V_115 ,
. V_112 = 400 ,
. V_116 = 1 ,
. V_109 = {
. V_12 = {
. V_10 = V_110 ,
. V_14 = 1 ,
} ,
. V_111 = V_19 -> V_111 ,
} ,
. V_117 = {
. V_12 = {
. V_10 = V_118 ,
. V_14 = 2 ,
} ,
. V_119 = {
[ 0 ] = V_120 |
V_121 ,
[ 1 ] = V_120 |
V_122 ,
} ,
} ,
. V_123 = {
. V_12 = {
. V_10 = V_118 ,
. V_14 = 2 ,
} ,
. V_119 = {
[ 0 ] = V_120 |
V_121 ,
[ 1 ] = V_120 |
V_122 ,
} ,
} ,
. V_124 = {
. V_12 = {
. V_10 = V_125 ,
. V_14 = 2 ,
} ,
. V_126 = 10 ,
} ,
. V_102 = F_29 ( V_19 ) ,
. V_127 = F_30 ( V_19 ) ,
} ;
F_5 ( & V_50 . V_128 . V_12 , & V_19 -> V_129 . V_12 ) ;
F_5 ( & V_19 -> V_130 . V_12 , & V_19 -> V_129 . V_12 ) ;
return F_19 ( V_19 , & V_50 , sizeof( V_50 ) ) ;
}
static void F_34 ( struct V_18 * V_19 , T_2 V_131 )
{
T_2 V_3 = 0 ;
int V_132 = 0 ;
struct V_133 V_50 ;
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
if ( V_50 . V_72 == V_134 ) {
F_35 ( L_5 ) ;
if ( ( V_19 -> V_88 == V_89 &&
( V_50 . V_127 & V_92 ) ) ||
( V_19 -> V_88 == V_135 &&
( V_50 . V_127 & V_93 ) ) ||
V_19 -> V_88 == V_136 ) {
if ( ! V_19 -> V_129 . V_12 . V_14 )
V_132 = 1 ;
else if ( V_19 -> V_129 . V_12 . V_14 == 3 &&
! memcmp ( V_19 -> V_129 . V_129 , L_6 , 3 ) )
V_132 = 1 ;
else if ( V_19 -> V_129 . V_12 . V_14 != V_50 . V_128 . V_12 . V_14 )
V_132 = 0 ;
else if ( memcmp ( V_19 -> V_129 . V_129 , V_50 . V_128 . V_129 ,
V_19 -> V_129 . V_12 . V_14 ) )
V_132 = 0 ;
else
V_132 = 1 ;
if ( V_132 ) {
for ( V_3 = 0 ; V_3 < V_19 -> V_103 ; V_3 ++ ) {
if ( ! memcmp ( V_19 -> V_113 [ V_3 ] . V_137 ,
V_50 . V_137 , V_84 ) ) {
V_132 = 0 ;
break;
}
}
}
if ( V_132 && ( V_3 < 20 ) ) {
memcpy ( & V_19 -> V_113 [ V_3 ] . V_112 ,
& V_50 . V_112 , 73 ) ;
V_19 -> V_103 ++ ;
V_19 -> V_138 = V_50 . V_138 ;
}
}
} else if ( V_50 . V_72 == V_139 ) {
F_35 ( L_7 ) ;
V_19 -> V_104 = 0 ;
for ( V_3 = V_19 -> V_104 ; V_3 < V_19 -> V_103 ; V_3 ++ )
if ( ! F_32 ( V_19 , V_3 ) )
break;
V_19 -> V_104 = V_3 ;
if ( V_19 -> V_104 == V_19 -> V_103 ) {
if ( V_19 -> V_88 == V_89 )
F_31 ( V_19 , 100 ) ;
else {
V_19 -> V_140 ++ ;
if ( V_19 -> V_140 > V_141 )
F_33 ( V_19 ) ;
else
F_31 ( V_19 , 100 ) ;
}
}
}
}
static int F_36 ( struct V_18 * V_19 )
{
T_1 V_142 = F_10 ( V_19 -> V_21 + V_143 ) ;
T_1 V_144 = V_142 & ( ~ ( V_145 | V_146 |
V_147 ) ) ;
F_7 ( V_144 , V_19 -> V_21 + V_143 ) ;
return V_142 & V_147 ;
}
static int F_37 ( struct V_18 * V_19 )
{
T_1 V_142 = F_10 ( V_19 -> V_21 + V_143 ) ;
T_1 V_144 = ( V_142 & ~ ( V_145 | V_146 ) ) |
V_147 ;
F_7 ( V_144 , V_19 -> V_21 + V_143 ) ;
return V_142 & V_147 ;
}
static T_2 F_38 ( struct V_18 * V_19 , T_1 * V_54 , T_2 V_33 )
{
T_2 V_148 , V_149 ;
T_1 * V_15 = V_54 + 12 ;
V_33 -= 12 ;
F_13 ( V_19 , V_19 -> V_150 + 2 ,
& V_148 , sizeof( V_148 ) ) ;
if ( V_33 > V_151 - sizeof( struct V_152 ) ) {
F_13 ( V_19 ,
V_19 -> V_150 +
sizeof( struct V_152 ) , V_15 ,
V_151 -
sizeof( struct V_152 ) ) ;
V_33 -= V_151 - sizeof( struct V_152 ) ;
V_15 += V_151 - sizeof( struct V_152 ) ;
} else {
F_13 ( V_19 ,
V_19 -> V_150 +
sizeof( struct V_152 ) ,
V_15 , V_33 ) ;
V_33 = 0 ;
}
while ( V_33 > 0 ) {
if ( V_33 > V_151 - 5 ) {
F_13 ( V_19 , V_148 + 5 , V_15 ,
V_151 - 5 ) ;
V_33 -= V_151 - 5 ;
V_15 += V_151 - 5 ;
F_13 ( V_19 , V_148 + 2 , & V_149 ,
sizeof( V_149 ) ) ;
V_148 = V_149 ;
} else {
F_13 ( V_19 , V_148 + 5 , V_15 , V_33 ) ;
V_33 = 0 ;
}
}
return 0 ;
}
static void F_39 ( struct V_18 * V_19 )
{
T_1 V_46 ;
T_2 V_131 ;
if ( V_19 -> V_47 == V_19 -> V_153 )
goto V_42;
F_13 ( V_19 , V_19 -> V_153 + 3 , & V_46 , sizeof( V_46 ) ) ;
if ( ! ( V_46 & 0x80 ) )
goto V_42;
F_13 ( V_19 , V_19 -> V_153 , & V_131 , sizeof( V_131 ) ) ;
F_16 ( V_19 , V_131 ) ;
V_19 -> V_153 += 4 ;
if ( V_19 -> V_153 >= V_19 -> V_48 )
V_19 -> V_153 = V_19 -> V_49 ;
V_42:
return;
}
static int F_40 ( struct V_18 * V_19 )
{
T_1 V_46 ;
F_13 ( V_19 , V_19 -> V_154 + 3 , & V_46 , sizeof( V_46 ) ) ;
return V_46 & 0x80 ;
}
static void F_41 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
F_25 ( V_73 L_8 ,
V_156 -> V_157 , V_19 -> V_137 ) ;
F_43 ( V_156 ) ;
}
static void F_44 ( struct V_18 * V_19 )
{
T_1 V_46 = 0 ;
F_11 ( V_19 , V_19 -> V_154 + 3 , & V_46 , sizeof( V_46 ) ) ;
V_19 -> V_154 += 4 ;
if ( V_19 -> V_154 >= V_19 -> V_158 )
V_19 -> V_154 = V_19 -> V_159 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_160 V_50 = {
. V_56 = V_161 ,
. type = V_162 ,
. V_108 = 1000 ,
} ;
F_35 ( L_4 ) ;
memcpy ( V_50 . V_26 , V_19 -> V_137 , V_84 ) ;
return F_19 ( V_19 , & V_50 , sizeof( V_50 ) ) ;
}
static int F_46 ( struct V_18 * V_19 )
{
struct V_163 V_50 = {
. V_56 = V_164 ,
. V_108 = 1000 ,
. V_165 = 5 ,
. V_127 = V_19 -> V_127 ,
} ;
F_35 ( L_4 ) ;
memcpy ( V_50 . V_26 , V_19 -> V_137 , V_84 ) ;
return F_19 ( V_19 , & V_50 , sizeof( V_50 ) ) ;
}
static void F_47 ( struct V_155 * V_156 , T_2 V_131 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
struct V_166 V_50 ;
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
if ( V_50 . V_72 == V_134 ) {
if ( V_19 -> V_88 == V_89 ) {
if ( V_19 -> V_104 < V_19 -> V_103 ) {
const int V_3 = V_19 -> V_104 ;
memcpy ( V_19 -> V_137 ,
V_19 -> V_113 [ V_3 ] . V_137 , V_84 ) ;
V_19 -> V_111 = V_19 -> V_113 [ V_3 ] . V_109 . V_111 ;
F_5 ( & V_19 -> V_130 . V_12 ,
& V_19 -> V_113 [ V_3 ] . V_128 . V_12 ) ;
F_45 ( V_19 ) ;
}
} else {
const int V_3 = V_19 -> V_104 ;
memcpy ( & V_19 -> V_137 , & V_19 -> V_113 [ V_3 ] . V_137 , V_84 ) ;
V_19 -> V_111 = V_19 -> V_113 [ V_3 ] . V_109 . V_111 ;
F_5 ( & V_19 -> V_130 . V_12 ,
& V_19 -> V_113 [ V_3 ] . V_128 . V_12 ) ;
F_41 ( V_156 ) ;
}
} else {
int V_3 ;
V_19 -> V_104 ++ ;
for ( V_3 = V_19 -> V_104 ; V_3 < V_19 -> V_103 ; V_3 ++ )
if ( ! F_32 ( V_19 , V_3 ) )
break;
V_19 -> V_104 = V_3 ;
if ( V_19 -> V_104 == V_19 -> V_103 ) {
if ( V_19 -> V_88 == V_89 )
F_31 ( V_19 , 100 ) ;
else {
V_19 -> V_140 ++ ;
if ( V_19 -> V_140 > V_141 )
F_33 ( V_19 ) ;
else
F_31 ( V_19 , 100 ) ;
}
}
}
}
static inline void F_48 ( struct V_155 * V_156 ,
struct V_18 * V_19 )
{
if ( V_19 -> V_88 == V_89 ) {
F_25 ( V_73 L_9 ) ;
F_49 ( V_156 ) ;
F_28 ( V_19 ) ;
}
}
static inline void F_50 ( struct V_155 * V_156 ,
struct V_18 * V_19 ,
T_2 V_131 )
{
struct V_167 V_50 ;
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
F_16 ( V_19 , V_50 . V_15 ) ;
if ( F_51 ( V_156 ) )
F_43 ( V_156 ) ;
}
static inline void F_52 ( struct V_155 * V_156 ,
struct V_18 * V_19 , T_2 V_131 )
{
struct V_168 V_50 ;
struct V_169 * V_170 ;
T_1 V_138 , V_83 [ V_84 ] ;
T_2 V_171 ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
V_19 -> V_150 = V_50 . V_15 ;
F_13 ( V_19 ,
V_50 . V_15 + F_27 ( struct V_152 , V_138 ) ,
& V_138 , sizeof( V_138 ) ) ;
V_19 -> V_138 = V_138 <= 63 ? ( V_138 * 100 ) / 64 : 255 ;
F_13 ( V_19 ,
V_50 . V_15 +
F_27 ( struct V_152 , V_83 ) ,
& V_83 , sizeof( V_83 ) ) ;
if ( ! ( V_83 [ 0 ] == 0xAA && V_83 [ 1 ] == 0xAA &&
V_83 [ 2 ] == 0x03 && V_83 [ 4 ] == 0x00 ) ) {
F_25 ( V_73 L_10 ) ;
return;
}
V_171 = V_50 . V_33 + 12 - 24 - 4 - 6 ;
V_170 = F_53 ( V_171 + 5 ) ;
if ( ! V_170 ) {
F_25 ( V_172 L_11 ,
V_156 -> V_157 , V_171 ) ;
V_156 -> V_173 . V_174 ++ ;
} else {
V_170 -> V_156 = V_156 ;
F_54 ( V_170 , 2 ) ;
F_55 ( V_170 , ( unsigned char * ) & V_50 . V_82 , 12 ) ;
F_38 ( V_19 , V_170 -> V_15 , V_171 ) ;
F_56 ( V_170 , V_171 ) ;
V_170 -> V_175 = F_57 ( V_170 , V_156 ) ;
V_156 -> V_173 . V_176 ++ ;
V_156 -> V_173 . V_177 += V_170 -> V_14 ;
F_58 ( V_170 ) ;
}
}
static inline void F_59 ( struct V_18 * V_19 ,
T_2 V_131 , void * V_50 , int V_33 )
{
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_19 -> V_61 ,
sizeof( V_19 -> V_61 ) ) ;
V_69 ( & V_19 -> V_63 ) ;
}
static inline void F_60 ( struct V_155 * V_156 ,
struct V_18 * V_19 ,
T_2 V_131 )
{
struct V_178 V_50 ;
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
if ( V_50 . V_72 == V_134 )
F_43 ( V_156 ) ;
}
static inline void F_61 ( struct V_155 * V_156 ,
T_2 V_131 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
struct V_179 V_50 ;
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
if ( V_50 . V_72 == V_134 )
F_41 ( V_156 ) ;
}
static inline void F_62 ( struct V_18 * V_19 ,
T_2 V_131 )
{
struct V_180 V_50 ;
F_35 ( L_4 ) ;
F_13 ( V_19 , V_131 , & V_50 , sizeof( V_50 ) ) ;
if ( V_50 . V_72 == V_134 )
F_46 ( V_19 ) ;
else
F_28 ( V_19 ) ;
}
static inline void F_63 ( struct V_155 * V_156 )
{
int V_181 ;
T_2 V_131 ;
T_1 V_56 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
F_35 ( L_4 ) ;
V_182:
V_181 = 0 ;
if ( ! F_40 ( V_19 ) )
goto free;
F_13 ( V_19 , V_19 -> V_154 , & V_131 , sizeof( V_131 ) ) ;
F_13 ( V_19 , V_131 + 2 , & V_56 , sizeof( V_56 ) ) ;
switch ( V_56 ) {
case V_183 :
case V_184 :
case V_185 :
F_48 ( V_156 , V_19 ) ;
break;
case V_186 :
F_50 ( V_156 , V_19 , V_131 ) ;
break;
case V_187 :
F_52 ( V_156 , V_19 , V_131 ) ;
break;
case V_188 :
F_59 ( V_19 , V_131 ,
& V_19 -> V_61 ,
sizeof( V_19 -> V_61 ) ) ;
break;
case V_189 :
F_59 ( V_19 , V_131 ,
& V_19 -> V_71 ,
sizeof( V_19 -> V_71 ) ) ;
break;
case V_190 :
F_60 ( V_156 , V_19 , V_131 ) ;
break;
case V_191 :
F_34 ( V_19 , V_131 ) ;
break;
case V_192 :
F_47 ( V_156 , V_131 ) ;
break;
case V_193 :
F_61 ( V_156 , V_131 ) ;
break;
case V_194 :
F_62 ( V_19 , V_131 ) ;
break;
case V_195 :
F_28 ( V_19 ) ;
break;
}
F_44 ( V_19 ) ;
V_181 = 1 ;
free:
F_39 ( V_19 ) ;
if ( V_181 )
goto V_182;
}
static inline void F_64 ( struct V_18 * V_19 )
{
F_7 ( V_145 , V_19 -> V_21 + V_143 ) ;
}
static T_3 F_65 ( int V_196 , void * V_197 )
{
struct V_155 * V_156 = V_197 ;
struct V_18 * V_19 ;
V_19 = F_42 ( V_156 ) ;
F_66 ( & V_19 -> V_60 ) ;
F_64 ( V_19 ) ;
F_36 ( V_19 ) ;
F_63 ( V_156 ) ;
F_37 ( V_19 ) ;
F_67 ( & V_19 -> V_60 ) ;
return V_198 ;
}
static int F_68 ( struct V_18 * V_19 )
{
T_1 V_46 = 0 ;
int V_3 , V_4 = 0 ;
F_69 ( V_199 , V_19 -> V_21 + V_143 ) ;
F_69 ( 0 , V_19 -> V_21 + V_143 ) ;
F_69 ( V_199 , V_19 -> V_21 + V_143 ) ;
F_11 ( V_19 , 0x480 , & V_46 , sizeof( V_46 ) ) ;
F_69 ( 0 , V_19 -> V_21 + V_143 ) ;
F_9 ( 1024 * 50 ) ;
F_37 ( V_19 ) ;
for ( V_3 = 0 ; V_3 < 10000 ; V_3 ++ ) {
F_13 ( V_19 , 0x480 , & V_46 , sizeof( V_46 ) ) ;
if ( V_46 == 'W' ) {
V_46 = 'A' ;
F_11 ( V_19 , 0x480 , & V_46 , sizeof( V_46 ) ) ;
goto V_42;
}
F_9 ( 10 ) ;
}
F_25 ( V_172 L_12 , V_74 ) ;
V_4 = - V_200 ;
V_42:
return V_4 ;
}
static int F_70 ( struct V_18 * V_19 )
{
T_2 V_44 , V_35 ;
int V_4 = F_68 ( V_19 ) ;
if ( V_4 )
goto V_201;
V_19 -> V_202 [ 0 ] = '\0' ;
F_13 ( V_19 , 0x1a00 ,
V_19 -> V_202 , sizeof( V_19 -> V_202 ) ) ;
V_19 -> V_202 [ sizeof( V_19 -> V_202 ) - 1 ] = '\0' ;
V_19 -> V_203 [ 0 ] = '\0' ;
F_13 ( V_19 , 0x1a40 ,
V_19 -> V_203 , sizeof( V_19 -> V_203 ) ) ;
V_19 -> V_203 [ sizeof( V_19 -> V_203 ) - 1 ] = '\0' ;
F_6 ( V_19 , V_30 ) ;
F_13 ( V_19 , 0x482 , & V_19 -> V_49 , 2 ) ;
F_13 ( V_19 , 0x486 , & V_19 -> V_48 , 2 ) ;
F_13 ( V_19 , 0x488 , & V_19 -> V_159 , 2 ) ;
F_13 ( V_19 , 0x48c , & V_19 -> V_158 , 2 ) ;
F_13 ( V_19 , 0x48e , & V_19 -> V_43 , 2 ) ;
F_13 ( V_19 , 0x492 , & V_19 -> V_204 , 2 ) ;
V_19 -> V_153 = V_19 -> V_47 = V_19 -> V_49 ;
V_19 -> V_48 += V_19 -> V_49 ;
V_19 -> V_154 = V_19 -> V_159 ;
V_19 -> V_158 += V_19 -> V_159 ;
V_19 -> V_41 = 1 ;
V_44 = V_19 -> V_43 ;
V_35 = V_44 + V_151 ;
while ( ( V_35 - V_19 -> V_43 ) < V_19 -> V_204 ) {
V_19 -> V_41 ++ ;
F_11 ( V_19 , V_44 , & V_35 , sizeof( V_35 ) ) ;
V_44 = V_35 ;
V_35 = V_44 + V_151 ;
}
V_4 = 0 ;
V_35 = 0 ;
F_11 ( V_19 , V_44 , & V_35 , sizeof( V_35 ) ) ;
V_19 -> V_45 = V_44 ;
V_42:
return V_4 ;
V_201:
F_25 ( V_172 L_13 , V_74 ) ;
goto V_42;
}
static int F_71 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = - V_200 ;
unsigned long V_59 ;
struct V_205 * V_206 ;
V_206 = V_19 -> V_207 ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
V_206 -> V_208 -- ;
F_49 ( V_156 ) ;
F_64 ( V_19 ) ;
F_36 ( V_19 ) ;
V_4 = 0 ;
F_25 ( V_73 L_14 , V_156 -> V_157 ) ;
F_22 ( & V_19 -> V_60 , V_59 ) ;
return V_4 ;
}
static int F_72 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = - V_200 ;
F_36 ( V_19 ) ;
if ( F_70 ( V_19 ) ) {
F_25 ( V_172 L_15 ,
V_156 -> V_157 ) ;
F_73 ( V_156 -> V_196 , V_156 ) ;
goto V_42;
}
F_49 ( V_156 ) ;
V_19 -> V_140 = 0 ;
F_64 ( V_19 ) ;
F_37 ( V_19 ) ;
F_31 ( V_19 , 100 ) ;
F_35 ( L_16 , V_156 -> V_157 ) ;
V_4 = 0 ;
V_42:
return V_4 ;
}
static void F_74 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
struct V_209 * V_173 = & V_156 -> V_173 ;
unsigned long V_59 ;
int V_4 ;
V_173 -> V_210 ++ ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
V_4 = F_72 ( V_156 ) ;
F_22 ( & V_19 -> V_60 , V_59 ) ;
if ( V_4 )
F_25 ( V_211 L_17 ,
V_156 -> V_157 , V_4 ) ;
else {
V_156 -> V_212 = V_213 ;
F_43 ( V_156 ) ;
}
}
static T_4 F_75 ( struct V_169 * V_170 ,
struct V_155 * V_156 )
{
int V_214 , V_4 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
unsigned long V_59 ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
V_214 = F_36 ( V_19 ) ;
V_4 = F_26 ( V_19 , V_170 -> V_15 , V_170 -> V_14 ) ;
if ( V_214 )
F_37 ( V_19 ) ;
if ( V_4 ) {
++ V_156 -> V_173 . V_215 ;
F_49 ( V_156 ) ;
} else {
++ V_156 -> V_173 . V_216 ;
V_156 -> V_173 . V_217 += V_170 -> V_14 ;
F_76 ( V_170 ) ;
if ( V_19 -> V_41 < 2 )
F_49 ( V_156 ) ;
}
F_22 ( & V_19 -> V_60 , V_59 ) ;
return V_218 ;
}
static int F_77 ( struct V_155 * V_156 )
{
int V_4 = - V_200 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
unsigned long V_59 ;
struct V_205 * V_206 ;
V_206 = V_19 -> V_207 ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
if ( ! F_78 ( V_206 ) )
goto V_42;
F_79 ( V_156 ) ;
V_206 -> V_208 ++ ;
F_35 ( L_18 , V_156 -> V_157 ) ;
if ( F_70 ( V_19 ) )
goto V_201;
V_19 -> V_140 = 0 ;
F_64 ( V_19 ) ;
F_37 ( V_19 ) ;
F_31 ( V_19 , 100 ) ;
V_4 = 0 ;
F_35 ( L_19 , V_156 -> V_157 ) ;
F_25 ( V_73 L_20
L_21 ,
V_156 -> V_157 , V_19 -> V_202 ,
V_156 -> V_157 , V_19 -> V_203 ) ;
V_42:
F_22 ( & V_19 -> V_60 , V_59 ) ;
return V_4 ;
V_201:
F_25 ( V_172 L_22 , V_156 -> V_157 ) ;
goto V_42;
}
static struct V_219 * F_80 ( struct V_155 * V_156 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
struct V_219 * V_220 = & V_19 -> V_220 ;
T_5 V_13 ;
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
V_220 -> V_72 = F_81 ( V_156 ) ;
if ( ! F_20 ( V_19 , V_221 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_223 += V_13 ;
if ( ! F_20 ( V_19 , V_224 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_223 += V_13 ;
if ( ! F_20 ( V_19 , V_225 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_223 += V_13 ;
if ( ! F_20 ( V_19 , V_226 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_227 = V_13 ;
if ( ! F_20 ( V_19 , V_228 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_229 += V_13 ;
if ( ! F_20 ( V_19 , V_230 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_229 += V_13 ;
if ( ! F_20 ( V_19 , V_231 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_229 += V_13 ;
if ( ! F_20 ( V_19 , V_232 ,
& V_13 , sizeof( V_13 ) ) )
V_220 -> V_222 . V_229 += V_13 ;
return V_220 ;
}
static void F_82 ( struct V_205 * V_206 )
{
struct V_155 * V_156 = V_206 -> V_233 ;
while ( V_206 -> V_208 > 0 )
F_71 ( V_156 ) ;
F_83 ( V_156 ) ;
F_84 ( V_206 ) ;
F_85 ( V_156 ) ;
if ( V_206 -> V_233 )
F_86 ( V_206 -> V_233 ) ;
}
static int F_87 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
F_88 ( V_237 -> V_157 , L_23 , sizeof( V_237 -> V_157 ) ) ;
return 0 ;
}
static int F_89 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_2 = V_237 -> V_239 . V_240 ;
int V_4 = - V_241 ;
if ( F_1 ( V_19 -> V_1 , V_2 ) ) {
V_19 -> V_111 = V_2 ;
V_4 = F_72 ( V_156 ) ;
}
return V_4 ;
}
static int F_90 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
V_237 -> V_239 . V_240 = F_91 ( V_19 -> V_111 ) * 100000 ;
V_237 -> V_239 . V_242 = 1 ;
return 0 ;
}
static int F_92 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
int V_4 = - V_241 ;
if ( V_237 -> V_243 == V_89 ||
V_237 -> V_243 == V_135 ||
V_237 -> V_243 == V_136 ) {
struct V_18 * V_19 = F_42 ( V_156 ) ;
V_19 -> V_88 = V_237 -> V_243 ;
V_4 = F_72 ( V_156 ) ;
}
return V_4 ;
}
static int F_93 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
V_237 -> V_243 = V_19 -> V_88 ;
return 0 ;
}
static int F_94 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
V_237 -> V_244 . V_13 = V_19 -> V_138 ;
V_237 -> V_244 . V_245 = ! V_237 -> V_244 . V_13 ;
V_237 -> V_244 . V_246 = 1 ;
return 0 ;
}
static int F_95 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_247 * V_248 = (struct V_247 * ) V_238 ;
V_237 -> V_15 . V_249 = sizeof( * V_248 ) ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_250 = V_251 ;
V_248 -> V_252 = 1 ;
V_248 -> V_253 = 2 * 1000 * 1000 ;
return 0 ;
}
static int F_96 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = - V_241 ;
if ( V_237 -> V_254 . V_255 != V_256 )
goto V_42;
if ( F_97 ( V_237 -> V_254 . V_257 ) ) {
} else
memcpy ( V_19 -> V_137 , V_237 -> V_254 . V_257 , V_84 ) ;
V_4 = 0 ;
V_42:
return V_4 ;
}
static int F_98 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
V_237 -> V_254 . V_255 = V_256 ;
memcpy ( V_237 -> V_254 . V_257 , V_19 -> V_137 , V_84 ) ;
return 0 ;
}
static int F_99 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
return F_72 ( V_156 ) ;
}
static int F_100 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_3 ;
char * V_258 = V_238 ;
struct V_259 V_260 ;
for ( V_3 = 0 ; V_3 < V_19 -> V_103 ; ++ V_3 ) {
V_260 . V_261 = V_262 ;
V_260 . V_263 . V_254 . V_255 = V_256 ;
memcpy ( V_260 . V_263 . V_254 . V_257 , V_19 -> V_113 [ V_3 ] . V_137 , V_84 ) ;
V_258 = F_101 ( V_235 , V_258 ,
V_238 + V_264 ,
& V_260 , V_265 ) ;
V_260 . V_261 = V_266 ;
V_260 . V_263 . V_15 . V_59 = 1 ;
V_260 . V_263 . V_15 . V_249 = V_19 -> V_113 [ V_3 ] . V_128 . V_12 . V_14 ;
V_258 = F_102 ( V_235 , V_258 ,
V_238 + V_264 ,
& V_260 ,
V_19 -> V_113 [ V_3 ] . V_128 . V_129 ) ;
V_260 . V_261 = V_267 ;
V_260 . V_263 . V_243 = V_19 -> V_113 [ V_3 ] . V_102 ;
V_258 = F_101 ( V_235 , V_258 ,
V_238 + V_264 ,
& V_260 , V_268 ) ;
V_260 . V_261 = V_269 ;
V_260 . V_263 . V_239 . V_240 = V_19 -> V_113 [ V_3 ] . V_109 . V_111 ;
V_260 . V_263 . V_239 . V_242 = 0 ;
V_258 = F_101 ( V_235 , V_258 ,
V_238 + V_264 ,
& V_260 , V_270 ) ;
V_260 . V_261 = V_271 ;
if ( V_19 -> V_113 [ V_3 ] . V_127 & V_272 )
V_260 . V_263 . V_15 . V_59 = V_273 | V_274 ;
else
V_260 . V_263 . V_15 . V_59 = V_275 ;
V_260 . V_263 . V_15 . V_249 = 0 ;
V_258 = F_102 ( V_235 , V_258 ,
V_238 + V_264 ,
& V_260 , NULL ) ;
}
V_237 -> V_15 . V_249 = ( V_258 - V_238 ) ;
V_237 -> V_15 . V_59 = 0 ;
return 0 ;
}
static int F_103 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
if ( V_237 -> V_15 . V_59 ) {
F_4 ( V_276 ,
& V_19 -> V_129 . V_12 ,
V_238 , V_237 -> V_15 . V_249 ) ;
} else {
F_4 ( V_276 ,
& V_19 -> V_129 . V_12 , L_6 , 3 ) ;
}
return F_72 ( V_156 ) ;
}
static int F_104 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
unsigned long V_59 ;
F_21 ( & V_19 -> V_60 , V_59 ) ;
V_237 -> V_129 . V_59 = 1 ;
V_237 -> V_129 . V_249 = V_19 -> V_129 . V_12 . V_14 ;
memcpy ( V_238 , V_19 -> V_129 . V_129 , V_19 -> V_129 . V_12 . V_14 ) ;
F_22 ( & V_19 -> V_60 , V_59 ) ;
return 0 ;
}
static int F_105 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
if ( V_237 -> V_15 . V_249 > sizeof( V_19 -> V_277 ) )
return - V_278 ;
F_88 ( V_19 -> V_277 , V_238 , V_237 -> V_15 . V_249 ) ;
return 0 ;
}
static int F_106 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
struct V_18 * V_19 = F_42 ( V_156 ) ;
F_88 ( V_238 , V_19 -> V_277 , 32 ) ;
V_237 -> V_15 . V_249 = strlen ( V_238 ) ;
return 0 ;
}
static int F_107 ( struct V_155 * V_156 , struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
V_237 -> V_279 . V_13 = 2000000 ;
V_237 -> V_279 . V_246 = 1 ;
return 0 ;
}
static int F_108 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
T_2 V_280 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = F_20 ( V_19 , V_281 ,
& V_280 , sizeof( V_280 ) ) ;
if ( ! V_4 ) {
V_237 -> V_282 . V_13 = V_280 ;
V_237 -> V_282 . V_245 = V_280 >= 2347 ;
V_237 -> V_282 . V_246 = 1 ;
}
return V_4 ;
}
static int F_109 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
T_2 V_280 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = F_20 ( V_19 , V_283 ,
& V_280 , sizeof( V_280 ) ) ;
if ( ! V_4 ) {
V_237 -> V_284 . V_13 = V_280 ;
V_237 -> V_284 . V_245 = V_280 >= 2346 ;
V_237 -> V_284 . V_246 = 1 ;
}
return V_4 ;
}
static int F_110 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
T_2 V_285 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = F_20 ( V_19 ,
V_286 ,
& V_285 , sizeof( V_285 ) ) ;
if ( ! V_4 ) {
V_237 -> V_287 . V_13 = V_285 ;
V_237 -> V_287 . V_245 = 0 ;
V_237 -> V_287 . V_246 = 0 ;
V_237 -> V_287 . V_59 = V_288 ;
}
return V_4 ;
}
static int F_111 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
T_1 V_289 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = F_20 ( V_19 ,
V_290 ,
& V_289 , sizeof( V_289 ) ) ;
if ( V_4 )
goto V_42;
if ( V_237 -> V_289 . V_59 & V_291 ) {
V_237 -> V_289 . V_59 = V_292 | V_291 ;
goto V_293;
}
V_4 = F_20 ( V_19 , V_294 ,
& V_289 , sizeof( V_289 ) ) ;
if ( V_4 )
goto V_42;
V_237 -> V_289 . V_59 = V_292 | V_295 ;
V_293:
V_237 -> V_289 . V_13 = V_289 ;
V_237 -> V_289 . V_245 = 0 ;
V_42:
return V_4 ;
}
static int F_112 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
T_1 V_296 , V_297 , V_298 [ 100 ] , V_299 , V_300 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = F_20 ( V_19 ,
V_301 ,
& V_296 , sizeof( V_296 ) ) ;
if ( V_4 )
goto V_42;
if ( ! V_296 ) {
V_237 -> V_302 . V_59 = V_275 ;
goto V_42;
}
V_4 = F_20 ( V_19 , V_303 ,
& V_297 , sizeof( V_297 ) ) ;
if ( V_4 )
goto V_42;
V_237 -> V_302 . V_59 = V_297 ? V_304 :
V_305 ;
V_4 = F_20 ( V_19 , V_306 ,
& V_299 , sizeof( V_299 ) ) ;
if ( V_4 )
goto V_42;
V_4 = F_20 ( V_19 , V_307 ,
V_298 , V_299 ) ;
if ( V_4 )
goto V_42;
V_300 = F_113 ( T_2 , V_299 , V_237 -> V_302 . V_249 ) ;
V_300 = F_113 ( T_1 , V_300 , 100 ) ;
V_237 -> V_302 . V_249 = V_300 ;
memcpy ( V_238 , V_298 , V_300 ) ;
V_42:
return V_4 ;
}
static int F_114 ( struct V_155 * V_156 ,
struct V_234 * V_235 ,
union V_236 * V_237 , char * V_238 )
{
T_1 V_308 ;
struct V_18 * V_19 = F_42 ( V_156 ) ;
int V_4 = F_20 ( V_19 ,
V_309 ,
& V_308 , sizeof( V_308 ) ) ;
if ( V_4 )
goto V_42;
V_237 -> V_310 . V_245 = ! V_308 ;
V_237 -> V_310 . V_59 = V_311 ;
V_42:
return V_4 ;
}
static int F_115 ( struct V_205 * V_207 )
{
struct V_155 * V_156 ;
struct V_18 * V_19 ;
V_207 -> V_312 [ 0 ] -> V_313 = 16 ;
V_207 -> V_312 [ 0 ] -> V_59 = V_314 ;
V_207 -> V_315 = V_316 ;
V_207 -> V_317 = 1 ;
V_156 = F_116 ( sizeof( struct V_18 ) ) ;
if ( ! V_156 )
goto V_318;
V_156 -> V_319 = & V_320 ;
V_156 -> V_321 = 5 * V_322 ;
V_19 = F_42 ( V_156 ) ;
V_19 -> V_323 . V_324 = & V_19 -> V_324 ;
V_19 -> V_207 = V_207 ;
V_156 -> V_323 = & V_19 -> V_323 ;
V_156 -> V_325 = & V_326 ;
F_49 ( V_156 ) ;
V_207 -> V_233 = V_156 ;
return F_117 ( V_207 ) ;
V_318:
return - V_81 ;
}
static int F_117 ( struct V_205 * V_206 )
{
struct V_155 * V_156 = V_206 -> V_233 ;
int V_3 = 0 , V_327 , V_40 ;
struct V_18 * V_19 ;
V_206 -> V_328 = 5 ;
for ( V_327 = 0x280 ; V_327 < 0x400 ; V_327 += 0x20 ) {
V_206 -> V_312 [ 0 ] -> V_329 = V_327 ;
V_206 -> V_312 [ 1 ] -> V_329 = V_206 -> V_312 [ 0 ] -> V_329 + 0x10 ;
V_3 = F_118 ( V_206 ) ;
if ( V_3 == 0 )
break;
}
if ( V_3 != 0 )
goto V_330;
V_40 = F_119 ( V_206 , F_65 ) ;
if ( V_40 )
goto V_330;
V_40 = F_120 ( V_206 ) ;
if ( V_40 )
goto V_330;
V_156 -> V_196 = V_206 -> V_196 ;
V_156 -> V_21 = V_206 -> V_312 [ 0 ] -> V_329 ;
F_121 ( V_156 , & V_206 -> V_156 ) ;
if ( F_122 ( V_156 ) ) {
F_25 ( V_331 L_24 ) ;
goto V_330;
}
V_19 = F_42 ( V_156 ) ;
V_19 -> V_21 = V_156 -> V_21 ;
if ( ! F_8 ( V_19 ) ) {
F_25 ( V_172 L_25 ,
V_156 -> V_157 ) ;
F_85 ( V_156 ) ;
goto V_330;
}
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_156 -> V_332 [ V_3 ] = ( ( char * ) & V_19 -> V_26 ) [ V_3 ] ;
F_25 ( V_73 L_26
L_27 ,
V_156 -> V_157 , V_19 -> V_21 , ( int ) V_156 -> V_196 ,
V_156 -> V_332 ) ;
V_19 -> V_88 = V_89 ;
V_19 -> V_103 = 0 ;
V_19 -> V_104 = 0 ;
V_19 -> V_140 = 0 ;
F_4 ( V_276 , & V_19 -> V_129 . V_12 ,
L_6 , 3 ) ;
V_19 -> V_202 [ 0 ] = '\0' ;
V_19 -> V_203 [ 0 ] = '\0' ;
V_19 -> V_138 = 255 ;
V_19 -> V_111 = F_3 ( V_19 -> V_1 ) ;
F_88 ( V_19 -> V_277 , L_28 , sizeof( V_19 -> V_277 ) ) ;
F_123 ( & V_19 -> V_60 ) ;
F_124 ( & V_19 -> V_63 ) ;
F_125 ( V_156 ) ;
return 0 ;
V_330:
F_84 ( V_206 ) ;
return - V_200 ;
}
static void F_84 ( struct V_205 * V_206 )
{
F_126 ( V_206 ) ;
}
static int F_127 ( struct V_205 * V_206 )
{
struct V_155 * V_156 = V_206 -> V_233 ;
F_24 ( F_42 ( V_156 ) , V_333 ) ;
if ( V_206 -> V_208 )
F_83 ( V_156 ) ;
return 0 ;
}
static int F_128 ( struct V_205 * V_206 )
{
struct V_155 * V_156 = V_206 -> V_233 ;
F_24 ( F_42 ( V_156 ) , V_334 ) ;
if ( V_206 -> V_208 ) {
F_72 ( V_156 ) ;
F_79 ( V_156 ) ;
}
return 0 ;
}
static int T_6 F_129 ( void )
{
return F_130 ( & V_335 ) ;
}
static void T_7 F_131 ( void )
{
F_132 ( & V_335 ) ;
}
