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
struct V_6 * V_7 , * V_8 ;
int V_9 ;
int V_10 ;
F_5 ( & V_11 ) ;
F_6 (entry, tmp, &ima_policy_rules, list) {
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
if ( ! V_7 -> V_13 [ V_10 ] . V_14 )
continue;
V_9 = F_7 ( V_7 -> V_13 [ V_10 ] . type ,
V_15 ,
V_7 -> V_13 [ V_10 ] . V_16 ,
& V_7 -> V_13 [ V_10 ] . V_14 ) ;
F_8 ( ! V_7 -> V_13 [ V_10 ] . V_14 ) ;
}
}
F_9 ( & V_11 ) ;
}
static bool F_10 ( struct V_6 * V_14 ,
struct V_17 * V_17 , enum V_18 V_19 , int V_20 )
{
struct V_21 * V_22 = V_23 ;
const struct V_24 * V_24 = F_11 () ;
int V_10 ;
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
memcmp ( V_14 -> V_35 , V_17 -> V_32 -> V_36 , sizeof( V_14 -> V_35 ) ) )
return false ;
if ( ( V_14 -> V_25 & V_37 ) && ! F_12 ( V_14 -> V_38 , V_24 -> V_38 ) )
return false ;
if ( V_14 -> V_25 & V_39 ) {
if ( F_13 ( V_23 , V_40 ) ) {
if ( ! F_12 ( V_14 -> V_38 , V_24 -> V_41 )
&& ! F_12 ( V_14 -> V_38 , V_24 -> V_42 )
&& ! F_12 ( V_14 -> V_38 , V_24 -> V_38 ) )
return false ;
} else if ( ! F_12 ( V_14 -> V_38 , V_24 -> V_41 ) )
return false ;
}
if ( ( V_14 -> V_25 & V_43 ) && ! F_12 ( V_14 -> V_44 , V_17 -> V_45 ) )
return false ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
int V_46 = 0 ;
T_2 V_47 , V_48 ;
int V_49 = 0 ;
if ( ! V_14 -> V_13 [ V_10 ] . V_14 )
continue;
V_50:
switch ( V_10 ) {
case V_51 :
case V_52 :
case V_53 :
F_14 ( V_17 , & V_47 ) ;
V_46 = F_15 ( V_47 ,
V_14 -> V_13 [ V_10 ] . type ,
V_15 ,
V_14 -> V_13 [ V_10 ] . V_14 ,
NULL ) ;
break;
case V_54 :
case V_55 :
case V_56 :
F_16 ( V_22 , & V_48 ) ;
V_46 = F_15 ( V_48 ,
V_14 -> V_13 [ V_10 ] . type ,
V_15 ,
V_14 -> V_13 [ V_10 ] . V_14 ,
NULL ) ;
default:
break;
}
if ( ( V_46 < 0 ) && ( ! V_49 ) ) {
V_49 = 1 ;
F_4 () ;
goto V_50;
}
if ( ! V_46 )
return false ;
}
return true ;
}
static int F_17 ( struct V_6 * V_14 , int V_19 )
{
if ( ! ( V_14 -> V_25 & V_26 ) )
return V_57 ;
switch ( V_19 ) {
case V_58 :
return V_59 ;
case V_60 :
return V_61 ;
case V_62 :
return V_63 ;
case V_64 :
return V_65 ;
case V_66 :
default:
return V_57 ;
}
}
int F_18 ( struct V_17 * V_17 , enum V_18 V_19 , int V_20 ,
int V_25 )
{
struct V_6 * V_7 ;
int V_67 = 0 , V_68 = V_25 | ( V_25 << 1 ) ;
F_19 (entry, ima_rules, list) {
if ( ! ( V_7 -> V_67 & V_68 ) )
continue;
if ( ! F_10 ( V_7 , V_17 , V_19 , V_20 ) )
continue;
V_67 |= V_7 -> V_25 & V_69 ;
V_67 |= V_7 -> V_67 & V_70 ;
if ( V_7 -> V_67 & V_71 )
V_67 |= F_17 ( V_7 , V_19 ) ;
if ( V_7 -> V_67 & V_70 )
V_68 &= ~ ( V_7 -> V_67 | V_7 -> V_67 << 1 ) ;
else
V_68 &= ~ ( V_7 -> V_67 | V_7 -> V_67 >> 1 ) ;
if ( ! V_68 )
break;
}
return V_67 ;
}
void F_20 ( void )
{
struct V_6 * V_7 ;
V_72 = 0 ;
F_19 (entry, ima_rules, list) {
if ( V_7 -> V_67 & V_70 )
V_72 |= V_7 -> V_67 ;
}
if ( ! V_73 )
V_72 &= ~ V_71 ;
}
void T_1 F_21 ( void )
{
int V_10 , V_74 , V_75 ;
V_74 = V_2 ? F_22 ( V_76 ) : 0 ;
V_75 = V_5 ?
F_22 ( V_77 ) : 0 ;
for ( V_10 = 0 ; V_10 < V_74 ; V_10 ++ )
F_23 ( & V_76 [ V_10 ] . V_78 , & V_79 ) ;
switch ( V_2 ) {
case V_3 :
for ( V_10 = 0 ; V_10 < F_22 ( V_80 ) ; V_10 ++ )
F_23 ( & V_80 [ V_10 ] . V_78 ,
& V_79 ) ;
break;
case V_4 :
for ( V_10 = 0 ; V_10 < F_22 ( V_81 ) ; V_10 ++ )
F_23 ( & V_81 [ V_10 ] . V_78 ,
& V_79 ) ;
default:
break;
}
for ( V_10 = 0 ; V_10 < V_75 ; V_10 ++ ) {
F_23 ( & V_77 [ V_10 ] . V_78 ,
& V_79 ) ;
}
V_82 = & V_79 ;
}
void F_24 ( void )
{
V_82 = & V_83 ;
F_20 () ;
}
static int F_25 ( struct V_6 * V_7 ,
T_3 * args , int V_84 , int V_85 )
{
int V_9 ;
if ( V_7 -> V_13 [ V_84 ] . V_14 )
return - V_86 ;
V_7 -> V_13 [ V_84 ] . V_16 = F_26 ( args ) ;
if ( ! V_7 -> V_13 [ V_84 ] . V_16 )
return - V_87 ;
V_7 -> V_13 [ V_84 ] . type = V_85 ;
V_9 = F_7 ( V_7 -> V_13 [ V_84 ] . type ,
V_15 ,
V_7 -> V_13 [ V_84 ] . V_16 ,
& V_7 -> V_13 [ V_84 ] . V_14 ) ;
if ( ! V_7 -> V_13 [ V_84 ] . V_14 ) {
F_27 ( V_7 -> V_13 [ V_84 ] . V_16 ) ;
return - V_86 ;
}
return V_9 ;
}
static void F_28 ( struct V_88 * V_89 , char * V_90 , char * V_91 )
{
F_29 ( V_89 , L_2 , V_90 ) ;
F_30 ( V_89 , V_91 ) ;
F_29 ( V_89 , L_3 ) ;
}
static int F_31 ( char * V_14 , struct V_6 * V_7 )
{
struct V_88 * V_89 ;
char * V_92 ;
char * V_93 ;
int V_9 = 0 ;
V_89 = F_32 ( NULL , V_94 , V_95 ) ;
V_7 -> V_38 = V_96 ;
V_7 -> V_44 = V_96 ;
V_7 -> V_67 = V_97 ;
while ( ( V_93 = F_33 ( & V_14 , L_4 ) ) != NULL ) {
T_3 args [ V_98 ] ;
int V_99 ;
unsigned long V_100 ;
if ( V_9 < 0 )
break;
if ( ( * V_93 == '\0' ) || ( * V_93 == ' ' ) || ( * V_93 == '\t' ) )
continue;
V_99 = F_34 ( V_93 , V_101 , args ) ;
switch ( V_99 ) {
case V_102 :
F_28 ( V_89 , L_5 , L_6 ) ;
if ( V_7 -> V_67 != V_97 )
V_9 = - V_86 ;
V_7 -> V_67 = V_103 ;
break;
case V_104 :
F_28 ( V_89 , L_5 , L_7 ) ;
if ( V_7 -> V_67 != V_97 )
V_9 = - V_86 ;
V_7 -> V_67 = V_105 ;
break;
case V_106 :
F_28 ( V_89 , L_5 , L_8 ) ;
if ( V_7 -> V_67 != V_97 )
V_9 = - V_86 ;
V_7 -> V_67 = V_107 ;
break;
case V_108 :
F_28 ( V_89 , L_5 , L_9 ) ;
if ( V_7 -> V_67 != V_97 )
V_9 = - V_86 ;
V_7 -> V_67 = V_109 ;
break;
case V_110 :
F_28 ( V_89 , L_5 , L_10 ) ;
if ( V_7 -> V_67 != V_97 )
V_9 = - V_86 ;
V_7 -> V_67 = V_111 ;
break;
case V_112 :
F_28 ( V_89 , L_11 , args [ 0 ] . V_92 ) ;
if ( V_7 -> V_19 )
V_9 = - V_86 ;
if ( strcmp ( args [ 0 ] . V_92 , L_12 ) == 0 )
V_7 -> V_19 = V_66 ;
else if ( strcmp ( args [ 0 ] . V_92 , L_13 ) == 0 )
V_7 -> V_19 = V_66 ;
else if ( strcmp ( args [ 0 ] . V_92 , L_14 ) == 0 )
V_7 -> V_19 = V_62 ;
else if ( strcmp ( args [ 0 ] . V_92 , L_15 ) == 0 )
V_7 -> V_19 = V_64 ;
else if ( ( strcmp ( args [ 0 ] . V_92 , L_16 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_92 , L_17 ) == 0 ) )
V_7 -> V_19 = V_58 ;
else if ( strcmp ( args [ 0 ] . V_92 , L_18 ) == 0 )
V_7 -> V_19 = V_60 ;
else
V_9 = - V_86 ;
if ( ! V_9 )
V_7 -> V_25 |= V_26 ;
break;
case V_113 :
F_28 ( V_89 , L_19 , args [ 0 ] . V_92 ) ;
if ( V_7 -> V_20 )
V_9 = - V_86 ;
V_92 = args [ 0 ] . V_92 ;
if ( * V_92 == '^' )
V_92 ++ ;
if ( ( strcmp ( V_92 , L_20 ) ) == 0 )
V_7 -> V_20 = V_114 ;
else if ( strcmp ( V_92 , L_21 ) == 0 )
V_7 -> V_20 = V_115 ;
else if ( strcmp ( V_92 , L_22 ) == 0 )
V_7 -> V_20 = V_116 ;
else if ( strcmp ( V_92 , L_23 ) == 0 )
V_7 -> V_20 = V_117 ;
else
V_9 = - V_86 ;
if ( ! V_9 )
V_7 -> V_25 |= ( * args [ 0 ] . V_92 == '^' )
? V_29 : V_28 ;
break;
case V_118 :
F_28 ( V_89 , L_24 , args [ 0 ] . V_92 ) ;
if ( V_7 -> V_31 ) {
V_9 = - V_86 ;
break;
}
V_9 = F_35 ( args [ 0 ] . V_92 , 16 , & V_7 -> V_31 ) ;
if ( ! V_9 )
V_7 -> V_25 |= V_30 ;
break;
case V_119 :
F_28 ( V_89 , L_25 , args [ 0 ] . V_92 ) ;
if ( F_36 ( V_7 -> V_35 , 0x00 ,
sizeof( V_7 -> V_35 ) ) ) {
V_9 = - V_86 ;
break;
}
V_9 = F_37 ( args [ 0 ] . V_92 ,
V_7 -> V_35 ) ;
if ( ! V_9 )
V_7 -> V_25 |= V_34 ;
break;
case V_120 :
F_28 ( V_89 , L_26 , args [ 0 ] . V_92 ) ;
case V_121 :
if ( V_99 == V_121 )
F_28 ( V_89 , L_27 , args [ 0 ] . V_92 ) ;
if ( F_38 ( V_7 -> V_38 ) ) {
V_9 = - V_86 ;
break;
}
V_9 = F_35 ( args [ 0 ] . V_92 , 10 , & V_100 ) ;
if ( ! V_9 ) {
V_7 -> V_38 = F_39 ( F_40 () ,
( V_122 ) V_100 ) ;
if ( ! F_38 ( V_7 -> V_38 ) ||
( V_122 ) V_100 != V_100 )
V_9 = - V_86 ;
else
V_7 -> V_25 |= ( V_99 == V_120 )
? V_37 : V_39 ;
}
break;
case V_123 :
F_28 ( V_89 , L_28 , args [ 0 ] . V_92 ) ;
if ( F_38 ( V_7 -> V_44 ) ) {
V_9 = - V_86 ;
break;
}
V_9 = F_35 ( args [ 0 ] . V_92 , 10 , & V_100 ) ;
if ( ! V_9 ) {
V_7 -> V_44 = F_39 ( F_40 () , ( V_122 ) V_100 ) ;
if ( ! F_38 ( V_7 -> V_44 ) || ( ( ( V_122 ) V_100 ) != V_100 ) )
V_9 = - V_86 ;
else
V_7 -> V_25 |= V_43 ;
}
break;
case V_124 :
F_28 ( V_89 , L_29 , args [ 0 ] . V_92 ) ;
V_9 = F_25 ( V_7 , args ,
V_51 ,
V_125 ) ;
break;
case V_126 :
F_28 ( V_89 , L_30 , args [ 0 ] . V_92 ) ;
V_9 = F_25 ( V_7 , args ,
V_52 ,
V_127 ) ;
break;
case V_128 :
F_28 ( V_89 , L_31 , args [ 0 ] . V_92 ) ;
V_9 = F_25 ( V_7 , args ,
V_53 ,
V_129 ) ;
break;
case V_130 :
F_28 ( V_89 , L_32 , args [ 0 ] . V_92 ) ;
V_9 = F_25 ( V_7 , args ,
V_54 ,
V_131 ) ;
break;
case V_132 :
F_28 ( V_89 , L_33 , args [ 0 ] . V_92 ) ;
V_9 = F_25 ( V_7 , args ,
V_55 ,
V_133 ) ;
break;
case V_134 :
F_28 ( V_89 , L_34 , args [ 0 ] . V_92 ) ;
V_9 = F_25 ( V_7 , args ,
V_56 ,
V_135 ) ;
break;
case V_136 :
if ( V_7 -> V_67 != V_107 ) {
V_9 = - V_86 ;
break;
}
F_28 ( V_89 , L_35 , args [ 0 ] . V_92 ) ;
if ( ( strcmp ( args [ 0 ] . V_92 , L_36 ) ) == 0 )
V_7 -> V_25 |= V_137 ;
else
V_9 = - V_86 ;
break;
case V_138 :
V_7 -> V_25 |= V_139 ;
break;
case V_140 :
F_28 ( V_89 , L_37 , V_93 ) ;
V_9 = - V_86 ;
break;
}
}
if ( ! V_9 && ( V_7 -> V_67 == V_97 ) )
V_9 = - V_86 ;
else if ( V_7 -> V_19 == V_62 )
V_73 |= V_141 ;
else if ( V_7 -> V_19 == V_64 )
V_73 |= V_142 ;
F_29 ( V_89 , L_38 , ! V_9 ) ;
F_41 ( V_89 ) ;
return V_9 ;
}
T_4 F_42 ( char * V_14 )
{
static const char V_143 [] = L_39 ;
char * V_93 ;
struct V_6 * V_7 ;
T_4 V_9 , V_144 ;
int V_145 = 0 ;
V_93 = F_33 ( & V_14 , L_40 ) ;
V_144 = strlen ( V_93 ) + 1 ;
V_93 += strspn ( V_93 , L_4 ) ;
if ( * V_93 == '#' || * V_93 == '\0' )
return V_144 ;
V_7 = F_43 ( sizeof( * V_7 ) , V_94 ) ;
if ( ! V_7 ) {
F_44 ( V_146 , NULL ,
NULL , V_143 , L_41 , - V_87 , V_145 ) ;
return - V_87 ;
}
F_45 ( & V_7 -> V_78 ) ;
V_9 = F_31 ( V_93 , V_7 ) ;
if ( V_9 ) {
F_27 ( V_7 ) ;
F_44 ( V_146 , NULL ,
NULL , V_143 , L_42 , V_9 ,
V_145 ) ;
return V_9 ;
}
F_5 ( & V_11 ) ;
F_23 ( & V_7 -> V_78 , & V_83 ) ;
F_9 ( & V_11 ) ;
return V_144 ;
}
void F_46 ( void )
{
struct V_6 * V_7 , * V_8 ;
int V_10 ;
F_5 ( & V_11 ) ;
F_6 (entry, tmp, &ima_policy_rules, list) {
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ )
F_27 ( V_7 -> V_13 [ V_10 ] . V_16 ) ;
F_47 ( & V_7 -> V_78 ) ;
F_27 ( V_7 ) ;
}
F_9 ( & V_11 ) ;
}
