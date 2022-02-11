static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 = F_3 ( V_2 ) ;
int V_7 ;
T_1 V_8 ;
if ( V_6 < V_9 || V_6 > V_10 )
return - V_11 ;
V_8 = V_12 - V_6 ;
V_7 = F_4 ( V_4 -> V_13 , V_14 , & V_5 ) ;
if ( V_7 != 0 )
return V_7 ;
else
return ( V_5 & 1 << V_8 ) ? 1 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 = F_3 ( V_2 ) ;
int V_7 ;
T_1 V_8 ;
if ( V_15 < V_16 || V_15 > V_17 )
return - V_11 ;
V_8 = ( V_15 == V_16 ? 1 : 2 ) ;
V_7 = F_4 ( V_4 -> V_13 , V_14 , & V_5 ) ;
if ( V_7 != 0 )
return V_7 ;
else
return ( V_5 & 1 << V_8 ) ? 1 : 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 = F_3 ( V_2 ) ;
T_1 V_8 ;
if ( V_6 < V_9 || V_6 > V_10 )
return - V_11 ;
V_8 = V_12 - V_6 ;
return F_7 ( V_4 -> V_13 , V_14 , 1 << V_8 , 1 << V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 = F_3 ( V_2 ) ;
T_1 V_8 ;
if ( V_6 < V_9 || V_6 > V_10 )
return - V_11 ;
V_8 = V_12 - V_6 ;
return F_7 ( V_4 -> V_13 , V_14 , 1 << V_8 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_3 ( V_2 ) ;
T_1 V_8 ;
if ( V_15 < V_16 || V_15 > V_17 )
return - V_11 ;
V_8 = ( V_15 == V_16 ? 1 : 2 ) ;
return F_7 ( V_4 -> V_13 , V_14 , 1 << V_8 , 1 << V_8 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_3 ( V_2 ) ;
T_1 V_8 ;
if ( V_15 < V_16 || V_15 > V_17 )
return - V_11 ;
V_8 = ( V_15 == V_16 ? 1 : 2 ) ;
return F_7 ( V_4 -> V_13 , V_14 , 1 << V_8 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
int V_5 , V_6 = F_3 ( V_2 ) ;
if ( V_6 < V_9 || V_6 > V_10 )
return - V_11 ;
if ( V_6 == V_4 -> V_18 ) {
V_7 = F_4 ( V_4 -> V_13 , V_19 , & V_5 ) ;
if ( V_7 != 0 )
return V_7 ;
V_5 &= ( V_4 -> V_20 [ V_6 ] -> V_21 - 1 ) ;
return V_4 -> V_20 [ V_6 ] -> V_22 [ V_5 ] * 1000 ;
} else
return V_4 -> V_20 [ V_6 ] -> V_23 ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_23 , int V_24 ,
unsigned * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 = F_3 ( V_2 ) ;
int V_26 ;
int V_7 ;
if ( V_6 != V_4 -> V_18 )
return - V_11 ;
if ( V_23 < V_4 -> V_20 [ V_6 ] -> V_23
|| V_23 > V_4 -> V_20 [ V_6 ] -> V_24 )
return - V_11 ;
if ( V_24 < V_4 -> V_20 [ V_6 ] -> V_23
|| V_24 > V_4 -> V_20 [ V_6 ] -> V_24 )
return - V_11 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_20 [ V_6 ] -> V_21 ; V_26 ++ ) {
int V_27 = V_4 -> V_20 [ V_6 ] -> V_22 [ V_26 ] ;
int V_28 = V_27 * 1000 ;
if ( V_23 <= V_28 && V_28 <= V_24 )
break;
}
* V_25 = V_26 ;
if ( V_26 == V_4 -> V_20 [ V_6 ] -> V_21 )
goto V_29;
V_7 = F_13 ( V_4 -> V_13 , V_19 , V_26 ) ;
F_7 ( V_4 -> V_13 , V_30 ,
V_31 , V_31 ) ;
return V_7 ;
V_29:
return - V_11 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 = F_3 ( V_2 ) ;
int V_7 ;
if ( V_15 < V_16 || V_15 > V_17 )
return - V_11 ;
V_7 = F_4 ( V_4 -> V_13 , V_32 , & V_5 ) ;
if ( V_7 != 0 )
return V_7 ;
V_5 >>= ( F_15 ( V_15 - V_16 ) ) ;
V_5 &= ( V_4 -> V_20 [ V_15 ] -> V_21 - 1 ) ;
return V_4 -> V_20 [ V_15 ] -> V_22 [ V_5 ] * 1000 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_23 , int V_24 , unsigned * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_26 , V_15 = F_3 ( V_2 ) ;
int V_7 ;
if ( V_15 < V_16 || V_15 > V_17 )
return - V_11 ;
if ( V_23 < V_4 -> V_20 [ V_15 ] -> V_23 || V_23 > V_4 -> V_20 [ V_15 ] -> V_24 )
return - V_11 ;
if ( V_24 < V_4 -> V_20 [ V_15 ] -> V_23 || V_24 > V_4 -> V_20 [ V_15 ] -> V_24 )
return - V_11 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_20 [ V_15 ] -> V_21 ; V_26 ++ ) {
int V_27 = V_4 -> V_20 [ V_15 ] -> V_22 [ V_26 ] ;
int V_28 = V_27 * 1000 ;
if ( V_23 <= V_28 && V_28 <= V_24 )
break;
}
if ( V_26 == V_4 -> V_20 [ V_15 ] -> V_21 )
return - V_11 ;
* V_25 = V_26 ;
V_7 = F_4 ( V_4 -> V_13 , V_32 , & V_5 ) ;
if ( V_7 != 0 )
return V_7 ;
V_5 &= F_17 ( V_15 - V_16 ) ;
V_5 |= ( V_26 << ( F_15 ( V_15 - V_16 ) ) ) ;
return F_13 ( V_4 -> V_13 , V_32 , V_5 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 = F_3 ( V_2 ) ;
if ( V_6 < V_9 || V_6 > V_10 )
return - V_11 ;
if ( V_6 == V_4 -> V_18 ) {
if ( V_25 >= V_4 -> V_20 [ V_6 ] -> V_21 )
return - V_11 ;
else
return V_4 -> V_20 [ V_6 ] -> V_22 [ V_25 ] * 1000 ;
} else
return V_4 -> V_20 [ V_6 ] -> V_23 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 = F_3 ( V_2 ) ;
if ( V_15 < V_16 || V_15 > V_17 )
return - V_11 ;
if ( V_25 >= V_4 -> V_20 [ V_15 ] -> V_21 )
return - V_11 ;
else
return V_4 -> V_20 [ V_15 ] -> V_22 [ V_25 ] * 1000 ;
}
static int T_2 F_20 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
const struct V_37 * V_38 = ( void * ) V_36 -> V_39 ;
const struct V_40 * V_20 = V_38 -> V_20 ;
struct V_41 * V_42 ;
struct V_1 * V_43 ;
struct V_3 * V_4 ;
int V_44 ;
int error ;
if ( ! F_21 ( V_34 -> V_45 , V_46 ) )
return - V_47 ;
V_42 = V_34 -> V_2 . V_48 ;
if ( ! V_42 )
return - V_47 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_13 = F_23 ( V_34 , & V_51 ) ;
if ( F_24 ( V_4 -> V_13 ) ) {
error = F_25 ( V_4 -> V_13 ) ;
F_26 ( & V_34 -> V_2 , L_1 ,
error ) ;
goto V_52;
}
V_4 -> V_34 = V_34 ;
V_4 -> V_18 = V_38 -> V_18 ;
for ( V_44 = 0 ; V_44 < V_12 ; V_44 ++ , V_20 ++ , V_42 ++ ) {
V_4 -> V_20 [ V_44 ] = V_20 ;
V_4 -> V_53 [ V_44 ] . V_54 = V_20 -> V_54 ;
V_4 -> V_53 [ V_44 ] . V_36 = V_44 ;
V_4 -> V_53 [ V_44 ] . V_55 = V_20 -> V_21 ;
V_4 -> V_53 [ V_44 ] . V_56 = ( V_44 > V_10 ?
& V_57 : & V_58 ) ;
V_4 -> V_53 [ V_44 ] . type = V_59 ;
V_4 -> V_53 [ V_44 ] . V_60 = V_61 ;
V_43 = F_27 ( & V_4 -> V_53 [ V_44 ] , & V_34 -> V_2 ,
V_42 , V_4 , NULL ) ;
if ( F_24 ( V_43 ) ) {
F_26 ( & V_34 -> V_2 , L_2 ,
V_36 -> V_54 ) ;
error = F_25 ( V_43 ) ;
goto V_62;
}
V_4 -> V_43 [ V_44 ] = V_43 ;
}
F_28 ( V_34 , V_4 ) ;
F_7 ( V_4 -> V_13 , V_30 ,
V_63 , V_63 ) ;
return 0 ;
V_62:
while ( -- V_44 >= 0 )
F_29 ( V_4 -> V_43 [ V_44 ] ) ;
F_30 ( V_4 -> V_13 ) ;
V_52:
F_31 ( V_4 ) ;
return error ;
}
static int T_3 F_32 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = F_33 ( V_34 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_12 ; V_44 ++ )
F_29 ( V_4 -> V_43 [ V_44 ] ) ;
F_30 ( V_4 -> V_13 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_64 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_64 ) ;
}
