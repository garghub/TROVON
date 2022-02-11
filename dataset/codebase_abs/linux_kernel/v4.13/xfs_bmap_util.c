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
STATIC void
F_24 (
struct V_54 * V_55 ,
T_9 * V_56 ,
T_10 * V_57 )
{
T_9 V_58 ;
T_9 V_59 = F_25 ( V_55 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
T_11 * V_60 = F_26 ( V_55 , V_58 ) ;
if ( ! F_27 ( F_28 ( V_60 ) ) ) {
( * V_56 ) ++ ;
* V_57 += F_29 ( V_60 ) ;
}
}
}
STATIC void
F_30 (
struct V_7 * V_8 ,
struct V_61 * V_10 ,
int V_56 ,
T_10 * V_57 )
{
int V_62 ;
T_12 * V_60 ;
for ( V_62 = 1 ; V_62 <= V_56 ; V_62 ++ ) {
V_60 = F_31 ( V_8 , V_10 , V_62 ) ;
* V_57 += F_32 ( V_60 ) ;
}
}
STATIC int
F_33 (
struct V_7 * V_8 ,
struct V_63 * V_32 ,
struct V_54 * V_55 ,
T_2 V_64 ,
int V_65 ,
T_9 * V_66 ,
T_10 * V_57 )
{
int error ;
struct V_67 * V_68 , * V_69 ;
int V_70 = V_65 ;
T_13 * V_71 ;
T_2 V_72 = V_64 ;
T_2 V_73 ;
struct V_61 * V_10 , * V_74 ;
int V_56 ;
error = F_34 ( V_8 , V_32 , V_72 , 0 , & V_68 , V_75 ,
& V_76 ) ;
if ( error )
return error ;
* V_57 += 1 ;
V_10 = F_35 ( V_68 ) ;
if ( -- V_70 ) {
V_73 = F_36 ( V_10 -> V_77 . V_78 . V_79 ) ;
while ( V_73 != V_39 ) {
error = F_34 ( V_8 , V_32 , V_73 , 0 , & V_69 ,
V_75 ,
& V_76 ) ;
if ( error )
return error ;
* V_57 += 1 ;
V_74 = F_35 ( V_69 ) ;
V_73 = F_36 ( V_74 -> V_77 . V_78 . V_79 ) ;
F_37 ( V_32 , V_69 ) ;
}
V_71 = F_38 ( V_8 , V_10 , 1 , V_8 -> V_80 [ 1 ] ) ;
V_72 = F_36 ( * V_71 ) ;
error = F_33 ( V_8 , V_32 , V_55 , V_72 , V_70 , V_66 ,
V_57 ) ;
if ( error ) {
F_37 ( V_32 , V_68 ) ;
F_39 ( L_1 ,
V_81 , V_8 ) ;
return - V_82 ;
}
F_37 ( V_32 , V_68 ) ;
} else {
for (; ; ) {
V_73 = F_36 ( V_10 -> V_77 . V_78 . V_79 ) ;
V_56 = F_40 ( V_10 -> V_83 ) ;
( * V_66 ) += V_56 ;
F_30 ( V_8 , V_10 , V_56 , V_57 ) ;
F_37 ( V_32 , V_68 ) ;
if ( V_73 == V_39 )
break;
V_72 = V_73 ;
error = F_34 ( V_8 , V_32 , V_72 , 0 , & V_68 ,
V_75 ,
& V_76 ) ;
if ( error )
return error ;
* V_57 += 1 ;
V_10 = F_35 ( V_68 ) ;
}
}
return 0 ;
}
int
F_41 (
struct V_63 * V_32 ,
struct V_1 * V_2 ,
int V_49 ,
T_9 * V_66 ,
T_10 * V_57 )
{
struct V_7 * V_8 ;
T_13 * V_71 ;
struct V_61 * V_10 ;
struct V_54 * V_55 ;
T_2 V_72 ;
int V_70 ;
int error ;
V_72 = V_39 ;
V_8 = V_2 -> V_4 ;
* V_66 = 0 ;
* V_57 = 0 ;
V_55 = F_42 ( V_2 , V_49 ) ;
if ( ! V_55 )
return 0 ;
switch ( F_43 ( V_2 , V_49 ) ) {
case V_84 :
F_24 ( V_55 , V_66 , V_57 ) ;
return 0 ;
case V_85 :
if ( ! ( V_55 -> V_86 & V_87 ) ) {
error = F_44 ( V_32 , V_2 , V_49 ) ;
if ( error )
return error ;
}
V_10 = V_55 -> V_88 ;
V_70 = F_40 ( V_10 -> V_89 ) ;
ASSERT ( V_70 > 0 ) ;
V_71 = F_45 ( V_8 , V_10 , 1 , V_55 -> V_90 ) ;
V_72 = F_36 ( * V_71 ) ;
ASSERT ( V_72 != V_39 ) ;
ASSERT ( F_46 ( V_8 , V_72 ) < V_8 -> V_20 . V_91 ) ;
ASSERT ( F_47 ( V_8 , V_72 ) < V_8 -> V_20 . V_92 ) ;
error = F_33 ( V_8 , V_32 , V_55 , V_72 , V_70 ,
V_66 , V_57 ) ;
if ( error ) {
F_39 ( L_2 ,
V_81 , V_8 ) ;
return - V_82 ;
}
return 0 ;
}
return 0 ;
}
STATIC int
F_48 (
T_14 * V_2 ,
int V_49 ,
struct V_93 * V_94 ,
int V_95 ,
T_15 V_96 ,
T_2 V_97 ,
bool V_98 )
{
T_15 V_99 ;
T_5 * V_8 ;
T_16 * V_55 ;
T_9 V_100 ;
T_8 V_101 ;
if ( V_97 == V_102 ) {
V_8 = V_2 -> V_4 ;
V_94 -> V_103 = - 1 ;
V_99 = F_3 ( V_8 , F_49 ( V_8 , F_50 ( V_2 ) ) ) ;
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
V_101 = F_51 ( V_2 -> V_4 , V_94 -> V_104 ) ;
V_55 = F_42 ( V_2 , V_49 ) ;
if ( ! V_98 &&
F_52 ( V_55 , V_101 , & V_100 ) &&
( V_100 == F_25 ( V_55 ) - 1 ) )
V_94 -> V_107 |= V_108 ;
}
return 1 ;
}
STATIC int
F_53 (
struct V_1 * V_2 ,
int V_49 ,
struct V_50 * V_109 ,
struct V_93 * V_94 ,
struct V_50 * V_110 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_17 V_111 ;
T_18 V_112 ;
T_18 V_113 ;
T_6 V_114 ;
T_6 V_115 ;
int error ;
V_110 -> V_116 = V_39 ;
V_110 -> V_52 = V_117 ;
V_110 -> V_53 = 0 ;
if ( ! F_54 ( V_2 ) ||
V_49 != V_118 ||
! F_55 ( V_109 ) )
return 0 ;
V_111 = F_46 ( V_8 , V_109 -> V_116 ) ;
V_112 = F_47 ( V_8 , V_109 -> V_116 ) ;
error = F_56 ( V_8 , NULL , V_111 , V_112 ,
V_109 -> V_53 , & V_113 , & V_114 , true ) ;
if ( error )
return error ;
if ( V_113 == V_119 ) {
return 0 ;
} else if ( V_112 == V_113 ) {
V_94 -> V_105 = F_3 ( V_8 , V_114 ) ;
V_94 -> V_107 |= V_120 ;
if ( V_114 != V_109 -> V_53 ) {
* V_110 = * V_109 ;
V_110 -> V_116 += V_114 ;
V_110 -> V_52 += V_114 ;
V_110 -> V_53 -= V_114 ;
}
V_109 -> V_53 -= V_114 ;
} else {
* V_110 = * V_109 ;
V_115 = V_113 - V_112 ;
V_94 -> V_105 = F_3 ( V_8 , V_115 ) ;
V_110 -> V_116 += V_115 ;
V_110 -> V_52 += V_115 ;
V_110 -> V_53 -= V_115 ;
V_109 -> V_53 -= V_115 ;
}
return 0 ;
}
int
F_57 (
T_14 * V_2 ,
struct V_93 * V_121 ,
T_19 V_122 ,
void * V_123 )
{
T_15 V_124 ;
int error = 0 ;
T_15 V_99 ;
int V_58 ;
int V_125 ;
T_20 * V_109 ;
T_5 * V_8 ;
int V_126 ;
int V_127 ;
int V_128 ;
struct V_93 * V_94 ;
int V_49 ;
int V_95 ;
int V_129 ;
int V_130 ;
int V_131 = 0 ;
struct V_50 V_132 ;
V_8 = V_2 -> V_4 ;
V_129 = V_121 -> V_133 ;
#ifndef F_58
if ( V_129 & V_134 )
return - V_135 ;
#endif
if ( ( V_129 & V_136 ) && ( V_129 & V_134 ) )
return - V_135 ;
if ( V_129 & V_136 )
V_49 = V_137 ;
else if ( V_129 & V_134 )
V_49 = V_138 ;
else
V_49 = V_118 ;
switch ( V_49 ) {
case V_137 :
if ( F_59 ( V_2 ) ) {
if ( V_2 -> V_40 . V_139 != V_84 &&
V_2 -> V_40 . V_139 != V_85 &&
V_2 -> V_40 . V_139 != V_140 )
return - V_135 ;
} else if ( F_60 (
V_2 -> V_40 . V_139 != 0 &&
V_2 -> V_40 . V_139 != V_84 ) ) {
F_39 ( L_3 , V_81 ,
V_2 -> V_4 ) ;
return - V_82 ;
}
V_95 = 0 ;
V_99 = 1LL << 32 ;
break;
case V_138 :
if ( V_2 -> V_141 != V_84 )
return - V_135 ;
if ( F_61 ( V_2 ) ) {
V_95 = 1 ;
V_99 = V_8 -> V_11 -> V_142 ;
} else {
V_95 = 0 ;
V_99 = F_50 ( V_2 ) ;
}
break;
default:
if ( V_2 -> V_40 . V_143 == V_140 ) {
V_121 -> V_144 = 0 ;
return 0 ;
}
if ( V_2 -> V_40 . V_143 != V_84 &&
V_2 -> V_40 . V_143 != V_85 )
return - V_135 ;
if ( F_11 ( V_2 ) ||
V_2 -> V_40 . V_145 & ( V_146 | V_147 ) ) {
V_95 = 1 ;
V_99 = V_8 -> V_11 -> V_142 ;
} else {
V_95 = 0 ;
V_99 = F_50 ( V_2 ) ;
}
break;
}
if ( V_121 -> V_105 == - 1 ) {
V_99 = F_3 ( V_8 , F_49 ( V_8 , V_99 ) ) ;
V_121 -> V_105 =
F_62 ( T_15 , V_99 - V_121 -> V_104 , 0 ) ;
} else if ( V_121 -> V_105 == 0 ) {
V_121 -> V_144 = 0 ;
return 0 ;
} else if ( V_121 -> V_105 < 0 ) {
return - V_135 ;
}
V_126 = V_121 -> V_148 - 1 ;
if ( V_126 <= 0 )
return - V_135 ;
V_124 = V_121 -> V_104 + V_121 -> V_105 ;
if ( V_121 -> V_148 > V_149 / sizeof( struct V_93 ) )
return - V_150 ;
V_94 = F_63 ( V_121 -> V_148 * sizeof( struct V_93 ) , 0 ) ;
if ( ! V_94 )
return - V_150 ;
F_14 ( V_2 , V_151 ) ;
switch ( V_49 ) {
case V_118 :
if ( ! ( V_129 & V_152 ) &&
( V_2 -> V_43 || F_50 ( V_2 ) > V_2 -> V_40 . V_153 ) ) {
error = F_64 ( F_9 ( V_2 ) -> V_154 ) ;
if ( error )
goto V_155;
}
V_125 = F_65 ( V_2 ) ;
break;
case V_138 :
V_125 = V_156 ;
F_14 ( V_2 , V_125 ) ;
break;
case V_137 :
V_125 = F_66 ( V_2 ) ;
break;
}
if ( V_126 > F_67 ( V_2 , V_49 ) * 2 + 1 )
V_126 = F_67 ( V_2 , V_49 ) * 2 + 1 ;
V_130 = F_68 ( V_49 ) ;
if ( ! ( V_129 & V_157 ) )
V_130 |= V_158 ;
error = - V_150 ;
V_127 = 16 ;
V_109 = F_69 ( V_127 * sizeof( * V_109 ) , V_159 | V_160 ) ;
if ( ! V_109 )
goto V_161;
V_121 -> V_144 = 0 ;
if ( F_67 ( V_2 , V_49 ) == 0 &&
( V_49 == V_137 || ! ( V_129 & V_152 ) ) ) {
error = 0 ;
goto V_162;
}
do {
V_128 = ( V_126 > V_127 ) ? V_127 : V_126 ;
error = F_70 ( V_2 , F_6 ( V_8 , V_121 -> V_104 ) ,
F_51 ( V_8 , V_121 -> V_105 ) ,
V_109 , & V_128 , V_130 ) ;
if ( error )
goto V_162;
ASSERT ( V_128 <= V_127 ) ;
for ( V_58 = 0 ; V_58 < V_128 && V_121 -> V_105 &&
V_131 < V_121 -> V_148 - 1 ; V_58 ++ ) {
V_94 [ V_131 ] . V_107 = 0 ;
if ( V_109 [ V_58 ] . V_163 == V_164 )
V_94 [ V_131 ] . V_107 |= V_165 ;
else if ( V_109 [ V_58 ] . V_116 == V_106 )
V_94 [ V_131 ] . V_107 |= V_166 ;
V_94 [ V_131 ] . V_104 =
F_3 ( V_8 , V_109 [ V_58 ] . V_52 ) ;
V_94 [ V_131 ] . V_105 =
F_3 ( V_8 , V_109 [ V_58 ] . V_53 ) ;
V_94 [ V_131 ] . V_167 = 0 ;
V_94 [ V_131 ] . V_168 = 0 ;
if ( V_109 [ V_58 ] . V_116 == V_106 &&
V_109 [ V_58 ] . V_52 < F_49 ( V_8 , F_50 ( V_2 ) ) )
ASSERT ( ( V_129 & V_152 ) != 0 ) ;
if ( V_109 [ V_58 ] . V_116 == V_102 &&
V_49 == V_137 ) {
V_94 [ V_131 ] . V_107 |= V_108 ;
goto V_162;
}
error = F_53 ( V_2 , V_49 ,
& V_109 [ V_58 ] , & V_94 [ V_131 ] , & V_132 ) ;
if ( error )
goto V_162;
if ( ! F_48 ( V_2 , V_49 ,
& V_94 [ V_131 ] , V_95 , V_124 ,
V_109 [ V_58 ] . V_116 ,
V_132 . V_116 != V_39 ) )
goto V_162;
V_121 -> V_104 =
V_94 [ V_131 ] . V_104 +
V_94 [ V_131 ] . V_105 ;
V_121 -> V_105 =
F_62 ( T_15 , 0 , V_124 - V_121 -> V_104 ) ;
if ( ( V_129 & V_169 ) &&
V_109 [ V_58 ] . V_116 == V_102 ) {
memset ( & V_94 [ V_131 ] , 0 , sizeof( V_94 [ V_131 ] ) ) ;
continue;
}
if ( V_132 . V_116 != V_39 ) {
V_109 [ V_58 ] = V_132 ;
V_58 -- ;
}
V_121 -> V_144 ++ ;
V_131 ++ ;
}
} while ( V_128 && V_121 -> V_105 && V_131 < V_121 -> V_148 - 1 );
V_162:
F_71 ( V_109 ) ;
V_161:
F_72 ( V_2 , V_125 ) ;
V_155:
F_72 ( V_2 , V_151 ) ;
for ( V_58 = 0 ; V_58 < V_131 ; V_58 ++ ) {
error = V_122 ( & V_123 , & V_94 [ V_58 ] ) ;
if ( error )
break;
}
F_71 ( V_94 ) ;
return error ;
}
int
F_73 (
struct V_1 * V_2 ,
T_8 V_5 ,
T_8 V_27 )
{
T_8 V_170 = V_27 ;
int error = 0 ;
ASSERT ( F_74 ( V_2 , V_30 ) ) ;
do {
int V_171 ;
T_20 V_172 ;
int V_173 = 1 ;
T_2 V_174 ;
struct V_175 V_176 ;
error = F_70 ( V_2 , V_5 , 1 , & V_172 , & V_173 ,
V_177 ) ;
if ( error ) {
if ( ! F_75 ( V_2 -> V_4 ) ) {
F_76 ( V_2 -> V_4 ,
L_4 ,
V_2 -> V_178 , V_5 ) ;
}
break;
}
if ( ! V_173 ) {
goto V_179;
}
if ( V_172 . V_116 != V_106 ) {
goto V_179;
}
F_77 ( V_172 . V_53 == 0 ) ;
F_78 ( & V_176 , & V_174 ) ;
error = F_79 ( NULL , V_2 , V_5 , 1 , 0 , 1 , & V_174 ,
& V_176 , & V_171 ) ;
if ( error )
break;
ASSERT ( ! F_80 ( & V_176 ) ) ;
V_179:
V_5 ++ ;
V_170 -- ;
} while( V_170 > 0 );
return error ;
}
bool
F_81 ( struct V_1 * V_2 , bool V_180 )
{
if ( ! F_82 ( F_9 ( V_2 ) -> V_181 ) )
return false ;
if ( F_9 ( V_2 ) -> V_182 == 0 &&
F_9 ( V_2 ) -> V_154 -> V_183 == 0 &&
V_2 -> V_43 == 0 )
return false ;
if ( ! ( V_2 -> V_184 . V_86 & V_87 ) )
return false ;
if ( V_2 -> V_40 . V_145 & ( V_146 | V_147 ) )
if ( ! V_180 || V_2 -> V_43 == 0 )
return false ;
return true ;
}
int
F_83 (
struct V_1 * V_2 )
{
struct V_63 * V_32 ;
int error ;
T_8 V_185 ;
T_8 V_186 ;
T_10 V_187 ;
int V_173 ;
struct V_50 V_172 ;
struct V_7 * V_8 = V_2 -> V_4 ;
V_185 = F_49 ( V_8 , ( V_188 ) F_50 ( V_2 ) ) ;
V_186 = F_49 ( V_8 , V_8 -> V_11 -> V_142 ) ;
if ( V_186 <= V_185 )
return 0 ;
V_187 = V_186 - V_185 ;
V_173 = 1 ;
F_14 ( V_2 , V_156 ) ;
error = F_70 ( V_2 , V_185 , V_187 , & V_172 , & V_173 , 0 ) ;
F_72 ( V_2 , V_156 ) ;
if ( ! error && ( V_173 != 0 ) &&
( V_172 . V_116 != V_102 ||
V_2 -> V_43 ) ) {
error = F_84 ( V_2 , 0 ) ;
if ( error )
return error ;
F_85 ( F_9 ( V_2 ) ) ;
error = F_86 ( V_8 , & F_87 ( V_8 ) -> V_189 , 0 , 0 , 0 ,
& V_32 ) ;
if ( error ) {
ASSERT ( F_75 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_30 ) ;
F_15 ( V_32 , V_2 , 0 ) ;
error = F_88 ( & V_32 , V_2 , V_118 ,
F_50 ( V_2 ) ) ;
if ( error ) {
F_89 ( V_32 ) ;
} else {
error = F_90 ( V_32 ) ;
if ( ! error )
F_91 ( V_2 ) ;
}
F_72 ( V_2 , V_30 ) ;
}
return error ;
}
int
F_92 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_190 ,
int V_191 )
{
T_5 * V_8 = V_2 -> V_4 ;
T_3 V_57 ;
T_10 V_192 ;
T_10 V_193 ;
T_6 V_194 , V_195 ;
T_8 V_196 ;
T_2 V_197 ;
int V_173 ;
int V_198 ;
int V_199 ;
T_21 * V_32 ;
T_20 V_200 [ 1 ] , * V_201 ;
struct V_175 V_176 ;
T_22 V_202 , V_203 , V_204 ;
int error ;
F_93 ( V_2 ) ;
if ( F_75 ( V_8 ) )
return - V_205 ;
error = F_84 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_190 <= 0 )
return - V_135 ;
V_199 = F_2 ( V_2 ) ;
V_194 = F_11 ( V_2 ) ;
V_57 = V_190 ;
V_201 = & V_200 [ 0 ] ;
V_173 = 1 ;
V_196 = F_94 ( V_8 , V_26 ) ;
V_193 = F_49 ( V_8 , V_57 ) ;
while ( V_193 && ! error ) {
T_8 V_206 , V_207 ;
if ( F_60 ( V_194 ) ) {
V_206 = V_196 ;
F_18 ( V_206 , V_194 ) ;
V_206 *= V_194 ;
V_207 = V_196 + V_193 ;
if ( ( V_195 = F_13 ( V_196 , V_194 ) ) )
V_207 += V_195 ;
if ( ( V_195 = F_13 ( V_207 , V_194 ) ) )
V_207 += V_194 - V_195 ;
} else {
V_206 = 0 ;
V_207 = V_193 ;
}
V_203 = F_95 ( T_8 , ( V_207 - V_206 ) , ( V_28 * V_173 ) ) ;
if ( F_60 ( V_199 ) ) {
V_204 = V_202 = V_203 ;
V_204 /= V_8 -> V_20 . V_21 ;
V_203 = F_96 ( V_8 , 0 ) ;
V_198 = V_208 ;
} else {
V_204 = 0 ;
V_203 = V_202 = F_96 ( V_8 , V_203 ) ;
V_198 = V_209 ;
}
error = F_86 ( V_8 , & F_87 ( V_8 ) -> V_210 , V_203 ,
V_204 , 0 , & V_32 ) ;
if ( error ) {
ASSERT ( error == - V_211 || F_75 ( V_8 ) ) ;
break;
}
F_14 ( V_2 , V_30 ) ;
error = F_97 ( V_32 , V_2 , V_202 ,
0 , V_198 ) ;
if ( error )
goto V_212;
F_15 ( V_32 , V_2 , 0 ) ;
F_78 ( & V_176 , & V_197 ) ;
error = F_98 ( V_32 , V_2 , V_196 ,
V_193 , V_191 , & V_197 ,
V_203 , V_201 , & V_173 , & V_176 ) ;
if ( error )
goto V_213;
error = F_99 ( & V_32 , & V_176 , NULL ) ;
if ( error )
goto V_213;
error = F_90 ( V_32 ) ;
F_72 ( V_2 , V_30 ) ;
if ( error )
break;
V_192 = V_201 -> V_53 ;
if ( V_173 == 0 ) {
error = - V_211 ;
break;
}
V_196 += V_192 ;
V_193 -= V_192 ;
}
return error ;
V_213:
F_100 ( & V_176 ) ;
F_101 ( V_32 , V_2 , ( long ) V_202 , 0 , V_198 ) ;
V_212:
F_89 ( V_32 ) ;
F_72 ( V_2 , V_30 ) ;
return error ;
}
static int
F_102 (
struct V_1 * V_2 ,
T_8 V_196 ,
T_10 V_214 ,
int * V_171 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_63 * V_32 ;
struct V_175 V_176 ;
T_2 V_197 ;
T_22 V_203 = F_96 ( V_8 , 0 ) ;
int error ;
error = F_86 ( V_8 , & F_87 ( V_8 ) -> V_210 , V_203 , 0 , 0 , & V_32 ) ;
if ( error ) {
ASSERT ( error == - V_211 || F_75 ( V_8 ) ) ;
return error ;
}
F_14 ( V_2 , V_30 ) ;
error = F_103 ( V_32 , V_8 , V_2 -> V_215 , V_2 -> V_216 ,
V_2 -> V_217 , V_203 , 0 , V_209 ) ;
if ( error )
goto V_218;
F_15 ( V_32 , V_2 , 0 ) ;
F_78 ( & V_176 , & V_197 ) ;
error = F_79 ( V_32 , V_2 , V_196 , V_214 , 0 , 2 , & V_197 ,
& V_176 , V_171 ) ;
if ( error )
goto V_219;
error = F_99 ( & V_32 , & V_176 , V_2 ) ;
if ( error )
goto V_219;
error = F_90 ( V_32 ) ;
V_220:
F_72 ( V_2 , V_30 ) ;
return error ;
V_219:
F_100 ( & V_176 ) ;
V_218:
F_89 ( V_32 ) ;
goto V_220;
}
static int
F_104 (
struct V_1 * V_2 ,
T_8 * V_196 ,
T_8 * V_221 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_50 V_172 ;
int V_222 , error ;
T_6 V_223 = 0 ;
V_222 = 1 ;
error = F_70 ( V_2 , * V_196 , 1 , & V_172 , & V_222 , 0 ) ;
if ( error )
return error ;
if ( V_222 && V_172 . V_116 != V_102 ) {
ASSERT ( V_172 . V_116 != V_106 ) ;
V_223 = F_13 ( V_172 . V_116 , V_8 -> V_20 . V_21 ) ;
if ( V_223 )
* V_196 += V_8 -> V_20 . V_21 - V_223 ;
}
V_222 = 1 ;
error = F_70 ( V_2 , * V_221 - 1 , 1 , & V_172 , & V_222 , 0 ) ;
if ( error )
return error ;
if ( V_222 && V_172 . V_116 != V_102 ) {
ASSERT ( V_172 . V_116 != V_106 ) ;
V_223 ++ ;
if ( V_223 && V_223 != V_8 -> V_20 . V_21 )
* V_221 -= V_223 ;
}
return 0 ;
}
static int
F_105 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_190 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_224 * V_224 = F_9 ( V_2 ) ;
T_3 V_225 , V_226 , V_96 ;
int error ;
F_85 ( V_224 ) ;
V_225 = F_62 ( T_3 , 1 << V_8 -> V_20 . V_227 , V_228 ) ;
V_226 = F_106 ( V_26 , V_225 ) ;
V_96 = F_107 ( V_26 + V_190 , V_225 ) - 1 ;
error = F_108 ( V_224 -> V_154 , V_226 , V_96 ) ;
if ( error )
return error ;
F_109 ( V_224 , V_226 , V_96 ) ;
return 0 ;
}
int
F_110 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_190 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_8 V_196 ;
T_8 V_221 ;
int V_171 = 0 , error ;
F_111 ( V_2 ) ;
error = F_84 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_190 <= 0 )
return 0 ;
error = F_105 ( V_2 , V_26 , V_190 ) ;
if ( error )
return error ;
V_196 = F_49 ( V_8 , V_26 ) ;
V_221 = F_94 ( V_8 , V_26 + V_190 ) ;
if ( F_2 ( V_2 ) &&
! F_112 ( & V_8 -> V_20 ) ) {
error = F_104 ( V_2 , & V_196 ,
& V_221 ) ;
if ( error )
return error ;
}
if ( V_221 > V_196 ) {
while ( ! V_171 ) {
error = F_102 ( V_2 , V_196 ,
V_221 - V_196 , & V_171 ) ;
if ( error )
return error ;
}
}
if ( V_26 >= F_50 ( V_2 ) )
return 0 ;
if ( V_26 + V_190 > F_50 ( V_2 ) )
V_190 = F_50 ( V_2 ) - V_26 ;
return F_113 ( V_2 , V_26 , V_190 , NULL ) ;
}
int
F_114 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_190 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
T_22 V_229 ;
int error ;
F_115 ( V_2 ) ;
V_229 = 1 << V_8 -> V_20 . V_227 ;
error = F_110 ( V_2 , V_26 , V_190 ) ;
if ( error )
goto V_94;
error = F_92 ( V_2 , F_106 ( V_26 , V_229 ) ,
F_107 ( V_26 + V_190 , V_229 ) -
F_106 ( V_26 , V_229 ) ,
V_230 ) ;
V_94:
return error ;
}
static int
F_116 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_190 ,
enum V_231 V_232 )
{
int V_171 = 0 ;
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_63 * V_32 ;
int error ;
struct V_175 V_176 ;
T_2 V_233 ;
T_8 V_234 ;
T_8 V_235 ;
T_8 V_236 ;
T_22 V_203 ;
ASSERT ( V_232 == V_237 || V_232 == V_238 ) ;
if ( V_232 == V_237 ) {
V_203 = F_96 ( V_8 , 0 ) ;
V_235 = F_49 ( V_8 , V_26 + V_190 ) ;
V_234 = F_49 ( V_8 , F_9 ( V_2 ) -> V_182 ) ;
} else {
V_203 = 0 ;
V_235 = V_39 ;
V_234 = F_49 ( V_8 , V_26 ) ;
}
V_236 = F_49 ( V_8 , V_190 ) ;
if ( F_81 ( V_2 , true ) ) {
error = F_83 ( V_2 ) ;
if ( error )
return error ;
}
error = F_108 ( F_9 ( V_2 ) -> V_154 ,
V_26 , - 1 ) ;
if ( error )
return error ;
error = F_117 ( F_9 ( V_2 ) -> V_154 ,
V_26 >> V_239 , - 1 ) ;
if ( error )
return error ;
if ( V_232 == V_238 ) {
error = F_118 ( V_2 , V_234 ) ;
if ( error )
return error ;
}
while ( ! error && ! V_171 ) {
error = F_86 ( V_8 , & F_87 ( V_8 ) -> V_210 , V_203 , 0 , 0 ,
& V_32 ) ;
if ( error )
break;
F_14 ( V_2 , V_30 ) ;
error = F_103 ( V_32 , V_8 , V_2 -> V_215 ,
V_2 -> V_216 , V_2 -> V_217 , V_203 , 0 ,
V_209 ) ;
if ( error )
goto V_218;
F_15 ( V_32 , V_2 , V_30 ) ;
F_78 ( & V_176 , & V_233 ) ;
error = F_119 ( V_32 , V_2 , & V_235 , V_236 ,
& V_171 , V_234 , & V_233 , & V_176 ,
V_232 , V_240 ) ;
if ( error )
goto V_219;
error = F_99 ( & V_32 , & V_176 , NULL ) ;
if ( error )
goto V_219;
error = F_90 ( V_32 ) ;
}
return error ;
V_219:
F_100 ( & V_176 ) ;
V_218:
F_89 ( V_32 ) ;
return error ;
}
int
F_120 (
struct V_1 * V_2 ,
T_3 V_26 ,
T_3 V_190 )
{
int error ;
ASSERT ( F_74 ( V_2 , V_241 ) ) ;
F_121 ( V_2 ) ;
error = F_110 ( V_2 , V_26 , V_190 ) ;
if ( error )
return error ;
return F_116 ( V_2 , V_26 , V_190 , V_237 ) ;
}
int
F_122 (
struct V_1 * V_2 ,
T_23 V_26 ,
T_23 V_190 )
{
ASSERT ( F_74 ( V_2 , V_241 ) ) ;
F_123 ( V_2 ) ;
return F_116 ( V_2 , V_26 , V_190 , V_238 ) ;
}
static int
F_124 (
struct V_1 * V_2 ,
struct V_1 * V_242 )
{
if ( V_2 -> V_40 . V_143 == V_140 ||
V_242 -> V_40 . V_143 == V_140 )
return - V_135 ;
if ( V_2 -> V_40 . V_243 < V_242 -> V_40 . V_243 )
return - V_135 ;
if ( F_125 ( & V_2 -> V_4 -> V_20 ) )
return 0 ;
if ( V_2 -> V_40 . V_143 == V_84 &&
V_242 -> V_40 . V_143 == V_85 )
return - V_135 ;
if ( V_242 -> V_40 . V_143 == V_84 &&
F_67 ( V_242 , V_118 ) >
F_126 ( V_2 , V_118 ) )
return - V_135 ;
if ( V_2 -> V_40 . V_143 == V_84 &&
F_67 ( V_2 , V_118 ) >
F_126 ( V_242 , V_118 ) )
return - V_135 ;
if ( V_242 -> V_40 . V_143 == V_85 ) {
if ( F_59 ( V_2 ) &&
F_127 ( V_242 -> V_184 . V_88 ) > F_128 ( V_2 ) )
return - V_135 ;
if ( F_67 ( V_242 , V_118 ) <=
F_126 ( V_2 , V_118 ) )
return - V_135 ;
}
if ( V_2 -> V_40 . V_143 == V_85 ) {
if ( F_59 ( V_242 ) &&
F_127 ( V_2 -> V_184 . V_88 ) > F_128 ( V_242 ) )
return - V_135 ;
if ( F_67 ( V_2 , V_118 ) <=
F_126 ( V_242 , V_118 ) )
return - V_135 ;
}
return 0 ;
}
static int
F_129 (
struct V_1 * V_2 )
{
int error ;
error = F_64 ( F_9 ( V_2 ) -> V_154 ) ;
if ( error )
return error ;
F_109 ( F_9 ( V_2 ) , 0 , - 1 ) ;
if ( F_9 ( V_2 ) -> V_154 -> V_183 )
return - V_135 ;
return 0 ;
}
STATIC int
F_130 (
struct V_63 * * V_244 ,
struct V_1 * V_2 ,
struct V_1 * V_242 )
{
struct V_50 V_245 ;
struct V_50 V_246 ;
struct V_50 V_247 ;
T_8 V_248 ;
T_8 V_185 ;
T_10 V_6 ;
T_2 V_197 ;
struct V_175 V_176 ;
int error ;
T_10 V_249 ;
T_10 V_250 ;
int V_173 ;
T_24 V_251 ;
V_251 = V_242 -> V_40 . V_252 ;
if ( V_2 -> V_40 . V_252 & V_253 )
V_242 -> V_40 . V_252 |= V_253 ;
V_248 = 0 ;
V_185 = F_49 ( V_2 -> V_4 , F_131 ( F_9 ( V_2 ) ) ) ;
V_6 = ( T_10 ) ( V_185 - V_248 ) ;
while ( V_6 ) {
V_173 = 1 ;
error = F_70 ( V_242 , V_248 , V_6 , & V_247 ,
& V_173 , 0 ) ;
if ( error )
goto V_94;
ASSERT ( V_173 == 1 ) ;
ASSERT ( V_247 . V_116 != V_106 ) ;
F_132 ( V_242 , & V_247 ) ;
V_249 = V_247 . V_53 ;
while ( V_247 . V_53 ) {
F_78 ( & V_176 , & V_197 ) ;
F_133 ( V_242 , & V_247 ) ;
V_173 = 1 ;
error = F_70 ( V_2 , V_247 . V_52 ,
V_247 . V_53 , & V_245 ,
& V_173 , 0 ) ;
if ( error )
goto V_254;
ASSERT ( V_173 == 1 ) ;
ASSERT ( V_247 . V_52 == V_245 . V_52 ) ;
F_133 ( V_2 , & V_245 ) ;
V_246 = V_247 ;
V_246 . V_53 = V_250 = F_95 ( T_10 ,
V_247 . V_53 ,
V_245 . V_53 ) ;
F_133 ( V_242 , & V_246 ) ;
error = F_134 ( ( * V_244 ) -> V_255 , & V_176 ,
V_242 , & V_246 ) ;
if ( error )
goto V_254;
error = F_134 ( ( * V_244 ) -> V_255 , & V_176 ,
V_2 , & V_245 ) ;
if ( error )
goto V_254;
error = F_135 ( ( * V_244 ) -> V_255 , & V_176 ,
V_2 , & V_246 ) ;
if ( error )
goto V_254;
error = F_135 ( ( * V_244 ) -> V_255 , & V_176 ,
V_242 , & V_245 ) ;
if ( error )
goto V_254;
error = F_99 ( V_244 , & V_176 , V_2 ) ;
if ( error )
goto V_254;
V_247 . V_52 += V_250 ;
if ( V_247 . V_116 != V_102 &&
V_247 . V_116 != V_106 )
V_247 . V_116 += V_250 ;
V_247 . V_53 -= V_250 ;
}
V_6 -= V_249 ;
V_248 += V_249 ;
}
V_242 -> V_40 . V_252 = V_251 ;
return 0 ;
V_254:
F_100 ( & V_176 ) ;
V_94:
F_136 ( V_2 , error , V_256 ) ;
V_242 -> V_40 . V_252 = V_251 ;
return error ;
}
STATIC int
F_137 (
struct V_63 * V_32 ,
struct V_1 * V_2 ,
struct V_1 * V_242 ,
int * V_257 ,
int * V_258 )
{
struct V_54 V_259 , * V_55 , * V_260 ;
T_10 V_261 = 0 ;
T_10 V_262 = 0 ;
T_9 V_263 ;
T_9 V_66 ;
T_24 V_264 ;
int error ;
if ( ( ( F_59 ( V_2 ) != 0 ) && ( V_2 -> V_40 . V_265 > 0 ) ) &&
( V_2 -> V_40 . V_139 != V_140 ) ) {
error = F_41 ( V_32 , V_2 , V_137 , & V_263 ,
& V_261 ) ;
if ( error )
return error ;
}
if ( ( ( F_59 ( V_242 ) != 0 ) && ( V_242 -> V_40 . V_265 > 0 ) ) &&
( V_242 -> V_40 . V_139 != V_140 ) ) {
error = F_41 ( V_32 , V_242 , V_137 , & V_263 ,
& V_262 ) ;
if ( error )
return error ;
}
if ( V_2 -> V_40 . V_266 == 3 &&
V_2 -> V_40 . V_143 == V_85 ) {
( * V_258 ) |= V_267 ;
error = F_138 ( V_32 , V_2 , V_118 ,
V_242 -> V_178 , NULL ) ;
if ( error )
return error ;
}
if ( V_242 -> V_40 . V_266 == 3 &&
V_242 -> V_40 . V_143 == V_85 ) {
( * V_257 ) |= V_267 ;
error = F_138 ( V_32 , V_242 , V_118 ,
V_2 -> V_178 , NULL ) ;
if ( error )
return error ;
}
V_55 = & V_2 -> V_184 ;
V_260 = & V_242 -> V_184 ;
V_259 = * V_55 ;
* V_55 = * V_260 ;
* V_260 = V_259 ;
V_264 = ( T_24 ) V_2 -> V_40 . V_41 ;
V_2 -> V_40 . V_41 = V_242 -> V_40 . V_41 - V_262 + V_261 ;
V_242 -> V_40 . V_41 = V_264 + V_262 - V_261 ;
V_264 = ( T_24 ) V_2 -> V_40 . V_243 ;
V_2 -> V_40 . V_243 = V_242 -> V_40 . V_243 ;
V_242 -> V_40 . V_243 = V_264 ;
V_264 = ( T_24 ) V_2 -> V_40 . V_143 ;
V_2 -> V_40 . V_143 = V_242 -> V_40 . V_143 ;
V_242 -> V_40 . V_143 = V_264 ;
ASSERT ( V_242 -> V_43 == 0 ) ;
V_242 -> V_43 = V_2 -> V_43 ;
V_2 -> V_43 = 0 ;
switch ( V_2 -> V_40 . V_143 ) {
case V_84 :
V_66 = F_25 ( & V_2 -> V_184 ) ;
if ( V_66 <= V_268 )
V_55 -> V_269 . V_270 = V_55 -> V_271 . V_272 ;
( * V_257 ) |= V_273 ;
break;
case V_85 :
ASSERT ( V_2 -> V_40 . V_266 < 3 ||
( * V_257 & V_267 ) ) ;
( * V_257 ) |= V_274 ;
break;
}
switch ( V_242 -> V_40 . V_143 ) {
case V_84 :
V_66 = F_25 ( & V_242 -> V_184 ) ;
if ( V_66 <= V_268 )
V_260 -> V_269 . V_270 = V_260 -> V_271 . V_272 ;
( * V_258 ) |= V_273 ;
break;
case V_85 :
( * V_258 ) |= V_274 ;
ASSERT ( V_242 -> V_40 . V_266 < 3 ||
( * V_258 & V_267 ) ) ;
break;
}
return 0 ;
}
int
F_139 (
struct V_1 * V_2 ,
struct V_1 * V_242 ,
struct V_275 * V_276 )
{
struct V_7 * V_8 = V_2 -> V_4 ;
struct V_63 * V_32 ;
struct V_277 * V_278 = & V_276 -> V_279 ;
int V_257 , V_258 ;
int error = 0 ;
int V_280 ;
struct V_54 * V_281 ;
T_24 V_282 ;
int V_203 ;
F_140 ( F_9 ( V_2 ) , F_9 ( V_242 ) ) ;
V_280 = V_283 ;
F_141 ( V_2 , V_242 , V_283 ) ;
if ( ( F_9 ( V_2 ) -> V_181 & V_284 ) != ( F_9 ( V_242 ) -> V_181 & V_284 ) ) {
error = - V_135 ;
goto V_220;
}
if ( F_2 ( V_2 ) != F_2 ( V_242 ) ) {
error = - V_135 ;
goto V_220;
}
error = F_129 ( V_2 ) ;
if ( error )
goto V_220;
error = F_129 ( V_242 ) ;
if ( error )
goto V_220;
if ( F_125 ( & V_8 -> V_20 ) ) {
V_203 = F_142 ( V_8 ,
F_67 ( V_2 , V_118 ) ,
V_118 ) +
F_142 ( V_8 ,
F_67 ( V_242 , V_118 ) ,
V_118 ) ;
error = F_86 ( V_8 , & F_87 ( V_8 ) -> V_210 , V_203 ,
0 , 0 , & V_32 ) ;
} else
error = F_86 ( V_8 , & F_87 ( V_8 ) -> V_285 , 0 ,
0 , 0 , & V_32 ) ;
if ( error )
goto V_220;
F_141 ( V_2 , V_242 , V_30 ) ;
V_280 |= V_30 ;
F_15 ( V_32 , V_2 , 0 ) ;
F_15 ( V_32 , V_242 , 0 ) ;
if ( V_276 -> V_286 != 0 ||
V_276 -> V_287 != V_2 -> V_40 . V_153 ||
V_276 -> V_287 != V_242 -> V_40 . V_153 ) {
error = - V_288 ;
goto V_218;
}
F_143 ( V_2 , 0 ) ;
F_143 ( V_242 , 1 ) ;
error = F_124 ( V_2 , V_242 ) ;
if ( error ) {
F_144 ( V_8 ,
L_5 ,
V_289 , V_2 -> V_178 ) ;
goto V_218;
}
if ( ( V_278 -> V_290 . V_291 != F_9 ( V_2 ) -> V_292 . V_291 ) ||
( V_278 -> V_290 . V_293 != F_9 ( V_2 ) -> V_292 . V_293 ) ||
( V_278 -> V_294 . V_291 != F_9 ( V_2 ) -> V_295 . V_291 ) ||
( V_278 -> V_294 . V_293 != F_9 ( V_2 ) -> V_295 . V_293 ) ) {
error = - V_296 ;
goto V_218;
}
V_257 = V_42 ;
V_258 = V_42 ;
if ( F_125 ( & V_8 -> V_20 ) )
error = F_130 ( & V_32 , V_2 , V_242 ) ;
else
error = F_137 ( V_32 , V_2 , V_242 , & V_257 ,
& V_258 ) ;
if ( error )
goto V_218;
if ( ( V_2 -> V_40 . V_252 & V_253 ) ^
( V_242 -> V_40 . V_252 & V_253 ) ) {
V_282 = V_2 -> V_40 . V_252 & V_253 ;
V_2 -> V_40 . V_252 &= ~ V_253 ;
V_2 -> V_40 . V_252 |= V_242 -> V_40 . V_252 & V_253 ;
V_242 -> V_40 . V_252 &= ~ V_253 ;
V_242 -> V_40 . V_252 |= V_282 & V_253 ;
V_281 = V_2 -> V_297 ;
V_2 -> V_297 = V_242 -> V_297 ;
V_242 -> V_297 = V_281 ;
F_145 ( V_2 ) ;
F_145 ( V_242 ) ;
}
F_20 ( V_32 , V_2 , V_257 ) ;
F_20 ( V_32 , V_242 , V_258 ) ;
if ( V_8 -> V_298 & V_299 )
F_146 ( V_32 ) ;
error = F_90 ( V_32 ) ;
F_147 ( V_2 , 0 ) ;
F_147 ( V_242 , 1 ) ;
V_220:
F_72 ( V_2 , V_280 ) ;
F_72 ( V_242 , V_280 ) ;
F_148 ( F_9 ( V_2 ) , F_9 ( V_242 ) ) ;
return error ;
V_218:
F_89 ( V_32 ) ;
goto V_220;
}
