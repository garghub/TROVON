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
if ( ( V_12 -> V_23 & V_24 ) && V_12 -> V_17 != V_17 )
return false ;
if ( ( V_12 -> V_23 & V_25 ) && V_12 -> V_18 != V_18 )
return false ;
if ( ( V_12 -> V_23 & V_26 )
&& V_12 -> V_27 != V_15 -> V_28 -> V_29 )
return false ;
if ( ( V_12 -> V_23 & V_30 ) &&
memcmp ( V_12 -> V_31 , V_15 -> V_28 -> V_32 , sizeof( V_12 -> V_31 ) ) )
return false ;
if ( ( V_12 -> V_23 & V_33 ) && ! F_11 ( V_12 -> V_34 , V_22 -> V_34 ) )
return false ;
if ( ( V_12 -> V_23 & V_35 ) && ! F_11 ( V_12 -> V_36 , V_15 -> V_37 ) )
return false ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
int V_38 = 0 ;
T_2 V_39 , V_40 ;
int V_41 = 0 ;
if ( ! V_12 -> V_11 [ V_8 ] . V_12 )
continue;
V_42:
switch ( V_8 ) {
case V_43 :
case V_44 :
case V_45 :
F_12 ( V_15 , & V_39 ) ;
V_38 = F_13 ( V_39 ,
V_12 -> V_11 [ V_8 ] . type ,
V_13 ,
V_12 -> V_11 [ V_8 ] . V_12 ,
NULL ) ;
break;
case V_46 :
case V_47 :
case V_48 :
F_14 ( V_20 , & V_40 ) ;
V_38 = F_13 ( V_40 ,
V_12 -> V_11 [ V_8 ] . type ,
V_13 ,
V_12 -> V_11 [ V_8 ] . V_12 ,
NULL ) ;
default:
break;
}
if ( ( V_38 < 0 ) && ( ! V_41 ) ) {
V_41 = 1 ;
F_3 () ;
goto V_42;
}
if ( ! V_38 )
return false ;
}
return true ;
}
static int F_15 ( struct V_4 * V_12 , int V_17 )
{
if ( ! ( V_12 -> V_23 & V_24 ) )
return V_49 ;
switch( V_17 ) {
case V_50 :
return V_51 ;
case V_52 :
return V_53 ;
case V_54 :
return V_55 ;
case V_56 :
default:
return V_49 ;
}
}
int F_16 ( struct V_15 * V_15 , enum V_16 V_17 , int V_18 ,
int V_23 )
{
struct V_4 * V_5 ;
int V_57 = 0 , V_58 = V_23 | ( V_23 << 1 ) ;
F_17 (entry, ima_rules, list) {
if ( ! ( V_5 -> V_57 & V_58 ) )
continue;
if ( ! F_9 ( V_5 , V_15 , V_17 , V_18 ) )
continue;
V_57 |= V_5 -> V_23 & V_59 ;
V_57 |= V_5 -> V_57 & V_60 ;
if ( V_5 -> V_57 & V_61 )
V_57 |= F_15 ( V_5 , V_17 ) ;
if ( V_5 -> V_57 & V_60 )
V_58 &= ~ ( V_5 -> V_57 | V_5 -> V_57 << 1 ) ;
else
V_58 &= ~ ( V_5 -> V_57 | V_5 -> V_57 >> 1 ) ;
if ( ! V_58 )
break;
}
return V_57 ;
}
void T_1 F_18 ( void )
{
int V_8 , V_62 , V_63 ;
V_62 = V_2 ? F_19 ( V_64 ) : 0 ;
V_63 = V_3 ?
F_19 ( V_65 ) : 0 ;
for ( V_8 = 0 ; V_8 < V_62 + V_63 ; V_8 ++ ) {
if ( V_8 < V_62 )
F_20 ( & V_64 [ V_8 ] . V_66 ,
& V_67 ) ;
else {
int V_68 = V_8 - V_62 ;
F_20 ( & V_65 [ V_68 ] . V_66 ,
& V_67 ) ;
}
}
V_69 = & V_67 ;
}
void F_21 ( void )
{
const char * V_70 = L_1 ;
const char * V_71 = L_2 ;
int V_7 = 1 ;
int V_72 = 0 ;
if ( V_69 == & V_67 ) {
V_69 = & V_73 ;
V_71 = L_3 ;
V_7 = 0 ;
}
F_22 ( V_74 , NULL ,
NULL , V_70 , V_71 , V_7 , V_72 ) ;
}
static int F_23 ( struct V_4 * V_5 ,
T_3 * args , int V_75 , int V_76 )
{
int V_7 ;
if ( V_5 -> V_11 [ V_75 ] . V_12 )
return - V_77 ;
V_5 -> V_11 [ V_75 ] . V_14 = F_24 ( args ) ;
if ( ! V_5 -> V_11 [ V_75 ] . V_14 )
return - V_78 ;
V_5 -> V_11 [ V_75 ] . type = V_76 ;
V_7 = F_6 ( V_5 -> V_11 [ V_75 ] . type ,
V_13 ,
V_5 -> V_11 [ V_75 ] . V_14 ,
& V_5 -> V_11 [ V_75 ] . V_12 ) ;
if ( ! V_5 -> V_11 [ V_75 ] . V_12 ) {
F_25 ( V_5 -> V_11 [ V_75 ] . V_14 ) ;
return - V_77 ;
}
return V_7 ;
}
static void F_26 ( struct V_79 * V_80 , char * V_81 , char * V_82 )
{
F_27 ( V_80 , L_4 , V_81 ) ;
F_28 ( V_80 , V_82 ) ;
F_27 ( V_80 , L_5 ) ;
}
static int F_29 ( char * V_12 , struct V_4 * V_5 )
{
struct V_79 * V_80 ;
char * V_83 ;
int V_7 = 0 ;
V_80 = F_30 ( NULL , V_84 , V_85 ) ;
V_5 -> V_34 = V_86 ;
V_5 -> V_36 = V_86 ;
V_5 -> V_57 = V_87 ;
while ( ( V_83 = F_31 ( & V_12 , L_6 ) ) != NULL ) {
T_3 args [ V_88 ] ;
int V_89 ;
unsigned long V_90 ;
if ( V_7 < 0 )
break;
if ( ( * V_83 == '\0' ) || ( * V_83 == ' ' ) || ( * V_83 == '\t' ) )
continue;
V_89 = F_32 ( V_83 , V_91 , args ) ;
switch ( V_89 ) {
case V_92 :
F_26 ( V_80 , L_7 , L_8 ) ;
if ( V_5 -> V_57 != V_87 )
V_7 = - V_77 ;
V_5 -> V_57 = V_93 ;
break;
case V_94 :
F_26 ( V_80 , L_7 , L_9 ) ;
if ( V_5 -> V_57 != V_87 )
V_7 = - V_77 ;
V_5 -> V_57 = V_95 ;
break;
case V_96 :
F_26 ( V_80 , L_7 , L_10 ) ;
if ( V_5 -> V_57 != V_87 )
V_7 = - V_77 ;
V_5 -> V_57 = V_97 ;
break;
case V_98 :
F_26 ( V_80 , L_7 , L_11 ) ;
if ( V_5 -> V_57 != V_87 )
V_7 = - V_77 ;
V_5 -> V_57 = V_99 ;
break;
case V_100 :
F_26 ( V_80 , L_7 , L_12 ) ;
if ( V_5 -> V_57 != V_87 )
V_7 = - V_77 ;
V_5 -> V_57 = V_101 ;
break;
case V_102 :
F_26 ( V_80 , L_13 , args [ 0 ] . V_103 ) ;
if ( V_5 -> V_17 )
V_7 = - V_77 ;
if ( strcmp ( args [ 0 ] . V_103 , L_14 ) == 0 )
V_5 -> V_17 = V_56 ;
else if ( strcmp ( args [ 0 ] . V_103 , L_15 ) == 0 )
V_5 -> V_17 = V_56 ;
else if ( strcmp ( args [ 0 ] . V_103 , L_16 ) == 0 )
V_5 -> V_17 = V_54 ;
else if ( ( strcmp ( args [ 0 ] . V_103 , L_17 ) == 0 )
|| ( strcmp ( args [ 0 ] . V_103 , L_18 ) == 0 ) )
V_5 -> V_17 = V_50 ;
else if ( strcmp ( args [ 0 ] . V_103 , L_19 ) == 0 )
V_5 -> V_17 = V_52 ;
else
V_7 = - V_77 ;
if ( ! V_7 )
V_5 -> V_23 |= V_24 ;
break;
case V_104 :
F_26 ( V_80 , L_20 , args [ 0 ] . V_103 ) ;
if ( V_5 -> V_18 )
V_7 = - V_77 ;
if ( ( strcmp ( args [ 0 ] . V_103 , L_21 ) ) == 0 )
V_5 -> V_18 = V_105 ;
else if ( strcmp ( args [ 0 ] . V_103 , L_22 ) == 0 )
V_5 -> V_18 = V_106 ;
else if ( strcmp ( args [ 0 ] . V_103 , L_23 ) == 0 )
V_5 -> V_18 = V_107 ;
else if ( strcmp ( args [ 0 ] . V_103 , L_24 ) == 0 )
V_5 -> V_18 = V_108 ;
else
V_7 = - V_77 ;
if ( ! V_7 )
V_5 -> V_23 |= V_25 ;
break;
case V_109 :
F_26 ( V_80 , L_25 , args [ 0 ] . V_103 ) ;
if ( V_5 -> V_27 ) {
V_7 = - V_77 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_103 , 16 ,
& V_5 -> V_27 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_26 ;
break;
case V_110 :
F_26 ( V_80 , L_26 , args [ 0 ] . V_103 ) ;
if ( F_34 ( V_5 -> V_31 , 0x00 ,
sizeof( V_5 -> V_31 ) ) ) {
V_7 = - V_77 ;
break;
}
V_7 = F_35 ( args [ 0 ] . V_103 ,
V_5 -> V_31 ) ;
if ( ! V_7 )
V_5 -> V_23 |= V_30 ;
break;
case V_111 :
F_26 ( V_80 , L_27 , args [ 0 ] . V_103 ) ;
if ( F_36 ( V_5 -> V_34 ) ) {
V_7 = - V_77 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_103 , 10 , & V_90 ) ;
if ( ! V_7 ) {
V_5 -> V_34 = F_37 ( F_38 () , ( V_112 ) V_90 ) ;
if ( ! F_36 ( V_5 -> V_34 ) || ( ( ( V_112 ) V_90 ) != V_90 ) )
V_7 = - V_77 ;
else
V_5 -> V_23 |= V_33 ;
}
break;
case V_113 :
F_26 ( V_80 , L_28 , args [ 0 ] . V_103 ) ;
if ( F_36 ( V_5 -> V_36 ) ) {
V_7 = - V_77 ;
break;
}
V_7 = F_33 ( args [ 0 ] . V_103 , 10 , & V_90 ) ;
if ( ! V_7 ) {
V_5 -> V_36 = F_37 ( F_38 () , ( V_112 ) V_90 ) ;
if ( ! F_36 ( V_5 -> V_36 ) || ( ( ( V_112 ) V_90 ) != V_90 ) )
V_7 = - V_77 ;
else
V_5 -> V_23 |= V_35 ;
}
break;
case V_114 :
F_26 ( V_80 , L_29 , args [ 0 ] . V_103 ) ;
V_7 = F_23 ( V_5 , args ,
V_43 ,
V_115 ) ;
break;
case V_116 :
F_26 ( V_80 , L_30 , args [ 0 ] . V_103 ) ;
V_7 = F_23 ( V_5 , args ,
V_44 ,
V_117 ) ;
break;
case V_118 :
F_26 ( V_80 , L_31 , args [ 0 ] . V_103 ) ;
V_7 = F_23 ( V_5 , args ,
V_45 ,
V_119 ) ;
break;
case V_120 :
F_26 ( V_80 , L_32 , args [ 0 ] . V_103 ) ;
V_7 = F_23 ( V_5 , args ,
V_46 ,
V_121 ) ;
break;
case V_122 :
F_26 ( V_80 , L_33 , args [ 0 ] . V_103 ) ;
V_7 = F_23 ( V_5 , args ,
V_47 ,
V_123 ) ;
break;
case V_124 :
F_26 ( V_80 , L_34 , args [ 0 ] . V_103 ) ;
V_7 = F_23 ( V_5 , args ,
V_48 ,
V_125 ) ;
break;
case V_126 :
if ( V_5 -> V_57 != V_97 ) {
V_7 = - V_77 ;
break;
}
F_26 ( V_80 , L_35 , args [ 0 ] . V_103 ) ;
if ( ( strcmp ( args [ 0 ] . V_103 , L_36 ) ) == 0 )
V_5 -> V_23 |= V_127 ;
else
V_7 = - V_77 ;
break;
case V_128 :
F_26 ( V_80 , L_37 , V_83 ) ;
V_7 = - V_77 ;
break;
}
}
if ( ! V_7 && ( V_5 -> V_57 == V_87 ) )
V_7 = - V_77 ;
else if ( V_5 -> V_17 == V_54 )
V_129 |= V_130 ;
F_27 ( V_80 , L_38 , ! V_7 ) ;
F_39 ( V_80 ) ;
return V_7 ;
}
T_4 F_40 ( char * V_12 )
{
const char * V_70 = L_39 ;
char * V_83 ;
struct V_4 * V_5 ;
T_4 V_7 , V_131 ;
int V_72 = 0 ;
if ( V_69 != & V_67 ) {
F_22 ( V_74 , NULL ,
NULL , V_70 , L_2 ,
- V_132 , V_72 ) ;
return - V_132 ;
}
V_5 = F_41 ( sizeof( * V_5 ) , V_84 ) ;
if ( ! V_5 ) {
F_22 ( V_74 , NULL ,
NULL , V_70 , L_40 , - V_78 , V_72 ) ;
return - V_78 ;
}
F_42 ( & V_5 -> V_66 ) ;
V_83 = F_31 ( & V_12 , L_41 ) ;
V_131 = strlen ( V_83 ) + 1 ;
if ( * V_83 == '#' ) {
F_25 ( V_5 ) ;
return V_131 ;
}
V_7 = F_29 ( V_83 , V_5 ) ;
if ( V_7 ) {
F_25 ( V_5 ) ;
F_22 ( V_74 , NULL ,
NULL , V_70 , L_42 , V_7 ,
V_72 ) ;
return V_7 ;
}
F_4 ( & V_9 ) ;
F_20 ( & V_5 -> V_66 , & V_73 ) ;
F_8 ( & V_9 ) ;
return V_131 ;
}
void F_43 ( void )
{
struct V_4 * V_5 , * V_6 ;
int V_8 ;
F_4 ( & V_9 ) ;
F_5 (entry, tmp, &ima_policy_rules, list) {
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ )
F_25 ( V_5 -> V_11 [ V_8 ] . V_14 ) ;
F_44 ( & V_5 -> V_66 ) ;
F_25 ( V_5 ) ;
}
F_8 ( & V_9 ) ;
}
