int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 * V_5 ;
* V_2 = 0 ;
V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_4 == - 1 ) {
return - 1 ;
}
if ( V_4 == V_6 ) {
return 0 ;
}
V_5 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ;
V_1 -> V_7 = ( void * ) V_5 ;
V_5 -> V_8 = V_4 ;
F_4 ( V_5 , V_4 ) ;
V_1 -> V_9 = 0 ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
if ( V_4 == V_18 || V_4 == V_19 || V_4 == V_20 )
V_1 -> V_21 = V_22 ;
else if ( V_4 == V_23 || V_4 == V_24 )
V_1 -> V_21 = V_25 ;
return 1 ;
}
static T_4 V_11 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_26 )
{
T_3 * V_5 = ( T_3 * ) V_1 -> V_7 ;
int V_27 = 0 , V_28 ;
if ( ! F_5 ( V_5 , V_1 -> V_29 , & V_27 , & V_28 , V_2 , V_3 ) )
return FALSE ;
* V_26 = ( F_6 ( V_1 -> V_29 ) - V_30 ) ;
if ( ! F_7 ( V_1 -> V_29 , V_27 , & V_1 -> V_31 ,
V_1 -> V_32 , V_5 , V_28 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_16 == V_33 )
V_1 -> V_16 = V_1 -> V_31 . V_34 ;
else {
if ( V_1 -> V_16 != V_1 -> V_31 . V_34 )
V_1 -> V_16 = V_35 ;
}
return TRUE ;
}
static T_4 V_13 ( T_1 * V_1 , T_5 V_36 ,
struct V_37 * V_31 , T_6 * V_38 , int * V_2 , T_2 * * V_3 )
{
T_3 * V_5 = ( T_3 * ) V_1 -> V_7 ;
int V_27 , V_28 ;
if ( F_8 ( V_1 -> V_39 , V_36 , V_40 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_5 ( V_5 , V_1 -> V_39 , & V_27 , & V_28 , V_2 , V_3 ) )
return FALSE ;
return F_7 ( V_1 -> V_39 , V_27 , V_31 , V_38 ,
V_5 , V_28 , V_2 , V_3 ) ;
}
static T_4 F_5 ( T_3 * V_5 , T_7 V_29 , int * V_27 , int * V_28 , int * V_2 , T_2 * * V_3 )
{
int V_41 , V_42 ;
T_8 V_43 [ V_30 ] ;
V_44 = V_45 ;
* V_27 = 0 ;
while ( 1 ) {
if ( F_9 ( V_43 , V_30 , V_29 ) != V_30 ) {
* V_2 = F_10 ( V_29 , V_3 ) ;
return FALSE ;
}
if ( ( V_41 = F_11 ( V_5 , V_43 , & V_42 , V_28 ) ) != 0 ) {
if ( V_41 > V_46 ) {
* V_2 = V_47 ;
* V_3 = F_12 ( L_1 , V_41 ) ;
return FALSE ;
}
else if ( V_42 != V_48 ) {
if ( F_8 ( V_29 , V_41 , V_49 , V_2 ) < 0 )
return FALSE ;
}
else {
* V_27 = V_41 ;
return TRUE ;
}
}
}
}
static int F_2 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_8 V_50 [ V_46 ] ;
T_8 V_43 [ V_30 ] ;
int V_27 = 0 ;
T_8 V_51 ;
T_8 * V_52 = NULL ;
T_8 * V_53 = NULL ;
T_8 * V_54 = NULL ;
T_5 V_55 = - 1 ;
T_9 V_56 = 0 ;
int V_41 , V_42 ;
T_10 V_57 = 0 ;
T_10 V_58 ;
int V_59 = - 1 ;
V_55 = F_6 ( V_1 -> V_29 ) ;
if ( V_55 == - 1 ) {
* V_2 = F_10 ( V_1 -> V_29 , V_3 ) ;
return - 1 ;
}
V_58 = 1000 ;
while ( ( F_9 ( V_43 , V_30 , V_1 -> V_29 ) ) == V_30 ) {
if ( ( V_41 = F_11 ( NULL , V_43 , & V_42 , NULL ) ) != 0 ) {
if ( V_41 > V_46 ) {
return V_6 ;
}
else if ( V_42 != V_48 ) {
if ( F_8 ( V_1 -> V_29 , V_41 , V_49 , V_2 ) < 0 )
return - 1 ;
else if ( V_42 == V_60 )
V_59 = 1 ;
}
else {
V_27 = V_41 ;
if ( F_9 ( V_50 , V_27 , V_1 -> V_29 ) != V_27 ) {
* V_2 = F_10 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_61 )
return - 1 ;
return V_6 ;
}
if ( V_27 > V_62 ) {
V_52 = & ( V_50 [ V_27 - V_62 ] ) ;
V_57 = F_13 ( & V_52 [ V_63 ] ) ;
V_51 = 0 ;
while ( ( ( V_57 + V_51 ) % 4 ) != 0 )
V_51 = V_51 + 1 ;
V_56 = F_14 ( & V_52 [ V_64 ] ) ;
if ( V_27 == ( V_57 + V_62 + V_51 ) && ( V_56 & V_65 ) == 0x1000000 ) {
V_58 = V_19 ;
}
}
if ( ( V_27 > V_66 ) && ( V_58 == 1000 ) ) {
V_54 = & ( V_50 [ V_27 - V_66 ] ) ;
V_57 = F_13 ( & V_54 [ V_67 ] ) ;
V_51 = 0 ;
while ( ( ( V_57 + V_51 ) % 4 ) != 0 )
V_51 = V_51 + 1 ;
if ( V_27 == ( V_57 + V_66 + V_51 ) )
V_58 = V_23 ;
}
if ( ( V_27 > V_68 ) && ( V_58 == 1000 ) ) {
V_57 = ( 256 * ( V_50 [ V_69 + 1 ] & 0x1f ) ) + V_50 [ V_69 ] ;
V_51 = 0 ;
while ( ( ( V_57 + V_51 ) % 4 ) != 0 )
V_51 = V_51 + 1 ;
if ( V_27 == ( V_57 + V_68 + V_70 + 12 + V_51 ) )
V_58 = V_18 ;
}
if ( ( V_27 > V_71 ) && ( V_58 == 1000 ) ) {
V_53 = & ( V_50 [ V_27 - V_71 ] ) ;
V_57 = F_13 ( & V_53 [ V_72 ] ) ;
V_51 = 0 ;
while ( ( ( V_57 + V_51 ) % 4 ) != 0 )
V_51 = V_51 + 1 ;
if ( V_27 == ( V_57 + V_71 + V_51 ) )
V_58 = V_24 ;
}
if ( ( V_27 > V_68 ) && ( V_58 == 1000 ) ) {
if ( V_43 [ 8 ] == 48 )
V_58 = V_20 ;
}
if ( V_58 != 1000 )
{
if ( F_8 ( V_1 -> V_29 , V_55 , V_40 , V_2 ) == - 1 ) {
return ( - 1 ) ;
}
return V_58 ;
}
}
}
}
if ( V_59 > 0 )
return ( V_20 ) ;
* V_2 = F_10 ( V_1 -> V_29 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_61 )
return - 1 ;
return V_6 ;
}
static T_4 F_15 ( T_3 * V_5 , struct V_37 * V_31 ,
T_6 * V_38 , const T_8 * V_50 , int V_27 ,
int * V_2 , T_2 * * V_3 )
{
T_8 * V_73 ;
int V_74 = 0 ;
const T_8 * V_75 , * V_76 ;
T_10 V_77 , V_78 ;
T_10 V_79 ;
T_10 V_80 ;
T_8 V_81 ;
T_11 V_82 ;
T_12 V_83 = V_84 , V_85 = V_84 ;
T_9 V_86 ;
T_12 V_87 , V_88 , V_89 = V_84 ;
T_12 V_90 ;
T_9 V_91 ;
T_13 V_92 ;
int V_93 ;
T_8 V_94 , V_95 , V_96 ;
T_10 V_97 , V_98 = 0 ;
T_11 V_99 ;
T_9 V_100 , V_101 ;
int V_102 , V_103 ;
T_12 V_104 ;
T_10 V_105 ;
T_10 V_106 ;
if ( V_27 < V_62 ) {
* V_3 = F_12 ( L_2 ,
V_27 , V_62 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_75 = & ( V_50 [ V_27 - V_62 ] ) ;
V_81 = V_75 [ V_107 ] & 0x7 ;
V_93 = ! ( V_75 [ V_107 ] & 0x8 ) ;
V_78 = F_13 ( & V_75 [ V_63 ] ) ;
V_97 = F_13 ( & V_75 [ V_108 ] ) & 0x3ff ;
V_82 = V_75 [ V_109 ] ;
V_86 = ( T_9 ) F_16 ( & V_75 [ V_110 ] ) ;
V_99 = F_13 ( & V_75 [ V_111 + 1 ] ) ;
V_101 = F_13 ( & V_75 [ V_112 ] ) ;
V_91 = F_13 ( & V_75 [ V_113 ] ) ;
V_92 = ( V_75 [ V_114 ] & 0x80 ) ? ( - 1 * ( V_75 [ V_114 ] & 0x7f ) ) : V_75 [ V_114 ] ;
if ( V_78 > V_27 - V_62 ) {
* V_3 = F_12 ( L_3 ,
V_78 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_94 = 0 ;
V_96 = 1 ;
if ( V_81 == V_5 -> V_115 )
V_95 = F_17 ( V_50 ) ;
else if ( ( V_81 == V_5 -> V_116 ) || ( V_81 == V_5 -> V_117 ) )
V_95 = F_18 ( V_50 ) ;
else
V_95 = 1 ;
V_80 = ( V_81 == V_5 -> V_117 ) ? V_118 : 0 ;
V_79 = ( V_81 == V_5 -> V_115 ) ? 4 : 6 ;
if ( V_78 >= V_79 )
V_78 -= V_79 ;
else {
* V_3 = F_12 ( L_4 ,
V_78 , V_79 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_76 = & V_50 [ V_79 ] ;
V_77 = V_78 ;
if ( V_78 < 4 ) {
* V_3 = F_12 ( L_5 ,
V_78 , V_79 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_78 -= 4 ;
V_83 = F_19 ( & V_75 [ V_119 ] ) ;
V_85 = F_19 ( & V_75 [ V_120 ] ) ;
V_100 = ( T_9 ) ( ( V_85 - V_83 ) / V_121 ) ;
V_87 = V_83 / V_121 ;
V_88 = ( V_87 / V_122 ) ;
V_89 = V_87 - ( V_88 * V_122 ) ;
V_90 = V_85 / V_121 ;
V_103 = 42 ;
V_102 = F_20 ( V_76 , V_27 - 6 , V_103 , V_99 , V_82 ) ;
if ( ( V_76 [ V_102 ] == 0xdd ) && ( V_102 + 15 <= ( V_27 - V_62 ) ) )
V_104 = F_21 ( V_76 , V_102 ) ;
else
V_104 = 0 ;
V_31 -> V_123 = V_124 + V_125 + V_78 ;
V_31 -> V_126 = V_124 + V_125 + V_78 ;
V_31 -> V_127 . V_128 = ( V_129 ) V_88 ;
V_31 -> V_127 . V_130 = ( int ) ( V_89 * 1000 ) ;
V_31 -> V_34 = V_17 ;
V_31 -> V_131 = V_132 ;
V_31 -> V_133 = V_134 ;
F_22 ( V_38 , V_31 -> V_126 ) ;
V_73 = F_23 ( V_38 ) ;
F_24 ( & V_73 [ V_74 ] , 0 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_124 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_77 ) ;
V_74 += 2 ;
F_25 ( & V_73 [ V_74 ] , V_99 ) ;
V_74 += 4 ;
F_24 ( & V_73 [ V_74 ] , V_97 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_82 ) ;
V_74 += 2 ;
if ( ! V_93 && V_104 != 0 ) {
F_25 ( & V_73 [ V_74 ] , V_86 ) ;
} else {
F_25 ( & V_73 [ V_74 ] , 0 ) ;
}
V_74 += 4 ;
F_25 ( & V_73 [ V_74 ] , V_104 ) ;
V_74 += 4 ;
F_26 ( & V_73 [ V_74 ] , V_87 ) ;
V_74 += 8 ;
F_26 ( & V_73 [ V_74 ] , V_90 ) ;
V_74 += 8 ;
F_25 ( & V_73 [ V_74 ] , V_100 ) ;
V_74 += 4 ;
F_24 ( & V_73 [ V_74 ] , V_125 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_80 ) ;
V_74 += 2 ;
if ( V_81 == V_5 -> V_115 ) {
F_24 ( & V_73 [ V_74 ] , V_135 ) ;
} else {
F_24 ( & V_73 [ V_74 ] , V_136 ) ;
}
V_74 += 2 ;
V_105 = ( T_10 ) ( F_27 ( V_94 , V_95 , V_80 , V_96 ) * 10 ) ;
F_24 ( & V_73 [ V_74 ] , V_105 ) ;
V_74 += 2 ;
V_73 [ V_74 ] = V_94 ;
V_74 += 1 ;
V_73 [ V_74 ] = V_95 ;
V_74 += 1 ;
V_73 [ V_74 ] = V_96 ;
V_74 += 1 ;
V_73 [ V_74 ] = V_92 ;
V_74 += 1 ;
V_73 [ V_74 ] = 100 ;
V_74 += 1 ;
V_73 [ V_74 ] = 100 ;
V_74 += 1 ;
V_73 [ V_74 ] = 100 ;
V_74 += 1 ;
V_73 [ V_74 ] = 0 ;
V_74 += 1 ;
V_106 = 0 ;
if ( V_93 )
V_106 |= V_137 ;
if ( V_101 & V_5 -> V_138 )
V_106 |= V_139 ;
if ( ! V_93 && ( V_101 & V_5 -> V_140 ) )
V_106 |= V_141 ;
if ( ! V_93 && ( V_101 & V_5 -> V_142 ) )
V_106 |= V_143 ;
if ( V_91 & V_5 -> V_144 )
V_106 |= V_145 ;
else if ( V_91 & V_5 -> V_146 )
V_106 |= V_147 ;
else if ( V_91 & V_5 -> V_148 )
V_106 |= V_149 ;
F_24 ( & V_73 [ V_74 ] , V_106 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_98 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_91 ) ;
V_74 += 2 ;
F_25 ( & V_73 [ V_74 ] , V_101 ) ;
V_74 += 4 ;
memcpy ( & V_73 [ V_74 ] , & V_50 [ V_79 ] , V_78 ) ;
return TRUE ;
}
static T_4 F_28 ( T_3 * V_5 , struct V_37 * V_31 ,
T_6 * V_38 , const T_8 * V_50 , int V_27 ,
int V_28 , int * V_2 , T_2 * * V_3 )
{
T_8 * V_73 ;
int V_74 = 0 ;
register int V_51 ;
const T_8 * V_150 , * V_151 , * V_152 , * V_76 ;
T_9 V_77 , V_78 ;
T_8 V_153 , V_154 , V_94 , V_95 , V_96 ;
T_11 V_82 ;
T_12 V_83 = V_84 , V_85 = V_84 ;
T_12 V_86 = V_84 ;
T_12 V_87 , V_88 , V_89 = V_84 ;
T_12 V_90 ;
T_10 V_91 ;
T_9 V_101 ;
T_13 V_92 [] = { 0 , 0 , 0 , 0 } ;
int V_93 ;
T_10 V_97 , V_98 = 0 ;
T_9 V_99 , V_100 ;
int V_102 , V_103 ;
T_12 V_104 , V_155 ;
T_10 V_156 = 0 ;
T_10 V_157 = 0 ;
T_12 V_158 ;
T_10 V_105 ;
T_10 V_106 ;
if ( V_27 < V_159 + V_68 ) {
* V_3 = F_12 ( L_2 ,
V_27 ,
V_159 + V_68 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_150 = & ( V_50 [ 0 ] ) ;
V_151 = & ( V_50 [ V_27 - V_68 ] ) ;
V_153 = V_150 [ V_160 ] ;
V_154 = V_150 [ V_161 ] ;
if ( V_5 -> V_8 == V_18 )
{
V_95 = V_153 & 0x3f ;
V_94 = V_154 & 0x03 ;
V_77 = ( ( V_150 [ V_69 + 1 ] & 0x1f ) << 8 )
+ V_150 [ V_69 ] ;
V_97 = F_13 ( & V_150 [ V_162 ] ) ;
if ( V_28 )
{
V_92 [ 0 ] = ( V_150 [ V_163 ] & 0x80 ) ?
- 1 * ( V_150 [ V_163 ] & 0x7f ) :
V_150 [ V_163 ] & 0x7f ;
}
else
{
V_92 [ 0 ] = ( V_150 [ V_163 ] & 0x80 ) ?
( V_150 [ V_163 ] - 256 ) :
V_150 [ V_163 ] ;
}
V_92 [ 1 ] = 100 ;
V_92 [ 2 ] = 100 ;
V_92 [ 3 ] = 100 ;
V_96 = 0 ;
V_152 = & ( V_50 [ 8 ] ) ;
}
else
{
V_94 = V_154 & 0xf ;
if ( V_94 == V_164 )
{
V_95 = V_153 & 0x0f ;
V_96 = ( V_153 >> 4 & 0x3 ) + 1 ;
}
else
{
V_95 = V_153 & 0x3f ;
V_96 = 0 ;
}
V_77 = F_29 ( & V_150 [ 9 ] ) ;
V_97 = F_13 ( & V_150 [ 14 ] ) & 0x3ff ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
{
if ( V_28 )
{
V_92 [ V_51 ] = ( V_150 [ 4 + V_51 ] & 0x80 ) ? - 1 * ( V_150 [ 4 + V_51 ] & 0x7f ) : V_150 [ 4 + V_51 ] & 0x7f ;
}
else
{
V_92 [ V_51 ] = ( V_150 [ 4 + V_51 ] >= 128 ) ? ( V_150 [ 4 + V_51 ] - 256 ) : V_150 [ 4 + V_51 ] ;
}
}
V_152 = & ( V_50 [ 16 ] ) ;
}
V_78 = V_77 ;
if ( V_78 > V_27 - ( V_5 -> V_165 + V_68 ) ) {
* V_3 = F_12 ( L_3 ,
V_78 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_93 = V_28 ;
V_82 = V_151 [ V_166 ] ;
V_86 = 0x00000000 ;
V_99 = F_29 ( & V_151 [ V_167 ] ) ;
V_155 = F_16 ( & V_151 [ V_168 ] ) ;
V_101 = F_14 ( & V_151 [ V_169 ] ) ;
V_91 = F_13 ( & V_151 [ V_170 ] ) ;
if ( ( V_91 & 0xFC00 ) != 0 )
V_98 = F_30 ( & V_150 [ V_5 -> V_171 ] ) ;
if ( V_94 == V_172 ) {
if ( V_95 < 4 ) {
V_156 |= V_136 ;
}
else {
V_156 |= V_135 ;
}
}
else if ( V_94 == V_173 ) {
V_157 |= V_174 | ( ( V_152 [ 3 ] & 0x80 ) ? V_175 : 0 ) |
( ( V_153 & 0x40 ) ? 0 : V_176 ) ;
V_156 |= V_135 ;
}
else if ( V_94 == V_177 ) {
V_157 |= V_174 | ( ( V_152 [ 0 ] & 0x80 ) ? V_175 : 0 ) |
( ( V_153 & 0x40 ) ? 0 : V_176 ) ;
V_156 |= V_135 ;
}
else if ( V_94 == V_164 ) {
T_8 V_178 = V_154 >> 4 & 0xf ;
V_157 |= V_179 | ( ( V_153 & 0x40 ) ? 0 : V_176 ) ;
V_156 |= V_135 ;
if ( V_178 == 3 )
V_157 |= V_175 ;
else if ( V_178 == 4 )
V_157 |= V_180 ;
}
if ( V_78 < 4 ) {
* V_3 = F_12 ( L_6 ,
V_78 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_78 -= 4 ;
V_83 = F_19 ( & V_151 [ V_181 ] ) ;
V_85 = F_19 ( & V_151 [ V_182 ] ) ;
V_100 = ( T_9 ) ( ( V_85 - V_83 ) / V_121 ) ;
V_87 = V_83 / V_121 ;
V_88 = ( V_87 / V_122 ) ;
V_89 = V_87 - ( V_88 * V_122 ) ;
V_90 = V_85 / V_121 ;
V_76 = & ( V_50 [ 8 + 12 ] ) ;
V_103 = 42 ;
V_102 = F_20 ( V_76 , V_27 - 20 , V_103 , V_99 , V_82 ) ;
if ( ( V_76 [ V_102 ] == 0xdd ) && ( V_102 + 15 <= ( V_27 - V_68 ) ) )
V_104 = F_21 ( V_76 , V_102 ) ;
else
V_104 = 0 ;
if ( ! V_28 ) {
if ( V_155 < V_83 ) {
V_86 = V_83 - V_155 ;
} else {
V_158 = V_155 - V_83 ;
if ( V_158 > 0x10000000 )
V_86 = 0 ;
else
V_86 = V_158 ;
}
}
V_31 -> V_123 = V_124 + V_125 + V_78 ;
V_31 -> V_126 = V_124 + V_125 + V_78 ;
V_31 -> V_127 . V_128 = ( V_129 ) V_88 ;
V_31 -> V_127 . V_130 = ( int ) ( V_89 * 1000 ) ;
V_31 -> V_34 = V_17 ;
V_31 -> V_131 = V_132 ;
V_31 -> V_133 = V_134 ;
F_22 ( V_38 , V_31 -> V_126 ) ;
V_73 = F_23 ( V_38 ) ;
F_24 ( & V_73 [ V_74 ] , 0 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_124 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_77 ) ;
V_74 += 2 ;
F_25 ( & V_73 [ V_74 ] , V_99 ) ;
V_74 += 4 ;
F_24 ( & V_73 [ V_74 ] , V_97 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_82 ) ;
V_74 += 2 ;
if ( ! V_93 && V_104 != 0 ) {
F_25 ( & V_73 [ V_74 ] , V_86 ) ;
} else {
F_25 ( & V_73 [ V_74 ] , 0 ) ;
}
V_74 += 4 ;
F_25 ( & V_73 [ V_74 ] , V_104 ) ;
V_74 += 4 ;
F_26 ( & V_73 [ V_74 ] , V_87 ) ;
V_74 += 8 ;
F_26 ( & V_73 [ V_74 ] , V_90 ) ;
V_74 += 8 ;
F_25 ( & V_73 [ V_74 ] , V_100 ) ;
V_74 += 4 ;
F_24 ( & V_73 [ V_74 ] , V_125 ) ;
V_74 += 2 ;
if ( V_91 & V_183 )
V_157 |= V_184 ;
if ( ( V_153 & V_185 ) != V_186 && ( V_94 == V_172 ) )
V_157 |= V_118 ;
F_24 ( & V_73 [ V_74 ] , V_157 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_156 ) ;
V_74 += 2 ;
V_105 = ( T_10 ) ( F_27 ( V_94 , V_95 , V_157 , V_96 ) * 10 ) ;
F_24 ( & V_73 [ V_74 ] , V_105 ) ;
V_74 += 2 ;
V_73 [ V_74 ] = V_94 ;
V_74 += 1 ;
V_73 [ V_74 ] = V_95 ;
V_74 += 1 ;
V_73 [ V_74 ] = V_96 ;
V_74 += 1 ;
V_73 [ V_74 ] = V_92 [ 0 ] ;
V_74 += 1 ;
V_73 [ V_74 ] = V_92 [ 1 ] ;
V_74 += 1 ;
V_73 [ V_74 ] = V_92 [ 2 ] ;
V_74 += 1 ;
V_73 [ V_74 ] = V_92 [ 3 ] ;
V_74 += 1 ;
V_73 [ V_74 ] = 0 ;
V_74 += 1 ;
V_106 = 0 ;
if ( V_93 )
V_106 |= V_137 ;
if ( V_101 & 0x1f )
V_106 |= V_139 ;
if ( ! V_93 && ( V_101 & V_5 -> V_140 ) )
V_106 |= V_141 ;
if ( ! V_93 && ( V_101 & V_5 -> V_142 ) )
V_106 |= V_143 ;
if ( V_91 & V_5 -> V_144 )
V_106 |= V_145 ;
else if ( V_91 & V_5 -> V_146 )
V_106 |= V_147 ;
else if ( V_91 & V_5 -> V_148 )
V_106 |= V_149 ;
F_24 ( & V_73 [ V_74 ] , V_106 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_98 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_91 ) ;
V_74 += 2 ;
F_25 ( & V_73 [ V_74 ] , V_101 ) ;
V_74 += 4 ;
memcpy ( & V_73 [ V_74 ] , & V_50 [ V_5 -> V_165 ] , V_78 ) ;
return TRUE ;
}
static T_4 F_31 ( T_3 * V_5 , struct V_37 * V_31 ,
T_6 * V_38 , const T_8 * V_50 ,
int V_27 , int V_28 , int * V_2 ,
T_2 * * V_3 )
{
T_8 * V_73 ;
int V_74 = 0 ;
const T_8 * V_75 , * V_76 ;
T_10 V_77 , V_78 ;
T_11 V_82 ;
T_12 V_83 = V_84 , V_85 = V_84 ;
T_9 V_86 = 0 ;
T_12 V_87 , V_88 , V_89 = V_84 ;
T_12 V_90 ;
T_11 V_187 ;
T_10 V_91 , V_188 ;
T_9 V_101 ;
T_10 V_97 ;
T_9 V_99 , V_100 ;
int V_189 ;
T_9 V_56 ;
int V_190 , V_102 , V_103 ;
T_12 V_104 ;
T_12 V_158 ;
T_10 V_106 ;
if ( V_27 < ( int ) V_5 -> V_191 ) {
* V_3 = F_12 ( L_2 , V_27 , V_5 -> V_191 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_76 = & ( V_50 [ 0 ] ) ;
V_75 = & ( V_50 [ V_27 - V_5 -> V_191 ] ) ;
V_77 = F_13 ( & V_75 [ V_5 -> V_192 ] ) ;
V_78 = V_77 ;
if ( V_78 > V_27 - V_5 -> V_191 ) {
* V_3 = F_12 ( L_3 ,
V_78 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_97 = F_13 ( & V_75 [ V_5 -> V_193 ] ) & V_5 -> V_194 ;
V_82 = V_75 [ V_5 -> V_195 ] ;
V_56 = F_14 ( & V_75 [ V_5 -> V_196 ] ) ;
if ( V_5 -> V_8 == V_24 ) {
V_188 = F_13 ( & V_75 [ V_5 -> V_197 ] ) ;
V_189 = V_188 & V_5 -> V_198 ;
V_190 = ( V_188 & V_5 -> V_199 ) ? 16 : 14 ;
V_101 = F_13 ( & V_75 [ V_5 -> V_200 ] ) ;
}
else {
V_189 = V_75 [ V_5 -> V_197 ] & V_5 -> V_198 ;
V_190 = ( V_56 & V_5 -> V_199 ) ? 16 : 14 ;
V_101 = F_13 ( & V_75 [ V_5 -> V_200 ] ) ;
}
V_91 = F_13 ( & V_75 [ V_5 -> V_201 ] ) ;
V_99 = F_29 ( & V_75 [ V_5 -> V_202 ] ) ;
#if 0
tsid = pcorey48tohll(&s_ptr[vwr->LATVAL_OFF]);
#endif
V_187 = F_13 ( & V_75 [ V_5 -> V_203 ] ) ;
if ( V_78 < 4 ) {
* V_3 = F_12 ( L_6 ,
V_78 ) ;
* V_2 = V_47 ;
return FALSE ;
}
V_78 -= 4 ;
V_83 = F_19 ( & V_75 [ V_5 -> V_204 ] ) ;
V_85 = F_19 ( & V_75 [ V_5 -> V_205 ] ) ;
V_100 = ( T_9 ) ( ( V_85 - V_83 ) ) ;
V_87 = V_83 / V_121 ;
V_88 = ( V_87 / V_122 ) ;
V_89 = V_87 - ( V_88 * V_122 ) ;
V_90 = V_85 / V_121 ;
if ( V_56 & V_5 -> V_206 )
{
V_103 = V_190 + 40 ;
}
else if ( V_56 & V_5 -> V_207 )
{
V_103 = V_190 + 28 ;
}
else if ( V_56 & V_5 -> V_208 )
{
V_103 = V_190 + 24 ;
}
else if ( V_56 & V_5 -> V_209 )
{
V_103 = V_190 + 28 ;
}
else
{
V_103 = V_190 + 20 ;
}
V_102 = F_20 ( V_76 , V_27 , V_103 , V_99 , V_82 ) ;
if ( ( V_76 [ V_102 ] == 0xdd ) && ( V_102 + 15 <= V_77 ) && ( V_189 != 0 ) )
V_104 = F_21 ( V_76 , V_102 ) ;
else
V_104 = 0 ;
if ( ! V_28 ) {
if ( V_104 < V_83 ) {
V_86 = ( T_9 ) ( V_83 - V_104 ) ;
} else {
V_158 = V_104 - V_83 ;
if ( V_158 > 0x10000000 ) {
V_86 = 0 ;
} else
V_86 = ( T_9 ) V_158 ;
}
}
V_31 -> V_123 = V_124 + V_125 + V_78 ;
V_31 -> V_126 = V_124 + V_125 + V_78 ;
V_31 -> V_127 . V_128 = ( V_129 ) V_88 ;
V_31 -> V_127 . V_130 = ( int ) ( V_89 * 1000 ) ;
V_31 -> V_34 = V_17 ;
V_31 -> V_131 = V_132 ;
V_31 -> V_133 = V_134 ;
F_22 ( V_38 , V_31 -> V_126 ) ;
V_73 = F_23 ( V_38 ) ;
F_24 ( & V_73 [ V_74 ] , 1 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_124 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_77 ) ;
V_74 += 2 ;
F_25 ( & V_73 [ V_74 ] , V_99 ) ;
V_74 += 4 ;
F_24 ( & V_73 [ V_74 ] , V_97 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_82 ) ;
V_74 += 2 ;
if ( ! V_28 && ( V_104 != 0 ) ) {
F_25 ( & V_73 [ V_74 ] , V_86 ) ;
} else {
F_25 ( & V_73 [ V_74 ] , 0 ) ;
}
V_74 += 4 ;
F_25 ( & V_73 [ V_74 ] , V_104 ) ;
V_74 += 4 ;
F_26 (&data_ptr[bytes_written], start_time)
V_74 += 8 ;
F_26 ( & V_73 [ V_74 ] , V_90 ) ;
V_74 += 8 ;
F_25 ( & V_73 [ V_74 ] , V_100 ) ;
V_74 += 4 ;
F_24 ( & V_73 [ V_74 ] , V_210 ) ;
V_74 += 2 ;
V_106 = 0 ;
if ( V_28 )
V_106 |= V_137 ;
if ( V_101 & V_5 -> V_138 )
V_106 |= V_139 ;
F_24 ( & V_73 [ V_74 ] , V_106 ) ;
V_74 += 2 ;
F_24 ( & V_73 [ V_74 ] , V_91 ) ;
V_74 += 2 ;
F_25 ( & V_73 [ V_74 ] , V_101 ) ;
V_74 += 4 ;
F_25 ( & V_73 [ V_74 ] , V_187 ) ;
V_74 += 4 ;
F_25 ( & V_73 [ V_74 ] , 0 ) ;
V_74 += 4 ;
memcpy ( & V_73 [ V_74 ] , V_76 , V_78 ) ;
return TRUE ;
}
static int F_11 ( T_3 * V_5 , T_8 * V_50 , int * V_42 , int * V_28 )
{
T_8 V_211 ;
T_9 V_212 , V_213 ;
int V_214 = 0 ;
V_211 = V_50 [ 0 ] ;
V_212 = F_14 ( & V_50 [ 8 ] ) ;
V_213 = F_14 ( & V_50 [ 12 ] ) ;
if ( V_5 != NULL ) {
if ( ( V_211 & V_5 -> V_215 ) == V_5 -> V_215 )
* V_28 = 1 ;
else if ( ( V_211 & V_5 -> V_216 ) == V_5 -> V_216 )
* V_28 = 0 ;
else * V_28 = 2 ;
}
switch ( V_211 ) {
case 0x21 :
case 0x31 :
V_214 = ( int ) ( V_212 & 0xffff ) ;
* V_42 = V_48 ;
break;
case 0xc1 :
case 0x8b :
V_214 = ( int ) ( V_212 & 0xffff ) ;
* V_42 = V_60 ;
break;
case 0xfe :
V_214 = ( int ) ( V_213 & 0xffff ) ;
* V_42 = V_60 ;
break;
default:
break;
}
return V_214 ;
}
static T_8 F_17 ( const T_8 * V_217 )
{
switch ( V_217 [ 0 ] & 0x0f ) {
case 0x0b : return 4 ;
case 0x0f : return 5 ;
case 0x0a : return 6 ;
case 0x0e : return 7 ;
case 0x09 : return 8 ;
case 0x0d : return 9 ;
case 0x08 : return 10 ;
case 0x0c : return 11 ;
default: return 0 ;
}
}
static T_8 F_18 ( const T_8 * V_217 )
{
switch ( V_217 [ 0 ] ) {
case 0x0a : return 0 ;
case 0x14 : return 1 ;
case 0x37 : return 2 ;
case 0x6e : return 3 ;
default: return 0 ;
}
}
static void F_4 ( T_3 * V_5 , T_10 V_218 )
{
switch ( V_218 ) {
case V_18 :
V_5 -> V_191 = V_68 ;
V_5 -> V_197 = V_219 ;
V_5 -> V_220 = V_221 ;
V_5 -> V_193 = V_162 ;
V_5 -> V_195 = V_166 ;
V_5 -> V_202 = V_167 ;
V_5 -> V_200 = V_169 ;
V_5 -> V_222 = V_223 ;
V_5 -> V_224 = V_163 ;
V_5 -> V_204 = V_181 ;
V_5 -> V_205 = V_182 ;
V_5 -> V_225 = V_168 ;
V_5 -> V_201 = V_170 ;
V_5 -> V_226 = V_227 ;
V_5 -> V_228 = V_229 ;
V_5 -> V_192 = V_69 ;
V_5 -> V_230 = V_160 ;
V_5 -> V_231 = V_161 ;
V_5 -> V_203 = V_232 ;
V_5 -> V_233 = V_234 ;
V_5 -> V_171 = V_235 ;
V_5 -> V_216 = V_236 ;
V_5 -> V_215 = V_237 ;
V_5 -> V_238 = V_239 ;
V_5 -> V_240 = V_241 ;
V_5 -> V_194 = 0xffff ;
V_5 -> V_198 = V_242 ;
V_5 -> V_243 = V_244 ;
V_5 -> V_138 = V_245 ;
V_5 -> V_140 = V_246 ;
V_5 -> V_142 = V_247 ;
V_5 -> V_248 = V_249 ;
V_5 -> V_250 = 0 ;
V_5 -> V_251 = 0 ;
V_5 -> V_252 = 0 ;
V_5 -> V_253 = 0 ;
V_5 -> V_254 = 0 ;
V_5 -> V_255 = 0 ;
V_5 -> V_116 = V_256 ;
V_5 -> V_117 = V_257 ;
V_5 -> V_144 = V_258 ;
V_5 -> V_146 = V_259 ;
V_5 -> V_148 = V_260 ;
V_5 -> V_196 = V_261 ;
V_5 -> V_206 = V_262 ;
V_5 -> V_207 = V_263 ;
V_5 -> V_208 = V_264 ;
V_5 -> V_209 = V_265 ;
V_5 -> V_266 = V_267 ;
V_5 -> V_165 = V_159 + 12 ;
break;
case V_20 :
V_5 -> V_191 = V_68 ;
V_5 -> V_171 = 16 ;
V_5 -> V_216 = V_236 ;
V_5 -> V_215 = V_237 ;
V_5 -> V_165 = 16 + 16 ;
break;
case V_23 :
V_5 -> V_191 = V_66 ;
V_5 -> V_197 = V_268 ;
V_5 -> V_220 = V_269 ;
V_5 -> V_193 = V_270 ;
V_5 -> V_195 = V_271 ;
V_5 -> V_202 = V_272 ;
V_5 -> V_192 = V_67 ;
V_5 -> V_200 = V_273 ;
V_5 -> V_222 = V_274 ;
V_5 -> V_224 = V_275 ;
V_5 -> V_204 = V_276 ;
V_5 -> V_205 = V_277 ;
V_5 -> V_225 = V_278 ;
V_5 -> V_201 = V_279 ;
V_5 -> V_203 = V_280 ;
V_5 -> V_216 = V_281 ;
V_5 -> V_215 = V_282 ;
V_5 -> V_283 = V_284 ;
V_5 -> V_238 = V_285 ;
V_5 -> V_194 = V_286 ;
V_5 -> V_198 = V_287 ;
V_5 -> V_138 = V_288 ;
V_5 -> V_289 = V_290 ;
V_5 -> V_291 = V_292 ;
V_5 -> V_293 = V_294 ;
V_5 -> V_250 = V_295 ;
V_5 -> V_251 = V_296 ;
V_5 -> V_252 = V_297 ;
V_5 -> V_253 = V_298 ;
V_5 -> V_254 = V_299 ;
V_5 -> V_255 = V_300 ;
V_5 -> V_116 = 0 ;
V_5 -> V_117 = 0 ;
V_5 -> V_115 = 0 ;
V_5 -> V_196 = V_301 ;
V_5 -> V_206 = V_302 ;
V_5 -> V_207 = V_303 ;
V_5 -> V_208 = V_304 ;
V_5 -> V_209 = V_305 ;
V_5 -> V_266 = V_306 ;
V_5 -> V_199 = V_307 ;
break;
case V_19 :
V_5 -> V_191 = V_62 ;
V_5 -> V_220 = V_107 ;
V_5 -> V_197 = V_308 ;
V_5 -> V_193 = V_108 ;
V_5 -> V_195 = V_109 ;
V_5 -> V_202 = V_111 ;
V_5 -> V_192 = V_63 ;
V_5 -> V_200 = V_112 ;
V_5 -> V_222 = V_309 ;
V_5 -> V_224 = V_114 ;
V_5 -> V_204 = V_119 ;
V_5 -> V_205 = V_120 ;
V_5 -> V_225 = V_110 ;
V_5 -> V_201 = V_113 ;
V_5 -> V_203 = V_310 ;
V_5 -> V_233 = V_311 ;
V_5 -> V_171 = V_312 ;
V_5 -> V_138 = V_313 ;
V_5 -> V_140 = V_246 ;
V_5 -> V_314 = V_315 ;
V_5 -> V_142 = V_247 ;
V_5 -> V_283 = V_316 ;
V_5 -> V_238 = V_317 ;
V_5 -> V_194 = V_318 ;
V_5 -> V_198 = V_319 ;
V_5 -> V_216 = V_320 ;
V_5 -> V_215 = V_321 ;
V_5 -> V_289 = V_322 ;
V_5 -> V_291 = V_323 ;
V_5 -> V_293 = V_324 ;
V_5 -> V_250 = 0 ;
V_5 -> V_251 = 0 ;
V_5 -> V_252 = 0 ;
V_5 -> V_253 = 0 ;
V_5 -> V_254 = 0 ;
V_5 -> V_255 = 0 ;
V_5 -> V_116 = V_256 ;
V_5 -> V_117 = V_257 ;
V_5 -> V_115 = V_325 ;
V_5 -> V_144 = V_326 ;
V_5 -> V_146 = V_327 ;
V_5 -> V_148 = V_328 ;
V_5 -> V_196 = V_64 ;
V_5 -> V_206 = V_329 ;
V_5 -> V_207 = V_330 ;
V_5 -> V_208 = V_331 ;
V_5 -> V_209 = V_332 ;
V_5 -> V_266 = V_333 ;
break;
case V_24 :
V_5 -> V_191 = V_71 ;
V_5 -> V_197 = V_334 ;
V_5 -> V_193 = V_335 ;
V_5 -> V_195 = V_336 ;
V_5 -> V_202 = V_337 ;
V_5 -> V_192 = V_72 ;
V_5 -> V_200 = V_338 ;
V_5 -> V_222 = V_339 ;
V_5 -> V_204 = V_340 ;
V_5 -> V_205 = V_341 ;
V_5 -> V_225 = V_342 ;
V_5 -> V_201 = V_343 ;
V_5 -> V_203 = V_344 ;
V_5 -> V_233 = V_345 ;
V_5 -> V_226 = V_346 ;
V_5 -> V_228 = V_347 ;
V_5 -> V_216 = V_348 ;
V_5 -> V_215 = V_349 ;
V_5 -> V_194 = V_350 ;
V_5 -> V_198 = V_351 ;
V_5 -> V_138 = V_288 ;
V_5 -> V_196 = V_352 ;
V_5 -> V_206 = V_353 ;
V_5 -> V_207 = V_354 ;
V_5 -> V_208 = V_355 ;
V_5 -> V_209 = V_356 ;
V_5 -> V_266 = V_357 ;
V_5 -> V_199 = V_358 ;
break;
}
}
int F_20 ( const T_8 * V_76 , int V_27 , int V_103 , T_9 V_99 , T_8 V_82 )
{
int V_359 ;
T_9 V_360 ;
if ( V_76 [ V_103 ] == 0xdd )
return V_103 ;
for ( V_359 = V_103 ; V_359 < ( V_27 ) ; V_359 ++ ) {
if ( V_76 [ V_359 ] == 0xdd ) {
if ( V_76 [ V_359 + 15 ] == 0xe2 ) {
if ( V_76 [ V_359 + 4 ] != V_82 )
continue;
V_360 = F_32 ( & V_76 [ V_359 + 1 ] ) ;
if ( V_360 != V_99 )
continue;
return ( V_359 ) ;
}
else
{
if ( V_76 [ V_359 + V_361 ] != V_82 )
continue;
V_360 = F_32 ( & V_76 [ V_359 + V_362 ] ) ;
if ( V_360 != V_99 )
continue;
return ( V_359 ) ;
}
}
}
return V_103 ;
}
T_12 F_21 ( const T_8 * V_76 , int V_102 )
{
int V_363 ;
T_12 V_104 ;
if ( V_76 [ V_102 + 15 ] == 0xe2 )
V_363 = 5 ;
else
V_363 = 8 ;
V_104 = F_33 ( & V_76 [ V_102 + V_363 ] ) ;
return ( V_104 & 0xffffffff ) ;
}
static float F_27 ( T_8 V_364 , T_8 V_365 , T_10 V_80 , T_8 V_96 )
{
float V_366 [] = { 1.0f , 2.0f , 5.5f , 11.0f , 6.0f , 9.0f , 12.0f , 18.0f , 24.0f , 36.0f , 48.0f , 54.0f } ;
int V_367 [] = { 26 , 52 , 78 , 104 , 156 , 208 , 234 , 260 } ;
int V_368 [] = { 54 , 108 , 162 , 216 , 324 , 432 , 486 , 540 } ;
int V_369 [] = { 26 , 52 , 78 , 104 , 156 , 208 , 234 , 260 , 312 } ;
int V_370 [] = { 54 , 108 , 162 , 216 , 324 , 432 , 486 , 540 , 648 , 720 } ;
int V_371 [] = { 117 , 234 , 351 , 468 , 702 , 936 , 1053 , 1170 , 1404 , 1560 } ;
int V_372 ;
float V_373 , V_374 = 0.0f ;
if ( V_364 == 0 )
V_374 = V_366 [ V_365 ] ;
else if ( V_364 == 1 || V_364 == 2 )
{
if ( V_80 & V_176 )
V_373 = 3.6f ;
else
V_373 = 4.0f ;
if ( V_80 & V_175 )
V_372 = V_368 [ V_365 - 8 * ( int ) ( V_365 / 8 ) ] ;
else
V_372 = V_367 [ V_365 - 8 * ( int ) ( V_365 / 8 ) ] ;
V_374 = ( V_372 * ( ( ( int ) ( V_365 / 8 ) + 1 ) ) ) / V_373 ;
}
else
{
if ( V_80 & V_176 )
V_373 = 3.6f ;
else
V_373 = 4.0f ;
if ( V_365 > 9 ) V_365 = 9 ;
if ( V_80 & V_175 )
V_374 = ( V_370 [ V_365 ] * V_96 ) / V_373 ;
else if ( V_80 & V_180 )
V_374 = ( V_371 [ V_365 ] * V_96 ) / V_373 ;
else
{
if ( V_365 == 9 && V_96 == 3 )
V_374 = 1040 / V_373 ;
else if ( V_365 < 9 )
V_374 = ( V_369 [ V_365 ] * V_96 ) / V_373 ;
}
}
return V_374 ;
}
static T_4
F_7 ( T_7 V_29 , int V_27 ,
struct V_37 * V_31 , T_6 * V_38 , T_3 * V_5 ,
int V_28 , int * V_2 , T_2 * * V_3 )
{
T_8 V_50 [ V_46 ] ;
if ( F_9 ( V_50 , V_27 , V_29 ) != V_27 ) {
* V_2 = F_10 ( V_29 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_61 ;
return FALSE ;
}
switch ( V_5 -> V_8 )
{
case V_19 :
return F_15 ( V_5 , V_31 , V_38 , V_50 , V_27 , V_2 , V_3 ) ;
break;
case V_18 :
case V_20 :
return F_28 ( V_5 , V_31 , V_38 , V_50 , V_27 , V_28 , V_2 , V_3 ) ;
break;
case V_23 :
case V_24 :
return F_31 ( V_5 , V_31 , V_38 , V_50 , V_27 , V_28 , V_2 , V_3 ) ;
break;
default:
F_34 () ;
return FALSE ;
}
}
