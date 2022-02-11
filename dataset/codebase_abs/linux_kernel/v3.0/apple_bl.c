static void F_1 ( int V_1 )
{
F_2 ( 0x04 | ( V_1 << 4 ) , 0xb3 ) ;
F_2 ( 0xbf , 0xb2 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
int V_1 = V_3 -> V_4 . V_5 ;
if ( V_6 )
F_4 (KERN_DEBUG DRIVER L_1 ,
intensity) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
int V_1 ;
F_2 ( 0x03 , 0xb3 ) ;
F_2 ( 0xbf , 0xb2 ) ;
V_1 = F_6 ( 0xb3 ) >> 4 ;
if ( V_6 )
F_4 (KERN_DEBUG DRIVER L_2 ,
intensity) ;
return V_1 ;
}
static void F_7 ( int V_1 )
{
F_2 ( 0x04 | ( V_1 << 4 ) , 0x52f ) ;
F_2 ( 0xbf , 0x52e ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
int V_1 = V_3 -> V_4 . V_5 ;
if ( V_6 )
F_4 (KERN_DEBUG DRIVER L_1 ,
intensity) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
int V_1 ;
F_2 ( 0x03 , 0x52f ) ;
F_2 ( 0xbf , 0x52e ) ;
V_1 = F_6 ( 0x52f ) >> 4 ;
if ( V_6 )
F_4 (KERN_DEBUG DRIVER L_2 ,
intensity) ;
return V_1 ;
}
static int T_1 F_10 ( struct V_7 * V_8 )
{
struct V_9 V_4 ;
struct V_10 * V_11 ;
int V_1 ;
V_11 = F_11 ( 0 , 0 ) ;
if ( ! V_11 ) {
F_4 (KERN_ERR DRIVER L_3 ) ;
return - V_12 ;
}
if ( V_11 -> V_13 == V_14 )
V_15 = & V_16 ;
else if ( V_11 -> V_13 == V_17 )
V_15 = & V_18 ;
F_12 ( V_11 ) ;
if ( ! V_15 ) {
F_4 (KERN_ERR DRIVER L_4 ) ;
return - V_12 ;
}
V_1 = V_15 -> V_19 . V_20 ( NULL ) ;
if ( ! V_1 ) {
V_15 -> V_21 ( 1 ) ;
if ( ! V_15 -> V_19 . V_20 ( NULL ) )
return - V_12 ;
V_15 -> V_21 ( 0 ) ;
}
if ( ! F_13 ( V_15 -> V_22 , V_15 -> V_23 ,
L_5 ) )
return - V_24 ;
memset ( & V_4 , 0 , sizeof( struct V_9 ) ) ;
V_4 . type = V_25 ;
V_4 . V_26 = 15 ;
V_27 = F_14 ( L_6 ,
NULL , NULL , & V_15 -> V_19 , & V_4 ) ;
if ( F_15 ( V_27 ) ) {
F_16 ( V_15 -> V_22 , V_15 -> V_23 ) ;
return F_17 ( V_27 ) ;
}
V_27 -> V_4 . V_5 =
V_15 -> V_19 . V_20 ( V_27 ) ;
F_18 ( V_27 ) ;
return 0 ;
}
static int T_2 F_19 ( struct V_7 * V_8 , int type )
{
F_20 ( V_27 ) ;
F_16 ( V_15 -> V_22 , V_15 -> V_23 ) ;
V_15 = NULL ;
return 0 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_28 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_28 ) ;
}
