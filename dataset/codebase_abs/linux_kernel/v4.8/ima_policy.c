static int T_1 F_1 ( char * V_1 )
{
if ( V_2 )
return 1 ;
V_2 = V_3 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
if ( V_2 )
return 1 ;
if ( strcmp ( V_1 , L_1 ) == 0 )
V_2 = V_4 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_5 = 1 ;
return 1 ;
}
static void F_4 ( void )
{
struct V_6 * V_7 ;
int V_8 ;
int V_9 ;
F_5 (entry, &ima_policy_rules, list) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! V_7 -> V_11 [ V_9 ] . V_12 )
continue;
V_8 = F_6 ( V_7 -> V_11 [ V_9 ] . type ,
V_13 ,
V_7 -> V_11 [ V_9 ] . V_14 ,
& V_7 -> V_11 [ V_9 ] . V_12 ) ;
F_7 ( ! V_7 -> V_11 [ V_9 ] . V_12 ) ;
}
}
}
static bool F_8 ( struct V_6 * V_12 , struct V_15 * V_15 ,
enum V_16 V_17 , int V_18 )
{
struct V_19 * V_20 = V_21 ;
const struct V_22 * V_22 = F_9 () ;
int V_9 ;
if ( ( V_12 -> V_23 & V_24 ) &&
( V_12 -> V_17 != V_17 && V_17 != V_25 ) )
return false ;
if ( ( V_12 -> V_23 & V_26 ) &&
( V_12 -> V_18 != V_18 && V_17 != V_25 ) )
return false ;
if ( ( V_12 -> V_23 & V_27 ) &&
( ! ( V_12 -> V_18 & V_18 ) && V_17 != V_25 ) )
return false ;
if ( ( V_12 -> V_23 & V_28 )
&& V_12 -> V_29 != V_15 -> V_30 -> V_31 )
return false ;
if ( ( V_12 -> V_23 & V_32 ) &&
memcmp ( V_12 -> V_33 , V_15 -> V_30 -> V_34 , sizeof( V_12 -> V_33 ) ) )
return false ;
if ( ( V_12 -> V_23 & V_35 ) && ! F_10 ( V_12 -> V_36 , V_22 -> V_36 ) )
return false ;
if ( V_12 -> V_23 & V_37 ) {
if ( F_11 ( V_21 , V_38 ) ) {
if ( ! F_10 ( V_12 -> V_36 , V_22 -> V_39 )
&& ! F_10 ( V_12 -> V_36 , V_22 -> V_40 )
&& ! F_10 ( V_12 -> V_36 , V_22 -> V_36 ) )
return false ;
} else if ( ! F_10 ( V_12 -> V_36 , V_22 -> V_39 ) )
return false ;
}
if ( ( V_12 -> V_23 & V_41 ) && ! F_10 ( V_12 -> V_42 , V_15 -> V_43 ) )
return false ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
int V_44 = 0 ;
T_2 V_45 , V_46 ;
int V_47 = 0 ;
if ( ! V_12 -> V_11 [ V_9 ] . V_12 )
continue;
V_48:
switch ( V_9 ) {
case V_49 :
case V_50 :
case V_51 :
F_12 ( V_15 , & V_45 ) ;
V_44 = F_13 ( V_45 ,
V_12 -> V_11 [ V_9 ] . type ,
V_13 ,
V_12 -> V_11 [ V_9 ] . V_12 ,
NULL ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_14 ( V_20 , & V_46 ) ;
V_44 = F_13 ( V_46 ,
V_12 -> V_11 [ V_9 ] . type ,
V_13 ,
V_12 -> V_11 [ V_9 ] . V_12 ,
NULL ) ;
default:
break;
}
if ( ( V_44 < 0 ) && ( ! V_47 ) ) {
V_47 = 1 ;
F_4 () ;
goto V_48;
}
if ( ! V_44 )
return false ;
}
return true ;
}
static int F_15 ( struct V_6 * V_12 , enum V_16 V_17 )
{
if ( ! ( V_12 -> V_23 & V_24 ) )
return V_55 ;
switch ( V_17 ) {
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
case V_25 :
return V_55 ;
case V_61 ... V_62 - 1 :
default:
return V_63 ;
}
}
int F_16 ( struct V_15 * V_15 , enum V_16 V_17 , int V_18 ,
int V_23 , int * V_64 )
{
struct V_6 * V_7 ;
int V_65 = 0 , V_66 = V_23 | ( V_23 << 1 ) ;
F_17 () ;
F_18 (entry, ima_rules, list) {
if ( ! ( V_7 -> V_65 & V_66 ) )
continue;
if ( ! F_8 ( V_7 , V_15 , V_17 , V_18 ) )
continue;
V_65 |= V_7 -> V_23 & V_67 ;
V_65 |= V_7 -> V_65 & V_68 ;
if ( V_7 -> V_65 & V_69 )
V_65 |= F_15 ( V_7 , V_17 ) ;
if ( V_7 -> V_65 & V_68 )
V_66 &= ~ ( V_7 -> V_65 | V_7 -> V_65 << 1 ) ;
else
V_66 &= ~ ( V_7 -> V_65 | V_7 -> V_65 >> 1 ) ;
if ( ( V_64 ) && ( V_7 -> V_23 & V_70 ) )
* V_64 = V_7 -> V_64 ;
if ( ! V_66 )
break;
}
F_19 () ;
return V_65 ;
}
void F_20 ( void )
{
struct V_6 * V_7 ;
F_5 (entry, ima_rules, list) {
if ( V_7 -> V_65 & V_68 )
V_71 |= V_7 -> V_65 ;
}
V_72 |= V_73 ;
if ( ! V_72 )
V_71 &= ~ V_69 ;
}
void T_1 F_21 ( void )
{
int V_9 , V_74 , V_75 ;
V_74 = V_2 ? F_22 ( V_76 ) : 0 ;
V_75 = V_5 ?
F_22 ( V_77 ) : 0 ;
for ( V_9 = 0 ; V_9 < V_74 ; V_9 ++ )
F_23 ( & V_76 [ V_9 ] . V_78 , & V_79 ) ;
switch ( V_2 ) {
case V_3 :
for ( V_9 = 0 ; V_9 < F_22 ( V_80 ) ; V_9 ++ )
F_23 ( & V_80 [ V_9 ] . V_78 ,
& V_79 ) ;
break;
case V_4 :
for ( V_9 = 0 ; V_9 < F_22 ( V_81 ) ; V_9 ++ )
F_23 ( & V_81 [ V_9 ] . V_78 ,
& V_79 ) ;
default:
break;
}
for ( V_9 = 0 ; V_9 < V_75 ; V_9 ++ ) {
F_23 ( & V_77 [ V_9 ] . V_78 ,
& V_79 ) ;
if ( V_77 [ V_9 ] . V_17 == V_82 )
V_73 |= V_83 ;
}
V_84 = & V_79 ;
F_20 () ;
}
int F_24 ( void )
{
if ( F_25 ( & V_85 ) )
return - V_86 ;
return 0 ;
}
void F_26 ( void )
{
struct V_87 * V_88 , * V_89 , * V_90 ;
V_88 = ( & V_85 ) -> V_91 ;
V_89 = ( & V_85 ) -> V_92 ;
V_90 = & V_93 ;
F_27 () ;
V_89 -> V_91 = V_90 ;
F_28 ( F_29 ( V_90 -> V_92 ) , V_88 ) ;
V_88 -> V_92 = V_90 -> V_92 ;
V_90 -> V_92 = V_89 ;
F_30 ( & V_85 ) ;
if ( V_84 != V_90 ) {
V_71 = 0 ;
V_84 = V_90 ;
}
F_20 () ;
}
static int F_31 ( struct V_6 * V_7 ,
T_3 * args , int V_94 , int V_95 )
{
int V_8 ;
if ( V_7 -> V_11 [ V_94 ] . V_12 )
return - V_86 ;
V_7 -> V_11 [ V_94 ] . V_14 = F_32 ( args ) ;
if ( ! V_7 -> V_11 [ V_94 ] . V_14 )
return - V_96 ;
V_7 -> V_11 [ V_94 ] . type = V_95 ;
V_8 = F_6 ( V_7 -> V_11 [ V_94 ] . type ,
V_13 ,
V_7 -> V_11 [ V_94 ] . V_14 ,
& V_7 -> V_11 [ V_94 ] . V_12 ) ;
if ( ! V_7 -> V_11 [ V_94 ] . V_12 ) {
F_33 ( V_7 -> V_11 [ V_94 ] . V_14 ) ;
return - V_86 ;
}
return V_8 ;
}
static void F_34 ( struct V_97 * V_98 , char * V_99 , char * V_100 )
{
F_35 ( V_98 , L_2 , V_99 ) ;
F_36 ( V_98 , V_100 ) ;
F_35 ( V_98 , L_3 ) ;
}
static int F_37 ( char * V_12 , struct V_6 * V_7 )
{
struct V_97 * V_98 ;
char * V_101 ;
char * V_102 ;
int V_8 = 0 ;
V_98 = F_38 ( NULL , V_103 , V_104 ) ;
V_7 -> V_36 = V_105 ;
V_7 -> V_42 = V_105 ;
V_7 -> V_65 = V_106 ;
while ( ( V_102 = F_39 ( & V_12 , L_4 ) ) != NULL ) {
T_3 args [ V_107 ] ;
int V_108 ;
unsigned long V_109 ;
if ( V_8 < 0 )
break;
if ( ( * V_102 == '\0' ) || ( * V_102 == ' ' ) || ( * V_102 == '\t' ) )
continue;
V_108 = F_40 ( V_102 , V_110 , args ) ;
switch ( V_108 ) {
case V_111 :
F_34 ( V_98 , L_5 , L_6 ) ;
if ( V_7 -> V_65 != V_106 )
V_8 = - V_86 ;
V_7 -> V_65 = V_112 ;
break;
case V_113 :
F_34 ( V_98 , L_5 , L_7 ) ;
if ( V_7 -> V_65 != V_106 )
V_8 = - V_86 ;
V_7 -> V_65 = V_114 ;
break;
case V_115 :
F_34 ( V_98 , L_5 , L_8 ) ;
if ( V_7 -> V_65 != V_106 )
V_8 = - V_86 ;
V_7 -> V_65 = V_116 ;
break;
case V_117 :
F_34 ( V_98 , L_5 , L_9 ) ;
if ( V_7 -> V_65 != V_106 )
V_8 = - V_86 ;
V_7 -> V_65 = V_118 ;
break;
case V_119 :
F_34 ( V_98 , L_5 , L_10 ) ;
if ( V_7 -> V_65 != V_106 )
V_8 = - V_86 ;
V_7 -> V_65 = V_120 ;
break;
case V_121 :
F_34 ( V_98 , L_11 , args [ 0 ] . V_101 ) ;
if ( V_7 -> V_17 )
V_8 = - V_86 ;
if ( strcmp ( args [ 0 ] . V_101 , L_12 ) == 0 )
V_7 -> V_17 = V_60 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_13 ) == 0 )
V_7 -> V_17 = V_60 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_14 ) == 0 )
V_7 -> V_17 = V_61 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_15 ) == 0 )
V_7 -> V_17 = V_122 ;
else if ( ( strcmp ( args [ 0 ] . V_101 , L_16 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_101 , L_17 ) == 0 ) )
V_7 -> V_17 = V_56 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_18 ) == 0 )
V_7 -> V_17 = V_58 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_19 ) ==
0 )
V_7 -> V_17 = V_123 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_20 )
== 0 )
V_7 -> V_17 = V_124 ;
else if ( strcmp ( args [ 0 ] . V_101 , L_21 ) == 0 )
V_7 -> V_17 = V_82 ;
else
V_8 = - V_86 ;
if ( ! V_8 )
V_7 -> V_23 |= V_24 ;
break;
case V_125 :
F_34 ( V_98 , L_22 , args [ 0 ] . V_101 ) ;
if ( V_7 -> V_18 )
V_8 = - V_86 ;
V_101 = args [ 0 ] . V_101 ;
if ( * V_101 == '^' )
V_101 ++ ;
if ( ( strcmp ( V_101 , L_23 ) ) == 0 )
V_7 -> V_18 = V_126 ;
else if ( strcmp ( V_101 , L_24 ) == 0 )
V_7 -> V_18 = V_127 ;
else if ( strcmp ( V_101 , L_25 ) == 0 )
V_7 -> V_18 = V_128 ;
else if ( strcmp ( V_101 , L_26 ) == 0 )
V_7 -> V_18 = V_129 ;
else
V_8 = - V_86 ;
if ( ! V_8 )
V_7 -> V_23 |= ( * args [ 0 ] . V_101 == '^' )
? V_27 : V_26 ;
break;
case V_130 :
F_34 ( V_98 , L_27 , args [ 0 ] . V_101 ) ;
if ( V_7 -> V_29 ) {
V_8 = - V_86 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_101 , 16 , & V_7 -> V_29 ) ;
if ( ! V_8 )
V_7 -> V_23 |= V_28 ;
break;
case V_131 :
F_34 ( V_98 , L_28 , args [ 0 ] . V_101 ) ;
if ( F_42 ( V_7 -> V_33 , 0x00 ,
sizeof( V_7 -> V_33 ) ) ) {
V_8 = - V_86 ;
break;
}
V_8 = F_43 ( args [ 0 ] . V_101 ,
V_7 -> V_33 ) ;
if ( ! V_8 )
V_7 -> V_23 |= V_32 ;
break;
case V_132 :
F_34 ( V_98 , L_29 , args [ 0 ] . V_101 ) ;
case V_133 :
if ( V_108 == V_133 )
F_34 ( V_98 , L_30 , args [ 0 ] . V_101 ) ;
if ( F_44 ( V_7 -> V_36 ) ) {
V_8 = - V_86 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_101 , 10 , & V_109 ) ;
if ( ! V_8 ) {
V_7 -> V_36 = F_45 ( F_46 () ,
( V_134 ) V_109 ) ;
if ( ! F_44 ( V_7 -> V_36 ) ||
( V_134 ) V_109 != V_109 )
V_8 = - V_86 ;
else
V_7 -> V_23 |= ( V_108 == V_132 )
? V_35 : V_37 ;
}
break;
case V_135 :
F_34 ( V_98 , L_31 , args [ 0 ] . V_101 ) ;
if ( F_44 ( V_7 -> V_42 ) ) {
V_8 = - V_86 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_101 , 10 , & V_109 ) ;
if ( ! V_8 ) {
V_7 -> V_42 = F_45 ( F_46 () , ( V_134 ) V_109 ) ;
if ( ! F_44 ( V_7 -> V_42 ) || ( ( ( V_134 ) V_109 ) != V_109 ) )
V_8 = - V_86 ;
else
V_7 -> V_23 |= V_41 ;
}
break;
case V_136 :
F_34 ( V_98 , L_32 , args [ 0 ] . V_101 ) ;
V_8 = F_31 ( V_7 , args ,
V_49 ,
V_137 ) ;
break;
case V_138 :
F_34 ( V_98 , L_33 , args [ 0 ] . V_101 ) ;
V_8 = F_31 ( V_7 , args ,
V_50 ,
V_139 ) ;
break;
case V_140 :
F_34 ( V_98 , L_34 , args [ 0 ] . V_101 ) ;
V_8 = F_31 ( V_7 , args ,
V_51 ,
V_141 ) ;
break;
case V_142 :
F_34 ( V_98 , L_35 , args [ 0 ] . V_101 ) ;
V_8 = F_31 ( V_7 , args ,
V_52 ,
V_143 ) ;
break;
case V_144 :
F_34 ( V_98 , L_36 , args [ 0 ] . V_101 ) ;
V_8 = F_31 ( V_7 , args ,
V_53 ,
V_145 ) ;
break;
case V_146 :
F_34 ( V_98 , L_37 , args [ 0 ] . V_101 ) ;
V_8 = F_31 ( V_7 , args ,
V_54 ,
V_147 ) ;
break;
case V_148 :
if ( V_7 -> V_65 != V_116 ) {
V_8 = - V_86 ;
break;
}
F_34 ( V_98 , L_38 , args [ 0 ] . V_101 ) ;
if ( ( strcmp ( args [ 0 ] . V_101 , L_39 ) ) == 0 )
V_7 -> V_23 |= V_149 ;
else
V_8 = - V_86 ;
break;
case V_150 :
V_7 -> V_23 |= V_151 ;
break;
case V_152 :
if ( V_7 -> V_65 != V_112 ) {
V_8 = - V_86 ;
break;
}
F_34 ( V_98 , L_40 , args [ 0 ] . V_101 ) ;
V_8 = F_47 ( args [ 0 ] . V_101 , 10 , & V_7 -> V_64 ) ;
if ( V_8 || F_48 ( V_7 -> V_64 ) )
V_8 = - V_86 ;
else
V_7 -> V_23 |= V_70 ;
break;
case V_153 :
F_34 ( V_98 , L_41 , V_102 ) ;
V_8 = - V_86 ;
break;
}
}
if ( ! V_8 && ( V_7 -> V_65 == V_106 ) )
V_8 = - V_86 ;
else if ( V_7 -> V_17 == V_61 )
V_73 |= V_154 ;
else if ( V_7 -> V_17 == V_122 )
V_73 |= V_155 ;
else if ( V_7 -> V_17 == V_82 )
V_73 |= V_83 ;
F_35 ( V_98 , L_42 , ! V_8 ) ;
F_49 ( V_98 ) ;
return V_8 ;
}
T_4 F_50 ( char * V_12 )
{
static const char V_156 [] = L_43 ;
char * V_102 ;
struct V_6 * V_7 ;
T_4 V_8 , V_157 ;
int V_158 = 0 ;
V_102 = F_39 ( & V_12 , L_44 ) ;
V_157 = strlen ( V_102 ) + 1 ;
V_102 += strspn ( V_102 , L_4 ) ;
if ( * V_102 == '#' || * V_102 == '\0' )
return V_157 ;
V_7 = F_51 ( sizeof( * V_7 ) , V_103 ) ;
if ( ! V_7 ) {
F_52 ( V_159 , NULL ,
NULL , V_156 , L_45 , - V_96 , V_158 ) ;
return - V_96 ;
}
F_30 ( & V_7 -> V_78 ) ;
V_8 = F_37 ( V_102 , V_7 ) ;
if ( V_8 ) {
F_33 ( V_7 ) ;
F_52 ( V_159 , NULL ,
NULL , V_156 , L_46 , V_8 ,
V_158 ) ;
return V_8 ;
}
F_23 ( & V_7 -> V_78 , & V_85 ) ;
return V_157 ;
}
void F_53 ( void )
{
struct V_6 * V_7 , * V_160 ;
int V_9 ;
V_73 = 0 ;
F_54 (entry, tmp, &ima_temp_rules, list) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_33 ( V_7 -> V_11 [ V_9 ] . V_14 ) ;
F_55 ( & V_7 -> V_78 ) ;
F_33 ( V_7 ) ;
}
}
void * F_56 ( struct V_161 * V_162 , T_5 * V_163 )
{
T_5 V_164 = * V_163 ;
struct V_6 * V_7 ;
F_17 () ;
F_18 (entry, ima_rules, list) {
if ( ! V_164 -- ) {
F_19 () ;
return V_7 ;
}
}
F_19 () ;
return NULL ;
}
void * F_57 ( struct V_161 * V_162 , void * V_165 , T_5 * V_163 )
{
struct V_6 * V_7 = V_165 ;
F_17 () ;
V_7 = F_58 ( V_7 -> V_78 . V_91 , struct V_6 , V_78 ) ;
F_19 () ;
( * V_163 ) ++ ;
return ( & V_7 -> V_78 == V_84 ) ? NULL : V_7 ;
}
void F_59 ( struct V_161 * V_162 , void * V_165 )
{
}
static void F_60 ( struct V_161 * V_162 , enum V_16 V_17 )
{
char V_166 [ 64 ] = { 0 ,} ;
switch ( V_17 ) {
case V_60 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_167 ) ) ;
break;
case V_56 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_168 ) ) ;
break;
case V_58 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_169 ) ) ;
break;
case V_61 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_170 ) ) ;
break;
case V_122 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_171 ) ) ;
break;
case V_25 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_172 ) ) ;
break;
case V_123 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_173 ) ) ;
break;
case V_124 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_174 ) ) ;
break;
case V_82 :
F_61 ( V_162 , F_62 ( V_121 ) , F_63 ( V_175 ) ) ;
break;
default:
snprintf ( V_166 , sizeof( V_166 ) , L_47 , V_17 ) ;
F_61 ( V_162 , F_62 ( V_121 ) , V_166 ) ;
break;
}
F_64 ( V_162 , L_3 ) ;
}
int F_65 ( struct V_161 * V_162 , void * V_165 )
{
struct V_6 * V_7 = V_165 ;
int V_9 ;
char V_166 [ 64 ] = { 0 ,} ;
F_17 () ;
if ( V_7 -> V_65 & V_112 )
F_64 ( V_162 , F_62 ( V_111 ) ) ;
if ( V_7 -> V_65 & V_114 )
F_64 ( V_162 , F_62 ( V_113 ) ) ;
if ( V_7 -> V_65 & V_116 )
F_64 ( V_162 , F_62 ( V_115 ) ) ;
if ( V_7 -> V_65 & V_118 )
F_64 ( V_162 , F_62 ( V_117 ) ) ;
if ( V_7 -> V_65 & V_120 )
F_64 ( V_162 , F_62 ( V_119 ) ) ;
F_64 ( V_162 , L_3 ) ;
if ( V_7 -> V_23 & V_24 )
F_60 ( V_162 , V_7 -> V_17 ) ;
if ( V_7 -> V_23 & V_26 ) {
if ( V_7 -> V_18 & V_126 )
F_61 ( V_162 , F_62 ( V_125 ) , F_66 ( V_176 ) ) ;
if ( V_7 -> V_18 & V_127 )
F_61 ( V_162 , F_62 ( V_125 ) , F_66 ( V_177 ) ) ;
if ( V_7 -> V_18 & V_128 )
F_61 ( V_162 , F_62 ( V_125 ) , F_66 ( V_178 ) ) ;
if ( V_7 -> V_18 & V_129 )
F_61 ( V_162 , F_62 ( V_125 ) , F_66 ( V_179 ) ) ;
F_64 ( V_162 , L_3 ) ;
}
if ( V_7 -> V_23 & V_28 ) {
snprintf ( V_166 , sizeof( V_166 ) , L_48 , V_7 -> V_29 ) ;
F_61 ( V_162 , F_62 ( V_130 ) , V_166 ) ;
F_64 ( V_162 , L_3 ) ;
}
if ( V_7 -> V_23 & V_70 ) {
snprintf ( V_166 , sizeof( V_166 ) , L_47 , V_7 -> V_64 ) ;
F_61 ( V_162 , F_62 ( V_152 ) , V_166 ) ;
F_64 ( V_162 , L_3 ) ;
}
if ( V_7 -> V_23 & V_32 ) {
F_61 ( V_162 , L_49 , V_7 -> V_33 ) ;
F_64 ( V_162 , L_3 ) ;
}
if ( V_7 -> V_23 & V_35 ) {
snprintf ( V_166 , sizeof( V_166 ) , L_47 , F_67 ( V_7 -> V_36 ) ) ;
F_61 ( V_162 , F_62 ( V_132 ) , V_166 ) ;
F_64 ( V_162 , L_3 ) ;
}
if ( V_7 -> V_23 & V_37 ) {
snprintf ( V_166 , sizeof( V_166 ) , L_47 , F_67 ( V_7 -> V_36 ) ) ;
F_61 ( V_162 , F_62 ( V_133 ) , V_166 ) ;
F_64 ( V_162 , L_3 ) ;
}
if ( V_7 -> V_23 & V_41 ) {
snprintf ( V_166 , sizeof( V_166 ) , L_47 , F_67 ( V_7 -> V_42 ) ) ;
F_61 ( V_162 , F_62 ( V_135 ) , V_166 ) ;
F_64 ( V_162 , L_3 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_7 -> V_11 [ V_9 ] . V_12 ) {
switch ( V_9 ) {
case V_49 :
F_61 ( V_162 , F_62 ( V_136 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_50 :
F_61 ( V_162 , F_62 ( V_138 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_51 :
F_61 ( V_162 , F_62 ( V_140 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_52 :
F_61 ( V_162 , F_62 ( V_142 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_53 :
F_61 ( V_162 , F_62 ( V_144 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_54 :
F_61 ( V_162 , F_62 ( V_146 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
}
}
}
if ( V_7 -> V_23 & V_149 )
F_64 ( V_162 , L_50 ) ;
if ( V_7 -> V_23 & V_151 )
F_64 ( V_162 , L_51 ) ;
F_19 () ;
F_64 ( V_162 , L_44 ) ;
return 0 ;
}
