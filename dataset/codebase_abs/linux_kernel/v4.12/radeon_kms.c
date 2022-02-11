static inline bool F_1 ( void ) { return false ; }
void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_6 == NULL )
goto V_7;
if ( F_3 ( V_2 ) ) {
F_4 ( V_2 -> V_2 ) ;
F_5 ( V_2 -> V_2 ) ;
}
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
V_7:
F_10 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_11 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_12 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_13 ( V_2 -> V_13 , V_14 ) ) {
V_8 |= V_15 ;
} else if ( F_14 ( V_2 -> V_13 ) ) {
V_8 |= V_16 ;
} else {
V_8 |= V_17 ;
}
if ( ( V_18 != 0 ) &&
F_1 () &&
( ( V_8 & V_19 ) == 0 ) &&
! F_15 ( V_2 -> V_13 ) )
V_8 |= V_20 ;
V_9 = F_16 ( V_4 , V_2 , V_2 -> V_13 , V_8 ) ;
if ( V_9 ) {
F_17 ( & V_2 -> V_13 -> V_2 , L_1 ) ;
goto V_21;
}
V_9 = F_18 ( V_4 ) ;
if ( V_9 )
F_17 ( & V_2 -> V_13 -> V_2 , L_2 ) ;
if ( ! V_9 ) {
V_10 = F_19 ( V_4 ) ;
if ( V_10 )
F_20 ( & V_2 -> V_13 -> V_2 ,
L_3 ) ;
}
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_23 ( V_2 -> V_2 ) ;
F_24 ( V_2 -> V_2 , 5000 ) ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_2 ) ;
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
}
V_21:
if ( V_9 )
F_2 ( V_2 ) ;
return V_9 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_22 * * V_23 ,
struct V_22 * V_24 ,
T_1 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_30 ( & V_4 -> V_26 . V_27 ) ;
if ( * V_25 == 1 ) {
if ( ! * V_23 )
* V_23 = V_24 ;
} else if ( * V_25 == 0 ) {
if ( * V_23 == V_24 )
* V_23 = NULL ;
}
* V_25 = * V_23 == V_24 ? 1 : 0 ;
F_31 ( & V_4 -> V_26 . V_27 ) ;
}
static int F_32 ( struct V_1 * V_2 , void * V_28 , struct V_22 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_28 ;
struct V_32 * V_33 = & V_4 -> V_34 ;
T_1 * V_25 , V_35 , * V_36 , V_37 ;
T_2 V_38 ;
struct V_39 * V_40 ;
int V_41 , V_42 ;
V_36 = ( T_1 * ) ( ( unsigned long ) V_31 -> V_25 ) ;
V_25 = & V_35 ;
V_37 = sizeof( T_1 ) ;
switch ( V_31 -> V_43 ) {
case V_44 :
* V_25 = V_2 -> V_13 -> V_45 ;
break;
case V_46 :
* V_25 = V_4 -> V_47 ;
break;
case V_48 :
* V_25 = V_4 -> V_49 ;
break;
case V_50 :
if ( ( V_4 -> V_51 >= V_52 ) && ( V_4 -> V_51 <= V_53 ) )
* V_25 = false ;
else
* V_25 = V_4 -> V_54 ;
break;
case V_55 :
if ( F_33 ( V_25 , V_36 , sizeof( T_1 ) ) ) {
F_34 ( L_4 , V_56 , __LINE__ ) ;
return - V_57 ;
}
for ( V_41 = 0 , V_42 = 0 ; V_41 < V_4 -> V_58 ; V_41 ++ ) {
V_40 = (struct V_39 * ) V_33 -> V_59 [ V_41 ] ;
if ( V_40 && V_40 -> V_60 . V_61 == * V_25 ) {
struct V_62 * V_62 = F_35 ( V_40 ) ;
* V_25 = V_62 -> V_63 ;
V_42 = 1 ;
break;
}
}
if ( ! V_42 ) {
F_36 ( L_5 , * V_25 ) ;
return - V_64 ;
}
break;
case V_65 :
if ( V_4 -> V_51 == V_66 ) {
if ( V_4 -> V_54 ) {
if ( V_4 -> V_67 )
* V_25 = 3 ;
else
* V_25 = 2 ;
} else {
* V_25 = 0 ;
}
} else {
* V_25 = V_4 -> V_54 ;
}
break;
case V_68 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_72 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_72 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_72 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_72 ;
else if ( V_4 -> V_51 >= V_78 )
* V_25 = V_4 -> V_70 . V_79 . V_72 ;
else if ( V_4 -> V_51 >= V_80 )
* V_25 = V_4 -> V_70 . V_81 . V_72 ;
else {
F_36 ( L_6 ) ;
return - V_64 ;
}
break;
case V_82 :
if ( F_33 ( V_25 , V_36 , sizeof( T_1 ) ) ) {
F_34 ( L_4 , V_56 , __LINE__ ) ;
return - V_57 ;
}
if ( * V_25 >= 2 ) {
F_36 ( L_7 , * V_25 ) ;
return - V_64 ;
}
F_29 ( V_2 , & V_4 -> V_83 , V_29 , V_25 ) ;
break;
case V_84 :
if ( F_33 ( V_25 , V_36 , sizeof( T_1 ) ) ) {
F_34 ( L_4 , V_56 , __LINE__ ) ;
return - V_57 ;
}
if ( * V_25 >= 2 ) {
F_36 ( L_8 , * V_25 ) ;
return - V_64 ;
}
F_29 ( V_2 , & V_4 -> V_85 , V_29 , V_25 ) ;
break;
case V_86 :
if ( V_4 -> V_87 -> V_88 )
* V_25 = F_37 ( V_4 ) * 10 ;
else
* V_25 = V_4 -> clock . V_89 . V_90 * 10 ;
break;
case V_91 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_92 *
V_4 -> V_70 . V_71 . V_93 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_92 *
V_4 -> V_70 . V_74 . V_93 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_92 *
V_4 -> V_70 . V_76 . V_93 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_94 ;
else if ( V_4 -> V_51 >= V_78 )
* V_25 = V_4 -> V_70 . V_79 . V_94 ;
else if ( V_4 -> V_51 >= V_80 )
* V_25 = V_4 -> V_70 . V_81 . V_94 ;
else {
return - V_64 ;
}
break;
case V_95 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_96 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_96 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_96 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_96 ;
else if ( V_4 -> V_51 >= V_78 )
* V_25 = V_4 -> V_70 . V_79 . V_96 ;
else if ( V_4 -> V_51 >= V_80 )
* V_25 = V_4 -> V_70 . V_81 . V_96 ;
else {
return - V_64 ;
}
break;
case V_97 :
* V_25 = 1 ;
break;
case V_98 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_99 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_99 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_99 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_99 ;
else if ( V_4 -> V_51 >= V_78 )
* V_25 = V_4 -> V_70 . V_79 . V_99 ;
else if ( V_4 -> V_51 >= V_80 )
* V_25 = V_4 -> V_70 . V_81 . V_99 ;
else {
return - V_64 ;
}
break;
case V_100 :
if ( V_4 -> V_51 < V_75 )
return - V_64 ;
* V_25 = V_101 ;
break;
case V_102 :
if ( V_4 -> V_51 < V_75 )
return - V_64 ;
* V_25 = V_103 ;
break;
case V_104 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_105 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_105 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_106 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_107 ;
else if ( V_4 -> V_51 >= V_78 )
* V_25 = V_4 -> V_70 . V_79 . V_107 ;
else if ( V_4 -> V_51 >= V_80 )
* V_25 = V_4 -> V_70 . V_81 . V_107 ;
else {
return - V_64 ;
}
break;
case V_108 :
if ( V_4 -> V_51 < V_80 ) {
F_36 ( L_9 ) ;
return - V_64 ;
}
V_25 = ( T_1 * ) & V_38 ;
V_37 = sizeof( T_2 ) ;
V_38 = F_38 ( V_4 ) ;
break;
case V_109 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_93 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_93 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_93 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_110 ;
else
* V_25 = 1 ;
break;
case V_111 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_112 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_112 ;
else
return - V_64 ;
break;
case V_113 :
* V_25 = V_4 -> V_114 ;
break;
case V_115 :
if ( F_33 ( V_25 , V_36 , sizeof( T_1 ) ) ) {
F_34 ( L_4 , V_56 , __LINE__ ) ;
return - V_57 ;
}
switch ( * V_25 ) {
case V_116 :
case V_117 :
* V_25 = V_4 -> V_118 [ V_119 ] . V_120 ;
break;
case V_121 :
* V_25 = V_4 -> V_118 [ V_122 ] . V_120 ;
* V_25 |= V_4 -> V_118 [ V_123 ] . V_120 ;
break;
case V_124 :
* V_25 = V_4 -> V_118 [ V_125 ] . V_120 ;
break;
case V_126 :
* V_25 = V_4 -> V_118 [ V_127 ] . V_120 ;
break;
default:
return - V_64 ;
}
break;
case V_128 :
if ( V_4 -> V_51 >= V_69 ) {
V_25 = V_4 -> V_70 . V_71 . V_129 ;
V_37 = sizeof( T_1 ) * 32 ;
} else if ( V_4 -> V_51 >= V_73 ) {
V_25 = V_4 -> V_70 . V_74 . V_129 ;
V_37 = sizeof( T_1 ) * 32 ;
} else {
F_36 ( L_10 ) ;
return - V_64 ;
}
break;
case V_130 :
if ( V_4 -> V_51 >= V_69 ) {
V_25 = V_4 -> V_70 . V_71 . V_131 ;
V_37 = sizeof( T_1 ) * 16 ;
} else {
F_36 ( L_11 ) ;
return - V_64 ;
}
break;
case V_132 :
* V_25 = 1 ;
break;
case V_133 :
if ( V_4 -> V_51 >= V_69 ) {
* V_25 = V_4 -> V_70 . V_71 . V_134 ;
} else if ( V_4 -> V_51 >= V_73 ) {
* V_25 = V_4 -> V_70 . V_74 . V_134 ;
} else {
F_36 ( L_12 ) ;
}
break;
case V_135 :
if ( ( V_4 -> V_136 . V_137 == V_138 ) &&
V_4 -> V_136 . V_139 )
* V_25 = V_4 -> V_136 . V_140 . V_141 . V_142 . V_143 * 10 ;
else
* V_25 = V_4 -> V_136 . V_144 * 10 ;
break;
case V_145 :
* V_25 = V_4 -> V_146 . V_147 ;
break;
case V_148 :
* V_25 = V_4 -> V_146 . V_149 ;
break;
case V_150 :
V_25 = ( T_1 * ) & V_38 ;
V_37 = sizeof( T_2 ) ;
V_38 = F_39 ( & V_4 -> V_151 ) ;
break;
case V_152 :
V_25 = ( T_1 * ) & V_38 ;
V_37 = sizeof( T_2 ) ;
V_38 = F_39 ( & V_4 -> V_153 ) ;
break;
case V_154 :
V_25 = ( T_1 * ) & V_38 ;
V_37 = sizeof( T_2 ) ;
V_38 = F_39 ( & V_4 -> V_155 ) ;
break;
case V_156 :
if ( V_4 -> V_51 >= V_69 )
* V_25 = V_4 -> V_70 . V_71 . V_157 ;
else if ( V_4 -> V_51 >= V_73 )
* V_25 = V_4 -> V_70 . V_74 . V_157 ;
else if ( V_4 -> V_51 >= V_75 )
* V_25 = V_4 -> V_70 . V_76 . V_158 ;
else if ( V_4 -> V_51 >= V_52 )
* V_25 = V_4 -> V_70 . V_77 . V_158 ;
else if ( V_4 -> V_51 >= V_78 )
* V_25 = V_4 -> V_70 . V_79 . V_158 ;
else if ( V_4 -> V_51 >= V_80 )
* V_25 = V_4 -> V_70 . V_81 . V_158 ;
else
* V_25 = 1 ;
break;
case V_159 :
if ( V_4 -> V_87 -> V_136 . V_160 )
* V_25 = F_40 ( V_4 ) ;
else
* V_25 = 0 ;
break;
case V_161 :
if ( V_4 -> V_136 . V_139 )
* V_25 = F_41 ( V_4 ) / 100 ;
else
* V_25 = V_4 -> V_136 . V_162 / 100 ;
break;
case V_163 :
if ( V_4 -> V_136 . V_139 )
* V_25 = F_42 ( V_4 ) / 100 ;
else
* V_25 = V_4 -> V_136 . V_164 / 100 ;
break;
case V_165 :
if ( F_33 ( V_25 , V_36 , sizeof( T_1 ) ) ) {
F_34 ( L_4 , V_56 , __LINE__ ) ;
return - V_57 ;
}
if ( F_43 ( V_4 , * V_25 , V_25 ) )
return - V_64 ;
break;
case V_166 :
* V_25 = true ;
break;
case V_167 :
* V_25 = F_44 ( & V_4 -> V_168 ) ;
break;
default:
F_36 ( L_13 , V_31 -> V_43 ) ;
return - V_64 ;
}
if ( F_45 ( V_36 , ( char * ) V_25 , V_37 ) ) {
F_34 ( L_14 , V_56 , __LINE__ ) ;
return - V_57 ;
}
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_47 ( V_4 ) ;
F_48 () ;
}
int F_49 ( struct V_1 * V_2 , struct V_22 * V_169 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_169 -> V_170 = NULL ;
V_9 = F_4 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 -> V_51 >= V_75 ) {
struct V_171 * V_172 ;
struct V_173 * V_174 ;
V_172 = F_12 ( sizeof( * V_172 ) , V_11 ) ;
if ( F_50 ( ! V_172 ) ) {
V_9 = - V_12 ;
goto V_175;
}
if ( V_4 -> V_54 ) {
V_174 = & V_172 -> V_174 ;
V_9 = F_51 ( V_4 , V_174 ) ;
if ( V_9 ) {
F_10 ( V_172 ) ;
goto V_175;
}
V_9 = F_52 ( V_4 -> V_176 . V_177 , false ) ;
if ( V_9 ) {
F_53 ( V_4 , V_174 ) ;
F_10 ( V_172 ) ;
goto V_175;
}
V_174 -> V_178 = F_54 ( V_4 , V_174 ,
V_4 -> V_176 . V_177 ) ;
V_9 = F_55 ( V_4 , V_174 -> V_178 ,
V_179 ,
V_180 |
V_181 ) ;
if ( V_9 ) {
F_53 ( V_4 , V_174 ) ;
F_10 ( V_172 ) ;
goto V_175;
}
}
V_169 -> V_170 = V_172 ;
}
V_175:
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
return V_9 ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_22 * V_169 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( V_2 -> V_2 ) ;
F_30 ( & V_4 -> V_26 . V_27 ) ;
if ( V_4 -> V_83 == V_169 )
V_4 -> V_83 = NULL ;
if ( V_4 -> V_85 == V_169 )
V_4 -> V_85 = NULL ;
F_31 ( & V_4 -> V_26 . V_27 ) ;
F_57 ( V_4 , V_169 ) ;
F_58 ( V_4 , V_169 ) ;
if ( V_4 -> V_51 >= V_75 && V_169 -> V_170 ) {
struct V_171 * V_172 = V_169 -> V_170 ;
struct V_173 * V_174 = & V_172 -> V_174 ;
int V_9 ;
if ( V_4 -> V_54 ) {
V_9 = F_52 ( V_4 -> V_176 . V_177 , false ) ;
if ( ! V_9 ) {
if ( V_174 -> V_178 )
F_59 ( V_4 , V_174 -> V_178 ) ;
F_60 ( V_4 -> V_176 . V_177 ) ;
}
F_53 ( V_4 , V_174 ) ;
}
F_10 ( V_172 ) ;
V_169 -> V_170 = NULL ;
}
F_27 ( V_2 -> V_2 ) ;
F_28 ( V_2 -> V_2 ) ;
}
T_3 F_61 ( struct V_1 * V_2 , unsigned int V_182 )
{
int V_183 , V_184 , V_185 ;
T_3 V_186 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_182 >= V_4 -> V_58 ) {
F_34 ( L_15 , V_182 ) ;
return - V_64 ;
}
if ( V_4 -> V_34 . V_59 [ V_182 ] ) {
do {
V_186 = F_62 ( V_4 , V_182 ) ;
V_185 = F_63 (
V_2 , V_182 , V_187 ,
& V_183 , & V_184 , NULL , NULL ,
& V_4 -> V_34 . V_59 [ V_182 ] -> V_60 . V_188 ) ;
} while ( V_186 != F_62 ( V_4 , V_182 ) );
if ( ( ( V_185 & ( V_189 | V_190 ) ) !=
( V_189 | V_190 ) ) ) {
F_64 ( L_16 , V_185 ) ;
}
else {
F_64 ( L_17 ,
V_182 , V_183 ) ;
if ( V_183 >= 0 )
V_186 ++ ;
}
}
else {
V_186 = F_62 ( V_4 , V_182 ) ;
F_64 ( L_18 ) ;
}
return V_186 ;
}
int F_65 ( struct V_1 * V_2 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_191 ;
int V_9 ;
if ( V_40 < 0 || V_40 >= V_4 -> V_58 ) {
F_34 ( L_19 , V_40 ) ;
return - V_64 ;
}
F_66 ( & V_4 -> V_192 . V_193 , V_191 ) ;
V_4 -> V_192 . V_194 [ V_40 ] = true ;
V_9 = F_67 ( V_4 ) ;
F_68 ( & V_4 -> V_192 . V_193 , V_191 ) ;
return V_9 ;
}
void F_69 ( struct V_1 * V_2 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_191 ;
if ( V_40 < 0 || V_40 >= V_4 -> V_58 ) {
F_34 ( L_19 , V_40 ) ;
return;
}
F_66 ( & V_4 -> V_192 . V_193 , V_191 ) ;
V_4 -> V_192 . V_194 [ V_40 ] = false ;
F_67 ( V_4 ) ;
F_68 ( & V_4 -> V_192 . V_193 , V_191 ) ;
}
int F_70 ( struct V_1 * V_2 , int V_40 ,
int * V_195 ,
struct V_196 * V_197 ,
unsigned V_8 )
{
struct V_39 * V_198 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_40 < 0 || V_40 >= V_2 -> V_199 ) {
F_34 ( L_19 , V_40 ) ;
return - V_64 ;
}
V_198 = & V_4 -> V_34 . V_59 [ V_40 ] -> V_60 ;
if ( ! V_198 )
return - V_64 ;
return F_71 ( V_2 , V_40 , V_195 ,
V_197 , V_8 ,
& V_198 -> V_188 ) ;
}
