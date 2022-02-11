int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned int V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
if ( F_2 ( V_4 ) && ! F_3 ( V_2 , V_9 ) )
return - V_10 ;
V_6 = F_4 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
F_5 () ;
V_8 = F_6 ( V_2 -> V_7 ) ;
if ( V_8 ) {
unsigned int V_11 = F_7 ( V_8 -> V_12 , V_4 ) ;
V_6 = V_11 ? F_8 ( V_4 , F_9 ( V_5 , V_11 ) ) : - V_13 ;
}
F_10 () ;
return V_6 ;
}
static T_1 F_11 ( int V_14 , int V_15 , int V_16 ,
struct V_17 * V_18 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_14 ) {
case V_20 :
F_12 ( F_13 ( struct V_3 , V_21 ) != 4 ) ;
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_21 ) ) ;
break;
case V_23 :
* V_19 ++ = F_14 ( V_24 , V_15 , V_16 , F_16 () ) ;
* V_19 ++ = F_17 ( V_25 , V_15 , V_26 ) ;
#ifdef F_18
* V_19 ++ = F_17 ( V_27 , V_15 , 5 ) ;
#endif
break;
case V_28 :
F_12 ( F_13 ( struct V_3 , V_29 ) != 2 ) ;
* V_19 ++ = F_14 ( V_30 , V_15 , V_16 ,
F_15 ( struct V_3 , V_29 ) ) ;
break;
case V_31 :
case V_32 :
F_12 ( F_13 ( struct V_3 , V_33 ) != 2 ) ;
F_12 ( V_34 != 0x1000 ) ;
* V_19 ++ = F_14 ( V_30 , V_15 , V_16 ,
F_15 ( struct V_3 , V_33 ) ) ;
if ( V_14 == V_31 ) {
* V_19 ++ = F_17 ( V_25 , V_15 ,
~ V_34 ) ;
} else {
* V_19 ++ = F_17 ( V_27 , V_15 , 12 ) ;
* V_19 ++ = F_17 ( V_25 , V_15 , 1 ) ;
}
break;
}
return V_19 - V_18 ;
}
static bool F_19 ( struct V_35 * V_36 ,
struct V_17 * * V_37 )
{
struct V_17 * V_19 = * V_37 ;
T_1 V_38 ;
switch ( V_36 -> V_39 ) {
case V_40 + V_41 :
F_12 ( F_13 ( struct V_3 , V_42 ) != 2 ) ;
* V_19 ++ = F_14 ( V_30 , V_43 , V_44 ,
F_15 ( struct V_3 , V_42 ) ) ;
* V_19 = F_20 ( V_45 , V_43 , 16 ) ;
break;
case V_40 + V_23 :
V_38 = F_11 ( V_23 , V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_46 :
case V_40 + V_47 :
F_12 ( F_13 ( struct V_48 , V_49 ) != 4 ) ;
F_12 ( F_13 ( struct V_48 , type ) != 2 ) ;
* V_19 ++ = F_14 ( F_21 ( struct V_3 , V_50 ) ,
V_51 , V_44 ,
F_15 ( struct V_3 , V_50 ) ) ;
* V_19 ++ = F_22 ( V_52 , V_51 , 0 , 1 ) ;
* V_19 ++ = F_23 () ;
if ( V_36 -> V_39 == V_40 + V_46 )
* V_19 = F_14 ( V_22 , V_43 , V_51 ,
F_15 ( struct V_48 , V_49 ) ) ;
else
* V_19 = F_14 ( V_30 , V_43 , V_51 ,
F_15 ( struct V_48 , type ) ) ;
break;
case V_40 + V_20 :
V_38 = F_11 ( V_20 , V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_53 :
F_12 ( F_13 ( struct V_3 , V_54 ) != 4 ) ;
* V_19 = F_14 ( V_22 , V_43 , V_44 ,
F_15 ( struct V_3 , V_54 ) ) ;
break;
case V_40 + V_28 :
V_38 = F_11 ( V_28 , V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_31 :
V_38 = F_11 ( V_31 ,
V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_32 :
V_38 = F_11 ( V_32 ,
V_43 , V_44 , V_19 ) ;
V_19 += V_38 - 1 ;
break;
case V_40 + V_55 :
F_12 ( F_13 ( struct V_3 , V_56 ) != 2 ) ;
* V_19 ++ = F_14 ( V_30 , V_43 , V_44 ,
F_15 ( struct V_3 , V_56 ) ) ;
* V_19 = F_20 ( V_45 , V_43 , 16 ) ;
break;
case V_40 + V_57 :
case V_40 + V_58 :
case V_40 + V_59 :
case V_40 + V_60 :
case V_40 + V_61 :
* V_19 ++ = F_24 ( V_62 , V_44 ) ;
* V_19 ++ = F_24 ( V_63 , V_43 ) ;
* V_19 ++ = F_24 ( V_64 , V_65 ) ;
switch ( V_36 -> V_39 ) {
case V_40 + V_57 :
* V_19 = F_25 ( V_66 ) ;
break;
case V_40 + V_58 :
* V_19 = F_25 ( V_67 ) ;
break;
case V_40 + V_59 :
* V_19 = F_25 ( V_68 ) ;
break;
case V_40 + V_60 :
* V_19 = F_25 ( V_69 ) ;
break;
case V_40 + V_61 :
* V_19 = F_25 ( V_70 ) ;
F_26 () ;
break;
}
break;
case V_40 + V_71 :
* V_19 = F_27 ( V_72 , V_43 , V_65 ) ;
break;
default:
F_28 ( F_29 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_37 = V_19 ;
return true ;
}
static int F_30 ( struct V_35 * V_12 , int V_73 ,
struct V_17 * V_74 , int * V_75 )
{
int V_76 = 0 , V_77 = 0 , V_78 , V_79 ;
struct V_17 * V_80 ;
struct V_35 * V_36 ;
int * V_81 = NULL ;
T_2 V_82 ;
F_12 ( V_83 * sizeof( T_1 ) > V_84 ) ;
F_12 ( V_85 + 1 != V_86 ) ;
if ( V_73 <= 0 || V_73 > V_87 )
return - V_88 ;
if ( V_74 ) {
V_81 = F_31 ( V_73 , sizeof( * V_81 ) ,
V_89 | V_90 ) ;
if ( ! V_81 )
return - V_10 ;
}
V_91:
V_80 = V_74 ;
V_36 = V_12 ;
if ( V_80 ) {
* V_80 ++ = F_32 ( V_72 , V_43 , V_43 ) ;
* V_80 ++ = F_32 ( V_72 , V_65 , V_65 ) ;
* V_80 ++ = F_24 ( V_44 , V_62 ) ;
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
if ( F_33 ( V_36 -> V_93 ) == V_105 &&
F_34 ( V_36 -> V_93 ) == V_106 &&
F_19 ( V_36 , & V_19 ) )
break;
* V_19 = F_35 ( V_36 -> V_93 , V_43 , V_65 , 0 , V_36 -> V_39 ) ;
break;
#define F_36 \
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
F_36 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
if ( F_37 ( V_36 -> V_93 ) == V_97 && ( int ) V_36 -> V_39 < 0 ) {
* V_19 ++ = F_38 ( V_51 , V_36 -> V_39 ) ;
V_19 -> V_15 = V_43 ;
V_19 -> V_16 = V_51 ;
V_82 = V_96 ;
} else {
V_19 -> V_15 = V_43 ;
V_19 -> V_114 = V_36 -> V_39 ;
V_82 = F_37 ( V_36 -> V_93 ) ;
V_19 -> V_16 = V_82 == V_96 ? V_65 : 0 ;
}
if ( V_36 -> V_115 == 0 ) {
V_19 -> V_93 = V_108 | F_39 ( V_36 -> V_93 ) | V_82 ;
V_78 = V_79 + V_36 -> V_116 + 1 ;
F_36 ;
break;
}
if ( V_36 -> V_116 == 0 && F_39 ( V_36 -> V_93 ) == V_110 ) {
V_19 -> V_93 = V_108 | V_52 | V_82 ;
V_78 = V_79 + V_36 -> V_115 + 1 ;
F_36 ;
break;
}
V_78 = V_79 + V_36 -> V_116 + 1 ;
V_19 -> V_93 = V_108 | F_39 ( V_36 -> V_93 ) | V_82 ;
F_36 ;
V_19 ++ ;
V_19 -> V_93 = V_108 | V_109 ;
V_78 = V_79 + V_36 -> V_115 + 1 ;
F_36 ;
break;
case V_117 | V_118 | V_24 :
* V_19 ++ = F_24 ( V_51 , V_43 ) ;
* V_19 ++ = F_40 ( V_24 , V_36 -> V_39 ) ;
* V_19 ++ = F_17 ( V_25 , V_43 , 0xf ) ;
* V_19 ++ = F_17 ( V_100 , V_43 , 2 ) ;
* V_19 ++ = F_24 ( V_65 , V_43 ) ;
* V_19 = F_24 ( V_43 , V_51 ) ;
break;
case V_119 | V_120 :
case V_119 | V_97 :
if ( F_41 ( V_36 -> V_93 ) == V_97 )
* V_19 ++ = F_42 ( V_97 , V_121 ,
0 , V_36 -> V_39 ) ;
* V_19 = F_23 () ;
break;
case V_122 :
case V_123 :
* V_19 = F_43 ( V_22 , V_85 , F_33 ( V_36 -> V_93 ) ==
V_122 ? V_43 : V_65 ,
- ( V_83 - V_36 -> V_39 ) * 4 ) ;
break;
case V_105 | V_124 :
case V_117 | V_124 :
* V_19 = F_14 ( V_22 , F_33 ( V_36 -> V_93 ) == V_105 ?
V_43 : V_65 , V_85 ,
- ( V_83 - V_36 -> V_39 ) * 4 ) ;
break;
case V_105 | V_125 :
case V_117 | V_125 :
* V_19 = F_38 ( F_33 ( V_36 -> V_93 ) == V_105 ?
V_43 : V_65 , V_36 -> V_39 ) ;
break;
case V_126 | V_127 :
* V_19 = F_24 ( V_65 , V_43 ) ;
break;
case V_126 | V_128 :
* V_19 = F_24 ( V_43 , V_65 ) ;
break;
case V_105 | V_22 | V_129 :
case V_117 | V_22 | V_129 :
* V_19 = F_14 ( V_22 , F_33 ( V_36 -> V_93 ) == V_105 ?
V_43 : V_65 , V_44 ,
F_15 ( struct V_3 , V_73 ) ) ;
break;
case V_117 | V_106 | V_22 :
* V_19 = F_14 ( V_22 , V_43 , V_44 , V_36 -> V_39 ) ;
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
F_44 ( V_81 ) ;
F_28 ( * V_75 != V_76 ) ;
return 0 ;
V_6:
F_44 ( V_81 ) ;
return - V_88 ;
}
static int F_45 ( const struct V_35 * V_8 , int V_130 )
{
T_3 * V_131 , V_132 = 0 ;
int V_133 , V_134 = 0 ;
F_12 ( V_83 > 16 ) ;
V_131 = F_46 ( V_130 , sizeof( * V_131 ) , V_89 ) ;
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
F_44 ( V_131 ) ;
return V_134 ;
}
static bool F_47 ( T_3 V_135 )
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
if ( V_135 >= F_48 ( V_136 ) )
return false ;
return V_136 [ V_135 ] ;
}
static bool F_49 ( const struct V_35 * V_8 ,
unsigned int V_130 )
{
if ( V_8 == NULL )
return false ;
if ( V_130 == 0 || V_130 > V_87 )
return false ;
return true ;
}
static int F_50 ( const struct V_35 * V_8 ,
unsigned int V_130 )
{
bool V_137 ;
int V_133 ;
for ( V_133 = 0 ; V_133 < V_130 ; V_133 ++ ) {
const struct V_35 * V_138 = & V_8 [ V_133 ] ;
if ( ! F_47 ( V_138 -> V_93 ) )
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
if ( F_51 ( V_138 ) & V_139 )
V_137 = true ;
if ( V_137 == false && V_138 -> V_39 >= V_40 )
return - V_88 ;
}
}
switch ( V_8 [ V_130 - 1 ] . V_93 ) {
case V_119 | V_97 :
case V_119 | V_120 :
return F_45 ( V_8 , V_130 ) ;
}
return - V_88 ;
}
static int F_52 ( struct V_140 * V_36 ,
const struct V_141 * V_142 )
{
unsigned int V_143 = F_53 ( V_142 ) ;
struct V_144 * V_145 ;
V_36 -> V_146 = F_54 ( sizeof( * V_145 ) , V_89 ) ;
if ( ! V_36 -> V_146 )
return - V_10 ;
V_145 = V_36 -> V_146 ;
V_145 -> V_73 = V_142 -> V_73 ;
V_145 -> V_8 = F_55 ( V_36 -> V_147 , V_143 ,
V_89 | V_90 ) ;
if ( ! V_145 -> V_8 ) {
F_44 ( V_36 -> V_146 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_56 ( struct V_140 * V_36 )
{
struct V_144 * V_142 = V_36 -> V_146 ;
if ( V_142 ) {
F_44 ( V_142 -> V_8 ) ;
F_44 ( V_142 ) ;
}
}
static void F_57 ( struct V_140 * V_12 )
{
if ( V_12 -> type == V_148 ) {
F_58 ( V_12 ) ;
} else {
F_56 ( V_12 ) ;
F_59 ( V_12 ) ;
}
}
static void F_60 ( struct V_7 * V_36 )
{
F_57 ( V_36 -> V_12 ) ;
F_44 ( V_36 ) ;
}
static void F_61 ( struct V_149 * V_150 )
{
struct V_7 * V_36 = F_62 ( V_150 , struct V_7 , V_150 ) ;
F_60 ( V_36 ) ;
}
static void F_63 ( struct V_7 * V_36 )
{
if ( F_64 ( & V_36 -> V_151 ) )
F_65 ( & V_36 -> V_150 , F_61 ) ;
}
void F_66 ( struct V_1 * V_2 , struct V_7 * V_36 )
{
T_1 V_152 = F_67 ( V_36 -> V_12 -> V_73 ) ;
F_68 ( V_152 , & V_2 -> V_153 ) ;
F_63 ( V_36 ) ;
}
bool F_69 ( struct V_1 * V_2 , struct V_7 * V_36 )
{
T_1 V_152 = F_67 ( V_36 -> V_12 -> V_73 ) ;
if ( V_152 <= V_154 &&
F_70 ( & V_2 -> V_153 ) + V_152 < V_154 ) {
F_71 ( & V_36 -> V_151 ) ;
F_72 ( V_152 , & V_2 -> V_153 ) ;
return true ;
}
return false ;
}
static struct V_140 * F_73 ( struct V_140 * V_36 )
{
struct V_35 * V_155 ;
struct V_140 * V_156 ;
int V_6 , V_75 , V_157 = V_36 -> V_73 ;
F_12 ( sizeof( struct V_35 ) !=
sizeof( struct V_17 ) ) ;
V_155 = F_55 ( V_36 -> V_147 , V_157 * sizeof( struct V_35 ) ,
V_89 | V_90 ) ;
if ( ! V_155 ) {
V_6 = - V_10 ;
goto V_158;
}
V_6 = F_30 ( V_155 , V_157 , NULL , & V_75 ) ;
if ( V_6 )
goto V_159;
V_156 = V_36 ;
V_36 = F_74 ( V_156 , F_67 ( V_75 ) , 0 ) ;
if ( ! V_36 ) {
V_36 = V_156 ;
V_6 = - V_10 ;
goto V_159;
}
V_36 -> V_73 = V_75 ;
V_6 = F_30 ( V_155 , V_157 , V_36 -> V_160 , & V_75 ) ;
if ( V_6 )
goto V_159;
V_36 = F_75 ( V_36 , & V_6 ) ;
F_44 ( V_155 ) ;
return V_36 ;
V_159:
F_44 ( V_155 ) ;
V_158:
F_57 ( V_36 ) ;
return F_76 ( V_6 ) ;
}
static struct V_140 * F_77 ( struct V_140 * V_36 ,
T_4 V_161 )
{
int V_6 ;
V_36 -> V_162 = NULL ;
V_36 -> V_163 = 0 ;
V_6 = F_50 ( V_36 -> V_147 , V_36 -> V_73 ) ;
if ( V_6 ) {
F_57 ( V_36 ) ;
return F_76 ( V_6 ) ;
}
if ( V_161 ) {
V_6 = V_161 ( V_36 -> V_147 , V_36 -> V_73 ) ;
if ( V_6 ) {
F_57 ( V_36 ) ;
return F_76 ( V_6 ) ;
}
}
F_78 ( V_36 ) ;
if ( ! V_36 -> V_163 )
V_36 = F_73 ( V_36 ) ;
return V_36 ;
}
int F_79 ( struct V_140 * * V_164 , struct V_144 * V_142 )
{
unsigned int V_143 = F_53 ( V_142 ) ;
struct V_140 * V_36 ;
if ( ! F_49 ( V_142 -> V_8 , V_142 -> V_73 ) )
return - V_88 ;
V_36 = F_80 ( F_67 ( V_142 -> V_73 ) , 0 ) ;
if ( ! V_36 )
return - V_10 ;
memcpy ( V_36 -> V_147 , V_142 -> V_8 , V_143 ) ;
V_36 -> V_73 = V_142 -> V_73 ;
V_36 -> V_146 = NULL ;
V_36 = F_77 ( V_36 , NULL ) ;
if ( F_81 ( V_36 ) )
return F_82 ( V_36 ) ;
* V_164 = V_36 ;
return 0 ;
}
int F_83 ( struct V_140 * * V_164 , struct V_141 * V_142 ,
T_4 V_161 , bool V_165 )
{
unsigned int V_143 = F_53 ( V_142 ) ;
struct V_140 * V_36 ;
int V_6 ;
if ( ! F_49 ( V_142 -> V_8 , V_142 -> V_73 ) )
return - V_88 ;
V_36 = F_80 ( F_67 ( V_142 -> V_73 ) , 0 ) ;
if ( ! V_36 )
return - V_10 ;
if ( F_84 ( V_36 -> V_147 , V_142 -> V_8 , V_143 ) ) {
F_85 ( V_36 ) ;
return - V_166 ;
}
V_36 -> V_73 = V_142 -> V_73 ;
V_36 -> V_146 = NULL ;
if ( V_165 ) {
V_6 = F_52 ( V_36 , V_142 ) ;
if ( V_6 ) {
F_85 ( V_36 ) ;
return - V_10 ;
}
}
V_36 = F_77 ( V_36 , V_161 ) ;
if ( F_81 ( V_36 ) )
return F_82 ( V_36 ) ;
* V_164 = V_36 ;
return 0 ;
}
void F_86 ( struct V_140 * V_36 )
{
F_57 ( V_36 ) ;
}
static int F_87 ( struct V_140 * V_12 , struct V_1 * V_2 )
{
struct V_7 * V_36 , * V_156 ;
V_36 = F_54 ( sizeof( * V_36 ) , V_89 ) ;
if ( ! V_36 )
return - V_10 ;
V_36 -> V_12 = V_12 ;
F_88 ( & V_36 -> V_151 , 0 ) ;
if ( ! F_69 ( V_2 , V_36 ) ) {
F_44 ( V_36 ) ;
return - V_10 ;
}
V_156 = F_89 ( V_2 -> V_7 ,
F_90 ( V_2 ) ) ;
F_91 ( V_2 -> V_7 , V_36 ) ;
if ( V_156 )
F_66 ( V_2 , V_156 ) ;
return 0 ;
}
static int F_92 ( struct V_140 * V_12 , struct V_1 * V_2 )
{
struct V_140 * V_155 ;
int V_6 ;
if ( F_67 ( V_12 -> V_73 ) > V_154 )
return - V_10 ;
if ( F_93 ( V_2 ) && V_2 -> V_167 ) {
V_6 = F_94 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_95 ( V_2 -> V_168 ) ) {
return - V_88 ;
}
V_155 = F_96 ( V_2 , V_12 ) ;
if ( V_155 )
F_86 ( V_155 ) ;
return 0 ;
}
static
struct V_140 * F_97 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
unsigned int V_143 = F_53 ( V_142 ) ;
struct V_140 * V_12 ;
int V_6 ;
if ( F_3 ( V_2 , V_169 ) )
return F_76 ( - V_13 ) ;
if ( ! F_49 ( V_142 -> V_8 , V_142 -> V_73 ) )
return F_76 ( - V_88 ) ;
V_12 = F_80 ( F_67 ( V_142 -> V_73 ) , 0 ) ;
if ( ! V_12 )
return F_76 ( - V_10 ) ;
if ( F_84 ( V_12 -> V_147 , V_142 -> V_8 , V_143 ) ) {
F_85 ( V_12 ) ;
return F_76 ( - V_166 ) ;
}
V_12 -> V_73 = V_142 -> V_73 ;
V_6 = F_52 ( V_12 , V_142 ) ;
if ( V_6 ) {
F_85 ( V_12 ) ;
return F_76 ( - V_10 ) ;
}
return F_77 ( V_12 , NULL ) ;
}
int F_98 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_97 ( V_142 , V_2 ) ;
int V_6 ;
if ( F_81 ( V_12 ) )
return F_82 ( V_12 ) ;
V_6 = F_87 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_57 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_99 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_97 ( V_142 , V_2 ) ;
int V_6 ;
if ( F_81 ( V_12 ) )
return F_82 ( V_12 ) ;
V_6 = F_92 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_57 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_140 * F_100 ( T_1 V_170 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_169 ) )
return F_76 ( - V_13 ) ;
return F_101 ( V_170 , V_148 ) ;
}
int F_102 ( T_1 V_170 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_100 ( V_170 , V_2 ) ;
int V_6 ;
if ( F_81 ( V_12 ) )
return F_82 ( V_12 ) ;
V_6 = F_87 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_58 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_103 ( T_1 V_170 , struct V_1 * V_2 )
{
struct V_140 * V_12 = F_100 ( V_170 , V_2 ) ;
int V_6 ;
if ( F_81 ( V_12 ) )
return F_82 ( V_12 ) ;
V_6 = F_92 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_58 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_104 ( struct V_3 * V_4 ,
unsigned int V_171 )
{
return F_105 ( V_4 , V_171 ) ;
}
static inline int F_106 ( struct V_3 * V_4 ,
unsigned int V_171 )
{
int V_6 = F_104 ( V_4 , V_171 ) ;
F_107 ( V_4 ) ;
return V_6 ;
}
static int F_108 ( struct V_3 * V_4 )
{
return F_106 ( V_4 , F_109 ( V_4 ) ) ;
}
static inline void F_110 ( struct V_3 * V_4 )
{
if ( F_111 ( V_4 ) )
F_112 ( V_4 , F_113 ( V_4 ) , V_4 -> V_172 ) ;
}
static inline void F_114 ( struct V_3 * V_4 )
{
if ( F_111 ( V_4 ) )
F_115 ( V_4 , F_113 ( V_4 ) , V_4 -> V_172 ) ;
}
static inline int F_116 ( struct V_48 * V_50 , struct V_3 * V_4 )
{
return F_117 ( V_50 , V_4 ) ;
}
static inline int F_118 ( struct V_48 * V_50 ,
struct V_3 * V_4 )
{
int V_134 = F_119 ( V_50 , V_4 ) ;
if ( F_120 ( ! V_134 ) ) {
V_4 -> V_50 = V_50 ;
V_134 = F_121 ( V_4 ) ;
}
return V_134 ;
}
static inline int F_122 ( struct V_48 * V_50 , struct V_3 * V_4 )
{
int V_134 ;
if ( F_123 ( F_124 ( V_173 ) > V_174 ) ) {
F_125 ( L_1 ) ;
F_126 ( V_4 ) ;
return - V_175 ;
}
V_4 -> V_50 = V_50 ;
F_127 ( V_173 ) ;
V_134 = F_128 ( V_4 ) ;
F_129 ( V_173 ) ;
return V_134 ;
}
static int F_130 ( struct V_3 * V_4 , struct V_48 * V_50 ,
T_1 V_176 )
{
unsigned int V_177 = V_4 -> V_178 - V_4 -> V_179 ;
F_131 ( V_4 , V_177 ) ;
if ( ! F_111 ( V_4 ) )
F_115 ( V_4 , F_113 ( V_4 ) , V_177 ) ;
F_132 ( V_4 ) ;
F_133 ( V_4 ) ;
return V_176 & V_180 ?
F_118 ( V_50 , V_4 ) : F_122 ( V_50 , V_4 ) ;
}
static int F_134 ( struct V_3 * V_4 , struct V_48 * V_50 ,
T_1 V_176 )
{
F_110 ( V_4 ) ;
return V_176 & V_180 ?
F_116 ( V_50 , V_4 ) : F_122 ( V_50 , V_4 ) ;
}
static int F_135 ( struct V_3 * V_4 , struct V_48 * V_50 ,
T_1 V_176 )
{
switch ( V_50 -> type ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
return F_130 ( V_4 , V_50 , V_176 ) ;
default:
return F_134 ( V_4 , V_50 , V_176 ) ;
}
}
int F_136 ( struct V_3 * V_4 )
{
struct V_187 * V_188 = F_137 ( & V_187 ) ;
struct V_48 * V_50 ;
V_50 = F_138 ( F_139 ( V_4 -> V_50 ) , V_188 -> V_49 ) ;
V_188 -> V_49 = 0 ;
if ( F_123 ( ! V_50 ) ) {
F_126 ( V_4 ) ;
return - V_88 ;
}
return F_135 ( V_4 , V_50 , V_188 -> V_176 ) ;
}
static int F_140 ( struct V_3 * V_4 , T_1 V_189 , T_1 V_73 )
{
F_141 ( V_4 , V_73 ) ;
memmove ( V_4 -> V_190 , V_4 -> V_190 + V_73 , V_189 ) ;
memset ( V_4 -> V_190 + V_189 , 0 , V_73 ) ;
return 0 ;
}
static int F_142 ( struct V_3 * V_4 , T_1 V_189 , T_1 V_73 )
{
if ( F_123 ( ! F_143 ( V_4 , V_189 + V_73 ) ) )
return - V_10 ;
F_115 ( V_4 , V_4 -> V_190 + V_189 , V_73 ) ;
memmove ( V_4 -> V_190 + V_73 , V_4 -> V_190 , V_189 ) ;
F_131 ( V_4 , V_73 ) ;
return 0 ;
}
static int F_144 ( struct V_3 * V_4 , T_1 V_189 , T_1 V_73 )
{
bool V_191 = V_4 -> V_192 == V_4 -> V_178 ;
int V_134 ;
V_134 = F_140 ( V_4 , V_189 , V_73 ) ;
if ( F_120 ( ! V_134 ) ) {
V_4 -> V_179 -= V_73 ;
V_4 -> V_178 -= V_73 ;
if ( V_191 )
V_4 -> V_192 = V_4 -> V_178 ;
}
return V_134 ;
}
static int F_145 ( struct V_3 * V_4 , T_1 V_189 , T_1 V_73 )
{
bool V_191 = V_4 -> V_192 == V_4 -> V_178 ;
int V_134 ;
V_134 = F_142 ( V_4 , V_189 , V_73 ) ;
if ( F_120 ( ! V_134 ) ) {
V_4 -> V_179 += V_73 ;
V_4 -> V_178 += V_73 ;
if ( V_191 )
V_4 -> V_192 = V_4 -> V_178 ;
}
return V_134 ;
}
static int F_146 ( struct V_3 * V_4 )
{
const T_1 V_193 = sizeof( struct V_194 ) - sizeof( struct V_195 ) ;
T_1 V_189 = V_4 -> V_178 - V_4 -> V_179 ;
int V_134 ;
V_134 = F_147 ( V_4 , V_193 ) ;
if ( F_123 ( V_134 < 0 ) )
return V_134 ;
V_134 = F_144 ( V_4 , V_189 , V_193 ) ;
if ( F_123 ( V_134 < 0 ) )
return V_134 ;
if ( F_148 ( V_4 ) ) {
if ( F_149 ( V_4 ) -> V_196 & V_197 ) {
F_149 ( V_4 ) -> V_196 &= ~ V_197 ;
F_149 ( V_4 ) -> V_196 |= V_198 ;
}
F_149 ( V_4 ) -> V_199 -= V_193 ;
F_149 ( V_4 ) -> V_196 |= V_200 ;
F_149 ( V_4 ) -> V_201 = 0 ;
}
V_4 -> V_42 = F_150 ( V_202 ) ;
F_151 ( V_4 ) ;
return 0 ;
}
static int F_152 ( struct V_3 * V_4 )
{
const T_1 V_193 = sizeof( struct V_194 ) - sizeof( struct V_195 ) ;
T_1 V_189 = V_4 -> V_178 - V_4 -> V_179 ;
int V_134 ;
V_134 = F_153 ( V_4 , V_203 ) ;
if ( F_123 ( V_134 < 0 ) )
return V_134 ;
V_134 = F_145 ( V_4 , V_189 , V_193 ) ;
if ( F_123 ( V_134 < 0 ) )
return V_134 ;
if ( F_148 ( V_4 ) ) {
if ( F_149 ( V_4 ) -> V_196 & V_198 ) {
F_149 ( V_4 ) -> V_196 &= ~ V_198 ;
F_149 ( V_4 ) -> V_196 |= V_197 ;
}
F_149 ( V_4 ) -> V_199 += V_193 ;
F_149 ( V_4 ) -> V_196 |= V_200 ;
F_149 ( V_4 ) -> V_201 = 0 ;
}
V_4 -> V_42 = F_150 ( V_204 ) ;
F_151 ( V_4 ) ;
return 0 ;
}
static int F_154 ( struct V_3 * V_4 , T_5 V_205 )
{
T_5 V_206 = V_4 -> V_42 ;
if ( V_206 == F_150 ( V_204 ) &&
V_205 == F_150 ( V_202 ) )
return F_146 ( V_4 ) ;
if ( V_206 == F_150 ( V_202 ) &&
V_205 == F_150 ( V_204 ) )
return F_152 ( V_4 ) ;
return - V_207 ;
}
static T_1 F_155 ( const struct V_3 * V_4 )
{
T_1 V_208 = F_156 ( V_4 ) ;
if ( F_157 ( V_4 ) )
V_208 = F_158 ( V_4 ) ;
if ( V_4 -> V_209 == V_210 )
V_208 = F_159 ( V_4 ) +
V_4 -> V_211 + sizeof( V_212 ) ;
return V_208 ;
}
static T_1 F_160 ( const struct V_3 * V_4 )
{
return V_4 -> V_50 -> V_213 + V_4 -> V_50 -> V_214 ;
}
static int F_161 ( struct V_3 * V_4 , unsigned int V_75 )
{
unsigned int V_157 = V_4 -> V_73 ;
int V_134 ;
V_134 = F_162 ( V_4 , V_75 ) ;
if ( ! V_134 )
memset ( V_4 -> V_190 + V_157 , 0 , V_75 - V_157 ) ;
return V_134 ;
}
static int F_163 ( struct V_3 * V_4 , unsigned int V_75 )
{
return F_164 ( V_4 , V_75 ) ;
}
bool F_165 ( void * V_215 )
{
if ( V_215 == V_216 ||
V_215 == V_217 ||
V_215 == V_218 ||
V_215 == V_219 ||
V_215 == V_220 ||
V_215 == V_221 ||
V_215 == V_222 ||
V_215 == V_223 )
return true ;
return false ;
}
static unsigned long F_166 ( void * V_224 , const void * V_4 ,
unsigned long V_189 , unsigned long V_73 )
{
void * V_225 = F_167 ( V_4 , V_189 , V_73 , V_224 ) ;
if ( F_123 ( ! V_225 ) )
return V_73 ;
if ( V_225 != V_224 )
memcpy ( V_224 , V_225 , V_73 ) ;
return 0 ;
}
static unsigned short F_168 ( T_6 V_176 )
{
return V_176 & V_226 ? V_227 : V_228 ;
}
static const struct V_229 *
F_169 ( enum V_230 V_231 )
{
if ( ! V_232 ) {
V_232 = F_170 ( V_233 ,
V_89 ) ;
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
static unsigned long F_171 ( void * V_224 , const void * V_238 ,
unsigned long V_189 , unsigned long V_73 )
{
memcpy ( V_224 , V_238 + V_189 , V_73 ) ;
return 0 ;
}
static const struct V_229 *
F_172 ( enum V_230 V_239 )
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
if ( F_173 ( V_255 ) )
return F_174 () ;
default:
return NULL ;
}
}
static const struct V_229 *
F_175 ( enum V_230 V_239 )
{
switch ( V_239 ) {
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
case V_234 :
return F_169 ( V_239 ) ;
case V_286 :
return & V_287 ;
case V_236 :
return F_169 ( V_239 ) ;
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
case V_248 :
return & V_298 ;
case V_299 :
return & V_300 ;
default:
return F_172 ( V_239 ) ;
}
}
static const struct V_229 *
F_176 ( enum V_230 V_239 )
{
switch ( V_239 ) {
case V_296 :
return & V_301 ;
case V_248 :
return & V_298 ;
default:
return F_172 ( V_239 ) ;
}
}
static bool F_177 ( int V_189 , int V_302 , enum V_303 type )
{
if ( V_189 < 0 || V_189 >= sizeof( struct V_304 ) )
return false ;
if ( V_189 % V_302 != 0 )
return false ;
if ( V_302 != sizeof( V_305 ) )
return false ;
return true ;
}
static bool F_178 ( int V_189 , int V_302 ,
enum V_303 type ,
enum V_306 * V_307 )
{
switch ( V_189 ) {
case F_15 ( struct V_304 , V_308 ) :
case F_15 ( struct V_304 , V_190 ) :
case F_15 ( struct V_304 , V_309 ) :
return false ;
}
if ( type == V_310 ) {
switch ( V_189 ) {
case F_15 ( struct V_304 , V_311 [ 0 ] ) ...
F_15 ( struct V_304 , V_311 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_177 ( V_189 , V_302 , type ) ;
}
static int F_179 ( struct V_17 * V_18 , bool V_312 ,
const struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
if ( ! V_312 )
return 0 ;
* V_19 ++ = F_14 ( V_24 , V_313 , V_314 , F_180 () ) ;
* V_19 ++ = F_17 ( V_25 , V_313 , V_315 ) ;
* V_19 ++ = F_22 ( V_110 , V_313 , 0 , 7 ) ;
* V_19 ++ = F_24 ( V_313 , V_314 ) ;
* V_19 ++ = F_32 ( V_72 , V_316 , V_316 ) ;
* V_19 ++ = F_35 ( V_108 | V_317 , 0 , 0 , 0 ,
V_260 ) ;
* V_19 ++ = F_22 ( V_110 , V_121 , 0 , 2 ) ;
* V_19 ++ = F_17 ( V_318 , V_121 , V_319 ) ;
* V_19 ++ = F_23 () ;
* V_19 ++ = F_24 ( V_314 , V_313 ) ;
* V_19 ++ = V_12 -> V_160 [ 0 ] ;
return V_19 - V_18 ;
}
static bool F_181 ( int V_189 , int V_302 ,
enum V_303 type ,
enum V_306 * V_307 )
{
if ( type == V_310 ) {
switch ( V_189 ) {
case F_15 ( struct V_304 , V_21 ) :
case F_15 ( struct V_304 , V_320 ) :
case F_15 ( struct V_304 , V_321 ) :
case F_15 ( struct V_304 , V_311 [ 0 ] ) ...
F_15 ( struct V_304 , V_311 [ 4 ] ) :
case F_15 ( struct V_304 , V_308 ) :
break;
default:
return false ;
}
}
switch ( V_189 ) {
case F_15 ( struct V_304 , V_190 ) :
* V_307 = V_322 ;
break;
case F_15 ( struct V_304 , V_309 ) :
* V_307 = V_323 ;
break;
}
return F_177 ( V_189 , V_302 , type ) ;
}
static bool F_182 ( int V_189 , int V_302 ,
enum V_303 type )
{
if ( V_189 < 0 || V_189 >= sizeof( struct V_324 ) )
return false ;
if ( V_189 % V_302 != 0 )
return false ;
if ( V_302 != sizeof( V_305 ) )
return false ;
return true ;
}
static bool F_183 ( int V_189 , int V_302 ,
enum V_303 type ,
enum V_306 * V_307 )
{
if ( type == V_310 )
return false ;
switch ( V_189 ) {
case F_15 ( struct V_324 , V_190 ) :
* V_307 = V_322 ;
break;
case F_15 ( struct V_324 , V_309 ) :
* V_307 = V_323 ;
break;
}
return F_182 ( V_189 , V_302 , type ) ;
}
void F_184 ( T_1 V_325 )
{
F_185 ( 1 , L_2 , V_325 ) ;
}
static T_1 F_186 ( enum V_303 type , int V_15 ,
int V_16 , int V_326 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_326 ) {
case F_15 ( struct V_304 , V_73 ) :
F_12 ( F_13 ( struct V_3 , V_73 ) != 4 ) ;
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_73 ) ) ;
break;
case F_15 ( struct V_304 , V_42 ) :
F_12 ( F_13 ( struct V_3 , V_42 ) != 2 ) ;
* V_19 ++ = F_14 ( V_30 , V_15 , V_16 ,
F_15 ( struct V_3 , V_42 ) ) ;
break;
case F_15 ( struct V_304 , V_56 ) :
F_12 ( F_13 ( struct V_3 , V_56 ) != 2 ) ;
* V_19 ++ = F_14 ( V_30 , V_15 , V_16 ,
F_15 ( struct V_3 , V_56 ) ) ;
break;
case F_15 ( struct V_304 , V_321 ) :
F_12 ( F_13 ( struct V_3 , V_321 ) != 4 ) ;
if ( type == V_310 )
* V_19 ++ = F_43 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_321 ) ) ;
else
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_321 ) ) ;
break;
case F_15 ( struct V_304 , V_327 ) :
F_12 ( F_13 ( struct V_3 , V_328 ) != 4 ) ;
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_328 ) ) ;
break;
case F_15 ( struct V_304 , V_49 ) :
F_12 ( F_13 ( struct V_48 , V_49 ) != 4 ) ;
* V_19 ++ = F_14 ( F_21 ( struct V_3 , V_50 ) ,
V_15 , V_16 ,
F_15 ( struct V_3 , V_50 ) ) ;
* V_19 ++ = F_22 ( V_110 , V_15 , 0 , 1 ) ;
* V_19 ++ = F_14 ( V_22 , V_15 , V_15 ,
F_15 ( struct V_48 , V_49 ) ) ;
break;
case F_15 ( struct V_304 , V_54 ) :
F_12 ( F_13 ( struct V_3 , V_54 ) != 4 ) ;
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_54 ) ) ;
break;
case F_15 ( struct V_304 , V_21 ) :
F_12 ( F_13 ( struct V_3 , V_21 ) != 4 ) ;
if ( type == V_310 )
* V_19 ++ = F_43 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_21 ) ) ;
else
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 ,
F_15 ( struct V_3 , V_21 ) ) ;
break;
case F_15 ( struct V_304 , V_329 ) :
return F_11 ( V_23 , V_15 , V_16 , V_19 ) ;
case F_15 ( struct V_304 , V_29 ) :
return F_11 ( V_28 , V_15 , V_16 , V_19 ) ;
case F_15 ( struct V_304 , V_330 ) :
return F_11 ( V_32 ,
V_15 , V_16 , V_19 ) ;
case F_15 ( struct V_304 , V_33 ) :
return F_11 ( V_31 ,
V_15 , V_16 , V_19 ) ;
case F_15 ( struct V_304 , V_311 [ 0 ] ) ...
F_15 ( struct V_304 , V_311 [ 4 ] ) :
F_12 ( F_13 ( struct V_331 , V_190 ) < 20 ) ;
V_12 -> V_332 = 1 ;
V_326 -= F_15 ( struct V_304 , V_311 [ 0 ] ) ;
V_326 += F_15 ( struct V_3 , V_311 ) ;
V_326 += F_15 ( struct V_331 , V_190 ) ;
if ( type == V_310 )
* V_19 ++ = F_43 ( V_22 , V_15 , V_16 , V_326 ) ;
else
* V_19 ++ = F_14 ( V_22 , V_15 , V_16 , V_326 ) ;
break;
case F_15 ( struct V_304 , V_308 ) :
V_326 -= F_15 ( struct V_304 , V_308 ) ;
V_326 += F_15 ( struct V_3 , V_311 ) ;
V_326 += F_15 ( struct V_331 , V_308 ) ;
if ( type == V_310 )
* V_19 ++ = F_43 ( V_30 , V_15 , V_16 , V_326 ) ;
else
* V_19 ++ = F_14 ( V_30 , V_15 , V_16 , V_326 ) ;
break;
case F_15 ( struct V_304 , V_190 ) :
* V_19 ++ = F_14 ( F_21 ( struct V_3 , V_190 ) ,
V_15 , V_16 ,
F_15 ( struct V_3 , V_190 ) ) ;
break;
case F_15 ( struct V_304 , V_309 ) :
V_326 -= F_15 ( struct V_304 , V_309 ) ;
V_326 += F_15 ( struct V_3 , V_311 ) ;
V_326 += F_15 ( struct V_333 , V_309 ) ;
* V_19 ++ = F_14 ( F_187 ( void * ) , V_15 , V_16 ,
V_326 ) ;
break;
case F_15 ( struct V_304 , V_320 ) :
#ifdef F_188
F_12 ( F_13 ( struct V_3 , V_320 ) != 2 ) ;
if ( type == V_310 )
* V_19 ++ = F_43 ( V_30 , V_15 , V_16 ,
F_15 ( struct V_3 , V_320 ) ) ;
else
* V_19 ++ = F_14 ( V_30 , V_15 , V_16 ,
F_15 ( struct V_3 , V_320 ) ) ;
break;
#else
if ( type == V_310 )
* V_19 ++ = F_24 ( V_15 , V_15 ) ;
else
* V_19 ++ = F_189 ( V_15 , 0 ) ;
break;
#endif
}
return V_19 - V_18 ;
}
static T_1 F_190 ( enum V_303 type , int V_15 ,
int V_16 , int V_326 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_326 ) {
case F_15 ( struct V_304 , V_49 ) :
F_12 ( F_13 ( struct V_48 , V_49 ) != 4 ) ;
* V_19 ++ = F_14 ( F_21 ( struct V_3 , V_50 ) ,
V_15 , V_16 ,
F_15 ( struct V_3 , V_50 ) ) ;
* V_19 ++ = F_14 ( V_22 , V_15 , V_15 ,
F_15 ( struct V_48 , V_49 ) ) ;
break;
default:
return F_186 ( type , V_15 , V_16 ,
V_326 , V_18 , V_12 ) ;
}
return V_19 - V_18 ;
}
static T_1 F_191 ( enum V_303 type , int V_15 ,
int V_16 , int V_326 ,
struct V_17 * V_18 ,
struct V_140 * V_12 )
{
struct V_17 * V_19 = V_18 ;
switch ( V_326 ) {
case F_15 ( struct V_324 , V_190 ) :
* V_19 ++ = F_14 ( F_21 ( struct V_334 , V_190 ) ,
V_15 , V_16 ,
F_15 ( struct V_334 , V_190 ) ) ;
break;
case F_15 ( struct V_324 , V_309 ) :
* V_19 ++ = F_14 ( F_21 ( struct V_334 , V_309 ) ,
V_15 , V_16 ,
F_15 ( struct V_334 , V_309 ) ) ;
break;
}
return V_19 - V_18 ;
}
static int T_7 F_192 ( void )
{
F_193 ( & V_335 ) ;
F_193 ( & V_336 ) ;
F_193 ( & V_337 ) ;
F_193 ( & V_338 ) ;
return 0 ;
}
int F_194 ( struct V_1 * V_2 )
{
int V_134 = - V_339 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_169 ) )
return - V_13 ;
V_8 = F_89 ( V_2 -> V_7 ,
F_90 ( V_2 ) ) ;
if ( V_8 ) {
F_195 ( V_2 -> V_7 , NULL ) ;
F_66 ( V_2 , V_8 ) ;
V_134 = 0 ;
}
return V_134 ;
}
int F_196 ( struct V_1 * V_2 , struct V_35 T_8 * V_340 ,
unsigned int V_73 )
{
struct V_144 * V_142 ;
struct V_7 * V_8 ;
int V_134 = 0 ;
F_197 ( V_2 ) ;
V_8 = F_89 ( V_2 -> V_7 ,
F_90 ( V_2 ) ) ;
if ( ! V_8 )
goto V_341;
V_134 = - V_342 ;
V_142 = V_8 -> V_12 -> V_146 ;
if ( ! V_142 )
goto V_341;
V_134 = V_142 -> V_73 ;
if ( ! V_73 )
goto V_341;
V_134 = - V_88 ;
if ( V_73 < V_142 -> V_73 )
goto V_341;
V_134 = - V_166 ;
if ( F_198 ( V_340 , V_142 -> V_8 , F_53 ( V_142 ) ) )
goto V_341;
V_134 = V_142 -> V_73 ;
V_341:
F_199 ( V_2 ) ;
return V_134 ;
}
