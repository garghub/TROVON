static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( T_1 ) , V_5 ) ;
if ( ! V_3 ) return - V_6 ;
V_3 -> V_7 = V_2 ;
V_2 -> V_8 = V_3 ;
V_3 -> V_9 = - 1 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 * V_10 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_4 , L_2 , V_2 ) ;
V_10 -> V_11 = 1 ;
F_6 ( V_2 ) ;
F_7 ( V_10 ) ;
}
static int F_8 ( struct V_1 * V_7 , void * V_12 )
{
int V_13 ;
V_7 -> V_14 = 3 ;
V_7 -> V_15 [ 0 ] -> V_16 = 8 ;
V_7 -> V_15 [ 0 ] -> V_17 &= V_18 ;
V_7 -> V_15 [ 0 ] -> V_17 |= V_19 ;
if ( ( V_7 -> V_15 [ 0 ] -> V_16 ) && V_7 -> V_15 [ 0 ] -> V_20 ) {
F_9 ( V_21 L_3 ) ;
if ( ! F_10 ( V_7 ) )
return 0 ;
} else {
F_9 ( V_21 L_4 ) ;
for ( V_13 = 0x2f0 ; V_13 > 0x100 ; V_13 -= 0x10 ) {
V_7 -> V_15 [ 0 ] -> V_20 = V_13 ;
if ( ! F_10 ( V_7 ) )
return 0 ;
}
}
return - V_22 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_23 ;
T_2 V_24 ;
F_2 ( & V_2 -> V_4 , L_5 , V_2 ) ;
V_2 -> V_25 |= V_26 | V_27 ;
V_23 = F_11 ( V_2 , F_8 , NULL ) ;
if ( V_23 != 0 )
goto V_28;
if ( ! V_2 -> V_29 )
goto V_28;
V_23 = F_12 ( V_2 ) ;
if ( V_23 != 0 )
goto V_28;
V_24 . V_30 [ 0 ] = V_2 -> V_29 ;
V_24 . V_30 [ 1 ] = V_2 -> V_15 [ 0 ] -> V_20 ;
V_24 . V_31 = V_31 ;
V_24 . V_32 = V_33 ;
V_23 = F_13 ( V_2 , & ( ( ( T_1 * ) V_2 -> V_8 ) -> V_11 ) , & V_24 ) ;
if ( V_23 < 0 ) {
F_9 ( V_34 L_6
L_7 , V_23 , V_2 -> V_15 [ 0 ] ) ;
F_6 ( V_2 ) ;
} else
( ( T_1 * ) V_2 -> V_8 ) -> V_9 = V_23 ;
return 0 ;
V_28:
F_6 ( V_2 ) ;
return - V_22 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_4 , L_8 , V_2 ) ;
if ( V_3 ) {
if ( V_3 -> V_9 >= 0 ) {
F_14 ( V_3 -> V_9 ) ;
}
}
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_8 ;
V_4 -> V_11 = 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_8 ;
V_4 -> V_11 = 0 ;
return 0 ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_35 ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_35 ) ;
}
