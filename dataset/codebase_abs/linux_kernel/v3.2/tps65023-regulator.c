static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_6 ;
int V_7 ;
V_7 = F_5 ( V_2 -> V_5 , V_3 , & V_6 ) ;
if ( V_7 != 0 )
return V_7 ;
else
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
return F_7 ( V_2 -> V_5 , V_3 , V_6 ) ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_10 , V_11 = F_10 ( V_9 ) ;
T_1 V_12 ;
if ( V_11 < V_13 || V_11 > V_14 )
return - V_15 ;
V_12 = V_16 - V_11 ;
V_10 = F_4 ( V_2 , V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return ( V_10 & 1 << V_12 ) ? 1 : 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_10 , V_18 = F_10 ( V_9 ) ;
T_1 V_12 ;
if ( V_18 < V_19 || V_18 > V_20 )
return - V_15 ;
V_12 = ( V_18 == V_19 ? 1 : 2 ) ;
V_10 = F_4 ( V_2 , V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return ( V_10 & 1 << V_12 ) ? 1 : 0 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_10 ( V_9 ) ;
T_1 V_12 ;
if ( V_11 < V_13 || V_11 > V_14 )
return - V_15 ;
V_12 = V_16 - V_11 ;
return F_1 ( V_2 , V_17 , 1 << V_12 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_10 ( V_9 ) ;
T_1 V_12 ;
if ( V_11 < V_13 || V_11 > V_14 )
return - V_15 ;
V_12 = V_16 - V_11 ;
return F_3 ( V_2 , V_17 , 1 << V_12 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_18 = F_10 ( V_9 ) ;
T_1 V_12 ;
if ( V_18 < V_19 || V_18 > V_20 )
return - V_15 ;
V_12 = ( V_18 == V_19 ? 1 : 2 ) ;
return F_1 ( V_2 , V_17 , 1 << V_12 ) ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_18 = F_10 ( V_9 ) ;
T_1 V_12 ;
if ( V_18 < V_19 || V_18 > V_20 )
return - V_15 ;
V_12 = ( V_18 == V_19 ? 1 : 2 ) ;
return F_3 ( V_2 , V_17 , 1 << V_12 ) ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_10 , V_11 = F_10 ( V_9 ) ;
if ( V_11 < V_13 || V_11 > V_14 )
return - V_15 ;
if ( V_11 == V_2 -> V_21 ) {
V_10 = F_4 ( V_2 , V_22 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ( V_2 -> V_23 [ V_11 ] -> V_24 - 1 ) ;
return V_2 -> V_23 [ V_11 ] -> V_25 [ V_10 ] * 1000 ;
} else
return V_2 -> V_23 [ V_11 ] -> V_26 ;
}
static int F_17 ( struct V_8 * V_9 ,
int V_26 , int V_27 ,
unsigned * V_28 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_10 ( V_9 ) ;
int V_29 ;
int V_7 ;
if ( V_11 != V_2 -> V_21 )
return - V_15 ;
if ( V_26 < V_2 -> V_23 [ V_11 ] -> V_26
|| V_26 > V_2 -> V_23 [ V_11 ] -> V_27 )
return - V_15 ;
if ( V_27 < V_2 -> V_23 [ V_11 ] -> V_26
|| V_27 > V_2 -> V_23 [ V_11 ] -> V_27 )
return - V_15 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_23 [ V_11 ] -> V_24 ; V_29 ++ ) {
int V_30 = V_2 -> V_23 [ V_11 ] -> V_25 [ V_29 ] ;
int V_31 = V_30 * 1000 ;
if ( V_26 <= V_31 && V_31 <= V_27 )
break;
}
* V_28 = V_29 ;
if ( V_29 == V_2 -> V_23 [ V_11 ] -> V_24 )
goto V_32;
V_7 = F_6 ( V_2 , V_22 , V_29 ) ;
F_1 ( V_2 , V_33 ,
V_34 ) ;
return V_7 ;
V_32:
return - V_15 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_10 , V_18 = F_10 ( V_9 ) ;
if ( V_18 < V_19 || V_18 > V_20 )
return - V_15 ;
V_10 = F_4 ( V_2 , V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 >>= ( F_19 ( V_18 - V_19 ) ) ;
V_10 &= ( V_2 -> V_23 [ V_18 ] -> V_24 - 1 ) ;
return V_2 -> V_23 [ V_18 ] -> V_25 [ V_10 ] * 1000 ;
}
static int F_20 ( struct V_8 * V_9 ,
int V_26 , int V_27 , unsigned * V_28 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_10 , V_29 , V_18 = F_10 ( V_9 ) ;
if ( V_18 < V_19 || V_18 > V_20 )
return - V_15 ;
if ( V_26 < V_2 -> V_23 [ V_18 ] -> V_26 || V_26 > V_2 -> V_23 [ V_18 ] -> V_27 )
return - V_15 ;
if ( V_27 < V_2 -> V_23 [ V_18 ] -> V_26 || V_27 > V_2 -> V_23 [ V_18 ] -> V_27 )
return - V_15 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_23 [ V_18 ] -> V_24 ; V_29 ++ ) {
int V_30 = V_2 -> V_23 [ V_18 ] -> V_25 [ V_29 ] ;
int V_31 = V_30 * 1000 ;
if ( V_26 <= V_31 && V_31 <= V_27 )
break;
}
if ( V_29 == V_2 -> V_23 [ V_18 ] -> V_24 )
return - V_15 ;
* V_28 = V_29 ;
V_10 = F_4 ( V_2 , V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= F_21 ( V_18 - V_19 ) ;
V_10 |= ( V_29 << ( F_19 ( V_18 - V_19 ) ) ) ;
return F_6 ( V_2 , V_35 , V_10 ) ;
}
static int F_22 ( struct V_8 * V_9 ,
unsigned V_28 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_11 = F_10 ( V_9 ) ;
if ( V_11 < V_13 || V_11 > V_14 )
return - V_15 ;
if ( V_11 == V_2 -> V_21 ) {
if ( V_28 >= V_2 -> V_23 [ V_11 ] -> V_24 )
return - V_15 ;
else
return V_2 -> V_23 [ V_11 ] -> V_25 [ V_28 ] * 1000 ;
} else
return V_2 -> V_23 [ V_11 ] -> V_26 ;
}
static int F_23 ( struct V_8 * V_9 ,
unsigned V_28 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
int V_18 = F_10 ( V_9 ) ;
if ( V_18 < V_19 || V_18 > V_20 )
return - V_15 ;
if ( V_28 >= V_2 -> V_23 [ V_18 ] -> V_24 )
return - V_15 ;
else
return V_2 -> V_23 [ V_18 ] -> V_25 [ V_28 ] * 1000 ;
}
static int T_2 F_24 ( struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
const struct V_40 * V_41 = ( void * ) V_39 -> V_42 ;
const struct V_43 * V_23 = V_41 -> V_23 ;
struct V_44 * V_45 ;
struct V_8 * V_46 ;
struct V_1 * V_2 ;
int V_47 ;
int error ;
if ( ! F_25 ( V_37 -> V_48 , V_49 ) )
return - V_50 ;
V_45 = V_37 -> V_9 . V_51 ;
if ( ! V_45 )
return - V_50 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_5 = F_27 ( V_37 , & V_54 ) ;
if ( F_28 ( V_2 -> V_5 ) ) {
error = F_29 ( V_2 -> V_5 ) ;
F_30 ( & V_37 -> V_9 , L_1 ,
error ) ;
goto V_55;
}
V_2 -> V_37 = V_37 ;
V_2 -> V_21 = V_41 -> V_21 ;
for ( V_47 = 0 ; V_47 < V_16 ; V_47 ++ , V_23 ++ , V_45 ++ ) {
V_2 -> V_23 [ V_47 ] = V_23 ;
V_2 -> V_56 [ V_47 ] . V_57 = V_23 -> V_57 ;
V_2 -> V_56 [ V_47 ] . V_39 = V_47 ;
V_2 -> V_56 [ V_47 ] . V_58 = V_23 -> V_24 ;
V_2 -> V_56 [ V_47 ] . V_59 = ( V_47 > V_14 ?
& V_60 : & V_61 ) ;
V_2 -> V_56 [ V_47 ] . type = V_62 ;
V_2 -> V_56 [ V_47 ] . V_63 = V_64 ;
V_46 = F_31 ( & V_2 -> V_56 [ V_47 ] , & V_37 -> V_9 ,
V_45 , V_2 ) ;
if ( F_28 ( V_46 ) ) {
F_30 ( & V_37 -> V_9 , L_2 ,
V_39 -> V_57 ) ;
error = F_29 ( V_46 ) ;
goto V_65;
}
V_2 -> V_46 [ V_47 ] = V_46 ;
}
F_32 ( V_37 , V_2 ) ;
F_3 ( V_2 , V_33 ,
V_66 ) ;
F_3 ( V_2 , V_33 ,
V_66 ) ;
return 0 ;
V_65:
while ( -- V_47 >= 0 )
F_33 ( V_2 -> V_46 [ V_47 ] ) ;
F_34 ( V_2 -> V_5 ) ;
V_55:
F_35 ( V_2 ) ;
return error ;
}
static int T_3 F_36 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_37 ( V_37 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_16 ; V_47 ++ )
F_33 ( V_2 -> V_46 [ V_47 ] ) ;
F_34 ( V_2 -> V_5 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_67 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_67 ) ;
}
