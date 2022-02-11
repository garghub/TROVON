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
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_16 ( V_2 ) ;
if ( V_2 -> V_4 . type == V_32 ) {
V_2 -> V_33 |= V_34 ;
F_8 ( V_2 , V_35 , V_2 -> V_33 ) ;
}
}
static void F_18 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! ( V_2 -> V_28 & V_29 ) ) {
V_2 -> V_28 |= V_29 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
if ( V_2 -> V_4 . type == V_32 && V_2 -> V_33 & V_34 ) {
V_2 -> V_33 &= ~ V_34 ;
F_8 ( V_2 , V_35 , V_2 -> V_33 ) ;
}
}
static void F_19 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_28 &= ~ V_36 ;
V_2 -> V_4 . V_37 &= ~ V_38 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
}
static void F_20 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_39 ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_2 -> V_28 |= V_40 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static struct V_41 *
F_23 ( struct V_1 * V_2 , unsigned char * V_42 )
{
struct V_41 * V_43 = V_2 -> V_4 . V_44 -> V_4 . V_43 ;
unsigned char V_45 , V_46 ;
int V_47 = 256 ;
int V_48 = 0 ;
do {
V_45 = F_10 ( V_2 , V_49 ) ;
V_46 = V_50 ;
V_2 -> V_4 . V_51 . V_52 ++ ;
if ( F_24 ( * V_42 & ( V_53 | V_54 |
V_55 | V_56 ) ) ) {
if ( * V_42 & V_53 ) {
* V_42 &= ~ ( V_55 | V_54 ) ;
V_2 -> V_4 . V_51 . V_57 ++ ;
if ( V_2 -> V_4 . V_58 != NULL &&
V_2 -> V_4 . line == V_2 -> V_4 . V_58 -> V_59 )
V_48 = 1 ;
if ( F_25 ( & V_2 -> V_4 ) )
goto V_60;
} else if ( * V_42 & V_54 )
V_2 -> V_4 . V_51 . V_61 ++ ;
else if ( * V_42 & V_55 )
V_2 -> V_4 . V_51 . V_62 ++ ;
if ( * V_42 & V_56 )
V_2 -> V_4 . V_51 . V_63 ++ ;
* V_42 &= V_2 -> V_4 . V_37 ;
if ( V_2 -> V_4 . V_58 != NULL &&
V_2 -> V_4 . line == V_2 -> V_4 . V_58 -> V_59 ) {
* V_42 |= V_2 -> V_64 ;
V_2 -> V_64 = 0 ;
}
if ( * V_42 & V_53 ) {
V_46 = V_65 ;
} else if ( * V_42 & V_54 )
V_46 = V_66 ;
else if ( * V_42 & V_55 )
V_46 = V_67 ;
}
if ( F_26 ( & V_2 -> V_4 , V_45 ) )
goto V_60;
if ( ( * V_42 & V_2 -> V_4 . V_68 ) == 0 )
F_27 ( V_43 , V_45 , V_46 ) ;
if ( * V_42 & V_56 )
F_27 ( V_43 , 0 , V_69 ) ;
V_60:
* V_42 = F_10 ( V_2 , V_70 ) ;
} while ( ( * V_42 & V_38 ) && ( V_47 -- > 0 ) );
if ( V_48 )
F_28 () ;
return V_43 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = & V_2 -> V_4 . V_44 -> V_72 ;
int V_73 ;
if ( V_2 -> V_4 . V_74 ) {
F_11 ( V_2 , V_75 , V_2 -> V_4 . V_74 ) ;
V_2 -> V_4 . V_51 . V_76 ++ ;
V_2 -> V_4 . V_74 = 0 ;
return;
}
if ( F_30 ( & V_2 -> V_4 ) ) {
F_17 ( & V_2 -> V_4 ) ;
return;
}
if ( F_31 ( V_72 ) ) {
F_16 ( V_2 ) ;
return;
}
V_73 = V_2 -> V_4 . V_77 ;
do {
F_5 ( V_2 , V_75 , V_72 -> V_78 [ V_72 -> V_79 ] ) ;
V_72 -> V_79 = ( V_72 -> V_79 + 1 ) & ( V_80 - 1 ) ;
V_2 -> V_4 . V_51 . V_76 ++ ;
if ( F_31 ( V_72 ) )
break;
} while ( -- V_73 > 0 );
if ( F_32 ( V_72 ) < V_81 )
F_33 ( & V_2 -> V_4 ) ;
if ( F_31 ( V_72 ) )
F_16 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_1 ( V_2 , V_82 ) ;
if ( ( V_42 & V_83 ) == 0 )
return;
if ( V_42 & V_84 )
V_2 -> V_4 . V_51 . V_85 ++ ;
if ( V_42 & V_86 )
V_2 -> V_4 . V_51 . V_87 ++ ;
if ( V_42 & V_88 )
F_35 ( & V_2 -> V_4 , V_42 & V_89 ) ;
if ( V_42 & V_90 )
F_36 ( & V_2 -> V_4 , V_42 & V_91 ) ;
F_37 ( & V_2 -> V_4 . V_44 -> V_4 . V_92 ) ;
}
static T_1 F_38 ( int V_93 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
unsigned long V_39 ;
unsigned char V_42 ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
do {
struct V_41 * V_43 ;
V_42 = F_10 ( V_2 , V_70 ) ;
V_43 = NULL ;
if ( V_42 & V_38 )
V_43 = F_23 ( V_2 , & V_42 ) ;
F_34 ( V_2 ) ;
if ( V_42 & V_95 )
F_29 ( V_2 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( V_43 )
F_39 ( V_43 ) ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
} while ( ! ( F_1 ( V_2 , V_96 ) & V_97 ) );
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
return V_98 ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_99 = V_2 -> V_100 ;
int V_101 , V_102 ;
V_2 -> V_100 &= ~ V_103 ;
V_2 -> V_100 |= F_41 ( V_99 , & V_102 ) ;
V_101 = V_2 -> V_4 . V_21 / ( 16 * V_102 ) ;
F_42 ( & V_2 -> V_4 , V_2 -> V_100 , 0 , V_101 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_104 )
{
do {
unsigned char V_45 = F_10 ( V_2 , V_49 ) ;
if ( V_2 -> V_105 == V_106 ) {
#ifdef F_44
F_45 ( & V_2 -> V_107 , V_45 , 0 ) ;
#endif
} else if ( V_2 -> V_105 == V_108 ) {
int V_109 = F_46 ( V_45 , V_104 ) ;
switch ( V_109 ) {
case 2 :
F_40 ( V_2 ) ;
case 1 :
break;
case 0 :
#ifdef F_44
F_45 ( & V_2 -> V_107 , V_45 , 0 ) ;
#endif
break;
} ;
}
} while ( F_1 ( V_2 , V_70 ) & V_38 );
}
static T_1 F_47 ( int V_93 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
if ( ! ( F_1 ( V_2 , V_96 ) & V_97 ) ) {
unsigned char V_42 = F_10 ( V_2 , V_70 ) ;
if ( ( V_42 & V_38 ) || ( V_42 & V_53 ) )
F_43 ( V_2 , ( V_42 & V_53 ) != 0 ) ;
}
return V_98 ;
}
static unsigned int F_48 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_39 ;
unsigned int V_109 ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_109 = F_1 ( V_2 , V_70 ) & V_110 ? V_111 : 0 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
return V_109 ;
}
static unsigned int F_49 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_42 ;
unsigned int V_109 ;
V_42 = F_1 ( V_2 , V_82 ) ;
V_109 = 0 ;
if ( V_42 & V_89 )
V_109 |= V_112 ;
if ( V_42 & V_113 )
V_109 |= V_114 ;
if ( V_42 & V_115 )
V_109 |= V_116 ;
if ( V_42 & V_91 )
V_109 |= V_117 ;
return V_109 ;
}
static void F_50 ( struct V_31 * V_4 , unsigned int V_118 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_119 = 0 ;
if ( V_118 & V_120 )
V_119 |= V_121 ;
if ( V_118 & V_122 )
V_119 |= V_123 ;
if ( V_118 & V_124 )
V_119 |= V_125 ;
if ( V_118 & V_126 )
V_119 |= V_14 ;
if ( V_118 & V_127 )
V_119 |= V_128 ;
F_5 ( V_2 , V_13 , V_119 ) ;
}
static void F_51 ( struct V_31 * V_4 , int V_129 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_39 ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( V_129 == - 1 )
V_2 -> V_130 |= V_131 ;
else
V_2 -> V_130 &= ~ V_131 ;
F_5 ( V_2 , V_132 , V_2 -> V_130 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static int F_52 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_39 ;
int V_133 ;
if ( V_2 -> V_4 . type == V_32 ) {
V_2 -> V_33 = 0 ;
F_11 ( V_2 , V_132 , 0xBF ) ;
F_11 ( V_2 , V_134 , V_135 ) ;
F_11 ( V_2 , V_30 , 0 ) ;
F_11 ( V_2 , V_132 , 0 ) ;
F_8 ( V_2 , V_136 , 0 ) ;
F_11 ( V_2 , V_132 , 0xBF ) ;
F_11 ( V_2 , V_134 , V_135 ) ;
F_11 ( V_2 , V_132 , 0 ) ;
}
#ifdef F_53
F_12 ( V_2 ) ;
#endif
if ( V_137 [ V_2 -> V_4 . type ] . V_39 & V_138 ) {
F_11 ( V_2 , V_139 , V_140 ) ;
F_11 ( V_2 , V_139 , V_140 |
V_141 | V_142 ) ;
F_11 ( V_2 , V_139 , 0 ) ;
}
( void ) F_10 ( V_2 , V_70 ) ;
( void ) F_10 ( V_2 , V_49 ) ;
( void ) F_10 ( V_2 , V_96 ) ;
( void ) F_10 ( V_2 , V_82 ) ;
if ( ! ( V_2 -> V_4 . V_39 & V_143 ) &&
( F_10 ( V_2 , V_70 ) == 0xff ) ) {
F_54 ( L_1 , V_2 -> V_4 . line ) ;
return - V_144 ;
}
if ( V_2 -> V_105 != V_145 ) {
V_133 = F_55 ( V_2 -> V_4 . V_93 , F_47 ,
V_146 , V_147 [ V_2 -> V_105 ] , V_2 ) ;
} else {
V_133 = F_55 ( V_2 -> V_4 . V_93 , F_38 ,
V_146 , V_147 [ V_2 -> V_105 ] , V_2 ) ;
}
if ( V_133 ) {
F_54 ( L_2 , V_2 -> V_4 . V_93 ) ;
return V_133 ;
}
F_11 ( V_2 , V_132 , V_148 ) ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_2 -> V_4 . V_118 |= V_126 ;
F_50 ( & V_2 -> V_4 , V_2 -> V_4 . V_118 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
V_2 -> V_28 = V_36 | V_149 ;
F_11 ( V_2 , V_30 , V_2 -> V_28 ) ;
if ( V_2 -> V_4 . V_39 & V_150 ) {
unsigned int V_151 ;
V_151 = ( V_2 -> V_4 . V_9 & 0xfe0 ) | 0x01f ;
F_56 ( 0x80 , V_151 ) ;
( void ) F_57 ( V_151 ) ;
}
( void ) F_10 ( V_2 , V_70 ) ;
( void ) F_10 ( V_2 , V_49 ) ;
( void ) F_10 ( V_2 , V_96 ) ;
( void ) F_10 ( V_2 , V_82 ) ;
return 0 ;
}
static void F_58 ( struct V_31 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_39 ;
V_2 -> V_28 = 0 ;
F_11 ( V_2 , V_30 , 0 ) ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( V_2 -> V_4 . V_39 & V_150 ) {
F_3 ( ( V_2 -> V_4 . V_9 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_4 . V_118 |= V_124 ;
} else
V_2 -> V_4 . V_118 &= ~ V_126 ;
F_50 ( & V_2 -> V_4 , V_2 -> V_4 . V_118 ) ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
F_5 ( V_2 , V_132 , F_10 ( V_2 , V_132 ) & ~ V_131 ) ;
F_11 ( V_2 , V_139 , V_140 |
V_141 |
V_142 ) ;
F_11 ( V_2 , V_139 , 0 ) ;
#ifdef F_53
F_15 ( V_2 ) ;
#endif
( void ) F_1 ( V_2 , V_49 ) ;
F_59 ( V_2 -> V_4 . V_93 , V_2 ) ;
}
static void
F_42 ( struct V_31 * V_4 , unsigned int V_100 ,
unsigned int V_152 , unsigned int V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_153 , V_154 = 0 ;
unsigned long V_39 ;
switch ( V_100 & V_155 ) {
case V_156 :
V_153 = 0x00 ;
break;
case V_157 :
V_153 = 0x01 ;
break;
case V_158 :
V_153 = 0x02 ;
break;
default:
case V_159 :
V_153 = 0x03 ;
break;
}
if ( V_100 & V_160 )
V_153 |= 0x04 ;
if ( V_100 & V_161 )
V_153 |= V_162 ;
if ( ! ( V_100 & V_163 ) )
V_153 |= V_164 ;
#ifdef F_60
if ( V_100 & F_60 )
V_153 |= V_165 ;
#endif
if ( ( V_101 & 0xff ) == 0 && V_2 -> V_4 . type == V_32 &&
V_2 -> V_166 == 0x5201 )
V_101 ++ ;
if ( V_137 [ V_2 -> V_4 . type ] . V_39 & V_167 ) {
if ( ( V_2 -> V_4 . V_21 / V_101 ) < ( 2400 * 16 ) )
V_154 = V_140 | V_168 ;
#ifdef F_53
else if ( V_2 -> V_4 . type == V_23 )
V_154 = V_140 | V_169 ;
#endif
else
V_154 = V_140 | V_170 ;
}
if ( V_2 -> V_4 . type == V_171 )
V_154 |= V_172 ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
F_61 ( V_4 , V_100 , ( V_4 -> V_21 / ( 16 * V_101 ) ) ) ;
V_2 -> V_4 . V_37 = V_56 | V_95 | V_38 ;
if ( V_152 & V_173 )
V_2 -> V_4 . V_37 |= V_55 | V_54 ;
if ( V_152 & ( V_174 | V_175 ) )
V_2 -> V_4 . V_37 |= V_53 ;
V_2 -> V_4 . V_68 = 0 ;
if ( V_152 & V_176 )
V_2 -> V_4 . V_68 |= V_54 | V_55 ;
if ( V_152 & V_177 ) {
V_2 -> V_4 . V_68 |= V_53 ;
if ( V_152 & V_176 )
V_2 -> V_4 . V_68 |= V_56 ;
}
if ( ( V_100 & V_178 ) == 0 )
V_2 -> V_4 . V_68 |= V_38 ;
V_2 -> V_28 &= ~ V_40 ;
if ( F_62 ( & V_2 -> V_4 , V_100 ) )
V_2 -> V_28 |= V_40 ;
F_5 ( V_2 , V_30 , V_2 -> V_28 ) ;
if ( V_137 [ V_2 -> V_4 . type ] . V_39 & V_179 ) {
F_11 ( V_2 , V_132 , 0xBF ) ;
F_11 ( V_2 , V_134 , V_100 & V_180 ? V_181 : 0 ) ;
}
F_11 ( V_2 , V_132 , V_153 | V_182 ) ;
F_11 ( V_2 , V_183 , V_101 & 0xff ) ;
F_11 ( V_2 , V_184 , V_101 >> 8 ) ;
if ( V_2 -> V_4 . type == V_171 )
F_11 ( V_2 , V_139 , V_154 ) ;
F_11 ( V_2 , V_132 , V_153 ) ;
V_2 -> V_130 = V_153 ;
if ( V_2 -> V_4 . type != V_171 ) {
if ( V_154 & V_140 ) {
F_11 ( V_2 , V_139 , V_140 ) ;
}
F_11 ( V_2 , V_139 , V_154 ) ;
}
V_2 -> V_100 = V_100 ;
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static void
F_63 ( struct V_31 * V_4 , struct V_185 * V_186 ,
struct V_185 * V_187 )
{
unsigned int V_188 , V_101 ;
V_188 = F_64 ( V_4 , V_186 , V_187 , 0 , V_4 -> V_21 / 16 ) ;
V_101 = F_65 ( V_4 , V_188 ) ;
F_42 ( V_4 , V_186 -> V_189 , V_186 -> V_190 , V_101 ) ;
}
static void F_66 ( struct V_31 * V_4 )
{
}
static int F_67 ( struct V_31 * V_4 )
{
return 0 ;
}
static void F_68 ( struct V_31 * V_4 , int V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_39 & V_191 ) {
V_4 -> type = V_2 -> V_192 ;
}
}
static int
F_69 ( struct V_31 * V_4 , struct V_193 * V_194 )
{
return - V_195 ;
}
static const char *
F_70 ( struct V_31 * V_4 )
{
int type = V_4 -> type ;
if ( type >= F_71 ( V_137 ) )
type = 0 ;
return V_137 [ type ] . V_196 ;
}
static int F_72 ( struct V_107 * V_107 , unsigned char V_45 )
{
struct V_1 * V_2 = V_107 -> V_197 ;
unsigned long V_39 ;
int V_198 ;
F_21 ( & V_199 , V_39 ) ;
do {
V_198 = F_1 ( V_2 , V_70 ) ;
} while ( ! ( V_198 & V_95 ) );
F_5 ( V_2 , V_75 , V_45 ) ;
F_22 ( & V_199 , V_39 ) ;
return 0 ;
}
static int F_73 ( struct V_107 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_197 ;
unsigned long V_39 ;
int V_109 ;
F_21 ( & V_199 , V_39 ) ;
if ( ! V_2 -> V_200 ) {
V_2 -> V_200 = 1 ;
V_109 = 0 ;
} else
V_109 = - V_201 ;
F_22 ( & V_199 , V_39 ) ;
return V_109 ;
}
static void F_74 ( struct V_107 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_197 ;
unsigned long V_39 ;
F_21 ( & V_199 , V_39 ) ;
V_2 -> V_200 = 0 ;
F_22 ( & V_199 , V_39 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
unsigned char V_202 , V_203 , V_204 , V_205 , V_206 ;
unsigned char V_207 , V_208 ;
unsigned long V_39 ;
if ( V_2 -> V_105 == V_209 )
return;
V_2 -> V_192 = V_210 ;
V_2 -> V_4 . V_6 = V_10 ;
F_21 ( & V_2 -> V_4 . V_24 , V_39 ) ;
if ( ! ( V_2 -> V_4 . V_39 & V_143 ) ) {
V_204 = F_10 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_30 , 0 ) ;
#ifdef F_76
F_2 ( 0xff , 0x080 ) ;
#endif
V_205 = F_10 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_30 , 0x0f ) ;
#ifdef F_76
F_2 ( 0 , 0x080 ) ;
#endif
V_206 = F_10 ( V_2 , V_30 ) ;
F_11 ( V_2 , V_30 , V_204 ) ;
if ( V_205 != 0 || V_206 != 0x0F )
goto V_211;
}
V_208 = F_1 ( V_2 , V_13 ) ;
V_207 = F_1 ( V_2 , V_132 ) ;
if ( ! ( V_2 -> V_4 . V_39 & V_212 ) ) {
F_11 ( V_2 , V_13 , V_128 | 0x0A ) ;
V_202 = F_10 ( V_2 , V_82 ) & 0xF0 ;
F_11 ( V_2 , V_13 , V_208 ) ;
if ( V_202 != 0x90 )
goto V_211;
}
F_11 ( V_2 , V_132 , 0xBF ) ;
F_11 ( V_2 , V_134 , 0 ) ;
F_11 ( V_2 , V_132 , 0 ) ;
F_11 ( V_2 , V_139 , V_140 ) ;
V_204 = F_1 ( V_2 , V_96 ) >> 6 ;
switch ( V_204 ) {
case 0 :
V_2 -> V_4 . type = V_213 ;
break;
case 1 :
V_2 -> V_4 . type = V_210 ;
break;
case 2 :
V_2 -> V_4 . type = V_214 ;
break;
case 3 :
V_2 -> V_4 . type = V_215 ;
break;
}
if ( V_2 -> V_4 . type == V_215 ) {
F_11 ( V_2 , V_132 , V_182 ) ;
if ( F_1 ( V_2 , V_134 ) == 0 ) {
V_2 -> V_4 . type = V_216 ;
} else {
F_11 ( V_2 , V_132 , 0xBF ) ;
if ( F_1 ( V_2 , V_134 ) == 0 )
V_2 -> V_4 . type = V_217 ;
}
}
if ( V_2 -> V_4 . type == V_215 ) {
F_11 ( V_2 , V_132 , V_207 | V_182 ) ;
F_11 ( V_2 , V_139 ,
V_140 | V_172 ) ;
V_204 = F_1 ( V_2 , V_96 ) >> 5 ;
if ( V_204 == 7 ) {
F_11 ( V_2 , V_139 , V_140 ) ;
F_11 ( V_2 , V_132 , 0 ) ;
F_11 ( V_2 , V_139 ,
V_140 | V_172 ) ;
V_204 = F_1 ( V_2 , V_96 ) >> 5 ;
if ( V_204 == 6 )
V_2 -> V_4 . type = V_171 ;
}
F_11 ( V_2 , V_139 , V_140 ) ;
}
F_11 ( V_2 , V_132 , V_207 ) ;
if ( V_2 -> V_4 . type == V_213 ) {
V_204 = F_1 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 , 0xa5 ) ;
V_202 = F_1 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 , 0x5a ) ;
V_203 = F_1 ( V_2 , V_15 ) ;
F_11 ( V_2 , V_15 , V_204 ) ;
if ( ( V_202 != 0xa5 ) || ( V_203 != 0x5a ) )
V_2 -> V_4 . type = V_218 ;
}
V_2 -> V_4 . V_77 = V_137 [ V_2 -> V_4 . type ] . V_219 ;
if ( V_2 -> V_4 . type == V_210 )
goto V_211;
V_2 -> V_192 = V_2 -> V_4 . type ;
#ifdef F_53
if ( V_2 -> V_4 . type == V_23 )
F_11 ( V_2 , V_25 , 0 ) ;
#endif
F_11 ( V_2 , V_13 , V_208 ) ;
F_11 ( V_2 , V_139 , ( V_140 |
V_141 |
V_142 ) ) ;
F_11 ( V_2 , V_139 , 0 ) ;
( void ) F_1 ( V_2 , V_49 ) ;
F_11 ( V_2 , V_30 , 0 ) ;
V_211:
F_22 ( & V_2 -> V_4 . V_24 , V_39 ) ;
}
static int T_2 F_77 ( struct V_1 * V_2 )
{
int V_101 , V_188 ;
#ifdef F_44
struct V_107 * V_107 ;
#endif
if ( V_2 -> V_105 == V_106 ) {
V_2 -> V_100 = V_220 | V_159 | V_221 | V_178 ;
V_188 = 1200 ;
} else {
V_2 -> V_100 = V_222 | V_159 | V_221 | V_178 ;
V_188 = 4800 ;
}
V_101 = V_2 -> V_4 . V_21 / ( 16 * V_188 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_4 . type == V_210 )
return - V_144 ;
F_54 ( L_3 ,
V_2 -> V_4 . V_223 -> V_224 -> V_225 ,
( V_2 -> V_105 == V_106 ) ? L_4 : L_5 ,
( unsigned long long ) V_2 -> V_4 . V_226 ,
V_2 -> V_4 . V_93 ) ;
#ifdef F_44
V_107 = & V_2 -> V_107 ;
V_107 -> V_197 = V_2 ;
V_107 -> V_227 . type = V_228 ;
if ( V_2 -> V_105 == V_106 ) {
V_107 -> V_227 . V_229 = V_230 ;
F_78 ( V_107 -> V_196 , L_6 , sizeof( V_107 -> V_196 ) ) ;
} else {
V_107 -> V_227 . V_229 = V_231 ;
V_107 -> V_227 . V_232 = 1 ;
F_78 ( V_107 -> V_196 , L_7 , sizeof( V_107 -> V_196 ) ) ;
}
F_78 ( V_107 -> V_233 ,
( ! ( V_2 -> V_4 . line & 1 ) ? L_8 : L_9 ) ,
sizeof( V_107 -> V_233 ) ) ;
V_107 -> V_234 = F_72 ;
V_107 -> V_235 = F_73 ;
V_107 -> V_236 = F_74 ;
V_107 -> V_223 . V_237 = V_2 -> V_4 . V_223 ;
F_79 ( V_107 ) ;
#endif
F_42 ( & V_2 -> V_4 , V_2 -> V_100 , 0 , V_101 ) ;
F_52 ( & V_2 -> V_4 ) ;
return 0 ;
}
static T_3 void F_80 ( struct V_1 * V_2 )
{
unsigned int V_42 , V_238 = 10000 ;
do {
V_42 = F_1 ( V_2 , V_70 ) ;
if ( V_42 & V_53 )
V_2 -> V_64 = V_53 ;
if ( -- V_238 == 0 )
break;
F_81 ( 1 ) ;
} while ( ( V_42 & V_239 ) != V_239 );
if ( V_2 -> V_4 . V_39 & V_240 ) {
V_238 = 1000000 ;
while ( -- V_238 &&
( ( F_1 ( V_2 , V_82 ) & V_91 ) == 0 ) )
F_81 ( 1 ) ;
}
}
static void F_82 ( struct V_31 * V_4 , int V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_80 ( V_2 ) ;
F_5 ( V_2 , V_75 , V_45 ) ;
}
static void F_83 ( struct V_241 * V_242 , const char * V_243 ,
unsigned int V_73 )
{
struct V_1 * V_2 = & V_244 [ V_242 -> V_59 ] ;
unsigned long V_39 ;
unsigned int V_28 ;
int V_245 = 1 ;
F_84 ( V_39 ) ;
if ( V_2 -> V_4 . V_246 ) {
V_245 = 0 ;
} else if ( V_247 ) {
V_245 = F_85 ( & V_2 -> V_4 . V_24 ) ;
} else
F_86 ( & V_2 -> V_4 . V_24 ) ;
V_28 = F_1 ( V_2 , V_30 ) ;
F_5 ( V_2 , V_30 , 0 ) ;
F_87 ( & V_2 -> V_4 , V_243 , V_73 , F_82 ) ;
F_80 ( V_2 ) ;
F_5 ( V_2 , V_30 , V_28 ) ;
if ( V_245 )
F_88 ( & V_2 -> V_4 . V_24 ) ;
F_89 ( V_39 ) ;
}
static int T_4 F_90 ( struct V_241 * V_242 , char * V_248 )
{
static struct V_185 V_249 ;
struct V_185 V_186 ;
struct V_31 * V_4 ;
F_54 ( L_10 ,
( V_250 . V_251 - 64 ) + V_242 -> V_59 ) ;
if ( V_242 -> V_59 >= V_252 )
V_242 -> V_59 = 0 ;
V_4 = & V_244 [ V_242 -> V_59 ] . V_4 ;
F_91 ( & V_4 -> V_24 ) ;
F_92 ( V_242 , V_4 -> V_223 -> V_224 ) ;
memset ( & V_186 , 0 , sizeof( struct V_185 ) ) ;
V_186 . V_189 = V_242 -> V_100 ;
V_4 -> V_118 |= V_122 ;
V_4 -> V_253 -> V_254 ( V_4 , & V_186 , & V_249 ) ;
return 0 ;
}
static inline struct V_241 * F_93 ( void )
{
return & V_255 ;
}
static enum V_105 T_2 F_94 ( struct V_256 * V_257 )
{
struct V_256 * V_258 = F_95 ( L_11 ) ;
if ( V_258 ) {
const char * V_259 = F_96 ( V_258 , L_12 , NULL ) ;
const char * V_260 = F_96 ( V_258 , L_13 , NULL ) ;
if ( V_259 ) {
if ( V_257 == F_95 ( V_259 ) )
return V_106 ;
}
if ( V_260 ) {
if ( V_257 == F_95 ( V_260 ) )
return V_108 ;
}
}
return V_145 ;
}
static int T_2 F_97 ( struct V_261 * V_262 )
{
static int V_263 ;
struct V_256 * V_257 = V_262 -> V_223 . V_224 ;
struct V_1 * V_2 ;
struct V_264 * V_265 ;
enum V_105 type ;
bool V_266 ;
int V_267 ;
type = F_94 ( V_257 ) ;
if ( type == V_145 ) {
if ( V_263 >= V_252 )
return - V_195 ;
V_2 = & V_244 [ V_263 ] ;
} else {
V_2 = F_98 ( sizeof( * V_2 ) , V_268 ) ;
if ( ! V_2 )
return - V_269 ;
}
V_2 -> V_4 . line = V_263 ;
F_91 ( & V_2 -> V_4 . V_24 ) ;
V_2 -> V_105 = type ;
V_265 = & V_262 -> V_264 [ 0 ] ;
V_2 -> V_4 . V_226 = V_265 -> V_270 ;
V_2 -> V_271 = ( V_265 -> V_272 - V_265 -> V_270 ) + 1 ;
V_2 -> V_4 . V_11 = F_99 ( V_265 , 0 , V_2 -> V_271 , L_14 ) ;
if ( ! V_2 -> V_4 . V_11 ) {
if ( type != V_145 )
F_100 ( V_2 ) ;
return - V_269 ;
}
V_2 -> V_4 . V_93 = V_262 -> V_273 . V_274 [ 0 ] ;
V_2 -> V_4 . V_223 = & V_262 -> V_223 ;
V_2 -> V_4 . type = V_210 ;
V_2 -> V_4 . V_21 = ( V_275 * 16 ) ;
V_267 = 0 ;
if ( V_2 -> V_105 == V_106 || V_2 -> V_105 == V_108 ) {
V_267 = F_77 ( V_2 ) ;
if ( V_267 ) {
F_101 ( & V_262 -> V_264 [ 0 ] ,
V_2 -> V_4 . V_11 , V_2 -> V_271 ) ;
F_100 ( V_2 ) ;
return V_267 ;
}
F_102 ( & V_262 -> V_223 , V_2 ) ;
return 0 ;
}
V_2 -> V_4 . V_39 |= V_276 ;
F_75 ( V_2 ) ;
V_267 = - V_144 ;
if ( V_2 -> V_4 . type == V_210 )
goto V_277;
V_2 -> V_4 . V_253 = & V_278 ;
V_266 = false ;
if ( ! strcmp ( V_257 -> V_196 , L_15 ) ||
! strcmp ( V_257 -> V_196 , L_16 ) )
V_266 = true ;
F_103 ( F_93 () , V_257 ,
& V_250 , V_2 -> V_4 . line ,
V_266 ) ;
V_267 = F_104 ( & V_250 , & V_2 -> V_4 ) ;
if ( V_267 )
goto V_277;
F_102 ( & V_262 -> V_223 , V_2 ) ;
V_263 ++ ;
return 0 ;
V_277:
F_101 ( & V_262 -> V_264 [ 0 ] , V_2 -> V_4 . V_11 , V_2 -> V_271 ) ;
return V_267 ;
}
static int T_5 F_105 ( struct V_261 * V_262 )
{
struct V_1 * V_2 = F_106 ( & V_262 -> V_223 ) ;
bool V_279 = false ;
if ( V_2 -> V_105 == V_108 ||
V_2 -> V_105 == V_106 )
V_279 = true ;
if ( V_279 ) {
#ifdef F_44
F_107 ( & V_2 -> V_107 ) ;
#endif
} else if ( V_2 -> V_4 . type != V_210 )
F_108 ( & V_250 , & V_2 -> V_4 ) ;
if ( V_2 -> V_4 . V_11 )
F_101 ( & V_262 -> V_264 [ 0 ] , V_2 -> V_4 . V_11 , V_2 -> V_271 ) ;
if ( V_279 )
F_100 ( V_2 ) ;
F_102 ( & V_262 -> V_223 , NULL ) ;
return 0 ;
}
static int T_4 F_109 ( void )
{
struct V_256 * V_257 ;
int V_267 ;
int V_280 = 0 ;
F_110 (dp, L_14 ) {
if ( F_94 ( V_257 ) == V_145 )
V_280 ++ ;
}
F_110 (dp, L_17 ) {
if ( F_94 ( V_257 ) == V_145 )
V_280 ++ ;
}
F_110 (dp, L_18 ) {
if ( F_111 ( V_257 , L_14 ) ) {
if ( F_94 ( V_257 ) == V_145 )
V_280 ++ ;
}
}
F_112 (dp, L_18 ) {
if ( F_111 ( V_257 , L_14 ) ) {
if ( F_94 ( V_257 ) == V_145 )
V_280 ++ ;
}
}
if ( V_280 ) {
V_267 = F_113 ( & V_250 , V_280 ) ;
if ( V_267 )
return V_267 ;
}
V_267 = F_114 ( & V_281 ) ;
if ( V_267 && V_280 )
F_115 ( & V_250 , V_280 ) ;
return V_267 ;
}
static void T_6 F_116 ( void )
{
if ( V_250 . V_282 )
F_115 ( & V_250 , V_250 . V_282 ) ;
}
