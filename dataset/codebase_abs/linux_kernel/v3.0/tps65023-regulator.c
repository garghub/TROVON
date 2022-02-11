static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
return F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
int V_7 , V_8 ;
F_6 ( & V_2 -> V_9 ) ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_2 -> V_4 -> V_10 , L_1 , V_3 ) ;
V_7 = V_8 ;
goto V_11;
}
V_8 |= V_6 ;
V_7 = F_3 ( V_2 , V_3 , V_8 ) ;
if ( V_7 )
F_7 ( & V_2 -> V_4 -> V_10 , L_2 , V_3 ) ;
V_11:
F_8 ( & V_2 -> V_9 ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
int V_7 , V_8 ;
F_6 ( & V_2 -> V_9 ) ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_2 -> V_4 -> V_10 , L_1 , V_3 ) ;
V_7 = V_8 ;
goto V_11;
}
V_8 &= ~ V_6 ;
V_7 = F_3 ( V_2 , V_3 , V_8 ) ;
if ( V_7 )
F_7 ( & V_2 -> V_4 -> V_10 , L_2 , V_3 ) ;
V_11:
F_8 ( & V_2 -> V_9 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
F_6 ( & V_2 -> V_9 ) ;
V_8 = F_1 ( V_2 , V_3 ) ;
if ( V_8 < 0 )
F_7 ( & V_2 -> V_4 -> V_10 , L_1 , V_3 ) ;
F_8 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
int V_7 ;
F_6 ( & V_2 -> V_9 ) ;
V_7 = F_3 ( V_2 , V_3 , V_5 ) ;
if ( V_7 < 0 )
F_7 ( & V_2 -> V_4 -> V_10 , L_2 , V_3 ) ;
F_8 ( & V_2 -> V_9 ) ;
return V_7 ;
}
static int F_12 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_8 , V_13 = F_14 ( V_10 ) ;
T_1 V_14 ;
if ( V_13 < V_15 || V_13 > V_16 )
return - V_17 ;
V_14 = V_18 - V_13 ;
V_8 = F_10 ( V_2 , V_19 ) ;
if ( V_8 < 0 )
return V_8 ;
else
return ( V_8 & 1 << V_14 ) ? 1 : 0 ;
}
static int F_15 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_8 , V_20 = F_14 ( V_10 ) ;
T_1 V_14 ;
if ( V_20 < V_21 || V_20 > V_22 )
return - V_17 ;
V_14 = ( V_20 == V_21 ? 1 : 2 ) ;
V_8 = F_10 ( V_2 , V_19 ) ;
if ( V_8 < 0 )
return V_8 ;
else
return ( V_8 & 1 << V_14 ) ? 1 : 0 ;
}
static int F_16 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_13 = F_14 ( V_10 ) ;
T_1 V_14 ;
if ( V_13 < V_15 || V_13 > V_16 )
return - V_17 ;
V_14 = V_18 - V_13 ;
return F_5 ( V_2 , V_19 , 1 << V_14 ) ;
}
static int F_17 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_13 = F_14 ( V_10 ) ;
T_1 V_14 ;
if ( V_13 < V_15 || V_13 > V_16 )
return - V_17 ;
V_14 = V_18 - V_13 ;
return F_9 ( V_2 , V_19 , 1 << V_14 ) ;
}
static int F_18 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_20 = F_14 ( V_10 ) ;
T_1 V_14 ;
if ( V_20 < V_21 || V_20 > V_22 )
return - V_17 ;
V_14 = ( V_20 == V_21 ? 1 : 2 ) ;
return F_5 ( V_2 , V_19 , 1 << V_14 ) ;
}
static int F_19 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_20 = F_14 ( V_10 ) ;
T_1 V_14 ;
if ( V_20 < V_21 || V_20 > V_22 )
return - V_17 ;
V_14 = ( V_20 == V_21 ? 1 : 2 ) ;
return F_9 ( V_2 , V_19 , 1 << V_14 ) ;
}
static int F_20 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_8 , V_13 = F_14 ( V_10 ) ;
if ( V_13 < V_15 || V_13 > V_16 )
return - V_17 ;
if ( V_13 == V_15 ) {
V_8 = F_10 ( V_2 , V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 &= ( V_2 -> V_24 [ V_13 ] -> V_25 - 1 ) ;
return V_2 -> V_24 [ V_13 ] -> V_26 [ V_8 ] * 1000 ;
} else
return V_2 -> V_24 [ V_13 ] -> V_27 ;
}
static int F_21 ( struct V_12 * V_10 ,
int V_27 , int V_28 ,
unsigned * V_29 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_13 = F_14 ( V_10 ) ;
int V_30 ;
if ( V_13 != V_15 )
return - V_17 ;
if ( V_27 < V_2 -> V_24 [ V_13 ] -> V_27
|| V_27 > V_2 -> V_24 [ V_13 ] -> V_28 )
return - V_17 ;
if ( V_28 < V_2 -> V_24 [ V_13 ] -> V_27
|| V_28 > V_2 -> V_24 [ V_13 ] -> V_28 )
return - V_17 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_24 [ V_13 ] -> V_25 ; V_30 ++ ) {
int V_31 = V_2 -> V_24 [ V_13 ] -> V_26 [ V_30 ] ;
int V_32 = V_31 * 1000 ;
if ( V_27 <= V_32 && V_32 <= V_28 )
break;
}
* V_29 = V_30 ;
if ( V_30 == V_2 -> V_24 [ V_13 ] -> V_25 )
return - V_17 ;
else
return F_11 ( V_2 , V_23 , V_30 ) ;
}
static int F_22 ( struct V_12 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_8 , V_20 = F_14 ( V_10 ) ;
if ( V_20 < V_21 || V_20 > V_22 )
return - V_17 ;
V_8 = F_10 ( V_2 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 >>= ( F_23 ( V_20 - V_21 ) ) ;
V_8 &= ( V_2 -> V_24 [ V_20 ] -> V_25 - 1 ) ;
return V_2 -> V_24 [ V_20 ] -> V_26 [ V_8 ] * 1000 ;
}
static int F_24 ( struct V_12 * V_10 ,
int V_27 , int V_28 , unsigned * V_29 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_8 , V_30 , V_20 = F_14 ( V_10 ) ;
if ( V_20 < V_21 || V_20 > V_22 )
return - V_17 ;
if ( V_27 < V_2 -> V_24 [ V_20 ] -> V_27 || V_27 > V_2 -> V_24 [ V_20 ] -> V_28 )
return - V_17 ;
if ( V_28 < V_2 -> V_24 [ V_20 ] -> V_27 || V_28 > V_2 -> V_24 [ V_20 ] -> V_28 )
return - V_17 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_24 [ V_20 ] -> V_25 ; V_30 ++ ) {
int V_31 = V_2 -> V_24 [ V_20 ] -> V_26 [ V_30 ] ;
int V_32 = V_31 * 1000 ;
if ( V_27 <= V_32 && V_32 <= V_28 )
break;
}
if ( V_30 == V_2 -> V_24 [ V_20 ] -> V_25 )
return - V_17 ;
* V_29 = V_30 ;
V_8 = F_10 ( V_2 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 &= F_25 ( V_20 - V_21 ) ;
V_8 |= ( V_30 << ( F_23 ( V_20 - V_21 ) ) ) ;
return F_11 ( V_2 , V_33 , V_8 ) ;
}
static int F_26 ( struct V_12 * V_10 ,
unsigned V_29 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_13 = F_14 ( V_10 ) ;
if ( V_13 < V_15 || V_13 > V_16 )
return - V_17 ;
if ( V_13 == V_15 ) {
if ( V_29 >= V_2 -> V_24 [ V_13 ] -> V_25 )
return - V_17 ;
else
return V_2 -> V_24 [ V_13 ] -> V_26 [ V_29 ] * 1000 ;
} else
return V_2 -> V_24 [ V_13 ] -> V_27 ;
}
static int F_27 ( struct V_12 * V_10 ,
unsigned V_29 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
int V_20 = F_14 ( V_10 ) ;
if ( V_20 < V_21 || V_20 > V_22 )
return - V_17 ;
if ( V_29 >= V_2 -> V_24 [ V_20 ] -> V_25 )
return - V_17 ;
else
return V_2 -> V_24 [ V_20 ] -> V_26 [ V_29 ] * 1000 ;
}
static int T_2 F_28 ( struct V_34 * V_4 ,
const struct V_35 * V_36 )
{
const struct V_37 * V_24 = ( void * ) V_36 -> V_38 ;
struct V_39 * V_40 ;
struct V_12 * V_41 ;
struct V_1 * V_2 ;
int V_42 ;
int error ;
if ( ! F_29 ( V_4 -> V_43 , V_44 ) )
return - V_45 ;
V_40 = V_4 -> V_10 . V_46 ;
if ( ! V_40 )
return - V_45 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_31 ( & V_2 -> V_9 ) ;
V_2 -> V_4 = V_4 ;
for ( V_42 = 0 ; V_42 < V_18 ; V_42 ++ , V_24 ++ , V_40 ++ ) {
V_2 -> V_24 [ V_42 ] = V_24 ;
V_2 -> V_49 [ V_42 ] . V_50 = V_24 -> V_50 ;
V_2 -> V_49 [ V_42 ] . V_36 = V_42 ;
V_2 -> V_49 [ V_42 ] . V_51 = V_52 [ V_42 ] ;
V_2 -> V_49 [ V_42 ] . V_53 = ( V_42 > V_16 ?
& V_54 : & V_55 ) ;
V_2 -> V_49 [ V_42 ] . type = V_56 ;
V_2 -> V_49 [ V_42 ] . V_57 = V_58 ;
V_41 = F_32 ( & V_2 -> V_49 [ V_42 ] , & V_4 -> V_10 ,
V_40 , V_2 ) ;
if ( F_33 ( V_41 ) ) {
F_7 ( & V_4 -> V_10 , L_3 ,
V_36 -> V_50 ) ;
error = F_34 ( V_41 ) ;
goto V_59;
}
V_2 -> V_41 [ V_42 ] = V_41 ;
}
F_35 ( V_4 , V_2 ) ;
return 0 ;
V_59:
while ( -- V_42 >= 0 )
F_36 ( V_2 -> V_41 [ V_42 ] ) ;
F_37 ( V_2 ) ;
return error ;
}
static int T_3 F_38 ( struct V_34 * V_4 )
{
struct V_1 * V_2 = F_39 ( V_4 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_18 ; V_42 ++ )
F_36 ( V_2 -> V_41 [ V_42 ] ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_60 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_60 ) ;
}
