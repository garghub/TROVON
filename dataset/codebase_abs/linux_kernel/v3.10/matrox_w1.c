static T_1 T_2 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_2 V_4 ;
F_2 ( V_3 , V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 ) ;
F_4 () ;
return V_4 ;
}
static T_1 void F_5 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_7 )
{
F_2 ( V_3 , V_2 -> V_5 ) ;
F_2 ( V_7 , V_2 -> V_6 ) ;
F_6 () ;
}
static void F_7 ( void * V_8 , T_2 V_9 )
{
T_2 V_4 ;
struct V_1 * V_2 = V_8 ;
if ( V_9 )
V_9 = 0 ;
else
V_9 = V_2 -> V_10 ;
V_4 = F_1 ( V_2 , V_11 ) ;
F_5 ( V_2 , V_11 , ( ( V_4 & ~ V_2 -> V_10 ) | V_9 ) ) ;
F_5 ( V_2 , V_12 , 0x00 ) ;
}
static T_2 F_8 ( void * V_8 )
{
T_2 V_4 ;
struct V_1 * V_2 = V_8 ;
V_4 = F_1 ( V_2 , V_12 ) ;
return V_4 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_12 , 0xFF ) ;
F_5 ( V_2 , V_11 , 0x00 ) ;
}
static int F_10 ( struct V_13 * V_14 , const struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_17 ;
assert ( V_14 != NULL ) ;
assert ( V_16 != NULL ) ;
if ( V_14 -> V_18 != V_19 || V_14 -> V_20 != V_21 )
return - V_22 ;
V_2 = F_11 ( sizeof( struct V_1 ) +
sizeof( struct V_23 ) , V_24 ) ;
if ( ! V_2 ) {
F_12 ( & V_14 -> V_2 ,
L_1 ,
V_25 ) ;
return - V_26 ;
}
V_2 -> V_27 = (struct V_23 * ) ( V_2 + 1 ) ;
V_2 -> V_28 = F_13 ( V_14 , 1 ) ;
V_2 -> V_29 = F_14 ( V_2 -> V_28 , 16384 ) ;
if ( ! V_2 -> V_29 ) {
F_12 ( & V_14 -> V_2 , L_2 ,
V_25 , V_2 -> V_28 , 16384 ) ;
V_17 = - V_30 ;
goto V_31;
}
V_2 -> V_32 = V_2 -> V_29 + V_33 ;
V_2 -> V_5 = V_2 -> V_32 + V_34 ;
V_2 -> V_6 = V_2 -> V_32 + V_35 ;
V_2 -> V_10 = ( V_36 ) ;
F_9 ( V_2 ) ;
V_2 -> V_27 -> V_8 = V_2 ;
V_2 -> V_27 -> V_37 = & F_8 ;
V_2 -> V_27 -> V_38 = & F_7 ;
V_17 = F_15 ( V_2 -> V_27 ) ;
if ( V_17 )
goto V_31;
F_16 ( V_14 , V_2 ) ;
V_2 -> V_39 = 1 ;
F_17 ( & V_14 -> V_2 , L_3 ) ;
return 0 ;
V_31:
if ( V_2 -> V_29 )
F_18 ( V_2 -> V_29 ) ;
F_19 ( V_2 ) ;
return V_17 ;
}
static void F_20 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_21 ( V_14 ) ;
assert ( V_2 != NULL ) ;
if ( V_2 -> V_39 ) {
F_22 ( V_2 -> V_27 ) ;
F_18 ( V_2 -> V_29 ) ;
}
F_19 ( V_2 ) ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_40 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_40 ) ;
}
