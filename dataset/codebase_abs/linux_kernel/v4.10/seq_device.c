static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
return strcmp ( V_8 -> V_9 , V_6 -> V_9 ) == 0 &&
V_8 -> V_10 == V_6 -> V_10 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 ;
F_5 ( V_13 , L_1 , V_6 -> V_9 ,
V_2 -> V_14 ? L_2 : L_3 ,
V_2 -> V_14 ? 1 : 0 ) ;
return 0 ;
}
static void F_6 ( struct V_15 * V_16 ,
struct V_12 * V_13 )
{
F_7 ( & V_17 , NULL , V_13 , F_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_14 )
F_9 ( L_4 , V_6 -> V_9 ) ;
return 0 ;
}
static void F_10 ( struct V_18 * V_19 )
{
if ( F_11 ( & V_20 ) == 1 )
F_7 ( & V_17 , NULL , NULL ,
F_8 ) ;
F_12 ( & V_20 ) ;
}
static void F_13 ( void )
{
F_14 ( & V_21 ) ;
}
void F_15 ( void )
{
F_12 ( & V_20 ) ;
#ifdef F_16
F_13 () ;
#endif
}
void F_17 ( void )
{
F_18 ( & V_20 ) ;
}
void F_19 ( void )
{
F_13 () ;
F_20 ( & V_21 ) ;
}
static int F_21 ( struct V_22 * V_1 )
{
struct V_5 * V_2 = V_1 -> V_23 ;
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_22 * V_1 )
{
struct V_5 * V_2 = V_1 -> V_23 ;
int V_24 ;
V_24 = F_24 ( & V_2 -> V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! V_2 -> V_2 . V_14 )
F_13 () ;
return 0 ;
}
static int F_25 ( struct V_22 * V_1 )
{
struct V_5 * V_2 = V_1 -> V_23 ;
F_26 ( & V_2 -> V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_25 )
V_6 -> V_25 ( V_6 ) ;
F_28 ( V_6 ) ;
}
int F_29 ( struct V_26 * V_27 , int V_1 , const char * V_9 ,
int V_10 , struct V_5 * * V_28 )
{
struct V_5 * V_2 ;
int V_24 ;
static struct V_29 V_30 = {
. V_31 = F_21 ,
. V_32 = F_23 ,
. V_33 = F_25 ,
} ;
if ( V_28 )
* V_28 = NULL ;
if ( F_30 ( ! V_9 ) )
return - V_34 ;
V_2 = F_31 ( sizeof( * V_2 ) + V_10 , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
F_32 ( & V_2 -> V_2 ) ;
V_2 -> V_2 . V_37 = & V_27 -> V_38 ;
V_2 -> V_2 . V_39 = & V_17 ;
V_2 -> V_2 . V_40 = F_27 ;
F_33 ( & V_2 -> V_2 , L_5 , V_2 -> V_9 , V_27 -> V_41 , V_1 ) ;
V_24 = F_34 ( V_27 , V_42 , V_2 , & V_30 ) ;
if ( V_24 < 0 ) {
F_22 ( & V_2 -> V_2 ) ;
return V_24 ;
}
if ( V_28 )
* V_28 = V_2 ;
return 0 ;
}
int F_35 ( struct V_7 * V_4 , struct V_43 * V_44 )
{
if ( F_36 ( ! V_4 -> V_14 . V_45 || ! V_4 -> V_9 ) )
return - V_34 ;
V_4 -> V_14 . V_39 = & V_17 ;
V_4 -> V_14 . V_46 = V_44 ;
return F_37 ( & V_4 -> V_14 ) ;
}
void F_38 ( struct V_7 * V_4 )
{
F_39 ( & V_4 -> V_14 ) ;
}
static int T_1 F_40 ( void )
{
#ifdef F_41
V_47 = F_42 ( V_48 , L_6 ,
V_49 ) ;
if ( V_47 == NULL )
return - V_36 ;
V_47 -> V_50 = V_51 ;
V_47 -> V_52 . V_53 . V_54 = F_6 ;
if ( F_43 ( V_47 ) < 0 ) {
F_44 ( V_47 ) ;
return - V_36 ;
}
#endif
return 0 ;
}
static int T_1 F_45 ( void )
{
int V_24 ;
V_24 = F_46 ( & V_17 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_40 () ;
if ( V_24 < 0 )
F_47 ( & V_17 ) ;
return V_24 ;
}
static void T_2 F_48 ( void )
{
#ifdef F_49
F_50 ( & V_21 ) ;
#endif
#ifdef F_41
F_44 ( V_47 ) ;
#endif
F_47 ( & V_17 ) ;
}
