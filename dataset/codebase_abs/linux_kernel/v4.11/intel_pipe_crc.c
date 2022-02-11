static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const void * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL ) {
F_3 ( V_4 ) ;
return - V_9 ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_10 = V_4 ;
V_7 -> V_11 = ( void * ) V_5 ;
F_4 ( & V_2 -> V_12 ) ;
F_5 ( & V_7 -> V_13 , & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_15 * V_15 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
struct V_23 * V_24 = & V_22 -> V_24 [ V_19 -> V_25 ] ;
if ( V_19 -> V_25 >= F_8 ( V_22 ) -> V_26 )
return - V_27 ;
F_9 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_29 ) {
F_10 ( & V_24 -> V_28 ) ;
return - V_30 ;
}
V_24 -> V_29 = true ;
V_17 -> V_31 = V_15 -> V_20 ;
F_10 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_11 ( struct V_15 * V_15 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
struct V_23 * V_24 = & V_22 -> V_24 [ V_19 -> V_25 ] ;
F_9 ( & V_24 -> V_28 ) ;
V_24 -> V_29 = false ;
F_10 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_24 )
{
F_13 ( & V_24 -> V_28 ) ;
return F_14 ( V_24 -> V_32 , V_24 -> V_33 ,
V_34 ) ;
}
static T_1
F_15 ( struct V_16 * V_17 , char T_2 * V_35 , T_3 V_36 ,
T_4 * V_37 )
{
struct V_18 * V_19 = V_17 -> V_31 ;
struct V_21 * V_22 = V_19 -> V_22 ;
struct V_23 * V_24 = & V_22 -> V_24 [ V_19 -> V_25 ] ;
char V_38 [ V_39 ] ;
int V_40 ;
T_1 V_41 ;
if ( V_36 < V_42 )
return - V_43 ;
if ( V_24 -> V_44 == V_45 )
return 0 ;
F_9 ( & V_24 -> V_28 ) ;
while ( F_12 ( V_24 ) == 0 ) {
int V_46 ;
if ( V_17 -> V_47 & V_48 ) {
F_10 ( & V_24 -> V_28 ) ;
return - V_49 ;
}
V_46 = F_16 ( V_24 -> V_50 ,
F_12 ( V_24 ) , V_24 -> V_28 ) ;
if ( V_46 ) {
F_10 ( & V_24 -> V_28 ) ;
return V_46 ;
}
}
V_40 = V_36 / V_42 ;
V_41 = 0 ;
while ( V_40 > 0 ) {
struct V_51 * V_52 =
& V_24 -> V_53 [ V_24 -> V_33 ] ;
if ( F_14 ( V_24 -> V_32 , V_24 -> V_33 ,
V_34 ) < 1 )
break;
F_17 ( V_34 ) ;
V_24 -> V_33 = ( V_24 -> V_33 + 1 ) &
( V_34 - 1 ) ;
V_41 += snprintf ( V_38 , V_39 ,
L_1 ,
V_52 -> V_54 , V_52 -> V_55 [ 0 ] ,
V_52 -> V_55 [ 1 ] , V_52 -> V_55 [ 2 ] ,
V_52 -> V_55 [ 3 ] , V_52 -> V_55 [ 4 ] ) ;
F_10 ( & V_24 -> V_28 ) ;
if ( F_18 ( V_35 , V_38 , V_42 ) )
return - V_56 ;
V_35 += V_42 ;
V_40 -- ;
F_9 ( & V_24 -> V_28 ) ;
}
F_10 ( & V_24 -> V_28 ) ;
return V_41 ;
}
static int F_19 ( struct V_3 * V_57 , struct V_1 * V_2 ,
enum V_25 V_25 )
{
struct V_21 * V_22 = F_20 ( V_2 -> V_58 ) ;
struct V_3 * V_4 ;
struct V_18 * V_19 = & V_59 [ V_25 ] ;
V_19 -> V_22 = V_22 ;
V_4 = F_21 ( V_19 -> V_60 , V_61 , V_57 , V_19 ,
& V_62 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_19 ) ;
}
static const char * F_22 ( enum V_63 V_44 )
{
F_23 ( F_24 ( V_64 ) != V_65 ) ;
return V_64 [ V_44 ] ;
}
static int F_25 ( struct V_66 * V_67 , void * V_68 )
{
struct V_21 * V_22 = V_67 -> V_69 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_26 ( V_67 , L_2 , F_27 ( V_70 ) ,
F_22 ( V_22 -> V_24 [ V_70 ] . V_44 ) ) ;
return 0 ;
}
static int F_28 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_29 ( V_16 , F_25 , V_15 -> V_20 ) ;
}
static int F_30 ( enum V_63 * V_44 ,
T_5 * V_72 )
{
if ( * V_44 == V_73 )
* V_44 = V_74 ;
switch ( * V_44 ) {
case V_74 :
* V_72 = V_75 | V_76 ;
break;
case V_45 :
* V_72 = 0 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_31 ( struct V_21 * V_22 ,
enum V_25 V_25 ,
enum V_63 * V_44 )
{
struct V_77 * V_58 = & V_22 -> V_78 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_46 = 0 ;
* V_44 = V_74 ;
F_32 ( V_58 ) ;
F_33 (dev, encoder) {
if ( ! V_80 -> V_85 . V_82 )
continue;
V_82 = F_34 ( V_80 -> V_85 . V_82 ) ;
if ( V_82 -> V_25 != V_25 )
continue;
switch ( V_80 -> type ) {
case V_86 :
* V_44 = V_87 ;
break;
case V_88 :
case V_89 :
V_84 = F_35 ( & V_80 -> V_85 ) ;
switch ( V_84 -> V_90 ) {
case V_91 :
* V_44 = V_92 ;
break;
case V_93 :
* V_44 = V_94 ;
break;
case V_95 :
* V_44 = V_96 ;
break;
default:
F_36 ( 1 , L_3 ,
F_37 ( V_84 -> V_90 ) ) ;
break;
}
break;
default:
break;
}
}
F_38 ( V_58 ) ;
return V_46 ;
}
static int F_39 ( struct V_21 * V_22 ,
enum V_25 V_25 ,
enum V_63 * V_44 ,
T_5 * V_72 )
{
bool V_97 = false ;
if ( * V_44 == V_73 ) {
int V_46 = F_31 ( V_22 , V_25 , V_44 ) ;
if ( V_46 )
return V_46 ;
}
switch ( * V_44 ) {
case V_74 :
* V_72 = V_75 | V_98 ;
break;
case V_92 :
* V_72 = V_75 | V_99 ;
V_97 = true ;
break;
case V_94 :
* V_72 = V_75 | V_100 ;
V_97 = true ;
break;
case V_96 :
if ( ! F_40 ( V_22 ) )
return - V_43 ;
* V_72 = V_75 | V_101 ;
V_97 = true ;
break;
case V_45 :
* V_72 = 0 ;
break;
default:
return - V_43 ;
}
if ( V_97 ) {
T_5 V_102 = F_41 ( V_103 ) ;
V_102 |= V_104 ;
switch ( V_25 ) {
case V_105 :
V_102 |= V_106 ;
break;
case V_107 :
V_102 |= V_108 ;
break;
case V_109 :
V_102 |= V_110 ;
break;
default:
return - V_43 ;
}
F_42 ( V_103 , V_102 ) ;
}
return 0 ;
}
static int F_43 ( struct V_21 * V_22 ,
enum V_25 V_25 ,
enum V_63 * V_44 ,
T_5 * V_72 )
{
bool V_97 = false ;
if ( * V_44 == V_73 ) {
int V_46 = F_31 ( V_22 , V_25 , V_44 ) ;
if ( V_46 )
return V_46 ;
}
switch ( * V_44 ) {
case V_74 :
* V_72 = V_75 | V_111 ;
break;
case V_87 :
if ( ! F_44 ( V_22 ) )
return - V_43 ;
* V_72 = V_75 | V_112 ;
break;
case V_92 :
if ( ! F_45 ( V_22 ) )
return - V_43 ;
* V_72 = V_75 | V_113 ;
V_97 = true ;
break;
case V_94 :
if ( ! F_45 ( V_22 ) )
return - V_43 ;
* V_72 = V_75 | V_114 ;
V_97 = true ;
break;
case V_96 :
if ( ! F_45 ( V_22 ) )
return - V_43 ;
* V_72 = V_75 | V_115 ;
V_97 = true ;
break;
case V_45 :
* V_72 = 0 ;
break;
default:
return - V_43 ;
}
if ( V_97 ) {
T_5 V_102 = F_41 ( V_103 ) ;
F_46 ( ! F_45 ( V_22 ) ) ;
F_42 ( V_116 ,
F_41 ( V_116 ) | V_117 ) ;
if ( V_25 == V_105 )
V_102 |= V_106 ;
else
V_102 |= V_108 ;
F_42 ( V_103 , V_102 ) ;
}
return 0 ;
}
static void F_47 ( struct V_21 * V_22 ,
enum V_25 V_25 )
{
T_5 V_102 = F_41 ( V_103 ) ;
switch ( V_25 ) {
case V_105 :
V_102 &= ~ V_106 ;
break;
case V_107 :
V_102 &= ~ V_108 ;
break;
case V_109 :
V_102 &= ~ V_110 ;
break;
default:
return;
}
if ( ! ( V_102 & V_118 ) )
V_102 &= ~ V_104 ;
F_42 ( V_103 , V_102 ) ;
}
static void F_48 ( struct V_21 * V_22 ,
enum V_25 V_25 )
{
T_5 V_102 = F_41 ( V_103 ) ;
if ( V_25 == V_105 )
V_102 &= ~ V_106 ;
else
V_102 &= ~ V_108 ;
F_42 ( V_103 , V_102 ) ;
if ( ! ( V_102 & V_118 ) ) {
F_42 ( V_116 ,
F_41 ( V_116 ) & ~ V_117 ) ;
}
}
static int F_49 ( enum V_63 * V_44 ,
T_5 * V_72 )
{
if ( * V_44 == V_73 )
* V_44 = V_74 ;
switch ( * V_44 ) {
case V_119 :
* V_72 = V_75 | V_120 ;
break;
case V_121 :
* V_72 = V_75 | V_122 ;
break;
case V_74 :
* V_72 = V_75 | V_123 ;
break;
case V_45 :
* V_72 = 0 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static void F_50 ( struct V_21 * V_22 ,
bool V_124 )
{
struct V_77 * V_58 = & V_22 -> V_78 ;
struct V_81 * V_82 = F_51 ( V_22 , V_105 ) ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
int V_46 = 0 ;
F_32 ( V_58 ) ;
V_128 = F_52 ( V_58 ) ;
if ( ! V_128 ) {
V_46 = - V_9 ;
goto V_129;
}
V_128 -> V_130 = F_53 ( & V_82 -> V_85 ) ;
V_126 = F_54 ( V_128 , V_82 ) ;
if ( F_55 ( V_126 ) ) {
V_46 = F_56 ( V_126 ) ;
goto V_131;
}
V_126 -> V_132 . V_133 = V_124 ;
if ( V_126 -> V_134 == V_135 &&
V_126 -> V_132 . V_136 != V_124 )
V_126 -> V_85 . V_137 = true ;
V_46 = F_57 ( V_128 ) ;
V_131:
F_58 ( V_128 ) ;
V_129:
F_36 ( V_46 , L_4 , V_124 , V_46 ) ;
F_38 ( V_58 ) ;
}
static int F_59 ( struct V_21 * V_22 ,
enum V_25 V_25 ,
enum V_63 * V_44 ,
T_5 * V_72 )
{
if ( * V_44 == V_73 )
* V_44 = V_138 ;
switch ( * V_44 ) {
case V_119 :
* V_72 = V_75 | V_139 ;
break;
case V_121 :
* V_72 = V_75 | V_140 ;
break;
case V_138 :
if ( F_60 ( V_22 ) && V_25 == V_105 )
F_50 ( V_22 , true ) ;
* V_72 = V_75 | V_141 ;
break;
case V_45 :
* V_72 = 0 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_61 ( struct V_21 * V_22 ,
enum V_25 V_25 ,
enum V_63 * V_44 , T_6 * V_72 )
{
if ( F_62 ( V_22 ) )
return F_30 ( V_44 , V_72 ) ;
else if ( F_63 ( V_22 ) < 5 )
return F_43 ( V_22 , V_25 , V_44 , V_72 ) ;
else if ( F_64 ( V_22 ) || F_40 ( V_22 ) )
return F_39 ( V_22 , V_25 , V_44 , V_72 ) ;
else if ( F_65 ( V_22 ) || F_66 ( V_22 ) )
return F_49 ( V_44 , V_72 ) ;
else
return F_59 ( V_22 , V_25 , V_44 , V_72 ) ;
}
static int F_67 ( struct V_21 * V_22 ,
enum V_25 V_25 ,
enum V_63 V_44 )
{
struct V_23 * V_24 = & V_22 -> V_24 [ V_25 ] ;
struct V_81 * V_82 = F_51 ( V_22 , V_25 ) ;
enum V_142 V_143 ;
T_6 V_72 = 0 ;
int V_46 ;
if ( V_24 -> V_44 == V_44 )
return 0 ;
if ( V_24 -> V_44 && V_44 )
return - V_43 ;
V_143 = F_68 ( V_25 ) ;
if ( ! F_69 ( V_22 , V_143 ) ) {
F_70 ( L_5 ) ;
return - V_144 ;
}
V_46 = F_61 ( V_22 , V_25 , & V_44 , & V_72 ) ;
if ( V_46 != 0 )
goto V_145;
if ( V_44 ) {
struct V_51 * V_53 ;
F_71 ( L_6 ,
F_27 ( V_25 ) , F_22 ( V_44 ) ) ;
V_53 = F_72 ( V_34 ,
sizeof( V_24 -> V_53 [ 0 ] ) ,
V_8 ) ;
if ( ! V_53 ) {
V_46 = - V_9 ;
goto V_145;
}
F_73 ( V_82 ) ;
F_9 ( & V_24 -> V_28 ) ;
F_74 ( V_24 -> V_53 ) ;
V_24 -> V_53 = V_53 ;
V_24 -> V_32 = 0 ;
V_24 -> V_33 = 0 ;
F_10 ( & V_24 -> V_28 ) ;
}
V_24 -> V_44 = V_44 ;
F_42 ( F_75 ( V_25 ) , V_72 ) ;
F_76 ( F_75 ( V_25 ) ) ;
if ( ! V_44 ) {
struct V_51 * V_53 ;
struct V_81 * V_82 = F_51 ( V_22 ,
V_25 ) ;
F_71 ( L_7 ,
F_27 ( V_25 ) ) ;
F_77 ( & V_82 -> V_85 . V_146 , NULL ) ;
if ( V_82 -> V_85 . V_128 -> V_147 )
F_78 ( V_22 , V_25 ) ;
F_79 ( & V_82 -> V_85 . V_146 ) ;
F_9 ( & V_24 -> V_28 ) ;
V_53 = V_24 -> V_53 ;
V_24 -> V_53 = NULL ;
V_24 -> V_32 = 0 ;
V_24 -> V_33 = 0 ;
F_10 ( & V_24 -> V_28 ) ;
F_74 ( V_53 ) ;
if ( F_45 ( V_22 ) )
F_48 ( V_22 , V_25 ) ;
else if ( F_64 ( V_22 ) || F_40 ( V_22 ) )
F_47 ( V_22 , V_25 ) ;
else if ( F_60 ( V_22 ) && V_25 == V_105 )
F_50 ( V_22 , false ) ;
F_80 ( V_82 ) ;
}
V_46 = 0 ;
V_145:
F_81 ( V_22 , V_143 ) ;
return V_46 ;
}
static int F_82 ( char * V_38 , char * V_148 [] , int V_149 )
{
int V_150 = 0 ;
while ( * V_38 ) {
char * V_151 ;
V_38 = F_83 ( V_38 ) ;
if ( ! * V_38 )
break;
for ( V_151 = V_38 ; * V_151 && ! isspace ( * V_151 ) ; V_151 ++ )
;
if ( V_150 == V_149 ) {
F_71 ( L_8 ,
V_149 ) ;
return - V_43 ;
}
if ( * V_151 )
* V_151 ++ = '\0' ;
V_148 [ V_150 ++ ] = V_38 ;
V_38 = V_151 ;
}
return V_150 ;
}
static int
F_84 ( const char * V_38 , enum V_152 * V_153 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_24 ( V_154 ) ; V_70 ++ )
if ( ! strcmp ( V_38 , V_154 [ V_70 ] ) ) {
* V_153 = V_70 ;
return 0 ;
}
return - V_43 ;
}
static int F_85 ( const char * V_38 , enum V_25 * V_25 )
{
const char V_60 = V_38 [ 0 ] ;
if ( V_60 < 'A' || V_60 >= F_27 ( V_71 ) )
return - V_43 ;
* V_25 = V_60 - 'A' ;
return 0 ;
}
static int
F_86 ( const char * V_38 , enum V_63 * V_155 )
{
int V_70 ;
if ( ! V_38 ) {
* V_155 = V_45 ;
return 0 ;
}
for ( V_70 = 0 ; V_70 < F_24 ( V_64 ) ; V_70 ++ )
if ( ! strcmp ( V_38 , V_64 [ V_70 ] ) ) {
* V_155 = V_70 ;
return 0 ;
}
return - V_43 ;
}
static int F_87 ( struct V_21 * V_22 ,
char * V_38 , T_3 V_156 )
{
#define F_88 3
int V_150 ;
char * V_148 [ F_88 ] ;
enum V_25 V_25 ;
enum V_152 V_157 ;
enum V_63 V_44 ;
V_150 = F_82 ( V_38 , V_148 , F_88 ) ;
if ( V_150 != F_88 ) {
F_71 ( L_9 ,
F_88 ) ;
return - V_43 ;
}
if ( F_84 ( V_148 [ 0 ] , & V_157 ) < 0 ) {
F_71 ( L_10 , V_148 [ 0 ] ) ;
return - V_43 ;
}
if ( F_85 ( V_148 [ 1 ] , & V_25 ) < 0 ) {
F_71 ( L_11 , V_148 [ 1 ] ) ;
return - V_43 ;
}
if ( F_86 ( V_148 [ 2 ] , & V_44 ) < 0 ) {
F_71 ( L_12 , V_148 [ 2 ] ) ;
return - V_43 ;
}
return F_67 ( V_22 , V_25 , V_44 ) ;
}
static T_1 F_89 ( struct V_16 * V_16 , const char T_2 * V_158 ,
T_3 V_156 , T_4 * V_159 )
{
struct V_66 * V_67 = V_16 -> V_31 ;
struct V_21 * V_22 = V_67 -> V_69 ;
char * V_160 ;
int V_46 ;
if ( V_156 == 0 )
return 0 ;
if ( V_156 > V_161 - 1 ) {
F_71 ( L_13 ,
V_161 ) ;
return - V_162 ;
}
V_160 = F_2 ( V_156 + 1 , V_8 ) ;
if ( ! V_160 )
return - V_9 ;
if ( F_90 ( V_160 , V_158 , V_156 ) ) {
V_46 = - V_56 ;
goto V_145;
}
V_160 [ V_156 ] = '\0' ;
V_46 = F_87 ( V_22 , V_160 , V_156 ) ;
V_145:
F_74 ( V_160 ) ;
if ( V_46 < 0 )
return V_46 ;
* V_159 += V_156 ;
return V_156 ;
}
void F_91 ( struct V_21 * V_22 )
{
enum V_25 V_25 ;
F_92 (dev_priv, pipe) {
struct V_23 * V_24 = & V_22 -> V_24 [ V_25 ] ;
V_24 -> V_29 = false ;
F_93 ( & V_24 -> V_28 ) ;
F_94 ( & V_24 -> V_50 ) ;
}
}
int F_95 ( struct V_1 * V_2 )
{
int V_46 , V_70 ;
for ( V_70 = 0 ; V_70 < F_24 ( V_59 ) ; V_70 ++ ) {
V_46 = F_19 ( V_2 -> V_163 , V_2 , V_70 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
void F_96 ( struct V_1 * V_2 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_24 ( V_59 ) ; V_70 ++ ) {
struct V_164 * V_165 =
(struct V_164 * ) & V_59 [ V_70 ] ;
F_97 ( V_165 , 1 , V_2 ) ;
}
}
int F_98 ( struct V_166 * V_82 , const char * V_167 ,
T_3 * V_168 )
{
struct V_21 * V_22 = V_82 -> V_58 -> V_169 ;
struct V_23 * V_24 = & V_22 -> V_24 [ V_82 -> V_170 ] ;
struct V_81 * V_81 = F_34 ( V_82 ) ;
enum V_142 V_143 ;
enum V_63 V_44 ;
T_6 V_72 = 0 ;
int V_46 = 0 ;
if ( F_86 ( V_167 , & V_44 ) < 0 ) {
F_71 ( L_12 , V_167 ) ;
return - V_43 ;
}
V_143 = F_68 ( V_82 -> V_170 ) ;
if ( ! F_69 ( V_22 , V_143 ) ) {
F_70 ( L_5 ) ;
return - V_144 ;
}
V_46 = F_61 ( V_22 , V_82 -> V_170 , & V_44 , & V_72 ) ;
if ( V_46 != 0 )
goto V_145;
if ( V_44 ) {
F_73 ( V_81 ) ;
}
F_42 ( F_75 ( V_82 -> V_170 ) , V_72 ) ;
F_76 ( F_75 ( V_82 -> V_170 ) ) ;
if ( ! V_44 ) {
if ( F_45 ( V_22 ) )
F_48 ( V_22 , V_82 -> V_170 ) ;
else if ( F_64 ( V_22 ) || F_40 ( V_22 ) )
F_47 ( V_22 , V_82 -> V_170 ) ;
else if ( F_60 ( V_22 ) && V_82 -> V_170 == V_105 )
F_50 ( V_22 , false ) ;
F_80 ( V_81 ) ;
}
V_24 -> V_171 = 0 ;
* V_168 = 5 ;
V_145:
F_81 ( V_22 , V_143 ) ;
return V_46 ;
}
