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
struct V_19 * V_76 , int * V_77 )
{
int V_78 = 0 , V_79 = 0 , V_80 , V_81 ;
struct V_19 * V_82 ;
struct V_37 * V_38 ;
int * V_83 = NULL ;
T_2 V_84 ;
F_15 ( V_85 * sizeof( T_1 ) > V_86 ) ;
F_15 ( V_87 + 1 != V_88 ) ;
if ( V_75 <= 0 || V_75 > V_89 )
return - V_90 ;
if ( V_76 ) {
V_83 = F_34 ( V_75 , sizeof( * V_83 ) ,
V_91 | V_92 ) ;
if ( ! V_83 )
return - V_11 ;
}
V_93:
V_82 = V_76 ;
V_38 = V_14 ;
if ( V_82 ) {
* V_82 ++ = F_35 ( V_74 , V_45 , V_45 ) ;
* V_82 ++ = F_35 ( V_74 , V_67 , V_67 ) ;
* V_82 ++ = F_27 ( V_46 , V_64 ) ;
} else {
V_82 += 3 ;
}
for ( V_81 = 0 ; V_81 < V_75 ; V_38 ++ , V_81 ++ ) {
struct V_19 V_94 [ 6 ] = { } ;
struct V_19 * V_21 = V_94 ;
if ( V_83 )
V_83 [ V_81 ] = V_82 - V_76 ;
switch ( V_38 -> V_95 ) {
case V_96 | V_97 | V_98 :
case V_96 | V_97 | V_99 :
case V_96 | V_100 | V_98 :
case V_96 | V_100 | V_99 :
case V_96 | V_27 | V_98 :
case V_96 | V_27 | V_99 :
case V_96 | V_101 | V_98 :
case V_96 | V_101 | V_99 :
case V_96 | V_102 | V_98 :
case V_96 | V_102 | V_99 :
case V_96 | V_29 | V_98 :
case V_96 | V_29 | V_99 :
case V_96 | V_74 | V_98 :
case V_96 | V_74 | V_99 :
case V_96 | V_103 | V_98 :
case V_96 | V_103 | V_99 :
case V_96 | V_104 | V_98 :
case V_96 | V_104 | V_99 :
case V_96 | V_105 | V_98 :
case V_96 | V_105 | V_99 :
case V_96 | V_106 :
case V_107 | V_108 | V_24 :
case V_107 | V_108 | V_32 :
case V_107 | V_108 | V_26 :
case V_107 | V_109 | V_24 :
case V_107 | V_109 | V_32 :
case V_107 | V_109 | V_26 :
if ( F_36 ( V_38 -> V_95 ) == V_107 &&
F_37 ( V_38 -> V_95 ) == V_108 &&
F_22 ( V_38 , & V_21 ) )
break;
* V_21 = F_38 ( V_38 -> V_95 , V_45 , V_67 , 0 , V_38 -> V_41 ) ;
break;
#define F_39 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_110 | V_111 :
V_80 = V_81 + V_38 -> V_41 + 1 ;
V_21 -> V_95 = V_38 -> V_95 ;
F_39 ;
break;
case V_110 | V_112 | V_99 :
case V_110 | V_112 | V_98 :
case V_110 | V_113 | V_99 :
case V_110 | V_113 | V_98 :
case V_110 | V_114 | V_99 :
case V_110 | V_114 | V_98 :
case V_110 | V_115 | V_99 :
case V_110 | V_115 | V_98 :
if ( F_40 ( V_38 -> V_95 ) == V_99 && ( int ) V_38 -> V_41 < 0 ) {
* V_21 ++ = F_41 ( V_53 , V_38 -> V_41 ) ;
V_21 -> V_17 = V_45 ;
V_21 -> V_18 = V_53 ;
V_84 = V_98 ;
} else {
V_21 -> V_17 = V_45 ;
V_21 -> V_116 = V_38 -> V_41 ;
V_84 = F_40 ( V_38 -> V_95 ) ;
V_21 -> V_18 = V_84 == V_98 ? V_67 : 0 ;
}
if ( V_38 -> V_117 == 0 ) {
V_21 -> V_95 = V_110 | F_42 ( V_38 -> V_95 ) | V_84 ;
V_80 = V_81 + V_38 -> V_118 + 1 ;
F_39 ;
break;
}
if ( V_38 -> V_118 == 0 && F_42 ( V_38 -> V_95 ) == V_112 ) {
V_21 -> V_95 = V_110 | V_54 | V_84 ;
V_80 = V_81 + V_38 -> V_117 + 1 ;
F_39 ;
break;
}
V_80 = V_81 + V_38 -> V_118 + 1 ;
V_21 -> V_95 = V_110 | F_42 ( V_38 -> V_95 ) | V_84 ;
F_39 ;
V_21 ++ ;
V_21 -> V_95 = V_110 | V_111 ;
V_80 = V_81 + V_38 -> V_117 + 1 ;
F_39 ;
break;
case V_119 | V_120 | V_26 :
* V_21 ++ = F_27 ( V_53 , V_45 ) ;
* V_21 ++ = F_43 ( V_26 , V_38 -> V_41 ) ;
* V_21 ++ = F_20 ( V_27 , V_45 , 0xf ) ;
* V_21 ++ = F_20 ( V_102 , V_45 , 2 ) ;
* V_21 ++ = F_27 ( V_67 , V_45 ) ;
* V_21 = F_27 ( V_45 , V_53 ) ;
break;
case V_121 | V_122 :
case V_121 | V_99 :
if ( F_44 ( V_38 -> V_95 ) == V_99 )
* V_21 ++ = F_45 ( V_99 , V_123 ,
0 , V_38 -> V_41 ) ;
* V_21 = F_26 () ;
break;
case V_124 :
case V_125 :
* V_21 = F_46 ( V_24 , V_87 , F_36 ( V_38 -> V_95 ) ==
V_124 ? V_45 : V_67 ,
- ( V_85 - V_38 -> V_41 ) * 4 ) ;
break;
case V_107 | V_126 :
case V_119 | V_126 :
* V_21 = F_17 ( V_24 , F_36 ( V_38 -> V_95 ) == V_107 ?
V_45 : V_67 , V_87 ,
- ( V_85 - V_38 -> V_41 ) * 4 ) ;
break;
case V_107 | V_127 :
case V_119 | V_127 :
* V_21 = F_41 ( F_36 ( V_38 -> V_95 ) == V_107 ?
V_45 : V_67 , V_38 -> V_41 ) ;
break;
case V_128 | V_129 :
* V_21 = F_27 ( V_67 , V_45 ) ;
break;
case V_128 | V_130 :
* V_21 = F_27 ( V_45 , V_67 ) ;
break;
case V_107 | V_24 | V_131 :
case V_119 | V_24 | V_131 :
* V_21 = F_17 ( V_24 , F_36 ( V_38 -> V_95 ) == V_107 ?
V_45 : V_67 , V_46 ,
F_18 ( struct V_3 , V_75 ) ) ;
break;
case V_119 | V_108 | V_24 :
* V_21 = F_17 ( V_24 , V_45 , V_46 , V_38 -> V_41 ) ;
break;
default:
goto V_6;
}
V_21 ++ ;
if ( V_76 )
memcpy ( V_82 , V_94 ,
sizeof( * V_21 ) * ( V_21 - V_94 ) ) ;
V_82 += V_21 - V_94 ;
}
if ( ! V_76 ) {
* V_77 = V_82 - V_76 ;
return 0 ;
}
V_79 ++ ;
if ( V_78 != V_82 - V_76 ) {
V_78 = V_82 - V_76 ;
if ( V_79 > 2 )
goto V_6;
goto V_93;
}
F_47 ( V_83 ) ;
F_31 ( * V_77 != V_78 ) ;
return 0 ;
V_6:
F_47 ( V_83 ) ;
return - V_90 ;
}
static int F_48 ( const struct V_37 * V_8 , int V_132 )
{
T_3 * V_133 , V_134 = 0 ;
int V_135 , V_136 = 0 ;
F_15 ( V_85 > 16 ) ;
V_133 = F_49 ( V_132 , sizeof( * V_133 ) , V_91 ) ;
if ( ! V_133 )
return - V_11 ;
memset ( V_133 , 0xff , V_132 * sizeof( * V_133 ) ) ;
for ( V_135 = 0 ; V_135 < V_132 ; V_135 ++ ) {
V_134 &= V_133 [ V_135 ] ;
switch ( V_8 [ V_135 ] . V_95 ) {
case V_124 :
case V_125 :
V_134 |= ( 1 << V_8 [ V_135 ] . V_41 ) ;
break;
case V_107 | V_126 :
case V_119 | V_126 :
if ( ! ( V_134 & ( 1 << V_8 [ V_135 ] . V_41 ) ) ) {
V_136 = - V_90 ;
goto error;
}
break;
case V_110 | V_111 :
V_133 [ V_135 + 1 + V_8 [ V_135 ] . V_41 ] &= V_134 ;
V_134 = ~ 0 ;
break;
case V_110 | V_112 | V_99 :
case V_110 | V_112 | V_98 :
case V_110 | V_115 | V_99 :
case V_110 | V_115 | V_98 :
case V_110 | V_114 | V_99 :
case V_110 | V_114 | V_98 :
case V_110 | V_113 | V_99 :
case V_110 | V_113 | V_98 :
V_133 [ V_135 + 1 + V_8 [ V_135 ] . V_118 ] &= V_134 ;
V_133 [ V_135 + 1 + V_8 [ V_135 ] . V_117 ] &= V_134 ;
V_134 = ~ 0 ;
break;
}
}
error:
F_47 ( V_133 ) ;
return V_136 ;
}
static bool F_50 ( T_3 V_137 )
{
static const bool V_138 [] = {
[ V_96 | V_97 | V_99 ] = true ,
[ V_96 | V_97 | V_98 ] = true ,
[ V_96 | V_100 | V_99 ] = true ,
[ V_96 | V_100 | V_98 ] = true ,
[ V_96 | V_103 | V_99 ] = true ,
[ V_96 | V_103 | V_98 ] = true ,
[ V_96 | V_104 | V_99 ] = true ,
[ V_96 | V_104 | V_98 ] = true ,
[ V_96 | V_105 | V_99 ] = true ,
[ V_96 | V_105 | V_98 ] = true ,
[ V_96 | V_27 | V_99 ] = true ,
[ V_96 | V_27 | V_98 ] = true ,
[ V_96 | V_101 | V_99 ] = true ,
[ V_96 | V_101 | V_98 ] = true ,
[ V_96 | V_74 | V_99 ] = true ,
[ V_96 | V_74 | V_98 ] = true ,
[ V_96 | V_102 | V_99 ] = true ,
[ V_96 | V_102 | V_98 ] = true ,
[ V_96 | V_29 | V_99 ] = true ,
[ V_96 | V_29 | V_98 ] = true ,
[ V_96 | V_106 ] = true ,
[ V_107 | V_24 | V_108 ] = true ,
[ V_107 | V_32 | V_108 ] = true ,
[ V_107 | V_26 | V_108 ] = true ,
[ V_107 | V_24 | V_131 ] = true ,
[ V_107 | V_24 | V_109 ] = true ,
[ V_107 | V_32 | V_109 ] = true ,
[ V_107 | V_26 | V_109 ] = true ,
[ V_107 | V_127 ] = true ,
[ V_107 | V_126 ] = true ,
[ V_119 | V_24 | V_131 ] = true ,
[ V_119 | V_26 | V_120 ] = true ,
[ V_119 | V_127 ] = true ,
[ V_119 | V_126 ] = true ,
[ V_124 ] = true ,
[ V_125 ] = true ,
[ V_128 | V_129 ] = true ,
[ V_128 | V_130 ] = true ,
[ V_121 | V_99 ] = true ,
[ V_121 | V_122 ] = true ,
[ V_110 | V_111 ] = true ,
[ V_110 | V_112 | V_99 ] = true ,
[ V_110 | V_112 | V_98 ] = true ,
[ V_110 | V_115 | V_99 ] = true ,
[ V_110 | V_115 | V_98 ] = true ,
[ V_110 | V_114 | V_99 ] = true ,
[ V_110 | V_114 | V_98 ] = true ,
[ V_110 | V_113 | V_99 ] = true ,
[ V_110 | V_113 | V_98 ] = true ,
} ;
if ( V_137 >= F_51 ( V_138 ) )
return false ;
return V_138 [ V_137 ] ;
}
static bool F_52 ( const struct V_37 * V_8 ,
unsigned int V_132 )
{
if ( V_8 == NULL )
return false ;
if ( V_132 == 0 || V_132 > V_89 )
return false ;
return true ;
}
static int F_53 ( const struct V_37 * V_8 ,
unsigned int V_132 )
{
bool V_139 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_132 ; V_135 ++ ) {
const struct V_37 * V_140 = & V_8 [ V_135 ] ;
if ( ! F_50 ( V_140 -> V_95 ) )
return - V_90 ;
switch ( V_140 -> V_95 ) {
case V_96 | V_104 | V_99 :
case V_96 | V_105 | V_99 :
if ( V_140 -> V_41 == 0 )
return - V_90 ;
break;
case V_96 | V_102 | V_99 :
case V_96 | V_29 | V_99 :
if ( V_140 -> V_41 >= 32 )
return - V_90 ;
break;
case V_107 | V_126 :
case V_119 | V_126 :
case V_124 :
case V_125 :
if ( V_140 -> V_41 >= V_85 )
return - V_90 ;
break;
case V_110 | V_111 :
if ( V_140 -> V_41 >= ( unsigned int ) ( V_132 - V_135 - 1 ) )
return - V_90 ;
break;
case V_110 | V_112 | V_99 :
case V_110 | V_112 | V_98 :
case V_110 | V_115 | V_99 :
case V_110 | V_115 | V_98 :
case V_110 | V_114 | V_99 :
case V_110 | V_114 | V_98 :
case V_110 | V_113 | V_99 :
case V_110 | V_113 | V_98 :
if ( V_135 + V_140 -> V_118 + 1 >= V_132 ||
V_135 + V_140 -> V_117 + 1 >= V_132 )
return - V_90 ;
break;
case V_107 | V_24 | V_108 :
case V_107 | V_32 | V_108 :
case V_107 | V_26 | V_108 :
V_139 = false ;
if ( F_54 ( V_140 ) & V_141 )
V_139 = true ;
if ( V_139 == false && V_140 -> V_41 >= V_42 )
return - V_90 ;
}
}
switch ( V_8 [ V_132 - 1 ] . V_95 ) {
case V_121 | V_99 :
case V_121 | V_122 :
return F_48 ( V_8 , V_132 ) ;
}
return - V_90 ;
}
static int F_55 ( struct V_142 * V_38 ,
const struct V_143 * V_144 )
{
unsigned int V_145 = F_56 ( V_144 ) ;
struct V_146 * V_147 ;
V_38 -> V_148 = F_57 ( sizeof( * V_147 ) , V_91 ) ;
if ( ! V_38 -> V_148 )
return - V_11 ;
V_147 = V_38 -> V_148 ;
V_147 -> V_75 = V_144 -> V_75 ;
V_147 -> V_8 = F_58 ( V_38 -> V_149 , V_145 ,
V_91 | V_92 ) ;
if ( ! V_147 -> V_8 ) {
F_47 ( V_38 -> V_148 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_59 ( struct V_142 * V_38 )
{
struct V_146 * V_144 = V_38 -> V_148 ;
if ( V_144 ) {
F_47 ( V_144 -> V_8 ) ;
F_47 ( V_144 ) ;
}
}
static void F_60 ( struct V_142 * V_14 )
{
if ( V_14 -> type == V_150 ) {
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
static void F_64 ( struct V_151 * V_152 )
{
struct V_7 * V_38 = F_65 ( V_152 , struct V_7 , V_152 ) ;
F_63 ( V_38 ) ;
}
static void F_66 ( struct V_7 * V_38 )
{
if ( F_67 ( & V_38 -> V_153 ) )
F_68 ( & V_38 -> V_152 , F_64 ) ;
}
void F_69 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
T_1 V_154 = F_70 ( V_38 -> V_14 -> V_75 ) ;
F_71 ( V_154 , & V_2 -> V_155 ) ;
F_66 ( V_38 ) ;
}
static bool F_72 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
T_1 V_154 = F_70 ( V_38 -> V_14 -> V_75 ) ;
if ( V_154 <= V_156 &&
F_73 ( & V_2 -> V_155 ) + V_154 < V_156 ) {
F_74 ( V_154 , & V_2 -> V_155 ) ;
return true ;
}
return false ;
}
bool F_75 ( struct V_1 * V_2 , struct V_7 * V_38 )
{
bool V_136 = F_72 ( V_2 , V_38 ) ;
if ( V_136 )
F_76 ( & V_38 -> V_153 ) ;
return V_136 ;
}
static struct V_142 * F_77 ( struct V_142 * V_38 )
{
struct V_37 * V_157 ;
struct V_142 * V_158 ;
int V_6 , V_77 , V_159 = V_38 -> V_75 ;
F_15 ( sizeof( struct V_37 ) !=
sizeof( struct V_19 ) ) ;
V_157 = F_58 ( V_38 -> V_149 , V_159 * sizeof( struct V_37 ) ,
V_91 | V_92 ) ;
if ( ! V_157 ) {
V_6 = - V_11 ;
goto V_160;
}
V_6 = F_33 ( V_157 , V_159 , NULL , & V_77 ) ;
if ( V_6 )
goto V_161;
V_158 = V_38 ;
V_38 = F_78 ( V_158 , F_70 ( V_77 ) , 0 ) ;
if ( ! V_38 ) {
V_38 = V_158 ;
V_6 = - V_11 ;
goto V_161;
}
V_38 -> V_75 = V_77 ;
V_6 = F_33 ( V_157 , V_159 , V_38 -> V_162 , & V_77 ) ;
if ( V_6 )
goto V_161;
V_38 = F_79 ( V_38 , & V_6 ) ;
F_47 ( V_157 ) ;
return V_38 ;
V_161:
F_47 ( V_157 ) ;
V_160:
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
static struct V_142 * F_81 ( struct V_142 * V_38 ,
T_4 V_163 )
{
int V_6 ;
V_38 -> V_164 = NULL ;
V_38 -> V_165 = 0 ;
V_6 = F_53 ( V_38 -> V_149 , V_38 -> V_75 ) ;
if ( V_6 ) {
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
if ( V_163 ) {
V_6 = V_163 ( V_38 -> V_149 , V_38 -> V_75 ) ;
if ( V_6 ) {
F_60 ( V_38 ) ;
return F_80 ( V_6 ) ;
}
}
F_82 ( V_38 ) ;
if ( ! V_38 -> V_165 )
V_38 = F_77 ( V_38 ) ;
return V_38 ;
}
int F_83 ( struct V_142 * * V_166 , struct V_146 * V_144 )
{
unsigned int V_145 = F_56 ( V_144 ) ;
struct V_142 * V_38 ;
if ( ! F_52 ( V_144 -> V_8 , V_144 -> V_75 ) )
return - V_90 ;
V_38 = F_84 ( F_70 ( V_144 -> V_75 ) , 0 ) ;
if ( ! V_38 )
return - V_11 ;
memcpy ( V_38 -> V_149 , V_144 -> V_8 , V_145 ) ;
V_38 -> V_75 = V_144 -> V_75 ;
V_38 -> V_148 = NULL ;
V_38 = F_81 ( V_38 , NULL ) ;
if ( F_85 ( V_38 ) )
return F_86 ( V_38 ) ;
* V_166 = V_38 ;
return 0 ;
}
int F_87 ( struct V_142 * * V_166 , struct V_143 * V_144 ,
T_4 V_163 , bool V_167 )
{
unsigned int V_145 = F_56 ( V_144 ) ;
struct V_142 * V_38 ;
int V_6 ;
if ( ! F_52 ( V_144 -> V_8 , V_144 -> V_75 ) )
return - V_90 ;
V_38 = F_84 ( F_70 ( V_144 -> V_75 ) , 0 ) ;
if ( ! V_38 )
return - V_11 ;
if ( F_88 ( V_38 -> V_149 , V_144 -> V_8 , V_145 ) ) {
F_89 ( V_38 ) ;
return - V_168 ;
}
V_38 -> V_75 = V_144 -> V_75 ;
V_38 -> V_148 = NULL ;
if ( V_167 ) {
V_6 = F_55 ( V_38 , V_144 ) ;
if ( V_6 ) {
F_89 ( V_38 ) ;
return - V_11 ;
}
}
V_38 = F_81 ( V_38 , V_163 ) ;
if ( F_85 ( V_38 ) )
return F_86 ( V_38 ) ;
* V_166 = V_38 ;
return 0 ;
}
void F_90 ( struct V_142 * V_38 )
{
F_60 ( V_38 ) ;
}
static int F_91 ( struct V_142 * V_14 , struct V_1 * V_2 )
{
struct V_7 * V_38 , * V_158 ;
V_38 = F_57 ( sizeof( * V_38 ) , V_91 ) ;
if ( ! V_38 )
return - V_11 ;
V_38 -> V_14 = V_14 ;
if ( ! F_72 ( V_2 , V_38 ) ) {
F_47 ( V_38 ) ;
return - V_11 ;
}
F_92 ( & V_38 -> V_153 , 1 ) ;
V_158 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
F_95 ( V_2 -> V_7 , V_38 ) ;
if ( V_158 )
F_69 ( V_2 , V_158 ) ;
return 0 ;
}
static int F_96 ( struct V_142 * V_14 , struct V_1 * V_2 )
{
struct V_142 * V_157 ;
int V_6 ;
if ( F_70 ( V_14 -> V_75 ) > V_156 )
return - V_11 ;
if ( F_97 ( V_2 ) && V_2 -> V_169 ) {
V_6 = F_98 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_99 ( V_2 -> V_170 ) ) {
return - V_90 ;
}
V_157 = F_100 ( V_2 , V_14 ) ;
if ( V_157 )
F_90 ( V_157 ) ;
return 0 ;
}
static
struct V_142 * F_101 ( struct V_143 * V_144 , struct V_1 * V_2 )
{
unsigned int V_145 = F_56 ( V_144 ) ;
struct V_142 * V_14 ;
int V_6 ;
if ( F_3 ( V_2 , V_171 ) )
return F_80 ( - V_15 ) ;
if ( ! F_52 ( V_144 -> V_8 , V_144 -> V_75 ) )
return F_80 ( - V_90 ) ;
V_14 = F_84 ( F_70 ( V_144 -> V_75 ) , 0 ) ;
if ( ! V_14 )
return F_80 ( - V_11 ) ;
if ( F_88 ( V_14 -> V_149 , V_144 -> V_8 , V_145 ) ) {
F_89 ( V_14 ) ;
return F_80 ( - V_168 ) ;
}
V_14 -> V_75 = V_144 -> V_75 ;
V_6 = F_55 ( V_14 , V_144 ) ;
if ( V_6 ) {
F_89 ( V_14 ) ;
return F_80 ( - V_11 ) ;
}
return F_81 ( V_14 , NULL ) ;
}
int F_102 ( struct V_143 * V_144 , struct V_1 * V_2 )
{
struct V_142 * V_14 = F_101 ( V_144 , V_2 ) ;
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
int F_103 ( struct V_143 * V_144 , struct V_1 * V_2 )
{
struct V_142 * V_14 = F_101 ( V_144 , V_2 ) ;
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
static struct V_142 * F_104 ( T_1 V_172 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_171 ) )
return F_80 ( - V_15 ) ;
return F_105 ( V_172 , V_150 ) ;
}
int F_106 ( T_1 V_172 , struct V_1 * V_2 )
{
struct V_142 * V_14 = F_104 ( V_172 , V_2 ) ;
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
int F_107 ( T_1 V_172 , struct V_1 * V_2 )
{
struct V_142 * V_14 = F_104 ( V_172 , V_2 ) ;
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
unsigned int V_173 )
{
return F_109 ( V_4 , V_173 ) ;
}
static inline int F_110 ( struct V_3 * V_4 ,
unsigned int V_173 )
{
int V_6 = F_108 ( V_4 , V_173 ) ;
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
F_116 ( V_4 , F_117 ( V_4 ) , V_4 -> V_174 ) ;
}
static inline void F_118 ( struct V_3 * V_4 )
{
if ( F_115 ( V_4 ) )
F_119 ( V_4 , F_117 ( V_4 ) , V_4 -> V_174 ) ;
}
static inline int F_120 ( struct V_50 * V_52 , struct V_3 * V_4 )
{
return F_121 ( V_52 , V_4 ) ;
}
static inline int F_122 ( struct V_50 * V_52 ,
struct V_3 * V_4 )
{
int V_136 = F_123 ( V_52 , V_4 ) ;
if ( F_124 ( ! V_136 ) ) {
V_4 -> V_52 = V_52 ;
V_136 = F_125 ( V_4 ) ;
}
return V_136 ;
}
static inline int F_126 ( struct V_50 * V_52 , struct V_3 * V_4 )
{
int V_136 ;
if ( F_127 ( F_128 ( V_175 ) > V_176 ) ) {
F_129 ( L_1 ) ;
F_130 ( V_4 ) ;
return - V_177 ;
}
V_4 -> V_52 = V_52 ;
F_131 ( V_175 ) ;
V_136 = F_132 ( V_4 ) ;
F_133 ( V_175 ) ;
return V_136 ;
}
static int F_134 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_178 )
{
unsigned int V_179 = V_4 -> V_180 - V_4 -> V_181 ;
F_135 ( V_4 , V_179 ) ;
if ( ! F_115 ( V_4 ) )
F_119 ( V_4 , F_117 ( V_4 ) , V_179 ) ;
F_136 ( V_4 ) ;
F_137 ( V_4 ) ;
return V_178 & V_182 ?
F_122 ( V_52 , V_4 ) : F_126 ( V_52 , V_4 ) ;
}
static int F_138 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_178 )
{
if ( F_127 ( V_4 -> V_181 >= V_4 -> V_180 ) ) {
F_130 ( V_4 ) ;
return - V_183 ;
}
F_114 ( V_4 ) ;
return V_178 & V_182 ?
F_120 ( V_52 , V_4 ) : F_126 ( V_52 , V_4 ) ;
}
static int F_139 ( struct V_3 * V_4 , struct V_50 * V_52 ,
T_1 V_178 )
{
if ( F_140 ( V_52 ) )
return F_138 ( V_4 , V_52 , V_178 ) ;
else
return F_134 ( V_4 , V_52 , V_178 ) ;
}
int F_141 ( struct V_3 * V_4 )
{
struct V_184 * V_185 = F_142 ( & V_184 ) ;
struct V_50 * V_52 ;
V_52 = F_143 ( F_144 ( V_4 -> V_52 ) , V_185 -> V_51 ) ;
V_185 -> V_51 = 0 ;
if ( F_127 ( ! V_52 ) ) {
F_130 ( V_4 ) ;
return - V_90 ;
}
return F_139 ( V_4 , V_52 , V_185 -> V_178 ) ;
}
static int F_145 ( struct V_3 * V_4 , T_1 V_186 , T_1 V_75 )
{
F_146 ( V_4 , V_75 ) ;
memmove ( V_4 -> V_187 , V_4 -> V_187 + V_75 , V_186 ) ;
memset ( V_4 -> V_187 + V_186 , 0 , V_75 ) ;
return 0 ;
}
static int F_147 ( struct V_3 * V_4 , T_1 V_186 , T_1 V_75 )
{
if ( F_127 ( ! F_148 ( V_4 , V_186 + V_75 ) ) )
return - V_11 ;
F_119 ( V_4 , V_4 -> V_187 + V_186 , V_75 ) ;
memmove ( V_4 -> V_187 + V_75 , V_4 -> V_187 , V_186 ) ;
F_135 ( V_4 , V_75 ) ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 , T_1 V_186 , T_1 V_75 )
{
bool V_188 = V_4 -> V_189 == V_4 -> V_180 ;
int V_136 ;
V_136 = F_145 ( V_4 , V_186 , V_75 ) ;
if ( F_124 ( ! V_136 ) ) {
V_4 -> V_181 -= V_75 ;
V_4 -> V_180 -= V_75 ;
if ( V_188 )
V_4 -> V_189 = V_4 -> V_180 ;
}
return V_136 ;
}
static int F_150 ( struct V_3 * V_4 , T_1 V_186 , T_1 V_75 )
{
bool V_188 = V_4 -> V_189 == V_4 -> V_180 ;
int V_136 ;
V_136 = F_147 ( V_4 , V_186 , V_75 ) ;
if ( F_124 ( ! V_136 ) ) {
V_4 -> V_181 += V_75 ;
V_4 -> V_180 += V_75 ;
if ( V_188 )
V_4 -> V_189 = V_4 -> V_180 ;
}
return V_136 ;
}
static int F_151 ( struct V_3 * V_4 )
{
const T_1 V_190 = sizeof( struct V_191 ) - sizeof( struct V_192 ) ;
T_1 V_186 = V_4 -> V_180 - V_4 -> V_181 ;
int V_136 ;
V_136 = F_152 ( V_4 , V_190 ) ;
if ( F_127 ( V_136 < 0 ) )
return V_136 ;
V_136 = F_149 ( V_4 , V_186 , V_190 ) ;
if ( F_127 ( V_136 < 0 ) )
return V_136 ;
if ( F_153 ( V_4 ) ) {
if ( F_154 ( V_4 ) -> V_193 & V_194 ) {
F_154 ( V_4 ) -> V_193 &= ~ V_194 ;
F_154 ( V_4 ) -> V_193 |= V_195 ;
}
F_154 ( V_4 ) -> V_196 -= V_190 ;
F_154 ( V_4 ) -> V_193 |= V_197 ;
F_154 ( V_4 ) -> V_198 = 0 ;
}
V_4 -> V_44 = F_155 ( V_199 ) ;
F_156 ( V_4 ) ;
return 0 ;
}
static int F_157 ( struct V_3 * V_4 )
{
const T_1 V_190 = sizeof( struct V_191 ) - sizeof( struct V_192 ) ;
T_1 V_186 = V_4 -> V_180 - V_4 -> V_181 ;
int V_136 ;
V_136 = F_158 ( V_4 , V_200 ) ;
if ( F_127 ( V_136 < 0 ) )
return V_136 ;
V_136 = F_150 ( V_4 , V_186 , V_190 ) ;
if ( F_127 ( V_136 < 0 ) )
return V_136 ;
if ( F_153 ( V_4 ) ) {
if ( F_154 ( V_4 ) -> V_193 & V_195 ) {
F_154 ( V_4 ) -> V_193 &= ~ V_195 ;
F_154 ( V_4 ) -> V_193 |= V_194 ;
}
F_154 ( V_4 ) -> V_196 += V_190 ;
F_154 ( V_4 ) -> V_193 |= V_197 ;
F_154 ( V_4 ) -> V_198 = 0 ;
}
V_4 -> V_44 = F_155 ( V_201 ) ;
F_156 ( V_4 ) ;
return 0 ;
}
static int F_159 ( struct V_3 * V_4 , T_5 V_202 )
{
T_5 V_203 = V_4 -> V_44 ;
if ( V_203 == F_155 ( V_201 ) &&
V_202 == F_155 ( V_199 ) )
return F_151 ( V_4 ) ;
if ( V_203 == F_155 ( V_199 ) &&
V_202 == F_155 ( V_201 ) )
return F_157 ( V_4 ) ;
return - V_204 ;
}
static T_1 F_160 ( const struct V_3 * V_4 )
{
T_1 V_205 = F_161 ( V_4 ) ;
if ( F_162 ( V_4 ) )
V_205 = F_163 ( V_4 ) ;
if ( V_4 -> V_206 == V_207 )
V_205 = F_164 ( V_4 ) +
V_4 -> V_208 + sizeof( V_209 ) ;
return V_205 ;
}
static T_1 F_165 ( const struct V_3 * V_4 )
{
return V_4 -> V_52 -> V_210 + V_4 -> V_52 -> V_211 ;
}
static int F_166 ( struct V_3 * V_4 , unsigned int V_77 )
{
unsigned int V_159 = V_4 -> V_75 ;
int V_136 ;
V_136 = F_167 ( V_4 , V_77 ) ;
if ( ! V_136 )
memset ( V_4 -> V_187 + V_159 , 0 , V_77 - V_159 ) ;
return V_136 ;
}
static int F_168 ( struct V_3 * V_4 , unsigned int V_77 )
{
return F_169 ( V_4 , V_77 ) ;
}
bool F_170 ( void * V_212 )
{
if ( V_212 == V_213 ||
V_212 == V_214 ||
V_212 == V_215 ||
V_212 == V_216 ||
V_212 == V_217 ||
V_212 == V_218 ||
V_212 == V_219 ||
V_212 == V_220 ||
V_212 == V_221 ||
V_212 == V_222 ||
V_212 == V_223 )
return true ;
return false ;
}
static unsigned long F_171 ( void * V_224 , const void * V_4 ,
unsigned long V_186 , unsigned long V_75 )
{
void * V_225 = F_172 ( V_4 , V_186 , V_75 , V_224 ) ;
if ( F_127 ( ! V_225 ) )
return V_75 ;
if ( V_225 != V_224 )
memcpy ( V_224 , V_225 , V_75 ) ;
return 0 ;
}
static unsigned short F_173 ( T_6 V_178 )
{
return V_178 & V_226 ? V_227 : V_228 ;
}
static const struct V_229 *
F_174 ( enum V_230 V_231 )
{
if ( ! V_232 ) {
V_232 = F_175 ( V_233 ,
V_91 ) ;
if ( ! V_232 )
return NULL ;
}
switch ( V_231 ) {
case V_234 :
return & V_235 ;
case V_236 :
return & V_237 ;
default:
return NULL ;
}
}
static unsigned long F_176 ( void * V_224 , const void * V_238 ,
unsigned long V_186 , unsigned long V_75 )
{
memcpy ( V_224 , V_238 + V_186 , V_75 ) ;
return 0 ;
}
static const struct V_229 *
F_177 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_240 :
return & V_241 ;
case V_242 :
return & V_243 ;
case V_244 :
return & V_245 ;
case V_246 :
return & V_247 ;
case V_248 :
return & V_249 ;
case V_250 :
return & V_251 ;
case V_252 :
return & V_253 ;
case V_254 :
return & V_255 ;
case V_256 :
if ( F_178 ( V_257 ) )
return F_179 () ;
default:
return NULL ;
}
}
static const struct V_229 *
F_180 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_258 :
return & V_259 ;
case V_260 :
return & V_261 ;
case V_262 :
return & V_263 ;
default:
return F_177 ( V_239 ) ;
}
}
static const struct V_229 *
F_181 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_264 :
return & V_265 ;
case V_258 :
return & V_259 ;
case V_266 :
return & V_267 ;
case V_268 :
return & V_269 ;
case V_270 :
return & V_271 ;
case V_272 :
return & V_273 ;
case V_274 :
return & V_275 ;
case V_276 :
return & V_277 ;
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
case V_234 :
return F_174 ( V_239 ) ;
case V_292 :
return & V_293 ;
case V_236 :
return F_174 ( V_239 ) ;
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
case V_248 :
return & V_304 ;
case V_305 :
return & V_306 ;
case V_260 :
return & V_261 ;
case V_262 :
return & V_263 ;
default:
return F_177 ( V_239 ) ;
}
}
static const struct V_229 *
F_182 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_302 :
return & V_307 ;
case V_248 :
return & V_304 ;
case V_308 :
return & V_309 ;
default:
return F_177 ( V_239 ) ;
}
}
static const struct V_229 *
F_183 ( enum V_230 V_239 )
{
return F_180 ( V_239 ) ;
}
static const struct V_229 *
F_184 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_258 :
return & V_259 ;
case V_266 :
return & V_267 ;
case V_268 :
return & V_269 ;
case V_278 :
return & V_279 ;
case V_296 :
return & V_297 ;
case V_298 :
return & V_299 ;
case V_302 :
return & V_303 ;
case V_248 :
return & V_304 ;
case V_305 :
return & V_306 ;
default:
return F_177 ( V_239 ) ;
}
}
static const struct V_229 *
F_185 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_290 :
return & V_291 ;
case V_234 :
return F_174 ( V_239 ) ;
case V_292 :
return & V_293 ;
case V_236 :
return F_174 ( V_239 ) ;
case V_294 :
return & V_295 ;
case V_276 :
return & V_277 ;
case V_288 :
return & V_289 ;
case V_310 :
return & V_311 ;
case V_264 :
return & V_265 ;
case V_270 :
return & V_271 ;
case V_272 :
return & V_273 ;
case V_274 :
return & V_275 ;
case V_300 :
return & V_301 ;
default:
return F_184 ( V_239 ) ;
}
}
static bool F_186 ( int V_186 , int V_312 )
{
if ( V_186 < 0 || V_186 >= sizeof( struct V_313 ) )
return false ;
if ( V_186 % V_312 != 0 )
return false ;
switch ( V_186 ) {
case F_18 ( struct V_313 , V_314 [ 0 ] ) ...
F_18 ( struct V_313 , V_314 [ 4 ] ) + sizeof( V_315 ) - 1 :
if ( V_186 + V_312 >
F_18 ( struct V_313 , V_314 [ 4 ] ) + sizeof( V_315 ) )
return false ;
break;
default:
if ( V_312 != sizeof( V_315 ) )
return false ;
}
return true ;
}
static bool F_187 ( int V_186 , int V_312 ,
enum V_316 type ,
enum V_317 * V_318 )
{
switch ( V_186 ) {
case F_18 ( struct V_313 , V_319 ) :
case F_18 ( struct V_313 , V_187 ) :
case F_18 ( struct V_313 , V_320 ) :
return false ;
}
if ( type == V_321 ) {
switch ( V_186 ) {
case F_18 ( struct V_313 , V_314 [ 0 ] ) ...
F_18 ( struct V_313 , V_314 [ 4 ] ) + sizeof( V_315 ) - 1 :
break;
default:
return false ;
}
}
return F_186 ( V_186 , V_312 ) ;
}
static bool F_188 ( int V_186 , int V_312 ,
enum V_316 type ,
enum V_317 * V_318 )
{
switch ( V_186 ) {
case F_18 ( struct V_313 , V_319 ) :
return false ;
}
if ( type == V_321 ) {
switch ( V_186 ) {
case F_18 ( struct V_313 , V_23 ) :
case F_18 ( struct V_313 , V_322 ) :
case F_18 ( struct V_313 , V_314 [ 0 ] ) ...
F_18 ( struct V_313 , V_314 [ 4 ] ) + sizeof( V_315 ) - 1 :
break;
default:
return false ;
}
}
switch ( V_186 ) {
case F_18 ( struct V_313 , V_187 ) :
* V_318 = V_323 ;
break;
case F_18 ( struct V_313 , V_320 ) :
* V_318 = V_324 ;
break;
}
return F_186 ( V_186 , V_312 ) ;
}
static bool F_189 ( int V_186 , int V_312 ,
enum V_316 type ,
enum V_317 * V_318 )
{
if ( type == V_321 ) {
switch ( V_186 ) {
case F_18 ( struct V_325 , V_326 ) :
break;
default:
return false ;
}
}
if ( V_186 < 0 || V_186 + V_312 > sizeof( struct V_325 ) )
return false ;
if ( V_186 % V_312 != 0 )
return false ;
if ( V_312 != sizeof( V_315 ) )
return false ;
return true ;
}
static int F_190 ( struct V_19 * V_20 , bool V_327 ,
const struct V_142 * V_14 )
{
struct V_19 * V_21 = V_20 ;
if ( ! V_327 )
return 0 ;
* V_21 ++ = F_17 ( V_26 , V_328 , V_329 , F_191 () ) ;
* V_21 ++ = F_20 ( V_27 , V_328 , V_330 ) ;
* V_21 ++ = F_25 ( V_112 , V_328 , 0 , 7 ) ;
* V_21 ++ = F_27 ( V_328 , V_329 ) ;
* V_21 ++ = F_35 ( V_74 , V_331 , V_331 ) ;
* V_21 ++ = F_38 ( V_110 | V_332 , 0 , 0 , 0 ,
V_266 ) ;
* V_21 ++ = F_25 ( V_112 , V_123 , 0 , 2 ) ;
* V_21 ++ = F_20 ( V_333 , V_123 , V_334 ) ;
* V_21 ++ = F_26 () ;
* V_21 ++ = F_27 ( V_329 , V_328 ) ;
* V_21 ++ = V_14 -> V_162 [ 0 ] ;
return V_21 - V_20 ;
}
static bool F_192 ( int V_186 , int V_312 ,
enum V_316 type ,
enum V_317 * V_318 )
{
if ( type == V_321 ) {
switch ( V_186 ) {
case F_18 ( struct V_313 , V_23 ) :
case F_18 ( struct V_313 , V_335 ) :
case F_18 ( struct V_313 , V_322 ) :
case F_18 ( struct V_313 , V_314 [ 0 ] ) ...
F_18 ( struct V_313 , V_314 [ 4 ] ) + sizeof( V_315 ) - 1 :
case F_18 ( struct V_313 , V_319 ) :
break;
default:
return false ;
}
}
switch ( V_186 ) {
case F_18 ( struct V_313 , V_187 ) :
* V_318 = V_323 ;
break;
case F_18 ( struct V_313 , V_320 ) :
* V_318 = V_324 ;
break;
}
return F_186 ( V_186 , V_312 ) ;
}
static bool F_193 ( int V_186 , int V_312 )
{
if ( V_186 < 0 || V_186 >= sizeof( struct V_336 ) )
return false ;
if ( V_186 % V_312 != 0 )
return false ;
if ( V_312 != sizeof( V_315 ) )
return false ;
return true ;
}
static bool F_194 ( int V_186 , int V_312 ,
enum V_316 type ,
enum V_317 * V_318 )
{
if ( type == V_321 )
return false ;
switch ( V_186 ) {
case F_18 ( struct V_336 , V_187 ) :
* V_318 = V_323 ;
break;
case F_18 ( struct V_336 , V_320 ) :
* V_318 = V_324 ;
break;
}
return F_193 ( V_186 , V_312 ) ;
}
void F_195 ( T_1 V_337 )
{
F_196 ( 1 , L_2 , V_337 ) ;
}
static T_1 F_197 ( enum V_316 type ,
const struct V_19 * V_338 ,
struct V_19 * V_20 ,
struct V_142 * V_14 )
{
struct V_19 * V_21 = V_20 ;
int V_186 ;
switch ( V_338 -> V_186 ) {
case F_18 ( struct V_313 , V_75 ) :
F_15 ( F_16 ( struct V_3 , V_75 ) != 4 ) ;
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_75 ) ) ;
break;
case F_18 ( struct V_313 , V_44 ) :
F_15 ( F_16 ( struct V_3 , V_44 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_44 ) ) ;
break;
case F_18 ( struct V_313 , V_58 ) :
F_15 ( F_16 ( struct V_3 , V_58 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_58 ) ) ;
break;
case F_18 ( struct V_313 , V_322 ) :
F_15 ( F_16 ( struct V_3 , V_322 ) != 4 ) ;
if ( type == V_321 )
* V_21 ++ = F_46 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_322 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_322 ) ) ;
break;
case F_18 ( struct V_313 , V_339 ) :
F_15 ( F_16 ( struct V_3 , V_340 ) != 4 ) ;
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_340 ) ) ;
break;
case F_18 ( struct V_313 , V_51 ) :
F_15 ( F_16 ( struct V_50 , V_51 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_25 ( V_112 , V_338 -> V_17 , 0 , 1 ) ;
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_17 ,
F_18 ( struct V_50 , V_51 ) ) ;
break;
case F_18 ( struct V_313 , V_56 ) :
F_15 ( F_16 ( struct V_3 , V_56 ) != 4 ) ;
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_56 ) ) ;
break;
case F_18 ( struct V_313 , V_23 ) :
F_15 ( F_16 ( struct V_3 , V_23 ) != 4 ) ;
if ( type == V_321 )
* V_21 ++ = F_46 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_23 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_23 ) ) ;
break;
case F_18 ( struct V_313 , V_341 ) :
return F_14 ( V_25 , V_338 -> V_17 ,
V_338 -> V_18 , V_21 ) ;
case F_18 ( struct V_313 , V_31 ) :
return F_14 ( V_30 , V_338 -> V_17 ,
V_338 -> V_18 , V_21 ) ;
case F_18 ( struct V_313 , V_342 ) :
return F_14 ( V_34 ,
V_338 -> V_17 , V_338 -> V_18 , V_21 ) ;
case F_18 ( struct V_313 , V_35 ) :
return F_14 ( V_33 ,
V_338 -> V_17 , V_338 -> V_18 , V_21 ) ;
case F_18 ( struct V_313 , V_314 [ 0 ] ) ...
F_18 ( struct V_313 , V_314 [ 4 ] ) + sizeof( V_315 ) - 1 :
F_15 ( F_16 ( struct V_343 , V_187 ) < 20 ) ;
F_15 ( ( F_18 ( struct V_3 , V_314 ) +
F_18 ( struct V_343 , V_187 ) ) %
sizeof( V_344 ) ) ;
V_14 -> V_345 = 1 ;
V_186 = V_338 -> V_186 ;
V_186 -= F_18 ( struct V_313 , V_314 [ 0 ] ) ;
V_186 += F_18 ( struct V_3 , V_314 ) ;
V_186 += F_18 ( struct V_343 , V_187 ) ;
if ( type == V_321 )
* V_21 ++ = F_46 ( F_198 ( V_338 -> V_95 ) , V_338 -> V_17 ,
V_338 -> V_18 , V_186 ) ;
else
* V_21 ++ = F_17 ( F_198 ( V_338 -> V_95 ) , V_338 -> V_17 ,
V_338 -> V_18 , V_186 ) ;
break;
case F_18 ( struct V_313 , V_319 ) :
F_15 ( F_16 ( struct V_343 , V_319 ) != 2 ) ;
V_186 = V_338 -> V_186 ;
V_186 -= F_18 ( struct V_313 , V_319 ) ;
V_186 += F_18 ( struct V_3 , V_314 ) ;
V_186 += F_18 ( struct V_343 , V_319 ) ;
if ( type == V_321 )
* V_21 ++ = F_46 ( V_32 , V_338 -> V_17 ,
V_338 -> V_18 , V_186 ) ;
else
* V_21 ++ = F_17 ( V_32 , V_338 -> V_17 ,
V_338 -> V_18 , V_186 ) ;
break;
case F_18 ( struct V_313 , V_187 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_187 ) ,
V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_187 ) ) ;
break;
case F_18 ( struct V_313 , V_320 ) :
V_186 = V_338 -> V_186 ;
V_186 -= F_18 ( struct V_313 , V_320 ) ;
V_186 += F_18 ( struct V_3 , V_314 ) ;
V_186 += F_18 ( struct V_346 , V_320 ) ;
* V_21 ++ = F_17 ( F_199 ( void * ) , V_338 -> V_17 ,
V_338 -> V_18 , V_186 ) ;
break;
case F_18 ( struct V_313 , V_335 ) :
#ifdef F_200
F_15 ( F_16 ( struct V_3 , V_335 ) != 2 ) ;
if ( type == V_321 )
* V_21 ++ = F_46 ( V_32 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_335 ) ) ;
else
* V_21 ++ = F_17 ( V_32 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_335 ) ) ;
#else
if ( type == V_321 )
* V_21 ++ = F_27 ( V_338 -> V_17 , V_338 -> V_17 ) ;
else
* V_21 ++ = F_201 ( V_338 -> V_17 , 0 ) ;
#endif
break;
case F_18 ( struct V_313 , V_347 ) :
#if F_202 ( V_348 )
F_15 ( F_16 ( struct V_3 , V_347 ) != 4 ) ;
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_347 ) ) ;
* V_21 ++ = F_25 ( V_115 , V_338 -> V_17 , V_349 , 1 ) ;
* V_21 ++ = F_201 ( V_338 -> V_17 , 0 ) ;
#else
* V_21 ++ = F_201 ( V_338 -> V_17 , 0 ) ;
#endif
break;
}
return V_21 - V_20 ;
}
static T_1 F_203 ( enum V_316 type ,
const struct V_19 * V_338 ,
struct V_19 * V_20 ,
struct V_142 * V_14 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_338 -> V_186 ) {
case F_18 ( struct V_325 , V_326 ) :
F_15 ( F_16 ( struct V_1 , V_350 ) != 4 ) ;
if ( type == V_321 )
* V_21 ++ = F_46 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_1 , V_350 ) ) ;
else
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_1 , V_350 ) ) ;
break;
case F_18 ( struct V_325 , V_351 ) :
F_15 ( F_16 ( struct V_1 , V_352 ) != 2 ) ;
* V_21 ++ = F_17 ( V_32 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_1 , V_352 ) ) ;
break;
case F_18 ( struct V_325 , type ) :
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_1 , V_353 ) ) ;
* V_21 ++ = F_20 ( V_27 , V_338 -> V_17 , V_354 ) ;
* V_21 ++ = F_20 ( V_29 , V_338 -> V_17 , V_355 ) ;
break;
case F_18 ( struct V_325 , V_44 ) :
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_1 , V_353 ) ) ;
* V_21 ++ = F_20 ( V_27 , V_338 -> V_17 , V_356 ) ;
* V_21 ++ = F_20 ( V_29 , V_338 -> V_17 , V_357 ) ;
break;
}
return V_21 - V_20 ;
}
static T_1 F_204 ( enum V_316 type ,
const struct V_19 * V_338 ,
struct V_19 * V_20 ,
struct V_142 * V_14 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_338 -> V_186 ) {
case F_18 ( struct V_313 , V_51 ) :
F_15 ( F_16 ( struct V_50 , V_51 ) != 4 ) ;
* V_21 ++ = F_17 ( F_24 ( struct V_3 , V_52 ) ,
V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_3 , V_52 ) ) ;
* V_21 ++ = F_17 ( V_24 , V_338 -> V_17 , V_338 -> V_17 ,
F_18 ( struct V_50 , V_51 ) ) ;
break;
default:
return F_197 ( type , V_338 , V_20 , V_14 ) ;
}
return V_21 - V_20 ;
}
static T_1 F_205 ( enum V_316 type ,
const struct V_19 * V_338 ,
struct V_19 * V_20 ,
struct V_142 * V_14 )
{
struct V_19 * V_21 = V_20 ;
switch ( V_338 -> V_186 ) {
case F_18 ( struct V_336 , V_187 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_358 , V_187 ) ,
V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_358 , V_187 ) ) ;
break;
case F_18 ( struct V_336 , V_320 ) :
* V_21 ++ = F_17 ( F_24 ( struct V_358 , V_320 ) ,
V_338 -> V_17 , V_338 -> V_18 ,
F_18 ( struct V_358 , V_320 ) ) ;
break;
}
return V_21 - V_20 ;
}
int F_206 ( struct V_1 * V_2 )
{
int V_136 = - V_359 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_171 ) )
return - V_15 ;
V_8 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
if ( V_8 ) {
F_207 ( V_2 -> V_7 , NULL ) ;
F_69 ( V_2 , V_8 ) ;
V_136 = 0 ;
}
return V_136 ;
}
int F_208 ( struct V_1 * V_2 , struct V_37 T_7 * V_360 ,
unsigned int V_75 )
{
struct V_146 * V_144 ;
struct V_7 * V_8 ;
int V_136 = 0 ;
F_209 ( V_2 ) ;
V_8 = F_93 ( V_2 -> V_7 ,
F_94 ( V_2 ) ) ;
if ( ! V_8 )
goto V_361;
V_136 = - V_362 ;
V_144 = V_8 -> V_14 -> V_148 ;
if ( ! V_144 )
goto V_361;
V_136 = V_144 -> V_75 ;
if ( ! V_75 )
goto V_361;
V_136 = - V_90 ;
if ( V_75 < V_144 -> V_75 )
goto V_361;
V_136 = - V_168 ;
if ( F_210 ( V_360 , V_144 -> V_8 , F_56 ( V_144 ) ) )
goto V_361;
V_136 = V_144 -> V_75 ;
V_361:
F_211 ( V_2 ) ;
return V_136 ;
}
