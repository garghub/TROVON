static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
T_3 V_6 ;
int V_7 ;
V_6 = F_2 ( V_5 + V_8 ) ;
V_6 |= V_9 ;
F_3 ( V_6 , V_5 + V_8 ) ;
for ( V_7 = 0 ; V_7 < 20 ; V_7 ++ ) {
V_6 = F_2 ( V_5 + V_8 ) ;
if ( V_6 & V_10 )
break;
F_4 ( 10 , 100 ) ;
}
if ( F_5 ( V_7 == 5 ) )
return - V_11 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
T_3 V_6 ;
V_6 = F_2 ( V_5 + V_8 ) ;
V_6 &= ~ V_9 ;
F_3 ( V_6 , V_5 + V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_3 V_14 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_7 ;
T_3 V_15 ;
V_15 = ( V_12 << V_16 ) |
( V_13 << V_17 ) |
V_18 |
V_14 ;
F_3 ( V_15 , V_5 + V_19 ) ;
for ( V_7 = 0 ; V_7 < 5 ; ++ V_7 ) {
V_15 = F_2 ( V_5 + V_19 ) ;
if ( ! ( V_15 & V_18 ) )
break;
F_4 ( 10 , 100 ) ;
}
if ( F_5 ( V_7 == 5 ) )
return - V_11 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_1 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
V_21 = F_7 ( V_2 , V_12 , V_13 , 0 ) ;
if ( V_21 )
goto V_22;
* V_20 = F_2 ( V_5 + V_23 ) & 0xff ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_4 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
V_21 = F_7 ( V_2 , V_12 , V_13 , 0 ) ;
if ( V_21 )
goto V_22;
* V_20 = F_2 ( V_5 + V_23 ) & 0xffff ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_3 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
V_21 = F_7 ( V_2 , V_12 , V_13 , 0 ) ;
if ( V_21 )
goto V_22;
* V_20 = F_2 ( V_5 + V_23 ) ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_5 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
V_21 = F_7 ( V_2 , V_12 , V_13 , 0 ) ;
if ( V_21 )
goto V_22;
* V_20 = F_2 ( V_5 + V_23 ) ;
* V_20 += ( ( T_5 ) F_2 ( V_5 + V_24 ) & 0xffff ) << 32 ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_5 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
V_21 = F_7 ( V_2 , V_12 , V_13 , 0 ) ;
if ( V_21 )
goto V_22;
* V_20 = F_2 ( V_5 + V_23 ) ;
* V_20 += ( T_5 ) F_2 ( V_5 + V_24 ) << 32 ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 , T_1 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
F_3 ( V_25 , V_5 + V_26 ) ;
V_21 = F_7 ( V_2 , V_12 , V_13 , V_27 ) ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
T_4 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
F_3 ( V_25 , V_5 + V_26 ) ;
V_21 = F_7 ( V_2 , V_12 , V_13 , V_27 ) ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
T_3 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
F_3 ( V_25 , V_5 + V_26 ) ;
V_21 = F_7 ( V_2 , V_12 , V_13 , V_27 ) ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
T_5 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
F_3 ( ( T_3 ) V_25 , V_5 + V_26 ) ;
F_3 ( ( T_4 ) ( V_25 >> 32 ) , V_5 + V_28 ) ;
V_21 = F_7 ( V_2 , V_12 , V_13 , V_27 ) ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
T_5 V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 T_2 * V_5 = V_4 -> V_5 ;
int V_21 = 0 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
goto V_22;
F_3 ( ( T_3 ) V_25 , V_5 + V_26 ) ;
F_3 ( ( T_3 ) ( V_25 >> 32 ) , V_5 + V_28 ) ;
V_21 = F_7 ( V_2 , V_12 , V_13 , V_27 ) ;
V_22:
F_6 ( V_2 ) ;
return V_21 ;
}
static int F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_2 . V_33 ;
struct V_34 * V_35 = V_30 -> V_2 . V_36 ;
const struct V_37 * V_38 = NULL ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
if ( V_35 )
V_38 = F_19 ( V_41 , V_35 ) ;
if ( V_38 ) {
V_32 = F_20 ( & V_30 -> V_2 , sizeof( * V_32 ) , V_42 ) ;
if ( ! V_32 )
return - V_43 ;
V_32 -> V_44 = ( T_3 ) ( unsigned long ) V_38 -> V_45 ;
}
V_4 = F_20 ( & V_30 -> V_2 , sizeof( * V_4 ) , V_42 ) ;
if ( ! V_4 )
return - V_43 ;
V_40 = F_21 ( V_30 , V_46 , 0 ) ;
V_4 -> V_5 = F_22 ( & V_30 -> V_2 , V_40 ) ;
if ( F_23 ( V_4 -> V_5 ) )
return - V_43 ;
V_2 = F_24 ( & V_30 -> V_2 , & V_47 , V_4 ) ;
if ( ! V_2 )
return - V_43 ;
if ( V_32 )
V_2 -> V_32 = V_32 ;
F_25 ( V_30 , V_2 ) ;
return F_26 ( V_2 ) ;
}
static int F_27 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_28 ( V_30 ) ;
if ( V_2 )
F_29 ( V_2 ) ;
return 0 ;
}
