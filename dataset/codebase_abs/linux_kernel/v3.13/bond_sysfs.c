static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 = 0 ;
struct V_10 * V_11 ;
F_3 () ;
F_4 (bond, &bn->dev_list, bond_list) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_11 -> V_14 -> V_15 ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static struct V_16 * F_6 ( struct V_6 * V_7 , const char * V_17 )
{
struct V_10 * V_11 ;
F_4 (bond, &bn->dev_list, bond_list) {
if ( strncmp ( V_11 -> V_14 -> V_15 , V_17 , V_13 ) == 0 )
return V_11 -> V_14 ;
}
return NULL ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
char V_20 [ V_13 + 1 ] = { 0 , } ;
char * V_17 ;
int V_21 , V_9 = V_19 ;
sscanf ( V_18 , L_3 , V_20 ) ;
V_17 = V_20 + 1 ;
if ( ( strlen ( V_20 ) <= 1 ) ||
! F_8 ( V_17 ) )
goto V_22;
if ( V_20 [ 0 ] == '+' ) {
F_9 ( L_4 , V_17 ) ;
V_21 = F_10 ( V_7 -> V_23 , V_17 ) ;
if ( V_21 ) {
if ( V_21 == - V_24 )
F_9 ( L_5 , V_17 ) ;
else
F_9 ( L_6 , V_17 ) ;
V_9 = V_21 ;
}
} else if ( V_20 [ 0 ] == '-' ) {
struct V_16 * V_25 ;
F_3 () ;
V_25 = F_6 ( V_7 , V_17 ) ;
if ( V_25 ) {
F_9 ( L_7 , V_17 ) ;
F_11 ( V_25 ) ;
} else {
F_12 ( L_8 , V_17 ) ;
V_9 = - V_26 ;
}
F_5 () ;
} else
goto V_22;
return V_9 ;
V_22:
F_12 ( L_9 ) ;
return - V_27 ;
}
static T_1 F_13 ( struct V_28 * V_29 ,
struct V_30 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
int V_9 = 0 ;
if ( ! F_15 () )
return F_16 () ;
F_17 (bond, slave, iter) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_33 -> V_14 -> V_15 ) ;
}
F_5 () ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_18 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_18 , T_2 V_19 )
{
char V_20 [ V_13 + 1 ] = { 0 , } ;
char * V_17 ;
int V_9 , V_34 = V_19 ;
struct V_16 * V_14 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( ! F_15 () )
return F_16 () ;
sscanf ( V_18 , L_3 , V_20 ) ;
V_17 = V_20 + 1 ;
if ( ( strlen ( V_20 ) <= 1 ) ||
! F_8 ( V_17 ) )
goto V_22;
V_14 = F_19 ( F_20 ( V_11 -> V_14 ) , V_17 ) ;
if ( ! V_14 ) {
F_9 ( L_10 ,
V_11 -> V_14 -> V_15 , V_17 ) ;
V_34 = - V_26 ;
goto V_35;
}
switch ( V_20 [ 0 ] ) {
case '+' :
F_9 ( L_11 , V_11 -> V_14 -> V_15 , V_14 -> V_15 ) ;
V_9 = F_21 ( V_11 -> V_14 , V_14 ) ;
break;
case '-' :
F_9 ( L_12 , V_11 -> V_14 -> V_15 , V_14 -> V_15 ) ;
V_9 = F_22 ( V_11 -> V_14 , V_14 ) ;
break;
default:
goto V_22;
}
if ( V_9 )
V_34 = V_9 ;
goto V_35;
V_22:
F_12 ( L_13 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_23 ( struct V_28 * V_29 ,
struct V_30 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_36 [ V_11 -> V_37 . V_38 ] . V_39 ,
V_11 -> V_37 . V_38 ) ;
}
static T_1 F_24 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
V_40 = F_25 ( V_5 , V_36 ) ;
if ( V_40 < 0 ) {
F_12 ( L_15 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
return - V_41 ;
}
if ( ! F_15 () )
return F_16 () ;
V_34 = F_26 ( V_11 , V_40 ) ;
if ( ! V_34 ) {
F_9 ( L_16 ,
V_11 -> V_14 -> V_15 , V_36 [ V_40 ] . V_39 ,
V_40 ) ;
V_34 = V_19 ;
}
F_5 () ;
return V_34 ;
}
static T_1 F_27 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_42 [ V_11 -> V_37 . V_43 ] . V_39 ,
V_11 -> V_37 . V_43 ) ;
}
static T_1 F_28 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
V_40 = F_25 ( V_5 , V_42 ) ;
if ( V_40 < 0 ) {
F_12 ( L_17 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_41 ;
} else {
V_11 -> V_37 . V_43 = V_40 ;
F_9 ( L_18 ,
V_11 -> V_14 -> V_15 ,
V_42 [ V_40 ] . V_39 , V_40 ) ;
}
return V_34 ;
}
static T_1 F_29 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_44 [ V_11 -> V_37 . V_45 ] . V_39 ,
V_11 -> V_37 . V_45 ) ;
}
static T_1 F_30 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 , V_34 = V_19 ;
if ( ! F_15 () )
return F_16 () ;
V_40 = F_25 ( V_5 , V_44 ) ;
if ( V_40 < 0 ) {
F_12 ( L_19 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_11 -> V_37 . V_38 != V_46 ) {
F_12 ( L_20 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
F_9 ( L_21 ,
V_11 -> V_14 -> V_15 , V_44 [ V_40 ] . V_39 ,
V_40 ) ;
if ( V_11 -> V_14 -> V_47 & V_48 ) {
if ( ! V_40 )
V_11 -> V_49 = NULL ;
else if ( V_11 -> V_37 . V_50 )
V_11 -> V_49 = V_51 ;
}
V_11 -> V_37 . V_45 = V_40 ;
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_31 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_52 = V_11 -> V_37 . V_53 ;
return sprintf ( V_5 , L_14 , V_54 [ V_52 ] . V_39 ,
V_52 ) ;
}
static T_1 F_32 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 ;
V_40 = F_25 ( V_5 , V_54 ) ;
if ( V_40 < 0 ) {
F_12 ( L_22 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return - V_41 ;
}
F_9 ( L_23 ,
V_11 -> V_14 -> V_15 , V_54 [ V_40 ] . V_39 ,
V_40 ) ;
V_11 -> V_37 . V_53 = V_40 ;
return V_19 ;
}
static T_1 F_33 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_55 [ V_11 -> V_37 . V_56 ] . V_39 ,
V_11 -> V_37 . V_56 ) ;
}
static T_1 F_34 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( ! F_15 () )
return F_16 () ;
if ( F_35 ( V_11 ) ) {
F_12 ( L_24 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
V_40 = F_25 ( V_5 , V_55 ) ;
if ( V_40 < 0 ) {
F_12 ( L_25 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
V_34 = - V_41 ;
goto V_35;
}
V_11 -> V_37 . V_56 = V_40 ;
F_9 ( L_26 ,
V_11 -> V_14 -> V_15 , V_55 [ V_40 ] . V_39 ,
V_40 ) ;
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_36 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_50 ) ;
}
static T_1 F_37 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 , V_34 = V_19 ;
if ( ! F_15 () )
return F_16 () ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_29 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 < 0 ) {
F_12 ( L_30 ,
V_11 -> V_14 -> V_15 , V_40 , V_57 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( F_38 ( V_11 -> V_37 . V_38 ) ) {
F_9 ( L_31 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
F_9 ( L_32 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
V_11 -> V_37 . V_50 = V_40 ;
if ( V_40 ) {
if ( V_11 -> V_37 . V_58 ) {
F_9 ( L_33 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_11 -> V_37 . V_58 = 0 ;
}
if ( ! V_11 -> V_37 . V_59 [ 0 ] )
F_9 ( L_34 ,
V_11 -> V_14 -> V_15 ) ;
}
if ( V_11 -> V_14 -> V_47 & V_48 ) {
if ( ! V_40 ) {
if ( V_11 -> V_37 . V_45 )
V_11 -> V_49 = NULL ;
F_39 ( & V_11 -> V_60 ) ;
} else {
if ( V_11 -> V_37 . V_45 )
V_11 -> V_49 = V_51 ;
F_39 ( & V_11 -> V_61 ) ;
F_40 ( V_11 -> V_62 , & V_11 -> V_60 , 0 ) ;
}
}
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_41 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_63 , V_9 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
if ( V_11 -> V_37 . V_59 [ V_63 ] )
V_9 += sprintf ( V_5 + V_9 , L_35 ,
& V_11 -> V_37 . V_59 [ V_63 ] ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_42 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
T_3 V_65 , * V_66 ;
unsigned long * V_67 ;
int V_68 , V_63 , V_69 , V_34 = - V_41 ;
if ( ! F_15 () )
return F_16 () ;
V_66 = V_11 -> V_37 . V_59 ;
if ( ! F_43 ( V_5 + 1 , - 1 , ( V_70 * ) & V_65 , - 1 , NULL ) ||
F_44 ( V_65 ) ) {
F_12 ( L_36 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
goto V_35;
}
if ( V_5 [ 0 ] == '+' ) {
if ( F_45 ( V_66 , V_65 ) != - 1 ) {
F_12 ( L_37 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
goto V_35;
}
V_68 = F_45 ( V_66 , 0 ) ;
if ( V_68 == - 1 ) {
F_12 ( L_38 ,
V_11 -> V_14 -> V_15 ) ;
goto V_35;
}
F_9 ( L_39 , V_11 -> V_14 -> V_15 ,
& V_65 ) ;
F_46 ( & V_11 -> V_71 ) ;
F_17 (bond, slave, iter)
V_33 -> V_72 [ V_68 ] = V_73 ;
V_66 [ V_68 ] = V_65 ;
F_47 ( & V_11 -> V_71 ) ;
} else if ( V_5 [ 0 ] == '-' ) {
V_68 = F_45 ( V_66 , V_65 ) ;
if ( V_68 == - 1 ) {
F_12 ( L_40 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
goto V_35;
}
if ( V_68 == 0 && ! V_66 [ 1 ] && V_11 -> V_37 . V_50 )
F_48 ( L_41 ,
V_11 -> V_14 -> V_15 ) ;
F_9 ( L_42 , V_11 -> V_14 -> V_15 ,
& V_65 ) ;
F_46 ( & V_11 -> V_71 ) ;
F_17 (bond, slave, iter) {
V_67 = V_33 -> V_72 ;
V_69 = V_68 ;
for (; ( V_69 < V_64 - 1 ) && V_66 [ V_69 + 1 ] ; V_69 ++ )
V_67 [ V_69 ] = V_67 [ V_69 + 1 ] ;
V_67 [ V_69 ] = 0 ;
}
for ( V_63 = V_68 ; ( V_63 < V_64 - 1 ) && V_66 [ V_63 + 1 ] ; V_63 ++ )
V_66 [ V_63 ] = V_66 [ V_63 + 1 ] ;
V_66 [ V_63 ] = 0 ;
F_47 ( & V_11 -> V_71 ) ;
} else {
F_12 ( L_43 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
V_34 = V_19 ;
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_49 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_74 * V_11 -> V_37 . V_58 ) ;
}
static T_1 F_50 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( ! F_15 () )
return F_16 () ;
if ( ! ( V_11 -> V_37 . V_58 ) ) {
F_12 ( L_44 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_45 , V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 < 0 ) {
F_12 ( L_46 ,
V_11 -> V_14 -> V_15 , V_40 , 0 , V_57 ) ;
V_34 = - V_41 ;
goto V_35;
} else {
if ( ( V_40 % V_11 -> V_37 . V_58 ) != 0 ) {
F_51 ( L_47 ,
V_11 -> V_14 -> V_15 , V_40 ,
V_11 -> V_37 . V_58 ,
( V_40 / V_11 -> V_37 . V_58 ) *
V_11 -> V_37 . V_58 ) ;
}
V_11 -> V_37 . V_74 = V_40 / V_11 -> V_37 . V_58 ;
F_9 ( L_48 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_37 . V_74 * V_11 -> V_37 . V_58 ) ;
}
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_52 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_75 * V_11 -> V_37 . V_58 ) ;
}
static T_1 F_53 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( ! F_15 () )
return F_16 () ;
if ( ! ( V_11 -> V_37 . V_58 ) ) {
F_12 ( L_49 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_50 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 < 0 ) {
F_12 ( L_51 ,
V_11 -> V_14 -> V_15 , V_40 , 0 , V_57 ) ;
V_34 = - V_41 ;
goto V_35;
} else {
if ( ( V_40 % V_11 -> V_37 . V_58 ) != 0 ) {
F_51 ( L_52 ,
V_11 -> V_14 -> V_15 , V_40 ,
V_11 -> V_37 . V_58 ,
( V_40 / V_11 -> V_37 . V_58 ) *
V_11 -> V_37 . V_58 ) ;
}
V_11 -> V_37 . V_75 = V_40 / V_11 -> V_37 . V_58 ;
F_9 ( L_53 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_37 . V_75 * V_11 -> V_37 . V_58 ) ;
}
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_54 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_76 [ V_11 -> V_37 . V_77 ] . V_39 ,
V_11 -> V_37 . V_77 ) ;
}
static T_1 F_55 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 , V_34 = V_19 ;
if ( ! F_15 () )
return F_16 () ;
if ( V_11 -> V_14 -> V_47 & V_48 ) {
F_12 ( L_54 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
if ( V_11 -> V_37 . V_38 != V_78 ) {
F_12 ( L_55 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
V_40 = F_25 ( V_5 , V_76 ) ;
if ( ( V_40 == 1 ) || ( V_40 == 0 ) ) {
V_11 -> V_37 . V_77 = V_40 ;
F_56 ( V_11 ) ;
F_9 ( L_56 ,
V_11 -> V_14 -> V_15 , V_76 [ V_40 ] . V_39 ,
V_40 ) ;
} else {
F_12 ( L_57 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_41 ;
}
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_57 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_79 ) ;
}
static T_1 F_58 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
unsigned int V_40 ;
V_34 = F_59 ( V_5 , 0 , & V_40 ) ;
if ( V_34 < 0 ) {
F_12 ( L_58 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return V_34 ;
}
F_9 ( L_59 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
V_11 -> V_37 . V_79 = V_40 ;
return V_19 ;
}
static T_1 F_60 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_80 [ V_11 -> V_37 . V_81 ] . V_39 ,
V_11 -> V_37 . V_81 ) ;
}
static T_1 F_61 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_14 -> V_47 & V_48 ) {
F_12 ( L_60 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
V_40 = F_25 ( V_5 , V_80 ) ;
if ( V_40 != - 1 ) {
V_11 -> V_37 . V_81 = V_40 ;
F_9 ( L_61 ,
V_11 -> V_14 -> V_15 , V_80 [ V_40 ] . V_39 ,
V_40 ) ;
} else {
F_12 ( L_62 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_41 ;
}
V_35:
return V_34 ;
}
static T_1 F_62 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_82 ) ;
}
static T_1 F_63 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_83 = F_64 ( V_5 , 10 , & V_11 -> V_37 . V_82 ) ;
return V_83 ? V_83 : V_19 ;
}
static T_1 F_65 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_58 ) ;
}
static T_1 F_66 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( ! F_15 () )
return F_16 () ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_63 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 < 0 ) {
F_12 ( L_64 ,
V_11 -> V_14 -> V_15 , V_40 , 0 , V_57 ) ;
V_34 = - V_41 ;
goto V_35;
}
F_9 ( L_65 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
V_11 -> V_37 . V_58 = V_40 ;
if ( V_11 -> V_37 . V_75 )
F_9 ( L_66 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_37 . V_75 * V_11 -> V_37 . V_58 ) ;
if ( V_11 -> V_37 . V_74 )
F_9 ( L_67 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_37 . V_74 * V_11 -> V_37 . V_58 ) ;
if ( V_40 && V_11 -> V_37 . V_50 ) {
F_9 ( L_68 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_37 . V_50 = 0 ;
if ( V_11 -> V_37 . V_45 )
V_11 -> V_37 . V_45 = V_84 ;
}
if ( V_11 -> V_14 -> V_47 & V_48 ) {
if ( ! V_40 ) {
F_39 ( & V_11 -> V_61 ) ;
} else {
F_39 ( & V_11 -> V_60 ) ;
F_40 ( V_11 -> V_62 , & V_11 -> V_61 , 0 ) ;
}
}
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_67 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_85 )
V_19 = sprintf ( V_5 , L_69 , V_11 -> V_85 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_68 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
char V_17 [ V_13 ] ;
struct V_33 * V_33 ;
if ( ! F_15 () )
return F_16 () ;
F_69 () ;
F_70 ( & V_11 -> V_71 ) ;
F_46 ( & V_11 -> V_86 ) ;
if ( ! F_71 ( V_11 -> V_37 . V_38 ) ) {
F_9 ( L_70 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_37 . V_38 ) ;
goto V_35;
}
sscanf ( V_5 , L_71 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_72 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_85 = NULL ;
memset ( V_11 -> V_37 . V_87 , 0 , sizeof( V_11 -> V_37 . V_87 ) ) ;
F_72 ( V_11 ) ;
goto V_35;
}
F_17 (bond, slave, iter) {
if ( strncmp ( V_33 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
F_9 ( L_73 ,
V_11 -> V_14 -> V_15 , V_33 -> V_14 -> V_15 ) ;
V_11 -> V_85 = V_33 ;
strcpy ( V_11 -> V_37 . V_87 , V_33 -> V_14 -> V_15 ) ;
F_72 ( V_11 ) ;
goto V_35;
}
}
strncpy ( V_11 -> V_37 . V_87 , V_17 , V_13 ) ;
V_11 -> V_37 . V_87 [ V_13 - 1 ] = 0 ;
F_9 ( L_74
L_75 ,
V_11 -> V_14 -> V_15 , V_17 , V_11 -> V_14 -> V_15 ) ;
V_35:
F_47 ( & V_11 -> V_86 ) ;
F_73 ( & V_11 -> V_71 ) ;
F_74 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_75 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_14 ,
V_88 [ V_11 -> V_37 . V_89 ] . V_39 ,
V_11 -> V_37 . V_89 ) ;
}
static T_1 F_76 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( ! F_15 () )
return F_16 () ;
V_40 = F_25 ( V_5 , V_88 ) ;
if ( V_40 < 0 ) {
F_12 ( L_76 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_41 ;
goto V_35;
}
V_11 -> V_37 . V_89 = V_40 ;
F_9 ( L_77 ,
V_11 -> V_14 -> V_15 , V_88 [ V_40 ] . V_39 ,
V_40 ) ;
F_69 () ;
F_70 ( & V_11 -> V_71 ) ;
F_46 ( & V_11 -> V_86 ) ;
F_72 ( V_11 ) ;
F_47 ( & V_11 -> V_86 ) ;
F_73 ( & V_11 -> V_71 ) ;
F_74 () ;
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_77 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_90 ) ;
}
static T_1 F_78 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_78 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( ( V_40 == 0 ) || ( V_40 == 1 ) ) {
V_11 -> V_37 . V_90 = V_40 ;
F_9 ( L_79 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
} else {
F_9 ( L_80 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
}
V_35:
return V_34 ;
}
static T_1 F_79 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_16 * V_91 ;
int V_19 = 0 ;
F_80 () ;
V_91 = F_81 ( V_11 ) ;
if ( V_91 )
V_19 = sprintf ( V_5 , L_69 , V_91 -> V_15 ) ;
F_82 () ;
return V_19 ;
}
static T_1 F_83 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_34 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
char V_17 [ V_13 ] ;
struct V_16 * V_14 ;
if ( ! F_15 () )
return F_16 () ;
sscanf ( V_5 , L_71 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
V_14 = NULL ;
} else {
V_14 = F_19 ( F_20 ( V_11 -> V_14 ) , V_17 ) ;
if ( ! V_14 ) {
V_34 = - V_26 ;
goto V_35;
}
}
V_34 = F_84 ( V_11 , V_14 ) ;
if ( ! V_34 )
V_34 = V_19 ;
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_85 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_69 , V_11 -> V_92 ? L_81 : L_82 ) ;
}
static T_1 F_86 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_37 . V_38 == V_78 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_27 ,
F_87 ( V_11 , & V_93 )
? 0 : V_93 . V_94 ) ;
}
return V_19 ;
}
static T_1 F_88 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_37 . V_38 == V_78 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_27 ,
F_87 ( V_11 , & V_93 )
? 0 : V_93 . V_95 ) ;
}
return V_19 ;
}
static T_1 F_89 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_37 . V_38 == V_78 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_27 ,
F_87 ( V_11 , & V_93 )
? 0 : V_93 . V_96 ) ;
}
return V_19 ;
}
static T_1 F_90 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_37 . V_38 == V_78 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_27 ,
F_87 ( V_11 , & V_93 )
? 0 : V_93 . V_97 ) ;
}
return V_19 ;
}
static T_1 F_91 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_37 . V_38 == V_78 ) {
struct V_93 V_93 ;
if ( ! F_87 ( V_11 , & V_93 ) )
V_19 = sprintf ( V_5 , L_83 , V_93 . V_98 ) ;
}
return V_19 ;
}
static T_1 F_92 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
int V_9 = 0 ;
if ( ! F_15 () )
return F_16 () ;
F_17 (bond, slave, iter) {
if ( V_9 > ( V_12 - V_13 - 6 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_84 ,
V_33 -> V_14 -> V_15 , V_33 -> V_99 ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static T_1 F_93 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_33 * V_33 , * V_100 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
T_4 V_101 ;
int V_34 = V_19 ;
char * V_102 ;
struct V_16 * V_103 = NULL ;
if ( ! F_15 () )
return F_16 () ;
V_102 = strchr ( V_18 , ':' ) ;
if ( ! V_102 )
goto V_22;
* V_102 = '\0' ;
if ( sscanf ( ++ V_102 , L_85 , & V_101 ) != 1 )
goto V_22;
if ( strlen ( V_18 ) > V_13 ||
! F_8 ( V_18 ) ||
V_101 > V_11 -> V_14 -> V_104 )
goto V_22;
V_103 = F_19 ( F_20 ( V_11 -> V_14 ) , V_18 ) ;
if ( ! V_103 )
goto V_22;
V_100 = NULL ;
F_17 (bond, slave, iter) {
if ( V_103 == V_33 -> V_14 )
V_100 = V_33 ;
else if ( V_101 && V_101 == V_33 -> V_99 ) {
goto V_22;
}
}
if ( ! V_100 )
goto V_22;
V_100 -> V_99 = V_101 ;
V_35:
F_5 () ;
return V_34 ;
V_22:
F_9 ( L_86 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_27 ;
goto V_35;
}
static T_1 F_94 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_105 ) ;
}
static T_1 F_95 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 , V_34 = V_19 ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
if ( ! F_15 () )
return F_16 () ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_87 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 == V_11 -> V_37 . V_105 )
goto V_35;
if ( ( V_40 == 0 ) || ( V_40 == 1 ) ) {
V_11 -> V_37 . V_105 = V_40 ;
} else {
F_9 ( L_88 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
V_34 = - V_41 ;
goto V_35;
}
F_17 (bond, slave, iter) {
if ( ! F_96 ( V_33 ) ) {
if ( V_40 )
V_33 -> V_106 = 0 ;
else
V_33 -> V_106 = 1 ;
}
}
V_35:
F_5 () ;
return V_34 ;
}
static T_1 F_97 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_107 ) ;
}
static T_1 F_98 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_40 , V_34 = V_19 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_89 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 < 0 || V_40 > 255 ) {
F_12 ( L_90 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
V_34 = - V_41 ;
goto V_35;
}
F_9 ( L_91 ,
V_11 -> V_14 -> V_15 , V_40 ) ;
V_11 -> V_37 . V_107 = V_40 ;
V_35:
return V_34 ;
}
static T_1 F_99 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_27 , V_11 -> V_37 . V_108 ) ;
}
static T_1 F_100 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 , V_34 = V_19 ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_92 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 <= 0 ) {
F_12 ( L_93 ,
V_11 -> V_14 -> V_15 , V_57 ) ;
V_34 = - V_41 ;
goto V_35;
}
V_11 -> V_37 . V_108 = V_40 ;
V_35:
return V_34 ;
}
static T_1 F_101 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
unsigned int V_109 = V_11 -> V_37 . V_109 ;
if ( V_109 > 1 )
V_109 = F_102 ( V_109 ) ;
return sprintf ( V_5 , L_94 , V_109 ) ;
}
static T_1 F_103 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_40 , V_34 = V_19 ;
if ( sscanf ( V_5 , L_28 , & V_40 ) != 1 ) {
F_12 ( L_95 ,
V_11 -> V_14 -> V_15 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_40 < 0 || V_40 > V_110 ) {
F_12 ( L_96 ,
V_11 -> V_14 -> V_15 , V_110 ) ;
V_34 = - V_41 ;
goto V_35;
}
if ( V_11 -> V_37 . V_38 != V_111 )
F_48 ( L_97 ,
V_11 -> V_14 -> V_15 ) ;
if ( V_40 > 1 )
V_11 -> V_37 . V_109 = F_102 ( V_40 ) ;
else
V_11 -> V_37 . V_109 = V_40 ;
V_35:
return V_34 ;
}
int F_104 ( struct V_6 * V_7 )
{
int V_34 ;
V_7 -> V_8 = V_8 ;
F_105 ( & V_7 -> V_8 . V_4 ) ;
V_34 = F_106 ( & V_7 -> V_8 ,
V_7 -> V_23 ) ;
if ( V_34 == - V_24 ) {
if ( F_19 ( V_7 -> V_23 ,
V_8 . V_4 . V_15 ) )
F_12 ( L_98 ,
V_8 . V_4 . V_15 ) ;
V_34 = 0 ;
}
return V_34 ;
}
void F_107 ( struct V_6 * V_7 )
{
F_108 ( & V_7 -> V_8 , V_7 -> V_23 ) ;
}
void F_109 ( struct V_10 * V_11 )
{
V_11 -> V_14 -> V_112 [ 0 ] = & V_113 ;
}
