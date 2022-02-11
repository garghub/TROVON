static inline bool F_1 ( void ) { return false ; }
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
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
return 0 ;
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
if ( F_13 ( V_2 ) ) {
V_8 |= V_13 ;
} else if ( F_14 ( V_2 -> V_14 ) ) {
V_8 |= V_15 ;
} else {
V_8 |= V_16 ;
}
if ( ( V_17 != 0 ) &&
F_1 () &&
( ( V_8 & V_18 ) == 0 ) )
V_8 |= V_19 ;
V_9 = F_15 ( V_4 , V_2 , V_2 -> V_14 , V_8 ) ;
if ( V_9 ) {
F_16 ( & V_2 -> V_14 -> V_2 , L_1 ) ;
goto V_20;
}
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
F_16 ( & V_2 -> V_14 -> V_2 , L_2 ) ;
if ( ! V_9 ) {
V_10 = F_18 ( V_4 ) ;
if ( V_10 )
F_19 ( & V_2 -> V_14 -> V_2 ,
L_3 ) ;
}
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
if ( F_3 ( V_2 ) ) {
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 -> V_2 , 5000 ) ;
F_24 ( V_2 -> V_2 ) ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_2 ) ;
F_27 ( V_2 -> V_2 ) ;
}
V_20:
if ( V_9 )
F_2 ( V_2 ) ;
return V_9 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_21 * * V_22 ,
struct V_21 * V_23 ,
T_1 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_29 ( & V_4 -> V_25 . V_26 ) ;
if ( * V_24 == 1 ) {
if ( ! * V_22 )
* V_22 = V_23 ;
} else if ( * V_24 == 0 ) {
if ( * V_22 == V_23 )
* V_22 = NULL ;
}
* V_24 = * V_22 == V_23 ? 1 : 0 ;
F_30 ( & V_4 -> V_25 . V_26 ) ;
}
static int F_31 ( struct V_1 * V_2 , void * V_27 , struct V_21 * V_28 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_29 * V_30 = V_27 ;
struct V_31 * V_32 = & V_4 -> V_33 ;
T_1 * V_24 , V_34 , * V_35 , V_36 ;
T_2 V_37 ;
struct V_38 * V_39 ;
int V_40 , V_41 ;
V_35 = ( T_1 * ) ( ( unsigned long ) V_30 -> V_24 ) ;
V_24 = & V_34 ;
V_36 = sizeof( T_1 ) ;
switch ( V_30 -> V_42 ) {
case V_43 :
* V_24 = V_2 -> V_14 -> V_44 ;
break;
case V_45 :
* V_24 = V_4 -> V_46 ;
break;
case V_47 :
* V_24 = V_4 -> V_48 ;
break;
case V_49 :
if ( ( V_4 -> V_50 >= V_51 ) && ( V_4 -> V_50 <= V_52 ) )
* V_24 = false ;
else
* V_24 = V_4 -> V_53 ;
break;
case V_54 :
if ( F_32 ( V_24 , V_35 , sizeof( T_1 ) ) ) {
F_33 ( L_4 , V_55 , __LINE__ ) ;
return - V_56 ;
}
for ( V_40 = 0 , V_41 = 0 ; V_40 < V_4 -> V_57 ; V_40 ++ ) {
V_39 = (struct V_38 * ) V_32 -> V_58 [ V_40 ] ;
if ( V_39 && V_39 -> V_59 . V_60 == * V_24 ) {
struct V_61 * V_61 = F_34 ( V_39 ) ;
* V_24 = V_61 -> V_62 ;
V_41 = 1 ;
break;
}
}
if ( ! V_41 ) {
F_35 ( L_5 , * V_24 ) ;
return - V_63 ;
}
break;
case V_64 :
if ( V_4 -> V_50 == V_65 ) {
if ( V_4 -> V_53 ) {
if ( V_4 -> V_66 )
* V_24 = 3 ;
else
* V_24 = 2 ;
} else {
* V_24 = 0 ;
}
} else {
* V_24 = V_4 -> V_53 ;
}
break;
case V_67 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_71 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_71 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_71 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_71 ;
else if ( V_4 -> V_50 >= V_77 )
* V_24 = V_4 -> V_69 . V_78 . V_71 ;
else if ( V_4 -> V_50 >= V_79 )
* V_24 = V_4 -> V_69 . V_80 . V_71 ;
else {
F_35 ( L_6 ) ;
return - V_63 ;
}
break;
case V_81 :
if ( F_32 ( V_24 , V_35 , sizeof( T_1 ) ) ) {
F_33 ( L_4 , V_55 , __LINE__ ) ;
return - V_56 ;
}
if ( * V_24 >= 2 ) {
F_35 ( L_7 , * V_24 ) ;
return - V_63 ;
}
F_28 ( V_2 , & V_4 -> V_82 , V_28 , V_24 ) ;
break;
case V_83 :
if ( F_32 ( V_24 , V_35 , sizeof( T_1 ) ) ) {
F_33 ( L_4 , V_55 , __LINE__ ) ;
return - V_56 ;
}
if ( * V_24 >= 2 ) {
F_35 ( L_8 , * V_24 ) ;
return - V_63 ;
}
F_28 ( V_2 , & V_4 -> V_84 , V_28 , V_24 ) ;
break;
case V_85 :
if ( V_4 -> V_86 -> V_87 )
* V_24 = F_36 ( V_4 ) * 10 ;
else
* V_24 = V_4 -> clock . V_88 . V_89 * 10 ;
break;
case V_90 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_91 *
V_4 -> V_69 . V_70 . V_92 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_91 *
V_4 -> V_69 . V_73 . V_92 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_91 *
V_4 -> V_69 . V_75 . V_92 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_93 ;
else if ( V_4 -> V_50 >= V_77 )
* V_24 = V_4 -> V_69 . V_78 . V_93 ;
else if ( V_4 -> V_50 >= V_79 )
* V_24 = V_4 -> V_69 . V_80 . V_93 ;
else {
return - V_63 ;
}
break;
case V_94 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_95 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_95 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_95 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_95 ;
else if ( V_4 -> V_50 >= V_77 )
* V_24 = V_4 -> V_69 . V_78 . V_95 ;
else if ( V_4 -> V_50 >= V_79 )
* V_24 = V_4 -> V_69 . V_80 . V_95 ;
else {
return - V_63 ;
}
break;
case V_96 :
* V_24 = 1 ;
break;
case V_97 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_98 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_98 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_98 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_98 ;
else if ( V_4 -> V_50 >= V_77 )
* V_24 = V_4 -> V_69 . V_78 . V_98 ;
else if ( V_4 -> V_50 >= V_79 )
* V_24 = V_4 -> V_69 . V_80 . V_98 ;
else {
return - V_63 ;
}
break;
case V_99 :
if ( V_4 -> V_50 < V_74 )
return - V_63 ;
* V_24 = V_100 ;
break;
case V_101 :
if ( V_4 -> V_50 < V_74 )
return - V_63 ;
* V_24 = V_102 ;
break;
case V_103 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_104 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_104 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_105 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_106 ;
else if ( V_4 -> V_50 >= V_77 )
* V_24 = V_4 -> V_69 . V_78 . V_106 ;
else if ( V_4 -> V_50 >= V_79 )
* V_24 = V_4 -> V_69 . V_80 . V_106 ;
else {
return - V_63 ;
}
break;
case V_107 :
if ( V_4 -> V_50 < V_79 ) {
F_35 ( L_9 ) ;
return - V_63 ;
}
V_24 = ( T_1 * ) & V_37 ;
V_36 = sizeof( T_2 ) ;
V_37 = F_37 ( V_4 ) ;
break;
case V_108 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_92 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_92 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_92 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_109 ;
else
* V_24 = 1 ;
break;
case V_110 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_111 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_111 ;
else
return - V_63 ;
break;
case V_112 :
* V_24 = V_4 -> V_113 ;
break;
case V_114 :
if ( F_32 ( V_24 , V_35 , sizeof( T_1 ) ) ) {
F_33 ( L_4 , V_55 , __LINE__ ) ;
return - V_56 ;
}
switch ( * V_24 ) {
case V_115 :
case V_116 :
* V_24 = V_4 -> V_117 [ V_118 ] . V_119 ;
break;
case V_120 :
* V_24 = V_4 -> V_117 [ V_121 ] . V_119 ;
* V_24 |= V_4 -> V_117 [ V_122 ] . V_119 ;
break;
case V_123 :
* V_24 = V_4 -> V_117 [ V_124 ] . V_119 ;
break;
case V_125 :
* V_24 = V_4 -> V_117 [ V_126 ] . V_119 ;
break;
default:
return - V_63 ;
}
break;
case V_127 :
if ( V_4 -> V_50 >= V_68 ) {
V_24 = V_4 -> V_69 . V_70 . V_128 ;
V_36 = sizeof( T_1 ) * 32 ;
} else if ( V_4 -> V_50 >= V_72 ) {
V_24 = V_4 -> V_69 . V_73 . V_128 ;
V_36 = sizeof( T_1 ) * 32 ;
} else {
F_35 ( L_10 ) ;
return - V_63 ;
}
break;
case V_129 :
if ( V_4 -> V_50 >= V_68 ) {
V_24 = V_4 -> V_69 . V_70 . V_130 ;
V_36 = sizeof( T_1 ) * 16 ;
} else {
F_35 ( L_11 ) ;
return - V_63 ;
}
break;
case V_131 :
* V_24 = 1 ;
break;
case V_132 :
if ( V_4 -> V_50 >= V_68 ) {
* V_24 = V_4 -> V_69 . V_70 . V_133 ;
} else if ( V_4 -> V_50 >= V_72 ) {
* V_24 = V_4 -> V_69 . V_73 . V_133 ;
} else {
F_35 ( L_12 ) ;
}
break;
case V_134 :
if ( ( V_4 -> V_135 . V_136 == V_137 ) &&
V_4 -> V_135 . V_138 )
* V_24 = V_4 -> V_135 . V_139 . V_140 . V_141 . V_142 * 10 ;
else
* V_24 = V_4 -> V_135 . V_143 * 10 ;
break;
case V_144 :
* V_24 = V_4 -> V_145 . V_146 ;
break;
case V_147 :
* V_24 = V_4 -> V_145 . V_148 ;
break;
case V_149 :
V_24 = ( T_1 * ) & V_37 ;
V_36 = sizeof( T_2 ) ;
V_37 = F_38 ( & V_4 -> V_150 ) ;
break;
case V_151 :
V_24 = ( T_1 * ) & V_37 ;
V_36 = sizeof( T_2 ) ;
V_37 = F_38 ( & V_4 -> V_152 ) ;
break;
case V_153 :
V_24 = ( T_1 * ) & V_37 ;
V_36 = sizeof( T_2 ) ;
V_37 = F_38 ( & V_4 -> V_154 ) ;
break;
case V_155 :
if ( V_4 -> V_50 >= V_68 )
* V_24 = V_4 -> V_69 . V_70 . V_156 ;
else if ( V_4 -> V_50 >= V_72 )
* V_24 = V_4 -> V_69 . V_73 . V_156 ;
else if ( V_4 -> V_50 >= V_74 )
* V_24 = V_4 -> V_69 . V_75 . V_157 ;
else if ( V_4 -> V_50 >= V_51 )
* V_24 = V_4 -> V_69 . V_76 . V_157 ;
else if ( V_4 -> V_50 >= V_77 )
* V_24 = V_4 -> V_69 . V_78 . V_157 ;
else if ( V_4 -> V_50 >= V_79 )
* V_24 = V_4 -> V_69 . V_80 . V_157 ;
else
* V_24 = 1 ;
break;
case V_158 :
if ( V_4 -> V_86 -> V_135 . V_159 )
* V_24 = F_39 ( V_4 ) ;
else
* V_24 = 0 ;
break;
case V_160 :
if ( V_4 -> V_135 . V_138 )
* V_24 = F_40 ( V_4 ) / 100 ;
else
* V_24 = V_4 -> V_135 . V_161 / 100 ;
break;
case V_162 :
if ( V_4 -> V_135 . V_138 )
* V_24 = F_41 ( V_4 ) / 100 ;
else
* V_24 = V_4 -> V_135 . V_163 / 100 ;
break;
case V_164 :
if ( F_32 ( V_24 , V_35 , sizeof( T_1 ) ) ) {
F_33 ( L_4 , V_55 , __LINE__ ) ;
return - V_56 ;
}
if ( F_42 ( V_4 , * V_24 , V_24 ) )
return - V_63 ;
break;
case V_165 :
* V_24 = true ;
break;
case V_166 :
* V_24 = F_43 ( & V_4 -> V_167 ) ;
break;
default:
F_35 ( L_13 , V_30 -> V_42 ) ;
return - V_63 ;
}
if ( F_44 ( V_35 , ( char * ) V_24 , V_36 ) ) {
F_33 ( L_14 , V_55 , __LINE__ ) ;
return - V_56 ;
}
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_46 ( V_4 ) ;
F_47 () ;
}
int F_48 ( struct V_1 * V_2 , struct V_21 * V_168 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_168 -> V_169 = NULL ;
V_9 = F_4 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 -> V_50 >= V_74 ) {
struct V_170 * V_171 ;
struct V_172 * V_173 ;
int V_9 ;
V_171 = F_12 ( sizeof( * V_171 ) , V_11 ) ;
if ( F_49 ( ! V_171 ) ) {
return - V_12 ;
}
if ( V_4 -> V_53 ) {
V_173 = & V_171 -> V_173 ;
V_9 = F_50 ( V_4 , V_173 ) ;
if ( V_9 ) {
F_10 ( V_171 ) ;
return V_9 ;
}
V_9 = F_51 ( V_4 -> V_174 . V_175 , false ) ;
if ( V_9 ) {
F_52 ( V_4 , V_173 ) ;
F_10 ( V_171 ) ;
return V_9 ;
}
V_173 -> V_176 = F_53 ( V_4 , V_173 ,
V_4 -> V_174 . V_175 ) ;
V_9 = F_54 ( V_4 , V_173 -> V_176 ,
V_177 ,
V_178 |
V_179 ) ;
if ( V_9 ) {
F_52 ( V_4 , V_173 ) ;
F_10 ( V_171 ) ;
return V_9 ;
}
}
V_168 -> V_169 = V_171 ;
}
F_26 ( V_2 -> V_2 ) ;
F_27 ( V_2 -> V_2 ) ;
return 0 ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_21 * V_168 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_50 >= V_74 && V_168 -> V_169 ) {
struct V_170 * V_171 = V_168 -> V_169 ;
struct V_172 * V_173 = & V_171 -> V_173 ;
int V_9 ;
if ( V_4 -> V_53 ) {
V_9 = F_51 ( V_4 -> V_174 . V_175 , false ) ;
if ( ! V_9 ) {
if ( V_173 -> V_176 )
F_56 ( V_4 , V_173 -> V_176 ) ;
F_57 ( V_4 -> V_174 . V_175 ) ;
}
F_52 ( V_4 , V_173 ) ;
}
F_10 ( V_171 ) ;
V_168 -> V_169 = NULL ;
}
}
void F_58 ( struct V_1 * V_2 ,
struct V_21 * V_168 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_29 ( & V_4 -> V_25 . V_26 ) ;
if ( V_4 -> V_82 == V_168 )
V_4 -> V_82 = NULL ;
if ( V_4 -> V_84 == V_168 )
V_4 -> V_84 = NULL ;
F_30 ( & V_4 -> V_25 . V_26 ) ;
F_59 ( V_4 , V_168 ) ;
F_60 ( V_4 , V_168 ) ;
}
T_3 F_61 ( struct V_1 * V_2 , unsigned int V_180 )
{
int V_181 , V_182 , V_183 ;
T_3 V_184 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_180 >= V_4 -> V_57 ) {
F_33 ( L_15 , V_180 ) ;
return - V_63 ;
}
if ( V_4 -> V_33 . V_58 [ V_180 ] ) {
do {
V_184 = F_62 ( V_4 , V_180 ) ;
V_183 = F_63 (
V_2 , V_180 , V_185 ,
& V_181 , & V_182 , NULL , NULL ,
& V_4 -> V_33 . V_58 [ V_180 ] -> V_59 . V_186 ) ;
} while ( V_184 != F_62 ( V_4 , V_180 ) );
if ( ( ( V_183 & ( V_187 | V_188 ) ) !=
( V_187 | V_188 ) ) ) {
F_64 ( L_16 , V_183 ) ;
}
else {
F_64 ( L_17 ,
V_180 , V_181 ) ;
if ( V_181 >= 0 )
V_184 ++ ;
}
}
else {
V_184 = F_62 ( V_4 , V_180 ) ;
F_64 ( L_18 ) ;
}
return V_184 ;
}
int F_65 ( struct V_1 * V_2 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_189 ;
int V_9 ;
if ( V_39 < 0 || V_39 >= V_4 -> V_57 ) {
F_33 ( L_19 , V_39 ) ;
return - V_63 ;
}
F_66 ( & V_4 -> V_190 . V_191 , V_189 ) ;
V_4 -> V_190 . V_192 [ V_39 ] = true ;
V_9 = F_67 ( V_4 ) ;
F_68 ( & V_4 -> V_190 . V_191 , V_189 ) ;
return V_9 ;
}
void F_69 ( struct V_1 * V_2 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_189 ;
if ( V_39 < 0 || V_39 >= V_4 -> V_57 ) {
F_33 ( L_19 , V_39 ) ;
return;
}
F_66 ( & V_4 -> V_190 . V_191 , V_189 ) ;
V_4 -> V_190 . V_192 [ V_39 ] = false ;
F_67 ( V_4 ) ;
F_68 ( & V_4 -> V_190 . V_191 , V_189 ) ;
}
int F_70 ( struct V_1 * V_2 , int V_39 ,
int * V_193 ,
struct V_194 * V_195 ,
unsigned V_8 )
{
struct V_38 * V_196 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_39 < 0 || V_39 >= V_2 -> V_197 ) {
F_33 ( L_19 , V_39 ) ;
return - V_63 ;
}
V_196 = & V_4 -> V_33 . V_58 [ V_39 ] -> V_59 ;
if ( ! V_196 )
return - V_63 ;
return F_71 ( V_2 , V_39 , V_193 ,
V_195 , V_8 ,
& V_196 -> V_186 ) ;
}
