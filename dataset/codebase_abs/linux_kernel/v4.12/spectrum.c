int F_1 ( struct V_1 * V_1 ,
unsigned int V_2 , T_1 * V_3 ,
T_1 * V_4 )
{
char V_5 [ V_6 ] ;
int V_7 ;
F_2 ( V_5 , V_2 , V_8 ,
V_9 ) ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_11 ) , V_5 ) ;
if ( V_7 )
return V_7 ;
* V_3 = F_5 ( V_5 ) ;
* V_4 = F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 ,
unsigned int V_2 )
{
char V_5 [ V_6 ] ;
F_2 ( V_5 , V_2 , V_12 ,
V_9 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_11 ) , V_5 ) ;
}
int F_9 ( struct V_1 * V_1 ,
unsigned int * V_13 )
{
int V_7 ;
V_7 = F_10 ( V_1 , V_14 ,
V_13 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( V_1 , * V_13 ) ;
if ( V_7 )
goto V_15;
return 0 ;
V_15:
F_11 ( V_1 , V_14 ,
* V_13 ) ;
return V_7 ;
}
void F_12 ( struct V_1 * V_1 ,
unsigned int V_2 )
{
F_11 ( V_1 , V_14 ,
V_2 ) ;
}
static void F_13 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
char * V_20 = F_14 ( V_17 , V_21 ) ;
memset ( V_20 , 0 , V_21 ) ;
F_15 ( V_20 , V_22 ) ;
F_16 ( V_20 , V_23 ) ;
F_17 ( V_20 , V_24 ) ;
F_18 ( V_20 , 0 ) ;
F_19 ( V_20 , 1 ) ;
F_20 ( V_20 , V_19 -> V_25 ) ;
F_21 ( V_20 , V_26 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
char V_27 [ V_28 ] = { 0 } ;
int V_7 ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_29 ) , V_27 ) ;
if ( V_7 )
return V_7 ;
F_23 ( V_27 , V_1 -> V_30 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 )
{
int V_31 ;
if ( ! F_25 ( V_1 -> V_10 , V_32 ) )
return - V_33 ;
V_1 -> V_34 . V_35 = F_26 ( V_1 -> V_10 ,
V_32 ) ;
V_1 -> V_34 . V_36 = F_27 ( V_1 -> V_34 . V_35 ,
sizeof( struct V_37 ) ,
V_38 ) ;
if ( ! V_1 -> V_34 . V_36 )
return - V_39 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_34 . V_35 ; V_31 ++ )
F_28 ( & V_1 -> V_34 . V_36 [ V_31 ] . V_40 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_1 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_34 . V_35 ; V_31 ++ ) {
struct V_37 * V_41 = & V_1 -> V_34 . V_36 [ V_31 ] ;
F_30 ( ! F_31 ( & V_41 -> V_40 ) ) ;
}
F_32 ( V_1 -> V_34 . V_36 ) ;
}
static struct V_37 *
F_33 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = V_43 -> V_1 ;
struct V_37 * V_44 ;
char V_45 [ V_46 ] ;
T_2 V_25 = V_43 -> V_25 ;
int V_47 ;
int V_31 ;
int V_7 ;
V_47 = - 1 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_34 . V_35 ; V_31 ++ ) {
if ( ! V_1 -> V_34 . V_36 [ V_31 ] . V_48 ) {
V_47 = V_31 ;
V_44 = & V_1 -> V_34 . V_36 [ V_31 ] ;
break;
}
}
if ( V_47 < 0 )
return NULL ;
F_34 ( V_45 , V_47 , V_25 , true ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_49 ) , V_45 ) ;
if ( V_7 )
return NULL ;
V_44 -> V_48 = true ;
V_44 -> V_50 = V_47 ;
V_44 -> V_51 = 1 ;
V_44 -> V_25 = V_25 ;
return V_44 ;
}
static void F_35 ( struct V_1 * V_1 ,
struct V_37 * V_44 )
{
T_2 V_25 = V_44 -> V_25 ;
char V_45 [ V_46 ] ;
int V_52 = V_44 -> V_50 ;
F_34 ( V_45 , V_52 , V_25 , false ) ;
F_8 ( V_1 -> V_10 , F_4 ( V_49 ) , V_45 ) ;
V_44 -> V_48 = false ;
}
static struct V_37 *
F_36 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = V_43 -> V_1 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_34 . V_35 ; V_31 ++ ) {
struct V_37 * V_41 = & V_1 -> V_34 . V_36 [ V_31 ] ;
if ( V_41 -> V_48 && V_41 -> V_25 == V_43 -> V_25 )
return V_41 ;
}
return NULL ;
}
static struct V_37
* F_37 ( struct V_42 * V_43 )
{
struct V_37 * V_44 ;
V_44 = F_36 ( V_43 ) ;
if ( V_44 ) {
V_44 -> V_51 ++ ;
return V_44 ;
}
return F_33 ( V_43 ) ;
}
static int F_38 ( struct V_1 * V_1 ,
struct V_37 * V_44 )
{
F_39 ( ! V_44 -> V_51 ) ;
if ( -- V_44 -> V_51 == 0 )
F_35 ( V_1 , V_44 ) ;
return 0 ;
}
static bool F_40 ( struct V_42 * V_43 )
{
struct V_1 * V_1 = V_43 -> V_1 ;
struct V_53 * V_54 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_1 -> V_34 . V_35 ; V_31 ++ ) {
struct V_37 * V_41 = & V_1 -> V_34 . V_36 [ V_31 ] ;
F_41 (p, &curr->bound_ports_list, list)
if ( V_54 -> V_25 == V_43 -> V_25 &&
V_54 -> type == V_55 )
return true ;
}
return false ;
}
static int F_42 ( const struct V_1 * V_1 ,
int V_56 )
{
return F_43 ( V_1 , V_56 * 5 / 2 ) + 1 ;
}
static int F_44 ( struct V_42 * V_43 , T_3 V_56 )
{
struct V_1 * V_1 = V_43 -> V_1 ;
char V_57 [ V_58 ] ;
int V_7 ;
if ( F_40 ( V_43 ) ) {
T_4 V_59 = F_42 ( V_1 , V_56 ) ;
F_45 ( V_57 , V_43 -> V_25 , V_59 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_60 ) , V_57 ) ;
if ( V_7 ) {
F_46 ( V_43 -> V_61 , L_1 ) ;
return V_7 ;
}
}
return 0 ;
}
static struct V_53 *
F_47 ( struct V_42 * V_43 ,
struct V_37 * V_44 )
{
struct V_53 * V_54 ;
F_41 (p, &span_entry->bound_ports_list, list)
if ( V_43 -> V_25 == V_54 -> V_25 )
return V_54 ;
return NULL ;
}
static int
F_48 ( struct V_42 * V_43 ,
struct V_37 * V_44 ,
enum V_62 type )
{
struct V_53 * V_63 ;
struct V_1 * V_1 = V_43 -> V_1 ;
char V_64 [ V_65 ] ;
char V_57 [ V_58 ] ;
int V_52 = V_44 -> V_50 ;
int V_7 ;
if ( type == V_55 ) {
T_4 V_59 = F_42 ( V_1 ,
V_43 -> V_61 -> V_56 ) ;
F_45 ( V_57 , V_43 -> V_25 , V_59 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_60 ) , V_57 ) ;
if ( V_7 ) {
F_46 ( V_43 -> V_61 , L_2 ) ;
return V_7 ;
}
}
F_49 ( V_64 , V_43 -> V_25 ,
(enum V_66 ) type , true , V_52 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_67 ) , V_64 ) ;
if ( V_7 )
goto V_68;
V_63 = F_50 ( sizeof( * V_63 ) , V_38 ) ;
if ( ! V_63 ) {
V_7 = - V_39 ;
goto V_69;
}
V_63 -> V_25 = V_43 -> V_25 ;
V_63 -> type = type ;
F_51 ( & V_63 -> V_70 , & V_44 -> V_40 ) ;
return 0 ;
V_68:
V_69:
if ( type == V_55 ) {
F_45 ( V_57 , V_43 -> V_25 , 0 ) ;
F_8 ( V_1 -> V_10 , F_4 ( V_60 ) , V_57 ) ;
}
return V_7 ;
}
static void
F_52 ( struct V_42 * V_43 ,
struct V_37 * V_44 ,
enum V_62 type )
{
struct V_53 * V_63 ;
struct V_1 * V_1 = V_43 -> V_1 ;
char V_64 [ V_65 ] ;
char V_57 [ V_58 ] ;
int V_52 = V_44 -> V_50 ;
V_63 = F_47 ( V_43 , V_44 ) ;
if ( ! V_63 )
return;
F_49 ( V_64 , V_43 -> V_25 ,
(enum V_66 ) type , false , V_52 ) ;
F_8 ( V_1 -> V_10 , F_4 ( V_67 ) , V_64 ) ;
if ( type == V_55 ) {
F_45 ( V_57 , V_43 -> V_25 , 0 ) ;
F_8 ( V_1 -> V_10 , F_4 ( V_60 ) , V_57 ) ;
}
F_38 ( V_1 , V_44 ) ;
F_53 ( & V_63 -> V_70 ) ;
F_32 ( V_63 ) ;
}
static int F_54 ( struct V_42 * V_71 ,
struct V_42 * V_72 ,
enum V_62 type )
{
struct V_1 * V_1 = V_71 -> V_1 ;
struct V_37 * V_44 ;
int V_7 ;
V_44 = F_37 ( V_72 ) ;
if ( ! V_44 )
return - V_73 ;
F_55 ( V_71 -> V_61 , L_3 ,
V_44 -> V_50 ) ;
V_7 = F_48 ( V_71 , V_44 , type ) ;
if ( V_7 )
goto V_74;
return 0 ;
V_74:
F_38 ( V_1 , V_44 ) ;
return V_7 ;
}
static void F_56 ( struct V_42 * V_71 ,
struct V_42 * V_72 ,
enum V_62 type )
{
struct V_37 * V_44 ;
V_44 = F_36 ( V_72 ) ;
if ( ! V_44 ) {
F_46 ( V_71 -> V_61 , L_4 ) ;
return;
}
F_55 ( V_71 -> V_61 , L_5 ,
V_44 -> V_50 ) ;
F_52 ( V_71 , V_44 , type ) ;
}
static int F_57 ( struct V_42 * V_42 ,
bool V_75 , T_4 V_76 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_77 [ V_78 ] ;
F_58 ( V_77 , V_42 -> V_25 , V_75 , V_76 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_79 ) , V_77 ) ;
}
static int F_59 ( struct V_42 * V_42 ,
bool V_80 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_81 [ V_82 ] ;
F_60 ( V_81 , V_42 -> V_25 ,
V_80 ? V_83 :
V_84 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_85 ) , V_81 ) ;
}
static int F_61 ( struct V_42 * V_42 ,
unsigned char * V_86 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_87 [ V_88 ] ;
F_62 ( V_87 , true , V_42 -> V_25 ) ;
F_63 ( V_87 , V_86 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_89 ) , V_87 ) ;
}
static int F_64 ( struct V_42 * V_42 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
unsigned char * V_86 = V_42 -> V_61 -> V_90 ;
F_65 ( V_86 , V_1 -> V_30 ) ;
V_86 [ V_91 - 1 ] += V_42 -> V_25 ;
return F_61 ( V_42 , V_86 ) ;
}
static int F_66 ( struct V_42 * V_42 , T_3 V_56 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_92 [ V_93 ] ;
int V_94 ;
int V_7 ;
V_56 += V_21 + V_95 ;
F_67 ( V_92 , V_42 -> V_25 , 0 ) ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_96 ) , V_92 ) ;
if ( V_7 )
return V_7 ;
V_94 = F_68 ( V_92 ) ;
if ( V_56 > V_94 )
return - V_97 ;
F_67 ( V_92 , V_42 -> V_25 , V_56 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_96 ) , V_92 ) ;
}
static int F_69 ( struct V_1 * V_1 , T_2 V_25 ,
T_2 V_98 )
{
char V_99 [ V_100 ] ;
F_70 ( V_99 , V_98 , V_25 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_101 ) , V_99 ) ;
}
static int F_71 ( struct V_42 * V_42 , T_2 V_98 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
return F_69 ( V_1 , V_42 -> V_25 ,
V_98 ) ;
}
static int F_72 ( struct V_42 * V_42 ,
bool V_75 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_102 [ V_103 ] ;
F_73 ( V_102 , V_42 -> V_25 , V_75 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_104 ) , V_102 ) ;
}
int F_74 ( struct V_42 * V_42 ,
enum V_105 V_106 , bool V_107 , T_3 V_108 ,
T_3 V_109 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_110 [ V_111 ] ;
F_75 ( V_110 , V_42 -> V_25 , V_106 , V_107 ,
V_108 , V_109 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_112 ) , V_110 ) ;
}
int F_76 ( struct V_42 * V_42 ,
T_3 V_113 , T_3 V_114 ,
bool V_115 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char * V_116 ;
int V_7 ;
V_116 = F_77 ( V_117 , V_38 ) ;
if ( ! V_116 )
return - V_39 ;
F_78 ( V_116 , V_42 -> V_25 , V_113 ,
V_114 , V_115 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_118 ) , V_116 ) ;
F_32 ( V_116 ) ;
return V_7 ;
}
static int F_79 ( struct V_42 * V_42 ,
T_3 V_109 , bool V_115 )
{
return F_76 ( V_42 , V_109 , V_109 ,
V_115 ) ;
}
static int
F_80 ( struct V_42 * V_42 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_119 [ V_120 ] ;
F_81 ( V_119 , V_42 -> V_25 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_121 ) , V_119 ) ;
}
static int F_82 ( struct V_1 * V_1 ,
T_2 V_25 , T_2 * V_122 ,
T_2 * V_123 , T_2 * V_124 )
{
char V_125 [ V_126 ] ;
int V_7 ;
F_83 ( V_125 , V_25 ) ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_127 ) , V_125 ) ;
if ( V_7 )
return V_7 ;
* V_122 = F_84 ( V_125 , 0 ) ;
* V_123 = F_85 ( V_125 ) ;
* V_124 = F_86 ( V_125 , 0 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_1 , T_2 V_25 ,
T_2 V_128 , T_2 V_129 , T_2 V_130 )
{
char V_125 [ V_126 ] ;
int V_31 ;
F_83 ( V_125 , V_25 ) ;
F_88 ( V_125 , V_129 ) ;
for ( V_31 = 0 ; V_31 < V_129 ; V_31 ++ ) {
F_89 ( V_125 , V_31 , V_128 ) ;
F_90 ( V_125 , V_31 , V_130 + V_31 ) ;
}
return F_8 ( V_1 -> V_10 , F_4 ( V_127 ) , V_125 ) ;
}
static int F_91 ( struct V_1 * V_1 , T_2 V_25 )
{
char V_125 [ V_126 ] ;
F_83 ( V_125 , V_25 ) ;
F_88 ( V_125 , 0 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_127 ) , V_125 ) ;
}
static int F_92 ( struct V_131 * V_61 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
int V_7 ;
V_7 = F_59 ( V_42 , true ) ;
if ( V_7 )
return V_7 ;
F_94 ( V_61 ) ;
return 0 ;
}
static int F_95 ( struct V_131 * V_61 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
F_96 ( V_61 ) ;
return F_59 ( V_42 , false ) ;
}
static T_5 F_97 ( struct V_16 * V_17 ,
struct V_131 * V_61 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
struct V_132 * V_133 ;
const struct V_18 V_19 = {
. V_25 = V_42 -> V_25 ,
. V_134 = false ,
} ;
T_1 V_135 ;
int V_7 ;
if ( F_98 ( V_1 -> V_10 , & V_19 ) )
return V_136 ;
if ( F_99 ( F_100 ( V_17 ) < V_21 ) ) {
struct V_16 * V_137 = V_17 ;
V_17 = F_101 ( V_17 , V_21 ) ;
if ( ! V_17 ) {
F_102 ( V_42 -> V_133 -> V_138 ) ;
F_103 ( V_137 ) ;
return V_139 ;
}
F_104 ( V_137 ) ;
}
if ( F_105 ( V_17 ) ) {
F_102 ( V_42 -> V_133 -> V_138 ) ;
return V_139 ;
}
F_13 ( V_17 , & V_19 ) ;
V_135 = V_17 -> V_135 - V_21 ;
V_7 = F_106 ( V_1 -> V_10 , V_17 , & V_19 ) ;
if ( ! V_7 ) {
V_133 = F_107 ( V_42 -> V_133 ) ;
F_108 ( & V_133 -> V_140 ) ;
V_133 -> V_141 ++ ;
V_133 -> V_142 += V_135 ;
F_109 ( & V_133 -> V_140 ) ;
} else {
F_102 ( V_42 -> V_133 -> V_138 ) ;
F_103 ( V_17 ) ;
}
return V_139 ;
}
static void F_110 ( struct V_131 * V_61 )
{
}
static int F_111 ( struct V_131 * V_61 , void * V_54 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_143 * V_86 = V_54 ;
int V_7 ;
if ( ! F_112 ( V_86 -> V_144 ) )
return - V_145 ;
V_7 = F_61 ( V_42 , V_86 -> V_144 ) ;
if ( V_7 )
return V_7 ;
memcpy ( V_61 -> V_90 , V_86 -> V_144 , V_61 -> V_146 ) ;
return 0 ;
}
static T_3 F_113 ( const struct V_1 * V_1 ,
int V_56 )
{
return 2 * F_43 ( V_1 , V_56 ) ;
}
static T_3 F_114 ( const struct V_1 * V_1 , int V_56 ,
T_3 V_147 )
{
V_147 = F_43 ( V_1 , F_115 ( V_147 ,
V_148 ) ) ;
return V_149 * V_147 + F_43 ( V_1 ,
V_56 ) ;
}
static T_3 F_116 ( const struct V_1 * V_1 , int V_56 ,
T_3 V_147 , bool V_150 , bool V_151 )
{
if ( V_150 )
return F_114 ( V_1 , V_56 , V_147 ) ;
else if ( V_151 )
return F_43 ( V_1 , V_152 ) ;
else
return 0 ;
}
static void F_117 ( char * V_153 , int V_47 , T_3 V_154 , T_3 V_155 ,
bool V_156 )
{
if ( V_156 )
F_118 ( V_153 , V_47 , V_154 ) ;
else
F_119 ( V_153 , V_47 , V_154 ,
V_155 ) ;
}
int F_120 ( struct V_42 * V_42 , int V_56 ,
T_2 * V_157 , bool V_158 ,
struct V_159 * V_160 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
T_2 V_161 = ! ! V_160 ? V_160 -> V_161 : 0 ;
T_3 V_147 = ! ! V_160 ? V_160 -> V_147 : 0 ;
char V_153 [ V_162 ] ;
int V_31 , V_163 , V_7 ;
F_121 ( V_153 , V_42 -> V_25 , 0 , 0 ) ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_164 ) , V_153 ) ;
if ( V_7 )
return V_7 ;
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
bool V_166 = false ;
bool V_150 = false ;
bool V_156 ;
T_3 V_155 ;
for ( V_163 = 0 ; V_163 < V_165 ; V_163 ++ ) {
if ( V_157 [ V_163 ] == V_31 ) {
V_150 = V_161 & F_122 ( V_163 ) ;
V_166 = true ;
break;
}
}
if ( ! V_166 )
continue;
V_156 = ! ( V_150 || V_158 ) ;
V_155 = F_113 ( V_1 , V_56 ) ;
V_147 = F_116 ( V_1 , V_56 , V_147 , V_150 ,
V_158 ) ;
F_117 ( V_153 , V_31 , V_155 + V_147 , V_155 , V_156 ) ;
}
return F_8 ( V_1 -> V_10 , F_4 ( V_164 ) , V_153 ) ;
}
static int F_123 ( struct V_42 * V_42 ,
int V_56 , bool V_158 )
{
T_2 V_167 [ V_165 ] = { 0 } ;
bool V_168 = ! ! V_42 -> V_169 . V_170 ;
struct V_159 * V_160 ;
T_2 * V_157 ;
V_157 = V_168 ? V_42 -> V_169 . V_170 -> V_157 : V_167 ;
V_160 = V_168 ? V_42 -> V_169 . V_150 : NULL ;
return F_120 ( V_42 , V_56 , V_157 ,
V_158 , V_160 ) ;
}
static int F_124 ( struct V_131 * V_61 , int V_56 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
bool V_158 = F_125 ( V_42 ) ;
int V_7 ;
V_7 = F_123 ( V_42 , V_56 , V_158 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_44 ( V_42 , V_56 ) ;
if ( V_7 )
goto V_171;
V_7 = F_66 ( V_42 , V_56 ) ;
if ( V_7 )
goto V_172;
V_61 -> V_56 = V_56 ;
return 0 ;
V_172:
F_44 ( V_42 , V_61 -> V_56 ) ;
V_171:
F_123 ( V_42 , V_61 -> V_56 , V_158 ) ;
return V_7 ;
}
static int
F_126 ( const struct V_131 * V_61 ,
struct V_173 * V_174 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_132 * V_54 ;
T_1 V_175 , V_176 , V_141 , V_142 ;
T_4 V_138 = 0 ;
unsigned int V_177 ;
int V_31 ;
F_127 (i) {
V_54 = F_128 ( V_42 -> V_133 , V_31 ) ;
do {
V_177 = F_129 ( & V_54 -> V_140 ) ;
V_175 = V_54 -> V_175 ;
V_176 = V_54 -> V_176 ;
V_141 = V_54 -> V_141 ;
V_142 = V_54 -> V_142 ;
} while ( F_130 ( & V_54 -> V_140 , V_177 ) );
V_174 -> V_175 += V_175 ;
V_174 -> V_176 += V_176 ;
V_174 -> V_141 += V_141 ;
V_174 -> V_142 += V_142 ;
V_138 += V_54 -> V_138 ;
}
V_174 -> V_138 = V_138 ;
return 0 ;
}
static bool F_131 ( const struct V_131 * V_61 , int V_178 )
{
switch ( V_178 ) {
case V_179 :
return true ;
}
return false ;
}
static int F_132 ( int V_178 , const struct V_131 * V_61 ,
void * V_180 )
{
switch ( V_178 ) {
case V_179 :
return F_126 ( V_61 , V_180 ) ;
}
return - V_97 ;
}
static int F_133 ( struct V_131 * V_61 , int V_181 ,
int V_182 , char * V_183 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
F_134 ( V_183 , V_42 -> V_25 , V_181 , V_182 ) ;
return F_3 ( V_1 -> V_10 , F_4 ( V_184 ) , V_183 ) ;
}
static int F_135 ( struct V_131 * V_61 ,
struct V_173 * V_174 )
{
char V_183 [ V_185 ] ;
int V_7 ;
V_7 = F_133 ( V_61 , V_186 ,
0 , V_183 ) ;
if ( V_7 )
goto V_187;
V_174 -> V_141 =
F_136 ( V_183 ) ;
V_174 -> V_175 =
F_137 ( V_183 ) ;
V_174 -> V_142 =
F_138 ( V_183 ) ;
V_174 -> V_176 =
F_139 ( V_183 ) ;
V_174 -> V_188 =
F_140 ( V_183 ) ;
V_174 -> V_189 =
F_141 ( V_183 ) ;
V_174 -> V_190 =
F_142 ( V_183 ) ;
V_174 -> V_191 = (
F_143 ( V_183 ) +
F_144 ( V_183 ) +
F_145 ( V_183 ) ) ;
V_174 -> V_192 = ( V_174 -> V_189 +
V_174 -> V_190 + V_174 -> V_191 ) ;
V_187:
return V_7 ;
}
static void F_146 ( struct V_193 * V_194 )
{
struct V_42 * V_42 =
F_147 ( V_194 , struct V_42 ,
V_195 . V_196 . V_194 ) ;
if ( ! F_148 ( V_42 -> V_61 ) )
goto V_187;
F_135 ( V_42 -> V_61 ,
V_42 -> V_195 . V_197 ) ;
V_187:
F_149 ( & V_42 -> V_195 . V_196 ,
V_198 ) ;
}
static void
F_150 ( struct V_131 * V_61 ,
struct V_173 * V_174 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
memcpy ( V_174 , V_42 -> V_195 . V_197 , sizeof( * V_174 ) ) ;
}
static int F_151 ( struct V_42 * V_42 ,
T_3 V_113 , T_3 V_114 ,
bool V_199 , bool V_200 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char * V_201 ;
int V_7 ;
V_201 = F_77 ( V_202 , V_38 ) ;
if ( ! V_201 )
return - V_39 ;
F_152 ( V_201 , V_42 -> V_25 , V_113 ,
V_114 , V_199 , V_200 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_203 ) , V_201 ) ;
F_32 ( V_201 ) ;
return V_7 ;
}
int F_153 ( struct V_42 * V_42 , T_3 V_113 ,
T_3 V_114 , bool V_199 , bool V_200 )
{
T_3 V_109 , V_204 ;
int V_7 ;
for ( V_109 = V_113 ; V_109 <= V_114 ;
V_109 += V_205 ) {
V_204 = F_154 ( ( T_3 ) ( V_109 + V_205 - 1 ) ,
V_114 ) ;
V_7 = F_151 ( V_42 , V_109 , V_204 ,
V_199 , V_200 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_155 ( struct V_42 * V_42 )
{
enum V_105 V_106 = V_206 ;
T_3 V_109 , V_207 ;
int V_7 ;
F_156 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_7 = F_74 ( V_42 , V_106 , true , V_109 ,
V_109 ) ;
if ( V_7 ) {
V_207 = V_109 ;
goto V_208;
}
}
V_7 = F_72 ( V_42 , true ) ;
if ( V_7 ) {
V_207 = V_209 ;
goto V_208;
}
return 0 ;
V_208:
F_156 (vid, mlxsw_sp_port->active_vlans, last_visited_vid)
F_74 ( V_42 , V_106 , false , V_109 ,
V_109 ) ;
return V_7 ;
}
static int F_157 ( struct V_42 * V_42 )
{
enum V_105 V_106 = V_206 ;
T_3 V_109 ;
int V_7 ;
V_7 = F_72 ( V_42 , false ) ;
if ( V_7 )
return V_7 ;
F_156 (vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
V_7 = F_74 ( V_42 , V_106 , false ,
V_109 , V_109 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static struct V_42 *
F_158 ( struct V_42 * V_42 , T_3 V_109 )
{
struct V_42 * V_210 ;
V_210 = F_50 ( sizeof( * V_210 ) , V_38 ) ;
if ( ! V_210 )
return NULL ;
V_210 -> V_61 = V_42 -> V_61 ;
V_210 -> V_1 = V_42 -> V_1 ;
V_210 -> V_25 = V_42 -> V_25 ;
V_210 -> V_211 = V_212 ;
V_210 -> V_213 = V_42 -> V_213 ;
V_210 -> V_214 = V_42 -> V_214 ;
V_210 -> V_215 . V_109 = V_109 ;
F_159 ( & V_210 -> V_215 . V_70 , & V_42 -> V_216 ) ;
return V_210 ;
}
static void F_160 ( struct V_42 * V_210 )
{
F_53 ( & V_210 -> V_215 . V_70 ) ;
F_32 ( V_210 ) ;
}
static int F_161 ( struct V_131 * V_61 ,
T_6 T_7 V_217 , T_3 V_109 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_42 * V_210 ;
bool V_200 = V_109 == 1 ;
int V_7 ;
if ( ! V_109 )
return 0 ;
if ( F_162 ( V_42 , V_109 ) )
return 0 ;
V_210 = F_158 ( V_42 , V_109 ) ;
if ( ! V_210 )
return - V_39 ;
if ( F_163 ( & V_42 -> V_216 ) ) {
V_7 = F_155 ( V_42 ) ;
if ( V_7 )
goto V_218;
}
V_7 = F_153 ( V_210 , V_109 , V_109 , true , V_200 ) ;
if ( V_7 )
goto V_219;
return 0 ;
V_219:
if ( F_163 ( & V_42 -> V_216 ) )
F_157 ( V_42 ) ;
V_218:
F_160 ( V_210 ) ;
return V_7 ;
}
static int F_164 ( struct V_131 * V_61 ,
T_6 T_7 V_217 , T_3 V_109 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_42 * V_210 ;
struct V_220 * V_221 ;
if ( ! V_109 )
return 0 ;
V_210 = F_162 ( V_42 , V_109 ) ;
if ( F_39 ( ! V_210 ) )
return 0 ;
F_153 ( V_210 , V_109 , V_109 , false , false ) ;
V_221 = F_165 ( V_210 ) ;
if ( V_221 && ! F_39 ( ! V_221 -> V_222 ) )
V_221 -> V_222 ( V_210 ) ;
if ( F_163 ( & V_42 -> V_216 ) )
F_157 ( V_42 ) ;
F_160 ( V_210 ) ;
return 0 ;
}
static int F_166 ( struct V_131 * V_61 , char * V_223 ,
T_8 V_135 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
T_2 V_128 = V_42 -> V_224 . V_128 ;
T_2 V_129 = V_42 -> V_224 . V_129 ;
T_2 V_130 = V_42 -> V_224 . V_130 ;
int V_7 ;
if ( ! V_42 -> V_225 )
V_7 = snprintf ( V_223 , V_135 , L_6 , V_128 + 1 ) ;
else
V_7 = snprintf ( V_223 , V_135 , L_7 , V_128 + 1 ,
V_130 / V_129 ) ;
if ( V_7 >= V_135 )
return - V_97 ;
return 0 ;
}
static struct V_226 *
F_167 ( struct V_42 * V_43 ,
unsigned long V_227 ) {
struct V_226 * V_228 ;
F_41 (mall_tc_entry, &port->mall_tc_list, list)
if ( V_228 -> V_227 == V_227 )
return V_228 ;
return NULL ;
}
static int
F_168 ( struct V_42 * V_42 ,
struct V_229 * V_230 ,
const struct V_231 * V_232 ,
bool V_233 )
{
struct V_234 * V_234 = F_169 ( V_42 -> V_61 ) ;
enum V_62 V_235 ;
struct V_42 * V_236 ;
struct V_131 * V_237 ;
int V_238 ;
V_238 = F_170 ( V_232 ) ;
V_237 = F_171 ( V_234 , V_238 ) ;
if ( ! V_237 ) {
F_46 ( V_42 -> V_61 , L_8 ) ;
return - V_97 ;
}
if ( ! F_172 ( V_237 ) ) {
F_46 ( V_42 -> V_61 , L_9 ) ;
return - V_239 ;
}
V_236 = F_93 ( V_237 ) ;
V_230 -> V_240 = V_236 -> V_25 ;
V_230 -> V_233 = V_233 ;
V_235 = V_233 ? V_241 : V_55 ;
return F_54 ( V_42 , V_236 , V_235 ) ;
}
static void
F_173 ( struct V_42 * V_42 ,
struct V_229 * V_230 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
enum V_62 V_235 ;
struct V_42 * V_236 ;
V_236 = V_1 -> V_242 [ V_230 -> V_240 ] ;
V_235 = V_230 -> V_233 ?
V_241 : V_55 ;
F_56 ( V_42 , V_236 , V_235 ) ;
}
static int
F_174 ( struct V_42 * V_42 ,
struct V_243 * V_244 ,
const struct V_231 * V_232 ,
bool V_233 )
{
int V_7 ;
if ( ! V_42 -> V_245 )
return - V_239 ;
if ( F_175 ( V_42 -> V_245 -> V_246 ) ) {
F_46 ( V_42 -> V_61 , L_10 ) ;
return - V_247 ;
}
if ( F_176 ( V_232 ) > V_248 ) {
F_46 ( V_42 -> V_61 , L_11 ) ;
return - V_239 ;
}
F_177 ( V_42 -> V_245 -> V_246 ,
F_178 ( V_232 ) ) ;
V_42 -> V_245 -> V_249 = F_179 ( V_232 ) ;
V_42 -> V_245 -> V_250 = F_180 ( V_232 ) ;
V_42 -> V_245 -> V_76 = F_176 ( V_232 ) ;
V_7 = F_57 ( V_42 , true , F_176 ( V_232 ) ) ;
if ( V_7 )
goto V_251;
return 0 ;
V_251:
F_181 ( V_42 -> V_245 -> V_246 , NULL ) ;
return V_7 ;
}
static void
F_182 ( struct V_42 * V_42 )
{
if ( ! V_42 -> V_245 )
return;
F_57 ( V_42 , false , 1 ) ;
F_181 ( V_42 -> V_245 -> V_246 , NULL ) ;
}
static int F_183 ( struct V_42 * V_42 ,
T_6 V_252 ,
struct V_243 * V_244 ,
bool V_233 )
{
struct V_226 * V_228 ;
const struct V_231 * V_232 ;
F_184 ( V_253 ) ;
int V_7 ;
if ( ! F_185 ( V_244 -> V_254 ) ) {
F_46 ( V_42 -> V_61 , L_12 ) ;
return - V_239 ;
}
V_228 = F_50 ( sizeof( * V_228 ) , V_38 ) ;
if ( ! V_228 )
return - V_39 ;
V_228 -> V_227 = V_244 -> V_227 ;
F_186 ( V_244 -> V_254 , & V_253 ) ;
V_232 = F_187 ( & V_253 , struct V_231 , V_70 ) ;
if ( F_188 ( V_232 ) && V_252 == F_189 ( V_255 ) ) {
struct V_229 * V_230 ;
V_228 -> type = V_256 ;
V_230 = & V_228 -> V_230 ;
V_7 = F_168 ( V_42 ,
V_230 , V_232 , V_233 ) ;
} else if ( F_190 ( V_232 ) && V_252 == F_189 ( V_255 ) ) {
V_228 -> type = V_257 ;
V_7 = F_174 ( V_42 , V_244 ,
V_232 , V_233 ) ;
} else {
V_7 = - V_239 ;
}
if ( V_7 )
goto V_258;
F_51 ( & V_228 -> V_70 , & V_42 -> V_259 ) ;
return 0 ;
V_258:
F_32 ( V_228 ) ;
return V_7 ;
}
static void F_191 ( struct V_42 * V_42 ,
struct V_243 * V_244 )
{
struct V_226 * V_228 ;
V_228 = F_167 ( V_42 ,
V_244 -> V_227 ) ;
if ( ! V_228 ) {
F_55 ( V_42 -> V_61 , L_13 ) ;
return;
}
F_53 ( & V_228 -> V_70 ) ;
switch ( V_228 -> type ) {
case V_256 :
F_173 ( V_42 ,
& V_228 -> V_230 ) ;
break;
case V_257 :
F_182 ( V_42 ) ;
break;
default:
F_39 ( 1 ) ;
}
F_32 ( V_228 ) ;
}
static int F_192 ( struct V_131 * V_61 , T_4 V_260 ,
T_6 V_217 , struct V_261 * V_262 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
bool V_233 = F_193 ( V_260 ) == F_193 ( V_263 ) ;
switch ( V_262 -> type ) {
case V_264 :
switch ( V_262 -> V_265 -> V_266 ) {
case V_267 :
return F_183 ( V_42 ,
V_217 ,
V_262 -> V_265 ,
V_233 ) ;
case V_268 :
F_191 ( V_42 ,
V_262 -> V_265 ) ;
return 0 ;
default:
return - V_239 ;
}
case V_269 :
switch ( V_262 -> V_270 -> V_266 ) {
case V_271 :
return F_194 ( V_42 , V_233 ,
V_217 , V_262 -> V_270 ) ;
case V_272 :
F_195 ( V_42 , V_233 ,
V_262 -> V_270 ) ;
return 0 ;
case V_273 :
return F_196 ( V_42 , V_233 ,
V_262 -> V_270 ) ;
default:
return - V_239 ;
}
}
return - V_239 ;
}
static void F_197 ( struct V_131 * V_61 ,
struct V_274 * V_275 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
F_198 ( V_275 -> V_276 , V_277 , sizeof( V_275 -> V_276 ) ) ;
F_198 ( V_275 -> V_278 , V_279 ,
sizeof( V_275 -> V_278 ) ) ;
snprintf ( V_275 -> V_280 , sizeof( V_275 -> V_280 ) ,
L_14 ,
V_1 -> V_281 -> V_282 . V_283 ,
V_1 -> V_281 -> V_282 . V_284 ,
V_1 -> V_281 -> V_282 . V_285 ) ;
F_198 ( V_275 -> V_281 , V_1 -> V_281 -> V_286 ,
sizeof( V_275 -> V_281 ) ) ;
}
static void F_199 ( struct V_131 * V_61 ,
struct V_287 * V_151 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
V_151 -> V_288 = V_42 -> V_289 . V_288 ;
V_151 -> V_290 = V_42 -> V_289 . V_290 ;
}
static int F_200 ( struct V_42 * V_42 ,
struct V_287 * V_151 )
{
char V_291 [ V_292 ] ;
F_201 ( V_291 , V_42 -> V_25 ) ;
F_202 ( V_291 , V_151 -> V_288 ) ;
F_203 ( V_291 , V_151 -> V_290 ) ;
return F_8 ( V_42 -> V_1 -> V_10 , F_4 ( V_293 ) ,
V_291 ) ;
}
static int F_204 ( struct V_131 * V_61 ,
struct V_287 * V_151 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
bool V_158 = V_151 -> V_290 || V_151 -> V_288 ;
int V_7 ;
if ( V_42 -> V_169 . V_150 && V_42 -> V_169 . V_150 -> V_161 ) {
F_46 ( V_61 , L_15 ) ;
return - V_97 ;
}
if ( V_151 -> V_294 ) {
F_46 ( V_61 , L_16 ) ;
return - V_97 ;
}
V_7 = F_123 ( V_42 , V_61 -> V_56 , V_158 ) ;
if ( V_7 ) {
F_46 ( V_61 , L_17 ) ;
return V_7 ;
}
V_7 = F_200 ( V_42 , V_151 ) ;
if ( V_7 ) {
F_46 ( V_61 , L_18 ) ;
goto V_295;
}
V_42 -> V_289 . V_288 = V_151 -> V_288 ;
V_42 -> V_289 . V_290 = V_151 -> V_290 ;
return 0 ;
V_295:
V_158 = F_125 ( V_42 ) ;
F_123 ( V_42 , V_61 -> V_56 , V_158 ) ;
return V_7 ;
}
static void F_205 ( T_2 * * V_54 , int V_182 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_296 ; V_31 ++ ) {
snprintf ( * V_54 , V_297 , L_19 ,
V_298 [ V_31 ] . V_299 , V_182 ) ;
* V_54 += V_297 ;
}
}
static void F_206 ( T_2 * * V_54 , int V_262 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_300 ; V_31 ++ ) {
snprintf ( * V_54 , V_297 , L_19 ,
V_301 [ V_31 ] . V_299 , V_262 ) ;
* V_54 += V_297 ;
}
}
static void F_207 ( struct V_131 * V_61 ,
T_4 V_302 , T_2 * V_303 )
{
T_2 * V_54 = V_303 ;
int V_31 ;
switch ( V_302 ) {
case V_304 :
for ( V_31 = 0 ; V_31 < V_305 ; V_31 ++ ) {
memcpy ( V_54 , V_306 [ V_31 ] . V_299 ,
V_297 ) ;
V_54 += V_297 ;
}
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ )
F_205 ( & V_54 , V_31 ) ;
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ )
F_206 ( & V_54 , V_31 ) ;
break;
}
}
static int F_208 ( struct V_131 * V_61 ,
enum V_307 V_308 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
char V_309 [ V_310 ] ;
bool V_311 ;
switch ( V_308 ) {
case V_312 :
V_311 = true ;
break;
case V_313 :
V_311 = false ;
break;
default:
return - V_239 ;
}
F_209 ( V_309 , V_42 -> V_25 , V_311 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_314 ) , V_309 ) ;
}
static int
F_210 ( struct V_306 * * V_315 ,
int * V_316 , enum V_317 V_181 )
{
switch ( V_181 ) {
case V_186 :
* V_315 = V_306 ;
* V_316 = V_305 ;
break;
case V_318 :
* V_315 = V_298 ;
* V_316 = V_296 ;
break;
case V_319 :
* V_315 = V_301 ;
* V_316 = V_300 ;
break;
default:
F_39 ( 1 ) ;
return - V_239 ;
}
return 0 ;
}
static void F_211 ( struct V_131 * V_61 ,
enum V_317 V_181 , int V_182 ,
T_1 * V_303 , int V_320 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
struct V_306 * V_195 ;
char V_183 [ V_185 ] ;
int V_31 , V_135 ;
int V_7 ;
V_7 = F_210 ( & V_195 , & V_135 , V_181 ) ;
if ( V_7 )
return;
F_133 ( V_61 , V_181 , V_182 , V_183 ) ;
for ( V_31 = 0 ; V_31 < V_135 ; V_31 ++ ) {
V_303 [ V_320 + V_31 ] = V_195 [ V_31 ] . F_212 ( V_183 ) ;
if ( ! V_195 [ V_31 ] . V_321 )
continue;
V_303 [ V_320 + V_31 ] = F_213 ( V_1 ,
V_303 [ V_320 + V_31 ] ) ;
}
}
static void F_214 ( struct V_131 * V_61 ,
struct V_322 * V_174 , T_1 * V_303 )
{
int V_31 , V_320 = 0 ;
F_211 ( V_61 , V_186 , 0 ,
V_303 , V_320 ) ;
V_320 = V_305 ;
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
F_211 ( V_61 , V_318 , V_31 ,
V_303 , V_320 ) ;
V_320 += V_296 ;
}
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
F_211 ( V_61 , V_319 , V_31 ,
V_303 , V_320 ) ;
V_320 += V_300 ;
}
}
static int F_215 ( struct V_131 * V_61 , int V_323 )
{
switch ( V_323 ) {
case V_304 :
return V_324 ;
default:
return - V_239 ;
}
}
static void
F_216 ( T_4 V_325 ,
struct V_326 * V_327 )
{
if ( V_325 & ( V_328 |
V_329 |
V_330 |
V_331 |
V_332 |
V_333 ) )
F_217 ( V_327 , V_334 , V_335 ) ;
if ( V_325 & ( V_336 |
V_337 |
V_338 |
V_339 |
V_340 ) )
F_217 ( V_327 , V_334 , V_341 ) ;
}
static void F_218 ( T_4 V_325 , unsigned long * V_342 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_343 ; V_31 ++ ) {
if ( V_325 & V_344 [ V_31 ] . V_345 )
F_219 ( V_344 [ V_31 ] . V_346 ,
V_342 ) ;
}
}
static void F_220 ( bool V_347 , T_4 V_325 ,
struct V_326 * V_327 )
{
T_4 V_348 = V_349 ;
T_2 V_350 = V_351 ;
int V_31 ;
if ( ! V_347 )
goto V_187;
for ( V_31 = 0 ; V_31 < V_343 ; V_31 ++ ) {
if ( V_325 & V_344 [ V_31 ] . V_345 ) {
V_348 = V_344 [ V_31 ] . V_348 ;
V_350 = V_352 ;
break;
}
}
V_187:
V_327 -> V_353 . V_348 = V_348 ;
V_327 -> V_353 . V_350 = V_350 ;
}
static T_2 F_221 ( T_4 V_325 )
{
if ( V_325 & ( V_329 |
V_331 |
V_332 |
V_333 ) )
return V_354 ;
if ( V_325 & ( V_328 |
V_330 |
V_355 ) )
return V_356 ;
if ( V_325 & ( V_336 |
V_337 |
V_338 |
V_339 ) )
return V_357 ;
return V_358 ;
}
static T_4
F_222 ( const struct V_326 * V_327 )
{
T_4 V_359 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_343 ; V_31 ++ ) {
if ( F_223 ( V_344 [ V_31 ] . V_346 ,
V_327 -> V_360 . V_361 ) )
V_359 |= V_344 [ V_31 ] . V_345 ;
}
return V_359 ;
}
static T_4 F_224 ( T_4 V_348 )
{
T_4 V_359 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_343 ; V_31 ++ ) {
if ( V_348 == V_344 [ V_31 ] . V_348 )
V_359 |= V_344 [ V_31 ] . V_345 ;
}
return V_359 ;
}
static T_4 F_225 ( T_4 V_362 )
{
T_4 V_359 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_343 ; V_31 ++ ) {
if ( V_344 [ V_31 ] . V_348 <= V_362 )
V_359 |= V_344 [ V_31 ] . V_345 ;
}
return V_359 ;
}
static void F_226 ( T_4 V_363 ,
struct V_326 * V_327 )
{
F_217 ( V_327 , V_334 , V_364 ) ;
F_217 ( V_327 , V_334 , V_365 ) ;
F_217 ( V_327 , V_334 , V_366 ) ;
F_216 ( V_363 , V_327 ) ;
F_218 ( V_363 , V_327 -> V_360 . V_334 ) ;
}
static void F_227 ( T_4 V_367 , bool V_294 ,
struct V_326 * V_327 )
{
if ( ! V_294 )
return;
F_217 ( V_327 , V_361 , V_365 ) ;
F_218 ( V_367 , V_327 -> V_360 . V_361 ) ;
}
static void
F_228 ( T_4 V_368 , T_2 V_369 ,
struct V_326 * V_327 )
{
if ( V_369 != V_370 || ! V_368 )
return;
F_217 ( V_327 , V_371 , V_365 ) ;
F_218 ( V_368 , V_327 -> V_360 . V_371 ) ;
}
static int F_229 ( struct V_131 * V_61 ,
struct V_326 * V_327 )
{
T_4 V_363 , V_367 , V_372 , V_368 ;
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
char V_373 [ V_374 ] ;
T_2 V_369 ;
bool V_294 ;
int V_7 ;
V_294 = V_42 -> V_289 . V_294 ;
F_230 ( V_373 , V_42 -> V_25 , 0 ) ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_375 ) , V_373 ) ;
if ( V_7 )
return V_7 ;
F_231 ( V_373 , & V_363 , & V_367 ,
& V_372 ) ;
F_226 ( V_363 , V_327 ) ;
F_227 ( V_367 , V_294 , V_327 ) ;
V_368 = F_232 ( V_373 ) ;
V_369 = F_233 ( V_373 ) ;
F_228 ( V_368 , V_369 , V_327 ) ;
V_327 -> V_353 . V_294 = V_294 ? V_376 : V_377 ;
V_327 -> V_353 . V_43 = F_221 ( V_372 ) ;
F_220 ( F_148 ( V_61 ) , V_372 ,
V_327 ) ;
return 0 ;
}
static int
F_234 ( struct V_131 * V_61 ,
const struct V_326 * V_327 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_1 * V_1 = V_42 -> V_1 ;
char V_373 [ V_374 ] ;
T_4 V_363 , V_378 ;
bool V_294 ;
int V_7 ;
F_230 ( V_373 , V_42 -> V_25 , 0 ) ;
V_7 = F_3 ( V_1 -> V_10 , F_4 ( V_375 ) , V_373 ) ;
if ( V_7 )
return V_7 ;
F_231 ( V_373 , & V_363 , NULL , NULL ) ;
V_294 = V_327 -> V_353 . V_294 == V_376 ;
V_378 = V_294 ?
F_222 ( V_327 ) :
F_224 ( V_327 -> V_353 . V_348 ) ;
V_378 = V_378 & V_363 ;
if ( ! V_378 ) {
F_46 ( V_61 , L_20 ) ;
return - V_97 ;
}
F_230 ( V_373 , V_42 -> V_25 ,
V_378 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_375 ) , V_373 ) ;
if ( V_7 )
return V_7 ;
if ( ! F_235 ( V_61 ) )
return 0 ;
V_42 -> V_289 . V_294 = V_294 ;
F_59 ( V_42 , false ) ;
F_59 ( V_42 , true ) ;
return 0 ;
}
static int
F_236 ( struct V_42 * V_42 , T_2 V_129 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
T_4 V_362 = V_379 * V_129 ;
char V_373 [ V_374 ] ;
T_4 V_367 ;
V_367 = F_225 ( V_362 ) ;
F_230 ( V_373 , V_42 -> V_25 ,
V_367 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_375 ) , V_373 ) ;
}
int F_237 ( struct V_42 * V_42 ,
enum V_380 V_381 , T_2 V_47 , T_2 V_382 ,
bool V_383 , T_2 V_384 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_385 [ V_386 ] ;
F_238 ( V_385 , V_42 -> V_25 , V_381 , V_47 ,
V_382 ) ;
F_239 ( V_385 , true ) ;
F_240 ( V_385 , V_383 ) ;
F_241 ( V_385 , V_384 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_387 ) , V_385 ) ;
}
int F_242 ( struct V_42 * V_42 ,
enum V_380 V_381 , T_2 V_47 ,
T_2 V_382 , T_4 V_388 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_385 [ V_386 ] ;
F_238 ( V_385 , V_42 -> V_25 , V_381 , V_47 ,
V_382 ) ;
F_243 ( V_385 , true ) ;
F_244 ( V_385 , V_388 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_387 ) , V_385 ) ;
}
int F_245 ( struct V_42 * V_42 ,
T_2 V_389 , T_2 V_390 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_391 [ V_392 ] ;
F_246 ( V_391 , V_42 -> V_25 , V_389 ,
V_390 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_393 ) , V_391 ) ;
}
static int F_247 ( struct V_42 * V_42 )
{
int V_7 , V_31 ;
V_7 = F_237 ( V_42 ,
V_394 , 0 , 0 , false ,
0 ) ;
if ( V_7 )
return V_7 ;
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
V_7 = F_237 ( V_42 ,
V_395 , V_31 ,
0 , false , 0 ) ;
if ( V_7 )
return V_7 ;
}
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
V_7 = F_237 ( V_42 ,
V_396 , V_31 , V_31 ,
false , 0 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_242 ( V_42 ,
V_397 , 0 , 0 ,
V_398 ) ;
if ( V_7 )
return V_7 ;
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
V_7 = F_242 ( V_42 ,
V_395 ,
V_31 , 0 ,
V_398 ) ;
if ( V_7 )
return V_7 ;
}
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
V_7 = F_242 ( V_42 ,
V_396 ,
V_31 , V_31 ,
V_398 ) ;
if ( V_7 )
return V_7 ;
}
for ( V_31 = 0 ; V_31 < V_165 ; V_31 ++ ) {
V_7 = F_245 ( V_42 , V_31 , 0 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_248 ( struct V_42 * V_42 )
{
V_42 -> V_399 = 1 ;
return F_161 ( V_42 -> V_61 , 0 , 1 ) ;
}
static int F_249 ( struct V_42 * V_42 )
{
return F_164 ( V_42 -> V_61 , 0 , 1 ) ;
}
static int F_250 ( struct V_1 * V_1 , T_2 V_25 ,
bool V_225 , T_2 V_128 , T_2 V_129 , T_2 V_130 )
{
struct V_42 * V_42 ;
struct V_131 * V_61 ;
T_8 V_4 ;
int V_7 ;
V_61 = F_251 ( sizeof( struct V_42 ) ) ;
if ( ! V_61 )
return - V_39 ;
F_252 ( V_61 , V_1 -> V_281 -> V_61 ) ;
V_42 = F_93 ( V_61 ) ;
V_42 -> V_61 = V_61 ;
V_42 -> V_1 = V_1 ;
V_42 -> V_25 = V_25 ;
V_42 -> V_225 = V_225 ;
V_42 -> V_224 . V_128 = V_128 ;
V_42 -> V_224 . V_129 = V_129 ;
V_42 -> V_224 . V_130 = V_130 ;
V_42 -> V_289 . V_294 = 1 ;
V_4 = F_115 ( V_209 , V_148 ) ;
V_42 -> V_400 = F_50 ( V_4 , V_38 ) ;
if ( ! V_42 -> V_400 ) {
V_7 = - V_39 ;
goto V_401;
}
V_42 -> V_402 = F_50 ( V_4 , V_38 ) ;
if ( ! V_42 -> V_402 ) {
V_7 = - V_39 ;
goto V_403;
}
F_28 ( & V_42 -> V_216 ) ;
F_28 ( & V_42 -> V_259 ) ;
V_42 -> V_133 =
F_253 ( struct V_132 ) ;
if ( ! V_42 -> V_133 ) {
V_7 = - V_39 ;
goto V_404;
}
V_42 -> V_245 = F_50 ( sizeof( * V_42 -> V_245 ) ,
V_38 ) ;
if ( ! V_42 -> V_245 ) {
V_7 = - V_39 ;
goto V_405;
}
V_42 -> V_195 . V_197 =
F_50 ( sizeof( * V_42 -> V_195 . V_197 ) , V_38 ) ;
if ( ! V_42 -> V_195 . V_197 ) {
V_7 = - V_39 ;
goto V_406;
}
F_254 ( & V_42 -> V_195 . V_196 ,
& F_146 ) ;
V_61 -> V_407 = & V_408 ;
V_61 -> V_409 = & V_410 ;
V_7 = F_71 ( V_42 , 0 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_21 ,
V_42 -> V_25 ) ;
goto V_411;
}
V_7 = F_64 ( V_42 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_22 ,
V_42 -> V_25 ) ;
goto V_412;
}
F_256 ( V_61 ) ;
V_61 -> V_413 |= V_414 | V_415 | V_416 |
V_417 | V_418 ;
V_61 -> V_419 |= V_418 ;
V_61 -> V_420 = 0 ;
V_61 -> V_94 = V_421 ;
V_61 -> V_422 = V_21 ;
V_7 = F_80 ( V_42 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_23 ,
V_42 -> V_25 ) ;
goto V_423;
}
V_7 = F_236 ( V_42 , V_129 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_24 ,
V_42 -> V_25 ) ;
goto V_424;
}
V_7 = F_66 ( V_42 , V_425 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_25 ,
V_42 -> V_25 ) ;
goto V_172;
}
V_7 = F_59 ( V_42 , false ) ;
if ( V_7 )
goto V_426;
V_7 = F_257 ( V_42 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_26 ,
V_42 -> V_25 ) ;
goto V_427;
}
V_7 = F_247 ( V_42 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_27 ,
V_42 -> V_25 ) ;
goto V_428;
}
V_7 = F_258 ( V_42 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_28 ,
V_42 -> V_25 ) ;
goto V_429;
}
V_7 = F_248 ( V_42 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_29 ,
V_42 -> V_25 ) ;
goto V_430;
}
F_259 ( V_42 ) ;
V_1 -> V_242 [ V_25 ] = V_42 ;
V_7 = F_260 ( V_61 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_30 ,
V_42 -> V_25 ) ;
goto V_431;
}
F_261 ( V_1 -> V_10 , V_42 -> V_25 ,
V_42 , V_61 , V_42 -> V_225 ,
V_128 ) ;
F_149 ( & V_42 -> V_195 . V_196 , 0 ) ;
return 0 ;
V_431:
V_1 -> V_242 [ V_25 ] = NULL ;
F_262 ( V_42 ) ;
F_249 ( V_42 ) ;
V_430:
F_263 ( V_42 ) ;
V_429:
V_428:
V_427:
V_426:
V_172:
V_424:
V_423:
V_412:
F_71 ( V_42 , V_432 ) ;
V_411:
F_32 ( V_42 -> V_195 . V_197 ) ;
V_406:
F_32 ( V_42 -> V_245 ) ;
V_405:
F_264 ( V_42 -> V_133 ) ;
V_404:
F_32 ( V_42 -> V_402 ) ;
V_403:
F_32 ( V_42 -> V_400 ) ;
V_401:
F_265 ( V_61 ) ;
return V_7 ;
}
static int F_266 ( struct V_1 * V_1 , T_2 V_25 ,
bool V_225 , T_2 V_128 , T_2 V_129 , T_2 V_130 )
{
int V_7 ;
V_7 = F_267 ( V_1 -> V_10 , V_25 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_31 ,
V_25 ) ;
return V_7 ;
}
V_7 = F_250 ( V_1 , V_25 , V_225 ,
V_128 , V_129 , V_130 ) ;
if ( V_7 )
goto V_433;
return 0 ;
V_433:
F_268 ( V_1 -> V_10 , V_25 ) ;
return V_7 ;
}
static void F_269 ( struct V_1 * V_1 , T_2 V_25 )
{
struct V_42 * V_42 = V_1 -> V_242 [ V_25 ] ;
F_270 ( & V_42 -> V_195 . V_196 ) ;
F_271 ( V_1 -> V_10 , V_25 , V_1 ) ;
F_272 ( V_42 -> V_61 ) ;
V_1 -> V_242 [ V_25 ] = NULL ;
F_262 ( V_42 ) ;
F_249 ( V_42 ) ;
F_263 ( V_42 ) ;
F_71 ( V_42 , V_432 ) ;
F_91 ( V_1 , V_42 -> V_25 ) ;
F_32 ( V_42 -> V_195 . V_197 ) ;
F_32 ( V_42 -> V_245 ) ;
F_264 ( V_42 -> V_133 ) ;
F_32 ( V_42 -> V_402 ) ;
F_32 ( V_42 -> V_400 ) ;
F_30 ( ! F_31 ( & V_42 -> V_216 ) ) ;
F_265 ( V_42 -> V_61 ) ;
}
static void F_273 ( struct V_1 * V_1 , T_2 V_25 )
{
F_269 ( V_1 , V_25 ) ;
F_268 ( V_1 -> V_10 , V_25 ) ;
}
static bool F_274 ( struct V_1 * V_1 , T_2 V_25 )
{
return V_1 -> V_242 [ V_25 ] != NULL ;
}
static void F_275 ( struct V_1 * V_1 )
{
int V_31 ;
for ( V_31 = 1 ; V_31 < F_276 ( V_1 -> V_10 ) ; V_31 ++ )
if ( F_274 ( V_1 , V_31 ) )
F_273 ( V_1 , V_31 ) ;
F_32 ( V_1 -> V_434 ) ;
F_32 ( V_1 -> V_242 ) ;
}
static int F_277 ( struct V_1 * V_1 )
{
unsigned int V_435 = F_276 ( V_1 -> V_10 ) ;
T_2 V_128 , V_129 , V_130 ;
T_8 V_436 ;
int V_31 ;
int V_7 ;
V_436 = sizeof( struct V_42 * ) * V_435 ;
V_1 -> V_242 = F_50 ( V_436 , V_38 ) ;
if ( ! V_1 -> V_242 )
return - V_39 ;
V_1 -> V_434 = F_27 ( V_435 , sizeof( T_2 ) , V_38 ) ;
if ( ! V_1 -> V_434 ) {
V_7 = - V_39 ;
goto V_437;
}
for ( V_31 = 1 ; V_31 < V_435 ; V_31 ++ ) {
V_7 = F_82 ( V_1 , V_31 , & V_128 ,
& V_129 , & V_130 ) ;
if ( V_7 )
goto V_438;
if ( ! V_129 )
continue;
V_1 -> V_434 [ V_31 ] = V_128 ;
V_7 = F_266 ( V_1 , V_31 , false ,
V_128 , V_129 , V_130 ) ;
if ( V_7 )
goto V_433;
}
return 0 ;
V_433:
V_438:
for ( V_31 -- ; V_31 >= 1 ; V_31 -- )
if ( F_274 ( V_1 , V_31 ) )
F_273 ( V_1 , V_31 ) ;
F_32 ( V_1 -> V_434 ) ;
V_437:
F_32 ( V_1 -> V_242 ) ;
return V_7 ;
}
static T_2 F_278 ( T_2 V_25 )
{
T_2 V_439 = ( V_25 - 1 ) % V_440 ;
return V_25 - V_439 ;
}
static int F_279 ( struct V_1 * V_1 , T_2 V_441 ,
T_2 V_128 , unsigned int V_442 )
{
T_2 V_129 = V_443 / V_442 ;
int V_7 , V_31 ;
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ ) {
V_7 = F_87 ( V_1 , V_441 + V_31 , V_128 ,
V_129 , V_31 * V_129 ) ;
if ( V_7 )
goto V_444;
}
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ ) {
V_7 = F_69 ( V_1 , V_441 + V_31 , 0 ) ;
if ( V_7 )
goto V_411;
}
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ ) {
V_7 = F_266 ( V_1 , V_441 + V_31 , true ,
V_128 , V_129 , V_31 * V_129 ) ;
if ( V_7 )
goto V_433;
}
return 0 ;
V_433:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
if ( F_274 ( V_1 , V_441 + V_31 ) )
F_273 ( V_1 , V_441 + V_31 ) ;
V_31 = V_442 ;
V_411:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
F_69 ( V_1 , V_441 + V_31 ,
V_432 ) ;
V_31 = V_442 ;
V_444:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- )
F_91 ( V_1 , V_441 + V_31 ) ;
return V_7 ;
}
static void F_280 ( struct V_1 * V_1 ,
T_2 V_441 , unsigned int V_442 )
{
T_2 V_25 , V_128 , V_129 = V_443 ;
int V_31 ;
V_442 = V_442 / 2 ;
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ ) {
V_25 = V_441 + V_31 * 2 ;
V_128 = V_1 -> V_434 [ V_25 ] ;
F_87 ( V_1 , V_25 , V_128 , V_129 ,
0 ) ;
}
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ )
F_69 ( V_1 , V_441 + V_31 * 2 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ ) {
V_25 = V_441 + V_31 * 2 ;
V_128 = V_1 -> V_434 [ V_25 ] ;
F_266 ( V_1 , V_25 , false , V_128 ,
V_129 , 0 ) ;
}
}
static int F_281 ( struct V_445 * V_445 , T_2 V_25 ,
unsigned int V_442 )
{
struct V_1 * V_1 = F_282 ( V_445 ) ;
struct V_42 * V_42 ;
T_2 V_128 , V_446 , V_441 ;
int V_31 ;
int V_7 ;
V_42 = V_1 -> V_242 [ V_25 ] ;
if ( ! V_42 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_32 ,
V_25 ) ;
return - V_97 ;
}
V_128 = V_42 -> V_224 . V_128 ;
V_446 = V_42 -> V_224 . V_129 ;
if ( V_442 != 2 && V_442 != 4 ) {
F_46 ( V_42 -> V_61 , L_33 ) ;
return - V_97 ;
}
if ( V_446 != V_443 ) {
F_46 ( V_42 -> V_61 , L_34 ) ;
return - V_97 ;
}
if ( V_442 == 2 ) {
V_441 = V_25 ;
if ( V_1 -> V_242 [ V_441 + 1 ] ) {
F_46 ( V_42 -> V_61 , L_35 ) ;
return - V_97 ;
}
} else {
V_441 = F_278 ( V_25 ) ;
if ( V_1 -> V_242 [ V_441 + 1 ] ||
V_1 -> V_242 [ V_441 + 3 ] ) {
F_46 ( V_42 -> V_61 , L_35 ) ;
return - V_97 ;
}
}
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ )
if ( F_274 ( V_1 , V_441 + V_31 ) )
F_273 ( V_1 , V_441 + V_31 ) ;
V_7 = F_279 ( V_1 , V_441 , V_128 , V_442 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_36 ) ;
goto V_447;
}
return 0 ;
V_447:
F_280 ( V_1 , V_441 , V_442 ) ;
return V_7 ;
}
static int F_283 ( struct V_445 * V_445 , T_2 V_25 )
{
struct V_1 * V_1 = F_282 ( V_445 ) ;
struct V_42 * V_42 ;
T_2 V_446 , V_441 ;
unsigned int V_442 ;
int V_31 ;
V_42 = V_1 -> V_242 [ V_25 ] ;
if ( ! V_42 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_32 ,
V_25 ) ;
return - V_97 ;
}
if ( ! V_42 -> V_225 ) {
F_46 ( V_42 -> V_61 , L_37 ) ;
return - V_97 ;
}
V_446 = V_42 -> V_224 . V_129 ;
V_442 = V_446 == 1 ? 4 : 2 ;
V_441 = F_278 ( V_25 ) ;
if ( V_442 == 2 && V_25 >= V_441 + 2 )
V_441 = V_441 + 2 ;
for ( V_31 = 0 ; V_31 < V_442 ; V_31 ++ )
if ( F_274 ( V_1 , V_441 + V_31 ) )
F_273 ( V_1 , V_441 + V_31 ) ;
F_280 ( V_1 , V_441 , V_442 ) ;
return 0 ;
}
static void F_284 ( const struct V_448 * V_449 ,
char * V_450 , void * V_451 )
{
struct V_1 * V_1 = V_451 ;
struct V_42 * V_42 ;
enum V_452 V_453 ;
T_2 V_25 ;
V_25 = F_285 ( V_450 ) ;
V_42 = V_1 -> V_242 [ V_25 ] ;
if ( ! V_42 )
return;
V_453 = F_286 ( V_450 ) ;
if ( V_453 == V_454 ) {
F_287 ( V_42 -> V_61 , L_38 ) ;
F_288 ( V_42 -> V_61 ) ;
} else {
F_287 ( V_42 -> V_61 , L_39 ) ;
F_256 ( V_42 -> V_61 ) ;
}
}
static void F_289 ( struct V_16 * V_17 ,
T_2 V_25 , void * V_451 )
{
struct V_1 * V_1 = V_451 ;
struct V_42 * V_42 = V_1 -> V_242 [ V_25 ] ;
struct V_132 * V_133 ;
if ( F_99 ( ! V_42 ) ) {
F_290 ( V_1 -> V_281 -> V_61 , L_40 ,
V_25 ) ;
return;
}
V_17 -> V_61 = V_42 -> V_61 ;
V_133 = F_107 ( V_42 -> V_133 ) ;
F_108 ( & V_133 -> V_140 ) ;
V_133 -> V_175 ++ ;
V_133 -> V_176 += V_17 -> V_135 ;
F_109 ( & V_133 -> V_140 ) ;
V_17 -> V_252 = F_291 ( V_17 , V_17 -> V_61 ) ;
F_292 ( V_17 ) ;
}
static void F_293 ( struct V_16 * V_17 , T_2 V_25 ,
void * V_451 )
{
V_17 -> V_455 = 1 ;
return F_289 ( V_17 , V_25 , V_451 ) ;
}
static void F_294 ( struct V_16 * V_17 , T_2 V_25 ,
void * V_451 )
{
struct V_1 * V_1 = V_451 ;
struct V_42 * V_42 = V_1 -> V_242 [ V_25 ] ;
struct V_246 * V_246 ;
T_4 V_154 ;
if ( F_99 ( ! V_42 ) ) {
F_290 ( V_1 -> V_281 -> V_61 , L_41 ,
V_25 ) ;
goto V_187;
}
if ( F_99 ( ! V_42 -> V_245 ) ) {
F_290 ( V_1 -> V_281 -> V_61 , L_42 ,
V_25 ) ;
goto V_187;
}
V_154 = V_42 -> V_245 -> V_249 ?
V_42 -> V_245 -> V_250 : V_17 -> V_135 ;
F_295 () ;
V_246 = F_296 ( V_42 -> V_245 -> V_246 ) ;
if ( ! V_246 )
goto V_456;
F_297 ( V_246 , V_17 , V_154 ,
V_42 -> V_61 -> V_238 , 0 ,
V_42 -> V_245 -> V_76 ) ;
V_456:
F_298 () ;
V_187:
F_299 ( V_17 ) ;
}
static int F_300 ( struct V_445 * V_445 )
{
char V_457 [ V_458 ] ;
enum V_459 V_460 ;
int V_461 ;
bool V_462 ;
T_2 V_463 ;
T_4 V_76 ;
int V_31 , V_7 ;
if ( ! F_25 ( V_445 , V_464 ) )
return - V_33 ;
V_461 = F_26 ( V_445 , V_464 ) ;
V_460 = V_465 ;
for ( V_31 = 0 ; V_31 < V_461 ; V_31 ++ ) {
V_462 = false ;
switch ( V_31 ) {
case V_466 :
case V_467 :
case V_468 :
case V_469 :
V_76 = 128 ;
V_463 = 7 ;
break;
case V_470 :
V_76 = 16 * 1024 ;
V_463 = 10 ;
break;
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
V_76 = 1024 ;
V_463 = 7 ;
break;
case V_477 :
V_462 = true ;
V_76 = 4 * 1024 ;
V_463 = 4 ;
break;
default:
continue;
}
F_301 ( V_457 , V_31 , V_460 , V_462 , V_76 ,
V_463 ) ;
V_7 = F_8 ( V_445 , F_4 ( V_478 ) , V_457 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_302 ( struct V_445 * V_445 )
{
char V_479 [ V_480 ] ;
enum V_481 V_31 ;
int V_461 ;
int V_482 ;
T_2 V_483 , V_262 ;
T_3 V_484 ;
int V_7 ;
if ( ! F_25 ( V_445 , V_485 ) )
return - V_33 ;
V_482 = F_26 ( V_445 , V_485 ) ;
V_461 = F_26 ( V_445 , V_464 ) ;
for ( V_31 = 0 ; V_31 < V_482 ; V_31 ++ ) {
V_484 = V_31 ;
switch ( V_31 ) {
case V_466 :
case V_467 :
case V_468 :
case V_469 :
V_483 = 5 ;
V_262 = 5 ;
break;
case V_471 :
case V_473 :
V_483 = 4 ;
V_262 = 4 ;
break;
case V_470 :
case V_477 :
V_483 = 3 ;
V_262 = 3 ;
break;
case V_472 :
V_483 = 2 ;
V_262 = 2 ;
break;
case V_474 :
case V_475 :
case V_476 :
V_483 = 1 ;
V_262 = 1 ;
break;
case V_486 :
V_483 = V_487 ;
V_262 = V_488 ;
V_484 = V_489 ;
break;
default:
continue;
}
if ( V_461 <= V_484 &&
V_484 != V_489 )
return - V_33 ;
F_303 ( V_479 , V_31 , V_484 , V_483 , V_262 ) ;
V_7 = F_8 ( V_445 , F_4 ( V_490 ) , V_479 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_304 ( struct V_1 * V_1 )
{
int V_31 ;
int V_7 ;
V_7 = F_300 ( V_1 -> V_10 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_302 ( V_1 -> V_10 ) ;
if ( V_7 )
return V_7 ;
for ( V_31 = 0 ; V_31 < F_305 ( V_491 ) ; V_31 ++ ) {
V_7 = F_306 ( V_1 -> V_10 ,
& V_491 [ V_31 ] ,
V_1 ) ;
if ( V_7 )
goto V_492;
}
return 0 ;
V_492:
for ( V_31 -- ; V_31 >= 0 ; V_31 -- ) {
F_307 ( V_1 -> V_10 ,
& V_491 [ V_31 ] ,
V_1 ) ;
}
return V_7 ;
}
static void F_308 ( struct V_1 * V_1 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_305 ( V_491 ) ; V_31 ++ ) {
F_307 ( V_1 -> V_10 ,
& V_491 [ V_31 ] ,
V_1 ) ;
}
}
static int F_309 ( struct V_445 * V_445 ,
enum V_493 type ,
enum V_494 V_495 )
{
enum V_496 V_497 ;
enum V_498 V_499 ;
char V_500 [ V_501 ] ;
if ( V_495 == V_502 )
V_497 = V_503 ;
else
V_497 = V_504 ;
switch ( type ) {
case V_505 :
V_499 = V_506 ;
break;
case V_507 :
V_499 = V_508 ;
break;
default:
V_499 = V_509 ;
}
F_310 ( V_500 , type , V_495 , V_497 ,
V_499 ) ;
return F_8 ( V_445 , F_4 ( V_510 ) , V_500 ) ;
}
static int F_311 ( struct V_1 * V_1 )
{
int type , V_7 ;
for ( type = 0 ; type < V_511 ; type ++ ) {
if ( type == V_512 )
continue;
V_7 = F_309 ( V_1 -> V_10 , type ,
V_502 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_309 ( V_1 -> V_10 , type ,
V_513 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_312 ( struct V_1 * V_1 )
{
char V_514 [ V_515 ] ;
int V_7 ;
F_313 ( V_514 , V_516 |
V_517 |
V_518 |
V_519 |
V_520 |
V_521 |
V_522 |
V_523 |
V_524 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_525 ) , V_514 ) ;
if ( V_7 )
return V_7 ;
if ( ! F_25 ( V_1 -> V_10 , V_526 ) ||
! F_25 ( V_1 -> V_10 , V_527 ) )
return - V_33 ;
V_1 -> V_528 = F_27 ( F_26 ( V_1 -> V_10 , V_526 ) ,
sizeof( struct V_529 ) ,
V_38 ) ;
if ( ! V_1 -> V_528 )
return - V_39 ;
return 0 ;
}
static void F_314 ( struct V_1 * V_1 )
{
F_32 ( V_1 -> V_528 ) ;
}
static int F_315 ( struct V_445 * V_445 )
{
char V_479 [ V_480 ] ;
F_303 ( V_479 , V_530 ,
V_489 ,
V_487 ,
V_488 ) ;
return F_8 ( V_445 , F_4 ( V_490 ) , V_479 ) ;
}
static int F_316 ( struct V_1 * V_1 )
{
return F_317 ( V_1 , V_531 , true ) ;
}
static void F_318 ( struct V_1 * V_1 )
{
F_317 ( V_1 , V_531 , false ) ;
}
static int F_319 ( struct V_445 * V_445 ,
const struct V_532 * V_532 )
{
struct V_1 * V_1 = F_282 ( V_445 ) ;
int V_7 ;
V_1 -> V_10 = V_445 ;
V_1 -> V_281 = V_532 ;
F_28 ( & V_1 -> V_533 ) ;
F_28 ( & V_1 -> V_534 . V_70 ) ;
F_28 ( & V_1 -> V_535 . V_70 ) ;
V_7 = F_22 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_43 ) ;
return V_7 ;
}
V_7 = F_304 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_44 ) ;
return V_7 ;
}
V_7 = F_311 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_45 ) ;
goto V_536;
}
V_7 = F_320 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_46 ) ;
goto V_537;
}
V_7 = F_312 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_47 ) ;
goto V_538;
}
V_7 = F_321 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_48 ) ;
goto V_539;
}
V_7 = F_322 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_49 ) ;
goto V_540;
}
V_7 = F_24 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_50 ) ;
goto V_541;
}
V_7 = F_323 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_51 ) ;
goto V_542;
}
V_7 = F_324 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_52 ) ;
goto V_543;
}
V_7 = F_325 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_53 ) ;
goto V_544;
}
V_7 = F_316 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_54 ) ;
goto V_545;
}
V_7 = F_277 ( V_1 ) ;
if ( V_7 ) {
F_255 ( V_1 -> V_281 -> V_61 , L_55 ) ;
goto V_546;
}
return 0 ;
V_546:
F_318 ( V_1 ) ;
V_545:
F_326 ( V_1 ) ;
V_544:
F_327 ( V_1 ) ;
V_543:
F_328 ( V_1 ) ;
V_542:
F_29 ( V_1 ) ;
V_541:
F_329 ( V_1 ) ;
V_540:
F_330 ( V_1 ) ;
V_539:
F_314 ( V_1 ) ;
V_538:
F_331 ( V_1 ) ;
V_537:
V_536:
F_308 ( V_1 ) ;
return V_7 ;
}
static void F_332 ( struct V_445 * V_445 )
{
struct V_1 * V_1 = F_282 ( V_445 ) ;
F_275 ( V_1 ) ;
F_318 ( V_1 ) ;
F_326 ( V_1 ) ;
F_327 ( V_1 ) ;
F_328 ( V_1 ) ;
F_29 ( V_1 ) ;
F_329 ( V_1 ) ;
F_330 ( V_1 ) ;
F_314 ( V_1 ) ;
F_331 ( V_1 ) ;
F_308 ( V_1 ) ;
F_39 ( ! F_31 ( & V_1 -> V_534 . V_70 ) ) ;
F_39 ( ! F_31 ( & V_1 -> V_533 ) ) ;
}
bool F_172 ( const struct V_131 * V_61 )
{
return V_61 -> V_407 == & V_408 ;
}
static int F_333 ( struct V_131 * V_547 , void * V_303 )
{
struct V_42 * * V_548 = V_303 ;
int V_549 = 0 ;
if ( F_172 ( V_547 ) ) {
* V_548 = F_93 ( V_547 ) ;
V_549 = 1 ;
}
return V_549 ;
}
static struct V_42 * F_334 ( struct V_131 * V_61 )
{
struct V_42 * V_42 ;
if ( F_172 ( V_61 ) )
return F_93 ( V_61 ) ;
V_42 = NULL ;
F_335 ( V_61 , F_333 , & V_42 ) ;
return V_42 ;
}
struct V_1 * F_336 ( struct V_131 * V_61 )
{
struct V_42 * V_42 ;
V_42 = F_334 ( V_61 ) ;
return V_42 ? V_42 -> V_1 : NULL ;
}
static struct V_42 * F_337 ( struct V_131 * V_61 )
{
struct V_42 * V_42 ;
if ( F_172 ( V_61 ) )
return F_93 ( V_61 ) ;
V_42 = NULL ;
F_338 ( V_61 , F_333 ,
& V_42 ) ;
return V_42 ;
}
struct V_42 * F_339 ( struct V_131 * V_61 )
{
struct V_42 * V_42 ;
F_295 () ;
V_42 = F_337 ( V_61 ) ;
if ( V_42 )
F_340 ( V_42 -> V_61 ) ;
F_298 () ;
return V_42 ;
}
void F_341 ( struct V_42 * V_42 )
{
F_342 ( V_42 -> V_61 ) ;
}
static bool F_343 ( struct V_42 * V_550 ,
T_3 V_108 )
{
if ( F_344 ( V_108 ) )
return F_345 ( V_550 , V_108 ) ;
else
return F_223 ( V_108 , V_550 -> V_400 ) ;
}
static bool F_346 ( struct V_42 * V_42 ,
T_3 V_108 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
T_2 V_25 = V_42 -> V_25 ;
T_3 V_214 = V_42 -> V_214 ;
T_1 V_551 ;
int V_31 , V_442 = 0 ;
if ( ! V_42 -> V_213 )
return true ;
V_551 = F_26 ( V_1 -> V_10 ,
V_527 ) ;
for ( V_31 = 0 ; V_31 < V_551 ; V_31 ++ ) {
struct V_42 * V_550 ;
V_550 = F_347 ( V_1 , V_214 , V_31 ) ;
if ( ! V_550 || V_550 -> V_25 == V_25 )
continue;
if ( F_343 ( V_550 , V_108 ) )
V_442 ++ ;
}
return ! V_442 ;
}
static int
F_348 ( const struct V_42 * V_42 ,
T_3 V_108 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_552 [ V_553 ] ;
F_349 ( V_552 , V_554 ) ;
F_350 ( V_552 , V_108 ) ;
F_351 ( V_552 ,
V_42 -> V_25 ) ;
F_55 ( V_42 -> V_61 , L_56 ,
V_42 -> V_25 , V_108 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_555 ) , V_552 ) ;
}
static int
F_352 ( const struct V_42 * V_42 ,
T_3 V_108 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_552 [ V_553 ] ;
F_349 ( V_552 , V_556 ) ;
F_350 ( V_552 , V_108 ) ;
F_353 ( V_552 , V_42 -> V_214 ) ;
F_55 ( V_42 -> V_61 , L_57 ,
V_42 -> V_214 , V_108 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_555 ) , V_552 ) ;
}
int F_354 ( struct V_42 * V_42 , T_3 V_108 )
{
if ( ! F_346 ( V_42 , V_108 ) )
return 0 ;
if ( V_42 -> V_213 )
return F_352 ( V_42 ,
V_108 ) ;
else
return F_348 ( V_42 , V_108 ) ;
}
static void F_355 ( struct V_1 * V_1 )
{
struct V_220 * V_221 , * V_557 ;
F_356 (f, tmp, &mlxsw_sp->fids, list)
if ( -- V_221 -> V_51 == 0 )
F_357 ( V_1 , V_221 ) ;
else
F_30 ( 1 ) ;
}
static bool F_358 ( struct V_1 * V_1 ,
struct V_131 * V_558 )
{
return ! V_1 -> V_559 . V_61 ||
V_1 -> V_559 . V_61 == V_558 ;
}
static void F_359 ( struct V_1 * V_1 ,
struct V_131 * V_558 )
{
V_1 -> V_559 . V_61 = V_558 ;
V_1 -> V_559 . V_51 ++ ;
}
static void F_360 ( struct V_1 * V_1 )
{
if ( -- V_1 -> V_559 . V_51 == 0 ) {
V_1 -> V_559 . V_61 = NULL ;
F_355 ( V_1 ) ;
}
}
static int F_361 ( struct V_42 * V_42 ,
struct V_131 * V_558 )
{
struct V_131 * V_61 = V_42 -> V_61 ;
int V_7 ;
V_7 = F_164 ( V_61 , 0 , 1 ) ;
if ( V_7 )
return V_7 ;
F_359 ( V_42 -> V_1 , V_558 ) ;
V_42 -> V_560 = 1 ;
V_42 -> V_561 = 1 ;
V_42 -> V_562 = 1 ;
V_42 -> V_563 = 1 ;
V_42 -> V_564 = 0 ;
V_42 -> V_565 = 1 ;
V_42 -> V_566 = 1 ;
return 0 ;
}
static void F_362 ( struct V_42 * V_42 )
{
struct V_131 * V_61 = V_42 -> V_61 ;
F_363 ( V_42 , 1 ) ;
F_360 ( V_42 -> V_1 ) ;
V_42 -> V_560 = 0 ;
V_42 -> V_561 = 0 ;
V_42 -> V_562 = 0 ;
V_42 -> V_563 = 0 ;
V_42 -> V_564 = 0 ;
V_42 -> V_566 = 0 ;
F_161 ( V_61 , 0 , 1 ) ;
}
static int F_364 ( struct V_1 * V_1 , T_3 V_214 )
{
char V_567 [ V_568 ] ;
F_365 ( V_567 , V_214 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_569 ) , V_567 ) ;
}
static int F_366 ( struct V_1 * V_1 , T_3 V_214 )
{
char V_567 [ V_568 ] ;
F_367 ( V_567 , V_214 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_569 ) , V_567 ) ;
}
static int F_368 ( struct V_42 * V_42 ,
T_3 V_214 , T_2 V_570 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_571 [ V_572 ] ;
F_369 ( V_571 , V_42 -> V_25 ,
V_214 , V_570 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_573 ) , V_571 ) ;
}
static int F_370 ( struct V_42 * V_42 ,
T_3 V_214 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_571 [ V_572 ] ;
F_371 ( V_571 , V_42 -> V_25 ,
V_214 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_573 ) , V_571 ) ;
}
static int F_372 ( struct V_42 * V_42 ,
T_3 V_214 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_571 [ V_572 ] ;
F_373 ( V_571 , V_42 -> V_25 ,
V_214 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_573 ) , V_571 ) ;
}
static int F_374 ( struct V_42 * V_42 ,
T_3 V_214 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_571 [ V_572 ] ;
F_375 ( V_571 , V_42 -> V_25 ,
V_214 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_573 ) , V_571 ) ;
}
static int F_376 ( struct V_1 * V_1 ,
struct V_131 * V_574 ,
T_3 * V_575 )
{
struct V_529 * V_576 ;
int V_577 = - 1 ;
T_1 V_578 ;
int V_31 ;
V_578 = F_26 ( V_1 -> V_10 , V_526 ) ;
for ( V_31 = 0 ; V_31 < V_578 ; V_31 ++ ) {
V_576 = F_377 ( V_1 , V_31 ) ;
if ( V_576 -> V_51 ) {
if ( V_576 -> V_61 == V_574 ) {
* V_575 = V_31 ;
return 0 ;
}
} else if ( V_577 < 0 ) {
V_577 = V_31 ;
}
}
if ( V_577 < 0 )
return - V_579 ;
* V_575 = V_577 ;
return 0 ;
}
static bool
F_378 ( struct V_1 * V_1 ,
struct V_131 * V_574 ,
struct V_580 * V_581 )
{
T_3 V_214 ;
if ( F_376 ( V_1 , V_574 , & V_214 ) != 0 )
return false ;
if ( V_581 -> V_582 != V_583 )
return false ;
return true ;
}
static int F_379 ( struct V_1 * V_1 ,
T_3 V_214 , T_2 * V_584 )
{
T_1 V_551 ;
int V_31 ;
V_551 = F_26 ( V_1 -> V_10 ,
V_527 ) ;
for ( V_31 = 0 ; V_31 < V_551 ; V_31 ++ ) {
if ( ! F_347 ( V_1 , V_214 , V_31 ) ) {
* V_584 = V_31 ;
return 0 ;
}
}
return - V_579 ;
}
static void
F_380 ( struct V_42 * V_42 ,
struct V_131 * V_574 , T_3 V_214 )
{
struct V_42 * V_210 ;
struct V_220 * V_221 ;
V_210 = F_162 ( V_42 , 1 ) ;
if ( F_39 ( ! V_210 ) )
return;
V_221 = F_165 ( V_210 ) ;
if ( V_221 )
V_221 -> V_222 ( V_210 ) ;
V_210 -> V_214 = V_214 ;
V_210 -> V_213 = 1 ;
V_210 -> V_61 = V_574 ;
}
static void
F_381 ( struct V_42 * V_42 )
{
struct V_42 * V_210 ;
struct V_220 * V_221 ;
V_210 = F_162 ( V_42 , 1 ) ;
if ( F_39 ( ! V_210 ) )
return;
V_221 = F_165 ( V_210 ) ;
if ( V_221 )
V_221 -> V_222 ( V_210 ) ;
V_210 -> V_61 = V_42 -> V_61 ;
V_210 -> V_213 = 0 ;
}
static int F_382 ( struct V_42 * V_42 ,
struct V_131 * V_574 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
struct V_529 * V_576 ;
T_3 V_214 ;
T_2 V_570 ;
int V_7 ;
V_7 = F_376 ( V_1 , V_574 , & V_214 ) ;
if ( V_7 )
return V_7 ;
V_576 = F_377 ( V_1 , V_214 ) ;
if ( ! V_576 -> V_51 ) {
V_7 = F_364 ( V_1 , V_214 ) ;
if ( V_7 )
return V_7 ;
V_576 -> V_61 = V_574 ;
}
V_7 = F_379 ( V_1 , V_214 , & V_570 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_368 ( V_42 , V_214 , V_570 ) ;
if ( V_7 )
goto V_585;
V_7 = F_372 ( V_42 , V_214 ) ;
if ( V_7 )
goto V_586;
F_383 ( V_1 -> V_10 , V_214 , V_570 ,
V_42 -> V_25 ) ;
V_42 -> V_214 = V_214 ;
V_42 -> V_213 = 1 ;
V_576 -> V_51 ++ ;
F_380 ( V_42 , V_574 , V_214 ) ;
return 0 ;
V_586:
F_370 ( V_42 , V_214 ) ;
V_585:
if ( ! V_576 -> V_51 )
F_366 ( V_1 , V_214 ) ;
return V_7 ;
}
static void F_384 ( struct V_42 * V_42 ,
struct V_131 * V_574 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
T_3 V_214 = V_42 -> V_214 ;
struct V_529 * V_576 ;
if ( ! V_42 -> V_213 )
return;
V_576 = F_377 ( V_1 , V_214 ) ;
F_39 ( V_576 -> V_51 == 0 ) ;
F_374 ( V_42 , V_214 ) ;
F_370 ( V_42 , V_214 ) ;
if ( V_42 -> V_566 ) {
F_385 ( V_42 ) ;
F_362 ( V_42 ) ;
}
if ( V_576 -> V_51 == 1 )
F_366 ( V_1 , V_214 ) ;
F_386 ( V_1 -> V_10 , V_214 ,
V_42 -> V_25 ) ;
V_42 -> V_213 = 0 ;
V_576 -> V_51 -- ;
F_381 ( V_42 ) ;
}
static int F_387 ( struct V_42 * V_42 ,
T_3 V_214 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_567 [ V_568 ] ;
F_388 ( V_567 , V_214 ,
V_42 -> V_25 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_569 ) , V_567 ) ;
}
static int F_389 ( struct V_42 * V_42 ,
T_3 V_214 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
char V_567 [ V_568 ] ;
F_390 ( V_567 , V_214 ,
V_42 -> V_25 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_569 ) , V_567 ) ;
}
static int F_391 ( struct V_42 * V_42 ,
bool V_587 )
{
if ( V_587 )
return F_387 ( V_42 ,
V_42 -> V_214 ) ;
else
return F_389 ( V_42 ,
V_42 -> V_214 ) ;
}
static int F_392 ( struct V_42 * V_42 ,
struct V_588 * V_589 )
{
return F_391 ( V_42 , V_589 -> V_590 ) ;
}
static int F_393 ( struct V_42 * V_42 ,
struct V_131 * V_591 )
{
struct V_42 * V_210 ;
T_3 V_109 = F_394 ( V_591 ) ;
V_210 = F_162 ( V_42 , V_109 ) ;
if ( F_39 ( ! V_210 ) )
return - V_97 ;
V_210 -> V_61 = V_591 ;
return 0 ;
}
static void F_395 ( struct V_42 * V_42 ,
struct V_131 * V_591 )
{
struct V_42 * V_210 ;
T_3 V_109 = F_394 ( V_591 ) ;
V_210 = F_162 ( V_42 , V_109 ) ;
if ( F_39 ( ! V_210 ) )
return;
V_210 -> V_61 = V_42 -> V_61 ;
}
static int F_396 ( struct V_42 * V_42 ,
bool V_75 )
{
struct V_1 * V_1 = V_42 -> V_1 ;
enum V_592 V_593 ;
char * V_594 ;
T_3 V_109 ;
int V_7 ;
V_593 = V_75 ? V_595 :
V_596 ;
V_594 = F_77 ( V_597 , V_38 ) ;
if ( ! V_594 )
return - V_39 ;
F_397 ( V_594 , V_42 -> V_25 ) ;
for ( V_109 = 0 ; V_109 < V_209 ; V_109 ++ )
F_398 ( V_594 , V_109 , V_593 ) ;
V_7 = F_8 ( V_1 -> V_10 , F_4 ( V_598 ) , V_594 ) ;
F_32 ( V_594 ) ;
return V_7 ;
}
static int F_399 ( struct V_42 * V_42 )
{
int V_7 ;
V_7 = F_396 ( V_42 , true ) ;
if ( V_7 )
return V_7 ;
V_7 = F_153 ( V_42 , 2 , V_209 - 1 ,
true , false ) ;
if ( V_7 )
goto V_599;
return 0 ;
V_599:
F_396 ( V_42 , false ) ;
return V_7 ;
}
static void F_400 ( struct V_42 * V_42 )
{
F_153 ( V_42 , 2 , V_209 - 1 ,
false , false ) ;
F_396 ( V_42 , false ) ;
}
static int F_401 ( struct V_131 * V_61 ,
unsigned long V_600 , void * V_601 )
{
struct V_602 * V_589 ;
struct V_42 * V_42 ;
struct V_131 * V_603 ;
struct V_1 * V_1 ;
int V_7 = 0 ;
V_42 = F_93 ( V_61 ) ;
V_1 = V_42 -> V_1 ;
V_589 = V_601 ;
switch ( V_600 ) {
case V_604 :
V_603 = V_589 -> V_603 ;
if ( ! F_402 ( V_603 ) &&
! F_403 ( V_603 ) &&
! F_404 ( V_603 ) &&
! F_405 ( V_603 ) )
return - V_97 ;
if ( ! V_589 -> V_605 )
break;
if ( F_404 ( V_603 ) &&
! F_358 ( V_1 , V_603 ) )
return - V_97 ;
if ( F_403 ( V_603 ) &&
! F_378 ( V_1 , V_603 ,
V_589 -> V_606 ) )
return - V_97 ;
if ( F_403 ( V_603 ) && F_406 ( V_61 ) )
return - V_97 ;
if ( F_407 ( V_61 ) && F_402 ( V_603 ) &&
! F_403 ( F_408 ( V_603 ) ) )
return - V_97 ;
if ( F_405 ( V_603 ) && F_406 ( V_61 ) )
return - V_97 ;
if ( F_409 ( V_61 ) && F_402 ( V_603 ) )
return - V_97 ;
break;
case V_607 :
V_603 = V_589 -> V_603 ;
if ( F_402 ( V_603 ) ) {
if ( V_589 -> V_605 )
V_7 = F_393 ( V_42 ,
V_603 ) ;
else
F_395 ( V_42 ,
V_603 ) ;
} else if ( F_404 ( V_603 ) ) {
if ( V_589 -> V_605 )
V_7 = F_361 ( V_42 ,
V_603 ) ;
else
F_362 ( V_42 ) ;
} else if ( F_403 ( V_603 ) ) {
if ( V_589 -> V_605 )
V_7 = F_382 ( V_42 ,
V_603 ) ;
else
F_384 ( V_42 ,
V_603 ) ;
} else if ( F_405 ( V_603 ) ) {
if ( V_589 -> V_605 )
V_7 = F_399 ( V_42 ) ;
else
F_400 ( V_42 ) ;
} else {
V_7 = - V_97 ;
F_39 ( 1 ) ;
}
break;
}
return V_7 ;
}
static int F_410 ( struct V_131 * V_61 ,
unsigned long V_600 , void * V_601 )
{
struct V_608 * V_589 ;
struct V_42 * V_42 ;
int V_7 ;
V_42 = F_93 ( V_61 ) ;
V_589 = V_601 ;
switch ( V_600 ) {
case V_609 :
if ( F_407 ( V_61 ) && V_42 -> V_213 ) {
V_7 = F_392 ( V_42 ,
V_589 -> V_610 ) ;
if ( V_7 )
F_46 ( V_61 , L_58 ) ;
}
break;
}
return 0 ;
}
static int F_411 ( struct V_131 * V_61 ,
unsigned long V_600 , void * V_601 )
{
switch ( V_600 ) {
case V_604 :
case V_607 :
return F_401 ( V_61 , V_600 , V_601 ) ;
case V_609 :
return F_410 ( V_61 , V_600 , V_601 ) ;
}
return 0 ;
}
static int F_412 ( struct V_131 * V_574 ,
unsigned long V_600 , void * V_601 )
{
struct V_131 * V_61 ;
struct V_611 * V_612 ;
int V_549 ;
F_413 (lag_dev, dev, iter) {
if ( F_172 ( V_61 ) ) {
V_549 = F_411 ( V_61 , V_600 , V_601 ) ;
if ( V_549 )
return V_549 ;
}
}
return 0 ;
}
static int F_414 ( struct V_1 * V_1 ,
struct V_131 * V_591 )
{
T_3 V_108 = F_394 ( V_591 ) ;
struct V_220 * V_221 ;
V_221 = F_415 ( V_1 , V_108 ) ;
if ( ! V_221 ) {
V_221 = F_416 ( V_1 , V_108 ) ;
if ( F_417 ( V_221 ) )
return F_418 ( V_221 ) ;
}
V_221 -> V_51 ++ ;
return 0 ;
}
static void F_419 ( struct V_1 * V_1 ,
struct V_131 * V_591 )
{
T_3 V_108 = F_394 ( V_591 ) ;
struct V_220 * V_221 ;
V_221 = F_415 ( V_1 , V_108 ) ;
if ( V_221 && V_221 -> V_613 )
F_420 ( V_1 , V_221 -> V_613 ) ;
if ( V_221 && -- V_221 -> V_51 == 0 )
F_357 ( V_1 , V_221 ) ;
}
static int F_421 ( struct V_131 * V_558 ,
unsigned long V_600 , void * V_601 )
{
struct V_602 * V_589 ;
struct V_131 * V_603 ;
struct V_1 * V_1 ;
int V_7 = 0 ;
V_1 = F_336 ( V_558 ) ;
if ( ! V_1 )
return 0 ;
V_589 = V_601 ;
switch ( V_600 ) {
case V_604 :
V_603 = V_589 -> V_603 ;
if ( ! F_402 ( V_603 ) )
return - V_97 ;
if ( F_402 ( V_603 ) &&
V_558 != V_1 -> V_559 . V_61 )
return - V_97 ;
break;
case V_607 :
V_603 = V_589 -> V_603 ;
if ( F_402 ( V_603 ) ) {
if ( V_589 -> V_605 )
V_7 = F_414 ( V_1 ,
V_603 ) ;
else
F_419 ( V_1 ,
V_603 ) ;
} else {
V_7 = - V_97 ;
F_39 ( 1 ) ;
}
break;
}
return V_7 ;
}
static T_3 F_422 ( const struct V_1 * V_1 )
{
return F_423 ( V_1 -> V_534 . V_614 ,
V_615 ) ;
}
static int F_317 ( struct V_1 * V_1 , T_3 V_108 , bool V_616 )
{
char V_617 [ V_618 ] ;
F_424 ( V_617 , ! V_616 , V_108 , 0 ) ;
return F_8 ( V_1 -> V_10 , F_4 ( V_619 ) , V_617 ) ;
}
static struct V_220 * F_425 ( struct V_1 * V_1 ,
struct V_131 * V_558 )
{
struct V_620 * V_61 = V_1 -> V_281 -> V_61 ;
struct V_220 * V_221 ;
T_3 V_621 , V_108 ;
int V_7 ;
V_621 = F_422 ( V_1 ) ;
if ( V_621 == V_615 ) {
F_255 ( V_61 , L_59 ) ;
return F_426 ( - V_622 ) ;
}
V_108 = F_427 ( V_621 ) ;
V_7 = F_317 ( V_1 , V_108 , true ) ;
if ( V_7 ) {
F_255 ( V_61 , L_60 , V_108 ) ;
return F_426 ( V_7 ) ;
}
V_221 = F_50 ( sizeof( * V_221 ) , V_38 ) ;
if ( ! V_221 )
goto V_623;
V_221 -> V_222 = V_624 ;
V_221 -> V_108 = V_108 ;
V_221 -> V_61 = V_558 ;
F_159 ( & V_221 -> V_70 , & V_1 -> V_534 . V_70 ) ;
F_428 ( V_621 , V_1 -> V_534 . V_614 ) ;
return V_221 ;
V_623:
F_317 ( V_1 , V_108 , false ) ;
return F_426 ( - V_39 ) ;
}
static void F_429 ( struct V_1 * V_1 ,
struct V_220 * V_221 )
{
T_3 V_621 = F_430 ( V_221 -> V_108 ) ;
T_3 V_108 = V_221 -> V_108 ;
F_431 ( V_621 , V_1 -> V_534 . V_614 ) ;
F_53 ( & V_221 -> V_70 ) ;
if ( V_221 -> V_613 )
F_420 ( V_1 , V_221 -> V_613 ) ;
F_32 ( V_221 ) ;
F_317 ( V_1 , V_108 , false ) ;
}
static int F_432 ( struct V_42 * V_210 , T_3 V_108 ,
bool V_107 )
{
enum V_105 V_106 = V_206 ;
T_3 V_109 = F_433 ( V_210 ) ;
return F_74 ( V_210 , V_106 , V_107 , V_108 ,
V_109 ) ;
}
static int F_434 ( struct V_42 * V_210 ,
struct V_131 * V_558 )
{
struct V_220 * V_221 ;
int V_7 ;
V_221 = F_435 ( V_210 -> V_1 , V_558 ) ;
if ( ! V_221 ) {
V_221 = F_425 ( V_210 -> V_1 , V_558 ) ;
if ( F_417 ( V_221 ) )
return F_418 ( V_221 ) ;
}
V_7 = F_436 ( V_210 , V_221 -> V_108 , true ) ;
if ( V_7 )
goto V_625;
V_7 = F_432 ( V_210 , V_221 -> V_108 , true ) ;
if ( V_7 )
goto V_626;
F_437 ( V_210 , V_221 ) ;
V_221 -> V_51 ++ ;
F_55 ( V_210 -> V_61 , L_61 , V_221 -> V_108 ) ;
return 0 ;
V_626:
F_436 ( V_210 , V_221 -> V_108 , false ) ;
V_625:
if ( ! V_221 -> V_51 )
F_429 ( V_210 -> V_1 , V_221 ) ;
return V_7 ;
}
static void V_624 ( struct V_42 * V_210 )
{
struct V_220 * V_221 = F_165 ( V_210 ) ;
F_55 ( V_210 -> V_61 , L_62 , V_221 -> V_108 ) ;
F_432 ( V_210 , V_221 -> V_108 , false ) ;
F_436 ( V_210 , V_221 -> V_108 , false ) ;
F_354 ( V_210 , V_221 -> V_108 ) ;
F_437 ( V_210 , NULL ) ;
if ( -- V_221 -> V_51 == 0 )
F_429 ( V_210 -> V_1 , V_221 ) ;
}
static int F_438 ( struct V_42 * V_210 ,
struct V_131 * V_558 )
{
struct V_220 * V_221 = F_165 ( V_210 ) ;
T_3 V_109 = F_433 ( V_210 ) ;
struct V_131 * V_61 = V_210 -> V_61 ;
int V_7 ;
if ( V_221 && ! F_39 ( ! V_221 -> V_222 ) )
V_221 -> V_222 ( V_210 ) ;
V_7 = F_434 ( V_210 , V_558 ) ;
if ( V_7 ) {
F_46 ( V_61 , L_63 ) ;
return V_7 ;
}
V_7 = F_79 ( V_210 , V_109 , true ) ;
if ( V_7 ) {
F_46 ( V_61 , L_64 ) ;
goto V_627;
}
V_210 -> V_560 = 1 ;
V_210 -> V_561 = 1 ;
V_210 -> V_562 = 1 ;
V_210 -> V_563 = 1 ;
V_210 -> V_564 = 0 ;
V_210 -> V_565 = 1 ;
V_210 -> V_566 = 1 ;
return 0 ;
V_627:
V_624 ( V_210 ) ;
return V_7 ;
}
static void F_439 ( struct V_42 * V_210 )
{
T_3 V_109 = F_433 ( V_210 ) ;
F_79 ( V_210 , V_109 , false ) ;
V_624 ( V_210 ) ;
V_210 -> V_560 = 0 ;
V_210 -> V_561 = 0 ;
V_210 -> V_562 = 0 ;
V_210 -> V_563 = 0 ;
V_210 -> V_564 = 0 ;
V_210 -> V_566 = 0 ;
}
static bool
F_440 ( const struct V_42 * V_42 ,
const struct V_131 * V_558 )
{
struct V_42 * V_210 ;
F_41 (mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct V_131 * V_61 = F_441 ( V_210 ) ;
if ( V_61 && V_61 == V_558 )
return false ;
}
return true ;
}
static int F_442 ( struct V_131 * V_61 ,
unsigned long V_600 , void * V_601 ,
T_3 V_109 )
{
struct V_42 * V_42 = F_93 ( V_61 ) ;
struct V_602 * V_589 = V_601 ;
struct V_42 * V_210 ;
struct V_131 * V_603 ;
int V_7 = 0 ;
V_210 = F_162 ( V_42 , V_109 ) ;
if ( ! V_210 )
return 0 ;
switch ( V_600 ) {
case V_604 :
V_603 = V_589 -> V_603 ;
if ( ! F_404 ( V_603 ) )
return - V_97 ;
if ( ! V_589 -> V_605 )
break;
if ( F_404 ( V_603 ) &&
! F_440 ( V_42 ,
V_603 ) )
return - V_97 ;
break;
case V_607 :
V_603 = V_589 -> V_603 ;
if ( F_404 ( V_603 ) ) {
if ( V_589 -> V_605 )
V_7 = F_438 ( V_210 ,
V_603 ) ;
else
F_439 ( V_210 ) ;
} else {
V_7 = - V_97 ;
F_39 ( 1 ) ;
}
break;
}
return V_7 ;
}
static int F_443 ( struct V_131 * V_574 ,
unsigned long V_600 , void * V_601 ,
T_3 V_109 )
{
struct V_131 * V_61 ;
struct V_611 * V_612 ;
int V_549 ;
F_413 (lag_dev, dev, iter) {
if ( F_172 ( V_61 ) ) {
V_549 = F_442 ( V_61 , V_600 , V_601 ,
V_109 ) ;
if ( V_549 )
return V_549 ;
}
}
return 0 ;
}
static int F_444 ( struct V_131 * V_591 ,
unsigned long V_600 , void * V_601 )
{
struct V_131 * V_628 = F_408 ( V_591 ) ;
T_3 V_109 = F_394 ( V_591 ) ;
if ( F_172 ( V_628 ) )
return F_442 ( V_628 , V_600 , V_601 ,
V_109 ) ;
else if ( F_403 ( V_628 ) )
return F_443 ( V_628 , V_600 , V_601 ,
V_109 ) ;
return 0 ;
}
static bool F_445 ( unsigned long V_600 , void * V_601 )
{
struct V_602 * V_589 = V_601 ;
if ( V_600 != V_604 && V_600 != V_607 )
return false ;
return F_446 ( V_589 -> V_603 ) ;
}
static int F_447 ( struct V_629 * V_630 ,
unsigned long V_600 , void * V_601 )
{
struct V_131 * V_61 = F_448 ( V_601 ) ;
int V_7 = 0 ;
if ( V_600 == V_631 || V_600 == V_632 )
V_7 = F_449 ( V_61 ) ;
else if ( F_445 ( V_600 , V_601 ) )
V_7 = F_450 ( V_61 , V_600 , V_601 ) ;
else if ( F_172 ( V_61 ) )
V_7 = F_411 ( V_61 , V_600 , V_601 ) ;
else if ( F_403 ( V_61 ) )
V_7 = F_412 ( V_61 , V_600 , V_601 ) ;
else if ( F_404 ( V_61 ) )
V_7 = F_421 ( V_61 , V_600 , V_601 ) ;
else if ( F_402 ( V_61 ) )
V_7 = F_444 ( V_61 , V_600 , V_601 ) ;
return F_451 ( V_7 ) ;
}
static int T_9 F_452 ( void )
{
int V_7 ;
F_453 ( & V_633 ) ;
F_454 ( & V_634 ) ;
F_455 ( & V_635 ) ;
V_7 = F_456 ( & V_636 ) ;
if ( V_7 )
goto V_637;
V_7 = F_457 ( & V_638 ) ;
if ( V_7 )
goto V_639;
return 0 ;
V_639:
F_458 ( & V_636 ) ;
V_637:
F_459 ( & V_635 ) ;
F_460 ( & V_634 ) ;
F_461 ( & V_633 ) ;
return V_7 ;
}
static void T_10 F_462 ( void )
{
F_463 ( & V_638 ) ;
F_458 ( & V_636 ) ;
F_459 ( & V_635 ) ;
F_460 ( & V_634 ) ;
F_461 ( & V_633 ) ;
}
