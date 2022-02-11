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
error = F_2 ( NULL , V_1 , 0 , F_3 ( V_3 , V_5 ) , 0 , NULL , 0 ,
V_10 , & V_8 , NULL ) ;
if ( error )
goto V_15;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_6 ( V_3 -> V_18 , V_11 , F_7 ( V_12 ) ,
V_19 | V_20 | V_21 ) ;
if ( ! V_14 )
return F_8 ( V_22 ) ;
error = V_14 -> V_23 ;
if ( error ) {
F_9 ( L_1 ,
V_1 -> V_4 , V_14 , F_10 ( V_14 ) ) ;
F_11 ( V_14 ) ;
goto V_15;
}
if ( V_5 < V_12 )
V_12 = V_5 ;
V_5 -= V_12 ;
memcpy ( V_2 , V_14 -> V_24 , V_12 ) ;
F_11 ( V_14 ) ;
}
V_2 [ V_1 -> V_6 . V_7 ] = '\0' ;
error = 0 ;
V_15:
return error ;
}
int
F_12 (
T_1 * V_1 ,
char * V_2 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_5 ;
int error = 0 ;
F_13 ( V_1 ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
F_15 ( V_1 , V_26 ) ;
ASSERT ( F_16 ( V_1 -> V_6 . V_27 ) ) ;
ASSERT ( V_1 -> V_6 . V_7 <= V_28 ) ;
V_5 = V_1 -> V_6 . V_7 ;
if ( ! V_5 )
goto V_15;
if ( V_1 -> V_29 . V_30 & V_31 ) {
memcpy ( V_2 , V_1 -> V_29 . V_32 . V_33 , V_5 ) ;
V_2 [ V_5 ] = '\0' ;
} else {
error = F_1 ( V_1 , V_2 ) ;
}
V_15:
F_17 ( V_1 , V_26 ) ;
return error ;
}
STATIC int
F_18 (
T_2 * V_3 ,
T_1 * V_1 ,
int V_34 )
{
T_6 * V_35 ;
int error ;
T_7 V_36 ;
T_7 V_37 ;
T_8 V_38 ;
int V_39 ;
T_3 V_40 ;
V_36 = F_3 ( V_3 , ( ( V_41 ) V_1 -> V_42 ) ) ;
V_37 = F_3 ( V_3 , ( V_41 ) F_19 ( V_3 ) ) ;
if ( V_37 <= V_36 )
return 0 ;
V_38 = V_37 - V_36 ;
V_39 = 1 ;
F_15 ( V_1 , V_26 ) ;
error = F_2 ( NULL , V_1 , V_36 , V_38 , 0 ,
NULL , 0 , & V_40 , & V_39 , NULL ) ;
F_17 ( V_1 , V_26 ) ;
if ( ! error && ( V_39 != 0 ) &&
( V_40 . V_16 != V_43 ||
V_1 -> V_44 ) ) {
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
V_35 = F_21 ( V_3 , V_45 ) ;
if ( V_34 & V_46 ) {
if ( ! F_22 ( V_1 , V_47 ) ) {
F_23 ( V_35 , 0 ) ;
return 0 ;
}
} else {
F_15 ( V_1 , V_47 ) ;
}
error = F_24 ( V_35 , 0 ,
F_25 ( V_3 ) ,
0 , V_48 ,
V_49 ) ;
if ( error ) {
ASSERT ( F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
F_17 ( V_1 , V_47 ) ;
return error ;
}
F_15 ( V_1 , V_50 ) ;
F_26 ( V_35 , V_1 ) ;
error = F_27 ( & V_35 , V_1 , V_1 -> V_42 ) ;
if ( error ) {
F_23 ( V_35 ,
( V_51 |
V_52 ) ) ;
} else {
error = F_28 ( V_35 ,
V_51 ) ;
}
F_17 ( V_1 , V_47 | V_50 ) ;
}
return error ;
}
STATIC int
F_29 (
T_1 * V_1 ,
T_6 * * V_53 )
{
T_5 * V_14 ;
int V_54 ;
int V_55 ;
int error ;
T_9 V_56 ;
T_10 V_57 ;
int V_58 ;
T_2 * V_3 ;
T_3 V_10 [ V_9 ] ;
int V_8 ;
T_6 * V_59 ;
int V_60 ;
T_6 * V_35 ;
V_35 = * V_53 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ;
ASSERT ( V_1 -> V_6 . V_61 > 0 && V_1 -> V_6 . V_61 <= 2 ) ;
if ( ( error = F_24 ( V_35 , 0 , F_25 ( V_3 ) , 0 ,
V_48 , V_49 ) ) ) {
ASSERT ( F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
* V_53 = NULL ;
return error ;
}
F_15 ( V_1 , V_47 | V_50 ) ;
V_60 = ( int ) V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_7 = 0 ;
F_26 ( V_35 , V_1 ) ;
F_31 ( V_35 , V_1 , V_62 ) ;
V_55 = 0 ;
F_32 ( & V_57 , & V_56 ) ;
V_8 = F_33 ( V_10 ) ;
if ( ( error = F_2 ( V_35 , V_1 , 0 , F_3 ( V_3 , V_60 ) ,
V_63 , & V_56 , 0 , V_10 , & V_8 ,
& V_57 ) ) )
goto V_64;
for ( V_58 = 0 ; V_58 < V_8 ; V_58 ++ ) {
V_14 = F_34 ( V_35 , V_3 -> V_18 ,
F_4 ( V_3 , V_10 [ V_58 ] . V_16 ) ,
F_35 ( V_3 , V_10 [ V_58 ] . V_17 ) , 0 ) ;
F_36 ( V_35 , V_14 ) ;
}
if ( ( error = F_37 ( V_35 , V_1 , 0 , V_60 , V_63 , V_8 ,
& V_56 , & V_57 , & V_55 ) ) )
goto V_65;
ASSERT ( V_55 ) ;
if ( ( error = F_38 ( & V_35 , & V_57 , & V_54 ) ) )
goto V_65;
ASSERT ( V_54 ) ;
F_26 ( V_35 , V_1 ) ;
F_31 ( V_35 , V_1 , V_62 ) ;
V_59 = F_39 ( V_35 ) ;
error = F_28 ( V_35 , 0 ) ;
V_35 = V_59 ;
if ( error ) {
ASSERT ( F_14 ( V_3 ) ) ;
goto V_64;
}
F_40 ( V_35 -> V_66 ) ;
if ( V_1 -> V_29 . V_67 )
F_41 ( V_1 , - V_1 -> V_29 . V_67 , V_68 ) ;
ASSERT ( V_1 -> V_29 . V_67 == 0 ) ;
if ( ( error = F_24 ( V_35 , 0 , F_25 ( V_3 ) , 0 ,
V_48 , V_49 ) ) ) {
ASSERT ( F_14 ( V_3 ) ) ;
goto V_64;
}
* V_53 = V_35 ;
return 0 ;
V_65:
F_42 ( & V_57 ) ;
V_64:
F_23 ( V_35 , V_51 | V_52 ) ;
F_17 ( V_1 , V_47 | V_50 ) ;
* V_53 = NULL ;
return error ;
}
STATIC int
F_43 (
T_1 * V_1 ,
T_6 * * V_53 )
{
int error ;
ASSERT ( V_1 -> V_6 . V_7 <= F_30 ( V_1 ) ) ;
error = F_24 ( * V_53 , 0 ,
F_25 ( V_1 -> V_4 ) ,
0 , V_48 ,
V_49 ) ;
if ( error ) {
F_23 ( * V_53 , 0 ) ;
* V_53 = NULL ;
return error ;
}
F_15 ( V_1 , V_50 | V_47 ) ;
if ( V_1 -> V_29 . V_67 > 0 ) {
F_41 ( V_1 ,
- ( V_1 -> V_29 . V_67 ) ,
V_68 ) ;
ASSERT ( V_1 -> V_29 . V_67 == 0 ) ;
}
return 0 ;
}
STATIC int
F_44 (
T_1 * V_1 ,
T_6 * * V_53 )
{
T_6 * V_35 ;
int error ;
T_2 * V_3 ;
ASSERT ( F_45 ( V_1 , V_47 ) ) ;
V_35 = * V_53 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_69 != 0 ) ;
error = F_28 ( V_35 , V_51 ) ;
F_17 ( V_1 , V_50 ) ;
if ( error )
goto V_70;
error = F_46 ( V_1 ) ;
if ( error )
goto V_70;
V_35 = F_21 ( V_3 , V_45 ) ;
error = F_24 ( V_35 , 0 ,
F_47 ( V_3 ) ,
0 , V_48 ,
V_71 ) ;
if ( error )
goto V_72;
F_15 ( V_1 , V_50 ) ;
F_26 ( V_35 , V_1 ) ;
F_48 ( V_1 , V_73 ) ;
ASSERT ( V_1 -> V_6 . V_74 == 0 ) ;
* V_53 = V_35 ;
return 0 ;
V_72:
ASSERT ( F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
V_70:
* V_53 = NULL ;
F_17 ( V_1 , V_47 ) ;
return error ;
}
int
F_49 (
T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
int error ;
if ( ! F_50 ( V_1 -> V_6 . V_27 ) || ( V_1 -> V_6 . V_27 == 0 ) )
return 0 ;
if ( V_3 -> V_75 & V_76 )
return 0 ;
if ( ! F_14 ( V_3 ) ) {
int V_77 ;
if ( ( V_1 -> V_6 . V_78 == 0 ) && F_51 ( V_1 ) )
F_52 ( V_1 ) ;
V_77 = F_53 ( V_1 , V_79 ) ;
if ( V_77 ) {
F_54 ( V_1 , V_80 ) ;
if ( F_55 ( F_56 ( V_1 ) ) && V_1 -> V_44 > 0 )
F_57 ( V_1 , 0 , - 1 , V_81 , V_82 ) ;
}
}
if ( V_1 -> V_6 . V_78 == 0 )
return 0 ;
if ( ( F_50 ( V_1 -> V_6 . V_27 ) &&
( ( V_1 -> V_42 > 0 ) || ( F_58 ( F_56 ( V_1 ) ) > 0 ||
V_1 -> V_44 > 0 ) ) &&
( V_1 -> V_29 . V_30 & V_83 ) ) &&
( ! ( V_1 -> V_6 . V_84 & ( V_85 | V_86 ) ) ) ) {
if ( F_59 ( V_1 , V_80 ) )
return 0 ;
error = F_18 ( V_3 , V_1 ,
V_46 ) ;
if ( error )
return error ;
if ( V_1 -> V_44 )
F_60 ( V_1 , V_80 ) ;
}
return 0 ;
}
int
F_61 (
T_1 * V_1 )
{
T_10 V_57 ;
T_9 V_56 ;
int V_54 ;
T_6 * V_35 ;
T_2 * V_3 ;
int error ;
int V_87 ;
if ( V_1 -> V_6 . V_27 == 0 || F_62 ( F_56 ( V_1 ) ) ) {
ASSERT ( V_1 -> V_29 . V_88 == 0 ) ;
ASSERT ( V_1 -> V_29 . V_89 == 0 ) ;
return V_90 ;
}
V_87 = ( ( V_1 -> V_6 . V_78 == 0 ) &&
( ( V_1 -> V_6 . V_7 != 0 ) || ( V_1 -> V_42 != 0 ) ||
( V_1 -> V_6 . V_61 > 0 ) || ( V_1 -> V_44 > 0 ) ) &&
F_50 ( V_1 -> V_6 . V_27 ) ) ;
V_3 = V_1 -> V_4 ;
error = 0 ;
if ( V_3 -> V_75 & V_76 )
goto V_15;
if ( V_1 -> V_6 . V_78 != 0 ) {
if ( ( F_50 ( V_1 -> V_6 . V_27 ) &&
( ( V_1 -> V_42 > 0 ) || ( F_58 ( F_56 ( V_1 ) ) > 0 ||
V_1 -> V_44 > 0 ) ) &&
( V_1 -> V_29 . V_30 & V_83 ) &&
( ! ( V_1 -> V_6 . V_84 &
( V_85 | V_86 ) ) ||
( V_1 -> V_44 != 0 ) ) ) ) {
error = F_18 ( V_3 , V_1 , 0 ) ;
if ( error )
return V_90 ;
}
goto V_15;
}
ASSERT ( V_1 -> V_6 . V_78 == 0 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return V_90 ;
V_35 = F_21 ( V_3 , V_45 ) ;
if ( V_87 ) {
F_15 ( V_1 , V_47 ) ;
F_63 ( V_1 ) ;
error = F_24 ( V_35 , 0 ,
F_25 ( V_3 ) ,
0 , V_48 ,
V_49 ) ;
if ( error ) {
ASSERT ( F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
F_17 ( V_1 , V_47 ) ;
return V_90 ;
}
F_15 ( V_1 , V_50 ) ;
F_26 ( V_35 , V_1 ) ;
error = F_27 ( & V_35 , V_1 , 0 ) ;
if ( error ) {
F_23 ( V_35 ,
V_51 | V_52 ) ;
F_17 ( V_1 , V_47 | V_50 ) ;
return V_90 ;
}
} else if ( F_16 ( V_1 -> V_6 . V_27 ) ) {
error = ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ?
F_29 ( V_1 , & V_35 ) :
F_43 ( V_1 , & V_35 ) ;
if ( error ) {
ASSERT ( V_35 == NULL ) ;
return V_90 ;
}
F_26 ( V_35 , V_1 ) ;
} else {
error = F_24 ( V_35 , 0 ,
F_47 ( V_3 ) ,
0 , V_48 ,
V_71 ) ;
if ( error ) {
ASSERT ( F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
return V_90 ;
}
F_15 ( V_1 , V_50 | V_47 ) ;
F_26 ( V_35 , V_1 ) ;
}
if ( V_1 -> V_6 . V_74 > 0 ) {
error = F_44 ( V_1 , & V_35 ) ;
if ( error )
return V_90 ;
} else if ( V_1 -> V_91 ) {
F_48 ( V_1 , V_73 ) ;
}
F_32 ( & V_57 , & V_56 ) ;
error = F_64 ( V_35 , V_1 , & V_57 ) ;
if ( error ) {
if ( ! F_14 ( V_3 ) ) {
F_65 ( V_3 , L_2 ,
V_92 , error ) ;
F_66 ( V_3 , V_93 ) ;
}
F_23 ( V_35 , V_51 | V_52 ) ;
} else {
F_67 ( V_35 , V_1 , V_94 , - 1 ) ;
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error )
F_65 ( V_3 , L_3 ,
V_92 , error ) ;
error = F_28 ( V_35 , V_51 ) ;
if ( error )
F_65 ( V_3 , L_4 ,
V_92 , error ) ;
}
F_68 ( V_1 ) ;
F_17 ( V_1 , V_47 | V_50 ) ;
V_15:
return V_90 ;
}
int
F_69 (
T_1 * V_95 ,
struct V_96 * V_97 ,
T_1 * * V_98 ,
struct V_96 * V_99 )
{
T_11 V_100 ;
int error ;
T_12 V_101 ;
F_70 ( V_95 , V_97 ) ;
if ( F_14 ( V_95 -> V_4 ) )
return F_8 ( V_25 ) ;
V_101 = F_71 ( V_95 ) ;
error = F_72 ( NULL , V_95 , V_97 , & V_100 , V_99 ) ;
F_73 ( V_95 , V_101 ) ;
if ( error )
goto V_15;
error = F_74 ( V_95 -> V_4 , NULL , V_100 , 0 , 0 , V_98 ) ;
if ( error )
goto V_102;
return 0 ;
V_102:
if ( V_99 )
F_75 ( V_99 -> V_97 ) ;
V_15:
* V_98 = NULL ;
return error ;
}
int
F_76 (
T_1 * V_95 ,
struct V_96 * V_97 ,
T_13 V_103 ,
T_14 V_104 ,
T_1 * * V_98 )
{
int V_105 = F_77 ( V_103 ) ;
struct V_106 * V_3 = V_95 -> V_4 ;
struct V_107 * V_1 = NULL ;
struct V_108 * V_35 = NULL ;
int error ;
T_10 V_57 ;
T_9 V_56 ;
T_15 V_109 = V_110 ;
T_12 V_111 ;
int V_54 ;
T_16 V_112 ;
struct V_113 * V_114 = NULL ;
struct V_113 * V_115 = NULL ;
T_12 V_116 ;
T_12 V_117 ;
T_12 V_118 ;
F_78 ( V_95 , V_97 ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
if ( V_95 -> V_6 . V_84 & V_119 )
V_112 = F_79 ( V_95 ) ;
else
V_112 = V_120 ;
error = F_80 ( V_95 , F_81 () , F_82 () , V_112 ,
V_121 | V_122 , & V_114 , & V_115 ) ;
if ( error )
return error ;
if ( V_105 ) {
V_104 = 0 ;
V_116 = F_83 ( V_3 , V_97 -> V_123 ) ;
V_117 = F_84 ( V_3 ) ;
V_118 = V_124 ;
V_35 = F_21 ( V_3 , V_125 ) ;
} else {
V_116 = F_85 ( V_3 , V_97 -> V_123 ) ;
V_117 = F_86 ( V_3 ) ;
V_118 = V_126 ;
V_35 = F_21 ( V_3 , V_127 ) ;
}
V_111 = V_51 ;
error = F_24 ( V_35 , V_116 , V_117 , 0 ,
V_48 , V_118 ) ;
if ( error == V_128 ) {
F_87 ( V_95 ) ;
error = F_24 ( V_35 , V_116 , V_117 , 0 ,
V_48 , V_118 ) ;
}
if ( error == V_128 ) {
V_116 = 0 ;
error = F_24 ( V_35 , 0 , V_117 , 0 ,
V_48 , V_118 ) ;
}
if ( error ) {
V_111 = 0 ;
goto V_129;
}
F_15 ( V_95 , V_50 | V_130 ) ;
V_109 = V_131 ;
if ( V_105 && V_95 -> V_6 . V_78 >= V_132 ) {
error = F_8 ( V_133 ) ;
goto V_129;
}
F_32 ( & V_57 , & V_56 ) ;
error = F_88 ( V_35 , V_3 , V_114 , V_115 , V_116 , 1 , 0 ) ;
if ( error )
goto V_129;
error = F_89 ( V_35 , V_95 , V_97 , V_116 ) ;
if ( error )
goto V_129;
error = F_90 ( & V_35 , V_95 , V_103 , V_105 ? 2 : 1 , V_104 ,
V_112 , V_116 > 0 , & V_1 , & V_54 ) ;
if ( error ) {
if ( error == V_128 )
goto V_129;
goto V_134;
}
F_91 ( V_35 , V_95 , V_50 ) ;
V_109 = V_110 ;
error = F_92 ( V_35 , V_95 , V_97 , V_1 -> V_135 ,
& V_56 , & V_57 , V_116 ?
V_116 - F_93 ( V_3 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_128 ) ;
goto V_134;
}
F_94 ( V_35 , V_95 , V_136 | V_137 ) ;
F_31 ( V_35 , V_95 , V_62 ) ;
if ( V_105 ) {
error = F_95 ( V_35 , V_1 , V_95 ) ;
if ( error )
goto V_138;
error = F_96 ( V_35 , V_95 ) ;
if ( error )
goto V_138;
}
if ( V_3 -> V_75 & ( V_139 | V_140 ) )
F_97 ( V_35 ) ;
F_98 ( V_35 , V_1 , V_114 , V_115 ) ;
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error )
goto V_138;
error = F_28 ( V_35 , V_51 ) ;
if ( error )
goto V_141;
F_99 ( V_114 ) ;
F_99 ( V_115 ) ;
* V_98 = V_1 ;
return 0 ;
V_138:
F_42 ( & V_57 ) ;
V_134:
V_111 |= V_52 ;
V_129:
F_23 ( V_35 , V_111 ) ;
V_141:
if ( V_1 )
F_100 ( V_1 ) ;
F_99 ( V_114 ) ;
F_99 ( V_115 ) ;
if ( V_109 )
F_17 ( V_95 , V_50 ) ;
return error ;
}
static inline int
F_101 ( int V_101 , int V_142 )
{
if ( V_101 & ( V_143 | V_47 ) )
V_101 |= ( V_142 + V_144 ) << V_145 ;
if ( V_101 & ( V_26 | V_50 ) )
V_101 |= ( V_142 + V_144 ) << V_146 ;
return V_101 ;
}
void
F_102 (
T_1 * * V_147 ,
int V_148 ,
T_12 V_101 )
{
int V_149 = 0 , V_58 , V_150 , V_151 ;
T_17 * V_152 ;
ASSERT ( V_147 && ( V_148 >= 2 ) ) ;
V_151 = 0 ;
V_58 = 0 ;
V_153:
for (; V_58 < V_148 ; V_58 ++ ) {
ASSERT ( V_147 [ V_58 ] ) ;
if ( V_58 && ( V_147 [ V_58 ] == V_147 [ V_58 - 1 ] ) )
continue;
if ( ! V_151 ) {
for ( V_150 = ( V_58 - 1 ) ; V_150 >= 0 && ! V_151 ; V_150 -- ) {
V_152 = ( T_17 * ) V_147 [ V_150 ] -> V_154 ;
if ( V_152 && ( V_152 -> V_155 & V_156 ) ) {
V_151 ++ ;
}
}
}
if ( V_151 ) {
ASSERT ( V_58 != 0 ) ;
if ( ! F_22 ( V_147 [ V_58 ] , F_101 ( V_101 , V_58 ) ) ) {
V_149 ++ ;
for( V_150 = V_58 - 1 ; V_150 >= 0 ; V_150 -- ) {
if ( ( V_150 != ( V_58 - 1 ) ) && V_147 [ V_150 ] ==
V_147 [ V_150 + 1 ] )
continue;
F_17 ( V_147 [ V_150 ] , V_101 ) ;
}
if ( ( V_149 % 5 ) == 0 ) {
F_103 ( 1 ) ;
#ifdef F_104
V_157 ++ ;
#endif
}
V_58 = 0 ;
V_151 = 0 ;
goto V_153;
}
} else {
F_15 ( V_147 [ V_58 ] , F_101 ( V_101 , V_58 ) ) ;
}
}
#ifdef F_104
if ( V_149 ) {
if ( V_149 < 5 ) V_158 ++ ;
else if ( V_149 < 100 ) V_159 ++ ;
else V_160 ++ ;
} else {
V_161 ++ ;
}
#endif
}
void
F_105 (
T_1 * V_162 ,
T_1 * V_163 ,
T_12 V_101 )
{
T_1 * V_164 ;
int V_149 = 0 ;
T_17 * V_152 ;
if ( V_101 & ( V_143 | V_47 ) )
ASSERT ( ( V_101 & ( V_26 | V_50 ) ) == 0 ) ;
ASSERT ( V_162 -> V_135 != V_163 -> V_135 ) ;
if ( V_162 -> V_135 > V_163 -> V_135 ) {
V_164 = V_162 ;
V_162 = V_163 ;
V_163 = V_164 ;
}
V_153:
F_15 ( V_162 , F_101 ( V_101 , 0 ) ) ;
V_152 = ( T_17 * ) V_162 -> V_154 ;
if ( V_152 && ( V_152 -> V_155 & V_156 ) ) {
if ( ! F_22 ( V_163 , F_101 ( V_101 , 1 ) ) ) {
F_17 ( V_162 , V_101 ) ;
if ( ( ++ V_149 % 5 ) == 0 )
F_103 ( 1 ) ;
goto V_153;
}
} else {
F_15 ( V_163 , F_101 ( V_101 , 1 ) ) ;
}
}
int
F_106 (
T_1 * V_95 ,
struct V_96 * V_97 ,
T_1 * V_1 )
{
T_2 * V_3 = V_95 -> V_4 ;
T_6 * V_35 = NULL ;
int V_105 = F_77 ( V_1 -> V_6 . V_27 ) ;
int error = 0 ;
T_10 V_57 ;
T_9 V_56 ;
int V_111 ;
int V_54 ;
int V_165 ;
T_12 V_116 ;
T_12 V_118 ;
F_107 ( V_95 , V_97 ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
error = F_20 ( V_95 , 0 ) ;
if ( error )
goto V_166;
error = F_20 ( V_1 , 0 ) ;
if ( error )
goto V_166;
if ( V_105 ) {
V_35 = F_21 ( V_3 , V_167 ) ;
V_118 = V_168 ;
} else {
V_35 = F_21 ( V_3 , V_169 ) ;
V_118 = V_170 ;
}
V_111 = V_51 ;
V_116 = F_108 ( V_3 ) ;
error = F_24 ( V_35 , V_116 , F_109 ( V_3 ) , 0 ,
V_48 , V_118 ) ;
if ( error == V_128 ) {
V_116 = 0 ;
error = F_24 ( V_35 , 0 , F_109 ( V_3 ) , 0 ,
V_48 , V_118 ) ;
}
if ( error ) {
ASSERT ( error != V_128 ) ;
V_111 = 0 ;
goto V_129;
}
F_105 ( V_95 , V_1 , V_50 ) ;
F_91 ( V_35 , V_95 , V_50 ) ;
F_91 ( V_35 , V_1 , V_50 ) ;
if ( V_105 ) {
ASSERT ( V_1 -> V_6 . V_78 >= 2 ) ;
if ( V_1 -> V_6 . V_78 != 2 ) {
error = F_8 ( V_171 ) ;
goto V_129;
}
if ( ! F_110 ( V_1 ) ) {
error = F_8 ( V_171 ) ;
goto V_129;
}
}
F_32 ( & V_57 , & V_56 ) ;
error = F_111 ( V_35 , V_95 , V_97 , V_1 -> V_135 ,
& V_56 , & V_57 , V_116 ) ;
if ( error ) {
ASSERT ( error != V_172 ) ;
goto V_138;
}
F_94 ( V_35 , V_95 , V_136 | V_137 ) ;
if ( V_105 ) {
error = F_112 ( V_35 , V_95 ) ;
if ( error )
goto V_138;
error = F_112 ( V_35 , V_1 ) ;
if ( error )
goto V_138;
} else {
F_31 ( V_35 , V_95 , V_62 ) ;
}
error = F_112 ( V_35 , V_1 ) ;
if ( error )
goto V_138;
V_165 = ( V_1 -> V_6 . V_78 == 0 ) ;
if ( V_3 -> V_75 & ( V_139 | V_140 ) )
F_97 ( V_35 ) ;
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error )
goto V_138;
error = F_28 ( V_35 , V_51 ) ;
if ( error )
goto V_166;
if ( ! V_105 && V_165 && F_51 ( V_1 ) )
F_52 ( V_1 ) ;
return 0 ;
V_138:
F_42 ( & V_57 ) ;
V_111 |= V_52 ;
V_129:
F_23 ( V_35 , V_111 ) ;
V_166:
return error ;
}
int
F_113 (
T_1 * V_173 ,
T_1 * V_174 ,
struct V_96 * V_175 )
{
T_2 * V_3 = V_173 -> V_4 ;
T_6 * V_35 ;
int error ;
T_10 V_57 ;
T_9 V_56 ;
int V_111 ;
int V_54 ;
int V_116 ;
F_114 ( V_173 , V_175 ) ;
ASSERT ( ! F_77 ( V_174 -> V_6 . V_27 ) ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
error = F_20 ( V_174 , 0 ) ;
if ( error )
goto V_166;
error = F_20 ( V_173 , 0 ) ;
if ( error )
goto V_166;
V_35 = F_21 ( V_3 , V_176 ) ;
V_111 = V_51 ;
V_116 = F_115 ( V_3 , V_175 -> V_123 ) ;
error = F_24 ( V_35 , V_116 , F_116 ( V_3 ) , 0 ,
V_48 , V_177 ) ;
if ( error == V_128 ) {
V_116 = 0 ;
error = F_24 ( V_35 , 0 , F_116 ( V_3 ) , 0 ,
V_48 , V_177 ) ;
}
if ( error ) {
V_111 = 0 ;
goto V_178;
}
F_105 ( V_174 , V_173 , V_50 ) ;
F_91 ( V_35 , V_174 , V_50 ) ;
F_91 ( V_35 , V_173 , V_50 ) ;
if ( V_174 -> V_6 . V_78 >= V_132 ) {
error = F_8 ( V_133 ) ;
goto V_178;
}
if ( F_117 ( ( V_173 -> V_6 . V_84 & V_119 ) &&
( F_79 ( V_173 ) != F_79 ( V_174 ) ) ) ) {
error = F_8 ( V_179 ) ;
goto V_178;
}
error = F_89 ( V_35 , V_173 , V_175 , V_116 ) ;
if ( error )
goto V_178;
F_32 ( & V_57 , & V_56 ) ;
error = F_92 ( V_35 , V_173 , V_175 , V_174 -> V_135 ,
& V_56 , & V_57 , V_116 ) ;
if ( error )
goto V_180;
F_94 ( V_35 , V_173 , V_136 | V_137 ) ;
F_31 ( V_35 , V_173 , V_62 ) ;
error = F_96 ( V_35 , V_174 ) ;
if ( error )
goto V_180;
if ( V_3 -> V_75 & ( V_139 | V_140 ) ) {
F_97 ( V_35 ) ;
}
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error ) {
F_42 ( & V_57 ) ;
goto V_180;
}
return F_28 ( V_35 , V_51 ) ;
V_180:
V_111 |= V_52 ;
V_178:
F_23 ( V_35 , V_111 ) ;
V_166:
return error ;
}
int
F_118 (
T_1 * V_95 ,
struct V_96 * V_181 ,
const char * V_182 ,
T_13 V_103 ,
T_1 * * V_98 )
{
T_2 * V_3 = V_95 -> V_4 ;
T_6 * V_35 ;
T_1 * V_1 ;
int error ;
int V_5 ;
T_10 V_57 ;
T_9 V_56 ;
T_15 V_109 = V_110 ;
T_12 V_111 ;
int V_54 ;
T_7 V_183 ;
T_8 V_184 ;
int V_8 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
const char * V_185 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
T_16 V_112 ;
struct V_113 * V_114 , * V_115 ;
T_12 V_116 ;
* V_98 = NULL ;
error = 0 ;
V_1 = NULL ;
V_35 = NULL ;
F_119 ( V_95 , V_181 ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
V_5 = strlen ( V_182 ) ;
if ( V_5 >= V_28 )
return F_8 ( V_186 ) ;
V_114 = V_115 = NULL ;
if ( V_95 -> V_6 . V_84 & V_119 )
V_112 = F_79 ( V_95 ) ;
else
V_112 = V_120 ;
error = F_80 ( V_95 , F_81 () , F_82 () , V_112 ,
V_121 | V_122 , & V_114 , & V_115 ) ;
if ( error )
goto V_166;
V_35 = F_21 ( V_3 , V_187 ) ;
V_111 = V_51 ;
if ( V_5 <= F_120 ( V_3 ) )
V_184 = 0 ;
else
V_184 = F_3 ( V_3 , V_5 ) ;
V_116 = F_121 ( V_3 , V_181 -> V_123 , V_184 ) ;
error = F_24 ( V_35 , V_116 , F_122 ( V_3 ) , 0 ,
V_48 , V_188 ) ;
if ( error == V_128 && V_184 == 0 ) {
V_116 = 0 ;
error = F_24 ( V_35 , 0 , F_122 ( V_3 ) , 0 ,
V_48 , V_188 ) ;
}
if ( error ) {
V_111 = 0 ;
goto V_178;
}
F_15 ( V_95 , V_50 | V_130 ) ;
V_109 = V_131 ;
if ( V_95 -> V_6 . V_84 & V_189 ) {
error = F_8 ( V_190 ) ;
goto V_178;
}
error = F_88 ( V_35 , V_3 , V_114 , V_115 , V_116 , 1 , 0 ) ;
if ( error )
goto V_178;
error = F_89 ( V_35 , V_95 , V_181 , V_116 ) ;
if ( error )
goto V_178;
F_32 ( & V_57 , & V_56 ) ;
error = F_90 ( & V_35 , V_95 , V_191 | ( V_103 & ~ V_192 ) , 1 , 0 ,
V_112 , V_116 > 0 , & V_1 , NULL ) ;
if ( error ) {
if ( error == V_128 )
goto V_178;
goto V_65;
}
F_91 ( V_35 , V_95 , V_50 ) ;
V_109 = V_110 ;
F_98 ( V_35 , V_1 , V_114 , V_115 ) ;
if ( V_116 )
V_116 -= F_93 ( V_3 ) ;
if ( V_5 <= F_30 ( V_1 ) ) {
F_41 ( V_1 , V_5 , V_68 ) ;
memcpy ( V_1 -> V_29 . V_32 . V_33 , V_182 , V_5 ) ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_29 . V_30 &= ~ ( V_83 | V_193 ) ;
V_1 -> V_29 . V_30 |= V_31 ;
V_1 -> V_6 . V_194 = V_195 ;
F_31 ( V_35 , V_1 , V_196 | V_62 ) ;
} else {
V_183 = 0 ;
V_8 = V_9 ;
error = F_2 ( V_35 , V_1 , V_183 , V_184 ,
V_197 | V_63 ,
& V_56 , V_116 , V_10 , & V_8 ,
& V_57 ) ;
if ( error )
goto V_198;
if ( V_116 )
V_116 -= V_184 ;
V_1 -> V_6 . V_7 = V_5 ;
F_31 ( V_35 , V_1 , V_62 ) ;
V_185 = V_182 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_34 ( V_35 , V_3 -> V_18 , V_11 ,
F_7 ( V_12 ) , 0 ) ;
ASSERT ( ! F_123 ( V_14 ) ) ;
if ( V_5 < V_12 ) {
V_12 = V_5 ;
}
V_5 -= V_12 ;
memcpy ( V_14 -> V_24 , V_185 , V_12 ) ;
V_185 += V_12 ;
F_124 ( V_35 , V_14 , 0 , V_12 - 1 ) ;
}
}
error = F_92 ( V_35 , V_95 , V_181 , V_1 -> V_135 ,
& V_56 , & V_57 , V_116 ) ;
if ( error )
goto V_198;
F_94 ( V_35 , V_95 , V_136 | V_137 ) ;
F_31 ( V_35 , V_95 , V_62 ) ;
if ( V_3 -> V_75 & ( V_139 | V_140 ) ) {
F_97 ( V_35 ) ;
}
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error ) {
goto V_198;
}
error = F_28 ( V_35 , V_51 ) ;
F_99 ( V_114 ) ;
F_99 ( V_115 ) ;
* V_98 = V_1 ;
return 0 ;
V_198:
F_100 ( V_1 ) ;
V_65:
F_42 ( & V_57 ) ;
V_111 |= V_52 ;
V_178:
F_23 ( V_35 , V_111 ) ;
F_99 ( V_114 ) ;
F_99 ( V_115 ) ;
if ( V_109 )
F_17 ( V_95 , V_50 ) ;
V_166:
return error ;
}
int
F_125 (
T_1 * V_1 ,
T_18 V_199 ,
T_19 V_200 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_6 * V_35 ;
int error ;
if ( ! F_126 ( V_201 ) )
return F_8 ( V_190 ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
V_35 = F_21 ( V_3 , V_202 ) ;
error = F_24 ( V_35 , 0 , F_127 ( V_3 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_23 ( V_35 , 0 ) ;
return error ;
}
F_15 ( V_1 , V_50 ) ;
F_91 ( V_35 , V_1 , V_50 ) ;
V_1 -> V_6 . V_203 = V_199 ;
V_1 -> V_6 . V_204 = V_200 ;
F_31 ( V_35 , V_1 , V_62 ) ;
error = F_28 ( V_35 , 0 ) ;
return error ;
}
STATIC int
F_128 (
T_1 * V_1 ,
T_20 V_205 ,
T_20 V_123 ,
int V_206 ,
int V_207 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_20 V_208 ;
T_8 V_209 ;
T_8 V_210 ;
T_21 V_211 , V_164 ;
T_7 V_212 ;
T_9 V_213 ;
int V_39 ;
int V_214 ;
int V_215 ;
int V_216 ;
T_6 * V_35 ;
T_3 V_217 [ 1 ] , * V_218 ;
T_10 V_57 ;
T_12 V_219 , V_116 , V_220 ;
int V_54 ;
int error ;
F_129 ( V_1 ) ;
if ( F_14 ( V_3 ) )
return F_8 ( V_25 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
if ( V_123 <= 0 )
return F_8 ( V_221 ) ;
V_216 = F_130 ( V_1 ) ;
V_211 = F_131 ( V_1 ) ;
V_208 = V_123 ;
V_218 = & V_217 [ 0 ] ;
V_39 = 1 ;
V_214 = V_197 | V_206 ;
V_212 = F_132 ( V_3 , V_205 ) ;
V_210 = F_3 ( V_3 , V_208 ) ;
while ( V_210 && ! error ) {
T_7 V_222 , V_223 ;
if ( F_117 ( V_211 ) ) {
V_222 = V_212 ;
F_133 ( V_222 , V_211 ) ;
V_222 *= V_211 ;
V_223 = V_212 + V_210 ;
if ( ( V_164 = F_134 ( V_212 , V_211 ) ) )
V_223 += V_164 ;
if ( ( V_164 = F_134 ( V_223 , V_211 ) ) )
V_223 += V_211 - V_164 ;
} else {
V_222 = 0 ;
V_223 = V_210 ;
}
V_116 = F_135 ( T_7 , ( V_223 - V_222 ) , ( V_224 * V_39 ) ) ;
if ( F_117 ( V_216 ) ) {
V_220 = V_219 = V_116 ;
V_220 /= V_3 -> V_225 . V_226 ;
V_116 = F_136 ( V_3 , 0 ) ;
V_215 = V_227 ;
} else {
V_220 = 0 ;
V_116 = V_219 = F_136 ( V_3 , V_116 ) ;
V_215 = V_228 ;
}
V_35 = F_21 ( V_3 , V_229 ) ;
error = F_24 ( V_35 , V_116 ,
F_137 ( V_3 ) , V_220 ,
V_48 ,
V_230 ) ;
if ( error ) {
ASSERT ( error == V_128 || F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
break;
}
F_15 ( V_1 , V_50 ) ;
error = F_138 ( V_35 , V_1 , V_219 ,
0 , V_215 ) ;
if ( error )
goto V_65;
F_26 ( V_35 , V_1 ) ;
F_32 ( & V_57 , & V_213 ) ;
error = F_2 ( V_35 , V_1 , V_212 ,
V_210 , V_214 ,
& V_213 , 0 , V_218 , & V_39 ,
& V_57 ) ;
if ( error ) {
goto V_64;
}
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error ) {
goto V_64;
}
error = F_28 ( V_35 , V_51 ) ;
F_17 ( V_1 , V_50 ) ;
if ( error ) {
break;
}
V_209 = V_218 -> V_17 ;
if ( V_39 == 0 ) {
error = F_8 ( V_128 ) ;
break;
}
V_212 += V_209 ;
V_210 -= V_209 ;
}
return error ;
V_64:
F_42 ( & V_57 ) ;
F_139 ( V_35 , V_1 , V_219 , 0 , V_215 ) ;
V_65:
F_23 ( V_35 , V_51 | V_52 ) ;
F_17 ( V_1 , V_50 ) ;
return error ;
}
STATIC int
F_140 (
T_1 * V_1 ,
T_20 V_231 ,
T_20 V_232 )
{
T_3 V_40 ;
T_7 V_233 ;
T_20 V_234 ;
T_20 V_205 ;
T_5 * V_14 ;
T_2 * V_3 = V_1 -> V_4 ;
int V_235 ;
int error = 0 ;
if ( V_231 >= V_1 -> V_42 )
return 0 ;
if ( V_232 > V_1 -> V_42 )
V_232 = V_1 -> V_42 ;
V_14 = F_141 ( F_130 ( V_1 ) ?
V_3 -> V_236 : V_3 -> V_18 ,
V_3 -> V_225 . V_237 , V_21 ) ;
if ( ! V_14 )
return F_8 ( V_22 ) ;
F_142 ( V_14 ) ;
for ( V_205 = V_231 ; V_205 <= V_232 ; V_205 = V_234 + 1 ) {
V_233 = F_132 ( V_3 , V_205 ) ;
V_235 = 1 ;
error = F_2 ( NULL , V_1 , V_233 , 1 , 0 ,
NULL , 0 , & V_40 , & V_235 , NULL ) ;
if ( error || V_235 < 1 )
break;
ASSERT ( V_40 . V_17 >= 1 ) ;
ASSERT ( V_40 . V_238 == V_233 ) ;
V_234 = F_5 ( V_3 , V_40 . V_238 + 1 ) - 1 ;
if ( V_234 > V_232 )
V_234 = V_232 ;
if ( V_40 . V_16 == V_43 )
continue;
ASSERT ( V_40 . V_16 != V_239 ) ;
if ( V_40 . V_240 == V_241 )
continue;
F_143 ( V_14 ) ;
F_144 ( V_14 ) ;
F_145 ( V_14 ) ;
F_146 ( V_14 , F_147 ( V_1 , V_40 . V_16 ) ) ;
F_148 ( V_3 , V_14 ) ;
error = F_149 ( V_14 ) ;
if ( error ) {
F_9 ( L_5 ,
V_3 , V_14 , F_10 ( V_14 ) ) ;
break;
}
memset ( V_14 -> V_24 +
( V_205 - F_5 ( V_3 , V_40 . V_238 ) ) ,
0 , V_234 - V_205 + 1 ) ;
F_143 ( V_14 ) ;
F_150 ( V_14 ) ;
F_151 ( V_14 ) ;
F_148 ( V_3 , V_14 ) ;
error = F_149 ( V_14 ) ;
if ( error ) {
F_9 ( L_6 ,
V_3 , V_14 , F_10 ( V_14 ) ) ;
break;
}
}
F_152 ( V_14 ) ;
return error ;
}
STATIC int
F_153 (
T_1 * V_1 ,
T_20 V_205 ,
T_20 V_123 ,
int V_207 )
{
int V_54 ;
int V_55 ;
T_7 V_242 ;
int error ;
T_9 V_213 ;
T_10 V_57 ;
T_3 V_40 ;
T_20 V_243 ;
T_21 V_244 = 0 ;
T_2 * V_3 ;
int V_235 ;
T_12 V_116 ;
T_12 V_245 ;
int V_216 ;
T_7 V_212 ;
T_6 * V_35 ;
int V_246 = 1 ;
V_3 = V_1 -> V_4 ;
F_154 ( V_1 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_123 <= 0 )
return error ;
V_216 = F_130 ( V_1 ) ;
V_212 = F_3 ( V_3 , V_205 ) ;
V_242 = F_132 ( V_3 , V_205 + V_123 ) ;
if ( V_207 & V_247 )
V_246 = 0 ;
if ( V_246 ) {
F_15 ( V_1 , V_47 ) ;
F_63 ( V_1 ) ;
}
V_245 = F_155 ( T_12 , 1 << V_3 -> V_225 . V_248 , V_249 ) ;
V_243 = V_205 & ~ ( V_245 - 1 ) ;
if ( F_58 ( F_56 ( V_1 ) ) != 0 ) {
error = F_156 ( V_1 , V_243 , - 1 , V_250 ) ;
if ( error )
goto V_251;
}
if ( V_216 && ! F_157 ( & V_3 -> V_225 ) ) {
V_235 = 1 ;
error = F_2 ( NULL , V_1 , V_212 ,
1 , 0 , NULL , 0 , & V_40 , & V_235 , NULL ) ;
if ( error )
goto V_251;
ASSERT ( V_235 == 0 || V_235 == 1 ) ;
if ( V_235 && V_40 . V_16 != V_43 ) {
T_4 V_252 ;
ASSERT ( V_40 . V_16 != V_239 ) ;
V_252 = V_40 . V_16 ;
V_244 = F_133 ( V_252 , V_3 -> V_225 . V_226 ) ;
if ( V_244 )
V_212 += V_3 -> V_225 . V_226 - V_244 ;
}
V_235 = 1 ;
error = F_2 ( NULL , V_1 , V_242 - 1 ,
1 , 0 , NULL , 0 , & V_40 , & V_235 , NULL ) ;
if ( error )
goto V_251;
ASSERT ( V_235 == 0 || V_235 == 1 ) ;
if ( V_235 && V_40 . V_16 != V_43 ) {
ASSERT ( V_40 . V_16 != V_239 ) ;
V_244 ++ ;
if ( V_244 && ( V_244 != V_3 -> V_225 . V_226 ) )
V_242 -= V_244 ;
}
}
if ( ( V_55 = ( V_242 <= V_212 ) ) )
error = F_140 ( V_1 , V_205 , V_205 + V_123 - 1 ) ;
else {
if ( V_205 < F_5 ( V_3 , V_212 ) )
error = F_140 ( V_1 , V_205 ,
F_5 ( V_3 , V_212 ) - 1 ) ;
if ( ! error &&
F_5 ( V_3 , V_242 ) < V_205 + V_123 )
error = F_140 ( V_1 ,
F_5 ( V_3 , V_242 ) ,
V_205 + V_123 - 1 ) ;
}
V_116 = F_136 ( V_3 , 0 ) ;
while ( ! error && ! V_55 ) {
V_35 = F_21 ( V_3 , V_229 ) ;
V_35 -> V_253 |= V_254 ;
error = F_24 ( V_35 ,
V_116 ,
F_137 ( V_3 ) ,
0 ,
V_48 ,
V_230 ) ;
if ( error ) {
ASSERT ( error == V_128 || F_14 ( V_3 ) ) ;
F_23 ( V_35 , 0 ) ;
break;
}
F_15 ( V_1 , V_50 ) ;
error = F_88 ( V_35 , V_3 ,
V_1 -> V_255 , V_1 -> V_256 ,
V_116 , 0 , V_228 ) ;
if ( error )
goto V_65;
F_26 ( V_35 , V_1 ) ;
F_32 ( & V_57 , & V_213 ) ;
error = F_37 ( V_35 , V_1 , V_212 ,
V_242 - V_212 ,
0 , 2 , & V_213 , & V_57 , & V_55 ) ;
if ( error ) {
goto V_64;
}
error = F_38 ( & V_35 , & V_57 , & V_54 ) ;
if ( error ) {
goto V_64;
}
error = F_28 ( V_35 , V_51 ) ;
F_17 ( V_1 , V_50 ) ;
}
V_251:
if ( V_246 )
F_17 ( V_1 , V_47 ) ;
return error ;
V_64:
F_42 ( & V_57 ) ;
V_65:
F_23 ( V_35 , V_51 | V_52 ) ;
F_17 ( V_1 , V_246 ? ( V_50 | V_47 ) :
V_50 ) ;
return error ;
}
int
F_158 (
T_1 * V_1 ,
int V_257 ,
T_22 * V_258 ,
T_20 V_205 ,
int V_207 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_259 ;
int error ;
T_23 V_260 ;
int V_261 ;
T_20 V_262 ;
T_20 V_263 ;
T_6 * V_35 ;
struct V_264 V_264 ;
int V_265 ;
if ( ! F_50 ( V_1 -> V_6 . V_27 ) )
return F_8 ( V_221 ) ;
switch ( V_258 -> V_266 ) {
case 0 :
break;
case 1 :
V_258 -> V_267 += V_205 ;
break;
case 2 :
V_258 -> V_267 += V_1 -> V_42 ;
break;
default:
return F_8 ( V_221 ) ;
}
V_263 = V_258 -> V_268 > 0 ? V_258 -> V_268 - 1 : V_258 -> V_268 ;
if ( ( V_258 -> V_267 < 0 )
|| ( V_258 -> V_267 > F_19 ( V_3 ) )
|| ( V_258 -> V_267 + V_263 < 0 )
|| ( V_258 -> V_267 + V_263 > F_19 ( V_3 ) ) )
return F_8 ( V_221 ) ;
V_258 -> V_266 = 0 ;
V_262 = V_258 -> V_267 ;
V_260 = V_1 -> V_42 ;
V_261 = V_259 = 0 ;
V_265 = V_269 ;
switch ( V_257 ) {
case V_270 :
V_265 |= V_271 ;
F_159 ( V_1 , V_262 , V_262 + V_258 -> V_268 , 0 ) ;
case V_272 :
case V_273 :
error = F_128 ( V_1 , V_262 , V_258 -> V_268 ,
V_265 , V_207 ) ;
if ( error )
return error ;
V_261 = 1 ;
break;
case V_274 :
case V_275 :
if ( ( error = F_153 ( V_1 , V_262 , V_258 -> V_268 ,
V_207 ) ) )
return error ;
break;
case V_276 :
case V_277 :
case V_278 :
case V_279 :
if ( V_262 > V_260 ) {
error = F_128 ( V_1 , V_260 ,
V_262 - V_260 , 0 , V_207 ) ;
if ( error )
break;
}
V_264 . V_280 = V_281 ;
V_264 . V_282 = V_262 ;
error = F_160 ( V_1 , & V_264 , V_207 ) ;
if ( error )
return error ;
V_259 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_8 ( V_221 ) ;
}
V_35 = F_21 ( V_3 , V_283 ) ;
if ( ( error = F_24 ( V_35 , 0 , F_161 ( V_3 ) ,
0 , 0 , 0 ) ) ) {
F_23 ( V_35 , 0 ) ;
return error ;
}
F_15 ( V_1 , V_50 ) ;
F_26 ( V_35 , V_1 ) ;
if ( ( V_207 & V_284 ) == 0 ) {
V_1 -> V_6 . V_27 &= ~ V_285 ;
if ( V_1 -> V_6 . V_27 & V_286 )
V_1 -> V_6 . V_27 &= ~ V_287 ;
F_94 ( V_35 , V_1 , V_136 | V_137 ) ;
}
if ( V_261 )
V_1 -> V_6 . V_84 |= V_85 ;
else if ( V_259 )
V_1 -> V_6 . V_84 &= ~ V_85 ;
F_31 ( V_35 , V_1 , V_62 ) ;
if ( V_207 & V_288 )
F_97 ( V_35 ) ;
error = F_28 ( V_35 , 0 ) ;
F_17 ( V_1 , V_50 ) ;
return error ;
}
