static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
int V_8 = V_9 ;
F_2 ( L_1 , V_10 , V_4 -> V_11 ) ;
F_3 ( 1000 * V_12 ) ;
while ( V_8 -- ) {
V_7 = F_4 ( V_6 -> V_13 ,
F_5 ( V_6 -> V_13 , 0 ) , 0x22 , 0x21 ,
0x1 , 0 , NULL , 0 , 100 ) ;
if ( ! V_7 )
break;
F_3 ( 1000 ) ;
}
if ( ! V_8 && V_7 ) {
F_6 ( & V_4 -> V_13 , L_2 ,
V_10 , V_7 ) ;
return V_7 ;
}
return F_7 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_14 = 1 ;
F_2 ( L_3 , V_15 ,
( int ) V_6 -> V_16 -> V_17 -> V_18 . V_19 ) ;
if ( V_6 -> V_16 -> V_17 -> V_18 . V_19 > 3 ) {
V_14 = 2 ;
}
return V_14 ;
}
static int F_9 ( struct V_5 * V_6 )
{
F_2 ( L_4 , V_10 ) ;
if ( V_6 -> V_20 < V_6 -> V_21 ||
V_6 -> V_22 < V_6 -> V_21 )
return - V_23 ;
if ( V_6 -> V_13 -> V_24 -> V_18 . V_25 != 1 ) {
F_6 ( & V_6 -> V_13 -> V_13 , L_5 ,
V_6 -> V_13 -> V_24 -> V_18 . V_25 ) ;
return - V_23 ;
}
F_2 ( L_6 ,
V_15 , V_6 -> V_21 ) ;
return F_10 ( V_6 -> V_13 ) ;
}
static int T_1 F_11 ( void )
{
int V_26 ;
if ( V_27 ) {
V_28 [ 0 ] . V_29 = V_27 ;
V_28 [ 0 ] . V_30 = V_31 ;
}
V_26 = F_12 ( & V_32 , V_33 ) ;
if ( V_26 == 0 )
F_13 (KERN_INFO KBUILD_MODNAME L_7 DRIVER_VERSION L_8
DRIVER_DESC L_9 ) ;
return V_26 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_32 , V_33 ) ;
}
