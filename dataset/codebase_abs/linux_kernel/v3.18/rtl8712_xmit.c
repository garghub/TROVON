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
int V_64 , V_65 , V_66 [ 4 ] ;
V_63 [ 0 ] = 0 ; V_66 [ 0 ] = V_45 -> V_67 ;
V_63 [ 1 ] = 1 ; V_66 [ 1 ] = V_45 -> V_68 ;
V_63 [ 2 ] = 2 ; V_66 [ 2 ] = V_45 -> V_69 ;
V_63 [ 3 ] = 3 ; V_66 [ 3 ] = V_45 -> V_70 ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
for ( V_64 = V_62 + 1 ; V_64 < 4 ; V_64 ++ ) {
if ( V_66 [ V_64 ] < V_66 [ V_62 ] ) {
V_65 = V_66 [ V_62 ] ;
V_66 [ V_62 ] = V_66 [ V_64 ] ;
V_66 [ V_64 ] = V_65 ;
V_65 = V_63 [ V_62 ] ;
V_63 [ V_62 ] = V_63 [ V_64 ] ;
V_63 [ V_64 ] = V_65 ;
}
}
}
F_9 ( & V_45 -> V_71 , V_59 ) ;
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
V_47 = V_57 + V_63 [ V_62 ] ;
V_61 = & V_47 -> V_72 -> V_53 ;
V_60 = V_61 -> V_54 ;
while ( ( F_5 ( V_61 , V_60 ) ) == false ) {
V_22 = F_6 ( V_60 , struct V_21 ,
V_73 ) ;
V_49 = & V_22 -> V_74 ;
V_31 = F_4 ( V_45 , V_47 ,
V_22 , V_49 ) ;
if ( V_31 ) {
V_47 -> V_75 -- ;
goto V_76;
}
V_60 = V_60 -> V_54 ;
if ( F_10 ( & V_49 -> V_53 ) ) {
F_7 ( & V_22 -> V_73 ) ;
}
}
}
V_76:
F_11 ( & V_45 -> V_71 , V_59 ) ;
return V_31 ;
}
void F_12 ( struct V_15 * V_16 ,
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
T_2 F_13 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_78 -> V_81 ;
V_80 -> V_82 = F_14 ( V_83 & 0xffff ) ;
V_80 -> V_82 |=
F_14 ( ( ( V_84 + V_85 ) << V_86 ) & 0x00ff0000 ) ;
V_80 -> V_82 |= F_14 ( V_87 | V_88 | V_89 ) ;
V_80 -> V_90 |= F_14 ( ( 0x13 << V_91 ) & 0x00001f00 ) ;
return V_14 ;
}
T_2 F_15 ( struct V_77 * V_78 )
{
struct V_30 * V_31 = (struct V_30 * )
V_78 -> V_92 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_93 * V_94 = & ( V_16 -> V_95 ) ;
struct V_96 * V_97 = (struct V_96 * )
( V_78 -> V_81 + V_84 ) ;
V_97 -> V_98 = F_14 ( ( F_16 ( V_99 ) << 16 ) |
( V_94 -> V_100 << 24 ) ) ;
V_94 -> V_100 ++ ;
return V_14 ;
}
T_2 F_17 ( struct V_77 * V_78 ,
struct V_30 * V_31 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_79 * V_80 = (struct V_79 * ) V_78 -> V_81 ;
int V_101 = 0 ;
int V_102 = 0 ;
F_18 ( V_16 , V_31 -> V_103 , V_31 ) ;
F_19 ( V_16 , V_31 ) ;
if ( V_31 -> V_33 . V_104 != 0x0806 ) {
if ( ( V_31 -> V_33 . V_104 != 0x888e ) &&
( V_31 -> V_33 . V_105 != 1 ) ) {
F_20 ( V_16 ,
V_31 -> V_33 . V_23 ) ;
}
}
V_31 -> V_106 [ 0 ] = 1 ;
F_21 ( V_31 , ( V_107 * ) ( V_31 -> V_108 ) ,
V_31 -> V_33 . V_101 ) ;
V_101 = V_31 -> V_33 . V_101 ;
V_102 = ( 8 - ( V_101 % 8 ) ) ;
if ( ( V_101 % 8 ) != 0 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_102 ; V_62 ++ )
* ( V_31 -> V_108 + V_84 + V_101 + V_62 ) = 0 ;
}
V_80 -> V_82 = F_14 ( ( V_80 -> V_82 & 0xffff0000 ) |
( ( V_80 -> V_82 & 0x0000ffff ) +
( ( V_84 + V_101 + V_102 ) & 0x0000ffff ) ) ) ;
return V_14 ;
}
T_2 F_22 ( struct V_77 * V_78 ,
struct V_30 * V_31 )
{
V_31 -> V_78 = V_78 ;
V_78 -> V_92 = V_31 ;
V_31 -> V_109 [ 0 ] = V_78 -> V_109 [ 0 ] ;
V_31 -> V_108 = V_78 -> V_81 + V_84 + V_83 ;
F_13 ( V_78 ) ;
F_15 ( V_78 ) ;
if ( F_17 ( V_78 , V_31 ) == V_14 )
V_78 -> V_110 = 1 ;
return V_14 ;
}
T_4 F_23 ( struct V_77 * V_78 ,
struct V_30 * V_31 )
{
V_31 -> V_78 = V_78 ;
V_78 -> V_92 = V_31 ;
V_31 -> V_109 [ 0 ] = V_78 -> V_109 [ 0 ] ;
V_31 -> V_108 = V_78 -> V_81 + V_84 +
( ( (struct V_79 * ) V_78 -> V_81 ) -> V_82 & 0x0000ffff ) ;
if ( F_17 ( V_78 , V_31 ) == V_14 ) {
F_24 ( & V_31 -> V_16 -> V_111 ,
V_31 ) ;
V_78 -> V_110 ++ ;
}
return V_84 +
( ( (struct V_79 * ) V_78 -> V_81 ) -> V_82 & 0x0000ffff ) ;
}
T_2 F_25 ( struct V_77 * V_78 ,
struct V_30 * V_31 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
struct V_79 * V_112 = (struct V_79 * ) V_78 -> V_81 ;
struct V_96 * V_97 = (struct V_96 * )
( V_78 -> V_81 + V_84 ) ;
T_4 V_113 = ( T_4 ) ( V_112 -> V_82 & 0xffff ) ;
F_26 ( V_31 , V_78 ) ;
V_97 -> V_98 = F_14 ( ( ( V_113 - V_83 ) & 0x0000ffff ) |
( V_97 -> V_98 & 0xffff0000 ) ) ;
V_97 -> V_114 = F_14 ( ( V_78 -> V_110 & 0xff ) |
( ( V_113 + V_84 ) << 16 ) ) ;
V_31 -> V_106 [ 0 ] = 1 ;
V_31 -> V_115 [ 0 ] = false ;
V_31 -> V_116 = V_78 -> V_81 ;
if ( ( V_35 -> V_117 && ( ( V_113 + V_84 ) % 0x200 ) == 0 ) ||
( ( ! V_35 -> V_117 &&
( ( V_113 + V_84 ) % 0x40 ) == 0 ) ) ) {
V_112 -> V_82 |= F_14
( ( ( V_84 + V_85 + 8 ) << V_86 ) & 0x00ff0000 ) ;
} else {
V_112 -> V_82 |= F_14
( ( ( V_84 + V_85 ) << V_86 ) & 0x00ff0000 ) ;
}
F_27 ( V_31 -> V_16 , V_39 ,
V_113 + V_84 , ( T_2 * ) V_31 ) ;
return V_14 ;
}
static void F_21 ( struct V_30 * V_31 , V_107 * V_118 , int V_119 )
{
V_107 V_43 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_120 * V_121 = & V_16 -> V_122 ;
struct V_123 * V_124 = & V_121 -> V_125 ;
struct V_126 * V_127 = & V_16 -> V_128 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_79 * V_112 = (struct V_79 * ) V_118 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
#ifdef F_28
struct V_93 * V_94 = (struct V_93 * ) & V_16 -> V_95 ;
#endif
T_2 V_129 ;
T_1 V_130 = F_29 ( V_18 -> V_131 ) ;
struct V_132 * V_133 = & V_121 -> V_134 ;
struct V_79 V_135 ;
memcpy ( & V_135 , V_112 , sizeof( struct V_79 ) ) ;
memset ( V_112 , 0 , sizeof( struct V_79 ) ) ;
V_112 -> V_82 |= F_14 ( V_119 & 0x0000ffff ) ;
if ( V_35 -> V_117 ) {
if ( ( ( V_119 + V_84 ) % 512 ) == 0 )
V_129 = 1 ;
else
V_129 = 0 ;
} else {
if ( ( ( V_119 + V_84 ) % 64 ) == 0 )
V_129 = 1 ;
else
V_129 = 0 ;
}
if ( V_129 ) {
V_112 -> V_82 |= F_14 ( ( ( V_84 + V_85 + 8 ) <<
V_86 ) & 0x00ff0000 ) ;
} else {
V_112 -> V_82 |= F_14 ( ( ( V_84 + V_85 ) <<
V_86 ) & 0x00ff0000 ) ;
}
V_112 -> V_82 |= F_14 ( V_87 | V_88 | V_89 ) ;
if ( V_31 -> V_37 == V_136 ) {
V_112 -> V_90 |= F_14 ( ( V_18 -> V_137 ) & 0x1f ) ;
#ifdef F_28
if ( ( T_2 * ) V_118 != ( T_2 * ) V_31 -> V_78 -> V_81 ) {
V_112 -> V_82 |= F_14
( ( 0x3 << V_138 ) & V_139 ) ;
V_43 = ( V_107 ) ( V_18 -> V_43 & 0x0000001f ) ;
if ( V_43 == 2 )
V_43 = 0 ;
V_112 -> V_90 |= F_14
( ( V_43 << V_91 ) & 0x00001f00 ) ;
V_112 -> V_140 = F_14
( ( V_43 << V_141 ) & 0x001f0000 ) ;
V_112 -> V_142 |= F_14
( ( 0x5 << V_143 ) & V_144 ) ;
} else {
V_112 -> V_82 |= F_14
( ( 0x3 << V_138 ) & V_139 ) ;
V_112 -> V_90 |= F_14
( ( 0x13 << V_91 ) & 0x00001f00 ) ;
V_43 = ( V_107 ) ( V_18 -> V_43 & 0x0000001f ) ;
if ( V_43 == 2 )
V_43 = 0 ;
V_112 -> V_140 = F_14
( ( V_43 << V_141 ) & 0x0001f000 ) ;
V_112 -> V_145 |= F_14
( V_94 -> V_100 << 24 ) ;
V_94 -> V_100 ++ ;
}
V_18 -> V_43 = 0x13 ;
#else
V_43 = ( V_107 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_112 -> V_90 |= F_14 ( ( V_43 << V_91 ) & 0x00001f00 ) ;
#endif
if ( ! V_124 -> V_146 )
V_112 -> V_90 |= F_14 ( F_30 ( 16 ) ) ;
if ( ( V_18 -> V_147 > 0 ) && ! V_18 -> V_148 ) {
switch ( V_18 -> V_147 ) {
case V_149 :
case V_150 :
V_112 -> V_90 |= F_14 ( ( 0x01 << 22 ) &
0x00c00000 ) ;
V_112 -> V_90 |= F_14 ( ( V_127 ->
V_151 << 17 ) &
0x00060000 ) ;
break;
case V_152 :
case V_153 :
V_112 -> V_90 |= F_14 ( ( 0x02 << 22 ) &
0x00c00000 ) ;
break;
case V_154 :
V_112 -> V_90 |= F_14 ( ( 0x03 << 22 ) &
0x00c00000 ) ;
break;
case V_155 :
default:
break;
}
}
if ( V_130 )
V_112 -> V_140 |= F_14 ( V_156 ) ;
V_112 -> V_157 = F_14 ( ( V_18 -> V_23 << V_158 ) &
0x0fff0000 ) ;
if ( ( V_18 -> V_104 != 0x888e ) &&
( V_18 -> V_104 != 0x0806 ) &&
( V_18 -> V_105 != 1 ) ) {
if ( V_133 -> V_159 == 1 ) {
if ( V_133 -> V_160 != true )
V_112 -> V_140 |= F_14 ( V_161 ) ;
}
} else {
V_112 -> V_162 = F_14 ( 0x80000000 ) ;
V_112 -> V_163 = F_14 ( 0x001f8000 ) ;
}
if ( V_18 -> V_164 == 1 ) {
struct V_79 * V_165 ;
V_165 = & V_135 ;
V_112 -> V_140 = F_14 ( V_165 -> V_140 ) ;
if ( V_130 )
V_112 -> V_140 |= F_14 ( V_156 ) ;
V_112 -> V_140 |= F_14 ( V_161 ) ;
V_112 -> V_162 = F_14 ( V_165 -> V_162 ) ;
V_112 -> V_163 = F_14 ( V_165 -> V_163 ) ;
V_18 -> V_164 = 0 ;
}
} else if ( V_31 -> V_37 == V_40 ) {
V_112 -> V_90 |= ( 0x05 ) & 0x1f ;
V_43 = ( V_107 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_112 -> V_90 |= F_14 ( ( V_43 << V_91 ) & 0x00001f00 ) ;
V_112 -> V_90 |= F_14 ( F_30 ( 16 ) ) ;
if ( V_130 )
V_112 -> V_140 |= F_14 ( V_156 ) ;
V_112 -> V_157 = F_14 ( ( V_18 -> V_23 << V_158 ) &
0x0fff0000 ) ;
V_112 -> V_162 = F_14 ( 0x80002040 ) ;
V_112 -> V_163 = F_14 ( 0x001f8000 ) ;
} else if ( V_31 -> V_37 == V_38 ) {
V_43 = 0x13 ;
V_112 -> V_90 |= F_14 ( ( V_43 << V_91 ) & 0x00001f00 ) ;
} else {
V_43 = ( V_107 ) ( V_18 -> V_23 & 0x0000001f ) ;
V_112 -> V_90 |= F_14 ( ( V_43 << V_91 ) & 0x00001f00 ) ;
V_112 -> V_157 = F_14 ( ( V_18 -> V_166 << V_158 ) &
0x0fff0000 ) ;
V_112 -> V_162 = F_14 ( 0x80002040 ) ;
V_112 -> V_163 = F_14 ( 0x001f9600 ) ;
}
}
int F_31 ( struct V_15 * V_16 ,
struct V_44 * V_45 ,
struct V_77 * V_78 )
{
struct V_46 * V_167 ;
T_1 V_168 ;
struct V_30 * V_31 = NULL ;
#ifdef F_28
struct V_30 * V_169 = NULL ;
#else
int V_170 = V_14 , V_171 = 0 ;
#endif
V_167 = V_45 -> V_172 ;
V_168 = V_45 -> V_173 ;
if ( V_78 == NULL ) {
V_78 = F_32 ( V_45 ) ;
if ( ! V_78 )
return false ;
#ifdef F_28
V_78 -> V_110 = 0 ;
#endif
}
V_31 = F_8 ( V_45 , V_167 , V_168 ) ;
if ( V_31 != NULL ) {
#ifdef F_28
if ( V_174 > 1 )
V_169 = F_8 ( V_45 , V_167 ,
V_168 ) ;
if ( V_31 -> V_37 != V_136 ) {
F_33 ( V_45 , V_78 ) ;
return false ;
}
if ( V_169 != NULL )
if ( V_169 -> V_37 != V_136 ) {
F_33 ( V_45 , V_78 ) ;
return false ;
}
F_22 ( V_78 , V_31 ) ;
if ( V_169 != NULL ) {
T_4 V_113 ;
V_113 = F_23 (
V_78 , V_169 ) ;
do {
V_169 = F_8 (
V_45 , V_167 , V_168 ) ;
if ( V_169 != NULL )
V_113 =
F_23 (
V_78 ,
V_169 ) ;
else
break;
} while ( V_113 <= 0x1800 &&
V_78 -> V_110 <= V_174 );
}
if ( V_78 -> V_110 > 0 )
F_25 ( V_78 , V_31 ) ;
#else
F_26 ( V_31 , V_78 ) ;
if ( V_31 -> V_37 == V_136 ) {
if ( V_31 -> V_33 . V_23 <= 15 )
V_170 = F_18 ( V_16 ,
V_31 -> V_103 , V_31 ) ;
F_19 ( V_16 , V_31 ) ;
}
if ( V_170 == V_14 )
F_34 ( V_16 , V_31 ) ;
else
F_24 ( V_45 , V_31 ) ;
V_171 ++ ;
#endif
} else {
F_33 ( V_45 , V_78 ) ;
return false ;
}
return true ;
}
static void F_34 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
int V_175 , V_119 , V_176 ;
T_2 * V_116 ;
T_3 V_5 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_44 * V_45 = & V_16 -> V_111 ;
struct V_126 * V_127 = & V_16 -> V_128 ;
if ( V_31 -> V_33 . V_104 != 0x0806 ) {
if ( V_31 -> V_33 . V_104 != 0x888e )
F_20 ( V_16 , V_18 -> V_23 ) ;
}
V_116 = V_31 -> V_108 ;
for ( V_175 = 0 ; V_175 < V_18 -> V_177 ; V_175 ++ ) {
if ( V_175 != ( V_18 -> V_177 - 1 ) ) {
V_119 = V_45 -> V_178 ;
V_119 = V_119 - 4 - ( V_127 -> V_179 ? 0 :
V_18 -> V_180 ) ;
V_31 -> V_106 [ V_175 ] = 0 ;
} else {
V_119 = V_18 -> V_101 ;
V_31 -> V_106 [ V_175 ] = 1 ;
}
F_21 ( V_31 , ( V_107 * ) V_116 , V_119 ) ;
V_176 = V_119 + V_84 ;
V_31 -> V_116 = V_116 ;
V_31 -> V_115 [ V_175 ] = false ;
V_5 = F_3 ( V_31 ) ;
#ifdef F_28
F_27 ( V_16 , V_39 , V_176 ,
( unsigned char * ) V_31 ) ;
#else
F_27 ( V_16 , V_5 , V_176 ,
( unsigned char * ) V_31 ) ;
#endif
V_116 += V_176 ;
V_116 = ( T_2 * ) F_35 ( ( ( V_181 ) ( V_116 ) ) ) ;
}
}
int F_36 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
int V_170 = V_14 ;
V_170 = F_18 ( V_16 , V_31 -> V_103 , V_31 ) ;
V_31 -> V_103 = NULL ;
if ( V_170 == V_14 )
F_34 ( V_16 , V_31 ) ;
return V_170 ;
}
int F_37 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
if ( F_38 ( V_16 , V_31 ) == V_182 ) {
V_31 -> V_103 = NULL ;
return V_182 ;
}
return V_14 ;
}
