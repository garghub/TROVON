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
V_13 , 0 ) ;
}
int
F_10 (
struct V_14 * V_15 )
{
int error ;
T_5 * V_8 ;
T_6 V_16 = 0 ;
T_6 V_17 = 0 ;
T_6 V_18 ;
T_7 V_19 ;
V_8 = V_15 -> V_2 -> V_4 ;
V_18 = F_11 ( V_15 -> V_2 ) ;
V_16 = V_18 / V_8 -> V_20 . V_21 ;
error = F_12 ( V_8 , & V_15 -> V_22 , & V_15 -> V_23 ,
V_18 , 1 , V_15 -> V_24 , 0 ,
V_15 -> V_25 , & V_15 -> V_26 , & V_15 -> V_27 ) ;
if ( error )
return error ;
ASSERT ( V_15 -> V_27 ) ;
ASSERT ( V_15 -> V_27 % V_8 -> V_20 . V_21 == 0 ) ;
if ( F_13 ( V_15 -> V_26 , V_18 ) || V_15 -> V_27 % V_18 )
V_16 = 1 ;
V_17 = V_15 -> V_27 / V_8 -> V_20 . V_21 ;
if ( V_17 * V_8 -> V_20 . V_21 >= V_28 )
V_17 = V_28 / V_8 -> V_20 . V_21 ;
F_14 ( V_8 -> V_29 , V_30 | V_31 ) ;
F_15 ( V_15 -> V_32 , V_8 -> V_29 , V_30 ) ;
F_14 ( V_8 -> V_33 , V_30 | V_34 ) ;
F_15 ( V_15 -> V_32 , V_8 -> V_33 , V_30 ) ;
if ( V_15 -> V_24 && V_15 -> V_26 == 0 ) {
T_7 V_35 ( V_36 ) ;
error = F_16 ( V_8 , V_15 -> V_32 , V_17 , & V_36 ) ;
if ( error )
return error ;
V_15 -> V_37 = V_36 * V_8 -> V_20 . V_21 ;
} else {
V_15 -> V_37 = 0 ;
}
F_17 ( V_15 ) ;
F_18 ( V_15 -> V_37 , V_8 -> V_20 . V_21 ) ;
V_19 = V_15 -> V_37 ;
V_15 -> V_27 = V_17 ;
error = F_19 ( V_15 -> V_32 , V_15 -> V_37 , 1 , V_15 -> V_27 ,
& V_17 , V_15 -> V_38 , V_16 , & V_19 ) ;
if ( error )
return error ;
V_15 -> V_37 = V_19 ;
if ( V_15 -> V_37 != V_39 ) {
V_15 -> V_37 *= V_8 -> V_20 . V_21 ;
V_17 *= V_8 -> V_20 . V_21 ;
V_15 -> V_27 = V_17 ;
V_15 -> V_2 -> V_40 . V_41 += V_17 ;
F_20 ( V_15 -> V_32 , V_15 -> V_2 , V_42 ) ;
if ( V_15 -> V_38 )
V_15 -> V_2 -> V_43 -= V_17 ;
F_21 ( V_15 -> V_32 , V_15 -> V_2 ,
V_15 -> V_38 ? V_44 :
V_45 , ( long ) V_17 ) ;
if ( V_15 -> V_46 & V_47 ) {
error = F_5 ( V_15 -> V_2 , V_15 -> V_37 , V_15 -> V_27 ) ;
if ( error )
return error ;
}
} else {
V_15 -> V_27 = 0 ;
}
return 0 ;
}
int
F_22 (
struct V_1 * V_2 ,
T_8 V_48 ,
int V_49 ,
int * V_24 )
{
struct V_50 V_51 ;
int error ;
error = F_23 ( NULL , V_2 , V_49 , & V_51 , V_24 ) ;
if ( error || * V_24 )
return error ;
* V_24 = V_48 >= V_51 . V_52 + V_51 . V_53 ;
return 0 ;
}
T_9
F_24 (
struct V_54 * V_55 ,
T_10 * V_56 )
{
struct V_50 V_22 ;
T_9 V_57 = 0 , V_58 = 0 ;
while ( F_25 ( V_55 , V_58 ++ , & V_22 ) ) {
if ( ! F_26 ( V_22 . V_59 ) ) {
* V_56 += V_22 . V_53 ;
V_57 ++ ;
}
}
return V_57 ;
}
STATIC void
F_27 (
struct V_7 * V_8 ,
struct V_60 * V_10 ,
int V_57 ,
T_10 * V_56 )
{
int V_61 ;
T_11 * V_62 ;
for ( V_61 = 1 ; V_61 <= V_57 ; V_61 ++ ) {
V_62 = F_28 ( V_8 , V_10 , V_61 ) ;
* V_56 += F_29 ( V_62 ) ;
}
}
STATIC int
F_30 (
struct V_7 * V_8 ,
struct V_63 * V_32 ,
struct V_54 * V_55 ,
T_2 V_64 ,
int V_65 ,
T_9 * V_66 ,
T_10 * V_56 )
{
int error ;
struct V_67 * V_68 , * V_69 ;
int V_70 = V_65 ;
T_12 * V_71 ;
T_2 V_72 = V_64 ;
T_2 V_73 ;
struct V_60 * V_10 , * V_74 ;
int V_57 ;
error = F_31 ( V_8 , V_32 , V_72 , 0 , & V_68 , V_75 ,
& V_76 ) ;
if ( error )
return error ;
* V_56 += 1 ;
V_10 = F_32 ( V_68 ) ;
if ( -- V_70 ) {
V_73 = F_33 ( V_10 -> V_77 . V_78 . V_79 ) ;
while ( V_73 != V_39 ) {
error = F_31 ( V_8 , V_32 , V_73 , 0 , & V_69 ,
V_75 ,
& V_76 ) ;
if ( error )
return error ;
* V_56 += 1 ;
V_74 = F_32 ( V_69 ) ;
V_73 = F_33 ( V_74 -> V_77 . V_78 . V_79 ) ;
F_34 ( V_32 , V_69 ) ;
}
V_71 = F_35 ( V_8 , V_10 , 1 , V_8 -> V_80 [ 1 ] ) ;
V_72 = F_33 ( * V_71 ) ;
error = F_30 ( V_8 , V_32 , V_55 , V_72 , V_70 , V_66 ,
V_56 ) ;
if ( error ) {
F_34 ( V_32 , V_68 ) ;
F_36 ( L_1 ,
V_81 , V_8 ) ;
return - V_82 ;
}
F_34 ( V_32 , V_68 ) ;
} else {
for (; ; ) {
V_73 = F_33 ( V_10 -> V_77 . V_78 . V_79 ) ;
V_57 = F_37 ( V_10 -> V_83 ) ;
( * V_66 ) += V_57 ;
F_27 ( V_8 , V_10 , V_57 , V_56 ) ;
F_34 ( V_32 , V_68 ) ;
if ( V_73 == V_39 )
break;
V_72 = V_73 ;
error = F_31 ( V_8 , V_32 , V_72 , 0 , & V_68 ,
V_75 ,
& V_76 ) ;
if ( error )
return error ;
* V_56 += 1 ;
V_10 = F_32 ( V_68 ) ;
}
}
return 0 ;
}
int
F_38 (
struct V_63 * V_32 ,
struct V_1 * V_2 ,
int V_49 ,
T_9 * V_66 ,
T_10 * V_56 )
{
struct V_7 * V_8 ;
T_12 * V_71 ;
struct V_60 * V_10 ;
struct V_54 * V_55 ;
T_2 V_72 ;
int V_70 ;
int error ;
V_72 = V_39 ;
V_8 = V_2 -> V_4 ;
* V_66 = 0 ;
* V_56 = 0 ;
V_55 = F_39 ( V_2 , V_49 ) ;
if ( ! V_55 )
return 0 ;
switch ( F_40 ( V_2 , V_49 ) ) {
case V_84 :
* V_66 = F_24 ( V_55 , V_56 ) ;
return 0 ;
case V_85 :
if ( ! ( V_55 -> V_86 & V_87 ) ) {
error = F_41 ( V_32 , V_2 , V_49 ) ;
if ( error )
return error ;
}
V_10 = V_55 -> V_88 ;
V_70 = F_37 ( V_10 -> V_89 ) ;
ASSERT ( V_70 > 0 ) ;
V_71 = F_42 ( V_8 , V_10 , 1 , V_55 -> V_90 ) ;
V_72 = F_33 ( * V_71 ) ;
ASSERT ( V_72 != V_39 ) ;
ASSERT ( F_43 ( V_8 , V_72 ) < V_8 -> V_20 . V_91 ) ;
ASSERT ( F_44 ( V_8 , V_72 ) < V_8 -> V_20 . V_92 ) ;
error = F_30 ( V_8 , V_32 , V_55 , V_72 , V_70 ,
V_66 , V_56 ) ;
if ( error ) {
F_36 ( L_2 ,
V_81 , V_8 ) ;
return - V_82 ;
}
return 0 ;
}
return 0 ;
}
STATIC int
F_45 (
T_13 * V_2 ,
int V_49 ,
struct V_93 * V_94 ,
int V_95 ,
T_14 V_96 ,
T_2 V_97 ,
bool V_98 )
{
T_14 V_99 ;
T_5 * V_8 ;
T_15 * V_55 ;
T_9 V_100 ;
T_8 V_101 ;
if ( V_97 == V_102 ) {
V_8 = V_2 -> V_4 ;
V_94 -> V_103 = - 1 ;
V_99 = F_3 ( V_8 , F_46 ( V_8 , F_47 ( V_2 ) ) ) ;
V_99 -= V_94 -> V_104 ;
if ( V_95 && V_94 -> V_104 + V_94 -> V_105 == V_96 ) {
if ( V_99 <= 0 )
return 0 ;
V_94 -> V_105 = V_99 ;
}
} else {
if ( V_97 == V_106 )
V_94 -> V_103 = - 2 ;
else
V_94 -> V_103 = F_1 ( V_2 , V_97 ) ;
V_101 = F_48 ( V_2 -> V_4 , V_94 -> V_104 ) ;
V_55 = F_39 ( V_2 , V_49 ) ;
if ( ! V_98 &&
F_49 ( V_55 , V_101 , & V_100 ) &&
( V_100 == F_50 ( V_55 ) - 1 ) )
V_94 -> V_107 |= V_108 ;
}
return 1 ;
}
STATIC int
F_51 (
struct V_1 * V_2 ,
int V_49 ,
struct V_50 * V_109 ,
struct V_93 * V_94 ,
struct V_50 * V_110 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_16 V_111 ;
T_17 V_112 ;
T_17 V_113 ;
T_6 V_114 ;
T_6 V_115 ;
int error ;
V_110 -> V_59 = V_39 ;
V_110 -> V_52 = V_116 ;
V_110 -> V_53 = 0 ;
if ( ! F_52 ( V_2 ) ||
V_49 != V_117 ||
! F_53 ( V_109 ) )
return 0 ;
V_111 = F_43 ( V_8 , V_109 -> V_59 ) ;
V_112 = F_44 ( V_8 , V_109 -> V_59 ) ;
error = F_54 ( V_8 , NULL , V_111 , V_112 ,
V_109 -> V_53 , & V_113 , & V_114 , true ) ;
if ( error )
return error ;
if ( V_113 == V_118 ) {
return 0 ;
} else if ( V_112 == V_113 ) {
V_94 -> V_105 = F_3 ( V_8 , V_114 ) ;
V_94 -> V_107 |= V_119 ;
if ( V_114 != V_109 -> V_53 ) {
* V_110 = * V_109 ;
V_110 -> V_59 += V_114 ;
V_110 -> V_52 += V_114 ;
V_110 -> V_53 -= V_114 ;
}
V_109 -> V_53 -= V_114 ;
} else {
* V_110 = * V_109 ;
V_115 = V_113 - V_112 ;
V_94 -> V_105 = F_3 ( V_8 , V_115 ) ;
V_110 -> V_59 += V_115 ;
V_110 -> V_52 += V_115 ;
V_110 -> V_53 -= V_115 ;
V_109 -> V_53 -= V_115 ;
}
return 0 ;
}
int
F_55 (
T_13 * V_2 ,
struct V_93 * V_120 ,
T_18 V_121 ,
void * V_122 )
{
T_14 V_123 ;
int error = 0 ;
T_14 V_99 ;
int V_58 ;
int V_124 ;
T_19 * V_109 ;
T_5 * V_8 ;
int V_125 ;
int V_126 ;
int V_127 ;
struct V_93 * V_94 ;
int V_49 ;
int V_95 ;
int V_128 ;
int V_129 ;
int V_130 = 0 ;
struct V_50 V_131 ;
V_8 = V_2 -> V_4 ;
V_128 = V_120 -> V_132 ;
#ifndef F_56
if ( V_128 & V_133 )
return - V_134 ;
#endif
if ( ( V_128 & V_135 ) && ( V_128 & V_133 ) )
return - V_134 ;
if ( V_128 & V_135 )
V_49 = V_136 ;
else if ( V_128 & V_133 )
V_49 = V_137 ;
else
V_49 = V_117 ;
switch ( V_49 ) {
case V_136 :
if ( F_57 ( V_2 ) ) {
if ( V_2 -> V_40 . V_138 != V_84 &&
V_2 -> V_40 . V_138 != V_85 &&
V_2 -> V_40 . V_138 != V_139 )
return - V_134 ;
} else if ( F_58 (
V_2 -> V_40 . V_138 != 0 &&
V_2 -> V_40 . V_138 != V_84 ) ) {
F_36 ( L_3 , V_81 ,
V_2 -> V_4 ) ;
return - V_82 ;
}
V_95 = 0 ;
V_99 = 1LL << 32 ;
break;
case V_137 :
if ( V_2 -> V_140 != V_84 )
return - V_134 ;
if ( F_59 ( V_2 ) ) {
V_95 = 1 ;
V_99 = V_8 -> V_11 -> V_141 ;
} else {
V_95 = 0 ;
V_99 = F_47 ( V_2 ) ;
}
break;
default:
if ( V_2 -> V_40 . V_142 == V_139 ) {
V_120 -> V_143 = 0 ;
return 0 ;
}
if ( V_2 -> V_40 . V_142 != V_84 &&
V_2 -> V_40 . V_142 != V_85 )
return - V_134 ;
if ( F_11 ( V_2 ) ||
V_2 -> V_40 . V_144 & ( V_145 | V_146 ) ) {
V_95 = 1 ;
V_99 = V_8 -> V_11 -> V_141 ;
} else {
V_95 = 0 ;
V_99 = F_47 ( V_2 ) ;
}
break;
}
if ( V_120 -> V_105 == - 1 ) {
V_99 = F_3 ( V_8 , F_46 ( V_8 , V_99 ) ) ;
V_120 -> V_105 =
F_60 ( T_14 , V_99 - V_120 -> V_104 , 0 ) ;
} else if ( V_120 -> V_105 == 0 ) {
V_120 -> V_143 = 0 ;
return 0 ;
} else if ( V_120 -> V_105 < 0 ) {
return - V_134 ;
}
V_125 = V_120 -> V_147 - 1 ;
if ( V_125 <= 0 )
return - V_134 ;
V_123 = V_120 -> V_104 + V_120 -> V_105 ;
if ( V_120 -> V_147 > V_148 / sizeof( struct V_93 ) )
return - V_149 ;
V_94 = F_61 ( V_120 -> V_147 * sizeof( struct V_93 ) , 0 ) ;
if ( ! V_94 )
return - V_149 ;
F_14 ( V_2 , V_150 ) ;
switch ( V_49 ) {
case V_117 :
if ( ! ( V_128 & V_151 ) &&
( V_2 -> V_43 || F_47 ( V_2 ) > V_2 -> V_40 . V_152 ) ) {
error = F_62 ( F_9 ( V_2 ) -> V_153 ) ;
if ( error )
goto V_154;
}
V_124 = F_63 ( V_2 ) ;
break;
case V_137 :
V_124 = V_155 ;
F_14 ( V_2 , V_124 ) ;
break;
case V_136 :
V_124 = F_64 ( V_2 ) ;
break;
}
if ( V_125 > F_65 ( V_2 , V_49 ) * 2 + 1 )
V_125 = F_65 ( V_2 , V_49 ) * 2 + 1 ;
V_129 = F_66 ( V_49 ) ;
if ( ! ( V_128 & V_156 ) )
V_129 |= V_157 ;
error = - V_149 ;
V_126 = 16 ;
V_109 = F_67 ( V_126 * sizeof( * V_109 ) , V_158 | V_159 ) ;
if ( ! V_109 )
goto V_160;
V_120 -> V_143 = 0 ;
if ( F_65 ( V_2 , V_49 ) == 0 &&
( V_49 == V_136 || ! ( V_128 & V_151 ) ) ) {
error = 0 ;
goto V_161;
}
do {
V_127 = ( V_125 > V_126 ) ? V_126 : V_125 ;
error = F_68 ( V_2 , F_6 ( V_8 , V_120 -> V_104 ) ,
F_48 ( V_8 , V_120 -> V_105 ) ,
V_109 , & V_127 , V_129 ) ;
if ( error )
goto V_161;
ASSERT ( V_127 <= V_126 ) ;
for ( V_58 = 0 ; V_58 < V_127 && V_120 -> V_105 &&
V_130 < V_120 -> V_147 - 1 ; V_58 ++ ) {
V_94 [ V_130 ] . V_107 = 0 ;
if ( V_109 [ V_58 ] . V_162 == V_163 )
V_94 [ V_130 ] . V_107 |= V_164 ;
else if ( V_109 [ V_58 ] . V_59 == V_106 )
V_94 [ V_130 ] . V_107 |= V_165 ;
V_94 [ V_130 ] . V_104 =
F_3 ( V_8 , V_109 [ V_58 ] . V_52 ) ;
V_94 [ V_130 ] . V_105 =
F_3 ( V_8 , V_109 [ V_58 ] . V_53 ) ;
V_94 [ V_130 ] . V_166 = 0 ;
V_94 [ V_130 ] . V_167 = 0 ;
if ( V_109 [ V_58 ] . V_59 == V_106 &&
V_109 [ V_58 ] . V_52 < F_46 ( V_8 , F_47 ( V_2 ) ) )
ASSERT ( ( V_128 & V_151 ) != 0 ) ;
if ( V_109 [ V_58 ] . V_59 == V_102 &&
V_49 == V_136 ) {
V_94 [ V_130 ] . V_107 |= V_108 ;
goto V_161;
}
error = F_51 ( V_2 , V_49 ,
& V_109 [ V_58 ] , & V_94 [ V_130 ] , & V_131 ) ;
if ( error )
goto V_161;
if ( ! F_45 ( V_2 , V_49 ,
& V_94 [ V_130 ] , V_95 , V_123 ,
V_109 [ V_58 ] . V_59 ,
V_131 . V_59 != V_39 ) )
goto V_161;
V_120 -> V_104 =
V_94 [ V_130 ] . V_104 +
V_94 [ V_130 ] . V_105 ;
V_120 -> V_105 =
F_60 ( T_14 , 0 , V_123 - V_120 -> V_104 ) ;
if ( ( V_128 & V_168 ) &&
V_109 [ V_58 ] . V_59 == V_102 ) {
memset ( & V_94 [ V_130 ] , 0 , sizeof( V_94 [ V_130 ] ) ) ;
continue;
}
if ( V_131 . V_59 != V_39 ) {
V_109 [ V_58 ] = V_131 ;
V_58 -- ;
}
V_120 -> V_143 ++ ;
V_130 ++ ;
}
} while ( V_127 && V_120 -> V_105 && V_130 < V_120 -> V_147 - 1 );
V_161:
F_69 ( V_109 ) ;
V_160:
F_70 ( V_2 , V_124 ) ;
V_154:
F_70 ( V_2 , V_150 ) ;
for ( V_58 = 0 ; V_58 < V_130 ; V_58 ++ ) {
error = V_121 ( & V_122 , & V_94 [ V_58 ] ) ;
if ( error )
break;
}
F_69 ( V_94 ) ;
return error ;
}
int
F_71 (
struct V_1 * V_2 ,
T_8 V_5 ,
T_8 V_27 )
{
T_8 V_169 = V_27 ;
int error = 0 ;
ASSERT ( F_72 ( V_2 , V_30 ) ) ;
do {
int V_170 ;
T_19 V_171 ;
int V_172 = 1 ;
T_2 V_173 ;
struct V_174 V_175 ;
error = F_68 ( V_2 , V_5 , 1 , & V_171 , & V_172 ,
V_176 ) ;
if ( error ) {
if ( ! F_73 ( V_2 -> V_4 ) ) {
F_74 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_177 , V_5 ) ;
}
break;
}
if ( ! V_172 ) {
goto V_178;
}
if ( V_171 . V_59 != V_106 ) {
goto V_178;
}
F_75 ( V_171 . V_53 == 0 ) ;
F_76 ( & V_175 , & V_173 ) ;
error = F_77 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_173 ,
& V_175 , & V_170 ) ;
if ( error )
break;
ASSERT ( ! F_78 ( & V_175 ) ) ;
V_178:
V_5 ++ ;
V_169 -- ;
} while( V_169 > 0 );
return error ;
}
bool
F_79 ( struct V_1 * V_2 , bool V_179 )
{
if ( ! F_80 ( F_9 ( V_2 ) -> V_180 ) )
return false ;
if ( F_9 ( V_2 ) -> V_181 == 0 &&
F_9 ( V_2 ) -> V_153 -> V_182 == 0 &&
V_2 -> V_43 == 0 )
return false ;
if ( ! ( V_2 -> V_183 . V_86 & V_87 ) )
return false ;
if ( V_2 -> V_40 . V_144 & ( V_145 | V_146 ) )
if ( ! V_179 || V_2 -> V_43 == 0 )
return false ;
return true ;
}
int
F_81 (
struct V_1 * V_2 )
{
struct V_63 * V_32 ;
int error ;
T_8 V_184 ;
T_8 V_185 ;
T_10 V_186 ;
int V_172 ;
struct V_50 V_171 ;
struct V_7 * V_8 = V_2 -> V_4 ;
V_184 = F_46 ( V_8 , ( V_187 ) F_47 ( V_2 ) ) ;
V_185 = F_46 ( V_8 , V_8 -> V_11 -> V_141 ) ;
if ( V_185 <= V_184 )
return 0 ;
V_186 = V_185 - V_184 ;
V_172 = 1 ;
F_14 ( V_2 , V_155 ) ;
error = F_68 ( V_2 , V_184 , V_186 , & V_171 , & V_172 , 0 ) ;
F_70 ( V_2 , V_155 ) ;
if ( ! error && ( V_172 != 0 ) &&
( V_171 . V_59 != V_102 ||
V_2 -> V_43 ) ) {
error = F_82 ( V_2 , 0 ) ;
if ( error )
return error ;
F_83 ( F_9 ( V_2 ) ) ;
error = F_84 ( V_8 , & F_85 ( V_8 ) -> V_188 , 0 , 0 , 0 ,
& V_32 ) ;
if ( error ) {
ASSERT ( F_73 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_30 ) ;
F_15 ( V_32 , V_2 , 0 ) ;
error = F_86 ( & V_32 , V_2 , V_117 ,
F_47 ( V_2 ) ) ;
if ( error ) {
F_87 ( V_32 ) ;
} else {
error = F_88 ( V_32 ) ;
if ( ! error )
F_89 ( V_2 ) ;
}
F_70 ( V_2 , V_30 ) ;
}
return error ;
}
int
F_90 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_189 ,
int V_190 )
{
T_5 * V_8 = V_2 -> V_4 ;
T_3 V_56 ;
T_10 V_191 ;
T_10 V_192 ;
T_6 V_193 , V_194 ;
T_8 V_195 ;
T_2 V_196 ;
int V_172 ;
int V_197 ;
int V_198 ;
T_20 * V_32 ;
T_19 V_199 [ 1 ] , * V_200 ;
struct V_174 V_175 ;
T_21 V_201 , V_202 , V_203 ;
int error ;
F_91 ( V_2 ) ;
if ( F_73 ( V_8 ) )
return - V_204 ;
error = F_82 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_189 <= 0 )
return - V_134 ;
V_198 = F_2 ( V_2 ) ;
V_193 = F_11 ( V_2 ) ;
V_56 = V_189 ;
V_200 = & V_199 [ 0 ] ;
V_172 = 1 ;
V_195 = F_92 ( V_8 , V_26 ) ;
V_192 = F_46 ( V_8 , V_56 ) ;
while ( V_192 && ! error ) {
T_8 V_205 , V_206 ;
if ( F_58 ( V_193 ) ) {
V_205 = V_195 ;
F_18 ( V_205 , V_193 ) ;
V_205 *= V_193 ;
V_206 = V_195 + V_192 ;
if ( ( V_194 = F_13 ( V_195 , V_193 ) ) )
V_206 += V_194 ;
if ( ( V_194 = F_13 ( V_206 , V_193 ) ) )
V_206 += V_193 - V_194 ;
} else {
V_205 = 0 ;
V_206 = V_192 ;
}
V_202 = F_93 ( T_8 , ( V_206 - V_205 ) , ( V_28 * V_172 ) ) ;
if ( F_58 ( V_198 ) ) {
V_203 = V_201 = V_202 ;
V_203 /= V_8 -> V_20 . V_21 ;
V_202 = F_94 ( V_8 , 0 ) ;
V_197 = V_207 ;
} else {
V_203 = 0 ;
V_202 = V_201 = F_94 ( V_8 , V_202 ) ;
V_197 = V_208 ;
}
error = F_84 ( V_8 , & F_85 ( V_8 ) -> V_209 , V_202 ,
V_203 , 0 , & V_32 ) ;
if ( error ) {
ASSERT ( error == - V_210 || F_73 ( V_8 ) ) ;
break;
}
F_14 ( V_2 , V_30 ) ;
error = F_95 ( V_32 , V_2 , V_201 ,
0 , V_197 ) ;
if ( error )
goto V_211;
F_15 ( V_32 , V_2 , 0 ) ;
F_76 ( & V_175 , & V_196 ) ;
error = F_96 ( V_32 , V_2 , V_195 ,
V_192 , V_190 , & V_196 ,
V_202 , V_200 , & V_172 , & V_175 ) ;
if ( error )
goto V_212;
error = F_97 ( & V_32 , & V_175 ) ;
if ( error )
goto V_212;
error = F_88 ( V_32 ) ;
F_70 ( V_2 , V_30 ) ;
if ( error )
break;
V_191 = V_200 -> V_53 ;
if ( V_172 == 0 ) {
error = - V_210 ;
break;
}
V_195 += V_191 ;
V_192 -= V_191 ;
}
return error ;
V_212:
F_98 ( & V_175 ) ;
F_99 ( V_32 , V_2 , ( long ) V_201 , 0 , V_197 ) ;
V_211:
F_87 ( V_32 ) ;
F_70 ( V_2 , V_30 ) ;
return error ;
}
static int
F_100 (
struct V_1 * V_2 ,
T_8 V_195 ,
T_10 V_213 ,
int * V_170 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_63 * V_32 ;
struct V_174 V_175 ;
T_2 V_196 ;
T_21 V_202 = F_94 ( V_8 , 0 ) ;
int error ;
error = F_84 ( V_8 , & F_85 ( V_8 ) -> V_209 , V_202 , 0 , 0 , & V_32 ) ;
if ( error ) {
ASSERT ( error == - V_210 || F_73 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_30 ) ;
error = F_101 ( V_32 , V_8 , V_2 -> V_214 , V_2 -> V_215 ,
V_2 -> V_216 , V_202 , 0 , V_208 ) ;
if ( error )
goto V_217;
F_15 ( V_32 , V_2 , 0 ) ;
F_76 ( & V_175 , & V_196 ) ;
error = F_77 ( V_32 , V_2 , V_195 , V_213 , 0 , 2 , & V_196 ,
& V_175 , V_170 ) ;
if ( error )
goto V_218;
F_102 ( & V_175 , V_2 ) ;
error = F_97 ( & V_32 , & V_175 ) ;
if ( error )
goto V_218;
error = F_88 ( V_32 ) ;
V_219:
F_70 ( V_2 , V_30 ) ;
return error ;
V_218:
F_98 ( & V_175 ) ;
V_217:
F_87 ( V_32 ) ;
goto V_219;
}
static int
F_103 (
struct V_1 * V_2 ,
T_8 * V_195 ,
T_8 * V_220 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_50 V_171 ;
int V_221 , error ;
T_6 V_222 = 0 ;
V_221 = 1 ;
error = F_68 ( V_2 , * V_195 , 1 , & V_171 , & V_221 , 0 ) ;
if ( error )
return error ;
if ( V_221 && V_171 . V_59 != V_102 ) {
ASSERT ( V_171 . V_59 != V_106 ) ;
V_222 = F_13 ( V_171 . V_59 , V_8 -> V_20 . V_21 ) ;
if ( V_222 )
* V_195 += V_8 -> V_20 . V_21 - V_222 ;
}
V_221 = 1 ;
error = F_68 ( V_2 , * V_220 - 1 , 1 , & V_171 , & V_221 , 0 ) ;
if ( error )
return error ;
if ( V_221 && V_171 . V_59 != V_102 ) {
ASSERT ( V_171 . V_59 != V_106 ) ;
V_222 ++ ;
if ( V_222 && V_222 != V_8 -> V_20 . V_21 )
* V_220 -= V_222 ;
}
return 0 ;
}
static int
F_104 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_189 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_223 * V_223 = F_9 ( V_2 ) ;
T_3 V_224 , V_225 , V_96 ;
int error ;
F_83 ( V_223 ) ;
V_224 = F_60 ( T_3 , 1 << V_8 -> V_20 . V_226 , V_227 ) ;
V_225 = F_105 ( V_26 , V_224 ) ;
V_96 = F_106 ( V_26 + V_189 , V_224 ) - 1 ;
error = F_107 ( V_223 -> V_153 , V_225 , V_96 ) ;
if ( error )
return error ;
F_108 ( V_223 , V_225 , V_96 ) ;
return 0 ;
}
int
F_109 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_189 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_8 V_195 ;
T_8 V_220 ;
int V_170 = 0 , error ;
F_110 ( V_2 ) ;
error = F_82 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_189 <= 0 )
return 0 ;
error = F_104 ( V_2 , V_26 , V_189 ) ;
if ( error )
return error ;
V_195 = F_46 ( V_8 , V_26 ) ;
V_220 = F_92 ( V_8 , V_26 + V_189 ) ;
if ( F_2 ( V_2 ) &&
! F_111 ( & V_8 -> V_20 ) ) {
error = F_103 ( V_2 , & V_195 ,
& V_220 ) ;
if ( error )
return error ;
}
if ( V_220 > V_195 ) {
while ( ! V_170 ) {
error = F_100 ( V_2 , V_195 ,
V_220 - V_195 , & V_170 ) ;
if ( error )
return error ;
}
}
if ( V_26 >= F_47 ( V_2 ) )
return 0 ;
if ( V_26 + V_189 > F_47 ( V_2 ) )
V_189 = F_47 ( V_2 ) - V_26 ;
return F_112 ( V_2 , V_26 , V_189 , NULL ) ;
}
int
F_113 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_189 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_21 V_228 ;
int error ;
F_114 ( V_2 ) ;
V_228 = 1 << V_8 -> V_20 . V_226 ;
error = F_109 ( V_2 , V_26 , V_189 ) ;
if ( error )
goto V_94;
error = F_90 ( V_2 , F_105 ( V_26 , V_228 ) ,
F_106 ( V_26 + V_189 , V_228 ) -
F_105 ( V_26 , V_228 ) ,
V_229 ) ;
V_94:
return error ;
}
static int
F_115 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_189 ,
enum V_230 V_231 )
{
int V_170 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_63 * V_32 ;
int error ;
struct V_174 V_175 ;
T_2 V_232 ;
T_8 V_233 ;
T_8 V_234 ;
T_8 V_235 ;
T_21 V_202 ;
ASSERT ( V_231 == V_236 || V_231 == V_237 ) ;
if ( V_231 == V_236 ) {
V_202 = F_94 ( V_8 , 0 ) ;
V_234 = F_46 ( V_8 , V_26 + V_189 ) ;
V_233 = F_46 ( V_8 , F_9 ( V_2 ) -> V_181 ) ;
} else {
V_202 = 0 ;
V_234 = V_39 ;
V_233 = F_46 ( V_8 , V_26 ) ;
}
V_235 = F_46 ( V_8 , V_189 ) ;
if ( F_79 ( V_2 , true ) ) {
error = F_81 ( V_2 ) ;
if ( error )
return error ;
}
error = F_107 ( F_9 ( V_2 ) -> V_153 ,
V_26 , - 1 ) ;
if ( error )
return error ;
error = F_116 ( F_9 ( V_2 ) -> V_153 ,
V_26 >> V_238 , - 1 ) ;
if ( error )
return error ;
if ( F_52 ( V_2 ) ) {
error = F_117 ( V_2 , V_26 , V_116 ,
true ) ;
if ( error )
return error ;
}
if ( V_231 == V_237 ) {
error = F_118 ( V_2 , V_233 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_170 ) {
error = F_84 ( V_8 , & F_85 ( V_8 ) -> V_209 , V_202 , 0 , 0 ,
& V_32 ) ;
if ( error )
break;
F_14 ( V_2 , V_30 ) ;
error = F_101 ( V_32 , V_8 , V_2 -> V_214 ,
V_2 -> V_215 , V_2 -> V_216 , V_202 , 0 ,
V_208 ) ;
if ( error )
goto V_217;
F_15 ( V_32 , V_2 , V_30 ) ;
F_76 ( & V_175 , & V_232 ) ;
error = F_119 ( V_32 , V_2 , & V_234 , V_235 ,
& V_170 , V_233 , & V_232 , & V_175 ,
V_231 , V_239 ) ;
if ( error )
goto V_218;
error = F_97 ( & V_32 , & V_175 ) ;
if ( error )
goto V_218;
error = F_88 ( V_32 ) ;
}
return error ;
V_218:
F_98 ( & V_175 ) ;
V_217:
F_87 ( V_32 ) ;
return error ;
}
int
F_120 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_189 )
{
int error ;
ASSERT ( F_72 ( V_2 , V_240 ) ) ;
F_121 ( V_2 ) ;
error = F_109 ( V_2 , V_26 , V_189 ) ;
if ( error )
return error ;
return F_115 ( V_2 , V_26 , V_189 , V_236 ) ;
}
int
F_122 (
struct V_1 * V_2 ,
T_22 V_26 ,
T_22 V_189 )
{
ASSERT ( F_72 ( V_2 , V_240 ) ) ;
F_123 ( V_2 ) ;
return F_115 ( V_2 , V_26 , V_189 , V_237 ) ;
}
static int
F_124 (
struct V_1 * V_2 ,
struct V_1 * V_241 )
{
if ( V_2 -> V_40 . V_142 == V_139 ||
V_241 -> V_40 . V_142 == V_139 )
return - V_134 ;
if ( V_2 -> V_40 . V_242 < V_241 -> V_40 . V_242 )
return - V_134 ;
if ( F_125 ( & V_2 -> V_4 -> V_20 ) )
return 0 ;
if ( V_2 -> V_40 . V_142 == V_84 &&
V_241 -> V_40 . V_142 == V_85 )
return - V_134 ;
if ( V_241 -> V_40 . V_142 == V_84 &&
F_65 ( V_241 , V_117 ) >
F_126 ( V_2 , V_117 ) )
return - V_134 ;
if ( V_2 -> V_40 . V_142 == V_84 &&
F_65 ( V_2 , V_117 ) >
F_126 ( V_241 , V_117 ) )
return - V_134 ;
if ( V_241 -> V_40 . V_142 == V_85 ) {
if ( F_57 ( V_2 ) &&
F_127 ( V_241 -> V_183 . V_88 ) > F_128 ( V_2 ) )
return - V_134 ;
if ( F_65 ( V_241 , V_117 ) <=
F_126 ( V_2 , V_117 ) )
return - V_134 ;
}
if ( V_2 -> V_40 . V_142 == V_85 ) {
if ( F_57 ( V_241 ) &&
F_127 ( V_2 -> V_183 . V_88 ) > F_128 ( V_241 ) )
return - V_134 ;
if ( F_65 ( V_2 , V_117 ) <=
F_126 ( V_241 , V_117 ) )
return - V_134 ;
}
return 0 ;
}
static int
F_129 (
struct V_1 * V_2 )
{
int error ;
error = F_62 ( F_9 ( V_2 ) -> V_153 ) ;
if ( error )
return error ;
F_108 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_153 -> V_182 )
return - V_134 ;
return 0 ;
}
STATIC int
F_130 (
struct V_63 * * V_243 ,
struct V_1 * V_2 ,
struct V_1 * V_241 )
{
struct V_50 V_244 ;
struct V_50 V_245 ;
struct V_50 V_246 ;
T_8 V_247 ;
T_8 V_184 ;
T_10 V_6 ;
T_2 V_196 ;
struct V_174 V_175 ;
int error ;
T_10 V_248 ;
T_10 V_249 ;
int V_172 ;
T_23 V_250 ;
V_250 = V_241 -> V_40 . V_251 ;
if ( V_2 -> V_40 . V_251 & V_252 )
V_241 -> V_40 . V_251 |= V_252 ;
V_247 = 0 ;
V_184 = F_46 ( V_2 -> V_4 , F_131 ( F_9 ( V_2 ) ) ) ;
V_6 = ( T_10 ) ( V_184 - V_247 ) ;
while ( V_6 ) {
V_172 = 1 ;
error = F_68 ( V_241 , V_247 , V_6 , & V_246 ,
& V_172 , 0 ) ;
if ( error )
goto V_94;
ASSERT ( V_172 == 1 ) ;
ASSERT ( V_246 . V_59 != V_106 ) ;
F_132 ( V_241 , & V_246 ) ;
V_248 = V_246 . V_53 ;
while ( V_246 . V_53 ) {
F_76 ( & V_175 , & V_196 ) ;
F_133 ( V_241 , & V_246 ) ;
V_172 = 1 ;
error = F_68 ( V_2 , V_246 . V_52 ,
V_246 . V_53 , & V_244 ,
& V_172 , 0 ) ;
if ( error )
goto V_253;
ASSERT ( V_172 == 1 ) ;
ASSERT ( V_246 . V_52 == V_244 . V_52 ) ;
F_133 ( V_2 , & V_244 ) ;
V_245 = V_246 ;
V_245 . V_53 = V_249 = F_93 ( T_10 ,
V_246 . V_53 ,
V_244 . V_53 ) ;
F_133 ( V_241 , & V_245 ) ;
error = F_134 ( ( * V_243 ) -> V_254 , & V_175 ,
V_241 , & V_245 ) ;
if ( error )
goto V_253;
error = F_134 ( ( * V_243 ) -> V_254 , & V_175 ,
V_2 , & V_244 ) ;
if ( error )
goto V_253;
error = F_135 ( ( * V_243 ) -> V_254 , & V_175 ,
V_2 , & V_245 ) ;
if ( error )
goto V_253;
error = F_135 ( ( * V_243 ) -> V_254 , & V_175 ,
V_241 , & V_244 ) ;
if ( error )
goto V_253;
F_102 ( & V_175 , V_2 ) ;
error = F_97 ( V_243 , & V_175 ) ;
if ( error )
goto V_253;
V_246 . V_52 += V_249 ;
if ( V_246 . V_59 != V_102 &&
V_246 . V_59 != V_106 )
V_246 . V_59 += V_249 ;
V_246 . V_53 -= V_249 ;
}
V_6 -= V_248 ;
V_247 += V_248 ;
}
V_241 -> V_40 . V_251 = V_250 ;
return 0 ;
V_253:
F_98 ( & V_175 ) ;
V_94:
F_136 ( V_2 , error , V_255 ) ;
V_241 -> V_40 . V_251 = V_250 ;
return error ;
}
STATIC int
F_137 (
struct V_63 * V_32 ,
struct V_1 * V_2 ,
struct V_1 * V_241 ,
int * V_256 ,
int * V_257 )
{
struct V_54 V_258 , * V_55 , * V_259 ;
T_10 V_260 = 0 ;
T_10 V_261 = 0 ;
T_9 V_262 ;
T_9 V_66 ;
T_23 V_263 ;
int error ;
if ( ( ( F_57 ( V_2 ) != 0 ) && ( V_2 -> V_40 . V_264 > 0 ) ) &&
( V_2 -> V_40 . V_138 != V_139 ) ) {
error = F_38 ( V_32 , V_2 , V_136 , & V_262 ,
& V_260 ) ;
if ( error )
return error ;
}
if ( ( ( F_57 ( V_241 ) != 0 ) && ( V_241 -> V_40 . V_264 > 0 ) ) &&
( V_241 -> V_40 . V_138 != V_139 ) ) {
error = F_38 ( V_32 , V_241 , V_136 , & V_262 ,
& V_261 ) ;
if ( error )
return error ;
}
if ( V_2 -> V_40 . V_265 == 3 &&
V_2 -> V_40 . V_142 == V_85 )
( * V_257 ) |= V_266 ;
if ( V_241 -> V_40 . V_265 == 3 &&
V_241 -> V_40 . V_142 == V_85 )
( * V_256 ) |= V_266 ;
V_55 = & V_2 -> V_183 ;
V_259 = & V_241 -> V_183 ;
V_258 = * V_55 ;
* V_55 = * V_259 ;
* V_259 = V_258 ;
V_263 = ( T_23 ) V_2 -> V_40 . V_41 ;
V_2 -> V_40 . V_41 = V_241 -> V_40 . V_41 - V_261 + V_260 ;
V_241 -> V_40 . V_41 = V_263 + V_261 - V_260 ;
V_263 = ( T_23 ) V_2 -> V_40 . V_242 ;
V_2 -> V_40 . V_242 = V_241 -> V_40 . V_242 ;
V_241 -> V_40 . V_242 = V_263 ;
V_263 = ( T_23 ) V_2 -> V_40 . V_142 ;
V_2 -> V_40 . V_142 = V_241 -> V_40 . V_142 ;
V_241 -> V_40 . V_142 = V_263 ;
ASSERT ( V_241 -> V_43 == 0 ) ;
V_241 -> V_43 = V_2 -> V_43 ;
V_2 -> V_43 = 0 ;
switch ( V_2 -> V_40 . V_142 ) {
case V_84 :
V_66 = F_50 ( & V_2 -> V_183 ) ;
if ( V_66 <= V_267 )
V_55 -> V_268 . V_269 = V_55 -> V_270 . V_271 ;
( * V_256 ) |= V_272 ;
break;
case V_85 :
ASSERT ( V_2 -> V_40 . V_265 < 3 ||
( * V_256 & V_266 ) ) ;
( * V_256 ) |= V_273 ;
break;
}
switch ( V_241 -> V_40 . V_142 ) {
case V_84 :
V_66 = F_50 ( & V_241 -> V_183 ) ;
if ( V_66 <= V_267 )
V_259 -> V_268 . V_269 = V_259 -> V_270 . V_271 ;
( * V_257 ) |= V_272 ;
break;
case V_85 :
( * V_257 ) |= V_273 ;
ASSERT ( V_241 -> V_40 . V_265 < 3 ||
( * V_257 & V_266 ) ) ;
break;
}
return 0 ;
}
static int
F_138 (
struct V_63 * * V_243 ,
struct V_1 * V_2 ,
struct V_1 * V_274 )
{
int error ;
struct V_63 * V_32 = * V_243 ;
do {
error = F_139 ( V_32 , V_2 , V_117 , V_2 -> V_177 ,
NULL ) ;
if ( error != - V_275 )
break;
error = F_140 ( V_243 ) ;
if ( error )
break;
V_32 = * V_243 ;
F_15 ( V_32 , V_2 , 0 ) ;
F_15 ( V_32 , V_274 , 0 ) ;
F_20 ( V_32 , V_2 , V_42 ) ;
F_20 ( V_32 , V_274 , V_42 ) ;
} while ( true );
return error ;
}
int
F_141 (
struct V_1 * V_2 ,
struct V_1 * V_241 ,
struct V_276 * V_277 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_63 * V_32 ;
struct V_278 * V_279 = & V_277 -> V_280 ;
int V_256 , V_257 ;
int error = 0 ;
int V_281 ;
struct V_54 * V_282 ;
T_23 V_283 ;
int V_202 = 0 ;
F_142 ( F_9 ( V_2 ) , F_9 ( V_241 ) ) ;
V_281 = V_284 ;
F_143 ( V_2 , V_241 , V_284 ) ;
if ( ( F_9 ( V_2 ) -> V_180 & V_285 ) != ( F_9 ( V_241 ) -> V_180 & V_285 ) ) {
error = - V_134 ;
goto V_219;
}
if ( F_2 ( V_2 ) != F_2 ( V_241 ) ) {
error = - V_134 ;
goto V_219;
}
error = F_129 ( V_2 ) ;
if ( error )
goto V_219;
error = F_129 ( V_241 ) ;
if ( error )
goto V_219;
if ( F_125 ( & V_8 -> V_20 ) ) {
V_202 = F_144 ( V_8 ,
F_65 ( V_2 , V_117 ) ,
V_117 ) +
F_144 ( V_8 ,
F_65 ( V_241 , V_117 ) ,
V_117 ) ;
}
error = F_84 ( V_8 , & F_85 ( V_8 ) -> V_209 , V_202 , 0 , 0 , & V_32 ) ;
if ( error )
goto V_219;
F_143 ( V_2 , V_241 , V_30 ) ;
V_281 |= V_30 ;
F_15 ( V_32 , V_2 , 0 ) ;
F_15 ( V_32 , V_241 , 0 ) ;
if ( V_277 -> V_286 != 0 ||
V_277 -> V_287 != V_2 -> V_40 . V_152 ||
V_277 -> V_287 != V_241 -> V_40 . V_152 ) {
error = - V_288 ;
goto V_217;
}
F_145 ( V_2 , 0 ) ;
F_145 ( V_241 , 1 ) ;
error = F_124 ( V_2 , V_241 ) ;
if ( error ) {
F_146 ( V_8 ,
L_5 ,
V_289 , V_2 -> V_177 ) ;
goto V_217;
}
if ( ( V_279 -> V_290 . V_291 != F_9 ( V_2 ) -> V_292 . V_291 ) ||
( V_279 -> V_290 . V_293 != F_9 ( V_2 ) -> V_292 . V_293 ) ||
( V_279 -> V_294 . V_291 != F_9 ( V_2 ) -> V_295 . V_291 ) ||
( V_279 -> V_294 . V_293 != F_9 ( V_2 ) -> V_295 . V_293 ) ) {
error = - V_296 ;
goto V_217;
}
V_256 = V_42 ;
V_257 = V_42 ;
if ( F_125 ( & V_8 -> V_20 ) )
error = F_130 ( & V_32 , V_2 , V_241 ) ;
else
error = F_137 ( V_32 , V_2 , V_241 , & V_256 ,
& V_257 ) ;
if ( error )
goto V_217;
if ( ( V_2 -> V_40 . V_251 & V_252 ) ^
( V_241 -> V_40 . V_251 & V_252 ) ) {
V_283 = V_2 -> V_40 . V_251 & V_252 ;
V_2 -> V_40 . V_251 &= ~ V_252 ;
V_2 -> V_40 . V_251 |= V_241 -> V_40 . V_251 & V_252 ;
V_241 -> V_40 . V_251 &= ~ V_252 ;
V_241 -> V_40 . V_251 |= V_283 & V_252 ;
}
if ( F_147 ( & V_8 -> V_20 ) ) {
T_9 V_297 ;
ASSERT ( V_2 -> V_140 == V_84 ) ;
ASSERT ( V_241 -> V_140 == V_84 ) ;
V_297 = V_2 -> V_298 ;
V_2 -> V_298 = V_241 -> V_298 ;
V_241 -> V_298 = V_297 ;
V_282 = V_2 -> V_299 ;
V_2 -> V_299 = V_241 -> V_299 ;
V_241 -> V_299 = V_282 ;
if ( V_2 -> V_299 && V_2 -> V_298 )
F_148 ( V_2 ) ;
else
F_149 ( V_2 ) ;
if ( V_241 -> V_299 && V_241 -> V_298 )
F_148 ( V_241 ) ;
else
F_149 ( V_241 ) ;
}
F_20 ( V_32 , V_2 , V_256 ) ;
F_20 ( V_32 , V_241 , V_257 ) ;
if ( V_256 & V_266 ) {
error = F_138 ( & V_32 , V_2 , V_241 ) ;
if ( error )
goto V_217;
}
if ( V_257 & V_266 ) {
error = F_138 ( & V_32 , V_241 , V_2 ) ;
if ( error )
goto V_217;
}
if ( V_8 -> V_300 & V_301 )
F_150 ( V_32 ) ;
error = F_88 ( V_32 ) ;
F_151 ( V_2 , 0 ) ;
F_151 ( V_241 , 1 ) ;
V_219:
F_70 ( V_2 , V_281 ) ;
F_70 ( V_241 , V_281 ) ;
F_152 ( F_9 ( V_2 ) , F_9 ( V_241 ) ) ;
return error ;
V_217:
F_87 ( V_32 ) ;
goto V_219;
}
