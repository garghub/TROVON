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
struct V_87 * V_88 ;
T_1 * V_89 ;
int V_67 ;
unsigned long V_68 ;
F_2 ( L_15 , V_9 ) ;
if ( ! V_86 ) {
F_55 ( L_16 ) ;
F_22 ( V_9 ) ;
V_29 -> V_62 . V_90 ++ ;
return V_91 ;
}
V_88 = (struct V_87 * ) V_86 ;
if ( V_88 -> V_92 )
V_89 = & V_88 -> V_92 ;
else
V_89 = & F_56 ( V_9 ) -> V_89 ;
V_35 = F_57 ( V_86 , V_89 ) ;
if ( ! V_35 ) {
F_55 ( L_17 ) ;
F_22 ( V_9 ) ;
V_29 -> V_62 . V_90 ++ ;
return V_91 ;
}
V_21 = F_16 ( V_35 ) ;
if ( ! V_21 -> V_25 ) {
if ( F_17 ( V_27 , V_21 -> V_31 ) ) {
V_21 -> V_31 = V_27 + V_93 * V_50 ;
F_1 ( V_72 , F_43 ( V_29 ) -> V_73 , * ( ( T_1 * ) V_35 -> V_71 ) ) ;
}
if ( V_21 -> V_22 -> V_44 . V_94 < V_95 )
F_7 ( & V_21 -> V_22 -> V_44 , V_9 ) ;
else {
F_22 ( V_9 ) ;
V_29 -> V_62 . V_90 ++ ;
}
goto V_96;
}
F_2 ( L_18 , V_21 , V_21 -> V_25 ) ;
F_29 ( V_9 ) -> V_41 = V_41 = V_21 -> V_25 -> V_41 ;
F_2 ( L_19 , V_35 , V_41 ) ;
if ( V_21 -> V_25 -> V_54 ) {
void * V_97 ;
V_97 = F_58 ( V_9 , V_55 ) ;
memcpy ( V_97 , V_57 , sizeof( V_57 ) ) ;
( ( V_60 * ) V_97 ) [ 3 ] = V_9 -> V_58 ;
}
F_59 ( V_9 -> V_15 , & F_6 ( V_41 ) -> V_98 ) ;
F_29 ( V_9 ) -> V_99 = V_41 -> V_99 ;
V_21 -> V_25 -> V_39 = V_27 ;
F_2 ( L_20 , V_9 , V_41 , V_41 -> V_29 ) ;
V_67 = F_45 ( & V_21 -> V_25 -> V_23 , 1 ) ;
if ( V_67 ) {
F_60 ( L_21 ) ;
goto V_96;
}
V_29 -> V_62 . V_100 ++ ;
V_29 -> V_62 . V_101 += V_9 -> V_18 ;
V_41 -> V_102 ( V_41 , V_9 ) ;
if ( F_44 ( V_41 , 0 ) ) {
V_21 -> V_25 -> V_23 = 0 ;
goto V_96;
}
F_42 ( & V_84 -> V_70 , V_68 ) ;
F_61 ( V_29 ) ;
F_62 () ;
if ( ! V_21 -> V_25 -> V_23 )
F_63 ( V_29 ) ;
F_46 ( & V_84 -> V_70 , V_68 ) ;
V_96:
F_64 ( V_35 ) ;
return V_91 ;
}
static int F_65 ( struct V_51 * V_41 , int V_103 )
{
struct V_19 * V_19 ;
if ( ! V_41 -> V_104 )
return - V_105 ;
V_19 = F_66 ( sizeof( struct V_19 ) , V_106 ) ;
if ( ! V_19 )
return - V_13 ;
F_2 ( L_22 , V_19 , V_41 ) ;
V_19 -> V_41 = V_41 ;
V_41 -> V_107 = V_19 ;
F_67 ( V_108 , & V_41 -> V_68 ) ;
V_19 -> V_21 = NULL ;
V_19 -> V_23 = 0 ;
V_19 -> V_54 = 1 ;
V_19 -> V_39 = V_27 ;
V_19 -> V_40 = V_103 * V_50 ;
V_19 -> V_52 = V_41 -> V_104 ;
V_19 -> V_69 = V_41 -> V_109 ;
V_41 -> V_104 = F_33 ;
V_41 -> V_109 = F_41 ;
F_68 ( V_41 ) ;
return 0 ;
}
static int F_69 ( struct V_51 * V_41 , T_1 V_3 )
{
struct V_34 * V_22 ;
struct V_20 * V_21 ;
int error ;
struct V_19 * V_19 ;
struct V_87 * V_88 ;
if ( V_41 -> V_104 != F_33 ) {
F_60 ( L_23 ) ;
return - V_110 ;
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
V_88 = F_70 ( & V_111 , V_3 , 0 , 1 , 0 ) ;
if ( F_71 ( V_88 ) )
return F_72 ( V_88 ) ;
V_22 = F_73 ( & V_46 , & V_3 , V_88 -> V_86 . V_29 , 1 ) ;
F_74 ( V_88 ) ;
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
error = F_13 ( V_22 , V_57 , V_112 ,
V_113 | V_33 ) ;
F_64 ( V_22 ) ;
return error ;
}
static void F_75 ( struct V_66 * V_29 )
{
V_29 -> V_114 = & V_115 ;
V_29 -> type = V_116 ;
V_29 -> V_117 = sizeof( struct V_20 ) ;
V_29 -> V_118 = V_55 ;
V_29 -> V_119 = V_120 ;
V_29 -> V_121 = 100 ;
V_29 -> V_122 &= ~ V_123 ;
}
static int F_76 ( int V_73 )
{
struct V_66 * V_29 ;
struct V_84 * V_84 ;
int error ;
if ( V_73 != - 1 ) {
for ( V_29 = V_53 ; V_29 ; V_29 = F_43 ( V_29 ) -> V_24 )
if ( F_43 ( V_29 ) -> V_73 == V_73 )
return - V_124 ;
} else {
V_73 = 0 ;
for ( V_29 = V_53 ; V_29 ; V_29 = F_43 ( V_29 ) -> V_24 )
if ( F_43 ( V_29 ) -> V_73 >= V_73 )
V_73 = F_43 ( V_29 ) -> V_73 + 1 ;
}
V_29 = F_77 ( sizeof( struct V_84 ) , L_28 , F_75 ) ;
if ( ! V_29 )
return - V_13 ;
V_84 = F_43 ( V_29 ) ;
sprintf ( V_29 -> V_125 , L_29 , V_73 ) ;
F_78 ( & V_84 -> V_70 ) ;
V_84 -> V_73 = V_73 ;
error = F_79 ( V_29 ) ;
if ( error ) {
F_80 ( V_29 ) ;
return error ;
}
V_84 -> V_24 = V_53 ;
V_53 = V_29 ;
F_2 ( L_30 , V_29 -> V_125 ) ;
return V_73 ;
}
static int F_81 ( struct V_126 * V_127 , unsigned long V_128 ,
void * V_129 )
{
struct V_66 * V_29 = V_129 ;
if ( ! F_82 ( F_83 ( V_29 ) , & V_111 ) )
return V_130 ;
if ( V_128 == V_131 )
return V_130 ;
if ( V_29 -> type != V_116 || V_29 -> V_114 != & V_115 )
return V_130 ;
switch ( V_128 ) {
case V_132 :
F_2 ( L_31 ) ;
F_1 ( V_133 , F_43 ( V_29 ) -> V_73 , 0 ) ;
break;
case V_134 :
F_2 ( L_32 ) ;
F_1 ( V_135 , F_43 ( V_29 ) -> V_73 , 0 ) ;
break;
case V_136 :
case V_137 :
F_2 ( L_33 ) ;
F_1 ( V_138 , F_43 ( V_29 ) -> V_73 , 0 ) ;
break;
}
return V_130 ;
}
static int F_84 ( struct V_126 * V_127 , unsigned long V_128 ,
void * V_139 )
{
struct V_140 * V_141 ;
V_141 = ( (struct V_142 * ) V_139 ) -> V_143 ;
if ( V_128 != V_132 )
return V_130 ;
return F_81 ( V_127 , V_136 , V_141 -> V_29 ) ;
}
static void F_85 ( struct V_51 * V_41 )
{
F_2 ( L_9 ) ;
F_86 () ;
V_10 = NULL ;
F_87 ( & F_6 ( V_41 ) -> V_16 ) ;
F_88 () ;
F_2 ( L_34 ) ;
F_89 ( V_144 ) ;
}
static int F_90 ( struct V_51 * V_41 )
{
F_86 () ;
if ( V_10 ) {
F_88 () ;
return - V_145 ;
}
F_26 ( & V_48 , V_27 + V_49 * V_50 ) ;
V_10 = V_41 ;
F_67 ( V_146 , & V_41 -> V_68 ) ;
F_67 ( V_147 , & V_41 -> V_68 ) ;
V_41 -> V_29 = & V_148 ;
F_91 ( F_6 ( V_41 ) ) ;
V_41 -> V_104 = NULL ;
V_41 -> V_109 = NULL ;
V_41 -> V_149 = NULL ;
F_88 () ;
return 0 ;
}
static int F_92 ( struct V_150 * V_4 , unsigned int V_151 , unsigned long V_129 )
{
struct V_51 * V_41 = F_93 ( V_4 ) ;
int V_152 = 0 ;
switch ( V_151 ) {
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
if ( ! F_94 ( V_158 ) )
return - V_159 ;
break;
default:
return - V_160 ;
}
switch ( V_151 ) {
case V_153 :
V_152 = F_76 ( V_129 ) ;
break;
case V_154 :
V_152 = F_90 ( V_41 ) ;
if ( ! V_152 ) {
V_4 -> V_161 = V_162 ;
F_95 ( V_144 ) ;
}
break;
case V_155 :
V_152 = F_65 ( V_41 , V_129 ) ;
break;
case V_156 :
V_152 = F_69 ( V_41 , ( V_163 T_1 ) V_129 ) ;
break;
case V_157 :
V_152 = F_52 ( V_41 , V_129 ) ;
break;
}
return V_152 ;
}
static void F_96 ( struct V_164 * V_165 , struct V_166 * V_167 )
{
static int V_168 [] = { 1 , 2 , 10 , 6 , 1 , 0 } ;
static int V_169 [] = { 1 , 8 , 4 , 6 , 1 , 0 } ;
if ( * V_167 -> V_170 . V_171 ) {
F_97 ( V_165 , L_35 , V_167 -> V_170 . V_171 ) ;
if ( * V_167 -> V_170 . V_172 )
F_98 ( V_165 , '+' ) ;
} else if ( ! * V_167 -> V_170 . V_172 ) {
F_97 ( V_165 , L_35 , L_36 ) ;
return;
}
if ( * V_167 -> V_170 . V_172 ) {
unsigned char * V_172 = V_167 -> V_170 . V_172 ;
int * V_173 ;
int V_174 , V_175 ;
V_173 = * V_172 == V_176 ? V_169 : V_168 ;
for ( V_174 = 0 ; V_173 [ V_174 ] ; V_174 ++ ) {
for ( V_175 = V_173 [ V_174 ] ; V_175 ; V_175 -- )
F_97 ( V_165 , L_37 , * V_172 ++ ) ;
if ( V_173 [ V_174 + 1 ] )
F_98 ( V_165 , '.' ) ;
}
}
}
static void F_99 ( struct V_164 * V_165 , struct V_34 * V_35 ,
struct V_20 * V_21 , struct V_19 * V_19 )
{
struct V_66 * V_29 = V_35 -> V_29 ;
unsigned long exp ;
char V_177 [ 17 ] ;
int V_178 , V_179 , V_180 ;
V_178 = ( ( V_19 == V_181 ) ||
( F_6 ( V_19 -> V_41 ) -> V_182 == V_183 ) ) ;
V_179 = ( ( V_19 == V_181 ) || V_19 -> V_54 ) ;
if ( V_19 == V_181 )
exp = V_21 -> V_22 -> V_26 ;
else
exp = V_19 -> V_39 ;
exp = ( V_27 - exp ) / V_50 ;
F_97 ( V_165 , L_38 ,
V_29 -> V_125 , V_178 ? L_39 : L_40 , V_179 ? L_41 : L_42 , exp ) ;
V_180 = F_100 ( V_177 , sizeof( V_177 ) - 1 , L_43 , V_35 -> V_71 ) ;
while ( V_180 < 16 )
V_177 [ V_180 ++ ] = ' ' ;
V_177 [ V_180 ] = '\0' ;
F_97 ( V_165 , L_35 , V_177 ) ;
if ( V_19 == V_181 ) {
if ( F_19 ( V_27 , V_21 -> V_31 ) )
F_97 ( V_165 , L_44 ) ;
else
F_97 ( V_165 , L_45 ,
F_20 ( & V_21 -> V_22 -> V_43 ) ) ;
} else if ( ! V_178 ) {
F_97 ( V_165 , L_46 ,
V_19 -> V_41 -> V_29 -> V_73 ,
V_19 -> V_41 -> V_184 , V_19 -> V_41 -> V_185 ) ;
} else {
F_96 ( V_165 , & V_19 -> V_41 -> V_186 ) ;
F_98 ( V_165 , '\n' ) ;
}
}
static struct V_19 * F_101 ( struct V_20 * V_187 ,
struct V_19 * V_188 )
{
if ( ! V_188 ) {
V_188 = V_187 -> V_25 ;
if ( ! V_188 )
return V_181 ;
return V_188 ;
}
if ( V_188 == V_181 )
return NULL ;
V_188 = V_188 -> V_24 ;
return V_188 ;
}
static void * F_102 ( struct V_189 * V_161 ,
struct V_20 * V_187 , T_3 * V_190 )
{
struct V_19 * V_41 = V_161 -> V_41 ;
V_41 = F_101 ( V_187 , V_41 ) ;
if ( V_41 && V_190 != NULL ) {
while ( * V_190 ) {
V_41 = F_101 ( V_187 , V_41 ) ;
if ( ! V_41 )
break;
-- ( * V_190 ) ;
}
}
V_161 -> V_41 = V_41 ;
return V_41 ;
}
static void * F_103 ( struct V_191 * V_192 ,
struct V_34 * V_35 , T_3 * V_190 )
{
struct V_189 * V_161 = (struct V_189 * ) V_192 ;
if ( V_35 -> V_29 -> type != V_116 )
return NULL ;
return F_102 ( V_161 , F_16 ( V_35 ) , V_190 ) ;
}
static void * F_104 ( struct V_164 * V_165 , T_3 * V_190 )
{
struct V_189 * V_161 = V_165 -> V_193 ;
V_161 -> V_194 . V_195 = F_103 ;
return F_105 ( V_165 , V_190 , & V_46 , V_196 ) ;
}
static int F_106 ( struct V_164 * V_165 , void * V_197 )
{
static char V_198 [] =
L_47 ;
if ( V_197 == V_199 ) {
F_107 ( V_165 , V_198 ) ;
} else {
struct V_189 * V_161 = V_165 -> V_193 ;
struct V_19 * V_41 = V_161 -> V_41 ;
struct V_34 * V_35 = V_197 ;
F_99 ( V_165 , V_35 , F_16 ( V_35 ) , V_41 ) ;
}
return 0 ;
}
static int F_108 ( struct V_200 * V_200 , struct V_201 * V_201 )
{
return F_109 ( V_200 , V_201 , & V_202 ,
sizeof( struct V_189 ) ) ;
}
static int T_4 F_110 ( void )
{
F_111 ( & V_203 ) ;
F_112 ( & V_204 ) ;
F_113 ( & V_205 ) ;
F_114 ( & V_48 , F_23 , 0 ) ;
#ifdef F_115
{
struct V_206 * V_207 ;
V_207 = F_116 ( L_48 , V_208 , V_209 , & V_210 ) ;
if ( ! V_207 ) {
F_55 ( L_49 ) ;
F_117 () ;
return - V_13 ;
}
}
#endif
return 0 ;
}
static void F_117 ( void )
{
struct V_66 * V_29 , * V_24 ;
F_118 ( & V_205 ) ;
F_119 ( & V_204 ) ;
F_120 ( & V_203 ) ;
F_121 ( & V_48 ) ;
V_29 = V_53 ;
while ( V_29 ) {
V_24 = F_43 ( V_29 ) -> V_24 ;
F_122 ( V_29 ) ;
F_80 ( V_29 ) ;
V_29 = V_24 ;
}
}
static void T_5 F_123 ( void )
{
F_124 ( L_48 , V_209 ) ;
F_117 () ;
}
