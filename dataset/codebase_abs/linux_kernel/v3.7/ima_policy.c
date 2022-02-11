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
static bool F_3 ( struct V_4 * V_5 ,
struct V_6 * V_6 , enum V_7 V_8 , int V_9 )
{
struct V_10 * V_11 = V_12 ;
const struct V_13 * V_13 = F_4 () ;
int V_14 ;
if ( ( V_5 -> V_15 & V_16 ) && V_5 -> V_8 != V_8 )
return false ;
if ( ( V_5 -> V_15 & V_17 ) && V_5 -> V_9 != V_9 )
return false ;
if ( ( V_5 -> V_15 & V_18 )
&& V_5 -> V_19 != V_6 -> V_20 -> V_21 )
return false ;
if ( ( V_5 -> V_15 & V_22 ) && ! F_5 ( V_5 -> V_23 , V_13 -> V_23 ) )
return false ;
if ( ( V_5 -> V_15 & V_24 ) && ! F_5 ( V_5 -> V_25 , V_6 -> V_26 ) )
return false ;
for ( V_14 = 0 ; V_14 < V_27 ; V_14 ++ ) {
int V_28 = 0 ;
T_2 V_29 , V_30 ;
if ( ! V_5 -> V_31 [ V_14 ] . V_5 )
continue;
switch ( V_14 ) {
case V_32 :
case V_33 :
case V_34 :
F_6 ( V_6 , & V_29 ) ;
V_28 = F_7 ( V_29 ,
V_5 -> V_31 [ V_14 ] . type ,
V_35 ,
V_5 -> V_31 [ V_14 ] . V_5 ,
NULL ) ;
break;
case V_36 :
case V_37 :
case V_38 :
F_8 ( V_11 , & V_30 ) ;
V_28 = F_7 ( V_30 ,
V_5 -> V_31 [ V_14 ] . type ,
V_35 ,
V_5 -> V_31 [ V_14 ] . V_5 ,
NULL ) ;
default:
break;
}
if ( ! V_28 )
return false ;
}
return true ;
}
int F_9 ( struct V_6 * V_6 , enum V_7 V_8 , int V_9 ,
int V_15 )
{
struct V_4 * V_39 ;
int V_40 = 0 , V_41 = V_15 | ( V_15 << 1 ) ;
F_10 (entry, ima_rules, list) {
if ( ! ( V_39 -> V_40 & V_41 ) )
continue;
if ( ! F_3 ( V_39 , V_6 , V_8 , V_9 ) )
continue;
V_40 |= V_39 -> V_40 & V_42 ;
if ( V_39 -> V_40 & V_42 )
V_41 &= ~ ( V_39 -> V_40 | V_39 -> V_40 << 1 ) ;
else
V_41 &= ~ ( V_39 -> V_40 | V_39 -> V_40 >> 1 ) ;
if ( ! V_41 )
break;
}
return V_40 ;
}
void T_1 F_11 ( void )
{
int V_14 , V_43 , V_44 ;
V_43 = V_2 ? F_12 ( V_45 ) : 0 ;
V_44 = V_3 ?
F_12 ( V_46 ) : 0 ;
for ( V_14 = 0 ; V_14 < V_43 + V_44 ; V_14 ++ ) {
if ( V_14 < V_43 )
F_13 ( & V_45 [ V_14 ] . V_47 ,
& V_48 ) ;
else {
int V_49 = V_14 - V_43 ;
F_13 ( & V_46 [ V_49 ] . V_47 ,
& V_48 ) ;
}
}
V_50 = & V_48 ;
}
void F_14 ( void )
{
const char * V_51 = L_1 ;
const char * V_52 = L_2 ;
int V_53 = 1 ;
int V_54 = 0 ;
if ( V_50 == & V_48 ) {
V_50 = & V_55 ;
V_52 = L_3 ;
V_53 = 0 ;
}
F_15 ( V_56 , NULL ,
NULL , V_51 , V_52 , V_53 , V_54 ) ;
}
static int F_16 ( struct V_4 * V_39 ,
char * args , int V_57 , int V_58 )
{
int V_53 ;
if ( V_39 -> V_31 [ V_57 ] . V_5 )
return - V_59 ;
V_39 -> V_31 [ V_57 ] . type = V_58 ;
V_53 = F_17 ( V_39 -> V_31 [ V_57 ] . type ,
V_35 , args ,
& V_39 -> V_31 [ V_57 ] . V_5 ) ;
if ( ! V_39 -> V_31 [ V_57 ] . V_5 )
return - V_59 ;
return V_53 ;
}
static void F_18 ( struct V_60 * V_61 , char * V_62 , char * V_63 )
{
F_19 ( V_61 , L_4 , V_62 ) ;
F_20 ( V_61 , V_63 ) ;
F_19 ( V_61 , L_5 ) ;
}
static int F_21 ( char * V_5 , struct V_4 * V_39 )
{
struct V_60 * V_61 ;
char * V_64 ;
int V_53 = 0 ;
V_61 = F_22 ( NULL , V_65 , V_66 ) ;
V_39 -> V_23 = V_67 ;
V_39 -> V_25 = V_67 ;
V_39 -> V_40 = V_68 ;
while ( ( V_64 = F_23 ( & V_5 , L_6 ) ) != NULL ) {
T_3 args [ V_69 ] ;
int V_70 ;
unsigned long V_71 ;
if ( V_53 < 0 )
break;
if ( ( * V_64 == '\0' ) || ( * V_64 == ' ' ) || ( * V_64 == '\t' ) )
continue;
V_70 = F_24 ( V_64 , V_72 , args ) ;
switch ( V_70 ) {
case V_73 :
F_18 ( V_61 , L_7 , L_8 ) ;
if ( V_39 -> V_40 != V_68 )
V_53 = - V_59 ;
V_39 -> V_40 = V_74 ;
break;
case V_75 :
F_18 ( V_61 , L_7 , L_9 ) ;
if ( V_39 -> V_40 != V_68 )
V_53 = - V_59 ;
V_39 -> V_40 = V_76 ;
break;
case V_77 :
F_18 ( V_61 , L_7 , L_10 ) ;
if ( V_39 -> V_40 != V_68 )
V_53 = - V_59 ;
V_39 -> V_40 = V_78 ;
break;
case V_79 :
F_18 ( V_61 , L_7 , L_11 ) ;
if ( V_39 -> V_40 != V_68 )
V_53 = - V_59 ;
V_39 -> V_40 = V_80 ;
break;
case V_81 :
F_18 ( V_61 , L_7 , L_12 ) ;
if ( V_39 -> V_40 != V_68 )
V_53 = - V_59 ;
V_39 -> V_40 = V_82 ;
break;
case V_83 :
F_18 ( V_61 , L_13 , args [ 0 ] . V_84 ) ;
if ( V_39 -> V_8 )
V_53 = - V_59 ;
if ( strcmp ( args [ 0 ] . V_84 , L_14 ) == 0 )
V_39 -> V_8 = V_85 ;
else if ( strcmp ( args [ 0 ] . V_84 , L_15 ) == 0 )
V_39 -> V_8 = V_85 ;
else if ( strcmp ( args [ 0 ] . V_84 , L_16 ) == 0 )
V_39 -> V_8 = V_86 ;
else if ( strcmp ( args [ 0 ] . V_84 , L_17 ) == 0 )
V_39 -> V_8 = V_87 ;
else
V_53 = - V_59 ;
if ( ! V_53 )
V_39 -> V_15 |= V_16 ;
break;
case V_88 :
F_18 ( V_61 , L_18 , args [ 0 ] . V_84 ) ;
if ( V_39 -> V_9 )
V_53 = - V_59 ;
if ( ( strcmp ( args [ 0 ] . V_84 , L_19 ) ) == 0 )
V_39 -> V_9 = V_89 ;
else if ( strcmp ( args [ 0 ] . V_84 , L_20 ) == 0 )
V_39 -> V_9 = V_90 ;
else if ( strcmp ( args [ 0 ] . V_84 , L_21 ) == 0 )
V_39 -> V_9 = V_91 ;
else if ( strcmp ( args [ 0 ] . V_84 , L_22 ) == 0 )
V_39 -> V_9 = V_92 ;
else
V_53 = - V_59 ;
if ( ! V_53 )
V_39 -> V_15 |= V_17 ;
break;
case V_93 :
F_18 ( V_61 , L_23 , args [ 0 ] . V_84 ) ;
if ( V_39 -> V_19 ) {
V_53 = - V_59 ;
break;
}
V_53 = F_25 ( args [ 0 ] . V_84 , 16 ,
& V_39 -> V_19 ) ;
if ( ! V_53 )
V_39 -> V_15 |= V_18 ;
break;
case V_94 :
F_18 ( V_61 , L_24 , args [ 0 ] . V_84 ) ;
if ( F_26 ( V_39 -> V_23 ) ) {
V_53 = - V_59 ;
break;
}
V_53 = F_25 ( args [ 0 ] . V_84 , 10 , & V_71 ) ;
if ( ! V_53 ) {
V_39 -> V_23 = F_27 ( F_28 () , ( V_95 ) V_71 ) ;
if ( ! F_26 ( V_39 -> V_23 ) || ( ( ( V_95 ) V_71 ) != V_71 ) )
V_53 = - V_59 ;
else
V_39 -> V_15 |= V_22 ;
}
break;
case V_96 :
F_18 ( V_61 , L_25 , args [ 0 ] . V_84 ) ;
if ( F_26 ( V_39 -> V_25 ) ) {
V_53 = - V_59 ;
break;
}
V_53 = F_25 ( args [ 0 ] . V_84 , 10 , & V_71 ) ;
if ( ! V_53 ) {
V_39 -> V_25 = F_27 ( F_28 () , ( V_95 ) V_71 ) ;
if ( ! F_26 ( V_39 -> V_25 ) || ( ( ( V_95 ) V_71 ) != V_71 ) )
V_53 = - V_59 ;
else
V_39 -> V_15 |= V_24 ;
}
break;
case V_97 :
F_18 ( V_61 , L_26 , args [ 0 ] . V_84 ) ;
V_53 = F_16 ( V_39 , args [ 0 ] . V_84 ,
V_32 ,
V_98 ) ;
break;
case V_99 :
F_18 ( V_61 , L_27 , args [ 0 ] . V_84 ) ;
V_53 = F_16 ( V_39 , args [ 0 ] . V_84 ,
V_33 ,
V_100 ) ;
break;
case V_101 :
F_18 ( V_61 , L_28 , args [ 0 ] . V_84 ) ;
V_53 = F_16 ( V_39 , args [ 0 ] . V_84 ,
V_34 ,
V_102 ) ;
break;
case V_103 :
F_18 ( V_61 , L_29 , args [ 0 ] . V_84 ) ;
V_53 = F_16 ( V_39 , args [ 0 ] . V_84 ,
V_36 ,
V_104 ) ;
break;
case V_105 :
F_18 ( V_61 , L_30 , args [ 0 ] . V_84 ) ;
V_53 = F_16 ( V_39 , args [ 0 ] . V_84 ,
V_37 ,
V_106 ) ;
break;
case V_107 :
F_18 ( V_61 , L_31 , args [ 0 ] . V_84 ) ;
V_53 = F_16 ( V_39 , args [ 0 ] . V_84 ,
V_38 ,
V_108 ) ;
break;
case V_109 :
F_18 ( V_61 , L_32 , V_64 ) ;
V_53 = - V_59 ;
break;
}
}
if ( ! V_53 && ( V_39 -> V_40 == V_68 ) )
V_53 = - V_59 ;
F_19 ( V_61 , L_33 , ! V_53 ) ;
F_29 ( V_61 ) ;
return V_53 ;
}
T_4 F_30 ( char * V_5 )
{
const char * V_51 = L_34 ;
char * V_64 ;
struct V_4 * V_39 ;
T_4 V_53 , V_110 ;
int V_54 = 0 ;
if ( V_50 != & V_48 ) {
F_15 ( V_56 , NULL ,
NULL , V_51 , L_2 ,
- V_111 , V_54 ) ;
return - V_111 ;
}
V_39 = F_31 ( sizeof( * V_39 ) , V_65 ) ;
if ( ! V_39 ) {
F_15 ( V_56 , NULL ,
NULL , V_51 , L_35 , - V_112 , V_54 ) ;
return - V_112 ;
}
F_32 ( & V_39 -> V_47 ) ;
V_64 = F_23 ( & V_5 , L_36 ) ;
V_110 = strlen ( V_64 ) + 1 ;
if ( * V_64 == '#' ) {
F_33 ( V_39 ) ;
return V_110 ;
}
V_53 = F_21 ( V_64 , V_39 ) ;
if ( V_53 ) {
F_33 ( V_39 ) ;
F_15 ( V_56 , NULL ,
NULL , V_51 , L_37 , V_53 ,
V_54 ) ;
return V_53 ;
}
F_34 ( & V_113 ) ;
F_13 ( & V_39 -> V_47 , & V_55 ) ;
F_35 ( & V_113 ) ;
return V_110 ;
}
void F_36 ( void )
{
struct V_4 * V_39 , * V_114 ;
F_34 ( & V_113 ) ;
F_37 (entry, tmp, &ima_policy_rules, list) {
F_38 ( & V_39 -> V_47 ) ;
F_33 ( V_39 ) ;
}
F_35 ( & V_113 ) ;
}
