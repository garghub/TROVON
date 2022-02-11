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
error = F_8 ( V_30 ) ;
goto V_15;
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
V_38 = F_3 ( V_3 , ( V_43 ) F_18 ( V_1 ) ) ;
V_39 = F_3 ( V_3 , ( V_43 ) F_19 ( V_3 ) ) ;
if ( V_39 <= V_38 )
return 0 ;
V_40 = V_39 - V_38 ;
V_41 = 1 ;
F_14 ( V_1 , V_27 ) ;
error = F_2 ( V_1 , V_38 , V_40 , & V_42 , & V_41 , 0 ) ;
F_16 ( V_1 , V_27 ) ;
if ( ! error && ( V_41 != 0 ) &&
( V_42 . V_16 != V_44 ||
V_1 -> V_45 ) ) {
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
V_37 = F_21 ( V_3 , V_46 ) ;
if ( V_36 & V_47 ) {
if ( ! F_22 ( V_1 , V_48 ) ) {
F_23 ( V_37 , 0 ) ;
return 0 ;
}
} else {
F_14 ( V_1 , V_48 ) ;
}
error = F_24 ( V_37 , 0 ,
F_25 ( V_3 ) ,
0 , V_49 ,
V_50 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
F_16 ( V_1 , V_48 ) ;
return error ;
}
F_14 ( V_1 , V_51 ) ;
F_26 ( V_37 , V_1 , 0 ) ;
error = F_27 ( & V_37 , V_1 , V_52 ,
F_18 ( V_1 ) ) ;
if ( error ) {
F_23 ( V_37 ,
( V_53 |
V_54 ) ) ;
} else {
error = F_28 ( V_37 ,
V_53 ) ;
}
F_16 ( V_1 , V_48 | V_51 ) ;
}
return error ;
}
STATIC int
F_29 (
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
ASSERT ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ;
ASSERT ( V_1 -> V_6 . V_63 > 0 && V_1 -> V_6 . V_63 <= 2 ) ;
if ( ( error = F_24 ( V_37 , 0 , F_25 ( V_3 ) , 0 ,
V_49 , V_50 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
* V_55 = NULL ;
return error ;
}
F_14 ( V_1 , V_48 | V_51 ) ;
V_62 = ( int ) V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_7 = 0 ;
F_26 ( V_37 , V_1 , 0 ) ;
F_31 ( V_37 , V_1 , V_64 ) ;
V_57 = 0 ;
F_32 ( & V_59 , & V_58 ) ;
V_8 = F_33 ( V_10 ) ;
error = F_2 ( V_1 , 0 , F_3 ( V_3 , V_62 ) ,
V_10 , & V_8 , 0 ) ;
if ( error )
goto V_65;
for ( V_60 = 0 ; V_60 < V_8 ; V_60 ++ ) {
V_14 = F_34 ( V_37 , V_3 -> V_18 ,
F_4 ( V_3 , V_10 [ V_60 ] . V_16 ) ,
F_35 ( V_3 , V_10 [ V_60 ] . V_17 ) , 0 ) ;
if ( ! V_14 ) {
error = V_22 ;
goto V_66;
}
F_36 ( V_37 , V_14 ) ;
}
if ( ( error = F_37 ( V_37 , V_1 , 0 , V_62 , V_67 , V_8 ,
& V_58 , & V_59 , & V_57 ) ) )
goto V_66;
ASSERT ( V_57 ) ;
if ( ( error = F_38 ( & V_37 , & V_59 , & V_56 ) ) )
goto V_66;
ASSERT ( V_56 ) ;
F_26 ( V_37 , V_1 , 0 ) ;
F_31 ( V_37 , V_1 , V_64 ) ;
V_61 = F_39 ( V_37 ) ;
error = F_28 ( V_37 , 0 ) ;
V_37 = V_61 ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_65;
}
F_40 ( V_37 -> V_68 ) ;
if ( V_1 -> V_31 . V_69 )
F_41 ( V_1 , - V_1 -> V_31 . V_69 , V_52 ) ;
ASSERT ( V_1 -> V_31 . V_69 == 0 ) ;
if ( ( error = F_24 ( V_37 , 0 , F_25 ( V_3 ) , 0 ,
V_49 , V_50 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_65;
}
* V_55 = V_37 ;
return 0 ;
V_66:
F_42 ( & V_59 ) ;
V_65:
F_23 ( V_37 , V_53 | V_54 ) ;
F_16 ( V_1 , V_48 | V_51 ) ;
* V_55 = NULL ;
return error ;
}
STATIC int
F_43 (
T_1 * V_1 ,
T_7 * * V_55 )
{
int error ;
ASSERT ( V_1 -> V_6 . V_7 <= F_30 ( V_1 ) ) ;
error = F_24 ( * V_55 , 0 ,
F_25 ( V_1 -> V_4 ) ,
0 , V_49 ,
V_50 ) ;
if ( error ) {
F_23 ( * V_55 , 0 ) ;
* V_55 = NULL ;
return error ;
}
F_14 ( V_1 , V_51 | V_48 ) ;
if ( V_1 -> V_31 . V_69 > 0 ) {
F_41 ( V_1 ,
- ( V_1 -> V_31 . V_69 ) ,
V_52 ) ;
ASSERT ( V_1 -> V_31 . V_69 == 0 ) ;
}
return 0 ;
}
STATIC int
F_44 (
T_1 * V_1 ,
T_7 * * V_55 )
{
T_7 * V_37 ;
int error ;
T_2 * V_3 ;
ASSERT ( F_45 ( V_1 , V_48 ) ) ;
V_37 = * V_55 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_70 != 0 ) ;
error = F_28 ( V_37 , V_53 ) ;
F_16 ( V_1 , V_51 ) ;
if ( error )
goto V_71;
error = F_46 ( V_1 ) ;
if ( error )
goto V_71;
V_37 = F_21 ( V_3 , V_46 ) ;
error = F_24 ( V_37 , 0 ,
F_47 ( V_3 ) ,
0 , V_49 ,
V_72 ) ;
if ( error )
goto V_73;
F_14 ( V_1 , V_51 ) ;
F_26 ( V_37 , V_1 , 0 ) ;
F_48 ( V_1 , V_74 ) ;
ASSERT ( V_1 -> V_6 . V_75 == 0 ) ;
* V_55 = V_37 ;
return 0 ;
V_73:
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
V_71:
* V_55 = NULL ;
F_16 ( V_1 , V_48 ) ;
return error ;
}
int
F_49 (
T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
int error ;
if ( ! F_50 ( V_1 -> V_6 . V_76 ) || ( V_1 -> V_6 . V_76 == 0 ) )
return 0 ;
if ( V_3 -> V_77 & V_78 )
return 0 ;
if ( ! F_13 ( V_3 ) ) {
int V_79 ;
if ( ( V_1 -> V_6 . V_80 == 0 ) && F_51 ( V_1 ) )
F_52 ( V_1 ) ;
V_79 = F_53 ( V_1 , V_81 ) ;
if ( V_79 ) {
F_54 ( V_1 , V_82 ) ;
if ( F_55 ( F_56 ( V_1 ) ) && V_1 -> V_45 > 0 )
F_57 ( V_1 , 0 , - 1 , V_83 , V_84 ) ;
}
}
if ( V_1 -> V_6 . V_80 == 0 )
return 0 ;
if ( ( F_50 ( V_1 -> V_6 . V_76 ) &&
( F_56 ( V_1 ) -> V_85 > 0 ||
( F_58 ( F_56 ( V_1 ) ) > 0 || V_1 -> V_45 > 0 ) ) &&
( V_1 -> V_31 . V_32 & V_86 ) ) &&
( ! ( V_1 -> V_6 . V_87 & ( V_88 | V_89 ) ) ) ) {
if ( F_59 ( V_1 , V_82 ) )
return 0 ;
error = F_17 ( V_3 , V_1 ,
V_47 ) ;
if ( error )
return error ;
if ( V_1 -> V_45 )
F_60 ( V_1 , V_82 ) ;
}
return 0 ;
}
int
F_61 (
T_1 * V_1 )
{
T_11 V_59 ;
T_10 V_58 ;
int V_56 ;
T_7 * V_37 ;
T_2 * V_3 ;
int error ;
int V_90 ;
if ( V_1 -> V_6 . V_76 == 0 || F_62 ( F_56 ( V_1 ) ) ) {
ASSERT ( V_1 -> V_31 . V_91 == 0 ) ;
ASSERT ( V_1 -> V_31 . V_92 == 0 ) ;
return V_93 ;
}
V_90 = ( ( V_1 -> V_6 . V_80 == 0 ) &&
( ( V_1 -> V_6 . V_7 != 0 ) || F_18 ( V_1 ) != 0 ||
( V_1 -> V_6 . V_63 > 0 ) || ( V_1 -> V_45 > 0 ) ) &&
F_50 ( V_1 -> V_6 . V_76 ) ) ;
V_3 = V_1 -> V_4 ;
error = 0 ;
if ( V_3 -> V_77 & V_78 )
goto V_15;
if ( V_1 -> V_6 . V_80 != 0 ) {
if ( ( F_50 ( V_1 -> V_6 . V_76 ) &&
( F_56 ( V_1 ) -> V_85 > 0 ||
( F_58 ( F_56 ( V_1 ) ) > 0 || V_1 -> V_45 > 0 ) ) &&
( V_1 -> V_31 . V_32 & V_86 ) &&
( ! ( V_1 -> V_6 . V_87 &
( V_88 | V_89 ) ) ||
V_1 -> V_45 != 0 ) ) ) {
error = F_17 ( V_3 , V_1 , 0 ) ;
if ( error )
return V_93 ;
}
goto V_15;
}
ASSERT ( V_1 -> V_6 . V_80 == 0 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return V_93 ;
V_37 = F_21 ( V_3 , V_46 ) ;
if ( V_90 ) {
F_14 ( V_1 , V_48 ) ;
error = F_24 ( V_37 , 0 ,
F_25 ( V_3 ) ,
0 , V_49 ,
V_50 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
F_16 ( V_1 , V_48 ) ;
return V_93 ;
}
F_14 ( V_1 , V_51 ) ;
F_26 ( V_37 , V_1 , 0 ) ;
V_1 -> V_6 . V_7 = 0 ;
F_31 ( V_37 , V_1 , V_64 ) ;
error = F_27 ( & V_37 , V_1 , V_52 , 0 ) ;
if ( error ) {
F_23 ( V_37 ,
V_53 | V_54 ) ;
F_16 ( V_1 , V_48 | V_51 ) ;
return V_93 ;
}
ASSERT ( V_1 -> V_6 . V_63 == 0 ) ;
} else if ( F_63 ( V_1 -> V_6 . V_76 ) ) {
error = ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ?
F_29 ( V_1 , & V_37 ) :
F_43 ( V_1 , & V_37 ) ;
if ( error ) {
ASSERT ( V_37 == NULL ) ;
return V_93 ;
}
F_26 ( V_37 , V_1 , 0 ) ;
} else {
error = F_24 ( V_37 , 0 ,
F_47 ( V_3 ) ,
0 , V_49 ,
V_72 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
return V_93 ;
}
F_14 ( V_1 , V_51 | V_48 ) ;
F_26 ( V_37 , V_1 , 0 ) ;
}
if ( V_1 -> V_6 . V_75 > 0 ) {
error = F_44 ( V_1 , & V_37 ) ;
if ( error )
return V_93 ;
} else if ( V_1 -> V_94 ) {
F_48 ( V_1 , V_74 ) ;
}
F_32 ( & V_59 , & V_58 ) ;
error = F_64 ( V_37 , V_1 , & V_59 ) ;
if ( error ) {
if ( ! F_13 ( V_3 ) ) {
F_65 ( V_3 , L_2 ,
V_24 , error ) ;
F_66 ( V_3 , V_95 ) ;
}
F_23 ( V_37 , V_53 | V_54 ) ;
} else {
F_67 ( V_37 , V_1 , V_96 , - 1 ) ;
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error )
F_65 ( V_3 , L_3 ,
V_24 , error ) ;
error = F_28 ( V_37 , V_53 ) ;
if ( error )
F_65 ( V_3 , L_4 ,
V_24 , error ) ;
}
F_68 ( V_1 ) ;
F_16 ( V_1 , V_48 | V_51 ) ;
V_15:
return V_93 ;
}
int
F_69 (
T_1 * V_97 ,
struct V_98 * V_99 ,
T_1 * * V_100 ,
struct V_98 * V_101 )
{
T_12 V_102 ;
int error ;
T_13 V_103 ;
F_70 ( V_97 , V_99 ) ;
if ( F_13 ( V_97 -> V_4 ) )
return F_8 ( V_26 ) ;
V_103 = F_71 ( V_97 ) ;
error = F_72 ( NULL , V_97 , V_99 , & V_102 , V_101 ) ;
F_73 ( V_97 , V_103 ) ;
if ( error )
goto V_15;
error = F_74 ( V_97 -> V_4 , NULL , V_102 , 0 , 0 , V_100 ) ;
if ( error )
goto V_104;
return 0 ;
V_104:
if ( V_101 )
F_75 ( V_101 -> V_99 ) ;
V_15:
* V_100 = NULL ;
return error ;
}
int
F_76 (
T_1 * V_97 ,
struct V_98 * V_99 ,
T_14 V_105 ,
T_15 V_106 ,
T_1 * * V_100 )
{
int V_107 = F_77 ( V_105 ) ;
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
F_78 ( V_97 , V_99 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
if ( V_97 -> V_6 . V_87 & V_121 )
V_114 = F_79 ( V_97 ) ;
else
V_114 = V_122 ;
error = F_80 ( V_97 , F_81 () , F_82 () , V_114 ,
V_123 | V_124 , & V_116 , & V_117 ) ;
if ( error )
return error ;
if ( V_107 ) {
V_106 = 0 ;
V_118 = F_83 ( V_3 , V_99 -> V_125 ) ;
V_119 = F_84 ( V_3 ) ;
V_120 = V_126 ;
V_37 = F_21 ( V_3 , V_127 ) ;
} else {
V_118 = F_85 ( V_3 , V_99 -> V_125 ) ;
V_119 = F_86 ( V_3 ) ;
V_120 = V_128 ;
V_37 = F_21 ( V_3 , V_129 ) ;
}
V_113 = V_53 ;
error = F_24 ( V_37 , V_118 , V_119 , 0 ,
V_49 , V_120 ) ;
if ( error == V_130 ) {
F_87 ( V_97 ) ;
error = F_24 ( V_37 , V_118 , V_119 , 0 ,
V_49 , V_120 ) ;
}
if ( error == V_130 ) {
V_118 = 0 ;
error = F_24 ( V_37 , 0 , V_119 , 0 ,
V_49 , V_120 ) ;
}
if ( error ) {
V_113 = 0 ;
goto V_131;
}
F_14 ( V_97 , V_51 | V_132 ) ;
V_111 = V_133 ;
F_32 ( & V_59 , & V_58 ) ;
error = F_88 ( V_37 , V_3 , V_116 , V_117 , V_118 , 1 , 0 ) ;
if ( error )
goto V_131;
error = F_89 ( V_37 , V_97 , V_99 , V_118 ) ;
if ( error )
goto V_131;
error = F_90 ( & V_37 , V_97 , V_105 , V_107 ? 2 : 1 , V_106 ,
V_114 , V_118 > 0 , & V_1 , & V_56 ) ;
if ( error ) {
if ( error == V_130 )
goto V_131;
goto V_134;
}
F_26 ( V_37 , V_97 , V_51 ) ;
V_111 = V_112 ;
error = F_91 ( V_37 , V_97 , V_99 , V_1 -> V_29 ,
& V_58 , & V_59 , V_118 ?
V_118 - F_92 ( V_3 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_130 ) ;
goto V_134;
}
F_93 ( V_37 , V_97 , V_135 | V_136 ) ;
F_31 ( V_37 , V_97 , V_64 ) ;
if ( V_107 ) {
error = F_94 ( V_37 , V_1 , V_97 ) ;
if ( error )
goto V_137;
error = F_95 ( V_37 , V_97 ) ;
if ( error )
goto V_137;
}
if ( V_3 -> V_77 & ( V_138 | V_139 ) )
F_96 ( V_37 ) ;
F_97 ( V_37 , V_1 , V_116 , V_117 ) ;
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error )
goto V_137;
error = F_28 ( V_37 , V_53 ) ;
if ( error )
goto V_140;
F_98 ( V_116 ) ;
F_98 ( V_117 ) ;
* V_100 = V_1 ;
return 0 ;
V_137:
F_42 ( & V_59 ) ;
V_134:
V_113 |= V_54 ;
V_131:
F_23 ( V_37 , V_113 ) ;
V_140:
if ( V_1 )
F_99 ( V_1 ) ;
F_98 ( V_116 ) ;
F_98 ( V_117 ) ;
if ( V_111 )
F_16 ( V_97 , V_51 ) ;
return error ;
}
static inline int
F_100 ( int V_103 , int V_141 )
{
if ( V_103 & ( V_142 | V_48 ) )
V_103 |= ( V_141 + V_143 ) << V_144 ;
if ( V_103 & ( V_27 | V_51 ) )
V_103 |= ( V_141 + V_143 ) << V_145 ;
return V_103 ;
}
void
F_101 (
T_1 * * V_146 ,
int V_147 ,
T_13 V_103 )
{
int V_148 = 0 , V_60 , V_149 , V_150 ;
T_18 * V_151 ;
ASSERT ( V_146 && ( V_147 >= 2 ) ) ;
V_150 = 0 ;
V_60 = 0 ;
V_152:
for (; V_60 < V_147 ; V_60 ++ ) {
ASSERT ( V_146 [ V_60 ] ) ;
if ( V_60 && ( V_146 [ V_60 ] == V_146 [ V_60 - 1 ] ) )
continue;
if ( ! V_150 ) {
for ( V_149 = ( V_60 - 1 ) ; V_149 >= 0 && ! V_150 ; V_149 -- ) {
V_151 = ( T_18 * ) V_146 [ V_149 ] -> V_153 ;
if ( V_151 && ( V_151 -> V_154 & V_155 ) ) {
V_150 ++ ;
}
}
}
if ( V_150 ) {
ASSERT ( V_60 != 0 ) ;
if ( ! F_22 ( V_146 [ V_60 ] , F_100 ( V_103 , V_60 ) ) ) {
V_148 ++ ;
for( V_149 = V_60 - 1 ; V_149 >= 0 ; V_149 -- ) {
if ( ( V_149 != ( V_60 - 1 ) ) && V_146 [ V_149 ] ==
V_146 [ V_149 + 1 ] )
continue;
F_16 ( V_146 [ V_149 ] , V_103 ) ;
}
if ( ( V_148 % 5 ) == 0 ) {
F_102 ( 1 ) ;
#ifdef F_103
V_156 ++ ;
#endif
}
V_60 = 0 ;
V_150 = 0 ;
goto V_152;
}
} else {
F_14 ( V_146 [ V_60 ] , F_100 ( V_103 , V_60 ) ) ;
}
}
#ifdef F_103
if ( V_148 ) {
if ( V_148 < 5 ) V_157 ++ ;
else if ( V_148 < 100 ) V_158 ++ ;
else V_159 ++ ;
} else {
V_160 ++ ;
}
#endif
}
void
F_104 (
T_1 * V_161 ,
T_1 * V_162 ,
T_13 V_103 )
{
T_1 * V_163 ;
int V_148 = 0 ;
T_18 * V_151 ;
if ( V_103 & ( V_142 | V_48 ) )
ASSERT ( ( V_103 & ( V_27 | V_51 ) ) == 0 ) ;
ASSERT ( V_161 -> V_29 != V_162 -> V_29 ) ;
if ( V_161 -> V_29 > V_162 -> V_29 ) {
V_163 = V_161 ;
V_161 = V_162 ;
V_162 = V_163 ;
}
V_152:
F_14 ( V_161 , F_100 ( V_103 , 0 ) ) ;
V_151 = ( T_18 * ) V_161 -> V_153 ;
if ( V_151 && ( V_151 -> V_154 & V_155 ) ) {
if ( ! F_22 ( V_162 , F_100 ( V_103 , 1 ) ) ) {
F_16 ( V_161 , V_103 ) ;
if ( ( ++ V_148 % 5 ) == 0 )
F_102 ( 1 ) ;
goto V_152;
}
} else {
F_14 ( V_162 , F_100 ( V_103 , 1 ) ) ;
}
}
int
F_105 (
T_1 * V_97 ,
struct V_98 * V_99 ,
T_1 * V_1 )
{
T_2 * V_3 = V_97 -> V_4 ;
T_7 * V_37 = NULL ;
int V_107 = F_77 ( V_1 -> V_6 . V_76 ) ;
int error = 0 ;
T_11 V_59 ;
T_10 V_58 ;
int V_113 ;
int V_56 ;
int V_164 ;
T_13 V_118 ;
T_13 V_120 ;
F_106 ( V_97 , V_99 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
error = F_20 ( V_97 , 0 ) ;
if ( error )
goto V_165;
error = F_20 ( V_1 , 0 ) ;
if ( error )
goto V_165;
if ( V_107 ) {
V_37 = F_21 ( V_3 , V_166 ) ;
V_120 = V_167 ;
} else {
V_37 = F_21 ( V_3 , V_168 ) ;
V_120 = V_169 ;
}
V_113 = V_53 ;
V_118 = F_107 ( V_3 ) ;
error = F_24 ( V_37 , V_118 , F_108 ( V_3 ) , 0 ,
V_49 , V_120 ) ;
if ( error == V_130 ) {
V_118 = 0 ;
error = F_24 ( V_37 , 0 , F_108 ( V_3 ) , 0 ,
V_49 , V_120 ) ;
}
if ( error ) {
ASSERT ( error != V_130 ) ;
V_113 = 0 ;
goto V_131;
}
F_104 ( V_97 , V_1 , V_51 ) ;
F_26 ( V_37 , V_97 , V_51 ) ;
F_26 ( V_37 , V_1 , V_51 ) ;
if ( V_107 ) {
ASSERT ( V_1 -> V_6 . V_80 >= 2 ) ;
if ( V_1 -> V_6 . V_80 != 2 ) {
error = F_8 ( V_170 ) ;
goto V_131;
}
if ( ! F_109 ( V_1 ) ) {
error = F_8 ( V_170 ) ;
goto V_131;
}
}
F_32 ( & V_59 , & V_58 ) ;
error = F_110 ( V_37 , V_97 , V_99 , V_1 -> V_29 ,
& V_58 , & V_59 , V_118 ) ;
if ( error ) {
ASSERT ( error != V_171 ) ;
goto V_137;
}
F_93 ( V_37 , V_97 , V_135 | V_136 ) ;
if ( V_107 ) {
error = F_111 ( V_37 , V_97 ) ;
if ( error )
goto V_137;
error = F_111 ( V_37 , V_1 ) ;
if ( error )
goto V_137;
} else {
F_31 ( V_37 , V_97 , V_64 ) ;
}
error = F_111 ( V_37 , V_1 ) ;
if ( error )
goto V_137;
V_164 = ( V_1 -> V_6 . V_80 == 0 ) ;
if ( V_3 -> V_77 & ( V_138 | V_139 ) )
F_96 ( V_37 ) ;
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error )
goto V_137;
error = F_28 ( V_37 , V_53 ) ;
if ( error )
goto V_165;
if ( ! V_107 && V_164 && F_51 ( V_1 ) )
F_52 ( V_1 ) ;
return 0 ;
V_137:
F_42 ( & V_59 ) ;
V_113 |= V_54 ;
V_131:
F_23 ( V_37 , V_113 ) ;
V_165:
return error ;
}
int
F_112 (
T_1 * V_172 ,
T_1 * V_173 ,
struct V_98 * V_174 )
{
T_2 * V_3 = V_172 -> V_4 ;
T_7 * V_37 ;
int error ;
T_11 V_59 ;
T_10 V_58 ;
int V_113 ;
int V_56 ;
int V_118 ;
F_113 ( V_172 , V_174 ) ;
ASSERT ( ! F_77 ( V_173 -> V_6 . V_76 ) ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
error = F_20 ( V_173 , 0 ) ;
if ( error )
goto V_165;
error = F_20 ( V_172 , 0 ) ;
if ( error )
goto V_165;
V_37 = F_21 ( V_3 , V_175 ) ;
V_113 = V_53 ;
V_118 = F_114 ( V_3 , V_174 -> V_125 ) ;
error = F_24 ( V_37 , V_118 , F_115 ( V_3 ) , 0 ,
V_49 , V_176 ) ;
if ( error == V_130 ) {
V_118 = 0 ;
error = F_24 ( V_37 , 0 , F_115 ( V_3 ) , 0 ,
V_49 , V_176 ) ;
}
if ( error ) {
V_113 = 0 ;
goto V_177;
}
F_104 ( V_173 , V_172 , V_51 ) ;
F_26 ( V_37 , V_173 , V_51 ) ;
F_26 ( V_37 , V_172 , V_51 ) ;
if ( F_116 ( ( V_172 -> V_6 . V_87 & V_121 ) &&
( F_79 ( V_172 ) != F_79 ( V_173 ) ) ) ) {
error = F_8 ( V_178 ) ;
goto V_177;
}
error = F_89 ( V_37 , V_172 , V_174 , V_118 ) ;
if ( error )
goto V_177;
F_32 ( & V_59 , & V_58 ) ;
error = F_91 ( V_37 , V_172 , V_174 , V_173 -> V_29 ,
& V_58 , & V_59 , V_118 ) ;
if ( error )
goto V_179;
F_93 ( V_37 , V_172 , V_135 | V_136 ) ;
F_31 ( V_37 , V_172 , V_64 ) ;
error = F_95 ( V_37 , V_173 ) ;
if ( error )
goto V_179;
if ( V_3 -> V_77 & ( V_138 | V_139 ) ) {
F_96 ( V_37 ) ;
}
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
F_42 ( & V_59 ) ;
goto V_179;
}
return F_28 ( V_37 , V_53 ) ;
V_179:
V_113 |= V_54 ;
V_177:
F_23 ( V_37 , V_113 ) ;
V_165:
return error ;
}
int
F_117 (
T_1 * V_97 ,
struct V_98 * V_180 ,
const char * V_181 ,
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
T_8 V_182 ;
T_9 V_183 ;
int V_8 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
const char * V_184 ;
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
F_118 ( V_97 , V_180 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
V_5 = strlen ( V_181 ) ;
if ( V_5 >= V_28 )
return F_8 ( V_185 ) ;
V_116 = V_117 = NULL ;
if ( V_97 -> V_6 . V_87 & V_121 )
V_114 = F_79 ( V_97 ) ;
else
V_114 = V_122 ;
error = F_80 ( V_97 , F_81 () , F_82 () , V_114 ,
V_123 | V_124 , & V_116 , & V_117 ) ;
if ( error )
goto V_165;
V_37 = F_21 ( V_3 , V_186 ) ;
V_113 = V_53 ;
if ( V_5 <= F_119 ( V_3 ) )
V_183 = 0 ;
else
V_183 = F_3 ( V_3 , V_5 ) ;
V_118 = F_120 ( V_3 , V_180 -> V_125 , V_183 ) ;
error = F_24 ( V_37 , V_118 , F_121 ( V_3 ) , 0 ,
V_49 , V_187 ) ;
if ( error == V_130 && V_183 == 0 ) {
V_118 = 0 ;
error = F_24 ( V_37 , 0 , F_121 ( V_3 ) , 0 ,
V_49 , V_187 ) ;
}
if ( error ) {
V_113 = 0 ;
goto V_177;
}
F_14 ( V_97 , V_51 | V_132 ) ;
V_111 = V_133 ;
if ( V_97 -> V_6 . V_87 & V_188 ) {
error = F_8 ( V_189 ) ;
goto V_177;
}
error = F_88 ( V_37 , V_3 , V_116 , V_117 , V_118 , 1 , 0 ) ;
if ( error )
goto V_177;
error = F_89 ( V_37 , V_97 , V_180 , V_118 ) ;
if ( error )
goto V_177;
F_32 ( & V_59 , & V_58 ) ;
error = F_90 ( & V_37 , V_97 , V_190 | ( V_105 & ~ V_191 ) , 1 , 0 ,
V_114 , V_118 > 0 , & V_1 , NULL ) ;
if ( error ) {
if ( error == V_130 )
goto V_177;
goto V_66;
}
F_26 ( V_37 , V_97 , V_51 ) ;
V_111 = V_112 ;
F_97 ( V_37 , V_1 , V_116 , V_117 ) ;
if ( V_118 )
V_118 -= F_92 ( V_3 ) ;
if ( V_5 <= F_30 ( V_1 ) ) {
F_41 ( V_1 , V_5 , V_52 ) ;
memcpy ( V_1 -> V_31 . V_34 . V_35 , V_181 , V_5 ) ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_31 . V_32 &= ~ ( V_86 | V_192 ) ;
V_1 -> V_31 . V_32 |= V_33 ;
V_1 -> V_6 . V_193 = V_194 ;
F_31 ( V_37 , V_1 , V_195 | V_64 ) ;
} else {
V_182 = 0 ;
V_8 = V_9 ;
error = F_122 ( V_37 , V_1 , V_182 , V_183 ,
V_67 , & V_58 , V_118 ,
V_10 , & V_8 , & V_59 ) ;
if ( error )
goto V_196;
if ( V_118 )
V_118 -= V_183 ;
V_1 -> V_6 . V_7 = V_5 ;
F_31 ( V_37 , V_1 , V_64 ) ;
V_184 = V_181 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_34 ( V_37 , V_3 -> V_18 , V_11 ,
F_7 ( V_12 ) , 0 ) ;
if ( ! V_14 ) {
error = V_22 ;
goto V_196;
}
if ( V_5 < V_12 ) {
V_12 = V_5 ;
}
V_5 -= V_12 ;
memcpy ( V_14 -> V_25 , V_184 , V_12 ) ;
V_184 += V_12 ;
F_123 ( V_37 , V_14 , 0 , V_12 - 1 ) ;
}
}
error = F_91 ( V_37 , V_97 , V_180 , V_1 -> V_29 ,
& V_58 , & V_59 , V_118 ) ;
if ( error )
goto V_196;
F_93 ( V_37 , V_97 , V_135 | V_136 ) ;
F_31 ( V_37 , V_97 , V_64 ) ;
if ( V_3 -> V_77 & ( V_138 | V_139 ) ) {
F_96 ( V_37 ) ;
}
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
goto V_196;
}
error = F_28 ( V_37 , V_53 ) ;
F_98 ( V_116 ) ;
F_98 ( V_117 ) ;
* V_100 = V_1 ;
return 0 ;
V_196:
F_99 ( V_1 ) ;
V_66:
F_42 ( & V_59 ) ;
V_113 |= V_54 ;
V_177:
F_23 ( V_37 , V_113 ) ;
F_98 ( V_116 ) ;
F_98 ( V_117 ) ;
if ( V_111 )
F_16 ( V_97 , V_51 ) ;
V_165:
return error ;
}
int
F_124 (
T_1 * V_1 ,
T_19 V_197 ,
T_20 V_198 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_7 * V_37 ;
int error ;
if ( ! F_125 ( V_199 ) )
return F_8 ( V_189 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
V_37 = F_21 ( V_3 , V_200 ) ;
error = F_24 ( V_37 , 0 , F_126 ( V_3 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_23 ( V_37 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_51 ) ;
F_26 ( V_37 , V_1 , V_51 ) ;
V_1 -> V_6 . V_201 = V_197 ;
V_1 -> V_6 . V_202 = V_198 ;
F_31 ( V_37 , V_1 , V_64 ) ;
error = F_28 ( V_37 , 0 ) ;
return error ;
}
STATIC int
F_127 (
T_1 * V_1 ,
T_21 V_203 ,
T_21 V_125 ,
int V_204 ,
int V_205 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_21 V_206 ;
T_9 V_207 ;
T_9 V_208 ;
T_22 V_209 , V_163 ;
T_8 V_210 ;
T_10 V_211 ;
int V_41 ;
int V_212 ;
int V_213 ;
T_7 * V_37 ;
T_3 V_214 [ 1 ] , * V_215 ;
T_11 V_59 ;
T_13 V_216 , V_118 , V_217 ;
int V_56 ;
int error ;
F_128 ( V_1 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_26 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
if ( V_125 <= 0 )
return F_8 ( V_218 ) ;
V_213 = F_129 ( V_1 ) ;
V_209 = F_130 ( V_1 ) ;
V_206 = V_125 ;
V_215 = & V_214 [ 0 ] ;
V_41 = 1 ;
V_210 = F_131 ( V_3 , V_203 ) ;
V_208 = F_3 ( V_3 , V_206 ) ;
while ( V_208 && ! error ) {
T_8 V_219 , V_220 ;
if ( F_116 ( V_209 ) ) {
V_219 = V_210 ;
F_132 ( V_219 , V_209 ) ;
V_219 *= V_209 ;
V_220 = V_210 + V_208 ;
if ( ( V_163 = F_133 ( V_210 , V_209 ) ) )
V_220 += V_163 ;
if ( ( V_163 = F_133 ( V_220 , V_209 ) ) )
V_220 += V_209 - V_163 ;
} else {
V_219 = 0 ;
V_220 = V_208 ;
}
V_118 = F_134 ( T_8 , ( V_220 - V_219 ) , ( V_221 * V_41 ) ) ;
if ( F_116 ( V_213 ) ) {
V_217 = V_216 = V_118 ;
V_217 /= V_3 -> V_222 . V_223 ;
V_118 = F_135 ( V_3 , 0 ) ;
V_212 = V_224 ;
} else {
V_217 = 0 ;
V_118 = V_216 = F_135 ( V_3 , V_118 ) ;
V_212 = V_225 ;
}
V_37 = F_21 ( V_3 , V_226 ) ;
error = F_24 ( V_37 , V_118 ,
F_136 ( V_3 ) , V_217 ,
V_49 ,
V_227 ) ;
if ( error ) {
ASSERT ( error == V_130 || F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
break;
}
F_14 ( V_1 , V_51 ) ;
error = F_137 ( V_37 , V_1 , V_216 ,
0 , V_212 ) ;
if ( error )
goto V_66;
F_26 ( V_37 , V_1 , 0 ) ;
F_32 ( & V_59 , & V_211 ) ;
error = F_122 ( V_37 , V_1 , V_210 ,
V_208 , V_204 , & V_211 ,
0 , V_215 , & V_41 , & V_59 ) ;
if ( error ) {
goto V_65;
}
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
goto V_65;
}
error = F_28 ( V_37 , V_53 ) ;
F_16 ( V_1 , V_51 ) ;
if ( error ) {
break;
}
V_207 = V_215 -> V_17 ;
if ( V_41 == 0 ) {
error = F_8 ( V_130 ) ;
break;
}
V_210 += V_207 ;
V_208 -= V_207 ;
}
return error ;
V_65:
F_42 ( & V_59 ) ;
F_138 ( V_37 , V_1 , V_216 , 0 , V_212 ) ;
V_66:
F_23 ( V_37 , V_53 | V_54 ) ;
F_16 ( V_1 , V_51 ) ;
return error ;
}
STATIC int
F_139 (
T_1 * V_1 ,
T_21 V_228 ,
T_21 V_229 )
{
T_3 V_42 ;
T_8 V_230 ;
T_21 V_231 ;
T_21 V_203 ;
T_5 * V_14 ;
T_2 * V_3 = V_1 -> V_4 ;
int V_232 ;
int error = 0 ;
if ( V_228 >= F_18 ( V_1 ) )
return 0 ;
if ( V_229 > F_18 ( V_1 ) )
V_229 = F_18 ( V_1 ) ;
V_14 = F_140 ( F_129 ( V_1 ) ?
V_3 -> V_233 : V_3 -> V_18 ,
V_3 -> V_222 . V_234 , V_21 ) ;
if ( ! V_14 )
return F_8 ( V_22 ) ;
F_141 ( V_14 ) ;
for ( V_203 = V_228 ; V_203 <= V_229 ; V_203 = V_231 + 1 ) {
V_230 = F_131 ( V_3 , V_203 ) ;
V_232 = 1 ;
error = F_2 ( V_1 , V_230 , 1 , & V_42 , & V_232 , 0 ) ;
if ( error || V_232 < 1 )
break;
ASSERT ( V_42 . V_17 >= 1 ) ;
ASSERT ( V_42 . V_235 == V_230 ) ;
V_231 = F_5 ( V_3 , V_42 . V_235 + 1 ) - 1 ;
if ( V_231 > V_229 )
V_231 = V_229 ;
if ( V_42 . V_16 == V_44 )
continue;
ASSERT ( V_42 . V_16 != V_236 ) ;
if ( V_42 . V_237 == V_238 )
continue;
F_142 ( V_14 ) ;
F_143 ( V_14 ) ;
F_144 ( V_14 ) ;
F_145 ( V_14 , F_146 ( V_1 , V_42 . V_16 ) ) ;
F_147 ( V_3 , V_14 ) ;
error = F_148 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_5 ) ;
break;
}
memset ( V_14 -> V_25 +
( V_203 - F_5 ( V_3 , V_42 . V_235 ) ) ,
0 , V_231 - V_203 + 1 ) ;
F_142 ( V_14 ) ;
F_149 ( V_14 ) ;
F_150 ( V_14 ) ;
F_147 ( V_3 , V_14 ) ;
error = F_148 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_6 ) ;
break;
}
}
F_151 ( V_14 ) ;
return error ;
}
STATIC int
F_152 (
T_1 * V_1 ,
T_21 V_203 ,
T_21 V_125 ,
int V_205 )
{
int V_56 ;
int V_57 ;
T_8 V_239 ;
int error ;
T_10 V_211 ;
T_11 V_59 ;
T_3 V_42 ;
T_21 V_240 ;
T_22 V_241 = 0 ;
T_2 * V_3 ;
int V_232 ;
T_13 V_118 ;
T_13 V_242 ;
int V_213 ;
T_8 V_210 ;
T_7 * V_37 ;
int V_243 = 1 ;
V_3 = V_1 -> V_4 ;
F_153 ( V_1 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_125 <= 0 )
return error ;
V_213 = F_129 ( V_1 ) ;
V_210 = F_3 ( V_3 , V_203 ) ;
V_239 = F_131 ( V_3 , V_203 + V_125 ) ;
if ( V_205 & V_244 )
V_243 = 0 ;
if ( V_243 ) {
F_14 ( V_1 , V_48 ) ;
F_154 ( F_56 ( V_1 ) ) ;
}
V_242 = F_155 ( T_13 , 1 << V_3 -> V_222 . V_245 , V_246 ) ;
V_240 = V_203 & ~ ( V_242 - 1 ) ;
if ( F_58 ( F_56 ( V_1 ) ) != 0 ) {
error = F_156 ( V_1 , V_240 , - 1 , V_247 ) ;
if ( error )
goto V_248;
}
if ( V_213 && ! F_157 ( & V_3 -> V_222 ) ) {
V_232 = 1 ;
error = F_2 ( V_1 , V_210 , 1 ,
& V_42 , & V_232 , 0 ) ;
if ( error )
goto V_248;
ASSERT ( V_232 == 0 || V_232 == 1 ) ;
if ( V_232 && V_42 . V_16 != V_44 ) {
T_4 V_249 ;
ASSERT ( V_42 . V_16 != V_236 ) ;
V_249 = V_42 . V_16 ;
V_241 = F_132 ( V_249 , V_3 -> V_222 . V_223 ) ;
if ( V_241 )
V_210 += V_3 -> V_222 . V_223 - V_241 ;
}
V_232 = 1 ;
error = F_2 ( V_1 , V_239 - 1 , 1 ,
& V_42 , & V_232 , 0 ) ;
if ( error )
goto V_248;
ASSERT ( V_232 == 0 || V_232 == 1 ) ;
if ( V_232 && V_42 . V_16 != V_44 ) {
ASSERT ( V_42 . V_16 != V_236 ) ;
V_241 ++ ;
if ( V_241 && ( V_241 != V_3 -> V_222 . V_223 ) )
V_239 -= V_241 ;
}
}
if ( ( V_57 = ( V_239 <= V_210 ) ) )
error = F_139 ( V_1 , V_203 , V_203 + V_125 - 1 ) ;
else {
if ( V_203 < F_5 ( V_3 , V_210 ) )
error = F_139 ( V_1 , V_203 ,
F_5 ( V_3 , V_210 ) - 1 ) ;
if ( ! error &&
F_5 ( V_3 , V_239 ) < V_203 + V_125 )
error = F_139 ( V_1 ,
F_5 ( V_3 , V_239 ) ,
V_203 + V_125 - 1 ) ;
}
V_118 = F_135 ( V_3 , 0 ) ;
while ( ! error && ! V_57 ) {
V_37 = F_21 ( V_3 , V_226 ) ;
V_37 -> V_250 |= V_251 ;
error = F_24 ( V_37 ,
V_118 ,
F_136 ( V_3 ) ,
0 ,
V_49 ,
V_227 ) ;
if ( error ) {
ASSERT ( error == V_130 || F_13 ( V_3 ) ) ;
F_23 ( V_37 , 0 ) ;
break;
}
F_14 ( V_1 , V_51 ) ;
error = F_88 ( V_37 , V_3 ,
V_1 -> V_252 , V_1 -> V_253 ,
V_118 , 0 , V_225 ) ;
if ( error )
goto V_66;
F_26 ( V_37 , V_1 , 0 ) ;
F_32 ( & V_59 , & V_211 ) ;
error = F_37 ( V_37 , V_1 , V_210 ,
V_239 - V_210 ,
0 , 2 , & V_211 , & V_59 , & V_57 ) ;
if ( error ) {
goto V_65;
}
error = F_38 ( & V_37 , & V_59 , & V_56 ) ;
if ( error ) {
goto V_65;
}
error = F_28 ( V_37 , V_53 ) ;
F_16 ( V_1 , V_51 ) ;
}
V_248:
if ( V_243 )
F_16 ( V_1 , V_48 ) ;
return error ;
V_65:
F_42 ( & V_59 ) ;
V_66:
F_23 ( V_37 , V_53 | V_54 ) ;
F_16 ( V_1 , V_243 ? ( V_51 | V_48 ) :
V_51 ) ;
return error ;
}
int
F_158 (
T_1 * V_1 ,
int V_254 ,
T_23 * V_255 ,
T_21 V_203 ,
int V_205 )
{
T_2 * V_3 = V_1 -> V_4 ;
int V_256 ;
int error ;
T_6 V_257 ;
int V_258 ;
T_21 V_259 ;
T_21 V_260 ;
T_7 * V_37 ;
struct V_261 V_261 ;
int V_262 ;
if ( ! F_50 ( V_1 -> V_6 . V_76 ) )
return F_8 ( V_218 ) ;
switch ( V_255 -> V_263 ) {
case 0 :
break;
case 1 :
V_255 -> V_264 += V_203 ;
break;
case 2 :
V_255 -> V_264 += F_18 ( V_1 ) ;
break;
default:
return F_8 ( V_218 ) ;
}
V_260 = V_255 -> V_265 > 0 ? V_255 -> V_265 - 1 : V_255 -> V_265 ;
if ( ( V_255 -> V_264 < 0 )
|| ( V_255 -> V_264 > F_19 ( V_3 ) )
|| ( V_255 -> V_264 + V_260 < 0 )
|| ( V_255 -> V_264 + V_260 > F_19 ( V_3 ) ) )
return F_8 ( V_218 ) ;
V_255 -> V_263 = 0 ;
V_259 = V_255 -> V_264 ;
V_257 = F_18 ( V_1 ) ;
V_258 = V_256 = 0 ;
V_262 = V_266 ;
switch ( V_254 ) {
case V_267 :
V_262 |= V_268 ;
F_159 ( V_1 , V_259 , V_259 + V_255 -> V_265 , 0 ) ;
case V_269 :
case V_270 :
error = F_127 ( V_1 , V_259 , V_255 -> V_265 ,
V_262 , V_205 ) ;
if ( error )
return error ;
V_258 = 1 ;
break;
case V_271 :
case V_272 :
if ( ( error = F_152 ( V_1 , V_259 , V_255 -> V_265 ,
V_205 ) ) )
return error ;
break;
case V_273 :
case V_274 :
case V_275 :
case V_276 :
if ( V_259 > V_257 ) {
error = F_127 ( V_1 , V_257 ,
V_259 - V_257 , 0 , V_205 ) ;
if ( error )
break;
}
V_261 . V_277 = V_278 ;
V_261 . V_279 = V_259 ;
error = F_160 ( V_1 , & V_261 , V_205 ) ;
if ( error )
return error ;
V_256 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_8 ( V_218 ) ;
}
V_37 = F_21 ( V_3 , V_280 ) ;
if ( ( error = F_24 ( V_37 , 0 , F_161 ( V_3 ) ,
0 , 0 , 0 ) ) ) {
F_23 ( V_37 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_51 ) ;
F_26 ( V_37 , V_1 , V_51 ) ;
if ( ( V_205 & V_281 ) == 0 ) {
V_1 -> V_6 . V_76 &= ~ V_282 ;
if ( V_1 -> V_6 . V_76 & V_283 )
V_1 -> V_6 . V_76 &= ~ V_284 ;
F_93 ( V_37 , V_1 , V_135 | V_136 ) ;
}
if ( V_258 )
V_1 -> V_6 . V_87 |= V_88 ;
else if ( V_256 )
V_1 -> V_6 . V_87 &= ~ V_88 ;
F_31 ( V_37 , V_1 , V_64 ) ;
if ( V_205 & V_285 )
F_96 ( V_37 ) ;
return F_28 ( V_37 , 0 ) ;
}
