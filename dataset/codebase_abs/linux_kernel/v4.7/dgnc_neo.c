static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 + 0x8D ) ;
}
static inline void F_3 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
unsigned char V_8 = F_2 ( & V_5 -> V_7 -> V_8 ) ;
#if 1
V_6 |= V_9 ;
#else
V_6 &= ~ ( V_9 ) ;
#endif
V_8 |= ( V_10 | V_11 ) ;
V_8 &= ~ V_12 ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_8 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_13 | V_14 ,
& V_5 -> V_7 -> V_15 ) ;
F_4 ( 8 , & V_5 -> V_7 -> V_16 ) ;
V_5 -> V_17 = 8 ;
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_5 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
unsigned char V_8 = F_2 ( & V_5 -> V_7 -> V_8 ) ;
#if 1
V_6 |= V_19 ;
#else
V_6 &= ~ ( V_19 ) ;
#endif
V_8 |= ( V_10 | V_20 ) ;
V_6 &= ~ V_21 ;
V_8 &= ~ V_22 ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_8 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_13 | V_14 ,
& V_5 -> V_7 -> V_15 ) ;
V_5 -> V_23 = 4 ;
F_4 ( 32 , & V_5 -> V_7 -> V_24 ) ;
V_5 -> V_25 = 32 ;
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
V_5 -> V_26 |= V_27 ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_6 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
unsigned char V_8 = F_2 ( & V_5 -> V_7 -> V_8 ) ;
V_6 &= ~ V_9 ;
V_8 &= ~ V_11 ;
V_8 |= ( V_10 | V_12 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_8 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_13 | V_28 ,
& V_5 -> V_7 -> V_15 ) ;
V_5 -> V_23 = 4 ;
F_4 ( 32 , & V_5 -> V_7 -> V_24 ) ;
V_5 -> V_25 = 32 ;
F_4 ( V_5 -> V_29 , & V_5 -> V_7 -> V_30 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_31 ) ;
F_4 ( V_5 -> V_32 , & V_5 -> V_7 -> V_33 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_34 ) ;
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_7 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
unsigned char V_8 = F_2 ( & V_5 -> V_7 -> V_8 ) ;
V_6 &= ~ V_19 ;
V_8 &= ~ V_20 ;
V_6 |= V_21 ;
V_8 |= ( V_10 | V_22 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_8 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_13 | V_28 ,
& V_5 -> V_7 -> V_15 ) ;
F_4 ( 8 , & V_5 -> V_7 -> V_16 ) ;
V_5 -> V_17 = 8 ;
F_4 ( V_5 -> V_29 , & V_5 -> V_7 -> V_30 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_31 ) ;
F_4 ( V_5 -> V_32 , & V_5 -> V_7 -> V_33 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_34 ) ;
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_8 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
unsigned char V_8 = F_2 ( & V_5 -> V_7 -> V_8 ) ;
V_6 &= ~ V_19 ;
V_8 &= ~ V_20 ;
V_6 &= ~ V_21 ;
if ( V_5 -> V_35 & V_36 )
V_8 &= ~ ( V_22 ) ;
else
V_8 &= ~ ( V_10 | V_22 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_8 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_13 | V_28 ,
& V_5 -> V_7 -> V_15 ) ;
V_5 -> V_23 = 0 ;
F_4 ( 16 , & V_5 -> V_7 -> V_16 ) ;
V_5 -> V_17 = 16 ;
F_4 ( 16 , & V_5 -> V_7 -> V_24 ) ;
V_5 -> V_25 = 16 ;
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_9 ( struct V_4 * V_5 )
{
unsigned char V_6 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
unsigned char V_8 = F_2 ( & V_5 -> V_7 -> V_8 ) ;
V_6 &= ~ V_9 ;
V_8 &= ~ V_11 ;
if ( V_5 -> V_35 & V_37 )
V_8 &= ~ V_12 ;
else
V_8 &= ~ ( V_10 | V_12 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_8 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_13 | V_28 ,
& V_5 -> V_7 -> V_15 ) ;
V_5 -> V_23 = 0 ;
F_4 ( 16 , & V_5 -> V_7 -> V_16 ) ;
V_5 -> V_17 = 16 ;
F_4 ( 16 , & V_5 -> V_7 -> V_24 ) ;
V_5 -> V_25 = 16 ;
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_10 ( struct V_4 * V_5 )
{
if ( V_5 -> V_38 . V_39 & ( V_40 | V_41 ) ||
V_5 -> V_42 & V_43 )
return;
F_4 ( V_5 -> V_29 , & V_5 -> V_7 -> V_30 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_31 ) ;
F_4 ( V_5 -> V_32 , & V_5 -> V_7 -> V_33 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_34 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static inline void F_11 ( struct V_4 * V_5 , int V_44 )
{
unsigned long V_45 ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
if ( ! V_5 -> V_47 ) {
F_13 ( & V_5 -> V_46 , V_45 ) ;
return;
}
if ( V_5 -> V_48 & V_49 ) {
if ( V_44 ||
F_14 ( V_50 , V_5 -> V_47 ) ) {
unsigned char V_51 = F_2 ( & V_5 -> V_7 -> V_52 ) ;
F_4 ( ( V_51 & ~ V_53 ) , & V_5 -> V_7 -> V_52 ) ;
F_1 ( V_5 -> V_18 ) ;
V_5 -> V_48 &= ~ ( V_49 ) ;
V_5 -> V_47 = 0 ;
}
}
F_13 ( & V_5 -> V_46 , V_45 ) ;
}
static inline void F_15 ( struct V_1 * V_54 , T_1 V_55 )
{
struct V_4 * V_5 ;
unsigned char V_56 ;
unsigned char V_57 ;
unsigned long V_45 ;
V_5 = V_54 -> V_58 [ V_55 ] ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
while ( 1 ) {
V_56 = F_2 ( & V_5 -> V_7 -> V_61 ) ;
if ( V_56 & V_62 )
break;
V_56 &= ~ ( V_63 ) ;
if ( V_56 & ( V_64 | V_65 ) ) {
V_54 -> V_66 ++ ;
V_5 -> V_67 ++ ;
F_16 ( V_5 ) ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
F_17 ( V_5 ) ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
}
if ( V_56 & V_68 ) {
V_54 -> V_69 ++ ;
V_5 -> V_70 ++ ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
V_5 -> V_48 |= ( V_71 | V_72 ) ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
F_18 ( V_5 ) ;
}
if ( V_56 & V_73 ) {
V_57 = F_2 ( & V_5 -> V_7 -> V_33 ) ;
if ( V_57 == V_74 ) {
if ( V_54 -> V_58 [ V_55 ] -> V_48 & V_75 ) {
F_12 ( & V_5 -> V_46 ,
V_45 ) ;
V_5 -> V_48 &= ~ ( V_75 ) ;
F_13 ( & V_5 -> V_46 ,
V_45 ) ;
}
} else if ( V_57 == V_76 ) {
if ( ! ( V_54 -> V_58 [ V_55 ] -> V_48 & V_75 ) ) {
F_12 ( & V_5 -> V_46 ,
V_45 ) ;
V_5 -> V_48 |= V_75 ;
F_13 ( & V_5 -> V_46 ,
V_45 ) ;
}
}
}
if ( V_56 & V_77 ) {
V_54 -> V_78 ++ ;
V_5 -> V_79 ++ ;
V_57 = F_2 ( & V_5 -> V_7 -> V_80 ) ;
if ( ( V_57 & 0x4 ) == 0 ) {
if ( V_57 & V_27 ) {
F_12 ( & V_5 -> V_46 ,
V_45 ) ;
V_5 -> V_26 |= V_27 ;
F_13 ( & V_5 -> V_46 ,
V_45 ) ;
} else {
F_12 ( & V_5 -> V_46 ,
V_45 ) ;
V_5 -> V_26 &= ~ ( V_27 ) ;
F_13 ( & V_5 -> V_46 ,
V_45 ) ;
}
} else {
if ( V_57 & V_81 ) {
F_12 ( & V_5 -> V_46 ,
V_45 ) ;
V_5 -> V_26 |= V_81 ;
F_13 ( & V_5 -> V_46 ,
V_45 ) ;
} else {
F_12 ( & V_5 -> V_46 ,
V_45 ) ;
V_5 -> V_26 &= ~ ( V_81 ) ;
F_13 ( & V_5 -> V_46 ,
V_45 ) ;
}
}
}
F_19 ( V_5 , F_2 ( & V_5 -> V_7 -> V_82 ) ) ;
}
}
static inline void F_20 ( struct V_1 * V_54 , T_1 V_55 )
{
struct V_4 * V_5 ;
int V_83 ;
unsigned long V_45 ;
if ( ! V_54 || V_54 -> V_59 != V_84 )
return;
if ( V_55 >= V_54 -> V_85 )
return;
V_5 = V_54 -> V_58 [ V_55 ] ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
V_83 = F_2 ( & V_5 -> V_7 -> V_86 ) ;
V_5 -> V_87 |= V_83 ;
if ( V_5 -> V_87 & V_88 ) {
V_54 -> V_66 ++ ;
V_5 -> V_67 ++ ;
F_16 ( V_5 ) ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
F_17 ( V_5 ) ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
}
if ( V_83 & V_89 )
V_5 -> V_90 ++ ;
if ( V_83 & V_91 )
V_5 -> V_92 ++ ;
if ( V_83 & V_93 )
V_5 -> V_94 ++ ;
if ( V_83 & V_95 ) {
V_5 -> V_96 ++ ;
}
if ( V_83 & V_97 ) {
V_54 -> V_69 ++ ;
V_5 -> V_70 ++ ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
V_5 -> V_48 |= ( V_71 | V_72 ) ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
F_18 ( V_5 ) ;
} else if ( V_83 & V_98 ) {
V_54 -> V_69 ++ ;
V_5 -> V_70 ++ ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
V_5 -> V_48 |= ( V_71 | V_72 ) ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
F_18 ( V_5 ) ;
}
}
static void F_21 ( struct V_99 * V_100 )
{
unsigned char V_52 = 0 ;
unsigned char V_101 = 0 ;
unsigned char V_6 = 0 ;
unsigned char V_102 = 0 ;
T_1 V_103 = 9600 ;
int V_104 = 0 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_105 * V_106 ;
if ( ! V_100 || V_100 -> V_59 != V_107 )
return;
V_106 = (struct V_105 * ) V_100 -> V_108 ;
if ( ! V_106 || V_106 -> V_59 != V_109 )
return;
V_5 = V_106 -> V_110 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
V_2 = V_5 -> V_18 ;
if ( ! V_2 || V_2 -> V_59 != V_84 )
return;
if ( ( V_5 -> V_42 & ( V_111 ) ) == 0 ) {
V_5 -> V_112 = 0 ;
V_5 -> V_113 = 0 ;
V_5 -> V_114 = 0 ;
V_5 -> V_115 = 0 ;
V_5 -> V_116 = 0 ;
V_5 -> V_117 = 0 ;
F_22 ( V_5 ) ;
F_23 ( V_5 ) ;
V_5 -> V_48 |= ( V_118 ) ;
V_5 -> V_26 &= ~ ( V_27 | V_81 ) ;
F_24 ( V_5 ) ;
V_5 -> V_119 = 0 ;
return;
} else if ( V_5 -> V_120 ) {
V_103 = V_5 -> V_120 ;
if ( V_5 -> V_48 & V_118 ) {
V_5 -> V_48 &= ~ ( V_118 ) ;
if ( ! ( V_5 -> V_38 . V_39 & V_121 ) )
V_5 -> V_26 |= ( V_27 ) ;
if ( ! ( V_5 -> V_38 . V_39 & V_122 ) )
V_5 -> V_26 |= ( V_81 ) ;
}
} else {
int V_123 = 0 ;
int V_124 = 0 ;
T_2 V_125 [ 4 ] [ 16 ] = {
{
0 , 50 , 75 , 110 ,
134 , 150 , 200 , 300 ,
600 , 1200 , 1800 , 2400 ,
4800 , 9600 , 19200 , 38400 } ,
{
0 , 57600 , 115200 , 230400 ,
460800 , 150 , 200 , 921600 ,
600 , 1200 , 1800 , 2400 ,
4800 , 9600 , 19200 , 38400 } ,
{
0 , 57600 , 76800 , 115200 ,
131657 , 153600 , 230400 , 460800 ,
921600 , 1200 , 1800 , 2400 ,
4800 , 9600 , 19200 , 38400 } ,
{
0 , 57600 , 115200 , 230400 ,
460800 , 150 , 200 , 921600 ,
600 , 1200 , 1800 , 2400 ,
4800 , 9600 , 19200 , 38400 }
} ;
if ( ! ( V_5 -> V_126 . V_127 & V_128 ) &&
( V_106 -> V_129 == V_130 ) )
V_103 = F_25 ( V_5 -> V_131 . V_132 ) & 0xff ;
else
V_103 = F_25 ( V_5 -> V_126 . V_132 ) & 0xff ;
if ( V_5 -> V_42 & V_133 )
V_123 = 1 ;
if ( V_5 -> V_38 . V_39 & V_134 )
V_123 += 2 ;
V_124 = V_103 ;
if ( ( V_123 >= 0 ) && ( V_123 < 4 ) &&
( V_124 >= 0 ) && ( V_124 < 16 ) )
V_103 = V_125 [ V_123 ] [ V_124 ] ;
else
V_103 = 0 ;
if ( V_103 == 0 )
V_103 = 9600 ;
if ( V_5 -> V_48 & V_118 ) {
V_5 -> V_48 &= ~ ( V_118 ) ;
if ( ! ( V_5 -> V_38 . V_39 & V_121 ) )
V_5 -> V_26 |= ( V_27 ) ;
if ( ! ( V_5 -> V_38 . V_39 & V_122 ) )
V_5 -> V_26 |= ( V_81 ) ;
}
}
if ( V_5 -> V_42 & V_135 )
V_52 |= V_136 ;
if ( ! ( V_5 -> V_42 & V_137 ) )
V_52 |= V_138 ;
#ifdef F_26
if ( V_5 -> V_42 & F_26 )
V_52 |= V_139 ;
#endif
if ( V_5 -> V_42 & V_140 )
V_52 |= V_141 ;
switch ( V_5 -> V_42 & V_142 ) {
case V_143 :
V_52 |= V_144 ;
break;
case V_145 :
V_52 |= V_146 ;
break;
case V_147 :
V_52 |= V_148 ;
break;
case V_149 :
default:
V_52 |= V_150 ;
break;
}
V_102 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
V_6 = V_102 ;
V_101 = F_2 ( & V_5 -> V_7 -> V_52 ) ;
if ( V_103 == 0 )
V_103 = 9600 ;
V_104 = V_5 -> V_18 -> V_151 / V_103 ;
if ( V_104 != 0 && V_5 -> V_119 != V_103 ) {
V_5 -> V_119 = V_103 ;
F_4 ( V_152 , & V_5 -> V_7 -> V_52 ) ;
F_4 ( ( V_104 & 0xff ) , & V_5 -> V_7 -> V_153 ) ;
F_4 ( ( V_104 >> 8 ) , & V_5 -> V_7 -> V_6 ) ;
F_4 ( V_52 , & V_5 -> V_7 -> V_52 ) ;
}
if ( V_101 != V_52 )
F_4 ( V_52 , & V_5 -> V_7 -> V_52 ) ;
if ( V_5 -> V_42 & V_154 )
V_6 |= ( V_155 | V_156 ) ;
else
V_6 &= ~ ( V_155 | V_156 ) ;
if ( ( V_5 -> V_38 . V_39 & V_40 ) ||
( V_5 -> V_38 . V_39 & V_41 ) ||
( V_5 -> V_42 & V_43 ) ||
! ( V_5 -> V_38 . V_39 & V_157 ) ||
! ( V_5 -> V_42 & V_158 ) )
V_6 |= V_159 ;
else
V_6 &= ~ V_159 ;
V_6 |= V_160 ;
if ( V_6 != V_102 )
F_4 ( V_6 , & V_5 -> V_7 -> V_6 ) ;
F_10 ( V_5 ) ;
if ( V_5 -> V_38 . V_39 & V_40 || V_5 -> V_42 & V_43 ) {
F_3 ( V_5 ) ;
} else if ( V_5 -> V_35 & V_36 ) {
if ( ( V_5 -> V_29 == V_161 ) ||
( V_5 -> V_32 == V_161 ) )
F_9 ( V_5 ) ;
else
F_6 ( V_5 ) ;
} else {
F_9 ( V_5 ) ;
}
if ( V_5 -> V_38 . V_39 & V_41 || V_5 -> V_42 & V_43 ) {
F_5 ( V_5 ) ;
} else if ( V_5 -> V_35 & V_37 ) {
if ( ( V_5 -> V_29 == V_161 ) ||
( V_5 -> V_32 == V_161 ) )
F_8 ( V_5 ) ;
else
F_7 ( V_5 ) ;
} else {
F_8 ( V_5 ) ;
}
if ( V_103 < 9600 ) {
F_4 ( 1 , & V_5 -> V_7 -> V_24 ) ;
V_5 -> V_25 = 1 ;
}
F_24 ( V_5 ) ;
F_19 ( V_5 , F_2 ( & V_5 -> V_7 -> V_82 ) ) ;
}
static void F_27 ( unsigned long V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_162 ;
struct V_4 * V_5 ;
unsigned long V_45 ;
int V_163 ;
int V_164 = 0 ;
int V_165 = 0 ;
if ( ! V_2 || V_2 -> V_59 != V_84 )
return;
F_12 ( & V_2 -> V_166 , V_45 ) ;
V_164 = V_2 -> V_164 ;
V_165 = V_2 -> V_167 ;
F_13 ( & V_2 -> V_166 , V_45 ) ;
F_12 ( & V_2 -> V_168 , V_45 ) ;
if ( ( V_164 == V_169 ) && ( V_165 > 0 ) ) {
for ( V_163 = 0 ; V_163 < V_165 ; V_163 ++ ) {
V_5 = V_2 -> V_58 [ V_163 ] ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
continue;
F_28 ( V_5 ) ;
F_18 ( V_5 ) ;
F_29 ( V_5 ) ;
F_30 ( V_5 ) ;
if ( V_5 -> V_47 )
F_11 ( V_5 , 0 ) ;
}
}
F_13 ( & V_2 -> V_168 , V_45 ) ;
}
static T_3 F_31 ( int V_170 , void * V_171 )
{
struct V_1 * V_54 = V_171 ;
struct V_4 * V_5 ;
int V_55 = 0 ;
int type ;
T_4 V_172 ;
unsigned long V_45 ;
unsigned long V_173 ;
if ( ! V_54 || V_54 -> V_59 != V_84 )
return V_174 ;
V_54 -> V_175 ++ ;
F_12 ( & V_54 -> V_168 , V_45 ) ;
V_172 = F_32 ( V_54 -> V_3 + V_176 ) ;
if ( ! V_172 ) {
F_13 ( & V_54 -> V_168 , V_45 ) ;
return V_174 ;
}
while ( ( V_172 & 0xff ) != 0 ) {
type = V_172 >> ( 8 + ( V_55 * 3 ) ) ;
type &= 0x7 ;
V_172 &= ~ ( 0x01 << V_55 ) ;
switch ( type ) {
case V_177 :
if ( V_55 >= V_54 -> V_167 )
break;
V_5 = V_54 -> V_58 [ V_55 ] ;
F_16 ( V_5 ) ;
F_12 ( & V_5 -> V_46 , V_173 ) ;
F_17 ( V_5 ) ;
F_13 ( & V_5 -> V_46 , V_173 ) ;
break;
case V_178 :
F_20 ( V_54 , V_55 ) ;
break;
case V_179 :
F_15 ( V_54 , V_55 ) ;
break;
case V_180 :
F_15 ( V_54 , V_55 ) ;
break;
default:
break;
}
V_55 ++ ;
}
F_33 ( & V_54 -> V_181 ) ;
F_13 ( & V_54 -> V_168 , V_45 ) ;
return V_182 ;
}
static void F_34 ( struct V_4 * V_5 )
{
unsigned char V_183 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
V_183 &= ~ ( V_155 ) ;
F_4 ( V_183 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned char V_183 = F_2 ( & V_5 -> V_7 -> V_6 ) ;
V_183 |= ( V_155 ) ;
F_4 ( V_183 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static void F_16 ( struct V_4 * V_5 )
{
int V_184 = 0 ;
unsigned char V_83 = 0 ;
unsigned char V_185 = 0 ;
int V_186 = 0 ;
int V_187 = 0 ;
T_5 V_188 ;
T_5 V_189 ;
unsigned long V_45 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
F_12 ( & V_5 -> V_46 , V_45 ) ;
V_188 = V_5 -> V_112 & V_190 ;
V_189 = V_5 -> V_113 & V_190 ;
V_83 = V_5 -> V_87 ;
V_5 -> V_87 = 0 ;
V_184 = V_189 - V_188 - 1 ;
if ( V_184 < 0 )
V_184 += V_190 + 1 ;
if ( ! ( V_5 -> V_48 & V_191 ) ) {
V_187 = 0 ;
} else {
V_187 = F_2 ( & V_5 -> V_7 -> V_24 ) ;
if ( ( V_5 -> V_18 -> V_192 & 0xf0 ) >= V_193 )
V_187 -= 1 ;
else
V_187 -= 3 ;
}
V_187 = F_36 ( V_187 , V_184 ) ;
while ( V_187 > 0 ) {
V_83 = F_2 ( & V_5 -> V_7 -> V_86 ) ;
if ( V_83 & V_194 )
break;
V_186 = F_36 ( ( ( T_1 ) V_187 ) , ( V_195 - ( T_1 ) V_188 ) ) ;
V_186 = F_37 ( T_1 , V_186 , 12 ) ;
if ( V_83 & ( V_97 | V_98 ) )
V_5 -> V_48 |= ( V_71 | V_72 ) ;
V_83 = 0 ;
F_38 ( V_5 -> V_196 + V_188 ,
& V_5 -> V_7 -> V_197 , V_186 ) ;
memset ( V_5 -> V_198 + V_188 , 0 , V_186 ) ;
V_188 = ( V_188 + V_186 ) & V_190 ;
V_187 -= V_186 ;
V_184 -= V_186 ;
V_5 -> V_199 += V_186 ;
}
if ( V_5 -> V_35 & V_200 )
V_185 |= V_93 ;
while ( 1 ) {
V_83 |= F_2 ( & V_5 -> V_7 -> V_86 ) ;
if ( ! ( V_83 & V_88 ) ) {
V_5 -> V_87 = V_83 ;
break;
}
V_83 &= ~ V_88 ;
if ( V_83 & ( V_97 | V_98 ) ) {
V_83 &= ~ ( V_97 |
V_98 ) ;
V_5 -> V_48 |= ( V_71 | V_72 ) ;
}
if ( V_83 & V_185 ) {
unsigned char V_201 ;
V_83 = 0 ;
F_38 ( & V_201 , & V_5 -> V_7 -> V_197 , 1 ) ;
continue;
}
while ( V_184 < 1 ) {
V_189 = ( V_189 + 1 ) & V_190 ;
V_5 -> V_113 = V_189 ;
V_5 -> V_96 ++ ;
V_184 ++ ;
}
F_38 ( V_5 -> V_196 + V_188 ,
& V_5 -> V_7 -> V_197 , 1 ) ;
V_5 -> V_198 [ V_188 ] = ( unsigned char ) V_83 ;
V_83 = 0 ;
V_188 = ( V_188 + 1 ) & V_190 ;
V_184 -- ;
V_5 -> V_199 ++ ;
}
V_5 -> V_112 = V_188 & V_190 ;
V_5 -> V_114 = V_188 & V_202 ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
}
static int F_39 ( struct V_99 * V_100 , T_1 V_203 )
{
unsigned long V_45 ;
struct V_4 * V_5 ;
struct V_105 * V_106 ;
int V_204 = 0 ;
if ( ! V_100 || V_100 -> V_59 != V_107 )
return - V_205 ;
V_106 = (struct V_105 * ) V_100 -> V_108 ;
if ( ! V_106 || V_106 -> V_59 != V_109 )
return - V_205 ;
V_5 = V_106 -> V_110 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return - V_205 ;
F_12 ( & V_5 -> V_46 , V_45 ) ;
V_106 -> V_127 |= V_206 ;
F_13 ( & V_5 -> V_46 , V_45 ) ;
V_204 = F_40 ( V_106 -> V_207 ,
( ( V_106 -> V_127 & V_206 ) == 0 ) ,
F_41 ( V_203 * 1000 ) ) ;
return V_204 ;
}
static void F_22 ( struct V_4 * V_5 )
{
unsigned char V_183 = 0 ;
int V_163 = 0 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
F_4 ( ( V_208 | V_209 ) ,
& V_5 -> V_7 -> V_61 ) ;
F_1 ( V_5 -> V_18 ) ;
for ( V_163 = 0 ; V_163 < 10 ; V_163 ++ ) {
V_183 = F_2 ( & V_5 -> V_7 -> V_61 ) ;
if ( V_183 & 4 )
F_42 ( 10 ) ;
else
break;
}
V_5 -> V_48 |= ( V_71 | V_72 ) ;
}
static void F_23 ( struct V_4 * V_5 )
{
unsigned char V_183 = 0 ;
int V_163 = 0 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
F_4 ( V_208 | V_210 ,
& V_5 -> V_7 -> V_61 ) ;
F_1 ( V_5 -> V_18 ) ;
for ( V_163 = 0 ; V_163 < 10 ; V_163 ++ ) {
V_183 = F_2 ( & V_5 -> V_7 -> V_61 ) ;
if ( V_183 & 2 )
F_42 ( 10 ) ;
else
break;
}
}
static void F_18 ( struct V_4 * V_5 )
{
T_5 V_188 ;
T_5 V_189 ;
int V_186 ;
int V_211 ;
int V_212 ;
T_1 V_213 = 0 ;
unsigned long V_45 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
F_12 ( & V_5 -> V_46 , V_45 ) ;
if ( V_5 -> V_117 == V_5 -> V_116 )
goto V_214;
if ( ( V_5 -> V_48 & V_215 ) ||
( V_5 -> V_48 & V_49 ) )
goto V_214;
if ( ! ( V_5 -> V_48 & V_191 ) ) {
unsigned char V_216 = F_2 ( & V_5 -> V_7 -> V_86 ) ;
V_5 -> V_87 |= V_216 ;
if ( V_5 -> V_87 & V_97 ) {
V_5 -> V_87 &= ~ ( V_97 ) ;
if ( V_5 -> V_38 . V_39 & V_121 ) {
if ( ! ( V_5 -> V_26 & V_27 ) ) {
V_5 -> V_26 |= ( V_27 ) ;
F_24 ( V_5 ) ;
}
V_5 -> V_126 . V_127 |= ( V_206 ) ;
}
if ( V_5 -> V_38 . V_39 & V_122 ) {
if ( ! ( V_5 -> V_26 & V_81 ) ) {
V_5 -> V_26 |= ( V_81 ) ;
F_24 ( V_5 ) ;
}
V_5 -> V_126 . V_127 |= ( V_206 ) ;
}
F_4 ( V_5 -> V_217 [ V_5 -> V_117 ] ,
& V_5 -> V_7 -> V_153 ) ;
V_5 -> V_117 ++ ;
V_5 -> V_117 &= V_218 ;
V_5 -> V_219 ++ ;
}
goto V_214;
}
if ( ( V_5 -> V_18 -> V_192 & 0xf0 ) < V_193 ) {
if ( ! ( V_5 -> V_48 & ( V_71 | V_72 ) ) )
goto V_214;
V_213 = 0 ;
V_186 = F_2 ( & V_5 -> V_7 -> V_16 ) ;
if ( ( unsigned int ) V_186 > V_5 -> V_17 )
goto V_214;
V_186 = V_220 - V_5 -> V_17 ;
} else {
V_186 = V_220 - F_2 ( & V_5 -> V_7 -> V_16 ) ;
}
V_188 = V_5 -> V_116 & V_218 ;
V_189 = V_5 -> V_117 & V_218 ;
V_212 = ( V_188 - V_189 ) & V_218 ;
V_186 = F_36 ( V_186 , V_212 ) ;
while ( V_186 > 0 ) {
V_211 = ( ( V_188 >= V_189 ) ? V_188 : V_221 ) - V_189 ;
V_211 = F_36 ( V_211 , V_186 ) ;
if ( V_211 <= 0 )
break;
if ( V_5 -> V_38 . V_39 & V_121 ) {
if ( ! ( V_5 -> V_26 & V_27 ) ) {
V_5 -> V_26 |= ( V_27 ) ;
F_24 ( V_5 ) ;
}
V_5 -> V_126 . V_127 |= ( V_206 ) ;
}
if ( V_5 -> V_38 . V_39 & V_122 ) {
if ( ! ( V_5 -> V_26 & V_81 ) ) {
V_5 -> V_26 |= ( V_81 ) ;
F_24 ( V_5 ) ;
}
V_5 -> V_126 . V_127 |= ( V_206 ) ;
}
F_43 ( & V_5 -> V_7 -> V_197 ,
V_5 -> V_217 + V_189 , V_211 ) ;
V_189 = ( V_189 + V_211 ) & V_218 ;
V_186 -= V_211 ;
V_5 -> V_219 += V_211 ;
V_213 += V_211 ;
}
V_5 -> V_117 = V_189 & V_218 ;
if ( V_213 > 0 ) {
F_1 ( V_5 -> V_18 ) ;
V_5 -> V_48 &= ~ ( V_71 | V_72 ) ;
}
V_214:
F_13 ( & V_5 -> V_46 , V_45 ) ;
}
static void F_19 ( struct V_4 * V_5 , unsigned char V_222 )
{
unsigned char V_223 = V_222 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
if ( V_5 -> V_38 . V_39 & V_224 ) {
unsigned char V_225 = V_223 ;
if ( V_225 & V_226 ) {
V_223 &= ~ V_226 ;
V_223 |= V_227 ;
}
if ( V_225 & V_227 ) {
V_223 &= ~ V_227 ;
V_223 |= V_226 ;
}
if ( V_225 & V_228 ) {
V_223 &= ~ V_228 ;
V_223 |= V_229 ;
}
if ( V_225 & V_229 ) {
V_223 &= ~ V_229 ;
V_223 |= V_228 ;
}
}
V_223 &= 0xf0 ;
if ( V_223 & V_228 )
V_5 -> V_230 |= V_228 ;
else
V_5 -> V_230 &= ~ V_228 ;
if ( V_223 & V_229 )
V_5 -> V_230 |= V_229 ;
else
V_5 -> V_230 &= ~ V_229 ;
if ( V_223 & V_231 )
V_5 -> V_230 |= V_231 ;
else
V_5 -> V_230 &= ~ V_231 ;
if ( V_223 & V_232 )
V_5 -> V_230 |= V_232 ;
else
V_5 -> V_230 &= ~ V_232 ;
}
static void F_24 ( struct V_4 * V_5 )
{
unsigned char V_233 ;
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
V_233 = V_5 -> V_26 ;
if ( V_5 -> V_48 & V_234 )
V_233 |= V_235 ;
F_4 ( V_233 , & V_5 -> V_7 -> V_80 ) ;
F_1 ( V_5 -> V_18 ) ;
F_42 ( 10 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
if ( V_5 -> V_29 != V_161 ) {
V_5 -> V_236 ++ ;
F_4 ( V_5 -> V_29 , & V_5 -> V_7 -> V_153 ) ;
F_1 ( V_5 -> V_18 ) ;
F_42 ( 10 ) ;
}
}
static void F_45 ( struct V_4 * V_5 )
{
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
if ( V_5 -> V_32 != V_161 ) {
V_5 -> V_237 ++ ;
F_4 ( V_5 -> V_32 , & V_5 -> V_7 -> V_153 ) ;
F_1 ( V_5 -> V_18 ) ;
F_42 ( 10 ) ;
}
}
static void F_46 ( struct V_4 * V_5 )
{
F_4 ( 0 , & V_5 -> V_7 -> V_6 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( V_238 , & V_5 -> V_7 -> V_8 ) ;
F_2 ( & V_5 -> V_7 -> V_153 ) ;
F_4 ( V_208 | V_210 | V_209 ,
& V_5 -> V_7 -> V_61 ) ;
F_2 ( & V_5 -> V_7 -> V_86 ) ;
F_2 ( & V_5 -> V_7 -> V_82 ) ;
V_5 -> V_48 |= V_191 ;
F_4 ( V_5 -> V_26 , & V_5 -> V_7 -> V_80 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static void F_47 ( struct V_4 * V_5 )
{
F_4 ( 0 , & V_5 -> V_7 -> V_8 ) ;
F_4 ( 0 , & V_5 -> V_7 -> V_6 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static T_1 F_48 ( struct V_4 * V_5 )
{
unsigned char V_239 = 0 ;
unsigned char V_86 = F_2 ( & V_5 -> V_7 -> V_86 ) ;
V_5 -> V_87 |= V_86 ;
if ( ! ( V_86 & V_240 ) ) {
if ( V_5 -> V_48 & V_71 )
F_33 ( & V_5 -> V_18 -> V_181 ) ;
V_239 = 1 ;
} else {
V_5 -> V_48 |= ( V_71 | V_72 ) ;
V_239 = 0 ;
}
return V_239 ;
}
static void F_49 ( struct V_4 * V_5 , int V_241 )
{
if ( V_241 == 0 ) {
if ( V_5 -> V_48 & V_49 ) {
unsigned char V_51 = F_2 ( & V_5 -> V_7 -> V_52 ) ;
F_4 ( ( V_51 & ~ V_53 ) , & V_5 -> V_7 -> V_52 ) ;
F_1 ( V_5 -> V_18 ) ;
V_5 -> V_48 &= ~ ( V_49 ) ;
V_5 -> V_47 = 0 ;
}
return;
}
V_5 -> V_47 = V_50 + F_50 ( V_241 ) ;
if ( ! ( V_5 -> V_48 & V_49 ) ) {
unsigned char V_51 = F_2 ( & V_5 -> V_7 -> V_52 ) ;
F_4 ( ( V_51 | V_53 ) , & V_5 -> V_7 -> V_52 ) ;
F_1 ( V_5 -> V_18 ) ;
V_5 -> V_48 |= ( V_49 ) ;
}
}
static void F_51 ( struct V_4 * V_5 , unsigned char V_242 )
{
if ( ! V_5 || V_5 -> V_59 != V_60 )
return;
F_4 ( V_242 , & V_5 -> V_7 -> V_153 ) ;
F_1 ( V_5 -> V_18 ) ;
}
static unsigned int F_52 ( unsigned char T_6 * V_243 ,
unsigned int V_244 )
{
unsigned int V_245 ;
unsigned int V_246 ;
unsigned int V_247 ;
unsigned int V_248 ;
F_4 ( V_249 , V_243 + V_250 ) ;
V_245 = V_244 | 0x180 ;
for ( V_246 = 9 ; V_246 -- ; ) {
V_247 = ( V_245 & ( 1 << V_246 ) ) ? V_251 : 0 ;
F_4 ( V_247 | V_249 , V_243 + V_250 ) ;
F_4 ( V_247 | V_249 | V_252 , V_243 + V_250 ) ;
}
V_248 = 0 ;
for ( V_246 = 17 ; V_246 -- ; ) {
F_4 ( V_249 , V_243 + V_250 ) ;
F_4 ( V_249 | V_252 , V_243 + V_250 ) ;
V_248 <<= 1 ;
if ( F_2 ( V_243 + V_250 ) & V_253 )
V_248 |= 1 ;
}
F_4 ( V_249 , V_243 + V_250 ) ;
F_4 ( 0x00 , V_243 + V_250 ) ;
return V_248 ;
}
static void F_53 ( struct V_1 * V_54 )
{
unsigned int V_163 = 0 ;
unsigned int V_254 ;
if ( ! V_54 || V_54 -> V_59 != V_84 )
return;
if ( ! V_54 -> V_3 )
return;
for ( V_163 = 0 ; V_163 < V_255 ; V_163 ++ ) {
V_254 = F_52 ( V_54 -> V_3 , V_163 ) ;
V_54 -> V_256 [ V_163 * 2 ] = V_254 & 0xff ;
V_54 -> V_256 [ ( V_163 * 2 ) + 1 ] = ( V_254 >> 8 ) & 0xff ;
}
if ( ( ( V_54 -> V_256 [ 0x08 ] != 0x82 ) &&
( V_54 -> V_256 [ 0x10 ] != 0x82 ) ) ||
( V_54 -> V_256 [ 0x7F ] != 0x78 ) ) {
memset ( V_54 -> V_256 , '\0' , V_255 ) ;
} else {
for ( V_163 = 0 ; V_163 < V_257 - 3 ; V_163 ++ )
if ( V_54 -> V_256 [ V_163 ] == 'S' && V_54 -> V_256 [ V_163 + 1 ] == 'N' )
strncpy ( V_54 -> V_258 , & V_54 -> V_256 [ V_163 + 3 ] , 9 ) ;
}
}
