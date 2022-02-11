static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
char * V_5 ;
if ( F_2 ( V_4 ) -> V_6 & ( 1 << V_7 ) ) {
V_5 = L_1 ;
} else if ( F_2 ( V_4 ) -> V_6 & ( 1 << V_8 ) ) {
V_5 = L_2 ;
} else {
V_5 = L_3 ;
}
F_3 ( V_2 , L_4 , V_5 ,
#if F_4 ( V_9 )
L_5
#else
L_6
#endif
) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
F_3 ( V_2 , L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33 ,
F_6 ( V_12 ) == V_13 ?
L_34 : L_35 ,
F_7 ( V_4 ) ? L_36 : L_37 ,
F_8 ( V_4 ) ? L_38 : L_37 ,
F_9 ( V_4 ) ? L_39 : L_37 ,
F_10 ( V_4 ) ? L_40 : L_37 ,
F_11 ( V_4 ) ? L_41 : L_42 ,
F_12 ( V_4 ) ?
L_43 : L_37 ,
F_13 ( V_4 ) ? L_44 : L_37 ,
F_14 ( V_4 ) ? L_45 : L_37 ,
F_15 ( V_4 ) ? L_46 : F_16 ( V_4 ) ?
L_47 : L_48 ,
F_17 ( V_4 ) ? L_49 : L_37 ,
F_18 ( V_4 ) ? L_50 : L_37 ,
F_19 ( & V_11 -> V_14 ) ,
F_6 ( V_15 ) , F_6 ( V_16 ) , F_6 ( V_17 ) ,
F_6 ( V_18 ) , F_6 ( V_19 ) ,
F_6 ( V_20 ) , F_6 ( V_21 ) ,
F_6 ( V_22 ) , F_6 ( V_23 ) ,
F_6 ( V_24 ) , F_20 ( V_25 ) , F_20 ( V_26 ) ,
F_20 ( V_27 ) , F_20 ( V_28 ) ,
F_20 ( V_29 ) , F_20 ( V_30 ) ,
F_20 ( V_31 ) , F_20 ( V_32 ) ,
F_20 ( V_33 ) ,
F_20 ( V_34 ) , F_20 ( V_35 ) ,
F_20 ( V_36 ) , F_20 ( V_37 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
int V_38 ;
F_3 ( V_2 , L_51
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62
L_63
L_64 L_65 L_66 L_20 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
F_3 ( V_2 , L_67
L_68
L_68
L_68
L_68
L_68
L_68
L_68
L_69
L_69
L_69
L_69
L_68
L_68
L_68
L_68
L_20 ,
V_38 ,
F_22 ( V_40 ) ,
F_22 ( V_41 ) ,
F_22 ( V_42 ) ,
F_22 ( V_43 ) ,
F_22 ( V_44 ) ,
F_22 ( V_45 ) ,
F_22 ( V_46 ) ,
F_22 ( V_47 ) ,
F_22 ( V_48 ) ,
F_22 ( V_49 ) ,
F_22 ( V_50 ) ,
F_22 ( V_51 ) ,
F_22 ( V_52 ) ,
F_22 ( V_53 ) , F_22 ( V_54 )
) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
F_3 ( V_2 , L_70
L_71
L_72
L_73
L_74
L_75
L_76
L_77
L_20
L_78
L_78
L_78
L_78
L_78
L_78
L_78
L_20 ,
F_20 ( V_55 ) ,
F_24 ( V_56 ) ,
F_24 ( V_57 ) ,
F_24 ( V_58 ) ,
F_24 ( V_59 ) ,
F_24 ( V_60 ) ,
F_24 ( V_61 ) , F_24 ( V_62 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_63 = F_2 ( V_4 ) ;
struct V_64 * V_65 = V_63 -> V_66 ;
int V_67 = F_26 ( V_68 ) ;
T_1 V_69 = F_27 ( V_70 ) ;
F_3 ( V_2 , L_79
L_80
L_81
L_82
L_83
L_84
L_85
L_86
L_87
L_88
L_89
L_90
L_91
L_92
L_93 ,
F_26 ( V_71 ) ,
F_26 ( V_72 ) ,
F_26 ( V_73 ) ,
F_28 ( V_74 ) ,
F_28 ( V_75 ) ,
F_28 ( V_76 ) ,
F_28 ( V_77 ) ,
V_65 -> V_78 . V_79 ,
F_28 ( V_80 ) ,
V_67 == V_81 ? L_94 :
( V_67 == V_82 ) ? L_95 :
( V_67 == V_83 ) ? L_96 :
( V_67 == V_84 ) ? L_97 : L_3 ,
F_28 ( V_85 ) ,
F_28 ( V_86 ) ,
F_28 ( V_87 ) , V_69 , ( V_69 & V_88 )
? L_98 : L_37 , F_28 ( V_89 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_63 = F_2 ( V_4 ) ;
struct V_64 * V_65 = V_63 -> V_66 ;
unsigned int V_90 = F_30 ( V_65 -> V_78 . V_76 ) ;
unsigned long V_91 = 0 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_90 ; ++ V_92 ) {
T_1 V_93 ;
V_93 = ( V_92 == V_90 - 1 ) ? V_94 : F_31 ( V_92 + 1 ) ;
F_3 ( V_2 , L_99 ,
( V_92 & 1 ) ? L_100 : L_101 , F_31 ( V_92 ) , V_93 ) ;
if ( ! ( V_92 & 1 ) ) {
V_91 += V_93 - F_31 ( V_92 ) ;
}
}
#if F_4 ( V_95 )
if ( V_63 -> V_96 . V_97 && ( V_63 -> V_96 . V_98 != NULL ) ) {
T_2 V_99 = F_32 ( V_63 -> V_96 . V_98 ) -> V_100 ;
V_91 += V_99 / sizeof( V_101 ) ;
}
#endif
F_3 ( V_2 , L_102 ,
V_90 ,
V_90 , F_30 ( V_65 -> V_78 . V_75 ) , V_91 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = F_2 ( V_4 ) ;
struct V_64 * V_65 = V_11 -> V_66 ;
struct V_102 * V_103 = & V_65 -> V_78 . V_104 ;
char V_105 [ V_106 ] ;
F_3 ( V_2 ,
L_103
L_104
L_105
L_106
L_107
L_108
L_109
L_110
L_111
L_112
L_113
L_114
L_115
L_116
L_117
L_118
L_119
L_120
L_121
L_122
L_123
L_124
L_125
L_126
L_127 L_128 L_20
L_129
L_130
L_131
L_132
L_133
L_134
L_135
L_136
L_137
L_138
L_139
L_140
L_141
L_142 ,
F_34 ( V_107 ) ,
F_35 ( F_36 ( V_4 ) -> V_108 , V_105 ) ,
F_34 ( V_109 ) ,
F_34 ( V_110 ) ,
F_34 ( V_111 ) ,
F_34 ( V_112 ) ,
F_34 ( V_113 ) ,
F_36 ( V_4 ) -> V_114 ,
F_34 ( V_115 ) ,
F_37 ( V_116 ) ,
F_37 ( V_117 ) ,
F_37 ( V_118 ) ,
F_37 ( V_119 ) ,
F_37 ( V_120 ) ,
F_37 ( V_121 ) ,
F_37 ( V_122 ) ,
F_19 ( & V_11 -> V_104 -> V_123 ) ,
F_37 ( V_124 ) ,
F_37 ( V_125 ) ,
F_37 ( V_126 ) ,
F_37 ( V_127 ) ,
F_37 ( V_128 ) ,
F_37 ( V_129 ) ,
F_37 ( V_130 ) ,
F_37 ( V_131 ) ,
F_37 ( V_132 ) ,
F_37 ( V_133 ) ,
F_38 ( V_134 ) ,
F_38 ( V_135 ) ,
F_38 ( V_136 ) ,
F_38 ( V_137 ) ,
F_38 ( V_138 ) ,
F_38 ( V_139 ) ,
F_38 ( V_140 ) ,
F_38 ( V_141 ) ,
F_38 ( V_142 ) ,
F_38 ( V_143 ) ,
F_38 ( V_144 ) ,
F_38 ( V_145 ) , F_38 ( V_146 ) , F_38 ( V_147 )
) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , void * V_148 )
{
return V_148 == V_4 ;
}
static int F_40 ( struct V_3 * V_4 , void * V_148 )
{
return - V_149 ;
}
static void * F_41 ( struct V_1 * V_2 , T_2 * V_150 )
{
struct V_151 * V_152 = V_2 -> V_153 ;
T_2 V_154 = * V_150 ;
if ( V_154 )
return NULL ;
if ( F_42 ( F_43 ( & V_155 , F_39 , F_40 , 0 , V_152 -> V_4 ) ) )
return NULL ;
F_44 ( & V_152 -> V_4 -> V_156 ) ;
return V_152 -> V_4 ;
}
static void * F_45 ( struct V_1 * V_2 , void * V_157 , T_2 * V_150 )
{
++ * V_150 ;
if ( V_157 )
F_46 ( V_157 ) ;
return NULL ;
}
static void F_47 ( struct V_1 * V_2 , void * V_157 )
{
if ( V_157 )
F_46 ( V_157 ) ;
}
static int F_48 ( struct V_1 * V_2 , void * V_157 )
{
struct V_151 * V_152 = V_2 -> V_153 ;
return V_152 -> V_158 ( V_2 , V_157 ) ;
}
static int F_49 ( struct V_159 * V_159 , struct V_160 * V_160 )
{
struct V_151 * V_152 ;
int V_161 = F_50 ( V_160 , & V_162 ,
sizeof( struct V_151 ) ) ;
if ( ! V_161 ) {
struct V_1 * V_2 = V_160 -> V_163 ;
V_152 = V_2 -> V_153 ;
V_152 -> V_4 = F_51 ( V_159 ) ;
V_152 -> V_158 = F_52 ( V_159 ) ;
}
return V_161 ;
}
static void F_53 ( struct V_3 * V_4 , char * V_164 ,
int (* F_54) ( struct V_1 * , struct V_3 * ) )
{
F_55 ( V_164 , 0 , F_2 ( V_4 ) -> V_165 ,
& V_166 , F_54 ) ;
}
int F_56 ( struct V_3 * V_4 )
{
char V_105 [ V_106 ] ;
char * V_167 ;
F_57 ( V_105 , F_58 ( V_4 ) , V_106 ) ;
V_167 = strchr ( V_105 , '/' ) ;
if ( V_167 )
* V_167 = '!' ;
F_59 ( & F_60 ( V_4 ) . V_168 ) ;
F_2 ( V_4 ) -> V_165 = F_61 ( V_105 , 0 , V_169 , V_4 ) ;
if ( F_2 ( V_4 ) -> V_165 ) {
F_53 ( V_4 , L_143 , F_1 ) ;
F_53 ( V_4 , L_144 , F_5 ) ;
F_53 ( V_4 , L_145 , F_21 ) ;
F_53 ( V_4 , L_146 , F_23 ) ;
F_53 ( V_4 , L_147 , F_25 ) ;
F_53 ( V_4 , L_148 , F_29 ) ;
F_53 ( V_4 , L_149 , F_33 ) ;
return 0 ;
}
F_62 ( V_4 , L_150 ,
V_170 , V_105 ) ;
return 1 ;
}
int F_63 ( struct V_3 * V_4 )
{
struct V_171 * V_172 = F_2 ( V_4 ) -> V_165 ;
if ( V_172 ) {
char V_105 [ V_106 ] ;
char * V_167 ;
F_57 ( V_105 , F_58 ( V_4 ) , V_106 ) ;
V_167 = strchr ( V_105 , '/' ) ;
if ( V_167 )
* V_167 = '!' ;
F_64 ( V_105 , V_169 ) ;
F_2 ( V_4 ) -> V_165 = NULL ;
}
return 0 ;
}
int F_65 ( void )
{
if ( V_169 == NULL ) {
V_169 = F_66 ( V_170 , NULL ) ;
if ( ! V_169 ) {
F_62 ( NULL , L_151 ,
V_170 ) ;
return 1 ;
}
}
return 0 ;
}
int F_67 ( void )
{
if ( V_169 != NULL ) {
V_169 = NULL ;
F_68 ( V_170 , NULL ) ;
}
return 0 ;
}
