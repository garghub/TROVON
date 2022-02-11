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
V_5 -> V_17 ( V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_18 * V_18 , struct V_19 * V_20 )
{
F_2 ( L_2 , V_18 , V_20 , V_20 -> V_21 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_22 = 0 ;
V_18 -> V_23 = V_20 -> V_24 ;
V_20 -> V_24 = V_18 ;
V_20 -> V_21 -> V_25 = V_26 ;
}
static void F_9 ( struct V_18 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_18 * * V_27 ;
if ( ! V_20 ) {
F_10 ( L_3 , V_18 ) ;
return;
}
F_11 ( V_20 -> V_21 -> V_28 ) ;
V_20 -> V_21 -> V_25 = V_26 ;
for ( V_27 = & V_20 -> V_24 ; * V_27 ; V_27 = & ( * V_27 ) -> V_23 )
if ( * V_27 == V_18 ) {
int error ;
* V_27 = V_18 -> V_23 ;
V_18 -> V_20 = NULL ;
if ( V_18 -> V_22 )
F_12 ( V_20 -> V_21 -> V_28 ) ;
if ( V_20 -> V_24 )
goto V_29;
V_20 -> V_30 = V_26 - 1 ;
error = F_13 ( V_20 -> V_21 , NULL , V_31 ,
V_32 ) ;
if ( error )
F_10 ( L_4 , error ) ;
goto V_29;
}
F_10 ( L_5 , V_20 , V_18 ) ;
V_29:
F_14 ( V_20 -> V_21 -> V_28 ) ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_19 * V_20 = F_16 ( V_34 ) ;
struct V_18 * V_35 ;
if ( V_34 -> V_36 != & V_37 )
return 0 ;
for ( V_35 = V_20 -> V_24 ; V_35 ; V_35 = V_35 -> V_23 ) {
unsigned long exp = V_35 -> V_38 + V_35 -> V_39 ;
if ( V_35 -> V_39 && F_17 ( V_26 , exp ) ) {
F_2 ( L_6 ,
V_35 , V_35 -> V_40 , V_20 ) ;
F_18 ( V_35 -> V_40 , - V_41 ) ;
}
}
if ( V_20 -> V_24 || F_19 ( V_26 , V_20 -> V_30 ) )
return 0 ;
if ( F_20 ( & V_34 -> V_42 ) > 1 ) {
struct V_8 * V_9 ;
F_2 ( L_7 ,
F_20 ( & V_34 -> V_42 ) ) ;
while ( ( V_9 = F_21 ( & V_34 -> V_43 ) ) != NULL )
F_22 ( V_9 ) ;
return 0 ;
}
F_2 ( L_8 , V_34 ) ;
return 1 ;
}
static void F_23 ( unsigned long V_44 )
{
F_24 ( & V_45 . V_46 ) ;
F_25 ( & V_45 , F_15 ) ;
F_26 ( & V_47 , V_26 + V_48 * V_49 ) ;
F_27 ( & V_45 . V_46 ) ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_50 * V_40 ;
F_2 ( L_9 ) ;
V_40 = F_29 ( V_9 ) -> V_40 ;
if ( ! V_40 || ! F_30 ( V_40 , V_9 -> V_15 ) ) {
F_31 ( V_9 ) ;
return 0 ;
}
F_2 ( L_10 , V_40 ) ;
F_2 ( L_11 , F_32 ( V_40 ) -> V_51 ) ;
F_32 ( V_40 ) -> V_51 ( V_40 , V_9 ) ;
return 0 ;
}
static void F_33 ( struct V_50 * V_40 , struct V_8 * V_9 )
{
struct V_18 * V_18 = F_32 ( V_40 ) ;
F_2 ( L_9 ) ;
if ( ! V_52 ) {
F_34 ( V_40 , V_9 -> V_15 ) ;
F_35 ( V_9 ) ;
return;
}
if ( ! V_9 ) {
F_2 ( L_12 , V_18 ) ;
if ( V_18 -> V_20 )
F_9 ( V_18 ) ;
V_18 -> V_51 ( V_40 , NULL ) ;
F_36 ( V_18 ) ;
return;
}
F_34 ( V_40 , V_9 -> V_15 ) ;
V_9 -> V_28 = V_18 -> V_20 ? V_18 -> V_20 -> V_21 -> V_28 : V_52 ;
if ( ! V_9 -> V_28 ) {
F_31 ( V_9 ) ;
return;
}
F_29 ( V_9 ) -> V_40 = V_40 ;
F_37 ( V_9 ) ;
if ( ! V_18 -> V_53 ||
V_9 -> V_54 < V_55 ||
memcmp ( V_9 -> V_56 , V_57 , sizeof( V_57 ) ) )
V_9 -> V_58 = F_38 ( V_59 ) ;
else {
V_9 -> V_58 = ( ( V_60 * ) V_9 -> V_56 ) [ 3 ] ;
F_39 ( V_9 , V_55 ) ;
if ( V_9 -> V_58 == F_38 ( V_61 ) ) {
V_9 -> V_28 -> V_62 . V_63 ++ ;
V_9 -> V_28 -> V_62 . V_64 += V_9 -> V_54 ;
F_28 ( V_9 ) ;
return;
}
}
V_18 -> V_38 = V_26 ;
V_9 -> V_28 -> V_62 . V_63 ++ ;
V_9 -> V_28 -> V_62 . V_64 += V_9 -> V_54 ;
memset ( F_29 ( V_9 ) , 0 , sizeof( struct V_65 ) ) ;
F_40 ( V_9 ) ;
}
static void F_41 ( struct V_50 * V_40 , struct V_8 * V_9 )
{
struct V_18 * V_18 = F_32 ( V_40 ) ;
struct V_66 * V_28 = V_9 -> V_28 ;
int V_67 ;
unsigned long V_68 ;
F_2 ( L_13 , V_40 ) ;
V_18 -> V_69 ( V_40 , V_9 ) ;
if ( ! V_28 )
return;
F_42 ( & F_43 ( V_28 ) -> V_70 , V_68 ) ;
if ( F_44 ( V_40 , 0 ) ) {
V_67 = F_45 ( & V_18 -> V_22 , 0 ) ;
if ( V_67 )
F_12 ( V_28 ) ;
}
F_46 ( & F_43 ( V_28 ) -> V_70 , V_68 ) ;
}
static void F_47 ( struct V_33 * V_21 , struct V_8 * V_9 )
{
T_1 * V_3 = ( T_1 * ) V_21 -> V_71 ;
F_2 ( L_14 , V_21 , V_9 ) ;
F_1 ( V_72 , F_43 ( V_21 -> V_28 ) -> V_73 , * V_3 ) ;
}
static void F_48 ( struct V_33 * V_21 , struct V_8 * V_9 )
{
#ifndef F_49
F_50 ( V_9 , V_74 , V_75 , 0 ) ;
#endif
F_35 ( V_9 ) ;
}
static int F_51 ( struct V_33 * V_21 )
{
struct V_19 * V_20 = F_16 ( V_21 ) ;
if ( V_21 -> V_76 -> V_77 != V_78 )
return - V_79 ;
if ( V_21 -> type != V_80 )
return - V_79 ;
V_21 -> V_81 = V_31 ;
V_21 -> V_36 = & V_37 ;
V_21 -> V_82 = V_21 -> V_36 -> V_82 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_24 = NULL ;
V_20 -> V_30 = V_26 - 1 ;
return 0 ;
}
static int F_52 ( struct V_50 * V_40 , int V_83 )
{
F_32 ( V_40 ) -> V_53 = V_83 ;
return 0 ;
}
static T_2 F_53 ( struct V_8 * V_9 ,
struct V_66 * V_28 )
{
struct V_84 * V_84 = F_43 ( V_28 ) ;
struct V_85 * V_86 = F_54 ( V_9 ) ;
struct V_19 * V_20 ;
struct V_33 * V_34 ;
struct V_50 * V_40 ;
struct V_87 * V_88 ;
T_1 * V_89 ;
int V_67 ;
unsigned long V_68 ;
F_2 ( L_15 , V_9 ) ;
if ( ! V_86 ) {
F_55 ( L_16 ) ;
F_22 ( V_9 ) ;
V_28 -> V_62 . V_90 ++ ;
return V_91 ;
}
V_88 = (struct V_87 * ) V_86 ;
if ( V_88 -> V_92 )
V_89 = & V_88 -> V_92 ;
else
V_89 = & F_56 ( V_9 ) -> V_89 ;
V_34 = F_57 ( V_86 , V_89 ) ;
if ( ! V_34 ) {
F_55 ( L_17 ) ;
F_22 ( V_9 ) ;
V_28 -> V_62 . V_90 ++ ;
return V_91 ;
}
V_20 = F_16 ( V_34 ) ;
if ( ! V_20 -> V_24 ) {
if ( F_17 ( V_26 , V_20 -> V_30 ) ) {
V_20 -> V_30 = V_26 + V_93 * V_49 ;
F_1 ( V_72 , F_43 ( V_28 ) -> V_73 , * ( ( T_1 * ) V_34 -> V_71 ) ) ;
}
if ( V_20 -> V_21 -> V_43 . V_94 < V_95 )
F_7 ( & V_20 -> V_21 -> V_43 , V_9 ) ;
else {
F_22 ( V_9 ) ;
V_28 -> V_62 . V_90 ++ ;
}
goto V_96;
}
F_2 ( L_18 , V_20 , V_20 -> V_24 ) ;
F_29 ( V_9 ) -> V_40 = V_40 = V_20 -> V_24 -> V_40 ;
F_2 ( L_19 , V_34 , V_40 ) ;
if ( V_20 -> V_24 -> V_53 ) {
void * V_97 ;
V_97 = F_58 ( V_9 , V_55 ) ;
memcpy ( V_97 , V_57 , sizeof( V_57 ) ) ;
( ( V_60 * ) V_97 ) [ 3 ] = V_9 -> V_58 ;
}
F_59 ( V_9 -> V_15 , & F_6 ( V_40 ) -> V_98 ) ;
F_29 ( V_9 ) -> V_99 = V_40 -> V_99 ;
V_20 -> V_24 -> V_38 = V_26 ;
F_2 ( L_20 , V_9 , V_40 , V_40 -> V_28 ) ;
V_67 = F_45 ( & V_20 -> V_24 -> V_22 , 1 ) ;
if ( V_67 ) {
F_60 ( L_21 ) ;
goto V_96;
}
V_28 -> V_62 . V_100 ++ ;
V_28 -> V_62 . V_101 += V_9 -> V_54 ;
V_40 -> V_102 ( V_40 , V_9 ) ;
if ( F_44 ( V_40 , 0 ) ) {
V_20 -> V_24 -> V_22 = 0 ;
goto V_96;
}
F_42 ( & V_84 -> V_70 , V_68 ) ;
F_61 ( V_28 ) ;
F_62 () ;
if ( ! V_20 -> V_24 -> V_22 )
F_63 ( V_28 ) ;
F_46 ( & V_84 -> V_70 , V_68 ) ;
V_96:
F_64 ( V_34 ) ;
return V_91 ;
}
static int F_65 ( struct V_50 * V_40 , int V_103 )
{
struct V_18 * V_18 ;
if ( ! V_40 -> V_104 )
return - V_105 ;
V_18 = F_66 ( sizeof( struct V_18 ) , V_106 ) ;
if ( ! V_18 )
return - V_13 ;
F_2 ( L_22 , V_18 , V_40 ) ;
V_18 -> V_40 = V_40 ;
V_40 -> V_107 = V_18 ;
F_67 ( V_108 , & V_40 -> V_68 ) ;
V_18 -> V_20 = NULL ;
V_18 -> V_22 = 0 ;
V_18 -> V_53 = 1 ;
V_18 -> V_38 = V_26 ;
V_18 -> V_39 = V_103 * V_49 ;
V_18 -> V_51 = V_40 -> V_104 ;
V_18 -> V_69 = V_40 -> V_109 ;
V_40 -> V_104 = F_33 ;
V_40 -> V_109 = F_41 ;
F_68 ( V_40 ) ;
return 0 ;
}
static int F_69 ( struct V_50 * V_40 , T_1 V_3 )
{
struct V_33 * V_21 ;
struct V_19 * V_20 ;
int error ;
struct V_18 * V_18 ;
struct V_87 * V_88 ;
if ( V_40 -> V_104 != F_33 ) {
F_60 ( L_23 ) ;
return - V_110 ;
}
V_18 = F_32 ( V_40 ) ;
if ( ! V_3 ) {
if ( ! V_18 -> V_20 ) {
F_55 ( L_24 ) ;
return 0 ;
}
F_2 ( L_25 ) ;
F_9 ( V_18 ) ;
return 0 ;
}
V_88 = F_70 ( & V_111 , V_3 , 0 , 1 , 0 ) ;
if ( F_71 ( V_88 ) )
return F_72 ( V_88 ) ;
V_21 = F_73 ( & V_45 , & V_3 , V_88 -> V_86 . V_28 , 1 ) ;
F_74 ( V_88 ) ;
if ( ! V_21 )
return - V_13 ;
V_20 = F_16 ( V_21 ) ;
if ( V_20 != V_18 -> V_20 ) {
if ( ! V_18 -> V_20 )
F_2 ( L_26 ) ;
else {
F_2 ( L_27 ) ;
F_9 ( V_18 ) ;
}
F_8 ( V_18 , V_20 ) ;
}
error = F_13 ( V_21 , V_57 , V_112 ,
V_113 | V_32 ) ;
F_64 ( V_21 ) ;
return error ;
}
static void F_75 ( struct V_66 * V_28 )
{
V_28 -> V_114 = & V_115 ;
V_28 -> type = V_116 ;
V_28 -> V_117 = sizeof( struct V_19 ) ;
V_28 -> V_118 = V_55 ;
V_28 -> V_119 = V_120 ;
V_28 -> V_121 = 100 ;
F_76 ( V_28 ) ;
}
static int F_77 ( int V_73 )
{
struct V_66 * V_28 ;
struct V_84 * V_84 ;
int error ;
if ( V_73 != - 1 ) {
for ( V_28 = V_52 ; V_28 ; V_28 = F_43 ( V_28 ) -> V_23 )
if ( F_43 ( V_28 ) -> V_73 == V_73 )
return - V_122 ;
} else {
V_73 = 0 ;
for ( V_28 = V_52 ; V_28 ; V_28 = F_43 ( V_28 ) -> V_23 )
if ( F_43 ( V_28 ) -> V_73 >= V_73 )
V_73 = F_43 ( V_28 ) -> V_73 + 1 ;
}
V_28 = F_78 ( sizeof( struct V_84 ) , L_28 , V_123 ,
F_75 ) ;
if ( ! V_28 )
return - V_13 ;
V_84 = F_43 ( V_28 ) ;
sprintf ( V_28 -> V_124 , L_29 , V_73 ) ;
F_79 ( & V_84 -> V_70 ) ;
V_84 -> V_73 = V_73 ;
error = F_80 ( V_28 ) ;
if ( error ) {
F_81 ( V_28 ) ;
return error ;
}
V_84 -> V_23 = V_52 ;
V_52 = V_28 ;
F_2 ( L_30 , V_28 -> V_124 ) ;
return V_73 ;
}
static int F_82 ( struct V_125 * V_126 , unsigned long V_127 ,
void * V_128 )
{
struct V_66 * V_28 = F_83 ( V_128 ) ;
if ( ! F_84 ( F_85 ( V_28 ) , & V_111 ) )
return V_129 ;
if ( V_127 == V_130 )
return V_129 ;
if ( V_28 -> type != V_116 || V_28 -> V_114 != & V_115 )
return V_129 ;
switch ( V_127 ) {
case V_131 :
F_2 ( L_31 ) ;
F_1 ( V_132 , F_43 ( V_28 ) -> V_73 , 0 ) ;
break;
case V_133 :
F_2 ( L_32 ) ;
F_1 ( V_134 , F_43 ( V_28 ) -> V_73 , 0 ) ;
break;
case V_135 :
case V_136 :
F_2 ( L_33 ) ;
F_1 ( V_137 , F_43 ( V_28 ) -> V_73 , 0 ) ;
break;
}
return V_129 ;
}
static int F_86 ( struct V_125 * V_126 , unsigned long V_127 ,
void * V_138 )
{
struct V_139 * V_140 ;
struct V_141 V_142 ;
V_140 = ( (struct V_143 * ) V_138 ) -> V_144 ;
if ( V_127 != V_131 )
return V_129 ;
F_87 ( & V_142 , V_140 -> V_28 ) ;
return F_82 ( V_126 , V_135 , & V_142 ) ;
}
static void F_88 ( struct V_50 * V_40 )
{
F_2 ( L_9 ) ;
F_89 () ;
V_10 = NULL ;
F_90 ( & F_6 ( V_40 ) -> V_16 ) ;
F_91 () ;
F_2 ( L_34 ) ;
F_92 ( V_145 ) ;
}
static int F_93 ( struct V_50 * V_40 )
{
F_89 () ;
if ( V_10 ) {
F_91 () ;
return - V_146 ;
}
F_26 ( & V_47 , V_26 + V_48 * V_49 ) ;
V_10 = V_40 ;
F_67 ( V_147 , & V_40 -> V_68 ) ;
F_67 ( V_148 , & V_40 -> V_68 ) ;
V_40 -> V_28 = & V_149 ;
F_94 ( F_6 ( V_40 ) ) ;
V_40 -> V_104 = NULL ;
V_40 -> V_109 = NULL ;
V_40 -> V_150 = NULL ;
F_91 () ;
return 0 ;
}
static int F_95 ( struct V_151 * V_4 , unsigned int V_152 , unsigned long V_153 )
{
struct V_50 * V_40 = F_96 ( V_4 ) ;
int V_154 = 0 ;
switch ( V_152 ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
if ( ! F_97 ( V_160 ) )
return - V_161 ;
break;
default:
return - V_162 ;
}
switch ( V_152 ) {
case V_155 :
V_154 = F_77 ( V_153 ) ;
break;
case V_156 :
V_154 = F_93 ( V_40 ) ;
if ( ! V_154 ) {
V_4 -> V_163 = V_164 ;
F_98 ( V_145 ) ;
}
break;
case V_157 :
V_154 = F_65 ( V_40 , V_153 ) ;
break;
case V_158 :
V_154 = F_69 ( V_40 , ( V_165 T_1 ) V_153 ) ;
break;
case V_159 :
V_154 = F_52 ( V_40 , V_153 ) ;
break;
}
return V_154 ;
}
static void F_99 ( struct V_166 * V_167 , struct V_168 * V_169 )
{
static int V_170 [] = { 1 , 2 , 10 , 6 , 1 , 0 } ;
static int V_171 [] = { 1 , 8 , 4 , 6 , 1 , 0 } ;
if ( * V_169 -> V_172 . V_173 ) {
F_100 ( V_167 , L_35 , V_169 -> V_172 . V_173 ) ;
if ( * V_169 -> V_172 . V_174 )
F_101 ( V_167 , '+' ) ;
} else if ( ! * V_169 -> V_172 . V_174 ) {
F_100 ( V_167 , L_35 , L_36 ) ;
return;
}
if ( * V_169 -> V_172 . V_174 ) {
unsigned char * V_174 = V_169 -> V_172 . V_174 ;
int * V_175 ;
int V_176 , V_177 ;
V_175 = * V_174 == V_178 ? V_171 : V_170 ;
for ( V_176 = 0 ; V_175 [ V_176 ] ; V_176 ++ ) {
for ( V_177 = V_175 [ V_176 ] ; V_177 ; V_177 -- )
F_100 ( V_167 , L_37 , * V_174 ++ ) ;
if ( V_175 [ V_176 + 1 ] )
F_101 ( V_167 , '.' ) ;
}
}
}
static void F_102 ( struct V_166 * V_167 , struct V_33 * V_34 ,
struct V_19 * V_20 , struct V_18 * V_18 )
{
struct V_66 * V_28 = V_34 -> V_28 ;
unsigned long exp ;
char V_179 [ 17 ] ;
int V_180 , V_181 , V_182 ;
V_180 = ( ( V_18 == V_183 ) ||
( F_6 ( V_18 -> V_40 ) -> V_184 == V_185 ) ) ;
V_181 = ( ( V_18 == V_183 ) || V_18 -> V_53 ) ;
if ( V_18 == V_183 )
exp = V_20 -> V_21 -> V_25 ;
else
exp = V_18 -> V_38 ;
exp = ( V_26 - exp ) / V_49 ;
F_100 ( V_167 , L_38 ,
V_28 -> V_124 , V_180 ? L_39 : L_40 , V_181 ? L_41 : L_42 , exp ) ;
V_182 = F_103 ( V_179 , sizeof( V_179 ) - 1 , L_43 , V_34 -> V_71 ) ;
while ( V_182 < 16 )
V_179 [ V_182 ++ ] = ' ' ;
V_179 [ V_182 ] = '\0' ;
F_100 ( V_167 , L_35 , V_179 ) ;
if ( V_18 == V_183 ) {
if ( F_19 ( V_26 , V_20 -> V_30 ) )
F_100 ( V_167 , L_44 ) ;
else
F_100 ( V_167 , L_45 ,
F_20 ( & V_20 -> V_21 -> V_42 ) ) ;
} else if ( ! V_180 ) {
F_100 ( V_167 , L_46 ,
V_18 -> V_40 -> V_28 -> V_73 ,
V_18 -> V_40 -> V_186 , V_18 -> V_40 -> V_187 ) ;
} else {
F_99 ( V_167 , & V_18 -> V_40 -> V_188 ) ;
F_101 ( V_167 , '\n' ) ;
}
}
static struct V_18 * F_104 ( struct V_19 * V_189 ,
struct V_18 * V_190 )
{
if ( ! V_190 ) {
V_190 = V_189 -> V_24 ;
if ( ! V_190 )
return V_183 ;
return V_190 ;
}
if ( V_190 == V_183 )
return NULL ;
V_190 = V_190 -> V_23 ;
return V_190 ;
}
static void * F_105 ( struct V_191 * V_163 ,
struct V_19 * V_189 , T_3 * V_192 )
{
struct V_18 * V_40 = V_163 -> V_40 ;
V_40 = F_104 ( V_189 , V_40 ) ;
if ( V_40 && V_192 != NULL ) {
while ( * V_192 ) {
V_40 = F_104 ( V_189 , V_40 ) ;
if ( ! V_40 )
break;
-- ( * V_192 ) ;
}
}
V_163 -> V_40 = V_40 ;
return V_40 ;
}
static void * F_106 ( struct V_193 * V_194 ,
struct V_33 * V_34 , T_3 * V_192 )
{
struct V_191 * V_163 = (struct V_191 * ) V_194 ;
if ( V_34 -> V_28 -> type != V_116 )
return NULL ;
return F_105 ( V_163 , F_16 ( V_34 ) , V_192 ) ;
}
static void * F_107 ( struct V_166 * V_167 , T_3 * V_192 )
{
struct V_191 * V_163 = V_167 -> V_195 ;
V_163 -> V_196 . V_197 = F_106 ;
return F_108 ( V_167 , V_192 , & V_45 , V_198 ) ;
}
static int F_109 ( struct V_166 * V_167 , void * V_199 )
{
static char V_200 [] =
L_47 ;
if ( V_199 == V_201 ) {
F_110 ( V_167 , V_200 ) ;
} else {
struct V_191 * V_163 = V_167 -> V_195 ;
struct V_18 * V_40 = V_163 -> V_40 ;
struct V_33 * V_34 = V_199 ;
F_102 ( V_167 , V_34 , F_16 ( V_34 ) , V_40 ) ;
}
return 0 ;
}
static int F_111 ( struct V_202 * V_202 , struct V_203 * V_203 )
{
return F_112 ( V_202 , V_203 , & V_204 ,
sizeof( struct V_191 ) ) ;
}
static int T_4 F_113 ( void )
{
F_114 ( & V_205 ) ;
F_115 ( & V_206 ) ;
F_116 ( & V_207 ) ;
F_117 ( & V_47 , F_23 , 0 ) ;
#ifdef F_118
{
struct V_208 * V_209 ;
V_209 = F_119 ( L_48 , V_210 , V_211 , & V_212 ) ;
if ( ! V_209 ) {
F_55 ( L_49 ) ;
F_120 () ;
return - V_13 ;
}
}
#endif
return 0 ;
}
static void F_120 ( void )
{
struct V_66 * V_28 , * V_23 ;
F_121 ( & V_207 ) ;
F_122 ( & V_206 ) ;
F_123 ( & V_205 ) ;
F_124 ( & V_47 ) ;
V_28 = V_52 ;
while ( V_28 ) {
V_23 = F_43 ( V_28 ) -> V_23 ;
F_125 ( V_28 ) ;
F_81 ( V_28 ) ;
V_28 = V_23 ;
}
}
static void T_5 F_126 ( void )
{
F_127 ( L_48 , V_211 ) ;
F_120 () ;
}
