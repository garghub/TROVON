static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 [ V_5 -> V_11 ] ;
if ( V_5 -> V_11 >= F_2 ( V_8 ) -> V_12 )
return - V_13 ;
F_3 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_15 ) {
F_4 ( & V_10 -> V_14 ) ;
return - V_16 ;
}
V_10 -> V_15 = true ;
V_3 -> V_17 = V_1 -> V_6 ;
F_4 ( & V_10 -> V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 [ V_5 -> V_11 ] ;
F_3 ( & V_10 -> V_14 ) ;
V_10 -> V_15 = false ;
F_4 ( & V_10 -> V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 )
{
F_7 ( & V_10 -> V_14 ) ;
return F_8 ( V_10 -> V_18 , V_10 -> V_19 ,
V_20 ) ;
}
static T_1
F_9 ( struct V_2 * V_3 , char T_2 * V_21 , T_3 V_22 ,
T_4 * V_23 )
{
struct V_4 * V_5 = V_3 -> V_17 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 [ V_5 -> V_11 ] ;
char V_24 [ V_25 ] ;
int V_26 ;
T_1 V_27 ;
if ( V_22 < V_28 )
return - V_29 ;
if ( V_10 -> V_30 == V_31 )
return 0 ;
F_3 ( & V_10 -> V_14 ) ;
while ( F_6 ( V_10 ) == 0 ) {
int V_32 ;
if ( V_3 -> V_33 & V_34 ) {
F_4 ( & V_10 -> V_14 ) ;
return - V_35 ;
}
V_32 = F_10 ( V_10 -> V_36 ,
F_6 ( V_10 ) , V_10 -> V_14 ) ;
if ( V_32 ) {
F_4 ( & V_10 -> V_14 ) ;
return V_32 ;
}
}
V_26 = V_22 / V_28 ;
V_27 = 0 ;
while ( V_26 > 0 ) {
struct V_37 * V_38 =
& V_10 -> V_39 [ V_10 -> V_19 ] ;
if ( F_8 ( V_10 -> V_18 , V_10 -> V_19 ,
V_20 ) < 1 )
break;
F_11 ( V_20 ) ;
V_10 -> V_19 = ( V_10 -> V_19 + 1 ) &
( V_20 - 1 ) ;
V_27 += snprintf ( V_24 , V_25 ,
L_1 ,
V_38 -> V_40 , V_38 -> V_41 [ 0 ] ,
V_38 -> V_41 [ 1 ] , V_38 -> V_41 [ 2 ] ,
V_38 -> V_41 [ 3 ] , V_38 -> V_41 [ 4 ] ) ;
F_4 ( & V_10 -> V_14 ) ;
if ( F_12 ( V_21 , V_24 , V_28 ) )
return - V_42 ;
V_21 += V_28 ;
V_26 -- ;
F_3 ( & V_10 -> V_14 ) ;
}
F_4 ( & V_10 -> V_14 ) ;
return V_27 ;
}
static const char * F_13 ( enum V_43 V_30 )
{
F_14 ( F_15 ( V_44 ) != V_45 ) ;
return V_44 [ V_30 ] ;
}
static int F_16 ( struct V_46 * V_47 , void * V_48 )
{
struct V_7 * V_8 = V_47 -> V_49 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ )
F_17 ( V_47 , L_2 , F_18 ( V_50 ) ,
F_13 ( V_8 -> V_10 [ V_50 ] . V_30 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_20 ( V_2 , F_16 , V_1 -> V_6 ) ;
}
static int F_21 ( enum V_43 * V_30 ,
T_5 * V_52 )
{
if ( * V_30 == V_53 )
* V_30 = V_54 ;
switch ( * V_30 ) {
case V_54 :
* V_52 = V_55 | V_56 ;
break;
case V_31 :
* V_52 = 0 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 )
{
struct V_57 * V_58 = & V_8 -> V_59 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
int V_32 = 0 ;
* V_30 = V_54 ;
F_23 ( V_58 ) ;
F_24 (dev, encoder) {
if ( ! V_61 -> V_66 . V_63 )
continue;
V_63 = F_25 ( V_61 -> V_66 . V_63 ) ;
if ( V_63 -> V_11 != V_11 )
continue;
switch ( V_61 -> type ) {
case V_67 :
* V_30 = V_68 ;
break;
case V_69 :
case V_70 :
V_65 = F_26 ( & V_61 -> V_66 ) ;
switch ( V_65 -> V_71 ) {
case V_72 :
* V_30 = V_73 ;
break;
case V_74 :
* V_30 = V_75 ;
break;
case V_76 :
* V_30 = V_77 ;
break;
default:
F_27 ( 1 , L_3 ,
F_28 ( V_65 -> V_71 ) ) ;
break;
}
break;
default:
break;
}
}
F_29 ( V_58 ) ;
return V_32 ;
}
static int F_30 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 ,
T_5 * V_52 )
{
bool V_78 = false ;
if ( * V_30 == V_53 ) {
int V_32 = F_22 ( V_8 , V_11 , V_30 ) ;
if ( V_32 )
return V_32 ;
}
switch ( * V_30 ) {
case V_54 :
* V_52 = V_55 | V_79 ;
break;
case V_73 :
* V_52 = V_55 | V_80 ;
V_78 = true ;
break;
case V_75 :
* V_52 = V_55 | V_81 ;
V_78 = true ;
break;
case V_77 :
if ( ! F_31 ( V_8 ) )
return - V_29 ;
* V_52 = V_55 | V_82 ;
V_78 = true ;
break;
case V_31 :
* V_52 = 0 ;
break;
default:
return - V_29 ;
}
if ( V_78 ) {
T_5 V_83 = F_32 ( V_84 ) ;
V_83 |= V_85 ;
switch ( V_11 ) {
case V_86 :
V_83 |= V_87 ;
break;
case V_88 :
V_83 |= V_89 ;
break;
case V_90 :
V_83 |= V_91 ;
break;
default:
return - V_29 ;
}
F_33 ( V_84 , V_83 ) ;
}
return 0 ;
}
static int F_34 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 ,
T_5 * V_52 )
{
bool V_78 = false ;
if ( * V_30 == V_53 ) {
int V_32 = F_22 ( V_8 , V_11 , V_30 ) ;
if ( V_32 )
return V_32 ;
}
switch ( * V_30 ) {
case V_54 :
* V_52 = V_55 | V_92 ;
break;
case V_68 :
if ( ! F_35 ( V_8 ) )
return - V_29 ;
* V_52 = V_55 | V_93 ;
break;
case V_73 :
if ( ! F_36 ( V_8 ) )
return - V_29 ;
* V_52 = V_55 | V_94 ;
V_78 = true ;
break;
case V_75 :
if ( ! F_36 ( V_8 ) )
return - V_29 ;
* V_52 = V_55 | V_95 ;
V_78 = true ;
break;
case V_77 :
if ( ! F_36 ( V_8 ) )
return - V_29 ;
* V_52 = V_55 | V_96 ;
V_78 = true ;
break;
case V_31 :
* V_52 = 0 ;
break;
default:
return - V_29 ;
}
if ( V_78 ) {
T_5 V_83 = F_32 ( V_84 ) ;
F_37 ( ! F_36 ( V_8 ) ) ;
F_33 ( V_97 ,
F_32 ( V_97 ) | V_98 ) ;
if ( V_11 == V_86 )
V_83 |= V_87 ;
else
V_83 |= V_89 ;
F_33 ( V_84 , V_83 ) ;
}
return 0 ;
}
static void F_38 ( struct V_7 * V_8 ,
enum V_11 V_11 )
{
T_5 V_83 = F_32 ( V_84 ) ;
switch ( V_11 ) {
case V_86 :
V_83 &= ~ V_87 ;
break;
case V_88 :
V_83 &= ~ V_89 ;
break;
case V_90 :
V_83 &= ~ V_91 ;
break;
default:
return;
}
if ( ! ( V_83 & V_99 ) )
V_83 &= ~ V_85 ;
F_33 ( V_84 , V_83 ) ;
}
static void F_39 ( struct V_7 * V_8 ,
enum V_11 V_11 )
{
T_5 V_83 = F_32 ( V_84 ) ;
if ( V_11 == V_86 )
V_83 &= ~ V_87 ;
else
V_83 &= ~ V_89 ;
F_33 ( V_84 , V_83 ) ;
if ( ! ( V_83 & V_99 ) ) {
F_33 ( V_97 ,
F_32 ( V_97 ) & ~ V_98 ) ;
}
}
static int F_40 ( enum V_43 * V_30 ,
T_5 * V_52 )
{
if ( * V_30 == V_53 )
* V_30 = V_54 ;
switch ( * V_30 ) {
case V_100 :
* V_52 = V_55 | V_101 ;
break;
case V_102 :
* V_52 = V_55 | V_103 ;
break;
case V_54 :
* V_52 = V_55 | V_104 ;
break;
case V_31 :
* V_52 = 0 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static void F_41 ( struct V_7 * V_8 ,
bool V_105 )
{
struct V_57 * V_58 = & V_8 -> V_59 ;
struct V_62 * V_63 = F_42 ( V_8 , V_86 ) ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 V_111 ;
int V_32 = 0 ;
F_43 ( & V_111 , 0 ) ;
V_109 = F_44 ( V_58 ) ;
if ( ! V_109 ) {
V_32 = - V_112 ;
goto V_113;
}
V_109 -> V_114 = & V_111 ;
V_115:
V_107 = F_45 ( V_109 , V_63 ) ;
if ( F_46 ( V_107 ) ) {
V_32 = F_47 ( V_107 ) ;
goto V_116;
}
V_107 -> V_117 . V_118 = V_105 ;
if ( V_107 -> V_119 == V_120 &&
V_107 -> V_117 . V_121 != V_105 )
V_107 -> V_66 . V_122 = true ;
V_32 = F_48 ( V_109 ) ;
V_116:
if ( V_32 == - V_123 ) {
F_49 ( V_109 ) ;
F_50 ( & V_111 ) ;
goto V_115;
}
F_51 ( V_109 ) ;
V_113:
F_27 ( V_32 , L_4 , V_105 , V_32 ) ;
F_52 ( & V_111 ) ;
F_53 ( & V_111 ) ;
}
static int F_54 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 ,
T_5 * V_52 )
{
if ( * V_30 == V_53 )
* V_30 = V_124 ;
switch ( * V_30 ) {
case V_100 :
* V_52 = V_55 | V_125 ;
break;
case V_102 :
* V_52 = V_55 | V_126 ;
break;
case V_124 :
if ( F_55 ( V_8 ) && V_11 == V_86 )
F_41 ( V_8 , true ) ;
* V_52 = V_55 | V_127 ;
break;
case V_31 :
* V_52 = 0 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_56 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 , T_6 * V_52 )
{
if ( F_57 ( V_8 ) )
return F_21 ( V_30 , V_52 ) ;
else if ( F_58 ( V_8 ) < 5 )
return F_34 ( V_8 , V_11 , V_30 , V_52 ) ;
else if ( F_59 ( V_8 ) || F_31 ( V_8 ) )
return F_30 ( V_8 , V_11 , V_30 , V_52 ) ;
else if ( F_60 ( V_8 ) || F_61 ( V_8 ) )
return F_40 ( V_30 , V_52 ) ;
else
return F_54 ( V_8 , V_11 , V_30 , V_52 ) ;
}
static int F_62 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 V_30 )
{
struct V_9 * V_10 = & V_8 -> V_10 [ V_11 ] ;
struct V_62 * V_63 = F_42 ( V_8 , V_11 ) ;
enum V_128 V_129 ;
T_6 V_52 = 0 ;
int V_32 ;
if ( V_10 -> V_30 == V_30 )
return 0 ;
if ( V_10 -> V_30 && V_30 )
return - V_29 ;
V_129 = F_63 ( V_11 ) ;
if ( ! F_64 ( V_8 , V_129 ) ) {
F_65 ( L_5 ) ;
return - V_130 ;
}
V_32 = F_56 ( V_8 , V_11 , & V_30 , & V_52 ) ;
if ( V_32 != 0 )
goto V_131;
if ( V_30 ) {
struct V_37 * V_39 ;
F_66 ( L_6 ,
F_18 ( V_11 ) , F_13 ( V_30 ) ) ;
V_39 = F_67 ( V_20 ,
sizeof( V_10 -> V_39 [ 0 ] ) ,
V_132 ) ;
if ( ! V_39 ) {
V_32 = - V_112 ;
goto V_131;
}
F_68 ( V_63 ) ;
F_3 ( & V_10 -> V_14 ) ;
F_69 ( V_10 -> V_39 ) ;
V_10 -> V_39 = V_39 ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = 0 ;
F_4 ( & V_10 -> V_14 ) ;
}
V_10 -> V_30 = V_30 ;
F_33 ( F_70 ( V_11 ) , V_52 ) ;
F_71 ( F_70 ( V_11 ) ) ;
if ( ! V_30 ) {
struct V_37 * V_39 ;
struct V_62 * V_63 = F_42 ( V_8 ,
V_11 ) ;
F_66 ( L_7 ,
F_18 ( V_11 ) ) ;
F_72 ( & V_63 -> V_66 . V_133 , NULL ) ;
if ( V_63 -> V_66 . V_109 -> V_134 )
F_73 ( V_8 , V_11 ) ;
F_74 ( & V_63 -> V_66 . V_133 ) ;
F_3 ( & V_10 -> V_14 ) ;
V_39 = V_10 -> V_39 ;
V_10 -> V_39 = NULL ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = 0 ;
F_4 ( & V_10 -> V_14 ) ;
F_69 ( V_39 ) ;
if ( F_36 ( V_8 ) )
F_39 ( V_8 , V_11 ) ;
else if ( F_59 ( V_8 ) || F_31 ( V_8 ) )
F_38 ( V_8 , V_11 ) ;
else if ( F_55 ( V_8 ) && V_11 == V_86 )
F_41 ( V_8 , false ) ;
F_75 ( V_63 ) ;
}
V_32 = 0 ;
V_131:
F_76 ( V_8 , V_129 ) ;
return V_32 ;
}
static int F_77 ( char * V_24 , char * V_135 [] , int V_136 )
{
int V_137 = 0 ;
while ( * V_24 ) {
char * V_138 ;
V_24 = F_78 ( V_24 ) ;
if ( ! * V_24 )
break;
for ( V_138 = V_24 ; * V_138 && ! isspace ( * V_138 ) ; V_138 ++ )
;
if ( V_137 == V_136 ) {
F_66 ( L_8 ,
V_136 ) ;
return - V_29 ;
}
if ( * V_138 )
* V_138 ++ = '\0' ;
V_135 [ V_137 ++ ] = V_24 ;
V_24 = V_138 ;
}
return V_137 ;
}
static int
F_79 ( const char * V_24 , enum V_139 * V_140 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < F_15 ( V_141 ) ; V_50 ++ )
if ( ! strcmp ( V_24 , V_141 [ V_50 ] ) ) {
* V_140 = V_50 ;
return 0 ;
}
return - V_29 ;
}
static int F_80 ( const char * V_24 , enum V_11 * V_11 )
{
const char V_142 = V_24 [ 0 ] ;
if ( V_142 < 'A' || V_142 >= F_18 ( V_51 ) )
return - V_29 ;
* V_11 = V_142 - 'A' ;
return 0 ;
}
static int
F_81 ( const char * V_24 , enum V_43 * V_143 )
{
int V_50 ;
if ( ! V_24 ) {
* V_143 = V_31 ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < F_15 ( V_44 ) ; V_50 ++ )
if ( ! strcmp ( V_24 , V_44 [ V_50 ] ) ) {
* V_143 = V_50 ;
return 0 ;
}
return - V_29 ;
}
static int F_82 ( struct V_7 * V_8 ,
char * V_24 , T_3 V_144 )
{
#define F_83 3
int V_137 ;
char * V_135 [ F_83 ] ;
enum V_11 V_11 ;
enum V_139 V_145 ;
enum V_43 V_30 ;
V_137 = F_77 ( V_24 , V_135 , F_83 ) ;
if ( V_137 != F_83 ) {
F_66 ( L_9 ,
F_83 ) ;
return - V_29 ;
}
if ( F_79 ( V_135 [ 0 ] , & V_145 ) < 0 ) {
F_66 ( L_10 , V_135 [ 0 ] ) ;
return - V_29 ;
}
if ( F_80 ( V_135 [ 1 ] , & V_11 ) < 0 ) {
F_66 ( L_11 , V_135 [ 1 ] ) ;
return - V_29 ;
}
if ( F_81 ( V_135 [ 2 ] , & V_30 ) < 0 ) {
F_66 ( L_12 , V_135 [ 2 ] ) ;
return - V_29 ;
}
return F_62 ( V_8 , V_11 , V_30 ) ;
}
static T_1 F_84 ( struct V_2 * V_2 , const char T_2 * V_146 ,
T_3 V_144 , T_4 * V_147 )
{
struct V_46 * V_47 = V_2 -> V_17 ;
struct V_7 * V_8 = V_47 -> V_49 ;
char * V_148 ;
int V_32 ;
if ( V_144 == 0 )
return 0 ;
if ( V_144 > V_149 - 1 ) {
F_66 ( L_13 ,
V_149 ) ;
return - V_150 ;
}
V_148 = F_85 ( V_146 , V_144 ) ;
if ( F_46 ( V_148 ) )
return F_47 ( V_148 ) ;
V_32 = F_82 ( V_8 , V_148 , V_144 ) ;
F_69 ( V_148 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_147 += V_144 ;
return V_144 ;
}
void F_86 ( struct V_7 * V_8 )
{
enum V_11 V_11 ;
F_87 (dev_priv, pipe) {
struct V_9 * V_10 = & V_8 -> V_10 [ V_11 ] ;
V_10 -> V_15 = false ;
F_88 ( & V_10 -> V_14 ) ;
F_89 ( & V_10 -> V_36 ) ;
}
}
int F_90 ( struct V_151 * V_152 )
{
struct V_7 * V_8 = F_91 ( V_152 -> V_58 ) ;
struct V_153 * V_154 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_15 ( V_155 ) ; V_50 ++ ) {
struct V_4 * V_5 = & V_155 [ V_50 ] ;
V_5 -> V_8 = V_8 ;
V_154 = F_92 ( V_5 -> V_142 , V_156 ,
V_152 -> V_157 , V_5 ,
& V_158 ) ;
if ( ! V_154 )
return - V_112 ;
}
return 0 ;
}
int F_93 ( struct V_159 * V_63 , const char * V_160 ,
T_3 * V_161 )
{
struct V_7 * V_8 = V_63 -> V_58 -> V_162 ;
struct V_9 * V_10 = & V_8 -> V_10 [ V_63 -> V_163 ] ;
struct V_62 * V_62 = F_25 ( V_63 ) ;
enum V_128 V_129 ;
enum V_43 V_30 ;
T_6 V_52 = 0 ;
int V_32 = 0 ;
if ( F_81 ( V_160 , & V_30 ) < 0 ) {
F_66 ( L_12 , V_160 ) ;
return - V_29 ;
}
V_129 = F_63 ( V_63 -> V_163 ) ;
if ( ! F_64 ( V_8 , V_129 ) ) {
F_65 ( L_5 ) ;
return - V_130 ;
}
V_32 = F_56 ( V_8 , V_63 -> V_163 , & V_30 , & V_52 ) ;
if ( V_32 != 0 )
goto V_131;
if ( V_30 ) {
F_68 ( V_62 ) ;
}
F_33 ( F_70 ( V_63 -> V_163 ) , V_52 ) ;
F_71 ( F_70 ( V_63 -> V_163 ) ) ;
if ( ! V_30 ) {
if ( F_36 ( V_8 ) )
F_39 ( V_8 , V_63 -> V_163 ) ;
else if ( F_59 ( V_8 ) || F_31 ( V_8 ) )
F_38 ( V_8 , V_63 -> V_163 ) ;
else if ( F_55 ( V_8 ) && V_63 -> V_163 == V_86 )
F_41 ( V_8 , false ) ;
F_75 ( V_62 ) ;
}
V_10 -> V_164 = 0 ;
* V_161 = 5 ;
V_131:
F_76 ( V_8 , V_129 ) ;
return V_32 ;
}
