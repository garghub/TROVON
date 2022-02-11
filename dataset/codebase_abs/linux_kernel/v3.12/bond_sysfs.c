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
struct V_10 * V_11 = F_19 ( V_34 ) ;
struct V_29 * V_29 ;
int V_9 = 0 ;
F_20 ( & V_11 -> V_36 ) ;
F_21 (bond, slave) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_29 -> V_14 -> V_15 ) ;
}
F_22 ( & V_11 -> V_36 ) ;
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
goto V_37;
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
goto V_37;
V_22:
F_12 ( L_15 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_30 ( struct V_33 * V_34 ,
struct V_35 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_38 [ V_11 -> V_39 . V_40 ] . V_41 ,
V_11 -> V_39 . V_40 ) ;
}
static T_1 F_31 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
if ( V_11 -> V_14 -> V_43 & V_44 ) {
F_12 ( L_17 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
if ( ! F_32 ( & V_11 -> V_45 ) ) {
F_12 ( L_18 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
V_42 = F_33 ( V_5 , V_38 ) ;
if ( V_42 < 0 ) {
F_12 ( L_19 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( ( V_42 == V_47 ||
V_42 == V_48 ) &&
V_11 -> V_39 . V_49 ) {
F_12 ( L_20 ,
V_11 -> V_14 -> V_15 , V_38 [ V_42 ] . V_41 ) ;
V_31 = - V_46 ;
goto V_37;
}
V_11 -> V_39 . V_50 = V_51 ;
V_11 -> V_39 . V_40 = V_42 ;
F_34 ( V_11 , V_11 -> V_39 . V_40 ) ;
F_9 ( L_21 ,
V_11 -> V_14 -> V_15 , V_38 [ V_42 ] . V_41 ,
V_42 ) ;
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_35 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_52 [ V_11 -> V_39 . V_53 ] . V_41 ,
V_11 -> V_39 . V_53 ) ;
}
static T_1 F_36 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
V_42 = F_33 ( V_5 , V_52 ) ;
if ( V_42 < 0 ) {
F_12 ( L_22 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_46 ;
} else {
V_11 -> V_39 . V_53 = V_42 ;
F_34 ( V_11 , V_11 -> V_39 . V_40 ) ;
F_9 ( L_23 ,
V_11 -> V_14 -> V_15 ,
V_52 [ V_42 ] . V_41 , V_42 ) ;
}
return V_31 ;
}
static T_1 F_37 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_54 [ V_11 -> V_39 . V_50 ] . V_41 ,
V_11 -> V_39 . V_50 ) ;
}
static T_1 F_38 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_42 , V_31 = V_19 ;
if ( ! F_24 () )
return F_25 () ;
V_42 = F_33 ( V_5 , V_54 ) ;
if ( V_42 < 0 ) {
F_12 ( L_24 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_11 -> V_39 . V_40 != V_55 ) {
F_12 ( L_25 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
F_9 ( L_26 ,
V_11 -> V_14 -> V_15 , V_54 [ V_42 ] . V_41 ,
V_42 ) ;
if ( V_11 -> V_14 -> V_43 & V_44 ) {
if ( ! V_42 )
V_11 -> V_56 = NULL ;
else if ( V_11 -> V_39 . V_49 )
V_11 -> V_56 = V_57 ;
}
V_11 -> V_39 . V_50 = V_42 ;
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_39 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_58 = V_11 -> V_39 . V_59 ;
return sprintf ( V_5 , L_16 , V_60 [ V_58 ] . V_41 ,
V_58 ) ;
}
static T_1 F_40 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_42 ;
V_42 = F_33 ( V_5 , V_60 ) ;
if ( V_42 < 0 ) {
F_12 ( L_27 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return - V_46 ;
}
F_9 ( L_28 ,
V_11 -> V_14 -> V_15 , V_60 [ V_42 ] . V_41 ,
V_42 ) ;
V_11 -> V_39 . V_59 = V_42 ;
return V_19 ;
}
static T_1 F_41 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_61 [ V_11 -> V_39 . V_62 ] . V_41 ,
V_11 -> V_39 . V_62 ) ;
}
static T_1 F_42 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
if ( ! F_32 ( & V_11 -> V_45 ) ) {
F_12 ( L_29 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
V_42 = F_33 ( V_5 , V_61 ) ;
if ( V_42 < 0 ) {
F_12 ( L_30 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
V_31 = - V_46 ;
goto V_37;
}
V_11 -> V_39 . V_62 = V_42 ;
F_9 ( L_31 ,
V_11 -> V_14 -> V_15 , V_61 [ V_42 ] . V_41 ,
V_42 ) ;
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_43 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_49 ) ;
}
static T_1 F_44 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_42 , V_31 = V_19 ;
if ( ! F_24 () )
return F_25 () ;
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_34 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 < 0 ) {
F_12 ( L_35 ,
V_11 -> V_14 -> V_15 , V_42 , V_63 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_11 -> V_39 . V_40 == V_47 ||
V_11 -> V_39 . V_40 == V_48 ) {
F_9 ( L_36 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
F_9 ( L_37 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
V_11 -> V_39 . V_49 = V_42 ;
if ( V_42 ) {
if ( V_11 -> V_39 . V_64 ) {
F_9 ( L_38 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 ) ;
V_11 -> V_39 . V_64 = 0 ;
}
if ( ! V_11 -> V_39 . V_65 [ 0 ] )
F_9 ( L_39 ,
V_11 -> V_14 -> V_15 ) ;
}
if ( V_11 -> V_14 -> V_43 & V_44 ) {
if ( ! V_42 ) {
if ( V_11 -> V_39 . V_50 )
V_11 -> V_56 = NULL ;
F_45 ( & V_11 -> V_66 ) ;
} else {
if ( V_11 -> V_39 . V_50 )
V_11 -> V_56 = V_57 ;
F_45 ( & V_11 -> V_67 ) ;
F_46 ( V_11 -> V_68 , & V_11 -> V_66 , 0 ) ;
}
}
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_47 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_69 , V_9 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
if ( V_11 -> V_39 . V_65 [ V_69 ] )
V_9 += sprintf ( V_5 + V_9 , L_40 ,
& V_11 -> V_39 . V_65 [ V_69 ] ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_48 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
struct V_29 * V_29 ;
T_3 V_71 , * V_72 ;
unsigned long * V_73 ;
int V_74 , V_69 , V_75 , V_31 = - V_46 ;
V_72 = V_11 -> V_39 . V_65 ;
V_71 = F_49 ( V_5 + 1 ) ;
if ( V_5 [ 0 ] == '+' ) {
if ( ( V_71 == 0 ) || ( V_71 == F_50 ( V_76 ) ) ) {
F_12 ( L_41 ,
V_11 -> V_14 -> V_15 , & V_71 ) ;
goto V_37;
}
if ( F_51 ( V_72 , V_71 ) != - 1 ) {
F_12 ( L_42 ,
V_11 -> V_14 -> V_15 , & V_71 ) ;
goto V_37;
}
V_74 = F_51 ( V_72 , 0 ) ;
if ( V_74 == - 1 ) {
F_12 ( L_43 ,
V_11 -> V_14 -> V_15 ) ;
goto V_37;
}
F_9 ( L_44 , V_11 -> V_14 -> V_15 ,
& V_71 ) ;
F_52 ( & V_11 -> V_36 ) ;
F_21 (bond, slave)
V_29 -> V_77 [ V_74 ] = V_78 ;
V_72 [ V_74 ] = V_71 ;
F_53 ( & V_11 -> V_36 ) ;
} else if ( V_5 [ 0 ] == '-' ) {
if ( ( V_71 == 0 ) || ( V_71 == F_50 ( V_76 ) ) ) {
F_12 ( L_45 ,
V_11 -> V_14 -> V_15 , & V_71 ) ;
goto V_37;
}
V_74 = F_51 ( V_72 , V_71 ) ;
if ( V_74 == - 1 ) {
F_12 ( L_46 ,
V_11 -> V_14 -> V_15 , & V_71 ) ;
goto V_37;
}
if ( V_74 == 0 && ! V_72 [ 1 ] && V_11 -> V_39 . V_49 )
F_54 ( L_47 ,
V_11 -> V_14 -> V_15 ) ;
F_9 ( L_48 , V_11 -> V_14 -> V_15 ,
& V_71 ) ;
F_52 ( & V_11 -> V_36 ) ;
F_21 (bond, slave) {
V_73 = V_29 -> V_77 ;
V_75 = V_74 ;
for (; ( V_75 < V_70 - 1 ) && V_72 [ V_75 + 1 ] ; V_75 ++ )
V_73 [ V_75 ] = V_73 [ V_75 + 1 ] ;
V_73 [ V_75 ] = 0 ;
}
for ( V_69 = V_74 ; ( V_69 < V_70 - 1 ) && V_72 [ V_69 + 1 ] ; V_69 ++ )
V_72 [ V_69 ] = V_72 [ V_69 + 1 ] ;
V_72 [ V_69 ] = 0 ;
F_53 ( & V_11 -> V_36 ) ;
} else {
F_12 ( L_49 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
V_31 = V_19 ;
V_37:
return V_31 ;
}
static T_1 F_55 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_79 * V_11 -> V_39 . V_64 ) ;
}
static T_1 F_56 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! ( V_11 -> V_39 . V_64 ) ) {
F_12 ( L_50 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_51 , V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 < 0 ) {
F_12 ( L_52 ,
V_11 -> V_14 -> V_15 , V_42 , 0 , V_63 ) ;
V_31 = - V_46 ;
goto V_37;
} else {
if ( ( V_42 % V_11 -> V_39 . V_64 ) != 0 ) {
F_57 ( L_53 ,
V_11 -> V_14 -> V_15 , V_42 ,
V_11 -> V_39 . V_64 ,
( V_42 / V_11 -> V_39 . V_64 ) *
V_11 -> V_39 . V_64 ) ;
}
V_11 -> V_39 . V_79 = V_42 / V_11 -> V_39 . V_64 ;
F_9 ( L_54 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_39 . V_79 * V_11 -> V_39 . V_64 ) ;
}
V_37:
return V_31 ;
}
static T_1 F_58 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_80 * V_11 -> V_39 . V_64 ) ;
}
static T_1 F_59 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! ( V_11 -> V_39 . V_64 ) ) {
F_12 ( L_55 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_56 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 < 0 ) {
F_12 ( L_57 ,
V_11 -> V_14 -> V_15 , V_42 , 0 , V_63 ) ;
V_31 = - V_46 ;
goto V_37;
} else {
if ( ( V_42 % V_11 -> V_39 . V_64 ) != 0 ) {
F_57 ( L_58 ,
V_11 -> V_14 -> V_15 , V_42 ,
V_11 -> V_39 . V_64 ,
( V_42 / V_11 -> V_39 . V_64 ) *
V_11 -> V_39 . V_64 ) ;
}
V_11 -> V_39 . V_80 = V_42 / V_11 -> V_39 . V_64 ;
F_9 ( L_59 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_39 . V_80 * V_11 -> V_39 . V_64 ) ;
}
V_37:
return V_31 ;
}
static T_1 F_60 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_81 [ V_11 -> V_39 . V_82 ] . V_41 ,
V_11 -> V_39 . V_82 ) ;
}
static T_1 F_61 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_42 , V_31 = V_19 ;
if ( ! F_24 () )
return F_25 () ;
if ( V_11 -> V_14 -> V_43 & V_44 ) {
F_12 ( L_60 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
if ( V_11 -> V_39 . V_40 != V_83 ) {
F_12 ( L_61 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
V_42 = F_33 ( V_5 , V_81 ) ;
if ( ( V_42 == 1 ) || ( V_42 == 0 ) ) {
V_11 -> V_39 . V_82 = V_42 ;
F_62 ( V_11 ) ;
F_9 ( L_62 ,
V_11 -> V_14 -> V_15 , V_81 [ V_42 ] . V_41 ,
V_42 ) ;
} else {
F_12 ( L_63 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_46 ;
}
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_63 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_84 ) ;
}
static T_1 F_64 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_31 ;
unsigned int V_42 ;
V_31 = F_65 ( V_5 , 0 , & V_42 ) ;
if ( V_31 < 0 ) {
F_12 ( L_64 ,
V_11 -> V_14 -> V_15 , V_5 ) ;
return V_31 ;
}
F_9 ( L_65 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
V_11 -> V_39 . V_84 = V_42 ;
return V_19 ;
}
static T_1 F_66 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_85 [ V_11 -> V_39 . V_86 ] . V_41 ,
V_11 -> V_39 . V_86 ) ;
}
static T_1 F_67 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_14 -> V_43 & V_44 ) {
F_12 ( L_66 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
V_42 = F_33 ( V_5 , V_85 ) ;
if ( V_42 != - 1 ) {
V_11 -> V_39 . V_86 = V_42 ;
F_9 ( L_67 ,
V_11 -> V_14 -> V_15 , V_85 [ V_42 ] . V_41 ,
V_42 ) ;
} else {
F_12 ( L_68 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_46 ;
}
V_37:
return V_31 ;
}
static T_1 F_68 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_87 ) ;
}
static T_1 F_69 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_88 = F_70 ( V_5 , 10 , & V_11 -> V_39 . V_87 ) ;
return V_88 ? V_88 : V_19 ;
}
static T_1 F_71 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_64 ) ;
}
static T_1 F_72 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_69 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 < 0 ) {
F_12 ( L_70 ,
V_11 -> V_14 -> V_15 , V_42 , 0 , V_63 ) ;
V_31 = - V_46 ;
goto V_37;
}
F_9 ( L_71 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
V_11 -> V_39 . V_64 = V_42 ;
if ( V_11 -> V_39 . V_80 )
F_9 ( L_72 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_39 . V_80 * V_11 -> V_39 . V_64 ) ;
if ( V_11 -> V_39 . V_79 )
F_9 ( L_73 ,
V_11 -> V_14 -> V_15 ,
V_11 -> V_39 . V_79 * V_11 -> V_39 . V_64 ) ;
if ( V_42 && V_11 -> V_39 . V_49 ) {
F_9 ( L_74 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_39 . V_49 = 0 ;
if ( V_11 -> V_39 . V_50 )
V_11 -> V_39 . V_50 = V_51 ;
}
if ( V_11 -> V_14 -> V_43 & V_44 ) {
if ( ! V_42 ) {
F_45 ( & V_11 -> V_67 ) ;
} else {
F_45 ( & V_11 -> V_66 ) ;
F_46 ( V_11 -> V_68 , & V_11 -> V_67 , 0 ) ;
}
}
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_73 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_89 )
V_19 = sprintf ( V_5 , L_75 , V_11 -> V_89 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_74 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
char V_17 [ V_13 ] ;
struct V_29 * V_29 ;
if ( ! F_24 () )
return F_25 () ;
F_75 () ;
F_20 ( & V_11 -> V_36 ) ;
F_52 ( & V_11 -> V_90 ) ;
if ( ! F_76 ( V_11 -> V_39 . V_40 ) ) {
F_9 ( L_76 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_39 . V_40 ) ;
goto V_37;
}
sscanf ( V_5 , L_77 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_78 ,
V_11 -> V_14 -> V_15 ) ;
V_11 -> V_89 = NULL ;
memset ( V_11 -> V_39 . V_91 , 0 , sizeof( V_11 -> V_39 . V_91 ) ) ;
F_77 ( V_11 ) ;
goto V_37;
}
F_21 (bond, slave) {
if ( strncmp ( V_29 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
F_9 ( L_79 ,
V_11 -> V_14 -> V_15 , V_29 -> V_14 -> V_15 ) ;
V_11 -> V_89 = V_29 ;
strcpy ( V_11 -> V_39 . V_91 , V_29 -> V_14 -> V_15 ) ;
F_77 ( V_11 ) ;
goto V_37;
}
}
strncpy ( V_11 -> V_39 . V_91 , V_17 , V_13 ) ;
V_11 -> V_39 . V_91 [ V_13 - 1 ] = 0 ;
F_9 ( L_80
L_81 ,
V_11 -> V_14 -> V_15 , V_17 , V_11 -> V_14 -> V_15 ) ;
V_37:
F_53 ( & V_11 -> V_90 ) ;
F_22 ( & V_11 -> V_36 ) ;
F_78 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_79 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_16 ,
V_92 [ V_11 -> V_39 . V_93 ] . V_41 ,
V_11 -> V_39 . V_93 ) ;
}
static T_1 F_80 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( ! F_24 () )
return F_25 () ;
V_42 = F_33 ( V_5 , V_92 ) ;
if ( V_42 < 0 ) {
F_12 ( L_82 ,
V_11 -> V_14 -> V_15 ,
( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_31 = - V_46 ;
goto V_37;
}
V_11 -> V_39 . V_93 = V_42 ;
F_9 ( L_83 ,
V_11 -> V_14 -> V_15 , V_92 [ V_42 ] . V_41 ,
V_42 ) ;
F_75 () ;
F_20 ( & V_11 -> V_36 ) ;
F_52 ( & V_11 -> V_90 ) ;
F_77 ( V_11 ) ;
F_53 ( & V_11 -> V_90 ) ;
F_22 ( & V_11 -> V_36 ) ;
F_78 () ;
V_37:
F_5 () ;
return V_31 ;
}
static T_1 F_81 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_94 ) ;
}
static T_1 F_82 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_84 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( ( V_42 == 0 ) || ( V_42 == 1 ) ) {
V_11 -> V_39 . V_94 = V_42 ;
F_9 ( L_85 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
} else {
F_9 ( L_86 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
}
V_37:
return V_31 ;
}
static T_1 F_83 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
struct V_29 * V_95 ;
int V_19 = 0 ;
F_84 () ;
V_95 = F_85 ( V_11 -> V_96 ) ;
if ( F_76 ( V_11 -> V_39 . V_40 ) && V_95 )
V_19 = sprintf ( V_5 , L_75 , V_95 -> V_14 -> V_15 ) ;
F_86 () ;
return V_19 ;
}
static T_1 F_87 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_29 * V_29 , * V_97 , * V_98 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
char V_17 [ V_13 ] ;
if ( ! F_24 () )
return F_25 () ;
V_97 = V_98 = NULL ;
F_75 () ;
F_20 ( & V_11 -> V_36 ) ;
F_52 ( & V_11 -> V_90 ) ;
if ( ! F_76 ( V_11 -> V_39 . V_40 ) ) {
F_9 ( L_87 ,
V_11 -> V_14 -> V_15 , V_11 -> V_14 -> V_15 , V_11 -> V_39 . V_40 ) ;
goto V_37;
}
sscanf ( V_5 , L_77 , V_17 ) ;
if ( ! strlen ( V_17 ) || V_5 [ 0 ] == '\n' ) {
F_9 ( L_88 ,
V_11 -> V_14 -> V_15 ) ;
F_88 ( V_11 -> V_96 , NULL ) ;
F_77 ( V_11 ) ;
goto V_37;
}
F_21 (bond, slave) {
if ( strncmp ( V_29 -> V_14 -> V_15 , V_17 , V_13 ) == 0 ) {
V_97 = V_11 -> V_96 ;
V_98 = V_29 ;
if ( V_98 == V_97 ) {
F_9 ( L_89
L_90 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
goto V_37;
} else {
if ( ( V_98 ) &&
( V_97 ) &&
( V_98 -> V_99 == V_100 ) &&
F_89 ( V_98 -> V_14 ) ) {
F_9 ( L_91
L_92 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
F_90 ( V_11 ,
V_98 ) ;
} else {
F_9 ( L_93
L_94
L_95 ,
V_11 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ,
V_29 -> V_14 -> V_15 ) ;
}
goto V_37;
}
}
}
F_9 ( L_96 ,
V_11 -> V_14 -> V_15 , ( int ) strlen ( V_5 ) - 1 , V_5 ) ;
V_37:
F_53 ( & V_11 -> V_90 ) ;
F_22 ( & V_11 -> V_36 ) ;
F_78 () ;
F_5 () ;
return V_19 ;
}
static T_1 F_91 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_75 , V_11 -> V_96 ? L_97 : L_98 ) ;
}
static T_1 F_92 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_39 . V_40 == V_83 ) {
struct V_101 V_101 ;
V_19 = sprintf ( V_5 , L_32 ,
F_93 ( V_11 , & V_101 )
? 0 : V_101 . V_102 ) ;
}
return V_19 ;
}
static T_1 F_94 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_39 . V_40 == V_83 ) {
struct V_101 V_101 ;
V_19 = sprintf ( V_5 , L_32 ,
F_93 ( V_11 , & V_101 )
? 0 : V_101 . V_103 ) ;
}
return V_19 ;
}
static T_1 F_95 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_39 . V_40 == V_83 ) {
struct V_101 V_101 ;
V_19 = sprintf ( V_5 , L_32 ,
F_93 ( V_11 , & V_101 )
? 0 : V_101 . V_104 ) ;
}
return V_19 ;
}
static T_1 F_96 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_39 . V_40 == V_83 ) {
struct V_101 V_101 ;
V_19 = sprintf ( V_5 , L_32 ,
F_93 ( V_11 , & V_101 )
? 0 : V_101 . V_105 ) ;
}
return V_19 ;
}
static T_1 F_97 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( V_11 -> V_39 . V_40 == V_83 ) {
struct V_101 V_101 ;
if ( ! F_93 ( V_11 , & V_101 ) )
V_19 = sprintf ( V_5 , L_99 , V_101 . V_106 ) ;
}
return V_19 ;
}
static T_1 F_98 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
struct V_29 * V_29 ;
int V_9 = 0 ;
if ( ! F_24 () )
return F_25 () ;
F_20 ( & V_11 -> V_36 ) ;
F_21 (bond, slave) {
if ( V_9 > ( V_12 - V_13 - 6 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_100 ,
V_29 -> V_14 -> V_15 , V_29 -> V_107 ) ;
}
F_22 ( & V_11 -> V_36 ) ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static T_1 F_99 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_29 * V_29 , * V_108 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
T_4 V_109 ;
int V_31 = V_19 ;
char * V_110 ;
struct V_16 * V_111 = NULL ;
if ( ! F_24 () )
return F_25 () ;
V_110 = strchr ( V_18 , ':' ) ;
if ( ! V_110 )
goto V_22;
* V_110 = '\0' ;
if ( sscanf ( ++ V_110 , L_101 , & V_109 ) != 1 )
goto V_22;
if ( strlen ( V_18 ) > V_13 ||
! F_8 ( V_18 ) ||
V_109 > V_11 -> V_14 -> V_112 )
goto V_22;
V_111 = F_26 ( F_27 ( V_11 -> V_14 ) , V_18 ) ;
if ( ! V_111 )
goto V_22;
F_20 ( & V_11 -> V_36 ) ;
V_108 = NULL ;
F_21 (bond, slave) {
if ( V_111 == V_29 -> V_14 )
V_108 = V_29 ;
else if ( V_109 && V_109 == V_29 -> V_107 ) {
goto V_113;
}
}
if ( ! V_108 )
goto V_113;
V_108 -> V_107 = V_109 ;
F_22 ( & V_11 -> V_36 ) ;
V_37:
F_5 () ;
return V_31 ;
V_113:
F_22 ( & V_11 -> V_36 ) ;
V_22:
F_9 ( L_102 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_27 ;
goto V_37;
}
static T_1 F_100 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_114 ) ;
}
static T_1 F_101 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_42 , V_31 = V_19 ;
struct V_29 * V_29 ;
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_103 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 == V_11 -> V_39 . V_114 )
goto V_37;
if ( ( V_42 == 0 ) || ( V_42 == 1 ) ) {
V_11 -> V_39 . V_114 = V_42 ;
} else {
F_9 ( L_104 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
V_31 = - V_46 ;
goto V_37;
}
F_20 ( & V_11 -> V_36 ) ;
F_21 (bond, slave) {
if ( ! F_102 ( V_29 ) ) {
if ( V_42 )
V_29 -> V_115 = 0 ;
else
V_29 -> V_115 = 1 ;
}
}
F_22 ( & V_11 -> V_36 ) ;
V_37:
return V_31 ;
}
static T_1 F_103 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_116 ) ;
}
static T_1 F_104 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
int V_42 , V_31 = V_19 ;
struct V_10 * V_11 = F_19 ( V_34 ) ;
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_105 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 < 0 || V_42 > 255 ) {
F_12 ( L_106 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
V_31 = - V_46 ;
goto V_37;
}
F_9 ( L_107 ,
V_11 -> V_14 -> V_15 , V_42 ) ;
V_11 -> V_39 . V_116 = V_42 ;
V_37:
return V_31 ;
}
static T_1 F_105 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
return sprintf ( V_5 , L_32 , V_11 -> V_39 . V_117 ) ;
}
static T_1 F_106 ( struct V_33 * V_34 ,
struct V_35 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_19 ( V_34 ) ;
int V_42 , V_31 = V_19 ;
if ( sscanf ( V_5 , L_33 , & V_42 ) != 1 ) {
F_12 ( L_108 ,
V_11 -> V_14 -> V_15 ) ;
V_31 = - V_46 ;
goto V_37;
}
if ( V_42 <= 0 ) {
F_12 ( L_109 ,
V_11 -> V_14 -> V_15 , V_63 ) ;
V_31 = - V_46 ;
goto V_37;
}
V_11 -> V_39 . V_117 = V_42 ;
V_37:
return V_31 ;
}
int F_107 ( struct V_6 * V_7 )
{
int V_31 ;
V_7 -> V_8 = V_8 ;
F_108 ( & V_7 -> V_8 . V_4 ) ;
V_31 = F_109 ( & V_7 -> V_8 ) ;
if ( V_31 == - V_24 ) {
if ( F_26 ( V_7 -> V_23 ,
V_8 . V_4 . V_15 ) )
F_12 ( L_110 ,
V_8 . V_4 . V_15 ) ;
V_31 = 0 ;
}
return V_31 ;
}
void F_110 ( struct V_6 * V_7 )
{
F_111 ( & V_7 -> V_8 ) ;
}
void F_112 ( struct V_10 * V_11 )
{
V_11 -> V_14 -> V_118 [ 0 ] = & V_119 ;
}
