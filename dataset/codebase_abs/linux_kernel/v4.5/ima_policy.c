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
static bool F_8 ( struct V_6 * V_12 ,
struct V_15 * V_15 , enum V_16 V_17 , int V_18 )
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
static int F_15 ( struct V_6 * V_12 , int V_17 )
{
if ( ! ( V_12 -> V_23 & V_24 ) )
return V_55 ;
switch ( V_17 ) {
case V_56 :
return V_57 ;
case V_58 :
return V_59 ;
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
default:
return V_55 ;
}
}
int F_16 ( struct V_15 * V_15 , enum V_16 V_17 , int V_18 ,
int V_23 )
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
V_70 |= V_7 -> V_65 ;
}
V_71 |= V_72 ;
if ( ! V_71 )
V_70 &= ~ V_69 ;
}
void T_1 F_21 ( void )
{
int V_9 , V_73 , V_74 ;
V_73 = V_2 ? F_22 ( V_75 ) : 0 ;
V_74 = V_5 ?
F_22 ( V_76 ) : 0 ;
for ( V_9 = 0 ; V_9 < V_73 ; V_9 ++ )
F_23 ( & V_75 [ V_9 ] . V_77 , & V_78 ) ;
switch ( V_2 ) {
case V_3 :
for ( V_9 = 0 ; V_9 < F_22 ( V_79 ) ; V_9 ++ )
F_23 ( & V_79 [ V_9 ] . V_77 ,
& V_78 ) ;
break;
case V_4 :
for ( V_9 = 0 ; V_9 < F_22 ( V_80 ) ; V_9 ++ )
F_23 ( & V_80 [ V_9 ] . V_77 ,
& V_78 ) ;
default:
break;
}
for ( V_9 = 0 ; V_9 < V_74 ; V_9 ++ ) {
F_23 ( & V_76 [ V_9 ] . V_77 ,
& V_78 ) ;
}
V_81 = & V_78 ;
}
int F_24 ()
{
if ( F_25 ( & V_82 ) )
return - V_83 ;
return 0 ;
}
void F_26 ( void )
{
struct V_84 * V_85 , * V_86 , * V_87 ;
V_85 = ( & V_82 ) -> V_88 ;
V_86 = ( & V_82 ) -> V_89 ;
V_87 = & V_90 ;
F_27 () ;
V_86 -> V_88 = V_87 ;
F_28 ( F_29 ( V_87 -> V_89 ) , V_85 ) ;
V_85 -> V_89 = V_87 -> V_89 ;
V_87 -> V_89 = V_86 ;
F_30 ( & V_82 ) ;
if ( V_81 != V_87 ) {
V_70 = 0 ;
V_81 = V_87 ;
}
F_20 () ;
}
static int F_31 ( struct V_6 * V_7 ,
T_3 * args , int V_91 , int V_92 )
{
int V_8 ;
if ( V_7 -> V_11 [ V_91 ] . V_12 )
return - V_83 ;
V_7 -> V_11 [ V_91 ] . V_14 = F_32 ( args ) ;
if ( ! V_7 -> V_11 [ V_91 ] . V_14 )
return - V_93 ;
V_7 -> V_11 [ V_91 ] . type = V_92 ;
V_8 = F_6 ( V_7 -> V_11 [ V_91 ] . type ,
V_13 ,
V_7 -> V_11 [ V_91 ] . V_14 ,
& V_7 -> V_11 [ V_91 ] . V_12 ) ;
if ( ! V_7 -> V_11 [ V_91 ] . V_12 ) {
F_33 ( V_7 -> V_11 [ V_91 ] . V_14 ) ;
return - V_83 ;
}
return V_8 ;
}
static void F_34 ( struct V_94 * V_95 , char * V_96 , char * V_97 )
{
F_35 ( V_95 , L_2 , V_96 ) ;
F_36 ( V_95 , V_97 ) ;
F_35 ( V_95 , L_3 ) ;
}
static int F_37 ( char * V_12 , struct V_6 * V_7 )
{
struct V_94 * V_95 ;
char * V_98 ;
char * V_99 ;
int V_8 = 0 ;
V_95 = F_38 ( NULL , V_100 , V_101 ) ;
V_7 -> V_36 = V_102 ;
V_7 -> V_42 = V_102 ;
V_7 -> V_65 = V_103 ;
while ( ( V_99 = F_39 ( & V_12 , L_4 ) ) != NULL ) {
T_3 args [ V_104 ] ;
int V_105 ;
unsigned long V_106 ;
if ( V_8 < 0 )
break;
if ( ( * V_99 == '\0' ) || ( * V_99 == ' ' ) || ( * V_99 == '\t' ) )
continue;
V_105 = F_40 ( V_99 , V_107 , args ) ;
switch ( V_105 ) {
case V_108 :
F_34 ( V_95 , L_5 , L_6 ) ;
if ( V_7 -> V_65 != V_103 )
V_8 = - V_83 ;
V_7 -> V_65 = V_109 ;
break;
case V_110 :
F_34 ( V_95 , L_5 , L_7 ) ;
if ( V_7 -> V_65 != V_103 )
V_8 = - V_83 ;
V_7 -> V_65 = V_111 ;
break;
case V_112 :
F_34 ( V_95 , L_5 , L_8 ) ;
if ( V_7 -> V_65 != V_103 )
V_8 = - V_83 ;
V_7 -> V_65 = V_113 ;
break;
case V_114 :
F_34 ( V_95 , L_5 , L_9 ) ;
if ( V_7 -> V_65 != V_103 )
V_8 = - V_83 ;
V_7 -> V_65 = V_115 ;
break;
case V_116 :
F_34 ( V_95 , L_5 , L_10 ) ;
if ( V_7 -> V_65 != V_103 )
V_8 = - V_83 ;
V_7 -> V_65 = V_117 ;
break;
case V_118 :
F_34 ( V_95 , L_11 , args [ 0 ] . V_98 ) ;
if ( V_7 -> V_17 )
V_8 = - V_83 ;
if ( strcmp ( args [ 0 ] . V_98 , L_12 ) == 0 )
V_7 -> V_17 = V_64 ;
else if ( strcmp ( args [ 0 ] . V_98 , L_13 ) == 0 )
V_7 -> V_17 = V_64 ;
else if ( strcmp ( args [ 0 ] . V_98 , L_14 ) == 0 )
V_7 -> V_17 = V_60 ;
else if ( strcmp ( args [ 0 ] . V_98 , L_15 ) == 0 )
V_7 -> V_17 = V_62 ;
else if ( ( strcmp ( args [ 0 ] . V_98 , L_16 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_98 , L_17 ) == 0 ) )
V_7 -> V_17 = V_56 ;
else if ( strcmp ( args [ 0 ] . V_98 , L_18 ) == 0 )
V_7 -> V_17 = V_58 ;
else
V_8 = - V_83 ;
if ( ! V_8 )
V_7 -> V_23 |= V_24 ;
break;
case V_119 :
F_34 ( V_95 , L_19 , args [ 0 ] . V_98 ) ;
if ( V_7 -> V_18 )
V_8 = - V_83 ;
V_98 = args [ 0 ] . V_98 ;
if ( * V_98 == '^' )
V_98 ++ ;
if ( ( strcmp ( V_98 , L_20 ) ) == 0 )
V_7 -> V_18 = V_120 ;
else if ( strcmp ( V_98 , L_21 ) == 0 )
V_7 -> V_18 = V_121 ;
else if ( strcmp ( V_98 , L_22 ) == 0 )
V_7 -> V_18 = V_122 ;
else if ( strcmp ( V_98 , L_23 ) == 0 )
V_7 -> V_18 = V_123 ;
else
V_8 = - V_83 ;
if ( ! V_8 )
V_7 -> V_23 |= ( * args [ 0 ] . V_98 == '^' )
? V_27 : V_26 ;
break;
case V_124 :
F_34 ( V_95 , L_24 , args [ 0 ] . V_98 ) ;
if ( V_7 -> V_29 ) {
V_8 = - V_83 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_98 , 16 , & V_7 -> V_29 ) ;
if ( ! V_8 )
V_7 -> V_23 |= V_28 ;
break;
case V_125 :
F_34 ( V_95 , L_25 , args [ 0 ] . V_98 ) ;
if ( F_42 ( V_7 -> V_33 , 0x00 ,
sizeof( V_7 -> V_33 ) ) ) {
V_8 = - V_83 ;
break;
}
V_8 = F_43 ( args [ 0 ] . V_98 ,
V_7 -> V_33 ) ;
if ( ! V_8 )
V_7 -> V_23 |= V_32 ;
break;
case V_126 :
F_34 ( V_95 , L_26 , args [ 0 ] . V_98 ) ;
case V_127 :
if ( V_105 == V_127 )
F_34 ( V_95 , L_27 , args [ 0 ] . V_98 ) ;
if ( F_44 ( V_7 -> V_36 ) ) {
V_8 = - V_83 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_98 , 10 , & V_106 ) ;
if ( ! V_8 ) {
V_7 -> V_36 = F_45 ( F_46 () ,
( V_128 ) V_106 ) ;
if ( ! F_44 ( V_7 -> V_36 ) ||
( V_128 ) V_106 != V_106 )
V_8 = - V_83 ;
else
V_7 -> V_23 |= ( V_105 == V_126 )
? V_35 : V_37 ;
}
break;
case V_129 :
F_34 ( V_95 , L_28 , args [ 0 ] . V_98 ) ;
if ( F_44 ( V_7 -> V_42 ) ) {
V_8 = - V_83 ;
break;
}
V_8 = F_41 ( args [ 0 ] . V_98 , 10 , & V_106 ) ;
if ( ! V_8 ) {
V_7 -> V_42 = F_45 ( F_46 () , ( V_128 ) V_106 ) ;
if ( ! F_44 ( V_7 -> V_42 ) || ( ( ( V_128 ) V_106 ) != V_106 ) )
V_8 = - V_83 ;
else
V_7 -> V_23 |= V_41 ;
}
break;
case V_130 :
F_34 ( V_95 , L_29 , args [ 0 ] . V_98 ) ;
V_8 = F_31 ( V_7 , args ,
V_49 ,
V_131 ) ;
break;
case V_132 :
F_34 ( V_95 , L_30 , args [ 0 ] . V_98 ) ;
V_8 = F_31 ( V_7 , args ,
V_50 ,
V_133 ) ;
break;
case V_134 :
F_34 ( V_95 , L_31 , args [ 0 ] . V_98 ) ;
V_8 = F_31 ( V_7 , args ,
V_51 ,
V_135 ) ;
break;
case V_136 :
F_34 ( V_95 , L_32 , args [ 0 ] . V_98 ) ;
V_8 = F_31 ( V_7 , args ,
V_52 ,
V_137 ) ;
break;
case V_138 :
F_34 ( V_95 , L_33 , args [ 0 ] . V_98 ) ;
V_8 = F_31 ( V_7 , args ,
V_53 ,
V_139 ) ;
break;
case V_140 :
F_34 ( V_95 , L_34 , args [ 0 ] . V_98 ) ;
V_8 = F_31 ( V_7 , args ,
V_54 ,
V_141 ) ;
break;
case V_142 :
if ( V_7 -> V_65 != V_113 ) {
V_8 = - V_83 ;
break;
}
F_34 ( V_95 , L_35 , args [ 0 ] . V_98 ) ;
if ( ( strcmp ( args [ 0 ] . V_98 , L_36 ) ) == 0 )
V_7 -> V_23 |= V_143 ;
else
V_8 = - V_83 ;
break;
case V_144 :
V_7 -> V_23 |= V_145 ;
break;
case V_146 :
F_34 ( V_95 , L_37 , V_99 ) ;
V_8 = - V_83 ;
break;
}
}
if ( ! V_8 && ( V_7 -> V_65 == V_103 ) )
V_8 = - V_83 ;
else if ( V_7 -> V_17 == V_60 )
V_72 |= V_147 ;
else if ( V_7 -> V_17 == V_62 )
V_72 |= V_148 ;
F_35 ( V_95 , L_38 , ! V_8 ) ;
F_47 ( V_95 ) ;
return V_8 ;
}
T_4 F_48 ( char * V_12 )
{
static const char V_149 [] = L_39 ;
char * V_99 ;
struct V_6 * V_7 ;
T_4 V_8 , V_150 ;
int V_151 = 0 ;
V_99 = F_39 ( & V_12 , L_40 ) ;
V_150 = strlen ( V_99 ) + 1 ;
V_99 += strspn ( V_99 , L_4 ) ;
if ( * V_99 == '#' || * V_99 == '\0' )
return V_150 ;
V_7 = F_49 ( sizeof( * V_7 ) , V_100 ) ;
if ( ! V_7 ) {
F_50 ( V_152 , NULL ,
NULL , V_149 , L_41 , - V_93 , V_151 ) ;
return - V_93 ;
}
F_30 ( & V_7 -> V_77 ) ;
V_8 = F_37 ( V_99 , V_7 ) ;
if ( V_8 ) {
F_33 ( V_7 ) ;
F_50 ( V_152 , NULL ,
NULL , V_149 , L_42 , V_8 ,
V_151 ) ;
return V_8 ;
}
F_23 ( & V_7 -> V_77 , & V_82 ) ;
return V_150 ;
}
void F_51 ( void )
{
struct V_6 * V_7 , * V_153 ;
int V_9 ;
V_72 = 0 ;
F_52 (entry, tmp, &ima_temp_rules, list) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_33 ( V_7 -> V_11 [ V_9 ] . V_14 ) ;
F_53 ( & V_7 -> V_77 ) ;
F_33 ( V_7 ) ;
}
}
void * F_54 ( struct V_154 * V_155 , T_5 * V_156 )
{
T_5 V_157 = * V_156 ;
struct V_6 * V_7 ;
F_17 () ;
F_18 (entry, ima_rules, list) {
if ( ! V_157 -- ) {
F_19 () ;
return V_7 ;
}
}
F_19 () ;
return NULL ;
}
void * F_55 ( struct V_154 * V_155 , void * V_158 , T_5 * V_156 )
{
struct V_6 * V_7 = V_158 ;
F_17 () ;
V_7 = F_56 ( V_7 -> V_77 . V_88 , struct V_6 , V_77 ) ;
F_19 () ;
( * V_156 ) ++ ;
return ( & V_7 -> V_77 == V_81 ) ? NULL : V_7 ;
}
void F_57 ( struct V_154 * V_155 , void * V_158 )
{
}
int F_58 ( struct V_154 * V_155 , void * V_158 )
{
struct V_6 * V_7 = V_158 ;
int V_9 = 0 ;
char V_159 [ 64 ] = { 0 ,} ;
F_17 () ;
if ( V_7 -> V_65 & V_109 )
F_59 ( V_155 , F_60 ( V_108 ) ) ;
if ( V_7 -> V_65 & V_111 )
F_59 ( V_155 , F_60 ( V_110 ) ) ;
if ( V_7 -> V_65 & V_113 )
F_59 ( V_155 , F_60 ( V_112 ) ) ;
if ( V_7 -> V_65 & V_115 )
F_59 ( V_155 , F_60 ( V_114 ) ) ;
if ( V_7 -> V_65 & V_117 )
F_59 ( V_155 , F_60 ( V_116 ) ) ;
F_59 ( V_155 , L_3 ) ;
if ( V_7 -> V_23 & V_24 ) {
switch ( V_7 -> V_17 ) {
case V_64 :
F_61 ( V_155 , F_60 ( V_118 ) , F_62 ( V_160 ) ) ;
break;
case V_56 :
F_61 ( V_155 , F_60 ( V_118 ) , F_62 ( V_161 ) ) ;
break;
case V_58 :
F_61 ( V_155 , F_60 ( V_118 ) , F_62 ( V_162 ) ) ;
break;
case V_60 :
F_61 ( V_155 , F_60 ( V_118 ) , F_62 ( V_163 ) ) ;
break;
case V_62 :
F_61 ( V_155 , F_60 ( V_118 ) , F_62 ( V_164 ) ) ;
break;
case V_25 :
F_61 ( V_155 , F_60 ( V_118 ) , F_62 ( V_165 ) ) ;
break;
default:
snprintf ( V_159 , sizeof( V_159 ) , L_43 , V_7 -> V_17 ) ;
F_61 ( V_155 , F_60 ( V_118 ) , V_159 ) ;
break;
}
F_59 ( V_155 , L_3 ) ;
}
if ( V_7 -> V_23 & V_26 ) {
if ( V_7 -> V_18 & V_120 )
F_61 ( V_155 , F_60 ( V_119 ) , F_63 ( V_166 ) ) ;
if ( V_7 -> V_18 & V_121 )
F_61 ( V_155 , F_60 ( V_119 ) , F_63 ( V_167 ) ) ;
if ( V_7 -> V_18 & V_122 )
F_61 ( V_155 , F_60 ( V_119 ) , F_63 ( V_168 ) ) ;
if ( V_7 -> V_18 & V_123 )
F_61 ( V_155 , F_60 ( V_119 ) , F_63 ( V_169 ) ) ;
F_59 ( V_155 , L_3 ) ;
}
if ( V_7 -> V_23 & V_28 ) {
snprintf ( V_159 , sizeof( V_159 ) , L_44 , V_7 -> V_29 ) ;
F_61 ( V_155 , F_60 ( V_124 ) , V_159 ) ;
F_59 ( V_155 , L_3 ) ;
}
if ( V_7 -> V_23 & V_32 ) {
F_59 ( V_155 , L_45 ) ;
for ( V_9 = 0 ; V_9 < F_22 ( V_7 -> V_33 ) ; ++ V_9 ) {
switch ( V_9 ) {
case 4 :
case 6 :
case 8 :
case 10 :
F_59 ( V_155 , L_46 ) ;
}
F_61 ( V_155 , L_47 , V_7 -> V_33 [ V_9 ] ) ;
}
F_59 ( V_155 , L_3 ) ;
}
if ( V_7 -> V_23 & V_35 ) {
snprintf ( V_159 , sizeof( V_159 ) , L_43 , F_64 ( V_7 -> V_36 ) ) ;
F_61 ( V_155 , F_60 ( V_126 ) , V_159 ) ;
F_59 ( V_155 , L_3 ) ;
}
if ( V_7 -> V_23 & V_37 ) {
snprintf ( V_159 , sizeof( V_159 ) , L_43 , F_64 ( V_7 -> V_36 ) ) ;
F_61 ( V_155 , F_60 ( V_127 ) , V_159 ) ;
F_59 ( V_155 , L_3 ) ;
}
if ( V_7 -> V_23 & V_41 ) {
snprintf ( V_159 , sizeof( V_159 ) , L_43 , F_64 ( V_7 -> V_42 ) ) ;
F_61 ( V_155 , F_60 ( V_129 ) , V_159 ) ;
F_59 ( V_155 , L_3 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_7 -> V_11 [ V_9 ] . V_12 ) {
switch ( V_9 ) {
case V_49 :
F_61 ( V_155 , F_60 ( V_130 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_50 :
F_61 ( V_155 , F_60 ( V_132 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_51 :
F_61 ( V_155 , F_60 ( V_134 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_52 :
F_61 ( V_155 , F_60 ( V_136 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_53 :
F_61 ( V_155 , F_60 ( V_138 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
case V_54 :
F_61 ( V_155 , F_60 ( V_140 ) ,
( char * ) V_7 -> V_11 [ V_9 ] . V_14 ) ;
break;
}
}
}
if ( V_7 -> V_23 & V_143 )
F_59 ( V_155 , L_48 ) ;
if ( V_7 -> V_23 & V_145 )
F_59 ( V_155 , L_49 ) ;
F_19 () ;
F_59 ( V_155 , L_40 ) ;
return 0 ;
}
