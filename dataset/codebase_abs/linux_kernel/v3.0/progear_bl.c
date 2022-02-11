static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 ;
if ( V_2 -> V_4 . V_6 != V_7 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 != V_7 )
V_3 = 0 ;
F_2 ( V_9 , V_10 , V_3 + V_11 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_4 ( V_9 , V_10 , & V_3 ) ;
return V_3 - V_11 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_14 V_4 ;
T_1 V_15 ;
struct V_1 * V_16 ;
int V_17 ;
V_9 = F_6 ( V_18 , V_19 , NULL ) ;
if ( ! V_9 ) {
F_7 ( L_1 ) ;
return - V_20 ;
}
V_21 = F_6 ( V_18 , V_22 , NULL ) ;
if ( ! V_21 ) {
F_7 ( L_2 ) ;
V_17 = - V_20 ;
goto V_23;
}
F_4 ( V_21 , V_24 , & V_15 ) ;
F_2 ( V_21 , V_24 , V_15 | 0x20 ) ;
memset ( & V_4 , 0 , sizeof( struct V_14 ) ) ;
V_4 . type = V_25 ;
V_4 . V_26 = V_27 - V_11 ;
V_16 = F_8 ( L_3 ,
& V_13 -> V_28 , NULL ,
& V_29 ,
& V_4 ) ;
if ( F_9 ( V_16 ) ) {
V_17 = F_10 ( V_16 ) ;
goto V_30;
}
F_11 ( V_13 , V_16 ) ;
V_16 -> V_4 . V_6 = V_7 ;
V_16 -> V_4 . V_5 = V_27 - V_11 ;
F_1 ( V_16 ) ;
return 0 ;
V_30:
F_12 ( V_21 ) ;
V_23:
F_12 ( V_9 ) ;
return V_17 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_14 ( V_13 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
int V_17 = F_17 ( & V_31 ) ;
if ( V_17 )
return V_17 ;
V_32 = F_18 ( L_3 , - 1 ,
NULL , 0 ) ;
if ( F_9 ( V_32 ) ) {
F_19 ( & V_31 ) ;
return F_10 ( V_32 ) ;
}
return 0 ;
}
static void T_3 F_20 ( void )
{
F_12 ( V_9 ) ;
F_12 ( V_21 ) ;
F_21 ( V_32 ) ;
F_19 ( & V_31 ) ;
}
