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
if ( V_38 -> V_122 == 0 && F_42 ( V_38 -> V_99 ) == V_116 ) {
V_21 -> V_99 = V_114 | V_54 | V_87 ;
V_81 = V_82 + V_38 -> V_121 + 1 ;
F_39 ;
break;
}
V_81 = V_82 + V_38 -> V_122 + 1 ;
V_21 -> V_99 = V_114 | F_42 ( V_38 -> V_99 ) | V_87 ;
F_39 ;
V_21 ++ ;
V_21 -> V_99 = V_114 | V_115 ;
V_81 = V_82 + V_38 -> V_121 + 1 ;
F_39 ;
break;
case V_123 | V_124 | V_26 :
* V_21 ++ = F_27 ( V_53 , V_45 ) ;
* V_21 ++ = F_43 ( V_26 , V_38 -> V_41 ) ;
* V_21 ++ = F_20 ( V_27 , V_45 , 0xf ) ;
* V_21 ++ = F_20 ( V_106 , V_45 , 2 ) ;
* V_21 ++ = F_27 ( V_67 , V_45 ) ;
* V_21 = F_27 ( V_45 , V_53 ) ;
break;
case V_125 | V_126 :
case V_125 | V_103 :
if ( F_44 ( V_38 -> V_99 ) == V_103 )
* V_21 ++ = F_45 ( V_103 , V_127 ,
0 , V_38 -> V_41 ) ;
* V_21 = F_26 () ;
break;
case V_128 :
case V_129 :
V_83 = V_38 -> V_41 * 4 + 4 ;
* V_21 = F_46 ( V_24 , V_90 , F_36 ( V_38 -> V_99 ) ==
V_128 ? V_45 : V_67 ,
- V_83 ) ;
if ( V_77 && V_77 -> V_130 -> V_131 < V_83 )
V_77 -> V_130 -> V_131 = V_83 ;
break;
case V_111 | V_132 :
case V_123 | V_132 :
V_83 = V_38 -> V_41 * 4 + 4 ;
* V_21 = F_17 ( V_24 , F_36 ( V_38 -> V_99 ) == V_111 ?
V_45 : V_67 , V_90 ,
- V_83 ) ;
break;
case V_111 | V_133 :
case V_123 | V_133 :
* V_21 = F_41 ( F_36 ( V_38 -> V_99 ) == V_111 ?
V_45 : V_67 , V_38 -> V_41 ) ;
break;
case V_134 | V_135 :
* V_21 = F_27 ( V_67 , V_45 ) ;
break;
case V_134 | V_136 :
* V_21 = F_27 ( V_45 , V_67 ) ;
break;
case V_111 | V_24 | V_137 :
case V_123 | V_24 | V_137 :
* V_21 = F_17 ( V_24 , F_36 ( V_38 -> V_99 ) == V_111 ?
V_45 : V_67 , V_46 ,
F_18 ( struct V_3 , V_75 ) ) ;
break;
case V_123 | V_112 | V_24 :
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
static int F_48 ( const struct V_37 * V_8 , int V_138 )
{
T_3 * V_139 , V_140 = 0 ;
int V_141 , V_142 = 0 ;
F_15 ( V_88 > 16 ) ;
V_139 = F_49 ( V_138 , sizeof( * V_139 ) , V_95 ) ;
if ( ! V_139 )
return - V_11 ;
memset ( V_139 , 0xff , V_138 * sizeof( * V_139 ) ) ;
for ( V_141 = 0 ; V_141 < V_138 ; V_141 ++ ) {
V_140 &= V_139 [ V_141 ] ;
switch ( V_8 [ V_141 ] . V_99 ) {
case V_128 :
case V_129 :
V_140 |= ( 1 << V_8 [ V_141 ] . V_41 ) ;
break;
case V_111 | V_132 :
case V_123 | V_132 :
if ( ! ( V_140 & ( 1 << V_8 [ V_141 ] . V_41 ) ) ) {
V_142 = - V_93 ;
goto error;
}
break;
case V_114 | V_115 :
V_139 [ V_141 + 1 + V_8 [ V_141 ] . V_41 ] &= V_140 ;
V_140 = ~ 0 ;
break;
case V_114 | V_116 | V_103 :
case V_114 | V_116 | V_102 :
case V_114 | V_119 | V_103 :
case V_114 | V_119 | V_102 :
case V_114 | V_118 | V_103 :
case V_114 | V_118 | V_102 :
case V_114 | V_117 | V_103 :
case V_114 | V_117 | V_102 :
V_139 [ V_141 + 1 + V_8 [ V_141 ] . V_122 ] &= V_140 ;
V_139 [ V_141 + 1 + V_8 [ V_141 ] . V_121 ] &= V_140 ;
V_140 = ~ 0 ;
break;
}
}
error:
F_47 ( V_139 ) ;
return V_142 ;
}
static bool F_50 ( T_3 V_143 )
{
static const bool V_144 [] = {
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
[ V_111 | V_24 | V_137 ] = true ,
[ V_111 | V_24 | V_113 ] = true ,
[ V_111 | V_32 | V_113 ] = true ,
[ V_111 | V_26 | V_113 ] = true ,
[ V_111 | V_133 ] = true ,
[ V_111 | V_132 ] = true ,
[ V_123 | V_24 | V_137 ] = true ,
[ V_123 | V_26 | V_124 ] = true ,
[ V_123 | V_133 ] = true ,
[ V_123 | V_132 ] = true ,
[ V_128 ] = true ,
[ V_129 ] = true ,
[ V_134 | V_135 ] = true ,
[ V_134 | V_136 ] = true ,
[ V_125 | V_103 ] = true ,
[ V_125 | V_126 ] = true ,
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
if ( V_143 >= F_51 ( V_144 ) )
return false ;
return V_144 [ V_143 ] ;
}
static bool F_52 ( const struct V_37 * V_8 ,
unsigned int V_138 )
{
if ( V_8 == NULL )
return false ;
if ( V_138 == 0 || V_138 > V_92 )
return false ;
return true ;
}
static int F_53 ( const struct V_37 * V_8 ,
unsigned int V_138 )
{
bool V_145 ;
int V_141 ;
for ( V_141 = 0 ; V_141 < V_138 ; V_141 ++ ) {
const struct V_37 * V_146 = & V_8 [ V_141 ] ;
if ( ! F_50 ( V_146 -> V_99 ) )
return - V_93 ;
switch ( V_146 -> V_99 ) {
case V_100 | V_108 | V_103 :
case V_100 | V_109 | V_103 :
if ( V_146 -> V_41 == 0 )
return - V_93 ;
break;
case V_100 | V_106 | V_103 :
case V_100 | V_29 | V_103 :
if ( V_146 -> V_41 >= 32 )
return - V_93 ;
break;
case V_111 | V_132 :
case V_123 | V_132 :
case V_128 :
case V_129 :
if ( V_146 -> V_41 >= V_88 )
return - V_93 ;
break;
case V_114 | V_115 :
if ( V_146 -> V_41 >= ( unsigned int ) ( V_138 - V_141 - 1 ) )
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
if ( V_141 + V_146 -> V_122 + 1 >= V_138 ||
V_141 + V_146 -> V_121 + 1 >= V_138 )
return - V_93 ;
break;
case V_111 | V_24 | V_112 :
case V_111 | V_32 | V_112 :
case V_111 | V_26 | V_112 :
V_145 = false ;
if ( F_54 ( V_146 ) & V_147 )
V_145 = true ;
if ( V_145 == false && V_146 -> V_41 >= V_42 )
return - V_93 ;
}
}
switch ( V_8 [ V_138 - 1 ] . V_99 ) {
case V_125 | V_103 :
case V_125 | V_126 :
return F_48 ( V_8 , V_138 ) ;
}
return - V_93 ;
}
static int F_55 ( struct V_76 * V_38 ,
const struct V_148 * V_149 )
{
unsigned int V_150 = F_56 ( V_149 ) ;
struct V_151 * V_152 ;
V_38 -> V_153 = F_57 ( sizeof( * V_152 ) , V_95 ) ;
if ( ! V_38 -> V_153 )
return - V_11 ;
V_152 = V_38 -> V_153 ;
V_152 -> V_75 = V_149 -> V_75 ;
V_152 -> V_8 = F_58 ( V_38 -> V_154 , V_150 ,
V_95 | V_96 ) ;
if ( ! V_152 -> V_8 ) {
F_47 ( V_38 -> V_153 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_59 ( struct V_76 * V_38 )
{
struct V_151 * V_149 = V_38 -> V_153 ;
if ( V_149 ) {
F_47 ( V_149 -> V_8 ) ;
F_47 ( V_149 ) ;
}
}
static void F_60 ( struct V_76 * V_14 )
{
if ( V_14 -> type == V_155 ) {
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
static void F_64 ( struct V_156 * V_157 )
{
struct V_7 * V_38 = F_65 ( V_157 , struct V_7 , V_157 ) ;
F_63 ( V_38 ) ;
}
static void F_66 ( struct V_7 * V_38 )
{
if ( F_67 ( & V_38 -> V_158 ) )
F_68 ( & V_38 -> V_157 , F_64 ) ;
}
void F_69 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
T_1 V_159 = F_70 ( V_38 -> V_14 -> V_75 ) ;
F_71 ( V_159 , & V_2 -> V_160 ) ;
F_66 ( V_38 ) ;
}
static bool F_72 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
T_1 V_159 = F_70 ( V_38 -> V_14 -> V_75 ) ;
if ( V_159 <= V_161 &&
F_73 ( & V_2 -> V_160 ) + V_159 < V_161 ) {
F_74 ( V_159 , & V_2 -> V_160 ) ;
return true ;
}
return false ;
}
bool F_75 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
bool V_142 = F_72 ( V_2 , V_38 ) ;
if ( V_142 )
F_76 ( & V_38 -> V_158 ) ;
return V_142 ;
}
static struct V_76 * F_77 ( struct V_76 * V_38 )
{
struct V_37 * V_162 ;
struct V_76 * V_163 ;
int V_6 , V_78 , V_164 = V_38 -> V_75 ;
F_15 ( sizeof( struct V_37 ) !=
sizeof( struct V_19 ) ) ;
V_162 = F_58 ( V_38 -> V_154 , V_164 * sizeof( struct V_37 ) ,
V_95 | V_96 ) ;
if ( ! V_162 ) {
V_6 = - V_11 ;
goto V_165;
}
V_6 = F_33 ( V_162 , V_164 , NULL , & V_78 ) ;
if ( V_6 )
goto V_166;
V_163 = V_38 ;
V_38 = F_78 ( V_163 , F_70 ( V_78 ) , 0 ) ;
if ( ! V_38 ) {
V_38 = V_163 ;
V_6 = - V_11 ;
goto V_166;
}
V_38 -> V_75 = V_78 ;
V_6 = F_33 ( V_162 , V_164 , V_38 , & V_78 ) ;
if ( V_6 )
goto V_166;
V_38 = F_79 ( V_38 , & V_6 ) ;
F_47 ( V_162 ) ;
return V_38 ;
V_166:
F_47 ( V_162 ) ;
V_165:
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
static struct V_76 * F_81 ( struct V_76 * V_38 ,
T_4 V_167 )
{
int V_6 ;
V_38 -> V_168 = NULL ;
V_38 -> V_169 = 0 ;
V_6 = F_53 ( V_38 -> V_154 , V_38 -> V_75 ) ;
if ( V_6 ) {
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
if ( V_167 ) {
V_6 = V_167 ( V_38 -> V_154 , V_38 -> V_75 ) ;
if ( V_6 ) {
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
}
F_82 ( V_38 ) ;
if ( ! V_38 -> V_169 )
V_38 = F_77 ( V_38 ) ;
return V_38 ;
}
int F_83 ( struct V_76 * * V_170 , struct V_151 * V_149 )
{
unsigned int V_150 = F_56 ( V_149 ) ;
struct V_76 * V_38 ;
if ( ! F_52 ( V_149 -> V_8 , V_149 -> V_75 ) )
return - V_93 ;
V_38 = F_84 ( F_70 ( V_149 -> V_75 ) , 0 ) ;
if ( ! V_38 )
return - V_11 ;
memcpy ( V_38 -> V_154 , V_149 -> V_8 , V_150 ) ;
V_38 -> V_75 = V_149 -> V_75 ;
V_38 -> V_153 = NULL ;
V_38 = F_81 ( V_38 , NULL ) ;
if ( F_85 ( V_38 ) )
return F_86 ( V_38 ) ;
* V_170 = V_38 ;
return 0 ;
}
int F_87 ( struct V_76 * * V_170 , struct V_148 * V_149 ,
T_4 V_167 , bool V_171 )
{
unsigned int V_150 = F_56 ( V_149 ) ;
struct V_76 * V_38 ;
int V_6 ;
if ( ! F_52 ( V_149 -> V_8 , V_149 -> V_75 ) )
return - V_93 ;
V_38 = F_84 ( F_70 ( V_149 -> V_75 ) , 0 ) ;
if ( ! V_38 )
return - V_11 ;
if ( F_88 ( V_38 -> V_154 , V_149 -> V_8 , V_150 ) ) {
F_89 ( V_38 ) ;
return - V_172 ;
}
V_38 -> V_75 = V_149 -> V_75 ;
V_38 -> V_153 = NULL ;
if ( V_171 ) {
V_6 = F_55 ( V_38 , V_149 ) ;
if ( V_6 ) {
F_89 ( V_38 ) ;
return - V_11 ;
}
}
V_38 = F_81 ( V_38 , V_167 ) ;
if ( F_85 ( V_38 ) )
return F_86 ( V_38 ) ;
* V_170 = V_38 ;
return 0 ;
}
void F_90 ( struct V_76 * V_38 )
{
F_60 ( V_38 ) ;
}
static int F_91 ( struct V_76 * V_14 , struct V_1 * V_2 )
{
struct V_7 * V_38 , * V_163 ;
V_38 = F_57 ( sizeof( * V_38 ) , V_95 ) ;
if ( ! V_38 )
return - V_11 ;
V_38 -> V_14 = V_14 ;
if ( ! F_72 ( V_2 , V_38 ) ) {
F_47 ( V_38 ) ;
return - V_11 ;
}
F_92 ( & V_38 -> V_158 , 1 ) ;
V_163 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
F_95 ( V_2 -> V_7 , V_38 ) ;
if ( V_163 )
F_69 ( V_2 , V_163 ) ;
return 0 ;
}
static int F_96 ( struct V_76 * V_14 , struct V_1 * V_2 )
{
struct V_76 * V_162 ;
int V_6 ;
if ( F_70 ( V_14 -> V_75 ) > V_161 )
return - V_11 ;
if ( F_97 ( V_2 ) && V_2 -> V_173 ) {
V_6 = F_98 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_99 ( V_2 -> V_174 ) ) {
return - V_93 ;
}
V_162 = F_100 ( V_2 , V_14 ) ;
if ( V_162 )
F_90 ( V_162 ) ;
return 0 ;
}
static
struct V_76 * F_101 ( struct V_148 * V_149 , struct V_1 * V_2 )
{
unsigned int V_150 = F_56 ( V_149 ) ;
struct V_76 * V_14 ;
int V_6 ;
if ( F_3 ( V_2 , V_175 ) )
return F_80 ( - V_15 ) ;
if ( ! F_52 ( V_149 -> V_8 , V_149 -> V_75 ) )
return F_80 ( - V_93 ) ;
V_14 = F_84 ( F_70 ( V_149 -> V_75 ) , 0 ) ;
if ( ! V_14 )
return F_80 ( - V_11 ) ;
if ( F_88 ( V_14 -> V_154 , V_149 -> V_8 , V_150 ) ) {
F_89 ( V_14 ) ;
return F_80 ( - V_172 ) ;
}
V_14 -> V_75 = V_149 -> V_75 ;
V_6 = F_55 ( V_14 , V_149 ) ;
if ( V_6 ) {
F_89 ( V_14 ) ;
return F_80 ( - V_11 ) ;
}
return F_81 ( V_14 , NULL ) ;
}
int F_102 ( struct V_148 * V_149 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_101 ( V_149 , V_2 ) ;
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
int F_103 ( struct V_148 * V_149 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_101 ( V_149 , V_2 ) ;
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
static struct V_76 * F_104 ( T_1 V_176 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_175 ) )
return F_80 ( - V_15 ) ;
return F_105 ( V_176 , V_155 ) ;
}
int F_106 ( T_1 V_176 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_104 ( V_176 , V_2 ) ;
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
int F_107 ( T_1 V_176 , struct V_1 * V_2 )
{
struct V_76 * V_14 = F_104 ( V_176 , V_2 ) ;
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
unsigned int V_177 )
{
return F_109 ( V_4 , V_177 ) ;
}
static inline int F_110 ( struct V_3 * V_4 ,
unsigned int V_177 )
{
int V_6 = F_108 ( V_4 , V_177 ) ;
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
F_116 ( V_4 , F_117 ( V_4 ) , V_4 -> V_178 ) ;
}
static inline void F_118 ( struct V_3 * V_4 )
{
if ( F_115 ( V_4 ) )
F_119 ( V_4 , F_117 ( V_4 ) , V_4 -> V_178 ) ;
}
static inline int F_120 ( struct V_50 * V_52 , struct V_3 * V_4 )
{
return F_121 ( V_52 , V_4 ) ;
}
static inline int F_122 ( struct V_50 * V_52 ,
struct V_3 * V_4 )
{
int V_142 = F_123 ( V_52 , V_4 ) ;
if ( F_124 ( ! V_142 ) ) {
V_4 -> V_52 = V_52 ;
V_142 = F_125 ( V_4 ) ;
}
return V_142 ;
}
static inline int F_126 ( struct V_50 * V_52 , struct V_3 * V_4 )
{
int V_142 ;
if ( F_127 ( F_128 ( V_179 ) > V_180 ) ) {
F_129 ( L_1 ) ;
F_130 ( V_4 ) ;
return - V_181 ;
}
V_4 -> V_52 = V_52 ;
F_131 ( V_179 ) ;
V_142 = F_132 ( V_4 ) ;
F_133 ( V_179 ) ;
return V_142 ;
}
static int F_134 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_182 )
{
unsigned int V_183 = V_4 -> V_184 - V_4 -> V_185 ;
F_135 ( V_4 , V_183 ) ;
if ( ! F_115 ( V_4 ) )
F_119 ( V_4 , F_117 ( V_4 ) , V_183 ) ;
F_136 ( V_4 ) ;
F_137 ( V_4 ) ;
return V_182 & V_186 ?
F_122 ( V_52 , V_4 ) : F_126 ( V_52 , V_4 ) ;
}
static int F_138 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_182 )
{
if ( F_127 ( V_4 -> V_185 >= V_4 -> V_184 ) ) {
F_130 ( V_4 ) ;
return - V_187 ;
}
F_114 ( V_4 ) ;
return V_182 & V_186 ?
F_120 ( V_52 , V_4 ) : F_126 ( V_52 , V_4 ) ;
}
static int F_139 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_182 )
{
if ( F_140 ( V_52 ) )
return F_138 ( V_4 , V_52 , V_182 ) ;
else
return F_134 ( V_4 , V_52 , V_182 ) ;
}
int F_141 ( struct V_3 * V_4 )
{
struct V_188 * V_189 = F_142 ( & V_188 ) ;
struct V_50 * V_52 ;
V_52 = F_143 ( F_144 ( V_4 -> V_52 ) , V_189 -> V_51 ) ;
V_189 -> V_51 = 0 ;
if ( F_127 ( ! V_52 ) ) {
F_130 ( V_4 ) ;
return - V_93 ;
}
return F_139 ( V_4 , V_52 , V_189 -> V_182 ) ;
}
static int F_145 ( struct V_3 * V_4 , T_1 V_190 , T_1 V_75 )
{
F_146 ( V_4 , V_75 ) ;
memmove ( V_4 -> V_191 , V_4 -> V_191 + V_75 , V_190 ) ;
memset ( V_4 -> V_191 + V_190 , 0 , V_75 ) ;
return 0 ;
}
static int F_147 ( struct V_3 * V_4 , T_1 V_190 , T_1 V_75 )
{
if ( F_127 ( ! F_148 ( V_4 , V_190 + V_75 ) ) )
return - V_11 ;
F_119 ( V_4 , V_4 -> V_191 + V_190 , V_75 ) ;
memmove ( V_4 -> V_191 + V_75 , V_4 -> V_191 , V_190 ) ;
F_135 ( V_4 , V_75 ) ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 , T_1 V_190 , T_1 V_75 )
{
bool V_192 = V_4 -> V_193 == V_4 -> V_184 ;
int V_142 ;
V_142 = F_145 ( V_4 , V_190 , V_75 ) ;
if ( F_124 ( ! V_142 ) ) {
V_4 -> V_185 -= V_75 ;
V_4 -> V_184 -= V_75 ;
if ( V_192 )
V_4 -> V_193 = V_4 -> V_184 ;
}
return V_142 ;
}
static int F_150 ( struct V_3 * V_4 , T_1 V_190 , T_1 V_75 )
{
bool V_192 = V_4 -> V_193 == V_4 -> V_184 ;
int V_142 ;
V_142 = F_147 ( V_4 , V_190 , V_75 ) ;
if ( F_124 ( ! V_142 ) ) {
V_4 -> V_185 += V_75 ;
V_4 -> V_184 += V_75 ;
if ( V_192 )
V_4 -> V_193 = V_4 -> V_184 ;
}
return V_142 ;
}
static int F_151 ( struct V_3 * V_4 )
{
const T_1 V_194 = sizeof( struct V_195 ) - sizeof( struct V_196 ) ;
T_1 V_190 = F_152 ( V_4 ) ;
int V_142 ;
V_142 = F_153 ( V_4 , V_194 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
V_142 = F_149 ( V_4 , V_190 , V_194 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
if ( F_154 ( V_4 ) ) {
if ( F_155 ( V_4 ) -> V_197 & V_198 ) {
F_155 ( V_4 ) -> V_197 &= ~ V_198 ;
F_155 ( V_4 ) -> V_197 |= V_199 ;
}
F_155 ( V_4 ) -> V_200 -= V_194 ;
F_155 ( V_4 ) -> V_197 |= V_201 ;
F_155 ( V_4 ) -> V_202 = 0 ;
}
V_4 -> V_44 = F_156 ( V_203 ) ;
F_157 ( V_4 ) ;
return 0 ;
}
static int F_158 ( struct V_3 * V_4 )
{
const T_1 V_194 = sizeof( struct V_195 ) - sizeof( struct V_196 ) ;
T_1 V_190 = F_152 ( V_4 ) ;
int V_142 ;
V_142 = F_159 ( V_4 , V_204 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
V_142 = F_150 ( V_4 , V_190 , V_194 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
if ( F_154 ( V_4 ) ) {
if ( F_155 ( V_4 ) -> V_197 & V_199 ) {
F_155 ( V_4 ) -> V_197 &= ~ V_199 ;
F_155 ( V_4 ) -> V_197 |= V_198 ;
}
F_155 ( V_4 ) -> V_200 += V_194 ;
F_155 ( V_4 ) -> V_197 |= V_201 ;
F_155 ( V_4 ) -> V_202 = 0 ;
}
V_4 -> V_44 = F_156 ( V_205 ) ;
F_157 ( V_4 ) ;
return 0 ;
}
static int F_160 ( struct V_3 * V_4 , T_5 V_206 )
{
T_5 V_207 = V_4 -> V_44 ;
if ( V_207 == F_156 ( V_205 ) &&
V_206 == F_156 ( V_203 ) )
return F_151 ( V_4 ) ;
if ( V_207 == F_156 ( V_203 ) &&
V_206 == F_156 ( V_205 ) )
return F_158 ( V_4 ) ;
return - V_208 ;
}
static T_1 F_161 ( const struct V_3 * V_4 )
{
switch ( V_4 -> V_44 ) {
case F_156 ( V_205 ) :
return sizeof( struct V_196 ) ;
case F_156 ( V_203 ) :
return sizeof( struct V_195 ) ;
default:
return ~ 0U ;
}
}
static int F_162 ( struct V_3 * V_4 , T_1 V_194 )
{
T_1 V_190 = F_152 ( V_4 ) + F_161 ( V_4 ) ;
int V_142 ;
V_142 = F_153 ( V_4 , V_194 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
V_142 = F_149 ( V_4 , V_190 , V_194 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
if ( F_154 ( V_4 ) ) {
F_155 ( V_4 ) -> V_200 -= V_194 ;
F_155 ( V_4 ) -> V_197 |= V_201 ;
F_155 ( V_4 ) -> V_202 = 0 ;
}
return 0 ;
}
static int F_163 ( struct V_3 * V_4 , T_1 V_194 )
{
T_1 V_190 = F_152 ( V_4 ) + F_161 ( V_4 ) ;
int V_142 ;
V_142 = F_159 ( V_4 , V_204 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
V_142 = F_150 ( V_4 , V_190 , V_194 ) ;
if ( F_127 ( V_142 < 0 ) )
return V_142 ;
if ( F_154 ( V_4 ) ) {
F_155 ( V_4 ) -> V_200 += V_194 ;
F_155 ( V_4 ) -> V_197 |= V_201 ;
F_155 ( V_4 ) -> V_202 = 0 ;
}
return 0 ;
}
static T_1 F_164 ( const struct V_3 * V_4 )
{
return V_4 -> V_52 -> V_209 + V_4 -> V_52 -> V_210 ;
}
static int F_165 ( struct V_3 * V_4 , T_6 V_194 )
{
bool V_192 = V_4 -> V_193 == V_4 -> V_184 ;
T_1 V_211 , V_212 = abs ( V_194 ) ;
T_1 V_213 = F_161 ( V_4 ) ;
T_1 V_214 = F_164 ( V_4 ) ;
T_5 V_215 = V_4 -> V_44 ;
bool V_216 = V_194 < 0 ;
int V_142 ;
if ( F_127 ( V_212 > 0xfffU ) )
return - V_172 ;
if ( F_127 ( V_215 != F_156 ( V_205 ) &&
V_215 != F_156 ( V_203 ) ) )
return - V_208 ;
V_211 = V_4 -> V_75 - F_166 ( V_4 ) ;
if ( F_167 ( V_4 ) && ! V_192 )
V_211 = F_168 ( V_4 ) ;
if ( ( V_216 && ( V_212 >= V_211 ||
V_211 - V_212 < V_213 ) ) ||
( ! V_216 && ( V_4 -> V_75 + V_212 > V_214 &&
! F_154 ( V_4 ) ) ) )
return - V_208 ;
V_142 = V_216 ? F_163 ( V_4 , V_212 ) :
F_162 ( V_4 , V_212 ) ;
F_111 ( V_4 ) ;
return V_142 ;
}
static T_1 F_169 ( const struct V_3 * V_4 )
{
T_1 V_217 = F_166 ( V_4 ) ;
if ( F_167 ( V_4 ) )
V_217 = F_170 ( V_4 ) ;
if ( V_4 -> V_218 == V_219 )
V_217 = F_171 ( V_4 ) +
V_4 -> V_220 + sizeof( V_221 ) ;
return V_217 ;
}
static int F_172 ( struct V_3 * V_4 , unsigned int V_78 )
{
unsigned int V_164 = V_4 -> V_75 ;
int V_142 ;
V_142 = F_173 ( V_4 , V_78 ) ;
if ( ! V_142 )
memset ( V_4 -> V_191 + V_164 , 0 , V_78 - V_164 ) ;
return V_142 ;
}
static int F_174 ( struct V_3 * V_4 , unsigned int V_78 )
{
return F_175 ( V_4 , V_78 ) ;
}
bool F_176 ( void * V_222 )
{
if ( V_222 == V_223 ||
V_222 == V_224 ||
V_222 == V_225 ||
V_222 == V_226 ||
V_222 == V_227 ||
V_222 == V_228 ||
V_222 == V_229 ||
V_222 == V_230 ||
V_222 == V_231 ||
V_222 == V_232 ||
V_222 == V_233 ||
V_222 == V_234 )
return true ;
return false ;
}
static unsigned long F_177 ( void * V_235 , const void * V_4 ,
unsigned long V_190 , unsigned long V_75 )
{
void * V_236 = F_178 ( V_4 , V_190 , V_75 , V_235 ) ;
if ( F_127 ( ! V_236 ) )
return V_75 ;
if ( V_236 != V_235 )
memcpy ( V_235 , V_236 , V_75 ) ;
return 0 ;
}
static unsigned short F_179 ( T_7 V_182 )
{
return V_182 & V_237 ? V_238 : V_239 ;
}
static const struct V_240 *
F_180 ( enum V_241 V_242 )
{
if ( ! V_243 ) {
V_243 = F_181 ( V_244 ,
V_245 ,
V_95 ) ;
if ( ! V_243 )
return NULL ;
}
switch ( V_242 ) {
case V_246 :
return & V_247 ;
case V_248 :
return & V_249 ;
default:
return NULL ;
}
}
static unsigned long F_182 ( void * V_235 , const void * V_250 ,
unsigned long V_190 , unsigned long V_75 )
{
memcpy ( V_235 , V_250 + V_190 , V_75 ) ;
return 0 ;
}
static const struct V_240 *
F_183 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_252 :
return & V_253 ;
case V_254 :
return & V_255 ;
case V_256 :
return & V_257 ;
case V_258 :
return & V_259 ;
case V_260 :
return & V_261 ;
case V_262 :
return & V_263 ;
case V_264 :
return & V_265 ;
case V_266 :
return & V_267 ;
case V_268 :
if ( F_184 ( V_269 ) )
return F_185 () ;
default:
return NULL ;
}
}
static const struct V_240 *
F_186 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_270 :
return & V_271 ;
case V_272 :
return & V_273 ;
case V_274 :
return & V_275 ;
default:
return F_183 ( V_251 ) ;
}
}
static const struct V_240 *
F_187 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_276 :
return & V_277 ;
case V_270 :
return & V_271 ;
case V_278 :
return & V_279 ;
case V_280 :
return & V_281 ;
case V_282 :
return & V_283 ;
case V_284 :
return & V_285 ;
case V_286 :
return & V_287 ;
case V_288 :
return & V_289 ;
case V_290 :
return & V_291 ;
case V_292 :
return & V_293 ;
case V_294 :
return & V_295 ;
case V_296 :
return & V_297 ;
case V_298 :
return & V_299 ;
case V_300 :
return & V_301 ;
case V_302 :
return & V_303 ;
case V_304 :
return & V_305 ;
case V_246 :
return F_180 ( V_251 ) ;
case V_306 :
return & V_307 ;
case V_248 :
return F_180 ( V_251 ) ;
case V_308 :
return & V_309 ;
case V_310 :
return & V_311 ;
case V_312 :
return & V_313 ;
case V_314 :
return & V_315 ;
case V_316 :
return & V_317 ;
case V_318 :
return & V_319 ;
case V_260 :
return & V_320 ;
case V_321 :
return & V_322 ;
case V_272 :
return & V_273 ;
case V_274 :
return & V_275 ;
default:
return F_183 ( V_251 ) ;
}
}
static const struct V_240 *
F_188 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_318 :
return & V_323 ;
case V_260 :
return & V_320 ;
case V_324 :
return & V_325 ;
default:
return F_183 ( V_251 ) ;
}
}
static const struct V_240 *
F_189 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_270 :
return & V_271 ;
case V_278 :
return & V_279 ;
case V_280 :
return & V_281 ;
case V_290 :
return & V_291 ;
case V_310 :
return & V_311 ;
case V_312 :
return & V_313 ;
case V_318 :
return & V_319 ;
case V_260 :
return & V_320 ;
case V_321 :
return & V_322 ;
default:
return F_183 ( V_251 ) ;
}
}
static const struct V_240 *
F_190 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_326 :
return & V_327 ;
default:
return F_183 ( V_251 ) ;
}
}
static const struct V_240 *
F_191 ( enum V_241 V_251 )
{
switch ( V_251 ) {
case V_304 :
return & V_305 ;
case V_246 :
return F_180 ( V_251 ) ;
case V_306 :
return & V_307 ;
case V_248 :
return F_180 ( V_251 ) ;
case V_308 :
return & V_309 ;
case V_288 :
return & V_289 ;
case V_302 :
return & V_303 ;
case V_328 :
return & V_329 ;
case V_276 :
return & V_277 ;
case V_282 :
return & V_283 ;
case V_284 :
return & V_285 ;
case V_286 :
return & V_287 ;
case V_314 :
return & V_315 ;
default:
return F_189 ( V_251 ) ;
}
}
static bool F_192 ( int V_190 , int V_330 , enum V_331 type ,
struct V_332 * V_333 )
{
const int V_334 = sizeof( V_335 ) ;
if ( V_190 < 0 || V_190 >= sizeof( struct V_336 ) )
return false ;
if ( V_190 % V_330 != 0 )
return false ;
switch ( V_190 ) {
case F_193 ( struct V_336 , V_337 [ 0 ] , V_337 [ 4 ] ) :
if ( V_190 + V_330 > F_194 ( struct V_336 , V_337 [ 4 ] ) )
return false ;
break;
case F_195 ( struct V_336 , V_191 ) :
case F_195 ( struct V_336 , V_338 ) :
if ( V_330 != V_334 )
return false ;
break;
default:
if ( type == V_339 ) {
if ( V_330 != V_334 )
return false ;
} else {
F_196 ( V_333 , V_334 ) ;
if ( ! F_197 ( V_190 , V_330 , V_334 ) )
return false ;
}
}
return true ;
}
static bool F_198 ( int V_190 , int V_330 ,
enum V_331 type ,
struct V_332 * V_333 )
{
switch ( V_190 ) {
case F_195 ( struct V_336 , V_340 ) :
case F_195 ( struct V_336 , V_191 ) :
case F_195 ( struct V_336 , V_338 ) :
return false ;
}
if ( type == V_339 ) {
switch ( V_190 ) {
case F_193 ( struct V_336 , V_337 [ 0 ] , V_337 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_192 ( V_190 , V_330 , type , V_333 ) ;
}
static bool F_199 ( int V_190 , int V_330 ,
enum V_331 type ,
struct V_332 * V_333 )
{
switch ( V_190 ) {
case F_195 ( struct V_336 , V_340 ) :
return false ;
}
if ( type == V_339 ) {
switch ( V_190 ) {
case F_195 ( struct V_336 , V_23 ) :
case F_195 ( struct V_336 , V_341 ) :
case F_193 ( struct V_336 , V_337 [ 0 ] , V_337 [ 4 ] ) :
break;
default:
return false ;
}
}
switch ( V_190 ) {
case F_195 ( struct V_336 , V_191 ) :
V_333 -> V_342 = V_343 ;
break;
case F_195 ( struct V_336 , V_338 ) :
V_333 -> V_342 = V_344 ;
break;
}
return F_192 ( V_190 , V_330 , type , V_333 ) ;
}
static bool F_200 ( int V_190 , int V_330 ,
enum V_331 type ,
struct V_332 * V_333 )
{
if ( type == V_339 ) {
switch ( V_190 ) {
case F_18 ( struct V_345 , V_346 ) :
break;
default:
return false ;
}
}
if ( V_190 < 0 || V_190 + V_330 > sizeof( struct V_345 ) )
return false ;
if ( V_190 % V_330 != 0 )
return false ;
if ( V_330 != sizeof( V_335 ) )
return false ;
return true ;
}
static int F_201 ( struct V_19 * V_20 , bool V_347 ,
const struct V_76 * V_14 )
{
struct V_19 * V_21 = V_20 ;
if ( ! V_347 )
return 0 ;
* V_21 ++ = F_17 ( V_26 , V_348 , V_349 , F_202 () ) ;
* V_21 ++ = F_20 ( V_27 , V_348 , V_350 ) ;
* V_21 ++ = F_25 ( V_116 , V_348 , 0 , 7 ) ;
* V_21 ++ = F_27 ( V_348 , V_349 ) ;
* V_21 ++ = F_35 ( V_74 , V_351 , V_351 ) ;
* V_21 ++ = F_38 ( V_114 | V_352 , 0 , 0 , 0 ,
V_278 ) ;
* V_21 ++ = F_25 ( V_116 , V_127 , 0 , 2 ) ;
* V_21 ++ = F_20 ( V_353 , V_127 , V_354 ) ;
* V_21 ++ = F_26 () ;
* V_21 ++ = F_27 ( V_349 , V_348 ) ;
* V_21 ++ = V_14 -> V_94 [ 0 ] ;
return V_21 - V_20 ;
}
static bool F_203 ( int V_190 , int V_330 ,
enum V_331 type ,
struct V_332 * V_333 )
{
if ( type == V_339 ) {
switch ( V_190 ) {
case F_195 ( struct V_336 , V_23 ) :
case F_195 ( struct V_336 , V_355 ) :
case F_195 ( struct V_336 , V_341 ) :
case F_195 ( struct V_336 , V_340 ) :
case F_193 ( struct V_336 , V_337 [ 0 ] , V_337 [ 4 ] ) :
break;
default:
return false ;
}
}
switch ( V_190 ) {
case F_195 ( struct V_336 , V_191 ) :
V_333 -> V_342 = V_343 ;
break;
case F_195 ( struct V_336 , V_338 ) :
V_333 -> V_342 = V_344 ;
break;
}
return F_192 ( V_190 , V_330 , type , V_333 ) ;
}
static bool F_204 ( int V_190 , int V_330 )
{
if ( V_190 < 0 || V_190 >= sizeof( struct V_356 ) )
return false ;
if ( V_190 % V_330 != 0 )
return false ;
if ( V_330 != sizeof( V_335 ) )
return false ;
return true ;
}
static bool F_205 ( int V_190 , int V_330 ,
enum V_331 type ,
struct V_332 * V_333 )
{
if ( type == V_339 )
return false ;
switch ( V_190 ) {
case F_18 ( struct V_356 , V_191 ) :
V_333 -> V_342 = V_343 ;
break;
case F_18 ( struct V_356 , V_338 ) :
V_333 -> V_342 = V_344 ;
break;
}
return F_204 ( V_190 , V_330 ) ;
}
void F_206 ( T_1 V_357 )
{
F_207 ( 1 , L_2 , V_357 ) ;
}
static bool F_208 ( int V_190 , int V_330 )
{
if ( V_190 < 0 || V_190 >= sizeof( struct V_358 ) )
return false ;
if ( V_190 % V_330 != 0 )
return false ;
if ( V_330 != sizeof( V_335 ) )
return false ;
return true ;
}
static bool F_209 ( int V_190 , int V_330 ,
enum V_331 type ,
struct V_332 * V_333 )
{
if ( type == V_339 ) {
switch ( V_190 ) {
case F_18 ( struct V_358 , V_359 ) ...
F_18 ( struct V_358 , V_360 [ 3 ] ) :
break;
default:
return false ;
}
}
return F_208 ( V_190 , V_330 ) ;
}
static T_1 F_210 ( enum V_331 type ,
const struct V_19 * V_361 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_362 )
{
struct V_19 * V_21 = V_20 ;
int V_190 ;
switch ( V_361 -> V_190 ) {
case F_18 ( struct V_336 , V_75 ) :
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_75 , 4 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_44 ) :
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_44 , 2 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_58 ) :
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_58 , 2 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_341 ) :
if ( type == V_339 )
* V_21 ++ = F_46 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_341 , 4 ,
V_362 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_341 , 4 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_363 ) :
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_364 , 4 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_51 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_25 ( V_116 , V_361 -> V_17 , 0 , 1 ) ;
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_17 ,
F_211 ( struct V_50 , V_51 , 4 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_56 ) :
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_56 , 4 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_23 ) :
if ( type == V_339 )
* V_21 ++ = F_46 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_23 , 4 ,
V_362 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_23 , 4 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_365 ) :
* V_362 = 1 ;
* V_21 ++ = F_17 ( V_26 , V_361 -> V_17 , V_361 -> V_18 ,
F_19 () ) ;
* V_21 ++ = F_20 ( V_27 , V_361 -> V_17 , V_28 ) ;
#ifdef F_21
* V_21 ++ = F_20 ( V_29 , V_361 -> V_17 , 5 ) ;
#endif
break;
case F_18 ( struct V_336 , V_31 ) :
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_31 , 2 ,
V_362 ) ) ;
break;
case F_18 ( struct V_336 , V_366 ) :
case F_18 ( struct V_336 , V_35 ) :
F_15 ( V_36 != 0x1000 ) ;
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_35 , 2 ,
V_362 ) ) ;
if ( V_361 -> V_190 == F_18 ( struct V_336 , V_35 ) ) {
* V_21 ++ = F_20 ( V_27 , V_361 -> V_17 ,
~ V_36 ) ;
} else {
* V_21 ++ = F_20 ( V_29 , V_361 -> V_17 , 12 ) ;
* V_21 ++ = F_20 ( V_27 , V_361 -> V_17 , 1 ) ;
}
break;
case F_18 ( struct V_336 , V_337 [ 0 ] ) ...
F_194 ( struct V_336 , V_337 [ 4 ] ) - 1 :
F_15 ( F_16 ( struct V_367 , V_191 ) < 20 ) ;
F_15 ( ( F_18 ( struct V_3 , V_337 ) +
F_18 ( struct V_367 , V_191 ) ) %
sizeof( V_368 ) ) ;
V_14 -> V_369 = 1 ;
V_190 = V_361 -> V_190 ;
V_190 -= F_18 ( struct V_336 , V_337 [ 0 ] ) ;
V_190 += F_18 ( struct V_3 , V_337 ) ;
V_190 += F_18 ( struct V_367 , V_191 ) ;
if ( type == V_339 )
* V_21 ++ = F_46 ( F_212 ( V_361 -> V_99 ) , V_361 -> V_17 ,
V_361 -> V_18 , V_190 ) ;
else
* V_21 ++ = F_17 ( F_212 ( V_361 -> V_99 ) , V_361 -> V_17 ,
V_361 -> V_18 , V_190 ) ;
break;
case F_18 ( struct V_336 , V_340 ) :
F_15 ( F_16 ( struct V_367 , V_340 ) != 2 ) ;
V_190 = V_361 -> V_190 ;
V_190 -= F_18 ( struct V_336 , V_340 ) ;
V_190 += F_18 ( struct V_3 , V_337 ) ;
V_190 += F_18 ( struct V_367 , V_340 ) ;
* V_362 = 2 ;
if ( type == V_339 )
* V_21 ++ = F_46 ( V_32 , V_361 -> V_17 ,
V_361 -> V_18 , V_190 ) ;
else
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 ,
V_361 -> V_18 , V_190 ) ;
break;
case F_18 ( struct V_336 , V_191 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_191 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_3 , V_191 ) ) ;
break;
case F_18 ( struct V_336 , V_338 ) :
V_190 = V_361 -> V_190 ;
V_190 -= F_18 ( struct V_336 , V_338 ) ;
V_190 += F_18 ( struct V_3 , V_337 ) ;
V_190 += F_18 ( struct V_370 , V_338 ) ;
* V_21 ++ = F_17 ( F_213 ( void * ) , V_361 -> V_17 ,
V_361 -> V_18 , V_190 ) ;
break;
case F_18 ( struct V_336 , V_355 ) :
#ifdef F_214
if ( type == V_339 )
* V_21 ++ = F_46 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_355 , 2 ,
V_362 ) ) ;
else
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_355 , 2 ,
V_362 ) ) ;
#else
* V_362 = 2 ;
if ( type == V_339 )
* V_21 ++ = F_27 ( V_361 -> V_17 , V_361 -> V_17 ) ;
else
* V_21 ++ = F_215 ( V_361 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_336 , V_371 ) :
#if F_216 ( V_372 )
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_211 ( struct V_3 , V_371 , 4 ,
V_362 ) ) ;
* V_21 ++ = F_25 ( V_119 , V_361 -> V_17 , V_373 , 1 ) ;
* V_21 ++ = F_215 ( V_361 -> V_17 , 0 ) ;
#else
* V_362 = 4 ;
* V_21 ++ = F_215 ( V_361 -> V_17 , 0 ) ;
#endif
break;
}
return V_21 - V_20 ;
}
static T_1 F_217 ( enum V_331 type ,
const struct V_19 * V_361 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_362 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_361 -> V_190 ) {
case F_18 ( struct V_345 , V_346 ) :
F_15 ( F_16 ( struct V_1 , V_374 ) != 4 ) ;
if ( type == V_339 )
* V_21 ++ = F_46 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_1 , V_374 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_1 , V_374 ) ) ;
break;
case F_18 ( struct V_345 , V_375 ) :
F_15 ( F_16 ( struct V_1 , V_376 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_1 , V_376 ) ) ;
break;
case F_18 ( struct V_345 , type ) :
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_1 , V_377 ) ) ;
* V_21 ++ = F_20 ( V_27 , V_361 -> V_17 , V_378 ) ;
* V_21 ++ = F_20 ( V_29 , V_361 -> V_17 , V_379 ) ;
break;
case F_18 ( struct V_345 , V_44 ) :
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_1 , V_377 ) ) ;
* V_21 ++ = F_20 ( V_27 , V_361 -> V_17 , V_380 ) ;
* V_21 ++ = F_20 ( V_29 , V_361 -> V_17 , V_381 ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_218 ( enum V_331 type ,
const struct V_19 * V_361 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_362 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_361 -> V_190 ) {
case F_18 ( struct V_336 , V_51 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_17 ,
F_211 ( struct V_50 , V_51 , 4 ,
V_362 ) ) ;
break;
default:
return F_210 ( type , V_361 , V_20 , V_14 ,
V_362 ) ;
}
return V_21 - V_20 ;
}
static T_1 F_219 ( enum V_331 type ,
const struct V_19 * V_361 ,
struct V_19 * V_20 ,
struct V_76 * V_14 , T_1 * V_362 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_361 -> V_190 ) {
case F_18 ( struct V_356 , V_191 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_382 , V_191 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_382 , V_191 ) ) ;
break;
case F_18 ( struct V_356 , V_338 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_382 , V_338 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_382 , V_338 ) ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_220 ( enum V_331 type ,
const struct V_19 * V_361 ,
struct V_19 * V_20 ,
struct V_76 * V_14 ,
T_1 * V_362 )
{
struct V_19 * V_21 = V_20 ;
int V_190 ;
switch ( V_361 -> V_190 ) {
case F_18 ( struct V_358 , V_359 ) ...
F_18 ( struct V_358 , V_360 [ 3 ] ) :
F_15 ( F_16 ( struct V_358 , V_359 ) !=
F_16 ( struct V_383 , V_359 ) ) ;
F_15 ( F_16 ( struct V_358 , V_384 ) !=
F_16 ( struct V_383 , V_384 ) ) ;
F_15 ( F_16 ( struct V_358 , V_360 ) !=
F_16 ( struct V_383 , V_360 ) ) ;
V_190 = V_361 -> V_190 ;
V_190 -= F_18 ( struct V_358 , V_359 ) ;
V_190 += F_18 ( struct V_383 , V_359 ) ;
if ( type == V_339 )
* V_21 ++ = F_46 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
V_190 ) ;
else
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_18 ,
V_190 ) ;
break;
case F_18 ( struct V_358 , V_375 ) :
F_15 ( F_16 ( struct V_385 , V_386 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 , V_386 ) ) ;
break;
case F_18 ( struct V_358 , V_387 ) :
F_15 ( F_16 ( struct V_385 , V_388 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 , V_388 ) ) ;
break;
case F_18 ( struct V_358 , V_389 ) :
F_15 ( F_16 ( struct V_385 , V_390 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 ,
V_390 ) ) ;
break;
case F_18 ( struct V_358 , V_391 [ 0 ] ) ...
F_18 ( struct V_358 , V_391 [ 3 ] ) :
#if F_221 ( V_392 )
F_15 ( F_16 ( struct V_385 ,
V_393 . V_394 [ 0 ] ) != 4 ) ;
V_190 = V_361 -> V_190 ;
V_190 -= F_18 ( struct V_358 , V_391 [ 0 ] ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 ,
V_393 . V_394 [ 0 ] ) +
V_190 ) ;
#else
* V_21 ++ = F_41 ( V_361 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_358 , V_395 [ 0 ] ) ...
F_18 ( struct V_358 , V_395 [ 3 ] ) :
#if F_221 ( V_392 )
F_15 ( F_16 ( struct V_385 ,
V_396 . V_394 [ 0 ] ) != 4 ) ;
V_190 = V_361 -> V_190 ;
V_190 -= F_18 ( struct V_358 , V_395 [ 0 ] ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 ,
V_396 . V_394 [ 0 ] ) +
V_190 ) ;
#else
* V_21 ++ = F_41 ( V_361 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_358 , V_397 ) :
F_15 ( F_16 ( struct V_385 , V_398 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 , V_398 ) ) ;
#ifndef F_21
* V_21 ++ = F_20 ( V_106 , V_361 -> V_17 , 16 ) ;
#endif
break;
case F_18 ( struct V_358 , V_399 ) :
F_15 ( F_16 ( struct V_385 , V_400 ) != 2 ) ;
* V_21 ++ = F_17 ( F_24 (
struct V_383 , V_2 ) ,
V_361 -> V_17 , V_361 -> V_18 ,
F_18 ( struct V_383 , V_2 ) ) ;
* V_21 ++ = F_17 ( V_32 , V_361 -> V_17 , V_361 -> V_17 ,
F_18 ( struct V_385 , V_400 ) ) ;
break;
}
return V_21 - V_20 ;
}
int F_222 ( struct V_1 * V_2 )
{
int V_142 = - V_401 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_175 ) )
return - V_15 ;
V_8 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
if ( V_8 ) {
F_223 ( V_2 -> V_7 , NULL ) ;
F_69 ( V_2 , V_8 ) ;
V_142 = 0 ;
}
return V_142 ;
}
int F_224 ( struct V_1 * V_2 , struct V_37 T_8 * V_402 ,
unsigned int V_75 )
{
struct V_151 * V_149 ;
struct V_7 * V_8 ;
int V_142 = 0 ;
F_225 ( V_2 ) ;
V_8 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
if ( ! V_8 )
goto V_403;
V_142 = - V_404 ;
V_149 = V_8 -> V_14 -> V_153 ;
if ( ! V_149 )
goto V_403;
V_142 = V_149 -> V_75 ;
if ( ! V_75 )
goto V_403;
V_142 = - V_93 ;
if ( V_75 < V_149 -> V_75 )
goto V_403;
V_142 = - V_172 ;
if ( F_226 ( V_402 , V_149 -> V_8 , F_56 ( V_149 ) ) )
goto V_403;
V_142 = V_149 -> V_75 ;
V_403:
F_227 ( V_2 ) ;
return V_142 ;
}
