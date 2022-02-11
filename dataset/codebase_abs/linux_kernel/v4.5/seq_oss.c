static inline int F_1 ( void ) { return 0 ; }
static inline void F_2 ( void ) {}
static int T_1 F_3 ( void )
{
int V_1 ;
if ( ( V_1 = F_4 () ) < 0 )
goto error;
if ( ( V_1 = F_1 () ) < 0 ) {
F_5 () ;
goto error;
}
if ( ( V_1 = F_6 () ) < 0 ) {
F_2 () ;
F_5 () ;
goto error;
}
V_1 = F_7 ( & V_2 ) ;
if ( V_1 < 0 ) {
F_8 () ;
F_2 () ;
F_5 () ;
goto error;
}
F_9 () ;
error:
return V_1 ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_2 ) ;
F_8 () ;
F_2 () ;
F_5 () ;
}
static int
F_12 ( struct V_3 * V_3 , struct V_4 * V_4 )
{
int V_5 , V_1 ;
if ( F_13 ( V_3 ) == V_6 )
V_5 = V_7 ;
else
V_5 = V_8 ;
F_14 ( & V_9 ) ;
V_1 = F_15 ( V_4 , V_5 ) ;
F_16 ( & V_9 ) ;
return V_1 ;
}
static int
F_17 ( struct V_3 * V_3 , struct V_4 * V_4 )
{
struct V_10 * V_11 ;
if ( ( V_11 = V_4 -> V_12 ) == NULL )
return 0 ;
F_14 ( & V_9 ) ;
F_18 ( V_11 ) ;
F_16 ( & V_9 ) ;
return 0 ;
}
static T_3
F_19 ( struct V_4 * V_4 , char T_4 * V_13 , T_5 V_14 , T_6 * V_15 )
{
struct V_10 * V_11 ;
V_11 = V_4 -> V_12 ;
if ( F_20 ( ! V_11 ) )
return - V_16 ;
return F_21 ( V_11 , V_13 , V_14 ) ;
}
static T_3
F_22 ( struct V_4 * V_4 , const char T_4 * V_13 , T_5 V_14 , T_6 * V_15 )
{
struct V_10 * V_11 ;
V_11 = V_4 -> V_12 ;
if ( F_20 ( ! V_11 ) )
return - V_16 ;
return F_23 ( V_11 , V_13 , V_14 , V_4 ) ;
}
static long
F_24 ( struct V_4 * V_4 , unsigned int V_17 , unsigned long V_18 )
{
struct V_10 * V_11 ;
V_11 = V_4 -> V_12 ;
if ( F_20 ( ! V_11 ) )
return - V_16 ;
return F_25 ( V_11 , V_17 , V_18 ) ;
}
static long F_26 ( struct V_4 * V_4 , unsigned int V_17 ,
unsigned long V_18 )
{
return F_24 ( V_4 , V_17 , ( unsigned long ) F_27 ( V_18 ) ) ;
}
static unsigned int
F_28 ( struct V_4 * V_4 , T_7 * V_19 )
{
struct V_10 * V_11 ;
V_11 = V_4 -> V_12 ;
if ( F_20 ( ! V_11 ) )
return - V_16 ;
return F_29 ( V_11 , V_4 , V_19 ) ;
}
static int T_1
F_4 ( void )
{
int V_1 ;
F_14 ( & V_9 ) ;
if ( ( V_1 = F_30 ( V_20 ,
NULL , 0 ,
& V_21 , NULL ) ) < 0 ) {
F_31 ( L_1 ) ;
F_16 ( & V_9 ) ;
return V_1 ;
}
if ( ( V_1 = F_30 ( V_22 ,
NULL , 0 ,
& V_21 , NULL ) ) < 0 ) {
F_31 ( L_2 ) ;
F_32 ( V_20 , NULL , 0 ) ;
F_16 ( & V_9 ) ;
return V_1 ;
}
F_16 ( & V_9 ) ;
return 0 ;
}
static void
F_5 ( void )
{
F_14 ( & V_9 ) ;
if ( F_32 ( V_22 , NULL , 0 ) < 0 )
F_31 ( L_3 ) ;
if ( F_32 ( V_20 , NULL , 0 ) < 0 )
F_31 ( L_4 ) ;
F_16 ( & V_9 ) ;
}
static void
F_33 ( struct V_23 * V_24 , struct V_25 * V_13 )
{
F_14 ( & V_9 ) ;
F_34 ( V_13 , L_5 , V_26 ) ;
F_35 ( V_13 ) ;
F_36 ( V_13 ) ;
F_37 ( V_13 ) ;
F_16 ( & V_9 ) ;
}
static int T_1
F_1 ( void )
{
struct V_23 * V_24 ;
V_24 = F_38 ( V_27 , V_28 , V_29 ) ;
if ( V_24 == NULL )
return - V_30 ;
V_24 -> V_31 = V_32 ;
V_24 -> V_12 = NULL ;
V_24 -> V_33 . V_34 . V_35 = F_33 ;
if ( F_39 ( V_24 ) < 0 ) {
F_40 ( V_24 ) ;
return - V_30 ;
}
V_36 = V_24 ;
return 0 ;
}
static void
F_2 ( void )
{
F_40 ( V_36 ) ;
V_36 = NULL ;
}
