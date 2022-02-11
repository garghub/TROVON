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
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = & V_9 -> V_15 ;
int V_16 = 0 ;
ASSERT ( V_14 -> V_17 ) ;
if ( V_11 -> V_18 && ! V_14 -> V_19 ) {
V_14 -> V_19 = F_7 ( V_11 -> V_18 ) ;
V_16 = 1 ;
}
if ( V_11 -> V_20 && ! V_14 -> V_21 ) {
V_14 -> V_21 = F_7 ( V_11 -> V_20 ) ;
V_16 = 1 ;
}
if ( V_11 -> V_22 && ! V_14 -> V_23 )
V_14 -> V_23 = F_7 ( V_11 -> V_22 ) ;
if ( V_11 -> V_24 && ! V_14 -> V_25 )
V_14 -> V_25 = F_7 ( V_11 -> V_24 ) ;
if ( V_11 -> V_26 && ! V_14 -> V_27 )
V_14 -> V_27 = F_7 ( V_11 -> V_26 ) ;
if ( V_11 -> V_28 && ! V_14 -> V_29 )
V_14 -> V_29 = F_7 ( V_11 -> V_28 ) ;
if ( V_16 )
F_8 ( V_9 ) ;
}
void
F_9 (
T_2 * V_7 ,
T_3 * V_14 )
{
ASSERT ( V_14 -> V_17 ) ;
#ifdef F_10
if ( V_14 -> V_21 )
ASSERT ( F_11 ( V_14 -> V_19 ) <=
F_11 ( V_14 -> V_21 ) ) ;
if ( V_14 -> V_25 )
ASSERT ( F_11 ( V_14 -> V_23 ) <=
F_11 ( V_14 -> V_25 ) ) ;
if ( V_14 -> V_29 )
ASSERT ( F_11 ( V_14 -> V_27 ) <=
F_11 ( V_14 -> V_29 ) ) ;
#endif
if ( ! V_14 -> V_30 ) {
if ( ( V_14 -> V_19 &&
( F_11 ( V_14 -> V_31 ) >
F_11 ( V_14 -> V_19 ) ) ) ||
( V_14 -> V_21 &&
( F_11 ( V_14 -> V_31 ) >
F_11 ( V_14 -> V_21 ) ) ) ) {
V_14 -> V_30 = F_12 ( F_13 () +
V_7 -> V_12 -> V_32 ) ;
} else {
V_14 -> V_33 = 0 ;
}
} else {
if ( ( ! V_14 -> V_19 ||
( F_11 ( V_14 -> V_31 ) <=
F_11 ( V_14 -> V_19 ) ) ) &&
( ! V_14 -> V_21 ||
( F_11 ( V_14 -> V_31 ) <=
F_11 ( V_14 -> V_21 ) ) ) ) {
V_14 -> V_30 = 0 ;
}
}
if ( ! V_14 -> V_34 ) {
if ( ( V_14 -> V_23 &&
( F_11 ( V_14 -> V_35 ) >
F_11 ( V_14 -> V_23 ) ) ) ||
( V_14 -> V_25 &&
( F_11 ( V_14 -> V_35 ) >
F_11 ( V_14 -> V_25 ) ) ) ) {
V_14 -> V_34 = F_12 ( F_13 () +
V_7 -> V_12 -> V_36 ) ;
} else {
V_14 -> V_37 = 0 ;
}
} else {
if ( ( ! V_14 -> V_23 ||
( F_11 ( V_14 -> V_35 ) <=
F_11 ( V_14 -> V_23 ) ) ) &&
( ! V_14 -> V_25 ||
( F_11 ( V_14 -> V_35 ) <=
F_11 ( V_14 -> V_25 ) ) ) ) {
V_14 -> V_34 = 0 ;
}
}
if ( ! V_14 -> V_38 ) {
if ( ( V_14 -> V_27 &&
( F_11 ( V_14 -> V_39 ) >
F_11 ( V_14 -> V_27 ) ) ) ||
( V_14 -> V_29 &&
( F_11 ( V_14 -> V_39 ) >
F_11 ( V_14 -> V_29 ) ) ) ) {
V_14 -> V_38 = F_12 ( F_13 () +
V_7 -> V_12 -> V_40 ) ;
} else {
V_14 -> V_41 = 0 ;
}
} else {
if ( ( ! V_14 -> V_27 ||
( F_11 ( V_14 -> V_39 ) <=
F_11 ( V_14 -> V_27 ) ) ) &&
( ! V_14 -> V_29 ||
( F_11 ( V_14 -> V_39 ) <=
F_11 ( V_14 -> V_29 ) ) ) ) {
V_14 -> V_38 = 0 ;
}
}
}
STATIC void
F_14 (
T_4 * V_42 ,
T_2 * V_7 ,
T_5 V_43 ,
T_6 type ,
T_7 * V_44 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
T_8 * V_14 ;
int V_45 , V_46 ;
ASSERT ( V_42 ) ;
ASSERT ( F_15 ( V_44 ) ) ;
V_14 = V_44 -> V_47 ;
V_45 = V_43 - ( V_43 % V_11 -> V_48 ) ;
ASSERT ( V_45 >= 0 ) ;
memset ( V_14 , 0 , F_16 ( V_11 -> V_49 ) ) ;
for ( V_46 = 0 ; V_46 < V_11 -> V_48 ; V_46 ++ , V_14 ++ , V_45 ++ ) {
V_14 -> V_50 . V_51 = F_17 ( V_52 ) ;
V_14 -> V_50 . V_53 = V_54 ;
V_14 -> V_50 . V_17 = F_12 ( V_45 ) ;
V_14 -> V_50 . V_55 = type ;
if ( F_18 ( & V_7 -> V_56 ) ) {
F_19 ( & V_14 -> V_57 , & V_7 -> V_56 . V_58 ) ;
F_20 ( ( char * ) V_14 , sizeof( struct V_59 ) ,
V_60 ) ;
}
}
F_21 ( V_42 , V_44 ,
( type & V_61 ? V_62 :
( ( type & V_63 ) ? V_64 :
V_65 ) ) ) ;
F_22 ( V_42 , V_44 , 0 , F_16 ( V_11 -> V_49 ) - 1 ) ;
}
void
F_8 ( struct V_8 * V_1 )
{
T_9 V_66 ;
V_1 -> V_67 = F_11 ( V_1 -> V_15 . V_21 ) ;
V_1 -> V_68 = F_11 ( V_1 -> V_15 . V_19 ) ;
if ( ! V_1 -> V_68 ) {
V_1 -> V_68 = V_1 -> V_67 ;
F_23 ( V_1 -> V_68 , 100 ) ;
V_1 -> V_68 *= 95 ;
}
V_66 = V_1 -> V_67 ;
F_23 ( V_66 , 100 ) ;
V_1 -> V_69 [ V_70 ] = V_66 ;
V_1 -> V_69 [ V_71 ] = V_66 * 3 ;
V_1 -> V_69 [ V_72 ] = V_66 * 5 ;
}
STATIC bool
F_24 (
struct V_6 * V_7 ,
struct V_73 * V_44 )
{
struct V_59 * V_14 = (struct V_59 * ) V_44 -> V_47 ;
int V_74 ;
int V_46 ;
if ( ! F_18 ( & V_7 -> V_56 ) )
return true ;
if ( V_7 -> V_12 )
V_74 = V_7 -> V_12 -> V_48 ;
else
V_74 = F_25 ( V_7 ,
F_26 ( V_7 , V_44 -> V_75 ) ) ;
for ( V_46 = 0 ; V_46 < V_74 ; V_46 ++ , V_14 ++ ) {
if ( ! F_27 ( ( char * ) V_14 , sizeof( struct V_59 ) ,
V_60 ) )
return false ;
if ( ! F_28 ( & V_14 -> V_57 , & V_7 -> V_56 . V_58 ) )
return false ;
}
return true ;
}
STATIC bool
F_29 (
struct V_6 * V_7 ,
struct V_73 * V_44 )
{
struct V_59 * V_14 = (struct V_59 * ) V_44 -> V_47 ;
T_5 V_43 = 0 ;
int V_74 ;
int V_46 ;
if ( V_7 -> V_12 )
V_74 = V_7 -> V_12 -> V_48 ;
else
V_74 = F_25 ( V_7 , V_44 -> V_75 ) ;
for ( V_46 = 0 ; V_46 < V_74 ; V_46 ++ ) {
struct V_13 * V_76 ;
int error ;
V_76 = & V_14 [ V_46 ] . V_50 ;
if ( V_46 == 0 )
V_43 = F_30 ( V_76 -> V_17 ) ;
error = F_31 ( V_7 , V_76 , V_43 + V_46 , 0 , V_77 ,
L_1 ) ;
if ( error )
return false ;
}
return true ;
}
static void
F_32 (
struct V_73 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_78 -> V_79 ;
if ( ! F_24 ( V_7 , V_44 ) || ! F_29 ( V_7 , V_44 ) ) {
F_33 ( V_80 , V_81 , V_7 , V_44 -> V_47 ) ;
F_34 ( V_44 , V_82 ) ;
}
}
void
F_35 (
struct V_73 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_78 -> V_79 ;
if ( ! F_29 ( V_7 , V_44 ) ) {
F_33 ( V_80 , V_81 , V_7 , V_44 -> V_47 ) ;
F_34 ( V_44 , V_82 ) ;
return;
}
}
STATIC int
F_36 (
T_4 * * V_83 ,
T_2 * V_7 ,
T_1 * V_1 ,
T_10 * V_84 ,
T_11 V_85 ,
T_7 * * V_86 )
{
T_12 V_87 ;
T_13 V_88 ;
T_14 V_89 ;
int V_90 , error , V_91 ;
T_7 * V_44 ;
T_4 * V_42 = * V_83 ;
ASSERT ( V_42 != NULL ) ;
F_37 ( V_1 ) ;
F_38 ( & V_88 , & V_87 ) ;
F_39 ( V_84 , V_92 ) ;
if ( ! F_40 ( V_1 -> V_93 , V_1 -> V_94 ) ) {
F_41 ( V_84 , V_92 ) ;
return ( V_95 ) ;
}
F_42 ( V_42 , V_84 , V_92 ) ;
V_90 = 1 ;
error = F_43 ( V_42 , V_84 , V_85 ,
V_96 , V_97 ,
& V_87 , F_44 ( V_7 ) ,
& V_89 , & V_90 , & V_88 ) ;
if ( error )
goto V_98;
ASSERT ( V_89 . V_99 == V_96 ) ;
ASSERT ( V_90 == 1 ) ;
ASSERT ( ( V_89 . V_100 != V_101 ) &&
( V_89 . V_100 != V_102 ) ) ;
V_1 -> V_103 = F_45 ( V_7 , V_89 . V_100 ) ;
V_44 = F_46 ( V_42 , V_7 -> V_104 ,
V_1 -> V_103 ,
V_7 -> V_12 -> V_49 ,
0 ) ;
error = F_47 ( V_44 ) ;
if ( error )
goto V_105;
V_44 -> V_106 = & V_107 ;
F_14 ( V_42 , V_7 , F_30 ( V_1 -> V_15 . V_17 ) ,
V_1 -> V_94 & V_108 , V_44 ) ;
F_48 ( V_42 , V_44 ) ;
if ( ( error = F_49 ( V_83 , & V_88 , & V_91 ) ) ) {
goto V_105;
}
if ( V_91 ) {
V_42 = * V_83 ;
F_50 ( V_42 , V_44 ) ;
} else {
F_51 ( V_42 , V_44 ) ;
}
* V_86 = V_44 ;
return 0 ;
V_105:
F_52 ( & V_88 ) ;
V_98:
F_41 ( V_84 , V_92 ) ;
return ( error ) ;
}
STATIC int
F_53 (
struct V_6 * V_7 ,
struct V_109 * V_42 ,
struct V_8 * V_1 ,
T_5 V_110 ,
struct V_73 * * V_111 )
{
int error ;
struct V_13 * V_76 ;
struct V_59 * V_14 ;
int V_46 ;
error = F_54 ( V_7 , V_42 , V_7 -> V_104 , V_1 -> V_103 ,
V_7 -> V_12 -> V_49 ,
0 , V_111 , NULL ) ;
if ( error ) {
ASSERT ( * V_111 == NULL ) ;
return F_55 ( error ) ;
}
( * V_111 ) -> V_106 = & V_107 ;
ASSERT ( F_15 ( * V_111 ) ) ;
V_14 = (struct V_59 * ) ( * V_111 ) -> V_47 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_12 -> V_48 ; V_46 ++ ) {
V_76 = & V_14 [ V_46 ] . V_50 ;
error = F_31 ( V_7 , V_76 , V_110 + V_46 ,
V_1 -> V_94 & V_108 ,
V_112 , L_2 ) ;
if ( error ) {
F_56 ( V_42 , * V_111 ) ;
return F_55 ( V_113 ) ;
}
}
return 0 ;
}
STATIC int
F_57 (
T_4 * * V_83 ,
T_1 * V_1 ,
T_3 * * V_114 ,
T_7 * * V_86 ,
T_6 V_115 )
{
struct V_116 V_89 ;
int V_90 = 1 , error ;
struct V_73 * V_44 ;
struct V_117 * V_84 = F_58 ( V_1 ) ;
struct V_6 * V_7 = V_1 -> V_93 ;
T_5 V_43 = F_30 ( V_1 -> V_15 . V_17 ) ;
struct V_109 * V_42 = ( V_83 ? * V_83 : NULL ) ;
V_1 -> V_118 = ( T_11 ) V_43 / V_7 -> V_12 -> V_48 ;
F_39 ( V_84 , V_119 ) ;
if ( ! F_40 ( V_1 -> V_93 , V_1 -> V_94 ) ) {
F_41 ( V_84 , V_119 ) ;
return V_95 ;
}
error = F_59 ( V_84 , V_1 -> V_118 ,
V_96 , & V_89 , & V_90 , 0 ) ;
F_41 ( V_84 , V_119 ) ;
if ( error )
return error ;
ASSERT ( V_90 == 1 ) ;
ASSERT ( V_89 . V_99 == 1 ) ;
V_1 -> V_120 = ( V_43 % V_7 -> V_12 -> V_48 ) *
sizeof( T_8 ) ;
ASSERT ( V_89 . V_100 != V_101 ) ;
if ( V_89 . V_100 == V_102 ) {
if ( ! ( V_115 & V_121 ) )
return V_122 ;
ASSERT ( V_42 ) ;
error = F_36 ( V_83 , V_7 , V_1 , V_84 ,
V_1 -> V_118 , & V_44 ) ;
if ( error )
return error ;
V_42 = * V_83 ;
} else {
F_60 ( V_1 ) ;
V_1 -> V_103 = F_45 ( V_7 , V_89 . V_100 ) ;
error = F_54 ( V_7 , V_42 , V_7 -> V_104 ,
V_1 -> V_103 ,
V_7 -> V_12 -> V_49 ,
0 , & V_44 , & V_107 ) ;
if ( error == V_82 && ( V_115 & V_112 ) ) {
T_5 V_110 = ( T_5 ) V_89 . V_123 *
V_7 -> V_12 -> V_48 ;
ASSERT ( V_44 == NULL ) ;
error = F_53 ( V_7 , V_42 , V_1 , V_110 , & V_44 ) ;
}
if ( error ) {
ASSERT ( V_44 == NULL ) ;
return F_55 ( error ) ;
}
}
ASSERT ( F_15 ( V_44 ) ) ;
* V_86 = V_44 ;
* V_114 = V_44 -> V_47 + V_1 -> V_120 ;
return ( 0 ) ;
}
int
F_61 (
struct V_6 * V_7 ,
T_5 V_43 ,
T_6 type ,
T_6 V_115 ,
struct V_8 * * V_124 )
{
struct V_8 * V_1 ;
struct V_13 * V_125 ;
struct V_73 * V_44 ;
struct V_109 * V_42 = NULL ;
int error ;
int V_126 = 0 ;
V_1 = F_62 ( V_4 , V_127 ) ;
V_1 -> V_94 = type ;
V_1 -> V_15 . V_17 = F_12 ( V_43 ) ;
V_1 -> V_93 = V_7 ;
F_63 ( & V_1 -> V_2 ) ;
F_64 ( & V_1 -> V_3 ) ;
F_65 ( & V_1 -> V_128 ) ;
F_66 ( & V_1 -> V_129 ) ;
F_67 ( & V_1 -> V_129 ) ;
switch ( type ) {
case V_61 :
break;
case V_130 :
F_68 ( & V_1 -> V_3 , & V_131 ) ;
break;
case V_63 :
F_68 ( & V_1 -> V_3 , & V_132 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_69 ( V_5 ) ;
F_70 ( V_1 ) ;
if ( V_115 & V_121 ) {
V_42 = F_71 ( V_7 , V_133 ) ;
error = F_72 ( V_42 , & F_73 ( V_7 ) -> V_134 ,
F_44 ( V_7 ) , 0 ) ;
if ( error )
goto V_105;
V_126 = V_135 ;
}
error = F_57 ( & V_42 , V_1 , & V_125 , & V_44 , V_115 ) ;
if ( error ) {
F_74 ( V_1 ) ;
V_126 |= V_136 ;
goto V_105;
}
memcpy ( & V_1 -> V_15 , V_125 , sizeof( T_3 ) ) ;
F_75 ( V_1 ) ;
V_1 -> V_137 = F_11 ( V_125 -> V_31 ) ;
V_1 -> V_138 = F_11 ( V_125 -> V_35 ) ;
V_1 -> V_139 = F_11 ( V_125 -> V_39 ) ;
F_8 ( V_1 ) ;
F_76 ( V_44 , V_140 ) ;
ASSERT ( F_15 ( V_44 ) ) ;
F_56 ( V_42 , V_44 ) ;
if ( V_42 ) {
error = F_77 ( V_42 , V_135 ) ;
if ( error )
goto V_98;
}
* V_124 = V_1 ;
return error ;
V_105:
if ( V_42 )
F_78 ( V_42 , V_126 ) ;
V_98:
F_1 ( V_1 ) ;
* V_124 = NULL ;
return error ;
}
int
F_79 (
T_2 * V_7 ,
T_10 * V_141 ,
T_5 V_43 ,
T_6 type ,
T_6 V_115 ,
T_1 * * V_124 )
{
struct V_10 * V_142 = V_7 -> V_12 ;
struct V_143 * V_144 = F_80 ( V_142 , type ) ;
struct V_8 * V_1 ;
int error ;
ASSERT ( F_81 ( V_7 ) ) ;
if ( ( ! F_82 ( V_7 ) && type == V_61 ) ||
( ! F_83 ( V_7 ) && type == V_63 ) ||
( ! F_84 ( V_7 ) && type == V_130 ) ) {
return ( V_95 ) ;
}
#ifdef F_10
if ( V_145 ) {
if ( ( V_146 == V_7 -> V_104 ) &&
( V_147 ++ % V_148 ) == 0 ) {
F_85 ( V_7 , L_3 ) ;
return ( V_113 ) ;
}
}
ASSERT ( type == V_61 ||
type == V_63 ||
type == V_130 ) ;
if ( V_141 ) {
ASSERT ( F_86 ( V_141 , V_92 ) ) ;
ASSERT ( F_87 ( V_141 , type ) == NULL ) ;
}
#endif
V_149:
F_88 ( & V_142 -> V_150 ) ;
V_1 = F_89 ( V_144 , V_43 ) ;
if ( V_1 ) {
F_90 ( V_1 ) ;
if ( V_1 -> V_94 & V_151 ) {
F_91 ( V_1 ) ;
F_92 ( & V_142 -> V_150 ) ;
F_93 ( V_1 ) ;
F_94 ( 1 ) ;
goto V_149;
}
V_1 -> V_152 ++ ;
F_92 ( & V_142 -> V_150 ) ;
F_95 ( V_1 ) ;
F_69 ( V_153 ) ;
* V_124 = V_1 ;
return 0 ;
}
F_92 ( & V_142 -> V_150 ) ;
F_69 ( V_154 ) ;
if ( V_141 )
F_41 ( V_141 , V_92 ) ;
error = F_61 ( V_7 , V_43 , type , V_115 , & V_1 ) ;
if ( V_141 )
F_39 ( V_141 , V_92 ) ;
if ( error )
return error ;
if ( V_141 ) {
if ( F_40 ( V_7 , type ) ) {
struct V_8 * V_155 ;
V_155 = F_87 ( V_141 , type ) ;
if ( V_155 ) {
F_1 ( V_1 ) ;
V_1 = V_155 ;
F_90 ( V_1 ) ;
goto V_156;
}
} else {
F_1 ( V_1 ) ;
return F_55 ( V_95 ) ;
}
}
F_88 ( & V_142 -> V_150 ) ;
error = - F_96 ( V_144 , V_43 , V_1 ) ;
if ( F_97 ( error ) ) {
F_98 ( error != V_157 ) ;
F_92 ( & V_142 -> V_150 ) ;
F_99 ( V_1 ) ;
F_1 ( V_1 ) ;
F_69 ( V_158 ) ;
goto V_149;
}
F_90 ( V_1 ) ;
V_1 -> V_152 = 1 ;
V_142 -> V_159 ++ ;
F_92 ( & V_142 -> V_150 ) ;
V_156:
ASSERT ( ( V_141 == NULL ) || F_86 ( V_141 , V_92 ) ) ;
F_100 ( V_1 ) ;
* V_124 = V_1 ;
return ( 0 ) ;
}
STATIC void
F_101 (
struct V_8 * V_1 )
{
struct V_10 * V_142 = V_1 -> V_93 -> V_12 ;
struct V_8 * V_160 ;
struct V_8 * V_161 ;
F_102 ( V_1 ) ;
if ( F_103 ( & V_142 -> V_162 , & V_1 -> V_2 ) )
F_69 ( V_163 ) ;
V_160 = V_1 -> V_164 ;
if ( V_160 ) {
F_90 ( V_160 ) ;
V_1 -> V_164 = NULL ;
}
V_161 = V_1 -> V_165 ;
if ( V_161 ) {
F_90 ( V_161 ) ;
V_1 -> V_165 = NULL ;
}
F_91 ( V_1 ) ;
if ( V_160 )
F_104 ( V_160 ) ;
if ( V_161 )
F_104 ( V_161 ) ;
}
void
F_104 (
struct V_8 * V_1 )
{
ASSERT ( V_1 -> V_152 > 0 ) ;
ASSERT ( F_105 ( V_1 ) ) ;
F_106 ( V_1 ) ;
if ( -- V_1 -> V_152 > 0 )
F_91 ( V_1 ) ;
else
F_101 ( V_1 ) ;
}
void
F_107 (
T_1 * V_1 )
{
if ( ! V_1 )
return;
F_108 ( V_1 ) ;
F_90 ( V_1 ) ;
F_104 ( V_1 ) ;
}
STATIC void
F_109 (
struct V_73 * V_44 ,
struct V_166 * V_167 )
{
T_15 * V_168 = (struct V_169 * ) V_167 ;
T_1 * V_1 = V_168 -> V_170 ;
struct V_171 * V_172 = V_167 -> V_173 ;
if ( ( V_167 -> V_174 & V_175 ) &&
V_167 -> V_176 == V_168 -> V_177 ) {
F_110 ( & V_172 -> V_178 ) ;
if ( V_167 -> V_176 == V_168 -> V_177 )
F_111 ( V_172 , V_167 , V_179 ) ;
else
F_112 ( & V_172 -> V_178 ) ;
}
F_113 ( V_1 ) ;
}
int
F_114 (
struct V_8 * V_1 ,
struct V_73 * * V_111 )
{
struct V_6 * V_7 = V_1 -> V_93 ;
struct V_73 * V_44 ;
struct V_13 * V_125 ;
int error ;
ASSERT ( F_105 ( V_1 ) ) ;
ASSERT ( ! F_115 ( & V_1 -> V_129 ) ) ;
F_116 ( V_1 ) ;
* V_111 = NULL ;
F_117 ( V_1 ) ;
if ( F_118 ( V_7 ) ) {
struct V_166 * V_167 = & V_1 -> V_180 . V_181 ;
V_1 -> V_94 &= ~ V_182 ;
F_110 ( & V_7 -> V_183 -> V_178 ) ;
if ( V_167 -> V_174 & V_175 )
F_111 ( V_7 -> V_183 , V_167 ,
V_179 ) ;
else
F_112 ( & V_7 -> V_183 -> V_178 ) ;
error = F_55 ( V_113 ) ;
goto V_184;
}
error = F_54 ( V_7 , NULL , V_7 -> V_104 , V_1 -> V_103 ,
V_7 -> V_12 -> V_49 , 0 , & V_44 , NULL ) ;
if ( error )
goto V_184;
V_125 = V_44 -> V_47 + V_1 -> V_120 ;
error = F_31 ( V_7 , & V_1 -> V_15 , F_30 ( V_125 -> V_17 ) , 0 ,
V_77 , L_4 ) ;
if ( error ) {
F_119 ( V_44 ) ;
F_113 ( V_1 ) ;
F_120 ( V_7 , V_179 ) ;
return F_55 ( V_113 ) ;
}
memcpy ( V_125 , & V_1 -> V_15 , sizeof( T_3 ) ) ;
V_1 -> V_94 &= ~ V_182 ;
F_121 ( V_7 -> V_183 , & V_1 -> V_180 . V_177 ,
& V_1 -> V_180 . V_181 . V_176 ) ;
if ( F_18 ( & V_7 -> V_56 ) ) {
struct V_59 * V_185 = (struct V_59 * ) V_125 ;
V_185 -> V_186 = F_7 ( V_1 -> V_180 . V_181 . V_176 ) ;
F_20 ( ( char * ) V_185 , sizeof( struct V_59 ) ,
V_60 ) ;
}
F_122 ( V_44 , F_109 ,
& V_1 -> V_180 . V_181 ) ;
if ( F_123 ( V_44 ) ) {
F_124 ( V_1 ) ;
F_125 ( V_7 , 0 ) ;
}
F_126 ( V_1 ) ;
* V_111 = V_44 ;
return 0 ;
V_184:
F_113 ( V_1 ) ;
return F_55 ( V_113 ) ;
}
void
F_127 (
T_1 * V_187 ,
T_1 * V_188 )
{
if ( V_187 && V_188 ) {
ASSERT ( V_187 != V_188 ) ;
if ( F_30 ( V_187 -> V_15 . V_17 ) >
F_30 ( V_188 -> V_15 . V_17 ) ) {
F_88 ( & V_188 -> V_3 ) ;
F_128 ( & V_187 -> V_3 , V_189 ) ;
} else {
F_88 ( & V_187 -> V_3 ) ;
F_128 ( & V_188 -> V_3 , V_189 ) ;
}
} else if ( V_187 ) {
F_88 ( & V_187 -> V_3 ) ;
} else if ( V_188 ) {
F_88 ( & V_188 -> V_3 ) ;
}
}
int T_16
F_129 ( void )
{
V_4 =
F_130 ( sizeof( struct V_8 ) , L_5 ) ;
if ( ! V_4 )
goto V_190;
V_191 =
F_130 ( sizeof( struct V_192 ) , L_6 ) ;
if ( ! V_191 )
goto V_193;
return 0 ;
V_193:
F_131 ( V_4 ) ;
V_190:
return - V_194 ;
}
void
F_132 ( void )
{
F_131 ( V_191 ) ;
F_131 ( V_4 ) ;
}
