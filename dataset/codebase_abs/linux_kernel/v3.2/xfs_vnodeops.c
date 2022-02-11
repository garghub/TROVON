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
V_14 = F_6 ( V_3 -> V_18 , V_11 , F_7 ( V_12 ) ,
V_19 | V_20 | V_21 ) ;
if ( ! V_14 )
return F_8 ( V_22 ) ;
error = V_14 -> V_23 ;
if ( error ) {
F_9 ( V_14 , V_24 ) ;
F_10 ( V_14 ) ;
goto V_15;
}
if ( V_5 < V_12 )
V_12 = V_5 ;
V_5 -= V_12 ;
memcpy ( V_2 , V_14 -> V_25 , V_12 ) ;
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
return F_8 ( V_26 ) ;
F_14 ( V_1 , V_27 ) ;
V_5 = V_1 -> V_6 . V_7 ;
if ( ! V_5 )
goto V_15;
if ( V_5 < 0 || V_5 > V_28 ) {
F_15 ( V_3 , L_1 ,
V_24 , ( unsigned long long ) V_1 -> V_29 ,
( long long ) V_5 ) ;
ASSERT ( 0 ) ;
return F_8 ( V_30 ) ;
}
if ( V_1 -> V_31 . V_32 & V_33 ) {
memcpy ( V_2 , V_1 -> V_31 . V_34 . V_35 , V_5 ) ;
V_2 [ V_5 ] = '\0' ;
} else {
error = F_1 ( V_1 , V_2 ) ;
}
V_15:
F_16 ( V_1 , V_27 ) ;
return error ;
}
STATIC int
F_17 (
T_2 * V_3 ,
T_1 * V_1 ,
int V_36 )
{
T_7 * V_37 ;
int error ;
T_8 V_38 ;
T_8 V_39 ;
T_9 V_40 ;
int V_41 ;
T_3 V_42 ;
V_38 = F_3 ( V_3 , ( ( V_43 ) V_1 -> V_44 ) ) ;
V_39 = F_3 ( V_3 , ( V_43 ) F_18 ( V_3 ) ) ;
if ( V_39 <= V_38 )
return 0 ;
V_40 = V_39 - V_38 ;
V_41 = 1 ;
F_14 ( V_1 , V_27 ) ;
error = F_2 ( V_1 , V_38 , V_40 , & V_42 , & V_41 , 0 ) ;
F_16 ( V_1 , V_27 ) ;
if ( ! error && ( V_41 != 0 ) &&
( V_42 . V_16 != V_45 ||
V_1 -> V_46 ) ) {
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
V_37 = F_20 ( V_3 , V_47 ) ;
if ( V_36 & V_48 ) {
if ( ! F_21 ( V_1 , V_49 ) ) {
F_22 ( V_37 , 0 ) ;
return 0 ;
}
} else {
F_14 ( V_1 , V_49 ) ;
}
error = F_23 ( V_37 , 0 ,
F_24 ( V_3 ) ,
0 , V_50 ,
V_51 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
F_16 ( V_1 , V_49 ) ;
return error ;
}
F_14 ( V_1 , V_52 ) ;
F_25 ( V_37 , V_1 , 0 ) ;
error = F_26 ( & V_37 , V_1 , V_1 -> V_44 ) ;
if ( error ) {
F_22 ( V_37 ,
( V_53 |
V_54 ) ) ;
} else {
error = F_27 ( V_37 ,
V_53 ) ;
}
F_16 ( V_1 , V_49 | V_52 ) ;
}
return error ;
}
STATIC int
F_28 (
T_1 * V_1 ,
T_7 * * V_55 )
{
T_5 * V_14 ;
int V_56 ;
int V_57 ;
int error ;
T_10 V_58 ;
T_11 V_59 ;
int V_60 ;
T_2 * V_3 ;
T_3 V_10 [ V_9 ] ;
int V_8 ;
T_7 * V_61 ;
int V_62 ;
T_7 * V_37 ;
V_37 = * V_55 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_7 > F_29 ( V_1 ) ) ;
ASSERT ( V_1 -> V_6 . V_63 > 0 && V_1 -> V_6 . V_63 <= 2 ) ;
if ( ( error = F_23 ( V_37 , 0 , F_24 ( V_3 ) , 0 ,
V_50 , V_51 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
* V_55 = NULL ;
return error ;
}
F_14 ( V_1 , V_49 | V_52 ) ;
V_62 = ( int ) V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_7 = 0 ;
F_25 ( V_37 , V_1 , 0 ) ;
F_30 ( V_37 , V_1 , V_64 ) ;
V_57 = 0 ;
F_31 ( & V_59 , & V_58 ) ;
V_8 = F_32 ( V_10 ) ;
error = F_2 ( V_1 , 0 , F_3 ( V_3 , V_62 ) ,
V_10 , & V_8 , 0 ) ;
if ( error )
goto V_65;
for ( V_60 = 0 ; V_60 < V_8 ; V_60 ++ ) {
V_14 = F_33 ( V_37 , V_3 -> V_18 ,
F_4 ( V_3 , V_10 [ V_60 ] . V_16 ) ,
F_34 ( V_3 , V_10 [ V_60 ] . V_17 ) , 0 ) ;
if ( ! V_14 ) {
error = V_22 ;
goto V_66;
}
F_35 ( V_37 , V_14 ) ;
}
if ( ( error = F_36 ( V_37 , V_1 , 0 , V_62 , V_67 , V_8 ,
& V_58 , & V_59 , & V_57 ) ) )
goto V_66;
ASSERT ( V_57 ) ;
if ( ( error = F_37 ( & V_37 , & V_59 , & V_56 ) ) )
goto V_66;
ASSERT ( V_56 ) ;
F_25 ( V_37 , V_1 , 0 ) ;
F_30 ( V_37 , V_1 , V_64 ) ;
V_61 = F_38 ( V_37 ) ;
error = F_27 ( V_37 , 0 ) ;
V_37 = V_61 ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_65;
}
F_39 ( V_37 -> V_68 ) ;
if ( V_1 -> V_31 . V_69 )
F_40 ( V_1 , - V_1 -> V_31 . V_69 , V_70 ) ;
ASSERT ( V_1 -> V_31 . V_69 == 0 ) ;
if ( ( error = F_23 ( V_37 , 0 , F_24 ( V_3 ) , 0 ,
V_50 , V_51 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_65;
}
* V_55 = V_37 ;
return 0 ;
V_66:
F_41 ( & V_59 ) ;
V_65:
F_22 ( V_37 , V_53 | V_54 ) ;
F_16 ( V_1 , V_49 | V_52 ) ;
* V_55 = NULL ;
return error ;
}
STATIC int
F_42 (
T_1 * V_1 ,
T_7 * * V_55 )
{
int error ;
ASSERT ( V_1 -> V_6 . V_7 <= F_29 ( V_1 ) ) ;
error = F_23 ( * V_55 , 0 ,
F_24 ( V_1 -> V_4 ) ,
0 , V_50 ,
V_51 ) ;
if ( error ) {
F_22 ( * V_55 , 0 ) ;
* V_55 = NULL ;
return error ;
}
F_14 ( V_1 , V_52 | V_49 ) ;
if ( V_1 -> V_31 . V_69 > 0 ) {
F_40 ( V_1 ,
- ( V_1 -> V_31 . V_69 ) ,
V_70 ) ;
ASSERT ( V_1 -> V_31 . V_69 == 0 ) ;
}
return 0 ;
}
STATIC int
F_43 (
T_1 * V_1 ,
T_7 * * V_55 )
{
T_7 * V_37 ;
int error ;
T_2 * V_3 ;
ASSERT ( F_44 ( V_1 , V_49 ) ) ;
V_37 = * V_55 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_71 != 0 ) ;
error = F_27 ( V_37 , V_53 ) ;
F_16 ( V_1 , V_52 ) ;
if ( error )
goto V_72;
error = F_45 ( V_1 ) ;
if ( error )
goto V_72;
V_37 = F_20 ( V_3 , V_47 ) ;
error = F_23 ( V_37 , 0 ,
F_46 ( V_3 ) ,
0 , V_50 ,
V_73 ) ;
if ( error )
goto V_74;
F_14 ( V_1 , V_52 ) ;
F_25 ( V_37 , V_1 , 0 ) ;
F_47 ( V_1 , V_75 ) ;
ASSERT ( V_1 -> V_6 . V_76 == 0 ) ;
* V_55 = V_37 ;
return 0 ;
V_74:
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
V_72:
* V_55 = NULL ;
F_16 ( V_1 , V_49 ) ;
return error ;
}
int
F_48 (
T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
int error ;
if ( ! F_49 ( V_1 -> V_6 . V_77 ) || ( V_1 -> V_6 . V_77 == 0 ) )
return 0 ;
if ( V_3 -> V_78 & V_79 )
return 0 ;
if ( ! F_13 ( V_3 ) ) {
int V_80 ;
if ( ( V_1 -> V_6 . V_81 == 0 ) && F_50 ( V_1 ) )
F_51 ( V_1 ) ;
V_80 = F_52 ( V_1 , V_82 ) ;
if ( V_80 ) {
F_53 ( V_1 , V_83 ) ;
if ( F_54 ( F_55 ( V_1 ) ) && V_1 -> V_46 > 0 )
F_56 ( V_1 , 0 , - 1 , V_84 , V_85 ) ;
}
}
if ( V_1 -> V_6 . V_81 == 0 )
return 0 ;
if ( ( F_49 ( V_1 -> V_6 . V_77 ) &&
( ( V_1 -> V_44 > 0 ) || ( F_57 ( F_55 ( V_1 ) ) > 0 ||
V_1 -> V_46 > 0 ) ) &&
( V_1 -> V_31 . V_32 & V_86 ) ) &&
( ! ( V_1 -> V_6 . V_87 & ( V_88 | V_89 ) ) ) ) {
if ( F_58 ( V_1 , V_83 ) )
return 0 ;
error = F_17 ( V_3 , V_1 ,
V_48 ) ;
if ( error )
return error ;
if ( V_1 -> V_46 )
F_59 ( V_1 , V_83 ) ;
}
return 0 ;
}
int
F_60 (
T_1 * V_1 )
{
T_11 V_59 ;
T_10 V_58 ;
int V_56 ;
T_7 * V_37 ;
T_2 * V_3 ;
int error ;
int V_90 ;
if ( V_1 -> V_6 . V_77 == 0 || F_61 ( F_55 ( V_1 ) ) ) {
ASSERT ( V_1 -> V_31 . V_91 == 0 ) ;
ASSERT ( V_1 -> V_31 . V_92 == 0 ) ;
return V_93 ;
}
V_90 = ( ( V_1 -> V_6 . V_81 == 0 ) &&
( ( V_1 -> V_6 . V_7 != 0 ) || ( V_1 -> V_44 != 0 ) ||
( V_1 -> V_6 . V_63 > 0 ) || ( V_1 -> V_46 > 0 ) ) &&
F_49 ( V_1 -> V_6 . V_77 ) ) ;
V_3 = V_1 -> V_4 ;
error = 0 ;
if ( V_3 -> V_78 & V_79 )
goto V_15;
if ( V_1 -> V_6 . V_81 != 0 ) {
if ( ( F_49 ( V_1 -> V_6 . V_77 ) &&
( ( V_1 -> V_44 > 0 ) || ( F_57 ( F_55 ( V_1 ) ) > 0 ||
V_1 -> V_46 > 0 ) ) &&
( V_1 -> V_31 . V_32 & V_86 ) &&
( ! ( V_1 -> V_6 . V_87 &
( V_88 | V_89 ) ) ||
( V_1 -> V_46 != 0 ) ) ) ) {
error = F_17 ( V_3 , V_1 , 0 ) ;
if ( error )
return V_93 ;
}
goto V_15;
}
ASSERT ( V_1 -> V_6 . V_81 == 0 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return V_93 ;
V_37 = F_20 ( V_3 , V_47 ) ;
if ( V_90 ) {
F_14 ( V_1 , V_49 ) ;
error = F_23 ( V_37 , 0 ,
F_24 ( V_3 ) ,
0 , V_50 ,
V_51 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
F_16 ( V_1 , V_49 ) ;
return V_93 ;
}
F_14 ( V_1 , V_52 ) ;
F_25 ( V_37 , V_1 , 0 ) ;
error = F_26 ( & V_37 , V_1 , 0 ) ;
if ( error ) {
F_22 ( V_37 ,
V_53 | V_54 ) ;
F_16 ( V_1 , V_49 | V_52 ) ;
return V_93 ;
}
} else if ( F_62 ( V_1 -> V_6 . V_77 ) ) {
error = ( V_1 -> V_6 . V_7 > F_29 ( V_1 ) ) ?
F_28 ( V_1 , & V_37 ) :
F_42 ( V_1 , & V_37 ) ;
if ( error ) {
ASSERT ( V_37 == NULL ) ;
return V_93 ;
}
F_25 ( V_37 , V_1 , 0 ) ;
} else {
error = F_23 ( V_37 , 0 ,
F_46 ( V_3 ) ,
0 , V_50 ,
V_73 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
return V_93 ;
}
F_14 ( V_1 , V_52 | V_49 ) ;
F_25 ( V_37 , V_1 , 0 ) ;
}
if ( V_1 -> V_6 . V_76 > 0 ) {
error = F_43 ( V_1 , & V_37 ) ;
if ( error )
return V_93 ;
} else if ( V_1 -> V_94 ) {
F_47 ( V_1 , V_75 ) ;
}
F_31 ( & V_59 , & V_58 ) ;
error = F_63 ( V_37 , V_1 , & V_59 ) ;
if ( error ) {
if ( ! F_13 ( V_3 ) ) {
F_64 ( V_3 , L_2 ,
V_24 , error ) ;
F_65 ( V_3 , V_95 ) ;
}
F_22 ( V_37 , V_53 | V_54 ) ;
} else {
F_66 ( V_37 , V_1 , V_96 , - 1 ) ;
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error )
F_64 ( V_3 , L_3 ,
V_24 , error ) ;
error = F_27 ( V_37 , V_53 ) ;
if ( error )
F_64 ( V_3 , L_4 ,
V_24 , error ) ;
}
F_67 ( V_1 ) ;
F_16 ( V_1 , V_49 | V_52 ) ;
V_15:
return V_93 ;
}
int
F_68 (
T_1 * V_97 ,
struct V_98 * V_99 ,
T_1 * * V_100 ,
struct V_98 * V_101 )
{
T_12 V_102 ;
int error ;
T_13 V_103 ;
F_69 ( V_97 , V_99 ) ;
if ( F_13 ( V_97 -> V_4 ) )
return F_8 ( V_26 ) ;
V_103 = F_70 ( V_97 ) ;
error = F_71 ( NULL , V_97 , V_99 , & V_102 , V_101 ) ;
F_72 ( V_97 , V_103 ) ;
if ( error )
goto V_15;
error = F_73 ( V_97 -> V_4 , NULL , V_102 , 0 , 0 , V_100 ) ;
if ( error )
goto V_104;
return 0 ;
V_104:
if ( V_101 )
F_74 ( V_101 -> V_99 ) ;
V_15:
* V_100 = NULL ;
return error ;
}
int
F_75 (
T_1 * V_97 ,
struct V_98 * V_99 ,
T_14 V_105 ,
T_15 V_106 ,
T_1 * * V_100 )
{
int V_107 = F_76 ( V_105 ) ;
struct V_108 * V_3 = V_97 -> V_4 ;
struct V_109 * V_1 = NULL ;
struct V_110 * V_37 = NULL ;
int error ;
T_11 V_59 ;
T_10 V_58 ;
T_16 V_111 = V_112 ;
T_13 V_113 ;
int V_56 ;
T_17 V_114 ;
struct V_115 * V_116 = NULL ;
struct V_115 * V_117 = NULL ;
T_13 V_118 ;
T_13 V_119 ;
T_13 V_120 ;
F_77 ( V_97 , V_99 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
if ( V_97 -> V_6 . V_87 & V_121 )
V_114 = F_78 ( V_97 ) ;
else
V_114 = V_122 ;
error = F_79 ( V_97 , F_80 () , F_81 () , V_114 ,
V_123 | V_124 , & V_116 , & V_117 ) ;
if ( error )
return error ;
if ( V_107 ) {
V_106 = 0 ;
V_118 = F_82 ( V_3 , V_99 -> V_125 ) ;
V_119 = F_83 ( V_3 ) ;
V_120 = V_126 ;
V_37 = F_20 ( V_3 , V_127 ) ;
} else {
V_118 = F_84 ( V_3 , V_99 -> V_125 ) ;
V_119 = F_85 ( V_3 ) ;
V_120 = V_128 ;
V_37 = F_20 ( V_3 , V_129 ) ;
}
V_113 = V_53 ;
error = F_23 ( V_37 , V_118 , V_119 , 0 ,
V_50 , V_120 ) ;
if ( error == V_130 ) {
F_86 ( V_97 ) ;
error = F_23 ( V_37 , V_118 , V_119 , 0 ,
V_50 , V_120 ) ;
}
if ( error == V_130 ) {
V_118 = 0 ;
error = F_23 ( V_37 , 0 , V_119 , 0 ,
V_50 , V_120 ) ;
}
if ( error ) {
V_113 = 0 ;
goto V_131;
}
F_14 ( V_97 , V_52 | V_132 ) ;
V_111 = V_133 ;
if ( V_107 && V_97 -> V_6 . V_81 >= V_134 ) {
error = F_8 ( V_135 ) ;
goto V_131;
}
F_31 ( & V_59 , & V_58 ) ;
error = F_87 ( V_37 , V_3 , V_116 , V_117 , V_118 , 1 , 0 ) ;
if ( error )
goto V_131;
error = F_88 ( V_37 , V_97 , V_99 , V_118 ) ;
if ( error )
goto V_131;
error = F_89 ( & V_37 , V_97 , V_105 , V_107 ? 2 : 1 , V_106 ,
V_114 , V_118 > 0 , & V_1 , & V_56 ) ;
if ( error ) {
if ( error == V_130 )
goto V_131;
goto V_136;
}
F_25 ( V_37 , V_97 , V_52 ) ;
V_111 = V_112 ;
error = F_90 ( V_37 , V_97 , V_99 , V_1 -> V_29 ,
& V_58 , & V_59 , V_118 ?
V_118 - F_91 ( V_3 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_130 ) ;
goto V_136;
}
F_92 ( V_37 , V_97 , V_137 | V_138 ) ;
F_30 ( V_37 , V_97 , V_64 ) ;
if ( V_107 ) {
error = F_93 ( V_37 , V_1 , V_97 ) ;
if ( error )
goto V_139;
error = F_94 ( V_37 , V_97 ) ;
if ( error )
goto V_139;
}
if ( V_3 -> V_78 & ( V_140 | V_141 ) )
F_95 ( V_37 ) ;
F_96 ( V_37 , V_1 , V_116 , V_117 ) ;
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error )
goto V_139;
error = F_27 ( V_37 , V_53 ) ;
if ( error )
goto V_142;
F_97 ( V_116 ) ;
F_97 ( V_117 ) ;
* V_100 = V_1 ;
return 0 ;
V_139:
F_41 ( & V_59 ) ;
V_136:
V_113 |= V_54 ;
V_131:
F_22 ( V_37 , V_113 ) ;
V_142:
if ( V_1 )
F_98 ( V_1 ) ;
F_97 ( V_116 ) ;
F_97 ( V_117 ) ;
if ( V_111 )
F_16 ( V_97 , V_52 ) ;
return error ;
}
static inline int
F_99 ( int V_103 , int V_143 )
{
if ( V_103 & ( V_144 | V_49 ) )
V_103 |= ( V_143 + V_145 ) << V_146 ;
if ( V_103 & ( V_27 | V_52 ) )
V_103 |= ( V_143 + V_145 ) << V_147 ;
return V_103 ;
}
void
F_100 (
T_1 * * V_148 ,
int V_149 ,
T_13 V_103 )
{
int V_150 = 0 , V_60 , V_151 , V_152 ;
T_18 * V_153 ;
ASSERT ( V_148 && ( V_149 >= 2 ) ) ;
V_152 = 0 ;
V_60 = 0 ;
V_154:
for (; V_60 < V_149 ; V_60 ++ ) {
ASSERT ( V_148 [ V_60 ] ) ;
if ( V_60 && ( V_148 [ V_60 ] == V_148 [ V_60 - 1 ] ) )
continue;
if ( ! V_152 ) {
for ( V_151 = ( V_60 - 1 ) ; V_151 >= 0 && ! V_152 ; V_151 -- ) {
V_153 = ( T_18 * ) V_148 [ V_151 ] -> V_155 ;
if ( V_153 && ( V_153 -> V_156 & V_157 ) ) {
V_152 ++ ;
}
}
}
if ( V_152 ) {
ASSERT ( V_60 != 0 ) ;
if ( ! F_21 ( V_148 [ V_60 ] , F_99 ( V_103 , V_60 ) ) ) {
V_150 ++ ;
for( V_151 = V_60 - 1 ; V_151 >= 0 ; V_151 -- ) {
if ( ( V_151 != ( V_60 - 1 ) ) && V_148 [ V_151 ] ==
V_148 [ V_151 + 1 ] )
continue;
F_16 ( V_148 [ V_151 ] , V_103 ) ;
}
if ( ( V_150 % 5 ) == 0 ) {
F_101 ( 1 ) ;
#ifdef F_102
V_158 ++ ;
#endif
}
V_60 = 0 ;
V_152 = 0 ;
goto V_154;
}
} else {
F_14 ( V_148 [ V_60 ] , F_99 ( V_103 , V_60 ) ) ;
}
}
#ifdef F_102
if ( V_150 ) {
if ( V_150 < 5 ) V_159 ++ ;
else if ( V_150 < 100 ) V_160 ++ ;
else V_161 ++ ;
} else {
V_162 ++ ;
}
#endif
}
void
F_103 (
T_1 * V_163 ,
T_1 * V_164 ,
T_13 V_103 )
{
T_1 * V_165 ;
int V_150 = 0 ;
T_18 * V_153 ;
if ( V_103 & ( V_144 | V_49 ) )
ASSERT ( ( V_103 & ( V_27 | V_52 ) ) == 0 ) ;
ASSERT ( V_163 -> V_29 != V_164 -> V_29 ) ;
if ( V_163 -> V_29 > V_164 -> V_29 ) {
V_165 = V_163 ;
V_163 = V_164 ;
V_164 = V_165 ;
}
V_154:
F_14 ( V_163 , F_99 ( V_103 , 0 ) ) ;
V_153 = ( T_18 * ) V_163 -> V_155 ;
if ( V_153 && ( V_153 -> V_156 & V_157 ) ) {
if ( ! F_21 ( V_164 , F_99 ( V_103 , 1 ) ) ) {
F_16 ( V_163 , V_103 ) ;
if ( ( ++ V_150 % 5 ) == 0 )
F_101 ( 1 ) ;
goto V_154;
}
} else {
F_14 ( V_164 , F_99 ( V_103 , 1 ) ) ;
}
}
int
F_104 (
T_1 * V_97 ,
struct V_98 * V_99 ,
T_1 * V_1 )
{
T_2 * V_3 = V_97 -> V_4 ;
T_7 * V_37 = NULL ;
int V_107 = F_76 ( V_1 -> V_6 . V_77 ) ;
int error = 0 ;
T_11 V_59 ;
T_10 V_58 ;
int V_113 ;
int V_56 ;
int V_166 ;
T_13 V_118 ;
T_13 V_120 ;
F_105 ( V_97 , V_99 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
error = F_19 ( V_97 , 0 ) ;
if ( error )
goto V_167;
error = F_19 ( V_1 , 0 ) ;
if ( error )
goto V_167;
if ( V_107 ) {
V_37 = F_20 ( V_3 , V_168 ) ;
V_120 = V_169 ;
} else {
V_37 = F_20 ( V_3 , V_170 ) ;
V_120 = V_171 ;
}
V_113 = V_53 ;
V_118 = F_106 ( V_3 ) ;
error = F_23 ( V_37 , V_118 , F_107 ( V_3 ) , 0 ,
V_50 , V_120 ) ;
if ( error == V_130 ) {
V_118 = 0 ;
error = F_23 ( V_37 , 0 , F_107 ( V_3 ) , 0 ,
V_50 , V_120 ) ;
}
if ( error ) {
ASSERT ( error != V_130 ) ;
V_113 = 0 ;
goto V_131;
}
F_103 ( V_97 , V_1 , V_52 ) ;
F_25 ( V_37 , V_97 , V_52 ) ;
F_25 ( V_37 , V_1 , V_52 ) ;
if ( V_107 ) {
ASSERT ( V_1 -> V_6 . V_81 >= 2 ) ;
if ( V_1 -> V_6 . V_81 != 2 ) {
error = F_8 ( V_172 ) ;
goto V_131;
}
if ( ! F_108 ( V_1 ) ) {
error = F_8 ( V_172 ) ;
goto V_131;
}
}
F_31 ( & V_59 , & V_58 ) ;
error = F_109 ( V_37 , V_97 , V_99 , V_1 -> V_29 ,
& V_58 , & V_59 , V_118 ) ;
if ( error ) {
ASSERT ( error != V_173 ) ;
goto V_139;
}
F_92 ( V_37 , V_97 , V_137 | V_138 ) ;
if ( V_107 ) {
error = F_110 ( V_37 , V_97 ) ;
if ( error )
goto V_139;
error = F_110 ( V_37 , V_1 ) ;
if ( error )
goto V_139;
} else {
F_30 ( V_37 , V_97 , V_64 ) ;
}
error = F_110 ( V_37 , V_1 ) ;
if ( error )
goto V_139;
V_166 = ( V_1 -> V_6 . V_81 == 0 ) ;
if ( V_3 -> V_78 & ( V_140 | V_141 ) )
F_95 ( V_37 ) ;
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error )
goto V_139;
error = F_27 ( V_37 , V_53 ) ;
if ( error )
goto V_167;
if ( ! V_107 && V_166 && F_50 ( V_1 ) )
F_51 ( V_1 ) ;
return 0 ;
V_139:
F_41 ( & V_59 ) ;
V_113 |= V_54 ;
V_131:
F_22 ( V_37 , V_113 ) ;
V_167:
return error ;
}
int
F_111 (
T_1 * V_174 ,
T_1 * V_175 ,
struct V_98 * V_176 )
{
T_2 * V_3 = V_174 -> V_4 ;
T_7 * V_37 ;
int error ;
T_11 V_59 ;
T_10 V_58 ;
int V_113 ;
int V_56 ;
int V_118 ;
F_112 ( V_174 , V_176 ) ;
ASSERT ( ! F_76 ( V_175 -> V_6 . V_77 ) ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
error = F_19 ( V_175 , 0 ) ;
if ( error )
goto V_167;
error = F_19 ( V_174 , 0 ) ;
if ( error )
goto V_167;
V_37 = F_20 ( V_3 , V_177 ) ;
V_113 = V_53 ;
V_118 = F_113 ( V_3 , V_176 -> V_125 ) ;
error = F_23 ( V_37 , V_118 , F_114 ( V_3 ) , 0 ,
V_50 , V_178 ) ;
if ( error == V_130 ) {
V_118 = 0 ;
error = F_23 ( V_37 , 0 , F_114 ( V_3 ) , 0 ,
V_50 , V_178 ) ;
}
if ( error ) {
V_113 = 0 ;
goto V_179;
}
F_103 ( V_175 , V_174 , V_52 ) ;
F_25 ( V_37 , V_175 , V_52 ) ;
F_25 ( V_37 , V_174 , V_52 ) ;
if ( V_175 -> V_6 . V_81 >= V_134 ) {
error = F_8 ( V_135 ) ;
goto V_179;
}
if ( F_115 ( ( V_174 -> V_6 . V_87 & V_121 ) &&
( F_78 ( V_174 ) != F_78 ( V_175 ) ) ) ) {
error = F_8 ( V_180 ) ;
goto V_179;
}
error = F_88 ( V_37 , V_174 , V_176 , V_118 ) ;
if ( error )
goto V_179;
F_31 ( & V_59 , & V_58 ) ;
error = F_90 ( V_37 , V_174 , V_176 , V_175 -> V_29 ,
& V_58 , & V_59 , V_118 ) ;
if ( error )
goto V_181;
F_92 ( V_37 , V_174 , V_137 | V_138 ) ;
F_30 ( V_37 , V_174 , V_64 ) ;
error = F_94 ( V_37 , V_175 ) ;
if ( error )
goto V_181;
if ( V_3 -> V_78 & ( V_140 | V_141 ) ) {
F_95 ( V_37 ) ;
}
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
F_41 ( & V_59 ) ;
goto V_181;
}
return F_27 ( V_37 , V_53 ) ;
V_181:
V_113 |= V_54 ;
V_179:
F_22 ( V_37 , V_113 ) ;
V_167:
return error ;
}
int
F_116 (
T_1 * V_97 ,
struct V_98 * V_182 ,
const char * V_183 ,
T_14 V_105 ,
T_1 * * V_100 )
{
T_2 * V_3 = V_97 -> V_4 ;
T_7 * V_37 ;
T_1 * V_1 ;
int error ;
int V_5 ;
T_11 V_59 ;
T_10 V_58 ;
T_16 V_111 = V_112 ;
T_13 V_113 ;
int V_56 ;
T_8 V_184 ;
T_9 V_185 ;
int V_8 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
const char * V_186 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
T_17 V_114 ;
struct V_115 * V_116 , * V_117 ;
T_13 V_118 ;
* V_100 = NULL ;
error = 0 ;
V_1 = NULL ;
V_37 = NULL ;
F_117 ( V_97 , V_182 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
V_5 = strlen ( V_183 ) ;
if ( V_5 >= V_28 )
return F_8 ( V_187 ) ;
V_116 = V_117 = NULL ;
if ( V_97 -> V_6 . V_87 & V_121 )
V_114 = F_78 ( V_97 ) ;
else
V_114 = V_122 ;
error = F_79 ( V_97 , F_80 () , F_81 () , V_114 ,
V_123 | V_124 , & V_116 , & V_117 ) ;
if ( error )
goto V_167;
V_37 = F_20 ( V_3 , V_188 ) ;
V_113 = V_53 ;
if ( V_5 <= F_118 ( V_3 ) )
V_185 = 0 ;
else
V_185 = F_3 ( V_3 , V_5 ) ;
V_118 = F_119 ( V_3 , V_182 -> V_125 , V_185 ) ;
error = F_23 ( V_37 , V_118 , F_120 ( V_3 ) , 0 ,
V_50 , V_189 ) ;
if ( error == V_130 && V_185 == 0 ) {
V_118 = 0 ;
error = F_23 ( V_37 , 0 , F_120 ( V_3 ) , 0 ,
V_50 , V_189 ) ;
}
if ( error ) {
V_113 = 0 ;
goto V_179;
}
F_14 ( V_97 , V_52 | V_132 ) ;
V_111 = V_133 ;
if ( V_97 -> V_6 . V_87 & V_190 ) {
error = F_8 ( V_191 ) ;
goto V_179;
}
error = F_87 ( V_37 , V_3 , V_116 , V_117 , V_118 , 1 , 0 ) ;
if ( error )
goto V_179;
error = F_88 ( V_37 , V_97 , V_182 , V_118 ) ;
if ( error )
goto V_179;
F_31 ( & V_59 , & V_58 ) ;
error = F_89 ( & V_37 , V_97 , V_192 | ( V_105 & ~ V_193 ) , 1 , 0 ,
V_114 , V_118 > 0 , & V_1 , NULL ) ;
if ( error ) {
if ( error == V_130 )
goto V_179;
goto V_66;
}
F_25 ( V_37 , V_97 , V_52 ) ;
V_111 = V_112 ;
F_96 ( V_37 , V_1 , V_116 , V_117 ) ;
if ( V_118 )
V_118 -= F_91 ( V_3 ) ;
if ( V_5 <= F_29 ( V_1 ) ) {
F_40 ( V_1 , V_5 , V_70 ) ;
memcpy ( V_1 -> V_31 . V_34 . V_35 , V_183 , V_5 ) ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_31 . V_32 &= ~ ( V_86 | V_194 ) ;
V_1 -> V_31 . V_32 |= V_33 ;
V_1 -> V_6 . V_195 = V_196 ;
F_30 ( V_37 , V_1 , V_197 | V_64 ) ;
} else {
V_184 = 0 ;
V_8 = V_9 ;
error = F_121 ( V_37 , V_1 , V_184 , V_185 ,
V_67 , & V_58 , V_118 ,
V_10 , & V_8 , & V_59 ) ;
if ( error )
goto V_198;
if ( V_118 )
V_118 -= V_185 ;
V_1 -> V_6 . V_7 = V_5 ;
F_30 ( V_37 , V_1 , V_64 ) ;
V_186 = V_183 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_33 ( V_37 , V_3 -> V_18 , V_11 ,
F_7 ( V_12 ) , 0 ) ;
if ( ! V_14 ) {
error = V_22 ;
goto V_198;
}
if ( V_5 < V_12 ) {
V_12 = V_5 ;
}
V_5 -= V_12 ;
memcpy ( V_14 -> V_25 , V_186 , V_12 ) ;
V_186 += V_12 ;
F_122 ( V_37 , V_14 , 0 , V_12 - 1 ) ;
}
}
error = F_90 ( V_37 , V_97 , V_182 , V_1 -> V_29 ,
& V_58 , & V_59 , V_118 ) ;
if ( error )
goto V_198;
F_92 ( V_37 , V_97 , V_137 | V_138 ) ;
F_30 ( V_37 , V_97 , V_64 ) ;
if ( V_3 -> V_78 & ( V_140 | V_141 ) ) {
F_95 ( V_37 ) ;
}
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
goto V_198;
}
error = F_27 ( V_37 , V_53 ) ;
F_97 ( V_116 ) ;
F_97 ( V_117 ) ;
* V_100 = V_1 ;
return 0 ;
V_198:
F_98 ( V_1 ) ;
V_66:
F_41 ( & V_59 ) ;
V_113 |= V_54 ;
V_179:
F_22 ( V_37 , V_113 ) ;
F_97 ( V_116 ) ;
F_97 ( V_117 ) ;
if ( V_111 )
F_16 ( V_97 , V_52 ) ;
V_167:
return error ;
}
int
F_123 (
T_1 * V_1 ,
T_19 V_199 ,
T_20 V_200 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_7 * V_37 ;
int error ;
if ( ! F_124 ( V_201 ) )
return F_8 ( V_191 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
V_37 = F_20 ( V_3 , V_202 ) ;
error = F_23 ( V_37 , 0 , F_125 ( V_3 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_22 ( V_37 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_52 ) ;
F_25 ( V_37 , V_1 , V_52 ) ;
V_1 -> V_6 . V_203 = V_199 ;
V_1 -> V_6 . V_204 = V_200 ;
F_30 ( V_37 , V_1 , V_64 ) ;
error = F_27 ( V_37 , 0 ) ;
return error ;
}
STATIC int
F_126 (
T_1 * V_1 ,
T_21 V_205 ,
T_21 V_125 ,
int V_206 ,
int V_207 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_21 V_208 ;
T_9 V_209 ;
T_9 V_210 ;
T_22 V_211 , V_165 ;
T_8 V_212 ;
T_10 V_213 ;
int V_41 ;
int V_214 ;
int V_215 ;
T_7 * V_37 ;
T_3 V_216 [ 1 ] , * V_217 ;
T_11 V_59 ;
T_13 V_218 , V_118 , V_219 ;
int V_56 ;
int error ;
F_127 ( V_1 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
if ( V_125 <= 0 )
return F_8 ( V_220 ) ;
V_215 = F_128 ( V_1 ) ;
V_211 = F_129 ( V_1 ) ;
V_208 = V_125 ;
V_217 = & V_216 [ 0 ] ;
V_41 = 1 ;
V_212 = F_130 ( V_3 , V_205 ) ;
V_210 = F_3 ( V_3 , V_208 ) ;
while ( V_210 && ! error ) {
T_8 V_221 , V_222 ;
if ( F_115 ( V_211 ) ) {
V_221 = V_212 ;
F_131 ( V_221 , V_211 ) ;
V_221 *= V_211 ;
V_222 = V_212 + V_210 ;
if ( ( V_165 = F_132 ( V_212 , V_211 ) ) )
V_222 += V_165 ;
if ( ( V_165 = F_132 ( V_222 , V_211 ) ) )
V_222 += V_211 - V_165 ;
} else {
V_221 = 0 ;
V_222 = V_210 ;
}
V_118 = F_133 ( T_8 , ( V_222 - V_221 ) , ( V_223 * V_41 ) ) ;
if ( F_115 ( V_215 ) ) {
V_219 = V_218 = V_118 ;
V_219 /= V_3 -> V_224 . V_225 ;
V_118 = F_134 ( V_3 , 0 ) ;
V_214 = V_226 ;
} else {
V_219 = 0 ;
V_118 = V_218 = F_134 ( V_3 , V_118 ) ;
V_214 = V_227 ;
}
V_37 = F_20 ( V_3 , V_228 ) ;
error = F_23 ( V_37 , V_118 ,
F_135 ( V_3 ) , V_219 ,
V_50 ,
V_229 ) ;
if ( error ) {
ASSERT ( error == V_130 || F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
break;
}
F_14 ( V_1 , V_52 ) ;
error = F_136 ( V_37 , V_1 , V_218 ,
0 , V_214 ) ;
if ( error )
goto V_66;
F_25 ( V_37 , V_1 , 0 ) ;
F_31 ( & V_59 , & V_213 ) ;
error = F_121 ( V_37 , V_1 , V_212 ,
V_210 , V_206 , & V_213 ,
0 , V_217 , & V_41 , & V_59 ) ;
if ( error ) {
goto V_65;
}
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
goto V_65;
}
error = F_27 ( V_37 , V_53 ) ;
F_16 ( V_1 , V_52 ) ;
if ( error ) {
break;
}
V_209 = V_217 -> V_17 ;
if ( V_41 == 0 ) {
error = F_8 ( V_130 ) ;
break;
}
V_212 += V_209 ;
V_210 -= V_209 ;
}
return error ;
V_65:
F_41 ( & V_59 ) ;
F_137 ( V_37 , V_1 , V_218 , 0 , V_214 ) ;
V_66:
F_22 ( V_37 , V_53 | V_54 ) ;
F_16 ( V_1 , V_52 ) ;
return error ;
}
STATIC int
F_138 (
T_1 * V_1 ,
T_21 V_230 ,
T_21 V_231 )
{
T_3 V_42 ;
T_8 V_232 ;
T_21 V_233 ;
T_21 V_205 ;
T_5 * V_14 ;
T_2 * V_3 = V_1 -> V_4 ;
int V_234 ;
int error = 0 ;
if ( V_230 >= V_1 -> V_44 )
return 0 ;
if ( V_231 > V_1 -> V_44 )
V_231 = V_1 -> V_44 ;
V_14 = F_139 ( F_128 ( V_1 ) ?
V_3 -> V_235 : V_3 -> V_18 ,
V_3 -> V_224 . V_236 , V_21 ) ;
if ( ! V_14 )
return F_8 ( V_22 ) ;
F_140 ( V_14 ) ;
for ( V_205 = V_230 ; V_205 <= V_231 ; V_205 = V_233 + 1 ) {
V_232 = F_130 ( V_3 , V_205 ) ;
V_234 = 1 ;
error = F_2 ( V_1 , V_232 , 1 , & V_42 , & V_234 , 0 ) ;
if ( error || V_234 < 1 )
break;
ASSERT ( V_42 . V_17 >= 1 ) ;
ASSERT ( V_42 . V_237 == V_232 ) ;
V_233 = F_5 ( V_3 , V_42 . V_237 + 1 ) - 1 ;
if ( V_233 > V_231 )
V_233 = V_231 ;
if ( V_42 . V_16 == V_45 )
continue;
ASSERT ( V_42 . V_16 != V_238 ) ;
if ( V_42 . V_239 == V_240 )
continue;
F_141 ( V_14 ) ;
F_142 ( V_14 ) ;
F_143 ( V_14 ) ;
F_144 ( V_14 , F_145 ( V_1 , V_42 . V_16 ) ) ;
F_146 ( V_3 , V_14 ) ;
error = F_147 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_5 ) ;
break;
}
memset ( V_14 -> V_25 +
( V_205 - F_5 ( V_3 , V_42 . V_237 ) ) ,
0 , V_233 - V_205 + 1 ) ;
F_141 ( V_14 ) ;
F_148 ( V_14 ) ;
F_149 ( V_14 ) ;
F_146 ( V_3 , V_14 ) ;
error = F_147 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_6 ) ;
break;
}
}
F_150 ( V_14 ) ;
return error ;
}
STATIC int
F_151 (
T_1 * V_1 ,
T_21 V_205 ,
T_21 V_125 ,
int V_207 )
{
int V_56 ;
int V_57 ;
T_8 V_241 ;
int error ;
T_10 V_213 ;
T_11 V_59 ;
T_3 V_42 ;
T_21 V_242 ;
T_22 V_243 = 0 ;
T_2 * V_3 ;
int V_234 ;
T_13 V_118 ;
T_13 V_244 ;
int V_215 ;
T_8 V_212 ;
T_7 * V_37 ;
int V_245 = 1 ;
V_3 = V_1 -> V_4 ;
F_152 ( V_1 ) ;
error = F_19 ( V_1 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_125 <= 0 )
return error ;
V_215 = F_128 ( V_1 ) ;
V_212 = F_3 ( V_3 , V_205 ) ;
V_241 = F_130 ( V_3 , V_205 + V_125 ) ;
if ( V_207 & V_246 )
V_245 = 0 ;
if ( V_245 ) {
F_14 ( V_1 , V_49 ) ;
F_153 ( F_55 ( V_1 ) ) ;
}
V_244 = F_154 ( T_13 , 1 << V_3 -> V_224 . V_247 , V_248 ) ;
V_242 = V_205 & ~ ( V_244 - 1 ) ;
if ( F_57 ( F_55 ( V_1 ) ) != 0 ) {
error = F_155 ( V_1 , V_242 , - 1 , V_249 ) ;
if ( error )
goto V_250;
}
if ( V_215 && ! F_156 ( & V_3 -> V_224 ) ) {
V_234 = 1 ;
error = F_2 ( V_1 , V_212 , 1 ,
& V_42 , & V_234 , 0 ) ;
if ( error )
goto V_250;
ASSERT ( V_234 == 0 || V_234 == 1 ) ;
if ( V_234 && V_42 . V_16 != V_45 ) {
T_4 V_251 ;
ASSERT ( V_42 . V_16 != V_238 ) ;
V_251 = V_42 . V_16 ;
V_243 = F_131 ( V_251 , V_3 -> V_224 . V_225 ) ;
if ( V_243 )
V_212 += V_3 -> V_224 . V_225 - V_243 ;
}
V_234 = 1 ;
error = F_2 ( V_1 , V_241 - 1 , 1 ,
& V_42 , & V_234 , 0 ) ;
if ( error )
goto V_250;
ASSERT ( V_234 == 0 || V_234 == 1 ) ;
if ( V_234 && V_42 . V_16 != V_45 ) {
ASSERT ( V_42 . V_16 != V_238 ) ;
V_243 ++ ;
if ( V_243 && ( V_243 != V_3 -> V_224 . V_225 ) )
V_241 -= V_243 ;
}
}
if ( ( V_57 = ( V_241 <= V_212 ) ) )
error = F_138 ( V_1 , V_205 , V_205 + V_125 - 1 ) ;
else {
if ( V_205 < F_5 ( V_3 , V_212 ) )
error = F_138 ( V_1 , V_205 ,
F_5 ( V_3 , V_212 ) - 1 ) ;
if ( ! error &&
F_5 ( V_3 , V_241 ) < V_205 + V_125 )
error = F_138 ( V_1 ,
F_5 ( V_3 , V_241 ) ,
V_205 + V_125 - 1 ) ;
}
V_118 = F_134 ( V_3 , 0 ) ;
while ( ! error && ! V_57 ) {
V_37 = F_20 ( V_3 , V_228 ) ;
V_37 -> V_252 |= V_253 ;
error = F_23 ( V_37 ,
V_118 ,
F_135 ( V_3 ) ,
0 ,
V_50 ,
V_229 ) ;
if ( error ) {
ASSERT ( error == V_130 || F_13 ( V_3 ) ) ;
F_22 ( V_37 , 0 ) ;
break;
}
F_14 ( V_1 , V_52 ) ;
error = F_87 ( V_37 , V_3 ,
V_1 -> V_254 , V_1 -> V_255 ,
V_118 , 0 , V_227 ) ;
if ( error )
goto V_66;
F_25 ( V_37 , V_1 , 0 ) ;
F_31 ( & V_59 , & V_213 ) ;
error = F_36 ( V_37 , V_1 , V_212 ,
V_241 - V_212 ,
0 , 2 , & V_213 , & V_59 , & V_57 ) ;
if ( error ) {
goto V_65;
}
error = F_37 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
goto V_65;
}
error = F_27 ( V_37 , V_53 ) ;
F_16 ( V_1 , V_52 ) ;
}
V_250:
if ( V_245 )
F_16 ( V_1 , V_49 ) ;
return error ;
V_65:
F_41 ( & V_59 ) ;
V_66:
F_22 ( V_37 , V_53 | V_54 ) ;
F_16 ( V_1 , V_245 ? ( V_52 | V_49 ) :
V_52 ) ;
return error ;
}
int
F_157 (
T_1 * V_1 ,
int V_256 ,
T_23 * V_257 ,
T_21 V_205 ,
int V_207 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_258 ;
int error ;
T_6 V_259 ;
int V_260 ;
T_21 V_261 ;
T_21 V_262 ;
T_7 * V_37 ;
struct V_263 V_263 ;
int V_264 ;
if ( ! F_49 ( V_1 -> V_6 . V_77 ) )
return F_8 ( V_220 ) ;
switch ( V_257 -> V_265 ) {
case 0 :
break;
case 1 :
V_257 -> V_266 += V_205 ;
break;
case 2 :
V_257 -> V_266 += V_1 -> V_44 ;
break;
default:
return F_8 ( V_220 ) ;
}
V_262 = V_257 -> V_267 > 0 ? V_257 -> V_267 - 1 : V_257 -> V_267 ;
if ( ( V_257 -> V_266 < 0 )
|| ( V_257 -> V_266 > F_18 ( V_3 ) )
|| ( V_257 -> V_266 + V_262 < 0 )
|| ( V_257 -> V_266 + V_262 > F_18 ( V_3 ) ) )
return F_8 ( V_220 ) ;
V_257 -> V_265 = 0 ;
V_261 = V_257 -> V_266 ;
V_259 = V_1 -> V_44 ;
V_260 = V_258 = 0 ;
V_264 = V_268 ;
switch ( V_256 ) {
case V_269 :
V_264 |= V_270 ;
F_158 ( V_1 , V_261 , V_261 + V_257 -> V_267 , 0 ) ;
case V_271 :
case V_272 :
error = F_126 ( V_1 , V_261 , V_257 -> V_267 ,
V_264 , V_207 ) ;
if ( error )
return error ;
V_260 = 1 ;
break;
case V_273 :
case V_274 :
if ( ( error = F_151 ( V_1 , V_261 , V_257 -> V_267 ,
V_207 ) ) )
return error ;
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
if ( V_261 > V_259 ) {
error = F_126 ( V_1 , V_259 ,
V_261 - V_259 , 0 , V_207 ) ;
if ( error )
break;
}
V_263 . V_279 = V_280 ;
V_263 . V_281 = V_261 ;
error = F_159 ( V_1 , & V_263 , V_207 ) ;
if ( error )
return error ;
V_258 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_8 ( V_220 ) ;
}
V_37 = F_20 ( V_3 , V_282 ) ;
if ( ( error = F_23 ( V_37 , 0 , F_160 ( V_3 ) ,
0 , 0 , 0 ) ) ) {
F_22 ( V_37 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_52 ) ;
F_25 ( V_37 , V_1 , V_52 ) ;
if ( ( V_207 & V_283 ) == 0 ) {
V_1 -> V_6 . V_77 &= ~ V_284 ;
if ( V_1 -> V_6 . V_77 & V_285 )
V_1 -> V_6 . V_77 &= ~ V_286 ;
F_92 ( V_37 , V_1 , V_137 | V_138 ) ;
}
if ( V_260 )
V_1 -> V_6 . V_87 |= V_88 ;
else if ( V_258 )
V_1 -> V_6 . V_87 &= ~ V_88 ;
F_30 ( V_37 , V_1 , V_64 ) ;
if ( V_207 & V_287 )
F_95 ( V_37 ) ;
return F_27 ( V_37 , 0 ) ;
}
