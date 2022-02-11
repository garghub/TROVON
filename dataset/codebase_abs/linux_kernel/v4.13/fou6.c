static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 * V_7 , T_2 V_8 )
{
struct V_9 * V_10 ;
F_2 ( V_2 , sizeof( struct V_9 ) ) ;
F_3 ( V_2 ) ;
V_10 = F_4 ( V_2 ) ;
V_10 -> V_11 = V_4 -> V_12 ;
V_10 -> V_13 = V_8 ;
V_10 -> V_14 = F_5 ( V_2 -> V_14 ) ;
F_6 ( ! ( V_4 -> V_15 & V_16 ) , V_2 ,
& V_6 -> V_17 , & V_6 -> V_18 , V_2 -> V_14 ) ;
* V_7 = V_19 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_7 , struct V_5 * V_6 )
{
T_2 V_8 ;
int V_20 ;
int type = V_4 -> V_15 & V_16 ?
V_21 : V_22 ;
V_20 = F_8 ( V_2 , V_4 , V_7 , & V_8 , type ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_7 , struct V_5 * V_6 )
{
T_2 V_8 ;
int V_20 ;
int type = V_4 -> V_15 & V_16 ?
V_21 : V_22 ;
V_20 = F_10 ( V_2 , V_4 , V_7 , & V_8 , type ) ;
if ( V_20 )
return V_20 ;
F_1 ( V_2 , V_4 , V_6 , V_7 , V_8 ) ;
return 0 ;
}
static int F_11 ( void )
{
int V_23 ;
V_23 = F_12 ( & V_24 , V_25 ) ;
if ( V_23 < 0 ) {
F_13 ( L_1 ) ;
return V_23 ;
}
V_23 = F_12 ( & V_26 , V_27 ) ;
if ( V_23 < 0 ) {
F_13 ( L_2 ) ;
F_14 ( & V_24 , V_25 ) ;
return V_23 ;
}
return 0 ;
}
static void F_15 ( void )
{
F_14 ( & V_24 , V_25 ) ;
F_14 ( & V_26 , V_27 ) ;
}
static int F_11 ( void )
{
return 0 ;
}
static void F_15 ( void )
{
}
static int T_3 F_16 ( void )
{
int V_23 ;
V_23 = F_11 () ;
return V_23 ;
}
static void T_4 F_17 ( void )
{
F_15 () ;
}
