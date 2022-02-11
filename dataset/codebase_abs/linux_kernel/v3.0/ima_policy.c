static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static bool F_2 ( struct V_3 * V_4 ,
struct V_5 * V_5 , enum V_6 V_7 , int V_8 )
{
struct V_9 * V_10 = V_11 ;
int V_12 ;
if ( ( V_4 -> V_13 & V_14 ) && V_4 -> V_7 != V_7 )
return false ;
if ( ( V_4 -> V_13 & V_15 ) && V_4 -> V_8 != V_8 )
return false ;
if ( ( V_4 -> V_13 & V_16 )
&& V_4 -> V_17 != V_5 -> V_18 -> V_19 )
return false ;
if ( ( V_4 -> V_13 & V_20 ) && V_4 -> V_21 != V_10 -> V_22 -> V_21 )
return false ;
for ( V_12 = 0 ; V_12 < V_23 ; V_12 ++ ) {
int V_24 = 0 ;
T_2 V_25 , V_26 ;
if ( ! V_4 -> V_27 [ V_12 ] . V_4 )
continue;
switch ( V_12 ) {
case V_28 :
case V_29 :
case V_30 :
F_3 ( V_5 , & V_25 ) ;
V_24 = F_4 ( V_25 ,
V_4 -> V_27 [ V_12 ] . type ,
V_31 ,
V_4 -> V_27 [ V_12 ] . V_4 ,
NULL ) ;
break;
case V_32 :
case V_33 :
case V_34 :
F_5 ( V_10 , & V_26 ) ;
V_24 = F_4 ( V_26 ,
V_4 -> V_27 [ V_12 ] . type ,
V_31 ,
V_4 -> V_27 [ V_12 ] . V_4 ,
NULL ) ;
default:
break;
}
if ( ! V_24 )
return false ;
}
return true ;
}
int F_6 ( struct V_5 * V_5 , enum V_6 V_7 , int V_8 )
{
struct V_3 * V_35 ;
F_7 (entry, ima_measure, list) {
bool V_24 ;
V_24 = F_2 ( V_35 , V_5 , V_7 , V_8 ) ;
if ( V_24 )
return V_35 -> V_36 ;
}
return 0 ;
}
void T_1 F_8 ( void )
{
int V_12 , V_37 ;
if ( V_2 )
V_37 = F_9 ( V_38 ) ;
else
V_37 = 0 ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ )
F_10 ( & V_38 [ V_12 ] . V_39 , & V_40 ) ;
V_41 = & V_40 ;
}
void F_11 ( void )
{
const char * V_42 = L_1 ;
const char * V_43 = L_2 ;
int V_44 = 1 ;
int V_45 = 0 ;
if ( V_41 == & V_40 ) {
V_41 = & V_46 ;
V_43 = L_3 ;
V_44 = 0 ;
}
F_12 ( V_47 , NULL ,
NULL , V_42 , V_43 , V_44 , V_45 ) ;
}
static int F_13 ( struct V_3 * V_35 ,
char * args , int V_48 , int V_49 )
{
int V_44 ;
if ( V_35 -> V_27 [ V_48 ] . V_4 )
return - V_50 ;
V_35 -> V_27 [ V_48 ] . type = V_49 ;
V_44 = F_14 ( V_35 -> V_27 [ V_48 ] . type ,
V_31 , args ,
& V_35 -> V_27 [ V_48 ] . V_4 ) ;
if ( ! V_35 -> V_27 [ V_48 ] . V_4 )
return - V_50 ;
return V_44 ;
}
static void F_15 ( struct V_51 * V_52 , char * V_53 , char * V_54 )
{
F_16 ( V_52 , L_4 , V_53 ) ;
F_17 ( V_52 , V_54 ) ;
F_16 ( V_52 , L_5 ) ;
}
static int F_18 ( char * V_4 , struct V_3 * V_35 )
{
struct V_51 * V_52 ;
char * V_55 ;
int V_44 = 0 ;
V_52 = F_19 ( NULL , V_56 , V_57 ) ;
V_35 -> V_21 = - 1 ;
V_35 -> V_36 = V_58 ;
while ( ( V_55 = F_20 ( & V_4 , L_6 ) ) != NULL ) {
T_3 args [ V_59 ] ;
int V_60 ;
unsigned long V_61 ;
if ( V_44 < 0 )
break;
if ( ( * V_55 == '\0' ) || ( * V_55 == ' ' ) || ( * V_55 == '\t' ) )
continue;
V_60 = F_21 ( V_55 , V_62 , args ) ;
switch ( V_60 ) {
case V_63 :
F_15 ( V_52 , L_7 , L_8 ) ;
if ( V_35 -> V_36 != V_58 )
V_44 = - V_50 ;
V_35 -> V_36 = V_64 ;
break;
case V_65 :
F_15 ( V_52 , L_7 , L_9 ) ;
if ( V_35 -> V_36 != V_58 )
V_44 = - V_50 ;
V_35 -> V_36 = V_66 ;
break;
case V_67 :
F_15 ( V_52 , L_10 , args [ 0 ] . V_68 ) ;
if ( V_35 -> V_7 )
V_44 = - V_50 ;
if ( strcmp ( args [ 0 ] . V_68 , L_11 ) == 0 )
V_35 -> V_7 = V_69 ;
else if ( strcmp ( args [ 0 ] . V_68 , L_12 ) == 0 )
V_35 -> V_7 = V_69 ;
else if ( strcmp ( args [ 0 ] . V_68 , L_13 ) == 0 )
V_35 -> V_7 = V_70 ;
else if ( strcmp ( args [ 0 ] . V_68 , L_14 ) == 0 )
V_35 -> V_7 = V_71 ;
else
V_44 = - V_50 ;
if ( ! V_44 )
V_35 -> V_13 |= V_14 ;
break;
case V_72 :
F_15 ( V_52 , L_15 , args [ 0 ] . V_68 ) ;
if ( V_35 -> V_8 )
V_44 = - V_50 ;
if ( ( strcmp ( args [ 0 ] . V_68 , L_16 ) ) == 0 )
V_35 -> V_8 = V_73 ;
else if ( strcmp ( args [ 0 ] . V_68 , L_17 ) == 0 )
V_35 -> V_8 = V_74 ;
else if ( strcmp ( args [ 0 ] . V_68 , L_18 ) == 0 )
V_35 -> V_8 = V_75 ;
else if ( strcmp ( args [ 0 ] . V_68 , L_19 ) == 0 )
V_35 -> V_8 = V_76 ;
else
V_44 = - V_50 ;
if ( ! V_44 )
V_35 -> V_13 |= V_15 ;
break;
case V_77 :
F_15 ( V_52 , L_20 , args [ 0 ] . V_68 ) ;
if ( V_35 -> V_17 ) {
V_44 = - V_50 ;
break;
}
V_44 = F_22 ( args [ 0 ] . V_68 , 16 ,
& V_35 -> V_17 ) ;
if ( ! V_44 )
V_35 -> V_13 |= V_16 ;
break;
case V_78 :
F_15 ( V_52 , L_21 , args [ 0 ] . V_68 ) ;
if ( V_35 -> V_21 != - 1 ) {
V_44 = - V_50 ;
break;
}
V_44 = F_22 ( args [ 0 ] . V_68 , 10 , & V_61 ) ;
if ( ! V_44 ) {
V_35 -> V_21 = ( V_79 ) V_61 ;
if ( V_35 -> V_21 != V_61 )
V_44 = - V_50 ;
else
V_35 -> V_13 |= V_20 ;
}
break;
case V_80 :
F_15 ( V_52 , L_22 , args [ 0 ] . V_68 ) ;
V_44 = F_13 ( V_35 , args [ 0 ] . V_68 ,
V_28 ,
V_81 ) ;
break;
case V_82 :
F_15 ( V_52 , L_23 , args [ 0 ] . V_68 ) ;
V_44 = F_13 ( V_35 , args [ 0 ] . V_68 ,
V_29 ,
V_83 ) ;
break;
case V_84 :
F_15 ( V_52 , L_24 , args [ 0 ] . V_68 ) ;
V_44 = F_13 ( V_35 , args [ 0 ] . V_68 ,
V_30 ,
V_85 ) ;
break;
case V_86 :
F_15 ( V_52 , L_25 , args [ 0 ] . V_68 ) ;
V_44 = F_13 ( V_35 , args [ 0 ] . V_68 ,
V_32 ,
V_87 ) ;
break;
case V_88 :
F_15 ( V_52 , L_26 , args [ 0 ] . V_68 ) ;
V_44 = F_13 ( V_35 , args [ 0 ] . V_68 ,
V_33 ,
V_89 ) ;
break;
case V_90 :
F_15 ( V_52 , L_27 , args [ 0 ] . V_68 ) ;
V_44 = F_13 ( V_35 , args [ 0 ] . V_68 ,
V_34 ,
V_91 ) ;
break;
case V_92 :
F_15 ( V_52 , L_28 , V_55 ) ;
V_44 = - V_50 ;
break;
}
}
if ( ! V_44 && ( V_35 -> V_36 == V_58 ) )
V_44 = - V_50 ;
F_16 ( V_52 , L_29 , ! ! V_44 ) ;
F_23 ( V_52 ) ;
return V_44 ;
}
T_4 F_24 ( char * V_4 )
{
const char * V_42 = L_30 ;
char * V_55 ;
struct V_3 * V_35 ;
T_4 V_44 , V_93 ;
int V_45 = 0 ;
if ( V_41 != & V_40 ) {
F_12 ( V_47 , NULL ,
NULL , V_42 , L_2 ,
- V_94 , V_45 ) ;
return - V_94 ;
}
V_35 = F_25 ( sizeof( * V_35 ) , V_56 ) ;
if ( ! V_35 ) {
F_12 ( V_47 , NULL ,
NULL , V_42 , L_31 , - V_95 , V_45 ) ;
return - V_95 ;
}
F_26 ( & V_35 -> V_39 ) ;
V_55 = F_20 ( & V_4 , L_32 ) ;
V_93 = strlen ( V_55 ) + 1 ;
if ( * V_55 == '#' ) {
F_27 ( V_35 ) ;
return V_93 ;
}
V_44 = F_18 ( V_55 , V_35 ) ;
if ( V_44 ) {
F_27 ( V_35 ) ;
F_12 ( V_47 , NULL ,
NULL , V_42 , L_33 , V_44 ,
V_45 ) ;
return V_44 ;
}
F_28 ( & V_96 ) ;
F_10 ( & V_35 -> V_39 , & V_46 ) ;
F_29 ( & V_96 ) ;
return V_93 ;
}
void F_30 ( void )
{
struct V_3 * V_35 , * V_97 ;
F_28 ( & V_96 ) ;
F_31 (entry, tmp, &measure_policy_rules, list) {
F_32 ( & V_35 -> V_39 ) ;
F_27 ( V_35 ) ;
}
F_29 ( & V_96 ) ;
}
