int F_1 ( struct V_1 * V_2 )
{
return V_2 == & V_3 . V_4 ;
}
static int F_2 ( struct V_5 * V_6 , void * V_7 , int V_8 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 ;
V_6 -> V_12 = V_13 ;
V_6 -> V_14 = V_15 ;
V_6 -> V_16 = V_17 ;
V_6 -> V_18 = & V_19 ;
V_6 -> V_20 = 1 ;
V_9 = F_3 ( V_21 | V_22 | V_23 | V_24 ,
& V_25 , V_6 ) ;
if ( V_9 ) {
V_9 -> V_26 = & V_27 ;
V_9 -> V_28 = & V_29 ;
F_4 ( V_9 ) ;
} else {
F_5 ( L_1 ) ;
return - V_30 ;
}
V_11 = F_6 ( V_9 ) ;
if ( ! V_11 ) {
F_5 ( L_2 , V_31 ) ;
return - V_30 ;
}
F_7 ( & V_3 ) ;
V_3 . V_4 . V_32 = V_11 ;
V_11 -> V_33 = & V_25 ;
V_6 -> V_34 = V_11 ;
V_6 -> V_35 = & V_36 ;
return 0 ;
}
static struct V_10 * F_8 ( struct V_37 * V_38 ,
int V_39 , const char * V_40 , void * V_7 )
{
return F_9 ( V_38 , V_39 , V_7 , F_2 ) ;
}
struct V_10 * F_10 ( void )
{
int V_41 = F_11 ( & V_42 , & V_43 ,
& V_44 ) ;
return V_41 ? F_12 ( V_41 ) : V_43 -> V_45 ;
}
void F_13 ( void )
{
F_14 ( & V_43 , & V_44 ) ;
}
static int T_1 F_15 ( void )
{
int V_41 = - V_30 ;
V_46 = F_16 ( L_3 ,
sizeof( struct V_47 ) ,
0 , 0 , NULL ) ;
if ( ! V_46 )
goto V_48;
V_41 = F_17 ( V_49 , L_4 ) ;
if ( V_41 )
goto V_50;
V_41 = F_18 ( & V_42 ) ;
if ( V_41 )
goto V_51;
return 0 ;
V_51:
F_19 ( L_5 ) ;
F_20 ( V_49 , L_4 ) ;
V_50:
F_21 ( V_46 ) ;
V_46 = NULL ;
V_48:
return V_41 ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_42 ) ;
F_20 ( V_49 , L_4 ) ;
F_21 ( V_46 ) ;
V_46 = NULL ;
}
