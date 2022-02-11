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
static T_1 F_17 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 , V_2 -> V_11 . V_31 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
int V_32 ;
int V_16 ;
bool V_29 ;
if ( ! F_19 ( V_33 ) )
return - V_34 ;
V_16 = F_20 ( V_3 , 0 , & V_32 ) ;
if ( V_16 )
return V_16 ;
V_29 = ! ! V_32 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_11 . V_31 == V_29 )
return V_13 ;
V_11 . V_31 = V_29 ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_14 V_11 ;
V_2 -> V_18 ( V_2 , & V_11 ) ;
return snprintf ( V_3 , V_4 ,
L_5 ,
V_11 . V_35 . V_36 ,
V_11 . V_35 . V_37 ,
V_11 . V_35 . V_38 ,
V_11 . V_35 . V_39 ,
V_11 . V_35 . V_40 ,
V_11 . V_35 . V_41 ,
V_11 . V_35 . V_42 ,
V_11 . V_35 . V_43 ,
V_11 . V_35 . V_44 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
struct V_45 V_46 ;
int V_16 , V_47 ;
T_4 * V_48 ;
if ( ! F_19 ( V_33 ) )
return - V_34 ;
if ( sscanf ( V_3 , L_6 ,
& V_46 . V_36 , & V_46 . V_37 , & V_46 . V_38 ,
& V_46 . V_39 , & V_46 . V_40 , & V_46 . V_41 ,
& V_46 . V_42 , & V_46 . V_43 , & V_46 . V_44 ) != 9 )
return - V_17 ;
V_48 = ( T_4 [] ) { V_46 . V_36 , V_46 . V_37 , V_46 . V_38 ,
V_46 . V_39 , V_46 . V_40 , V_46 . V_41 ,
V_46 . V_42 , V_46 . V_43 , V_46 . V_44 } ;
for ( V_47 = 0 ; V_47 < 9 ; ++ V_47 ) {
if ( V_48 [ V_47 ] < - 512 || V_48 [ V_47 ] > 511 )
return - V_17 ;
}
V_2 -> V_18 ( V_2 , & V_11 ) ;
V_11 . V_35 = V_46 ;
V_16 = V_2 -> V_19 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_23 ( struct V_49 * V_50 , struct V_51 * V_52 ,
char * V_3 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_24 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_24 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_56 )
return - V_57 ;
return V_55 -> V_56 ( V_53 , V_3 ) ;
}
static T_1 F_25 ( struct V_49 * V_50 , struct V_51 * V_52 ,
const char * V_3 , T_2 V_13 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_24 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_24 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_58 )
return - V_57 ;
return V_55 -> V_58 ( V_53 , V_3 , V_13 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_47 ;
int V_16 ;
if ( V_8 -> V_53 ) {
F_27 ( L_7 ,
V_8 -> V_5 , V_8 -> V_53 -> V_5 ) ;
return - V_17 ;
}
if ( ( V_2 -> V_59 & V_8 -> type ) == 0 ) {
F_27 ( L_8 ,
V_8 -> V_5 , V_2 -> V_5 ) ;
return - V_17 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_60 ; V_47 ++ ) {
struct V_61 * V_62 = V_2 -> V_63 [ V_47 ] ;
if ( V_62 -> V_53 != V_2 || ! V_62 -> V_11 . V_64 )
continue;
V_16 = F_28 ( V_62 , V_8 ) ;
if ( V_16 )
return V_16 ;
}
V_8 -> V_53 = V_2 ;
V_2 -> V_6 = V_8 ;
V_2 -> V_65 = true ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 ) {
F_27 ( L_9 ) ;
return - V_17 ;
}
V_2 -> V_6 -> V_53 = NULL ;
V_2 -> V_6 = NULL ;
V_2 -> V_65 = true ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned long V_66 = F_31 ( 500 ) ;
T_3 V_67 ;
if ( V_2 -> V_6 -> type == V_68 ) {
V_67 = V_69 ;
} else if ( V_2 -> V_6 -> type == V_70 ) {
V_67 = V_71 ;
} else {
if ( V_2 -> V_72 == V_73 )
V_67 = V_74 ;
else
V_67 = V_75 ;
}
return F_32 ( V_67 , V_66 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned long V_66 = F_31 ( 500 ) ;
struct V_76 * V_77 ;
T_3 V_67 ;
int V_16 ;
int V_47 ;
struct V_7 * V_8 = V_2 -> V_6 ;
if ( ! V_8 || V_8 -> V_78 != V_79 )
return 0 ;
if ( V_8 -> V_80 & V_81 )
return 0 ;
if ( V_8 -> type == V_68
|| V_8 -> type == V_70 ) {
V_67 = V_69 | V_71 ;
} else {
V_67 = ( V_8 -> V_53 -> V_72 == V_73 ) ?
V_74 : V_75 ;
}
V_77 = & V_82 . V_83 [ V_2 -> V_72 ] ;
V_47 = 0 ;
while ( 1 ) {
unsigned long V_84 ;
bool V_85 , V_86 ;
F_34 ( & V_82 . V_87 , V_84 ) ;
V_86 = V_77 -> V_86 ;
V_85 = V_77 -> V_85 ;
F_35 ( & V_82 . V_87 , V_84 ) ;
if ( ! V_86 && ! V_85 ) {
V_16 = 0 ;
break;
}
if ( V_47 ++ == 3 ) {
F_27 ( L_10 ,
V_2 -> V_72 ) ;
V_16 = 0 ;
break;
}
V_16 = F_32 ( V_67 , V_66 ) ;
if ( V_16 == - V_88 )
break;
if ( V_16 ) {
F_27 ( L_11 , V_2 -> V_72 ) ;
break;
}
}
return V_16 ;
}
int F_36 ( struct V_61 * V_62 )
{
unsigned long V_66 = F_31 ( 500 ) ;
struct V_89 * V_90 ;
struct V_7 * V_8 ;
T_3 V_67 ;
int V_16 ;
int V_47 ;
if ( ! V_62 -> V_53 )
return 0 ;
V_8 = V_62 -> V_53 -> V_6 ;
if ( ! V_8 || V_8 -> V_78 != V_79 )
return 0 ;
if ( V_8 -> V_80 & V_81 )
return 0 ;
if ( V_8 -> type == V_68
|| V_8 -> type == V_70 ) {
V_67 = V_69 | V_71 ;
} else {
V_67 = ( V_8 -> V_53 -> V_72 == V_73 ) ?
V_74 : V_75 ;
}
V_90 = & V_82 . V_91 [ V_62 -> V_72 ] ;
V_47 = 0 ;
while ( 1 ) {
unsigned long V_84 ;
bool V_85 , V_86 ;
F_34 ( & V_82 . V_87 , V_84 ) ;
V_86 = V_90 -> V_86 ;
V_85 = V_90 -> V_85 ;
F_35 ( & V_82 . V_87 , V_84 ) ;
if ( ! V_86 && ! V_85 ) {
V_16 = 0 ;
break;
}
if ( V_47 ++ == 3 ) {
F_27 ( L_12 ,
V_62 -> V_72 ) ;
V_16 = 0 ;
break;
}
V_16 = F_32 ( V_67 , V_66 ) ;
if ( V_16 == - V_88 )
break;
if ( V_16 ) {
F_27 ( L_13 , V_62 -> V_72 ) ;
break;
}
}
return V_16 ;
}
static int F_37 ( struct V_61 * V_62 )
{
return V_62 -> V_11 . V_64 && V_62 -> V_53 && V_62 -> V_53 -> V_6 ;
}
static bool F_38 ( int V_92 , int y1 , int V_93 , int V_94 ,
int V_95 , int V_96 , int V_97 , int V_98 )
{
if ( V_92 < V_95 || y1 < V_96 )
return false ;
if ( V_92 + V_93 > V_95 + V_97 )
return false ;
if ( y1 + V_94 > V_96 + V_98 )
return false ;
return true ;
}
static bool F_39 ( int V_92 , int y1 , int V_93 , int V_94 ,
int V_95 , int V_96 , int V_97 , int V_98 )
{
if ( V_92 >= V_95 + V_97 )
return false ;
if ( V_95 >= V_92 + V_93 )
return false ;
if ( y1 >= V_96 + V_98 )
return false ;
if ( V_96 >= y1 + V_94 )
return false ;
return true ;
}
static bool F_40 ( struct V_89 * V_90 )
{
struct V_99 * V_100 = & V_90 -> V_11 ;
if ( V_100 -> V_101 != 0 && V_100 -> V_102 != V_100 -> V_101 )
return true ;
if ( V_100 -> V_103 != 0 && V_100 -> V_104 != V_100 -> V_103 )
return true ;
return false ;
}
static int F_41 ( enum V_105 V_106 )
{
struct V_89 * V_107 ;
struct V_76 * V_77 ;
struct V_99 * V_100 ;
struct V_14 * V_108 ;
T_5 V_109 , V_110 ;
T_5 V_111 , V_112 , V_113 , V_114 ;
T_3 V_115 ;
int V_16 ;
T_5 V_116 , V_117 , V_118 , V_119 ;
F_42 ( L_4 , V_106 ) ;
V_107 = & V_82 . V_91 [ V_106 ] ;
V_100 = & V_107 -> V_11 ;
if ( ! V_107 -> V_64 ) {
F_43 ( V_106 , 0 ) ;
return 0 ;
}
V_77 = & V_82 . V_83 [ V_107 -> V_120 ] ;
V_108 = & V_77 -> V_11 ;
V_111 = V_100 -> V_121 ;
V_112 = V_100 -> V_122 ;
V_113 = V_100 -> V_102 ;
V_114 = V_100 -> V_104 ;
V_109 = V_100 -> V_101 == 0 ? V_100 -> V_102 : V_100 -> V_101 ;
V_110 = V_100 -> V_103 == 0 ? V_100 -> V_104 : V_100 -> V_103 ;
V_115 = V_100 -> V_115 ;
V_116 = V_113 ;
V_117 = V_114 ;
V_118 = V_109 ;
V_119 = V_110 ;
if ( V_77 -> V_123 && V_77 -> V_124 ) {
unsigned V_125 ;
unsigned V_126 = V_113 , V_127 = V_109 ;
unsigned V_128 = V_114 , V_129 = V_110 ;
if ( ! F_39 ( V_77 -> V_111 , V_77 -> V_112 , V_77 -> V_113 , V_77 -> V_114 ,
V_111 , V_112 , V_109 , V_110 ) ) {
F_43 ( V_106 , 0 ) ;
return 0 ;
}
switch ( V_100 -> V_130 ) {
case V_131 :
V_125 = 8 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_125 = 16 ;
break;
case V_140 :
V_125 = 24 ;
break;
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_125 = 32 ;
break;
default:
F_44 () ;
}
if ( V_77 -> V_111 > V_100 -> V_121 ) {
V_111 = 0 ;
V_109 -= ( V_77 -> V_111 - V_100 -> V_121 ) ;
V_115 += ( V_77 -> V_111 - V_100 -> V_121 ) *
V_126 / V_127 * V_125 / 8 ;
} else {
V_111 = V_100 -> V_121 - V_77 -> V_111 ;
}
if ( V_77 -> V_112 > V_100 -> V_122 ) {
V_112 = 0 ;
V_110 -= ( V_77 -> V_112 - V_100 -> V_122 ) ;
V_115 += ( V_77 -> V_112 - V_100 -> V_122 ) *
V_128 / V_129 *
V_100 -> V_145 * V_125 / 8 ;
} else {
V_112 = V_100 -> V_122 - V_77 -> V_112 ;
}
if ( V_77 -> V_113 < ( V_111 + V_109 ) )
V_109 -= ( V_111 + V_109 ) - ( V_77 -> V_113 ) ;
if ( V_77 -> V_114 < ( V_112 + V_110 ) )
V_110 -= ( V_112 + V_110 ) - ( V_77 -> V_114 ) ;
V_113 = V_113 * V_109 / V_118 ;
V_114 = V_114 * V_110 / V_119 ;
if ( ( V_113 & 1 ) &&
( V_100 -> V_130 == V_134 ||
V_100 -> V_130 == V_135 ) ) {
if ( V_116 > V_113 )
V_113 += 1 ;
else
V_113 -= 1 ;
}
}
V_16 = F_45 ( V_106 ,
V_115 ,
V_100 -> V_145 ,
V_111 , V_112 ,
V_113 , V_114 ,
V_109 , V_110 ,
V_100 -> V_130 ,
V_107 -> V_146 ,
V_100 -> V_147 ,
V_100 -> V_148 ,
V_100 -> V_149 ,
V_100 -> V_150 ,
V_100 -> V_151 ,
V_107 -> V_120 ,
V_100 -> V_152 ) ;
if ( V_16 ) {
F_27 ( L_14 , V_106 ) ;
F_43 ( V_106 , 0 ) ;
return V_16 ;
}
F_46 ( V_106 , V_107 -> V_153 ) ;
F_47 ( V_106 , V_107 -> V_154 , V_107 -> V_155 ) ;
F_43 ( V_106 , 1 ) ;
return 0 ;
}
static void F_48 ( enum V_156 V_120 )
{
struct V_14 * V_108 ;
F_42 ( L_4 , V_120 ) ;
V_108 = & V_82 . V_83 [ V_120 ] . V_11 ;
F_49 ( V_120 , V_108 -> V_12 ) ;
F_50 ( V_120 , V_108 -> V_23 , V_108 -> V_26 ) ;
F_51 ( V_120 , V_108 -> V_28 ) ;
F_52 ( V_120 , V_108 -> V_30 ) ;
if ( F_19 ( V_33 ) ) {
F_53 ( V_120 , V_108 -> V_31 ) ;
F_54 ( V_120 , & V_108 -> V_35 ) ;
}
}
static int F_55 ( void )
{
struct V_89 * V_90 ;
struct V_76 * V_77 ;
const int V_157 = F_56 () ;
const int V_158 = F_57 () ;
int V_47 ;
int V_16 ;
bool V_159 [ V_160 ] ;
bool V_161 [ V_160 ] ;
bool V_162 ;
V_16 = 0 ;
V_162 = false ;
for ( V_47 = 0 ; V_47 < V_158 ; V_47 ++ ) {
V_159 [ V_47 ] = F_58 ( V_47 ) ;
V_161 [ V_47 ] = false ;
}
for ( V_47 = 0 ; V_47 < V_157 ; ++ V_47 ) {
V_90 = & V_82 . V_91 [ V_47 ] ;
V_77 = & V_82 . V_83 [ V_90 -> V_120 ] ;
if ( ! V_90 -> V_86 )
continue;
if ( V_77 -> V_123 && ! V_77 -> V_124 )
continue;
if ( V_159 [ V_90 -> V_120 ] ) {
V_162 = true ;
continue;
}
V_16 = F_41 ( V_47 ) ;
if ( V_16 )
F_27 ( L_15 , V_47 ) ;
V_90 -> V_86 = false ;
V_90 -> V_85 = true ;
V_161 [ V_90 -> V_120 ] = true ;
}
for ( V_47 = 0 ; V_47 < V_158 ; ++ V_47 ) {
V_77 = & V_82 . V_83 [ V_47 ] ;
if ( ! V_77 -> V_86 )
continue;
if ( V_77 -> V_123 && ! V_77 -> V_124 )
continue;
if ( V_159 [ V_47 ] ) {
V_162 = true ;
continue;
}
F_48 ( V_47 ) ;
V_77 -> V_86 = false ;
V_77 -> V_85 = true ;
V_161 [ V_47 ] = true ;
}
for ( V_47 = 0 ; V_47 < V_158 ; ++ V_47 ) {
V_77 = & V_82 . V_83 [ V_47 ] ;
if ( ! V_161 [ V_47 ] )
continue;
if ( ! V_77 -> V_123 )
F_59 ( V_47 ) ;
}
if ( V_162 )
V_16 = 1 ;
else
V_16 = 0 ;
return V_16 ;
}
static void F_60 ( T_5 * V_111 , T_5 * V_113 )
{
T_5 V_92 , V_95 ;
V_92 = * V_111 ;
V_95 = * V_111 + * V_113 ;
V_92 &= ~ 1 ;
V_95 = F_61 ( V_95 , 2 ) ;
* V_111 = V_92 ;
* V_113 = V_95 - V_92 ;
}
void F_62 ( struct V_7 * V_8 ,
T_5 * V_163 , T_5 * V_164 , T_5 * V_165 , T_5 * V_166 , bool V_167 )
{
struct V_89 * V_90 ;
struct V_76 * V_77 ;
struct V_99 * V_100 ;
const int V_157 = F_56 () ;
struct V_1 * V_2 ;
int V_47 ;
T_5 V_111 , V_112 , V_113 , V_114 ;
unsigned long V_84 ;
bool V_168 ;
V_111 = * V_163 ;
V_112 = * V_164 ;
V_113 = * V_165 ;
V_114 = * V_166 ;
F_63 ( L_16 ,
* V_163 , * V_164 , * V_165 , * V_166 ) ;
V_2 = V_8 -> V_53 ;
if ( ! V_2 ) {
F_63 ( L_17 ) ;
return;
}
F_60 ( & V_111 , & V_113 ) ;
F_34 ( & V_82 . V_87 , V_84 ) ;
do {
V_168 = false ;
for ( V_47 = 0 ; V_47 < V_157 ; ++ V_47 ) {
unsigned V_92 , y1 , V_95 , V_96 ;
unsigned V_109 , V_110 ;
V_90 = & V_82 . V_91 [ V_47 ] ;
V_100 = & V_90 -> V_11 ;
if ( V_90 -> V_120 != V_2 -> V_72 )
continue;
V_90 -> V_86 = true ;
if ( ! V_167 )
continue;
if ( ! V_90 -> V_64 )
continue;
if ( ! F_40 ( V_90 ) )
continue;
V_109 = V_100 -> V_101 == 0 ?
V_100 -> V_102 : V_100 -> V_101 ;
V_110 = V_100 -> V_103 == 0 ?
V_100 -> V_104 : V_100 -> V_103 ;
if ( ! F_39 ( V_111 , V_112 , V_113 , V_114 ,
V_100 -> V_121 , V_100 -> V_122 ,
V_109 , V_110 ) )
continue;
if ( F_38 ( V_100 -> V_121 , V_100 -> V_122 , V_109 , V_110 ,
V_111 , V_112 , V_113 , V_114 ) )
continue;
if ( V_111 > V_100 -> V_121 )
V_92 = V_100 -> V_121 ;
else
V_92 = V_111 ;
if ( V_112 > V_100 -> V_122 )
y1 = V_100 -> V_122 ;
else
y1 = V_112 ;
if ( ( V_111 + V_113 ) < ( V_100 -> V_121 + V_109 ) )
V_95 = V_100 -> V_121 + V_109 ;
else
V_95 = V_111 + V_113 ;
if ( ( V_112 + V_114 ) < ( V_100 -> V_122 + V_110 ) )
V_96 = V_100 -> V_122 + V_110 ;
else
V_96 = V_112 + V_114 ;
V_111 = V_92 ;
V_112 = y1 ;
V_113 = V_95 - V_92 ;
V_114 = V_96 - y1 ;
F_60 ( & V_111 , & V_113 ) ;
F_63 ( L_18
L_19 ,
V_47 , V_111 , V_112 , V_113 , V_114 ) ;
V_168 = true ;
}
} while ( V_168 );
V_77 = & V_82 . V_83 [ V_2 -> V_72 ] ;
V_77 -> V_124 = true ;
V_77 -> V_167 = V_167 ;
V_77 -> V_111 = V_111 ;
V_77 -> V_112 = V_112 ;
V_77 -> V_113 = V_113 ;
V_77 -> V_114 = V_114 ;
F_55 () ;
V_77 -> V_124 = false ;
F_35 ( & V_82 . V_87 , V_84 ) ;
* V_163 = V_111 ;
* V_164 = V_112 ;
* V_165 = V_113 ;
* V_166 = V_114 ;
}
void F_64 ( struct V_7 * V_8 )
{
struct V_76 * V_77 ;
struct V_89 * V_90 ;
const int V_157 = F_56 () ;
const int V_158 = F_57 () ;
struct V_1 * V_2 ;
int V_47 ;
V_2 = V_8 -> V_53 ;
for ( V_47 = 0 ; V_47 < V_157 ; ++ V_47 ) {
V_90 = & V_82 . V_91 [ V_47 ] ;
if ( V_90 -> V_120 != V_2 -> V_72 )
continue;
V_90 -> V_85 = false ;
}
for ( V_47 = 0 ; V_47 < V_158 ; ++ V_47 ) {
V_77 = & V_82 . V_83 [ V_47 ] ;
if ( V_2 -> V_72 != V_47 )
continue;
V_77 -> V_85 = false ;
}
V_8 -> V_53 -> V_29 ( V_8 -> V_53 ) ;
}
static void F_65 ( void * V_9 , T_3 V_169 )
{
struct V_76 * V_77 ;
struct V_89 * V_90 ;
const int V_157 = F_56 () ;
const int V_158 = F_57 () ;
int V_47 , V_16 ;
bool V_159 [ V_160 ] ;
T_3 V_170 ;
for ( V_47 = 0 ; V_47 < V_158 ; V_47 ++ )
V_159 [ V_47 ] = F_58 ( V_47 ) ;
F_66 ( & V_82 . V_87 ) ;
for ( V_47 = 0 ; V_47 < V_157 ; ++ V_47 ) {
V_90 = & V_82 . V_91 [ V_47 ] ;
if ( ! V_159 [ V_90 -> V_120 ] )
V_90 -> V_85 = false ;
}
for ( V_47 = 0 ; V_47 < V_158 ; ++ V_47 ) {
V_77 = & V_82 . V_83 [ V_47 ] ;
if ( ! V_159 [ V_47 ] )
V_77 -> V_85 = false ;
}
V_16 = F_55 () ;
if ( V_16 == 1 )
goto V_171;
for ( V_47 = 0 ; V_47 < V_158 ; V_47 ++ )
V_159 [ V_47 ] = F_58 ( V_47 ) ;
for ( V_47 = 0 ; V_47 < V_158 ; ++ V_47 ) {
if ( V_159 [ V_47 ] )
goto V_171;
}
V_170 = V_74 | V_69 |
V_71 ;
if ( F_19 ( V_172 ) )
V_170 |= V_75 ;
F_67 ( F_65 , NULL , V_170 ) ;
V_82 . V_173 = false ;
V_171:
F_68 ( & V_82 . V_87 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
struct V_76 * V_77 ;
int V_47 ;
struct V_61 * V_62 ;
int V_174 = 0 ;
bool V_175 ;
unsigned long V_84 ;
int V_16 ;
F_63 ( L_20 , V_2 -> V_5 ) ;
V_16 = F_70 () ;
if ( V_16 )
return V_16 ;
F_34 ( & V_82 . V_87 , V_84 ) ;
for ( V_47 = 0 ; V_47 < F_71 () ; ++ V_47 ) {
struct V_7 * V_8 ;
V_62 = F_72 ( V_47 ) ;
if ( ! ( V_62 -> V_80 & V_176 ) )
continue;
V_90 = & V_82 . V_91 [ V_62 -> V_72 ] ;
if ( ! F_37 ( V_62 ) ) {
if ( V_90 -> V_64 ) {
V_90 -> V_64 = false ;
V_90 -> V_86 = true ;
}
continue;
}
if ( ! V_62 -> V_177 ) {
if ( V_90 -> V_64 )
++ V_174 ;
continue;
}
V_8 = V_62 -> V_53 -> V_6 ;
if ( F_28 ( V_62 , V_8 ) ) {
if ( V_90 -> V_64 ) {
V_90 -> V_64 = false ;
V_90 -> V_86 = true ;
}
continue;
}
V_62 -> V_177 = false ;
V_90 -> V_86 = true ;
V_90 -> V_11 = V_62 -> V_11 ;
V_90 -> V_153 =
F_73 ( V_8 , V_62 -> V_11 . V_130 ) ;
V_90 -> V_146 = V_8 -> type == V_68 ;
V_90 -> V_120 = V_62 -> V_53 -> V_72 ;
V_90 -> V_64 = true ;
++ V_174 ;
}
F_74 (mgr, &manager_list, list) {
struct V_7 * V_8 ;
if ( ! ( V_2 -> V_80 & V_178 ) )
continue;
V_77 = & V_82 . V_83 [ V_2 -> V_72 ] ;
if ( V_2 -> V_65 ) {
V_2 -> V_65 = false ;
V_2 -> V_177 = true ;
}
if ( ! V_2 -> V_177 )
continue;
if ( ! V_2 -> V_6 )
continue;
V_8 = V_2 -> V_6 ;
V_2 -> V_177 = false ;
V_77 -> V_86 = true ;
V_77 -> V_11 = V_2 -> V_11 ;
V_77 -> V_123 =
V_8 -> V_80 & V_81 ;
}
V_175 = false ;
for ( V_47 = 0 ; V_47 < F_71 () ; ++ V_47 ) {
struct V_7 * V_8 ;
T_3 V_13 , V_179 ;
V_62 = F_72 ( V_47 ) ;
if ( ! ( V_62 -> V_80 & V_176 ) )
continue;
V_90 = & V_82 . V_91 [ V_62 -> V_72 ] ;
if ( ! V_90 -> V_64 )
continue;
V_8 = V_62 -> V_53 -> V_6 ;
V_13 = F_75 ( V_62 -> V_72 ) ;
if ( V_175 )
V_13 *= 3 ;
V_179 = F_76 ( V_62 -> V_72 ) ;
switch ( V_8 -> type ) {
case V_180 :
case V_181 :
case V_182 :
case V_68 :
case V_70 :
F_77 ( V_62 -> V_72 , V_13 ,
V_179 , & V_90 -> V_154 ,
& V_90 -> V_155 ) ;
break;
#ifdef F_78
case V_183 :
F_79 ( V_62 -> V_72 , V_13 ,
V_179 , & V_90 -> V_154 ,
& V_90 -> V_155 ) ;
break;
#endif
default:
F_44 () ;
}
}
V_16 = 0 ;
if ( ! V_82 . V_173 ) {
T_3 V_169 ;
V_169 = V_74 | V_69 |
V_71 ;
if ( F_19 ( V_172 ) )
V_169 |= V_75 ;
V_16 = F_80 ( F_65 , NULL , V_169 ) ;
V_82 . V_173 = true ;
}
F_55 () ;
F_35 ( & V_82 . V_87 , V_84 ) ;
F_81 () ;
return V_16 ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 . V_30 && V_2 -> V_11 . V_28 &&
V_2 -> V_11 . V_23 != V_25 )
return - V_17 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_14 * V_11 )
{
int V_16 ;
struct V_14 V_184 ;
V_184 = V_2 -> V_11 ;
V_2 -> V_11 = * V_11 ;
V_16 = F_82 ( V_2 ) ;
if ( V_16 ) {
V_2 -> V_11 = V_184 ;
return V_16 ;
}
V_2 -> V_177 = true ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_14 * V_11 )
{
* V_11 = V_2 -> V_11 ;
}
static int F_85 ( struct V_1 * V_2 )
{
F_86 ( V_2 -> V_72 , 1 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
F_86 ( V_2 -> V_72 , 0 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_53 )
{
++ V_185 ;
F_89 ( & V_53 -> V_186 , & V_187 ) ;
}
int F_90 ( struct V_1 * V_2 )
{
F_63 ( L_21 , V_2 -> V_5 ) ;
return 0 ;
}
void F_91 ( struct V_188 * V_189 )
{
struct V_1 * V_2 ;
while ( ! F_92 ( & V_187 ) ) {
V_2 = F_93 ( & V_187 ,
struct V_1 , V_186 ) ;
F_94 ( & V_2 -> V_186 ) ;
F_95 ( & V_2 -> V_50 ) ;
F_96 ( & V_2 -> V_50 ) ;
F_97 ( V_2 ) ;
}
V_185 = 0 ;
}
int F_98 ( void )
{
return V_185 ;
}
struct V_1 * F_99 ( int V_190 )
{
int V_47 = 0 ;
struct V_1 * V_2 ;
F_74 (mgr, &manager_list, list) {
if ( V_47 ++ == V_190 )
return V_2 ;
}
return NULL ;
}
