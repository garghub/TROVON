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
for (; ; ) {
F_13 ( & V_3 -> V_23 . V_31 ) ;
V_22 = F_29 ( & V_3 -> V_23 . V_24 ) ;
if ( ! V_22 ) {
F_14 ( & V_3 -> V_23 . V_31 ) ;
break;
}
V_42 = F_11 ( V_22 , struct V_19 , V_22 ) ;
F_8 ( V_3 , V_42 -> V_5 ) ;
V_20 = V_42 -> V_20 ;
F_20 ( V_3 , V_42 ) ;
F_14 ( & V_3 -> V_23 . V_31 ) ;
F_24 ( V_8 , & V_20 , 1 ) ;
}
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
L_4
L_5 ,
F_37 ( type -> V_57 ) ,
F_37 ( type -> V_58 ) ,
type -> V_59 , F_38 ( type -> V_60 ) ,
type -> V_61 ) ;
}
static bool F_39 ( struct V_44 * V_9 )
{
int V_46 , V_62 ;
struct V_43 * type ;
struct V_63 * V_64 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_49 ; V_46 ++ ) {
type = & V_9 -> V_50 [ V_46 ] ;
V_64 = F_16 ( sizeof( struct V_63 ) , V_36 ) ;
if ( F_25 ( ! V_64 ) )
goto V_65;
V_64 -> V_45 = type -> V_45 ;
V_64 -> V_66 = V_67 ;
V_68 [ V_46 ] = V_64 ;
}
return true ;
V_65:
for ( V_62 = 0 ; V_62 < V_46 ; V_62 ++ ) {
V_64 = V_68 [ V_62 ] ;
F_19 ( V_64 ) ;
}
return false ;
}
static void F_40 ( struct V_44 * V_9 )
{
int V_46 ;
struct V_63 * V_64 ;
for ( V_46 = 0 ; V_46 < V_9 -> V_49 ; V_46 ++ ) {
V_64 = V_68 [ V_46 ] ;
F_19 ( V_64 ) ;
}
}
static void F_41 ( struct V_69 * V_70 )
{
F_42 ( V_70 -> V_71 ) ;
}
static void F_43 ( struct V_69 * V_70 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
int V_46 ;
F_44 (info->ptable, i, tmp, p, hnode) {
F_45 ( & V_73 -> V_76 ) ;
F_19 ( V_73 ) ;
}
}
static struct V_72 *
F_46 ( struct V_69 * V_70 , T_3 V_20 )
{
struct V_72 * V_73 , * V_77 = NULL ;
F_47 (info->ptable, p, hnode, gfn) {
if ( V_20 == V_73 -> V_20 ) {
V_77 = V_73 ;
break;
}
}
return V_77 ;
}
static bool F_48 ( struct V_69 * V_70 ,
T_3 V_20 )
{
struct V_72 * V_73 ;
V_73 = F_46 ( V_70 , V_20 ) ;
return ! ! V_73 ;
}
static void F_49 ( struct V_69 * V_70 , T_3 V_20 )
{
struct V_72 * V_73 ;
if ( F_48 ( V_70 , V_20 ) )
return;
V_73 = F_16 ( sizeof( struct V_72 ) , V_78 ) ;
if ( F_50 ( ! V_73 , L_6 , V_20 ) )
return;
V_73 -> V_20 = V_20 ;
F_51 ( V_70 -> V_71 , & V_73 -> V_76 , V_20 ) ;
}
static void F_52 ( struct V_69 * V_70 ,
T_3 V_20 )
{
struct V_72 * V_73 ;
V_73 = F_46 ( V_70 , V_20 ) ;
if ( V_73 ) {
F_45 ( & V_73 -> V_76 ) ;
F_19 ( V_73 ) ;
}
}
static int F_53 ( struct V_51 * V_52 , struct V_79 * V_37 )
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
F_55 ( L_7 ,
F_34 ( V_52 ) ) ;
V_25 = - V_80 ;
goto V_29;
}
V_3 = V_81 -> V_82 ( V_9 , type ) ;
if ( F_56 ( V_3 ) ) {
V_25 = V_3 == NULL ? - V_14 : F_57 ( V_3 ) ;
F_55 ( L_8 , V_25 ) ;
goto V_29;
}
F_58 ( & V_3 -> V_23 . V_83 , V_84 ) ;
V_3 -> V_23 . V_37 = V_37 ;
F_59 ( V_37 , V_3 ) ;
F_60 ( L_9 ,
F_61 ( F_23 ( V_37 ) ) ) ;
V_25 = 0 ;
V_29:
return V_25 ;
}
static int F_62 ( struct V_79 * V_37 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
if ( F_1 ( V_3 -> V_1 ) )
return - V_85 ;
V_81 -> V_86 ( V_3 ) ;
return 0 ;
}
static int F_64 ( struct V_87 * V_88 ,
unsigned long V_89 , void * V_90 )
{
struct V_2 * V_3 = F_65 ( V_88 ,
struct V_2 ,
V_23 . V_91 ) ;
if ( V_89 == V_92 ) {
struct V_93 * V_94 = V_90 ;
unsigned long V_20 , V_95 ;
V_20 = V_94 -> V_5 >> V_18 ;
V_95 = V_20 + V_94 -> V_96 / V_15 ;
while ( V_20 < V_95 )
F_22 ( V_3 , V_20 ++ ) ;
}
return V_97 ;
}
static int F_66 ( struct V_87 * V_88 ,
unsigned long V_89 , void * V_90 )
{
struct V_2 * V_3 = F_65 ( V_88 ,
struct V_2 ,
V_23 . V_98 ) ;
if ( V_89 == V_99 ) {
V_3 -> V_23 . V_100 = V_90 ;
if ( ! V_90 )
F_67 ( & V_3 -> V_23 . V_83 ) ;
}
return V_97 ;
}
static int F_68 ( struct V_79 * V_37 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
unsigned long V_101 ;
int V_25 ;
V_3 -> V_23 . V_91 . V_102 = F_64 ;
V_3 -> V_23 . V_98 . V_102 = F_66 ;
V_101 = V_92 ;
V_25 = F_69 ( F_23 ( V_37 ) , V_103 , & V_101 ,
& V_3 -> V_23 . V_91 ) ;
if ( V_25 != 0 ) {
F_55 ( L_10 ,
V_25 ) ;
goto V_29;
}
V_101 = V_99 ;
V_25 = F_69 ( F_23 ( V_37 ) , V_104 , & V_101 ,
& V_3 -> V_23 . V_98 ) ;
if ( V_25 != 0 ) {
F_55 ( L_11 ,
V_25 ) ;
goto V_105;
}
V_25 = F_70 ( V_37 ) ;
if ( V_25 )
goto V_106;
V_81 -> V_107 ( V_3 ) ;
F_71 ( & V_3 -> V_23 . V_108 , 0 ) ;
return V_25 ;
V_106:
F_72 ( F_23 ( V_37 ) , V_104 ,
& V_3 -> V_23 . V_98 ) ;
V_105:
F_72 ( F_23 ( V_37 ) , V_103 ,
& V_3 -> V_23 . V_91 ) ;
V_29:
return V_25 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_69 * V_70 ;
int V_25 ;
if ( ! F_1 ( V_3 -> V_1 ) )
return;
if ( F_74 ( & V_3 -> V_23 . V_108 , 0 , 1 ) )
return;
V_81 -> V_109 ( V_3 ) ;
V_25 = F_72 ( F_23 ( V_3 -> V_23 . V_37 ) , V_103 ,
& V_3 -> V_23 . V_91 ) ;
F_50 ( V_25 , L_12 , V_25 ) ;
V_25 = F_72 ( F_23 ( V_3 -> V_23 . V_37 ) , V_104 ,
& V_3 -> V_23 . V_98 ) ;
F_50 ( V_25 , L_13 , V_25 ) ;
V_70 = (struct V_69 * ) V_3 -> V_1 ;
F_75 ( V_70 ) ;
V_3 -> V_23 . V_100 = NULL ;
V_3 -> V_1 = 0 ;
}
static void F_76 ( struct V_79 * V_37 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
F_73 ( V_3 ) ;
}
static void V_84 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = F_65 ( V_111 , struct V_2 ,
V_23 . V_83 ) ;
F_73 ( V_3 ) ;
}
static T_5 F_77 ( struct V_2 * V_3 )
{
T_6 V_112 , V_113 ;
T_6 V_114 ;
int V_115 = V_116 ;
V_112 = ( * ( T_6 * ) ( V_3 -> V_117 . V_118 + V_115 ) ) &
V_119 ;
V_114 = ( * ( T_6 * ) ( V_3 -> V_117 . V_118 + V_115 ) ) &
V_120 ;
switch ( V_114 ) {
case V_121 :
V_113 = ( * ( T_6 * ) ( V_3 -> V_117 . V_118
+ V_115 + 4 ) ) ;
break;
case V_122 :
case V_123 :
default:
V_113 = 0 ;
break;
}
return ( ( V_124 ) V_113 << 32 ) | V_112 ;
}
static T_4 F_78 ( struct V_79 * V_37 , char * V_53 ,
T_7 V_125 , T_8 * V_126 , bool V_127 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
unsigned int V_128 = F_79 ( * V_126 ) ;
T_5 V_115 = * V_126 & V_129 ;
int V_25 = - V_80 ;
if ( V_128 >= V_130 ) {
F_55 ( L_14 , V_128 ) ;
return - V_80 ;
}
switch ( V_128 ) {
case V_131 :
if ( V_127 )
V_25 = V_81 -> V_132 ( V_3 , V_115 ,
V_53 , V_125 ) ;
else
V_25 = V_81 -> V_133 ( V_3 , V_115 ,
V_53 , V_125 ) ;
break;
case V_134 :
case V_135 :
if ( V_127 ) {
T_5 V_136 = F_77 ( V_3 ) ;
V_25 = V_81 -> V_137 ( V_3 ,
V_136 + V_115 , V_53 , V_125 ) ;
} else {
T_5 V_136 = F_77 ( V_3 ) ;
V_25 = V_81 -> V_138 ( V_3 ,
V_136 + V_115 , V_53 , V_125 ) ;
}
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
default:
F_55 ( L_15 , V_128 ) ;
}
return V_25 == 0 ? V_125 : V_25 ;
}
static T_4 F_80 ( struct V_79 * V_37 , char T_9 * V_53 ,
T_7 V_125 , T_8 * V_126 )
{
unsigned int V_145 = 0 ;
int V_25 ;
while ( V_125 ) {
T_7 V_146 ;
if ( V_125 >= 4 && ! ( * V_126 % 4 ) ) {
T_6 V_147 ;
V_25 = F_78 ( V_37 , ( char * ) & V_147 , sizeof( V_147 ) ,
V_126 , false ) ;
if ( V_25 <= 0 )
goto V_148;
if ( F_81 ( V_53 , & V_147 , sizeof( V_147 ) ) )
goto V_148;
V_146 = 4 ;
} else if ( V_125 >= 2 && ! ( * V_126 % 2 ) ) {
T_10 V_147 ;
V_25 = F_78 ( V_37 , ( char * ) & V_147 , sizeof( V_147 ) ,
V_126 , false ) ;
if ( V_25 <= 0 )
goto V_148;
if ( F_81 ( V_53 , & V_147 , sizeof( V_147 ) ) )
goto V_148;
V_146 = 2 ;
} else {
T_11 V_147 ;
V_25 = F_78 ( V_37 , & V_147 , sizeof( V_147 ) , V_126 ,
false ) ;
if ( V_25 <= 0 )
goto V_148;
if ( F_81 ( V_53 , & V_147 , sizeof( V_147 ) ) )
goto V_148;
V_146 = 1 ;
}
V_125 -= V_146 ;
V_145 += V_146 ;
* V_126 += V_146 ;
V_53 += V_146 ;
}
return V_145 ;
V_148:
return - V_14 ;
}
static T_4 F_82 ( struct V_79 * V_37 ,
const char T_9 * V_53 ,
T_7 V_125 , T_8 * V_126 )
{
unsigned int V_145 = 0 ;
int V_25 ;
while ( V_125 ) {
T_7 V_146 ;
if ( V_125 >= 4 && ! ( * V_126 % 4 ) ) {
T_6 V_147 ;
if ( F_83 ( & V_147 , V_53 , sizeof( V_147 ) ) )
goto V_149;
V_25 = F_78 ( V_37 , ( char * ) & V_147 , sizeof( V_147 ) ,
V_126 , true ) ;
if ( V_25 <= 0 )
goto V_149;
V_146 = 4 ;
} else if ( V_125 >= 2 && ! ( * V_126 % 2 ) ) {
T_10 V_147 ;
if ( F_83 ( & V_147 , V_53 , sizeof( V_147 ) ) )
goto V_149;
V_25 = F_78 ( V_37 , ( char * ) & V_147 ,
sizeof( V_147 ) , V_126 , true ) ;
if ( V_25 <= 0 )
goto V_149;
V_146 = 2 ;
} else {
T_11 V_147 ;
if ( F_83 ( & V_147 , V_53 , sizeof( V_147 ) ) )
goto V_149;
V_25 = F_78 ( V_37 , & V_147 , sizeof( V_147 ) ,
V_126 , true ) ;
if ( V_25 <= 0 )
goto V_149;
V_146 = 1 ;
}
V_125 -= V_146 ;
V_145 += V_146 ;
* V_126 += V_146 ;
V_53 += V_146 ;
}
return V_145 ;
V_149:
return - V_14 ;
}
static int F_84 ( struct V_79 * V_37 , struct V_150 * V_151 )
{
unsigned int V_128 ;
V_124 V_152 ;
unsigned long V_153 , V_154 = 0 ;
T_12 V_155 ;
struct V_2 * V_3 = F_63 ( V_37 ) ;
V_128 = V_151 -> V_156 >> ( V_157 - V_18 ) ;
if ( V_128 >= V_144 )
return - V_80 ;
if ( V_151 -> V_158 < V_151 -> V_159 )
return - V_80 ;
if ( ( V_151 -> V_160 & V_161 ) == 0 )
return - V_80 ;
if ( V_128 != V_139 )
return - V_80 ;
V_155 = V_151 -> V_162 ;
V_152 = V_151 -> V_159 ;
V_153 = V_151 -> V_158 - V_151 -> V_159 ;
V_154 = F_85 ( V_3 ) >> V_18 ;
return F_86 ( V_151 , V_152 , V_154 , V_153 , V_155 ) ;
}
static int F_87 ( struct V_2 * V_3 , int type )
{
if ( type == V_163 || type == V_164 )
return 1 ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
unsigned int V_128 , unsigned int V_165 ,
unsigned int V_125 , T_13 V_166 ,
void * V_90 )
{
return 0 ;
}
static int F_89 ( struct V_2 * V_3 ,
unsigned int V_128 , unsigned int V_165 ,
unsigned int V_125 , T_13 V_166 , void * V_90 )
{
return 0 ;
}
static int F_90 ( struct V_2 * V_3 ,
unsigned int V_128 , unsigned int V_165 , unsigned int V_125 ,
T_13 V_166 , void * V_90 )
{
return 0 ;
}
static int F_91 ( struct V_2 * V_3 ,
unsigned int V_128 , unsigned int V_165 , unsigned int V_125 ,
T_13 V_166 , void * V_90 )
{
struct V_167 * V_168 ;
if ( V_166 & V_169 ) {
int V_170 = * ( int * ) V_90 ;
V_168 = F_92 ( V_170 ) ;
if ( F_93 ( V_168 ) ) {
F_55 ( L_16 ) ;
return F_57 ( V_168 ) ;
}
V_3 -> V_23 . V_171 = V_168 ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , T_13 V_166 ,
unsigned int V_128 , unsigned int V_165 , unsigned int V_125 ,
void * V_90 )
{
int (* F_95)( struct V_2 * V_3 , unsigned int V_128 ,
unsigned int V_165 , unsigned int V_125 , T_13 V_166 ,
void * V_90 ) = NULL ;
switch ( V_128 ) {
case V_163 :
switch ( V_166 & V_172 ) {
case V_173 :
F_95 = F_88 ;
break;
case V_174 :
F_95 = F_89 ;
break;
case V_175 :
F_95 = F_90 ;
break;
}
break;
case V_164 :
switch ( V_166 & V_172 ) {
case V_173 :
case V_174 :
break;
case V_175 :
F_95 = F_91 ;
break;
}
break;
}
if ( ! F_95 )
return - V_176 ;
return F_95 ( V_3 , V_128 , V_165 , V_125 , V_166 , V_90 ) ;
}
static long F_96 ( struct V_79 * V_37 , unsigned int V_177 ,
unsigned long V_178 )
{
struct V_2 * V_3 = F_63 ( V_37 ) ;
unsigned long V_179 ;
F_60 ( L_17 , V_3 -> V_180 , V_177 ) ;
if ( V_177 == V_181 ) {
struct V_182 V_70 ;
V_179 = F_97 ( struct V_182 , V_183 ) ;
if ( F_83 ( & V_70 , ( void T_9 * ) V_178 , V_179 ) )
return - V_14 ;
if ( V_70 . V_184 < V_179 )
return - V_80 ;
V_70 . V_166 = V_185 ;
V_70 . V_166 |= V_186 ;
V_70 . V_187 = V_130 ;
V_70 . V_183 = V_188 ;
return F_81 ( ( void T_9 * ) V_178 , & V_70 , V_179 ) ?
- V_14 : 0 ;
} else if ( V_177 == V_189 ) {
struct V_190 V_70 ;
struct V_191 V_192 = { . V_53 = NULL , . V_96 = 0 } ;
int V_46 , V_25 ;
struct V_193 * V_194 = NULL ;
T_7 V_96 ;
int V_195 = 1 ;
int V_196 ;
V_179 = F_97 ( struct V_190 , V_197 ) ;
if ( F_83 ( & V_70 , ( void T_9 * ) V_178 , V_179 ) )
return - V_14 ;
if ( V_70 . V_184 < V_179 )
return - V_80 ;
switch ( V_70 . V_128 ) {
case V_131 :
V_70 . V_197 = F_98 ( V_70 . V_128 ) ;
V_70 . V_96 = V_198 ;
V_70 . V_166 = V_199 |
V_200 ;
break;
case V_134 :
V_70 . V_197 = F_98 ( V_70 . V_128 ) ;
V_70 . V_96 = V_3 -> V_117 . V_201 [ V_70 . V_128 ] . V_96 ;
if ( ! V_70 . V_96 ) {
V_70 . V_166 = 0 ;
break;
}
V_70 . V_166 = V_199 |
V_200 ;
break;
case V_135 :
V_70 . V_197 = F_98 ( V_70 . V_128 ) ;
V_70 . V_96 = 0 ;
V_70 . V_166 = 0 ;
break;
case V_139 :
V_70 . V_197 = F_98 ( V_70 . V_128 ) ;
V_70 . V_166 = V_202 |
V_203 |
V_199 |
V_200 ;
V_70 . V_96 = F_99 ( V_3 -> V_9 ) ;
V_96 = sizeof( * V_194 ) +
( V_195 * sizeof( * V_194 -> V_204 ) ) ;
V_194 = F_16 ( V_96 , V_36 ) ;
if ( ! V_194 )
return - V_17 ;
V_194 -> V_195 = V_195 ;
V_196 = V_205 ;
V_194 -> V_204 [ 0 ] . V_197 =
F_100 ( F_101 ( V_3 ) ) ;
V_194 -> V_204 [ 0 ] . V_96 = F_102 ( V_3 ) ;
break;
case V_140 ... V_142 :
V_70 . V_197 = F_98 ( V_70 . V_128 ) ;
V_70 . V_96 = 0 ;
V_70 . V_166 = 0 ;
F_60 ( L_18 , V_70 . V_128 ) ;
break;
case V_144 :
case V_143 :
F_60 ( L_19 , V_70 . V_128 ) ;
break;
default:
{
struct V_206 V_207 ;
if ( V_70 . V_128 >= V_130 +
V_3 -> V_23 . V_187 )
return - V_80 ;
V_46 = V_70 . V_128 - V_130 ;
V_70 . V_197 =
F_98 ( V_70 . V_128 ) ;
V_70 . V_96 = V_3 -> V_23 . V_208 [ V_46 ] . V_96 ;
V_70 . V_166 = V_3 -> V_23 . V_208 [ V_46 ] . V_166 ;
V_207 . type = V_3 -> V_23 . V_208 [ V_46 ] . type ;
V_207 . V_209 = V_3 -> V_23 . V_208 [ V_46 ] . V_209 ;
V_25 = F_103 ( & V_192 ,
V_210 ,
& V_207 ) ;
if ( V_25 )
return V_25 ;
}
}
if ( ( V_70 . V_166 & V_202 ) && V_194 ) {
switch ( V_196 ) {
case V_205 :
V_25 = F_103 ( & V_192 ,
V_205 ,
V_194 ) ;
F_19 ( V_194 ) ;
if ( V_25 )
return V_25 ;
break;
default:
return - V_80 ;
}
}
if ( V_192 . V_96 ) {
if ( V_70 . V_184 < sizeof( V_70 ) + V_192 . V_96 ) {
V_70 . V_184 = sizeof( V_70 ) + V_192 . V_96 ;
V_70 . V_211 = 0 ;
} else {
F_104 ( & V_192 , sizeof( V_70 ) ) ;
if ( F_81 ( ( void T_9 * ) V_178 +
sizeof( V_70 ) , V_192 . V_53 ,
V_192 . V_96 ) ) {
F_19 ( V_192 . V_53 ) ;
return - V_14 ;
}
V_70 . V_211 = sizeof( V_70 ) ;
}
F_19 ( V_192 . V_53 ) ;
}
return F_81 ( ( void T_9 * ) V_178 , & V_70 , V_179 ) ?
- V_14 : 0 ;
} else if ( V_177 == V_212 ) {
struct V_213 V_70 ;
V_179 = F_97 ( struct V_213 , V_125 ) ;
if ( F_83 ( & V_70 , ( void T_9 * ) V_178 , V_179 ) )
return - V_14 ;
if ( V_70 . V_184 < V_179 || V_70 . V_128 >= V_188 )
return - V_80 ;
switch ( V_70 . V_128 ) {
case V_163 :
case V_164 :
break;
default:
return - V_80 ;
}
V_70 . V_166 = V_214 ;
V_70 . V_125 = F_87 ( V_3 , V_70 . V_128 ) ;
if ( V_70 . V_128 == V_163 )
V_70 . V_166 |= ( V_215 |
V_216 ) ;
else
V_70 . V_166 |= V_217 ;
return F_81 ( ( void T_9 * ) V_178 , & V_70 , V_179 ) ?
- V_14 : 0 ;
} else if ( V_177 == V_218 ) {
struct V_219 V_220 ;
T_11 * V_90 = NULL ;
int V_25 = 0 ;
T_7 V_221 = 0 ;
V_179 = F_97 ( struct V_219 , V_125 ) ;
if ( F_83 ( & V_220 , ( void T_9 * ) V_178 , V_179 ) )
return - V_14 ;
if ( ! ( V_220 . V_166 & V_222 ) ) {
int V_223 = F_87 ( V_3 , V_220 . V_128 ) ;
V_25 = F_105 ( & V_220 , V_223 ,
V_188 , & V_221 ) ;
if ( V_25 ) {
F_55 ( L_20 ) ;
return - V_80 ;
}
if ( V_221 ) {
V_90 = F_106 ( ( void T_9 * ) ( V_178 + V_179 ) ,
V_221 ) ;
if ( F_93 ( V_90 ) )
return F_57 ( V_90 ) ;
}
}
V_25 = F_94 ( V_3 , V_220 . V_166 , V_220 . V_128 ,
V_220 . V_165 , V_220 . V_125 , V_90 ) ;
F_19 ( V_90 ) ;
return V_25 ;
} else if ( V_177 == V_224 ) {
V_81 -> V_225 ( V_3 ) ;
return 0 ;
}
return 0 ;
}
static T_4
F_107 ( struct V_7 * V_8 , struct V_226 * V_227 ,
char * V_53 )
{
struct V_79 * V_37 = F_108 ( V_8 ) ;
if ( V_37 ) {
struct V_2 * V_3 = (struct V_2 * )
F_63 ( V_37 ) ;
return sprintf ( V_53 , L_21 , V_3 -> V_180 ) ;
}
return sprintf ( V_53 , L_22 ) ;
}
static T_4
F_109 ( struct V_7 * V_8 , struct V_226 * V_227 ,
char * V_53 )
{
struct V_79 * V_37 = F_108 ( V_8 ) ;
if ( V_37 ) {
struct V_2 * V_3 = (struct V_2 * )
F_63 ( V_37 ) ;
return sprintf ( V_53 , L_1 ,
V_3 -> V_228 -> V_229 ) ;
}
return sprintf ( V_53 , L_22 ) ;
}
static int F_110 ( struct V_7 * V_8 , void * V_9 , const void * V_230 )
{
if ( ! F_39 ( V_9 ) )
return - V_14 ;
V_81 = V_230 ;
return F_111 ( V_8 , & V_231 ) ;
}
static void F_112 ( struct V_7 * V_8 , void * V_9 )
{
F_40 ( V_9 ) ;
F_113 ( V_8 ) ;
}
static int F_114 ( unsigned long V_1 , V_124 V_20 )
{
struct V_69 * V_70 ;
struct V_100 * V_100 ;
struct V_232 * V_233 ;
int V_234 ;
if ( ! F_1 ( V_1 ) )
return - V_235 ;
V_70 = (struct V_69 * ) V_1 ;
V_100 = V_70 -> V_100 ;
V_234 = F_115 ( & V_100 -> V_236 ) ;
V_233 = F_116 ( V_100 , V_20 ) ;
if ( ! V_233 ) {
F_117 ( & V_100 -> V_236 , V_234 ) ;
return - V_80 ;
}
F_118 ( & V_100 -> V_237 ) ;
if ( F_48 ( V_70 , V_20 ) )
goto V_29;
F_119 ( V_100 , V_233 , V_20 , V_238 ) ;
F_49 ( V_70 , V_20 ) ;
V_29:
F_120 ( & V_100 -> V_237 ) ;
F_117 ( & V_100 -> V_236 , V_234 ) ;
return 0 ;
}
static int F_121 ( unsigned long V_1 , V_124 V_20 )
{
struct V_69 * V_70 ;
struct V_100 * V_100 ;
struct V_232 * V_233 ;
int V_234 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
V_70 = (struct V_69 * ) V_1 ;
V_100 = V_70 -> V_100 ;
V_234 = F_115 ( & V_100 -> V_236 ) ;
V_233 = F_116 ( V_100 , V_20 ) ;
if ( ! V_233 ) {
F_117 ( & V_100 -> V_236 , V_234 ) ;
return - V_80 ;
}
F_118 ( & V_100 -> V_237 ) ;
if ( ! F_48 ( V_70 , V_20 ) )
goto V_29;
F_122 ( V_100 , V_233 , V_20 , V_238 ) ;
F_52 ( V_70 , V_20 ) ;
V_29:
F_120 ( & V_100 -> V_237 ) ;
F_117 ( & V_100 -> V_236 , V_234 ) ;
return 0 ;
}
static void F_123 ( struct V_239 * V_240 , T_14 V_241 ,
const T_11 * V_147 , int V_242 ,
struct V_243 * V_22 )
{
struct V_69 * V_70 = F_65 ( V_22 ,
struct V_69 , V_244 ) ;
if ( F_48 ( V_70 , F_124 ( V_241 ) ) )
V_81 -> V_137 ( V_70 -> V_3 , V_241 ,
( void * ) V_147 , V_242 ) ;
}
static void F_125 ( struct V_100 * V_100 ,
struct V_232 * V_233 ,
struct V_243 * V_22 )
{
int V_46 ;
T_3 V_20 ;
struct V_69 * V_70 = F_65 ( V_22 ,
struct V_69 , V_244 ) ;
F_118 ( & V_100 -> V_237 ) ;
for ( V_46 = 0 ; V_46 < V_233 -> V_245 ; V_46 ++ ) {
V_20 = V_233 -> V_246 + V_46 ;
if ( F_48 ( V_70 , V_20 ) ) {
F_122 ( V_100 , V_233 , V_20 ,
V_238 ) ;
F_52 ( V_70 , V_20 ) ;
}
}
F_120 ( & V_100 -> V_237 ) ;
}
static bool F_126 ( struct V_2 * V_3 , struct V_100 * V_100 )
{
struct V_2 * V_26 ;
struct V_69 * V_70 ;
int V_180 ;
bool V_25 = false ;
F_13 ( & V_3 -> V_9 -> V_247 ) ;
F_127 (vgpu->gvt, itr, id) {
if ( ! F_1 ( V_26 -> V_1 ) )
continue;
V_70 = (struct V_69 * ) V_26 -> V_1 ;
if ( V_100 && V_100 == V_70 -> V_100 ) {
V_25 = true ;
goto V_29;
}
}
V_29:
F_14 ( & V_3 -> V_9 -> V_247 ) ;
return V_25 ;
}
static int F_70 ( struct V_79 * V_37 )
{
struct V_69 * V_70 ;
struct V_2 * V_3 ;
struct V_100 * V_100 ;
V_3 = F_63 ( V_37 ) ;
if ( F_1 ( V_3 -> V_1 ) )
return - V_248 ;
V_100 = V_3 -> V_23 . V_100 ;
if ( ! V_100 || V_100 -> V_249 != V_250 -> V_249 ) {
F_55 ( L_23 ) ;
return - V_235 ;
}
if ( F_126 ( V_3 , V_100 ) )
return - V_248 ;
V_70 = F_128 ( sizeof( struct V_69 ) ) ;
if ( ! V_70 )
return - V_17 ;
V_3 -> V_1 = ( unsigned long ) V_70 ;
V_70 -> V_3 = V_3 ;
V_70 -> V_100 = V_100 ;
F_129 ( V_70 -> V_100 ) ;
F_41 ( V_70 ) ;
F_26 ( V_3 ) ;
V_70 -> V_244 . V_251 = F_123 ;
V_70 -> V_244 . V_252 = F_125 ;
F_130 ( V_100 , & V_70 -> V_244 ) ;
return 0 ;
}
static bool F_75 ( struct V_69 * V_70 )
{
F_131 ( V_70 -> V_100 , & V_70 -> V_244 ) ;
F_132 ( V_70 -> V_100 ) ;
F_43 ( V_70 ) ;
F_28 ( V_70 -> V_3 ) ;
F_133 ( V_70 ) ;
return true ;
}
static int F_134 ( void * V_3 , unsigned long * V_1 )
{
return 0 ;
}
static void F_135 ( unsigned long V_1 )
{
}
static int F_136 ( unsigned long V_1 , T_6 V_253 , T_10 V_90 )
{
struct V_69 * V_70 ;
struct V_2 * V_3 ;
if ( ! F_1 ( V_1 ) )
return - V_235 ;
V_70 = (struct V_69 * ) V_1 ;
V_3 = V_70 -> V_3 ;
if ( F_137 ( V_3 -> V_23 . V_171 , 1 ) == 1 )
return 0 ;
return - V_14 ;
}
static unsigned long F_138 ( unsigned long V_1 , unsigned long V_20 )
{
unsigned long V_5 , V_4 ;
struct V_69 * V_70 ;
struct V_7 * V_8 ;
struct V_2 * V_3 ;
int V_40 ;
if ( ! F_1 ( V_1 ) )
return V_32 ;
V_70 = (struct V_69 * ) V_1 ;
V_3 = V_70 -> V_3 ;
V_5 = F_12 ( V_70 -> V_3 , V_20 ) ;
if ( V_5 != V_32 )
return V_5 ;
V_4 = V_32 ;
V_8 = F_23 ( V_70 -> V_3 -> V_23 . V_37 ) ;
V_40 = F_139 ( V_8 , & V_20 , 1 , V_254 | V_255 , & V_4 ) ;
if ( V_40 != 1 ) {
F_55 ( L_24 ,
V_20 , V_40 ) ;
return V_32 ;
}
V_40 = F_2 ( V_70 -> V_3 , V_4 , & V_5 ) ;
if ( V_40 ) {
F_55 ( L_25 , V_20 ) ;
F_24 ( V_8 , & V_20 , 1 ) ;
return V_32 ;
}
F_15 ( V_70 -> V_3 , V_20 , V_5 ) ;
return V_5 ;
}
static int F_140 ( unsigned long V_1 , unsigned long V_241 ,
void * V_53 , unsigned long V_242 , bool V_256 )
{
struct V_69 * V_70 ;
struct V_100 * V_100 ;
int V_234 , V_25 ;
bool V_257 = V_250 -> V_249 == NULL ;
if ( ! F_1 ( V_1 ) )
return - V_235 ;
V_70 = (struct V_69 * ) V_1 ;
V_100 = V_70 -> V_100 ;
if ( V_257 )
F_141 ( V_100 -> V_249 ) ;
V_234 = F_115 ( & V_100 -> V_236 ) ;
V_25 = V_256 ? F_142 ( V_100 , V_241 , V_53 , V_242 ) :
F_143 ( V_100 , V_241 , V_53 , V_242 ) ;
F_117 ( & V_100 -> V_236 , V_234 ) ;
if ( V_257 )
F_144 ( V_100 -> V_249 ) ;
return V_25 ;
}
static int F_145 ( unsigned long V_1 , unsigned long V_241 ,
void * V_53 , unsigned long V_242 )
{
return F_140 ( V_1 , V_241 , V_53 , V_242 , false ) ;
}
static int F_146 ( unsigned long V_1 , unsigned long V_241 ,
void * V_53 , unsigned long V_242 )
{
return F_140 ( V_1 , V_241 , V_53 , V_242 , true ) ;
}
static unsigned long F_147 ( void * V_253 )
{
return F_148 ( F_149 ( V_253 ) ) ;
}
static int T_15 F_150 ( void )
{
return 0 ;
}
static void T_16 F_151 ( void )
{
}
