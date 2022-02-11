static void * F_1 ( const struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
T_1 * V_5 = NULL ;
if ( V_3 >= V_6 )
V_5 = F_2 ( V_2 ) + V_3 - V_6 ;
else if ( V_3 >= V_7 )
V_5 = F_3 ( V_2 ) + V_3 - V_7 ;
if ( V_5 >= V_2 -> V_8 && V_5 + V_4 <= F_4 ( V_2 ) )
return V_5 ;
return NULL ;
}
static inline void * F_5 ( const struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , void * V_9 )
{
if ( V_3 >= 0 )
return F_6 ( V_2 , V_3 , V_4 , V_9 ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_7 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_12 ;
struct F_7 * V_13 ;
V_12 = F_8 ( V_11 , V_2 ) ;
if ( V_12 )
return V_12 ;
F_9 () ;
V_13 = F_10 ( V_11 -> F_7 ) ;
if ( V_13 ) {
unsigned int V_14 = F_11 ( V_13 , V_2 ) ;
V_12 = V_14 ? F_12 ( V_2 , V_14 ) : - V_15 ;
}
F_13 () ;
return V_12 ;
}
unsigned int F_14 ( const struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
void * V_5 ;
T_2 V_18 = 0 ;
T_2 V_19 = 0 ;
T_2 V_20 [ V_21 ] ;
T_2 V_22 ;
int V_3 ;
for (; ; V_17 ++ ) {
#if F_15 ( V_23 )
#define F_16 (fentry->k)
#else
const T_2 F_16 = V_17 -> V_3 ;
#endif
switch ( V_17 -> V_24 ) {
case V_25 :
V_18 += V_19 ;
continue;
case V_26 :
V_18 += F_16 ;
continue;
case V_27 :
V_18 -= V_19 ;
continue;
case V_28 :
V_18 -= F_16 ;
continue;
case V_29 :
V_18 *= V_19 ;
continue;
case V_30 :
V_18 *= F_16 ;
continue;
case V_31 :
if ( V_19 == 0 )
return 0 ;
V_18 /= V_19 ;
continue;
case V_32 :
V_18 = F_17 ( V_18 , F_16 ) ;
continue;
case V_33 :
V_18 &= V_19 ;
continue;
case V_34 :
V_18 &= F_16 ;
continue;
case V_35 :
V_18 |= V_19 ;
continue;
case V_36 :
V_18 |= F_16 ;
continue;
case V_37 :
V_18 <<= V_19 ;
continue;
case V_38 :
V_18 <<= F_16 ;
continue;
case V_39 :
V_18 >>= V_19 ;
continue;
case V_40 :
V_18 >>= F_16 ;
continue;
case V_41 :
V_18 = - V_18 ;
continue;
case V_42 :
V_17 += F_16 ;
continue;
case V_43 :
V_17 += ( V_18 > F_16 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_46 :
V_17 += ( V_18 >= F_16 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_47 :
V_17 += ( V_18 == F_16 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_48 :
V_17 += ( V_18 & F_16 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_49 :
V_17 += ( V_18 > V_19 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_50 :
V_17 += ( V_18 >= V_19 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_51 :
V_17 += ( V_18 == V_19 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_52 :
V_17 += ( V_18 & V_19 ) ? V_17 -> V_44 : V_17 -> V_45 ;
continue;
case V_53 :
V_3 = F_16 ;
V_54:
V_5 = F_5 ( V_2 , V_3 , 4 , & V_22 ) ;
if ( V_5 != NULL ) {
V_18 = F_18 ( V_5 ) ;
continue;
}
return 0 ;
case V_55 :
V_3 = F_16 ;
V_56:
V_5 = F_5 ( V_2 , V_3 , 2 , & V_22 ) ;
if ( V_5 != NULL ) {
V_18 = F_19 ( V_5 ) ;
continue;
}
return 0 ;
case V_57 :
V_3 = F_16 ;
V_58:
V_5 = F_5 ( V_2 , V_3 , 1 , & V_22 ) ;
if ( V_5 != NULL ) {
V_18 = * ( T_1 * ) V_5 ;
continue;
}
return 0 ;
case V_59 :
V_18 = V_2 -> V_60 ;
continue;
case V_61 :
V_19 = V_2 -> V_60 ;
continue;
case V_62 :
V_3 = V_19 + F_16 ;
goto V_54;
case V_63 :
V_3 = V_19 + F_16 ;
goto V_56;
case V_64 :
V_3 = V_19 + F_16 ;
goto V_58;
case V_65 :
V_5 = F_5 ( V_2 , F_16 , 1 , & V_22 ) ;
if ( V_5 != NULL ) {
V_19 = ( * ( T_1 * ) V_5 & 0xf ) << 2 ;
continue;
}
return 0 ;
case V_66 :
V_18 = F_16 ;
continue;
case V_67 :
V_19 = F_16 ;
continue;
case V_68 :
V_18 = V_20 [ F_16 ] ;
continue;
case V_69 :
V_19 = V_20 [ F_16 ] ;
continue;
case V_70 :
V_19 = V_18 ;
continue;
case V_71 :
V_18 = V_19 ;
continue;
case V_72 :
return F_16 ;
case V_73 :
return V_18 ;
case V_74 :
V_20 [ F_16 ] = V_18 ;
continue;
case V_75 :
V_20 [ F_16 ] = V_19 ;
continue;
case V_76 :
V_18 = F_20 ( V_2 -> V_77 ) ;
continue;
case V_78 :
V_18 = V_2 -> V_79 ;
continue;
case V_80 :
if ( ! V_2 -> V_81 )
return 0 ;
V_18 = V_2 -> V_81 -> V_82 ;
continue;
case V_83 :
V_18 = V_2 -> V_84 ;
continue;
case V_85 :
V_18 = V_2 -> V_86 ;
continue;
case V_87 :
if ( ! V_2 -> V_81 )
return 0 ;
V_18 = V_2 -> V_81 -> type ;
continue;
case V_88 :
V_18 = V_2 -> V_89 ;
continue;
case V_90 :
V_18 = F_21 () ;
continue;
case V_91 : {
struct V_92 * V_93 ;
if ( F_22 ( V_2 ) )
return 0 ;
if ( V_18 > V_2 -> V_60 - sizeof( struct V_92 ) )
return 0 ;
V_93 = F_23 ( (struct V_92 * ) & V_2 -> V_94 [ V_18 ] ,
V_2 -> V_60 - V_18 , V_19 ) ;
if ( V_93 )
V_18 = ( void * ) V_93 - ( void * ) V_2 -> V_94 ;
else
V_18 = 0 ;
continue;
}
case V_95 : {
struct V_92 * V_93 ;
if ( F_22 ( V_2 ) )
return 0 ;
if ( V_18 > V_2 -> V_60 - sizeof( struct V_92 ) )
return 0 ;
V_93 = (struct V_92 * ) & V_2 -> V_94 [ V_18 ] ;
if ( V_93 -> V_96 > V_18 - V_2 -> V_60 )
return 0 ;
V_93 = F_24 ( V_93 , V_19 ) ;
if ( V_93 )
V_18 = ( void * ) V_93 - ( void * ) V_2 -> V_94 ;
else
V_18 = 0 ;
continue;
}
default:
F_25 ( 1 , L_1 ,
V_17 -> V_24 , V_17 -> V_44 ,
V_17 -> V_45 , V_17 -> V_3 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_26 ( struct V_16 * V_13 , int V_97 )
{
T_3 * V_98 , V_99 = 0 ;
int V_100 , V_101 = 0 ;
F_27 ( V_21 > 16 ) ;
V_98 = F_28 ( V_97 * sizeof( * V_98 ) , V_102 ) ;
if ( ! V_98 )
return - V_103 ;
memset ( V_98 , 0xff , V_97 * sizeof( * V_98 ) ) ;
for ( V_100 = 0 ; V_100 < V_97 ; V_100 ++ ) {
V_99 &= V_98 [ V_100 ] ;
switch ( V_13 [ V_100 ] . V_24 ) {
case V_74 :
case V_75 :
V_99 |= ( 1 << V_13 [ V_100 ] . V_3 ) ;
break;
case V_68 :
case V_69 :
if ( ! ( V_99 & ( 1 << V_13 [ V_100 ] . V_3 ) ) ) {
V_101 = - V_104 ;
goto error;
}
break;
case V_42 :
V_98 [ V_100 + 1 + V_13 [ V_100 ] . V_3 ] &= V_99 ;
V_99 = ~ 0 ;
break;
case V_47 :
case V_51 :
case V_46 :
case V_50 :
case V_43 :
case V_49 :
case V_52 :
case V_48 :
V_98 [ V_100 + 1 + V_13 [ V_100 ] . V_44 ] &= V_99 ;
V_98 [ V_100 + 1 + V_13 [ V_100 ] . V_45 ] &= V_99 ;
V_99 = ~ 0 ;
break;
}
}
error:
F_29 ( V_98 ) ;
return V_101 ;
}
int F_30 ( struct V_16 * V_13 , int V_97 )
{
static const T_1 V_105 [] = {
[ V_106 | V_107 | V_108 ] = V_26 ,
[ V_106 | V_107 | V_109 ] = V_25 ,
[ V_106 | V_110 | V_108 ] = V_28 ,
[ V_106 | V_110 | V_109 ] = V_27 ,
[ V_106 | V_111 | V_108 ] = V_30 ,
[ V_106 | V_111 | V_109 ] = V_29 ,
[ V_106 | V_112 | V_109 ] = V_31 ,
[ V_106 | V_113 | V_108 ] = V_34 ,
[ V_106 | V_113 | V_109 ] = V_33 ,
[ V_106 | V_114 | V_108 ] = V_36 ,
[ V_106 | V_114 | V_109 ] = V_35 ,
[ V_106 | V_115 | V_108 ] = V_38 ,
[ V_106 | V_115 | V_109 ] = V_37 ,
[ V_106 | V_116 | V_108 ] = V_40 ,
[ V_106 | V_116 | V_109 ] = V_39 ,
[ V_106 | V_117 ] = V_41 ,
[ V_118 | V_119 | V_120 ] = V_53 ,
[ V_118 | V_121 | V_120 ] = V_55 ,
[ V_118 | V_122 | V_120 ] = V_57 ,
[ V_118 | V_119 | V_123 ] = V_59 ,
[ V_118 | V_119 | V_124 ] = V_62 ,
[ V_118 | V_121 | V_124 ] = V_63 ,
[ V_118 | V_122 | V_124 ] = V_64 ,
[ V_118 | V_125 ] = V_66 ,
[ V_126 | V_119 | V_123 ] = V_61 ,
[ V_126 | V_122 | V_127 ] = V_65 ,
[ V_126 | V_125 ] = V_67 ,
[ V_128 | V_129 ] = V_70 ,
[ V_128 | V_130 ] = V_71 ,
[ V_131 | V_108 ] = V_72 ,
[ V_131 | V_132 ] = V_73 ,
[ V_106 | V_112 | V_108 ] = V_32 ,
[ V_118 | V_133 ] = V_68 ,
[ V_126 | V_133 ] = V_69 ,
[ V_134 ] = V_74 ,
[ V_135 ] = V_75 ,
[ V_136 | V_137 ] = V_42 ,
[ V_136 | V_138 | V_108 ] = V_47 ,
[ V_136 | V_138 | V_109 ] = V_51 ,
[ V_136 | V_139 | V_108 ] = V_46 ,
[ V_136 | V_139 | V_109 ] = V_50 ,
[ V_136 | V_140 | V_108 ] = V_43 ,
[ V_136 | V_140 | V_109 ] = V_49 ,
[ V_136 | V_141 | V_108 ] = V_48 ,
[ V_136 | V_141 | V_109 ] = V_52 ,
} ;
int V_100 ;
if ( V_97 == 0 || V_97 > V_142 )
return - V_104 ;
for ( V_100 = 0 ; V_100 < V_97 ; V_100 ++ ) {
struct V_16 * V_143 = & V_13 [ V_100 ] ;
T_3 V_24 = V_143 -> V_24 ;
if ( V_24 >= F_31 ( V_105 ) )
return - V_104 ;
V_24 = V_105 [ V_24 ] ;
if ( ! V_24 )
return - V_104 ;
switch ( V_24 ) {
case V_32 :
if ( V_143 -> V_3 == 0 )
return - V_104 ;
V_143 -> V_3 = F_32 ( V_143 -> V_3 ) ;
break;
case V_68 :
case V_69 :
case V_74 :
case V_75 :
if ( V_143 -> V_3 >= V_21 )
return - V_104 ;
break;
case V_42 :
if ( V_143 -> V_3 >= ( unsigned ) ( V_97 - V_100 - 1 ) )
return - V_104 ;
break;
case V_47 :
case V_51 :
case V_46 :
case V_50 :
case V_43 :
case V_49 :
case V_52 :
case V_48 :
if ( V_100 + V_143 -> V_44 + 1 >= V_97 ||
V_100 + V_143 -> V_45 + 1 >= V_97 )
return - V_104 ;
break;
case V_53 :
case V_55 :
case V_57 :
#define F_33 ( T_4 ) case SKF_AD_OFF + SKF_AD_##CODE: \
code = BPF_S_ANC_##CODE; \
break
switch ( V_143 -> V_3 ) {
F_33 ( V_144 ) ;
F_33 ( V_145 ) ;
F_33 ( V_146 ) ;
F_33 ( V_147 ) ;
F_33 ( V_148 ) ;
F_33 ( V_149 ) ;
F_33 ( V_150 ) ;
F_33 ( V_151 ) ;
F_33 ( V_152 ) ;
F_33 ( V_153 ) ;
}
}
V_143 -> V_24 = V_24 ;
}
switch ( V_13 [ V_97 - 1 ] . V_24 ) {
case V_72 :
case V_73 :
return F_26 ( V_13 , V_97 ) ;
}
return - V_104 ;
}
void F_34 ( struct V_154 * V_155 )
{
struct F_7 * V_156 = F_35 ( V_155 , struct F_7 , V_155 ) ;
F_36 ( V_156 ) ;
F_29 ( V_156 ) ;
}
int F_37 ( struct V_157 * V_158 , struct V_10 * V_11 )
{
struct F_7 * V_156 , * V_159 ;
unsigned int V_160 = sizeof( struct V_16 ) * V_158 -> V_60 ;
int V_12 ;
if ( V_158 -> V_13 == NULL )
return - V_104 ;
V_156 = F_38 ( V_11 , V_160 + sizeof( * V_156 ) , V_102 ) ;
if ( ! V_156 )
return - V_103 ;
if ( F_39 ( V_156 -> V_161 , V_158 -> V_13 , V_160 ) ) {
F_40 ( V_11 , V_156 , V_160 + sizeof( * V_156 ) ) ;
return - V_162 ;
}
F_41 ( & V_156 -> V_163 , 1 ) ;
V_156 -> V_60 = V_158 -> V_60 ;
V_156 -> V_164 = F_14 ;
V_12 = F_30 ( V_156 -> V_161 , V_156 -> V_60 ) ;
if ( V_12 ) {
F_42 ( V_11 , V_156 ) ;
return V_12 ;
}
F_43 ( V_156 ) ;
V_159 = F_44 ( V_11 -> F_7 ,
F_45 ( V_11 ) ) ;
F_46 ( V_11 -> F_7 , V_156 ) ;
if ( V_159 )
F_42 ( V_11 , V_159 ) ;
return 0 ;
}
int F_47 ( struct V_10 * V_11 )
{
int V_101 = - V_165 ;
struct F_7 * V_13 ;
V_13 = F_44 ( V_11 -> F_7 ,
F_45 ( V_11 ) ) ;
if ( V_13 ) {
F_46 ( V_11 -> F_7 , NULL ) ;
F_42 ( V_11 , V_13 ) ;
V_101 = 0 ;
}
return V_101 ;
}
