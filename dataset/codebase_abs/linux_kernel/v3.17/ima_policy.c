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
void T_1 F_18 ( void )
{
int V_8 , V_65 , V_66 ;
V_65 = V_2 ? F_19 ( V_67 ) : 0 ;
V_66 = V_3 ?
F_19 ( V_68 ) : 0 ;
for ( V_8 = 0 ; V_8 < V_65 + V_66 ; V_8 ++ ) {
if ( V_8 < V_65 )
F_20 ( & V_67 [ V_8 ] . V_69 ,
& V_70 ) ;
else {
int V_71 = V_8 - V_65 ;
F_20 ( & V_68 [ V_71 ] . V_69 ,
& V_70 ) ;
}
}
V_72 = & V_70 ;
}
void F_21 ( void )
{
static const char V_73 [] = L_1 ;
const char * V_74 = L_2 ;
int V_7 = 1 ;
int V_75 = 0 ;
if ( V_72 == & V_70 ) {
V_72 = & V_76 ;
V_74 = L_3 ;
V_7 = 0 ;
}
F_22 ( V_77 , NULL ,
NULL , V_73 , V_74 , V_7 , V_75 ) ;
}
static int F_23 ( struct V_4 * V_5 ,
T_3 * args , int V_78 , int V_79 )
{
int V_7 ;
if ( V_5 -> V_11 [ V_78 ] . V_12 )
return - V_80 ;
V_5 -> V_11 [ V_78 ] . V_14 = F_24 ( args ) ;
if ( ! V_5 -> V_11 [ V_78 ] . V_14 )
return - V_81 ;
V_5 -> V_11 [ V_78 ] . type = V_79 ;
V_7 = F_6 ( V_5 -> V_11 [ V_78 ] . type ,
V_13 ,
V_5 -> V_11 [ V_78 ] . V_14 ,
& V_5 -> V_11 [ V_78 ] . V_12 ) ;
if ( ! V_5 -> V_11 [ V_78 ] . V_12 ) {
F_25 ( V_5 -> V_11 [ V_78 ] . V_14 ) ;
return - V_80 ;
}
return V_7 ;
}
static void F_26 ( struct V_82 * V_83 , char * V_84 , char * V_85 )
{
F_27 ( V_83 , L_4 , V_84 ) ;
F_28 ( V_83 , V_85 ) ;
F_27 ( V_83 , L_5 ) ;
}
static int F_29 ( char * V_12 , struct V_4 * V_5 )
{
struct V_82 * V_83 ;
char * V_86 ;
int V_7 = 0 ;
V_83 = F_30 ( NULL , V_87 , V_88 ) ;
V_5 -> V_35 = V_89 ;
V_5 -> V_37 = V_89 ;
V_5 -> V_60 = V_90 ;
while ( ( V_86 = F_31 ( & V_12 , L_6 ) ) != NULL ) {
T_3 args [ V_91 ] ;
int V_92 ;
unsigned long V_93 ;
if ( V_7 < 0 )
break;
if ( ( * V_86 == '\0' ) || ( * V_86 == ' ' ) || ( * V_86 == '\t' ) )
continue;
V_92 = F_32 ( V_86 , V_94 , args ) ;
switch ( V_92 ) {
case V_95 :
F_26 ( V_83 , L_7 , L_8 ) ;
if ( V_5 -> V_60 != V_90 )
V_7 = - V_80 ;
V_5 -> V_60 = V_96 ;
break;
case V_97 :
F_26 ( V_83 , L_7 , L_9 ) ;
if ( V_5 -> V_60 != V_90 )
V_7 = - V_80 ;
V_5 -> V_60 = V_98 ;
break;
case V_99 :
F_26 ( V_83 , L_7 , L_10 ) ;
if ( V_5 -> V_60 != V_90 )
V_7 = - V_80 ;
V_5 -> V_60 = V_100 ;
break;
case V_101 :
F_26 ( V_83 , L_7 , L_11 ) ;
if ( V_5 -> V_60 != V_90 )
V_7 = - V_80 ;
V_5 -> V_60 = V_102 ;
break;
case V_103 :
F_26 ( V_83 , L_7 , L_12 ) ;
if ( V_5 -> V_60 != V_90 )
V_7 = - V_80 ;
V_5 -> V_60 = V_104 ;
break;
case V_105 :
F_26 ( V_83 , L_13 , args [ 0 ] . V_106 ) ;
if ( V_5 -> V_17 )
V_7 = - V_80 ;
if ( strcmp ( args [ 0 ] . V_106 , L_14 ) == 0 )
V_5 -> V_17 = V_59 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_15 ) == 0 )
V_5 -> V_17 = V_59 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_16 ) == 0 )
V_5 -> V_17 = V_55 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_17 ) == 0 )
V_5 -> V_17 = V_57 ;
else if ( ( strcmp ( args [ 0 ] . V_106 , L_18 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_106 , L_19 ) == 0 ) )
V_5 -> V_17 = V_51 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_20 ) == 0 )
V_5 -> V_17 = V_53 ;
else
V_7 = - V_80 ;
if ( ! V_7 )
V_5 -> V_23 |= V_24 ;
break;
case V_107 :
F_26 ( V_83 , L_21 , args [ 0 ] . V_106 ) ;
if ( V_5 -> V_18 )
V_7 = - V_80 ;
if ( ( strcmp ( args [ 0 ] . V_106 , L_22 ) ) == 0 )
V_5 -> V_18 = V_108 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_23 ) == 0 )
V_5 -> V_18 = V_109 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_24 ) == 0 )
V_5 -> V_18 = V_110 ;
else if ( strcmp ( args [ 0 ] . V_106 , L_25 ) == 0 )
V_5 -> V_18 = V_111 ;
else
V_7 = - V_80 ;
if ( ! V_7 )
V_5 -> V_23 |= V_26 ;
break;
case V_112 :
F_26 ( V_83 , L_26 , args [ 0 ] . V_106 ) ;
if ( V_5 -> V_28 ) {
V_7 = - V_80 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_106 , 16 , & V_5 -> V_28 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_27 ;
break;
case V_113 :
F_26 ( V_83 , L_27 , args [ 0 ] . V_106 ) ;
if ( F_34 ( V_5 -> V_32 , 0x00 ,
sizeof( V_5 -> V_32 ) ) ) {
V_7 = - V_80 ;
break;
}
V_7 = F_35 ( args [ 0 ] . V_106 ,
V_5 -> V_32 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_31 ;
break;
case V_114 :
F_26 ( V_83 , L_28 , args [ 0 ] . V_106 ) ;
if ( F_36 ( V_5 -> V_35 ) ) {
V_7 = - V_80 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_106 , 10 , & V_93 ) ;
if ( ! V_7 ) {
V_5 -> V_35 = F_37 ( F_38 () , ( V_115 ) V_93 ) ;
if ( ! F_36 ( V_5 -> V_35 ) || ( ( ( V_115 ) V_93 ) != V_93 ) )
V_7 = - V_80 ;
else
V_5 -> V_23 |= V_34 ;
}
break;
case V_116 :
F_26 ( V_83 , L_29 , args [ 0 ] . V_106 ) ;
if ( F_36 ( V_5 -> V_37 ) ) {
V_7 = - V_80 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_106 , 10 , & V_93 ) ;
if ( ! V_7 ) {
V_5 -> V_37 = F_37 ( F_38 () , ( V_115 ) V_93 ) ;
if ( ! F_36 ( V_5 -> V_37 ) || ( ( ( V_115 ) V_93 ) != V_93 ) )
V_7 = - V_80 ;
else
V_5 -> V_23 |= V_36 ;
}
break;
case V_117 :
F_26 ( V_83 , L_30 , args [ 0 ] . V_106 ) ;
V_7 = F_23 ( V_5 , args ,
V_44 ,
V_118 ) ;
break;
case V_119 :
F_26 ( V_83 , L_31 , args [ 0 ] . V_106 ) ;
V_7 = F_23 ( V_5 , args ,
V_45 ,
V_120 ) ;
break;
case V_121 :
F_26 ( V_83 , L_32 , args [ 0 ] . V_106 ) ;
V_7 = F_23 ( V_5 , args ,
V_46 ,
V_122 ) ;
break;
case V_123 :
F_26 ( V_83 , L_33 , args [ 0 ] . V_106 ) ;
V_7 = F_23 ( V_5 , args ,
V_47 ,
V_124 ) ;
break;
case V_125 :
F_26 ( V_83 , L_34 , args [ 0 ] . V_106 ) ;
V_7 = F_23 ( V_5 , args ,
V_48 ,
V_126 ) ;
break;
case V_127 :
F_26 ( V_83 , L_35 , args [ 0 ] . V_106 ) ;
V_7 = F_23 ( V_5 , args ,
V_49 ,
V_128 ) ;
break;
case V_129 :
if ( V_5 -> V_60 != V_100 ) {
V_7 = - V_80 ;
break;
}
F_26 ( V_83 , L_36 , args [ 0 ] . V_106 ) ;
if ( ( strcmp ( args [ 0 ] . V_106 , L_37 ) ) == 0 )
V_5 -> V_23 |= V_130 ;
else
V_7 = - V_80 ;
break;
case V_131 :
V_5 -> V_23 |= V_132 ;
break;
case V_133 :
F_26 ( V_83 , L_38 , V_86 ) ;
V_7 = - V_80 ;
break;
}
}
if ( ! V_7 && ( V_5 -> V_60 == V_90 ) )
V_7 = - V_80 ;
else if ( V_5 -> V_17 == V_55 )
V_134 |= V_135 ;
else if ( V_5 -> V_17 == V_57 )
V_134 |= V_136 ;
F_27 ( V_83 , L_39 , ! V_7 ) ;
F_39 ( V_83 ) ;
return V_7 ;
}
T_4 F_40 ( char * V_12 )
{
static const char V_73 [] = L_40 ;
char * V_86 ;
struct V_4 * V_5 ;
T_4 V_7 , V_137 ;
int V_75 = 0 ;
if ( V_72 != & V_70 ) {
F_22 ( V_77 , NULL ,
NULL , V_73 , L_2 ,
- V_138 , V_75 ) ;
return - V_138 ;
}
V_5 = F_41 ( sizeof( * V_5 ) , V_87 ) ;
if ( ! V_5 ) {
F_22 ( V_77 , NULL ,
NULL , V_73 , L_41 , - V_81 , V_75 ) ;
return - V_81 ;
}
F_42 ( & V_5 -> V_69 ) ;
V_86 = F_31 ( & V_12 , L_42 ) ;
V_137 = strlen ( V_86 ) + 1 ;
if ( * V_86 == '#' ) {
F_25 ( V_5 ) ;
return V_137 ;
}
V_7 = F_29 ( V_86 , V_5 ) ;
if ( V_7 ) {
F_25 ( V_5 ) ;
F_22 ( V_77 , NULL ,
NULL , V_73 , L_43 , V_7 ,
V_75 ) ;
return V_7 ;
}
F_4 ( & V_9 ) ;
F_20 ( & V_5 -> V_69 , & V_76 ) ;
F_8 ( & V_9 ) ;
return V_137 ;
}
void F_43 ( void )
{
struct V_4 * V_5 , * V_6 ;
int V_8 ;
F_4 ( & V_9 ) ;
F_5 (entry, tmp, &ima_policy_rules, list) {
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
F_25 ( V_5 -> V_11 [ V_8 ] . V_14 ) ;
F_44 ( & V_5 -> V_69 ) ;
F_25 ( V_5 ) ;
}
F_8 ( & V_9 ) ;
}
