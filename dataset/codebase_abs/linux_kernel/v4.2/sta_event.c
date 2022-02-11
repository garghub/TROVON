void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 ( V_5 , V_7 ,
L_1 ) ;
V_2 -> V_6 = false ;
V_2 -> V_8 = false ;
if ( ( F_3 ( V_2 ) == V_9 ) &&
F_4 ( V_2 -> V_5 -> V_10 ) ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_5 -> V_11 )
F_6 ( V_2 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 . V_23 = false ;
V_2 -> V_22 . V_24 = false ;
V_2 -> V_25 = 0 ;
V_2 -> V_22 . V_26 = false ;
V_2 -> V_27 = 0 ;
V_2 -> V_22 . V_28 = false ;
V_2 -> V_22 . V_29 = 0 ;
V_2 -> V_30 = true ;
V_2 -> V_31 = 0 ;
if ( ( F_3 ( V_2 ) == V_9 ||
F_3 ( V_2 ) == V_32 ) && V_2 -> V_33 )
F_8 ( V_2 ) ;
if ( V_2 -> V_34 == V_35 ) {
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = false ;
}
F_2 ( V_5 , V_7 ,
L_2 ,
V_2 -> V_39 . V_40 , V_2 -> V_39 . V_41 ) ;
F_2 ( V_5 , V_7 ,
L_3 ,
V_2 -> V_42 . V_43 . V_40 . V_40 ,
V_2 -> V_42 . V_43 . V_40 . V_41 ) ;
memcpy ( & V_2 -> V_39 ,
& V_2 -> V_42 . V_43 . V_40 ,
sizeof( struct V_44 ) ) ;
memcpy ( V_2 -> V_45 ,
V_2 -> V_42 . V_43 . V_46 , V_47 ) ;
memset ( & V_2 -> V_42 , 0x00 , sizeof( V_2 -> V_42 ) ) ;
V_5 -> V_48 = false ;
V_5 -> V_49 = false ;
if ( V_5 -> V_50 && V_5 -> V_51 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 , V_52 ,
L_4 ,
V_2 -> V_53 , V_3 ) ;
if ( V_2 -> V_34 == V_54 ||
V_2 -> V_34 == V_55 ) {
F_9 ( V_2 -> V_56 , V_3 , NULL , 0 ,
false , V_57 ) ;
}
F_10 ( V_2 -> V_53 ) ;
F_11 ( V_2 -> V_56 , V_5 ) ;
if ( F_12 ( V_2 -> V_56 ) )
F_13 ( V_2 -> V_56 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
int V_60 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_61 * V_62 ;
struct V_63 * V_64 =
( void * ) V_59 -> V_65 + sizeof( V_5 -> V_66 ) ;
if ( V_59 -> V_67 < ( sizeof( struct V_63 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_66 ) ) ) {
F_2 ( V_5 , ERROR , L_5 ) ;
return - 1 ;
}
V_62 = F_15 ( V_2 , V_64 -> V_68 ) ;
if ( ! V_62 ) {
F_2 ( V_5 , ERROR , L_6 ) ;
return - 1 ;
}
switch ( F_16 ( V_64 -> type ) ) {
case V_69 :
F_17 ( V_2 -> V_56 ,
V_64 -> V_68 ,
V_70 ,
F_16 ( V_64 -> V_71 . V_3 ) ,
V_57 ) ;
break;
default:
break;
}
return V_60 ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
T_2 V_67 = V_59 -> V_67 - sizeof( V_78 ) ;
T_3 * V_79 = V_59 -> V_65 + sizeof( V_78 ) ;
T_1 V_80 , V_81 ;
while ( V_67 >= sizeof( struct V_72 ) ) {
V_73 = (struct V_72 * ) V_79 ;
V_81 = F_16 ( V_73 -> V_67 ) ;
V_80 = F_16 ( V_73 -> type ) ;
if ( ( V_81 + sizeof( struct V_72 ) ) > V_67 )
break;
switch ( V_80 ) {
case V_82 :
V_75 =
(struct V_74 * ) V_73 ;
V_5 -> V_83 = V_75 -> V_83 ;
V_5 -> V_84 =
V_75 -> V_85 ;
V_5 -> V_86 =
V_75 -> V_87 ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
break;
case V_88 :
V_77 =
(struct V_76 * ) V_73 ;
V_5 -> V_89 = V_77 -> V_89 ;
V_5 -> V_90 = V_77 -> V_91 ;
V_5 -> V_92 = V_77 -> V_93 ;
break;
default:
break;
}
V_67 -= V_81 + sizeof( struct V_72 ) ;
V_79 += V_81 +
sizeof( struct V_72 ) ;
}
F_21 ( V_5 -> V_94 , L_7 ,
V_5 -> V_89 , V_5 -> V_90 ,
V_5 -> V_83 , V_5 -> V_84 ,
V_5 -> V_86 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_60 = 0 ;
V_78 V_95 = V_5 -> V_66 ;
T_1 V_96 , V_3 ;
switch ( V_95 ) {
case V_97 :
F_2 ( V_5 , ERROR ,
L_8 ) ;
break;
case V_98 :
F_2 ( V_5 , V_99 , L_9 ) ;
if ( ! F_12 ( V_2 -> V_56 ) )
F_23 ( V_2 -> V_56 ) ;
F_24 ( V_2 -> V_56 , V_5 ) ;
break;
case V_100 :
F_2 ( V_5 , V_99 , L_10 ) ;
if ( V_2 -> V_101 . V_102 ) {
F_2 ( V_5 , V_7 ,
L_11 ) ;
break;
}
V_5 -> V_103 . V_104 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_105 * ) V_5 -> V_106 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_107 :
F_2 ( V_5 , V_99 , L_12 ) ;
if ( V_2 -> V_101 . V_102 ) {
F_2 ( V_5 , V_7 ,
L_13 ) ;
break;
}
V_5 -> V_103 . V_108 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_105 * ) V_5 -> V_106 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_109 :
F_2 ( V_5 , V_99 , L_14 ) ;
V_5 -> V_103 . V_110 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_105 * ) V_5 -> V_106 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_111 :
F_2 ( V_5 , V_99 , L_15 ) ;
V_5 -> V_112 = V_113 ;
F_25 ( V_5 ) ;
break;
case V_114 :
F_2 ( V_5 , V_99 , L_16 ) ;
if ( ! V_5 -> V_49 &&
V_2 -> V_6 && V_5 -> V_115 . V_116 ) {
V_5 -> V_49 = true ;
F_2 ( V_5 , V_99 ,
L_17 ) ;
}
V_5 -> V_48 = false ;
if ( V_5 -> V_49 && V_5 -> V_117 ) {
if ( F_26 ( V_2 ) ) {
if ( V_5 -> V_118 ) {
V_5 -> V_112 = V_119 ;
V_5 -> V_120 = false ;
V_5 -> V_121 = false ;
F_27 ( & V_5 -> V_122 ) ;
break;
}
if ( ! F_28
( V_2 ,
V_123 |
V_124 ) )
V_5 -> V_112 =
V_125 ;
return 0 ;
}
}
V_5 -> V_112 = V_119 ;
V_5 -> V_120 = false ;
V_5 -> V_121 = false ;
F_27 ( & V_5 -> V_122 ) ;
break;
case V_126 :
V_5 -> V_127 . V_128 ( V_5 ) ;
F_2 ( V_5 , V_99 , L_18 ) ;
if ( V_5 -> V_129 )
V_5 -> V_129 = false ;
break;
case V_130 :
F_2 ( V_5 , V_99 , L_19 ) ;
V_60 = F_29 ( V_2 , V_131 ,
0 , 0 , NULL , false ) ;
break;
case V_132 :
F_2 ( V_5 , V_99 , L_20 ) ;
F_30 ( V_2 -> V_56 , V_2 -> V_53 ,
V_133 ,
- 1 , NULL , V_57 ) ;
break;
case V_134 :
F_2 ( V_5 , V_99 , L_21 ) ;
F_30 ( V_2 -> V_56 , V_2 -> V_53 ,
V_135 ,
- 1 , NULL , V_57 ) ;
break;
case V_136 :
case V_137 :
break;
case V_138 :
F_2 ( V_5 , V_99 , L_22 ) ;
V_2 -> V_38 = false ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_56 , V_5 ) ;
if ( F_12 ( V_2 -> V_56 ) )
F_13 ( V_2 -> V_56 ) ;
break;
case V_139 :
F_2 ( V_5 , V_99 , L_23 ) ;
V_60 = F_29 ( V_2 , V_140 ,
V_141 , 0 , NULL , false ) ;
break;
case V_142 :
F_2 ( V_5 , V_99 , L_24 ) ;
break;
case V_143 :
F_2 ( V_5 , V_99 , L_25 ) ;
if ( V_5 -> V_144 )
V_60 = F_31 ( V_2 ,
V_5 -> V_59 -> V_65 ) ;
break;
case V_145 :
F_2 ( V_5 , V_99 , L_26 ) ;
V_60 = F_29 ( V_2 , V_146 ,
0 , 0 , NULL , false ) ;
break;
case V_147 :
F_32 ( V_2 -> V_56 ,
V_148 ,
V_57 ) ;
F_29 ( V_2 , V_149 ,
V_141 , 0 , NULL , false ) ;
V_2 -> V_150 = V_151 ;
F_2 ( V_5 , V_99 , L_27 ) ;
break;
case V_152 :
F_2 ( V_5 , V_99 , L_28 ) ;
break;
case V_153 :
F_2 ( V_5 , V_99 , L_29 ) ;
break;
case V_154 :
F_32 ( V_2 -> V_56 ,
V_155 ,
V_57 ) ;
F_29 ( V_2 , V_149 ,
V_141 , 0 , NULL , false ) ;
V_2 -> V_150 = V_156 ;
F_2 ( V_5 , V_99 , L_30 ) ;
break;
case V_157 :
F_2 ( V_5 , V_99 , L_31 ) ;
break;
case V_158 :
F_2 ( V_5 , V_99 , L_32 ) ;
break;
case V_159 :
F_2 ( V_5 , V_99 , L_33 ) ;
break;
case V_160 :
F_2 ( V_5 , V_99 , L_34 ) ;
break;
case V_161 :
F_2 ( V_5 , V_99 , L_35 ) ;
break;
case V_162 :
F_2 ( V_5 , V_99 , L_36 ) ;
break;
case V_163 :
F_2 ( V_5 , V_99 , L_37 ) ;
break;
case V_164 :
F_2 ( V_5 , V_99 , L_38 ) ;
V_60 = F_29 ( V_2 ,
V_165 ,
V_141 , 0 , NULL , false ) ;
break;
case V_166 :
F_2 ( V_5 , V_99 , L_39 ) ;
F_29 ( V_2 , V_167 ,
V_168 , 0 ,
V_5 -> V_106 , false ) ;
break;
case V_169 :
F_2 ( V_5 , V_99 , L_40 ) ;
F_33 ( V_2 , V_5 -> V_106 ) ;
break;
case V_170 :
F_2 ( V_5 , V_99 , L_41 ) ;
F_34 ( V_2 ,
(struct V_171
* )
V_5 -> V_106 ) ;
break;
case V_172 :
V_96 = F_16 ( * ( V_105 * ) V_5 -> V_106 ) ;
F_2 ( V_5 , V_99 ,
L_42 , V_96 ) ;
V_5 -> V_173 =
F_35 ( T_1 , V_5 -> V_174 , V_96 ) ;
F_2 ( V_5 , V_99 , L_43 ,
V_5 -> V_173 ) ;
break;
case V_175 :
F_2 ( V_5 , V_99 , L_44 ) ;
break;
case V_176 :
F_2 ( V_5 , V_99 , L_45 ) ;
break;
case V_177 :
F_2 ( V_5 , V_99 ,
L_46 , V_95 ) ;
break;
case V_178 :
F_2 ( V_5 , V_99 ,
L_47 ) ;
F_36 ( & V_2 -> V_179 ,
V_2 -> V_180 . V_181 ,
& V_2 -> V_180 . V_182 ,
V_183 ) ;
memset ( & V_2 -> V_180 , 0x00 , sizeof( struct V_184 ) ) ;
break;
case V_185 :
F_2 ( V_5 , V_99 , L_48 ) ;
V_2 -> V_186 =
V_187 + F_37 ( V_188 ) ;
V_2 -> V_189 = V_2 -> V_42 . V_43 . V_190 ;
V_60 = F_29 ( V_2 , V_191 ,
V_168 , 0 ,
V_2 -> V_42 . V_43 . V_46 ,
false ) ;
break;
case V_192 :
V_60 = F_14 ( V_2 , V_5 -> V_59 ) ;
break;
case V_193 :
F_2 ( V_5 , V_99 , L_49 ) ;
F_38 ( V_2 , V_5 -> V_106 ) ;
break;
case V_194 :
F_2 ( V_5 , V_99 , L_50 ) ;
V_60 = F_39 ( V_2 ,
V_5 -> V_59 ) ;
break;
case V_195 :
F_2 ( V_5 , V_99 , L_51 ) ;
V_60 = F_40 ( V_2 ,
V_5 -> V_59 ) ;
break;
case V_196 :
F_21 ( V_5 -> V_94 , L_52 ) ;
F_18 ( V_2 ,
V_5 -> V_59 ) ;
break;
default:
F_2 ( V_5 , ERROR , L_53 ,
V_95 ) ;
break;
}
return V_60 ;
}
