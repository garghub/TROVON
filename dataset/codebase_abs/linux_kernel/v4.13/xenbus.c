static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_4 == NULL )
goto V_6;
F_3 ( & V_3 -> V_7 , L_1 , V_4 ) ;
V_4 -> V_3 = V_3 ;
F_4 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = NULL ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = 0 ;
F_5 ( & V_4 -> V_13 , V_14 ) ;
if ( F_6 ( V_4 ) ) {
F_7 ( V_4 ) ;
V_4 = NULL ;
}
F_8 ( & V_3 -> V_7 , V_4 ) ;
V_6:
return V_4 ;
}
static void F_9 ( struct V_1 * V_4 )
{
F_10 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_10 != V_11 ) {
F_11 ( V_4 -> V_10 , V_4 ) ;
V_4 -> V_10 = V_11 ;
}
F_12 ( & V_4 -> V_13 ) ;
if ( V_4 -> V_9 != NULL ) {
F_13 ( V_4 -> V_3 , V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
}
F_14 ( & V_4 -> V_8 ) ;
}
static void F_15 ( struct V_1 * V_4 )
{
if ( V_4 -> V_12 ) {
F_16 ( & V_4 -> V_15 ) ;
V_4 -> V_12 = 0 ;
}
F_9 ( V_4 ) ;
F_17 ( V_4 ) ;
F_8 ( & V_4 -> V_3 -> V_7 , NULL ) ;
V_4 -> V_3 = NULL ;
F_7 ( V_4 ) ;
}
static int F_18 ( struct V_1 * V_4 , int V_16 ,
int V_17 )
{
int V_18 = 0 ;
void * V_19 ;
F_3 ( & V_4 -> V_3 -> V_7 ,
L_2 ,
V_16 , V_17 ) ;
V_18 = F_19 ( V_4 -> V_3 , & V_16 , 1 , & V_19 ) ;
if ( V_18 < 0 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_3 ) ;
goto V_6;
}
V_4 -> V_9 = V_19 ;
V_18 = F_21 (
V_4 -> V_3 -> V_20 , V_17 , V_21 ,
0 , V_22 , V_4 ) ;
if ( V_18 < 0 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_4 ) ;
goto V_6;
}
V_4 -> V_10 = V_18 ;
V_18 = 0 ;
F_3 ( & V_4 -> V_3 -> V_7 , L_5 ) ;
V_6:
return V_18 ;
}
static int F_22 ( struct V_1 * V_4 )
{
int V_18 = 0 ;
int V_16 , V_17 ;
char * V_23 = NULL ;
F_10 ( & V_4 -> V_8 ) ;
if ( F_23 ( V_4 -> V_3 -> V_24 ) !=
V_25 )
goto V_6;
if ( F_23 ( V_4 -> V_3 -> V_26 ) !=
V_25 )
goto V_6;
F_3 ( & V_4 -> V_3 -> V_7 , L_6 ) ;
V_18 = F_24 ( V_27 , V_4 -> V_3 -> V_26 ,
L_7 , L_8 , & V_16 ,
L_9 , L_8 , & V_17 ,
L_10 , NULL , & V_23 , NULL ) ;
if ( V_18 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_11 ) ;
goto V_6;
}
if ( V_23 == NULL || strcmp ( V_23 , V_28 ) != 0 ) {
F_20 ( V_4 -> V_3 , - V_29 ,
L_12
L_13 V_22 ,
V_23 , V_28 ) ;
V_18 = - V_29 ;
goto V_6;
}
V_18 = F_18 ( V_4 , V_16 , V_17 ) ;
if ( V_18 )
goto V_6;
F_3 ( & V_4 -> V_3 -> V_7 , L_14 ) ;
V_18 = F_25 ( V_4 -> V_3 , V_30 ) ;
if ( V_18 )
F_20 ( V_4 -> V_3 , V_18 ,
L_15 ) ;
F_3 ( & V_4 -> V_3 -> V_7 , L_16 , V_18 ) ;
V_6:
F_14 ( & V_4 -> V_8 ) ;
F_7 ( V_23 ) ;
return V_18 ;
}
static int F_26 ( struct V_1 * V_4 ,
unsigned int V_31 , unsigned int V_32 ,
unsigned int V_33 , unsigned int V_34 )
{
int V_18 ;
int V_35 ;
char V_36 [ 64 ] ;
V_35 = snprintf ( V_36 , sizeof( V_36 ) , L_17 , V_34 ) ;
if ( F_27 ( V_35 >= ( sizeof( V_36 ) - 1 ) ) ) {
V_18 = - V_37 ;
goto V_6;
}
V_18 = F_28 ( V_27 , V_4 -> V_3 -> V_24 , V_36 ,
L_18 , V_31 , V_32 ,
F_29 ( V_33 ) , F_30 ( V_33 ) ) ;
V_6:
return V_18 ;
}
static int F_31 ( struct V_1 * V_4 ,
int V_31 , int V_32 , int V_38 , int V_39 ,
int V_34 )
{
struct V_40 * V_7 ;
int V_18 = 0 ;
F_3 ( & V_4 -> V_3 -> V_7 , L_19 ,
V_31 , V_32 , V_38 , V_39 ) ;
V_7 = F_32 ( V_4 , V_31 , V_32 , V_38 , V_39 ) ;
if ( ! V_7 ) {
V_18 = - V_41 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_20
L_21
L_22 ,
V_31 , V_32 , V_38 , V_39 ) ;
goto V_6;
}
V_18 = F_33 ( V_4 , V_7 , V_34 ,
F_26 ) ;
if ( V_18 )
goto V_6;
F_34 ( & V_7 -> V_7 , L_23 , V_4 -> V_3 -> V_20 ) ;
if ( F_35 ( V_7 ,
V_4 -> V_3 -> V_20 ) != 0 ) {
F_36 ( & V_7 -> V_7 , L_24 ,
F_37 ( V_7 ) ) ;
F_38 ( V_7 ) ;
F_35 ( V_7 , V_4 -> V_3 -> V_20 ) ;
}
V_6:
return V_18 ;
}
static int F_39 ( struct V_1 * V_4 ,
int V_31 , int V_32 , int V_38 , int V_39 )
{
int V_18 = 0 ;
struct V_40 * V_7 ;
F_3 ( & V_4 -> V_3 -> V_7 , L_25 ,
V_31 , V_32 , V_38 , V_39 ) ;
V_7 = F_40 ( V_4 , V_31 , V_32 , F_41 ( V_38 , V_39 ) ) ;
if ( ! V_7 ) {
V_18 = - V_41 ;
F_3 ( & V_4 -> V_3 -> V_7 , L_20
L_26 ,
V_31 , V_32 , V_38 , V_39 ) ;
goto V_6;
}
F_3 ( & V_7 -> V_7 , L_27 , V_4 -> V_3 -> V_20 ) ;
F_38 ( V_7 ) ;
F_42 ( V_4 , V_7 , true ) ;
V_6:
return V_18 ;
}
static int F_43 ( struct V_1 * V_4 ,
unsigned int V_31 , unsigned int V_32 )
{
unsigned int V_42 , V_43 ;
int V_44 , V_45 , V_35 , V_18 ;
char V_36 [ 64 ] ;
F_3 ( & V_4 -> V_3 -> V_7 , L_28 ) ;
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 ,
L_29 , L_30 , & V_45 ) ;
if ( V_18 == 0 || V_18 == - V_46 )
V_45 = 0 ;
else if ( V_18 < 0 )
goto V_6;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
V_35 = snprintf ( V_36 , sizeof( V_36 ) , L_31 , V_44 ) ;
if ( F_27 ( V_35 >= ( sizeof( V_36 ) - 1 ) ) ) {
V_18 = - V_37 ;
goto V_6;
}
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 ,
V_36 , L_32 , & V_42 , & V_43 ) ;
if ( V_18 < 0 )
goto V_6;
if ( V_18 != 2 ) {
V_18 = - V_41 ;
goto V_6;
}
if ( V_42 == V_31 && V_43 == V_32 ) {
V_18 = 0 ;
goto V_6;
}
}
V_35 = snprintf ( V_36 , sizeof( V_36 ) , L_31 , V_45 ) ;
if ( F_27 ( V_35 >= ( sizeof( V_36 ) - 1 ) ) ) {
V_18 = - V_37 ;
goto V_6;
}
F_3 ( & V_4 -> V_3 -> V_7 , L_33 ,
V_45 , V_31 , V_32 ) ;
V_18 = F_28 ( V_27 , V_4 -> V_3 -> V_24 , V_36 ,
L_34 , V_31 , V_32 ) ;
if ( V_18 )
goto V_6;
V_18 = F_28 ( V_27 , V_4 -> V_3 -> V_24 ,
L_29 , L_30 , ( V_45 + 1 ) ) ;
V_6:
return V_18 ;
}
static int F_45 ( struct V_1 * V_4 )
{
int V_18 = 0 ;
int V_47 ;
int V_31 , V_32 , V_38 , V_39 ;
unsigned int V_48 ;
int V_44 , V_35 ;
char V_49 [ 64 ] ;
char V_50 [ 64 ] ;
F_3 ( & V_4 -> V_3 -> V_7 , L_35 ) ;
F_10 ( & V_4 -> V_8 ) ;
if ( F_23 ( V_4 -> V_3 -> V_24 ) !=
V_51 )
goto V_6;
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 , L_36 , L_30 ,
& V_47 ) ;
if ( V_18 != 1 ) {
if ( V_18 >= 0 )
V_18 = - V_41 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_37 ) ;
goto V_6;
}
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
V_35 = snprintf ( V_49 , sizeof( V_49 ) , L_38 , V_44 ) ;
if ( F_27 ( V_35 >= ( sizeof( V_49 ) - 1 ) ) ) {
V_18 = - V_37 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_39
L_40 ) ;
goto V_6;
}
V_48 = F_46 ( V_4 -> V_3 -> V_24 , V_49 ,
V_52 ) ;
switch ( V_48 ) {
case V_53 :
F_3 ( & V_4 -> V_3 -> V_7 , L_41 , V_44 ) ;
V_35 = snprintf ( V_50 , sizeof( V_50 ) , L_42 , V_44 ) ;
if ( F_27 ( V_35 >= ( sizeof( V_50 ) - 1 ) ) ) {
V_18 = - V_37 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_43
L_44 ) ;
goto V_6;
}
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 ,
V_50 , L_45 ,
& V_31 , & V_32 , & V_38 , & V_39 ) ;
if ( V_18 < 0 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_46
L_40 ) ;
goto V_6;
}
if ( V_18 != 4 ) {
V_18 = - V_41 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_47
L_40 ) ;
goto V_6;
}
V_18 = F_31 ( V_4 , V_31 , V_32 , V_38 ,
V_39 , V_44 ) ;
if ( V_18 )
goto V_6;
V_18 = F_47 ( V_4 ,
F_43 ) ;
if ( V_18 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_48
L_49 ) ;
goto V_6;
}
V_18 = F_28 ( V_27 , V_4 -> V_3 -> V_24 ,
V_49 , L_30 ,
V_25 ) ;
if ( V_18 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_50
L_51 , V_44 ) ;
goto V_6;
}
break;
case V_54 :
F_3 ( & V_4 -> V_3 -> V_7 , L_52 , V_44 ) ;
V_35 = snprintf ( V_50 , sizeof( V_50 ) , L_17 , V_44 ) ;
if ( F_27 ( V_35 >= ( sizeof( V_50 ) - 1 ) ) ) {
V_18 = - V_37 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_43
L_44 ) ;
goto V_6;
}
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 ,
V_50 , L_45 ,
& V_31 , & V_32 , & V_38 , & V_39 ) ;
if ( V_18 < 0 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_46
L_40 ) ;
goto V_6;
}
if ( V_18 != 4 ) {
V_18 = - V_41 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_47
L_40 ) ;
goto V_6;
}
V_18 = F_39 ( V_4 , V_31 , V_32 , V_38 ,
V_39 ) ;
if ( V_18 )
goto V_6;
break;
default:
break;
}
}
V_18 = F_25 ( V_4 -> V_3 , V_55 ) ;
if ( V_18 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_53 ) ;
goto V_6;
}
V_6:
F_14 ( & V_4 -> V_8 ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_3 ,
enum V_56 V_57 )
{
struct V_1 * V_4 = F_49 ( & V_3 -> V_7 ) ;
F_3 ( & V_3 -> V_7 , L_54 , V_57 ) ;
switch ( V_57 ) {
case V_25 :
F_22 ( V_4 ) ;
break;
case V_51 :
F_45 ( V_4 ) ;
break;
case V_30 :
F_25 ( V_3 , V_30 ) ;
break;
case V_54 :
F_9 ( V_4 ) ;
F_25 ( V_3 , V_54 ) ;
break;
case V_58 :
F_9 ( V_4 ) ;
F_25 ( V_3 , V_58 ) ;
if ( F_50 ( V_3 ) )
break;
case V_52 :
F_3 ( & V_3 -> V_7 , L_55 ) ;
F_51 ( & V_3 -> V_7 ) ;
break;
default:
break;
}
}
static int F_52 ( struct V_1 * V_4 )
{
int V_31 , V_32 , V_38 , V_39 ;
int V_18 = 0 ;
int V_44 , V_47 ;
char V_50 [ 64 ] ;
char V_49 [ 64 ] ;
F_10 ( & V_4 -> V_8 ) ;
if ( F_23 ( V_4 -> V_3 -> V_24 ) !=
V_59 )
goto V_6;
F_3 ( & V_4 -> V_3 -> V_7 , L_56 ) ;
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 , L_36 , L_30 ,
& V_47 ) ;
if ( V_18 != 1 ) {
if ( V_18 >= 0 )
V_18 = - V_41 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_37 ) ;
goto V_6;
}
for ( V_44 = 0 ; V_44 < V_47 ; V_44 ++ ) {
int V_60 = snprintf ( V_50 , sizeof( V_50 ) , L_42 , V_44 ) ;
if ( F_27 ( V_60 >= ( sizeof( V_50 ) - 1 ) ) ) {
V_18 = - V_37 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_39
L_40 ) ;
goto V_6;
}
V_18 = F_44 ( V_27 , V_4 -> V_3 -> V_24 , V_50 ,
L_45 , & V_31 , & V_32 , & V_38 , & V_39 ) ;
if ( V_18 < 0 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_57 ) ;
goto V_6;
}
if ( V_18 != 4 ) {
V_18 = - V_41 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_47
L_40 ) ;
goto V_6;
}
V_18 = F_31 ( V_4 , V_31 , V_32 , V_38 , V_39 , V_44 ) ;
if ( V_18 )
goto V_6;
V_60 = snprintf ( V_49 , sizeof( V_49 ) , L_38 , V_44 ) ;
if ( F_27 ( V_60 >= ( sizeof( V_49 ) - 1 ) ) ) {
V_18 = - V_37 ;
F_20 ( V_4 -> V_3 , V_18 ,
L_39
L_40 ) ;
goto V_6;
}
V_18 = F_28 ( V_27 , V_4 -> V_3 -> V_24 , V_49 ,
L_30 , V_25 ) ;
if ( V_18 ) {
F_20 ( V_4 -> V_3 , V_18 , L_58
L_59 , V_44 ) ;
goto V_6;
}
}
V_18 = F_47 ( V_4 , F_43 ) ;
if ( V_18 ) {
F_20 ( V_4 -> V_3 , V_18 ,
L_60
L_61 ) ;
goto V_6;
}
V_18 = F_25 ( V_4 -> V_3 , V_25 ) ;
if ( V_18 )
F_20 ( V_4 -> V_3 , V_18 ,
L_62 ) ;
V_6:
F_14 ( & V_4 -> V_8 ) ;
if ( ! V_18 )
F_22 ( V_4 ) ;
return V_18 ;
}
static void F_53 ( struct V_61 * V_62 ,
const char * V_63 , const char * V_64 )
{
struct V_1 * V_4 =
F_54 ( V_62 , struct V_1 , V_15 ) ;
switch ( F_23 ( V_4 -> V_3 -> V_24 ) ) {
case V_59 :
F_52 ( V_4 ) ;
break;
default:
break;
}
}
static int F_55 ( struct V_2 * V_7 ,
const struct V_65 * V_66 )
{
int V_18 = 0 ;
struct V_1 * V_4 = F_1 ( V_7 ) ;
if ( V_4 == NULL ) {
V_18 = - V_37 ;
F_20 ( V_7 , V_18 ,
L_63 ) ;
goto V_6;
}
V_18 = F_25 ( V_7 , V_59 ) ;
if ( V_18 )
goto V_6;
V_18 = F_56 ( V_7 , V_7 -> V_24 , & V_4 -> V_15 ,
F_53 ) ;
if ( V_18 )
goto V_6;
V_4 -> V_12 = 1 ;
F_53 ( & V_4 -> V_15 , NULL , 0 ) ;
V_6:
return V_18 ;
}
static int F_57 ( struct V_2 * V_7 )
{
struct V_1 * V_4 = F_49 ( & V_7 -> V_7 ) ;
if ( V_4 != NULL )
F_15 ( V_4 ) ;
return 0 ;
}
int T_1 F_58 ( void )
{
V_67 = & V_68 ;
if ( V_69 )
V_67 = & V_70 ;
F_59 ( L_64 , V_67 -> V_71 ) ;
return F_60 ( & V_72 ) ;
}
void T_2 F_61 ( void )
{
F_62 ( & V_72 ) ;
}
