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
static T_1 F_10 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
return F_11 ( (struct V_3 * ) ( unsigned long ) V_11 ) ;
}
static T_1 F_12 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_11 ;
struct V_16 * V_17 ;
if ( F_13 ( V_4 ) )
return 0 ;
if ( V_4 -> V_18 < sizeof( struct V_16 ) )
return 0 ;
if ( V_12 > V_4 -> V_18 - sizeof( struct V_16 ) )
return 0 ;
V_17 = F_14 ( (struct V_16 * ) & V_4 -> V_19 [ V_12 ] , V_4 -> V_18 - V_12 , V_13 ) ;
if ( V_17 )
return ( void * ) V_17 - ( void * ) V_4 -> V_19 ;
return 0 ;
}
static T_1 F_15 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( unsigned long ) V_11 ;
struct V_16 * V_17 ;
if ( F_13 ( V_4 ) )
return 0 ;
if ( V_4 -> V_18 < sizeof( struct V_16 ) )
return 0 ;
if ( V_12 > V_4 -> V_18 - sizeof( struct V_16 ) )
return 0 ;
V_17 = (struct V_16 * ) & V_4 -> V_19 [ V_12 ] ;
if ( V_17 -> V_20 > V_4 -> V_18 - V_12 )
return 0 ;
V_17 = F_16 ( V_17 , V_13 ) ;
if ( V_17 )
return ( void * ) V_17 - ( void * ) V_4 -> V_19 ;
return 0 ;
}
static T_1 F_17 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
return F_18 () ;
}
static T_1 F_19 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 , T_1 V_15 )
{
return F_20 () ;
}
static bool F_21 ( struct V_21 * V_22 ,
struct V_23 * * V_24 )
{
struct V_23 * V_25 = * V_24 ;
switch ( V_22 -> V_26 ) {
case V_27 + V_28 :
F_22 ( F_23 ( struct V_3 , V_29 ) != 2 ) ;
* V_25 ++ = F_24 ( V_30 , V_31 , V_32 ,
F_25 ( struct V_3 , V_29 ) ) ;
* V_25 = F_26 ( V_33 , V_31 , 16 ) ;
break;
case V_27 + V_34 :
* V_25 ++ = F_24 ( V_35 , V_31 , V_32 ,
F_27 () ) ;
* V_25 = F_28 ( V_36 , V_31 , V_37 ) ;
#ifdef F_29
V_25 ++ ;
* V_25 = F_28 ( V_38 , V_31 , 5 ) ;
#endif
break;
case V_27 + V_39 :
case V_27 + V_40 :
F_22 ( F_23 ( struct V_41 , V_42 ) != 4 ) ;
F_22 ( F_23 ( struct V_41 , type ) != 2 ) ;
F_22 ( F_30 ( F_23 ( struct V_3 , V_43 ) ) < 0 ) ;
* V_25 ++ = F_24 ( F_30 ( F_23 ( struct V_3 , V_43 ) ) ,
V_44 , V_32 ,
F_25 ( struct V_3 , V_43 ) ) ;
* V_25 ++ = F_31 ( V_45 , V_44 , 0 , 1 ) ;
* V_25 ++ = F_32 () ;
if ( V_22 -> V_26 == V_27 + V_39 )
* V_25 = F_24 ( V_46 , V_31 , V_44 ,
F_25 ( struct V_41 , V_42 ) ) ;
else
* V_25 = F_24 ( V_30 , V_31 , V_44 ,
F_25 ( struct V_41 , type ) ) ;
break;
case V_27 + V_47 :
F_22 ( F_23 ( struct V_3 , V_48 ) != 4 ) ;
* V_25 = F_24 ( V_46 , V_31 , V_32 ,
F_25 ( struct V_3 , V_48 ) ) ;
break;
case V_27 + V_49 :
F_22 ( F_23 ( struct V_3 , V_50 ) != 4 ) ;
* V_25 = F_24 ( V_46 , V_31 , V_32 ,
F_25 ( struct V_3 , V_50 ) ) ;
break;
case V_27 + V_51 :
F_22 ( F_23 ( struct V_3 , V_52 ) != 2 ) ;
* V_25 = F_24 ( V_30 , V_31 , V_32 ,
F_25 ( struct V_3 , V_52 ) ) ;
break;
case V_27 + V_53 :
case V_27 + V_54 :
F_22 ( F_23 ( struct V_3 , V_55 ) != 2 ) ;
F_22 ( V_56 != 0x1000 ) ;
* V_25 ++ = F_24 ( V_30 , V_31 , V_32 ,
F_25 ( struct V_3 , V_55 ) ) ;
if ( V_22 -> V_26 == V_27 + V_53 ) {
* V_25 = F_28 ( V_36 , V_31 ,
~ V_56 ) ;
} else {
* V_25 ++ = F_28 ( V_38 , V_31 , 12 ) ;
* V_25 = F_28 ( V_36 , V_31 , 1 ) ;
}
break;
case V_27 + V_57 :
case V_27 + V_58 :
case V_27 + V_59 :
case V_27 + V_60 :
case V_27 + V_61 :
* V_25 ++ = F_33 ( V_62 , V_32 ) ;
* V_25 ++ = F_33 ( V_63 , V_31 ) ;
* V_25 ++ = F_33 ( V_64 , V_65 ) ;
switch ( V_22 -> V_26 ) {
case V_27 + V_57 :
* V_25 = F_34 ( F_10 ) ;
break;
case V_27 + V_58 :
* V_25 = F_34 ( F_12 ) ;
break;
case V_27 + V_59 :
* V_25 = F_34 ( F_15 ) ;
break;
case V_27 + V_60 :
* V_25 = F_34 ( F_17 ) ;
break;
case V_27 + V_61 :
* V_25 = F_34 ( F_19 ) ;
break;
}
break;
case V_27 + V_66 :
* V_25 = F_35 ( V_67 , V_31 , V_65 ) ;
break;
default:
F_36 ( F_37 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_24 = V_25 ;
return true ;
}
int F_38 ( struct V_21 * V_68 , int V_18 ,
struct V_23 * V_69 , int * V_70 )
{
int V_71 = 0 , V_72 = 0 , V_73 , V_74 ;
struct V_23 * V_75 ;
struct V_21 * V_22 ;
int * V_76 = NULL ;
T_2 V_77 ;
F_22 ( V_78 * sizeof( V_79 ) > V_80 ) ;
F_22 ( V_81 + 1 != V_82 ) ;
if ( V_18 <= 0 || V_18 > V_83 )
return - V_84 ;
if ( V_69 ) {
V_76 = F_39 ( V_18 , sizeof( * V_76 ) , V_85 ) ;
if ( ! V_76 )
return - V_8 ;
}
V_86:
V_75 = V_69 ;
V_22 = V_68 ;
if ( V_75 )
* V_75 = F_33 ( V_32 , V_62 ) ;
V_75 ++ ;
for ( V_74 = 0 ; V_74 < V_18 ; V_22 ++ , V_74 ++ ) {
struct V_23 V_87 [ 6 ] = { } ;
struct V_23 * V_25 = V_87 ;
if ( V_76 )
V_76 [ V_74 ] = V_75 - V_69 ;
switch ( V_22 -> V_88 ) {
case V_89 | V_90 | V_91 :
case V_89 | V_90 | V_92 :
case V_89 | V_93 | V_91 :
case V_89 | V_93 | V_92 :
case V_89 | V_36 | V_91 :
case V_89 | V_36 | V_92 :
case V_89 | V_94 | V_91 :
case V_89 | V_94 | V_92 :
case V_89 | V_95 | V_91 :
case V_89 | V_95 | V_92 :
case V_89 | V_38 | V_91 :
case V_89 | V_38 | V_92 :
case V_89 | V_67 | V_91 :
case V_89 | V_67 | V_92 :
case V_89 | V_96 | V_91 :
case V_89 | V_96 | V_92 :
case V_89 | V_97 | V_91 :
case V_89 | V_97 | V_92 :
case V_89 | V_98 | V_91 :
case V_89 | V_98 | V_92 :
case V_89 | V_99 :
case V_100 | V_101 | V_46 :
case V_100 | V_101 | V_30 :
case V_100 | V_101 | V_35 :
case V_100 | V_102 | V_46 :
case V_100 | V_102 | V_30 :
case V_100 | V_102 | V_35 :
if ( F_40 ( V_22 -> V_88 ) == V_100 &&
F_41 ( V_22 -> V_88 ) == V_101 &&
F_21 ( V_22 , & V_25 ) )
break;
* V_25 = F_42 ( V_22 -> V_88 , V_31 , V_65 , 0 , V_22 -> V_26 ) ;
break;
#define F_43 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_103 | V_104 :
V_73 = V_74 + V_22 -> V_26 + 1 ;
V_25 -> V_88 = V_22 -> V_88 ;
F_43 ;
break;
case V_103 | V_105 | V_92 :
case V_103 | V_105 | V_91 :
case V_103 | V_106 | V_92 :
case V_103 | V_106 | V_91 :
case V_103 | V_107 | V_92 :
case V_103 | V_107 | V_91 :
case V_103 | V_108 | V_92 :
case V_103 | V_108 | V_91 :
if ( F_44 ( V_22 -> V_88 ) == V_92 && ( int ) V_22 -> V_26 < 0 ) {
* V_25 ++ = F_45 ( V_44 , V_22 -> V_26 ) ;
V_25 -> V_109 = V_31 ;
V_25 -> V_110 = V_44 ;
V_77 = V_91 ;
} else {
V_25 -> V_109 = V_31 ;
V_25 -> V_110 = V_65 ;
V_25 -> V_111 = V_22 -> V_26 ;
V_77 = F_44 ( V_22 -> V_88 ) ;
}
if ( V_22 -> V_112 == 0 ) {
V_25 -> V_88 = V_103 | F_46 ( V_22 -> V_88 ) | V_77 ;
V_73 = V_74 + V_22 -> V_113 + 1 ;
F_43 ;
break;
}
if ( V_22 -> V_113 == 0 && F_46 ( V_22 -> V_88 ) == V_105 ) {
V_25 -> V_88 = V_103 | V_45 | V_77 ;
V_73 = V_74 + V_22 -> V_112 + 1 ;
F_43 ;
break;
}
V_73 = V_74 + V_22 -> V_113 + 1 ;
V_25 -> V_88 = V_103 | F_46 ( V_22 -> V_88 ) | V_77 ;
F_43 ;
V_25 ++ ;
V_25 -> V_88 = V_103 | V_104 ;
V_73 = V_74 + V_22 -> V_112 + 1 ;
F_43 ;
break;
case V_114 | V_115 | V_35 :
* V_25 ++ = F_33 ( V_44 , V_31 ) ;
* V_25 ++ = F_47 ( V_35 , V_22 -> V_26 ) ;
* V_25 ++ = F_28 ( V_36 , V_31 , 0xf ) ;
* V_25 ++ = F_28 ( V_95 , V_31 , 2 ) ;
* V_25 ++ = F_33 ( V_65 , V_31 ) ;
* V_25 = F_33 ( V_31 , V_44 ) ;
break;
case V_116 | V_117 :
case V_116 | V_92 :
* V_25 ++ = F_48 ( F_49 ( V_22 -> V_88 ) == V_92 ?
V_92 : V_91 , V_118 ,
V_31 , V_22 -> V_26 ) ;
* V_25 = F_32 () ;
break;
case V_119 :
case V_120 :
* V_25 = F_50 ( V_46 , V_81 , F_40 ( V_22 -> V_88 ) ==
V_119 ? V_31 : V_65 ,
- ( V_78 - V_22 -> V_26 ) * 4 ) ;
break;
case V_100 | V_121 :
case V_114 | V_121 :
* V_25 = F_24 ( V_46 , F_40 ( V_22 -> V_88 ) == V_100 ?
V_31 : V_65 , V_81 ,
- ( V_78 - V_22 -> V_26 ) * 4 ) ;
break;
case V_100 | V_122 :
case V_114 | V_122 :
* V_25 = F_45 ( F_40 ( V_22 -> V_88 ) == V_100 ?
V_31 : V_65 , V_22 -> V_26 ) ;
break;
case V_123 | V_124 :
* V_25 = F_33 ( V_65 , V_31 ) ;
break;
case V_123 | V_125 :
* V_25 = F_33 ( V_31 , V_65 ) ;
break;
case V_100 | V_46 | V_126 :
case V_114 | V_46 | V_126 :
* V_25 = F_24 ( V_46 , F_40 ( V_22 -> V_88 ) == V_100 ?
V_31 : V_65 , V_32 ,
F_25 ( struct V_3 , V_18 ) ) ;
break;
case V_114 | V_101 | V_46 :
* V_25 = F_24 ( V_46 , V_31 , V_32 , V_22 -> V_26 ) ;
break;
default:
goto V_5;
}
V_25 ++ ;
if ( V_69 )
memcpy ( V_75 , V_87 ,
sizeof( * V_25 ) * ( V_25 - V_87 ) ) ;
V_75 += V_25 - V_87 ;
}
if ( ! V_69 ) {
* V_70 = V_75 - V_69 ;
return 0 ;
}
V_72 ++ ;
if ( V_71 != V_75 - V_69 ) {
V_71 = V_75 - V_69 ;
if ( V_72 > 2 )
goto V_5;
goto V_86;
}
F_51 ( V_76 ) ;
F_36 ( * V_70 != V_71 ) ;
return 0 ;
V_5:
F_51 ( V_76 ) ;
return - V_84 ;
}
static int F_52 ( const struct V_21 * V_6 , int V_127 )
{
T_3 * V_128 , V_129 = 0 ;
int V_130 , V_131 = 0 ;
F_22 ( V_78 > 16 ) ;
V_128 = F_53 ( V_127 , sizeof( * V_128 ) , V_85 ) ;
if ( ! V_128 )
return - V_8 ;
memset ( V_128 , 0xff , V_127 * sizeof( * V_128 ) ) ;
for ( V_130 = 0 ; V_130 < V_127 ; V_130 ++ ) {
V_129 &= V_128 [ V_130 ] ;
switch ( V_6 [ V_130 ] . V_88 ) {
case V_119 :
case V_120 :
V_129 |= ( 1 << V_6 [ V_130 ] . V_26 ) ;
break;
case V_100 | V_121 :
case V_114 | V_121 :
if ( ! ( V_129 & ( 1 << V_6 [ V_130 ] . V_26 ) ) ) {
V_131 = - V_84 ;
goto error;
}
break;
case V_103 | V_104 :
V_128 [ V_130 + 1 + V_6 [ V_130 ] . V_26 ] &= V_129 ;
V_129 = ~ 0 ;
break;
case V_103 | V_105 | V_92 :
case V_103 | V_105 | V_91 :
case V_103 | V_108 | V_92 :
case V_103 | V_108 | V_91 :
case V_103 | V_107 | V_92 :
case V_103 | V_107 | V_91 :
case V_103 | V_106 | V_92 :
case V_103 | V_106 | V_91 :
V_128 [ V_130 + 1 + V_6 [ V_130 ] . V_113 ] &= V_129 ;
V_128 [ V_130 + 1 + V_6 [ V_130 ] . V_112 ] &= V_129 ;
V_129 = ~ 0 ;
break;
}
}
error:
F_51 ( V_128 ) ;
return V_131 ;
}
static bool F_54 ( T_3 V_132 )
{
static const bool V_133 [] = {
[ V_89 | V_90 | V_92 ] = true ,
[ V_89 | V_90 | V_91 ] = true ,
[ V_89 | V_93 | V_92 ] = true ,
[ V_89 | V_93 | V_91 ] = true ,
[ V_89 | V_96 | V_92 ] = true ,
[ V_89 | V_96 | V_91 ] = true ,
[ V_89 | V_97 | V_92 ] = true ,
[ V_89 | V_97 | V_91 ] = true ,
[ V_89 | V_98 | V_92 ] = true ,
[ V_89 | V_98 | V_91 ] = true ,
[ V_89 | V_36 | V_92 ] = true ,
[ V_89 | V_36 | V_91 ] = true ,
[ V_89 | V_94 | V_92 ] = true ,
[ V_89 | V_94 | V_91 ] = true ,
[ V_89 | V_67 | V_92 ] = true ,
[ V_89 | V_67 | V_91 ] = true ,
[ V_89 | V_95 | V_92 ] = true ,
[ V_89 | V_95 | V_91 ] = true ,
[ V_89 | V_38 | V_92 ] = true ,
[ V_89 | V_38 | V_91 ] = true ,
[ V_89 | V_99 ] = true ,
[ V_100 | V_46 | V_101 ] = true ,
[ V_100 | V_30 | V_101 ] = true ,
[ V_100 | V_35 | V_101 ] = true ,
[ V_100 | V_46 | V_126 ] = true ,
[ V_100 | V_46 | V_102 ] = true ,
[ V_100 | V_30 | V_102 ] = true ,
[ V_100 | V_35 | V_102 ] = true ,
[ V_100 | V_122 ] = true ,
[ V_100 | V_121 ] = true ,
[ V_114 | V_46 | V_126 ] = true ,
[ V_114 | V_35 | V_115 ] = true ,
[ V_114 | V_122 ] = true ,
[ V_114 | V_121 ] = true ,
[ V_119 ] = true ,
[ V_120 ] = true ,
[ V_123 | V_124 ] = true ,
[ V_123 | V_125 ] = true ,
[ V_116 | V_92 ] = true ,
[ V_116 | V_117 ] = true ,
[ V_103 | V_104 ] = true ,
[ V_103 | V_105 | V_92 ] = true ,
[ V_103 | V_105 | V_91 ] = true ,
[ V_103 | V_108 | V_92 ] = true ,
[ V_103 | V_108 | V_91 ] = true ,
[ V_103 | V_107 | V_92 ] = true ,
[ V_103 | V_107 | V_91 ] = true ,
[ V_103 | V_106 | V_92 ] = true ,
[ V_103 | V_106 | V_91 ] = true ,
} ;
if ( V_132 >= F_55 ( V_133 ) )
return false ;
return V_133 [ V_132 ] ;
}
int F_56 ( const struct V_21 * V_6 , unsigned int V_127 )
{
bool V_134 ;
int V_130 ;
if ( V_127 == 0 || V_127 > V_83 )
return - V_84 ;
for ( V_130 = 0 ; V_130 < V_127 ; V_130 ++ ) {
const struct V_21 * V_135 = & V_6 [ V_130 ] ;
if ( ! F_54 ( V_135 -> V_88 ) )
return - V_84 ;
switch ( V_135 -> V_88 ) {
case V_89 | V_97 | V_92 :
case V_89 | V_98 | V_92 :
if ( V_135 -> V_26 == 0 )
return - V_84 ;
break;
case V_100 | V_121 :
case V_114 | V_121 :
case V_119 :
case V_120 :
if ( V_135 -> V_26 >= V_78 )
return - V_84 ;
break;
case V_103 | V_104 :
if ( V_135 -> V_26 >= ( unsigned int ) ( V_127 - V_130 - 1 ) )
return - V_84 ;
break;
case V_103 | V_105 | V_92 :
case V_103 | V_105 | V_91 :
case V_103 | V_108 | V_92 :
case V_103 | V_108 | V_91 :
case V_103 | V_107 | V_92 :
case V_103 | V_107 | V_91 :
case V_103 | V_106 | V_92 :
case V_103 | V_106 | V_91 :
if ( V_130 + V_135 -> V_113 + 1 >= V_127 ||
V_130 + V_135 -> V_112 + 1 >= V_127 )
return - V_84 ;
break;
case V_100 | V_46 | V_101 :
case V_100 | V_30 | V_101 :
case V_100 | V_35 | V_101 :
V_134 = false ;
if ( F_57 ( V_135 ) & V_136 )
V_134 = true ;
if ( V_134 == false && V_135 -> V_26 >= V_27 )
return - V_84 ;
}
}
switch ( V_6 [ V_127 - 1 ] . V_88 ) {
case V_116 | V_92 :
case V_116 | V_117 :
return F_52 ( V_6 , V_127 ) ;
}
return - V_84 ;
}
static int F_58 ( struct V_137 * V_22 ,
const struct V_138 * V_139 )
{
unsigned int V_140 = F_59 ( V_139 ) ;
struct V_141 * V_142 ;
V_22 -> V_143 = F_60 ( sizeof( * V_142 ) , V_85 ) ;
if ( ! V_22 -> V_143 )
return - V_8 ;
V_142 = V_22 -> V_143 ;
V_142 -> V_18 = V_139 -> V_18 ;
V_142 -> V_6 = F_61 ( V_22 -> V_144 , V_140 , V_85 ) ;
if ( ! V_142 -> V_6 ) {
F_51 ( V_22 -> V_143 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_62 ( struct V_137 * V_22 )
{
struct V_141 * V_139 = V_22 -> V_143 ;
if ( V_139 ) {
F_51 ( V_139 -> V_6 ) ;
F_51 ( V_139 ) ;
}
}
static void F_63 ( struct V_137 * V_68 )
{
if ( V_68 -> V_145 -> V_146 == V_147 ) {
F_64 ( V_68 ) ;
} else {
F_62 ( V_68 ) ;
F_65 ( V_68 ) ;
}
}
static void F_66 ( struct F_1 * V_22 )
{
F_63 ( V_22 -> V_68 ) ;
F_51 ( V_22 ) ;
}
static void F_67 ( struct V_148 * V_149 )
{
struct F_1 * V_22 = F_68 ( V_149 , struct F_1 , V_149 ) ;
F_66 ( V_22 ) ;
}
static void F_69 ( struct F_1 * V_22 )
{
if ( F_70 ( & V_22 -> V_150 ) )
F_71 ( & V_22 -> V_149 , F_67 ) ;
}
void F_72 ( struct V_1 * V_2 , struct F_1 * V_22 )
{
V_79 V_151 = F_73 ( V_22 -> V_68 -> V_18 ) ;
F_74 ( V_151 , & V_2 -> V_152 ) ;
F_69 ( V_22 ) ;
}
bool F_75 ( struct V_1 * V_2 , struct F_1 * V_22 )
{
V_79 V_151 = F_73 ( V_22 -> V_68 -> V_18 ) ;
if ( V_151 <= V_153 &&
F_76 ( & V_2 -> V_152 ) + V_151 < V_153 ) {
F_77 ( & V_22 -> V_150 ) ;
F_78 ( V_151 , & V_2 -> V_152 ) ;
return true ;
}
return false ;
}
static struct V_137 * F_79 ( struct V_137 * V_22 )
{
struct V_21 * V_154 ;
struct V_137 * V_155 ;
int V_5 , V_70 , V_156 = V_22 -> V_18 ;
F_22 ( sizeof( struct V_21 ) !=
sizeof( struct V_23 ) ) ;
V_154 = F_61 ( V_22 -> V_144 , V_156 * sizeof( struct V_21 ) ,
V_85 ) ;
if ( ! V_154 ) {
V_5 = - V_8 ;
goto V_157;
}
V_5 = F_38 ( V_154 , V_156 , NULL , & V_70 ) ;
if ( V_5 )
goto V_158;
V_155 = V_22 ;
V_22 = F_80 ( V_155 , F_73 ( V_70 ) , 0 ) ;
if ( ! V_22 ) {
V_22 = V_155 ;
V_5 = - V_8 ;
goto V_158;
}
V_22 -> V_18 = V_70 ;
V_5 = F_38 ( V_154 , V_156 , V_22 -> V_159 , & V_70 ) ;
if ( V_5 )
goto V_158;
F_81 ( V_22 ) ;
F_51 ( V_154 ) ;
return V_22 ;
V_158:
F_51 ( V_154 ) ;
V_157:
F_63 ( V_22 ) ;
return F_82 ( V_5 ) ;
}
static struct V_137 * F_83 ( struct V_137 * V_22 )
{
int V_5 ;
V_22 -> V_160 = NULL ;
V_22 -> V_161 = false ;
V_5 = F_56 ( V_22 -> V_144 , V_22 -> V_18 ) ;
if ( V_5 ) {
F_63 ( V_22 ) ;
return F_82 ( V_5 ) ;
}
F_84 ( V_22 ) ;
if ( ! V_22 -> V_161 )
V_22 = F_79 ( V_22 ) ;
return V_22 ;
}
int F_85 ( struct V_137 * * V_162 , struct V_141 * V_139 )
{
unsigned int V_140 = F_59 ( V_139 ) ;
struct V_137 * V_22 ;
if ( V_139 -> V_6 == NULL )
return - V_84 ;
V_22 = F_86 ( F_73 ( V_139 -> V_18 ) , 0 ) ;
if ( ! V_22 )
return - V_8 ;
memcpy ( V_22 -> V_144 , V_139 -> V_6 , V_140 ) ;
V_22 -> V_18 = V_139 -> V_18 ;
V_22 -> V_143 = NULL ;
V_22 = F_83 ( V_22 ) ;
if ( F_87 ( V_22 ) )
return F_88 ( V_22 ) ;
* V_162 = V_22 ;
return 0 ;
}
void F_89 ( struct V_137 * V_22 )
{
F_63 ( V_22 ) ;
}
int F_90 ( struct V_138 * V_139 , struct V_1 * V_2 )
{
struct F_1 * V_22 , * V_155 ;
unsigned int V_140 = F_59 ( V_139 ) ;
unsigned int V_163 = F_73 ( V_139 -> V_18 ) ;
struct V_137 * V_68 ;
int V_5 ;
if ( F_3 ( V_2 , V_164 ) )
return - V_10 ;
if ( V_139 -> V_6 == NULL )
return - V_84 ;
V_68 = F_86 ( V_163 , 0 ) ;
if ( ! V_68 )
return - V_8 ;
if ( F_91 ( V_68 -> V_144 , V_139 -> V_6 , V_140 ) ) {
F_92 ( V_68 ) ;
return - V_165 ;
}
V_68 -> V_18 = V_139 -> V_18 ;
V_5 = F_58 ( V_68 , V_139 ) ;
if ( V_5 ) {
F_92 ( V_68 ) ;
return - V_8 ;
}
V_68 = F_83 ( V_68 ) ;
if ( F_87 ( V_68 ) )
return F_88 ( V_68 ) ;
V_22 = F_60 ( sizeof( * V_22 ) , V_85 ) ;
if ( ! V_22 ) {
F_63 ( V_68 ) ;
return - V_8 ;
}
V_22 -> V_68 = V_68 ;
F_93 ( & V_22 -> V_150 , 0 ) ;
if ( ! F_75 ( V_2 , V_22 ) ) {
F_66 ( V_22 ) ;
return - V_8 ;
}
V_155 = F_94 ( V_2 -> F_1 ,
F_95 ( V_2 ) ) ;
F_96 ( V_2 -> F_1 , V_22 ) ;
if ( V_155 )
F_72 ( V_2 , V_155 ) ;
return 0 ;
}
int F_97 ( V_79 V_166 , struct V_1 * V_2 )
{
struct F_1 * V_22 , * V_155 ;
struct V_137 * V_68 ;
if ( F_3 ( V_2 , V_164 ) )
return - V_10 ;
V_68 = F_98 ( V_166 ) ;
if ( F_87 ( V_68 ) )
return F_88 ( V_68 ) ;
if ( V_68 -> V_145 -> V_146 != V_147 ) {
F_64 ( V_68 ) ;
return - V_84 ;
}
V_22 = F_60 ( sizeof( * V_22 ) , V_85 ) ;
if ( ! V_22 ) {
F_64 ( V_68 ) ;
return - V_8 ;
}
V_22 -> V_68 = V_68 ;
F_93 ( & V_22 -> V_150 , 0 ) ;
if ( ! F_75 ( V_2 , V_22 ) ) {
F_66 ( V_22 ) ;
return - V_8 ;
}
V_155 = F_94 ( V_2 -> F_1 ,
F_95 ( V_2 ) ) ;
F_96 ( V_2 -> F_1 , V_22 ) ;
if ( V_155 )
F_72 ( V_2 , V_155 ) ;
return 0 ;
}
static const struct V_167 * F_99 ( enum V_168 V_169 )
{
switch ( V_169 ) {
case V_170 :
return & V_171 ;
case V_172 :
return & V_173 ;
case V_174 :
return & V_175 ;
default:
return NULL ;
}
}
static bool F_100 ( int V_176 , int V_177 , enum V_178 type )
{
return false ;
}
static int T_4 F_101 ( void )
{
F_102 ( & V_179 ) ;
return 0 ;
}
int F_97 ( V_79 V_166 , struct V_1 * V_2 )
{
return - V_180 ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_131 = - V_181 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_164 ) )
return - V_10 ;
V_6 = F_94 ( V_2 -> F_1 ,
F_95 ( V_2 ) ) ;
if ( V_6 ) {
F_104 ( V_2 -> F_1 , NULL ) ;
F_72 ( V_2 , V_6 ) ;
V_131 = 0 ;
}
return V_131 ;
}
int F_105 ( struct V_1 * V_2 , struct V_21 T_5 * V_182 ,
unsigned int V_18 )
{
struct V_141 * V_139 ;
struct F_1 * V_6 ;
int V_131 = 0 ;
F_106 ( V_2 ) ;
V_6 = F_94 ( V_2 -> F_1 ,
F_95 ( V_2 ) ) ;
if ( ! V_6 )
goto V_183;
V_139 = V_6 -> V_68 -> V_143 ;
V_131 = V_139 -> V_18 ;
if ( ! V_18 )
goto V_183;
V_131 = - V_84 ;
if ( V_18 < V_139 -> V_18 )
goto V_183;
V_131 = - V_165 ;
if ( F_107 ( V_182 , V_139 -> V_6 , F_59 ( V_139 ) ) )
goto V_183;
V_131 = V_139 -> V_18 ;
V_183:
F_108 ( V_2 ) ;
return V_131 ;
}
