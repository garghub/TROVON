int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
char * V_5 , int V_6 )
{
int V_7 ;
int V_8 = F_2 ( V_2 -> V_9 , 0 ) ;
if ( V_2 -> V_10 )
return - V_11 ;
if ( V_6 > V_12 )
return - V_13 ;
if ( V_14 ) {
F_3 ( V_15 L_1
L_2 ,
V_8 ,
V_16 | V_17 | V_18 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 ) ;
}
F_4 ( & V_2 -> V_19 ) ;
V_7 = F_5 ( V_2 -> V_9 , V_8 , V_3 ,
V_16 | V_17 | V_18 ,
0x0000 , V_4 , V_2 -> V_20 , V_6 , V_21 ) ;
if ( V_7 < 0 ) {
if ( V_14 )
F_3 ( L_3 ) ;
F_6 ( & V_2 -> V_19 ) ;
return F_7 ( V_7 ) ;
}
if ( V_6 )
memcpy ( V_5 , V_2 -> V_20 , V_6 ) ;
F_6 ( & V_2 -> V_19 ) ;
if ( V_14 ) {
int V_22 ;
F_3 ( L_4 ) ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ )
F_3 ( L_5 , ( unsigned char ) V_5 [ V_22 ] ) ;
F_3 ( L_6 ) ;
}
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_7 ;
T_1 V_23 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , & V_23 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_23 ;
}
int F_9 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_8 ( V_2 , V_24 , V_4 ) ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , char * V_5 ,
int V_6 )
{
int V_7 ;
int V_8 = F_11 ( V_2 -> V_9 , 0 ) ;
if ( V_2 -> V_10 )
return - V_11 ;
if ( ( V_6 < 1 ) || ( V_6 > V_12 ) )
return - V_13 ;
if ( V_14 ) {
int V_22 ;
F_3 ( V_15 L_1
L_7 ,
V_8 ,
V_25 | V_17 | V_18 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 ) ;
for ( V_22 = 0 ; V_22 < V_6 ; V_22 ++ )
F_3 ( L_5 , ( unsigned char ) V_5 [ V_22 ] ) ;
F_3 ( L_6 ) ;
}
F_4 ( & V_2 -> V_19 ) ;
memcpy ( V_2 -> V_20 , V_5 , V_6 ) ;
V_7 = F_5 ( V_2 -> V_9 , V_8 , V_3 ,
V_25 | V_17 | V_18 ,
0x0000 , V_4 , V_2 -> V_20 , V_6 , V_21 ) ;
F_6 ( & V_2 -> V_19 ) ;
if ( V_7 < 0 )
return F_7 ( V_7 ) ;
if ( V_2 -> V_26 )
F_12 ( V_2 -> V_26 ) ;
return V_7 ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_4 , char * V_5 , int V_6 )
{
return F_10 ( V_2 , V_24 , V_4 , V_5 , V_6 ) ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_23 )
{
return F_13 ( V_2 , V_4 , & V_23 , 1 ) ;
}
int F_15 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_23 ,
T_1 V_27 )
{
int V_28 ;
T_1 V_29 ;
V_28 = F_9 ( V_2 , V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_29 = ( ( ( T_1 ) V_28 ) & ~ V_27 ) | ( V_23 & V_27 ) ;
return F_13 ( V_2 , V_4 , & V_29 , 1 ) ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_27 )
{
int V_28 ;
T_1 V_29 ;
V_28 = F_9 ( V_2 , V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_29 = ( ~ V_28 & V_27 ) | ( V_28 & ~ V_27 ) ;
return F_14 ( V_2 , V_4 , V_29 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_30 = V_31 + F_18 ( V_32 ) ;
int V_7 ;
while ( F_19 ( V_30 ) ) {
V_7 = F_9 ( V_2 , V_33 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! ( V_7 & 0x01 ) )
return 0 ;
F_12 ( 5 ) ;
}
F_20 ( L_8 ) ;
return - V_34 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_7 ;
T_1 V_35 = ( V_4 & 0x7f ) | 0x80 ;
T_2 V_23 ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_36 , & V_35 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_2 -> F_1 ( V_2 , 0 , V_37 ,
( T_1 * ) & V_23 , sizeof( V_23 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return F_22 ( V_23 ) ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_23 )
{
int V_7 ;
T_1 V_35 = V_4 & 0x7f ;
T_3 V_38 ;
V_38 = F_24 ( V_23 ) ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_37 , ( T_1 * ) & V_38 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_2 , V_36 , & V_35 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_7 , V_39 ;
enum V_40 V_41 = V_2 -> V_42 ;
if ( V_41 == V_43 )
V_41 = V_44 ;
for ( V_39 = 0 ; V_39 < F_26 ( V_45 ) ; V_39 ++ ) {
if ( V_41 == V_45 [ V_39 ] . V_46 )
V_7 = F_23 ( V_2 , V_45 [ V_39 ] . V_4 , 0x0808 ) ;
else
V_7 = F_23 ( V_2 , V_45 [ V_39 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_20 ( L_9 ,
V_45 [ V_39 ] . V_4 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_47 ;
if ( V_2 -> V_48 . V_49 ) {
if ( V_2 -> V_42 == V_44 )
V_47 = V_50 ;
else
V_47 = V_51 ;
V_7 = F_13 ( V_2 , V_52 , & V_47 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_2 -> V_48 . V_53 )
V_47 = V_54 ;
else {
switch ( V_2 -> V_42 ) {
case V_44 :
V_47 = V_54 ;
break;
default:
V_47 = V_55 ;
break;
}
}
if ( V_2 -> V_48 . V_56 && V_2 -> V_57 )
F_28 ( V_2 , V_2 -> V_48 . V_56 ) ;
else
F_28 ( V_2 , F_29 ( V_2 -> V_58 ) -> V_59 ) ;
V_7 = F_15 ( V_2 , V_60 , V_47 , 0xc0 ) ;
if ( V_7 < 0 )
return V_7 ;
F_12 ( 5 ) ;
switch ( V_2 -> V_61 . V_62 ) {
case V_63 :
break;
default:
V_7 = F_25 ( V_2 ) ;
}
return V_7 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_7 , V_39 ;
T_1 V_64 ;
if ( ! V_2 -> V_61 . V_65 )
return 0 ;
if ( V_2 -> V_61 . V_62 != V_63 ) {
for ( V_39 = 0 ; V_39 < F_26 ( V_66 ) ; V_39 ++ ) {
V_7 = F_23 ( V_2 , V_66 [ V_39 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_20 ( L_9 ,
V_66 [ V_39 ] . V_4 ) ;
}
}
V_64 = V_2 -> V_48 . V_64 & 0x7f ;
if ( ! V_2 -> V_57 )
V_64 |= V_67 ;
V_7 = F_14 ( V_2 , V_68 , V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
F_12 ( 10 ) ;
V_7 = F_27 ( V_2 ) ;
if ( V_2 -> V_61 . V_62 != V_63 ) {
int V_69 ;
F_23 ( V_2 , V_70 , 0x4200 ) ;
F_23 ( V_2 , V_71 , 0x0031 ) ;
F_23 ( V_2 , V_72 , 0xbb80 ) ;
V_69 = ( 0x1f - V_2 -> V_73 ) | ( ( 0x1f - V_2 -> V_73 ) << 8 ) ;
if ( V_2 -> V_57 )
V_69 |= 0x8000 ;
for ( V_39 = 0 ; V_39 < F_26 ( V_66 ) ; V_39 ++ ) {
if ( V_2 -> V_74 & V_66 [ V_39 ] . V_46 )
V_7 = F_23 ( V_2 , V_66 [ V_39 ] . V_4 ,
V_69 ) ;
if ( V_7 < 0 )
F_20 ( L_9 ,
V_66 [ V_39 ] . V_4 ) ;
}
if ( V_2 -> V_74 & V_75 ) {
int V_76 = F_31 ( V_2 -> V_74 ) ;
V_76 |= ( V_76 << 8 ) ;
F_23 ( V_2 , V_77 , V_76 ) ;
}
}
return V_7 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_78 , V_79 , V_80 , V_81 ;
T_4 V_82 ;
if ( ! V_2 -> V_61 . V_65 )
return 0 ;
V_81 = F_9 ( V_2 , V_83 ) ;
F_33 ( L_10 , V_81 ) ;
if ( V_81 < 0 ) {
V_81 = V_84 ;
} else if ( ( V_81 & V_85 ) == 0x00 ) {
V_2 -> V_86 = false ;
V_2 -> V_61 . V_65 = false ;
return 0 ;
} else if ( ( V_81 & V_85 ) != V_84 ) {
if ( V_2 -> V_87 < V_88 &&
( V_81 & V_85 ) ==
V_89 )
V_2 -> V_61 . V_90 = 1 ;
else if ( V_2 -> V_87 >= V_88 &&
( V_81 & V_85 ) ==
V_91 )
V_2 -> V_61 . V_90 = 5 ;
else
V_2 -> V_61 . V_90 = 3 ;
F_33 ( L_11 ,
V_2 -> V_61 . V_90 ) ;
V_2 -> V_61 . V_62 = V_63 ;
goto V_92;
}
V_2 -> V_61 . V_62 = V_93 ;
V_78 = F_21 ( V_2 , V_94 ) ;
if ( V_78 < 0 ) {
F_20 ( L_12 ) ;
V_2 -> V_61 . V_62 = V_63 ;
V_2 -> V_86 = false ;
V_2 -> V_61 . V_65 = false ;
goto V_92;
}
V_79 = F_21 ( V_2 , V_95 ) ;
if ( V_79 < 0 )
goto V_92;
V_82 = V_78 << 16 | V_79 ;
V_2 -> V_61 . V_96 = V_82 ;
F_20 ( L_13 , V_82 ) ;
V_80 = F_21 ( V_2 , V_97 ) ;
if ( V_80 < 0 )
goto V_92;
V_2 -> V_61 . V_98 = V_80 ;
F_20 ( L_14 , V_80 ) ;
if ( ( ( V_82 == 0xffffffff ) || ( V_82 == 0x83847650 ) ) && ( V_80 == 0x6a90 ) )
V_2 -> V_61 . V_62 = V_99 ;
else if ( ( V_82 >> 8 ) == 0x838476 )
V_2 -> V_61 . V_62 = V_100 ;
V_92:
switch ( V_2 -> V_61 . V_62 ) {
case V_63 :
F_33 ( L_15 ) ;
break;
case V_99 :
F_33 ( L_16 ) ;
break;
case V_100 :
F_33 ( L_17 ,
V_2 -> V_61 . V_96 & 0xff ) ;
break;
case V_93 :
F_20 ( L_18 ) ;
break;
default:
break;
}
return F_30 ( V_2 ) ;
}
const struct V_101 * F_34 ( struct V_1 * V_2 ,
enum V_102 V_103 )
{
if ( V_2 -> V_48 . V_104 ) {
T_1 V_105 = 0 ;
while ( V_2 -> V_48 . V_104 [ V_105 ] . V_103 >= 0 &&
V_2 -> V_48 . V_104 [ V_105 ] . V_103 < V_106 ) {
if ( V_2 -> V_48 . V_104 [ V_105 ] . V_103 == V_103 )
return & V_2 -> V_48 . V_104 [ V_105 ] ;
V_105 ++ ;
}
}
return NULL ;
}
int F_35 ( struct V_1 * V_2 , int V_107 )
{
int V_108 ;
const struct V_101 * V_109 = NULL ;
if ( V_2 -> V_87 == V_110 ||
V_2 -> V_87 == V_111 ||
V_2 -> V_87 == V_112 ||
V_2 -> V_87 == V_113 ) {
V_108 = F_15 ( V_2 , V_114 ,
V_107 ?
V_115 : 0x00 ,
V_115 ) ;
} else {
V_108 = F_15 ( V_2 , V_116 ,
V_107 ? 0x10 : 0x00 , 0x10 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_107 ) {
if ( V_2 -> V_48 . V_117 )
V_108 = F_14 ( V_2 , 0x13 , 0x0c ) ;
V_108 = F_14 ( V_2 , 0x48 , 0x00 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( V_2 -> V_118 == V_119 )
V_108 = F_14 ( V_2 ,
V_120 , 0x67 ) ;
else
V_108 = F_14 ( V_2 ,
V_120 , 0x37 ) ;
if ( V_108 < 0 )
return V_108 ;
F_12 ( 6 ) ;
} else {
V_108 = F_14 ( V_2 , V_120 , 0x27 ) ;
}
}
if ( V_2 -> V_118 == V_119 )
V_109 = F_34 ( V_2 , V_121 ) ;
else
V_109 = F_34 ( V_2 , V_122 ) ;
if ( V_109 )
F_15 ( V_2 , V_109 -> V_123 ,
( ! V_107 ^ V_109 -> V_124 ) ?
~ V_109 -> V_125 : V_109 -> V_125 ,
V_109 -> V_125 ) ;
return V_108 ;
}
int F_28 ( struct V_1 * V_2 , struct V_126 * V_59 )
{
int V_108 = 0 ;
if ( ! V_59 )
return V_108 ;
if ( V_2 -> V_118 != V_127 ) {
F_14 ( V_2 , 0x48 , 0x00 ) ;
if ( V_2 -> V_118 == V_119 )
F_14 ( V_2 , V_120 , 0x67 ) ;
else
F_14 ( V_2 , V_120 , 0x37 ) ;
F_12 ( 6 ) ;
}
while ( V_59 -> V_128 >= 0 ) {
if ( V_59 -> V_4 >= 0 ) {
V_108 = F_15 ( V_2 ,
V_59 -> V_4 ,
V_59 -> V_23 ,
V_59 -> V_129 ) ;
if ( V_108 < 0 )
return V_108 ;
}
if ( V_59 -> V_128 > 0 )
F_12 ( V_59 -> V_128 ) ;
V_59 ++ ;
}
return V_108 ;
}
int F_36 ( struct V_1 * V_2 , enum V_130 V_131 )
{
if ( V_2 -> V_118 == V_131 )
return 0 ;
if ( V_131 == V_127 ) {
V_2 -> V_118 = V_131 ;
return F_28 ( V_2 , V_2 -> V_48 . V_132 ) ;
}
V_2 -> V_118 = V_131 ;
if ( V_2 -> V_118 == V_133 )
return F_28 ( V_2 , V_2 -> V_48 . V_134 ) ;
else
return F_28 ( V_2 , F_29 ( V_2 -> V_58 ) -> V_59 ) ;
}
static void F_37 ( struct V_135 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
int V_39 ;
switch ( V_135 -> V_137 ) {
case 0 :
case - V_138 :
break;
case - V_139 :
case - V_140 :
case - V_141 :
return;
default:
F_38 ( L_19 , V_135 -> V_137 ) ;
break;
}
F_39 ( & V_2 -> V_142 ) ;
V_2 -> V_143 . V_144 ( V_2 , V_135 ) ;
F_40 ( & V_2 -> V_142 ) ;
for ( V_39 = 0 ; V_39 < V_135 -> V_145 ; V_39 ++ ) {
V_135 -> V_146 [ V_39 ] . V_137 = 0 ;
V_135 -> V_146 [ V_39 ] . V_147 = 0 ;
}
V_135 -> V_137 = 0 ;
V_135 -> V_137 = F_41 ( V_135 , V_148 ) ;
if ( V_135 -> V_137 ) {
F_38 ( L_20 ,
V_135 -> V_137 ) ;
}
}
void F_42 ( struct V_1 * V_2 , enum V_130 V_118 )
{
struct V_135 * V_135 ;
struct V_149 * V_150 ;
int V_39 ;
F_38 ( L_21 ,
V_118 ) ;
if ( V_118 == V_133 )
V_150 = & V_2 -> V_143 . V_151 ;
else
V_150 = & V_2 -> V_143 . V_152 ;
for ( V_39 = 0 ; V_39 < V_150 -> V_153 ; V_39 ++ ) {
V_135 = V_150 -> V_135 [ V_39 ] ;
if ( V_135 ) {
if ( ! F_43 () )
F_44 ( V_135 ) ;
else
F_45 ( V_135 ) ;
if ( V_150 -> V_154 [ V_39 ] ) {
F_46 ( V_2 -> V_9 ,
V_135 -> V_155 ,
V_150 -> V_154 [ V_39 ] ,
V_135 -> V_156 ) ;
}
F_47 ( V_135 ) ;
V_150 -> V_135 [ V_39 ] = NULL ;
}
V_150 -> V_154 [ V_39 ] = NULL ;
}
F_48 ( V_150 -> V_135 ) ;
F_48 ( V_150 -> V_154 ) ;
V_150 -> V_135 = NULL ;
V_150 -> V_154 = NULL ;
V_150 -> V_153 = 0 ;
F_35 ( V_2 , 0 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_39 ;
struct V_135 * V_135 ;
struct V_149 * V_157 = & V_2 -> V_143 . V_151 ;
F_38 ( L_22 ) ;
for ( V_39 = 0 ; V_39 < V_157 -> V_153 ; V_39 ++ ) {
V_135 = V_157 -> V_135 [ V_39 ] ;
if ( V_135 ) {
if ( ! F_43 () )
F_44 ( V_135 ) ;
else
F_45 ( V_135 ) ;
}
}
F_35 ( V_2 , 0 ) ;
}
int F_50 ( struct V_1 * V_2 , enum V_130 V_118 , int V_158 ,
int V_153 , int V_159 , int V_160 )
{
struct V_149 * V_150 ;
int V_39 ;
int V_161 , V_8 ;
struct V_135 * V_135 ;
int V_162 , V_105 ;
F_38 ( L_23 , V_118 ) ;
if ( V_118 == V_133 ) {
if ( ( V_158 && ! V_2 -> V_163 ) ||
( ! V_158 && ! V_2 -> V_164 ) ) {
F_51 ( L_24 ,
V_158 > 0 ) ;
return - V_13 ;
}
V_150 = & V_2 -> V_143 . V_151 ;
} else if ( V_118 == V_119 ) {
if ( ( V_158 && ! V_2 -> V_165 ) ||
( ! V_158 && ! V_2 -> V_166 ) ) {
F_51 ( L_25 ,
V_158 > 0 ) ;
return - V_13 ;
}
V_150 = & V_2 -> V_143 . V_152 ;
} else {
F_51 ( L_26 ) ;
return - V_13 ;
}
F_42 ( V_2 , V_118 ) ;
V_150 -> V_153 = V_153 ;
V_150 -> V_135 = F_52 ( sizeof( void * ) * V_153 , V_167 ) ;
if ( ! V_150 -> V_135 ) {
F_51 ( L_27 ) ;
return - V_168 ;
}
V_150 -> V_154 = F_52 ( sizeof( void * ) * V_153 ,
V_167 ) ;
if ( ! V_150 -> V_154 ) {
F_51 ( L_28 ) ;
F_48 ( V_150 -> V_135 ) ;
return - V_168 ;
}
V_150 -> V_159 = V_159 ;
if ( V_158 )
V_150 -> V_169 = 0 ;
else
V_150 -> V_169 = V_160 ;
V_2 -> V_143 . V_170 = NULL ;
V_2 -> V_143 . V_171 = NULL ;
V_161 = V_160 * V_150 -> V_159 ;
for ( V_39 = 0 ; V_39 < V_150 -> V_153 ; V_39 ++ ) {
V_135 = F_53 ( V_150 -> V_169 , V_167 ) ;
if ( ! V_135 ) {
F_54 ( L_29 , V_39 ) ;
F_42 ( V_2 , V_118 ) ;
return - V_168 ;
}
V_150 -> V_135 [ V_39 ] = V_135 ;
V_150 -> V_154 [ V_39 ] = F_55 ( V_2 -> V_9 ,
V_161 , V_167 , & V_135 -> V_156 ) ;
if ( ! V_150 -> V_154 [ V_39 ] ) {
F_54 ( L_30
L_31 ,
V_161 , V_39 ,
F_56 () ? L_32 : L_33 ) ;
F_42 ( V_2 , V_118 ) ;
return - V_168 ;
}
memset ( V_150 -> V_154 [ V_39 ] , 0 , V_161 ) ;
if ( V_158 ) {
V_8 = F_57 ( V_2 -> V_9 ,
V_118 == V_119 ?
V_2 -> V_165 :
V_2 -> V_163 ) ;
F_58 ( V_135 , V_2 -> V_9 , V_8 ,
V_150 -> V_154 [ V_39 ] , V_161 ,
F_37 , V_2 ) ;
V_135 -> V_172 = V_173 ;
} else {
V_8 = F_59 ( V_2 -> V_9 ,
V_118 == V_119 ?
V_2 -> V_166 :
V_2 -> V_164 ) ;
F_60 ( V_135 , V_2 -> V_9 , V_8 ,
V_150 -> V_154 [ V_39 ] , V_161 ,
F_37 , V_2 , 1 ) ;
V_135 -> V_172 = V_174 |
V_173 ;
V_105 = 0 ;
for ( V_162 = 0 ; V_162 < V_150 -> V_169 ; V_162 ++ ) {
V_135 -> V_146 [ V_162 ] . V_175 = V_105 ;
V_135 -> V_146 [ V_162 ] . V_176 =
V_150 -> V_159 ;
V_105 += V_150 -> V_159 ;
}
}
V_135 -> V_145 = V_150 -> V_169 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 , enum V_130 V_118 ,
int V_158 , int V_153 , int V_159 ,
int V_160 ,
int (* V_144) ( struct V_1 * V_2 , struct V_135 * V_135 ) )
{
struct V_177 * V_178 = & V_2 -> V_179 ;
struct V_177 * V_180 = & V_2 -> V_181 ;
struct V_149 * V_150 ;
int V_39 ;
int V_108 ;
int V_182 ;
F_38 ( L_34 ,
V_118 ) ;
V_2 -> V_143 . V_144 = V_144 ;
if ( V_118 == V_133 ) {
V_150 = & V_2 -> V_143 . V_151 ;
V_182 = 0 ;
} else {
V_150 = & V_2 -> V_143 . V_152 ;
V_182 = 1 ;
}
if ( V_182 ) {
V_108 = F_50 ( V_2 , V_118 , V_158 , V_153 ,
V_159 , V_160 ) ;
if ( V_108 )
return V_108 ;
}
if ( V_158 ) {
V_108 = F_62 ( V_2 -> V_9 , V_150 -> V_135 [ 0 ] -> V_8 ) ;
if ( V_108 < 0 ) {
F_54 ( L_35 ,
V_108 ) ;
F_42 ( V_2 , V_118 ) ;
return V_108 ;
}
}
F_63 ( & V_178 -> V_183 ) ;
F_63 ( & V_180 -> V_183 ) ;
F_35 ( V_2 , 1 ) ;
for ( V_39 = 0 ; V_39 < V_150 -> V_153 ; V_39 ++ ) {
V_108 = F_41 ( V_150 -> V_135 [ V_39 ] , V_148 ) ;
if ( V_108 ) {
F_54 ( L_36 , V_39 ,
V_108 ) ;
F_42 ( V_2 , V_118 ) ;
return V_108 ;
}
}
return 0 ;
}
int F_64 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_186 ) ;
F_65 ( & V_185 -> V_187 , & V_188 ) ;
F_66 (dev, &em28xx_devlist, devlist) {
V_185 -> V_189 ( V_2 ) ;
}
F_6 ( & V_186 ) ;
F_3 ( V_190 L_37 , V_185 -> V_191 ) ;
return 0 ;
}
void F_67 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_186 ) ;
F_66 (dev, &em28xx_devlist, devlist) {
V_185 -> V_192 ( V_2 ) ;
}
F_68 ( & V_185 -> V_187 ) ;
F_6 ( & V_186 ) ;
F_3 ( V_190 L_38 , V_185 -> V_191 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
const struct V_184 * V_185 = NULL ;
F_4 ( & V_186 ) ;
F_65 ( & V_2 -> V_193 , & V_194 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_185 -> V_189 )
V_185 -> V_189 ( V_2 ) ;
}
F_6 ( & V_186 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
const struct V_184 * V_185 = NULL ;
F_4 ( & V_186 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_185 -> V_192 )
V_185 -> V_192 ( V_2 ) ;
}
F_68 ( & V_2 -> V_193 ) ;
F_6 ( & V_186 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
const struct V_184 * V_185 = NULL ;
F_33 ( L_39 ) ;
F_4 ( & V_186 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_185 -> V_195 )
V_185 -> V_195 ( V_2 ) ;
}
F_6 ( & V_186 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 )
{
const struct V_184 * V_185 = NULL ;
F_33 ( L_40 ) ;
F_4 ( & V_186 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_185 -> V_196 )
V_185 -> V_196 ( V_2 ) ;
}
F_6 ( & V_186 ) ;
return 0 ;
}
