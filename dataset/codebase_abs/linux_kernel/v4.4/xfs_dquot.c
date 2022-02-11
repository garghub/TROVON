void
F_1 (
T_1 * V_1 )
{
ASSERT ( F_2 ( & V_1 -> V_2 ) ) ;
F_3 ( & V_1 -> V_3 ) ;
F_4 ( V_1 -> V_4 , V_5 ) ;
F_5 ( V_6 , V_1 ) ;
}
void
F_6 (
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_14 * V_15 = & V_10 -> V_16 ;
int V_17 = 0 ;
ASSERT ( V_15 -> V_18 ) ;
if ( V_12 -> V_19 && ! V_15 -> V_20 ) {
V_15 -> V_20 = F_7 ( V_12 -> V_19 ) ;
V_17 = 1 ;
}
if ( V_12 -> V_21 && ! V_15 -> V_22 ) {
V_15 -> V_22 = F_7 ( V_12 -> V_21 ) ;
V_17 = 1 ;
}
if ( V_12 -> V_23 && ! V_15 -> V_24 )
V_15 -> V_24 = F_7 ( V_12 -> V_23 ) ;
if ( V_12 -> V_25 && ! V_15 -> V_26 )
V_15 -> V_26 = F_7 ( V_12 -> V_25 ) ;
if ( V_12 -> V_27 && ! V_15 -> V_28 )
V_15 -> V_28 = F_7 ( V_12 -> V_27 ) ;
if ( V_12 -> V_29 && ! V_15 -> V_30 )
V_15 -> V_30 = F_7 ( V_12 -> V_29 ) ;
if ( V_17 )
F_8 ( V_10 ) ;
}
void
F_9 (
T_2 * V_8 ,
T_3 * V_15 )
{
ASSERT ( V_15 -> V_18 ) ;
#ifdef F_10
if ( V_15 -> V_22 )
ASSERT ( F_11 ( V_15 -> V_20 ) <=
F_11 ( V_15 -> V_22 ) ) ;
if ( V_15 -> V_26 )
ASSERT ( F_11 ( V_15 -> V_24 ) <=
F_11 ( V_15 -> V_26 ) ) ;
if ( V_15 -> V_30 )
ASSERT ( F_11 ( V_15 -> V_28 ) <=
F_11 ( V_15 -> V_30 ) ) ;
#endif
if ( ! V_15 -> V_31 ) {
if ( ( V_15 -> V_20 &&
( F_11 ( V_15 -> V_32 ) >
F_11 ( V_15 -> V_20 ) ) ) ||
( V_15 -> V_22 &&
( F_11 ( V_15 -> V_32 ) >
F_11 ( V_15 -> V_22 ) ) ) ) {
V_15 -> V_31 = F_12 ( F_13 () +
V_8 -> V_13 -> V_33 ) ;
} else {
V_15 -> V_34 = 0 ;
}
} else {
if ( ( ! V_15 -> V_20 ||
( F_11 ( V_15 -> V_32 ) <=
F_11 ( V_15 -> V_20 ) ) ) &&
( ! V_15 -> V_22 ||
( F_11 ( V_15 -> V_32 ) <=
F_11 ( V_15 -> V_22 ) ) ) ) {
V_15 -> V_31 = 0 ;
}
}
if ( ! V_15 -> V_35 ) {
if ( ( V_15 -> V_24 &&
( F_11 ( V_15 -> V_36 ) >
F_11 ( V_15 -> V_24 ) ) ) ||
( V_15 -> V_26 &&
( F_11 ( V_15 -> V_36 ) >
F_11 ( V_15 -> V_26 ) ) ) ) {
V_15 -> V_35 = F_12 ( F_13 () +
V_8 -> V_13 -> V_37 ) ;
} else {
V_15 -> V_38 = 0 ;
}
} else {
if ( ( ! V_15 -> V_24 ||
( F_11 ( V_15 -> V_36 ) <=
F_11 ( V_15 -> V_24 ) ) ) &&
( ! V_15 -> V_26 ||
( F_11 ( V_15 -> V_36 ) <=
F_11 ( V_15 -> V_26 ) ) ) ) {
V_15 -> V_35 = 0 ;
}
}
if ( ! V_15 -> V_39 ) {
if ( ( V_15 -> V_28 &&
( F_11 ( V_15 -> V_40 ) >
F_11 ( V_15 -> V_28 ) ) ) ||
( V_15 -> V_30 &&
( F_11 ( V_15 -> V_40 ) >
F_11 ( V_15 -> V_30 ) ) ) ) {
V_15 -> V_39 = F_12 ( F_13 () +
V_8 -> V_13 -> V_41 ) ;
} else {
V_15 -> V_42 = 0 ;
}
} else {
if ( ( ! V_15 -> V_28 ||
( F_11 ( V_15 -> V_40 ) <=
F_11 ( V_15 -> V_28 ) ) ) &&
( ! V_15 -> V_30 ||
( F_11 ( V_15 -> V_40 ) <=
F_11 ( V_15 -> V_30 ) ) ) ) {
V_15 -> V_39 = 0 ;
}
}
}
STATIC void
F_14 (
T_4 * V_43 ,
T_2 * V_8 ,
T_5 V_44 ,
T_6 type ,
T_7 * V_45 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
T_8 * V_15 ;
int V_46 , V_47 ;
ASSERT ( V_43 ) ;
ASSERT ( F_15 ( V_45 ) ) ;
V_15 = V_45 -> V_48 ;
V_46 = V_44 - ( V_44 % V_12 -> V_49 ) ;
ASSERT ( V_46 >= 0 ) ;
memset ( V_15 , 0 , F_16 ( V_12 -> V_50 ) ) ;
for ( V_47 = 0 ; V_47 < V_12 -> V_49 ; V_47 ++ , V_15 ++ , V_46 ++ ) {
V_15 -> V_51 . V_52 = F_17 ( V_53 ) ;
V_15 -> V_51 . V_54 = V_55 ;
V_15 -> V_51 . V_18 = F_12 ( V_46 ) ;
V_15 -> V_51 . V_56 = type ;
if ( F_18 ( & V_8 -> V_57 ) ) {
F_19 ( & V_15 -> V_58 , & V_8 -> V_57 . V_59 ) ;
F_20 ( ( char * ) V_15 , sizeof( struct V_60 ) ,
V_61 ) ;
}
}
F_21 ( V_43 , V_45 ,
( type & V_62 ? V_63 :
( ( type & V_64 ) ? V_65 :
V_66 ) ) ) ;
F_22 ( V_43 , V_45 , 0 , F_16 ( V_12 -> V_50 ) - 1 ) ;
}
void
F_8 ( struct V_9 * V_1 )
{
T_9 V_67 ;
V_1 -> V_68 = F_11 ( V_1 -> V_16 . V_22 ) ;
V_1 -> V_69 = F_11 ( V_1 -> V_16 . V_20 ) ;
if ( ! V_1 -> V_69 ) {
V_1 -> V_69 = V_1 -> V_68 ;
F_23 ( V_1 -> V_69 , 100 ) ;
V_1 -> V_69 *= 95 ;
}
V_67 = V_1 -> V_68 ;
F_23 ( V_67 , 100 ) ;
V_1 -> V_70 [ V_71 ] = V_67 ;
V_1 -> V_70 [ V_72 ] = V_67 * 3 ;
V_1 -> V_70 [ V_73 ] = V_67 * 5 ;
}
STATIC int
F_24 (
T_4 * * V_74 ,
T_2 * V_8 ,
T_1 * V_1 ,
T_10 * V_75 ,
T_11 V_76 ,
T_7 * * V_77 )
{
T_12 V_78 ;
T_13 V_79 ;
T_14 V_80 ;
int V_81 , error , V_82 ;
T_7 * V_45 ;
T_4 * V_43 = * V_74 ;
ASSERT ( V_43 != NULL ) ;
F_25 ( V_1 ) ;
F_26 ( & V_79 , & V_78 ) ;
F_27 ( V_75 , V_83 ) ;
if ( ! F_28 ( V_1 -> V_4 , V_1 -> V_84 ) ) {
F_29 ( V_75 , V_83 ) ;
return - V_85 ;
}
F_30 ( V_43 , V_75 , V_83 ) ;
V_81 = 1 ;
error = F_31 ( V_43 , V_75 , V_76 ,
V_86 , V_87 ,
& V_78 , F_32 ( V_8 ) ,
& V_80 , & V_81 , & V_79 ) ;
if ( error )
goto V_88;
ASSERT ( V_80 . V_89 == V_86 ) ;
ASSERT ( V_81 == 1 ) ;
ASSERT ( ( V_80 . V_90 != V_91 ) &&
( V_80 . V_90 != V_92 ) ) ;
V_1 -> V_93 = F_33 ( V_8 , V_80 . V_90 ) ;
V_45 = F_34 ( V_43 , V_8 -> V_94 ,
V_1 -> V_93 ,
V_8 -> V_13 -> V_50 ,
0 ) ;
if ( ! V_45 ) {
error = - V_95 ;
goto V_96;
}
V_45 -> V_97 = & V_98 ;
F_14 ( V_43 , V_8 , F_35 ( V_1 -> V_16 . V_18 ) ,
V_1 -> V_84 & V_99 , V_45 ) ;
F_36 ( V_43 , V_45 ) ;
if ( ( error = F_37 ( V_74 , & V_79 , & V_82 ) ) ) {
goto V_96;
}
if ( V_82 ) {
V_43 = * V_74 ;
F_38 ( V_43 , V_45 ) ;
} else {
F_39 ( V_43 , V_45 ) ;
}
* V_77 = V_45 ;
return 0 ;
V_96:
F_40 ( & V_79 ) ;
V_88:
F_29 ( V_75 , V_83 ) ;
return error ;
}
STATIC int
F_41 (
struct V_7 * V_8 ,
struct V_100 * V_43 ,
struct V_9 * V_1 ,
T_5 V_101 ,
struct V_102 * * V_103 )
{
int error ;
struct V_14 * V_104 ;
struct V_60 * V_15 ;
int V_47 ;
error = F_42 ( V_8 , V_43 , V_8 -> V_94 , V_1 -> V_93 ,
V_8 -> V_13 -> V_50 ,
0 , V_103 , NULL ) ;
if ( error ) {
ASSERT ( * V_103 == NULL ) ;
return error ;
}
( * V_103 ) -> V_97 = & V_98 ;
ASSERT ( F_15 ( * V_103 ) ) ;
V_15 = (struct V_60 * ) ( * V_103 ) -> V_48 ;
for ( V_47 = 0 ; V_47 < V_8 -> V_13 -> V_49 ; V_47 ++ ) {
V_104 = & V_15 [ V_47 ] . V_51 ;
error = F_43 ( V_8 , V_104 , V_101 + V_47 ,
V_1 -> V_84 & V_99 ,
V_105 , L_1 ) ;
if ( error ) {
F_44 ( V_43 , * V_103 ) ;
return - V_106 ;
}
}
return 0 ;
}
STATIC int
F_45 (
T_4 * * V_74 ,
T_1 * V_1 ,
T_3 * * V_107 ,
T_7 * * V_77 ,
T_6 V_108 )
{
struct V_109 V_80 ;
int V_81 = 1 , error ;
struct V_102 * V_45 ;
struct V_110 * V_75 = F_46 ( V_1 ) ;
struct V_7 * V_8 = V_1 -> V_4 ;
T_5 V_44 = F_35 ( V_1 -> V_16 . V_18 ) ;
struct V_100 * V_43 = ( V_74 ? * V_74 : NULL ) ;
T_6 V_111 ;
V_1 -> V_112 = ( T_11 ) V_44 / V_8 -> V_13 -> V_49 ;
V_111 = F_47 ( V_75 ) ;
if ( ! F_28 ( V_1 -> V_4 , V_1 -> V_84 ) ) {
F_29 ( V_75 , V_111 ) ;
return - V_85 ;
}
error = F_48 ( V_75 , V_1 -> V_112 ,
V_86 , & V_80 , & V_81 , 0 ) ;
F_29 ( V_75 , V_111 ) ;
if ( error )
return error ;
ASSERT ( V_81 == 1 ) ;
ASSERT ( V_80 . V_89 == 1 ) ;
V_1 -> V_113 = ( V_44 % V_8 -> V_13 -> V_49 ) *
sizeof( T_8 ) ;
ASSERT ( V_80 . V_90 != V_91 ) ;
if ( V_80 . V_90 == V_92 ) {
if ( ! ( V_108 & V_114 ) )
return - V_115 ;
ASSERT ( V_43 ) ;
error = F_24 ( V_74 , V_8 , V_1 , V_75 ,
V_1 -> V_112 , & V_45 ) ;
if ( error )
return error ;
V_43 = * V_74 ;
} else {
F_49 ( V_1 ) ;
V_1 -> V_93 = F_33 ( V_8 , V_80 . V_90 ) ;
error = F_42 ( V_8 , V_43 , V_8 -> V_94 ,
V_1 -> V_93 ,
V_8 -> V_13 -> V_50 ,
0 , & V_45 , & V_98 ) ;
if ( error == - V_116 && ( V_108 & V_105 ) ) {
T_5 V_101 = ( T_5 ) V_80 . V_117 *
V_8 -> V_13 -> V_49 ;
ASSERT ( V_45 == NULL ) ;
error = F_41 ( V_8 , V_43 , V_1 , V_101 , & V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 == NULL ) ;
return error ;
}
}
ASSERT ( F_15 ( V_45 ) ) ;
* V_77 = V_45 ;
* V_107 = V_45 -> V_48 + V_1 -> V_113 ;
return 0 ;
}
int
F_50 (
struct V_7 * V_8 ,
T_5 V_44 ,
T_6 type ,
T_6 V_108 ,
struct V_9 * * V_118 )
{
struct V_9 * V_1 ;
struct V_14 * V_119 ;
struct V_102 * V_45 ;
struct V_100 * V_43 = NULL ;
int error ;
V_1 = F_51 ( V_6 , V_120 ) ;
V_1 -> V_84 = type ;
V_1 -> V_16 . V_18 = F_12 ( V_44 ) ;
V_1 -> V_4 = V_8 ;
F_52 ( & V_1 -> V_2 ) ;
F_53 ( & V_1 -> V_3 ) ;
F_54 ( & V_1 -> V_121 ) ;
F_55 ( & V_1 -> V_122 ) ;
F_56 ( & V_1 -> V_122 ) ;
switch ( type ) {
case V_62 :
break;
case V_123 :
F_57 ( & V_1 -> V_3 , & V_124 ) ;
break;
case V_64 :
F_57 ( & V_1 -> V_3 , & V_125 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_58 ( V_8 , V_5 ) ;
F_59 ( V_1 ) ;
if ( V_108 & V_114 ) {
V_43 = F_60 ( V_8 , V_126 ) ;
error = F_61 ( V_43 , & F_62 ( V_8 ) -> V_127 ,
F_32 ( V_8 ) , 0 ) ;
if ( error )
goto V_96;
}
error = F_45 ( & V_43 , V_1 , & V_119 , & V_45 , V_108 ) ;
if ( error ) {
F_63 ( V_1 ) ;
goto V_96;
}
memcpy ( & V_1 -> V_16 , V_119 , sizeof( T_3 ) ) ;
F_64 ( V_1 ) ;
V_1 -> V_128 = F_11 ( V_119 -> V_32 ) ;
V_1 -> V_129 = F_11 ( V_119 -> V_36 ) ;
V_1 -> V_130 = F_11 ( V_119 -> V_40 ) ;
F_8 ( V_1 ) ;
F_65 ( V_45 , V_131 ) ;
ASSERT ( F_15 ( V_45 ) ) ;
F_44 ( V_43 , V_45 ) ;
if ( V_43 ) {
error = F_66 ( V_43 ) ;
if ( error )
goto V_88;
}
* V_118 = V_1 ;
return error ;
V_96:
if ( V_43 )
F_67 ( V_43 ) ;
V_88:
F_1 ( V_1 ) ;
* V_118 = NULL ;
return error ;
}
int
F_68 (
T_2 * V_8 ,
T_10 * V_132 ,
T_5 V_44 ,
T_6 type ,
T_6 V_108 ,
T_1 * * V_118 )
{
struct V_11 * V_133 = V_8 -> V_13 ;
struct V_134 * V_135 = F_69 ( V_133 , type ) ;
struct V_9 * V_1 ;
int error ;
ASSERT ( F_70 ( V_8 ) ) ;
if ( ( ! F_71 ( V_8 ) && type == V_62 ) ||
( ! F_72 ( V_8 ) && type == V_64 ) ||
( ! F_73 ( V_8 ) && type == V_123 ) ) {
return - V_85 ;
}
#ifdef F_10
if ( V_136 ) {
if ( ( V_137 == V_8 -> V_94 ) &&
( V_138 ++ % V_139 ) == 0 ) {
F_74 ( V_8 , L_2 ) ;
return - V_106 ;
}
}
ASSERT ( type == V_62 ||
type == V_64 ||
type == V_123 ) ;
if ( V_132 ) {
ASSERT ( F_75 ( V_132 , V_83 ) ) ;
ASSERT ( F_76 ( V_132 , type ) == NULL ) ;
}
#endif
V_140:
F_77 ( & V_133 -> V_141 ) ;
V_1 = F_78 ( V_135 , V_44 ) ;
if ( V_1 ) {
F_79 ( V_1 ) ;
if ( V_1 -> V_84 & V_142 ) {
F_80 ( V_1 ) ;
F_81 ( & V_133 -> V_141 ) ;
F_82 ( V_1 ) ;
F_83 ( 1 ) ;
goto V_140;
}
V_1 -> V_143 ++ ;
F_81 ( & V_133 -> V_141 ) ;
F_84 ( V_1 ) ;
F_58 ( V_8 , V_144 ) ;
* V_118 = V_1 ;
return 0 ;
}
F_81 ( & V_133 -> V_141 ) ;
F_58 ( V_8 , V_145 ) ;
if ( V_132 )
F_29 ( V_132 , V_83 ) ;
error = F_50 ( V_8 , V_44 , type , V_108 , & V_1 ) ;
if ( V_132 )
F_27 ( V_132 , V_83 ) ;
if ( error )
return error ;
if ( V_132 ) {
if ( F_28 ( V_8 , type ) ) {
struct V_9 * V_146 ;
V_146 = F_76 ( V_132 , type ) ;
if ( V_146 ) {
F_1 ( V_1 ) ;
V_1 = V_146 ;
F_79 ( V_1 ) ;
goto V_147;
}
} else {
F_1 ( V_1 ) ;
return - V_85 ;
}
}
F_77 ( & V_133 -> V_141 ) ;
error = F_85 ( V_135 , V_44 , V_1 ) ;
if ( F_86 ( error ) ) {
F_87 ( error != - V_148 ) ;
F_81 ( & V_133 -> V_141 ) ;
F_88 ( V_1 ) ;
F_1 ( V_1 ) ;
F_58 ( V_8 , V_149 ) ;
goto V_140;
}
F_79 ( V_1 ) ;
V_1 -> V_143 = 1 ;
V_133 -> V_150 ++ ;
F_81 ( & V_133 -> V_141 ) ;
V_147:
ASSERT ( ( V_132 == NULL ) || F_75 ( V_132 , V_83 ) ) ;
F_89 ( V_1 ) ;
* V_118 = V_1 ;
return 0 ;
}
void
F_90 (
struct V_9 * V_1 )
{
ASSERT ( V_1 -> V_143 > 0 ) ;
ASSERT ( F_91 ( V_1 ) ) ;
F_92 ( V_1 ) ;
if ( -- V_1 -> V_143 == 0 ) {
struct V_11 * V_133 = V_1 -> V_4 -> V_13 ;
F_93 ( V_1 ) ;
if ( F_94 ( & V_133 -> V_151 , & V_1 -> V_2 ) )
F_58 ( V_1 -> V_4 , V_152 ) ;
}
F_80 ( V_1 ) ;
}
void
F_95 (
T_1 * V_1 )
{
if ( ! V_1 )
return;
F_96 ( V_1 ) ;
F_79 ( V_1 ) ;
F_90 ( V_1 ) ;
}
STATIC void
F_97 (
struct V_102 * V_45 ,
struct V_153 * V_154 )
{
T_15 * V_155 = (struct V_156 * ) V_154 ;
T_1 * V_1 = V_155 -> V_157 ;
struct V_158 * V_159 = V_154 -> V_160 ;
if ( ( V_154 -> V_161 & V_162 ) &&
V_154 -> V_163 == V_155 -> V_164 ) {
F_98 ( & V_159 -> V_165 ) ;
if ( V_154 -> V_163 == V_155 -> V_164 )
F_99 ( V_159 , V_154 , V_166 ) ;
else
F_100 ( & V_159 -> V_165 ) ;
}
F_101 ( V_1 ) ;
}
int
F_102 (
struct V_9 * V_1 ,
struct V_102 * * V_103 )
{
struct V_7 * V_8 = V_1 -> V_4 ;
struct V_102 * V_45 ;
struct V_14 * V_119 ;
int error ;
ASSERT ( F_91 ( V_1 ) ) ;
ASSERT ( ! F_103 ( & V_1 -> V_122 ) ) ;
F_104 ( V_1 ) ;
* V_103 = NULL ;
F_105 ( V_1 ) ;
if ( F_106 ( V_8 ) ) {
struct V_153 * V_154 = & V_1 -> V_167 . V_168 ;
V_1 -> V_84 &= ~ V_169 ;
F_107 ( V_154 , V_166 ) ;
error = - V_106 ;
goto V_170;
}
error = F_42 ( V_8 , NULL , V_8 -> V_94 , V_1 -> V_93 ,
V_8 -> V_13 -> V_50 , 0 , & V_45 ,
& V_98 ) ;
if ( error )
goto V_170;
V_119 = V_45 -> V_48 + V_1 -> V_113 ;
error = F_43 ( V_8 , & V_1 -> V_16 , F_35 ( V_119 -> V_18 ) , 0 ,
V_171 , L_3 ) ;
if ( error ) {
F_108 ( V_45 ) ;
F_101 ( V_1 ) ;
F_109 ( V_8 , V_166 ) ;
return - V_106 ;
}
memcpy ( V_119 , & V_1 -> V_16 , sizeof( T_3 ) ) ;
V_1 -> V_84 &= ~ V_169 ;
F_110 ( V_8 -> V_172 , & V_1 -> V_167 . V_164 ,
& V_1 -> V_167 . V_168 . V_163 ) ;
if ( F_18 ( & V_8 -> V_57 ) ) {
struct V_60 * V_173 = (struct V_60 * ) V_119 ;
V_173 -> V_174 = F_7 ( V_1 -> V_167 . V_168 . V_163 ) ;
F_20 ( ( char * ) V_173 , sizeof( struct V_60 ) ,
V_61 ) ;
}
F_111 ( V_45 , F_97 ,
& V_1 -> V_167 . V_168 ) ;
if ( F_112 ( V_45 ) ) {
F_113 ( V_1 ) ;
F_114 ( V_8 , 0 ) ;
}
F_115 ( V_1 ) ;
* V_103 = V_45 ;
return 0 ;
V_170:
F_101 ( V_1 ) ;
return - V_106 ;
}
void
F_116 (
T_1 * V_175 ,
T_1 * V_176 )
{
if ( V_175 && V_176 ) {
ASSERT ( V_175 != V_176 ) ;
if ( F_35 ( V_175 -> V_16 . V_18 ) >
F_35 ( V_176 -> V_16 . V_18 ) ) {
F_77 ( & V_176 -> V_3 ) ;
F_117 ( & V_175 -> V_3 , V_177 ) ;
} else {
F_77 ( & V_175 -> V_3 ) ;
F_117 ( & V_176 -> V_3 , V_177 ) ;
}
} else if ( V_175 ) {
F_77 ( & V_175 -> V_3 ) ;
} else if ( V_176 ) {
F_77 ( & V_176 -> V_3 ) ;
}
}
int T_16
F_118 ( void )
{
V_6 =
F_119 ( sizeof( struct V_9 ) , L_4 ) ;
if ( ! V_6 )
goto V_178;
V_179 =
F_119 ( sizeof( struct V_180 ) , L_5 ) ;
if ( ! V_179 )
goto V_181;
return 0 ;
V_181:
F_120 ( V_6 ) ;
V_178:
return - V_95 ;
}
void
F_121 ( void )
{
F_120 ( V_179 ) ;
F_120 ( V_6 ) ;
}
