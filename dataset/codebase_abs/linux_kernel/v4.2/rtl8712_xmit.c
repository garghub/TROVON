T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
V_2 -> V_3 = V_3 ;
switch ( V_3 ) {
case V_4 :
V_2 -> V_5 = V_6 ;
break;
case V_7 :
V_2 -> V_5 = V_8 ;
break;
case V_9 :
V_2 -> V_5 = V_10 ;
break;
case V_11 :
V_2 -> V_5 = V_12 ;
break;
case V_13 :
V_2 -> V_5 = V_6 ;
break;
}
return V_14 ;
}
int F_2 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = V_18 -> V_23 ;
V_20 = V_18 -> V_20 ;
switch ( V_23 ) {
case 1 :
case 2 :
V_22 = & ( V_20 -> V_24 . V_25 ) ;
break;
case 4 :
case 5 :
V_22 = & ( V_20 -> V_24 . V_26 ) ;
break;
case 6 :
case 7 :
V_22 = & ( V_20 -> V_24 . V_27 ) ;
break;
case 0 :
case 3 :
default:
V_22 = & ( V_20 -> V_24 . V_28 ) ;
break;
}
return V_22 -> V_29 ;
}
static T_3 F_3 ( struct V_30 * V_31 )
{
T_3 V_32 = 0 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
if ( V_31 -> V_37 == V_38 )
V_32 = V_39 ;
else if ( V_31 -> V_37 == V_40 )
V_32 = V_41 ;
else if ( V_35 -> V_42 == 6 ) {
switch ( V_18 -> V_23 ) {
case 0 :
case 3 :
V_32 = V_6 ;
break;
case 1 :
case 2 :
V_32 = V_8 ;
break;
case 4 :
case 5 :
V_32 = V_10 ;
break;
case 6 :
case 7 :
V_32 = V_12 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
case 0x13 :
V_32 = V_39 ;
break;
default:
V_32 = V_6 ;
break;
}
} else if ( V_35 -> V_42 == 4 ) {
switch ( V_18 -> V_43 ) {
case 0 :
case 3 :
case 1 :
case 2 :
V_32 = V_6 ;
break;
case 4 :
case 5 :
case 6 :
case 7 :
V_32 = V_12 ;
break;
case 0x10 :
case 0x11 :
case 0x12 :
case 0x13 :
V_32 = V_39 ;
break;
default:
V_32 = V_6 ;
break;
}
}
return V_32 ;
}
static struct V_30 * F_4 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_21 * V_22 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 , * V_52 ;
struct V_30 * V_31 = NULL ;
V_52 = & V_49 -> V_53 ;
V_51 = V_52 -> V_54 ;
if ( ( F_5 ( V_52 , V_51 ) ) == false ) {
V_31 = F_6 ( V_51 ,
struct V_30 , V_55 ) ;
F_7 ( & V_31 -> V_55 ) ;
V_22 -> V_29 -- ;
V_47 -> V_56 ++ ;
}
return V_31 ;
}
static struct V_30 * F_8 ( struct V_44 * V_45 ,
struct V_46 * V_57 , T_1 V_58 )
{
unsigned long V_59 ;
struct V_50 * V_60 , * V_61 ;
struct V_46 * V_47 ;
struct V_21 * V_22 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_30 * V_31 = NULL ;
int V_62 , V_63 [ 4 ] ;
int V_64 , V_65 [ 4 ] ;
V_63 [ 0 ] = 0 ; V_65 [ 0 ] = V_45 -> V_66 ;
V_63 [ 1 ] = 1 ; V_65 [ 1 ] = V_45 -> V_67 ;
V_63 [ 2 ] = 2 ; V_65 [ 2 ] = V_45 -> V_68 ;
V_63 [ 3 ] = 3 ; V_65 [ 3 ] = V_45 -> V_69 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
for ( V_64 = V_62 + 1 ; V_64 < 4 ; V_64 ++ ) {
if ( V_65 [ V_64 ] < V_65 [ V_62 ] ) {
F_9 ( V_65 [ V_62 ] , V_65 [ V_64 ] ) ;
F_9 ( V_63 [ V_62 ] , V_63 [ V_64 ] ) ;
}
}
}
F_10 ( & V_45 -> V_70 , V_59 ) ;
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
V_47 = V_57 + V_63 [ V_62 ] ;
V_61 = & V_47 -> V_71 -> V_53 ;
V_60 = V_61 -> V_54 ;
while ( ( F_5 ( V_61 , V_60 ) ) == false ) {
V_22 = F_6 ( V_60 , struct V_21 ,
V_72 ) ;
V_49 = & V_22 -> V_73 ;
V_31 = F_4 ( V_45 , V_47 ,
V_22 , V_49 ) ;
if ( V_31 ) {
V_47 -> V_74 -- ;
goto V_75;
}
V_60 = V_60 -> V_54 ;
if ( F_11 ( & V_49 -> V_53 ) ) {
F_7 ( & V_22 -> V_72 ) ;
}
}
}
V_75:
F_12 ( & V_45 -> V_70 , V_59 ) ;
return V_31 ;
}
void F_13 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
unsigned int V_43 = 0 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
if ( V_35 -> V_42 == 6 )
V_43 = ( unsigned int ) V_18 -> V_23 ;
else if ( V_35 -> V_42 == 4 ) {
V_43 = ( unsigned int ) V_18 -> V_23 ;
if ( V_43 == 0 || V_43 == 3 )
V_43 = 3 ;
else if ( V_43 == 1 || V_43 == 2 )
V_43 = 1 ;
else if ( V_43 == 4 || V_43 == 5 )
V_43 = 5 ;
else if ( V_43 == 6 || V_43 == 7 )
V_43 = 7 ;
else
V_43 = 3 ;
}
V_18 -> V_43 = V_43 ;
}
T_2 F_14 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = (struct V_78 * ) V_77 -> V_80 ;
V_79 -> V_81 = F_15 ( V_82 & 0xffff ) ;
V_79 -> V_81 |=
F_15 ( ( ( V_83 + V_84 ) << V_85 ) & 0x00ff0000 ) ;
V_79 -> V_81 |= F_15 ( V_86 | V_87 | V_88 ) ;
V_79 -> V_89 |= F_15 ( ( 0x13 << V_90 ) & 0x00001f00 ) ;
return V_14 ;
}
T_2 F_16 ( struct V_76 * V_77 )
{
struct V_30 * V_31 = (struct V_30 * )
V_77 -> V_91 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_92 * V_93 = & ( V_16 -> V_94 ) ;
struct V_95 * V_96 = (struct V_95 * )
( V_77 -> V_80 + V_83 ) ;
V_96 -> V_97 = F_15 ( ( F_17 ( V_98 ) << 16 ) |
( V_93 -> V_99 << 24 ) ) ;
V_93 -> V_99 ++ ;
return V_14 ;
}
T_2 F_18 ( struct V_76 * V_77 ,
struct V_30 * V_31 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_78 * V_79 = (struct V_78 * ) V_77 -> V_80 ;
int V_100 = 0 ;
int V_101 = 0 ;
F_19 ( V_16 , V_31 -> V_102 , V_31 ) ;
F_20 ( V_16 , V_31 ) ;
if ( V_31 -> V_33 . V_103 != 0x0806 ) {
if ( ( V_31 -> V_33 . V_103 != 0x888e ) &&
( V_31 -> V_33 . V_104 != 1 ) ) {
F_21 ( V_16 ,
V_31 -> V_33 . V_23 ) ;
}
}
V_31 -> V_105 [ 0 ] = 1 ;
F_22 ( V_31 , ( V_106 * ) ( V_31 -> V_107 ) ,
V_31 -> V_33 . V_100 ) ;
V_100 = V_31 -> V_33 . V_100 ;
V_101 = ( 8 - ( V_100 % 8 ) ) ;
if ( ( V_100 % 8 ) != 0 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_101 ; V_62 ++ )
* ( V_31 -> V_107 + V_83 + V_100 + V_62 ) = 0 ;
}
V_79 -> V_81 = F_15 ( ( V_79 -> V_81 & 0xffff0000 ) |
( ( V_79 -> V_81 & 0x0000ffff ) +
( ( V_83 + V_100 + V_101 ) & 0x0000ffff ) ) ) ;
return V_14 ;
}
T_2 F_23 ( struct V_76 * V_77 ,
struct V_30 * V_31 )
{
V_31 -> V_77 = V_77 ;
V_77 -> V_91 = V_31 ;
V_31 -> V_108 [ 0 ] = V_77 -> V_108 [ 0 ] ;
V_31 -> V_107 = V_77 -> V_80 + V_83 + V_82 ;
F_14 ( V_77 ) ;
F_16 ( V_77 ) ;
if ( F_18 ( V_77 , V_31 ) == V_14 )
V_77 -> V_109 = 1 ;
return V_14 ;
}
T_4 F_24 ( struct V_76 * V_77 ,
struct V_30 * V_31 )
{
V_31 -> V_77 = V_77 ;
V_77 -> V_91 = V_31 ;
V_31 -> V_108 [ 0 ] = V_77 -> V_108 [ 0 ] ;
V_31 -> V_107 = V_77 -> V_80 + V_83 +
( ( (struct V_78 * ) V_77 -> V_80 ) -> V_81 & 0x0000ffff ) ;
if ( F_18 ( V_77 , V_31 ) == V_14 ) {
F_25 ( & V_31 -> V_16 -> V_110 ,
V_31 ) ;
V_77 -> V_109 ++ ;
}
return V_83 +
( ( (struct V_78 * ) V_77 -> V_80 ) -> V_81 & 0x0000ffff ) ;
}
T_2 F_26 ( struct V_76 * V_77 ,
struct V_30 * V_31 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
struct V_78 * V_111 = (struct V_78 * ) V_77 -> V_80 ;
struct V_95 * V_96 = (struct V_95 * )
( V_77 -> V_80 + V_83 ) ;
T_4 V_112 = ( T_4 ) ( V_111 -> V_81 & 0xffff ) ;
F_27 ( V_31 , V_77 ) ;
V_96 -> V_97 = F_15 ( ( ( V_112 - V_82 ) & 0x0000ffff ) |
( V_96 -> V_97 & 0xffff0000 ) ) ;
V_96 -> V_113 = F_15 ( ( V_77 -> V_109 & 0xff ) |
( ( V_112 + V_83 ) << 16 ) ) ;
V_31 -> V_105 [ 0 ] = 1 ;
V_31 -> V_114 [ 0 ] = false ;
V_31 -> V_115 = V_77 -> V_80 ;
if ( ( V_35 -> V_116 && ( ( V_112 + V_83 ) % 0x200 ) == 0 ) ||
( ( ! V_35 -> V_116 &&
( ( V_112 + V_83 ) % 0x40 ) == 0 ) ) ) {
V_111 -> V_81 |= F_15
( ( ( V_83 + V_84 + 8 ) << V_85 ) & 0x00ff0000 ) ;
} else {
V_111 -> V_81 |= F_15
( ( ( V_83 + V_84 ) << V_85 ) & 0x00ff0000 ) ;
}
F_28 ( V_31 -> V_16 , V_39 ,
V_112 + V_83 , ( T_2 * ) V_31 ) ;
return V_14 ;
}
static void F_22 ( struct V_30 * V_31 , V_106 * V_117 , int V_118 )
{
V_106 V_43 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_119 * V_120 = & V_16 -> V_121 ;
struct V_122 * V_123 = & V_120 -> V_124 ;
struct V_125 * V_126 = & V_16 -> V_127 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_78 * V_111 = (struct V_78 * ) V_117 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
#ifdef F_29
struct V_92 * V_93 = (struct V_92 * ) & V_16 -> V_94 ;
#endif
T_2 V_128 ;
T_1 V_129 = F_30 ( V_18 -> V_130 ) ;
struct V_131 * V_132 = & V_120 -> V_133 ;
struct V_78 V_134 ;
memcpy ( & V_134 , V_111 , sizeof( struct V_78 ) ) ;
memset ( V_111 , 0 , sizeof( struct V_78 ) ) ;
V_111 -> V_81 |= F_15 ( V_118 & 0x0000ffff ) ;
if ( V_35 -> V_116 ) {
if ( ( ( V_118 + V_83 ) % 512 ) == 0 )
V_128 = 1 ;
else
V_128 = 0 ;
} else {
if ( ( ( V_118 + V_83 ) % 64 ) == 0 )
V_128 = 1 ;
else
V_128 = 0 ;
}
if ( V_128 ) {
V_111 -> V_81 |= F_15 ( ( ( V_83 + V_84 + 8 ) <<
V_85 ) & 0x00ff0000 ) ;
} else {
V_111 -> V_81 |= F_15 ( ( ( V_83 + V_84 ) <<
V_85 ) & 0x00ff0000 ) ;
}
V_111 -> V_81 |= F_15 ( V_86 | V_87 | V_88 ) ;
if ( V_31 -> V_37 == V_135 ) {
V_111 -> V_89 |= F_15 ( ( V_18 -> V_136 ) & 0x1f ) ;
#ifdef F_29
if ( ( T_2 * ) V_117 != ( T_2 * ) V_31 -> V_77 -> V_80 ) {
V_111 -> V_81 |= F_15
( ( 0x3 << V_137 ) & V_138 ) ;
V_43 = ( V_106 ) ( V_18 -> V_43 & 0x0000001f ) ;
if ( V_43 == 2 )
V_43 = 0 ;
V_111 -> V_89 |= F_15
( ( V_43 << V_90 ) & 0x00001f00 ) ;
V_111 -> V_139 = F_15
( ( V_43 << V_140 ) & 0x001f0000 ) ;
V_111 -> V_141 |= F_15
( ( 0x5 << V_142 ) & V_143 ) ;
} else {
V_111 -> V_81 |= F_15
( ( 0x3 << V_137 ) & V_138 ) ;
V_111 -> V_89 |= F_15
( ( 0x13 << V_90 ) & 0x00001f00 ) ;
V_43 = ( V_106 ) ( V_18 -> V_43 & 0x0000001f ) ;
if ( V_43 == 2 )
V_43 = 0 ;
V_111 -> V_139 = F_15
( ( V_43 << V_140 ) & 0x0001f000 ) ;
V_111 -> V_144 |= F_15
( V_93 -> V_99 << 24 ) ;
V_93 -> V_99 ++ ;
}
V_18 -> V_43 = 0x13 ;
#else
V_43 = ( V_106 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_111 -> V_89 |= F_15 ( ( V_43 << V_90 ) & 0x00001f00 ) ;
#endif
if ( ! V_123 -> V_145 )
V_111 -> V_89 |= F_15 ( F_31 ( 16 ) ) ;
if ( ( V_18 -> V_146 > 0 ) && ! V_18 -> V_147 ) {
switch ( V_18 -> V_146 ) {
case V_148 :
case V_149 :
V_111 -> V_89 |= F_15 ( ( 0x01 << 22 ) &
0x00c00000 ) ;
V_111 -> V_89 |= F_15 ( ( V_126 ->
V_150 << 17 ) &
0x00060000 ) ;
break;
case V_151 :
case V_152 :
V_111 -> V_89 |= F_15 ( ( 0x02 << 22 ) &
0x00c00000 ) ;
break;
case V_153 :
V_111 -> V_89 |= F_15 ( ( 0x03 << 22 ) &
0x00c00000 ) ;
break;
case V_154 :
default:
break;
}
}
if ( V_129 )
V_111 -> V_139 |= F_15 ( V_155 ) ;
V_111 -> V_156 = F_15 ( ( V_18 -> V_23 << V_157 ) &
0x0fff0000 ) ;
if ( ( V_18 -> V_103 != 0x888e ) &&
( V_18 -> V_103 != 0x0806 ) &&
( V_18 -> V_104 != 1 ) ) {
if ( V_132 -> V_158 == 1 ) {
if ( V_132 -> V_159 != true )
V_111 -> V_139 |= F_15 ( V_160 ) ;
}
} else {
V_111 -> V_161 = F_15 ( 0x80000000 ) ;
V_111 -> V_162 = F_15 ( 0x001f8000 ) ;
}
if ( V_18 -> V_163 == 1 ) {
struct V_78 * V_164 ;
V_164 = & V_134 ;
V_111 -> V_139 = F_15 ( V_164 -> V_139 ) ;
if ( V_129 )
V_111 -> V_139 |= F_15 ( V_155 ) ;
V_111 -> V_139 |= F_15 ( V_160 ) ;
V_111 -> V_161 = F_15 ( V_164 -> V_161 ) ;
V_111 -> V_162 = F_15 ( V_164 -> V_162 ) ;
V_18 -> V_163 = 0 ;
}
} else if ( V_31 -> V_37 == V_40 ) {
V_111 -> V_89 |= ( 0x05 ) & 0x1f ;
V_43 = ( V_106 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_111 -> V_89 |= F_15 ( ( V_43 << V_90 ) & 0x00001f00 ) ;
V_111 -> V_89 |= F_15 ( F_31 ( 16 ) ) ;
if ( V_129 )
V_111 -> V_139 |= F_15 ( V_155 ) ;
V_111 -> V_156 = F_15 ( ( V_18 -> V_23 << V_157 ) &
0x0fff0000 ) ;
V_111 -> V_161 = F_15 ( 0x80002040 ) ;
V_111 -> V_162 = F_15 ( 0x001f8000 ) ;
} else if ( V_31 -> V_37 == V_38 ) {
V_43 = 0x13 ;
V_111 -> V_89 |= F_15 ( ( V_43 << V_90 ) & 0x00001f00 ) ;
} else {
V_43 = ( V_106 ) ( V_18 -> V_23 & 0x0000001f ) ;
V_111 -> V_89 |= F_15 ( ( V_43 << V_90 ) & 0x00001f00 ) ;
V_111 -> V_156 = F_15 ( ( V_18 -> V_165 << V_157 ) &
0x0fff0000 ) ;
V_111 -> V_161 = F_15 ( 0x80002040 ) ;
V_111 -> V_162 = F_15 ( 0x001f9600 ) ;
}
}
int F_32 ( struct V_15 * V_16 ,
struct V_44 * V_45 ,
struct V_76 * V_77 )
{
struct V_46 * V_166 ;
T_1 V_167 ;
struct V_30 * V_31 = NULL ;
#ifdef F_29
struct V_30 * V_168 = NULL ;
#else
int V_169 = V_14 , V_170 = 0 ;
#endif
V_166 = V_45 -> V_171 ;
V_167 = V_45 -> V_172 ;
if ( V_77 == NULL ) {
V_77 = F_33 ( V_45 ) ;
if ( ! V_77 )
return false ;
#ifdef F_29
V_77 -> V_109 = 0 ;
#endif
}
V_31 = F_8 ( V_45 , V_166 , V_167 ) ;
if ( V_31 != NULL ) {
#ifdef F_29
if ( V_173 > 1 )
V_168 = F_8 ( V_45 , V_166 ,
V_167 ) ;
if ( V_31 -> V_37 != V_135 ) {
F_34 ( V_45 , V_77 ) ;
return false ;
}
if ( V_168 != NULL )
if ( V_168 -> V_37 != V_135 ) {
F_34 ( V_45 , V_77 ) ;
return false ;
}
F_23 ( V_77 , V_31 ) ;
if ( V_168 != NULL ) {
T_4 V_112 ;
V_112 = F_24 (
V_77 , V_168 ) ;
do {
V_168 = F_8 (
V_45 , V_166 , V_167 ) ;
if ( V_168 != NULL )
V_112 =
F_24 (
V_77 ,
V_168 ) ;
else
break;
} while ( V_112 <= 0x1800 &&
V_77 -> V_109 <= V_173 );
}
if ( V_77 -> V_109 > 0 )
F_26 ( V_77 , V_31 ) ;
#else
F_27 ( V_31 , V_77 ) ;
if ( V_31 -> V_37 == V_135 ) {
if ( V_31 -> V_33 . V_23 <= 15 )
V_169 = F_19 ( V_16 ,
V_31 -> V_102 , V_31 ) ;
F_20 ( V_16 , V_31 ) ;
}
if ( V_169 == V_14 )
F_35 ( V_16 , V_31 ) ;
else
F_25 ( V_45 , V_31 ) ;
V_170 ++ ;
#endif
} else {
F_34 ( V_45 , V_77 ) ;
return false ;
}
return true ;
}
static void F_35 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
int V_174 , V_118 , V_175 ;
T_2 * V_115 ;
T_3 V_5 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_44 * V_45 = & V_16 -> V_110 ;
struct V_125 * V_126 = & V_16 -> V_127 ;
if ( V_31 -> V_33 . V_103 != 0x0806 ) {
if ( V_31 -> V_33 . V_103 != 0x888e )
F_21 ( V_16 , V_18 -> V_23 ) ;
}
V_115 = V_31 -> V_107 ;
for ( V_174 = 0 ; V_174 < V_18 -> V_176 ; V_174 ++ ) {
if ( V_174 != ( V_18 -> V_176 - 1 ) ) {
V_118 = V_45 -> V_177 ;
V_118 = V_118 - 4 - ( V_126 -> V_178 ? 0 :
V_18 -> V_179 ) ;
V_31 -> V_105 [ V_174 ] = 0 ;
} else {
V_118 = V_18 -> V_100 ;
V_31 -> V_105 [ V_174 ] = 1 ;
}
F_22 ( V_31 , ( V_106 * ) V_115 , V_118 ) ;
V_175 = V_118 + V_83 ;
V_31 -> V_115 = V_115 ;
V_31 -> V_114 [ V_174 ] = false ;
V_5 = F_3 ( V_31 ) ;
#ifdef F_29
F_28 ( V_16 , V_39 , V_175 ,
( unsigned char * ) V_31 ) ;
#else
F_28 ( V_16 , V_5 , V_175 ,
( unsigned char * ) V_31 ) ;
#endif
V_115 += V_175 ;
V_115 = ( T_2 * ) F_36 ( ( ( V_180 ) ( V_115 ) ) ) ;
}
}
int F_37 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
int V_169 = V_14 ;
V_169 = F_19 ( V_16 , V_31 -> V_102 , V_31 ) ;
V_31 -> V_102 = NULL ;
if ( V_169 == V_14 )
F_35 ( V_16 , V_31 ) ;
return V_169 ;
}
int F_38 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
if ( F_39 ( V_16 , V_31 ) == V_181 ) {
V_31 -> V_102 = NULL ;
return V_181 ;
}
return V_14 ;
}
