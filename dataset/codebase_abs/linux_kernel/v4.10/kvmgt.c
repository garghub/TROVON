static inline bool F_1 ( unsigned long V_1 )
{
return ! ! ( V_1 & ~ 0xff ) ;
}
static struct V_2 * F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_9 . V_6 ;
struct V_2 * V_10 = NULL ;
while ( V_7 ) {
struct V_2 * V_11 = F_3 ( V_7 , struct V_2 , V_7 ) ;
if ( V_5 < V_11 -> V_5 )
V_7 = V_7 -> V_12 ;
else if ( V_5 > V_11 -> V_5 )
V_7 = V_7 -> V_13 ;
else {
V_10 = V_11 ;
goto V_14;
}
}
V_14:
return V_10 ;
}
static T_2 F_4 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_2 * V_15 ;
T_2 V_16 ;
F_5 ( & V_4 -> V_8 . V_17 ) ;
V_15 = F_2 ( V_4 , V_5 ) ;
V_16 = ( V_15 == NULL ) ? 0 : V_15 -> V_16 ;
F_6 ( & V_4 -> V_8 . V_17 ) ;
return V_16 ;
}
static void F_7 ( struct V_3 * V_4 , T_1 V_5 , T_2 V_16 )
{
struct V_2 * V_18 , * V_11 ;
struct V_6 * * V_19 = & V_4 -> V_8 . V_9 . V_6 , * V_20 = NULL ;
V_18 = F_8 ( sizeof( struct V_2 ) , V_21 ) ;
if ( ! V_18 )
return;
V_18 -> V_5 = V_5 ;
V_18 -> V_16 = V_16 ;
F_5 ( & V_4 -> V_8 . V_17 ) ;
while ( * V_19 ) {
V_20 = * V_19 ;
V_11 = F_3 ( V_20 , struct V_2 , V_7 ) ;
if ( V_5 == V_11 -> V_5 )
goto V_14;
else if ( V_5 < V_11 -> V_5 )
V_19 = & V_20 -> V_12 ;
else
V_19 = & V_20 -> V_13 ;
}
F_9 ( & V_18 -> V_7 , V_20 , V_19 ) ;
F_10 ( & V_18 -> V_7 , & V_4 -> V_8 . V_9 ) ;
F_6 ( & V_4 -> V_8 . V_17 ) ;
return;
V_14:
F_6 ( & V_4 -> V_8 . V_17 ) ;
F_11 ( V_18 ) ;
}
static void F_12 ( struct V_3 * V_4 ,
struct V_2 * V_15 )
{
F_13 ( & V_15 -> V_7 , & V_4 -> V_8 . V_9 ) ;
F_11 ( V_15 ) ;
}
static void F_14 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_22 * V_23 = F_15 ( V_4 -> V_8 . V_24 ) ;
struct V_2 * V_25 ;
unsigned long V_26 ;
int V_27 ;
F_5 ( & V_4 -> V_8 . V_17 ) ;
V_25 = F_2 ( V_4 , V_5 ) ;
if ( ! V_25 ) {
F_6 ( & V_4 -> V_8 . V_17 ) ;
return;
}
V_26 = V_5 ;
V_27 = F_16 ( V_23 , & V_26 , 1 ) ;
F_17 ( V_27 != 1 ) ;
F_12 ( V_4 , V_25 ) ;
F_6 ( & V_4 -> V_8 . V_17 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
V_4 -> V_8 . V_9 = V_28 ;
F_19 ( & V_4 -> V_8 . V_17 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_2 * V_29 ;
struct V_6 * V_7 = NULL ;
struct V_22 * V_23 = F_15 ( V_4 -> V_8 . V_24 ) ;
unsigned long V_5 ;
F_5 ( & V_4 -> V_8 . V_17 ) ;
while ( ( V_7 = F_21 ( & V_4 -> V_8 . V_9 ) ) ) {
V_29 = F_3 ( V_7 , struct V_2 , V_7 ) ;
V_5 = V_29 -> V_5 ;
F_16 ( V_23 , & V_5 , 1 ) ;
F_12 ( V_4 , V_29 ) ;
}
F_6 ( & V_4 -> V_8 . V_17 ) ;
}
static struct V_30 * F_22 ( struct V_31 * V_32 ,
const char * V_33 )
{
int V_34 ;
struct V_30 * V_35 ;
const char * V_36 = F_23 (
& V_32 -> V_37 -> V_38 . V_39 -> V_23 ) ;
for ( V_34 = 0 ; V_34 < V_32 -> V_40 ; V_34 ++ ) {
V_35 = & V_32 -> V_41 [ V_34 ] ;
if ( ! strncmp ( V_35 -> V_33 , V_33 + strlen ( V_36 ) + 1 ,
sizeof( V_35 -> V_33 ) ) )
return V_35 ;
}
return NULL ;
}
static T_3 F_24 ( struct V_42 * V_43 ,
struct V_22 * V_23 , char * V_44 )
{
struct V_30 * type ;
unsigned int V_45 = 0 ;
void * V_32 = F_25 ( V_23 ) -> V_32 ;
type = F_22 ( V_32 , F_26 ( V_43 ) ) ;
if ( ! type )
V_45 = 0 ;
else
V_45 = type -> V_46 ;
return sprintf ( V_44 , L_1 , V_45 ) ;
}
static T_3 F_27 ( struct V_42 * V_43 , struct V_22 * V_23 ,
char * V_44 )
{
return sprintf ( V_44 , L_2 , V_47 ) ;
}
static T_3 F_28 ( struct V_42 * V_43 , struct V_22 * V_23 ,
char * V_44 )
{
struct V_30 * type ;
void * V_32 = F_25 ( V_23 ) -> V_32 ;
type = F_22 ( V_32 , F_26 ( V_43 ) ) ;
if ( ! type )
return 0 ;
return sprintf ( V_44 , L_3
L_4 ,
F_29 ( type -> V_48 ) ,
F_29 ( type -> V_49 ) ,
type -> V_50 ) ;
}
static bool F_30 ( struct V_31 * V_32 )
{
int V_34 , V_51 ;
struct V_30 * type ;
struct V_52 * V_53 ;
for ( V_34 = 0 ; V_34 < V_32 -> V_40 ; V_34 ++ ) {
type = & V_32 -> V_41 [ V_34 ] ;
V_53 = F_8 ( sizeof( struct V_52 ) , V_21 ) ;
if ( F_17 ( ! V_53 ) )
goto V_54;
V_53 -> V_33 = type -> V_33 ;
V_53 -> V_55 = V_56 ;
V_57 [ V_34 ] = V_53 ;
}
return true ;
V_54:
for ( V_51 = 0 ; V_51 < V_34 ; V_51 ++ ) {
V_53 = V_57 [ V_51 ] ;
F_11 ( V_53 ) ;
}
return false ;
}
static void F_31 ( struct V_31 * V_32 )
{
int V_34 ;
struct V_52 * V_53 ;
for ( V_34 = 0 ; V_34 < V_32 -> V_40 ; V_34 ++ ) {
V_53 = V_57 [ V_34 ] ;
F_11 ( V_53 ) ;
}
}
static void F_32 ( struct V_58 * V_59 )
{
F_33 ( V_59 -> V_60 ) ;
}
static void F_34 ( struct V_58 * V_59 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_34 ;
F_35 (info->ptable, i, tmp, p, hnode) {
F_36 ( & V_62 -> V_65 ) ;
F_11 ( V_62 ) ;
}
}
static struct V_61 *
F_37 ( struct V_58 * V_59 , T_1 V_5 )
{
struct V_61 * V_62 , * V_66 = NULL ;
F_38 (info->ptable, p, hnode, gfn) {
if ( V_5 == V_62 -> V_5 ) {
V_66 = V_62 ;
break;
}
}
return V_66 ;
}
static bool F_39 ( struct V_58 * V_59 ,
T_1 V_5 )
{
struct V_61 * V_62 ;
V_62 = F_37 ( V_59 , V_5 ) ;
return ! ! V_62 ;
}
static void F_40 ( struct V_58 * V_59 , T_1 V_5 )
{
struct V_61 * V_62 ;
if ( F_39 ( V_59 , V_5 ) )
return;
V_62 = F_8 ( sizeof( struct V_61 ) , V_67 ) ;
if ( F_41 ( ! V_62 , L_5 , V_5 ) )
return;
V_62 -> V_5 = V_5 ;
F_42 ( V_59 -> V_60 , & V_62 -> V_65 , V_5 ) ;
}
static void F_43 ( struct V_58 * V_59 ,
T_1 V_5 )
{
struct V_61 * V_62 ;
V_62 = F_37 ( V_59 , V_5 ) ;
if ( V_62 ) {
F_36 ( & V_62 -> V_65 ) ;
F_11 ( V_62 ) ;
}
}
static int F_44 ( struct V_42 * V_43 , struct V_68 * V_24 )
{
struct V_3 * V_4 ;
struct V_30 * type ;
struct V_22 * V_39 ;
void * V_32 ;
int V_10 ;
V_39 = F_45 ( V_24 ) ;
V_32 = F_25 ( V_39 ) -> V_32 ;
type = F_22 ( V_32 , F_26 ( V_43 ) ) ;
if ( ! type ) {
F_46 ( L_6 ,
F_26 ( V_43 ) ) ;
V_10 = - V_69 ;
goto V_14;
}
V_4 = V_70 -> V_71 ( V_32 , type ) ;
if ( F_47 ( V_4 ) ) {
V_10 = V_4 == NULL ? - V_72 : F_48 ( V_4 ) ;
F_46 ( L_7 , V_10 ) ;
goto V_14;
}
F_49 ( & V_4 -> V_8 . V_73 , V_74 ) ;
V_4 -> V_8 . V_24 = V_24 ;
F_50 ( V_24 , V_4 ) ;
F_51 ( L_8 ,
F_52 ( F_15 ( V_24 ) ) ) ;
V_10 = 0 ;
V_14:
return V_10 ;
}
static int F_53 ( struct V_68 * V_24 )
{
struct V_3 * V_4 = F_54 ( V_24 ) ;
if ( F_1 ( V_4 -> V_1 ) )
return - V_75 ;
V_70 -> V_76 ( V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
struct V_3 * V_4 = F_56 ( V_78 ,
struct V_3 ,
V_8 . V_81 ) ;
if ( V_79 == V_82 ) {
struct V_83 * V_84 = V_80 ;
unsigned long V_5 , V_85 ;
V_5 = V_84 -> V_86 >> V_87 ;
V_85 = V_5 + V_84 -> V_88 / V_89 ;
while ( V_5 < V_85 )
F_14 ( V_4 , V_5 ++ ) ;
}
return V_90 ;
}
static int F_57 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
struct V_3 * V_4 = F_56 ( V_78 ,
struct V_3 ,
V_8 . V_91 ) ;
if ( V_79 == V_92 ) {
V_4 -> V_8 . V_93 = V_80 ;
if ( ! V_80 )
F_58 ( & V_4 -> V_8 . V_73 ) ;
}
return V_90 ;
}
static int F_59 ( struct V_68 * V_24 )
{
struct V_3 * V_4 = F_54 ( V_24 ) ;
unsigned long V_94 ;
int V_10 ;
V_4 -> V_8 . V_81 . V_95 = F_55 ;
V_4 -> V_8 . V_91 . V_95 = F_57 ;
V_94 = V_82 ;
V_10 = F_60 ( F_15 ( V_24 ) , V_96 , & V_94 ,
& V_4 -> V_8 . V_81 ) ;
if ( V_10 != 0 ) {
F_46 ( L_9 , V_10 ) ;
goto V_14;
}
V_94 = V_92 ;
V_10 = F_60 ( F_15 ( V_24 ) , V_97 , & V_94 ,
& V_4 -> V_8 . V_91 ) ;
if ( V_10 != 0 ) {
F_46 ( L_10 , V_10 ) ;
goto V_98;
}
V_10 = F_61 ( V_24 ) ;
if ( V_10 )
goto V_99;
F_62 ( & V_4 -> V_8 . V_100 , 0 ) ;
return V_10 ;
V_99:
F_63 ( F_15 ( V_24 ) , V_97 ,
& V_4 -> V_8 . V_91 ) ;
V_98:
F_63 ( F_15 ( V_24 ) , V_96 ,
& V_4 -> V_8 . V_81 ) ;
V_14:
return V_10 ;
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_58 * V_59 ;
int V_10 ;
if ( ! F_1 ( V_4 -> V_1 ) )
return;
if ( F_65 ( & V_4 -> V_8 . V_100 , 0 , 1 ) )
return;
V_10 = F_63 ( F_15 ( V_4 -> V_8 . V_24 ) , V_96 ,
& V_4 -> V_8 . V_81 ) ;
F_41 ( V_10 , L_11 , V_10 ) ;
V_10 = F_63 ( F_15 ( V_4 -> V_8 . V_24 ) , V_97 ,
& V_4 -> V_8 . V_91 ) ;
F_41 ( V_10 , L_12 , V_10 ) ;
V_59 = (struct V_58 * ) V_4 -> V_1 ;
F_66 ( V_59 ) ;
V_4 -> V_8 . V_93 = NULL ;
V_4 -> V_1 = 0 ;
}
static void F_67 ( struct V_68 * V_24 )
{
struct V_3 * V_4 = F_54 ( V_24 ) ;
F_64 ( V_4 ) ;
}
static void V_74 ( struct V_101 * V_102 )
{
struct V_3 * V_4 = F_56 ( V_102 , struct V_3 ,
V_8 . V_73 ) ;
F_64 ( V_4 ) ;
}
static T_4 F_68 ( struct V_3 * V_4 )
{
T_5 V_103 , V_104 ;
T_5 V_105 ;
int V_106 = V_107 ;
V_103 = ( * ( T_5 * ) ( V_4 -> V_108 . V_109 + V_106 ) ) &
V_110 ;
V_105 = ( * ( T_5 * ) ( V_4 -> V_108 . V_109 + V_106 ) ) &
V_111 ;
switch ( V_105 ) {
case V_112 :
V_104 = ( * ( T_5 * ) ( V_4 -> V_108 . V_109
+ V_106 + 4 ) ) ;
break;
case V_113 :
case V_114 :
default:
V_104 = 0 ;
break;
}
return ( ( V_115 ) V_104 << 32 ) | V_103 ;
}
static T_3 F_69 ( struct V_68 * V_24 , char * V_44 ,
T_6 V_116 , T_7 * V_117 , bool V_118 )
{
struct V_3 * V_4 = F_54 ( V_24 ) ;
unsigned int V_119 = F_70 ( * V_117 ) ;
T_4 V_106 = * V_117 & V_120 ;
int V_10 = - V_69 ;
if ( V_119 >= V_121 ) {
F_46 ( L_13 , V_119 ) ;
return - V_69 ;
}
switch ( V_119 ) {
case V_122 :
if ( V_118 )
V_10 = V_70 -> V_123 ( V_4 , V_106 ,
V_44 , V_116 ) ;
else
V_10 = V_70 -> V_124 ( V_4 , V_106 ,
V_44 , V_116 ) ;
break;
case V_125 :
case V_126 :
if ( V_118 ) {
T_4 V_127 = F_68 ( V_4 ) ;
V_10 = V_70 -> V_128 ( V_4 ,
V_127 + V_106 , V_44 , V_116 ) ;
} else {
T_4 V_127 = F_68 ( V_4 ) ;
V_10 = V_70 -> V_129 ( V_4 ,
V_127 + V_106 , V_44 , V_116 ) ;
}
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
default:
F_46 ( L_14 , V_119 ) ;
}
return V_10 == 0 ? V_116 : V_10 ;
}
static T_3 F_71 ( struct V_68 * V_24 , char T_8 * V_44 ,
T_6 V_116 , T_7 * V_117 )
{
unsigned int V_136 = 0 ;
int V_10 ;
while ( V_116 ) {
T_6 V_137 ;
if ( V_116 >= 4 && ! ( * V_117 % 4 ) ) {
T_5 V_138 ;
V_10 = F_69 ( V_24 , ( char * ) & V_138 , sizeof( V_138 ) ,
V_117 , false ) ;
if ( V_10 <= 0 )
goto V_139;
if ( F_72 ( V_44 , & V_138 , sizeof( V_138 ) ) )
goto V_139;
V_137 = 4 ;
} else if ( V_116 >= 2 && ! ( * V_117 % 2 ) ) {
T_9 V_138 ;
V_10 = F_69 ( V_24 , ( char * ) & V_138 , sizeof( V_138 ) ,
V_117 , false ) ;
if ( V_10 <= 0 )
goto V_139;
if ( F_72 ( V_44 , & V_138 , sizeof( V_138 ) ) )
goto V_139;
V_137 = 2 ;
} else {
T_10 V_138 ;
V_10 = F_69 ( V_24 , & V_138 , sizeof( V_138 ) , V_117 ,
false ) ;
if ( V_10 <= 0 )
goto V_139;
if ( F_72 ( V_44 , & V_138 , sizeof( V_138 ) ) )
goto V_139;
V_137 = 1 ;
}
V_116 -= V_137 ;
V_136 += V_137 ;
* V_117 += V_137 ;
V_44 += V_137 ;
}
return V_136 ;
V_139:
return - V_72 ;
}
static T_3 F_73 ( struct V_68 * V_24 ,
const char T_8 * V_44 ,
T_6 V_116 , T_7 * V_117 )
{
unsigned int V_136 = 0 ;
int V_10 ;
while ( V_116 ) {
T_6 V_137 ;
if ( V_116 >= 4 && ! ( * V_117 % 4 ) ) {
T_5 V_138 ;
if ( F_74 ( & V_138 , V_44 , sizeof( V_138 ) ) )
goto V_140;
V_10 = F_69 ( V_24 , ( char * ) & V_138 , sizeof( V_138 ) ,
V_117 , true ) ;
if ( V_10 <= 0 )
goto V_140;
V_137 = 4 ;
} else if ( V_116 >= 2 && ! ( * V_117 % 2 ) ) {
T_9 V_138 ;
if ( F_74 ( & V_138 , V_44 , sizeof( V_138 ) ) )
goto V_140;
V_10 = F_69 ( V_24 , ( char * ) & V_138 ,
sizeof( V_138 ) , V_117 , true ) ;
if ( V_10 <= 0 )
goto V_140;
V_137 = 2 ;
} else {
T_10 V_138 ;
if ( F_74 ( & V_138 , V_44 , sizeof( V_138 ) ) )
goto V_140;
V_10 = F_69 ( V_24 , & V_138 , sizeof( V_138 ) ,
V_117 , true ) ;
if ( V_10 <= 0 )
goto V_140;
V_137 = 1 ;
}
V_116 -= V_137 ;
V_136 += V_137 ;
* V_117 += V_137 ;
V_44 += V_137 ;
}
return V_136 ;
V_140:
return - V_72 ;
}
static int F_75 ( struct V_68 * V_24 , struct V_141 * V_142 )
{
unsigned int V_119 ;
V_115 V_143 ;
unsigned long V_144 , V_145 = 0 ;
T_11 V_146 ;
struct V_3 * V_4 = F_54 ( V_24 ) ;
V_119 = V_142 -> V_147 >> ( V_148 - V_87 ) ;
if ( V_119 >= V_135 )
return - V_69 ;
if ( V_142 -> V_149 < V_142 -> V_150 )
return - V_69 ;
if ( ( V_142 -> V_151 & V_152 ) == 0 )
return - V_69 ;
if ( V_119 != V_130 )
return - V_69 ;
V_146 = V_142 -> V_153 ;
V_143 = V_142 -> V_150 ;
V_144 = V_142 -> V_149 - V_142 -> V_150 ;
V_145 = F_76 ( V_4 ) >> V_87 ;
return F_77 ( V_142 , V_143 , V_145 , V_144 , V_146 ) ;
}
static int F_78 ( struct V_3 * V_4 , int type )
{
if ( type == V_154 || type == V_155 )
return 1 ;
return 0 ;
}
static int F_79 ( struct V_3 * V_4 ,
unsigned int V_119 , unsigned int V_156 ,
unsigned int V_116 , T_12 V_157 ,
void * V_80 )
{
return 0 ;
}
static int F_80 ( struct V_3 * V_4 ,
unsigned int V_119 , unsigned int V_156 ,
unsigned int V_116 , T_12 V_157 , void * V_80 )
{
return 0 ;
}
static int F_81 ( struct V_3 * V_4 ,
unsigned int V_119 , unsigned int V_156 , unsigned int V_116 ,
T_12 V_157 , void * V_80 )
{
return 0 ;
}
static int F_82 ( struct V_3 * V_4 ,
unsigned int V_119 , unsigned int V_156 , unsigned int V_116 ,
T_12 V_157 , void * V_80 )
{
struct V_158 * V_159 ;
if ( V_157 & V_160 ) {
int V_161 = * ( int * ) V_80 ;
V_159 = F_83 ( V_161 ) ;
if ( F_84 ( V_159 ) ) {
F_46 ( L_15 ) ;
return F_48 ( V_159 ) ;
}
V_4 -> V_8 . V_162 = V_159 ;
}
return 0 ;
}
static int F_85 ( struct V_3 * V_4 , T_12 V_157 ,
unsigned int V_119 , unsigned int V_156 , unsigned int V_116 ,
void * V_80 )
{
int (* F_86)( struct V_3 * V_4 , unsigned int V_119 ,
unsigned int V_156 , unsigned int V_116 , T_12 V_157 ,
void * V_80 ) = NULL ;
switch ( V_119 ) {
case V_154 :
switch ( V_157 & V_163 ) {
case V_164 :
F_86 = F_79 ;
break;
case V_165 :
F_86 = F_80 ;
break;
case V_166 :
F_86 = F_81 ;
break;
}
break;
case V_155 :
switch ( V_157 & V_163 ) {
case V_164 :
case V_165 :
break;
case V_166 :
F_86 = F_82 ;
break;
}
break;
}
if ( ! F_86 )
return - V_167 ;
return F_86 ( V_4 , V_119 , V_156 , V_116 , V_157 , V_80 ) ;
}
static long F_87 ( struct V_68 * V_24 , unsigned int V_168 ,
unsigned long V_169 )
{
struct V_3 * V_4 = F_54 ( V_24 ) ;
unsigned long V_170 ;
F_51 ( L_16 , V_4 -> V_171 , V_168 ) ;
if ( V_168 == V_172 ) {
struct V_173 V_59 ;
V_170 = F_88 ( struct V_173 , V_174 ) ;
if ( F_74 ( & V_59 , ( void T_8 * ) V_169 , V_170 ) )
return - V_72 ;
if ( V_59 . V_175 < V_170 )
return - V_69 ;
V_59 . V_157 = V_176 ;
V_59 . V_157 |= V_177 ;
V_59 . V_178 = V_121 ;
V_59 . V_174 = V_179 ;
return F_72 ( ( void T_8 * ) V_169 , & V_59 , V_170 ) ?
- V_72 : 0 ;
} else if ( V_168 == V_180 ) {
struct V_181 V_59 ;
struct V_182 V_183 = { . V_44 = NULL , . V_88 = 0 } ;
int V_34 , V_10 ;
struct V_184 * V_185 = NULL ;
T_6 V_88 ;
int V_186 = 1 ;
int V_187 ;
V_170 = F_88 ( struct V_181 , V_188 ) ;
if ( F_74 ( & V_59 , ( void T_8 * ) V_169 , V_170 ) )
return - V_72 ;
if ( V_59 . V_175 < V_170 )
return - V_69 ;
switch ( V_59 . V_119 ) {
case V_122 :
V_59 . V_188 = F_89 ( V_59 . V_119 ) ;
V_59 . V_88 = V_189 ;
V_59 . V_157 = V_190 |
V_191 ;
break;
case V_125 :
V_59 . V_188 = F_89 ( V_59 . V_119 ) ;
V_59 . V_88 = V_4 -> V_108 . V_192 [ V_59 . V_119 ] . V_88 ;
if ( ! V_59 . V_88 ) {
V_59 . V_157 = 0 ;
break;
}
V_59 . V_157 = V_190 |
V_191 ;
break;
case V_126 :
V_59 . V_188 = F_89 ( V_59 . V_119 ) ;
V_59 . V_88 = 0 ;
V_59 . V_157 = 0 ;
break;
case V_130 :
V_59 . V_188 = F_89 ( V_59 . V_119 ) ;
V_59 . V_157 = V_193 |
V_194 |
V_190 |
V_191 ;
V_59 . V_88 = F_90 ( V_4 -> V_32 ) ;
V_88 = sizeof( * V_185 ) +
( V_186 * sizeof( * V_185 -> V_195 ) ) ;
V_185 = F_8 ( V_88 , V_21 ) ;
if ( ! V_185 )
return - V_196 ;
V_185 -> V_186 = V_186 ;
V_187 = V_197 ;
V_185 -> V_195 [ 0 ] . V_188 =
F_91 ( F_92 ( V_4 ) ) ;
V_185 -> V_195 [ 0 ] . V_88 = F_93 ( V_4 ) ;
if ( ! V_183 . V_44 ) {
F_11 ( V_183 . V_44 ) ;
V_183 . V_44 = NULL ;
V_183 . V_88 = 0 ;
}
break;
case V_131 ... V_133 :
V_59 . V_188 = F_89 ( V_59 . V_119 ) ;
V_59 . V_88 = 0 ;
V_59 . V_157 = 0 ;
F_51 ( L_17 , V_59 . V_119 ) ;
break;
case V_135 :
case V_134 :
F_51 ( L_18 , V_59 . V_119 ) ;
break;
default:
{
struct V_198 V_199 ;
if ( V_59 . V_119 >= V_121 +
V_4 -> V_8 . V_178 )
return - V_69 ;
V_34 = V_59 . V_119 - V_121 ;
V_59 . V_188 =
F_89 ( V_59 . V_119 ) ;
V_59 . V_88 = V_4 -> V_8 . V_200 [ V_34 ] . V_88 ;
V_59 . V_157 = V_4 -> V_8 . V_200 [ V_34 ] . V_157 ;
V_199 . type = V_4 -> V_8 . V_200 [ V_34 ] . type ;
V_199 . V_201 = V_4 -> V_8 . V_200 [ V_34 ] . V_201 ;
V_10 = F_94 ( & V_183 ,
V_202 ,
& V_199 ) ;
if ( V_10 )
return V_10 ;
}
}
if ( ( V_59 . V_157 & V_193 ) && V_185 ) {
switch ( V_187 ) {
case V_197 :
V_10 = F_94 ( & V_183 ,
V_197 ,
V_185 ) ;
F_11 ( V_185 ) ;
if ( V_10 )
return V_10 ;
break;
default:
return - V_69 ;
}
}
if ( V_183 . V_88 ) {
if ( V_59 . V_175 < sizeof( V_59 ) + V_183 . V_88 ) {
V_59 . V_175 = sizeof( V_59 ) + V_183 . V_88 ;
V_59 . V_203 = 0 ;
} else {
F_95 ( & V_183 , sizeof( V_59 ) ) ;
if ( F_72 ( ( void T_8 * ) V_169 +
sizeof( V_59 ) , V_183 . V_44 ,
V_183 . V_88 ) ) {
F_11 ( V_183 . V_44 ) ;
return - V_72 ;
}
V_59 . V_203 = sizeof( V_59 ) ;
}
F_11 ( V_183 . V_44 ) ;
}
return F_72 ( ( void T_8 * ) V_169 , & V_59 , V_170 ) ?
- V_72 : 0 ;
} else if ( V_168 == V_204 ) {
struct V_205 V_59 ;
V_170 = F_88 ( struct V_205 , V_116 ) ;
if ( F_74 ( & V_59 , ( void T_8 * ) V_169 , V_170 ) )
return - V_72 ;
if ( V_59 . V_175 < V_170 || V_59 . V_119 >= V_179 )
return - V_69 ;
switch ( V_59 . V_119 ) {
case V_154 :
case V_155 :
break;
default:
return - V_69 ;
}
V_59 . V_157 = V_206 ;
V_59 . V_116 = F_78 ( V_4 , V_59 . V_119 ) ;
if ( V_59 . V_119 == V_154 )
V_59 . V_157 |= ( V_207 |
V_208 ) ;
else
V_59 . V_157 |= V_209 ;
return F_72 ( ( void T_8 * ) V_169 , & V_59 , V_170 ) ?
- V_72 : 0 ;
} else if ( V_168 == V_210 ) {
struct V_211 V_212 ;
T_10 * V_80 = NULL ;
int V_10 = 0 ;
T_6 V_213 = 0 ;
V_170 = F_88 ( struct V_211 , V_116 ) ;
if ( F_74 ( & V_212 , ( void T_8 * ) V_169 , V_170 ) )
return - V_72 ;
if ( ! ( V_212 . V_157 & V_214 ) ) {
int V_215 = F_78 ( V_4 , V_212 . V_119 ) ;
V_10 = F_96 ( & V_212 , V_215 ,
V_179 , & V_213 ) ;
if ( V_10 ) {
F_46 ( L_19 ) ;
return - V_69 ;
}
if ( V_213 ) {
V_80 = F_97 ( ( void T_8 * ) ( V_169 + V_170 ) ,
V_213 ) ;
if ( F_84 ( V_80 ) )
return F_48 ( V_80 ) ;
}
}
V_10 = F_85 ( V_4 , V_212 . V_157 , V_212 . V_119 ,
V_212 . V_156 , V_212 . V_116 , V_80 ) ;
F_11 ( V_80 ) ;
return V_10 ;
} else if ( V_168 == V_216 ) {
V_70 -> V_217 ( V_4 ) ;
return 0 ;
}
return 0 ;
}
static int F_98 ( struct V_22 * V_23 , void * V_32 , const void * V_218 )
{
if ( ! F_30 ( V_32 ) )
return - V_72 ;
V_70 = V_218 ;
return F_99 ( V_23 , & V_219 ) ;
}
static void F_100 ( struct V_22 * V_23 , void * V_32 )
{
F_31 ( V_32 ) ;
F_101 ( V_23 ) ;
}
static int F_102 ( unsigned long V_1 , V_115 V_5 )
{
struct V_58 * V_59 ;
struct V_93 * V_93 ;
struct V_220 * V_221 ;
int V_222 ;
if ( ! F_1 ( V_1 ) )
return - V_223 ;
V_59 = (struct V_58 * ) V_1 ;
V_93 = V_59 -> V_93 ;
V_222 = F_103 ( & V_93 -> V_224 ) ;
V_221 = F_104 ( V_93 , V_5 ) ;
if ( ! V_221 ) {
F_105 ( & V_93 -> V_224 , V_222 ) ;
return - V_69 ;
}
F_106 ( & V_93 -> V_225 ) ;
if ( F_39 ( V_59 , V_5 ) )
goto V_14;
F_107 ( V_93 , V_221 , V_5 , V_226 ) ;
F_40 ( V_59 , V_5 ) ;
V_14:
F_108 ( & V_93 -> V_225 ) ;
F_105 ( & V_93 -> V_224 , V_222 ) ;
return 0 ;
}
static int F_109 ( unsigned long V_1 , V_115 V_5 )
{
struct V_58 * V_59 ;
struct V_93 * V_93 ;
struct V_220 * V_221 ;
int V_222 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
V_59 = (struct V_58 * ) V_1 ;
V_93 = V_59 -> V_93 ;
V_222 = F_103 ( & V_93 -> V_224 ) ;
V_221 = F_104 ( V_93 , V_5 ) ;
if ( ! V_221 ) {
F_105 ( & V_93 -> V_224 , V_222 ) ;
return - V_69 ;
}
F_106 ( & V_93 -> V_225 ) ;
if ( ! F_39 ( V_59 , V_5 ) )
goto V_14;
F_110 ( V_93 , V_221 , V_5 , V_226 ) ;
F_43 ( V_59 , V_5 ) ;
V_14:
F_108 ( & V_93 -> V_225 ) ;
F_105 ( & V_93 -> V_224 , V_222 ) ;
return 0 ;
}
static void F_111 ( struct V_227 * V_228 , T_13 V_229 ,
const T_10 * V_138 , int V_230 ,
struct V_231 * V_7 )
{
struct V_58 * V_59 = F_56 ( V_7 ,
struct V_58 , V_232 ) ;
if ( F_39 ( V_59 , F_112 ( V_229 ) ) )
V_70 -> V_128 ( V_59 -> V_4 , V_229 ,
( void * ) V_138 , V_230 ) ;
}
static void F_113 ( struct V_93 * V_93 ,
struct V_220 * V_221 ,
struct V_231 * V_7 )
{
int V_34 ;
T_1 V_5 ;
struct V_58 * V_59 = F_56 ( V_7 ,
struct V_58 , V_232 ) ;
F_106 ( & V_93 -> V_225 ) ;
for ( V_34 = 0 ; V_34 < V_221 -> V_233 ; V_34 ++ ) {
V_5 = V_221 -> V_234 + V_34 ;
if ( F_39 ( V_59 , V_5 ) ) {
F_110 ( V_93 , V_221 , V_5 ,
V_226 ) ;
F_43 ( V_59 , V_5 ) ;
}
}
F_108 ( & V_93 -> V_225 ) ;
}
static bool F_114 ( void )
{
unsigned int V_235 , V_236 , V_237 , V_238 ;
char V_239 [ 12 ] ;
unsigned int * V_34 ;
V_235 = V_240 ;
V_236 = V_237 = V_238 = 0 ;
asm volatile ("cpuid"
: "+a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
:
: "cc", "memory");
V_34 = ( unsigned int * ) V_239 ;
V_34 [ 0 ] = V_236 ;
V_34 [ 1 ] = V_237 ;
V_34 [ 2 ] = V_238 ;
return ! strncmp ( V_239 , L_20 , strlen ( L_20 ) ) ;
}
static int F_115 ( void )
{
#ifdef F_116
if ( V_241 ) {
F_46 ( L_21 ) ;
return - V_242 ;
}
#endif
return F_114 () ? - V_242 : 0 ;
}
static bool F_117 ( struct V_3 * V_4 , struct V_93 * V_93 )
{
struct V_3 * V_11 ;
struct V_58 * V_59 ;
int V_171 ;
bool V_10 = false ;
F_5 ( & V_4 -> V_32 -> V_243 ) ;
F_118 (vgpu->gvt, itr, id) {
if ( ! F_1 ( V_11 -> V_1 ) )
continue;
V_59 = (struct V_58 * ) V_11 -> V_1 ;
if ( V_93 && V_93 == V_59 -> V_93 ) {
V_10 = true ;
goto V_14;
}
}
V_14:
F_6 ( & V_4 -> V_32 -> V_243 ) ;
return V_10 ;
}
static int F_61 ( struct V_68 * V_24 )
{
struct V_58 * V_59 ;
struct V_3 * V_4 ;
struct V_93 * V_93 ;
V_4 = F_54 ( V_24 ) ;
if ( F_1 ( V_4 -> V_1 ) )
return - V_244 ;
V_93 = V_4 -> V_8 . V_93 ;
if ( ! V_93 || V_93 -> V_245 != V_246 -> V_245 ) {
F_46 ( L_22 ) ;
return - V_223 ;
}
if ( F_117 ( V_4 , V_93 ) )
return - V_244 ;
V_59 = F_119 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 )
return - V_196 ;
V_4 -> V_1 = ( unsigned long ) V_59 ;
V_59 -> V_4 = V_4 ;
V_59 -> V_93 = V_93 ;
F_32 ( V_59 ) ;
F_18 ( V_4 ) ;
V_59 -> V_232 . V_247 = F_111 ;
V_59 -> V_232 . V_248 = F_113 ;
F_120 ( V_93 , & V_59 -> V_232 ) ;
return 0 ;
}
static bool F_66 ( struct V_58 * V_59 )
{
if ( ! V_59 ) {
F_46 ( L_23 ) ;
return false ;
}
F_121 ( V_59 -> V_93 , & V_59 -> V_232 ) ;
F_34 ( V_59 ) ;
F_20 ( V_59 -> V_4 ) ;
F_122 ( V_59 ) ;
return true ;
}
static int F_123 ( void * V_4 , unsigned long * V_1 )
{
return 0 ;
}
static void F_124 ( unsigned long V_1 )
{
}
static int F_125 ( unsigned long V_1 , T_5 V_249 , T_9 V_80 )
{
struct V_58 * V_59 ;
struct V_3 * V_4 ;
if ( ! F_1 ( V_1 ) )
return - V_223 ;
V_59 = (struct V_58 * ) V_1 ;
V_4 = V_59 -> V_4 ;
if ( F_126 ( V_4 -> V_8 . V_162 , 1 ) == 1 )
return 0 ;
return - V_72 ;
}
static unsigned long F_127 ( unsigned long V_1 , unsigned long V_5 )
{
unsigned long V_16 ;
struct V_58 * V_59 ;
struct V_22 * V_23 ;
int V_27 ;
if ( ! F_1 ( V_1 ) )
return V_250 ;
V_59 = (struct V_58 * ) V_1 ;
V_16 = F_4 ( V_59 -> V_4 , V_5 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = V_250 ;
V_23 = F_15 ( V_59 -> V_4 -> V_8 . V_24 ) ;
V_27 = F_128 ( V_23 , & V_5 , 1 , V_251 | V_252 , & V_16 ) ;
if ( V_27 != 1 ) {
F_46 ( L_24 , V_5 , V_27 ) ;
return V_250 ;
}
F_7 ( V_59 -> V_4 , V_5 , V_16 ) ;
return V_16 ;
}
static int F_129 ( unsigned long V_1 , unsigned long V_229 ,
void * V_44 , unsigned long V_230 , bool V_253 )
{
struct V_58 * V_59 ;
struct V_93 * V_93 ;
int V_10 ;
bool V_254 = V_246 -> V_245 == NULL ;
if ( ! F_1 ( V_1 ) )
return - V_223 ;
V_59 = (struct V_58 * ) V_1 ;
V_93 = V_59 -> V_93 ;
if ( V_254 )
F_130 ( V_93 -> V_245 ) ;
V_10 = V_253 ? F_131 ( V_93 , V_229 , V_44 , V_230 ) :
F_132 ( V_93 , V_229 , V_44 , V_230 ) ;
if ( V_254 )
F_133 ( V_93 -> V_245 ) ;
return V_10 ;
}
static int F_134 ( unsigned long V_1 , unsigned long V_229 ,
void * V_44 , unsigned long V_230 )
{
return F_129 ( V_1 , V_229 , V_44 , V_230 , false ) ;
}
static int F_135 ( unsigned long V_1 , unsigned long V_229 ,
void * V_44 , unsigned long V_230 )
{
return F_129 ( V_1 , V_229 , V_44 , V_230 , true ) ;
}
static unsigned long F_136 ( void * V_249 )
{
return F_137 ( F_138 ( V_249 ) ) ;
}
static int T_14 F_139 ( void )
{
return 0 ;
}
static void T_15 F_140 ( void )
{
}
