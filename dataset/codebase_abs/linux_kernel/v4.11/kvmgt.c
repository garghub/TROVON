static inline bool F_1 ( unsigned long V_1 )
{
return ! ! ( V_1 & ~ 0xff ) ;
}
static int F_2 ( struct V_2 * V_3 , T_1 V_4 ,
unsigned long * V_5 )
{
struct V_6 * V_6 ;
struct V_7 * V_8 = & V_3 -> V_9 -> V_10 -> V_11 . V_12 -> V_8 ;
T_2 V_13 ;
if ( F_3 ( ! F_4 ( V_4 ) ) )
return - V_14 ;
V_6 = F_5 ( V_4 ) ;
V_13 = F_6 ( V_8 , V_6 , 0 , V_15 ,
V_16 ) ;
if ( F_7 ( V_8 , V_13 ) )
return - V_17 ;
* V_5 = ( unsigned long ) ( V_13 >> V_18 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 , unsigned long V_5 )
{
struct V_7 * V_8 = & V_3 -> V_9 -> V_10 -> V_11 . V_12 -> V_8 ;
T_2 V_13 ;
V_13 = ( T_2 ) ( V_5 << V_18 ) ;
F_9 ( V_8 , V_13 , V_15 , V_16 ) ;
}
static struct V_19 * F_10 ( struct V_2 * V_3 , T_3 V_20 )
{
struct V_21 * V_22 = V_3 -> V_23 . V_24 . V_21 ;
struct V_19 * V_25 = NULL ;
while ( V_22 ) {
struct V_19 * V_26 = F_11 ( V_22 , struct V_19 , V_22 ) ;
if ( V_20 < V_26 -> V_20 )
V_22 = V_22 -> V_27 ;
else if ( V_20 > V_26 -> V_20 )
V_22 = V_22 -> V_28 ;
else {
V_25 = V_26 ;
goto V_29;
}
}
V_29:
return V_25 ;
}
static unsigned long F_12 ( struct V_2 * V_3 , T_3 V_20 )
{
struct V_19 * V_30 ;
unsigned long V_5 ;
F_13 ( & V_3 -> V_23 . V_31 ) ;
V_30 = F_10 ( V_3 , V_20 ) ;
V_5 = ( V_30 == NULL ) ? V_32 : V_30 -> V_5 ;
F_14 ( & V_3 -> V_23 . V_31 ) ;
return V_5 ;
}
static void F_15 ( struct V_2 * V_3 , T_3 V_20 ,
unsigned long V_5 )
{
struct V_19 * V_33 , * V_26 ;
struct V_21 * * V_34 = & V_3 -> V_23 . V_24 . V_21 , * V_35 = NULL ;
V_33 = F_16 ( sizeof( struct V_19 ) , V_36 ) ;
if ( ! V_33 )
return;
V_33 -> V_20 = V_20 ;
V_33 -> V_5 = V_5 ;
F_13 ( & V_3 -> V_23 . V_31 ) ;
while ( * V_34 ) {
V_35 = * V_34 ;
V_26 = F_11 ( V_35 , struct V_19 , V_22 ) ;
if ( V_20 == V_26 -> V_20 )
goto V_29;
else if ( V_20 < V_26 -> V_20 )
V_34 = & V_35 -> V_27 ;
else
V_34 = & V_35 -> V_28 ;
}
F_17 ( & V_33 -> V_22 , V_35 , V_34 ) ;
F_18 ( & V_33 -> V_22 , & V_3 -> V_23 . V_24 ) ;
F_14 ( & V_3 -> V_23 . V_31 ) ;
return;
V_29:
F_14 ( & V_3 -> V_23 . V_31 ) ;
F_19 ( V_33 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_19 * V_30 )
{
F_21 ( & V_30 -> V_22 , & V_3 -> V_23 . V_24 ) ;
F_19 ( V_30 ) ;
}
static void F_22 ( struct V_2 * V_3 , T_3 V_20 )
{
struct V_7 * V_8 = F_23 ( V_3 -> V_23 . V_37 ) ;
struct V_19 * V_38 ;
unsigned long V_39 ;
int V_40 ;
F_13 ( & V_3 -> V_23 . V_31 ) ;
V_38 = F_10 ( V_3 , V_20 ) ;
if ( ! V_38 ) {
F_14 ( & V_3 -> V_23 . V_31 ) ;
return;
}
V_39 = V_20 ;
F_8 ( V_3 , V_38 -> V_5 ) ;
V_40 = F_24 ( V_8 , & V_39 , 1 ) ;
F_25 ( V_40 != 1 ) ;
F_20 ( V_3 , V_38 ) ;
F_14 ( & V_3 -> V_23 . V_31 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
V_3 -> V_23 . V_24 = V_41 ;
F_27 ( & V_3 -> V_23 . V_31 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_19 * V_42 ;
struct V_21 * V_22 = NULL ;
struct V_7 * V_8 = F_23 ( V_3 -> V_23 . V_37 ) ;
unsigned long V_20 ;
F_13 ( & V_3 -> V_23 . V_31 ) ;
while ( ( V_22 = F_29 ( & V_3 -> V_23 . V_24 ) ) ) {
V_42 = F_11 ( V_22 , struct V_19 , V_22 ) ;
F_8 ( V_3 , V_42 -> V_5 ) ;
V_20 = V_42 -> V_20 ;
F_24 ( V_8 , & V_20 , 1 ) ;
F_20 ( V_3 , V_42 ) ;
}
F_14 ( & V_3 -> V_23 . V_31 ) ;
}
static struct V_43 * F_30 ( struct V_44 * V_9 ,
const char * V_45 )
{
int V_46 ;
struct V_43 * V_47 ;
const char * V_48 = F_31 (
& V_9 -> V_10 -> V_11 . V_12 -> V_8 ) ;
for ( V_46 = 0 ; V_46 < V_9 -> V_49 ; V_46 ++ ) {
V_47 = & V_9 -> V_50 [ V_46 ] ;
if ( ! strncmp ( V_47 -> V_45 , V_45 + strlen ( V_48 ) + 1 ,
sizeof( V_47 -> V_45 ) ) )
return V_47 ;
}
return NULL ;
}
static T_4 F_32 ( struct V_51 * V_52 ,
struct V_7 * V_8 , char * V_53 )
{
struct V_43 * type ;
unsigned int V_54 = 0 ;
void * V_9 = F_33 ( V_8 ) -> V_9 ;
type = F_30 ( V_9 , F_34 ( V_52 ) ) ;
if ( ! type )
V_54 = 0 ;
else
V_54 = type -> V_55 ;
return sprintf ( V_53 , L_1 , V_54 ) ;
}
static T_4 F_35 ( struct V_51 * V_52 , struct V_7 * V_8 ,
char * V_53 )
{
return sprintf ( V_53 , L_2 , V_56 ) ;
}
static T_4 F_36 ( struct V_51 * V_52 , struct V_7 * V_8 ,
char * V_53 )
{
struct V_43 * type ;
void * V_9 = F_33 ( V_8 ) -> V_9 ;
type = F_30 ( V_9 , F_34 ( V_52 ) ) ;
if ( ! type )
return 0 ;
return sprintf ( V_53 , L_3
L_4 ,
F_37 ( type -> V_57 ) ,
F_37 ( type -> V_58 ) ,
type -> V_59 , F_38 ( type -> V_60 ) ) ;
}
static bool F_39 ( struct V_44 * V_9 )
{
int V_46 , V_61 ;
struct V_43 * type ;
struct V_62 * V_63 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_49 ; V_46 ++ ) {
type = & V_9 -> V_50 [ V_46 ] ;
V_63 = F_16 ( sizeof( struct V_62 ) , V_36 ) ;
if ( F_25 ( ! V_63 ) )
goto V_64;
V_63 -> V_45 = type -> V_45 ;
V_63 -> V_65 = V_66 ;
V_67 [ V_46 ] = V_63 ;
}
return true ;
V_64:
for ( V_61 = 0 ; V_61 < V_46 ; V_61 ++ ) {
V_63 = V_67 [ V_61 ] ;
F_19 ( V_63 ) ;
}
return false ;
}
static void F_40 ( struct V_44 * V_9 )
{
int V_46 ;
struct V_62 * V_63 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_49 ; V_46 ++ ) {
V_63 = V_67 [ V_46 ] ;
F_19 ( V_63 ) ;
}
}
static void F_41 ( struct V_68 * V_69 )
{
F_42 ( V_69 -> V_70 ) ;
}
static void F_43 ( struct V_68 * V_69 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
int V_46 ;
F_44 (info->ptable, i, tmp, p, hnode) {
F_45 ( & V_72 -> V_75 ) ;
F_19 ( V_72 ) ;
}
}
static struct V_71 *
F_46 ( struct V_68 * V_69 , T_3 V_20 )
{
struct V_71 * V_72 , * V_76 = NULL ;
F_47 (info->ptable, p, hnode, gfn) {
if ( V_20 == V_72 -> V_20 ) {
V_76 = V_72 ;
break;
}
}
return V_76 ;
}
static bool F_48 ( struct V_68 * V_69 ,
T_3 V_20 )
{
struct V_71 * V_72 ;
V_72 = F_46 ( V_69 , V_20 ) ;
return ! ! V_72 ;
}
static void F_49 ( struct V_68 * V_69 , T_3 V_20 )
{
struct V_71 * V_72 ;
if ( F_48 ( V_69 , V_20 ) )
return;
V_72 = F_16 ( sizeof( struct V_71 ) , V_77 ) ;
if ( F_50 ( ! V_72 , L_5 , V_20 ) )
return;
V_72 -> V_20 = V_20 ;
F_51 ( V_69 -> V_70 , & V_72 -> V_75 , V_20 ) ;
}
static void F_52 ( struct V_68 * V_69 ,
T_3 V_20 )
{
struct V_71 * V_72 ;
V_72 = F_46 ( V_69 , V_20 ) ;
if ( V_72 ) {
F_45 ( & V_72 -> V_75 ) ;
F_19 ( V_72 ) ;
}
}
static int F_53 ( struct V_51 * V_52 , struct V_78 * V_37 )
{
struct V_2 * V_3 = NULL ;
struct V_43 * type ;
struct V_7 * V_12 ;
void * V_9 ;
int V_25 ;
V_12 = F_54 ( V_37 ) ;
V_9 = F_33 ( V_12 ) -> V_9 ;
type = F_30 ( V_9 , F_34 ( V_52 ) ) ;
if ( ! type ) {
F_55 ( L_6 ,
F_34 ( V_52 ) ) ;
V_25 = - V_79 ;
goto V_29;
}
V_3 = V_80 -> V_81 ( V_9 , type ) ;
if ( F_56 ( V_3 ) ) {
V_25 = V_3 == NULL ? - V_14 : F_57 ( V_3 ) ;
F_55 ( L_7 , V_25 ) ;
goto V_29;
}
F_58 ( & V_3 -> V_23 . V_82 , V_83 ) ;
V_3 -> V_23 . V_37 = V_37 ;
F_59 ( V_37 , V_3 ) ;
F_60 ( L_8 ,
F_61 ( F_23 ( V_37 ) ) ) ;
V_25 = 0 ;
V_29:
return V_25 ;
}
static int F_62 ( struct V_78 * V_37 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
if ( F_1 ( V_3 -> V_1 ) )
return - V_84 ;
V_80 -> V_85 ( V_3 ) ;
return 0 ;
}
static int F_64 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
struct V_2 * V_3 = F_65 ( V_87 ,
struct V_2 ,
V_23 . V_90 ) ;
if ( V_88 == V_91 ) {
struct V_92 * V_93 = V_89 ;
unsigned long V_20 , V_94 ;
V_20 = V_93 -> V_5 >> V_18 ;
V_94 = V_20 + V_93 -> V_95 / V_15 ;
while ( V_20 < V_94 )
F_22 ( V_3 , V_20 ++ ) ;
}
return V_96 ;
}
static int F_66 ( struct V_86 * V_87 ,
unsigned long V_88 , void * V_89 )
{
struct V_2 * V_3 = F_65 ( V_87 ,
struct V_2 ,
V_23 . V_97 ) ;
if ( V_88 == V_98 ) {
V_3 -> V_23 . V_99 = V_89 ;
if ( ! V_89 )
F_67 ( & V_3 -> V_23 . V_82 ) ;
}
return V_96 ;
}
static int F_68 ( struct V_78 * V_37 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
unsigned long V_100 ;
int V_25 ;
V_3 -> V_23 . V_90 . V_101 = F_64 ;
V_3 -> V_23 . V_97 . V_101 = F_66 ;
V_100 = V_91 ;
V_25 = F_69 ( F_23 ( V_37 ) , V_102 , & V_100 ,
& V_3 -> V_23 . V_90 ) ;
if ( V_25 != 0 ) {
F_55 ( L_9 ,
V_25 ) ;
goto V_29;
}
V_100 = V_98 ;
V_25 = F_69 ( F_23 ( V_37 ) , V_103 , & V_100 ,
& V_3 -> V_23 . V_97 ) ;
if ( V_25 != 0 ) {
F_55 ( L_10 ,
V_25 ) ;
goto V_104;
}
V_25 = F_70 ( V_37 ) ;
if ( V_25 )
goto V_105;
V_80 -> V_106 ( V_3 ) ;
F_71 ( & V_3 -> V_23 . V_107 , 0 ) ;
return V_25 ;
V_105:
F_72 ( F_23 ( V_37 ) , V_103 ,
& V_3 -> V_23 . V_97 ) ;
V_104:
F_72 ( F_23 ( V_37 ) , V_102 ,
& V_3 -> V_23 . V_90 ) ;
V_29:
return V_25 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_68 * V_69 ;
int V_25 ;
if ( ! F_1 ( V_3 -> V_1 ) )
return;
if ( F_74 ( & V_3 -> V_23 . V_107 , 0 , 1 ) )
return;
V_80 -> V_108 ( V_3 ) ;
V_25 = F_72 ( F_23 ( V_3 -> V_23 . V_37 ) , V_102 ,
& V_3 -> V_23 . V_90 ) ;
F_50 ( V_25 , L_11 , V_25 ) ;
V_25 = F_72 ( F_23 ( V_3 -> V_23 . V_37 ) , V_103 ,
& V_3 -> V_23 . V_97 ) ;
F_50 ( V_25 , L_12 , V_25 ) ;
V_69 = (struct V_68 * ) V_3 -> V_1 ;
F_75 ( V_69 ) ;
V_3 -> V_23 . V_99 = NULL ;
V_3 -> V_1 = 0 ;
}
static void F_76 ( struct V_78 * V_37 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
F_73 ( V_3 ) ;
}
static void V_83 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = F_65 ( V_110 , struct V_2 ,
V_23 . V_82 ) ;
F_73 ( V_3 ) ;
}
static T_5 F_77 ( struct V_2 * V_3 )
{
T_6 V_111 , V_112 ;
T_6 V_113 ;
int V_114 = V_115 ;
V_111 = ( * ( T_6 * ) ( V_3 -> V_116 . V_117 + V_114 ) ) &
V_118 ;
V_113 = ( * ( T_6 * ) ( V_3 -> V_116 . V_117 + V_114 ) ) &
V_119 ;
switch ( V_113 ) {
case V_120 :
V_112 = ( * ( T_6 * ) ( V_3 -> V_116 . V_117
+ V_114 + 4 ) ) ;
break;
case V_121 :
case V_122 :
default:
V_112 = 0 ;
break;
}
return ( ( V_123 ) V_112 << 32 ) | V_111 ;
}
static T_4 F_78 ( struct V_78 * V_37 , char * V_53 ,
T_7 V_124 , T_8 * V_125 , bool V_126 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
unsigned int V_127 = F_79 ( * V_125 ) ;
T_5 V_114 = * V_125 & V_128 ;
int V_25 = - V_79 ;
if ( V_127 >= V_129 ) {
F_55 ( L_13 , V_127 ) ;
return - V_79 ;
}
switch ( V_127 ) {
case V_130 :
if ( V_126 )
V_25 = V_80 -> V_131 ( V_3 , V_114 ,
V_53 , V_124 ) ;
else
V_25 = V_80 -> V_132 ( V_3 , V_114 ,
V_53 , V_124 ) ;
break;
case V_133 :
case V_134 :
if ( V_126 ) {
T_5 V_135 = F_77 ( V_3 ) ;
V_25 = V_80 -> V_136 ( V_3 ,
V_135 + V_114 , V_53 , V_124 ) ;
} else {
T_5 V_135 = F_77 ( V_3 ) ;
V_25 = V_80 -> V_137 ( V_3 ,
V_135 + V_114 , V_53 , V_124 ) ;
}
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
default:
F_55 ( L_14 , V_127 ) ;
}
return V_25 == 0 ? V_124 : V_25 ;
}
static T_4 F_80 ( struct V_78 * V_37 , char T_9 * V_53 ,
T_7 V_124 , T_8 * V_125 )
{
unsigned int V_144 = 0 ;
int V_25 ;
while ( V_124 ) {
T_7 V_145 ;
if ( V_124 >= 4 && ! ( * V_125 % 4 ) ) {
T_6 V_146 ;
V_25 = F_78 ( V_37 , ( char * ) & V_146 , sizeof( V_146 ) ,
V_125 , false ) ;
if ( V_25 <= 0 )
goto V_147;
if ( F_81 ( V_53 , & V_146 , sizeof( V_146 ) ) )
goto V_147;
V_145 = 4 ;
} else if ( V_124 >= 2 && ! ( * V_125 % 2 ) ) {
T_10 V_146 ;
V_25 = F_78 ( V_37 , ( char * ) & V_146 , sizeof( V_146 ) ,
V_125 , false ) ;
if ( V_25 <= 0 )
goto V_147;
if ( F_81 ( V_53 , & V_146 , sizeof( V_146 ) ) )
goto V_147;
V_145 = 2 ;
} else {
T_11 V_146 ;
V_25 = F_78 ( V_37 , & V_146 , sizeof( V_146 ) , V_125 ,
false ) ;
if ( V_25 <= 0 )
goto V_147;
if ( F_81 ( V_53 , & V_146 , sizeof( V_146 ) ) )
goto V_147;
V_145 = 1 ;
}
V_124 -= V_145 ;
V_144 += V_145 ;
* V_125 += V_145 ;
V_53 += V_145 ;
}
return V_144 ;
V_147:
return - V_14 ;
}
static T_4 F_82 ( struct V_78 * V_37 ,
const char T_9 * V_53 ,
T_7 V_124 , T_8 * V_125 )
{
unsigned int V_144 = 0 ;
int V_25 ;
while ( V_124 ) {
T_7 V_145 ;
if ( V_124 >= 4 && ! ( * V_125 % 4 ) ) {
T_6 V_146 ;
if ( F_83 ( & V_146 , V_53 , sizeof( V_146 ) ) )
goto V_148;
V_25 = F_78 ( V_37 , ( char * ) & V_146 , sizeof( V_146 ) ,
V_125 , true ) ;
if ( V_25 <= 0 )
goto V_148;
V_145 = 4 ;
} else if ( V_124 >= 2 && ! ( * V_125 % 2 ) ) {
T_10 V_146 ;
if ( F_83 ( & V_146 , V_53 , sizeof( V_146 ) ) )
goto V_148;
V_25 = F_78 ( V_37 , ( char * ) & V_146 ,
sizeof( V_146 ) , V_125 , true ) ;
if ( V_25 <= 0 )
goto V_148;
V_145 = 2 ;
} else {
T_11 V_146 ;
if ( F_83 ( & V_146 , V_53 , sizeof( V_146 ) ) )
goto V_148;
V_25 = F_78 ( V_37 , & V_146 , sizeof( V_146 ) ,
V_125 , true ) ;
if ( V_25 <= 0 )
goto V_148;
V_145 = 1 ;
}
V_124 -= V_145 ;
V_144 += V_145 ;
* V_125 += V_145 ;
V_53 += V_145 ;
}
return V_144 ;
V_148:
return - V_14 ;
}
static int F_84 ( struct V_78 * V_37 , struct V_149 * V_150 )
{
unsigned int V_127 ;
V_123 V_151 ;
unsigned long V_152 , V_153 = 0 ;
T_12 V_154 ;
struct V_2 * V_3 = F_63 ( V_37 ) ;
V_127 = V_150 -> V_155 >> ( V_156 - V_18 ) ;
if ( V_127 >= V_143 )
return - V_79 ;
if ( V_150 -> V_157 < V_150 -> V_158 )
return - V_79 ;
if ( ( V_150 -> V_159 & V_160 ) == 0 )
return - V_79 ;
if ( V_127 != V_138 )
return - V_79 ;
V_154 = V_150 -> V_161 ;
V_151 = V_150 -> V_158 ;
V_152 = V_150 -> V_157 - V_150 -> V_158 ;
V_153 = F_85 ( V_3 ) >> V_18 ;
return F_86 ( V_150 , V_151 , V_153 , V_152 , V_154 ) ;
}
static int F_87 ( struct V_2 * V_3 , int type )
{
if ( type == V_162 || type == V_163 )
return 1 ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
unsigned int V_127 , unsigned int V_164 ,
unsigned int V_124 , T_13 V_165 ,
void * V_89 )
{
return 0 ;
}
static int F_89 ( struct V_2 * V_3 ,
unsigned int V_127 , unsigned int V_164 ,
unsigned int V_124 , T_13 V_165 , void * V_89 )
{
return 0 ;
}
static int F_90 ( struct V_2 * V_3 ,
unsigned int V_127 , unsigned int V_164 , unsigned int V_124 ,
T_13 V_165 , void * V_89 )
{
return 0 ;
}
static int F_91 ( struct V_2 * V_3 ,
unsigned int V_127 , unsigned int V_164 , unsigned int V_124 ,
T_13 V_165 , void * V_89 )
{
struct V_166 * V_167 ;
if ( V_165 & V_168 ) {
int V_169 = * ( int * ) V_89 ;
V_167 = F_92 ( V_169 ) ;
if ( F_93 ( V_167 ) ) {
F_55 ( L_15 ) ;
return F_57 ( V_167 ) ;
}
V_3 -> V_23 . V_170 = V_167 ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , T_13 V_165 ,
unsigned int V_127 , unsigned int V_164 , unsigned int V_124 ,
void * V_89 )
{
int (* F_95)( struct V_2 * V_3 , unsigned int V_127 ,
unsigned int V_164 , unsigned int V_124 , T_13 V_165 ,
void * V_89 ) = NULL ;
switch ( V_127 ) {
case V_162 :
switch ( V_165 & V_171 ) {
case V_172 :
F_95 = F_88 ;
break;
case V_173 :
F_95 = F_89 ;
break;
case V_174 :
F_95 = F_90 ;
break;
}
break;
case V_163 :
switch ( V_165 & V_171 ) {
case V_172 :
case V_173 :
break;
case V_174 :
F_95 = F_91 ;
break;
}
break;
}
if ( ! F_95 )
return - V_175 ;
return F_95 ( V_3 , V_127 , V_164 , V_124 , V_165 , V_89 ) ;
}
static long F_96 ( struct V_78 * V_37 , unsigned int V_176 ,
unsigned long V_177 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
unsigned long V_178 ;
F_60 ( L_16 , V_3 -> V_179 , V_176 ) ;
if ( V_176 == V_180 ) {
struct V_181 V_69 ;
V_178 = F_97 ( struct V_181 , V_182 ) ;
if ( F_83 ( & V_69 , ( void T_9 * ) V_177 , V_178 ) )
return - V_14 ;
if ( V_69 . V_183 < V_178 )
return - V_79 ;
V_69 . V_165 = V_184 ;
V_69 . V_165 |= V_185 ;
V_69 . V_186 = V_129 ;
V_69 . V_182 = V_187 ;
return F_81 ( ( void T_9 * ) V_177 , & V_69 , V_178 ) ?
- V_14 : 0 ;
} else if ( V_176 == V_188 ) {
struct V_189 V_69 ;
struct V_190 V_191 = { . V_53 = NULL , . V_95 = 0 } ;
int V_46 , V_25 ;
struct V_192 * V_193 = NULL ;
T_7 V_95 ;
int V_194 = 1 ;
int V_195 ;
V_178 = F_97 ( struct V_189 , V_196 ) ;
if ( F_83 ( & V_69 , ( void T_9 * ) V_177 , V_178 ) )
return - V_14 ;
if ( V_69 . V_183 < V_178 )
return - V_79 ;
switch ( V_69 . V_127 ) {
case V_130 :
V_69 . V_196 = F_98 ( V_69 . V_127 ) ;
V_69 . V_95 = V_197 ;
V_69 . V_165 = V_198 |
V_199 ;
break;
case V_133 :
V_69 . V_196 = F_98 ( V_69 . V_127 ) ;
V_69 . V_95 = V_3 -> V_116 . V_200 [ V_69 . V_127 ] . V_95 ;
if ( ! V_69 . V_95 ) {
V_69 . V_165 = 0 ;
break;
}
V_69 . V_165 = V_198 |
V_199 ;
break;
case V_134 :
V_69 . V_196 = F_98 ( V_69 . V_127 ) ;
V_69 . V_95 = 0 ;
V_69 . V_165 = 0 ;
break;
case V_138 :
V_69 . V_196 = F_98 ( V_69 . V_127 ) ;
V_69 . V_165 = V_201 |
V_202 |
V_198 |
V_199 ;
V_69 . V_95 = F_99 ( V_3 -> V_9 ) ;
V_95 = sizeof( * V_193 ) +
( V_194 * sizeof( * V_193 -> V_203 ) ) ;
V_193 = F_16 ( V_95 , V_36 ) ;
if ( ! V_193 )
return - V_17 ;
V_193 -> V_194 = V_194 ;
V_195 = V_204 ;
V_193 -> V_203 [ 0 ] . V_196 =
F_100 ( F_101 ( V_3 ) ) ;
V_193 -> V_203 [ 0 ] . V_95 = F_102 ( V_3 ) ;
break;
case V_139 ... V_141 :
V_69 . V_196 = F_98 ( V_69 . V_127 ) ;
V_69 . V_95 = 0 ;
V_69 . V_165 = 0 ;
F_60 ( L_17 , V_69 . V_127 ) ;
break;
case V_143 :
case V_142 :
F_60 ( L_18 , V_69 . V_127 ) ;
break;
default:
{
struct V_205 V_206 ;
if ( V_69 . V_127 >= V_129 +
V_3 -> V_23 . V_186 )
return - V_79 ;
V_46 = V_69 . V_127 - V_129 ;
V_69 . V_196 =
F_98 ( V_69 . V_127 ) ;
V_69 . V_95 = V_3 -> V_23 . V_207 [ V_46 ] . V_95 ;
V_69 . V_165 = V_3 -> V_23 . V_207 [ V_46 ] . V_165 ;
V_206 . type = V_3 -> V_23 . V_207 [ V_46 ] . type ;
V_206 . V_208 = V_3 -> V_23 . V_207 [ V_46 ] . V_208 ;
V_25 = F_103 ( & V_191 ,
V_209 ,
& V_206 ) ;
if ( V_25 )
return V_25 ;
}
}
if ( ( V_69 . V_165 & V_201 ) && V_193 ) {
switch ( V_195 ) {
case V_204 :
V_25 = F_103 ( & V_191 ,
V_204 ,
V_193 ) ;
F_19 ( V_193 ) ;
if ( V_25 )
return V_25 ;
break;
default:
return - V_79 ;
}
}
if ( V_191 . V_95 ) {
if ( V_69 . V_183 < sizeof( V_69 ) + V_191 . V_95 ) {
V_69 . V_183 = sizeof( V_69 ) + V_191 . V_95 ;
V_69 . V_210 = 0 ;
} else {
F_104 ( & V_191 , sizeof( V_69 ) ) ;
if ( F_81 ( ( void T_9 * ) V_177 +
sizeof( V_69 ) , V_191 . V_53 ,
V_191 . V_95 ) ) {
F_19 ( V_191 . V_53 ) ;
return - V_14 ;
}
V_69 . V_210 = sizeof( V_69 ) ;
}
F_19 ( V_191 . V_53 ) ;
}
return F_81 ( ( void T_9 * ) V_177 , & V_69 , V_178 ) ?
- V_14 : 0 ;
} else if ( V_176 == V_211 ) {
struct V_212 V_69 ;
V_178 = F_97 ( struct V_212 , V_124 ) ;
if ( F_83 ( & V_69 , ( void T_9 * ) V_177 , V_178 ) )
return - V_14 ;
if ( V_69 . V_183 < V_178 || V_69 . V_127 >= V_187 )
return - V_79 ;
switch ( V_69 . V_127 ) {
case V_162 :
case V_163 :
break;
default:
return - V_79 ;
}
V_69 . V_165 = V_213 ;
V_69 . V_124 = F_87 ( V_3 , V_69 . V_127 ) ;
if ( V_69 . V_127 == V_162 )
V_69 . V_165 |= ( V_214 |
V_215 ) ;
else
V_69 . V_165 |= V_216 ;
return F_81 ( ( void T_9 * ) V_177 , & V_69 , V_178 ) ?
- V_14 : 0 ;
} else if ( V_176 == V_217 ) {
struct V_218 V_219 ;
T_11 * V_89 = NULL ;
int V_25 = 0 ;
T_7 V_220 = 0 ;
V_178 = F_97 ( struct V_218 , V_124 ) ;
if ( F_83 ( & V_219 , ( void T_9 * ) V_177 , V_178 ) )
return - V_14 ;
if ( ! ( V_219 . V_165 & V_221 ) ) {
int V_222 = F_87 ( V_3 , V_219 . V_127 ) ;
V_25 = F_105 ( & V_219 , V_222 ,
V_187 , & V_220 ) ;
if ( V_25 ) {
F_55 ( L_19 ) ;
return - V_79 ;
}
if ( V_220 ) {
V_89 = F_106 ( ( void T_9 * ) ( V_177 + V_178 ) ,
V_220 ) ;
if ( F_93 ( V_89 ) )
return F_57 ( V_89 ) ;
}
}
V_25 = F_94 ( V_3 , V_219 . V_165 , V_219 . V_127 ,
V_219 . V_164 , V_219 . V_124 , V_89 ) ;
F_19 ( V_89 ) ;
return V_25 ;
} else if ( V_176 == V_223 ) {
V_80 -> V_224 ( V_3 ) ;
return 0 ;
}
return 0 ;
}
static int F_107 ( struct V_7 * V_8 , void * V_9 , const void * V_225 )
{
if ( ! F_39 ( V_9 ) )
return - V_14 ;
V_80 = V_225 ;
return F_108 ( V_8 , & V_226 ) ;
}
static void F_109 ( struct V_7 * V_8 , void * V_9 )
{
F_40 ( V_9 ) ;
F_110 ( V_8 ) ;
}
static int F_111 ( unsigned long V_1 , V_123 V_20 )
{
struct V_68 * V_69 ;
struct V_99 * V_99 ;
struct V_227 * V_228 ;
int V_229 ;
if ( ! F_1 ( V_1 ) )
return - V_230 ;
V_69 = (struct V_68 * ) V_1 ;
V_99 = V_69 -> V_99 ;
V_229 = F_112 ( & V_99 -> V_231 ) ;
V_228 = F_113 ( V_99 , V_20 ) ;
if ( ! V_228 ) {
F_114 ( & V_99 -> V_231 , V_229 ) ;
return - V_79 ;
}
F_115 ( & V_99 -> V_232 ) ;
if ( F_48 ( V_69 , V_20 ) )
goto V_29;
F_116 ( V_99 , V_228 , V_20 , V_233 ) ;
F_49 ( V_69 , V_20 ) ;
V_29:
F_117 ( & V_99 -> V_232 ) ;
F_114 ( & V_99 -> V_231 , V_229 ) ;
return 0 ;
}
static int F_118 ( unsigned long V_1 , V_123 V_20 )
{
struct V_68 * V_69 ;
struct V_99 * V_99 ;
struct V_227 * V_228 ;
int V_229 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
V_69 = (struct V_68 * ) V_1 ;
V_99 = V_69 -> V_99 ;
V_229 = F_112 ( & V_99 -> V_231 ) ;
V_228 = F_113 ( V_99 , V_20 ) ;
if ( ! V_228 ) {
F_114 ( & V_99 -> V_231 , V_229 ) ;
return - V_79 ;
}
F_115 ( & V_99 -> V_232 ) ;
if ( ! F_48 ( V_69 , V_20 ) )
goto V_29;
F_119 ( V_99 , V_228 , V_20 , V_233 ) ;
F_52 ( V_69 , V_20 ) ;
V_29:
F_117 ( & V_99 -> V_232 ) ;
F_114 ( & V_99 -> V_231 , V_229 ) ;
return 0 ;
}
static void F_120 ( struct V_234 * V_235 , T_14 V_236 ,
const T_11 * V_146 , int V_237 ,
struct V_238 * V_22 )
{
struct V_68 * V_69 = F_65 ( V_22 ,
struct V_68 , V_239 ) ;
if ( F_48 ( V_69 , F_121 ( V_236 ) ) )
V_80 -> V_136 ( V_69 -> V_3 , V_236 ,
( void * ) V_146 , V_237 ) ;
}
static void F_122 ( struct V_99 * V_99 ,
struct V_227 * V_228 ,
struct V_238 * V_22 )
{
int V_46 ;
T_3 V_20 ;
struct V_68 * V_69 = F_65 ( V_22 ,
struct V_68 , V_239 ) ;
F_115 ( & V_99 -> V_232 ) ;
for ( V_46 = 0 ; V_46 < V_228 -> V_240 ; V_46 ++ ) {
V_20 = V_228 -> V_241 + V_46 ;
if ( F_48 ( V_69 , V_20 ) ) {
F_119 ( V_99 , V_228 , V_20 ,
V_233 ) ;
F_52 ( V_69 , V_20 ) ;
}
}
F_117 ( & V_99 -> V_232 ) ;
}
static bool F_123 ( struct V_2 * V_3 , struct V_99 * V_99 )
{
struct V_2 * V_26 ;
struct V_68 * V_69 ;
int V_179 ;
bool V_25 = false ;
F_13 ( & V_3 -> V_9 -> V_242 ) ;
F_124 (vgpu->gvt, itr, id) {
if ( ! F_1 ( V_26 -> V_1 ) )
continue;
V_69 = (struct V_68 * ) V_26 -> V_1 ;
if ( V_99 && V_99 == V_69 -> V_99 ) {
V_25 = true ;
goto V_29;
}
}
V_29:
F_14 ( & V_3 -> V_9 -> V_242 ) ;
return V_25 ;
}
static int F_70 ( struct V_78 * V_37 )
{
struct V_68 * V_69 ;
struct V_2 * V_3 ;
struct V_99 * V_99 ;
V_3 = F_63 ( V_37 ) ;
if ( F_1 ( V_3 -> V_1 ) )
return - V_243 ;
V_99 = V_3 -> V_23 . V_99 ;
if ( ! V_99 || V_99 -> V_244 != V_245 -> V_244 ) {
F_55 ( L_20 ) ;
return - V_230 ;
}
if ( F_123 ( V_3 , V_99 ) )
return - V_243 ;
V_69 = F_125 ( sizeof( struct V_68 ) ) ;
if ( ! V_69 )
return - V_17 ;
V_3 -> V_1 = ( unsigned long ) V_69 ;
V_69 -> V_3 = V_3 ;
V_69 -> V_99 = V_99 ;
F_126 ( V_69 -> V_99 ) ;
F_41 ( V_69 ) ;
F_26 ( V_3 ) ;
V_69 -> V_239 . V_246 = F_120 ;
V_69 -> V_239 . V_247 = F_122 ;
F_127 ( V_99 , & V_69 -> V_239 ) ;
return 0 ;
}
static bool F_75 ( struct V_68 * V_69 )
{
F_128 ( V_69 -> V_99 , & V_69 -> V_239 ) ;
F_129 ( V_69 -> V_99 ) ;
F_43 ( V_69 ) ;
F_28 ( V_69 -> V_3 ) ;
F_130 ( V_69 ) ;
return true ;
}
static int F_131 ( void * V_3 , unsigned long * V_1 )
{
return 0 ;
}
static void F_132 ( unsigned long V_1 )
{
}
static int F_133 ( unsigned long V_1 , T_6 V_248 , T_10 V_89 )
{
struct V_68 * V_69 ;
struct V_2 * V_3 ;
if ( ! F_1 ( V_1 ) )
return - V_230 ;
V_69 = (struct V_68 * ) V_1 ;
V_3 = V_69 -> V_3 ;
if ( F_134 ( V_3 -> V_23 . V_170 , 1 ) == 1 )
return 0 ;
return - V_14 ;
}
static unsigned long F_135 ( unsigned long V_1 , unsigned long V_20 )
{
unsigned long V_5 , V_4 ;
struct V_68 * V_69 ;
struct V_7 * V_8 ;
struct V_2 * V_3 ;
int V_40 ;
if ( ! F_1 ( V_1 ) )
return V_32 ;
V_69 = (struct V_68 * ) V_1 ;
V_3 = V_69 -> V_3 ;
V_5 = F_12 ( V_69 -> V_3 , V_20 ) ;
if ( V_5 != V_32 )
return V_5 ;
V_4 = V_32 ;
V_8 = F_23 ( V_69 -> V_3 -> V_23 . V_37 ) ;
V_40 = F_136 ( V_8 , & V_20 , 1 , V_249 | V_250 , & V_4 ) ;
if ( V_40 != 1 ) {
F_55 ( L_21 ,
V_20 , V_40 ) ;
return V_32 ;
}
V_40 = F_2 ( V_69 -> V_3 , V_4 , & V_5 ) ;
if ( V_40 ) {
F_55 ( L_22 , V_20 ) ;
F_24 ( V_8 , & V_20 , 1 ) ;
return V_32 ;
}
F_15 ( V_69 -> V_3 , V_20 , V_5 ) ;
return V_5 ;
}
static int F_137 ( unsigned long V_1 , unsigned long V_236 ,
void * V_53 , unsigned long V_237 , bool V_251 )
{
struct V_68 * V_69 ;
struct V_99 * V_99 ;
int V_229 , V_25 ;
bool V_252 = V_245 -> V_244 == NULL ;
if ( ! F_1 ( V_1 ) )
return - V_230 ;
V_69 = (struct V_68 * ) V_1 ;
V_99 = V_69 -> V_99 ;
if ( V_252 )
F_138 ( V_99 -> V_244 ) ;
V_229 = F_112 ( & V_99 -> V_231 ) ;
V_25 = V_251 ? F_139 ( V_99 , V_236 , V_53 , V_237 ) :
F_140 ( V_99 , V_236 , V_53 , V_237 ) ;
F_114 ( & V_99 -> V_231 , V_229 ) ;
if ( V_252 )
F_141 ( V_99 -> V_244 ) ;
return V_25 ;
}
static int F_142 ( unsigned long V_1 , unsigned long V_236 ,
void * V_53 , unsigned long V_237 )
{
return F_137 ( V_1 , V_236 , V_53 , V_237 , false ) ;
}
static int F_143 ( unsigned long V_1 , unsigned long V_236 ,
void * V_53 , unsigned long V_237 )
{
return F_137 ( V_1 , V_236 , V_53 , V_237 , true ) ;
}
static unsigned long F_144 ( void * V_248 )
{
return F_145 ( F_146 ( V_248 ) ) ;
}
static int T_15 F_147 ( void )
{
return 0 ;
}
static void T_16 F_148 ( void )
{
}
