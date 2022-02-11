static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 , int V_7 )
{
int V_8 ;
int V_9 ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
V_8 = F_2 ( V_6 , V_13 ) ;
V_9 = V_3 -> V_14 ;
if ( V_9 < 0 )
V_9 = 7 ;
F_3 ( V_6 , V_9 , V_13 ) ;
V_3 -> V_15 = V_16 ;
V_10 = F_4 ( V_3 , sizeof( struct V_11 ) ) ;
if ( ! V_10 )
goto V_17;
V_10 -> V_18 = V_6 ;
V_10 -> V_19 = 16 ;
V_10 -> V_20 = - 1 ;
if ( V_7 != - 1 )
V_10 -> V_21 = V_7 ;
V_12 = F_5 ( V_10 ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_9 = V_9 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_22 = V_13 ;
if ( F_6 ( V_7 , V_23 , 0 , V_16 , V_10 ) )
goto V_24;
sprintf ( V_12 -> V_25 ,
L_1 ,
V_8 , V_6 , V_7 , V_26 ) ;
if ( F_7 ( V_10 , NULL ) )
goto V_27;
F_8 ( V_10 ) ;
return V_10 ;
V_27:
F_9 ( V_7 , V_10 ) ;
V_24:
F_10 ( V_10 ) ;
V_17:
return NULL ;
}
static int F_11 ( struct V_4 * V_5 )
{
T_1 * V_28 ;
F_12 ( & V_5 -> V_29 , L_2 ) ;
V_28 = F_13 ( sizeof( * V_28 ) , V_30 ) ;
if ( ! V_28 )
return - V_31 ;
V_28 -> V_32 = V_5 ;
V_5 -> V_12 = V_28 ;
V_5 -> V_33 |= V_34 | V_35 ;
V_5 -> V_36 = V_37 ;
return F_14 ( V_5 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
F_12 ( & V_5 -> V_29 , L_3 ) ;
F_16 ( V_5 ) ;
F_17 ( V_5 -> V_12 ) ;
}
static int F_18 ( struct V_4 * V_32 , void * V_38 )
{
V_32 -> V_39 = 10 ;
V_32 -> V_40 [ 0 ] -> V_41 &= ~ V_42 ;
V_32 -> V_40 [ 0 ] -> V_41 |= V_43 ;
if ( V_32 -> V_40 [ 0 ] -> V_44 == 0 )
return - V_45 ;
return F_19 ( V_32 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
T_1 * V_28 = V_5 -> V_12 ;
int V_46 ;
struct V_1 * V_3 ;
F_12 ( & V_5 -> V_29 , L_4 ) ;
V_46 = F_20 ( V_5 , F_18 , NULL ) ;
if ( V_46 )
goto V_47;
if ( ! V_5 -> V_21 )
goto V_47;
V_46 = F_21 ( V_5 ) ;
if ( V_46 )
goto V_47;
if ( ( V_28 -> V_48 == V_49 ) || ( V_28 -> V_48 == V_50 ) || ( V_28 -> V_48 == 0x0098 ) ) {
F_22 ( 0xb4 , V_5 -> V_40 [ 0 ] -> V_44 + 0xd ) ;
F_22 ( 0x24 , V_5 -> V_40 [ 0 ] -> V_44 + 0x9 ) ;
F_22 ( 0x04 , V_5 -> V_40 [ 0 ] -> V_44 + 0xd ) ;
}
if ( F_23 ( V_5 -> V_40 [ 0 ] ) == 32 )
V_3 = F_1 ( & V_51 , V_5 ,
V_5 -> V_40 [ 0 ] -> V_44 + 16 , V_5 -> V_21 ) ;
else
V_3 = F_1 ( & V_51 , V_5 ,
V_5 -> V_40 [ 0 ] -> V_44 , V_5 -> V_21 ) ;
if ( ! V_3 ) {
F_24 ( V_52 L_5 , V_16 ) ;
goto V_47;
}
V_28 -> V_3 = V_3 ;
return 0 ;
V_47:
F_25 ( V_5 ) ;
return - V_45 ;
}
static void F_16 ( struct V_4 * V_5 )
{
T_1 * V_28 = V_5 -> V_12 ;
F_12 ( & V_5 -> V_29 , L_6 ) ;
F_26 ( V_28 -> V_3 ) ;
F_9 ( V_5 -> V_21 , V_28 -> V_3 ) ;
F_25 ( V_5 ) ;
F_10 ( V_28 -> V_3 ) ;
}
static int F_27 ( struct V_4 * V_5 )
{
T_1 * V_28 = V_5 -> V_12 ;
F_21 ( V_5 ) ;
if ( ( V_28 -> V_48 == V_49 ) ||
( V_28 -> V_48 == V_50 ) ||
( V_28 -> V_48 == 0x0098 ) ) {
F_22 ( 0x80 , V_5 -> V_40 [ 0 ] -> V_44 + 0xd ) ;
F_22 ( 0x24 , V_5 -> V_40 [ 0 ] -> V_44 + 0x9 ) ;
F_22 ( 0x04 , V_5 -> V_40 [ 0 ] -> V_44 + 0xd ) ;
}
F_28 ( NULL ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_53 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_53 ) ;
}
