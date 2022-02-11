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
char V_30 [ 256 ] ;
int V_31 ;
if ( ! F_15 ( V_32 , & V_4 -> V_25 ) )
return 0 ;
F_16 ( V_4 , 0 , 0 ) ;
F_17 ( V_33 , & V_4 -> V_25 ) ;
V_31 = snprintf ( V_30 , sizeof( V_30 ) ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8 ,
F_15 ( V_34 , & V_4 -> V_25 ) ? '1' : '0' ,
( unsigned long long ) V_4 -> V_35 ,
( unsigned long long ) V_4 -> V_36 ,
( unsigned long long ) V_4 -> V_37 ,
( unsigned long long ) V_4 -> V_38 ,
( unsigned long long ) V_4 -> V_39 ,
( unsigned long long ) V_4 -> V_40
) ;
if ( V_31 > V_28 )
return - V_41 ;
if ( F_18 ( V_27 , V_30 , V_31 ) != 0 )
return - V_42 ;
return V_31 ;
}
static T_1 F_19 ( struct V_2 * V_2 ,
const char T_2 * V_43 ,
T_3 V_44 ,
T_4 * V_29 )
{
const struct V_45 * V_46 ;
struct V_3 * V_4 = V_2 -> V_22 ;
T_1 V_47 ;
char * V_48 , * args , * V_49 ;
ASSERT ( V_4 ) ;
if ( F_15 ( V_24 , & V_4 -> V_25 ) )
return - V_50 ;
if ( V_44 < 0 || V_44 > V_51 - 1 )
return - V_52 ;
V_48 = F_20 ( V_44 + 1 , V_9 ) ;
if ( ! V_48 )
return - V_10 ;
V_47 = - V_42 ;
if ( F_21 ( V_48 , V_43 , V_44 ) != 0 )
goto error;
V_48 [ V_44 ] = '\0' ;
V_47 = - V_53 ;
if ( memchr ( V_48 , '\0' , V_44 ) )
goto error;
V_49 = memchr ( V_48 , '\n' , V_44 ) ;
if ( V_49 ) {
if ( V_49 == V_48 )
goto error;
* V_49 = '\0' ;
}
V_47 = - V_52 ;
for ( args = V_48 ; * args ; args ++ )
if ( isspace ( * args ) )
break;
if ( * args ) {
if ( args == V_48 )
goto error;
* args = '\0' ;
args = F_22 ( ++ args ) ;
}
for ( V_46 = V_54 ; V_46 -> V_55 [ 0 ] ; V_46 ++ )
if ( strcmp ( V_46 -> V_55 , V_48 ) == 0 )
goto V_56;
error:
F_12 ( V_48 ) ;
return V_47 ;
V_56:
F_23 ( & V_4 -> V_11 ) ;
V_47 = - V_50 ;
if ( ! F_15 ( V_24 , & V_4 -> V_25 ) )
V_47 = V_46 -> V_57 ( V_4 , args ) ;
F_24 ( & V_4 -> V_11 ) ;
if ( V_47 == 0 )
V_47 = V_44 ;
goto error;
}
static unsigned int F_25 ( struct V_2 * V_2 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = V_2 -> V_22 ;
unsigned int V_60 ;
F_26 ( V_2 , & V_4 -> V_15 , V_59 ) ;
V_60 = 0 ;
if ( F_15 ( V_33 , & V_4 -> V_25 ) )
V_60 |= V_61 ;
if ( F_15 ( V_34 , & V_4 -> V_25 ) )
V_60 |= V_62 ;
return V_60 ;
}
static int F_27 ( struct V_3 * V_4 ,
char * args )
{
F_28 ( L_9 ) ;
return - V_53 ;
}
static int F_29 ( struct V_3 * V_4 , char * args )
{
unsigned long V_35 ;
F_2 ( L_10 , args ) ;
if ( ! * args )
return - V_53 ;
V_35 = F_30 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_53 ;
if ( V_35 <= V_4 -> V_17 || V_35 >= 100 )
return F_27 ( V_4 , args ) ;
V_4 -> V_16 = V_35 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , char * args )
{
unsigned long V_36 ;
F_2 ( L_10 , args ) ;
if ( ! * args )
return - V_53 ;
V_36 = F_30 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_53 ;
if ( V_36 <= V_4 -> V_18 || V_36 >= V_4 -> V_16 )
return F_27 ( V_4 , args ) ;
V_4 -> V_17 = V_36 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , char * args )
{
unsigned long V_37 ;
F_2 ( L_10 , args ) ;
if ( ! * args )
return - V_53 ;
V_37 = F_30 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_53 ;
if ( V_37 < 0 || V_37 >= V_4 -> V_17 )
return F_27 ( V_4 , args ) ;
V_4 -> V_18 = V_37 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , char * args )
{
unsigned long V_38 ;
F_2 ( L_10 , args ) ;
if ( ! * args )
return - V_53 ;
V_38 = F_30 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_53 ;
if ( V_38 <= V_4 -> V_20 || V_38 >= 100 )
return F_27 ( V_4 , args ) ;
V_4 -> V_19 = V_38 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 , char * args )
{
unsigned long V_39 ;
F_2 ( L_10 , args ) ;
if ( ! * args )
return - V_53 ;
V_39 = F_30 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_53 ;
if ( V_39 <= V_4 -> V_21 || V_39 >= V_4 -> V_19 )
return F_27 ( V_4 , args ) ;
V_4 -> V_20 = V_39 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , char * args )
{
unsigned long V_40 ;
F_2 ( L_10 , args ) ;
if ( ! * args )
return - V_53 ;
V_40 = F_30 ( args , & args , 10 ) ;
if ( args [ 0 ] != '%' || args [ 1 ] != '\0' )
return - V_53 ;
if ( V_40 < 0 || V_40 >= V_4 -> V_20 )
return F_27 ( V_4 , args ) ;
V_4 -> V_21 = V_40 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , char * args )
{
char * V_63 ;
F_2 ( L_10 , args ) ;
if ( ! * args ) {
F_28 ( L_11 ) ;
return - V_53 ;
}
if ( V_4 -> V_64 ) {
F_28 ( L_12 ) ;
return - V_65 ;
}
V_63 = F_37 ( args , V_9 ) ;
if ( ! V_63 )
return - V_10 ;
V_4 -> V_64 = V_63 ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 , char * args )
{
char * V_66 ;
F_2 ( L_10 , args ) ;
if ( ! * args ) {
F_28 ( L_13 ) ;
return - V_53 ;
}
if ( V_4 -> V_66 ) {
F_28 ( L_14 ) ;
return - V_53 ;
}
V_66 = F_37 ( args , V_9 ) ;
if ( ! V_66 )
return - V_10 ;
V_4 -> V_66 = V_66 ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , char * args )
{
char * V_67 ;
F_2 ( L_10 , args ) ;
if ( ! * args ) {
F_28 ( L_15 ) ;
return - V_53 ;
}
if ( V_4 -> V_67 )
return - V_65 ;
V_67 = F_37 ( args , V_9 ) ;
if ( ! V_67 )
return - V_10 ;
V_4 -> V_67 = V_67 ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , char * args )
{
struct V_68 V_68 ;
const struct V_69 * V_70 ;
int V_47 ;
F_2 ( L_10 , args ) ;
if ( strchr ( args , '/' ) )
goto V_71;
if ( ! F_15 ( V_32 , & V_4 -> V_25 ) ) {
F_28 ( L_16 ) ;
return - V_50 ;
}
if ( F_15 ( V_24 , & V_4 -> V_25 ) ) {
F_28 ( L_17 ) ;
return - V_50 ;
}
F_41 ( V_72 -> V_73 , & V_68 ) ;
if ( ! F_42 ( V_68 . V_74 -> V_75 -> V_76 ) )
goto V_77;
F_43 ( V_4 , & V_70 ) ;
V_47 = F_44 ( V_4 , V_68 . V_74 , args ) ;
F_45 ( V_4 , V_70 ) ;
F_46 ( & V_68 ) ;
F_13 ( L_18 , V_47 ) ;
return V_47 ;
V_77:
F_46 ( & V_68 ) ;
F_28 ( L_19 ) ;
return - V_78 ;
V_71:
F_28 ( L_20 ) ;
return - V_53 ;
}
static int F_47 ( struct V_3 * V_4 , char * args )
{
unsigned long V_60 ;
F_2 ( L_10 , args ) ;
V_60 = F_30 ( args , & args , 0 ) ;
if ( args [ 0 ] != '\0' )
goto V_71;
V_79 = V_60 ;
F_13 ( L_21 ) ;
return 0 ;
V_71:
F_28 ( L_22 ) ;
return - V_53 ;
}
static int F_48 ( struct V_3 * V_4 , char * args )
{
struct V_68 V_68 ;
const struct V_69 * V_70 ;
int V_47 ;
if ( strchr ( args , '/' ) )
goto V_71;
if ( ! F_15 ( V_32 , & V_4 -> V_25 ) ) {
F_28 ( L_23 ) ;
return - V_50 ;
}
if ( F_15 ( V_24 , & V_4 -> V_25 ) ) {
F_28 ( L_24 ) ;
return - V_50 ;
}
F_41 ( V_72 -> V_73 , & V_68 ) ;
if ( ! F_42 ( V_68 . V_74 -> V_75 -> V_76 ) )
goto V_77;
F_43 ( V_4 , & V_70 ) ;
V_47 = F_49 ( V_4 , V_68 . V_74 , args ) ;
F_45 ( V_4 , V_70 ) ;
F_46 ( & V_68 ) ;
return V_47 ;
V_77:
F_46 ( & V_68 ) ;
F_28 ( L_25 ) ;
return - V_78 ;
V_71:
F_28 ( L_26 ) ;
return - V_53 ;
}
int F_16 ( struct V_3 * V_4 ,
unsigned V_80 , unsigned V_81 )
{
struct V_82 V_83 ;
struct V_68 V_68 = {
. V_84 = V_4 -> V_84 ,
. V_74 = V_4 -> V_84 -> V_85 ,
} ;
int V_47 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_47 = F_50 ( & V_68 , & V_83 ) ;
if ( V_47 < 0 ) {
if ( V_47 == - V_50 )
F_51 ( V_4 , L_27 ) ;
F_13 ( L_18 , V_47 ) ;
return V_47 ;
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
V_47 = - V_89 ;
if ( V_83 . V_88 < V_4 -> V_37 ||
V_83 . V_86 < V_4 -> V_40 )
goto V_90;
V_47 = 0 ;
if ( V_83 . V_88 < V_4 -> V_36 ||
V_83 . V_86 < V_4 -> V_39 )
goto V_90;
if ( F_15 ( V_34 , & V_4 -> V_25 ) &&
V_83 . V_88 >= V_4 -> V_35 &&
V_83 . V_86 >= V_4 -> V_38 &&
F_52 ( V_34 , & V_4 -> V_25 )
) {
F_53 ( L_28 ) ;
F_54 ( V_4 ) ;
}
return 0 ;
V_90:
if ( ! F_55 ( V_34 , & V_4 -> V_25 ) ) {
F_53 ( L_29 ) ;
F_54 ( V_4 ) ;
}
F_13 ( L_18 , V_47 ) ;
return V_47 ;
}
