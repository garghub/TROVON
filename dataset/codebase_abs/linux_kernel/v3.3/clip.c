static int F_1 ( enum V_1 type , int V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_2 ( L_1 , type ) ;
if ( ! V_10 )
return - V_11 ;
V_9 = F_3 ( sizeof( struct V_6 ) , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_7 = (struct V_6 * ) F_4 ( V_9 , sizeof( struct V_6 ) ) ;
V_7 -> type = type ;
V_7 -> V_14 = V_2 ;
V_7 -> V_3 = V_3 ;
F_5 ( V_10 , V_9 -> V_15 ) ;
V_5 = F_6 ( V_10 ) ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
V_5 -> V_17 ( V_5 , V_9 -> V_18 ) ;
return 0 ;
}
static void F_8 ( struct V_19 * V_19 , struct V_20 * V_21 )
{
F_2 ( L_2 , V_19 , V_21 , V_21 -> V_22 ) ;
V_19 -> V_21 = V_21 ;
V_19 -> V_23 = 0 ;
V_19 -> V_24 = V_21 -> V_25 ;
V_21 -> V_25 = V_19 ;
V_21 -> V_22 -> V_26 = V_27 ;
}
static void F_9 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_19 * * V_28 ;
if ( ! V_21 ) {
F_10 ( L_3 , V_19 ) ;
return;
}
F_11 ( V_21 -> V_22 -> V_29 ) ;
V_21 -> V_22 -> V_26 = V_27 ;
for ( V_28 = & V_21 -> V_25 ; * V_28 ; V_28 = & ( * V_28 ) -> V_24 )
if ( * V_28 == V_19 ) {
int error ;
* V_28 = V_19 -> V_24 ;
V_19 -> V_21 = NULL ;
if ( V_19 -> V_23 )
F_12 ( V_21 -> V_22 -> V_29 ) ;
if ( V_21 -> V_25 )
goto V_30;
V_21 -> V_31 = V_27 - 1 ;
error = F_13 ( V_21 -> V_22 , NULL , V_32 ,
V_33 ) ;
if ( error )
F_10 ( L_4 , error ) ;
goto V_30;
}
F_10 ( L_5 , V_21 , V_19 ) ;
V_30:
F_14 ( V_21 -> V_22 -> V_29 ) ;
}
static int F_15 ( struct V_34 * V_35 )
{
struct V_20 * V_21 = F_16 ( V_35 ) ;
struct V_19 * V_36 ;
if ( V_35 -> V_37 != & V_38 )
return 0 ;
for ( V_36 = V_21 -> V_25 ; V_36 ; V_36 = V_36 -> V_24 ) {
unsigned long exp = V_36 -> V_39 + V_36 -> V_40 ;
if ( V_36 -> V_40 && F_17 ( V_27 , exp ) ) {
F_2 ( L_6 ,
V_36 , V_36 -> V_41 , V_21 ) ;
F_18 ( V_36 -> V_41 , - V_42 ) ;
}
}
if ( V_21 -> V_25 || F_19 ( V_27 , V_21 -> V_31 ) )
return 0 ;
if ( F_20 ( & V_35 -> V_43 ) > 1 ) {
struct V_8 * V_9 ;
F_2 ( L_7 ,
F_20 ( & V_35 -> V_43 ) ) ;
while ( ( V_9 = F_21 ( & V_35 -> V_44 ) ) != NULL )
F_22 ( V_9 ) ;
return 0 ;
}
F_2 ( L_8 , V_35 ) ;
return 1 ;
}
static void F_23 ( unsigned long V_45 )
{
F_24 ( & V_46 . V_47 ) ;
F_25 ( & V_46 , F_15 ) ;
F_26 ( & V_48 , V_27 + V_49 * V_50 ) ;
F_27 ( & V_46 . V_47 ) ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_51 * V_41 ;
F_2 ( L_9 ) ;
V_41 = F_29 ( V_9 ) -> V_41 ;
if ( ! V_41 || ! F_30 ( V_41 , V_9 -> V_15 ) ) {
F_31 ( V_9 ) ;
return 0 ;
}
F_2 ( L_10 , V_41 ) ;
F_2 ( L_11 , F_32 ( V_41 ) -> V_52 ) ;
F_32 ( V_41 ) -> V_52 ( V_41 , V_9 ) ;
return 0 ;
}
static void F_33 ( struct V_51 * V_41 , struct V_8 * V_9 )
{
struct V_19 * V_19 = F_32 ( V_41 ) ;
F_2 ( L_9 ) ;
if ( ! V_53 ) {
F_34 ( V_41 , V_9 -> V_15 ) ;
F_35 ( V_9 ) ;
return;
}
if ( ! V_9 ) {
F_2 ( L_12 , V_19 ) ;
if ( V_19 -> V_21 )
F_9 ( V_19 ) ;
V_19 -> V_52 ( V_41 , NULL ) ;
F_36 ( V_19 ) ;
return;
}
F_34 ( V_41 , V_9 -> V_15 ) ;
V_9 -> V_29 = V_19 -> V_21 ? V_19 -> V_21 -> V_22 -> V_29 : V_53 ;
if ( ! V_9 -> V_29 ) {
F_31 ( V_9 ) ;
return;
}
F_29 ( V_9 ) -> V_41 = V_41 ;
F_37 ( V_9 ) ;
if ( ! V_19 -> V_54 ||
V_9 -> V_18 < V_55 ||
memcmp ( V_9 -> V_56 , V_57 , sizeof( V_57 ) ) )
V_9 -> V_58 = F_38 ( V_59 ) ;
else {
V_9 -> V_58 = ( ( V_60 * ) V_9 -> V_56 ) [ 3 ] ;
F_39 ( V_9 , V_55 ) ;
if ( V_9 -> V_58 == F_38 ( V_61 ) ) {
V_9 -> V_29 -> V_62 . V_63 ++ ;
V_9 -> V_29 -> V_62 . V_64 += V_9 -> V_18 ;
F_28 ( V_9 ) ;
return;
}
}
V_19 -> V_39 = V_27 ;
V_9 -> V_29 -> V_62 . V_63 ++ ;
V_9 -> V_29 -> V_62 . V_64 += V_9 -> V_18 ;
memset ( F_29 ( V_9 ) , 0 , sizeof( struct V_65 ) ) ;
F_40 ( V_9 ) ;
}
static void F_41 ( struct V_51 * V_41 , struct V_8 * V_9 )
{
struct V_19 * V_19 = F_32 ( V_41 ) ;
struct V_66 * V_29 = V_9 -> V_29 ;
int V_67 ;
unsigned long V_68 ;
F_2 ( L_13 , V_41 ) ;
V_19 -> V_69 ( V_41 , V_9 ) ;
if ( ! V_29 )
return;
F_42 ( & F_43 ( V_29 ) -> V_70 , V_68 ) ;
if ( F_44 ( V_41 , 0 ) ) {
V_67 = F_45 ( & V_19 -> V_23 , 0 ) ;
if ( V_67 )
F_12 ( V_29 ) ;
}
F_46 ( & F_43 ( V_29 ) -> V_70 , V_68 ) ;
}
static void F_47 ( struct V_34 * V_22 , struct V_8 * V_9 )
{
T_1 * V_3 = ( T_1 * ) V_22 -> V_71 ;
F_2 ( L_14 , V_22 , V_9 ) ;
F_1 ( V_72 , F_43 ( V_22 -> V_29 ) -> V_73 , * V_3 ) ;
}
static void F_48 ( struct V_34 * V_22 , struct V_8 * V_9 )
{
#ifndef F_49
F_50 ( V_9 , V_74 , V_75 , 0 ) ;
#endif
F_35 ( V_9 ) ;
}
static int F_51 ( struct V_34 * V_22 )
{
struct V_20 * V_21 = F_16 ( V_22 ) ;
if ( V_22 -> V_76 -> V_77 != V_78 )
return - V_79 ;
if ( V_22 -> type != V_80 )
return - V_79 ;
V_22 -> V_81 = V_32 ;
V_22 -> V_37 = & V_38 ;
V_22 -> V_82 = V_22 -> V_37 -> V_82 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_25 = NULL ;
V_21 -> V_31 = V_27 - 1 ;
return 0 ;
}
static int F_52 ( struct V_51 * V_41 , int V_83 )
{
F_32 ( V_41 ) -> V_54 = V_83 ;
return 0 ;
}
static T_2 F_53 ( struct V_8 * V_9 ,
struct V_66 * V_29 )
{
struct V_84 * V_84 = F_43 ( V_29 ) ;
struct V_85 * V_86 = F_54 ( V_9 ) ;
struct V_20 * V_21 ;
struct V_34 * V_35 ;
struct V_51 * V_41 ;
int V_67 ;
unsigned long V_68 ;
F_2 ( L_15 , V_9 ) ;
if ( ! V_86 ) {
F_55 ( L_16 ) ;
F_22 ( V_9 ) ;
V_29 -> V_62 . V_87 ++ ;
return V_88 ;
}
V_35 = F_56 ( V_86 ) ;
if ( ! V_35 ) {
F_55 ( L_17 ) ;
F_22 ( V_9 ) ;
V_29 -> V_62 . V_87 ++ ;
return V_88 ;
}
V_21 = F_16 ( V_35 ) ;
if ( ! V_21 -> V_25 ) {
if ( F_17 ( V_27 , V_21 -> V_31 ) ) {
V_21 -> V_31 = V_27 + V_89 * V_50 ;
F_1 ( V_72 , F_43 ( V_29 ) -> V_73 , * ( ( T_1 * ) V_35 -> V_71 ) ) ;
}
if ( V_21 -> V_22 -> V_44 . V_90 < V_91 )
F_7 ( & V_21 -> V_22 -> V_44 , V_9 ) ;
else {
F_22 ( V_9 ) ;
V_29 -> V_62 . V_87 ++ ;
}
return V_88 ;
}
F_2 ( L_18 , V_21 , V_21 -> V_25 ) ;
F_29 ( V_9 ) -> V_41 = V_41 = V_21 -> V_25 -> V_41 ;
F_2 ( L_19 , V_35 , V_41 ) ;
if ( V_21 -> V_25 -> V_54 ) {
void * V_92 ;
V_92 = F_57 ( V_9 , V_55 ) ;
memcpy ( V_92 , V_57 , sizeof( V_57 ) ) ;
( ( V_60 * ) V_92 ) [ 3 ] = V_9 -> V_58 ;
}
F_58 ( V_9 -> V_15 , & F_6 ( V_41 ) -> V_93 ) ;
F_29 ( V_9 ) -> V_94 = V_41 -> V_94 ;
V_21 -> V_25 -> V_39 = V_27 ;
F_2 ( L_20 , V_9 , V_41 , V_41 -> V_29 ) ;
V_67 = F_45 ( & V_21 -> V_25 -> V_23 , 1 ) ;
if ( V_67 ) {
F_59 ( L_21 ) ;
return V_88 ;
}
V_29 -> V_62 . V_95 ++ ;
V_29 -> V_62 . V_96 += V_9 -> V_18 ;
V_41 -> V_97 ( V_41 , V_9 ) ;
if ( F_44 ( V_41 , 0 ) ) {
V_21 -> V_25 -> V_23 = 0 ;
return V_88 ;
}
F_42 ( & V_84 -> V_70 , V_68 ) ;
F_60 ( V_29 ) ;
F_61 () ;
if ( ! V_21 -> V_25 -> V_23 )
F_62 ( V_29 ) ;
F_46 ( & V_84 -> V_70 , V_68 ) ;
return V_88 ;
}
static int F_63 ( struct V_51 * V_41 , int V_98 )
{
struct V_19 * V_19 ;
if ( ! V_41 -> V_99 )
return - V_100 ;
V_19 = F_64 ( sizeof( struct V_19 ) , V_101 ) ;
if ( ! V_19 )
return - V_13 ;
F_2 ( L_22 , V_19 , V_41 ) ;
V_19 -> V_41 = V_41 ;
V_41 -> V_102 = V_19 ;
F_65 ( V_103 , & V_41 -> V_68 ) ;
V_19 -> V_21 = NULL ;
V_19 -> V_23 = 0 ;
V_19 -> V_54 = 1 ;
V_19 -> V_39 = V_27 ;
V_19 -> V_40 = V_98 * V_50 ;
V_19 -> V_52 = V_41 -> V_99 ;
V_19 -> V_69 = V_41 -> V_104 ;
V_41 -> V_99 = F_33 ;
V_41 -> V_104 = F_41 ;
F_66 ( V_41 ) ;
return 0 ;
}
static int F_67 ( struct V_51 * V_41 , T_1 V_3 )
{
struct V_34 * V_22 ;
struct V_20 * V_21 ;
int error ;
struct V_19 * V_19 ;
struct V_105 * V_106 ;
if ( V_41 -> V_99 != F_33 ) {
F_59 ( L_23 ) ;
return - V_107 ;
}
V_19 = F_32 ( V_41 ) ;
if ( ! V_3 ) {
if ( ! V_19 -> V_21 ) {
F_55 ( L_24 ) ;
return 0 ;
}
F_2 ( L_25 ) ;
F_9 ( V_19 ) ;
return 0 ;
}
V_106 = F_68 ( & V_108 , V_3 , 0 , 1 , 0 ) ;
if ( F_69 ( V_106 ) )
return F_70 ( V_106 ) ;
V_22 = F_71 ( & V_46 , & V_3 , V_106 -> V_86 . V_29 , 1 ) ;
F_72 ( V_106 ) ;
if ( ! V_22 )
return - V_13 ;
V_21 = F_16 ( V_22 ) ;
if ( V_21 != V_19 -> V_21 ) {
if ( ! V_19 -> V_21 )
F_2 ( L_26 ) ;
else {
F_2 ( L_27 ) ;
F_9 ( V_19 ) ;
}
F_8 ( V_19 , V_21 ) ;
}
error = F_13 ( V_22 , V_57 , V_109 ,
V_110 | V_33 ) ;
F_73 ( V_22 ) ;
return error ;
}
static void F_74 ( struct V_66 * V_29 )
{
V_29 -> V_111 = & V_112 ;
V_29 -> type = V_113 ;
V_29 -> V_114 = sizeof( struct V_20 ) ;
V_29 -> V_115 = V_55 ;
V_29 -> V_116 = V_117 ;
V_29 -> V_118 = 100 ;
V_29 -> V_119 &= ~ V_120 ;
}
static int F_75 ( int V_73 )
{
struct V_66 * V_29 ;
struct V_84 * V_84 ;
int error ;
if ( V_73 != - 1 ) {
for ( V_29 = V_53 ; V_29 ; V_29 = F_43 ( V_29 ) -> V_24 )
if ( F_43 ( V_29 ) -> V_73 == V_73 )
return - V_121 ;
} else {
V_73 = 0 ;
for ( V_29 = V_53 ; V_29 ; V_29 = F_43 ( V_29 ) -> V_24 )
if ( F_43 ( V_29 ) -> V_73 >= V_73 )
V_73 = F_43 ( V_29 ) -> V_73 + 1 ;
}
V_29 = F_76 ( sizeof( struct V_84 ) , L_28 , F_74 ) ;
if ( ! V_29 )
return - V_13 ;
V_84 = F_43 ( V_29 ) ;
sprintf ( V_29 -> V_122 , L_29 , V_73 ) ;
F_77 ( & V_84 -> V_70 ) ;
V_84 -> V_73 = V_73 ;
error = F_78 ( V_29 ) ;
if ( error ) {
F_79 ( V_29 ) ;
return error ;
}
V_84 -> V_24 = V_53 ;
V_53 = V_29 ;
F_2 ( L_30 , V_29 -> V_122 ) ;
return V_73 ;
}
static int F_80 ( struct V_123 * V_124 , unsigned long V_125 ,
void * V_126 )
{
struct V_66 * V_29 = V_126 ;
if ( ! F_81 ( F_82 ( V_29 ) , & V_108 ) )
return V_127 ;
if ( V_125 == V_128 )
return V_127 ;
if ( V_29 -> type != V_113 || V_29 -> V_111 != & V_112 )
return V_127 ;
switch ( V_125 ) {
case V_129 :
F_2 ( L_31 ) ;
F_1 ( V_130 , F_43 ( V_29 ) -> V_73 , 0 ) ;
break;
case V_131 :
F_2 ( L_32 ) ;
F_1 ( V_132 , F_43 ( V_29 ) -> V_73 , 0 ) ;
break;
case V_133 :
case V_134 :
F_2 ( L_33 ) ;
F_1 ( V_135 , F_43 ( V_29 ) -> V_73 , 0 ) ;
break;
}
return V_127 ;
}
static int F_83 ( struct V_123 * V_124 , unsigned long V_125 ,
void * V_136 )
{
struct V_137 * V_138 ;
V_138 = ( (struct V_139 * ) V_136 ) -> V_140 ;
if ( V_125 != V_129 )
return V_127 ;
return F_80 ( V_124 , V_133 , V_138 -> V_29 ) ;
}
static void F_84 ( struct V_51 * V_41 )
{
F_2 ( L_9 ) ;
F_85 () ;
V_10 = NULL ;
F_86 ( & F_6 ( V_41 ) -> V_16 ) ;
F_87 () ;
F_2 ( L_34 ) ;
F_88 ( V_141 ) ;
}
static int F_89 ( struct V_51 * V_41 )
{
F_85 () ;
if ( V_10 ) {
F_87 () ;
return - V_142 ;
}
F_26 ( & V_48 , V_27 + V_49 * V_50 ) ;
V_10 = V_41 ;
F_65 ( V_143 , & V_41 -> V_68 ) ;
F_65 ( V_144 , & V_41 -> V_68 ) ;
V_41 -> V_29 = & V_145 ;
F_90 ( F_6 ( V_41 ) ) ;
V_41 -> V_99 = NULL ;
V_41 -> V_104 = NULL ;
V_41 -> V_146 = NULL ;
F_87 () ;
return 0 ;
}
static int F_91 ( struct V_147 * V_4 , unsigned int V_148 , unsigned long V_126 )
{
struct V_51 * V_41 = F_92 ( V_4 ) ;
int V_149 = 0 ;
switch ( V_148 ) {
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
if ( ! F_93 ( V_155 ) )
return - V_156 ;
break;
default:
return - V_157 ;
}
switch ( V_148 ) {
case V_150 :
V_149 = F_75 ( V_126 ) ;
break;
case V_151 :
V_149 = F_89 ( V_41 ) ;
if ( ! V_149 ) {
V_4 -> V_158 = V_159 ;
F_94 ( V_141 ) ;
}
break;
case V_152 :
V_149 = F_63 ( V_41 , V_126 ) ;
break;
case V_153 :
V_149 = F_67 ( V_41 , ( V_160 T_1 ) V_126 ) ;
break;
case V_154 :
V_149 = F_52 ( V_41 , V_126 ) ;
break;
}
return V_149 ;
}
static void F_95 ( struct V_161 * V_162 , struct V_163 * V_164 )
{
static int V_165 [] = { 1 , 2 , 10 , 6 , 1 , 0 } ;
static int V_166 [] = { 1 , 8 , 4 , 6 , 1 , 0 } ;
if ( * V_164 -> V_167 . V_168 ) {
F_96 ( V_162 , L_35 , V_164 -> V_167 . V_168 ) ;
if ( * V_164 -> V_167 . V_169 )
F_97 ( V_162 , '+' ) ;
} else if ( ! * V_164 -> V_167 . V_169 ) {
F_96 ( V_162 , L_35 , L_36 ) ;
return;
}
if ( * V_164 -> V_167 . V_169 ) {
unsigned char * V_169 = V_164 -> V_167 . V_169 ;
int * V_170 ;
int V_171 , V_172 ;
V_170 = * V_169 == V_173 ? V_166 : V_165 ;
for ( V_171 = 0 ; V_170 [ V_171 ] ; V_171 ++ ) {
for ( V_172 = V_170 [ V_171 ] ; V_172 ; V_172 -- )
F_96 ( V_162 , L_37 , * V_169 ++ ) ;
if ( V_170 [ V_171 + 1 ] )
F_97 ( V_162 , '.' ) ;
}
}
}
static void F_98 ( struct V_161 * V_162 , struct V_34 * V_35 ,
struct V_20 * V_21 , struct V_19 * V_19 )
{
struct V_66 * V_29 = V_35 -> V_29 ;
unsigned long exp ;
char V_174 [ 17 ] ;
int V_175 , V_176 , V_177 ;
V_175 = ( ( V_19 == V_178 ) ||
( F_6 ( V_19 -> V_41 ) -> V_179 == V_180 ) ) ;
V_176 = ( ( V_19 == V_178 ) || V_19 -> V_54 ) ;
if ( V_19 == V_178 )
exp = V_21 -> V_22 -> V_26 ;
else
exp = V_19 -> V_39 ;
exp = ( V_27 - exp ) / V_50 ;
F_96 ( V_162 , L_38 ,
V_29 -> V_122 , V_175 ? L_39 : L_40 , V_176 ? L_41 : L_42 , exp ) ;
V_177 = F_99 ( V_174 , sizeof( V_174 ) - 1 , L_43 , V_35 -> V_71 ) ;
while ( V_177 < 16 )
V_174 [ V_177 ++ ] = ' ' ;
V_174 [ V_177 ] = '\0' ;
F_96 ( V_162 , L_35 , V_174 ) ;
if ( V_19 == V_178 ) {
if ( F_19 ( V_27 , V_21 -> V_31 ) )
F_96 ( V_162 , L_44 ) ;
else
F_96 ( V_162 , L_45 ,
F_20 ( & V_21 -> V_22 -> V_43 ) ) ;
} else if ( ! V_175 ) {
F_96 ( V_162 , L_46 ,
V_19 -> V_41 -> V_29 -> V_73 ,
V_19 -> V_41 -> V_181 , V_19 -> V_41 -> V_182 ) ;
} else {
F_95 ( V_162 , & V_19 -> V_41 -> V_183 ) ;
F_97 ( V_162 , '\n' ) ;
}
}
static struct V_19 * F_100 ( struct V_20 * V_184 ,
struct V_19 * V_185 )
{
if ( ! V_185 ) {
V_185 = V_184 -> V_25 ;
if ( ! V_185 )
return V_178 ;
return V_185 ;
}
if ( V_185 == V_178 )
return NULL ;
V_185 = V_185 -> V_24 ;
return V_185 ;
}
static void * F_101 ( struct V_186 * V_158 ,
struct V_20 * V_184 , T_3 * V_187 )
{
struct V_19 * V_41 = V_158 -> V_41 ;
V_41 = F_100 ( V_184 , V_41 ) ;
if ( V_41 && V_187 != NULL ) {
while ( * V_187 ) {
V_41 = F_100 ( V_184 , V_41 ) ;
if ( ! V_41 )
break;
-- ( * V_187 ) ;
}
}
V_158 -> V_41 = V_41 ;
return V_41 ;
}
static void * F_102 ( struct V_188 * V_189 ,
struct V_34 * V_35 , T_3 * V_187 )
{
struct V_186 * V_158 = (struct V_186 * ) V_189 ;
if ( V_35 -> V_29 -> type != V_113 )
return NULL ;
return F_101 ( V_158 , F_16 ( V_35 ) , V_187 ) ;
}
static void * F_103 ( struct V_161 * V_162 , T_3 * V_187 )
{
struct V_186 * V_158 = V_162 -> V_190 ;
V_158 -> V_191 . V_192 = F_102 ;
return F_104 ( V_162 , V_187 , & V_46 , V_193 ) ;
}
static int F_105 ( struct V_161 * V_162 , void * V_194 )
{
static char V_195 [] =
L_47 ;
if ( V_194 == V_196 ) {
F_106 ( V_162 , V_195 ) ;
} else {
struct V_186 * V_158 = V_162 -> V_190 ;
struct V_19 * V_41 = V_158 -> V_41 ;
struct V_34 * V_35 = V_194 ;
F_98 ( V_162 , V_35 , F_16 ( V_35 ) , V_41 ) ;
}
return 0 ;
}
static int F_107 ( struct V_197 * V_197 , struct V_198 * V_198 )
{
return F_108 ( V_197 , V_198 , & V_199 ,
sizeof( struct V_186 ) ) ;
}
static int T_4 F_109 ( void )
{
F_110 ( & V_200 ) ;
F_111 ( & V_201 ) ;
F_112 ( & V_202 ) ;
F_113 ( & V_48 , F_23 , 0 ) ;
#ifdef F_114
{
struct V_203 * V_204 ;
V_204 = F_115 ( L_48 , V_205 , V_206 , & V_207 ) ;
if ( ! V_204 ) {
F_55 ( L_49 ) ;
F_116 () ;
return - V_13 ;
}
}
#endif
return 0 ;
}
static void F_116 ( void )
{
struct V_66 * V_29 , * V_24 ;
F_117 ( & V_202 ) ;
F_118 ( & V_201 ) ;
F_119 ( & V_200 ) ;
F_120 ( & V_48 ) ;
V_29 = V_53 ;
while ( V_29 ) {
V_24 = F_43 ( V_29 ) -> V_24 ;
F_121 ( V_29 ) ;
F_79 ( V_29 ) ;
V_29 = V_24 ;
}
}
static void T_5 F_122 ( void )
{
F_123 ( L_48 , V_206 ) ;
F_116 () ;
}
