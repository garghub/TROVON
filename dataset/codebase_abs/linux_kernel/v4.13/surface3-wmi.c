static int F_1 ( const char * V_1 , int V_2 , int * V_3 )
{
struct V_4 V_5 = { V_6 , NULL } ;
T_1 V_7 ;
union V_8 * V_9 ;
int error = 0 ;
F_2 ( & V_10 ) ;
V_7 = F_3 ( V_1 , V_2 , & V_5 ) ;
V_9 = V_5 . V_11 ;
if ( ! V_9 || V_9 -> type != V_12 ) {
if ( V_9 ) {
F_4 ( L_1 ,
V_9 -> type ,
V_9 -> type == V_13 ?
V_9 -> V_14 . V_15 : 0 ) ;
}
error = - V_16 ;
goto V_17;
}
* V_3 = V_9 -> integer . V_18 ;
V_17:
F_5 ( V_9 ) ;
F_6 ( & V_10 ) ;
return error ;
}
static inline int F_7 ( int * V_3 )
{
return F_1 ( V_19 , 0 , V_3 ) ;
}
static int F_8 ( void )
{
int V_3 , V_20 ;
V_3 = F_7 ( & V_20 ) ;
if ( V_3 )
return V_3 ;
F_9 ( V_21 . V_22 , V_23 , V_20 ) ;
F_10 ( V_21 . V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 , T_2 V_18 )
{
return F_8 () ;
}
static T_1 F_12 ( T_3 V_26 ,
T_2 V_27 ,
void * V_28 ,
void * * V_29 )
{
struct V_24 * V_25 , * * V_30 ;
if ( F_13 ( V_26 , & V_25 ) )
return V_31 ;
V_30 = V_28 ;
if ( strncmp ( F_14 ( V_25 ) , V_32 ,
strlen ( V_32 ) ) )
return V_31 ;
if ( * V_30 ) {
F_4 ( L_2 , V_32 ) ;
return V_31 ;
}
* V_30 = V_25 ;
return V_31 ;
}
static int F_15 ( struct V_33 * V_34 , void * V_28 )
{
struct V_24 * V_25 , * V_30 = NULL ;
T_3 V_26 ;
T_1 V_7 ;
V_26 = F_16 ( V_34 ) ;
if ( ! V_26 || F_13 ( V_26 , & V_25 ) )
return 0 ;
if ( ! strcmp ( V_35 , F_17 ( V_25 ) ) ) {
V_21 . V_36 = V_25 ;
return 0 ;
}
if ( strncmp ( F_14 ( V_25 ) , V_37 ,
strlen ( V_37 ) ) )
return 0 ;
V_7 = F_18 ( V_38 , V_26 , 1 ,
F_12 , NULL ,
& V_30 , NULL ) ;
if ( F_19 ( V_7 ) )
F_20 ( V_34 , L_3 ) ;
if ( ! V_30 )
return 0 ;
V_21 . V_39 = V_30 ;
return 0 ;
}
static int F_21 ( struct V_40 * V_41 )
{
struct V_42 * V_22 ;
int error ;
V_22 = F_22 ( & V_41 -> V_34 ) ;
if ( ! V_22 )
return - V_43 ;
V_22 -> V_44 = L_4 ;
V_22 -> V_45 = L_5 ;
V_22 -> V_46 . V_47 = V_48 ;
V_22 -> V_46 . V_49 = 0x0005 ;
F_23 ( V_22 , V_50 , V_23 ) ;
error = F_24 ( V_22 ) ;
if ( error )
goto V_51;
V_21 . V_22 = V_22 ;
return 0 ;
V_51:
F_25 ( V_21 . V_22 ) ;
return error ;
}
static int T_4 F_26 ( struct V_40 * V_41 )
{
int error ;
if ( ! F_27 ( V_52 ) )
return - V_53 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_28 ( & V_54 , NULL , NULL ,
F_15 ) ;
if ( ! V_21 . V_39 )
return - V_53 ;
F_29 ( V_21 . V_36 ) ;
error = F_21 ( V_41 ) ;
if ( error )
goto V_55;
F_30 ( V_21 . V_39 , & V_21 . V_56 ,
F_11 , NULL ) ;
F_8 () ;
return 0 ;
V_55:
F_31 ( V_21 . V_36 -> V_26 ) ;
return error ;
}
static int F_32 ( struct V_40 * V_33 )
{
V_21 . V_39 -> V_56 = NULL ;
F_31 ( V_21 . V_36 -> V_26 ) ;
return 0 ;
}
static int T_5 F_33 ( struct V_33 * V_34 )
{
F_8 () ;
return 0 ;
}
static int T_4 F_34 ( void )
{
int error ;
V_57 = F_35 ( L_6 , - 1 ) ;
if ( ! V_57 )
return - V_43 ;
error = F_36 ( V_57 ) ;
if ( error )
goto V_58;
error = F_37 ( & V_59 , F_26 ) ;
if ( error )
goto V_60;
F_38 ( L_7 ) ;
return 0 ;
V_60:
F_39 ( V_57 ) ;
V_58:
F_40 ( V_57 ) ;
return error ;
}
static void T_6 F_41 ( void )
{
F_42 ( V_57 ) ;
F_43 ( & V_59 ) ;
}
