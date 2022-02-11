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
T_3 V_23 ;
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
if ( V_2 -> V_65 == V_66 )
return 0 ;
if ( V_2 -> V_61 . V_62 != V_63 ) {
for ( V_39 = 0 ; V_39 < F_26 ( V_67 ) ; V_39 ++ ) {
V_7 = F_23 ( V_2 , V_67 [ V_39 ] . V_4 , 0x8000 ) ;
if ( V_7 < 0 )
F_20 ( L_9 ,
V_67 [ V_39 ] . V_4 ) ;
}
}
V_64 = V_2 -> V_48 . V_64 & 0x7f ;
if ( ! V_2 -> V_57 )
V_64 |= V_68 ;
V_7 = F_14 ( V_2 , V_69 , V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
F_12 ( 10 ) ;
V_7 = F_27 ( V_2 ) ;
if ( V_2 -> V_61 . V_62 != V_63 ) {
int V_70 ;
F_23 ( V_2 , V_71 , 0x4200 ) ;
F_23 ( V_2 , V_72 , 0x0031 ) ;
F_23 ( V_2 , V_73 , 0xbb80 ) ;
V_70 = ( 0x1f - V_2 -> V_74 ) | ( ( 0x1f - V_2 -> V_74 ) << 8 ) ;
if ( V_2 -> V_57 )
V_70 |= 0x8000 ;
for ( V_39 = 0 ; V_39 < F_26 ( V_67 ) ; V_39 ++ ) {
if ( V_2 -> V_75 & V_67 [ V_39 ] . V_46 )
V_7 = F_23 ( V_2 , V_67 [ V_39 ] . V_4 ,
V_70 ) ;
if ( V_7 < 0 )
F_20 ( L_9 ,
V_67 [ V_39 ] . V_4 ) ;
}
if ( V_2 -> V_75 & V_76 ) {
int V_77 = F_31 ( V_2 -> V_75 ) ;
V_77 |= ( V_77 << 8 ) ;
F_23 ( V_2 , V_78 , V_77 ) ;
}
}
return V_7 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_79 , V_80 , V_81 , V_82 ;
T_4 V_83 = 0 ;
T_1 V_84 ;
if ( V_2 -> V_85 == V_86 ||
V_2 -> V_85 == V_87 ||
V_2 -> V_85 == V_88 ||
V_2 -> V_85 == V_89 ) {
V_2 -> V_65 = V_66 ;
V_2 -> V_90 = V_91 ;
return 0 ;
}
V_82 = F_9 ( V_2 , V_92 ) ;
F_33 ( L_10 , V_82 ) ;
if ( V_82 < 0 ) {
V_2 -> V_65 = V_93 ;
} else if ( ( V_82 & V_94 ) == 0x00 ) {
V_2 -> V_65 = V_66 ;
V_2 -> V_90 = V_91 ;
return 0 ;
} else if ( ( V_82 & V_94 ) != V_95 ) {
V_2 -> V_65 = V_96 ;
if ( V_2 -> V_85 < V_97 &&
( V_82 & V_94 ) ==
V_98 )
V_84 = 1 ;
else if ( V_2 -> V_85 >= V_97 &&
( V_82 & V_94 ) ==
V_99 )
V_84 = 5 ;
else
V_84 = 3 ;
F_33 ( L_11 ,
V_84 ) ;
V_2 -> V_61 . V_62 = V_63 ;
goto V_100;
} else {
V_2 -> V_65 = V_93 ;
}
V_2 -> V_61 . V_62 = V_101 ;
V_79 = F_21 ( V_2 , V_102 ) ;
if ( V_79 < 0 ) {
F_20 ( L_12 ) ;
V_2 -> V_61 . V_62 = V_63 ;
if ( V_2 -> V_90 == V_103 )
V_2 -> V_90 = V_91 ;
V_2 -> V_65 = V_66 ;
goto V_100;
}
V_80 = F_21 ( V_2 , V_104 ) ;
if ( V_80 < 0 )
goto V_100;
V_83 = V_79 << 16 | V_80 ;
F_20 ( L_13 , V_83 ) ;
V_81 = F_21 ( V_2 , V_105 ) ;
if ( V_81 < 0 )
goto V_100;
F_20 ( L_14 , V_81 ) ;
if ( ( ( V_83 == 0xffffffff ) || ( V_83 == 0x83847650 ) ) && ( V_81 == 0x6a90 ) )
V_2 -> V_61 . V_62 = V_106 ;
else if ( ( V_83 >> 8 ) == 0x838476 )
V_2 -> V_61 . V_62 = V_107 ;
V_100:
switch ( V_2 -> V_61 . V_62 ) {
case V_63 :
F_33 ( L_15 ) ;
break;
case V_106 :
F_33 ( L_16 ) ;
break;
case V_107 :
F_33 ( L_17 ,
V_83 & 0xff ) ;
break;
case V_101 :
F_20 ( L_18 ) ;
break;
default:
break;
}
return F_30 ( V_2 ) ;
}
const struct V_108 * F_34 ( struct V_1 * V_2 ,
enum V_109 V_110 )
{
if ( V_2 -> V_48 . V_111 ) {
T_1 V_112 = 0 ;
while ( V_2 -> V_48 . V_111 [ V_112 ] . V_110 >= 0 &&
V_2 -> V_48 . V_111 [ V_112 ] . V_110 < V_113 ) {
if ( V_2 -> V_48 . V_111 [ V_112 ] . V_110 == V_110 )
return & V_2 -> V_48 . V_111 [ V_112 ] ;
V_112 ++ ;
}
}
return NULL ;
}
int F_35 ( struct V_1 * V_2 , int V_114 )
{
int V_115 ;
const struct V_108 * V_116 = NULL ;
if ( V_2 -> V_85 == V_87 ||
V_2 -> V_85 == V_117 ||
V_2 -> V_85 == V_88 ||
V_2 -> V_85 == V_89 ) {
V_115 = F_15 ( V_2 , V_118 ,
V_114 ?
V_119 : 0x00 ,
V_119 ) ;
} else {
V_115 = F_15 ( V_2 , V_120 ,
V_114 ? 0x10 : 0x00 , 0x10 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( V_114 ) {
if ( V_2 -> V_48 . V_121 )
V_115 = F_14 ( V_2 , 0x13 , 0x0c ) ;
V_115 = F_14 ( V_2 , 0x48 , 0x00 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( V_2 -> V_122 == V_123 )
V_115 = F_14 ( V_2 ,
V_124 ,
0x67 ) ;
else
V_115 = F_14 ( V_2 ,
V_124 ,
0x37 ) ;
if ( V_115 < 0 )
return V_115 ;
F_12 ( 6 ) ;
} else {
V_115 = F_14 ( V_2 , V_124 , 0x27 ) ;
}
}
if ( V_2 -> V_122 == V_123 )
V_116 = F_34 ( V_2 , V_125 ) ;
else
V_116 = F_34 ( V_2 , V_126 ) ;
if ( V_116 )
F_15 ( V_2 , V_116 -> V_127 ,
( ! V_114 ^ V_116 -> V_128 ) ?
~ V_116 -> V_129 : V_116 -> V_129 ,
V_116 -> V_129 ) ;
return V_115 ;
}
int F_28 ( struct V_1 * V_2 , struct V_130 * V_59 )
{
int V_115 = 0 ;
if ( ! V_59 )
return V_115 ;
if ( V_2 -> V_122 != V_131 ) {
F_14 ( V_2 , 0x48 , 0x00 ) ;
if ( V_2 -> V_122 == V_123 )
F_14 ( V_2 , V_124 , 0x67 ) ;
else
F_14 ( V_2 , V_124 , 0x37 ) ;
F_12 ( 6 ) ;
}
while ( V_59 -> V_132 >= 0 ) {
if ( V_59 -> V_4 >= 0 ) {
V_115 = F_15 ( V_2 ,
V_59 -> V_4 ,
V_59 -> V_23 ,
V_59 -> V_133 ) ;
if ( V_115 < 0 )
return V_115 ;
}
if ( V_59 -> V_132 > 0 )
F_12 ( V_59 -> V_132 ) ;
V_59 ++ ;
}
return V_115 ;
}
int F_36 ( struct V_1 * V_2 , enum V_134 V_135 )
{
if ( V_2 -> V_122 == V_135 )
return 0 ;
if ( V_135 == V_131 ) {
V_2 -> V_122 = V_135 ;
return F_28 ( V_2 , V_2 -> V_48 . V_136 ) ;
}
V_2 -> V_122 = V_135 ;
if ( V_2 -> V_122 == V_137 )
return F_28 ( V_2 , V_2 -> V_48 . V_138 ) ;
else
return F_28 ( V_2 , F_29 ( V_2 -> V_58 ) -> V_59 ) ;
}
static void F_37 ( struct V_139 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_140 ;
int V_39 ;
switch ( V_139 -> V_141 ) {
case 0 :
case - V_142 :
break;
case - V_143 :
case - V_144 :
case - V_145 :
return;
default:
F_38 ( L_19 , V_139 -> V_141 ) ;
break;
}
F_39 ( & V_2 -> V_146 ) ;
V_2 -> V_147 . V_148 ( V_2 , V_139 ) ;
F_40 ( & V_2 -> V_146 ) ;
for ( V_39 = 0 ; V_39 < V_139 -> V_149 ; V_39 ++ ) {
V_139 -> V_150 [ V_39 ] . V_141 = 0 ;
V_139 -> V_150 [ V_39 ] . V_151 = 0 ;
}
V_139 -> V_141 = 0 ;
V_139 -> V_141 = F_41 ( V_139 , V_152 ) ;
if ( V_139 -> V_141 ) {
F_38 ( L_20 ,
V_139 -> V_141 ) ;
}
}
void F_42 ( struct V_1 * V_2 , enum V_134 V_122 )
{
struct V_139 * V_139 ;
struct V_153 * V_154 ;
int V_39 ;
F_38 ( L_21 ,
V_122 ) ;
if ( V_122 == V_137 )
V_154 = & V_2 -> V_147 . V_155 ;
else
V_154 = & V_2 -> V_147 . V_156 ;
for ( V_39 = 0 ; V_39 < V_154 -> V_157 ; V_39 ++ ) {
V_139 = V_154 -> V_139 [ V_39 ] ;
if ( V_139 ) {
if ( ! F_43 () )
F_44 ( V_139 ) ;
else
F_45 ( V_139 ) ;
if ( V_154 -> V_158 [ V_39 ] ) {
F_46 ( V_2 -> V_9 ,
V_139 -> V_159 ,
V_154 -> V_158 [ V_39 ] ,
V_139 -> V_160 ) ;
}
F_47 ( V_139 ) ;
V_154 -> V_139 [ V_39 ] = NULL ;
}
V_154 -> V_158 [ V_39 ] = NULL ;
}
F_48 ( V_154 -> V_139 ) ;
F_48 ( V_154 -> V_158 ) ;
V_154 -> V_139 = NULL ;
V_154 -> V_158 = NULL ;
V_154 -> V_157 = 0 ;
F_35 ( V_2 , 0 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_39 ;
struct V_139 * V_139 ;
struct V_153 * V_161 = & V_2 -> V_147 . V_155 ;
F_38 ( L_22 ) ;
for ( V_39 = 0 ; V_39 < V_161 -> V_157 ; V_39 ++ ) {
V_139 = V_161 -> V_139 [ V_39 ] ;
if ( V_139 ) {
if ( ! F_43 () )
F_44 ( V_139 ) ;
else
F_45 ( V_139 ) ;
}
}
F_35 ( V_2 , 0 ) ;
}
int F_50 ( struct V_1 * V_2 , enum V_134 V_122 , int V_162 ,
int V_157 , int V_163 , int V_164 )
{
struct V_153 * V_154 ;
int V_39 ;
int V_165 , V_8 ;
struct V_139 * V_139 ;
int V_166 , V_112 ;
F_38 ( L_23 , V_122 ) ;
if ( V_122 == V_137 ) {
if ( ( V_162 && ! V_2 -> V_167 ) ||
( ! V_162 && ! V_2 -> V_168 ) ) {
F_51 ( L_24 ,
V_162 > 0 ) ;
return - V_13 ;
}
V_154 = & V_2 -> V_147 . V_155 ;
} else if ( V_122 == V_123 ) {
if ( ( V_162 && ! V_2 -> V_169 ) ||
( ! V_162 && ! V_2 -> V_170 ) ) {
F_51 ( L_25 ,
V_162 > 0 ) ;
return - V_13 ;
}
V_154 = & V_2 -> V_147 . V_156 ;
} else {
F_51 ( L_26 ) ;
return - V_13 ;
}
F_42 ( V_2 , V_122 ) ;
V_154 -> V_157 = V_157 ;
V_154 -> V_139 = F_52 ( sizeof( void * ) * V_157 , V_171 ) ;
if ( ! V_154 -> V_139 ) {
F_51 ( L_27 ) ;
return - V_172 ;
}
V_154 -> V_158 = F_52 ( sizeof( void * ) * V_157 ,
V_171 ) ;
if ( ! V_154 -> V_158 ) {
F_51 ( L_28 ) ;
F_48 ( V_154 -> V_139 ) ;
return - V_172 ;
}
V_154 -> V_163 = V_163 ;
if ( V_162 )
V_154 -> V_173 = 0 ;
else
V_154 -> V_173 = V_164 ;
V_2 -> V_147 . V_174 = NULL ;
V_2 -> V_147 . V_175 = NULL ;
V_165 = V_164 * V_154 -> V_163 ;
for ( V_39 = 0 ; V_39 < V_154 -> V_157 ; V_39 ++ ) {
V_139 = F_53 ( V_154 -> V_173 , V_171 ) ;
if ( ! V_139 ) {
F_42 ( V_2 , V_122 ) ;
return - V_172 ;
}
V_154 -> V_139 [ V_39 ] = V_139 ;
V_154 -> V_158 [ V_39 ] = F_54 ( V_2 -> V_9 ,
V_165 , V_171 , & V_139 -> V_160 ) ;
if ( ! V_154 -> V_158 [ V_39 ] ) {
F_55 ( L_29
L_30 ,
V_165 , V_39 ,
F_56 () ? L_31 : L_32 ) ;
F_42 ( V_2 , V_122 ) ;
return - V_172 ;
}
memset ( V_154 -> V_158 [ V_39 ] , 0 , V_165 ) ;
if ( V_162 ) {
V_8 = F_57 ( V_2 -> V_9 ,
V_122 == V_123 ?
V_2 -> V_169 :
V_2 -> V_167 ) ;
F_58 ( V_139 , V_2 -> V_9 , V_8 ,
V_154 -> V_158 [ V_39 ] , V_165 ,
F_37 , V_2 ) ;
V_139 -> V_176 = V_177 ;
} else {
V_8 = F_59 ( V_2 -> V_9 ,
V_122 == V_123 ?
V_2 -> V_170 :
V_2 -> V_168 ) ;
F_60 ( V_139 , V_2 -> V_9 , V_8 ,
V_154 -> V_158 [ V_39 ] , V_165 ,
F_37 , V_2 , 1 ) ;
V_139 -> V_176 = V_178 |
V_177 ;
V_112 = 0 ;
for ( V_166 = 0 ; V_166 < V_154 -> V_173 ; V_166 ++ ) {
V_139 -> V_150 [ V_166 ] . V_179 = V_112 ;
V_139 -> V_150 [ V_166 ] . V_180 =
V_154 -> V_163 ;
V_112 += V_154 -> V_163 ;
}
}
V_139 -> V_149 = V_154 -> V_173 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 , enum V_134 V_122 ,
int V_162 , int V_157 , int V_163 ,
int V_164 ,
int (* V_148)( struct V_1 * V_2 , struct V_139 * V_139 ) )
{
struct V_181 * V_182 = & V_2 -> V_183 ;
struct V_181 * V_184 = & V_2 -> V_185 ;
struct V_153 * V_154 ;
int V_39 ;
int V_115 ;
int V_186 ;
F_38 ( L_33 ,
V_122 ) ;
V_2 -> V_147 . V_148 = V_148 ;
if ( V_122 == V_137 ) {
V_154 = & V_2 -> V_147 . V_155 ;
V_186 = 0 ;
} else {
V_154 = & V_2 -> V_147 . V_156 ;
V_186 = 1 ;
}
if ( V_186 ) {
V_115 = F_50 ( V_2 , V_122 , V_162 , V_157 ,
V_163 , V_164 ) ;
if ( V_115 )
return V_115 ;
}
if ( V_162 ) {
V_115 = F_62 ( V_2 -> V_9 , V_154 -> V_139 [ 0 ] -> V_8 ) ;
if ( V_115 < 0 ) {
F_55 ( L_34 ,
V_115 ) ;
F_42 ( V_2 , V_122 ) ;
return V_115 ;
}
}
F_63 ( & V_182 -> V_187 ) ;
F_63 ( & V_184 -> V_187 ) ;
F_35 ( V_2 , 1 ) ;
for ( V_39 = 0 ; V_39 < V_154 -> V_157 ; V_39 ++ ) {
V_115 = F_41 ( V_154 -> V_139 [ V_39 ] , V_152 ) ;
if ( V_115 ) {
F_55 ( L_35 , V_39 ,
V_115 ) ;
F_42 ( V_2 , V_122 ) ;
return V_115 ;
}
}
return 0 ;
}
int F_64 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_190 ) ;
F_65 ( & V_189 -> V_191 , & V_192 ) ;
F_66 (dev, &em28xx_devlist, devlist) {
V_189 -> V_193 ( V_2 ) ;
}
F_6 ( & V_190 ) ;
F_3 ( V_194 L_36 , V_189 -> V_195 ) ;
return 0 ;
}
void F_67 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_190 ) ;
F_66 (dev, &em28xx_devlist, devlist) {
V_189 -> V_196 ( V_2 ) ;
}
F_68 ( & V_189 -> V_191 ) ;
F_6 ( & V_190 ) ;
F_3 ( V_194 L_37 , V_189 -> V_195 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
const struct V_188 * V_189 = NULL ;
F_4 ( & V_190 ) ;
F_65 ( & V_2 -> V_197 , & V_198 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_189 -> V_193 )
V_189 -> V_193 ( V_2 ) ;
}
F_6 ( & V_190 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
const struct V_188 * V_189 = NULL ;
F_4 ( & V_190 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_189 -> V_196 )
V_189 -> V_196 ( V_2 ) ;
}
F_68 ( & V_2 -> V_197 ) ;
F_6 ( & V_190 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
const struct V_188 * V_189 = NULL ;
F_33 ( L_38 ) ;
F_4 ( & V_190 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_189 -> V_199 )
V_189 -> V_199 ( V_2 ) ;
}
F_6 ( & V_190 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 )
{
const struct V_188 * V_189 = NULL ;
F_33 ( L_39 ) ;
F_4 ( & V_190 ) ;
F_66 (ops, &em28xx_extension_devlist, next) {
if ( V_189 -> V_200 )
V_189 -> V_200 ( V_2 ) ;
}
F_6 ( & V_190 ) ;
return 0 ;
}
