static void F_1 ( void )
{
T_1 V_1 ;
if ( ! V_2 )
return;
V_1 = F_2 ( V_2 ) ;
V_1 &= ~ V_3 ;
F_3 ( V_1 , V_2 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
unsigned long V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
if ( V_6 != V_10 )
return V_11 ;
F_5 ( V_9 , & V_12 ) ;
return V_13 ;
}
static int F_6 ( unsigned int V_14 )
{
F_1 () ;
return 0 ;
}
static void T_2 F_7 ( struct V_15 * V_16 )
{
struct V_17 V_18 ;
struct V_15 * V_19 ;
F_8 ( V_16 , 0 , & V_18 ) ;
V_20 = V_18 . V_21 ;
F_9 ( & V_20 ) ;
V_22 = F_10 ( V_16 , 0 ) ;
V_23 = F_10 ( V_16 , 1 ) ;
V_19 = F_11 ( NULL , NULL ,
L_1 ) ;
if ( ! V_19 )
goto exit;
V_2 = F_10 ( V_19 , 0 ) ;
if ( ! V_2 ) {
F_12 ( V_19 ) ;
goto exit;
}
F_12 ( V_19 ) ;
F_13 ( V_24 ,
L_2 ,
F_6 , NULL ) ;
exit:
F_14 () ;
}
static void T_3 *
F_15 ( T_4 V_25 , T_5 V_26 ,
unsigned int V_27 , void * V_28 )
{
V_27 = V_29 ;
return F_16 ( V_25 , V_26 , V_27 , V_28 ) ;
}
static void T_2 F_17 ( struct V_15 * V_16 )
{
struct V_15 * V_30 ;
V_23 = F_10 ( V_16 , 0 ) ;
V_31 = F_15 ;
F_18 ( V_29 ) ;
if ( ! F_19 () )
return;
F_20 (cache_dn, NULL, L_3 ) {
struct V_32 * V_33 ;
V_33 = F_21 ( sizeof( * V_33 ) , V_34 ) ;
V_33 -> V_35 = F_22 ( L_4 , V_34 ) ;
F_23 ( V_30 , V_33 ) ;
}
}
static int F_24 ( void )
{
struct V_15 * V_16 ;
const struct V_36 * V_37 ;
int type ;
if ( ! F_25 () )
return V_38 ;
V_16 = F_26 ( NULL , V_39 , & V_37 ) ;
if ( ! V_16 )
return V_38 ;
type = ( int ) V_37 -> V_40 ;
F_12 ( V_16 ) ;
return type ;
}
int F_14 ( void )
{
int type = F_24 () ;
if ( type == V_41 ) {
if ( ! V_22 ) {
F_27 ( L_5 ) ;
F_27 ( L_6 ) ;
return 1 ;
}
F_1 () ;
F_28 () ;
return F_29 () ;
}
return 0 ;
}
int F_19 ( void )
{
return F_24 () != V_38 ;
}
int T_2 F_30 ( void )
{
int type = F_24 () ;
struct V_15 * V_16 ;
V_16 = F_31 ( NULL , V_39 ) ;
if ( type == V_41 )
F_7 ( V_16 ) ;
else if ( type == V_42 ||
type == V_43 )
F_17 ( V_16 ) ;
F_12 ( V_16 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
if ( F_19 () )
F_33 ( & V_44 ,
& V_45 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
if ( F_19 () )
F_33 ( & V_46 ,
& V_47 ) ;
return 0 ;
}
