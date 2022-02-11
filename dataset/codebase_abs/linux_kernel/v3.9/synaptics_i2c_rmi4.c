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
int V_6 ;
int V_31 , V_32 ;
int V_33 , V_34 ;
unsigned short V_35 ;
unsigned short V_36 ;
unsigned char V_37 ;
unsigned char V_38 [ 2 ] ;
unsigned char V_21 [ V_39 ] ;
unsigned char V_40 = V_2 -> V_40 ;
struct V_8 * V_41 = V_2 -> V_8 ;
struct V_42 * V_42 = V_2 -> V_42 ;
V_27 = ( V_40 + 3 ) / 4 ;
V_35 = V_24 -> V_43 . V_35 ;
V_6 = F_4 ( V_2 , V_35 , V_38 ,
V_27 ) ;
if ( V_6 != V_27 ) {
F_3 ( & V_41 -> V_12 , L_3 ,
V_13 ) ;
return 0 ;
}
V_37 = V_24 -> V_44 ;
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ ) {
V_28 = V_26 / 4 ;
V_29 = ( V_26 % 4 ) * 2 ;
V_30 = ( V_38 [ V_28 ] >> V_29 ) & 3 ;
F_10 ( V_42 , V_26 ) ;
F_11 ( V_42 , V_45 ,
V_30 != 0 ) ;
if ( V_30 ) {
V_36 = V_35 +
( ( V_26 * V_37 ) +
V_27 ) ;
V_6 = F_4 ( V_2 ,
V_36 , V_21 ,
V_37 ) ;
if ( V_6 != V_37 ) {
F_3 ( & V_41 -> V_12 , L_4 ,
V_13 ) ;
return 0 ;
}
V_31 = ( V_21 [ 0 ] << 4 ) | ( V_21 [ 2 ] & V_46 ) ;
V_32 = ( V_21 [ 1 ] << 4 ) | ( ( V_21 [ 2 ] >> 4 ) & V_46 ) ;
V_34 = ( V_21 [ 3 ] >> 4 ) & V_46 ;
V_33 = ( V_21 [ 3 ] & V_46 ) ;
if ( V_2 -> V_47 -> V_48 )
V_31 = V_2 -> V_49 - V_31 ;
if ( V_2 -> V_47 -> V_50 )
V_32 = V_2 -> V_51 - V_32 ;
F_12 ( V_42 , V_52 ,
F_13 ( V_33 , V_34 ) ) ;
F_12 ( V_42 , V_53 , V_31 ) ;
F_12 ( V_42 , V_54 , V_32 ) ;
V_25 ++ ;
}
}
F_14 ( V_42 ) ;
F_15 ( V_42 ) ;
return V_25 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
int V_55 = 0 ;
struct V_8 * V_41 = V_2 -> V_8 ;
static int V_56 ;
if ( V_24 -> V_57 != V_58 ) {
V_56 ++ ;
if ( V_56 < V_59 )
F_3 ( & V_41 -> V_12 , L_5 ,
V_13 ) ;
} else
V_55 = F_9 ( V_2 , V_24 ) ;
return V_55 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned char V_60 [ 4 ] ;
int V_55 = 0 ;
unsigned int V_6 ;
struct V_23 * V_24 ;
struct V_61 * V_62 ;
struct V_8 * V_41 = V_2 -> V_8 ;
V_6 = F_4 ( V_2 ,
V_2 -> V_63 + 1 ,
V_60 ,
V_2 -> V_64 ) ;
if ( V_6 != V_2 -> V_64 ) {
F_3 ( & V_41 -> V_12 ,
L_6 ) ;
return 0 ;
}
V_62 = & ( V_2 -> V_65 ) ;
F_18 (rfi, &rmi->support_fn_list, link) {
if ( V_24 -> V_66 ) {
if ( V_60 [ V_24 -> V_67 ] &
V_24 -> V_68 )
V_55 = F_16 ( V_2 ,
V_24 ) ;
}
}
return V_55 ;
}
static T_1 F_19 ( int V_69 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
int V_25 ;
do {
V_25 = F_17 ( V_2 ) ;
if ( V_25 )
F_20 ( V_2 -> V_70 , V_2 -> V_71 ,
F_21 ( 1 ) ) ;
else
break;
} while ( ! V_2 -> V_71 );
return V_72 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_73 * V_74 ,
unsigned int V_75 )
{
unsigned char V_76 [ V_77 ] ;
unsigned short V_78 ;
unsigned char V_79 ;
unsigned char V_80 ;
unsigned char V_81 , V_82 ;
unsigned int V_83 ;
int V_84 , V_85 , V_86 ;
int V_87 , V_88 ;
int V_89 , V_90 ;
int V_91 , V_92 ;
int V_93 ;
int V_94 ;
int V_6 ;
struct V_8 * V_41 = V_2 -> V_8 ;
V_24 -> V_43 . V_95 = V_74 -> V_95 ;
V_24 -> V_43 . V_35 = V_74 -> V_35 ;
V_24 -> V_43 . V_96 = V_74 -> V_96 ;
V_24 -> V_43 . V_57 = V_74 -> V_57 ;
V_24 -> V_57 = V_74 -> V_57 ;
V_24 -> V_66 = V_74 -> V_96 ;
V_24 -> V_43 . V_97 = V_74 -> V_97 ;
V_24 -> V_43 . V_98 = V_74 -> V_98 ;
V_6 = F_4 ( V_2 , V_74 -> V_95 ,
V_76 ,
sizeof( V_76 ) ) ;
if ( V_6 != sizeof( V_76 ) ) {
F_3 ( & V_41 -> V_12 , L_7 ,
V_13 ) ;
return V_6 ;
}
if ( ( V_76 [ 1 ] & V_99 ) <= 4 )
V_24 -> V_100 = ( V_76 [ 1 ] & V_99 ) + 1 ;
else {
if ( ( V_76 [ 1 ] & V_99 ) == 5 )
V_24 -> V_100 = 10 ;
}
V_2 -> V_40 = V_24 -> V_100 ;
V_24 -> V_67 = ( V_75 + 7 ) / 8 ;
if ( V_24 -> V_67 != 0 )
V_24 -> V_67 -= 1 ;
V_78 = V_75 % 8 ;
V_24 -> V_68 = 0 ;
for ( V_94 = V_78 ;
V_94 < ( ( V_74 -> V_96 & V_99 ) + V_78 ) ; V_94 ++ )
V_24 -> V_68 |= 1 << V_94 ;
V_79 = V_76 [ 5 ] & V_101 ;
V_80 = 3 + ( 2 * ( V_79 == 0 ? 1 : 0 ) ) ;
V_24 -> V_44 = V_80 ;
V_81 = V_76 [ 7 ] ;
V_82 = V_76 [ 8 ] ;
V_84 = V_81 & V_102 ;
V_85 = V_81 & V_103 ;
V_86 = V_81 & V_104 ;
V_89 = V_81 & V_105 ;
V_90 = V_81 & V_106 ;
V_92 = V_82 & V_107 ;
V_93 = V_76 [ 1 ] & V_108 ;
V_87 = V_81 & V_109 ;
V_88 = V_81 & V_110 ;
V_91 = V_82 & V_111 ;
V_83 =
( ( V_24 -> V_100 + 3 ) / 4 ) +
( V_80 * V_24 -> V_100 ) +
2 * V_93 +
! ! ( V_81 ) +
( V_81 || V_82 ) +
! ! ( V_84 | V_85 ) +
2 * ! ! ( V_85 ) ;
return V_6 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
unsigned char V_21 [ V_112 ] ;
int V_6 = 0 ;
struct V_8 * V_41 = V_2 -> V_8 ;
V_6 = F_4 ( V_2 ,
V_24 -> V_43 . V_95 ,
V_21 , V_77 ) ;
if ( V_6 != V_77 )
F_3 ( & V_41 -> V_12 , L_8 ,
V_13 ) ;
else {
V_6 = F_4 ( V_2 ,
V_24 -> V_43 . V_97 ,
V_21 , V_113 ) ;
if ( V_6 != V_113 ) {
F_3 ( & V_41 -> V_12 ,
L_9 ,
V_13 ) ;
return V_6 ;
}
V_2 -> V_49 = ( ( V_21 [ 6 ] & V_10 ) << 0 ) |
( ( V_21 [ 7 ] & V_46 ) << 8 ) ;
V_2 -> V_51 = ( ( V_21 [ 8 ] & V_114 ) << 0 ) |
( ( V_21 [ 9 ] & V_46 ) << 8 ) ;
}
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_94 ;
int V_6 ;
unsigned char V_115 [ V_116 ] ;
unsigned char V_117 = 0 ;
int V_118 = 0 ;
unsigned int V_119 ;
struct V_23 * V_24 ;
struct V_73 V_120 ;
struct V_61 * V_62 ;
struct V_8 * V_41 = V_2 -> V_8 ;
F_25 ( & V_2 -> V_65 . V_121 ) ;
for ( V_94 = V_122 ; V_94 > V_123 ;
V_94 -= V_124 ) {
V_6 = F_4 ( V_2 , V_94 ,
( unsigned char * ) & V_120 ,
sizeof( V_120 ) ) ;
if ( V_6 != sizeof( V_120 ) ) {
F_3 ( & V_41 -> V_12 , L_10 , V_13 ) ;
return - V_22 ;
}
V_24 = NULL ;
if ( V_120 . V_57 ) {
switch ( V_120 . V_57 & V_10 ) {
case V_125 :
V_2 -> V_126 =
V_120 . V_95 ;
V_2 -> V_127 =
V_120 . V_97 ;
V_2 -> V_63 =
V_120 . V_35 ;
break;
case V_58 :
if ( V_120 . V_96 ) {
V_24 = F_26 ( sizeof( * V_24 ) ,
V_128 ) ;
if ( ! V_24 )
return - V_129 ;
V_6 = F_22
( V_2 , V_24 ,
& V_120 ,
V_117 ) ;
if ( V_6 < 0 ) {
F_27 ( V_24 ) ;
return V_6 ;
}
}
break;
}
V_117 += ( V_120 . V_96 & V_99 ) ;
if ( V_24 && V_120 . V_96 ) {
F_5 ( & ( V_2 -> V_130 ) ) ;
F_28 ( & V_24 -> V_131 ,
& V_2 -> V_65 . V_121 ) ;
F_7 ( & ( V_2 -> V_130 ) ) ;
}
} else {
F_29 ( & V_41 -> V_12 ,
L_11 , V_13 ) ;
break;
}
}
V_2 -> V_64 = ( V_117 + 7 ) / 8 ;
V_6 = F_4 ( V_2 ,
V_2 -> V_126 ,
V_115 ,
sizeof( V_115 ) ) ;
if ( V_6 != sizeof( V_115 ) ) {
F_3 ( & V_41 -> V_12 , L_12 ,
V_13 ) ;
return - V_22 ;
}
V_2 -> V_65 . V_132 = 4 ;
V_2 -> V_65 . V_133 = 0 ;
V_2 -> V_65 . V_134 = V_115 [ 0 ] ;
V_2 -> V_65 . V_135 = V_115 [ 1 ] ;
V_2 -> V_65 . V_136 [ 0 ] = V_115 [ 2 ] ;
V_2 -> V_65 . V_136 [ 1 ] = V_115 [ 3 ] ;
V_2 -> V_65 . V_137 [ 0 ] = V_115 [ 4 ] & V_114 ;
V_2 -> V_65 . V_137 [ 1 ] = V_115 [ 5 ] & V_46 ;
V_2 -> V_65 . V_137 [ 2 ] = V_115 [ 6 ] & V_114 ;
V_2 -> V_65 . V_138 = ( ( V_115 [ 7 ] & V_139 ) << 8 ) |
( V_115 [ 8 ] & V_139 ) ;
V_2 -> V_65 . V_140 =
( ( V_115 [ 9 ] & V_139 ) << 8 ) |
( V_115 [ 10 ] & V_139 ) ;
memcpy ( V_2 -> V_65 . V_141 , & V_115 [ 11 ] , 10 ) ;
if ( V_2 -> V_65 . V_134 != 1 )
F_3 ( & V_41 -> V_12 , L_13 ,
V_13 , V_2 -> V_65 . V_134 ) ;
F_18 (rfi, &pdata->rmi4_mod_info.support_fn_list, link)
V_118 += V_24 -> V_66 ;
if ( V_118 ) {
V_62 = & ( V_2 -> V_65 ) ;
F_18 (rfi, &rmi->support_fn_list, link) {
if ( V_24 -> V_66 ) {
if ( V_24 -> V_57 ==
V_58 ) {
V_6 = F_23
( V_2 , V_24 ) ;
if ( V_6 < 0 )
return V_6 ;
} else
F_3 ( & V_41 -> V_12 ,
L_14 ,
V_13 ) ;
V_119 = V_2 -> V_127 + 1 +
V_24 -> V_67 ;
V_6 = F_8 ( V_2 ,
V_119 ,
V_24 -> V_68 ) ;
if ( V_6 < 0 )
return V_6 ;
}
}
}
return 0 ;
}
static int F_30
( struct V_8 * V_41 , const struct V_142 * V_143 )
{
int V_6 ;
unsigned char V_60 [ 4 ] ;
struct V_1 * V_144 ;
const struct V_145 * V_146 =
V_41 -> V_12 . V_147 ;
if ( ! F_31 ( V_41 -> V_148 ,
V_149 ) ) {
F_3 ( & V_41 -> V_12 , L_15 ) ;
return - V_22 ;
}
if ( ! V_146 ) {
F_3 ( & V_41 -> V_12 , L_16 , V_13 ) ;
return - V_150 ;
}
V_144 = F_32 ( 2 , sizeof( struct V_1 ) ,
V_128 ) ;
if ( ! V_144 )
return - V_129 ;
V_144 -> V_42 = F_33 () ;
if ( V_144 -> V_42 == NULL ) {
F_3 ( & V_41 -> V_12 , L_17 ,
V_13 ) ;
V_6 = - V_129 ;
goto V_151;
}
V_144 -> V_152 = F_34 ( & V_41 -> V_12 , L_18 ) ;
if ( F_35 ( V_144 -> V_152 ) ) {
F_3 ( & V_41 -> V_12 , L_19 ,
V_13 ) ;
V_6 = F_36 ( V_144 -> V_152 ) ;
goto V_153;
}
V_6 = F_37 ( V_144 -> V_152 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_41 -> V_12 , L_20 ,
V_13 ) ;
goto V_154;
}
F_38 ( & V_144 -> V_70 ) ;
V_144 -> V_8 = V_41 ;
V_144 -> V_11 = V_155 ;
V_144 -> V_47 = V_146 ;
V_144 -> V_71 = false ;
F_39 ( & ( V_144 -> V_130 ) ) ;
F_39 ( & ( V_144 -> V_18 ) ) ;
V_6 = F_24 ( V_144 ) ;
if ( V_6 ) {
F_3 ( & V_41 -> V_12 , L_21 ,
V_13 ) ;
goto V_156;
}
F_40 ( V_41 , V_144 ) ;
V_144 -> V_42 -> V_157 = V_158 ;
V_144 -> V_42 -> V_159 = L_22 ;
V_144 -> V_42 -> V_160 . V_161 = V_162 ;
V_144 -> V_42 -> V_12 . V_163 = & V_41 -> V_12 ;
F_41 ( V_144 -> V_42 , V_144 ) ;
F_42 ( V_164 , V_144 -> V_42 -> V_165 ) ;
F_42 ( V_166 , V_144 -> V_42 -> V_165 ) ;
F_42 ( V_167 , V_144 -> V_42 -> V_165 ) ;
F_43 ( V_144 -> V_42 , V_53 , 0 ,
V_144 -> V_49 , 0 , 0 ) ;
F_43 ( V_144 -> V_42 , V_54 , 0 ,
V_144 -> V_51 , 0 , 0 ) ;
F_43 ( V_144 -> V_42 , V_52 , 0 ,
V_168 , 0 , 0 ) ;
F_44 ( V_144 -> V_42 ,
V_144 -> V_40 , 0 ) ;
F_4 ( V_144 ,
V_144 -> V_63 + 1 , V_60 ,
V_144 -> V_64 ) ;
V_6 = F_45 ( V_146 -> V_169 , NULL ,
F_19 ,
V_146 -> V_170 ,
V_158 , V_144 ) ;
if ( V_6 ) {
F_3 ( & V_41 -> V_12 , L_23 ,
V_13 , V_146 -> V_169 ) ;
goto V_156;
}
V_6 = F_46 ( V_144 -> V_42 ) ;
if ( V_6 ) {
F_3 ( & V_41 -> V_12 , L_24 , V_13 ) ;
goto V_171;
}
return V_6 ;
V_171:
F_47 ( V_146 -> V_169 , V_144 ) ;
V_156:
F_48 ( V_144 -> V_152 ) ;
V_154:
F_49 ( V_144 -> V_152 ) ;
V_153:
F_50 ( V_144 -> V_42 ) ;
V_144 -> V_42 = NULL ;
V_151:
F_27 ( V_144 ) ;
return V_6 ;
}
static int F_51 ( struct V_8 * V_41 )
{
struct V_1 * V_144 = F_52 ( V_41 ) ;
const struct V_145 * V_2 = V_144 -> V_47 ;
V_144 -> V_71 = true ;
F_53 ( & V_144 -> V_70 ) ;
F_47 ( V_2 -> V_169 , V_144 ) ;
F_54 ( V_144 -> V_42 ) ;
F_48 ( V_144 -> V_152 ) ;
F_49 ( V_144 -> V_152 ) ;
F_27 ( V_144 ) ;
return 0 ;
}
static int F_55 ( struct V_172 * V_12 )
{
int V_6 ;
unsigned char V_60 ;
struct V_1 * V_144 = F_56 ( V_12 ) ;
const struct V_145 * V_2 = V_144 -> V_47 ;
V_144 -> V_71 = true ;
F_57 ( V_2 -> V_169 ) ;
V_6 = F_4 ( V_144 ,
V_144 -> V_63 + 1 ,
& V_60 ,
V_144 -> V_64 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_144 ,
V_144 -> V_127 + 1 ,
( V_60 & ~ V_173 ) ) ;
if ( V_6 < 0 )
return V_6 ;
F_48 ( V_144 -> V_152 ) ;
return 0 ;
}
static int F_58 ( struct V_172 * V_12 )
{
int V_6 ;
unsigned char V_60 ;
struct V_1 * V_144 = F_56 ( V_12 ) ;
const struct V_145 * V_2 = V_144 -> V_47 ;
F_37 ( V_144 -> V_152 ) ;
F_59 ( V_2 -> V_169 ) ;
V_144 -> V_71 = false ;
V_6 = F_4 ( V_144 ,
V_144 -> V_63 + 1 ,
& V_60 ,
V_144 -> V_64 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_144 ,
V_144 -> V_127 + 1 ,
( V_60 | V_173 ) ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
