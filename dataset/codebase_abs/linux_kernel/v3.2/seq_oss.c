static inline int F_1 ( void ) { return 0 ; }
static inline void F_2 ( void ) {}
static int T_1 F_3 ( void )
{
int V_1 ;
static struct V_2 V_3 = {
V_4 ,
V_5 ,
} ;
F_4 () ;
if ( ( V_1 = F_5 () ) < 0 )
goto error;
if ( ( V_1 = F_1 () ) < 0 ) {
F_6 () ;
goto error;
}
if ( ( V_1 = F_7 () ) < 0 ) {
F_2 () ;
F_6 () ;
goto error;
}
if ( ( V_1 = F_8 ( V_6 , & V_3 ,
sizeof( struct V_7 ) ) ) < 0 ) {
F_9 () ;
F_2 () ;
F_6 () ;
goto error;
}
F_10 () ;
error:
F_11 () ;
return V_1 ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_6 ) ;
F_9 () ;
F_2 () ;
F_6 () ;
}
static int
F_14 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
int V_10 , V_1 ;
if ( F_15 ( V_8 ) == V_11 )
V_10 = V_12 ;
else
V_10 = V_13 ;
F_16 ( & V_14 ) ;
V_1 = F_17 ( V_9 , V_10 ) ;
F_18 ( & V_14 ) ;
return V_1 ;
}
static int
F_19 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
struct V_15 * V_16 ;
if ( ( V_16 = V_9 -> V_17 ) == NULL )
return 0 ;
F_20 ( V_16 ) ;
F_16 ( & V_14 ) ;
F_21 ( V_16 ) ;
F_18 ( & V_14 ) ;
return 0 ;
}
static T_3
F_22 ( struct V_9 * V_9 , char T_4 * V_18 , T_5 V_19 , T_6 * V_20 )
{
struct V_15 * V_16 ;
V_16 = V_9 -> V_17 ;
if ( F_23 ( ! V_16 ) )
return - V_21 ;
return F_24 ( V_16 , V_18 , V_19 ) ;
}
static T_3
F_25 ( struct V_9 * V_9 , const char T_4 * V_18 , T_5 V_19 , T_6 * V_20 )
{
struct V_15 * V_16 ;
V_16 = V_9 -> V_17 ;
if ( F_23 ( ! V_16 ) )
return - V_21 ;
return F_26 ( V_16 , V_18 , V_19 , V_9 ) ;
}
static long
F_27 ( struct V_9 * V_9 , unsigned int V_22 , unsigned long V_23 )
{
struct V_15 * V_16 ;
V_16 = V_9 -> V_17 ;
if ( F_23 ( ! V_16 ) )
return - V_21 ;
return F_28 ( V_16 , V_22 , V_23 ) ;
}
static unsigned int
F_29 ( struct V_9 * V_9 , T_7 * V_24 )
{
struct V_15 * V_16 ;
V_16 = V_9 -> V_17 ;
if ( F_23 ( ! V_16 ) )
return - V_21 ;
return F_30 ( V_16 , V_9 , V_24 ) ;
}
static int T_1
F_5 ( void )
{
int V_1 ;
F_16 ( & V_14 ) ;
if ( ( V_1 = F_31 ( V_25 ,
NULL , 0 ,
& V_26 , NULL ,
V_27 ) ) < 0 ) {
F_32 ( V_28 L_1 ) ;
F_18 ( & V_14 ) ;
return V_1 ;
}
if ( ( V_1 = F_31 ( V_29 ,
NULL , 0 ,
& V_26 , NULL ,
V_27 ) ) < 0 ) {
F_32 ( V_28 L_2 ) ;
F_33 ( V_25 , NULL , 0 ) ;
F_18 ( & V_14 ) ;
return V_1 ;
}
F_34 ( ( L_3 ) ) ;
F_18 ( & V_14 ) ;
return 0 ;
}
static void
F_6 ( void )
{
F_16 ( & V_14 ) ;
F_34 ( ( L_4 ) ) ;
if ( F_33 ( V_29 , NULL , 0 ) < 0 )
F_32 ( V_28 L_5 ) ;
if ( F_33 ( V_25 , NULL , 0 ) < 0 )
F_32 ( V_28 L_6 ) ;
F_18 ( & V_14 ) ;
}
static void
F_35 ( struct V_30 * V_31 , struct V_32 * V_18 )
{
F_16 ( & V_14 ) ;
F_36 ( V_18 , L_7 , V_33 ) ;
F_37 ( V_18 ) ;
F_38 ( V_18 ) ;
F_39 ( V_18 ) ;
F_18 ( & V_14 ) ;
}
static int T_1
F_1 ( void )
{
struct V_30 * V_31 ;
V_31 = F_40 ( V_34 , V_35 , V_36 ) ;
if ( V_31 == NULL )
return - V_37 ;
V_31 -> V_38 = V_39 ;
V_31 -> V_17 = NULL ;
V_31 -> V_40 . V_41 . V_42 = F_35 ;
if ( F_41 ( V_31 ) < 0 ) {
F_42 ( V_31 ) ;
return - V_37 ;
}
V_43 = V_31 ;
return 0 ;
}
static void
F_2 ( void )
{
F_42 ( V_43 ) ;
V_43 = NULL ;
}
