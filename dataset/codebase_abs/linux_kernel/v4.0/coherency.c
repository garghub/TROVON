int F_1 ( void )
{
if ( ! V_1 ) {
F_2 ( L_1 ) ;
F_2 ( L_2 ) ;
return 1 ;
}
F_3 () ;
return F_4 () ;
}
static int F_5 ( struct V_2 * V_3 ,
unsigned long V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
if ( V_4 != V_8 )
return V_9 ;
F_6 ( V_7 , & V_10 ) ;
return V_11 ;
}
static void T_1 F_7 ( struct V_12 * V_13 )
{
struct V_14 V_15 ;
F_8 ( V_13 , 0 , & V_15 ) ;
V_16 = V_15 . V_17 ;
F_9 ( & V_16 ) ;
V_1 = F_10 ( V_13 , 0 ) ;
V_18 = F_10 ( V_13 , 1 ) ;
F_1 () ;
}
static void T_2 *
F_11 ( T_3 V_19 , T_4 V_20 ,
unsigned int V_21 , void * V_22 )
{
struct V_14 V_23 ;
F_12 ( & V_23 ) ;
if ( V_23 . V_17 <= V_19 && ( V_19 + V_20 ) <= V_23 . V_24 )
V_21 = V_25 ;
return F_13 ( V_19 , V_20 , V_21 , V_22 ) ;
}
static void T_1 F_14 ( struct V_12 * V_13 )
{
struct V_12 * V_26 ;
V_18 = F_10 ( V_13 , 0 ) ;
V_27 = F_11 ;
if ( ! F_15 () )
return;
F_16 (cache_dn, NULL, L_3 ) {
struct V_28 * V_29 ;
V_29 = F_17 ( sizeof( * V_29 ) , V_30 ) ;
V_29 -> V_31 = F_18 ( L_4 , V_30 ) ;
F_19 ( V_26 , V_29 ) ;
}
}
static int F_20 ( void )
{
struct V_12 * V_13 ;
const struct V_32 * V_33 ;
int type ;
if ( ! F_21 () )
return V_34 ;
V_13 = F_22 ( NULL , V_35 , & V_33 ) ;
if ( ! V_13 )
return V_34 ;
type = ( int ) V_33 -> V_36 ;
F_23 ( V_13 ) ;
return type ;
}
int F_15 ( void )
{
return F_20 () != V_34 ;
}
int T_1 F_24 ( void )
{
int type = F_20 () ;
struct V_12 * V_13 ;
V_13 = F_25 ( NULL , V_35 ) ;
if ( type == V_37 )
F_7 ( V_13 ) ;
else if ( type == V_38 ||
type == V_39 )
F_14 ( V_13 ) ;
F_23 ( V_13 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
if ( F_15 () )
F_27 ( & V_40 ,
& V_41 ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( F_15 () )
F_27 ( & V_42 ,
& V_43 ) ;
return 0 ;
}
