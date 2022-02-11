static int F_1 ( struct V_1 * V_2 )
{
const T_1 * V_3 ;
const T_1 * V_4 ;
int V_5 , V_6 ;
if ( ! V_2 -> V_7 . V_8 )
return 0 ;
V_3 = F_2 ( V_2 -> V_7 . V_8 ,
L_1 , & V_5 ) ;
if ( ! V_3 )
return 0 ;
V_4 = V_3 + ( V_5 /= sizeof( * V_3 ) ) ;
V_6 = 0 ;
while ( V_3 + 3 < V_4 ) {
T_2 V_9 = F_3 ( V_3 ++ ) ;
T_2 V_10 = F_3 ( V_3 ++ ) ;
T_2 V_11 = F_3 ( V_3 ++ ) ;
T_2 V_12 = F_3 ( V_3 ++ ) ;
int V_13 ;
T_3 V_14 = V_15 | ( V_9 << 16 ) | V_10 ;
V_13 = 0 ;
if ( V_11 ) {
V_13 = F_4 ( V_2 , V_14 ) ;
if ( V_13 < 0 ) {
V_6 = V_13 ;
goto V_16;
}
V_13 &= V_11 ;
}
V_13 |= V_12 ;
V_6 = F_5 ( V_2 , V_14 , V_13 ) ;
if ( V_6 < 0 )
goto V_16;
}
V_16:
return V_6 ;
}
static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = V_24 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return - V_25 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_26 ;
int V_27 ;
int V_28 ;
V_26 = F_4 ( V_2 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ( V_26 & 1 ) == 0 )
goto V_30;
V_27 = F_4 ( V_2 , V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ( V_27 & 1 ) == 0 )
goto V_30;
V_28 = F_4 ( V_2 , V_32 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 & 0x1000 ) == 0 )
goto V_30;
V_2 -> V_33 = 10000 ;
V_2 -> V_34 = 1 ;
V_2 -> V_35 = 1 ;
return 0 ;
V_30:
V_2 -> V_34 = 0 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_10 , V_16 ;
V_10 = F_4 ( V_2 , V_36 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_2 -> V_37 == V_38 )
V_10 |= 1 ;
else
V_10 &= ~ 1 ;
V_16 = F_5 ( V_2 , V_36 , V_10 ) ;
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_4 ( V_2 , V_39 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_2 -> V_7 ,
L_2 , V_10 ) ;
return 0 ;
}
return ( V_10 & 1 ) != 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return V_2 -> V_40 . V_41 [ 4 ] == V_42 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_40 . V_41 [ 4 ] == V_43 ;
}
