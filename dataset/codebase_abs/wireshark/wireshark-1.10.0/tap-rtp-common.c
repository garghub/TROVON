T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) V_1 ;
const struct V_3 * V_5 = ( const struct V_3 * ) V_2 ;
if ( V_4 == V_5 )
return 0 ;
if ( V_4 == NULL || V_5 == NULL )
return 1 ;
if ( F_2 ( & ( V_4 -> V_6 ) , & ( V_5 -> V_6 ) )
&& ( V_4 -> V_7 == V_5 -> V_7 )
&& F_2 ( & ( V_4 -> V_8 ) , & ( V_5 -> V_8 ) )
&& ( V_4 -> V_9 == V_5 -> V_9 )
&& ( V_4 -> V_10 == V_5 -> V_10 ) )
return 0 ;
else
return 1 ;
}
void F_3 ( T_3 * V_11 )
{
T_4 * V_12 ;
if ( V_11 -> V_13 == V_14 ) {
V_12 = F_4 ( V_11 -> V_15 ) ;
while ( V_12 )
{
F_5 ( V_12 -> V_16 ) ;
V_12 = F_6 ( V_12 ) ;
}
F_7 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
V_11 -> V_17 = 0 ;
V_11 -> V_18 = 0 ;
}
++ ( V_11 -> V_19 ) ;
return;
}
void F_8 ( void * V_20 )
{
F_3 ( ( T_3 * ) V_20 ) ;
}
void F_9 ( T_5 * V_21 , T_6 * V_22 )
{
T_7 V_23 ;
T_7 V_24 ;
T_7 V_25 ;
T_8 V_26 ;
T_9 V_27 ;
T_9 V_28 ;
fprintf ( V_22 , L_1 , V_29 ,
F_10 ( & ( V_21 -> V_8 ) ) ,
V_21 -> V_9 ) ;
V_23 = F_11 ( V_21 -> V_23 ) ;
V_24 = F_11 ( V_21 -> V_24 ) ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_26 = V_21 -> V_6 . V_30 ;
if ( V_26 > sizeof V_25 )
V_26 = sizeof V_25 ;
memcpy ( & V_25 , V_21 -> V_6 . V_16 , V_26 ) ;
V_27 = F_12 ( V_21 -> V_7 ) ;
V_28 = 0 ;
if ( fwrite ( & V_23 , 4 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( & V_24 , 4 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( & V_25 , 4 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( & V_27 , 2 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( & V_28 , 2 , 1 , V_22 ) == 0 )
return;
}
void F_13 ( T_10 * V_31 , T_6 * V_22 )
{
T_9 V_32 ;
T_9 V_33 ;
T_7 V_34 ;
V_32 = F_12 ( V_31 -> V_35 . V_36 + 8 ) ;
V_33 = F_12 ( V_31 -> V_35 . V_36 ) ;
V_34 = F_11 ( V_31 -> V_35 . V_37 ) ;
if ( fwrite ( & V_32 , 2 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( & V_33 , 2 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( & V_34 , 4 , 1 , V_22 ) == 0 )
return;
if ( fwrite ( V_31 -> V_38 , V_31 -> V_35 . V_36 , 1 , V_22 ) == 0 )
return;
}
int F_14 ( void * V_20 , T_11 * V_39 , T_12 * T_13 V_40 , const void * V_41 )
{
T_3 * V_11 = ( T_3 * ) V_20 ;
const struct V_42 * V_43 = ( const struct V_42 * ) V_41 ;
T_5 V_44 ;
T_5 * V_21 = NULL ;
T_4 * V_12 ;
T_10 V_31 ;
struct V_45 * V_46 = NULL ;
F_15 ( & ( V_44 . V_6 ) , & ( V_39 -> V_47 ) ) ;
V_44 . V_7 = V_39 -> V_48 ;
F_15 ( & ( V_44 . V_8 ) , & ( V_39 -> V_49 ) ) ;
V_44 . V_9 = V_39 -> V_50 ;
V_44 . V_10 = V_43 -> V_51 ;
V_44 . V_52 = V_43 -> V_53 ;
V_44 . V_54 = V_43 -> V_54 ;
if ( V_11 -> V_13 == V_14 ) {
V_12 = F_4 ( V_11 -> V_15 ) ;
while ( V_12 )
{
if ( F_1 ( & V_44 , ( T_5 * ) ( V_12 -> V_16 ) ) == 0 )
{
V_21 = ( T_5 * ) ( V_12 -> V_16 ) ;
break;
}
V_12 = F_6 ( V_12 ) ;
}
if ( ! V_21 ) {
V_44 . V_18 = 0 ;
V_44 . V_55 = V_39 -> V_56 -> V_57 ;
V_44 . V_23 = ( T_7 ) V_39 -> V_56 -> V_58 . V_59 ;
V_44 . V_24 = V_39 -> V_56 -> V_58 . V_60 / 1000 ;
V_44 . V_61 = ( T_7 ) V_39 -> V_56 -> V_62 . V_59 ;
V_44 . V_63 = V_39 -> V_56 -> V_62 . V_60 / 1000 ;
V_44 . V_64 = 0 ;
V_44 . V_65 = 0 ;
V_44 . V_66 = 0 ;
V_44 . V_67 = FALSE ;
V_44 . V_68 . V_69 = TRUE ;
V_44 . V_68 . V_70 = 0 ;
V_44 . V_68 . V_71 = 0 ;
V_44 . V_68 . V_72 = 0 ;
V_44 . V_68 . V_73 = 0 ;
V_44 . V_68 . V_74 = 0 ;
V_44 . V_68 . V_75 = 0 ;
V_44 . V_68 . V_76 = 0 ;
V_44 . V_68 . V_77 = 0 ;
V_44 . V_68 . V_78 = 0 ;
V_44 . V_68 . V_79 = 0 ;
V_44 . V_68 . V_80 = 0 ;
V_44 . V_68 . V_81 = 0 ;
V_44 . V_68 . V_82 = 0 ;
V_44 . V_68 . V_83 = 0 ;
V_44 . V_68 . V_84 = 0 ;
V_44 . V_68 . V_85 = 0 ;
V_44 . V_68 . V_86 = 0 ;
V_44 . V_68 . V_87 = FALSE ;
V_44 . V_68 . V_88 = 0 ;
V_44 . V_68 . time = 0 ;
V_44 . V_68 . V_89 = V_90 ;
V_46 = (struct V_45 * ) F_16 ( V_39 -> V_56 , F_17 ( L_2 ) , 0 ) ;
if ( V_46 )
V_44 . V_91 = V_46 -> V_92 ;
else
V_44 . V_91 = 0xFFFFFFFF ;
V_21 = F_18 ( T_5 , 1 ) ;
* V_21 = V_44 ;
V_11 -> V_15 = F_19 ( V_11 -> V_15 , V_21 ) ;
}
F_20 ( & ( V_21 -> V_68 ) , V_39 , V_43 ) ;
if ( V_21 -> V_68 . V_93 & V_94
|| V_21 -> V_68 . V_93 & V_95 )
V_21 -> V_67 = TRUE ;
++ ( V_21 -> V_18 ) ;
V_21 -> V_96 = ( T_7 ) V_39 -> V_56 -> V_62 . V_59 ;
V_21 -> V_97 = V_39 -> V_56 -> V_62 . V_60 / 1000 ;
++ ( V_11 -> V_18 ) ;
return 1 ;
}
else if ( V_11 -> V_13 == V_98 ) {
if ( F_1 ( & V_44 , V_11 -> V_99 ) == 0 ) {
V_31 . V_35 . V_37 =
( V_39 -> V_56 -> V_58 . V_60 / 1000 + 1000000 - V_11 -> V_99 -> V_24 ) / 1000
+ ( T_7 ) ( V_39 -> V_56 -> V_58 . V_59 - V_11 -> V_99 -> V_23 - 1 ) * 1000 ;
V_31 . V_35 . V_36 = V_43 -> V_100 ;
V_31 . V_38 = V_43 -> V_101 ;
F_13 ( & V_31 , V_11 -> V_102 ) ;
}
}
#ifdef F_21
else if ( V_11 -> V_13 == V_103 ) {
if ( F_1 ( & V_44 , V_11 -> V_99 ) == 0
|| F_1 ( & V_44 , V_11 -> V_104 ) == 0 )
{
F_22 ( & V_105 , V_39 -> V_56 ) ;
}
}
#endif
return 0 ;
}
static T_7
F_23 ( T_7 V_106 )
{
T_8 V_107 ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ ) {
if ( V_109 [ V_107 ] . V_106 == V_106 )
return V_109 [ V_107 ] . V_110 ;
}
return 0 ;
}
static T_7
F_24 ( T_14 * V_111 )
{
int V_107 ;
for ( V_107 = V_112 - 1 ; V_107 > - 1 ; V_107 -- ) {
if ( F_25 ( V_113 [ V_107 ] . V_114 , V_111 , ( strlen ( V_113 [ V_107 ] . V_114 ) ) ) == 0 )
return V_113 [ V_107 ] . V_110 ;
}
return 0 ;
}
int F_20 ( T_15 * V_115 ,
T_11 * V_39 ,
const struct V_42 * V_43 )
{
double V_116 ;
double V_117 ;
double V_118 = 0 ;
double V_119 ;
double V_120 ;
double V_121 ;
double V_122 ;
T_7 V_123 ;
V_116 = F_26 ( & V_39 -> V_56 -> V_62 ) ;
if ( V_115 -> V_69 ) {
if( V_39 -> V_124 . type == V_125 ) {
F_15 ( & ( V_115 -> V_126 ) , & ( V_39 -> V_124 ) ) ;
}
V_115 -> V_84 = V_43 -> V_127 ;
V_115 -> V_85 = V_43 -> V_127 ;
V_115 -> V_128 = V_43 -> V_127 ;
V_115 -> V_88 = V_116 ;
V_115 -> V_80 = V_43 -> V_129 ;
V_115 -> V_130 = V_43 -> V_129 ;
V_115 -> time = V_116 ;
V_115 -> V_131 = 0 ;
V_115 -> V_52 = V_43 -> V_53 ;
V_115 -> V_89 = V_43 -> V_53 ;
V_115 -> V_132 [ V_115 -> V_79 ] . V_133 = V_43 -> V_100 + 28 ;
V_115 -> V_132 [ V_115 -> V_79 ] . time = V_116 ;
V_115 -> V_79 ++ ;
V_115 -> V_77 += V_43 -> V_100 + 28 ;
V_115 -> V_76 = ( double ) ( V_115 -> V_77 * 8 ) / 1000 ;
V_115 -> V_73 = 0 ;
V_115 -> V_75 = 0 ;
V_115 -> V_74 = 0 ;
V_115 -> V_82 ++ ;
V_115 -> V_93 |= V_134 ;
if ( V_43 -> V_135 ) {
V_115 -> V_93 |= V_136 ;
}
V_115 -> V_69 = FALSE ;
return 0 ;
}
V_115 -> V_93 = 0 ;
if( V_39 -> V_124 . type == V_125 ) {
if( ! F_2 ( & ( V_115 -> V_126 ) , & ( V_39 -> V_124 ) ) ) {
V_115 -> V_93 |= V_137 ;
V_115 -> V_73 = V_116 - ( V_115 -> time ) ;
return 0 ;
}
}
if ( ( V_43 -> V_127 < V_115 -> V_84 ) && ( V_115 -> V_87 == FALSE ) ) {
V_115 -> V_86 ++ ;
V_115 -> V_87 = TRUE ;
}
else if ( ( V_43 -> V_127 == 0 ) && ( V_115 -> V_85 == 65535 ) &&
( V_115 -> V_87 == FALSE ) ) {
V_115 -> V_86 ++ ;
V_115 -> V_87 = TRUE ;
}
else if ( ( V_43 -> V_127 > V_115 -> V_84 ) && ( V_115 -> V_87 != FALSE ) ) {
V_115 -> V_87 = FALSE ;
}
if ( ( V_115 -> V_128 + 1 == V_43 -> V_127 ) || ( V_115 -> V_93 & V_134 ) )
V_115 -> V_128 = V_43 -> V_127 ;
else if ( ( V_115 -> V_128 == 65535 ) && ( V_43 -> V_127 == 0 ) )
V_115 -> V_128 = V_43 -> V_127 ;
else if ( V_115 -> V_128 + 1 < V_43 -> V_127 || V_115 -> V_128 - V_43 -> V_127 > 0xFF00 ) {
V_115 -> V_128 = V_43 -> V_127 ;
V_115 -> V_83 ++ ;
V_115 -> V_93 |= V_95 ;
}
else if ( V_115 -> V_128 + 1 > V_43 -> V_127 ) {
V_115 -> V_83 ++ ;
V_115 -> V_93 |= V_95 ;
}
if ( V_43 -> V_53 == V_138
|| V_43 -> V_53 == V_139 )
V_115 -> V_93 |= V_140 ;
if ( V_115 -> V_52 == V_138
|| V_115 -> V_52 == V_139 )
V_115 -> V_93 |= V_141 ;
if ( V_43 -> V_53 != V_115 -> V_52 )
V_115 -> V_93 |= V_142 ;
V_115 -> V_52 = V_43 -> V_53 ;
if ( V_115 -> V_52 < 96 ) {
V_123 = F_23 ( V_115 -> V_52 ) ;
} else{
if ( V_43 -> V_54 != NULL ) {
if ( F_25 ( L_3 , V_43 -> V_54 , ( strlen ( L_3 ) ) ) == 0 ) {
V_123 = 0 ;
V_115 -> V_93 |= V_143 ;
} else{
if( V_43 -> V_144 != 0 ) {
V_123 = V_43 -> V_144 ;
} else{
V_123 = F_24 ( V_43 -> V_54 ) ;
}
}
} else{
V_123 = 0 ;
}
}
V_120 = V_116 - V_115 -> V_88 ;
if ( V_115 -> V_130 > V_43 -> V_129 ) {
V_119 = ( double ) ( V_43 -> V_129 + 0xffffffff - V_115 -> V_130 + 1 ) ;
} else{
V_119 = ( double ) ( V_43 -> V_129 - V_115 -> V_130 ) ;
}
if ( V_123 != 0 ) {
V_115 -> V_123 = V_123 ;
V_119 = V_119 / ( V_123 / 1000 ) ;
if ( ! V_115 -> V_69 ) {
V_121 = V_115 -> time + ( V_119 - V_115 -> V_131 ) ;
V_118 = fabs ( V_116 - V_121 ) ;
V_117 = ( 15 * V_115 -> V_75 + V_118 ) / 16 ;
V_115 -> V_73 = V_116 - ( V_115 -> time ) ;
V_115 -> V_75 = V_117 ;
V_115 -> V_74 = V_118 ;
}
V_115 -> V_131 = V_119 ;
V_115 -> V_145 = V_119 - V_120 ;
V_122 = fabs ( V_115 -> V_145 ) ;
if( V_122 > fabs ( V_115 -> V_146 ) ) {
V_115 -> V_146 = V_115 -> V_145 ;
}
#if 0
if (numPackets > 0 && (!hardPayloadType || !alternatePayloadType)) {
double dt;
dt = nominaltime - statinfo->lastnominaltime;
sumdt += 1.0 * dt;
numdt += (dt != 0 ? 1 : 0);
mindt = (dt < mindt ? dt : mindt);
maxdt = (dt > maxdt ? dt : maxdt);
}
#endif
V_115 -> V_147 += 1.0 * V_116 ;
V_115 -> V_148 += 1.0 * V_119 ;
V_115 -> V_149 += 1.0 * V_116 * V_116 ;
V_115 -> V_150 += 1.0 * V_116 * V_119 ;
}
V_115 -> V_132 [ V_115 -> V_79 ] . V_133 = V_43 -> V_100 + V_39 -> V_151 + 8 ;
V_115 -> V_132 [ V_115 -> V_79 ] . time = V_116 ;
while ( ( V_115 -> V_132 [ V_115 -> V_78 ] . time + 1000 ) < V_116 ) {
V_115 -> V_77 -= V_115 -> V_132 [ V_115 -> V_78 ] . V_133 ;
V_115 -> V_78 ++ ;
if ( V_115 -> V_78 == V_152 ) V_115 -> V_78 = 0 ;
} ;
V_115 -> V_77 += V_43 -> V_100 + V_39 -> V_151 + 8 ;
V_115 -> V_76 = ( double ) ( V_115 -> V_77 * 8 ) / 1000 ;
V_115 -> V_79 ++ ;
if ( V_115 -> V_79 == V_152 ) V_115 -> V_79 = 0 ;
if ( V_43 -> V_135 ) {
V_115 -> V_153 = V_43 -> V_129 - V_115 -> V_80 ;
if ( V_43 -> V_129 > V_115 -> V_80 ) {
V_115 -> V_93 |= V_136 ;
}
else{
V_115 -> V_93 |= V_94 ;
}
}
if ( ! ( V_115 -> V_93 & V_134 )
&& ! ( V_115 -> V_93 & V_136 )
&& ! ( V_115 -> V_93 & V_140 )
&& ! ( V_115 -> V_93 & V_94 )
&& ! ( V_115 -> V_93 & V_141 ) ) {
if ( V_115 -> V_73 > V_115 -> V_70 ) {
V_115 -> V_70 = V_115 -> V_73 ;
V_115 -> V_81 = V_39 -> V_56 -> V_57 ;
}
if ( V_123 != 0 ) {
if ( V_115 -> V_75 > V_115 -> V_71 ) {
V_115 -> V_71 = V_115 -> V_75 ;
}
V_115 -> V_72 = ( V_115 -> V_72 * V_115 -> V_82 + V_118 ) / ( V_115 -> V_82 + 1 ) ;
}
}
if ( ! ( V_115 -> V_93 & V_134 )
&& ! ( V_115 -> V_93 & V_140 ) ) {
if ( ( V_115 -> V_52 != V_115 -> V_89 )
&& ( V_115 -> V_89 != V_90 ) ) {
V_115 -> V_93 |= V_154 ;
}
}
if ( ! ( V_115 -> V_93 & V_140 ) ) {
V_115 -> V_89 = V_115 -> V_52 ;
}
V_115 -> time = V_116 ;
V_115 -> V_80 = V_43 -> V_129 ;
V_115 -> V_85 = V_43 -> V_127 ;
V_115 -> V_82 ++ ;
return 0 ;
}
