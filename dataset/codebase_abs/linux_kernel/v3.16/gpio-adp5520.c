static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_2 , struct V_4 , V_1 ) ;
if ( F_3 ( V_3 , & V_5 -> V_7 ) )
F_4 ( V_5 -> V_8 , V_9 , & V_6 ) ;
else
F_4 ( V_5 -> V_8 , V_10 , & V_6 ) ;
return ! ! ( V_6 & V_5 -> V_11 [ V_3 ] ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_1 ) ;
if ( V_12 )
F_6 ( V_5 -> V_8 , V_9 , V_5 -> V_11 [ V_3 ] ) ;
else
F_7 ( V_5 -> V_8 , V_9 , V_5 -> V_11 [ V_3 ] ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_1 ) ;
F_9 ( V_3 , & V_5 -> V_7 ) ;
return F_7 ( V_5 -> V_8 , V_13 ,
V_5 -> V_11 [ V_3 ] ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
struct V_4 * V_5 ;
int V_14 = 0 ;
V_5 = F_2 ( V_2 , struct V_4 , V_1 ) ;
F_11 ( V_3 , & V_5 -> V_7 ) ;
if ( V_12 )
V_14 |= F_6 ( V_5 -> V_8 , V_9 ,
V_5 -> V_11 [ V_3 ] ) ;
else
V_14 |= F_7 ( V_5 -> V_8 , V_9 ,
V_5 -> V_11 [ V_3 ] ) ;
V_14 |= F_6 ( V_5 -> V_8 , V_13 ,
V_5 -> V_11 [ V_3 ] ) ;
return V_14 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_13 ( & V_16 -> V_5 ) ;
struct V_4 * V_5 ;
struct V_1 * V_19 ;
int V_14 , V_20 , V_21 ;
unsigned char V_22 = 0 ;
if ( V_18 == NULL ) {
F_14 ( & V_16 -> V_5 , L_1 ) ;
return - V_23 ;
}
if ( V_16 -> V_24 != V_25 ) {
F_14 ( & V_16 -> V_5 , L_2 ) ;
return - V_23 ;
}
V_5 = F_15 ( & V_16 -> V_5 , sizeof( * V_5 ) , V_26 ) ;
if ( V_5 == NULL )
return - V_27 ;
V_5 -> V_8 = V_16 -> V_5 . V_28 ;
for ( V_21 = 0 , V_20 = 0 ; V_20 < V_29 ; V_20 ++ )
if ( V_18 -> V_30 & ( 1 << V_20 ) )
V_5 -> V_11 [ V_21 ++ ] = 1 << V_20 ;
if ( V_21 < 1 ) {
V_14 = - V_31 ;
goto V_32;
}
V_19 = & V_5 -> V_1 ;
V_19 -> V_33 = F_8 ;
V_19 -> V_34 = F_10 ;
V_19 -> V_35 = F_1 ;
V_19 -> V_36 = F_5 ;
V_19 -> V_37 = true ;
V_19 -> V_38 = V_18 -> V_39 ;
V_19 -> V_40 = V_21 ;
V_19 -> V_41 = V_16 -> V_42 ;
V_19 -> V_43 = V_44 ;
V_14 = F_7 ( V_5 -> V_8 , V_45 ,
V_18 -> V_30 ) ;
if ( V_18 -> V_30 & V_46 )
V_22 |= V_47 ;
if ( V_18 -> V_30 & V_48 )
V_22 |= V_49 ;
if ( V_22 )
V_14 = F_6 ( V_5 -> V_8 , V_50 ,
V_22 ) ;
V_14 |= F_6 ( V_5 -> V_8 , V_51 ,
V_18 -> V_52 ) ;
if ( V_14 ) {
F_14 ( & V_16 -> V_5 , L_3 ) ;
goto V_32;
}
V_14 = F_16 ( & V_5 -> V_1 ) ;
if ( V_14 )
goto V_32;
F_17 ( V_16 , V_5 ) ;
return 0 ;
V_32:
return V_14 ;
}
static int F_18 ( struct V_15 * V_16 )
{
struct V_4 * V_5 ;
int V_14 ;
V_5 = F_19 ( V_16 ) ;
V_14 = F_20 ( & V_5 -> V_1 ) ;
if ( V_14 ) {
F_14 ( & V_16 -> V_5 , L_4 ,
L_5 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
