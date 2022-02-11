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
if ( V_22 > V_97 ) {
F_4 ( L_14 , V_22 ) ;
V_56 = V_60 ;
goto V_98;
}
if ( V_94 ) {
V_95 = ( V_89 ) & 0xff ;
switch ( V_95 ) {
case V_99 :
V_56 = F_23 ( V_2 ) ;
break;
case V_100 :
V_56 = F_25 ( V_2 ) ;
break;
case V_101 :
V_56 = F_31 ( V_2 ) ;
break;
case V_102 :
V_56 = F_33 ( V_2 ) ;
break;
case V_103 :
F_4 ( L_15 ) ;
break;
case V_104 :
V_56 = F_13 ( V_2 ) ;
goto V_105;
break;
case V_106 :
V_56 = F_18 ( V_2 ) ;
break;
}
} else {
switch ( V_92 ) {
case V_107 :
#ifdef F_37
V_62 -> V_69 [ V_22 ] [ V_93 ] ++ ;
#endif
if ( ( V_22 == V_108 ) && ( V_93 == 0 ) ) {
V_2 -> V_8 . V_21 [ V_26 ] = ( F_38 () >> 2 ) ;
} else if ( ( V_22 == V_109 ) && ( V_93 == 0 ) ) {
V_2 -> V_8 . V_21 [ V_26 ] = 0x0 ;
#ifdef F_39
F_40 ( V_89 , V_90 , V_2 ) ;
#endif
}
else {
V_2 -> V_8 . V_21 [ V_26 ] = V_62 -> V_110 [ V_22 ] [ V_93 ] ;
#ifdef F_39
F_40 ( V_89 , V_90 , V_2 ) ;
#endif
}
F_6
( L_16 ,
V_59 , V_22 , V_93 , V_26 , V_2 -> V_8 . V_21 [ V_26 ] ) ;
break;
case V_111 :
V_2 -> V_8 . V_21 [ V_26 ] = V_62 -> V_110 [ V_22 ] [ V_93 ] ;
break;
case V_112 :
#ifdef F_37
V_62 -> V_69 [ V_22 ] [ V_93 ] ++ ;
#endif
if ( ( V_22 == V_113 )
&& ( V_2 -> V_8 . V_21 [ V_26 ] >=
V_81 ) ) {
F_4 ( L_17 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_56 = V_60 ;
break;
}
#define F_41 0xff
if ( ( V_22 == V_114 ) && ( V_93 == 1 ) ) {
F_42 ( V_62 ,
~ ( F_41 ) ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
F_4 ( L_18 ,
F_43 ( V_62 ) ) ;
} else if ( V_22 == V_115 && V_93 == 0 ) {
V_14 V_116 =
V_2 -> V_8 . V_21 [ V_26 ] & V_117 ;
if ( ( F_44 ( V_2 -> V_8 . V_21 [ V_26 ] ) != V_118 )
&&
( ( F_26 ( V_62 ) &
V_117 ) != V_116 ) ) {
F_6
( L_19 ,
F_26 ( V_62 ) &
V_117 ,
V_2 -> V_8 . V_21 [ V_26 ] & V_117 ) ;
F_45 ( 1 ) ;
}
F_46 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
}
else if ( ( V_22 == V_108 ) && ( V_93 == 0 ) ) {
goto V_98;
} else if ( ( V_22 == V_119 ) && ( V_93 == 0 ) ) {
F_6 ( L_20 ,
V_59 , F_47 ( V_62 ) ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_120 -> V_121 ( V_2 ) ;
F_48 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
} else if ( ( V_22 == V_122 ) && ( V_93 == 0 ) ) {
F_49 ( V_62 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
F_16 ( V_62 ,
( V_123 | V_124 ) ) ;
#ifdef F_39
F_50 ( V_89 , V_90 , V_2 ) ;
#endif
} else {
V_62 -> V_110 [ V_22 ] [ V_93 ] = V_2 -> V_8 . V_21 [ V_26 ] ;
#ifdef F_39
F_50 ( V_89 , V_90 , V_2 ) ;
#endif
}
F_6 ( L_21 , V_59 ,
V_22 , V_93 , V_62 -> V_110 [ V_22 ] [ V_93 ] ) ;
break;
case V_125 :
F_4
( L_22 ,
V_2 -> V_8 . V_59 , V_26 , V_22 , V_93 ) ;
V_56 = V_60 ;
break;
case V_126 :
#ifdef F_51
V_62 -> V_69 [ V_122 ] [ 0 ] ++ ;
#endif
if ( V_26 != 0 ) {
V_2 -> V_8 . V_21 [ V_26 ] =
F_14 ( V_62 ) ;
}
if ( V_89 & 0x20 ) {
F_6 ( L_23 ,
V_2 -> V_8 . V_59 ) ;
F_52 ( V_62 , V_127 ) ;
} else {
F_6 ( L_24 ,
V_2 -> V_8 . V_59 ) ;
F_16 ( V_62 , V_127 ) ;
}
break;
case V_128 :
{
V_14 V_129 =
V_62 -> V_110 [ V_122 ] [ 2 ] & 0xf ;
V_14 V_130 =
( V_62 -> V_110 [ V_122 ] [ 2 ] >> 6 ) & 0xf ;
if ( V_129 || V_130 ) {
V_56 = V_60 ;
break;
}
F_6 ( L_25 , V_130 , V_22 ,
V_2 -> V_8 . V_21 [ V_26 ] ) ;
V_2 -> V_8 . V_21 [ V_22 ] = V_2 -> V_8 . V_21 [ V_26 ] ;
}
break;
default:
F_4
( L_26 ,
V_2 -> V_8 . V_59 , V_92 ) ;
V_56 = V_60 ;
break;
}
}
V_98:
if ( V_56 == V_60 ) {
V_2 -> V_8 . V_59 = V_96 ;
}
V_105:
return V_56 ;
}
enum V_53
F_53 ( V_14 V_89 , V_14 V_54 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_131 ;
T_1 V_95 , V_132 , V_26 , V_133 ;
V_14 V_134 ;
void * V_135 = V_75 -> V_136 . V_135 ;
unsigned long V_96 ;
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
V_26 = ( V_89 >> 16 ) & 0x1f ;
V_132 = ( V_89 >> 21 ) & 0x1f ;
V_133 = V_89 & 0xffff ;
V_95 = ( V_89 >> 26 ) & 0x3f ;
switch ( V_95 ) {
case V_137 :
V_134 = 1 ;
if ( V_134 > sizeof( V_75 -> V_136 . V_135 ) ) {
F_54 ( L_27 , V_52 ,
V_75 -> V_136 . V_138 ) ;
}
V_75 -> V_136 . V_139 =
V_120 -> V_140 ( V_2 -> V_8 .
V_141 ) ;
if ( V_75 -> V_136 . V_139 == V_142 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_138 = V_134 ;
V_75 -> V_136 . V_143 = 1 ;
V_2 -> V_144 = 1 ;
V_2 -> V_145 = 1 ;
* ( V_146 * ) V_135 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_28 ,
V_2 -> V_8 . V_141 , V_2 -> V_8 . V_21 [ V_26 ] ,
* ( V_147 * ) V_135 ) ;
break;
case V_148 :
V_134 = 4 ;
if ( V_134 > sizeof( V_75 -> V_136 . V_135 ) ) {
F_54 ( L_27 , V_52 ,
V_75 -> V_136 . V_138 ) ;
}
V_75 -> V_136 . V_139 =
V_120 -> V_140 ( V_2 -> V_8 .
V_141 ) ;
if ( V_75 -> V_136 . V_139 == V_142 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_138 = V_134 ;
V_75 -> V_136 . V_143 = 1 ;
V_2 -> V_144 = 1 ;
V_2 -> V_145 = 1 ;
* ( V_14 * ) V_135 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_29 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_141 ,
V_2 -> V_8 . V_21 [ V_26 ] , * ( V_14 * ) V_135 ) ;
break;
case V_149 :
V_134 = 2 ;
if ( V_134 > sizeof( V_75 -> V_136 . V_135 ) ) {
F_54 ( L_27 , V_52 ,
V_75 -> V_136 . V_138 ) ;
}
V_75 -> V_136 . V_139 =
V_120 -> V_140 ( V_2 -> V_8 .
V_141 ) ;
if ( V_75 -> V_136 . V_139 == V_142 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_138 = V_134 ;
V_75 -> V_136 . V_143 = 1 ;
V_2 -> V_144 = 1 ;
V_2 -> V_145 = 1 ;
* ( V_150 * ) V_135 = V_2 -> V_8 . V_21 [ V_26 ] ;
F_6 ( L_30 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_141 ,
V_2 -> V_8 . V_21 [ V_26 ] , * ( V_14 * ) V_135 ) ;
break;
default:
F_4 ( L_31 ) ;
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
enum V_53 V_56 = V_131 ;
T_1 V_95 , V_132 , V_26 , V_133 ;
V_14 V_134 ;
V_26 = ( V_89 >> 16 ) & 0x1f ;
V_132 = ( V_89 >> 21 ) & 0x1f ;
V_133 = V_89 & 0xffff ;
V_95 = ( V_89 >> 26 ) & 0x3f ;
V_2 -> V_8 . V_151 = V_54 ;
V_2 -> V_8 . V_152 = V_26 ;
switch ( V_95 ) {
case V_153 :
V_134 = 4 ;
if ( V_134 > sizeof( V_75 -> V_136 . V_135 ) ) {
F_54 ( L_27 , V_52 ,
V_75 -> V_136 . V_138 ) ;
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_139 =
V_120 -> V_140 ( V_2 -> V_8 .
V_141 ) ;
if ( V_75 -> V_136 . V_139 == V_142 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_138 = V_134 ;
V_75 -> V_136 . V_143 = 0 ;
V_2 -> V_144 = 1 ;
V_2 -> V_145 = 0 ;
break;
case V_154 :
case V_155 :
V_134 = 2 ;
if ( V_134 > sizeof( V_75 -> V_136 . V_135 ) ) {
F_54 ( L_27 , V_52 ,
V_75 -> V_136 . V_138 ) ;
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_139 =
V_120 -> V_140 ( V_2 -> V_8 .
V_141 ) ;
if ( V_75 -> V_136 . V_139 == V_142 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_138 = V_134 ;
V_75 -> V_136 . V_143 = 0 ;
V_2 -> V_144 = 1 ;
V_2 -> V_145 = 0 ;
if ( V_95 == V_154 )
V_2 -> V_144 = 2 ;
else
V_2 -> V_144 = 1 ;
break;
case V_156 :
case V_157 :
V_134 = 1 ;
if ( V_134 > sizeof( V_75 -> V_136 . V_135 ) ) {
F_54 ( L_27 , V_52 ,
V_75 -> V_136 . V_138 ) ;
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_139 =
V_120 -> V_140 ( V_2 -> V_8 .
V_141 ) ;
if ( V_75 -> V_136 . V_139 == V_142 ) {
V_56 = V_60 ;
break;
}
V_75 -> V_136 . V_138 = V_134 ;
V_75 -> V_136 . V_143 = 0 ;
V_2 -> V_145 = 0 ;
if ( V_95 == V_157 )
V_2 -> V_144 = 2 ;
else
V_2 -> V_144 = 1 ;
break;
default:
F_4 ( L_32 ) ;
V_56 = V_60 ;
break;
}
return V_56 ;
}
int F_56 ( unsigned long V_158 , struct V_1 * V_2 )
{
unsigned long V_133 = ( V_158 & ~ V_159 ) ;
struct V_160 * V_160 = V_2 -> V_160 ;
unsigned long V_161 ;
T_2 V_162 ;
T_3 V_163 ;
V_162 = V_158 >> V_164 ;
if ( V_162 >= V_160 -> V_8 . V_165 ) {
F_4 ( L_33 , V_52 , V_162 ) ;
F_57 () ;
F_58 ( V_2 ) ;
return - 1 ;
}
V_163 = V_160 -> V_8 . V_166 [ V_162 ] ;
V_161 = ( V_163 << V_164 ) | V_133 ;
F_4 ( L_34 , V_52 , V_158 , F_59 ( V_161 ) ) ;
F_60 ( F_59 ( V_161 ) , 32 ) ;
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
T_1 V_133 , V_167 , V_168 , V_95 , V_132 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
unsigned long V_158 ;
unsigned long V_96 ;
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_54 ) ;
if ( V_56 == V_60 )
return V_56 ;
V_132 = ( V_89 >> 21 ) & 0x1f ;
V_168 = ( V_89 >> 16 ) & 0x1f ;
V_133 = V_89 & 0xffff ;
V_167 = ( V_89 >> 16 ) & 0x3 ;
V_95 = ( V_89 >> 18 ) & 0x7 ;
V_158 = V_8 -> V_21 [ V_132 ] + V_133 ;
F_6 ( L_35 ,
V_167 , V_95 , V_132 , V_8 -> V_21 [ V_132 ] , V_133 ) ;
if ( V_95 == V_169 ) {
F_6
( L_36 ,
V_2 -> V_8 . V_59 , V_2 -> V_8 . V_21 [ 31 ] , V_167 , V_95 , V_132 ,
V_8 -> V_21 [ V_132 ] , V_133 ) ;
if ( V_167 == V_170 )
F_62 () ;
else if ( V_167 == V_171 )
F_63 () ;
else {
F_4 ( L_37 ,
V_52 ) ;
return V_60 ;
}
#ifdef F_39
F_64 ( V_89 , V_90 , V_2 ) ;
#endif
goto V_98;
}
F_65 () ;
if ( F_66 ( V_158 ) == V_172 ) {
if ( F_67 ( V_2 , V_158 ) < 0 ) {
F_68 ( V_158 , V_2 ) ;
}
} else if ( ( F_66 ( V_158 ) < V_172 ) ||
F_66 ( V_158 ) == V_173 ) {
int V_78 ;
if ( F_67 ( V_2 , V_158 ) >= 0 ) {
goto V_174;
}
V_78 = F_34 ( V_2 , ( V_158 & V_175 ) |
( F_26
( V_62 ) & V_117 ) ) ;
if ( V_78 < 0 ) {
V_2 -> V_8 . V_176 = ( V_158 & V_175 ) ;
V_2 -> V_8 . V_141 = V_158 ;
V_56 = F_69 ( V_54 , NULL , V_75 ,
V_2 ) ;
F_70 () ;
goto V_105;
} else {
struct V_79 * V_80 = & V_2 -> V_8 . V_82 [ V_78 ] ;
if ( ! F_71 ( * V_80 , V_158 ) ) {
V_56 = F_72 ( V_54 , NULL ,
V_75 , V_2 ) ;
F_70 () ;
goto V_105;
} else {
F_73 ( V_2 , V_80 ,
NULL ,
NULL ) ;
}
}
} else {
F_4
( L_38 ,
V_167 , V_95 , V_132 , V_8 -> V_21 [ V_132 ] , V_133 ) ;
V_56 = V_60 ;
F_70 () ;
goto V_105;
}
V_174:
if ( V_167 == V_170
&& ( V_95 == V_177
|| V_95 == V_178 ) ) {
F_74 ( V_158 ) ;
#ifdef F_39
F_75 ( V_89 , V_90 , V_2 ) ;
#endif
} else if ( V_95 == V_178 && V_167 == V_171 ) {
F_74 ( V_158 ) ;
F_76 ( V_158 ) ;
#ifdef F_39
F_75 ( V_89 , V_90 , V_2 ) ;
#endif
} else {
F_4
( L_39 ,
V_167 , V_95 , V_132 , V_8 -> V_21 [ V_132 ] , V_133 ) ;
V_56 = V_60 ;
F_70 () ;
goto V_105;
}
F_70 () ;
V_105:
V_2 -> V_8 . V_59 = V_96 ;
V_98:
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
case V_179 :
V_56 = F_36 ( V_89 , V_90 , V_54 , V_75 , V_2 ) ;
break;
case V_137 :
case V_149 :
case V_148 :
V_56 = F_53 ( V_89 , V_54 , V_75 , V_2 ) ;
break;
case V_157 :
case V_156 :
case V_155 :
case V_154 :
case V_153 :
V_56 = F_55 ( V_89 , V_54 , V_75 , V_2 ) ;
break;
case V_180 :
++ V_2 -> V_69 . V_181 ;
F_19 ( V_2 , V_182 ) ;
V_56 = F_61 ( V_89 , V_90 , V_54 , V_75 , V_2 ) ;
break;
default:
F_4 ( L_40 , V_90 ,
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
F_6 ( L_41 , V_8 -> V_59 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_183 << V_184 ) ) ;
V_8 -> V_59 = V_172 + 0x180 ;
} else {
F_4 ( L_42 ) ;
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
unsigned long V_88 = ( V_2 -> V_8 . V_141 & V_175 ) |
( F_26 ( V_62 ) & V_117 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_43 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x0 ;
} else {
F_6 ( L_44 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_185 << V_184 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_141 ) ;
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
( V_2 -> V_8 . V_141 & V_175 ) |
( F_26 ( V_62 ) & V_117 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_45 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
} else {
F_6 ( L_44 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_185 << V_184 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_141 ) ;
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
unsigned long V_88 = ( V_2 -> V_8 . V_141 & V_175 ) |
( F_26 ( V_62 ) & V_117 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_46 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x0 ;
} else {
F_6 ( L_47 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_186 << V_184 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_141 ) ;
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
unsigned long V_88 = ( V_2 -> V_8 . V_141 & V_175 ) |
( F_26 ( V_62 ) & V_117 ) ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_46 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
} else {
F_6 ( L_47 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) ,
( V_186 << V_184 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_141 ) ;
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
F_30 ( V_2 , V_2 -> V_8 . V_141 ) ;
F_54 ( L_48 ,
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
unsigned long V_88 = ( V_2 -> V_8 . V_141 & V_175 ) |
( F_26 ( V_62 ) & V_117 ) ;
struct V_7 * V_8 = & V_2 -> V_8 ;
enum V_53 V_56 = V_57 ;
if ( ( F_14 ( V_62 ) & V_66 ) == 0 ) {
F_79 ( V_62 , V_8 -> V_59 ) ;
F_52 ( V_62 , V_66 ) ;
if ( V_54 & V_58 )
F_80 ( V_62 , V_58 ) ;
else
F_81 ( V_62 , V_58 ) ;
F_6 ( L_49 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
} else {
F_6 ( L_50 ,
V_8 -> V_59 ) ;
V_8 -> V_59 = V_172 + 0x180 ;
}
F_82 ( V_62 , ( 0xff ) , ( V_187 << V_184 ) ) ;
F_83 ( V_62 , V_2 -> V_8 . V_141 ) ;
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
V_8 -> V_59 = V_172 + 0x180 ;
F_82 ( V_62 , ( 0xff ) ,
( V_188 << V_184 ) ) ;
F_82 ( V_62 , ( V_189 ) , ( 0x1 << V_190 ) ) ;
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
F_6 ( L_51 , V_8 -> V_59 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_191 << V_184 ) ) ;
V_8 -> V_59 = V_172 + 0x180 ;
} else {
F_54 ( L_52 ) ;
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
F_6 ( L_53 , V_8 -> V_59 ) ;
F_82 ( V_62 , ( 0xff ) ,
( V_192 << V_184 ) ) ;
V_8 -> V_59 = V_172 + 0x180 ;
} else {
F_4 ( L_54 ) ;
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
F_4 ( L_55 , V_52 , V_90 ) ;
return V_60 ;
}
if ( ( V_89 & V_193 ) == V_194 && ( V_89 & V_195 ) == V_196 ) {
int V_22 = ( V_89 & V_197 ) >> 11 ;
int V_26 = ( V_89 & V_198 ) >> 16 ;
switch ( V_22 ) {
case 0 :
V_8 -> V_21 [ V_26 ] = 0 ;
break;
case 1 :
V_8 -> V_21 [ V_26 ] = F_94 ( V_199 . V_200 . V_201 ,
V_199 . V_202 . V_201 ) ;
break;
case 2 :
F_4 ( L_56 ) ;
V_8 -> V_21 [ V_26 ] = F_95 ( V_62 ) ;
break;
case 3 :
switch ( V_199 . V_203 ) {
case V_204 :
case V_205 :
V_8 -> V_21 [ V_26 ] = 1 ;
break;
default:
V_8 -> V_21 [ V_26 ] = 2 ;
}
break;
case 29 :
#if 1
V_8 -> V_21 [ V_26 ] = F_96 ( V_62 ) ;
#else
V_56 = F_91 ( V_54 , V_90 , V_75 , V_2 ) ;
#endif
break;
default:
F_4 ( L_57 ) ;
V_56 = V_60 ;
break;
}
} else {
F_4 ( L_58 , V_90 , V_89 ) ;
V_56 = V_60 ;
}
if ( V_56 == V_60 ) {
V_2 -> V_8 . V_59 = V_96 ;
}
return V_56 ;
}
enum V_53
F_97 ( struct V_1 * V_2 , struct V_91 * V_75 )
{
unsigned long * V_206 = & V_2 -> V_8 . V_21 [ V_2 -> V_8 . V_152 ] ;
enum V_53 V_56 = V_57 ;
unsigned long V_96 ;
if ( V_75 -> V_136 . V_138 > sizeof( * V_206 ) ) {
F_4 ( L_59 , V_75 -> V_136 . V_138 ) ;
V_56 = V_60 ;
goto V_98;
}
V_96 = V_2 -> V_8 . V_59 ;
V_56 = F_5 ( V_2 , V_2 -> V_8 . V_151 ) ;
if ( V_56 == V_60 )
return V_56 ;
switch ( V_75 -> V_136 . V_138 ) {
case 4 :
* V_206 = * ( T_1 * ) V_75 -> V_136 . V_135 ;
break;
case 2 :
if ( V_2 -> V_144 == 2 )
* V_206 = * ( V_207 * ) V_75 -> V_136 . V_135 ;
else
* V_206 = * ( V_207 * ) V_75 -> V_136 . V_135 ;
break;
case 1 :
if ( V_2 -> V_144 == 2 )
* V_206 = * ( V_208 * ) V_75 -> V_136 . V_135 ;
else
* V_206 = * ( V_146 * ) V_75 -> V_136 . V_135 ;
break;
}
if ( V_2 -> V_8 . V_151 & V_58 )
F_6
( L_60 ,
V_2 -> V_8 . V_59 , V_75 -> V_136 . V_138 , V_2 -> V_8 . V_152 , * V_206 ,
V_2 -> V_144 ) ;
V_98:
return V_56 ;
}
static enum V_53
F_98 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
V_14 V_209 = ( V_54 >> V_184 ) & 0x1f ;
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
( V_209 << V_184 ) ) ;
V_8 -> V_59 = V_172 + 0x180 ;
F_83 ( V_62 , V_2 -> V_8 . V_141 ) ;
F_6 ( L_61 ,
V_209 , F_15 ( V_62 ) ,
F_99 ( V_62 ) ) ;
} else {
F_4 ( L_62 ) ;
V_56 = V_60 ;
}
return V_56 ;
}
enum V_53
F_100 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_209 = ( V_54 >> V_184 ) & 0x1f ;
unsigned long V_210 = V_2 -> V_8 . V_141 ;
int V_211 = ! F_101 ( V_2 ) ;
if ( V_211 ) {
switch ( V_209 ) {
case V_212 :
case V_183 :
case V_192 :
case V_191 :
break;
case V_188 :
if ( ( ( V_54 & V_189 ) >> V_190 ) == 0 )
V_56 = V_213 ;
break;
case V_187 :
break;
case V_185 :
if ( V_210 >= ( unsigned long ) V_172 ) {
F_4 ( L_63 , V_52 ,
V_210 ) ;
V_54 &= ~ 0xff ;
V_54 |= ( V_214 << V_184 ) ;
V_56 = V_213 ;
}
break;
case V_186 :
if ( V_210 >= ( unsigned long ) V_172 ) {
F_4 ( L_64 , V_52 ,
V_210 ) ;
V_54 &= ~ 0xff ;
V_54 |= ( V_215 << V_184 ) ;
V_56 = V_213 ;
}
break;
case V_215 :
F_4 ( L_65 , V_52 ,
V_210 ) ;
if ( ( V_210 & V_159 ) == V_216 ) {
V_54 &= ~ 0xff ;
V_54 |= ( V_186 << V_184 ) ;
}
V_56 = V_213 ;
break;
case V_214 :
F_4 ( L_66 , V_52 ,
V_210 ) ;
if ( ( V_210 & V_159 ) == V_216 ) {
V_54 &= ~ 0xff ;
V_54 |= ( V_185 << V_184 ) ;
}
V_56 = V_213 ;
break;
default:
V_56 = V_213 ;
break;
}
}
if ( V_56 == V_213 ) {
F_98 ( V_54 , V_90 , V_75 , V_2 ) ;
}
return V_56 ;
}
enum V_53
F_102 ( unsigned long V_54 , V_14 * V_90 ,
struct V_91 * V_75 , struct V_1 * V_2 )
{
enum V_53 V_56 = V_57 ;
V_14 V_209 = ( V_54 >> V_184 ) & 0x1f ;
unsigned long V_158 = V_2 -> V_8 . V_141 ;
int V_78 ;
F_6 ( L_67 ,
V_2 -> V_8 . V_141 , V_2 -> V_8 . V_176 ) ;
V_78 = F_34 ( V_2 ,
( V_158 & V_175 ) |
( F_26
( V_2 -> V_8 . V_62 ) & V_117 ) ) ;
if ( V_78 < 0 ) {
if ( V_209 == V_185 ) {
V_56 = F_69 ( V_54 , V_90 , V_75 , V_2 ) ;
} else if ( V_209 == V_186 ) {
V_56 = F_84 ( V_54 , V_90 , V_75 , V_2 ) ;
} else {
F_4 ( L_68 , V_52 , V_209 ) ;
V_56 = V_60 ;
}
} else {
struct V_79 * V_80 = & V_2 -> V_8 . V_82 [ V_78 ] ;
if ( ! F_71 ( * V_80 , V_158 ) ) {
if ( V_209 == V_185 ) {
V_56 = F_72 ( V_54 , V_90 , V_75 ,
V_2 ) ;
} else if ( V_209 == V_186 ) {
V_56 = F_85 ( V_54 , V_90 , V_75 ,
V_2 ) ;
} else {
F_4 ( L_68 , V_52 ,
V_209 ) ;
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
