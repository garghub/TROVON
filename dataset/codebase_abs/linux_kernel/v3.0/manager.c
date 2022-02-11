static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_6 ? V_2 -> V_6 -> V_5 : L_2 ) ;
}
int F_3 ( struct V_7 * V_8 , void * V_9 )
{
const char * V_10 = V_9 ;
return F_4 ( V_8 -> V_5 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 , V_2 -> V_11 . V_12 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
T_3 V_15 ;
int V_16 ;
if ( sscanf ( V_3 , L_4 , & V_15 ) != 1 )
return - V_17 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
V_11 . V_12 = V_15 ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
char * V_3 )
{
enum V_21 V_22 ;
V_22 = V_2 -> V_11 . V_23 ;
F_8 ( V_22 >= F_9 ( V_24 ) ) ;
return snprintf ( V_3 , V_4 , L_1 , V_24 [ V_22 ] ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
enum V_21 V_22 ;
struct V_14 V_11 ;
int V_16 ;
for ( V_22 = V_25 ;
V_22 < F_9 ( V_24 ) ; V_22 ++ ) {
if ( F_4 ( V_3 , V_24 [ V_22 ] ) )
break;
}
if ( V_22 == F_9 ( V_24 ) )
return - V_17 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
V_11 . V_23 = V_22 ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 , V_2 -> V_11 . V_26 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
T_3 V_27 ;
int V_16 ;
if ( sscanf ( V_3 , L_4 , & V_27 ) != 1 )
return - V_17 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
V_11 . V_26 = V_27 ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 , V_2 -> V_11 . V_28 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
int V_29 ;
int V_16 ;
if ( sscanf ( V_3 , L_4 , & V_29 ) != 1 )
return - V_17 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
V_11 . V_28 = V_29 ? true : false ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_15 (
struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 , V_2 -> V_11 . V_30 ) ;
}
static T_1 F_16 (
struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
int V_29 ;
int V_16 ;
if ( sscanf ( V_3 , L_4 , & V_29 ) != 1 )
return - V_17 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
V_11 . V_30 = V_29 ? true : false ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_17 ( struct V_31 * V_32 , struct V_33 * V_34 ,
char * V_3 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
V_35 = F_18 ( V_32 , struct V_1 , V_32 ) ;
V_37 = F_18 ( V_34 , struct V_36 , V_34 ) ;
if ( ! V_37 -> V_38 )
return - V_39 ;
return V_37 -> V_38 ( V_35 , V_3 ) ;
}
static T_1 F_19 ( struct V_31 * V_32 , struct V_33 * V_34 ,
const char * V_3 , T_2 V_13 )
{
struct V_1 * V_35 ;
struct V_36 * V_37 ;
V_35 = F_18 ( V_32 , struct V_1 , V_32 ) ;
V_37 = F_18 ( V_34 , struct V_36 , V_34 ) ;
if ( ! V_37 -> V_40 )
return - V_39 ;
return V_37 -> V_40 ( V_35 , V_3 , V_13 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_41 ;
int V_16 ;
if ( V_8 -> V_35 ) {
F_21 ( L_5 ,
V_8 -> V_5 , V_8 -> V_35 -> V_5 ) ;
return - V_17 ;
}
if ( ( V_2 -> V_42 & V_8 -> type ) == 0 ) {
F_21 ( L_6 ,
V_8 -> V_5 , V_2 -> V_5 ) ;
return - V_17 ;
}
for ( V_41 = 0 ; V_41 < V_2 -> V_43 ; V_41 ++ ) {
struct V_44 * V_45 = V_2 -> V_46 [ V_41 ] ;
if ( V_45 -> V_35 != V_2 || ! V_45 -> V_11 . V_47 )
continue;
V_16 = F_22 ( V_45 , V_8 ) ;
if ( V_16 )
return V_16 ;
}
V_8 -> V_35 = V_2 ;
V_2 -> V_6 = V_8 ;
V_2 -> V_48 = true ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 ) {
F_21 ( L_7 ) ;
return - V_17 ;
}
V_2 -> V_6 -> V_35 = NULL ;
V_2 -> V_6 = NULL ;
V_2 -> V_48 = true ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_49 = F_25 ( 500 ) ;
T_3 V_50 ;
if ( V_2 -> V_6 -> type == V_51 ) {
V_50 = V_52 ;
} else if ( V_2 -> V_6 -> type == V_53 ) {
V_50 = V_54 ;
} else {
if ( V_2 -> V_55 == V_56 )
V_50 = V_57 ;
else
V_50 = V_58 ;
}
return F_26 ( V_50 , V_49 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned long V_49 = F_25 ( 500 ) ;
struct V_59 * V_60 ;
T_3 V_50 ;
int V_16 ;
int V_41 ;
struct V_7 * V_8 = V_2 -> V_6 ;
if ( ! V_8 || V_8 -> V_61 != V_62 )
return 0 ;
if ( V_8 -> type == V_51
|| V_8 -> type == V_53 ) {
V_50 = V_52 | V_54 ;
} else {
if ( V_8 -> V_63 & V_64 ) {
enum V_65 V_66 ;
V_66 = V_8 -> V_67 -> V_68 ( V_8 ) ;
if ( V_66 != V_69 )
return 0 ;
V_50 = ( V_8 -> V_35 -> V_55 == V_56 ) ?
V_70
: V_71 ;
} else {
V_50 = ( V_8 -> V_35 -> V_55 == V_56 ) ?
V_57
: V_58 ;
}
}
V_60 = & V_72 . V_73 [ V_2 -> V_55 ] ;
V_41 = 0 ;
while ( 1 ) {
unsigned long V_74 ;
bool V_75 , V_76 ;
F_28 ( & V_72 . V_77 , V_74 ) ;
V_76 = V_60 -> V_76 ;
V_75 = V_60 -> V_75 ;
F_29 ( & V_72 . V_77 , V_74 ) ;
if ( ! V_76 && ! V_75 ) {
V_16 = 0 ;
break;
}
if ( V_41 ++ == 3 ) {
F_21 ( L_8 ,
V_2 -> V_55 ) ;
V_16 = 0 ;
break;
}
V_16 = F_26 ( V_50 , V_49 ) ;
if ( V_16 == - V_78 )
break;
if ( V_16 ) {
F_21 ( L_9 , V_2 -> V_55 ) ;
break;
}
}
return V_16 ;
}
int F_30 ( struct V_44 * V_45 )
{
unsigned long V_49 = F_25 ( 500 ) ;
struct V_79 * V_80 ;
struct V_7 * V_8 ;
T_3 V_50 ;
int V_16 ;
int V_41 ;
if ( ! V_45 -> V_35 )
return 0 ;
V_8 = V_45 -> V_35 -> V_6 ;
if ( ! V_8 || V_8 -> V_61 != V_62 )
return 0 ;
if ( V_8 -> type == V_51
|| V_8 -> type == V_53 ) {
V_50 = V_52 | V_54 ;
} else {
if ( V_8 -> V_63 & V_64 ) {
enum V_65 V_66 ;
V_66 = V_8 -> V_67 -> V_68 ( V_8 ) ;
if ( V_66 != V_69 )
return 0 ;
V_50 = ( V_8 -> V_35 -> V_55 == V_56 ) ?
V_70
: V_71 ;
} else {
V_50 = ( V_8 -> V_35 -> V_55 == V_56 ) ?
V_57
: V_58 ;
}
}
V_80 = & V_72 . V_81 [ V_45 -> V_55 ] ;
V_41 = 0 ;
while ( 1 ) {
unsigned long V_74 ;
bool V_75 , V_76 ;
F_28 ( & V_72 . V_77 , V_74 ) ;
V_76 = V_80 -> V_76 ;
V_75 = V_80 -> V_75 ;
F_29 ( & V_72 . V_77 , V_74 ) ;
if ( ! V_76 && ! V_75 ) {
V_16 = 0 ;
break;
}
if ( V_41 ++ == 3 ) {
F_21 ( L_10 ,
V_45 -> V_55 ) ;
V_16 = 0 ;
break;
}
V_16 = F_26 ( V_50 , V_49 ) ;
if ( V_16 == - V_78 )
break;
if ( V_16 ) {
F_21 ( L_11 , V_45 -> V_55 ) ;
break;
}
}
return V_16 ;
}
static int F_31 ( struct V_44 * V_45 )
{
return V_45 -> V_11 . V_47 && V_45 -> V_35 && V_45 -> V_35 -> V_6 ;
}
static bool F_32 ( int V_82 , int y1 , int V_83 , int V_84 ,
int V_85 , int V_86 , int V_87 , int V_88 )
{
if ( V_82 < V_85 || y1 < V_86 )
return false ;
if ( V_82 + V_83 > V_85 + V_87 )
return false ;
if ( y1 + V_84 > V_86 + V_88 )
return false ;
return true ;
}
static bool F_33 ( int V_82 , int y1 , int V_83 , int V_84 ,
int V_85 , int V_86 , int V_87 , int V_88 )
{
if ( V_82 >= V_85 + V_87 )
return false ;
if ( V_85 >= V_82 + V_83 )
return false ;
if ( y1 >= V_86 + V_88 )
return false ;
if ( V_86 >= y1 + V_84 )
return false ;
return true ;
}
static bool F_34 ( struct V_79 * V_80 )
{
if ( V_80 -> V_89 != 0 && V_80 -> V_90 != V_80 -> V_89 )
return true ;
if ( V_80 -> V_91 != 0 && V_80 -> V_92 != V_80 -> V_91 )
return true ;
return false ;
}
static int F_35 ( enum V_93 V_94 )
{
struct V_79 * V_95 ;
struct V_59 * V_60 ;
T_4 V_96 , V_97 ;
T_4 V_98 , V_99 , V_100 , V_101 ;
T_3 V_102 ;
int V_16 ;
T_4 V_103 , V_104 , V_105 , V_106 ;
F_36 ( L_4 , V_94 ) ;
V_95 = & V_72 . V_81 [ V_94 ] ;
if ( ! V_95 -> V_47 ) {
F_37 ( V_94 , 0 ) ;
return 0 ;
}
V_60 = & V_72 . V_73 [ V_95 -> V_107 ] ;
V_98 = V_95 -> V_108 ;
V_99 = V_95 -> V_109 ;
V_100 = V_95 -> V_90 ;
V_101 = V_95 -> V_92 ;
V_96 = V_95 -> V_89 == 0 ? V_95 -> V_90 : V_95 -> V_89 ;
V_97 = V_95 -> V_91 == 0 ? V_95 -> V_92 : V_95 -> V_91 ;
V_102 = V_95 -> V_102 ;
V_103 = V_100 ;
V_104 = V_101 ;
V_105 = V_96 ;
V_106 = V_97 ;
if ( V_95 -> V_110 && V_60 -> V_111 ) {
unsigned V_112 ;
unsigned V_113 = V_100 , V_114 = V_96 ;
unsigned V_115 = V_101 , V_116 = V_97 ;
if ( ! F_33 ( V_60 -> V_98 , V_60 -> V_99 , V_60 -> V_100 , V_60 -> V_101 ,
V_98 , V_99 , V_96 , V_97 ) ) {
F_37 ( V_94 , 0 ) ;
return 0 ;
}
switch ( V_95 -> V_117 ) {
case V_118 :
V_112 = 8 ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_112 = 16 ;
break;
case V_127 :
V_112 = 24 ;
break;
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_112 = 32 ;
break;
default:
F_38 () ;
}
if ( V_60 -> V_98 > V_95 -> V_108 ) {
V_98 = 0 ;
V_96 -= ( V_60 -> V_98 - V_95 -> V_108 ) ;
V_102 += ( V_60 -> V_98 - V_95 -> V_108 ) *
V_113 / V_114 * V_112 / 8 ;
} else {
V_98 = V_95 -> V_108 - V_60 -> V_98 ;
}
if ( V_60 -> V_99 > V_95 -> V_109 ) {
V_99 = 0 ;
V_97 -= ( V_60 -> V_99 - V_95 -> V_109 ) ;
V_102 += ( V_60 -> V_99 - V_95 -> V_109 ) *
V_115 / V_116 *
V_95 -> V_132 * V_112 / 8 ;
} else {
V_99 = V_95 -> V_109 - V_60 -> V_99 ;
}
if ( V_60 -> V_100 < ( V_98 + V_96 ) )
V_96 -= ( V_98 + V_96 ) - ( V_60 -> V_100 ) ;
if ( V_60 -> V_101 < ( V_99 + V_97 ) )
V_97 -= ( V_99 + V_97 ) - ( V_60 -> V_101 ) ;
V_100 = V_100 * V_96 / V_105 ;
V_101 = V_101 * V_97 / V_106 ;
if ( ( V_100 & 1 ) &&
( V_95 -> V_117 == V_121 ||
V_95 -> V_117 == V_122 ) ) {
if ( V_103 > V_100 )
V_100 += 1 ;
else
V_100 -= 1 ;
}
}
V_16 = F_39 ( V_94 ,
V_102 ,
V_95 -> V_132 ,
V_98 , V_99 ,
V_100 , V_101 ,
V_96 , V_97 ,
V_95 -> V_117 ,
V_95 -> V_133 ,
V_95 -> V_134 ,
V_95 -> V_135 ,
V_95 -> V_136 ,
V_95 -> V_137 ,
V_95 -> V_138 ,
V_95 -> V_107 ,
V_95 -> V_139 ) ;
if ( V_16 ) {
F_21 ( L_12 , V_94 ) ;
F_37 ( V_94 , 0 ) ;
return V_16 ;
}
F_40 ( V_94 , V_95 -> V_140 ) ;
F_41 ( V_94 , V_95 -> V_141 ) ;
F_42 ( V_94 , V_95 -> V_142 , V_95 -> V_143 ) ;
F_37 ( V_94 , 1 ) ;
return 0 ;
}
static void F_43 ( enum V_144 V_107 )
{
struct V_59 * V_95 ;
F_36 ( L_4 , V_107 ) ;
V_95 = & V_72 . V_73 [ V_107 ] ;
F_44 ( V_107 , V_95 -> V_12 ) ;
F_45 ( V_107 , V_95 -> V_23 , V_95 -> V_26 ) ;
F_46 ( V_107 , V_95 -> V_28 ) ;
F_47 ( V_107 , V_95 -> V_30 ) ;
}
static int F_48 ( void )
{
struct V_79 * V_80 ;
struct V_59 * V_60 ;
const int V_145 = F_49 () ;
const int V_146 = F_50 () ;
int V_41 ;
int V_16 ;
bool V_147 [ V_148 ] ;
bool V_149 [ V_148 ] ;
bool V_150 ;
V_16 = 0 ;
V_150 = false ;
for ( V_41 = 0 ; V_41 < V_146 ; V_41 ++ ) {
V_147 [ V_41 ] = F_51 ( V_41 ) ;
V_149 [ V_41 ] = false ;
}
for ( V_41 = 0 ; V_41 < V_145 ; ++ V_41 ) {
V_80 = & V_72 . V_81 [ V_41 ] ;
V_60 = & V_72 . V_73 [ V_80 -> V_107 ] ;
if ( ! V_80 -> V_76 )
continue;
if ( V_80 -> V_110 && ! V_60 -> V_111 )
continue;
if ( V_147 [ V_80 -> V_107 ] ) {
V_150 = true ;
continue;
}
V_16 = F_35 ( V_41 ) ;
if ( V_16 )
F_21 ( L_13 , V_41 ) ;
V_80 -> V_76 = false ;
V_80 -> V_75 = true ;
V_149 [ V_80 -> V_107 ] = true ;
}
for ( V_41 = 0 ; V_41 < V_146 ; ++ V_41 ) {
V_60 = & V_72 . V_73 [ V_41 ] ;
if ( ! V_60 -> V_76 )
continue;
if ( V_60 -> V_110 && ! V_60 -> V_111 )
continue;
if ( V_147 [ V_41 ] ) {
V_150 = true ;
continue;
}
F_43 ( V_41 ) ;
V_60 -> V_76 = false ;
V_60 -> V_75 = true ;
V_149 [ V_41 ] = true ;
}
for ( V_41 = 0 ; V_41 < V_146 ; ++ V_41 ) {
V_60 = & V_72 . V_73 [ V_41 ] ;
if ( ! V_149 [ V_41 ] )
continue;
if ( ! V_60 -> V_151 )
F_52 ( V_41 ) ;
}
if ( V_150 )
V_16 = 1 ;
else
V_16 = 0 ;
return V_16 ;
}
static void F_53 ( T_4 * V_98 , T_4 * V_100 )
{
T_4 V_82 , V_85 ;
V_82 = * V_98 ;
V_85 = * V_98 + * V_100 ;
V_82 &= ~ 1 ;
V_85 = F_54 ( V_85 , 2 ) ;
* V_98 = V_82 ;
* V_100 = V_85 - V_82 ;
}
void F_55 ( struct V_7 * V_8 ,
T_4 * V_152 , T_4 * V_153 , T_4 * V_154 , T_4 * V_155 , bool V_156 )
{
struct V_79 * V_80 ;
struct V_59 * V_60 ;
const int V_145 = F_49 () ;
struct V_1 * V_2 ;
int V_41 ;
T_4 V_98 , V_99 , V_100 , V_101 ;
unsigned long V_74 ;
bool V_157 ;
V_98 = * V_152 ;
V_99 = * V_153 ;
V_100 = * V_154 ;
V_101 = * V_155 ;
F_56 ( L_14 ,
* V_152 , * V_153 , * V_154 , * V_155 ) ;
V_2 = V_8 -> V_35 ;
if ( ! V_2 ) {
F_56 ( L_15 ) ;
return;
}
F_53 ( & V_98 , & V_100 ) ;
F_28 ( & V_72 . V_77 , V_74 ) ;
do {
V_157 = false ;
for ( V_41 = 0 ; V_41 < V_145 ; ++ V_41 ) {
unsigned V_82 , y1 , V_85 , V_86 ;
unsigned V_96 , V_97 ;
V_80 = & V_72 . V_81 [ V_41 ] ;
if ( V_80 -> V_107 != V_2 -> V_55 )
continue;
V_80 -> V_76 = true ;
if ( ! V_156 )
continue;
if ( ! V_80 -> V_47 )
continue;
if ( ! F_34 ( V_80 ) )
continue;
V_96 = V_80 -> V_89 == 0 ?
V_80 -> V_90 : V_80 -> V_89 ;
V_97 = V_80 -> V_91 == 0 ?
V_80 -> V_92 : V_80 -> V_91 ;
if ( ! F_33 ( V_98 , V_99 , V_100 , V_101 ,
V_80 -> V_108 , V_80 -> V_109 ,
V_96 , V_97 ) )
continue;
if ( F_32 ( V_80 -> V_108 , V_80 -> V_109 , V_96 , V_97 ,
V_98 , V_99 , V_100 , V_101 ) )
continue;
if ( V_98 > V_80 -> V_108 )
V_82 = V_80 -> V_108 ;
else
V_82 = V_98 ;
if ( V_99 > V_80 -> V_109 )
y1 = V_80 -> V_109 ;
else
y1 = V_99 ;
if ( ( V_98 + V_100 ) < ( V_80 -> V_108 + V_96 ) )
V_85 = V_80 -> V_108 + V_96 ;
else
V_85 = V_98 + V_100 ;
if ( ( V_99 + V_101 ) < ( V_80 -> V_109 + V_97 ) )
V_86 = V_80 -> V_109 + V_97 ;
else
V_86 = V_99 + V_101 ;
V_98 = V_82 ;
V_99 = y1 ;
V_100 = V_85 - V_82 ;
V_101 = V_86 - y1 ;
F_53 ( & V_98 , & V_100 ) ;
F_56 ( L_16
L_17 ,
V_41 , V_98 , V_99 , V_100 , V_101 ) ;
V_157 = true ;
}
} while ( V_157 );
V_60 = & V_72 . V_73 [ V_2 -> V_55 ] ;
V_60 -> V_111 = true ;
V_60 -> V_156 = V_156 ;
V_60 -> V_98 = V_98 ;
V_60 -> V_99 = V_99 ;
V_60 -> V_100 = V_100 ;
V_60 -> V_101 = V_101 ;
F_48 () ;
V_60 -> V_111 = false ;
F_29 ( & V_72 . V_77 , V_74 ) ;
* V_152 = V_98 ;
* V_153 = V_99 ;
* V_154 = V_100 ;
* V_155 = V_101 ;
}
void F_57 ( struct V_7 * V_8 )
{
struct V_59 * V_60 ;
struct V_79 * V_80 ;
const int V_145 = F_49 () ;
const int V_146 = F_50 () ;
struct V_1 * V_2 ;
int V_41 ;
V_2 = V_8 -> V_35 ;
for ( V_41 = 0 ; V_41 < V_145 ; ++ V_41 ) {
V_80 = & V_72 . V_81 [ V_41 ] ;
if ( V_80 -> V_107 != V_2 -> V_55 )
continue;
V_80 -> V_75 = false ;
}
for ( V_41 = 0 ; V_41 < V_146 ; ++ V_41 ) {
V_60 = & V_72 . V_73 [ V_41 ] ;
if ( V_2 -> V_55 != V_41 )
continue;
V_60 -> V_75 = false ;
}
V_8 -> V_35 -> V_29 ( V_8 -> V_35 ) ;
}
static void F_58 ( void * V_9 , T_3 V_158 )
{
struct V_59 * V_60 ;
struct V_79 * V_80 ;
const int V_145 = F_49 () ;
const int V_146 = F_50 () ;
int V_41 , V_16 ;
bool V_147 [ V_148 ] ;
T_3 V_159 ;
for ( V_41 = 0 ; V_41 < V_146 ; V_41 ++ )
V_147 [ V_41 ] = F_51 ( V_41 ) ;
F_59 ( & V_72 . V_77 ) ;
for ( V_41 = 0 ; V_41 < V_145 ; ++ V_41 ) {
V_80 = & V_72 . V_81 [ V_41 ] ;
if ( ! V_147 [ V_80 -> V_107 ] )
V_80 -> V_75 = false ;
}
for ( V_41 = 0 ; V_41 < V_146 ; ++ V_41 ) {
V_60 = & V_72 . V_73 [ V_41 ] ;
if ( ! V_147 [ V_41 ] )
V_60 -> V_75 = false ;
}
V_16 = F_48 () ;
if ( V_16 == 1 )
goto V_160;
for ( V_41 = 0 ; V_41 < V_146 ; V_41 ++ )
V_147 [ V_41 ] = F_51 ( V_41 ) ;
for ( V_41 = 0 ; V_41 < V_146 ; ++ V_41 ) {
if ( V_147 [ V_41 ] )
goto V_160;
}
V_159 = V_57 | V_52 |
V_54 ;
if ( F_60 ( V_161 ) )
V_159 |= V_58 ;
F_61 ( F_58 , NULL , V_159 ) ;
V_72 . V_162 = false ;
V_160:
F_62 ( & V_72 . V_77 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
struct V_59 * V_60 ;
int V_41 ;
struct V_44 * V_45 ;
int V_163 = 0 ;
bool V_164 ;
unsigned long V_74 ;
int V_16 ;
F_56 ( L_18 , V_2 -> V_5 ) ;
F_28 ( & V_72 . V_77 , V_74 ) ;
for ( V_41 = 0 ; V_41 < F_64 () ; ++ V_41 ) {
struct V_7 * V_8 ;
V_45 = F_65 ( V_41 ) ;
if ( ! ( V_45 -> V_63 & V_165 ) )
continue;
V_80 = & V_72 . V_81 [ V_45 -> V_55 ] ;
if ( ! F_31 ( V_45 ) ) {
if ( V_80 -> V_47 ) {
V_80 -> V_47 = false ;
V_80 -> V_76 = true ;
}
continue;
}
if ( ! V_45 -> V_166 ) {
if ( V_80 -> V_47 )
++ V_163 ;
continue;
}
V_8 = V_45 -> V_35 -> V_6 ;
if ( F_22 ( V_45 , V_8 ) ) {
if ( V_80 -> V_47 ) {
V_80 -> V_47 = false ;
V_80 -> V_76 = true ;
}
continue;
}
V_45 -> V_166 = false ;
V_80 -> V_76 = true ;
V_80 -> V_102 = V_45 -> V_11 . V_102 ;
V_80 -> V_167 = V_45 -> V_11 . V_167 ;
V_80 -> V_139 = V_45 -> V_11 . V_139 ;
V_80 -> V_132 = V_45 -> V_11 . V_132 ;
V_80 -> V_90 = V_45 -> V_11 . V_90 ;
V_80 -> V_92 = V_45 -> V_11 . V_92 ;
V_80 -> V_117 = V_45 -> V_11 . V_117 ;
V_80 -> V_135 = V_45 -> V_11 . V_135 ;
V_80 -> V_134 = V_45 -> V_11 . V_134 ;
V_80 -> V_136 = V_45 -> V_11 . V_136 ;
V_80 -> V_108 = V_45 -> V_11 . V_108 ;
V_80 -> V_109 = V_45 -> V_11 . V_109 ;
V_80 -> V_89 = V_45 -> V_11 . V_89 ;
V_80 -> V_91 = V_45 -> V_11 . V_91 ;
V_80 -> V_137 = V_45 -> V_11 . V_137 ;
V_80 -> V_138 = V_45 -> V_11 . V_138 ;
V_80 -> V_140 =
F_66 ( V_8 , V_45 -> V_11 . V_117 ) ;
V_80 -> V_133 = V_8 -> type == V_51 ;
V_80 -> V_107 = V_45 -> V_35 -> V_55 ;
V_80 -> V_47 = true ;
V_80 -> V_110 =
V_8 -> V_63 & V_64 &&
V_8 -> V_67 -> V_68 ( V_8 ) !=
V_69 ;
++ V_163 ;
}
F_67 (mgr, &manager_list, list) {
struct V_7 * V_8 ;
if ( ! ( V_2 -> V_63 & V_168 ) )
continue;
V_60 = & V_72 . V_73 [ V_2 -> V_55 ] ;
if ( V_2 -> V_48 ) {
V_2 -> V_48 = false ;
V_2 -> V_166 = true ;
}
if ( ! V_2 -> V_166 )
continue;
if ( ! V_2 -> V_6 )
continue;
V_8 = V_2 -> V_6 ;
V_2 -> V_166 = false ;
V_60 -> V_76 = true ;
V_60 -> V_12 = V_2 -> V_11 . V_12 ;
V_60 -> V_23 = V_2 -> V_11 . V_23 ;
V_60 -> V_26 = V_2 -> V_11 . V_26 ;
V_60 -> V_28 = V_2 -> V_11 . V_28 ;
V_60 -> V_30 = V_2 -> V_11 . V_30 ;
V_60 -> V_151 =
V_8 -> V_63 & V_64 ;
V_60 -> V_110 =
V_8 -> V_63 & V_64 &&
V_8 -> V_67 -> V_68 ( V_8 ) !=
V_69 ;
}
V_164 = false ;
for ( V_41 = 0 ; V_41 < F_64 () ; ++ V_41 ) {
struct V_7 * V_8 ;
T_3 V_13 ;
V_45 = F_65 ( V_41 ) ;
if ( ! ( V_45 -> V_63 & V_165 ) )
continue;
V_80 = & V_72 . V_81 [ V_45 -> V_55 ] ;
if ( ! V_80 -> V_47 )
continue;
V_8 = V_45 -> V_35 -> V_6 ;
V_13 = F_68 ( V_45 -> V_55 ) ;
if ( V_164 )
V_13 *= 3 ;
switch ( V_8 -> type ) {
case V_169 :
case V_170 :
case V_171 :
case V_51 :
case V_53 :
F_69 ( V_45 -> V_55 , V_13 ,
& V_80 -> V_141 , & V_80 -> V_142 ,
& V_80 -> V_143 ) ;
break;
#ifdef F_70
case V_172 :
F_71 ( V_45 -> V_55 , V_13 ,
& V_80 -> V_141 , & V_80 -> V_142 ,
& V_80 -> V_143 ) ;
break;
#endif
default:
F_38 () ;
}
}
V_16 = 0 ;
F_72 ( V_173 | V_174 ) ;
if ( ! V_72 . V_162 ) {
T_3 V_158 ;
V_158 = V_57 | V_52 |
V_54 ;
if ( F_60 ( V_161 ) )
V_158 |= V_58 ;
V_16 = F_73 ( F_58 , NULL , V_158 ) ;
V_72 . V_162 = true ;
}
F_48 () ;
F_74 ( V_173 | V_174 ) ;
F_29 ( & V_72 . V_77 , V_74 ) ;
return V_16 ;
}
static int F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_30 && V_2 -> V_11 . V_28 &&
V_2 -> V_11 . V_23 != V_25 )
return - V_17 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_14 * V_11 )
{
int V_16 ;
struct V_14 V_175 ;
V_175 = V_2 -> V_11 ;
V_2 -> V_11 = * V_11 ;
V_16 = F_75 ( V_2 ) ;
if ( V_16 ) {
V_2 -> V_11 = V_175 ;
return V_16 ;
}
V_2 -> V_166 = true ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_14 * V_11 )
{
* V_11 = V_2 -> V_11 ;
}
static int F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_55 , 1 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_55 , 0 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_35 )
{
++ V_176 ;
F_82 ( & V_35 -> V_177 , & V_178 ) ;
}
int F_83 ( struct V_1 * V_2 )
{
F_56 ( L_19 , V_2 -> V_5 ) ;
return 0 ;
}
void F_84 ( struct V_179 * V_180 )
{
struct V_1 * V_2 ;
while ( ! F_85 ( & V_178 ) ) {
V_2 = F_86 ( & V_178 ,
struct V_1 , V_177 ) ;
F_87 ( & V_2 -> V_177 ) ;
F_88 ( & V_2 -> V_32 ) ;
F_89 ( & V_2 -> V_32 ) ;
F_90 ( V_2 ) ;
}
V_176 = 0 ;
}
int F_91 ( void )
{
return V_176 ;
}
struct V_1 * F_92 ( int V_181 )
{
int V_41 = 0 ;
struct V_1 * V_2 ;
F_67 (mgr, &manager_list, list) {
if ( V_41 ++ == V_181 )
return V_2 ;
}
return NULL ;
}
