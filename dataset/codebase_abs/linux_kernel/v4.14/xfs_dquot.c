void
F_1 (
T_1 * V_1 )
{
ASSERT ( F_2 ( & V_1 -> V_2 ) ) ;
F_3 ( V_1 -> V_3 . V_4 . V_5 ) ;
F_4 ( & V_1 -> V_6 ) ;
F_5 ( V_1 -> V_7 , V_8 ) ;
F_6 ( V_9 , V_1 ) ;
}
void
F_7 (
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_17 * V_18 = & V_13 -> V_19 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
ASSERT ( V_18 -> V_23 ) ;
V_21 = F_8 ( V_13 , V_15 ) ;
if ( V_21 -> V_24 && ! V_18 -> V_25 ) {
V_18 -> V_25 = F_9 ( V_21 -> V_24 ) ;
V_22 = 1 ;
}
if ( V_21 -> V_26 && ! V_18 -> V_27 ) {
V_18 -> V_27 = F_9 ( V_21 -> V_26 ) ;
V_22 = 1 ;
}
if ( V_21 -> V_28 && ! V_18 -> V_29 )
V_18 -> V_29 = F_9 ( V_21 -> V_28 ) ;
if ( V_21 -> V_30 && ! V_18 -> V_31 )
V_18 -> V_31 = F_9 ( V_21 -> V_30 ) ;
if ( V_21 -> V_32 && ! V_18 -> V_33 )
V_18 -> V_33 = F_9 ( V_21 -> V_32 ) ;
if ( V_21 -> V_34 && ! V_18 -> V_35 )
V_18 -> V_35 = F_9 ( V_21 -> V_34 ) ;
if ( V_22 )
F_10 ( V_13 ) ;
}
void
F_11 (
T_2 * V_11 ,
T_3 * V_18 )
{
ASSERT ( V_18 -> V_23 ) ;
#ifdef F_12
if ( V_18 -> V_27 )
ASSERT ( F_13 ( V_18 -> V_25 ) <=
F_13 ( V_18 -> V_27 ) ) ;
if ( V_18 -> V_31 )
ASSERT ( F_13 ( V_18 -> V_29 ) <=
F_13 ( V_18 -> V_31 ) ) ;
if ( V_18 -> V_35 )
ASSERT ( F_13 ( V_18 -> V_33 ) <=
F_13 ( V_18 -> V_35 ) ) ;
#endif
if ( ! V_18 -> V_36 ) {
if ( ( V_18 -> V_25 &&
( F_13 ( V_18 -> V_37 ) >
F_13 ( V_18 -> V_25 ) ) ) ||
( V_18 -> V_27 &&
( F_13 ( V_18 -> V_37 ) >
F_13 ( V_18 -> V_27 ) ) ) ) {
V_18 -> V_36 = F_14 ( F_15 () +
V_11 -> V_16 -> V_38 ) ;
} else {
V_18 -> V_39 = 0 ;
}
} else {
if ( ( ! V_18 -> V_25 ||
( F_13 ( V_18 -> V_37 ) <=
F_13 ( V_18 -> V_25 ) ) ) &&
( ! V_18 -> V_27 ||
( F_13 ( V_18 -> V_37 ) <=
F_13 ( V_18 -> V_27 ) ) ) ) {
V_18 -> V_36 = 0 ;
}
}
if ( ! V_18 -> V_40 ) {
if ( ( V_18 -> V_29 &&
( F_13 ( V_18 -> V_41 ) >
F_13 ( V_18 -> V_29 ) ) ) ||
( V_18 -> V_31 &&
( F_13 ( V_18 -> V_41 ) >
F_13 ( V_18 -> V_31 ) ) ) ) {
V_18 -> V_40 = F_14 ( F_15 () +
V_11 -> V_16 -> V_42 ) ;
} else {
V_18 -> V_43 = 0 ;
}
} else {
if ( ( ! V_18 -> V_29 ||
( F_13 ( V_18 -> V_41 ) <=
F_13 ( V_18 -> V_29 ) ) ) &&
( ! V_18 -> V_31 ||
( F_13 ( V_18 -> V_41 ) <=
F_13 ( V_18 -> V_31 ) ) ) ) {
V_18 -> V_40 = 0 ;
}
}
if ( ! V_18 -> V_44 ) {
if ( ( V_18 -> V_33 &&
( F_13 ( V_18 -> V_45 ) >
F_13 ( V_18 -> V_33 ) ) ) ||
( V_18 -> V_35 &&
( F_13 ( V_18 -> V_45 ) >
F_13 ( V_18 -> V_35 ) ) ) ) {
V_18 -> V_44 = F_14 ( F_15 () +
V_11 -> V_16 -> V_46 ) ;
} else {
V_18 -> V_47 = 0 ;
}
} else {
if ( ( ! V_18 -> V_33 ||
( F_13 ( V_18 -> V_45 ) <=
F_13 ( V_18 -> V_33 ) ) ) &&
( ! V_18 -> V_35 ||
( F_13 ( V_18 -> V_45 ) <=
F_13 ( V_18 -> V_35 ) ) ) ) {
V_18 -> V_44 = 0 ;
}
}
}
STATIC void
F_16 (
T_4 * V_48 ,
T_2 * V_11 ,
T_5 V_49 ,
T_6 type ,
T_7 * V_50 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
T_8 * V_18 ;
T_5 V_51 ;
int V_52 ;
ASSERT ( V_48 ) ;
ASSERT ( F_17 ( V_50 ) ) ;
V_18 = V_50 -> V_53 ;
V_51 = V_49 - ( V_49 % V_15 -> V_54 ) ;
memset ( V_18 , 0 , F_18 ( V_15 -> V_55 ) ) ;
for ( V_52 = 0 ; V_52 < V_15 -> V_54 ; V_52 ++ , V_18 ++ , V_51 ++ ) {
V_18 -> V_56 . V_57 = F_19 ( V_58 ) ;
V_18 -> V_56 . V_59 = V_60 ;
V_18 -> V_56 . V_23 = F_14 ( V_51 ) ;
V_18 -> V_56 . V_61 = type ;
if ( F_20 ( & V_11 -> V_62 ) ) {
F_21 ( & V_18 -> V_63 , & V_11 -> V_62 . V_64 ) ;
F_22 ( ( char * ) V_18 , sizeof( struct V_65 ) ,
V_66 ) ;
}
}
F_23 ( V_48 , V_50 ,
( type & V_67 ? V_68 :
( ( type & V_69 ) ? V_70 :
V_71 ) ) ) ;
F_24 ( V_48 , V_50 , 0 , F_18 ( V_15 -> V_55 ) - 1 ) ;
}
void
F_10 ( struct V_12 * V_1 )
{
T_9 V_72 ;
V_1 -> V_73 = F_13 ( V_1 -> V_19 . V_27 ) ;
V_1 -> V_74 = F_13 ( V_1 -> V_19 . V_25 ) ;
if ( ! V_1 -> V_74 ) {
V_1 -> V_74 = V_1 -> V_73 ;
F_25 ( V_1 -> V_74 , 100 ) ;
V_1 -> V_74 *= 95 ;
}
V_72 = V_1 -> V_73 ;
F_25 ( V_72 , 100 ) ;
V_1 -> V_75 [ V_76 ] = V_72 ;
V_1 -> V_75 [ V_77 ] = V_72 * 3 ;
V_1 -> V_75 [ V_78 ] = V_72 * 5 ;
}
STATIC int
F_26 (
T_4 * * V_79 ,
T_2 * V_11 ,
T_1 * V_1 ,
T_10 * V_80 ,
T_11 V_81 ,
T_7 * * V_82 )
{
T_12 V_83 ;
struct V_84 V_85 ;
T_13 V_86 ;
int V_87 , error ;
T_7 * V_50 ;
T_4 * V_48 = * V_79 ;
ASSERT ( V_48 != NULL ) ;
F_27 ( V_1 ) ;
F_28 ( & V_85 , & V_83 ) ;
F_29 ( V_80 , V_88 ) ;
if ( ! F_30 ( V_1 -> V_7 , V_1 -> V_89 ) ) {
F_31 ( V_80 , V_88 ) ;
return - V_90 ;
}
F_32 ( V_48 , V_80 , V_88 ) ;
V_87 = 1 ;
error = F_33 ( V_48 , V_80 , V_81 ,
V_91 , V_92 ,
& V_83 , F_34 ( V_11 ) ,
& V_86 , & V_87 , & V_85 ) ;
if ( error )
goto V_93;
ASSERT ( V_86 . V_94 == V_91 ) ;
ASSERT ( V_87 == 1 ) ;
ASSERT ( ( V_86 . V_95 != V_96 ) &&
( V_86 . V_95 != V_97 ) ) ;
V_1 -> V_98 = F_35 ( V_11 , V_86 . V_95 ) ;
V_50 = F_36 ( V_48 , V_11 -> V_99 ,
V_1 -> V_98 ,
V_11 -> V_16 -> V_55 ,
0 ) ;
if ( ! V_50 ) {
error = - V_100 ;
goto V_101;
}
V_50 -> V_102 = & V_103 ;
F_16 ( V_48 , V_11 , F_37 ( V_1 -> V_19 . V_23 ) ,
V_1 -> V_89 & V_104 , V_50 ) ;
F_38 ( V_48 , V_50 ) ;
error = F_39 ( V_79 , & V_85 ) ;
if ( error )
goto V_101;
if ( * V_79 != V_48 ) {
V_48 = * V_79 ;
F_40 ( V_48 , V_50 ) ;
} else {
F_41 ( V_48 , V_50 ) ;
}
* V_82 = V_50 ;
return 0 ;
V_101:
F_42 ( & V_85 ) ;
V_93:
F_31 ( V_80 , V_88 ) ;
return error ;
}
STATIC int
F_43 (
struct V_10 * V_11 ,
struct V_105 * V_48 ,
struct V_12 * V_1 ,
T_5 V_106 ,
struct V_107 * * V_108 )
{
int error ;
struct V_17 * V_109 ;
struct V_65 * V_18 ;
int V_52 ;
error = F_44 ( V_11 , V_48 , V_11 -> V_99 , V_1 -> V_98 ,
V_11 -> V_16 -> V_55 ,
0 , V_108 , NULL ) ;
if ( error ) {
ASSERT ( * V_108 == NULL ) ;
return error ;
}
( * V_108 ) -> V_102 = & V_103 ;
ASSERT ( F_17 ( * V_108 ) ) ;
V_18 = (struct V_65 * ) ( * V_108 ) -> V_53 ;
for ( V_52 = 0 ; V_52 < V_11 -> V_16 -> V_54 ; V_52 ++ ) {
V_109 = & V_18 [ V_52 ] . V_56 ;
error = F_45 ( V_11 , V_109 , V_106 + V_52 ,
V_1 -> V_89 & V_104 ,
V_110 , L_1 ) ;
if ( error ) {
F_46 ( V_48 , * V_108 ) ;
return - V_111 ;
}
}
return 0 ;
}
STATIC int
F_47 (
T_4 * * V_79 ,
T_1 * V_1 ,
T_3 * * V_112 ,
T_7 * * V_82 ,
T_6 V_113 )
{
struct V_114 V_86 ;
int V_87 = 1 , error ;
struct V_107 * V_50 ;
struct V_115 * V_80 ;
struct V_10 * V_11 = V_1 -> V_7 ;
T_5 V_49 = F_37 ( V_1 -> V_19 . V_23 ) ;
struct V_105 * V_48 = ( V_79 ? * V_79 : NULL ) ;
T_6 V_116 ;
V_80 = F_48 ( V_1 -> V_7 , V_1 -> V_89 ) ;
V_1 -> V_117 = ( T_11 ) V_49 / V_11 -> V_16 -> V_54 ;
V_116 = F_49 ( V_80 ) ;
if ( ! F_30 ( V_1 -> V_7 , V_1 -> V_89 ) ) {
F_31 ( V_80 , V_116 ) ;
return - V_90 ;
}
error = F_50 ( V_80 , V_1 -> V_117 ,
V_91 , & V_86 , & V_87 , 0 ) ;
F_31 ( V_80 , V_116 ) ;
if ( error )
return error ;
ASSERT ( V_87 == 1 ) ;
ASSERT ( V_86 . V_94 == 1 ) ;
V_1 -> V_118 = ( V_49 % V_11 -> V_16 -> V_54 ) *
sizeof( T_8 ) ;
ASSERT ( V_86 . V_95 != V_96 ) ;
if ( V_86 . V_95 == V_97 ) {
if ( ! ( V_113 & V_119 ) )
return - V_120 ;
ASSERT ( V_48 ) ;
error = F_26 ( V_79 , V_11 , V_1 , V_80 ,
V_1 -> V_117 , & V_50 ) ;
if ( error )
return error ;
V_48 = * V_79 ;
} else {
F_51 ( V_1 ) ;
V_1 -> V_98 = F_35 ( V_11 , V_86 . V_95 ) ;
error = F_44 ( V_11 , V_48 , V_11 -> V_99 ,
V_1 -> V_98 ,
V_11 -> V_16 -> V_55 ,
0 , & V_50 , & V_103 ) ;
if ( error == - V_121 && ( V_113 & V_110 ) ) {
T_5 V_106 = ( T_5 ) V_86 . V_122 *
V_11 -> V_16 -> V_54 ;
ASSERT ( V_50 == NULL ) ;
error = F_43 ( V_11 , V_48 , V_1 , V_106 , & V_50 ) ;
}
if ( error ) {
ASSERT ( V_50 == NULL ) ;
return error ;
}
}
ASSERT ( F_17 ( V_50 ) ) ;
* V_82 = V_50 ;
* V_112 = V_50 -> V_53 + V_1 -> V_118 ;
return 0 ;
}
int
F_52 (
struct V_10 * V_11 ,
T_5 V_49 ,
T_6 type ,
T_6 V_113 ,
struct V_12 * * V_123 )
{
struct V_12 * V_1 ;
struct V_17 * V_124 ;
struct V_107 * V_50 ;
struct V_105 * V_48 = NULL ;
int error ;
V_1 = F_53 ( V_9 , V_125 ) ;
V_1 -> V_89 = type ;
V_1 -> V_19 . V_23 = F_14 ( V_49 ) ;
V_1 -> V_7 = V_11 ;
F_54 ( & V_1 -> V_2 ) ;
F_55 ( & V_1 -> V_6 ) ;
F_56 ( & V_1 -> V_126 ) ;
F_57 ( & V_1 -> V_127 ) ;
F_58 ( & V_1 -> V_127 ) ;
switch ( type ) {
case V_67 :
break;
case V_128 :
F_59 ( & V_1 -> V_6 , & V_129 ) ;
break;
case V_69 :
F_59 ( & V_1 -> V_6 , & V_130 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_60 ( V_11 , V_8 ) ;
F_61 ( V_1 ) ;
if ( V_113 & V_119 ) {
error = F_62 ( V_11 , & F_63 ( V_11 ) -> V_131 ,
F_34 ( V_11 ) , 0 , 0 , & V_48 ) ;
if ( error )
goto V_93;
}
error = F_47 ( & V_48 , V_1 , & V_124 , & V_50 , V_113 ) ;
if ( error ) {
F_64 ( V_1 ) ;
goto V_101;
}
memcpy ( & V_1 -> V_19 , V_124 , sizeof( T_3 ) ) ;
F_65 ( V_1 ) ;
V_1 -> V_132 = F_13 ( V_124 -> V_37 ) ;
V_1 -> V_133 = F_13 ( V_124 -> V_41 ) ;
V_1 -> V_134 = F_13 ( V_124 -> V_45 ) ;
F_10 ( V_1 ) ;
F_66 ( V_50 , V_135 ) ;
ASSERT ( F_17 ( V_50 ) ) ;
F_46 ( V_48 , V_50 ) ;
if ( V_48 ) {
error = F_67 ( V_48 ) ;
if ( error )
goto V_93;
}
* V_123 = V_1 ;
return error ;
V_101:
if ( V_48 )
F_68 ( V_48 ) ;
V_93:
F_1 ( V_1 ) ;
* V_123 = NULL ;
return error ;
}
static int
F_69 (
struct V_10 * V_11 ,
T_6 type ,
T_5 * V_49 )
{
struct V_115 * V_80 = F_48 ( V_11 , type ) ;
T_5 V_136 = * V_49 + 1 ;
T_6 V_137 ;
struct V_114 V_138 ;
T_14 V_139 ;
T_12 V_140 ;
int error = 0 ;
if ( V_136 < * V_49 )
return - V_120 ;
if ( V_136 % V_11 -> V_16 -> V_54 ) {
* V_49 = V_136 ;
return 0 ;
}
V_140 = ( T_12 ) V_136 / V_11 -> V_16 -> V_54 ;
V_137 = F_49 ( V_80 ) ;
if ( ! ( V_80 -> V_141 . V_142 & V_143 ) ) {
error = F_70 ( NULL , V_80 , V_144 ) ;
if ( error )
return error ;
}
if ( F_71 ( V_80 , & V_80 -> V_141 , V_140 , & V_139 , & V_138 ) ) {
if ( V_138 . V_122 < V_140 )
V_138 . V_122 = V_140 ;
* V_49 = V_138 . V_122 * V_11 -> V_16 -> V_54 ;
} else {
error = - V_120 ;
}
F_31 ( V_80 , V_137 ) ;
return error ;
}
int
F_72 (
T_2 * V_11 ,
T_10 * V_145 ,
T_5 V_49 ,
T_6 type ,
T_6 V_113 ,
T_1 * * V_123 )
{
struct V_14 * V_146 = V_11 -> V_16 ;
struct V_147 * V_148 = F_73 ( V_146 , type ) ;
struct V_12 * V_1 ;
int error ;
ASSERT ( F_74 ( V_11 ) ) ;
if ( ( ! F_75 ( V_11 ) && type == V_67 ) ||
( ! F_76 ( V_11 ) && type == V_69 ) ||
( ! F_77 ( V_11 ) && type == V_128 ) ) {
return - V_90 ;
}
#ifdef F_12
if ( V_149 ) {
if ( ( V_150 == V_11 -> V_99 ) &&
( V_151 ++ % V_152 ) == 0 ) {
F_78 ( V_11 , L_2 ) ;
return - V_111 ;
}
}
ASSERT ( type == V_67 ||
type == V_69 ||
type == V_128 ) ;
if ( V_145 ) {
ASSERT ( F_79 ( V_145 , V_88 ) ) ;
ASSERT ( F_80 ( V_145 , type ) == NULL ) ;
}
#endif
V_153:
F_81 ( & V_146 -> V_154 ) ;
V_1 = F_82 ( V_148 , V_49 ) ;
if ( V_1 ) {
F_83 ( V_1 ) ;
if ( V_1 -> V_89 & V_155 ) {
F_84 ( V_1 ) ;
F_85 ( & V_146 -> V_154 ) ;
F_86 ( V_1 ) ;
F_87 ( 1 ) ;
goto V_153;
}
if ( V_113 & V_156 ) {
if ( F_88 ( V_1 ) ) {
F_84 ( V_1 ) ;
F_85 ( & V_146 -> V_154 ) ;
error = F_69 ( V_11 , type , & V_49 ) ;
if ( error )
return error ;
goto V_153;
}
}
V_1 -> V_157 ++ ;
F_85 ( & V_146 -> V_154 ) ;
F_89 ( V_1 ) ;
F_60 ( V_11 , V_158 ) ;
* V_123 = V_1 ;
return 0 ;
}
F_85 ( & V_146 -> V_154 ) ;
F_60 ( V_11 , V_159 ) ;
if ( V_145 )
F_31 ( V_145 , V_88 ) ;
error = F_52 ( V_11 , V_49 , type , V_113 , & V_1 ) ;
if ( V_145 )
F_29 ( V_145 , V_88 ) ;
if ( error == - V_120 && ( V_113 & V_156 ) ) {
error = F_69 ( V_11 , type , & V_49 ) ;
if ( ! error )
goto V_153;
}
if ( error )
return error ;
if ( V_145 ) {
if ( F_30 ( V_11 , type ) ) {
struct V_12 * V_160 ;
V_160 = F_80 ( V_145 , type ) ;
if ( V_160 ) {
F_1 ( V_1 ) ;
V_1 = V_160 ;
F_83 ( V_1 ) ;
goto V_161;
}
} else {
F_1 ( V_1 ) ;
return - V_90 ;
}
}
F_81 ( & V_146 -> V_154 ) ;
error = F_90 ( V_148 , V_49 , V_1 ) ;
if ( F_91 ( error ) ) {
F_92 ( error != - V_162 ) ;
F_85 ( & V_146 -> V_154 ) ;
F_93 ( V_1 ) ;
F_1 ( V_1 ) ;
F_60 ( V_11 , V_163 ) ;
goto V_153;
}
F_83 ( V_1 ) ;
V_1 -> V_157 = 1 ;
V_146 -> V_164 ++ ;
F_85 ( & V_146 -> V_154 ) ;
if ( V_113 & V_156 ) {
if ( F_88 ( V_1 ) ) {
F_94 ( V_1 ) ;
error = F_69 ( V_11 , type , & V_49 ) ;
if ( error )
return error ;
goto V_153;
}
}
V_161:
ASSERT ( ( V_145 == NULL ) || F_79 ( V_145 , V_88 ) ) ;
F_95 ( V_1 ) ;
* V_123 = V_1 ;
return 0 ;
}
void
F_94 (
struct V_12 * V_1 )
{
ASSERT ( V_1 -> V_157 > 0 ) ;
ASSERT ( F_96 ( V_1 ) ) ;
F_97 ( V_1 ) ;
if ( -- V_1 -> V_157 == 0 ) {
struct V_14 * V_146 = V_1 -> V_7 -> V_16 ;
F_98 ( V_1 ) ;
if ( F_99 ( & V_146 -> V_165 , & V_1 -> V_2 ) )
F_60 ( V_1 -> V_7 , V_166 ) ;
}
F_84 ( V_1 ) ;
}
void
F_100 (
T_1 * V_1 )
{
if ( ! V_1 )
return;
F_101 ( V_1 ) ;
F_83 ( V_1 ) ;
F_94 ( V_1 ) ;
}
STATIC void
F_102 (
struct V_107 * V_50 ,
struct V_167 * V_168 )
{
T_15 * V_169 = (struct V_170 * ) V_168 ;
T_1 * V_1 = V_169 -> V_171 ;
struct V_172 * V_173 = V_168 -> V_174 ;
if ( ( V_168 -> V_175 & V_176 ) &&
V_168 -> V_177 == V_169 -> V_178 ) {
F_103 ( & V_173 -> V_179 ) ;
if ( V_168 -> V_177 == V_169 -> V_178 )
F_104 ( V_173 , V_168 , V_180 ) ;
else
F_105 ( & V_173 -> V_179 ) ;
}
F_106 ( V_1 ) ;
}
int
F_107 (
struct V_12 * V_1 ,
struct V_107 * * V_108 )
{
struct V_10 * V_11 = V_1 -> V_7 ;
struct V_107 * V_50 ;
struct V_17 * V_124 ;
int error ;
ASSERT ( F_96 ( V_1 ) ) ;
ASSERT ( ! F_108 ( & V_1 -> V_127 ) ) ;
F_109 ( V_1 ) ;
* V_108 = NULL ;
F_110 ( V_1 ) ;
if ( F_111 ( V_11 ) ) {
struct V_167 * V_168 = & V_1 -> V_3 . V_4 ;
V_1 -> V_89 &= ~ V_181 ;
F_112 ( V_168 , V_180 ) ;
error = - V_111 ;
goto V_182;
}
error = F_44 ( V_11 , NULL , V_11 -> V_99 , V_1 -> V_98 ,
V_11 -> V_16 -> V_55 , 0 , & V_50 ,
& V_103 ) ;
if ( error )
goto V_182;
V_124 = V_50 -> V_53 + V_1 -> V_118 ;
error = F_45 ( V_11 , & V_1 -> V_19 , F_37 ( V_124 -> V_23 ) , 0 ,
V_183 , L_3 ) ;
if ( error ) {
F_113 ( V_50 ) ;
F_106 ( V_1 ) ;
F_114 ( V_11 , V_180 ) ;
return - V_111 ;
}
memcpy ( V_124 , & V_1 -> V_19 , sizeof( T_3 ) ) ;
V_1 -> V_89 &= ~ V_181 ;
F_115 ( V_11 -> V_184 , & V_1 -> V_3 . V_178 ,
& V_1 -> V_3 . V_4 . V_177 ) ;
if ( F_20 ( & V_11 -> V_62 ) ) {
struct V_65 * V_185 = (struct V_65 * ) V_124 ;
V_185 -> V_186 = F_9 ( V_1 -> V_3 . V_4 . V_177 ) ;
F_22 ( ( char * ) V_185 , sizeof( struct V_65 ) ,
V_66 ) ;
}
F_116 ( V_50 , F_102 ,
& V_1 -> V_3 . V_4 ) ;
if ( F_117 ( V_50 ) ) {
F_118 ( V_1 ) ;
F_119 ( V_11 , 0 ) ;
}
F_120 ( V_1 ) ;
* V_108 = V_50 ;
return 0 ;
V_182:
F_106 ( V_1 ) ;
return - V_111 ;
}
void
F_121 (
T_1 * V_187 ,
T_1 * V_188 )
{
if ( V_187 && V_188 ) {
ASSERT ( V_187 != V_188 ) ;
if ( F_37 ( V_187 -> V_19 . V_23 ) >
F_37 ( V_188 -> V_19 . V_23 ) ) {
F_81 ( & V_188 -> V_6 ) ;
F_122 ( & V_187 -> V_6 , V_189 ) ;
} else {
F_81 ( & V_187 -> V_6 ) ;
F_122 ( & V_188 -> V_6 , V_189 ) ;
}
} else if ( V_187 ) {
F_81 ( & V_187 -> V_6 ) ;
} else if ( V_188 ) {
F_81 ( & V_188 -> V_6 ) ;
}
}
int T_16
F_123 ( void )
{
V_9 =
F_124 ( sizeof( struct V_12 ) , L_4 ) ;
if ( ! V_9 )
goto V_190;
V_191 =
F_124 ( sizeof( struct V_192 ) , L_5 ) ;
if ( ! V_191 )
goto V_193;
return 0 ;
V_193:
F_125 ( V_9 ) ;
V_190:
return - V_100 ;
}
void
F_126 ( void )
{
F_125 ( V_191 ) ;
F_125 ( V_9 ) ;
}
