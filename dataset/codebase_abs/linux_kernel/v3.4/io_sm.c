static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 &= ~ ( 1 << V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 |= 1 << V_3 ;
}
int F_3 ( struct V_5 * * V_6 ,
struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_5 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_2 V_18 ;
if ( ! V_6 || ! V_10 || V_10 -> V_19 == 0 )
return - V_20 ;
* V_6 = NULL ;
F_4 ( V_8 , & V_17 ) ;
if ( ! V_17 || V_17 -> V_21 )
return - V_20 ;
F_5 ( V_8 , & V_13 ) ;
if ( ! V_13 )
return - V_20 ;
F_6 ( V_8 , & V_18 ) ;
V_11 = F_7 ( sizeof( struct V_5 ) , V_22 ) ;
if ( ! V_11 )
return - V_23 ;
V_11 -> V_16 = V_17 ;
V_11 -> V_19 = V_10 -> V_19 ;
if ( V_18 == V_24 ) {
F_8 ( & V_11 -> V_25 , V_26 , ( T_1 ) V_11 ) ;
V_11 -> V_27 = 0 ;
V_11 -> V_28 = 0 ;
F_9 ( & V_11 -> V_29 ) ;
if ( F_10 ( V_8 , & V_15 ) ) {
F_11 ( V_11 ) ;
return - V_30 ;
}
}
V_11 -> V_31 = V_13 ;
V_11 -> V_32 = V_10 -> V_33 ;
if ( F_12 () ) {
F_11 ( V_11 ) ;
return - V_34 ;
}
V_17 -> V_21 = V_11 ;
* V_6 = V_11 ;
return 0 ;
}
int F_11 ( struct V_5 * V_35 )
{
int V_36 = 0 ;
if ( V_35 ) {
F_13 ( & V_35 -> V_25 ) ;
#if F_14 ( V_37 )
F_15 ( V_35 -> V_38 ) ;
#endif
F_16 () ;
F_15 ( V_35 ) ;
} else {
V_36 = - V_20 ;
}
return V_36 ;
}
int F_17 ( struct V_5 * V_35 )
{
struct V_39 * V_40 ;
struct V_16 * V_17 ;
struct V_41 * V_42 ;
T_1 V_43 ;
T_1 V_44 ;
T_1 V_45 ;
T_1 V_46 = - 1 ;
T_1 V_47 = - 1 ;
T_1 V_48 ;
T_1 V_49 ;
T_1 V_50 = - 1 ;
T_1 V_51 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0 ;
T_1 V_56 = 0 ;
T_1 V_57 ;
int V_36 = 0 ;
T_2 V_58 = 0 ;
T_3 V_59 = 0 ;
struct V_60 V_61 [ V_62 ] ;
struct V_63 * V_64 ;
struct V_12 * V_65 ;
T_1 V_66 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_1 V_75 [] = { V_76 , V_77 ,
V_78 , V_79
} ;
V_36 = F_5 ( V_35 -> V_80 , & V_65 ) ;
if ( ! V_65 ) {
V_36 = - V_20 ;
goto V_81;
}
V_64 = V_65 -> V_82 ;
if ( ! V_64 ) {
V_36 = - V_20 ;
goto V_81;
}
V_36 = F_18 ( V_35 -> V_80 , & V_40 ) ;
if ( ! V_40 ) {
V_36 = - V_20 ;
goto V_81;
}
V_17 = V_35 -> V_16 ;
F_19 ( V_35 -> V_80 , & V_35 -> V_41 ) ;
V_42 = V_35 -> V_41 ;
if ( ! V_17 || ! V_42 ) {
V_36 = - V_20 ;
goto V_81;
}
if ( V_35 -> V_83 )
V_35 -> V_83 = NULL ;
V_36 = F_20 ( V_40 , V_84 ,
& V_43 ) ;
if ( V_36 ) {
V_36 = - V_20 ;
goto V_81;
}
V_36 = F_20 ( V_40 , V_85 ,
& V_45 ) ;
if ( V_36 ) {
V_36 = - V_20 ;
goto V_81;
}
if ( V_45 <= V_43 ) {
V_36 = - V_86 ;
goto V_81;
}
V_46 = ( V_45 - V_43 + 1 ) * V_35 -> V_19 ;
F_21 ( V_87 , L_1 ,
V_88 , ( V_46 - sizeof( struct V_1 ) ) ) ;
V_36 = F_20 ( V_40 , V_89 ,
& V_48 ) ;
if ( ! V_36 ) {
V_36 = F_20 ( V_40 , V_90 ,
& V_49 ) ;
if ( ! V_36 ) {
if ( V_49 <= V_48 ) {
V_36 = - V_86 ;
} else {
V_50 =
( V_49 - V_48 +
1 ) * V_35 -> V_19 ;
V_47 = V_46 + V_50 ;
}
} else {
V_36 = - V_20 ;
}
} else {
V_36 = - V_20 ;
}
if ( ! V_36 ) {
#if F_14 ( V_37 )
V_36 =
F_20 ( V_40 , V_91 , & V_67 ) ;
#else
V_36 = F_20 ( V_40 , V_92 ,
& V_67 ) ;
#endif
if ( V_36 )
V_36 = - V_20 ;
}
if ( ! V_36 ) {
V_36 =
F_20 ( V_40 , V_93 , & V_68 ) ;
if ( V_36 )
V_36 = - V_20 ;
}
if ( ! V_36 ) {
V_36 = F_20 ( V_40 , V_94 , & V_51 ) ;
if ( V_36 )
V_36 = - V_20 ;
}
if ( ! V_36 ) {
( void ) F_22 ( 0 , (struct V_95 * )
& V_35 -> V_96 ,
sizeof( struct
V_97 ) ,
& V_58 ) ;
V_59 = 0 ;
V_52 = V_64 -> V_98 [ 1 ] ;
V_53 = V_64 -> V_99 [ 1 ] ;
V_54 = V_35 -> V_96 . V_100 [ 0 ] . V_101 ;
V_55 = ( V_67 - V_54 ) * V_35 -> V_19 ;
V_69 =
( V_51 - V_68 ) * V_35 -> V_19 ;
V_69 = ( V_69 + 0xFFF ) & ( ~ 0xFFFUL ) ;
V_55 = ( V_55 + 0xFFFF ) & ( ~ 0xFFFFUL ) ;
V_56 = V_102 - ( ( V_52 + V_69 ) %
V_102 ) ;
if ( V_56 == V_102 )
V_56 = 0x0 ;
F_21 ( V_87 , L_2
L_3
L_4 , V_88 ,
V_52 , V_53 , V_54 , V_67 ,
V_68 , V_51 , V_55 , V_69 ) ;
if ( ( V_55 + V_69 + V_56 ) >
V_64 -> V_103 [ 1 ] ) {
F_23 ( L_5 ,
V_88 , V_64 -> V_103 [ 1 ] ,
V_55 + V_69 + V_56 ) ;
V_36 = - V_23 ;
}
}
if ( V_36 )
goto V_81;
V_70 = V_52 ;
V_71 = V_68 * V_35 -> V_19 ;
V_72 = V_53 ;
V_73 = V_69 ;
V_66 = 0x00000000 ;
V_66 = V_104 ;
V_66 |= V_105 ;
V_66 |= V_106 ;
V_66 |= V_107 ;
while ( V_73 ) {
V_74 = V_70 | V_71 ;
F_21 ( V_87 , L_6
L_7 , V_74 , V_70 , V_71 ,
V_73 ) ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
if ( ( V_73 >= V_75 [ V_57 ] ) && ( ( V_74 &
( V_75 [ V_57 ] -
1 ) ) == 0 ) ) {
V_36 =
V_35 -> V_108 ->
V_109 ( V_35 -> V_31 ,
V_70 , V_71 ,
V_75 [ V_57 ] , V_66 ,
NULL ) ;
if ( V_36 )
goto V_81;
V_70 += V_75 [ V_57 ] ;
V_71 += V_75 [ V_57 ] ;
V_72 += V_75 [ V_57 ] ;
V_73 -= V_75 [ V_57 ] ;
break;
}
}
}
V_70 += V_56 ;
V_71 += V_56 ;
V_72 += V_56 ;
V_73 = V_55 ;
V_71 = V_54 * V_35 -> V_19 ;
while ( V_73 ) {
V_74 = V_70 | V_71 ;
F_21 ( V_87 , L_8
L_9 , V_74 , V_70 ,
V_71 , V_73 ) ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
if ( ! ( V_73 >= V_75 [ V_57 ] ) ||
! ( ( V_74 & ( V_75 [ V_57 ] - 1 ) ) == 0 ) )
continue;
if ( V_59 < V_110 ) {
V_61 [ V_59 ] . V_111 = V_70 ;
V_61 [ V_59 ] . V_112 = V_72 ;
V_61 [ V_59 ] . V_113 =
V_71 / V_35 -> V_19 ;
V_61 [ V_59 ] . V_114 = V_75 [ V_57 ] ;
V_61 [ V_59 ] . V_115 = V_116 ;
V_61 [ V_59 ] . V_117 = V_118 ;
V_61 [ V_59 ] . V_119 = V_120 ;
F_21 ( V_87 , L_10
L_11 ,
V_61 [ V_59 ] . V_111 ,
V_61 [ V_59 ] . V_112 ,
V_61 [ V_59 ] . V_113 *
V_35 -> V_19 , V_75 [ V_57 ] ) ;
V_59 ++ ;
} else {
V_36 =
V_35 -> V_108 ->
V_109 ( V_35 -> V_31 ,
V_70 , V_71 ,
V_75 [ V_57 ] , V_66 ,
NULL ) ;
F_21 ( V_87 ,
L_12
L_11 ,
V_61 [ V_59 ] . V_111 ,
V_61 [ V_59 ] . V_112 ,
V_61 [ V_59 ] . V_113 *
V_35 -> V_19 , V_75 [ V_57 ] ) ;
if ( V_36 )
goto V_81;
}
V_70 += V_75 [ V_57 ] ;
V_71 += V_75 [ V_57 ] ;
V_72 += V_75 [ V_57 ] ;
V_73 -= V_75 [ V_57 ] ;
break;
}
}
for ( V_57 = 3 ; V_57 < 7 && V_59 < V_62 ; V_57 ++ ) {
if ( V_35 -> V_96 . V_100 [ V_57 ] . V_121 == 0 )
continue;
if ( ( V_35 -> V_96 . V_100 [ V_57 ] . V_121 >
V_52 - 0x100000
&& V_35 -> V_96 . V_100 [ V_57 ] . V_121 <=
V_52 + V_55 )
|| ( V_35 -> V_96 . V_100 [ V_57 ] . V_101 >
V_54 - 0x100000 / V_35 -> V_19
&& V_35 -> V_96 . V_100 [ V_57 ] . V_101 <=
V_54 + V_55 / V_35 -> V_19 ) ) {
F_21 ( V_87 ,
L_13
L_14
L_15 , V_57 ,
V_35 -> V_96 . V_100 [ V_57 ] . V_121 ,
V_35 -> V_96 . V_100 [ V_57 ] . V_101 ,
V_52 , V_54 , V_55 ) ;
V_36 = - V_34 ;
} else {
if ( V_59 < V_110 ) {
V_61 [ V_59 ] . V_113 =
V_35 -> V_96 . V_100 [ V_57 ] .
V_101 ;
V_61 [ V_59 ] . V_111 =
V_35 -> V_96 . V_100 [ V_57 ] .
V_121 ;
V_61 [ V_59 ] . V_112 = 0 ;
V_61 [ V_59 ] . V_114 = 0x100000 ;
F_21 ( V_87 , L_16
L_17 , V_61 [ V_59 ] . V_111 ,
V_61 [ V_59 ] . V_113 ) ;
V_59 ++ ;
} else {
V_36 = V_35 -> V_108 -> V_109
( V_35 -> V_31 ,
V_35 -> V_96 . V_100 [ V_57 ] .
V_121 ,
V_35 -> V_96 . V_100 [ V_57 ] .
V_101 , 0x100000 , V_66 ,
NULL ) ;
}
}
if ( V_36 )
goto V_81;
}
V_66 = 0x00000000 ;
V_66 = V_104 ;
V_66 |= V_105 ;
V_66 |= V_106 ;
V_66 |= V_107 ;
V_57 = 0 ;
while ( V_122 [ V_57 ] . V_123 ) {
V_36 = V_35 -> V_108 -> V_109
( V_35 -> V_31 , V_122 [ V_57 ] . V_123 ,
V_122 [ V_57 ] . V_124 , V_79 ,
V_66 , NULL ) ;
if ( V_36 )
goto V_81;
V_57 ++ ;
}
for ( V_57 = V_59 ; V_57 < V_62 ; V_57 ++ ) {
V_61 [ V_57 ] . V_113 = 0 ;
V_61 [ V_57 ] . V_111 = 0 ;
V_61 [ V_57 ] . V_112 = 0 ;
V_61 [ V_57 ] . V_114 = 0 ;
}
V_35 -> V_96 . V_100 [ 0 ] . V_121 =
( V_53 + V_69 + V_56 ) ;
if ( ! V_35 -> V_96 . V_100 [ 0 ] . V_121 || V_58 != 1 ) {
V_36 = - V_20 ;
goto V_81;
} else {
if ( V_61 [ 0 ] . V_113 > V_43 ) {
V_36 = - V_34 ;
goto V_81;
}
V_44 = ( V_43 - V_61 [ 0 ] . V_113 ) *
V_35 -> V_19 ;
V_36 =
V_35 -> V_108 -> V_125 ( V_35 -> V_31 ,
V_126 ,
V_61 ) ;
if ( V_36 )
goto V_81;
V_43 = V_35 -> V_96 . V_100 [ 0 ] . V_121 ;
V_43 += V_44 ;
V_43 = ( T_1 ) F_24 ( ( void * ) V_43 ,
V_47 ) ;
if ( V_43 == 0 ) {
V_36 = - V_20 ;
goto V_81;
}
V_36 =
F_25 ( V_35 , V_40 , V_61 [ 0 ] . V_111 ) ;
}
V_35 -> V_83 = (struct V_1 * ) V_43 ;
V_35 -> V_127 = ( T_2 * ) V_35 -> V_83 + sizeof( struct V_1 ) ;
V_35 -> V_128 = V_35 -> V_127 + ( V_46 -
sizeof( struct V_1 ) ) / 2 ;
V_35 -> V_129 = V_35 -> V_128 - V_35 -> V_127 ;
V_35 -> V_130 = (struct V_131 * ) ( ( T_2 * ) V_35 -> V_83
+ V_46 ) ;
V_35 -> V_132 =
( T_2 * ) V_35 -> V_130 + sizeof( struct V_131 ) ;
V_35 -> V_133 =
(struct V_131 * ) ( ( T_2 * ) V_35 -> V_130 +
V_50 / 2 ) ;
V_35 -> V_134 =
( T_2 * ) V_35 -> V_133 + sizeof( struct V_131 ) ;
V_42 -> V_135 =
( ( T_2 * ) V_35 -> V_133 - V_35 -> V_132 )
/ sizeof( struct V_136 ) ;
F_21 ( V_87 , L_18
L_19
L_20 ,
( T_2 * ) V_35 -> V_83 , V_35 -> V_127 ,
V_35 -> V_128 , ( T_2 * ) V_35 -> V_130 ,
V_35 -> V_132 , ( T_2 * ) V_35 -> V_133 ,
V_35 -> V_134 ) ;
F_21 ( V_87 , L_21 ,
V_42 -> V_135 ) ;
memset ( ( void * ) V_35 -> V_83 , 0 , sizeof( struct V_1 ) ) ;
#if F_14 ( V_37 )
V_36 = F_20 ( V_40 , V_137 ,
& V_35 -> V_138 ) ;
if ( V_36 ) {
V_36 = - V_20 ;
goto V_81;
}
V_35 -> V_139 = V_35 -> V_138 =
( V_53 + V_69 + V_56 ) +
( V_35 -> V_138 - V_54 ) ;
V_36 = F_20 ( V_40 , V_140 ,
& V_35 -> V_141 ) ;
if ( V_36 ) {
V_36 = - V_20 ;
goto V_81;
}
V_35 -> V_141 =
( V_53 + V_69 + V_56 ) +
( V_35 -> V_141 - V_54 ) ;
V_36 = F_20 ( V_40 , V_142 ,
& V_35 -> V_143 ) ;
if ( V_36 ) {
V_36 = - V_20 ;
goto V_81;
}
V_35 -> V_143 =
( V_53 + V_69 + V_56 ) +
( V_35 -> V_143 - V_54 ) ;
F_15 ( V_35 -> V_38 ) ;
V_35 -> V_38 = F_26 ( ( ( V_35 -> V_141 -
V_35 -> V_138 ) *
V_35 -> V_19 ) + 2 , V_22 ) ;
if ( ! V_35 -> V_38 )
V_36 = - V_23 ;
V_35 -> V_113 = V_54 ;
V_35 -> V_112 = ( V_53 + V_69 + V_56 ) ;
#endif
V_81:
return V_36 ;
}
T_1 F_27 ( struct V_5 * V_35 )
{
if ( V_35 )
return V_35 -> V_129 ;
else
return 0 ;
}
void F_28 ( struct V_5 * V_35 , T_1 V_3 )
{
struct V_5 * V_11 = (struct V_5 * ) V_35 ;
struct V_1 * V_2 ;
if ( ! V_35 )
goto V_81;
V_2 = V_35 -> V_83 ;
F_1 ( V_2 , V_3 ) ;
F_29 ( V_11 -> V_31 , V_144 ) ;
V_81:
return;
}
static void F_30 ( struct V_5 * V_11 )
{
int V_36 ;
T_1 V_145 [ 2 ] ;
V_145 [ 0 ] = V_11 -> V_146 ;
if ( V_145 [ 0 ] == V_147 ) {
F_21 ( V_87 , L_22 ) ;
V_36 = V_11 -> V_108 ->
V_125 ( V_11 -> V_31 ,
V_148 , V_145 ) ;
if ( V_36 )
F_23 ( L_23 ,
V_88 , V_36 ) ;
} else if ( V_145 [ 0 ] == V_149 ) {
V_145 [ 1 ] = V_11 -> V_83 -> V_150 . V_151 ;
F_21 ( V_87 , L_24 , V_145 [ 1 ] ) ;
V_36 = V_11 -> V_108 ->
V_125 ( V_11 -> V_31 ,
V_152 , V_145 ) ;
if ( V_36 )
F_21 ( V_87 , L_25
L_26 , V_145 [ 1 ] ) ;
} else {
F_21 ( V_87 , L_27 ,
V_145 [ 0 ] ) ;
V_36 = V_11 -> V_108 ->
V_125 ( V_11 -> V_31 ,
V_153 , V_145 ) ;
if ( V_36 )
F_21 ( V_87 , L_28
L_26 , * V_145 ) ;
}
}
void V_26 ( unsigned long V_154 )
{
struct V_5 * V_11 = (struct V_5 * ) V_154 ;
struct V_16 * V_155 ;
struct V_41 * V_156 ;
struct V_157 * V_158 ;
T_1 V_159 ;
T_1 V_160 ;
if ( ! V_11 )
goto V_81;
V_155 = V_11 -> V_16 ;
F_19 ( V_11 -> V_80 , & V_156 ) ;
F_31 ( V_11 -> V_80 , & V_158 ) ;
if ( ! V_155 )
goto V_81;
V_159 = V_11 -> V_27 ;
V_160 = V_11 -> V_28 ;
if ( V_160 == V_159 )
goto V_81;
do {
if ( ( V_11 -> V_146 > V_161 ) &&
( V_11 -> V_146 < V_162 ) ) {
if ( V_158 ) {
#ifdef V_37
F_32 ( V_11 ) ;
#endif
F_33 ( V_158 , V_163 ,
V_11 -> V_146 ) ;
}
}
F_34 ( V_11 , NULL , V_164 ) ;
F_35 ( V_11 , NULL , V_164 ) ;
#ifdef F_36
if ( V_156 ) {
F_37 ( V_11 , V_156 ) ;
F_38 ( V_11 , V_156 ) ;
}
#endif
#ifdef V_37
if ( V_11 -> V_146 & V_165 ) {
F_32 ( V_11 ) ;
}
#endif
V_160 ++ ;
} while ( V_160 != V_159 );
V_11 -> V_28 = V_159 ;
V_81:
return;
}
int F_39 ( struct V_166 * V_167 , unsigned long V_168 , void * V_38 )
{
struct V_5 * V_11 ;
struct V_7 * V_80 ;
unsigned long V_169 ;
V_80 = F_40 () ;
F_41 ( V_80 , & V_11 ) ;
if ( ! V_11 )
return V_170 ;
V_11 -> V_146 = ( V_171 ) ( ( T_1 ) V_38 ) ;
if ( V_11 -> V_146 & V_172 )
F_30 ( V_11 ) ;
if ( V_11 -> V_146 == V_173 ) {
V_11 -> V_146 = 0 ;
} else {
F_42 ( & V_11 -> V_29 , V_169 ) ;
V_11 -> V_27 ++ ;
F_43 ( & V_11 -> V_29 , V_169 ) ;
F_44 ( & V_11 -> V_25 ) ;
}
return V_174 ;
}
void F_45 ( struct V_5 * V_175 , struct V_176 * V_177 ,
T_2 V_178 , V_171 * V_179 )
{
struct V_16 * V_155 ;
struct V_1 * V_2 ;
if ( ! V_177 || ! V_179 )
goto V_81;
V_155 = V_175 -> V_16 ;
V_2 = V_175 -> V_83 ;
if ( V_178 == V_180 ) {
F_2 ( V_2 , V_177 -> V_181 ) ;
* V_179 = V_144 ;
} else if ( V_178 == V_182 ) {
V_155 -> V_183 |= ( 1 << V_177 -> V_181 ) ;
} else {
}
V_81:
return;
}
void F_46 ( struct V_5 * V_175 )
{
unsigned long V_169 ;
if ( ! V_175 )
return;
F_42 ( & V_175 -> V_29 , V_169 ) ;
V_175 -> V_27 ++ ;
F_43 ( & V_175 -> V_29 , V_169 ) ;
F_44 ( & V_175 -> V_25 ) ;
}
static T_1 F_47 ( struct V_16 * V_155 ,
struct V_176 * V_177 , T_1 V_184 )
{
T_1 V_185 = V_186 ;
T_1 V_187 , V_188 ;
T_1 V_189 ;
V_187 = ( V_177 !=
NULL ? V_177 -> V_181 : ( V_155 -> V_190 + 1 ) ) ;
V_187 = ( ( V_187 == V_191 ) ? 0 : V_187 ) ;
if ( V_187 >= V_191 )
goto V_81;
if ( V_184 ) {
V_189 = ( 1 << V_187 ) ;
V_188 = V_187 ;
do {
if ( V_184 & V_189 ) {
V_185 = V_187 ;
if ( V_177 == NULL )
V_155 -> V_190 = V_187 ;
break;
}
V_187 = V_187 + 1 ;
V_187 = ( ( V_187 == V_191 ) ? 0 : V_187 ) ;
V_189 = ( 1 << V_187 ) ;
} while ( V_187 != V_188 );
}
V_81:
return V_185 ;
}
static void F_34 ( struct V_5 * V_11 , struct V_176 * V_177 ,
T_2 V_178 )
{
struct V_16 * V_155 ;
struct V_1 * V_2 ;
T_1 V_181 ;
T_1 V_192 ;
struct V_193 * V_194 = NULL ;
T_1 V_195 ;
bool V_196 = false ;
bool V_197 = false ;
V_2 = V_11 -> V_83 ;
V_155 = V_11 -> V_16 ;
if ( ! V_2 -> V_198 )
goto V_81;
V_192 = V_2 -> V_199 * V_155 -> V_19 ;
V_181 = V_2 -> V_200 ;
V_195 = V_2 -> V_201 ;
if ( V_181 >= V_191 ) {
goto V_81;
}
V_177 = V_155 -> V_202 [ V_181 ] ;
if ( ( V_177 != NULL ) && F_48 ( V_177 -> V_203 ) ) {
if ( ( V_177 -> V_204 & ~ V_205 ) == V_206 ) {
if ( ! F_49 ( & V_177 -> V_207 ) ) {
if ( ! V_177 -> V_208 )
goto V_81;
V_194 = F_50 (
& V_177 -> V_207 ,
struct V_193 , V_209 ) ;
F_51 ( & V_194 -> V_209 ) ;
V_177 -> V_208 -- ;
V_192 = F_52 ( V_192 , V_194 -> V_210 ) ;
memcpy ( V_194 -> V_211 ,
V_11 -> V_127 , V_192 ) ;
V_177 -> V_212 += V_192 ;
V_194 -> V_210 = V_192 ;
V_194 -> V_201 = V_195 ;
V_194 -> V_36 = V_213 ;
if ( V_192 == 0 ) {
if ( V_177 -> V_204 & V_205 )
goto V_81;
V_194 -> V_36 |=
V_214 ;
V_177 -> V_204 |= V_205 ;
F_53 ( V_177 -> V_215 ,
V_216 ) ;
}
if ( F_49 ( & V_177 -> V_207 ) )
F_1 ( V_2 , V_177 -> V_181 ) ;
V_196 = true ;
V_197 = true ;
} else {
V_196 = true ;
}
} else {
V_196 = true ;
}
} else {
V_196 = true ;
}
if ( V_196 ) {
V_2 -> V_198 = 0 ;
F_29 ( V_11 -> V_31 , V_144 ) ;
}
if ( V_197 ) {
F_54 ( V_177 , V_194 ) ;
}
V_81:
return;
}
static void F_37 ( struct V_5 * V_11 , struct V_41 * V_42 )
{
T_1 V_217 ;
T_1 V_57 ;
T_2 * V_132 ;
struct V_218 * V_219 ;
struct V_220 * V_221 ;
struct V_136 V_38 ;
struct V_131 * V_222 ;
T_1 V_223 ;
T_1 V_224 ;
V_222 = V_11 -> V_130 ;
V_223 = V_222 -> V_225 ;
V_217 = V_222 -> V_114 ;
if ( V_223 )
return;
V_132 = V_11 -> V_132 ;
for ( V_57 = 0 ; V_57 < V_217 ; V_57 ++ ) {
V_224 = ( T_1 ) & ( ( (struct V_136 * ) V_132 ) -> V_38 . V_226 ) ;
V_38 . V_38 . V_226 =
F_55 ( V_11 -> V_31 , V_224 ) ;
V_224 = ( T_1 ) & ( ( (struct V_136 * ) V_132 ) -> V_38 . V_227 ) ;
V_38 . V_38 . V_227 =
F_55 ( V_11 -> V_31 , V_224 ) ;
V_224 = ( T_1 ) & ( ( (struct V_136 * ) V_132 ) -> V_38 . V_228 ) ;
V_38 . V_38 . V_228 =
F_55 ( V_11 -> V_31 , V_224 ) ;
V_224 = ( T_1 ) & ( ( (struct V_136 * ) V_132 ) -> V_229 ) ;
V_38 . V_229 =
F_55 ( V_11 -> V_31 , V_224 ) ;
V_132 += sizeof( struct V_136 ) ;
F_21 ( V_87 , L_29
L_30 , V_38 . V_38 . V_226 ,
V_38 . V_38 . V_227 , V_38 . V_38 . V_228 , V_38 . V_229 ) ;
F_56 (msg_queue_obj, &hmsg_mgr->queue_list,
list_elem) {
if ( V_38 . V_229 != V_219 -> V_229 )
continue;
if ( V_38 . V_38 . V_226 == V_230 ) {
(* V_42 -> V_231 )( V_219 -> V_201 ,
V_38 . V_38 . V_227 ) ;
break;
}
if ( F_49 ( & V_219 -> V_232 ) ) {
F_23 ( L_31
L_32 ,
V_88 ) ;
break;
}
V_221 = F_50 ( & V_219 -> V_232 ,
struct V_220 , V_233 ) ;
F_51 ( & V_221 -> V_233 ) ;
V_221 -> V_234 = V_38 ;
F_57 ( & V_221 -> V_233 ,
& V_219 -> V_235 ) ;
F_53 ( V_219 -> V_215 ,
V_236 ) ;
F_58 ( V_219 -> V_237 ) ;
}
}
if ( V_217 > 0 ) {
V_222 -> V_225 = true ;
V_222 -> V_238 = true ;
F_29 ( V_11 -> V_31 , V_144 ) ;
}
}
static void F_54 ( struct V_176 * V_177 ,
struct V_193 * V_194 )
{
bool V_239 ;
if ( ! V_177 || ! V_177 -> V_237 || ! V_194 )
goto V_81;
V_239 = F_49 ( & V_177 -> V_240 ) ;
F_57 ( & V_194 -> V_209 , & V_177 -> V_240 ) ;
V_177 -> V_241 ++ ;
if ( V_177 -> V_241 > V_177 -> V_242 )
goto V_81;
if ( V_239 )
F_58 ( V_177 -> V_237 ) ;
F_53 ( V_177 -> V_215 , V_243 ) ;
V_81:
return;
}
static void F_35 ( struct V_5 * V_11 , struct V_176 * V_177 ,
T_2 V_178 )
{
struct V_16 * V_155 ;
struct V_1 * V_2 ;
T_1 V_181 ;
struct V_193 * V_194 ;
T_1 V_244 ;
V_155 = V_11 -> V_16 ;
V_2 = V_11 -> V_83 ;
if ( V_2 -> V_245 )
goto V_81;
if ( V_177 && ! ( ( V_177 -> V_204 & ~ V_205 ) == V_206 ) )
goto V_81;
V_244 = V_2 -> V_246 ;
V_181 =
F_47 ( V_155 , V_177 ,
( V_155 -> V_183 & V_244 ) ) ;
if ( V_181 == V_186 )
goto V_81;
V_177 = V_155 -> V_202 [ V_181 ] ;
if ( ! V_177 || F_49 ( & V_177 -> V_207 ) ) {
goto V_81;
}
if ( ! V_177 -> V_208 )
goto V_81;
V_194 = F_50 ( & V_177 -> V_207 ,
struct V_193 , V_209 ) ;
F_51 ( & V_194 -> V_209 ) ;
V_177 -> V_208 -- ;
if ( F_49 ( & V_177 -> V_207 ) )
V_155 -> V_183 &= ~ ( 1 << V_181 ) ;
V_194 -> V_210 = F_52 ( V_11 -> V_129 ,
V_194 -> V_210 ) ;
memcpy ( V_11 -> V_128 , V_194 -> V_211 ,
V_194 -> V_210 ) ;
V_177 -> V_212 += V_194 -> V_210 ;
V_2 -> V_201 = V_194 -> V_201 ;
#if V_247 == 2
V_2 -> V_248 = ( V_171 ) V_181 ;
V_2 -> V_249 = ( V_171 ) ( V_194 -> V_210 +
V_155 -> V_19 - 1 ) /
( V_171 ) V_155 -> V_19 ;
#else
V_2 -> V_248 = V_181 ;
V_2 -> V_249 = ( V_194 -> V_210 +
V_155 -> V_19 - 1 ) / V_155 -> V_19 ;
#endif
V_2 -> V_245 = 1 ;
F_29 ( V_11 -> V_31 , V_144 ) ;
V_194 -> V_36 &= V_214 ;
F_54 ( V_177 , V_194 ) ;
if ( V_194 -> V_36 & V_214 )
F_53 ( V_177 -> V_215 , V_216 ) ;
V_81:
return;
}
static void F_38 ( struct V_5 * V_11 , struct V_41 * V_42 )
{
T_1 V_217 = 0 ;
T_1 V_57 ;
struct V_136 * V_134 ;
struct V_220 * V_221 ;
struct V_131 * V_222 ;
T_1 V_250 ;
T_1 V_224 ;
V_222 = V_11 -> V_133 ;
if ( ! V_222 -> V_225 )
return;
V_217 = ( V_42 -> V_251 > V_42 -> V_135 ) ?
V_42 -> V_135 : V_42 -> V_251 ;
V_134 = (struct V_136 * ) V_11 -> V_134 ;
for ( V_57 = 0 ; V_57 < V_217 ; V_57 ++ ) {
if ( F_49 ( & V_42 -> V_235 ) )
continue;
V_221 = F_50 ( & V_42 -> V_235 ,
struct V_220 , V_233 ) ;
F_51 ( & V_221 -> V_233 ) ;
V_250 = ( V_221 -> V_234 ) . V_229 ;
V_224 = ( T_1 ) & V_134 -> V_229 ;
F_59 ( V_11 -> V_31 , V_224 , V_250 ) ;
V_250 = ( V_221 -> V_234 ) . V_38 . V_226 ;
V_224 = ( T_1 ) & V_134 -> V_38 . V_226 ;
F_59 ( V_11 -> V_31 , V_224 , V_250 ) ;
V_250 = ( V_221 -> V_234 ) . V_38 . V_227 ;
V_224 = ( T_1 ) & V_134 -> V_38 . V_227 ;
F_59 ( V_11 -> V_31 , V_224 , V_250 ) ;
V_250 = ( V_221 -> V_234 ) . V_38 . V_228 ;
V_224 = ( T_1 ) & V_134 -> V_38 . V_228 ;
F_59 ( V_11 -> V_31 , V_224 , V_250 ) ;
V_134 ++ ;
F_57 ( & V_221 -> V_233 , & V_42 -> V_232 ) ;
F_58 ( V_42 -> V_237 ) ;
}
if ( V_217 > 0 ) {
V_42 -> V_251 -= V_217 ;
#if V_247 == 2
V_222 -> V_114 = ( V_171 ) V_217 ;
#else
V_222 -> V_114 = V_217 ;
#endif
V_222 -> V_225 = false ;
V_222 -> V_238 = true ;
F_29 ( V_11 -> V_31 , V_144 ) ;
}
}
static int F_25 ( struct V_5 * V_35 ,
struct V_39 * V_40 ,
T_1 V_252 )
{
int V_36 = 0 ;
T_1 V_253 = 0 ;
T_1 V_67 = 0 ;
T_1 V_254 = 0 ;
T_1 V_255 = 0 ;
T_1 V_256 ;
T_1 V_257 ;
T_1 V_258 = 0 ;
T_1 V_259 , V_260 , V_261 ;
V_36 =
F_20 ( V_40 , V_262 , & V_253 ) ;
if ( V_253 == 0 ) {
V_36 = - V_34 ;
goto V_81;
}
if ( ! V_36 ) {
V_36 = F_20 ( V_40 , V_92 ,
& V_67 ) ;
if ( V_67 == 0 ) {
V_36 = - V_34 ;
goto V_81;
}
}
if ( ! V_36 ) {
V_36 =
F_20 ( V_40 , V_263 ,
& V_254 ) ;
if ( V_254 == 0 ) {
V_36 = - V_34 ;
goto V_81;
}
}
if ( ! V_36 ) {
V_36 = F_60 ( V_35 -> V_80 , & V_35 -> V_264 ) ;
if ( ! V_36 ) {
V_36 = F_61 ( V_35 -> V_264 ,
V_265 ) ;
}
}
if ( ! V_36 && ( V_67 - V_253 ) > 0 ) {
V_255 =
( V_67 - V_254 + 1 ) * V_35 -> V_19 ;
if ( V_255 <= 0 ) {
V_36 = - V_34 ;
goto V_81;
}
V_261 =
( V_254 - V_253 ) * V_35 -> V_19 ;
if ( V_261 <= 0 ) {
V_36 = - V_34 ;
goto V_81;
}
V_256 = V_35 -> V_96 . V_100 [ 0 ] . V_121 ;
V_257 =
V_35 -> V_96 . V_100 [ 0 ] . V_101 *
V_35 -> V_19 ;
if ( V_252 > V_257 )
V_259 = V_252 - V_257 ;
else
V_259 = V_257 - V_252 ;
if ( V_254 * V_35 -> V_19 < V_257 ) {
V_36 = - V_34 ;
goto V_81;
}
V_260 =
V_256 + V_254 * V_35 -> V_19 -
V_257 ;
V_252 =
V_252 + V_254 * V_35 -> V_19 -
V_257 ;
V_36 =
F_62 ( V_35 -> V_264 , V_252 ,
V_255 , V_259 ,
( V_252 >
V_257 ) ? V_266 :
V_267 ,
( T_1 ) ( V_253 *
V_35 -> V_19 ) ,
V_261 , & V_258 ,
V_260 ) ;
if ( V_258 != 1 )
V_36 = - V_34 ;
}
V_81:
return V_36 ;
}
int F_63 ( struct V_5 * V_35 , T_2 V_268 , void * V_269 )
{
#ifdef F_64
T_1 V_57 ;
struct V_270 * V_271 =
V_272 -> V_273 . V_274 ;
switch ( V_268 ) {
case V_275 :
if ( V_269 != NULL )
V_35 -> V_83 -> V_276 . V_277 =
* ( T_1 * ) V_269 ;
else
return - V_34 ;
break;
case V_278 :
for ( V_57 = 0 ; V_57 <= V_279 ; V_57 ++ ) {
V_35 -> V_83 -> V_276 . V_280 [ V_57 ] .
V_281 = V_282 [ V_57 ] [ 0 ] ;
F_21 ( V_87 , L_33 ,
V_282 [ V_57 ] [ 0 ] ) ;
V_35 -> V_83 -> V_276 .
V_280 [ V_57 ] . V_283 = V_282 [ V_57 ] [ 1 ] ;
F_21 ( V_87 , L_34 ,
V_282 [ V_57 ] [ 1 ] ) ;
V_35 -> V_83 -> V_276 . V_280 [ V_57 ] .
V_284 = V_282 [ V_57 ] [ 2 ] ;
F_21 ( V_87 , L_35 ,
V_282 [ V_57 ] [ 2 ] ) ;
V_35 -> V_83 -> V_276 . V_280 [ V_57 ] .
V_285 = V_282 [ V_57 ] [ 3 ] ;
F_21 ( V_87 , L_36 ,
V_282 [ V_57 ] [ 3 ] ) ;
}
V_35 -> V_83 -> V_276 . V_286 =
V_279 ;
F_21 ( V_87 , L_37 , V_279 ) ;
if ( V_271 -> V_287 )
V_57 = (* V_271 -> V_287 ) () ;
V_35 -> V_83 -> V_276 . V_277 = V_57 ;
F_21 ( V_87 , L_38 , V_57 ) ;
break;
case V_288 :
* ( T_1 * ) V_269 = V_35 -> V_83 -> V_150 . V_151 ;
break;
default:
break;
}
#endif
return 0 ;
}
int F_65 ( struct V_5 * V_35 ,
struct V_289 * V_290 )
{
if ( ! V_35 -> V_83 )
return - V_20 ;
V_290 -> V_291 =
V_35 -> V_83 -> V_292 . V_293 ;
V_290 -> V_294 =
V_35 -> V_83 -> V_292 . V_295 ;
V_290 -> V_296 =
V_35 -> V_83 -> V_292 . V_296 ;
V_290 -> V_297 =
V_35 -> V_83 -> V_292 . V_298 ;
F_21 ( V_87 , L_39
L_40 , V_290 -> V_291 ,
V_290 -> V_294 , V_290 -> V_296 ,
V_290 -> V_297 ) ;
return 0 ;
}
void F_32 ( struct V_5 * V_35 )
{
T_1 V_299 = 0 , V_300 ;
while ( true ) {
V_300 =
* ( T_1 * ) ( V_35 -> V_143 ) ;
V_300 =
V_35 -> V_112 + ( V_300 -
V_35 -> V_113 ) ;
if ( V_300 == V_35 -> V_139 ) {
break;
} else if ( V_300 > V_35 -> V_139 ) {
V_299 =
V_300 - V_35 -> V_139 ;
memcpy ( V_35 -> V_38 ,
( char * ) V_35 -> V_139 ,
V_299 ) ;
V_35 -> V_38 [ V_299 ] = '\0' ;
V_35 -> V_139 += V_299 ;
F_66 ( L_41 , V_35 -> V_38 ) ;
} else if ( V_300 < V_35 -> V_139 ) {
memcpy ( V_35 -> V_38 ,
( char * ) V_35 -> V_139 ,
V_35 -> V_141 -
V_35 -> V_139 ) ;
V_299 =
V_300 - V_35 -> V_138 ;
memcpy ( & V_35 -> V_38 [ V_35 -> V_141 -
V_35 -> V_139 ] ,
( char * ) V_35 -> V_138 ,
V_299 ) ;
V_35 -> V_38 [ V_35 -> V_141 -
V_35 -> V_139 +
V_299 ] = '\0' ;
V_35 -> V_139 =
V_35 -> V_138 +
V_299 ;
F_66 ( L_41 , V_35 -> V_38 ) ;
}
}
}
int F_67 ( struct V_12 * V_13 )
{
int V_36 = 0 ;
struct V_39 * V_301 ;
T_1 V_302 ;
T_1 V_303 ;
T_1 V_304 ;
T_1 V_305 = 0 ;
T_1 V_306 = 0 ;
T_1 V_307 = 2 ;
char * V_308 ;
char * V_309 ;
char * V_310 ;
char * V_311 ;
char * V_312 ;
struct V_12 * V_65 = V_13 ;
struct V_313 * V_108 ;
struct V_7 * V_80 = (struct V_7 * )
V_65 -> V_80 ;
V_36 = F_18 ( V_80 , & V_301 ) ;
if ( V_301 ) {
V_36 =
F_20 ( V_301 , V_314 , & V_303 ) ;
} else {
V_36 = - V_20 ;
}
if ( ! V_36 )
V_36 =
F_20 ( V_301 , V_315 , & V_302 ) ;
if ( ! V_36 )
V_36 = F_20 ( V_301 , V_316 ,
& V_304 ) ;
if ( V_36 )
goto V_81;
V_305 = ( V_302 - V_303 ) ;
V_306 = V_305 * V_307 ;
V_36 = F_68 ( V_80 , & V_108 ) ;
if ( V_36 )
goto V_81;
V_308 = F_7 ( V_305 + 2 , V_317 ) ;
if ( V_308 != NULL ) {
V_36 = (* V_108 -> V_318 )( V_65 ,
( T_2 * ) V_308 , ( T_1 ) V_303 ,
V_305 , 0 ) ;
if ( V_36 )
goto V_81;
F_69 ( L_42
L_43 ) ;
F_69 ( L_44
L_45 ,
V_88 , V_308 ) ;
V_36 = (* V_108 -> V_318 )( V_65 ,
( T_2 * ) & V_304 , ( T_1 ) V_304 ,
4 , 0 ) ;
if ( V_36 )
goto V_81;
F_66 ( L_46
L_45 ,
V_308 ) ;
V_304 = V_304 - V_303 ;
if ( V_305 ) {
V_311 = & V_308 [ V_305 + 1 ] ;
V_310 = & V_308 [ V_304 ] ;
V_309 = V_310 ;
V_305 = V_311 - V_309 ;
while ( V_309 < V_311 ) {
V_312 = F_70 ( V_309 , V_305 ,
'\n' ) ;
if ( V_312 && V_312 < V_311 ) {
* V_312 = 0 ;
F_69 ( L_47 , V_309 ) ;
V_309 = ++ V_312 ;
V_305 = V_311 - V_309 ;
} else {
if ( * V_309 != '\0' ) {
V_309 [ V_305 ] = 0 ;
F_69 ( L_47 , V_309 ) ;
}
V_309 = V_311 ;
V_305 = 0 ;
}
}
V_309 = V_308 ;
V_305 = V_310 - V_309 ;
while ( V_309 < V_310 ) {
V_312 = F_70 ( V_309 , V_305 , '\n' ) ;
if ( V_312 != NULL && V_312 < V_310 ) {
* V_312 = 0 ;
F_69 ( L_47 , V_309 ) ;
V_309 = ++ V_312 ;
V_305 = V_310 - V_309 ;
} else {
if ( * V_309 != '\0' ) {
V_309 [ V_305 ] = 0 ;
F_69 ( L_47 , V_309 ) ;
}
V_309 = V_310 ;
V_305 = 0 ;
}
}
}
F_66 ( L_48
L_49 ) ;
F_15 ( V_308 ) ;
} else {
V_36 = - V_23 ;
}
V_81:
if ( V_36 )
F_21 ( V_87 , L_50 , V_88 , V_36 ) ;
return V_36 ;
}
int F_71 ( struct V_12 * V_31 )
{
int V_36 = 0 ;
struct V_39 * V_319 ;
struct V_320 * V_320 ;
T_1 V_321 ;
char V_322 [ 256 ] ;
struct {
T_1 V_323 [ 2 ] ;
T_1 V_114 ;
} V_324 ;
T_1 * V_325 ;
T_1 * V_326 ;
T_1 * V_327 ;
T_1 V_328 ;
T_1 V_329 ;
T_1 V_57 ;
T_1 V_330 ;
T_1 V_331 ;
T_1 V_332 ;
const char * V_333 [] = { L_51 , L_52 , L_53 , L_54 ,
L_55 , L_56 , L_57 , L_58 ,
L_59 , L_60 , L_61 , L_62 } ;
const char * V_334 [] = { L_63 , L_64 , L_65 , L_66 } ;
struct V_313 * V_108 ;
struct V_7 * V_7 = V_31 -> V_80 ;
V_36 = F_18 ( V_7 , & V_319 ) ;
if ( ! V_319 ) {
F_69 ( L_67 , V_88 ) ;
V_36 = - V_20 ;
}
if ( ! V_36 ) {
V_36 = F_72 ( V_7 , & V_320 ) ;
if ( ! V_320 ) {
F_69 ( L_68 ,
V_88 ) ;
V_36 = - V_20 ;
}
}
if ( ! V_36 ) {
V_36 =
F_20 ( V_319 , V_314 , & V_321 ) ;
F_69 ( L_69 ,
V_88 , V_321 ) ;
if ( V_36 )
F_69 ( L_70 ,
V_88 ) ;
}
if ( ! V_36 )
V_36 = F_68 ( V_7 , & V_108 ) ;
V_324 . V_323 [ 0 ] = 0 ;
V_324 . V_323 [ 1 ] = 0 ;
if ( ! V_36 ) {
V_332 = 0 ;
while ( ( V_324 . V_323 [ 0 ] != V_335 ||
V_324 . V_323 [ 1 ] != V_336 ) &&
V_332 < V_337 ) {
V_36 = (* V_108 -> V_318 )( V_31 ,
( T_2 * ) & V_324 , ( T_1 ) V_321 ,
sizeof( V_324 ) , 0 ) ;
if ( V_36 )
break;
V_332 ++ ;
}
if ( V_324 . V_323 [ 0 ] != V_335 &&
V_324 . V_323 [ 1 ] != V_336 ) {
V_36 = - V_338 ;
F_23 ( L_71 ,
V_88 ) ;
}
}
if ( ! V_36 ) {
V_331 = V_324 . V_114 ;
if ( V_331 > V_339 )
V_331 = V_339 ;
V_325 = F_7 ( V_331 , V_317 ) ;
if ( ! V_325 ) {
V_36 = - V_23 ;
F_69 ( L_72
L_73 , V_88 ) ;
goto V_81;
}
V_326 = V_325 ;
V_327 = V_325 + V_331 / 4 ;
V_36 = (* V_108 -> V_318 )( V_31 ,
( T_2 * ) V_325 , ( T_1 ) V_321 ,
V_331 , 0 ) ;
if ( V_36 ) {
F_69 ( L_74 ,
V_88 ) ;
goto V_81;
}
F_23 ( L_75
L_76 ) ;
V_328 = V_325 [ 3 ] ;
if ( ! V_328 )
V_57 = V_325 [ 79 ] ;
else
V_57 = V_325 [ 80 ] ;
V_36 =
F_20 ( V_319 , V_93 , & V_329 ) ;
if ( V_36 ) {
V_36 = - V_20 ;
goto V_81;
}
if ( ( V_57 > V_329 ) && ( F_73 ( V_320 , V_57 ,
0x1000 , & V_330 , V_322 ) == 0 ) )
F_23 ( L_77 , V_57 , V_322 ,
V_57 - V_330 ) ;
else
F_23 ( L_78 , V_57 ) ;
V_325 += 4 ;
F_23 ( L_79
L_80 ) ;
if ( * V_325 < F_74 ( V_334 ) ) {
F_23 ( L_81 ,
V_334 [ * V_325 ++ ] ) ;
} else {
F_23 ( L_82 ) ;
F_15 ( V_326 ) ;
return - V_20 ;
}
F_23 ( L_83 , * V_325 ++ ) ;
F_23 ( L_84 , * V_325 ++ ) ;
F_23 ( L_85 , * V_325 ++ ) ;
F_23 ( L_86 , * V_325 ++ ) ;
F_23 ( L_87 , * V_325 ++ ) ;
F_23 ( L_88 , * V_325 ++ ) ;
F_23 ( L_89
L_80 ) ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ ) {
if ( V_57 == 4 || V_57 == 6 || V_57 == 8 )
F_23 ( L_90 ,
V_57 , * V_325 ++ , V_57 - 3 ) ;
else if ( V_57 == 15 )
F_23 ( L_91 ,
* V_325 ++ ) ;
else
F_23 ( L_92 , V_57 , * V_325 ++ ) ;
}
F_23 ( L_93 , * V_325 ++ ) ;
F_23 ( L_94 , * V_325 ++ ) ;
F_23 ( L_95 , * V_325 ++ ) ;
if ( ( * V_325 > V_329 ) && ( F_73 ( V_320 ,
* V_325 , 0x1000 , & V_330 , V_322 ) == 0 ) )
F_23 ( L_96
L_97 , * V_325 , V_322 ,
* V_325 - V_330 ) ;
else
F_23 ( L_96
L_98 , * V_325 ) ;
V_325 ++ ;
for ( V_57 = 4 ; V_57 < 32 ; V_57 ++ ) {
if ( V_57 == 4 || V_57 == 6 || V_57 == 8 )
F_23 ( L_99 ,
V_57 , * V_325 ++ , V_57 - 2 ) ;
else if ( V_57 == 14 )
F_23 ( L_100 ,
* V_325 ++ ) ;
else
F_23 ( L_101 , V_57 , * V_325 ++ ) ;
}
F_23 ( L_102 ) ;
for ( V_57 = 0 ; V_57 < F_74 ( V_333 ) ; V_57 ++ )
F_23 ( L_103 , V_333 [ V_57 ] , * V_325 ++ ) ;
F_23 ( L_104
L_105 ) ;
for ( V_57 = 0 ; V_325 < V_327 ; V_57 ++ , V_325 ++ ) {
if ( ( * V_325 > V_329 ) && (
F_73 ( V_320 , * V_325 , 0x600 ,
& V_330 , V_322 ) == 0 ) )
F_23 ( L_106 ,
V_57 , * V_325 , V_322 ,
* V_325 - V_330 ) ;
else
F_23 ( L_107 , V_57 , * V_325 ) ;
}
F_15 ( V_326 ) ;
}
V_81:
return V_36 ;
}
void F_75 ( struct V_12 * V_31 )
{
struct V_39 * V_319 ;
struct V_313 * V_108 ;
struct V_12 * V_340 = V_31 ;
struct V_7 * V_7 = V_340 -> V_80 ;
struct V_341 V_342 ;
struct V_343 * V_344 = NULL ;
T_1 V_345 ;
T_1 V_346 ;
T_1 V_347 = 0 ;
T_1 V_348 ;
char * V_349 ;
int V_36 = 0 ;
V_36 = F_68 ( V_7 , & V_108 ) ;
if ( V_36 ) {
F_69 ( L_108 , V_88 ) ;
goto V_81;
}
V_36 = F_18 ( V_7 , & V_319 ) ;
if ( ! V_319 ) {
F_69 ( L_67 , V_88 ) ;
V_36 = - V_20 ;
goto V_81;
}
V_36 = F_20 ( V_319 , L_109 , & V_345 ) ;
if ( V_36 ) {
F_69 ( L_110 ,
V_88 ) ;
goto V_81;
}
F_69 ( L_111 , V_88 , V_345 ) ;
V_36 = (* V_108 -> V_318 )( V_31 , ( T_2 * ) & V_342 ,
( T_1 ) V_345 , sizeof( V_342 ) , 0 ) ;
if ( V_36 ) {
F_69 ( L_112 ,
V_88 ) ;
goto V_81;
}
V_345 = V_342 . V_350 ;
V_346 = V_342 . V_351 ;
F_69 ( L_113 , V_88 , V_345 ,
V_346 ) ;
F_23 ( L_114
L_115 ) ;
while ( V_346 ) {
if ( V_346 > V_347 ) {
F_15 ( V_344 ) ;
V_344 = F_7 ( V_346 + 128 , V_317 ) ;
V_347 = V_346 + 128 ;
F_69 ( L_116 ,
V_88 , V_344 , V_347 ) ;
if ( ! V_344 )
goto V_81;
}
V_36 = (* V_108 -> V_318 )( V_31 ,
( T_2 * ) V_344 , V_345 , V_346 , 0 ) ;
if ( V_36 ) {
F_69 (
L_117 ,
V_88 , V_345 ) ;
break;
}
V_345 = V_344 -> V_352 ;
V_346 = V_344 -> V_353 ;
F_69 ( L_118 ,
V_88 , V_345 , V_346 ,
V_344 -> V_354 ) ;
V_349 = ( char * ) & V_344 ->
V_355 [ V_344 -> V_354 ] ;
F_23 ( L_47 , V_349 ) ;
V_349 += strlen ( V_349 ) + 1 ;
for ( V_348 = 0 ;
V_348 < V_344 -> V_354 ; V_348 ++ ) {
F_23 ( L_119 ,
V_344 -> V_355 [ V_348 ] . V_356 ) ;
if ( ( ( T_1 ) V_349 - ( T_1 ) V_344 ) <
V_347 ) {
F_23 ( L_47 , V_349 ) ;
V_349 += strlen ( V_349 ) + 1 ;
} else {
F_23 ( L_120 ) ;
F_69 ( L_121
L_122 , V_88 , V_349 ) ;
}
}
}
V_81:
F_15 ( V_344 ) ;
}
