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
static T_1 F_11 ( T_1 V_14 , T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
return F_12 ( (struct V_3 * ) ( unsigned long ) V_14 ) ;
}
static T_1 F_13 ( T_1 V_14 , T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_14 ;
struct V_19 * V_20 ;
if ( F_14 ( V_4 ) )
return 0 ;
if ( V_4 -> V_21 < sizeof( struct V_19 ) )
return 0 ;
if ( V_15 > V_4 -> V_21 - sizeof( struct V_19 ) )
return 0 ;
V_20 = F_15 ( (struct V_19 * ) & V_4 -> V_22 [ V_15 ] , V_4 -> V_21 - V_15 , V_16 ) ;
if ( V_20 )
return ( void * ) V_20 - ( void * ) V_4 -> V_22 ;
return 0 ;
}
static T_1 F_16 ( T_1 V_14 , T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_14 ;
struct V_19 * V_20 ;
if ( F_14 ( V_4 ) )
return 0 ;
if ( V_4 -> V_21 < sizeof( struct V_19 ) )
return 0 ;
if ( V_15 > V_4 -> V_21 - sizeof( struct V_19 ) )
return 0 ;
V_20 = (struct V_19 * ) & V_4 -> V_22 [ V_15 ] ;
if ( V_20 -> V_23 > V_4 -> V_21 - V_15 )
return 0 ;
V_20 = F_17 ( V_20 , V_16 ) ;
if ( V_20 )
return ( void * ) V_20 - ( void * ) V_4 -> V_22 ;
return 0 ;
}
static T_1 F_18 ( T_1 V_14 , T_1 V_15 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
return F_19 () ;
}
static T_2 F_20 ( int V_24 , int V_25 , int V_26 ,
struct V_27 * V_28 )
{
struct V_27 * V_29 = V_28 ;
switch ( V_24 ) {
case V_30 :
F_21 ( F_22 ( struct V_3 , V_31 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_31 ) ) ;
break;
case V_33 :
* V_29 ++ = F_23 ( V_34 , V_25 , V_26 , F_25 () ) ;
* V_29 ++ = F_26 ( V_35 , V_25 , V_36 ) ;
#ifdef F_27
* V_29 ++ = F_26 ( V_37 , V_25 , 5 ) ;
#endif
break;
case V_38 :
F_21 ( F_22 ( struct V_3 , V_39 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_39 ) ) ;
break;
case V_41 :
case V_42 :
F_21 ( F_22 ( struct V_3 , V_43 ) != 2 ) ;
F_21 ( V_44 != 0x1000 ) ;
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_43 ) ) ;
if ( V_24 == V_41 ) {
* V_29 ++ = F_26 ( V_35 , V_25 ,
~ V_44 ) ;
} else {
* V_29 ++ = F_26 ( V_37 , V_25 , 12 ) ;
* V_29 ++ = F_26 ( V_35 , V_25 , 1 ) ;
}
break;
}
return V_29 - V_28 ;
}
static bool F_28 ( struct V_45 * V_46 ,
struct V_27 * * V_47 )
{
struct V_27 * V_29 = * V_47 ;
T_2 V_48 ;
switch ( V_46 -> V_49 ) {
case V_50 + V_51 :
F_21 ( F_22 ( struct V_3 , V_52 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_53 , V_54 ,
F_24 ( struct V_3 , V_52 ) ) ;
* V_29 = F_29 ( V_55 , V_53 , 16 ) ;
break;
case V_50 + V_33 :
V_48 = F_20 ( V_33 , V_53 , V_54 , V_29 ) ;
V_29 += V_48 - 1 ;
break;
case V_50 + V_56 :
case V_50 + V_57 :
F_21 ( F_22 ( struct V_58 , V_59 ) != 4 ) ;
F_21 ( F_22 ( struct V_58 , type ) != 2 ) ;
F_21 ( F_30 ( F_22 ( struct V_3 , V_60 ) ) < 0 ) ;
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_3 , V_60 ) ) ,
V_61 , V_54 ,
F_24 ( struct V_3 , V_60 ) ) ;
* V_29 ++ = F_31 ( V_62 , V_61 , 0 , 1 ) ;
* V_29 ++ = F_32 () ;
if ( V_46 -> V_49 == V_50 + V_56 )
* V_29 = F_23 ( V_32 , V_53 , V_61 ,
F_24 ( struct V_58 , V_59 ) ) ;
else
* V_29 = F_23 ( V_40 , V_53 , V_61 ,
F_24 ( struct V_58 , type ) ) ;
break;
case V_50 + V_30 :
V_48 = F_20 ( V_30 , V_53 , V_54 , V_29 ) ;
V_29 += V_48 - 1 ;
break;
case V_50 + V_63 :
F_21 ( F_22 ( struct V_3 , V_64 ) != 4 ) ;
* V_29 = F_23 ( V_32 , V_53 , V_54 ,
F_24 ( struct V_3 , V_64 ) ) ;
break;
case V_50 + V_38 :
V_48 = F_20 ( V_38 , V_53 , V_54 , V_29 ) ;
V_29 += V_48 - 1 ;
break;
case V_50 + V_41 :
V_48 = F_20 ( V_41 ,
V_53 , V_54 , V_29 ) ;
V_29 += V_48 - 1 ;
break;
case V_50 + V_42 :
V_48 = F_20 ( V_42 ,
V_53 , V_54 , V_29 ) ;
V_29 += V_48 - 1 ;
break;
case V_50 + V_65 :
F_21 ( F_22 ( struct V_3 , V_66 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_53 , V_54 ,
F_24 ( struct V_3 , V_66 ) ) ;
* V_29 = F_29 ( V_55 , V_53 , 16 ) ;
break;
case V_50 + V_67 :
case V_50 + V_68 :
case V_50 + V_69 :
case V_50 + V_70 :
case V_50 + V_71 :
* V_29 ++ = F_33 ( V_72 , V_54 ) ;
* V_29 ++ = F_33 ( V_73 , V_53 ) ;
* V_29 ++ = F_33 ( V_74 , V_75 ) ;
switch ( V_46 -> V_49 ) {
case V_50 + V_67 :
* V_29 = F_34 ( F_11 ) ;
break;
case V_50 + V_68 :
* V_29 = F_34 ( F_13 ) ;
break;
case V_50 + V_69 :
* V_29 = F_34 ( F_16 ) ;
break;
case V_50 + V_70 :
* V_29 = F_34 ( F_18 ) ;
break;
case V_50 + V_71 :
* V_29 = F_34 ( V_76 ) ;
F_35 () ;
break;
}
break;
case V_50 + V_77 :
* V_29 = F_36 ( V_78 , V_53 , V_75 ) ;
break;
default:
F_37 ( F_38 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_47 = V_29 ;
return true ;
}
static int F_39 ( struct V_45 * V_12 , int V_21 ,
struct V_27 * V_79 , int * V_80 )
{
int V_81 = 0 , V_82 = 0 , V_83 , V_84 ;
struct V_27 * V_85 ;
struct V_45 * V_46 ;
int * V_86 = NULL ;
T_3 V_87 ;
F_21 ( V_88 * sizeof( T_2 ) > V_89 ) ;
F_21 ( V_90 + 1 != V_91 ) ;
if ( V_21 <= 0 || V_21 > V_92 )
return - V_93 ;
if ( V_79 ) {
V_86 = F_40 ( V_21 , sizeof( * V_86 ) ,
V_94 | V_95 ) ;
if ( ! V_86 )
return - V_10 ;
}
V_96:
V_85 = V_79 ;
V_46 = V_12 ;
if ( V_85 ) {
* V_85 ++ = F_41 ( V_78 , V_53 , V_53 ) ;
* V_85 ++ = F_41 ( V_78 , V_75 , V_75 ) ;
* V_85 ++ = F_33 ( V_54 , V_72 ) ;
} else {
V_85 += 3 ;
}
for ( V_84 = 0 ; V_84 < V_21 ; V_46 ++ , V_84 ++ ) {
struct V_27 V_97 [ 6 ] = { } ;
struct V_27 * V_29 = V_97 ;
if ( V_86 )
V_86 [ V_84 ] = V_85 - V_79 ;
switch ( V_46 -> V_98 ) {
case V_99 | V_100 | V_101 :
case V_99 | V_100 | V_102 :
case V_99 | V_103 | V_101 :
case V_99 | V_103 | V_102 :
case V_99 | V_35 | V_101 :
case V_99 | V_35 | V_102 :
case V_99 | V_104 | V_101 :
case V_99 | V_104 | V_102 :
case V_99 | V_105 | V_101 :
case V_99 | V_105 | V_102 :
case V_99 | V_37 | V_101 :
case V_99 | V_37 | V_102 :
case V_99 | V_78 | V_101 :
case V_99 | V_78 | V_102 :
case V_99 | V_106 | V_101 :
case V_99 | V_106 | V_102 :
case V_99 | V_107 | V_101 :
case V_99 | V_107 | V_102 :
case V_99 | V_108 | V_101 :
case V_99 | V_108 | V_102 :
case V_99 | V_109 :
case V_110 | V_111 | V_32 :
case V_110 | V_111 | V_40 :
case V_110 | V_111 | V_34 :
case V_110 | V_112 | V_32 :
case V_110 | V_112 | V_40 :
case V_110 | V_112 | V_34 :
if ( F_42 ( V_46 -> V_98 ) == V_110 &&
F_43 ( V_46 -> V_98 ) == V_111 &&
F_28 ( V_46 , & V_29 ) )
break;
* V_29 = F_44 ( V_46 -> V_98 , V_53 , V_75 , 0 , V_46 -> V_49 ) ;
break;
#define F_45 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_113 | V_114 :
V_83 = V_84 + V_46 -> V_49 + 1 ;
V_29 -> V_98 = V_46 -> V_98 ;
F_45 ;
break;
case V_113 | V_115 | V_102 :
case V_113 | V_115 | V_101 :
case V_113 | V_116 | V_102 :
case V_113 | V_116 | V_101 :
case V_113 | V_117 | V_102 :
case V_113 | V_117 | V_101 :
case V_113 | V_118 | V_102 :
case V_113 | V_118 | V_101 :
if ( F_46 ( V_46 -> V_98 ) == V_102 && ( int ) V_46 -> V_49 < 0 ) {
* V_29 ++ = F_47 ( V_61 , V_46 -> V_49 ) ;
V_29 -> V_25 = V_53 ;
V_29 -> V_26 = V_61 ;
V_87 = V_101 ;
} else {
V_29 -> V_25 = V_53 ;
V_29 -> V_119 = V_46 -> V_49 ;
V_87 = F_46 ( V_46 -> V_98 ) ;
V_29 -> V_26 = V_87 == V_101 ? V_75 : 0 ;
}
if ( V_46 -> V_120 == 0 ) {
V_29 -> V_98 = V_113 | F_48 ( V_46 -> V_98 ) | V_87 ;
V_83 = V_84 + V_46 -> V_121 + 1 ;
F_45 ;
break;
}
if ( V_46 -> V_121 == 0 && F_48 ( V_46 -> V_98 ) == V_115 ) {
V_29 -> V_98 = V_113 | V_62 | V_87 ;
V_83 = V_84 + V_46 -> V_120 + 1 ;
F_45 ;
break;
}
V_83 = V_84 + V_46 -> V_121 + 1 ;
V_29 -> V_98 = V_113 | F_48 ( V_46 -> V_98 ) | V_87 ;
F_45 ;
V_29 ++ ;
V_29 -> V_98 = V_113 | V_114 ;
V_83 = V_84 + V_46 -> V_120 + 1 ;
F_45 ;
break;
case V_122 | V_123 | V_34 :
* V_29 ++ = F_33 ( V_61 , V_53 ) ;
* V_29 ++ = F_49 ( V_34 , V_46 -> V_49 ) ;
* V_29 ++ = F_26 ( V_35 , V_53 , 0xf ) ;
* V_29 ++ = F_26 ( V_105 , V_53 , 2 ) ;
* V_29 ++ = F_33 ( V_75 , V_53 ) ;
* V_29 = F_33 ( V_53 , V_61 ) ;
break;
case V_124 | V_125 :
case V_124 | V_102 :
if ( F_50 ( V_46 -> V_98 ) == V_102 )
* V_29 ++ = F_51 ( V_102 , V_126 ,
0 , V_46 -> V_49 ) ;
* V_29 = F_32 () ;
break;
case V_127 :
case V_128 :
* V_29 = F_52 ( V_32 , V_90 , F_42 ( V_46 -> V_98 ) ==
V_127 ? V_53 : V_75 ,
- ( V_88 - V_46 -> V_49 ) * 4 ) ;
break;
case V_110 | V_129 :
case V_122 | V_129 :
* V_29 = F_23 ( V_32 , F_42 ( V_46 -> V_98 ) == V_110 ?
V_53 : V_75 , V_90 ,
- ( V_88 - V_46 -> V_49 ) * 4 ) ;
break;
case V_110 | V_130 :
case V_122 | V_130 :
* V_29 = F_47 ( F_42 ( V_46 -> V_98 ) == V_110 ?
V_53 : V_75 , V_46 -> V_49 ) ;
break;
case V_131 | V_132 :
* V_29 = F_33 ( V_75 , V_53 ) ;
break;
case V_131 | V_133 :
* V_29 = F_33 ( V_53 , V_75 ) ;
break;
case V_110 | V_32 | V_134 :
case V_122 | V_32 | V_134 :
* V_29 = F_23 ( V_32 , F_42 ( V_46 -> V_98 ) == V_110 ?
V_53 : V_75 , V_54 ,
F_24 ( struct V_3 , V_21 ) ) ;
break;
case V_122 | V_111 | V_32 :
* V_29 = F_23 ( V_32 , V_53 , V_54 , V_46 -> V_49 ) ;
break;
default:
goto V_6;
}
V_29 ++ ;
if ( V_79 )
memcpy ( V_85 , V_97 ,
sizeof( * V_29 ) * ( V_29 - V_97 ) ) ;
V_85 += V_29 - V_97 ;
}
if ( ! V_79 ) {
* V_80 = V_85 - V_79 ;
return 0 ;
}
V_82 ++ ;
if ( V_81 != V_85 - V_79 ) {
V_81 = V_85 - V_79 ;
if ( V_82 > 2 )
goto V_6;
goto V_96;
}
F_53 ( V_86 ) ;
F_37 ( * V_80 != V_81 ) ;
return 0 ;
V_6:
F_53 ( V_86 ) ;
return - V_93 ;
}
static int F_54 ( const struct V_45 * V_8 , int V_135 )
{
T_4 * V_136 , V_137 = 0 ;
int V_138 , V_139 = 0 ;
F_21 ( V_88 > 16 ) ;
V_136 = F_55 ( V_135 , sizeof( * V_136 ) , V_94 ) ;
if ( ! V_136 )
return - V_10 ;
memset ( V_136 , 0xff , V_135 * sizeof( * V_136 ) ) ;
for ( V_138 = 0 ; V_138 < V_135 ; V_138 ++ ) {
V_137 &= V_136 [ V_138 ] ;
switch ( V_8 [ V_138 ] . V_98 ) {
case V_127 :
case V_128 :
V_137 |= ( 1 << V_8 [ V_138 ] . V_49 ) ;
break;
case V_110 | V_129 :
case V_122 | V_129 :
if ( ! ( V_137 & ( 1 << V_8 [ V_138 ] . V_49 ) ) ) {
V_139 = - V_93 ;
goto error;
}
break;
case V_113 | V_114 :
V_136 [ V_138 + 1 + V_8 [ V_138 ] . V_49 ] &= V_137 ;
V_137 = ~ 0 ;
break;
case V_113 | V_115 | V_102 :
case V_113 | V_115 | V_101 :
case V_113 | V_118 | V_102 :
case V_113 | V_118 | V_101 :
case V_113 | V_117 | V_102 :
case V_113 | V_117 | V_101 :
case V_113 | V_116 | V_102 :
case V_113 | V_116 | V_101 :
V_136 [ V_138 + 1 + V_8 [ V_138 ] . V_121 ] &= V_137 ;
V_136 [ V_138 + 1 + V_8 [ V_138 ] . V_120 ] &= V_137 ;
V_137 = ~ 0 ;
break;
}
}
error:
F_53 ( V_136 ) ;
return V_139 ;
}
static bool F_56 ( T_4 V_140 )
{
static const bool V_141 [] = {
[ V_99 | V_100 | V_102 ] = true ,
[ V_99 | V_100 | V_101 ] = true ,
[ V_99 | V_103 | V_102 ] = true ,
[ V_99 | V_103 | V_101 ] = true ,
[ V_99 | V_106 | V_102 ] = true ,
[ V_99 | V_106 | V_101 ] = true ,
[ V_99 | V_107 | V_102 ] = true ,
[ V_99 | V_107 | V_101 ] = true ,
[ V_99 | V_108 | V_102 ] = true ,
[ V_99 | V_108 | V_101 ] = true ,
[ V_99 | V_35 | V_102 ] = true ,
[ V_99 | V_35 | V_101 ] = true ,
[ V_99 | V_104 | V_102 ] = true ,
[ V_99 | V_104 | V_101 ] = true ,
[ V_99 | V_78 | V_102 ] = true ,
[ V_99 | V_78 | V_101 ] = true ,
[ V_99 | V_105 | V_102 ] = true ,
[ V_99 | V_105 | V_101 ] = true ,
[ V_99 | V_37 | V_102 ] = true ,
[ V_99 | V_37 | V_101 ] = true ,
[ V_99 | V_109 ] = true ,
[ V_110 | V_32 | V_111 ] = true ,
[ V_110 | V_40 | V_111 ] = true ,
[ V_110 | V_34 | V_111 ] = true ,
[ V_110 | V_32 | V_134 ] = true ,
[ V_110 | V_32 | V_112 ] = true ,
[ V_110 | V_40 | V_112 ] = true ,
[ V_110 | V_34 | V_112 ] = true ,
[ V_110 | V_130 ] = true ,
[ V_110 | V_129 ] = true ,
[ V_122 | V_32 | V_134 ] = true ,
[ V_122 | V_34 | V_123 ] = true ,
[ V_122 | V_130 ] = true ,
[ V_122 | V_129 ] = true ,
[ V_127 ] = true ,
[ V_128 ] = true ,
[ V_131 | V_132 ] = true ,
[ V_131 | V_133 ] = true ,
[ V_124 | V_102 ] = true ,
[ V_124 | V_125 ] = true ,
[ V_113 | V_114 ] = true ,
[ V_113 | V_115 | V_102 ] = true ,
[ V_113 | V_115 | V_101 ] = true ,
[ V_113 | V_118 | V_102 ] = true ,
[ V_113 | V_118 | V_101 ] = true ,
[ V_113 | V_117 | V_102 ] = true ,
[ V_113 | V_117 | V_101 ] = true ,
[ V_113 | V_116 | V_102 ] = true ,
[ V_113 | V_116 | V_101 ] = true ,
} ;
if ( V_140 >= F_57 ( V_141 ) )
return false ;
return V_141 [ V_140 ] ;
}
static int F_58 ( const struct V_45 * V_8 ,
unsigned int V_135 )
{
bool V_142 ;
int V_138 ;
if ( V_135 == 0 || V_135 > V_92 )
return - V_93 ;
for ( V_138 = 0 ; V_138 < V_135 ; V_138 ++ ) {
const struct V_45 * V_143 = & V_8 [ V_138 ] ;
if ( ! F_56 ( V_143 -> V_98 ) )
return - V_93 ;
switch ( V_143 -> V_98 ) {
case V_99 | V_107 | V_102 :
case V_99 | V_108 | V_102 :
if ( V_143 -> V_49 == 0 )
return - V_93 ;
break;
case V_99 | V_105 | V_102 :
case V_99 | V_37 | V_102 :
if ( V_143 -> V_49 >= 32 )
return - V_93 ;
break;
case V_110 | V_129 :
case V_122 | V_129 :
case V_127 :
case V_128 :
if ( V_143 -> V_49 >= V_88 )
return - V_93 ;
break;
case V_113 | V_114 :
if ( V_143 -> V_49 >= ( unsigned int ) ( V_135 - V_138 - 1 ) )
return - V_93 ;
break;
case V_113 | V_115 | V_102 :
case V_113 | V_115 | V_101 :
case V_113 | V_118 | V_102 :
case V_113 | V_118 | V_101 :
case V_113 | V_117 | V_102 :
case V_113 | V_117 | V_101 :
case V_113 | V_116 | V_102 :
case V_113 | V_116 | V_101 :
if ( V_138 + V_143 -> V_121 + 1 >= V_135 ||
V_138 + V_143 -> V_120 + 1 >= V_135 )
return - V_93 ;
break;
case V_110 | V_32 | V_111 :
case V_110 | V_40 | V_111 :
case V_110 | V_34 | V_111 :
V_142 = false ;
if ( F_59 ( V_143 ) & V_144 )
V_142 = true ;
if ( V_142 == false && V_143 -> V_49 >= V_50 )
return - V_93 ;
}
}
switch ( V_8 [ V_135 - 1 ] . V_98 ) {
case V_124 | V_102 :
case V_124 | V_125 :
return F_54 ( V_8 , V_135 ) ;
}
return - V_93 ;
}
static int F_60 ( struct V_145 * V_46 ,
const struct V_146 * V_147 )
{
unsigned int V_148 = F_61 ( V_147 ) ;
struct V_149 * V_150 ;
V_46 -> V_151 = F_62 ( sizeof( * V_150 ) , V_94 ) ;
if ( ! V_46 -> V_151 )
return - V_10 ;
V_150 = V_46 -> V_151 ;
V_150 -> V_21 = V_147 -> V_21 ;
V_150 -> V_8 = F_63 ( V_46 -> V_152 , V_148 ,
V_94 | V_95 ) ;
if ( ! V_150 -> V_8 ) {
F_53 ( V_46 -> V_151 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_64 ( struct V_145 * V_46 )
{
struct V_149 * V_147 = V_46 -> V_151 ;
if ( V_147 ) {
F_53 ( V_147 -> V_8 ) ;
F_53 ( V_147 ) ;
}
}
static void F_65 ( struct V_145 * V_12 )
{
if ( V_12 -> type == V_153 ) {
F_66 ( V_12 ) ;
} else {
F_64 ( V_12 ) ;
F_67 ( V_12 ) ;
}
}
static void F_68 ( struct V_7 * V_46 )
{
F_65 ( V_46 -> V_12 ) ;
F_53 ( V_46 ) ;
}
static void F_69 ( struct V_154 * V_155 )
{
struct V_7 * V_46 = F_70 ( V_155 , struct V_7 , V_155 ) ;
F_68 ( V_46 ) ;
}
static void F_71 ( struct V_7 * V_46 )
{
if ( F_72 ( & V_46 -> V_156 ) )
F_73 ( & V_46 -> V_155 , F_69 ) ;
}
void F_74 ( struct V_1 * V_2 , struct V_7 * V_46 )
{
T_2 V_157 = F_75 ( V_46 -> V_12 -> V_21 ) ;
F_76 ( V_157 , & V_2 -> V_158 ) ;
F_71 ( V_46 ) ;
}
bool F_77 ( struct V_1 * V_2 , struct V_7 * V_46 )
{
T_2 V_157 = F_75 ( V_46 -> V_12 -> V_21 ) ;
if ( V_157 <= V_159 &&
F_78 ( & V_2 -> V_158 ) + V_157 < V_159 ) {
F_79 ( & V_46 -> V_156 ) ;
F_80 ( V_157 , & V_2 -> V_158 ) ;
return true ;
}
return false ;
}
static struct V_145 * F_81 ( struct V_145 * V_46 )
{
struct V_45 * V_160 ;
struct V_145 * V_161 ;
int V_6 , V_80 , V_162 = V_46 -> V_21 ;
F_21 ( sizeof( struct V_45 ) !=
sizeof( struct V_27 ) ) ;
V_160 = F_63 ( V_46 -> V_152 , V_162 * sizeof( struct V_45 ) ,
V_94 | V_95 ) ;
if ( ! V_160 ) {
V_6 = - V_10 ;
goto V_163;
}
V_6 = F_39 ( V_160 , V_162 , NULL , & V_80 ) ;
if ( V_6 )
goto V_164;
V_161 = V_46 ;
V_46 = F_82 ( V_161 , F_75 ( V_80 ) , 0 ) ;
if ( ! V_46 ) {
V_46 = V_161 ;
V_6 = - V_10 ;
goto V_164;
}
V_46 -> V_21 = V_80 ;
V_6 = F_39 ( V_160 , V_162 , V_46 -> V_165 , & V_80 ) ;
if ( V_6 )
goto V_164;
V_46 = F_83 ( V_46 , & V_6 ) ;
F_53 ( V_160 ) ;
return V_46 ;
V_164:
F_53 ( V_160 ) ;
V_163:
F_65 ( V_46 ) ;
return F_84 ( V_6 ) ;
}
static struct V_145 * F_85 ( struct V_145 * V_46 ,
T_5 V_166 )
{
int V_6 ;
V_46 -> V_167 = NULL ;
V_46 -> V_168 = 0 ;
V_6 = F_58 ( V_46 -> V_152 , V_46 -> V_21 ) ;
if ( V_6 ) {
F_65 ( V_46 ) ;
return F_84 ( V_6 ) ;
}
if ( V_166 ) {
V_6 = V_166 ( V_46 -> V_152 , V_46 -> V_21 ) ;
if ( V_6 ) {
F_65 ( V_46 ) ;
return F_84 ( V_6 ) ;
}
}
F_86 ( V_46 ) ;
if ( ! V_46 -> V_168 )
V_46 = F_81 ( V_46 ) ;
return V_46 ;
}
int F_87 ( struct V_145 * * V_169 , struct V_149 * V_147 )
{
unsigned int V_148 = F_61 ( V_147 ) ;
struct V_145 * V_46 ;
if ( V_147 -> V_8 == NULL )
return - V_93 ;
V_46 = F_88 ( F_75 ( V_147 -> V_21 ) , 0 ) ;
if ( ! V_46 )
return - V_10 ;
memcpy ( V_46 -> V_152 , V_147 -> V_8 , V_148 ) ;
V_46 -> V_21 = V_147 -> V_21 ;
V_46 -> V_151 = NULL ;
V_46 = F_85 ( V_46 , NULL ) ;
if ( F_89 ( V_46 ) )
return F_90 ( V_46 ) ;
* V_169 = V_46 ;
return 0 ;
}
int F_91 ( struct V_145 * * V_169 , struct V_146 * V_147 ,
T_5 V_166 , bool V_170 )
{
unsigned int V_148 = F_61 ( V_147 ) ;
struct V_145 * V_46 ;
int V_6 ;
if ( V_147 -> V_8 == NULL )
return - V_93 ;
V_46 = F_88 ( F_75 ( V_147 -> V_21 ) , 0 ) ;
if ( ! V_46 )
return - V_10 ;
if ( F_92 ( V_46 -> V_152 , V_147 -> V_8 , V_148 ) ) {
F_93 ( V_46 ) ;
return - V_171 ;
}
V_46 -> V_21 = V_147 -> V_21 ;
V_46 -> V_151 = NULL ;
if ( V_170 ) {
V_6 = F_60 ( V_46 , V_147 ) ;
if ( V_6 ) {
F_93 ( V_46 ) ;
return - V_10 ;
}
}
V_46 = F_85 ( V_46 , V_166 ) ;
if ( F_89 ( V_46 ) )
return F_90 ( V_46 ) ;
* V_169 = V_46 ;
return 0 ;
}
void F_94 ( struct V_145 * V_46 )
{
F_65 ( V_46 ) ;
}
static int F_95 ( struct V_145 * V_12 , struct V_1 * V_2 )
{
struct V_7 * V_46 , * V_161 ;
V_46 = F_62 ( sizeof( * V_46 ) , V_94 ) ;
if ( ! V_46 )
return - V_10 ;
V_46 -> V_12 = V_12 ;
F_96 ( & V_46 -> V_156 , 0 ) ;
if ( ! F_77 ( V_2 , V_46 ) ) {
F_53 ( V_46 ) ;
return - V_10 ;
}
V_161 = F_97 ( V_2 -> V_7 ,
F_98 ( V_2 ) ) ;
F_99 ( V_2 -> V_7 , V_46 ) ;
if ( V_161 )
F_74 ( V_2 , V_161 ) ;
return 0 ;
}
static int F_100 ( struct V_145 * V_12 , struct V_1 * V_2 )
{
struct V_145 * V_160 ;
int V_6 ;
if ( F_75 ( V_12 -> V_21 ) > V_159 )
return - V_10 ;
if ( F_101 ( V_2 ) && V_2 -> V_172 ) {
V_6 = F_102 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_103 ( V_2 -> V_173 ) ) {
return - V_93 ;
}
V_160 = F_104 ( V_2 , V_12 ) ;
if ( V_160 )
F_94 ( V_160 ) ;
return 0 ;
}
static
struct V_145 * F_105 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
unsigned int V_148 = F_61 ( V_147 ) ;
unsigned int V_174 = F_75 ( V_147 -> V_21 ) ;
struct V_145 * V_12 ;
int V_6 ;
if ( F_3 ( V_2 , V_175 ) )
return F_84 ( - V_13 ) ;
if ( V_147 -> V_8 == NULL )
return F_84 ( - V_93 ) ;
V_12 = F_88 ( V_174 , 0 ) ;
if ( ! V_12 )
return F_84 ( - V_10 ) ;
if ( F_92 ( V_12 -> V_152 , V_147 -> V_8 , V_148 ) ) {
F_93 ( V_12 ) ;
return F_84 ( - V_171 ) ;
}
V_12 -> V_21 = V_147 -> V_21 ;
V_6 = F_60 ( V_12 , V_147 ) ;
if ( V_6 ) {
F_93 ( V_12 ) ;
return F_84 ( - V_10 ) ;
}
return F_85 ( V_12 , NULL ) ;
}
int F_106 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_105 ( V_147 , V_2 ) ;
int V_6 ;
if ( F_89 ( V_12 ) )
return F_90 ( V_12 ) ;
V_6 = F_95 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_65 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_107 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_105 ( V_147 , V_2 ) ;
int V_6 ;
if ( F_89 ( V_12 ) )
return F_90 ( V_12 ) ;
V_6 = F_100 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_65 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_145 * F_108 ( T_2 V_176 , struct V_1 * V_2 )
{
struct V_145 * V_12 ;
if ( F_3 ( V_2 , V_175 ) )
return F_84 ( - V_13 ) ;
V_12 = F_109 ( V_176 ) ;
if ( F_89 ( V_12 ) )
return V_12 ;
if ( V_12 -> type != V_153 ) {
F_66 ( V_12 ) ;
return F_84 ( - V_93 ) ;
}
return V_12 ;
}
int F_110 ( T_2 V_176 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_108 ( V_176 , V_2 ) ;
int V_6 ;
if ( F_89 ( V_12 ) )
return F_90 ( V_12 ) ;
V_6 = F_95 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_66 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_111 ( T_2 V_176 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_108 ( V_176 , V_2 ) ;
int V_6 ;
if ( F_89 ( V_12 ) )
return F_90 ( V_12 ) ;
V_6 = F_100 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_66 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_112 ( struct V_3 * V_4 ,
unsigned int V_177 )
{
int V_6 ;
if ( ! F_113 ( V_4 ) )
return 0 ;
if ( F_114 ( V_4 , V_177 ) )
return 0 ;
V_6 = F_115 ( V_4 , 0 , 0 , V_178 ) ;
if ( ! V_6 )
F_116 ( V_4 ) ;
return V_6 ;
}
static T_1 F_117 ( T_1 V_179 , T_1 V_180 , T_1 V_181 , T_1 V_17 , T_1 V_182 )
{
struct V_183 * V_184 = F_118 ( & V_185 ) ;
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
int V_186 = ( int ) V_180 ;
void * V_187 = ( void * ) ( long ) V_181 ;
unsigned int V_21 = ( unsigned int ) V_17 ;
void * V_188 ;
if ( F_119 ( V_182 & ~ ( V_189 | V_190 ) ) )
return - V_93 ;
if ( F_119 ( ( T_2 ) V_186 > 0xffff || V_21 > sizeof( V_184 -> V_191 ) ) )
return - V_171 ;
if ( F_119 ( F_112 ( V_4 , V_186 + V_21 ) ) )
return - V_171 ;
V_188 = F_120 ( V_4 , V_186 , V_21 , V_184 -> V_191 ) ;
if ( F_119 ( ! V_188 ) )
return - V_171 ;
if ( V_182 & V_189 )
F_121 ( V_4 , V_188 , V_21 ) ;
memcpy ( V_188 , V_187 , V_21 ) ;
if ( V_188 == V_184 -> V_191 )
F_122 ( V_4 , V_186 , V_188 , V_21 ) ;
if ( V_182 & V_189 )
F_123 ( V_4 , V_188 , V_21 ) ;
if ( V_182 & V_190 )
F_124 ( V_4 ) ;
return 0 ;
}
static T_1 F_125 ( T_1 V_179 , T_1 V_180 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) ( unsigned long ) V_179 ;
int V_186 = ( int ) V_180 ;
void * V_192 = ( void * ) ( unsigned long ) V_181 ;
unsigned int V_21 = ( unsigned int ) V_17 ;
void * V_188 ;
if ( F_119 ( ( T_2 ) V_186 > 0xffff ) )
goto V_193;
V_188 = F_120 ( V_4 , V_186 , V_21 , V_192 ) ;
if ( F_119 ( ! V_188 ) )
goto V_193;
if ( V_188 != V_192 )
memcpy ( V_192 , V_188 , V_21 ) ;
return 0 ;
V_193:
memset ( V_192 , 0 , V_21 ) ;
return - V_171 ;
}
static T_1 F_126 ( T_1 V_179 , T_1 V_180 , T_1 V_187 , T_1 V_192 , T_1 V_182 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
int V_186 = ( int ) V_180 ;
T_6 V_194 , * V_188 ;
if ( F_119 ( V_182 & ~ ( V_195 ) ) )
return - V_93 ;
if ( F_119 ( ( T_2 ) V_186 > 0xffff ) )
return - V_171 ;
if ( F_119 ( F_112 ( V_4 , V_186 + sizeof( V_194 ) ) ) )
return - V_171 ;
V_188 = F_120 ( V_4 , V_186 , sizeof( V_194 ) , & V_194 ) ;
if ( F_119 ( ! V_188 ) )
return - V_171 ;
switch ( V_182 & V_195 ) {
case 0 :
if ( F_119 ( V_187 != 0 ) )
return - V_93 ;
F_127 ( V_188 , V_192 ) ;
break;
case 2 :
F_128 ( V_188 , V_187 , V_192 ) ;
break;
case 4 :
F_129 ( V_188 , V_187 , V_192 ) ;
break;
default:
return - V_93 ;
}
if ( V_188 == & V_194 )
F_122 ( V_4 , V_186 , V_188 , sizeof( V_194 ) ) ;
return 0 ;
}
static T_1 F_130 ( T_1 V_179 , T_1 V_180 , T_1 V_187 , T_1 V_192 , T_1 V_182 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
bool V_196 = V_182 & V_197 ;
bool V_198 = V_182 & V_199 ;
int V_186 = ( int ) V_180 ;
T_6 V_194 , * V_188 ;
if ( F_119 ( V_182 & ~ ( V_199 | V_197 |
V_195 ) ) )
return - V_93 ;
if ( F_119 ( ( T_2 ) V_186 > 0xffff ) )
return - V_171 ;
if ( F_119 ( F_112 ( V_4 , V_186 + sizeof( V_194 ) ) ) )
return - V_171 ;
V_188 = F_120 ( V_4 , V_186 , sizeof( V_194 ) , & V_194 ) ;
if ( F_119 ( ! V_188 ) )
return - V_171 ;
if ( V_198 && ! * V_188 )
return 0 ;
switch ( V_182 & V_195 ) {
case 0 :
if ( F_119 ( V_187 != 0 ) )
return - V_93 ;
F_131 ( V_188 , V_4 , V_192 , V_196 ) ;
break;
case 2 :
F_132 ( V_188 , V_4 , V_187 , V_192 , V_196 ) ;
break;
case 4 :
F_133 ( V_188 , V_4 , V_187 , V_192 , V_196 ) ;
break;
default:
return - V_93 ;
}
if ( V_198 && ! * V_188 )
* V_188 = V_200 ;
if ( V_188 == & V_194 )
F_122 ( V_4 , V_186 , V_188 , sizeof( V_194 ) ) ;
return 0 ;
}
static T_1 F_134 ( T_1 V_179 , T_1 V_201 , T_1 V_181 , T_1 V_202 , T_1 V_203 )
{
struct V_183 * V_184 = F_118 ( & V_185 ) ;
T_1 V_204 = V_201 + V_202 ;
T_7 * V_187 = ( T_7 * ) ( long ) V_179 ;
T_7 * V_192 = ( T_7 * ) ( long ) V_181 ;
int V_84 , V_205 = 0 ;
if ( F_119 ( ( ( V_201 | V_202 ) & ( sizeof( T_7 ) - 1 ) ) ||
V_204 > sizeof( V_184 -> V_206 ) ) )
return - V_93 ;
for ( V_84 = 0 ; V_84 < V_201 / sizeof( T_7 ) ; V_84 ++ , V_205 ++ )
V_184 -> V_206 [ V_205 ] = ~ V_187 [ V_84 ] ;
for ( V_84 = 0 ; V_84 < V_202 / sizeof( T_7 ) ; V_84 ++ , V_205 ++ )
V_184 -> V_206 [ V_205 ] = V_192 [ V_84 ] ;
return F_135 ( V_184 -> V_206 , V_204 , V_203 ) ;
}
static T_1 F_136 ( T_1 V_179 , T_1 V_59 , T_1 V_182 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 , * V_207 ;
struct V_58 * V_60 ;
if ( F_119 ( V_182 & ~ ( V_208 ) ) )
return - V_93 ;
V_60 = F_137 ( F_138 ( V_4 -> V_60 ) , V_59 ) ;
if ( F_119 ( ! V_60 ) )
return - V_93 ;
V_207 = F_139 ( V_4 , V_178 ) ;
if ( F_119 ( ! V_207 ) )
return - V_10 ;
if ( V_182 & V_208 ) {
if ( F_140 ( V_207 ) )
F_123 ( V_207 , F_141 ( V_207 ) ,
V_207 -> V_209 ) ;
return F_142 ( V_60 , V_207 ) ;
}
V_207 -> V_60 = V_60 ;
return F_143 ( V_207 ) ;
}
static T_1 F_144 ( T_1 V_59 , T_1 V_182 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
struct V_210 * V_211 = F_118 ( & V_210 ) ;
if ( F_119 ( V_182 & ~ ( V_208 ) ) )
return V_212 ;
V_211 -> V_59 = V_59 ;
V_211 -> V_182 = V_182 ;
return V_213 ;
}
int F_145 ( struct V_3 * V_4 )
{
struct V_210 * V_211 = F_118 ( & V_210 ) ;
struct V_58 * V_60 ;
V_60 = F_137 ( F_138 ( V_4 -> V_60 ) , V_211 -> V_59 ) ;
V_211 -> V_59 = 0 ;
if ( F_119 ( ! V_60 ) ) {
F_146 ( V_4 ) ;
return - V_93 ;
}
if ( V_211 -> V_182 & V_208 ) {
if ( F_140 ( V_4 ) )
F_123 ( V_4 , F_141 ( V_4 ) ,
V_4 -> V_209 ) ;
return F_142 ( V_60 , V_4 ) ;
}
V_4 -> V_60 = V_60 ;
return F_143 ( V_4 ) ;
}
static T_1 F_147 ( T_1 V_179 , T_1 V_180 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
return F_148 ( (struct V_3 * ) ( unsigned long ) V_179 ) ;
}
static T_1 F_149 ( T_1 V_179 , T_1 V_180 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
return F_150 ( (struct V_3 * ) ( unsigned long ) V_179 ) ;
}
static T_1 F_151 ( T_1 V_179 , T_1 V_180 , T_1 V_43 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
T_8 V_66 = ( V_214 T_8 ) V_180 ;
int V_139 ;
if ( F_119 ( V_66 != F_152 ( V_215 ) &&
V_66 != F_152 ( V_216 ) ) )
V_66 = F_152 ( V_215 ) ;
V_139 = F_153 ( V_4 , V_66 , V_43 ) ;
F_116 ( V_4 ) ;
return V_139 ;
}
static T_1 F_154 ( T_1 V_179 , T_1 V_180 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
int V_139 ;
V_139 = F_155 ( V_4 ) ;
F_116 ( V_4 ) ;
return V_139 ;
}
bool F_156 ( void * V_217 )
{
if ( V_217 == F_151 )
return true ;
if ( V_217 == F_154 )
return true ;
if ( V_217 == F_117 )
return true ;
if ( V_217 == F_126 )
return true ;
if ( V_217 == F_130 )
return true ;
return false ;
}
static unsigned short F_157 ( T_1 V_182 )
{
return V_182 & V_218 ? V_219 : V_220 ;
}
static T_1 F_158 ( T_1 V_179 , T_1 V_180 , T_1 V_221 , T_1 V_182 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
struct V_222 * V_192 = (struct V_222 * ) ( long ) V_180 ;
const struct V_223 * V_224 = F_159 ( V_4 ) ;
T_3 V_225 [ sizeof( struct V_222 ) ] ;
void * V_226 = V_192 ;
int V_6 ;
if ( F_119 ( ! V_224 || ( V_182 & ~ ( V_218 ) ) ) ) {
V_6 = - V_93 ;
goto V_193;
}
if ( F_160 ( V_224 ) != F_157 ( V_182 ) ) {
V_6 = - V_227 ;
goto V_193;
}
if ( F_119 ( V_221 != sizeof( struct V_222 ) ) ) {
V_6 = - V_93 ;
switch ( V_221 ) {
case F_24 ( struct V_222 , V_228 ) :
case F_24 ( struct V_222 , V_229 ) :
goto V_230;
case F_24 ( struct V_222 , V_231 [ 1 ] ) :
if ( F_160 ( V_224 ) != V_220 )
goto V_193;
V_230:
V_192 = (struct V_222 * ) V_225 ;
break;
default:
goto V_193;
}
}
V_192 -> V_232 = F_161 ( V_224 -> V_233 . V_234 ) ;
V_192 -> V_235 = V_224 -> V_233 . V_236 ;
V_192 -> V_237 = V_224 -> V_233 . V_238 ;
if ( V_182 & V_218 ) {
memcpy ( V_192 -> V_231 , & V_224 -> V_233 . V_239 . V_240 . V_241 ,
sizeof( V_192 -> V_231 ) ) ;
V_192 -> V_228 = F_162 ( V_224 -> V_233 . V_242 ) ;
} else {
V_192 -> V_243 = F_162 ( V_224 -> V_233 . V_239 . V_244 . V_241 ) ;
}
if ( F_119 ( V_221 != sizeof( struct V_222 ) ) )
memcpy ( V_226 , V_192 , V_221 ) ;
return 0 ;
V_193:
memset ( V_226 , 0 , V_221 ) ;
return V_6 ;
}
static T_1 F_163 ( T_1 V_179 , T_1 V_180 , T_1 V_221 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
T_3 * V_192 = ( T_3 * ) ( long ) V_180 ;
const struct V_223 * V_224 = F_159 ( V_4 ) ;
int V_6 ;
if ( F_119 ( ! V_224 ||
! ( V_224 -> V_233 . V_245 & V_246 ) ) ) {
V_6 = - V_247 ;
goto V_193;
}
if ( F_119 ( V_221 < V_224 -> V_248 ) ) {
V_6 = - V_10 ;
goto V_193;
}
F_164 ( V_192 , V_224 ) ;
if ( V_221 > V_224 -> V_248 )
memset ( V_192 + V_224 -> V_248 , 0 , V_221 - V_224 -> V_248 ) ;
return V_224 -> V_248 ;
V_193:
memset ( V_192 , 0 , V_221 ) ;
return V_6 ;
}
static T_1 F_165 ( T_1 V_179 , T_1 V_180 , T_1 V_221 , T_1 V_182 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
struct V_222 * V_187 = (struct V_222 * ) ( long ) V_180 ;
struct V_249 * V_250 = F_118 ( V_251 ) ;
T_3 V_225 [ sizeof( struct V_222 ) ] ;
struct V_223 * V_224 ;
if ( F_119 ( V_182 & ~ ( V_218 | V_252 |
V_253 ) ) )
return - V_93 ;
if ( F_119 ( V_221 != sizeof( struct V_222 ) ) ) {
switch ( V_221 ) {
case F_24 ( struct V_222 , V_228 ) :
case F_24 ( struct V_222 , V_229 ) :
case F_24 ( struct V_222 , V_231 [ 1 ] ) :
memcpy ( V_225 , V_187 , V_221 ) ;
memset ( V_225 + V_221 , 0 , sizeof( V_225 ) - V_221 ) ;
V_187 = (struct V_222 * ) V_225 ;
break;
default:
return - V_93 ;
}
}
if ( F_119 ( ( ! ( V_182 & V_218 ) && V_187 -> V_228 ) ||
V_187 -> V_229 ) )
return - V_93 ;
F_166 ( V_4 ) ;
F_167 ( (struct V_254 * ) V_250 ) ;
F_168 ( V_4 , (struct V_254 * ) V_250 ) ;
V_224 = & V_250 -> V_239 . V_255 ;
V_224 -> V_256 = V_257 ;
V_224 -> V_233 . V_245 = V_258 | V_259 | V_260 ;
if ( V_182 & V_253 )
V_224 -> V_233 . V_245 |= V_261 ;
V_224 -> V_233 . V_234 = F_169 ( V_187 -> V_232 ) ;
V_224 -> V_233 . V_236 = V_187 -> V_235 ;
V_224 -> V_233 . V_238 = V_187 -> V_237 ;
if ( V_182 & V_218 ) {
V_224 -> V_256 |= V_262 ;
memcpy ( & V_224 -> V_233 . V_239 . V_240 . V_263 , V_187 -> V_231 ,
sizeof( V_187 -> V_231 ) ) ;
V_224 -> V_233 . V_242 = F_170 ( V_187 -> V_228 ) &
V_264 ;
} else {
V_224 -> V_233 . V_239 . V_244 . V_263 = F_170 ( V_187 -> V_243 ) ;
if ( V_182 & V_252 )
V_224 -> V_233 . V_245 &= ~ V_259 ;
}
return 0 ;
}
static T_1 F_171 ( T_1 V_179 , T_1 V_180 , T_1 V_221 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_179 ;
T_3 * V_187 = ( T_3 * ) ( long ) V_180 ;
struct V_223 * V_224 = F_159 ( V_4 ) ;
const struct V_249 * V_250 = F_118 ( V_251 ) ;
if ( F_119 ( V_224 != & V_250 -> V_239 . V_255 || ( V_221 & ( sizeof( T_2 ) - 1 ) ) ) )
return - V_93 ;
if ( F_119 ( V_221 > V_265 ) )
return - V_10 ;
F_172 ( V_224 , V_187 , V_221 ) ;
return 0 ;
}
static const struct V_266 *
F_173 ( enum V_267 V_268 )
{
if ( ! V_251 ) {
V_251 = F_174 ( V_265 ,
V_94 ) ;
if ( ! V_251 )
return NULL ;
}
switch ( V_268 ) {
case V_269 :
return & V_270 ;
case V_271 :
return & V_272 ;
default:
return NULL ;
}
}
static const struct V_266 *
F_175 ( enum V_267 V_273 )
{
switch ( V_273 ) {
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
if ( F_176 ( V_289 ) )
return F_177 () ;
default:
return NULL ;
}
}
static const struct V_266 *
F_178 ( enum V_267 V_273 )
{
switch ( V_273 ) {
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
case V_306 :
return & V_307 ;
case V_308 :
return & V_309 ;
case V_269 :
return F_173 ( V_273 ) ;
case V_310 :
return & V_311 ;
case V_271 :
return F_173 ( V_273 ) ;
case V_312 :
return & V_313 ;
case V_314 :
return & V_315 ;
case V_316 :
return F_179 () ;
default:
return F_175 ( V_273 ) ;
}
}
static bool F_180 ( int V_317 , int V_221 , enum V_318 type )
{
if ( V_317 < 0 || V_317 >= sizeof( struct V_319 ) )
return false ;
if ( V_317 % V_221 != 0 )
return false ;
if ( V_221 != sizeof( V_320 ) )
return false ;
return true ;
}
static bool F_181 ( int V_317 , int V_221 ,
enum V_318 type ,
enum V_321 * V_322 )
{
switch ( V_317 ) {
case F_24 ( struct V_319 , V_323 ) :
case F_24 ( struct V_319 , V_22 ) :
case F_24 ( struct V_319 , V_324 ) :
return false ;
}
if ( type == V_325 ) {
switch ( V_317 ) {
case F_24 ( struct V_319 , V_326 [ 0 ] ) ...
F_24 ( struct V_319 , V_326 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_180 ( V_317 , V_221 , type ) ;
}
static bool F_182 ( int V_317 , int V_221 ,
enum V_318 type ,
enum V_321 * V_322 )
{
if ( type == V_325 ) {
switch ( V_317 ) {
case F_24 ( struct V_319 , V_31 ) :
case F_24 ( struct V_319 , V_327 ) :
case F_24 ( struct V_319 , V_328 ) :
case F_24 ( struct V_319 , V_326 [ 0 ] ) ...
F_24 ( struct V_319 , V_326 [ 4 ] ) :
case F_24 ( struct V_319 , V_323 ) :
break;
default:
return false ;
}
}
switch ( V_317 ) {
case F_24 ( struct V_319 , V_22 ) :
* V_322 = V_329 ;
break;
case F_24 ( struct V_319 , V_324 ) :
* V_322 = V_330 ;
break;
}
return F_180 ( V_317 , V_221 , type ) ;
}
static T_2 F_183 ( enum V_318 type , int V_25 ,
int V_26 , int V_331 ,
struct V_27 * V_28 ,
struct V_145 * V_12 )
{
struct V_27 * V_29 = V_28 ;
switch ( V_331 ) {
case F_24 ( struct V_319 , V_21 ) :
F_21 ( F_22 ( struct V_3 , V_21 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_21 ) ) ;
break;
case F_24 ( struct V_319 , V_52 ) :
F_21 ( F_22 ( struct V_3 , V_52 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_52 ) ) ;
break;
case F_24 ( struct V_319 , V_66 ) :
F_21 ( F_22 ( struct V_3 , V_66 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_66 ) ) ;
break;
case F_24 ( struct V_319 , V_328 ) :
F_21 ( F_22 ( struct V_3 , V_328 ) != 4 ) ;
if ( type == V_325 )
* V_29 ++ = F_52 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_328 ) ) ;
else
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_328 ) ) ;
break;
case F_24 ( struct V_319 , V_332 ) :
F_21 ( F_22 ( struct V_3 , V_333 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_333 ) ) ;
break;
case F_24 ( struct V_319 , V_59 ) :
F_21 ( F_22 ( struct V_58 , V_59 ) != 4 ) ;
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_3 , V_60 ) ) ,
V_25 , V_26 ,
F_24 ( struct V_3 , V_60 ) ) ;
* V_29 ++ = F_31 ( V_115 , V_25 , 0 , 1 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_25 ,
F_24 ( struct V_58 , V_59 ) ) ;
break;
case F_24 ( struct V_319 , V_64 ) :
F_21 ( F_22 ( struct V_3 , V_64 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_64 ) ) ;
break;
case F_24 ( struct V_319 , V_31 ) :
F_21 ( F_22 ( struct V_3 , V_31 ) != 4 ) ;
if ( type == V_325 )
* V_29 ++ = F_52 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_31 ) ) ;
else
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_31 ) ) ;
break;
case F_24 ( struct V_319 , V_334 ) :
return F_20 ( V_33 , V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_319 , V_39 ) :
return F_20 ( V_38 , V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_319 , V_335 ) :
return F_20 ( V_42 ,
V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_319 , V_43 ) :
return F_20 ( V_41 ,
V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_319 , V_326 [ 0 ] ) ...
F_24 ( struct V_319 , V_326 [ 4 ] ) :
F_21 ( F_22 ( struct V_336 , V_22 ) < 20 ) ;
V_12 -> V_337 = 1 ;
V_331 -= F_24 ( struct V_319 , V_326 [ 0 ] ) ;
V_331 += F_24 ( struct V_3 , V_326 ) ;
V_331 += F_24 ( struct V_336 , V_22 ) ;
if ( type == V_325 )
* V_29 ++ = F_52 ( V_32 , V_25 , V_26 , V_331 ) ;
else
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 , V_331 ) ;
break;
case F_24 ( struct V_319 , V_323 ) :
V_331 -= F_24 ( struct V_319 , V_323 ) ;
V_331 += F_24 ( struct V_3 , V_326 ) ;
V_331 += F_24 ( struct V_336 , V_323 ) ;
if ( type == V_325 )
* V_29 ++ = F_52 ( V_40 , V_25 , V_26 , V_331 ) ;
else
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 , V_331 ) ;
break;
case F_24 ( struct V_319 , V_22 ) :
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_3 , V_22 ) ) ,
V_25 , V_26 ,
F_24 ( struct V_3 , V_22 ) ) ;
break;
case F_24 ( struct V_319 , V_324 ) :
V_331 -= F_24 ( struct V_319 , V_324 ) ;
V_331 += F_24 ( struct V_3 , V_326 ) ;
V_331 += F_24 ( struct V_338 , V_324 ) ;
* V_29 ++ = F_23 ( F_30 ( sizeof( void * ) ) ,
V_25 , V_26 , V_331 ) ;
break;
case F_24 ( struct V_319 , V_327 ) :
#ifdef F_184
F_21 ( F_22 ( struct V_3 , V_327 ) != 2 ) ;
if ( type == V_325 )
* V_29 ++ = F_52 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_327 ) ) ;
else
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_327 ) ) ;
break;
#else
if ( type == V_325 )
* V_29 ++ = F_33 ( V_25 , V_25 ) ;
else
* V_29 ++ = F_185 ( V_25 , 0 ) ;
break;
#endif
}
return V_29 - V_28 ;
}
static int T_9 F_186 ( void )
{
F_187 ( & V_339 ) ;
F_187 ( & V_340 ) ;
F_187 ( & V_341 ) ;
return 0 ;
}
int F_188 ( struct V_1 * V_2 )
{
int V_139 = - V_247 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_175 ) )
return - V_13 ;
V_8 = F_97 ( V_2 -> V_7 ,
F_98 ( V_2 ) ) ;
if ( V_8 ) {
F_189 ( V_2 -> V_7 , NULL ) ;
F_74 ( V_2 , V_8 ) ;
V_139 = 0 ;
}
return V_139 ;
}
int F_190 ( struct V_1 * V_2 , struct V_45 T_10 * V_342 ,
unsigned int V_21 )
{
struct V_149 * V_147 ;
struct V_7 * V_8 ;
int V_139 = 0 ;
F_191 ( V_2 ) ;
V_8 = F_97 ( V_2 -> V_7 ,
F_98 ( V_2 ) ) ;
if ( ! V_8 )
goto V_343;
V_139 = - V_344 ;
V_147 = V_8 -> V_12 -> V_151 ;
if ( ! V_147 )
goto V_343;
V_139 = V_147 -> V_21 ;
if ( ! V_21 )
goto V_343;
V_139 = - V_93 ;
if ( V_21 < V_147 -> V_21 )
goto V_343;
V_139 = - V_171 ;
if ( F_192 ( V_342 , V_147 -> V_8 , F_61 ( V_147 ) ) )
goto V_343;
V_139 = V_147 -> V_21 ;
V_343:
F_193 ( V_2 ) ;
return V_139 ;
}
