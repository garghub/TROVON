static T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 = NULL ;
V_2 =
F_2 ( V_1 -> V_3 , & V_1 -> V_4 , & V_1 -> V_5 ,
V_1 -> V_6 , 0 , 0 , 0 ) ;
if ( V_2 == NULL ) {
V_2 =
F_3 ( V_1 -> V_3 , & V_1 -> V_4 ,
& V_1 -> V_5 , V_1 -> V_6 , 0 , 0 , 0 ) ;
}
return V_2 ;
}
static void
F_4 ( T_3 * V_7 , int V_8 , T_4 * V_9 )
{
T_5 type ;
T_5 V_10 ;
T_6 * V_11 ;
T_4 * V_12 = NULL ;
T_7 V_13 ;
T_7 V_14 ;
static const int * V_15 [] = {
& V_16 ,
& V_17 ,
& V_18 ,
& V_19 ,
& V_20 ,
& V_21 ,
& V_22 ,
& V_23 ,
& V_24 ,
& V_25 ,
& V_26 ,
NULL
} ;
if ( ! V_9 )
return;
while ( F_5 ( V_7 , V_8 ) > 0 ) {
type = F_6 ( V_7 , V_8 + 0 ) ;
if ( type ) {
V_10 = F_6 ( V_7 , V_8 + 1 ) ;
} else {
V_10 = 0 ;
}
V_12 = F_7 ( V_9 , V_7 , V_8 ,
1 , V_27 , & V_11 ,
L_1 , F_8 ( type ,
V_28 ,
L_2 ) ) ;
F_9 ( V_12 , V_29 ,
V_7 , V_8 , 1 ,
V_30 ) ;
V_8 ++ ;
if ( type != V_31 )
{
F_10 ( V_11 , V_10 + 2 ) ;
F_9 ( V_12 , V_32 ,
V_7 , V_8 , 1 ,
V_30 ) ;
V_8 ++ ;
}
switch ( type ) {
case V_31 :
break;
case V_33 :
F_9 ( V_12 , V_34 , V_7 ,
V_8 , 2 , V_30 ) ;
V_8 += 2 ;
F_9 ( V_12 , V_35 ,
V_7 , V_8 , 2 ,
V_30 ) ;
V_8 += 2 ;
F_11 ( V_12 , V_7 , V_8 , V_36 , V_37 , V_15 , V_30 ) ;
V_8 += 2 ;
V_13 = ( V_10 - 6 ) / 4 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_9 ( V_12 ,
V_38 , V_7 ,
V_8 , 4 ,
V_30 ) ;
V_8 += 4 ;
}
break;
case V_39 :
for ( V_14 = 0 ; V_14 < V_10 ; V_14 ++ ) {
F_9 ( V_12 ,
V_40 ,
V_7 , V_8 , 1 ,
V_30 ) ;
V_8 ++ ;
}
break;
case V_41 :
F_9 ( V_12 ,
V_42 , V_7 ,
V_8 , V_10 , V_43 ) ;
V_8 += V_10 ;
break;
default:
if ( V_10 != 0 ) {
F_9 ( V_12 , V_44 , V_7 , V_8 , V_10 - 4 , V_43 ) ;
V_8 += V_10 ;
}
break;
}
}
}
static T_8
F_12 ( T_3 * V_7 , T_7 V_8 ,
T_4 * V_45 ,
T_6 * V_46 )
{
T_9 V_47 , V_48 ;
T_8 V_49 ;
T_5 V_50 ;
V_49 = FALSE ;
V_47 = F_13 ( V_7 , V_8 ) ;
V_48 =
F_14 ( V_47 , F_5 ( V_7 , V_8 ) ) ;
V_50 = F_6 ( V_7 , V_8 + 3 ) ;
F_15 ( V_45 , V_51 , V_7 ,
V_8 + 3 , 1 , V_50 ) ;
V_8 += 4 ;
switch ( V_50 ) {
case V_52 :
F_16 ( V_46 , L_3 ) ;
if ( V_48 > 4 ) {
F_9 ( V_45 , V_53 , V_7 , V_8 , V_48 - 4 , V_43 ) ;
}
break;
default:
V_49 = TRUE ;
}
return V_49 ;
}
static T_8
F_17 ( T_3 * V_7 , T_7 V_8 ,
T_4 * V_45 ,
T_6 * V_46 )
{
T_6 * V_54 ;
T_4 * V_55 ;
T_9 V_47 , V_48 ;
T_7 V_56 ;
T_10 V_57 ;
T_5 V_58 ;
T_5 V_59 ;
T_8 V_49 ;
T_5 V_50 ;
V_49 = FALSE ;
V_47 = F_13 ( V_7 , V_8 ) ;
V_48 =
F_14 ( V_47 , F_5 ( V_7 , V_8 ) ) ;
V_56 = V_8 + V_48 ;
V_50 = F_6 ( V_7 , V_8 + 3 ) ;
F_15 ( V_45 , V_51 , V_7 ,
V_8 + 3 , 1 , V_50 ) ;
V_8 += 4 ;
switch ( V_50 ) {
case V_60 :
F_16 ( V_46 , L_4 ) ;
while ( V_8 + 4 <= V_56 ) {
if ( F_5 ( V_7 , V_8 ) < 4 ) {
break;
}
V_55 = F_18 ( V_45 ,
V_7 , V_8 , 4 ,
V_61 , & V_54 , L_5 ) ;
V_57 = ( T_10 ) F_13 ( V_7 , V_8 ) ;
V_59 = F_6 ( V_7 , V_8 + 2 ) ;
V_57 = ( V_57 << 4 ) + ( V_59 >> 4 ) ;
F_15 ( V_55 ,
V_62 , V_7 ,
V_8 , 3 , V_57 << 4 ) ;
F_16 ( V_54 , L_6 , V_57 ) ;
F_15 ( V_55 ,
V_63 , V_7 ,
V_8 + 2 , 1 , V_59 ) ;
F_19 ( V_54 , L_7 ,
( V_59 >> 1 ) & 0x07 ) ;
F_20 ( V_55 ,
V_64 , V_7 ,
V_8 + 2 , 1 , V_59 ) ;
F_19 ( V_54 , L_8 ,
V_59 & 0x01 ) ;
V_58 = F_6 ( V_7 , V_8 + 3 ) ;
F_9 ( V_55 ,
V_65 , V_7 ,
V_8 + 3 , 1 , V_30 ) ;
F_19 ( V_54 , L_9 , V_58 ) ;
V_8 += 4 ;
}
if ( V_8 < V_56 ) {
F_9 ( V_45 , V_66 , V_7 , V_8 , V_56 - V_8 , V_43 ) ;
}
break;
default:
V_49 = TRUE ;
break;
}
return V_49 ;
}
static T_8
F_21 ( T_3 * V_7 , T_7 V_8 ,
T_4 * V_45 ,
T_6 * V_46 )
{
T_4 * V_67 = NULL ;
T_4 * V_68 ;
T_9 V_47 , V_48 ;
T_7 V_56 ;
T_5 V_50 ;
T_8 V_49 ;
T_5 V_69 ;
T_5 V_70 ;
T_5 V_71 ;
T_9 V_72 ;
T_5 V_73 = 0 ;
V_49 = FALSE ;
V_47 = F_13 ( V_7 , V_8 ) ;
V_48 =
F_14 ( V_47 , F_5 ( V_7 , V_8 ) ) ;
V_56 = V_8 + V_48 ;
V_50 = F_6 ( V_7 , V_8 + 3 ) ;
F_16 ( V_46 , L_10 ) ;
if ( F_5 ( V_7 , V_8 ) < 4 ) {
return TRUE ;
}
V_69 = ( V_50 & V_74 ) >> 3 ;
V_70 = ( V_50 & V_75 ) >> 2 ;
V_71 = ( V_50 & V_76 ) >> 1 ;
{
static const T_7 * V_77 [] = {
& V_78 ,
& V_79 ,
& V_80 ,
& V_81 ,
& V_82 ,
& V_83 ,
NULL
} ;
F_11 ( V_45 , V_7 , V_8 + 3 ,
V_51 ,
V_84 ,
V_77 , V_30 ) ;
}
V_8 += 4 ;
if ( V_69 ) {
F_9 ( V_45 , V_85 , V_7 , V_8 , 4 , V_43 ) ;
V_8 += 4 ;
}
if ( V_70 && ( V_56 >= V_8 + 2 ) ) {
V_72 = F_13 ( V_7 , V_8 ) ;
V_68 = F_18 ( V_45 , V_7 , V_8 ,
V_72 == 1 ? 8 : 10 , V_86 , NULL ,
L_11 ) ;
F_15 ( V_68 ,
V_87 , V_7 , V_8 , 2 ,
V_72 ) ;
V_8 += 2 ;
F_9 ( V_68 , V_88 , V_7 , V_8 , 2 , V_43 ) ;
V_8 += 2 ;
switch( V_72 ) {
case 1 :
F_9 ( V_68 , V_89 , V_7 , V_8 , 4 , V_30 ) ;
break;
case 2 :
F_9 ( V_68 , V_90 , V_7 , V_8 , 16 , V_43 ) ;
break;
default:
F_9 ( V_68 , V_91 , V_7 , V_8 , V_8 - V_56 , V_43 ) ;
return FALSE ;
}
}
if ( V_71 ) {
if ( V_56 >= V_8 + 1 ) {
V_73 = F_6 ( V_7 , V_8 ) ;
V_67 = F_18 ( V_45 , V_7 ,
V_8 , V_73 , V_92 , NULL ,
L_12 ) ;
F_9 ( V_67 , V_93 , V_7 , V_8 , 1 , V_30 ) ;
}
if ( V_56 >= V_8 + 1 + V_73 ) {
F_9 ( V_67 , V_94 , V_7 , V_8 + 1 , V_73 , V_95 | V_43 ) ;
}
}
return V_49 ;
}
static void
F_22 ( T_3 * V_7 , T_7 V_8 , T_4 * V_9 )
{
T_5 V_96 ;
T_5 V_97 ;
T_5 V_50 ;
T_9 V_98 , V_99 ;
T_9 V_47 , V_48 ;
T_6 * V_11 , * V_46 , * V_100 ;
T_4 * V_101 , * V_45 ;
T_7 V_56 ;
T_10 V_102 ;
T_8 V_49 ;
T_5 V_103 ;
if ( ! V_9 )
return;
V_101 = NULL ;
V_103 = 0 ;
V_102 = F_5 ( V_7 , V_8 ) ;
V_11 = F_23 ( V_9 , V_104 , V_7 ,
V_8 , V_102 ,
L_13 ) ;
if ( V_102 < 4 ) {
return;
}
V_101 = F_24 ( V_11 , V_105 ) ;
V_96 = F_25 ( F_6 ( V_7 , V_8 ) ) ;
F_15 ( V_101 , V_106 , V_7 , V_8 , 1 ,
V_96 ) ;
F_9 ( V_101 , V_107 ,
V_7 , V_8 , 2 , V_30 ) ;
V_98 = F_13 ( V_7 , V_8 + 2 ) ;
V_99 = F_26 ( V_7 , V_8 , V_102 ) ;
if ( V_99 == 0 ) {
F_27 ( V_101 , V_108 ,
V_7 , V_8 + 2 , 2 , V_98 ,
L_14 ,
V_98 ) ;
V_100 =
F_20 ( V_101 ,
V_109 , V_7 ,
V_8 + 2 , 2 , FALSE ) ;
} else {
F_27 ( V_101 , V_108 ,
V_7 , V_8 + 2 , 2 , V_98 ,
L_15 ,
V_98 , F_28 ( V_98 ,
V_99 ) ) ;
V_100 =
F_20 ( V_101 ,
V_109 , V_7 ,
V_8 + 2 , 2 , TRUE ) ;
}
F_29 ( V_100 ) ;
if ( V_96 != 1 && V_96 != 2 ) {
F_19 ( V_11 , L_16 ) ;
return;
}
V_8 += 4 ;
while ( F_5 ( V_7 , V_8 ) >=
4 ) {
V_47 = F_13 ( V_7 , V_8 ) ;
V_48 =
F_14 ( V_47 ,
F_5 ( V_7 , V_8 ) ) ;
V_56 = V_8 + V_48 ;
V_45 = F_18 ( V_101 , V_7 , V_8 ,
F_30 ( V_48 , 4 ) ,
V_110 , & V_46 , L_17 ) ;
F_15 ( V_45 , V_111 ,
V_7 , V_8 , 2 , V_47 ) ;
V_97 = F_6 ( V_7 , V_8 + 2 ) ;
F_15 ( V_45 , V_112 ,
V_7 , V_8 + 2 , 1 , V_97 ) ;
V_50 = F_6 ( V_7 , V_8 + 3 ) ;
if ( V_47 < 4 ) {
F_16 ( V_46 ,
L_18 ) ;
break;
}
switch ( V_97 ) {
case V_113 :
V_49 =
F_17 ( V_7 , V_8 ,
V_45 ,
V_46 ) ;
break;
case V_114 :
V_49 =
F_21 ( V_7 ,
V_8 ,
V_45 ,
V_46 ) ;
V_103 ++ ;
if ( V_103 > 4 ) {
F_16 ( V_46 ,
L_19 ) ;
}
break;
case V_115 :
V_49 =
F_12 ( V_7 ,
V_8 ,
V_45 ,
V_46 ) ;
break;
default:
V_49 = TRUE ;
break;
}
V_8 += 4 ;
if ( V_49 == TRUE ) {
F_16 ( V_46 ,
L_20 ,
V_97 , V_50 ) ;
if ( V_48 > 4 ) {
F_9 ( V_45 , V_53 , V_7 , V_8 , V_48 - 4 , V_43 ) ;
}
}
if ( V_48 < V_47 ) {
F_19 ( V_46 , L_21 ) ;
}
V_8 = V_56 ;
}
}
static T_11 * F_31 ( T_2 * V_1 ,
T_4 * V_9 ,
T_12 * V_116 )
{
T_1 * V_117 ;
T_13 * V_118 ;
T_11 * V_119 ;
T_14 V_120 [ 3 ] ;
T_6 * V_121 ;
V_117 = F_1 ( V_1 ) ;
V_118 = ( T_13 * ) F_32 ( V_117 , V_122 ) ;
if ( V_118 == NULL ) {
V_118 = F_33 ( F_34 () , T_13 ) ;
V_118 -> V_123 = F_35 ( F_34 () ) ;
V_118 -> V_124 = F_35 ( F_34 () ) ;
F_36 ( V_117 , V_122 ,
V_118 ) ;
}
if ( ! F_37 ( V_1 ) ) {
V_120 [ 0 ] . V_10 = 2 ;
V_120 [ 0 ] . V_116 = V_116 ;
V_120 [ 1 ] . V_10 = 0 ;
V_120 [ 1 ] . V_116 = NULL ;
V_119 = F_33 ( F_34 () , T_11 ) ;
V_119 -> V_125 = V_1 -> V_3 ;
V_119 -> V_126 = 0 ;
V_119 -> V_127 = V_1 -> V_128 ;
F_38 ( & V_119 -> V_129 ) ;
F_39 ( V_118 -> V_123 , V_120 ,
( void * ) V_119 ) ;
} else {
T_12 V_130 = V_1 -> V_3 ;
V_120 [ 0 ] . V_10 = 2 ;
V_120 [ 0 ] . V_116 = V_116 ;
V_120 [ 1 ] . V_10 = 1 ;
V_120 [ 1 ] . V_116 = & V_130 ;
V_120 [ 2 ] . V_10 = 0 ;
V_120 [ 2 ] . V_116 = NULL ;
V_119 =
( T_11 * ) F_40 ( V_118 -> V_124 ,
V_120 ) ;
}
if ( V_119 == NULL ) {
if ( F_37 ( V_1 ) ) {
V_121 = F_9 ( V_9 , V_131 , NULL , 0 , 0 ,
V_43 ) ;
F_41 ( V_121 ) ;
F_42 ( V_1 -> V_132 , V_133 , L_22 ) ;
F_43 ( V_1 , V_121 , & V_134 ,
L_23 ) ;
}
return NULL ;
}
if ( V_119 -> V_126 ) {
V_121 = F_15 ( V_9 , V_135 , NULL , 0 , 0 ,
V_119 -> V_126 ) ;
F_41 ( V_121 ) ;
F_42 ( V_1 -> V_132 , V_133 , L_24 ,
V_119 -> V_126 ) ;
}
return V_119 ;
}
static T_11 * F_44 ( T_2 * V_1 ,
T_4 * V_9 ,
T_12 * V_116 )
{
T_1 * V_117 ;
T_13 * V_118 ;
T_11 * V_119 ;
T_14 V_120 [ 3 ] ;
T_6 * V_121 ;
T_15 V_136 ;
double V_129 ;
V_117 =
F_2 ( V_1 -> V_3 , & V_1 -> V_4 , & V_1 -> V_5 ,
V_1 -> V_6 , 0 , 0 , 0 ) ;
if ( V_117 == NULL ) {
return NULL ;
}
V_118 = ( T_13 * ) F_32 ( V_117 , V_122 ) ;
if ( V_118 == NULL ) {
return NULL ;
}
if ( ! F_37 ( V_1 ) ) {
T_12 V_130 ;
V_120 [ 0 ] . V_10 = 2 ;
V_120 [ 0 ] . V_116 = V_116 ;
V_120 [ 1 ] . V_10 = 0 ;
V_120 [ 1 ] . V_116 = NULL ;
V_119 =
( T_11 * ) F_40 ( V_118 -> V_123 ,
V_120 ) ;
if ( V_119 == NULL ) {
return NULL ;
}
if ( V_119 -> V_126 != 0 ) {
return NULL ;
}
V_119 -> V_126 = V_1 -> V_3 ;
V_120 [ 0 ] . V_10 = 2 ;
V_120 [ 0 ] . V_116 = V_116 ;
V_120 [ 1 ] . V_10 = 1 ;
V_120 [ 1 ] . V_116 = & V_130 ;
V_120 [ 2 ] . V_10 = 0 ;
V_120 [ 2 ] . V_116 = NULL ;
V_130 = V_119 -> V_125 ;
F_39 ( V_118 -> V_124 , V_120 ,
( void * ) V_119 ) ;
V_130 = V_119 -> V_126 ;
F_39 ( V_118 -> V_124 , V_120 ,
( void * ) V_119 ) ;
} else {
T_12 V_130 = V_1 -> V_3 ;
V_120 [ 0 ] . V_10 = 2 ;
V_120 [ 0 ] . V_116 = V_116 ;
V_120 [ 1 ] . V_10 = 1 ;
V_120 [ 1 ] . V_116 = & V_130 ;
V_120 [ 2 ] . V_10 = 0 ;
V_120 [ 2 ] . V_116 = NULL ;
V_119 =
( T_11 * ) F_40 ( V_118 -> V_124 ,
V_120 ) ;
if ( V_119 == NULL ) {
return NULL ;
}
}
V_121 = F_15 ( V_9 , V_137 , NULL , 0 , 0 ,
V_119 -> V_125 ) ;
F_41 ( V_121 ) ;
F_45 ( & V_136 , & V_1 -> V_128 , & V_119 -> V_127 ) ;
V_119 -> V_129 = V_136 ;
V_129 = F_46 ( & V_136 ) ;
V_121 = F_47 ( V_9 , V_138 ,
NULL , 0 , 0 , V_129 ,
L_25 , V_129 ) ;
F_41 ( V_121 ) ;
F_42 ( V_1 -> V_132 , V_133 , L_26 ,
V_119 -> V_125 ) ;
return V_119 ;
}
static T_12
F_48 ( T_3 * V_7 , T_7 V_8 , T_12 V_139 )
{
T_12 V_140 , V_141 ;
V_140 = F_49 ( V_7 , V_8 ) & 0x7fffffff ;
V_141 = F_50 ( V_7 , V_8 ) & 0x7fffffff ;
if ( V_140 < V_142 && V_141 >= V_142 ) {
return V_140 ;
}
if ( V_141 < V_142 && V_140 >= V_142 ) {
return V_141 ;
}
if ( V_140 < V_142 && V_141 < V_142 ) {
T_12 V_143 = V_140 ;
T_12 V_144 = V_141 ;
if ( V_140 < V_139 && V_140 <= ( V_142 / 4 )
&& V_139 >= ( V_142 - ( V_142 / 4 ) ) )
V_140 += V_142 ;
if ( V_141 < V_139 && V_141 <= ( V_142 / 4 )
&& V_139 >= ( V_142 - ( V_142 / 4 ) ) )
V_141 += V_142 ;
if ( ( V_140 - V_139 ) < ( V_141 - V_139 ) )
return V_143 ;
return V_144 ;
}
if ( ( V_140 - V_139 ) < ( V_141 - V_139 ) ) {
return V_140 ;
}
return V_141 ;
}
static T_8
F_51 ( const T_16 * T_17 V_145 , int V_8 V_145 , int T_18 V_145 , T_19 * V_146 , const union V_147 * T_20 V_145 )
{
F_52 ( V_146 , V_122 ) ;
return TRUE ;
}
static int
F_53 ( T_3 * V_7 , T_2 * V_1 , T_4 * V_9 , void * V_148 )
{
T_4 * V_149 = NULL ;
T_6 * V_11 , * V_150 ;
T_5 V_151 ;
T_5 V_152 ;
T_5 V_153 ;
T_10 V_154 , V_102 ;
T_9 V_98 , V_99 ;
const T_21 * V_155 , * V_156 ;
T_12 V_157 = 0 ;
T_12 V_158 = 0 ;
T_12 V_14 ;
T_8 V_159 ;
T_3 * V_160 ;
T_6 * V_161 ;
T_12 V_162 [ 2 ] ;
T_11 * V_163 = NULL ;
T_15 V_164 , V_165 ;
T_22 * V_166 = ( T_22 * ) V_148 ;
F_54 ( V_1 -> V_132 , V_167 , L_27 ) ;
F_55 ( V_1 -> V_132 , V_133 ) ;
V_151 = F_6 ( V_7 , 0 ) ;
V_152 = F_6 ( V_7 , 1 ) ;
V_98 = F_13 ( V_7 , 2 ) ;
V_153 = F_6 ( V_7 , 5 ) ;
V_155 =
F_56 ( V_151 , V_168 ,
L_28 ) ;
switch ( V_151 ) {
case V_169 :
V_156 =
F_8 ( V_152 , V_170 ,
L_29 ) ;
break;
case V_171 :
V_156 =
F_8 ( V_152 , V_172 ,
L_29 ) ;
break;
case V_173 :
V_156 =
F_8 ( V_152 , V_174 ,
L_29 ) ;
V_153 = 0 ;
break;
case V_175 :
switch ( V_152 ) {
case 0 :
case 16 :
V_155 = L_30 ;
break;
}
V_156 =
F_8 ( V_152 , V_176 ,
L_29 ) ;
break;
case V_177 :
V_156 =
F_8 ( V_152 , V_178 ,
L_29 ) ;
break;
case V_179 :
V_156 =
F_8 ( V_152 , V_180 ,
L_29 ) ;
break;
case V_181 :
V_156 =
F_8 ( V_152 , V_182 ,
L_29 ) ;
break;
default:
V_156 = NULL ;
break;
}
F_57 ( V_1 -> V_132 , V_133 , L_31 , V_155 ) ;
if ( V_156 ) {
F_42 ( V_1 -> V_132 , V_133 , L_32 , V_156 ) ;
}
V_154 = F_58 ( V_7 ) ;
V_102 = F_59 ( V_7 ) ;
V_11 = F_9 ( V_9 , V_122 , V_7 , 0 , V_154 , V_43 ) ;
V_149 = F_24 ( V_11 , V_183 ) ;
V_11 = F_9 ( V_149 , V_184 , V_7 , 0 , 1 ,
V_30 ) ;
F_19 ( V_11 , L_32 , V_155 ) ;
V_11 = F_9 ( V_149 , V_185 , V_7 , 1 , 1 ,
V_30 ) ;
if ( V_156 ) {
F_19 ( V_11 , L_32 , V_156 ) ;
}
V_150 = F_9 ( V_149 , V_186 , V_7 , 2 , 2 , V_30 ) ;
if ( ! V_1 -> V_187 && V_154 >= V_102
&& ! V_1 -> V_15 . V_188 ) {
V_99 = F_26 ( V_7 , 0 , V_102 ) ;
if ( V_99 == 0 ) {
V_161 = F_20 ( V_149 , V_189 , V_7 , 2 , 2 , FALSE ) ;
F_29 ( V_161 ) ;
F_19 ( V_150 , L_33 ) ;
} else {
V_161 = F_20 ( V_149 , V_189 , V_7 , 2 , 2 , TRUE ) ;
F_29 ( V_161 ) ;
F_19 ( V_150 , L_34 , F_28 ( V_98 , V_99 ) ) ;
F_43 ( V_1 , V_150 , & V_190 ,
L_35 , F_28 ( V_98 , V_99 ) ) ;
}
} else {
F_19 ( V_150 , L_36 ,
V_1 -> V_15 . V_188 ? L_37 : L_38 ) ;
}
switch ( V_151 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_9 ( V_149 , V_199 , V_7 , 4 , 2 ,
V_30 ) ;
F_9 ( V_149 , V_200 , V_7 , 4 , 2 ,
V_201 ) ;
F_9 ( V_149 , V_202 , V_7 , 6 , 2 ,
V_30 ) ;
F_9 ( V_149 , V_203 , V_7 , 6 ,
2 , V_201 ) ;
F_42 ( V_1 -> V_132 , V_133 ,
L_39 ,
F_13 ( V_7 , 4 ) , F_13 ( V_7 ,
6 ) ,
F_60 ( V_7 , 6 ) , ( V_166 != NULL ) ? V_166 -> V_204 : 0 ) ;
break;
case V_169 :
if ( V_153 > 0 ) {
F_9 ( V_149 , V_205 ,
V_7 , 5 , 1 ,
V_30 ) ;
V_11 = F_15 ( V_149 , V_206 ,
V_7 , 5 , 1 ,
V_153 * 4 ) ;
F_41 ( V_11 ) ;
}
switch ( V_152 ) {
case V_207 :
F_9 ( V_149 , V_208 , V_7 , 4 ,
2 , V_43 ) ;
F_9 ( V_149 , V_209 , V_7 , 6 ,
2 , V_30 ) ;
break;
default:
F_9 ( V_149 , V_208 , V_7 , 4 ,
4 , V_43 ) ;
}
break;
case V_175 :
F_61 ( V_149 , V_210 , V_7 , 4 , 1 , V_30 , & V_157 ) ;
F_61 ( V_149 , V_211 , V_7 , 5 , 1 , V_30 , & V_158 ) ;
V_11 = F_9 ( V_149 , V_212 , V_7 , 6 , 2 , V_30 ) ;
F_19 ( V_11 , L_32 , F_62 ( F_63 () , F_13 ( V_7 , 6 ) ) ) ;
break;
case V_179 :
F_9 ( V_149 , V_213 , V_7 , 4 , 1 , V_30 ) ;
if ( V_153 > 0 ) {
F_9 ( V_149 , V_205 ,
V_7 , 5 , 1 ,
V_30 ) ;
V_11 = F_15 ( V_149 , V_206 ,
V_7 , 5 , 1 ,
V_153 * 4 ) ;
F_41 ( V_11 ) ;
}
break;
case V_171 :
F_9 ( V_149 , V_214 , V_7 , 4 , 4 ,
V_30 ) ;
break;
case V_177 :
if ( V_153 > 0 ) {
F_9 ( V_149 , V_205 ,
V_7 , 5 , 1 ,
V_30 ) ;
V_11 = F_15 ( V_149 , V_206 ,
V_7 , 5 , 1 ,
V_153 * 4 ) ;
F_41 ( V_11 ) ;
}
}
switch ( V_151 ) {
case V_169 :
case V_177 :
case V_179 :
case V_215 :
case V_171 :
V_159 = V_1 -> V_15 . V_188 ;
V_1 -> V_15 . V_188 = TRUE ;
V_160 = F_64 ( V_7 , 8 ) ;
if ( V_151 == V_171 ) {
F_65 ( V_160 , ( ( F_6 ( V_7 , 8 ) & 0x0f ) * 4 ) + 8 ) ;
} else if ( V_153
&& ( F_59 ( V_7 ) >
( T_10 ) ( 8 + V_153 * 4 ) )
&& ( F_13 ( V_7 , 8 + 2 ) >
( T_10 ) V_153 * 4 ) ) {
F_65 ( V_160 ,
( ( F_6 ( V_7 , 8 ) & 0x0f ) + V_153 ) * 4 ) ;
} else {
if ( ( F_59 ( V_7 ) > 8 + 128 ) &&
V_216
&& ( F_13 ( V_7 , 8 + 2 ) > 128 ) ) {
F_65 ( V_160 , 128 ) ;
}
}
F_66 ( V_217 , V_160 , V_1 , V_149 ) ;
V_1 -> V_15 . V_188 = V_159 ;
if ( ( F_59 ( V_7 ) > 8 + 128 )
&& ( F_13 ( V_7 , 8 + 2 ) <= 128
|| V_216 ) ) {
F_22 ( V_7 , 8 + 128 , V_149 ) ;
}
break;
case V_191 :
case V_192 :
if ( V_151 == V_191 ) {
if ( ! V_1 -> V_15 . V_188 ) {
V_162 [ 0 ] =
( T_12 ) F_13 ( V_7 , 2 ) ;
if ( V_1 -> V_15 . V_218 )
V_162 [ 0 ] |= 0x00010000 ;
V_162 [ 1 ] =
( ( T_12 ) F_13 ( V_7 , 4 ) << 16 ) |
F_13 ( V_7 , 6 ) ;
V_163 =
F_44 ( V_1 , V_149 ,
V_162 ) ;
}
} else {
if ( ! V_1 -> V_15 . V_188 ) {
T_9 V_59 [ 2 ] ;
V_59 [ 0 ] = ~ F_13 ( V_7 , 2 ) ;
V_59 [ 1 ] = ~ 0x0800 ;
V_162 [ 0 ] =
F_67 ( ( T_5 * ) & V_59 ,
sizeof( V_59 ) ) ;
if ( V_162 [ 0 ] == 0 ) {
V_162 [ 0 ] = 0xffff ;
}
if ( V_1 -> V_15 . V_218 ) {
V_162 [ 0 ] |= 0x00010000 ;
}
V_162 [ 1 ] =
( ( T_12 ) F_13 ( V_7 , 4 ) << 16 ) |
F_13 ( V_7 , 6 ) ;
V_163 =
F_31 ( V_1 , V_149 ,
V_162 ) ;
}
}
if ( F_68 ( V_7 , 8 ) < 8 ) {
if ( F_68 ( V_7 , 8 ) > 0 ) {
F_69 ( F_64
( V_7 , 8 ) , V_1 , V_149 ) ;
}
break;
}
V_164 . V_219 = F_49 ( V_7 , 8 ) ;
V_164 . V_220 = F_49 ( V_7 , 8 + 4 ) ;
if ( ( T_12 ) ( V_164 . V_219 - V_1 -> V_128 . V_219 ) >=
3600 * 24 || V_164 . V_220 >= 1000000 ) {
V_164 . V_219 = F_50 ( V_7 , 8 ) ;
V_164 . V_220 = F_50 ( V_7 , 8 + 4 ) ;
}
if ( ( T_12 ) ( V_164 . V_219 - V_1 -> V_128 . V_219 ) <
3600 * 24 && V_164 . V_220 < 1000000 ) {
V_164 . V_220 *= 1000 ;
F_70 ( V_149 , V_221 ,
V_7 , 8 , 8 , & V_164 ) ;
F_45 ( & V_165 , & V_1 -> V_128 ,
& V_164 ) ;
V_11 = F_70 ( V_149 ,
V_222 ,
V_7 , 8 , 8 ,
& V_165 ) ;
F_41 ( V_11 ) ;
F_69 ( F_64 ( V_7 ,
8 + 8 ) ,
V_1 , V_149 ) ;
} else {
F_69 ( F_64 ( V_7 , 8 ) ,
V_1 , V_149 ) ;
}
break;
case V_175 :
if ( V_158 == 2 ) {
for ( V_14 = 0 ; V_14 < V_157 ; V_14 ++ ) {
F_9 ( V_149 , V_223 , V_7 , 8 + ( V_14 * 8 ) , 4 , V_43 ) ;
F_9 ( V_149 , V_224 , V_7 , 12 + ( V_14 * 8 ) , 4 , V_43 ) ;
}
if ( ( V_152 == 0 ) || ( V_152 == 16 ) ) {
F_4 ( V_7 , 8 + V_14 * 8 ,
V_149 ) ;
}
} else {
F_69 ( F_64 ( V_7 , 8 ) ,
V_1 , V_149 ) ;
}
break;
case V_193 :
case V_194 :
{
T_12 V_225 , V_226 ;
V_225 = ( T_12 ) ( ( ( V_1 -> V_128 . V_219 * 1000 ) +
( V_1 -> V_128 . V_220 / 1000000 ) ) %
86400000 ) ;
V_226 = F_48 ( V_7 , 8 , V_225 ) ;
V_11 = F_9 ( V_149 , V_227 , V_7 , 8 , 4 , V_30 ) ;
F_19 ( V_11 , L_40 , F_71 ( F_63 () , V_226 ) ) ;
V_11 = F_9 ( V_149 , V_228 , V_7 , 12 , 4 , V_30 ) ;
F_19 ( V_11 , L_40 , F_71 ( F_63 () , F_48 ( V_7 , 12 , V_225 ) ) ) ;
V_11 = F_9 ( V_149 , V_229 , V_7 , 16 , 4 , V_30 ) ;
F_19 ( V_11 , L_40 , F_71 ( F_63 () , F_48 ( V_7 , 16 , V_225 ) ) ) ;
}
break;
case V_197 :
case V_198 :
F_9 ( V_149 , V_230 , V_7 , 8 , 4 , V_30 ) ;
break;
}
if ( ! F_37 ( V_1 ) ) {
T_23 * V_231 = F_33 ( F_34 () , T_23 ) ;
V_231 -> type = V_151 ;
V_231 -> V_232 = V_152 ;
F_72 ( F_34 () , V_1 , V_122 , 0 , V_231 ) ;
}
if ( V_163 ) {
F_73 ( V_233 , V_1 , V_163 ) ;
}
return F_59 ( V_7 ) ;
}
void F_74 ( void )
{
static T_24 V_234 [] = {
{ & V_184 ,
{ L_41 , L_42 , V_235 , V_236 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_185 ,
{ L_43 , L_44 , V_235 , V_236 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_186 ,
{ L_45 , L_46 , V_238 , V_239 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_189 ,
{ L_47 , L_48 , V_240 ,
V_241 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_208 ,
{ L_49 , L_50 , V_242 ,
V_241 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_88 ,
{ L_51 , L_52 , V_242 ,
V_241 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_199 ,
{ L_53 , L_54 , V_238 , V_243 ,
NULL , 0x0 ,
L_55 , V_237 } } ,
{ & V_200 ,
{ L_56 , L_54 , V_238 , V_243 ,
NULL , 0x0 ,
L_57 , V_237 } } ,
{ & V_202 ,
{ L_58 , L_59 , V_238 ,
V_243 , NULL , 0x0 ,
L_60 , V_237 } } ,
{ & V_203 ,
{ L_61 , L_62 , V_238 ,
V_243 , NULL ,
0x0 , L_63 ,
V_237 } } ,
{ & V_209 ,
{ L_64 , L_65 , V_238 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_210 ,
{ L_66 , L_67 , V_235 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_211 ,
{ L_66 , L_68 , V_235 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_212 ,
{ L_69 , L_70 , V_238 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_213 ,
{ L_71 , L_72 , V_244 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_223 ,
{ L_73 , L_74 , V_245 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_224 ,
{ L_75 , L_76 , V_246 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_227 ,
{ L_77 , L_78 , V_244 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_228 ,
{ L_79 , L_80 , V_244 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_229 ,
{ L_81 , L_82 , V_244 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_230 ,
{ L_83 , L_84 , V_245 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_214 ,
{ L_85 , L_86 , V_245 , V_241 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_29 ,
{ L_87 , L_88 , V_235 , V_236 ,
F_75 ( V_28 ) , 0x0 , NULL , V_237 } } ,
{ & V_32 ,
{ L_89 , L_90 , V_235 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_40 ,
{ L_91 , L_92 , V_235 ,
V_236 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_34 ,
{ L_93 , L_94 , V_238 , V_236 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_35 ,
{ L_95 , L_96 , V_238 ,
V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_36 ,
{ L_97 , L_98 , V_238 , V_239 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_16 ,
{ L_99 , L_100 , V_240 , 16 ,
NULL , 0x8000 ,
L_101 , V_237 } } ,
{ & V_17 ,
{ L_102 , L_103 , V_240 , 16 , NULL , 0x4000 ,
L_104 , V_237 } } ,
{ & V_18 ,
{ L_105 , L_106 , V_240 , 16 , NULL , 0x2000 ,
L_107 , V_237 } } ,
{ & V_19 ,
{ L_108 , L_109 , V_240 , 16 , NULL ,
0x1000 ,
L_110 , V_237 } } ,
{ & V_20 ,
{ L_111 , L_112 , V_240 , 16 ,
NULL , 0x0800 ,
L_113 ,
V_237 } } ,
{ & V_21 ,
{ L_114 , L_115 , V_240 , 16 , NULL , 0x0400 ,
L_116 , V_237 } } ,
{ & V_22 ,
{ L_117 , L_118 , V_240 , 16 , NULL , 0x0200 ,
L_119 , V_237 } } ,
{ & V_23 ,
{ L_120 , L_121 , V_240 , 16 , NULL ,
0x0100 ,
L_122 , V_237 } } ,
{ & V_24 ,
{ L_123 , L_124 , V_240 , 16 , NULL ,
0x0080 ,
L_125 , V_237 } } ,
{ & V_25 ,
{ L_126 , L_127 , V_240 , 16 , NULL ,
0x0040 ,
L_128 , V_237 } } ,
{ & V_26 ,
{ L_51 , L_129 , V_238 , V_239 ,
NULL , 0x003f ,
NULL , V_237 } } ,
{ & V_38 ,
{ L_130 , L_131 , V_245 , V_241 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_42 ,
{ L_132 , L_133 , V_242 , V_241 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_44 ,
{ L_134 , L_135 , V_242 , V_241 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_104 ,
{ L_136 , L_137 , V_247 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_106 ,
{ L_138 , L_139 , V_235 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_107 ,
{ L_51 , L_140 , V_238 , V_239 , NULL ,
0x0fff ,
NULL , V_237 } } ,
{ & V_108 ,
{ L_45 , L_141 , V_238 , V_239 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_109 ,
{ L_47 , L_142 , V_240 ,
V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_111 ,
{ L_89 , L_143 , V_238 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_112 ,
{ L_144 , L_145 , V_235 , V_236 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_51 ,
{ L_146 , L_147 , V_235 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_53 ,
{ L_148 , L_149 , V_242 , V_241 , NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_62 ,
{ L_150 , L_151 , V_248 , V_236 , NULL ,
0x00fffff0 ,
NULL , V_237 } } ,
{ & V_63 ,
{ L_152 , L_153 , V_248 , V_236 ,
NULL , 0x0e ,
NULL , V_237 } } ,
{ & V_64 ,
{ L_154 , L_155 , V_240 , 24 ,
F_76 ( & V_249 ) , 0x01 ,
NULL , V_237 } } ,
{ & V_65 ,
{ L_156 , L_157 , V_235 , V_236 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_66 ,
{ L_148 , L_158 , V_242 , V_241 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_135 ,
{ L_159 , L_160 , V_250 , V_241 ,
F_77 ( V_251 ) , 0x0 ,
L_161 ,
V_237 } } ,
{ & V_131 ,
{ L_162 , L_163 , V_247 , V_241 ,
NULL , 0x0 ,
L_164 ,
V_237 } } ,
{ & V_137 ,
{ L_165 , L_166 , V_250 , V_241 ,
F_77 ( V_252 ) , 0x0 ,
L_167 , V_237 } } ,
{ & V_138 ,
{ L_168 , L_169 , V_253 , V_241 ,
NULL , 0x0 ,
L_170 ,
V_237 } } ,
{ & V_221 ,
{ L_171 , L_172 ,
V_254 ,
V_255 , NULL , 0x0 ,
L_173 ,
V_237 } } ,
{ & V_222 ,
{ L_174 ,
L_175 ,
V_256 , V_241 , NULL , 0x0 ,
L_176 ,
V_237 } } ,
{ & V_205 ,
{ L_89 , L_177 , V_235 ,
V_236 , NULL ,
0x0 ,
L_178 , V_237 } } ,
{ & V_206 ,
{ L_179 , L_180 , V_235 ,
V_236 , NULL ,
0x0 ,
L_181 , V_237 } } ,
{ & V_78 ,
{ L_182 , L_183 ,
V_235 , V_236 , F_75 ( V_257 ) ,
V_258 ,
NULL , V_237 } } ,
{ & V_79 ,
{ L_51 , L_184 ,
V_235 , V_236 , NULL , V_259 ,
NULL , V_237 } } ,
{ & V_80 ,
{ L_185 , L_186 , V_240 , 8 , NULL ,
V_74 ,
L_187 ,
V_237 } } ,
{ & V_81 ,
{ L_188 , L_189 , V_240 , 8 ,
F_76 ( & V_260 ) ,
V_75 ,
NULL , V_237 } } ,
{ & V_82 ,
{ L_190 , L_191 , V_240 , 8 ,
F_76 ( & V_260 ) ,
V_76 ,
NULL ,
V_237 } } ,
{ & V_83 ,
{ L_192 , L_193 , V_240 , 8 , F_76 ( & V_260 ) ,
V_261 ,
NULL , V_237 } } ,
{ & V_85 ,
{ L_194 , L_195 ,
V_244 , V_236 ,
NULL , 0x0 ,
NULL , V_237 } } ,
{ & V_87 ,
{ L_196 , L_197 ,
V_238 , V_236 ,
NULL , 0x0 ,
L_198 , V_237 } } ,
{ & V_89 ,
{ L_199 , L_200 , V_245 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_90 ,
{ L_199 , L_201 , V_262 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_91 ,
{ L_199 , L_202 , V_242 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_93 ,
{ L_203 , L_204 , V_235 , V_236 , NULL ,
0x0 ,
NULL , V_237 } } ,
{ & V_94 ,
{ L_205 , L_206 , V_263 , V_241 , NULL ,
0x0 ,
NULL , V_237 } } ,
} ;
static T_7 * V_264 [] = {
& V_183 ,
& V_27 ,
& V_37 ,
& V_105 ,
& V_110 ,
& V_61 ,
& V_84 ,
& V_86 ,
& V_92
} ;
static T_25 V_265 [] = {
{ & V_134 , { L_207 , V_266 , V_267 , L_208 , V_268 } } ,
{ & V_190 , { L_209 , V_269 , V_267 , L_210 , V_268 } } ,
} ;
T_26 * V_270 ;
T_27 * V_271 ;
V_122 =
F_78 ( L_211 ,
L_27 , L_212 ) ;
F_79 ( V_122 , V_234 , F_80 ( V_234 ) ) ;
V_271 = F_81 ( V_122 ) ;
F_82 ( V_271 , V_265 , F_80 ( V_265 ) ) ;
F_83 ( V_264 , F_80 ( V_264 ) ) ;
V_270 = F_84 ( V_122 , NULL ) ;
F_85 ( V_270 , L_213 ,
L_214 ,
L_215 ,
& V_216 ) ;
F_86 ( L_212 , F_53 , V_122 ) ;
V_233 = F_87 ( L_212 ) ;
}
void F_88 ( void )
{
T_28 V_272 ;
V_217 = F_89 ( L_216 , V_122 ) ;
V_272 = F_90 ( L_212 ) ;
F_91 ( L_217 , V_273 , V_272 ) ;
F_92 ( L_217 , V_273 , F_51 , V_122 ) ;
F_92 ( L_218 , V_273 , F_51 , V_122 ) ;
}
