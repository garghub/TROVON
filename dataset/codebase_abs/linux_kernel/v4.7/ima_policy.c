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
int V_23 )
{
struct V_6 * V_7 ;
int V_64 = 0 , V_65 = V_23 | ( V_23 << 1 ) ;
F_17 () ;
F_18 (entry, ima_rules, list) {
if ( ! ( V_7 -> V_64 & V_65 ) )
continue;
if ( ! F_8 ( V_7 , V_15 , V_17 , V_18 ) )
continue;
V_64 |= V_7 -> V_23 & V_66 ;
V_64 |= V_7 -> V_64 & V_67 ;
if ( V_7 -> V_64 & V_68 )
V_64 |= F_15 ( V_7 , V_17 ) ;
if ( V_7 -> V_64 & V_67 )
V_65 &= ~ ( V_7 -> V_64 | V_7 -> V_64 << 1 ) ;
else
V_65 &= ~ ( V_7 -> V_64 | V_7 -> V_64 >> 1 ) ;
if ( ! V_65 )
break;
}
F_19 () ;
return V_64 ;
}
void F_20 ( void )
{
struct V_6 * V_7 ;
F_5 (entry, ima_rules, list) {
if ( V_7 -> V_64 & V_67 )
V_69 |= V_7 -> V_64 ;
}
V_70 |= V_71 ;
if ( ! V_70 )
V_69 &= ~ V_68 ;
}
void T_1 F_21 ( void )
{
int V_9 , V_72 , V_73 ;
V_72 = V_2 ? F_22 ( V_74 ) : 0 ;
V_73 = V_5 ?
F_22 ( V_75 ) : 0 ;
for ( V_9 = 0 ; V_9 < V_72 ; V_9 ++ )
F_23 ( & V_74 [ V_9 ] . V_76 , & V_77 ) ;
switch ( V_2 ) {
case V_3 :
for ( V_9 = 0 ; V_9 < F_22 ( V_78 ) ; V_9 ++ )
F_23 ( & V_78 [ V_9 ] . V_76 ,
& V_77 ) ;
break;
case V_4 :
for ( V_9 = 0 ; V_9 < F_22 ( V_79 ) ; V_9 ++ )
F_23 ( & V_79 [ V_9 ] . V_76 ,
& V_77 ) ;
default:
break;
}
for ( V_9 = 0 ; V_9 < V_73 ; V_9 ++ ) {
F_23 ( & V_75 [ V_9 ] . V_76 ,
& V_77 ) ;
if ( V_75 [ V_9 ] . V_17 == V_80 )
V_71 |= V_81 ;
}
V_82 = & V_77 ;
F_20 () ;
}
int F_24 ( void )
{
if ( F_25 ( & V_83 ) )
return - V_84 ;
return 0 ;
}
void F_26 ( void )
{
struct V_85 * V_86 , * V_87 , * V_88 ;
V_86 = ( & V_83 ) -> V_89 ;
V_87 = ( & V_83 ) -> V_90 ;
V_88 = & V_91 ;
F_27 () ;
V_87 -> V_89 = V_88 ;
F_28 ( F_29 ( V_88 -> V_90 ) , V_86 ) ;
V_86 -> V_90 = V_88 -> V_90 ;
V_88 -> V_90 = V_87 ;
F_30 ( & V_83 ) ;
if ( V_82 != V_88 ) {
V_69 = 0 ;
V_82 = V_88 ;
}
F_20 () ;
}
static int F_31 ( struct V_6 * V_7 ,
T_3 * args , int V_92 , int V_93 )
{
int V_8 ;
if ( V_7 -> V_11 [ V_92 ] . V_12 )
return - V_84 ;
V_7 -> V_11 [ V_92 ] . V_14 = F_32 ( args ) ;
if ( ! V_7 -> V_11 [ V_92 ] . V_14 )
return - V_94 ;
V_7 -> V_11 [ V_92 ] . type = V_93 ;
V_8 = F_6 ( V_7 -> V_11 [ V_92 ] . type ,
V_13 ,
V_7 -> V_11 [ V_92 ] . V_14 ,
& V_7 -> V_11 [ V_92 ] . V_12 ) ;
if ( ! V_7 -> V_11 [ V_92 ] . V_12 ) {
F_33 ( V_7 -> V_11 [ V_92 ] . V_14 ) ;
return - V_84 ;
}
return V_8 ;
}
static void F_34 ( struct V_95 * V_96 , char * V_97 , char * V_98 )
{
F_35 ( V_96 , L_2 , V_97 ) ;
F_36 ( V_96 , V_98 ) ;
F_35 ( V_96 , L_3 ) ;
}
static int F_37 ( char * V_12 , struct V_6 * V_7 )
{
struct V_95 * V_96 ;
char * V_99 ;
char * V_100 ;
int V_8 = 0 ;
V_96 = F_38 ( NULL , V_101 , V_102 ) ;
V_7 -> V_36 = V_103 ;
V_7 -> V_42 = V_103 ;
V_7 -> V_64 = V_104 ;
while ( ( V_100 = F_39 ( & V_12 , L_4 ) ) != NULL ) {
T_3 args [ V_105 ] ;
int V_106 ;
unsigned long V_107 ;
if ( V_8 < 0 )
break;
if ( ( * V_100 == '\0' ) || ( * V_100 == ' ' ) || ( * V_100 == '\t' ) )
continue;
V_106 = F_40 ( V_100 , V_108 , args ) ;
switch ( V_106 ) {
case V_109 :
F_34 ( V_96 , L_5 , L_6 ) ;
if ( V_7 -> V_64 != V_104 )
V_8 = - V_84 ;
V_7 -> V_64 = V_110 ;
break;
case V_111 :
F_34 ( V_96 , L_5 , L_7 ) ;
if ( V_7 -> V_64 != V_104 )
V_8 = - V_84 ;
V_7 -> V_64 = V_112 ;
break;
case V_113 :
F_34 ( V_96 , L_5 , L_8 ) ;
if ( V_7 -> V_64 != V_104 )
V_8 = - V_84 ;
V_7 -> V_64 = V_114 ;
break;
case V_115 :
F_34 ( V_96 , L_5 , L_9 ) ;
if ( V_7 -> V_64 != V_104 )
V_8 = - V_84 ;
V_7 -> V_64 = V_116 ;
break;
case V_117 :
F_34 ( V_96 , L_5 , L_10 ) ;
if ( V_7 -> V_64 != V_104 )
V_8 = - V_84 ;
V_7 -> V_64 = V_118 ;
break;
case V_119 :
F_34 ( V_96 , L_11 , args [ 0 ] . V_99 ) ;
if ( V_7 -> V_17 )
V_8 = - V_84 ;
if ( strcmp ( args [ 0 ] . V_99 , L_12 ) == 0 )
V_7 -> V_17 = V_60 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_13 ) == 0 )
V_7 -> V_17 = V_60 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_14 ) == 0 )
V_7 -> V_17 = V_61 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_15 ) == 0 )
V_7 -> V_17 = V_120 ;
else if ( ( strcmp ( args [ 0 ] . V_99 , L_16 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_99 , L_17 ) == 0 ) )
V_7 -> V_17 = V_56 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_18 ) == 0 )
V_7 -> V_17 = V_58 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_19 ) ==
0 )
V_7 -> V_17 = V_121 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_20 )
== 0 )
V_7 -> V_17 = V_122 ;
else if ( strcmp ( args [ 0 ] . V_99 , L_21 ) == 0 )
V_7 -> V_17 = V_80 ;
else
V_8 = - V_84 ;
if ( ! V_8 )
V_7 -> V_23 |= V_24 ;
break;
case V_123 :
F_34 ( V_96 , L_22 , args [ 0 ] . V_99 ) ;
if ( V_7 -> V_18 )
V_8 = - V_84 ;
V_99 = args [ 0 ] . V_99 ;
if ( * V_99 == '^' )
V_99 ++ ;
if ( ( strcmp ( V_99 , L_23 ) ) == 0 )
V_7 -> V_18 = V_124 ;
else if ( strcmp ( V_99 , L_24 ) == 0 )
V_7 -> V_18 = V_125 ;
else if ( strcmp ( V_99 , L_25 ) == 0 )
V_7 -> V_18 = V_126 ;
else if ( strcmp ( V_99 , L_26 ) == 0 )
V_7 -> V_18 = V_127 ;
else
V_8 = - V_84 ;
if ( ! V_8 )
V_7 -> V_23 |= ( * args [ 0 ] . V_99 == '^' )
? V_27 : V_26 ;
break;
case V_128 :
F_34 ( V_96 , L_27 , args [ 0 ] . V_99 ) ;
if ( V_7 -> V_29 ) {
V_8 = - V_84 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_99 , 16 , & V_7 -> V_29 ) ;
if ( ! V_8 )
V_7 -> V_23 |= V_28 ;
break;
case V_129 :
F_34 ( V_96 , L_28 , args [ 0 ] . V_99 ) ;
if ( F_42 ( V_7 -> V_33 , 0x00 ,
sizeof( V_7 -> V_33 ) ) ) {
V_8 = - V_84 ;
break;
}
V_8 = F_43 ( args [ 0 ] . V_99 ,
V_7 -> V_33 ) ;
if ( ! V_8 )
V_7 -> V_23 |= V_32 ;
break;
case V_130 :
F_34 ( V_96 , L_29 , args [ 0 ] . V_99 ) ;
case V_131 :
if ( V_106 == V_131 )
F_34 ( V_96 , L_30 , args [ 0 ] . V_99 ) ;
if ( F_44 ( V_7 -> V_36 ) ) {
V_8 = - V_84 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_99 , 10 , & V_107 ) ;
if ( ! V_8 ) {
V_7 -> V_36 = F_45 ( F_46 () ,
( V_132 ) V_107 ) ;
if ( ! F_44 ( V_7 -> V_36 ) ||
( V_132 ) V_107 != V_107 )
V_8 = - V_84 ;
else
V_7 -> V_23 |= ( V_106 == V_130 )
? V_35 : V_37 ;
}
break;
case V_133 :
F_34 ( V_96 , L_31 , args [ 0 ] . V_99 ) ;
if ( F_44 ( V_7 -> V_42 ) ) {
V_8 = - V_84 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_99 , 10 , & V_107 ) ;
if ( ! V_8 ) {
V_7 -> V_42 = F_45 ( F_46 () , ( V_132 ) V_107 ) ;
if ( ! F_44 ( V_7 -> V_42 ) || ( ( ( V_132 ) V_107 ) != V_107 ) )
V_8 = - V_84 ;
else
V_7 -> V_23 |= V_41 ;
}
break;
case V_134 :
F_34 ( V_96 , L_32 , args [ 0 ] . V_99 ) ;
V_8 = F_31 ( V_7 , args ,
V_49 ,
V_135 ) ;
break;
case V_136 :
F_34 ( V_96 , L_33 , args [ 0 ] . V_99 ) ;
V_8 = F_31 ( V_7 , args ,
V_50 ,
V_137 ) ;
break;
case V_138 :
F_34 ( V_96 , L_34 , args [ 0 ] . V_99 ) ;
V_8 = F_31 ( V_7 , args ,
V_51 ,
V_139 ) ;
break;
case V_140 :
F_34 ( V_96 , L_35 , args [ 0 ] . V_99 ) ;
V_8 = F_31 ( V_7 , args ,
V_52 ,
V_141 ) ;
break;
case V_142 :
F_34 ( V_96 , L_36 , args [ 0 ] . V_99 ) ;
V_8 = F_31 ( V_7 , args ,
V_53 ,
V_143 ) ;
break;
case V_144 :
F_34 ( V_96 , L_37 , args [ 0 ] . V_99 ) ;
V_8 = F_31 ( V_7 , args ,
V_54 ,
V_145 ) ;
break;
case V_146 :
if ( V_7 -> V_64 != V_114 ) {
V_8 = - V_84 ;
break;
}
F_34 ( V_96 , L_38 , args [ 0 ] . V_99 ) ;
if ( ( strcmp ( args [ 0 ] . V_99 , L_39 ) ) == 0 )
V_7 -> V_23 |= V_147 ;
else
V_8 = - V_84 ;
break;
case V_148 :
V_7 -> V_23 |= V_149 ;
break;
case V_150 :
F_34 ( V_96 , L_40 , V_100 ) ;
V_8 = - V_84 ;
break;
}
}
if ( ! V_8 && ( V_7 -> V_64 == V_104 ) )
V_8 = - V_84 ;
else if ( V_7 -> V_17 == V_61 )
V_71 |= V_151 ;
else if ( V_7 -> V_17 == V_120 )
V_71 |= V_152 ;
else if ( V_7 -> V_17 == V_80 )
V_71 |= V_81 ;
F_35 ( V_96 , L_41 , ! V_8 ) ;
F_47 ( V_96 ) ;
return V_8 ;
}
T_4 F_48 ( char * V_12 )
{
static const char V_153 [] = L_42 ;
char * V_100 ;
struct V_6 * V_7 ;
T_4 V_8 , V_154 ;
int V_155 = 0 ;
V_100 = F_39 ( & V_12 , L_43 ) ;
V_154 = strlen ( V_100 ) + 1 ;
V_100 += strspn ( V_100 , L_4 ) ;
if ( * V_100 == '#' || * V_100 == '\0' )
return V_154 ;
V_7 = F_49 ( sizeof( * V_7 ) , V_101 ) ;
if ( ! V_7 ) {
F_50 ( V_156 , NULL ,
NULL , V_153 , L_44 , - V_94 , V_155 ) ;
return - V_94 ;
}
F_30 ( & V_7 -> V_76 ) ;
V_8 = F_37 ( V_100 , V_7 ) ;
if ( V_8 ) {
F_33 ( V_7 ) ;
F_50 ( V_156 , NULL ,
NULL , V_153 , L_45 , V_8 ,
V_155 ) ;
return V_8 ;
}
F_23 ( & V_7 -> V_76 , & V_83 ) ;
return V_154 ;
}
void F_51 ( void )
{
struct V_6 * V_7 , * V_157 ;
int V_9 ;
V_71 = 0 ;
F_52 (entry, tmp, &ima_temp_rules, list) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_33 ( V_7 -> V_11 [ V_9 ] . V_14 ) ;
F_53 ( & V_7 -> V_76 ) ;
F_33 ( V_7 ) ;
}
}
void * F_54 ( struct V_158 * V_159 , T_5 * V_160 )
{
T_5 V_161 = * V_160 ;
struct V_6 * V_7 ;
F_17 () ;
F_18 (entry, ima_rules, list) {
if ( ! V_161 -- ) {
F_19 () ;
return V_7 ;
}
}
F_19 () ;
return NULL ;
}
void * F_55 ( struct V_158 * V_159 , void * V_162 , T_5 * V_160 )
{
struct V_6 * V_7 = V_162 ;
F_17 () ;
V_7 = F_56 ( V_7 -> V_76 . V_89 , struct V_6 , V_76 ) ;
F_19 () ;
( * V_160 ) ++ ;
return ( & V_7 -> V_76 == V_82 ) ? NULL : V_7 ;
}
void F_57 ( struct V_158 * V_159 , void * V_162 )
{
}
static void F_58 ( struct V_158 * V_159 , enum V_16 V_17 )
{
char V_163 [ 64 ] = { 0 ,} ;
switch ( V_17 ) {
case V_60 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_164 ) ) ;
break;
case V_56 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_165 ) ) ;
break;
case V_58 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_166 ) ) ;
break;
case V_61 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_167 ) ) ;
break;
case V_120 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_168 ) ) ;
break;
case V_25 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_169 ) ) ;
break;
case V_121 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_170 ) ) ;
break;
case V_122 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_171 ) ) ;
break;
case V_80 :
F_59 ( V_159 , F_60 ( V_119 ) , F_61 ( V_172 ) ) ;
break;
default:
snprintf ( V_163 , sizeof( V_163 ) , L_46 , V_17 ) ;
F_59 ( V_159 , F_60 ( V_119 ) , V_163 ) ;
break;
}
F_62 ( V_159 , L_3 ) ;
}
int F_63 ( struct V_158 * V_159 , void * V_162 )
{
struct V_6 * V_7 = V_162 ;
int V_9 ;
char V_163 [ 64 ] = { 0 ,} ;
F_17 () ;
if ( V_7 -> V_64 & V_110 )
F_62 ( V_159 , F_60 ( V_109 ) ) ;
if ( V_7 -> V_64 & V_112 )
F_62 ( V_159 , F_60 ( V_111 ) ) ;
if ( V_7 -> V_64 & V_114 )
F_62 ( V_159 , F_60 ( V_113 ) ) ;
if ( V_7 -> V_64 & V_116 )
F_62 ( V_159 , F_60 ( V_115 ) ) ;
if ( V_7 -> V_64 & V_118 )
F_62 ( V_159 , F_60 ( V_117 ) ) ;
F_62 ( V_159 , L_3 ) ;
if ( V_7 -> V_23 & V_24 )
F_58 ( V_159 , V_7 -> V_17 ) ;
if ( V_7 -> V_23 & V_26 ) {
if ( V_7 -> V_18 & V_124 )
F_59 ( V_159 , F_60 ( V_123 ) , F_64 ( V_173 ) ) ;
if ( V_7 -> V_18 & V_125 )
F_59 ( V_159 , F_60 ( V_123 ) , F_64 ( V_174 ) ) ;
if ( V_7 -> V_18 & V_126 )
F_59 ( V_159 , F_60 ( V_123 ) , F_64 ( V_175 ) ) ;
if ( V_7 -> V_18 & V_127 )
F_59 ( V_159 , F_60 ( V_123 ) , F_64 ( V_176 ) ) ;
F_62 ( V_159 , L_3 ) ;
}
if ( V_7 -> V_23 & V_28 ) {
snprintf ( V_163 , sizeof( V_163 ) , L_47 , V_7 -> V_29 ) ;
F_59 ( V_159 , F_60 ( V_128 ) , V_163 ) ;
F_62 ( V_159 , L_3 ) ;
}
if ( V_7 -> V_23 & V_32 ) {
F_59 ( V_159 , L_48 , V_7 -> V_33 ) ;
F_62 ( V_159 , L_3 ) ;
}
if ( V_7 -> V_23 & V_35 ) {
snprintf ( V_163 , sizeof( V_163 ) , L_46 , F_65 ( V_7 -> V_36 ) ) ;
F_59 ( V_159 , F_60 ( V_130 ) , V_163 ) ;
F_62 ( V_159 , L_3 ) ;
}
if ( V_7 -> V_23 & V_37 ) {
snprintf ( V_163 , sizeof( V_163 ) , L_46 , F_65 ( V_7 -> V_36 ) ) ;
F_59 ( V_159 , F_60 ( V_131 ) , V_163 ) ;
F_62 ( V_159 , L_3 ) ;
}
if ( V_7 -> V_23 & V_41 ) {
snprintf ( V_163 , sizeof( V_163 ) , L_46 , F_65 ( V_7 -> V_42 ) ) ;
F_59 ( V_159 , F_60 ( V_133 ) , V_163 ) ;
F_62 ( V_159 , L_3 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_7 -> V_11 [ V_9 ] . V_12 ) {
switch ( V_9 ) {
case V_49 :
F_59 ( V_159 , F_60 ( V_134 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_50 :
F_59 ( V_159 , F_60 ( V_136 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_51 :
F_59 ( V_159 , F_60 ( V_138 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_52 :
F_59 ( V_159 , F_60 ( V_140 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_53 :
F_59 ( V_159 , F_60 ( V_142 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_54 :
F_59 ( V_159 , F_60 ( V_144 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
}
}
}
if ( V_7 -> V_23 & V_147 )
F_62 ( V_159 , L_49 ) ;
if ( V_7 -> V_23 & V_149 )
F_62 ( V_159 , L_50 ) ;
F_19 () ;
F_62 ( V_159 , L_43 ) ;
return 0 ;
}
