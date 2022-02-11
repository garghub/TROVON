static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned char V_4 [ V_5 ] ;
int V_6 ;
unsigned int V_7 ;
struct V_8 * V_9 = V_2 -> V_8 ;
V_7 = ( ( V_3 >> 8 ) & V_10 ) ;
if ( V_7 != V_2 -> V_11 ) {
V_4 [ 0 ] = V_10 ;
V_4 [ 1 ] = V_7 ;
V_6 = F_2 ( V_9 , V_4 , V_5 ) ;
if ( V_6 != V_5 )
F_3 ( & V_9 -> V_12 , L_1 , V_13 , V_6 ) ;
else
V_2 -> V_11 = V_7 ;
} else
V_6 = V_5 ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned short V_3 ,
unsigned char * V_14 , int V_15 )
{
int V_6 = 0 ;
int V_16 = 0 ;
int V_17 ;
struct V_8 * V_9 = V_2 -> V_8 ;
F_5 ( & ( V_2 -> V_18 ) ) ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 != V_5 )
goto exit;
V_17 = V_3 & V_10 ;
V_19:
V_6 = F_6 ( V_9 , V_17 , V_15 , V_14 ) ;
if ( V_6 != V_15 ) {
if ( ++ V_16 == V_20 )
F_3 ( & V_9 -> V_12 ,
L_2 ,
V_13 , V_3 , V_15 , V_6 ) ;
else {
F_1 ( V_2 , V_3 ) ;
goto V_19;
}
}
exit:
F_7 ( & ( V_2 -> V_18 ) ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned short V_3 ,
unsigned char V_21 )
{
unsigned char V_4 [ 2 ] ;
int V_6 = 0 ;
struct V_8 * V_9 = V_2 -> V_8 ;
F_5 ( & ( V_2 -> V_18 ) ) ;
V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 != V_5 )
goto exit;
V_4 [ 0 ] = V_3 & V_10 ;
V_4 [ 1 ] = V_21 ;
V_6 = F_2 ( V_2 -> V_8 , V_4 , 2 ) ;
if ( V_6 != 2 ) {
F_3 ( & V_9 -> V_12 , L_1 , V_13 , V_6 ) ;
V_6 = - V_22 ;
} else
V_6 = 1 ;
exit:
F_7 ( & ( V_2 -> V_18 ) ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_25 = 0 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
int V_6 ;
unsigned short V_32 ;
unsigned short V_33 ;
unsigned char V_34 ;
unsigned char V_35 [ 2 ] ;
unsigned char V_21 [ V_36 ] ;
int V_37 [ V_38 ] ;
int V_39 [ V_38 ] ;
int V_40 [ V_38 ] ;
int V_41 [ V_38 ] ;
struct V_8 * V_42 = V_2 -> V_8 ;
V_27 = V_24 -> V_43 ;
V_28 = ( V_27 + 3 ) / 4 ;
V_32 = V_24 -> V_44 . V_32 ;
V_6 = F_4 ( V_2 , V_32 , V_35 ,
V_28 ) ;
if ( V_6 != V_28 ) {
F_3 ( & V_42 -> V_12 , L_3 ,
V_13 ) ;
return 0 ;
}
V_34 = V_24 -> V_45 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_29 = V_26 / 4 ;
V_30 = ( V_26 % 4 ) * 2 ;
V_31 = ( V_35 [ V_29 ] >> V_30 ) & 3 ;
if ( V_31 == 1 || V_31 == 2 ) {
V_33 = V_32 +
( ( V_26 * V_34 ) +
V_28 ) ;
V_6 = F_4 ( V_2 ,
V_33 , V_21 ,
V_34 ) ;
if ( V_6 != V_34 ) {
F_10 ( V_46 L_4 ,
V_13 ) ;
return 0 ;
} else {
V_37 [ V_25 ] =
( V_21 [ 0 ] << 4 ) | ( V_21 [ 2 ] & V_47 ) ;
V_39 [ V_25 ] =
( V_21 [ 1 ] << 4 ) |
( ( V_21 [ 2 ] >> 4 ) & V_47 ) ;
V_41 [ V_25 ] =
( V_21 [ 3 ] >> 4 ) & V_47 ;
V_40 [ V_25 ] =
( V_21 [ 3 ] & V_47 ) ;
if ( V_2 -> V_48 -> V_49 )
V_37 [ V_25 ] =
V_2 -> V_50 -
V_37 [ V_25 ] ;
if ( V_2 -> V_48 -> V_51 )
V_39 [ V_25 ] =
V_2 -> V_52 -
V_39 [ V_25 ] ;
}
V_25 ++ ;
}
}
if ( V_25 ) {
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
F_11 ( V_2 -> V_53 , V_54 ,
F_12 ( V_40 [ V_26 ] , V_41 [ V_26 ] ) ) ;
F_11 ( V_2 -> V_53 , V_55 ,
V_37 [ V_26 ] ) ;
F_11 ( V_2 -> V_53 , V_56 ,
V_39 [ V_26 ] ) ;
F_13 ( V_2 -> V_53 ) ;
}
} else
F_13 ( V_2 -> V_53 ) ;
F_14 ( V_2 -> V_53 ) ;
return V_25 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_57 = 0 ;
struct V_8 * V_42 = V_2 -> V_8 ;
static int V_58 ;
if ( V_24 -> V_59 != V_60 ) {
V_58 ++ ;
if ( V_58 < V_61 )
F_3 ( & V_42 -> V_12 , L_5 ,
V_13 ) ;
} else
V_57 = F_9 ( V_2 , V_24 ) ;
return V_57 ;
}
static int F_16 ( struct V_1 * V_2 )
{
unsigned char V_62 [ 4 ] ;
int V_57 = 0 ;
unsigned int V_6 ;
struct V_23 * V_24 ;
struct V_63 * V_64 ;
struct V_8 * V_42 = V_2 -> V_8 ;
V_6 = F_4 ( V_2 ,
V_2 -> V_65 + 1 ,
V_62 ,
V_2 -> V_66 ) ;
if ( V_6 != V_2 -> V_66 ) {
F_3 ( & V_42 -> V_12 ,
L_6 ) ;
return 0 ;
}
V_64 = & ( V_2 -> V_67 ) ;
F_17 (rfi, &rmi->support_fn_list, link) {
if ( V_24 -> V_68 ) {
if ( V_62 [ V_24 -> V_69 ] &
V_24 -> V_70 )
V_57 = F_15 ( V_2 ,
V_24 ) ;
}
}
return V_57 ;
}
static T_1 F_18 ( int V_71 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
int V_25 ;
do {
V_25 = F_16 ( V_2 ) ;
if ( V_25 )
F_19 ( V_2 -> V_72 , V_2 -> V_73 ,
F_20 ( 1 ) ) ;
else
break;
} while ( ! V_2 -> V_73 );
return V_74 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_75 * V_76 ,
unsigned int V_77 )
{
unsigned char V_78 [ V_79 ] ;
unsigned short V_80 ;
unsigned char V_81 ;
unsigned char V_82 ;
unsigned char V_83 , V_84 ;
unsigned int V_85 ;
int V_86 , V_87 , V_88 ;
int V_89 , V_90 ;
int V_91 , V_92 ;
int V_93 , V_94 ;
int V_95 ;
int V_96 ;
int V_6 ;
struct V_8 * V_42 = V_2 -> V_8 ;
V_24 -> V_44 . V_97 = V_76 -> V_97 ;
V_24 -> V_44 . V_32 = V_76 -> V_32 ;
V_24 -> V_44 . V_98 = V_76 -> V_98 ;
V_24 -> V_44 . V_59 = V_76 -> V_59 ;
V_24 -> V_59 = V_76 -> V_59 ;
V_24 -> V_68 = V_76 -> V_98 ;
V_24 -> V_44 . V_99 = V_76 -> V_99 ;
V_24 -> V_44 . V_100 = V_76 -> V_100 ;
V_6 = F_4 ( V_2 , V_76 -> V_97 ,
V_78 ,
sizeof( V_78 ) ) ;
if ( V_6 != sizeof( V_78 ) ) {
F_3 ( & V_42 -> V_12 , L_7 ,
V_13 ) ;
return V_6 ;
}
if ( ( V_78 [ 1 ] & V_101 ) <= 4 )
V_24 -> V_43 = ( V_78 [ 1 ] & V_101 ) + 1 ;
else {
if ( ( V_78 [ 1 ] & V_101 ) == 5 )
V_24 -> V_43 = 10 ;
}
V_24 -> V_69 = ( V_77 + 7 ) / 8 ;
if ( V_24 -> V_69 != 0 )
V_24 -> V_69 -= 1 ;
V_80 = V_77 % 8 ;
V_24 -> V_70 = 0 ;
for ( V_96 = V_80 ;
V_96 < ( ( V_76 -> V_98 & V_101 ) + V_80 ) ; V_96 ++ )
V_24 -> V_70 |= 1 << V_96 ;
V_81 = V_78 [ 5 ] & V_102 ;
V_82 = 3 + ( 2 * ( V_81 == 0 ? 1 : 0 ) ) ;
V_24 -> V_45 = V_82 ;
V_83 = V_78 [ 7 ] ;
V_84 = V_78 [ 8 ] ;
V_86 = V_83 & V_103 ;
V_87 = V_83 & V_104 ;
V_88 = V_83 & V_105 ;
V_91 = V_83 & V_106 ;
V_92 = V_83 & V_107 ;
V_94 = V_84 & V_108 ;
V_95 = V_78 [ 1 ] & V_109 ;
V_89 = V_83 & V_110 ;
V_90 = V_83 & V_111 ;
V_93 = V_84 & V_112 ;
V_85 =
( ( V_24 -> V_43 + 3 ) / 4 ) +
( V_82 * V_24 -> V_43 ) +
2 * V_95 +
! ! ( V_83 ) +
( V_83 || V_84 ) +
! ! ( V_86 | V_87 ) +
2 * ! ! ( V_87 ) ;
return V_6 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
unsigned char V_21 [ V_113 ] ;
int V_6 = 0 ;
struct V_8 * V_42 = V_2 -> V_8 ;
V_6 = F_4 ( V_2 ,
V_24 -> V_44 . V_97 ,
V_21 , V_79 ) ;
if ( V_6 != V_79 )
F_3 ( & V_42 -> V_12 , L_8 ,
V_13 ) ;
else {
V_6 = F_4 ( V_2 ,
V_24 -> V_44 . V_99 ,
V_21 , V_114 ) ;
if ( V_6 != V_114 ) {
F_3 ( & V_42 -> V_12 ,
L_9 ,
V_13 ) ;
return V_6 ;
}
V_2 -> V_50 = ( ( V_21 [ 6 ] & V_10 ) << 0 ) |
( ( V_21 [ 7 ] & V_47 ) << 8 ) ;
V_2 -> V_52 = ( ( V_21 [ 8 ] & V_115 ) << 0 ) |
( ( V_21 [ 9 ] & V_47 ) << 8 ) ;
}
return V_6 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_96 ;
int V_6 ;
unsigned char V_116 [ V_117 ] ;
unsigned char V_118 = 0 ;
int V_119 = 0 ;
unsigned int V_120 ;
struct V_23 * V_24 ;
struct V_75 V_121 ;
struct V_63 * V_64 ;
struct V_8 * V_42 = V_2 -> V_8 ;
F_24 ( & V_2 -> V_67 . V_122 ) ;
for ( V_96 = V_123 ; V_96 > V_124 ;
V_96 -= V_125 ) {
V_6 = F_4 ( V_2 , V_96 ,
( unsigned char * ) & V_121 ,
sizeof( V_121 ) ) ;
if ( V_6 != sizeof( V_121 ) ) {
F_3 ( & V_42 -> V_12 , L_10 , V_13 ) ;
return - V_22 ;
}
V_24 = NULL ;
if ( V_121 . V_59 ) {
switch ( V_121 . V_59 & V_10 ) {
case V_126 :
V_2 -> V_127 =
V_121 . V_97 ;
V_2 -> V_128 =
V_121 . V_99 ;
V_2 -> V_65 =
V_121 . V_32 ;
break;
case V_60 :
if ( V_121 . V_98 ) {
V_24 = F_25 ( sizeof( * V_24 ) ,
V_129 ) ;
if ( ! V_24 ) {
F_3 ( & V_42 -> V_12 ,
L_11 ,
V_13 ) ;
return - V_130 ;
}
V_6 = F_21
( V_2 , V_24 ,
& V_121 ,
V_118 ) ;
if ( V_6 < 0 ) {
F_26 ( V_24 ) ;
return V_6 ;
}
}
break;
}
V_118 += ( V_121 . V_98 & V_101 ) ;
if ( V_24 && V_121 . V_98 ) {
F_5 ( & ( V_2 -> V_131 ) ) ;
F_27 ( & V_24 -> V_132 ,
& V_2 -> V_67 . V_122 ) ;
F_7 ( & ( V_2 -> V_131 ) ) ;
}
} else {
F_28 ( & V_42 -> V_12 ,
L_12 , V_13 ) ;
break;
}
}
V_2 -> V_66 = ( V_118 + 7 ) / 8 ;
V_6 = F_4 ( V_2 ,
V_2 -> V_127 ,
V_116 ,
sizeof( V_116 ) ) ;
if ( V_6 != sizeof( V_116 ) ) {
F_3 ( & V_42 -> V_12 , L_13 ,
V_13 ) ;
return - V_22 ;
}
V_2 -> V_67 . V_133 = 4 ;
V_2 -> V_67 . V_134 = 0 ;
V_2 -> V_67 . V_135 = V_116 [ 0 ] ;
V_2 -> V_67 . V_136 = V_116 [ 1 ] ;
V_2 -> V_67 . V_137 [ 0 ] = V_116 [ 2 ] ;
V_2 -> V_67 . V_137 [ 1 ] = V_116 [ 3 ] ;
V_2 -> V_67 . V_138 [ 0 ] = V_116 [ 4 ] & V_115 ;
V_2 -> V_67 . V_138 [ 1 ] = V_116 [ 5 ] & V_47 ;
V_2 -> V_67 . V_138 [ 2 ] = V_116 [ 6 ] & V_115 ;
V_2 -> V_67 . V_139 = ( ( V_116 [ 7 ] & V_140 ) << 8 ) |
( V_116 [ 8 ] & V_140 ) ;
V_2 -> V_67 . V_141 =
( ( V_116 [ 9 ] & V_140 ) << 8 ) |
( V_116 [ 10 ] & V_140 ) ;
memcpy ( V_2 -> V_67 . V_142 , & V_116 [ 11 ] , 10 ) ;
if ( V_2 -> V_67 . V_135 != 1 )
F_3 ( & V_42 -> V_12 , L_14 ,
V_13 , V_2 -> V_67 . V_135 ) ;
F_17 (rfi, &pdata->rmi4_mod_info.support_fn_list, link)
V_119 += V_24 -> V_68 ;
if ( V_119 ) {
V_64 = & ( V_2 -> V_67 ) ;
F_17 (rfi, &rmi->support_fn_list, link) {
if ( V_24 -> V_68 ) {
if ( V_24 -> V_59 ==
V_60 ) {
V_6 = F_22
( V_2 , V_24 ) ;
if ( V_6 < 0 )
return V_6 ;
} else
F_3 ( & V_42 -> V_12 ,
L_15 ,
V_13 ) ;
V_120 = V_2 -> V_128 + 1 +
V_24 -> V_69 ;
V_6 = F_8 ( V_2 ,
V_120 ,
V_24 -> V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
}
}
}
return 0 ;
}
static int T_2 F_29
( struct V_8 * V_42 , const struct V_143 * V_144 )
{
int V_6 ;
unsigned char V_62 [ 4 ] ;
struct V_1 * V_145 ;
const struct V_146 * V_147 =
V_42 -> V_12 . V_148 ;
if ( ! F_30 ( V_42 -> V_149 ,
V_150 ) ) {
F_3 ( & V_42 -> V_12 , L_16 ) ;
return - V_22 ;
}
if ( ! V_147 ) {
F_3 ( & V_42 -> V_12 , L_17 , V_13 ) ;
return - V_151 ;
}
V_145 = F_31 ( sizeof( struct V_1 ) * 2 ,
V_129 ) ;
if ( ! V_145 ) {
F_3 ( & V_42 -> V_12 , L_18 , V_13 ) ;
return - V_130 ;
}
V_145 -> V_53 = F_32 () ;
if ( V_145 -> V_53 == NULL ) {
F_3 ( & V_42 -> V_12 , L_19 ,
V_13 ) ;
V_6 = - V_130 ;
goto V_152;
}
V_145 -> V_153 = F_33 ( & V_42 -> V_12 , L_20 ) ;
if ( F_34 ( V_145 -> V_153 ) ) {
F_3 ( & V_42 -> V_12 , L_21 ,
V_13 ) ;
V_6 = F_35 ( V_145 -> V_153 ) ;
goto V_154;
}
V_6 = F_36 ( V_145 -> V_153 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_42 -> V_12 , L_22 ,
V_13 ) ;
goto V_155;
}
F_37 ( & V_145 -> V_72 ) ;
V_145 -> V_8 = V_42 ;
V_145 -> V_11 = V_156 ;
V_145 -> V_48 = V_147 ;
V_145 -> V_73 = false ;
F_38 ( & ( V_145 -> V_131 ) ) ;
F_38 ( & ( V_145 -> V_18 ) ) ;
V_6 = F_23 ( V_145 ) ;
if ( V_6 ) {
F_3 ( & V_42 -> V_12 , L_23 ,
V_13 ) ;
goto V_157;
}
F_39 ( V_42 , V_145 ) ;
V_145 -> V_53 -> V_158 = V_159 ;
V_145 -> V_53 -> V_160 = L_24 ;
V_145 -> V_53 -> V_161 . V_162 = V_163 ;
V_145 -> V_53 -> V_12 . V_164 = & V_42 -> V_12 ;
F_40 ( V_145 -> V_53 , V_145 ) ;
F_41 ( V_165 , V_145 -> V_53 -> V_166 ) ;
F_41 ( V_167 , V_145 -> V_53 -> V_166 ) ;
F_41 ( V_168 , V_145 -> V_53 -> V_166 ) ;
F_42 ( V_145 -> V_53 , V_55 , 0 ,
V_145 -> V_50 , 0 , 0 ) ;
F_42 ( V_145 -> V_53 , V_56 , 0 ,
V_145 -> V_52 , 0 , 0 ) ;
F_42 ( V_145 -> V_53 , V_54 , 0 ,
V_169 , 0 , 0 ) ;
F_4 ( V_145 ,
V_145 -> V_65 + 1 , V_62 ,
V_145 -> V_66 ) ;
V_6 = F_43 ( V_147 -> V_170 , NULL ,
F_18 ,
V_147 -> V_171 ,
V_159 , V_145 ) ;
if ( V_6 ) {
F_3 ( & V_42 -> V_12 , L_25 ,
V_13 , V_147 -> V_170 ) ;
goto V_157;
}
V_6 = F_44 ( V_145 -> V_53 ) ;
if ( V_6 ) {
F_3 ( & V_42 -> V_12 , L_26 , V_13 ) ;
goto V_172;
}
return V_6 ;
V_172:
F_45 ( V_147 -> V_170 , V_145 ) ;
V_157:
F_46 ( V_145 -> V_153 ) ;
V_155:
F_47 ( V_145 -> V_153 ) ;
V_154:
F_48 ( V_145 -> V_53 ) ;
V_145 -> V_53 = NULL ;
V_152:
F_26 ( V_145 ) ;
return V_6 ;
}
static int T_3 F_49 ( struct V_8 * V_42 )
{
struct V_1 * V_145 = F_50 ( V_42 ) ;
const struct V_146 * V_2 = V_145 -> V_48 ;
V_145 -> V_73 = true ;
F_51 ( & V_145 -> V_72 ) ;
F_45 ( V_2 -> V_170 , V_145 ) ;
F_52 ( V_145 -> V_53 ) ;
F_46 ( V_145 -> V_153 ) ;
F_47 ( V_145 -> V_153 ) ;
F_26 ( V_145 ) ;
return 0 ;
}
static int F_53 ( struct V_173 * V_12 )
{
int V_6 ;
unsigned char V_62 ;
struct V_1 * V_145 = F_54 ( V_12 ) ;
const struct V_146 * V_2 = V_145 -> V_48 ;
V_145 -> V_73 = true ;
F_55 ( V_2 -> V_170 ) ;
V_6 = F_4 ( V_145 ,
V_145 -> V_65 + 1 ,
& V_62 ,
V_145 -> V_66 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_145 ,
V_145 -> V_128 + 1 ,
( V_62 & ~ V_174 ) ) ;
if ( V_6 < 0 )
return V_6 ;
F_46 ( V_145 -> V_153 ) ;
return 0 ;
}
static int F_56 ( struct V_173 * V_12 )
{
int V_6 ;
unsigned char V_62 ;
struct V_1 * V_145 = F_54 ( V_12 ) ;
const struct V_146 * V_2 = V_145 -> V_48 ;
F_36 ( V_145 -> V_153 ) ;
F_57 ( V_2 -> V_170 ) ;
V_145 -> V_73 = false ;
V_6 = F_4 ( V_145 ,
V_145 -> V_65 + 1 ,
& V_62 ,
V_145 -> V_66 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_145 ,
V_145 -> V_128 + 1 ,
( V_62 | V_174 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_175 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_175 ) ;
}
