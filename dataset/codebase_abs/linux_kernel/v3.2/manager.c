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
V_16 = F_7 ( V_3 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
V_11 . V_12 = V_15 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
char * V_3 )
{
enum V_20 V_21 ;
V_21 = V_2 -> V_11 . V_22 ;
F_9 ( V_21 >= F_10 ( V_23 ) ) ;
return snprintf ( V_3 , V_4 , L_1 , V_23 [ V_21 ] ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
enum V_20 V_21 ;
struct V_14 V_11 ;
int V_16 ;
for ( V_21 = V_24 ;
V_21 < F_10 ( V_23 ) ; V_21 ++ ) {
if ( F_4 ( V_3 , V_23 [ V_21 ] ) )
break;
}
if ( V_21 == F_10 ( V_23 ) )
return - V_25 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
V_11 . V_22 = V_21 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 , V_2 -> V_11 . V_26 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
T_3 V_27 ;
int V_16 ;
V_16 = F_7 ( V_3 , 0 , & V_27 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
V_11 . V_26 = V_27 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_4 , V_2 -> V_11 . V_28 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
bool V_29 ;
int V_16 ;
V_16 = F_16 ( V_3 , & V_29 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
V_11 . V_28 = V_29 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_17 (
struct V_1 * V_2 , char * V_3 )
{
F_18 ( ! F_19 ( V_30 ) ) ;
return snprintf ( V_3 , V_4 , L_4 ,
V_2 -> V_11 . V_31 ) ;
}
static T_1 F_20 (
struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
bool V_29 ;
int V_16 ;
F_18 ( ! F_19 ( V_30 ) ) ;
V_16 = F_16 ( V_3 , & V_29 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
V_11 . V_31 = V_29 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
char * V_3 )
{
return snprintf ( V_3 , V_4 , L_4 , V_2 -> V_11 . V_32 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_13 )
{
struct V_14 V_11 ;
int V_16 ;
bool V_29 ;
if ( ! F_19 ( V_33 ) )
return - V_34 ;
V_16 = F_16 ( V_3 , & V_29 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
if ( V_11 . V_32 == V_29 )
return V_13 ;
V_11 . V_32 = V_29 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_14 V_11 ;
V_2 -> V_17 ( V_2 , & V_11 ) ;
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
static T_1 F_24 ( struct V_1 * V_2 ,
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
return - V_25 ;
V_48 = ( T_4 [] ) { V_46 . V_36 , V_46 . V_37 , V_46 . V_38 ,
V_46 . V_39 , V_46 . V_40 , V_46 . V_41 ,
V_46 . V_42 , V_46 . V_43 , V_46 . V_44 } ;
for ( V_47 = 0 ; V_47 < 9 ; ++ V_47 ) {
if ( V_48 [ V_47 ] < - 512 || V_48 [ V_47 ] > 511 )
return - V_25 ;
}
V_2 -> V_17 ( V_2 , & V_11 ) ;
V_11 . V_35 = V_46 ;
V_16 = V_2 -> V_18 ( V_2 , & V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_2 -> V_19 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return V_13 ;
}
static T_1 F_25 ( struct V_49 * V_50 , struct V_51 * V_52 ,
char * V_3 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_26 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_26 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_56 )
return - V_57 ;
return V_55 -> V_56 ( V_53 , V_3 ) ;
}
static T_1 F_27 ( struct V_49 * V_50 , struct V_51 * V_52 ,
const char * V_3 , T_2 V_13 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_26 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_26 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_58 )
return - V_57 ;
return V_55 -> V_58 ( V_53 , V_3 , V_13 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_47 ;
int V_16 ;
if ( V_8 -> V_53 ) {
F_29 ( L_7 ,
V_8 -> V_5 , V_8 -> V_53 -> V_5 ) ;
return - V_25 ;
}
if ( ( V_2 -> V_59 & V_8 -> type ) == 0 ) {
F_29 ( L_8 ,
V_8 -> V_5 , V_2 -> V_5 ) ;
return - V_25 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_60 ; V_47 ++ ) {
struct V_61 * V_62 = V_2 -> V_63 [ V_47 ] ;
if ( V_62 -> V_53 != V_2 || ! V_62 -> V_11 . V_64 )
continue;
V_16 = F_30 ( V_62 , V_8 ) ;
if ( V_16 )
return V_16 ;
}
V_8 -> V_53 = V_2 ;
V_2 -> V_6 = V_8 ;
V_2 -> V_65 = true ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 ) {
F_29 ( L_9 ) ;
return - V_25 ;
}
if ( V_2 -> V_6 -> V_66 != V_67 )
return - V_25 ;
V_2 -> V_6 -> V_53 = NULL ;
V_2 -> V_6 = NULL ;
V_2 -> V_65 = true ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
unsigned long V_68 = F_33 ( 500 ) ;
T_3 V_69 ;
if ( V_2 -> V_6 -> type == V_70 ) {
V_69 = V_71 ;
} else if ( V_2 -> V_6 -> type == V_72 ) {
V_69 = V_73 ;
} else {
if ( V_2 -> V_74 == V_75 )
V_69 = V_76 ;
else
V_69 = V_77 ;
}
return F_34 ( V_69 , V_68 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned long V_68 = F_33 ( 500 ) ;
struct V_78 * V_79 ;
T_3 V_69 ;
int V_16 ;
int V_47 ;
struct V_7 * V_8 = V_2 -> V_6 ;
if ( ! V_8 || V_8 -> V_66 != V_80 )
return 0 ;
if ( V_8 -> V_81 & V_82 )
return 0 ;
if ( V_8 -> type == V_70
|| V_8 -> type == V_72 ) {
V_69 = V_71 | V_73 ;
} else {
V_69 = ( V_8 -> V_53 -> V_74 == V_75 ) ?
V_76 : V_77 ;
}
V_79 = & V_83 . V_84 [ V_2 -> V_74 ] ;
V_47 = 0 ;
while ( 1 ) {
unsigned long V_85 ;
bool V_86 , V_87 ;
F_36 ( & V_83 . V_88 , V_85 ) ;
V_87 = V_79 -> V_87 ;
V_86 = V_79 -> V_86 ;
F_37 ( & V_83 . V_88 , V_85 ) ;
if ( ! V_87 && ! V_86 ) {
V_16 = 0 ;
break;
}
if ( V_47 ++ == 3 ) {
F_29 ( L_10 ,
V_2 -> V_74 ) ;
V_16 = 0 ;
break;
}
V_16 = F_34 ( V_69 , V_68 ) ;
if ( V_16 == - V_89 )
break;
if ( V_16 ) {
F_29 ( L_11 , V_2 -> V_74 ) ;
break;
}
}
return V_16 ;
}
int F_38 ( struct V_61 * V_62 )
{
unsigned long V_68 = F_33 ( 500 ) ;
struct V_90 * V_91 ;
struct V_7 * V_8 ;
T_3 V_69 ;
int V_16 ;
int V_47 ;
if ( ! V_62 -> V_53 )
return 0 ;
V_8 = V_62 -> V_53 -> V_6 ;
if ( ! V_8 || V_8 -> V_66 != V_80 )
return 0 ;
if ( V_8 -> V_81 & V_82 )
return 0 ;
if ( V_8 -> type == V_70
|| V_8 -> type == V_72 ) {
V_69 = V_71 | V_73 ;
} else {
V_69 = ( V_8 -> V_53 -> V_74 == V_75 ) ?
V_76 : V_77 ;
}
V_91 = & V_83 . V_92 [ V_62 -> V_74 ] ;
V_47 = 0 ;
while ( 1 ) {
unsigned long V_85 ;
bool V_86 , V_87 ;
F_36 ( & V_83 . V_88 , V_85 ) ;
V_87 = V_91 -> V_87 ;
V_86 = V_91 -> V_86 ;
F_37 ( & V_83 . V_88 , V_85 ) ;
if ( ! V_87 && ! V_86 ) {
V_16 = 0 ;
break;
}
if ( V_47 ++ == 3 ) {
F_29 ( L_12 ,
V_62 -> V_74 ) ;
V_16 = 0 ;
break;
}
V_16 = F_34 ( V_69 , V_68 ) ;
if ( V_16 == - V_89 )
break;
if ( V_16 ) {
F_29 ( L_13 , V_62 -> V_74 ) ;
break;
}
}
return V_16 ;
}
static int F_39 ( struct V_61 * V_62 )
{
return V_62 -> V_11 . V_64 && V_62 -> V_53 && V_62 -> V_53 -> V_6 ;
}
static bool F_40 ( int V_93 , int y1 , int V_94 , int V_95 ,
int V_96 , int V_97 , int V_98 , int V_99 )
{
if ( V_93 < V_96 || y1 < V_97 )
return false ;
if ( V_93 + V_94 > V_96 + V_98 )
return false ;
if ( y1 + V_95 > V_97 + V_99 )
return false ;
return true ;
}
static bool F_41 ( int V_93 , int y1 , int V_94 , int V_95 ,
int V_96 , int V_97 , int V_98 , int V_99 )
{
if ( V_93 >= V_96 + V_98 )
return false ;
if ( V_96 >= V_93 + V_94 )
return false ;
if ( y1 >= V_97 + V_99 )
return false ;
if ( V_97 >= y1 + V_95 )
return false ;
return true ;
}
static bool F_42 ( struct V_90 * V_91 )
{
struct V_100 * V_101 = & V_91 -> V_11 ;
if ( V_101 -> V_102 != 0 && V_101 -> V_103 != V_101 -> V_102 )
return true ;
if ( V_101 -> V_104 != 0 && V_101 -> V_105 != V_101 -> V_104 )
return true ;
return false ;
}
static int F_43 ( enum V_106 V_107 )
{
struct V_90 * V_108 ;
struct V_78 * V_79 ;
struct V_100 * V_101 , V_109 ;
struct V_14 * V_110 ;
T_5 V_111 , V_112 ;
T_5 V_113 , V_114 , V_115 , V_116 ;
T_3 V_117 ;
int V_16 ;
T_5 V_118 , V_119 , V_120 , V_121 ;
F_44 ( L_14 , V_107 ) ;
V_108 = & V_83 . V_92 [ V_107 ] ;
V_101 = & V_108 -> V_11 ;
if ( ! V_108 -> V_64 ) {
F_45 ( V_107 , 0 ) ;
return 0 ;
}
V_79 = & V_83 . V_84 [ V_108 -> V_122 ] ;
V_110 = & V_79 -> V_11 ;
V_113 = V_101 -> V_123 ;
V_114 = V_101 -> V_124 ;
V_115 = V_101 -> V_103 ;
V_116 = V_101 -> V_105 ;
V_111 = V_101 -> V_102 == 0 ? V_101 -> V_103 : V_101 -> V_102 ;
V_112 = V_101 -> V_104 == 0 ? V_101 -> V_105 : V_101 -> V_104 ;
V_117 = V_101 -> V_117 ;
V_118 = V_115 ;
V_119 = V_116 ;
V_120 = V_111 ;
V_121 = V_112 ;
if ( V_79 -> V_125 && V_79 -> V_126 ) {
unsigned V_127 ;
unsigned V_128 = V_115 , V_129 = V_111 ;
unsigned V_130 = V_116 , V_131 = V_112 ;
if ( ! F_41 ( V_79 -> V_113 , V_79 -> V_114 , V_79 -> V_115 , V_79 -> V_116 ,
V_113 , V_114 , V_111 , V_112 ) ) {
F_45 ( V_107 , 0 ) ;
return 0 ;
}
switch ( V_101 -> V_132 ) {
case V_133 :
V_127 = 8 ;
break;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
V_127 = 16 ;
break;
case V_142 :
V_127 = 24 ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_127 = 32 ;
break;
default:
F_46 () ;
}
if ( V_79 -> V_113 > V_101 -> V_123 ) {
V_113 = 0 ;
V_111 -= ( V_79 -> V_113 - V_101 -> V_123 ) ;
V_117 += ( V_79 -> V_113 - V_101 -> V_123 ) *
V_128 / V_129 * V_127 / 8 ;
} else {
V_113 = V_101 -> V_123 - V_79 -> V_113 ;
}
if ( V_79 -> V_114 > V_101 -> V_124 ) {
V_114 = 0 ;
V_112 -= ( V_79 -> V_114 - V_101 -> V_124 ) ;
V_117 += ( V_79 -> V_114 - V_101 -> V_124 ) *
V_130 / V_131 *
V_101 -> V_147 * V_127 / 8 ;
} else {
V_114 = V_101 -> V_124 - V_79 -> V_114 ;
}
if ( V_79 -> V_115 < ( V_113 + V_111 ) )
V_111 -= ( V_113 + V_111 ) - ( V_79 -> V_115 ) ;
if ( V_79 -> V_116 < ( V_114 + V_112 ) )
V_112 -= ( V_114 + V_112 ) - ( V_79 -> V_116 ) ;
V_115 = V_115 * V_111 / V_120 ;
V_116 = V_116 * V_112 / V_121 ;
if ( ( V_115 & 1 ) &&
( V_101 -> V_132 == V_136 ||
V_101 -> V_132 == V_137 ) ) {
if ( V_118 > V_115 )
V_115 += 1 ;
else
V_115 -= 1 ;
}
}
V_109 = * V_101 ;
V_109 . V_123 = V_113 ;
V_109 . V_124 = V_114 ;
V_109 . V_103 = V_115 ;
V_109 . V_105 = V_116 ;
V_109 . V_102 = V_111 ;
V_109 . V_104 = V_112 ;
V_109 . V_117 = V_117 ;
V_16 = F_47 ( V_107 , & V_109 , V_108 -> V_148 , V_108 -> V_122 ,
V_108 -> V_149 , V_108 -> V_150 , V_108 -> V_151 ) ;
if ( V_16 ) {
F_29 ( L_15 , V_107 ) ;
F_45 ( V_107 , 0 ) ;
return V_16 ;
}
F_45 ( V_107 , 1 ) ;
return 0 ;
}
static void F_48 ( enum V_152 V_122 )
{
struct V_14 * V_110 ;
F_44 ( L_14 , V_122 ) ;
V_110 = & V_83 . V_84 [ V_122 ] . V_11 ;
F_49 ( V_122 , V_110 -> V_12 ) ;
F_50 ( V_122 , V_110 -> V_22 , V_110 -> V_26 ) ;
F_51 ( V_122 , V_110 -> V_28 ) ;
F_52 ( V_122 , V_110 -> V_31 ) ;
if ( F_19 ( V_33 ) ) {
F_53 ( V_122 , V_110 -> V_32 ) ;
F_54 ( V_122 , & V_110 -> V_35 ) ;
}
}
static int F_55 ( void )
{
struct V_90 * V_91 ;
struct V_78 * V_79 ;
const int V_153 = F_56 () ;
const int V_154 = F_57 () ;
int V_47 ;
int V_16 ;
bool V_155 [ V_156 ] ;
bool V_157 [ V_156 ] ;
bool V_158 ;
V_16 = 0 ;
V_158 = false ;
for ( V_47 = 0 ; V_47 < V_154 ; V_47 ++ ) {
V_155 [ V_47 ] = F_58 ( V_47 ) ;
V_157 [ V_47 ] = false ;
}
for ( V_47 = 0 ; V_47 < V_153 ; ++ V_47 ) {
V_91 = & V_83 . V_92 [ V_47 ] ;
V_79 = & V_83 . V_84 [ V_91 -> V_122 ] ;
if ( ! V_91 -> V_87 )
continue;
if ( V_79 -> V_125 && ! V_79 -> V_126 )
continue;
if ( V_155 [ V_91 -> V_122 ] ) {
V_158 = true ;
continue;
}
V_16 = F_43 ( V_47 ) ;
if ( V_16 )
F_29 ( L_16 , V_47 ) ;
V_91 -> V_87 = false ;
V_91 -> V_86 = true ;
V_157 [ V_91 -> V_122 ] = true ;
}
for ( V_47 = 0 ; V_47 < V_154 ; ++ V_47 ) {
V_79 = & V_83 . V_84 [ V_47 ] ;
if ( ! V_79 -> V_87 )
continue;
if ( V_79 -> V_125 && ! V_79 -> V_126 )
continue;
if ( V_155 [ V_47 ] ) {
V_158 = true ;
continue;
}
F_48 ( V_47 ) ;
V_79 -> V_87 = false ;
V_79 -> V_86 = true ;
V_157 [ V_47 ] = true ;
}
for ( V_47 = 0 ; V_47 < V_154 ; ++ V_47 ) {
V_79 = & V_83 . V_84 [ V_47 ] ;
if ( ! V_157 [ V_47 ] )
continue;
if ( ! V_79 -> V_125 )
F_59 ( V_47 ) ;
}
if ( V_158 )
V_16 = 1 ;
else
V_16 = 0 ;
return V_16 ;
}
static void F_60 ( T_5 * V_113 , T_5 * V_115 )
{
T_5 V_93 , V_96 ;
V_93 = * V_113 ;
V_96 = * V_113 + * V_115 ;
V_93 &= ~ 1 ;
V_96 = F_61 ( V_96 , 2 ) ;
* V_113 = V_93 ;
* V_115 = V_96 - V_93 ;
}
void F_62 ( struct V_7 * V_8 ,
T_5 * V_159 , T_5 * V_160 , T_5 * V_161 , T_5 * V_162 , bool V_163 )
{
struct V_90 * V_91 ;
struct V_78 * V_79 ;
struct V_100 * V_101 ;
const int V_153 = F_56 () ;
struct V_1 * V_2 ;
int V_47 ;
T_5 V_113 , V_114 , V_115 , V_116 ;
unsigned long V_85 ;
bool V_164 ;
V_113 = * V_159 ;
V_114 = * V_160 ;
V_115 = * V_161 ;
V_116 = * V_162 ;
F_63 ( L_17 ,
* V_159 , * V_160 , * V_161 , * V_162 ) ;
V_2 = V_8 -> V_53 ;
if ( ! V_2 ) {
F_63 ( L_18 ) ;
return;
}
F_60 ( & V_113 , & V_115 ) ;
F_36 ( & V_83 . V_88 , V_85 ) ;
do {
V_164 = false ;
for ( V_47 = 0 ; V_47 < V_153 ; ++ V_47 ) {
unsigned V_93 , y1 , V_96 , V_97 ;
unsigned V_111 , V_112 ;
V_91 = & V_83 . V_92 [ V_47 ] ;
V_101 = & V_91 -> V_11 ;
if ( V_91 -> V_122 != V_2 -> V_74 )
continue;
V_91 -> V_87 = true ;
if ( ! V_163 )
continue;
if ( ! V_91 -> V_64 )
continue;
if ( ! F_42 ( V_91 ) )
continue;
V_111 = V_101 -> V_102 == 0 ?
V_101 -> V_103 : V_101 -> V_102 ;
V_112 = V_101 -> V_104 == 0 ?
V_101 -> V_105 : V_101 -> V_104 ;
if ( ! F_41 ( V_113 , V_114 , V_115 , V_116 ,
V_101 -> V_123 , V_101 -> V_124 ,
V_111 , V_112 ) )
continue;
if ( F_40 ( V_101 -> V_123 , V_101 -> V_124 , V_111 , V_112 ,
V_113 , V_114 , V_115 , V_116 ) )
continue;
if ( V_113 > V_101 -> V_123 )
V_93 = V_101 -> V_123 ;
else
V_93 = V_113 ;
if ( V_114 > V_101 -> V_124 )
y1 = V_101 -> V_124 ;
else
y1 = V_114 ;
if ( ( V_113 + V_115 ) < ( V_101 -> V_123 + V_111 ) )
V_96 = V_101 -> V_123 + V_111 ;
else
V_96 = V_113 + V_115 ;
if ( ( V_114 + V_116 ) < ( V_101 -> V_124 + V_112 ) )
V_97 = V_101 -> V_124 + V_112 ;
else
V_97 = V_114 + V_116 ;
V_113 = V_93 ;
V_114 = y1 ;
V_115 = V_96 - V_93 ;
V_116 = V_97 - y1 ;
F_60 ( & V_113 , & V_115 ) ;
F_63 ( L_19
L_20 ,
V_47 , V_113 , V_114 , V_115 , V_116 ) ;
V_164 = true ;
}
} while ( V_164 );
V_79 = & V_83 . V_84 [ V_2 -> V_74 ] ;
V_79 -> V_126 = true ;
V_79 -> V_163 = V_163 ;
V_79 -> V_113 = V_113 ;
V_79 -> V_114 = V_114 ;
V_79 -> V_115 = V_115 ;
V_79 -> V_116 = V_116 ;
F_55 () ;
V_79 -> V_126 = false ;
F_37 ( & V_83 . V_88 , V_85 ) ;
* V_159 = V_113 ;
* V_160 = V_114 ;
* V_161 = V_115 ;
* V_162 = V_116 ;
}
void F_64 ( struct V_7 * V_8 )
{
struct V_78 * V_79 ;
struct V_90 * V_91 ;
const int V_153 = F_56 () ;
const int V_154 = F_57 () ;
struct V_1 * V_2 ;
int V_47 ;
V_2 = V_8 -> V_53 ;
for ( V_47 = 0 ; V_47 < V_153 ; ++ V_47 ) {
V_91 = & V_83 . V_92 [ V_47 ] ;
if ( V_91 -> V_122 != V_2 -> V_74 )
continue;
V_91 -> V_86 = false ;
}
for ( V_47 = 0 ; V_47 < V_154 ; ++ V_47 ) {
V_79 = & V_83 . V_84 [ V_47 ] ;
if ( V_2 -> V_74 != V_47 )
continue;
V_79 -> V_86 = false ;
}
V_8 -> V_53 -> V_29 ( V_8 -> V_53 ) ;
}
static void F_65 ( void * V_9 , T_3 V_165 )
{
struct V_78 * V_79 ;
struct V_90 * V_91 ;
const int V_153 = F_56 () ;
const int V_154 = F_57 () ;
int V_47 , V_16 ;
bool V_155 [ V_156 ] ;
T_3 V_166 ;
for ( V_47 = 0 ; V_47 < V_154 ; V_47 ++ )
V_155 [ V_47 ] = F_58 ( V_47 ) ;
F_66 ( & V_83 . V_88 ) ;
for ( V_47 = 0 ; V_47 < V_153 ; ++ V_47 ) {
V_91 = & V_83 . V_92 [ V_47 ] ;
if ( ! V_155 [ V_91 -> V_122 ] )
V_91 -> V_86 = false ;
}
for ( V_47 = 0 ; V_47 < V_154 ; ++ V_47 ) {
V_79 = & V_83 . V_84 [ V_47 ] ;
if ( ! V_155 [ V_47 ] )
V_79 -> V_86 = false ;
}
V_16 = F_55 () ;
if ( V_16 == 1 )
goto V_167;
for ( V_47 = 0 ; V_47 < V_154 ; V_47 ++ )
V_155 [ V_47 ] = F_58 ( V_47 ) ;
for ( V_47 = 0 ; V_47 < V_154 ; ++ V_47 ) {
if ( V_155 [ V_47 ] )
goto V_167;
}
V_166 = V_76 | V_71 |
V_73 ;
if ( F_19 ( V_168 ) )
V_166 |= V_77 ;
F_67 ( F_65 , NULL , V_166 ) ;
V_83 . V_169 = false ;
V_167:
F_68 ( & V_83 . V_88 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
struct V_78 * V_79 ;
int V_47 ;
struct V_61 * V_62 ;
int V_170 = 0 ;
bool V_171 ;
unsigned long V_85 ;
int V_16 ;
F_63 ( L_21 , V_2 -> V_5 ) ;
V_16 = F_70 () ;
if ( V_16 )
return V_16 ;
F_36 ( & V_83 . V_88 , V_85 ) ;
for ( V_47 = 0 ; V_47 < F_71 () ; ++ V_47 ) {
struct V_7 * V_8 ;
V_62 = F_72 ( V_47 ) ;
V_91 = & V_83 . V_92 [ V_62 -> V_74 ] ;
if ( V_62 -> V_172 ) {
V_62 -> V_172 = false ;
V_62 -> V_173 = true ;
}
if ( ! F_39 ( V_62 ) ) {
if ( V_91 -> V_64 ) {
V_91 -> V_64 = false ;
V_91 -> V_87 = true ;
}
continue;
}
if ( ! V_62 -> V_173 ) {
if ( V_91 -> V_64 )
++ V_170 ;
continue;
}
V_8 = V_62 -> V_53 -> V_6 ;
if ( F_30 ( V_62 , V_8 ) ) {
if ( V_91 -> V_64 ) {
V_91 -> V_64 = false ;
V_91 -> V_87 = true ;
}
continue;
}
V_62 -> V_173 = false ;
V_91 -> V_87 = true ;
V_91 -> V_11 = V_62 -> V_11 ;
V_91 -> V_149 =
F_73 ( V_8 , V_62 -> V_11 . V_132 ) ;
V_91 -> V_148 = V_8 -> type == V_70 ;
V_91 -> V_122 = V_62 -> V_53 -> V_74 ;
V_91 -> V_64 = true ;
++ V_170 ;
}
F_74 (mgr, &manager_list, list) {
struct V_7 * V_8 ;
V_79 = & V_83 . V_84 [ V_2 -> V_74 ] ;
if ( V_2 -> V_65 ) {
V_2 -> V_65 = false ;
V_2 -> V_173 = true ;
}
if ( ! V_2 -> V_173 )
continue;
if ( ! V_2 -> V_6 )
continue;
V_8 = V_2 -> V_6 ;
V_2 -> V_173 = false ;
V_79 -> V_87 = true ;
V_79 -> V_11 = V_2 -> V_11 ;
V_79 -> V_125 =
V_8 -> V_81 & V_82 ;
}
V_171 = false ;
for ( V_47 = 0 ; V_47 < F_71 () ; ++ V_47 ) {
struct V_7 * V_8 ;
T_3 V_13 , V_174 ;
V_62 = F_72 ( V_47 ) ;
V_91 = & V_83 . V_92 [ V_62 -> V_74 ] ;
if ( ! V_91 -> V_64 )
continue;
V_8 = V_62 -> V_53 -> V_6 ;
V_13 = F_75 ( V_62 -> V_74 ) ;
if ( V_171 )
V_13 *= 3 ;
V_174 = F_76 ( V_62 -> V_74 ) ;
switch ( V_8 -> type ) {
case V_175 :
case V_176 :
case V_177 :
case V_70 :
case V_72 :
F_77 ( V_62 -> V_74 , V_13 ,
V_174 , & V_91 -> V_150 ,
& V_91 -> V_151 ) ;
break;
#ifdef F_78
case V_178 :
F_79 ( V_62 -> V_74 , V_13 ,
V_174 , & V_91 -> V_150 ,
& V_91 -> V_151 ) ;
break;
#endif
default:
F_46 () ;
}
}
V_16 = 0 ;
if ( ! V_83 . V_169 ) {
T_3 V_165 ;
V_165 = V_76 | V_71 |
V_73 ;
if ( F_19 ( V_168 ) )
V_165 |= V_77 ;
V_16 = F_80 ( F_65 , NULL , V_165 ) ;
V_83 . V_169 = true ;
}
F_55 () ;
F_37 ( & V_83 . V_88 , V_85 ) ;
F_81 () ;
return V_16 ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( F_19 ( V_30 ) ) {
if ( V_2 -> V_11 . V_31 && V_2 -> V_11 . V_28
&& V_2 -> V_11 . V_22 !=
V_24 )
return - V_25 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_14 * V_11 )
{
int V_16 ;
struct V_14 V_179 ;
V_179 = V_2 -> V_11 ;
V_2 -> V_11 = * V_11 ;
V_16 = F_82 ( V_2 ) ;
if ( V_16 ) {
V_2 -> V_11 = V_179 ;
return V_16 ;
}
V_2 -> V_173 = true ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_14 * V_11 )
{
* V_11 = V_2 -> V_11 ;
}
static int F_85 ( struct V_1 * V_2 )
{
F_86 ( V_2 -> V_74 , 1 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
F_86 ( V_2 -> V_74 , 0 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_53 )
{
++ V_180 ;
F_89 ( & V_53 -> V_181 , & V_182 ) ;
}
int F_90 ( struct V_183 * V_184 )
{
int V_47 , V_16 ;
F_91 ( & V_83 . V_88 ) ;
F_92 ( & V_182 ) ;
V_180 = 0 ;
for ( V_47 = 0 ; V_47 < F_57 () ; ++ V_47 ) {
struct V_1 * V_2 ;
V_2 = F_93 ( sizeof( * V_2 ) , V_185 ) ;
F_9 ( V_2 == NULL ) ;
switch ( V_47 ) {
case 0 :
V_2 -> V_5 = L_22 ;
V_2 -> V_74 = V_75 ;
break;
case 1 :
V_2 -> V_5 = L_23 ;
V_2 -> V_74 = V_186 ;
break;
case 2 :
V_2 -> V_5 = L_24 ;
V_2 -> V_74 = V_187 ;
break;
}
V_2 -> V_188 = & F_28 ;
V_2 -> V_189 = & F_31 ;
V_2 -> V_19 = & F_69 ;
V_2 -> V_18 = & F_83 ;
V_2 -> V_17 = & F_84 ;
V_2 -> V_190 = & F_35 ;
V_2 -> V_191 = & F_32 ;
V_2 -> V_29 = & F_85 ;
V_2 -> V_192 = & F_87 ;
V_2 -> V_81 = 0 ;
V_2 -> V_59 =
F_94 ( V_2 -> V_74 ) ;
F_95 ( V_2 ) ;
F_88 ( V_2 ) ;
V_16 = F_96 ( & V_2 -> V_50 , & V_193 ,
& V_184 -> V_194 . V_50 , L_25 , V_47 ) ;
if ( V_16 ) {
F_29 ( L_26 ) ;
continue;
}
}
return 0 ;
}
void F_97 ( struct V_183 * V_184 )
{
struct V_1 * V_2 ;
while ( ! F_98 ( & V_182 ) ) {
V_2 = F_99 ( & V_182 ,
struct V_1 , V_181 ) ;
F_100 ( & V_2 -> V_181 ) ;
F_101 ( & V_2 -> V_50 ) ;
F_102 ( & V_2 -> V_50 ) ;
F_103 ( V_2 ) ;
}
V_180 = 0 ;
}
int F_104 ( void )
{
return V_180 ;
}
struct V_1 * F_105 ( int V_195 )
{
int V_47 = 0 ;
struct V_1 * V_2 ;
F_74 (mgr, &manager_list, list) {
if ( V_47 ++ == V_195 )
return V_2 ;
}
return NULL ;
}
