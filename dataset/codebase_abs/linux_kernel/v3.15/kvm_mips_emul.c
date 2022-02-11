unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned int V_4 ;
union V_5 V_6 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
long V_9 = V_3 ;
long V_10 = V_11 ;
if ( V_9 & 3 )
goto V_12;
V_6 . V_13 = F_2 ( ( V_14 * ) V_9 , V_2 ) ;
if ( V_6 . V_13 == V_11 )
return V_11 ;
switch ( V_6 . V_15 . V_16 ) {
case V_17 :
switch ( V_6 . V_18 . V_19 ) {
case V_20 :
V_8 -> V_21 [ V_6 . V_18 . V_22 ] = V_9 + 8 ;
case V_23 :
V_10 = V_8 -> V_21 [ V_6 . V_18 . V_24 ] ;
break;
}
break;
case V_25 :
switch ( V_6 . V_15 . V_26 ) {
case V_27 :
case V_28 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] < 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_30 :
case V_31 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] >= 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_32 :
case V_33 :
V_8 -> V_21 [ 31 ] = V_9 + 8 ;
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] < 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_34 :
case V_35 :
V_8 -> V_21 [ 31 ] = V_9 + 8 ;
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] >= 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_36 :
if ( ! V_37 )
goto V_38;
V_4 = F_3 ( 0x01 ) ;
if ( V_4 >= 32 ) {
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
} else
V_9 += 8 ;
V_10 = V_9 ;
break;
}
break;
case V_39 :
V_8 -> V_21 [ 31 ] = V_3 + 8 ;
case V_40 :
V_9 += 4 ;
V_9 >>= 28 ;
V_9 <<= 28 ;
V_9 |= ( V_6 . V_41 . V_42 << 2 ) ;
V_10 = V_9 ;
break;
case V_43 :
case V_44 :
if ( V_8 -> V_21 [ V_6 . V_15 . V_24 ] ==
V_8 -> V_21 [ V_6 . V_15 . V_26 ] )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_45 :
case V_46 :
if ( V_8 -> V_21 [ V_6 . V_15 . V_24 ] !=
V_8 -> V_21 [ V_6 . V_15 . V_26 ] )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_47 :
case V_48 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] <= 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_49 :
case V_50 :
if ( ( long ) V_8 -> V_21 [ V_6 . V_15 . V_24 ] > 0 )
V_9 = V_9 + 4 + ( V_6 . V_15 . V_29 << 2 ) ;
else
V_9 += 8 ;
V_10 = V_9 ;
break;
case V_51 :
F_4 ( L_1 , V_52 ) ;
break;
}
return V_10 ;
V_12:
F_4 ( L_2 , V_52 ) ;
return V_10 ;
V_38:
F_4 ( L_3 , V_52 ) ;
return V_10 ;
}
enum V_53 F_5 ( struct V_1 * V_2 , V_14 V_54 )
{
unsigned long V_55 ;
enum V_53 V_56 = V_57 ;
if ( V_54 & V_58 ) {
V_55 = F_1 ( V_2 , V_2 -> V_8 . V_59 ) ;
if ( V_55 == V_11 ) {
V_56 = V_60 ;
} else {
V_2 -> V_8 . V_59 = V_55 ;
F_6 ( L_4 , V_2 -> V_8 . V_59 ) ;
}
} else
V_2 -> V_8 . V_59 += 4 ;
F_6 ( L_5 , V_2 -> V_8 . V_59 ) ;
return V_56 ;
}
enum V_53 F_7 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
if ( ! ( F_8 ( V_62 ) & V_63 ) ) {
F_9 ( & V_2 -> V_8 . V_64 ) ;
F_10 ( & V_2 -> V_8 . V_64 ,
F_11 ( 0 , F_12 ( 10 ) ) , V_65 ) ;
} else {
F_9 ( & V_2 -> V_8 . V_64 ) ;
}
return V_56 ;
}
enum V_53 F_13 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
if ( F_14 ( V_62 ) & V_66 ) {
F_6 ( L_6 , V_2 -> V_8 . V_59 ,
F_15 ( V_62 ) ) ;
F_16 ( V_62 , V_66 ) ;
V_2 -> V_8 . V_59 = F_15 ( V_62 ) ;
} else if ( F_14 ( V_62 ) & V_67 ) {
F_16 ( V_62 , V_67 ) ;
V_2 -> V_8 . V_59 = F_17 ( V_62 ) ;
} else {
F_4 ( L_7 ,
V_2 -> V_8 . V_59 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53 F_18 ( struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
F_6 ( L_8 , V_2 -> V_8 . V_59 ,
V_2 -> V_8 . V_68 ) ;
++ V_2 -> V_69 . V_70 ;
F_19 ( V_2 , V_71 ) ;
if ( ! V_2 -> V_8 . V_68 ) {
V_2 -> V_8 . V_72 = 1 ;
F_20 ( V_2 ) ;
if ( F_21 ( V_73 , V_2 ) ) {
F_22 ( V_73 , & V_2 -> V_74 ) ;
V_2 -> V_75 -> V_76 = V_77 ;
}
}
return V_56 ;
}
enum V_53 F_23 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_60 ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
F_4 ( L_9 , V_59 , F_24 ( V_62 ) ) ;
return V_56 ;
}
enum V_53 F_25 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
int V_78 = F_24 ( V_62 ) ;
enum V_53 V_56 = V_57 ;
struct V_79 * V_80 = NULL ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
if ( V_78 < 0 || V_78 >= V_81 ) {
F_4 ( L_10 , V_52 , V_78 ) ;
F_4
( L_11 ,
V_59 , V_78 , F_26 ( V_62 ) ,
F_27 ( V_62 ) ,
F_28 ( V_62 ) ,
F_29 ( V_62 ) ) ;
V_78 = ( V_78 & ~ 0x80000000 ) % V_81 ;
}
V_80 = & V_2 -> V_8 . V_82 [ V_78 ] ;
#if 1
F_30 ( V_2 , V_80 -> V_83 ) ;
#endif
V_80 -> V_84 = F_29 ( V_62 ) ;
V_80 -> V_83 = F_26 ( V_62 ) ;
V_80 -> V_85 = F_27 ( V_62 ) ;
V_80 -> V_86 = F_28 ( V_62 ) ;
F_6
( L_11 ,
V_59 , V_78 , F_26 ( V_62 ) ,
F_27 ( V_62 ) , F_28 ( V_62 ) ,
F_29 ( V_62 ) ) ;
return V_56 ;
}
enum V_53 F_31 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
struct V_79 * V_80 = NULL ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
int V_78 ;
#if 1
F_32 ( & V_78 , sizeof( V_78 ) ) ;
V_78 &= ( V_81 - 1 ) ;
#else
V_78 = V_87 % V_81 ;
#endif
if ( V_78 < 0 || V_78 >= V_81 ) {
F_4 ( L_10 , V_52 , V_78 ) ;
return V_60 ;
}
V_80 = & V_2 -> V_8 . V_82 [ V_78 ] ;
#if 1
F_30 ( V_2 , V_80 -> V_83 ) ;
#endif
V_80 -> V_84 = F_29 ( V_62 ) ;
V_80 -> V_83 = F_26 ( V_62 ) ;
V_80 -> V_85 = F_27 ( V_62 ) ;
V_80 -> V_86 = F_28 ( V_62 ) ;
F_6
( L_12 ,
V_59 , V_78 , F_26 ( V_62 ) ,
F_27 ( V_62 ) ,
F_28 ( V_62 ) ) ;
return V_56 ;
}
enum V_53 F_33 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
long V_88 = F_26 ( V_62 ) ;
enum V_53 V_56 = V_57 ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
int V_78 = - 1 ;
V_78 = F_34 ( V_2 , V_88 ) ;
F_35 ( V_62 , V_78 ) ;
F_6 ( L_13 , V_59 , V_88 ,
V_78 ) ;
return V_56 ;
}
enum V_53
F_36 ( V_14 V_89 , V_14 * V_90 , V_14 V_54 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
enum V_53 V_56 = V_57 ;
T_1 V_26 , V_22 , V_92 , V_93 , V_94 , V_95 ;
V_14 V_59 = V_2 -> V_8 . V_59 ;
unsigned long V_96 ;
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 ) {
return V_56 ;
}
V_92 = ( V_89 >> 21 ) & 0x1f ;
V_26 = ( V_89 >> 16 ) & 0x1f ;
V_22 = ( V_89 >> 11 ) & 0x1f ;
V_93 = V_89 & 0x7 ;
V_94 = ( V_89 >> 25 ) & 1 ;
if ( V_94 ) {
V_95 = ( V_89 ) & 0xff ;
switch ( V_95 ) {
case V_97 :
V_56 = F_23 ( V_2 ) ;
break;
case V_98 :
V_56 = F_25 ( V_2 ) ;
break;
case V_99 :
V_56 = F_31 ( V_2 ) ;
break;
case V_100 :
V_56 = F_33 ( V_2 ) ;
break;
case V_101 :
F_4 ( L_14 ) ;
break;
case V_102 :
V_56 = F_13 ( V_2 ) ;
goto V_103;
break;
case V_104 :
V_56 = F_18 ( V_2 ) ;
break;
}
} else {
switch ( V_92 ) {
case V_105 :
#ifdef F_37
V_62 -> V_69 [ V_22 ] [ V_93 ] ++ ;
#endif
if ( ( V_22 == V_106 ) && ( V_93 == 0 ) ) {
V_2 -> V_8 . V_21 [ V_26 ] = ( F_38 () >> 2 ) ;
} else if ( ( V_22 == V_107 ) && ( V_93 == 0 ) ) {
V_2 -> V_8 . V_21 [ V_26 ] = 0x0 ;
#ifdef F_39
F_40 ( V_89 , V_90 , V_2 ) ;
#endif
}
else {
V_2 -> V_8 . V_21 [ V_26 ] = V_62 -> V_108 [ V_22 ] [ V_93 ] ;
#ifdef F_39
F_40 ( V_89 , V_90 , V_2 ) ;
#endif
}
F_6
( L_15 ,
V_59 , V_22 , V_93 , V_26 , V_2 -> V_8 . V_21 [ V_26 ] ) ;
break;
case V_109 :
V_2 -> V_8 . V_21 [ V_26 ] = V_62 -> V_108 [ V_22 ] [ V_93 ] ;
break;
case V_110 :
#ifdef F_37
V_62 -> V_69 [ V_22 ] [ V_93 ] ++ ;
#endif
if ( ( V_22 == V_111 )
&& ( V_2 -> V_8 . V_21 [ V_26 ] >=
V_81 ) ) {
F_4 ( L_16 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_56 = V_60 ;
break;
}
#define F_41 0xff
if ( ( V_22 == V_112 ) && ( V_93 == 1 ) ) {
F_42 ( V_62 ,
~ ( F_41 ) ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
F_4 ( L_17 ,
F_43 ( V_62 ) ) ;
} else if ( V_22 == V_113 && V_93 == 0 ) {
V_14 V_114 =
V_2 -> V_8 . V_21 [ V_26 ] & V_115 ;
if ( ( F_44 ( V_2 -> V_8 . V_21 [ V_26 ] ) != V_116 )
&&
( ( F_26 ( V_62 ) &
V_115 ) != V_114 ) ) {
F_6
( L_18 ,
F_26 ( V_62 ) &
V_115 ,
V_2 -> V_8 . V_21 [ V_26 ] & V_115 ) ;
F_45 ( 1 ) ;
}
F_46 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
}
else if ( ( V_22 == V_106 ) && ( V_93 == 0 ) ) {
goto V_117;
} else if ( ( V_22 == V_118 ) && ( V_93 == 0 ) ) {
F_6 ( L_19 ,
V_59 , F_47 ( V_62 ) ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_119 -> V_120 ( V_2 ) ;
F_48 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
} else if ( ( V_22 == V_121 ) && ( V_93 == 0 ) ) {
F_49 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
F_16 ( V_62 ,
( V_122 | V_123 ) ) ;
#ifdef F_39
F_50 ( V_89 , V_90 , V_2 ) ;
#endif
} else {
V_62 -> V_108 [ V_22 ] [ V_93 ] = V_2 -> V_8 . V_21 [ V_26 ] ;
#ifdef F_39
F_50 ( V_89 , V_90 , V_2 ) ;
#endif
}
F_6 ( L_20 , V_59 ,
V_22 , V_93 , V_62 -> V_108 [ V_22 ] [ V_93 ] ) ;
break;
case V_124 :
F_4
( L_21 ,
V_2 -> V_8 . V_59 , V_26 , V_22 , V_93 ) ;
V_56 = V_60 ;
break;
case V_125 :
#ifdef F_51
V_62 -> V_69 [ V_121 ] [ 0 ] ++ ;
#endif
if ( V_26 != 0 ) {
V_2 -> V_8 . V_21 [ V_26 ] =
F_14 ( V_62 ) ;
}
if ( V_89 & 0x20 ) {
F_6 ( L_22 ,
V_2 -> V_8 . V_59 ) ;
F_52 ( V_62 , V_126 ) ;
} else {
F_6 ( L_23 ,
V_2 -> V_8 . V_59 ) ;
F_16 ( V_62 , V_126 ) ;
}
break;
case V_127 :
{
V_14 V_128 =
V_62 -> V_108 [ V_121 ] [ 2 ] & 0xf ;
V_14 V_129 =
( V_62 -> V_108 [ V_121 ] [ 2 ] >> 6 ) & 0xf ;
if ( V_128 || V_129 ) {
V_56 = V_60 ;
break;
}
F_6 ( L_24 , V_129 , V_22 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_2 -> V_8 . V_21 [ V_22 ] = V_2 -> V_8 . V_21 [ V_26 ] ;
}
break;
default:
F_4
( L_25 ,
V_2 -> V_8 . V_59 , V_92 ) ;
V_56 = V_60 ;
break;
}
}
V_117:
if ( V_56 == V_60 ) {
V_2 -> V_8 . V_59 = V_96 ;
}
V_103:
return V_56 ;
}
enum V_53
F_53 ( V_14 V_89 , V_14 V_54 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_130 ;
T_1 V_95 , V_131 , V_26 , V_132 ;
V_14 V_133 ;
void * V_134 = V_75 -> V_135 . V_134 ;
unsigned long V_96 ;
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
V_26 = ( V_89 >> 16 ) & 0x1f ;
V_131 = ( V_89 >> 21 ) & 0x1f ;
V_132 = V_89 & 0xffff ;
V_95 = ( V_89 >> 26 ) & 0x3f ;
switch ( V_95 ) {
case V_136 :
V_133 = 1 ;
if ( V_133 > sizeof( V_75 -> V_135 . V_134 ) ) {
F_54 ( L_26 , V_52 ,
V_75 -> V_135 . V_137 ) ;
}
V_75 -> V_135 . V_138 =
V_119 -> V_139 ( V_2 -> V_8 .
V_140 ) ;
if ( V_75 -> V_135 . V_138 == V_141 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_137 = V_133 ;
V_75 -> V_135 . V_142 = 1 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = 1 ;
* ( V_145 * ) V_134 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_27 ,
V_2 -> V_8 . V_140 , V_2 -> V_8 . V_21 [ V_26 ] ,
* ( V_146 * ) V_134 ) ;
break;
case V_147 :
V_133 = 4 ;
if ( V_133 > sizeof( V_75 -> V_135 . V_134 ) ) {
F_54 ( L_26 , V_52 ,
V_75 -> V_135 . V_137 ) ;
}
V_75 -> V_135 . V_138 =
V_119 -> V_139 ( V_2 -> V_8 .
V_140 ) ;
if ( V_75 -> V_135 . V_138 == V_141 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_137 = V_133 ;
V_75 -> V_135 . V_142 = 1 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = 1 ;
* ( V_14 * ) V_134 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_28 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_140 ,
V_2 -> V_8 . V_21 [ V_26 ] , * ( V_14 * ) V_134 ) ;
break;
case V_148 :
V_133 = 2 ;
if ( V_133 > sizeof( V_75 -> V_135 . V_134 ) ) {
F_54 ( L_26 , V_52 ,
V_75 -> V_135 . V_137 ) ;
}
V_75 -> V_135 . V_138 =
V_119 -> V_139 ( V_2 -> V_8 .
V_140 ) ;
if ( V_75 -> V_135 . V_138 == V_141 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_137 = V_133 ;
V_75 -> V_135 . V_142 = 1 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = 1 ;
* ( V_149 * ) V_134 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_29 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_140 ,
V_2 -> V_8 . V_21 [ V_26 ] , * ( V_14 * ) V_134 ) ;
break;
default:
F_4 ( L_30 ) ;
V_56 = V_60 ;
break;
}
if ( V_56 == V_60 ) {
V_2 -> V_8 . V_59 = V_96 ;
}
return V_56 ;
}
enum V_53
F_55 ( V_14 V_89 , V_14 V_54 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_130 ;
T_1 V_95 , V_131 , V_26 , V_132 ;
V_14 V_133 ;
V_26 = ( V_89 >> 16 ) & 0x1f ;
V_131 = ( V_89 >> 21 ) & 0x1f ;
V_132 = V_89 & 0xffff ;
V_95 = ( V_89 >> 26 ) & 0x3f ;
V_2 -> V_8 . V_150 = V_54 ;
V_2 -> V_8 . V_151 = V_26 ;
switch ( V_95 ) {
case V_152 :
V_133 = 4 ;
if ( V_133 > sizeof( V_75 -> V_135 . V_134 ) ) {
F_54 ( L_26 , V_52 ,
V_75 -> V_135 . V_137 ) ;
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_138 =
V_119 -> V_139 ( V_2 -> V_8 .
V_140 ) ;
if ( V_75 -> V_135 . V_138 == V_141 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_137 = V_133 ;
V_75 -> V_135 . V_142 = 0 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = 0 ;
break;
case V_153 :
case V_154 :
V_133 = 2 ;
if ( V_133 > sizeof( V_75 -> V_135 . V_134 ) ) {
F_54 ( L_26 , V_52 ,
V_75 -> V_135 . V_137 ) ;
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_138 =
V_119 -> V_139 ( V_2 -> V_8 .
V_140 ) ;
if ( V_75 -> V_135 . V_138 == V_141 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_137 = V_133 ;
V_75 -> V_135 . V_142 = 0 ;
V_2 -> V_143 = 1 ;
V_2 -> V_144 = 0 ;
if ( V_95 == V_153 )
V_2 -> V_143 = 2 ;
else
V_2 -> V_143 = 1 ;
break;
case V_155 :
case V_156 :
V_133 = 1 ;
if ( V_133 > sizeof( V_75 -> V_135 . V_134 ) ) {
F_54 ( L_26 , V_52 ,
V_75 -> V_135 . V_137 ) ;
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_138 =
V_119 -> V_139 ( V_2 -> V_8 .
V_140 ) ;
if ( V_75 -> V_135 . V_138 == V_141 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_135 . V_137 = V_133 ;
V_75 -> V_135 . V_142 = 0 ;
V_2 -> V_144 = 0 ;
if ( V_95 == V_156 )
V_2 -> V_143 = 2 ;
else
V_2 -> V_143 = 1 ;
break;
default:
F_4 ( L_31 ) ;
V_56 = V_60 ;
break;
}
return V_56 ;
}
int F_56 ( unsigned long V_157 , struct V_1 * V_2 )
{
unsigned long V_132 = ( V_157 & ~ V_158 ) ;
struct V_159 * V_159 = V_2 -> V_159 ;
unsigned long V_160 ;
T_2 V_161 ;
T_3 V_162 ;
V_161 = V_157 >> V_163 ;
if ( V_161 >= V_159 -> V_8 . V_164 ) {
F_4 ( L_32 , V_52 , V_161 ) ;
F_57 () ;
F_58 ( V_2 ) ;
return - 1 ;
}
V_162 = V_159 -> V_8 . V_165 [ V_161 ] ;
V_160 = ( V_162 << V_163 ) | V_132 ;
F_4 ( L_33 , V_52 , V_157 , F_59 ( V_160 ) ) ;
F_60 ( F_59 ( V_160 ) , 32 ) ;
return 0 ;
}
enum V_53
F_61 ( V_14 V_89 , V_14 * V_90 , V_14 V_54 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
extern void (* F_62) ( void );
extern void (* F_63) ( void );
enum V_53 V_56 = V_57 ;
T_1 V_132 , V_166 , V_167 , V_95 , V_131 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned long V_157 ;
unsigned long V_96 ;
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
V_131 = ( V_89 >> 21 ) & 0x1f ;
V_167 = ( V_89 >> 16 ) & 0x1f ;
V_132 = V_89 & 0xffff ;
V_166 = ( V_89 >> 16 ) & 0x3 ;
V_95 = ( V_89 >> 18 ) & 0x7 ;
V_157 = V_8 -> V_21 [ V_131 ] + V_132 ;
F_6 ( L_34 ,
V_166 , V_95 , V_131 , V_8 -> V_21 [ V_131 ] , V_132 ) ;
if ( V_95 == V_168 ) {
F_6
( L_35 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_21 [ 31 ] , V_166 , V_95 , V_131 ,
V_8 -> V_21 [ V_131 ] , V_132 ) ;
if ( V_166 == V_169 )
F_62 () ;
else if ( V_166 == V_170 )
F_63 () ;
else {
F_4 ( L_36 ,
V_52 ) ;
return V_60 ;
}
#ifdef F_39
F_64 ( V_89 , V_90 , V_2 ) ;
#endif
goto V_117;
}
F_65 () ;
if ( F_66 ( V_157 ) == V_171 ) {
if ( F_67 ( V_2 , V_157 ) < 0 ) {
F_68 ( V_157 , V_2 ) ;
}
} else if ( ( F_66 ( V_157 ) < V_171 ) ||
F_66 ( V_157 ) == V_172 ) {
int V_78 ;
if ( F_67 ( V_2 , V_157 ) >= 0 ) {
goto V_173;
}
V_78 = F_34 ( V_2 , ( V_157 & V_174 ) |
( F_26
( V_62 ) & V_115 ) ) ;
if ( V_78 < 0 ) {
V_2 -> V_8 . V_175 = ( V_157 & V_174 ) ;
V_2 -> V_8 . V_140 = V_157 ;
V_56 = F_69 ( V_54 , NULL , V_75 ,
V_2 ) ;
F_70 () ;
goto V_103;
} else {
struct V_79 * V_80 = & V_2 -> V_8 . V_82 [ V_78 ] ;
if ( ! F_71 ( * V_80 , V_157 ) ) {
V_56 = F_72 ( V_54 , NULL ,
V_75 , V_2 ) ;
F_70 () ;
goto V_103;
} else {
F_73 ( V_2 , V_80 ,
NULL ,
NULL ) ;
}
}
} else {
F_4
( L_37 ,
V_166 , V_95 , V_131 , V_8 -> V_21 [ V_131 ] , V_132 ) ;
V_56 = V_60 ;
F_70 () ;
goto V_103;
}
V_173:
if ( V_166 == V_169
&& ( V_95 == V_176
|| V_95 == V_177 ) ) {
F_74 ( V_157 ) ;
#ifdef F_39
F_75 ( V_89 , V_90 , V_2 ) ;
#endif
} else if ( V_95 == V_177 && V_166 == V_170 ) {
F_74 ( V_157 ) ;
F_76 ( V_157 ) ;
#ifdef F_39
F_75 ( V_89 , V_90 , V_2 ) ;
#endif
} else {
F_4
( L_38 ,
V_166 , V_95 , V_131 , V_8 -> V_21 [ V_131 ] , V_132 ) ;
V_56 = V_60 ;
F_70 () ;
goto V_103;
}
F_70 () ;
V_103:
V_2 -> V_8 . V_59 = V_96 ;
V_117:
return V_56 ;
}
enum V_53
F_77 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_89 ;
if ( V_54 & V_58 ) {
V_90 += 1 ;
}
V_89 = F_2 ( V_90 , V_2 ) ;
switch ( ( (union V_5 ) V_89 ) . V_18 . V_16 ) {
case V_178 :
V_56 = F_36 ( V_89 , V_90 , V_54 , V_75 , V_2 ) ;
break;
case V_136 :
case V_148 :
case V_147 :
V_56 = F_53 ( V_89 , V_54 , V_75 , V_2 ) ;
break;
case V_156 :
case V_155 :
case V_154 :
case V_153 :
case V_152 :
V_56 = F_55 ( V_89 , V_54 , V_75 , V_2 ) ;
break;
case V_179 :
++ V_2 -> V_69 . V_180 ;
F_19 ( V_2 , V_181 ) ;
V_56 = F_61 ( V_89 , V_90 , V_54 , V_75 , V_2 ) ;
break;
default:
F_4 ( L_39 , V_90 ,
V_89 ) ;
F_58 ( V_2 ) ;
V_56 = V_60 ;
break;
}
return V_56 ;
}
enum V_53
F_78 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_40 , V_8 -> V_59 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_182 << V_183 ) ) ;
V_8 -> V_59 = V_171 + 0x180 ;
} else {
F_4 ( L_41 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_69 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_88 = ( V_2 -> V_8 . V_140 & V_174 ) |
( F_26 ( V_62 ) & V_115 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_42 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x0 ;
} else {
F_6 ( L_43 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_184 << V_183 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_140 ) ;
F_46 ( V_62 , V_88 ) ;
F_45 ( 1 ) ;
return V_56 ;
}
enum V_53
F_72 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_88 =
( V_2 -> V_8 . V_140 & V_174 ) |
( F_26 ( V_62 ) & V_115 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_44 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
} else {
F_6 ( L_43 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_184 << V_183 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_140 ) ;
F_46 ( V_62 , V_88 ) ;
F_45 ( 1 ) ;
return V_56 ;
}
enum V_53
F_84 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_88 = ( V_2 -> V_8 . V_140 & V_174 ) |
( F_26 ( V_62 ) & V_115 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_45 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x0 ;
} else {
F_6 ( L_46 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_185 << V_183 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_140 ) ;
F_46 ( V_62 , V_88 ) ;
F_45 ( 1 ) ;
return V_56 ;
}
enum V_53
F_85 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_88 = ( V_2 -> V_8 . V_140 & V_174 ) |
( F_26 ( V_62 ) & V_115 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_45 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
} else {
F_6 ( L_46 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_185 << V_183 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_140 ) ;
F_46 ( V_62 , V_88 ) ;
F_45 ( 1 ) ;
return V_56 ;
}
enum V_53
F_86 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
#ifdef F_87
V_78 = F_34 ( V_2 , V_88 ) ;
if ( V_78 < 0 ) {
F_30 ( V_2 , V_2 -> V_8 . V_140 ) ;
F_54 ( L_47 ,
V_52 , V_88 ) ;
F_88 ( V_2 ) ;
F_57 () ;
return V_60 ;
}
#endif
V_56 = F_89 ( V_54 , V_90 , V_75 , V_2 ) ;
return V_56 ;
}
enum V_53
F_89 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
unsigned long V_88 = ( V_2 -> V_8 . V_140 & V_174 ) |
( F_26 ( V_62 ) & V_115 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_48 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
} else {
F_6 ( L_49 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_171 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) , ( V_186 << V_183 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_140 ) ;
F_46 ( V_62 , V_88 ) ;
F_45 ( 1 ) ;
return V_56 ;
}
enum V_53
F_90 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
}
V_8 -> V_59 = V_171 + 0x180 ;
F_82 ( V_62 , ( 0xff ) ,
( V_187 << V_183 ) ) ;
F_82 ( V_62 , ( V_188 ) , ( 0x1 << V_189 ) ) ;
return V_56 ;
}
enum V_53
F_91 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_50 , V_8 -> V_59 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_190 << V_183 ) ) ;
V_8 -> V_59 = V_171 + 0x180 ;
} else {
F_54 ( L_51 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_92 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_52 , V_8 -> V_59 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_191 << V_183 ) ) ;
V_8 -> V_59 = V_171 + 0x180 ;
} else {
F_4 ( L_53 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_93 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
unsigned long V_96 ;
V_14 V_89 ;
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
if ( V_54 & V_58 )
V_90 += 1 ;
V_89 = F_2 ( V_90 , V_2 ) ;
if ( V_89 == V_11 ) {
F_4 ( L_54 , V_52 , V_90 ) ;
return V_60 ;
}
if ( ( V_89 & V_192 ) == V_193 && ( V_89 & V_194 ) == V_195 ) {
int V_196 = ! F_94 ( V_2 ) ;
int V_22 = ( V_89 & V_197 ) >> 11 ;
int V_26 = ( V_89 & V_198 ) >> 16 ;
if ( V_196 && ! ( F_95 ( V_62 ) & F_96 ( V_22 ) ) ) {
F_6 ( L_55 ,
V_22 , V_90 ) ;
goto V_199;
}
switch ( V_22 ) {
case 0 :
V_8 -> V_21 [ V_26 ] = 0 ;
break;
case 1 :
V_8 -> V_21 [ V_26 ] = F_97 ( V_200 . V_201 . V_202 ,
V_200 . V_203 . V_202 ) ;
break;
case 2 :
F_4 ( L_56 ) ;
V_8 -> V_21 [ V_26 ] = F_98 ( V_62 ) ;
break;
case 3 :
switch ( V_200 . V_204 ) {
case V_205 :
case V_206 :
V_8 -> V_21 [ V_26 ] = 1 ;
break;
default:
V_8 -> V_21 [ V_26 ] = 2 ;
}
break;
case 29 :
V_8 -> V_21 [ V_26 ] = F_99 ( V_62 ) ;
break;
default:
F_6 ( L_57 , V_22 , V_90 ) ;
goto V_199;
}
} else {
F_6 ( L_58 , V_90 , V_89 ) ;
goto V_199;
}
return V_57 ;
V_199:
V_2 -> V_8 . V_59 = V_96 ;
return F_91 ( V_54 , V_90 , V_75 , V_2 ) ;
}
enum V_53
F_100 ( struct V_1 * V_2 , struct V_91 * V_75 )
{
unsigned long * V_207 = & V_2 -> V_8 . V_21 [ V_2 -> V_8 . V_151 ] ;
enum V_53 V_56 = V_57 ;
unsigned long V_96 ;
if ( V_75 -> V_135 . V_137 > sizeof( * V_207 ) ) {
F_4 ( L_59 , V_75 -> V_135 . V_137 ) ;
V_56 = V_60 ;
goto V_117;
}
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_2 -> V_8 . V_150 ) ;
if ( V_56 == V_60 )
return V_56 ;
switch ( V_75 -> V_135 . V_137 ) {
case 4 :
* V_207 = * ( T_1 * ) V_75 -> V_135 . V_134 ;
break;
case 2 :
if ( V_2 -> V_143 == 2 )
* V_207 = * ( V_208 * ) V_75 -> V_135 . V_134 ;
else
* V_207 = * ( V_208 * ) V_75 -> V_135 . V_134 ;
break;
case 1 :
if ( V_2 -> V_143 == 2 )
* V_207 = * ( V_209 * ) V_75 -> V_135 . V_134 ;
else
* V_207 = * ( V_145 * ) V_75 -> V_135 . V_134 ;
break;
}
if ( V_2 -> V_8 . V_150 & V_58 )
F_6
( L_60 ,
V_2 -> V_8 . V_59 , V_75 -> V_135 . V_137 , V_2 -> V_8 . V_151 , * V_207 ,
V_2 -> V_143 ) ;
V_117:
return V_56 ;
}
static enum V_53
F_101 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
V_14 V_210 = ( V_54 >> V_183 ) & 0x1f ;
struct V_61 * V_62 = V_2 -> V_8 . V_62 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_210 << V_183 ) ) ;
V_8 -> V_59 = V_171 + 0x180 ;
F_83 ( V_62 , V_2 -> V_8 . V_140 ) ;
F_6 ( L_61 ,
V_210 , F_15 ( V_62 ) ,
F_102 ( V_62 ) ) ;
} else {
F_4 ( L_62 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_103 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_210 = ( V_54 >> V_183 ) & 0x1f ;
unsigned long V_211 = V_2 -> V_8 . V_140 ;
int V_196 = ! F_94 ( V_2 ) ;
if ( V_196 ) {
switch ( V_210 ) {
case V_212 :
case V_182 :
case V_191 :
case V_190 :
break;
case V_187 :
if ( ( ( V_54 & V_188 ) >> V_189 ) == 0 )
V_56 = V_213 ;
break;
case V_186 :
break;
case V_184 :
if ( V_211 >= ( unsigned long ) V_171 ) {
F_4 ( L_63 , V_52 ,
V_211 ) ;
V_54 &= ~ 0xff ;
V_54 |= ( V_214 << V_183 ) ;
V_56 = V_213 ;
}
break;
case V_185 :
if ( V_211 >= ( unsigned long ) V_171 ) {
F_4 ( L_64 , V_52 ,
V_211 ) ;
V_54 &= ~ 0xff ;
V_54 |= ( V_215 << V_183 ) ;
V_56 = V_213 ;
}
break;
case V_215 :
F_4 ( L_65 , V_52 ,
V_211 ) ;
if ( ( V_211 & V_158 ) == V_216 ) {
V_54 &= ~ 0xff ;
V_54 |= ( V_185 << V_183 ) ;
}
V_56 = V_213 ;
break;
case V_214 :
F_4 ( L_66 , V_52 ,
V_211 ) ;
if ( ( V_211 & V_158 ) == V_216 ) {
V_54 &= ~ 0xff ;
V_54 |= ( V_184 << V_183 ) ;
}
V_56 = V_213 ;
break;
default:
V_56 = V_213 ;
break;
}
}
if ( V_56 == V_213 ) {
F_101 ( V_54 , V_90 , V_75 , V_2 ) ;
}
return V_56 ;
}
enum V_53
F_104 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_210 = ( V_54 >> V_183 ) & 0x1f ;
unsigned long V_157 = V_2 -> V_8 . V_140 ;
int V_78 ;
F_6 ( L_67 ,
V_2 -> V_8 . V_140 , V_2 -> V_8 . V_175 ) ;
V_78 = F_34 ( V_2 ,
( V_157 & V_174 ) |
( F_26
( V_2 -> V_8 . V_62 ) & V_115 ) ) ;
if ( V_78 < 0 ) {
if ( V_210 == V_184 ) {
V_56 = F_69 ( V_54 , V_90 , V_75 , V_2 ) ;
} else if ( V_210 == V_185 ) {
V_56 = F_84 ( V_54 , V_90 , V_75 , V_2 ) ;
} else {
F_4 ( L_68 , V_52 , V_210 ) ;
V_56 = V_60 ;
}
} else {
struct V_79 * V_80 = & V_2 -> V_8 . V_82 [ V_78 ] ;
if ( ! F_71 ( * V_80 , V_157 ) ) {
if ( V_210 == V_184 ) {
V_56 = F_72 ( V_54 , V_90 , V_75 ,
V_2 ) ;
} else if ( V_210 == V_185 ) {
V_56 = F_85 ( V_54 , V_90 , V_75 ,
V_2 ) ;
} else {
F_4 ( L_68 , V_52 ,
V_210 ) ;
V_56 = V_60 ;
}
} else {
#ifdef F_87
F_6
( L_69 ,
V_80 -> V_83 , V_80 -> V_85 , V_80 -> V_86 ) ;
#endif
F_73 ( V_2 , V_80 , NULL ,
NULL ) ;
}
}
return V_56 ;
}
