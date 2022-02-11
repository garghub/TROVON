static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_3 = F_2 ( V_6 , L_1 , NULL , NULL ) ;
if ( F_3 ( V_3 ) )
return - V_7 ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_8 . V_9 ; V_4 ++ ) {
V_3 = F_2 ( V_6 , L_2 , NULL , NULL ) ;
if ( F_3 ( V_3 ) )
return - V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 V_8 ;
struct V_1 * V_2 ;
memset ( & V_8 , 0 , sizeof( struct V_12 ) ) ;
V_8 . type = V_13 ;
V_8 . V_14 = V_5 ;
V_2 = F_5 ( L_3 , & V_11 -> V_15 , NULL ,
& V_16 , & V_8 ) ;
if ( F_6 ( V_2 ) )
return F_7 ( V_2 ) ;
F_8 ( V_11 , V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int T_2 F_12 ( const struct V_17 * V_18 )
{
F_13 (KERN_INFO KBUILD_MODNAME L_4 , id->ident) ;
return 1 ;
}
static int T_2 F_14 ( void )
{
if ( ! V_19 && ! F_15 ( V_20 ) )
return - V_21 ;
V_6 = F_16 () ;
if ( ! V_6 )
return - V_21 ;
V_22 = F_17 ( & V_23 ,
F_4 ,
NULL , 0 , NULL , 0 ) ;
return F_18 ( V_22 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_22 ) ;
F_21 ( & V_23 ) ;
}
