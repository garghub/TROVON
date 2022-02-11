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
F_24 ( V_57 , 0 , F_42 ( V_57 ) , V_60 ) ;
return 0 ;
}
V_10 = V_57 -> V_83 ;
V_68 = F_38 ( V_10 -> V_84 ) ;
ASSERT ( V_68 > 0 ) ;
V_69 = F_43 ( V_8 , V_10 , 1 , V_57 -> V_85 ) ;
V_70 = F_33 ( * V_69 ) ;
ASSERT ( V_70 != V_42 ) ;
ASSERT ( F_44 ( V_8 , V_70 ) < V_8 -> V_21 . V_86 ) ;
ASSERT ( F_45 ( V_8 , V_70 ) < V_8 -> V_21 . V_87 ) ;
if ( F_36 ( F_30 ( V_8 , V_33 , V_57 , V_70 , V_68 , V_60 ) < 0 ) ) {
F_37 ( L_2 , V_79 ,
V_8 ) ;
return - V_80 ;
}
return 0 ;
}
STATIC int
F_46 (
T_17 * V_2 ,
int V_52 ,
struct V_88 * V_89 ,
int V_90 ,
T_18 V_91 ,
T_2 V_92 ,
bool V_93 )
{
T_18 V_94 ;
T_6 * V_8 ;
T_10 * V_57 ;
T_11 V_95 ;
T_9 V_96 ;
if ( V_92 == V_97 ) {
V_8 = V_2 -> V_4 ;
V_89 -> V_98 = - 1 ;
V_94 = F_3 ( V_8 , F_47 ( V_8 , F_48 ( V_2 ) ) ) ;
V_94 -= V_89 -> V_99 ;
if ( V_90 && V_89 -> V_99 + V_89 -> V_100 == V_91 ) {
if ( V_94 <= 0 )
return 0 ;
V_89 -> V_100 = V_94 ;
}
} else {
if ( V_92 == V_101 )
V_89 -> V_98 = - 2 ;
else
V_89 -> V_98 = F_1 ( V_2 , V_92 ) ;
V_96 = F_49 ( V_2 -> V_4 , V_89 -> V_99 ) ;
V_57 = F_40 ( V_2 , V_52 ) ;
if ( ! V_93 &&
F_50 ( V_57 , V_96 , & V_95 ) &&
( V_95 == F_42 ( V_57 ) - 1 ) )
V_89 -> V_102 |= V_103 ;
}
return 1 ;
}
STATIC int
F_51 (
struct V_1 * V_2 ,
int V_52 ,
struct V_53 * V_104 ,
struct V_88 * V_89 ,
struct V_53 * V_105 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_19 V_106 ;
T_20 V_107 ;
T_20 V_108 ;
T_7 V_109 ;
T_7 V_110 ;
int error ;
V_105 -> V_111 = V_42 ;
V_105 -> V_55 = V_112 ;
V_105 -> V_56 = 0 ;
if ( ! F_52 ( V_2 ) || V_52 != V_113 ||
V_104 -> V_111 == V_101 ||
V_104 -> V_111 == V_97 ||
F_53 ( V_104 ) )
return 0 ;
V_106 = F_44 ( V_8 , V_104 -> V_111 ) ;
V_107 = F_45 ( V_8 , V_104 -> V_111 ) ;
error = F_54 ( V_8 , V_106 , V_107 , V_104 -> V_56 ,
& V_108 , & V_109 , true ) ;
if ( error )
return error ;
if ( V_108 == V_114 ) {
return 0 ;
} else if ( V_107 == V_108 ) {
V_89 -> V_100 = F_3 ( V_8 , V_109 ) ;
V_89 -> V_102 |= V_115 ;
if ( V_109 != V_104 -> V_56 ) {
* V_105 = * V_104 ;
V_105 -> V_111 += V_109 ;
V_105 -> V_55 += V_109 ;
V_105 -> V_56 -= V_109 ;
}
V_104 -> V_56 -= V_109 ;
} else {
* V_105 = * V_104 ;
V_110 = V_108 - V_107 ;
V_89 -> V_100 = F_3 ( V_8 , V_110 ) ;
V_105 -> V_111 += V_110 ;
V_105 -> V_55 += V_110 ;
V_105 -> V_56 -= V_110 ;
V_104 -> V_56 -= V_110 ;
}
return 0 ;
}
int
F_55 (
T_17 * V_2 ,
struct V_88 * V_116 ,
T_21 V_117 ,
void * V_118 )
{
T_18 V_119 ;
int error = 0 ;
T_18 V_94 ;
int V_120 ;
int V_121 ;
T_22 * V_104 ;
T_6 * V_8 ;
int V_122 ;
int V_123 ;
int V_124 ;
struct V_88 * V_89 ;
int V_52 ;
int V_90 ;
int V_125 ;
int V_126 ;
int V_127 = 0 ;
struct V_53 V_128 ;
V_8 = V_2 -> V_4 ;
V_125 = V_116 -> V_129 ;
#ifndef F_56
if ( V_125 & V_130 )
return - V_131 ;
#endif
if ( ( V_125 & V_132 ) && ( V_125 & V_130 ) )
return - V_131 ;
if ( V_125 & V_132 )
V_52 = V_133 ;
else if ( V_125 & V_130 )
V_52 = V_134 ;
else
V_52 = V_113 ;
switch ( V_52 ) {
case V_133 :
if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_43 . V_135 != V_82 &&
V_2 -> V_43 . V_135 != V_136 &&
V_2 -> V_43 . V_135 != V_137 )
return - V_131 ;
} else if ( F_36 (
V_2 -> V_43 . V_135 != 0 &&
V_2 -> V_43 . V_135 != V_82 ) ) {
F_37 ( L_3 , V_79 ,
V_2 -> V_4 ) ;
return - V_80 ;
}
V_90 = 0 ;
V_94 = 1LL << 32 ;
break;
case V_134 :
if ( V_2 -> V_138 != V_82 )
return - V_131 ;
if ( F_58 ( V_2 ) ) {
V_90 = 1 ;
V_94 = V_8 -> V_11 -> V_139 ;
} else {
V_90 = 0 ;
V_94 = F_48 ( V_2 ) ;
}
break;
default:
if ( V_2 -> V_43 . V_140 != V_82 &&
V_2 -> V_43 . V_140 != V_136 &&
V_2 -> V_43 . V_140 != V_137 )
return - V_131 ;
if ( F_11 ( V_2 ) ||
V_2 -> V_43 . V_141 & ( V_142 | V_143 ) ) {
V_90 = 1 ;
V_94 = V_8 -> V_11 -> V_139 ;
} else {
V_90 = 0 ;
V_94 = F_48 ( V_2 ) ;
}
break;
}
if ( V_116 -> V_100 == - 1 ) {
V_94 = F_3 ( V_8 , F_47 ( V_8 , V_94 ) ) ;
V_116 -> V_100 =
F_59 ( T_18 , V_94 - V_116 -> V_99 , 0 ) ;
} else if ( V_116 -> V_100 == 0 ) {
V_116 -> V_144 = 0 ;
return 0 ;
} else if ( V_116 -> V_100 < 0 ) {
return - V_131 ;
}
V_122 = V_116 -> V_145 - 1 ;
if ( V_122 <= 0 )
return - V_131 ;
V_119 = V_116 -> V_99 + V_116 -> V_100 ;
if ( V_116 -> V_145 > V_146 / sizeof( struct V_88 ) )
return - V_147 ;
V_89 = F_60 ( V_116 -> V_145 * sizeof( struct V_88 ) , 0 ) ;
if ( ! V_89 )
return - V_147 ;
F_14 ( V_2 , V_148 ) ;
switch ( V_52 ) {
case V_113 :
if ( ! ( V_125 & V_149 ) &&
( V_2 -> V_46 || F_48 ( V_2 ) > V_2 -> V_43 . V_150 ) ) {
error = F_61 ( F_9 ( V_2 ) -> V_151 ) ;
if ( error )
goto V_152;
}
V_121 = F_62 ( V_2 ) ;
break;
case V_134 :
V_121 = V_153 ;
F_14 ( V_2 , V_121 ) ;
break;
case V_133 :
V_121 = F_63 ( V_2 ) ;
break;
}
if ( V_122 > F_64 ( V_2 , V_52 ) * 2 + 1 )
V_122 = F_64 ( V_2 , V_52 ) * 2 + 1 ;
V_126 = F_65 ( V_52 ) ;
if ( ! ( V_125 & V_154 ) )
V_126 |= V_155 ;
error = - V_147 ;
V_123 = 16 ;
V_104 = F_66 ( V_123 * sizeof( * V_104 ) , V_156 | V_157 ) ;
if ( ! V_104 )
goto V_158;
V_116 -> V_144 = 0 ;
if ( F_64 ( V_2 , V_52 ) == 0 &&
( V_52 == V_133 || ! ( V_125 & V_149 ) ) ) {
error = 0 ;
goto V_159;
}
do {
V_124 = ( V_122 > V_123 ) ? V_123 : V_122 ;
error = F_67 ( V_2 , F_6 ( V_8 , V_116 -> V_99 ) ,
F_49 ( V_8 , V_116 -> V_100 ) ,
V_104 , & V_124 , V_126 ) ;
if ( error )
goto V_159;
ASSERT ( V_124 <= V_123 ) ;
for ( V_120 = 0 ; V_120 < V_124 && V_116 -> V_100 &&
V_127 < V_116 -> V_145 - 1 ; V_120 ++ ) {
V_89 [ V_127 ] . V_102 = 0 ;
if ( V_104 [ V_120 ] . V_160 == V_161 )
V_89 [ V_127 ] . V_102 |= V_162 ;
else if ( V_104 [ V_120 ] . V_111 == V_101 )
V_89 [ V_127 ] . V_102 |= V_163 ;
V_89 [ V_127 ] . V_99 =
F_3 ( V_8 , V_104 [ V_120 ] . V_55 ) ;
V_89 [ V_127 ] . V_100 =
F_3 ( V_8 , V_104 [ V_120 ] . V_56 ) ;
V_89 [ V_127 ] . V_164 = 0 ;
V_89 [ V_127 ] . V_165 = 0 ;
if ( V_104 [ V_120 ] . V_111 == V_101 &&
V_104 [ V_120 ] . V_55 <= F_47 ( V_8 , F_48 ( V_2 ) ) )
ASSERT ( ( V_125 & V_149 ) != 0 ) ;
if ( V_104 [ V_120 ] . V_111 == V_97 &&
V_52 == V_133 ) {
V_89 [ V_127 ] . V_102 |= V_103 ;
goto V_159;
}
error = F_51 ( V_2 , V_52 ,
& V_104 [ V_120 ] , & V_89 [ V_127 ] , & V_128 ) ;
if ( error )
goto V_159;
if ( ! F_46 ( V_2 , V_52 ,
& V_89 [ V_127 ] , V_90 , V_119 ,
V_104 [ V_120 ] . V_111 ,
V_128 . V_111 != V_42 ) )
goto V_159;
V_116 -> V_99 =
V_89 [ V_127 ] . V_99 +
V_89 [ V_127 ] . V_100 ;
V_116 -> V_100 =
F_59 ( T_18 , 0 , V_119 - V_116 -> V_99 ) ;
if ( ( V_125 & V_166 ) &&
V_104 [ V_120 ] . V_111 == V_97 ) {
memset ( & V_89 [ V_127 ] , 0 , sizeof( V_89 [ V_127 ] ) ) ;
continue;
}
if ( V_128 . V_111 != V_42 ) {
V_104 [ V_120 ] = V_128 ;
V_120 -- ;
}
V_116 -> V_144 ++ ;
V_127 ++ ;
}
} while ( V_124 && V_116 -> V_100 && V_127 < V_116 -> V_145 - 1 );
V_159:
F_68 ( V_104 ) ;
V_158:
F_69 ( V_2 , V_121 ) ;
V_152:
F_69 ( V_2 , V_148 ) ;
for ( V_120 = 0 ; V_120 < V_127 ; V_120 ++ ) {
int V_167 = 0 ;
error = V_117 ( & V_118 , & V_89 [ V_120 ] , & V_167 ) ;
if ( error || V_167 )
break;
}
F_68 ( V_89 ) ;
return error ;
}
int
F_70 (
struct V_1 * V_2 ,
T_9 V_5 ,
T_9 V_28 )
{
T_9 V_168 = V_28 ;
int error = 0 ;
ASSERT ( F_71 ( V_2 , V_31 ) ) ;
do {
int V_169 ;
T_22 V_170 ;
int V_171 = 1 ;
T_2 V_172 ;
struct V_173 V_174 ;
error = F_67 ( V_2 , V_5 , 1 , & V_170 , & V_171 ,
V_175 ) ;
if ( error ) {
if ( ! F_72 ( V_2 -> V_4 ) ) {
F_73 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_176 , V_5 ) ;
}
break;
}
if ( ! V_171 ) {
goto V_177;
}
if ( V_170 . V_111 != V_101 ) {
goto V_177;
}
F_74 ( V_170 . V_56 == 0 ) ;
F_75 ( & V_174 , & V_172 ) ;
error = F_76 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_172 ,
& V_174 , & V_169 ) ;
if ( error )
break;
ASSERT ( ! F_77 ( & V_174 ) ) ;
V_177:
V_5 ++ ;
V_168 -- ;
} while( V_168 > 0 );
return error ;
}
bool
F_78 ( struct V_1 * V_2 , bool V_178 )
{
if ( ! F_79 ( F_9 ( V_2 ) -> V_179 ) )
return false ;
if ( F_9 ( V_2 ) -> V_180 == 0 &&
F_9 ( V_2 ) -> V_151 -> V_181 == 0 &&
V_2 -> V_46 == 0 )
return false ;
if ( ! ( V_2 -> V_182 . V_183 & V_184 ) )
return false ;
if ( V_2 -> V_43 . V_141 & ( V_142 | V_143 ) )
if ( ! V_178 || V_2 -> V_46 == 0 )
return false ;
return true ;
}
int
F_80 (
T_6 * V_8 ,
T_17 * V_2 ,
bool V_185 )
{
T_14 * V_33 ;
int error ;
T_9 V_186 ;
T_9 V_187 ;
T_23 V_188 ;
int V_171 ;
T_22 V_170 ;
V_186 = F_47 ( V_8 , ( V_189 ) F_48 ( V_2 ) ) ;
V_187 = F_47 ( V_8 , V_8 -> V_11 -> V_139 ) ;
if ( V_187 <= V_186 )
return 0 ;
V_188 = V_187 - V_186 ;
V_171 = 1 ;
F_14 ( V_2 , V_153 ) ;
error = F_67 ( V_2 , V_186 , V_188 , & V_170 , & V_171 , 0 ) ;
F_69 ( V_2 , V_153 ) ;
if ( ! error && ( V_171 != 0 ) &&
( V_170 . V_111 != V_97 ||
V_2 -> V_46 ) ) {
error = F_81 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_185 ) {
if ( ! F_82 ( V_2 , V_190 ) )
return - V_191 ;
}
error = F_83 ( V_8 , & F_84 ( V_8 ) -> V_192 , 0 , 0 , 0 ,
& V_33 ) ;
if ( error ) {
ASSERT ( F_72 ( V_8 ) ) ;
if ( V_185 )
F_69 ( V_2 , V_190 ) ;
return error ;
}
F_14 ( V_2 , V_31 ) ;
F_15 ( V_33 , V_2 , 0 ) ;
error = F_85 ( & V_33 , V_2 , V_113 ,
F_48 ( V_2 ) ) ;
if ( error ) {
F_86 ( V_33 ) ;
} else {
error = F_87 ( V_33 ) ;
if ( ! error )
F_88 ( V_2 ) ;
}
F_69 ( V_2 , V_31 ) ;
if ( V_185 )
F_69 ( V_2 , V_190 ) ;
}
return error ;
}
int
F_89 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_193 ,
int V_194 )
{
T_6 * V_8 = V_2 -> V_4 ;
T_3 V_60 ;
T_23 V_195 ;
T_23 V_196 ;
T_7 V_197 , V_198 ;
T_9 V_199 ;
T_2 V_200 ;
int V_171 ;
int V_201 ;
int V_202 ;
T_14 * V_33 ;
T_22 V_203 [ 1 ] , * V_204 ;
struct V_173 V_174 ;
T_24 V_205 , V_206 , V_207 ;
int error ;
F_90 ( V_2 ) ;
if ( F_72 ( V_8 ) )
return - V_208 ;
error = F_81 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_193 <= 0 )
return - V_131 ;
V_202 = F_2 ( V_2 ) ;
V_197 = F_11 ( V_2 ) ;
V_60 = V_193 ;
V_204 = & V_203 [ 0 ] ;
V_171 = 1 ;
V_199 = F_91 ( V_8 , V_27 ) ;
V_196 = F_47 ( V_8 , V_60 ) ;
while ( V_196 && ! error ) {
T_9 V_209 , V_210 ;
if ( F_36 ( V_197 ) ) {
V_209 = V_199 ;
F_18 ( V_209 , V_197 ) ;
V_209 *= V_197 ;
V_210 = V_199 + V_196 ;
if ( ( V_198 = F_13 ( V_199 , V_197 ) ) )
V_210 += V_198 ;
if ( ( V_198 = F_13 ( V_210 , V_197 ) ) )
V_210 += V_197 - V_198 ;
} else {
V_209 = 0 ;
V_210 = V_196 ;
}
V_206 = F_92 ( T_9 , ( V_210 - V_209 ) , ( V_29 * V_171 ) ) ;
if ( F_36 ( V_202 ) ) {
V_207 = V_205 = V_206 ;
V_207 /= V_8 -> V_21 . V_22 ;
V_206 = F_93 ( V_8 , 0 ) ;
V_201 = V_211 ;
} else {
V_207 = 0 ;
V_206 = V_205 = F_93 ( V_8 , V_206 ) ;
V_201 = V_212 ;
}
error = F_83 ( V_8 , & F_84 ( V_8 ) -> V_213 , V_206 ,
V_207 , 0 , & V_33 ) ;
if ( error ) {
ASSERT ( error == - V_214 || F_72 ( V_8 ) ) ;
break;
}
F_14 ( V_2 , V_31 ) ;
error = F_94 ( V_33 , V_2 , V_205 ,
0 , V_201 ) ;
if ( error )
goto V_215;
F_15 ( V_33 , V_2 , 0 ) ;
F_75 ( & V_174 , & V_200 ) ;
error = F_95 ( V_33 , V_2 , V_199 ,
V_196 , V_194 , & V_200 ,
V_206 , V_204 , & V_171 , & V_174 ) ;
if ( error )
goto V_216;
error = F_96 ( & V_33 , & V_174 , NULL ) ;
if ( error )
goto V_216;
error = F_87 ( V_33 ) ;
F_69 ( V_2 , V_31 ) ;
if ( error )
break;
V_195 = V_204 -> V_56 ;
if ( V_171 == 0 ) {
error = - V_214 ;
break;
}
V_199 += V_195 ;
V_196 -= V_195 ;
}
return error ;
V_216:
F_97 ( & V_174 ) ;
F_98 ( V_33 , V_2 , ( long ) V_205 , 0 , V_201 ) ;
V_215:
F_86 ( V_33 ) ;
F_69 ( V_2 , V_31 ) ;
return error ;
}
static int
F_99 (
struct V_1 * V_2 ,
T_9 V_199 ,
T_23 V_217 ,
int * V_169 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_218 * V_33 ;
struct V_173 V_174 ;
T_2 V_200 ;
T_24 V_206 = F_93 ( V_8 , 0 ) ;
int error ;
error = F_83 ( V_8 , & F_84 ( V_8 ) -> V_213 , V_206 , 0 , 0 , & V_33 ) ;
if ( error ) {
ASSERT ( error == - V_214 || F_72 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_31 ) ;
error = F_100 ( V_33 , V_8 , V_2 -> V_219 , V_2 -> V_220 ,
V_2 -> V_221 , V_206 , 0 , V_212 ) ;
if ( error )
goto V_222;
F_15 ( V_33 , V_2 , 0 ) ;
F_75 ( & V_174 , & V_200 ) ;
error = F_76 ( V_33 , V_2 , V_199 , V_217 , 0 , 2 , & V_200 ,
& V_174 , V_169 ) ;
if ( error )
goto V_223;
error = F_96 ( & V_33 , & V_174 , V_2 ) ;
if ( error )
goto V_223;
error = F_87 ( V_33 ) ;
V_224:
F_69 ( V_2 , V_31 ) ;
return error ;
V_223:
F_97 ( & V_174 ) ;
V_222:
F_86 ( V_33 ) ;
goto V_224;
}
static int
F_101 (
struct V_1 * V_2 ,
T_9 * V_199 ,
T_9 * V_225 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_53 V_170 ;
int V_226 , error ;
T_7 V_227 = 0 ;
V_226 = 1 ;
error = F_67 ( V_2 , * V_199 , 1 , & V_170 , & V_226 , 0 ) ;
if ( error )
return error ;
if ( V_226 && V_170 . V_111 != V_97 ) {
T_1 V_10 ;
ASSERT ( V_170 . V_111 != V_101 ) ;
V_10 = V_170 . V_111 ;
V_227 = F_18 ( V_10 , V_8 -> V_21 . V_22 ) ;
if ( V_227 )
* V_199 += V_8 -> V_21 . V_22 - V_227 ;
}
V_226 = 1 ;
error = F_67 ( V_2 , * V_225 - 1 , 1 , & V_170 , & V_226 , 0 ) ;
if ( error )
return error ;
if ( V_226 && V_170 . V_111 != V_97 ) {
ASSERT ( V_170 . V_111 != V_101 ) ;
V_227 ++ ;
if ( V_227 && V_227 != V_8 -> V_21 . V_22 )
* V_225 -= V_227 ;
}
return 0 ;
}
static int
F_102 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_193 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_228 * V_228 = F_9 ( V_2 ) ;
T_3 V_229 , V_230 , V_91 ;
int error ;
F_103 ( V_228 ) ;
V_229 = F_59 ( T_3 , 1 << V_8 -> V_21 . V_231 , V_232 ) ;
V_230 = F_104 ( V_27 , V_229 ) ;
V_91 = F_105 ( V_27 + V_193 , V_229 ) - 1 ;
error = F_106 ( V_228 -> V_151 , V_230 , V_91 ) ;
if ( error )
return error ;
F_107 ( V_228 , V_230 , V_91 ) ;
return 0 ;
}
int
F_108 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_193 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_9 V_199 ;
T_9 V_225 ;
int V_169 = 0 , error ;
F_109 ( V_2 ) ;
error = F_81 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_193 <= 0 )
return 0 ;
error = F_102 ( V_2 , V_27 , V_193 ) ;
if ( error )
return error ;
V_199 = F_47 ( V_8 , V_27 ) ;
V_225 = F_91 ( V_8 , V_27 + V_193 ) ;
if ( F_2 ( V_2 ) &&
! F_110 ( & V_8 -> V_21 ) ) {
error = F_101 ( V_2 , & V_199 ,
& V_225 ) ;
if ( error )
return error ;
}
if ( V_225 > V_199 ) {
while ( ! V_169 ) {
error = F_99 ( V_2 , V_199 ,
V_225 - V_199 , & V_169 ) ;
if ( error )
return error ;
}
}
return F_111 ( V_2 , V_27 , V_193 , NULL ) ;
}
int
F_112 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_193 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_24 V_233 ;
int error ;
F_113 ( V_2 ) ;
V_233 = 1 << V_8 -> V_21 . V_231 ;
error = F_108 ( V_2 , V_27 , V_193 ) ;
if ( error )
goto V_89;
error = F_89 ( V_2 , F_104 ( V_27 , V_233 ) ,
F_105 ( V_27 + V_193 , V_233 ) -
F_104 ( V_27 , V_233 ) ,
V_234 ) ;
V_89:
return error ;
}
static int
F_114 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_193 ,
enum V_235 V_236 )
{
int V_169 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_218 * V_33 ;
int error ;
struct V_173 V_174 ;
T_2 V_237 ;
T_9 V_238 ;
T_9 V_239 ;
T_9 V_240 ;
ASSERT ( V_236 == V_241 || V_236 == V_242 ) ;
if ( V_236 == V_241 ) {
V_239 = F_47 ( V_8 , V_27 + V_193 ) ;
V_238 = F_47 ( V_8 , F_9 ( V_2 ) -> V_180 ) ;
} else {
V_239 = V_42 ;
V_238 = F_47 ( V_8 , V_27 ) ;
}
V_240 = F_47 ( V_8 , V_193 ) ;
if ( F_78 ( V_2 , true ) ) {
error = F_80 ( V_8 , V_2 , false ) ;
if ( error )
return error ;
}
error = F_106 ( F_9 ( V_2 ) -> V_151 ,
V_27 , - 1 ) ;
if ( error )
return error ;
error = F_115 ( F_9 ( V_2 ) -> V_151 ,
V_27 >> V_243 , - 1 ) ;
if ( error )
return error ;
if ( V_236 == V_242 ) {
error = F_116 ( V_2 , V_238 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_169 ) {
error = F_83 ( V_8 , & F_84 ( V_8 ) -> V_213 ,
F_93 ( V_8 , 0 ) , 0 , 0 , & V_33 ) ;
if ( error )
break;
F_14 ( V_2 , V_31 ) ;
error = F_100 ( V_33 , V_8 , V_2 -> V_219 ,
V_2 -> V_220 , V_2 -> V_221 ,
F_93 ( V_8 , 0 ) , 0 ,
V_212 ) ;
if ( error )
goto V_222;
F_15 ( V_33 , V_2 , V_31 ) ;
F_75 ( & V_174 , & V_237 ) ;
error = F_117 ( V_33 , V_2 , & V_239 , V_240 ,
& V_169 , V_238 , & V_237 , & V_174 ,
V_236 , V_244 ) ;
if ( error )
goto V_223;
error = F_96 ( & V_33 , & V_174 , NULL ) ;
if ( error )
goto V_223;
error = F_87 ( V_33 ) ;
}
return error ;
V_223:
F_97 ( & V_174 ) ;
V_222:
F_86 ( V_33 ) ;
return error ;
}
int
F_118 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_193 )
{
int error ;
ASSERT ( F_71 ( V_2 , V_190 ) ) ;
F_119 ( V_2 ) ;
error = F_108 ( V_2 , V_27 , V_193 ) ;
if ( error )
return error ;
return F_114 ( V_2 , V_27 , V_193 , V_241 ) ;
}
int
F_120 (
struct V_1 * V_2 ,
T_25 V_27 ,
T_25 V_193 )
{
ASSERT ( F_71 ( V_2 , V_190 ) ) ;
F_121 ( V_2 ) ;
return F_114 ( V_2 , V_27 , V_193 , V_242 ) ;
}
static int
F_122 (
struct V_1 * V_2 ,
struct V_1 * V_245 )
{
if ( V_2 -> V_43 . V_140 == V_137 ||
V_245 -> V_43 . V_140 == V_137 )
return - V_131 ;
if ( V_2 -> V_43 . V_246 < V_245 -> V_43 . V_246 )
return - V_131 ;
if ( F_123 ( & V_2 -> V_4 -> V_21 ) )
return 0 ;
if ( V_2 -> V_43 . V_140 == V_82 &&
V_245 -> V_43 . V_140 == V_136 )
return - V_131 ;
if ( V_245 -> V_43 . V_140 == V_82 &&
F_64 ( V_245 , V_113 ) >
F_124 ( V_2 , V_113 ) )
return - V_131 ;
if ( V_2 -> V_43 . V_140 == V_82 &&
F_64 ( V_2 , V_113 ) >
F_124 ( V_245 , V_113 ) )
return - V_131 ;
if ( V_245 -> V_43 . V_140 == V_136 ) {
if ( F_125 ( V_2 ) &&
F_126 ( V_245 -> V_182 . V_83 ) > F_125 ( V_2 ) )
return - V_131 ;
if ( F_64 ( V_245 , V_113 ) <=
F_124 ( V_2 , V_113 ) )
return - V_131 ;
}
if ( V_2 -> V_43 . V_140 == V_136 ) {
if ( F_125 ( V_245 ) &&
F_126 ( V_2 -> V_182 . V_83 ) > F_125 ( V_245 ) )
return - V_131 ;
if ( F_64 ( V_2 , V_113 ) <=
F_124 ( V_245 , V_113 ) )
return - V_131 ;
}
return 0 ;
}
static int
F_127 (
struct V_1 * V_2 )
{
int error ;
error = F_61 ( F_9 ( V_2 ) -> V_151 ) ;
if ( error )
return error ;
F_107 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_151 -> V_181 )
return - V_131 ;
return 0 ;
}
STATIC int
F_128 (
struct V_218 * * V_247 ,
struct V_1 * V_2 ,
struct V_1 * V_245 )
{
struct V_53 V_248 ;
struct V_53 V_249 ;
struct V_53 V_250 ;
T_9 V_251 ;
T_9 V_186 ;
T_23 V_6 ;
T_2 V_200 ;
struct V_173 V_174 ;
int error ;
T_23 V_252 ;
T_23 V_253 ;
int V_171 ;
T_26 V_254 ;
V_254 = V_245 -> V_43 . V_255 ;
if ( V_2 -> V_43 . V_255 & V_256 )
V_245 -> V_43 . V_255 |= V_256 ;
V_251 = 0 ;
V_186 = F_47 ( V_2 -> V_4 , F_129 ( F_9 ( V_2 ) ) ) ;
V_6 = ( T_23 ) ( V_186 - V_251 ) ;
while ( V_6 ) {
V_171 = 1 ;
error = F_67 ( V_245 , V_251 , V_6 , & V_250 ,
& V_171 , 0 ) ;
if ( error )
goto V_89;
ASSERT ( V_171 == 1 ) ;
ASSERT ( V_250 . V_111 != V_101 ) ;
F_130 ( V_245 , & V_250 ) ;
V_252 = V_250 . V_56 ;
while ( V_250 . V_56 ) {
F_75 ( & V_174 , & V_200 ) ;
F_131 ( V_245 , & V_250 ) ;
V_171 = 1 ;
error = F_67 ( V_2 , V_250 . V_55 ,
V_250 . V_56 , & V_248 ,
& V_171 , 0 ) ;
if ( error )
goto V_257;
ASSERT ( V_171 == 1 ) ;
ASSERT ( V_250 . V_55 == V_248 . V_55 ) ;
F_131 ( V_2 , & V_248 ) ;
V_249 = V_250 ;
V_249 . V_56 = V_253 = F_92 ( T_23 ,
V_250 . V_56 ,
V_248 . V_56 ) ;
F_131 ( V_245 , & V_249 ) ;
error = F_132 ( ( * V_247 ) -> V_258 , & V_174 ,
V_245 , & V_249 ) ;
if ( error )
goto V_257;
error = F_132 ( ( * V_247 ) -> V_258 , & V_174 ,
V_2 , & V_248 ) ;
if ( error )
goto V_257;
error = F_133 ( ( * V_247 ) -> V_258 , & V_174 ,
V_2 , & V_249 ) ;
if ( error )
goto V_257;
error = F_133 ( ( * V_247 ) -> V_258 , & V_174 ,
V_245 , & V_248 ) ;
if ( error )
goto V_257;
error = F_96 ( V_247 , & V_174 , V_2 ) ;
if ( error )
goto V_257;
V_250 . V_55 += V_253 ;
if ( V_250 . V_111 != V_97 &&
V_250 . V_111 != V_101 )
V_250 . V_111 += V_253 ;
V_250 . V_56 -= V_253 ;
}
V_6 -= V_252 ;
V_251 += V_252 ;
}
V_245 -> V_43 . V_255 = V_254 ;
return 0 ;
V_257:
F_97 ( & V_174 ) ;
V_89:
F_134 ( V_2 , error , V_259 ) ;
V_245 -> V_43 . V_255 = V_254 ;
return error ;
}
STATIC int
F_135 (
struct V_218 * V_33 ,
struct V_1 * V_2 ,
struct V_1 * V_245 ,
int * V_260 ,
int * V_261 )
{
struct V_262 V_263 , * V_57 , * V_264 ;
int V_265 = 0 ;
int V_266 = 0 ;
T_11 V_267 ;
T_26 V_268 ;
int error ;
if ( ( ( F_57 ( V_2 ) != 0 ) && ( V_2 -> V_43 . V_269 > 0 ) ) &&
( V_2 -> V_43 . V_135 != V_137 ) ) {
error = F_39 ( V_33 , V_2 , V_133 ,
& V_265 ) ;
if ( error )
return error ;
}
if ( ( ( F_57 ( V_245 ) != 0 ) && ( V_245 -> V_43 . V_269 > 0 ) ) &&
( V_245 -> V_43 . V_135 != V_137 ) ) {
error = F_39 ( V_33 , V_245 , V_133 ,
& V_266 ) ;
if ( error )
return error ;
}
if ( V_2 -> V_43 . V_270 == 3 &&
V_2 -> V_43 . V_140 == V_136 ) {
( * V_261 ) |= V_271 ;
error = F_136 ( V_33 , V_2 , V_113 ,
V_245 -> V_176 , NULL ) ;
if ( error )
return error ;
}
if ( V_245 -> V_43 . V_270 == 3 &&
V_245 -> V_43 . V_140 == V_136 ) {
( * V_260 ) |= V_271 ;
error = F_136 ( V_33 , V_245 , V_113 ,
V_2 -> V_176 , NULL ) ;
if ( error )
return error ;
}
V_57 = & V_2 -> V_182 ;
V_264 = & V_245 -> V_182 ;
V_263 = * V_57 ;
* V_57 = * V_264 ;
* V_264 = V_263 ;
V_268 = ( T_26 ) V_2 -> V_43 . V_44 ;
V_2 -> V_43 . V_44 = V_245 -> V_43 . V_44 - V_266 + V_265 ;
V_245 -> V_43 . V_44 = V_268 + V_266 - V_265 ;
V_268 = ( T_26 ) V_2 -> V_43 . V_246 ;
V_2 -> V_43 . V_246 = V_245 -> V_43 . V_246 ;
V_245 -> V_43 . V_246 = V_268 ;
V_268 = ( T_26 ) V_2 -> V_43 . V_140 ;
V_2 -> V_43 . V_140 = V_245 -> V_43 . V_140 ;
V_245 -> V_43 . V_140 = V_268 ;
ASSERT ( V_245 -> V_46 == 0 ) ;
V_245 -> V_46 = V_2 -> V_46 ;
V_2 -> V_46 = 0 ;
switch ( V_2 -> V_43 . V_140 ) {
case V_82 :
V_267 = F_42 ( & V_2 -> V_182 ) ;
if ( V_267 <= V_272 )
V_57 -> V_273 . V_274 = V_57 -> V_275 . V_276 ;
( * V_260 ) |= V_277 ;
break;
case V_136 :
ASSERT ( V_2 -> V_43 . V_270 < 3 ||
( * V_260 & V_271 ) ) ;
( * V_260 ) |= V_278 ;
break;
}
switch ( V_245 -> V_43 . V_140 ) {
case V_82 :
V_267 = F_42 ( & V_245 -> V_182 ) ;
if ( V_267 <= V_272 )
V_264 -> V_273 . V_274 = V_264 -> V_275 . V_276 ;
( * V_261 ) |= V_277 ;
break;
case V_136 :
( * V_261 ) |= V_278 ;
ASSERT ( V_245 -> V_43 . V_270 < 3 ||
( * V_261 & V_271 ) ) ;
break;
}
return 0 ;
}
int
F_137 (
struct V_1 * V_2 ,
struct V_1 * V_245 ,
struct V_279 * V_280 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_218 * V_33 ;
struct V_281 * V_282 = & V_280 -> V_283 ;
int V_260 , V_261 ;
int error = 0 ;
int V_284 ;
struct V_262 * V_285 ;
T_26 V_286 ;
int V_206 ;
F_138 ( F_9 ( V_2 ) , F_9 ( V_245 ) ) ;
V_284 = V_287 ;
F_139 ( V_2 , V_245 , V_287 ) ;
if ( ( F_9 ( V_2 ) -> V_179 & V_288 ) != ( F_9 ( V_245 ) -> V_179 & V_288 ) ) {
error = - V_131 ;
goto V_224;
}
if ( F_2 ( V_2 ) != F_2 ( V_245 ) ) {
error = - V_131 ;
goto V_224;
}
error = F_127 ( V_2 ) ;
if ( error )
goto V_224;
error = F_127 ( V_245 ) ;
if ( error )
goto V_224;
if ( F_123 ( & V_8 -> V_21 ) ) {
V_206 = F_140 ( V_8 ,
F_64 ( V_2 , V_113 ) ,
V_113 ) +
F_140 ( V_8 ,
F_64 ( V_245 , V_113 ) ,
V_113 ) ;
error = F_83 ( V_8 , & F_84 ( V_8 ) -> V_213 , V_206 ,
0 , 0 , & V_33 ) ;
} else
error = F_83 ( V_8 , & F_84 ( V_8 ) -> V_289 , 0 ,
0 , 0 , & V_33 ) ;
if ( error )
goto V_224;
F_139 ( V_2 , V_245 , V_31 ) ;
V_284 |= V_31 ;
F_15 ( V_33 , V_2 , 0 ) ;
F_15 ( V_33 , V_245 , 0 ) ;
if ( V_280 -> V_290 != 0 ||
V_280 -> V_291 != V_2 -> V_43 . V_150 ||
V_280 -> V_291 != V_245 -> V_43 . V_150 ) {
error = - V_292 ;
goto V_222;
}
F_141 ( V_2 , 0 ) ;
F_141 ( V_245 , 1 ) ;
error = F_122 ( V_2 , V_245 ) ;
if ( error ) {
F_142 ( V_8 ,
L_5 ,
V_293 , V_2 -> V_176 ) ;
goto V_222;
}
if ( ( V_282 -> V_294 . V_295 != F_9 ( V_2 ) -> V_296 . V_295 ) ||
( V_282 -> V_294 . V_297 != F_9 ( V_2 ) -> V_296 . V_297 ) ||
( V_282 -> V_298 . V_295 != F_9 ( V_2 ) -> V_299 . V_295 ) ||
( V_282 -> V_298 . V_297 != F_9 ( V_2 ) -> V_299 . V_297 ) ) {
error = - V_300 ;
goto V_222;
}
V_260 = V_45 ;
V_261 = V_45 ;
if ( F_123 ( & V_8 -> V_21 ) )
error = F_128 ( & V_33 , V_2 , V_245 ) ;
else
error = F_135 ( V_33 , V_2 , V_245 , & V_260 ,
& V_261 ) ;
if ( error )
goto V_222;
if ( ( V_2 -> V_43 . V_255 & V_256 ) ^
( V_245 -> V_43 . V_255 & V_256 ) ) {
V_286 = V_2 -> V_43 . V_255 & V_256 ;
V_2 -> V_43 . V_255 &= ~ V_256 ;
V_2 -> V_43 . V_255 |= V_245 -> V_43 . V_255 & V_256 ;
V_245 -> V_43 . V_255 &= ~ V_256 ;
V_245 -> V_43 . V_255 |= V_286 & V_256 ;
V_285 = V_2 -> V_301 ;
V_2 -> V_301 = V_245 -> V_301 ;
V_245 -> V_301 = V_285 ;
F_143 ( V_2 ) ;
F_143 ( V_245 ) ;
}
F_20 ( V_33 , V_2 , V_260 ) ;
F_20 ( V_33 , V_245 , V_261 ) ;
if ( V_8 -> V_302 & V_303 )
F_144 ( V_33 ) ;
error = F_87 ( V_33 ) ;
F_145 ( V_2 , 0 ) ;
F_145 ( V_245 , 1 ) ;
V_224:
F_69 ( V_2 , V_284 ) ;
F_69 ( V_245 , V_284 ) ;
F_146 ( F_9 ( V_2 ) , F_9 ( V_245 ) ) ;
return error ;
V_222:
F_86 ( V_33 ) ;
goto V_224;
}
