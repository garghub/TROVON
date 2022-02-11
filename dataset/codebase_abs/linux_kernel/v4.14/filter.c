int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
if ( F_2 ( V_4 ) && ! F_3 ( V_2 , V_9 ) ) {
F_4 ( F_5 ( V_2 ) , V_10 ) ;
return - V_11 ;
}
V_6 = F_6 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_7 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
F_8 () ;
V_8 = F_9 ( V_2 -> V_7 ) ;
if ( V_8 ) {
struct V_1 * V_12 = V_4 -> V_2 ;
unsigned int V_13 ;
V_4 -> V_2 = V_2 ;
V_13 = F_10 ( V_8 -> V_14 , V_4 ) ;
V_4 -> V_2 = V_12 ;
V_6 = V_13 ? F_11 ( V_4 , F_12 ( V_5 , V_13 ) ) : - V_15 ;
}
F_13 () ;
return V_6 ;
}
static T_1 F_14 ( int V_16 , int V_17 , int V_18 ,
struct V_19 * V_20 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_16 ) {
case V_22 :
F_15 ( F_16 ( struct V_3 , V_23 ) != 4 ) ;
* V_21 ++ = F_17 ( V_24 , V_17 , V_18 ,
F_18 ( struct V_3 , V_23 ) ) ;
break;
case V_25 :
* V_21 ++ = F_17 ( V_26 , V_17 , V_18 , F_19 () ) ;
* V_21 ++ = F_20 ( V_27 , V_17 , V_28 ) ;
#ifdef F_21
* V_21 ++ = F_20 ( V_29 , V_17 , 5 ) ;
#endif
break;
case V_30 :
F_15 ( F_16 ( struct V_3 , V_31 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_17 , V_18 ,
F_18 ( struct V_3 , V_31 ) ) ;
break;
case V_33 :
case V_34 :
F_15 ( F_16 ( struct V_3 , V_35 ) != 2 ) ;
F_15 ( V_36 != 0x1000 ) ;
* V_21 ++ = F_17 ( V_32 , V_17 , V_18 ,
F_18 ( struct V_3 , V_35 ) ) ;
if ( V_16 == V_33 ) {
* V_21 ++ = F_20 ( V_27 , V_17 ,
~ V_36 ) ;
} else {
* V_21 ++ = F_20 ( V_29 , V_17 , 12 ) ;
* V_21 ++ = F_20 ( V_27 , V_17 , 1 ) ;
}
break;
}
return V_21 - V_20 ;
}
static bool F_22 ( struct V_37 * V_38 ,
struct V_19 * * V_39 )
{
struct V_19 * V_21 = * V_39 ;
T_1 V_40 ;
switch ( V_38 -> V_41 ) {
case V_42 + V_43 :
F_15 ( F_16 ( struct V_3 , V_44 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_45 , V_46 ,
F_18 ( struct V_3 , V_44 ) ) ;
* V_21 = F_23 ( V_47 , V_45 , 16 ) ;
break;
case V_42 + V_25 :
V_40 = F_14 ( V_25 , V_45 , V_46 , V_21 ) ;
V_21 += V_40 - 1 ;
break;
case V_42 + V_48 :
case V_42 + V_49 :
F_15 ( F_16 ( struct V_50 , V_51 ) != 4 ) ;
F_15 ( F_16 ( struct V_50 , type ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_53 , V_46 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_25 ( V_54 , V_53 , 0 , 1 ) ;
* V_21 ++ = F_26 () ;
if ( V_38 -> V_41 == V_42 + V_48 )
* V_21 = F_17 ( V_24 , V_45 , V_53 ,
F_18 ( struct V_50 , V_51 ) ) ;
else
* V_21 = F_17 ( V_32 , V_45 , V_53 ,
F_18 ( struct V_50 , type ) ) ;
break;
case V_42 + V_22 :
V_40 = F_14 ( V_22 , V_45 , V_46 , V_21 ) ;
V_21 += V_40 - 1 ;
break;
case V_42 + V_55 :
F_15 ( F_16 ( struct V_3 , V_56 ) != 4 ) ;
* V_21 = F_17 ( V_24 , V_45 , V_46 ,
F_18 ( struct V_3 , V_56 ) ) ;
break;
case V_42 + V_30 :
V_40 = F_14 ( V_30 , V_45 , V_46 , V_21 ) ;
V_21 += V_40 - 1 ;
break;
case V_42 + V_33 :
V_40 = F_14 ( V_33 ,
V_45 , V_46 , V_21 ) ;
V_21 += V_40 - 1 ;
break;
case V_42 + V_34 :
V_40 = F_14 ( V_34 ,
V_45 , V_46 , V_21 ) ;
V_21 += V_40 - 1 ;
break;
case V_42 + V_57 :
F_15 ( F_16 ( struct V_3 , V_58 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_45 , V_46 ,
F_18 ( struct V_3 , V_58 ) ) ;
* V_21 = F_23 ( V_47 , V_45 , 16 ) ;
break;
case V_42 + V_59 :
case V_42 + V_60 :
case V_42 + V_61 :
case V_42 + V_62 :
case V_42 + V_63 :
* V_21 ++ = F_27 ( V_64 , V_46 ) ;
* V_21 ++ = F_27 ( V_65 , V_45 ) ;
* V_21 ++ = F_27 ( V_66 , V_67 ) ;
switch ( V_38 -> V_41 ) {
case V_42 + V_59 :
* V_21 = F_28 ( V_68 ) ;
break;
case V_42 + V_60 :
* V_21 = F_28 ( V_69 ) ;
break;
case V_42 + V_61 :
* V_21 = F_28 ( V_70 ) ;
break;
case V_42 + V_62 :
* V_21 = F_28 ( V_71 ) ;
break;
case V_42 + V_63 :
* V_21 = F_28 ( V_72 ) ;
F_29 () ;
break;
}
break;
case V_42 + V_73 :
* V_21 = F_30 ( V_74 , V_45 , V_67 ) ;
break;
default:
F_31 ( F_32 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_39 = V_21 ;
return true ;
}
static int F_33 ( struct V_37 * V_14 , int V_75 ,
struct V_76 * V_77 , int * V_78 )
{
int V_79 = 0 , V_80 = 0 , V_81 , V_82 , V_83 ;
struct V_19 * V_84 , * V_85 = NULL ;
struct V_37 * V_38 ;
int * V_86 = NULL ;
T_2 V_87 ;
F_15 ( V_88 * sizeof( T_1 ) > V_89 ) ;
F_15 ( V_90 + 1 != V_91 ) ;
if ( V_75 <= 0 || V_75 > V_92 )
return - V_93 ;
if ( V_77 ) {
V_85 = V_77 -> V_94 ;
V_86 = F_34 ( V_75 , sizeof( * V_86 ) ,
V_95 | V_96 ) ;
if ( ! V_86 )
return - V_11 ;
}
V_97:
V_84 = V_85 ;
V_38 = V_14 ;
if ( V_77 ) {
* V_84 ++ = F_35 ( V_74 , V_45 , V_45 ) ;
* V_84 ++ = F_35 ( V_74 , V_67 , V_67 ) ;
* V_84 ++ = F_27 ( V_46 , V_64 ) ;
} else {
V_84 += 3 ;
}
for ( V_82 = 0 ; V_82 < V_75 ; V_38 ++ , V_82 ++ ) {
struct V_19 V_98 [ 6 ] = { } ;
struct V_19 * V_21 = V_98 ;
if ( V_86 )
V_86 [ V_82 ] = V_84 - V_85 ;
switch ( V_38 -> V_99 ) {
case V_100 | V_101 | V_102 :
case V_100 | V_101 | V_103 :
case V_100 | V_104 | V_102 :
case V_100 | V_104 | V_103 :
case V_100 | V_27 | V_102 :
case V_100 | V_27 | V_103 :
case V_100 | V_105 | V_102 :
case V_100 | V_105 | V_103 :
case V_100 | V_106 | V_102 :
case V_100 | V_106 | V_103 :
case V_100 | V_29 | V_102 :
case V_100 | V_29 | V_103 :
case V_100 | V_74 | V_102 :
case V_100 | V_74 | V_103 :
case V_100 | V_107 | V_102 :
case V_100 | V_107 | V_103 :
case V_100 | V_108 | V_102 :
case V_100 | V_108 | V_103 :
case V_100 | V_109 | V_102 :
case V_100 | V_109 | V_103 :
case V_100 | V_110 :
case V_111 | V_112 | V_24 :
case V_111 | V_112 | V_32 :
case V_111 | V_112 | V_26 :
case V_111 | V_113 | V_24 :
case V_111 | V_113 | V_32 :
case V_111 | V_113 | V_26 :
if ( F_36 ( V_38 -> V_99 ) == V_111 &&
F_37 ( V_38 -> V_99 ) == V_112 &&
F_22 ( V_38 , & V_21 ) )
break;
* V_21 = F_38 ( V_38 -> V_99 , V_45 , V_67 , 0 , V_38 -> V_41 ) ;
break;
#define F_39 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_114 | V_115 :
V_81 = V_82 + V_38 -> V_41 + 1 ;
V_21 -> V_99 = V_38 -> V_99 ;
F_39 ;
break;
case V_114 | V_116 | V_103 :
case V_114 | V_116 | V_102 :
case V_114 | V_117 | V_103 :
case V_114 | V_117 | V_102 :
case V_114 | V_118 | V_103 :
case V_114 | V_118 | V_102 :
case V_114 | V_119 | V_103 :
case V_114 | V_119 | V_102 :
if ( F_40 ( V_38 -> V_99 ) == V_103 && ( int ) V_38 -> V_41 < 0 ) {
* V_21 ++ = F_41 ( V_53 , V_38 -> V_41 ) ;
V_21 -> V_17 = V_45 ;
V_21 -> V_18 = V_53 ;
V_87 = V_102 ;
} else {
V_21 -> V_17 = V_45 ;
V_21 -> V_120 = V_38 -> V_41 ;
V_87 = F_40 ( V_38 -> V_99 ) ;
V_21 -> V_18 = V_87 == V_102 ? V_67 : 0 ;
}
if ( V_38 -> V_121 == 0 ) {
V_21 -> V_99 = V_114 | F_42 ( V_38 -> V_99 ) | V_87 ;
V_81 = V_82 + V_38 -> V_122 + 1 ;
F_39 ;
break;
}
if ( V_38 -> V_122 == 0 ) {
switch ( F_42 ( V_38 -> V_99 ) ) {
case V_116 :
V_21 -> V_99 = V_114 | V_54 | V_87 ;
break;
case V_118 :
V_21 -> V_99 = V_114 | V_123 | V_87 ;
break;
case V_119 :
V_21 -> V_99 = V_114 | V_124 | V_87 ;
break;
default:
goto V_125;
}
V_81 = V_82 + V_38 -> V_121 + 1 ;
F_39 ;
break;
}
V_125:
V_81 = V_82 + V_38 -> V_122 + 1 ;
V_21 -> V_99 = V_114 | F_42 ( V_38 -> V_99 ) | V_87 ;
F_39 ;
V_21 ++ ;
V_21 -> V_99 = V_114 | V_115 ;
V_81 = V_82 + V_38 -> V_121 + 1 ;
F_39 ;
break;
case V_126 | V_127 | V_26 :
* V_21 ++ = F_27 ( V_53 , V_45 ) ;
* V_21 ++ = F_43 ( V_26 , V_38 -> V_41 ) ;
* V_21 ++ = F_20 ( V_27 , V_45 , 0xf ) ;
* V_21 ++ = F_20 ( V_106 , V_45 , 2 ) ;
* V_21 ++ = F_27 ( V_67 , V_45 ) ;
* V_21 = F_27 ( V_45 , V_53 ) ;
break;
case V_128 | V_129 :
case V_128 | V_103 :
if ( F_44 ( V_38 -> V_99 ) == V_103 )
* V_21 ++ = F_45 ( V_103 , V_130 ,
0 , V_38 -> V_41 ) ;
* V_21 = F_26 () ;
break;
case V_131 :
case V_132 :
V_83 = V_38 -> V_41 * 4 + 4 ;
* V_21 = F_46 ( V_24 , V_90 , F_36 ( V_38 -> V_99 ) ==
V_131 ? V_45 : V_67 ,
- V_83 ) ;
if ( V_77 && V_77 -> V_133 -> V_134 < V_83 )
V_77 -> V_133 -> V_134 = V_83 ;
break;
case V_111 | V_135 :
case V_126 | V_135 :
V_83 = V_38 -> V_41 * 4 + 4 ;
* V_21 = F_17 ( V_24 , F_36 ( V_38 -> V_99 ) == V_111 ?
V_45 : V_67 , V_90 ,
- V_83 ) ;
break;
case V_111 | V_136 :
case V_126 | V_136 :
* V_21 = F_41 ( F_36 ( V_38 -> V_99 ) == V_111 ?
V_45 : V_67 , V_38 -> V_41 ) ;
break;
case V_137 | V_138 :
* V_21 = F_27 ( V_67 , V_45 ) ;
break;
case V_137 | V_139 :
* V_21 = F_27 ( V_45 , V_67 ) ;
break;
case V_111 | V_24 | V_140 :
case V_126 | V_24 | V_140 :
* V_21 = F_17 ( V_24 , F_36 ( V_38 -> V_99 ) == V_111 ?
V_45 : V_67 , V_46 ,
F_18 ( struct V_3 , V_75 ) ) ;
break;
case V_126 | V_112 | V_24 :
* V_21 = F_17 ( V_24 , V_45 , V_46 , V_38 -> V_41 ) ;
break;
default:
goto V_6;
}
V_21 ++ ;
if ( V_77 )
memcpy ( V_84 , V_98 ,
sizeof( * V_21 ) * ( V_21 - V_98 ) ) ;
V_84 += V_21 - V_98 ;
}
if ( ! V_77 ) {
* V_78 = V_84 - V_85 ;
return 0 ;
}
V_80 ++ ;
if ( V_79 != V_84 - V_85 ) {
V_79 = V_84 - V_85 ;
if ( V_80 > 2 )
goto V_6;
goto V_97;
}
F_47 ( V_86 ) ;
F_31 ( * V_78 != V_79 ) ;
return 0 ;
V_6:
F_47 ( V_86 ) ;
return - V_93 ;
}
static int F_48 ( const struct V_37 * V_8 , int V_141 )
{
T_3 * V_142 , V_143 = 0 ;
int V_144 , V_145 = 0 ;
F_15 ( V_88 > 16 ) ;
V_142 = F_49 ( V_141 , sizeof( * V_142 ) , V_95 ) ;
if ( ! V_142 )
return - V_11 ;
memset ( V_142 , 0xff , V_141 * sizeof( * V_142 ) ) ;
for ( V_144 = 0 ; V_144 < V_141 ; V_144 ++ ) {
V_143 &= V_142 [ V_144 ] ;
switch ( V_8 [ V_144 ] . V_99 ) {
case V_131 :
case V_132 :
V_143 |= ( 1 << V_8 [ V_144 ] . V_41 ) ;
break;
case V_111 | V_135 :
case V_126 | V_135 :
if ( ! ( V_143 & ( 1 << V_8 [ V_144 ] . V_41 ) ) ) {
V_145 = - V_93 ;
goto error;
}
break;
case V_114 | V_115 :
V_142 [ V_144 + 1 + V_8 [ V_144 ] . V_41 ] &= V_143 ;
V_143 = ~ 0 ;
break;
case V_114 | V_116 | V_103 :
case V_114 | V_116 | V_102 :
case V_114 | V_119 | V_103 :
case V_114 | V_119 | V_102 :
case V_114 | V_118 | V_103 :
case V_114 | V_118 | V_102 :
case V_114 | V_117 | V_103 :
case V_114 | V_117 | V_102 :
V_142 [ V_144 + 1 + V_8 [ V_144 ] . V_122 ] &= V_143 ;
V_142 [ V_144 + 1 + V_8 [ V_144 ] . V_121 ] &= V_143 ;
V_143 = ~ 0 ;
break;
}
}
error:
F_47 ( V_142 ) ;
return V_145 ;
}
static bool F_50 ( T_3 V_146 )
{
static const bool V_147 [] = {
[ V_100 | V_101 | V_103 ] = true ,
[ V_100 | V_101 | V_102 ] = true ,
[ V_100 | V_104 | V_103 ] = true ,
[ V_100 | V_104 | V_102 ] = true ,
[ V_100 | V_107 | V_103 ] = true ,
[ V_100 | V_107 | V_102 ] = true ,
[ V_100 | V_108 | V_103 ] = true ,
[ V_100 | V_108 | V_102 ] = true ,
[ V_100 | V_109 | V_103 ] = true ,
[ V_100 | V_109 | V_102 ] = true ,
[ V_100 | V_27 | V_103 ] = true ,
[ V_100 | V_27 | V_102 ] = true ,
[ V_100 | V_105 | V_103 ] = true ,
[ V_100 | V_105 | V_102 ] = true ,
[ V_100 | V_74 | V_103 ] = true ,
[ V_100 | V_74 | V_102 ] = true ,
[ V_100 | V_106 | V_103 ] = true ,
[ V_100 | V_106 | V_102 ] = true ,
[ V_100 | V_29 | V_103 ] = true ,
[ V_100 | V_29 | V_102 ] = true ,
[ V_100 | V_110 ] = true ,
[ V_111 | V_24 | V_112 ] = true ,
[ V_111 | V_32 | V_112 ] = true ,
[ V_111 | V_26 | V_112 ] = true ,
[ V_111 | V_24 | V_140 ] = true ,
[ V_111 | V_24 | V_113 ] = true ,
[ V_111 | V_32 | V_113 ] = true ,
[ V_111 | V_26 | V_113 ] = true ,
[ V_111 | V_136 ] = true ,
[ V_111 | V_135 ] = true ,
[ V_126 | V_24 | V_140 ] = true ,
[ V_126 | V_26 | V_127 ] = true ,
[ V_126 | V_136 ] = true ,
[ V_126 | V_135 ] = true ,
[ V_131 ] = true ,
[ V_132 ] = true ,
[ V_137 | V_138 ] = true ,
[ V_137 | V_139 ] = true ,
[ V_128 | V_103 ] = true ,
[ V_128 | V_129 ] = true ,
[ V_114 | V_115 ] = true ,
[ V_114 | V_116 | V_103 ] = true ,
[ V_114 | V_116 | V_102 ] = true ,
[ V_114 | V_119 | V_103 ] = true ,
[ V_114 | V_119 | V_102 ] = true ,
[ V_114 | V_118 | V_103 ] = true ,
[ V_114 | V_118 | V_102 ] = true ,
[ V_114 | V_117 | V_103 ] = true ,
[ V_114 | V_117 | V_102 ] = true ,
} ;
if ( V_146 >= F_51 ( V_147 ) )
return false ;
return V_147 [ V_146 ] ;
}
static bool F_52 ( const struct V_37 * V_8 ,
unsigned int V_141 )
{
if ( V_8 == NULL )
return false ;
if ( V_141 == 0 || V_141 > V_92 )
return false ;
return true ;
}
static int F_53 ( const struct V_37 * V_8 ,
unsigned int V_141 )
{
bool V_148 ;
int V_144 ;
for ( V_144 = 0 ; V_144 < V_141 ; V_144 ++ ) {
const struct V_37 * V_149 = & V_8 [ V_144 ] ;
if ( ! F_50 ( V_149 -> V_99 ) )
return - V_93 ;
switch ( V_149 -> V_99 ) {
case V_100 | V_108 | V_103 :
case V_100 | V_109 | V_103 :
if ( V_149 -> V_41 == 0 )
return - V_93 ;
break;
case V_100 | V_106 | V_103 :
case V_100 | V_29 | V_103 :
if ( V_149 -> V_41 >= 32 )
return - V_93 ;
break;
case V_111 | V_135 :
case V_126 | V_135 :
case V_131 :
case V_132 :
if ( V_149 -> V_41 >= V_88 )
return - V_93 ;
break;
case V_114 | V_115 :
if ( V_149 -> V_41 >= ( unsigned int ) ( V_141 - V_144 - 1 ) )
return - V_93 ;
break;
case V_114 | V_116 | V_103 :
case V_114 | V_116 | V_102 :
case V_114 | V_119 | V_103 :
case V_114 | V_119 | V_102 :
case V_114 | V_118 | V_103 :
case V_114 | V_118 | V_102 :
case V_114 | V_117 | V_103 :
case V_114 | V_117 | V_102 :
if ( V_144 + V_149 -> V_122 + 1 >= V_141 ||
V_144 + V_149 -> V_121 + 1 >= V_141 )
return - V_93 ;
break;
case V_111 | V_24 | V_112 :
case V_111 | V_32 | V_112 :
case V_111 | V_26 | V_112 :
V_148 = false ;
if ( F_54 ( V_149 ) & V_150 )
V_148 = true ;
if ( V_148 == false && V_149 -> V_41 >= V_42 )
return - V_93 ;
}
}
switch ( V_8 [ V_141 - 1 ] . V_99 ) {
case V_128 | V_103 :
case V_128 | V_129 :
return F_48 ( V_8 , V_141 ) ;
}
return - V_93 ;
}
static int F_55 ( struct V_76 * V_38 ,
const struct V_151 * V_152 )
{
unsigned int V_153 = F_56 ( V_152 ) ;
struct V_154 * V_155 ;
V_38 -> V_156 = F_57 ( sizeof( * V_155 ) , V_95 ) ;
if ( ! V_38 -> V_156 )
return - V_11 ;
V_155 = V_38 -> V_156 ;
V_155 -> V_75 = V_152 -> V_75 ;
V_155 -> V_8 = F_58 ( V_38 -> V_157 , V_153 ,
V_95 | V_96 ) ;
if ( ! V_155 -> V_8 ) {
F_47 ( V_38 -> V_156 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_59 ( struct V_76 * V_38 )
{
struct V_154 * V_152 = V_38 -> V_156 ;
if ( V_152 ) {
F_47 ( V_152 -> V_8 ) ;
F_47 ( V_152 ) ;
}
}
static void F_60 ( struct V_76 * V_14 )
{
if ( V_14 -> type == V_158 ) {
F_61 ( V_14 ) ;
} else {
F_59 ( V_14 ) ;
F_62 ( V_14 ) ;
}
}
static void F_63 ( struct V_7 * V_38 )
{
F_60 ( V_38 -> V_14 ) ;
F_47 ( V_38 ) ;
}
static void F_64 ( struct V_159 * V_160 )
{
struct V_7 * V_38 = F_65 ( V_160 , struct V_7 , V_160 ) ;
F_63 ( V_38 ) ;
}
static void F_66 ( struct V_7 * V_38 )
{
if ( F_67 ( & V_38 -> V_161 ) )
F_68 ( & V_38 -> V_160 , F_64 ) ;
}
void F_69 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
T_1 V_162 = F_70 ( V_38 -> V_14 -> V_75 ) ;
F_71 ( V_162 , & V_2 -> V_163 ) ;
F_66 ( V_38 ) ;
}
static bool F_72 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
T_1 V_162 = F_70 ( V_38 -> V_14 -> V_75 ) ;
if ( V_162 <= V_164 &&
F_73 ( & V_2 -> V_163 ) + V_162 < V_164 ) {
F_74 ( V_162 , & V_2 -> V_163 ) ;
return true ;
}
return false ;
}
bool F_75 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
if ( ! F_76 ( & V_38 -> V_161 ) )
return false ;
if ( ! F_72 ( V_2 , V_38 ) ) {
F_66 ( V_38 ) ;
return false ;
}
return true ;
}
static struct V_76 * F_77 ( struct V_76 * V_38 )
{
struct V_37 * V_165 ;
struct V_76 * V_166 ;
int V_6 , V_78 , V_167 = V_38 -> V_75 ;
F_15 ( sizeof( struct V_37 ) !=
sizeof( struct V_19 ) ) ;
V_165 = F_58 ( V_38 -> V_157 , V_167 * sizeof( struct V_37 ) ,
V_95 | V_96 ) ;
if ( ! V_165 ) {
V_6 = - V_11 ;
goto V_168;
}
V_6 = F_33 ( V_165 , V_167 , NULL , & V_78 ) ;
if ( V_6 )
goto V_169;
V_166 = V_38 ;
V_38 = F_78 ( V_166 , F_70 ( V_78 ) , 0 ) ;
if ( ! V_38 ) {
V_38 = V_166 ;
V_6 = - V_11 ;
goto V_169;
}
V_38 -> V_75 = V_78 ;
V_6 = F_33 ( V_165 , V_167 , V_38 , & V_78 ) ;
if ( V_6 )
goto V_169;
V_38 = F_79 ( V_38 , & V_6 ) ;
F_47 ( V_165 ) ;
return V_38 ;
V_169:
F_47 ( V_165 ) ;
V_168:
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
static struct V_76 * F_81 ( struct V_76 * V_38 ,
T_4 V_170 )
{
int V_6 ;
V_38 -> V_171 = NULL ;
V_38 -> V_172 = 0 ;
V_6 = F_53 ( V_38 -> V_157 , V_38 -> V_75 ) ;
if ( V_6 ) {
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
if ( V_170 ) {
V_6 = V_170 ( V_38 -> V_157 , V_38 -> V_75 ) ;
if ( V_6 ) {
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
}
F_82 ( V_38 ) ;
if ( ! V_38 -> V_172 )
V_38 = F_77 ( V_38 ) ;
return V_38 ;
}
int F_83 ( struct V_76 * * V_173 , struct V_154 * V_152 )
{
unsigned int V_153 = F_56 ( V_152 ) ;
struct V_76 * V_38 ;
if ( ! F_52 ( V_152 -> V_8 , V_152 -> V_75 ) )
return - V_93 ;
V_38 = F_84 ( F_70 ( V_152 -> V_75 ) , 0 ) ;
if ( ! V_38 )
return - V_11 ;
memcpy ( V_38 -> V_157 , V_152 -> V_8 , V_153 ) ;
V_38 -> V_75 = V_152 -> V_75 ;
V_38 -> V_156 = NULL ;
V_38 = F_81 ( V_38 , NULL ) ;
if ( F_85 ( V_38 ) )
return F_86 ( V_38 ) ;
* V_173 = V_38 ;
return 0 ;
}
int F_87 ( struct V_76 * * V_173 , struct V_151 * V_152 ,
T_4 V_170 , bool V_174 )
{
unsigned int V_153 = F_56 ( V_152 ) ;
struct V_76 * V_38 ;
int V_6 ;
if ( ! F_52 ( V_152 -> V_8 , V_152 -> V_75 ) )
return - V_93 ;
V_38 = F_84 ( F_70 ( V_152 -> V_75 ) , 0 ) ;
if ( ! V_38 )
return - V_11 ;
if ( F_88 ( V_38 -> V_157 , V_152 -> V_8 , V_153 ) ) {
F_89 ( V_38 ) ;
return - V_175 ;
}
V_38 -> V_75 = V_152 -> V_75 ;
V_38 -> V_156 = NULL ;
if ( V_174 ) {
V_6 = F_55 ( V_38 , V_152 ) ;
if ( V_6 ) {
F_89 ( V_38 ) ;
return - V_11 ;
}
}
V_38 = F_81 ( V_38 , V_170 ) ;
if ( F_85 ( V_38 ) )
return F_86 ( V_38 ) ;
* V_173 = V_38 ;
return 0 ;
}
void F_90 ( struct V_76 * V_38 )
{
F_60 ( V_38 ) ;
}
static int F_91 ( struct V_76 * V_14 , struct V_1 * V_2 )
{
struct V_7 * V_38 , * V_166 ;
V_38 = F_57 ( sizeof( * V_38 ) , V_95 ) ;
if ( ! V_38 )
return - V_11 ;
V_38 -> V_14 = V_14 ;
if ( ! F_72 ( V_2 , V_38 ) ) {
F_47 ( V_38 ) ;
return - V_11 ;
}
F_92 ( & V_38 -> V_161 , 1 ) ;
V_166 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
F_95 ( V_2 -> V_7 , V_38 ) ;
if ( V_166 )
F_69 ( V_2 , V_166 ) ;
return 0 ;
}
static int F_96 ( struct V_76 * V_14 , struct V_1 * V_2 )
{
struct V_76 * V_165 ;
int V_6 ;
if ( F_70 ( V_14 -> V_75 ) > V_164 )
return - V_11 ;
if ( F_97 ( V_2 ) && V_2 -> V_176 ) {
V_6 = F_98 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_99 ( V_2 -> V_177 ) ) {
return - V_93 ;
}
V_165 = F_100 ( V_2 , V_14 ) ;
if ( V_165 )
F_90 ( V_165 ) ;
return 0 ;
}
static
struct V_76 * F_101 ( struct V_151 * V_152 , struct V_1 * V_2 )
{
unsigned int V_153 = F_56 ( V_152 ) ;
struct V_76 * V_14 ;
int V_6 ;
if ( F_3 ( V_2 , V_178 ) )
return F_80 ( - V_15 ) ;
if ( ! F_52 ( V_152 -> V_8 , V_152 -> V_75 ) )
return F_80 ( - V_93 ) ;
V_14 = F_84 ( F_70 ( V_152 -> V_75 ) , 0 ) ;
if ( ! V_14 )
return F_80 ( - V_11 ) ;
if ( F_88 ( V_14 -> V_157 , V_152 -> V_8 , V_153 ) ) {
F_89 ( V_14 ) ;
return F_80 ( - V_175 ) ;
}
V_14 -> V_75 = V_152 -> V_75 ;
V_6 = F_55 ( V_14 , V_152 ) ;
if ( V_6 ) {
F_89 ( V_14 ) ;
return F_80 ( - V_11 ) ;
}
return F_81 ( V_14 , NULL ) ;
}
int F_102 ( struct V_151 * V_152 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_101 ( V_152 , V_2 ) ;
int V_6 ;
if ( F_85 ( V_14 ) )
return F_86 ( V_14 ) ;
V_6 = F_91 ( V_14 , V_2 ) ;
if ( V_6 < 0 ) {
F_60 ( V_14 ) ;
return V_6 ;
}
return 0 ;
}
int F_103 ( struct V_151 * V_152 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_101 ( V_152 , V_2 ) ;
int V_6 ;
if ( F_85 ( V_14 ) )
return F_86 ( V_14 ) ;
V_6 = F_96 ( V_14 , V_2 ) ;
if ( V_6 < 0 ) {
F_60 ( V_14 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_76 * F_104 ( T_1 V_179 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_178 ) )
return F_80 ( - V_15 ) ;
return F_105 ( V_179 , V_158 ) ;
}
int F_106 ( T_1 V_179 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_104 ( V_179 , V_2 ) ;
int V_6 ;
if ( F_85 ( V_14 ) )
return F_86 ( V_14 ) ;
V_6 = F_91 ( V_14 , V_2 ) ;
if ( V_6 < 0 ) {
F_61 ( V_14 ) ;
return V_6 ;
}
return 0 ;
}
int F_107 ( T_1 V_179 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_104 ( V_179 , V_2 ) ;
int V_6 ;
if ( F_85 ( V_14 ) )
return F_86 ( V_14 ) ;
V_6 = F_96 ( V_14 , V_2 ) ;
if ( V_6 < 0 ) {
F_61 ( V_14 ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_108 ( struct V_3 * V_4 ,
unsigned int V_180 )
{
return F_109 ( V_4 , V_180 ) ;
}
static inline int F_110 ( struct V_3 * V_4 ,
unsigned int V_180 )
{
int V_6 = F_108 ( V_4 , V_180 ) ;
F_111 ( V_4 ) ;
return V_6 ;
}
static int F_112 ( struct V_3 * V_4 )
{
return F_110 ( V_4 , F_113 ( V_4 ) ) ;
}
static inline void F_114 ( struct V_3 * V_4 )
{
if ( F_115 ( V_4 ) )
F_116 ( V_4 , F_117 ( V_4 ) , V_4 -> V_181 ) ;
}
static inline void F_118 ( struct V_3 * V_4 )
{
if ( F_115 ( V_4 ) )
F_119 ( V_4 , F_117 ( V_4 ) , V_4 -> V_181 ) ;
}
static inline int F_120 ( struct V_50 * V_52 , struct V_3 * V_4 )
{
return F_121 ( V_52 , V_4 ) ;
}
static inline int F_122 ( struct V_50 * V_52 ,
struct V_3 * V_4 )
{
int V_145 = F_123 ( V_52 , V_4 ) ;
if ( F_124 ( ! V_145 ) ) {
V_4 -> V_52 = V_52 ;
V_145 = F_125 ( V_4 ) ;
}
return V_145 ;
}
static inline int F_126 ( struct V_50 * V_52 , struct V_3 * V_4 )
{
int V_145 ;
if ( F_127 ( F_128 ( V_182 ) > V_183 ) ) {
F_129 ( L_1 ) ;
F_130 ( V_4 ) ;
return - V_184 ;
}
V_4 -> V_52 = V_52 ;
F_131 ( V_182 ) ;
V_145 = F_132 ( V_4 ) ;
F_133 ( V_182 ) ;
return V_145 ;
}
static int F_134 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_185 )
{
unsigned int V_186 = V_4 -> V_187 - V_4 -> V_188 ;
F_135 ( V_4 , V_186 ) ;
if ( ! F_115 ( V_4 ) )
F_119 ( V_4 , F_117 ( V_4 ) , V_186 ) ;
F_136 ( V_4 ) ;
F_137 ( V_4 ) ;
return V_185 & V_189 ?
F_122 ( V_52 , V_4 ) : F_126 ( V_52 , V_4 ) ;
}
static int F_138 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_185 )
{
if ( F_127 ( V_4 -> V_188 >= V_4 -> V_187 ) ) {
F_130 ( V_4 ) ;
return - V_190 ;
}
F_114 ( V_4 ) ;
return V_185 & V_189 ?
F_120 ( V_52 , V_4 ) : F_126 ( V_52 , V_4 ) ;
}
static int F_139 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_185 )
{
if ( F_140 ( V_52 ) )
return F_138 ( V_4 , V_52 , V_185 ) ;
else
return F_134 ( V_4 , V_52 , V_185 ) ;
}
int F_141 ( struct V_3 * V_4 )
{
struct V_191 * V_192 = F_142 ( & V_191 ) ;
struct V_50 * V_52 ;
V_52 = F_143 ( F_144 ( V_4 -> V_52 ) , V_192 -> V_51 ) ;
V_192 -> V_51 = 0 ;
if ( F_127 ( ! V_52 ) ) {
F_130 ( V_4 ) ;
return - V_93 ;
}
return F_139 ( V_4 , V_52 , V_192 -> V_185 ) ;
}
struct V_1 * F_145 ( struct V_3 * V_4 )
{
struct V_193 * V_194 = F_146 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
if ( V_194 -> V_195 . V_196 ) {
V_2 = F_147 ( V_194 -> V_195 . V_196 , V_194 -> V_195 . V_197 ) ;
V_194 -> V_195 . V_197 = 0 ;
V_194 -> V_195 . V_196 = NULL ;
}
return V_2 ;
}
static int F_148 ( struct V_3 * V_4 , T_1 V_198 , T_1 V_75 )
{
F_149 ( V_4 , V_75 ) ;
memmove ( V_4 -> V_199 , V_4 -> V_199 + V_75 , V_198 ) ;
memset ( V_4 -> V_199 + V_198 , 0 , V_75 ) ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 , T_1 V_198 , T_1 V_75 )
{
if ( F_127 ( ! F_151 ( V_4 , V_198 + V_75 ) ) )
return - V_11 ;
F_119 ( V_4 , V_4 -> V_199 + V_198 , V_75 ) ;
memmove ( V_4 -> V_199 + V_75 , V_4 -> V_199 , V_198 ) ;
F_135 ( V_4 , V_75 ) ;
return 0 ;
}
static int F_152 ( struct V_3 * V_4 , T_1 V_198 , T_1 V_75 )
{
bool V_200 = V_4 -> V_201 == V_4 -> V_187 ;
int V_145 ;
V_145 = F_148 ( V_4 , V_198 , V_75 ) ;
if ( F_124 ( ! V_145 ) ) {
V_4 -> V_188 -= V_75 ;
V_4 -> V_187 -= V_75 ;
if ( V_200 )
V_4 -> V_201 = V_4 -> V_187 ;
}
return V_145 ;
}
static int F_153 ( struct V_3 * V_4 , T_1 V_198 , T_1 V_75 )
{
bool V_200 = V_4 -> V_201 == V_4 -> V_187 ;
int V_145 ;
V_145 = F_150 ( V_4 , V_198 , V_75 ) ;
if ( F_124 ( ! V_145 ) ) {
V_4 -> V_188 += V_75 ;
V_4 -> V_187 += V_75 ;
if ( V_200 )
V_4 -> V_201 = V_4 -> V_187 ;
}
return V_145 ;
}
static int F_154 ( struct V_3 * V_4 )
{
const T_1 V_202 = sizeof( struct V_203 ) - sizeof( struct V_204 ) ;
T_1 V_198 = F_155 ( V_4 ) ;
int V_145 ;
V_145 = F_156 ( V_4 , V_202 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
V_145 = F_152 ( V_4 , V_198 , V_202 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
if ( F_157 ( V_4 ) ) {
if ( F_158 ( V_4 ) -> V_205 & V_206 ) {
F_158 ( V_4 ) -> V_205 &= ~ V_206 ;
F_158 ( V_4 ) -> V_205 |= V_207 ;
}
F_158 ( V_4 ) -> V_208 -= V_202 ;
F_158 ( V_4 ) -> V_205 |= V_209 ;
F_158 ( V_4 ) -> V_210 = 0 ;
}
V_4 -> V_44 = F_159 ( V_211 ) ;
F_160 ( V_4 ) ;
return 0 ;
}
static int F_161 ( struct V_3 * V_4 )
{
const T_1 V_202 = sizeof( struct V_203 ) - sizeof( struct V_204 ) ;
T_1 V_198 = F_155 ( V_4 ) ;
int V_145 ;
V_145 = F_162 ( V_4 , V_212 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
V_145 = F_153 ( V_4 , V_198 , V_202 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
if ( F_157 ( V_4 ) ) {
if ( F_158 ( V_4 ) -> V_205 & V_207 ) {
F_158 ( V_4 ) -> V_205 &= ~ V_207 ;
F_158 ( V_4 ) -> V_205 |= V_206 ;
}
F_158 ( V_4 ) -> V_208 += V_202 ;
F_158 ( V_4 ) -> V_205 |= V_209 ;
F_158 ( V_4 ) -> V_210 = 0 ;
}
V_4 -> V_44 = F_159 ( V_213 ) ;
F_160 ( V_4 ) ;
return 0 ;
}
static int F_163 ( struct V_3 * V_4 , T_5 V_214 )
{
T_5 V_215 = V_4 -> V_44 ;
if ( V_215 == F_159 ( V_213 ) &&
V_214 == F_159 ( V_211 ) )
return F_154 ( V_4 ) ;
if ( V_215 == F_159 ( V_211 ) &&
V_214 == F_159 ( V_213 ) )
return F_161 ( V_4 ) ;
return - V_216 ;
}
static T_1 F_164 ( const struct V_3 * V_4 )
{
switch ( V_4 -> V_44 ) {
case F_159 ( V_213 ) :
return sizeof( struct V_204 ) ;
case F_159 ( V_211 ) :
return sizeof( struct V_203 ) ;
default:
return ~ 0U ;
}
}
static int F_165 ( struct V_3 * V_4 , T_1 V_202 )
{
T_1 V_198 = F_155 ( V_4 ) + F_164 ( V_4 ) ;
int V_145 ;
V_145 = F_156 ( V_4 , V_202 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
V_145 = F_152 ( V_4 , V_198 , V_202 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
if ( F_157 ( V_4 ) ) {
F_158 ( V_4 ) -> V_208 -= V_202 ;
F_158 ( V_4 ) -> V_205 |= V_209 ;
F_158 ( V_4 ) -> V_210 = 0 ;
}
return 0 ;
}
static int F_166 ( struct V_3 * V_4 , T_1 V_202 )
{
T_1 V_198 = F_155 ( V_4 ) + F_164 ( V_4 ) ;
int V_145 ;
V_145 = F_162 ( V_4 , V_212 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
V_145 = F_153 ( V_4 , V_198 , V_202 ) ;
if ( F_127 ( V_145 < 0 ) )
return V_145 ;
if ( F_157 ( V_4 ) ) {
F_158 ( V_4 ) -> V_208 += V_202 ;
F_158 ( V_4 ) -> V_205 |= V_209 ;
F_158 ( V_4 ) -> V_210 = 0 ;
}
return 0 ;
}
static T_1 F_167 ( const struct V_3 * V_4 )
{
return V_4 -> V_52 -> V_217 + V_4 -> V_52 -> V_218 ;
}
static int F_168 ( struct V_3 * V_4 , T_6 V_202 )
{
bool V_200 = V_4 -> V_201 == V_4 -> V_187 ;
T_1 V_219 , V_220 = abs ( V_202 ) ;
T_1 V_221 = F_164 ( V_4 ) ;
T_1 V_222 = F_167 ( V_4 ) ;
T_5 V_223 = V_4 -> V_44 ;
bool V_224 = V_202 < 0 ;
int V_145 ;
if ( F_127 ( V_220 > 0xfffU ) )
return - V_175 ;
if ( F_127 ( V_223 != F_159 ( V_213 ) &&
V_223 != F_159 ( V_211 ) ) )
return - V_216 ;
V_219 = V_4 -> V_75 - F_169 ( V_4 ) ;
if ( F_170 ( V_4 ) && ! V_200 )
V_219 = F_171 ( V_4 ) ;
if ( ( V_224 && ( V_220 >= V_219 ||
V_219 - V_220 < V_221 ) ) ||
( ! V_224 && ( V_4 -> V_75 + V_220 > V_222 &&
! F_157 ( V_4 ) ) ) )
return - V_216 ;
V_145 = V_224 ? F_166 ( V_4 , V_220 ) :
F_165 ( V_4 , V_220 ) ;
F_111 ( V_4 ) ;
return V_145 ;
}
static T_1 F_172 ( const struct V_3 * V_4 )
{
T_1 V_225 = F_169 ( V_4 ) ;
if ( F_170 ( V_4 ) )
V_225 = F_173 ( V_4 ) ;
if ( V_4 -> V_226 == V_227 )
V_225 = F_174 ( V_4 ) +
V_4 -> V_228 + sizeof( V_229 ) ;
return V_225 ;
}
static int F_175 ( struct V_3 * V_4 , unsigned int V_78 )
{
unsigned int V_167 = V_4 -> V_75 ;
int V_145 ;
V_145 = F_176 ( V_4 , V_78 ) ;
if ( ! V_145 )
memset ( V_4 -> V_199 + V_167 , 0 , V_78 - V_167 ) ;
return V_145 ;
}
static int F_177 ( struct V_3 * V_4 , unsigned int V_78 )
{
return F_178 ( V_4 , V_78 ) ;
}
static int F_179 ( struct V_50 * V_52 ,
struct V_230 * V_196 ,
struct V_231 * V_232 ,
T_1 V_233 )
{
int V_6 ;
if ( ! V_52 -> V_234 -> V_235 ) {
return - V_236 ;
}
V_6 = V_52 -> V_234 -> V_235 ( V_52 , V_232 ) ;
if ( V_6 )
return V_6 ;
if ( V_196 )
F_180 ( V_196 , V_233 ) ;
else
V_52 -> V_234 -> V_237 ( V_52 ) ;
return 0 ;
}
void F_181 ( void )
{
struct V_191 * V_192 = F_142 ( & V_191 ) ;
struct V_230 * V_196 = V_192 -> V_238 ;
V_192 -> V_238 = NULL ;
if ( V_196 )
F_182 ( V_196 ) ;
}
static inline bool F_183 ( const struct V_76 * V_239 ,
unsigned long V_133 )
{
return ( unsigned long ) V_239 -> V_133 != V_133 ;
}
static int F_184 ( struct V_50 * V_52 , struct V_231 * V_232 ,
struct V_76 * V_239 )
{
struct V_191 * V_192 = F_142 ( & V_191 ) ;
unsigned long V_240 = V_192 -> V_240 ;
struct V_230 * V_196 = V_192 -> V_196 ;
struct V_50 * V_241 = NULL ;
T_1 V_233 = V_192 -> V_51 ;
int V_6 ;
V_192 -> V_51 = 0 ;
V_192 -> V_196 = NULL ;
V_192 -> V_240 = 0 ;
if ( F_127 ( F_183 ( V_239 , V_240 ) ) ) {
V_6 = - V_175 ;
V_196 = NULL ;
goto V_6;
}
V_241 = F_185 ( V_196 , V_233 ) ;
if ( ! V_241 ) {
V_6 = - V_93 ;
goto V_6;
}
if ( V_192 -> V_238 && V_192 -> V_238 != V_196 )
F_181 () ;
V_6 = F_179 ( V_241 , V_196 , V_232 , V_233 ) ;
if ( F_127 ( V_6 ) )
goto V_6;
V_192 -> V_238 = V_196 ;
F_186 ( V_52 , V_239 , V_241 , V_196 , V_233 ) ;
return 0 ;
V_6:
F_187 ( V_52 , V_239 , V_241 , V_196 , V_233 , V_6 ) ;
return V_6 ;
}
int F_188 ( struct V_50 * V_52 , struct V_231 * V_232 ,
struct V_76 * V_239 )
{
struct V_191 * V_192 = F_142 ( & V_191 ) ;
struct V_50 * V_241 ;
T_1 V_233 = V_192 -> V_51 ;
int V_6 ;
if ( V_192 -> V_196 )
return F_184 ( V_52 , V_232 , V_239 ) ;
V_241 = F_143 ( F_144 ( V_52 ) , V_233 ) ;
V_192 -> V_51 = 0 ;
if ( F_127 ( ! V_241 ) ) {
V_6 = - V_93 ;
goto V_6;
}
V_6 = F_179 ( V_241 , NULL , V_232 , 0 ) ;
if ( F_127 ( V_6 ) )
goto V_6;
F_189 ( V_52 , V_239 , V_233 ) ;
return 0 ;
V_6:
F_190 ( V_52 , V_239 , V_233 , V_6 ) ;
return V_6 ;
}
int F_191 ( struct V_50 * V_52 , struct V_3 * V_4 ,
struct V_76 * V_239 )
{
struct V_191 * V_192 = F_142 ( & V_191 ) ;
unsigned long V_240 = V_192 -> V_240 ;
struct V_230 * V_196 = V_192 -> V_196 ;
struct V_50 * V_241 = NULL ;
T_1 V_233 = V_192 -> V_51 ;
unsigned int V_75 ;
int V_6 = 0 ;
V_192 -> V_51 = 0 ;
V_192 -> V_196 = NULL ;
V_192 -> V_240 = 0 ;
if ( V_196 ) {
if ( F_127 ( F_183 ( V_239 , V_240 ) ) ) {
V_6 = - V_175 ;
V_196 = NULL ;
goto V_6;
}
V_241 = F_185 ( V_196 , V_233 ) ;
} else {
V_241 = F_143 ( F_144 ( V_52 ) , V_233 ) ;
}
if ( F_127 ( ! V_241 ) ) {
V_6 = - V_93 ;
goto V_6;
}
if ( F_127 ( ! ( V_241 -> V_185 & V_242 ) ) ) {
V_6 = - V_184 ;
goto V_6;
}
V_75 = V_241 -> V_217 + V_241 -> V_218 + V_243 ;
if ( V_4 -> V_75 > V_75 ) {
V_6 = - V_244 ;
goto V_6;
}
V_4 -> V_52 = V_241 ;
V_196 ? F_186 ( V_52 , V_239 , V_241 , V_196 , V_233 )
: F_189 ( V_52 , V_239 , V_233 ) ;
return 0 ;
V_6:
V_196 ? F_187 ( V_52 , V_239 , V_241 , V_196 , V_233 , V_6 )
: F_190 ( V_52 , V_239 , V_233 , V_6 ) ;
return V_6 ;
}
bool F_192 ( void * V_245 )
{
if ( V_245 == V_246 ||
V_245 == V_247 ||
V_245 == V_248 ||
V_245 == V_249 ||
V_245 == V_250 ||
V_245 == V_251 ||
V_245 == V_252 ||
V_245 == V_253 ||
V_245 == V_254 ||
V_245 == V_255 ||
V_245 == V_256 ||
V_245 == V_257 )
return true ;
return false ;
}
static unsigned long F_193 ( void * V_258 , const void * V_4 ,
unsigned long V_198 , unsigned long V_75 )
{
void * V_259 = F_194 ( V_4 , V_198 , V_75 , V_258 ) ;
if ( F_127 ( ! V_259 ) )
return V_75 ;
if ( V_259 != V_258 )
memcpy ( V_258 , V_259 , V_75 ) ;
return 0 ;
}
static unsigned short F_195 ( T_7 V_185 )
{
return V_185 & V_260 ? V_261 : V_262 ;
}
static const struct V_263 *
F_196 ( enum V_264 V_265 )
{
if ( ! V_266 ) {
V_266 = F_197 ( V_267 ,
V_268 ,
V_95 ) ;
if ( ! V_266 )
return NULL ;
}
switch ( V_265 ) {
case V_269 :
return & V_270 ;
case V_271 :
return & V_272 ;
default:
return NULL ;
}
}
static unsigned long F_198 ( void * V_258 , const void * V_273 ,
unsigned long V_198 , unsigned long V_75 )
{
memcpy ( V_258 , V_273 + V_198 , V_75 ) ;
return 0 ;
}
static const struct V_263 *
F_199 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_275 :
return & V_276 ;
case V_277 :
return & V_278 ;
case V_279 :
return & V_280 ;
case V_281 :
return & V_282 ;
case V_283 :
return & V_284 ;
case V_285 :
return & V_286 ;
case V_287 :
return & V_288 ;
case V_289 :
return & V_290 ;
case V_291 :
if ( F_200 ( V_292 ) )
return F_201 () ;
default:
return NULL ;
}
}
static const struct V_263 *
F_202 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_293 :
return & V_294 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 *
F_203 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_295 :
return & V_296 ;
case V_297 :
return & V_298 ;
case V_299 :
return & V_300 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 *
F_204 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_301 :
return & V_302 ;
case V_295 :
return & V_296 ;
case V_303 :
return & V_304 ;
case V_305 :
return & V_306 ;
case V_307 :
return & V_308 ;
case V_309 :
return & V_310 ;
case V_311 :
return & V_312 ;
case V_313 :
return & V_314 ;
case V_315 :
return & V_316 ;
case V_317 :
return & V_318 ;
case V_319 :
return & V_320 ;
case V_321 :
return & V_322 ;
case V_323 :
return & V_324 ;
case V_325 :
return & V_326 ;
case V_327 :
return & V_328 ;
case V_329 :
return & V_330 ;
case V_269 :
return F_196 ( V_274 ) ;
case V_331 :
return & V_332 ;
case V_271 :
return F_196 ( V_274 ) ;
case V_333 :
return & V_334 ;
case V_335 :
return & V_336 ;
case V_337 :
return & V_338 ;
case V_339 :
return & V_340 ;
case V_341 :
return & V_342 ;
case V_343 :
return & V_344 ;
case V_283 :
return & V_345 ;
case V_346 :
return & V_347 ;
case V_297 :
return & V_298 ;
case V_299 :
return & V_300 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 *
F_205 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_343 :
return & V_348 ;
case V_283 :
return & V_345 ;
case V_349 :
return & V_350 ;
case V_333 :
return & V_351 ;
case V_352 :
return & V_353 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 *
F_206 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_295 :
return & V_296 ;
case V_303 :
return & V_304 ;
case V_305 :
return & V_306 ;
case V_315 :
return & V_316 ;
case V_335 :
return & V_336 ;
case V_337 :
return & V_338 ;
case V_343 :
return & V_344 ;
case V_283 :
return & V_345 ;
case V_346 :
return & V_347 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 *
F_207 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_354 :
return & V_355 ;
case V_356 :
return & V_357 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 * F_208 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_301 :
return & V_302 ;
case V_295 :
return & V_296 ;
case V_303 :
return & V_304 ;
case V_327 :
return & V_328 ;
case V_358 :
return & V_359 ;
case V_297 :
return & V_298 ;
case V_299 :
return & V_300 ;
case V_360 :
return & V_361 ;
default:
return F_199 ( V_274 ) ;
}
}
static const struct V_263 *
F_209 ( enum V_264 V_274 )
{
switch ( V_274 ) {
case V_329 :
return & V_330 ;
case V_269 :
return F_196 ( V_274 ) ;
case V_331 :
return & V_332 ;
case V_271 :
return F_196 ( V_274 ) ;
case V_333 :
return & V_334 ;
case V_313 :
return & V_314 ;
case V_327 :
return & V_328 ;
case V_358 :
return & V_359 ;
case V_301 :
return & V_302 ;
case V_307 :
return & V_308 ;
case V_309 :
return & V_310 ;
case V_311 :
return & V_312 ;
case V_339 :
return & V_340 ;
default:
return F_206 ( V_274 ) ;
}
}
static bool F_210 ( int V_198 , int V_362 , enum V_363 type ,
struct V_364 * V_365 )
{
const int V_366 = sizeof( V_367 ) ;
if ( V_198 < 0 || V_198 >= sizeof( struct V_368 ) )
return false ;
if ( V_198 % V_362 != 0 )
return false ;
switch ( V_198 ) {
case F_211 ( struct V_368 , V_369 [ 0 ] , V_369 [ 4 ] ) :
if ( V_198 + V_362 > F_212 ( struct V_368 , V_369 [ 4 ] ) )
return false ;
break;
case F_211 ( struct V_368 , V_370 [ 0 ] , V_370 [ 3 ] ) :
case F_211 ( struct V_368 , V_371 [ 0 ] , V_371 [ 3 ] ) :
case F_211 ( struct V_368 , V_372 , V_372 ) :
case F_211 ( struct V_368 , V_373 , V_373 ) :
case F_213 ( struct V_368 , V_199 ) :
case F_213 ( struct V_368 , V_374 ) :
if ( V_362 != V_366 )
return false ;
break;
default:
if ( type == V_375 ) {
if ( V_362 != V_366 )
return false ;
} else {
F_214 ( V_365 , V_366 ) ;
if ( ! F_215 ( V_198 , V_362 , V_366 ) )
return false ;
}
}
return true ;
}
static bool F_216 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
switch ( V_198 ) {
case F_213 ( struct V_368 , V_376 ) :
case F_213 ( struct V_368 , V_199 ) :
case F_213 ( struct V_368 , V_374 ) :
case F_211 ( struct V_368 , V_377 , V_378 ) :
return false ;
}
if ( type == V_375 ) {
switch ( V_198 ) {
case F_211 ( struct V_368 , V_369 [ 0 ] , V_369 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_210 ( V_198 , V_362 , type , V_365 ) ;
}
static bool F_217 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
switch ( V_198 ) {
case F_213 ( struct V_368 , V_376 ) :
case F_211 ( struct V_368 , V_377 , V_378 ) :
return false ;
}
if ( type == V_375 ) {
switch ( V_198 ) {
case F_213 ( struct V_368 , V_23 ) :
case F_213 ( struct V_368 , V_379 ) :
case F_211 ( struct V_368 , V_369 [ 0 ] , V_369 [ 4 ] ) :
break;
default:
return false ;
}
}
switch ( V_198 ) {
case F_213 ( struct V_368 , V_199 ) :
V_365 -> V_380 = V_381 ;
break;
case F_213 ( struct V_368 , V_374 ) :
V_365 -> V_380 = V_382 ;
break;
}
return F_210 ( V_198 , V_362 , type , V_365 ) ;
}
static bool F_218 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
if ( type == V_375 ) {
switch ( V_198 ) {
case F_18 ( struct V_383 , V_384 ) :
case F_18 ( struct V_383 , V_23 ) :
case F_18 ( struct V_383 , V_379 ) :
break;
default:
return false ;
}
}
if ( V_198 < 0 || V_198 + V_362 > sizeof( struct V_383 ) )
return false ;
if ( V_198 % V_362 != 0 )
return false ;
if ( V_362 != sizeof( V_367 ) )
return false ;
return true ;
}
static int F_219 ( struct V_19 * V_20 , bool V_385 ,
const struct V_76 * V_14 , int V_386 )
{
struct V_19 * V_21 = V_20 ;
if ( ! V_385 )
return 0 ;
* V_21 ++ = F_17 ( V_26 , V_387 , V_388 , F_220 () ) ;
* V_21 ++ = F_20 ( V_27 , V_387 , V_389 ) ;
* V_21 ++ = F_25 ( V_116 , V_387 , 0 , 7 ) ;
* V_21 ++ = F_27 ( V_387 , V_388 ) ;
* V_21 ++ = F_35 ( V_74 , V_390 , V_390 ) ;
* V_21 ++ = F_38 ( V_114 | V_391 , 0 , 0 , 0 ,
V_303 ) ;
* V_21 ++ = F_25 ( V_116 , V_130 , 0 , 2 ) ;
* V_21 ++ = F_20 ( V_392 , V_130 , V_386 ) ;
* V_21 ++ = F_26 () ;
* V_21 ++ = F_27 ( V_388 , V_387 ) ;
* V_21 ++ = V_14 -> V_94 [ 0 ] ;
return V_21 - V_20 ;
}
static int F_221 ( struct V_19 * V_20 , bool V_385 ,
const struct V_76 * V_14 )
{
return F_219 ( V_20 , V_385 , V_14 , V_393 ) ;
}
static bool F_222 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
if ( type == V_375 ) {
switch ( V_198 ) {
case F_213 ( struct V_368 , V_23 ) :
case F_213 ( struct V_368 , V_394 ) :
case F_213 ( struct V_368 , V_379 ) :
case F_213 ( struct V_368 , V_376 ) :
case F_211 ( struct V_368 , V_369 [ 0 ] , V_369 [ 4 ] ) :
break;
default:
return false ;
}
}
switch ( V_198 ) {
case F_213 ( struct V_368 , V_199 ) :
V_365 -> V_380 = V_381 ;
break;
case F_213 ( struct V_368 , V_374 ) :
V_365 -> V_380 = V_382 ;
break;
case F_211 ( struct V_368 , V_377 , V_378 ) :
return false ;
}
return F_210 ( V_198 , V_362 , type , V_365 ) ;
}
static bool F_223 ( int V_198 , int V_362 )
{
if ( V_198 < 0 || V_198 >= sizeof( struct V_395 ) )
return false ;
if ( V_198 % V_362 != 0 )
return false ;
if ( V_362 != sizeof( V_367 ) )
return false ;
return true ;
}
static bool F_224 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
if ( type == V_375 )
return false ;
switch ( V_198 ) {
case F_18 ( struct V_395 , V_199 ) :
V_365 -> V_380 = V_381 ;
break;
case F_18 ( struct V_395 , V_374 ) :
V_365 -> V_380 = V_382 ;
break;
}
return F_223 ( V_198 , V_362 ) ;
}
void F_225 ( T_1 V_396 )
{
const T_1 V_397 = V_398 ;
F_226 ( 1 , L_2 ,
V_396 > V_397 ? L_3 : L_4 ,
V_396 ) ;
}
static bool F_227 ( int V_198 , int V_362 )
{
if ( V_198 < 0 || V_198 >= sizeof( struct V_399 ) )
return false ;
if ( V_198 % V_362 != 0 )
return false ;
if ( V_362 != sizeof( V_367 ) )
return false ;
return true ;
}
static bool F_228 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
if ( type == V_375 ) {
switch ( V_198 ) {
case F_18 ( struct V_399 , V_400 ) ...
F_18 ( struct V_399 , V_401 [ 3 ] ) :
break;
default:
return false ;
}
}
return F_227 ( V_198 , V_362 ) ;
}
static int F_229 ( struct V_19 * V_20 , bool V_385 ,
const struct V_76 * V_14 )
{
return F_219 ( V_20 , V_385 , V_14 , V_402 ) ;
}
static bool F_230 ( int V_198 , int V_362 ,
enum V_363 type ,
struct V_364 * V_365 )
{
if ( type == V_375 ) {
switch ( V_198 ) {
case F_213 ( struct V_368 , V_394 ) :
case F_213 ( struct V_368 , V_379 ) :
break;
default:
return false ;
}
}
switch ( V_198 ) {
case F_213 ( struct V_368 , V_23 ) :
case F_213 ( struct V_368 , V_376 ) :
return false ;
case F_213 ( struct V_368 , V_199 ) :
V_365 -> V_380 = V_381 ;
break;
case F_213 ( struct V_368 , V_374 ) :
V_365 -> V_380 = V_382 ;
break;
}
return F_210 ( V_198 , V_362 , type , V_365 ) ;
}
static T_1 F_231 ( enum V_363 type ,
const struct V_19 * V_403 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_404 )
{
struct V_19 * V_21 = V_20 ;
int V_198 ;
switch ( V_403 -> V_198 ) {
case F_18 ( struct V_368 , V_75 ) :
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_75 , 4 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_44 ) :
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_44 , 2 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_58 ) :
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_58 , 2 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_379 ) :
if ( type == V_375 )
* V_21 ++ = F_46 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_379 , 4 ,
V_404 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_379 , 4 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_405 ) :
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_406 , 4 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_51 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_25 ( V_116 , V_403 -> V_17 , 0 , 1 ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_50 , V_51 , 4 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_56 ) :
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_56 , 4 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_23 ) :
if ( type == V_375 )
* V_21 ++ = F_46 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_23 , 4 ,
V_404 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_23 , 4 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_407 ) :
* V_404 = 1 ;
* V_21 ++ = F_17 ( V_26 , V_403 -> V_17 , V_403 -> V_18 ,
F_19 () ) ;
* V_21 ++ = F_20 ( V_27 , V_403 -> V_17 , V_28 ) ;
#ifdef F_21
* V_21 ++ = F_20 ( V_29 , V_403 -> V_17 , 5 ) ;
#endif
break;
case F_18 ( struct V_368 , V_31 ) :
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_31 , 2 ,
V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_408 ) :
case F_18 ( struct V_368 , V_35 ) :
F_15 ( V_36 != 0x1000 ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_35 , 2 ,
V_404 ) ) ;
if ( V_403 -> V_198 == F_18 ( struct V_368 , V_35 ) ) {
* V_21 ++ = F_20 ( V_27 , V_403 -> V_17 ,
~ V_36 ) ;
} else {
* V_21 ++ = F_20 ( V_29 , V_403 -> V_17 , 12 ) ;
* V_21 ++ = F_20 ( V_27 , V_403 -> V_17 , 1 ) ;
}
break;
case F_18 ( struct V_368 , V_369 [ 0 ] ) ...
F_212 ( struct V_368 , V_369 [ 4 ] ) - 1 :
F_15 ( F_16 ( struct V_409 , V_199 ) < 20 ) ;
F_15 ( ( F_18 ( struct V_3 , V_369 ) +
F_18 ( struct V_409 , V_199 ) ) %
sizeof( V_410 ) ) ;
V_14 -> V_411 = 1 ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_368 , V_369 [ 0 ] ) ;
V_198 += F_18 ( struct V_3 , V_369 ) ;
V_198 += F_18 ( struct V_409 , V_199 ) ;
if ( type == V_375 )
* V_21 ++ = F_46 ( F_233 ( V_403 -> V_99 ) , V_403 -> V_17 ,
V_403 -> V_18 , V_198 ) ;
else
* V_21 ++ = F_17 ( F_233 ( V_403 -> V_99 ) , V_403 -> V_17 ,
V_403 -> V_18 , V_198 ) ;
break;
case F_18 ( struct V_368 , V_376 ) :
F_15 ( F_16 ( struct V_409 , V_376 ) != 2 ) ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_368 , V_376 ) ;
V_198 += F_18 ( struct V_3 , V_369 ) ;
V_198 += F_18 ( struct V_409 , V_376 ) ;
* V_404 = 2 ;
if ( type == V_375 )
* V_21 ++ = F_46 ( V_32 , V_403 -> V_17 ,
V_403 -> V_18 , V_198 ) ;
else
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 ,
V_403 -> V_18 , V_198 ) ;
break;
case F_18 ( struct V_368 , V_199 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_199 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_199 ) ) ;
break;
case F_18 ( struct V_368 , V_374 ) :
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_368 , V_374 ) ;
V_198 += F_18 ( struct V_3 , V_369 ) ;
V_198 += F_18 ( struct V_412 , V_374 ) ;
* V_21 ++ = F_17 ( F_234 ( void * ) , V_403 -> V_17 ,
V_403 -> V_18 , V_198 ) ;
break;
case F_18 ( struct V_368 , V_394 ) :
#ifdef F_235
if ( type == V_375 )
* V_21 ++ = F_46 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_394 , 2 ,
V_404 ) ) ;
else
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_394 , 2 ,
V_404 ) ) ;
#else
* V_404 = 2 ;
if ( type == V_375 )
* V_21 ++ = F_27 ( V_403 -> V_17 , V_403 -> V_17 ) ;
else
* V_21 ++ = F_236 ( V_403 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_368 , V_413 ) :
#if F_237 ( V_414 )
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_232 ( struct V_3 , V_413 , 4 ,
V_404 ) ) ;
* V_21 ++ = F_25 ( V_119 , V_403 -> V_17 , V_415 , 1 ) ;
* V_21 ++ = F_236 ( V_403 -> V_17 , 0 ) ;
#else
* V_404 = 4 ;
* V_21 ++ = F_236 ( V_403 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_368 , V_377 ) :
F_15 ( F_16 ( struct V_416 , V_417 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_416 ,
V_417 ,
2 , V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_372 ) :
F_15 ( F_16 ( struct V_416 , V_418 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_416 ,
V_418 ,
4 , V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_373 ) :
F_15 ( F_16 ( struct V_416 ,
V_419 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_416 ,
V_419 ,
4 , V_404 ) ) ;
break;
case F_18 ( struct V_368 , V_370 [ 0 ] ) ...
F_18 ( struct V_368 , V_370 [ 3 ] ) :
#if F_238 ( V_420 )
F_15 ( F_16 ( struct V_416 ,
V_421 . V_422 [ 0 ] ) != 4 ) ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_368 , V_370 [ 0 ] ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 ,
V_421 . V_422 [ 0 ] ) +
V_198 ) ;
#else
* V_21 ++ = F_41 ( V_403 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_368 , V_371 [ 0 ] ) ...
F_18 ( struct V_368 , V_371 [ 3 ] ) :
#if F_238 ( V_420 )
F_15 ( F_16 ( struct V_416 ,
V_423 . V_422 [ 0 ] ) != 4 ) ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_368 , V_371 [ 0 ] ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 ,
V_423 . V_422 [ 0 ] ) +
V_198 ) ;
#else
* V_21 ++ = F_41 ( V_403 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_368 , V_424 ) :
F_15 ( F_16 ( struct V_416 , V_425 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_416 ,
V_425 ,
2 , V_404 ) ) ;
#ifndef F_21
* V_21 ++ = F_20 ( V_106 , V_403 -> V_17 , 16 ) ;
#endif
break;
case F_18 ( struct V_368 , V_378 ) :
F_15 ( F_16 ( struct V_416 , V_426 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_416 ,
V_426 , 2 , V_404 ) ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_239 ( enum V_363 type ,
const struct V_19 * V_403 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_404 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_403 -> V_198 ) {
case F_18 ( struct V_383 , V_384 ) :
F_15 ( F_16 ( struct V_1 , V_427 ) != 4 ) ;
if ( type == V_375 )
* V_21 ++ = F_46 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_427 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_427 ) ) ;
break;
case F_18 ( struct V_383 , V_23 ) :
F_15 ( F_16 ( struct V_1 , V_428 ) != 4 ) ;
if ( type == V_375 )
* V_21 ++ = F_46 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_428 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_428 ) ) ;
break;
case F_18 ( struct V_383 , V_379 ) :
F_15 ( F_16 ( struct V_1 , V_429 ) != 4 ) ;
if ( type == V_375 )
* V_21 ++ = F_46 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_429 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_429 ) ) ;
break;
case F_18 ( struct V_383 , V_377 ) :
F_15 ( F_16 ( struct V_1 , V_430 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_430 ) ) ;
break;
case F_18 ( struct V_383 , type ) :
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_431 ) ) ;
* V_21 ++ = F_20 ( V_27 , V_403 -> V_17 , V_432 ) ;
* V_21 ++ = F_20 ( V_29 , V_403 -> V_17 , V_433 ) ;
break;
case F_18 ( struct V_383 , V_44 ) :
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_1 , V_431 ) ) ;
* V_21 ++ = F_20 ( V_27 , V_403 -> V_17 , V_434 ) ;
* V_21 ++ = F_20 ( V_29 , V_403 -> V_17 , V_435 ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_240 ( enum V_363 type ,
const struct V_19 * V_403 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_404 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_403 -> V_198 ) {
case F_18 ( struct V_368 , V_51 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_232 ( struct V_50 , V_51 , 4 ,
V_404 ) ) ;
break;
default:
return F_231 ( type , V_403 , V_20 , V_14 ,
V_404 ) ;
}
return V_21 - V_20 ;
}
static T_1 F_241 ( enum V_363 type ,
const struct V_19 * V_403 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_404 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_403 -> V_198 ) {
case F_18 ( struct V_395 , V_199 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_231 , V_199 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_231 , V_199 ) ) ;
break;
case F_18 ( struct V_395 , V_374 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_231 , V_374 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_231 , V_374 ) ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_242 ( enum V_363 type ,
const struct V_19 * V_403 ,
struct V_19 * V_20 ,
struct V_76 * V_14 ,
T_1 * V_404 )
{
struct V_19 * V_21 = V_20 ;
int V_198 ;
switch ( V_403 -> V_198 ) {
case F_18 ( struct V_399 , V_400 ) ...
F_18 ( struct V_399 , V_401 [ 3 ] ) :
F_15 ( F_16 ( struct V_399 , V_400 ) !=
F_16 ( struct V_436 , V_400 ) ) ;
F_15 ( F_16 ( struct V_399 , V_437 ) !=
F_16 ( struct V_436 , V_437 ) ) ;
F_15 ( F_16 ( struct V_399 , V_401 ) !=
F_16 ( struct V_436 , V_401 ) ) ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_399 , V_400 ) ;
V_198 += F_18 ( struct V_436 , V_400 ) ;
if ( type == V_375 )
* V_21 ++ = F_46 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
V_198 ) ;
else
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_18 ,
V_198 ) ;
break;
case F_18 ( struct V_399 , V_377 ) :
F_15 ( F_16 ( struct V_416 , V_417 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 , V_417 ) ) ;
break;
case F_18 ( struct V_399 , V_372 ) :
F_15 ( F_16 ( struct V_416 , V_418 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 , V_418 ) ) ;
break;
case F_18 ( struct V_399 , V_373 ) :
F_15 ( F_16 ( struct V_416 , V_419 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 ,
V_419 ) ) ;
break;
case F_18 ( struct V_399 , V_370 [ 0 ] ) ...
F_18 ( struct V_399 , V_370 [ 3 ] ) :
#if F_238 ( V_420 )
F_15 ( F_16 ( struct V_416 ,
V_421 . V_422 [ 0 ] ) != 4 ) ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_399 , V_370 [ 0 ] ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 ,
V_421 . V_422 [ 0 ] ) +
V_198 ) ;
#else
* V_21 ++ = F_41 ( V_403 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_399 , V_371 [ 0 ] ) ...
F_18 ( struct V_399 , V_371 [ 3 ] ) :
#if F_238 ( V_420 )
F_15 ( F_16 ( struct V_416 ,
V_423 . V_422 [ 0 ] ) != 4 ) ;
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_399 , V_371 [ 0 ] ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 ,
V_423 . V_422 [ 0 ] ) +
V_198 ) ;
#else
* V_21 ++ = F_41 ( V_403 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_399 , V_424 ) :
F_15 ( F_16 ( struct V_416 , V_425 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 , V_425 ) ) ;
#ifndef F_21
* V_21 ++ = F_20 ( V_106 , V_403 -> V_17 , 16 ) ;
#endif
break;
case F_18 ( struct V_399 , V_378 ) :
F_15 ( F_16 ( struct V_416 , V_426 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_436 , V_2 ) ,
V_403 -> V_17 , V_403 -> V_18 ,
F_18 ( struct V_436 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_403 -> V_17 , V_403 -> V_17 ,
F_18 ( struct V_416 , V_426 ) ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_243 ( enum V_363 type ,
const struct V_19 * V_403 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_404 )
{
struct V_19 * V_21 = V_20 ;
int V_198 ;
switch ( V_403 -> V_198 ) {
case F_18 ( struct V_368 , V_374 ) :
V_198 = V_403 -> V_198 ;
V_198 -= F_18 ( struct V_368 , V_374 ) ;
V_198 += F_18 ( struct V_3 , V_369 ) ;
V_198 += F_18 ( struct V_193 , V_195 . V_374 ) ;
* V_21 ++ = F_17 ( F_234 ( void * ) , V_403 -> V_17 ,
V_403 -> V_18 , V_198 ) ;
break;
default:
return F_231 ( type , V_403 , V_20 , V_14 ,
V_404 ) ;
}
return V_21 - V_20 ;
}
int F_244 ( struct V_1 * V_2 )
{
int V_145 = - V_438 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_178 ) )
return - V_15 ;
V_8 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
if ( V_8 ) {
F_245 ( V_2 -> V_7 , NULL ) ;
F_69 ( V_2 , V_8 ) ;
V_145 = 0 ;
}
return V_145 ;
}
int F_246 ( struct V_1 * V_2 , struct V_37 T_8 * V_439 ,
unsigned int V_75 )
{
struct V_154 * V_152 ;
struct V_7 * V_8 ;
int V_145 = 0 ;
F_247 ( V_2 ) ;
V_8 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
if ( ! V_8 )
goto V_440;
V_145 = - V_441 ;
V_152 = V_8 -> V_14 -> V_156 ;
if ( ! V_152 )
goto V_440;
V_145 = V_152 -> V_75 ;
if ( ! V_75 )
goto V_440;
V_145 = - V_93 ;
if ( V_75 < V_152 -> V_75 )
goto V_440;
V_145 = - V_175 ;
if ( F_248 ( V_439 , V_152 -> V_8 , F_56 ( V_152 ) ) )
goto V_440;
V_145 = V_152 -> V_75 ;
V_440:
F_249 ( V_2 ) ;
return V_145 ;
}
