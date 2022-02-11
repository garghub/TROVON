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
int V_33 )
{
T_7 * V_34 ;
int error ;
T_8 V_35 ;
T_8 V_36 ;
T_9 V_37 ;
int V_38 ;
T_3 V_39 ;
V_35 = F_3 ( V_3 , ( V_40 ) F_18 ( V_1 ) ) ;
V_36 = F_3 ( V_3 , ( V_40 ) F_19 ( V_3 ) ) ;
if ( V_36 <= V_35 )
return 0 ;
V_37 = V_36 - V_35 ;
V_38 = 1 ;
F_14 ( V_1 , V_24 ) ;
error = F_2 ( V_1 , V_35 , V_37 , & V_39 , & V_38 , 0 ) ;
F_16 ( V_1 , V_24 ) ;
if ( ! error && ( V_38 != 0 ) &&
( V_39 . V_16 != V_41 ||
V_1 -> V_42 ) ) {
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
V_34 = F_21 ( V_3 , V_43 ) ;
if ( V_33 & V_44 ) {
if ( ! F_22 ( V_1 , V_45 ) ) {
F_23 ( V_34 , 0 ) ;
return 0 ;
}
} else {
F_14 ( V_1 , V_45 ) ;
}
error = F_24 ( V_34 , 0 ,
F_25 ( V_3 ) ,
0 , V_46 ,
V_47 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
F_16 ( V_1 , V_45 ) ;
return error ;
}
F_14 ( V_1 , V_48 ) ;
F_26 ( V_34 , V_1 , 0 ) ;
error = F_27 ( & V_34 , V_1 , V_49 ,
F_18 ( V_1 ) ) ;
if ( error ) {
F_23 ( V_34 ,
( V_50 |
V_51 ) ) ;
} else {
error = F_28 ( V_34 ,
V_50 ) ;
}
F_16 ( V_1 , V_45 | V_48 ) ;
}
return error ;
}
STATIC int
F_29 (
T_1 * V_1 ,
T_7 * * V_52 )
{
T_5 * V_14 ;
int V_53 ;
int V_54 ;
int error ;
T_10 V_55 ;
T_11 V_56 ;
int V_57 ;
T_2 * V_3 ;
T_3 V_10 [ V_9 ] ;
int V_8 ;
T_7 * V_58 ;
int V_59 ;
T_7 * V_34 ;
V_34 = * V_52 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ;
ASSERT ( V_1 -> V_6 . V_60 > 0 && V_1 -> V_6 . V_60 <= 2 ) ;
if ( ( error = F_24 ( V_34 , 0 , F_25 ( V_3 ) , 0 ,
V_46 , V_47 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
* V_52 = NULL ;
return error ;
}
F_14 ( V_1 , V_45 | V_48 ) ;
V_59 = ( int ) V_1 -> V_6 . V_7 ;
V_1 -> V_6 . V_7 = 0 ;
F_26 ( V_34 , V_1 , 0 ) ;
F_31 ( V_34 , V_1 , V_61 ) ;
V_54 = 0 ;
F_32 ( & V_56 , & V_55 ) ;
V_8 = F_33 ( V_10 ) ;
error = F_2 ( V_1 , 0 , F_3 ( V_3 , V_59 ) ,
V_10 , & V_8 , 0 ) ;
if ( error )
goto V_62;
for ( V_57 = 0 ; V_57 < V_8 ; V_57 ++ ) {
V_14 = F_34 ( V_34 , V_3 -> V_18 ,
F_4 ( V_3 , V_10 [ V_57 ] . V_16 ) ,
F_35 ( V_3 , V_10 [ V_57 ] . V_17 ) , 0 ) ;
if ( ! V_14 ) {
error = V_19 ;
goto V_63;
}
F_36 ( V_34 , V_14 ) ;
}
if ( ( error = F_37 ( V_34 , V_1 , 0 , V_59 , V_64 , V_8 ,
& V_55 , & V_56 , & V_54 ) ) )
goto V_63;
ASSERT ( V_54 ) ;
if ( ( error = F_38 ( & V_34 , & V_56 , & V_53 ) ) )
goto V_63;
ASSERT ( V_53 ) ;
F_26 ( V_34 , V_1 , 0 ) ;
F_31 ( V_34 , V_1 , V_61 ) ;
V_58 = F_39 ( V_34 ) ;
error = F_28 ( V_34 , 0 ) ;
V_34 = V_58 ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_62;
}
F_40 ( V_34 -> V_65 ) ;
if ( V_1 -> V_28 . V_66 )
F_41 ( V_1 , - V_1 -> V_28 . V_66 , V_49 ) ;
ASSERT ( V_1 -> V_28 . V_66 == 0 ) ;
if ( ( error = F_24 ( V_34 , 0 , F_25 ( V_3 ) , 0 ,
V_46 , V_47 ) ) ) {
ASSERT ( F_13 ( V_3 ) ) ;
goto V_62;
}
* V_52 = V_34 ;
return 0 ;
V_63:
F_42 ( & V_56 ) ;
V_62:
F_23 ( V_34 , V_50 | V_51 ) ;
F_16 ( V_1 , V_45 | V_48 ) ;
* V_52 = NULL ;
return error ;
}
STATIC int
F_43 (
T_1 * V_1 ,
T_7 * * V_52 )
{
int error ;
ASSERT ( V_1 -> V_6 . V_7 <= F_30 ( V_1 ) ) ;
error = F_24 ( * V_52 , 0 ,
F_25 ( V_1 -> V_4 ) ,
0 , V_46 ,
V_47 ) ;
if ( error ) {
F_23 ( * V_52 , 0 ) ;
* V_52 = NULL ;
return error ;
}
F_14 ( V_1 , V_48 | V_45 ) ;
if ( V_1 -> V_28 . V_66 > 0 ) {
F_41 ( V_1 ,
- ( V_1 -> V_28 . V_66 ) ,
V_49 ) ;
ASSERT ( V_1 -> V_28 . V_66 == 0 ) ;
}
return 0 ;
}
STATIC int
F_44 (
T_1 * V_1 ,
T_7 * * V_52 )
{
T_7 * V_34 ;
int error ;
T_2 * V_3 ;
ASSERT ( F_45 ( V_1 , V_45 ) ) ;
V_34 = * V_52 ;
V_3 = V_1 -> V_4 ;
ASSERT ( V_1 -> V_6 . V_67 != 0 ) ;
error = F_28 ( V_34 , V_50 ) ;
F_16 ( V_1 , V_48 ) ;
if ( error )
goto V_68;
error = F_46 ( V_1 ) ;
if ( error )
goto V_68;
V_34 = F_21 ( V_3 , V_43 ) ;
error = F_24 ( V_34 , 0 ,
F_47 ( V_3 ) ,
0 , V_46 ,
V_69 ) ;
if ( error )
goto V_70;
F_14 ( V_1 , V_48 ) ;
F_26 ( V_34 , V_1 , 0 ) ;
F_48 ( V_1 , V_71 ) ;
ASSERT ( V_1 -> V_6 . V_72 == 0 ) ;
* V_52 = V_34 ;
return 0 ;
V_70:
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
V_68:
* V_52 = NULL ;
F_16 ( V_1 , V_45 ) ;
return error ;
}
int
F_49 (
T_1 * V_1 )
{
T_2 * V_3 = V_1 -> V_4 ;
int error ;
if ( ! F_50 ( V_1 -> V_6 . V_73 ) || ( V_1 -> V_6 . V_73 == 0 ) )
return 0 ;
if ( V_3 -> V_74 & V_75 )
return 0 ;
if ( ! F_13 ( V_3 ) ) {
int V_76 ;
if ( ( V_1 -> V_6 . V_77 == 0 ) && F_51 ( V_1 ) )
F_52 ( V_1 ) ;
V_76 = F_53 ( V_1 , V_78 ) ;
if ( V_76 ) {
F_54 ( V_1 , V_79 ) ;
if ( F_55 ( F_56 ( V_1 ) ) && V_1 -> V_42 > 0 )
F_57 ( V_1 , 0 , - 1 , V_80 , V_81 ) ;
}
}
if ( V_1 -> V_6 . V_77 == 0 )
return 0 ;
if ( ( F_50 ( V_1 -> V_6 . V_73 ) &&
( F_56 ( V_1 ) -> V_82 > 0 ||
( F_58 ( F_56 ( V_1 ) ) > 0 || V_1 -> V_42 > 0 ) ) &&
( V_1 -> V_28 . V_29 & V_83 ) ) &&
( ! ( V_1 -> V_6 . V_84 & ( V_85 | V_86 ) ) ) ) {
if ( F_59 ( V_1 , V_79 ) )
return 0 ;
error = F_17 ( V_3 , V_1 ,
V_44 ) ;
if ( error )
return error ;
if ( V_1 -> V_42 )
F_60 ( V_1 , V_79 ) ;
}
return 0 ;
}
int
F_61 (
T_1 * V_1 )
{
T_11 V_56 ;
T_10 V_55 ;
int V_53 ;
T_7 * V_34 ;
T_2 * V_3 ;
int error ;
int V_87 ;
if ( V_1 -> V_6 . V_73 == 0 || F_62 ( F_56 ( V_1 ) ) ) {
ASSERT ( V_1 -> V_28 . V_88 == 0 ) ;
ASSERT ( V_1 -> V_28 . V_89 == 0 ) ;
return V_90 ;
}
V_87 = ( ( V_1 -> V_6 . V_77 == 0 ) &&
( ( V_1 -> V_6 . V_7 != 0 ) || F_18 ( V_1 ) != 0 ||
( V_1 -> V_6 . V_60 > 0 ) || ( V_1 -> V_42 > 0 ) ) &&
F_50 ( V_1 -> V_6 . V_73 ) ) ;
V_3 = V_1 -> V_4 ;
error = 0 ;
if ( V_3 -> V_74 & V_75 )
goto V_15;
if ( V_1 -> V_6 . V_77 != 0 ) {
if ( ( F_50 ( V_1 -> V_6 . V_73 ) &&
( F_56 ( V_1 ) -> V_82 > 0 ||
( F_58 ( F_56 ( V_1 ) ) > 0 || V_1 -> V_42 > 0 ) ) &&
( V_1 -> V_28 . V_29 & V_83 ) &&
( ! ( V_1 -> V_6 . V_84 &
( V_85 | V_86 ) ) ||
V_1 -> V_42 != 0 ) ) ) {
error = F_17 ( V_3 , V_1 , 0 ) ;
if ( error )
return V_90 ;
}
goto V_15;
}
ASSERT ( V_1 -> V_6 . V_77 == 0 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return V_90 ;
V_34 = F_21 ( V_3 , V_43 ) ;
if ( V_87 ) {
F_14 ( V_1 , V_45 ) ;
error = F_24 ( V_34 , 0 ,
F_25 ( V_3 ) ,
0 , V_46 ,
V_47 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
F_16 ( V_1 , V_45 ) ;
return V_90 ;
}
F_14 ( V_1 , V_48 ) ;
F_26 ( V_34 , V_1 , 0 ) ;
V_1 -> V_6 . V_7 = 0 ;
F_31 ( V_34 , V_1 , V_61 ) ;
error = F_27 ( & V_34 , V_1 , V_49 , 0 ) ;
if ( error ) {
F_23 ( V_34 ,
V_50 | V_51 ) ;
F_16 ( V_1 , V_45 | V_48 ) ;
return V_90 ;
}
ASSERT ( V_1 -> V_6 . V_60 == 0 ) ;
} else if ( F_63 ( V_1 -> V_6 . V_73 ) ) {
error = ( V_1 -> V_6 . V_7 > F_30 ( V_1 ) ) ?
F_29 ( V_1 , & V_34 ) :
F_43 ( V_1 , & V_34 ) ;
if ( error ) {
ASSERT ( V_34 == NULL ) ;
return V_90 ;
}
F_26 ( V_34 , V_1 , 0 ) ;
} else {
error = F_24 ( V_34 , 0 ,
F_47 ( V_3 ) ,
0 , V_46 ,
V_69 ) ;
if ( error ) {
ASSERT ( F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
return V_90 ;
}
F_14 ( V_1 , V_48 | V_45 ) ;
F_26 ( V_34 , V_1 , 0 ) ;
}
if ( V_1 -> V_6 . V_72 > 0 ) {
error = F_44 ( V_1 , & V_34 ) ;
if ( error )
return V_90 ;
} else if ( V_1 -> V_91 ) {
F_48 ( V_1 , V_71 ) ;
}
F_32 ( & V_56 , & V_55 ) ;
error = F_64 ( V_34 , V_1 , & V_56 ) ;
if ( error ) {
if ( ! F_13 ( V_3 ) ) {
F_65 ( V_3 , L_2 ,
V_21 , error ) ;
F_66 ( V_3 , V_92 ) ;
}
F_23 ( V_34 , V_50 | V_51 ) ;
} else {
F_67 ( V_34 , V_1 , V_93 , - 1 ) ;
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error )
F_65 ( V_3 , L_3 ,
V_21 , error ) ;
error = F_28 ( V_34 , V_50 ) ;
if ( error )
F_65 ( V_3 , L_4 ,
V_21 , error ) ;
}
F_68 ( V_1 ) ;
F_16 ( V_1 , V_45 | V_48 ) ;
V_15:
return V_90 ;
}
int
F_69 (
T_1 * V_94 ,
struct V_95 * V_96 ,
T_1 * * V_97 ,
struct V_95 * V_98 )
{
T_12 V_99 ;
int error ;
T_13 V_100 ;
F_70 ( V_94 , V_96 ) ;
if ( F_13 ( V_94 -> V_4 ) )
return F_8 ( V_23 ) ;
V_100 = F_71 ( V_94 ) ;
error = F_72 ( NULL , V_94 , V_96 , & V_99 , V_98 ) ;
F_73 ( V_94 , V_100 ) ;
if ( error )
goto V_15;
error = F_74 ( V_94 -> V_4 , NULL , V_99 , 0 , 0 , V_97 ) ;
if ( error )
goto V_101;
return 0 ;
V_101:
if ( V_98 )
F_75 ( V_98 -> V_96 ) ;
V_15:
* V_97 = NULL ;
return error ;
}
int
F_76 (
T_1 * V_94 ,
struct V_95 * V_96 ,
T_14 V_102 ,
T_15 V_103 ,
T_1 * * V_97 )
{
int V_104 = F_77 ( V_102 ) ;
struct V_105 * V_3 = V_94 -> V_4 ;
struct V_106 * V_1 = NULL ;
struct V_107 * V_34 = NULL ;
int error ;
T_11 V_56 ;
T_10 V_55 ;
T_16 V_108 = V_109 ;
T_13 V_110 ;
int V_53 ;
T_17 V_111 ;
struct V_112 * V_113 = NULL ;
struct V_112 * V_114 = NULL ;
T_13 V_115 ;
T_13 V_116 ;
T_13 V_117 ;
F_78 ( V_94 , V_96 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
if ( V_94 -> V_6 . V_84 & V_118 )
V_111 = F_79 ( V_94 ) ;
else
V_111 = V_119 ;
error = F_80 ( V_94 , F_81 () , F_82 () , V_111 ,
V_120 | V_121 , & V_113 , & V_114 ) ;
if ( error )
return error ;
if ( V_104 ) {
V_103 = 0 ;
V_115 = F_83 ( V_3 , V_96 -> V_122 ) ;
V_116 = F_84 ( V_3 ) ;
V_117 = V_123 ;
V_34 = F_21 ( V_3 , V_124 ) ;
} else {
V_115 = F_85 ( V_3 , V_96 -> V_122 ) ;
V_116 = F_86 ( V_3 ) ;
V_117 = V_125 ;
V_34 = F_21 ( V_3 , V_126 ) ;
}
V_110 = V_50 ;
error = F_24 ( V_34 , V_115 , V_116 , 0 ,
V_46 , V_117 ) ;
if ( error == V_127 ) {
F_87 ( V_94 ) ;
error = F_24 ( V_34 , V_115 , V_116 , 0 ,
V_46 , V_117 ) ;
}
if ( error == V_127 ) {
V_115 = 0 ;
error = F_24 ( V_34 , 0 , V_116 , 0 ,
V_46 , V_117 ) ;
}
if ( error ) {
V_110 = 0 ;
goto V_128;
}
F_14 ( V_94 , V_48 | V_129 ) ;
V_108 = V_130 ;
F_32 ( & V_56 , & V_55 ) ;
error = F_88 ( V_34 , V_3 , V_113 , V_114 , V_115 , 1 , 0 ) ;
if ( error )
goto V_128;
error = F_89 ( V_34 , V_94 , V_96 , V_115 ) ;
if ( error )
goto V_128;
error = F_90 ( & V_34 , V_94 , V_102 , V_104 ? 2 : 1 , V_103 ,
V_111 , V_115 > 0 , & V_1 , & V_53 ) ;
if ( error ) {
if ( error == V_127 )
goto V_128;
goto V_131;
}
F_26 ( V_34 , V_94 , V_48 ) ;
V_108 = V_109 ;
error = F_91 ( V_34 , V_94 , V_96 , V_1 -> V_26 ,
& V_55 , & V_56 , V_115 ?
V_115 - F_92 ( V_3 ) : 0 ) ;
if ( error ) {
ASSERT ( error != V_127 ) ;
goto V_131;
}
F_93 ( V_34 , V_94 , V_132 | V_133 ) ;
F_31 ( V_34 , V_94 , V_61 ) ;
if ( V_104 ) {
error = F_94 ( V_34 , V_1 , V_94 ) ;
if ( error )
goto V_134;
error = F_95 ( V_34 , V_94 ) ;
if ( error )
goto V_134;
}
if ( V_3 -> V_74 & ( V_135 | V_136 ) )
F_96 ( V_34 ) ;
F_97 ( V_34 , V_1 , V_113 , V_114 ) ;
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error )
goto V_134;
error = F_28 ( V_34 , V_50 ) ;
if ( error )
goto V_137;
F_98 ( V_113 ) ;
F_98 ( V_114 ) ;
* V_97 = V_1 ;
return 0 ;
V_134:
F_42 ( & V_56 ) ;
V_131:
V_110 |= V_51 ;
V_128:
F_23 ( V_34 , V_110 ) ;
V_137:
if ( V_1 )
F_99 ( V_1 ) ;
F_98 ( V_113 ) ;
F_98 ( V_114 ) ;
if ( V_108 )
F_16 ( V_94 , V_48 ) ;
return error ;
}
static inline int
F_100 ( int V_100 , int V_138 )
{
if ( V_100 & ( V_139 | V_45 ) )
V_100 |= ( V_138 + V_140 ) << V_141 ;
if ( V_100 & ( V_24 | V_48 ) )
V_100 |= ( V_138 + V_140 ) << V_142 ;
return V_100 ;
}
void
F_101 (
T_1 * * V_143 ,
int V_144 ,
T_13 V_100 )
{
int V_145 = 0 , V_57 , V_146 , V_147 ;
T_18 * V_148 ;
ASSERT ( V_143 && ( V_144 >= 2 ) ) ;
V_147 = 0 ;
V_57 = 0 ;
V_149:
for (; V_57 < V_144 ; V_57 ++ ) {
ASSERT ( V_143 [ V_57 ] ) ;
if ( V_57 && ( V_143 [ V_57 ] == V_143 [ V_57 - 1 ] ) )
continue;
if ( ! V_147 ) {
for ( V_146 = ( V_57 - 1 ) ; V_146 >= 0 && ! V_147 ; V_146 -- ) {
V_148 = ( T_18 * ) V_143 [ V_146 ] -> V_150 ;
if ( V_148 && ( V_148 -> V_151 & V_152 ) ) {
V_147 ++ ;
}
}
}
if ( V_147 ) {
ASSERT ( V_57 != 0 ) ;
if ( ! F_22 ( V_143 [ V_57 ] , F_100 ( V_100 , V_57 ) ) ) {
V_145 ++ ;
for( V_146 = V_57 - 1 ; V_146 >= 0 ; V_146 -- ) {
if ( ( V_146 != ( V_57 - 1 ) ) && V_143 [ V_146 ] ==
V_143 [ V_146 + 1 ] )
continue;
F_16 ( V_143 [ V_146 ] , V_100 ) ;
}
if ( ( V_145 % 5 ) == 0 ) {
F_102 ( 1 ) ;
#ifdef F_103
V_153 ++ ;
#endif
}
V_57 = 0 ;
V_147 = 0 ;
goto V_149;
}
} else {
F_14 ( V_143 [ V_57 ] , F_100 ( V_100 , V_57 ) ) ;
}
}
#ifdef F_103
if ( V_145 ) {
if ( V_145 < 5 ) V_154 ++ ;
else if ( V_145 < 100 ) V_155 ++ ;
else V_156 ++ ;
} else {
V_157 ++ ;
}
#endif
}
void
F_104 (
T_1 * V_158 ,
T_1 * V_159 ,
T_13 V_100 )
{
T_1 * V_160 ;
int V_145 = 0 ;
T_18 * V_148 ;
if ( V_100 & ( V_139 | V_45 ) )
ASSERT ( ( V_100 & ( V_24 | V_48 ) ) == 0 ) ;
ASSERT ( V_158 -> V_26 != V_159 -> V_26 ) ;
if ( V_158 -> V_26 > V_159 -> V_26 ) {
V_160 = V_158 ;
V_158 = V_159 ;
V_159 = V_160 ;
}
V_149:
F_14 ( V_158 , F_100 ( V_100 , 0 ) ) ;
V_148 = ( T_18 * ) V_158 -> V_150 ;
if ( V_148 && ( V_148 -> V_151 & V_152 ) ) {
if ( ! F_22 ( V_159 , F_100 ( V_100 , 1 ) ) ) {
F_16 ( V_158 , V_100 ) ;
if ( ( ++ V_145 % 5 ) == 0 )
F_102 ( 1 ) ;
goto V_149;
}
} else {
F_14 ( V_159 , F_100 ( V_100 , 1 ) ) ;
}
}
int
F_105 (
T_1 * V_94 ,
struct V_95 * V_96 ,
T_1 * V_1 )
{
T_2 * V_3 = V_94 -> V_4 ;
T_7 * V_34 = NULL ;
int V_104 = F_77 ( V_1 -> V_6 . V_73 ) ;
int error = 0 ;
T_11 V_56 ;
T_10 V_55 ;
int V_110 ;
int V_53 ;
int V_161 ;
T_13 V_115 ;
T_13 V_117 ;
F_106 ( V_94 , V_96 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_20 ( V_94 , 0 ) ;
if ( error )
goto V_162;
error = F_20 ( V_1 , 0 ) ;
if ( error )
goto V_162;
if ( V_104 ) {
V_34 = F_21 ( V_3 , V_163 ) ;
V_117 = V_164 ;
} else {
V_34 = F_21 ( V_3 , V_165 ) ;
V_117 = V_166 ;
}
V_110 = V_50 ;
V_115 = F_107 ( V_3 ) ;
error = F_24 ( V_34 , V_115 , F_108 ( V_3 ) , 0 ,
V_46 , V_117 ) ;
if ( error == V_127 ) {
V_115 = 0 ;
error = F_24 ( V_34 , 0 , F_108 ( V_3 ) , 0 ,
V_46 , V_117 ) ;
}
if ( error ) {
ASSERT ( error != V_127 ) ;
V_110 = 0 ;
goto V_128;
}
F_104 ( V_94 , V_1 , V_48 ) ;
F_26 ( V_34 , V_94 , V_48 ) ;
F_26 ( V_34 , V_1 , V_48 ) ;
if ( V_104 ) {
ASSERT ( V_1 -> V_6 . V_77 >= 2 ) ;
if ( V_1 -> V_6 . V_77 != 2 ) {
error = F_8 ( V_167 ) ;
goto V_128;
}
if ( ! F_109 ( V_1 ) ) {
error = F_8 ( V_167 ) ;
goto V_128;
}
}
F_32 ( & V_56 , & V_55 ) ;
error = F_110 ( V_34 , V_94 , V_96 , V_1 -> V_26 ,
& V_55 , & V_56 , V_115 ) ;
if ( error ) {
ASSERT ( error != V_168 ) ;
goto V_134;
}
F_93 ( V_34 , V_94 , V_132 | V_133 ) ;
if ( V_104 ) {
error = F_111 ( V_34 , V_94 ) ;
if ( error )
goto V_134;
error = F_111 ( V_34 , V_1 ) ;
if ( error )
goto V_134;
} else {
F_31 ( V_34 , V_94 , V_61 ) ;
}
error = F_111 ( V_34 , V_1 ) ;
if ( error )
goto V_134;
V_161 = ( V_1 -> V_6 . V_77 == 0 ) ;
if ( V_3 -> V_74 & ( V_135 | V_136 ) )
F_96 ( V_34 ) ;
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error )
goto V_134;
error = F_28 ( V_34 , V_50 ) ;
if ( error )
goto V_162;
if ( ! V_104 && V_161 && F_51 ( V_1 ) )
F_52 ( V_1 ) ;
return 0 ;
V_134:
F_42 ( & V_56 ) ;
V_110 |= V_51 ;
V_128:
F_23 ( V_34 , V_110 ) ;
V_162:
return error ;
}
int
F_112 (
T_1 * V_169 ,
T_1 * V_170 ,
struct V_95 * V_171 )
{
T_2 * V_3 = V_169 -> V_4 ;
T_7 * V_34 ;
int error ;
T_11 V_56 ;
T_10 V_55 ;
int V_110 ;
int V_53 ;
int V_115 ;
F_113 ( V_169 , V_171 ) ;
ASSERT ( ! F_77 ( V_170 -> V_6 . V_73 ) ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_20 ( V_170 , 0 ) ;
if ( error )
goto V_162;
error = F_20 ( V_169 , 0 ) ;
if ( error )
goto V_162;
V_34 = F_21 ( V_3 , V_172 ) ;
V_110 = V_50 ;
V_115 = F_114 ( V_3 , V_171 -> V_122 ) ;
error = F_24 ( V_34 , V_115 , F_115 ( V_3 ) , 0 ,
V_46 , V_173 ) ;
if ( error == V_127 ) {
V_115 = 0 ;
error = F_24 ( V_34 , 0 , F_115 ( V_3 ) , 0 ,
V_46 , V_173 ) ;
}
if ( error ) {
V_110 = 0 ;
goto V_174;
}
F_104 ( V_170 , V_169 , V_48 ) ;
F_26 ( V_34 , V_170 , V_48 ) ;
F_26 ( V_34 , V_169 , V_48 ) ;
if ( F_116 ( ( V_169 -> V_6 . V_84 & V_118 ) &&
( F_79 ( V_169 ) != F_79 ( V_170 ) ) ) ) {
error = F_8 ( V_175 ) ;
goto V_174;
}
error = F_89 ( V_34 , V_169 , V_171 , V_115 ) ;
if ( error )
goto V_174;
F_32 ( & V_56 , & V_55 ) ;
error = F_91 ( V_34 , V_169 , V_171 , V_170 -> V_26 ,
& V_55 , & V_56 , V_115 ) ;
if ( error )
goto V_176;
F_93 ( V_34 , V_169 , V_132 | V_133 ) ;
F_31 ( V_34 , V_169 , V_61 ) ;
error = F_95 ( V_34 , V_170 ) ;
if ( error )
goto V_176;
if ( V_3 -> V_74 & ( V_135 | V_136 ) ) {
F_96 ( V_34 ) ;
}
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error ) {
F_42 ( & V_56 ) ;
goto V_176;
}
return F_28 ( V_34 , V_50 ) ;
V_176:
V_110 |= V_51 ;
V_174:
F_23 ( V_34 , V_110 ) ;
V_162:
return error ;
}
int
F_117 (
T_1 * V_94 ,
struct V_95 * V_177 ,
const char * V_178 ,
T_14 V_102 ,
T_1 * * V_97 )
{
T_2 * V_3 = V_94 -> V_4 ;
T_7 * V_34 ;
T_1 * V_1 ;
int error ;
int V_5 ;
T_11 V_56 ;
T_10 V_55 ;
T_16 V_108 = V_109 ;
T_13 V_110 ;
int V_53 ;
T_8 V_179 ;
T_9 V_180 ;
int V_8 ;
T_3 V_10 [ V_9 ] ;
T_4 V_11 ;
const char * V_181 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
T_17 V_111 ;
struct V_112 * V_113 , * V_114 ;
T_13 V_115 ;
* V_97 = NULL ;
error = 0 ;
V_1 = NULL ;
V_34 = NULL ;
F_118 ( V_94 , V_177 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
V_5 = strlen ( V_178 ) ;
if ( V_5 >= V_25 )
return F_8 ( V_182 ) ;
V_113 = V_114 = NULL ;
if ( V_94 -> V_6 . V_84 & V_118 )
V_111 = F_79 ( V_94 ) ;
else
V_111 = V_119 ;
error = F_80 ( V_94 , F_81 () , F_82 () , V_111 ,
V_120 | V_121 , & V_113 , & V_114 ) ;
if ( error )
goto V_162;
V_34 = F_21 ( V_3 , V_183 ) ;
V_110 = V_50 ;
if ( V_5 <= F_119 ( V_3 ) )
V_180 = 0 ;
else
V_180 = F_3 ( V_3 , V_5 ) ;
V_115 = F_120 ( V_3 , V_177 -> V_122 , V_180 ) ;
error = F_24 ( V_34 , V_115 , F_121 ( V_3 ) , 0 ,
V_46 , V_184 ) ;
if ( error == V_127 && V_180 == 0 ) {
V_115 = 0 ;
error = F_24 ( V_34 , 0 , F_121 ( V_3 ) , 0 ,
V_46 , V_184 ) ;
}
if ( error ) {
V_110 = 0 ;
goto V_174;
}
F_14 ( V_94 , V_48 | V_129 ) ;
V_108 = V_130 ;
if ( V_94 -> V_6 . V_84 & V_185 ) {
error = F_8 ( V_186 ) ;
goto V_174;
}
error = F_88 ( V_34 , V_3 , V_113 , V_114 , V_115 , 1 , 0 ) ;
if ( error )
goto V_174;
error = F_89 ( V_34 , V_94 , V_177 , V_115 ) ;
if ( error )
goto V_174;
F_32 ( & V_56 , & V_55 ) ;
error = F_90 ( & V_34 , V_94 , V_187 | ( V_102 & ~ V_188 ) , 1 , 0 ,
V_111 , V_115 > 0 , & V_1 , NULL ) ;
if ( error ) {
if ( error == V_127 )
goto V_174;
goto V_63;
}
F_26 ( V_34 , V_94 , V_48 ) ;
V_108 = V_109 ;
F_97 ( V_34 , V_1 , V_113 , V_114 ) ;
if ( V_115 )
V_115 -= F_92 ( V_3 ) ;
if ( V_5 <= F_30 ( V_1 ) ) {
F_41 ( V_1 , V_5 , V_49 ) ;
memcpy ( V_1 -> V_28 . V_31 . V_32 , V_178 , V_5 ) ;
V_1 -> V_6 . V_7 = V_5 ;
V_1 -> V_28 . V_29 &= ~ ( V_83 | V_189 ) ;
V_1 -> V_28 . V_29 |= V_30 ;
V_1 -> V_6 . V_190 = V_191 ;
F_31 ( V_34 , V_1 , V_192 | V_61 ) ;
} else {
V_179 = 0 ;
V_8 = V_9 ;
error = F_122 ( V_34 , V_1 , V_179 , V_180 ,
V_64 , & V_55 , V_115 ,
V_10 , & V_8 , & V_56 ) ;
if ( error )
goto V_193;
if ( V_115 )
V_115 -= V_180 ;
V_1 -> V_6 . V_7 = V_5 ;
F_31 ( V_34 , V_1 , V_61 ) ;
V_181 = V_178 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 = F_4 ( V_3 , V_10 [ V_13 ] . V_16 ) ;
V_12 = F_5 ( V_3 , V_10 [ V_13 ] . V_17 ) ;
V_14 = F_34 ( V_34 , V_3 -> V_18 , V_11 ,
F_7 ( V_12 ) , 0 ) ;
if ( ! V_14 ) {
error = V_19 ;
goto V_193;
}
if ( V_5 < V_12 ) {
V_12 = V_5 ;
}
V_5 -= V_12 ;
memcpy ( V_14 -> V_22 , V_181 , V_12 ) ;
V_181 += V_12 ;
F_123 ( V_34 , V_14 , 0 , V_12 - 1 ) ;
}
}
error = F_91 ( V_34 , V_94 , V_177 , V_1 -> V_26 ,
& V_55 , & V_56 , V_115 ) ;
if ( error )
goto V_193;
F_93 ( V_34 , V_94 , V_132 | V_133 ) ;
F_31 ( V_34 , V_94 , V_61 ) ;
if ( V_3 -> V_74 & ( V_135 | V_136 ) ) {
F_96 ( V_34 ) ;
}
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error ) {
goto V_193;
}
error = F_28 ( V_34 , V_50 ) ;
F_98 ( V_113 ) ;
F_98 ( V_114 ) ;
* V_97 = V_1 ;
return 0 ;
V_193:
F_99 ( V_1 ) ;
V_63:
F_42 ( & V_56 ) ;
V_110 |= V_51 ;
V_174:
F_23 ( V_34 , V_110 ) ;
F_98 ( V_113 ) ;
F_98 ( V_114 ) ;
if ( V_108 )
F_16 ( V_94 , V_48 ) ;
V_162:
return error ;
}
int
F_124 (
T_1 * V_1 ,
T_19 V_194 ,
T_20 V_195 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_7 * V_34 ;
int error ;
if ( ! F_125 ( V_196 ) )
return F_8 ( V_186 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
V_34 = F_21 ( V_3 , V_197 ) ;
error = F_24 ( V_34 , 0 , F_126 ( V_3 ) , 0 , 0 , 0 ) ;
if ( error ) {
F_23 ( V_34 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_48 ) ;
F_26 ( V_34 , V_1 , V_48 ) ;
V_1 -> V_6 . V_198 = V_194 ;
V_1 -> V_6 . V_199 = V_195 ;
F_31 ( V_34 , V_1 , V_61 ) ;
error = F_28 ( V_34 , 0 ) ;
return error ;
}
STATIC int
F_127 (
T_1 * V_1 ,
T_21 V_200 ,
T_21 V_122 ,
int V_201 ,
int V_202 )
{
T_2 * V_3 = V_1 -> V_4 ;
T_21 V_203 ;
T_9 V_204 ;
T_9 V_205 ;
T_22 V_206 , V_160 ;
T_8 V_207 ;
T_10 V_208 ;
int V_38 ;
int V_209 ;
int V_210 ;
T_7 * V_34 ;
T_3 V_211 [ 1 ] , * V_212 ;
T_11 V_56 ;
T_13 V_213 , V_115 , V_214 ;
int V_53 ;
int error ;
F_128 ( V_1 ) ;
if ( F_13 ( V_3 ) )
return F_8 ( V_23 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
if ( V_122 <= 0 )
return F_8 ( V_215 ) ;
V_210 = F_129 ( V_1 ) ;
V_206 = F_130 ( V_1 ) ;
V_203 = V_122 ;
V_212 = & V_211 [ 0 ] ;
V_38 = 1 ;
V_207 = F_131 ( V_3 , V_200 ) ;
V_205 = F_3 ( V_3 , V_203 ) ;
while ( V_205 && ! error ) {
T_8 V_216 , V_217 ;
if ( F_116 ( V_206 ) ) {
V_216 = V_207 ;
F_132 ( V_216 , V_206 ) ;
V_216 *= V_206 ;
V_217 = V_207 + V_205 ;
if ( ( V_160 = F_133 ( V_207 , V_206 ) ) )
V_217 += V_160 ;
if ( ( V_160 = F_133 ( V_217 , V_206 ) ) )
V_217 += V_206 - V_160 ;
} else {
V_216 = 0 ;
V_217 = V_205 ;
}
V_115 = F_134 ( T_8 , ( V_217 - V_216 ) , ( V_218 * V_38 ) ) ;
if ( F_116 ( V_210 ) ) {
V_214 = V_213 = V_115 ;
V_214 /= V_3 -> V_219 . V_220 ;
V_115 = F_135 ( V_3 , 0 ) ;
V_209 = V_221 ;
} else {
V_214 = 0 ;
V_115 = V_213 = F_135 ( V_3 , V_115 ) ;
V_209 = V_222 ;
}
V_34 = F_21 ( V_3 , V_223 ) ;
error = F_24 ( V_34 , V_115 ,
F_136 ( V_3 ) , V_214 ,
V_46 ,
V_224 ) ;
if ( error ) {
ASSERT ( error == V_127 || F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
break;
}
F_14 ( V_1 , V_48 ) ;
error = F_137 ( V_34 , V_1 , V_213 ,
0 , V_209 ) ;
if ( error )
goto V_63;
F_26 ( V_34 , V_1 , 0 ) ;
F_32 ( & V_56 , & V_208 ) ;
error = F_122 ( V_34 , V_1 , V_207 ,
V_205 , V_201 , & V_208 ,
0 , V_212 , & V_38 , & V_56 ) ;
if ( error ) {
goto V_62;
}
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error ) {
goto V_62;
}
error = F_28 ( V_34 , V_50 ) ;
F_16 ( V_1 , V_48 ) ;
if ( error ) {
break;
}
V_204 = V_212 -> V_17 ;
if ( V_38 == 0 ) {
error = F_8 ( V_127 ) ;
break;
}
V_207 += V_204 ;
V_205 -= V_204 ;
}
return error ;
V_62:
F_42 ( & V_56 ) ;
F_138 ( V_34 , V_1 , ( long ) V_213 , 0 , V_209 ) ;
V_63:
F_23 ( V_34 , V_50 | V_51 ) ;
F_16 ( V_1 , V_48 ) ;
return error ;
}
STATIC int
F_139 (
T_1 * V_1 ,
T_21 V_225 ,
T_21 V_226 )
{
T_3 V_39 ;
T_8 V_227 ;
T_21 V_228 ;
T_21 V_200 ;
T_5 * V_14 ;
T_2 * V_3 = V_1 -> V_4 ;
int V_229 ;
int error = 0 ;
if ( V_225 >= F_18 ( V_1 ) )
return 0 ;
if ( V_226 > F_18 ( V_1 ) )
V_226 = F_18 ( V_1 ) ;
V_14 = F_140 ( F_129 ( V_1 ) ?
V_3 -> V_230 : V_3 -> V_18 ,
F_7 ( V_3 -> V_219 . V_231 ) , 0 ) ;
if ( ! V_14 )
return F_8 ( V_19 ) ;
F_141 ( V_14 ) ;
for ( V_200 = V_225 ; V_200 <= V_226 ; V_200 = V_228 + 1 ) {
V_227 = F_131 ( V_3 , V_200 ) ;
V_229 = 1 ;
error = F_2 ( V_1 , V_227 , 1 , & V_39 , & V_229 , 0 ) ;
if ( error || V_229 < 1 )
break;
ASSERT ( V_39 . V_17 >= 1 ) ;
ASSERT ( V_39 . V_232 == V_227 ) ;
V_228 = F_5 ( V_3 , V_39 . V_232 + 1 ) - 1 ;
if ( V_228 > V_226 )
V_228 = V_226 ;
if ( V_39 . V_16 == V_41 )
continue;
ASSERT ( V_39 . V_16 != V_233 ) ;
if ( V_39 . V_234 == V_235 )
continue;
F_142 ( V_14 ) ;
F_143 ( V_14 ) ;
F_144 ( V_14 ) ;
F_145 ( V_14 , F_146 ( V_1 , V_39 . V_16 ) ) ;
F_147 ( V_3 , V_14 ) ;
error = F_148 ( V_14 ) ;
if ( error ) {
F_9 ( V_14 ,
L_5 ) ;
break;
}
memset ( V_14 -> V_22 +
( V_200 - F_5 ( V_3 , V_39 . V_232 ) ) ,
0 , V_228 - V_200 + 1 ) ;
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
T_21 V_200 ,
T_21 V_122 ,
int V_202 )
{
int V_53 ;
int V_54 ;
T_8 V_236 ;
int error ;
T_10 V_208 ;
T_11 V_56 ;
T_3 V_39 ;
T_21 V_237 ;
T_22 V_238 = 0 ;
T_2 * V_3 ;
int V_229 ;
T_13 V_115 ;
T_13 V_239 ;
int V_210 ;
T_8 V_207 ;
T_7 * V_34 ;
int V_240 = 1 ;
V_3 = V_1 -> V_4 ;
F_153 ( V_1 ) ;
error = F_20 ( V_1 , 0 ) ;
if ( error )
return error ;
error = 0 ;
if ( V_122 <= 0 )
return error ;
V_210 = F_129 ( V_1 ) ;
V_207 = F_3 ( V_3 , V_200 ) ;
V_236 = F_131 ( V_3 , V_200 + V_122 ) ;
if ( V_202 & V_241 )
V_240 = 0 ;
if ( V_240 ) {
F_14 ( V_1 , V_45 ) ;
F_154 ( F_56 ( V_1 ) ) ;
}
V_239 = F_155 ( T_13 , 1 << V_3 -> V_219 . V_242 , V_243 ) ;
V_237 = V_200 & ~ ( V_239 - 1 ) ;
if ( F_58 ( F_56 ( V_1 ) ) != 0 ) {
error = F_156 ( V_1 , V_237 , - 1 , V_244 ) ;
if ( error )
goto V_245;
}
if ( V_210 && ! F_157 ( & V_3 -> V_219 ) ) {
V_229 = 1 ;
error = F_2 ( V_1 , V_207 , 1 ,
& V_39 , & V_229 , 0 ) ;
if ( error )
goto V_245;
ASSERT ( V_229 == 0 || V_229 == 1 ) ;
if ( V_229 && V_39 . V_16 != V_41 ) {
T_4 V_246 ;
ASSERT ( V_39 . V_16 != V_233 ) ;
V_246 = V_39 . V_16 ;
V_238 = F_132 ( V_246 , V_3 -> V_219 . V_220 ) ;
if ( V_238 )
V_207 += V_3 -> V_219 . V_220 - V_238 ;
}
V_229 = 1 ;
error = F_2 ( V_1 , V_236 - 1 , 1 ,
& V_39 , & V_229 , 0 ) ;
if ( error )
goto V_245;
ASSERT ( V_229 == 0 || V_229 == 1 ) ;
if ( V_229 && V_39 . V_16 != V_41 ) {
ASSERT ( V_39 . V_16 != V_233 ) ;
V_238 ++ ;
if ( V_238 && ( V_238 != V_3 -> V_219 . V_220 ) )
V_236 -= V_238 ;
}
}
if ( ( V_54 = ( V_236 <= V_207 ) ) )
error = F_139 ( V_1 , V_200 , V_200 + V_122 - 1 ) ;
else {
if ( V_200 < F_5 ( V_3 , V_207 ) )
error = F_139 ( V_1 , V_200 ,
F_5 ( V_3 , V_207 ) - 1 ) ;
if ( ! error &&
F_5 ( V_3 , V_236 ) < V_200 + V_122 )
error = F_139 ( V_1 ,
F_5 ( V_3 , V_236 ) ,
V_200 + V_122 - 1 ) ;
}
V_115 = F_135 ( V_3 , 0 ) ;
while ( ! error && ! V_54 ) {
V_34 = F_21 ( V_3 , V_223 ) ;
V_34 -> V_247 |= V_248 ;
error = F_24 ( V_34 ,
V_115 ,
F_136 ( V_3 ) ,
0 ,
V_46 ,
V_224 ) ;
if ( error ) {
ASSERT ( error == V_127 || F_13 ( V_3 ) ) ;
F_23 ( V_34 , 0 ) ;
break;
}
F_14 ( V_1 , V_48 ) ;
error = F_88 ( V_34 , V_3 ,
V_1 -> V_249 , V_1 -> V_250 ,
V_115 , 0 , V_222 ) ;
if ( error )
goto V_63;
F_26 ( V_34 , V_1 , 0 ) ;
F_32 ( & V_56 , & V_208 ) ;
error = F_37 ( V_34 , V_1 , V_207 ,
V_236 - V_207 ,
0 , 2 , & V_208 , & V_56 , & V_54 ) ;
if ( error ) {
goto V_62;
}
error = F_38 ( & V_34 , & V_56 , & V_53 ) ;
if ( error ) {
goto V_62;
}
error = F_28 ( V_34 , V_50 ) ;
F_16 ( V_1 , V_48 ) ;
}
V_245:
if ( V_240 )
F_16 ( V_1 , V_45 ) ;
return error ;
V_62:
F_42 ( & V_56 ) ;
V_63:
F_23 ( V_34 , V_50 | V_51 ) ;
F_16 ( V_1 , V_240 ? ( V_48 | V_45 ) :
V_48 ) ;
return error ;
}
int
F_158 (
T_1 * V_1 ,
int V_251 ,
T_23 * V_252 ,
T_21 V_200 ,
int V_202 )
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
if ( ! F_50 ( V_1 -> V_6 . V_73 ) )
return F_8 ( V_215 ) ;
switch ( V_252 -> V_260 ) {
case 0 :
break;
case 1 :
V_252 -> V_261 += V_200 ;
break;
case 2 :
V_252 -> V_261 += F_18 ( V_1 ) ;
break;
default:
return F_8 ( V_215 ) ;
}
V_257 = V_252 -> V_262 > 0 ? V_252 -> V_262 - 1 : V_252 -> V_262 ;
if ( ( V_252 -> V_261 < 0 )
|| ( V_252 -> V_261 > F_19 ( V_3 ) )
|| ( V_252 -> V_261 + V_257 < 0 )
|| ( V_252 -> V_261 + V_257 > F_19 ( V_3 ) ) )
return F_8 ( V_215 ) ;
V_252 -> V_260 = 0 ;
V_256 = V_252 -> V_261 ;
V_254 = F_18 ( V_1 ) ;
V_255 = V_253 = 0 ;
V_259 = V_263 ;
switch ( V_251 ) {
case V_264 :
V_259 |= V_265 ;
F_159 ( V_1 , V_256 , V_256 + V_252 -> V_262 , 0 ) ;
case V_266 :
case V_267 :
error = F_127 ( V_1 , V_256 , V_252 -> V_262 ,
V_259 , V_202 ) ;
if ( error )
return error ;
V_255 = 1 ;
break;
case V_268 :
case V_269 :
if ( ( error = F_152 ( V_1 , V_256 , V_252 -> V_262 ,
V_202 ) ) )
return error ;
break;
case V_270 :
case V_271 :
case V_272 :
case V_273 :
F_14 ( V_1 , V_45 ) ;
if ( V_256 > V_254 ) {
error = F_127 ( V_1 , V_254 ,
V_256 - V_254 , 0 ,
V_202 | V_241 ) ;
if ( error ) {
F_16 ( V_1 , V_45 ) ;
break;
}
}
V_258 . V_274 = V_275 ;
V_258 . V_276 = V_256 ;
error = F_160 ( V_1 , & V_258 ,
V_202 | V_241 ) ;
F_16 ( V_1 , V_45 ) ;
if ( error )
return error ;
V_253 = 1 ;
break;
default:
ASSERT ( 0 ) ;
return F_8 ( V_215 ) ;
}
V_34 = F_21 ( V_3 , V_277 ) ;
if ( ( error = F_24 ( V_34 , 0 , F_161 ( V_3 ) ,
0 , 0 , 0 ) ) ) {
F_23 ( V_34 , 0 ) ;
return error ;
}
F_14 ( V_1 , V_48 ) ;
F_26 ( V_34 , V_1 , V_48 ) ;
if ( ( V_202 & V_278 ) == 0 ) {
V_1 -> V_6 . V_73 &= ~ V_279 ;
if ( V_1 -> V_6 . V_73 & V_280 )
V_1 -> V_6 . V_73 &= ~ V_281 ;
F_93 ( V_34 , V_1 , V_132 | V_133 ) ;
}
if ( V_255 )
V_1 -> V_6 . V_84 |= V_85 ;
else if ( V_253 )
V_1 -> V_6 . V_84 &= ~ V_85 ;
F_31 ( V_34 , V_1 , V_61 ) ;
if ( V_202 & V_282 )
F_96 ( V_34 ) ;
return F_28 ( V_34 , 0 ) ;
}
