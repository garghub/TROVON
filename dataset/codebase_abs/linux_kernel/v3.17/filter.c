int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct F_1 * V_6 ;
if ( F_2 ( V_4 ) && ! F_3 ( V_2 , V_7 ) )
return - V_8 ;
V_5 = F_4 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
F_5 () ;
V_6 = F_6 ( V_2 -> F_1 ) ;
if ( V_6 ) {
unsigned int V_9 = F_7 ( V_6 , V_4 ) ;
V_5 = V_9 ? F_8 ( V_4 , V_9 ) : - V_10 ;
}
F_9 () ;
return V_5 ;
}
static unsigned int F_10 ( void )
{
struct V_3 V_11 = { . V_12 = ~ 0 , } ;
T_1 * V_13 = ( T_1 * ) & V_11 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < sizeof( struct V_3 ) ; V_14 ++ ) {
if ( V_13 [ V_14 ] == V_15 )
return V_14 ;
}
F_11 ( L_1 , V_16 ) ;
return - 1 ;
}
static T_2 F_12 ( T_2 V_17 , T_2 V_18 , T_2 V_19 , T_2 V_20 , T_2 V_21 )
{
return F_13 ( (struct V_3 * ) ( unsigned long ) V_17 ) ;
}
static T_2 F_14 ( T_2 V_17 , T_2 V_18 , T_2 V_19 , T_2 V_20 , T_2 V_21 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_17 ;
struct V_22 * V_23 ;
if ( F_15 ( V_4 ) )
return 0 ;
if ( V_4 -> V_24 < sizeof( struct V_22 ) )
return 0 ;
if ( V_18 > V_4 -> V_24 - sizeof( struct V_22 ) )
return 0 ;
V_23 = F_16 ( (struct V_22 * ) & V_4 -> V_25 [ V_18 ] , V_4 -> V_24 - V_18 , V_19 ) ;
if ( V_23 )
return ( void * ) V_23 - ( void * ) V_4 -> V_25 ;
return 0 ;
}
static T_2 F_17 ( T_2 V_17 , T_2 V_18 , T_2 V_19 , T_2 V_20 , T_2 V_21 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_17 ;
struct V_22 * V_23 ;
if ( F_15 ( V_4 ) )
return 0 ;
if ( V_4 -> V_24 < sizeof( struct V_22 ) )
return 0 ;
if ( V_18 > V_4 -> V_24 - sizeof( struct V_22 ) )
return 0 ;
V_23 = (struct V_22 * ) & V_4 -> V_25 [ V_18 ] ;
if ( V_23 -> V_26 > V_4 -> V_24 - V_18 )
return 0 ;
V_23 = F_18 ( V_23 , V_19 ) ;
if ( V_23 )
return ( void * ) V_23 - ( void * ) V_4 -> V_25 ;
return 0 ;
}
static T_2 F_19 ( T_2 V_17 , T_2 V_18 , T_2 V_19 , T_2 V_20 , T_2 V_21 )
{
return F_20 () ;
}
static T_2 F_21 ( T_2 V_17 , T_2 V_18 , T_2 V_19 , T_2 V_20 , T_2 V_21 )
{
return F_22 () ;
}
static bool F_23 ( struct V_27 * V_28 ,
struct V_29 * * V_30 )
{
struct V_29 * V_31 = * V_30 ;
switch ( V_28 -> V_32 ) {
case V_33 + V_34 :
F_24 ( F_25 ( struct V_3 , V_35 ) != 2 ) ;
* V_31 ++ = F_26 ( V_36 , V_37 , V_38 ,
F_27 ( struct V_3 , V_35 ) ) ;
* V_31 = F_28 ( V_39 , V_37 , 16 ) ;
break;
case V_33 + V_40 :
* V_31 = F_26 ( V_41 , V_37 , V_38 ,
F_10 () ) ;
if ( V_31 -> V_14 < 0 )
return false ;
V_31 ++ ;
* V_31 = F_29 ( V_42 , V_37 , V_15 ) ;
#ifdef F_30
V_31 ++ ;
* V_31 = F_29 ( V_43 , V_37 , 5 ) ;
#endif
break;
case V_33 + V_44 :
case V_33 + V_45 :
F_24 ( F_25 ( struct V_46 , V_47 ) != 4 ) ;
F_24 ( F_25 ( struct V_46 , type ) != 2 ) ;
F_24 ( F_31 ( F_25 ( struct V_3 , V_48 ) ) < 0 ) ;
* V_31 ++ = F_26 ( F_31 ( F_25 ( struct V_3 , V_48 ) ) ,
V_49 , V_38 ,
F_27 ( struct V_3 , V_48 ) ) ;
* V_31 ++ = F_32 ( V_50 , V_49 , 0 , 1 ) ;
* V_31 ++ = F_33 () ;
if ( V_28 -> V_32 == V_33 + V_44 )
* V_31 = F_26 ( V_51 , V_37 , V_49 ,
F_27 ( struct V_46 , V_47 ) ) ;
else
* V_31 = F_26 ( V_36 , V_37 , V_49 ,
F_27 ( struct V_46 , type ) ) ;
break;
case V_33 + V_52 :
F_24 ( F_25 ( struct V_3 , V_53 ) != 4 ) ;
* V_31 = F_26 ( V_51 , V_37 , V_38 ,
F_27 ( struct V_3 , V_53 ) ) ;
break;
case V_33 + V_54 :
F_24 ( F_25 ( struct V_3 , V_55 ) != 4 ) ;
* V_31 = F_26 ( V_51 , V_37 , V_38 ,
F_27 ( struct V_3 , V_55 ) ) ;
break;
case V_33 + V_56 :
F_24 ( F_25 ( struct V_3 , V_57 ) != 2 ) ;
* V_31 = F_26 ( V_36 , V_37 , V_38 ,
F_27 ( struct V_3 , V_57 ) ) ;
break;
case V_33 + V_58 :
case V_33 + V_59 :
F_24 ( F_25 ( struct V_3 , V_60 ) != 2 ) ;
F_24 ( V_61 != 0x1000 ) ;
* V_31 ++ = F_26 ( V_36 , V_37 , V_38 ,
F_27 ( struct V_3 , V_60 ) ) ;
if ( V_28 -> V_32 == V_33 + V_58 ) {
* V_31 = F_29 ( V_42 , V_37 ,
~ V_61 ) ;
} else {
* V_31 ++ = F_29 ( V_43 , V_37 , 12 ) ;
* V_31 = F_29 ( V_42 , V_37 , 1 ) ;
}
break;
case V_33 + V_62 :
case V_33 + V_63 :
case V_33 + V_64 :
case V_33 + V_65 :
case V_33 + V_66 :
* V_31 ++ = F_34 ( V_67 , V_38 ) ;
* V_31 ++ = F_34 ( V_68 , V_37 ) ;
* V_31 ++ = F_34 ( V_69 , V_70 ) ;
switch ( V_28 -> V_32 ) {
case V_33 + V_62 :
* V_31 = F_35 ( F_12 ) ;
break;
case V_33 + V_63 :
* V_31 = F_35 ( F_14 ) ;
break;
case V_33 + V_64 :
* V_31 = F_35 ( F_17 ) ;
break;
case V_33 + V_65 :
* V_31 = F_35 ( F_19 ) ;
break;
case V_33 + V_66 :
* V_31 = F_35 ( F_21 ) ;
break;
}
break;
case V_33 + V_71 :
* V_31 = F_36 ( V_72 , V_37 , V_70 ) ;
break;
default:
F_37 ( F_38 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_30 = V_31 ;
return true ;
}
int F_39 ( struct V_27 * V_73 , int V_24 ,
struct V_29 * V_74 , int * V_75 )
{
int V_76 = 0 , V_77 = 0 , V_78 , V_79 ;
struct V_29 * V_80 ;
struct V_27 * V_28 ;
int * V_81 = NULL ;
T_1 V_82 ;
F_24 ( V_83 * sizeof( V_84 ) > V_85 ) ;
F_24 ( V_86 + 1 != V_87 ) ;
if ( V_24 <= 0 || V_24 > V_88 )
return - V_89 ;
if ( V_74 ) {
V_81 = F_40 ( V_24 , sizeof( * V_81 ) , V_90 ) ;
if ( ! V_81 )
return - V_8 ;
}
V_91:
V_80 = V_74 ;
V_28 = V_73 ;
if ( V_80 )
* V_80 = F_34 ( V_38 , V_67 ) ;
V_80 ++ ;
for ( V_79 = 0 ; V_79 < V_24 ; V_28 ++ , V_79 ++ ) {
struct V_29 V_92 [ 6 ] = { } ;
struct V_29 * V_31 = V_92 ;
if ( V_81 )
V_81 [ V_79 ] = V_80 - V_74 ;
switch ( V_28 -> V_93 ) {
case V_94 | V_95 | V_96 :
case V_94 | V_95 | V_97 :
case V_94 | V_98 | V_96 :
case V_94 | V_98 | V_97 :
case V_94 | V_42 | V_96 :
case V_94 | V_42 | V_97 :
case V_94 | V_99 | V_96 :
case V_94 | V_99 | V_97 :
case V_94 | V_100 | V_96 :
case V_94 | V_100 | V_97 :
case V_94 | V_43 | V_96 :
case V_94 | V_43 | V_97 :
case V_94 | V_72 | V_96 :
case V_94 | V_72 | V_97 :
case V_94 | V_101 | V_96 :
case V_94 | V_101 | V_97 :
case V_94 | V_102 | V_96 :
case V_94 | V_102 | V_97 :
case V_94 | V_103 | V_96 :
case V_94 | V_103 | V_97 :
case V_94 | V_104 :
case V_105 | V_106 | V_51 :
case V_105 | V_106 | V_36 :
case V_105 | V_106 | V_41 :
case V_105 | V_107 | V_51 :
case V_105 | V_107 | V_36 :
case V_105 | V_107 | V_41 :
if ( F_41 ( V_28 -> V_93 ) == V_105 &&
F_42 ( V_28 -> V_93 ) == V_106 &&
F_23 ( V_28 , & V_31 ) )
break;
* V_31 = F_43 ( V_28 -> V_93 , V_37 , V_70 , 0 , V_28 -> V_32 ) ;
break;
#define F_44 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_108 | V_109 :
V_78 = V_79 + V_28 -> V_32 + 1 ;
V_31 -> V_93 = V_28 -> V_93 ;
F_44 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
if ( F_45 ( V_28 -> V_93 ) == V_97 && ( int ) V_28 -> V_32 < 0 ) {
* V_31 ++ = F_46 ( V_49 , V_28 -> V_32 ) ;
V_31 -> V_114 = V_37 ;
V_31 -> V_115 = V_49 ;
V_82 = V_96 ;
} else {
V_31 -> V_114 = V_37 ;
V_31 -> V_115 = V_70 ;
V_31 -> V_116 = V_28 -> V_32 ;
V_82 = F_45 ( V_28 -> V_93 ) ;
}
if ( V_28 -> V_117 == 0 ) {
V_31 -> V_93 = V_108 | F_47 ( V_28 -> V_93 ) | V_82 ;
V_78 = V_79 + V_28 -> V_118 + 1 ;
F_44 ;
break;
}
if ( V_28 -> V_118 == 0 && F_47 ( V_28 -> V_93 ) == V_110 ) {
V_31 -> V_93 = V_108 | V_50 | V_82 ;
V_78 = V_79 + V_28 -> V_117 + 1 ;
F_44 ;
break;
}
V_78 = V_79 + V_28 -> V_118 + 1 ;
V_31 -> V_93 = V_108 | F_47 ( V_28 -> V_93 ) | V_82 ;
F_44 ;
V_31 ++ ;
V_31 -> V_93 = V_108 | V_109 ;
V_78 = V_79 + V_28 -> V_117 + 1 ;
F_44 ;
break;
case V_119 | V_120 | V_41 :
* V_31 ++ = F_34 ( V_49 , V_37 ) ;
* V_31 ++ = F_48 ( V_41 , V_28 -> V_32 ) ;
* V_31 ++ = F_29 ( V_42 , V_37 , 0xf ) ;
* V_31 ++ = F_29 ( V_100 , V_37 , 2 ) ;
* V_31 ++ = F_34 ( V_70 , V_37 ) ;
* V_31 = F_34 ( V_37 , V_49 ) ;
break;
case V_121 | V_122 :
case V_121 | V_97 :
* V_31 ++ = F_49 ( F_50 ( V_28 -> V_93 ) == V_97 ?
V_97 : V_96 , V_123 ,
V_37 , V_28 -> V_32 ) ;
* V_31 = F_33 () ;
break;
case V_124 :
case V_125 :
* V_31 = F_51 ( V_51 , V_86 , F_41 ( V_28 -> V_93 ) ==
V_124 ? V_37 : V_70 ,
- ( V_83 - V_28 -> V_32 ) * 4 ) ;
break;
case V_105 | V_126 :
case V_119 | V_126 :
* V_31 = F_26 ( V_51 , F_41 ( V_28 -> V_93 ) == V_105 ?
V_37 : V_70 , V_86 ,
- ( V_83 - V_28 -> V_32 ) * 4 ) ;
break;
case V_105 | V_127 :
case V_119 | V_127 :
* V_31 = F_46 ( F_41 ( V_28 -> V_93 ) == V_105 ?
V_37 : V_70 , V_28 -> V_32 ) ;
break;
case V_128 | V_129 :
* V_31 = F_34 ( V_70 , V_37 ) ;
break;
case V_128 | V_130 :
* V_31 = F_34 ( V_37 , V_70 ) ;
break;
case V_105 | V_51 | V_131 :
case V_119 | V_51 | V_131 :
* V_31 = F_26 ( V_51 , F_41 ( V_28 -> V_93 ) == V_105 ?
V_37 : V_70 , V_38 ,
F_27 ( struct V_3 , V_24 ) ) ;
break;
case V_119 | V_106 | V_51 :
* V_31 = F_26 ( V_51 , V_37 , V_38 , V_28 -> V_32 ) ;
break;
default:
goto V_5;
}
V_31 ++ ;
if ( V_74 )
memcpy ( V_80 , V_92 ,
sizeof( * V_31 ) * ( V_31 - V_92 ) ) ;
V_80 += V_31 - V_92 ;
}
if ( ! V_74 ) {
* V_75 = V_80 - V_74 ;
return 0 ;
}
V_77 ++ ;
if ( V_76 != V_80 - V_74 ) {
V_76 = V_80 - V_74 ;
if ( V_77 > 2 )
goto V_5;
goto V_91;
}
F_52 ( V_81 ) ;
F_37 ( * V_75 != V_76 ) ;
return 0 ;
V_5:
F_52 ( V_81 ) ;
return - V_89 ;
}
static int F_53 ( const struct V_27 * V_6 , int V_132 )
{
T_3 * V_133 , V_134 = 0 ;
int V_135 , V_136 = 0 ;
F_24 ( V_83 > 16 ) ;
V_133 = F_54 ( V_132 , sizeof( * V_133 ) , V_90 ) ;
if ( ! V_133 )
return - V_8 ;
memset ( V_133 , 0xff , V_132 * sizeof( * V_133 ) ) ;
for ( V_135 = 0 ; V_135 < V_132 ; V_135 ++ ) {
V_134 &= V_133 [ V_135 ] ;
switch ( V_6 [ V_135 ] . V_93 ) {
case V_124 :
case V_125 :
V_134 |= ( 1 << V_6 [ V_135 ] . V_32 ) ;
break;
case V_105 | V_126 :
case V_119 | V_126 :
if ( ! ( V_134 & ( 1 << V_6 [ V_135 ] . V_32 ) ) ) {
V_136 = - V_89 ;
goto error;
}
break;
case V_108 | V_109 :
V_133 [ V_135 + 1 + V_6 [ V_135 ] . V_32 ] &= V_134 ;
V_134 = ~ 0 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
V_133 [ V_135 + 1 + V_6 [ V_135 ] . V_118 ] &= V_134 ;
V_133 [ V_135 + 1 + V_6 [ V_135 ] . V_117 ] &= V_134 ;
V_134 = ~ 0 ;
break;
}
}
error:
F_52 ( V_133 ) ;
return V_136 ;
}
static bool F_55 ( T_3 V_137 )
{
static const bool V_138 [] = {
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
[ V_94 | V_42 | V_97 ] = true ,
[ V_94 | V_42 | V_96 ] = true ,
[ V_94 | V_99 | V_97 ] = true ,
[ V_94 | V_99 | V_96 ] = true ,
[ V_94 | V_72 | V_97 ] = true ,
[ V_94 | V_72 | V_96 ] = true ,
[ V_94 | V_100 | V_97 ] = true ,
[ V_94 | V_100 | V_96 ] = true ,
[ V_94 | V_43 | V_97 ] = true ,
[ V_94 | V_43 | V_96 ] = true ,
[ V_94 | V_104 ] = true ,
[ V_105 | V_51 | V_106 ] = true ,
[ V_105 | V_36 | V_106 ] = true ,
[ V_105 | V_41 | V_106 ] = true ,
[ V_105 | V_51 | V_131 ] = true ,
[ V_105 | V_51 | V_107 ] = true ,
[ V_105 | V_36 | V_107 ] = true ,
[ V_105 | V_41 | V_107 ] = true ,
[ V_105 | V_127 ] = true ,
[ V_105 | V_126 ] = true ,
[ V_119 | V_51 | V_131 ] = true ,
[ V_119 | V_41 | V_120 ] = true ,
[ V_119 | V_127 ] = true ,
[ V_119 | V_126 ] = true ,
[ V_124 ] = true ,
[ V_125 ] = true ,
[ V_128 | V_129 ] = true ,
[ V_128 | V_130 ] = true ,
[ V_121 | V_97 ] = true ,
[ V_121 | V_122 ] = true ,
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
if ( V_137 >= F_56 ( V_138 ) )
return false ;
return V_138 [ V_137 ] ;
}
int F_57 ( const struct V_27 * V_6 , unsigned int V_132 )
{
bool V_139 ;
int V_135 ;
if ( V_132 == 0 || V_132 > V_88 )
return - V_89 ;
for ( V_135 = 0 ; V_135 < V_132 ; V_135 ++ ) {
const struct V_27 * V_140 = & V_6 [ V_135 ] ;
if ( ! F_55 ( V_140 -> V_93 ) )
return - V_89 ;
switch ( V_140 -> V_93 ) {
case V_94 | V_102 | V_97 :
case V_94 | V_103 | V_97 :
if ( V_140 -> V_32 == 0 )
return - V_89 ;
break;
case V_105 | V_126 :
case V_119 | V_126 :
case V_124 :
case V_125 :
if ( V_140 -> V_32 >= V_83 )
return - V_89 ;
break;
case V_108 | V_109 :
if ( V_140 -> V_32 >= ( unsigned int ) ( V_132 - V_135 - 1 ) )
return - V_89 ;
break;
case V_108 | V_110 | V_97 :
case V_108 | V_110 | V_96 :
case V_108 | V_113 | V_97 :
case V_108 | V_113 | V_96 :
case V_108 | V_112 | V_97 :
case V_108 | V_112 | V_96 :
case V_108 | V_111 | V_97 :
case V_108 | V_111 | V_96 :
if ( V_135 + V_140 -> V_118 + 1 >= V_132 ||
V_135 + V_140 -> V_117 + 1 >= V_132 )
return - V_89 ;
break;
case V_105 | V_51 | V_106 :
case V_105 | V_36 | V_106 :
case V_105 | V_41 | V_106 :
V_139 = false ;
if ( F_58 ( V_140 ) & V_141 )
V_139 = true ;
if ( V_139 == false && V_140 -> V_32 >= V_33 )
return - V_89 ;
}
}
switch ( V_6 [ V_132 - 1 ] . V_93 ) {
case V_121 | V_97 :
case V_121 | V_122 :
return F_53 ( V_6 , V_132 ) ;
}
return - V_89 ;
}
static int F_59 ( struct V_142 * V_28 ,
const struct V_143 * V_144 )
{
unsigned int V_145 = F_60 ( V_144 ) ;
struct V_146 * V_147 ;
V_28 -> V_148 = F_61 ( sizeof( * V_147 ) , V_90 ) ;
if ( ! V_28 -> V_148 )
return - V_8 ;
V_147 = V_28 -> V_148 ;
V_147 -> V_24 = V_144 -> V_24 ;
V_147 -> V_6 = F_62 ( V_28 -> V_149 , V_145 , V_90 ) ;
if ( ! V_147 -> V_6 ) {
F_52 ( V_28 -> V_148 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_63 ( struct V_142 * V_28 )
{
struct V_146 * V_144 = V_28 -> V_148 ;
if ( V_144 ) {
F_52 ( V_144 -> V_6 ) ;
F_52 ( V_144 ) ;
}
}
static void F_64 ( struct V_142 * V_73 )
{
F_63 ( V_73 ) ;
F_65 ( V_73 ) ;
}
static void F_66 ( struct F_1 * V_28 )
{
F_64 ( V_28 -> V_73 ) ;
F_52 ( V_28 ) ;
}
static void F_67 ( struct V_150 * V_151 )
{
struct F_1 * V_28 = F_68 ( V_151 , struct F_1 , V_151 ) ;
F_66 ( V_28 ) ;
}
static void F_69 ( struct F_1 * V_28 )
{
if ( F_70 ( & V_28 -> V_152 ) )
F_71 ( & V_28 -> V_151 , F_67 ) ;
}
void F_72 ( struct V_1 * V_2 , struct F_1 * V_28 )
{
V_84 V_153 = F_73 ( V_28 -> V_73 -> V_24 ) ;
F_74 ( V_153 , & V_2 -> V_154 ) ;
F_69 ( V_28 ) ;
}
bool F_75 ( struct V_1 * V_2 , struct F_1 * V_28 )
{
V_84 V_153 = F_73 ( V_28 -> V_73 -> V_24 ) ;
if ( V_153 <= V_155 &&
F_76 ( & V_2 -> V_154 ) + V_153 < V_155 ) {
F_77 ( & V_28 -> V_152 ) ;
F_78 ( V_153 , & V_2 -> V_154 ) ;
return true ;
}
return false ;
}
static struct V_142 * F_79 ( struct V_142 * V_28 )
{
struct V_27 * V_156 ;
struct V_142 * V_157 ;
int V_5 , V_75 , V_158 = V_28 -> V_24 ;
F_24 ( sizeof( struct V_27 ) !=
sizeof( struct V_29 ) ) ;
V_156 = F_62 ( V_28 -> V_149 , V_158 * sizeof( struct V_27 ) ,
V_90 ) ;
if ( ! V_156 ) {
V_5 = - V_8 ;
goto V_159;
}
V_5 = F_39 ( V_156 , V_158 , NULL , & V_75 ) ;
if ( V_5 )
goto V_160;
V_157 = V_28 ;
V_28 = F_80 ( V_157 , F_73 ( V_75 ) , V_90 ) ;
if ( ! V_28 ) {
V_28 = V_157 ;
V_5 = - V_8 ;
goto V_160;
}
V_28 -> V_24 = V_75 ;
V_5 = F_39 ( V_156 , V_158 , V_28 -> V_161 , & V_75 ) ;
if ( V_5 )
goto V_160;
F_81 ( V_28 ) ;
F_52 ( V_156 ) ;
return V_28 ;
V_160:
F_52 ( V_156 ) ;
V_159:
F_64 ( V_28 ) ;
return F_82 ( V_5 ) ;
}
static struct V_142 * F_83 ( struct V_142 * V_28 )
{
int V_5 ;
V_28 -> V_162 = NULL ;
V_28 -> V_163 = 0 ;
V_5 = F_57 ( V_28 -> V_149 , V_28 -> V_24 ) ;
if ( V_5 ) {
F_64 ( V_28 ) ;
return F_82 ( V_5 ) ;
}
F_84 ( V_28 ) ;
if ( ! V_28 -> V_163 )
V_28 = F_79 ( V_28 ) ;
return V_28 ;
}
int F_85 ( struct V_142 * * V_164 , struct V_146 * V_144 )
{
unsigned int V_145 = F_60 ( V_144 ) ;
struct V_142 * V_28 ;
if ( V_144 -> V_6 == NULL )
return - V_89 ;
V_28 = F_61 ( F_73 ( V_144 -> V_24 ) , V_90 ) ;
if ( ! V_28 )
return - V_8 ;
memcpy ( V_28 -> V_149 , V_144 -> V_6 , V_145 ) ;
V_28 -> V_24 = V_144 -> V_24 ;
V_28 -> V_148 = NULL ;
V_28 = F_83 ( V_28 ) ;
if ( F_86 ( V_28 ) )
return F_87 ( V_28 ) ;
* V_164 = V_28 ;
return 0 ;
}
void F_88 ( struct V_142 * V_28 )
{
F_64 ( V_28 ) ;
}
int F_89 ( struct V_143 * V_144 , struct V_1 * V_2 )
{
struct F_1 * V_28 , * V_157 ;
unsigned int V_145 = F_60 ( V_144 ) ;
unsigned int V_165 = F_73 ( V_144 -> V_24 ) ;
struct V_142 * V_73 ;
int V_5 ;
if ( F_3 ( V_2 , V_166 ) )
return - V_10 ;
if ( V_144 -> V_6 == NULL )
return - V_89 ;
V_73 = F_61 ( V_165 , V_90 ) ;
if ( ! V_73 )
return - V_8 ;
if ( F_90 ( V_73 -> V_149 , V_144 -> V_6 , V_145 ) ) {
F_52 ( V_73 ) ;
return - V_167 ;
}
V_73 -> V_24 = V_144 -> V_24 ;
V_5 = F_59 ( V_73 , V_144 ) ;
if ( V_5 ) {
F_52 ( V_73 ) ;
return - V_8 ;
}
V_73 = F_83 ( V_73 ) ;
if ( F_86 ( V_73 ) )
return F_87 ( V_73 ) ;
V_28 = F_61 ( sizeof( * V_28 ) , V_90 ) ;
if ( ! V_28 ) {
F_64 ( V_73 ) ;
return - V_8 ;
}
V_28 -> V_73 = V_73 ;
F_91 ( & V_28 -> V_152 , 0 ) ;
if ( ! F_75 ( V_2 , V_28 ) ) {
F_66 ( V_28 ) ;
return - V_8 ;
}
V_157 = F_92 ( V_2 -> F_1 ,
F_93 ( V_2 ) ) ;
F_94 ( V_2 -> F_1 , V_28 ) ;
if ( V_157 )
F_72 ( V_2 , V_157 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 )
{
int V_136 = - V_168 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_166 ) )
return - V_10 ;
V_6 = F_92 ( V_2 -> F_1 ,
F_93 ( V_2 ) ) ;
if ( V_6 ) {
F_96 ( V_2 -> F_1 , NULL ) ;
F_72 ( V_2 , V_6 ) ;
V_136 = 0 ;
}
return V_136 ;
}
int F_97 ( struct V_1 * V_2 , struct V_27 T_4 * V_169 ,
unsigned int V_24 )
{
struct V_146 * V_144 ;
struct F_1 * V_6 ;
int V_136 = 0 ;
F_98 ( V_2 ) ;
V_6 = F_92 ( V_2 -> F_1 ,
F_93 ( V_2 ) ) ;
if ( ! V_6 )
goto V_170;
V_144 = V_6 -> V_73 -> V_148 ;
V_136 = V_144 -> V_24 ;
if ( ! V_24 )
goto V_170;
V_136 = - V_89 ;
if ( V_24 < V_144 -> V_24 )
goto V_170;
V_136 = - V_167 ;
if ( F_99 ( V_169 , V_144 -> V_6 , F_60 ( V_144 ) ) )
goto V_170;
V_136 = V_144 -> V_24 ;
V_170:
F_100 ( V_2 ) ;
return V_136 ;
}
