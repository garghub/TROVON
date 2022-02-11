STATIC int
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
return ( V_2 == V_1 -> V_3 . V_4 || V_2 == V_1 -> V_3 . V_5 ||
( F_2 ( & V_1 -> V_3 ) &&
( V_2 == V_1 -> V_3 . V_6 || V_2 == V_1 -> V_3 . V_7 ) ) ) ;
}
int
F_3 (
struct V_8 * V_1 ,
T_2 V_2 ,
void T_3 * V_9 ,
int V_10 ,
T_4 V_11 ,
int * V_12 ,
int * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_18 ;
struct V_19 * V_20 ;
int error = 0 ;
* V_13 = V_21 ;
if ( ! V_9 || F_1 ( V_1 , V_2 ) )
return F_4 ( V_22 ) ;
V_20 = F_5 ( sizeof( * V_20 ) , V_23 | V_24 ) ;
if ( ! V_20 )
return F_4 ( V_25 ) ;
error = F_6 ( V_1 , NULL , V_2 ,
V_26 , V_27 , & V_17 ) ;
if ( error ) {
* V_13 = V_21 ;
goto V_28;
}
ASSERT ( V_17 != NULL ) ;
ASSERT ( V_17 -> V_29 . V_30 != 0 ) ;
V_15 = & V_17 -> V_31 ;
V_18 = F_7 ( V_17 ) ;
V_20 -> V_32 = V_15 -> V_33 ;
V_20 -> V_34 = V_15 -> V_35 ;
V_20 -> V_36 = V_15 -> V_37 ;
V_20 -> V_38 = V_2 ;
V_20 -> V_39 = V_15 -> V_40 ;
V_20 -> V_41 = V_15 -> V_42 ;
V_20 -> V_43 = V_15 -> V_44 ;
V_20 -> V_45 = V_15 -> V_46 ;
V_20 -> V_47 . V_48 = V_18 -> V_49 . V_48 ;
V_20 -> V_47 . V_50 = V_18 -> V_49 . V_50 ;
V_20 -> V_51 . V_48 = V_18 -> V_52 . V_48 ;
V_20 -> V_51 . V_50 = V_18 -> V_52 . V_50 ;
V_20 -> V_53 . V_48 = V_18 -> V_54 . V_48 ;
V_20 -> V_53 . V_50 = V_18 -> V_54 . V_50 ;
V_20 -> V_55 = F_8 ( V_17 ) ;
V_20 -> V_56 = V_15 -> V_57 << V_1 -> V_3 . V_58 ;
V_20 -> V_59 = V_15 -> V_60 ;
V_20 -> V_61 = V_15 -> V_62 ;
memset ( V_20 -> V_63 , 0 , sizeof( V_20 -> V_63 ) ) ;
V_20 -> V_64 = V_15 -> V_65 ;
V_20 -> V_66 = V_15 -> V_67 ;
V_20 -> V_68 = V_15 -> V_69 ;
V_20 -> V_70 = F_9 ( V_17 ) ;
switch ( V_15 -> V_71 ) {
case V_72 :
V_20 -> V_73 = V_17 -> V_74 . V_75 . V_76 ;
V_20 -> V_77 = V_78 ;
V_20 -> V_79 = 0 ;
break;
case V_80 :
case V_81 :
V_20 -> V_73 = 0 ;
V_20 -> V_77 = V_1 -> V_3 . V_82 ;
V_20 -> V_79 = 0 ;
break;
case V_83 :
case V_84 :
V_20 -> V_73 = 0 ;
V_20 -> V_77 = V_1 -> V_3 . V_82 ;
V_20 -> V_79 = V_15 -> V_85 + V_17 -> V_86 ;
break;
}
F_10 ( V_17 , V_27 ) ;
F_11 ( V_17 ) ;
error = V_11 ( V_9 , V_10 , V_12 , V_20 ) ;
if ( ! error )
* V_13 = V_87 ;
V_28:
F_12 ( V_20 ) ;
return error ;
}
STATIC int
F_13 (
void T_3 * V_88 ,
int V_10 ,
int * V_12 ,
const T_5 * V_9 )
{
if ( V_10 < sizeof( * V_9 ) )
return F_4 ( V_25 ) ;
if ( F_14 ( V_88 , V_9 , sizeof( * V_9 ) ) )
return F_4 ( V_89 ) ;
if ( V_12 )
* V_12 = sizeof( * V_9 ) ;
return 0 ;
}
int
F_15 (
T_1 * V_1 ,
T_2 V_2 ,
void T_3 * V_9 ,
int V_10 ,
int * V_12 ,
int * V_13 )
{
return F_3 ( V_1 , V_2 , V_9 , V_10 ,
F_13 , V_12 , V_13 ) ;
}
int
F_16 (
T_1 * V_1 ,
T_2 * V_90 ,
int * V_91 ,
T_6 V_11 ,
T_7 V_92 ,
char T_3 * V_88 ,
int * V_93 )
{
T_8 V_94 = 0 ;
T_9 * V_95 ;
T_10 * V_96 ;
T_11 V_97 ;
T_12 V_98 ;
int V_99 ;
int V_100 ;
T_13 * V_101 ;
int V_102 ;
int error ;
int V_103 ;
int V_104 ;
int V_105 ;
T_7 V_106 ;
T_2 V_2 ;
T_14 * V_107 ;
T_14 * V_108 ;
T_14 * V_109 ;
T_2 V_110 ;
int V_111 ;
int V_112 ;
int V_113 ;
int V_114 ;
int V_115 ;
int V_116 ;
int V_117 ;
int V_118 ;
char T_3 * V_119 ;
int V_120 ;
int V_12 ;
T_9 * V_121 ;
V_2 = ( T_2 ) * V_90 ;
V_110 = V_2 ;
V_98 = F_17 ( V_1 , V_2 ) ;
V_97 = F_18 ( V_1 , V_2 ) ;
if ( V_98 >= V_1 -> V_3 . V_122 ||
V_2 != F_19 ( V_1 , V_98 , V_97 ) ) {
* V_93 = 1 ;
* V_91 = 0 ;
return 0 ;
}
if ( ! V_91 || * V_91 <= 0 ) {
return V_22 ;
}
V_117 = * V_91 ;
V_118 = V_117 * V_92 ;
* V_91 = V_120 = 0 ;
* V_93 = 0 ;
V_103 = 0 ;
V_119 = V_88 ;
V_112 = V_1 -> V_3 . V_82 >= F_20 ( V_1 ) ?
V_1 -> V_3 . V_123 :
( F_20 ( V_1 ) >> V_1 -> V_3 . V_124 ) ;
V_113 = ~ ( V_112 - 1 ) ;
V_111 = V_112 >> V_1 -> V_3 . V_125 ;
V_108 = F_21 ( & V_106 , V_126 , V_126 * 4 ) ;
if ( ! V_108 )
return V_25 ;
V_114 = V_106 / sizeof( * V_108 ) ;
V_115 = 0 ;
while ( F_22 ( V_118 ) && V_98 < V_1 -> V_3 . V_122 ) {
F_23 () ;
V_121 = NULL ;
error = F_24 ( V_1 , NULL , V_98 , & V_95 ) ;
if ( error ) {
V_98 ++ ;
V_97 = 0 ;
continue;
}
V_96 = F_25 ( V_95 ) ;
V_101 = F_26 ( V_1 , NULL , V_95 , V_98 ) ;
V_107 = V_108 ;
V_109 = V_108 + V_114 ;
V_102 = 0 ;
if ( V_97 > 0 ) {
T_14 V_127 ;
error = F_27 ( V_101 , V_97 , V_128 ,
& V_116 ) ;
if ( ! error &&
V_116 &&
! ( error = F_28 ( V_101 , & V_127 , & V_104 ) ) &&
V_104 == 1 &&
V_97 < V_127 . V_129 + V_130 &&
( V_99 = V_97 - V_127 . V_129 + 1 ) <
V_130 &&
F_29 ( V_99 ,
V_130 - V_99 ) &
~ V_127 . V_131 ) {
for ( V_104 = 0 ; V_104 < V_99 ; V_104 ++ ) {
if ( F_30 ( V_104 ) & ~ V_127 . V_131 )
V_127 . V_132 ++ ;
}
V_127 . V_131 |= F_29 ( 0 , V_99 ) ;
V_107 -> V_129 = V_127 . V_129 ;
V_107 -> V_132 = V_127 . V_132 ;
V_107 -> V_131 = V_127 . V_131 ;
V_107 ++ ;
V_97 = V_127 . V_129 + V_130 ;
V_105 = V_130 - V_127 . V_132 ;
} else {
V_97 ++ ;
V_105 = 0 ;
}
if ( ! error )
error = F_31 ( V_101 , 0 , & V_116 ) ;
} else {
error = F_27 ( V_101 , 0 , V_133 , & V_116 ) ;
V_105 = 0 ;
}
while ( V_107 < V_109 && V_105 < V_117 ) {
T_14 V_127 ;
while ( error ) {
V_97 += V_130 ;
if ( F_32 ( V_1 , V_97 ) >=
F_33 ( V_96 -> V_134 ) )
break;
error = F_27 ( V_101 , V_97 ,
V_133 , & V_116 ) ;
F_23 () ;
}
if ( error ) {
V_102 = 1 ;
break;
}
error = F_28 ( V_101 , & V_127 , & V_104 ) ;
if ( error || V_104 == 0 ) {
V_102 = 1 ;
break;
}
if ( V_127 . V_132 < V_130 ) {
V_94 = F_32 ( V_1 , V_127 . V_129 ) ;
for ( V_99 = 0 ;
V_99 < V_130 ;
V_99 += V_112 ,
V_94 += V_111 ) {
if ( F_29 ( V_99 , V_112 )
& ~ V_127 . V_131 )
F_34 ( V_1 , V_98 ,
V_94 , V_111 ) ;
}
V_107 -> V_129 = V_127 . V_129 ;
V_107 -> V_132 = V_127 . V_132 ;
V_107 -> V_131 = V_127 . V_131 ;
V_107 ++ ;
V_105 += V_130 - V_127 . V_132 ;
}
V_97 = V_127 . V_129 + V_130 ;
error = F_31 ( V_101 , 0 , & V_116 ) ;
F_23 () ;
}
F_35 ( V_101 , V_135 ) ;
F_36 ( V_95 ) ;
V_109 = V_107 ;
for ( V_107 = V_108 ;
V_107 < V_109 && F_22 ( V_118 ) ; V_107 ++ ) {
for ( V_97 = V_107 -> V_129 , V_99 = V_100 = 0 ;
F_22 ( V_118 ) &&
V_107 -> V_132 < V_130 ;
V_99 ++ , V_100 ++ , V_97 ++ ) {
ASSERT ( V_99 < V_130 ) ;
if ( ( V_99 & ( V_112 - 1 ) ) == 0 ) {
V_94 = F_32 ( V_1 ,
V_107 -> V_129 ) +
( ( V_99 & V_113 ) >>
V_1 -> V_3 . V_125 ) ;
}
V_2 = F_19 ( V_1 , V_98 , V_97 ) ;
if ( F_30 ( V_99 ) & V_107 -> V_131 ) {
V_110 = V_2 ;
continue;
}
V_107 -> V_132 ++ ;
V_12 = V_92 ;
error = V_11 ( V_1 , V_2 , V_119 , V_118 ,
& V_12 , & V_103 ) ;
if ( V_103 == V_21 ) {
if ( error && error != V_136 &&
error != V_22 ) {
V_118 = 0 ;
V_115 = error ;
break;
}
V_110 = V_2 ;
continue;
}
if ( V_103 == V_137 ) {
V_118 = 0 ;
ASSERT ( error ) ;
V_115 = error ;
break;
}
if ( V_119 )
V_119 += V_12 ;
V_118 -= V_12 ;
V_120 ++ ;
V_110 = V_2 ;
}
F_23 () ;
}
if ( V_121 )
F_36 ( V_121 ) ;
if ( F_22 ( V_118 ) ) {
if ( V_102 ) {
V_98 ++ ;
V_97 = 0 ;
} else
V_97 = F_18 ( V_1 , V_110 ) ;
} else
break;
}
F_37 ( V_108 ) ;
* V_91 = V_120 ;
if ( V_120 )
V_115 = 0 ;
if ( V_98 >= V_1 -> V_3 . V_122 ) {
* V_90 = ( T_2 ) F_19 ( V_1 , V_98 , 0 ) ;
* V_93 = 1 ;
} else
* V_90 = ( T_2 ) V_110 ;
return V_115 ;
}
int
F_38 (
T_1 * V_1 ,
T_2 * V_90 ,
char T_3 * V_9 ,
int * V_93 )
{
int V_138 ;
int error ;
T_2 V_2 ;
int V_139 ;
V_2 = ( T_2 ) * V_90 ;
error = F_15 ( V_1 , V_2 , V_9 , sizeof( T_5 ) , 0 , & V_139 ) ;
if ( error ) {
( * V_90 ) -- ;
V_138 = 1 ;
if ( F_16 ( V_1 , V_90 , & V_138 , F_15 ,
sizeof( T_5 ) , V_9 , V_93 ) )
return error ;
if ( V_138 == 0 || ( T_2 ) * V_90 != V_2 )
return error == V_140 ?
F_4 ( V_22 ) : error ;
else
return 0 ;
}
* V_93 = 0 ;
return 0 ;
}
int
F_39 (
void T_3 * V_88 ,
const T_15 * V_9 ,
long V_138 ,
long * V_141 )
{
if ( F_14 ( V_88 , V_9 , V_138 * sizeof( * V_9 ) ) )
return - V_89 ;
* V_141 = V_138 * sizeof( * V_9 ) ;
return 0 ;
}
int
F_40 (
T_1 * V_1 ,
T_2 * V_110 ,
int * V_138 ,
void T_3 * V_88 ,
T_16 V_11 )
{
T_9 * V_95 ;
T_11 V_97 ;
T_12 V_98 ;
int V_142 ;
T_15 * V_9 ;
int V_143 ;
T_13 * V_101 ;
int error ;
T_14 V_127 ;
int V_104 ;
T_2 V_2 ;
int V_144 ;
int V_116 ;
V_2 = ( T_2 ) * V_110 ;
V_98 = F_17 ( V_1 , V_2 ) ;
V_97 = F_18 ( V_1 , V_2 ) ;
V_144 = * V_138 ;
* V_138 = 0 ;
V_142 = F_41 ( V_144 , ( int ) ( V_126 / sizeof( * V_9 ) ) ) ;
V_9 = F_5 ( V_142 * sizeof( * V_9 ) , V_23 ) ;
error = V_143 = 0 ;
V_101 = NULL ;
V_95 = NULL ;
while ( V_144 > 0 && V_98 < V_1 -> V_3 . V_122 ) {
if ( V_95 == NULL ) {
error = F_24 ( V_1 , NULL , V_98 , & V_95 ) ;
if ( error ) {
ASSERT ( V_101 == NULL ) ;
V_95 = NULL ;
V_98 ++ ;
V_97 = 0 ;
continue;
}
V_101 = F_26 ( V_1 , NULL , V_95 , V_98 ) ;
error = F_27 ( V_101 , V_97 , V_133 ,
& V_116 ) ;
if ( error ) {
F_35 ( V_101 , V_145 ) ;
V_101 = NULL ;
F_36 ( V_95 ) ;
V_95 = NULL ;
V_97 += V_130 - 1 ;
continue;
}
}
error = F_28 ( V_101 , & V_127 , & V_104 ) ;
if ( error || V_104 == 0 ) {
F_36 ( V_95 ) ;
V_95 = NULL ;
F_35 ( V_101 , V_135 ) ;
V_101 = NULL ;
V_98 ++ ;
V_97 = 0 ;
continue;
}
V_97 = V_127 . V_129 + V_130 - 1 ;
V_9 [ V_143 ] . V_146 =
F_19 ( V_1 , V_98 , V_127 . V_129 ) ;
V_9 [ V_143 ] . V_147 =
V_130 - V_127 . V_132 ;
V_9 [ V_143 ] . V_148 = ~ V_127 . V_131 ;
V_143 ++ ;
V_144 -- ;
if ( V_143 == V_142 ) {
long V_141 ;
if ( V_11 ( V_88 , V_9 , V_143 , & V_141 ) ) {
error = F_4 ( V_89 ) ;
break;
}
V_88 += V_141 ;
* V_138 += V_143 ;
V_143 = 0 ;
}
if ( V_144 ) {
error = F_31 ( V_101 , 0 , & V_116 ) ;
if ( error ) {
F_35 ( V_101 , V_145 ) ;
V_101 = NULL ;
F_36 ( V_95 ) ;
V_95 = NULL ;
V_97 += V_130 ;
continue;
}
}
}
if ( ! error ) {
if ( V_143 ) {
long V_141 ;
if ( V_11 ( V_88 , V_9 , V_143 , & V_141 ) )
error = F_4 ( V_89 ) ;
else
* V_138 += V_143 ;
}
* V_110 = F_19 ( V_1 , V_98 , V_97 ) ;
}
F_12 ( V_9 ) ;
if ( V_101 )
F_35 ( V_101 , ( error ? V_145 :
V_135 ) ) ;
if ( V_95 )
F_36 ( V_95 ) ;
return error ;
}
