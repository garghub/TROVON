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
struct V_17 * V_18 ;
int V_19 = 0 ;
ASSERT ( V_15 -> V_20 ) ;
V_18 = F_7 ( V_10 , V_12 ) ;
if ( V_18 -> V_21 && ! V_15 -> V_22 ) {
V_15 -> V_22 = F_8 ( V_18 -> V_21 ) ;
V_19 = 1 ;
}
if ( V_18 -> V_23 && ! V_15 -> V_24 ) {
V_15 -> V_24 = F_8 ( V_18 -> V_23 ) ;
V_19 = 1 ;
}
if ( V_18 -> V_25 && ! V_15 -> V_26 )
V_15 -> V_26 = F_8 ( V_18 -> V_25 ) ;
if ( V_18 -> V_27 && ! V_15 -> V_28 )
V_15 -> V_28 = F_8 ( V_18 -> V_27 ) ;
if ( V_18 -> V_29 && ! V_15 -> V_30 )
V_15 -> V_30 = F_8 ( V_18 -> V_29 ) ;
if ( V_18 -> V_31 && ! V_15 -> V_32 )
V_15 -> V_32 = F_8 ( V_18 -> V_31 ) ;
if ( V_19 )
F_9 ( V_10 ) ;
}
void
F_10 (
T_2 * V_8 ,
T_3 * V_15 )
{
ASSERT ( V_15 -> V_20 ) ;
#ifdef F_11
if ( V_15 -> V_24 )
ASSERT ( F_12 ( V_15 -> V_22 ) <=
F_12 ( V_15 -> V_24 ) ) ;
if ( V_15 -> V_28 )
ASSERT ( F_12 ( V_15 -> V_26 ) <=
F_12 ( V_15 -> V_28 ) ) ;
if ( V_15 -> V_32 )
ASSERT ( F_12 ( V_15 -> V_30 ) <=
F_12 ( V_15 -> V_32 ) ) ;
#endif
if ( ! V_15 -> V_33 ) {
if ( ( V_15 -> V_22 &&
( F_12 ( V_15 -> V_34 ) >
F_12 ( V_15 -> V_22 ) ) ) ||
( V_15 -> V_24 &&
( F_12 ( V_15 -> V_34 ) >
F_12 ( V_15 -> V_24 ) ) ) ) {
V_15 -> V_33 = F_13 ( F_14 () +
V_8 -> V_13 -> V_35 ) ;
} else {
V_15 -> V_36 = 0 ;
}
} else {
if ( ( ! V_15 -> V_22 ||
( F_12 ( V_15 -> V_34 ) <=
F_12 ( V_15 -> V_22 ) ) ) &&
( ! V_15 -> V_24 ||
( F_12 ( V_15 -> V_34 ) <=
F_12 ( V_15 -> V_24 ) ) ) ) {
V_15 -> V_33 = 0 ;
}
}
if ( ! V_15 -> V_37 ) {
if ( ( V_15 -> V_26 &&
( F_12 ( V_15 -> V_38 ) >
F_12 ( V_15 -> V_26 ) ) ) ||
( V_15 -> V_28 &&
( F_12 ( V_15 -> V_38 ) >
F_12 ( V_15 -> V_28 ) ) ) ) {
V_15 -> V_37 = F_13 ( F_14 () +
V_8 -> V_13 -> V_39 ) ;
} else {
V_15 -> V_40 = 0 ;
}
} else {
if ( ( ! V_15 -> V_26 ||
( F_12 ( V_15 -> V_38 ) <=
F_12 ( V_15 -> V_26 ) ) ) &&
( ! V_15 -> V_28 ||
( F_12 ( V_15 -> V_38 ) <=
F_12 ( V_15 -> V_28 ) ) ) ) {
V_15 -> V_37 = 0 ;
}
}
if ( ! V_15 -> V_41 ) {
if ( ( V_15 -> V_30 &&
( F_12 ( V_15 -> V_42 ) >
F_12 ( V_15 -> V_30 ) ) ) ||
( V_15 -> V_32 &&
( F_12 ( V_15 -> V_42 ) >
F_12 ( V_15 -> V_32 ) ) ) ) {
V_15 -> V_41 = F_13 ( F_14 () +
V_8 -> V_13 -> V_43 ) ;
} else {
V_15 -> V_44 = 0 ;
}
} else {
if ( ( ! V_15 -> V_30 ||
( F_12 ( V_15 -> V_42 ) <=
F_12 ( V_15 -> V_30 ) ) ) &&
( ! V_15 -> V_32 ||
( F_12 ( V_15 -> V_42 ) <=
F_12 ( V_15 -> V_32 ) ) ) ) {
V_15 -> V_41 = 0 ;
}
}
}
STATIC void
F_15 (
T_4 * V_45 ,
T_2 * V_8 ,
T_5 V_46 ,
T_6 type ,
T_7 * V_47 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
T_8 * V_15 ;
T_5 V_48 ;
int V_49 ;
ASSERT ( V_45 ) ;
ASSERT ( F_16 ( V_47 ) ) ;
V_15 = V_47 -> V_50 ;
V_48 = V_46 - ( V_46 % V_12 -> V_51 ) ;
memset ( V_15 , 0 , F_17 ( V_12 -> V_52 ) ) ;
for ( V_49 = 0 ; V_49 < V_12 -> V_51 ; V_49 ++ , V_15 ++ , V_48 ++ ) {
V_15 -> V_53 . V_54 = F_18 ( V_55 ) ;
V_15 -> V_53 . V_56 = V_57 ;
V_15 -> V_53 . V_20 = F_13 ( V_48 ) ;
V_15 -> V_53 . V_58 = type ;
if ( F_19 ( & V_8 -> V_59 ) ) {
F_20 ( & V_15 -> V_60 , & V_8 -> V_59 . V_61 ) ;
F_21 ( ( char * ) V_15 , sizeof( struct V_62 ) ,
V_63 ) ;
}
}
F_22 ( V_45 , V_47 ,
( type & V_64 ? V_65 :
( ( type & V_66 ) ? V_67 :
V_68 ) ) ) ;
F_23 ( V_45 , V_47 , 0 , F_17 ( V_12 -> V_52 ) - 1 ) ;
}
void
F_9 ( struct V_9 * V_1 )
{
T_9 V_69 ;
V_1 -> V_70 = F_12 ( V_1 -> V_16 . V_24 ) ;
V_1 -> V_71 = F_12 ( V_1 -> V_16 . V_22 ) ;
if ( ! V_1 -> V_71 ) {
V_1 -> V_71 = V_1 -> V_70 ;
F_24 ( V_1 -> V_71 , 100 ) ;
V_1 -> V_71 *= 95 ;
}
V_69 = V_1 -> V_70 ;
F_24 ( V_69 , 100 ) ;
V_1 -> V_72 [ V_73 ] = V_69 ;
V_1 -> V_72 [ V_74 ] = V_69 * 3 ;
V_1 -> V_72 [ V_75 ] = V_69 * 5 ;
}
STATIC int
F_25 (
T_4 * * V_76 ,
T_2 * V_8 ,
T_1 * V_1 ,
T_10 * V_77 ,
T_11 V_78 ,
T_7 * * V_79 )
{
T_12 V_80 ;
T_13 V_81 ;
T_14 V_82 ;
int V_83 , error ;
T_7 * V_47 ;
T_4 * V_45 = * V_76 ;
ASSERT ( V_45 != NULL ) ;
F_26 ( V_1 ) ;
F_27 ( & V_81 , & V_80 ) ;
F_28 ( V_77 , V_84 ) ;
if ( ! F_29 ( V_1 -> V_4 , V_1 -> V_85 ) ) {
F_30 ( V_77 , V_84 ) ;
return - V_86 ;
}
F_31 ( V_45 , V_77 , V_84 ) ;
V_83 = 1 ;
error = F_32 ( V_45 , V_77 , V_78 ,
V_87 , V_88 ,
& V_80 , F_33 ( V_8 ) ,
& V_82 , & V_83 , & V_81 ) ;
if ( error )
goto V_89;
ASSERT ( V_82 . V_90 == V_87 ) ;
ASSERT ( V_83 == 1 ) ;
ASSERT ( ( V_82 . V_91 != V_92 ) &&
( V_82 . V_91 != V_93 ) ) ;
V_1 -> V_94 = F_34 ( V_8 , V_82 . V_91 ) ;
V_47 = F_35 ( V_45 , V_8 -> V_95 ,
V_1 -> V_94 ,
V_8 -> V_13 -> V_52 ,
0 ) ;
if ( ! V_47 ) {
error = - V_96 ;
goto V_97;
}
V_47 -> V_98 = & V_99 ;
F_15 ( V_45 , V_8 , F_36 ( V_1 -> V_16 . V_20 ) ,
V_1 -> V_85 & V_100 , V_47 ) ;
F_37 ( V_45 , V_47 ) ;
error = F_38 ( V_76 , & V_81 , NULL ) ;
if ( error )
goto V_97;
if ( * V_76 != V_45 ) {
V_45 = * V_76 ;
F_39 ( V_45 , V_47 ) ;
} else {
F_40 ( V_45 , V_47 ) ;
}
* V_79 = V_47 ;
return 0 ;
V_97:
F_41 ( & V_81 ) ;
V_89:
F_30 ( V_77 , V_84 ) ;
return error ;
}
STATIC int
F_42 (
struct V_7 * V_8 ,
struct V_101 * V_45 ,
struct V_9 * V_1 ,
T_5 V_102 ,
struct V_103 * * V_104 )
{
int error ;
struct V_14 * V_105 ;
struct V_62 * V_15 ;
int V_49 ;
error = F_43 ( V_8 , V_45 , V_8 -> V_95 , V_1 -> V_94 ,
V_8 -> V_13 -> V_52 ,
0 , V_104 , NULL ) ;
if ( error ) {
ASSERT ( * V_104 == NULL ) ;
return error ;
}
( * V_104 ) -> V_98 = & V_99 ;
ASSERT ( F_16 ( * V_104 ) ) ;
V_15 = (struct V_62 * ) ( * V_104 ) -> V_50 ;
for ( V_49 = 0 ; V_49 < V_8 -> V_13 -> V_51 ; V_49 ++ ) {
V_105 = & V_15 [ V_49 ] . V_53 ;
error = F_44 ( V_8 , V_105 , V_102 + V_49 ,
V_1 -> V_85 & V_100 ,
V_106 , L_1 ) ;
if ( error ) {
F_45 ( V_45 , * V_104 ) ;
return - V_107 ;
}
}
return 0 ;
}
STATIC int
F_46 (
T_4 * * V_76 ,
T_1 * V_1 ,
T_3 * * V_108 ,
T_7 * * V_79 ,
T_6 V_109 )
{
struct V_110 V_82 ;
int V_83 = 1 , error ;
struct V_103 * V_47 ;
struct V_111 * V_77 ;
struct V_7 * V_8 = V_1 -> V_4 ;
T_5 V_46 = F_36 ( V_1 -> V_16 . V_20 ) ;
struct V_101 * V_45 = ( V_76 ? * V_76 : NULL ) ;
T_6 V_112 ;
V_77 = F_47 ( V_1 -> V_4 , V_1 -> V_85 ) ;
V_1 -> V_113 = ( T_11 ) V_46 / V_8 -> V_13 -> V_51 ;
V_112 = F_48 ( V_77 ) ;
if ( ! F_29 ( V_1 -> V_4 , V_1 -> V_85 ) ) {
F_30 ( V_77 , V_112 ) ;
return - V_86 ;
}
error = F_49 ( V_77 , V_1 -> V_113 ,
V_87 , & V_82 , & V_83 , 0 ) ;
F_30 ( V_77 , V_112 ) ;
if ( error )
return error ;
ASSERT ( V_83 == 1 ) ;
ASSERT ( V_82 . V_90 == 1 ) ;
V_1 -> V_114 = ( V_46 % V_8 -> V_13 -> V_51 ) *
sizeof( T_8 ) ;
ASSERT ( V_82 . V_91 != V_92 ) ;
if ( V_82 . V_91 == V_93 ) {
if ( ! ( V_109 & V_115 ) )
return - V_116 ;
ASSERT ( V_45 ) ;
error = F_25 ( V_76 , V_8 , V_1 , V_77 ,
V_1 -> V_113 , & V_47 ) ;
if ( error )
return error ;
V_45 = * V_76 ;
} else {
F_50 ( V_1 ) ;
V_1 -> V_94 = F_34 ( V_8 , V_82 . V_91 ) ;
error = F_43 ( V_8 , V_45 , V_8 -> V_95 ,
V_1 -> V_94 ,
V_8 -> V_13 -> V_52 ,
0 , & V_47 , & V_99 ) ;
if ( error == - V_117 && ( V_109 & V_106 ) ) {
T_5 V_102 = ( T_5 ) V_82 . V_118 *
V_8 -> V_13 -> V_51 ;
ASSERT ( V_47 == NULL ) ;
error = F_42 ( V_8 , V_45 , V_1 , V_102 , & V_47 ) ;
}
if ( error ) {
ASSERT ( V_47 == NULL ) ;
return error ;
}
}
ASSERT ( F_16 ( V_47 ) ) ;
* V_79 = V_47 ;
* V_108 = V_47 -> V_50 + V_1 -> V_114 ;
return 0 ;
}
int
F_51 (
struct V_7 * V_8 ,
T_5 V_46 ,
T_6 type ,
T_6 V_109 ,
struct V_9 * * V_119 )
{
struct V_9 * V_1 ;
struct V_14 * V_120 ;
struct V_103 * V_47 ;
struct V_101 * V_45 = NULL ;
int error ;
V_1 = F_52 ( V_6 , V_121 ) ;
V_1 -> V_85 = type ;
V_1 -> V_16 . V_20 = F_13 ( V_46 ) ;
V_1 -> V_4 = V_8 ;
F_53 ( & V_1 -> V_2 ) ;
F_54 ( & V_1 -> V_3 ) ;
F_55 ( & V_1 -> V_122 ) ;
F_56 ( & V_1 -> V_123 ) ;
F_57 ( & V_1 -> V_123 ) ;
switch ( type ) {
case V_64 :
break;
case V_124 :
F_58 ( & V_1 -> V_3 , & V_125 ) ;
break;
case V_66 :
F_58 ( & V_1 -> V_3 , & V_126 ) ;
break;
default:
ASSERT ( 0 ) ;
break;
}
F_59 ( V_8 , V_5 ) ;
F_60 ( V_1 ) ;
if ( V_109 & V_115 ) {
V_45 = F_61 ( V_8 , V_127 ) ;
error = F_62 ( V_45 , & F_63 ( V_8 ) -> V_128 ,
F_33 ( V_8 ) , 0 ) ;
if ( error )
goto V_97;
}
error = F_46 ( & V_45 , V_1 , & V_120 , & V_47 , V_109 ) ;
if ( error ) {
F_64 ( V_1 ) ;
goto V_97;
}
memcpy ( & V_1 -> V_16 , V_120 , sizeof( T_3 ) ) ;
F_65 ( V_1 ) ;
V_1 -> V_129 = F_12 ( V_120 -> V_34 ) ;
V_1 -> V_130 = F_12 ( V_120 -> V_38 ) ;
V_1 -> V_131 = F_12 ( V_120 -> V_42 ) ;
F_9 ( V_1 ) ;
F_66 ( V_47 , V_132 ) ;
ASSERT ( F_16 ( V_47 ) ) ;
F_45 ( V_45 , V_47 ) ;
if ( V_45 ) {
error = F_67 ( V_45 ) ;
if ( error )
goto V_89;
}
* V_119 = V_1 ;
return error ;
V_97:
if ( V_45 )
F_68 ( V_45 ) ;
V_89:
F_1 ( V_1 ) ;
* V_119 = NULL ;
return error ;
}
int
F_69 (
T_2 * V_8 ,
T_6 type ,
T_5 * V_46 ,
T_15 V_133 )
{
struct V_111 * V_77 ;
T_12 V_134 ;
T_15 V_135 ;
T_6 V_136 ;
T_5 V_137 ;
int error = 0 ;
V_137 = * V_46 + 1 ;
if ( V_137 % V_8 -> V_13 -> V_51 ) {
* V_46 = V_137 ;
return 0 ;
}
V_134 = ( T_12 ) V_137 / V_8 -> V_13 -> V_51 ;
V_77 = F_47 ( V_8 , type ) ;
V_136 = F_48 ( V_77 ) ;
V_135 = F_70 ( F_71 ( V_77 ) , F_72 ( V_8 , V_134 ) ,
V_133 , V_138 ) ;
if ( V_135 < 0 )
error = V_135 ;
F_30 ( V_77 , V_136 ) ;
if ( error )
return ( error == - V_139 ? - V_116 : error ) ;
* V_46 = F_73 ( V_8 , V_135 ) * V_8 -> V_13 -> V_51 ;
return 0 ;
}
int
F_74 (
T_2 * V_8 ,
T_10 * V_140 ,
T_5 V_46 ,
T_6 type ,
T_6 V_109 ,
T_1 * * V_119 )
{
struct V_11 * V_141 = V_8 -> V_13 ;
struct V_142 * V_143 = F_75 ( V_141 , type ) ;
struct V_9 * V_1 ;
T_15 V_133 = 0 ;
int error ;
ASSERT ( F_76 ( V_8 ) ) ;
if ( ( ! F_77 ( V_8 ) && type == V_64 ) ||
( ! F_78 ( V_8 ) && type == V_66 ) ||
( ! F_79 ( V_8 ) && type == V_124 ) ) {
return - V_86 ;
}
#ifdef F_11
if ( V_144 ) {
if ( ( V_145 == V_8 -> V_95 ) &&
( V_146 ++ % V_147 ) == 0 ) {
F_80 ( V_8 , L_2 ) ;
return - V_107 ;
}
}
ASSERT ( type == V_64 ||
type == V_66 ||
type == V_124 ) ;
if ( V_140 ) {
ASSERT ( F_81 ( V_140 , V_84 ) ) ;
ASSERT ( F_82 ( V_140 , type ) == NULL ) ;
}
#endif
if ( V_109 & V_148 ) {
struct V_111 * V_77 ;
T_11 V_149 ;
T_6 V_112 ;
V_77 = F_47 ( V_8 , type ) ;
V_112 = F_48 ( V_77 ) ;
error = F_83 ( V_77 , & V_149 , V_150 ) ;
F_30 ( V_77 , V_112 ) ;
if ( error )
return error ;
V_133 = F_72 ( V_8 , V_149 ) ;
}
V_151:
F_84 ( & V_141 -> V_152 ) ;
V_1 = F_85 ( V_143 , V_46 ) ;
if ( V_1 ) {
F_86 ( V_1 ) ;
if ( V_1 -> V_85 & V_153 ) {
F_87 ( V_1 ) ;
F_88 ( & V_141 -> V_152 ) ;
F_89 ( V_1 ) ;
F_90 ( 1 ) ;
goto V_151;
}
if ( V_109 & V_148 ) {
if ( F_91 ( V_1 ) ) {
F_87 ( V_1 ) ;
F_88 ( & V_141 -> V_152 ) ;
error = F_69 ( V_8 , type , & V_46 , V_133 ) ;
if ( error )
return error ;
goto V_151;
}
}
V_1 -> V_154 ++ ;
F_88 ( & V_141 -> V_152 ) ;
F_92 ( V_1 ) ;
F_59 ( V_8 , V_155 ) ;
* V_119 = V_1 ;
return 0 ;
}
F_88 ( & V_141 -> V_152 ) ;
F_59 ( V_8 , V_156 ) ;
if ( V_140 )
F_30 ( V_140 , V_84 ) ;
error = F_51 ( V_8 , V_46 , type , V_109 , & V_1 ) ;
if ( V_140 )
F_28 ( V_140 , V_84 ) ;
if ( error == - V_116 && ( V_109 & V_148 ) ) {
error = F_69 ( V_8 , type , & V_46 , V_133 ) ;
if ( ! error )
goto V_151;
}
if ( error )
return error ;
if ( V_140 ) {
if ( F_29 ( V_8 , type ) ) {
struct V_9 * V_157 ;
V_157 = F_82 ( V_140 , type ) ;
if ( V_157 ) {
F_1 ( V_1 ) ;
V_1 = V_157 ;
F_86 ( V_1 ) ;
goto V_158;
}
} else {
F_1 ( V_1 ) ;
return - V_86 ;
}
}
F_84 ( & V_141 -> V_152 ) ;
error = F_93 ( V_143 , V_46 , V_1 ) ;
if ( F_94 ( error ) ) {
F_95 ( error != - V_159 ) ;
F_88 ( & V_141 -> V_152 ) ;
F_96 ( V_1 ) ;
F_1 ( V_1 ) ;
F_59 ( V_8 , V_160 ) ;
goto V_151;
}
F_86 ( V_1 ) ;
V_1 -> V_154 = 1 ;
V_141 -> V_161 ++ ;
F_88 ( & V_141 -> V_152 ) ;
if ( V_109 & V_148 ) {
if ( F_91 ( V_1 ) ) {
F_97 ( V_1 ) ;
error = F_69 ( V_8 , type , & V_46 , V_133 ) ;
if ( error )
return error ;
goto V_151;
}
}
V_158:
ASSERT ( ( V_140 == NULL ) || F_81 ( V_140 , V_84 ) ) ;
F_98 ( V_1 ) ;
* V_119 = V_1 ;
return 0 ;
}
void
F_97 (
struct V_9 * V_1 )
{
ASSERT ( V_1 -> V_154 > 0 ) ;
ASSERT ( F_99 ( V_1 ) ) ;
F_100 ( V_1 ) ;
if ( -- V_1 -> V_154 == 0 ) {
struct V_11 * V_141 = V_1 -> V_4 -> V_13 ;
F_101 ( V_1 ) ;
if ( F_102 ( & V_141 -> V_162 , & V_1 -> V_2 ) )
F_59 ( V_1 -> V_4 , V_163 ) ;
}
F_87 ( V_1 ) ;
}
void
F_103 (
T_1 * V_1 )
{
if ( ! V_1 )
return;
F_104 ( V_1 ) ;
F_86 ( V_1 ) ;
F_97 ( V_1 ) ;
}
STATIC void
F_105 (
struct V_103 * V_47 ,
struct V_164 * V_165 )
{
T_16 * V_166 = (struct V_167 * ) V_165 ;
T_1 * V_1 = V_166 -> V_168 ;
struct V_169 * V_170 = V_165 -> V_171 ;
if ( ( V_165 -> V_172 & V_173 ) &&
V_165 -> V_174 == V_166 -> V_175 ) {
F_106 ( & V_170 -> V_176 ) ;
if ( V_165 -> V_174 == V_166 -> V_175 )
F_107 ( V_170 , V_165 , V_177 ) ;
else
F_108 ( & V_170 -> V_176 ) ;
}
F_109 ( V_1 ) ;
}
int
F_110 (
struct V_9 * V_1 ,
struct V_103 * * V_104 )
{
struct V_7 * V_8 = V_1 -> V_4 ;
struct V_103 * V_47 ;
struct V_14 * V_120 ;
int error ;
ASSERT ( F_99 ( V_1 ) ) ;
ASSERT ( ! F_111 ( & V_1 -> V_123 ) ) ;
F_112 ( V_1 ) ;
* V_104 = NULL ;
F_113 ( V_1 ) ;
if ( F_114 ( V_8 ) ) {
struct V_164 * V_165 = & V_1 -> V_178 . V_179 ;
V_1 -> V_85 &= ~ V_180 ;
F_115 ( V_165 , V_177 ) ;
error = - V_107 ;
goto V_181;
}
error = F_43 ( V_8 , NULL , V_8 -> V_95 , V_1 -> V_94 ,
V_8 -> V_13 -> V_52 , 0 , & V_47 ,
& V_99 ) ;
if ( error )
goto V_181;
V_120 = V_47 -> V_50 + V_1 -> V_114 ;
error = F_44 ( V_8 , & V_1 -> V_16 , F_36 ( V_120 -> V_20 ) , 0 ,
V_182 , L_3 ) ;
if ( error ) {
F_116 ( V_47 ) ;
F_109 ( V_1 ) ;
F_117 ( V_8 , V_177 ) ;
return - V_107 ;
}
memcpy ( V_120 , & V_1 -> V_16 , sizeof( T_3 ) ) ;
V_1 -> V_85 &= ~ V_180 ;
F_118 ( V_8 -> V_183 , & V_1 -> V_178 . V_175 ,
& V_1 -> V_178 . V_179 . V_174 ) ;
if ( F_19 ( & V_8 -> V_59 ) ) {
struct V_62 * V_184 = (struct V_62 * ) V_120 ;
V_184 -> V_185 = F_8 ( V_1 -> V_178 . V_179 . V_174 ) ;
F_21 ( ( char * ) V_184 , sizeof( struct V_62 ) ,
V_63 ) ;
}
F_119 ( V_47 , F_105 ,
& V_1 -> V_178 . V_179 ) ;
if ( F_120 ( V_47 ) ) {
F_121 ( V_1 ) ;
F_122 ( V_8 , 0 ) ;
}
F_123 ( V_1 ) ;
* V_104 = V_47 ;
return 0 ;
V_181:
F_109 ( V_1 ) ;
return - V_107 ;
}
void
F_124 (
T_1 * V_186 ,
T_1 * V_187 )
{
if ( V_186 && V_187 ) {
ASSERT ( V_186 != V_187 ) ;
if ( F_36 ( V_186 -> V_16 . V_20 ) >
F_36 ( V_187 -> V_16 . V_20 ) ) {
F_84 ( & V_187 -> V_3 ) ;
F_125 ( & V_186 -> V_3 , V_188 ) ;
} else {
F_84 ( & V_186 -> V_3 ) ;
F_125 ( & V_187 -> V_3 , V_188 ) ;
}
} else if ( V_186 ) {
F_84 ( & V_186 -> V_3 ) ;
} else if ( V_187 ) {
F_84 ( & V_187 -> V_3 ) ;
}
}
int T_17
F_126 ( void )
{
V_6 =
F_127 ( sizeof( struct V_9 ) , L_4 ) ;
if ( ! V_6 )
goto V_189;
V_190 =
F_127 ( sizeof( struct V_191 ) , L_5 ) ;
if ( ! V_190 )
goto V_192;
return 0 ;
V_192:
F_128 ( V_6 ) ;
V_189:
return - V_96 ;
}
void
F_129 ( void )
{
F_128 ( V_190 ) ;
F_128 ( V_6 ) ;
}
