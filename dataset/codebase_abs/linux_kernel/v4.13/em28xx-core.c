int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
char * V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
int V_11 = F_3 ( V_9 , 0 ) ;
if ( V_2 -> V_12 )
return - V_13 ;
if ( V_6 > V_14 )
return - V_15 ;
F_4 ( & V_2 -> V_16 ) ;
V_7 = F_5 ( V_9 , V_11 , V_3 ,
V_17 | V_18 | V_19 ,
0x0000 , V_4 , V_2 -> V_20 , V_6 , V_21 ) ;
if ( V_7 < 0 ) {
F_6 ( L_1 ,
V_11 , V_17 | V_18 | V_19 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 , V_7 ) ;
F_7 ( & V_2 -> V_16 ) ;
return F_8 ( V_7 ) ;
}
if ( V_6 )
memcpy ( V_5 , V_2 -> V_20 , V_6 ) ;
F_7 ( & V_2 -> V_16 ) ;
F_6 ( L_2 ,
V_11 , V_17 | V_18 | V_19 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 , V_6 , V_5 ) ;
return V_7 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_7 ;
T_1 V_22 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , & V_22 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return V_22 ;
}
int F_10 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_9 ( V_2 , V_23 , V_4 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , char * V_5 ,
int V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
int V_11 = F_12 ( V_9 , 0 ) ;
if ( V_2 -> V_12 )
return - V_13 ;
if ( ( V_6 < 1 ) || ( V_6 > V_14 ) )
return - V_15 ;
F_4 ( & V_2 -> V_16 ) ;
memcpy ( V_2 -> V_20 , V_5 , V_6 ) ;
V_7 = F_5 ( V_9 , V_11 , V_3 ,
V_24 | V_18 | V_19 ,
0x0000 , V_4 , V_2 -> V_20 , V_6 , V_21 ) ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_7 < 0 ) {
F_6 ( L_3 ,
V_11 ,
V_24 | V_18 | V_19 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 , V_6 , V_5 , V_7 ) ;
return F_8 ( V_7 ) ;
}
F_6 ( L_4 ,
V_11 ,
V_24 | V_18 | V_19 ,
V_3 , 0 , 0 ,
V_4 & 0xff , V_4 >> 8 ,
V_6 & 0xff , V_6 >> 8 , V_6 , V_5 ) ;
if ( V_2 -> V_25 )
F_13 ( V_2 -> V_25 ) ;
return V_7 ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_4 , char * V_5 , int V_6 )
{
return F_11 ( V_2 , V_23 , V_4 , V_5 , V_6 ) ;
}
int F_15 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_22 )
{
return F_14 ( V_2 , V_4 , & V_22 , 1 ) ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_22 ,
T_1 V_26 )
{
int V_27 ;
T_1 V_28 ;
V_27 = F_10 ( V_2 , V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
V_28 = ( ( ( T_1 ) V_27 ) & ~ V_26 ) | ( V_22 & V_26 ) ;
return F_14 ( V_2 , V_4 , & V_28 , 1 ) ;
}
int F_17 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_26 )
{
int V_27 ;
T_1 V_28 ;
V_27 = F_10 ( V_2 , V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
V_28 = ( ~ V_27 & V_26 ) | ( V_27 & ~ V_26 ) ;
return F_15 ( V_2 , V_4 , V_28 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned long V_29 = V_30 + F_19 ( V_31 ) ;
int V_7 ;
while ( F_20 ( V_29 ) ) {
V_7 = F_10 ( V_2 , V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! ( V_7 & 0x01 ) )
return 0 ;
F_13 ( 5 ) ;
}
F_21 ( & V_2 -> V_10 -> V_2 ,
L_5 ) ;
return - V_33 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_4 )
{
int V_7 ;
T_1 V_34 = ( V_4 & 0x7f ) | 0x80 ;
T_3 V_22 ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( V_2 , V_35 , & V_34 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = V_2 -> F_1 ( V_2 , 0 , V_36 ,
( T_1 * ) & V_22 , sizeof( V_22 ) ) ;
if ( V_7 < 0 )
return V_7 ;
return F_23 ( V_22 ) ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_22 )
{
int V_7 ;
T_1 V_34 = V_4 & 0x7f ;
T_3 V_37 ;
V_37 = F_25 ( V_22 ) ;
V_7 = F_18 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( V_2 , V_36 , ( T_1 * ) & V_37 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( V_2 , V_35 , & V_34 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_7 , V_38 ;
enum V_39 V_40 = V_2 -> V_41 ;
if ( V_40 == V_42 )
V_40 = V_43 ;
for ( V_38 = 0 ; V_38 < F_27 ( V_44 ) ; V_38 ++ ) {
if ( V_40 == V_44 [ V_38 ] . V_45 )
V_7 = F_24 ( V_2 , V_44 [ V_38 ] . V_4 , 0x0808 ) ;
else
V_7 = F_24 ( V_2 , V_44 [ V_38 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_21 ( & V_2 -> V_10 -> V_2 ,
L_6 ,
V_44 [ V_38 ] . V_4 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_46 ;
if ( V_2 -> V_47 . V_48 ) {
if ( V_2 -> V_41 == V_43 )
V_46 = V_49 ;
else
V_46 = V_50 ;
V_7 = F_14 ( V_2 , V_51 , & V_46 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_2 -> V_47 . V_52 )
V_46 = V_53 ;
else {
switch ( V_2 -> V_41 ) {
case V_43 :
V_46 = V_53 ;
break;
default:
V_46 = V_54 ;
break;
}
}
if ( V_2 -> V_47 . V_55 && V_2 -> V_56 )
F_29 ( V_2 , V_2 -> V_47 . V_55 ) ;
else
F_29 ( V_2 , F_30 ( V_2 -> V_57 ) -> V_58 ) ;
V_7 = F_16 ( V_2 , V_59 , V_46 , 0xc0 ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( 5 ) ;
switch ( V_2 -> V_60 . V_61 ) {
case V_62 :
break;
default:
V_7 = F_26 ( V_2 ) ;
}
return V_7 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_7 , V_38 ;
T_1 V_63 ;
if ( V_2 -> V_64 == V_65 )
return 0 ;
if ( V_2 -> V_60 . V_61 != V_62 ) {
for ( V_38 = 0 ; V_38 < F_27 ( V_66 ) ; V_38 ++ ) {
V_7 = F_24 ( V_2 , V_66 [ V_38 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_21 ( & V_2 -> V_10 -> V_2 ,
L_6 ,
V_66 [ V_38 ] . V_4 ) ;
}
}
V_63 = V_2 -> V_47 . V_63 & 0x7f ;
if ( ! V_2 -> V_56 )
V_63 |= V_67 ;
V_7 = F_15 ( V_2 , V_68 , V_63 ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( 10 ) ;
V_7 = F_28 ( V_2 ) ;
if ( V_2 -> V_60 . V_61 != V_62 ) {
int V_69 ;
F_24 ( V_2 , V_70 , 0x4200 ) ;
F_24 ( V_2 , V_71 , 0x0031 ) ;
F_24 ( V_2 , V_72 , 0xbb80 ) ;
V_69 = ( 0x1f - V_2 -> V_73 ) | ( ( 0x1f - V_2 -> V_73 ) << 8 ) ;
if ( V_2 -> V_56 )
V_69 |= 0x8000 ;
for ( V_38 = 0 ; V_38 < F_27 ( V_66 ) ; V_38 ++ ) {
if ( V_2 -> V_74 & V_66 [ V_38 ] . V_45 )
V_7 = F_24 ( V_2 , V_66 [ V_38 ] . V_4 ,
V_69 ) ;
if ( V_7 < 0 )
F_21 ( & V_2 -> V_10 -> V_2 ,
L_6 ,
V_66 [ V_38 ] . V_4 ) ;
}
if ( V_2 -> V_74 & V_75 ) {
int V_76 = F_32 ( V_2 -> V_74 ) ;
V_76 |= ( V_76 << 8 ) ;
F_24 ( V_2 , V_77 , V_76 ) ;
}
}
return V_7 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_78 , V_79 , V_80 , V_81 ;
T_4 V_82 = 0 ;
T_1 V_83 ;
if ( V_2 -> V_84 == V_85 ||
V_2 -> V_84 == V_86 ||
V_2 -> V_84 == V_87 ||
V_2 -> V_84 == V_88 ) {
V_2 -> V_64 = V_65 ;
V_2 -> V_89 = V_90 ;
return 0 ;
}
V_81 = F_10 ( V_2 , V_91 ) ;
F_34 ( & V_2 -> V_10 -> V_2 , L_7 , V_81 ) ;
if ( V_81 < 0 ) {
V_2 -> V_64 = V_92 ;
} else if ( ( V_81 & V_93 ) == 0x00 ) {
V_2 -> V_64 = V_65 ;
V_2 -> V_89 = V_90 ;
return 0 ;
} else if ( ( V_81 & V_93 ) != V_94 ) {
V_2 -> V_64 = V_95 ;
if ( V_2 -> V_84 < V_96 &&
( V_81 & V_93 ) ==
V_97 )
V_83 = 1 ;
else if ( V_2 -> V_84 >= V_96 &&
( V_81 & V_93 ) ==
V_98 )
V_83 = 5 ;
else
V_83 = 3 ;
F_34 ( & V_2 -> V_10 -> V_2 , L_8 ,
V_83 ) ;
V_2 -> V_60 . V_61 = V_62 ;
goto V_99;
} else {
V_2 -> V_64 = V_92 ;
}
V_2 -> V_60 . V_61 = V_100 ;
V_78 = F_22 ( V_2 , V_101 ) ;
if ( V_78 < 0 ) {
F_21 ( & V_2 -> V_10 -> V_2 ,
L_9 ) ;
V_2 -> V_60 . V_61 = V_62 ;
if ( V_2 -> V_89 == V_102 )
V_2 -> V_89 = V_90 ;
V_2 -> V_64 = V_65 ;
goto V_99;
}
V_79 = F_22 ( V_2 , V_103 ) ;
if ( V_79 < 0 )
goto V_99;
V_82 = V_78 << 16 | V_79 ;
F_21 ( & V_2 -> V_10 -> V_2 , L_10 , V_82 ) ;
V_80 = F_22 ( V_2 , V_104 ) ;
if ( V_80 < 0 )
goto V_99;
F_21 ( & V_2 -> V_10 -> V_2 , L_11 , V_80 ) ;
if ( ( ( V_82 == 0xffffffff ) || ( V_82 == 0x83847650 ) ) && ( V_80 == 0x6a90 ) )
V_2 -> V_60 . V_61 = V_105 ;
else if ( ( V_82 >> 8 ) == 0x838476 )
V_2 -> V_60 . V_61 = V_106 ;
V_99:
switch ( V_2 -> V_60 . V_61 ) {
case V_62 :
F_34 ( & V_2 -> V_10 -> V_2 , L_12 ) ;
break;
case V_105 :
F_34 ( & V_2 -> V_10 -> V_2 ,
L_13 ) ;
break;
case V_106 :
F_34 ( & V_2 -> V_10 -> V_2 ,
L_14 ,
V_82 & 0xff ) ;
break;
case V_100 :
F_21 ( & V_2 -> V_10 -> V_2 ,
L_15 ) ;
break;
default:
break;
}
return F_31 ( V_2 ) ;
}
const struct V_107 * F_35 ( struct V_1 * V_2 ,
enum V_108 V_109 )
{
if ( V_2 -> V_47 . V_110 ) {
T_1 V_111 = 0 ;
while ( V_2 -> V_47 . V_110 [ V_111 ] . V_109 >= 0 &&
V_2 -> V_47 . V_110 [ V_111 ] . V_109 < V_112 ) {
if ( V_2 -> V_47 . V_110 [ V_111 ] . V_109 == V_109 )
return & V_2 -> V_47 . V_110 [ V_111 ] ;
V_111 ++ ;
}
}
return NULL ;
}
int F_36 ( struct V_1 * V_2 , int V_113 )
{
int V_114 ;
const struct V_107 * V_115 = NULL ;
if ( V_2 -> V_84 == V_86 ||
V_2 -> V_84 == V_116 ||
V_2 -> V_84 == V_87 ||
V_2 -> V_84 == V_88 ) {
V_114 = F_16 ( V_2 , V_117 ,
V_113 ?
V_118 : 0x00 ,
V_118 ) ;
} else {
V_114 = F_16 ( V_2 , V_119 ,
V_113 ? 0x10 : 0x00 , 0x10 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( V_113 ) {
if ( V_2 -> V_47 . V_120 )
V_114 = F_15 ( V_2 , 0x13 , 0x0c ) ;
V_114 = F_15 ( V_2 , 0x48 , 0x00 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( V_2 -> V_121 == V_122 )
V_114 = F_15 ( V_2 ,
V_123 ,
0x67 ) ;
else
V_114 = F_15 ( V_2 ,
V_123 ,
0x37 ) ;
if ( V_114 < 0 )
return V_114 ;
F_13 ( 6 ) ;
} else {
V_114 = F_15 ( V_2 , V_123 , 0x27 ) ;
}
}
if ( V_2 -> V_121 == V_122 )
V_115 = F_35 ( V_2 , V_124 ) ;
else
V_115 = F_35 ( V_2 , V_125 ) ;
if ( V_115 )
F_16 ( V_2 , V_115 -> V_126 ,
( ! V_113 ^ V_115 -> V_127 ) ?
~ V_115 -> V_128 : V_115 -> V_128 ,
V_115 -> V_128 ) ;
return V_114 ;
}
int F_29 ( struct V_1 * V_2 , struct V_129 * V_58 )
{
int V_114 = 0 ;
if ( ! V_58 )
return V_114 ;
if ( V_2 -> V_121 != V_130 ) {
F_15 ( V_2 , 0x48 , 0x00 ) ;
if ( V_2 -> V_121 == V_122 )
F_15 ( V_2 , V_123 , 0x67 ) ;
else
F_15 ( V_2 , V_123 , 0x37 ) ;
F_13 ( 6 ) ;
}
while ( V_58 -> V_131 >= 0 ) {
if ( V_58 -> V_4 >= 0 ) {
V_114 = F_16 ( V_2 ,
V_58 -> V_4 ,
V_58 -> V_22 ,
V_58 -> V_132 ) ;
if ( V_114 < 0 )
return V_114 ;
}
if ( V_58 -> V_131 > 0 )
F_13 ( V_58 -> V_131 ) ;
V_58 ++ ;
}
return V_114 ;
}
int F_37 ( struct V_1 * V_2 , enum V_133 V_134 )
{
if ( V_2 -> V_121 == V_134 )
return 0 ;
if ( V_134 == V_130 ) {
V_2 -> V_121 = V_134 ;
return F_29 ( V_2 , V_2 -> V_47 . V_135 ) ;
}
V_2 -> V_121 = V_134 ;
if ( V_2 -> V_121 == V_136 )
return F_29 ( V_2 , V_2 -> V_47 . V_137 ) ;
else
return F_29 ( V_2 , F_30 ( V_2 -> V_57 ) -> V_58 ) ;
}
static void F_38 ( struct V_138 * V_138 )
{
struct V_1 * V_2 = V_138 -> V_139 ;
int V_38 ;
switch ( V_138 -> V_140 ) {
case 0 :
case - V_141 :
break;
case - V_142 :
case - V_143 :
case - V_144 :
return;
default:
F_39 ( L_16 , V_138 -> V_140 ) ;
break;
}
F_40 ( & V_2 -> V_145 ) ;
V_2 -> V_146 . V_147 ( V_2 , V_138 ) ;
F_41 ( & V_2 -> V_145 ) ;
for ( V_38 = 0 ; V_38 < V_138 -> V_148 ; V_38 ++ ) {
V_138 -> V_149 [ V_38 ] . V_140 = 0 ;
V_138 -> V_149 [ V_38 ] . V_150 = 0 ;
}
V_138 -> V_140 = 0 ;
V_138 -> V_140 = F_42 ( V_138 , V_151 ) ;
if ( V_138 -> V_140 ) {
F_39 ( L_17 ,
V_138 -> V_140 ) ;
}
}
void F_43 ( struct V_1 * V_2 , enum V_133 V_121 )
{
struct V_138 * V_138 ;
struct V_152 * V_153 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
int V_38 ;
F_39 ( L_18 ,
V_121 ) ;
if ( V_121 == V_136 )
V_153 = & V_2 -> V_146 . V_154 ;
else
V_153 = & V_2 -> V_146 . V_155 ;
for ( V_38 = 0 ; V_38 < V_153 -> V_156 ; V_38 ++ ) {
V_138 = V_153 -> V_138 [ V_38 ] ;
if ( V_138 ) {
if ( ! F_44 () )
F_45 ( V_138 ) ;
else
F_46 ( V_138 ) ;
if ( V_153 -> V_157 [ V_38 ] ) {
F_47 ( V_9 ,
V_138 -> V_158 ,
V_153 -> V_157 [ V_38 ] ,
V_138 -> V_159 ) ;
}
F_48 ( V_138 ) ;
V_153 -> V_138 [ V_38 ] = NULL ;
}
V_153 -> V_157 [ V_38 ] = NULL ;
}
F_49 ( V_153 -> V_138 ) ;
F_49 ( V_153 -> V_157 ) ;
V_153 -> V_138 = NULL ;
V_153 -> V_157 = NULL ;
V_153 -> V_156 = 0 ;
F_36 ( V_2 , 0 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
int V_38 ;
struct V_138 * V_138 ;
struct V_152 * V_160 = & V_2 -> V_146 . V_154 ;
F_39 ( L_19 ) ;
for ( V_38 = 0 ; V_38 < V_160 -> V_156 ; V_38 ++ ) {
V_138 = V_160 -> V_138 [ V_38 ] ;
if ( V_138 ) {
if ( ! F_44 () )
F_45 ( V_138 ) ;
else
F_46 ( V_138 ) ;
}
}
F_36 ( V_2 , 0 ) ;
}
int F_51 ( struct V_1 * V_2 , enum V_133 V_121 , int V_161 ,
int V_156 , int V_162 , int V_163 )
{
struct V_152 * V_153 ;
struct V_138 * V_138 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
int V_38 ;
int V_164 , V_11 ;
int V_165 , V_111 ;
F_39 ( L_20 , V_121 ) ;
if ( V_121 == V_136 ) {
if ( ( V_161 && ! V_2 -> V_166 ) ||
( ! V_161 && ! V_2 -> V_167 ) ) {
F_52 ( & V_2 -> V_10 -> V_2 ,
L_21 ,
V_161 > 0 ) ;
return - V_15 ;
}
V_153 = & V_2 -> V_146 . V_154 ;
} else if ( V_121 == V_122 ) {
if ( ( V_161 && ! V_2 -> V_168 ) ||
( ! V_161 && ! V_2 -> V_169 ) ) {
F_52 ( & V_2 -> V_10 -> V_2 ,
L_22 ,
V_161 > 0 ) ;
return - V_15 ;
}
V_153 = & V_2 -> V_146 . V_155 ;
} else {
F_52 ( & V_2 -> V_10 -> V_2 , L_23 ) ;
return - V_15 ;
}
F_43 ( V_2 , V_121 ) ;
V_153 -> V_156 = V_156 ;
V_153 -> V_138 = F_53 ( sizeof( void * ) * V_156 , V_170 ) ;
if ( ! V_153 -> V_138 )
return - V_171 ;
V_153 -> V_157 = F_53 ( sizeof( void * ) * V_156 ,
V_170 ) ;
if ( ! V_153 -> V_157 ) {
F_49 ( V_153 -> V_138 ) ;
return - V_171 ;
}
V_153 -> V_162 = V_162 ;
if ( V_161 )
V_153 -> V_172 = 0 ;
else
V_153 -> V_172 = V_163 ;
V_2 -> V_146 . V_173 = NULL ;
V_2 -> V_146 . V_174 = NULL ;
V_164 = V_163 * V_153 -> V_162 ;
for ( V_38 = 0 ; V_38 < V_153 -> V_156 ; V_38 ++ ) {
V_138 = F_54 ( V_153 -> V_172 , V_170 ) ;
if ( ! V_138 ) {
F_43 ( V_2 , V_121 ) ;
return - V_171 ;
}
V_153 -> V_138 [ V_38 ] = V_138 ;
V_153 -> V_157 [ V_38 ] = F_55 ( V_9 ,
V_164 , V_170 , & V_138 -> V_159 ) ;
if ( ! V_153 -> V_157 [ V_38 ] ) {
F_52 ( & V_2 -> V_10 -> V_2 ,
L_24 ,
V_164 , V_38 ,
F_56 () ? L_25 : L_26 ) ;
F_43 ( V_2 , V_121 ) ;
return - V_171 ;
}
memset ( V_153 -> V_157 [ V_38 ] , 0 , V_164 ) ;
if ( V_161 ) {
V_11 = F_57 ( V_9 ,
V_121 == V_122 ?
V_2 -> V_168 :
V_2 -> V_166 ) ;
F_58 ( V_138 , V_9 , V_11 ,
V_153 -> V_157 [ V_38 ] , V_164 ,
F_38 , V_2 ) ;
V_138 -> V_175 = V_176 ;
} else {
V_11 = F_59 ( V_9 ,
V_121 == V_122 ?
V_2 -> V_169 :
V_2 -> V_167 ) ;
F_60 ( V_138 , V_9 , V_11 ,
V_153 -> V_157 [ V_38 ] , V_164 ,
F_38 , V_2 , 1 ) ;
V_138 -> V_175 = V_177 |
V_176 ;
V_111 = 0 ;
for ( V_165 = 0 ; V_165 < V_153 -> V_172 ; V_165 ++ ) {
V_138 -> V_149 [ V_165 ] . V_178 = V_111 ;
V_138 -> V_149 [ V_165 ] . V_179 =
V_153 -> V_162 ;
V_111 += V_153 -> V_162 ;
}
}
V_138 -> V_148 = V_153 -> V_172 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 , enum V_133 V_121 ,
int V_161 , int V_156 , int V_162 ,
int V_163 ,
int (* V_147)( struct V_1 * V_2 , struct V_138 * V_138 ) )
{
struct V_180 * V_181 = & V_2 -> V_182 ;
struct V_180 * V_183 = & V_2 -> V_184 ;
struct V_152 * V_153 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 ) ;
int V_38 ;
int V_114 ;
int V_185 ;
F_39 ( L_27 ,
V_121 ) ;
V_2 -> V_146 . V_147 = V_147 ;
if ( V_121 == V_136 ) {
V_153 = & V_2 -> V_146 . V_154 ;
V_185 = 0 ;
} else {
V_153 = & V_2 -> V_146 . V_155 ;
V_185 = 1 ;
}
if ( V_185 ) {
V_114 = F_51 ( V_2 , V_121 , V_161 , V_156 ,
V_162 , V_163 ) ;
if ( V_114 )
return V_114 ;
}
if ( V_161 ) {
V_114 = F_62 ( V_9 , V_153 -> V_138 [ 0 ] -> V_11 ) ;
if ( V_114 < 0 ) {
F_52 ( & V_2 -> V_10 -> V_2 ,
L_28 ,
V_114 ) ;
F_43 ( V_2 , V_121 ) ;
return V_114 ;
}
}
F_63 ( & V_181 -> V_186 ) ;
F_63 ( & V_183 -> V_186 ) ;
F_36 ( V_2 , 1 ) ;
for ( V_38 = 0 ; V_38 < V_153 -> V_156 ; V_38 ++ ) {
V_114 = F_42 ( V_153 -> V_138 [ V_38 ] , V_151 ) ;
if ( V_114 ) {
F_52 ( & V_2 -> V_10 -> V_2 ,
L_29 , V_38 , V_114 ) ;
F_43 ( V_2 , V_121 ) ;
return V_114 ;
}
}
return 0 ;
}
int F_64 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_189 ) ;
F_65 ( & V_188 -> V_190 , & V_191 ) ;
F_66 (dev, &em28xx_devlist, devlist) {
V_188 -> V_192 ( V_2 ) ;
}
F_7 ( & V_189 ) ;
F_67 ( L_30 , V_188 -> V_193 ) ;
return 0 ;
}
void F_68 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_189 ) ;
F_66 (dev, &em28xx_devlist, devlist) {
V_188 -> V_194 ( V_2 ) ;
}
F_69 ( & V_188 -> V_190 ) ;
F_7 ( & V_189 ) ;
F_67 ( L_31 , V_188 -> V_193 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
const struct V_187 * V_188 = NULL ;
F_4 ( & V_189 ) ;
F_65 ( & V_2 -> V_195 , & V_196 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_188 -> V_192 )
V_188 -> V_192 ( V_2 ) ;
}
F_7 ( & V_189 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
const struct V_187 * V_188 = NULL ;
F_4 ( & V_189 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_188 -> V_194 )
V_188 -> V_194 ( V_2 ) ;
}
F_69 ( & V_2 -> V_195 ) ;
F_7 ( & V_189 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
const struct V_187 * V_188 = NULL ;
F_34 ( & V_2 -> V_10 -> V_2 , L_32 ) ;
F_4 ( & V_189 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_188 -> V_197 )
V_188 -> V_197 ( V_2 ) ;
}
F_7 ( & V_189 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 )
{
const struct V_187 * V_188 = NULL ;
F_34 ( & V_2 -> V_10 -> V_2 , L_33 ) ;
F_4 ( & V_189 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_188 -> V_198 )
V_188 -> V_198 ( V_2 ) ;
}
F_7 ( & V_189 ) ;
return 0 ;
}
