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
if ( V_83 )
* V_83 = F_32 ( V_52 , V_70 ) ;
V_83 ++ ;
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
if ( F_40 ( V_44 -> V_96 ) == V_108 &&
F_41 ( V_44 -> V_96 ) == V_109 &&
F_27 ( V_44 , & V_27 ) )
break;
* V_27 = F_42 ( V_44 -> V_96 , V_51 , V_73 , 0 , V_44 -> V_47 ) ;
break;
#define F_43 \
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
F_43 ;
break;
case V_111 | V_113 | V_100 :
case V_111 | V_113 | V_99 :
case V_111 | V_114 | V_100 :
case V_111 | V_114 | V_99 :
case V_111 | V_115 | V_100 :
case V_111 | V_115 | V_99 :
case V_111 | V_116 | V_100 :
case V_111 | V_116 | V_99 :
if ( F_44 ( V_44 -> V_96 ) == V_100 && ( int ) V_44 -> V_47 < 0 ) {
* V_27 ++ = F_45 ( V_59 , V_44 -> V_47 ) ;
V_27 -> V_23 = V_51 ;
V_27 -> V_24 = V_59 ;
V_85 = V_99 ;
} else {
V_27 -> V_23 = V_51 ;
V_27 -> V_117 = V_44 -> V_47 ;
V_85 = F_44 ( V_44 -> V_96 ) ;
V_27 -> V_24 = V_85 == V_99 ? V_73 : 0 ;
}
if ( V_44 -> V_118 == 0 ) {
V_27 -> V_96 = V_111 | F_46 ( V_44 -> V_96 ) | V_85 ;
V_81 = V_82 + V_44 -> V_119 + 1 ;
F_43 ;
break;
}
if ( V_44 -> V_119 == 0 && F_46 ( V_44 -> V_96 ) == V_113 ) {
V_27 -> V_96 = V_111 | V_60 | V_85 ;
V_81 = V_82 + V_44 -> V_118 + 1 ;
F_43 ;
break;
}
V_81 = V_82 + V_44 -> V_119 + 1 ;
V_27 -> V_96 = V_111 | F_46 ( V_44 -> V_96 ) | V_85 ;
F_43 ;
V_27 ++ ;
V_27 -> V_96 = V_111 | V_112 ;
V_81 = V_82 + V_44 -> V_118 + 1 ;
F_43 ;
break;
case V_120 | V_121 | V_32 :
* V_27 ++ = F_32 ( V_59 , V_51 ) ;
* V_27 ++ = F_47 ( V_32 , V_44 -> V_47 ) ;
* V_27 ++ = F_25 ( V_33 , V_51 , 0xf ) ;
* V_27 ++ = F_25 ( V_103 , V_51 , 2 ) ;
* V_27 ++ = F_32 ( V_73 , V_51 ) ;
* V_27 = F_32 ( V_51 , V_59 ) ;
break;
case V_122 | V_123 :
case V_122 | V_100 :
* V_27 ++ = F_48 ( F_49 ( V_44 -> V_96 ) == V_100 ?
V_100 : V_99 , V_124 ,
V_51 , V_44 -> V_47 ) ;
* V_27 = F_31 () ;
break;
case V_125 :
case V_126 :
* V_27 = F_50 ( V_30 , V_88 , F_40 ( V_44 -> V_96 ) ==
V_125 ? V_51 : V_73 ,
- ( V_86 - V_44 -> V_47 ) * 4 ) ;
break;
case V_108 | V_127 :
case V_120 | V_127 :
* V_27 = F_22 ( V_30 , F_40 ( V_44 -> V_96 ) == V_108 ?
V_51 : V_73 , V_88 ,
- ( V_86 - V_44 -> V_47 ) * 4 ) ;
break;
case V_108 | V_128 :
case V_120 | V_128 :
* V_27 = F_45 ( F_40 ( V_44 -> V_96 ) == V_108 ?
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
* V_27 = F_22 ( V_30 , F_40 ( V_44 -> V_96 ) == V_108 ?
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
F_51 ( V_84 ) ;
F_36 ( * V_78 != V_79 ) ;
return 0 ;
V_5:
F_51 ( V_84 ) ;
return - V_91 ;
}
static int F_52 ( const struct V_43 * V_6 , int V_133 )
{
T_4 * V_134 , V_135 = 0 ;
int V_136 , V_137 = 0 ;
F_20 ( V_86 > 16 ) ;
V_134 = F_53 ( V_133 , sizeof( * V_134 ) , V_92 ) ;
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
F_51 ( V_134 ) ;
return V_137 ;
}
static bool F_54 ( T_4 V_138 )
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
if ( V_138 >= F_55 ( V_139 ) )
return false ;
return V_139 [ V_138 ] ;
}
static int F_56 ( const struct V_43 * V_6 ,
unsigned int V_133 )
{
bool V_140 ;
int V_136 ;
if ( V_133 == 0 || V_133 > V_90 )
return - V_91 ;
for ( V_136 = 0 ; V_136 < V_133 ; V_136 ++ ) {
const struct V_43 * V_141 = & V_6 [ V_136 ] ;
if ( ! F_54 ( V_141 -> V_96 ) )
return - V_91 ;
switch ( V_141 -> V_96 ) {
case V_97 | V_105 | V_100 :
case V_97 | V_106 | V_100 :
if ( V_141 -> V_47 == 0 )
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
if ( F_57 ( V_141 ) & V_142 )
V_140 = true ;
if ( V_140 == false && V_141 -> V_47 >= V_48 )
return - V_91 ;
}
}
switch ( V_6 [ V_133 - 1 ] . V_96 ) {
case V_122 | V_100 :
case V_122 | V_123 :
return F_52 ( V_6 , V_133 ) ;
}
return - V_91 ;
}
static int F_58 ( struct V_143 * V_44 ,
const struct V_144 * V_145 )
{
unsigned int V_146 = F_59 ( V_145 ) ;
struct V_147 * V_148 ;
V_44 -> V_149 = F_60 ( sizeof( * V_148 ) , V_92 ) ;
if ( ! V_44 -> V_149 )
return - V_8 ;
V_148 = V_44 -> V_149 ;
V_148 -> V_19 = V_145 -> V_19 ;
V_148 -> V_6 = F_61 ( V_44 -> V_150 , V_146 ,
V_92 | V_93 ) ;
if ( ! V_148 -> V_6 ) {
F_51 ( V_44 -> V_149 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_62 ( struct V_143 * V_44 )
{
struct V_147 * V_145 = V_44 -> V_149 ;
if ( V_145 ) {
F_51 ( V_145 -> V_6 ) ;
F_51 ( V_145 ) ;
}
}
static void F_63 ( struct V_143 * V_10 )
{
if ( V_10 -> type == V_151 ) {
F_64 ( V_10 ) ;
} else {
F_62 ( V_10 ) ;
F_65 ( V_10 ) ;
}
}
static void F_66 ( struct F_1 * V_44 )
{
F_63 ( V_44 -> V_10 ) ;
F_51 ( V_44 ) ;
}
static void F_67 ( struct V_152 * V_153 )
{
struct F_1 * V_44 = F_68 ( V_153 , struct F_1 , V_153 ) ;
F_66 ( V_44 ) ;
}
static void F_69 ( struct F_1 * V_44 )
{
if ( F_70 ( & V_44 -> V_154 ) )
F_71 ( & V_44 -> V_153 , F_67 ) ;
}
void F_72 ( struct V_1 * V_2 , struct F_1 * V_44 )
{
T_2 V_155 = F_73 ( V_44 -> V_10 -> V_19 ) ;
F_74 ( V_155 , & V_2 -> V_156 ) ;
F_69 ( V_44 ) ;
}
bool F_75 ( struct V_1 * V_2 , struct F_1 * V_44 )
{
T_2 V_155 = F_73 ( V_44 -> V_10 -> V_19 ) ;
if ( V_155 <= V_157 &&
F_76 ( & V_2 -> V_156 ) + V_155 < V_157 ) {
F_77 ( & V_44 -> V_154 ) ;
F_78 ( V_155 , & V_2 -> V_156 ) ;
return true ;
}
return false ;
}
static struct V_143 * F_79 ( struct V_143 * V_44 )
{
struct V_43 * V_158 ;
struct V_143 * V_159 ;
int V_5 , V_78 , V_160 = V_44 -> V_19 ;
F_20 ( sizeof( struct V_43 ) !=
sizeof( struct V_25 ) ) ;
V_158 = F_61 ( V_44 -> V_150 , V_160 * sizeof( struct V_43 ) ,
V_92 | V_93 ) ;
if ( ! V_158 ) {
V_5 = - V_8 ;
goto V_161;
}
V_5 = F_38 ( V_158 , V_160 , NULL , & V_78 ) ;
if ( V_5 )
goto V_162;
V_159 = V_44 ;
V_44 = F_80 ( V_159 , F_73 ( V_78 ) , 0 ) ;
if ( ! V_44 ) {
V_44 = V_159 ;
V_5 = - V_8 ;
goto V_162;
}
V_44 -> V_19 = V_78 ;
V_5 = F_38 ( V_158 , V_160 , V_44 -> V_163 , & V_78 ) ;
if ( V_5 )
goto V_162;
F_81 ( V_44 ) ;
F_51 ( V_158 ) ;
return V_44 ;
V_162:
F_51 ( V_158 ) ;
V_161:
F_63 ( V_44 ) ;
return F_82 ( V_5 ) ;
}
static struct V_143 * F_83 ( struct V_143 * V_44 ,
T_5 V_164 )
{
int V_5 ;
V_44 -> V_165 = NULL ;
V_44 -> V_166 = 0 ;
V_5 = F_56 ( V_44 -> V_150 , V_44 -> V_19 ) ;
if ( V_5 ) {
F_63 ( V_44 ) ;
return F_82 ( V_5 ) ;
}
if ( V_164 ) {
V_5 = V_164 ( V_44 -> V_150 , V_44 -> V_19 ) ;
if ( V_5 ) {
F_63 ( V_44 ) ;
return F_82 ( V_5 ) ;
}
}
F_84 ( V_44 ) ;
if ( ! V_44 -> V_166 )
V_44 = F_79 ( V_44 ) ;
return V_44 ;
}
int F_85 ( struct V_143 * * V_167 , struct V_147 * V_145 )
{
unsigned int V_146 = F_59 ( V_145 ) ;
struct V_143 * V_44 ;
if ( V_145 -> V_6 == NULL )
return - V_91 ;
V_44 = F_86 ( F_73 ( V_145 -> V_19 ) , 0 ) ;
if ( ! V_44 )
return - V_8 ;
memcpy ( V_44 -> V_150 , V_145 -> V_6 , V_146 ) ;
V_44 -> V_19 = V_145 -> V_19 ;
V_44 -> V_149 = NULL ;
V_44 = F_83 ( V_44 , NULL ) ;
if ( F_87 ( V_44 ) )
return F_88 ( V_44 ) ;
* V_167 = V_44 ;
return 0 ;
}
int F_89 ( struct V_143 * * V_167 , struct V_144 * V_145 ,
T_5 V_164 , bool V_168 )
{
unsigned int V_146 = F_59 ( V_145 ) ;
struct V_143 * V_44 ;
int V_5 ;
if ( V_145 -> V_6 == NULL )
return - V_91 ;
V_44 = F_86 ( F_73 ( V_145 -> V_19 ) , 0 ) ;
if ( ! V_44 )
return - V_8 ;
if ( F_90 ( V_44 -> V_150 , V_145 -> V_6 , V_146 ) ) {
F_91 ( V_44 ) ;
return - V_169 ;
}
V_44 -> V_19 = V_145 -> V_19 ;
V_44 -> V_149 = NULL ;
if ( V_168 ) {
V_5 = F_58 ( V_44 , V_145 ) ;
if ( V_5 ) {
F_91 ( V_44 ) ;
return - V_8 ;
}
}
V_44 = F_83 ( V_44 , V_164 ) ;
if ( F_87 ( V_44 ) )
return F_88 ( V_44 ) ;
* V_167 = V_44 ;
return 0 ;
}
void F_92 ( struct V_143 * V_44 )
{
F_63 ( V_44 ) ;
}
static int F_93 ( struct V_143 * V_10 , struct V_1 * V_2 )
{
struct F_1 * V_44 , * V_159 ;
V_44 = F_60 ( sizeof( * V_44 ) , V_92 ) ;
if ( ! V_44 )
return - V_8 ;
V_44 -> V_10 = V_10 ;
F_94 ( & V_44 -> V_154 , 0 ) ;
if ( ! F_75 ( V_2 , V_44 ) ) {
F_51 ( V_44 ) ;
return - V_8 ;
}
V_159 = F_95 ( V_2 -> F_1 ,
F_96 ( V_2 ) ) ;
F_97 ( V_2 -> F_1 , V_44 ) ;
if ( V_159 )
F_72 ( V_2 , V_159 ) ;
return 0 ;
}
int F_98 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
unsigned int V_146 = F_59 ( V_145 ) ;
unsigned int V_170 = F_73 ( V_145 -> V_19 ) ;
struct V_143 * V_10 ;
int V_5 ;
if ( F_3 ( V_2 , V_171 ) )
return - V_11 ;
if ( V_145 -> V_6 == NULL )
return - V_91 ;
V_10 = F_86 ( V_170 , 0 ) ;
if ( ! V_10 )
return - V_8 ;
if ( F_90 ( V_10 -> V_150 , V_145 -> V_6 , V_146 ) ) {
F_91 ( V_10 ) ;
return - V_169 ;
}
V_10 -> V_19 = V_145 -> V_19 ;
V_5 = F_58 ( V_10 , V_145 ) ;
if ( V_5 ) {
F_91 ( V_10 ) ;
return - V_8 ;
}
V_10 = F_83 ( V_10 , NULL ) ;
if ( F_87 ( V_10 ) )
return F_88 ( V_10 ) ;
V_5 = F_93 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_63 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
int F_99 ( T_2 V_172 , struct V_1 * V_2 )
{
struct V_143 * V_10 ;
int V_5 ;
if ( F_3 ( V_2 , V_171 ) )
return - V_11 ;
V_10 = F_100 ( V_172 ) ;
if ( F_87 ( V_10 ) )
return F_88 ( V_10 ) ;
if ( V_10 -> type != V_151 ) {
F_64 ( V_10 ) ;
return - V_91 ;
}
V_5 = F_93 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_64 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
static T_1 F_101 ( T_1 V_173 , T_1 V_174 , T_1 V_175 , T_1 V_15 , T_1 V_176 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
int V_177 = ( int ) V_174 ;
void * V_178 = ( void * ) ( long ) V_175 ;
unsigned int V_19 = ( unsigned int ) V_15 ;
char V_179 [ 16 ] ;
void * V_180 ;
if ( F_102 ( ( T_2 ) V_177 > 0xffff || V_19 > sizeof( V_179 ) ) )
return - V_169 ;
if ( F_102 ( F_103 ( V_4 ) &&
! F_104 ( V_4 , V_177 + V_19 ) ) )
return - V_169 ;
V_180 = F_105 ( V_4 , V_177 , V_19 , V_179 ) ;
if ( F_102 ( ! V_180 ) )
return - V_169 ;
if ( F_106 ( V_176 ) )
F_107 ( V_4 , V_180 , V_19 ) ;
memcpy ( V_180 , V_178 , V_19 ) ;
if ( V_180 == V_179 )
F_108 ( V_4 , V_177 , V_180 , V_19 ) ;
if ( F_106 ( V_176 ) && V_4 -> V_181 == V_182 )
V_4 -> V_183 = F_109 ( V_4 -> V_183 , F_110 ( V_180 , V_19 , 0 ) ) ;
return 0 ;
}
static T_1 F_111 ( T_1 V_173 , T_1 V_174 , T_1 V_178 , T_1 V_184 , T_1 V_176 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
int V_177 = ( int ) V_174 ;
T_6 V_185 , * V_180 ;
if ( F_102 ( ( T_2 ) V_177 > 0xffff ) )
return - V_169 ;
if ( F_102 ( F_103 ( V_4 ) &&
! F_104 ( V_4 , V_177 + sizeof( V_185 ) ) ) )
return - V_169 ;
V_180 = F_105 ( V_4 , V_177 , sizeof( V_185 ) , & V_185 ) ;
if ( F_102 ( ! V_180 ) )
return - V_169 ;
switch ( F_112 ( V_176 ) ) {
case 2 :
F_113 ( V_180 , V_178 , V_184 ) ;
break;
case 4 :
F_114 ( V_180 , V_178 , V_184 ) ;
break;
default:
return - V_91 ;
}
if ( V_180 == & V_185 )
F_108 ( V_4 , V_177 , V_180 , sizeof( V_185 ) ) ;
return 0 ;
}
static T_1 F_115 ( T_1 V_173 , T_1 V_174 , T_1 V_178 , T_1 V_184 , T_1 V_176 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
bool V_186 = ! ! F_116 ( V_176 ) ;
int V_177 = ( int ) V_174 ;
T_6 V_185 , * V_180 ;
if ( F_102 ( ( T_2 ) V_177 > 0xffff ) )
return - V_169 ;
if ( F_102 ( F_103 ( V_4 ) &&
! F_104 ( V_4 , V_177 + sizeof( V_185 ) ) ) )
return - V_169 ;
V_180 = F_105 ( V_4 , V_177 , sizeof( V_185 ) , & V_185 ) ;
if ( F_102 ( ! V_180 ) )
return - V_169 ;
switch ( F_112 ( V_176 ) ) {
case 2 :
F_117 ( V_180 , V_4 , V_178 , V_184 , V_186 ) ;
break;
case 4 :
F_118 ( V_180 , V_4 , V_178 , V_184 , V_186 ) ;
break;
default:
return - V_91 ;
}
if ( V_180 == & V_185 )
F_108 ( V_4 , V_177 , V_180 , sizeof( V_185 ) ) ;
return 0 ;
}
static T_1 F_119 ( T_1 V_173 , T_1 V_57 , T_1 V_176 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 , * V_187 ;
struct V_56 * V_58 ;
V_58 = F_120 ( F_121 ( V_4 -> V_58 ) , V_57 ) ;
if ( F_102 ( ! V_58 ) )
return - V_91 ;
V_187 = F_122 ( V_4 , V_188 ) ;
if ( F_102 ( ! V_187 ) )
return - V_8 ;
if ( F_123 ( V_176 ) )
return F_124 ( V_58 , V_187 ) ;
V_187 -> V_58 = V_58 ;
F_125 ( V_187 ) ;
return F_126 ( V_187 ) ;
}
static T_1 F_127 ( T_1 V_57 , T_1 V_176 , T_1 V_175 , T_1 V_15 , T_1 V_16 )
{
struct V_189 * V_190 = F_128 ( & V_189 ) ;
V_190 -> V_57 = V_57 ;
V_190 -> V_176 = V_176 ;
return V_191 ;
}
int F_129 ( struct V_3 * V_4 )
{
struct V_189 * V_190 = F_128 ( & V_189 ) ;
struct V_56 * V_58 ;
V_58 = F_120 ( F_121 ( V_4 -> V_58 ) , V_190 -> V_57 ) ;
V_190 -> V_57 = 0 ;
if ( F_102 ( ! V_58 ) ) {
F_130 ( V_4 ) ;
return - V_91 ;
}
if ( F_123 ( V_190 -> V_176 ) )
return F_124 ( V_58 , V_4 ) ;
V_4 -> V_58 = V_58 ;
F_125 ( V_4 ) ;
return F_126 ( V_4 ) ;
}
static T_1 F_131 ( T_1 V_173 , T_1 V_174 , T_1 V_175 , T_1 V_15 , T_1 V_16 )
{
return F_132 ( (struct V_3 * ) ( unsigned long ) V_173 ) ;
}
static T_1 F_133 ( T_1 V_173 , T_1 V_174 , T_1 V_175 , T_1 V_15 , T_1 V_16 )
{
#ifdef F_134
const struct V_192 * V_193 ;
V_193 = F_135 ( (struct V_3 * ) ( unsigned long ) V_173 ) ;
if ( V_193 )
return V_193 -> V_194 ;
#endif
return 0 ;
}
static T_1 F_136 ( T_1 V_173 , T_1 V_174 , T_1 V_41 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
T_7 V_64 = ( V_195 T_7 ) V_174 ;
if ( F_102 ( V_64 != F_137 ( V_196 ) &&
V_64 != F_137 ( V_197 ) ) )
V_64 = F_137 ( V_196 ) ;
return F_138 ( V_4 , V_64 , V_41 ) ;
}
static T_1 F_139 ( T_1 V_173 , T_1 V_174 , T_1 V_175 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
return F_140 ( V_4 ) ;
}
bool F_141 ( void * V_198 )
{
if ( V_198 == F_136 )
return true ;
if ( V_198 == F_139 )
return true ;
return false ;
}
static T_1 F_142 ( T_1 V_173 , T_1 V_174 , T_1 V_199 , T_1 V_176 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
struct V_200 * V_184 = (struct V_200 * ) ( long ) V_174 ;
struct V_201 * V_202 = F_143 ( V_4 ) ;
if ( F_102 ( V_199 != sizeof( struct V_200 ) || V_176 || ! V_202 ) )
return - V_91 ;
if ( F_144 ( V_202 ) != V_203 )
return - V_91 ;
V_184 -> V_204 = F_145 ( V_202 -> V_205 . V_206 ) ;
V_184 -> V_207 = F_146 ( V_202 -> V_205 . V_208 . V_209 . V_210 ) ;
return 0 ;
}
static T_1 F_147 ( T_1 V_173 , T_1 V_174 , T_1 V_199 , T_1 V_176 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_173 ;
struct V_200 * V_178 = (struct V_200 * ) ( long ) V_174 ;
struct V_211 * V_212 = F_128 ( V_213 ) ;
struct V_201 * V_202 ;
if ( F_102 ( V_199 != sizeof( struct V_200 ) || V_176 ) )
return - V_91 ;
F_148 ( V_4 ) ;
F_149 ( (struct V_192 * ) V_212 ) ;
F_150 ( V_4 , (struct V_192 * ) V_212 ) ;
V_202 = & V_212 -> V_208 . V_214 ;
V_202 -> V_215 = V_216 ;
V_202 -> V_205 . V_217 = V_218 ;
V_202 -> V_205 . V_206 = F_151 ( V_178 -> V_204 ) ;
V_202 -> V_205 . V_208 . V_209 . V_193 = F_152 ( V_178 -> V_207 ) ;
return 0 ;
}
static const struct V_219 * F_153 ( void )
{
if ( ! V_213 ) {
V_213 = F_154 ( 0 , V_92 ) ;
if ( ! V_213 )
return NULL ;
}
return & V_220 ;
}
static const struct V_219 *
F_155 ( enum V_221 V_222 )
{
switch ( V_222 ) {
case V_223 :
return & V_224 ;
case V_225 :
return & V_226 ;
case V_227 :
return & V_228 ;
case V_229 :
return & V_230 ;
case V_231 :
return & V_232 ;
case V_233 :
return & V_234 ;
case V_235 :
return & V_236 ;
case V_237 :
if ( F_156 ( V_238 ) )
return F_157 () ;
default:
return NULL ;
}
}
static const struct V_219 *
F_158 ( enum V_221 V_222 )
{
switch ( V_222 ) {
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
return & V_254 ;
case V_255 :
return F_153 () ;
case V_256 :
return & V_257 ;
case V_258 :
return & V_259 ;
default:
return F_155 ( V_222 ) ;
}
}
static bool F_159 ( int V_260 , int V_199 , enum V_261 type )
{
if ( V_260 < 0 || V_260 >= sizeof( struct V_262 ) )
return false ;
if ( V_260 % V_199 != 0 )
return false ;
if ( V_199 != 4 )
return false ;
return true ;
}
static bool F_160 ( int V_260 , int V_199 ,
enum V_261 type )
{
if ( V_260 == F_23 ( struct V_262 , V_263 ) )
return false ;
if ( type == V_264 ) {
switch ( V_260 ) {
case F_23 ( struct V_262 , V_265 [ 0 ] ) ...
F_23 ( struct V_262 , V_265 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_159 ( V_260 , V_199 , type ) ;
}
static bool F_161 ( int V_260 , int V_199 ,
enum V_261 type )
{
if ( V_260 == F_23 ( struct V_262 , V_263 ) )
return type == V_264 ? true : false ;
if ( type == V_264 ) {
switch ( V_260 ) {
case F_23 ( struct V_262 , V_29 ) :
case F_23 ( struct V_262 , V_266 ) :
case F_23 ( struct V_262 , V_267 ) :
case F_23 ( struct V_262 , V_265 [ 0 ] ) ...
F_23 ( struct V_262 , V_265 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_159 ( V_260 , V_199 , type ) ;
}
static T_2 F_162 ( enum V_261 type , int V_23 ,
int V_24 , int V_268 ,
struct V_25 * V_26 ,
struct V_143 * V_10 )
{
struct V_25 * V_27 = V_26 ;
switch ( V_268 ) {
case F_23 ( struct V_262 , V_19 ) :
F_20 ( F_21 ( struct V_3 , V_19 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_19 ) ) ;
break;
case F_23 ( struct V_262 , V_50 ) :
F_20 ( F_21 ( struct V_3 , V_50 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_50 ) ) ;
break;
case F_23 ( struct V_262 , V_64 ) :
F_20 ( F_21 ( struct V_3 , V_64 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_64 ) ) ;
break;
case F_23 ( struct V_262 , V_267 ) :
F_20 ( F_21 ( struct V_3 , V_267 ) != 4 ) ;
if ( type == V_264 )
* V_27 ++ = F_50 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_267 ) ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_267 ) ) ;
break;
case F_23 ( struct V_262 , V_269 ) :
F_20 ( F_21 ( struct V_3 , V_270 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_270 ) ) ;
break;
case F_23 ( struct V_262 , V_57 ) :
F_20 ( F_21 ( struct V_56 , V_57 ) != 4 ) ;
* V_27 ++ = F_22 ( F_29 ( F_21 ( struct V_3 , V_58 ) ) ,
V_23 , V_24 ,
F_23 ( struct V_3 , V_58 ) ) ;
* V_27 ++ = F_30 ( V_113 , V_23 , 0 , 1 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_23 ,
F_23 ( struct V_56 , V_57 ) ) ;
break;
case F_23 ( struct V_262 , V_62 ) :
F_20 ( F_21 ( struct V_3 , V_62 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_62 ) ) ;
break;
case F_23 ( struct V_262 , V_29 ) :
F_20 ( F_21 ( struct V_3 , V_29 ) != 4 ) ;
if ( type == V_264 )
* V_27 ++ = F_50 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
break;
case F_23 ( struct V_262 , V_271 ) :
return F_19 ( V_31 , V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_262 , V_37 ) :
return F_19 ( V_36 , V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_262 , V_272 ) :
return F_19 ( V_40 ,
V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_262 , V_41 ) :
return F_19 ( V_39 ,
V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_262 , V_265 [ 0 ] ) ...
F_23 ( struct V_262 , V_265 [ 4 ] ) :
F_20 ( F_21 ( struct V_273 , V_20 ) < 20 ) ;
V_10 -> V_274 = 1 ;
V_268 -= F_23 ( struct V_262 , V_265 [ 0 ] ) ;
V_268 += F_23 ( struct V_3 , V_265 ) ;
V_268 += F_23 ( struct V_273 , V_20 ) ;
if ( type == V_264 )
* V_27 ++ = F_50 ( V_30 , V_23 , V_24 , V_268 ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 , V_268 ) ;
break;
case F_23 ( struct V_262 , V_263 ) :
V_268 -= F_23 ( struct V_262 , V_263 ) ;
V_268 += F_23 ( struct V_3 , V_265 ) ;
V_268 += F_23 ( struct V_273 , V_263 ) ;
F_163 ( type != V_264 ) ;
* V_27 ++ = F_50 ( V_38 , V_23 , V_24 , V_268 ) ;
break;
case F_23 ( struct V_262 , V_266 ) :
#ifdef F_164
F_20 ( F_21 ( struct V_3 , V_266 ) != 2 ) ;
if ( type == V_264 )
* V_27 ++ = F_50 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_266 ) ) ;
else
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_266 ) ) ;
break;
#else
if ( type == V_264 )
* V_27 ++ = F_32 ( V_23 , V_23 ) ;
else
* V_27 ++ = F_165 ( V_23 , 0 ) ;
break;
#endif
}
return V_27 - V_26 ;
}
static int T_8 F_166 ( void )
{
F_167 ( & V_275 ) ;
F_167 ( & V_276 ) ;
F_167 ( & V_277 ) ;
return 0 ;
}
int F_168 ( struct V_1 * V_2 )
{
int V_137 = - V_278 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_171 ) )
return - V_11 ;
V_6 = F_95 ( V_2 -> F_1 ,
F_96 ( V_2 ) ) ;
if ( V_6 ) {
F_169 ( V_2 -> F_1 , NULL ) ;
F_72 ( V_2 , V_6 ) ;
V_137 = 0 ;
}
return V_137 ;
}
int F_170 ( struct V_1 * V_2 , struct V_43 T_9 * V_279 ,
unsigned int V_19 )
{
struct V_147 * V_145 ;
struct F_1 * V_6 ;
int V_137 = 0 ;
F_171 ( V_2 ) ;
V_6 = F_95 ( V_2 -> F_1 ,
F_96 ( V_2 ) ) ;
if ( ! V_6 )
goto V_280;
V_137 = - V_281 ;
V_145 = V_6 -> V_10 -> V_149 ;
if ( ! V_145 )
goto V_280;
V_137 = V_145 -> V_19 ;
if ( ! V_19 )
goto V_280;
V_137 = - V_91 ;
if ( V_19 < V_145 -> V_19 )
goto V_280;
V_137 = - V_169 ;
if ( F_172 ( V_279 , V_145 -> V_6 , F_59 ( V_145 ) ) )
goto V_280;
V_137 = V_145 -> V_19 ;
V_280:
F_173 ( V_2 ) ;
return V_137 ;
}
