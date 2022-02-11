static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = V_7 -> V_8 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_6 , V_12 ) ;
int V_13 = 0 ;
struct V_14 * V_15 ;
F_3 () ;
F_4 (bond, &bn->dev_list, bond_list) {
if ( V_13 > ( V_16 - V_17 ) ) {
if ( ( V_16 - V_13 ) > 10 )
V_13 = V_16 - 10 ;
V_13 += sprintf ( V_5 + V_13 , L_1 ) ;
break;
}
V_13 += sprintf ( V_5 + V_13 , L_2 , V_15 -> V_18 -> V_19 ) ;
}
if ( V_13 )
V_5 [ V_13 - 1 ] = '\n' ;
F_5 () ;
return V_13 ;
}
static struct V_20 * F_6 ( struct V_6 * V_6 , const char * V_21 )
{
struct V_10 * V_11 = F_2 ( V_6 , V_12 ) ;
struct V_14 * V_15 ;
F_4 (bond, &bn->dev_list, bond_list) {
if ( strncmp ( V_15 -> V_18 -> V_19 , V_21 , V_17 ) == 0 )
return V_15 -> V_18 ;
}
return NULL ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_22 , T_2 V_23 )
{
struct V_6 * V_6 = V_7 -> V_8 -> V_9 ;
char V_24 [ V_17 + 1 ] = { 0 , } ;
char * V_21 ;
int V_25 , V_13 = V_23 ;
sscanf ( V_22 , L_3 , V_24 ) ;
V_21 = V_24 + 1 ;
if ( ( strlen ( V_24 ) <= 1 ) ||
! F_8 ( V_21 ) )
goto V_26;
if ( V_24 [ 0 ] == '+' ) {
F_9 ( L_4 , V_21 ) ;
V_25 = F_10 ( V_6 , V_21 ) ;
if ( V_25 ) {
if ( V_25 == - V_27 )
F_9 ( L_5 , V_21 ) ;
else
F_9 ( L_6 , V_21 ) ;
V_13 = V_25 ;
}
} else if ( V_24 [ 0 ] == '-' ) {
struct V_20 * V_28 ;
F_3 () ;
V_28 = F_6 ( V_6 , V_21 ) ;
if ( V_28 ) {
F_9 ( L_7 , V_21 ) ;
F_11 ( V_28 ) ;
} else {
F_12 ( L_8 , V_21 ) ;
V_13 = - V_29 ;
}
F_5 () ;
} else
goto V_26;
return V_13 ;
V_26:
F_12 ( L_9 ) ;
return - V_30 ;
}
int F_13 ( struct V_20 * V_31 ,
struct V_20 * V_32 )
{
char V_33 [ V_17 + 7 ] ;
int V_34 = 0 ;
V_34 = F_14 ( & ( V_32 -> V_18 . V_35 ) , & ( V_31 -> V_18 . V_35 ) ,
L_10 ) ;
if ( V_34 )
return V_34 ;
sprintf ( V_33 , L_11 , V_32 -> V_19 ) ;
V_34 = F_14 ( & ( V_31 -> V_18 . V_35 ) , & ( V_32 -> V_18 . V_35 ) ,
V_33 ) ;
return V_34 ;
}
void F_15 ( struct V_20 * V_31 ,
struct V_20 * V_32 )
{
char V_33 [ V_17 + 7 ] ;
F_16 ( & ( V_32 -> V_18 . V_35 ) , L_10 ) ;
sprintf ( V_33 , L_11 , V_32 -> V_19 ) ;
F_16 ( & ( V_31 -> V_18 . V_35 ) , V_33 ) ;
}
static T_1 F_17 ( struct V_36 * V_37 ,
struct V_38 * V_4 , char * V_5 )
{
struct V_32 * V_32 ;
int V_39 , V_13 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
F_19 ( & V_15 -> V_40 ) ;
F_20 (bond, slave, i) {
if ( V_13 > ( V_16 - V_17 ) ) {
if ( ( V_16 - V_13 ) > 10 )
V_13 = V_16 - 10 ;
V_13 += sprintf ( V_5 + V_13 , L_1 ) ;
break;
}
V_13 += sprintf ( V_5 + V_13 , L_2 , V_32 -> V_18 -> V_19 ) ;
}
F_21 ( & V_15 -> V_40 ) ;
if ( V_13 )
V_5 [ V_13 - 1 ] = '\n' ;
return V_13 ;
}
static T_1 F_22 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_22 , T_2 V_23 )
{
char V_24 [ V_17 + 1 ] = { 0 , } ;
char * V_21 ;
int V_13 , V_34 = V_23 ;
struct V_20 * V_18 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! F_23 () )
return F_24 () ;
sscanf ( V_22 , L_3 , V_24 ) ;
V_21 = V_24 + 1 ;
if ( ( strlen ( V_24 ) <= 1 ) ||
! F_8 ( V_21 ) )
goto V_26;
V_18 = F_25 ( F_26 ( V_15 -> V_18 ) , V_21 ) ;
if ( ! V_18 ) {
F_9 ( L_12 ,
V_15 -> V_18 -> V_19 , V_21 ) ;
V_34 = - V_29 ;
goto V_41;
}
switch ( V_24 [ 0 ] ) {
case '+' :
F_9 ( L_13 , V_15 -> V_18 -> V_19 , V_18 -> V_19 ) ;
V_13 = F_27 ( V_15 -> V_18 , V_18 ) ;
break;
case '-' :
F_9 ( L_14 , V_15 -> V_18 -> V_19 , V_18 -> V_19 ) ;
V_13 = F_28 ( V_15 -> V_18 , V_18 ) ;
break;
default:
goto V_26;
}
if ( V_13 )
V_34 = V_13 ;
goto V_41;
V_26:
F_12 ( L_15 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
V_41:
F_5 () ;
return V_34 ;
}
static T_1 F_29 ( struct V_36 * V_37 ,
struct V_38 * V_4 , char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_42 [ V_15 -> V_43 . V_44 ] . V_45 ,
V_15 -> V_43 . V_44 ) ;
}
static T_1 F_30 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_18 -> V_47 & V_48 ) {
F_12 ( L_17 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
V_46 = F_31 ( V_5 , V_42 ) ;
if ( V_46 < 0 ) {
F_12 ( L_18 ,
V_15 -> V_18 -> V_19 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( ( V_46 == V_50 ||
V_46 == V_51 ) &&
V_15 -> V_43 . V_52 ) {
F_12 ( L_19 ,
V_15 -> V_18 -> V_19 , V_42 [ V_46 ] . V_45 ) ;
V_34 = - V_49 ;
goto V_41;
}
V_15 -> V_43 . V_44 = V_46 ;
F_32 ( V_15 , V_15 -> V_43 . V_44 ) ;
F_9 ( L_20 ,
V_15 -> V_18 -> V_19 , V_42 [ V_46 ] . V_45 ,
V_46 ) ;
V_41:
return V_34 ;
}
static T_1 F_33 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_53 [ V_15 -> V_43 . V_54 ] . V_45 ,
V_15 -> V_43 . V_54 ) ;
}
static T_1 F_34 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_18 -> V_47 & V_48 ) {
F_12 ( L_21 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
V_46 = F_31 ( V_5 , V_53 ) ;
if ( V_46 < 0 ) {
F_12 ( L_22 ,
V_15 -> V_18 -> V_19 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_49 ;
goto V_41;
} else {
V_15 -> V_43 . V_54 = V_46 ;
F_32 ( V_15 , V_15 -> V_43 . V_44 ) ;
F_9 ( L_23 ,
V_15 -> V_18 -> V_19 ,
V_53 [ V_46 ] . V_45 , V_46 ) ;
}
V_41:
return V_34 ;
}
static T_1 F_35 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_55 [ V_15 -> V_43 . V_56 ] . V_45 ,
V_15 -> V_43 . V_56 ) ;
}
static T_1 F_36 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
V_46 = F_31 ( V_5 , V_55 ) ;
if ( V_46 < 0 ) {
F_12 ( L_24 ,
V_15 -> V_18 -> V_19 , V_5 ) ;
return - V_49 ;
}
if ( V_46 && ( V_15 -> V_43 . V_44 != V_57 ) ) {
F_12 ( L_25 ,
V_15 -> V_18 -> V_19 ) ;
return - V_49 ;
}
F_9 ( L_26 ,
V_15 -> V_18 -> V_19 , V_55 [ V_46 ] . V_45 ,
V_46 ) ;
V_15 -> V_43 . V_56 = V_46 ;
return V_23 ;
}
static T_1 F_37 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_58 [ V_15 -> V_43 . V_59 ] . V_45 ,
V_15 -> V_43 . V_59 ) ;
}
static T_1 F_38 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_60 != 0 ) {
F_12 ( L_27 ,
V_15 -> V_18 -> V_19 ) ;
return - V_30 ;
}
V_46 = F_31 ( V_5 , V_58 ) ;
if ( V_46 < 0 ) {
F_12 ( L_28 ,
V_15 -> V_18 -> V_19 , V_5 ) ;
return - V_49 ;
}
V_15 -> V_43 . V_59 = V_46 ;
F_9 ( L_29 ,
V_15 -> V_18 -> V_19 , V_58 [ V_46 ] . V_45 ,
V_46 ) ;
return V_23 ;
}
static T_1 F_39 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_52 ) ;
}
static T_1 F_40 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_32 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_46 < 0 ) {
F_12 ( L_33 ,
V_15 -> V_18 -> V_19 , V_46 , V_61 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_15 -> V_43 . V_44 == V_50 ||
V_15 -> V_43 . V_44 == V_51 ) {
F_9 ( L_34 ,
V_15 -> V_18 -> V_19 , V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
F_9 ( L_35 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
V_15 -> V_43 . V_52 = V_46 ;
if ( V_15 -> V_43 . V_62 ) {
F_9 ( L_36 ,
V_15 -> V_18 -> V_19 , V_15 -> V_18 -> V_19 ) ;
V_15 -> V_43 . V_62 = 0 ;
if ( F_41 ( & V_15 -> V_63 ) ) {
F_42 ( & V_15 -> V_63 ) ;
F_43 ( V_15 -> V_64 ) ;
}
}
if ( ! V_15 -> V_43 . V_65 [ 0 ] ) {
F_9 ( L_37 ,
V_15 -> V_18 -> V_19 ) ;
}
if ( V_15 -> V_18 -> V_47 & V_48 ) {
if ( ! F_41 ( & V_15 -> V_66 ) ) {
if ( V_15 -> V_43 . V_44 == V_57 )
F_44 ( & V_15 -> V_66 ,
V_67 ) ;
else
F_44 ( & V_15 -> V_66 ,
V_68 ) ;
F_45 ( V_15 -> V_64 , & V_15 -> V_66 , 0 ) ;
}
}
V_41:
return V_34 ;
}
static T_1 F_46 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_39 , V_13 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
for ( V_39 = 0 ; V_39 < V_69 ; V_39 ++ ) {
if ( V_15 -> V_43 . V_65 [ V_39 ] )
V_13 += sprintf ( V_5 + V_13 , L_38 ,
& V_15 -> V_43 . V_65 [ V_39 ] ) ;
}
if ( V_13 )
V_5 [ V_13 - 1 ] = '\n' ;
return V_13 ;
}
static T_1 F_47 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
T_3 V_70 ;
int V_39 = 0 , V_71 = 0 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
T_3 * V_72 ;
V_72 = V_15 -> V_43 . V_65 ;
V_70 = F_48 ( V_5 + 1 ) ;
if ( V_5 [ 0 ] == '+' ) {
if ( ( V_70 == 0 ) || ( V_70 == F_49 ( V_73 ) ) ) {
F_12 ( L_39 ,
V_15 -> V_18 -> V_19 , & V_70 ) ;
V_34 = - V_49 ;
goto V_41;
}
for ( V_39 = 0 ; ( V_39 < V_69 ) && ! V_71 ; V_39 ++ ) {
if ( V_72 [ V_39 ] == V_70 ) {
F_12 ( L_40 ,
V_15 -> V_18 -> V_19 , & V_70 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_72 [ V_39 ] == 0 ) {
F_9 ( L_41 ,
V_15 -> V_18 -> V_19 , & V_70 ) ;
V_71 = 1 ;
V_72 [ V_39 ] = V_70 ;
}
}
if ( ! V_71 ) {
F_12 ( L_42 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
} else if ( V_5 [ 0 ] == '-' ) {
if ( ( V_70 == 0 ) || ( V_70 == F_49 ( V_73 ) ) ) {
F_12 ( L_43 ,
V_15 -> V_18 -> V_19 , & V_70 ) ;
V_34 = - V_49 ;
goto V_41;
}
for ( V_39 = 0 ; ( V_39 < V_69 ) && ! V_71 ; V_39 ++ ) {
if ( V_72 [ V_39 ] == V_70 ) {
int V_74 ;
F_9 ( L_44 ,
V_15 -> V_18 -> V_19 , & V_70 ) ;
for ( V_74 = V_39 ; ( V_74 < ( V_69 - 1 ) ) && V_72 [ V_74 + 1 ] ; V_74 ++ )
V_72 [ V_74 ] = V_72 [ V_74 + 1 ] ;
V_72 [ V_74 ] = 0 ;
V_71 = 1 ;
}
}
if ( ! V_71 ) {
F_9 ( L_45 ,
V_15 -> V_18 -> V_19 , & V_70 ) ;
V_34 = - V_49 ;
goto V_41;
}
} else {
F_12 ( L_46 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
V_41:
return V_34 ;
}
static T_1 F_50 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_75 * V_15 -> V_43 . V_62 ) ;
}
static T_1 F_51 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! ( V_15 -> V_43 . V_62 ) ) {
F_12 ( L_47 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_48 , V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_46 < 0 ) {
F_12 ( L_49 ,
V_15 -> V_18 -> V_19 , V_46 , 1 , V_61 ) ;
V_34 = - V_49 ;
goto V_41;
} else {
if ( ( V_46 % V_15 -> V_43 . V_62 ) != 0 ) {
F_52 ( L_50 ,
V_15 -> V_18 -> V_19 , V_46 ,
V_15 -> V_43 . V_62 ,
( V_46 / V_15 -> V_43 . V_62 ) *
V_15 -> V_43 . V_62 ) ;
}
V_15 -> V_43 . V_75 = V_46 / V_15 -> V_43 . V_62 ;
F_9 ( L_51 ,
V_15 -> V_18 -> V_19 ,
V_15 -> V_43 . V_75 * V_15 -> V_43 . V_62 ) ;
}
V_41:
return V_34 ;
}
static T_1 F_53 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_76 * V_15 -> V_43 . V_62 ) ;
}
static T_1 F_54 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! ( V_15 -> V_43 . V_62 ) ) {
F_12 ( L_52 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_53 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_46 < 0 ) {
F_12 ( L_49 ,
V_15 -> V_18 -> V_19 , V_46 , 1 , V_61 ) ;
V_34 = - V_49 ;
goto V_41;
} else {
if ( ( V_46 % V_15 -> V_43 . V_62 ) != 0 ) {
F_52 ( L_54 ,
V_15 -> V_18 -> V_19 , V_46 ,
V_15 -> V_43 . V_62 ,
( V_46 / V_15 -> V_43 . V_62 ) *
V_15 -> V_43 . V_62 ) ;
}
V_15 -> V_43 . V_76 = V_46 / V_15 -> V_43 . V_62 ;
F_9 ( L_55 ,
V_15 -> V_18 -> V_19 ,
V_15 -> V_43 . V_76 * V_15 -> V_43 . V_62 ) ;
}
V_41:
return V_34 ;
}
static T_1 F_55 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_77 [ V_15 -> V_43 . V_78 ] . V_45 ,
V_15 -> V_43 . V_78 ) ;
}
static T_1 F_56 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_18 -> V_47 & V_48 ) {
F_12 ( L_56 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
if ( V_15 -> V_43 . V_44 != V_79 ) {
F_12 ( L_57 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
V_46 = F_31 ( V_5 , V_77 ) ;
if ( ( V_46 == 1 ) || ( V_46 == 0 ) ) {
V_15 -> V_43 . V_78 = V_46 ;
F_9 ( L_58 ,
V_15 -> V_18 -> V_19 , V_77 [ V_46 ] . V_45 ,
V_46 ) ;
} else {
F_12 ( L_59 ,
V_15 -> V_18 -> V_19 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_49 ;
}
V_41:
return V_34 ;
}
static T_1 F_57 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_80 [ V_15 -> V_43 . V_81 ] . V_45 ,
V_15 -> V_43 . V_81 ) ;
}
static T_1 F_58 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_18 -> V_47 & V_48 ) {
F_12 ( L_60 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
V_46 = F_31 ( V_5 , V_80 ) ;
if ( V_46 != - 1 ) {
V_15 -> V_43 . V_81 = V_46 ;
F_9 ( L_61 ,
V_15 -> V_18 -> V_19 , V_80 [ V_46 ] . V_45 ,
V_46 ) ;
} else {
F_12 ( L_62 ,
V_15 -> V_18 -> V_19 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_49 ;
}
V_41:
return V_34 ;
}
static T_1 F_59 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_82 ) ;
}
static T_1 F_60 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
int V_83 = F_61 ( V_5 , 10 , & V_15 -> V_43 . V_82 ) ;
return V_83 ? V_83 : V_23 ;
}
static T_1 F_62 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_62 ) ;
}
static T_1 F_63 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_63 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_46 < 0 ) {
F_12 ( L_64 ,
V_15 -> V_18 -> V_19 , V_46 , 1 , V_61 ) ;
V_34 = - V_49 ;
goto V_41;
} else {
F_9 ( L_65 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
V_15 -> V_43 . V_62 = V_46 ;
if ( V_15 -> V_43 . V_76 )
F_9 ( L_66 ,
V_15 -> V_18 -> V_19 ,
V_15 -> V_43 . V_76 * V_15 -> V_43 . V_62 ) ;
if ( V_15 -> V_43 . V_75 )
F_9 ( L_67 ,
V_15 -> V_18 -> V_19 ,
V_15 -> V_43 . V_75 * V_15 -> V_43 . V_62 ) ;
if ( V_15 -> V_43 . V_52 ) {
F_9 ( L_68 ,
V_15 -> V_18 -> V_19 ) ;
V_15 -> V_43 . V_52 = 0 ;
if ( V_15 -> V_43 . V_56 ) {
V_15 -> V_43 . V_56 =
V_84 ;
}
if ( F_41 ( & V_15 -> V_66 ) ) {
F_42 ( & V_15 -> V_66 ) ;
F_43 ( V_15 -> V_64 ) ;
}
}
if ( V_15 -> V_18 -> V_47 & V_48 ) {
if ( ! F_41 ( & V_15 -> V_63 ) ) {
F_44 ( & V_15 -> V_63 ,
V_85 ) ;
F_45 ( V_15 -> V_64 ,
& V_15 -> V_63 , 0 ) ;
}
}
}
V_41:
return V_34 ;
}
static T_1 F_64 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_23 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_86 )
V_23 = sprintf ( V_5 , L_69 , V_15 -> V_86 -> V_18 -> V_19 ) ;
return V_23 ;
}
static T_1 F_65 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_39 ;
struct V_32 * V_32 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! F_23 () )
return F_24 () ;
F_66 () ;
F_19 ( & V_15 -> V_40 ) ;
F_67 ( & V_15 -> V_87 ) ;
if ( ! F_68 ( V_15 -> V_43 . V_44 ) ) {
F_9 ( L_70 ,
V_15 -> V_18 -> V_19 , V_15 -> V_18 -> V_19 , V_15 -> V_43 . V_44 ) ;
} else {
F_20 (bond, slave, i) {
if ( F_69
( V_32 -> V_18 -> V_19 , V_5 ,
strlen ( V_32 -> V_18 -> V_19 ) ) == 0 ) {
F_9 ( L_71 ,
V_15 -> V_18 -> V_19 , V_32 -> V_18 -> V_19 ) ;
V_15 -> V_86 = V_32 ;
strcpy ( V_15 -> V_43 . V_88 , V_32 -> V_18 -> V_19 ) ;
F_70 ( V_15 ) ;
goto V_41;
}
}
if ( strlen ( V_5 ) == 0 || V_5 [ 0 ] == '\n' ) {
F_9 ( L_72 ,
V_15 -> V_18 -> V_19 ) ;
V_15 -> V_86 = NULL ;
F_70 ( V_15 ) ;
} else {
F_9 ( L_73 ,
V_15 -> V_18 -> V_19 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
}
}
V_41:
F_71 ( & V_15 -> V_87 ) ;
F_21 ( & V_15 -> V_40 ) ;
F_72 () ;
F_5 () ;
return V_23 ;
}
static T_1 F_73 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_16 ,
V_89 [ V_15 -> V_43 . V_90 ] . V_45 ,
V_15 -> V_43 . V_90 ) ;
}
static T_1 F_74 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! F_23 () )
return F_24 () ;
V_46 = F_31 ( V_5 , V_89 ) ;
if ( V_46 < 0 ) {
F_12 ( L_74 ,
V_15 -> V_18 -> V_19 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_34 = - V_49 ;
goto V_41;
}
V_15 -> V_43 . V_90 = V_46 ;
F_9 ( L_75 ,
V_15 -> V_18 -> V_19 , V_89 [ V_46 ] . V_45 ,
V_46 ) ;
F_66 () ;
F_19 ( & V_15 -> V_40 ) ;
F_67 ( & V_15 -> V_87 ) ;
F_70 ( V_15 ) ;
F_71 ( & V_15 -> V_87 ) ;
F_21 ( & V_15 -> V_40 ) ;
F_72 () ;
V_41:
F_5 () ;
return V_34 ;
}
static T_1 F_75 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_91 ) ;
}
static T_1 F_76 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_76 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( ( V_46 == 0 ) || ( V_46 == 1 ) ) {
V_15 -> V_43 . V_91 = V_46 ;
F_9 ( L_77 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
} else {
F_9 ( L_78 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
}
V_41:
return V_34 ;
}
static T_1 F_77 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_32 * V_92 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
int V_23 = 0 ;
F_19 ( & V_15 -> V_87 ) ;
V_92 = V_15 -> V_93 ;
F_21 ( & V_15 -> V_87 ) ;
if ( F_68 ( V_15 -> V_43 . V_44 ) && V_92 )
V_23 = sprintf ( V_5 , L_69 , V_92 -> V_18 -> V_19 ) ;
return V_23 ;
}
static T_1 F_78 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_39 ;
struct V_32 * V_32 ;
struct V_32 * V_94 = NULL ;
struct V_32 * V_95 = NULL ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! F_23 () )
return F_24 () ;
F_66 () ;
F_19 ( & V_15 -> V_40 ) ;
F_67 ( & V_15 -> V_87 ) ;
if ( ! F_68 ( V_15 -> V_43 . V_44 ) )
F_9 ( L_79 ,
V_15 -> V_18 -> V_19 , V_15 -> V_18 -> V_19 , V_15 -> V_43 . V_44 ) ;
else {
F_20 (bond, slave, i) {
if ( F_69
( V_32 -> V_18 -> V_19 , V_5 ,
strlen ( V_32 -> V_18 -> V_19 ) ) == 0 ) {
V_94 = V_15 -> V_93 ;
V_95 = V_32 ;
if ( V_95 == V_94 ) {
F_9 ( L_80 ,
V_15 -> V_18 -> V_19 ,
V_32 -> V_18 -> V_19 ) ;
goto V_41;
}
else {
if ( ( V_95 ) &&
( V_94 ) &&
( V_95 -> V_96 == V_97 ) &&
F_79 ( V_95 -> V_18 ) ) {
F_9 ( L_81 ,
V_15 -> V_18 -> V_19 ,
V_32 -> V_18 -> V_19 ) ;
F_80 ( V_15 , V_95 ) ;
}
else {
F_9 ( L_82 ,
V_15 -> V_18 -> V_19 ,
V_32 -> V_18 -> V_19 ,
V_32 -> V_18 -> V_19 ) ;
}
goto V_41;
}
}
}
if ( strlen ( V_5 ) == 0 || V_5 [ 0 ] == '\n' ) {
F_9 ( L_83 ,
V_15 -> V_18 -> V_19 ) ;
V_15 -> V_86 = NULL ;
F_70 ( V_15 ) ;
} else {
F_9 ( L_84 ,
V_15 -> V_18 -> V_19 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
}
}
V_41:
F_71 ( & V_15 -> V_87 ) ;
F_21 ( & V_15 -> V_40 ) ;
F_72 () ;
F_5 () ;
return V_23 ;
}
static T_1 F_81 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_32 * V_92 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
F_19 ( & V_15 -> V_87 ) ;
V_92 = V_15 -> V_93 ;
F_21 ( & V_15 -> V_87 ) ;
return sprintf ( V_5 , L_69 , V_92 ? L_85 : L_86 ) ;
}
static T_1 F_82 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_23 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_43 . V_44 == V_79 ) {
struct V_98 V_98 ;
V_23 = sprintf ( V_5 , L_30 ,
( F_83 ( V_15 , & V_98 ) )
? 0 : V_98 . V_99 ) ;
}
return V_23 ;
}
static T_1 F_84 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_23 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_43 . V_44 == V_79 ) {
struct V_98 V_98 ;
V_23 = sprintf ( V_5 , L_30 ,
( F_83 ( V_15 , & V_98 ) )
? 0 : V_98 . V_100 ) ;
}
return V_23 ;
}
static T_1 F_85 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_23 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_43 . V_44 == V_79 ) {
struct V_98 V_98 ;
V_23 = sprintf ( V_5 , L_30 ,
( F_83 ( V_15 , & V_98 ) )
? 0 : V_98 . V_101 ) ;
}
return V_23 ;
}
static T_1 F_86 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_23 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_43 . V_44 == V_79 ) {
struct V_98 V_98 ;
V_23 = sprintf ( V_5 , L_30 ,
( F_83 ( V_15 , & V_98 ) )
? 0 : V_98 . V_102 ) ;
}
return V_23 ;
}
static T_1 F_87 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
int V_23 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( V_15 -> V_43 . V_44 == V_79 ) {
struct V_98 V_98 ;
if ( ! F_83 ( V_15 , & V_98 ) )
V_23 = sprintf ( V_5 , L_87 , V_98 . V_103 ) ;
}
return V_23 ;
}
static T_1 F_88 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_32 * V_32 ;
int V_39 , V_13 = 0 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( ! F_23 () )
return F_24 () ;
F_19 ( & V_15 -> V_40 ) ;
F_20 (bond, slave, i) {
if ( V_13 > ( V_16 - V_17 - 6 ) ) {
if ( ( V_16 - V_13 ) > 10 )
V_13 = V_16 - 10 ;
V_13 += sprintf ( V_5 + V_13 , L_1 ) ;
break;
}
V_13 += sprintf ( V_5 + V_13 , L_88 ,
V_32 -> V_18 -> V_19 , V_32 -> V_104 ) ;
}
F_21 ( & V_15 -> V_40 ) ;
if ( V_13 )
V_5 [ V_13 - 1 ] = '\n' ;
F_5 () ;
return V_13 ;
}
static T_1 F_89 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_22 , T_2 V_23 )
{
struct V_32 * V_32 , * V_105 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
T_4 V_106 ;
int V_39 , V_34 = V_23 ;
char * V_107 ;
struct V_20 * V_108 = NULL ;
if ( ! F_23 () )
return F_24 () ;
V_107 = strchr ( V_22 , ':' ) ;
if ( ! V_107 )
goto V_26;
* V_107 = '\0' ;
if ( sscanf ( ++ V_107 , L_89 , & V_106 ) != 1 )
goto V_26;
if ( strlen ( V_22 ) > V_17 ||
! F_8 ( V_22 ) ||
V_106 > V_15 -> V_43 . V_109 )
goto V_26;
V_108 = F_25 ( F_26 ( V_15 -> V_18 ) , V_22 ) ;
if ( ! V_108 )
goto V_26;
F_19 ( & V_15 -> V_40 ) ;
V_105 = NULL ;
F_20 (bond, slave, i) {
if ( V_108 == V_32 -> V_18 )
V_105 = V_32 ;
else if ( V_106 && V_106 == V_32 -> V_104 ) {
goto V_110;
}
}
if ( ! V_105 )
goto V_110;
V_105 -> V_104 = V_106 ;
F_21 ( & V_15 -> V_40 ) ;
V_41:
F_5 () ;
return V_34 ;
V_110:
F_21 ( & V_15 -> V_40 ) ;
V_26:
F_9 ( L_90 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_30 ;
goto V_41;
}
static T_1 F_90 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_111 ) ;
}
static T_1 F_91 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_39 , V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
struct V_32 * V_32 ;
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_91 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_46 == V_15 -> V_43 . V_111 )
goto V_41;
if ( ( V_46 == 0 ) || ( V_46 == 1 ) ) {
V_15 -> V_43 . V_111 = V_46 ;
} else {
F_9 ( L_92 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
V_34 = - V_49 ;
goto V_41;
}
F_20 (bond, slave, i) {
if ( ! F_92 ( V_32 ) ) {
if ( V_46 )
V_32 -> V_112 = 0 ;
else
V_32 -> V_112 = 1 ;
}
}
V_41:
return V_34 ;
}
static T_1 F_93 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
char * V_5 )
{
struct V_14 * V_15 = F_18 ( V_37 ) ;
return sprintf ( V_5 , L_30 , V_15 -> V_43 . V_113 ) ;
}
static T_1 F_94 ( struct V_36 * V_37 ,
struct V_38 * V_4 ,
const char * V_5 , T_2 V_23 )
{
int V_46 , V_34 = V_23 ;
struct V_14 * V_15 = F_18 ( V_37 ) ;
if ( sscanf ( V_5 , L_31 , & V_46 ) != 1 ) {
F_12 ( L_93 ,
V_15 -> V_18 -> V_19 ) ;
V_34 = - V_49 ;
goto V_41;
}
if ( V_46 < 0 || V_46 > 255 ) {
F_12 ( L_94 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
V_34 = - V_49 ;
goto V_41;
}
F_9 ( L_95 ,
V_15 -> V_18 -> V_19 , V_46 ) ;
V_15 -> V_43 . V_113 = V_46 ;
V_41:
return V_34 ;
}
int F_95 ( void )
{
int V_34 ;
V_34 = F_96 ( & V_114 ) ;
if ( V_34 == - V_27 ) {
if ( F_25 ( & V_115 ,
V_114 . V_4 . V_19 ) )
F_12 ( L_96 ,
V_114 . V_4 . V_19 ) ;
V_34 = 0 ;
}
return V_34 ;
}
void F_97 ( void )
{
F_98 ( & V_114 ) ;
}
void F_99 ( struct V_14 * V_15 )
{
V_15 -> V_18 -> V_116 [ 0 ] = & V_117 ;
}
