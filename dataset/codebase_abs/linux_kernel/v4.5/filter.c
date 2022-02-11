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
* V_27 ++ = F_49 ( F_50 ( V_44 -> V_96 ) == V_100 ?
V_100 : V_99 , V_124 ,
V_51 , V_44 -> V_47 ) ;
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
static int F_94 ( struct V_143 * V_10 , struct V_1 * V_2 )
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
V_159 = F_96 ( V_2 -> F_1 ,
F_97 ( V_2 ) ) ;
F_98 ( V_2 -> F_1 , V_44 ) ;
if ( V_159 )
F_73 ( V_2 , V_159 ) ;
return 0 ;
}
static int F_99 ( struct V_143 * V_10 , struct V_1 * V_2 )
{
struct V_143 * V_158 ;
int V_5 ;
if ( F_74 ( V_10 -> V_19 ) > V_157 )
return - V_8 ;
if ( F_100 ( V_2 ) ) {
V_5 = F_101 ( V_2 ) ;
if ( V_5 )
return V_5 ;
} else if ( ! F_102 ( V_2 -> V_170 ) ) {
return - V_91 ;
}
V_158 = F_103 ( V_2 , V_10 ) ;
if ( V_158 )
F_93 ( V_158 ) ;
return 0 ;
}
static
struct V_143 * F_104 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
unsigned int V_146 = F_60 ( V_145 ) ;
unsigned int V_171 = F_74 ( V_145 -> V_19 ) ;
struct V_143 * V_10 ;
int V_5 ;
if ( F_3 ( V_2 , V_172 ) )
return F_83 ( - V_11 ) ;
if ( V_145 -> V_6 == NULL )
return F_83 ( - V_91 ) ;
V_10 = F_87 ( V_171 , 0 ) ;
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
int F_105 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_104 ( V_145 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_94 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_64 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
int F_106 ( struct V_144 * V_145 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_104 ( V_145 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_99 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_64 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
static struct V_143 * F_107 ( T_2 V_173 , struct V_1 * V_2 )
{
struct V_143 * V_10 ;
if ( F_3 ( V_2 , V_172 ) )
return F_83 ( - V_11 ) ;
V_10 = F_108 ( V_173 ) ;
if ( F_88 ( V_10 ) )
return V_10 ;
if ( V_10 -> type != V_151 ) {
F_65 ( V_10 ) ;
return F_83 ( - V_91 ) ;
}
return V_10 ;
}
int F_109 ( T_2 V_173 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_107 ( V_173 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_94 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_65 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
int F_110 ( T_2 V_173 , struct V_1 * V_2 )
{
struct V_143 * V_10 = F_107 ( V_173 , V_2 ) ;
int V_5 ;
if ( F_88 ( V_10 ) )
return F_89 ( V_10 ) ;
V_5 = F_99 ( V_10 , V_2 ) ;
if ( V_5 < 0 ) {
F_65 ( V_10 ) ;
return V_5 ;
}
return 0 ;
}
static T_1 F_111 ( T_1 V_174 , T_1 V_175 , T_1 V_176 , T_1 V_15 , T_1 V_177 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
int V_178 = ( int ) V_175 ;
void * V_179 = ( void * ) ( long ) V_176 ;
unsigned int V_19 = ( unsigned int ) V_15 ;
char V_180 [ V_181 ] ;
void * V_182 ;
if ( F_112 ( V_177 & ~ ( V_183 ) ) )
return - V_91 ;
if ( F_112 ( ( T_2 ) V_178 > 0xffff || V_19 > sizeof( V_180 ) ) )
return - V_169 ;
if ( F_112 ( F_113 ( V_4 ) &&
! F_114 ( V_4 , V_178 + V_19 ) ) )
return - V_169 ;
V_182 = F_115 ( V_4 , V_178 , V_19 , V_180 ) ;
if ( F_112 ( ! V_182 ) )
return - V_169 ;
if ( V_177 & V_183 )
F_116 ( V_4 , V_182 , V_19 ) ;
memcpy ( V_182 , V_179 , V_19 ) ;
if ( V_182 == V_180 )
F_117 ( V_4 , V_178 , V_182 , V_19 ) ;
if ( V_177 & V_183 )
F_118 ( V_4 , V_182 , V_19 ) ;
return 0 ;
}
static T_1 F_119 ( T_1 V_174 , T_1 V_175 , T_1 V_176 , T_1 V_15 , T_1 V_16 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) ( unsigned long ) V_174 ;
int V_178 = ( int ) V_175 ;
void * V_184 = ( void * ) ( unsigned long ) V_176 ;
unsigned int V_19 = ( unsigned int ) V_15 ;
void * V_182 ;
if ( F_112 ( ( T_2 ) V_178 > 0xffff || V_19 > V_181 ) )
return - V_169 ;
V_182 = F_115 ( V_4 , V_178 , V_19 , V_184 ) ;
if ( F_112 ( ! V_182 ) )
return - V_169 ;
if ( V_182 != V_184 )
memcpy ( V_184 , V_182 , V_19 ) ;
return 0 ;
}
static T_1 F_120 ( T_1 V_174 , T_1 V_175 , T_1 V_179 , T_1 V_184 , T_1 V_177 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
int V_178 = ( int ) V_175 ;
T_6 V_185 , * V_182 ;
if ( F_112 ( V_177 & ~ ( V_186 ) ) )
return - V_91 ;
if ( F_112 ( ( T_2 ) V_178 > 0xffff ) )
return - V_169 ;
if ( F_112 ( F_113 ( V_4 ) &&
! F_114 ( V_4 , V_178 + sizeof( V_185 ) ) ) )
return - V_169 ;
V_182 = F_115 ( V_4 , V_178 , sizeof( V_185 ) , & V_185 ) ;
if ( F_112 ( ! V_182 ) )
return - V_169 ;
switch ( V_177 & V_186 ) {
case 2 :
F_121 ( V_182 , V_179 , V_184 ) ;
break;
case 4 :
F_122 ( V_182 , V_179 , V_184 ) ;
break;
default:
return - V_91 ;
}
if ( V_182 == & V_185 )
F_117 ( V_4 , V_178 , V_182 , sizeof( V_185 ) ) ;
return 0 ;
}
static T_1 F_123 ( T_1 V_174 , T_1 V_175 , T_1 V_179 , T_1 V_184 , T_1 V_177 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
bool V_187 = V_177 & V_188 ;
int V_178 = ( int ) V_175 ;
T_6 V_185 , * V_182 ;
if ( F_112 ( V_177 & ~ ( V_188 | V_186 ) ) )
return - V_91 ;
if ( F_112 ( ( T_2 ) V_178 > 0xffff ) )
return - V_169 ;
if ( F_112 ( F_113 ( V_4 ) &&
! F_114 ( V_4 , V_178 + sizeof( V_185 ) ) ) )
return - V_169 ;
V_182 = F_115 ( V_4 , V_178 , sizeof( V_185 ) , & V_185 ) ;
if ( F_112 ( ! V_182 ) )
return - V_169 ;
switch ( V_177 & V_186 ) {
case 2 :
F_124 ( V_182 , V_4 , V_179 , V_184 , V_187 ) ;
break;
case 4 :
F_125 ( V_182 , V_4 , V_179 , V_184 , V_187 ) ;
break;
default:
return - V_91 ;
}
if ( V_182 == & V_185 )
F_117 ( V_4 , V_178 , V_182 , sizeof( V_185 ) ) ;
return 0 ;
}
static T_1 F_126 ( T_1 V_174 , T_1 V_57 , T_1 V_177 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 , * V_189 ;
struct V_56 * V_58 ;
if ( F_112 ( V_177 & ~ ( V_190 ) ) )
return - V_91 ;
V_58 = F_127 ( F_128 ( V_4 -> V_58 ) , V_57 ) ;
if ( F_112 ( ! V_58 ) )
return - V_91 ;
V_189 = F_129 ( V_4 , V_191 ) ;
if ( F_112 ( ! V_189 ) )
return - V_8 ;
if ( V_177 & V_190 ) {
if ( F_130 ( V_189 ) )
F_118 ( V_189 , F_131 ( V_189 ) ,
V_189 -> V_192 ) ;
return F_132 ( V_58 , V_189 ) ;
}
V_189 -> V_58 = V_58 ;
F_133 ( V_189 ) ;
return F_134 ( V_189 ) ;
}
static T_1 F_135 ( T_1 V_57 , T_1 V_177 , T_1 V_176 , T_1 V_15 , T_1 V_16 )
{
struct V_193 * V_194 = F_136 ( & V_193 ) ;
if ( F_112 ( V_177 & ~ ( V_190 ) ) )
return V_195 ;
V_194 -> V_57 = V_57 ;
V_194 -> V_177 = V_177 ;
return V_196 ;
}
int F_137 ( struct V_3 * V_4 )
{
struct V_193 * V_194 = F_136 ( & V_193 ) ;
struct V_56 * V_58 ;
V_58 = F_127 ( F_128 ( V_4 -> V_58 ) , V_194 -> V_57 ) ;
V_194 -> V_57 = 0 ;
if ( F_112 ( ! V_58 ) ) {
F_138 ( V_4 ) ;
return - V_91 ;
}
if ( V_194 -> V_177 & V_190 ) {
if ( F_130 ( V_4 ) )
F_118 ( V_4 , F_131 ( V_4 ) ,
V_4 -> V_192 ) ;
return F_132 ( V_58 , V_4 ) ;
}
V_4 -> V_58 = V_58 ;
F_133 ( V_4 ) ;
return F_134 ( V_4 ) ;
}
static T_1 F_139 ( T_1 V_174 , T_1 V_175 , T_1 V_176 , T_1 V_15 , T_1 V_16 )
{
return F_140 ( (struct V_3 * ) ( unsigned long ) V_174 ) ;
}
static T_1 F_141 ( T_1 V_174 , T_1 V_175 , T_1 V_176 , T_1 V_15 , T_1 V_16 )
{
#ifdef F_142
const struct V_197 * V_198 ;
V_198 = F_143 ( (struct V_3 * ) ( unsigned long ) V_174 ) ;
if ( V_198 )
return V_198 -> V_199 ;
#endif
return 0 ;
}
static T_1 F_144 ( T_1 V_174 , T_1 V_175 , T_1 V_41 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
T_7 V_64 = ( V_200 T_7 ) V_175 ;
if ( F_112 ( V_64 != F_145 ( V_201 ) &&
V_64 != F_145 ( V_202 ) ) )
V_64 = F_145 ( V_201 ) ;
return F_146 ( V_4 , V_64 , V_41 ) ;
}
static T_1 F_147 ( T_1 V_174 , T_1 V_175 , T_1 V_176 , T_1 V_15 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
return F_148 ( V_4 ) ;
}
bool F_149 ( void * V_203 )
{
if ( V_203 == F_144 )
return true ;
if ( V_203 == F_147 )
return true ;
return false ;
}
static unsigned short F_150 ( T_1 V_177 )
{
return V_177 & V_204 ? V_205 : V_206 ;
}
static T_1 F_151 ( T_1 V_174 , T_1 V_175 , T_1 V_207 , T_1 V_177 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
struct V_208 * V_184 = (struct V_208 * ) ( long ) V_175 ;
const struct V_209 * V_210 = F_152 ( V_4 ) ;
T_3 V_211 [ sizeof( struct V_208 ) ] ;
if ( F_112 ( ! V_210 || ( V_177 & ~ ( V_204 ) ) ) )
return - V_91 ;
if ( F_153 ( V_210 ) != F_150 ( V_177 ) )
return - V_212 ;
if ( F_112 ( V_207 != sizeof( struct V_208 ) ) ) {
switch ( V_207 ) {
case F_23 ( struct V_208 , V_213 [ 1 ] ) :
if ( F_153 ( V_210 ) != V_206 )
return - V_91 ;
V_184 = (struct V_208 * ) V_211 ;
break;
default:
return - V_91 ;
}
}
V_184 -> V_214 = F_154 ( V_210 -> V_215 . V_216 ) ;
V_184 -> V_217 = V_210 -> V_215 . V_218 ;
V_184 -> V_219 = V_210 -> V_215 . V_220 ;
if ( V_177 & V_204 )
memcpy ( V_184 -> V_213 , & V_210 -> V_215 . V_221 . V_222 . V_223 ,
sizeof( V_184 -> V_213 ) ) ;
else
V_184 -> V_224 = F_155 ( V_210 -> V_215 . V_221 . V_225 . V_223 ) ;
if ( F_112 ( V_207 != sizeof( struct V_208 ) ) )
memcpy ( ( void * ) ( long ) V_175 , V_184 , V_207 ) ;
return 0 ;
}
static T_1 F_156 ( T_1 V_174 , T_1 V_175 , T_1 V_207 , T_1 V_177 , T_1 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_174 ;
struct V_208 * V_179 = (struct V_208 * ) ( long ) V_175 ;
struct V_226 * V_227 = F_136 ( V_228 ) ;
T_3 V_211 [ sizeof( struct V_208 ) ] ;
struct V_209 * V_210 ;
if ( F_112 ( V_177 & ~ ( V_204 | V_229 ) ) )
return - V_91 ;
if ( F_112 ( V_207 != sizeof( struct V_208 ) ) ) {
switch ( V_207 ) {
case F_23 ( struct V_208 , V_213 [ 1 ] ) :
memcpy ( V_211 , V_179 , V_207 ) ;
memset ( V_211 + V_207 , 0 , sizeof( V_211 ) - V_207 ) ;
V_179 = (struct V_208 * ) V_211 ;
break;
default:
return - V_91 ;
}
}
F_157 ( V_4 ) ;
F_158 ( (struct V_197 * ) V_227 ) ;
F_159 ( V_4 , (struct V_197 * ) V_227 ) ;
V_210 = & V_227 -> V_221 . V_230 ;
V_210 -> V_231 = V_232 ;
V_210 -> V_215 . V_233 = V_234 | V_235 ;
V_210 -> V_215 . V_216 = F_160 ( V_179 -> V_214 ) ;
V_210 -> V_215 . V_218 = V_179 -> V_217 ;
V_210 -> V_215 . V_220 = V_179 -> V_219 ;
if ( V_177 & V_204 ) {
V_210 -> V_231 |= V_236 ;
memcpy ( & V_210 -> V_215 . V_221 . V_222 . V_198 , V_179 -> V_213 ,
sizeof( V_179 -> V_213 ) ) ;
} else {
V_210 -> V_215 . V_221 . V_225 . V_198 = F_161 ( V_179 -> V_224 ) ;
if ( V_177 & V_229 )
V_210 -> V_215 . V_233 &= ~ V_235 ;
}
return 0 ;
}
static const struct V_237 * F_162 ( void )
{
if ( ! V_228 ) {
V_228 = F_163 ( 0 , V_92 ) ;
if ( ! V_228 )
return NULL ;
}
return & V_238 ;
}
static const struct V_237 *
F_164 ( enum V_239 V_240 )
{
switch ( V_240 ) {
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
if ( F_165 ( V_256 ) )
return F_166 () ;
default:
return NULL ;
}
}
static const struct V_237 *
F_167 ( enum V_239 V_240 )
{
switch ( V_240 ) {
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
return F_162 () ;
case V_276 :
return & V_277 ;
case V_278 :
return & V_279 ;
default:
return F_164 ( V_240 ) ;
}
}
static bool F_168 ( int V_280 , int V_207 , enum V_281 type )
{
if ( V_280 < 0 || V_280 >= sizeof( struct V_282 ) )
return false ;
if ( V_280 % V_207 != 0 )
return false ;
if ( V_207 != 4 )
return false ;
return true ;
}
static bool F_169 ( int V_280 , int V_207 ,
enum V_281 type )
{
if ( V_280 == F_23 ( struct V_282 , V_283 ) )
return false ;
if ( type == V_284 ) {
switch ( V_280 ) {
case F_23 ( struct V_282 , V_285 [ 0 ] ) ...
F_23 ( struct V_282 , V_285 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_168 ( V_280 , V_207 , type ) ;
}
static bool F_170 ( int V_280 , int V_207 ,
enum V_281 type )
{
if ( V_280 == F_23 ( struct V_282 , V_283 ) )
return type == V_284 ? true : false ;
if ( type == V_284 ) {
switch ( V_280 ) {
case F_23 ( struct V_282 , V_29 ) :
case F_23 ( struct V_282 , V_286 ) :
case F_23 ( struct V_282 , V_287 ) :
case F_23 ( struct V_282 , V_285 [ 0 ] ) ...
F_23 ( struct V_282 , V_285 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_168 ( V_280 , V_207 , type ) ;
}
static T_2 F_171 ( enum V_281 type , int V_23 ,
int V_24 , int V_288 ,
struct V_25 * V_26 ,
struct V_143 * V_10 )
{
struct V_25 * V_27 = V_26 ;
switch ( V_288 ) {
case F_23 ( struct V_282 , V_19 ) :
F_20 ( F_21 ( struct V_3 , V_19 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_19 ) ) ;
break;
case F_23 ( struct V_282 , V_50 ) :
F_20 ( F_21 ( struct V_3 , V_50 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_50 ) ) ;
break;
case F_23 ( struct V_282 , V_64 ) :
F_20 ( F_21 ( struct V_3 , V_64 ) != 2 ) ;
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_64 ) ) ;
break;
case F_23 ( struct V_282 , V_287 ) :
F_20 ( F_21 ( struct V_3 , V_287 ) != 4 ) ;
if ( type == V_284 )
* V_27 ++ = F_51 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_287 ) ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_287 ) ) ;
break;
case F_23 ( struct V_282 , V_289 ) :
F_20 ( F_21 ( struct V_3 , V_290 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_290 ) ) ;
break;
case F_23 ( struct V_282 , V_57 ) :
F_20 ( F_21 ( struct V_56 , V_57 ) != 4 ) ;
* V_27 ++ = F_22 ( F_29 ( F_21 ( struct V_3 , V_58 ) ) ,
V_23 , V_24 ,
F_23 ( struct V_3 , V_58 ) ) ;
* V_27 ++ = F_30 ( V_113 , V_23 , 0 , 1 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_23 ,
F_23 ( struct V_56 , V_57 ) ) ;
break;
case F_23 ( struct V_282 , V_62 ) :
F_20 ( F_21 ( struct V_3 , V_62 ) != 4 ) ;
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_62 ) ) ;
break;
case F_23 ( struct V_282 , V_29 ) :
F_20 ( F_21 ( struct V_3 , V_29 ) != 4 ) ;
if ( type == V_284 )
* V_27 ++ = F_51 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 ,
F_23 ( struct V_3 , V_29 ) ) ;
break;
case F_23 ( struct V_282 , V_291 ) :
return F_19 ( V_31 , V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_282 , V_37 ) :
return F_19 ( V_36 , V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_282 , V_292 ) :
return F_19 ( V_40 ,
V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_282 , V_41 ) :
return F_19 ( V_39 ,
V_23 , V_24 , V_27 ) ;
case F_23 ( struct V_282 , V_285 [ 0 ] ) ...
F_23 ( struct V_282 , V_285 [ 4 ] ) :
F_20 ( F_21 ( struct V_293 , V_20 ) < 20 ) ;
V_10 -> V_294 = 1 ;
V_288 -= F_23 ( struct V_282 , V_285 [ 0 ] ) ;
V_288 += F_23 ( struct V_3 , V_285 ) ;
V_288 += F_23 ( struct V_293 , V_20 ) ;
if ( type == V_284 )
* V_27 ++ = F_51 ( V_30 , V_23 , V_24 , V_288 ) ;
else
* V_27 ++ = F_22 ( V_30 , V_23 , V_24 , V_288 ) ;
break;
case F_23 ( struct V_282 , V_283 ) :
V_288 -= F_23 ( struct V_282 , V_283 ) ;
V_288 += F_23 ( struct V_3 , V_285 ) ;
V_288 += F_23 ( struct V_293 , V_283 ) ;
F_172 ( type != V_284 ) ;
* V_27 ++ = F_51 ( V_38 , V_23 , V_24 , V_288 ) ;
break;
case F_23 ( struct V_282 , V_286 ) :
#ifdef F_173
F_20 ( F_21 ( struct V_3 , V_286 ) != 2 ) ;
if ( type == V_284 )
* V_27 ++ = F_51 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_286 ) ) ;
else
* V_27 ++ = F_22 ( V_38 , V_23 , V_24 ,
F_23 ( struct V_3 , V_286 ) ) ;
break;
#else
if ( type == V_284 )
* V_27 ++ = F_32 ( V_23 , V_23 ) ;
else
* V_27 ++ = F_174 ( V_23 , 0 ) ;
break;
#endif
}
return V_27 - V_26 ;
}
static int T_8 F_175 ( void )
{
F_176 ( & V_295 ) ;
F_176 ( & V_296 ) ;
F_176 ( & V_297 ) ;
return 0 ;
}
int F_177 ( struct V_1 * V_2 )
{
int V_137 = - V_298 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_172 ) )
return - V_11 ;
V_6 = F_96 ( V_2 -> F_1 ,
F_97 ( V_2 ) ) ;
if ( V_6 ) {
F_178 ( V_2 -> F_1 , NULL ) ;
F_73 ( V_2 , V_6 ) ;
V_137 = 0 ;
}
return V_137 ;
}
int F_179 ( struct V_1 * V_2 , struct V_43 T_9 * V_299 ,
unsigned int V_19 )
{
struct V_147 * V_145 ;
struct F_1 * V_6 ;
int V_137 = 0 ;
F_180 ( V_2 ) ;
V_6 = F_96 ( V_2 -> F_1 ,
F_97 ( V_2 ) ) ;
if ( ! V_6 )
goto V_300;
V_137 = - V_301 ;
V_145 = V_6 -> V_10 -> V_149 ;
if ( ! V_145 )
goto V_300;
V_137 = V_145 -> V_19 ;
if ( ! V_19 )
goto V_300;
V_137 = - V_91 ;
if ( V_19 < V_145 -> V_19 )
goto V_300;
V_137 = - V_169 ;
if ( F_181 ( V_299 , V_145 -> V_6 , F_60 ( V_145 ) ) )
goto V_300;
V_137 = V_145 -> V_19 ;
V_300:
F_182 ( V_2 ) ;
return V_137 ;
}
