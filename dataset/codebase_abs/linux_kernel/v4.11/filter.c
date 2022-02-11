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
unsigned int V_12 = F_10 ( V_8 -> V_13 , V_4 ) ;
V_6 = V_12 ? F_11 ( V_4 , F_12 ( V_5 , V_12 ) ) : - V_14 ;
}
F_13 () ;
return V_6 ;
}
static T_1 F_14 ( int V_15 , int V_16 , int V_17 ,
struct V_18 * V_19 )
{
struct V_18 * V_20 = V_19 ;
switch ( V_15 ) {
case V_21 :
F_15 ( F_16 ( struct V_3 , V_22 ) != 4 ) ;
* V_20 ++ = F_17 ( V_23 , V_16 , V_17 ,
F_18 ( struct V_3 , V_22 ) ) ;
break;
case V_24 :
* V_20 ++ = F_17 ( V_25 , V_16 , V_17 , F_19 () ) ;
* V_20 ++ = F_20 ( V_26 , V_16 , V_27 ) ;
#ifdef F_21
* V_20 ++ = F_20 ( V_28 , V_16 , 5 ) ;
#endif
break;
case V_29 :
F_15 ( F_16 ( struct V_3 , V_30 ) != 2 ) ;
* V_20 ++ = F_17 ( V_31 , V_16 , V_17 ,
F_18 ( struct V_3 , V_30 ) ) ;
break;
case V_32 :
case V_33 :
F_15 ( F_16 ( struct V_3 , V_34 ) != 2 ) ;
F_15 ( V_35 != 0x1000 ) ;
* V_20 ++ = F_17 ( V_31 , V_16 , V_17 ,
F_18 ( struct V_3 , V_34 ) ) ;
if ( V_15 == V_32 ) {
* V_20 ++ = F_20 ( V_26 , V_16 ,
~ V_35 ) ;
} else {
* V_20 ++ = F_20 ( V_28 , V_16 , 12 ) ;
* V_20 ++ = F_20 ( V_26 , V_16 , 1 ) ;
}
break;
}
return V_20 - V_19 ;
}
static bool F_22 ( struct V_36 * V_37 ,
struct V_18 * * V_38 )
{
struct V_18 * V_20 = * V_38 ;
T_1 V_39 ;
switch ( V_37 -> V_40 ) {
case V_41 + V_42 :
F_15 ( F_16 ( struct V_3 , V_43 ) != 2 ) ;
* V_20 ++ = F_17 ( V_31 , V_44 , V_45 ,
F_18 ( struct V_3 , V_43 ) ) ;
* V_20 = F_23 ( V_46 , V_44 , 16 ) ;
break;
case V_41 + V_24 :
V_39 = F_14 ( V_24 , V_44 , V_45 , V_20 ) ;
V_20 += V_39 - 1 ;
break;
case V_41 + V_47 :
case V_41 + V_48 :
F_15 ( F_16 ( struct V_49 , V_50 ) != 4 ) ;
F_15 ( F_16 ( struct V_49 , type ) != 2 ) ;
* V_20 ++ = F_17 ( F_24 ( struct V_3 , V_51 ) ,
V_52 , V_45 ,
F_18 ( struct V_3 , V_51 ) ) ;
* V_20 ++ = F_25 ( V_53 , V_52 , 0 , 1 ) ;
* V_20 ++ = F_26 () ;
if ( V_37 -> V_40 == V_41 + V_47 )
* V_20 = F_17 ( V_23 , V_44 , V_52 ,
F_18 ( struct V_49 , V_50 ) ) ;
else
* V_20 = F_17 ( V_31 , V_44 , V_52 ,
F_18 ( struct V_49 , type ) ) ;
break;
case V_41 + V_21 :
V_39 = F_14 ( V_21 , V_44 , V_45 , V_20 ) ;
V_20 += V_39 - 1 ;
break;
case V_41 + V_54 :
F_15 ( F_16 ( struct V_3 , V_55 ) != 4 ) ;
* V_20 = F_17 ( V_23 , V_44 , V_45 ,
F_18 ( struct V_3 , V_55 ) ) ;
break;
case V_41 + V_29 :
V_39 = F_14 ( V_29 , V_44 , V_45 , V_20 ) ;
V_20 += V_39 - 1 ;
break;
case V_41 + V_32 :
V_39 = F_14 ( V_32 ,
V_44 , V_45 , V_20 ) ;
V_20 += V_39 - 1 ;
break;
case V_41 + V_33 :
V_39 = F_14 ( V_33 ,
V_44 , V_45 , V_20 ) ;
V_20 += V_39 - 1 ;
break;
case V_41 + V_56 :
F_15 ( F_16 ( struct V_3 , V_57 ) != 2 ) ;
* V_20 ++ = F_17 ( V_31 , V_44 , V_45 ,
F_18 ( struct V_3 , V_57 ) ) ;
* V_20 = F_23 ( V_46 , V_44 , 16 ) ;
break;
case V_41 + V_58 :
case V_41 + V_59 :
case V_41 + V_60 :
case V_41 + V_61 :
case V_41 + V_62 :
* V_20 ++ = F_27 ( V_63 , V_45 ) ;
* V_20 ++ = F_27 ( V_64 , V_44 ) ;
* V_20 ++ = F_27 ( V_65 , V_66 ) ;
switch ( V_37 -> V_40 ) {
case V_41 + V_58 :
* V_20 = F_28 ( V_67 ) ;
break;
case V_41 + V_59 :
* V_20 = F_28 ( V_68 ) ;
break;
case V_41 + V_60 :
* V_20 = F_28 ( V_69 ) ;
break;
case V_41 + V_61 :
* V_20 = F_28 ( V_70 ) ;
break;
case V_41 + V_62 :
* V_20 = F_28 ( V_71 ) ;
F_29 () ;
break;
}
break;
case V_41 + V_72 :
* V_20 = F_30 ( V_73 , V_44 , V_66 ) ;
break;
default:
F_31 ( F_32 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_38 = V_20 ;
return true ;
}
static int F_33 ( struct V_36 * V_13 , int V_74 ,
struct V_18 * V_75 , int * V_76 )
{
int V_77 = 0 , V_78 = 0 , V_79 , V_80 ;
struct V_18 * V_81 ;
struct V_36 * V_37 ;
int * V_82 = NULL ;
T_2 V_83 ;
F_15 ( V_84 * sizeof( T_1 ) > V_85 ) ;
F_15 ( V_86 + 1 != V_87 ) ;
if ( V_74 <= 0 || V_74 > V_88 )
return - V_89 ;
if ( V_75 ) {
V_82 = F_34 ( V_74 , sizeof( * V_82 ) ,
V_90 | V_91 ) ;
if ( ! V_82 )
return - V_11 ;
}
V_92:
V_81 = V_75 ;
V_37 = V_13 ;
if ( V_81 ) {
* V_81 ++ = F_35 ( V_73 , V_44 , V_44 ) ;
* V_81 ++ = F_35 ( V_73 , V_66 , V_66 ) ;
* V_81 ++ = F_27 ( V_45 , V_63 ) ;
} else {
V_81 += 3 ;
}
for ( V_80 = 0 ; V_80 < V_74 ; V_37 ++ , V_80 ++ ) {
struct V_18 V_93 [ 6 ] = { } ;
struct V_18 * V_20 = V_93 ;
if ( V_82 )
V_82 [ V_80 ] = V_81 - V_75 ;
switch ( V_37 -> V_94 ) {
case V_95 | V_96 | V_97 :
case V_95 | V_96 | V_98 :
case V_95 | V_99 | V_97 :
case V_95 | V_99 | V_98 :
case V_95 | V_26 | V_97 :
case V_95 | V_26 | V_98 :
case V_95 | V_100 | V_97 :
case V_95 | V_100 | V_98 :
case V_95 | V_101 | V_97 :
case V_95 | V_101 | V_98 :
case V_95 | V_28 | V_97 :
case V_95 | V_28 | V_98 :
case V_95 | V_73 | V_97 :
case V_95 | V_73 | V_98 :
case V_95 | V_102 | V_97 :
case V_95 | V_102 | V_98 :
case V_95 | V_103 | V_97 :
case V_95 | V_103 | V_98 :
case V_95 | V_104 | V_97 :
case V_95 | V_104 | V_98 :
case V_95 | V_105 :
case V_106 | V_107 | V_23 :
case V_106 | V_107 | V_31 :
case V_106 | V_107 | V_25 :
case V_106 | V_108 | V_23 :
case V_106 | V_108 | V_31 :
case V_106 | V_108 | V_25 :
if ( F_36 ( V_37 -> V_94 ) == V_106 &&
F_37 ( V_37 -> V_94 ) == V_107 &&
F_22 ( V_37 , & V_20 ) )
break;
* V_20 = F_38 ( V_37 -> V_94 , V_44 , V_66 , 0 , V_37 -> V_40 ) ;
break;
#define F_39 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_109 | V_110 :
V_79 = V_80 + V_37 -> V_40 + 1 ;
V_20 -> V_94 = V_37 -> V_94 ;
F_39 ;
break;
case V_109 | V_111 | V_98 :
case V_109 | V_111 | V_97 :
case V_109 | V_112 | V_98 :
case V_109 | V_112 | V_97 :
case V_109 | V_113 | V_98 :
case V_109 | V_113 | V_97 :
case V_109 | V_114 | V_98 :
case V_109 | V_114 | V_97 :
if ( F_40 ( V_37 -> V_94 ) == V_98 && ( int ) V_37 -> V_40 < 0 ) {
* V_20 ++ = F_41 ( V_52 , V_37 -> V_40 ) ;
V_20 -> V_16 = V_44 ;
V_20 -> V_17 = V_52 ;
V_83 = V_97 ;
} else {
V_20 -> V_16 = V_44 ;
V_20 -> V_115 = V_37 -> V_40 ;
V_83 = F_40 ( V_37 -> V_94 ) ;
V_20 -> V_17 = V_83 == V_97 ? V_66 : 0 ;
}
if ( V_37 -> V_116 == 0 ) {
V_20 -> V_94 = V_109 | F_42 ( V_37 -> V_94 ) | V_83 ;
V_79 = V_80 + V_37 -> V_117 + 1 ;
F_39 ;
break;
}
if ( V_37 -> V_117 == 0 && F_42 ( V_37 -> V_94 ) == V_111 ) {
V_20 -> V_94 = V_109 | V_53 | V_83 ;
V_79 = V_80 + V_37 -> V_116 + 1 ;
F_39 ;
break;
}
V_79 = V_80 + V_37 -> V_117 + 1 ;
V_20 -> V_94 = V_109 | F_42 ( V_37 -> V_94 ) | V_83 ;
F_39 ;
V_20 ++ ;
V_20 -> V_94 = V_109 | V_110 ;
V_79 = V_80 + V_37 -> V_116 + 1 ;
F_39 ;
break;
case V_118 | V_119 | V_25 :
* V_20 ++ = F_27 ( V_52 , V_44 ) ;
* V_20 ++ = F_43 ( V_25 , V_37 -> V_40 ) ;
* V_20 ++ = F_20 ( V_26 , V_44 , 0xf ) ;
* V_20 ++ = F_20 ( V_101 , V_44 , 2 ) ;
* V_20 ++ = F_27 ( V_66 , V_44 ) ;
* V_20 = F_27 ( V_44 , V_52 ) ;
break;
case V_120 | V_121 :
case V_120 | V_98 :
if ( F_44 ( V_37 -> V_94 ) == V_98 )
* V_20 ++ = F_45 ( V_98 , V_122 ,
0 , V_37 -> V_40 ) ;
* V_20 = F_26 () ;
break;
case V_123 :
case V_124 :
* V_20 = F_46 ( V_23 , V_86 , F_36 ( V_37 -> V_94 ) ==
V_123 ? V_44 : V_66 ,
- ( V_84 - V_37 -> V_40 ) * 4 ) ;
break;
case V_106 | V_125 :
case V_118 | V_125 :
* V_20 = F_17 ( V_23 , F_36 ( V_37 -> V_94 ) == V_106 ?
V_44 : V_66 , V_86 ,
- ( V_84 - V_37 -> V_40 ) * 4 ) ;
break;
case V_106 | V_126 :
case V_118 | V_126 :
* V_20 = F_41 ( F_36 ( V_37 -> V_94 ) == V_106 ?
V_44 : V_66 , V_37 -> V_40 ) ;
break;
case V_127 | V_128 :
* V_20 = F_27 ( V_66 , V_44 ) ;
break;
case V_127 | V_129 :
* V_20 = F_27 ( V_44 , V_66 ) ;
break;
case V_106 | V_23 | V_130 :
case V_118 | V_23 | V_130 :
* V_20 = F_17 ( V_23 , F_36 ( V_37 -> V_94 ) == V_106 ?
V_44 : V_66 , V_45 ,
F_18 ( struct V_3 , V_74 ) ) ;
break;
case V_118 | V_107 | V_23 :
* V_20 = F_17 ( V_23 , V_44 , V_45 , V_37 -> V_40 ) ;
break;
default:
goto V_6;
}
V_20 ++ ;
if ( V_75 )
memcpy ( V_81 , V_93 ,
sizeof( * V_20 ) * ( V_20 - V_93 ) ) ;
V_81 += V_20 - V_93 ;
}
if ( ! V_75 ) {
* V_76 = V_81 - V_75 ;
return 0 ;
}
V_78 ++ ;
if ( V_77 != V_81 - V_75 ) {
V_77 = V_81 - V_75 ;
if ( V_78 > 2 )
goto V_6;
goto V_92;
}
F_47 ( V_82 ) ;
F_31 ( * V_76 != V_77 ) ;
return 0 ;
V_6:
F_47 ( V_82 ) ;
return - V_89 ;
}
static int F_48 ( const struct V_36 * V_8 , int V_131 )
{
T_3 * V_132 , V_133 = 0 ;
int V_134 , V_135 = 0 ;
F_15 ( V_84 > 16 ) ;
V_132 = F_49 ( V_131 , sizeof( * V_132 ) , V_90 ) ;
if ( ! V_132 )
return - V_11 ;
memset ( V_132 , 0xff , V_131 * sizeof( * V_132 ) ) ;
for ( V_134 = 0 ; V_134 < V_131 ; V_134 ++ ) {
V_133 &= V_132 [ V_134 ] ;
switch ( V_8 [ V_134 ] . V_94 ) {
case V_123 :
case V_124 :
V_133 |= ( 1 << V_8 [ V_134 ] . V_40 ) ;
break;
case V_106 | V_125 :
case V_118 | V_125 :
if ( ! ( V_133 & ( 1 << V_8 [ V_134 ] . V_40 ) ) ) {
V_135 = - V_89 ;
goto error;
}
break;
case V_109 | V_110 :
V_132 [ V_134 + 1 + V_8 [ V_134 ] . V_40 ] &= V_133 ;
V_133 = ~ 0 ;
break;
case V_109 | V_111 | V_98 :
case V_109 | V_111 | V_97 :
case V_109 | V_114 | V_98 :
case V_109 | V_114 | V_97 :
case V_109 | V_113 | V_98 :
case V_109 | V_113 | V_97 :
case V_109 | V_112 | V_98 :
case V_109 | V_112 | V_97 :
V_132 [ V_134 + 1 + V_8 [ V_134 ] . V_117 ] &= V_133 ;
V_132 [ V_134 + 1 + V_8 [ V_134 ] . V_116 ] &= V_133 ;
V_133 = ~ 0 ;
break;
}
}
error:
F_47 ( V_132 ) ;
return V_135 ;
}
static bool F_50 ( T_3 V_136 )
{
static const bool V_137 [] = {
[ V_95 | V_96 | V_98 ] = true ,
[ V_95 | V_96 | V_97 ] = true ,
[ V_95 | V_99 | V_98 ] = true ,
[ V_95 | V_99 | V_97 ] = true ,
[ V_95 | V_102 | V_98 ] = true ,
[ V_95 | V_102 | V_97 ] = true ,
[ V_95 | V_103 | V_98 ] = true ,
[ V_95 | V_103 | V_97 ] = true ,
[ V_95 | V_104 | V_98 ] = true ,
[ V_95 | V_104 | V_97 ] = true ,
[ V_95 | V_26 | V_98 ] = true ,
[ V_95 | V_26 | V_97 ] = true ,
[ V_95 | V_100 | V_98 ] = true ,
[ V_95 | V_100 | V_97 ] = true ,
[ V_95 | V_73 | V_98 ] = true ,
[ V_95 | V_73 | V_97 ] = true ,
[ V_95 | V_101 | V_98 ] = true ,
[ V_95 | V_101 | V_97 ] = true ,
[ V_95 | V_28 | V_98 ] = true ,
[ V_95 | V_28 | V_97 ] = true ,
[ V_95 | V_105 ] = true ,
[ V_106 | V_23 | V_107 ] = true ,
[ V_106 | V_31 | V_107 ] = true ,
[ V_106 | V_25 | V_107 ] = true ,
[ V_106 | V_23 | V_130 ] = true ,
[ V_106 | V_23 | V_108 ] = true ,
[ V_106 | V_31 | V_108 ] = true ,
[ V_106 | V_25 | V_108 ] = true ,
[ V_106 | V_126 ] = true ,
[ V_106 | V_125 ] = true ,
[ V_118 | V_23 | V_130 ] = true ,
[ V_118 | V_25 | V_119 ] = true ,
[ V_118 | V_126 ] = true ,
[ V_118 | V_125 ] = true ,
[ V_123 ] = true ,
[ V_124 ] = true ,
[ V_127 | V_128 ] = true ,
[ V_127 | V_129 ] = true ,
[ V_120 | V_98 ] = true ,
[ V_120 | V_121 ] = true ,
[ V_109 | V_110 ] = true ,
[ V_109 | V_111 | V_98 ] = true ,
[ V_109 | V_111 | V_97 ] = true ,
[ V_109 | V_114 | V_98 ] = true ,
[ V_109 | V_114 | V_97 ] = true ,
[ V_109 | V_113 | V_98 ] = true ,
[ V_109 | V_113 | V_97 ] = true ,
[ V_109 | V_112 | V_98 ] = true ,
[ V_109 | V_112 | V_97 ] = true ,
} ;
if ( V_136 >= F_51 ( V_137 ) )
return false ;
return V_137 [ V_136 ] ;
}
static bool F_52 ( const struct V_36 * V_8 ,
unsigned int V_131 )
{
if ( V_8 == NULL )
return false ;
if ( V_131 == 0 || V_131 > V_88 )
return false ;
return true ;
}
static int F_53 ( const struct V_36 * V_8 ,
unsigned int V_131 )
{
bool V_138 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < V_131 ; V_134 ++ ) {
const struct V_36 * V_139 = & V_8 [ V_134 ] ;
if ( ! F_50 ( V_139 -> V_94 ) )
return - V_89 ;
switch ( V_139 -> V_94 ) {
case V_95 | V_103 | V_98 :
case V_95 | V_104 | V_98 :
if ( V_139 -> V_40 == 0 )
return - V_89 ;
break;
case V_95 | V_101 | V_98 :
case V_95 | V_28 | V_98 :
if ( V_139 -> V_40 >= 32 )
return - V_89 ;
break;
case V_106 | V_125 :
case V_118 | V_125 :
case V_123 :
case V_124 :
if ( V_139 -> V_40 >= V_84 )
return - V_89 ;
break;
case V_109 | V_110 :
if ( V_139 -> V_40 >= ( unsigned int ) ( V_131 - V_134 - 1 ) )
return - V_89 ;
break;
case V_109 | V_111 | V_98 :
case V_109 | V_111 | V_97 :
case V_109 | V_114 | V_98 :
case V_109 | V_114 | V_97 :
case V_109 | V_113 | V_98 :
case V_109 | V_113 | V_97 :
case V_109 | V_112 | V_98 :
case V_109 | V_112 | V_97 :
if ( V_134 + V_139 -> V_117 + 1 >= V_131 ||
V_134 + V_139 -> V_116 + 1 >= V_131 )
return - V_89 ;
break;
case V_106 | V_23 | V_107 :
case V_106 | V_31 | V_107 :
case V_106 | V_25 | V_107 :
V_138 = false ;
if ( F_54 ( V_139 ) & V_140 )
V_138 = true ;
if ( V_138 == false && V_139 -> V_40 >= V_41 )
return - V_89 ;
}
}
switch ( V_8 [ V_131 - 1 ] . V_94 ) {
case V_120 | V_98 :
case V_120 | V_121 :
return F_48 ( V_8 , V_131 ) ;
}
return - V_89 ;
}
static int F_55 ( struct V_141 * V_37 ,
const struct V_142 * V_143 )
{
unsigned int V_144 = F_56 ( V_143 ) ;
struct V_145 * V_146 ;
V_37 -> V_147 = F_57 ( sizeof( * V_146 ) , V_90 ) ;
if ( ! V_37 -> V_147 )
return - V_11 ;
V_146 = V_37 -> V_147 ;
V_146 -> V_74 = V_143 -> V_74 ;
V_146 -> V_8 = F_58 ( V_37 -> V_148 , V_144 ,
V_90 | V_91 ) ;
if ( ! V_146 -> V_8 ) {
F_47 ( V_37 -> V_147 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_59 ( struct V_141 * V_37 )
{
struct V_145 * V_143 = V_37 -> V_147 ;
if ( V_143 ) {
F_47 ( V_143 -> V_8 ) ;
F_47 ( V_143 ) ;
}
}
static void F_60 ( struct V_141 * V_13 )
{
if ( V_13 -> type == V_149 ) {
F_61 ( V_13 ) ;
} else {
F_59 ( V_13 ) ;
F_62 ( V_13 ) ;
}
}
static void F_63 ( struct V_7 * V_37 )
{
F_60 ( V_37 -> V_13 ) ;
F_47 ( V_37 ) ;
}
static void F_64 ( struct V_150 * V_151 )
{
struct V_7 * V_37 = F_65 ( V_151 , struct V_7 , V_151 ) ;
F_63 ( V_37 ) ;
}
static void F_66 ( struct V_7 * V_37 )
{
if ( F_67 ( & V_37 -> V_152 ) )
F_68 ( & V_37 -> V_151 , F_64 ) ;
}
void F_69 ( struct V_1 * V_2 , struct V_7 * V_37 )
{
T_1 V_153 = F_70 ( V_37 -> V_13 -> V_74 ) ;
F_71 ( V_153 , & V_2 -> V_154 ) ;
F_66 ( V_37 ) ;
}
bool F_72 ( struct V_1 * V_2 , struct V_7 * V_37 )
{
T_1 V_153 = F_70 ( V_37 -> V_13 -> V_74 ) ;
if ( V_153 <= V_155 &&
F_73 ( & V_2 -> V_154 ) + V_153 < V_155 ) {
F_74 ( & V_37 -> V_152 ) ;
F_75 ( V_153 , & V_2 -> V_154 ) ;
return true ;
}
return false ;
}
static struct V_141 * F_76 ( struct V_141 * V_37 )
{
struct V_36 * V_156 ;
struct V_141 * V_157 ;
int V_6 , V_76 , V_158 = V_37 -> V_74 ;
F_15 ( sizeof( struct V_36 ) !=
sizeof( struct V_18 ) ) ;
V_156 = F_58 ( V_37 -> V_148 , V_158 * sizeof( struct V_36 ) ,
V_90 | V_91 ) ;
if ( ! V_156 ) {
V_6 = - V_11 ;
goto V_159;
}
V_6 = F_33 ( V_156 , V_158 , NULL , & V_76 ) ;
if ( V_6 )
goto V_160;
V_157 = V_37 ;
V_37 = F_77 ( V_157 , F_70 ( V_76 ) , 0 ) ;
if ( ! V_37 ) {
V_37 = V_157 ;
V_6 = - V_11 ;
goto V_160;
}
V_37 -> V_74 = V_76 ;
V_6 = F_33 ( V_156 , V_158 , V_37 -> V_161 , & V_76 ) ;
if ( V_6 )
goto V_160;
V_37 = F_78 ( V_37 , & V_6 ) ;
F_47 ( V_156 ) ;
return V_37 ;
V_160:
F_47 ( V_156 ) ;
V_159:
F_60 ( V_37 ) ;
return F_79 ( V_6 ) ;
}
static struct V_141 * F_80 ( struct V_141 * V_37 ,
T_4 V_162 )
{
int V_6 ;
V_37 -> V_163 = NULL ;
V_37 -> V_164 = 0 ;
V_6 = F_53 ( V_37 -> V_148 , V_37 -> V_74 ) ;
if ( V_6 ) {
F_60 ( V_37 ) ;
return F_79 ( V_6 ) ;
}
if ( V_162 ) {
V_6 = V_162 ( V_37 -> V_148 , V_37 -> V_74 ) ;
if ( V_6 ) {
F_60 ( V_37 ) ;
return F_79 ( V_6 ) ;
}
}
F_81 ( V_37 ) ;
if ( ! V_37 -> V_164 )
V_37 = F_76 ( V_37 ) ;
return V_37 ;
}
int F_82 ( struct V_141 * * V_165 , struct V_145 * V_143 )
{
unsigned int V_144 = F_56 ( V_143 ) ;
struct V_141 * V_37 ;
if ( ! F_52 ( V_143 -> V_8 , V_143 -> V_74 ) )
return - V_89 ;
V_37 = F_83 ( F_70 ( V_143 -> V_74 ) , 0 ) ;
if ( ! V_37 )
return - V_11 ;
memcpy ( V_37 -> V_148 , V_143 -> V_8 , V_144 ) ;
V_37 -> V_74 = V_143 -> V_74 ;
V_37 -> V_147 = NULL ;
V_37 = F_80 ( V_37 , NULL ) ;
if ( F_84 ( V_37 ) )
return F_85 ( V_37 ) ;
* V_165 = V_37 ;
return 0 ;
}
int F_86 ( struct V_141 * * V_165 , struct V_142 * V_143 ,
T_4 V_162 , bool V_166 )
{
unsigned int V_144 = F_56 ( V_143 ) ;
struct V_141 * V_37 ;
int V_6 ;
if ( ! F_52 ( V_143 -> V_8 , V_143 -> V_74 ) )
return - V_89 ;
V_37 = F_83 ( F_70 ( V_143 -> V_74 ) , 0 ) ;
if ( ! V_37 )
return - V_11 ;
if ( F_87 ( V_37 -> V_148 , V_143 -> V_8 , V_144 ) ) {
F_88 ( V_37 ) ;
return - V_167 ;
}
V_37 -> V_74 = V_143 -> V_74 ;
V_37 -> V_147 = NULL ;
if ( V_166 ) {
V_6 = F_55 ( V_37 , V_143 ) ;
if ( V_6 ) {
F_88 ( V_37 ) ;
return - V_11 ;
}
}
V_37 = F_80 ( V_37 , V_162 ) ;
if ( F_84 ( V_37 ) )
return F_85 ( V_37 ) ;
* V_165 = V_37 ;
return 0 ;
}
void F_89 ( struct V_141 * V_37 )
{
F_60 ( V_37 ) ;
}
static int F_90 ( struct V_141 * V_13 , struct V_1 * V_2 )
{
struct V_7 * V_37 , * V_157 ;
V_37 = F_57 ( sizeof( * V_37 ) , V_90 ) ;
if ( ! V_37 )
return - V_11 ;
V_37 -> V_13 = V_13 ;
F_91 ( & V_37 -> V_152 , 0 ) ;
if ( ! F_72 ( V_2 , V_37 ) ) {
F_47 ( V_37 ) ;
return - V_11 ;
}
V_157 = F_92 ( V_2 -> V_7 ,
F_93 ( V_2 ) ) ;
F_94 ( V_2 -> V_7 , V_37 ) ;
if ( V_157 )
F_69 ( V_2 , V_157 ) ;
return 0 ;
}
static int F_95 ( struct V_141 * V_13 , struct V_1 * V_2 )
{
struct V_141 * V_156 ;
int V_6 ;
if ( F_70 ( V_13 -> V_74 ) > V_155 )
return - V_11 ;
if ( F_96 ( V_2 ) && V_2 -> V_168 ) {
V_6 = F_97 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_98 ( V_2 -> V_169 ) ) {
return - V_89 ;
}
V_156 = F_99 ( V_2 , V_13 ) ;
if ( V_156 )
F_89 ( V_156 ) ;
return 0 ;
}
static
struct V_141 * F_100 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
unsigned int V_144 = F_56 ( V_143 ) ;
struct V_141 * V_13 ;
int V_6 ;
if ( F_3 ( V_2 , V_170 ) )
return F_79 ( - V_14 ) ;
if ( ! F_52 ( V_143 -> V_8 , V_143 -> V_74 ) )
return F_79 ( - V_89 ) ;
V_13 = F_83 ( F_70 ( V_143 -> V_74 ) , 0 ) ;
if ( ! V_13 )
return F_79 ( - V_11 ) ;
if ( F_87 ( V_13 -> V_148 , V_143 -> V_8 , V_144 ) ) {
F_88 ( V_13 ) ;
return F_79 ( - V_167 ) ;
}
V_13 -> V_74 = V_143 -> V_74 ;
V_6 = F_55 ( V_13 , V_143 ) ;
if ( V_6 ) {
F_88 ( V_13 ) ;
return F_79 ( - V_11 ) ;
}
return F_80 ( V_13 , NULL ) ;
}
int F_101 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
struct V_141 * V_13 = F_100 ( V_143 , V_2 ) ;
int V_6 ;
if ( F_84 ( V_13 ) )
return F_85 ( V_13 ) ;
V_6 = F_90 ( V_13 , V_2 ) ;
if ( V_6 < 0 ) {
F_60 ( V_13 ) ;
return V_6 ;
}
return 0 ;
}
int F_102 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
struct V_141 * V_13 = F_100 ( V_143 , V_2 ) ;
int V_6 ;
if ( F_84 ( V_13 ) )
return F_85 ( V_13 ) ;
V_6 = F_95 ( V_13 , V_2 ) ;
if ( V_6 < 0 ) {
F_60 ( V_13 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_141 * F_103 ( T_1 V_171 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_170 ) )
return F_79 ( - V_14 ) ;
return F_104 ( V_171 , V_149 ) ;
}
int F_105 ( T_1 V_171 , struct V_1 * V_2 )
{
struct V_141 * V_13 = F_103 ( V_171 , V_2 ) ;
int V_6 ;
if ( F_84 ( V_13 ) )
return F_85 ( V_13 ) ;
V_6 = F_90 ( V_13 , V_2 ) ;
if ( V_6 < 0 ) {
F_61 ( V_13 ) ;
return V_6 ;
}
return 0 ;
}
int F_106 ( T_1 V_171 , struct V_1 * V_2 )
{
struct V_141 * V_13 = F_103 ( V_171 , V_2 ) ;
int V_6 ;
if ( F_84 ( V_13 ) )
return F_85 ( V_13 ) ;
V_6 = F_95 ( V_13 , V_2 ) ;
if ( V_6 < 0 ) {
F_61 ( V_13 ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_107 ( struct V_3 * V_4 ,
unsigned int V_172 )
{
return F_108 ( V_4 , V_172 ) ;
}
static inline int F_109 ( struct V_3 * V_4 ,
unsigned int V_172 )
{
int V_6 = F_107 ( V_4 , V_172 ) ;
F_110 ( V_4 ) ;
return V_6 ;
}
static int F_111 ( struct V_3 * V_4 )
{
return F_109 ( V_4 , F_112 ( V_4 ) ) ;
}
static inline void F_113 ( struct V_3 * V_4 )
{
if ( F_114 ( V_4 ) )
F_115 ( V_4 , F_116 ( V_4 ) , V_4 -> V_173 ) ;
}
static inline void F_117 ( struct V_3 * V_4 )
{
if ( F_114 ( V_4 ) )
F_118 ( V_4 , F_116 ( V_4 ) , V_4 -> V_173 ) ;
}
static inline int F_119 ( struct V_49 * V_51 , struct V_3 * V_4 )
{
return F_120 ( V_51 , V_4 ) ;
}
static inline int F_121 ( struct V_49 * V_51 ,
struct V_3 * V_4 )
{
int V_135 = F_122 ( V_51 , V_4 ) ;
if ( F_123 ( ! V_135 ) ) {
V_4 -> V_51 = V_51 ;
V_135 = F_124 ( V_4 ) ;
}
return V_135 ;
}
static inline int F_125 ( struct V_49 * V_51 , struct V_3 * V_4 )
{
int V_135 ;
if ( F_126 ( F_127 ( V_174 ) > V_175 ) ) {
F_128 ( L_1 ) ;
F_129 ( V_4 ) ;
return - V_176 ;
}
V_4 -> V_51 = V_51 ;
F_130 ( V_174 ) ;
V_135 = F_131 ( V_4 ) ;
F_132 ( V_174 ) ;
return V_135 ;
}
static int F_133 ( struct V_3 * V_4 , struct V_49 * V_51 ,
T_1 V_177 )
{
unsigned int V_178 = V_4 -> V_179 - V_4 -> V_180 ;
F_134 ( V_4 , V_178 ) ;
if ( ! F_114 ( V_4 ) )
F_118 ( V_4 , F_116 ( V_4 ) , V_178 ) ;
F_135 ( V_4 ) ;
F_136 ( V_4 ) ;
return V_177 & V_181 ?
F_121 ( V_51 , V_4 ) : F_125 ( V_51 , V_4 ) ;
}
static int F_137 ( struct V_3 * V_4 , struct V_49 * V_51 ,
T_1 V_177 )
{
if ( F_126 ( V_4 -> V_180 >= V_4 -> V_179 ) ) {
F_129 ( V_4 ) ;
return - V_182 ;
}
F_113 ( V_4 ) ;
return V_177 & V_181 ?
F_119 ( V_51 , V_4 ) : F_125 ( V_51 , V_4 ) ;
}
static int F_138 ( struct V_3 * V_4 , struct V_49 * V_51 ,
T_1 V_177 )
{
if ( F_139 ( V_51 ) )
return F_137 ( V_4 , V_51 , V_177 ) ;
else
return F_133 ( V_4 , V_51 , V_177 ) ;
}
int F_140 ( struct V_3 * V_4 )
{
struct V_183 * V_184 = F_141 ( & V_183 ) ;
struct V_49 * V_51 ;
V_51 = F_142 ( F_143 ( V_4 -> V_51 ) , V_184 -> V_50 ) ;
V_184 -> V_50 = 0 ;
if ( F_126 ( ! V_51 ) ) {
F_129 ( V_4 ) ;
return - V_89 ;
}
return F_138 ( V_4 , V_51 , V_184 -> V_177 ) ;
}
static int F_144 ( struct V_3 * V_4 , T_1 V_185 , T_1 V_74 )
{
F_145 ( V_4 , V_74 ) ;
memmove ( V_4 -> V_186 , V_4 -> V_186 + V_74 , V_185 ) ;
memset ( V_4 -> V_186 + V_185 , 0 , V_74 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_4 , T_1 V_185 , T_1 V_74 )
{
if ( F_126 ( ! F_147 ( V_4 , V_185 + V_74 ) ) )
return - V_11 ;
F_118 ( V_4 , V_4 -> V_186 + V_185 , V_74 ) ;
memmove ( V_4 -> V_186 + V_74 , V_4 -> V_186 , V_185 ) ;
F_134 ( V_4 , V_74 ) ;
return 0 ;
}
static int F_148 ( struct V_3 * V_4 , T_1 V_185 , T_1 V_74 )
{
bool V_187 = V_4 -> V_188 == V_4 -> V_179 ;
int V_135 ;
V_135 = F_144 ( V_4 , V_185 , V_74 ) ;
if ( F_123 ( ! V_135 ) ) {
V_4 -> V_180 -= V_74 ;
V_4 -> V_179 -= V_74 ;
if ( V_187 )
V_4 -> V_188 = V_4 -> V_179 ;
}
return V_135 ;
}
static int F_149 ( struct V_3 * V_4 , T_1 V_185 , T_1 V_74 )
{
bool V_187 = V_4 -> V_188 == V_4 -> V_179 ;
int V_135 ;
V_135 = F_146 ( V_4 , V_185 , V_74 ) ;
if ( F_123 ( ! V_135 ) ) {
V_4 -> V_180 += V_74 ;
V_4 -> V_179 += V_74 ;
if ( V_187 )
V_4 -> V_188 = V_4 -> V_179 ;
}
return V_135 ;
}
static int F_150 ( struct V_3 * V_4 )
{
const T_1 V_189 = sizeof( struct V_190 ) - sizeof( struct V_191 ) ;
T_1 V_185 = V_4 -> V_179 - V_4 -> V_180 ;
int V_135 ;
V_135 = F_151 ( V_4 , V_189 ) ;
if ( F_126 ( V_135 < 0 ) )
return V_135 ;
V_135 = F_148 ( V_4 , V_185 , V_189 ) ;
if ( F_126 ( V_135 < 0 ) )
return V_135 ;
if ( F_152 ( V_4 ) ) {
if ( F_153 ( V_4 ) -> V_192 & V_193 ) {
F_153 ( V_4 ) -> V_192 &= ~ V_193 ;
F_153 ( V_4 ) -> V_192 |= V_194 ;
}
F_153 ( V_4 ) -> V_195 -= V_189 ;
F_153 ( V_4 ) -> V_192 |= V_196 ;
F_153 ( V_4 ) -> V_197 = 0 ;
}
V_4 -> V_43 = F_154 ( V_198 ) ;
F_155 ( V_4 ) ;
return 0 ;
}
static int F_156 ( struct V_3 * V_4 )
{
const T_1 V_189 = sizeof( struct V_190 ) - sizeof( struct V_191 ) ;
T_1 V_185 = V_4 -> V_179 - V_4 -> V_180 ;
int V_135 ;
V_135 = F_157 ( V_4 , V_199 ) ;
if ( F_126 ( V_135 < 0 ) )
return V_135 ;
V_135 = F_149 ( V_4 , V_185 , V_189 ) ;
if ( F_126 ( V_135 < 0 ) )
return V_135 ;
if ( F_152 ( V_4 ) ) {
if ( F_153 ( V_4 ) -> V_192 & V_194 ) {
F_153 ( V_4 ) -> V_192 &= ~ V_194 ;
F_153 ( V_4 ) -> V_192 |= V_193 ;
}
F_153 ( V_4 ) -> V_195 += V_189 ;
F_153 ( V_4 ) -> V_192 |= V_196 ;
F_153 ( V_4 ) -> V_197 = 0 ;
}
V_4 -> V_43 = F_154 ( V_200 ) ;
F_155 ( V_4 ) ;
return 0 ;
}
static int F_158 ( struct V_3 * V_4 , T_5 V_201 )
{
T_5 V_202 = V_4 -> V_43 ;
if ( V_202 == F_154 ( V_200 ) &&
V_201 == F_154 ( V_198 ) )
return F_150 ( V_4 ) ;
if ( V_202 == F_154 ( V_198 ) &&
V_201 == F_154 ( V_200 ) )
return F_156 ( V_4 ) ;
return - V_203 ;
}
static T_1 F_159 ( const struct V_3 * V_4 )
{
T_1 V_204 = F_160 ( V_4 ) ;
if ( F_161 ( V_4 ) )
V_204 = F_162 ( V_4 ) ;
if ( V_4 -> V_205 == V_206 )
V_204 = F_163 ( V_4 ) +
V_4 -> V_207 + sizeof( V_208 ) ;
return V_204 ;
}
static T_1 F_164 ( const struct V_3 * V_4 )
{
return V_4 -> V_51 -> V_209 + V_4 -> V_51 -> V_210 ;
}
static int F_165 ( struct V_3 * V_4 , unsigned int V_76 )
{
unsigned int V_158 = V_4 -> V_74 ;
int V_135 ;
V_135 = F_166 ( V_4 , V_76 ) ;
if ( ! V_135 )
memset ( V_4 -> V_186 + V_158 , 0 , V_76 - V_158 ) ;
return V_135 ;
}
static int F_167 ( struct V_3 * V_4 , unsigned int V_76 )
{
return F_168 ( V_4 , V_76 ) ;
}
bool F_169 ( void * V_211 )
{
if ( V_211 == V_212 ||
V_211 == V_213 ||
V_211 == V_214 ||
V_211 == V_215 ||
V_211 == V_216 ||
V_211 == V_217 ||
V_211 == V_218 ||
V_211 == V_219 ||
V_211 == V_220 ||
V_211 == V_221 )
return true ;
return false ;
}
static unsigned long F_170 ( void * V_222 , const void * V_4 ,
unsigned long V_185 , unsigned long V_74 )
{
void * V_223 = F_171 ( V_4 , V_185 , V_74 , V_222 ) ;
if ( F_126 ( ! V_223 ) )
return V_74 ;
if ( V_223 != V_222 )
memcpy ( V_222 , V_223 , V_74 ) ;
return 0 ;
}
static unsigned short F_172 ( T_6 V_177 )
{
return V_177 & V_224 ? V_225 : V_226 ;
}
static const struct V_227 *
F_173 ( enum V_228 V_229 )
{
if ( ! V_230 ) {
V_230 = F_174 ( V_231 ,
V_90 ) ;
if ( ! V_230 )
return NULL ;
}
switch ( V_229 ) {
case V_232 :
return & V_233 ;
case V_234 :
return & V_235 ;
default:
return NULL ;
}
}
static unsigned long F_175 ( void * V_222 , const void * V_236 ,
unsigned long V_185 , unsigned long V_74 )
{
memcpy ( V_222 , V_236 + V_185 , V_74 ) ;
return 0 ;
}
static const struct V_227 *
F_176 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_238 :
return & V_239 ;
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
if ( F_177 ( V_255 ) )
return F_178 () ;
default:
return NULL ;
}
}
static const struct V_227 *
F_179 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_256 :
return & V_257 ;
default:
return F_176 ( V_237 ) ;
}
}
static const struct V_227 *
F_180 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_258 :
return & V_259 ;
case V_256 :
return & V_257 ;
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
case V_232 :
return F_173 ( V_237 ) ;
case V_286 :
return & V_287 ;
case V_234 :
return F_173 ( V_237 ) ;
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
case V_246 :
return & V_298 ;
case V_299 :
return & V_300 ;
default:
return F_176 ( V_237 ) ;
}
}
static const struct V_227 *
F_181 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_296 :
return & V_301 ;
case V_246 :
return & V_298 ;
case V_302 :
return & V_303 ;
default:
return F_176 ( V_237 ) ;
}
}
static const struct V_227 *
F_182 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_256 :
return & V_257 ;
default:
return F_176 ( V_237 ) ;
}
}
static const struct V_227 *
F_183 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_256 :
return & V_257 ;
case V_260 :
return & V_261 ;
case V_262 :
return & V_263 ;
case V_272 :
return & V_273 ;
case V_290 :
return & V_291 ;
case V_292 :
return & V_293 ;
case V_296 :
return & V_297 ;
case V_246 :
return & V_298 ;
case V_299 :
return & V_300 ;
default:
return F_176 ( V_237 ) ;
}
}
static const struct V_227 *
F_184 ( enum V_228 V_237 )
{
switch ( V_237 ) {
case V_284 :
return & V_285 ;
case V_232 :
return F_173 ( V_237 ) ;
case V_286 :
return & V_287 ;
case V_234 :
return F_173 ( V_237 ) ;
case V_288 :
return & V_289 ;
case V_270 :
return & V_271 ;
case V_282 :
return & V_283 ;
case V_304 :
return & V_305 ;
case V_258 :
return & V_259 ;
case V_264 :
return & V_265 ;
case V_266 :
return & V_267 ;
case V_268 :
return & V_269 ;
case V_294 :
return & V_295 ;
default:
return F_183 ( V_237 ) ;
}
}
static bool F_185 ( int V_185 , int V_306 )
{
if ( V_185 < 0 || V_185 >= sizeof( struct V_307 ) )
return false ;
if ( V_185 % V_306 != 0 )
return false ;
switch ( V_185 ) {
case F_18 ( struct V_307 , V_308 [ 0 ] ) ...
F_18 ( struct V_307 , V_308 [ 4 ] ) + sizeof( V_309 ) - 1 :
if ( V_185 + V_306 >
F_18 ( struct V_307 , V_308 [ 4 ] ) + sizeof( V_309 ) )
return false ;
break;
default:
if ( V_306 != sizeof( V_309 ) )
return false ;
}
return true ;
}
static bool F_186 ( int V_185 , int V_306 ,
enum V_310 type ,
enum V_311 * V_312 )
{
switch ( V_185 ) {
case F_18 ( struct V_307 , V_313 ) :
case F_18 ( struct V_307 , V_186 ) :
case F_18 ( struct V_307 , V_314 ) :
return false ;
}
if ( type == V_315 ) {
switch ( V_185 ) {
case F_18 ( struct V_307 , V_308 [ 0 ] ) ...
F_18 ( struct V_307 , V_308 [ 4 ] ) + sizeof( V_309 ) - 1 :
break;
default:
return false ;
}
}
return F_185 ( V_185 , V_306 ) ;
}
static bool F_187 ( int V_185 , int V_306 ,
enum V_310 type ,
enum V_311 * V_312 )
{
switch ( V_185 ) {
case F_18 ( struct V_307 , V_313 ) :
return false ;
}
if ( type == V_315 ) {
switch ( V_185 ) {
case F_18 ( struct V_307 , V_22 ) :
case F_18 ( struct V_307 , V_316 ) :
case F_18 ( struct V_307 , V_308 [ 0 ] ) ...
F_18 ( struct V_307 , V_308 [ 4 ] ) + sizeof( V_309 ) - 1 :
break;
default:
return false ;
}
}
switch ( V_185 ) {
case F_18 ( struct V_307 , V_186 ) :
* V_312 = V_317 ;
break;
case F_18 ( struct V_307 , V_314 ) :
* V_312 = V_318 ;
break;
}
return F_185 ( V_185 , V_306 ) ;
}
static bool F_188 ( int V_185 , int V_306 ,
enum V_310 type ,
enum V_311 * V_312 )
{
if ( type == V_315 ) {
switch ( V_185 ) {
case F_18 ( struct V_319 , V_320 ) :
break;
default:
return false ;
}
}
if ( V_185 < 0 || V_185 + V_306 > sizeof( struct V_319 ) )
return false ;
if ( V_185 % V_306 != 0 )
return false ;
if ( V_306 != sizeof( V_309 ) )
return false ;
return true ;
}
static int F_189 ( struct V_18 * V_19 , bool V_321 ,
const struct V_141 * V_13 )
{
struct V_18 * V_20 = V_19 ;
if ( ! V_321 )
return 0 ;
* V_20 ++ = F_17 ( V_25 , V_322 , V_323 , F_190 () ) ;
* V_20 ++ = F_20 ( V_26 , V_322 , V_324 ) ;
* V_20 ++ = F_25 ( V_111 , V_322 , 0 , 7 ) ;
* V_20 ++ = F_27 ( V_322 , V_323 ) ;
* V_20 ++ = F_35 ( V_73 , V_325 , V_325 ) ;
* V_20 ++ = F_38 ( V_109 | V_326 , 0 , 0 , 0 ,
V_260 ) ;
* V_20 ++ = F_25 ( V_111 , V_122 , 0 , 2 ) ;
* V_20 ++ = F_20 ( V_327 , V_122 , V_328 ) ;
* V_20 ++ = F_26 () ;
* V_20 ++ = F_27 ( V_323 , V_322 ) ;
* V_20 ++ = V_13 -> V_161 [ 0 ] ;
return V_20 - V_19 ;
}
static bool F_191 ( int V_185 , int V_306 ,
enum V_310 type ,
enum V_311 * V_312 )
{
if ( type == V_315 ) {
switch ( V_185 ) {
case F_18 ( struct V_307 , V_22 ) :
case F_18 ( struct V_307 , V_329 ) :
case F_18 ( struct V_307 , V_316 ) :
case F_18 ( struct V_307 , V_308 [ 0 ] ) ...
F_18 ( struct V_307 , V_308 [ 4 ] ) + sizeof( V_309 ) - 1 :
case F_18 ( struct V_307 , V_313 ) :
break;
default:
return false ;
}
}
switch ( V_185 ) {
case F_18 ( struct V_307 , V_186 ) :
* V_312 = V_317 ;
break;
case F_18 ( struct V_307 , V_314 ) :
* V_312 = V_318 ;
break;
}
return F_185 ( V_185 , V_306 ) ;
}
static bool F_192 ( int V_185 , int V_306 )
{
if ( V_185 < 0 || V_185 >= sizeof( struct V_330 ) )
return false ;
if ( V_185 % V_306 != 0 )
return false ;
if ( V_306 != sizeof( V_309 ) )
return false ;
return true ;
}
static bool F_193 ( int V_185 , int V_306 ,
enum V_310 type ,
enum V_311 * V_312 )
{
if ( type == V_315 )
return false ;
switch ( V_185 ) {
case F_18 ( struct V_330 , V_186 ) :
* V_312 = V_317 ;
break;
case F_18 ( struct V_330 , V_314 ) :
* V_312 = V_318 ;
break;
}
return F_192 ( V_185 , V_306 ) ;
}
void F_194 ( T_1 V_331 )
{
F_195 ( 1 , L_2 , V_331 ) ;
}
static T_1 F_196 ( enum V_310 type ,
const struct V_18 * V_332 ,
struct V_18 * V_19 ,
struct V_141 * V_13 )
{
struct V_18 * V_20 = V_19 ;
int V_185 ;
switch ( V_332 -> V_185 ) {
case F_18 ( struct V_307 , V_74 ) :
F_15 ( F_16 ( struct V_3 , V_74 ) != 4 ) ;
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_74 ) ) ;
break;
case F_18 ( struct V_307 , V_43 ) :
F_15 ( F_16 ( struct V_3 , V_43 ) != 2 ) ;
* V_20 ++ = F_17 ( V_31 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_43 ) ) ;
break;
case F_18 ( struct V_307 , V_57 ) :
F_15 ( F_16 ( struct V_3 , V_57 ) != 2 ) ;
* V_20 ++ = F_17 ( V_31 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_57 ) ) ;
break;
case F_18 ( struct V_307 , V_316 ) :
F_15 ( F_16 ( struct V_3 , V_316 ) != 4 ) ;
if ( type == V_315 )
* V_20 ++ = F_46 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_316 ) ) ;
else
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_316 ) ) ;
break;
case F_18 ( struct V_307 , V_333 ) :
F_15 ( F_16 ( struct V_3 , V_334 ) != 4 ) ;
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_334 ) ) ;
break;
case F_18 ( struct V_307 , V_50 ) :
F_15 ( F_16 ( struct V_49 , V_50 ) != 4 ) ;
* V_20 ++ = F_17 ( F_24 ( struct V_3 , V_51 ) ,
V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_51 ) ) ;
* V_20 ++ = F_25 ( V_111 , V_332 -> V_16 , 0 , 1 ) ;
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_16 ,
F_18 ( struct V_49 , V_50 ) ) ;
break;
case F_18 ( struct V_307 , V_55 ) :
F_15 ( F_16 ( struct V_3 , V_55 ) != 4 ) ;
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_55 ) ) ;
break;
case F_18 ( struct V_307 , V_22 ) :
F_15 ( F_16 ( struct V_3 , V_22 ) != 4 ) ;
if ( type == V_315 )
* V_20 ++ = F_46 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_22 ) ) ;
else
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_22 ) ) ;
break;
case F_18 ( struct V_307 , V_335 ) :
return F_14 ( V_24 , V_332 -> V_16 ,
V_332 -> V_17 , V_20 ) ;
case F_18 ( struct V_307 , V_30 ) :
return F_14 ( V_29 , V_332 -> V_16 ,
V_332 -> V_17 , V_20 ) ;
case F_18 ( struct V_307 , V_336 ) :
return F_14 ( V_33 ,
V_332 -> V_16 , V_332 -> V_17 , V_20 ) ;
case F_18 ( struct V_307 , V_34 ) :
return F_14 ( V_32 ,
V_332 -> V_16 , V_332 -> V_17 , V_20 ) ;
case F_18 ( struct V_307 , V_308 [ 0 ] ) ...
F_18 ( struct V_307 , V_308 [ 4 ] ) + sizeof( V_309 ) - 1 :
F_15 ( F_16 ( struct V_337 , V_186 ) < 20 ) ;
F_15 ( ( F_18 ( struct V_3 , V_308 ) +
F_18 ( struct V_337 , V_186 ) ) %
sizeof( V_338 ) ) ;
V_13 -> V_339 = 1 ;
V_185 = V_332 -> V_185 ;
V_185 -= F_18 ( struct V_307 , V_308 [ 0 ] ) ;
V_185 += F_18 ( struct V_3 , V_308 ) ;
V_185 += F_18 ( struct V_337 , V_186 ) ;
if ( type == V_315 )
* V_20 ++ = F_46 ( F_197 ( V_332 -> V_94 ) , V_332 -> V_16 ,
V_332 -> V_17 , V_185 ) ;
else
* V_20 ++ = F_17 ( F_197 ( V_332 -> V_94 ) , V_332 -> V_16 ,
V_332 -> V_17 , V_185 ) ;
break;
case F_18 ( struct V_307 , V_313 ) :
F_15 ( F_16 ( struct V_337 , V_313 ) != 2 ) ;
V_185 = V_332 -> V_185 ;
V_185 -= F_18 ( struct V_307 , V_313 ) ;
V_185 += F_18 ( struct V_3 , V_308 ) ;
V_185 += F_18 ( struct V_337 , V_313 ) ;
if ( type == V_315 )
* V_20 ++ = F_46 ( V_31 , V_332 -> V_16 ,
V_332 -> V_17 , V_185 ) ;
else
* V_20 ++ = F_17 ( V_31 , V_332 -> V_16 ,
V_332 -> V_17 , V_185 ) ;
break;
case F_18 ( struct V_307 , V_186 ) :
* V_20 ++ = F_17 ( F_24 ( struct V_3 , V_186 ) ,
V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_186 ) ) ;
break;
case F_18 ( struct V_307 , V_314 ) :
V_185 = V_332 -> V_185 ;
V_185 -= F_18 ( struct V_307 , V_314 ) ;
V_185 += F_18 ( struct V_3 , V_308 ) ;
V_185 += F_18 ( struct V_340 , V_314 ) ;
* V_20 ++ = F_17 ( F_198 ( void * ) , V_332 -> V_16 ,
V_332 -> V_17 , V_185 ) ;
break;
case F_18 ( struct V_307 , V_329 ) :
#ifdef F_199
F_15 ( F_16 ( struct V_3 , V_329 ) != 2 ) ;
if ( type == V_315 )
* V_20 ++ = F_46 ( V_31 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_329 ) ) ;
else
* V_20 ++ = F_17 ( V_31 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_329 ) ) ;
#else
if ( type == V_315 )
* V_20 ++ = F_27 ( V_332 -> V_16 , V_332 -> V_16 ) ;
else
* V_20 ++ = F_200 ( V_332 -> V_16 , 0 ) ;
#endif
break;
}
return V_20 - V_19 ;
}
static T_1 F_201 ( enum V_310 type ,
const struct V_18 * V_332 ,
struct V_18 * V_19 ,
struct V_141 * V_13 )
{
struct V_18 * V_20 = V_19 ;
switch ( V_332 -> V_185 ) {
case F_18 ( struct V_319 , V_320 ) :
F_15 ( F_16 ( struct V_1 , V_341 ) != 4 ) ;
if ( type == V_315 )
* V_20 ++ = F_46 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_1 , V_341 ) ) ;
else
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_1 , V_341 ) ) ;
break;
case F_18 ( struct V_319 , V_342 ) :
F_15 ( F_16 ( struct V_1 , V_343 ) != 2 ) ;
* V_20 ++ = F_17 ( V_31 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_1 , V_343 ) ) ;
break;
case F_18 ( struct V_319 , type ) :
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_1 , V_344 ) ) ;
* V_20 ++ = F_20 ( V_26 , V_332 -> V_16 , V_345 ) ;
* V_20 ++ = F_20 ( V_28 , V_332 -> V_16 , V_346 ) ;
break;
case F_18 ( struct V_319 , V_43 ) :
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_1 , V_344 ) ) ;
* V_20 ++ = F_20 ( V_26 , V_332 -> V_16 , V_347 ) ;
* V_20 ++ = F_20 ( V_28 , V_332 -> V_16 , V_348 ) ;
break;
}
return V_20 - V_19 ;
}
static T_1 F_202 ( enum V_310 type ,
const struct V_18 * V_332 ,
struct V_18 * V_19 ,
struct V_141 * V_13 )
{
struct V_18 * V_20 = V_19 ;
switch ( V_332 -> V_185 ) {
case F_18 ( struct V_307 , V_50 ) :
F_15 ( F_16 ( struct V_49 , V_50 ) != 4 ) ;
* V_20 ++ = F_17 ( F_24 ( struct V_3 , V_51 ) ,
V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_3 , V_51 ) ) ;
* V_20 ++ = F_17 ( V_23 , V_332 -> V_16 , V_332 -> V_16 ,
F_18 ( struct V_49 , V_50 ) ) ;
break;
default:
return F_196 ( type , V_332 , V_19 , V_13 ) ;
}
return V_20 - V_19 ;
}
static T_1 F_203 ( enum V_310 type ,
const struct V_18 * V_332 ,
struct V_18 * V_19 ,
struct V_141 * V_13 )
{
struct V_18 * V_20 = V_19 ;
switch ( V_332 -> V_185 ) {
case F_18 ( struct V_330 , V_186 ) :
* V_20 ++ = F_17 ( F_24 ( struct V_349 , V_186 ) ,
V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_349 , V_186 ) ) ;
break;
case F_18 ( struct V_330 , V_314 ) :
* V_20 ++ = F_17 ( F_24 ( struct V_349 , V_314 ) ,
V_332 -> V_16 , V_332 -> V_17 ,
F_18 ( struct V_349 , V_314 ) ) ;
break;
}
return V_20 - V_19 ;
}
static int T_7 F_204 ( void )
{
F_205 ( & V_350 ) ;
F_205 ( & V_351 ) ;
F_205 ( & V_352 ) ;
F_205 ( & V_353 ) ;
F_205 ( & V_354 ) ;
F_205 ( & V_355 ) ;
F_205 ( & V_356 ) ;
F_205 ( & V_357 ) ;
F_205 ( & V_358 ) ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 )
{
int V_135 = - V_359 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_170 ) )
return - V_14 ;
V_8 = F_92 ( V_2 -> V_7 ,
F_93 ( V_2 ) ) ;
if ( V_8 ) {
F_207 ( V_2 -> V_7 , NULL ) ;
F_69 ( V_2 , V_8 ) ;
V_135 = 0 ;
}
return V_135 ;
}
int F_208 ( struct V_1 * V_2 , struct V_36 T_8 * V_360 ,
unsigned int V_74 )
{
struct V_145 * V_143 ;
struct V_7 * V_8 ;
int V_135 = 0 ;
F_209 ( V_2 ) ;
V_8 = F_92 ( V_2 -> V_7 ,
F_93 ( V_2 ) ) ;
if ( ! V_8 )
goto V_361;
V_135 = - V_362 ;
V_143 = V_8 -> V_13 -> V_147 ;
if ( ! V_143 )
goto V_361;
V_135 = V_143 -> V_74 ;
if ( ! V_74 )
goto V_361;
V_135 = - V_89 ;
if ( V_74 < V_143 -> V_74 )
goto V_361;
V_135 = - V_167 ;
if ( F_210 ( V_360 , V_143 -> V_8 , F_56 ( V_143 ) ) )
goto V_361;
V_135 = V_143 -> V_74 ;
V_361:
F_211 ( V_2 ) ;
return V_135 ;
}
