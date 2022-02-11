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
return F_5 ( V_19 ) ;
V_17 = F_6 ( sizeof( * V_17 ) , V_20 | V_21 ) ;
if ( ! V_17 )
return F_5 ( V_22 ) ;
error = F_7 ( V_1 , NULL , V_2 ,
( V_23 | V_24 ) ,
V_25 , & V_15 ) ;
if ( error ) {
* V_11 = V_18 ;
goto V_26;
}
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
V_17 -> V_55 = F_8 ( V_15 ) ;
V_17 -> V_56 = V_13 -> V_57 << V_1 -> V_3 . V_58 ;
V_17 -> V_59 = V_13 -> V_60 ;
V_17 -> V_61 = V_13 -> V_62 ;
memset ( V_17 -> V_63 , 0 , sizeof( V_17 -> V_63 ) ) ;
V_17 -> V_64 = V_13 -> V_65 ;
V_17 -> V_66 = V_13 -> V_67 ;
V_17 -> V_68 = V_13 -> V_69 ;
V_17 -> V_70 = F_9 ( V_15 ) ;
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
F_10 ( V_15 , V_25 ) ;
F_11 ( V_15 ) ;
error = V_9 ( V_7 , V_8 , V_10 , V_17 ) ;
if ( ! error )
* V_11 = V_87 ;
V_26:
F_12 ( V_17 ) ;
return error ;
}
STATIC int
F_13 (
void T_3 * V_88 ,
int V_8 ,
int * V_10 ,
const T_5 * V_7 )
{
if ( V_8 < sizeof( * V_7 ) )
return F_5 ( V_22 ) ;
if ( F_14 ( V_88 , V_7 , sizeof( * V_7 ) ) )
return F_5 ( V_89 ) ;
if ( V_10 )
* V_10 = sizeof( * V_7 ) ;
return 0 ;
}
int
F_15 (
T_1 * V_1 ,
T_2 V_2 ,
void T_3 * V_7 ,
int V_8 ,
int * V_10 ,
int * V_11 )
{
return F_4 ( V_1 , V_2 , V_7 , V_8 ,
F_13 , V_10 , V_11 ) ;
}
int
F_16 (
T_1 * V_1 ,
T_2 * V_90 ,
int * V_91 ,
T_6 V_9 ,
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
int V_10 ;
V_2 = ( T_2 ) * V_90 ;
V_110 = V_2 ;
V_98 = F_17 ( V_1 , V_2 ) ;
V_97 = F_18 ( V_1 , V_2 ) ;
if ( V_98 >= V_1 -> V_3 . V_121 ||
V_2 != F_19 ( V_1 , V_98 , V_97 ) ) {
* V_93 = 1 ;
* V_91 = 0 ;
return 0 ;
}
if ( ! V_91 || * V_91 <= 0 ) {
return V_19 ;
}
V_117 = * V_91 ;
V_118 = V_117 * V_92 ;
* V_91 = V_120 = 0 ;
* V_93 = 0 ;
V_103 = 0 ;
V_119 = V_88 ;
V_112 = V_1 -> V_3 . V_82 >= F_20 ( V_1 ) ?
V_1 -> V_3 . V_122 :
( F_20 ( V_1 ) >> V_1 -> V_3 . V_123 ) ;
V_113 = ~ ( V_112 - 1 ) ;
V_111 = V_112 >> V_1 -> V_3 . V_124 ;
V_108 = F_21 ( & V_106 , V_125 , V_125 * 4 ) ;
if ( ! V_108 )
return V_22 ;
V_114 = V_106 / sizeof( * V_108 ) ;
V_115 = 0 ;
while ( F_22 ( V_118 ) && V_98 < V_1 -> V_3 . V_121 ) {
F_23 () ;
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
T_14 V_126 ;
error = F_27 ( V_101 , V_97 , V_127 ,
& V_116 ) ;
if ( ! error &&
V_116 &&
! ( error = F_28 ( V_101 , & V_126 , & V_104 ) ) &&
V_104 == 1 &&
V_97 < V_126 . V_128 + V_129 &&
( V_99 = V_97 - V_126 . V_128 + 1 ) <
V_129 &&
F_29 ( V_99 ,
V_129 - V_99 ) &
~ V_126 . V_130 ) {
for ( V_104 = 0 ; V_104 < V_99 ; V_104 ++ ) {
if ( F_30 ( V_104 ) & ~ V_126 . V_130 )
V_126 . V_131 ++ ;
}
V_126 . V_130 |= F_29 ( 0 , V_99 ) ;
V_107 -> V_128 = V_126 . V_128 ;
V_107 -> V_131 = V_126 . V_131 ;
V_107 -> V_130 = V_126 . V_130 ;
V_107 ++ ;
V_97 = V_126 . V_128 + V_129 ;
V_105 = V_129 - V_126 . V_131 ;
} else {
V_97 ++ ;
V_105 = 0 ;
}
if ( ! error )
error = F_31 ( V_101 , 0 , & V_116 ) ;
} else {
error = F_27 ( V_101 , 0 , V_132 , & V_116 ) ;
V_105 = 0 ;
}
while ( V_107 < V_109 && V_105 < V_117 ) {
T_14 V_126 ;
while ( error ) {
V_97 += V_129 ;
if ( F_32 ( V_1 , V_97 ) >=
F_33 ( V_96 -> V_133 ) )
break;
error = F_27 ( V_101 , V_97 ,
V_132 , & V_116 ) ;
F_23 () ;
}
if ( error ) {
V_102 = 1 ;
break;
}
error = F_28 ( V_101 , & V_126 , & V_104 ) ;
if ( error || V_104 == 0 ) {
V_102 = 1 ;
break;
}
if ( V_126 . V_131 < V_129 ) {
struct V_134 V_135 ;
F_34 ( & V_135 ) ;
V_94 = F_32 ( V_1 , V_126 . V_128 ) ;
for ( V_99 = 0 ;
V_99 < V_129 ;
V_99 += V_112 ,
V_94 += V_111 ) {
if ( F_29 ( V_99 , V_112 )
& ~ V_126 . V_130 )
F_35 ( V_1 , V_98 ,
V_94 , V_111 ,
& V_136 ) ;
}
F_36 ( & V_135 ) ;
V_107 -> V_128 = V_126 . V_128 ;
V_107 -> V_131 = V_126 . V_131 ;
V_107 -> V_130 = V_126 . V_130 ;
V_107 ++ ;
V_105 += V_129 - V_126 . V_131 ;
}
V_97 = V_126 . V_128 + V_129 ;
error = F_31 ( V_101 , 0 , & V_116 ) ;
F_23 () ;
}
F_37 ( V_101 , V_137 ) ;
F_38 ( V_95 ) ;
V_109 = V_107 ;
for ( V_107 = V_108 ;
V_107 < V_109 && F_22 ( V_118 ) ; V_107 ++ ) {
for ( V_97 = V_107 -> V_128 , V_99 = V_100 = 0 ;
F_22 ( V_118 ) &&
V_107 -> V_131 < V_129 ;
V_99 ++ , V_100 ++ , V_97 ++ ) {
ASSERT ( V_99 < V_129 ) ;
V_2 = F_19 ( V_1 , V_98 , V_97 ) ;
if ( F_30 ( V_99 ) & V_107 -> V_130 ) {
V_110 = V_2 ;
continue;
}
V_107 -> V_131 ++ ;
V_10 = V_92 ;
error = V_9 ( V_1 , V_2 , V_119 , V_118 ,
& V_10 , & V_103 ) ;
if ( V_103 == V_18 ) {
if ( error && error != V_138 &&
error != V_19 ) {
V_118 = 0 ;
V_115 = error ;
break;
}
V_110 = V_2 ;
continue;
}
if ( V_103 == V_139 ) {
V_118 = 0 ;
ASSERT ( error ) ;
V_115 = error ;
break;
}
if ( V_119 )
V_119 += V_10 ;
V_118 -= V_10 ;
V_120 ++ ;
V_110 = V_2 ;
}
F_23 () ;
}
if ( F_22 ( V_118 ) ) {
if ( V_102 ) {
V_98 ++ ;
V_97 = 0 ;
} else
V_97 = F_18 ( V_1 , V_110 ) ;
} else
break;
}
F_12 ( V_108 ) ;
* V_91 = V_120 ;
if ( V_120 )
V_115 = 0 ;
if ( V_98 >= V_1 -> V_3 . V_121 ) {
* V_90 = ( T_2 ) F_19 ( V_1 , V_98 , 0 ) ;
* V_93 = 1 ;
} else
* V_90 = ( T_2 ) V_110 ;
return V_115 ;
}
int
F_39 (
T_1 * V_1 ,
T_2 * V_90 ,
char T_3 * V_7 ,
int * V_93 )
{
int V_140 ;
int error ;
T_2 V_2 ;
int V_141 ;
V_2 = * V_90 ;
error = F_15 ( V_1 , V_2 , V_7 , sizeof( T_5 ) ,
NULL , & V_141 ) ;
if ( error ) {
( * V_90 ) -- ;
V_140 = 1 ;
if ( F_16 ( V_1 , V_90 , & V_140 , F_15 ,
sizeof( T_5 ) , V_7 , V_93 ) )
return error ;
if ( V_140 == 0 || ( T_2 ) * V_90 != V_2 )
return error == V_142 ?
F_5 ( V_19 ) : error ;
else
return 0 ;
}
* V_93 = 0 ;
return 0 ;
}
int
F_40 (
void T_3 * V_88 ,
const T_15 * V_7 ,
long V_140 ,
long * V_143 )
{
if ( F_14 ( V_88 , V_7 , V_140 * sizeof( * V_7 ) ) )
return - V_89 ;
* V_143 = V_140 * sizeof( * V_7 ) ;
return 0 ;
}
int
F_41 (
T_1 * V_1 ,
T_2 * V_110 ,
int * V_140 ,
void T_3 * V_88 ,
T_16 V_9 )
{
T_9 * V_95 ;
T_11 V_97 ;
T_12 V_98 ;
int V_144 ;
T_15 * V_7 ;
int V_145 ;
T_13 * V_101 ;
int error ;
T_14 V_126 ;
int V_104 ;
T_2 V_2 ;
int V_146 ;
int V_116 ;
V_2 = ( T_2 ) * V_110 ;
V_98 = F_17 ( V_1 , V_2 ) ;
V_97 = F_18 ( V_1 , V_2 ) ;
V_146 = * V_140 ;
* V_140 = 0 ;
V_144 = F_42 ( V_146 , ( int ) ( V_125 / sizeof( * V_7 ) ) ) ;
V_7 = F_6 ( V_144 * sizeof( * V_7 ) , V_20 ) ;
error = V_145 = 0 ;
V_101 = NULL ;
V_95 = NULL ;
while ( V_146 > 0 && V_98 < V_1 -> V_3 . V_121 ) {
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
error = F_27 ( V_101 , V_97 , V_132 ,
& V_116 ) ;
if ( error ) {
F_37 ( V_101 , V_147 ) ;
V_101 = NULL ;
F_38 ( V_95 ) ;
V_95 = NULL ;
V_97 += V_129 - 1 ;
continue;
}
}
error = F_28 ( V_101 , & V_126 , & V_104 ) ;
if ( error || V_104 == 0 ) {
F_38 ( V_95 ) ;
V_95 = NULL ;
F_37 ( V_101 , V_137 ) ;
V_101 = NULL ;
V_98 ++ ;
V_97 = 0 ;
continue;
}
V_97 = V_126 . V_128 + V_129 - 1 ;
V_7 [ V_145 ] . V_148 =
F_19 ( V_1 , V_98 , V_126 . V_128 ) ;
V_7 [ V_145 ] . V_149 =
V_129 - V_126 . V_131 ;
V_7 [ V_145 ] . V_150 = ~ V_126 . V_130 ;
V_145 ++ ;
V_146 -- ;
if ( V_145 == V_144 ) {
long V_143 ;
if ( V_9 ( V_88 , V_7 , V_145 , & V_143 ) ) {
error = F_5 ( V_89 ) ;
break;
}
V_88 += V_143 ;
* V_140 += V_145 ;
V_145 = 0 ;
}
if ( V_146 ) {
error = F_31 ( V_101 , 0 , & V_116 ) ;
if ( error ) {
F_37 ( V_101 , V_147 ) ;
V_101 = NULL ;
F_38 ( V_95 ) ;
V_95 = NULL ;
V_97 += V_129 ;
continue;
}
}
}
if ( ! error ) {
if ( V_145 ) {
long V_143 ;
if ( V_9 ( V_88 , V_7 , V_145 , & V_143 ) )
error = F_5 ( V_89 ) ;
else
* V_140 += V_145 ;
}
* V_110 = F_19 ( V_1 , V_98 , V_97 ) ;
}
F_12 ( V_7 ) ;
if ( V_101 )
F_37 ( V_101 , ( error ? V_147 :
V_137 ) ) ;
if ( V_95 )
F_38 ( V_95 ) ;
return error ;
}
