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
int V_32 = 0 ;
F_23 ( V_58 ) ;
V_109 = F_43 ( V_58 ) ;
if ( ! V_109 ) {
V_32 = - V_110 ;
goto V_111;
}
V_109 -> V_112 = V_63 -> V_66 . V_58 -> V_113 . V_112 ;
V_107 = F_44 ( V_109 , V_63 ) ;
if ( F_45 ( V_107 ) ) {
V_32 = F_46 ( V_107 ) ;
goto V_114;
}
V_107 -> V_115 . V_116 = V_105 ;
if ( V_107 -> V_117 == V_118 &&
V_107 -> V_115 . V_119 != V_105 )
V_107 -> V_66 . V_120 = true ;
V_32 = F_47 ( V_109 ) ;
V_114:
F_48 ( V_109 ) ;
V_111:
F_27 ( V_32 , L_4 , V_105 , V_32 ) ;
F_29 ( V_58 ) ;
}
static int F_49 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 ,
T_5 * V_52 )
{
if ( * V_30 == V_53 )
* V_30 = V_121 ;
switch ( * V_30 ) {
case V_100 :
* V_52 = V_55 | V_122 ;
break;
case V_102 :
* V_52 = V_55 | V_123 ;
break;
case V_121 :
if ( F_50 ( V_8 ) && V_11 == V_86 )
F_41 ( V_8 , true ) ;
* V_52 = V_55 | V_124 ;
break;
case V_31 :
* V_52 = 0 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_51 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 * V_30 , T_6 * V_52 )
{
if ( F_52 ( V_8 ) )
return F_21 ( V_30 , V_52 ) ;
else if ( F_53 ( V_8 ) < 5 )
return F_34 ( V_8 , V_11 , V_30 , V_52 ) ;
else if ( F_54 ( V_8 ) || F_31 ( V_8 ) )
return F_30 ( V_8 , V_11 , V_30 , V_52 ) ;
else if ( F_55 ( V_8 ) || F_56 ( V_8 ) )
return F_40 ( V_30 , V_52 ) ;
else
return F_49 ( V_8 , V_11 , V_30 , V_52 ) ;
}
static int F_57 ( struct V_7 * V_8 ,
enum V_11 V_11 ,
enum V_43 V_30 )
{
struct V_9 * V_10 = & V_8 -> V_10 [ V_11 ] ;
struct V_62 * V_63 = F_42 ( V_8 , V_11 ) ;
enum V_125 V_126 ;
T_6 V_52 = 0 ;
int V_32 ;
if ( V_10 -> V_30 == V_30 )
return 0 ;
if ( V_10 -> V_30 && V_30 )
return - V_29 ;
V_126 = F_58 ( V_11 ) ;
if ( ! F_59 ( V_8 , V_126 ) ) {
F_60 ( L_5 ) ;
return - V_127 ;
}
V_32 = F_51 ( V_8 , V_11 , & V_30 , & V_52 ) ;
if ( V_32 != 0 )
goto V_128;
if ( V_30 ) {
struct V_37 * V_39 ;
F_61 ( L_6 ,
F_18 ( V_11 ) , F_13 ( V_30 ) ) ;
V_39 = F_62 ( V_20 ,
sizeof( V_10 -> V_39 [ 0 ] ) ,
V_129 ) ;
if ( ! V_39 ) {
V_32 = - V_110 ;
goto V_128;
}
F_63 ( V_63 ) ;
F_3 ( & V_10 -> V_14 ) ;
F_64 ( V_10 -> V_39 ) ;
V_10 -> V_39 = V_39 ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = 0 ;
F_4 ( & V_10 -> V_14 ) ;
}
V_10 -> V_30 = V_30 ;
F_33 ( F_65 ( V_11 ) , V_52 ) ;
F_66 ( F_65 ( V_11 ) ) ;
if ( ! V_30 ) {
struct V_37 * V_39 ;
struct V_62 * V_63 = F_42 ( V_8 ,
V_11 ) ;
F_61 ( L_7 ,
F_18 ( V_11 ) ) ;
F_67 ( & V_63 -> V_66 . V_130 , NULL ) ;
if ( V_63 -> V_66 . V_109 -> V_131 )
F_68 ( V_8 , V_11 ) ;
F_69 ( & V_63 -> V_66 . V_130 ) ;
F_3 ( & V_10 -> V_14 ) ;
V_39 = V_10 -> V_39 ;
V_10 -> V_39 = NULL ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = 0 ;
F_4 ( & V_10 -> V_14 ) ;
F_64 ( V_39 ) ;
if ( F_36 ( V_8 ) )
F_39 ( V_8 , V_11 ) ;
else if ( F_54 ( V_8 ) || F_31 ( V_8 ) )
F_38 ( V_8 , V_11 ) ;
else if ( F_50 ( V_8 ) && V_11 == V_86 )
F_41 ( V_8 , false ) ;
F_70 ( V_63 ) ;
}
V_32 = 0 ;
V_128:
F_71 ( V_8 , V_126 ) ;
return V_32 ;
}
static int F_72 ( char * V_24 , char * V_132 [] , int V_133 )
{
int V_134 = 0 ;
while ( * V_24 ) {
char * V_135 ;
V_24 = F_73 ( V_24 ) ;
if ( ! * V_24 )
break;
for ( V_135 = V_24 ; * V_135 && ! isspace ( * V_135 ) ; V_135 ++ )
;
if ( V_134 == V_133 ) {
F_61 ( L_8 ,
V_133 ) ;
return - V_29 ;
}
if ( * V_135 )
* V_135 ++ = '\0' ;
V_132 [ V_134 ++ ] = V_24 ;
V_24 = V_135 ;
}
return V_134 ;
}
static int
F_74 ( const char * V_24 , enum V_136 * V_137 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < F_15 ( V_138 ) ; V_50 ++ )
if ( ! strcmp ( V_24 , V_138 [ V_50 ] ) ) {
* V_137 = V_50 ;
return 0 ;
}
return - V_29 ;
}
static int F_75 ( const char * V_24 , enum V_11 * V_11 )
{
const char V_139 = V_24 [ 0 ] ;
if ( V_139 < 'A' || V_139 >= F_18 ( V_51 ) )
return - V_29 ;
* V_11 = V_139 - 'A' ;
return 0 ;
}
static int
F_76 ( const char * V_24 , enum V_43 * V_140 )
{
int V_50 ;
if ( ! V_24 ) {
* V_140 = V_31 ;
return 0 ;
}
for ( V_50 = 0 ; V_50 < F_15 ( V_44 ) ; V_50 ++ )
if ( ! strcmp ( V_24 , V_44 [ V_50 ] ) ) {
* V_140 = V_50 ;
return 0 ;
}
return - V_29 ;
}
static int F_77 ( struct V_7 * V_8 ,
char * V_24 , T_3 V_141 )
{
#define F_78 3
int V_134 ;
char * V_132 [ F_78 ] ;
enum V_11 V_11 ;
enum V_136 V_142 ;
enum V_43 V_30 ;
V_134 = F_72 ( V_24 , V_132 , F_78 ) ;
if ( V_134 != F_78 ) {
F_61 ( L_9 ,
F_78 ) ;
return - V_29 ;
}
if ( F_74 ( V_132 [ 0 ] , & V_142 ) < 0 ) {
F_61 ( L_10 , V_132 [ 0 ] ) ;
return - V_29 ;
}
if ( F_75 ( V_132 [ 1 ] , & V_11 ) < 0 ) {
F_61 ( L_11 , V_132 [ 1 ] ) ;
return - V_29 ;
}
if ( F_76 ( V_132 [ 2 ] , & V_30 ) < 0 ) {
F_61 ( L_12 , V_132 [ 2 ] ) ;
return - V_29 ;
}
return F_57 ( V_8 , V_11 , V_30 ) ;
}
static T_1 F_79 ( struct V_2 * V_2 , const char T_2 * V_143 ,
T_3 V_141 , T_4 * V_144 )
{
struct V_46 * V_47 = V_2 -> V_17 ;
struct V_7 * V_8 = V_47 -> V_49 ;
char * V_145 ;
int V_32 ;
if ( V_141 == 0 )
return 0 ;
if ( V_141 > V_146 - 1 ) {
F_61 ( L_13 ,
V_146 ) ;
return - V_147 ;
}
V_145 = F_80 ( V_141 + 1 , V_129 ) ;
if ( ! V_145 )
return - V_110 ;
if ( F_81 ( V_145 , V_143 , V_141 ) ) {
V_32 = - V_42 ;
goto V_128;
}
V_145 [ V_141 ] = '\0' ;
V_32 = F_77 ( V_8 , V_145 , V_141 ) ;
V_128:
F_64 ( V_145 ) ;
if ( V_32 < 0 )
return V_32 ;
* V_144 += V_141 ;
return V_141 ;
}
void F_82 ( struct V_7 * V_8 )
{
enum V_11 V_11 ;
F_83 (dev_priv, pipe) {
struct V_9 * V_10 = & V_8 -> V_10 [ V_11 ] ;
V_10 -> V_15 = false ;
F_84 ( & V_10 -> V_14 ) ;
F_85 ( & V_10 -> V_36 ) ;
}
}
int F_86 ( struct V_148 * V_149 )
{
struct V_7 * V_8 = F_87 ( V_149 -> V_58 ) ;
struct V_150 * V_151 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_15 ( V_152 ) ; V_50 ++ ) {
struct V_4 * V_5 = & V_152 [ V_50 ] ;
V_5 -> V_8 = V_8 ;
V_151 = F_88 ( V_5 -> V_139 , V_153 ,
V_149 -> V_154 , V_5 ,
& V_155 ) ;
if ( ! V_151 )
return - V_110 ;
}
return 0 ;
}
int F_89 ( struct V_156 * V_63 , const char * V_157 ,
T_3 * V_158 )
{
struct V_7 * V_8 = V_63 -> V_58 -> V_159 ;
struct V_9 * V_10 = & V_8 -> V_10 [ V_63 -> V_160 ] ;
struct V_62 * V_62 = F_25 ( V_63 ) ;
enum V_125 V_126 ;
enum V_43 V_30 ;
T_6 V_52 = 0 ;
int V_32 = 0 ;
if ( F_76 ( V_157 , & V_30 ) < 0 ) {
F_61 ( L_12 , V_157 ) ;
return - V_29 ;
}
V_126 = F_58 ( V_63 -> V_160 ) ;
if ( ! F_59 ( V_8 , V_126 ) ) {
F_60 ( L_5 ) ;
return - V_127 ;
}
V_32 = F_51 ( V_8 , V_63 -> V_160 , & V_30 , & V_52 ) ;
if ( V_32 != 0 )
goto V_128;
if ( V_30 ) {
F_63 ( V_62 ) ;
}
F_33 ( F_65 ( V_63 -> V_160 ) , V_52 ) ;
F_66 ( F_65 ( V_63 -> V_160 ) ) ;
if ( ! V_30 ) {
if ( F_36 ( V_8 ) )
F_39 ( V_8 , V_63 -> V_160 ) ;
else if ( F_54 ( V_8 ) || F_31 ( V_8 ) )
F_38 ( V_8 , V_63 -> V_160 ) ;
else if ( F_50 ( V_8 ) && V_63 -> V_160 == V_86 )
F_41 ( V_8 , false ) ;
F_70 ( V_62 ) ;
}
V_10 -> V_161 = 0 ;
* V_158 = 5 ;
V_128:
F_71 ( V_8 , V_126 ) ;
return V_32 ;
}
