static
void
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = & ( V_2 -> V_4 ) ;
bool V_5 ;
V_5 = false ;
if ( ( V_3 -> V_6 == V_7 ) &&
( V_3 -> V_8 >= V_9 ) ) {
if ( ( V_3 -> V_10 <= V_11 ) &&
( V_3 -> V_12 > V_11 ) ) {
V_5 = true ;
}
if ( V_3 -> V_10 > V_11 )
V_5 = true ;
}
if ( V_5 )
F_2 ( V_2 -> V_13 , V_14 , V_15 ) ;
}
static
void
F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = & ( V_2 -> V_4 ) ;
if ( ( V_3 -> V_6 == V_7 ) &&
( V_3 -> V_8 >= V_9 ) ) {
F_4 ( V_2 -> V_13 , V_14 , V_15 ) ;
}
}
static
void
F_5 (
struct V_1 * V_2
)
{
unsigned char V_16 [] = { V_17 , 8 , 0x02 , 0x04 , 0x0B , 0x16 , 0x24 , 0x30 , 0x48 , 0x6C } ;
unsigned char V_18 [] = { V_19 , 4 , 0x0C , 0x12 , 0x18 , 0x60 } ;
unsigned char V_20 [] = { V_17 , 8 , 0x0C , 0x12 , 0x18 , 0x24 , 0x30 , 0x48 , 0x60 , 0x6C } ;
unsigned char V_21 [] = { V_17 , 4 , 0x02 , 0x04 , 0x0B , 0x16 } ;
unsigned char * V_22 ;
T_2 V_23 ;
T_1 V_3 = V_2 -> V_3 ;
unsigned int V_24 ;
if ( V_2 -> V_25 == V_26 )
V_22 = & V_20 [ 0 ] ;
else if ( V_2 -> V_25 == V_27 )
V_22 = & V_21 [ 0 ] ;
else
V_22 = & V_16 [ 0 ] ;
V_23 = F_6
(
V_2 ,
V_3 ,
V_3 -> V_28 ,
( V_29 ) V_3 -> V_30 ,
( V_31 ) V_22 ,
( V_31 ) V_18
) ;
if ( V_23 != NULL ) {
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
if ( F_7 ( V_2 , V_23 ) != V_32 )
F_8 ( L_1 ) ;
else
F_8 ( L_2 ) ;
}
}
}
static T_2
F_6 (
struct V_1 * V_2 ,
T_1 V_3 ,
unsigned char * V_33 ,
V_29 V_34 ,
V_31 V_35 ,
V_31 V_36
)
{
T_2 V_23 = NULL ;
T_3 V_37 ;
V_23 = ( T_2 ) V_3 -> V_38 ;
memset ( V_23 , 0 , sizeof( V_39 ) + V_40 ) ;
V_23 -> V_41 = ( V_42 ) ( ( unsigned char * ) V_23 + sizeof( V_39 ) ) ;
V_37 . V_43 = ( unsigned char * ) V_23 -> V_41 ;
V_37 . V_44 = V_40 ;
F_9 ( & V_37 ) ;
V_37 . V_45 -> V_46 . V_47 = F_10 (
(
F_11 ( V_48 ) |
F_12 ( V_49 )
) ) ;
memcpy ( V_37 . V_45 -> V_46 . V_50 , V_33 , V_51 ) ;
memcpy ( V_37 . V_45 -> V_46 . V_52 , V_3 -> V_53 , V_51 ) ;
memcpy ( V_37 . V_45 -> V_46 . V_54 , V_33 , V_55 ) ;
V_37 . V_34 = ( V_29 ) ( V_37 . V_43 + V_37 . V_44 ) ;
V_37 . V_44 += V_34 -> V_44 + V_56 ;
memcpy ( V_37 . V_34 , V_34 , V_34 -> V_44 + V_56 ) ;
V_37 . V_57 = ( V_31 ) ( V_37 . V_43 + V_37 . V_44 ) ;
V_37 . V_44 += V_35 -> V_44 + V_56 ;
memcpy ( V_37 . V_57 , V_35 , V_35 -> V_44 + V_56 ) ;
if ( V_2 -> V_25 == V_58 ) {
V_37 . V_59 = ( V_31 ) ( V_37 . V_43 + V_37 . V_44 ) ;
V_37 . V_44 += V_36 -> V_44 + V_56 ;
memcpy ( V_37 . V_59 , V_36 , V_36 -> V_44 + V_56 ) ;
}
V_23 -> V_60 = V_37 . V_44 ;
V_23 -> V_61 = V_37 . V_44 - V_62 ;
return V_23 ;
}
void
F_13 (
void * V_63 ,
unsigned int V_64
)
{
struct V_1 * V_2 = V_63 ;
F_14 ( & V_2 -> V_65 ) ;
V_2 -> V_65 . V_66 = ( unsigned long ) V_2 ;
V_2 -> V_65 . V_67 = ( V_68 ) V_69 ;
V_2 -> V_65 . V_70 = ( unsigned int ) F_15 ( ( V_64 * V_71 ) >> 10 ) ;
F_16 ( & V_2 -> V_65 ) ;
}
void
V_69 (
void * V_63
)
{
struct V_1 * V_2 = V_63 ;
T_1 V_3 = V_2 -> V_3 ;
V_29 V_72 ;
V_29 V_73 ;
T_4 V_74 ;
unsigned int V_24 ;
unsigned char V_75 [ 8 ] = { 1 , 2 , 4 , 8 , 0x10 , 0x20 , 0x40 , 0x80 } ;
struct V_76 * V_77 ;
if ( V_2 -> V_78 != 0 )
return;
if ( ! V_2 -> V_79 )
return;
F_17 ( & V_2 -> V_80 ) ;
switch ( V_2 -> V_81 ) {
case V_82 :
V_2 -> V_83 = 0 ;
if ( V_2 -> V_84 ) {
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
if ( V_3 -> V_6 == V_85 ) {
F_18 ( V_2 ) ;
F_20 ( V_3 -> V_86 , V_3 -> V_87 , V_88 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
F_8 ( L_3 ) ;
V_72 = ( V_29 ) V_3 -> V_30 ;
if ( V_2 -> V_89 [ V_90 ] != 0 ) {
F_19 ( & V_2 -> V_80 ) ;
F_13 ( ( void * ) V_2 , 10 ) ;
return;
}
if ( V_3 -> V_12 == 0 ) {
V_3 -> V_12 = V_2 -> V_91 ;
}
if ( V_3 -> V_12 > V_2 -> V_92 ) {
V_3 -> V_93 = V_94 ;
F_21 ( V_3 -> V_86 , V_3 -> V_95 ) ;
F_8 ( L_4 ,
V_3 -> V_95 ) ;
if ( V_3 -> V_6 == V_7 )
F_20 ( V_3 -> V_86 , V_3 -> V_87 , V_96 ) ;
else
F_20 ( V_3 -> V_86 , V_3 -> V_87 , V_97 ) ;
F_3 ( V_2 ) ;
F_18 ( V_2 ) ;
} else {
if ( ! F_22 ( V_3 -> V_12 ) ) {
F_8 ( L_5 ,
V_3 -> V_12 ) ;
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
if ( V_3 -> V_12 == V_2 -> V_91 ) {
V_3 -> V_28 [ 0 ] = 0xFF ;
V_3 -> V_28 [ 1 ] = 0xFF ;
V_3 -> V_28 [ 2 ] = 0xFF ;
V_3 -> V_28 [ 3 ] = 0xFF ;
V_3 -> V_28 [ 4 ] = 0xFF ;
V_3 -> V_28 [ 5 ] = 0xFF ;
V_72 -> V_98 = V_99 ;
V_3 -> V_93 = V_100 ;
}
F_1 ( V_2 ) ;
if ( F_21 ( V_3 -> V_86 , V_3 -> V_12 ) )
F_8 ( L_6 ,
V_3 -> V_12 ) ;
else
F_8 ( L_7 ,
V_3 -> V_12 ) ;
F_20 ( V_3 -> V_86 , V_3 -> V_87 , V_101 ) ;
V_3 -> V_12 ++ ;
if ( ! F_22 ( V_3 -> V_12 ) &&
V_3 -> V_12 <= V_2 -> V_92 ) {
V_3 -> V_12 = V_2 -> V_92 + 1 ;
V_3 -> V_81 = V_102 ;
}
if ( ! V_3 -> V_103 ||
( V_3 -> V_12 < V_11 ) ) {
F_5 ( V_2 ) ;
F_19 ( & V_2 -> V_80 ) ;
F_13 ( ( void * ) V_2 , V_104 ) ;
return;
} else {
F_19 ( & V_2 -> V_80 ) ;
F_13 ( ( void * ) V_2 , V_105 ) ;
return;
}
}
break;
case V_102 :
F_21 ( V_3 -> V_86 , V_3 -> V_95 ) ;
F_8 ( L_4 ,
V_3 -> V_95 ) ;
if ( V_3 -> V_6 == V_7 )
F_20 ( V_3 -> V_86 , V_3 -> V_87 , V_96 ) ;
else
F_20 ( V_3 -> V_86 , V_3 -> V_87 , V_97 ) ;
V_3 -> V_93 = V_94 ;
F_3 ( V_2 ) ;
#ifdef F_23
if ( V_3 -> V_106 == V_107 ) {
union V_108 V_109 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
F_24 ( V_2 -> V_110 , V_111 , & V_109 , NULL ) ;
}
#endif
F_18 ( V_2 ) ;
break;
case V_112 :
V_2 -> V_83 = 0 ;
if ( ( V_3 -> V_6 == V_113 ) &&
( V_3 -> V_8 != V_114 ) ) {
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
} else {
F_8 ( L_8 ) ;
F_25 ( ( void * ) V_2 , V_3 , V_3 -> V_87 , ( 8 ) , & V_74 ) ;
V_2 -> V_115 = false ;
V_72 = ( V_29 ) V_3 -> V_116 ;
V_72 -> V_44 = 0 ;
memset ( V_72 -> V_117 , 0 , V_118 ) ;
V_3 -> V_8 = V_119 ;
V_3 -> V_120 [ 0 ] . V_121 = false ;
}
F_26 ( V_2 -> V_110 ) ;
V_2 -> V_81 = V_122 ;
if ( V_2 -> V_89 [ V_123 ] != 0 ) {
F_13 ( ( void * ) V_2 , 10 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
F_8 ( L_9 ) ;
F_18 ( V_2 ) ;
break;
case V_122 :
if ( V_2 -> V_89 [ V_123 ] != 0 ) {
F_13 ( ( void * ) V_2 , 10 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
F_18 ( V_2 ) ;
break;
case V_124 :
V_2 -> V_83 = 0 ;
if ( V_2 -> V_84 ) {
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
F_8 ( L_10 , ( ( V_29 ) V_3 -> V_125 ) -> V_117 ) ;
V_72 = ( V_29 ) V_3 -> V_125 ;
V_73 = ( V_29 ) V_3 -> V_116 ;
F_8 ( L_11 , V_72 -> V_117 ) ;
F_8 ( L_12 , V_73 -> V_117 ) ;
if ( V_3 -> V_8 == V_114 ) {
F_8 ( L_13 ) ;
F_8 ( L_14 , V_72 -> V_44 ) ;
F_8 ( L_15 ,
V_73 -> V_44 ) ;
F_8 ( L_16 , V_72 -> V_117 ) ;
F_8 ( L_17 , V_73 -> V_117 ) ;
}
if ( ( V_3 -> V_8 == V_114 ) ||
( ( V_3 -> V_6 == V_7 ) && ( V_3 -> V_8 == V_126 ) ) ) {
if ( V_72 -> V_44 == V_73 -> V_44 ) {
if ( memcmp ( V_72 -> V_117 , V_73 -> V_117 , V_72 -> V_44 ) == 0 ) {
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
}
F_26 ( V_2 -> V_110 ) ;
V_2 -> V_115 = false ;
}
V_3 -> V_8 = V_119 ;
V_3 -> V_6 = V_127 ;
F_27 ( ( void * ) V_2 ) ;
F_28 ( V_2 , 0 ) ;
F_29 ( ( void * ) V_2 , & V_74 ) ;
if ( ( V_3 -> V_6 == V_113 ) && ( V_3 -> V_8 == V_126 ) ) {
if ( V_3 -> V_8 >= V_128 )
F_30 ( ( void * ) V_2 , V_3 , V_3 -> V_87 , ( 3 ) , & V_74 ) ;
F_31 ( ( void * ) V_2 , V_3 , & V_74 ) ;
if ( V_74 == V_129 ) {
V_2 -> V_130 = 0 ;
V_2 -> V_81 = V_131 ;
F_13 ( ( void * ) V_2 , V_132 ) ;
F_19 ( & V_2 -> V_80 ) ;
F_8 ( L_18 ) ;
return;
}
}
else if ( V_3 -> V_6 == V_7 ) {
if ( V_3 -> V_8 == V_126 ) {
if ( F_32 ( V_2 -> V_110 ) )
F_33 ( V_2 -> V_110 ) ;
V_2 -> V_115 = true ;
V_3 -> V_120 [ 0 ] . V_121 = true ;
V_3 -> V_120 [ 0 ] . V_133 = 0 ;
F_34 ( V_2 ) ;
} else {
F_35 ( ( void * ) V_2 , & V_74 ) ;
if ( V_74 != V_129 )
F_8 ( L_19 ) ;
F_36 ( V_2 ) ;
}
}
else if ( V_3 -> V_6 == V_127 ) {
if ( V_3 -> V_134 == V_135 ||
V_3 -> V_134 == V_136 ) {
F_35 ( ( void * ) V_2 , & V_74 ) ;
if ( V_74 != V_129 )
F_8 ( L_19 ) ;
F_36 ( V_2 ) ;
if ( F_32 ( V_2 -> V_110 ) )
F_33 ( V_2 -> V_110 ) ;
V_2 -> V_115 = true ;
} else {
F_8 ( L_20 ) ;
#ifdef F_23
{
union V_108 V_109 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_137 . V_138 = V_139 ;
F_8 ( L_21 ) ;
F_24 ( V_2 -> V_110 , V_140 , & V_109 , NULL ) ;
}
#endif
}
}
F_18 ( V_2 ) ;
break;
case V_131 :
F_8 ( L_22 ) ;
if ( V_3 -> V_8 == V_128 ) {
V_2 -> V_130 = 0 ;
F_8 ( L_23 ) ;
F_37 ( ( void * ) V_2 , V_3 , & V_74 ) ;
if ( V_74 == V_129 ) {
V_2 -> V_130 = 0 ;
F_8 ( L_24 ) ;
V_2 -> V_81 = V_141 ;
F_13 ( ( void * ) V_2 , V_142 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
}
else if ( V_3 -> V_8 < V_143 ) {
F_8 ( L_25 ) ;
} else if ( V_2 -> V_130 <= 4 ) {
V_2 -> V_130 ++ ;
F_8 ( L_26 , V_2 -> V_130 ) ;
F_19 ( & V_2 -> V_80 ) ;
F_13 ( ( void * ) V_2 , V_132 / 2 ) ;
return;
}
V_2 -> V_130 = 0 ;
F_18 ( V_2 ) ;
break;
case V_141 :
if ( V_3 -> V_8 == V_114 ) {
F_8 ( L_27 ) ;
if ( V_2 -> V_144 != V_145 )
F_38 ( ( void * ) V_2 , V_3 -> V_146 ) ;
if ( V_3 -> V_147 >= V_148 )
F_39 ( & ( V_2 -> V_149 ) , V_2 -> V_150 , V_2 -> V_13 ) ;
V_2 -> V_115 = true ;
V_2 -> V_130 = 0 ;
V_2 -> V_83 = 0 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_151 ) {
F_40 ( V_2 -> V_13 ) ;
F_41 ( V_2 ) ;
}
if ( F_32 ( V_2 -> V_110 ) )
F_33 ( V_2 -> V_110 ) ;
if ( V_2 -> V_152 ) {
F_42 ( & V_2 -> V_153 ) ;
F_14 ( & V_2 -> V_153 ) ;
V_2 -> V_153 . V_66 = ( unsigned long ) V_2 ;
V_2 -> V_153 . V_67 = ( V_68 ) V_154 ;
V_2 -> V_153 . V_70 = F_15 ( 10 * V_71 ) ;
V_2 -> V_155 = false ;
V_2 -> V_156 = 0 ;
}
V_2 -> V_152 = true ;
F_16 ( & V_2 -> V_153 ) ;
} else if ( V_3 -> V_8 < V_157 ) {
F_43 ( L_28 ) ;
} else if ( V_2 -> V_130 <= 4 ) {
V_2 -> V_130 ++ ;
F_8 ( L_29 , V_2 -> V_130 ) ;
F_19 ( & V_2 -> V_80 ) ;
F_13 ( ( void * ) V_2 , V_142 / 2 ) ;
return;
}
V_2 -> V_130 = 0 ;
F_18 ( V_2 ) ;
break;
case V_158 :
F_8 ( L_30 ) ;
if ( V_3 -> V_134 == V_159 ) {
F_42 ( & V_3 -> V_160 ) ;
V_3 -> V_8 = V_119 ;
V_3 -> V_6 = V_127 ;
V_2 -> V_115 = false ;
if ( V_2 -> V_161 )
F_28 ( V_2 , 1 ) ;
else
F_28 ( V_2 , 0 ) ;
V_2 -> V_162 = 0 ;
V_3 -> V_8 = V_119 ;
V_2 -> V_163 = false ;
F_35 ( ( void * ) V_2 , & V_74 ) ;
if ( V_74 != V_129 )
F_8 ( L_31 ) ;
F_2 ( V_2 -> V_13 , V_164 , V_165 ) ;
V_2 -> V_166 &= ~ V_165 ;
F_8 ( L_32 , V_2 -> V_166 ) ;
F_36 ( V_2 ) ;
if ( F_32 ( V_2 -> V_110 ) )
F_33 ( V_2 -> V_110 ) ;
V_2 -> V_115 = true ;
F_16 ( & V_3 -> V_160 ) ;
}
F_18 ( V_2 ) ;
break;
case V_167 :
if ( V_3 -> V_120 [ 0 ] . V_168 ) {
while ( ( V_77 = F_44 ( & V_3 -> V_120 [ 0 ] . V_169 ) ) != NULL ) {
if ( F_45 ( & V_3 -> V_120 [ 0 ] . V_169 ) ) {
V_3 -> V_170 [ 0 ] &= ~ V_75 [ 0 ] ;
V_2 -> V_171 = false ;
} else {
V_2 -> V_171 = true ;
}
if ( ! F_46 ( V_2 , V_77 , 0 ) )
F_8 ( L_33 ) ;
V_3 -> V_120 [ 0 ] . V_172 -- ;
}
}
for ( V_24 = 1 ; V_24 < ( V_173 + 1 ) ; V_24 ++ ) {
if ( V_3 -> V_120 [ V_24 ] . V_121 &&
V_3 -> V_120 [ V_24 ] . V_168 ) {
F_8 ( L_34 ,
V_24 ,
V_3 -> V_120 [ V_24 ] . V_172 ) ;
while ( ( V_77 = F_44 ( & V_3 -> V_120 [ V_24 ] . V_169 ) ) != NULL ) {
if ( F_45 ( & V_3 -> V_120 [ V_24 ] . V_169 ) ) {
V_3 -> V_170 [ V_3 -> V_120 [ V_24 ] . V_174 >> 3 ] &=
~ V_75 [ V_3 -> V_120 [ V_24 ] . V_174 & 7 ] ;
V_2 -> V_171 = false ;
} else {
V_2 -> V_171 = true ;
}
if ( ! F_46 ( V_2 , V_77 , V_24 ) )
F_8 ( L_35 ) ;
V_3 -> V_120 [ V_24 ] . V_172 -- ;
if ( V_3 -> V_120 [ V_24 ] . V_175 )
break;
}
if ( F_45 ( & V_3 -> V_120 [ V_24 ] . V_169 ) ) {
V_3 -> V_170 [ V_3 -> V_120 [ V_24 ] . V_174 >> 3 ] &=
~ V_75 [ V_3 -> V_120 [ V_24 ] . V_174 & 7 ] ;
F_8 ( L_36 ,
V_24 ) ;
}
V_3 -> V_120 [ V_24 ] . V_168 = false ;
}
}
F_18 ( V_2 ) ;
break;
case V_176 :
F_8 ( L_37 ) ;
if ( V_2 -> V_177 )
F_47 ( V_2 ) ;
else
F_48 ( V_2 ) ;
F_18 ( V_2 ) ;
break;
case V_178 :
if ( V_2 -> V_89 [ V_90 ] != 0 ) {
F_13 ( ( void * ) V_2 , 10 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
if ( V_2 -> V_89 [ V_123 ] != 0 ) {
F_13 ( ( void * ) V_2 , 10 ) ;
F_19 ( & V_2 -> V_80 ) ;
return;
}
V_2 -> V_179 = V_2 -> V_180 ;
F_49 ( V_2 , V_2 -> V_179 ) ;
F_8 ( L_38 , V_2 -> V_179 ) ;
F_18 ( V_2 ) ;
break;
default:
F_18 ( V_2 ) ;
break;
}
F_19 ( & V_2 -> V_80 ) ;
}
static
bool
F_18 (
struct V_1 * V_2
)
{
V_29 V_34 ;
bool V_177 = false ;
bool V_181 = true ;
T_1 V_3 = V_2 -> V_3 ;
V_2 -> V_81 = V_182 ;
if ( V_2 -> V_183 == V_184 ) {
V_2 -> V_79 = false ;
return true ;
} else {
V_2 -> V_185 = V_2 -> V_186 [ V_2 -> V_187 ] . V_188 ;
V_34 = ( V_29 ) V_2 -> V_186 [ V_2 -> V_187 ] . V_189 ;
V_177 = V_2 -> V_186 [ V_2 -> V_187 ] . V_177 ;
V_181 = V_2 -> V_186 [ V_2 -> V_187 ] . V_181 ;
F_50 ( V_2 -> V_187 , V_184 ) ;
V_2 -> V_183 ++ ;
V_2 -> V_79 = true ;
switch ( V_2 -> V_185 ) {
case V_190 :
F_8 ( L_39 ) ;
V_2 -> V_81 = V_82 ;
V_3 -> V_12 = 0 ;
if ( V_34 -> V_44 != 0 )
memcpy ( V_3 -> V_30 , V_34 , V_56 + V_118 + 1 ) ;
else
memset ( V_3 -> V_30 , 0 , V_56 + V_118 + 1 ) ;
break;
case V_191 :
V_2 -> V_81 = V_124 ;
if ( V_34 -> V_44 > V_118 )
V_34 -> V_44 = V_118 ;
if ( V_34 -> V_44 != 0 )
memcpy ( V_2 -> V_3 -> V_125 , V_34 , V_56 + V_118 + 1 ) ;
F_8 ( L_40 ) ;
break;
case V_192 :
V_2 -> V_81 = V_112 ;
break;
case V_193 :
V_2 -> V_81 = V_167 ;
break;
case V_194 :
V_2 -> V_81 = V_158 ;
break;
case V_195 :
V_2 -> V_81 = V_176 ;
V_2 -> V_177 = V_177 ;
break;
case V_196 :
V_2 -> V_81 = V_178 ;
break;
default:
break;
}
F_13 ( ( void * ) V_2 , 0 ) ;
}
return true ;
}
bool F_51 (
void * V_63 ,
T_5 V_185 ,
unsigned char * V_197
)
{
struct V_1 * V_2 = V_63 ;
if ( V_2 -> V_183 == 0 )
return false ;
V_2 -> V_186 [ V_2 -> V_198 ] . V_188 = V_185 ;
V_2 -> V_186 [ V_2 -> V_198 ] . V_181 = true ;
memset ( V_2 -> V_186 [ V_2 -> V_198 ] . V_189 , 0 , V_56 + V_118 + 1 ) ;
if ( V_197 != NULL ) {
switch ( V_185 ) {
case V_190 :
memcpy ( V_2 -> V_186 [ V_2 -> V_198 ] . V_189 ,
V_197 , V_56 + V_118 + 1 ) ;
V_2 -> V_186 [ V_2 -> V_198 ] . V_181 = false ;
break;
case V_191 :
memcpy ( V_2 -> V_186 [ V_2 -> V_198 ] . V_189 ,
V_197 , V_56 + V_118 + 1 ) ;
break;
case V_192 :
V_2 -> V_186 [ V_2 -> V_198 ] . V_199 = * ( ( int * ) V_197 ) ;
break;
case V_193 :
break;
case V_195 :
V_2 -> V_186 [ V_2 -> V_198 ] . V_177 = * ( ( int * ) V_197 ) ;
break;
case V_196 :
V_2 -> V_81 = V_178 ;
break;
default:
break;
}
}
F_50 ( V_2 -> V_198 , V_184 ) ;
V_2 -> V_183 -- ;
if ( ! V_2 -> V_79 )
F_18 ( V_2 ) ;
return true ;
}
bool F_34 (
void * V_63
)
{
struct V_1 * V_2 = V_63 ;
unsigned int V_187 = V_2 -> V_187 ;
unsigned int V_24 ;
if ( ( V_2 -> V_183 < V_184 ) && ( V_187 != V_2 -> V_198 ) ) {
for ( V_24 = 0 ; V_24 < ( V_184 - V_2 -> V_183 ) ; V_24 ++ ) {
if ( V_2 -> V_186 [ V_187 ] . V_188 == V_190 )
V_2 -> V_186 [ V_187 ] . V_188 = V_182 ;
F_50 ( V_187 , V_184 ) ;
if ( V_187 == V_2 -> V_198 )
break;
}
}
return true ;
}
void
F_52 (
void * V_63
)
{
struct V_1 * V_2 = V_63 ;
F_42 ( & V_2 -> V_65 ) ;
F_14 ( & V_2 -> V_65 ) ;
V_2 -> V_65 . V_66 = ( unsigned long ) V_2 ;
V_2 -> V_65 . V_67 = ( V_68 ) V_69 ;
V_2 -> V_65 . V_70 = F_15 ( V_71 ) ;
V_2 -> V_183 = V_184 ;
V_2 -> V_187 = 0 ;
V_2 -> V_198 = 0 ;
V_2 -> V_81 = V_182 ;
V_2 -> V_79 = false ;
V_2 -> V_200 = false ;
}
void
V_154 (
void * V_63
)
{
struct V_1 * V_2 = V_63 ;
T_1 V_3 = & ( V_2 -> V_4 ) ;
V_2 -> V_156 ++ ;
if ( V_2 -> V_156 < 4 )
{
V_2 -> V_153 . V_70 = F_15 ( 10 * V_71 ) ;
F_16 ( & V_2 -> V_153 ) ;
return;
}
F_17 ( & V_2 -> V_80 ) ;
if ( ( V_2 -> V_115 && ( V_3 -> V_147 < V_148 ) ) ||
V_2 -> V_201 ) {
V_2 -> V_155 = true ;
F_41 ( V_2 ) ;
V_2 -> V_155 = false ;
}
F_19 ( & V_2 -> V_80 ) ;
V_2 -> V_153 . V_70 = F_15 ( 10 * V_71 ) ;
F_16 ( & V_2 -> V_153 ) ;
}
