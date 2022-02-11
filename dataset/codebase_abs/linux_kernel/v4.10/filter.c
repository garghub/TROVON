int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
if ( F_2 ( V_4 ) && ! F_3 ( V_2 , V_9 ) )
return - V_10 ;
V_6 = F_4 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
F_6 () ;
V_8 = F_7 ( V_2 -> V_7 ) ;
if ( V_8 ) {
unsigned int V_11 = F_8 ( V_8 -> V_12 , V_4 ) ;
V_6 = V_11 ? F_9 ( V_4 , F_10 ( V_5 , V_11 ) ) : - V_13 ;
}
F_11 () ;
return V_6 ;
}
static T_1 F_12 ( int V_14 , int V_15 , int V_16 ,
struct V_17 * V_18 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_14 ) {
case V_20 :
F_13 ( F_14 ( struct V_3 , V_21 ) != 4 ) ;
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_21 ) ) ;
break;
case V_23 :
* V_19 ++ = F_15 ( V_24 , V_15 , V_16 , F_17 () ) ;
* V_19 ++ = F_18 ( V_25 , V_15 , V_26 ) ;
#ifdef F_19
* V_19 ++ = F_18 ( V_27 , V_15 , 5 ) ;
#endif
break;
case V_28 :
F_13 ( F_14 ( struct V_3 , V_29 ) != 2 ) ;
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_3 , V_29 ) ) ;
break;
case V_31 :
case V_32 :
F_13 ( F_14 ( struct V_3 , V_33 ) != 2 ) ;
F_13 ( V_34 != 0x1000 ) ;
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_3 , V_33 ) ) ;
if ( V_14 == V_31 ) {
* V_19 ++ = F_18 ( V_25 , V_15 ,
~ V_34 ) ;
} else {
* V_19 ++ = F_18 ( V_27 , V_15 , 12 ) ;
* V_19 ++ = F_18 ( V_25 , V_15 , 1 ) ;
}
break;
}
return V_19 - V_18 ;
}
static bool F_20 ( struct V_35 * V_36 ,
struct V_17 * * V_37 )
{
struct V_17 * V_19 = * V_37 ;
T_1 V_38 ;
switch ( V_36 -> V_39 ) {
case V_40 + V_41 :
F_13 ( F_14 ( struct V_3 , V_42 ) != 2 ) ;
* V_19 ++ = F_15 ( V_30 , V_43 , V_44 ,
F_16 ( struct V_3 , V_42 ) ) ;
* V_19 = F_21 ( V_45 , V_43 , 16 ) ;
break;
case V_40 + V_23 :
V_38 = F_12 ( V_23 , V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_46 :
case V_40 + V_47 :
F_13 ( F_14 ( struct V_48 , V_49 ) != 4 ) ;
F_13 ( F_14 ( struct V_48 , type ) != 2 ) ;
* V_19 ++ = F_15 ( F_22 ( struct V_3 , V_50 ) ,
V_51 , V_44 ,
F_16 ( struct V_3 , V_50 ) ) ;
* V_19 ++ = F_23 ( V_52 , V_51 , 0 , 1 ) ;
* V_19 ++ = F_24 () ;
if ( V_36 -> V_39 == V_40 + V_46 )
* V_19 = F_15 ( V_22 , V_43 , V_51 ,
F_16 ( struct V_48 , V_49 ) ) ;
else
* V_19 = F_15 ( V_30 , V_43 , V_51 ,
F_16 ( struct V_48 , type ) ) ;
break;
case V_40 + V_20 :
V_38 = F_12 ( V_20 , V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_53 :
F_13 ( F_14 ( struct V_3 , V_54 ) != 4 ) ;
* V_19 = F_15 ( V_22 , V_43 , V_44 ,
F_16 ( struct V_3 , V_54 ) ) ;
break;
case V_40 + V_28 :
V_38 = F_12 ( V_28 , V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_31 :
V_38 = F_12 ( V_31 ,
V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_32 :
V_38 = F_12 ( V_32 ,
V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_55 :
F_13 ( F_14 ( struct V_3 , V_56 ) != 2 ) ;
* V_19 ++ = F_15 ( V_30 , V_43 , V_44 ,
F_16 ( struct V_3 , V_56 ) ) ;
* V_19 = F_21 ( V_45 , V_43 , 16 ) ;
break;
case V_40 + V_57 :
case V_40 + V_58 :
case V_40 + V_59 :
case V_40 + V_60 :
case V_40 + V_61 :
* V_19 ++ = F_25 ( V_62 , V_44 ) ;
* V_19 ++ = F_25 ( V_63 , V_43 ) ;
* V_19 ++ = F_25 ( V_64 , V_65 ) ;
switch ( V_36 -> V_39 ) {
case V_40 + V_57 :
* V_19 = F_26 ( V_66 ) ;
break;
case V_40 + V_58 :
* V_19 = F_26 ( V_67 ) ;
break;
case V_40 + V_59 :
* V_19 = F_26 ( V_68 ) ;
break;
case V_40 + V_60 :
* V_19 = F_26 ( V_69 ) ;
break;
case V_40 + V_61 :
* V_19 = F_26 ( V_70 ) ;
F_27 () ;
break;
}
break;
case V_40 + V_71 :
* V_19 = F_28 ( V_72 , V_43 , V_65 ) ;
break;
default:
F_29 ( F_30 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_37 = V_19 ;
return true ;
}
static int F_31 ( struct V_35 * V_12 , int V_73 ,
struct V_17 * V_74 , int * V_75 )
{
int V_76 = 0 , V_77 = 0 , V_78 , V_79 ;
struct V_17 * V_80 ;
struct V_35 * V_36 ;
int * V_81 = NULL ;
T_2 V_82 ;
F_13 ( V_83 * sizeof( T_1 ) > V_84 ) ;
F_13 ( V_85 + 1 != V_86 ) ;
if ( V_73 <= 0 || V_73 > V_87 )
return - V_88 ;
if ( V_74 ) {
V_81 = F_32 ( V_73 , sizeof( * V_81 ) ,
V_89 | V_90 ) ;
if ( ! V_81 )
return - V_10 ;
}
V_91:
V_80 = V_74 ;
V_36 = V_12 ;
if ( V_80 ) {
* V_80 ++ = F_33 ( V_72 , V_43 , V_43 ) ;
* V_80 ++ = F_33 ( V_72 , V_65 , V_65 ) ;
* V_80 ++ = F_25 ( V_44 , V_62 ) ;
} else {
V_80 += 3 ;
}
for ( V_79 = 0 ; V_79 < V_73 ; V_36 ++ , V_79 ++ ) {
struct V_17 V_92 [ 6 ] = { } ;
struct V_17 * V_19 = V_92 ;
if ( V_81 )
V_81 [ V_79 ] = V_80 - V_74 ;
switch ( V_36 -> V_93 ) {
case V_94 | V_95 | V_96 :
case V_94 | V_95 | V_97 :
case V_94 | V_98 | V_96 :
case V_94 | V_98 | V_97 :
case V_94 | V_25 | V_96 :
case V_94 | V_25 | V_97 :
case V_94 | V_99 | V_96 :
case V_94 | V_99 | V_97 :
case V_94 | V_100 | V_96 :
case V_94 | V_100 | V_97 :
case V_94 | V_27 | V_96 :
case V_94 | V_27 | V_97 :
case V_94 | V_72 | V_96 :
case V_94 | V_72 | V_97 :
case V_94 | V_101 | V_96 :
case V_94 | V_101 | V_97 :
case V_94 | V_102 | V_96 :
case V_94 | V_102 | V_97 :
case V_94 | V_103 | V_96 :
case V_94 | V_103 | V_97 :
case V_94 | V_104 :
case V_105 | V_106 | V_22 :
case V_105 | V_106 | V_30 :
case V_105 | V_106 | V_24 :
case V_105 | V_107 | V_22 :
case V_105 | V_107 | V_30 :
case V_105 | V_107 | V_24 :
if ( F_34 ( V_36 -> V_93 ) == V_105 &&
F_35 ( V_36 -> V_93 ) == V_106 &&
F_20 ( V_36 , & V_19 ) )
break;
* V_19 = F_36 ( V_36 -> V_93 , V_43 , V_65 , 0 , V_36 -> V_39 ) ;
break;
#define F_37 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_108 | V_109 :
V_78 = V_79 + V_36 -> V_39 + 1 ;
V_19 -> V_93 = V_36 -> V_93 ;
F_37 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
if ( F_38 ( V_36 -> V_93 ) == V_97 && ( int ) V_36 -> V_39 < 0 ) {
* V_19 ++ = F_39 ( V_51 , V_36 -> V_39 ) ;
V_19 -> V_15 = V_43 ;
V_19 -> V_16 = V_51 ;
V_82 = V_96 ;
} else {
V_19 -> V_15 = V_43 ;
V_19 -> V_114 = V_36 -> V_39 ;
V_82 = F_38 ( V_36 -> V_93 ) ;
V_19 -> V_16 = V_82 == V_96 ? V_65 : 0 ;
}
if ( V_36 -> V_115 == 0 ) {
V_19 -> V_93 = V_108 | F_40 ( V_36 -> V_93 ) | V_82 ;
V_78 = V_79 + V_36 -> V_116 + 1 ;
F_37 ;
break;
}
if ( V_36 -> V_116 == 0 && F_40 ( V_36 -> V_93 ) == V_110 ) {
V_19 -> V_93 = V_108 | V_52 | V_82 ;
V_78 = V_79 + V_36 -> V_115 + 1 ;
F_37 ;
break;
}
V_78 = V_79 + V_36 -> V_116 + 1 ;
V_19 -> V_93 = V_108 | F_40 ( V_36 -> V_93 ) | V_82 ;
F_37 ;
V_19 ++ ;
V_19 -> V_93 = V_108 | V_109 ;
V_78 = V_79 + V_36 -> V_115 + 1 ;
F_37 ;
break;
case V_117 | V_118 | V_24 :
* V_19 ++ = F_25 ( V_51 , V_43 ) ;
* V_19 ++ = F_41 ( V_24 , V_36 -> V_39 ) ;
* V_19 ++ = F_18 ( V_25 , V_43 , 0xf ) ;
* V_19 ++ = F_18 ( V_100 , V_43 , 2 ) ;
* V_19 ++ = F_25 ( V_65 , V_43 ) ;
* V_19 = F_25 ( V_43 , V_51 ) ;
break;
case V_119 | V_120 :
case V_119 | V_97 :
if ( F_42 ( V_36 -> V_93 ) == V_97 )
* V_19 ++ = F_43 ( V_97 , V_121 ,
0 , V_36 -> V_39 ) ;
* V_19 = F_24 () ;
break;
case V_122 :
case V_123 :
* V_19 = F_44 ( V_22 , V_85 , F_34 ( V_36 -> V_93 ) ==
V_122 ? V_43 : V_65 ,
- ( V_83 - V_36 -> V_39 ) * 4 ) ;
break;
case V_105 | V_124 :
case V_117 | V_124 :
* V_19 = F_15 ( V_22 , F_34 ( V_36 -> V_93 ) == V_105 ?
V_43 : V_65 , V_85 ,
- ( V_83 - V_36 -> V_39 ) * 4 ) ;
break;
case V_105 | V_125 :
case V_117 | V_125 :
* V_19 = F_39 ( F_34 ( V_36 -> V_93 ) == V_105 ?
V_43 : V_65 , V_36 -> V_39 ) ;
break;
case V_126 | V_127 :
* V_19 = F_25 ( V_65 , V_43 ) ;
break;
case V_126 | V_128 :
* V_19 = F_25 ( V_43 , V_65 ) ;
break;
case V_105 | V_22 | V_129 :
case V_117 | V_22 | V_129 :
* V_19 = F_15 ( V_22 , F_34 ( V_36 -> V_93 ) == V_105 ?
V_43 : V_65 , V_44 ,
F_16 ( struct V_3 , V_73 ) ) ;
break;
case V_117 | V_106 | V_22 :
* V_19 = F_15 ( V_22 , V_43 , V_44 , V_36 -> V_39 ) ;
break;
default:
goto V_6;
}
V_19 ++ ;
if ( V_74 )
memcpy ( V_80 , V_92 ,
sizeof( * V_19 ) * ( V_19 - V_92 ) ) ;
V_80 += V_19 - V_92 ;
}
if ( ! V_74 ) {
* V_75 = V_80 - V_74 ;
return 0 ;
}
V_77 ++ ;
if ( V_76 != V_80 - V_74 ) {
V_76 = V_80 - V_74 ;
if ( V_77 > 2 )
goto V_6;
goto V_91;
}
F_45 ( V_81 ) ;
F_29 ( * V_75 != V_76 ) ;
return 0 ;
V_6:
F_45 ( V_81 ) ;
return - V_88 ;
}
static int F_46 ( const struct V_35 * V_8 , int V_130 )
{
T_3 * V_131 , V_132 = 0 ;
int V_133 , V_134 = 0 ;
F_13 ( V_83 > 16 ) ;
V_131 = F_47 ( V_130 , sizeof( * V_131 ) , V_89 ) ;
if ( ! V_131 )
return - V_10 ;
memset ( V_131 , 0xff , V_130 * sizeof( * V_131 ) ) ;
for ( V_133 = 0 ; V_133 < V_130 ; V_133 ++ ) {
V_132 &= V_131 [ V_133 ] ;
switch ( V_8 [ V_133 ] . V_93 ) {
case V_122 :
case V_123 :
V_132 |= ( 1 << V_8 [ V_133 ] . V_39 ) ;
break;
case V_105 | V_124 :
case V_117 | V_124 :
if ( ! ( V_132 & ( 1 << V_8 [ V_133 ] . V_39 ) ) ) {
V_134 = - V_88 ;
goto error;
}
break;
case V_108 | V_109 :
V_131 [ V_133 + 1 + V_8 [ V_133 ] . V_39 ] &= V_132 ;
V_132 = ~ 0 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
V_131 [ V_133 + 1 + V_8 [ V_133 ] . V_116 ] &= V_132 ;
V_131 [ V_133 + 1 + V_8 [ V_133 ] . V_115 ] &= V_132 ;
V_132 = ~ 0 ;
break;
}
}
error:
F_45 ( V_131 ) ;
return V_134 ;
}
static bool F_48 ( T_3 V_135 )
{
static const bool V_136 [] = {
[ V_94 | V_95 | V_97 ] = true ,
[ V_94 | V_95 | V_96 ] = true ,
[ V_94 | V_98 | V_97 ] = true ,
[ V_94 | V_98 | V_96 ] = true ,
[ V_94 | V_101 | V_97 ] = true ,
[ V_94 | V_101 | V_96 ] = true ,
[ V_94 | V_102 | V_97 ] = true ,
[ V_94 | V_102 | V_96 ] = true ,
[ V_94 | V_103 | V_97 ] = true ,
[ V_94 | V_103 | V_96 ] = true ,
[ V_94 | V_25 | V_97 ] = true ,
[ V_94 | V_25 | V_96 ] = true ,
[ V_94 | V_99 | V_97 ] = true ,
[ V_94 | V_99 | V_96 ] = true ,
[ V_94 | V_72 | V_97 ] = true ,
[ V_94 | V_72 | V_96 ] = true ,
[ V_94 | V_100 | V_97 ] = true ,
[ V_94 | V_100 | V_96 ] = true ,
[ V_94 | V_27 | V_97 ] = true ,
[ V_94 | V_27 | V_96 ] = true ,
[ V_94 | V_104 ] = true ,
[ V_105 | V_22 | V_106 ] = true ,
[ V_105 | V_30 | V_106 ] = true ,
[ V_105 | V_24 | V_106 ] = true ,
[ V_105 | V_22 | V_129 ] = true ,
[ V_105 | V_22 | V_107 ] = true ,
[ V_105 | V_30 | V_107 ] = true ,
[ V_105 | V_24 | V_107 ] = true ,
[ V_105 | V_125 ] = true ,
[ V_105 | V_124 ] = true ,
[ V_117 | V_22 | V_129 ] = true ,
[ V_117 | V_24 | V_118 ] = true ,
[ V_117 | V_125 ] = true ,
[ V_117 | V_124 ] = true ,
[ V_122 ] = true ,
[ V_123 ] = true ,
[ V_126 | V_127 ] = true ,
[ V_126 | V_128 ] = true ,
[ V_119 | V_97 ] = true ,
[ V_119 | V_120 ] = true ,
[ V_108 | V_109 ] = true ,
[ V_108 | V_110 | V_97 ] = true ,
[ V_108 | V_110 | V_96 ] = true ,
[ V_108 | V_113 | V_97 ] = true ,
[ V_108 | V_113 | V_96 ] = true ,
[ V_108 | V_112 | V_97 ] = true ,
[ V_108 | V_112 | V_96 ] = true ,
[ V_108 | V_111 | V_97 ] = true ,
[ V_108 | V_111 | V_96 ] = true ,
} ;
if ( V_135 >= F_49 ( V_136 ) )
return false ;
return V_136 [ V_135 ] ;
}
static bool F_50 ( const struct V_35 * V_8 ,
unsigned int V_130 )
{
if ( V_8 == NULL )
return false ;
if ( V_130 == 0 || V_130 > V_87 )
return false ;
return true ;
}
static int F_51 ( const struct V_35 * V_8 ,
unsigned int V_130 )
{
bool V_137 ;
int V_133 ;
for ( V_133 = 0 ; V_133 < V_130 ; V_133 ++ ) {
const struct V_35 * V_138 = & V_8 [ V_133 ] ;
if ( ! F_48 ( V_138 -> V_93 ) )
return - V_88 ;
switch ( V_138 -> V_93 ) {
case V_94 | V_102 | V_97 :
case V_94 | V_103 | V_97 :
if ( V_138 -> V_39 == 0 )
return - V_88 ;
break;
case V_94 | V_100 | V_97 :
case V_94 | V_27 | V_97 :
if ( V_138 -> V_39 >= 32 )
return - V_88 ;
break;
case V_105 | V_124 :
case V_117 | V_124 :
case V_122 :
case V_123 :
if ( V_138 -> V_39 >= V_83 )
return - V_88 ;
break;
case V_108 | V_109 :
if ( V_138 -> V_39 >= ( unsigned int ) ( V_130 - V_133 - 1 ) )
return - V_88 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
if ( V_133 + V_138 -> V_116 + 1 >= V_130 ||
V_133 + V_138 -> V_115 + 1 >= V_130 )
return - V_88 ;
break;
case V_105 | V_22 | V_106 :
case V_105 | V_30 | V_106 :
case V_105 | V_24 | V_106 :
V_137 = false ;
if ( F_52 ( V_138 ) & V_139 )
V_137 = true ;
if ( V_137 == false && V_138 -> V_39 >= V_40 )
return - V_88 ;
}
}
switch ( V_8 [ V_130 - 1 ] . V_93 ) {
case V_119 | V_97 :
case V_119 | V_120 :
return F_46 ( V_8 , V_130 ) ;
}
return - V_88 ;
}
static int F_53 ( struct V_140 * V_36 ,
const struct V_141 * V_142 )
{
unsigned int V_143 = F_54 ( V_142 ) ;
struct V_144 * V_145 ;
V_36 -> V_146 = F_55 ( sizeof( * V_145 ) , V_89 ) ;
if ( ! V_36 -> V_146 )
return - V_10 ;
V_145 = V_36 -> V_146 ;
V_145 -> V_73 = V_142 -> V_73 ;
V_145 -> V_8 = F_56 ( V_36 -> V_147 , V_143 ,
V_89 | V_90 ) ;
if ( ! V_145 -> V_8 ) {
F_45 ( V_36 -> V_146 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_57 ( struct V_140 * V_36 )
{
struct V_144 * V_142 = V_36 -> V_146 ;
if ( V_142 ) {
F_45 ( V_142 -> V_8 ) ;
F_45 ( V_142 ) ;
}
}
static void F_58 ( struct V_140 * V_12 )
{
if ( V_12 -> type == V_148 ) {
F_59 ( V_12 ) ;
} else {
F_57 ( V_12 ) ;
F_60 ( V_12 ) ;
}
}
static void F_61 ( struct V_7 * V_36 )
{
F_58 ( V_36 -> V_12 ) ;
F_45 ( V_36 ) ;
}
static void F_62 ( struct V_149 * V_150 )
{
struct V_7 * V_36 = F_63 ( V_150 , struct V_7 , V_150 ) ;
F_61 ( V_36 ) ;
}
static void F_64 ( struct V_7 * V_36 )
{
if ( F_65 ( & V_36 -> V_151 ) )
F_66 ( & V_36 -> V_150 , F_62 ) ;
}
void F_67 ( struct V_1 * V_2 , struct V_7 * V_36 )
{
T_1 V_152 = F_68 ( V_36 -> V_12 -> V_73 ) ;
F_69 ( V_152 , & V_2 -> V_153 ) ;
F_64 ( V_36 ) ;
}
bool F_70 ( struct V_1 * V_2 , struct V_7 * V_36 )
{
T_1 V_152 = F_68 ( V_36 -> V_12 -> V_73 ) ;
if ( V_152 <= V_154 &&
F_71 ( & V_2 -> V_153 ) + V_152 < V_154 ) {
F_72 ( & V_36 -> V_151 ) ;
F_73 ( V_152 , & V_2 -> V_153 ) ;
return true ;
}
return false ;
}
static struct V_140 * F_74 ( struct V_140 * V_36 )
{
struct V_35 * V_155 ;
struct V_140 * V_156 ;
int V_6 , V_75 , V_157 = V_36 -> V_73 ;
F_13 ( sizeof( struct V_35 ) !=
sizeof( struct V_17 ) ) ;
V_155 = F_56 ( V_36 -> V_147 , V_157 * sizeof( struct V_35 ) ,
V_89 | V_90 ) ;
if ( ! V_155 ) {
V_6 = - V_10 ;
goto V_158;
}
V_6 = F_31 ( V_155 , V_157 , NULL , & V_75 ) ;
if ( V_6 )
goto V_159;
V_156 = V_36 ;
V_36 = F_75 ( V_156 , F_68 ( V_75 ) , 0 ) ;
if ( ! V_36 ) {
V_36 = V_156 ;
V_6 = - V_10 ;
goto V_159;
}
V_36 -> V_73 = V_75 ;
V_6 = F_31 ( V_155 , V_157 , V_36 -> V_160 , & V_75 ) ;
if ( V_6 )
goto V_159;
V_36 = F_76 ( V_36 , & V_6 ) ;
F_45 ( V_155 ) ;
return V_36 ;
V_159:
F_45 ( V_155 ) ;
V_158:
F_58 ( V_36 ) ;
return F_77 ( V_6 ) ;
}
static struct V_140 * F_78 ( struct V_140 * V_36 ,
T_4 V_161 )
{
int V_6 ;
V_36 -> V_162 = NULL ;
V_36 -> V_163 = 0 ;
V_6 = F_51 ( V_36 -> V_147 , V_36 -> V_73 ) ;
if ( V_6 ) {
F_58 ( V_36 ) ;
return F_77 ( V_6 ) ;
}
if ( V_161 ) {
V_6 = V_161 ( V_36 -> V_147 , V_36 -> V_73 ) ;
if ( V_6 ) {
F_58 ( V_36 ) ;
return F_77 ( V_6 ) ;
}
}
F_79 ( V_36 ) ;
if ( ! V_36 -> V_163 )
V_36 = F_74 ( V_36 ) ;
return V_36 ;
}
int F_80 ( struct V_140 * * V_164 , struct V_144 * V_142 )
{
unsigned int V_143 = F_54 ( V_142 ) ;
struct V_140 * V_36 ;
if ( ! F_50 ( V_142 -> V_8 , V_142 -> V_73 ) )
return - V_88 ;
V_36 = F_81 ( F_68 ( V_142 -> V_73 ) , 0 ) ;
if ( ! V_36 )
return - V_10 ;
memcpy ( V_36 -> V_147 , V_142 -> V_8 , V_143 ) ;
V_36 -> V_73 = V_142 -> V_73 ;
V_36 -> V_146 = NULL ;
V_36 = F_78 ( V_36 , NULL ) ;
if ( F_82 ( V_36 ) )
return F_83 ( V_36 ) ;
* V_164 = V_36 ;
return 0 ;
}
int F_84 ( struct V_140 * * V_164 , struct V_141 * V_142 ,
T_4 V_161 , bool V_165 )
{
unsigned int V_143 = F_54 ( V_142 ) ;
struct V_140 * V_36 ;
int V_6 ;
if ( ! F_50 ( V_142 -> V_8 , V_142 -> V_73 ) )
return - V_88 ;
V_36 = F_81 ( F_68 ( V_142 -> V_73 ) , 0 ) ;
if ( ! V_36 )
return - V_10 ;
if ( F_85 ( V_36 -> V_147 , V_142 -> V_8 , V_143 ) ) {
F_86 ( V_36 ) ;
return - V_166 ;
}
V_36 -> V_73 = V_142 -> V_73 ;
V_36 -> V_146 = NULL ;
if ( V_165 ) {
V_6 = F_53 ( V_36 , V_142 ) ;
if ( V_6 ) {
F_86 ( V_36 ) ;
return - V_10 ;
}
}
V_36 = F_78 ( V_36 , V_161 ) ;
if ( F_82 ( V_36 ) )
return F_83 ( V_36 ) ;
* V_164 = V_36 ;
return 0 ;
}
void F_87 ( struct V_140 * V_36 )
{
F_58 ( V_36 ) ;
}
static int F_88 ( struct V_140 * V_12 , struct V_1 * V_2 )
{
struct V_7 * V_36 , * V_156 ;
V_36 = F_55 ( sizeof( * V_36 ) , V_89 ) ;
if ( ! V_36 )
return - V_10 ;
V_36 -> V_12 = V_12 ;
F_89 ( & V_36 -> V_151 , 0 ) ;
if ( ! F_70 ( V_2 , V_36 ) ) {
F_45 ( V_36 ) ;
return - V_10 ;
}
V_156 = F_90 ( V_2 -> V_7 ,
F_91 ( V_2 ) ) ;
F_92 ( V_2 -> V_7 , V_36 ) ;
if ( V_156 )
F_67 ( V_2 , V_156 ) ;
return 0 ;
}
static int F_93 ( struct V_140 * V_12 , struct V_1 * V_2 )
{
struct V_140 * V_155 ;
int V_6 ;
if ( F_68 ( V_12 -> V_73 ) > V_154 )
return - V_10 ;
if ( F_94 ( V_2 ) && V_2 -> V_167 ) {
V_6 = F_95 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_96 ( V_2 -> V_168 ) ) {
return - V_88 ;
}
V_155 = F_97 ( V_2 , V_12 ) ;
if ( V_155 )
F_87 ( V_155 ) ;
return 0 ;
}
static
struct V_140 * F_98 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
unsigned int V_143 = F_54 ( V_142 ) ;
struct V_140 * V_12 ;
int V_6 ;
if ( F_3 ( V_2 , V_169 ) )
return F_77 ( - V_13 ) ;
if ( ! F_50 ( V_142 -> V_8 , V_142 -> V_73 ) )
return F_77 ( - V_88 ) ;
V_12 = F_81 ( F_68 ( V_142 -> V_73 ) , 0 ) ;
if ( ! V_12 )
return F_77 ( - V_10 ) ;
if ( F_85 ( V_12 -> V_147 , V_142 -> V_8 , V_143 ) ) {
F_86 ( V_12 ) ;
return F_77 ( - V_166 ) ;
}
V_12 -> V_73 = V_142 -> V_73 ;
V_6 = F_53 ( V_12 , V_142 ) ;
if ( V_6 ) {
F_86 ( V_12 ) ;
return F_77 ( - V_10 ) ;
}
return F_78 ( V_12 , NULL ) ;
}
int F_99 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_98 ( V_142 , V_2 ) ;
int V_6 ;
if ( F_82 ( V_12 ) )
return F_83 ( V_12 ) ;
V_6 = F_88 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_58 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_100 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_98 ( V_142 , V_2 ) ;
int V_6 ;
if ( F_82 ( V_12 ) )
return F_83 ( V_12 ) ;
V_6 = F_93 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_58 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_140 * F_101 ( T_1 V_170 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_169 ) )
return F_77 ( - V_13 ) ;
return F_102 ( V_170 , V_148 ) ;
}
int F_103 ( T_1 V_170 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_101 ( V_170 , V_2 ) ;
int V_6 ;
if ( F_82 ( V_12 ) )
return F_83 ( V_12 ) ;
V_6 = F_88 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_59 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_104 ( T_1 V_170 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_101 ( V_170 , V_2 ) ;
int V_6 ;
if ( F_82 ( V_12 ) )
return F_83 ( V_12 ) ;
V_6 = F_93 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_59 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_105 ( struct V_3 * V_4 ,
unsigned int V_171 )
{
return F_106 ( V_4 , V_171 ) ;
}
static inline int F_107 ( struct V_3 * V_4 ,
unsigned int V_171 )
{
int V_6 = F_105 ( V_4 , V_171 ) ;
F_108 ( V_4 ) ;
return V_6 ;
}
static int F_109 ( struct V_3 * V_4 )
{
return F_107 ( V_4 , F_110 ( V_4 ) ) ;
}
static inline void F_111 ( struct V_3 * V_4 )
{
if ( F_112 ( V_4 ) )
F_113 ( V_4 , F_114 ( V_4 ) , V_4 -> V_172 ) ;
}
static inline void F_115 ( struct V_3 * V_4 )
{
if ( F_112 ( V_4 ) )
F_116 ( V_4 , F_114 ( V_4 ) , V_4 -> V_172 ) ;
}
static inline int F_117 ( struct V_48 * V_50 , struct V_3 * V_4 )
{
return F_118 ( V_50 , V_4 ) ;
}
static inline int F_119 ( struct V_48 * V_50 ,
struct V_3 * V_4 )
{
int V_134 = F_120 ( V_50 , V_4 ) ;
if ( F_121 ( ! V_134 ) ) {
V_4 -> V_50 = V_50 ;
V_134 = F_122 ( V_4 ) ;
}
return V_134 ;
}
static inline int F_123 ( struct V_48 * V_50 , struct V_3 * V_4 )
{
int V_134 ;
if ( F_124 ( F_125 ( V_173 ) > V_174 ) ) {
F_126 ( L_1 ) ;
F_127 ( V_4 ) ;
return - V_175 ;
}
V_4 -> V_50 = V_50 ;
F_128 ( V_173 ) ;
V_134 = F_129 ( V_4 ) ;
F_130 ( V_173 ) ;
return V_134 ;
}
static int F_131 ( struct V_3 * V_4 , struct V_48 * V_50 ,
T_1 V_176 )
{
unsigned int V_177 = V_4 -> V_178 - V_4 -> V_179 ;
F_132 ( V_4 , V_177 ) ;
if ( ! F_112 ( V_4 ) )
F_116 ( V_4 , F_114 ( V_4 ) , V_177 ) ;
F_133 ( V_4 ) ;
F_134 ( V_4 ) ;
return V_176 & V_180 ?
F_119 ( V_50 , V_4 ) : F_123 ( V_50 , V_4 ) ;
}
static int F_135 ( struct V_3 * V_4 , struct V_48 * V_50 ,
T_1 V_176 )
{
if ( F_124 ( V_4 -> V_179 >= V_4 -> V_178 ) ) {
F_127 ( V_4 ) ;
return - V_181 ;
}
F_111 ( V_4 ) ;
return V_176 & V_180 ?
F_117 ( V_50 , V_4 ) : F_123 ( V_50 , V_4 ) ;
}
static int F_136 ( struct V_3 * V_4 , struct V_48 * V_50 ,
T_1 V_176 )
{
if ( F_137 ( V_50 ) )
return F_135 ( V_4 , V_50 , V_176 ) ;
else
return F_131 ( V_4 , V_50 , V_176 ) ;
}
int F_138 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = F_139 ( & V_182 ) ;
struct V_48 * V_50 ;
V_50 = F_140 ( F_141 ( V_4 -> V_50 ) , V_183 -> V_49 ) ;
V_183 -> V_49 = 0 ;
if ( F_124 ( ! V_50 ) ) {
F_127 ( V_4 ) ;
return - V_88 ;
}
return F_136 ( V_4 , V_50 , V_183 -> V_176 ) ;
}
static int F_142 ( struct V_3 * V_4 , T_1 V_184 , T_1 V_73 )
{
F_143 ( V_4 , V_73 ) ;
memmove ( V_4 -> V_185 , V_4 -> V_185 + V_73 , V_184 ) ;
memset ( V_4 -> V_185 + V_184 , 0 , V_73 ) ;
return 0 ;
}
static int F_144 ( struct V_3 * V_4 , T_1 V_184 , T_1 V_73 )
{
if ( F_124 ( ! F_145 ( V_4 , V_184 + V_73 ) ) )
return - V_10 ;
F_116 ( V_4 , V_4 -> V_185 + V_184 , V_73 ) ;
memmove ( V_4 -> V_185 + V_73 , V_4 -> V_185 , V_184 ) ;
F_132 ( V_4 , V_73 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_4 , T_1 V_184 , T_1 V_73 )
{
bool V_186 = V_4 -> V_187 == V_4 -> V_178 ;
int V_134 ;
V_134 = F_142 ( V_4 , V_184 , V_73 ) ;
if ( F_121 ( ! V_134 ) ) {
V_4 -> V_179 -= V_73 ;
V_4 -> V_178 -= V_73 ;
if ( V_186 )
V_4 -> V_187 = V_4 -> V_178 ;
}
return V_134 ;
}
static int F_147 ( struct V_3 * V_4 , T_1 V_184 , T_1 V_73 )
{
bool V_186 = V_4 -> V_187 == V_4 -> V_178 ;
int V_134 ;
V_134 = F_144 ( V_4 , V_184 , V_73 ) ;
if ( F_121 ( ! V_134 ) ) {
V_4 -> V_179 += V_73 ;
V_4 -> V_178 += V_73 ;
if ( V_186 )
V_4 -> V_187 = V_4 -> V_178 ;
}
return V_134 ;
}
static int F_148 ( struct V_3 * V_4 )
{
const T_1 V_188 = sizeof( struct V_189 ) - sizeof( struct V_190 ) ;
T_1 V_184 = V_4 -> V_178 - V_4 -> V_179 ;
int V_134 ;
V_134 = F_149 ( V_4 , V_188 ) ;
if ( F_124 ( V_134 < 0 ) )
return V_134 ;
V_134 = F_146 ( V_4 , V_184 , V_188 ) ;
if ( F_124 ( V_134 < 0 ) )
return V_134 ;
if ( F_150 ( V_4 ) ) {
if ( F_151 ( V_4 ) -> V_191 & V_192 ) {
F_151 ( V_4 ) -> V_191 &= ~ V_192 ;
F_151 ( V_4 ) -> V_191 |= V_193 ;
}
F_151 ( V_4 ) -> V_194 -= V_188 ;
F_151 ( V_4 ) -> V_191 |= V_195 ;
F_151 ( V_4 ) -> V_196 = 0 ;
}
V_4 -> V_42 = F_152 ( V_197 ) ;
F_153 ( V_4 ) ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 )
{
const T_1 V_188 = sizeof( struct V_189 ) - sizeof( struct V_190 ) ;
T_1 V_184 = V_4 -> V_178 - V_4 -> V_179 ;
int V_134 ;
V_134 = F_155 ( V_4 , V_198 ) ;
if ( F_124 ( V_134 < 0 ) )
return V_134 ;
V_134 = F_147 ( V_4 , V_184 , V_188 ) ;
if ( F_124 ( V_134 < 0 ) )
return V_134 ;
if ( F_150 ( V_4 ) ) {
if ( F_151 ( V_4 ) -> V_191 & V_193 ) {
F_151 ( V_4 ) -> V_191 &= ~ V_193 ;
F_151 ( V_4 ) -> V_191 |= V_192 ;
}
F_151 ( V_4 ) -> V_194 += V_188 ;
F_151 ( V_4 ) -> V_191 |= V_195 ;
F_151 ( V_4 ) -> V_196 = 0 ;
}
V_4 -> V_42 = F_152 ( V_199 ) ;
F_153 ( V_4 ) ;
return 0 ;
}
static int F_156 ( struct V_3 * V_4 , T_5 V_200 )
{
T_5 V_201 = V_4 -> V_42 ;
if ( V_201 == F_152 ( V_199 ) &&
V_200 == F_152 ( V_197 ) )
return F_148 ( V_4 ) ;
if ( V_201 == F_152 ( V_197 ) &&
V_200 == F_152 ( V_199 ) )
return F_154 ( V_4 ) ;
return - V_202 ;
}
static T_1 F_157 ( const struct V_3 * V_4 )
{
T_1 V_203 = F_158 ( V_4 ) ;
if ( F_159 ( V_4 ) )
V_203 = F_160 ( V_4 ) ;
if ( V_4 -> V_204 == V_205 )
V_203 = F_161 ( V_4 ) +
V_4 -> V_206 + sizeof( V_207 ) ;
return V_203 ;
}
static T_1 F_162 ( const struct V_3 * V_4 )
{
return V_4 -> V_50 -> V_208 + V_4 -> V_50 -> V_209 ;
}
static int F_163 ( struct V_3 * V_4 , unsigned int V_75 )
{
unsigned int V_157 = V_4 -> V_73 ;
int V_134 ;
V_134 = F_164 ( V_4 , V_75 ) ;
if ( ! V_134 )
memset ( V_4 -> V_185 + V_157 , 0 , V_75 - V_157 ) ;
return V_134 ;
}
static int F_165 ( struct V_3 * V_4 , unsigned int V_75 )
{
return F_166 ( V_4 , V_75 ) ;
}
bool F_167 ( void * V_210 )
{
if ( V_210 == V_211 ||
V_210 == V_212 ||
V_210 == V_213 ||
V_210 == V_214 ||
V_210 == V_215 ||
V_210 == V_216 ||
V_210 == V_217 ||
V_210 == V_218 ||
V_210 == V_219 ||
V_210 == V_220 )
return true ;
return false ;
}
static unsigned long F_168 ( void * V_221 , const void * V_4 ,
unsigned long V_184 , unsigned long V_73 )
{
void * V_222 = F_169 ( V_4 , V_184 , V_73 , V_221 ) ;
if ( F_124 ( ! V_222 ) )
return V_73 ;
if ( V_222 != V_221 )
memcpy ( V_221 , V_222 , V_73 ) ;
return 0 ;
}
static unsigned short F_170 ( T_6 V_176 )
{
return V_176 & V_223 ? V_224 : V_225 ;
}
static const struct V_226 *
F_171 ( enum V_227 V_228 )
{
if ( ! V_229 ) {
V_229 = F_172 ( V_230 ,
V_89 ) ;
if ( ! V_229 )
return NULL ;
}
switch ( V_228 ) {
case V_231 :
return & V_232 ;
case V_233 :
return & V_234 ;
default:
return NULL ;
}
}
static unsigned long F_173 ( void * V_221 , const void * V_235 ,
unsigned long V_184 , unsigned long V_73 )
{
memcpy ( V_221 , V_235 + V_184 , V_73 ) ;
return 0 ;
}
static const struct V_226 *
F_174 ( enum V_227 V_236 )
{
switch ( V_236 ) {
case V_237 :
return & V_238 ;
case V_239 :
return & V_240 ;
case V_241 :
return & V_242 ;
case V_243 :
return & V_244 ;
case V_245 :
return & V_246 ;
case V_247 :
return & V_248 ;
case V_249 :
return & V_250 ;
case V_251 :
return & V_252 ;
case V_253 :
if ( F_175 ( V_254 ) )
return F_176 () ;
default:
return NULL ;
}
}
static const struct V_226 *
F_177 ( enum V_227 V_236 )
{
switch ( V_236 ) {
case V_255 :
return & V_256 ;
case V_257 :
return & V_258 ;
case V_259 :
return & V_260 ;
case V_261 :
return & V_262 ;
case V_263 :
return & V_264 ;
case V_265 :
return & V_266 ;
case V_267 :
return & V_268 ;
case V_269 :
return & V_270 ;
case V_271 :
return & V_272 ;
case V_273 :
return & V_274 ;
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
case V_231 :
return F_171 ( V_236 ) ;
case V_285 :
return & V_286 ;
case V_233 :
return F_171 ( V_236 ) ;
case V_287 :
return & V_288 ;
case V_289 :
return & V_290 ;
case V_291 :
return & V_292 ;
case V_293 :
return & V_294 ;
case V_295 :
return & V_296 ;
case V_245 :
return & V_297 ;
case V_298 :
return & V_299 ;
default:
return F_174 ( V_236 ) ;
}
}
static const struct V_226 *
F_178 ( enum V_227 V_236 )
{
switch ( V_236 ) {
case V_295 :
return & V_300 ;
case V_245 :
return & V_297 ;
case V_301 :
return & V_302 ;
default:
return F_174 ( V_236 ) ;
}
}
static const struct V_226 *
F_179 ( enum V_227 V_236 )
{
switch ( V_236 ) {
case V_257 :
return & V_258 ;
default:
return F_174 ( V_236 ) ;
}
}
static const struct V_226 *
F_180 ( enum V_227 V_236 )
{
switch ( V_236 ) {
case V_257 :
return & V_258 ;
case V_259 :
return & V_260 ;
case V_261 :
return & V_262 ;
case V_271 :
return & V_272 ;
case V_289 :
return & V_290 ;
case V_291 :
return & V_292 ;
case V_295 :
return & V_296 ;
case V_245 :
return & V_297 ;
case V_298 :
return & V_299 ;
default:
return F_174 ( V_236 ) ;
}
}
static const struct V_226 *
F_181 ( enum V_227 V_236 )
{
switch ( V_236 ) {
case V_283 :
return & V_284 ;
case V_231 :
return F_171 ( V_236 ) ;
case V_285 :
return & V_286 ;
case V_233 :
return F_171 ( V_236 ) ;
case V_287 :
return & V_288 ;
case V_269 :
return & V_270 ;
case V_281 :
return & V_282 ;
case V_303 :
return & V_304 ;
case V_255 :
return & V_256 ;
case V_263 :
return & V_264 ;
case V_265 :
return & V_266 ;
case V_267 :
return & V_268 ;
case V_293 :
return & V_294 ;
default:
return F_180 ( V_236 ) ;
}
}
static bool F_182 ( int V_184 , int V_305 )
{
if ( V_184 < 0 || V_184 >= sizeof( struct V_306 ) )
return false ;
if ( V_184 % V_305 != 0 )
return false ;
if ( V_305 != sizeof( V_307 ) )
return false ;
return true ;
}
static bool F_183 ( int V_184 , int V_305 ,
enum V_308 type ,
enum V_309 * V_310 )
{
switch ( V_184 ) {
case F_16 ( struct V_306 , V_311 ) :
case F_16 ( struct V_306 , V_185 ) :
case F_16 ( struct V_306 , V_312 ) :
return false ;
}
if ( type == V_313 ) {
switch ( V_184 ) {
case F_16 ( struct V_306 , V_314 [ 0 ] ) ...
F_16 ( struct V_306 , V_314 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_182 ( V_184 , V_305 ) ;
}
static bool F_184 ( int V_184 , int V_305 ,
enum V_308 type ,
enum V_309 * V_310 )
{
switch ( V_184 ) {
case F_16 ( struct V_306 , V_311 ) :
return false ;
}
if ( type == V_313 ) {
switch ( V_184 ) {
case F_16 ( struct V_306 , V_21 ) :
case F_16 ( struct V_306 , V_315 ) :
case F_16 ( struct V_306 , V_314 [ 0 ] ) ...
F_16 ( struct V_306 , V_314 [ 4 ] ) :
break;
default:
return false ;
}
}
switch ( V_184 ) {
case F_16 ( struct V_306 , V_185 ) :
* V_310 = V_316 ;
break;
case F_16 ( struct V_306 , V_312 ) :
* V_310 = V_317 ;
break;
}
return F_182 ( V_184 , V_305 ) ;
}
static bool F_185 ( int V_184 , int V_305 ,
enum V_308 type ,
enum V_309 * V_310 )
{
if ( type == V_313 ) {
switch ( V_184 ) {
case F_16 ( struct V_318 , V_319 ) :
break;
default:
return false ;
}
}
if ( V_184 < 0 || V_184 + V_305 > sizeof( struct V_318 ) )
return false ;
if ( V_184 % V_305 != 0 )
return false ;
if ( V_305 != sizeof( V_307 ) )
return false ;
return true ;
}
static int F_186 ( struct V_17 * V_18 , bool V_320 ,
const struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
if ( ! V_320 )
return 0 ;
* V_19 ++ = F_15 ( V_24 , V_321 , V_322 , F_187 () ) ;
* V_19 ++ = F_18 ( V_25 , V_321 , V_323 ) ;
* V_19 ++ = F_23 ( V_110 , V_321 , 0 , 7 ) ;
* V_19 ++ = F_25 ( V_321 , V_322 ) ;
* V_19 ++ = F_33 ( V_72 , V_324 , V_324 ) ;
* V_19 ++ = F_36 ( V_108 | V_325 , 0 , 0 , 0 ,
V_259 ) ;
* V_19 ++ = F_23 ( V_110 , V_121 , 0 , 2 ) ;
* V_19 ++ = F_18 ( V_326 , V_121 , V_327 ) ;
* V_19 ++ = F_24 () ;
* V_19 ++ = F_25 ( V_322 , V_321 ) ;
* V_19 ++ = V_12 -> V_160 [ 0 ] ;
return V_19 - V_18 ;
}
static bool F_188 ( int V_184 , int V_305 ,
enum V_308 type ,
enum V_309 * V_310 )
{
if ( type == V_313 ) {
switch ( V_184 ) {
case F_16 ( struct V_306 , V_21 ) :
case F_16 ( struct V_306 , V_328 ) :
case F_16 ( struct V_306 , V_315 ) :
case F_16 ( struct V_306 , V_314 [ 0 ] ) ...
F_16 ( struct V_306 , V_314 [ 4 ] ) :
case F_16 ( struct V_306 , V_311 ) :
break;
default:
return false ;
}
}
switch ( V_184 ) {
case F_16 ( struct V_306 , V_185 ) :
* V_310 = V_316 ;
break;
case F_16 ( struct V_306 , V_312 ) :
* V_310 = V_317 ;
break;
}
return F_182 ( V_184 , V_305 ) ;
}
static bool F_189 ( int V_184 , int V_305 )
{
if ( V_184 < 0 || V_184 >= sizeof( struct V_329 ) )
return false ;
if ( V_184 % V_305 != 0 )
return false ;
if ( V_305 != sizeof( V_307 ) )
return false ;
return true ;
}
static bool F_190 ( int V_184 , int V_305 ,
enum V_308 type ,
enum V_309 * V_310 )
{
if ( type == V_313 )
return false ;
switch ( V_184 ) {
case F_16 ( struct V_329 , V_185 ) :
* V_310 = V_316 ;
break;
case F_16 ( struct V_329 , V_312 ) :
* V_310 = V_317 ;
break;
}
return F_189 ( V_184 , V_305 ) ;
}
void F_191 ( T_1 V_330 )
{
F_192 ( 1 , L_2 , V_330 ) ;
}
static T_1 F_193 ( enum V_308 type , int V_15 ,
int V_16 , int V_331 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_331 ) {
case F_16 ( struct V_306 , V_73 ) :
F_13 ( F_14 ( struct V_3 , V_73 ) != 4 ) ;
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_73 ) ) ;
break;
case F_16 ( struct V_306 , V_42 ) :
F_13 ( F_14 ( struct V_3 , V_42 ) != 2 ) ;
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_3 , V_42 ) ) ;
break;
case F_16 ( struct V_306 , V_56 ) :
F_13 ( F_14 ( struct V_3 , V_56 ) != 2 ) ;
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_3 , V_56 ) ) ;
break;
case F_16 ( struct V_306 , V_315 ) :
F_13 ( F_14 ( struct V_3 , V_315 ) != 4 ) ;
if ( type == V_313 )
* V_19 ++ = F_44 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_315 ) ) ;
else
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_315 ) ) ;
break;
case F_16 ( struct V_306 , V_332 ) :
F_13 ( F_14 ( struct V_3 , V_333 ) != 4 ) ;
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_333 ) ) ;
break;
case F_16 ( struct V_306 , V_49 ) :
F_13 ( F_14 ( struct V_48 , V_49 ) != 4 ) ;
* V_19 ++ = F_15 ( F_22 ( struct V_3 , V_50 ) ,
V_15 , V_16 ,
F_16 ( struct V_3 , V_50 ) ) ;
* V_19 ++ = F_23 ( V_110 , V_15 , 0 , 1 ) ;
* V_19 ++ = F_15 ( V_22 , V_15 , V_15 ,
F_16 ( struct V_48 , V_49 ) ) ;
break;
case F_16 ( struct V_306 , V_54 ) :
F_13 ( F_14 ( struct V_3 , V_54 ) != 4 ) ;
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_54 ) ) ;
break;
case F_16 ( struct V_306 , V_21 ) :
F_13 ( F_14 ( struct V_3 , V_21 ) != 4 ) ;
if ( type == V_313 )
* V_19 ++ = F_44 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_21 ) ) ;
else
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_3 , V_21 ) ) ;
break;
case F_16 ( struct V_306 , V_334 ) :
return F_12 ( V_23 , V_15 , V_16 , V_19 ) ;
case F_16 ( struct V_306 , V_29 ) :
return F_12 ( V_28 , V_15 , V_16 , V_19 ) ;
case F_16 ( struct V_306 , V_335 ) :
return F_12 ( V_32 ,
V_15 , V_16 , V_19 ) ;
case F_16 ( struct V_306 , V_33 ) :
return F_12 ( V_31 ,
V_15 , V_16 , V_19 ) ;
case F_16 ( struct V_306 , V_314 [ 0 ] ) ...
F_16 ( struct V_306 , V_314 [ 4 ] ) :
F_13 ( F_14 ( struct V_336 , V_185 ) < 20 ) ;
V_12 -> V_337 = 1 ;
V_331 -= F_16 ( struct V_306 , V_314 [ 0 ] ) ;
V_331 += F_16 ( struct V_3 , V_314 ) ;
V_331 += F_16 ( struct V_336 , V_185 ) ;
if ( type == V_313 )
* V_19 ++ = F_44 ( V_22 , V_15 , V_16 , V_331 ) ;
else
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 , V_331 ) ;
break;
case F_16 ( struct V_306 , V_311 ) :
V_331 -= F_16 ( struct V_306 , V_311 ) ;
V_331 += F_16 ( struct V_3 , V_314 ) ;
V_331 += F_16 ( struct V_336 , V_311 ) ;
if ( type == V_313 )
* V_19 ++ = F_44 ( V_30 , V_15 , V_16 , V_331 ) ;
else
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 , V_331 ) ;
break;
case F_16 ( struct V_306 , V_185 ) :
* V_19 ++ = F_15 ( F_22 ( struct V_3 , V_185 ) ,
V_15 , V_16 ,
F_16 ( struct V_3 , V_185 ) ) ;
break;
case F_16 ( struct V_306 , V_312 ) :
V_331 -= F_16 ( struct V_306 , V_312 ) ;
V_331 += F_16 ( struct V_3 , V_314 ) ;
V_331 += F_16 ( struct V_338 , V_312 ) ;
* V_19 ++ = F_15 ( F_194 ( void * ) , V_15 , V_16 ,
V_331 ) ;
break;
case F_16 ( struct V_306 , V_328 ) :
#ifdef F_195
F_13 ( F_14 ( struct V_3 , V_328 ) != 2 ) ;
if ( type == V_313 )
* V_19 ++ = F_44 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_3 , V_328 ) ) ;
else
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_3 , V_328 ) ) ;
break;
#else
if ( type == V_313 )
* V_19 ++ = F_25 ( V_15 , V_15 ) ;
else
* V_19 ++ = F_196 ( V_15 , 0 ) ;
break;
#endif
}
return V_19 - V_18 ;
}
static T_1 F_197 ( enum V_308 type ,
int V_15 , int V_16 ,
int V_331 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_331 ) {
case F_16 ( struct V_318 , V_319 ) :
F_13 ( F_14 ( struct V_1 , V_339 ) != 4 ) ;
if ( type == V_313 )
* V_19 ++ = F_44 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_1 , V_339 ) ) ;
else
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_1 , V_339 ) ) ;
break;
case F_16 ( struct V_318 , V_340 ) :
F_13 ( F_14 ( struct V_1 , V_341 ) != 2 ) ;
* V_19 ++ = F_15 ( V_30 , V_15 , V_16 ,
F_16 ( struct V_1 , V_341 ) ) ;
break;
case F_16 ( struct V_318 , type ) :
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_1 , V_342 ) ) ;
* V_19 ++ = F_18 ( V_25 , V_15 , V_343 ) ;
* V_19 ++ = F_18 ( V_27 , V_15 , V_344 ) ;
break;
case F_16 ( struct V_318 , V_42 ) :
* V_19 ++ = F_15 ( V_22 , V_15 , V_16 ,
F_16 ( struct V_1 , V_342 ) ) ;
* V_19 ++ = F_18 ( V_25 , V_15 , V_345 ) ;
* V_19 ++ = F_18 ( V_27 , V_15 , V_346 ) ;
break;
}
return V_19 - V_18 ;
}
static T_1 F_198 ( enum V_308 type , int V_15 ,
int V_16 , int V_331 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_331 ) {
case F_16 ( struct V_306 , V_49 ) :
F_13 ( F_14 ( struct V_48 , V_49 ) != 4 ) ;
* V_19 ++ = F_15 ( F_22 ( struct V_3 , V_50 ) ,
V_15 , V_16 ,
F_16 ( struct V_3 , V_50 ) ) ;
* V_19 ++ = F_15 ( V_22 , V_15 , V_15 ,
F_16 ( struct V_48 , V_49 ) ) ;
break;
default:
return F_193 ( type , V_15 , V_16 ,
V_331 , V_18 , V_12 ) ;
}
return V_19 - V_18 ;
}
static T_1 F_199 ( enum V_308 type , int V_15 ,
int V_16 , int V_331 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_331 ) {
case F_16 ( struct V_329 , V_185 ) :
* V_19 ++ = F_15 ( F_22 ( struct V_347 , V_185 ) ,
V_15 , V_16 ,
F_16 ( struct V_347 , V_185 ) ) ;
break;
case F_16 ( struct V_329 , V_312 ) :
* V_19 ++ = F_15 ( F_22 ( struct V_347 , V_312 ) ,
V_15 , V_16 ,
F_16 ( struct V_347 , V_312 ) ) ;
break;
}
return V_19 - V_18 ;
}
static int T_7 F_200 ( void )
{
F_201 ( & V_348 ) ;
F_201 ( & V_349 ) ;
F_201 ( & V_350 ) ;
F_201 ( & V_351 ) ;
F_201 ( & V_352 ) ;
F_201 ( & V_353 ) ;
F_201 ( & V_354 ) ;
F_201 ( & V_355 ) ;
F_201 ( & V_356 ) ;
return 0 ;
}
int F_202 ( struct V_1 * V_2 )
{
int V_134 = - V_357 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_169 ) )
return - V_13 ;
V_8 = F_90 ( V_2 -> V_7 ,
F_91 ( V_2 ) ) ;
if ( V_8 ) {
F_203 ( V_2 -> V_7 , NULL ) ;
F_67 ( V_2 , V_8 ) ;
V_134 = 0 ;
}
return V_134 ;
}
int F_204 ( struct V_1 * V_2 , struct V_35 T_8 * V_358 ,
unsigned int V_73 )
{
struct V_144 * V_142 ;
struct V_7 * V_8 ;
int V_134 = 0 ;
F_205 ( V_2 ) ;
V_8 = F_90 ( V_2 -> V_7 ,
F_91 ( V_2 ) ) ;
if ( ! V_8 )
goto V_359;
V_134 = - V_360 ;
V_142 = V_8 -> V_12 -> V_146 ;
if ( ! V_142 )
goto V_359;
V_134 = V_142 -> V_73 ;
if ( ! V_73 )
goto V_359;
V_134 = - V_88 ;
if ( V_73 < V_142 -> V_73 )
goto V_359;
V_134 = - V_166 ;
if ( F_206 ( V_358 , V_142 -> V_8 , F_54 ( V_142 ) ) )
goto V_359;
V_134 = V_142 -> V_73 ;
V_359:
F_207 ( V_2 ) ;
return V_134 ;
}
