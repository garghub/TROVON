static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_3 = 1 ;
return 1 ;
}
static void F_3 ( void )
{
struct V_4 * V_5 , * V_6 ;
int V_7 ;
int V_8 ;
F_4 ( & V_9 ) ;
F_5 (entry, tmp, &ima_policy_rules, list) {
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
if ( ! V_5 -> V_11 [ V_8 ] . V_12 )
continue;
V_7 = F_6 ( V_5 -> V_11 [ V_8 ] . type ,
V_13 ,
V_5 -> V_11 [ V_8 ] . V_14 ,
& V_5 -> V_11 [ V_8 ] . V_12 ) ;
F_7 ( ! V_5 -> V_11 [ V_8 ] . V_12 ) ;
}
}
F_8 ( & V_9 ) ;
}
static bool F_9 ( struct V_4 * V_12 ,
struct V_15 * V_15 , enum V_16 V_17 , int V_18 )
{
struct V_19 * V_20 = V_21 ;
const struct V_22 * V_22 = F_10 () ;
int V_8 ;
if ( ( V_12 -> V_23 & V_24 ) &&
( V_12 -> V_17 != V_17 && V_17 != V_25 ) )
return false ;
if ( ( V_12 -> V_23 & V_26 ) &&
( V_12 -> V_18 != V_18 && V_17 != V_25 ) )
return false ;
if ( ( V_12 -> V_23 & V_27 )
&& V_12 -> V_28 != V_15 -> V_29 -> V_30 )
return false ;
if ( ( V_12 -> V_23 & V_31 ) &&
memcmp ( V_12 -> V_32 , V_15 -> V_29 -> V_33 , sizeof( V_12 -> V_32 ) ) )
return false ;
if ( ( V_12 -> V_23 & V_34 ) && ! F_11 ( V_12 -> V_35 , V_22 -> V_35 ) )
return false ;
if ( ( V_12 -> V_23 & V_36 ) && ! F_11 ( V_12 -> V_37 , V_15 -> V_38 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
int V_39 = 0 ;
T_2 V_40 , V_41 ;
int V_42 = 0 ;
if ( ! V_12 -> V_11 [ V_8 ] . V_12 )
continue;
V_43:
switch ( V_8 ) {
case V_44 :
case V_45 :
case V_46 :
F_12 ( V_15 , & V_40 ) ;
V_39 = F_13 ( V_40 ,
V_12 -> V_11 [ V_8 ] . type ,
V_13 ,
V_12 -> V_11 [ V_8 ] . V_12 ,
NULL ) ;
break;
case V_47 :
case V_48 :
case V_49 :
F_14 ( V_20 , & V_41 ) ;
V_39 = F_13 ( V_41 ,
V_12 -> V_11 [ V_8 ] . type ,
V_13 ,
V_12 -> V_11 [ V_8 ] . V_12 ,
NULL ) ;
default:
break;
}
if ( ( V_39 < 0 ) && ( ! V_42 ) ) {
V_42 = 1 ;
F_3 () ;
goto V_43;
}
if ( ! V_39 )
return false ;
}
return true ;
}
static int F_15 ( struct V_4 * V_12 , int V_17 )
{
if ( ! ( V_12 -> V_23 & V_24 ) )
return V_50 ;
switch ( V_17 ) {
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
case V_57 :
default:
return V_50 ;
}
}
int F_16 ( struct V_15 * V_15 , enum V_16 V_17 , int V_18 ,
int V_23 )
{
struct V_4 * V_5 ;
int V_58 = 0 , V_59 = V_23 | ( V_23 << 1 ) ;
F_17 (entry, ima_rules, list) {
if ( ! ( V_5 -> V_58 & V_59 ) )
continue;
if ( ! F_9 ( V_5 , V_15 , V_17 , V_18 ) )
continue;
V_58 |= V_5 -> V_23 & V_60 ;
V_58 |= V_5 -> V_58 & V_61 ;
if ( V_5 -> V_58 & V_62 )
V_58 |= F_15 ( V_5 , V_17 ) ;
if ( V_5 -> V_58 & V_61 )
V_59 &= ~ ( V_5 -> V_58 | V_5 -> V_58 << 1 ) ;
else
V_59 &= ~ ( V_5 -> V_58 | V_5 -> V_58 >> 1 ) ;
if ( ! V_59 )
break;
}
return V_58 ;
}
void T_1 F_18 ( void )
{
int V_8 , V_63 , V_64 ;
V_63 = V_2 ? F_19 ( V_65 ) : 0 ;
V_64 = V_3 ?
F_19 ( V_66 ) : 0 ;
for ( V_8 = 0 ; V_8 < V_63 + V_64 ; V_8 ++ ) {
if ( V_8 < V_63 )
F_20 ( & V_65 [ V_8 ] . V_67 ,
& V_68 ) ;
else {
int V_69 = V_8 - V_63 ;
F_20 ( & V_66 [ V_69 ] . V_67 ,
& V_68 ) ;
}
}
V_70 = & V_68 ;
}
void F_21 ( void )
{
static const char V_71 [] = L_1 ;
const char * V_72 = L_2 ;
int V_7 = 1 ;
int V_73 = 0 ;
if ( V_70 == & V_68 ) {
V_70 = & V_74 ;
V_72 = L_3 ;
V_7 = 0 ;
}
F_22 ( V_75 , NULL ,
NULL , V_71 , V_72 , V_7 , V_73 ) ;
}
static int F_23 ( struct V_4 * V_5 ,
T_3 * args , int V_76 , int V_77 )
{
int V_7 ;
if ( V_5 -> V_11 [ V_76 ] . V_12 )
return - V_78 ;
V_5 -> V_11 [ V_76 ] . V_14 = F_24 ( args ) ;
if ( ! V_5 -> V_11 [ V_76 ] . V_14 )
return - V_79 ;
V_5 -> V_11 [ V_76 ] . type = V_77 ;
V_7 = F_6 ( V_5 -> V_11 [ V_76 ] . type ,
V_13 ,
V_5 -> V_11 [ V_76 ] . V_14 ,
& V_5 -> V_11 [ V_76 ] . V_12 ) ;
if ( ! V_5 -> V_11 [ V_76 ] . V_12 ) {
F_25 ( V_5 -> V_11 [ V_76 ] . V_14 ) ;
return - V_78 ;
}
return V_7 ;
}
static void F_26 ( struct V_80 * V_81 , char * V_82 , char * V_83 )
{
F_27 ( V_81 , L_4 , V_82 ) ;
F_28 ( V_81 , V_83 ) ;
F_27 ( V_81 , L_5 ) ;
}
static int F_29 ( char * V_12 , struct V_4 * V_5 )
{
struct V_80 * V_81 ;
char * V_84 ;
int V_7 = 0 ;
V_81 = F_30 ( NULL , V_85 , V_86 ) ;
V_5 -> V_35 = V_87 ;
V_5 -> V_37 = V_87 ;
V_5 -> V_58 = V_88 ;
while ( ( V_84 = F_31 ( & V_12 , L_6 ) ) != NULL ) {
T_3 args [ V_89 ] ;
int V_90 ;
unsigned long V_91 ;
if ( V_7 < 0 )
break;
if ( ( * V_84 == '\0' ) || ( * V_84 == ' ' ) || ( * V_84 == '\t' ) )
continue;
V_90 = F_32 ( V_84 , V_92 , args ) ;
switch ( V_90 ) {
case V_93 :
F_26 ( V_81 , L_7 , L_8 ) ;
if ( V_5 -> V_58 != V_88 )
V_7 = - V_78 ;
V_5 -> V_58 = V_94 ;
break;
case V_95 :
F_26 ( V_81 , L_7 , L_9 ) ;
if ( V_5 -> V_58 != V_88 )
V_7 = - V_78 ;
V_5 -> V_58 = V_96 ;
break;
case V_97 :
F_26 ( V_81 , L_7 , L_10 ) ;
if ( V_5 -> V_58 != V_88 )
V_7 = - V_78 ;
V_5 -> V_58 = V_98 ;
break;
case V_99 :
F_26 ( V_81 , L_7 , L_11 ) ;
if ( V_5 -> V_58 != V_88 )
V_7 = - V_78 ;
V_5 -> V_58 = V_100 ;
break;
case V_101 :
F_26 ( V_81 , L_7 , L_12 ) ;
if ( V_5 -> V_58 != V_88 )
V_7 = - V_78 ;
V_5 -> V_58 = V_102 ;
break;
case V_103 :
F_26 ( V_81 , L_13 , args [ 0 ] . V_104 ) ;
if ( V_5 -> V_17 )
V_7 = - V_78 ;
if ( strcmp ( args [ 0 ] . V_104 , L_14 ) == 0 )
V_5 -> V_17 = V_57 ;
else if ( strcmp ( args [ 0 ] . V_104 , L_15 ) == 0 )
V_5 -> V_17 = V_57 ;
else if ( strcmp ( args [ 0 ] . V_104 , L_16 ) == 0 )
V_5 -> V_17 = V_55 ;
else if ( ( strcmp ( args [ 0 ] . V_104 , L_17 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_104 , L_18 ) == 0 ) )
V_5 -> V_17 = V_51 ;
else if ( strcmp ( args [ 0 ] . V_104 , L_19 ) == 0 )
V_5 -> V_17 = V_53 ;
else
V_7 = - V_78 ;
if ( ! V_7 )
V_5 -> V_23 |= V_24 ;
break;
case V_105 :
F_26 ( V_81 , L_20 , args [ 0 ] . V_104 ) ;
if ( V_5 -> V_18 )
V_7 = - V_78 ;
if ( ( strcmp ( args [ 0 ] . V_104 , L_21 ) ) == 0 )
V_5 -> V_18 = V_106 ;
else if ( strcmp ( args [ 0 ] . V_104 , L_22 ) == 0 )
V_5 -> V_18 = V_107 ;
else if ( strcmp ( args [ 0 ] . V_104 , L_23 ) == 0 )
V_5 -> V_18 = V_108 ;
else if ( strcmp ( args [ 0 ] . V_104 , L_24 ) == 0 )
V_5 -> V_18 = V_109 ;
else
V_7 = - V_78 ;
if ( ! V_7 )
V_5 -> V_23 |= V_26 ;
break;
case V_110 :
F_26 ( V_81 , L_25 , args [ 0 ] . V_104 ) ;
if ( V_5 -> V_28 ) {
V_7 = - V_78 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_104 , 16 , & V_5 -> V_28 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_27 ;
break;
case V_111 :
F_26 ( V_81 , L_26 , args [ 0 ] . V_104 ) ;
if ( F_34 ( V_5 -> V_32 , 0x00 ,
sizeof( V_5 -> V_32 ) ) ) {
V_7 = - V_78 ;
break;
}
V_7 = F_35 ( args [ 0 ] . V_104 ,
V_5 -> V_32 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_31 ;
break;
case V_112 :
F_26 ( V_81 , L_27 , args [ 0 ] . V_104 ) ;
if ( F_36 ( V_5 -> V_35 ) ) {
V_7 = - V_78 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_104 , 10 , & V_91 ) ;
if ( ! V_7 ) {
V_5 -> V_35 = F_37 ( F_38 () , ( V_113 ) V_91 ) ;
if ( ! F_36 ( V_5 -> V_35 ) || ( ( ( V_113 ) V_91 ) != V_91 ) )
V_7 = - V_78 ;
else
V_5 -> V_23 |= V_34 ;
}
break;
case V_114 :
F_26 ( V_81 , L_28 , args [ 0 ] . V_104 ) ;
if ( F_36 ( V_5 -> V_37 ) ) {
V_7 = - V_78 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_104 , 10 , & V_91 ) ;
if ( ! V_7 ) {
V_5 -> V_37 = F_37 ( F_38 () , ( V_113 ) V_91 ) ;
if ( ! F_36 ( V_5 -> V_37 ) || ( ( ( V_113 ) V_91 ) != V_91 ) )
V_7 = - V_78 ;
else
V_5 -> V_23 |= V_36 ;
}
break;
case V_115 :
F_26 ( V_81 , L_29 , args [ 0 ] . V_104 ) ;
V_7 = F_23 ( V_5 , args ,
V_44 ,
V_116 ) ;
break;
case V_117 :
F_26 ( V_81 , L_30 , args [ 0 ] . V_104 ) ;
V_7 = F_23 ( V_5 , args ,
V_45 ,
V_118 ) ;
break;
case V_119 :
F_26 ( V_81 , L_31 , args [ 0 ] . V_104 ) ;
V_7 = F_23 ( V_5 , args ,
V_46 ,
V_120 ) ;
break;
case V_121 :
F_26 ( V_81 , L_32 , args [ 0 ] . V_104 ) ;
V_7 = F_23 ( V_5 , args ,
V_47 ,
V_122 ) ;
break;
case V_123 :
F_26 ( V_81 , L_33 , args [ 0 ] . V_104 ) ;
V_7 = F_23 ( V_5 , args ,
V_48 ,
V_124 ) ;
break;
case V_125 :
F_26 ( V_81 , L_34 , args [ 0 ] . V_104 ) ;
V_7 = F_23 ( V_5 , args ,
V_49 ,
V_126 ) ;
break;
case V_127 :
if ( V_5 -> V_58 != V_98 ) {
V_7 = - V_78 ;
break;
}
F_26 ( V_81 , L_35 , args [ 0 ] . V_104 ) ;
if ( ( strcmp ( args [ 0 ] . V_104 , L_36 ) ) == 0 )
V_5 -> V_23 |= V_128 ;
else
V_7 = - V_78 ;
break;
case V_129 :
F_26 ( V_81 , L_37 , V_84 ) ;
V_7 = - V_78 ;
break;
}
}
if ( ! V_7 && ( V_5 -> V_58 == V_88 ) )
V_7 = - V_78 ;
else if ( V_5 -> V_17 == V_55 )
V_130 |= V_131 ;
F_27 ( V_81 , L_38 , ! V_7 ) ;
F_39 ( V_81 ) ;
return V_7 ;
}
T_4 F_40 ( char * V_12 )
{
static const char V_71 [] = L_39 ;
char * V_84 ;
struct V_4 * V_5 ;
T_4 V_7 , V_132 ;
int V_73 = 0 ;
if ( V_70 != & V_68 ) {
F_22 ( V_75 , NULL ,
NULL , V_71 , L_2 ,
- V_133 , V_73 ) ;
return - V_133 ;
}
V_5 = F_41 ( sizeof( * V_5 ) , V_85 ) ;
if ( ! V_5 ) {
F_22 ( V_75 , NULL ,
NULL , V_71 , L_40 , - V_79 , V_73 ) ;
return - V_79 ;
}
F_42 ( & V_5 -> V_67 ) ;
V_84 = F_31 ( & V_12 , L_41 ) ;
V_132 = strlen ( V_84 ) + 1 ;
if ( * V_84 == '#' ) {
F_25 ( V_5 ) ;
return V_132 ;
}
V_7 = F_29 ( V_84 , V_5 ) ;
if ( V_7 ) {
F_25 ( V_5 ) ;
F_22 ( V_75 , NULL ,
NULL , V_71 , L_42 , V_7 ,
V_73 ) ;
return V_7 ;
}
F_4 ( & V_9 ) ;
F_20 ( & V_5 -> V_67 , & V_74 ) ;
F_8 ( & V_9 ) ;
return V_132 ;
}
void F_43 ( void )
{
struct V_4 * V_5 , * V_6 ;
int V_8 ;
F_4 ( & V_9 ) ;
F_5 (entry, tmp, &ima_policy_rules, list) {
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
F_25 ( V_5 -> V_11 [ V_8 ] . V_14 ) ;
F_44 ( & V_5 -> V_67 ) ;
F_25 ( V_5 ) ;
}
F_8 ( & V_9 ) ;
}
