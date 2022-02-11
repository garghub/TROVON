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
return V_58 ;
case V_59 :
default:
return V_50 ;
}
}
int F_16 ( struct V_15 * V_15 , enum V_16 V_17 , int V_18 ,
int V_23 )
{
struct V_4 * V_5 ;
int V_60 = 0 , V_61 = V_23 | ( V_23 << 1 ) ;
F_17 (entry, ima_rules, list) {
if ( ! ( V_5 -> V_60 & V_61 ) )
continue;
if ( ! F_9 ( V_5 , V_15 , V_17 , V_18 ) )
continue;
V_60 |= V_5 -> V_23 & V_62 ;
V_60 |= V_5 -> V_60 & V_63 ;
if ( V_5 -> V_60 & V_64 )
V_60 |= F_15 ( V_5 , V_17 ) ;
if ( V_5 -> V_60 & V_63 )
V_61 &= ~ ( V_5 -> V_60 | V_5 -> V_60 << 1 ) ;
else
V_61 &= ~ ( V_5 -> V_60 | V_5 -> V_60 >> 1 ) ;
if ( ! V_61 )
break;
}
return V_60 ;
}
void F_18 ( void )
{
struct V_4 * V_5 ;
V_65 = 0 ;
F_17 (entry, ima_rules, list) {
if ( V_5 -> V_60 & V_63 )
V_65 |= V_5 -> V_60 ;
}
if ( ! V_66 )
V_65 &= ~ V_64 ;
}
void T_1 F_19 ( void )
{
int V_8 , V_67 , V_68 ;
V_67 = V_2 ? F_20 ( V_69 ) : 0 ;
V_68 = V_3 ?
F_20 ( V_70 ) : 0 ;
for ( V_8 = 0 ; V_8 < V_67 + V_68 ; V_8 ++ ) {
if ( V_8 < V_67 )
F_21 ( & V_69 [ V_8 ] . V_71 ,
& V_72 ) ;
else {
int V_73 = V_8 - V_67 ;
F_21 ( & V_70 [ V_73 ] . V_71 ,
& V_72 ) ;
}
}
V_74 = & V_72 ;
}
void F_22 ( void )
{
static const char V_75 [] = L_1 ;
const char * V_76 = L_2 ;
int V_7 = 1 ;
int V_77 = 0 ;
if ( V_74 == & V_72 ) {
V_74 = & V_78 ;
F_18 () ;
V_76 = L_3 ;
V_7 = 0 ;
}
F_23 ( V_79 , NULL ,
NULL , V_75 , V_76 , V_7 , V_77 ) ;
}
static int F_24 ( struct V_4 * V_5 ,
T_3 * args , int V_80 , int V_81 )
{
int V_7 ;
if ( V_5 -> V_11 [ V_80 ] . V_12 )
return - V_82 ;
V_5 -> V_11 [ V_80 ] . V_14 = F_25 ( args ) ;
if ( ! V_5 -> V_11 [ V_80 ] . V_14 )
return - V_83 ;
V_5 -> V_11 [ V_80 ] . type = V_81 ;
V_7 = F_6 ( V_5 -> V_11 [ V_80 ] . type ,
V_13 ,
V_5 -> V_11 [ V_80 ] . V_14 ,
& V_5 -> V_11 [ V_80 ] . V_12 ) ;
if ( ! V_5 -> V_11 [ V_80 ] . V_12 ) {
F_26 ( V_5 -> V_11 [ V_80 ] . V_14 ) ;
return - V_82 ;
}
return V_7 ;
}
static void F_27 ( struct V_84 * V_85 , char * V_86 , char * V_87 )
{
F_28 ( V_85 , L_4 , V_86 ) ;
F_29 ( V_85 , V_87 ) ;
F_28 ( V_85 , L_5 ) ;
}
static int F_30 ( char * V_12 , struct V_4 * V_5 )
{
struct V_84 * V_85 ;
char * V_88 ;
int V_7 = 0 ;
V_85 = F_31 ( NULL , V_89 , V_90 ) ;
V_5 -> V_35 = V_91 ;
V_5 -> V_37 = V_91 ;
V_5 -> V_60 = V_92 ;
while ( ( V_88 = F_32 ( & V_12 , L_6 ) ) != NULL ) {
T_3 args [ V_93 ] ;
int V_94 ;
unsigned long V_95 ;
if ( V_7 < 0 )
break;
if ( ( * V_88 == '\0' ) || ( * V_88 == ' ' ) || ( * V_88 == '\t' ) )
continue;
V_94 = F_33 ( V_88 , V_96 , args ) ;
switch ( V_94 ) {
case V_97 :
F_27 ( V_85 , L_7 , L_8 ) ;
if ( V_5 -> V_60 != V_92 )
V_7 = - V_82 ;
V_5 -> V_60 = V_98 ;
break;
case V_99 :
F_27 ( V_85 , L_7 , L_9 ) ;
if ( V_5 -> V_60 != V_92 )
V_7 = - V_82 ;
V_5 -> V_60 = V_100 ;
break;
case V_101 :
F_27 ( V_85 , L_7 , L_10 ) ;
if ( V_5 -> V_60 != V_92 )
V_7 = - V_82 ;
V_5 -> V_60 = V_102 ;
break;
case V_103 :
F_27 ( V_85 , L_7 , L_11 ) ;
if ( V_5 -> V_60 != V_92 )
V_7 = - V_82 ;
V_5 -> V_60 = V_104 ;
break;
case V_105 :
F_27 ( V_85 , L_7 , L_12 ) ;
if ( V_5 -> V_60 != V_92 )
V_7 = - V_82 ;
V_5 -> V_60 = V_106 ;
break;
case V_107 :
F_27 ( V_85 , L_13 , args [ 0 ] . V_108 ) ;
if ( V_5 -> V_17 )
V_7 = - V_82 ;
if ( strcmp ( args [ 0 ] . V_108 , L_14 ) == 0 )
V_5 -> V_17 = V_59 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_15 ) == 0 )
V_5 -> V_17 = V_59 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_16 ) == 0 )
V_5 -> V_17 = V_55 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_17 ) == 0 )
V_5 -> V_17 = V_57 ;
else if ( ( strcmp ( args [ 0 ] . V_108 , L_18 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_108 , L_19 ) == 0 ) )
V_5 -> V_17 = V_51 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_20 ) == 0 )
V_5 -> V_17 = V_53 ;
else
V_7 = - V_82 ;
if ( ! V_7 )
V_5 -> V_23 |= V_24 ;
break;
case V_109 :
F_27 ( V_85 , L_21 , args [ 0 ] . V_108 ) ;
if ( V_5 -> V_18 )
V_7 = - V_82 ;
if ( ( strcmp ( args [ 0 ] . V_108 , L_22 ) ) == 0 )
V_5 -> V_18 = V_110 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_23 ) == 0 )
V_5 -> V_18 = V_111 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_24 ) == 0 )
V_5 -> V_18 = V_112 ;
else if ( strcmp ( args [ 0 ] . V_108 , L_25 ) == 0 )
V_5 -> V_18 = V_113 ;
else
V_7 = - V_82 ;
if ( ! V_7 )
V_5 -> V_23 |= V_26 ;
break;
case V_114 :
F_27 ( V_85 , L_26 , args [ 0 ] . V_108 ) ;
if ( V_5 -> V_28 ) {
V_7 = - V_82 ;
break;
}
V_7 = F_34 ( args [ 0 ] . V_108 , 16 , & V_5 -> V_28 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_27 ;
break;
case V_115 :
F_27 ( V_85 , L_27 , args [ 0 ] . V_108 ) ;
if ( F_35 ( V_5 -> V_32 , 0x00 ,
sizeof( V_5 -> V_32 ) ) ) {
V_7 = - V_82 ;
break;
}
V_7 = F_36 ( args [ 0 ] . V_108 ,
V_5 -> V_32 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_31 ;
break;
case V_116 :
F_27 ( V_85 , L_28 , args [ 0 ] . V_108 ) ;
if ( F_37 ( V_5 -> V_35 ) ) {
V_7 = - V_82 ;
break;
}
V_7 = F_34 ( args [ 0 ] . V_108 , 10 , & V_95 ) ;
if ( ! V_7 ) {
V_5 -> V_35 = F_38 ( F_39 () , ( V_117 ) V_95 ) ;
if ( ! F_37 ( V_5 -> V_35 ) || ( ( ( V_117 ) V_95 ) != V_95 ) )
V_7 = - V_82 ;
else
V_5 -> V_23 |= V_34 ;
}
break;
case V_118 :
F_27 ( V_85 , L_29 , args [ 0 ] . V_108 ) ;
if ( F_37 ( V_5 -> V_37 ) ) {
V_7 = - V_82 ;
break;
}
V_7 = F_34 ( args [ 0 ] . V_108 , 10 , & V_95 ) ;
if ( ! V_7 ) {
V_5 -> V_37 = F_38 ( F_39 () , ( V_117 ) V_95 ) ;
if ( ! F_37 ( V_5 -> V_37 ) || ( ( ( V_117 ) V_95 ) != V_95 ) )
V_7 = - V_82 ;
else
V_5 -> V_23 |= V_36 ;
}
break;
case V_119 :
F_27 ( V_85 , L_30 , args [ 0 ] . V_108 ) ;
V_7 = F_24 ( V_5 , args ,
V_44 ,
V_120 ) ;
break;
case V_121 :
F_27 ( V_85 , L_31 , args [ 0 ] . V_108 ) ;
V_7 = F_24 ( V_5 , args ,
V_45 ,
V_122 ) ;
break;
case V_123 :
F_27 ( V_85 , L_32 , args [ 0 ] . V_108 ) ;
V_7 = F_24 ( V_5 , args ,
V_46 ,
V_124 ) ;
break;
case V_125 :
F_27 ( V_85 , L_33 , args [ 0 ] . V_108 ) ;
V_7 = F_24 ( V_5 , args ,
V_47 ,
V_126 ) ;
break;
case V_127 :
F_27 ( V_85 , L_34 , args [ 0 ] . V_108 ) ;
V_7 = F_24 ( V_5 , args ,
V_48 ,
V_128 ) ;
break;
case V_129 :
F_27 ( V_85 , L_35 , args [ 0 ] . V_108 ) ;
V_7 = F_24 ( V_5 , args ,
V_49 ,
V_130 ) ;
break;
case V_131 :
if ( V_5 -> V_60 != V_102 ) {
V_7 = - V_82 ;
break;
}
F_27 ( V_85 , L_36 , args [ 0 ] . V_108 ) ;
if ( ( strcmp ( args [ 0 ] . V_108 , L_37 ) ) == 0 )
V_5 -> V_23 |= V_132 ;
else
V_7 = - V_82 ;
break;
case V_133 :
V_5 -> V_23 |= V_134 ;
break;
case V_135 :
F_27 ( V_85 , L_38 , V_88 ) ;
V_7 = - V_82 ;
break;
}
}
if ( ! V_7 && ( V_5 -> V_60 == V_92 ) )
V_7 = - V_82 ;
else if ( V_5 -> V_17 == V_55 )
V_66 |= V_136 ;
else if ( V_5 -> V_17 == V_57 )
V_66 |= V_137 ;
F_28 ( V_85 , L_39 , ! V_7 ) ;
F_40 ( V_85 ) ;
return V_7 ;
}
T_4 F_41 ( char * V_12 )
{
static const char V_75 [] = L_40 ;
char * V_88 ;
struct V_4 * V_5 ;
T_4 V_7 , V_138 ;
int V_77 = 0 ;
if ( V_74 != & V_72 ) {
F_23 ( V_79 , NULL ,
NULL , V_75 , L_2 ,
- V_139 , V_77 ) ;
return - V_139 ;
}
V_5 = F_42 ( sizeof( * V_5 ) , V_89 ) ;
if ( ! V_5 ) {
F_23 ( V_79 , NULL ,
NULL , V_75 , L_41 , - V_83 , V_77 ) ;
return - V_83 ;
}
F_43 ( & V_5 -> V_71 ) ;
V_88 = F_32 ( & V_12 , L_42 ) ;
V_138 = strlen ( V_88 ) + 1 ;
if ( * V_88 == '#' ) {
F_26 ( V_5 ) ;
return V_138 ;
}
V_7 = F_30 ( V_88 , V_5 ) ;
if ( V_7 ) {
F_26 ( V_5 ) ;
F_23 ( V_79 , NULL ,
NULL , V_75 , L_43 , V_7 ,
V_77 ) ;
return V_7 ;
}
F_4 ( & V_9 ) ;
F_21 ( & V_5 -> V_71 , & V_78 ) ;
F_8 ( & V_9 ) ;
return V_138 ;
}
void F_44 ( void )
{
struct V_4 * V_5 , * V_6 ;
int V_8 ;
F_4 ( & V_9 ) ;
F_5 (entry, tmp, &ima_policy_rules, list) {
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
F_26 ( V_5 -> V_11 [ V_8 ] . V_14 ) ;
F_45 ( & V_5 -> V_71 ) ;
F_26 ( V_5 ) ;
}
F_8 ( & V_9 ) ;
}
