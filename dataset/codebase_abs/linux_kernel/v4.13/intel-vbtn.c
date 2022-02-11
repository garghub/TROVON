static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
V_4 -> V_7 = F_3 ( & V_2 -> V_5 ) ;
if ( ! V_4 -> V_7 )
return - V_8 ;
V_6 = F_4 ( V_4 -> V_7 , V_9 , NULL ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_7 -> V_5 . V_10 = & V_2 -> V_5 ;
V_4 -> V_7 -> V_11 = L_1 ;
V_4 -> V_7 -> V_12 . V_13 = V_14 ;
return F_5 ( V_4 -> V_7 ) ;
}
static void F_6 ( T_1 V_15 , T_2 V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_18 ) {
if ( F_7 ( V_4 -> V_7 , V_16 ) ) {
F_8 ( & V_2 -> V_5 ) ;
return;
}
} else if ( F_9 ( V_4 -> V_7 , V_16 , 1 , true ) ) {
return;
}
F_10 ( & V_2 -> V_5 , L_2 , V_16 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_15 = F_12 ( & V_2 -> V_5 ) ;
struct V_3 * V_4 ;
T_3 V_19 ;
int V_20 ;
V_19 = F_13 ( V_15 , L_3 , NULL , NULL ) ;
if ( F_14 ( V_19 ) ) {
F_15 ( & V_2 -> V_5 , L_4 ) ;
return - V_21 ;
}
V_4 = F_16 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_8 ;
F_17 ( & V_2 -> V_5 , V_4 ) ;
V_20 = F_1 ( V_2 ) ;
if ( V_20 ) {
F_18 ( L_5 ) ;
return V_20 ;
}
V_19 = F_19 ( V_15 ,
V_23 ,
F_6 ,
V_2 ) ;
if ( F_14 ( V_19 ) )
return - V_24 ;
F_20 ( & V_2 -> V_5 , true ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_15 = F_12 ( & V_2 -> V_5 ) ;
F_22 ( V_15 , V_23 , F_6 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
V_4 -> V_18 = true ;
return 0 ;
}
static int F_24 ( struct V_2 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
V_4 -> V_18 = false ;
return 0 ;
}
static T_3 T_4
F_25 ( T_1 V_15 , T_2 V_25 , void * V_17 , void * * V_26 )
{
const struct V_27 * V_28 = V_17 ;
struct V_29 * V_5 ;
if ( F_26 ( V_15 , & V_5 ) != 0 )
return V_30 ;
if ( F_27 ( V_5 , V_28 ) == 0 )
if ( F_28 ( V_5 , NULL ) )
F_10 ( & V_5 -> V_5 ,
L_6 ) ;
return V_30 ;
}
static int T_4 F_29 ( void )
{
F_30 ( V_31 , V_32 ,
V_33 , F_25 , NULL ,
( void * ) V_34 , NULL ) ;
return F_31 ( & V_35 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_35 ) ;
}
