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
int F_39 ( struct V_42 * V_75 , int V_18 ,
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
V_83 = F_40 ( V_18 , sizeof( * V_83 ) , V_91 ) ;
if ( ! V_83 )
return - V_8 ;
}
V_92:
V_82 = V_76 ;
V_43 = V_75 ;
if ( V_82 )
* V_82 = F_34 ( V_51 , V_69 ) ;
V_82 ++ ;
for ( V_81 = 0 ; V_81 < V_18 ; V_43 ++ , V_81 ++ ) {
struct V_24 V_93 [ 6 ] = { } ;
struct V_24 * V_26 = V_93 ;
if ( V_83 )
V_83 [ V_81 ] = V_82 - V_76 ;
switch ( V_43 -> V_94 ) {
case V_95 | V_96 | V_97 :
case V_95 | V_96 | V_98 :
case V_95 | V_99 | V_97 :
case V_95 | V_99 | V_98 :
case V_95 | V_32 | V_97 :
case V_95 | V_32 | V_98 :
case V_95 | V_100 | V_97 :
case V_95 | V_100 | V_98 :
case V_95 | V_101 | V_97 :
case V_95 | V_101 | V_98 :
case V_95 | V_34 | V_97 :
case V_95 | V_34 | V_98 :
case V_95 | V_74 | V_97 :
case V_95 | V_74 | V_98 :
case V_95 | V_102 | V_97 :
case V_95 | V_102 | V_98 :
case V_95 | V_103 | V_97 :
case V_95 | V_103 | V_98 :
case V_95 | V_104 | V_97 :
case V_95 | V_104 | V_98 :
case V_95 | V_105 :
case V_106 | V_107 | V_29 :
case V_106 | V_107 | V_37 :
case V_106 | V_107 | V_31 :
case V_106 | V_108 | V_29 :
case V_106 | V_108 | V_37 :
case V_106 | V_108 | V_31 :
if ( F_41 ( V_43 -> V_94 ) == V_106 &&
F_42 ( V_43 -> V_94 ) == V_107 &&
F_29 ( V_43 , & V_26 ) )
break;
* V_26 = F_43 ( V_43 -> V_94 , V_50 , V_72 , 0 , V_43 -> V_46 ) ;
break;
#define F_44 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_109 | V_110 :
V_80 = V_81 + V_43 -> V_46 + 1 ;
V_26 -> V_94 = V_43 -> V_94 ;
F_44 ;
break;
case V_109 | V_111 | V_98 :
case V_109 | V_111 | V_97 :
case V_109 | V_112 | V_98 :
case V_109 | V_112 | V_97 :
case V_109 | V_113 | V_98 :
case V_109 | V_113 | V_97 :
case V_109 | V_114 | V_98 :
case V_109 | V_114 | V_97 :
if ( F_45 ( V_43 -> V_94 ) == V_98 && ( int ) V_43 -> V_46 < 0 ) {
* V_26 ++ = F_46 ( V_58 , V_43 -> V_46 ) ;
V_26 -> V_22 = V_50 ;
V_26 -> V_23 = V_58 ;
V_84 = V_97 ;
} else {
V_26 -> V_22 = V_50 ;
V_26 -> V_23 = V_72 ;
V_26 -> V_115 = V_43 -> V_46 ;
V_84 = F_45 ( V_43 -> V_94 ) ;
}
if ( V_43 -> V_116 == 0 ) {
V_26 -> V_94 = V_109 | F_47 ( V_43 -> V_94 ) | V_84 ;
V_80 = V_81 + V_43 -> V_117 + 1 ;
F_44 ;
break;
}
if ( V_43 -> V_117 == 0 && F_47 ( V_43 -> V_94 ) == V_111 ) {
V_26 -> V_94 = V_109 | V_59 | V_84 ;
V_80 = V_81 + V_43 -> V_116 + 1 ;
F_44 ;
break;
}
V_80 = V_81 + V_43 -> V_117 + 1 ;
V_26 -> V_94 = V_109 | F_47 ( V_43 -> V_94 ) | V_84 ;
F_44 ;
V_26 ++ ;
V_26 -> V_94 = V_109 | V_110 ;
V_80 = V_81 + V_43 -> V_116 + 1 ;
F_44 ;
break;
case V_118 | V_119 | V_31 :
* V_26 ++ = F_34 ( V_58 , V_50 ) ;
* V_26 ++ = F_48 ( V_31 , V_43 -> V_46 ) ;
* V_26 ++ = F_27 ( V_32 , V_50 , 0xf ) ;
* V_26 ++ = F_27 ( V_101 , V_50 , 2 ) ;
* V_26 ++ = F_34 ( V_72 , V_50 ) ;
* V_26 = F_34 ( V_50 , V_58 ) ;
break;
case V_120 | V_121 :
case V_120 | V_98 :
* V_26 ++ = F_49 ( F_50 ( V_43 -> V_94 ) == V_98 ?
V_98 : V_97 , V_122 ,
V_50 , V_43 -> V_46 ) ;
* V_26 = F_33 () ;
break;
case V_123 :
case V_124 :
* V_26 = F_51 ( V_29 , V_87 , F_41 ( V_43 -> V_94 ) ==
V_123 ? V_50 : V_72 ,
- ( V_85 - V_43 -> V_46 ) * 4 ) ;
break;
case V_106 | V_125 :
case V_118 | V_125 :
* V_26 = F_24 ( V_29 , F_41 ( V_43 -> V_94 ) == V_106 ?
V_50 : V_72 , V_87 ,
- ( V_85 - V_43 -> V_46 ) * 4 ) ;
break;
case V_106 | V_126 :
case V_118 | V_126 :
* V_26 = F_46 ( F_41 ( V_43 -> V_94 ) == V_106 ?
V_50 : V_72 , V_43 -> V_46 ) ;
break;
case V_127 | V_128 :
* V_26 = F_34 ( V_72 , V_50 ) ;
break;
case V_127 | V_129 :
* V_26 = F_34 ( V_50 , V_72 ) ;
break;
case V_106 | V_29 | V_130 :
case V_118 | V_29 | V_130 :
* V_26 = F_24 ( V_29 , F_41 ( V_43 -> V_94 ) == V_106 ?
V_50 : V_72 , V_51 ,
F_25 ( struct V_3 , V_18 ) ) ;
break;
case V_118 | V_107 | V_29 :
* V_26 = F_24 ( V_29 , V_50 , V_51 , V_43 -> V_46 ) ;
break;
default:
goto V_5;
}
V_26 ++ ;
if ( V_76 )
memcpy ( V_82 , V_93 ,
sizeof( * V_26 ) * ( V_26 - V_93 ) ) ;
V_82 += V_26 - V_93 ;
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
goto V_92;
}
F_52 ( V_83 ) ;
F_37 ( * V_77 != V_78 ) ;
return 0 ;
V_5:
F_52 ( V_83 ) ;
return - V_90 ;
}
static int F_53 ( const struct V_42 * V_6 , int V_131 )
{
T_4 * V_132 , V_133 = 0 ;
int V_134 , V_135 = 0 ;
F_22 ( V_85 > 16 ) ;
V_132 = F_54 ( V_131 , sizeof( * V_132 ) , V_91 ) ;
if ( ! V_132 )
return - V_8 ;
memset ( V_132 , 0xff , V_131 * sizeof( * V_132 ) ) ;
for ( V_134 = 0 ; V_134 < V_131 ; V_134 ++ ) {
V_133 &= V_132 [ V_134 ] ;
switch ( V_6 [ V_134 ] . V_94 ) {
case V_123 :
case V_124 :
V_133 |= ( 1 << V_6 [ V_134 ] . V_46 ) ;
break;
case V_106 | V_125 :
case V_118 | V_125 :
if ( ! ( V_133 & ( 1 << V_6 [ V_134 ] . V_46 ) ) ) {
V_135 = - V_90 ;
goto error;
}
break;
case V_109 | V_110 :
V_132 [ V_134 + 1 + V_6 [ V_134 ] . V_46 ] &= V_133 ;
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
V_132 [ V_134 + 1 + V_6 [ V_134 ] . V_117 ] &= V_133 ;
V_132 [ V_134 + 1 + V_6 [ V_134 ] . V_116 ] &= V_133 ;
V_133 = ~ 0 ;
break;
}
}
error:
F_52 ( V_132 ) ;
return V_135 ;
}
static bool F_55 ( T_4 V_136 )
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
[ V_95 | V_32 | V_98 ] = true ,
[ V_95 | V_32 | V_97 ] = true ,
[ V_95 | V_100 | V_98 ] = true ,
[ V_95 | V_100 | V_97 ] = true ,
[ V_95 | V_74 | V_98 ] = true ,
[ V_95 | V_74 | V_97 ] = true ,
[ V_95 | V_101 | V_98 ] = true ,
[ V_95 | V_101 | V_97 ] = true ,
[ V_95 | V_34 | V_98 ] = true ,
[ V_95 | V_34 | V_97 ] = true ,
[ V_95 | V_105 ] = true ,
[ V_106 | V_29 | V_107 ] = true ,
[ V_106 | V_37 | V_107 ] = true ,
[ V_106 | V_31 | V_107 ] = true ,
[ V_106 | V_29 | V_130 ] = true ,
[ V_106 | V_29 | V_108 ] = true ,
[ V_106 | V_37 | V_108 ] = true ,
[ V_106 | V_31 | V_108 ] = true ,
[ V_106 | V_126 ] = true ,
[ V_106 | V_125 ] = true ,
[ V_118 | V_29 | V_130 ] = true ,
[ V_118 | V_31 | V_119 ] = true ,
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
if ( V_136 >= F_56 ( V_137 ) )
return false ;
return V_137 [ V_136 ] ;
}
int F_57 ( const struct V_42 * V_6 , unsigned int V_131 )
{
bool V_138 ;
int V_134 ;
if ( V_131 == 0 || V_131 > V_89 )
return - V_90 ;
for ( V_134 = 0 ; V_134 < V_131 ; V_134 ++ ) {
const struct V_42 * V_139 = & V_6 [ V_134 ] ;
if ( ! F_55 ( V_139 -> V_94 ) )
return - V_90 ;
switch ( V_139 -> V_94 ) {
case V_95 | V_103 | V_98 :
case V_95 | V_104 | V_98 :
if ( V_139 -> V_46 == 0 )
return - V_90 ;
break;
case V_106 | V_125 :
case V_118 | V_125 :
case V_123 :
case V_124 :
if ( V_139 -> V_46 >= V_85 )
return - V_90 ;
break;
case V_109 | V_110 :
if ( V_139 -> V_46 >= ( unsigned int ) ( V_131 - V_134 - 1 ) )
return - V_90 ;
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
return - V_90 ;
break;
case V_106 | V_29 | V_107 :
case V_106 | V_37 | V_107 :
case V_106 | V_31 | V_107 :
V_138 = false ;
if ( F_58 ( V_139 ) & V_140 )
V_138 = true ;
if ( V_138 == false && V_139 -> V_46 >= V_47 )
return - V_90 ;
}
}
switch ( V_6 [ V_131 - 1 ] . V_94 ) {
case V_120 | V_98 :
case V_120 | V_121 :
return F_53 ( V_6 , V_131 ) ;
}
return - V_90 ;
}
static int F_59 ( struct V_141 * V_43 ,
const struct V_142 * V_143 )
{
unsigned int V_144 = F_60 ( V_143 ) ;
struct V_145 * V_146 ;
V_43 -> V_147 = F_61 ( sizeof( * V_146 ) , V_91 ) ;
if ( ! V_43 -> V_147 )
return - V_8 ;
V_146 = V_43 -> V_147 ;
V_146 -> V_18 = V_143 -> V_18 ;
V_146 -> V_6 = F_62 ( V_43 -> V_148 , V_144 , V_91 ) ;
if ( ! V_146 -> V_6 ) {
F_52 ( V_43 -> V_147 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_63 ( struct V_141 * V_43 )
{
struct V_145 * V_143 = V_43 -> V_147 ;
if ( V_143 ) {
F_52 ( V_143 -> V_6 ) ;
F_52 ( V_143 ) ;
}
}
static void F_64 ( struct V_141 * V_75 )
{
if ( V_75 -> type == V_149 ) {
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
static void F_68 ( struct V_150 * V_151 )
{
struct F_1 * V_43 = F_69 ( V_151 , struct F_1 , V_151 ) ;
F_67 ( V_43 ) ;
}
static void F_70 ( struct F_1 * V_43 )
{
if ( F_71 ( & V_43 -> V_152 ) )
F_72 ( & V_43 -> V_151 , F_68 ) ;
}
void F_73 ( struct V_1 * V_2 , struct F_1 * V_43 )
{
T_2 V_153 = F_74 ( V_43 -> V_75 -> V_18 ) ;
F_75 ( V_153 , & V_2 -> V_154 ) ;
F_70 ( V_43 ) ;
}
bool F_76 ( struct V_1 * V_2 , struct F_1 * V_43 )
{
T_2 V_153 = F_74 ( V_43 -> V_75 -> V_18 ) ;
if ( V_153 <= V_155 &&
F_77 ( & V_2 -> V_154 ) + V_153 < V_155 ) {
F_78 ( & V_43 -> V_152 ) ;
F_79 ( V_153 , & V_2 -> V_154 ) ;
return true ;
}
return false ;
}
static struct V_141 * F_80 ( struct V_141 * V_43 )
{
struct V_42 * V_156 ;
struct V_141 * V_157 ;
int V_5 , V_77 , V_158 = V_43 -> V_18 ;
F_22 ( sizeof( struct V_42 ) !=
sizeof( struct V_24 ) ) ;
V_156 = F_62 ( V_43 -> V_148 , V_158 * sizeof( struct V_42 ) ,
V_91 ) ;
if ( ! V_156 ) {
V_5 = - V_8 ;
goto V_159;
}
V_5 = F_39 ( V_156 , V_158 , NULL , & V_77 ) ;
if ( V_5 )
goto V_160;
V_157 = V_43 ;
V_43 = F_81 ( V_157 , F_74 ( V_77 ) , 0 ) ;
if ( ! V_43 ) {
V_43 = V_157 ;
V_5 = - V_8 ;
goto V_160;
}
V_43 -> V_18 = V_77 ;
V_5 = F_39 ( V_156 , V_158 , V_43 -> V_161 , & V_77 ) ;
if ( V_5 )
goto V_160;
F_82 ( V_43 ) ;
F_52 ( V_156 ) ;
return V_43 ;
V_160:
F_52 ( V_156 ) ;
V_159:
F_64 ( V_43 ) ;
return F_83 ( V_5 ) ;
}
static struct V_141 * F_84 ( struct V_141 * V_43 )
{
int V_5 ;
V_43 -> V_162 = NULL ;
V_43 -> V_163 = false ;
V_5 = F_57 ( V_43 -> V_148 , V_43 -> V_18 ) ;
if ( V_5 ) {
F_64 ( V_43 ) ;
return F_83 ( V_5 ) ;
}
F_85 ( V_43 ) ;
if ( ! V_43 -> V_163 )
V_43 = F_80 ( V_43 ) ;
return V_43 ;
}
int F_86 ( struct V_141 * * V_164 , struct V_145 * V_143 )
{
unsigned int V_144 = F_60 ( V_143 ) ;
struct V_141 * V_43 ;
if ( V_143 -> V_6 == NULL )
return - V_90 ;
V_43 = F_87 ( F_74 ( V_143 -> V_18 ) , 0 ) ;
if ( ! V_43 )
return - V_8 ;
memcpy ( V_43 -> V_148 , V_143 -> V_6 , V_144 ) ;
V_43 -> V_18 = V_143 -> V_18 ;
V_43 -> V_147 = NULL ;
V_43 = F_84 ( V_43 ) ;
if ( F_88 ( V_43 ) )
return F_89 ( V_43 ) ;
* V_164 = V_43 ;
return 0 ;
}
void F_90 ( struct V_141 * V_43 )
{
F_64 ( V_43 ) ;
}
static int F_91 ( struct V_141 * V_75 , struct V_1 * V_2 )
{
struct F_1 * V_43 , * V_157 ;
V_43 = F_61 ( sizeof( * V_43 ) , V_91 ) ;
if ( ! V_43 )
return - V_8 ;
V_43 -> V_75 = V_75 ;
F_92 ( & V_43 -> V_152 , 0 ) ;
if ( ! F_76 ( V_2 , V_43 ) ) {
F_52 ( V_43 ) ;
return - V_8 ;
}
V_157 = F_93 ( V_2 -> F_1 ,
F_94 ( V_2 ) ) ;
F_95 ( V_2 -> F_1 , V_43 ) ;
if ( V_157 )
F_73 ( V_2 , V_157 ) ;
return 0 ;
}
int F_96 ( struct V_142 * V_143 , struct V_1 * V_2 )
{
unsigned int V_144 = F_60 ( V_143 ) ;
unsigned int V_165 = F_74 ( V_143 -> V_18 ) ;
struct V_141 * V_75 ;
int V_5 ;
if ( F_3 ( V_2 , V_166 ) )
return - V_10 ;
if ( V_143 -> V_6 == NULL )
return - V_90 ;
V_75 = F_87 ( V_165 , 0 ) ;
if ( ! V_75 )
return - V_8 ;
if ( F_97 ( V_75 -> V_148 , V_143 -> V_6 , V_144 ) ) {
F_98 ( V_75 ) ;
return - V_167 ;
}
V_75 -> V_18 = V_143 -> V_18 ;
V_5 = F_59 ( V_75 , V_143 ) ;
if ( V_5 ) {
F_98 ( V_75 ) ;
return - V_8 ;
}
V_75 = F_84 ( V_75 ) ;
if ( F_88 ( V_75 ) )
return F_89 ( V_75 ) ;
V_5 = F_91 ( V_75 , V_2 ) ;
if ( V_5 < 0 ) {
F_64 ( V_75 ) ;
return V_5 ;
}
return 0 ;
}
int F_99 ( T_2 V_168 , struct V_1 * V_2 )
{
struct V_141 * V_75 ;
int V_5 ;
if ( F_3 ( V_2 , V_166 ) )
return - V_10 ;
V_75 = F_100 ( V_168 ) ;
if ( F_88 ( V_75 ) )
return F_89 ( V_75 ) ;
if ( V_75 -> type != V_149 ) {
F_65 ( V_75 ) ;
return - V_90 ;
}
V_5 = F_91 ( V_75 , V_2 ) ;
if ( V_5 < 0 ) {
F_65 ( V_75 ) ;
return V_5 ;
}
return 0 ;
}
static bool F_101 ( const struct V_3 * V_4 , int V_18 )
{
return F_102 ( V_4 ) ||
( int ) F_103 ( V_4 ) + V_18 > V_4 -> V_169 ;
}
static T_1 F_104 ( T_1 V_170 , T_1 V_171 , T_1 V_172 , T_1 V_14 , T_1 V_173 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_170 ;
int V_174 = ( int ) V_171 ;
void * V_175 = ( void * ) ( long ) V_172 ;
unsigned int V_18 = ( unsigned int ) V_14 ;
char V_176 [ 16 ] ;
void * V_177 ;
if ( F_105 ( ( T_2 ) V_174 > 0xffff || V_18 > sizeof( V_176 ) ) )
return - V_167 ;
V_174 -= V_4 -> V_19 - F_106 ( V_4 ) ;
if ( F_105 ( F_107 ( V_4 ) &&
F_101 ( V_4 , V_174 + V_18 ) ) )
return - V_167 ;
V_177 = F_108 ( V_4 , V_174 , V_18 , V_176 ) ;
if ( F_105 ( ! V_177 ) )
return - V_167 ;
if ( F_109 ( V_173 ) )
F_110 ( V_4 , V_177 , V_18 ) ;
memcpy ( V_177 , V_175 , V_18 ) ;
if ( V_177 == V_176 )
F_111 ( V_4 , V_174 , V_177 , V_18 ) ;
if ( F_109 ( V_173 ) && V_4 -> V_178 == V_179 )
V_4 -> V_180 = F_112 ( V_4 -> V_180 , F_113 ( V_177 , V_18 , 0 ) ) ;
return 0 ;
}
static T_1 F_114 ( T_1 V_170 , T_1 V_171 , T_1 V_175 , T_1 V_181 , T_1 V_173 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_170 ;
int V_174 = ( int ) V_171 ;
T_5 V_182 , * V_177 ;
if ( F_105 ( ( T_2 ) V_174 > 0xffff ) )
return - V_167 ;
V_174 -= V_4 -> V_19 - F_106 ( V_4 ) ;
if ( F_105 ( F_107 ( V_4 ) &&
F_101 ( V_4 , V_174 + sizeof( V_182 ) ) ) )
return - V_167 ;
V_177 = F_108 ( V_4 , V_174 , sizeof( V_182 ) , & V_182 ) ;
if ( F_105 ( ! V_177 ) )
return - V_167 ;
switch ( F_115 ( V_173 ) ) {
case 2 :
F_116 ( V_177 , V_175 , V_181 ) ;
break;
case 4 :
F_117 ( V_177 , V_175 , V_181 ) ;
break;
default:
return - V_90 ;
}
if ( V_177 == & V_182 )
F_111 ( V_4 , V_174 , V_177 , sizeof( V_182 ) ) ;
return 0 ;
}
static T_1 F_118 ( T_1 V_170 , T_1 V_171 , T_1 V_175 , T_1 V_181 , T_1 V_173 )
{
struct V_3 * V_4 = (struct V_3 * ) ( long ) V_170 ;
T_2 V_183 = F_119 ( V_173 ) ;
int V_174 = ( int ) V_171 ;
T_5 V_182 , * V_177 ;
if ( F_105 ( ( T_2 ) V_174 > 0xffff ) )
return - V_167 ;
V_174 -= V_4 -> V_19 - F_106 ( V_4 ) ;
if ( F_105 ( F_107 ( V_4 ) &&
F_101 ( V_4 , V_174 + sizeof( V_182 ) ) ) )
return - V_167 ;
V_177 = F_108 ( V_4 , V_174 , sizeof( V_182 ) , & V_182 ) ;
if ( F_105 ( ! V_177 ) )
return - V_167 ;
switch ( F_115 ( V_173 ) ) {
case 2 :
F_120 ( V_177 , V_4 , V_175 , V_181 , V_183 ) ;
break;
case 4 :
F_121 ( V_177 , V_4 , V_175 , V_181 , V_183 ) ;
break;
default:
return - V_90 ;
}
if ( V_177 == & V_182 )
F_111 ( V_4 , V_174 , V_177 , sizeof( V_182 ) ) ;
return 0 ;
}
static const struct V_184 *
F_122 ( enum V_185 V_186 )
{
switch ( V_186 ) {
case V_187 :
return & V_188 ;
case V_189 :
return & V_190 ;
case V_191 :
return & V_192 ;
case V_193 :
return & V_194 ;
case V_195 :
return & V_196 ;
default:
return NULL ;
}
}
static const struct V_184 *
F_123 ( enum V_185 V_186 )
{
switch ( V_186 ) {
case V_197 :
return & V_198 ;
case V_199 :
return & V_200 ;
case V_201 :
return & V_202 ;
default:
return F_122 ( V_186 ) ;
}
}
static bool F_124 ( int V_203 , int V_204 ,
enum V_205 type )
{
if ( type != V_206 )
return false ;
if ( V_203 < 0 || V_203 >= sizeof( struct V_207 ) )
return false ;
if ( V_203 % V_204 != 0 )
return false ;
if ( V_204 != 4 )
return false ;
return true ;
}
static T_2 F_125 ( int V_22 , int V_23 , int V_208 ,
struct V_24 * V_25 )
{
struct V_24 * V_26 = V_25 ;
switch ( V_208 ) {
case F_25 ( struct V_207 , V_18 ) :
F_22 ( F_23 ( struct V_3 , V_18 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_18 ) ) ;
break;
case F_25 ( struct V_207 , V_49 ) :
F_22 ( F_23 ( struct V_3 , V_49 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_49 ) ) ;
break;
case F_25 ( struct V_207 , V_63 ) :
F_22 ( F_23 ( struct V_3 , V_63 ) != 2 ) ;
* V_26 ++ = F_24 ( V_37 , V_22 , V_23 ,
F_25 ( struct V_3 , V_63 ) ) ;
break;
case F_25 ( struct V_207 , V_209 ) :
F_22 ( F_23 ( struct V_3 , V_209 ) != 4 ) ;
* V_26 ++ = F_24 ( V_29 , V_22 , V_23 ,
F_25 ( struct V_3 , V_209 ) ) ;
break;
case F_25 ( struct V_207 , V_28 ) :
return F_21 ( V_27 , V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_207 , V_210 ) :
return F_21 ( V_30 , V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_207 , V_36 ) :
return F_21 ( V_35 , V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_207 , V_211 ) :
return F_21 ( V_39 ,
V_22 , V_23 , V_26 ) ;
case F_25 ( struct V_207 , V_40 ) :
return F_21 ( V_38 ,
V_22 , V_23 , V_26 ) ;
}
return V_26 - V_25 ;
}
static int T_6 F_126 ( void )
{
F_127 ( & V_212 ) ;
F_127 ( & V_213 ) ;
F_127 ( & V_214 ) ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 )
{
int V_135 = - V_215 ;
struct F_1 * V_6 ;
if ( F_3 ( V_2 , V_166 ) )
return - V_10 ;
V_6 = F_93 ( V_2 -> F_1 ,
F_94 ( V_2 ) ) ;
if ( V_6 ) {
F_129 ( V_2 -> F_1 , NULL ) ;
F_73 ( V_2 , V_6 ) ;
V_135 = 0 ;
}
return V_135 ;
}
int F_130 ( struct V_1 * V_2 , struct V_42 T_7 * V_216 ,
unsigned int V_18 )
{
struct V_145 * V_143 ;
struct F_1 * V_6 ;
int V_135 = 0 ;
F_131 ( V_2 ) ;
V_6 = F_93 ( V_2 -> F_1 ,
F_94 ( V_2 ) ) ;
if ( ! V_6 )
goto V_217;
V_143 = V_6 -> V_75 -> V_147 ;
V_135 = V_143 -> V_18 ;
if ( ! V_18 )
goto V_217;
V_135 = - V_90 ;
if ( V_18 < V_143 -> V_18 )
goto V_217;
V_135 = - V_167 ;
if ( F_132 ( V_216 , V_143 -> V_6 , F_60 ( V_143 ) ) )
goto V_217;
V_135 = V_143 -> V_18 ;
V_217:
F_133 ( V_2 ) ;
return V_135 ;
}
