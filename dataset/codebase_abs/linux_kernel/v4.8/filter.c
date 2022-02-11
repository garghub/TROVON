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
static bool F_58 ( const struct V_45 * V_8 ,
unsigned int V_135 )
{
if ( V_8 == NULL )
return false ;
if ( V_135 == 0 || V_135 > V_92 )
return false ;
return true ;
}
static int F_59 ( const struct V_45 * V_8 ,
unsigned int V_135 )
{
bool V_142 ;
int V_138 ;
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
if ( F_60 ( V_143 ) & V_144 )
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
static int F_61 ( struct V_145 * V_46 ,
const struct V_146 * V_147 )
{
unsigned int V_148 = F_62 ( V_147 ) ;
struct V_149 * V_150 ;
V_46 -> V_151 = F_63 ( sizeof( * V_150 ) , V_94 ) ;
if ( ! V_46 -> V_151 )
return - V_10 ;
V_150 = V_46 -> V_151 ;
V_150 -> V_21 = V_147 -> V_21 ;
V_150 -> V_8 = F_64 ( V_46 -> V_152 , V_148 ,
V_94 | V_95 ) ;
if ( ! V_150 -> V_8 ) {
F_53 ( V_46 -> V_151 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_65 ( struct V_145 * V_46 )
{
struct V_149 * V_147 = V_46 -> V_151 ;
if ( V_147 ) {
F_53 ( V_147 -> V_8 ) ;
F_53 ( V_147 ) ;
}
}
static void F_66 ( struct V_145 * V_12 )
{
if ( V_12 -> type == V_153 ) {
F_67 ( V_12 ) ;
} else {
F_65 ( V_12 ) ;
F_68 ( V_12 ) ;
}
}
static void F_69 ( struct V_7 * V_46 )
{
F_66 ( V_46 -> V_12 ) ;
F_53 ( V_46 ) ;
}
static void F_70 ( struct V_154 * V_155 )
{
struct V_7 * V_46 = F_71 ( V_155 , struct V_7 , V_155 ) ;
F_69 ( V_46 ) ;
}
static void F_72 ( struct V_7 * V_46 )
{
if ( F_73 ( & V_46 -> V_156 ) )
F_74 ( & V_46 -> V_155 , F_70 ) ;
}
void F_75 ( struct V_1 * V_2 , struct V_7 * V_46 )
{
T_2 V_157 = F_76 ( V_46 -> V_12 -> V_21 ) ;
F_77 ( V_157 , & V_2 -> V_158 ) ;
F_72 ( V_46 ) ;
}
bool F_78 ( struct V_1 * V_2 , struct V_7 * V_46 )
{
T_2 V_157 = F_76 ( V_46 -> V_12 -> V_21 ) ;
if ( V_157 <= V_159 &&
F_79 ( & V_2 -> V_158 ) + V_157 < V_159 ) {
F_80 ( & V_46 -> V_156 ) ;
F_81 ( V_157 , & V_2 -> V_158 ) ;
return true ;
}
return false ;
}
static struct V_145 * F_82 ( struct V_145 * V_46 )
{
struct V_45 * V_160 ;
struct V_145 * V_161 ;
int V_6 , V_80 , V_162 = V_46 -> V_21 ;
F_21 ( sizeof( struct V_45 ) !=
sizeof( struct V_27 ) ) ;
V_160 = F_64 ( V_46 -> V_152 , V_162 * sizeof( struct V_45 ) ,
V_94 | V_95 ) ;
if ( ! V_160 ) {
V_6 = - V_10 ;
goto V_163;
}
V_6 = F_39 ( V_160 , V_162 , NULL , & V_80 ) ;
if ( V_6 )
goto V_164;
V_161 = V_46 ;
V_46 = F_83 ( V_161 , F_76 ( V_80 ) , 0 ) ;
if ( ! V_46 ) {
V_46 = V_161 ;
V_6 = - V_10 ;
goto V_164;
}
V_46 -> V_21 = V_80 ;
V_6 = F_39 ( V_160 , V_162 , V_46 -> V_165 , & V_80 ) ;
if ( V_6 )
goto V_164;
V_46 = F_84 ( V_46 , & V_6 ) ;
F_53 ( V_160 ) ;
return V_46 ;
V_164:
F_53 ( V_160 ) ;
V_163:
F_66 ( V_46 ) ;
return F_85 ( V_6 ) ;
}
static struct V_145 * F_86 ( struct V_145 * V_46 ,
T_5 V_166 )
{
int V_6 ;
V_46 -> V_167 = NULL ;
V_46 -> V_168 = 0 ;
V_6 = F_59 ( V_46 -> V_152 , V_46 -> V_21 ) ;
if ( V_6 ) {
F_66 ( V_46 ) ;
return F_85 ( V_6 ) ;
}
if ( V_166 ) {
V_6 = V_166 ( V_46 -> V_152 , V_46 -> V_21 ) ;
if ( V_6 ) {
F_66 ( V_46 ) ;
return F_85 ( V_6 ) ;
}
}
F_87 ( V_46 ) ;
if ( ! V_46 -> V_168 )
V_46 = F_82 ( V_46 ) ;
return V_46 ;
}
int F_88 ( struct V_145 * * V_169 , struct V_149 * V_147 )
{
unsigned int V_148 = F_62 ( V_147 ) ;
struct V_145 * V_46 ;
if ( ! F_58 ( V_147 -> V_8 , V_147 -> V_21 ) )
return - V_93 ;
V_46 = F_89 ( F_76 ( V_147 -> V_21 ) , 0 ) ;
if ( ! V_46 )
return - V_10 ;
memcpy ( V_46 -> V_152 , V_147 -> V_8 , V_148 ) ;
V_46 -> V_21 = V_147 -> V_21 ;
V_46 -> V_151 = NULL ;
V_46 = F_86 ( V_46 , NULL ) ;
if ( F_90 ( V_46 ) )
return F_91 ( V_46 ) ;
* V_169 = V_46 ;
return 0 ;
}
int F_92 ( struct V_145 * * V_169 , struct V_146 * V_147 ,
T_5 V_166 , bool V_170 )
{
unsigned int V_148 = F_62 ( V_147 ) ;
struct V_145 * V_46 ;
int V_6 ;
if ( ! F_58 ( V_147 -> V_8 , V_147 -> V_21 ) )
return - V_93 ;
V_46 = F_89 ( F_76 ( V_147 -> V_21 ) , 0 ) ;
if ( ! V_46 )
return - V_10 ;
if ( F_93 ( V_46 -> V_152 , V_147 -> V_8 , V_148 ) ) {
F_94 ( V_46 ) ;
return - V_171 ;
}
V_46 -> V_21 = V_147 -> V_21 ;
V_46 -> V_151 = NULL ;
if ( V_170 ) {
V_6 = F_61 ( V_46 , V_147 ) ;
if ( V_6 ) {
F_94 ( V_46 ) ;
return - V_10 ;
}
}
V_46 = F_86 ( V_46 , V_166 ) ;
if ( F_90 ( V_46 ) )
return F_91 ( V_46 ) ;
* V_169 = V_46 ;
return 0 ;
}
void F_95 ( struct V_145 * V_46 )
{
F_66 ( V_46 ) ;
}
static int F_96 ( struct V_145 * V_12 , struct V_1 * V_2 )
{
struct V_7 * V_46 , * V_161 ;
V_46 = F_63 ( sizeof( * V_46 ) , V_94 ) ;
if ( ! V_46 )
return - V_10 ;
V_46 -> V_12 = V_12 ;
F_97 ( & V_46 -> V_156 , 0 ) ;
if ( ! F_78 ( V_2 , V_46 ) ) {
F_53 ( V_46 ) ;
return - V_10 ;
}
V_161 = F_98 ( V_2 -> V_7 ,
F_99 ( V_2 ) ) ;
F_100 ( V_2 -> V_7 , V_46 ) ;
if ( V_161 )
F_75 ( V_2 , V_161 ) ;
return 0 ;
}
static int F_101 ( struct V_145 * V_12 , struct V_1 * V_2 )
{
struct V_145 * V_160 ;
int V_6 ;
if ( F_76 ( V_12 -> V_21 ) > V_159 )
return - V_10 ;
if ( F_102 ( V_2 ) && V_2 -> V_172 ) {
V_6 = F_103 ( V_2 ) ;
if ( V_6 )
return V_6 ;
} else if ( ! F_104 ( V_2 -> V_173 ) ) {
return - V_93 ;
}
V_160 = F_105 ( V_2 , V_12 ) ;
if ( V_160 )
F_95 ( V_160 ) ;
return 0 ;
}
static
struct V_145 * F_106 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
unsigned int V_148 = F_62 ( V_147 ) ;
struct V_145 * V_12 ;
int V_6 ;
if ( F_3 ( V_2 , V_174 ) )
return F_85 ( - V_13 ) ;
if ( ! F_58 ( V_147 -> V_8 , V_147 -> V_21 ) )
return F_85 ( - V_93 ) ;
V_12 = F_89 ( F_76 ( V_147 -> V_21 ) , 0 ) ;
if ( ! V_12 )
return F_85 ( - V_10 ) ;
if ( F_93 ( V_12 -> V_152 , V_147 -> V_8 , V_148 ) ) {
F_94 ( V_12 ) ;
return F_85 ( - V_171 ) ;
}
V_12 -> V_21 = V_147 -> V_21 ;
V_6 = F_61 ( V_12 , V_147 ) ;
if ( V_6 ) {
F_94 ( V_12 ) ;
return F_85 ( - V_10 ) ;
}
return F_86 ( V_12 , NULL ) ;
}
int F_107 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_106 ( V_147 , V_2 ) ;
int V_6 ;
if ( F_90 ( V_12 ) )
return F_91 ( V_12 ) ;
V_6 = F_96 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_66 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_108 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_106 ( V_147 , V_2 ) ;
int V_6 ;
if ( F_90 ( V_12 ) )
return F_91 ( V_12 ) ;
V_6 = F_101 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_66 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static struct V_145 * F_109 ( T_2 V_175 , struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_174 ) )
return F_85 ( - V_13 ) ;
return F_110 ( V_175 , V_153 ) ;
}
int F_111 ( T_2 V_175 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_109 ( V_175 , V_2 ) ;
int V_6 ;
if ( F_90 ( V_12 ) )
return F_91 ( V_12 ) ;
V_6 = F_96 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_67 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
int F_112 ( T_2 V_175 , struct V_1 * V_2 )
{
struct V_145 * V_12 = F_109 ( V_175 , V_2 ) ;
int V_6 ;
if ( F_90 ( V_12 ) )
return F_91 ( V_12 ) ;
V_6 = F_101 ( V_12 , V_2 ) ;
if ( V_6 < 0 ) {
F_67 ( V_12 ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_113 ( struct V_3 * V_4 ,
unsigned int V_176 )
{
int V_6 ;
V_6 = F_114 ( V_4 , V_176 ) ;
F_115 ( V_4 ) ;
return V_6 ;
}
static inline void F_116 ( struct V_3 * V_4 )
{
if ( F_117 ( V_4 ) )
F_118 ( V_4 , F_119 ( V_4 ) , V_4 -> V_177 ) ;
}
static inline void F_120 ( struct V_3 * V_4 )
{
if ( F_117 ( V_4 ) )
F_121 ( V_4 , F_119 ( V_4 ) , V_4 -> V_177 ) ;
}
static T_1 F_122 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_181 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
unsigned int V_182 = ( unsigned int ) V_179 ;
void * V_183 = ( void * ) ( long ) V_180 ;
unsigned int V_21 = ( unsigned int ) V_17 ;
void * V_184 ;
if ( F_123 ( V_181 & ~ ( V_185 | V_186 ) ) )
return - V_93 ;
if ( F_123 ( V_182 > 0xffff ) )
return - V_171 ;
if ( F_123 ( F_113 ( V_4 , V_182 + V_21 ) ) )
return - V_171 ;
V_184 = V_4 -> V_22 + V_182 ;
if ( V_181 & V_185 )
F_124 ( V_4 , V_184 , V_21 , V_182 ) ;
memcpy ( V_184 , V_183 , V_21 ) ;
if ( V_181 & V_185 )
F_125 ( V_4 , V_184 , V_21 , V_182 ) ;
if ( V_181 & V_186 )
F_126 ( V_4 ) ;
return 0 ;
}
static T_1 F_127 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) ( unsigned long ) V_178 ;
unsigned int V_182 = ( unsigned int ) V_179 ;
void * V_187 = ( void * ) ( unsigned long ) V_180 ;
unsigned int V_21 = ( unsigned int ) V_17 ;
void * V_184 ;
if ( F_123 ( V_182 > 0xffff ) )
goto V_188;
V_184 = F_128 ( V_4 , V_182 , V_21 , V_187 ) ;
if ( F_123 ( ! V_184 ) )
goto V_188;
if ( V_184 != V_187 )
memcpy ( V_187 , V_184 , V_21 ) ;
return 0 ;
V_188:
memset ( V_187 , 0 , V_21 ) ;
return - V_171 ;
}
static T_1 F_129 ( T_1 V_178 , T_1 V_179 , T_1 V_183 , T_1 V_187 , T_1 V_181 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
unsigned int V_182 = ( unsigned int ) V_179 ;
T_6 * V_184 ;
if ( F_123 ( V_181 & ~ ( V_189 ) ) )
return - V_93 ;
if ( F_123 ( V_182 > 0xffff || V_182 & 1 ) )
return - V_171 ;
if ( F_123 ( F_113 ( V_4 , V_182 + sizeof( * V_184 ) ) ) )
return - V_171 ;
V_184 = ( T_6 * ) ( V_4 -> V_22 + V_182 ) ;
switch ( V_181 & V_189 ) {
case 0 :
if ( F_123 ( V_183 != 0 ) )
return - V_93 ;
F_130 ( V_184 , V_187 ) ;
break;
case 2 :
F_131 ( V_184 , V_183 , V_187 ) ;
break;
case 4 :
F_132 ( V_184 , V_183 , V_187 ) ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static T_1 F_133 ( T_1 V_178 , T_1 V_179 , T_1 V_183 , T_1 V_187 , T_1 V_181 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
bool V_190 = V_181 & V_191 ;
bool V_192 = V_181 & V_193 ;
unsigned int V_182 = ( unsigned int ) V_179 ;
T_6 * V_184 ;
if ( F_123 ( V_181 & ~ ( V_193 | V_191 |
V_189 ) ) )
return - V_93 ;
if ( F_123 ( V_182 > 0xffff || V_182 & 1 ) )
return - V_171 ;
if ( F_123 ( F_113 ( V_4 , V_182 + sizeof( * V_184 ) ) ) )
return - V_171 ;
V_184 = ( T_6 * ) ( V_4 -> V_22 + V_182 ) ;
if ( V_192 && ! * V_184 )
return 0 ;
switch ( V_181 & V_189 ) {
case 0 :
if ( F_123 ( V_183 != 0 ) )
return - V_93 ;
F_134 ( V_184 , V_4 , V_187 , V_190 ) ;
break;
case 2 :
F_135 ( V_184 , V_4 , V_183 , V_187 , V_190 ) ;
break;
case 4 :
F_136 ( V_184 , V_4 , V_183 , V_187 , V_190 ) ;
break;
default:
return - V_93 ;
}
if ( V_192 && ! * V_184 )
* V_184 = V_194 ;
return 0 ;
}
static T_1 F_137 ( T_1 V_178 , T_1 V_195 , T_1 V_180 , T_1 V_196 , T_1 V_197 )
{
struct V_198 * V_199 = F_138 ( & V_200 ) ;
T_1 V_201 = V_195 + V_196 ;
T_7 * V_183 = ( T_7 * ) ( long ) V_178 ;
T_7 * V_187 = ( T_7 * ) ( long ) V_180 ;
int V_84 , V_202 = 0 ;
if ( F_123 ( ( ( V_195 | V_196 ) & ( sizeof( T_7 ) - 1 ) ) ||
V_201 > sizeof( V_199 -> V_203 ) ) )
return - V_93 ;
for ( V_84 = 0 ; V_84 < V_195 / sizeof( T_7 ) ; V_84 ++ , V_202 ++ )
V_199 -> V_203 [ V_202 ] = ~ V_183 [ V_84 ] ;
for ( V_84 = 0 ; V_84 < V_196 / sizeof( T_7 ) ; V_84 ++ , V_202 ++ )
V_199 -> V_203 [ V_202 ] = V_187 [ V_84 ] ;
return F_139 ( V_199 -> V_203 , V_201 , V_197 ) ;
}
static inline int F_140 ( struct V_58 * V_60 , struct V_3 * V_4 )
{
return F_141 ( V_60 , V_4 ) ;
}
static inline int F_142 ( struct V_58 * V_60 , struct V_3 * V_4 )
{
int V_139 ;
if ( F_123 ( F_143 ( V_204 ) > V_205 ) ) {
F_144 ( L_1 ) ;
F_145 ( V_4 ) ;
return - V_206 ;
}
V_4 -> V_60 = V_60 ;
F_146 ( V_204 ) ;
V_139 = F_147 ( V_4 ) ;
F_148 ( V_204 ) ;
return V_139 ;
}
static T_1 F_149 ( T_1 V_178 , T_1 V_59 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
struct V_58 * V_60 ;
if ( F_123 ( V_181 & ~ ( V_207 ) ) )
return - V_93 ;
V_60 = F_150 ( F_151 ( V_4 -> V_60 ) , V_59 ) ;
if ( F_123 ( ! V_60 ) )
return - V_93 ;
V_4 = F_152 ( V_4 , V_208 ) ;
if ( F_123 ( ! V_4 ) )
return - V_10 ;
F_116 ( V_4 ) ;
return V_181 & V_207 ?
F_140 ( V_60 , V_4 ) : F_142 ( V_60 , V_4 ) ;
}
static T_1 F_153 ( T_1 V_59 , T_1 V_181 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
struct V_209 * V_210 = F_138 ( & V_209 ) ;
if ( F_123 ( V_181 & ~ ( V_207 ) ) )
return V_211 ;
V_210 -> V_59 = V_59 ;
V_210 -> V_181 = V_181 ;
return V_212 ;
}
int F_154 ( struct V_3 * V_4 )
{
struct V_209 * V_210 = F_138 ( & V_209 ) ;
struct V_58 * V_60 ;
V_60 = F_150 ( F_151 ( V_4 -> V_60 ) , V_210 -> V_59 ) ;
V_210 -> V_59 = 0 ;
if ( F_123 ( ! V_60 ) ) {
F_145 ( V_4 ) ;
return - V_93 ;
}
F_116 ( V_4 ) ;
return V_210 -> V_181 & V_207 ?
F_140 ( V_60 , V_4 ) : F_142 ( V_60 , V_4 ) ;
}
static T_1 F_155 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
return F_156 ( (struct V_3 * ) ( unsigned long ) V_178 ) ;
}
static T_1 F_157 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
return F_158 ( (struct V_3 * ) ( unsigned long ) V_178 ) ;
}
static T_1 F_159 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
return F_160 ( (struct V_3 * ) ( unsigned long ) V_178 ) ;
}
static T_1 F_161 ( T_1 V_178 , T_1 V_179 , T_1 V_43 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
T_8 V_66 = ( V_213 T_8 ) V_179 ;
int V_139 ;
if ( F_123 ( V_66 != F_162 ( V_214 ) &&
V_66 != F_162 ( V_215 ) ) )
V_66 = F_162 ( V_214 ) ;
F_116 ( V_4 ) ;
V_139 = F_163 ( V_4 , V_66 , V_43 ) ;
F_120 ( V_4 ) ;
F_115 ( V_4 ) ;
return V_139 ;
}
static T_1 F_164 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
int V_139 ;
F_116 ( V_4 ) ;
V_139 = F_165 ( V_4 ) ;
F_120 ( V_4 ) ;
F_115 ( V_4 ) ;
return V_139 ;
}
static int F_166 ( struct V_3 * V_4 , T_2 V_216 , T_2 V_21 )
{
F_167 ( V_4 , V_21 ) ;
memmove ( V_4 -> V_22 , V_4 -> V_22 + V_21 , V_216 ) ;
memset ( V_4 -> V_22 + V_216 , 0 , V_21 ) ;
return 0 ;
}
static int F_168 ( struct V_3 * V_4 , T_2 V_216 , T_2 V_21 )
{
if ( F_123 ( ! F_169 ( V_4 , V_216 + V_21 ) ) )
return - V_10 ;
F_121 ( V_4 , V_4 -> V_22 + V_216 , V_21 ) ;
memmove ( V_4 -> V_22 + V_21 , V_4 -> V_22 , V_216 ) ;
F_170 ( V_4 , V_21 ) ;
return 0 ;
}
static int F_171 ( struct V_3 * V_4 , T_2 V_216 , T_2 V_21 )
{
bool V_217 = V_4 -> V_218 == V_4 -> V_219 ;
int V_139 ;
V_139 = F_166 ( V_4 , V_216 , V_21 ) ;
if ( F_172 ( ! V_139 ) ) {
V_4 -> V_220 -= V_21 ;
V_4 -> V_219 -= V_21 ;
if ( V_217 )
V_4 -> V_218 = V_4 -> V_219 ;
}
return V_139 ;
}
static int F_173 ( struct V_3 * V_4 , T_2 V_216 , T_2 V_21 )
{
bool V_217 = V_4 -> V_218 == V_4 -> V_219 ;
int V_139 ;
V_139 = F_168 ( V_4 , V_216 , V_21 ) ;
if ( F_172 ( ! V_139 ) ) {
V_4 -> V_220 += V_21 ;
V_4 -> V_219 += V_21 ;
if ( V_217 )
V_4 -> V_218 = V_4 -> V_219 ;
}
return V_139 ;
}
static int F_174 ( struct V_3 * V_4 )
{
const T_2 V_221 = sizeof( struct V_222 ) - sizeof( struct V_223 ) ;
T_2 V_216 = V_4 -> V_219 - V_4 -> V_220 ;
int V_139 ;
V_139 = F_175 ( V_4 , V_221 ) ;
if ( F_123 ( V_139 < 0 ) )
return V_139 ;
V_139 = F_171 ( V_4 , V_216 , V_221 ) ;
if ( F_123 ( V_139 < 0 ) )
return V_139 ;
if ( F_176 ( V_4 ) ) {
if ( F_177 ( V_4 ) -> V_224 & V_225 ) {
F_177 ( V_4 ) -> V_224 &= ~ V_225 ;
F_177 ( V_4 ) -> V_224 |= V_226 ;
}
F_177 ( V_4 ) -> V_227 -= V_221 ;
F_177 ( V_4 ) -> V_224 |= V_228 ;
F_177 ( V_4 ) -> V_229 = 0 ;
}
V_4 -> V_52 = F_162 ( V_230 ) ;
F_126 ( V_4 ) ;
return 0 ;
}
static int F_178 ( struct V_3 * V_4 )
{
const T_2 V_221 = sizeof( struct V_222 ) - sizeof( struct V_223 ) ;
T_2 V_216 = V_4 -> V_219 - V_4 -> V_220 ;
int V_139 ;
V_139 = F_179 ( V_4 , V_208 ) ;
if ( F_123 ( V_139 < 0 ) )
return V_139 ;
V_139 = F_173 ( V_4 , V_216 , V_221 ) ;
if ( F_123 ( V_139 < 0 ) )
return V_139 ;
if ( F_176 ( V_4 ) ) {
if ( F_177 ( V_4 ) -> V_224 & V_226 ) {
F_177 ( V_4 ) -> V_224 &= ~ V_226 ;
F_177 ( V_4 ) -> V_224 |= V_225 ;
}
F_177 ( V_4 ) -> V_227 += V_221 ;
F_177 ( V_4 ) -> V_224 |= V_228 ;
F_177 ( V_4 ) -> V_229 = 0 ;
}
V_4 -> V_52 = F_162 ( V_231 ) ;
F_126 ( V_4 ) ;
return 0 ;
}
static int F_180 ( struct V_3 * V_4 , T_8 V_232 )
{
T_8 V_233 = V_4 -> V_52 ;
if ( V_233 == F_162 ( V_231 ) &&
V_232 == F_162 ( V_230 ) )
return F_174 ( V_4 ) ;
if ( V_233 == F_162 ( V_230 ) &&
V_232 == F_162 ( V_231 ) )
return F_178 ( V_4 ) ;
return - V_234 ;
}
static T_1 F_181 ( T_1 V_178 , T_1 V_179 , T_1 V_181 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
T_8 V_235 = ( V_213 T_8 ) V_179 ;
int V_139 ;
if ( F_123 ( V_181 ) )
return - V_93 ;
V_139 = F_180 ( V_4 , V_235 ) ;
F_115 ( V_4 ) ;
return V_139 ;
}
static T_1 F_182 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
T_2 V_236 = V_179 ;
if ( F_123 ( V_4 -> V_236 > V_237 ||
V_236 > V_237 ) )
return - V_93 ;
V_4 -> V_236 = V_236 ;
return 0 ;
}
bool F_183 ( void * V_238 )
{
if ( V_238 == F_161 )
return true ;
if ( V_238 == F_164 )
return true ;
if ( V_238 == F_122 )
return true ;
if ( V_238 == F_181 )
return true ;
if ( V_238 == F_129 )
return true ;
if ( V_238 == F_133 )
return true ;
return false ;
}
static unsigned long F_184 ( void * V_239 , const void * V_4 ,
unsigned long V_216 , unsigned long V_21 )
{
void * V_184 = F_128 ( V_4 , V_216 , V_21 , V_239 ) ;
if ( F_123 ( ! V_184 ) )
return V_21 ;
if ( V_184 != V_239 )
memcpy ( V_239 , V_184 , V_21 ) ;
return 0 ;
}
static T_1 F_185 ( T_1 V_178 , T_1 V_179 , T_1 V_181 , T_1 V_17 ,
T_1 V_240 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
struct V_241 * V_242 = (struct V_241 * ) ( long ) V_179 ;
T_1 V_243 = ( V_181 & V_244 ) >> 32 ;
void * V_245 = ( void * ) ( long ) V_17 ;
if ( F_123 ( V_181 & ~ ( V_244 | V_246 ) ) )
return - V_93 ;
if ( F_123 ( V_243 > V_4 -> V_21 ) )
return - V_171 ;
return F_186 ( V_242 , V_181 , V_245 , V_240 , V_4 , V_243 ,
F_184 ) ;
}
static unsigned short F_187 ( T_1 V_181 )
{
return V_181 & V_247 ? V_248 : V_249 ;
}
static T_1 F_188 ( T_1 V_178 , T_1 V_179 , T_1 V_250 , T_1 V_181 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
struct V_251 * V_187 = (struct V_251 * ) ( long ) V_179 ;
const struct V_252 * V_253 = F_189 ( V_4 ) ;
T_3 V_254 [ sizeof( struct V_251 ) ] ;
void * V_255 = V_187 ;
int V_6 ;
if ( F_123 ( ! V_253 || ( V_181 & ~ ( V_247 ) ) ) ) {
V_6 = - V_93 ;
goto V_188;
}
if ( F_190 ( V_253 ) != F_187 ( V_181 ) ) {
V_6 = - V_256 ;
goto V_188;
}
if ( F_123 ( V_250 != sizeof( struct V_251 ) ) ) {
V_6 = - V_93 ;
switch ( V_250 ) {
case F_24 ( struct V_251 , V_257 ) :
case F_24 ( struct V_251 , V_258 ) :
goto V_259;
case F_24 ( struct V_251 , V_260 [ 1 ] ) :
if ( F_190 ( V_253 ) != V_249 )
goto V_188;
V_259:
V_187 = (struct V_251 * ) V_254 ;
break;
default:
goto V_188;
}
}
V_187 -> V_261 = F_191 ( V_253 -> V_262 . V_263 ) ;
V_187 -> V_264 = V_253 -> V_262 . V_265 ;
V_187 -> V_266 = V_253 -> V_262 . V_267 ;
if ( V_181 & V_247 ) {
memcpy ( V_187 -> V_260 , & V_253 -> V_262 . V_268 . V_269 . V_270 ,
sizeof( V_187 -> V_260 ) ) ;
V_187 -> V_257 = F_192 ( V_253 -> V_262 . V_271 ) ;
} else {
V_187 -> V_272 = F_192 ( V_253 -> V_262 . V_268 . V_273 . V_270 ) ;
}
if ( F_123 ( V_250 != sizeof( struct V_251 ) ) )
memcpy ( V_255 , V_187 , V_250 ) ;
return 0 ;
V_188:
memset ( V_255 , 0 , V_250 ) ;
return V_6 ;
}
static T_1 F_193 ( T_1 V_178 , T_1 V_179 , T_1 V_250 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
T_3 * V_187 = ( T_3 * ) ( long ) V_179 ;
const struct V_252 * V_253 = F_189 ( V_4 ) ;
int V_6 ;
if ( F_123 ( ! V_253 ||
! ( V_253 -> V_262 . V_274 & V_275 ) ) ) {
V_6 = - V_276 ;
goto V_188;
}
if ( F_123 ( V_250 < V_253 -> V_277 ) ) {
V_6 = - V_10 ;
goto V_188;
}
F_194 ( V_187 , V_253 ) ;
if ( V_250 > V_253 -> V_277 )
memset ( V_187 + V_253 -> V_277 , 0 , V_250 - V_253 -> V_277 ) ;
return V_253 -> V_277 ;
V_188:
memset ( V_187 , 0 , V_250 ) ;
return V_6 ;
}
static T_1 F_195 ( T_1 V_178 , T_1 V_179 , T_1 V_250 , T_1 V_181 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
struct V_251 * V_183 = (struct V_251 * ) ( long ) V_179 ;
struct V_278 * V_279 = F_138 ( V_280 ) ;
T_3 V_254 [ sizeof( struct V_251 ) ] ;
struct V_252 * V_253 ;
if ( F_123 ( V_181 & ~ ( V_247 | V_281 |
V_282 ) ) )
return - V_93 ;
if ( F_123 ( V_250 != sizeof( struct V_251 ) ) ) {
switch ( V_250 ) {
case F_24 ( struct V_251 , V_257 ) :
case F_24 ( struct V_251 , V_258 ) :
case F_24 ( struct V_251 , V_260 [ 1 ] ) :
memcpy ( V_254 , V_183 , V_250 ) ;
memset ( V_254 + V_250 , 0 , sizeof( V_254 ) - V_250 ) ;
V_183 = (struct V_251 * ) V_254 ;
break;
default:
return - V_93 ;
}
}
if ( F_123 ( ( ! ( V_181 & V_247 ) && V_183 -> V_257 ) ||
V_183 -> V_258 ) )
return - V_93 ;
F_196 ( V_4 ) ;
F_197 ( (struct V_283 * ) V_279 ) ;
F_198 ( V_4 , (struct V_283 * ) V_279 ) ;
V_253 = & V_279 -> V_268 . V_284 ;
V_253 -> V_285 = V_286 ;
V_253 -> V_262 . V_274 = V_287 | V_288 | V_289 ;
if ( V_181 & V_282 )
V_253 -> V_262 . V_274 |= V_290 ;
V_253 -> V_262 . V_263 = F_199 ( V_183 -> V_261 ) ;
V_253 -> V_262 . V_265 = V_183 -> V_264 ;
V_253 -> V_262 . V_267 = V_183 -> V_266 ;
if ( V_181 & V_247 ) {
V_253 -> V_285 |= V_291 ;
memcpy ( & V_253 -> V_262 . V_268 . V_269 . V_292 , V_183 -> V_260 ,
sizeof( V_183 -> V_260 ) ) ;
V_253 -> V_262 . V_271 = F_200 ( V_183 -> V_257 ) &
V_293 ;
} else {
V_253 -> V_262 . V_268 . V_273 . V_292 = F_200 ( V_183 -> V_272 ) ;
if ( V_181 & V_281 )
V_253 -> V_262 . V_274 &= ~ V_288 ;
}
return 0 ;
}
static T_1 F_201 ( T_1 V_178 , T_1 V_179 , T_1 V_250 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
T_3 * V_183 = ( T_3 * ) ( long ) V_179 ;
struct V_252 * V_253 = F_189 ( V_4 ) ;
const struct V_278 * V_279 = F_138 ( V_280 ) ;
if ( F_123 ( V_253 != & V_279 -> V_268 . V_284 || ( V_250 & ( sizeof( T_2 ) - 1 ) ) ) )
return - V_93 ;
if ( F_123 ( V_250 > V_294 ) )
return - V_10 ;
F_202 ( V_253 , V_183 , V_250 ) ;
return 0 ;
}
static const struct V_295 *
F_203 ( enum V_296 V_297 )
{
if ( ! V_280 ) {
V_280 = F_204 ( V_294 ,
V_94 ) ;
if ( ! V_280 )
return NULL ;
}
switch ( V_297 ) {
case V_298 :
return & V_299 ;
case V_300 :
return & V_301 ;
default:
return NULL ;
}
}
static T_1 F_205 ( T_1 V_178 , T_1 V_179 , T_1 V_180 , T_1 V_17 , T_1 V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_178 ;
struct V_241 * V_242 = (struct V_241 * ) ( long ) V_179 ;
struct V_302 * V_303 = F_71 ( V_242 , struct V_302 , V_242 ) ;
struct V_304 * V_305 ;
struct V_1 * V_2 ;
T_2 V_84 = ( T_2 ) V_180 ;
V_2 = V_4 -> V_2 ;
if ( ! V_2 || ! F_206 ( V_2 ) )
return - V_276 ;
if ( F_123 ( V_84 >= V_303 -> V_242 . V_306 ) )
return - V_307 ;
V_305 = F_207 ( V_303 -> V_308 [ V_84 ] ) ;
if ( F_123 ( ! V_305 ) )
return - V_309 ;
return F_208 ( F_209 ( & V_2 -> V_310 ) , V_305 ) ;
}
static const struct V_295 *
F_210 ( enum V_296 V_311 )
{
switch ( V_311 ) {
case V_312 :
return & V_313 ;
case V_314 :
return & V_315 ;
case V_316 :
return & V_317 ;
case V_318 :
return & V_319 ;
case V_320 :
return & V_321 ;
case V_322 :
return & V_323 ;
case V_324 :
return & V_325 ;
case V_326 :
if ( F_211 ( V_327 ) )
return F_212 () ;
default:
return NULL ;
}
}
static const struct V_295 *
F_213 ( enum V_296 V_311 )
{
switch ( V_311 ) {
case V_328 :
return & V_329 ;
case V_330 :
return & V_331 ;
case V_332 :
return & V_333 ;
case V_334 :
return & V_335 ;
case V_336 :
return & V_337 ;
case V_338 :
return & V_339 ;
case V_340 :
return & V_341 ;
case V_342 :
return & V_343 ;
case V_344 :
return & V_345 ;
case V_346 :
return & V_347 ;
case V_348 :
return & V_349 ;
case V_350 :
return & V_351 ;
case V_298 :
return F_203 ( V_311 ) ;
case V_352 :
return & V_353 ;
case V_300 :
return F_203 ( V_311 ) ;
case V_354 :
return & V_355 ;
case V_356 :
return & V_357 ;
case V_358 :
return & V_359 ;
case V_360 :
return & V_361 ;
case V_320 :
return & V_362 ;
#ifdef F_214
case V_363 :
return & V_364 ;
#endif
default:
return F_210 ( V_311 ) ;
}
}
static const struct V_295 *
F_215 ( enum V_296 V_311 )
{
return F_210 ( V_311 ) ;
}
static bool F_216 ( int V_216 , int V_250 , enum V_365 type )
{
if ( V_216 < 0 || V_216 >= sizeof( struct V_366 ) )
return false ;
if ( V_216 % V_250 != 0 )
return false ;
if ( V_250 != sizeof( V_367 ) )
return false ;
return true ;
}
static bool F_217 ( int V_216 , int V_250 ,
enum V_365 type ,
enum V_368 * V_369 )
{
switch ( V_216 ) {
case F_24 ( struct V_366 , V_370 ) :
case F_24 ( struct V_366 , V_22 ) :
case F_24 ( struct V_366 , V_371 ) :
return false ;
}
if ( type == V_372 ) {
switch ( V_216 ) {
case F_24 ( struct V_366 , V_373 [ 0 ] ) ...
F_24 ( struct V_366 , V_373 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_216 ( V_216 , V_250 , type ) ;
}
static bool F_218 ( int V_216 , int V_250 ,
enum V_365 type ,
enum V_368 * V_369 )
{
if ( type == V_372 ) {
switch ( V_216 ) {
case F_24 ( struct V_366 , V_31 ) :
case F_24 ( struct V_366 , V_374 ) :
case F_24 ( struct V_366 , V_375 ) :
case F_24 ( struct V_366 , V_373 [ 0 ] ) ...
F_24 ( struct V_366 , V_373 [ 4 ] ) :
case F_24 ( struct V_366 , V_370 ) :
break;
default:
return false ;
}
}
switch ( V_216 ) {
case F_24 ( struct V_366 , V_22 ) :
* V_369 = V_376 ;
break;
case F_24 ( struct V_366 , V_371 ) :
* V_369 = V_377 ;
break;
}
return F_216 ( V_216 , V_250 , type ) ;
}
static bool F_219 ( int V_216 , int V_250 ,
enum V_365 type )
{
if ( V_216 < 0 || V_216 >= sizeof( struct V_378 ) )
return false ;
if ( V_216 % V_250 != 0 )
return false ;
if ( V_250 != 4 )
return false ;
return true ;
}
static bool F_220 ( int V_216 , int V_250 ,
enum V_365 type ,
enum V_368 * V_369 )
{
if ( type == V_372 )
return false ;
switch ( V_216 ) {
case F_24 ( struct V_378 , V_22 ) :
* V_369 = V_376 ;
break;
case F_24 ( struct V_378 , V_371 ) :
* V_369 = V_377 ;
break;
}
return F_219 ( V_216 , V_250 , type ) ;
}
void F_221 ( T_2 V_379 )
{
F_222 ( 1 , L_2 , V_379 ) ;
}
static T_2 F_223 ( enum V_365 type , int V_25 ,
int V_26 , int V_380 ,
struct V_27 * V_28 ,
struct V_145 * V_12 )
{
struct V_27 * V_29 = V_28 ;
switch ( V_380 ) {
case F_24 ( struct V_366 , V_21 ) :
F_21 ( F_22 ( struct V_3 , V_21 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_21 ) ) ;
break;
case F_24 ( struct V_366 , V_52 ) :
F_21 ( F_22 ( struct V_3 , V_52 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_52 ) ) ;
break;
case F_24 ( struct V_366 , V_66 ) :
F_21 ( F_22 ( struct V_3 , V_66 ) != 2 ) ;
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_66 ) ) ;
break;
case F_24 ( struct V_366 , V_375 ) :
F_21 ( F_22 ( struct V_3 , V_375 ) != 4 ) ;
if ( type == V_372 )
* V_29 ++ = F_52 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_375 ) ) ;
else
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_375 ) ) ;
break;
case F_24 ( struct V_366 , V_381 ) :
F_21 ( F_22 ( struct V_3 , V_382 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_382 ) ) ;
break;
case F_24 ( struct V_366 , V_59 ) :
F_21 ( F_22 ( struct V_58 , V_59 ) != 4 ) ;
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_3 , V_60 ) ) ,
V_25 , V_26 ,
F_24 ( struct V_3 , V_60 ) ) ;
* V_29 ++ = F_31 ( V_115 , V_25 , 0 , 1 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_25 ,
F_24 ( struct V_58 , V_59 ) ) ;
break;
case F_24 ( struct V_366 , V_64 ) :
F_21 ( F_22 ( struct V_3 , V_64 ) != 4 ) ;
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_64 ) ) ;
break;
case F_24 ( struct V_366 , V_31 ) :
F_21 ( F_22 ( struct V_3 , V_31 ) != 4 ) ;
if ( type == V_372 )
* V_29 ++ = F_52 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_31 ) ) ;
else
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 ,
F_24 ( struct V_3 , V_31 ) ) ;
break;
case F_24 ( struct V_366 , V_236 ) :
return F_20 ( V_33 , V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_366 , V_39 ) :
return F_20 ( V_38 , V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_366 , V_383 ) :
return F_20 ( V_42 ,
V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_366 , V_43 ) :
return F_20 ( V_41 ,
V_25 , V_26 , V_29 ) ;
case F_24 ( struct V_366 , V_373 [ 0 ] ) ...
F_24 ( struct V_366 , V_373 [ 4 ] ) :
F_21 ( F_22 ( struct V_384 , V_22 ) < 20 ) ;
V_12 -> V_385 = 1 ;
V_380 -= F_24 ( struct V_366 , V_373 [ 0 ] ) ;
V_380 += F_24 ( struct V_3 , V_373 ) ;
V_380 += F_24 ( struct V_384 , V_22 ) ;
if ( type == V_372 )
* V_29 ++ = F_52 ( V_32 , V_25 , V_26 , V_380 ) ;
else
* V_29 ++ = F_23 ( V_32 , V_25 , V_26 , V_380 ) ;
break;
case F_24 ( struct V_366 , V_370 ) :
V_380 -= F_24 ( struct V_366 , V_370 ) ;
V_380 += F_24 ( struct V_3 , V_373 ) ;
V_380 += F_24 ( struct V_384 , V_370 ) ;
if ( type == V_372 )
* V_29 ++ = F_52 ( V_40 , V_25 , V_26 , V_380 ) ;
else
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 , V_380 ) ;
break;
case F_24 ( struct V_366 , V_22 ) :
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_3 , V_22 ) ) ,
V_25 , V_26 ,
F_24 ( struct V_3 , V_22 ) ) ;
break;
case F_24 ( struct V_366 , V_371 ) :
V_380 -= F_24 ( struct V_366 , V_371 ) ;
V_380 += F_24 ( struct V_3 , V_373 ) ;
V_380 += F_24 ( struct V_386 , V_371 ) ;
* V_29 ++ = F_23 ( F_30 ( sizeof( void * ) ) ,
V_25 , V_26 , V_380 ) ;
break;
case F_24 ( struct V_366 , V_374 ) :
#ifdef F_224
F_21 ( F_22 ( struct V_3 , V_374 ) != 2 ) ;
if ( type == V_372 )
* V_29 ++ = F_52 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_374 ) ) ;
else
* V_29 ++ = F_23 ( V_40 , V_25 , V_26 ,
F_24 ( struct V_3 , V_374 ) ) ;
break;
#else
if ( type == V_372 )
* V_29 ++ = F_33 ( V_25 , V_25 ) ;
else
* V_29 ++ = F_225 ( V_25 , 0 ) ;
break;
#endif
}
return V_29 - V_28 ;
}
static T_2 F_226 ( enum V_365 type , int V_25 ,
int V_26 , int V_380 ,
struct V_27 * V_28 ,
struct V_145 * V_12 )
{
struct V_27 * V_29 = V_28 ;
switch ( V_380 ) {
case F_24 ( struct V_378 , V_22 ) :
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_387 , V_22 ) ) ,
V_25 , V_26 ,
F_24 ( struct V_387 , V_22 ) ) ;
break;
case F_24 ( struct V_378 , V_371 ) :
* V_29 ++ = F_23 ( F_30 ( F_22 ( struct V_387 , V_371 ) ) ,
V_25 , V_26 ,
F_24 ( struct V_387 , V_371 ) ) ;
break;
}
return V_29 - V_28 ;
}
static int T_9 F_227 ( void )
{
F_228 ( & V_388 ) ;
F_228 ( & V_389 ) ;
F_228 ( & V_390 ) ;
F_228 ( & V_391 ) ;
return 0 ;
}
int F_229 ( struct V_1 * V_2 )
{
int V_139 = - V_276 ;
struct V_7 * V_8 ;
if ( F_3 ( V_2 , V_174 ) )
return - V_13 ;
V_8 = F_98 ( V_2 -> V_7 ,
F_99 ( V_2 ) ) ;
if ( V_8 ) {
F_230 ( V_2 -> V_7 , NULL ) ;
F_75 ( V_2 , V_8 ) ;
V_139 = 0 ;
}
return V_139 ;
}
int F_231 ( struct V_1 * V_2 , struct V_45 T_10 * V_392 ,
unsigned int V_21 )
{
struct V_149 * V_147 ;
struct V_7 * V_8 ;
int V_139 = 0 ;
F_232 ( V_2 ) ;
V_8 = F_98 ( V_2 -> V_7 ,
F_99 ( V_2 ) ) ;
if ( ! V_8 )
goto V_393;
V_139 = - V_394 ;
V_147 = V_8 -> V_12 -> V_151 ;
if ( ! V_147 )
goto V_393;
V_139 = V_147 -> V_21 ;
if ( ! V_21 )
goto V_393;
V_139 = - V_93 ;
if ( V_21 < V_147 -> V_21 )
goto V_393;
V_139 = - V_171 ;
if ( F_233 ( V_392 , V_147 -> V_8 , F_62 ( V_147 ) ) )
goto V_393;
V_139 = V_147 -> V_21 ;
V_393:
F_234 ( V_2 ) ;
return V_139 ;
}
