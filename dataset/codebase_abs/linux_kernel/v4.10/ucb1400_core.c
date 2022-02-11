unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
unsigned int V_5 ;
if ( V_4 )
V_3 |= V_6 ;
F_2 ( V_2 , V_7 , V_8 | V_3 ) ;
F_2 ( V_2 , V_7 , V_8 | V_3 |
V_9 ) ;
while ( ! ( ( V_5 = F_3 ( V_2 , V_10 ) )
& V_11 ) )
F_4 ( 1 ) ;
return V_5 & V_12 ;
}
static int F_5 ( struct V_13 * V_14 )
{
int V_15 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_23 = F_6 ( V_14 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_17 = F_7 ( sizeof( struct V_16 ) , V_24 ) ;
if ( ! V_17 ) {
V_15 = - V_25 ;
goto V_15;
}
F_8 ( V_14 , V_17 ) ;
V_2 = F_9 ( V_14 ) ;
V_19 . V_26 = F_3 ( V_2 , V_27 ) ;
if ( V_19 . V_26 != V_28 ) {
V_15 = - V_29 ;
goto V_30;
}
V_21 . V_2 = V_2 ;
if ( V_23 ) {
V_21 . V_31 = V_23 -> V_31 ;
V_21 . V_32 = V_23 -> V_32 ;
V_21 . V_33 = V_23 -> V_33 ;
}
V_17 -> V_20 = F_10 ( L_1 , - 1 ) ;
if ( ! V_17 -> V_20 ) {
V_15 = - V_25 ;
goto V_30;
}
V_15 = F_11 ( V_17 -> V_20 , & V_21 ,
sizeof( V_21 ) ) ;
if ( V_15 )
goto V_34;
V_15 = F_12 ( V_17 -> V_20 ) ;
if ( V_15 )
goto V_34;
V_19 . V_2 = V_2 ;
if ( V_23 != NULL && V_23 -> V_35 >= 0 )
V_19 . V_35 = V_23 -> V_35 ;
else
V_19 . V_35 = - 1 ;
V_17 -> V_18 = F_10 ( L_2 , - 1 ) ;
if ( ! V_17 -> V_18 ) {
V_15 = - V_25 ;
goto V_36;
}
V_15 = F_11 ( V_17 -> V_18 , & V_19 ,
sizeof( V_19 ) ) ;
if ( V_15 )
goto V_37;
V_15 = F_12 ( V_17 -> V_18 ) ;
if ( V_15 )
goto V_37;
return 0 ;
V_37:
F_13 ( V_17 -> V_18 ) ;
V_36:
F_14 ( V_17 -> V_20 ) ;
V_34:
F_13 ( V_17 -> V_20 ) ;
V_30:
F_15 ( V_17 ) ;
V_15:
return V_15 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_17 ( V_14 ) ;
F_18 ( V_17 -> V_18 ) ;
F_18 ( V_17 -> V_20 ) ;
F_15 ( V_17 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_38 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_38 ) ;
}
