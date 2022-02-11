T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return ( F_2 ( V_2 ) ? \
( T_1 ) F_3 ( ( V_2 ) -> V_4 , ( V_3 ) ) : \
F_4 ( ( V_2 ) -> V_4 , ( V_3 ) ) ) ;
}
int
F_5 (
struct V_1 * V_2 ,
T_2 V_5 ,
T_3 V_6 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_1 V_9 = F_1 ( V_2 , V_5 ) ;
T_4 V_10 = F_6 ( V_8 , V_9 ) ;
return F_7 ( F_8 ( F_9 ( V_2 ) ) ,
V_10 << ( V_8 -> V_11 -> V_12 - 9 ) ,
V_6 << ( V_8 -> V_11 -> V_12 - 9 ) ,
V_13 , true ) ;
}
int
F_10 (
struct V_14 * V_15 )
{
T_5 V_16 = 0 ;
int error ;
T_6 * V_8 ;
T_7 V_17 = 0 ;
T_7 V_18 = 0 ;
T_7 V_19 ;
T_8 V_20 ;
V_8 = V_15 -> V_2 -> V_4 ;
V_19 = F_11 ( V_15 -> V_2 ) ;
V_17 = V_19 / V_8 -> V_21 . V_22 ;
error = F_12 ( V_8 , & V_15 -> V_23 , & V_15 -> V_24 ,
V_19 , 1 , V_15 -> V_25 , 0 ,
V_15 -> V_26 , & V_15 -> V_27 , & V_15 -> V_28 ) ;
if ( error )
return error ;
ASSERT ( V_15 -> V_28 ) ;
ASSERT ( V_15 -> V_28 % V_8 -> V_21 . V_22 == 0 ) ;
if ( F_13 ( V_15 -> V_27 , V_19 ) || V_15 -> V_28 % V_19 )
V_17 = 1 ;
V_18 = V_15 -> V_28 / V_8 -> V_21 . V_22 ;
if ( V_18 * V_8 -> V_21 . V_22 >= V_29 )
V_18 = V_29 / V_8 -> V_21 . V_22 ;
F_14 ( V_8 -> V_30 , V_31 | V_32 ) ;
F_15 ( V_15 -> V_33 , V_8 -> V_30 , V_31 ) ;
F_14 ( V_8 -> V_34 , V_31 | V_35 ) ;
F_15 ( V_15 -> V_33 , V_8 -> V_34 , V_31 ) ;
if ( V_15 -> V_25 && V_15 -> V_27 == 0 ) {
T_8 V_36 ( V_37 ) ;
error = F_16 ( V_8 , V_15 -> V_33 , V_18 , & V_37 ) ;
if ( error )
return error ;
V_15 -> V_38 = V_37 * V_8 -> V_21 . V_22 ;
} else {
V_15 -> V_38 = 0 ;
}
F_17 ( V_15 ) ;
V_16 = V_15 -> V_38 == 0 ? V_39 : V_40 ;
F_18 ( V_15 -> V_38 , V_8 -> V_21 . V_22 ) ;
V_20 = V_15 -> V_38 ;
V_15 -> V_28 = V_18 ;
if ( ( error = F_19 ( V_15 -> V_33 , V_15 -> V_38 , 1 , V_15 -> V_28 ,
& V_18 , V_16 , V_15 -> V_41 , V_17 , & V_20 ) ) )
return error ;
if ( V_20 == V_42 && V_17 > 1 &&
( error = F_19 ( V_15 -> V_33 , V_15 -> V_38 , 1 ,
V_15 -> V_28 , & V_18 , V_16 ,
V_15 -> V_41 , 1 , & V_20 ) ) )
return error ;
V_15 -> V_38 = V_20 ;
if ( V_15 -> V_38 != V_42 ) {
V_15 -> V_38 *= V_8 -> V_21 . V_22 ;
V_18 *= V_8 -> V_21 . V_22 ;
V_15 -> V_28 = V_18 ;
V_15 -> V_2 -> V_43 . V_44 += V_18 ;
F_20 ( V_15 -> V_33 , V_15 -> V_2 , V_45 ) ;
if ( V_15 -> V_41 )
V_15 -> V_2 -> V_46 -= V_18 ;
F_21 ( V_15 -> V_33 , V_15 -> V_2 ,
V_15 -> V_41 ? V_47 :
V_48 , ( long ) V_18 ) ;
if ( V_15 -> V_49 & V_50 ) {
error = F_5 ( V_15 -> V_2 , V_15 -> V_38 , V_15 -> V_28 ) ;
if ( error )
return error ;
}
} else {
V_15 -> V_28 = 0 ;
}
return 0 ;
}
int
F_22 (
struct V_1 * V_2 ,
T_9 V_51 ,
int V_52 ,
int * V_25 )
{
struct V_53 V_54 ;
int error ;
error = F_23 ( NULL , V_2 , V_52 , & V_54 , V_25 ) ;
if ( error || * V_25 )
return error ;
* V_25 = V_51 >= V_54 . V_55 + V_54 . V_56 ;
return 0 ;
}
STATIC void
F_24 (
T_10 * V_57 ,
T_11 V_58 ,
int V_59 ,
int * V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
T_12 * V_62 = F_25 ( V_57 , V_58 + V_61 ) ;
* V_60 += F_26 ( V_62 ) ;
}
}
STATIC void
F_27 (
struct V_7 * V_8 ,
struct V_63 * V_10 ,
int V_59 ,
int * V_60 )
{
int V_61 ;
T_13 * V_62 ;
for ( V_61 = 1 ; V_61 <= V_59 ; V_61 ++ ) {
V_62 = F_28 ( V_8 , V_10 , V_61 ) ;
* V_60 += F_29 ( V_62 ) ;
}
}
STATIC int
F_30 (
T_6 * V_8 ,
T_14 * V_33 ,
T_10 * V_57 ,
T_2 V_64 ,
int V_65 ,
int * V_60 )
{
int error ;
T_15 * V_66 , * V_67 ;
int V_68 = V_65 ;
T_16 * V_69 ;
T_2 V_70 = V_64 ;
T_2 V_71 ;
struct V_63 * V_10 , * V_72 ;
int V_59 ;
error = F_31 ( V_8 , V_33 , V_70 , 0 , & V_66 , V_73 ,
& V_74 ) ;
if ( error )
return error ;
* V_60 += 1 ;
V_10 = F_32 ( V_66 ) ;
if ( -- V_68 ) {
V_71 = F_33 ( V_10 -> V_75 . V_76 . V_77 ) ;
while ( V_71 != V_42 ) {
error = F_31 ( V_8 , V_33 , V_71 , 0 , & V_67 ,
V_73 ,
& V_74 ) ;
if ( error )
return error ;
* V_60 += 1 ;
V_72 = F_32 ( V_67 ) ;
V_71 = F_33 ( V_72 -> V_75 . V_76 . V_77 ) ;
F_34 ( V_33 , V_67 ) ;
}
V_69 = F_35 ( V_8 , V_10 , 1 , V_8 -> V_78 [ 1 ] ) ;
V_70 = F_33 ( * V_69 ) ;
if ( F_36 ( ( error =
F_30 ( V_8 , V_33 , V_57 , V_70 , V_68 , V_60 ) ) < 0 ) ) {
F_34 ( V_33 , V_66 ) ;
F_37 ( L_1 ,
V_79 , V_8 ) ;
return - V_80 ;
}
F_34 ( V_33 , V_66 ) ;
} else {
for (; ; ) {
V_71 = F_33 ( V_10 -> V_75 . V_76 . V_77 ) ;
V_59 = F_38 ( V_10 -> V_81 ) ;
F_27 ( V_8 , V_10 , V_59 , V_60 ) ;
F_34 ( V_33 , V_66 ) ;
if ( V_71 == V_42 )
break;
V_70 = V_71 ;
error = F_31 ( V_8 , V_33 , V_70 , 0 , & V_66 ,
V_73 ,
& V_74 ) ;
if ( error )
return error ;
* V_60 += 1 ;
V_10 = F_32 ( V_66 ) ;
}
}
return 0 ;
}
static int
F_39 (
T_14 * V_33 ,
T_17 * V_2 ,
int V_52 ,
int * V_60 )
{
struct V_63 * V_10 ;
T_2 V_70 ;
T_10 * V_57 ;
int V_68 ;
T_6 * V_8 ;
T_16 * V_69 ;
V_70 = V_42 ;
V_8 = V_2 -> V_4 ;
V_57 = F_40 ( V_2 , V_52 ) ;
if ( F_41 ( V_2 , V_52 ) == V_82 ) {
F_24 ( V_57 , 0 ,
V_57 -> V_83 / ( V_84 ) sizeof( T_13 ) ,
V_60 ) ;
return 0 ;
}
V_10 = V_57 -> V_85 ;
V_68 = F_38 ( V_10 -> V_86 ) ;
ASSERT ( V_68 > 0 ) ;
V_69 = F_42 ( V_8 , V_10 , 1 , V_57 -> V_87 ) ;
V_70 = F_33 ( * V_69 ) ;
ASSERT ( V_70 != V_42 ) ;
ASSERT ( F_43 ( V_8 , V_70 ) < V_8 -> V_21 . V_88 ) ;
ASSERT ( F_44 ( V_8 , V_70 ) < V_8 -> V_21 . V_89 ) ;
if ( F_36 ( F_30 ( V_8 , V_33 , V_57 , V_70 , V_68 , V_60 ) < 0 ) ) {
F_37 ( L_2 , V_79 ,
V_8 ) ;
return - V_80 ;
}
return 0 ;
}
STATIC int
F_45 (
T_17 * V_2 ,
int V_52 ,
struct V_90 * V_91 ,
int V_92 ,
T_18 V_93 ,
T_2 V_94 ,
bool V_95 )
{
T_18 V_96 ;
T_6 * V_8 ;
T_10 * V_57 ;
T_11 V_97 ;
T_9 V_98 ;
if ( V_94 == V_99 ) {
V_8 = V_2 -> V_4 ;
V_91 -> V_100 = - 1 ;
V_96 = F_3 ( V_8 , F_46 ( V_8 , F_47 ( V_2 ) ) ) ;
V_96 -= V_91 -> V_101 ;
if ( V_92 && V_91 -> V_101 + V_91 -> V_102 == V_93 ) {
if ( V_96 <= 0 )
return 0 ;
V_91 -> V_102 = V_96 ;
}
} else {
if ( V_94 == V_103 )
V_91 -> V_100 = - 2 ;
else
V_91 -> V_100 = F_1 ( V_2 , V_94 ) ;
V_98 = F_48 ( V_2 -> V_4 , V_91 -> V_101 ) ;
V_57 = F_40 ( V_2 , V_52 ) ;
if ( ! V_95 &&
F_49 ( V_57 , V_98 , & V_97 ) &&
( V_97 == ( V_57 -> V_83 / ( V_84 ) sizeof( T_13 ) ) - 1 ) )
V_91 -> V_104 |= V_105 ;
}
return 1 ;
}
STATIC int
F_50 (
struct V_1 * V_2 ,
int V_52 ,
struct V_53 * V_106 ,
struct V_90 * V_91 ,
struct V_53 * V_107 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_19 V_108 ;
T_20 V_109 ;
T_20 V_110 ;
T_7 V_111 ;
T_7 V_112 ;
int error ;
V_107 -> V_113 = V_42 ;
V_107 -> V_55 = V_114 ;
V_107 -> V_56 = 0 ;
if ( ! F_51 ( V_2 ) || V_52 != V_115 ||
V_106 -> V_113 == V_103 ||
V_106 -> V_113 == V_99 ||
F_52 ( V_106 ) )
return 0 ;
V_108 = F_43 ( V_8 , V_106 -> V_113 ) ;
V_109 = F_44 ( V_8 , V_106 -> V_113 ) ;
error = F_53 ( V_8 , V_108 , V_109 , V_106 -> V_56 ,
& V_110 , & V_111 , true ) ;
if ( error )
return error ;
if ( V_110 == V_116 ) {
return 0 ;
} else if ( V_109 == V_110 ) {
V_91 -> V_102 = F_3 ( V_8 , V_111 ) ;
V_91 -> V_104 |= V_117 ;
if ( V_111 != V_106 -> V_56 ) {
* V_107 = * V_106 ;
V_107 -> V_113 += V_111 ;
V_107 -> V_55 += V_111 ;
V_107 -> V_56 -= V_111 ;
}
V_106 -> V_56 -= V_111 ;
} else {
* V_107 = * V_106 ;
V_112 = V_110 - V_109 ;
V_91 -> V_102 = F_3 ( V_8 , V_112 ) ;
V_107 -> V_113 += V_112 ;
V_107 -> V_55 += V_112 ;
V_107 -> V_56 -= V_112 ;
V_106 -> V_56 -= V_112 ;
}
return 0 ;
}
int
F_54 (
T_17 * V_2 ,
struct V_90 * V_118 ,
T_21 V_119 ,
void * V_120 )
{
T_18 V_121 ;
int error = 0 ;
T_18 V_96 ;
int V_122 ;
int V_123 ;
T_22 * V_106 ;
T_6 * V_8 ;
int V_124 ;
int V_125 ;
int V_126 ;
int V_127 ;
struct V_90 * V_91 ;
int V_52 ;
int V_92 ;
int V_128 ;
int V_129 ;
int V_130 = 0 ;
struct V_53 V_131 ;
V_8 = V_2 -> V_4 ;
V_128 = V_118 -> V_132 ;
#ifndef F_55
if ( V_128 & V_133 )
return - V_134 ;
#endif
if ( ( V_128 & V_135 ) && ( V_128 & V_133 ) )
return - V_134 ;
if ( V_128 & V_135 )
V_52 = V_136 ;
else if ( V_128 & V_133 )
V_52 = V_137 ;
else
V_52 = V_115 ;
switch ( V_52 ) {
case V_136 :
if ( F_56 ( V_2 ) ) {
if ( V_2 -> V_43 . V_138 != V_82 &&
V_2 -> V_43 . V_138 != V_139 &&
V_2 -> V_43 . V_138 != V_140 )
return - V_134 ;
} else if ( F_36 (
V_2 -> V_43 . V_138 != 0 &&
V_2 -> V_43 . V_138 != V_82 ) ) {
F_37 ( L_3 , V_79 ,
V_2 -> V_4 ) ;
return - V_80 ;
}
V_92 = 0 ;
V_96 = 1LL << 32 ;
break;
case V_137 :
if ( V_2 -> V_141 != V_82 )
return - V_134 ;
if ( F_57 ( V_2 ) ) {
V_92 = 1 ;
V_96 = V_8 -> V_11 -> V_142 ;
} else {
V_92 = 0 ;
V_96 = F_47 ( V_2 ) ;
}
break;
default:
if ( V_2 -> V_43 . V_143 != V_82 &&
V_2 -> V_43 . V_143 != V_139 &&
V_2 -> V_43 . V_143 != V_140 )
return - V_134 ;
if ( F_11 ( V_2 ) ||
V_2 -> V_43 . V_144 & ( V_145 | V_146 ) ) {
V_92 = 1 ;
V_96 = V_8 -> V_11 -> V_142 ;
} else {
V_92 = 0 ;
V_96 = F_47 ( V_2 ) ;
}
break;
}
if ( V_118 -> V_102 == - 1 ) {
V_96 = F_3 ( V_8 , F_46 ( V_8 , V_96 ) ) ;
V_118 -> V_102 =
F_58 ( T_18 , V_96 - V_118 -> V_101 , 0 ) ;
} else if ( V_118 -> V_102 == 0 ) {
V_118 -> V_147 = 0 ;
return 0 ;
} else if ( V_118 -> V_102 < 0 ) {
return - V_134 ;
}
V_124 = V_118 -> V_148 - 1 ;
if ( V_124 <= 0 )
return - V_134 ;
V_121 = V_118 -> V_101 + V_118 -> V_102 ;
if ( V_118 -> V_148 > V_149 / sizeof( struct V_90 ) )
return - V_150 ;
V_91 = F_59 ( V_118 -> V_148 * sizeof( struct V_90 ) , 0 ) ;
if ( ! V_91 )
return - V_150 ;
F_14 ( V_2 , V_151 ) ;
switch ( V_52 ) {
case V_115 :
if ( ! ( V_128 & V_152 ) &&
( V_2 -> V_46 || F_47 ( V_2 ) > V_2 -> V_43 . V_153 ) ) {
error = F_60 ( F_9 ( V_2 ) -> V_154 ) ;
if ( error )
goto V_155;
}
V_123 = F_61 ( V_2 ) ;
break;
case V_137 :
V_123 = V_156 ;
F_14 ( V_2 , V_123 ) ;
break;
case V_136 :
V_123 = F_62 ( V_2 ) ;
break;
}
if ( V_124 > F_63 ( V_2 , V_52 ) * 2 + 1 )
V_124 = F_63 ( V_2 , V_52 ) * 2 + 1 ;
V_129 = F_64 ( V_52 ) ;
if ( ! ( V_128 & V_157 ) )
V_129 |= V_158 ;
error = - V_150 ;
V_126 = 16 ;
V_106 = F_65 ( V_126 * sizeof( * V_106 ) , V_159 | V_160 ) ;
if ( ! V_106 )
goto V_161;
V_118 -> V_147 = 0 ;
if ( F_63 ( V_2 , V_52 ) == 0 &&
( V_52 == V_136 || ! ( V_128 & V_152 ) ) ) {
error = 0 ;
goto V_162;
}
V_125 = V_124 ;
do {
V_127 = ( V_125 > V_126 ) ? V_126 : V_125 ;
error = F_66 ( V_2 , F_6 ( V_8 , V_118 -> V_101 ) ,
F_48 ( V_8 , V_118 -> V_102 ) ,
V_106 , & V_127 , V_129 ) ;
if ( error )
goto V_162;
ASSERT ( V_127 <= V_126 ) ;
for ( V_122 = 0 ; V_122 < V_127 && V_125 && V_118 -> V_102 &&
V_130 < V_118 -> V_148 ; V_122 ++ ) {
V_91 [ V_130 ] . V_104 = 0 ;
if ( V_106 [ V_122 ] . V_163 == V_164 )
V_91 [ V_130 ] . V_104 |= V_165 ;
else if ( V_106 [ V_122 ] . V_113 == V_103 )
V_91 [ V_130 ] . V_104 |= V_166 ;
V_91 [ V_130 ] . V_101 =
F_3 ( V_8 , V_106 [ V_122 ] . V_55 ) ;
V_91 [ V_130 ] . V_102 =
F_3 ( V_8 , V_106 [ V_122 ] . V_56 ) ;
V_91 [ V_130 ] . V_167 = 0 ;
V_91 [ V_130 ] . V_168 = 0 ;
if ( V_106 [ V_122 ] . V_113 == V_103 &&
V_106 [ V_122 ] . V_55 <= F_46 ( V_8 , F_47 ( V_2 ) ) )
ASSERT ( ( V_128 & V_152 ) != 0 ) ;
if ( V_106 [ V_122 ] . V_113 == V_99 &&
V_52 == V_136 ) {
V_91 [ V_130 ] . V_104 |= V_105 ;
goto V_162;
}
error = F_50 ( V_2 , V_52 ,
& V_106 [ V_122 ] , & V_91 [ V_130 ] , & V_131 ) ;
if ( error )
goto V_162;
if ( ! F_45 ( V_2 , V_52 ,
& V_91 [ V_130 ] , V_92 , V_121 ,
V_106 [ V_122 ] . V_113 ,
V_131 . V_113 != V_42 ) )
goto V_162;
V_118 -> V_101 =
V_91 [ V_130 ] . V_101 +
V_91 [ V_130 ] . V_102 ;
V_118 -> V_102 =
F_58 ( T_18 , 0 , V_121 - V_118 -> V_101 ) ;
if ( ( V_128 & V_169 ) &&
V_106 [ V_122 ] . V_113 == V_99 ) {
memset ( & V_91 [ V_130 ] , 0 , sizeof( V_91 [ V_130 ] ) ) ;
continue;
}
if ( V_131 . V_113 != V_42 ) {
V_106 [ V_122 ] = V_131 ;
V_122 -- ;
} else
V_125 -- ;
V_118 -> V_147 ++ ;
V_130 ++ ;
}
} while ( V_127 && V_125 && V_118 -> V_102 &&
V_130 < V_118 -> V_148 );
V_162:
F_67 ( V_106 ) ;
V_161:
F_68 ( V_2 , V_123 ) ;
V_155:
F_68 ( V_2 , V_151 ) ;
for ( V_122 = 0 ; V_122 < V_130 ; V_122 ++ ) {
int V_170 = 0 ;
error = V_119 ( & V_120 , & V_91 [ V_122 ] , & V_170 ) ;
if ( error || V_170 )
break;
}
F_67 ( V_91 ) ;
return error ;
}
int
F_69 (
struct V_1 * V_2 ,
T_9 V_5 ,
T_9 V_28 )
{
T_9 V_171 = V_28 ;
int error = 0 ;
ASSERT ( F_70 ( V_2 , V_31 ) ) ;
do {
int V_172 ;
T_22 V_173 ;
int V_174 = 1 ;
T_2 V_175 ;
struct V_176 V_177 ;
error = F_66 ( V_2 , V_5 , 1 , & V_173 , & V_174 ,
V_178 ) ;
if ( error ) {
if ( ! F_71 ( V_2 -> V_4 ) ) {
F_72 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_179 , V_5 ) ;
}
break;
}
if ( ! V_174 ) {
goto V_180;
}
if ( V_173 . V_113 != V_103 ) {
goto V_180;
}
F_73 ( V_173 . V_56 == 0 ) ;
F_74 ( & V_177 , & V_175 ) ;
error = F_75 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_175 ,
& V_177 , & V_172 ) ;
if ( error )
break;
ASSERT ( ! F_76 ( & V_177 ) ) ;
V_180:
V_5 ++ ;
V_171 -- ;
} while( V_171 > 0 );
return error ;
}
bool
F_77 ( struct V_1 * V_2 , bool V_181 )
{
if ( ! F_78 ( F_9 ( V_2 ) -> V_182 ) )
return false ;
if ( F_9 ( V_2 ) -> V_183 == 0 &&
F_9 ( V_2 ) -> V_154 -> V_184 == 0 &&
V_2 -> V_46 == 0 )
return false ;
if ( ! ( V_2 -> V_185 . V_186 & V_187 ) )
return false ;
if ( V_2 -> V_43 . V_144 & ( V_145 | V_146 ) )
if ( ! V_181 || V_2 -> V_46 == 0 )
return false ;
return true ;
}
int
F_79 (
T_6 * V_8 ,
T_17 * V_2 ,
bool V_188 )
{
T_14 * V_33 ;
int error ;
T_9 V_189 ;
T_9 V_190 ;
T_23 V_191 ;
int V_174 ;
T_22 V_173 ;
V_189 = F_46 ( V_8 , ( V_192 ) F_47 ( V_2 ) ) ;
V_190 = F_46 ( V_8 , V_8 -> V_11 -> V_142 ) ;
if ( V_190 <= V_189 )
return 0 ;
V_191 = V_190 - V_189 ;
V_174 = 1 ;
F_14 ( V_2 , V_156 ) ;
error = F_66 ( V_2 , V_189 , V_191 , & V_173 , & V_174 , 0 ) ;
F_68 ( V_2 , V_156 ) ;
if ( ! error && ( V_174 != 0 ) &&
( V_173 . V_113 != V_99 ||
V_2 -> V_46 ) ) {
error = F_80 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_188 ) {
if ( ! F_81 ( V_2 , V_193 ) )
return - V_194 ;
}
error = F_82 ( V_8 , & F_83 ( V_8 ) -> V_195 , 0 , 0 , 0 ,
& V_33 ) ;
if ( error ) {
ASSERT ( F_71 ( V_8 ) ) ;
if ( V_188 )
F_68 ( V_2 , V_193 ) ;
return error ;
}
F_14 ( V_2 , V_31 ) ;
F_15 ( V_33 , V_2 , 0 ) ;
error = F_84 ( & V_33 , V_2 , V_115 ,
F_47 ( V_2 ) ) ;
if ( error ) {
F_85 ( V_33 ) ;
} else {
error = F_86 ( V_33 ) ;
if ( ! error )
F_87 ( V_2 ) ;
}
F_68 ( V_2 , V_31 ) ;
if ( V_188 )
F_68 ( V_2 , V_193 ) ;
}
return error ;
}
int
F_88 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_196 ,
int V_197 )
{
T_6 * V_8 = V_2 -> V_4 ;
T_3 V_60 ;
T_23 V_198 ;
T_23 V_199 ;
T_7 V_200 , V_201 ;
T_9 V_202 ;
T_2 V_203 ;
int V_174 ;
int V_204 ;
int V_205 ;
T_14 * V_33 ;
T_22 V_206 [ 1 ] , * V_207 ;
struct V_176 V_177 ;
V_84 V_208 , V_209 , V_210 ;
int error ;
F_89 ( V_2 ) ;
if ( F_71 ( V_8 ) )
return - V_211 ;
error = F_80 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_196 <= 0 )
return - V_134 ;
V_205 = F_2 ( V_2 ) ;
V_200 = F_11 ( V_2 ) ;
V_60 = V_196 ;
V_207 = & V_206 [ 0 ] ;
V_174 = 1 ;
V_202 = F_90 ( V_8 , V_27 ) ;
V_199 = F_46 ( V_8 , V_60 ) ;
while ( V_199 && ! error ) {
T_9 V_212 , V_213 ;
if ( F_36 ( V_200 ) ) {
V_212 = V_202 ;
F_18 ( V_212 , V_200 ) ;
V_212 *= V_200 ;
V_213 = V_202 + V_199 ;
if ( ( V_201 = F_13 ( V_202 , V_200 ) ) )
V_213 += V_201 ;
if ( ( V_201 = F_13 ( V_213 , V_200 ) ) )
V_213 += V_200 - V_201 ;
} else {
V_212 = 0 ;
V_213 = V_199 ;
}
V_209 = F_91 ( T_9 , ( V_213 - V_212 ) , ( V_29 * V_174 ) ) ;
if ( F_36 ( V_205 ) ) {
V_210 = V_208 = V_209 ;
V_210 /= V_8 -> V_21 . V_22 ;
V_209 = F_92 ( V_8 , 0 ) ;
V_204 = V_214 ;
} else {
V_210 = 0 ;
V_209 = V_208 = F_92 ( V_8 , V_209 ) ;
V_204 = V_215 ;
}
error = F_82 ( V_8 , & F_83 ( V_8 ) -> V_216 , V_209 ,
V_210 , 0 , & V_33 ) ;
if ( error ) {
ASSERT ( error == - V_217 || F_71 ( V_8 ) ) ;
break;
}
F_14 ( V_2 , V_31 ) ;
error = F_93 ( V_33 , V_2 , V_208 ,
0 , V_204 ) ;
if ( error )
goto V_218;
F_15 ( V_33 , V_2 , 0 ) ;
F_74 ( & V_177 , & V_203 ) ;
error = F_94 ( V_33 , V_2 , V_202 ,
V_199 , V_197 , & V_203 ,
V_209 , V_207 , & V_174 , & V_177 ) ;
if ( error )
goto V_219;
error = F_95 ( & V_33 , & V_177 , NULL ) ;
if ( error )
goto V_219;
error = F_86 ( V_33 ) ;
F_68 ( V_2 , V_31 ) ;
if ( error )
break;
V_198 = V_207 -> V_56 ;
if ( V_174 == 0 ) {
error = - V_217 ;
break;
}
V_202 += V_198 ;
V_199 -= V_198 ;
}
return error ;
V_219:
F_96 ( & V_177 ) ;
F_97 ( V_33 , V_2 , ( long ) V_208 , 0 , V_204 ) ;
V_218:
F_85 ( V_33 ) ;
F_68 ( V_2 , V_31 ) ;
return error ;
}
static int
F_98 (
struct V_1 * V_2 ,
T_9 V_202 ,
T_23 V_220 ,
int * V_172 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_221 * V_33 ;
struct V_176 V_177 ;
T_2 V_203 ;
V_84 V_209 = F_92 ( V_8 , 0 ) ;
int error ;
error = F_82 ( V_8 , & F_83 ( V_8 ) -> V_216 , V_209 , 0 , 0 , & V_33 ) ;
if ( error ) {
ASSERT ( error == - V_217 || F_71 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_31 ) ;
error = F_99 ( V_33 , V_8 , V_2 -> V_222 , V_2 -> V_223 ,
V_2 -> V_224 , V_209 , 0 , V_215 ) ;
if ( error )
goto V_225;
F_15 ( V_33 , V_2 , 0 ) ;
F_74 ( & V_177 , & V_203 ) ;
error = F_75 ( V_33 , V_2 , V_202 , V_220 , 0 , 2 , & V_203 ,
& V_177 , V_172 ) ;
if ( error )
goto V_226;
error = F_95 ( & V_33 , & V_177 , V_2 ) ;
if ( error )
goto V_226;
error = F_86 ( V_33 ) ;
V_227:
F_68 ( V_2 , V_31 ) ;
return error ;
V_226:
F_96 ( & V_177 ) ;
V_225:
F_85 ( V_33 ) ;
goto V_227;
}
static int
F_100 (
struct V_1 * V_2 ,
T_9 * V_202 ,
T_9 * V_228 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_53 V_173 ;
int V_229 , error ;
T_7 V_230 = 0 ;
V_229 = 1 ;
error = F_66 ( V_2 , * V_202 , 1 , & V_173 , & V_229 , 0 ) ;
if ( error )
return error ;
if ( V_229 && V_173 . V_113 != V_99 ) {
T_1 V_10 ;
ASSERT ( V_173 . V_113 != V_103 ) ;
V_10 = V_173 . V_113 ;
V_230 = F_18 ( V_10 , V_8 -> V_21 . V_22 ) ;
if ( V_230 )
* V_202 += V_8 -> V_21 . V_22 - V_230 ;
}
V_229 = 1 ;
error = F_66 ( V_2 , * V_228 - 1 , 1 , & V_173 , & V_229 , 0 ) ;
if ( error )
return error ;
if ( V_229 && V_173 . V_113 != V_99 ) {
ASSERT ( V_173 . V_113 != V_103 ) ;
V_230 ++ ;
if ( V_230 && V_230 != V_8 -> V_21 . V_22 )
* V_228 -= V_230 ;
}
return 0 ;
}
static int
F_101 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_196 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_231 * V_231 = F_9 ( V_2 ) ;
T_3 V_232 , V_233 , V_93 ;
int error ;
F_102 ( V_231 ) ;
V_232 = F_58 ( T_3 , 1 << V_8 -> V_21 . V_234 , V_235 ) ;
V_233 = F_103 ( V_27 , V_232 ) ;
V_93 = F_104 ( V_27 + V_196 , V_232 ) - 1 ;
error = F_105 ( V_231 -> V_154 , V_233 , V_93 ) ;
if ( error )
return error ;
F_106 ( V_231 , V_233 , V_93 ) ;
return 0 ;
}
int
F_107 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_196 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_9 V_202 ;
T_9 V_228 ;
int V_172 = 0 , error ;
F_108 ( V_2 ) ;
error = F_80 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_196 <= 0 )
return 0 ;
error = F_101 ( V_2 , V_27 , V_196 ) ;
if ( error )
return error ;
V_202 = F_46 ( V_8 , V_27 ) ;
V_228 = F_90 ( V_8 , V_27 + V_196 ) ;
if ( F_2 ( V_2 ) &&
! F_109 ( & V_8 -> V_21 ) ) {
error = F_100 ( V_2 , & V_202 ,
& V_228 ) ;
if ( error )
return error ;
}
if ( V_228 > V_202 ) {
while ( ! V_172 ) {
error = F_98 ( V_2 , V_202 ,
V_228 - V_202 , & V_172 ) ;
if ( error )
return error ;
}
}
return F_110 ( V_2 , V_27 , V_196 , NULL ) ;
}
int
F_111 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_196 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
V_84 V_236 ;
int error ;
F_112 ( V_2 ) ;
V_236 = 1 << V_8 -> V_21 . V_234 ;
error = F_107 ( V_2 , V_27 , V_196 ) ;
if ( error )
goto V_91;
error = F_88 ( V_2 , F_103 ( V_27 , V_236 ) ,
F_104 ( V_27 + V_196 , V_236 ) -
F_103 ( V_27 , V_236 ) ,
V_237 ) ;
V_91:
return error ;
}
static int
F_113 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_196 ,
enum V_238 V_239 )
{
int V_172 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_221 * V_33 ;
int error ;
struct V_176 V_177 ;
T_2 V_240 ;
T_9 V_241 ;
T_9 V_242 ;
T_9 V_243 ;
ASSERT ( V_239 == V_244 || V_239 == V_245 ) ;
if ( V_239 == V_244 ) {
V_242 = F_46 ( V_8 , V_27 + V_196 ) ;
V_241 = F_46 ( V_8 , F_9 ( V_2 ) -> V_183 ) ;
} else {
V_242 = V_42 ;
V_241 = F_46 ( V_8 , V_27 ) ;
}
V_243 = F_46 ( V_8 , V_196 ) ;
if ( F_77 ( V_2 , true ) ) {
error = F_79 ( V_8 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_105 ( F_9 ( V_2 ) -> V_154 ,
V_27 , - 1 ) ;
if ( error )
return error ;
error = F_114 ( F_9 ( V_2 ) -> V_154 ,
V_27 >> V_246 , - 1 ) ;
if ( error )
return error ;
if ( V_239 == V_245 ) {
error = F_115 ( V_2 , V_241 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_172 ) {
error = F_82 ( V_8 , & F_83 ( V_8 ) -> V_216 ,
F_92 ( V_8 , 0 ) , 0 , 0 , & V_33 ) ;
if ( error )
break;
F_14 ( V_2 , V_31 ) ;
error = F_99 ( V_33 , V_8 , V_2 -> V_222 ,
V_2 -> V_223 , V_2 -> V_224 ,
F_92 ( V_8 , 0 ) , 0 ,
V_215 ) ;
if ( error )
goto V_225;
F_15 ( V_33 , V_2 , V_31 ) ;
F_74 ( & V_177 , & V_240 ) ;
error = F_116 ( V_33 , V_2 , & V_242 , V_243 ,
& V_172 , V_241 , & V_240 , & V_177 ,
V_239 , V_247 ) ;
if ( error )
goto V_226;
error = F_95 ( & V_33 , & V_177 , NULL ) ;
if ( error )
goto V_226;
error = F_86 ( V_33 ) ;
}
return error ;
V_226:
F_96 ( & V_177 ) ;
V_225:
F_85 ( V_33 ) ;
return error ;
}
int
F_117 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_196 )
{
int error ;
ASSERT ( F_70 ( V_2 , V_193 ) ) ;
F_118 ( V_2 ) ;
error = F_107 ( V_2 , V_27 , V_196 ) ;
if ( error )
return error ;
return F_113 ( V_2 , V_27 , V_196 , V_244 ) ;
}
int
F_119 (
struct V_1 * V_2 ,
T_24 V_27 ,
T_24 V_196 )
{
ASSERT ( F_70 ( V_2 , V_193 ) ) ;
F_120 ( V_2 ) ;
return F_113 ( V_2 , V_27 , V_196 , V_245 ) ;
}
static int
F_121 (
struct V_1 * V_2 ,
struct V_1 * V_248 )
{
if ( V_2 -> V_43 . V_143 == V_140 ||
V_248 -> V_43 . V_143 == V_140 )
return - V_134 ;
if ( V_2 -> V_43 . V_249 < V_248 -> V_43 . V_249 )
return - V_134 ;
if ( F_122 ( & V_2 -> V_4 -> V_21 ) )
return 0 ;
if ( V_2 -> V_43 . V_143 == V_82 &&
V_248 -> V_43 . V_143 == V_139 )
return - V_134 ;
if ( V_248 -> V_43 . V_143 == V_82 &&
F_63 ( V_248 , V_115 ) >
F_123 ( V_2 , V_115 ) )
return - V_134 ;
if ( V_2 -> V_43 . V_143 == V_82 &&
F_63 ( V_2 , V_115 ) >
F_123 ( V_248 , V_115 ) )
return - V_134 ;
if ( V_248 -> V_43 . V_143 == V_139 ) {
if ( F_124 ( V_2 ) &&
F_125 ( V_248 -> V_185 . V_85 ) > F_124 ( V_2 ) )
return - V_134 ;
if ( F_63 ( V_248 , V_115 ) <=
F_123 ( V_2 , V_115 ) )
return - V_134 ;
}
if ( V_2 -> V_43 . V_143 == V_139 ) {
if ( F_124 ( V_248 ) &&
F_125 ( V_2 -> V_185 . V_85 ) > F_124 ( V_248 ) )
return - V_134 ;
if ( F_63 ( V_2 , V_115 ) <=
F_123 ( V_248 , V_115 ) )
return - V_134 ;
}
return 0 ;
}
static int
F_126 (
struct V_1 * V_2 )
{
int error ;
error = F_60 ( F_9 ( V_2 ) -> V_154 ) ;
if ( error )
return error ;
F_106 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_154 -> V_184 )
return - V_134 ;
return 0 ;
}
STATIC int
F_127 (
struct V_221 * * V_250 ,
struct V_1 * V_2 ,
struct V_1 * V_248 )
{
struct V_53 V_251 ;
struct V_53 V_252 ;
struct V_53 V_253 ;
T_9 V_254 ;
T_9 V_189 ;
T_23 V_6 ;
T_2 V_203 ;
struct V_176 V_177 ;
int error ;
T_23 V_255 ;
T_23 V_256 ;
int V_174 ;
T_25 V_257 ;
V_257 = V_248 -> V_43 . V_258 ;
if ( V_2 -> V_43 . V_258 & V_259 )
V_248 -> V_43 . V_258 |= V_259 ;
V_254 = 0 ;
V_189 = F_46 ( V_2 -> V_4 , F_128 ( F_9 ( V_2 ) ) ) ;
V_6 = ( T_23 ) ( V_189 - V_254 ) ;
while ( V_6 ) {
V_174 = 1 ;
error = F_66 ( V_248 , V_254 , V_6 , & V_253 ,
& V_174 , 0 ) ;
if ( error )
goto V_91;
ASSERT ( V_174 == 1 ) ;
ASSERT ( V_253 . V_113 != V_103 ) ;
F_129 ( V_248 , & V_253 ) ;
V_255 = V_253 . V_56 ;
while ( V_253 . V_56 ) {
F_74 ( & V_177 , & V_203 ) ;
F_130 ( V_248 , & V_253 ) ;
V_174 = 1 ;
error = F_66 ( V_2 , V_253 . V_55 ,
V_253 . V_56 , & V_251 ,
& V_174 , 0 ) ;
if ( error )
goto V_260;
ASSERT ( V_174 == 1 ) ;
ASSERT ( V_253 . V_55 == V_251 . V_55 ) ;
F_130 ( V_2 , & V_251 ) ;
V_252 = V_253 ;
V_252 . V_56 = V_256 = F_91 ( T_23 ,
V_253 . V_56 ,
V_251 . V_56 ) ;
F_130 ( V_248 , & V_252 ) ;
error = F_131 ( ( * V_250 ) -> V_261 , & V_177 ,
V_248 , & V_252 ) ;
if ( error )
goto V_260;
error = F_131 ( ( * V_250 ) -> V_261 , & V_177 ,
V_2 , & V_251 ) ;
if ( error )
goto V_260;
error = F_132 ( ( * V_250 ) -> V_261 , & V_177 ,
V_2 , & V_252 ) ;
if ( error )
goto V_260;
error = F_132 ( ( * V_250 ) -> V_261 , & V_177 ,
V_248 , & V_251 ) ;
if ( error )
goto V_260;
error = F_95 ( V_250 , & V_177 , V_2 ) ;
if ( error )
goto V_260;
V_253 . V_55 += V_256 ;
if ( V_253 . V_113 != V_99 &&
V_253 . V_113 != V_103 )
V_253 . V_113 += V_256 ;
V_253 . V_56 -= V_256 ;
}
V_6 -= V_255 ;
V_254 += V_255 ;
}
V_248 -> V_43 . V_258 = V_257 ;
return 0 ;
V_260:
F_96 ( & V_177 ) ;
V_91:
F_133 ( V_2 , error , V_262 ) ;
V_248 -> V_43 . V_258 = V_257 ;
return error ;
}
STATIC int
F_134 (
struct V_221 * V_33 ,
struct V_1 * V_2 ,
struct V_1 * V_248 ,
int * V_263 ,
int * V_264 )
{
struct V_265 V_266 , * V_57 , * V_267 ;
int V_268 = 0 ;
int V_269 = 0 ;
T_25 V_270 ;
int error ;
if ( ( ( F_56 ( V_2 ) != 0 ) && ( V_2 -> V_43 . V_271 > 0 ) ) &&
( V_2 -> V_43 . V_138 != V_140 ) ) {
error = F_39 ( V_33 , V_2 , V_136 ,
& V_268 ) ;
if ( error )
return error ;
}
if ( ( ( F_56 ( V_248 ) != 0 ) && ( V_248 -> V_43 . V_271 > 0 ) ) &&
( V_248 -> V_43 . V_138 != V_140 ) ) {
error = F_39 ( V_33 , V_248 , V_136 ,
& V_269 ) ;
if ( error )
return error ;
}
if ( V_2 -> V_43 . V_272 == 3 &&
V_2 -> V_43 . V_143 == V_139 ) {
( * V_264 ) |= V_273 ;
error = F_135 ( V_33 , V_2 , V_115 ,
V_248 -> V_179 , NULL ) ;
if ( error )
return error ;
}
if ( V_248 -> V_43 . V_272 == 3 &&
V_248 -> V_43 . V_143 == V_139 ) {
( * V_263 ) |= V_273 ;
error = F_135 ( V_33 , V_248 , V_115 ,
V_2 -> V_179 , NULL ) ;
if ( error )
return error ;
}
V_57 = & V_2 -> V_185 ;
V_267 = & V_248 -> V_185 ;
V_266 = * V_57 ;
* V_57 = * V_267 ;
* V_267 = V_266 ;
V_270 = ( T_25 ) V_2 -> V_43 . V_44 ;
V_2 -> V_43 . V_44 = V_248 -> V_43 . V_44 - V_269 + V_268 ;
V_248 -> V_43 . V_44 = V_270 + V_269 - V_268 ;
V_270 = ( T_25 ) V_2 -> V_43 . V_249 ;
V_2 -> V_43 . V_249 = V_248 -> V_43 . V_249 ;
V_248 -> V_43 . V_249 = V_270 ;
V_270 = ( T_25 ) V_2 -> V_43 . V_143 ;
V_2 -> V_43 . V_143 = V_248 -> V_43 . V_143 ;
V_248 -> V_43 . V_143 = V_270 ;
ASSERT ( V_248 -> V_46 == 0 ) ;
V_248 -> V_46 = V_2 -> V_46 ;
V_2 -> V_46 = 0 ;
switch ( V_2 -> V_43 . V_143 ) {
case V_82 :
if ( V_2 -> V_43 . V_249 <= V_274 ) {
V_57 -> V_275 . V_276 =
V_57 -> V_277 . V_278 ;
}
( * V_263 ) |= V_279 ;
break;
case V_139 :
ASSERT ( V_2 -> V_43 . V_272 < 3 ||
( * V_263 & V_273 ) ) ;
( * V_263 ) |= V_280 ;
break;
}
switch ( V_248 -> V_43 . V_143 ) {
case V_82 :
if ( V_248 -> V_43 . V_249 <= V_274 ) {
V_267 -> V_275 . V_276 =
V_267 -> V_277 . V_278 ;
}
( * V_264 ) |= V_279 ;
break;
case V_139 :
( * V_264 ) |= V_280 ;
ASSERT ( V_248 -> V_43 . V_272 < 3 ||
( * V_264 & V_273 ) ) ;
break;
}
return 0 ;
}
int
F_136 (
struct V_1 * V_2 ,
struct V_1 * V_248 ,
struct V_281 * V_282 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_221 * V_33 ;
struct V_283 * V_284 = & V_282 -> V_285 ;
int V_263 , V_264 ;
int error = 0 ;
int V_286 ;
struct V_265 * V_287 ;
T_25 V_288 ;
int V_209 ;
V_286 = V_193 | V_289 ;
F_137 ( V_2 , V_248 , V_193 ) ;
F_137 ( V_2 , V_248 , V_289 ) ;
if ( ( F_9 ( V_2 ) -> V_182 & V_290 ) != ( F_9 ( V_248 ) -> V_182 & V_290 ) ) {
error = - V_134 ;
goto V_227;
}
if ( F_2 ( V_2 ) != F_2 ( V_248 ) ) {
error = - V_134 ;
goto V_227;
}
error = F_126 ( V_2 ) ;
if ( error )
goto V_227;
error = F_126 ( V_248 ) ;
if ( error )
goto V_227;
if ( F_122 ( & V_8 -> V_21 ) ) {
V_209 = F_138 ( V_8 ,
F_63 ( V_2 , V_115 ) ,
V_115 ) +
F_138 ( V_8 ,
F_63 ( V_248 , V_115 ) ,
V_115 ) ;
error = F_82 ( V_8 , & F_83 ( V_8 ) -> V_216 , V_209 ,
0 , 0 , & V_33 ) ;
} else
error = F_82 ( V_8 , & F_83 ( V_8 ) -> V_291 , 0 ,
0 , 0 , & V_33 ) ;
if ( error )
goto V_227;
F_137 ( V_2 , V_248 , V_31 ) ;
V_286 |= V_31 ;
F_15 ( V_33 , V_2 , 0 ) ;
F_15 ( V_33 , V_248 , 0 ) ;
if ( V_282 -> V_292 != 0 ||
V_282 -> V_293 != V_2 -> V_43 . V_153 ||
V_282 -> V_293 != V_248 -> V_43 . V_153 ) {
error = - V_294 ;
goto V_225;
}
F_139 ( V_2 , 0 ) ;
F_139 ( V_248 , 1 ) ;
error = F_121 ( V_2 , V_248 ) ;
if ( error ) {
F_140 ( V_8 ,
L_5 ,
V_295 , V_2 -> V_179 ) ;
goto V_225;
}
if ( ( V_284 -> V_296 . V_297 != F_9 ( V_2 ) -> V_298 . V_297 ) ||
( V_284 -> V_296 . V_299 != F_9 ( V_2 ) -> V_298 . V_299 ) ||
( V_284 -> V_300 . V_297 != F_9 ( V_2 ) -> V_301 . V_297 ) ||
( V_284 -> V_300 . V_299 != F_9 ( V_2 ) -> V_301 . V_299 ) ) {
error = - V_302 ;
goto V_225;
}
V_263 = V_45 ;
V_264 = V_45 ;
if ( F_122 ( & V_8 -> V_21 ) )
error = F_127 ( & V_33 , V_2 , V_248 ) ;
else
error = F_134 ( V_33 , V_2 , V_248 , & V_263 ,
& V_264 ) ;
if ( error )
goto V_225;
if ( ( V_2 -> V_43 . V_258 & V_259 ) ^
( V_248 -> V_43 . V_258 & V_259 ) ) {
V_288 = V_2 -> V_43 . V_258 & V_259 ;
V_2 -> V_43 . V_258 &= ~ V_259 ;
V_2 -> V_43 . V_258 |= V_248 -> V_43 . V_258 & V_259 ;
V_248 -> V_43 . V_258 &= ~ V_259 ;
V_248 -> V_43 . V_258 |= V_288 & V_259 ;
V_287 = V_2 -> V_303 ;
V_2 -> V_303 = V_248 -> V_303 ;
V_248 -> V_303 = V_287 ;
F_141 ( V_2 ) ;
F_141 ( V_248 ) ;
}
F_20 ( V_33 , V_2 , V_263 ) ;
F_20 ( V_33 , V_248 , V_264 ) ;
if ( V_8 -> V_304 & V_305 )
F_142 ( V_33 ) ;
error = F_86 ( V_33 ) ;
F_143 ( V_2 , 0 ) ;
F_143 ( V_248 , 1 ) ;
F_68 ( V_2 , V_286 ) ;
F_68 ( V_248 , V_286 ) ;
return error ;
V_225:
F_85 ( V_33 ) ;
V_227:
F_68 ( V_2 , V_286 ) ;
F_68 ( V_248 , V_286 ) ;
return error ;
}
