static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 ) ;
if ( ! F_3 ( V_5 ) )
return - V_6 ;
if ( F_4 ( & V_7 , 1 ) == 1 )
return - V_8 ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_9 ) ;
if ( ! V_4 ) {
V_7 = 0 ;
return - V_10 ;
}
F_6 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_13 ;
F_7 ( & V_4 -> V_14 ) ;
F_8 ( & V_4 -> V_15 ) ;
V_4 -> V_16 = 7 ;
V_4 -> V_17 = 5 ;
V_4 -> V_18 = 1 ;
V_4 -> V_19 = 7 ;
V_4 -> V_20 = 5 ;
V_4 -> V_21 = 1 ;
V_2 -> V_22 = V_4 ;
V_4 -> V_23 = V_2 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_22 ;
F_2 ( L_1 ) ;
ASSERT ( V_4 ) ;
F_10 ( V_24 , & V_4 -> V_25 ) ;
F_11 ( V_4 ) ;
ASSERT ( ! V_4 -> V_12 . V_26 ) ;
V_4 -> V_23 = NULL ;
V_2 -> V_22 = NULL ;
V_7 = 0 ;
F_12 ( V_4 ) ;
F_13 ( L_1 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_2 * V_2 , char T_2 * V_27 ,
T_3 V_28 , T_4 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_22 ;
unsigned long long V_30 ;
unsigned V_31 ;
char V_32 [ 256 ] ;
int V_33 ;
if ( ! F_15 ( V_34 , & V_4 -> V_25 ) )
return 0 ;
F_16 ( V_4 , 0 , 0 ) ;
V_31 = F_17 ( & V_4 -> V_31 , 0 ) ;
V_30 = F_18 ( & V_4 -> V_30 , 0 ) ;
F_19 ( V_35 , & V_4 -> V_25 ) ;
V_33 = snprintf ( V_32 , sizeof( V_32 ) ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10 ,
F_15 ( V_36 , & V_4 -> V_25 ) ? '1' : '0' ,
( unsigned long long ) V_4 -> V_37 ,
( unsigned long long ) V_4 -> V_38 ,
( unsigned long long ) V_4 -> V_39 ,
( unsigned long long ) V_4 -> V_40 ,
( unsigned long long ) V_4 -> V_41 ,
( unsigned long long ) V_4 -> V_42 ,
V_31 ,
V_30 ) ;
if ( V_33 > V_28 )
return - V_43 ;
if ( F_20 ( V_27 , V_32 , V_33 ) != 0 )
return - V_44 ;
return V_33 ;
}
static T_1 F_21 ( struct V_2 * V_2 ,
const char T_2 * V_45 ,
T_3 V_46 ,
T_4 * V_29 )
{
const struct V_47 * V_48 ;
struct V_3 * V_4 = V_2 -> V_22 ;
T_1 V_49 ;
char * V_50 , * args , * V_51 ;
ASSERT ( V_4 ) ;
if ( F_15 ( V_24 , & V_4 -> V_25 ) )
return - V_52 ;
if ( V_46 < 0 || V_46 > V_53 - 1 )
return - V_54 ;
V_50 = F_22 ( V_45 , V_46 ) ;
if ( F_23 ( V_50 ) )
return F_24 ( V_50 ) ;
V_49 = - V_55 ;
if ( memchr ( V_50 , '\0' , V_46 ) )
goto error;
V_51 = memchr ( V_50 , '\n' , V_46 ) ;
if ( V_51 ) {
if ( V_51 == V_50 )
goto error;
* V_51 = '\0' ;
}
V_49 = - V_54 ;
for ( args = V_50 ; * args ; args ++ )
if ( isspace ( * args ) )
break;
if ( * args ) {
if ( args == V_50 )
goto error;
* args = '\0' ;
args = F_25 ( ++ args ) ;
}
for ( V_48 = V_56 ; V_48 -> V_57 [ 0 ] ; V_48 ++ )
if ( strcmp ( V_48 -> V_57 , V_50 ) == 0 )
goto V_58;
error:
F_12 ( V_50 ) ;
return V_49 ;
V_58:
F_26 ( & V_4 -> V_11 ) ;
V_49 = - V_52 ;
if ( ! F_15 ( V_24 , & V_4 -> V_25 ) )
V_49 = V_48 -> V_59 ( V_4 , args ) ;
F_27 ( & V_4 -> V_11 ) ;
if ( V_49 == 0 )
V_49 = V_46 ;
goto error;
}
static unsigned int F_28 ( struct V_2 * V_2 ,
struct V_60 * V_61 )
{
struct V_3 * V_4 = V_2 -> V_22 ;
unsigned int V_62 ;
F_29 ( V_2 , & V_4 -> V_15 , V_61 ) ;
V_62 = 0 ;
if ( F_15 ( V_35 , & V_4 -> V_25 ) )
V_62 |= V_63 ;
if ( F_15 ( V_36 , & V_4 -> V_25 ) )
V_62 |= V_64 ;
return V_62 ;
}
static int F_30 ( struct V_3 * V_4 ,
char * args )
{
F_31 ( L_11 ) ;
return - V_55 ;
}
static int F_32 ( struct V_3 * V_4 , char * args )
{
unsigned long V_37 ;
F_2 ( L_12 , args ) ;
if ( ! * args )
return - V_55 ;
V_37 = F_33 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_55 ;
if ( V_37 <= V_4 -> V_17 || V_37 >= 100 )
return F_30 ( V_4 , args ) ;
V_4 -> V_16 = V_37 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 , char * args )
{
unsigned long V_38 ;
F_2 ( L_12 , args ) ;
if ( ! * args )
return - V_55 ;
V_38 = F_33 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_55 ;
if ( V_38 <= V_4 -> V_18 || V_38 >= V_4 -> V_16 )
return F_30 ( V_4 , args ) ;
V_4 -> V_17 = V_38 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , char * args )
{
unsigned long V_39 ;
F_2 ( L_12 , args ) ;
if ( ! * args )
return - V_55 ;
V_39 = F_33 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_55 ;
if ( V_39 < 0 || V_39 >= V_4 -> V_17 )
return F_30 ( V_4 , args ) ;
V_4 -> V_18 = V_39 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , char * args )
{
unsigned long V_40 ;
F_2 ( L_12 , args ) ;
if ( ! * args )
return - V_55 ;
V_40 = F_33 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_55 ;
if ( V_40 <= V_4 -> V_20 || V_40 >= 100 )
return F_30 ( V_4 , args ) ;
V_4 -> V_19 = V_40 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , char * args )
{
unsigned long V_41 ;
F_2 ( L_12 , args ) ;
if ( ! * args )
return - V_55 ;
V_41 = F_33 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_55 ;
if ( V_41 <= V_4 -> V_21 || V_41 >= V_4 -> V_19 )
return F_30 ( V_4 , args ) ;
V_4 -> V_20 = V_41 ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , char * args )
{
unsigned long V_42 ;
F_2 ( L_12 , args ) ;
if ( ! * args )
return - V_55 ;
V_42 = F_33 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_55 ;
if ( V_42 < 0 || V_42 >= V_4 -> V_20 )
return F_30 ( V_4 , args ) ;
V_4 -> V_21 = V_42 ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , char * args )
{
char * V_65 ;
F_2 ( L_12 , args ) ;
if ( ! * args ) {
F_31 ( L_13 ) ;
return - V_55 ;
}
if ( V_4 -> V_66 ) {
F_31 ( L_14 ) ;
return - V_67 ;
}
V_65 = F_40 ( args , V_9 ) ;
if ( ! V_65 )
return - V_10 ;
V_4 -> V_66 = V_65 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , char * args )
{
char * V_68 ;
F_2 ( L_12 , args ) ;
if ( ! * args ) {
F_31 ( L_15 ) ;
return - V_55 ;
}
if ( V_4 -> V_68 ) {
F_31 ( L_16 ) ;
return - V_55 ;
}
V_68 = F_40 ( args , V_9 ) ;
if ( ! V_68 )
return - V_10 ;
V_4 -> V_68 = V_68 ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , char * args )
{
char * V_69 ;
F_2 ( L_12 , args ) ;
if ( ! * args ) {
F_31 ( L_17 ) ;
return - V_55 ;
}
if ( V_4 -> V_69 )
return - V_67 ;
V_69 = F_40 ( args , V_9 ) ;
if ( ! V_69 )
return - V_10 ;
V_4 -> V_69 = V_69 ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 , char * args )
{
struct V_70 V_70 ;
const struct V_71 * V_72 ;
int V_49 ;
F_2 ( L_12 , args ) ;
if ( strchr ( args , '/' ) )
goto V_73;
if ( ! F_15 ( V_34 , & V_4 -> V_25 ) ) {
F_31 ( L_18 ) ;
return - V_52 ;
}
if ( F_15 ( V_24 , & V_4 -> V_25 ) ) {
F_31 ( L_19 ) ;
return - V_52 ;
}
F_44 ( V_74 -> V_75 , & V_70 ) ;
if ( ! F_45 ( V_70 . V_76 ) )
goto V_77;
F_46 ( V_4 , & V_72 ) ;
V_49 = F_47 ( V_4 , V_70 . V_76 , args ) ;
F_48 ( V_4 , V_72 ) ;
F_49 ( & V_70 ) ;
F_13 ( L_20 , V_49 ) ;
return V_49 ;
V_77:
F_49 ( & V_70 ) ;
F_31 ( L_21 ) ;
return - V_78 ;
V_73:
F_31 ( L_22 ) ;
return - V_55 ;
}
static int F_50 ( struct V_3 * V_4 , char * args )
{
unsigned long V_62 ;
F_2 ( L_12 , args ) ;
V_62 = F_33 ( args , & args , 0 ) ;
if ( args [ 0 ] != '\0' )
goto V_73;
V_79 = V_62 ;
F_13 ( L_23 ) ;
return 0 ;
V_73:
F_31 ( L_24 ) ;
return - V_55 ;
}
static int F_51 ( struct V_3 * V_4 , char * args )
{
struct V_70 V_70 ;
const struct V_71 * V_72 ;
int V_49 ;
if ( strchr ( args , '/' ) )
goto V_73;
if ( ! F_15 ( V_34 , & V_4 -> V_25 ) ) {
F_31 ( L_25 ) ;
return - V_52 ;
}
if ( F_15 ( V_24 , & V_4 -> V_25 ) ) {
F_31 ( L_26 ) ;
return - V_52 ;
}
F_44 ( V_74 -> V_75 , & V_70 ) ;
if ( ! F_45 ( V_70 . V_76 ) )
goto V_77;
F_46 ( V_4 , & V_72 ) ;
V_49 = F_52 ( V_4 , V_70 . V_76 , args ) ;
F_48 ( V_4 , V_72 ) ;
F_49 ( & V_70 ) ;
return V_49 ;
V_77:
F_49 ( & V_70 ) ;
F_31 ( L_27 ) ;
return - V_78 ;
V_73:
F_31 ( L_28 ) ;
return - V_55 ;
}
int F_16 ( struct V_3 * V_4 ,
unsigned V_80 , unsigned V_81 )
{
struct V_82 V_83 ;
struct V_70 V_70 = {
. V_84 = V_4 -> V_84 ,
. V_76 = V_4 -> V_84 -> V_85 ,
} ;
int V_49 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_49 = F_53 ( & V_70 , & V_83 ) ;
if ( V_49 < 0 ) {
if ( V_49 == - V_52 )
F_54 ( V_4 , L_29 ) ;
F_13 ( L_20 , V_49 ) ;
return V_49 ;
}
V_83 . V_86 >>= V_4 -> V_87 ;
if ( V_83 . V_88 > V_80 )
V_83 . V_88 -= V_80 ;
else
V_83 . V_88 = 0 ;
if ( V_83 . V_86 > V_81 )
V_83 . V_86 -= V_81 ;
else
V_83 . V_86 = 0 ;
V_49 = - V_89 ;
if ( V_83 . V_88 < V_4 -> V_39 ||
V_83 . V_86 < V_4 -> V_42 )
goto V_90;
V_49 = 0 ;
if ( V_83 . V_88 < V_4 -> V_38 ||
V_83 . V_86 < V_4 -> V_41 )
goto V_90;
if ( F_15 ( V_36 , & V_4 -> V_25 ) &&
V_83 . V_88 >= V_4 -> V_37 &&
V_83 . V_86 >= V_4 -> V_40 &&
F_55 ( V_36 , & V_4 -> V_25 )
) {
F_56 ( L_30 ) ;
F_57 ( V_4 ) ;
}
return 0 ;
V_90:
if ( ! F_58 ( V_36 , & V_4 -> V_25 ) ) {
F_56 ( L_31 ) ;
F_57 ( V_4 ) ;
}
F_13 ( L_20 , V_49 ) ;
return V_49 ;
}
