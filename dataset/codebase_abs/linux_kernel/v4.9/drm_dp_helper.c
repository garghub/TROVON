static T_1 F_1 ( const T_1 V_1 [ V_2 ] , int V_3 )
{
return V_1 [ V_3 - V_4 ] ;
}
static T_1 F_2 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_4 + ( V_5 >> 1 ) ;
int V_7 = ( V_5 & 1 ) * 4 ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( V_8 >> V_7 ) & 0xf ;
}
bool F_3 ( const T_1 V_1 [ V_2 ] ,
int V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
int V_5 ;
V_10 = F_1 ( V_1 ,
V_12 ) ;
if ( ( V_10 & V_13 ) == 0 )
return false ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_11 = F_2 ( V_1 , V_5 ) ;
if ( ( V_11 & V_14 ) != V_14 )
return false ;
}
return true ;
}
bool F_4 ( const T_1 V_1 [ V_2 ] ,
int V_9 )
{
int V_5 ;
T_1 V_11 ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_11 = F_2 ( V_1 , V_5 ) ;
if ( ( V_11 & V_15 ) == 0 )
return false ;
}
return true ;
}
T_1 F_5 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_16 + ( V_5 >> 1 ) ;
int V_7 = ( ( V_5 & 1 ) ?
V_17 :
V_18 ) ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( ( V_8 >> V_7 ) & 0x3 ) << V_19 ;
}
T_1 F_6 ( const T_1 V_1 [ V_2 ] ,
int V_5 )
{
int V_6 = V_16 + ( V_5 >> 1 ) ;
int V_7 = ( ( V_5 & 1 ) ?
V_20 :
V_21 ) ;
T_1 V_8 = F_1 ( V_1 , V_6 ) ;
return ( ( V_8 >> V_7 ) & 0x3 ) << V_22 ;
}
void F_7 ( const T_1 V_23 [ V_24 ] ) {
if ( V_23 [ V_25 ] == 0 )
F_8 ( 100 ) ;
else
F_9 ( V_23 [ V_25 ] * 4 ) ;
}
void F_10 ( const T_1 V_23 [ V_24 ] ) {
if ( V_23 [ V_25 ] == 0 )
F_8 ( 400 ) ;
else
F_9 ( V_23 [ V_25 ] * 4 ) ;
}
T_1 F_11 ( int V_26 )
{
switch ( V_26 ) {
case 162000 :
default:
return V_27 ;
case 270000 :
return V_28 ;
case 540000 :
return V_29 ;
}
}
int F_12 ( T_1 V_30 )
{
switch ( V_30 ) {
case V_27 :
default:
return 162000 ;
case V_28 :
return 270000 ;
case V_29 :
return 540000 ;
}
}
static int F_13 ( struct V_31 * V_32 , T_1 V_33 ,
unsigned int V_34 , void * V_35 , T_2 V_36 )
{
struct V_37 V_38 ;
unsigned int V_39 , V_40 ;
int V_41 = 0 , V_42 = 0 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_43 = V_34 ;
V_38 . V_33 = V_33 ;
V_38 . V_35 = V_35 ;
V_38 . V_36 = V_36 ;
F_14 ( & V_32 -> V_44 ) ;
for ( V_39 = 0 ; V_39 < 32 ; V_39 ++ ) {
if ( V_42 != 0 && V_42 != - V_45 ) {
F_15 ( V_46 ,
V_46 + 100 ) ;
}
V_42 = V_32 -> V_47 ( V_32 , & V_38 ) ;
if ( V_42 >= 0 ) {
V_40 = V_38 . V_48 & V_49 ;
if ( V_40 == V_50 ) {
if ( V_42 == V_36 )
goto V_51;
V_42 = - V_52 ;
} else
V_42 = - V_53 ;
}
if ( ! V_41 )
V_41 = V_42 ;
}
F_16 ( L_1 , V_41 ) ;
V_42 = V_41 ;
V_51:
F_17 ( & V_32 -> V_44 ) ;
return V_42 ;
}
T_3 F_18 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
int V_42 ;
V_42 = F_13 ( V_32 , V_54 , V_55 , V_35 ,
1 ) ;
if ( V_42 != 1 )
return V_42 ;
return F_13 ( V_32 , V_54 , V_34 , V_35 ,
V_36 ) ;
}
T_3 F_19 ( struct V_31 * V_32 , unsigned int V_34 ,
void * V_35 , T_2 V_36 )
{
return F_13 ( V_32 , V_56 , V_34 , V_35 ,
V_36 ) ;
}
int F_20 ( struct V_31 * V_32 ,
T_1 V_57 [ V_2 ] )
{
return F_18 ( V_32 , V_4 , V_57 ,
V_2 ) ;
}
int F_21 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_60 [ 3 ] ;
int V_41 ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_41 = F_18 ( V_32 , V_55 , V_60 , sizeof( V_60 ) ) ;
if ( V_41 < 0 )
return V_41 ;
V_59 -> V_61 = V_60 [ 0 ] ;
V_59 -> V_62 = F_12 ( V_60 [ 1 ] ) ;
V_59 -> V_63 = V_60 [ 2 ] & V_64 ;
if ( V_60 [ 2 ] & V_65 )
V_59 -> V_66 |= V_67 ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_68 ;
int V_41 ;
if ( V_59 -> V_61 < 0x11 )
return 0 ;
V_41 = F_23 ( V_32 , V_69 , & V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
V_68 &= ~ V_70 ;
V_68 |= V_71 ;
V_41 = F_24 ( V_32 , V_69 , V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
F_15 ( 1000 , 2000 ) ;
return 0 ;
}
int F_25 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_68 ;
int V_41 ;
if ( V_59 -> V_61 < 0x11 )
return 0 ;
V_41 = F_23 ( V_32 , V_69 , & V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
V_68 &= ~ V_70 ;
V_68 |= V_72 ;
V_41 = F_24 ( V_32 , V_69 , V_68 ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
int F_26 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
T_1 V_60 [ 2 ] ;
int V_41 ;
V_60 [ 0 ] = F_11 ( V_59 -> V_62 ) ;
V_60 [ 1 ] = V_59 -> V_63 ;
if ( V_59 -> V_66 & V_67 )
V_60 [ 1 ] |= V_73 ;
V_41 = F_19 ( V_32 , V_74 , V_60 , sizeof( V_60 ) ) ;
if ( V_41 < 0 )
return V_41 ;
return 0 ;
}
int F_27 ( const T_1 V_23 [ V_24 ] ,
const T_1 V_75 [ 4 ] )
{
int type = V_75 [ 0 ] & V_76 ;
bool V_77 = V_23 [ V_78 ] &
V_79 ;
if ( ! V_77 )
return 0 ;
switch ( type ) {
case V_80 :
return V_75 [ 1 ] * 8 * 1000 ;
case V_81 :
case V_82 :
case V_83 :
return V_75 [ 1 ] * 2500 ;
default:
return 0 ;
}
}
int F_28 ( const T_1 V_23 [ V_24 ] ,
const T_1 V_75 [ 4 ] )
{
int type = V_75 [ 0 ] & V_76 ;
bool V_77 = V_23 [ V_78 ] &
V_79 ;
int V_84 ;
if ( ! V_77 )
return 0 ;
switch ( type ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_84 = V_75 [ 2 ] & V_85 ;
switch ( V_84 ) {
case V_86 :
return 8 ;
case V_87 :
return 10 ;
case V_88 :
return 12 ;
case V_89 :
return 16 ;
}
default:
return 0 ;
}
}
int F_29 ( struct V_31 * V_32 , char V_90 [ 6 ] )
{
return F_18 ( V_32 , V_91 , V_90 , 6 ) ;
}
void F_30 ( struct V_92 * V_93 ,
const T_1 V_23 [ V_24 ] ,
const T_1 V_75 [ 4 ] , struct V_31 * V_32 )
{
bool V_77 = V_23 [ V_78 ] &
V_79 ;
int V_94 ;
int V_84 ;
char V_90 [ 6 ] ;
int V_95 ;
T_4 V_96 [ 2 ] ;
int type = V_75 [ 0 ] & V_76 ;
bool V_97 = V_23 [ V_78 ] &
V_98 ;
F_31 ( V_93 , L_2 ,
V_97 ? L_3 : L_4 ) ;
if ( ! V_97 )
return;
switch ( type ) {
case V_99 :
F_32 ( V_93 , L_5 ) ;
break;
case V_80 :
F_32 ( V_93 , L_6 ) ;
break;
case V_81 :
F_32 ( V_93 , L_7 ) ;
break;
case V_82 :
F_32 ( V_93 , L_8 ) ;
break;
case V_100 :
F_32 ( V_93 , L_9 ) ;
break;
case V_83 :
F_32 ( V_93 , L_10 ) ;
break;
case V_101 :
F_32 ( V_93 , L_11 ) ;
break;
default:
F_32 ( V_93 , L_12 ) ;
}
F_29 ( V_32 , V_90 ) ;
F_31 ( V_93 , L_13 , V_90 ) ;
V_95 = F_18 ( V_32 , V_102 , & V_96 [ 0 ] , 1 ) ;
if ( V_95 > 0 )
F_31 ( V_93 , L_14 ,
( V_96 [ 0 ] & 0xf0 ) >> 4 , V_96 [ 0 ] & 0xf ) ;
V_95 = F_18 ( V_32 , V_103 , & V_96 , 2 ) ;
if ( V_95 > 0 )
F_31 ( V_93 , L_15 , V_96 [ 0 ] , V_96 [ 1 ] ) ;
if ( V_77 ) {
V_94 = F_27 ( V_23 , V_75 ) ;
if ( V_94 > 0 ) {
if ( type == V_80 )
F_31 ( V_93 , L_16 , V_94 ) ;
else
F_31 ( V_93 , L_17 , V_94 ) ;
}
V_84 = F_28 ( V_23 , V_75 ) ;
if ( V_84 > 0 )
F_31 ( V_93 , L_18 , V_84 ) ;
}
}
static T_5 F_33 ( struct V_104 * V_105 )
{
return V_106 | V_107 |
V_108 |
V_109 |
V_110 ;
}
static void F_34 ( struct V_37 * V_38 )
{
if ( ( V_38 -> V_33 & ~ V_111 ) == V_112 ) {
V_38 -> V_33 &= V_111 ;
V_38 -> V_33 |= V_113 ;
}
}
static int F_35 ( const struct V_37 * V_38 )
{
int V_95 = V_114 + V_115 + V_116 +
V_117 + V_118 + V_119 ;
if ( ( V_38 -> V_33 & V_120 ) == 0 )
V_95 += V_38 -> V_36 * 8 ;
return V_95 ;
}
static int F_36 ( const struct V_37 * V_38 )
{
int V_95 = V_114 + V_115 + V_116 +
V_117 + V_121 ;
if ( V_38 -> V_33 & V_120 )
V_95 += V_38 -> V_36 * 8 ;
return V_95 ;
}
static int F_37 ( const struct V_37 * V_38 ,
int V_122 )
{
return F_38 ( ( V_123 + V_124 +
V_38 -> V_36 * V_125 +
V_126 ) * 1000 , V_122 ) ;
}
static int F_39 ( const struct V_37 * V_38 ,
int V_122 )
{
int V_127 = F_35 ( V_38 ) +
F_36 ( V_38 ) ;
int V_128 = F_37 ( V_38 , V_122 ) ;
return F_38 ( V_128 , V_127 + V_46 ) ;
}
static int F_40 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
unsigned int V_39 , V_129 ;
int V_42 ;
int V_130 = F_41 ( 7 , F_39 ( V_38 , V_131 ) ) ;
for ( V_39 = 0 , V_129 = 0 ; V_39 < ( V_130 + V_129 ) ; V_39 ++ ) {
V_42 = V_32 -> V_47 ( V_32 , V_38 ) ;
if ( V_42 < 0 ) {
if ( V_42 == - V_132 )
continue;
if ( V_42 == - V_45 )
F_42 ( L_19 ) ;
else
F_16 ( L_20 , V_42 ) ;
return V_42 ;
}
switch ( V_38 -> V_48 & V_49 ) {
case V_50 :
break;
case V_133 :
F_16 ( L_21 , V_42 , V_38 -> V_36 ) ;
return - V_134 ;
case V_135 :
F_16 ( L_22 ) ;
F_15 ( V_46 , V_46 + 100 ) ;
continue;
default:
F_43 ( L_23 , V_38 -> V_48 ) ;
return - V_134 ;
}
switch ( V_38 -> V_48 & V_136 ) {
case V_137 :
if ( V_42 != V_38 -> V_36 )
F_34 ( V_38 ) ;
return V_42 ;
case V_138 :
F_16 ( L_24 , V_42 , V_38 -> V_36 ) ;
V_32 -> V_139 ++ ;
return - V_134 ;
case V_140 :
F_16 ( L_25 ) ;
V_32 -> V_141 ++ ;
if ( V_129 < 7 )
V_129 ++ ;
F_15 ( V_46 , V_46 + 100 ) ;
F_34 ( V_38 ) ;
continue;
default:
F_43 ( L_26 , V_38 -> V_48 ) ;
return - V_134 ;
}
}
F_16 ( L_27 ) ;
return - V_134 ;
}
static void F_44 ( struct V_37 * V_38 ,
const struct V_142 * V_142 )
{
V_38 -> V_33 = ( V_142 -> V_143 & V_144 ) ?
V_120 : V_112 ;
V_38 -> V_33 |= V_111 ;
}
static int F_45 ( struct V_31 * V_32 , struct V_37 * V_145 )
{
int V_41 , V_42 = V_145 -> V_36 ;
struct V_37 V_38 = * V_145 ;
while ( V_38 . V_36 > 0 ) {
V_41 = F_40 ( V_32 , & V_38 ) ;
if ( V_41 <= 0 )
return V_41 == 0 ? - V_52 : V_41 ;
if ( V_41 < V_38 . V_36 && V_41 < V_42 ) {
F_16 ( L_28 ,
V_38 . V_36 , V_41 ) ;
V_42 = V_41 ;
}
V_38 . V_36 -= V_41 ;
V_38 . V_35 += V_41 ;
}
return V_42 ;
}
static int F_46 ( struct V_104 * V_105 , struct V_142 * V_146 ,
int V_147 )
{
struct V_31 * V_32 = V_105 -> V_148 ;
unsigned int V_6 , V_149 ;
unsigned V_150 ;
struct V_37 V_38 ;
int V_41 = 0 ;
V_151 = F_47 ( V_151 , 1 , V_152 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
for ( V_6 = 0 ; V_6 < V_147 ; V_6 ++ ) {
V_38 . V_43 = V_146 [ V_6 ] . V_153 ;
F_44 ( & V_38 , & V_146 [ V_6 ] ) ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
V_41 = F_40 ( V_32 , & V_38 ) ;
F_44 ( & V_38 , & V_146 [ V_6 ] ) ;
if ( V_41 < 0 )
break;
V_150 = V_151 ;
for ( V_149 = 0 ; V_149 < V_146 [ V_6 ] . V_95 ; V_149 += V_38 . V_36 ) {
V_38 . V_35 = V_146 [ V_6 ] . V_154 + V_149 ;
V_38 . V_36 = F_48 ( V_150 , V_146 [ V_6 ] . V_95 - V_149 ) ;
V_41 = F_45 ( V_32 , & V_38 ) ;
F_44 ( & V_38 , & V_146 [ V_6 ] ) ;
if ( V_41 < 0 )
break;
V_150 = V_41 ;
}
if ( V_41 < 0 )
break;
}
if ( V_41 >= 0 )
V_41 = V_147 ;
V_38 . V_33 &= ~ V_111 ;
V_38 . V_35 = NULL ;
V_38 . V_36 = 0 ;
( void ) F_40 ( V_32 , & V_38 ) ;
return V_41 ;
}
static struct V_31 * F_49 ( struct V_104 * V_155 )
{
return F_50 ( V_155 , struct V_31 , V_156 ) ;
}
static void F_51 ( struct V_104 * V_155 , unsigned int V_143 )
{
F_14 ( & F_49 ( V_155 ) -> V_44 ) ;
}
static int F_52 ( struct V_104 * V_155 , unsigned int V_143 )
{
return F_53 ( & F_49 ( V_155 ) -> V_44 ) ;
}
static void F_54 ( struct V_104 * V_155 , unsigned int V_143 )
{
F_17 ( & F_49 ( V_155 ) -> V_44 ) ;
}
void F_55 ( struct V_31 * V_32 )
{
F_56 ( & V_32 -> V_44 ) ;
V_32 -> V_156 . V_157 = & V_158 ;
V_32 -> V_156 . V_148 = V_32 ;
V_32 -> V_156 . V_159 = 3 ;
V_32 -> V_156 . V_160 = & V_161 ;
}
int F_57 ( struct V_31 * V_32 )
{
int V_42 ;
if ( ! V_32 -> V_156 . V_157 )
F_55 ( V_32 ) ;
V_32 -> V_156 . V_162 = V_163 ;
V_32 -> V_156 . V_164 = V_165 ;
V_32 -> V_156 . V_166 . V_167 = V_32 -> V_166 ;
V_32 -> V_156 . V_166 . V_168 = V_32 -> V_166 -> V_168 ;
F_58 ( V_32 -> V_156 . V_169 , V_32 -> V_169 ? V_32 -> V_169 : F_59 ( V_32 -> V_166 ) ,
sizeof( V_32 -> V_156 . V_169 ) ) ;
V_42 = F_60 ( V_32 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_61 ( & V_32 -> V_156 ) ;
if ( V_42 ) {
F_62 ( V_32 ) ;
return V_42 ;
}
return 0 ;
}
void F_63 ( struct V_31 * V_32 )
{
F_62 ( V_32 ) ;
F_64 ( & V_32 -> V_156 ) ;
}
int F_65 ( const T_1 V_170 [ V_171 ] )
{
static const T_6 V_172 [] = {
F_66 ( 330 ) ,
F_66 ( 275 ) ,
F_66 ( 165 ) ,
F_66 ( 110 ) ,
F_66 ( 55 ) ,
F_66 ( 0 ) ,
} ;
int V_6 ;
V_6 = ( V_170 [ 1 ] & V_173 ) >> V_174 ;
if ( V_6 >= F_67 ( V_172 ) )
return - V_175 ;
return V_172 [ V_6 ] ;
}
