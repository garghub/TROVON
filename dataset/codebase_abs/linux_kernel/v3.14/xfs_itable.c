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
char T_3 * V_118 ;
int V_119 ;
int V_10 ;
V_2 = ( T_2 ) * V_90 ;
V_110 = V_2 ;
V_98 = F_17 ( V_1 , V_2 ) ;
V_97 = F_18 ( V_1 , V_2 ) ;
if ( V_98 >= V_1 -> V_3 . V_120 ||
V_2 != F_19 ( V_1 , V_98 , V_97 ) ) {
* V_93 = 1 ;
* V_91 = 0 ;
return 0 ;
}
if ( ! V_91 || * V_91 <= 0 ) {
return V_19 ;
}
V_116 = * V_91 ;
V_117 = V_116 * V_92 ;
* V_91 = V_119 = 0 ;
* V_93 = 0 ;
V_103 = 0 ;
V_118 = V_88 ;
V_111 = F_20 ( V_1 ) ;
V_112 = V_111 << V_1 -> V_3 . V_121 ;
V_108 = F_21 ( & V_106 , V_122 , V_122 * 4 ) ;
if ( ! V_108 )
return V_22 ;
V_113 = V_106 / sizeof( * V_108 ) ;
V_114 = 0 ;
while ( F_22 ( V_117 ) && V_98 < V_1 -> V_3 . V_120 ) {
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
V_109 = V_108 + V_113 ;
V_102 = 0 ;
if ( V_97 > 0 ) {
T_14 V_123 ;
error = F_27 ( V_101 , V_97 , V_124 ,
& V_115 ) ;
if ( ! error &&
V_115 &&
! ( error = F_28 ( V_101 , & V_123 , & V_104 ) ) &&
V_104 == 1 &&
V_97 < V_123 . V_125 + V_126 &&
( V_99 = V_97 - V_123 . V_125 + 1 ) <
V_126 &&
F_29 ( V_99 ,
V_126 - V_99 ) &
~ V_123 . V_127 ) {
for ( V_104 = 0 ; V_104 < V_99 ; V_104 ++ ) {
if ( F_30 ( V_104 ) & ~ V_123 . V_127 )
V_123 . V_128 ++ ;
}
V_123 . V_127 |= F_29 ( 0 , V_99 ) ;
V_107 -> V_125 = V_123 . V_125 ;
V_107 -> V_128 = V_123 . V_128 ;
V_107 -> V_127 = V_123 . V_127 ;
V_107 ++ ;
V_97 = V_123 . V_125 + V_126 ;
V_105 = V_126 - V_123 . V_128 ;
} else {
V_97 ++ ;
V_105 = 0 ;
}
if ( ! error )
error = F_31 ( V_101 , 0 , & V_115 ) ;
} else {
error = F_27 ( V_101 , 0 , V_129 , & V_115 ) ;
V_105 = 0 ;
}
while ( V_107 < V_109 && V_105 < V_116 ) {
T_14 V_123 ;
while ( error ) {
V_97 += V_126 ;
if ( F_32 ( V_1 , V_97 ) >=
F_33 ( V_96 -> V_130 ) )
break;
error = F_27 ( V_101 , V_97 ,
V_129 , & V_115 ) ;
F_23 () ;
}
if ( error ) {
V_102 = 1 ;
break;
}
error = F_28 ( V_101 , & V_123 , & V_104 ) ;
if ( error || V_104 == 0 ) {
V_102 = 1 ;
break;
}
if ( V_123 . V_128 < V_126 ) {
struct V_131 V_132 ;
F_34 ( & V_132 ) ;
V_94 = F_32 ( V_1 , V_123 . V_125 ) ;
for ( V_99 = 0 ;
V_99 < V_126 ;
V_99 += V_112 ,
V_94 += V_111 ) {
if ( F_29 ( V_99 ,
V_112 ) & ~ V_123 . V_127 )
F_35 ( V_1 , V_98 ,
V_94 , V_111 ,
& V_133 ) ;
}
F_36 ( & V_132 ) ;
V_107 -> V_125 = V_123 . V_125 ;
V_107 -> V_128 = V_123 . V_128 ;
V_107 -> V_127 = V_123 . V_127 ;
V_107 ++ ;
V_105 += V_126 - V_123 . V_128 ;
}
V_97 = V_123 . V_125 + V_126 ;
error = F_31 ( V_101 , 0 , & V_115 ) ;
F_23 () ;
}
F_37 ( V_101 , V_134 ) ;
F_38 ( V_95 ) ;
V_109 = V_107 ;
for ( V_107 = V_108 ;
V_107 < V_109 && F_22 ( V_117 ) ; V_107 ++ ) {
for ( V_97 = V_107 -> V_125 , V_99 = V_100 = 0 ;
F_22 ( V_117 ) &&
V_107 -> V_128 < V_126 ;
V_99 ++ , V_100 ++ , V_97 ++ ) {
ASSERT ( V_99 < V_126 ) ;
V_2 = F_19 ( V_1 , V_98 , V_97 ) ;
if ( F_30 ( V_99 ) & V_107 -> V_127 ) {
V_110 = V_2 ;
continue;
}
V_107 -> V_128 ++ ;
V_10 = V_92 ;
error = V_9 ( V_1 , V_2 , V_118 , V_117 ,
& V_10 , & V_103 ) ;
if ( V_103 == V_18 ) {
if ( error && error != V_135 &&
error != V_19 ) {
V_117 = 0 ;
V_114 = error ;
break;
}
V_110 = V_2 ;
continue;
}
if ( V_103 == V_136 ) {
V_117 = 0 ;
ASSERT ( error ) ;
V_114 = error ;
break;
}
if ( V_118 )
V_118 += V_10 ;
V_117 -= V_10 ;
V_119 ++ ;
V_110 = V_2 ;
}
F_23 () ;
}
if ( F_22 ( V_117 ) ) {
if ( V_102 ) {
V_98 ++ ;
V_97 = 0 ;
} else
V_97 = F_18 ( V_1 , V_110 ) ;
} else
break;
}
F_12 ( V_108 ) ;
* V_91 = V_119 ;
if ( V_119 )
V_114 = 0 ;
if ( V_98 >= V_1 -> V_3 . V_120 ) {
* V_90 = ( T_2 ) F_19 ( V_1 , V_98 , 0 ) ;
* V_93 = 1 ;
} else
* V_90 = ( T_2 ) V_110 ;
return V_114 ;
}
int
F_39 (
T_1 * V_1 ,
T_2 * V_90 ,
char T_3 * V_7 ,
int * V_93 )
{
int V_137 ;
int error ;
T_2 V_2 ;
int V_138 ;
V_2 = * V_90 ;
error = F_15 ( V_1 , V_2 , V_7 , sizeof( T_5 ) ,
NULL , & V_138 ) ;
if ( error ) {
( * V_90 ) -- ;
V_137 = 1 ;
if ( F_16 ( V_1 , V_90 , & V_137 , F_15 ,
sizeof( T_5 ) , V_7 , V_93 ) )
return error ;
if ( V_137 == 0 || ( T_2 ) * V_90 != V_2 )
return error == V_139 ?
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
long V_137 ,
long * V_140 )
{
if ( F_14 ( V_88 , V_7 , V_137 * sizeof( * V_7 ) ) )
return - V_89 ;
* V_140 = V_137 * sizeof( * V_7 ) ;
return 0 ;
}
int
F_41 (
T_1 * V_1 ,
T_2 * V_110 ,
int * V_137 ,
void T_3 * V_88 ,
T_16 V_9 )
{
T_9 * V_95 ;
T_11 V_97 ;
T_12 V_98 ;
int V_141 ;
T_15 * V_7 ;
int V_142 ;
T_13 * V_101 ;
int error ;
T_14 V_123 ;
int V_104 ;
T_2 V_2 ;
int V_143 ;
int V_115 ;
V_2 = ( T_2 ) * V_110 ;
V_98 = F_17 ( V_1 , V_2 ) ;
V_97 = F_18 ( V_1 , V_2 ) ;
V_143 = * V_137 ;
* V_137 = 0 ;
V_141 = F_42 ( V_143 , ( int ) ( V_122 / sizeof( * V_7 ) ) ) ;
V_7 = F_6 ( V_141 * sizeof( * V_7 ) , V_20 ) ;
error = V_142 = 0 ;
V_101 = NULL ;
V_95 = NULL ;
while ( V_143 > 0 && V_98 < V_1 -> V_3 . V_120 ) {
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
error = F_27 ( V_101 , V_97 , V_129 ,
& V_115 ) ;
if ( error ) {
F_37 ( V_101 , V_144 ) ;
V_101 = NULL ;
F_38 ( V_95 ) ;
V_95 = NULL ;
V_97 += V_126 - 1 ;
continue;
}
}
error = F_28 ( V_101 , & V_123 , & V_104 ) ;
if ( error || V_104 == 0 ) {
F_38 ( V_95 ) ;
V_95 = NULL ;
F_37 ( V_101 , V_134 ) ;
V_101 = NULL ;
V_98 ++ ;
V_97 = 0 ;
continue;
}
V_97 = V_123 . V_125 + V_126 - 1 ;
V_7 [ V_142 ] . V_145 =
F_19 ( V_1 , V_98 , V_123 . V_125 ) ;
V_7 [ V_142 ] . V_146 =
V_126 - V_123 . V_128 ;
V_7 [ V_142 ] . V_147 = ~ V_123 . V_127 ;
V_142 ++ ;
V_143 -- ;
if ( V_142 == V_141 ) {
long V_140 ;
if ( V_9 ( V_88 , V_7 , V_142 , & V_140 ) ) {
error = F_5 ( V_89 ) ;
break;
}
V_88 += V_140 ;
* V_137 += V_142 ;
V_142 = 0 ;
}
if ( V_143 ) {
error = F_31 ( V_101 , 0 , & V_115 ) ;
if ( error ) {
F_37 ( V_101 , V_144 ) ;
V_101 = NULL ;
F_38 ( V_95 ) ;
V_95 = NULL ;
V_97 += V_126 ;
continue;
}
}
}
if ( ! error ) {
if ( V_142 ) {
long V_140 ;
if ( V_9 ( V_88 , V_7 , V_142 , & V_140 ) )
error = F_5 ( V_89 ) ;
else
* V_137 += V_142 ;
}
* V_110 = F_19 ( V_1 , V_98 , V_97 ) ;
}
F_12 ( V_7 ) ;
if ( V_101 )
F_37 ( V_101 , ( error ? V_144 :
V_134 ) ) ;
if ( V_95 )
F_38 ( V_95 ) ;
return error ;
}
