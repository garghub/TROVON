static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
if ( V_3 != V_7 )
return V_8 ;
F_2 ( V_6 , & V_9 ) ;
return V_10 ;
}
static void T_1 F_3 ( struct V_11 * V_12 )
{
struct V_13 V_14 ;
F_4 ( V_12 , 0 , & V_14 ) ;
V_15 = V_14 . V_16 ;
F_5 ( & V_15 ) ;
V_17 = F_6 ( V_12 , 0 ) ;
V_18 = F_6 ( V_12 , 1 ) ;
F_7 () ;
}
static void T_2 *
F_8 ( T_3 V_19 , T_4 V_20 ,
unsigned int V_21 , void * V_22 )
{
struct V_13 V_23 ;
F_9 ( & V_23 ) ;
if ( V_23 . V_16 <= V_19 && ( V_19 + V_20 ) <= V_23 . V_24 )
V_21 = V_25 ;
return F_10 ( V_19 , V_20 , V_21 , V_22 ) ;
}
static void T_1 F_11 ( struct V_11 * V_12 )
{
struct V_11 * V_26 ;
V_18 = F_6 ( V_12 , 0 ) ;
V_27 = F_8 ;
if ( ! F_12 () )
return;
F_13 (cache_dn, NULL, L_1 ) {
struct V_28 * V_29 ;
V_29 = F_14 ( sizeof( * V_29 ) , V_30 ) ;
V_29 -> V_31 = F_15 ( L_2 , V_30 ) ;
F_16 ( V_26 , V_29 ) ;
}
}
static int F_17 ( void )
{
struct V_11 * V_12 ;
const struct V_32 * V_33 ;
int type ;
if ( ! F_18 () )
return V_34 ;
V_12 = F_19 ( NULL , V_35 , & V_33 ) ;
if ( ! V_12 )
return V_34 ;
type = ( int ) V_33 -> V_36 ;
F_20 ( V_12 ) ;
return type ;
}
int F_7 ( void )
{
int type = F_17 () ;
if ( type == V_37 ) {
if ( ! V_17 ) {
F_21 ( L_3 ) ;
F_21 ( L_4 ) ;
return 1 ;
}
F_22 () ;
return F_23 () ;
}
return 0 ;
}
int F_12 ( void )
{
return F_17 () != V_34 ;
}
int T_1 F_24 ( void )
{
int type = F_17 () ;
struct V_11 * V_12 ;
V_12 = F_25 ( NULL , V_35 ) ;
if ( type == V_37 )
F_3 ( V_12 ) ;
else if ( type == V_38 ||
type == V_39 )
F_11 ( V_12 ) ;
F_20 ( V_12 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
if ( F_12 () )
F_27 ( & V_40 ,
& V_41 ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( F_12 () )
F_27 ( & V_42 ,
& V_43 ) ;
return 0 ;
}
