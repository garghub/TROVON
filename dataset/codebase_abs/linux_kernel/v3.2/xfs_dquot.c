STATIC T_1 *
F_1 (
T_2 * V_1 ,
T_3 V_2 ,
T_4 type )
{
T_1 * V_3 ;
T_5 V_4 ;
V_4 = F_2 ( & V_3 ) ;
V_3 -> V_5 = type ;
V_3 -> V_6 . V_7 = F_3 ( V_2 ) ;
V_3 -> V_8 = V_1 ;
if ( V_4 ) {
F_4 ( & V_3 -> V_9 ) ;
F_5 ( & V_3 -> V_10 ) ;
F_6 ( & V_3 -> V_11 ) ;
F_7 ( & V_3 -> V_12 ) ;
F_8 ( & V_3 -> V_12 ) ;
F_9 ( V_3 ) ;
} else {
V_3 -> V_13 = 0 ;
V_3 -> V_14 = 0 ;
F_4 ( & V_3 -> V_15 ) ;
F_4 ( & V_3 -> V_16 ) ;
V_3 -> V_17 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_19 = NULL ;
V_3 -> V_20 = NULL ;
V_3 -> V_21 = 0 ;
V_3 -> V_22 = 0 ;
V_3 -> V_23 = 0 ;
F_10 ( & V_3 -> V_24 , 0 ) ;
V_3 -> V_25 = NULL ;
ASSERT ( F_11 ( & V_3 -> V_9 ) ) ;
F_12 ( V_3 ) ;
}
if ( ! ( type & V_26 ) )
F_13 ( & V_3 -> V_10 , & V_27 ) ;
return ( V_3 ) ;
}
void
F_14 (
T_1 * V_3 )
{
ASSERT ( F_11 ( & V_3 -> V_9 ) ) ;
F_15 ( & V_3 -> V_10 ) ;
F_16 ( V_28 -> V_29 , V_3 ) ;
F_17 ( & V_28 -> V_30 ) ;
}
STATIC void
F_18 (
T_3 V_2 ,
T_4 type ,
T_6 * V_31 )
{
V_31 -> V_32 . V_33 = F_19 ( V_34 ) ;
V_31 -> V_32 . V_35 = V_36 ;
V_31 -> V_32 . V_7 = F_3 ( V_2 ) ;
V_31 -> V_32 . V_37 = type ;
}
void
F_20 (
T_2 * V_1 ,
T_7 * V_31 )
{
T_8 * V_38 = V_1 -> V_39 ;
ASSERT ( V_31 -> V_7 ) ;
if ( V_38 -> V_40 && ! V_31 -> V_41 )
V_31 -> V_41 = F_21 ( V_38 -> V_40 ) ;
if ( V_38 -> V_42 && ! V_31 -> V_43 )
V_31 -> V_43 = F_21 ( V_38 -> V_42 ) ;
if ( V_38 -> V_44 && ! V_31 -> V_45 )
V_31 -> V_45 = F_21 ( V_38 -> V_44 ) ;
if ( V_38 -> V_46 && ! V_31 -> V_47 )
V_31 -> V_47 = F_21 ( V_38 -> V_46 ) ;
if ( V_38 -> V_48 && ! V_31 -> V_49 )
V_31 -> V_49 = F_21 ( V_38 -> V_48 ) ;
if ( V_38 -> V_50 && ! V_31 -> V_51 )
V_31 -> V_51 = F_21 ( V_38 -> V_50 ) ;
}
void
F_22 (
T_2 * V_1 ,
T_7 * V_31 )
{
ASSERT ( V_31 -> V_7 ) ;
#ifdef F_23
if ( V_31 -> V_43 )
ASSERT ( F_24 ( V_31 -> V_41 ) <=
F_24 ( V_31 -> V_43 ) ) ;
if ( V_31 -> V_47 )
ASSERT ( F_24 ( V_31 -> V_45 ) <=
F_24 ( V_31 -> V_47 ) ) ;
if ( V_31 -> V_51 )
ASSERT ( F_24 ( V_31 -> V_49 ) <=
F_24 ( V_31 -> V_51 ) ) ;
#endif
if ( ! V_31 -> V_52 ) {
if ( ( V_31 -> V_41 &&
( F_24 ( V_31 -> V_53 ) >=
F_24 ( V_31 -> V_41 ) ) ) ||
( V_31 -> V_43 &&
( F_24 ( V_31 -> V_53 ) >=
F_24 ( V_31 -> V_43 ) ) ) ) {
V_31 -> V_52 = F_3 ( F_25 () +
V_1 -> V_39 -> V_54 ) ;
} else {
V_31 -> V_55 = 0 ;
}
} else {
if ( ( ! V_31 -> V_41 ||
( F_24 ( V_31 -> V_53 ) <
F_24 ( V_31 -> V_41 ) ) ) &&
( ! V_31 -> V_43 ||
( F_24 ( V_31 -> V_53 ) <
F_24 ( V_31 -> V_43 ) ) ) ) {
V_31 -> V_52 = 0 ;
}
}
if ( ! V_31 -> V_56 ) {
if ( ( V_31 -> V_45 &&
( F_24 ( V_31 -> V_57 ) >=
F_24 ( V_31 -> V_45 ) ) ) ||
( V_31 -> V_47 &&
( F_24 ( V_31 -> V_57 ) >=
F_24 ( V_31 -> V_47 ) ) ) ) {
V_31 -> V_56 = F_3 ( F_25 () +
V_1 -> V_39 -> V_58 ) ;
} else {
V_31 -> V_59 = 0 ;
}
} else {
if ( ( ! V_31 -> V_45 ||
( F_24 ( V_31 -> V_57 ) <
F_24 ( V_31 -> V_45 ) ) ) &&
( ! V_31 -> V_47 ||
( F_24 ( V_31 -> V_57 ) <
F_24 ( V_31 -> V_47 ) ) ) ) {
V_31 -> V_56 = 0 ;
}
}
if ( ! V_31 -> V_60 ) {
if ( ( V_31 -> V_49 &&
( F_24 ( V_31 -> V_61 ) >=
F_24 ( V_31 -> V_49 ) ) ) ||
( V_31 -> V_51 &&
( F_24 ( V_31 -> V_61 ) >=
F_24 ( V_31 -> V_51 ) ) ) ) {
V_31 -> V_60 = F_3 ( F_25 () +
V_1 -> V_39 -> V_62 ) ;
} else {
V_31 -> V_63 = 0 ;
}
} else {
if ( ( ! V_31 -> V_49 ||
( F_24 ( V_31 -> V_61 ) <
F_24 ( V_31 -> V_49 ) ) ) &&
( ! V_31 -> V_51 ||
( F_24 ( V_31 -> V_61 ) <
F_24 ( V_31 -> V_51 ) ) ) ) {
V_31 -> V_60 = 0 ;
}
}
}
STATIC void
F_26 (
T_9 * V_64 ,
T_2 * V_1 ,
T_3 V_2 ,
T_4 type ,
T_10 * V_65 )
{
struct V_66 * V_38 = V_1 -> V_39 ;
T_6 * V_31 ;
int V_67 , V_68 ;
ASSERT ( V_64 ) ;
ASSERT ( F_27 ( V_65 ) ) ;
V_31 = V_65 -> V_69 ;
V_67 = V_2 - ( V_2 % V_38 -> V_70 ) ;
ASSERT ( V_67 >= 0 ) ;
memset ( V_31 , 0 , F_28 ( V_38 -> V_71 ) ) ;
for ( V_68 = 0 ; V_68 < V_38 -> V_70 ; V_68 ++ , V_31 ++ , V_67 ++ )
F_18 ( V_67 , type , V_31 ) ;
F_29 ( V_64 , V_65 ,
( type & V_26 ? V_72 :
( ( type & V_73 ) ? V_74 :
V_75 ) ) ) ;
F_30 ( V_64 , V_65 , 0 , F_28 ( V_38 -> V_71 ) - 1 ) ;
}
STATIC int
F_31 (
T_9 * * V_76 ,
T_2 * V_1 ,
T_1 * V_3 ,
T_11 * V_77 ,
T_12 V_78 ,
T_10 * * V_79 )
{
T_13 V_80 ;
T_14 V_81 ;
T_15 V_82 ;
int V_83 , error , V_84 ;
T_10 * V_65 ;
T_9 * V_64 = * V_76 ;
ASSERT ( V_64 != NULL ) ;
F_32 ( V_3 ) ;
F_33 ( & V_81 , & V_80 ) ;
F_34 ( V_77 , V_85 ) ;
if ( F_35 ( V_3 ) ) {
F_36 ( V_77 , V_85 ) ;
return ( V_86 ) ;
}
F_37 ( V_64 , V_77 , V_85 ) ;
V_83 = 1 ;
error = F_38 ( V_64 , V_77 , V_78 ,
V_87 , V_88 ,
& V_80 , F_39 ( V_1 ) ,
& V_82 , & V_83 , & V_81 ) ;
if ( error )
goto V_89;
ASSERT ( V_82 . V_90 == V_87 ) ;
ASSERT ( V_83 == 1 ) ;
ASSERT ( ( V_82 . V_91 != V_92 ) &&
( V_82 . V_91 != V_93 ) ) ;
V_3 -> V_14 = F_40 ( V_1 , V_82 . V_91 ) ;
V_65 = F_41 ( V_64 , V_1 -> V_94 ,
V_3 -> V_14 ,
V_1 -> V_39 -> V_71 ,
0 ) ;
error = F_42 ( V_65 ) ;
if ( error )
goto V_95;
F_26 ( V_64 , V_1 , F_43 ( V_3 -> V_6 . V_7 ) ,
V_3 -> V_5 & V_96 , V_65 ) ;
F_44 ( V_64 , V_65 ) ;
if ( ( error = F_45 ( V_76 , & V_81 , & V_84 ) ) ) {
goto V_95;
}
if ( V_84 ) {
V_64 = * V_76 ;
F_46 ( V_64 , V_65 ) ;
} else {
F_47 ( V_64 , V_65 ) ;
}
* V_79 = V_65 ;
return 0 ;
V_95:
F_48 ( & V_81 ) ;
V_89:
F_36 ( V_77 , V_85 ) ;
return ( error ) ;
}
STATIC int
F_49 (
T_9 * * V_76 ,
T_1 * V_3 ,
T_7 * * V_97 ,
T_10 * * V_79 ,
T_4 V_98 )
{
T_15 V_82 ;
int V_83 = 1 , error ;
T_10 * V_65 ;
T_11 * V_77 = F_50 ( V_3 ) ;
T_2 * V_1 = V_3 -> V_8 ;
T_7 * V_99 ;
T_3 V_2 = F_43 ( V_3 -> V_6 . V_7 ) ;
T_9 * V_64 = ( V_76 ? * V_76 : NULL ) ;
V_3 -> V_18 = ( T_12 ) V_2 / V_1 -> V_39 -> V_70 ;
F_34 ( V_77 , V_100 ) ;
if ( F_35 ( V_3 ) ) {
F_36 ( V_77 , V_100 ) ;
return V_86 ;
}
error = F_51 ( V_77 , V_3 -> V_18 ,
V_87 , & V_82 , & V_83 , 0 ) ;
F_36 ( V_77 , V_100 ) ;
if ( error )
return error ;
ASSERT ( V_83 == 1 ) ;
ASSERT ( V_82 . V_90 == 1 ) ;
V_3 -> V_17 = ( V_2 % V_1 -> V_39 -> V_70 ) *
sizeof( T_6 ) ;
ASSERT ( V_82 . V_91 != V_92 ) ;
if ( V_82 . V_91 == V_93 ) {
if ( ! ( V_98 & V_101 ) )
return V_102 ;
ASSERT ( V_64 ) ;
error = F_31 ( V_76 , V_1 , V_3 , V_77 ,
V_3 -> V_18 , & V_65 ) ;
if ( error )
return error ;
V_64 = * V_76 ;
} else {
F_52 ( V_3 ) ;
V_3 -> V_14 = F_40 ( V_1 , V_82 . V_91 ) ;
error = F_53 ( V_1 , V_64 , V_1 -> V_94 ,
V_3 -> V_14 ,
V_1 -> V_39 -> V_71 ,
0 , & V_65 ) ;
if ( error || ! V_65 )
return F_54 ( error ) ;
}
ASSERT ( F_27 ( V_65 ) ) ;
V_99 = V_65 -> V_69 + V_3 -> V_17 ;
error = F_55 ( V_1 , V_99 , V_2 , V_3 -> V_5 & V_96 ,
V_98 & ( V_103 | V_104 ) ,
L_1 ) ;
if ( error ) {
if ( ! ( V_98 & V_103 ) ) {
F_56 ( V_64 , V_65 ) ;
return F_54 ( V_105 ) ;
}
}
* V_79 = V_65 ;
* V_97 = V_99 ;
return ( 0 ) ;
}
STATIC int
F_57 (
T_9 * * V_76 ,
T_3 V_2 ,
T_1 * V_3 ,
T_4 V_98 )
{
T_7 * V_106 ;
T_10 * V_65 ;
int error ;
T_9 * V_64 ;
ASSERT ( V_76 ) ;
F_58 ( V_3 ) ;
if ( ( error = F_49 ( V_76 , V_3 , & V_106 , & V_65 , V_98 ) ) ) {
return ( error ) ;
}
V_64 = * V_76 ;
memcpy ( & V_3 -> V_6 , V_106 , sizeof( T_7 ) ) ;
ASSERT ( F_43 ( V_3 -> V_6 . V_7 ) == V_2 ) ;
F_59 ( V_3 ) ;
V_3 -> V_21 = F_24 ( V_106 -> V_53 ) ;
V_3 -> V_22 = F_24 ( V_106 -> V_57 ) ;
V_3 -> V_23 = F_24 ( V_106 -> V_61 ) ;
F_60 ( V_65 , V_107 ) ;
ASSERT ( F_27 ( V_65 ) ) ;
F_56 ( V_64 , V_65 ) ;
return ( error ) ;
}
STATIC int
F_61 (
T_2 * V_1 ,
T_3 V_2 ,
T_4 type ,
T_4 V_98 ,
T_1 * * V_108 )
{
T_1 * V_3 ;
int error ;
T_9 * V_64 ;
int V_109 = 0 ;
V_3 = F_1 ( V_1 , V_2 , type ) ;
V_64 = NULL ;
if ( V_98 & V_101 ) {
V_64 = F_62 ( V_1 , V_110 ) ;
error = F_63 ( V_64 , F_39 ( V_1 ) ,
F_64 ( V_1 ) +
F_28 ( V_1 -> V_39 -> V_71 ) - 1 +
128 ,
0 ,
V_111 ,
V_112 ) ;
if ( error ) {
V_109 = 0 ;
goto V_89;
}
V_109 = V_113 ;
}
if ( ( error = F_57 ( & V_64 , V_2 , V_3 , V_98 ) ) ) {
F_65 ( V_3 ) ;
V_109 |= V_114 ;
goto V_89;
}
if ( V_64 ) {
if ( ( error = F_66 ( V_64 , V_113 ) ) )
goto V_95;
}
* V_108 = V_3 ;
return ( 0 ) ;
V_89:
ASSERT ( error ) ;
if ( V_64 )
F_67 ( V_64 , V_109 ) ;
V_95:
F_14 ( V_3 ) ;
* V_108 = NULL ;
return ( error ) ;
}
STATIC int
F_68 (
T_2 * V_1 ,
T_3 V_2 ,
T_16 * V_115 ,
T_1 * * V_108 )
{
T_1 * V_3 ;
T_4 V_116 ;
ASSERT ( F_69 ( & V_115 -> V_117 ) ) ;
V_116 = V_118 ;
F_70 (dqp, &qh->qh_list, q_hashlist) {
if ( F_43 ( V_3 -> V_6 . V_7 ) == V_2 && V_3 -> V_8 == V_1 ) {
F_71 ( V_3 ) ;
ASSERT ( ! F_11 ( & V_3 -> V_15 ) ) ;
F_72 ( V_3 ) ;
if ( V_3 -> V_13 == 0 ) {
ASSERT ( ! F_11 ( & V_3 -> V_9 ) ) ;
if ( ! F_73 ( & V_28 -> V_119 ) ) {
F_74 ( V_3 ) ;
V_3 -> V_5 |= V_120 ;
F_75 ( V_3 ) ;
F_76 ( & V_28 -> V_119 ) ;
F_72 ( V_3 ) ;
V_3 -> V_5 &= ~ ( V_120 ) ;
}
V_116 = V_121 ;
}
ASSERT ( F_43 ( V_3 -> V_6 . V_7 ) == V_2 ) ;
if ( V_116 ) {
if ( V_3 -> V_13 != 0 ) {
F_77 ( & V_28 -> V_119 ) ;
V_116 = V_118 ;
} else {
F_78 ( V_3 ) ;
F_79 ( & V_3 -> V_9 ) ;
V_28 -> V_122 -- ;
}
}
F_80 ( V_3 ) ;
if ( V_116 )
F_77 ( & V_28 -> V_119 ) ;
ASSERT ( F_69 ( & V_115 -> V_117 ) ) ;
F_81 ( & V_3 -> V_16 , & V_115 -> V_123 ) ;
F_82 ( V_3 ) ;
* V_108 = V_3 ;
return 0 ;
}
}
* V_108 = NULL ;
ASSERT ( F_69 ( & V_115 -> V_117 ) ) ;
return ( 1 ) ;
}
int
F_83 (
T_2 * V_1 ,
T_11 * V_124 ,
T_3 V_2 ,
T_4 type ,
T_4 V_98 ,
T_1 * * V_108 )
{
T_1 * V_3 ;
T_16 * V_125 ;
T_4 V_126 ;
int error ;
ASSERT ( F_84 ( V_1 ) ) ;
if ( ( ! F_85 ( V_1 ) && type == V_26 ) ||
( ! F_86 ( V_1 ) && type == V_73 ) ||
( ! F_87 ( V_1 ) && type == V_127 ) ) {
return ( V_86 ) ;
}
V_125 = F_88 ( V_1 , V_2 , type ) ;
#ifdef F_23
if ( V_128 ) {
if ( ( V_129 == V_1 -> V_94 ) &&
( V_130 ++ % V_131 ) == 0 ) {
F_89 ( V_1 , L_2 ) ;
return ( V_105 ) ;
}
}
#endif
V_132:
#ifdef F_23
ASSERT ( type == V_26 ||
type == V_73 ||
type == V_127 ) ;
if ( V_124 ) {
ASSERT ( F_90 ( V_124 , V_85 ) ) ;
if ( type == V_26 )
ASSERT ( V_124 -> V_133 == NULL ) ;
else
ASSERT ( V_124 -> V_134 == NULL ) ;
}
#endif
F_76 ( & V_125 -> V_117 ) ;
if ( F_68 ( V_1 , V_2 , V_125 , V_108 ) == 0 ) {
F_91 ( V_135 . V_136 ) ;
ASSERT ( * V_108 ) ;
ASSERT ( F_92 ( * V_108 ) ) ;
F_77 ( & V_125 -> V_117 ) ;
F_93 ( * V_108 ) ;
return ( 0 ) ;
}
F_91 ( V_135 . V_137 ) ;
if ( V_124 )
F_36 ( V_124 , V_85 ) ;
V_126 = V_125 -> V_138 ;
F_77 ( & V_125 -> V_117 ) ;
if ( ( error = F_61 ( V_1 , V_2 , type ,
V_98 & ( V_101 | V_103 |
V_104 ) ,
& V_3 ) ) ) {
if ( V_124 )
F_34 ( V_124 , V_85 ) ;
return ( error ) ;
}
if ( V_98 & V_139 ) {
ASSERT ( V_2 == 0 ) ;
ASSERT ( ! V_124 ) ;
goto V_140;
}
if ( V_124 ) {
F_34 ( V_124 , V_85 ) ;
if ( type == V_26 ) {
if ( ! F_85 ( V_1 ) ) {
F_14 ( V_3 ) ;
return F_54 ( V_86 ) ;
}
if ( V_124 -> V_133 ) {
F_14 ( V_3 ) ;
V_3 = V_124 -> V_133 ;
F_72 ( V_3 ) ;
goto V_140;
}
} else {
if ( ! F_94 ( V_1 ) ) {
F_14 ( V_3 ) ;
return F_54 ( V_86 ) ;
}
if ( V_124 -> V_134 ) {
F_14 ( V_3 ) ;
V_3 = V_124 -> V_134 ;
F_72 ( V_3 ) ;
goto V_140;
}
}
}
F_76 ( & V_125 -> V_117 ) ;
if ( V_126 != V_125 -> V_138 ) {
T_1 * V_141 ;
if ( F_68 ( V_1 , V_2 , V_125 , & V_141 ) == 0 ) {
F_95 ( V_141 ) ;
F_77 ( & V_125 -> V_117 ) ;
F_14 ( V_3 ) ;
F_91 ( V_135 . V_142 ) ;
goto V_132;
}
}
ASSERT ( F_69 ( & V_125 -> V_117 ) ) ;
V_3 -> V_25 = V_125 ;
F_96 ( & V_3 -> V_16 , & V_125 -> V_123 ) ;
V_125 -> V_138 ++ ;
F_76 ( & V_1 -> V_39 -> V_143 ) ;
F_72 ( V_3 ) ;
V_3 -> V_13 = 1 ;
F_96 ( & V_3 -> V_15 , & V_1 -> V_39 -> V_144 ) ;
V_1 -> V_39 -> V_145 ++ ;
F_77 ( & V_1 -> V_39 -> V_143 ) ;
F_77 ( & V_125 -> V_117 ) ;
V_140:
ASSERT ( ( V_124 == NULL ) || F_90 ( V_124 , V_85 ) ) ;
F_97 ( V_3 ) ;
* V_108 = V_3 ;
return ( 0 ) ;
}
void
F_95 (
T_1 * V_3 )
{
T_1 * V_146 ;
ASSERT ( V_3 -> V_13 > 0 ) ;
ASSERT ( F_92 ( V_3 ) ) ;
F_98 ( V_3 ) ;
if ( V_3 -> V_13 != 1 ) {
V_3 -> V_13 -- ;
F_75 ( V_3 ) ;
return;
}
if ( ! F_73 ( & V_28 -> V_119 ) ) {
F_99 ( V_3 ) ;
F_75 ( V_3 ) ;
F_76 ( & V_28 -> V_119 ) ;
F_72 ( V_3 ) ;
}
while ( 1 ) {
V_146 = NULL ;
if ( -- V_3 -> V_13 == 0 ) {
F_100 ( V_3 ) ;
F_101 ( & V_3 -> V_9 , & V_28 -> V_147 ) ;
V_28 -> V_122 ++ ;
if ( ( V_146 = V_3 -> V_20 ) ) {
F_72 ( V_146 ) ;
V_3 -> V_20 = NULL ;
}
}
F_75 ( V_3 ) ;
if ( ! V_146 )
break;
V_3 = V_146 ;
}
F_77 ( & V_28 -> V_119 ) ;
}
void
F_102 (
T_1 * V_3 )
{
if ( ! V_3 )
return;
F_103 ( V_3 ) ;
F_72 ( V_3 ) ;
F_95 ( V_3 ) ;
}
STATIC void
F_104 (
struct V_148 * V_65 ,
struct V_149 * V_150 )
{
T_17 * V_151 = (struct V_152 * ) V_150 ;
T_1 * V_3 = V_151 -> V_153 ;
struct V_154 * V_155 = V_150 -> V_156 ;
if ( ( V_150 -> V_157 & V_158 ) &&
V_150 -> V_159 == V_151 -> V_160 ) {
F_105 ( & V_155 -> V_161 ) ;
if ( V_150 -> V_159 == V_151 -> V_160 )
F_106 ( V_155 , V_150 ) ;
else
F_107 ( & V_155 -> V_161 ) ;
}
F_108 ( V_3 ) ;
}
int
F_109 (
T_1 * V_3 ,
T_4 V_98 )
{
struct V_162 * V_1 = V_3 -> V_8 ;
struct V_148 * V_65 ;
struct V_163 * V_106 ;
int error ;
ASSERT ( F_92 ( V_3 ) ) ;
ASSERT ( ! F_110 ( & V_3 -> V_12 ) ) ;
F_111 ( V_3 ) ;
if ( ! F_112 ( V_3 ) ||
( ! ( V_98 & V_164 ) && F_113 ( & V_3 -> V_24 ) > 0 ) ) {
F_108 ( V_3 ) ;
return 0 ;
}
F_114 ( V_3 ) ;
if ( F_115 ( V_1 ) ) {
V_3 -> V_5 &= ~ V_165 ;
F_108 ( V_3 ) ;
return F_54 ( V_105 ) ;
}
error = F_53 ( V_1 , NULL , V_1 -> V_94 , V_3 -> V_14 ,
V_1 -> V_39 -> V_71 , 0 , & V_65 ) ;
if ( error ) {
ASSERT ( error != V_102 ) ;
F_108 ( V_3 ) ;
return error ;
}
V_106 = V_65 -> V_69 + V_3 -> V_17 ;
error = F_55 ( V_1 , & V_3 -> V_6 , F_43 ( V_106 -> V_7 ) , 0 ,
V_104 , L_3 ) ;
if ( error ) {
F_116 ( V_65 ) ;
F_108 ( V_3 ) ;
F_117 ( V_1 , V_166 ) ;
return F_54 ( V_105 ) ;
}
memcpy ( V_106 , & V_3 -> V_6 , sizeof( T_7 ) ) ;
V_3 -> V_5 &= ~ V_165 ;
F_118 ( V_1 -> V_167 , & V_3 -> V_168 . V_160 ,
& V_3 -> V_168 . V_169 . V_159 ) ;
F_119 ( V_65 , F_104 ,
& V_3 -> V_168 . V_169 ) ;
if ( F_120 ( V_65 ) ) {
F_121 ( V_3 ) ;
F_122 ( V_1 , 0 ) ;
}
if ( V_98 & V_164 )
error = F_123 ( V_65 ) ;
else
F_124 ( V_65 ) ;
F_116 ( V_65 ) ;
F_125 ( V_3 ) ;
return error ;
}
int
F_126 (
T_1 * V_3 )
{
return F_73 ( & V_3 -> V_10 ) ;
}
void
F_72 (
T_1 * V_3 )
{
F_76 ( & V_3 -> V_10 ) ;
}
void
F_75 (
T_1 * V_3 )
{
F_77 ( & ( V_3 -> V_10 ) ) ;
if ( V_3 -> V_168 . V_153 == V_3 ) {
F_127 ( V_3 -> V_168 . V_169 . V_156 ,
( V_170 * ) & ( V_3 -> V_168 ) ) ;
}
}
void
F_128 (
T_1 * V_3 )
{
F_77 ( & ( V_3 -> V_10 ) ) ;
}
void
F_129 (
T_1 * V_171 ,
T_1 * V_172 )
{
if ( V_171 && V_172 ) {
ASSERT ( V_171 != V_172 ) ;
if ( F_43 ( V_171 -> V_6 . V_7 ) >
F_43 ( V_172 -> V_6 . V_7 ) ) {
F_76 ( & V_172 -> V_10 ) ;
F_130 ( & V_171 -> V_10 , V_173 ) ;
} else {
F_76 ( & V_171 -> V_10 ) ;
F_130 ( & V_172 -> V_10 , V_173 ) ;
}
} else if ( V_171 ) {
F_76 ( & V_171 -> V_10 ) ;
} else if ( V_172 ) {
F_76 ( & V_172 -> V_10 ) ;
}
}
int
F_131 (
T_1 * V_3 )
{
T_16 * V_115 = V_3 -> V_25 ;
T_2 * V_1 = V_3 -> V_8 ;
ASSERT ( F_69 ( & V_1 -> V_39 -> V_143 ) ) ;
ASSERT ( F_69 ( & V_3 -> V_25 -> V_117 ) ) ;
F_72 ( V_3 ) ;
if ( V_3 -> V_13 != 0 ) {
F_75 ( V_3 ) ;
F_77 ( & V_3 -> V_25 -> V_117 ) ;
return ( 1 ) ;
}
ASSERT ( ! F_11 ( & V_3 -> V_9 ) ) ;
if ( ! F_132 ( V_3 ) ) {
F_133 ( V_3 ) ;
}
if ( F_112 ( V_3 ) ) {
int error ;
error = F_109 ( V_3 , V_164 ) ;
if ( error )
F_134 ( V_1 , L_4 ,
V_174 , V_3 ) ;
F_135 ( V_3 ) ;
}
ASSERT ( F_113 ( & V_3 -> V_24 ) == 0 ) ;
ASSERT ( F_115 ( V_1 ) ||
! ( V_3 -> V_168 . V_169 . V_157 & V_158 ) ) ;
F_79 ( & V_3 -> V_16 ) ;
V_115 -> V_138 ++ ;
F_79 ( & V_3 -> V_15 ) ;
V_1 -> V_39 -> V_175 ++ ;
V_1 -> V_39 -> V_145 -- ;
ASSERT ( ! F_11 ( & V_3 -> V_9 ) ) ;
V_3 -> V_8 = NULL ;
V_3 -> V_25 = NULL ;
V_3 -> V_5 = V_176 ;
memset ( & V_3 -> V_6 , 0 , sizeof( V_3 -> V_6 ) ) ;
F_108 ( V_3 ) ;
F_75 ( V_3 ) ;
F_77 ( & V_115 -> V_117 ) ;
return ( 0 ) ;
}
void
F_133 (
T_1 * V_3 )
{
T_2 * V_1 = V_3 -> V_8 ;
T_10 * V_65 ;
V_65 = F_136 ( V_1 -> V_94 , V_3 -> V_14 ,
V_1 -> V_39 -> V_71 , V_177 ) ;
if ( ! V_65 )
goto V_178;
if ( F_137 ( V_65 ) ) {
if ( F_120 ( V_65 ) )
F_122 ( V_1 , 0 ) ;
F_138 ( V_65 ) ;
F_139 ( V_65 -> V_179 -> V_180 ) ;
}
F_116 ( V_65 ) ;
V_178:
F_135 ( V_3 ) ;
}
