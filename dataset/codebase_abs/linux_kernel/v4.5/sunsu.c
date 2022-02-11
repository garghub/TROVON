static unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_4 . V_5 ;
switch ( V_2 -> V_4 . V_6 ) {
case V_7 :
F_2 ( V_2 -> V_4 . V_8 - 1 + V_3 , V_2 -> V_4 . V_9 ) ;
return F_3 ( V_2 -> V_4 . V_9 + 1 ) ;
case V_10 :
return F_4 ( V_2 -> V_4 . V_11 + V_3 ) ;
default:
return F_3 ( V_2 -> V_4 . V_9 + V_3 ) ;
}
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_12 )
{
#ifndef F_6
if ( V_3 == V_13 )
V_12 |= V_14 ;
#endif
V_3 <<= V_2 -> V_4 . V_5 ;
switch ( V_2 -> V_4 . V_6 ) {
case V_7 :
F_2 ( V_2 -> V_4 . V_8 - 1 + V_3 , V_2 -> V_4 . V_9 ) ;
F_2 ( V_12 , V_2 -> V_4 . V_9 + 1 ) ;
break;
case V_10 :
F_7 ( V_12 , V_2 -> V_4 . V_11 + V_3 ) ;
break;
default:
F_2 ( V_12 , V_2 -> V_4 . V_9 + V_3 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , int V_3 , int V_12 )
{
F_5 ( V_2 , V_15 , V_3 ) ;
F_5 ( V_2 , V_16 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned char V_17 ;
int V_18 ;
V_17 = F_10 ( V_2 , V_19 ) ;
V_18 = V_17 & V_20 ;
if ( ! V_18 ) {
F_11 ( V_2 , V_19 , V_17 | V_20 ) ;
V_17 = F_10 ( V_2 , V_19 ) ;
V_18 = V_17 & V_20 ;
}
if ( V_18 )
V_2 -> V_4 . V_21 = V_22 * 16 ;
return V_18 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . type == V_23 ) {
if ( V_2 -> V_4 . V_21 != V_22 * 16 ) {
F_13 ( & V_2 -> V_4 . V_24 ) ;
F_9 ( V_2 ) ;
F_14 ( & V_2 -> V_4 . V_24 ) ;
}
if ( V_2 -> V_4 . V_21 == V_22 * 16 )
F_11 ( V_2 , V_25 , 0 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned char V_17 ;
int V_18 ;
if ( V_2 -> V_4 . type == V_23 &&
V_2 -> V_4 . V_21 == V_22 * 16 ) {
F_13 ( & V_2 -> V_4 . V_24 ) ;
V_17 = F_10 ( V_2 , V_19 ) ;
V_18 = ! ( V_17 & V_20 ) ;
if ( ! V_18 ) {
F_11 ( V_2 , V_19 , V_17 & ~ V_20 ) ;
V_17 = F_10 ( V_2 , V_19 ) ;
V_18 = ! ( V_17 & V_20 ) ;
}
if ( V_18 )
V_2 -> V_4 . V_21 = V_26 * 16 ;
F_14 ( & V_2 -> V_4 . V_24 ) ;
}
}
static inline void F_16 ( struct V_1 * V_27 )
{
if ( V_27 -> V_28 & V_29 ) {
V_27 -> V_28 &= ~ V_29 ;
F_5 ( V_27 , V_30 , V_27 -> V_28 ) ;
}
}
static void F_17 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
F_16 ( V_2 ) ;
if ( V_2 -> V_4 . type == V_32 ) {
V_2 -> V_33 |= V_34 ;
F_8 ( V_2 , V_35 , V_2 -> V_33 ) ;
}
}
static void F_19 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
if ( ! ( V_2 -> V_28 & V_29 ) ) {
V_2 -> V_28 |= V_29 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
if ( V_2 -> V_4 . type == V_32 && V_2 -> V_33 & V_34 ) {
V_2 -> V_33 &= ~ V_34 ;
F_8 ( V_2 , V_35 , V_2 -> V_33 ) ;
}
}
static void F_20 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
V_2 -> V_28 &= ~ V_36 ;
V_2 -> V_4 . V_37 &= ~ V_38 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
static void F_21 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_39 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_2 -> V_28 |= V_40 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static void
F_24 ( struct V_1 * V_2 , unsigned char * V_41 )
{
struct V_42 * V_4 = & V_2 -> V_4 . V_43 -> V_4 ;
unsigned char V_44 , V_45 ;
int V_46 = 256 ;
int V_47 = 0 ;
do {
V_44 = F_10 ( V_2 , V_48 ) ;
V_45 = V_49 ;
V_2 -> V_4 . V_50 . V_51 ++ ;
if ( F_25 ( * V_41 & ( V_52 | V_53 |
V_54 | V_55 ) ) ) {
if ( * V_41 & V_52 ) {
* V_41 &= ~ ( V_54 | V_53 ) ;
V_2 -> V_4 . V_50 . V_56 ++ ;
if ( V_2 -> V_4 . V_57 != NULL &&
V_2 -> V_4 . line == V_2 -> V_4 . V_57 -> V_58 )
V_47 = 1 ;
if ( F_26 ( & V_2 -> V_4 ) )
goto V_59;
} else if ( * V_41 & V_53 )
V_2 -> V_4 . V_50 . V_60 ++ ;
else if ( * V_41 & V_54 )
V_2 -> V_4 . V_50 . V_61 ++ ;
if ( * V_41 & V_55 )
V_2 -> V_4 . V_50 . V_62 ++ ;
* V_41 &= V_2 -> V_4 . V_37 ;
if ( V_2 -> V_4 . V_57 != NULL &&
V_2 -> V_4 . line == V_2 -> V_4 . V_57 -> V_58 ) {
* V_41 |= V_2 -> V_63 ;
V_2 -> V_63 = 0 ;
}
if ( * V_41 & V_52 ) {
V_45 = V_64 ;
} else if ( * V_41 & V_53 )
V_45 = V_65 ;
else if ( * V_41 & V_54 )
V_45 = V_66 ;
}
if ( F_27 ( & V_2 -> V_4 , V_44 ) )
goto V_59;
if ( ( * V_41 & V_2 -> V_4 . V_67 ) == 0 )
F_28 ( V_4 , V_44 , V_45 ) ;
if ( * V_41 & V_55 )
F_28 ( V_4 , 0 , V_68 ) ;
V_59:
* V_41 = F_10 ( V_2 , V_69 ) ;
} while ( ( * V_41 & V_38 ) && ( V_46 -- > 0 ) );
if ( V_47 )
F_29 () ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = & V_2 -> V_4 . V_43 -> V_71 ;
int V_72 ;
if ( V_2 -> V_4 . V_73 ) {
F_11 ( V_2 , V_74 , V_2 -> V_4 . V_73 ) ;
V_2 -> V_4 . V_50 . V_75 ++ ;
V_2 -> V_4 . V_73 = 0 ;
return;
}
if ( F_31 ( & V_2 -> V_4 ) ) {
F_17 ( & V_2 -> V_4 ) ;
return;
}
if ( F_32 ( V_71 ) ) {
F_16 ( V_2 ) ;
return;
}
V_72 = V_2 -> V_4 . V_76 ;
do {
F_5 ( V_2 , V_74 , V_71 -> V_77 [ V_71 -> V_78 ] ) ;
V_71 -> V_78 = ( V_71 -> V_78 + 1 ) & ( V_79 - 1 ) ;
V_2 -> V_4 . V_50 . V_75 ++ ;
if ( F_32 ( V_71 ) )
break;
} while ( -- V_72 > 0 );
if ( F_33 ( V_71 ) < V_80 )
F_34 ( & V_2 -> V_4 ) ;
if ( F_32 ( V_71 ) )
F_16 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_41 ;
V_41 = F_1 ( V_2 , V_81 ) ;
if ( ( V_41 & V_82 ) == 0 )
return;
if ( V_41 & V_83 )
V_2 -> V_4 . V_50 . V_84 ++ ;
if ( V_41 & V_85 )
V_2 -> V_4 . V_50 . V_86 ++ ;
if ( V_41 & V_87 )
F_36 ( & V_2 -> V_4 , V_41 & V_88 ) ;
if ( V_41 & V_89 )
F_37 ( & V_2 -> V_4 , V_41 & V_90 ) ;
F_38 ( & V_2 -> V_4 . V_43 -> V_4 . V_91 ) ;
}
static T_1 F_39 ( int V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
unsigned long V_39 ;
unsigned char V_41 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
do {
V_41 = F_10 ( V_2 , V_69 ) ;
if ( V_41 & V_38 )
F_24 ( V_2 , & V_41 ) ;
F_35 ( V_2 ) ;
if ( V_41 & V_94 )
F_30 ( V_2 ) ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
F_40 ( & V_2 -> V_4 . V_43 -> V_4 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
} while ( ! ( F_1 ( V_2 , V_95 ) & V_96 ) );
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
return V_97 ;
}
static void F_41 ( struct V_1 * V_2 )
{
unsigned int V_98 = V_2 -> V_99 ;
int V_100 , V_101 ;
V_2 -> V_99 &= ~ V_102 ;
V_2 -> V_99 |= F_42 ( V_98 , & V_101 ) ;
V_100 = V_2 -> V_4 . V_21 / ( 16 * V_101 ) ;
F_43 ( & V_2 -> V_4 , V_2 -> V_99 , 0 , V_100 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_103 )
{
do {
unsigned char V_44 = F_10 ( V_2 , V_48 ) ;
if ( V_2 -> V_104 == V_105 ) {
#ifdef F_45
F_46 ( & V_2 -> V_106 , V_44 , 0 ) ;
#endif
} else if ( V_2 -> V_104 == V_107 ) {
int V_108 = F_47 ( V_44 , V_103 ) ;
switch ( V_108 ) {
case 2 :
F_41 ( V_2 ) ;
case 1 :
break;
case 0 :
#ifdef F_45
F_46 ( & V_2 -> V_106 , V_44 , 0 ) ;
#endif
break;
}
}
} while ( F_1 ( V_2 , V_69 ) & V_38 );
}
static T_1 F_48 ( int V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
if ( ! ( F_1 ( V_2 , V_95 ) & V_96 ) ) {
unsigned char V_41 = F_10 ( V_2 , V_69 ) ;
if ( ( V_41 & V_38 ) || ( V_41 & V_52 ) )
F_44 ( V_2 , ( V_41 & V_52 ) != 0 ) ;
}
return V_97 ;
}
static unsigned int F_49 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_39 ;
unsigned int V_108 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_108 = F_1 ( V_2 , V_69 ) & V_109 ? V_110 : 0 ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
return V_108 ;
}
static unsigned int F_50 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned char V_41 ;
unsigned int V_108 ;
V_41 = F_1 ( V_2 , V_81 ) ;
V_108 = 0 ;
if ( V_41 & V_88 )
V_108 |= V_111 ;
if ( V_41 & V_112 )
V_108 |= V_113 ;
if ( V_41 & V_114 )
V_108 |= V_115 ;
if ( V_41 & V_90 )
V_108 |= V_116 ;
return V_108 ;
}
static void F_51 ( struct V_31 * V_4 , unsigned int V_117 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned char V_118 = 0 ;
if ( V_117 & V_119 )
V_118 |= V_120 ;
if ( V_117 & V_121 )
V_118 |= V_122 ;
if ( V_117 & V_123 )
V_118 |= V_124 ;
if ( V_117 & V_125 )
V_118 |= V_14 ;
if ( V_117 & V_126 )
V_118 |= V_127 ;
F_5 ( V_2 , V_13 , V_118 ) ;
}
static void F_52 ( struct V_31 * V_4 , int V_128 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_39 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( V_128 == - 1 )
V_2 -> V_129 |= V_130 ;
else
V_2 -> V_129 &= ~ V_130 ;
F_5 ( V_2 , V_131 , V_2 -> V_129 ) ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static int F_53 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_39 ;
int V_132 ;
if ( V_2 -> V_4 . type == V_32 ) {
V_2 -> V_33 = 0 ;
F_11 ( V_2 , V_131 , 0xBF ) ;
F_11 ( V_2 , V_133 , V_134 ) ;
F_11 ( V_2 , V_30 , 0 ) ;
F_11 ( V_2 , V_131 , 0 ) ;
F_8 ( V_2 , V_135 , 0 ) ;
F_11 ( V_2 , V_131 , 0xBF ) ;
F_11 ( V_2 , V_133 , V_134 ) ;
F_11 ( V_2 , V_131 , 0 ) ;
}
#ifdef F_54
F_12 ( V_2 ) ;
#endif
if ( V_136 [ V_2 -> V_4 . type ] . V_39 & V_137 ) {
F_11 ( V_2 , V_138 , V_139 ) ;
F_11 ( V_2 , V_138 , V_139 |
V_140 | V_141 ) ;
F_11 ( V_2 , V_138 , 0 ) ;
}
( void ) F_10 ( V_2 , V_69 ) ;
( void ) F_10 ( V_2 , V_48 ) ;
( void ) F_10 ( V_2 , V_95 ) ;
( void ) F_10 ( V_2 , V_81 ) ;
if ( ! ( V_2 -> V_4 . V_39 & V_142 ) &&
( F_10 ( V_2 , V_69 ) == 0xff ) ) {
F_55 ( L_1 , V_2 -> V_4 . line ) ;
return - V_143 ;
}
if ( V_2 -> V_104 != V_144 ) {
V_132 = F_56 ( V_2 -> V_4 . V_92 , F_48 ,
V_145 , V_146 [ V_2 -> V_104 ] , V_2 ) ;
} else {
V_132 = F_56 ( V_2 -> V_4 . V_92 , F_39 ,
V_145 , V_146 [ V_2 -> V_104 ] , V_2 ) ;
}
if ( V_132 ) {
F_55 ( L_2 , V_2 -> V_4 . V_92 ) ;
return V_132 ;
}
F_11 ( V_2 , V_131 , V_147 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_2 -> V_4 . V_117 |= V_125 ;
F_51 ( & V_2 -> V_4 , V_2 -> V_4 . V_117 ) ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_2 -> V_28 = V_36 | V_148 ;
F_11 ( V_2 , V_30 , V_2 -> V_28 ) ;
if ( V_2 -> V_4 . V_39 & V_149 ) {
unsigned int V_150 ;
V_150 = ( V_2 -> V_4 . V_9 & 0xfe0 ) | 0x01f ;
F_57 ( 0x80 , V_150 ) ;
( void ) F_58 ( V_150 ) ;
}
( void ) F_10 ( V_2 , V_69 ) ;
( void ) F_10 ( V_2 , V_48 ) ;
( void ) F_10 ( V_2 , V_95 ) ;
( void ) F_10 ( V_2 , V_81 ) ;
return 0 ;
}
static void F_59 ( struct V_31 * V_4 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_39 ;
V_2 -> V_28 = 0 ;
F_11 ( V_2 , V_30 , 0 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( V_2 -> V_4 . V_39 & V_149 ) {
F_3 ( ( V_2 -> V_4 . V_9 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_4 . V_117 |= V_123 ;
} else
V_2 -> V_4 . V_117 &= ~ V_125 ;
F_51 ( & V_2 -> V_4 , V_2 -> V_4 . V_117 ) ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
F_5 ( V_2 , V_131 , F_10 ( V_2 , V_131 ) & ~ V_130 ) ;
F_11 ( V_2 , V_138 , V_139 |
V_140 |
V_141 ) ;
F_11 ( V_2 , V_138 , 0 ) ;
#ifdef F_54
F_15 ( V_2 ) ;
#endif
( void ) F_1 ( V_2 , V_48 ) ;
F_60 ( V_2 -> V_4 . V_92 , V_2 ) ;
}
static void
F_43 ( struct V_31 * V_4 , unsigned int V_99 ,
unsigned int V_151 , unsigned int V_100 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
unsigned char V_152 , V_153 = 0 ;
unsigned long V_39 ;
switch ( V_99 & V_154 ) {
case V_155 :
V_152 = 0x00 ;
break;
case V_156 :
V_152 = 0x01 ;
break;
case V_157 :
V_152 = 0x02 ;
break;
default:
case V_158 :
V_152 = 0x03 ;
break;
}
if ( V_99 & V_159 )
V_152 |= 0x04 ;
if ( V_99 & V_160 )
V_152 |= V_161 ;
if ( ! ( V_99 & V_162 ) )
V_152 |= V_163 ;
#ifdef F_61
if ( V_99 & F_61 )
V_152 |= V_164 ;
#endif
if ( ( V_100 & 0xff ) == 0 && V_2 -> V_4 . type == V_32 &&
V_2 -> V_165 == 0x5201 )
V_100 ++ ;
if ( V_136 [ V_2 -> V_4 . type ] . V_39 & V_166 ) {
if ( ( V_2 -> V_4 . V_21 / V_100 ) < ( 2400 * 16 ) )
V_153 = V_139 | V_167 ;
#ifdef F_54
else if ( V_2 -> V_4 . type == V_23 )
V_153 = V_139 | V_168 ;
#endif
else
V_153 = V_139 | V_169 ;
}
if ( V_2 -> V_4 . type == V_170 )
V_153 |= V_171 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
F_62 ( V_4 , V_99 , ( V_4 -> V_21 / ( 16 * V_100 ) ) ) ;
V_2 -> V_4 . V_37 = V_55 | V_94 | V_38 ;
if ( V_151 & V_172 )
V_2 -> V_4 . V_37 |= V_54 | V_53 ;
if ( V_151 & ( V_173 | V_174 | V_175 ) )
V_2 -> V_4 . V_37 |= V_52 ;
V_2 -> V_4 . V_67 = 0 ;
if ( V_151 & V_176 )
V_2 -> V_4 . V_67 |= V_53 | V_54 ;
if ( V_151 & V_173 ) {
V_2 -> V_4 . V_67 |= V_52 ;
if ( V_151 & V_176 )
V_2 -> V_4 . V_67 |= V_55 ;
}
if ( ( V_99 & V_177 ) == 0 )
V_2 -> V_4 . V_67 |= V_38 ;
V_2 -> V_28 &= ~ V_40 ;
if ( F_63 ( & V_2 -> V_4 , V_99 ) )
V_2 -> V_28 |= V_40 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
if ( V_136 [ V_2 -> V_4 . type ] . V_39 & V_178 ) {
F_11 ( V_2 , V_131 , 0xBF ) ;
F_11 ( V_2 , V_133 , V_99 & V_179 ? V_180 : 0 ) ;
}
F_11 ( V_2 , V_131 , V_152 | V_181 ) ;
F_11 ( V_2 , V_182 , V_100 & 0xff ) ;
F_11 ( V_2 , V_183 , V_100 >> 8 ) ;
if ( V_2 -> V_4 . type == V_170 )
F_11 ( V_2 , V_138 , V_153 ) ;
F_11 ( V_2 , V_131 , V_152 ) ;
V_2 -> V_129 = V_152 ;
if ( V_2 -> V_4 . type != V_170 ) {
if ( V_153 & V_139 ) {
F_11 ( V_2 , V_138 , V_139 ) ;
}
F_11 ( V_2 , V_138 , V_153 ) ;
}
V_2 -> V_99 = V_99 ;
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static void
F_64 ( struct V_31 * V_4 , struct V_184 * V_185 ,
struct V_184 * V_186 )
{
unsigned int V_187 , V_100 ;
V_187 = F_65 ( V_4 , V_185 , V_186 , 0 , V_4 -> V_21 / 16 ) ;
V_100 = F_66 ( V_4 , V_187 ) ;
F_43 ( V_4 , V_185 -> V_188 , V_185 -> V_189 , V_100 ) ;
}
static void F_67 ( struct V_31 * V_4 )
{
}
static int F_68 ( struct V_31 * V_4 )
{
return 0 ;
}
static void F_69 ( struct V_31 * V_4 , int V_39 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
if ( V_39 & V_190 ) {
V_4 -> type = V_2 -> V_191 ;
}
}
static int
F_70 ( struct V_31 * V_4 , struct V_192 * V_193 )
{
return - V_194 ;
}
static const char *
F_71 ( struct V_31 * V_4 )
{
int type = V_4 -> type ;
if ( type >= F_72 ( V_136 ) )
type = 0 ;
return V_136 [ type ] . V_195 ;
}
static int F_73 ( struct V_106 * V_106 , unsigned char V_44 )
{
struct V_1 * V_2 = V_106 -> V_196 ;
unsigned long V_39 ;
int V_197 ;
F_22 ( & V_198 , V_39 ) ;
do {
V_197 = F_1 ( V_2 , V_69 ) ;
} while ( ! ( V_197 & V_94 ) );
F_5 ( V_2 , V_74 , V_44 ) ;
F_23 ( & V_198 , V_39 ) ;
return 0 ;
}
static int F_74 ( struct V_106 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_196 ;
unsigned long V_39 ;
int V_108 ;
F_22 ( & V_198 , V_39 ) ;
if ( ! V_2 -> V_199 ) {
V_2 -> V_199 = 1 ;
V_108 = 0 ;
} else
V_108 = - V_200 ;
F_23 ( & V_198 , V_39 ) ;
return V_108 ;
}
static void F_75 ( struct V_106 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_196 ;
unsigned long V_39 ;
F_22 ( & V_198 , V_39 ) ;
V_2 -> V_199 = 0 ;
F_23 ( & V_198 , V_39 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned char V_201 , V_202 , V_203 , V_204 , V_205 ;
unsigned char V_206 , V_207 ;
unsigned long V_39 ;
if ( V_2 -> V_104 == V_208 )
return;
V_2 -> V_191 = V_209 ;
V_2 -> V_4 . V_6 = V_10 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( ! ( V_2 -> V_4 . V_39 & V_142 ) ) {
V_203 = F_10 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_30 , 0 ) ;
#ifdef F_77
F_2 ( 0xff , 0x080 ) ;
#endif
V_204 = F_10 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_30 , 0x0f ) ;
#ifdef F_77
F_2 ( 0 , 0x080 ) ;
#endif
V_205 = F_10 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_30 , V_203 ) ;
if ( V_204 != 0 || V_205 != 0x0F )
goto V_210;
}
V_207 = F_1 ( V_2 , V_13 ) ;
V_206 = F_1 ( V_2 , V_131 ) ;
if ( ! ( V_2 -> V_4 . V_39 & V_211 ) ) {
F_11 ( V_2 , V_13 , V_127 | 0x0A ) ;
V_201 = F_10 ( V_2 , V_81 ) & 0xF0 ;
F_11 ( V_2 , V_13 , V_207 ) ;
if ( V_201 != 0x90 )
goto V_210;
}
F_11 ( V_2 , V_131 , 0xBF ) ;
F_11 ( V_2 , V_133 , 0 ) ;
F_11 ( V_2 , V_131 , 0 ) ;
F_11 ( V_2 , V_138 , V_139 ) ;
V_203 = F_1 ( V_2 , V_95 ) >> 6 ;
switch ( V_203 ) {
case 0 :
V_2 -> V_4 . type = V_212 ;
break;
case 1 :
V_2 -> V_4 . type = V_209 ;
break;
case 2 :
V_2 -> V_4 . type = V_213 ;
break;
case 3 :
V_2 -> V_4 . type = V_214 ;
break;
}
if ( V_2 -> V_4 . type == V_214 ) {
F_11 ( V_2 , V_131 , V_181 ) ;
if ( F_1 ( V_2 , V_133 ) == 0 ) {
V_2 -> V_4 . type = V_215 ;
} else {
F_11 ( V_2 , V_131 , 0xBF ) ;
if ( F_1 ( V_2 , V_133 ) == 0 )
V_2 -> V_4 . type = V_216 ;
}
}
if ( V_2 -> V_4 . type == V_214 ) {
F_11 ( V_2 , V_131 , V_206 | V_181 ) ;
F_11 ( V_2 , V_138 ,
V_139 | V_171 ) ;
V_203 = F_1 ( V_2 , V_95 ) >> 5 ;
if ( V_203 == 7 ) {
F_11 ( V_2 , V_138 , V_139 ) ;
F_11 ( V_2 , V_131 , 0 ) ;
F_11 ( V_2 , V_138 ,
V_139 | V_171 ) ;
V_203 = F_1 ( V_2 , V_95 ) >> 5 ;
if ( V_203 == 6 )
V_2 -> V_4 . type = V_170 ;
}
F_11 ( V_2 , V_138 , V_139 ) ;
}
F_11 ( V_2 , V_131 , V_206 ) ;
if ( V_2 -> V_4 . type == V_212 ) {
V_203 = F_1 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 , 0xa5 ) ;
V_201 = F_1 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 , 0x5a ) ;
V_202 = F_1 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 , V_203 ) ;
if ( ( V_201 != 0xa5 ) || ( V_202 != 0x5a ) )
V_2 -> V_4 . type = V_217 ;
}
V_2 -> V_4 . V_76 = V_136 [ V_2 -> V_4 . type ] . V_218 ;
if ( V_2 -> V_4 . type == V_209 )
goto V_210;
V_2 -> V_191 = V_2 -> V_4 . type ;
#ifdef F_54
if ( V_2 -> V_4 . type == V_23 )
F_11 ( V_2 , V_25 , 0 ) ;
#endif
F_11 ( V_2 , V_13 , V_207 ) ;
F_11 ( V_2 , V_138 , ( V_139 |
V_140 |
V_141 ) ) ;
F_11 ( V_2 , V_138 , 0 ) ;
( void ) F_1 ( V_2 , V_48 ) ;
F_11 ( V_2 , V_30 , 0 ) ;
V_210:
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_100 , V_187 ;
#ifdef F_45
struct V_106 * V_106 ;
#endif
if ( V_2 -> V_104 == V_105 ) {
V_2 -> V_99 = V_219 | V_158 | V_220 | V_177 ;
V_187 = 1200 ;
} else {
V_2 -> V_99 = V_221 | V_158 | V_220 | V_177 ;
V_187 = 4800 ;
}
V_100 = V_2 -> V_4 . V_21 / ( 16 * V_187 ) ;
F_76 ( V_2 ) ;
if ( V_2 -> V_4 . type == V_209 )
return - V_143 ;
F_55 ( L_3 ,
V_2 -> V_4 . V_222 -> V_223 -> V_224 ,
( V_2 -> V_104 == V_105 ) ? L_4 : L_5 ,
( unsigned long long ) V_2 -> V_4 . V_225 ,
V_2 -> V_4 . V_92 ) ;
#ifdef F_45
V_106 = & V_2 -> V_106 ;
V_106 -> V_196 = V_2 ;
V_106 -> V_226 . type = V_227 ;
if ( V_2 -> V_104 == V_105 ) {
V_106 -> V_226 . V_228 = V_229 ;
F_79 ( V_106 -> V_195 , L_6 , sizeof( V_106 -> V_195 ) ) ;
} else {
V_106 -> V_226 . V_228 = V_230 ;
V_106 -> V_226 . V_231 = 1 ;
F_79 ( V_106 -> V_195 , L_7 , sizeof( V_106 -> V_195 ) ) ;
}
F_79 ( V_106 -> V_232 ,
( ! ( V_2 -> V_4 . line & 1 ) ? L_8 : L_9 ) ,
sizeof( V_106 -> V_232 ) ) ;
V_106 -> V_233 = F_73 ;
V_106 -> V_234 = F_74 ;
V_106 -> V_235 = F_75 ;
V_106 -> V_222 . V_236 = V_2 -> V_4 . V_222 ;
F_80 ( V_106 ) ;
#endif
F_43 ( & V_2 -> V_4 , V_2 -> V_99 , 0 , V_100 ) ;
F_53 ( & V_2 -> V_4 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned int V_41 , V_237 = 10000 ;
do {
V_41 = F_1 ( V_2 , V_69 ) ;
if ( V_41 & V_52 )
V_2 -> V_63 = V_52 ;
if ( -- V_237 == 0 )
break;
F_82 ( 1 ) ;
} while ( ( V_41 & V_238 ) != V_238 );
if ( V_2 -> V_4 . V_39 & V_239 ) {
V_237 = 1000000 ;
while ( -- V_237 &&
( ( F_1 ( V_2 , V_81 ) & V_90 ) == 0 ) )
F_82 ( 1 ) ;
}
}
static void F_83 ( struct V_31 * V_4 , int V_44 )
{
struct V_1 * V_2 =
F_18 ( V_4 , struct V_1 , V_4 ) ;
F_81 ( V_2 ) ;
F_5 ( V_2 , V_74 , V_44 ) ;
}
static void F_84 ( struct V_240 * V_241 , const char * V_242 ,
unsigned int V_72 )
{
struct V_1 * V_2 = & V_243 [ V_241 -> V_58 ] ;
unsigned long V_39 ;
unsigned int V_28 ;
int V_244 = 1 ;
if ( V_2 -> V_4 . V_245 || V_246 )
V_244 = F_85 ( & V_2 -> V_4 . V_24 , V_39 ) ;
else
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_28 = F_1 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_30 , 0 ) ;
F_86 ( & V_2 -> V_4 , V_242 , V_72 , F_83 ) ;
F_81 ( V_2 ) ;
F_5 ( V_2 , V_30 , V_28 ) ;
if ( V_244 )
F_23 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static int T_2 F_87 ( struct V_240 * V_241 , char * V_247 )
{
static struct V_184 V_248 ;
struct V_184 V_185 ;
struct V_31 * V_4 ;
F_55 ( L_10 ,
( V_249 . V_250 - 64 ) + V_241 -> V_58 ) ;
if ( V_241 -> V_58 > V_251 )
return - V_143 ;
V_4 = & V_243 [ V_241 -> V_58 ] . V_4 ;
F_88 ( & V_4 -> V_24 ) ;
F_89 ( V_241 , V_4 -> V_222 -> V_223 ) ;
memset ( & V_185 , 0 , sizeof( struct V_184 ) ) ;
V_185 . V_188 = V_241 -> V_99 ;
V_4 -> V_117 |= V_121 ;
V_4 -> V_252 -> V_253 ( V_4 , & V_185 , & V_248 ) ;
return 0 ;
}
static inline struct V_240 * F_90 ( void )
{
return & V_254 ;
}
static enum V_104 F_91 ( struct V_255 * V_256 )
{
struct V_255 * V_257 = F_92 ( L_11 ) ;
if ( V_257 ) {
const char * V_258 = F_93 ( V_257 , L_12 , NULL ) ;
const char * V_259 = F_93 ( V_257 , L_13 , NULL ) ;
if ( V_258 ) {
if ( V_256 == F_92 ( V_258 ) )
return V_105 ;
}
if ( V_259 ) {
if ( V_256 == F_92 ( V_259 ) )
return V_107 ;
}
}
return V_144 ;
}
static int F_94 ( struct V_260 * V_261 )
{
struct V_255 * V_256 = V_261 -> V_222 . V_223 ;
struct V_1 * V_2 ;
struct V_262 * V_263 ;
enum V_104 type ;
bool V_264 ;
int V_265 ;
type = F_91 ( V_256 ) ;
if ( type == V_144 ) {
if ( V_251 >= V_266 )
return - V_194 ;
V_2 = & V_243 [ V_251 ] ;
} else {
V_2 = F_95 ( sizeof( * V_2 ) , V_267 ) ;
if ( ! V_2 )
return - V_268 ;
}
V_2 -> V_4 . line = V_251 ;
F_88 ( & V_2 -> V_4 . V_24 ) ;
V_2 -> V_104 = type ;
V_263 = & V_261 -> V_262 [ 0 ] ;
V_2 -> V_4 . V_225 = V_263 -> V_269 ;
V_2 -> V_270 = F_96 ( V_263 ) ;
V_2 -> V_4 . V_11 = F_97 ( V_263 , 0 , V_2 -> V_270 , L_14 ) ;
if ( ! V_2 -> V_4 . V_11 ) {
if ( type != V_144 )
F_98 ( V_2 ) ;
return - V_268 ;
}
V_2 -> V_4 . V_92 = V_261 -> V_271 . V_272 [ 0 ] ;
V_2 -> V_4 . V_222 = & V_261 -> V_222 ;
V_2 -> V_4 . type = V_209 ;
V_2 -> V_4 . V_21 = ( V_273 * 16 ) ;
V_265 = 0 ;
if ( V_2 -> V_104 == V_105 || V_2 -> V_104 == V_107 ) {
V_265 = F_78 ( V_2 ) ;
if ( V_265 ) {
F_99 ( & V_261 -> V_262 [ 0 ] ,
V_2 -> V_4 . V_11 , V_2 -> V_270 ) ;
F_98 ( V_2 ) ;
return V_265 ;
}
F_100 ( V_261 , V_2 ) ;
V_251 ++ ;
return 0 ;
}
V_2 -> V_4 . V_39 |= V_274 ;
F_76 ( V_2 ) ;
V_265 = - V_143 ;
if ( V_2 -> V_4 . type == V_209 )
goto V_275;
V_2 -> V_4 . V_252 = & V_276 ;
V_264 = false ;
if ( ! strcmp ( V_256 -> V_195 , L_15 ) ||
! strcmp ( V_256 -> V_195 , L_16 ) )
V_264 = true ;
F_101 ( F_90 () , V_256 ,
& V_249 , V_2 -> V_4 . line ,
V_264 ) ;
V_265 = F_102 ( & V_249 , & V_2 -> V_4 ) ;
if ( V_265 )
goto V_275;
F_100 ( V_261 , V_2 ) ;
V_251 ++ ;
return 0 ;
V_275:
F_99 ( & V_261 -> V_262 [ 0 ] , V_2 -> V_4 . V_11 , V_2 -> V_270 ) ;
return V_265 ;
}
static int F_103 ( struct V_260 * V_261 )
{
struct V_1 * V_2 = F_104 ( V_261 ) ;
bool V_277 = false ;
if ( V_2 -> V_104 == V_107 ||
V_2 -> V_104 == V_105 )
V_277 = true ;
if ( V_277 ) {
#ifdef F_45
F_105 ( & V_2 -> V_106 ) ;
#endif
} else if ( V_2 -> V_4 . type != V_209 )
F_106 ( & V_249 , & V_2 -> V_4 ) ;
if ( V_2 -> V_4 . V_11 )
F_99 ( & V_261 -> V_262 [ 0 ] , V_2 -> V_4 . V_11 , V_2 -> V_270 ) ;
if ( V_277 )
F_98 ( V_2 ) ;
return 0 ;
}
static int T_2 F_107 ( void )
{
struct V_255 * V_256 ;
int V_265 ;
int V_278 = 0 ;
F_108 (dp, L_14 ) {
if ( F_91 ( V_256 ) == V_144 )
V_278 ++ ;
}
F_108 (dp, L_17 ) {
if ( F_91 ( V_256 ) == V_144 )
V_278 ++ ;
}
F_108 (dp, L_18 ) {
if ( F_109 ( V_256 , L_14 ) ) {
if ( F_91 ( V_256 ) == V_144 )
V_278 ++ ;
}
}
F_110 (dp, L_18 ) {
if ( F_109 ( V_256 , L_14 ) ) {
if ( F_91 ( V_256 ) == V_144 )
V_278 ++ ;
}
}
if ( V_278 ) {
V_265 = F_111 ( & V_249 , V_278 ) ;
if ( V_265 )
return V_265 ;
}
V_265 = F_112 ( & V_279 ) ;
if ( V_265 && V_278 )
F_113 ( & V_249 , V_278 ) ;
return V_265 ;
}
static void T_3 F_114 ( void )
{
F_115 ( & V_279 ) ;
if ( V_249 . V_280 )
F_113 ( & V_249 , V_249 . V_280 ) ;
}
