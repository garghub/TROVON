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
STATIC int
F_24 (
T_4 * * V_73 ,
T_2 * V_7 ,
T_1 * V_1 ,
T_10 * V_74 ,
T_11 V_75 ,
T_7 * * V_76 )
{
T_12 V_77 ;
T_13 V_78 ;
T_14 V_79 ;
int V_80 , error , V_81 ;
T_7 * V_44 ;
T_4 * V_42 = * V_73 ;
ASSERT ( V_42 != NULL ) ;
F_25 ( V_1 ) ;
F_26 ( & V_78 , & V_77 ) ;
F_27 ( V_74 , V_82 ) ;
if ( ! F_28 ( V_1 -> V_83 , V_1 -> V_84 ) ) {
F_29 ( V_74 , V_82 ) ;
return ( V_85 ) ;
}
F_30 ( V_42 , V_74 , V_82 ) ;
V_80 = 1 ;
error = F_31 ( V_42 , V_74 , V_75 ,
V_86 , V_87 ,
& V_77 , F_32 ( V_7 ) ,
& V_79 , & V_80 , & V_78 ) ;
if ( error )
goto V_88;
ASSERT ( V_79 . V_89 == V_86 ) ;
ASSERT ( V_80 == 1 ) ;
ASSERT ( ( V_79 . V_90 != V_91 ) &&
( V_79 . V_90 != V_92 ) ) ;
V_1 -> V_93 = F_33 ( V_7 , V_79 . V_90 ) ;
V_44 = F_34 ( V_42 , V_7 -> V_94 ,
V_1 -> V_93 ,
V_7 -> V_12 -> V_49 ,
0 ) ;
error = F_35 ( V_44 ) ;
if ( error )
goto V_95;
V_44 -> V_96 = & V_97 ;
F_14 ( V_42 , V_7 , F_36 ( V_1 -> V_15 . V_17 ) ,
V_1 -> V_84 & V_98 , V_44 ) ;
F_37 ( V_42 , V_44 ) ;
if ( ( error = F_38 ( V_73 , & V_78 , & V_81 ) ) ) {
goto V_95;
}
if ( V_81 ) {
V_42 = * V_73 ;
F_39 ( V_42 , V_44 ) ;
} else {
F_40 ( V_42 , V_44 ) ;
}
* V_76 = V_44 ;
return 0 ;
V_95:
F_41 ( & V_78 ) ;
V_88:
F_29 ( V_74 , V_82 ) ;
return ( error ) ;
}
STATIC int
F_42 (
struct V_6 * V_7 ,
struct V_99 * V_42 ,
struct V_8 * V_1 ,
T_5 V_100 ,
struct V_101 * * V_102 )
{
int error ;
struct V_13 * V_103 ;
struct V_59 * V_14 ;
int V_46 ;
error = F_43 ( V_7 , V_42 , V_7 -> V_94 , V_1 -> V_93 ,
V_7 -> V_12 -> V_49 ,
0 , V_102 , NULL ) ;
if ( error ) {
ASSERT ( * V_102 == NULL ) ;
return F_44 ( error ) ;
}
( * V_102 ) -> V_96 = & V_97 ;
ASSERT ( F_15 ( * V_102 ) ) ;
V_14 = (struct V_59 * ) ( * V_102 ) -> V_47 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_12 -> V_48 ; V_46 ++ ) {
V_103 = & V_14 [ V_46 ] . V_50 ;
error = F_45 ( V_7 , V_103 , V_100 + V_46 ,
V_1 -> V_84 & V_98 ,
V_104 , L_1 ) ;
if ( error ) {
F_46 ( V_42 , * V_102 ) ;
return F_44 ( V_105 ) ;
}
}
return 0 ;
}
STATIC int
F_47 (
T_4 * * V_73 ,
T_1 * V_1 ,
T_3 * * V_106 ,
T_7 * * V_76 ,
T_6 V_107 )
{
struct V_108 V_79 ;
int V_80 = 1 , error ;
struct V_101 * V_44 ;
struct V_109 * V_74 = F_48 ( V_1 ) ;
struct V_6 * V_7 = V_1 -> V_83 ;
T_5 V_43 = F_36 ( V_1 -> V_15 . V_17 ) ;
struct V_99 * V_42 = ( V_73 ? * V_73 : NULL ) ;
V_1 -> V_110 = ( T_11 ) V_43 / V_7 -> V_12 -> V_48 ;
F_27 ( V_74 , V_111 ) ;
if ( ! F_28 ( V_1 -> V_83 , V_1 -> V_84 ) ) {
F_29 ( V_74 , V_111 ) ;
return V_85 ;
}
error = F_49 ( V_74 , V_1 -> V_110 ,
V_86 , & V_79 , & V_80 , 0 ) ;
F_29 ( V_74 , V_111 ) ;
if ( error )
return error ;
ASSERT ( V_80 == 1 ) ;
ASSERT ( V_79 . V_89 == 1 ) ;
V_1 -> V_112 = ( V_43 % V_7 -> V_12 -> V_48 ) *
sizeof( T_8 ) ;
ASSERT ( V_79 . V_90 != V_91 ) ;
if ( V_79 . V_90 == V_92 ) {
if ( ! ( V_107 & V_113 ) )
return V_114 ;
ASSERT ( V_42 ) ;
error = F_24 ( V_73 , V_7 , V_1 , V_74 ,
V_1 -> V_110 , & V_44 ) ;
if ( error )
return error ;
V_42 = * V_73 ;
} else {
F_50 ( V_1 ) ;
V_1 -> V_93 = F_33 ( V_7 , V_79 . V_90 ) ;
error = F_43 ( V_7 , V_42 , V_7 -> V_94 ,
V_1 -> V_93 ,
V_7 -> V_12 -> V_49 ,
0 , & V_44 , & V_97 ) ;
if ( error == V_115 && ( V_107 & V_104 ) ) {
T_5 V_100 = ( T_5 ) V_79 . V_116 *
V_7 -> V_12 -> V_48 ;
ASSERT ( V_44 == NULL ) ;
error = F_42 ( V_7 , V_42 , V_1 , V_100 , & V_44 ) ;
}
if ( error ) {
ASSERT ( V_44 == NULL ) ;
return F_44 ( error ) ;
}
}
ASSERT ( F_15 ( V_44 ) ) ;
* V_76 = V_44 ;
* V_106 = V_44 -> V_47 + V_1 -> V_112 ;
return ( 0 ) ;
}
int
F_51 (
struct V_6 * V_7 ,
T_5 V_43 ,
T_6 type ,
T_6 V_107 ,
struct V_8 * * V_117 )
{
struct V_8 * V_1 ;
struct V_13 * V_118 ;
struct V_101 * V_44 ;
struct V_99 * V_42 = NULL ;
int error ;
int V_119 = 0 ;
V_1 = F_52 ( V_4 , V_120 ) ;
V_1 -> V_84 = type ;
V_1 -> V_15 . V_17 = F_12 ( V_43 ) ;
V_1 -> V_83 = V_7 ;
F_53 ( & V_1 -> V_2 ) ;
F_54 ( & V_1 -> V_3 ) ;
F_55 ( & V_1 -> V_121 ) ;
F_56 ( & V_1 -> V_122 ) ;
F_57 ( & V_1 -> V_122 ) ;
switch ( type ) {
case V_61 :
break;
case V_123 :
F_58 ( & V_1 -> V_3 , & V_124 ) ;
break;
case V_63 :
F_58 ( & V_1 -> V_3 , & V_125 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_59 ( V_5 ) ;
F_60 ( V_1 ) ;
if ( V_107 & V_113 ) {
V_42 = F_61 ( V_7 , V_126 ) ;
error = F_62 ( V_42 , & F_63 ( V_7 ) -> V_127 ,
F_32 ( V_7 ) , 0 ) ;
if ( error )
goto V_95;
V_119 = V_128 ;
}
error = F_47 ( & V_42 , V_1 , & V_118 , & V_44 , V_107 ) ;
if ( error ) {
F_64 ( V_1 ) ;
V_119 |= V_129 ;
goto V_95;
}
memcpy ( & V_1 -> V_15 , V_118 , sizeof( T_3 ) ) ;
F_65 ( V_1 ) ;
V_1 -> V_130 = F_11 ( V_118 -> V_31 ) ;
V_1 -> V_131 = F_11 ( V_118 -> V_35 ) ;
V_1 -> V_132 = F_11 ( V_118 -> V_39 ) ;
F_8 ( V_1 ) ;
F_66 ( V_44 , V_133 ) ;
ASSERT ( F_15 ( V_44 ) ) ;
F_46 ( V_42 , V_44 ) ;
if ( V_42 ) {
error = F_67 ( V_42 , V_128 ) ;
if ( error )
goto V_88;
}
* V_117 = V_1 ;
return error ;
V_95:
if ( V_42 )
F_68 ( V_42 , V_119 ) ;
V_88:
F_1 ( V_1 ) ;
* V_117 = NULL ;
return error ;
}
int
F_69 (
T_2 * V_7 ,
T_10 * V_134 ,
T_5 V_43 ,
T_6 type ,
T_6 V_107 ,
T_1 * * V_117 )
{
struct V_10 * V_135 = V_7 -> V_12 ;
struct V_136 * V_137 = F_70 ( V_135 , type ) ;
struct V_8 * V_1 ;
int error ;
ASSERT ( F_71 ( V_7 ) ) ;
if ( ( ! F_72 ( V_7 ) && type == V_61 ) ||
( ! F_73 ( V_7 ) && type == V_63 ) ||
( ! F_74 ( V_7 ) && type == V_123 ) ) {
return ( V_85 ) ;
}
#ifdef F_10
if ( V_138 ) {
if ( ( V_139 == V_7 -> V_94 ) &&
( V_140 ++ % V_141 ) == 0 ) {
F_75 ( V_7 , L_2 ) ;
return ( V_105 ) ;
}
}
ASSERT ( type == V_61 ||
type == V_63 ||
type == V_123 ) ;
if ( V_134 ) {
ASSERT ( F_76 ( V_134 , V_82 ) ) ;
ASSERT ( F_77 ( V_134 , type ) == NULL ) ;
}
#endif
V_142:
F_78 ( & V_135 -> V_143 ) ;
V_1 = F_79 ( V_137 , V_43 ) ;
if ( V_1 ) {
F_80 ( V_1 ) ;
if ( V_1 -> V_84 & V_144 ) {
F_81 ( V_1 ) ;
F_82 ( & V_135 -> V_143 ) ;
F_83 ( V_1 ) ;
F_84 ( 1 ) ;
goto V_142;
}
V_1 -> V_145 ++ ;
F_82 ( & V_135 -> V_143 ) ;
F_85 ( V_1 ) ;
F_59 ( V_146 ) ;
* V_117 = V_1 ;
return 0 ;
}
F_82 ( & V_135 -> V_143 ) ;
F_59 ( V_147 ) ;
if ( V_134 )
F_29 ( V_134 , V_82 ) ;
error = F_51 ( V_7 , V_43 , type , V_107 , & V_1 ) ;
if ( V_134 )
F_27 ( V_134 , V_82 ) ;
if ( error )
return error ;
if ( V_134 ) {
if ( F_28 ( V_7 , type ) ) {
struct V_8 * V_148 ;
V_148 = F_77 ( V_134 , type ) ;
if ( V_148 ) {
F_1 ( V_1 ) ;
V_1 = V_148 ;
F_80 ( V_1 ) ;
goto V_149;
}
} else {
F_1 ( V_1 ) ;
return F_44 ( V_85 ) ;
}
}
F_78 ( & V_135 -> V_143 ) ;
error = - F_86 ( V_137 , V_43 , V_1 ) ;
if ( F_87 ( error ) ) {
F_88 ( error != V_150 ) ;
F_82 ( & V_135 -> V_143 ) ;
F_89 ( V_1 ) ;
F_1 ( V_1 ) ;
F_59 ( V_151 ) ;
goto V_142;
}
F_80 ( V_1 ) ;
V_1 -> V_145 = 1 ;
V_135 -> V_152 ++ ;
F_82 ( & V_135 -> V_143 ) ;
V_149:
ASSERT ( ( V_134 == NULL ) || F_76 ( V_134 , V_82 ) ) ;
F_90 ( V_1 ) ;
* V_117 = V_1 ;
return ( 0 ) ;
}
STATIC void
F_91 (
struct V_8 * V_1 )
{
struct V_10 * V_135 = V_1 -> V_83 -> V_12 ;
struct V_8 * V_153 ;
struct V_8 * V_154 ;
F_92 ( V_1 ) ;
if ( F_93 ( & V_135 -> V_155 , & V_1 -> V_2 ) )
F_59 ( V_156 ) ;
V_153 = V_1 -> V_157 ;
if ( V_153 ) {
F_80 ( V_153 ) ;
V_1 -> V_157 = NULL ;
}
V_154 = V_1 -> V_158 ;
if ( V_154 ) {
F_80 ( V_154 ) ;
V_1 -> V_158 = NULL ;
}
F_81 ( V_1 ) ;
if ( V_153 )
F_94 ( V_153 ) ;
if ( V_154 )
F_94 ( V_154 ) ;
}
void
F_94 (
struct V_8 * V_1 )
{
ASSERT ( V_1 -> V_145 > 0 ) ;
ASSERT ( F_95 ( V_1 ) ) ;
F_96 ( V_1 ) ;
if ( -- V_1 -> V_145 > 0 )
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
struct V_101 * V_44 ,
struct V_159 * V_160 )
{
T_15 * V_161 = (struct V_162 * ) V_160 ;
T_1 * V_1 = V_161 -> V_163 ;
struct V_164 * V_165 = V_160 -> V_166 ;
if ( ( V_160 -> V_167 & V_168 ) &&
V_160 -> V_169 == V_161 -> V_170 ) {
F_100 ( & V_165 -> V_171 ) ;
if ( V_160 -> V_169 == V_161 -> V_170 )
F_101 ( V_165 , V_160 , V_172 ) ;
else
F_102 ( & V_165 -> V_171 ) ;
}
F_103 ( V_1 ) ;
}
int
F_104 (
struct V_8 * V_1 ,
struct V_101 * * V_102 )
{
struct V_6 * V_7 = V_1 -> V_83 ;
struct V_101 * V_44 ;
struct V_13 * V_118 ;
int error ;
ASSERT ( F_95 ( V_1 ) ) ;
ASSERT ( ! F_105 ( & V_1 -> V_122 ) ) ;
F_106 ( V_1 ) ;
* V_102 = NULL ;
F_107 ( V_1 ) ;
if ( F_108 ( V_7 ) ) {
struct V_159 * V_160 = & V_1 -> V_173 . V_174 ;
V_1 -> V_84 &= ~ V_175 ;
F_100 ( & V_7 -> V_176 -> V_171 ) ;
if ( V_160 -> V_167 & V_168 )
F_101 ( V_7 -> V_176 , V_160 ,
V_172 ) ;
else
F_102 ( & V_7 -> V_176 -> V_171 ) ;
error = F_44 ( V_105 ) ;
goto V_177;
}
error = F_43 ( V_7 , NULL , V_7 -> V_94 , V_1 -> V_93 ,
V_7 -> V_12 -> V_49 , 0 , & V_44 , NULL ) ;
if ( error )
goto V_177;
V_118 = V_44 -> V_47 + V_1 -> V_112 ;
error = F_45 ( V_7 , & V_1 -> V_15 , F_36 ( V_118 -> V_17 ) , 0 ,
V_178 , L_3 ) ;
if ( error ) {
F_109 ( V_44 ) ;
F_103 ( V_1 ) ;
F_110 ( V_7 , V_172 ) ;
return F_44 ( V_105 ) ;
}
memcpy ( V_118 , & V_1 -> V_15 , sizeof( T_3 ) ) ;
V_1 -> V_84 &= ~ V_175 ;
F_111 ( V_7 -> V_176 , & V_1 -> V_173 . V_170 ,
& V_1 -> V_173 . V_174 . V_169 ) ;
if ( F_18 ( & V_7 -> V_56 ) ) {
struct V_59 * V_179 = (struct V_59 * ) V_118 ;
V_179 -> V_180 = F_7 ( V_1 -> V_173 . V_174 . V_169 ) ;
F_20 ( ( char * ) V_179 , sizeof( struct V_59 ) ,
V_60 ) ;
}
F_112 ( V_44 , F_99 ,
& V_1 -> V_173 . V_174 ) ;
if ( F_113 ( V_44 ) ) {
F_114 ( V_1 ) ;
F_115 ( V_7 , 0 ) ;
}
F_116 ( V_1 ) ;
* V_102 = V_44 ;
return 0 ;
V_177:
F_103 ( V_1 ) ;
return F_44 ( V_105 ) ;
}
void
F_117 (
T_1 * V_181 ,
T_1 * V_182 )
{
if ( V_181 && V_182 ) {
ASSERT ( V_181 != V_182 ) ;
if ( F_36 ( V_181 -> V_15 . V_17 ) >
F_36 ( V_182 -> V_15 . V_17 ) ) {
F_78 ( & V_182 -> V_3 ) ;
F_118 ( & V_181 -> V_3 , V_183 ) ;
} else {
F_78 ( & V_181 -> V_3 ) ;
F_118 ( & V_182 -> V_3 , V_183 ) ;
}
} else if ( V_181 ) {
F_78 ( & V_181 -> V_3 ) ;
} else if ( V_182 ) {
F_78 ( & V_182 -> V_3 ) ;
}
}
int T_16
F_119 ( void )
{
V_4 =
F_120 ( sizeof( struct V_8 ) , L_4 ) ;
if ( ! V_4 )
goto V_184;
V_185 =
F_120 ( sizeof( struct V_186 ) , L_5 ) ;
if ( ! V_185 )
goto V_187;
return 0 ;
V_187:
F_121 ( V_4 ) ;
V_184:
return - V_188 ;
}
void
F_122 ( void )
{
F_121 ( V_185 ) ;
F_121 ( V_4 ) ;
}
