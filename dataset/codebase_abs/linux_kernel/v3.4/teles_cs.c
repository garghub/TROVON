static int T_1 F_1 ( struct V_1 * V_2 )
{
T_2 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( T_2 ) , V_5 ) ;
if ( ! V_3 ) return - V_6 ;
V_3 -> V_7 = - 1 ;
V_3 -> V_8 = V_2 ;
V_2 -> V_9 = V_3 ;
V_2 -> V_10 |= V_11 | V_12 ;
return F_4 ( V_2 ) ;
}
static void T_3 F_5 ( struct V_1 * V_2 )
{
T_2 * V_13 = V_2 -> V_9 ;
F_2 ( & V_2 -> V_4 , L_2 , V_2 ) ;
V_13 -> V_14 = 1 ;
F_6 ( V_2 ) ;
F_7 ( V_13 ) ;
}
static int F_8 ( struct V_1 * V_8 , void * V_15 )
{
int V_16 ;
V_8 -> V_17 = 5 ;
V_8 -> V_18 [ 0 ] -> V_19 = 96 ;
V_8 -> V_18 [ 0 ] -> V_20 &= V_21 ;
V_8 -> V_18 [ 0 ] -> V_20 |= V_22 ;
if ( ( V_8 -> V_18 [ 0 ] -> V_19 ) && V_8 -> V_18 [ 0 ] -> V_23 ) {
F_9 ( V_24 L_3 ) ;
if ( ! F_10 ( V_8 ) )
return 0 ;
} else {
F_9 ( V_24 L_4 ) ;
for ( V_16 = 0x2f0 ; V_16 > 0x100 ; V_16 -= 0x10 ) {
V_8 -> V_18 [ 0 ] -> V_23 = V_16 ;
if ( ! F_10 ( V_8 ) )
return 0 ;
}
}
return - V_25 ;
}
static int T_1 F_4 ( struct V_1 * V_2 )
{
int V_26 ;
T_4 V_27 ;
F_2 ( & V_2 -> V_4 , L_5 , V_2 ) ;
V_26 = F_11 ( V_2 , F_8 , NULL ) ;
if ( V_26 != 0 )
goto V_28;
if ( ! V_2 -> V_29 )
goto V_28;
V_26 = F_12 ( V_2 ) ;
if ( V_26 != 0 )
goto V_28;
V_27 . V_30 [ 0 ] = V_2 -> V_29 ;
V_27 . V_30 [ 1 ] = V_2 -> V_18 [ 0 ] -> V_23 ;
V_27 . V_31 = V_31 ;
V_27 . V_32 = V_33 ;
V_26 = F_13 ( V_2 , & ( ( ( T_2 * ) V_2 -> V_9 ) -> V_14 ) , & V_27 ) ;
if ( V_26 < 0 ) {
F_9 ( V_34 L_6 ,
V_26 , ( unsigned int ) V_2 -> V_18 [ 0 ] -> V_23 ) ;
F_6 ( V_2 ) ;
return - V_25 ;
}
( ( T_2 * ) V_2 -> V_9 ) -> V_7 = V_26 ;
return 0 ;
V_28:
F_6 ( V_2 ) ;
return - V_25 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 * V_3 = V_2 -> V_9 ;
F_2 ( & V_2 -> V_4 , L_7 , V_2 ) ;
if ( V_3 ) {
if ( V_3 -> V_7 >= 0 ) {
F_14 ( V_3 -> V_7 ) ;
}
}
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_9 ;
V_4 -> V_14 = 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_9 ;
V_4 -> V_14 = 0 ;
return 0 ;
}
static int T_5 F_18 ( void )
{
return F_19 ( & V_35 ) ;
}
static void T_6 F_20 ( void )
{
F_21 ( & V_35 ) ;
}
