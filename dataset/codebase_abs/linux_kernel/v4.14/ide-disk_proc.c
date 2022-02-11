static int F_1 ( T_1 * V_1 )
{
struct V_2 V_3 ;
struct V_4 * V_5 = & V_3 . V_5 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_5 -> V_6 = V_7 ;
V_5 -> V_8 = V_9 ;
V_5 -> V_10 = V_11 ;
V_5 -> V_12 = V_13 ;
V_3 . V_14 . V_15 . V_5 = V_16 | V_17 ;
V_3 . V_14 . V_18 . V_5 = V_19 | V_17 ;
return F_2 ( V_1 , & V_3 ) ;
}
static int F_3 ( T_1 * V_1 , T_2 * V_20 , T_2 V_21 )
{
struct V_2 V_3 ;
struct V_4 * V_5 = & V_3 . V_5 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_5 -> V_6 = V_21 ;
V_5 -> V_22 = 0x01 ;
V_5 -> V_8 = V_9 ;
V_5 -> V_10 = V_11 ;
V_5 -> V_12 = V_13 ;
V_3 . V_14 . V_15 . V_5 = V_16 | V_17 ;
V_3 . V_14 . V_18 . V_5 = V_19 | V_17 ;
V_3 . V_23 = V_24 ;
return F_4 ( V_1 , & V_3 , V_20 , 1 ) ;
}
static int F_5 ( struct V_25 * V_26 , void * V_27 )
{
T_1 * V_1 = ( T_1 * ) V_26 -> V_28 ;
if ( V_1 -> V_29 & V_30 )
F_6 ( V_26 , L_1 , V_1 -> V_31 [ V_32 ] / 2 ) ;
else
F_6 ( V_26 , L_2 ) ;
return 0 ;
}
static int F_7 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
return F_8 ( V_34 , F_5 , F_9 ( V_33 ) ) ;
}
static int F_10 ( struct V_25 * V_26 , void * V_27 )
{
T_1 * V_1 = ( T_1 * ) V_26 -> V_28 ;
F_6 ( V_26 , L_3 , ( long long ) F_11 ( V_1 ) ) ;
return 0 ;
}
static int F_12 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
return F_8 ( V_34 , F_10 , F_9 ( V_33 ) ) ;
}
static int F_13 ( struct V_25 * V_26 , T_1 * V_1 , T_2 V_21 )
{
T_2 * V_20 ;
V_20 = F_14 ( V_35 , V_36 ) ;
if ( ! V_20 )
return - V_37 ;
( void ) F_1 ( V_1 ) ;
if ( F_3 ( V_1 , V_20 , V_21 ) == 0 ) {
T_3 * V_38 = ( T_3 * ) V_20 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_35 / 2 ; V_39 ++ ) {
F_6 ( V_26 , L_4 , F_15 ( V_38 [ V_39 ] ) ,
( V_39 % 8 ) == 7 ? '\n' : ' ' ) ;
}
}
F_16 ( V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_25 * V_26 , void * V_27 )
{
return F_13 ( V_26 , V_26 -> V_28 , V_40 ) ;
}
static int F_18 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
return F_8 ( V_34 , F_17 , F_9 ( V_33 ) ) ;
}
static int F_19 ( struct V_25 * V_26 , void * V_27 )
{
return F_13 ( V_26 , V_26 -> V_28 , V_41 ) ;
}
static int F_20 ( struct V_33 * V_33 , struct V_34 * V_34 )
{
return F_8 ( V_34 , F_19 , F_9 ( V_33 ) ) ;
}
