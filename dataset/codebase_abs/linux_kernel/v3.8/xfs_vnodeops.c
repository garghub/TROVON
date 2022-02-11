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
V_14 = F_6 ( V_3 -> V_18 , V_11 , F_7 ( V_12 ) , 0 , NULL ) ;
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
int
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
return V_47 ;
}
}
error = F_23 ( V_34 , 0 ,
F_24 ( V_3 ) ,
0 , V_48 ,
V_49 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
if ( V_33 )
F_16 ( V_1 , V_46 ) ;
return error ;
}
F_14 ( V_1 , V_50 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
error = F_26 ( & V_34 , V_1 , V_51 ,
F_18 ( V_1 ) ) ;
if ( error ) {
F_22 ( V_34 ,
( V_52 |
V_53 ) ) ;
} else {
error = F_27 ( V_34 ,
V_52 ) ;
if ( ! error )
F_28 ( V_1 ) ;
}
F_16 ( V_1 , V_50 ) ;
if ( V_33 )
F_16 ( V_1 , V_46 ) ;
}
return error ;
}
STATIC int
F_29 (
T_1 * V_1 ,
T_7 * * V_54 )
{
T_5 * V_14 ;
int V_55 ;
int V_56 ;
int error ;
T_10 V_57 ;
T_11 V_58 ;
int V_59 ;
T_2 * V_3 ;
T_3 V_10 [ V_9 ] ;
int V_8 ;
T_7 * V_60 ;
int V_61 ;
T_7 * V_34 ;
V_34 = * V_54 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ;
ASSERT ( V_1 -> V_6 . V_62 > 0 && V_1 -> V_6 . V_62 <= 2 ) ;
V_61 = ( int ) V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_7 = 0 ;
F_31 ( V_34 , V_1 , V_63 ) ;
V_56 = 0 ;
F_32 ( & V_58 , & V_57 ) ;
V_8 = F_33 ( V_10 ) ;
error = F_2 ( V_1 , 0 , F_3 ( V_3 , V_61 ) ,
V_10 , & V_8 , 0 ) ;
if ( error )
goto V_64;
for ( V_59 = 0 ; V_59 < V_8 ; V_59 ++ ) {
V_14 = F_34 ( V_34 , V_3 -> V_18 ,
F_4 ( V_3 , V_10 [ V_59 ] . V_16 ) ,
F_35 ( V_3 , V_10 [ V_59 ] . V_17 ) , 0 ) ;
if ( ! V_14 ) {
error = V_19 ;
goto V_65;
}
F_36 ( V_34 , V_14 ) ;
}
if ( ( error = F_37 ( V_34 , V_1 , 0 , V_61 , V_66 , V_8 ,
& V_57 , & V_58 , & V_56 ) ) )
goto V_65;
ASSERT ( V_56 ) ;
if ( ( error = F_38 ( & V_34 , & V_58 , & V_55 ) ) )
goto V_65;
ASSERT ( V_55 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
F_31 ( V_34 , V_1 , V_63 ) ;
V_60 = F_39 ( V_34 ) ;
error = F_27 ( V_34 , 0 ) ;
V_34 = V_60 ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_64;
}
F_40 ( V_34 -> V_67 ) ;
if ( V_1 -> V_28 . V_68 )
F_41 ( V_1 , - V_1 -> V_28 . V_68 , V_51 ) ;
ASSERT ( V_1 -> V_28 . V_68 == 0 ) ;
if ( ( error = F_23 ( V_34 , 0 , F_24 ( V_3 ) , 0 ,
V_48 , V_49 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_64;
}
F_25 ( V_34 , V_1 , 0 ) ;
* V_54 = V_34 ;
return 0 ;
V_65:
F_42 ( & V_58 ) ;
V_64:
return error ;
}
int
F_43 (
T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
int error ;
if ( ! F_44 ( V_1 -> V_6 . V_69 ) || ( V_1 -> V_6 . V_69 == 0 ) )
return 0 ;
if ( V_3 -> V_70 & V_71 )
return 0 ;
if ( ! F_13 ( V_3 ) ) {
int V_72 ;
if ( ( V_1 -> V_6 . V_73 == 0 ) && F_45 ( V_1 ) )
F_46 ( V_1 ) ;
V_72 = F_47 ( V_1 , V_74 ) ;
if ( V_72 ) {
F_48 ( V_1 , V_75 ) ;
if ( F_49 ( F_50 ( V_1 ) ) && V_1 -> V_44 > 0 ) {
error = - F_51 ( F_50 ( V_1 ) -> V_76 ) ;
if ( error )
return error ;
}
}
}
if ( V_1 -> V_6 . V_73 == 0 )
return 0 ;
if ( F_52 ( V_1 , false ) ) {
if ( F_53 ( V_1 , V_75 ) )
return 0 ;
error = F_17 ( V_3 , V_1 , true ) ;
if ( error && error != V_47 )
return error ;
if ( V_1 -> V_44 )
F_54 ( V_1 , V_75 ) ;
}
return 0 ;
}
int
F_55 (
T_1 * V_1 )
{
T_11 V_58 ;
T_10 V_57 ;
int V_55 ;
T_7 * V_34 ;
T_2 * V_3 ;
int error ;
int V_77 = 0 ;
if ( V_1 -> V_6 . V_69 == 0 || F_56 ( F_50 ( V_1 ) ) ) {
ASSERT ( V_1 -> V_28 . V_78 == 0 ) ;
ASSERT ( V_1 -> V_28 . V_79 == 0 ) ;
return V_80 ;
}
V_3 = V_1 -> V_4 ;
error = 0 ;
if ( V_3 -> V_70 & V_71 )
goto V_15;
if ( V_1 -> V_6 . V_73 != 0 ) {
if ( F_52 ( V_1 , true ) ) {
error = F_17 ( V_3 , V_1 , false ) ;
if ( error )
return V_80 ;
}
goto V_15;
}
if ( F_44 ( V_1 -> V_6 . V_69 ) &&
( V_1 -> V_6 . V_7 != 0 || F_18 ( V_1 ) != 0 ||
V_1 -> V_6 . V_62 > 0 || V_1 -> V_44 > 0 ) )
V_77 = 1 ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return V_80 ;
V_34 = F_20 ( V_3 , V_45 ) ;
error = F_23 ( V_34 , 0 ,
( V_77 || F_57 ( V_1 -> V_6 . V_69 ) ) ?
F_24 ( V_3 ) :
F_58 ( V_3 ) ,
0 ,
V_48 ,
V_49 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
return V_80 ;
}
F_14 ( V_1 , V_50 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
if ( F_57 ( V_1 -> V_6 . V_69 ) ) {
if ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) {
error = F_29 ( V_1 , & V_34 ) ;
if ( error )
goto V_81;
} else if ( V_1 -> V_28 . V_68 > 0 ) {
F_41 ( V_1 , - ( V_1 -> V_28 . V_68 ) ,
V_51 ) ;
ASSERT ( V_1 -> V_28 . V_68 == 0 ) ;
}
} else if ( V_77 ) {
V_1 -> V_6 . V_7 = 0 ;
F_31 ( V_34 , V_1 , V_63 ) ;
error = F_26 ( & V_34 , V_1 , V_51 , 0 ) ;
if ( error )
goto V_81;
ASSERT ( V_1 -> V_6 . V_62 == 0 ) ;
}
if ( V_1 -> V_6 . V_82 > 0 ) {
ASSERT ( V_1 -> V_6 . V_83 != 0 ) ;
error = F_27 ( V_34 , V_52 ) ;
if ( error )
goto V_84;
F_16 ( V_1 , V_50 ) ;
error = F_59 ( V_1 ) ;
if ( error )
goto V_15;
V_34 = F_20 ( V_3 , V_45 ) ;
error = F_23 ( V_34 , 0 ,
F_58 ( V_3 ) ,
0 , V_48 ,
V_85 ) ;
if ( error ) {
F_22 ( V_34 , 0 ) ;
goto V_15;
}
F_14 ( V_1 , V_50 ) ;
F_25 ( V_34 , V_1 , 0 ) ;
}
if ( V_1 -> V_86 )
F_60 ( V_1 , V_87 ) ;
ASSERT ( V_1 -> V_6 . V_82 == 0 ) ;
F_32 ( & V_58 , & V_57 ) ;
error = F_61 ( V_34 , V_1 , & V_58 ) ;
if ( error ) {
if ( ! F_13 ( V_3 ) ) {
F_62 ( V_3 , L_2 ,
V_21 , error ) ;
F_63 ( V_3 , V_88 ) ;
}
F_22 ( V_34 , V_52 | V_53 ) ;
} else {
F_64 ( V_34 , V_1 , V_89 , - 1 ) ;
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error )
F_62 ( V_3 , L_3 ,
V_21 , error ) ;
error = F_27 ( V_34 , V_52 ) ;
if ( error )
F_62 ( V_3 , L_4 ,
V_21 , error ) ;
}
F_65 ( V_1 ) ;
V_84:
F_16 ( V_1 , V_50 ) ;
V_15:
return V_80 ;
V_81:
F_22 ( V_34 , V_52 | V_53 ) ;
goto V_84;
}
int
F_66 (
T_1 * V_90 ,
struct V_91 * V_92 ,
T_1 * * V_93 ,
struct V_91 * V_94 )
{
T_12 V_95 ;
int error ;
T_13 V_96 ;
F_67 ( V_90 , V_92 ) ;
if ( F_13 ( V_90 -> V_4 ) )
return F_8 ( V_23 ) ;
V_96 = F_68 ( V_90 ) ;
error = F_69 ( NULL , V_90 , V_92 , & V_95 , V_94 ) ;
F_70 ( V_90 , V_96 ) ;
if ( error )
goto V_15;
error = F_71 ( V_90 -> V_4 , NULL , V_95 , 0 , 0 , V_93 ) ;
if ( error )
goto V_97;
return 0 ;
V_97:
if ( V_94 )
F_72 ( V_94 -> V_92 ) ;
V_15:
* V_93 = NULL ;
return error ;
}
int
F_73 (
T_1 * V_90 ,
struct V_91 * V_92 ,
T_14 V_98 ,
T_15 V_99 ,
T_1 * * V_93 )
{
int V_100 = F_74 ( V_98 ) ;
struct V_101 * V_3 = V_90 -> V_4 ;
struct V_102 * V_1 = NULL ;
struct V_103 * V_34 = NULL ;
int error ;
T_11 V_58 ;
T_10 V_57 ;
T_16 V_104 = V_105 ;
T_13 V_106 ;
int V_55 ;
T_17 V_107 ;
struct V_108 * V_109 = NULL ;
struct V_108 * V_110 = NULL ;
T_13 V_111 ;
T_13 V_112 ;
T_13 V_113 ;
F_75 ( V_90 , V_92 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
if ( V_90 -> V_6 . V_114 & V_115 )
V_107 = F_76 ( V_90 ) ;
else
V_107 = V_116 ;
error = F_77 ( V_90 , F_78 () , F_79 () , V_107 ,
V_117 | V_118 , & V_109 , & V_110 ) ;
if ( error )
return error ;
if ( V_100 ) {
V_99 = 0 ;
V_111 = F_80 ( V_3 , V_92 -> V_119 ) ;
V_112 = F_81 ( V_3 ) ;
V_113 = V_120 ;
V_34 = F_20 ( V_3 , V_121 ) ;
} else {
V_111 = F_82 ( V_3 , V_92 -> V_119 ) ;
V_112 = F_83 ( V_3 ) ;
V_113 = V_122 ;
V_34 = F_20 ( V_3 , V_123 ) ;
}
V_106 = V_52 ;
error = F_23 ( V_34 , V_111 , V_112 , 0 ,
V_48 , V_113 ) ;
if ( error == V_124 ) {
F_84 ( V_3 ) ;
error = F_23 ( V_34 , V_111 , V_112 , 0 ,
V_48 , V_113 ) ;
}
if ( error == V_124 ) {
V_111 = 0 ;
error = F_23 ( V_34 , 0 , V_112 , 0 ,
V_48 , V_113 ) ;
}
if ( error ) {
V_106 = 0 ;
goto V_125;
}
F_14 ( V_90 , V_50 | V_126 ) ;
V_104 = V_127 ;
F_32 ( & V_58 , & V_57 ) ;
error = F_85 ( V_34 , V_3 , V_109 , V_110 , V_111 , 1 , 0 ) ;
if ( error )
goto V_125;
error = F_86 ( V_34 , V_90 , V_92 , V_111 ) ;
if ( error )
goto V_125;
error = F_87 ( & V_34 , V_90 , V_98 , V_100 ? 2 : 1 , V_99 ,
V_107 , V_111 > 0 , & V_1 , & V_55 ) ;
if ( error ) {
if ( error == V_124 )
goto V_125;
goto V_128;
}
F_25 ( V_34 , V_90 , V_50 ) ;
V_104 = V_105 ;
error = F_88 ( V_34 , V_90 , V_92 , V_1 -> V_26 ,
& V_57 , & V_58 , V_111 ?
V_111 - F_89 ( V_3 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_124 ) ;
goto V_128;
}
F_90 ( V_34 , V_90 , V_129 | V_130 ) ;
F_31 ( V_34 , V_90 , V_63 ) ;
if ( V_100 ) {
error = F_91 ( V_34 , V_1 , V_90 ) ;
if ( error )
goto V_131;
error = F_92 ( V_34 , V_90 ) ;
if ( error )
goto V_131;
}
if ( V_3 -> V_70 & ( V_132 | V_133 ) )
F_93 ( V_34 ) ;
F_94 ( V_34 , V_1 , V_109 , V_110 ) ;
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error )
goto V_131;
error = F_27 ( V_34 , V_52 ) ;
if ( error )
goto V_134;
F_95 ( V_109 ) ;
F_95 ( V_110 ) ;
* V_93 = V_1 ;
return 0 ;
V_131:
F_42 ( & V_58 ) ;
V_128:
V_106 |= V_53 ;
V_125:
F_22 ( V_34 , V_106 ) ;
V_134:
if ( V_1 )
F_96 ( V_1 ) ;
F_95 ( V_109 ) ;
F_95 ( V_110 ) ;
if ( V_104 )
F_16 ( V_90 , V_50 ) ;
return error ;
}
static inline int
F_97 ( int V_96 , int V_135 )
{
if ( V_96 & ( V_136 | V_46 ) )
V_96 |= ( V_135 + V_137 ) << V_138 ;
if ( V_96 & ( V_24 | V_50 ) )
V_96 |= ( V_135 + V_137 ) << V_139 ;
return V_96 ;
}
void
F_98 (
T_1 * * V_140 ,
int V_141 ,
T_13 V_96 )
{
int V_142 = 0 , V_59 , V_143 , V_144 ;
T_18 * V_145 ;
ASSERT ( V_140 && ( V_141 >= 2 ) ) ;
V_144 = 0 ;
V_59 = 0 ;
V_146:
for (; V_59 < V_141 ; V_59 ++ ) {
ASSERT ( V_140 [ V_59 ] ) ;
if ( V_59 && ( V_140 [ V_59 ] == V_140 [ V_59 - 1 ] ) )
continue;
if ( ! V_144 ) {
for ( V_143 = ( V_59 - 1 ) ; V_143 >= 0 && ! V_144 ; V_143 -- ) {
V_145 = ( T_18 * ) V_140 [ V_143 ] -> V_147 ;
if ( V_145 && ( V_145 -> V_148 & V_149 ) ) {
V_144 ++ ;
}
}
}
if ( V_144 ) {
ASSERT ( V_59 != 0 ) ;
if ( ! F_21 ( V_140 [ V_59 ] , F_97 ( V_96 , V_59 ) ) ) {
V_142 ++ ;
for( V_143 = V_59 - 1 ; V_143 >= 0 ; V_143 -- ) {
if ( ( V_143 != ( V_59 - 1 ) ) && V_140 [ V_143 ] ==
V_140 [ V_143 + 1 ] )
continue;
F_16 ( V_140 [ V_143 ] , V_96 ) ;
}
if ( ( V_142 % 5 ) == 0 ) {
F_99 ( 1 ) ;
#ifdef F_100
V_150 ++ ;
#endif
}
V_59 = 0 ;
V_144 = 0 ;
goto V_146;
}
} else {
F_14 ( V_140 [ V_59 ] , F_97 ( V_96 , V_59 ) ) ;
}
}
#ifdef F_100
if ( V_142 ) {
if ( V_142 < 5 ) V_151 ++ ;
else if ( V_142 < 100 ) V_152 ++ ;
else V_153 ++ ;
} else {
V_154 ++ ;
}
#endif
}
void
F_101 (
T_1 * V_155 ,
T_1 * V_156 ,
T_13 V_96 )
{
T_1 * V_157 ;
int V_142 = 0 ;
T_18 * V_145 ;
if ( V_96 & ( V_136 | V_46 ) )
ASSERT ( ( V_96 & ( V_24 | V_50 ) ) == 0 ) ;
ASSERT ( V_155 -> V_26 != V_156 -> V_26 ) ;
if ( V_155 -> V_26 > V_156 -> V_26 ) {
V_157 = V_155 ;
V_155 = V_156 ;
V_156 = V_157 ;
}
V_146:
F_14 ( V_155 , F_97 ( V_96 , 0 ) ) ;
V_145 = ( T_18 * ) V_155 -> V_147 ;
if ( V_145 && ( V_145 -> V_148 & V_149 ) ) {
if ( ! F_21 ( V_156 , F_97 ( V_96 , 1 ) ) ) {
F_16 ( V_155 , V_96 ) ;
if ( ( ++ V_142 % 5 ) == 0 )
F_99 ( 1 ) ;
goto V_146;
}
} else {
F_14 ( V_156 , F_97 ( V_96 , 1 ) ) ;
}
}
int
F_102 (
T_1 * V_90 ,
struct V_91 * V_92 ,
T_1 * V_1 )
{
T_2 * V_3 = V_90 -> V_4 ;
T_7 * V_34 = NULL ;
int V_100 = F_74 ( V_1 -> V_6 . V_69 ) ;
int error = 0 ;
T_11 V_58 ;
T_10 V_57 ;
int V_106 ;
int V_55 ;
int V_158 ;
T_13 V_111 ;
T_13 V_113 ;
F_103 ( V_90 , V_92 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_19 ( V_90 , 0 ) ;
if ( error )
goto V_159;
error = F_19 ( V_1 , 0 ) ;
if ( error )
goto V_159;
if ( V_100 ) {
V_34 = F_20 ( V_3 , V_160 ) ;
V_113 = V_161 ;
} else {
V_34 = F_20 ( V_3 , V_162 ) ;
V_113 = V_163 ;
}
V_106 = V_52 ;
V_111 = F_104 ( V_3 ) ;
error = F_23 ( V_34 , V_111 , F_105 ( V_3 ) , 0 ,
V_48 , V_113 ) ;
if ( error == V_124 ) {
V_111 = 0 ;
error = F_23 ( V_34 , 0 , F_105 ( V_3 ) , 0 ,
V_48 , V_113 ) ;
}
if ( error ) {
ASSERT ( error != V_124 ) ;
V_106 = 0 ;
goto V_125;
}
F_101 ( V_90 , V_1 , V_50 ) ;
F_25 ( V_34 , V_90 , V_50 ) ;
F_25 ( V_34 , V_1 , V_50 ) ;
if ( V_100 ) {
ASSERT ( V_1 -> V_6 . V_73 >= 2 ) ;
if ( V_1 -> V_6 . V_73 != 2 ) {
error = F_8 ( V_164 ) ;
goto V_125;
}
if ( ! F_106 ( V_1 ) ) {
error = F_8 ( V_164 ) ;
goto V_125;
}
}
F_32 ( & V_58 , & V_57 ) ;
error = F_107 ( V_34 , V_90 , V_92 , V_1 -> V_26 ,
& V_57 , & V_58 , V_111 ) ;
if ( error ) {
ASSERT ( error != V_165 ) ;
goto V_131;
}
F_90 ( V_34 , V_90 , V_129 | V_130 ) ;
if ( V_100 ) {
error = F_108 ( V_34 , V_90 ) ;
if ( error )
goto V_131;
error = F_108 ( V_34 , V_1 ) ;
if ( error )
goto V_131;
} else {
F_31 ( V_34 , V_90 , V_63 ) ;
}
error = F_108 ( V_34 , V_1 ) ;
if ( error )
goto V_131;
V_158 = ( V_1 -> V_6 . V_73 == 0 ) ;
if ( V_3 -> V_70 & ( V_132 | V_133 ) )
F_93 ( V_34 ) ;
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error )
goto V_131;
error = F_27 ( V_34 , V_52 ) ;
if ( error )
goto V_159;
if ( ! V_100 && V_158 && F_45 ( V_1 ) )
F_46 ( V_1 ) ;
return 0 ;
V_131:
F_42 ( & V_58 ) ;
V_106 |= V_53 ;
V_125:
F_22 ( V_34 , V_106 ) ;
V_159:
return error ;
}
int
F_109 (
T_1 * V_166 ,
T_1 * V_167 ,
struct V_91 * V_168 )
{
T_2 * V_3 = V_166 -> V_4 ;
T_7 * V_34 ;
int error ;
T_11 V_58 ;
T_10 V_57 ;
int V_106 ;
int V_55 ;
int V_111 ;
F_110 ( V_166 , V_168 ) ;
ASSERT ( ! F_74 ( V_167 -> V_6 . V_69 ) ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_19 ( V_167 , 0 ) ;
if ( error )
goto V_159;
error = F_19 ( V_166 , 0 ) ;
if ( error )
goto V_159;
V_34 = F_20 ( V_3 , V_169 ) ;
V_106 = V_52 ;
V_111 = F_111 ( V_3 , V_168 -> V_119 ) ;
error = F_23 ( V_34 , V_111 , F_112 ( V_3 ) , 0 ,
V_48 , V_170 ) ;
if ( error == V_124 ) {
V_111 = 0 ;
error = F_23 ( V_34 , 0 , F_112 ( V_3 ) , 0 ,
V_48 , V_170 ) ;
}
if ( error ) {
V_106 = 0 ;
goto V_171;
}
F_101 ( V_167 , V_166 , V_50 ) ;
F_25 ( V_34 , V_167 , V_50 ) ;
F_25 ( V_34 , V_166 , V_50 ) ;
if ( F_113 ( ( V_166 -> V_6 . V_114 & V_115 ) &&
( F_76 ( V_166 ) != F_76 ( V_167 ) ) ) ) {
error = F_8 ( V_172 ) ;
goto V_171;
}
error = F_86 ( V_34 , V_166 , V_168 , V_111 ) ;
if ( error )
goto V_171;
F_32 ( & V_58 , & V_57 ) ;
error = F_88 ( V_34 , V_166 , V_168 , V_167 -> V_26 ,
& V_57 , & V_58 , V_111 ) ;
if ( error )
goto V_173;
F_90 ( V_34 , V_166 , V_129 | V_130 ) ;
F_31 ( V_34 , V_166 , V_63 ) ;
error = F_92 ( V_34 , V_167 ) ;
if ( error )
goto V_173;
if ( V_3 -> V_70 & ( V_132 | V_133 ) ) {
F_93 ( V_34 ) ;
}
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error ) {
F_42 ( & V_58 ) ;
goto V_173;
}
return F_27 ( V_34 , V_52 ) ;
V_173:
V_106 |= V_53 ;
V_171:
F_22 ( V_34 , V_106 ) ;
V_159:
return error ;
}
int
F_114 (
T_1 * V_90 ,
struct V_91 * V_174 ,
const char * V_175 ,
T_14 V_98 ,
T_1 * * V_93 )
{
T_2 * V_3 = V_90 -> V_4 ;
T_7 * V_34 ;
T_1 * V_1 ;
int error ;
int V_5 ;
T_11 V_58 ;
T_10 V_57 ;
T_16 V_104 = V_105 ;
T_13 V_106 ;
int V_55 ;
T_8 V_176 ;
T_9 V_177 ;
int V_8 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
const char * V_178 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
T_17 V_107 ;
struct V_108 * V_109 , * V_110 ;
T_13 V_111 ;
* V_93 = NULL ;
error = 0 ;
V_1 = NULL ;
V_34 = NULL ;
F_115 ( V_90 , V_174 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
V_5 = strlen ( V_175 ) ;
if ( V_5 >= V_25 )
return F_8 ( V_179 ) ;
V_109 = V_110 = NULL ;
if ( V_90 -> V_6 . V_114 & V_115 )
V_107 = F_76 ( V_90 ) ;
else
V_107 = V_116 ;
error = F_77 ( V_90 , F_78 () , F_79 () , V_107 ,
V_117 | V_118 , & V_109 , & V_110 ) ;
if ( error )
goto V_159;
V_34 = F_20 ( V_3 , V_180 ) ;
V_106 = V_52 ;
if ( V_5 <= F_116 ( V_3 ) )
V_177 = 0 ;
else
V_177 = F_3 ( V_3 , V_5 ) ;
V_111 = F_117 ( V_3 , V_174 -> V_119 , V_177 ) ;
error = F_23 ( V_34 , V_111 , F_118 ( V_3 ) , 0 ,
V_48 , V_181 ) ;
if ( error == V_124 && V_177 == 0 ) {
V_111 = 0 ;
error = F_23 ( V_34 , 0 , F_118 ( V_3 ) , 0 ,
V_48 , V_181 ) ;
}
if ( error ) {
V_106 = 0 ;
goto V_171;
}
F_14 ( V_90 , V_50 | V_126 ) ;
V_104 = V_127 ;
if ( V_90 -> V_6 . V_114 & V_182 ) {
error = F_8 ( V_183 ) ;
goto V_171;
}
error = F_85 ( V_34 , V_3 , V_109 , V_110 , V_111 , 1 , 0 ) ;
if ( error )
goto V_171;
error = F_86 ( V_34 , V_90 , V_174 , V_111 ) ;
if ( error )
goto V_171;
F_32 ( & V_58 , & V_57 ) ;
error = F_87 ( & V_34 , V_90 , V_184 | ( V_98 & ~ V_185 ) , 1 , 0 ,
V_107 , V_111 > 0 , & V_1 , NULL ) ;
if ( error ) {
if ( error == V_124 )
goto V_171;
goto V_65;
}
F_25 ( V_34 , V_90 , V_50 ) ;
V_104 = V_105 ;
F_94 ( V_34 , V_1 , V_109 , V_110 ) ;
if ( V_111 )
V_111 -= F_89 ( V_3 ) ;
if ( V_5 <= F_30 ( V_1 ) ) {
F_41 ( V_1 , V_5 , V_51 ) ;
memcpy ( V_1 -> V_28 . V_31 . V_32 , V_175 , V_5 ) ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_28 . V_29 &= ~ ( V_186 | V_187 ) ;
V_1 -> V_28 . V_29 |= V_30 ;
V_1 -> V_6 . V_188 = V_189 ;
F_31 ( V_34 , V_1 , V_190 | V_63 ) ;
} else {
V_176 = 0 ;
V_8 = V_9 ;
error = F_119 ( V_34 , V_1 , V_176 , V_177 ,
V_66 , & V_57 , V_111 ,
V_10 , & V_8 , & V_58 ) ;
if ( error )
goto V_191;
if ( V_111 )
V_111 -= V_177 ;
V_1 -> V_6 . V_7 = V_5 ;
F_31 ( V_34 , V_1 , V_63 ) ;
V_178 = V_175 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_34 ( V_34 , V_3 -> V_18 , V_11 ,
F_7 ( V_12 ) , 0 ) ;
if ( ! V_14 ) {
error = V_19 ;
goto V_191;
}
if ( V_5 < V_12 ) {
V_12 = V_5 ;
}
V_5 -= V_12 ;
memcpy ( V_14 -> V_22 , V_178 , V_12 ) ;
V_178 += V_12 ;
F_120 ( V_34 , V_14 , 0 , V_12 - 1 ) ;
}
}
error = F_88 ( V_34 , V_90 , V_174 , V_1 -> V_26 ,
& V_57 , & V_58 , V_111 ) ;
if ( error )
goto V_191;
F_90 ( V_34 , V_90 , V_129 | V_130 ) ;
F_31 ( V_34 , V_90 , V_63 ) ;
if ( V_3 -> V_70 & ( V_132 | V_133 ) ) {
F_93 ( V_34 ) ;
}
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error ) {
goto V_191;
}
error = F_27 ( V_34 , V_52 ) ;
F_95 ( V_109 ) ;
F_95 ( V_110 ) ;
* V_93 = V_1 ;
return 0 ;
V_191:
F_96 ( V_1 ) ;
V_65:
F_42 ( & V_58 ) ;
V_106 |= V_53 ;
V_171:
F_22 ( V_34 , V_106 ) ;
F_95 ( V_109 ) ;
F_95 ( V_110 ) ;
if ( V_104 )
F_16 ( V_90 , V_50 ) ;
V_159:
return error ;
}
int
F_121 (
T_1 * V_1 ,
T_19 V_192 ,
T_20 V_193 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_7 * V_34 ;
int error ;
if ( ! F_122 ( V_194 ) )
return F_8 ( V_183 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
V_34 = F_20 ( V_3 , V_195 ) ;
error = F_23 ( V_34 , 0 , F_123 ( V_3 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_22 ( V_34 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_50 ) ;
F_25 ( V_34 , V_1 , V_50 ) ;
V_1 -> V_6 . V_196 = V_192 ;
V_1 -> V_6 . V_197 = V_193 ;
F_31 ( V_34 , V_1 , V_63 ) ;
error = F_27 ( V_34 , 0 ) ;
return error ;
}
STATIC int
F_124 (
T_1 * V_1 ,
T_21 V_198 ,
T_21 V_119 ,
int V_199 ,
int V_200 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_21 V_201 ;
T_9 V_202 ;
T_9 V_203 ;
T_22 V_204 , V_157 ;
T_8 V_205 ;
T_10 V_206 ;
int V_38 ;
int V_207 ;
int V_208 ;
T_7 * V_34 ;
T_3 V_209 [ 1 ] , * V_210 ;
T_11 V_58 ;
T_13 V_211 , V_111 , V_212 ;
int V_55 ;
int error ;
F_125 ( V_1 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
if ( V_119 <= 0 )
return F_8 ( V_213 ) ;
V_208 = F_126 ( V_1 ) ;
V_204 = F_127 ( V_1 ) ;
V_201 = V_119 ;
V_210 = & V_209 [ 0 ] ;
V_38 = 1 ;
V_205 = F_128 ( V_3 , V_198 ) ;
V_203 = F_3 ( V_3 , V_201 ) ;
while ( V_203 && ! error ) {
T_8 V_214 , V_215 ;
if ( F_113 ( V_204 ) ) {
V_214 = V_205 ;
F_129 ( V_214 , V_204 ) ;
V_214 *= V_204 ;
V_215 = V_205 + V_203 ;
if ( ( V_157 = F_130 ( V_205 , V_204 ) ) )
V_215 += V_157 ;
if ( ( V_157 = F_130 ( V_215 , V_204 ) ) )
V_215 += V_204 - V_157 ;
} else {
V_214 = 0 ;
V_215 = V_203 ;
}
V_111 = F_131 ( T_8 , ( V_215 - V_214 ) , ( V_216 * V_38 ) ) ;
if ( F_113 ( V_208 ) ) {
V_212 = V_211 = V_111 ;
V_212 /= V_3 -> V_217 . V_218 ;
V_111 = F_132 ( V_3 , 0 ) ;
V_207 = V_219 ;
} else {
V_212 = 0 ;
V_111 = V_211 = F_132 ( V_3 , V_111 ) ;
V_207 = V_220 ;
}
V_34 = F_20 ( V_3 , V_221 ) ;
error = F_23 ( V_34 , V_111 ,
F_133 ( V_3 ) , V_212 ,
V_48 ,
V_222 ) ;
if ( error ) {
ASSERT ( error == V_124 || F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
break;
}
F_14 ( V_1 , V_50 ) ;
error = F_134 ( V_34 , V_1 , V_211 ,
0 , V_207 ) ;
if ( error )
goto V_65;
F_25 ( V_34 , V_1 , 0 ) ;
F_32 ( & V_58 , & V_206 ) ;
error = F_119 ( V_34 , V_1 , V_205 ,
V_203 , V_199 , & V_206 ,
0 , V_210 , & V_38 , & V_58 ) ;
if ( error ) {
goto V_64;
}
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error ) {
goto V_64;
}
error = F_27 ( V_34 , V_52 ) ;
F_16 ( V_1 , V_50 ) ;
if ( error ) {
break;
}
V_202 = V_210 -> V_17 ;
if ( V_38 == 0 ) {
error = F_8 ( V_124 ) ;
break;
}
V_205 += V_202 ;
V_203 -= V_202 ;
}
return error ;
V_64:
F_42 ( & V_58 ) ;
F_135 ( V_34 , V_1 , ( long ) V_211 , 0 , V_207 ) ;
V_65:
F_22 ( V_34 , V_52 | V_53 ) ;
F_16 ( V_1 , V_50 ) ;
return error ;
}
STATIC int
F_136 (
T_1 * V_1 ,
T_21 V_223 ,
T_21 V_224 )
{
T_3 V_39 ;
T_8 V_225 ;
T_21 V_226 ;
T_21 V_198 ;
T_5 * V_14 ;
T_2 * V_3 = V_1 -> V_4 ;
int V_227 ;
int error = 0 ;
if ( V_223 >= F_18 ( V_1 ) )
return 0 ;
if ( V_224 > F_18 ( V_1 ) )
V_224 = F_18 ( V_1 ) ;
V_14 = F_137 ( F_126 ( V_1 ) ?
V_3 -> V_228 : V_3 -> V_18 ,
F_7 ( V_3 -> V_217 . V_229 ) , 0 ) ;
if ( ! V_14 )
return F_8 ( V_19 ) ;
F_138 ( V_14 ) ;
for ( V_198 = V_223 ; V_198 <= V_224 ; V_198 = V_226 + 1 ) {
V_225 = F_128 ( V_3 , V_198 ) ;
V_227 = 1 ;
error = F_2 ( V_1 , V_225 , 1 , & V_39 , & V_227 , 0 ) ;
if ( error || V_227 < 1 )
break;
ASSERT ( V_39 . V_17 >= 1 ) ;
ASSERT ( V_39 . V_230 == V_225 ) ;
V_226 = F_5 ( V_3 , V_39 . V_230 + 1 ) - 1 ;
if ( V_226 > V_224 )
V_226 = V_224 ;
if ( V_39 . V_16 == V_43 )
continue;
ASSERT ( V_39 . V_16 != V_231 ) ;
if ( V_39 . V_232 == V_233 )
continue;
F_139 ( V_14 ) ;
F_140 ( V_14 ) ;
F_141 ( V_14 ) ;
F_142 ( V_14 , F_143 ( V_1 , V_39 . V_16 ) ) ;
F_144 ( V_3 , V_14 ) ;
error = F_145 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_5 ) ;
break;
}
memset ( V_14 -> V_22 +
( V_198 - F_5 ( V_3 , V_39 . V_230 ) ) ,
0 , V_226 - V_198 + 1 ) ;
F_139 ( V_14 ) ;
F_146 ( V_14 ) ;
F_147 ( V_14 ) ;
F_144 ( V_3 , V_14 ) ;
error = F_145 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_6 ) ;
break;
}
}
F_148 ( V_14 ) ;
return error ;
}
STATIC int
F_149 (
T_1 * V_1 ,
T_21 V_198 ,
T_21 V_119 ,
int V_200 )
{
int V_55 ;
int V_56 ;
T_8 V_234 ;
int error ;
T_10 V_206 ;
T_11 V_58 ;
T_3 V_39 ;
T_21 V_235 ;
T_22 V_236 = 0 ;
T_2 * V_3 ;
int V_227 ;
T_13 V_111 ;
T_13 V_237 ;
int V_208 ;
T_8 V_205 ;
T_7 * V_34 ;
int V_33 = 1 ;
V_3 = V_1 -> V_4 ;
F_150 ( V_1 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_119 <= 0 )
return error ;
V_208 = F_126 ( V_1 ) ;
V_205 = F_3 ( V_3 , V_198 ) ;
V_234 = F_128 ( V_3 , V_198 + V_119 ) ;
if ( V_200 & V_238 )
V_33 = 0 ;
if ( V_33 ) {
F_14 ( V_1 , V_46 ) ;
F_151 ( F_50 ( V_1 ) ) ;
}
V_237 = F_152 ( T_13 , 1 << V_3 -> V_217 . V_239 , V_240 ) ;
V_235 = V_198 & ~ ( V_237 - 1 ) ;
error = - F_153 ( F_50 ( V_1 ) -> V_76 ,
V_235 , - 1 ) ;
if ( error )
goto V_241;
F_154 ( F_50 ( V_1 ) , V_235 , - 1 ) ;
if ( V_208 && ! F_155 ( & V_3 -> V_217 ) ) {
V_227 = 1 ;
error = F_2 ( V_1 , V_205 , 1 ,
& V_39 , & V_227 , 0 ) ;
if ( error )
goto V_241;
ASSERT ( V_227 == 0 || V_227 == 1 ) ;
if ( V_227 && V_39 . V_16 != V_43 ) {
T_4 V_242 ;
ASSERT ( V_39 . V_16 != V_231 ) ;
V_242 = V_39 . V_16 ;
V_236 = F_129 ( V_242 , V_3 -> V_217 . V_218 ) ;
if ( V_236 )
V_205 += V_3 -> V_217 . V_218 - V_236 ;
}
V_227 = 1 ;
error = F_2 ( V_1 , V_234 - 1 , 1 ,
& V_39 , & V_227 , 0 ) ;
if ( error )
goto V_241;
ASSERT ( V_227 == 0 || V_227 == 1 ) ;
if ( V_227 && V_39 . V_16 != V_43 ) {
ASSERT ( V_39 . V_16 != V_231 ) ;
V_236 ++ ;
if ( V_236 && ( V_236 != V_3 -> V_217 . V_218 ) )
V_234 -= V_236 ;
}
}
if ( ( V_56 = ( V_234 <= V_205 ) ) )
error = F_136 ( V_1 , V_198 , V_198 + V_119 - 1 ) ;
else {
if ( V_198 < F_5 ( V_3 , V_205 ) )
error = F_136 ( V_1 , V_198 ,
F_5 ( V_3 , V_205 ) - 1 ) ;
if ( ! error &&
F_5 ( V_3 , V_234 ) < V_198 + V_119 )
error = F_136 ( V_1 ,
F_5 ( V_3 , V_234 ) ,
V_198 + V_119 - 1 ) ;
}
V_111 = F_132 ( V_3 , 0 ) ;
while ( ! error && ! V_56 ) {
V_34 = F_20 ( V_3 , V_221 ) ;
V_34 -> V_243 |= V_244 ;
error = F_23 ( V_34 ,
V_111 ,
F_133 ( V_3 ) ,
0 ,
V_48 ,
V_222 ) ;
if ( error ) {
ASSERT ( error == V_124 || F_13 ( V_3 ) ) ;
F_22 ( V_34 , 0 ) ;
break;
}
F_14 ( V_1 , V_50 ) ;
error = F_85 ( V_34 , V_3 ,
V_1 -> V_245 , V_1 -> V_246 ,
V_111 , 0 , V_220 ) ;
if ( error )
goto V_65;
F_25 ( V_34 , V_1 , 0 ) ;
F_32 ( & V_58 , & V_206 ) ;
error = F_37 ( V_34 , V_1 , V_205 ,
V_234 - V_205 ,
0 , 2 , & V_206 , & V_58 , & V_56 ) ;
if ( error ) {
goto V_64;
}
error = F_38 ( & V_34 , & V_58 , & V_55 ) ;
if ( error ) {
goto V_64;
}
error = F_27 ( V_34 , V_52 ) ;
F_16 ( V_1 , V_50 ) ;
}
V_241:
if ( V_33 )
F_16 ( V_1 , V_46 ) ;
return error ;
V_64:
F_42 ( & V_58 ) ;
V_65:
F_22 ( V_34 , V_52 | V_53 ) ;
F_16 ( V_1 , V_33 ? ( V_50 | V_46 ) :
V_50 ) ;
return error ;
}
STATIC int
F_156 (
struct V_102 * V_1 ,
T_21 V_198 ,
T_21 V_119 ,
int V_200 )
{
struct V_101 * V_3 = V_1 -> V_4 ;
T_13 V_247 ;
T_21 V_248 ;
T_21 V_249 ;
int error ;
V_247 = F_152 ( T_13 , 1 << V_3 -> V_217 . V_239 , V_240 ) ;
V_248 = F_157 ( V_198 , V_247 ) ;
V_249 = F_158 ( V_198 + V_119 , V_247 ) ;
ASSERT ( V_248 >= V_198 ) ;
ASSERT ( V_249 <= V_198 + V_119 ) ;
if ( ! ( V_200 & V_238 ) )
F_14 ( V_1 , V_46 ) ;
if ( V_248 < V_249 - 1 ) {
F_154 ( F_50 ( V_1 ) , V_248 ,
V_249 - 1 ) ;
error = F_124 ( V_1 , V_248 ,
V_249 - V_248 - 1 ,
V_250 | V_251 ,
V_200 ) ;
if ( error )
goto V_84;
if ( V_248 != V_198 )
error = F_159 ( V_1 , V_198 , V_248 - V_198 ) ;
if ( error )
goto V_84;
if ( V_249 != V_198 + V_119 )
error = F_159 ( V_1 , V_249 ,
V_198 + V_119 - V_249 ) ;
} else {
error = F_159 ( V_1 , V_198 , V_119 ) ;
}
V_84:
if ( ! ( V_200 & V_238 ) )
F_16 ( V_1 , V_46 ) ;
return error ;
}
int
F_160 (
T_1 * V_1 ,
int V_252 ,
T_23 * V_253 ,
T_21 V_198 ,
int V_200 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_254 ;
int error ;
T_6 V_255 ;
int V_256 ;
T_21 V_257 ;
T_7 * V_34 ;
struct V_258 V_258 ;
if ( ! F_44 ( V_1 -> V_6 . V_69 ) )
return F_8 ( V_213 ) ;
switch ( V_253 -> V_259 ) {
case 0 :
break;
case 1 :
V_253 -> V_260 += V_198 ;
break;
case 2 :
V_253 -> V_260 += F_18 ( V_1 ) ;
break;
default:
return F_8 ( V_213 ) ;
}
switch ( V_252 ) {
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
if ( V_253 -> V_266 <= 0 )
return F_8 ( V_213 ) ;
break;
default:
V_253 -> V_266 = 0 ;
break;
}
if ( V_253 -> V_260 < 0 ||
V_253 -> V_260 > V_3 -> V_41 -> V_42 ||
V_253 -> V_260 + V_253 -> V_266 < 0 ||
V_253 -> V_260 + V_253 -> V_266 >= V_3 -> V_41 -> V_42 )
return F_8 ( V_213 ) ;
V_253 -> V_259 = 0 ;
V_257 = V_253 -> V_260 ;
V_255 = F_18 ( V_1 ) ;
V_256 = V_254 = 0 ;
switch ( V_252 ) {
case V_261 :
error = F_156 ( V_1 , V_257 , V_253 -> V_266 ,
V_200 ) ;
if ( error )
return error ;
V_256 = 1 ;
break;
case V_262 :
case V_263 :
error = F_124 ( V_1 , V_257 , V_253 -> V_266 ,
V_250 , V_200 ) ;
if ( error )
return error ;
V_256 = 1 ;
break;
case V_264 :
case V_265 :
if ( ( error = F_149 ( V_1 , V_257 , V_253 -> V_266 ,
V_200 ) ) )
return error ;
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
F_14 ( V_1 , V_46 ) ;
if ( V_257 > V_255 ) {
error = F_124 ( V_1 , V_255 ,
V_257 - V_255 , 0 ,
V_200 | V_238 ) ;
if ( error ) {
F_16 ( V_1 , V_46 ) ;
break;
}
}
V_258 . V_271 = V_272 ;
V_258 . V_273 = V_257 ;
error = F_161 ( V_1 , & V_258 ,
V_200 | V_238 ) ;
F_16 ( V_1 , V_46 ) ;
if ( error )
return error ;
V_254 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_8 ( V_213 ) ;
}
V_34 = F_20 ( V_3 , V_274 ) ;
if ( ( error = F_23 ( V_34 , 0 , F_162 ( V_3 ) ,
0 , 0 , 0 ) ) ) {
F_22 ( V_34 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_50 ) ;
F_25 ( V_34 , V_1 , V_50 ) ;
if ( ( V_200 & V_275 ) == 0 ) {
V_1 -> V_6 . V_69 &= ~ V_276 ;
if ( V_1 -> V_6 . V_69 & V_277 )
V_1 -> V_6 . V_69 &= ~ V_278 ;
F_90 ( V_34 , V_1 , V_129 | V_130 ) ;
}
if ( V_256 )
V_1 -> V_6 . V_114 |= V_279 ;
else if ( V_254 )
V_1 -> V_6 . V_114 &= ~ V_279 ;
F_31 ( V_34 , V_1 , V_63 ) ;
if ( V_200 & V_280 )
F_93 ( V_34 ) ;
return F_27 ( V_34 , 0 ) ;
}
