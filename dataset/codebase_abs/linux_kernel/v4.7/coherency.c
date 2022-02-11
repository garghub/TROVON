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
static int F_6 ( struct V_4 * V_14 ,
unsigned long V_15 , void * V_16 )
{
if ( V_15 == V_17 || V_15 == V_18 )
F_1 () ;
return V_13 ;
}
static void T_2 F_7 ( struct V_19 * V_20 )
{
struct V_21 V_22 ;
struct V_19 * V_23 ;
F_8 ( V_20 , 0 , & V_22 ) ;
V_24 = V_22 . V_25 ;
F_9 ( & V_24 ) ;
V_26 = F_10 ( V_20 , 0 ) ;
V_27 = F_10 ( V_20 , 1 ) ;
V_23 = F_11 ( NULL , NULL ,
L_1 ) ;
if ( ! V_23 )
goto exit;
V_2 = F_10 ( V_23 , 0 ) ;
if ( ! V_2 ) {
F_12 ( V_23 ) ;
goto exit;
}
F_12 ( V_23 ) ;
F_13 ( & V_28 ) ;
exit:
F_14 () ;
}
static void T_3 *
F_15 ( T_4 V_29 , T_5 V_30 ,
unsigned int V_31 , void * V_32 )
{
V_31 = V_33 ;
return F_16 ( V_29 , V_30 , V_31 , V_32 ) ;
}
static void T_2 F_17 ( struct V_19 * V_20 )
{
struct V_19 * V_34 ;
V_27 = F_10 ( V_20 , 0 ) ;
V_35 = F_15 ;
F_18 ( V_33 ) ;
if ( ! F_19 () )
return;
F_20 (cache_dn, NULL, L_2 ) {
struct V_36 * V_37 ;
V_37 = F_21 ( sizeof( * V_37 ) , V_38 ) ;
V_37 -> V_39 = F_22 ( L_3 , V_38 ) ;
F_23 ( V_34 , V_37 ) ;
}
}
static int F_24 ( void )
{
struct V_19 * V_20 ;
const struct V_40 * V_41 ;
int type ;
if ( ! F_25 () )
return V_42 ;
V_20 = F_26 ( NULL , V_43 , & V_41 ) ;
if ( ! V_20 )
return V_42 ;
type = ( int ) V_41 -> V_44 ;
F_12 ( V_20 ) ;
return type ;
}
int F_14 ( void )
{
int type = F_24 () ;
if ( type == V_45 ) {
if ( ! V_26 ) {
F_27 ( L_4 ) ;
F_27 ( L_5 ) ;
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
return F_24 () != V_42 ;
}
int T_2 F_30 ( void )
{
int type = F_24 () ;
struct V_19 * V_20 ;
V_20 = F_31 ( NULL , V_43 ) ;
if ( type == V_45 )
F_7 ( V_20 ) ;
else if ( type == V_46 ||
type == V_47 )
F_17 ( V_20 ) ;
F_12 ( V_20 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
if ( F_19 () )
F_33 ( & V_48 ,
& V_49 ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
if ( F_19 () )
F_33 ( & V_50 ,
& V_51 ) ;
return 0 ;
}
