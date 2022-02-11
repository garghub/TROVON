static int T_1 F_1 ( char * V_1 )
{
if ( V_2 )
return 1 ;
V_2 = V_3 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
char * V_4 ;
while ( ( V_4 = F_3 ( & V_1 , L_1 ) ) != NULL ) {
if ( * V_4 == ' ' )
continue;
if ( ( strcmp ( V_4 , L_2 ) == 0 ) && ! V_2 )
V_2 = V_5 ;
else if ( strcmp ( V_4 , L_3 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( V_4 , L_4 ) == 0 )
V_7 = 1 ;
}
return 1 ;
}
static int T_1 F_4 ( char * V_1 )
{
V_6 = 1 ;
return 1 ;
}
static void F_5 ( void )
{
struct V_8 * V_9 ;
int V_10 ;
int V_11 ;
F_6 (entry, &ima_policy_rules, list) {
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( ! V_9 -> V_13 [ V_11 ] . V_14 )
continue;
V_10 = F_7 ( V_9 -> V_13 [ V_11 ] . type ,
V_15 ,
V_9 -> V_13 [ V_11 ] . V_16 ,
& V_9 -> V_13 [ V_11 ] . V_14 ) ;
F_8 ( ! V_9 -> V_13 [ V_11 ] . V_14 ) ;
}
}
}
static bool F_9 ( struct V_8 * V_14 , struct V_17 * V_17 ,
enum V_18 V_19 , int V_20 )
{
struct V_21 * V_22 = V_23 ;
const struct V_24 * V_24 = F_10 () ;
int V_11 ;
if ( ( V_14 -> V_25 & V_26 ) &&
( V_14 -> V_19 != V_19 && V_19 != V_27 ) )
return false ;
if ( ( V_14 -> V_25 & V_28 ) &&
( V_14 -> V_20 != V_20 && V_19 != V_27 ) )
return false ;
if ( ( V_14 -> V_25 & V_29 ) &&
( ! ( V_14 -> V_20 & V_20 ) && V_19 != V_27 ) )
return false ;
if ( ( V_14 -> V_25 & V_30 )
&& V_14 -> V_31 != V_17 -> V_32 -> V_33 )
return false ;
if ( ( V_14 -> V_25 & V_34 ) &&
! F_11 ( & V_14 -> V_35 , & V_17 -> V_32 -> V_36 ) )
return false ;
if ( ( V_14 -> V_25 & V_37 ) && ! V_14 -> V_38 ( V_24 -> V_39 , V_14 -> V_39 ) )
return false ;
if ( V_14 -> V_25 & V_40 ) {
if ( F_12 ( V_23 , V_41 ) ) {
if ( ! V_14 -> V_38 ( V_24 -> V_42 , V_14 -> V_39 )
&& ! V_14 -> V_38 ( V_24 -> V_43 , V_14 -> V_39 )
&& ! V_14 -> V_38 ( V_24 -> V_39 , V_14 -> V_39 ) )
return false ;
} else if ( ! V_14 -> V_38 ( V_24 -> V_42 , V_14 -> V_39 ) )
return false ;
}
if ( ( V_14 -> V_25 & V_44 ) &&
! V_14 -> V_45 ( V_17 -> V_46 , V_14 -> V_47 ) )
return false ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
int V_48 = 0 ;
T_2 V_49 , V_50 ;
int V_51 = 0 ;
if ( ! V_14 -> V_13 [ V_11 ] . V_14 )
continue;
V_52:
switch ( V_11 ) {
case V_53 :
case V_54 :
case V_55 :
F_13 ( V_17 , & V_49 ) ;
V_48 = F_14 ( V_49 ,
V_14 -> V_13 [ V_11 ] . type ,
V_15 ,
V_14 -> V_13 [ V_11 ] . V_14 ,
NULL ) ;
break;
case V_56 :
case V_57 :
case V_58 :
F_15 ( V_22 , & V_50 ) ;
V_48 = F_14 ( V_50 ,
V_14 -> V_13 [ V_11 ] . type ,
V_15 ,
V_14 -> V_13 [ V_11 ] . V_14 ,
NULL ) ;
default:
break;
}
if ( ( V_48 < 0 ) && ( ! V_51 ) ) {
V_51 = 1 ;
F_5 () ;
goto V_52;
}
if ( ! V_48 )
return false ;
}
return true ;
}
static int F_16 ( struct V_8 * V_14 , enum V_18 V_19 )
{
if ( ! ( V_14 -> V_25 & V_26 ) )
return V_59 ;
switch ( V_19 ) {
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
case V_27 :
return V_59 ;
case V_65 ... V_66 - 1 :
default:
return V_67 ;
}
}
int F_17 ( struct V_17 * V_17 , enum V_18 V_19 , int V_20 ,
int V_25 , int * V_68 )
{
struct V_8 * V_9 ;
int V_69 = 0 , V_70 = V_25 | ( V_25 << 1 ) ;
F_18 () ;
F_19 (entry, ima_rules, list) {
if ( ! ( V_9 -> V_69 & V_70 ) )
continue;
if ( ! F_9 ( V_9 , V_17 , V_19 , V_20 ) )
continue;
V_69 |= V_9 -> V_25 & V_71 ;
V_69 |= V_9 -> V_69 & V_72 ;
if ( V_9 -> V_69 & V_73 )
V_69 |= F_16 ( V_9 , V_19 ) ;
if ( V_9 -> V_69 & V_72 )
V_70 &= ~ ( V_9 -> V_69 | V_9 -> V_69 << 1 ) ;
else
V_70 &= ~ ( V_9 -> V_69 | V_9 -> V_69 >> 1 ) ;
if ( ( V_68 ) && ( V_9 -> V_25 & V_74 ) )
* V_68 = V_9 -> V_68 ;
if ( ! V_70 )
break;
}
F_20 () ;
return V_69 ;
}
void F_21 ( void )
{
struct V_8 * V_9 ;
F_6 (entry, ima_rules, list) {
if ( V_9 -> V_69 & V_72 )
V_75 |= V_9 -> V_69 ;
}
V_76 |= V_77 ;
if ( ! V_76 )
V_75 &= ~ V_73 ;
}
void T_1 F_22 ( void )
{
int V_11 , V_78 , V_79 , V_80 ;
V_78 = V_2 ? F_23 ( V_81 ) : 0 ;
V_79 = V_6 ?
F_23 ( V_82 ) : 0 ;
V_80 = V_7 ?
F_23 ( V_83 ) : 0 ;
for ( V_11 = 0 ; V_11 < V_78 ; V_11 ++ )
F_24 ( & V_81 [ V_11 ] . V_84 , & V_85 ) ;
switch ( V_2 ) {
case V_3 :
for ( V_11 = 0 ; V_11 < F_23 ( V_86 ) ; V_11 ++ )
F_24 ( & V_86 [ V_11 ] . V_84 ,
& V_85 ) ;
break;
case V_5 :
for ( V_11 = 0 ; V_11 < F_23 ( V_87 ) ; V_11 ++ )
F_24 ( & V_87 [ V_11 ] . V_84 ,
& V_85 ) ;
default:
break;
}
for ( V_11 = 0 ; V_11 < V_80 ; V_11 ++ )
F_24 ( & V_83 [ V_11 ] . V_84 ,
& V_85 ) ;
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ ) {
F_24 ( & V_82 [ V_11 ] . V_84 ,
& V_85 ) ;
if ( V_82 [ V_11 ] . V_19 == V_88 )
V_77 |= V_89 ;
}
V_90 = & V_85 ;
F_21 () ;
}
int F_25 ( void )
{
if ( F_26 ( & V_91 ) )
return - V_92 ;
return 0 ;
}
void F_27 ( void )
{
struct V_93 * V_94 , * V_95 , * V_96 ;
V_94 = ( & V_91 ) -> V_97 ;
V_95 = ( & V_91 ) -> V_98 ;
V_96 = & V_99 ;
F_28 () ;
V_95 -> V_97 = V_96 ;
F_29 ( F_30 ( V_96 -> V_98 ) , V_94 ) ;
V_94 -> V_98 = V_96 -> V_98 ;
V_96 -> V_98 = V_95 ;
F_31 ( & V_91 ) ;
if ( V_90 != V_96 ) {
V_75 = 0 ;
V_90 = V_96 ;
}
F_21 () ;
}
static int F_32 ( struct V_8 * V_9 ,
T_3 * args , int V_100 , int V_101 )
{
int V_10 ;
if ( V_9 -> V_13 [ V_100 ] . V_14 )
return - V_92 ;
V_9 -> V_13 [ V_100 ] . V_16 = F_33 ( args ) ;
if ( ! V_9 -> V_13 [ V_100 ] . V_16 )
return - V_102 ;
V_9 -> V_13 [ V_100 ] . type = V_101 ;
V_10 = F_7 ( V_9 -> V_13 [ V_100 ] . type ,
V_15 ,
V_9 -> V_13 [ V_100 ] . V_16 ,
& V_9 -> V_13 [ V_100 ] . V_14 ) ;
if ( ! V_9 -> V_13 [ V_100 ] . V_14 ) {
F_34 ( V_9 -> V_13 [ V_100 ] . V_16 ) ;
return - V_92 ;
}
return V_10 ;
}
static void F_35 ( struct V_103 * V_104 , char * V_105 , char * V_106 ,
bool (* F_36)( T_4 , T_4 ) )
{
if ( F_36 == & V_107 )
F_37 ( V_104 , L_5 , V_105 ) ;
else if ( F_36 == & V_108 )
F_37 ( V_104 , L_6 , V_105 ) ;
else
F_37 ( V_104 , L_7 , V_105 ) ;
F_38 ( V_104 , V_106 ) ;
F_37 ( V_104 , L_8 ) ;
}
static void F_39 ( struct V_103 * V_104 , char * V_105 , char * V_106 )
{
F_35 ( V_104 , V_105 , V_106 , NULL ) ;
}
static int F_40 ( char * V_14 , struct V_8 * V_9 )
{
struct V_103 * V_104 ;
char * V_109 ;
char * V_4 ;
bool V_110 ;
int V_10 = 0 ;
V_104 = F_41 ( NULL , V_111 , V_112 ) ;
V_9 -> V_39 = V_113 ;
V_9 -> V_47 = V_113 ;
V_9 -> V_38 = & V_114 ;
V_9 -> V_45 = & V_114 ;
V_9 -> V_69 = V_115 ;
while ( ( V_4 = F_3 ( & V_14 , L_9 ) ) != NULL ) {
T_3 args [ V_116 ] ;
int V_117 ;
unsigned long V_118 ;
if ( V_10 < 0 )
break;
if ( ( * V_4 == '\0' ) || ( * V_4 == ' ' ) || ( * V_4 == '\t' ) )
continue;
V_117 = F_42 ( V_4 , V_119 , args ) ;
switch ( V_117 ) {
case V_120 :
F_39 ( V_104 , L_10 , L_11 ) ;
if ( V_9 -> V_69 != V_115 )
V_10 = - V_92 ;
V_9 -> V_69 = V_121 ;
break;
case V_122 :
F_39 ( V_104 , L_10 , L_12 ) ;
if ( V_9 -> V_69 != V_115 )
V_10 = - V_92 ;
V_9 -> V_69 = V_123 ;
break;
case V_124 :
F_39 ( V_104 , L_10 , L_13 ) ;
if ( V_9 -> V_69 != V_115 )
V_10 = - V_92 ;
V_9 -> V_69 = V_125 ;
break;
case V_126 :
F_39 ( V_104 , L_10 , L_14 ) ;
if ( V_9 -> V_69 != V_115 )
V_10 = - V_92 ;
V_9 -> V_69 = V_127 ;
break;
case V_128 :
F_39 ( V_104 , L_10 , L_15 ) ;
if ( V_9 -> V_69 != V_115 )
V_10 = - V_92 ;
V_9 -> V_69 = V_129 ;
break;
case V_130 :
F_39 ( V_104 , L_16 , args [ 0 ] . V_109 ) ;
if ( V_9 -> V_19 )
V_10 = - V_92 ;
if ( strcmp ( args [ 0 ] . V_109 , L_17 ) == 0 )
V_9 -> V_19 = V_64 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_18 ) == 0 )
V_9 -> V_19 = V_64 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_19 ) == 0 )
V_9 -> V_19 = V_65 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_20 ) == 0 )
V_9 -> V_19 = V_131 ;
else if ( ( strcmp ( args [ 0 ] . V_109 , L_21 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_109 , L_22 ) == 0 ) )
V_9 -> V_19 = V_60 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_23 ) == 0 )
V_9 -> V_19 = V_62 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_24 ) ==
0 )
V_9 -> V_19 = V_132 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_25 )
== 0 )
V_9 -> V_19 = V_133 ;
else if ( strcmp ( args [ 0 ] . V_109 , L_26 ) == 0 )
V_9 -> V_19 = V_88 ;
else
V_10 = - V_92 ;
if ( ! V_10 )
V_9 -> V_25 |= V_26 ;
break;
case V_134 :
F_39 ( V_104 , L_27 , args [ 0 ] . V_109 ) ;
if ( V_9 -> V_20 )
V_10 = - V_92 ;
V_109 = args [ 0 ] . V_109 ;
if ( * V_109 == '^' )
V_109 ++ ;
if ( ( strcmp ( V_109 , L_28 ) ) == 0 )
V_9 -> V_20 = V_135 ;
else if ( strcmp ( V_109 , L_29 ) == 0 )
V_9 -> V_20 = V_136 ;
else if ( strcmp ( V_109 , L_30 ) == 0 )
V_9 -> V_20 = V_137 ;
else if ( strcmp ( V_109 , L_31 ) == 0 )
V_9 -> V_20 = V_138 ;
else
V_10 = - V_92 ;
if ( ! V_10 )
V_9 -> V_25 |= ( * args [ 0 ] . V_109 == '^' )
? V_29 : V_28 ;
break;
case V_139 :
F_39 ( V_104 , L_32 , args [ 0 ] . V_109 ) ;
if ( V_9 -> V_31 ) {
V_10 = - V_92 ;
break;
}
V_10 = F_43 ( args [ 0 ] . V_109 , 16 , & V_9 -> V_31 ) ;
if ( ! V_10 )
V_9 -> V_25 |= V_30 ;
break;
case V_140 :
F_39 ( V_104 , L_33 , args [ 0 ] . V_109 ) ;
if ( F_44 ( & V_9 -> V_35 ) ) {
V_10 = - V_92 ;
break;
}
V_10 = F_45 ( args [ 0 ] . V_109 , & V_9 -> V_35 ) ;
if ( ! V_10 )
V_9 -> V_25 |= V_34 ;
break;
case V_141 :
case V_142 :
V_9 -> V_38 = & V_107 ;
case V_143 :
case V_144 :
if ( ( V_117 == V_143 ) || ( V_117 == V_144 ) )
V_9 -> V_38 = & V_108 ;
case V_145 :
case V_146 :
V_110 = ( V_117 == V_145 ) ||
( V_117 == V_141 ) ||
( V_117 == V_143 ) ;
F_35 ( V_104 , V_110 ? L_34 : L_35 ,
args [ 0 ] . V_109 , V_9 -> V_38 ) ;
if ( F_46 ( V_9 -> V_39 ) ) {
V_10 = - V_92 ;
break;
}
V_10 = F_43 ( args [ 0 ] . V_109 , 10 , & V_118 ) ;
if ( ! V_10 ) {
V_9 -> V_39 = F_47 ( F_48 () ,
( V_147 ) V_118 ) ;
if ( ! F_46 ( V_9 -> V_39 ) ||
( V_147 ) V_118 != V_118 )
V_10 = - V_92 ;
else
V_9 -> V_25 |= V_110
? V_37 : V_40 ;
}
break;
case V_148 :
V_9 -> V_45 = & V_107 ;
case V_149 :
if ( V_117 == V_149 )
V_9 -> V_45 = & V_108 ;
case V_150 :
F_35 ( V_104 , L_36 , args [ 0 ] . V_109 ,
V_9 -> V_45 ) ;
if ( F_46 ( V_9 -> V_47 ) ) {
V_10 = - V_92 ;
break;
}
V_10 = F_43 ( args [ 0 ] . V_109 , 10 , & V_118 ) ;
if ( ! V_10 ) {
V_9 -> V_47 = F_47 ( F_48 () , ( V_147 ) V_118 ) ;
if ( ! F_46 ( V_9 -> V_47 ) || ( ( ( V_147 ) V_118 ) != V_118 ) )
V_10 = - V_92 ;
else
V_9 -> V_25 |= V_44 ;
}
break;
case V_151 :
F_39 ( V_104 , L_37 , args [ 0 ] . V_109 ) ;
V_10 = F_32 ( V_9 , args ,
V_53 ,
V_152 ) ;
break;
case V_153 :
F_39 ( V_104 , L_38 , args [ 0 ] . V_109 ) ;
V_10 = F_32 ( V_9 , args ,
V_54 ,
V_154 ) ;
break;
case V_155 :
F_39 ( V_104 , L_39 , args [ 0 ] . V_109 ) ;
V_10 = F_32 ( V_9 , args ,
V_55 ,
V_156 ) ;
break;
case V_157 :
F_39 ( V_104 , L_40 , args [ 0 ] . V_109 ) ;
V_10 = F_32 ( V_9 , args ,
V_56 ,
V_158 ) ;
break;
case V_159 :
F_39 ( V_104 , L_41 , args [ 0 ] . V_109 ) ;
V_10 = F_32 ( V_9 , args ,
V_57 ,
V_160 ) ;
break;
case V_161 :
F_39 ( V_104 , L_42 , args [ 0 ] . V_109 ) ;
V_10 = F_32 ( V_9 , args ,
V_58 ,
V_162 ) ;
break;
case V_163 :
if ( V_9 -> V_69 != V_125 ) {
V_10 = - V_92 ;
break;
}
F_39 ( V_104 , L_43 , args [ 0 ] . V_109 ) ;
if ( ( strcmp ( args [ 0 ] . V_109 , L_44 ) ) == 0 )
V_9 -> V_25 |= V_164 ;
else
V_10 = - V_92 ;
break;
case V_165 :
V_9 -> V_25 |= V_166 ;
break;
case V_167 :
if ( V_9 -> V_69 != V_121 ) {
V_10 = - V_92 ;
break;
}
F_39 ( V_104 , L_45 , args [ 0 ] . V_109 ) ;
V_10 = F_49 ( args [ 0 ] . V_109 , 10 , & V_9 -> V_68 ) ;
if ( V_10 || F_50 ( V_9 -> V_68 ) )
V_10 = - V_92 ;
else
V_9 -> V_25 |= V_74 ;
break;
case V_168 :
F_39 ( V_104 , L_46 , V_4 ) ;
V_10 = - V_92 ;
break;
}
}
if ( ! V_10 && ( V_9 -> V_69 == V_115 ) )
V_10 = - V_92 ;
else if ( V_9 -> V_19 == V_65 )
V_77 |= V_169 ;
else if ( V_9 -> V_19 == V_131 )
V_77 |= V_170 ;
else if ( V_9 -> V_19 == V_88 )
V_77 |= V_89 ;
F_37 ( V_104 , L_47 , ! V_10 ) ;
F_51 ( V_104 ) ;
return V_10 ;
}
T_5 F_52 ( char * V_14 )
{
static const char V_171 [] = L_48 ;
char * V_4 ;
struct V_8 * V_9 ;
T_5 V_10 , V_172 ;
int V_173 = 0 ;
V_4 = F_3 ( & V_14 , L_49 ) ;
V_172 = strlen ( V_4 ) + 1 ;
V_4 += strspn ( V_4 , L_9 ) ;
if ( * V_4 == '#' || * V_4 == '\0' )
return V_172 ;
V_9 = F_53 ( sizeof( * V_9 ) , V_111 ) ;
if ( ! V_9 ) {
F_54 ( V_174 , NULL ,
NULL , V_171 , L_50 , - V_102 , V_173 ) ;
return - V_102 ;
}
F_31 ( & V_9 -> V_84 ) ;
V_10 = F_40 ( V_4 , V_9 ) ;
if ( V_10 ) {
F_34 ( V_9 ) ;
F_54 ( V_174 , NULL ,
NULL , V_171 , L_51 , V_10 ,
V_173 ) ;
return V_10 ;
}
F_24 ( & V_9 -> V_84 , & V_91 ) ;
return V_172 ;
}
void F_55 ( void )
{
struct V_8 * V_9 , * V_175 ;
int V_11 ;
V_77 = 0 ;
F_56 (entry, tmp, &ima_temp_rules, list) {
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ )
F_34 ( V_9 -> V_13 [ V_11 ] . V_16 ) ;
F_57 ( & V_9 -> V_84 ) ;
F_34 ( V_9 ) ;
}
}
void * F_58 ( struct V_176 * V_177 , T_6 * V_178 )
{
T_6 V_179 = * V_178 ;
struct V_8 * V_9 ;
F_18 () ;
F_19 (entry, ima_rules, list) {
if ( ! V_179 -- ) {
F_20 () ;
return V_9 ;
}
}
F_20 () ;
return NULL ;
}
void * F_59 ( struct V_176 * V_177 , void * V_180 , T_6 * V_178 )
{
struct V_8 * V_9 = V_180 ;
F_18 () ;
V_9 = F_60 ( V_9 -> V_84 . V_97 , struct V_8 , V_84 ) ;
F_20 () ;
( * V_178 ) ++ ;
return ( & V_9 -> V_84 == V_90 ) ? NULL : V_9 ;
}
void F_61 ( struct V_176 * V_177 , void * V_180 )
{
}
static void F_62 ( struct V_176 * V_177 , enum V_18 V_19 )
{
if ( V_19 > 0 && V_19 < V_66 )
F_63 ( V_177 , L_52 , V_181 [ V_19 ] ) ;
else
F_63 ( V_177 , L_53 , V_19 ) ;
}
int F_64 ( struct V_176 * V_177 , void * V_180 )
{
struct V_8 * V_9 = V_180 ;
int V_11 ;
char V_182 [ 64 ] = { 0 ,} ;
F_18 () ;
if ( V_9 -> V_69 & V_121 )
F_65 ( V_177 , F_66 ( V_120 ) ) ;
if ( V_9 -> V_69 & V_123 )
F_65 ( V_177 , F_66 ( V_122 ) ) ;
if ( V_9 -> V_69 & V_125 )
F_65 ( V_177 , F_66 ( V_124 ) ) ;
if ( V_9 -> V_69 & V_127 )
F_65 ( V_177 , F_66 ( V_126 ) ) ;
if ( V_9 -> V_69 & V_129 )
F_65 ( V_177 , F_66 ( V_128 ) ) ;
F_65 ( V_177 , L_8 ) ;
if ( V_9 -> V_25 & V_26 )
F_62 ( V_177 , V_9 -> V_19 ) ;
if ( V_9 -> V_25 & V_28 ) {
if ( V_9 -> V_20 & V_135 )
F_63 ( V_177 , F_66 ( V_134 ) , F_67 ( V_183 ) ) ;
if ( V_9 -> V_20 & V_136 )
F_63 ( V_177 , F_66 ( V_134 ) , F_67 ( V_184 ) ) ;
if ( V_9 -> V_20 & V_137 )
F_63 ( V_177 , F_66 ( V_134 ) , F_67 ( V_185 ) ) ;
if ( V_9 -> V_20 & V_138 )
F_63 ( V_177 , F_66 ( V_134 ) , F_67 ( V_186 ) ) ;
F_65 ( V_177 , L_8 ) ;
}
if ( V_9 -> V_25 & V_30 ) {
snprintf ( V_182 , sizeof( V_182 ) , L_54 , V_9 -> V_31 ) ;
F_63 ( V_177 , F_66 ( V_139 ) , V_182 ) ;
F_65 ( V_177 , L_8 ) ;
}
if ( V_9 -> V_25 & V_74 ) {
snprintf ( V_182 , sizeof( V_182 ) , L_55 , V_9 -> V_68 ) ;
F_63 ( V_177 , F_66 ( V_167 ) , V_182 ) ;
F_65 ( V_177 , L_8 ) ;
}
if ( V_9 -> V_25 & V_34 ) {
F_63 ( V_177 , L_56 , & V_9 -> V_35 ) ;
F_65 ( V_177 , L_8 ) ;
}
if ( V_9 -> V_25 & V_37 ) {
snprintf ( V_182 , sizeof( V_182 ) , L_55 , F_68 ( V_9 -> V_39 ) ) ;
if ( V_9 -> V_38 == & V_107 )
F_63 ( V_177 , F_66 ( V_141 ) , V_182 ) ;
else if ( V_9 -> V_38 == & V_108 )
F_63 ( V_177 , F_66 ( V_143 ) , V_182 ) ;
else
F_63 ( V_177 , F_66 ( V_145 ) , V_182 ) ;
F_65 ( V_177 , L_8 ) ;
}
if ( V_9 -> V_25 & V_40 ) {
snprintf ( V_182 , sizeof( V_182 ) , L_55 , F_68 ( V_9 -> V_39 ) ) ;
if ( V_9 -> V_38 == & V_107 )
F_63 ( V_177 , F_66 ( V_142 ) , V_182 ) ;
else if ( V_9 -> V_38 == & V_108 )
F_63 ( V_177 , F_66 ( V_144 ) , V_182 ) ;
else
F_63 ( V_177 , F_66 ( V_146 ) , V_182 ) ;
F_65 ( V_177 , L_8 ) ;
}
if ( V_9 -> V_25 & V_44 ) {
snprintf ( V_182 , sizeof( V_182 ) , L_55 , F_68 ( V_9 -> V_47 ) ) ;
if ( V_9 -> V_45 == & V_107 )
F_63 ( V_177 , F_66 ( V_148 ) , V_182 ) ;
else if ( V_9 -> V_45 == & V_108 )
F_63 ( V_177 , F_66 ( V_149 ) , V_182 ) ;
else
F_63 ( V_177 , F_66 ( V_150 ) , V_182 ) ;
F_65 ( V_177 , L_8 ) ;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( V_9 -> V_13 [ V_11 ] . V_14 ) {
switch ( V_11 ) {
case V_53 :
F_63 ( V_177 , F_66 ( V_151 ) ,
( char * ) V_9 -> V_13 [ V_11 ] . V_16 ) ;
break;
case V_54 :
F_63 ( V_177 , F_66 ( V_153 ) ,
( char * ) V_9 -> V_13 [ V_11 ] . V_16 ) ;
break;
case V_55 :
F_63 ( V_177 , F_66 ( V_155 ) ,
( char * ) V_9 -> V_13 [ V_11 ] . V_16 ) ;
break;
case V_56 :
F_63 ( V_177 , F_66 ( V_157 ) ,
( char * ) V_9 -> V_13 [ V_11 ] . V_16 ) ;
break;
case V_57 :
F_63 ( V_177 , F_66 ( V_159 ) ,
( char * ) V_9 -> V_13 [ V_11 ] . V_16 ) ;
break;
case V_58 :
F_63 ( V_177 , F_66 ( V_161 ) ,
( char * ) V_9 -> V_13 [ V_11 ] . V_16 ) ;
break;
}
}
}
if ( V_9 -> V_25 & V_164 )
F_65 ( V_177 , L_57 ) ;
if ( V_9 -> V_25 & V_166 )
F_65 ( V_177 , L_58 ) ;
F_20 () ;
F_65 ( V_177 , L_49 ) ;
return 0 ;
}
