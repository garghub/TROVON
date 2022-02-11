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
V_52 = F_5 ( V_49 ) ;
V_51 = F_6 ( V_52 ) ;
if ( ( F_7 ( V_52 , V_51 ) ) == false ) {
V_31 = F_8 ( V_51 ,
struct V_30 , V_53 ) ;
F_9 ( & V_31 -> V_53 ) ;
V_22 -> V_29 -- ;
V_47 -> V_54 ++ ;
}
return V_31 ;
}
static struct V_30 * F_10 ( struct V_44 * V_45 ,
struct V_46 * V_55 , T_1 V_56 )
{
unsigned long V_57 ;
struct V_50 * V_58 , * V_59 ;
struct V_46 * V_47 ;
struct V_21 * V_22 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_30 * V_31 = NULL ;
int V_60 , V_61 [ 4 ] ;
int V_62 , V_63 , V_64 [ 4 ] ;
V_61 [ 0 ] = 0 ; V_64 [ 0 ] = V_45 -> V_65 ;
V_61 [ 1 ] = 1 ; V_64 [ 1 ] = V_45 -> V_66 ;
V_61 [ 2 ] = 2 ; V_64 [ 2 ] = V_45 -> V_67 ;
V_61 [ 3 ] = 3 ; V_64 [ 3 ] = V_45 -> V_68 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
for ( V_62 = V_60 + 1 ; V_62 < 4 ; V_62 ++ ) {
if ( V_64 [ V_62 ] < V_64 [ V_60 ] ) {
V_63 = V_64 [ V_60 ] ;
V_64 [ V_60 ] = V_64 [ V_62 ] ;
V_64 [ V_62 ] = V_63 ;
V_63 = V_61 [ V_60 ] ;
V_61 [ V_60 ] = V_61 [ V_62 ] ;
V_61 [ V_62 ] = V_63 ;
}
}
}
F_11 ( & V_45 -> V_69 , V_57 ) ;
for ( V_60 = 0 ; V_60 < V_56 ; V_60 ++ ) {
V_47 = V_55 + V_61 [ V_60 ] ;
V_59 = F_5 ( V_47 -> V_70 ) ;
V_58 = F_6 ( V_59 ) ;
while ( ( F_7 ( V_59 , V_58 ) ) == false ) {
V_22 = F_8 ( V_58 , struct V_21 ,
V_71 ) ;
V_49 = & V_22 -> V_72 ;
V_31 = F_4 ( V_45 , V_47 ,
V_22 , V_49 ) ;
if ( V_31 ) {
V_47 -> V_73 -- ;
goto V_74;
}
V_58 = F_6 ( V_58 ) ;
if ( F_12 ( V_49 ) ) {
F_9 ( & V_22 -> V_71 ) ;
}
}
}
V_74:
F_13 ( & V_45 -> V_69 , V_57 ) ;
return V_31 ;
}
void F_14 ( struct V_15 * V_16 ,
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
T_2 F_15 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = (struct V_77 * ) V_76 -> V_79 ;
V_78 -> V_80 = F_16 ( V_81 & 0xffff ) ;
V_78 -> V_80 |=
F_16 ( ( ( V_82 + V_83 ) << V_84 ) & 0x00ff0000 ) ;
V_78 -> V_80 |= F_16 ( V_85 | V_86 | V_87 ) ;
V_78 -> V_88 |= F_16 ( ( 0x13 << V_89 ) & 0x00001f00 ) ;
return V_14 ;
}
T_2 F_17 ( struct V_75 * V_76 )
{
struct V_30 * V_31 = (struct V_30 * )
V_76 -> V_90 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_91 * V_92 = & ( V_16 -> V_93 ) ;
struct V_94 * V_95 = (struct V_94 * )
( V_76 -> V_79 + V_82 ) ;
V_95 -> V_96 = F_16 ( ( F_18 ( V_97 ) << 16 ) |
( V_92 -> V_98 << 24 ) ) ;
V_92 -> V_98 ++ ;
return V_14 ;
}
T_2 F_19 ( struct V_75 * V_76 ,
struct V_30 * V_31 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_77 * V_78 = (struct V_77 * ) V_76 -> V_79 ;
int V_99 = 0 ;
int V_100 = 0 ;
F_20 ( V_16 , V_31 -> V_101 , V_31 ) ;
F_21 ( V_16 , V_31 ) ;
if ( V_31 -> V_33 . V_102 != 0x0806 ) {
if ( ( V_31 -> V_33 . V_102 != 0x888e ) &&
( V_31 -> V_33 . V_103 != 1 ) ) {
F_22 ( V_16 ,
V_31 -> V_33 . V_23 ) ;
}
}
V_31 -> V_104 [ 0 ] = 1 ;
F_23 ( V_31 , ( V_105 * ) ( V_31 -> V_106 ) ,
V_31 -> V_33 . V_99 ) ;
V_99 = V_31 -> V_33 . V_99 ;
V_100 = ( 8 - ( V_99 % 8 ) ) ;
if ( ( V_99 % 8 ) != 0 ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_100 ; V_60 ++ )
* ( V_31 -> V_106 + V_82 + V_99 + V_60 ) = 0 ;
}
V_78 -> V_80 = F_16 ( ( V_78 -> V_80 & 0xffff0000 ) |
( ( V_78 -> V_80 & 0x0000ffff ) +
( ( V_82 + V_99 + V_100 ) & 0x0000ffff ) ) ) ;
return V_14 ;
}
T_2 F_24 ( struct V_75 * V_76 ,
struct V_30 * V_31 )
{
V_31 -> V_76 = V_76 ;
V_76 -> V_90 = V_31 ;
V_31 -> V_107 [ 0 ] = V_76 -> V_107 [ 0 ] ;
V_31 -> V_106 = V_76 -> V_79 + V_82 + V_81 ;
F_15 ( V_76 ) ;
F_17 ( V_76 ) ;
if ( F_19 ( V_76 , V_31 ) == V_14 )
V_76 -> V_108 = 1 ;
return V_14 ;
}
T_4 F_25 ( struct V_75 * V_76 ,
struct V_30 * V_31 )
{
V_31 -> V_76 = V_76 ;
V_76 -> V_90 = V_31 ;
V_31 -> V_107 [ 0 ] = V_76 -> V_107 [ 0 ] ;
V_31 -> V_106 = V_76 -> V_79 + V_82 +
( ( (struct V_77 * ) V_76 -> V_79 ) -> V_80 & 0x0000ffff ) ;
if ( F_19 ( V_76 , V_31 ) == V_14 ) {
F_26 ( & V_31 -> V_16 -> V_109 ,
V_31 ) ;
V_76 -> V_108 ++ ;
}
return V_82 +
( ( (struct V_77 * ) V_76 -> V_79 ) -> V_80 & 0x0000ffff ) ;
}
T_2 F_27 ( struct V_75 * V_76 ,
struct V_30 * V_31 )
{
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
struct V_77 * V_110 = (struct V_77 * ) V_76 -> V_79 ;
struct V_94 * V_95 = (struct V_94 * )
( V_76 -> V_79 + V_82 ) ;
T_4 V_111 = ( T_4 ) ( V_110 -> V_80 & 0xffff ) ;
F_28 ( V_31 , V_76 ) ;
V_95 -> V_96 = F_16 ( ( ( V_111 - V_81 ) & 0x0000ffff ) |
( V_95 -> V_96 & 0xffff0000 ) ) ;
V_95 -> V_112 = F_16 ( ( V_76 -> V_108 & 0xff ) |
( ( V_111 + V_82 ) << 16 ) ) ;
V_31 -> V_104 [ 0 ] = 1 ;
V_31 -> V_113 [ 0 ] = false ;
V_31 -> V_114 = V_76 -> V_79 ;
if ( ( V_35 -> V_115 && ( ( V_111 + V_82 ) % 0x200 ) == 0 ) ||
( ( ! V_35 -> V_115 &&
( ( V_111 + V_82 ) % 0x40 ) == 0 ) ) ) {
V_110 -> V_80 |= F_16
( ( ( V_82 + V_83 + 8 ) << V_84 ) & 0x00ff0000 ) ;
} else {
V_110 -> V_80 |= F_16
( ( ( V_82 + V_83 ) << V_84 ) & 0x00ff0000 ) ;
}
F_29 ( V_31 -> V_16 , V_39 ,
V_111 + V_82 , ( T_2 * ) V_31 ) ;
return V_14 ;
}
static void F_23 ( struct V_30 * V_31 , V_105 * V_116 , int V_117 )
{
V_105 V_43 ;
struct V_15 * V_16 = V_31 -> V_16 ;
struct V_118 * V_119 = & V_16 -> V_120 ;
struct V_121 * V_122 = & V_119 -> V_123 ;
struct V_124 * V_125 = & V_16 -> V_126 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_77 * V_110 = (struct V_77 * ) V_116 ;
struct V_34 * V_35 = (struct V_34 * ) & V_16 -> V_36 ;
#ifdef F_30
struct V_91 * V_92 = (struct V_91 * ) & V_16 -> V_93 ;
#endif
T_2 V_127 ;
T_1 V_128 = F_31 ( V_18 -> V_129 ) ;
struct V_130 * V_131 = & V_119 -> V_132 ;
struct V_77 V_133 ;
memcpy ( & V_133 , V_110 , sizeof( struct V_77 ) ) ;
memset ( V_110 , 0 , sizeof( struct V_77 ) ) ;
V_110 -> V_80 |= F_16 ( V_117 & 0x0000ffff ) ;
if ( V_35 -> V_115 ) {
if ( ( ( V_117 + V_82 ) % 512 ) == 0 )
V_127 = 1 ;
else
V_127 = 0 ;
} else {
if ( ( ( V_117 + V_82 ) % 64 ) == 0 )
V_127 = 1 ;
else
V_127 = 0 ;
}
if ( V_127 ) {
V_110 -> V_80 |= F_16 ( ( ( V_82 + V_83 + 8 ) <<
V_84 ) & 0x00ff0000 ) ;
} else {
V_110 -> V_80 |= F_16 ( ( ( V_82 + V_83 ) <<
V_84 ) & 0x00ff0000 ) ;
}
V_110 -> V_80 |= F_16 ( V_85 | V_86 | V_87 ) ;
if ( V_31 -> V_37 == V_134 ) {
V_110 -> V_88 |= F_16 ( ( V_18 -> V_135 ) & 0x1f ) ;
#ifdef F_30
if ( ( T_2 * ) V_116 != ( T_2 * ) V_31 -> V_76 -> V_79 ) {
V_110 -> V_80 |= F_16
( ( 0x3 << V_136 ) & V_137 ) ;
V_43 = ( V_105 ) ( V_18 -> V_43 & 0x0000001f ) ;
if ( V_43 == 2 )
V_43 = 0 ;
V_110 -> V_88 |= F_16
( ( V_43 << V_89 ) & 0x00001f00 ) ;
V_110 -> V_138 = F_16
( ( V_43 << V_139 ) & 0x001f0000 ) ;
V_110 -> V_140 |= F_16
( ( 0x5 << V_141 ) & V_142 ) ;
} else {
V_110 -> V_80 |= F_16
( ( 0x3 << V_136 ) & V_137 ) ;
V_110 -> V_88 |= F_16
( ( 0x13 << V_89 ) & 0x00001f00 ) ;
V_43 = ( V_105 ) ( V_18 -> V_43 & 0x0000001f ) ;
if ( V_43 == 2 )
V_43 = 0 ;
V_110 -> V_138 = F_16
( ( V_43 << V_139 ) & 0x0001f000 ) ;
V_110 -> V_143 |= F_16
( V_92 -> V_98 << 24 ) ;
V_92 -> V_98 ++ ;
}
V_18 -> V_43 = 0x13 ;
#else
V_43 = ( V_105 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_110 -> V_88 |= F_16 ( ( V_43 << V_89 ) & 0x00001f00 ) ;
#endif
if ( ! V_122 -> V_144 )
V_110 -> V_88 |= F_16 ( F_32 ( 16 ) ) ;
if ( ( V_18 -> V_145 > 0 ) && ! V_18 -> V_146 ) {
switch ( V_18 -> V_145 ) {
case V_147 :
case V_148 :
V_110 -> V_88 |= F_16 ( ( 0x01 << 22 ) &
0x00c00000 ) ;
V_110 -> V_88 |= F_16 ( ( V_125 ->
V_149 << 17 ) &
0x00060000 ) ;
break;
case V_150 :
case V_151 :
V_110 -> V_88 |= F_16 ( ( 0x02 << 22 ) &
0x00c00000 ) ;
break;
case V_152 :
V_110 -> V_88 |= F_16 ( ( 0x03 << 22 ) &
0x00c00000 ) ;
break;
case V_153 :
default:
break;
}
}
if ( V_128 )
V_110 -> V_138 |= F_16 ( V_154 ) ;
V_110 -> V_155 = F_16 ( ( V_18 -> V_23 << V_156 ) &
0x0fff0000 ) ;
if ( ( V_18 -> V_102 != 0x888e ) &&
( V_18 -> V_102 != 0x0806 ) &&
( V_18 -> V_103 != 1 ) ) {
if ( V_131 -> V_157 == 1 ) {
if ( V_131 -> V_158 != true )
V_110 -> V_138 |= F_16 ( V_159 ) ;
}
} else {
V_110 -> V_160 = F_16 ( 0x80000000 ) ;
V_110 -> V_161 = F_16 ( 0x001f8000 ) ;
}
if ( V_18 -> V_162 == 1 ) {
struct V_77 * V_163 ;
V_163 = & V_133 ;
V_110 -> V_138 = F_16 ( V_163 -> V_138 ) ;
if ( V_128 )
V_110 -> V_138 |= F_16 ( V_154 ) ;
V_110 -> V_138 |= F_16 ( V_159 ) ;
V_110 -> V_160 = F_16 ( V_163 -> V_160 ) ;
V_110 -> V_161 = F_16 ( V_163 -> V_161 ) ;
V_18 -> V_162 = 0 ;
}
} else if ( V_31 -> V_37 == V_40 ) {
V_110 -> V_88 |= ( 0x05 ) & 0x1f ;
V_43 = ( V_105 ) ( V_18 -> V_43 & 0x0000001f ) ;
V_110 -> V_88 |= F_16 ( ( V_43 << V_89 ) & 0x00001f00 ) ;
V_110 -> V_88 |= F_16 ( F_32 ( 16 ) ) ;
if ( V_128 )
V_110 -> V_138 |= F_16 ( V_154 ) ;
V_110 -> V_155 = F_16 ( ( V_18 -> V_23 << V_156 ) &
0x0fff0000 ) ;
V_110 -> V_160 = F_16 ( 0x80002040 ) ;
V_110 -> V_161 = F_16 ( 0x001f8000 ) ;
} else if ( V_31 -> V_37 == V_38 ) {
V_43 = 0x13 ;
V_110 -> V_88 |= F_16 ( ( V_43 << V_89 ) & 0x00001f00 ) ;
} else {
V_43 = ( V_105 ) ( V_18 -> V_23 & 0x0000001f ) ;
V_110 -> V_88 |= F_16 ( ( V_43 << V_89 ) & 0x00001f00 ) ;
V_110 -> V_155 = F_16 ( ( V_18 -> V_164 << V_156 ) &
0x0fff0000 ) ;
V_110 -> V_160 = F_16 ( 0x80002040 ) ;
V_110 -> V_161 = F_16 ( 0x001f9600 ) ;
}
}
int F_33 ( struct V_15 * V_16 ,
struct V_44 * V_45 ,
struct V_75 * V_76 )
{
struct V_46 * V_165 ;
T_1 V_166 ;
struct V_30 * V_31 = NULL ;
#ifdef F_30
struct V_30 * V_167 = NULL ;
#else
int V_168 = V_14 , V_169 = 0 ;
#endif
V_165 = V_45 -> V_170 ;
V_166 = V_45 -> V_171 ;
if ( V_76 == NULL ) {
V_76 = F_34 ( V_45 ) ;
if ( ! V_76 )
return false ;
#ifdef F_30
V_76 -> V_108 = 0 ;
#endif
}
V_31 = F_10 ( V_45 , V_165 , V_166 ) ;
if ( V_31 != NULL ) {
#ifdef F_30
if ( V_172 > 1 )
V_167 = F_10 ( V_45 , V_165 ,
V_166 ) ;
if ( V_31 -> V_37 != V_134 ) {
F_35 ( V_45 , V_76 ) ;
return false ;
}
if ( V_167 != NULL )
if ( V_167 -> V_37 != V_134 ) {
F_35 ( V_45 , V_76 ) ;
return false ;
}
F_24 ( V_76 , V_31 ) ;
if ( V_167 != NULL ) {
T_4 V_111 ;
V_111 = F_25 (
V_76 , V_167 ) ;
do {
V_167 = F_10 (
V_45 , V_165 , V_166 ) ;
if ( V_167 != NULL )
V_111 =
F_25 (
V_76 ,
V_167 ) ;
else
break;
} while ( V_111 <= 0x1800 &&
V_76 -> V_108 <= V_172 );
}
if ( V_76 -> V_108 > 0 )
F_27 ( V_76 , V_31 ) ;
#else
F_28 ( V_31 , V_76 ) ;
if ( V_31 -> V_37 == V_134 ) {
if ( V_31 -> V_33 . V_23 <= 15 )
V_168 = F_20 ( V_16 ,
V_31 -> V_101 , V_31 ) ;
F_21 ( V_16 , V_31 ) ;
}
if ( V_168 == V_14 )
F_36 ( V_16 , V_31 ) ;
else
F_26 ( V_45 , V_31 ) ;
V_169 ++ ;
#endif
} else {
F_35 ( V_45 , V_76 ) ;
return false ;
}
return true ;
}
static void F_36 ( struct V_15 * V_16 ,
struct V_30 * V_31 )
{
int V_173 , V_117 , V_174 ;
T_2 * V_114 ;
T_3 V_5 ;
struct V_17 * V_18 = & V_31 -> V_33 ;
struct V_44 * V_45 = & V_16 -> V_109 ;
struct V_124 * V_125 = & V_16 -> V_126 ;
if ( V_31 -> V_33 . V_102 != 0x0806 ) {
if ( V_31 -> V_33 . V_102 != 0x888e )
F_22 ( V_16 , V_18 -> V_23 ) ;
}
V_114 = V_31 -> V_106 ;
for ( V_173 = 0 ; V_173 < V_18 -> V_175 ; V_173 ++ ) {
if ( V_173 != ( V_18 -> V_175 - 1 ) ) {
V_117 = V_45 -> V_176 ;
V_117 = V_117 - 4 - ( V_125 -> V_177 ? 0 :
V_18 -> V_178 ) ;
V_31 -> V_104 [ V_173 ] = 0 ;
} else {
V_117 = V_18 -> V_99 ;
V_31 -> V_104 [ V_173 ] = 1 ;
}
F_23 ( V_31 , ( V_105 * ) V_114 , V_117 ) ;
V_174 = V_117 + V_82 ;
V_31 -> V_114 = V_114 ;
V_31 -> V_113 [ V_173 ] = false ;
V_5 = F_3 ( V_31 ) ;
#ifdef F_30
F_29 ( V_16 , V_39 , V_174 ,
( unsigned char * ) V_31 ) ;
#else
F_29 ( V_16 , V_5 , V_174 ,
( unsigned char * ) V_31 ) ;
#endif
V_114 += V_174 ;
V_114 = ( T_2 * ) F_37 ( ( ( V_179 ) ( V_114 ) ) ) ;
}
}
int F_38 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
int V_168 = V_14 ;
V_168 = F_20 ( V_16 , V_31 -> V_101 , V_31 ) ;
V_31 -> V_101 = NULL ;
if ( V_168 == V_14 )
F_36 ( V_16 , V_31 ) ;
return V_168 ;
}
int F_39 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
if ( F_40 ( V_16 , V_31 ) == V_180 ) {
V_31 -> V_101 = NULL ;
return V_180 ;
}
return V_14 ;
}
