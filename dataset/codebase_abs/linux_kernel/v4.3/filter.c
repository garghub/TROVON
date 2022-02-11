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
static T_2 F_21 ( int V_21 , int V_22 , int V_23 ,
struct V_24 * V_25 )
{
struct V_24 * V_26 = V_25 ;
switch ( V_21 ) {
case V_27 :
F_22 ( F_23 ( struct V_3 , V_28 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_28 ) ) ;
break;
case V_30 :
* V_26 ++ = F_24 ( V_31 , V_22 , V_23 , F_26 () ) ;
* V_26 ++ = F_27 ( V_32 , V_22 , V_33 ) ;
#ifdef F_28
* V_26 ++ = F_27 ( V_34 , V_22 , 5 ) ;
#endif
break;
case V_35 :
F_22 ( F_23 ( struct V_3 , V_36 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_36 ) ) ;
break;
case V_38 :
case V_39 :
F_22 ( F_23 ( struct V_3 , V_40 ) != 2 ) ;
F_22 ( V_41 != 0x1000 ) ;
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_40 ) ) ;
if ( V_21 == V_38 ) {
* V_26 ++ = F_27 ( V_32 , V_22 ,
~ V_41 ) ;
} else {
* V_26 ++ = F_27 ( V_34 , V_22 , 12 ) ;
* V_26 ++ = F_27 ( V_32 , V_22 , 1 ) ;
}
break;
}
return V_26 - V_25 ;
}
static bool F_29 ( struct V_42 * V_43 ,
struct V_24 * * V_44 )
{
struct V_24 * V_26 = * V_44 ;
T_2 V_45 ;
switch ( V_43 -> V_46 ) {
case V_47 + V_48 :
F_22 ( F_23 ( struct V_3 , V_49 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_50 , V_51 ,
F_25 ( struct V_3 , V_49 ) ) ;
* V_26 = F_30 ( V_52 , V_50 , 16 ) ;
break;
case V_47 + V_30 :
V_45 = F_21 ( V_30 , V_50 , V_51 , V_26 ) ;
V_26 += V_45 - 1 ;
break;
case V_47 + V_53 :
case V_47 + V_54 :
F_22 ( F_23 ( struct V_55 , V_56 ) != 4 ) ;
F_22 ( F_23 ( struct V_55 , type ) != 2 ) ;
F_22 ( F_31 ( F_23 ( struct V_3 , V_57 ) ) < 0 ) ;
* V_26 ++ = F_24 ( F_31 ( F_23 ( struct V_3 , V_57 ) ) ,
V_58 , V_51 ,
F_25 ( struct V_3 , V_57 ) ) ;
* V_26 ++ = F_32 ( V_59 , V_58 , 0 , 1 ) ;
* V_26 ++ = F_33 () ;
if ( V_43 -> V_46 == V_47 + V_53 )
* V_26 = F_24 ( V_29 , V_50 , V_58 ,
F_25 ( struct V_55 , V_56 ) ) ;
else
* V_26 = F_24 ( V_37 , V_50 , V_58 ,
F_25 ( struct V_55 , type ) ) ;
break;
case V_47 + V_27 :
V_45 = F_21 ( V_27 , V_50 , V_51 , V_26 ) ;
V_26 += V_45 - 1 ;
break;
case V_47 + V_60 :
F_22 ( F_23 ( struct V_3 , V_61 ) != 4 ) ;
* V_26 = F_24 ( V_29 , V_50 , V_51 ,
F_25 ( struct V_3 , V_61 ) ) ;
break;
case V_47 + V_35 :
V_45 = F_21 ( V_35 , V_50 , V_51 , V_26 ) ;
V_26 += V_45 - 1 ;
break;
case V_47 + V_38 :
V_45 = F_21 ( V_38 ,
V_50 , V_51 , V_26 ) ;
V_26 += V_45 - 1 ;
break;
case V_47 + V_39 :
V_45 = F_21 ( V_39 ,
V_50 , V_51 , V_26 ) ;
V_26 += V_45 - 1 ;
break;
case V_47 + V_62 :
F_22 ( F_23 ( struct V_3 , V_63 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_50 , V_51 ,
F_25 ( struct V_3 , V_63 ) ) ;
* V_26 = F_30 ( V_52 , V_50 , 16 ) ;
break;
case V_47 + V_64 :
case V_47 + V_65 :
case V_47 + V_66 :
case V_47 + V_67 :
case V_47 + V_68 :
* V_26 ++ = F_34 ( V_69 , V_51 ) ;
* V_26 ++ = F_34 ( V_70 , V_50 ) ;
* V_26 ++ = F_34 ( V_71 , V_72 ) ;
switch ( V_43 -> V_46 ) {
case V_47 + V_64 :
* V_26 = F_35 ( F_10 ) ;
break;
case V_47 + V_65 :
* V_26 = F_35 ( F_12 ) ;
break;
case V_47 + V_66 :
* V_26 = F_35 ( F_15 ) ;
break;
case V_47 + V_67 :
* V_26 = F_35 ( F_17 ) ;
break;
case V_47 + V_68 :
* V_26 = F_35 ( F_19 ) ;
break;
}
break;
case V_47 + V_73 :
* V_26 = F_36 ( V_74 , V_50 , V_72 ) ;
break;
default:
F_37 ( F_38 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_44 = V_26 ;
return true ;
}
static int F_39 ( struct V_42 * V_75 , int V_18 ,
struct V_24 * V_76 , int * V_77 )
{
int V_78 = 0 , V_79 = 0 , V_80 , V_81 ;
struct V_24 * V_82 ;
struct V_42 * V_43 ;
int * V_83 = NULL ;
T_3 V_84 ;
F_22 ( V_85 * sizeof( T_2 ) > V_86 ) ;
F_22 ( V_87 + 1 != V_88 ) ;
if ( V_18 <= 0 || V_18 > V_89 )
return - V_90 ;
if ( V_76 ) {
V_83 = F_40 ( V_18 , sizeof( * V_83 ) ,
V_91 | V_92 ) ;
if ( ! V_83 )
return - V_8 ;
}
V_93:
V_82 = V_76 ;
V_43 = V_75 ;
if ( V_82 )
* V_82 = F_34 ( V_51 , V_69 ) ;
V_82 ++ ;
for ( V_81 = 0 ; V_81 < V_18 ; V_43 ++ , V_81 ++ ) {
struct V_24 V_94 [ 6 ] = { } ;
struct V_24 * V_26 = V_94 ;
if ( V_83 )
V_83 [ V_81 ] = V_82 - V_76 ;
switch ( V_43 -> V_95 ) {
case V_96 | V_97 | V_98 :
case V_96 | V_97 | V_99 :
case V_96 | V_100 | V_98 :
case V_96 | V_100 | V_99 :
case V_96 | V_32 | V_98 :
case V_96 | V_32 | V_99 :
case V_96 | V_101 | V_98 :
case V_96 | V_101 | V_99 :
case V_96 | V_102 | V_98 :
case V_96 | V_102 | V_99 :
case V_96 | V_34 | V_98 :
case V_96 | V_34 | V_99 :
case V_96 | V_74 | V_98 :
case V_96 | V_74 | V_99 :
case V_96 | V_103 | V_98 :
case V_96 | V_103 | V_99 :
case V_96 | V_104 | V_98 :
case V_96 | V_104 | V_99 :
case V_96 | V_105 | V_98 :
case V_96 | V_105 | V_99 :
case V_96 | V_106 :
case V_107 | V_108 | V_29 :
case V_107 | V_108 | V_37 :
case V_107 | V_108 | V_31 :
case V_107 | V_109 | V_29 :
case V_107 | V_109 | V_37 :
case V_107 | V_109 | V_31 :
if ( F_41 ( V_43 -> V_95 ) == V_107 &&
F_42 ( V_43 -> V_95 ) == V_108 &&
F_29 ( V_43 , & V_26 ) )
break;
* V_26 = F_43 ( V_43 -> V_95 , V_50 , V_72 , 0 , V_43 -> V_46 ) ;
break;
#define F_44 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_110 | V_111 :
V_80 = V_81 + V_43 -> V_46 + 1 ;
V_26 -> V_95 = V_43 -> V_95 ;
F_44 ;
break;
case V_110 | V_112 | V_99 :
case V_110 | V_112 | V_98 :
case V_110 | V_113 | V_99 :
case V_110 | V_113 | V_98 :
case V_110 | V_114 | V_99 :
case V_110 | V_114 | V_98 :
case V_110 | V_115 | V_99 :
case V_110 | V_115 | V_98 :
if ( F_45 ( V_43 -> V_95 ) == V_99 && ( int ) V_43 -> V_46 < 0 ) {
* V_26 ++ = F_46 ( V_58 , V_43 -> V_46 ) ;
V_26 -> V_22 = V_50 ;
V_26 -> V_23 = V_58 ;
V_84 = V_98 ;
} else {
V_26 -> V_22 = V_50 ;
V_26 -> V_116 = V_43 -> V_46 ;
V_84 = F_45 ( V_43 -> V_95 ) ;
V_26 -> V_23 = V_84 == V_98 ? V_72 : 0 ;
}
if ( V_43 -> V_117 == 0 ) {
V_26 -> V_95 = V_110 | F_47 ( V_43 -> V_95 ) | V_84 ;
V_80 = V_81 + V_43 -> V_118 + 1 ;
F_44 ;
break;
}
if ( V_43 -> V_118 == 0 && F_47 ( V_43 -> V_95 ) == V_112 ) {
V_26 -> V_95 = V_110 | V_59 | V_84 ;
V_80 = V_81 + V_43 -> V_117 + 1 ;
F_44 ;
break;
}
V_80 = V_81 + V_43 -> V_118 + 1 ;
V_26 -> V_95 = V_110 | F_47 ( V_43 -> V_95 ) | V_84 ;
F_44 ;
V_26 ++ ;
V_26 -> V_95 = V_110 | V_111 ;
V_80 = V_81 + V_43 -> V_117 + 1 ;
F_44 ;
break;
case V_119 | V_120 | V_31 :
* V_26 ++ = F_34 ( V_58 , V_50 ) ;
* V_26 ++ = F_48 ( V_31 , V_43 -> V_46 ) ;
* V_26 ++ = F_27 ( V_32 , V_50 , 0xf ) ;
* V_26 ++ = F_27 ( V_102 , V_50 , 2 ) ;
* V_26 ++ = F_34 ( V_72 , V_50 ) ;
* V_26 = F_34 ( V_50 , V_58 ) ;
break;
case V_121 | V_122 :
case V_121 | V_99 :
* V_26 ++ = F_49 ( F_50 ( V_43 -> V_95 ) == V_99 ?
V_99 : V_98 , V_123 ,
V_50 , V_43 -> V_46 ) ;
* V_26 = F_33 () ;
break;
case V_124 :
case V_125 :
* V_26 = F_51 ( V_29 , V_87 , F_41 ( V_43 -> V_95 ) ==
V_124 ? V_50 : V_72 ,
- ( V_85 - V_43 -> V_46 ) * 4 ) ;
break;
case V_107 | V_126 :
case V_119 | V_126 :
* V_26 = F_24 ( V_29 , F_41 ( V_43 -> V_95 ) == V_107 ?
V_50 : V_72 , V_87 ,
- ( V_85 - V_43 -> V_46 ) * 4 ) ;
break;
case V_107 | V_127 :
case V_119 | V_127 :
* V_26 = F_46 ( F_41 ( V_43 -> V_95 ) == V_107 ?
V_50 : V_72 , V_43 -> V_46 ) ;
break;
case V_128 | V_129 :
* V_26 = F_34 ( V_72 , V_50 ) ;
break;
case V_128 | V_130 :
* V_26 = F_34 ( V_50 , V_72 ) ;
break;
case V_107 | V_29 | V_131 :
case V_119 | V_29 | V_131 :
* V_26 = F_24 ( V_29 , F_41 ( V_43 -> V_95 ) == V_107 ?
V_50 : V_72 , V_51 ,
F_25 ( struct V_3 , V_18 ) ) ;
break;
case V_119 | V_108 | V_29 :
* V_26 = F_24 ( V_29 , V_50 , V_51 , V_43 -> V_46 ) ;
break;
default:
goto V_5;
}
V_26 ++ ;
if ( V_76 )
memcpy ( V_82 , V_94 ,
sizeof( * V_26 ) * ( V_26 - V_94 ) ) ;
V_82 += V_26 - V_94 ;
}
if ( ! V_76 ) {
* V_77 = V_82 - V_76 ;
return 0 ;
}
V_79 ++ ;
if ( V_78 != V_82 - V_76 ) {
V_78 = V_82 - V_76 ;
if ( V_79 > 2 )
goto V_5;
goto V_93;
}
F_52 ( V_83 ) ;
F_37 ( * V_77 != V_78 ) ;
return 0 ;
V_5:
F_52 ( V_83 ) ;
return - V_90 ;
}
static int F_53 ( const struct V_42 * V_6 , int V_132 )
{
T_4 * V_133 , V_134 = 0 ;
int V_135 , V_136 = 0 ;
F_22 ( V_85 > 16 ) ;
V_133 = F_54 ( V_132 , sizeof( * V_133 ) , V_91 ) ;
if ( ! V_133 )
return - V_8 ;
memset ( V_133 , 0xff , V_132 * sizeof( * V_133 ) ) ;
for ( V_135 = 0 ; V_135 < V_132 ; V_135 ++ ) {
V_134 &= V_133 [ V_135 ] ;
switch ( V_6 [ V_135 ] . V_95 ) {
case V_124 :
case V_125 :
V_134 |= ( 1 << V_6 [ V_135 ] . V_46 ) ;
break;
case V_107 | V_126 :
case V_119 | V_126 :
if ( ! ( V_134 & ( 1 << V_6 [ V_135 ] . V_46 ) ) ) {
V_136 = - V_90 ;
goto error;
}
break;
case V_110 | V_111 :
V_133 [ V_135 + 1 + V_6 [ V_135 ] . V_46 ] &= V_134 ;
V_134 = ~ 0 ;
break;
case V_110 | V_112 | V_99 :
case V_110 | V_112 | V_98 :
case V_110 | V_115 | V_99 :
case V_110 | V_115 | V_98 :
case V_110 | V_114 | V_99 :
case V_110 | V_114 | V_98 :
case V_110 | V_113 | V_99 :
case V_110 | V_113 | V_98 :
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
static bool F_55 ( T_4 V_137 )
{
static const bool V_138 [] = {
[ V_96 | V_97 | V_99 ] = true ,
[ V_96 | V_97 | V_98 ] = true ,
[ V_96 | V_100 | V_99 ] = true ,
[ V_96 | V_100 | V_98 ] = true ,
[ V_96 | V_103 | V_99 ] = true ,
[ V_96 | V_103 | V_98 ] = true ,
[ V_96 | V_104 | V_99 ] = true ,
[ V_96 | V_104 | V_98 ] = true ,
[ V_96 | V_105 | V_99 ] = true ,
[ V_96 | V_105 | V_98 ] = true ,
[ V_96 | V_32 | V_99 ] = true ,
[ V_96 | V_32 | V_98 ] = true ,
[ V_96 | V_101 | V_99 ] = true ,
[ V_96 | V_101 | V_98 ] = true ,
[ V_96 | V_74 | V_99 ] = true ,
[ V_96 | V_74 | V_98 ] = true ,
[ V_96 | V_102 | V_99 ] = true ,
[ V_96 | V_102 | V_98 ] = true ,
[ V_96 | V_34 | V_99 ] = true ,
[ V_96 | V_34 | V_98 ] = true ,
[ V_96 | V_106 ] = true ,
[ V_107 | V_29 | V_108 ] = true ,
[ V_107 | V_37 | V_108 ] = true ,
[ V_107 | V_31 | V_108 ] = true ,
[ V_107 | V_29 | V_131 ] = true ,
[ V_107 | V_29 | V_109 ] = true ,
[ V_107 | V_37 | V_109 ] = true ,
[ V_107 | V_31 | V_109 ] = true ,
[ V_107 | V_127 ] = true ,
[ V_107 | V_126 ] = true ,
[ V_119 | V_29 | V_131 ] = true ,
[ V_119 | V_31 | V_120 ] = true ,
[ V_119 | V_127 ] = true ,
[ V_119 | V_126 ] = true ,
[ V_124 ] = true ,
[ V_125 ] = true ,
[ V_128 | V_129 ] = true ,
[ V_128 | V_130 ] = true ,
[ V_121 | V_99 ] = true ,
[ V_121 | V_122 ] = true ,
[ V_110 | V_111 ] = true ,
[ V_110 | V_112 | V_99 ] = true ,
[ V_110 | V_112 | V_98 ] = true ,
[ V_110 | V_115 | V_99 ] = true ,
[ V_110 | V_115 | V_98 ] = true ,
[ V_110 | V_114 | V_99 ] = true ,
[ V_110 | V_114 | V_98 ] = true ,
[ V_110 | V_113 | V_99 ] = true ,
[ V_110 | V_113 | V_98 ] = true ,
} ;
if ( V_137 >= F_56 ( V_138 ) )
return false ;
return V_138 [ V_137 ] ;
}
static int F_57 ( const struct V_42 * V_6 ,
unsigned int V_132 )
{
bool V_139 ;
int V_135 ;
if ( V_132 == 0 || V_132 > V_89 )
return - V_90 ;
for ( V_135 = 0 ; V_135 < V_132 ; V_135 ++ ) {
const struct V_42 * V_140 = & V_6 [ V_135 ] ;
if ( ! F_55 ( V_140 -> V_95 ) )
return - V_90 ;
switch ( V_140 -> V_95 ) {
case V_96 | V_104 | V_99 :
case V_96 | V_105 | V_99 :
if ( V_140 -> V_46 == 0 )
return - V_90 ;
break;
case V_107 | V_126 :
case V_119 | V_126 :
case V_124 :
case V_125 :
if ( V_140 -> V_46 >= V_85 )
return - V_90 ;
break;
case V_110 | V_111 :
if ( V_140 -> V_46 >= ( unsigned int ) ( V_132 - V_135 - 1 ) )
return - V_90 ;
break;
case V_110 | V_112 | V_99 :
case V_110 | V_112 | V_98 :
case V_110 | V_115 | V_99 :
case V_110 | V_115 | V_98 :
case V_110 | V_114 | V_99 :
case V_110 | V_114 | V_98 :
case V_110 | V_113 | V_99 :
case V_110 | V_113 | V_98 :
if ( V_135 + V_140 -> V_118 + 1 >= V_132 ||
V_135 + V_140 -> V_117 + 1 >= V_132 )
return - V_90 ;
break;
case V_107 | V_29 | V_108 :
case V_107 | V_37 | V_108 :
case V_107 | V_31 | V_108 :
V_139 = false ;
if ( F_58 ( V_140 ) & V_141 )
V_139 = true ;
if ( V_139 == false && V_140 -> V_46 >= V_47 )
return - V_90 ;
}
}
switch ( V_6 [ V_132 - 1 ] . V_95 ) {
case V_121 | V_99 :
case V_121 | V_122 :
return F_53 ( V_6 , V_132 ) ;
}
return - V_90 ;
}
static int F_59 ( struct V_142 * V_43 ,
const struct V_143 * V_144 )
{
unsigned int V_145 = F_60 ( V_144 ) ;
struct V_146 * V_147 ;
V_43 -> V_148 = F_61 ( sizeof( * V_147 ) , V_91 ) ;
if ( ! V_43 -> V_148 )
return - V_8 ;
V_147 = V_43 -> V_148 ;
V_147 -> V_18 = V_144 -> V_18 ;
V_147 -> V_6 = F_62 ( V_43 -> V_149 , V_145 ,
V_91 | V_92 ) ;
if ( ! V_147 -> V_6 ) {
F_52 ( V_43 -> V_148 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_63 ( struct V_142 * V_43 )
{
struct V_146 * V_144 = V_43 -> V_148 ;
if ( V_144 ) {
F_52 ( V_144 -> V_6 ) ;
F_52 ( V_144 ) ;
}
}
static void F_64 ( struct V_142 * V_75 )
{
if ( V_75 -> type == V_150 ) {
F_65 ( V_75 ) ;
} else {
F_63 ( V_75 ) ;
F_66 ( V_75 ) ;
}
}
static void F_67 ( struct F_1 * V_43 )
{
F_64 ( V_43 -> V_75 ) ;
F_52 ( V_43 ) ;
}
static void F_68 ( struct V_151 * V_152 )
{
struct F_1 * V_43 = F_69 ( V_152 , struct F_1 , V_152 ) ;
F_67 ( V_43 ) ;
}
static void F_70 ( struct F_1 * V_43 )
{
if ( F_71 ( & V_43 -> V_153 ) )
F_72 ( & V_43 -> V_152 , F_68 ) ;
}
void F_73 ( struct V_1 * V_2 , struct F_1 * V_43 )
{
T_2 V_154 = F_74 ( V_43 -> V_75 -> V_18 ) ;
F_75 ( V_154 , & V_2 -> V_155 ) ;
F_70 ( V_43 ) ;
}
bool F_76 ( struct V_1 * V_2 , struct F_1 * V_43 )
{
T_2 V_154 = F_74 ( V_43 -> V_75 -> V_18 ) ;
if ( V_154 <= V_156 &&
F_77 ( & V_2 -> V_155 ) + V_154 < V_156 ) {
F_78 ( & V_43 -> V_153 ) ;
F_79 ( V_154 , & V_2 -> V_155 ) ;
return true ;
}
return false ;
}
static struct V_142 * F_80 ( struct V_142 * V_43 )
{
struct V_42 * V_157 ;
struct V_142 * V_158 ;
int V_5 , V_77 , V_159 = V_43 -> V_18 ;
F_22 ( sizeof( struct V_42 ) !=
sizeof( struct V_24 ) ) ;
V_157 = F_62 ( V_43 -> V_149 , V_159 * sizeof( struct V_42 ) ,
V_91 | V_92 ) ;
if ( ! V_157 ) {
V_5 = - V_8 ;
goto V_160;
}
V_5 = F_39 ( V_157 , V_159 , NULL , & V_77 ) ;
if ( V_5 )
goto V_161;
V_158 = V_43 ;
V_43 = F_81 ( V_158 , F_74 ( V_77 ) , 0 ) ;
if ( ! V_43 ) {
V_43 = V_158 ;
V_5 = - V_8 ;
goto V_161;
}
V_43 -> V_18 = V_77 ;
V_5 = F_39 ( V_157 , V_159 , V_43 -> V_162 , & V_77 ) ;
if ( V_5 )
goto V_161;
F_82 ( V_43 ) ;
F_52 ( V_157 ) ;
return V_43 ;
V_161:
F_52 ( V_157 ) ;
V_160:
F_64 ( V_43 ) ;
return F_83 ( V_5 ) ;
}
static struct V_142 * F_84 ( struct V_142 * V_43 ,
T_5 V_163 )
{
int V_5 ;
V_43 -> V_164 = NULL ;
V_43 -> V_165 = false ;
V_5 = F_57 ( V_43 -> V_149 , V_43 -> V_18 ) ;
if ( V_5 ) {
F_64 ( V_43 ) ;
return F_83 ( V_5 ) ;
}
if ( V_163 ) {
V_5 = V_163 ( V_43 -> V_149 , V_43 -> V_18 ) ;
if ( V_5 ) {
F_64 ( V_43 ) ;
return F_83 ( V_5 ) ;
}
}
F_85 ( V_43 ) ;
if ( ! V_43 -> V_165 )
V_43 = F_80 ( V_43 ) ;
return V_43 ;
}
int F_86 ( struct V_142 * * V_166 , struct V_146 * V_144 )
{
unsigned int V_145 = F_60 ( V_144 ) ;
struct V_142 * V_43 ;
if ( V_144 -> V_6 == NULL )
return - V_90 ;
V_43 = F_87 ( F_74 ( V_144 -> V_18 ) , 0 ) ;
if ( ! V_43 )
return - V_8 ;
memcpy ( V_43 -> V_149 , V_144 -> V_6 , V_145 ) ;
V_43 -> V_18 = V_144 -> V_18 ;
V_43 -> V_148 = NULL ;
V_43 = F_84 ( V_43 , NULL ) ;
if ( F_88 ( V_43 ) )
return F_89 ( V_43 ) ;
* V_166 = V_43 ;
return 0 ;
}
int F_90 ( struct V_142 * * V_166 , struct V_143 * V_144 ,
T_5 V_163 )
{
unsigned int V_145 = F_60 ( V_144 ) ;
struct V_142 * V_43 ;
if ( V_144 -> V_6 == NULL )
return - V_90 ;
V_43 = F_87 ( F_74 ( V_144 -> V_18 ) , 0 ) ;
if ( ! V_43 )
return - V_8 ;
if ( F_91 ( V_43 -> V_149 , V_144 -> V_6 , V_145 ) ) {
F_92 ( V_43 ) ;
return - V_167 ;
}
V_43 -> V_18 = V_144 -> V_18 ;
V_43 -> V_148 = NULL ;
V_43 = F_84 ( V_43 , V_163 ) ;
if ( F_88 ( V_43 ) )
return F_89 ( V_43 ) ;
* V_166 = V_43 ;
return 0 ;
}
void F_93 ( struct V_142 * V_43 )
{
F_64 ( V_43 ) ;
}
static int F_94 ( struct V_142 * V_75 , struct V_1 * V_2 )
{
struct F_1 * V_43 , * V_158 ;
V_43 = F_61 ( sizeof( * V_43 ) , V_91 ) ;
if ( ! V_43 )
return - V_8 ;
V_43 -> V_75 = V_75 ;
F_95 ( & V_43 -> V_153 , 0 ) ;
if ( ! F_76 ( V_2 , V_43 ) ) {
F_52 ( V_43 ) ;
return - V_8 ;
}
V_158 = F_96 ( V_2 -> F_1 ,
F_97 ( V_2 ) ) ;
F_98 ( V_2 -> F_1 , V_43 ) ;
if ( V_158 )
F_73 ( V_2 , V_158 ) ;
return 0 ;
}
int F_99 ( struct V_143 * V_144 , struct V_1 * V_2 )
{
unsigned int V_145 = F_60 ( V_144 ) ;
unsigned int V_168 = F_74 ( V_144 -> V_18 ) ;
struct V_142 * V_75 ;
int V_5 ;
if ( F_3 ( V_2 , V_169 ) )
return - V_10 ;
if ( V_144 -> V_6 == NULL )
return - V_90 ;
V_75 = F_87 ( V_168 , 0 ) ;
if ( ! V_75 )
return - V_8 ;
if ( F_91 ( V_75 -> V_149 , V_144 -> V_6 , V_145 ) ) {
F_92 ( V_75 ) ;
return - V_167 ;
}
V_75 -> V_18 = V_144 -> V_18 ;
V_5 = F_59 ( V_75 , V_144 ) ;
if ( V_5 ) {
F_92 ( V_75 ) ;
return - V_8 ;
}
V_75 = F_84 ( V_75 , NULL ) ;
if ( F_88 ( V_75 ) )
return F_89 ( V_75 ) ;
V_5 = F_94 ( V_75 , V_2 ) ;
if ( V_5 < 0 ) {
F_64 ( V_75 ) ;
return V_5 ;
}
return 0 ;
}
int F_100 ( T_2 V_170 , struct V_1 * V_2 )
{
struct V_142 * V_75 ;
int V_5 ;
if ( F_3 ( V_2 , V_169 ) )
return - V_10 ;
V_75 = F_101 ( V_170 ) ;
if ( F_88 ( V_75 ) )
return F_89 ( V_75 ) ;
if ( V_75 -> type != V_150 ) {
F_65 ( V_75 ) ;
return - V_90 ;
}
V_5 = F_94 ( V_75 , V_2 ) ;
if ( V_5 < 0 ) {
F_65 ( V_75 ) ;
return V_5 ;
}
return 0 ;
}
static T_1 F_102 ( T_1 V_171 , T_1 V_172 , T_1 V_173 , T_1 V_14 , T_1 V_174 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
int V_175 = ( int ) V_172 ;
void * V_176 = ( void * ) ( long ) V_173 ;
unsigned int V_18 = ( unsigned int ) V_14 ;
char V_177 [ 16 ] ;
void * V_178 ;
if ( F_103 ( ( T_2 ) V_175 > 0xffff || V_18 > sizeof( V_177 ) ) )
return - V_167 ;
if ( F_103 ( F_104 ( V_4 ) &&
! F_105 ( V_4 , V_175 + V_18 ) ) )
return - V_167 ;
V_178 = F_106 ( V_4 , V_175 , V_18 , V_177 ) ;
if ( F_103 ( ! V_178 ) )
return - V_167 ;
if ( F_107 ( V_174 ) )
F_108 ( V_4 , V_178 , V_18 ) ;
memcpy ( V_178 , V_176 , V_18 ) ;
if ( V_178 == V_177 )
F_109 ( V_4 , V_175 , V_178 , V_18 ) ;
if ( F_107 ( V_174 ) && V_4 -> V_179 == V_180 )
V_4 -> V_181 = F_110 ( V_4 -> V_181 , F_111 ( V_178 , V_18 , 0 ) ) ;
return 0 ;
}
static T_1 F_112 ( T_1 V_171 , T_1 V_172 , T_1 V_176 , T_1 V_182 , T_1 V_174 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
int V_175 = ( int ) V_172 ;
T_6 V_183 , * V_178 ;
if ( F_103 ( ( T_2 ) V_175 > 0xffff ) )
return - V_167 ;
if ( F_103 ( F_104 ( V_4 ) &&
! F_105 ( V_4 , V_175 + sizeof( V_183 ) ) ) )
return - V_167 ;
V_178 = F_106 ( V_4 , V_175 , sizeof( V_183 ) , & V_183 ) ;
if ( F_103 ( ! V_178 ) )
return - V_167 ;
switch ( F_113 ( V_174 ) ) {
case 2 :
F_114 ( V_178 , V_176 , V_182 ) ;
break;
case 4 :
F_115 ( V_178 , V_176 , V_182 ) ;
break;
default:
return - V_90 ;
}
if ( V_178 == & V_183 )
F_109 ( V_4 , V_175 , V_178 , sizeof( V_183 ) ) ;
return 0 ;
}
static T_1 F_116 ( T_1 V_171 , T_1 V_172 , T_1 V_176 , T_1 V_182 , T_1 V_174 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
bool V_184 = ! ! F_117 ( V_174 ) ;
int V_175 = ( int ) V_172 ;
T_6 V_183 , * V_178 ;
if ( F_103 ( ( T_2 ) V_175 > 0xffff ) )
return - V_167 ;
if ( F_103 ( F_104 ( V_4 ) &&
! F_105 ( V_4 , V_175 + sizeof( V_183 ) ) ) )
return - V_167 ;
V_178 = F_106 ( V_4 , V_175 , sizeof( V_183 ) , & V_183 ) ;
if ( F_103 ( ! V_178 ) )
return - V_167 ;
switch ( F_113 ( V_174 ) ) {
case 2 :
F_118 ( V_178 , V_4 , V_176 , V_182 , V_184 ) ;
break;
case 4 :
F_119 ( V_178 , V_4 , V_176 , V_182 , V_184 ) ;
break;
default:
return - V_90 ;
}
if ( V_178 == & V_183 )
F_109 ( V_4 , V_175 , V_178 , sizeof( V_183 ) ) ;
return 0 ;
}
static T_1 F_120 ( T_1 V_171 , T_1 V_56 , T_1 V_174 , T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 , * V_185 ;
struct V_55 * V_57 ;
V_57 = F_121 ( F_122 ( V_4 -> V_57 ) , V_56 ) ;
if ( F_103 ( ! V_57 ) )
return - V_90 ;
if ( F_103 ( ! ( V_57 -> V_174 & V_186 ) ) )
return - V_90 ;
V_185 = F_123 ( V_4 , V_187 ) ;
if ( F_103 ( ! V_185 ) )
return - V_8 ;
if ( F_124 ( V_174 ) )
return F_125 ( V_57 , V_185 ) ;
V_185 -> V_57 = V_57 ;
F_126 ( V_185 ) ;
return F_127 ( V_185 ) ;
}
static T_1 F_128 ( T_1 V_171 , T_1 V_172 , T_1 V_173 , T_1 V_14 , T_1 V_15 )
{
return F_129 ( (struct V_3 * ) ( unsigned long ) V_171 ) ;
}
static T_1 F_130 ( T_1 V_171 , T_1 V_172 , T_1 V_40 , T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
T_7 V_63 = ( V_188 T_7 ) V_172 ;
if ( F_103 ( V_63 != F_131 ( V_189 ) &&
V_63 != F_131 ( V_190 ) ) )
V_63 = F_131 ( V_189 ) ;
return F_132 ( V_4 , V_63 , V_40 ) ;
}
static T_1 F_133 ( T_1 V_171 , T_1 V_172 , T_1 V_173 , T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
return F_134 ( V_4 ) ;
}
bool F_135 ( void * V_191 )
{
if ( V_191 == F_130 )
return true ;
if ( V_191 == F_133 )
return true ;
return false ;
}
static T_1 F_136 ( T_1 V_171 , T_1 V_172 , T_1 V_192 , T_1 V_174 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
struct V_193 * V_182 = (struct V_193 * ) ( long ) V_172 ;
struct V_194 * V_195 = F_137 ( V_4 ) ;
if ( F_103 ( V_192 != sizeof( struct V_193 ) || V_174 || ! V_195 ) )
return - V_90 ;
if ( F_138 ( V_195 ) != V_196 )
return - V_90 ;
V_182 -> V_197 = F_139 ( V_195 -> V_198 . V_199 ) ;
V_182 -> V_200 = F_140 ( V_195 -> V_198 . V_201 . V_202 . V_203 ) ;
return 0 ;
}
static T_1 F_141 ( T_1 V_171 , T_1 V_172 , T_1 V_192 , T_1 V_174 , T_1 V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_171 ;
struct V_193 * V_176 = (struct V_193 * ) ( long ) V_172 ;
struct V_204 * V_205 = F_142 ( V_206 ) ;
struct V_194 * V_195 ;
if ( F_103 ( V_192 != sizeof( struct V_193 ) || V_174 ) )
return - V_90 ;
F_143 ( V_4 ) ;
F_144 ( (struct V_207 * ) V_205 ) ;
F_145 ( V_4 , (struct V_207 * ) V_205 ) ;
V_195 = & V_205 -> V_201 . V_208 ;
V_195 -> V_209 = V_210 ;
V_195 -> V_198 . V_211 = V_212 ;
V_195 -> V_198 . V_199 = F_146 ( V_176 -> V_197 ) ;
V_195 -> V_198 . V_201 . V_202 . V_213 = F_147 ( V_176 -> V_200 ) ;
return 0 ;
}
static const struct V_214 * F_148 ( void )
{
if ( ! V_206 ) {
V_206 = F_149 ( 0 , V_91 ) ;
if ( ! V_206 )
return NULL ;
}
return & V_215 ;
}
static const struct V_214 *
F_150 ( enum V_216 V_217 )
{
switch ( V_217 ) {
case V_218 :
return & V_219 ;
case V_220 :
return & V_221 ;
case V_222 :
return & V_223 ;
case V_224 :
return & V_225 ;
case V_226 :
return & V_227 ;
case V_228 :
return & V_229 ;
case V_230 :
return & V_231 ;
case V_232 :
return F_151 () ;
default:
return NULL ;
}
}
static const struct V_214 *
F_152 ( enum V_216 V_217 )
{
switch ( V_217 ) {
case V_233 :
return & V_234 ;
case V_235 :
return & V_236 ;
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
return F_148 () ;
default:
return F_150 ( V_217 ) ;
}
}
static bool F_153 ( int V_250 , int V_192 , enum V_251 type )
{
if ( V_250 < 0 || V_250 >= sizeof( struct V_252 ) )
return false ;
if ( V_250 % V_192 != 0 )
return false ;
if ( V_192 != 4 )
return false ;
return true ;
}
static bool F_154 ( int V_250 , int V_192 ,
enum V_251 type )
{
if ( type == V_253 ) {
switch ( V_250 ) {
case F_25 ( struct V_252 , V_254 [ 0 ] ) ...
F_25 ( struct V_252 , V_254 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_153 ( V_250 , V_192 , type ) ;
}
static bool F_155 ( int V_250 , int V_192 ,
enum V_251 type )
{
if ( type == V_253 ) {
switch ( V_250 ) {
case F_25 ( struct V_252 , V_28 ) :
case F_25 ( struct V_252 , V_255 ) :
case F_25 ( struct V_252 , V_254 [ 0 ] ) ...
F_25 ( struct V_252 , V_254 [ 4 ] ) :
break;
default:
return false ;
}
}
return F_153 ( V_250 , V_192 , type ) ;
}
static T_2 F_156 ( enum V_251 type , int V_22 ,
int V_23 , int V_256 ,
struct V_24 * V_25 )
{
struct V_24 * V_26 = V_25 ;
switch ( V_256 ) {
case F_25 ( struct V_252 , V_18 ) :
F_22 ( F_23 ( struct V_3 , V_18 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_18 ) ) ;
break;
case F_25 ( struct V_252 , V_49 ) :
F_22 ( F_23 ( struct V_3 , V_49 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_49 ) ) ;
break;
case F_25 ( struct V_252 , V_63 ) :
F_22 ( F_23 ( struct V_3 , V_63 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_63 ) ) ;
break;
case F_25 ( struct V_252 , V_257 ) :
F_22 ( F_23 ( struct V_3 , V_257 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_257 ) ) ;
break;
case F_25 ( struct V_252 , V_258 ) :
F_22 ( F_23 ( struct V_3 , V_259 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_259 ) ) ;
break;
case F_25 ( struct V_252 , V_56 ) :
F_22 ( F_23 ( struct V_55 , V_56 ) != 4 ) ;
* V_26 ++ = F_24 ( F_31 ( F_23 ( struct V_3 , V_57 ) ) ,
V_22 , V_23 ,
F_25 ( struct V_3 , V_57 ) ) ;
* V_26 ++ = F_32 ( V_112 , V_22 , 0 , 1 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_22 ,
F_25 ( struct V_55 , V_56 ) ) ;
break;
case F_25 ( struct V_252 , V_61 ) :
F_22 ( F_23 ( struct V_3 , V_61 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_61 ) ) ;
break;
case F_25 ( struct V_252 , V_28 ) :
F_22 ( F_23 ( struct V_3 , V_28 ) != 4 ) ;
if ( type == V_253 )
* V_26 ++ = F_51 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_28 ) ) ;
else
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_28 ) ) ;
break;
case F_25 ( struct V_252 , V_260 ) :
return F_21 ( V_30 , V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_252 , V_36 ) :
return F_21 ( V_35 , V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_252 , V_261 ) :
return F_21 ( V_39 ,
V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_252 , V_40 ) :
return F_21 ( V_38 ,
V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_252 , V_254 [ 0 ] ) ...
F_25 ( struct V_252 , V_254 [ 4 ] ) :
F_22 ( F_23 ( struct V_262 , V_19 ) < 20 ) ;
V_256 -= F_25 ( struct V_252 , V_254 [ 0 ] ) ;
V_256 += F_25 ( struct V_3 , V_254 ) ;
V_256 += F_25 ( struct V_262 , V_19 ) ;
if ( type == V_253 )
* V_26 ++ = F_51 ( V_29 , V_22 , V_23 , V_256 ) ;
else
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 , V_256 ) ;
break;
case F_25 ( struct V_252 , V_255 ) :
#ifdef F_157
F_22 ( F_23 ( struct V_3 , V_255 ) != 2 ) ;
if ( type == V_253 )
* V_26 ++ = F_51 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_255 ) ) ;
else
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_255 ) ) ;
break;
#else
if ( type == V_253 )
* V_26 ++ = F_34 ( V_22 , V_22 ) ;
else
* V_26 ++ = F_158 ( V_22 , 0 ) ;
break;
#endif
}
return V_26 - V_25 ;
}
static int T_8 F_159 ( void )
{
F_160 ( & V_263 ) ;
F_160 ( & V_264 ) ;
F_160 ( & V_265 ) ;
return 0 ;
}
int F_161 ( struct V_1 * V_2 )
{
int V_136 = - V_266 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_169 ) )
return - V_10 ;
V_6 = F_96 ( V_2 -> F_1 ,
F_97 ( V_2 ) ) ;
if ( V_6 ) {
F_162 ( V_2 -> F_1 , NULL ) ;
F_73 ( V_2 , V_6 ) ;
V_136 = 0 ;
}
return V_136 ;
}
int F_163 ( struct V_1 * V_2 , struct V_42 T_9 * V_267 ,
unsigned int V_18 )
{
struct V_146 * V_144 ;
struct F_1 * V_6 ;
int V_136 = 0 ;
F_164 ( V_2 ) ;
V_6 = F_96 ( V_2 -> F_1 ,
F_97 ( V_2 ) ) ;
if ( ! V_6 )
goto V_268;
V_136 = - V_269 ;
V_144 = V_6 -> V_75 -> V_148 ;
if ( ! V_144 )
goto V_268;
V_136 = V_144 -> V_18 ;
if ( ! V_18 )
goto V_268;
V_136 = - V_90 ;
if ( V_18 < V_144 -> V_18 )
goto V_268;
V_136 = - V_167 ;
if ( F_165 ( V_267 , V_144 -> V_6 , F_60 ( V_144 ) ) )
goto V_268;
V_136 = V_144 -> V_18 ;
V_268:
F_166 ( V_2 ) ;
return V_136 ;
}
