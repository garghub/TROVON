static inline unsigned int F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_3 ;
if ( V_2 >= V_1 )
return F_2 ( V_2 - V_1 ) ;
return F_2 ( V_2 + ( V_4 - V_1 ) + 1 ) ;
}
static char * F_3 ( struct V_5 * V_6 ,
char * V_1 , char * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
char V_12 [ V_13 ] ;
char * V_14 ;
struct V_15 V_16 ;
int V_17 , V_18 ;
char * V_19 ;
T_1 V_20 ;
V_16 . V_21 = V_22 ;
V_16 . V_23 . V_24 . V_25 = V_26 ;
memcpy ( V_16 . V_23 . V_24 . V_27 , V_9 -> V_28 , V_29 ) ;
V_1 = F_4 ( V_11 , V_1 , V_7 , & V_16 , V_30 ) ;
V_16 . V_21 = V_31 ;
V_16 . V_23 . V_32 . V_33 = 1 ;
V_16 . V_23 . V_32 . V_34 = F_5 ( V_9 -> V_35 , ( T_1 ) 32 ) ;
V_1 = F_6 ( V_11 , V_1 , V_7 ,
& V_16 , V_9 -> V_36 ) ;
V_16 . V_21 = V_37 ;
snprintf ( V_16 . V_23 . V_38 , V_39 , L_1 ,
V_40 [ V_9 -> V_41 ] ) ;
V_1 = F_4 ( V_11 , V_1 , V_7 , & V_16 , V_42 ) ;
V_16 . V_21 = V_43 ;
if ( V_9 -> V_44 & ( V_45 | V_46 ) ) {
if ( V_9 -> V_44 & V_45 )
V_16 . V_23 . V_41 = V_47 ;
else
V_16 . V_23 . V_41 = V_48 ;
V_1 = F_4 ( V_11 , V_1 , V_7 ,
& V_16 , V_49 ) ;
}
V_16 . V_21 = V_50 ;
V_16 . V_23 . V_51 . V_52 = F_7 ( V_6 , V_9 -> V_53 ) ;
V_16 . V_23 . V_51 . V_54 = 6 ;
V_16 . V_23 . V_51 . V_17 = 0 ;
V_1 = F_4 ( V_11 , V_1 , V_7 , & V_16 , V_55 ) ;
V_16 . V_21 = V_56 ;
if ( V_9 -> V_44 & V_57 )
V_16 . V_23 . V_32 . V_33 = V_58 | V_59 ;
else
V_16 . V_23 . V_32 . V_33 = V_60 ;
V_16 . V_23 . V_32 . V_34 = 0 ;
V_1 = F_6 ( V_11 , V_1 , V_7 ,
& V_16 , V_9 -> V_36 ) ;
V_19 = V_1 + F_8 ( V_11 ) ;
V_16 . V_21 = V_61 ;
V_16 . V_23 . V_62 . V_63 = V_16 . V_23 . V_62 . V_64 = 0 ;
for ( V_17 = 0 , V_18 = 0 ; V_17 < V_9 -> V_65 ; ) {
if ( V_18 < V_9 -> V_66 &&
( ( V_9 -> V_67 [ V_18 ] & 0x7F ) <
( V_9 -> V_68 [ V_17 ] & 0x7F ) ) )
V_20 = V_9 -> V_67 [ V_18 ++ ] & 0x7F ;
else
V_20 = V_9 -> V_68 [ V_17 ++ ] & 0x7F ;
V_16 . V_23 . V_62 . V_69 = ( ( V_20 & 0x7f ) * 500000 ) ;
V_19 = F_9 ( V_11 , V_1 , V_19 ,
V_7 , & V_16 , V_70 ) ;
}
for (; V_18 < V_9 -> V_66 ; V_18 ++ ) {
V_20 = V_9 -> V_67 [ V_18 ] & 0x7F ;
V_16 . V_23 . V_62 . V_69 = ( ( V_20 & 0x7f ) * 500000 ) ;
V_19 = F_9 ( V_11 , V_1 , V_19 ,
V_7 , & V_16 , V_70 ) ;
}
if ( ( V_19 - V_1 ) > F_8 ( V_11 ) )
V_1 = V_19 ;
V_16 . V_21 = V_71 ;
V_16 . V_23 . V_72 . V_73 = V_74 | V_75 |
V_76 ;
if ( ! ( V_9 -> V_77 . V_78 & V_79 ) ) {
V_16 . V_23 . V_72 . V_73 |= V_80 |
V_81 ;
V_16 . V_23 . V_72 . V_72 = 0 ;
} else {
if ( V_6 -> V_82 == V_6 -> V_83 )
V_16 . V_23 . V_72 . V_72 = 100 ;
else
V_16 . V_23 . V_72 . V_72 =
( 100 *
( V_6 -> V_82 - V_6 -> V_83 ) *
( V_6 -> V_82 - V_6 -> V_83 ) -
( V_6 -> V_82 - V_9 -> V_77 . V_84 ) *
( 15 * ( V_6 -> V_82 - V_6 -> V_83 ) +
62 * ( V_6 -> V_82 -
V_9 -> V_77 . V_84 ) ) ) /
( ( V_6 -> V_82 -
V_6 -> V_83 ) * ( V_6 -> V_82 -
V_6 -> V_83 ) ) ;
if ( V_16 . V_23 . V_72 . V_72 > 100 )
V_16 . V_23 . V_72 . V_72 = 100 ;
else if ( V_16 . V_23 . V_72 . V_72 < 1 )
V_16 . V_23 . V_72 . V_72 = 0 ;
}
if ( ! ( V_9 -> V_77 . V_78 & V_85 ) ) {
V_16 . V_23 . V_72 . V_73 |= V_86 ;
V_16 . V_23 . V_72 . V_87 = 0 ;
} else {
V_16 . V_23 . V_72 . V_87 = V_9 -> V_77 . V_87 ;
}
if ( ! ( V_9 -> V_77 . V_78 & V_88 ) ) {
V_16 . V_23 . V_72 . V_73 |= V_81 ;
V_16 . V_23 . V_72 . V_89 = 0 ;
} else {
V_16 . V_23 . V_72 . V_89 = V_9 -> V_77 . signal ;
}
V_1 = F_4 ( V_11 , V_1 , V_7 , & V_16 , V_90 ) ;
V_16 . V_21 = V_91 ;
V_14 = V_12 ;
V_16 . V_23 . V_32 . V_34 = V_14 - V_12 ;
if ( V_16 . V_23 . V_32 . V_34 )
V_1 = F_6 ( V_11 , V_1 , V_7 , & V_16 , V_12 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( V_9 -> V_92 ) {
char V_93 [ V_94 ] ;
memcpy ( V_93 , V_9 -> V_95 , V_9 -> V_92 ) ;
V_16 . V_21 = V_96 ;
V_16 . V_23 . V_32 . V_34 = V_9 -> V_92 ;
V_1 = F_6 ( V_11 , V_1 , V_7 , & V_16 , V_93 ) ;
}
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( V_9 -> V_97 ) {
char V_93 [ V_94 ] ;
memcpy ( V_93 , V_9 -> V_98 , V_9 -> V_97 ) ;
V_16 . V_21 = V_96 ;
V_16 . V_23 . V_32 . V_34 = V_9 -> V_97 ;
V_1 = F_6 ( V_11 , V_1 , V_7 , & V_16 , V_93 ) ;
}
V_16 . V_21 = V_91 ;
V_14 = V_12 ;
V_14 += snprintf ( V_14 , V_13 - ( V_14 - V_12 ) ,
L_2 ,
F_1 ( V_9 -> V_99 ) ) ;
V_16 . V_23 . V_32 . V_34 = V_14 - V_12 ;
if ( V_16 . V_23 . V_32 . V_34 )
V_1 = F_6 ( V_11 , V_1 , V_7 , & V_16 , V_12 ) ;
V_16 . V_21 = - 1 ;
V_14 = V_12 ;
V_14 += snprintf ( V_14 , V_13 - ( V_14 - V_12 ) , L_3 ) ;
if ( F_10 ( V_6 , V_9 -> V_53 ) &
V_100 ) {
V_16 . V_21 = V_91 ;
V_14 += snprintf ( V_14 , V_13 - ( V_14 - V_12 ) , L_4 ) ;
}
if ( F_10 ( V_6 , V_9 -> V_53 ) &
V_101 ) {
V_16 . V_21 = V_91 ;
V_14 += snprintf ( V_14 , V_13 - ( V_14 - V_12 ) , L_5 ) ;
}
if ( V_16 . V_21 == V_91 ) {
V_16 . V_23 . V_32 . V_34 = V_14 - V_12 ;
V_1 = F_6 ( V_11 , V_1 , V_7 , & V_16 , V_12 ) ;
}
return V_1 ;
}
int F_11 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_102 * V_103 , char * V_104 )
{
struct V_8 * V_9 ;
unsigned long V_33 ;
int V_105 = 0 ;
char * V_106 = V_104 ;
char * V_7 = V_106 + V_103 -> V_32 . V_34 ;
int V_17 = 0 ;
F_12 ( V_36 ) ;
F_13 ( L_6 ) ;
F_14 ( & V_6 -> V_107 , V_33 ) ;
F_15 (network, &ieee->network_list, list) {
V_17 ++ ;
if ( V_7 - V_106 < V_108 ) {
V_105 = - V_109 ;
break;
}
if ( V_6 -> V_110 == 0 ||
F_16 ( V_9 -> V_99 + V_6 -> V_110 , V_3 ) )
V_106 = F_3 ( V_6 , V_106 , V_7 , V_9 ,
V_11 ) ;
else {
F_17 ( L_7
L_8 ,
F_18 ( V_36 , V_9 -> V_36 ,
V_9 -> V_35 ) ,
V_9 -> V_28 ,
F_1 (
V_9 -> V_99 ) ) ;
}
}
F_19 ( & V_6 -> V_107 , V_33 ) ;
V_103 -> V_32 . V_34 = V_106 - V_104 ;
V_103 -> V_32 . V_33 = 0 ;
F_13 ( L_9 , V_17 ) ;
return V_105 ;
}
int F_20 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_102 * V_103 , char * V_111 )
{
struct V_112 * V_113 = & ( V_103 -> V_114 ) ;
struct V_115 * V_116 = V_6 -> V_116 ;
struct V_117 V_118 = {
. V_33 = 0
} ;
int V_17 , V_119 , V_120 , V_121 ;
struct V_122 * * V_123 ;
int V_124 = V_6 -> V_125 || V_6 -> V_126 ;
F_12 ( V_36 ) ;
F_13 ( L_10 ) ;
V_119 = V_113 -> V_33 & V_127 ;
if ( V_119 ) {
if ( V_119 > V_128 )
return - V_129 ;
V_119 -- ;
V_120 = 1 ;
} else {
V_120 = 0 ;
V_119 = V_6 -> V_130 . V_131 ;
}
F_13 ( L_11 , V_119 , V_120 ?
L_12 : L_13 ) ;
V_123 = & V_6 -> V_130 . V_123 [ V_119 ] ;
if ( V_113 -> V_33 & V_60 ) {
if ( V_120 && * V_123 ) {
F_13 ( L_14 ,
V_119 ) ;
F_21 ( & V_6 -> V_130 , V_123 ) ;
} else
F_13 ( L_15 ) ;
for ( V_17 = 0 ; V_17 < V_128 ; V_17 ++ ) {
if ( V_6 -> V_130 . V_123 [ V_17 ] != NULL ) {
if ( V_120 )
break;
F_21 ( & V_6 -> V_130 ,
& V_6 -> V_130 . V_123 [ V_17 ] ) ;
}
}
if ( V_17 == V_128 ) {
V_118 . V_132 = 0 ;
V_118 . V_133 = 0 ;
V_118 . V_89 = V_134 ;
V_118 . V_33 |= V_135 | V_136 | V_137 ;
}
goto V_138;
}
V_118 . V_132 = 1 ;
V_118 . V_133 = 1 ;
V_118 . V_33 |= V_135 | V_137 ;
if ( * V_123 != NULL && ( * V_123 ) -> V_139 != NULL &&
strcmp ( ( * V_123 ) -> V_139 -> V_38 , L_16 ) != 0 ) {
F_21 ( & V_6 -> V_130 , V_123 ) ;
}
if ( * V_123 == NULL && V_124 ) {
struct V_122 * V_140 ;
V_140 = F_22 ( sizeof( struct V_122 ) ,
V_141 ) ;
if ( V_140 == NULL )
return - V_142 ;
V_140 -> V_139 = F_23 ( L_16 ) ;
if ( ! V_140 -> V_139 ) {
F_24 ( L_17 ) ;
V_140 -> V_139 = F_23 ( L_16 ) ;
}
if ( V_140 -> V_139 && F_25 ( V_140 -> V_139 -> V_143 ) )
V_140 -> V_144 = V_140 -> V_139 -> V_145 ( V_119 ) ;
if ( ! V_140 -> V_139 || ! V_140 -> V_144 ) {
F_26 ( V_140 ) ;
V_140 = NULL ;
F_27 ( V_146 L_18
L_19 , V_116 -> V_38 ) ;
return - V_147 ;
}
* V_123 = V_140 ;
}
if ( V_113 -> V_34 > 0 ) {
V_121 = V_113 -> V_34 <= 5 ? 5 : 13 ;
memcpy ( V_118 . V_148 [ V_119 ] , V_111 , V_113 -> V_34 ) ;
if ( V_121 > V_113 -> V_34 )
memset ( V_118 . V_148 [ V_119 ] + V_113 -> V_34 , 0 ,
V_121 - V_113 -> V_34 ) ;
F_13 ( L_20 ,
V_119 , F_18 ( V_36 , V_118 . V_148 [ V_119 ] , V_121 ) ,
V_113 -> V_34 , V_121 ) ;
V_118 . V_149 [ V_119 ] = V_121 ;
if ( * V_123 )
( * V_123 ) -> V_139 -> V_150 ( V_118 . V_148 [ V_119 ] , V_121 , NULL ,
( * V_123 ) -> V_144 ) ;
V_118 . V_33 |= ( 1 << V_119 ) ;
if ( V_119 == V_118 . V_151 )
V_118 . V_33 |= V_152 ;
} else {
if ( V_124 ) {
V_121 = ( * V_123 ) -> V_139 -> V_153 ( V_118 . V_148 [ V_119 ] , V_154 ,
NULL , ( * V_123 ) -> V_144 ) ;
if ( V_121 == 0 ) {
F_13 ( L_21
L_22 , V_119 ) ;
memset ( V_118 . V_148 [ V_119 ] , 0 , 13 ) ;
( * V_123 ) -> V_139 -> V_150 ( V_118 . V_148 [ V_119 ] , 13 , NULL ,
( * V_123 ) -> V_144 ) ;
V_118 . V_149 [ V_119 ] = 13 ;
V_118 . V_33 |= ( 1 << V_119 ) ;
}
}
if ( V_120 ) {
F_13 ( L_23
L_24 , V_119 ) ;
V_6 -> V_130 . V_131 = V_119 ;
V_118 . V_151 = V_119 ;
V_118 . V_33 |= V_152 ;
}
}
if ( V_113 -> V_33 & ( V_155 | V_156 ) ) {
V_6 -> V_157 = ! ( V_113 -> V_33 & V_156 ) ;
V_118 . V_158 = V_6 -> V_157 ? V_159 :
V_160 ;
V_118 . V_33 |= V_161 ;
F_13 ( L_25 ,
V_118 . V_158 == V_159 ?
L_26 : L_27 ) ;
}
V_118 . V_33 |= V_136 ;
V_118 . V_89 = V_162 ;
V_118 . V_163 [ V_119 ] = V_164 ;
V_138:
if ( V_6 -> V_165 )
V_6 -> V_165 ( V_116 , & V_118 ) ;
if ( V_6 -> V_166 &&
V_6 -> V_167 != V_168 &&
V_6 -> V_169 && V_6 -> V_169 ( V_116 ) ) {
F_27 ( V_170 L_28 , V_116 -> V_38 ) ;
return - V_129 ;
}
return 0 ;
}
int F_28 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_102 * V_103 , char * V_111 )
{
struct V_112 * V_113 = & ( V_103 -> V_114 ) ;
int V_121 , V_119 ;
struct V_122 * V_123 ;
struct V_117 * V_118 = & V_6 -> V_118 ;
F_13 ( L_29 ) ;
V_119 = V_113 -> V_33 & V_127 ;
if ( V_119 ) {
if ( V_119 > V_128 )
return - V_129 ;
V_119 -- ;
} else
V_119 = V_6 -> V_130 . V_131 ;
V_123 = V_6 -> V_130 . V_123 [ V_119 ] ;
V_113 -> V_33 = V_119 + 1 ;
if ( ! V_118 -> V_132 ) {
V_113 -> V_34 = 0 ;
V_113 -> V_33 |= V_60 ;
return 0 ;
}
V_121 = V_118 -> V_149 [ V_119 ] ;
memcpy ( V_111 , V_118 -> V_148 [ V_119 ] , V_121 ) ;
V_113 -> V_34 = V_121 ;
V_113 -> V_33 |= V_58 ;
if ( V_6 -> V_157 )
V_113 -> V_33 |= V_155 ;
else
V_113 -> V_33 |= V_156 ;
return 0 ;
}
int F_29 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_102 * V_103 , char * V_104 )
{
struct V_115 * V_116 = V_6 -> V_116 ;
struct V_112 * V_114 = & V_103 -> V_114 ;
struct V_171 * V_172 = (struct V_171 * ) V_104 ;
int V_17 , V_173 , V_174 = 0 ;
int V_175 = 0 ;
const char * V_176 , * V_177 ;
struct V_178 * V_139 ;
struct V_122 * * V_123 ;
struct V_117 V_118 = {
. V_33 = 0 ,
} ;
V_173 = V_114 -> V_33 & V_127 ;
if ( V_173 ) {
if ( V_173 < 1 || V_173 > V_128 )
return - V_129 ;
V_173 -- ;
} else
V_173 = V_6 -> V_130 . V_131 ;
if ( V_172 -> V_179 & V_180 ) {
V_123 = & V_6 -> V_130 . V_123 [ V_173 ] ;
V_175 = 1 ;
} else {
if ( V_173 != 0 && V_172 -> V_176 != V_181 )
return - V_129 ;
if ( V_6 -> V_167 == V_168 )
V_123 = & V_6 -> V_130 . V_123 [ V_173 ] ;
else
return - V_129 ;
}
V_118 . V_33 |= V_135 | V_137 ;
if ( ( V_114 -> V_33 & V_60 ) ||
V_172 -> V_176 == V_182 ) {
if ( * V_123 )
F_21 ( & V_6 -> V_130 , V_123 ) ;
for ( V_17 = 0 ; V_17 < V_128 ; V_17 ++ )
if ( V_6 -> V_130 . V_123 [ V_17 ] != NULL )
break;
if ( V_17 == V_128 ) {
V_118 . V_132 = 0 ;
V_118 . V_133 = 0 ;
V_118 . V_89 = V_134 ;
V_118 . V_33 |= V_136 ;
}
goto V_138;
}
V_118 . V_132 = 1 ;
V_118 . V_133 = 1 ;
if ( V_175 ? ! V_6 -> V_183 :
! ( V_6 -> V_125 || V_6 -> V_126 ||
V_6 -> V_184 ) )
goto V_185;
switch ( V_172 -> V_176 ) {
case V_181 :
V_176 = L_16 ;
V_177 = L_17 ;
break;
case V_186 :
V_176 = L_30 ;
V_177 = L_31 ;
break;
case V_187 :
V_176 = L_32 ;
V_177 = L_33 ;
break;
default:
F_13 ( L_34 ,
V_116 -> V_38 , V_172 -> V_176 ) ;
V_174 = - V_129 ;
goto V_138;
}
V_139 = F_23 ( V_176 ) ;
if ( V_139 == NULL ) {
F_24 ( V_177 ) ;
V_139 = F_23 ( V_176 ) ;
}
if ( V_139 == NULL ) {
F_13 ( L_34 ,
V_116 -> V_38 , V_172 -> V_176 ) ;
V_174 = - V_129 ;
goto V_138;
}
if ( * V_123 == NULL || ( * V_123 ) -> V_139 != V_139 ) {
struct V_122 * V_140 ;
F_21 ( & V_6 -> V_130 , V_123 ) ;
V_140 = F_22 ( sizeof( * V_140 ) , V_141 ) ;
if ( V_140 == NULL ) {
V_174 = - V_142 ;
goto V_138;
}
V_140 -> V_139 = V_139 ;
if ( V_140 -> V_139 && F_25 ( V_140 -> V_139 -> V_143 ) )
V_140 -> V_144 = V_140 -> V_139 -> V_145 ( V_173 ) ;
if ( V_140 -> V_144 == NULL ) {
F_26 ( V_140 ) ;
V_174 = - V_129 ;
goto V_138;
}
* V_123 = V_140 ;
}
if ( V_172 -> V_188 > 0 && ( * V_123 ) -> V_139 -> V_150 &&
( * V_123 ) -> V_139 -> V_150 ( V_172 -> V_119 , V_172 -> V_188 , V_172 -> V_189 ,
( * V_123 ) -> V_144 ) < 0 ) {
F_13 ( L_35 , V_116 -> V_38 ) ;
V_174 = - V_129 ;
goto V_138;
}
V_185:
if ( V_172 -> V_179 & V_190 ) {
V_6 -> V_130 . V_131 = V_173 ;
V_118 . V_151 = V_173 ;
V_118 . V_33 |= V_152 ;
}
if ( V_172 -> V_176 != V_182 ) {
memcpy ( V_118 . V_148 [ V_173 ] , V_172 -> V_119 , V_172 -> V_188 ) ;
V_118 . V_149 [ V_173 ] = V_172 -> V_188 ;
V_118 . V_33 |= ( 1 << V_173 ) ;
if ( V_172 -> V_176 == V_181 ) {
V_118 . V_163 [ V_173 ] = V_164 ;
V_118 . V_33 |= V_136 ;
V_118 . V_89 = V_162 ;
} else if ( V_172 -> V_176 == V_186 ) {
V_118 . V_163 [ V_173 ] = V_191 ;
V_118 . V_33 |= V_136 ;
V_118 . V_89 = V_192 ;
} else if ( V_172 -> V_176 == V_187 ) {
V_118 . V_163 [ V_173 ] = V_193 ;
V_118 . V_33 |= V_136 ;
V_118 . V_89 = V_194 ;
}
if ( V_175 )
V_118 . V_33 &= ~ V_136 ;
}
V_138:
if ( V_6 -> V_165 )
V_6 -> V_165 ( V_6 -> V_116 , & V_118 ) ;
if ( V_6 -> V_166 &&
V_6 -> V_167 != V_168 &&
V_6 -> V_169 && V_6 -> V_169 ( V_116 ) ) {
F_13 ( L_28 , V_116 -> V_38 ) ;
return - V_129 ;
}
return V_174 ;
}
int F_30 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
union V_102 * V_103 , char * V_104 )
{
struct V_112 * V_114 = & V_103 -> V_114 ;
struct V_171 * V_172 = (struct V_171 * ) V_104 ;
struct V_117 * V_118 = & V_6 -> V_118 ;
int V_173 , V_195 ;
V_195 = V_114 -> V_34 - sizeof( * V_172 ) ;
if ( V_195 < 0 )
return - V_129 ;
V_173 = V_114 -> V_33 & V_127 ;
if ( V_173 ) {
if ( V_173 < 1 || V_173 > V_128 )
return - V_129 ;
V_173 -- ;
} else
V_173 = V_6 -> V_130 . V_131 ;
if ( ! ( V_172 -> V_179 & V_180 ) &&
V_172 -> V_176 != V_181 )
if ( V_173 != 0 || V_6 -> V_167 != V_168 )
return - V_129 ;
V_114 -> V_33 = V_173 + 1 ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
if ( ! V_118 -> V_132 ) {
V_172 -> V_176 = V_182 ;
V_172 -> V_188 = 0 ;
V_114 -> V_33 |= V_60 ;
} else {
if ( V_118 -> V_163 [ V_173 ] == V_164 )
V_172 -> V_176 = V_181 ;
else if ( V_118 -> V_163 [ V_173 ] == V_191 )
V_172 -> V_176 = V_186 ;
else if ( V_118 -> V_163 [ V_173 ] == V_193 )
V_172 -> V_176 = V_187 ;
else
return - V_129 ;
V_172 -> V_188 = V_118 -> V_149 [ V_173 ] ;
memcpy ( V_172 -> V_119 , V_118 -> V_148 [ V_173 ] , V_172 -> V_188 ) ;
V_114 -> V_33 |= V_58 ;
if ( V_172 -> V_188 &&
( V_172 -> V_176 == V_186 ||
V_172 -> V_176 == V_187 ) )
V_172 -> V_179 |= V_196 ;
}
return 0 ;
}
