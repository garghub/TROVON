void
F_1 (
T_1 * V_1 )
{
ASSERT ( F_2 ( & V_1 -> V_2 ) ) ;
F_3 ( & V_1 -> V_3 ) ;
F_4 ( V_4 , V_1 ) ;
F_5 ( V_5 ) ;
}
void
F_6 (
T_2 * V_6 ,
T_3 * V_7 )
{
T_4 * V_8 = V_6 -> V_9 ;
ASSERT ( V_7 -> V_10 ) ;
if ( V_8 -> V_11 && ! V_7 -> V_12 )
V_7 -> V_12 = F_7 ( V_8 -> V_11 ) ;
if ( V_8 -> V_13 && ! V_7 -> V_14 )
V_7 -> V_14 = F_7 ( V_8 -> V_13 ) ;
if ( V_8 -> V_15 && ! V_7 -> V_16 )
V_7 -> V_16 = F_7 ( V_8 -> V_15 ) ;
if ( V_8 -> V_17 && ! V_7 -> V_18 )
V_7 -> V_18 = F_7 ( V_8 -> V_17 ) ;
if ( V_8 -> V_19 && ! V_7 -> V_20 )
V_7 -> V_20 = F_7 ( V_8 -> V_19 ) ;
if ( V_8 -> V_21 && ! V_7 -> V_22 )
V_7 -> V_22 = F_7 ( V_8 -> V_21 ) ;
}
void
F_8 (
T_2 * V_6 ,
T_3 * V_7 )
{
ASSERT ( V_7 -> V_10 ) ;
#ifdef F_9
if ( V_7 -> V_14 )
ASSERT ( F_10 ( V_7 -> V_12 ) <=
F_10 ( V_7 -> V_14 ) ) ;
if ( V_7 -> V_18 )
ASSERT ( F_10 ( V_7 -> V_16 ) <=
F_10 ( V_7 -> V_18 ) ) ;
if ( V_7 -> V_22 )
ASSERT ( F_10 ( V_7 -> V_20 ) <=
F_10 ( V_7 -> V_22 ) ) ;
#endif
if ( ! V_7 -> V_23 ) {
if ( ( V_7 -> V_12 &&
( F_10 ( V_7 -> V_24 ) >
F_10 ( V_7 -> V_12 ) ) ) ||
( V_7 -> V_14 &&
( F_10 ( V_7 -> V_24 ) >
F_10 ( V_7 -> V_14 ) ) ) ) {
V_7 -> V_23 = F_11 ( F_12 () +
V_6 -> V_9 -> V_25 ) ;
} else {
V_7 -> V_26 = 0 ;
}
} else {
if ( ( ! V_7 -> V_12 ||
( F_10 ( V_7 -> V_24 ) <=
F_10 ( V_7 -> V_12 ) ) ) &&
( ! V_7 -> V_14 ||
( F_10 ( V_7 -> V_24 ) <=
F_10 ( V_7 -> V_14 ) ) ) ) {
V_7 -> V_23 = 0 ;
}
}
if ( ! V_7 -> V_27 ) {
if ( ( V_7 -> V_16 &&
( F_10 ( V_7 -> V_28 ) >
F_10 ( V_7 -> V_16 ) ) ) ||
( V_7 -> V_18 &&
( F_10 ( V_7 -> V_28 ) >
F_10 ( V_7 -> V_18 ) ) ) ) {
V_7 -> V_27 = F_11 ( F_12 () +
V_6 -> V_9 -> V_29 ) ;
} else {
V_7 -> V_30 = 0 ;
}
} else {
if ( ( ! V_7 -> V_16 ||
( F_10 ( V_7 -> V_28 ) <=
F_10 ( V_7 -> V_16 ) ) ) &&
( ! V_7 -> V_18 ||
( F_10 ( V_7 -> V_28 ) <=
F_10 ( V_7 -> V_18 ) ) ) ) {
V_7 -> V_27 = 0 ;
}
}
if ( ! V_7 -> V_31 ) {
if ( ( V_7 -> V_20 &&
( F_10 ( V_7 -> V_32 ) >
F_10 ( V_7 -> V_20 ) ) ) ||
( V_7 -> V_22 &&
( F_10 ( V_7 -> V_32 ) >
F_10 ( V_7 -> V_22 ) ) ) ) {
V_7 -> V_31 = F_11 ( F_12 () +
V_6 -> V_9 -> V_33 ) ;
} else {
V_7 -> V_34 = 0 ;
}
} else {
if ( ( ! V_7 -> V_20 ||
( F_10 ( V_7 -> V_32 ) <=
F_10 ( V_7 -> V_20 ) ) ) &&
( ! V_7 -> V_22 ||
( F_10 ( V_7 -> V_32 ) <=
F_10 ( V_7 -> V_22 ) ) ) ) {
V_7 -> V_31 = 0 ;
}
}
}
STATIC void
F_13 (
T_5 * V_35 ,
T_2 * V_6 ,
T_6 V_36 ,
T_7 type ,
T_8 * V_37 )
{
struct V_38 * V_8 = V_6 -> V_9 ;
T_9 * V_7 ;
int V_39 , V_40 ;
ASSERT ( V_35 ) ;
ASSERT ( F_14 ( V_37 ) ) ;
V_7 = V_37 -> V_41 ;
V_39 = V_36 - ( V_36 % V_8 -> V_42 ) ;
ASSERT ( V_39 >= 0 ) ;
memset ( V_7 , 0 , F_15 ( V_8 -> V_43 ) ) ;
for ( V_40 = 0 ; V_40 < V_8 -> V_42 ; V_40 ++ , V_7 ++ , V_39 ++ ) {
V_7 -> V_44 . V_45 = F_16 ( V_46 ) ;
V_7 -> V_44 . V_47 = V_48 ;
V_7 -> V_44 . V_10 = F_11 ( V_39 ) ;
V_7 -> V_44 . V_49 = type ;
}
F_17 ( V_35 , V_37 ,
( type & V_50 ? V_51 :
( ( type & V_52 ) ? V_53 :
V_54 ) ) ) ;
F_18 ( V_35 , V_37 , 0 , F_15 ( V_8 -> V_43 ) - 1 ) ;
}
static void
F_19 (
struct V_55 * V_37 )
{
struct V_56 * V_6 = V_37 -> V_57 -> V_58 ;
struct V_59 * V_7 = (struct V_59 * ) V_37 -> V_41 ;
struct V_60 * V_61 ;
T_6 V_36 = 0 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_6 -> V_9 -> V_42 ; V_40 ++ ) {
int error ;
V_61 = & V_7 [ V_40 ] . V_44 ;
if ( V_40 == 0 )
V_36 = F_20 ( V_61 -> V_10 ) ;
error = F_21 ( V_6 , V_61 , V_36 + V_40 , 0 , V_62 ,
L_1 ) ;
if ( error ) {
F_22 ( V_63 , V_64 , V_6 , V_7 ) ;
F_23 ( V_37 , V_65 ) ;
break;
}
}
}
static void
F_24 (
struct V_55 * V_37 )
{
F_19 ( V_37 ) ;
}
void
F_25 (
struct V_55 * V_37 )
{
F_19 ( V_37 ) ;
}
STATIC int
F_26 (
T_5 * * V_66 ,
T_2 * V_6 ,
T_1 * V_1 ,
T_10 * V_67 ,
T_11 V_68 ,
T_8 * * V_69 )
{
T_12 V_70 ;
T_13 V_71 ;
T_14 V_72 ;
int V_73 , error , V_74 ;
T_8 * V_37 ;
T_5 * V_35 = * V_66 ;
ASSERT ( V_35 != NULL ) ;
F_27 ( V_1 ) ;
F_28 ( & V_71 , & V_70 ) ;
F_29 ( V_67 , V_75 ) ;
if ( ! F_30 ( V_1 -> V_76 , V_1 -> V_77 ) ) {
F_31 ( V_67 , V_75 ) ;
return ( V_78 ) ;
}
F_32 ( V_35 , V_67 , V_75 ) ;
V_73 = 1 ;
error = F_33 ( V_35 , V_67 , V_68 ,
V_79 , V_80 ,
& V_70 , F_34 ( V_6 ) ,
& V_72 , & V_73 , & V_71 ) ;
if ( error )
goto V_81;
ASSERT ( V_72 . V_82 == V_79 ) ;
ASSERT ( V_73 == 1 ) ;
ASSERT ( ( V_72 . V_83 != V_84 ) &&
( V_72 . V_83 != V_85 ) ) ;
V_1 -> V_86 = F_35 ( V_6 , V_72 . V_83 ) ;
V_37 = F_36 ( V_35 , V_6 -> V_87 ,
V_1 -> V_86 ,
V_6 -> V_9 -> V_43 ,
0 ) ;
error = F_37 ( V_37 ) ;
if ( error )
goto V_88;
V_37 -> V_89 = & V_90 ;
F_13 ( V_35 , V_6 , F_20 ( V_1 -> V_91 . V_10 ) ,
V_1 -> V_77 & V_92 , V_37 ) ;
F_38 ( V_35 , V_37 ) ;
if ( ( error = F_39 ( V_66 , & V_71 , & V_74 ) ) ) {
goto V_88;
}
if ( V_74 ) {
V_35 = * V_66 ;
F_40 ( V_35 , V_37 ) ;
} else {
F_41 ( V_35 , V_37 ) ;
}
* V_69 = V_37 ;
return 0 ;
V_88:
F_42 ( & V_71 ) ;
V_81:
F_31 ( V_67 , V_75 ) ;
return ( error ) ;
}
STATIC int
F_43 (
struct V_56 * V_6 ,
struct V_93 * V_35 ,
struct V_94 * V_1 ,
T_6 V_95 ,
struct V_55 * * V_96 )
{
int error ;
struct V_60 * V_61 ;
struct V_59 * V_7 ;
int V_40 ;
error = F_44 ( V_6 , V_35 , V_6 -> V_87 , V_1 -> V_86 ,
V_6 -> V_9 -> V_43 ,
0 , V_96 , NULL ) ;
if ( error ) {
ASSERT ( * V_96 == NULL ) ;
return F_45 ( error ) ;
}
( * V_96 ) -> V_89 = & V_90 ;
ASSERT ( F_14 ( * V_96 ) ) ;
V_7 = (struct V_59 * ) ( * V_96 ) -> V_41 ;
for ( V_40 = 0 ; V_40 < V_6 -> V_9 -> V_42 ; V_40 ++ ) {
V_61 = & V_7 [ V_40 ] . V_44 ;
error = F_21 ( V_6 , V_61 , V_95 + V_40 ,
V_1 -> V_77 & V_92 ,
V_97 , L_2 ) ;
if ( error ) {
F_46 ( V_35 , * V_96 ) ;
return F_45 ( V_98 ) ;
}
}
return 0 ;
}
STATIC int
F_47 (
T_5 * * V_66 ,
T_1 * V_1 ,
T_3 * * V_99 ,
T_8 * * V_69 ,
T_7 V_100 )
{
T_14 V_72 ;
int V_73 = 1 , error ;
T_8 * V_37 ;
T_10 * V_67 = F_48 ( V_1 ) ;
T_2 * V_6 = V_1 -> V_76 ;
T_6 V_36 = F_20 ( V_1 -> V_91 . V_10 ) ;
T_5 * V_35 = ( V_66 ? * V_66 : NULL ) ;
V_1 -> V_101 = ( T_11 ) V_36 / V_6 -> V_9 -> V_42 ;
F_29 ( V_67 , V_102 ) ;
if ( ! F_30 ( V_1 -> V_76 , V_1 -> V_77 ) ) {
F_31 ( V_67 , V_102 ) ;
return V_78 ;
}
error = F_49 ( V_67 , V_1 -> V_101 ,
V_79 , & V_72 , & V_73 , 0 ) ;
F_31 ( V_67 , V_102 ) ;
if ( error )
return error ;
ASSERT ( V_73 == 1 ) ;
ASSERT ( V_72 . V_82 == 1 ) ;
V_1 -> V_103 = ( V_36 % V_6 -> V_9 -> V_42 ) *
sizeof( T_9 ) ;
ASSERT ( V_72 . V_83 != V_84 ) ;
if ( V_72 . V_83 == V_85 ) {
if ( ! ( V_100 & V_104 ) )
return V_105 ;
ASSERT ( V_35 ) ;
error = F_26 ( V_66 , V_6 , V_1 , V_67 ,
V_1 -> V_101 , & V_37 ) ;
if ( error )
return error ;
V_35 = * V_66 ;
} else {
F_50 ( V_1 ) ;
V_1 -> V_86 = F_35 ( V_6 , V_72 . V_83 ) ;
error = F_44 ( V_6 , V_35 , V_6 -> V_87 ,
V_1 -> V_86 ,
V_6 -> V_9 -> V_43 ,
0 , & V_37 , & V_90 ) ;
if ( error == V_65 && ( V_100 & V_97 ) ) {
T_6 V_95 = ( T_6 ) V_72 . V_106 *
V_6 -> V_9 -> V_42 ;
ASSERT ( V_37 == NULL ) ;
error = F_43 ( V_6 , V_35 , V_1 , V_95 , & V_37 ) ;
}
if ( error ) {
ASSERT ( V_37 == NULL ) ;
return F_45 ( error ) ;
}
}
ASSERT ( F_14 ( V_37 ) ) ;
* V_69 = V_37 ;
* V_99 = V_37 -> V_41 + V_1 -> V_103 ;
return ( 0 ) ;
}
int
F_51 (
struct V_56 * V_6 ,
T_6 V_36 ,
T_7 type ,
T_7 V_100 ,
struct V_94 * * V_107 )
{
struct V_94 * V_1 ;
struct V_60 * V_108 ;
struct V_55 * V_37 ;
struct V_93 * V_35 = NULL ;
int error ;
int V_109 = 0 ;
V_1 = F_52 ( V_4 , V_110 ) ;
V_1 -> V_77 = type ;
V_1 -> V_91 . V_10 = F_11 ( V_36 ) ;
V_1 -> V_76 = V_6 ;
F_53 ( & V_1 -> V_2 ) ;
F_54 ( & V_1 -> V_3 ) ;
F_55 ( & V_1 -> V_111 ) ;
F_56 ( & V_1 -> V_112 ) ;
F_57 ( & V_1 -> V_112 ) ;
if ( ! ( type & V_50 ) )
F_58 ( & V_1 -> V_3 , & V_113 ) ;
F_59 ( V_5 ) ;
F_60 ( V_1 ) ;
if ( V_100 & V_104 ) {
V_35 = F_61 ( V_6 , V_114 ) ;
error = F_62 ( V_35 , F_34 ( V_6 ) ,
F_63 ( V_6 ) , 0 ,
V_115 ,
V_116 ) ;
if ( error )
goto V_88;
V_109 = V_117 ;
}
error = F_47 ( & V_35 , V_1 , & V_108 , & V_37 , V_100 ) ;
if ( error ) {
F_64 ( V_1 ) ;
V_109 |= V_118 ;
goto V_88;
}
memcpy ( & V_1 -> V_91 , V_108 , sizeof( T_3 ) ) ;
F_65 ( V_1 ) ;
V_1 -> V_119 = F_10 ( V_108 -> V_24 ) ;
V_1 -> V_120 = F_10 ( V_108 -> V_28 ) ;
V_1 -> V_121 = F_10 ( V_108 -> V_32 ) ;
F_66 ( V_37 , V_122 ) ;
ASSERT ( F_14 ( V_37 ) ) ;
F_46 ( V_35 , V_37 ) ;
if ( V_35 ) {
error = F_67 ( V_35 , V_117 ) ;
if ( error )
goto V_81;
}
* V_107 = V_1 ;
return error ;
V_88:
if ( V_35 )
F_68 ( V_35 , V_109 ) ;
V_81:
F_1 ( V_1 ) ;
* V_107 = NULL ;
return error ;
}
int
F_69 (
T_2 * V_6 ,
T_10 * V_123 ,
T_6 V_36 ,
T_7 type ,
T_7 V_100 ,
T_1 * * V_107 )
{
struct V_38 * V_124 = V_6 -> V_9 ;
struct V_125 * V_126 = F_70 ( V_124 , type ) ;
struct V_94 * V_1 ;
int error ;
ASSERT ( F_71 ( V_6 ) ) ;
if ( ( ! F_72 ( V_6 ) && type == V_50 ) ||
( ! F_73 ( V_6 ) && type == V_52 ) ||
( ! F_74 ( V_6 ) && type == V_127 ) ) {
return ( V_78 ) ;
}
#ifdef F_9
if ( V_128 ) {
if ( ( V_129 == V_6 -> V_87 ) &&
( V_130 ++ % V_131 ) == 0 ) {
F_75 ( V_6 , L_3 ) ;
return ( V_98 ) ;
}
}
ASSERT ( type == V_50 ||
type == V_52 ||
type == V_127 ) ;
if ( V_123 ) {
ASSERT ( F_76 ( V_123 , V_75 ) ) ;
ASSERT ( F_77 ( V_123 , type ) == NULL ) ;
}
#endif
V_132:
F_78 ( & V_124 -> V_133 ) ;
V_1 = F_79 ( V_126 , V_36 ) ;
if ( V_1 ) {
F_80 ( V_1 ) ;
if ( V_1 -> V_77 & V_134 ) {
F_81 ( V_1 ) ;
F_82 ( & V_124 -> V_133 ) ;
F_83 ( V_1 ) ;
F_84 ( 1 ) ;
goto V_132;
}
V_1 -> V_135 ++ ;
F_82 ( & V_124 -> V_133 ) ;
F_85 ( V_1 ) ;
F_59 ( V_136 ) ;
* V_107 = V_1 ;
return 0 ;
}
F_82 ( & V_124 -> V_133 ) ;
F_59 ( V_137 ) ;
if ( V_123 )
F_31 ( V_123 , V_75 ) ;
error = F_51 ( V_6 , V_36 , type , V_100 , & V_1 ) ;
if ( V_123 )
F_29 ( V_123 , V_75 ) ;
if ( error )
return error ;
if ( V_123 ) {
if ( F_30 ( V_6 , type ) ) {
struct V_94 * V_138 ;
V_138 = F_77 ( V_123 , type ) ;
if ( V_138 ) {
F_1 ( V_1 ) ;
V_1 = V_138 ;
F_80 ( V_1 ) ;
goto V_139;
}
} else {
F_1 ( V_1 ) ;
return F_45 ( V_78 ) ;
}
}
F_78 ( & V_124 -> V_133 ) ;
error = - F_86 ( V_126 , V_36 , V_1 ) ;
if ( F_87 ( error ) ) {
F_88 ( error != V_140 ) ;
F_82 ( & V_124 -> V_133 ) ;
F_89 ( V_1 ) ;
F_1 ( V_1 ) ;
F_59 ( V_141 ) ;
goto V_132;
}
F_80 ( V_1 ) ;
V_1 -> V_135 = 1 ;
V_124 -> V_142 ++ ;
F_82 ( & V_124 -> V_133 ) ;
V_139:
ASSERT ( ( V_123 == NULL ) || F_76 ( V_123 , V_75 ) ) ;
F_90 ( V_1 ) ;
* V_107 = V_1 ;
return ( 0 ) ;
}
STATIC void
F_91 (
struct V_94 * V_1 )
{
struct V_38 * V_124 = V_1 -> V_76 -> V_9 ;
struct V_94 * V_143 ;
F_92 ( V_1 ) ;
F_78 ( & V_124 -> V_144 ) ;
if ( F_2 ( & V_1 -> V_2 ) ) {
F_93 ( & V_1 -> V_2 , & V_124 -> V_145 ) ;
V_124 -> V_146 ++ ;
F_59 ( V_147 ) ;
}
F_82 ( & V_124 -> V_144 ) ;
V_143 = V_1 -> V_148 ;
if ( V_143 ) {
F_80 ( V_143 ) ;
V_1 -> V_148 = NULL ;
}
F_81 ( V_1 ) ;
if ( V_143 )
F_94 ( V_143 ) ;
}
void
F_94 (
struct V_94 * V_1 )
{
ASSERT ( V_1 -> V_135 > 0 ) ;
ASSERT ( F_95 ( V_1 ) ) ;
F_96 ( V_1 ) ;
if ( -- V_1 -> V_135 > 0 )
F_81 ( V_1 ) ;
else
F_91 ( V_1 ) ;
}
void
F_97 (
T_1 * V_1 )
{
if ( ! V_1 )
return;
F_98 ( V_1 ) ;
F_80 ( V_1 ) ;
F_94 ( V_1 ) ;
}
STATIC void
F_99 (
struct V_55 * V_37 ,
struct V_149 * V_150 )
{
T_15 * V_151 = (struct V_152 * ) V_150 ;
T_1 * V_1 = V_151 -> V_153 ;
struct V_154 * V_155 = V_150 -> V_156 ;
if ( ( V_150 -> V_157 & V_158 ) &&
V_150 -> V_159 == V_151 -> V_160 ) {
F_100 ( & V_155 -> V_161 ) ;
if ( V_150 -> V_159 == V_151 -> V_160 )
F_101 ( V_155 , V_150 , V_162 ) ;
else
F_102 ( & V_155 -> V_161 ) ;
}
F_103 ( V_1 ) ;
}
int
F_104 (
struct V_94 * V_1 ,
struct V_55 * * V_96 )
{
struct V_56 * V_6 = V_1 -> V_76 ;
struct V_55 * V_37 ;
struct V_60 * V_108 ;
int error ;
ASSERT ( F_95 ( V_1 ) ) ;
ASSERT ( ! F_105 ( & V_1 -> V_112 ) ) ;
F_106 ( V_1 ) ;
* V_96 = NULL ;
F_107 ( V_1 ) ;
if ( F_108 ( V_6 ) ) {
struct V_149 * V_150 = & V_1 -> V_163 . V_164 ;
V_1 -> V_77 &= ~ V_165 ;
F_100 ( & V_6 -> V_166 -> V_161 ) ;
if ( V_150 -> V_157 & V_158 )
F_101 ( V_6 -> V_166 , V_150 ,
V_162 ) ;
else
F_102 ( & V_6 -> V_166 -> V_161 ) ;
error = F_45 ( V_98 ) ;
goto V_167;
}
error = F_44 ( V_6 , NULL , V_6 -> V_87 , V_1 -> V_86 ,
V_6 -> V_9 -> V_43 , 0 , & V_37 , NULL ) ;
if ( error )
goto V_167;
V_108 = V_37 -> V_41 + V_1 -> V_103 ;
error = F_21 ( V_6 , & V_1 -> V_91 , F_20 ( V_108 -> V_10 ) , 0 ,
V_62 , L_4 ) ;
if ( error ) {
F_109 ( V_37 ) ;
F_103 ( V_1 ) ;
F_110 ( V_6 , V_162 ) ;
return F_45 ( V_98 ) ;
}
memcpy ( V_108 , & V_1 -> V_91 , sizeof( T_3 ) ) ;
V_1 -> V_77 &= ~ V_165 ;
F_111 ( V_6 -> V_166 , & V_1 -> V_163 . V_160 ,
& V_1 -> V_163 . V_164 . V_159 ) ;
F_112 ( V_37 , F_99 ,
& V_1 -> V_163 . V_164 ) ;
if ( F_113 ( V_37 ) ) {
F_114 ( V_1 ) ;
F_115 ( V_6 , 0 ) ;
}
F_116 ( V_1 ) ;
* V_96 = V_37 ;
return 0 ;
V_167:
F_103 ( V_1 ) ;
return F_45 ( V_98 ) ;
}
void
F_117 (
T_1 * V_168 ,
T_1 * V_169 )
{
if ( V_168 && V_169 ) {
ASSERT ( V_168 != V_169 ) ;
if ( F_20 ( V_168 -> V_91 . V_10 ) >
F_20 ( V_169 -> V_91 . V_10 ) ) {
F_78 ( & V_169 -> V_3 ) ;
F_118 ( & V_168 -> V_3 , V_170 ) ;
} else {
F_78 ( & V_168 -> V_3 ) ;
F_118 ( & V_169 -> V_3 , V_170 ) ;
}
} else if ( V_168 ) {
F_78 ( & V_168 -> V_3 ) ;
} else if ( V_169 ) {
F_78 ( & V_169 -> V_3 ) ;
}
}
int T_16
F_119 ( void )
{
V_4 =
F_120 ( sizeof( struct V_94 ) , L_5 ) ;
if ( ! V_4 )
goto V_171;
V_172 =
F_120 ( sizeof( struct V_173 ) , L_6 ) ;
if ( ! V_172 )
goto V_174;
return 0 ;
V_174:
F_121 ( V_4 ) ;
V_171:
return - V_175 ;
}
void
F_122 ( void )
{
F_121 ( V_172 ) ;
F_121 ( V_4 ) ;
}
