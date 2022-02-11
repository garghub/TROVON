static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( T_1 ) , V_5 ) ;
if ( ! V_3 ) return - V_6 ;
V_3 -> V_7 = - 1 ;
V_3 -> V_8 = V_2 ;
V_2 -> V_9 = V_3 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 , L_2 , V_2 ) ;
( ( T_1 * ) V_2 -> V_9 ) -> V_10 = 1 ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_9 ) ;
}
static int F_8 ( struct V_1 * V_8 , void * V_11 )
{
if ( V_8 -> V_12 == 0 )
return - V_13 ;
V_8 -> V_14 = 3 ;
return F_9 ( V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_15 ;
T_2 V_16 ;
F_2 ( & V_2 -> V_4 , L_3 , V_2 ) ;
V_2 -> V_17 |= V_18 | V_19 |
V_20 | V_21 | V_22 ;
V_15 = F_10 ( V_2 , F_8 , NULL ) ;
if ( V_15 )
goto V_23;
V_15 = F_11 ( V_2 ) ;
if ( V_15 )
goto V_23;
V_16 . V_24 [ 0 ] = V_2 -> V_25 ;
V_16 . V_24 [ 1 ] = V_2 -> V_26 [ 0 ] -> V_27 ;
V_16 . V_28 = V_28 ;
V_16 . V_29 = V_30 ;
V_15 = F_12 ( V_2 ,
& ( ( ( T_1 * ) V_2 -> V_9 ) -> V_10 ) , & V_16 ) ;
if ( V_15 < 0 ) {
F_13 ( V_31 L_4 ,
V_15 , V_2 -> V_26 [ 0 ] ) ;
F_6 ( V_2 ) ;
return - V_32 ;
} else
( ( T_1 * ) V_2 -> V_9 ) -> V_7 = V_15 ;
return 0 ;
V_23:
F_6 ( V_2 ) ;
return - V_32 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_9 ;
F_2 ( & V_2 -> V_4 , L_5 , V_2 ) ;
if ( V_3 ) {
if ( V_3 -> V_7 >= 0 ) {
F_14 ( V_3 -> V_7 ) ;
}
}
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_9 ;
V_4 -> V_10 = 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_9 ;
V_4 -> V_10 = 0 ;
return 0 ;
}
