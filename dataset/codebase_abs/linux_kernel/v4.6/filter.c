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
unsigned int V_9 = F_7 ( V_6 -> V_10 , V_4 ) ;
V_5 = V_9 ? F_8 ( V_4 , V_9 ) : - V_11 ;
}
F_9 () ;
return V_5 ;
}
static T_1 F_10 ( T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 , T_1 V_16 )
{
return F_11 ( (struct V_3 * ) ( unsigned long ) V_12 ) ;
}
static T_1 F_12 ( T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_12 ;
struct V_17 * V_18 ;
if ( F_13 ( V_4 ) )
return 0 ;
if ( V_4 -> V_19 < sizeof( struct V_17 ) )
return 0 ;
if ( V_13 > V_4 -> V_19 - sizeof( struct V_17 ) )
return 0 ;
V_18 = F_14 ( (struct V_17 * ) & V_4 -> V_20 [ V_13 ] , V_4 -> V_19 - V_13 , V_14 ) ;
if ( V_18 )
return ( void * ) V_18 - ( void * ) V_4 -> V_20 ;
return 0 ;
}
static T_1 F_15 ( T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_12 ;
struct V_17 * V_18 ;
if ( F_13 ( V_4 ) )
return 0 ;
if ( V_4 -> V_19 < sizeof( struct V_17 ) )
return 0 ;
if ( V_13 > V_4 -> V_19 - sizeof( struct V_17 ) )
return 0 ;
V_18 = (struct V_17 * ) & V_4 -> V_20 [ V_13 ] ;
if ( V_18 -> V_21 > V_4 -> V_19 - V_13 )
return 0 ;
V_18 = F_16 ( V_18 , V_14 ) ;
if ( V_18 )
return ( void * ) V_18 - ( void * ) V_4 -> V_20 ;
return 0 ;
}
static T_1 F_17 ( T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 , T_1 V_16 )
{
return F_18 () ;
}
static T_2 F_19 ( int V_22 , int V_23 , int V_24 ,
struct V_25 * V_26 )
{
struct V_25 * V_27 = V_26 ;
switch ( V_22 ) {
case V_28 :
F_20 ( F_21 ( struct V_3 , V_29 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
break;
case V_31 :
* V_27 ++ = F_22 ( V_32 , V_23 , V_24 , F_24 () ) ;
* V_27 ++ = F_25 ( V_33 , V_23 , V_34 ) ;
#ifdef F_26
* V_27 ++ = F_25 ( V_35 , V_23 , 5 ) ;
#endif
break;
case V_36 :
F_20 ( F_21 ( struct V_3 , V_37 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_37 ) ) ;
break;
case V_39 :
case V_40 :
F_20 ( F_21 ( struct V_3 , V_41 ) != 2 ) ;
F_20 ( V_42 != 0x1000 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_41 ) ) ;
if ( V_22 == V_39 ) {
* V_27 ++ = F_25 ( V_33 , V_23 ,
~ V_42 ) ;
} else {
* V_27 ++ = F_25 ( V_35 , V_23 , 12 ) ;
* V_27 ++ = F_25 ( V_33 , V_23 , 1 ) ;
}
break;
}
return V_27 - V_26 ;
}
static bool F_27 ( struct V_43 * V_44 ,
struct V_25 * * V_45 )
{
struct V_25 * V_27 = * V_45 ;
T_2 V_46 ;
switch ( V_44 -> V_47 ) {
case V_48 + V_49 :
F_20 ( F_21 ( struct V_3 , V_50 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_51 , V_52 ,
F_23 ( struct V_3 , V_50 ) ) ;
* V_27 = F_28 ( V_53 , V_51 , 16 ) ;
break;
case V_48 + V_31 :
V_46 = F_19 ( V_31 , V_51 , V_52 , V_27 ) ;
V_27 += V_46 - 1 ;
break;
case V_48 + V_54 :
case V_48 + V_55 :
F_20 ( F_21 ( struct V_56 , V_57 ) != 4 ) ;
F_20 ( F_21 ( struct V_56 , type ) != 2 ) ;
F_20 ( F_29 ( F_21 ( struct V_3 , V_58 ) ) < 0 ) ;
* V_27 ++ = F_22 ( F_29 ( F_21 ( struct V_3 , V_58 ) ) ,
V_59 , V_52 ,
F_23 ( struct V_3 , V_58 ) ) ;
* V_27 ++ = F_30 ( V_60 , V_59 , 0 , 1 ) ;
* V_27 ++ = F_31 () ;
if ( V_44 -> V_47 == V_48 + V_54 )
* V_27 = F_22 ( V_30 , V_51 , V_59 ,
F_23 ( struct V_56 , V_57 ) ) ;
else
* V_27 = F_22 ( V_38 , V_51 , V_59 ,
F_23 ( struct V_56 , type ) ) ;
break;
case V_48 + V_28 :
V_46 = F_19 ( V_28 , V_51 , V_52 , V_27 ) ;
V_27 += V_46 - 1 ;
break;
case V_48 + V_61 :
F_20 ( F_21 ( struct V_3 , V_62 ) != 4 ) ;
* V_27 = F_22 ( V_30 , V_51 , V_52 ,
F_23 ( struct V_3 , V_62 ) ) ;
break;
case V_48 + V_36 :
V_46 = F_19 ( V_36 , V_51 , V_52 , V_27 ) ;
V_27 += V_46 - 1 ;
break;
case V_48 + V_39 :
V_46 = F_19 ( V_39 ,
V_51 , V_52 , V_27 ) ;
V_27 += V_46 - 1 ;
break;
case V_48 + V_40 :
V_46 = F_19 ( V_40 ,
V_51 , V_52 , V_27 ) ;
V_27 += V_46 - 1 ;
break;
case V_48 + V_63 :
F_20 ( F_21 ( struct V_3 , V_64 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_51 , V_52 ,
F_23 ( struct V_3 , V_64 ) ) ;
* V_27 = F_28 ( V_53 , V_51 , 16 ) ;
break;
case V_48 + V_65 :
case V_48 + V_66 :
case V_48 + V_67 :
case V_48 + V_68 :
case V_48 + V_69 :
* V_27 ++ = F_32 ( V_70 , V_52 ) ;
* V_27 ++ = F_32 ( V_71 , V_51 ) ;
* V_27 ++ = F_32 ( V_72 , V_73 ) ;
switch ( V_44 -> V_47 ) {
case V_48 + V_65 :
* V_27 = F_33 ( F_10 ) ;
break;
case V_48 + V_66 :
* V_27 = F_33 ( F_12 ) ;
break;
case V_48 + V_67 :
* V_27 = F_33 ( F_15 ) ;
break;
case V_48 + V_68 :
* V_27 = F_33 ( F_17 ) ;
break;
case V_48 + V_69 :
* V_27 = F_33 ( V_74 ) ;
F_34 () ;
break;
}
break;
case V_48 + V_75 :
* V_27 = F_35 ( V_76 , V_51 , V_73 ) ;
break;
default:
F_36 ( F_37 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_45 = V_27 ;
return true ;
}
static int F_38 ( struct V_43 * V_10 , int V_19 ,
struct V_25 * V_77 , int * V_78 )
{
int V_79 = 0 , V_80 = 0 , V_81 , V_82 ;
struct V_25 * V_83 ;
struct V_43 * V_44 ;
int * V_84 = NULL ;
T_3 V_85 ;
F_20 ( V_86 * sizeof( T_2 ) > V_87 ) ;
F_20 ( V_88 + 1 != V_89 ) ;
if ( V_19 <= 0 || V_19 > V_90 )
return - V_91 ;
if ( V_77 ) {
V_84 = F_39 ( V_19 , sizeof( * V_84 ) ,
V_92 | V_93 ) ;
if ( ! V_84 )
return - V_8 ;
}
V_94:
V_83 = V_77 ;
V_44 = V_10 ;
if ( V_83 ) {
* V_83 ++ = F_40 ( V_76 , V_51 , V_51 ) ;
* V_83 ++ = F_40 ( V_76 , V_73 , V_73 ) ;
* V_83 ++ = F_32 ( V_52 , V_70 ) ;
} else {
V_83 += 3 ;
}
for ( V_82 = 0 ; V_82 < V_19 ; V_44 ++ , V_82 ++ ) {
struct V_25 V_95 [ 6 ] = { } ;
struct V_25 * V_27 = V_95 ;
if ( V_84 )
V_84 [ V_82 ] = V_83 - V_77 ;
switch ( V_44 -> V_96 ) {
case V_97 | V_98 | V_99 :
case V_97 | V_98 | V_100 :
case V_97 | V_101 | V_99 :
case V_97 | V_101 | V_100 :
case V_97 | V_33 | V_99 :
case V_97 | V_33 | V_100 :
case V_97 | V_102 | V_99 :
case V_97 | V_102 | V_100 :
case V_97 | V_103 | V_99 :
case V_97 | V_103 | V_100 :
case V_97 | V_35 | V_99 :
case V_97 | V_35 | V_100 :
case V_97 | V_76 | V_99 :
case V_97 | V_76 | V_100 :
case V_97 | V_104 | V_99 :
case V_97 | V_104 | V_100 :
case V_97 | V_105 | V_99 :
case V_97 | V_105 | V_100 :
case V_97 | V_106 | V_99 :
case V_97 | V_106 | V_100 :
case V_97 | V_107 :
case V_108 | V_109 | V_30 :
case V_108 | V_109 | V_38 :
case V_108 | V_109 | V_32 :
case V_108 | V_110 | V_30 :
case V_108 | V_110 | V_38 :
case V_108 | V_110 | V_32 :
if ( F_41 ( V_44 -> V_96 ) == V_108 &&
F_42 ( V_44 -> V_96 ) == V_109 &&
F_27 ( V_44 , & V_27 ) )
break;
* V_27 = F_43 ( V_44 -> V_96 , V_51 , V_73 , 0 , V_44 -> V_47 ) ;
break;
#define F_44 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_111 | V_112 :
V_81 = V_82 + V_44 -> V_47 + 1 ;
V_27 -> V_96 = V_44 -> V_96 ;
F_44 ;
break;
case V_111 | V_113 | V_100 :
case V_111 | V_113 | V_99 :
case V_111 | V_114 | V_100 :
case V_111 | V_114 | V_99 :
case V_111 | V_115 | V_100 :
case V_111 | V_115 | V_99 :
case V_111 | V_116 | V_100 :
case V_111 | V_116 | V_99 :
if ( F_45 ( V_44 -> V_96 ) == V_100 && ( int ) V_44 -> V_47 < 0 ) {
* V_27 ++ = F_46 ( V_59 , V_44 -> V_47 ) ;
V_27 -> V_23 = V_51 ;
V_27 -> V_24 = V_59 ;
V_85 = V_99 ;
} else {
V_27 -> V_23 = V_51 ;
V_27 -> V_117 = V_44 -> V_47 ;
V_85 = F_45 ( V_44 -> V_96 ) ;
V_27 -> V_24 = V_85 == V_99 ? V_73 : 0 ;
}
if ( V_44 -> V_118 == 0 ) {
V_27 -> V_96 = V_111 | F_47 ( V_44 -> V_96 ) | V_85 ;
V_81 = V_82 + V_44 -> V_119 + 1 ;
F_44 ;
break;
}
if ( V_44 -> V_119 == 0 && F_47 ( V_44 -> V_96 ) == V_113 ) {
V_27 -> V_96 = V_111 | V_60 | V_85 ;
V_81 = V_82 + V_44 -> V_118 + 1 ;
F_44 ;
break;
}
V_81 = V_82 + V_44 -> V_119 + 1 ;
V_27 -> V_96 = V_111 | F_47 ( V_44 -> V_96 ) | V_85 ;
F_44 ;
V_27 ++ ;
V_27 -> V_96 = V_111 | V_112 ;
V_81 = V_82 + V_44 -> V_118 + 1 ;
F_44 ;
break;
case V_120 | V_121 | V_32 :
* V_27 ++ = F_32 ( V_59 , V_51 ) ;
* V_27 ++ = F_48 ( V_32 , V_44 -> V_47 ) ;
* V_27 ++ = F_25 ( V_33 , V_51 , 0xf ) ;
* V_27 ++ = F_25 ( V_103 , V_51 , 2 ) ;
* V_27 ++ = F_32 ( V_73 , V_51 ) ;
* V_27 = F_32 ( V_51 , V_59 ) ;
break;
case V_122 | V_123 :
case V_122 | V_100 :
if ( F_49 ( V_44 -> V_96 ) == V_100 )
* V_27 ++ = F_50 ( V_100 , V_124 ,
0 , V_44 -> V_47 ) ;
* V_27 = F_31 () ;
break;
case V_125 :
case V_126 :
* V_27 = F_51 ( V_30 , V_88 , F_41 ( V_44 -> V_96 ) ==
V_125 ? V_51 : V_73 ,
- ( V_86 - V_44 -> V_47 ) * 4 ) ;
break;
case V_108 | V_127 :
case V_120 | V_127 :
* V_27 = F_22 ( V_30 , F_41 ( V_44 -> V_96 ) == V_108 ?
V_51 : V_73 , V_88 ,
- ( V_86 - V_44 -> V_47 ) * 4 ) ;
break;
case V_108 | V_128 :
case V_120 | V_128 :
* V_27 = F_46 ( F_41 ( V_44 -> V_96 ) == V_108 ?
V_51 : V_73 , V_44 -> V_47 ) ;
break;
case V_129 | V_130 :
* V_27 = F_32 ( V_73 , V_51 ) ;
break;
case V_129 | V_131 :
* V_27 = F_32 ( V_51 , V_73 ) ;
break;
case V_108 | V_30 | V_132 :
case V_120 | V_30 | V_132 :
* V_27 = F_22 ( V_30 , F_41 ( V_44 -> V_96 ) == V_108 ?
V_51 : V_73 , V_52 ,
F_23 ( struct V_3 , V_19 ) ) ;
break;
case V_120 | V_109 | V_30 :
* V_27 = F_22 ( V_30 , V_51 , V_52 , V_44 -> V_47 ) ;
break;
default:
goto V_5;
}
V_27 ++ ;
if ( V_77 )
memcpy ( V_83 , V_95 ,
sizeof( * V_27 ) * ( V_27 - V_95 ) ) ;
V_83 += V_27 - V_95 ;
}
if ( ! V_77 ) {
* V_78 = V_83 - V_77 ;
return 0 ;
}
V_80 ++ ;
if ( V_79 != V_83 - V_77 ) {
V_79 = V_83 - V_77 ;
if ( V_80 > 2 )
goto V_5;
goto V_94;
}
F_52 ( V_84 ) ;
F_36 ( * V_78 != V_79 ) ;
return 0 ;
V_5:
F_52 ( V_84 ) ;
return - V_91 ;
}
static int F_53 ( const struct V_43 * V_6 , int V_133 )
{
T_4 * V_134 , V_135 = 0 ;
int V_136 , V_137 = 0 ;
F_20 ( V_86 > 16 ) ;
V_134 = F_54 ( V_133 , sizeof( * V_134 ) , V_92 ) ;
if ( ! V_134 )
return - V_8 ;
memset ( V_134 , 0xff , V_133 * sizeof( * V_134 ) ) ;
for ( V_136 = 0 ; V_136 < V_133 ; V_136 ++ ) {
V_135 &= V_134 [ V_136 ] ;
switch ( V_6 [ V_136 ] . V_96 ) {
case V_125 :
case V_126 :
V_135 |= ( 1 << V_6 [ V_136 ] . V_47 ) ;
break;
case V_108 | V_127 :
case V_120 | V_127 :
if ( ! ( V_135 & ( 1 << V_6 [ V_136 ] . V_47 ) ) ) {
V_137 = - V_91 ;
goto error;
}
break;
case V_111 | V_112 :
V_134 [ V_136 + 1 + V_6 [ V_136 ] . V_47 ] &= V_135 ;
V_135 = ~ 0 ;
break;
case V_111 | V_113 | V_100 :
case V_111 | V_113 | V_99 :
case V_111 | V_116 | V_100 :
case V_111 | V_116 | V_99 :
case V_111 | V_115 | V_100 :
case V_111 | V_115 | V_99 :
case V_111 | V_114 | V_100 :
case V_111 | V_114 | V_99 :
V_134 [ V_136 + 1 + V_6 [ V_136 ] . V_119 ] &= V_135 ;
V_134 [ V_136 + 1 + V_6 [ V_136 ] . V_118 ] &= V_135 ;
V_135 = ~ 0 ;
break;
}
}
error:
F_52 ( V_134 ) ;
return V_137 ;
}
static bool F_55 ( T_4 V_138 )
{
static const bool V_139 [] = {
[ V_97 | V_98 | V_100 ] = true ,
[ V_97 | V_98 | V_99 ] = true ,
[ V_97 | V_101 | V_100 ] = true ,
[ V_97 | V_101 | V_99 ] = true ,
[ V_97 | V_104 | V_100 ] = true ,
[ V_97 | V_104 | V_99 ] = true ,
[ V_97 | V_105 | V_100 ] = true ,
[ V_97 | V_105 | V_99 ] = true ,
[ V_97 | V_106 | V_100 ] = true ,
[ V_97 | V_106 | V_99 ] = true ,
[ V_97 | V_33 | V_100 ] = true ,
[ V_97 | V_33 | V_99 ] = true ,
[ V_97 | V_102 | V_100 ] = true ,
[ V_97 | V_102 | V_99 ] = true ,
[ V_97 | V_76 | V_100 ] = true ,
[ V_97 | V_76 | V_99 ] = true ,
[ V_97 | V_103 | V_100 ] = true ,
[ V_97 | V_103 | V_99 ] = true ,
[ V_97 | V_35 | V_100 ] = true ,
[ V_97 | V_35 | V_99 ] = true ,
[ V_97 | V_107 ] = true ,
[ V_108 | V_30 | V_109 ] = true ,
[ V_108 | V_38 | V_109 ] = true ,
[ V_108 | V_32 | V_109 ] = true ,
[ V_108 | V_30 | V_132 ] = true ,
[ V_108 | V_30 | V_110 ] = true ,
[ V_108 | V_38 | V_110 ] = true ,
[ V_108 | V_32 | V_110 ] = true ,
[ V_108 | V_128 ] = true ,
[ V_108 | V_127 ] = true ,
[ V_120 | V_30 | V_132 ] = true ,
[ V_120 | V_32 | V_121 ] = true ,
[ V_120 | V_128 ] = true ,
[ V_120 | V_127 ] = true ,
[ V_125 ] = true ,
[ V_126 ] = true ,
[ V_129 | V_130 ] = true ,
[ V_129 | V_131 ] = true ,
[ V_122 | V_100 ] = true ,
[ V_122 | V_123 ] = true ,
[ V_111 | V_112 ] = true ,
[ V_111 | V_113 | V_100 ] = true ,
[ V_111 | V_113 | V_99 ] = true ,
[ V_111 | V_116 | V_100 ] = true ,
[ V_111 | V_116 | V_99 ] = true ,
[ V_111 | V_115 | V_100 ] = true ,
[ V_111 | V_115 | V_99 ] = true ,
[ V_111 | V_114 | V_100 ] = true ,
[ V_111 | V_114 | V_99 ] = true ,
} ;
if ( V_138 >= F_56 ( V_139 ) )
return false ;
return V_139 [ V_138 ] ;
}
static int F_57 ( const struct V_43 * V_6 ,
unsigned int V_133 )
{
bool V_140 ;
int V_136 ;
if ( V_133 == 0 || V_133 > V_90 )
return - V_91 ;
for ( V_136 = 0 ; V_136 < V_133 ; V_136 ++ ) {
const struct V_43 * V_141 = & V_6 [ V_136 ] ;
if ( ! F_55 ( V_141 -> V_96 ) )
return - V_91 ;
switch ( V_141 -> V_96 ) {
case V_97 | V_105 | V_100 :
case V_97 | V_106 | V_100 :
if ( V_141 -> V_47 == 0 )
return - V_91 ;
break;
case V_97 | V_103 | V_100 :
case V_97 | V_35 | V_100 :
if ( V_141 -> V_47 >= 32 )
return - V_91 ;
break;
case V_108 | V_127 :
case V_120 | V_127 :
case V_125 :
case V_126 :
if ( V_141 -> V_47 >= V_86 )
return - V_91 ;
break;
case V_111 | V_112 :
if ( V_141 -> V_47 >= ( unsigned int ) ( V_133 - V_136 - 1 ) )
return - V_91 ;
break;
case V_111 | V_113 | V_100 :
case V_111 | V_113 | V_99 :
case V_111 | V_116 | V_100 :
case V_111 | V_116 | V_99 :
case V_111 | V_115 | V_100 :
case V_111 | V_115 | V_99 :
case V_111 | V_114 | V_100 :
case V_111 | V_114 | V_99 :
if ( V_136 + V_141 -> V_119 + 1 >= V_133 ||
V_136 + V_141 -> V_118 + 1 >= V_133 )
return - V_91 ;
break;
case V_108 | V_30 | V_109 :
case V_108 | V_38 | V_109 :
case V_108 | V_32 | V_109 :
V_140 = false ;
if ( F_58 ( V_141 ) & V_142 )
V_140 = true ;
if ( V_140 == false && V_141 -> V_47 >= V_48 )
return - V_91 ;
}
}
switch ( V_6 [ V_133 - 1 ] . V_96 ) {
case V_122 | V_100 :
case V_122 | V_123 :
return F_53 ( V_6 , V_133 ) ;
}
return - V_91 ;
}
static int F_59 ( struct V_143 * V_44 ,
const struct V_144 * V_145 )
{
unsigned int V_146 = F_60 ( V_145 ) ;
struct V_147 * V_148 ;
V_44 -> V_149 = F_61 ( sizeof( * V_148 ) , V_92 ) ;
if ( ! V_44 -> V_149 )
return - V_8 ;
V_148 = V_44 -> V_149 ;
V_148 -> V_19 = V_145 -> V_19 ;
V_148 -> V_6 = F_62 ( V_44 -> V_150 , V_146 ,
V_92 | V_93 ) ;
if ( ! V_148 -> V_6 ) {
F_52 ( V_44 -> V_149 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_63 ( struct V_143 * V_44 )
{
struct V_147 * V_145 = V_44 -> V_149 ;
if ( V_145 ) {
F_52 ( V_145 -> V_6 ) ;
F_52 ( V_145 ) ;
}
}
static void F_64 ( struct V_143 * V_10 )
{
if ( V_10 -> type == V_151 ) {
F_65 ( V_10 ) ;
} else {
F_63 ( V_10 ) ;
F_66 ( V_10 ) ;
}
}
static void F_67 ( struct F_1 * V_44 )
{
F_64 ( V_44 -> V_10 ) ;
F_52 ( V_44 ) ;
}
static void F_68 ( struct V_152 * V_153 )
{
struct F_1 * V_44 = F_69 ( V_153 , struct F_1 , V_153 ) ;
F_67 ( V_44 ) ;
}
static void F_70 ( struct F_1 * V_44 )
{
if ( F_71 ( & V_44 -> V_154 ) )
F_72 ( & V_44 -> V_153 , F_68 ) ;
}
void F_73 ( struct V_1 * V_2 , struct F_1 * V_44 )
{
T_2 V_155 = F_74 ( V_44 -> V_10 -> V_19 ) ;
F_75 ( V_155 , & V_2 -> V_156 ) ;
F_70 ( V_44 ) ;
}
bool F_76 ( struct V_1 * V_2 , struct F_1 * V_44 )
{
T_2 V_155 = F_74 ( V_44 -> V_10 -> V_19 ) ;
if ( V_155 <= V_157 &&
F_77 ( & V_2 -> V_156 ) + V_155 < V_157 ) {
F_78 ( & V_44 -> V_154 ) ;
F_79 ( V_155 , & V_2 -> V_156 ) ;
return true ;
}
return false ;
}
static struct V_143 * F_80 ( struct V_143 * V_44 )
{
struct V_43 * V_158 ;
struct V_143 * V_159 ;
int V_5 , V_78 , V_160 = V_44 -> V_19 ;
F_20 ( sizeof( struct V_43 ) !=
sizeof( struct V_25 ) ) ;
V_158 = F_62 ( V_44 -> V_150 , V_160 * sizeof( struct V_43 ) ,
V_92 | V_93 ) ;
if ( ! V_158 ) {
V_5 = - V_8 ;
goto V_161;
}
V_5 = F_38 ( V_158 , V_160 , NULL , & V_78 ) ;
if ( V_5 )
goto V_162;
V_159 = V_44 ;
V_44 = F_81 ( V_159 , F_74 ( V_78 ) , 0 ) ;
if ( ! V_44 ) {
V_44 = V_159 ;
V_5 = - V_8 ;
goto V_162;
}
V_44 -> V_19 = V_78 ;
V_5 = F_38 ( V_158 , V_160 , V_44 -> V_163 , & V_78 ) ;
if ( V_5 )
goto V_162;
F_82 ( V_44 ) ;
F_52 ( V_158 ) ;
return V_44 ;
V_162:
F_52 ( V_158 ) ;
V_161:
F_64 ( V_44 ) ;
return F_83 ( V_5 ) ;
}
static struct V_143 * F_84 ( struct V_143 * V_44 ,
T_5 V_164 )
{
int V_5 ;
V_44 -> V_165 = NULL ;
V_44 -> V_166 = 0 ;
V_5 = F_57 ( V_44 -> V_150 , V_44 -> V_19 ) ;
if ( V_5 ) {
F_64 ( V_44 ) ;
return F_83 ( V_5 ) ;
}
if ( V_164 ) {
V_5 = V_164 ( V_44 -> V_150 , V_44 -> V_19 ) ;
if ( V_5 ) {
F_64 ( V_44 ) ;
return F_83 ( V_5 ) ;
}
}
F_85 ( V_44 ) ;
if ( ! V_44 -> V_166 )
V_44 = F_80 ( V_44 ) ;
return V_44 ;
}
int F_86 ( struct V_143 * * V_167 , struct V_147 * V_145 )
{
unsigned int V_146 = F_60 ( V_145 ) ;
struct V_143 * V_44 ;
if ( V_145 -> V_6 == NULL )
return - V_91 ;
V_44 = F_87 ( F_74 ( V_145 -> V_19 ) , 0 ) ;
if ( ! V_44 )
return - V_8 ;
memcpy ( V_44 -> V_150 , V_145 -> V_6 , V_146 ) ;
V_44 -> V_19 = V_145 -> V_19 ;
V_44 -> V_149 = NULL ;
V_44 = F_84 ( V_44 , NULL ) ;
if ( F_88 ( V_44 ) )
return F_89 ( V_44 ) ;
* V_167 = V_44 ;
return 0 ;
}
int F_90 ( struct V_143 * * V_167 , struct V_144 * V_145 ,
T_5 V_164 , bool V_168 )
{
unsigned int V_146 = F_60 ( V_145 ) ;
struct V_143 * V_44 ;
int V_5 ;
if ( V_145 -> V_6 == NULL )
return - V_91 ;
V_44 = F_87 ( F_74 ( V_145 -> V_19 ) , 0 ) ;
if ( ! V_44 )
return - V_8 ;
if ( F_91 ( V_44 -> V_150 , V_145 -> V_6 , V_146 ) ) {
F_92 ( V_44 ) ;
return - V_169 ;
}
V_44 -> V_19 = V_145 -> V_19 ;
V_44 -> V_149 = NULL ;
if ( V_168 ) {
V_5 = F_59 ( V_44 , V_145 ) ;
if ( V_5 ) {
F_92 ( V_44 ) ;
return - V_8 ;
}
}
V_44 = F_84 ( V_44 , V_164 ) ;
if ( F_88 ( V_44 ) )
return F_89 ( V_44 ) ;
* V_167 = V_44 ;
return 0 ;
}
void F_93 ( struct V_143 * V_44 )
{
F_64 ( V_44 ) ;
}
static int F_94 ( struct V_143 * V_10 , struct V_1 * V_2 ,
bool V_170 )
{
struct F_1 * V_44 , * V_159 ;
V_44 = F_61 ( sizeof( * V_44 ) , V_92 ) ;
if ( ! V_44 )
return - V_8 ;
V_44 -> V_10 = V_10 ;
F_95 ( & V_44 -> V_154 , 0 ) ;
if ( ! F_76 ( V_2 , V_44 ) ) {
F_52 ( V_44 ) ;
return - V_8 ;
}
V_159 = F_96 ( V_2 -> F_1 , V_170 ) ;
F_97 ( V_2 -> F_1 , V_44 ) ;
if ( V_159 )
F_73 ( V_2 , V_159 ) ;
return 0 ;
}
static int F_98 ( struct V_143 * V_10 , struct V_1 * V_2 )
{
struct V_143 * V_158 ;
int V_5 ;
if ( F_74 ( V_10 -> V_19 ) > V_157 )
return - V_8 ;
if ( F_99 ( V_2 ) && V_2 -> V_171 ) {
V_5 = F_100 ( V_2 ) ;
if ( V_5 )
return V_5 ;
} else if ( ! F_101 ( V_2 -> V_172 ) ) {
return - V_91 ;
}
V_158 = F_102 ( V_2 , V_10 ) ;
if ( V_158 )
F_93 ( V_158 ) ;
return 0 ;
}
static
struct V_143 * F_103 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
unsigned int V_146 = F_60 ( V_145 ) ;
unsigned int V_173 = F_74 ( V_145 -> V_19 ) ;
struct V_143 * V_10 ;
int V_5 ;
if ( F_3 ( V_2 , V_174 ) )
return F_83 ( - V_11 ) ;
if ( V_145 -> V_6 == NULL )
return F_83 ( - V_91 ) ;
V_10 = F_87 ( V_173 , 0 ) ;
if ( ! V_10 )
return F_83 ( - V_8 ) ;
if ( F_91 ( V_10 -> V_150 , V_145 -> V_6 , V_146 ) ) {
F_92 ( V_10 ) ;
return F_83 ( - V_169 ) ;
}
V_10 -> V_19 = V_145 -> V_19 ;
V_5 = F_59 ( V_10 , V_145 ) ;
if ( V_5 ) {
F_92 ( V_10 ) ;
return F_83 ( - V_8 ) ;
}
return F_84 ( V_10 , NULL ) ;
}
int F_104 ( struct V_144 * V_145 , struct V_1 * V_2 ,
bool V_170 )
{
struct V_143 * V_10 = F_103 ( V_145 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_94 ( V_10 , V_2 , V_170 ) ;
if ( V_5 < 0 ) {
F_64 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
int F_105 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
return F_104 ( V_145 , V_2 , F_106 ( V_2 ) ) ;
}
int F_107 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_103 ( V_145 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_98 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_64 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
static struct V_143 * F_108 ( T_2 V_175 , struct V_1 * V_2 )
{
struct V_143 * V_10 ;
if ( F_3 ( V_2 , V_174 ) )
return F_83 ( - V_11 ) ;
V_10 = F_109 ( V_175 ) ;
if ( F_88 ( V_10 ) )
return V_10 ;
if ( V_10 -> type != V_151 ) {
F_65 ( V_10 ) ;
return F_83 ( - V_91 ) ;
}
return V_10 ;
}
int F_110 ( T_2 V_175 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_108 ( V_175 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_94 ( V_10 , V_2 , F_106 ( V_2 ) ) ;
if ( V_5 < 0 ) {
F_65 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
int F_111 ( T_2 V_175 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_108 ( V_175 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_98 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_65 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
static T_1 F_112 ( T_1 V_176 , T_1 V_177 , T_1 V_178 , T_1 V_15 , T_1 V_179 )
{
struct V_180 * V_181 = F_113 ( & V_182 ) ;
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
int V_183 = ( int ) V_177 ;
void * V_184 = ( void * ) ( long ) V_178 ;
unsigned int V_19 = ( unsigned int ) V_15 ;
void * V_185 ;
if ( F_114 ( V_179 & ~ ( V_186 | V_187 ) ) )
return - V_91 ;
if ( F_114 ( ( T_2 ) V_183 > 0xffff || V_19 > sizeof( V_181 -> V_188 ) ) )
return - V_169 ;
if ( F_114 ( F_115 ( V_4 , V_183 + V_19 ) ) )
return - V_169 ;
V_185 = F_116 ( V_4 , V_183 , V_19 , V_181 -> V_188 ) ;
if ( F_114 ( ! V_185 ) )
return - V_169 ;
if ( V_179 & V_186 )
F_117 ( V_4 , V_185 , V_19 ) ;
memcpy ( V_185 , V_184 , V_19 ) ;
if ( V_185 == V_181 -> V_188 )
F_118 ( V_4 , V_183 , V_185 , V_19 ) ;
if ( V_179 & V_186 )
F_119 ( V_4 , V_185 , V_19 ) ;
if ( V_179 & V_187 )
F_120 ( V_4 ) ;
return 0 ;
}
static T_1 F_121 ( T_1 V_176 , T_1 V_177 , T_1 V_178 , T_1 V_15 , T_1 V_16 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) ( unsigned long ) V_176 ;
int V_183 = ( int ) V_177 ;
void * V_189 = ( void * ) ( unsigned long ) V_178 ;
unsigned int V_19 = ( unsigned int ) V_15 ;
void * V_185 ;
if ( F_114 ( ( T_2 ) V_183 > 0xffff || V_19 > V_87 ) )
return - V_169 ;
V_185 = F_116 ( V_4 , V_183 , V_19 , V_189 ) ;
if ( F_114 ( ! V_185 ) )
return - V_169 ;
if ( V_185 != V_189 )
memcpy ( V_189 , V_185 , V_19 ) ;
return 0 ;
}
static T_1 F_122 ( T_1 V_176 , T_1 V_177 , T_1 V_184 , T_1 V_189 , T_1 V_179 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
int V_183 = ( int ) V_177 ;
T_6 V_190 , * V_185 ;
if ( F_114 ( V_179 & ~ ( V_191 ) ) )
return - V_91 ;
if ( F_114 ( ( T_2 ) V_183 > 0xffff ) )
return - V_169 ;
if ( F_114 ( F_115 ( V_4 , V_183 + sizeof( V_190 ) ) ) )
return - V_169 ;
V_185 = F_116 ( V_4 , V_183 , sizeof( V_190 ) , & V_190 ) ;
if ( F_114 ( ! V_185 ) )
return - V_169 ;
switch ( V_179 & V_191 ) {
case 0 :
if ( F_114 ( V_184 != 0 ) )
return - V_91 ;
F_123 ( V_185 , V_189 ) ;
break;
case 2 :
F_124 ( V_185 , V_184 , V_189 ) ;
break;
case 4 :
F_125 ( V_185 , V_184 , V_189 ) ;
break;
default:
return - V_91 ;
}
if ( V_185 == & V_190 )
F_118 ( V_4 , V_183 , V_185 , sizeof( V_190 ) ) ;
return 0 ;
}
static T_1 F_126 ( T_1 V_176 , T_1 V_177 , T_1 V_184 , T_1 V_189 , T_1 V_179 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
bool V_192 = V_179 & V_193 ;
bool V_194 = V_179 & V_195 ;
int V_183 = ( int ) V_177 ;
T_6 V_190 , * V_185 ;
if ( F_114 ( V_179 & ~ ( V_195 | V_193 |
V_191 ) ) )
return - V_91 ;
if ( F_114 ( ( T_2 ) V_183 > 0xffff ) )
return - V_169 ;
if ( F_114 ( F_115 ( V_4 , V_183 + sizeof( V_190 ) ) ) )
return - V_169 ;
V_185 = F_116 ( V_4 , V_183 , sizeof( V_190 ) , & V_190 ) ;
if ( F_114 ( ! V_185 ) )
return - V_169 ;
if ( V_194 && ! * V_185 )
return 0 ;
switch ( V_179 & V_191 ) {
case 0 :
if ( F_114 ( V_184 != 0 ) )
return - V_91 ;
F_127 ( V_185 , V_4 , V_189 , V_192 ) ;
break;
case 2 :
F_128 ( V_185 , V_4 , V_184 , V_189 , V_192 ) ;
break;
case 4 :
F_129 ( V_185 , V_4 , V_184 , V_189 , V_192 ) ;
break;
default:
return - V_91 ;
}
if ( V_194 && ! * V_185 )
* V_185 = V_196 ;
if ( V_185 == & V_190 )
F_118 ( V_4 , V_183 , V_185 , sizeof( V_190 ) ) ;
return 0 ;
}
static T_1 F_130 ( T_1 V_176 , T_1 V_197 , T_1 V_178 , T_1 V_198 , T_1 V_199 )
{
struct V_180 * V_181 = F_113 ( & V_182 ) ;
T_1 V_200 = V_197 + V_198 ;
T_7 * V_184 = ( T_7 * ) ( long ) V_176 ;
T_7 * V_189 = ( T_7 * ) ( long ) V_178 ;
int V_82 , V_201 = 0 ;
if ( F_114 ( ( ( V_197 | V_198 ) & ( sizeof( T_7 ) - 1 ) ) ||
V_200 > sizeof( V_181 -> V_202 ) ) )
return - V_91 ;
for ( V_82 = 0 ; V_82 < V_197 / sizeof( T_7 ) ; V_82 ++ , V_201 ++ )
V_181 -> V_202 [ V_201 ] = ~ V_184 [ V_82 ] ;
for ( V_82 = 0 ; V_82 < V_198 / sizeof( T_7 ) ; V_82 ++ , V_201 ++ )
V_181 -> V_202 [ V_201 ] = V_189 [ V_82 ] ;
return F_131 ( V_181 -> V_202 , V_200 , V_199 ) ;
}
static T_1 F_132 ( T_1 V_176 , T_1 V_57 , T_1 V_179 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 , * V_203 ;
struct V_56 * V_58 ;
if ( F_114 ( V_179 & ~ ( V_204 ) ) )
return - V_91 ;
V_58 = F_133 ( F_134 ( V_4 -> V_58 ) , V_57 ) ;
if ( F_114 ( ! V_58 ) )
return - V_91 ;
V_203 = F_135 ( V_4 , V_205 ) ;
if ( F_114 ( ! V_203 ) )
return - V_8 ;
if ( V_179 & V_204 ) {
if ( F_136 ( V_203 ) )
F_119 ( V_203 , F_137 ( V_203 ) ,
V_203 -> V_206 ) ;
return F_138 ( V_58 , V_203 ) ;
}
V_203 -> V_58 = V_58 ;
return F_139 ( V_203 ) ;
}
static T_1 F_140 ( T_1 V_57 , T_1 V_179 , T_1 V_178 , T_1 V_15 , T_1 V_16 )
{
struct V_207 * V_208 = F_113 ( & V_207 ) ;
if ( F_114 ( V_179 & ~ ( V_204 ) ) )
return V_209 ;
V_208 -> V_57 = V_57 ;
V_208 -> V_179 = V_179 ;
return V_210 ;
}
int F_141 ( struct V_3 * V_4 )
{
struct V_207 * V_208 = F_113 ( & V_207 ) ;
struct V_56 * V_58 ;
V_58 = F_133 ( F_134 ( V_4 -> V_58 ) , V_208 -> V_57 ) ;
V_208 -> V_57 = 0 ;
if ( F_114 ( ! V_58 ) ) {
F_142 ( V_4 ) ;
return - V_91 ;
}
if ( V_208 -> V_179 & V_204 ) {
if ( F_136 ( V_4 ) )
F_119 ( V_4 , F_137 ( V_4 ) ,
V_4 -> V_206 ) ;
return F_138 ( V_58 , V_4 ) ;
}
V_4 -> V_58 = V_58 ;
return F_139 ( V_4 ) ;
}
static T_1 F_143 ( T_1 V_176 , T_1 V_177 , T_1 V_178 , T_1 V_15 , T_1 V_16 )
{
return F_144 ( (struct V_3 * ) ( unsigned long ) V_176 ) ;
}
static T_1 F_145 ( T_1 V_176 , T_1 V_177 , T_1 V_178 , T_1 V_15 , T_1 V_16 )
{
return F_146 ( (struct V_3 * ) ( unsigned long ) V_176 ) ;
}
static T_1 F_147 ( T_1 V_176 , T_1 V_177 , T_1 V_41 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
T_8 V_64 = ( V_211 T_8 ) V_177 ;
if ( F_114 ( V_64 != F_148 ( V_212 ) &&
V_64 != F_148 ( V_213 ) ) )
V_64 = F_148 ( V_212 ) ;
return F_149 ( V_4 , V_64 , V_41 ) ;
}
static T_1 F_150 ( T_1 V_176 , T_1 V_177 , T_1 V_178 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
return F_151 ( V_4 ) ;
}
bool F_152 ( void * V_214 )
{
if ( V_214 == F_147 )
return true ;
if ( V_214 == F_150 )
return true ;
if ( V_214 == F_112 )
return true ;
if ( V_214 == F_122 )
return true ;
if ( V_214 == F_126 )
return true ;
return false ;
}
static unsigned short F_153 ( T_1 V_179 )
{
return V_179 & V_215 ? V_216 : V_217 ;
}
static T_1 F_154 ( T_1 V_176 , T_1 V_177 , T_1 V_218 , T_1 V_179 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
struct V_219 * V_189 = (struct V_219 * ) ( long ) V_177 ;
const struct V_220 * V_221 = F_155 ( V_4 ) ;
T_3 V_222 [ sizeof( struct V_219 ) ] ;
if ( F_114 ( ! V_221 || ( V_179 & ~ ( V_215 ) ) ) )
return - V_91 ;
if ( F_156 ( V_221 ) != F_153 ( V_179 ) )
return - V_223 ;
if ( F_114 ( V_218 != sizeof( struct V_219 ) ) ) {
switch ( V_218 ) {
case F_23 ( struct V_219 , V_224 ) :
case F_23 ( struct V_219 , V_225 ) :
goto V_226;
case F_23 ( struct V_219 , V_227 [ 1 ] ) :
if ( F_156 ( V_221 ) != V_217 )
return - V_91 ;
V_226:
V_189 = (struct V_219 * ) V_222 ;
break;
default:
return - V_91 ;
}
}
V_189 -> V_228 = F_157 ( V_221 -> V_229 . V_230 ) ;
V_189 -> V_231 = V_221 -> V_229 . V_232 ;
V_189 -> V_233 = V_221 -> V_229 . V_234 ;
if ( V_179 & V_215 ) {
memcpy ( V_189 -> V_227 , & V_221 -> V_229 . V_235 . V_236 . V_237 ,
sizeof( V_189 -> V_227 ) ) ;
V_189 -> V_224 = F_158 ( V_221 -> V_229 . V_238 ) ;
} else {
V_189 -> V_239 = F_158 ( V_221 -> V_229 . V_235 . V_240 . V_237 ) ;
}
if ( F_114 ( V_218 != sizeof( struct V_219 ) ) )
memcpy ( ( void * ) ( long ) V_177 , V_189 , V_218 ) ;
return 0 ;
}
static T_1 F_159 ( T_1 V_176 , T_1 V_177 , T_1 V_218 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
T_3 * V_189 = ( T_3 * ) ( long ) V_177 ;
const struct V_220 * V_221 = F_155 ( V_4 ) ;
if ( F_114 ( ! V_221 ||
! ( V_221 -> V_229 . V_241 & V_242 ) ) )
return - V_243 ;
if ( F_114 ( V_218 < V_221 -> V_244 ) )
return - V_8 ;
F_160 ( V_189 , V_221 ) ;
return V_221 -> V_244 ;
}
static T_1 F_161 ( T_1 V_176 , T_1 V_177 , T_1 V_218 , T_1 V_179 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
struct V_219 * V_184 = (struct V_219 * ) ( long ) V_177 ;
struct V_245 * V_246 = F_113 ( V_247 ) ;
T_3 V_222 [ sizeof( struct V_219 ) ] ;
struct V_220 * V_221 ;
if ( F_114 ( V_179 & ~ ( V_215 | V_248 |
V_249 ) ) )
return - V_91 ;
if ( F_114 ( V_218 != sizeof( struct V_219 ) ) ) {
switch ( V_218 ) {
case F_23 ( struct V_219 , V_224 ) :
case F_23 ( struct V_219 , V_225 ) :
case F_23 ( struct V_219 , V_227 [ 1 ] ) :
memcpy ( V_222 , V_184 , V_218 ) ;
memset ( V_222 + V_218 , 0 , sizeof( V_222 ) - V_218 ) ;
V_184 = (struct V_219 * ) V_222 ;
break;
default:
return - V_91 ;
}
}
if ( F_114 ( ( ! ( V_179 & V_215 ) && V_184 -> V_224 ) ||
V_184 -> V_225 ) )
return - V_91 ;
F_162 ( V_4 ) ;
F_163 ( (struct V_250 * ) V_246 ) ;
F_164 ( V_4 , (struct V_250 * ) V_246 ) ;
V_221 = & V_246 -> V_235 . V_251 ;
V_221 -> V_252 = V_253 ;
V_221 -> V_229 . V_241 = V_254 | V_255 | V_256 ;
if ( V_179 & V_249 )
V_221 -> V_229 . V_241 |= V_257 ;
V_221 -> V_229 . V_230 = F_165 ( V_184 -> V_228 ) ;
V_221 -> V_229 . V_232 = V_184 -> V_231 ;
V_221 -> V_229 . V_234 = V_184 -> V_233 ;
if ( V_179 & V_215 ) {
V_221 -> V_252 |= V_258 ;
memcpy ( & V_221 -> V_229 . V_235 . V_236 . V_259 , V_184 -> V_227 ,
sizeof( V_184 -> V_227 ) ) ;
V_221 -> V_229 . V_238 = F_166 ( V_184 -> V_224 ) &
V_260 ;
} else {
V_221 -> V_229 . V_235 . V_240 . V_259 = F_166 ( V_184 -> V_239 ) ;
if ( V_179 & V_248 )
V_221 -> V_229 . V_241 &= ~ V_255 ;
}
return 0 ;
}
static T_1 F_167 ( T_1 V_176 , T_1 V_177 , T_1 V_218 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_176 ;
T_3 * V_184 = ( T_3 * ) ( long ) V_177 ;
struct V_220 * V_221 = F_155 ( V_4 ) ;
const struct V_245 * V_246 = F_113 ( V_247 ) ;
if ( F_114 ( V_221 != & V_246 -> V_235 . V_251 || ( V_218 & ( sizeof( T_2 ) - 1 ) ) ) )
return - V_91 ;
if ( F_114 ( V_218 > V_261 ) )
return - V_8 ;
F_168 ( V_221 , V_184 , V_218 ) ;
return 0 ;
}
static const struct V_262 *
F_169 ( enum V_263 V_264 )
{
if ( ! V_247 ) {
V_247 = F_170 ( V_261 ,
V_92 ) ;
if ( ! V_247 )
return NULL ;
}
switch ( V_264 ) {
case V_265 :
return & V_266 ;
case V_267 :
return & V_268 ;
default:
return NULL ;
}
}
static const struct V_262 *
F_171 ( enum V_263 V_269 )
{
switch ( V_269 ) {
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
if ( F_172 ( V_285 ) )
return F_173 () ;
default:
return NULL ;
}
}
static const struct V_262 *
F_174 ( enum V_263 V_269 )
{
switch ( V_269 ) {
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
case V_265 :
return F_169 ( V_269 ) ;
case V_306 :
return & V_307 ;
case V_267 :
return F_169 ( V_269 ) ;
case V_308 :
return & V_309 ;
case V_310 :
return & V_311 ;
default:
return F_171 ( V_269 ) ;
}
}
static bool F_175 ( int V_312 , int V_218 , enum V_313 type )
{
if ( V_312 < 0 || V_312 >= sizeof( struct V_314 ) )
return false ;
if ( V_312 % V_218 != 0 )
return false ;
if ( V_218 != 4 )
return false ;
return true ;
}
static bool F_176 ( int V_312 , int V_218 ,
enum V_313 type )
{
if ( V_312 == F_23 ( struct V_314 , V_315 ) )
return false ;
if ( type == V_316 ) {
switch ( V_312 ) {
case F_23 ( struct V_314 , V_317 [ 0 ] ) ...
F_23 ( struct V_314 , V_317 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_175 ( V_312 , V_218 , type ) ;
}
static bool F_177 ( int V_312 , int V_218 ,
enum V_313 type )
{
if ( type == V_316 ) {
switch ( V_312 ) {
case F_23 ( struct V_314 , V_29 ) :
case F_23 ( struct V_314 , V_318 ) :
case F_23 ( struct V_314 , V_319 ) :
case F_23 ( struct V_314 , V_317 [ 0 ] ) ...
F_23 ( struct V_314 , V_317 [ 4 ] ) :
case F_23 ( struct V_314 , V_315 ) :
break;
default:
return false ;
}
}
return F_175 ( V_312 , V_218 , type ) ;
}
static T_2 F_178 ( enum V_313 type , int V_23 ,
int V_24 , int V_320 ,
struct V_25 * V_26 ,
struct V_143 * V_10 )
{
struct V_25 * V_27 = V_26 ;
switch ( V_320 ) {
case F_23 ( struct V_314 , V_19 ) :
F_20 ( F_21 ( struct V_3 , V_19 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_19 ) ) ;
break;
case F_23 ( struct V_314 , V_50 ) :
F_20 ( F_21 ( struct V_3 , V_50 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_50 ) ) ;
break;
case F_23 ( struct V_314 , V_64 ) :
F_20 ( F_21 ( struct V_3 , V_64 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_64 ) ) ;
break;
case F_23 ( struct V_314 , V_319 ) :
F_20 ( F_21 ( struct V_3 , V_319 ) != 4 ) ;
if ( type == V_316 )
* V_27 ++ = F_51 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_319 ) ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_319 ) ) ;
break;
case F_23 ( struct V_314 , V_321 ) :
F_20 ( F_21 ( struct V_3 , V_322 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_322 ) ) ;
break;
case F_23 ( struct V_314 , V_57 ) :
F_20 ( F_21 ( struct V_56 , V_57 ) != 4 ) ;
* V_27 ++ = F_22 ( F_29 ( F_21 ( struct V_3 , V_58 ) ) ,
V_23 , V_24 ,
F_23 ( struct V_3 , V_58 ) ) ;
* V_27 ++ = F_30 ( V_113 , V_23 , 0 , 1 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_23 ,
F_23 ( struct V_56 , V_57 ) ) ;
break;
case F_23 ( struct V_314 , V_62 ) :
F_20 ( F_21 ( struct V_3 , V_62 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_62 ) ) ;
break;
case F_23 ( struct V_314 , V_29 ) :
F_20 ( F_21 ( struct V_3 , V_29 ) != 4 ) ;
if ( type == V_316 )
* V_27 ++ = F_51 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
break;
case F_23 ( struct V_314 , V_323 ) :
return F_19 ( V_31 , V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_314 , V_37 ) :
return F_19 ( V_36 , V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_314 , V_324 ) :
return F_19 ( V_40 ,
V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_314 , V_41 ) :
return F_19 ( V_39 ,
V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_314 , V_317 [ 0 ] ) ...
F_23 ( struct V_314 , V_317 [ 4 ] ) :
F_20 ( F_21 ( struct V_325 , V_20 ) < 20 ) ;
V_10 -> V_326 = 1 ;
V_320 -= F_23 ( struct V_314 , V_317 [ 0 ] ) ;
V_320 += F_23 ( struct V_3 , V_317 ) ;
V_320 += F_23 ( struct V_325 , V_20 ) ;
if ( type == V_316 )
* V_27 ++ = F_51 ( V_30 , V_23 , V_24 , V_320 ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 , V_320 ) ;
break;
case F_23 ( struct V_314 , V_315 ) :
V_320 -= F_23 ( struct V_314 , V_315 ) ;
V_320 += F_23 ( struct V_3 , V_317 ) ;
V_320 += F_23 ( struct V_325 , V_315 ) ;
if ( type == V_316 )
* V_27 ++ = F_51 ( V_38 , V_23 , V_24 , V_320 ) ;
else
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 , V_320 ) ;
break;
case F_23 ( struct V_314 , V_318 ) :
#ifdef F_179
F_20 ( F_21 ( struct V_3 , V_318 ) != 2 ) ;
if ( type == V_316 )
* V_27 ++ = F_51 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_318 ) ) ;
else
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_318 ) ) ;
break;
#else
if ( type == V_316 )
* V_27 ++ = F_32 ( V_23 , V_23 ) ;
else
* V_27 ++ = F_180 ( V_23 , 0 ) ;
break;
#endif
}
return V_27 - V_26 ;
}
static int T_9 F_181 ( void )
{
F_182 ( & V_327 ) ;
F_182 ( & V_328 ) ;
F_182 ( & V_329 ) ;
return 0 ;
}
int F_183 ( struct V_1 * V_2 , bool V_170 )
{
int V_137 = - V_243 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_174 ) )
return - V_11 ;
V_6 = F_96 ( V_2 -> F_1 , V_170 ) ;
if ( V_6 ) {
F_184 ( V_2 -> F_1 , NULL ) ;
F_73 ( V_2 , V_6 ) ;
V_137 = 0 ;
}
return V_137 ;
}
int F_185 ( struct V_1 * V_2 )
{
return F_183 ( V_2 , F_106 ( V_2 ) ) ;
}
int F_186 ( struct V_1 * V_2 , struct V_43 T_10 * V_330 ,
unsigned int V_19 )
{
struct V_147 * V_145 ;
struct F_1 * V_6 ;
int V_137 = 0 ;
F_187 ( V_2 ) ;
V_6 = F_96 ( V_2 -> F_1 ,
F_106 ( V_2 ) ) ;
if ( ! V_6 )
goto V_331;
V_137 = - V_332 ;
V_145 = V_6 -> V_10 -> V_149 ;
if ( ! V_145 )
goto V_331;
V_137 = V_145 -> V_19 ;
if ( ! V_19 )
goto V_331;
V_137 = - V_91 ;
if ( V_19 < V_145 -> V_19 )
goto V_331;
V_137 = - V_169 ;
if ( F_188 ( V_330 , V_145 -> V_6 , F_60 ( V_145 ) ) )
goto V_331;
V_137 = V_145 -> V_19 ;
V_331:
F_189 ( V_2 ) ;
return V_137 ;
}
