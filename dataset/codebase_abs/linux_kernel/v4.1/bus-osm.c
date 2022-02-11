static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
if ( F_3 ( V_4 ) )
return - V_7 ;
V_4 -> V_8 . V_9 [ 0 ] = F_4 ( V_10 | V_11 ) ;
V_4 -> V_8 . V_9 [ 1 ] =
F_4 ( V_12 << 24 | V_13 << 12 | V_2 -> V_14 .
V_15 ) ;
return F_5 ( V_2 -> V_5 , V_4 , 60 ) ;
}
static T_1 F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , T_2 V_21 )
{
struct V_1 * V_22 = F_7 ( V_17 ) ;
int V_23 ;
V_23 = F_1 ( V_22 ) ;
if ( V_23 )
F_8 ( L_1 , V_23 ) ;
return V_21 ;
}
static int F_9 ( struct V_16 * V_2 )
{
struct V_1 * V_22 = F_7 ( F_10 ( V_2 ) ) ;
int V_23 ;
V_23 = F_11 ( V_2 , & V_24 ) ;
if ( V_23 )
goto V_25;
F_12 ( L_2 , V_22 -> V_14 . V_15 ) ;
return 0 ;
V_25:
F_13 ( V_2 ) ;
return V_23 ;
}
static int F_14 ( struct V_16 * V_2 )
{
struct V_1 * V_22 = F_7 ( V_2 ) ;
F_15 ( V_2 , & V_24 ) ;
F_13 ( V_2 ) ;
F_12 ( L_3 , V_22 -> V_14 . V_15 ) ;
return 0 ;
}
static int T_3 F_16 ( void )
{
int V_23 ;
F_17 (KERN_INFO OSM_DESCRIPTION L_4 OSM_VERSION L_5 ) ;
V_23 = F_18 ( & V_26 ) ;
if ( V_23 ) {
F_19 ( L_6 ) ;
return V_23 ;
}
return 0 ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_26 ) ;
}
