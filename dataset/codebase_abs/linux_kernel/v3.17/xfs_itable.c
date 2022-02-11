STATIC int
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
return ( V_2 == V_1 -> V_3 . V_4 || V_2 == V_1 -> V_3 . V_5 ||
( F_2 ( & V_1 -> V_3 ) &&
F_3 ( & V_1 -> V_3 , V_2 ) ) ) ;
}
int
F_4 (
struct V_6 * V_1 ,
T_2 V_2 ,
void T_3 * V_7 ,
int V_8 ,
T_4 V_9 ,
int * V_10 ,
int * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int error = 0 ;
* V_11 = V_18 ;
if ( ! V_7 || F_1 ( V_1 , V_2 ) )
return - V_19 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_20 | V_21 ) ;
if ( ! V_17 )
return - V_22 ;
error = F_6 ( V_1 , NULL , V_2 ,
( V_23 | V_24 ) ,
V_25 , & V_15 ) ;
if ( error )
goto V_26;
ASSERT ( V_15 != NULL ) ;
ASSERT ( V_15 -> V_27 . V_28 != 0 ) ;
V_13 = & V_15 -> V_29 ;
V_17 -> V_30 = V_13 -> V_31 ;
V_17 -> V_32 = V_13 -> V_33 ;
V_17 -> V_34 = V_13 -> V_35 ;
V_17 -> V_36 = V_2 ;
V_17 -> V_37 = V_13 -> V_38 ;
V_17 -> V_39 = V_13 -> V_40 ;
V_17 -> V_41 = V_13 -> V_42 ;
V_17 -> V_43 = V_13 -> V_44 ;
V_17 -> V_45 . V_46 = V_13 -> V_47 . V_48 ;
V_17 -> V_45 . V_49 = V_13 -> V_47 . V_50 ;
V_17 -> V_51 . V_46 = V_13 -> V_52 . V_48 ;
V_17 -> V_51 . V_49 = V_13 -> V_52 . V_50 ;
V_17 -> V_53 . V_46 = V_13 -> V_54 . V_48 ;
V_17 -> V_53 . V_49 = V_13 -> V_54 . V_50 ;
V_17 -> V_55 = F_7 ( V_15 ) ;
V_17 -> V_56 = V_13 -> V_57 << V_1 -> V_3 . V_58 ;
V_17 -> V_59 = V_13 -> V_60 ;
V_17 -> V_61 = V_13 -> V_62 ;
memset ( V_17 -> V_63 , 0 , sizeof( V_17 -> V_63 ) ) ;
V_17 -> V_64 = V_13 -> V_65 ;
V_17 -> V_66 = V_13 -> V_67 ;
V_17 -> V_68 = V_13 -> V_69 ;
V_17 -> V_70 = F_8 ( V_15 ) ;
switch ( V_13 -> V_71 ) {
case V_72 :
V_17 -> V_73 = V_15 -> V_74 . V_75 . V_76 ;
V_17 -> V_77 = V_78 ;
V_17 -> V_79 = 0 ;
break;
case V_80 :
case V_81 :
V_17 -> V_73 = 0 ;
V_17 -> V_77 = V_1 -> V_3 . V_82 ;
V_17 -> V_79 = 0 ;
break;
case V_83 :
case V_84 :
V_17 -> V_73 = 0 ;
V_17 -> V_77 = V_1 -> V_3 . V_82 ;
V_17 -> V_79 = V_13 -> V_85 + V_15 -> V_86 ;
break;
}
F_9 ( V_15 , V_25 ) ;
F_10 ( V_15 ) ;
error = V_9 ( V_7 , V_8 , V_10 , V_17 ) ;
if ( ! error )
* V_11 = V_87 ;
V_26:
F_11 ( V_17 ) ;
return error ;
}
STATIC int
F_12 (
void T_3 * V_88 ,
int V_8 ,
int * V_10 ,
const T_5 * V_7 )
{
if ( V_8 < sizeof( * V_7 ) )
return - V_22 ;
if ( F_13 ( V_88 , V_7 , sizeof( * V_7 ) ) )
return - V_89 ;
if ( V_10 )
* V_10 = sizeof( * V_7 ) ;
return 0 ;
}
int
F_14 (
T_1 * V_1 ,
T_2 V_2 ,
void T_3 * V_7 ,
int V_8 ,
int * V_10 ,
int * V_11 )
{
return F_4 ( V_1 , V_2 , V_7 , V_8 ,
F_12 , V_10 , V_11 ) ;
}
STATIC void
F_15 (
struct V_6 * V_1 ,
T_6 V_90 ,
struct V_91 * V_92 )
{
T_7 V_93 ;
struct V_94 V_95 ;
int V_96 ;
int V_97 ;
int V_98 ;
V_93 = F_16 ( V_1 , V_92 -> V_99 ) ;
V_96 = F_17 ( V_1 ) ;
V_97 = V_96 << V_1 -> V_3 . V_100 ;
F_18 ( & V_95 ) ;
for ( V_98 = 0 ; V_98 < V_101 ;
V_98 += V_97 , V_93 += V_96 ) {
if ( F_19 ( V_98 , V_97 ) & ~ V_92 -> V_102 ) {
F_20 ( V_1 , V_90 , V_93 , V_96 ,
& V_103 ) ;
}
}
F_21 ( & V_95 ) ;
}
STATIC int
F_22 (
struct V_104 * V_105 ,
T_8 V_106 ,
int * V_107 ,
struct V_91 * V_92 )
{
int V_108 ;
int V_11 ;
int error = 0 ;
error = F_23 ( V_105 , V_106 , V_109 , & V_11 ) ;
if ( error )
return error ;
if ( ! V_11 ) {
* V_107 = 0 ;
return error ;
}
error = F_24 ( V_105 , V_92 , & V_11 ) ;
if ( error )
return error ;
F_25 ( V_11 == 1 ) ;
if ( V_92 -> V_99 + V_101 <= V_106 )
return - V_19 ;
V_108 = V_106 - V_92 -> V_99 + 1 ;
if ( V_108 < V_101 &&
( F_19 ( V_108 , V_101 - V_108 ) & ~ V_92 -> V_102 ) ) {
int V_98 ;
for ( V_98 = 0 ; V_98 < V_108 ; V_98 ++ ) {
if ( F_26 ( V_98 ) & ~ V_92 -> V_102 )
V_92 -> V_110 ++ ;
}
V_92 -> V_102 |= F_19 ( 0 , V_108 ) ;
* V_107 = V_101 - V_92 -> V_110 ;
}
return 0 ;
}
int
F_27 (
struct V_6 * V_1 ,
T_6 V_90 ,
struct V_91 * V_111 ,
T_9 V_9 ,
T_10 V_112 ,
struct V_113 * V_114 )
{
T_2 V_115 = V_114 -> V_116 ;
char T_3 * * V_117 = V_114 -> V_118 ;
int V_119 = V_114 -> V_120 ;
int V_121 = V_114 -> V_122 ;
int V_123 , V_124 ;
int error = 0 ;
T_8 V_106 ;
for ( V_106 = V_111 -> V_99 , V_123 = V_124 = 0 ;
F_28 ( V_119 ) &&
V_111 -> V_110 < V_101 ;
V_123 ++ , V_124 ++ , V_106 ++ ) {
int V_125 ;
int V_10 ;
T_2 V_2 = F_29 ( V_1 , V_90 , V_106 ) ;
ASSERT ( V_123 < V_101 ) ;
if ( F_26 ( V_123 ) & V_111 -> V_102 ) {
V_115 = V_2 ;
continue;
}
V_111 -> V_110 ++ ;
V_10 = V_112 ;
error = V_9 ( V_1 , V_2 , * V_117 , V_119 , & V_10 , & V_125 ) ;
if ( V_125 == V_18 ) {
if ( error && error != - V_126 && error != - V_19 ) {
V_119 = 0 ;
break;
}
V_115 = V_2 ;
continue;
}
if ( V_125 == V_127 ) {
V_119 = 0 ;
ASSERT ( error ) ;
break;
}
if ( * V_117 )
* V_117 += V_10 ;
V_119 -= V_10 ;
V_121 ++ ;
V_115 = V_2 ;
}
V_114 -> V_116 = V_115 ;
V_114 -> V_120 = V_119 ;
V_114 -> V_122 = V_121 ;
return error ;
}
int
F_30 (
T_1 * V_1 ,
T_2 * V_128 ,
int * V_129 ,
T_9 V_9 ,
T_10 V_112 ,
char T_3 * V_88 ,
int * V_130 )
{
T_11 * V_131 ;
T_12 * V_132 ;
T_8 V_106 ;
T_6 V_90 ;
T_13 * V_105 ;
int V_133 ;
int error ;
int V_125 ;
int V_98 ;
int V_107 ;
T_10 V_134 ;
T_2 V_2 ;
T_14 * V_111 ;
T_14 * V_135 ;
T_14 * V_136 ;
T_2 V_115 ;
int V_137 ;
int V_138 ;
int V_139 ;
int V_140 ;
int V_119 ;
char T_3 * V_117 ;
int V_121 ;
V_2 = ( T_2 ) * V_128 ;
V_115 = V_2 ;
V_90 = F_31 ( V_1 , V_2 ) ;
V_106 = F_32 ( V_1 , V_2 ) ;
if ( V_90 >= V_1 -> V_3 . V_141 ||
V_2 != F_29 ( V_1 , V_90 , V_106 ) ) {
* V_130 = 1 ;
* V_129 = 0 ;
return 0 ;
}
V_140 = * V_129 ;
V_119 = V_140 * V_112 ;
* V_129 = V_121 = 0 ;
* V_130 = 0 ;
V_125 = 0 ;
V_117 = V_88 ;
V_135 = F_33 ( & V_134 , V_142 , V_142 * 4 ) ;
if ( ! V_135 )
return - V_22 ;
V_137 = V_134 / sizeof( * V_135 ) ;
V_138 = 0 ;
while ( F_28 ( V_119 ) && V_90 < V_1 -> V_3 . V_141 ) {
F_34 () ;
error = F_35 ( V_1 , NULL , V_90 , & V_131 ) ;
if ( error )
break;
V_132 = F_36 ( V_131 ) ;
V_105 = F_37 ( V_1 , NULL , V_131 , V_90 ,
V_143 ) ;
V_111 = V_135 ;
V_136 = V_135 + V_137 ;
V_133 = 0 ;
V_107 = 0 ;
if ( V_106 > 0 ) {
struct V_91 V_144 ;
error = F_22 ( V_105 , V_106 , & V_107 , & V_144 ) ;
if ( error )
break;
if ( V_107 ) {
V_111 -> V_99 = V_144 . V_99 ;
V_111 -> V_110 = V_144 . V_110 ;
V_111 -> V_102 = V_144 . V_102 ;
V_111 ++ ;
V_106 = V_144 . V_99 + V_101 ;
}
error = F_38 ( V_105 , 0 , & V_139 ) ;
} else {
error = F_23 ( V_105 , 0 , V_145 , & V_139 ) ;
}
if ( error )
break;
while ( V_111 < V_136 && V_107 < V_140 ) {
struct V_91 V_144 ;
error = F_24 ( V_105 , & V_144 , & V_98 ) ;
if ( error || V_98 == 0 ) {
V_133 = 1 ;
break;
}
if ( V_144 . V_110 < V_101 ) {
F_15 ( V_1 , V_90 , & V_144 ) ;
V_111 -> V_99 = V_144 . V_99 ;
V_111 -> V_110 = V_144 . V_110 ;
V_111 -> V_102 = V_144 . V_102 ;
V_111 ++ ;
V_107 += V_101 - V_144 . V_110 ;
}
V_106 = V_144 . V_99 + V_101 ;
error = F_38 ( V_105 , 0 , & V_139 ) ;
F_34 () ;
}
F_39 ( V_105 , V_146 ) ;
F_40 ( V_131 ) ;
V_136 = V_111 ;
for ( V_111 = V_135 ;
V_111 < V_136 && F_28 ( V_119 ) ; V_111 ++ ) {
struct V_113 V_147 ;
V_147 . V_116 = V_115 ;
V_147 . V_118 = & V_88 ;
V_147 . V_120 = V_119 ;
V_147 . V_122 = V_121 ;
error = F_27 ( V_1 , V_90 , V_111 ,
V_9 , V_112 , & V_147 ) ;
if ( error )
V_138 = error ;
V_115 = V_147 . V_116 ;
V_119 = V_147 . V_120 ;
V_121 = V_147 . V_122 ;
F_34 () ;
}
if ( F_28 ( V_119 ) ) {
if ( V_133 ) {
V_90 ++ ;
V_106 = 0 ;
} else
V_106 = F_32 ( V_1 , V_115 ) ;
} else
break;
}
F_11 ( V_135 ) ;
* V_129 = V_121 ;
if ( V_121 )
V_138 = 0 ;
if ( V_90 >= V_1 -> V_3 . V_141 ) {
* V_128 = ( T_2 ) F_29 ( V_1 , V_90 , 0 ) ;
* V_130 = 1 ;
} else
* V_128 = ( T_2 ) V_115 ;
return V_138 ;
}
int
F_41 (
void T_3 * V_88 ,
const struct V_148 * V_7 ,
long V_149 ,
long * V_150 )
{
if ( F_13 ( V_88 , V_7 , V_149 * sizeof( * V_7 ) ) )
return - V_89 ;
* V_150 = V_149 * sizeof( * V_7 ) ;
return 0 ;
}
int
F_42 (
struct V_6 * V_1 ,
T_2 * V_115 ,
int * V_149 ,
void T_3 * V_88 ,
T_15 V_9 )
{
T_6 V_90 = F_31 ( V_1 , * V_115 ) ;
T_8 V_106 = F_32 ( V_1 , * V_115 ) ;
struct V_104 * V_105 = NULL ;
struct V_151 * V_131 = NULL ;
struct V_148 * V_7 ;
int V_152 ;
int V_153 = * V_149 ;
int V_154 = 0 ;
int error = 0 ;
* V_149 = 0 ;
if ( V_90 >= V_1 -> V_3 . V_141 ||
* V_115 != F_29 ( V_1 , V_90 , V_106 ) )
return error ;
V_152 = F_43 ( V_153 , ( int ) ( V_142 / sizeof( * V_7 ) ) ) ;
V_7 = F_5 ( V_152 * sizeof( * V_7 ) , V_20 ) ;
do {
struct V_91 V_144 ;
int V_11 ;
if ( ! V_131 ) {
error = F_35 ( V_1 , NULL , V_90 , & V_131 ) ;
if ( error )
break;
V_105 = F_37 ( V_1 , NULL , V_131 , V_90 ,
V_143 ) ;
error = F_23 ( V_105 , V_106 , V_145 ,
& V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_155;
}
error = F_24 ( V_105 , & V_144 , & V_11 ) ;
if ( error )
break;
if ( ! V_11 )
goto V_155;
V_106 = V_144 . V_99 + V_101 - 1 ;
V_7 [ V_154 ] . V_156 =
F_29 ( V_1 , V_90 , V_144 . V_99 ) ;
V_7 [ V_154 ] . V_157 =
V_101 - V_144 . V_110 ;
V_7 [ V_154 ] . V_158 = ~ V_144 . V_102 ;
if ( ++ V_154 == V_152 ) {
long V_150 ;
error = V_9 ( V_88 , V_7 , V_154 , & V_150 ) ;
if ( error )
break;
V_88 += V_150 ;
* V_149 += V_154 ;
V_154 = 0 ;
}
if ( ! -- V_153 )
break;
error = F_38 ( V_105 , 0 , & V_11 ) ;
if ( error )
break;
if ( V_11 )
continue;
V_155:
F_39 ( V_105 , V_159 ) ;
V_105 = NULL ;
F_40 ( V_131 ) ;
V_131 = NULL ;
V_106 = 0 ;
} while ( ++ V_90 < V_1 -> V_3 . V_141 );
if ( ! error ) {
if ( V_154 ) {
long V_150 ;
error = V_9 ( V_88 , V_7 , V_154 , & V_150 ) ;
if ( ! error )
* V_149 += V_154 ;
}
* V_115 = F_29 ( V_1 , V_90 , V_106 ) ;
}
F_11 ( V_7 ) ;
if ( V_105 )
F_39 ( V_105 , ( error ? V_159 :
V_146 ) ) ;
if ( V_131 )
F_40 ( V_131 ) ;
return error ;
}
