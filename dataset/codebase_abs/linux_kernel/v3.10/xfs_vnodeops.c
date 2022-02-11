int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
bool V_3 )
{
T_3 * V_4 ;
int error ;
T_4 V_5 ;
T_4 V_6 ;
T_5 V_7 ;
int V_8 ;
T_6 V_9 ;
V_5 = F_2 ( V_1 , ( V_10 ) F_3 ( V_2 ) ) ;
V_6 = F_2 ( V_1 , V_1 -> V_11 -> V_12 ) ;
if ( V_6 <= V_5 )
return 0 ;
V_7 = V_6 - V_5 ;
V_8 = 1 ;
F_4 ( V_2 , V_13 ) ;
error = F_5 ( V_2 , V_5 , V_7 , & V_9 , & V_8 , 0 ) ;
F_6 ( V_2 , V_13 ) ;
if ( ! error && ( V_8 != 0 ) &&
( V_9 . V_14 != V_15 ||
V_2 -> V_16 ) ) {
error = F_7 ( V_2 , 0 ) ;
if ( error )
return error ;
V_4 = F_8 ( V_1 , V_17 ) ;
if ( V_3 ) {
if ( ! F_9 ( V_2 , V_18 ) ) {
F_10 ( V_4 , 0 ) ;
return V_19 ;
}
}
error = F_11 ( V_4 , 0 ,
F_12 ( V_1 ) ,
0 , V_20 ,
V_21 ) ;
if ( error ) {
ASSERT ( F_13 ( V_1 ) ) ;
F_10 ( V_4 , 0 ) ;
if ( V_3 )
F_6 ( V_2 , V_18 ) ;
return error ;
}
F_4 ( V_2 , V_22 ) ;
F_14 ( V_4 , V_2 , 0 ) ;
error = F_15 ( & V_4 , V_2 , V_23 ,
F_3 ( V_2 ) ) ;
if ( error ) {
F_10 ( V_4 ,
( V_24 |
V_25 ) ) ;
} else {
error = F_16 ( V_4 ,
V_24 ) ;
if ( ! error )
F_17 ( V_2 ) ;
}
F_6 ( V_2 , V_22 ) ;
if ( V_3 )
F_6 ( V_2 , V_18 ) ;
}
return error ;
}
int
F_18 (
T_2 * V_2 )
{
T_1 * V_1 = V_2 -> V_26 ;
int error ;
if ( ! F_19 ( V_2 -> V_27 . V_28 ) || ( V_2 -> V_27 . V_28 == 0 ) )
return 0 ;
if ( V_1 -> V_29 & V_30 )
return 0 ;
if ( ! F_13 ( V_1 ) ) {
int V_31 ;
if ( ( V_2 -> V_27 . V_32 == 0 ) && F_20 ( V_2 ) )
F_21 ( V_2 ) ;
V_31 = F_22 ( V_2 , V_33 ) ;
if ( V_31 ) {
F_23 ( V_2 , V_34 ) ;
if ( F_24 ( F_25 ( V_2 ) ) && V_2 -> V_16 > 0 ) {
error = - F_26 ( F_25 ( V_2 ) -> V_35 ) ;
if ( error )
return error ;
}
}
}
if ( V_2 -> V_27 . V_32 == 0 )
return 0 ;
if ( F_27 ( V_2 , false ) ) {
if ( F_28 ( V_2 , V_34 ) )
return 0 ;
error = F_1 ( V_1 , V_2 , true ) ;
if ( error && error != V_19 )
return error ;
if ( V_2 -> V_16 )
F_29 ( V_2 , V_34 ) ;
}
return 0 ;
}
int
F_30 (
T_2 * V_2 )
{
T_7 V_36 ;
T_8 V_37 ;
int V_38 ;
T_3 * V_4 ;
T_1 * V_1 ;
int error ;
int V_39 = 0 ;
if ( V_2 -> V_27 . V_28 == 0 || F_31 ( F_25 ( V_2 ) ) ) {
ASSERT ( V_2 -> V_40 . V_41 == 0 ) ;
ASSERT ( V_2 -> V_40 . V_42 == 0 ) ;
return V_43 ;
}
V_1 = V_2 -> V_26 ;
error = 0 ;
if ( V_1 -> V_29 & V_30 )
goto V_44;
if ( V_2 -> V_27 . V_32 != 0 ) {
if ( F_27 ( V_2 , true ) ) {
error = F_1 ( V_1 , V_2 , false ) ;
if ( error )
return V_43 ;
}
goto V_44;
}
if ( F_19 ( V_2 -> V_27 . V_28 ) &&
( V_2 -> V_27 . V_45 != 0 || F_3 ( V_2 ) != 0 ||
V_2 -> V_27 . V_46 > 0 || V_2 -> V_16 > 0 ) )
V_39 = 1 ;
error = F_7 ( V_2 , 0 ) ;
if ( error )
return V_43 ;
V_4 = F_8 ( V_1 , V_17 ) ;
error = F_11 ( V_4 , 0 ,
( V_39 || F_32 ( V_2 -> V_27 . V_28 ) ) ?
F_12 ( V_1 ) :
F_33 ( V_1 ) ,
0 ,
V_20 ,
V_21 ) ;
if ( error ) {
ASSERT ( F_13 ( V_1 ) ) ;
F_10 ( V_4 , 0 ) ;
return V_43 ;
}
F_4 ( V_2 , V_22 ) ;
F_14 ( V_4 , V_2 , 0 ) ;
if ( F_32 ( V_2 -> V_27 . V_28 ) ) {
if ( V_2 -> V_27 . V_45 > F_34 ( V_2 ) ) {
error = F_35 ( V_2 , & V_4 ) ;
if ( error )
goto V_47;
} else if ( V_2 -> V_40 . V_48 > 0 ) {
F_36 ( V_2 , - ( V_2 -> V_40 . V_48 ) ,
V_23 ) ;
ASSERT ( V_2 -> V_40 . V_48 == 0 ) ;
}
} else if ( V_39 ) {
V_2 -> V_27 . V_45 = 0 ;
F_37 ( V_4 , V_2 , V_49 ) ;
error = F_15 ( & V_4 , V_2 , V_23 , 0 ) ;
if ( error )
goto V_47;
ASSERT ( V_2 -> V_27 . V_46 == 0 ) ;
}
if ( V_2 -> V_27 . V_50 > 0 ) {
ASSERT ( V_2 -> V_27 . V_51 != 0 ) ;
error = F_16 ( V_4 , V_24 ) ;
if ( error )
goto V_52;
F_6 ( V_2 , V_22 ) ;
error = F_38 ( V_2 ) ;
if ( error )
goto V_44;
V_4 = F_8 ( V_1 , V_17 ) ;
error = F_11 ( V_4 , 0 ,
F_33 ( V_1 ) ,
0 , V_20 ,
V_53 ) ;
if ( error ) {
F_10 ( V_4 , 0 ) ;
goto V_44;
}
F_4 ( V_2 , V_22 ) ;
F_14 ( V_4 , V_2 , 0 ) ;
}
if ( V_2 -> V_54 )
F_39 ( V_2 , V_55 ) ;
ASSERT ( V_2 -> V_27 . V_50 == 0 ) ;
F_40 ( & V_36 , & V_37 ) ;
error = F_41 ( V_4 , V_2 , & V_36 ) ;
if ( error ) {
if ( ! F_13 ( V_1 ) ) {
F_42 ( V_1 , L_1 ,
V_56 , error ) ;
F_43 ( V_1 , V_57 ) ;
}
F_10 ( V_4 , V_24 | V_25 ) ;
} else {
F_44 ( V_4 , V_2 , V_58 , - 1 ) ;
error = F_45 ( & V_4 , & V_36 , & V_38 ) ;
if ( error )
F_42 ( V_1 , L_2 ,
V_56 , error ) ;
error = F_16 ( V_4 , V_24 ) ;
if ( error )
F_42 ( V_1 , L_3 ,
V_56 , error ) ;
}
F_46 ( V_2 ) ;
V_52:
F_6 ( V_2 , V_22 ) ;
V_44:
return V_43 ;
V_47:
F_10 ( V_4 , V_24 | V_25 ) ;
goto V_52;
}
int
F_47 (
T_2 * V_59 ,
struct V_60 * V_61 ,
T_2 * * V_62 ,
struct V_60 * V_63 )
{
T_9 V_64 ;
int error ;
T_10 V_65 ;
F_48 ( V_59 , V_61 ) ;
if ( F_13 ( V_59 -> V_26 ) )
return F_49 ( V_66 ) ;
V_65 = F_50 ( V_59 ) ;
error = F_51 ( NULL , V_59 , V_61 , & V_64 , V_63 ) ;
F_52 ( V_59 , V_65 ) ;
if ( error )
goto V_44;
error = F_53 ( V_59 -> V_26 , NULL , V_64 , 0 , 0 , V_62 ) ;
if ( error )
goto V_67;
return 0 ;
V_67:
if ( V_63 )
F_54 ( V_63 -> V_61 ) ;
V_44:
* V_62 = NULL ;
return error ;
}
int
F_55 (
T_2 * V_59 ,
struct V_60 * V_61 ,
T_11 V_68 ,
T_12 V_69 ,
T_2 * * V_62 )
{
int V_70 = F_56 ( V_68 ) ;
struct V_71 * V_1 = V_59 -> V_26 ;
struct V_72 * V_2 = NULL ;
struct V_73 * V_4 = NULL ;
int error ;
T_7 V_36 ;
T_8 V_37 ;
bool V_74 = false ;
T_10 V_75 ;
int V_38 ;
T_13 V_76 ;
struct V_77 * V_78 = NULL ;
struct V_77 * V_79 = NULL ;
T_10 V_80 ;
T_10 V_81 ;
T_10 V_82 ;
F_57 ( V_59 , V_61 ) ;
if ( F_13 ( V_1 ) )
return F_49 ( V_66 ) ;
if ( V_59 -> V_27 . V_83 & V_84 )
V_76 = F_58 ( V_59 ) ;
else
V_76 = V_85 ;
error = F_59 ( V_59 , F_60 () , F_61 () , V_76 ,
V_86 | V_87 , & V_78 , & V_79 ) ;
if ( error )
return error ;
if ( V_70 ) {
V_69 = 0 ;
V_80 = F_62 ( V_1 , V_61 -> V_88 ) ;
V_81 = F_63 ( V_1 ) ;
V_82 = V_89 ;
V_4 = F_8 ( V_1 , V_90 ) ;
} else {
V_80 = F_64 ( V_1 , V_61 -> V_88 ) ;
V_81 = F_65 ( V_1 ) ;
V_82 = V_91 ;
V_4 = F_8 ( V_1 , V_92 ) ;
}
V_75 = V_24 ;
error = F_11 ( V_4 , V_80 , V_81 , 0 ,
V_20 , V_82 ) ;
if ( error == V_93 ) {
F_66 ( V_1 ) ;
error = F_11 ( V_4 , V_80 , V_81 , 0 ,
V_20 , V_82 ) ;
}
if ( error == V_93 ) {
V_80 = 0 ;
error = F_11 ( V_4 , 0 , V_81 , 0 ,
V_20 , V_82 ) ;
}
if ( error ) {
V_75 = 0 ;
goto V_94;
}
F_4 ( V_59 , V_22 | V_95 ) ;
V_74 = true ;
F_40 ( & V_36 , & V_37 ) ;
error = F_67 ( V_4 , V_1 , V_78 , V_79 , V_80 , 1 , 0 ) ;
if ( error )
goto V_94;
error = F_68 ( V_4 , V_59 , V_61 , V_80 ) ;
if ( error )
goto V_94;
error = F_69 ( & V_4 , V_59 , V_68 , V_70 ? 2 : 1 , V_69 ,
V_76 , V_80 > 0 , & V_2 , & V_38 ) ;
if ( error ) {
if ( error == V_93 )
goto V_94;
goto V_96;
}
F_14 ( V_4 , V_59 , V_22 ) ;
V_74 = false ;
error = F_70 ( V_4 , V_59 , V_61 , V_2 -> V_97 ,
& V_37 , & V_36 , V_80 ?
V_80 - F_71 ( V_1 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_93 ) ;
goto V_96;
}
F_72 ( V_4 , V_59 , V_98 | V_99 ) ;
F_37 ( V_4 , V_59 , V_49 ) ;
if ( V_70 ) {
error = F_73 ( V_4 , V_2 , V_59 ) ;
if ( error )
goto V_100;
error = F_74 ( V_4 , V_59 ) ;
if ( error )
goto V_100;
}
if ( V_1 -> V_29 & ( V_101 | V_102 ) )
F_75 ( V_4 ) ;
F_76 ( V_4 , V_2 , V_78 , V_79 ) ;
error = F_45 ( & V_4 , & V_36 , & V_38 ) ;
if ( error )
goto V_100;
error = F_16 ( V_4 , V_24 ) ;
if ( error )
goto V_103;
F_77 ( V_78 ) ;
F_77 ( V_79 ) ;
* V_62 = V_2 ;
return 0 ;
V_100:
F_78 ( & V_36 ) ;
V_96:
V_75 |= V_25 ;
V_94:
F_10 ( V_4 , V_75 ) ;
V_103:
if ( V_2 )
F_79 ( V_2 ) ;
F_77 ( V_78 ) ;
F_77 ( V_79 ) ;
if ( V_74 )
F_6 ( V_59 , V_22 ) ;
return error ;
}
static inline int
F_80 ( int V_65 , int V_104 )
{
if ( V_65 & ( V_105 | V_18 ) )
V_65 |= ( V_104 + V_106 ) << V_107 ;
if ( V_65 & ( V_13 | V_22 ) )
V_65 |= ( V_104 + V_106 ) << V_108 ;
return V_65 ;
}
void
F_81 (
T_2 * * V_109 ,
int V_110 ,
T_10 V_65 )
{
int V_111 = 0 , V_112 , V_113 , V_114 ;
T_14 * V_115 ;
ASSERT ( V_109 && ( V_110 >= 2 ) ) ;
V_114 = 0 ;
V_112 = 0 ;
V_116:
for (; V_112 < V_110 ; V_112 ++ ) {
ASSERT ( V_109 [ V_112 ] ) ;
if ( V_112 && ( V_109 [ V_112 ] == V_109 [ V_112 - 1 ] ) )
continue;
if ( ! V_114 ) {
for ( V_113 = ( V_112 - 1 ) ; V_113 >= 0 && ! V_114 ; V_113 -- ) {
V_115 = ( T_14 * ) V_109 [ V_113 ] -> V_117 ;
if ( V_115 && ( V_115 -> V_118 & V_119 ) ) {
V_114 ++ ;
}
}
}
if ( V_114 ) {
ASSERT ( V_112 != 0 ) ;
if ( ! F_9 ( V_109 [ V_112 ] , F_80 ( V_65 , V_112 ) ) ) {
V_111 ++ ;
for( V_113 = V_112 - 1 ; V_113 >= 0 ; V_113 -- ) {
if ( ( V_113 != ( V_112 - 1 ) ) && V_109 [ V_113 ] ==
V_109 [ V_113 + 1 ] )
continue;
F_6 ( V_109 [ V_113 ] , V_65 ) ;
}
if ( ( V_111 % 5 ) == 0 ) {
F_82 ( 1 ) ;
#ifdef F_83
V_120 ++ ;
#endif
}
V_112 = 0 ;
V_114 = 0 ;
goto V_116;
}
} else {
F_4 ( V_109 [ V_112 ] , F_80 ( V_65 , V_112 ) ) ;
}
}
#ifdef F_83
if ( V_111 ) {
if ( V_111 < 5 ) V_121 ++ ;
else if ( V_111 < 100 ) V_122 ++ ;
else V_123 ++ ;
} else {
V_124 ++ ;
}
#endif
}
void
F_84 (
T_2 * V_125 ,
T_2 * V_126 ,
T_10 V_65 )
{
T_2 * V_127 ;
int V_111 = 0 ;
T_14 * V_115 ;
if ( V_65 & ( V_105 | V_18 ) )
ASSERT ( ( V_65 & ( V_13 | V_22 ) ) == 0 ) ;
ASSERT ( V_125 -> V_97 != V_126 -> V_97 ) ;
if ( V_125 -> V_97 > V_126 -> V_97 ) {
V_127 = V_125 ;
V_125 = V_126 ;
V_126 = V_127 ;
}
V_116:
F_4 ( V_125 , F_80 ( V_65 , 0 ) ) ;
V_115 = ( T_14 * ) V_125 -> V_117 ;
if ( V_115 && ( V_115 -> V_118 & V_119 ) ) {
if ( ! F_9 ( V_126 , F_80 ( V_65 , 1 ) ) ) {
F_6 ( V_125 , V_65 ) ;
if ( ( ++ V_111 % 5 ) == 0 )
F_82 ( 1 ) ;
goto V_116;
}
} else {
F_4 ( V_126 , F_80 ( V_65 , 1 ) ) ;
}
}
int
F_85 (
T_2 * V_59 ,
struct V_60 * V_61 ,
T_2 * V_2 )
{
T_1 * V_1 = V_59 -> V_26 ;
T_3 * V_4 = NULL ;
int V_70 = F_56 ( V_2 -> V_27 . V_28 ) ;
int error = 0 ;
T_7 V_36 ;
T_8 V_37 ;
int V_75 ;
int V_38 ;
int V_128 ;
T_10 V_80 ;
T_10 V_82 ;
F_86 ( V_59 , V_61 ) ;
if ( F_13 ( V_1 ) )
return F_49 ( V_66 ) ;
error = F_7 ( V_59 , 0 ) ;
if ( error )
goto V_129;
error = F_7 ( V_2 , 0 ) ;
if ( error )
goto V_129;
if ( V_70 ) {
V_4 = F_8 ( V_1 , V_130 ) ;
V_82 = V_131 ;
} else {
V_4 = F_8 ( V_1 , V_132 ) ;
V_82 = V_133 ;
}
V_75 = V_24 ;
V_80 = F_87 ( V_1 ) ;
error = F_11 ( V_4 , V_80 , F_88 ( V_1 ) , 0 ,
V_20 , V_82 ) ;
if ( error == V_93 ) {
V_80 = 0 ;
error = F_11 ( V_4 , 0 , F_88 ( V_1 ) , 0 ,
V_20 , V_82 ) ;
}
if ( error ) {
ASSERT ( error != V_93 ) ;
V_75 = 0 ;
goto V_94;
}
F_84 ( V_59 , V_2 , V_22 ) ;
F_14 ( V_4 , V_59 , V_22 ) ;
F_14 ( V_4 , V_2 , V_22 ) ;
if ( V_70 ) {
ASSERT ( V_2 -> V_27 . V_32 >= 2 ) ;
if ( V_2 -> V_27 . V_32 != 2 ) {
error = F_49 ( V_134 ) ;
goto V_94;
}
if ( ! F_89 ( V_2 ) ) {
error = F_49 ( V_134 ) ;
goto V_94;
}
}
F_40 ( & V_36 , & V_37 ) ;
error = F_90 ( V_4 , V_59 , V_61 , V_2 -> V_97 ,
& V_37 , & V_36 , V_80 ) ;
if ( error ) {
ASSERT ( error != V_135 ) ;
goto V_100;
}
F_72 ( V_4 , V_59 , V_98 | V_99 ) ;
if ( V_70 ) {
error = F_91 ( V_4 , V_59 ) ;
if ( error )
goto V_100;
error = F_91 ( V_4 , V_2 ) ;
if ( error )
goto V_100;
} else {
F_37 ( V_4 , V_59 , V_49 ) ;
}
error = F_91 ( V_4 , V_2 ) ;
if ( error )
goto V_100;
V_128 = ( V_2 -> V_27 . V_32 == 0 ) ;
if ( V_1 -> V_29 & ( V_101 | V_102 ) )
F_75 ( V_4 ) ;
error = F_45 ( & V_4 , & V_36 , & V_38 ) ;
if ( error )
goto V_100;
error = F_16 ( V_4 , V_24 ) ;
if ( error )
goto V_129;
if ( ! V_70 && V_128 && F_20 ( V_2 ) )
F_21 ( V_2 ) ;
return 0 ;
V_100:
F_78 ( & V_36 ) ;
V_75 |= V_25 ;
V_94:
F_10 ( V_4 , V_75 ) ;
V_129:
return error ;
}
int
F_92 (
T_2 * V_136 ,
T_2 * V_137 ,
struct V_60 * V_138 )
{
T_1 * V_1 = V_136 -> V_26 ;
T_3 * V_4 ;
int error ;
T_7 V_36 ;
T_8 V_37 ;
int V_75 ;
int V_38 ;
int V_80 ;
F_93 ( V_136 , V_138 ) ;
ASSERT ( ! F_56 ( V_137 -> V_27 . V_28 ) ) ;
if ( F_13 ( V_1 ) )
return F_49 ( V_66 ) ;
error = F_7 ( V_137 , 0 ) ;
if ( error )
goto V_129;
error = F_7 ( V_136 , 0 ) ;
if ( error )
goto V_129;
V_4 = F_8 ( V_1 , V_139 ) ;
V_75 = V_24 ;
V_80 = F_94 ( V_1 , V_138 -> V_88 ) ;
error = F_11 ( V_4 , V_80 , F_95 ( V_1 ) , 0 ,
V_20 , V_140 ) ;
if ( error == V_93 ) {
V_80 = 0 ;
error = F_11 ( V_4 , 0 , F_95 ( V_1 ) , 0 ,
V_20 , V_140 ) ;
}
if ( error ) {
V_75 = 0 ;
goto V_141;
}
F_84 ( V_137 , V_136 , V_22 ) ;
F_14 ( V_4 , V_137 , V_22 ) ;
F_14 ( V_4 , V_136 , V_22 ) ;
if ( F_96 ( ( V_136 -> V_27 . V_83 & V_84 ) &&
( F_58 ( V_136 ) != F_58 ( V_137 ) ) ) ) {
error = F_49 ( V_142 ) ;
goto V_141;
}
error = F_68 ( V_4 , V_136 , V_138 , V_80 ) ;
if ( error )
goto V_141;
F_40 ( & V_36 , & V_37 ) ;
error = F_70 ( V_4 , V_136 , V_138 , V_137 -> V_97 ,
& V_37 , & V_36 , V_80 ) ;
if ( error )
goto V_143;
F_72 ( V_4 , V_136 , V_98 | V_99 ) ;
F_37 ( V_4 , V_136 , V_49 ) ;
error = F_74 ( V_4 , V_137 ) ;
if ( error )
goto V_143;
if ( V_1 -> V_29 & ( V_101 | V_102 ) ) {
F_75 ( V_4 ) ;
}
error = F_45 ( & V_4 , & V_36 , & V_38 ) ;
if ( error ) {
F_78 ( & V_36 ) ;
goto V_143;
}
return F_16 ( V_4 , V_24 ) ;
V_143:
V_75 |= V_25 ;
V_141:
F_10 ( V_4 , V_75 ) ;
V_129:
return error ;
}
int
F_97 (
T_2 * V_2 ,
T_15 V_144 ,
T_16 V_145 )
{
T_1 * V_1 = V_2 -> V_26 ;
T_3 * V_4 ;
int error ;
if ( ! F_98 ( V_146 ) )
return F_49 ( V_147 ) ;
if ( F_13 ( V_1 ) )
return F_49 ( V_66 ) ;
V_4 = F_8 ( V_1 , V_148 ) ;
error = F_11 ( V_4 , 0 , F_99 ( V_1 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_10 ( V_4 , 0 ) ;
return error ;
}
F_4 ( V_2 , V_22 ) ;
F_14 ( V_4 , V_2 , V_22 ) ;
V_2 -> V_27 . V_149 = V_144 ;
V_2 -> V_27 . V_150 = V_145 ;
F_37 ( V_4 , V_2 , V_49 ) ;
error = F_16 ( V_4 , 0 ) ;
return error ;
}
STATIC int
F_100 (
T_2 * V_2 ,
T_17 V_151 ,
T_17 V_88 ,
int V_152 ,
int V_153 )
{
T_1 * V_1 = V_2 -> V_26 ;
T_17 V_154 ;
T_5 V_155 ;
T_5 V_156 ;
T_18 V_157 , V_127 ;
T_4 V_158 ;
T_8 V_159 ;
int V_8 ;
int V_160 ;
int V_161 ;
T_3 * V_4 ;
T_6 V_162 [ 1 ] , * V_163 ;
T_7 V_36 ;
T_10 V_164 , V_80 , V_165 ;
int V_38 ;
int error ;
F_101 ( V_2 ) ;
if ( F_13 ( V_1 ) )
return F_49 ( V_66 ) ;
error = F_7 ( V_2 , 0 ) ;
if ( error )
return error ;
if ( V_88 <= 0 )
return F_49 ( V_166 ) ;
V_161 = F_102 ( V_2 ) ;
V_157 = F_103 ( V_2 ) ;
V_154 = V_88 ;
V_163 = & V_162 [ 0 ] ;
V_8 = 1 ;
V_158 = F_104 ( V_1 , V_151 ) ;
V_156 = F_2 ( V_1 , V_154 ) ;
while ( V_156 && ! error ) {
T_4 V_167 , V_168 ;
if ( F_96 ( V_157 ) ) {
V_167 = V_158 ;
F_105 ( V_167 , V_157 ) ;
V_167 *= V_157 ;
V_168 = V_158 + V_156 ;
if ( ( V_127 = F_106 ( V_158 , V_157 ) ) )
V_168 += V_127 ;
if ( ( V_127 = F_106 ( V_168 , V_157 ) ) )
V_168 += V_157 - V_127 ;
} else {
V_167 = 0 ;
V_168 = V_156 ;
}
V_80 = F_107 ( T_4 , ( V_168 - V_167 ) , ( V_169 * V_8 ) ) ;
if ( F_96 ( V_161 ) ) {
V_165 = V_164 = V_80 ;
V_165 /= V_1 -> V_170 . V_171 ;
V_80 = F_108 ( V_1 , 0 ) ;
V_160 = V_172 ;
} else {
V_165 = 0 ;
V_80 = V_164 = F_108 ( V_1 , V_80 ) ;
V_160 = V_173 ;
}
V_4 = F_8 ( V_1 , V_174 ) ;
error = F_11 ( V_4 , V_80 ,
F_109 ( V_1 ) , V_165 ,
V_20 ,
V_175 ) ;
if ( error ) {
ASSERT ( error == V_93 || F_13 ( V_1 ) ) ;
F_10 ( V_4 , 0 ) ;
break;
}
F_4 ( V_2 , V_22 ) ;
error = F_110 ( V_4 , V_2 , V_164 ,
0 , V_160 ) ;
if ( error )
goto V_176;
F_14 ( V_4 , V_2 , 0 ) ;
F_40 ( & V_36 , & V_159 ) ;
error = F_111 ( V_4 , V_2 , V_158 ,
V_156 , V_152 , & V_159 ,
0 , V_163 , & V_8 , & V_36 ) ;
if ( error ) {
goto V_177;
}
error = F_45 ( & V_4 , & V_36 , & V_38 ) ;
if ( error ) {
goto V_177;
}
error = F_16 ( V_4 , V_24 ) ;
F_6 ( V_2 , V_22 ) ;
if ( error ) {
break;
}
V_155 = V_163 -> V_178 ;
if ( V_8 == 0 ) {
error = F_49 ( V_93 ) ;
break;
}
V_158 += V_155 ;
V_156 -= V_155 ;
}
return error ;
V_177:
F_78 ( & V_36 ) ;
F_112 ( V_4 , V_2 , ( long ) V_164 , 0 , V_160 ) ;
V_176:
F_10 ( V_4 , V_24 | V_25 ) ;
F_6 ( V_2 , V_22 ) ;
return error ;
}
STATIC int
F_113 (
T_2 * V_2 ,
T_17 V_179 ,
T_17 V_180 )
{
T_6 V_9 ;
T_4 V_181 ;
T_17 V_182 ;
T_17 V_151 ;
T_19 * V_183 ;
T_1 * V_1 = V_2 -> V_26 ;
int V_184 ;
int error = 0 ;
if ( V_179 >= F_3 ( V_2 ) )
return 0 ;
if ( V_180 > F_3 ( V_2 ) )
V_180 = F_3 ( V_2 ) ;
V_183 = F_114 ( F_102 ( V_2 ) ?
V_1 -> V_185 : V_1 -> V_186 ,
F_115 ( V_1 -> V_170 . V_187 ) , 0 ) ;
if ( ! V_183 )
return F_49 ( V_188 ) ;
F_116 ( V_183 ) ;
for ( V_151 = V_179 ; V_151 <= V_180 ; V_151 = V_182 + 1 ) {
V_181 = F_104 ( V_1 , V_151 ) ;
V_184 = 1 ;
error = F_5 ( V_2 , V_181 , 1 , & V_9 , & V_184 , 0 ) ;
if ( error || V_184 < 1 )
break;
ASSERT ( V_9 . V_178 >= 1 ) ;
ASSERT ( V_9 . V_189 == V_181 ) ;
V_182 = F_117 ( V_1 , V_9 . V_189 + 1 ) - 1 ;
if ( V_182 > V_180 )
V_182 = V_180 ;
if ( V_9 . V_14 == V_15 )
continue;
ASSERT ( V_9 . V_14 != V_190 ) ;
if ( V_9 . V_191 == V_192 )
continue;
F_118 ( V_183 ) ;
F_119 ( V_183 ) ;
F_120 ( V_183 ) ;
F_121 ( V_183 , F_122 ( V_2 , V_9 . V_14 ) ) ;
F_123 ( V_1 , V_183 ) ;
error = F_124 ( V_183 ) ;
if ( error ) {
F_125 ( V_183 ,
L_4 ) ;
break;
}
memset ( V_183 -> V_193 +
( V_151 - F_117 ( V_1 , V_9 . V_189 ) ) ,
0 , V_182 - V_151 + 1 ) ;
F_118 ( V_183 ) ;
F_126 ( V_183 ) ;
F_127 ( V_183 ) ;
F_123 ( V_1 , V_183 ) ;
error = F_124 ( V_183 ) ;
if ( error ) {
F_125 ( V_183 ,
L_5 ) ;
break;
}
}
F_128 ( V_183 ) ;
return error ;
}
STATIC int
F_129 (
T_2 * V_2 ,
T_17 V_151 ,
T_17 V_88 ,
int V_153 )
{
int V_38 ;
int V_194 ;
T_4 V_195 ;
int error ;
T_8 V_159 ;
T_7 V_36 ;
T_6 V_9 ;
T_17 V_196 ;
T_18 V_197 = 0 ;
T_1 * V_1 ;
int V_184 ;
T_10 V_80 ;
T_17 V_198 ;
int V_161 ;
T_4 V_158 ;
T_3 * V_4 ;
int V_3 = 1 ;
V_1 = V_2 -> V_26 ;
F_130 ( V_2 ) ;
error = F_7 ( V_2 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_88 <= 0 )
return error ;
V_161 = F_102 ( V_2 ) ;
V_158 = F_2 ( V_1 , V_151 ) ;
V_195 = F_104 ( V_1 , V_151 + V_88 ) ;
if ( V_153 & V_199 )
V_3 = 0 ;
if ( V_3 ) {
F_4 ( V_2 , V_18 ) ;
F_131 ( F_25 ( V_2 ) ) ;
}
V_198 = F_132 ( T_17 , 1 << V_1 -> V_170 . V_200 , V_201 ) ;
V_196 = V_151 & ~ ( V_198 - 1 ) ;
error = - F_133 ( F_25 ( V_2 ) -> V_35 ,
V_196 , - 1 ) ;
if ( error )
goto V_202;
F_134 ( F_25 ( V_2 ) , V_196 , - 1 ) ;
if ( V_161 && ! F_135 ( & V_1 -> V_170 ) ) {
V_184 = 1 ;
error = F_5 ( V_2 , V_158 , 1 ,
& V_9 , & V_184 , 0 ) ;
if ( error )
goto V_202;
ASSERT ( V_184 == 0 || V_184 == 1 ) ;
if ( V_184 && V_9 . V_14 != V_15 ) {
T_20 V_203 ;
ASSERT ( V_9 . V_14 != V_190 ) ;
V_203 = V_9 . V_14 ;
V_197 = F_105 ( V_203 , V_1 -> V_170 . V_171 ) ;
if ( V_197 )
V_158 += V_1 -> V_170 . V_171 - V_197 ;
}
V_184 = 1 ;
error = F_5 ( V_2 , V_195 - 1 , 1 ,
& V_9 , & V_184 , 0 ) ;
if ( error )
goto V_202;
ASSERT ( V_184 == 0 || V_184 == 1 ) ;
if ( V_184 && V_9 . V_14 != V_15 ) {
ASSERT ( V_9 . V_14 != V_190 ) ;
V_197 ++ ;
if ( V_197 && ( V_197 != V_1 -> V_170 . V_171 ) )
V_195 -= V_197 ;
}
}
if ( ( V_194 = ( V_195 <= V_158 ) ) )
error = F_113 ( V_2 , V_151 , V_151 + V_88 - 1 ) ;
else {
if ( V_151 < F_117 ( V_1 , V_158 ) )
error = F_113 ( V_2 , V_151 ,
F_117 ( V_1 , V_158 ) - 1 ) ;
if ( ! error &&
F_117 ( V_1 , V_195 ) < V_151 + V_88 )
error = F_113 ( V_2 ,
F_117 ( V_1 , V_195 ) ,
V_151 + V_88 - 1 ) ;
}
V_80 = F_108 ( V_1 , 0 ) ;
while ( ! error && ! V_194 ) {
V_4 = F_8 ( V_1 , V_174 ) ;
V_4 -> V_204 |= V_205 ;
error = F_11 ( V_4 ,
V_80 ,
F_109 ( V_1 ) ,
0 ,
V_20 ,
V_175 ) ;
if ( error ) {
ASSERT ( error == V_93 || F_13 ( V_1 ) ) ;
F_10 ( V_4 , 0 ) ;
break;
}
F_4 ( V_2 , V_22 ) ;
error = F_67 ( V_4 , V_1 ,
V_2 -> V_206 , V_2 -> V_207 ,
V_80 , 0 , V_173 ) ;
if ( error )
goto V_176;
F_14 ( V_4 , V_2 , 0 ) ;
F_40 ( & V_36 , & V_159 ) ;
error = F_136 ( V_4 , V_2 , V_158 ,
V_195 - V_158 ,
0 , 2 , & V_159 , & V_36 , & V_194 ) ;
if ( error ) {
goto V_177;
}
error = F_45 ( & V_4 , & V_36 , & V_38 ) ;
if ( error ) {
goto V_177;
}
error = F_16 ( V_4 , V_24 ) ;
F_6 ( V_2 , V_22 ) ;
}
V_202:
if ( V_3 )
F_6 ( V_2 , V_18 ) ;
return error ;
V_177:
F_78 ( & V_36 ) ;
V_176:
F_10 ( V_4 , V_24 | V_25 ) ;
F_6 ( V_2 , V_3 ? ( V_22 | V_18 ) :
V_22 ) ;
return error ;
}
STATIC int
F_137 (
struct V_72 * V_2 ,
T_17 V_151 ,
T_17 V_88 ,
int V_153 )
{
struct V_71 * V_1 = V_2 -> V_26 ;
T_10 V_208 ;
T_17 V_209 ;
T_17 V_210 ;
int error ;
V_208 = F_132 ( T_10 , 1 << V_1 -> V_170 . V_200 , V_201 ) ;
V_209 = F_138 ( V_151 , V_208 ) ;
V_210 = F_139 ( V_151 + V_88 , V_208 ) ;
ASSERT ( V_209 >= V_151 ) ;
ASSERT ( V_210 <= V_151 + V_88 ) ;
if ( ! ( V_153 & V_199 ) )
F_4 ( V_2 , V_18 ) ;
if ( V_209 < V_210 - 1 ) {
F_134 ( F_25 ( V_2 ) , V_209 ,
V_210 - 1 ) ;
error = F_100 ( V_2 , V_209 ,
V_210 - V_209 - 1 ,
V_211 | V_212 ,
V_153 ) ;
if ( error )
goto V_52;
if ( V_209 != V_151 )
error = F_140 ( V_2 , V_151 , V_209 - V_151 ) ;
if ( error )
goto V_52;
if ( V_210 != V_151 + V_88 )
error = F_140 ( V_2 , V_210 ,
V_151 + V_88 - V_210 ) ;
} else {
error = F_140 ( V_2 , V_151 , V_88 ) ;
}
V_52:
if ( ! ( V_153 & V_199 ) )
F_6 ( V_2 , V_18 ) ;
return error ;
}
int
F_141 (
T_2 * V_2 ,
int V_213 ,
T_21 * V_214 ,
T_17 V_151 ,
int V_153 )
{
T_1 * V_1 = V_2 -> V_26 ;
int V_215 ;
int error ;
T_22 V_216 ;
int V_217 ;
T_17 V_218 ;
T_3 * V_4 ;
struct V_219 V_219 ;
if ( ! F_19 ( V_2 -> V_27 . V_28 ) )
return F_49 ( V_166 ) ;
switch ( V_214 -> V_220 ) {
case 0 :
break;
case 1 :
V_214 -> V_221 += V_151 ;
break;
case 2 :
V_214 -> V_221 += F_3 ( V_2 ) ;
break;
default:
return F_49 ( V_166 ) ;
}
switch ( V_213 ) {
case V_222 :
case V_223 :
case V_224 :
case V_225 :
case V_226 :
if ( V_214 -> V_227 <= 0 )
return F_49 ( V_166 ) ;
break;
default:
V_214 -> V_227 = 0 ;
break;
}
if ( V_214 -> V_221 < 0 ||
V_214 -> V_221 > V_1 -> V_11 -> V_12 ||
V_214 -> V_221 + V_214 -> V_227 < 0 ||
V_214 -> V_221 + V_214 -> V_227 >= V_1 -> V_11 -> V_12 )
return F_49 ( V_166 ) ;
V_214 -> V_220 = 0 ;
V_218 = V_214 -> V_221 ;
V_216 = F_3 ( V_2 ) ;
V_217 = V_215 = 0 ;
switch ( V_213 ) {
case V_222 :
error = F_137 ( V_2 , V_218 , V_214 -> V_227 ,
V_153 ) ;
if ( error )
return error ;
V_217 = 1 ;
break;
case V_223 :
case V_224 :
error = F_100 ( V_2 , V_218 , V_214 -> V_227 ,
V_211 , V_153 ) ;
if ( error )
return error ;
V_217 = 1 ;
break;
case V_225 :
case V_226 :
if ( ( error = F_129 ( V_2 , V_218 , V_214 -> V_227 ,
V_153 ) ) )
return error ;
break;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
F_4 ( V_2 , V_18 ) ;
if ( V_218 > V_216 ) {
error = F_100 ( V_2 , V_216 ,
V_218 - V_216 , 0 ,
V_153 | V_199 ) ;
if ( error ) {
F_6 ( V_2 , V_18 ) ;
break;
}
}
V_219 . V_232 = V_233 ;
V_219 . V_234 = V_218 ;
error = F_142 ( V_2 , & V_219 ,
V_153 | V_199 ) ;
F_6 ( V_2 , V_18 ) ;
if ( error )
return error ;
V_215 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_49 ( V_166 ) ;
}
V_4 = F_8 ( V_1 , V_235 ) ;
if ( ( error = F_11 ( V_4 , 0 , F_143 ( V_1 ) ,
0 , 0 , 0 ) ) ) {
F_10 ( V_4 , 0 ) ;
return error ;
}
F_4 ( V_2 , V_22 ) ;
F_14 ( V_4 , V_2 , V_22 ) ;
if ( ( V_153 & V_236 ) == 0 ) {
V_2 -> V_27 . V_28 &= ~ V_237 ;
if ( V_2 -> V_27 . V_28 & V_238 )
V_2 -> V_27 . V_28 &= ~ V_239 ;
F_72 ( V_4 , V_2 , V_98 | V_99 ) ;
}
if ( V_217 )
V_2 -> V_27 . V_83 |= V_240 ;
else if ( V_215 )
V_2 -> V_27 . V_83 &= ~ V_240 ;
F_37 ( V_4 , V_2 , V_49 ) ;
if ( V_153 & V_241 )
F_75 ( V_4 ) ;
return F_16 ( V_4 , 0 ) ;
}
