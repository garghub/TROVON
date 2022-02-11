static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned short V_11 ;
V_9 -> V_12 [ V_3 ] = V_5 ;
F_3 ( 1 << V_3 , V_2 -> V_13 + V_14 ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 , V_9 -> V_16 [ V_4 ] ,
( V_17 |
V_18 ) ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_11 = ( unsigned short ) V_5 << ( 16 - V_7 -> V_21 ) ;
if ( ( V_9 -> V_15 & V_17 ) ==
V_22 ) {
V_11 ^= 0x8000 ;
}
F_3 ( V_11 , V_2 -> V_13 + V_23 ) ;
F_5 ( V_2 -> V_13 + V_24 ) ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_27 * V_28 , unsigned int * V_5 )
{
int V_29 ;
int V_3 , V_4 ;
V_3 = F_7 ( V_28 -> V_30 ) ;
V_4 = F_8 ( V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_31 ; V_29 ++ )
F_1 ( V_2 , V_3 , V_4 , V_5 [ V_29 ] ) ;
return V_29 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_27 * V_28 , unsigned int * V_5 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_29 ;
int V_3 ;
V_3 = F_7 ( V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_31 ; V_29 ++ )
V_5 [ V_29 ] = V_9 -> V_12 [ V_3 ] ;
return V_29 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_32 ;
if ( ! F_11 ( V_33 , & V_9 -> V_34 ) )
return;
F_12 ( & V_9 -> V_35 , V_32 ) ;
V_9 -> V_36 = 0 ;
F_13 ( 0 , V_9 -> V_37 + V_38 ) ;
while ( V_9 -> V_39 && V_9 -> V_40 != V_41 ) {
F_14 ( & V_9 -> V_35 , V_32 ) ;
F_12 ( & V_9 -> V_35 , V_32 ) ;
}
F_14 ( & V_9 -> V_35 , V_32 ) ;
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
V_42 |
V_43 ,
V_44 |
V_45 ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_46 * V_47 = & V_26 -> V_48 -> V_47 ;
unsigned long V_32 ;
F_16 ( V_33 , & V_9 -> V_34 ) ;
if ( V_47 -> V_49 == V_50 && V_9 -> V_51 == 0 ) {
V_26 -> V_48 -> V_52 |= V_53 ;
F_17 ( V_2 , V_26 ) ;
} else {
F_12 ( & V_9 -> V_35 , V_32 ) ;
if ( V_47 -> V_49 == V_54 )
V_9 -> V_36 = V_55 | V_56 ;
else
V_9 -> V_36 = V_56 ;
F_13 ( V_9 -> V_36 , V_9 -> V_37 + V_38 ) ;
F_14 ( & V_9 -> V_35 , V_32 ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_46 * V_47 = & V_26 -> V_48 -> V_47 ;
unsigned int V_57 = F_19 ( V_26 ) ;
unsigned int V_58 ;
unsigned int V_59 ;
unsigned short V_60 ;
unsigned int V_29 , V_31 ;
V_58 = F_20 ( V_26 ) / V_57 ;
if ( V_47 -> V_49 == V_50 ) {
if ( V_58 > V_9 -> V_51 )
V_58 = V_9 -> V_51 ;
}
V_60 = F_5 ( V_2 -> V_13 + V_20 ) ;
switch ( V_60 & V_61 ) {
case V_62 :
V_59 = V_63 ;
if ( V_47 -> V_49 == V_50 && V_9 -> V_51 == 0 ) {
V_26 -> V_48 -> V_52 |= V_53 ;
F_17 ( V_2 , V_26 ) ;
return;
}
break;
case V_64 :
V_59 = V_65 ;
break;
case V_66 :
V_59 = V_67 ;
break;
default:
V_59 = V_68 ;
break;
}
if ( V_59 >= V_65 ) {
if ( V_58 == 0 ) {
F_21 ( V_2 -> V_69 , L_1 ) ;
V_26 -> V_48 -> V_52 |= V_70 ;
}
}
V_59 /= V_47 -> V_71 ;
if ( V_58 > V_59 )
V_58 = V_59 ;
for ( V_31 = 0 ; V_31 < V_58 ; V_31 ++ ) {
F_22 ( V_26 , & V_9 -> V_72 [ 0 ] ,
V_57 ) ;
for ( V_29 = 0 ; V_29 < V_47 -> V_71 ; V_29 ++ ) {
F_3 ( V_9 -> V_72 [ V_9 -> V_73 [ V_29 ] ] ,
V_2 -> V_13 + V_23 ) ;
}
}
if ( V_47 -> V_49 == V_50 ) {
V_9 -> V_51 -= V_58 ;
if ( V_9 -> V_51 == 0 ) {
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
V_43 ,
V_45 ) ;
F_3 ( V_9 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
}
if ( ( V_9 -> V_15 & V_44 ) ==
V_74 ) {
unsigned short V_75 ;
if ( V_47 -> V_76 == V_77 ) {
V_75 = V_78 ;
} else {
if ( V_47 -> V_79 & V_80 )
V_75 = V_81 ;
else
V_75 = V_82 ;
}
V_9 -> V_15 = F_4 ( V_9 -> V_15 , V_75 ,
V_44 ) ;
F_3 ( V_9 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
F_17 ( V_2 , V_26 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
unsigned int V_83 )
{
struct V_46 * V_47 = & V_26 -> V_48 -> V_47 ;
if ( V_83 != V_47 -> V_84 )
return - V_85 ;
V_26 -> V_48 -> V_86 = NULL ;
F_15 ( V_2 , V_26 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_46 * V_47 )
{
unsigned int V_87 = F_8 ( V_47 -> V_88 [ 0 ] ) ;
unsigned int V_89 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_47 -> V_71 ; V_29 ++ ) {
unsigned int V_3 = F_7 ( V_47 -> V_88 [ V_29 ] ) ;
unsigned int V_4 = F_8 ( V_47 -> V_88 [ V_29 ] ) ;
if ( V_89 & ( 1 << V_3 ) ) {
F_25 ( V_2 -> V_69 ,
L_2 ,
V_90 ) ;
return - V_85 ;
}
V_89 |= ( 1 << V_3 ) ;
if ( V_4 != V_87 ) {
F_25 ( V_2 -> V_69 ,
L_3 ,
V_90 ) ;
return - V_85 ;
}
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_46 * V_47 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_91 = 0 ;
unsigned int V_92 ;
V_91 |= F_27 ( & V_47 -> V_93 , V_94 | V_54 ) ;
V_91 |= F_27 ( & V_47 -> V_76 ,
V_54 | V_77 ) ;
V_91 |= F_27 ( & V_47 -> V_95 , V_96 ) ;
V_91 |= F_27 ( & V_47 -> V_97 , V_50 ) ;
V_91 |= F_27 ( & V_47 -> V_49 ,
V_50 | V_54 | V_98 ) ;
if ( V_91 )
return 1 ;
V_91 |= F_28 ( V_47 -> V_93 ) ;
V_91 |= F_28 ( V_47 -> V_76 ) ;
V_91 |= F_28 ( V_47 -> V_49 ) ;
V_92 = 0 ;
if ( V_47 -> V_93 & V_54 )
V_92 ++ ;
if ( V_47 -> V_76 & V_54 )
V_92 ++ ;
if ( V_47 -> V_49 & V_54 )
V_92 ++ ;
if ( V_92 > 1 )
V_91 |= - V_85 ;
if ( V_91 )
return 2 ;
switch ( V_47 -> V_93 ) {
case V_94 :
V_91 |= F_29 ( & V_47 -> V_84 , 0 ) ;
break;
case V_54 :
if ( ( V_47 -> V_84 & ~ V_99 ) != 0 ) {
V_47 -> V_84 = F_4 ( V_47 -> V_84 , 0 ,
~ V_99 ) ;
V_91 |= - V_85 ;
}
if ( ( V_47 -> V_84 & V_99 & ~ V_100 ) != 0 ) {
V_47 -> V_84 = F_4 ( V_47 -> V_84 , 0 ,
V_99 & ~ V_100 ) ;
V_91 |= - V_85 ;
}
break;
}
switch ( V_47 -> V_76 ) {
case V_77 :
V_91 |= F_30 ( & V_47 -> V_79 ,
V_101 ) ;
V_92 = V_47 -> V_71 * V_102 ;
if ( V_92 < V_103 )
V_92 = V_103 ;
V_91 |= F_31 ( & V_47 -> V_79 , V_92 ) ;
break;
case V_54 :
if ( ( V_47 -> V_79 & ~ V_99 ) != 0 ) {
V_47 -> V_79 = F_4 ( V_47 -> V_79 , 0 ,
~ V_99 ) ;
V_91 |= - V_85 ;
}
if ( ( V_47 -> V_79 & V_99 &
~ ( V_100 | V_80 ) ) != 0 ) {
V_47 -> V_79 = F_4 ( V_47 -> V_79 , 0 ,
V_99 &
~ ( V_100 | V_80 ) ) ;
V_91 |= - V_85 ;
}
break;
}
V_91 |= F_29 ( & V_47 -> V_104 , 0 ) ;
V_91 |= F_29 ( & V_47 -> V_105 , V_47 -> V_71 ) ;
switch ( V_47 -> V_49 ) {
case V_50 :
break;
case V_54 :
if ( ( V_47 -> V_106 & ~ V_99 ) != 0 ) {
V_47 -> V_106 = F_4 ( V_47 -> V_106 , 0 ,
~ V_99 ) ;
V_91 |= - V_85 ;
}
if ( ( V_47 -> V_106 & V_99 & ~ V_100 ) != 0 ) {
V_47 -> V_106 = F_4 ( V_47 -> V_106 , 0 ,
V_99 & ~ V_100 ) ;
}
break;
case V_98 :
V_91 |= F_29 ( & V_47 -> V_106 , 0 ) ;
break;
}
if ( V_91 )
return 3 ;
if ( V_47 -> V_76 == V_77 ) {
V_92 = V_47 -> V_79 ;
F_32 ( V_107 ,
& V_9 -> V_108 ,
& V_9 -> V_109 ,
& V_92 , V_47 -> V_32 ) ;
V_91 |= F_29 ( & V_47 -> V_79 , V_92 ) ;
}
if ( V_91 )
return 4 ;
if ( V_47 -> V_88 && V_47 -> V_71 > 0 )
V_91 |= F_24 ( V_2 , V_26 , V_47 ) ;
if ( V_91 )
return 5 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_110 = V_9 -> V_37 + V_111 ;
F_13 ( F_34 ( 0 , V_112 ) , V_9 -> V_37 + V_113 ) ;
F_13 ( F_34 ( 2 , V_112 ) , V_9 -> V_37 + V_113 ) ;
F_13 ( F_35 ( 2 , V_114 ) , V_9 -> V_37 + V_115 ) ;
F_36 ( V_110 , 0 , 2 , V_116 | V_117 ) ;
F_37 ( V_110 , 0 , 2 , V_9 -> V_108 ) ;
F_13 ( F_35 ( 0 , V_118 ) , V_9 -> V_37 + V_115 ) ;
F_36 ( V_110 , 0 , 0 , V_116 | V_117 ) ;
F_37 ( V_110 , 0 , 0 , V_9 -> V_109 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_46 * V_47 = & V_26 -> V_48 -> V_47 ;
int V_4 ;
unsigned int V_29 , V_119 ;
unsigned int V_120 ;
unsigned int V_121 ;
unsigned long V_32 ;
if ( V_47 -> V_88 == NULL || V_47 -> V_71 == 0 )
return - V_85 ;
V_9 -> V_122 = 0 ;
for ( V_29 = 0 ; V_29 < V_47 -> V_71 ; V_29 ++ ) {
V_120 = F_7 ( V_47 -> V_88 [ V_29 ] ) ;
V_9 -> V_122 |= 1U << V_120 ;
V_121 = 0 ;
for ( V_119 = 0 ; V_119 < V_47 -> V_71 ; V_119 ++ ) {
if ( F_7 ( V_47 -> V_88 [ V_119 ] ) < V_120 )
V_121 ++ ;
}
V_9 -> V_73 [ V_121 ] = V_29 ;
}
F_3 ( V_9 -> V_122 , V_2 -> V_13 + V_14 ) ;
V_4 = F_8 ( V_47 -> V_88 [ 0 ] ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
( V_9 ->
V_16 [ V_4 ] | V_74 |
V_123 ) ,
( V_17 |
V_18 |
V_44 |
V_45 ) ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
if ( V_47 -> V_76 == V_77 )
F_33 ( V_2 , V_26 ) ;
if ( V_47 -> V_49 == V_50 )
V_9 -> V_51 = V_47 -> V_106 ;
else
V_9 -> V_51 = 0 ;
F_12 ( & V_9 -> V_35 , V_32 ) ;
if ( V_47 -> V_93 == V_94 ) {
V_26 -> V_48 -> V_86 = F_23 ;
} else {
V_9 -> V_36 |= V_55 ;
F_13 ( V_9 -> V_36 , V_9 -> V_37 + V_38 ) ;
}
F_14 ( & V_9 -> V_35 , V_32 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_10 ( V_2 , V_26 ) ;
return 0 ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_25 * V_26 ,
void * V_5 , unsigned int V_124 , unsigned int V_125 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_46 * V_47 = & V_26 -> V_48 -> V_47 ;
unsigned short * V_126 = V_5 ;
unsigned int V_127 = V_124 / sizeof( * V_126 ) ;
unsigned int V_128 ;
unsigned int V_129 ;
unsigned int V_29 ;
V_129 = 16 - V_7 -> V_21 ;
if ( ( V_9 -> V_16 [ F_8 ( V_47 -> V_88 [ 0 ] ) ] &
V_17 ) == V_130 ) {
V_128 = 0 ;
} else {
V_128 = 32768 ;
}
for ( V_29 = 0 ; V_29 < V_127 ; V_29 ++ )
V_126 [ V_29 ] = ( V_126 [ V_29 ] << V_129 ) - V_128 ;
}
static T_1 F_41 ( int V_131 , void * V_132 )
{
struct V_1 * V_2 = V_132 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_25 * V_26 = V_2 -> V_133 ;
struct V_46 * V_47 ;
unsigned char V_134 , V_135 ;
unsigned char V_136 ;
int V_137 = 0 ;
unsigned long V_32 ;
V_134 = F_42 ( V_9 -> V_37 + V_38 ) & 0x3F ;
if ( V_134 ) {
V_137 = 1 ;
F_12 ( & V_9 -> V_35 , V_32 ) ;
V_135 = V_9 -> V_36 & V_134 ;
V_136 = V_9 -> V_36 & ~ V_134 ;
F_13 ( V_136 , V_9 -> V_37 + V_38 ) ;
V_9 -> V_39 = 1 ;
V_9 -> V_40 = V_41 ;
F_14 ( & V_9 -> V_35 , V_32 ) ;
if ( V_135 != 0 ) {
V_47 = & V_26 -> V_48 -> V_47 ;
if ( V_135 & V_55 ) {
V_9 -> V_36 &= ~ V_55 ;
if ( V_47 -> V_93 == V_54 )
F_15 ( V_2 , V_26 ) ;
else if ( V_47 -> V_49 == V_54 )
F_10 ( V_2 , V_26 ) ;
}
if ( V_135 & V_56 )
F_18 ( V_2 , V_26 ) ;
}
F_12 ( & V_9 -> V_35 , V_32 ) ;
if ( V_136 != V_9 -> V_36 ) {
F_13 ( V_9 -> V_36 ,
V_9 -> V_37 + V_38 ) ;
}
V_9 -> V_39 = 0 ;
F_14 ( & V_9 -> V_35 , V_32 ) ;
}
return F_43 ( V_137 ) ;
}
static const struct V_6
* F_44 ( struct V_138 * V_138 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_45 ( V_139 ) ; V_29 ++ )
if ( V_138 -> V_140 == V_139 [ V_29 ] . V_141 )
return & V_139 [ V_29 ] ;
return NULL ;
}
static struct V_138 * F_46 ( struct V_1 * V_2 ,
struct V_142 * V_143 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_138 * V_138 = NULL ;
int V_144 = V_143 -> V_145 [ 0 ] ;
int V_146 = V_143 -> V_145 [ 1 ] ;
F_47 (pci_dev) {
if ( V_144 || V_146 ) {
if ( V_144 != V_138 -> V_144 -> V_147 ||
V_146 != F_48 ( V_138 -> V_148 ) )
continue;
}
if ( V_138 -> V_149 != V_150 )
continue;
if ( V_7 -> V_151 == V_152 ) {
const struct V_6 * V_153 ;
V_153 = F_44 ( V_138 ) ;
if ( V_153 == NULL )
continue;
V_2 -> V_153 = V_153 ;
} else {
if ( V_7 -> V_141 != V_138 -> V_140 )
continue;
}
return V_138 ;
}
F_21 ( V_2 -> V_69 ,
L_4 ,
V_144 , V_146 ) ;
return NULL ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_138 * V_138 , int * V_145 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_25 * V_26 ;
unsigned int V_131 ;
unsigned V_31 ;
int V_154 ;
F_50 ( V_2 , & V_138 -> V_2 ) ;
V_154 = F_51 ( V_2 ) ;
if ( V_154 )
return V_154 ;
F_52 ( & V_9 -> V_35 ) ;
V_9 -> V_37 = F_53 ( V_138 , 2 ) ;
V_2 -> V_13 = F_53 ( V_138 , 3 ) ;
V_131 = V_138 -> V_131 ;
V_9 -> V_12 = F_54 ( sizeof( V_9 -> V_12 [ 0 ] ) *
V_7 -> V_155 , V_156 ) ;
if ( ! V_9 -> V_12 )
return - V_157 ;
V_9 -> V_72 = F_54 ( sizeof( V_9 -> V_72 [ 0 ] ) *
V_7 -> V_155 , V_156 ) ;
if ( ! V_9 -> V_72 )
return - V_157 ;
V_9 -> V_73 = F_54 ( sizeof( V_9 -> V_73 [ 0 ] ) *
V_7 -> V_155 , V_156 ) ;
if ( ! V_9 -> V_73 )
return - V_157 ;
V_9 -> V_36 = 0 ;
F_13 ( 0 , V_9 -> V_37 + V_38 ) ;
F_3 ( V_158 , V_2 -> V_13 + V_20 ) ;
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
F_3 ( 0 , V_2 -> V_13 + V_159 ) ;
V_9 -> V_15 = ( V_42 | V_22 |
V_160 |
V_43 ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_154 = F_55 ( V_2 , 1 ) ;
if ( V_154 )
return V_154 ;
V_26 = & V_2 -> V_161 [ 0 ] ;
V_26 -> type = V_162 ;
V_26 -> V_163 = V_164 | V_165 | V_166 ;
V_26 -> V_167 = V_7 -> V_155 ;
V_26 -> V_168 = ( 1 << V_7 -> V_21 ) - 1 ;
V_26 -> V_169 = & F_6 ;
V_26 -> V_170 = & F_9 ;
V_26 -> V_171 = V_26 -> V_167 ;
V_2 -> V_133 = V_26 ;
V_26 -> V_172 = & F_38 ;
V_26 -> V_173 = & F_26 ;
V_26 -> V_174 = & F_39 ;
V_26 -> V_175 = & F_40 ;
if ( V_7 -> V_151 == V_176 ) {
const struct V_177 * * V_178 ;
V_26 -> V_178 = V_178 =
F_54 ( sizeof( struct V_177 * ) * V_26 -> V_167 ,
V_156 ) ;
if ( ! V_26 -> V_178 )
return - V_157 ;
if ( V_145 ) {
for ( V_31 = 2 ; V_31 < 3 + V_26 -> V_167 ; V_31 ++ ) {
if ( V_145 [ V_31 ] < 0 || V_145 [ V_31 ] > 1 ) {
F_56 ( V_2 -> V_69 , V_179
L_5 ,
V_31 , V_145 [ V_31 ] ) ;
}
}
}
for ( V_31 = 0 ; V_31 < V_26 -> V_167 ; V_31 ++ ) {
if ( V_31 < V_180 - 3 && V_145 &&
V_145 [ 3 + V_31 ] == 1 ) {
if ( V_145 [ 2 ] == 1 )
V_178 [ V_31 ] = & V_181 ;
else
V_178 [ V_31 ] = & V_182 ;
} else {
if ( V_145 && V_145 [ 2 ] == 1 ) {
V_178 [ V_31 ] =
& V_183 ;
} else {
V_178 [ V_31 ] = & V_184 ;
}
}
}
V_9 -> V_16 = V_185 ;
} else {
if ( V_145 && V_145 [ 2 ] == 1 ) {
V_26 -> V_186 = & V_187 ;
V_9 -> V_16 = V_188 ;
} else {
if ( V_145 && V_145 [ 2 ] != 0 ) {
F_56 ( V_2 -> V_69 , V_179
L_6 ,
V_145 [ 2 ] ) ;
}
V_26 -> V_186 = & V_189 ;
V_9 -> V_16 = V_190 ;
}
}
V_2 -> V_191 = V_7 -> V_192 ;
if ( V_131 ) {
V_154 = F_57 ( V_131 , F_41 , V_193 ,
V_179 , V_2 ) ;
if ( V_154 < 0 ) {
F_21 ( V_2 -> V_69 ,
L_7 , V_131 ) ;
return V_154 ;
} else {
V_2 -> V_131 = V_131 ;
}
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
struct V_8 * V_9 ;
struct V_138 * V_138 ;
F_59 ( V_2 -> V_69 , V_179 L_8 ) ;
V_9 = F_60 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_157 ;
V_138 = F_46 ( V_2 , V_143 ) ;
if ( ! V_138 )
return - V_194 ;
return F_49 ( V_2 , V_138 , V_143 -> V_145 ) ;
}
static int
F_61 ( struct V_1 * V_2 , unsigned long V_195 )
{
struct V_138 * V_138 = F_62 ( V_2 ) ;
struct V_8 * V_9 ;
F_59 ( V_2 -> V_69 , V_179 L_9 ,
F_63 ( V_138 ) ) ;
V_9 = F_60 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_157 ;
V_2 -> V_153 = F_44 ( V_138 ) ;
if ( V_2 -> V_153 == NULL ) {
F_21 ( V_2 -> V_69 ,
V_179 L_10 ) ;
return - V_85 ;
}
F_64 ( V_138 ) ;
return F_49 ( V_2 , V_138 , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_138 * V_196 = F_62 ( V_2 ) ;
if ( V_2 -> V_131 )
F_66 ( V_2 -> V_131 , V_2 ) ;
if ( V_2 -> V_161 ) {
struct V_25 * V_26 ;
V_26 = & V_2 -> V_161 [ 0 ] ;
F_67 ( V_26 -> V_178 ) ;
}
if ( V_9 ) {
F_67 ( V_9 -> V_12 ) ;
F_67 ( V_9 -> V_72 ) ;
F_67 ( V_9 -> V_73 ) ;
}
F_68 ( V_2 ) ;
if ( V_196 )
F_69 ( V_196 ) ;
}
static int F_70 ( struct V_138 * V_2 ,
const struct V_197 * V_198 )
{
return F_71 ( V_2 , & V_199 ,
V_198 -> V_200 ) ;
}
