static inline bool F_1 ( void ) { return false ; }
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_6 == NULL )
goto V_7;
F_3 ( V_2 -> V_2 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
V_7:
F_7 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_9 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_10 ( V_2 ) ) {
V_8 |= V_13 ;
} else if ( F_11 ( V_2 -> V_14 ) ) {
V_8 |= V_15 ;
} else {
V_8 |= V_16 ;
}
if ( ( V_17 != 0 ) &&
F_1 () &&
( ( V_8 & V_18 ) == 0 ) )
V_8 |= V_19 ;
V_9 = F_12 ( V_4 , V_2 , V_2 -> V_14 , V_8 ) ;
if ( V_9 ) {
F_13 ( & V_2 -> V_14 -> V_2 , L_1 ) ;
goto V_20;
}
V_9 = F_14 ( V_4 ) ;
if ( V_9 )
F_13 ( & V_2 -> V_14 -> V_2 , L_2 ) ;
if ( ! V_9 ) {
V_10 = F_15 ( V_4 ) ;
if ( V_10 )
F_16 ( & V_2 -> V_14 -> V_2 ,
L_3 ) ;
}
if ( F_17 ( V_2 ) ) {
F_18 ( V_2 -> V_2 ) ;
F_19 ( V_2 -> V_2 , 5000 ) ;
F_20 ( V_2 -> V_2 ) ;
F_21 ( V_2 -> V_2 ) ;
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 -> V_2 ) ;
}
V_20:
if ( V_9 )
F_2 ( V_2 ) ;
return V_9 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_21 * * V_22 ,
struct V_21 * V_23 ,
T_1 * V_24 )
{
F_25 ( & V_2 -> V_25 ) ;
if ( * V_24 == 1 ) {
if ( ! * V_22 )
* V_22 = V_23 ;
} else if ( * V_24 == 0 ) {
if ( * V_22 == V_23 )
* V_22 = NULL ;
}
* V_24 = * V_22 == V_23 ? 1 : 0 ;
F_26 ( & V_2 -> V_25 ) ;
}
static int F_27 ( struct V_1 * V_2 , void * V_26 , struct V_21 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_28 * V_29 = V_26 ;
struct V_30 * V_31 = & V_4 -> V_32 ;
T_1 * V_24 , V_33 , * V_34 , V_35 ;
T_2 V_36 ;
struct V_37 * V_38 ;
int V_39 , V_40 ;
V_34 = ( T_1 * ) ( ( unsigned long ) V_29 -> V_24 ) ;
V_24 = & V_33 ;
V_35 = sizeof( T_1 ) ;
switch ( V_29 -> V_41 ) {
case V_42 :
* V_24 = V_2 -> V_14 -> V_43 ;
break;
case V_44 :
* V_24 = V_4 -> V_45 ;
break;
case V_46 :
* V_24 = V_4 -> V_47 ;
break;
case V_48 :
if ( ( V_4 -> V_49 >= V_50 ) && ( V_4 -> V_49 <= V_51 ) )
* V_24 = false ;
else
* V_24 = V_4 -> V_52 ;
break;
case V_53 :
if ( F_28 ( V_24 , V_34 , sizeof( T_1 ) ) ) {
F_29 ( L_4 , V_54 , __LINE__ ) ;
return - V_55 ;
}
for ( V_39 = 0 , V_40 = 0 ; V_39 < V_4 -> V_56 ; V_39 ++ ) {
V_38 = (struct V_37 * ) V_31 -> V_57 [ V_39 ] ;
if ( V_38 && V_38 -> V_58 . V_59 == * V_24 ) {
struct V_60 * V_60 = F_30 ( V_38 ) ;
* V_24 = V_60 -> V_61 ;
V_40 = 1 ;
break;
}
}
if ( ! V_40 ) {
F_31 ( L_5 , * V_24 ) ;
return - V_62 ;
}
break;
case V_63 :
if ( V_4 -> V_49 == V_64 ) {
if ( V_4 -> V_52 ) {
if ( V_4 -> V_65 )
* V_24 = 3 ;
else
* V_24 = 2 ;
} else {
* V_24 = 0 ;
}
} else {
* V_24 = V_4 -> V_52 ;
}
break;
case V_66 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_70 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_70 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_70 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_70 ;
else if ( V_4 -> V_49 >= V_76 )
* V_24 = V_4 -> V_68 . V_77 . V_70 ;
else if ( V_4 -> V_49 >= V_78 )
* V_24 = V_4 -> V_68 . V_79 . V_70 ;
else {
F_31 ( L_6 ) ;
return - V_62 ;
}
break;
case V_80 :
if ( F_28 ( V_24 , V_34 , sizeof( T_1 ) ) ) {
F_29 ( L_4 , V_54 , __LINE__ ) ;
return - V_55 ;
}
if ( * V_24 >= 2 ) {
F_31 ( L_7 , * V_24 ) ;
return - V_62 ;
}
F_24 ( V_2 , & V_4 -> V_81 , V_27 , V_24 ) ;
break;
case V_82 :
if ( F_28 ( V_24 , V_34 , sizeof( T_1 ) ) ) {
F_29 ( L_4 , V_54 , __LINE__ ) ;
return - V_55 ;
}
if ( * V_24 >= 2 ) {
F_31 ( L_8 , * V_24 ) ;
return - V_62 ;
}
F_24 ( V_2 , & V_4 -> V_83 , V_27 , V_24 ) ;
break;
case V_84 :
if ( V_4 -> V_85 -> V_86 )
* V_24 = F_32 ( V_4 ) * 10 ;
else
* V_24 = V_4 -> clock . V_87 . V_88 * 10 ;
break;
case V_89 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_90 *
V_4 -> V_68 . V_69 . V_91 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_90 *
V_4 -> V_68 . V_72 . V_91 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_90 *
V_4 -> V_68 . V_74 . V_91 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_92 ;
else if ( V_4 -> V_49 >= V_76 )
* V_24 = V_4 -> V_68 . V_77 . V_92 ;
else if ( V_4 -> V_49 >= V_78 )
* V_24 = V_4 -> V_68 . V_79 . V_92 ;
else {
return - V_62 ;
}
break;
case V_93 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_94 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_94 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_94 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_94 ;
else if ( V_4 -> V_49 >= V_76 )
* V_24 = V_4 -> V_68 . V_77 . V_94 ;
else if ( V_4 -> V_49 >= V_78 )
* V_24 = V_4 -> V_68 . V_79 . V_94 ;
else {
return - V_62 ;
}
break;
case V_95 :
* V_24 = 1 ;
break;
case V_96 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_97 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_97 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_97 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_97 ;
else if ( V_4 -> V_49 >= V_76 )
* V_24 = V_4 -> V_68 . V_77 . V_97 ;
else if ( V_4 -> V_49 >= V_78 )
* V_24 = V_4 -> V_68 . V_79 . V_97 ;
else {
return - V_62 ;
}
break;
case V_98 :
if ( V_4 -> V_49 < V_73 )
return - V_62 ;
* V_24 = V_99 ;
break;
case V_100 :
if ( V_4 -> V_49 < V_73 )
return - V_62 ;
* V_24 = V_101 ;
break;
case V_102 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_103 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_103 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_104 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_105 ;
else if ( V_4 -> V_49 >= V_76 )
* V_24 = V_4 -> V_68 . V_77 . V_105 ;
else if ( V_4 -> V_49 >= V_78 )
* V_24 = V_4 -> V_68 . V_79 . V_105 ;
else {
return - V_62 ;
}
break;
case V_106 :
if ( V_4 -> V_49 < V_78 ) {
F_31 ( L_9 ) ;
return - V_62 ;
}
V_24 = ( T_1 * ) & V_36 ;
V_35 = sizeof( T_2 ) ;
V_36 = F_33 ( V_4 ) ;
break;
case V_107 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_91 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_91 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_91 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_108 ;
else
* V_24 = 1 ;
break;
case V_109 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_110 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_110 ;
else
return - V_62 ;
break;
case V_111 :
* V_24 = V_4 -> V_112 ;
break;
case V_113 :
if ( F_28 ( V_24 , V_34 , sizeof( T_1 ) ) ) {
F_29 ( L_4 , V_54 , __LINE__ ) ;
return - V_55 ;
}
switch ( * V_24 ) {
case V_114 :
case V_115 :
* V_24 = V_4 -> V_116 [ V_117 ] . V_118 ;
break;
case V_119 :
* V_24 = V_4 -> V_116 [ V_120 ] . V_118 ;
* V_24 |= V_4 -> V_116 [ V_121 ] . V_118 ;
break;
case V_122 :
* V_24 = V_4 -> V_116 [ V_123 ] . V_118 ;
break;
case V_124 :
* V_24 = V_4 -> V_116 [ V_125 ] . V_118 ;
break;
default:
return - V_62 ;
}
break;
case V_126 :
if ( V_4 -> V_49 >= V_67 ) {
V_24 = V_4 -> V_68 . V_69 . V_127 ;
V_35 = sizeof( T_1 ) * 32 ;
} else if ( V_4 -> V_49 >= V_71 ) {
V_24 = V_4 -> V_68 . V_72 . V_127 ;
V_35 = sizeof( T_1 ) * 32 ;
} else {
F_31 ( L_10 ) ;
return - V_62 ;
}
break;
case V_128 :
if ( V_4 -> V_49 >= V_67 ) {
V_24 = V_4 -> V_68 . V_69 . V_129 ;
V_35 = sizeof( T_1 ) * 16 ;
} else {
F_31 ( L_11 ) ;
return - V_62 ;
}
break;
case V_130 :
* V_24 = 1 ;
break;
case V_131 :
if ( V_4 -> V_49 >= V_67 ) {
* V_24 = V_4 -> V_68 . V_69 . V_132 ;
} else if ( V_4 -> V_49 >= V_71 ) {
* V_24 = V_4 -> V_68 . V_72 . V_132 ;
} else {
F_31 ( L_12 ) ;
}
break;
case V_133 :
if ( ( V_4 -> V_134 . V_135 == V_136 ) &&
V_4 -> V_134 . V_137 )
* V_24 = V_4 -> V_134 . V_138 . V_139 . V_140 . V_141 * 10 ;
else
* V_24 = V_4 -> V_134 . V_142 * 10 ;
break;
case V_143 :
* V_24 = V_4 -> V_144 . V_145 ;
break;
case V_146 :
* V_24 = V_4 -> V_144 . V_147 ;
break;
case V_148 :
V_24 = ( T_1 * ) & V_36 ;
V_35 = sizeof( T_2 ) ;
V_36 = F_34 ( & V_4 -> V_149 ) ;
break;
case V_150 :
V_24 = ( T_1 * ) & V_36 ;
V_35 = sizeof( T_2 ) ;
V_36 = F_34 ( & V_4 -> V_151 ) ;
break;
case V_152 :
V_24 = ( T_1 * ) & V_36 ;
V_35 = sizeof( T_2 ) ;
V_36 = F_34 ( & V_4 -> V_153 ) ;
break;
case V_154 :
if ( V_4 -> V_49 >= V_67 )
* V_24 = V_4 -> V_68 . V_69 . V_155 ;
else if ( V_4 -> V_49 >= V_71 )
* V_24 = V_4 -> V_68 . V_72 . V_155 ;
else if ( V_4 -> V_49 >= V_73 )
* V_24 = V_4 -> V_68 . V_74 . V_156 ;
else if ( V_4 -> V_49 >= V_50 )
* V_24 = V_4 -> V_68 . V_75 . V_156 ;
else if ( V_4 -> V_49 >= V_76 )
* V_24 = V_4 -> V_68 . V_77 . V_156 ;
else if ( V_4 -> V_49 >= V_78 )
* V_24 = V_4 -> V_68 . V_79 . V_156 ;
else
* V_24 = 1 ;
break;
default:
F_31 ( L_13 , V_29 -> V_41 ) ;
return - V_62 ;
}
if ( F_35 ( V_34 , ( char * ) V_24 , V_35 ) ) {
F_29 ( L_14 , V_54 , __LINE__ ) ;
return - V_55 ;
}
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 () ;
}
int F_38 ( struct V_1 * V_2 , struct V_21 * V_157 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_157 -> V_158 = NULL ;
V_9 = F_3 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 -> V_49 >= V_73 ) {
struct V_159 * V_160 ;
struct V_161 * V_162 ;
int V_9 ;
V_160 = F_9 ( sizeof( * V_160 ) , V_11 ) ;
if ( F_39 ( ! V_160 ) ) {
return - V_12 ;
}
V_162 = & V_160 -> V_162 ;
V_9 = F_40 ( V_4 , V_162 ) ;
if ( V_9 ) {
F_7 ( V_160 ) ;
return V_9 ;
}
if ( V_4 -> V_52 ) {
V_9 = F_41 ( V_4 -> V_163 . V_164 , false ) ;
if ( V_9 ) {
F_42 ( V_4 , V_162 ) ;
F_7 ( V_160 ) ;
return V_9 ;
}
V_162 -> V_165 = F_43 ( V_4 , V_162 ,
V_4 -> V_163 . V_164 ) ;
V_9 = F_44 ( V_4 , V_162 -> V_165 ,
V_166 ,
V_167 |
V_168 ) ;
F_45 ( V_4 -> V_163 . V_164 ) ;
if ( V_9 ) {
F_42 ( V_4 , V_162 ) ;
F_7 ( V_160 ) ;
return V_9 ;
}
}
V_157 -> V_158 = V_160 ;
}
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 -> V_2 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_21 * V_157 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_49 >= V_73 && V_157 -> V_158 ) {
struct V_159 * V_160 = V_157 -> V_158 ;
struct V_161 * V_162 = & V_160 -> V_162 ;
int V_9 ;
if ( V_4 -> V_52 ) {
V_9 = F_41 ( V_4 -> V_163 . V_164 , false ) ;
if ( ! V_9 ) {
if ( V_162 -> V_165 )
F_47 ( V_4 , V_162 -> V_165 ) ;
F_45 ( V_4 -> V_163 . V_164 ) ;
}
}
F_42 ( V_4 , V_162 ) ;
F_7 ( V_160 ) ;
V_157 -> V_158 = NULL ;
}
}
void F_48 ( struct V_1 * V_2 ,
struct V_21 * V_157 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_81 == V_157 )
V_4 -> V_81 = NULL ;
if ( V_4 -> V_83 == V_157 )
V_4 -> V_83 = NULL ;
F_49 ( V_4 , V_157 ) ;
F_50 ( V_4 , V_157 ) ;
}
T_3 F_51 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_38 < 0 || V_38 >= V_4 -> V_56 ) {
F_29 ( L_15 , V_38 ) ;
return - V_62 ;
}
return F_52 ( V_4 , V_38 ) ;
}
int F_53 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_169 ;
int V_9 ;
if ( V_38 < 0 || V_38 >= V_4 -> V_56 ) {
F_29 ( L_15 , V_38 ) ;
return - V_62 ;
}
F_54 ( & V_4 -> V_170 . V_171 , V_169 ) ;
V_4 -> V_170 . V_172 [ V_38 ] = true ;
V_9 = F_55 ( V_4 ) ;
F_56 ( & V_4 -> V_170 . V_171 , V_169 ) ;
return V_9 ;
}
void F_57 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_169 ;
if ( V_38 < 0 || V_38 >= V_4 -> V_56 ) {
F_29 ( L_15 , V_38 ) ;
return;
}
F_54 ( & V_4 -> V_170 . V_171 , V_169 ) ;
V_4 -> V_170 . V_172 [ V_38 ] = false ;
F_55 ( V_4 ) ;
F_56 ( & V_4 -> V_170 . V_171 , V_169 ) ;
}
int F_58 ( struct V_1 * V_2 , int V_38 ,
int * V_173 ,
struct V_174 * V_175 ,
unsigned V_8 )
{
struct V_37 * V_176 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_38 < 0 || V_38 >= V_2 -> V_177 ) {
F_29 ( L_15 , V_38 ) ;
return - V_62 ;
}
V_176 = & V_4 -> V_32 . V_57 [ V_38 ] -> V_58 ;
if ( ! V_176 )
return - V_62 ;
return F_59 ( V_2 , V_38 , V_173 ,
V_175 , V_8 ,
V_176 , & V_176 -> V_178 ) ;
}
