static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_3 ;
unsigned char V_5 [ 3 ] = V_6 ;
V_5 [ 2 ] = ( unsigned char ) V_3 ;
F_2 () ;
F_3 ( V_5 , ( 0x30 << 8 ) | V_7 ) ;
F_4 () ;
V_8 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return V_8 ;
}
static int F_6 ( struct V_9 * V_10 )
{
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_13 V_4 ;
struct V_1 * V_2 ;
memset ( & V_4 , 0 , sizeof( struct V_13 ) ) ;
V_4 . type = V_14 ;
V_4 . V_15 = V_16 ;
V_2 = F_10 ( L_1 , & V_12 -> V_10 , NULL ,
& V_17 , & V_4 ) ;
if ( F_11 ( V_2 ) )
return F_12 ( V_2 ) ;
F_13 ( V_12 , V_2 ) ;
V_2 -> V_4 . V_3 = V_18 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
V_2 -> V_4 . V_3 = V_18 ;
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int T_1 F_17 ( const struct V_19 * V_20 )
{
F_18 (KERN_INFO KBUILD_MODNAME L_2 , id->ident) ;
return 1 ;
}
static int T_1 F_19 ( void )
{
if ( ! V_21 && ! F_20 ( V_22 ) )
return - V_23 ;
V_24 = F_21 ( & V_25 ,
F_9 ,
NULL , 0 , NULL , 0 ) ;
if ( F_11 ( V_24 ) )
return F_12 ( V_24 ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( V_24 ) ;
F_24 ( & V_25 ) ;
}
