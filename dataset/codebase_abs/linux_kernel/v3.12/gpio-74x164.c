static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 = 0 ;
V_8 = F_4 ( V_4 -> V_11 * sizeof( struct V_7 ) ,
V_12 ) ;
if ( ! V_8 )
return - V_13 ;
F_5 ( & V_6 ) ;
for ( V_9 = V_4 -> V_11 - 1 ; V_9 >= 0 ; V_9 -- ) {
V_8 [ V_9 ] . V_14 = V_4 -> V_15 + V_9 ;
V_8 [ V_9 ] . V_16 = sizeof( V_17 ) ;
F_6 ( V_8 + V_9 , & V_6 ) ;
}
V_10 = F_7 ( V_4 -> V_18 , & V_6 ) ;
F_8 ( V_8 ) ;
return V_10 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_17 V_20 = V_19 / 8 ;
V_17 V_21 = V_19 % 8 ;
int V_10 ;
F_10 ( & V_4 -> V_22 ) ;
V_10 = ( V_4 -> V_15 [ V_20 ] >> V_21 ) & 0x1 ;
F_11 ( & V_4 -> V_22 ) ;
return V_10 ;
}
static void F_12 ( struct V_2 * V_3 ,
unsigned V_19 , int V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_17 V_20 = V_19 / 8 ;
V_17 V_21 = V_19 % 8 ;
F_10 ( & V_4 -> V_22 ) ;
if ( V_23 )
V_4 -> V_15 [ V_20 ] |= ( 1 << V_21 ) ;
else
V_4 -> V_15 [ V_20 ] &= ~ ( 1 << V_21 ) ;
F_3 ( V_4 ) ;
F_11 ( & V_4 -> V_22 ) ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned V_19 , int V_23 )
{
F_12 ( V_3 , V_19 , V_23 ) ;
return 0 ;
}
static int F_14 ( struct V_24 * V_18 )
{
struct V_1 * V_4 ;
struct V_25 * V_26 ;
int V_10 ;
if ( ! V_18 -> V_27 . V_28 ) {
F_15 ( & V_18 -> V_27 , L_1 ) ;
return - V_29 ;
}
V_18 -> V_30 = 8 ;
V_10 = F_16 ( V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = F_17 ( & V_18 -> V_27 , sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_26 = F_18 ( & V_18 -> V_27 ) ;
if ( V_26 && V_26 -> V_31 )
V_4 -> V_2 . V_31 = V_26 -> V_31 ;
else
V_4 -> V_2 . V_31 = - 1 ;
F_19 ( & V_4 -> V_22 ) ;
F_20 ( V_18 , V_4 ) ;
V_4 -> V_18 = V_18 ;
V_4 -> V_2 . V_32 = V_18 -> V_33 ;
V_4 -> V_2 . V_34 = F_13 ;
V_4 -> V_2 . V_35 = F_9 ;
V_4 -> V_2 . V_36 = F_12 ;
if ( F_21 ( V_18 -> V_27 . V_28 , L_2 , & V_4 -> V_11 ) ) {
F_15 ( & V_18 -> V_27 , L_3 ) ;
V_10 = - V_29 ;
goto V_37;
}
V_4 -> V_2 . V_38 = V_39 * V_4 -> V_11 ;
V_4 -> V_15 = F_17 ( & V_18 -> V_27 , V_4 -> V_11 , V_12 ) ;
if ( ! V_4 -> V_15 ) {
V_10 = - V_13 ;
goto V_37;
}
V_4 -> V_2 . V_40 = 1 ;
V_4 -> V_2 . V_27 = & V_18 -> V_27 ;
V_4 -> V_2 . V_41 = V_42 ;
V_10 = F_3 ( V_4 ) ;
if ( V_10 ) {
F_15 ( & V_18 -> V_27 , L_4 , V_10 ) ;
goto V_37;
}
V_10 = F_22 ( & V_4 -> V_2 ) ;
if ( V_10 )
goto V_37;
return V_10 ;
V_37:
F_20 ( V_18 , NULL ) ;
F_23 ( & V_4 -> V_22 ) ;
return V_10 ;
}
static int F_24 ( struct V_24 * V_18 )
{
struct V_1 * V_4 ;
int V_10 ;
V_4 = F_25 ( V_18 ) ;
if ( V_4 == NULL )
return - V_43 ;
F_20 ( V_18 , NULL ) ;
V_10 = F_26 ( & V_4 -> V_2 ) ;
if ( ! V_10 )
F_23 ( & V_4 -> V_22 ) ;
else
F_15 ( & V_18 -> V_27 , L_5 ,
V_10 ) ;
return V_10 ;
}
