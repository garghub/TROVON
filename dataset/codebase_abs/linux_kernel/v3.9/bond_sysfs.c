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
static const void * F_13 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
return V_7 -> V_23 ;
}
int F_14 ( struct V_16 * V_28 ,
struct V_16 * V_29 )
{
char V_30 [ V_13 + 7 ] ;
int V_31 = 0 ;
V_31 = F_15 ( & ( V_29 -> V_14 . V_32 ) , & ( V_28 -> V_14 . V_32 ) ,
L_10 ) ;
if ( V_31 )
return V_31 ;
sprintf ( V_30 , L_11 , V_29 -> V_15 ) ;
V_31 = F_15 ( & ( V_28 -> V_14 . V_32 ) , & ( V_29 -> V_14 . V_32 ) ,
V_30 ) ;
if ( V_31 )
F_16 ( & ( V_29 -> V_14 . V_32 ) , L_10 ) ;
return V_31 ;
}
void F_17 ( struct V_16 * V_28 ,
struct V_16 * V_29 )
{
char V_30 [ V_13 + 7 ] ;
F_16 ( & ( V_29 -> V_14 . V_32 ) , L_10 ) ;
sprintf ( V_30 , L_11 , V_29 -> V_15 ) ;
F_16 ( & ( V_28 -> V_14 . V_32 ) , V_30 ) ;
}
static T_1 F_18 ( struct V_33 * V_34 ,
struct V_35 * V_4 , char * V_5 )
{
struct V_29 * V_29 ;
int V_36 , V_9 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
F_20 ( & V_11 -> V_37 ) ;
F_21 (bond, slave, i) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_29 -> V_14 -> V_15 ) ;
}
F_22 ( & V_11 -> V_37 ) ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_23 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_18 , T_2 V_19 )
{
char V_20 [ V_13 + 1 ] = { 0 , } ;
char * V_17 ;
int V_9 , V_31 = V_19 ;
struct V_16 * V_14 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
sscanf ( V_18 , L_3 , V_20 ) ;
V_17 = V_20 + 1 ;
if ( ( strlen ( V_20 ) <= 1 ) ||
! F_8 ( V_17 ) )
goto V_22;
V_14 = F_26 ( F_27 ( V_11 -> V_14 ) , V_17 ) ;
if ( ! V_14 ) {
F_9 ( L_12 ,
V_11 -> V_14 -> V_15 , V_17 ) ;
V_31 = - V_26 ;
goto V_38;
}
switch ( V_20 [ 0 ] ) {
case '+' :
F_9 ( L_13 , V_11 -> V_14 -> V_15 , V_14 -> V_15 ) ;
V_9 = F_28 ( V_11 -> V_14 , V_14 ) ;
break;
case '-' :
F_9 ( L_14 , V_11 -> V_14 -> V_15 , V_14 -> V_15 ) ;
V_9 = F_29 ( V_11 -> V_14 , V_14 ) ;
break;
default:
goto V_22;
}
if ( V_9 )
V_31 = V_9 ;
goto V_38;
V_22:
F_12 ( L_15 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
V_38:
F_5 () ;
return V_31 ;
}
static T_1 F_30 ( struct V_33 * V_34 ,
struct V_35 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_39 [ V_11 -> V_40 . V_41 ] . V_42 ,
V_11 -> V_40 . V_41 ) ;
}
static T_1 F_31 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_44 & V_45 ) {
F_12 ( L_17 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
if ( V_11 -> V_46 > 0 ) {
F_12 ( L_18 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_43 = F_32 ( V_5 , V_39 ) ;
if ( V_43 < 0 ) {
F_12 ( L_19 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( ( V_43 == V_48 ||
V_43 == V_49 ) &&
V_11 -> V_40 . V_50 ) {
F_12 ( L_20 ,
V_11 -> V_14 -> V_15 , V_39 [ V_43 ] . V_42 ) ;
V_31 = - V_47 ;
goto V_38;
}
V_11 -> V_40 . V_41 = V_43 ;
F_33 ( V_11 , V_11 -> V_40 . V_41 ) ;
F_9 ( L_21 ,
V_11 -> V_14 -> V_15 , V_39 [ V_43 ] . V_42 ,
V_43 ) ;
V_38:
return V_31 ;
}
static T_1 F_34 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_51 [ V_11 -> V_40 . V_52 ] . V_42 ,
V_11 -> V_40 . V_52 ) ;
}
static T_1 F_35 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_44 & V_45 ) {
F_12 ( L_22 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_43 = F_32 ( V_5 , V_51 ) ;
if ( V_43 < 0 ) {
F_12 ( L_23 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
goto V_38;
} else {
V_11 -> V_40 . V_52 = V_43 ;
F_33 ( V_11 , V_11 -> V_40 . V_41 ) ;
F_9 ( L_24 ,
V_11 -> V_14 -> V_15 ,
V_51 [ V_43 ] . V_42 , V_43 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_36 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_53 [ V_11 -> V_40 . V_54 ] . V_42 ,
V_11 -> V_40 . V_54 ) ;
}
static T_1 F_37 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
V_43 = F_32 ( V_5 , V_53 ) ;
if ( V_43 < 0 ) {
F_12 ( L_25 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return - V_47 ;
}
if ( V_43 && ( V_11 -> V_40 . V_41 != V_55 ) ) {
F_12 ( L_26 ,
V_11 -> V_14 -> V_15 ) ;
return - V_47 ;
}
F_9 ( L_27 ,
V_11 -> V_14 -> V_15 , V_53 [ V_43 ] . V_42 ,
V_43 ) ;
V_11 -> V_40 . V_54 = V_43 ;
return V_19 ;
}
static T_1 F_38 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_56 [ V_11 -> V_40 . V_57 ] . V_42 ,
V_11 -> V_40 . V_57 ) ;
}
static T_1 F_39 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_46 != 0 ) {
F_12 ( L_28 ,
V_11 -> V_14 -> V_15 ) ;
return - V_27 ;
}
V_43 = F_32 ( V_5 , V_56 ) ;
if ( V_43 < 0 ) {
F_12 ( L_29 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return - V_47 ;
}
V_11 -> V_40 . V_57 = V_43 ;
F_9 ( L_30 ,
V_11 -> V_14 -> V_15 , V_56 [ V_43 ] . V_42 ,
V_43 ) ;
return V_19 ;
}
static T_1 F_40 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_50 ) ;
}
static T_1 F_41 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_33 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 ) {
F_12 ( L_34 ,
V_11 -> V_14 -> V_15 , V_43 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_11 -> V_40 . V_41 == V_48 ||
V_11 -> V_40 . V_41 == V_49 ) {
F_9 ( L_35 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
F_9 ( L_36 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_50 = V_43 ;
if ( V_43 ) {
if ( V_11 -> V_40 . V_59 ) {
F_9 ( L_37 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_11 -> V_40 . V_59 = 0 ;
}
if ( ! V_11 -> V_40 . V_60 [ 0 ] )
F_9 ( L_38 ,
V_11 -> V_14 -> V_15 ) ;
}
if ( V_11 -> V_14 -> V_44 & V_45 ) {
if ( ! V_43 ) {
F_42 ( & V_11 -> V_61 ) ;
} else {
F_42 ( & V_11 -> V_62 ) ;
F_43 ( V_11 -> V_63 , & V_11 -> V_61 , 0 ) ;
}
}
V_38:
F_5 () ;
return V_31 ;
}
static T_1 F_44 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_36 , V_9 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
for ( V_36 = 0 ; V_36 < V_64 ; V_36 ++ ) {
if ( V_11 -> V_40 . V_60 [ V_36 ] )
V_9 += sprintf ( V_5 + V_9 , L_39 ,
& V_11 -> V_40 . V_60 [ V_36 ] ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_45 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
T_3 V_65 ;
int V_36 = 0 , V_66 = 0 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
T_3 * V_67 ;
V_67 = V_11 -> V_40 . V_60 ;
V_65 = F_46 ( V_5 + 1 ) ;
if ( V_5 [ 0 ] == '+' ) {
if ( ( V_65 == 0 ) || ( V_65 == F_47 ( V_68 ) ) ) {
F_12 ( L_40 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
V_31 = - V_47 ;
goto V_38;
}
for ( V_36 = 0 ; ( V_36 < V_64 ) && ! V_66 ; V_36 ++ ) {
if ( V_67 [ V_36 ] == V_65 ) {
F_12 ( L_41 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_67 [ V_36 ] == 0 ) {
F_9 ( L_42 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
V_66 = 1 ;
V_67 [ V_36 ] = V_65 ;
}
}
if ( ! V_66 ) {
F_12 ( L_43 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
} else if ( V_5 [ 0 ] == '-' ) {
if ( ( V_65 == 0 ) || ( V_65 == F_47 ( V_68 ) ) ) {
F_12 ( L_44 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
V_31 = - V_47 ;
goto V_38;
}
for ( V_36 = 0 ; ( V_36 < V_64 ) && ! V_66 ; V_36 ++ ) {
if ( V_67 [ V_36 ] == V_65 ) {
int V_69 ;
F_9 ( L_45 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
for ( V_69 = V_36 ; ( V_69 < ( V_64 - 1 ) ) && V_67 [ V_69 + 1 ] ; V_69 ++ )
V_67 [ V_69 ] = V_67 [ V_69 + 1 ] ;
V_67 [ V_69 ] = 0 ;
V_66 = 1 ;
}
}
if ( ! V_66 ) {
F_9 ( L_46 ,
V_11 -> V_14 -> V_15 , & V_65 ) ;
V_31 = - V_47 ;
goto V_38;
}
} else {
F_12 ( L_47 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_38:
return V_31 ;
}
static T_1 F_48 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_70 * V_11 -> V_40 . V_59 ) ;
}
static T_1 F_49 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! ( V_11 -> V_40 . V_59 ) ) {
F_12 ( L_48 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_49 , V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 ) {
F_12 ( L_50 ,
V_11 -> V_14 -> V_15 , V_43 , 0 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
} else {
if ( ( V_43 % V_11 -> V_40 . V_59 ) != 0 ) {
F_50 ( L_51 ,
V_11 -> V_14 -> V_15 , V_43 ,
V_11 -> V_40 . V_59 ,
( V_43 / V_11 -> V_40 . V_59 ) *
V_11 -> V_40 . V_59 ) ;
}
V_11 -> V_40 . V_70 = V_43 / V_11 -> V_40 . V_59 ;
F_9 ( L_52 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_70 * V_11 -> V_40 . V_59 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_51 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_71 * V_11 -> V_40 . V_59 ) ;
}
static T_1 F_52 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! ( V_11 -> V_40 . V_59 ) ) {
F_12 ( L_53 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_54 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 ) {
F_12 ( L_55 ,
V_11 -> V_14 -> V_15 , V_43 , 0 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
} else {
if ( ( V_43 % V_11 -> V_40 . V_59 ) != 0 ) {
F_50 ( L_56 ,
V_11 -> V_14 -> V_15 , V_43 ,
V_11 -> V_40 . V_59 ,
( V_43 / V_11 -> V_40 . V_59 ) *
V_11 -> V_40 . V_59 ) ;
}
V_11 -> V_40 . V_71 = V_43 / V_11 -> V_40 . V_59 ;
F_9 ( L_57 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_71 * V_11 -> V_40 . V_59 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_53 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_72 [ V_11 -> V_40 . V_73 ] . V_42 ,
V_11 -> V_40 . V_73 ) ;
}
static T_1 F_54 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_44 & V_45 ) {
F_12 ( L_58 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
if ( V_11 -> V_40 . V_41 != V_74 ) {
F_12 ( L_59 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_43 = F_32 ( V_5 , V_72 ) ;
if ( ( V_43 == 1 ) || ( V_43 == 0 ) ) {
V_11 -> V_40 . V_73 = V_43 ;
F_55 ( V_11 ) ;
F_9 ( L_60 ,
V_11 -> V_14 -> V_15 , V_72 [ V_43 ] . V_42 ,
V_43 ) ;
} else {
F_12 ( L_61 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
}
V_38:
return V_31 ;
}
static T_1 F_56 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_75 ) ;
}
static T_1 F_57 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_31 ;
unsigned int V_43 ;
V_31 = F_58 ( V_5 , 0 , & V_43 ) ;
if ( V_31 < 0 ) {
F_12 ( L_62 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return V_31 ;
}
F_9 ( L_63 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_75 = V_43 ;
return V_19 ;
}
static T_1 F_59 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_76 [ V_11 -> V_40 . V_77 ] . V_42 ,
V_11 -> V_40 . V_77 ) ;
}
static T_1 F_60 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_44 & V_45 ) {
F_12 ( L_64 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_43 = F_32 ( V_5 , V_76 ) ;
if ( V_43 != - 1 ) {
V_11 -> V_40 . V_77 = V_43 ;
F_9 ( L_65 ,
V_11 -> V_14 -> V_15 , V_76 [ V_43 ] . V_42 ,
V_43 ) ;
} else {
F_12 ( L_66 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
}
V_38:
return V_31 ;
}
static T_1 F_61 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_78 ) ;
}
static T_1 F_62 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_79 = F_63 ( V_5 , 10 , & V_11 -> V_40 . V_78 ) ;
return V_79 ? V_79 : V_19 ;
}
static T_1 F_64 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_59 ) ;
}
static T_1 F_65 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_67 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 ) {
F_12 ( L_68 ,
V_11 -> V_14 -> V_15 , V_43 , 0 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
}
F_9 ( L_69 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_59 = V_43 ;
if ( V_11 -> V_40 . V_71 )
F_9 ( L_70 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_71 * V_11 -> V_40 . V_59 ) ;
if ( V_11 -> V_40 . V_70 )
F_9 ( L_71 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_70 * V_11 -> V_40 . V_59 ) ;
if ( V_43 && V_11 -> V_40 . V_50 ) {
F_9 ( L_72 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_40 . V_50 = 0 ;
if ( V_11 -> V_40 . V_54 )
V_11 -> V_40 . V_54 = V_80 ;
}
if ( V_11 -> V_14 -> V_44 & V_45 ) {
if ( ! V_43 ) {
F_42 ( & V_11 -> V_62 ) ;
} else {
F_42 ( & V_11 -> V_61 ) ;
F_43 ( V_11 -> V_63 , & V_11 -> V_62 , 0 ) ;
}
}
V_38:
F_5 () ;
return V_31 ;
}
static T_1 F_66 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_81 )
V_19 = sprintf ( V_5 , L_73 , V_11 -> V_81 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_67 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_36 ;
struct V_29 * V_29 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
char V_17 [ V_13 ] ;
if ( ! F_24 () )
return F_25 () ;
F_68 () ;
F_20 ( & V_11 -> V_37 ) ;
F_69 ( & V_11 -> V_82 ) ;
if ( ! F_70 ( V_11 -> V_40 . V_41 ) ) {
F_9 ( L_74 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_40 . V_41 ) ;
goto V_38;
}
sscanf ( V_5 , L_75 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_76 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_81 = NULL ;
memset ( V_11 -> V_40 . V_83 , 0 , sizeof( V_11 -> V_40 . V_83 ) ) ;
F_71 ( V_11 ) ;
goto V_38;
}
F_21 (bond, slave, i) {
if ( strncmp ( V_29 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
F_9 ( L_77 ,
V_11 -> V_14 -> V_15 , V_29 -> V_14 -> V_15 ) ;
V_11 -> V_81 = V_29 ;
strcpy ( V_11 -> V_40 . V_83 , V_29 -> V_14 -> V_15 ) ;
F_71 ( V_11 ) ;
goto V_38;
}
}
strncpy ( V_11 -> V_40 . V_83 , V_17 , V_13 ) ;
V_11 -> V_40 . V_83 [ V_13 - 1 ] = 0 ;
F_9 ( L_78
L_79 ,
V_11 -> V_14 -> V_15 , V_17 , V_11 -> V_14 -> V_15 ) ;
V_38:
F_72 ( & V_11 -> V_82 ) ;
F_22 ( & V_11 -> V_37 ) ;
F_73 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_74 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_84 [ V_11 -> V_40 . V_85 ] . V_42 ,
V_11 -> V_40 . V_85 ) ;
}
static T_1 F_75 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
V_43 = F_32 ( V_5 , V_84 ) ;
if ( V_43 < 0 ) {
F_12 ( L_80 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
goto V_38;
}
V_11 -> V_40 . V_85 = V_43 ;
F_9 ( L_81 ,
V_11 -> V_14 -> V_15 , V_84 [ V_43 ] . V_42 ,
V_43 ) ;
F_68 () ;
F_20 ( & V_11 -> V_37 ) ;
F_69 ( & V_11 -> V_82 ) ;
F_71 ( V_11 ) ;
F_72 ( & V_11 -> V_82 ) ;
F_22 ( & V_11 -> V_37 ) ;
F_73 () ;
V_38:
F_5 () ;
return V_31 ;
}
static T_1 F_76 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_86 ) ;
}
static T_1 F_77 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_82 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( ( V_43 == 0 ) || ( V_43 == 1 ) ) {
V_11 -> V_40 . V_86 = V_43 ;
F_9 ( L_83 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
} else {
F_9 ( L_84 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_78 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_29 * V_87 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_19 = 0 ;
F_20 ( & V_11 -> V_82 ) ;
V_87 = V_11 -> V_88 ;
F_22 ( & V_11 -> V_82 ) ;
if ( F_70 ( V_11 -> V_40 . V_41 ) && V_87 )
V_19 = sprintf ( V_5 , L_73 , V_87 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_79 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_36 ;
struct V_29 * V_29 ;
struct V_29 * V_89 = NULL ;
struct V_29 * V_90 = NULL ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
char V_17 [ V_13 ] ;
if ( ! F_24 () )
return F_25 () ;
F_68 () ;
F_20 ( & V_11 -> V_37 ) ;
F_69 ( & V_11 -> V_82 ) ;
if ( ! F_70 ( V_11 -> V_40 . V_41 ) ) {
F_9 ( L_85 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_40 . V_41 ) ;
goto V_38;
}
sscanf ( V_5 , L_75 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_86 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_88 = NULL ;
F_71 ( V_11 ) ;
goto V_38;
}
F_21 (bond, slave, i) {
if ( strncmp ( V_29 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
V_89 = V_11 -> V_88 ;
V_90 = V_29 ;
if ( V_90 == V_89 ) {
F_9 ( L_87
L_88 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
goto V_38;
}
else {
if ( ( V_90 ) &&
( V_89 ) &&
( V_90 -> V_91 == V_92 ) &&
F_80 ( V_90 -> V_14 ) ) {
F_9 ( L_89
L_90 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
F_81 ( V_11 ,
V_90 ) ;
}
else {
F_9 ( L_91
L_92
L_93 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
}
goto V_38;
}
}
}
F_9 ( L_94 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_38:
F_72 ( & V_11 -> V_82 ) ;
F_22 ( & V_11 -> V_37 ) ;
F_73 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_82 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_29 * V_87 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
F_20 ( & V_11 -> V_82 ) ;
V_87 = V_11 -> V_88 ;
F_22 ( & V_11 -> V_82 ) ;
return sprintf ( V_5 , L_73 , V_87 ? L_95 : L_96 ) ;
}
static T_1 F_83 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_74 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_84 ( V_11 , & V_93 ) )
? 0 : V_93 . V_94 ) ;
}
return V_19 ;
}
static T_1 F_85 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_74 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_84 ( V_11 , & V_93 ) )
? 0 : V_93 . V_95 ) ;
}
return V_19 ;
}
static T_1 F_86 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_74 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_84 ( V_11 , & V_93 ) )
? 0 : V_93 . V_96 ) ;
}
return V_19 ;
}
static T_1 F_87 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_74 ) {
struct V_93 V_93 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_84 ( V_11 , & V_93 ) )
? 0 : V_93 . V_97 ) ;
}
return V_19 ;
}
static T_1 F_88 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_74 ) {
struct V_93 V_93 ;
if ( ! F_84 ( V_11 , & V_93 ) )
V_19 = sprintf ( V_5 , L_97 , V_93 . V_98 ) ;
}
return V_19 ;
}
static T_1 F_89 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_29 * V_29 ;
int V_36 , V_9 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
F_20 ( & V_11 -> V_37 ) ;
F_21 (bond, slave, i) {
if ( V_9 > ( V_12 - V_13 - 6 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_98 ,
V_29 -> V_14 -> V_15 , V_29 -> V_99 ) ;
}
F_22 ( & V_11 -> V_37 ) ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static T_1 F_90 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_29 * V_29 , * V_100 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
T_4 V_101 ;
int V_36 , V_31 = V_19 ;
char * V_102 ;
struct V_16 * V_103 = NULL ;
if ( ! F_24 () )
return F_25 () ;
V_102 = strchr ( V_18 , ':' ) ;
if ( ! V_102 )
goto V_22;
* V_102 = '\0' ;
if ( sscanf ( ++ V_102 , L_99 , & V_101 ) != 1 )
goto V_22;
if ( strlen ( V_18 ) > V_13 ||
! F_8 ( V_18 ) ||
V_101 > V_11 -> V_14 -> V_104 )
goto V_22;
V_103 = F_26 ( F_27 ( V_11 -> V_14 ) , V_18 ) ;
if ( ! V_103 )
goto V_22;
F_20 ( & V_11 -> V_37 ) ;
V_100 = NULL ;
F_21 (bond, slave, i) {
if ( V_103 == V_29 -> V_14 )
V_100 = V_29 ;
else if ( V_101 && V_101 == V_29 -> V_99 ) {
goto V_105;
}
}
if ( ! V_100 )
goto V_105;
V_100 -> V_99 = V_101 ;
F_22 ( & V_11 -> V_37 ) ;
V_38:
F_5 () ;
return V_31 ;
V_105:
F_22 ( & V_11 -> V_37 ) ;
V_22:
F_9 ( L_100 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
static T_1 F_91 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_106 ) ;
}
static T_1 F_92 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_36 , V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
struct V_29 * V_29 ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_101 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 == V_11 -> V_40 . V_106 )
goto V_38;
if ( ( V_43 == 0 ) || ( V_43 == 1 ) ) {
V_11 -> V_40 . V_106 = V_43 ;
} else {
F_9 ( L_102 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_31 = - V_47 ;
goto V_38;
}
F_20 ( & V_11 -> V_37 ) ;
F_21 (bond, slave, i) {
if ( ! F_93 ( V_29 ) ) {
if ( V_43 )
V_29 -> V_107 = 0 ;
else
V_29 -> V_107 = 1 ;
}
}
F_22 ( & V_11 -> V_37 ) ;
V_38:
return V_31 ;
}
static T_1 F_94 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_108 ) ;
}
static T_1 F_95 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_103 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 || V_43 > 255 ) {
F_12 ( L_104 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_31 = - V_47 ;
goto V_38;
}
F_9 ( L_105 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_108 = V_43 ;
V_38:
return V_31 ;
}
int F_96 ( struct V_6 * V_7 )
{
int V_31 ;
V_7 -> V_8 = V_8 ;
F_97 ( & V_7 -> V_8 . V_4 ) ;
V_31 = F_98 ( & V_7 -> V_8 ) ;
if ( V_31 == - V_24 ) {
if ( F_26 ( V_7 -> V_23 ,
V_8 . V_4 . V_15 ) )
F_12 ( L_106 ,
V_8 . V_4 . V_15 ) ;
V_31 = 0 ;
}
return V_31 ;
}
void F_99 ( struct V_6 * V_7 )
{
F_100 ( & V_7 -> V_8 ) ;
}
void F_101 ( struct V_10 * V_11 )
{
V_11 -> V_14 -> V_109 [ 0 ] = & V_110 ;
}
