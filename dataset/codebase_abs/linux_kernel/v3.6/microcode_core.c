static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
V_3 -> V_4 = V_5 -> V_6 ( F_2 () ,
V_3 -> V_7 ) ;
}
static int F_3 ( int V_8 , struct V_9 * V_7 )
{
struct V_2 V_3 = { . V_7 = V_7 , . V_4 = 0 } ;
int V_10 ;
V_10 = F_4 ( V_8 , F_1 , & V_3 , 1 ) ;
if ( ! V_10 )
V_10 = V_3 . V_4 ;
return V_10 ;
}
static int V_6 ( int V_8 )
{
struct V_11 * V_12 = V_11 + V_8 ;
int V_10 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_10 = F_3 ( V_8 , & V_12 -> V_7 ) ;
if ( ! V_10 )
V_12 -> V_13 = 1 ;
return V_10 ;
}
static void F_5 ( void * V_1 )
{
struct V_14 * V_3 = V_1 ;
V_3 -> V_4 = V_5 -> V_15 ( F_2 () ) ;
}
static int F_6 ( int V_8 )
{
struct V_14 V_3 = { . V_4 = 0 } ;
int V_10 ;
V_10 = F_4 ( V_8 , F_5 , & V_3 , 1 ) ;
if ( ! V_10 )
V_10 = V_3 . V_4 ;
return V_10 ;
}
static int F_7 ( const void T_1 * V_16 , T_2 V_17 )
{
int error = 0 ;
int V_8 ;
F_8 (cpu) {
struct V_11 * V_12 = V_11 + V_8 ;
enum V_18 V_19 ;
if ( ! V_12 -> V_13 )
continue;
V_19 = V_5 -> V_20 ( V_8 , V_16 , V_17 ) ;
if ( V_19 == V_21 ) {
error = - 1 ;
break;
} else if ( V_19 == V_22 )
F_6 ( V_8 ) ;
}
return error ;
}
static int F_9 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_10 ( V_25 ) ? F_11 ( V_23 , V_24 ) : - V_26 ;
}
static T_3 F_12 ( struct V_24 * V_24 , const char T_1 * V_16 ,
T_2 V_27 , T_4 * V_28 )
{
T_3 V_10 = - V_29 ;
if ( ( V_27 >> V_30 ) > V_31 ) {
F_13 ( L_1 , V_31 ) ;
return V_10 ;
}
F_14 () ;
F_15 ( & V_32 ) ;
if ( F_7 ( V_16 , V_27 ) == 0 )
V_10 = ( T_3 ) V_27 ;
if ( V_10 > 0 )
F_16 () ;
F_17 ( & V_32 ) ;
F_18 () ;
return V_10 ;
}
static int T_5 F_19 ( void )
{
int error ;
error = F_20 ( & V_33 ) ;
if ( error ) {
F_13 ( L_2 , V_34 ) ;
return error ;
}
return 0 ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_33 ) ;
}
static int F_23 ( int V_8 )
{
struct V_11 * V_12 = V_11 + V_8 ;
int V_4 = 0 ;
if ( V_12 -> V_13 ) {
enum V_18 V_19 ;
V_19 = V_5 -> V_35 ( V_8 , & V_36 -> V_37 ) ;
if ( V_19 == V_22 )
F_6 ( V_8 ) ;
else
if ( V_19 == V_21 )
V_4 = - V_29 ;
}
return V_4 ;
}
static T_3 F_24 ( struct V_38 * V_37 ,
struct V_39 * V_40 ,
const char * V_16 , T_2 V_17 )
{
unsigned long V_41 ;
int V_8 ;
T_3 V_10 = 0 , V_42 ;
V_10 = F_25 ( V_16 , 0 , & V_41 ) ;
if ( V_10 )
return V_10 ;
if ( V_41 != 1 )
return V_17 ;
F_14 () ;
F_15 ( & V_32 ) ;
F_8 (cpu) {
V_42 = F_23 ( V_8 ) ;
if ( V_42 != 0 )
F_26 ( L_3 , V_8 ) ;
if ( ! V_10 )
V_10 = V_42 ;
}
if ( ! V_10 )
F_16 () ;
F_17 ( & V_32 ) ;
F_18 () ;
if ( ! V_10 )
V_10 = V_17 ;
return V_10 ;
}
static T_3 F_27 ( struct V_38 * V_37 ,
struct V_39 * V_40 , char * V_16 )
{
struct V_11 * V_12 = V_11 + V_37 -> V_43 ;
return sprintf ( V_16 , L_4 , V_12 -> V_7 . V_44 ) ;
}
static T_3 F_28 ( struct V_38 * V_37 ,
struct V_39 * V_40 , char * V_16 )
{
struct V_11 * V_12 = V_11 + V_37 -> V_43 ;
return sprintf ( V_16 , L_4 , V_12 -> V_7 . V_45 ) ;
}
static void F_29 ( int V_8 )
{
struct V_11 * V_12 = V_11 + V_8 ;
V_5 -> F_29 ( V_8 ) ;
V_12 -> V_13 = 0 ;
}
static enum V_18 F_30 ( int V_8 )
{
struct V_11 * V_12 = V_11 + V_8 ;
if ( ! V_12 -> V_46 )
return V_47 ;
F_31 ( L_5 , V_8 ) ;
F_6 ( V_8 ) ;
return V_22 ;
}
static enum V_18 F_32 ( int V_8 )
{
enum V_18 V_19 ;
if ( V_6 ( V_8 ) )
return V_21 ;
if ( V_48 != V_49 )
return V_47 ;
V_19 = V_5 -> V_35 ( V_8 , & V_36 -> V_37 ) ;
if ( V_19 == V_22 ) {
F_31 ( L_6 , V_8 ) ;
F_6 ( V_8 ) ;
}
return V_19 ;
}
static enum V_18 F_33 ( int V_8 )
{
struct V_11 * V_12 = V_11 + V_8 ;
enum V_18 V_19 ;
if ( V_12 -> V_13 )
V_19 = F_30 ( V_8 ) ;
else
V_19 = F_32 ( V_8 ) ;
return V_19 ;
}
static int F_34 ( struct V_38 * V_37 , struct V_50 * V_51 )
{
int V_4 , V_8 = V_37 -> V_43 ;
if ( ! F_35 ( V_8 ) )
return 0 ;
F_31 ( L_7 , V_8 ) ;
V_4 = F_36 ( & V_37 -> V_52 , & V_53 ) ;
if ( V_4 )
return V_4 ;
if ( F_32 ( V_8 ) == V_21 )
return - V_29 ;
return V_4 ;
}
static int F_37 ( struct V_38 * V_37 , struct V_50 * V_51 )
{
int V_8 = V_37 -> V_43 ;
if ( ! F_35 ( V_8 ) )
return 0 ;
F_31 ( L_8 , V_8 ) ;
F_29 ( V_8 ) ;
F_38 ( & V_37 -> V_52 , & V_53 ) ;
return 0 ;
}
static void F_39 ( void )
{
int V_8 = F_2 () ;
struct V_11 * V_12 = V_11 + V_8 ;
if ( V_12 -> V_13 && V_12 -> V_46 )
V_5 -> V_15 ( V_8 ) ;
}
static T_7 int
F_40 ( struct V_54 * V_55 , unsigned long V_56 , void * V_57 )
{
unsigned int V_8 = ( unsigned long ) V_57 ;
struct V_38 * V_37 ;
V_37 = F_41 ( V_8 ) ;
switch ( V_56 ) {
case V_58 :
case V_59 :
F_33 ( V_8 ) ;
case V_60 :
case V_61 :
F_31 ( L_7 , V_8 ) ;
if ( F_36 ( & V_37 -> V_52 , & V_53 ) )
F_13 ( L_9 , V_8 ) ;
break;
case V_62 :
case V_63 :
F_38 ( & V_37 -> V_52 , & V_53 ) ;
F_31 ( L_8 , V_8 ) ;
break;
case V_64 :
F_29 ( V_8 ) ;
break;
}
return V_65 ;
}
static int T_5 F_42 ( void )
{
struct V_66 * V_67 = & F_43 ( 0 ) ;
int error ;
if ( V_67 -> V_68 == V_69 )
V_5 = F_44 () ;
else if ( V_67 -> V_68 == V_70 )
V_5 = F_45 () ;
else
F_13 ( L_10 ) ;
if ( ! V_5 )
return - V_71 ;
V_36 = F_46 ( L_11 , - 1 ,
NULL , 0 ) ;
if ( F_47 ( V_36 ) )
return F_48 ( V_36 ) ;
F_14 () ;
F_15 ( & V_32 ) ;
error = F_49 ( & V_72 ) ;
if ( ! error )
F_16 () ;
F_17 ( & V_32 ) ;
F_18 () ;
if ( error )
goto V_73;
error = F_36 ( & V_74 . V_75 -> V_52 ,
& V_76 ) ;
if ( error ) {
F_13 ( L_12 ) ;
goto V_77;
}
error = F_19 () ;
if ( error )
goto V_78;
F_50 ( & V_79 ) ;
F_51 ( & V_80 ) ;
F_52 ( L_13 V_81
L_14 ) ;
return 0 ;
V_78:
F_38 ( & V_74 . V_75 -> V_52 ,
& V_76 ) ;
V_77:
F_14 () ;
F_15 ( & V_32 ) ;
F_53 ( & V_72 ) ;
F_17 ( & V_32 ) ;
F_18 () ;
V_73:
F_54 ( V_36 ) ;
return error ;
}
static void T_6 F_55 ( void )
{
struct V_66 * V_67 = & F_43 ( 0 ) ;
F_21 () ;
F_56 ( & V_80 ) ;
F_57 ( & V_79 ) ;
F_38 ( & V_74 . V_75 -> V_52 ,
& V_76 ) ;
F_14 () ;
F_15 ( & V_32 ) ;
F_53 ( & V_72 ) ;
F_17 ( & V_32 ) ;
F_18 () ;
F_54 ( V_36 ) ;
V_5 = NULL ;
if ( V_67 -> V_68 == V_70 )
F_58 () ;
F_52 ( L_13 V_81 L_15 ) ;
}
