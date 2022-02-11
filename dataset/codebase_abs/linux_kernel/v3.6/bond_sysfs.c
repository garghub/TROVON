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
return V_31 ;
}
void F_16 ( struct V_16 * V_28 ,
struct V_16 * V_29 )
{
char V_30 [ V_13 + 7 ] ;
F_17 ( & ( V_29 -> V_14 . V_32 ) , L_10 ) ;
sprintf ( V_30 , L_11 , V_29 -> V_15 ) ;
F_17 ( & ( V_28 -> V_14 . V_32 ) , V_30 ) ;
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
if ( V_11 -> V_40 . V_59 ) {
F_9 ( L_37 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_11 -> V_40 . V_59 = 0 ;
if ( F_42 ( & V_11 -> V_60 ) ) {
F_43 ( & V_11 -> V_60 ) ;
F_44 ( V_11 -> V_61 ) ;
}
}
if ( ! V_11 -> V_40 . V_62 [ 0 ] ) {
F_9 ( L_38 ,
V_11 -> V_14 -> V_15 ) ;
}
if ( V_11 -> V_14 -> V_44 & V_45 ) {
if ( ! F_42 ( & V_11 -> V_63 ) ) {
if ( V_11 -> V_40 . V_41 == V_55 )
F_45 ( & V_11 -> V_63 ,
V_64 ) ;
else
F_45 ( & V_11 -> V_63 ,
V_65 ) ;
F_46 ( V_11 -> V_61 , & V_11 -> V_63 , 0 ) ;
}
}
V_38:
return V_31 ;
}
static T_1 F_47 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_36 , V_9 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
for ( V_36 = 0 ; V_36 < V_66 ; V_36 ++ ) {
if ( V_11 -> V_40 . V_62 [ V_36 ] )
V_9 += sprintf ( V_5 + V_9 , L_39 ,
& V_11 -> V_40 . V_62 [ V_36 ] ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_48 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
T_3 V_67 ;
int V_36 = 0 , V_68 = 0 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
T_3 * V_69 ;
V_69 = V_11 -> V_40 . V_62 ;
V_67 = F_49 ( V_5 + 1 ) ;
if ( V_5 [ 0 ] == '+' ) {
if ( ( V_67 == 0 ) || ( V_67 == F_50 ( V_70 ) ) ) {
F_12 ( L_40 ,
V_11 -> V_14 -> V_15 , & V_67 ) ;
V_31 = - V_47 ;
goto V_38;
}
for ( V_36 = 0 ; ( V_36 < V_66 ) && ! V_68 ; V_36 ++ ) {
if ( V_69 [ V_36 ] == V_67 ) {
F_12 ( L_41 ,
V_11 -> V_14 -> V_15 , & V_67 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_69 [ V_36 ] == 0 ) {
F_9 ( L_42 ,
V_11 -> V_14 -> V_15 , & V_67 ) ;
V_68 = 1 ;
V_69 [ V_36 ] = V_67 ;
}
}
if ( ! V_68 ) {
F_12 ( L_43 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
} else if ( V_5 [ 0 ] == '-' ) {
if ( ( V_67 == 0 ) || ( V_67 == F_50 ( V_70 ) ) ) {
F_12 ( L_44 ,
V_11 -> V_14 -> V_15 , & V_67 ) ;
V_31 = - V_47 ;
goto V_38;
}
for ( V_36 = 0 ; ( V_36 < V_66 ) && ! V_68 ; V_36 ++ ) {
if ( V_69 [ V_36 ] == V_67 ) {
int V_71 ;
F_9 ( L_45 ,
V_11 -> V_14 -> V_15 , & V_67 ) ;
for ( V_71 = V_36 ; ( V_71 < ( V_66 - 1 ) ) && V_69 [ V_71 + 1 ] ; V_71 ++ )
V_69 [ V_71 ] = V_69 [ V_71 + 1 ] ;
V_69 [ V_71 ] = 0 ;
V_68 = 1 ;
}
}
if ( ! V_68 ) {
F_9 ( L_46 ,
V_11 -> V_14 -> V_15 , & V_67 ) ;
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
static T_1 F_51 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_72 * V_11 -> V_40 . V_59 ) ;
}
static T_1 F_52 ( struct V_33 * V_34 ,
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
V_11 -> V_14 -> V_15 , V_43 , 1 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
} else {
if ( ( V_43 % V_11 -> V_40 . V_59 ) != 0 ) {
F_53 ( L_51 ,
V_11 -> V_14 -> V_15 , V_43 ,
V_11 -> V_40 . V_59 ,
( V_43 / V_11 -> V_40 . V_59 ) *
V_11 -> V_40 . V_59 ) ;
}
V_11 -> V_40 . V_72 = V_43 / V_11 -> V_40 . V_59 ;
F_9 ( L_52 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_72 * V_11 -> V_40 . V_59 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_54 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_73 * V_11 -> V_40 . V_59 ) ;
}
static T_1 F_55 ( struct V_33 * V_34 ,
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
F_12 ( L_50 ,
V_11 -> V_14 -> V_15 , V_43 , 1 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
} else {
if ( ( V_43 % V_11 -> V_40 . V_59 ) != 0 ) {
F_53 ( L_55 ,
V_11 -> V_14 -> V_15 , V_43 ,
V_11 -> V_40 . V_59 ,
( V_43 / V_11 -> V_40 . V_59 ) *
V_11 -> V_40 . V_59 ) ;
}
V_11 -> V_40 . V_73 = V_43 / V_11 -> V_40 . V_59 ;
F_9 ( L_56 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_73 * V_11 -> V_40 . V_59 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_56 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_74 [ V_11 -> V_40 . V_75 ] . V_42 ,
V_11 -> V_40 . V_75 ) ;
}
static T_1 F_57 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_44 & V_45 ) {
F_12 ( L_57 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
if ( V_11 -> V_40 . V_41 != V_76 ) {
F_12 ( L_58 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_43 = F_32 ( V_5 , V_74 ) ;
if ( ( V_43 == 1 ) || ( V_43 == 0 ) ) {
V_11 -> V_40 . V_75 = V_43 ;
F_58 ( V_11 ) ;
F_9 ( L_59 ,
V_11 -> V_14 -> V_15 , V_74 [ V_43 ] . V_42 ,
V_43 ) ;
} else {
F_12 ( L_60 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
}
V_38:
return V_31 ;
}
static T_1 F_59 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_77 ) ;
}
static T_1 F_60 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_31 ;
unsigned int V_43 ;
V_31 = F_61 ( V_5 , 0 , & V_43 ) ;
if ( V_31 < 0 ) {
F_12 ( L_61 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return V_31 ;
}
F_9 ( L_62 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_77 = V_43 ;
return V_19 ;
}
static T_1 F_62 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_78 [ V_11 -> V_40 . V_79 ] . V_42 ,
V_11 -> V_40 . V_79 ) ;
}
static T_1 F_63 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_44 & V_45 ) {
F_12 ( L_63 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
V_43 = F_32 ( V_5 , V_78 ) ;
if ( V_43 != - 1 ) {
V_11 -> V_40 . V_79 = V_43 ;
F_9 ( L_64 ,
V_11 -> V_14 -> V_15 , V_78 [ V_43 ] . V_42 ,
V_43 ) ;
} else {
F_12 ( L_65 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
}
V_38:
return V_31 ;
}
static T_1 F_64 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_80 ) ;
}
static T_1 F_65 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_81 = F_66 ( V_5 , 10 , & V_11 -> V_40 . V_80 ) ;
return V_81 ? V_81 : V_19 ;
}
static T_1 F_67 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_59 ) ;
}
static T_1 F_68 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_66 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 ) {
F_12 ( L_67 ,
V_11 -> V_14 -> V_15 , V_43 , 1 , V_58 ) ;
V_31 = - V_47 ;
goto V_38;
} else {
F_9 ( L_68 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_59 = V_43 ;
if ( V_11 -> V_40 . V_73 )
F_9 ( L_69 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_73 * V_11 -> V_40 . V_59 ) ;
if ( V_11 -> V_40 . V_72 )
F_9 ( L_70 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_40 . V_72 * V_11 -> V_40 . V_59 ) ;
if ( V_11 -> V_40 . V_50 ) {
F_9 ( L_71 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_40 . V_50 = 0 ;
if ( V_11 -> V_40 . V_54 ) {
V_11 -> V_40 . V_54 =
V_82 ;
}
if ( F_42 ( & V_11 -> V_63 ) ) {
F_43 ( & V_11 -> V_63 ) ;
F_44 ( V_11 -> V_61 ) ;
}
}
if ( V_11 -> V_14 -> V_44 & V_45 ) {
if ( ! F_42 ( & V_11 -> V_60 ) ) {
F_45 ( & V_11 -> V_60 ,
V_83 ) ;
F_46 ( V_11 -> V_61 ,
& V_11 -> V_60 , 0 ) ;
}
}
}
V_38:
return V_31 ;
}
static T_1 F_69 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_84 )
V_19 = sprintf ( V_5 , L_72 , V_11 -> V_84 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_70 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_36 ;
struct V_29 * V_29 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
char V_17 [ V_13 ] ;
if ( ! F_24 () )
return F_25 () ;
F_71 () ;
F_20 ( & V_11 -> V_37 ) ;
F_72 ( & V_11 -> V_85 ) ;
if ( ! F_73 ( V_11 -> V_40 . V_41 ) ) {
F_9 ( L_73 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_40 . V_41 ) ;
goto V_38;
}
sscanf ( V_5 , L_3 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_74 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_84 = NULL ;
F_74 ( V_11 ) ;
goto V_38;
}
F_21 (bond, slave, i) {
if ( strncmp ( V_29 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
F_9 ( L_75 ,
V_11 -> V_14 -> V_15 , V_29 -> V_14 -> V_15 ) ;
V_11 -> V_84 = V_29 ;
strcpy ( V_11 -> V_40 . V_86 , V_29 -> V_14 -> V_15 ) ;
F_74 ( V_11 ) ;
goto V_38;
}
}
strncpy ( V_11 -> V_40 . V_86 , V_17 , V_13 ) ;
V_11 -> V_40 . V_86 [ V_13 - 1 ] = 0 ;
F_9 ( L_76
L_77 ,
V_11 -> V_14 -> V_15 , V_17 , V_11 -> V_14 -> V_15 ) ;
V_38:
F_75 ( & V_11 -> V_85 ) ;
F_22 ( & V_11 -> V_37 ) ;
F_76 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_77 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_87 [ V_11 -> V_40 . V_88 ] . V_42 ,
V_11 -> V_40 . V_88 ) ;
}
static T_1 F_78 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
V_43 = F_32 ( V_5 , V_87 ) ;
if ( V_43 < 0 ) {
F_12 ( L_78 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_47 ;
goto V_38;
}
V_11 -> V_40 . V_88 = V_43 ;
F_9 ( L_79 ,
V_11 -> V_14 -> V_15 , V_87 [ V_43 ] . V_42 ,
V_43 ) ;
F_71 () ;
F_20 ( & V_11 -> V_37 ) ;
F_72 ( & V_11 -> V_85 ) ;
F_74 ( V_11 ) ;
F_75 ( & V_11 -> V_85 ) ;
F_22 ( & V_11 -> V_37 ) ;
F_76 () ;
V_38:
F_5 () ;
return V_31 ;
}
static T_1 F_79 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_89 ) ;
}
static T_1 F_80 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_80 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( ( V_43 == 0 ) || ( V_43 == 1 ) ) {
V_11 -> V_40 . V_89 = V_43 ;
F_9 ( L_81 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
} else {
F_9 ( L_82 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
}
V_38:
return V_31 ;
}
static T_1 F_81 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_29 * V_90 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_19 = 0 ;
F_20 ( & V_11 -> V_85 ) ;
V_90 = V_11 -> V_91 ;
F_22 ( & V_11 -> V_85 ) ;
if ( F_73 ( V_11 -> V_40 . V_41 ) && V_90 )
V_19 = sprintf ( V_5 , L_72 , V_90 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_82 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_36 ;
struct V_29 * V_29 ;
struct V_29 * V_92 = NULL ;
struct V_29 * V_93 = NULL ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
char V_17 [ V_13 ] ;
if ( ! F_24 () )
return F_25 () ;
F_71 () ;
F_20 ( & V_11 -> V_37 ) ;
F_72 ( & V_11 -> V_85 ) ;
if ( ! F_73 ( V_11 -> V_40 . V_41 ) ) {
F_9 ( L_83 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_40 . V_41 ) ;
goto V_38;
}
sscanf ( V_5 , L_3 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_84 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_91 = NULL ;
F_74 ( V_11 ) ;
goto V_38;
}
F_21 (bond, slave, i) {
if ( strncmp ( V_29 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
V_92 = V_11 -> V_91 ;
V_93 = V_29 ;
if ( V_93 == V_92 ) {
F_9 ( L_85
L_86 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
goto V_38;
}
else {
if ( ( V_93 ) &&
( V_92 ) &&
( V_93 -> V_94 == V_95 ) &&
F_83 ( V_93 -> V_14 ) ) {
F_9 ( L_87
L_88 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
F_84 ( V_11 ,
V_93 ) ;
}
else {
F_9 ( L_89
L_90
L_91 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
}
goto V_38;
}
}
}
F_9 ( L_92 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_38:
F_75 ( & V_11 -> V_85 ) ;
F_22 ( & V_11 -> V_37 ) ;
F_76 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_85 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_29 * V_90 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
F_20 ( & V_11 -> V_85 ) ;
V_90 = V_11 -> V_91 ;
F_22 ( & V_11 -> V_85 ) ;
return sprintf ( V_5 , L_72 , V_90 ? L_93 : L_94 ) ;
}
static T_1 F_86 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_76 ) {
struct V_96 V_96 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_87 ( V_11 , & V_96 ) )
? 0 : V_96 . V_97 ) ;
}
return V_19 ;
}
static T_1 F_88 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_76 ) {
struct V_96 V_96 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_87 ( V_11 , & V_96 ) )
? 0 : V_96 . V_98 ) ;
}
return V_19 ;
}
static T_1 F_89 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_76 ) {
struct V_96 V_96 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_87 ( V_11 , & V_96 ) )
? 0 : V_96 . V_99 ) ;
}
return V_19 ;
}
static T_1 F_90 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_76 ) {
struct V_96 V_96 ;
V_19 = sprintf ( V_5 , L_31 ,
( F_87 ( V_11 , & V_96 ) )
? 0 : V_96 . V_100 ) ;
}
return V_19 ;
}
static T_1 F_91 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_40 . V_41 == V_76 ) {
struct V_96 V_96 ;
if ( ! F_87 ( V_11 , & V_96 ) )
V_19 = sprintf ( V_5 , L_95 , V_96 . V_101 ) ;
}
return V_19 ;
}
static T_1 F_92 ( struct V_33 * V_34 ,
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
V_9 += sprintf ( V_5 + V_9 , L_96 ,
V_29 -> V_14 -> V_15 , V_29 -> V_102 ) ;
}
F_22 ( & V_11 -> V_37 ) ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static T_1 F_93 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_29 * V_29 , * V_103 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
T_4 V_104 ;
int V_36 , V_31 = V_19 ;
char * V_105 ;
struct V_16 * V_106 = NULL ;
if ( ! F_24 () )
return F_25 () ;
V_105 = strchr ( V_18 , ':' ) ;
if ( ! V_105 )
goto V_22;
* V_105 = '\0' ;
if ( sscanf ( ++ V_105 , L_97 , & V_104 ) != 1 )
goto V_22;
if ( strlen ( V_18 ) > V_13 ||
! F_8 ( V_18 ) ||
V_104 > V_11 -> V_14 -> V_107 )
goto V_22;
V_106 = F_26 ( F_27 ( V_11 -> V_14 ) , V_18 ) ;
if ( ! V_106 )
goto V_22;
F_20 ( & V_11 -> V_37 ) ;
V_103 = NULL ;
F_21 (bond, slave, i) {
if ( V_106 == V_29 -> V_14 )
V_103 = V_29 ;
else if ( V_104 && V_104 == V_29 -> V_102 ) {
goto V_108;
}
}
if ( ! V_103 )
goto V_108;
V_103 -> V_102 = V_104 ;
F_22 ( & V_11 -> V_37 ) ;
V_38:
F_5 () ;
return V_31 ;
V_108:
F_22 ( & V_11 -> V_37 ) ;
V_22:
F_9 ( L_98 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_38;
}
static T_1 F_94 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_109 ) ;
}
static T_1 F_95 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_36 , V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
struct V_29 * V_29 ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_99 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 == V_11 -> V_40 . V_109 )
goto V_38;
if ( ( V_43 == 0 ) || ( V_43 == 1 ) ) {
V_11 -> V_40 . V_109 = V_43 ;
} else {
F_9 ( L_100 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_31 = - V_47 ;
goto V_38;
}
F_21 (bond, slave, i) {
if ( ! F_96 ( V_29 ) ) {
if ( V_43 )
V_29 -> V_110 = 0 ;
else
V_29 -> V_110 = 1 ;
}
}
V_38:
return V_31 ;
}
static T_1 F_97 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_31 , V_11 -> V_40 . V_111 ) ;
}
static T_1 F_98 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_43 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_32 , & V_43 ) != 1 ) {
F_12 ( L_101 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_47 ;
goto V_38;
}
if ( V_43 < 0 || V_43 > 255 ) {
F_12 ( L_102 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_31 = - V_47 ;
goto V_38;
}
F_9 ( L_103 ,
V_11 -> V_14 -> V_15 , V_43 ) ;
V_11 -> V_40 . V_111 = V_43 ;
V_38:
return V_31 ;
}
int F_99 ( struct V_6 * V_7 )
{
int V_31 ;
V_7 -> V_8 = V_8 ;
F_100 ( & V_7 -> V_8 . V_4 ) ;
V_31 = F_101 ( & V_7 -> V_8 ) ;
if ( V_31 == - V_24 ) {
if ( F_26 ( V_7 -> V_23 ,
V_8 . V_4 . V_15 ) )
F_12 ( L_104 ,
V_8 . V_4 . V_15 ) ;
V_31 = 0 ;
}
return V_31 ;
}
void F_102 ( struct V_6 * V_7 )
{
F_103 ( & V_7 -> V_8 ) ;
}
void F_104 ( struct V_10 * V_11 )
{
V_11 -> V_14 -> V_112 [ 0 ] = & V_113 ;
}
