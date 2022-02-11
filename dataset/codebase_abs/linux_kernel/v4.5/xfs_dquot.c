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
int V_81 , error ;
T_7 * V_45 ;
T_4 * V_43 = * V_74 ;
ASSERT ( V_43 != NULL ) ;
F_25 ( V_1 ) ;
F_26 ( & V_79 , & V_78 ) ;
F_27 ( V_75 , V_82 ) ;
if ( ! F_28 ( V_1 -> V_4 , V_1 -> V_83 ) ) {
F_29 ( V_75 , V_82 ) ;
return - V_84 ;
}
F_30 ( V_43 , V_75 , V_82 ) ;
V_81 = 1 ;
error = F_31 ( V_43 , V_75 , V_76 ,
V_85 , V_86 ,
& V_78 , F_32 ( V_8 ) ,
& V_80 , & V_81 , & V_79 ) ;
if ( error )
goto V_87;
ASSERT ( V_80 . V_88 == V_85 ) ;
ASSERT ( V_81 == 1 ) ;
ASSERT ( ( V_80 . V_89 != V_90 ) &&
( V_80 . V_89 != V_91 ) ) ;
V_1 -> V_92 = F_33 ( V_8 , V_80 . V_89 ) ;
V_45 = F_34 ( V_43 , V_8 -> V_93 ,
V_1 -> V_92 ,
V_8 -> V_13 -> V_50 ,
0 ) ;
if ( ! V_45 ) {
error = - V_94 ;
goto V_95;
}
V_45 -> V_96 = & V_97 ;
F_14 ( V_43 , V_8 , F_35 ( V_1 -> V_16 . V_18 ) ,
V_1 -> V_83 & V_98 , V_45 ) ;
F_36 ( V_43 , V_45 ) ;
error = F_37 ( V_74 , & V_79 , NULL ) ;
if ( error )
goto V_95;
if ( * V_74 != V_43 ) {
V_43 = * V_74 ;
F_38 ( V_43 , V_45 ) ;
} else {
F_39 ( V_43 , V_45 ) ;
}
* V_77 = V_45 ;
return 0 ;
V_95:
F_40 ( & V_79 ) ;
V_87:
F_29 ( V_75 , V_82 ) ;
return error ;
}
STATIC int
F_41 (
struct V_7 * V_8 ,
struct V_99 * V_43 ,
struct V_9 * V_1 ,
T_5 V_100 ,
struct V_101 * * V_102 )
{
int error ;
struct V_14 * V_103 ;
struct V_60 * V_15 ;
int V_47 ;
error = F_42 ( V_8 , V_43 , V_8 -> V_93 , V_1 -> V_92 ,
V_8 -> V_13 -> V_50 ,
0 , V_102 , NULL ) ;
if ( error ) {
ASSERT ( * V_102 == NULL ) ;
return error ;
}
( * V_102 ) -> V_96 = & V_97 ;
ASSERT ( F_15 ( * V_102 ) ) ;
V_15 = (struct V_60 * ) ( * V_102 ) -> V_48 ;
for ( V_47 = 0 ; V_47 < V_8 -> V_13 -> V_49 ; V_47 ++ ) {
V_103 = & V_15 [ V_47 ] . V_51 ;
error = F_43 ( V_8 , V_103 , V_100 + V_47 ,
V_1 -> V_83 & V_98 ,
V_104 , L_1 ) ;
if ( error ) {
F_44 ( V_43 , * V_102 ) ;
return - V_105 ;
}
}
return 0 ;
}
STATIC int
F_45 (
T_4 * * V_74 ,
T_1 * V_1 ,
T_3 * * V_106 ,
T_7 * * V_77 ,
T_6 V_107 )
{
struct V_108 V_80 ;
int V_81 = 1 , error ;
struct V_101 * V_45 ;
struct V_109 * V_75 = F_46 ( V_1 ) ;
struct V_7 * V_8 = V_1 -> V_4 ;
T_5 V_44 = F_35 ( V_1 -> V_16 . V_18 ) ;
struct V_99 * V_43 = ( V_74 ? * V_74 : NULL ) ;
T_6 V_110 ;
V_1 -> V_111 = ( T_11 ) V_44 / V_8 -> V_13 -> V_49 ;
V_110 = F_47 ( V_75 ) ;
if ( ! F_28 ( V_1 -> V_4 , V_1 -> V_83 ) ) {
F_29 ( V_75 , V_110 ) ;
return - V_84 ;
}
error = F_48 ( V_75 , V_1 -> V_111 ,
V_85 , & V_80 , & V_81 , 0 ) ;
F_29 ( V_75 , V_110 ) ;
if ( error )
return error ;
ASSERT ( V_81 == 1 ) ;
ASSERT ( V_80 . V_88 == 1 ) ;
V_1 -> V_112 = ( V_44 % V_8 -> V_13 -> V_49 ) *
sizeof( T_8 ) ;
ASSERT ( V_80 . V_89 != V_90 ) ;
if ( V_80 . V_89 == V_91 ) {
if ( ! ( V_107 & V_113 ) )
return - V_114 ;
ASSERT ( V_43 ) ;
error = F_24 ( V_74 , V_8 , V_1 , V_75 ,
V_1 -> V_111 , & V_45 ) ;
if ( error )
return error ;
V_43 = * V_74 ;
} else {
F_49 ( V_1 ) ;
V_1 -> V_92 = F_33 ( V_8 , V_80 . V_89 ) ;
error = F_42 ( V_8 , V_43 , V_8 -> V_93 ,
V_1 -> V_92 ,
V_8 -> V_13 -> V_50 ,
0 , & V_45 , & V_97 ) ;
if ( error == - V_115 && ( V_107 & V_104 ) ) {
T_5 V_100 = ( T_5 ) V_80 . V_116 *
V_8 -> V_13 -> V_49 ;
ASSERT ( V_45 == NULL ) ;
error = F_41 ( V_8 , V_43 , V_1 , V_100 , & V_45 ) ;
}
if ( error ) {
ASSERT ( V_45 == NULL ) ;
return error ;
}
}
ASSERT ( F_15 ( V_45 ) ) ;
* V_77 = V_45 ;
* V_106 = V_45 -> V_48 + V_1 -> V_112 ;
return 0 ;
}
int
F_50 (
struct V_7 * V_8 ,
T_5 V_44 ,
T_6 type ,
T_6 V_107 ,
struct V_9 * * V_117 )
{
struct V_9 * V_1 ;
struct V_14 * V_118 ;
struct V_101 * V_45 ;
struct V_99 * V_43 = NULL ;
int error ;
V_1 = F_51 ( V_6 , V_119 ) ;
V_1 -> V_83 = type ;
V_1 -> V_16 . V_18 = F_12 ( V_44 ) ;
V_1 -> V_4 = V_8 ;
F_52 ( & V_1 -> V_2 ) ;
F_53 ( & V_1 -> V_3 ) ;
F_54 ( & V_1 -> V_120 ) ;
F_55 ( & V_1 -> V_121 ) ;
F_56 ( & V_1 -> V_121 ) ;
switch ( type ) {
case V_62 :
break;
case V_122 :
F_57 ( & V_1 -> V_3 , & V_123 ) ;
break;
case V_64 :
F_57 ( & V_1 -> V_3 , & V_124 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_58 ( V_8 , V_5 ) ;
F_59 ( V_1 ) ;
if ( V_107 & V_113 ) {
V_43 = F_60 ( V_8 , V_125 ) ;
error = F_61 ( V_43 , & F_62 ( V_8 ) -> V_126 ,
F_32 ( V_8 ) , 0 ) ;
if ( error )
goto V_95;
}
error = F_45 ( & V_43 , V_1 , & V_118 , & V_45 , V_107 ) ;
if ( error ) {
F_63 ( V_1 ) ;
goto V_95;
}
memcpy ( & V_1 -> V_16 , V_118 , sizeof( T_3 ) ) ;
F_64 ( V_1 ) ;
V_1 -> V_127 = F_11 ( V_118 -> V_32 ) ;
V_1 -> V_128 = F_11 ( V_118 -> V_36 ) ;
V_1 -> V_129 = F_11 ( V_118 -> V_40 ) ;
F_8 ( V_1 ) ;
F_65 ( V_45 , V_130 ) ;
ASSERT ( F_15 ( V_45 ) ) ;
F_44 ( V_43 , V_45 ) ;
if ( V_43 ) {
error = F_66 ( V_43 ) ;
if ( error )
goto V_87;
}
* V_117 = V_1 ;
return error ;
V_95:
if ( V_43 )
F_67 ( V_43 ) ;
V_87:
F_1 ( V_1 ) ;
* V_117 = NULL ;
return error ;
}
int
F_68 (
T_2 * V_8 ,
T_10 * V_131 ,
T_5 V_44 ,
T_6 type ,
T_6 V_107 ,
T_1 * * V_117 )
{
struct V_11 * V_132 = V_8 -> V_13 ;
struct V_133 * V_134 = F_69 ( V_132 , type ) ;
struct V_9 * V_1 ;
int error ;
ASSERT ( F_70 ( V_8 ) ) ;
if ( ( ! F_71 ( V_8 ) && type == V_62 ) ||
( ! F_72 ( V_8 ) && type == V_64 ) ||
( ! F_73 ( V_8 ) && type == V_122 ) ) {
return - V_84 ;
}
#ifdef F_10
if ( V_135 ) {
if ( ( V_136 == V_8 -> V_93 ) &&
( V_137 ++ % V_138 ) == 0 ) {
F_74 ( V_8 , L_2 ) ;
return - V_105 ;
}
}
ASSERT ( type == V_62 ||
type == V_64 ||
type == V_122 ) ;
if ( V_131 ) {
ASSERT ( F_75 ( V_131 , V_82 ) ) ;
ASSERT ( F_76 ( V_131 , type ) == NULL ) ;
}
#endif
V_139:
F_77 ( & V_132 -> V_140 ) ;
V_1 = F_78 ( V_134 , V_44 ) ;
if ( V_1 ) {
F_79 ( V_1 ) ;
if ( V_1 -> V_83 & V_141 ) {
F_80 ( V_1 ) ;
F_81 ( & V_132 -> V_140 ) ;
F_82 ( V_1 ) ;
F_83 ( 1 ) ;
goto V_139;
}
V_1 -> V_142 ++ ;
F_81 ( & V_132 -> V_140 ) ;
F_84 ( V_1 ) ;
F_58 ( V_8 , V_143 ) ;
* V_117 = V_1 ;
return 0 ;
}
F_81 ( & V_132 -> V_140 ) ;
F_58 ( V_8 , V_144 ) ;
if ( V_131 )
F_29 ( V_131 , V_82 ) ;
error = F_50 ( V_8 , V_44 , type , V_107 , & V_1 ) ;
if ( V_131 )
F_27 ( V_131 , V_82 ) ;
if ( error )
return error ;
if ( V_131 ) {
if ( F_28 ( V_8 , type ) ) {
struct V_9 * V_145 ;
V_145 = F_76 ( V_131 , type ) ;
if ( V_145 ) {
F_1 ( V_1 ) ;
V_1 = V_145 ;
F_79 ( V_1 ) ;
goto V_146;
}
} else {
F_1 ( V_1 ) ;
return - V_84 ;
}
}
F_77 ( & V_132 -> V_140 ) ;
error = F_85 ( V_134 , V_44 , V_1 ) ;
if ( F_86 ( error ) ) {
F_87 ( error != - V_147 ) ;
F_81 ( & V_132 -> V_140 ) ;
F_88 ( V_1 ) ;
F_1 ( V_1 ) ;
F_58 ( V_8 , V_148 ) ;
goto V_139;
}
F_79 ( V_1 ) ;
V_1 -> V_142 = 1 ;
V_132 -> V_149 ++ ;
F_81 ( & V_132 -> V_140 ) ;
V_146:
ASSERT ( ( V_131 == NULL ) || F_75 ( V_131 , V_82 ) ) ;
F_89 ( V_1 ) ;
* V_117 = V_1 ;
return 0 ;
}
void
F_90 (
struct V_9 * V_1 )
{
ASSERT ( V_1 -> V_142 > 0 ) ;
ASSERT ( F_91 ( V_1 ) ) ;
F_92 ( V_1 ) ;
if ( -- V_1 -> V_142 == 0 ) {
struct V_11 * V_132 = V_1 -> V_4 -> V_13 ;
F_93 ( V_1 ) ;
if ( F_94 ( & V_132 -> V_150 , & V_1 -> V_2 ) )
F_58 ( V_1 -> V_4 , V_151 ) ;
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
struct V_101 * V_45 ,
struct V_152 * V_153 )
{
T_15 * V_154 = (struct V_155 * ) V_153 ;
T_1 * V_1 = V_154 -> V_156 ;
struct V_157 * V_158 = V_153 -> V_159 ;
if ( ( V_153 -> V_160 & V_161 ) &&
V_153 -> V_162 == V_154 -> V_163 ) {
F_98 ( & V_158 -> V_164 ) ;
if ( V_153 -> V_162 == V_154 -> V_163 )
F_99 ( V_158 , V_153 , V_165 ) ;
else
F_100 ( & V_158 -> V_164 ) ;
}
F_101 ( V_1 ) ;
}
int
F_102 (
struct V_9 * V_1 ,
struct V_101 * * V_102 )
{
struct V_7 * V_8 = V_1 -> V_4 ;
struct V_101 * V_45 ;
struct V_14 * V_118 ;
int error ;
ASSERT ( F_91 ( V_1 ) ) ;
ASSERT ( ! F_103 ( & V_1 -> V_121 ) ) ;
F_104 ( V_1 ) ;
* V_102 = NULL ;
F_105 ( V_1 ) ;
if ( F_106 ( V_8 ) ) {
struct V_152 * V_153 = & V_1 -> V_166 . V_167 ;
V_1 -> V_83 &= ~ V_168 ;
F_107 ( V_153 , V_165 ) ;
error = - V_105 ;
goto V_169;
}
error = F_42 ( V_8 , NULL , V_8 -> V_93 , V_1 -> V_92 ,
V_8 -> V_13 -> V_50 , 0 , & V_45 ,
& V_97 ) ;
if ( error )
goto V_169;
V_118 = V_45 -> V_48 + V_1 -> V_112 ;
error = F_43 ( V_8 , & V_1 -> V_16 , F_35 ( V_118 -> V_18 ) , 0 ,
V_170 , L_3 ) ;
if ( error ) {
F_108 ( V_45 ) ;
F_101 ( V_1 ) ;
F_109 ( V_8 , V_165 ) ;
return - V_105 ;
}
memcpy ( V_118 , & V_1 -> V_16 , sizeof( T_3 ) ) ;
V_1 -> V_83 &= ~ V_168 ;
F_110 ( V_8 -> V_171 , & V_1 -> V_166 . V_163 ,
& V_1 -> V_166 . V_167 . V_162 ) ;
if ( F_18 ( & V_8 -> V_57 ) ) {
struct V_60 * V_172 = (struct V_60 * ) V_118 ;
V_172 -> V_173 = F_7 ( V_1 -> V_166 . V_167 . V_162 ) ;
F_20 ( ( char * ) V_172 , sizeof( struct V_60 ) ,
V_61 ) ;
}
F_111 ( V_45 , F_97 ,
& V_1 -> V_166 . V_167 ) ;
if ( F_112 ( V_45 ) ) {
F_113 ( V_1 ) ;
F_114 ( V_8 , 0 ) ;
}
F_115 ( V_1 ) ;
* V_102 = V_45 ;
return 0 ;
V_169:
F_101 ( V_1 ) ;
return - V_105 ;
}
void
F_116 (
T_1 * V_174 ,
T_1 * V_175 )
{
if ( V_174 && V_175 ) {
ASSERT ( V_174 != V_175 ) ;
if ( F_35 ( V_174 -> V_16 . V_18 ) >
F_35 ( V_175 -> V_16 . V_18 ) ) {
F_77 ( & V_175 -> V_3 ) ;
F_117 ( & V_174 -> V_3 , V_176 ) ;
} else {
F_77 ( & V_174 -> V_3 ) ;
F_117 ( & V_175 -> V_3 , V_176 ) ;
}
} else if ( V_174 ) {
F_77 ( & V_174 -> V_3 ) ;
} else if ( V_175 ) {
F_77 ( & V_175 -> V_3 ) ;
}
}
int T_16
F_118 ( void )
{
V_6 =
F_119 ( sizeof( struct V_9 ) , L_4 ) ;
if ( ! V_6 )
goto V_177;
V_178 =
F_119 ( sizeof( struct V_179 ) , L_5 ) ;
if ( ! V_178 )
goto V_180;
return 0 ;
V_180:
F_120 ( V_6 ) ;
V_177:
return - V_94 ;
}
void
F_121 ( void )
{
F_120 ( V_178 ) ;
F_120 ( V_6 ) ;
}
