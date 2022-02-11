STATIC int
F_1 (
T_1 * V_1 ,
char * V_2 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_6 . V_7 ;
int V_8 = V_9 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
int error = 0 ;
error = F_2 ( V_1 , 0 , F_3 ( V_3 , V_5 ) , V_10 , & V_8 ,
0 ) ;
if ( error )
goto V_15;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_6 ( V_3 -> V_18 , V_11 , F_7 ( V_12 ) , 0 ) ;
if ( ! V_14 )
return F_8 ( V_19 ) ;
error = V_14 -> V_20 ;
if ( error ) {
F_9 ( V_14 , V_21 ) ;
F_10 ( V_14 ) ;
goto V_15;
}
if ( V_5 < V_12 )
V_12 = V_5 ;
V_5 -= V_12 ;
memcpy ( V_2 , V_14 -> V_22 , V_12 ) ;
F_10 ( V_14 ) ;
}
V_2 [ V_1 -> V_6 . V_7 ] = '\0' ;
error = 0 ;
V_15:
return error ;
}
int
F_11 (
T_1 * V_1 ,
char * V_2 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_6 V_5 ;
int error = 0 ;
F_12 ( V_1 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
F_14 ( V_1 , V_24 ) ;
V_5 = V_1 -> V_6 . V_7 ;
if ( ! V_5 )
goto V_15;
if ( V_5 < 0 || V_5 > V_25 ) {
F_15 ( V_3 , L_1 ,
V_21 , ( unsigned long long ) V_1 -> V_26 ,
( long long ) V_5 ) ;
ASSERT ( 0 ) ;
error = F_8 ( V_27 ) ;
goto V_15;
}
if ( V_1 -> V_28 . V_29 & V_30 ) {
memcpy ( V_2 , V_1 -> V_28 . V_31 . V_32 , V_5 ) ;
V_2 [ V_5 ] = '\0' ;
} else {
error = F_1 ( V_1 , V_2 ) ;
}
V_15:
F_16 ( V_1 , V_24 ) ;
return error ;
}
STATIC int
F_17 (
T_2 * V_3 ,
T_1 * V_1 ,
bool V_33 )
{
T_7 * V_34 ;
int error ;
T_8 V_35 ;
T_8 V_36 ;
T_9 V_37 ;
int V_38 ;
T_3 V_39 ;
V_35 = F_3 ( V_3 , ( V_40 ) F_18 ( V_1 ) ) ;
V_36 = F_3 ( V_3 , V_3 -> V_41 -> V_42 ) ;
if ( V_36 <= V_35 )
return 0 ;
V_37 = V_36 - V_35 ;
V_38 = 1 ;
F_14 ( V_1 , V_24 ) ;
error = F_2 ( V_1 , V_35 , V_37 , & V_39 , & V_38 , 0 ) ;
F_16 ( V_1 , V_24 ) ;
if ( ! error && ( V_38 != 0 ) &&
( V_39 . V_16 != V_43 ||
V_1 -> V_44 ) ) {
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
V_34 = F_20 ( V_3 , V_45 ) ;
if ( V_33 ) {
if ( ! F_21 ( V_1 , V_46 ) ) {
F_22 ( V_34 , 0 ) ;
return 0 ;
}
}
error = F_23 ( V_34 , 0 ,
F_24 ( V_3 ) ,
0 , V_47 ,
V_48 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
if ( V_33 )
F_16 ( V_1 , V_46 ) ;
return error ;
}
F_14 ( V_1 , V_49 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
error = F_26 ( & V_34 , V_1 , V_50 ,
F_18 ( V_1 ) ) ;
if ( error ) {
F_22 ( V_34 ,
( V_51 |
V_52 ) ) ;
} else {
error = F_27 ( V_34 ,
V_51 ) ;
}
F_16 ( V_1 , V_49 ) ;
if ( V_33 )
F_16 ( V_1 , V_46 ) ;
}
return error ;
}
STATIC int
F_28 (
T_1 * V_1 ,
T_7 * * V_53 )
{
T_5 * V_14 ;
int V_54 ;
int V_55 ;
int error ;
T_10 V_56 ;
T_11 V_57 ;
int V_58 ;
T_2 * V_3 ;
T_3 V_10 [ V_9 ] ;
int V_8 ;
T_7 * V_59 ;
int V_60 ;
T_7 * V_34 ;
V_34 = * V_53 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_7 > F_29 ( V_1 ) ) ;
ASSERT ( V_1 -> V_6 . V_61 > 0 && V_1 -> V_6 . V_61 <= 2 ) ;
V_60 = ( int ) V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_7 = 0 ;
F_30 ( V_34 , V_1 , V_62 ) ;
V_55 = 0 ;
F_31 ( & V_57 , & V_56 ) ;
V_8 = F_32 ( V_10 ) ;
error = F_2 ( V_1 , 0 , F_3 ( V_3 , V_60 ) ,
V_10 , & V_8 , 0 ) ;
if ( error )
goto V_63;
for ( V_58 = 0 ; V_58 < V_8 ; V_58 ++ ) {
V_14 = F_33 ( V_34 , V_3 -> V_18 ,
F_4 ( V_3 , V_10 [ V_58 ] . V_16 ) ,
F_34 ( V_3 , V_10 [ V_58 ] . V_17 ) , 0 ) ;
if ( ! V_14 ) {
error = V_19 ;
goto V_64;
}
F_35 ( V_34 , V_14 ) ;
}
if ( ( error = F_36 ( V_34 , V_1 , 0 , V_60 , V_65 , V_8 ,
& V_56 , & V_57 , & V_55 ) ) )
goto V_64;
ASSERT ( V_55 ) ;
if ( ( error = F_37 ( & V_34 , & V_57 , & V_54 ) ) )
goto V_64;
ASSERT ( V_54 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
F_30 ( V_34 , V_1 , V_62 ) ;
V_59 = F_38 ( V_34 ) ;
error = F_27 ( V_34 , 0 ) ;
V_34 = V_59 ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_63;
}
F_39 ( V_34 -> V_66 ) ;
if ( V_1 -> V_28 . V_67 )
F_40 ( V_1 , - V_1 -> V_28 . V_67 , V_50 ) ;
ASSERT ( V_1 -> V_28 . V_67 == 0 ) ;
if ( ( error = F_23 ( V_34 , 0 , F_24 ( V_3 ) , 0 ,
V_47 , V_48 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_63;
}
F_25 ( V_34 , V_1 , 0 ) ;
* V_53 = V_34 ;
return 0 ;
V_64:
F_41 ( & V_57 ) ;
V_63:
return error ;
}
int
F_42 (
T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
int error ;
if ( ! F_43 ( V_1 -> V_6 . V_68 ) || ( V_1 -> V_6 . V_68 == 0 ) )
return 0 ;
if ( V_3 -> V_69 & V_70 )
return 0 ;
if ( ! F_13 ( V_3 ) ) {
int V_71 ;
if ( ( V_1 -> V_6 . V_72 == 0 ) && F_44 ( V_1 ) )
F_45 ( V_1 ) ;
V_71 = F_46 ( V_1 , V_73 ) ;
if ( V_71 ) {
F_47 ( V_1 , V_74 ) ;
if ( F_48 ( F_49 ( V_1 ) ) && V_1 -> V_44 > 0 )
F_50 ( V_1 , 0 , - 1 , V_75 , V_76 ) ;
}
}
if ( V_1 -> V_6 . V_72 == 0 )
return 0 ;
if ( ( F_43 ( V_1 -> V_6 . V_68 ) &&
( F_49 ( V_1 ) -> V_77 > 0 ||
( F_51 ( F_49 ( V_1 ) ) > 0 || V_1 -> V_44 > 0 ) ) &&
( V_1 -> V_28 . V_29 & V_78 ) ) &&
( ! ( V_1 -> V_6 . V_79 & ( V_80 | V_81 ) ) ) ) {
if ( F_52 ( V_1 , V_74 ) )
return 0 ;
error = F_17 ( V_3 , V_1 , true ) ;
if ( error )
return error ;
if ( V_1 -> V_44 )
F_53 ( V_1 , V_74 ) ;
}
return 0 ;
}
int
F_54 (
T_1 * V_1 )
{
T_11 V_57 ;
T_10 V_56 ;
int V_54 ;
T_7 * V_34 ;
T_2 * V_3 ;
int error ;
int V_82 = 0 ;
if ( V_1 -> V_6 . V_68 == 0 || F_55 ( F_49 ( V_1 ) ) ) {
ASSERT ( V_1 -> V_28 . V_83 == 0 ) ;
ASSERT ( V_1 -> V_28 . V_84 == 0 ) ;
return V_85 ;
}
V_3 = V_1 -> V_4 ;
error = 0 ;
if ( V_3 -> V_69 & V_70 )
goto V_15;
if ( V_1 -> V_6 . V_72 != 0 ) {
if ( ( F_43 ( V_1 -> V_6 . V_68 ) &&
( F_49 ( V_1 ) -> V_77 > 0 ||
( F_51 ( F_49 ( V_1 ) ) > 0 || V_1 -> V_44 > 0 ) ) &&
( V_1 -> V_28 . V_29 & V_78 ) &&
( ! ( V_1 -> V_6 . V_79 &
( V_80 | V_81 ) ) ||
V_1 -> V_44 != 0 ) ) ) {
error = F_17 ( V_3 , V_1 , false ) ;
if ( error )
return V_85 ;
}
goto V_15;
}
if ( F_43 ( V_1 -> V_6 . V_68 ) &&
( V_1 -> V_6 . V_7 != 0 || F_18 ( V_1 ) != 0 ||
V_1 -> V_6 . V_61 > 0 || V_1 -> V_44 > 0 ) )
V_82 = 1 ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return V_85 ;
V_34 = F_20 ( V_3 , V_45 ) ;
error = F_23 ( V_34 , 0 ,
( V_82 || F_56 ( V_1 -> V_6 . V_68 ) ) ?
F_24 ( V_3 ) :
F_57 ( V_3 ) ,
0 ,
V_47 ,
V_48 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
return V_85 ;
}
F_14 ( V_1 , V_49 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
if ( F_56 ( V_1 -> V_6 . V_68 ) ) {
if ( V_1 -> V_6 . V_7 > F_29 ( V_1 ) ) {
error = F_28 ( V_1 , & V_34 ) ;
if ( error )
goto V_86;
} else if ( V_1 -> V_28 . V_67 > 0 ) {
F_40 ( V_1 , - ( V_1 -> V_28 . V_67 ) ,
V_50 ) ;
ASSERT ( V_1 -> V_28 . V_67 == 0 ) ;
}
} else if ( V_82 ) {
V_1 -> V_6 . V_7 = 0 ;
F_30 ( V_34 , V_1 , V_62 ) ;
error = F_26 ( & V_34 , V_1 , V_50 , 0 ) ;
if ( error )
goto V_86;
ASSERT ( V_1 -> V_6 . V_61 == 0 ) ;
}
if ( V_1 -> V_6 . V_87 > 0 ) {
ASSERT ( V_1 -> V_6 . V_88 != 0 ) ;
error = F_27 ( V_34 , V_51 ) ;
if ( error )
goto V_89;
F_16 ( V_1 , V_49 ) ;
error = F_58 ( V_1 ) ;
if ( error )
goto V_15;
V_34 = F_20 ( V_3 , V_45 ) ;
error = F_23 ( V_34 , 0 ,
F_57 ( V_3 ) ,
0 , V_47 ,
V_90 ) ;
if ( error ) {
F_22 ( V_34 , 0 ) ;
goto V_15;
}
F_14 ( V_1 , V_49 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
}
if ( V_1 -> V_91 )
F_59 ( V_1 , V_92 ) ;
ASSERT ( V_1 -> V_6 . V_87 == 0 ) ;
F_31 ( & V_57 , & V_56 ) ;
error = F_60 ( V_34 , V_1 , & V_57 ) ;
if ( error ) {
if ( ! F_13 ( V_3 ) ) {
F_61 ( V_3 , L_2 ,
V_21 , error ) ;
F_62 ( V_3 , V_93 ) ;
}
F_22 ( V_34 , V_51 | V_52 ) ;
} else {
F_63 ( V_34 , V_1 , V_94 , - 1 ) ;
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error )
F_61 ( V_3 , L_3 ,
V_21 , error ) ;
error = F_27 ( V_34 , V_51 ) ;
if ( error )
F_61 ( V_3 , L_4 ,
V_21 , error ) ;
}
F_64 ( V_1 ) ;
V_89:
F_16 ( V_1 , V_49 ) ;
V_15:
return V_85 ;
V_86:
F_22 ( V_34 , V_51 | V_52 ) ;
goto V_89;
}
int
F_65 (
T_1 * V_95 ,
struct V_96 * V_97 ,
T_1 * * V_98 ,
struct V_96 * V_99 )
{
T_12 V_100 ;
int error ;
T_13 V_101 ;
F_66 ( V_95 , V_97 ) ;
if ( F_13 ( V_95 -> V_4 ) )
return F_8 ( V_23 ) ;
V_101 = F_67 ( V_95 ) ;
error = F_68 ( NULL , V_95 , V_97 , & V_100 , V_99 ) ;
F_69 ( V_95 , V_101 ) ;
if ( error )
goto V_15;
error = F_70 ( V_95 -> V_4 , NULL , V_100 , 0 , 0 , V_98 ) ;
if ( error )
goto V_102;
return 0 ;
V_102:
if ( V_99 )
F_71 ( V_99 -> V_97 ) ;
V_15:
* V_98 = NULL ;
return error ;
}
int
F_72 (
T_1 * V_95 ,
struct V_96 * V_97 ,
T_14 V_103 ,
T_15 V_104 ,
T_1 * * V_98 )
{
int V_105 = F_73 ( V_103 ) ;
struct V_106 * V_3 = V_95 -> V_4 ;
struct V_107 * V_1 = NULL ;
struct V_108 * V_34 = NULL ;
int error ;
T_11 V_57 ;
T_10 V_56 ;
T_16 V_109 = V_110 ;
T_13 V_111 ;
int V_54 ;
T_17 V_112 ;
struct V_113 * V_114 = NULL ;
struct V_113 * V_115 = NULL ;
T_13 V_116 ;
T_13 V_117 ;
T_13 V_118 ;
F_74 ( V_95 , V_97 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
if ( V_95 -> V_6 . V_79 & V_119 )
V_112 = F_75 ( V_95 ) ;
else
V_112 = V_120 ;
error = F_76 ( V_95 , F_77 () , F_78 () , V_112 ,
V_121 | V_122 , & V_114 , & V_115 ) ;
if ( error )
return error ;
if ( V_105 ) {
V_104 = 0 ;
V_116 = F_79 ( V_3 , V_97 -> V_123 ) ;
V_117 = F_80 ( V_3 ) ;
V_118 = V_124 ;
V_34 = F_20 ( V_3 , V_125 ) ;
} else {
V_116 = F_81 ( V_3 , V_97 -> V_123 ) ;
V_117 = F_82 ( V_3 ) ;
V_118 = V_126 ;
V_34 = F_20 ( V_3 , V_127 ) ;
}
V_111 = V_51 ;
error = F_23 ( V_34 , V_116 , V_117 , 0 ,
V_47 , V_118 ) ;
if ( error == V_128 ) {
F_83 ( V_95 ) ;
error = F_23 ( V_34 , V_116 , V_117 , 0 ,
V_47 , V_118 ) ;
}
if ( error == V_128 ) {
V_116 = 0 ;
error = F_23 ( V_34 , 0 , V_117 , 0 ,
V_47 , V_118 ) ;
}
if ( error ) {
V_111 = 0 ;
goto V_129;
}
F_14 ( V_95 , V_49 | V_130 ) ;
V_109 = V_131 ;
F_31 ( & V_57 , & V_56 ) ;
error = F_84 ( V_34 , V_3 , V_114 , V_115 , V_116 , 1 , 0 ) ;
if ( error )
goto V_129;
error = F_85 ( V_34 , V_95 , V_97 , V_116 ) ;
if ( error )
goto V_129;
error = F_86 ( & V_34 , V_95 , V_103 , V_105 ? 2 : 1 , V_104 ,
V_112 , V_116 > 0 , & V_1 , & V_54 ) ;
if ( error ) {
if ( error == V_128 )
goto V_129;
goto V_132;
}
F_25 ( V_34 , V_95 , V_49 ) ;
V_109 = V_110 ;
error = F_87 ( V_34 , V_95 , V_97 , V_1 -> V_26 ,
& V_56 , & V_57 , V_116 ?
V_116 - F_88 ( V_3 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_128 ) ;
goto V_132;
}
F_89 ( V_34 , V_95 , V_133 | V_134 ) ;
F_30 ( V_34 , V_95 , V_62 ) ;
if ( V_105 ) {
error = F_90 ( V_34 , V_1 , V_95 ) ;
if ( error )
goto V_135;
error = F_91 ( V_34 , V_95 ) ;
if ( error )
goto V_135;
}
if ( V_3 -> V_69 & ( V_136 | V_137 ) )
F_92 ( V_34 ) ;
F_93 ( V_34 , V_1 , V_114 , V_115 ) ;
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error )
goto V_135;
error = F_27 ( V_34 , V_51 ) ;
if ( error )
goto V_138;
F_94 ( V_114 ) ;
F_94 ( V_115 ) ;
* V_98 = V_1 ;
return 0 ;
V_135:
F_41 ( & V_57 ) ;
V_132:
V_111 |= V_52 ;
V_129:
F_22 ( V_34 , V_111 ) ;
V_138:
if ( V_1 )
F_95 ( V_1 ) ;
F_94 ( V_114 ) ;
F_94 ( V_115 ) ;
if ( V_109 )
F_16 ( V_95 , V_49 ) ;
return error ;
}
static inline int
F_96 ( int V_101 , int V_139 )
{
if ( V_101 & ( V_140 | V_46 ) )
V_101 |= ( V_139 + V_141 ) << V_142 ;
if ( V_101 & ( V_24 | V_49 ) )
V_101 |= ( V_139 + V_141 ) << V_143 ;
return V_101 ;
}
void
F_97 (
T_1 * * V_144 ,
int V_145 ,
T_13 V_101 )
{
int V_146 = 0 , V_58 , V_147 , V_148 ;
T_18 * V_149 ;
ASSERT ( V_144 && ( V_145 >= 2 ) ) ;
V_148 = 0 ;
V_58 = 0 ;
V_150:
for (; V_58 < V_145 ; V_58 ++ ) {
ASSERT ( V_144 [ V_58 ] ) ;
if ( V_58 && ( V_144 [ V_58 ] == V_144 [ V_58 - 1 ] ) )
continue;
if ( ! V_148 ) {
for ( V_147 = ( V_58 - 1 ) ; V_147 >= 0 && ! V_148 ; V_147 -- ) {
V_149 = ( T_18 * ) V_144 [ V_147 ] -> V_151 ;
if ( V_149 && ( V_149 -> V_152 & V_153 ) ) {
V_148 ++ ;
}
}
}
if ( V_148 ) {
ASSERT ( V_58 != 0 ) ;
if ( ! F_21 ( V_144 [ V_58 ] , F_96 ( V_101 , V_58 ) ) ) {
V_146 ++ ;
for( V_147 = V_58 - 1 ; V_147 >= 0 ; V_147 -- ) {
if ( ( V_147 != ( V_58 - 1 ) ) && V_144 [ V_147 ] ==
V_144 [ V_147 + 1 ] )
continue;
F_16 ( V_144 [ V_147 ] , V_101 ) ;
}
if ( ( V_146 % 5 ) == 0 ) {
F_98 ( 1 ) ;
#ifdef F_99
V_154 ++ ;
#endif
}
V_58 = 0 ;
V_148 = 0 ;
goto V_150;
}
} else {
F_14 ( V_144 [ V_58 ] , F_96 ( V_101 , V_58 ) ) ;
}
}
#ifdef F_99
if ( V_146 ) {
if ( V_146 < 5 ) V_155 ++ ;
else if ( V_146 < 100 ) V_156 ++ ;
else V_157 ++ ;
} else {
V_158 ++ ;
}
#endif
}
void
F_100 (
T_1 * V_159 ,
T_1 * V_160 ,
T_13 V_101 )
{
T_1 * V_161 ;
int V_146 = 0 ;
T_18 * V_149 ;
if ( V_101 & ( V_140 | V_46 ) )
ASSERT ( ( V_101 & ( V_24 | V_49 ) ) == 0 ) ;
ASSERT ( V_159 -> V_26 != V_160 -> V_26 ) ;
if ( V_159 -> V_26 > V_160 -> V_26 ) {
V_161 = V_159 ;
V_159 = V_160 ;
V_160 = V_161 ;
}
V_150:
F_14 ( V_159 , F_96 ( V_101 , 0 ) ) ;
V_149 = ( T_18 * ) V_159 -> V_151 ;
if ( V_149 && ( V_149 -> V_152 & V_153 ) ) {
if ( ! F_21 ( V_160 , F_96 ( V_101 , 1 ) ) ) {
F_16 ( V_159 , V_101 ) ;
if ( ( ++ V_146 % 5 ) == 0 )
F_98 ( 1 ) ;
goto V_150;
}
} else {
F_14 ( V_160 , F_96 ( V_101 , 1 ) ) ;
}
}
int
F_101 (
T_1 * V_95 ,
struct V_96 * V_97 ,
T_1 * V_1 )
{
T_2 * V_3 = V_95 -> V_4 ;
T_7 * V_34 = NULL ;
int V_105 = F_73 ( V_1 -> V_6 . V_68 ) ;
int error = 0 ;
T_11 V_57 ;
T_10 V_56 ;
int V_111 ;
int V_54 ;
int V_162 ;
T_13 V_116 ;
T_13 V_118 ;
F_102 ( V_95 , V_97 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_19 ( V_95 , 0 ) ;
if ( error )
goto V_163;
error = F_19 ( V_1 , 0 ) ;
if ( error )
goto V_163;
if ( V_105 ) {
V_34 = F_20 ( V_3 , V_164 ) ;
V_118 = V_165 ;
} else {
V_34 = F_20 ( V_3 , V_166 ) ;
V_118 = V_167 ;
}
V_111 = V_51 ;
V_116 = F_103 ( V_3 ) ;
error = F_23 ( V_34 , V_116 , F_104 ( V_3 ) , 0 ,
V_47 , V_118 ) ;
if ( error == V_128 ) {
V_116 = 0 ;
error = F_23 ( V_34 , 0 , F_104 ( V_3 ) , 0 ,
V_47 , V_118 ) ;
}
if ( error ) {
ASSERT ( error != V_128 ) ;
V_111 = 0 ;
goto V_129;
}
F_100 ( V_95 , V_1 , V_49 ) ;
F_25 ( V_34 , V_95 , V_49 ) ;
F_25 ( V_34 , V_1 , V_49 ) ;
if ( V_105 ) {
ASSERT ( V_1 -> V_6 . V_72 >= 2 ) ;
if ( V_1 -> V_6 . V_72 != 2 ) {
error = F_8 ( V_168 ) ;
goto V_129;
}
if ( ! F_105 ( V_1 ) ) {
error = F_8 ( V_168 ) ;
goto V_129;
}
}
F_31 ( & V_57 , & V_56 ) ;
error = F_106 ( V_34 , V_95 , V_97 , V_1 -> V_26 ,
& V_56 , & V_57 , V_116 ) ;
if ( error ) {
ASSERT ( error != V_169 ) ;
goto V_135;
}
F_89 ( V_34 , V_95 , V_133 | V_134 ) ;
if ( V_105 ) {
error = F_107 ( V_34 , V_95 ) ;
if ( error )
goto V_135;
error = F_107 ( V_34 , V_1 ) ;
if ( error )
goto V_135;
} else {
F_30 ( V_34 , V_95 , V_62 ) ;
}
error = F_107 ( V_34 , V_1 ) ;
if ( error )
goto V_135;
V_162 = ( V_1 -> V_6 . V_72 == 0 ) ;
if ( V_3 -> V_69 & ( V_136 | V_137 ) )
F_92 ( V_34 ) ;
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error )
goto V_135;
error = F_27 ( V_34 , V_51 ) ;
if ( error )
goto V_163;
if ( ! V_105 && V_162 && F_44 ( V_1 ) )
F_45 ( V_1 ) ;
return 0 ;
V_135:
F_41 ( & V_57 ) ;
V_111 |= V_52 ;
V_129:
F_22 ( V_34 , V_111 ) ;
V_163:
return error ;
}
int
F_108 (
T_1 * V_170 ,
T_1 * V_171 ,
struct V_96 * V_172 )
{
T_2 * V_3 = V_170 -> V_4 ;
T_7 * V_34 ;
int error ;
T_11 V_57 ;
T_10 V_56 ;
int V_111 ;
int V_54 ;
int V_116 ;
F_109 ( V_170 , V_172 ) ;
ASSERT ( ! F_73 ( V_171 -> V_6 . V_68 ) ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_19 ( V_171 , 0 ) ;
if ( error )
goto V_163;
error = F_19 ( V_170 , 0 ) ;
if ( error )
goto V_163;
V_34 = F_20 ( V_3 , V_173 ) ;
V_111 = V_51 ;
V_116 = F_110 ( V_3 , V_172 -> V_123 ) ;
error = F_23 ( V_34 , V_116 , F_111 ( V_3 ) , 0 ,
V_47 , V_174 ) ;
if ( error == V_128 ) {
V_116 = 0 ;
error = F_23 ( V_34 , 0 , F_111 ( V_3 ) , 0 ,
V_47 , V_174 ) ;
}
if ( error ) {
V_111 = 0 ;
goto V_175;
}
F_100 ( V_171 , V_170 , V_49 ) ;
F_25 ( V_34 , V_171 , V_49 ) ;
F_25 ( V_34 , V_170 , V_49 ) ;
if ( F_112 ( ( V_170 -> V_6 . V_79 & V_119 ) &&
( F_75 ( V_170 ) != F_75 ( V_171 ) ) ) ) {
error = F_8 ( V_176 ) ;
goto V_175;
}
error = F_85 ( V_34 , V_170 , V_172 , V_116 ) ;
if ( error )
goto V_175;
F_31 ( & V_57 , & V_56 ) ;
error = F_87 ( V_34 , V_170 , V_172 , V_171 -> V_26 ,
& V_56 , & V_57 , V_116 ) ;
if ( error )
goto V_177;
F_89 ( V_34 , V_170 , V_133 | V_134 ) ;
F_30 ( V_34 , V_170 , V_62 ) ;
error = F_91 ( V_34 , V_171 ) ;
if ( error )
goto V_177;
if ( V_3 -> V_69 & ( V_136 | V_137 ) ) {
F_92 ( V_34 ) ;
}
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error ) {
F_41 ( & V_57 ) ;
goto V_177;
}
return F_27 ( V_34 , V_51 ) ;
V_177:
V_111 |= V_52 ;
V_175:
F_22 ( V_34 , V_111 ) ;
V_163:
return error ;
}
int
F_113 (
T_1 * V_95 ,
struct V_96 * V_178 ,
const char * V_179 ,
T_14 V_103 ,
T_1 * * V_98 )
{
T_2 * V_3 = V_95 -> V_4 ;
T_7 * V_34 ;
T_1 * V_1 ;
int error ;
int V_5 ;
T_11 V_57 ;
T_10 V_56 ;
T_16 V_109 = V_110 ;
T_13 V_111 ;
int V_54 ;
T_8 V_180 ;
T_9 V_181 ;
int V_8 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
const char * V_182 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
T_17 V_112 ;
struct V_113 * V_114 , * V_115 ;
T_13 V_116 ;
* V_98 = NULL ;
error = 0 ;
V_1 = NULL ;
V_34 = NULL ;
F_114 ( V_95 , V_178 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
V_5 = strlen ( V_179 ) ;
if ( V_5 >= V_25 )
return F_8 ( V_183 ) ;
V_114 = V_115 = NULL ;
if ( V_95 -> V_6 . V_79 & V_119 )
V_112 = F_75 ( V_95 ) ;
else
V_112 = V_120 ;
error = F_76 ( V_95 , F_77 () , F_78 () , V_112 ,
V_121 | V_122 , & V_114 , & V_115 ) ;
if ( error )
goto V_163;
V_34 = F_20 ( V_3 , V_184 ) ;
V_111 = V_51 ;
if ( V_5 <= F_115 ( V_3 ) )
V_181 = 0 ;
else
V_181 = F_3 ( V_3 , V_5 ) ;
V_116 = F_116 ( V_3 , V_178 -> V_123 , V_181 ) ;
error = F_23 ( V_34 , V_116 , F_117 ( V_3 ) , 0 ,
V_47 , V_185 ) ;
if ( error == V_128 && V_181 == 0 ) {
V_116 = 0 ;
error = F_23 ( V_34 , 0 , F_117 ( V_3 ) , 0 ,
V_47 , V_185 ) ;
}
if ( error ) {
V_111 = 0 ;
goto V_175;
}
F_14 ( V_95 , V_49 | V_130 ) ;
V_109 = V_131 ;
if ( V_95 -> V_6 . V_79 & V_186 ) {
error = F_8 ( V_187 ) ;
goto V_175;
}
error = F_84 ( V_34 , V_3 , V_114 , V_115 , V_116 , 1 , 0 ) ;
if ( error )
goto V_175;
error = F_85 ( V_34 , V_95 , V_178 , V_116 ) ;
if ( error )
goto V_175;
F_31 ( & V_57 , & V_56 ) ;
error = F_86 ( & V_34 , V_95 , V_188 | ( V_103 & ~ V_189 ) , 1 , 0 ,
V_112 , V_116 > 0 , & V_1 , NULL ) ;
if ( error ) {
if ( error == V_128 )
goto V_175;
goto V_64;
}
F_25 ( V_34 , V_95 , V_49 ) ;
V_109 = V_110 ;
F_93 ( V_34 , V_1 , V_114 , V_115 ) ;
if ( V_116 )
V_116 -= F_88 ( V_3 ) ;
if ( V_5 <= F_29 ( V_1 ) ) {
F_40 ( V_1 , V_5 , V_50 ) ;
memcpy ( V_1 -> V_28 . V_31 . V_32 , V_179 , V_5 ) ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_28 . V_29 &= ~ ( V_78 | V_190 ) ;
V_1 -> V_28 . V_29 |= V_30 ;
V_1 -> V_6 . V_191 = V_192 ;
F_30 ( V_34 , V_1 , V_193 | V_62 ) ;
} else {
V_180 = 0 ;
V_8 = V_9 ;
error = F_118 ( V_34 , V_1 , V_180 , V_181 ,
V_65 , & V_56 , V_116 ,
V_10 , & V_8 , & V_57 ) ;
if ( error )
goto V_194;
if ( V_116 )
V_116 -= V_181 ;
V_1 -> V_6 . V_7 = V_5 ;
F_30 ( V_34 , V_1 , V_62 ) ;
V_182 = V_179 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_33 ( V_34 , V_3 -> V_18 , V_11 ,
F_7 ( V_12 ) , 0 ) ;
if ( ! V_14 ) {
error = V_19 ;
goto V_194;
}
if ( V_5 < V_12 ) {
V_12 = V_5 ;
}
V_5 -= V_12 ;
memcpy ( V_14 -> V_22 , V_182 , V_12 ) ;
V_182 += V_12 ;
F_119 ( V_34 , V_14 , 0 , V_12 - 1 ) ;
}
}
error = F_87 ( V_34 , V_95 , V_178 , V_1 -> V_26 ,
& V_56 , & V_57 , V_116 ) ;
if ( error )
goto V_194;
F_89 ( V_34 , V_95 , V_133 | V_134 ) ;
F_30 ( V_34 , V_95 , V_62 ) ;
if ( V_3 -> V_69 & ( V_136 | V_137 ) ) {
F_92 ( V_34 ) ;
}
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error ) {
goto V_194;
}
error = F_27 ( V_34 , V_51 ) ;
F_94 ( V_114 ) ;
F_94 ( V_115 ) ;
* V_98 = V_1 ;
return 0 ;
V_194:
F_95 ( V_1 ) ;
V_64:
F_41 ( & V_57 ) ;
V_111 |= V_52 ;
V_175:
F_22 ( V_34 , V_111 ) ;
F_94 ( V_114 ) ;
F_94 ( V_115 ) ;
if ( V_109 )
F_16 ( V_95 , V_49 ) ;
V_163:
return error ;
}
int
F_120 (
T_1 * V_1 ,
T_19 V_195 ,
T_20 V_196 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_7 * V_34 ;
int error ;
if ( ! F_121 ( V_197 ) )
return F_8 ( V_187 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
V_34 = F_20 ( V_3 , V_198 ) ;
error = F_23 ( V_34 , 0 , F_122 ( V_3 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_22 ( V_34 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_49 ) ;
F_25 ( V_34 , V_1 , V_49 ) ;
V_1 -> V_6 . V_199 = V_195 ;
V_1 -> V_6 . V_200 = V_196 ;
F_30 ( V_34 , V_1 , V_62 ) ;
error = F_27 ( V_34 , 0 ) ;
return error ;
}
STATIC int
F_123 (
T_1 * V_1 ,
T_21 V_201 ,
T_21 V_123 ,
int V_202 ,
int V_203 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_21 V_204 ;
T_9 V_205 ;
T_9 V_206 ;
T_22 V_207 , V_161 ;
T_8 V_208 ;
T_10 V_209 ;
int V_38 ;
int V_210 ;
int V_211 ;
T_7 * V_34 ;
T_3 V_212 [ 1 ] , * V_213 ;
T_11 V_57 ;
T_13 V_214 , V_116 , V_215 ;
int V_54 ;
int error ;
F_124 ( V_1 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
if ( V_123 <= 0 )
return F_8 ( V_216 ) ;
V_211 = F_125 ( V_1 ) ;
V_207 = F_126 ( V_1 ) ;
V_204 = V_123 ;
V_213 = & V_212 [ 0 ] ;
V_38 = 1 ;
V_208 = F_127 ( V_3 , V_201 ) ;
V_206 = F_3 ( V_3 , V_204 ) ;
while ( V_206 && ! error ) {
T_8 V_217 , V_218 ;
if ( F_112 ( V_207 ) ) {
V_217 = V_208 ;
F_128 ( V_217 , V_207 ) ;
V_217 *= V_207 ;
V_218 = V_208 + V_206 ;
if ( ( V_161 = F_129 ( V_208 , V_207 ) ) )
V_218 += V_161 ;
if ( ( V_161 = F_129 ( V_218 , V_207 ) ) )
V_218 += V_207 - V_161 ;
} else {
V_217 = 0 ;
V_218 = V_206 ;
}
V_116 = F_130 ( T_8 , ( V_218 - V_217 ) , ( V_219 * V_38 ) ) ;
if ( F_112 ( V_211 ) ) {
V_215 = V_214 = V_116 ;
V_215 /= V_3 -> V_220 . V_221 ;
V_116 = F_131 ( V_3 , 0 ) ;
V_210 = V_222 ;
} else {
V_215 = 0 ;
V_116 = V_214 = F_131 ( V_3 , V_116 ) ;
V_210 = V_223 ;
}
V_34 = F_20 ( V_3 , V_224 ) ;
error = F_23 ( V_34 , V_116 ,
F_132 ( V_3 ) , V_215 ,
V_47 ,
V_225 ) ;
if ( error ) {
ASSERT ( error == V_128 || F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
break;
}
F_14 ( V_1 , V_49 ) ;
error = F_133 ( V_34 , V_1 , V_214 ,
0 , V_210 ) ;
if ( error )
goto V_64;
F_25 ( V_34 , V_1 , 0 ) ;
F_31 ( & V_57 , & V_209 ) ;
error = F_118 ( V_34 , V_1 , V_208 ,
V_206 , V_202 , & V_209 ,
0 , V_213 , & V_38 , & V_57 ) ;
if ( error ) {
goto V_63;
}
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error ) {
goto V_63;
}
error = F_27 ( V_34 , V_51 ) ;
F_16 ( V_1 , V_49 ) ;
if ( error ) {
break;
}
V_205 = V_213 -> V_17 ;
if ( V_38 == 0 ) {
error = F_8 ( V_128 ) ;
break;
}
V_208 += V_205 ;
V_206 -= V_205 ;
}
return error ;
V_63:
F_41 ( & V_57 ) ;
F_134 ( V_34 , V_1 , ( long ) V_214 , 0 , V_210 ) ;
V_64:
F_22 ( V_34 , V_51 | V_52 ) ;
F_16 ( V_1 , V_49 ) ;
return error ;
}
STATIC int
F_135 (
T_1 * V_1 ,
T_21 V_226 ,
T_21 V_227 )
{
T_3 V_39 ;
T_8 V_228 ;
T_21 V_229 ;
T_21 V_201 ;
T_5 * V_14 ;
T_2 * V_3 = V_1 -> V_4 ;
int V_230 ;
int error = 0 ;
if ( V_226 >= F_18 ( V_1 ) )
return 0 ;
if ( V_227 > F_18 ( V_1 ) )
V_227 = F_18 ( V_1 ) ;
V_14 = F_136 ( F_125 ( V_1 ) ?
V_3 -> V_231 : V_3 -> V_18 ,
F_7 ( V_3 -> V_220 . V_232 ) , 0 ) ;
if ( ! V_14 )
return F_8 ( V_19 ) ;
F_137 ( V_14 ) ;
for ( V_201 = V_226 ; V_201 <= V_227 ; V_201 = V_229 + 1 ) {
V_228 = F_127 ( V_3 , V_201 ) ;
V_230 = 1 ;
error = F_2 ( V_1 , V_228 , 1 , & V_39 , & V_230 , 0 ) ;
if ( error || V_230 < 1 )
break;
ASSERT ( V_39 . V_17 >= 1 ) ;
ASSERT ( V_39 . V_233 == V_228 ) ;
V_229 = F_5 ( V_3 , V_39 . V_233 + 1 ) - 1 ;
if ( V_229 > V_227 )
V_229 = V_227 ;
if ( V_39 . V_16 == V_43 )
continue;
ASSERT ( V_39 . V_16 != V_234 ) ;
if ( V_39 . V_235 == V_236 )
continue;
F_138 ( V_14 ) ;
F_139 ( V_14 ) ;
F_140 ( V_14 ) ;
F_141 ( V_14 , F_142 ( V_1 , V_39 . V_16 ) ) ;
F_143 ( V_3 , V_14 ) ;
error = F_144 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_5 ) ;
break;
}
memset ( V_14 -> V_22 +
( V_201 - F_5 ( V_3 , V_39 . V_233 ) ) ,
0 , V_229 - V_201 + 1 ) ;
F_138 ( V_14 ) ;
F_145 ( V_14 ) ;
F_146 ( V_14 ) ;
F_143 ( V_3 , V_14 ) ;
error = F_144 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_6 ) ;
break;
}
}
F_147 ( V_14 ) ;
return error ;
}
STATIC int
F_148 (
T_1 * V_1 ,
T_21 V_201 ,
T_21 V_123 ,
int V_203 )
{
int V_54 ;
int V_55 ;
T_8 V_237 ;
int error ;
T_10 V_209 ;
T_11 V_57 ;
T_3 V_39 ;
T_21 V_238 ;
T_22 V_239 = 0 ;
T_2 * V_3 ;
int V_230 ;
T_13 V_116 ;
T_13 V_240 ;
int V_211 ;
T_8 V_208 ;
T_7 * V_34 ;
int V_33 = 1 ;
V_3 = V_1 -> V_4 ;
F_149 ( V_1 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_123 <= 0 )
return error ;
V_211 = F_125 ( V_1 ) ;
V_208 = F_3 ( V_3 , V_201 ) ;
V_237 = F_127 ( V_3 , V_201 + V_123 ) ;
if ( V_203 & V_241 )
V_33 = 0 ;
if ( V_33 ) {
F_14 ( V_1 , V_46 ) ;
F_150 ( F_49 ( V_1 ) ) ;
}
V_240 = F_151 ( T_13 , 1 << V_3 -> V_220 . V_242 , V_243 ) ;
V_238 = V_201 & ~ ( V_240 - 1 ) ;
if ( F_51 ( F_49 ( V_1 ) ) != 0 ) {
error = F_152 ( V_1 , V_238 , - 1 , V_244 ) ;
if ( error )
goto V_245;
}
if ( V_211 && ! F_153 ( & V_3 -> V_220 ) ) {
V_230 = 1 ;
error = F_2 ( V_1 , V_208 , 1 ,
& V_39 , & V_230 , 0 ) ;
if ( error )
goto V_245;
ASSERT ( V_230 == 0 || V_230 == 1 ) ;
if ( V_230 && V_39 . V_16 != V_43 ) {
T_4 V_246 ;
ASSERT ( V_39 . V_16 != V_234 ) ;
V_246 = V_39 . V_16 ;
V_239 = F_128 ( V_246 , V_3 -> V_220 . V_221 ) ;
if ( V_239 )
V_208 += V_3 -> V_220 . V_221 - V_239 ;
}
V_230 = 1 ;
error = F_2 ( V_1 , V_237 - 1 , 1 ,
& V_39 , & V_230 , 0 ) ;
if ( error )
goto V_245;
ASSERT ( V_230 == 0 || V_230 == 1 ) ;
if ( V_230 && V_39 . V_16 != V_43 ) {
ASSERT ( V_39 . V_16 != V_234 ) ;
V_239 ++ ;
if ( V_239 && ( V_239 != V_3 -> V_220 . V_221 ) )
V_237 -= V_239 ;
}
}
if ( ( V_55 = ( V_237 <= V_208 ) ) )
error = F_135 ( V_1 , V_201 , V_201 + V_123 - 1 ) ;
else {
if ( V_201 < F_5 ( V_3 , V_208 ) )
error = F_135 ( V_1 , V_201 ,
F_5 ( V_3 , V_208 ) - 1 ) ;
if ( ! error &&
F_5 ( V_3 , V_237 ) < V_201 + V_123 )
error = F_135 ( V_1 ,
F_5 ( V_3 , V_237 ) ,
V_201 + V_123 - 1 ) ;
}
V_116 = F_131 ( V_3 , 0 ) ;
while ( ! error && ! V_55 ) {
V_34 = F_20 ( V_3 , V_224 ) ;
V_34 -> V_247 |= V_248 ;
error = F_23 ( V_34 ,
V_116 ,
F_132 ( V_3 ) ,
0 ,
V_47 ,
V_225 ) ;
if ( error ) {
ASSERT ( error == V_128 || F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
break;
}
F_14 ( V_1 , V_49 ) ;
error = F_84 ( V_34 , V_3 ,
V_1 -> V_249 , V_1 -> V_250 ,
V_116 , 0 , V_223 ) ;
if ( error )
goto V_64;
F_25 ( V_34 , V_1 , 0 ) ;
F_31 ( & V_57 , & V_209 ) ;
error = F_36 ( V_34 , V_1 , V_208 ,
V_237 - V_208 ,
0 , 2 , & V_209 , & V_57 , & V_55 ) ;
if ( error ) {
goto V_63;
}
error = F_37 ( & V_34 , & V_57 , & V_54 ) ;
if ( error ) {
goto V_63;
}
error = F_27 ( V_34 , V_51 ) ;
F_16 ( V_1 , V_49 ) ;
}
V_245:
if ( V_33 )
F_16 ( V_1 , V_46 ) ;
return error ;
V_63:
F_41 ( & V_57 ) ;
V_64:
F_22 ( V_34 , V_51 | V_52 ) ;
F_16 ( V_1 , V_33 ? ( V_49 | V_46 ) :
V_49 ) ;
return error ;
}
int
F_154 (
T_1 * V_1 ,
int V_251 ,
T_23 * V_252 ,
T_21 V_201 ,
int V_203 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_253 ;
int error ;
T_6 V_254 ;
int V_255 ;
T_21 V_256 ;
T_21 V_257 ;
T_7 * V_34 ;
struct V_258 V_258 ;
int V_259 ;
if ( ! F_43 ( V_1 -> V_6 . V_68 ) )
return F_8 ( V_216 ) ;
switch ( V_252 -> V_260 ) {
case 0 :
break;
case 1 :
V_252 -> V_261 += V_201 ;
break;
case 2 :
V_252 -> V_261 += F_18 ( V_1 ) ;
break;
default:
return F_8 ( V_216 ) ;
}
V_257 = V_252 -> V_262 > 0 ? V_252 -> V_262 - 1 : V_252 -> V_262 ;
if ( V_252 -> V_261 < 0 ||
V_252 -> V_261 > V_3 -> V_41 -> V_42 ||
V_252 -> V_261 + V_257 < 0 ||
V_252 -> V_261 + V_257 > V_3 -> V_41 -> V_42 )
return F_8 ( V_216 ) ;
V_252 -> V_260 = 0 ;
V_256 = V_252 -> V_261 ;
V_254 = F_18 ( V_1 ) ;
V_255 = V_253 = 0 ;
V_259 = V_263 ;
switch ( V_251 ) {
case V_264 :
V_259 |= V_265 ;
F_155 ( V_1 , V_256 , V_256 + V_252 -> V_262 , 0 ) ;
case V_266 :
case V_267 :
error = F_123 ( V_1 , V_256 , V_252 -> V_262 ,
V_259 , V_203 ) ;
if ( error )
return error ;
V_255 = 1 ;
break;
case V_268 :
case V_269 :
if ( ( error = F_148 ( V_1 , V_256 , V_252 -> V_262 ,
V_203 ) ) )
return error ;
break;
case V_270 :
case V_271 :
case V_272 :
case V_273 :
F_14 ( V_1 , V_46 ) ;
if ( V_256 > V_254 ) {
error = F_123 ( V_1 , V_254 ,
V_256 - V_254 , 0 ,
V_203 | V_241 ) ;
if ( error ) {
F_16 ( V_1 , V_46 ) ;
break;
}
}
V_258 . V_274 = V_275 ;
V_258 . V_276 = V_256 ;
error = F_156 ( V_1 , & V_258 ,
V_203 | V_241 ) ;
F_16 ( V_1 , V_46 ) ;
if ( error )
return error ;
V_253 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_8 ( V_216 ) ;
}
V_34 = F_20 ( V_3 , V_277 ) ;
if ( ( error = F_23 ( V_34 , 0 , F_157 ( V_3 ) ,
0 , 0 , 0 ) ) ) {
F_22 ( V_34 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_49 ) ;
F_25 ( V_34 , V_1 , V_49 ) ;
if ( ( V_203 & V_278 ) == 0 ) {
V_1 -> V_6 . V_68 &= ~ V_279 ;
if ( V_1 -> V_6 . V_68 & V_280 )
V_1 -> V_6 . V_68 &= ~ V_281 ;
F_89 ( V_34 , V_1 , V_133 | V_134 ) ;
}
if ( V_255 )
V_1 -> V_6 . V_79 |= V_80 ;
else if ( V_253 )
V_1 -> V_6 . V_79 &= ~ V_80 ;
F_30 ( V_34 , V_1 , V_62 ) ;
if ( V_203 & V_282 )
F_92 ( V_34 ) ;
return F_27 ( V_34 , 0 ) ;
}
