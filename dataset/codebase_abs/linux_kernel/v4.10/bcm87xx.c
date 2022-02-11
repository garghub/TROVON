static int F_1 ( struct V_1 * V_2 )
{
const T_1 * V_3 ;
const T_1 * V_4 ;
int V_5 , V_6 ;
if ( ! V_2 -> V_7 . V_8 . V_9 )
return 0 ;
V_3 = F_2 ( V_2 -> V_7 . V_8 . V_9 ,
L_1 , & V_5 ) ;
if ( ! V_3 )
return 0 ;
V_4 = V_3 + ( V_5 /= sizeof( * V_3 ) ) ;
V_6 = 0 ;
while ( V_3 + 3 < V_4 ) {
T_2 V_10 = F_3 ( V_3 ++ ) ;
T_2 V_11 = F_3 ( V_3 ++ ) ;
T_2 V_12 = F_3 ( V_3 ++ ) ;
T_2 V_13 = F_3 ( V_3 ++ ) ;
int V_14 ;
T_3 V_15 = V_16 | ( V_10 << 16 ) | V_11 ;
V_14 = 0 ;
if ( V_12 ) {
V_14 = F_4 ( V_2 , V_15 ) ;
if ( V_14 < 0 ) {
V_6 = V_14 ;
goto V_17;
}
V_14 &= V_12 ;
}
V_14 |= V_13 ;
V_6 = F_5 ( V_2 , V_15 , V_14 ) ;
if ( V_6 < 0 )
goto V_17;
}
V_17:
return V_6 ;
}
static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_18 = V_19 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return - V_26 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_27 ;
int V_28 ;
int V_29 ;
V_27 = F_4 ( V_2 , V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ( V_27 & 1 ) == 0 )
goto V_31;
V_28 = F_4 ( V_2 , V_32 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( ( V_28 & 1 ) == 0 )
goto V_31;
V_29 = F_4 ( V_2 , V_33 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ( V_29 & 0x1000 ) == 0 )
goto V_31;
V_2 -> V_34 = 10000 ;
V_2 -> V_35 = 1 ;
V_2 -> V_36 = 1 ;
return 0 ;
V_31:
V_2 -> V_35 = 0 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_11 , V_17 ;
V_11 = F_4 ( V_2 , V_37 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_2 -> V_38 == V_39 )
V_11 |= 1 ;
else
V_11 &= ~ 1 ;
V_17 = F_5 ( V_2 , V_37 , V_11 ) ;
return V_17 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_4 ( V_2 , V_40 ) ;
if ( V_11 < 0 ) {
F_11 ( V_2 ,
L_2 ,
V_11 ) ;
return 0 ;
}
return ( V_11 & 1 ) != 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return V_2 -> V_41 . V_42 [ 4 ] == V_43 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_41 . V_42 [ 4 ] == V_44 ;
}
