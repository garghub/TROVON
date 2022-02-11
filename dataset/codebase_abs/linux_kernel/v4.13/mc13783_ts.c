static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 , V_1 ) ;
F_3 ( & V_4 -> V_6 , 0 ) ;
return V_7 ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_10 , V_11 , V_12 , y0 , y1 , V_13 ;
int V_14 , V_15 ;
V_10 = V_4 -> V_16 [ 0 ] & 0xfff ;
V_11 = V_4 -> V_16 [ 1 ] & 0xfff ;
V_12 = V_4 -> V_16 [ 2 ] & 0xfff ;
y0 = V_4 -> V_16 [ 3 ] & 0xfff ;
y1 = ( V_4 -> V_16 [ 0 ] >> 12 ) & 0xfff ;
V_13 = ( V_4 -> V_16 [ 1 ] >> 12 ) & 0xfff ;
V_14 = ( V_4 -> V_16 [ 2 ] >> 12 ) & 0xfff ;
V_15 = ( V_4 -> V_16 [ 3 ] >> 12 ) & 0xfff ;
F_5 ( & V_9 -> V_17 ,
L_1 ,
V_10 , V_11 , V_12 , y0 , y1 , V_13 , V_14 , V_15 ) ;
F_6 ( V_10 , V_11 , V_12 ) ;
F_6 ( y0 , y1 , V_13 ) ;
V_14 = ( V_14 + V_15 ) / 2 ;
if ( ! V_14 || ! V_18 ||
( V_12 - V_10 < V_18 &&
V_13 - y0 < V_18 ) ) {
if ( V_14 ) {
F_7 ( V_9 , V_19 , V_11 ) ;
F_7 ( V_9 , V_20 , y1 ) ;
F_5 ( & V_9 -> V_17 , L_2 ,
V_11 , y1 , 0x1000 - V_14 ) ;
F_3 ( & V_4 -> V_6 , V_21 / 50 ) ;
} else {
F_5 ( & V_9 -> V_17 , L_3 ) ;
}
F_7 ( V_9 , V_22 ,
V_14 ? 0x1000 - V_14 : V_14 ) ;
F_8 ( V_9 , V_23 , V_14 ) ;
F_9 ( V_9 ) ;
} else {
F_5 ( & V_9 -> V_17 , L_4 ) ;
}
}
static void F_10 ( struct V_24 * V_6 )
{
struct V_3 * V_4 =
F_11 ( V_6 , struct V_3 , V_6 . V_6 ) ;
unsigned int V_25 = V_26 ;
unsigned int V_27 = 12 ;
if ( F_12 ( V_4 -> V_5 ,
V_25 , V_27 ,
V_4 -> V_28 -> V_29 , V_4 -> V_28 -> V_30 ,
V_4 -> V_16 ) == 0 )
F_4 ( V_4 ) ;
}
static int F_13 ( struct V_8 * V_17 )
{
struct V_3 * V_4 = F_14 ( V_17 ) ;
int V_31 ;
F_15 ( V_4 -> V_5 ) ;
F_2 ( V_4 -> V_5 , V_32 ) ;
V_31 = F_16 ( V_4 -> V_5 , V_32 ,
F_1 , V_33 , V_4 ) ;
if ( V_31 )
goto V_34;
V_31 = F_17 ( V_4 -> V_5 , V_35 ,
V_36 , V_37 ) ;
if ( V_31 )
F_18 ( V_4 -> V_5 , V_32 , V_4 ) ;
V_34:
F_19 ( V_4 -> V_5 ) ;
return V_31 ;
}
static void F_20 ( struct V_8 * V_17 )
{
struct V_3 * V_4 = F_14 ( V_17 ) ;
F_15 ( V_4 -> V_5 ) ;
F_17 ( V_4 -> V_5 , V_35 ,
V_36 , 0 ) ;
F_18 ( V_4 -> V_5 , V_32 , V_4 ) ;
F_19 ( V_4 -> V_5 ) ;
F_21 ( & V_4 -> V_6 ) ;
}
static int T_2 F_22 ( struct V_38 * V_39 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
int V_31 = - V_40 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_41 ) ;
V_9 = F_24 () ;
if ( ! V_4 || ! V_9 )
goto V_42;
F_25 ( & V_4 -> V_6 , F_10 ) ;
V_4 -> V_5 = F_26 ( V_39 -> V_17 . V_43 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_28 = F_27 ( & V_39 -> V_17 ) ;
if ( ! V_4 -> V_28 ) {
F_28 ( & V_39 -> V_17 , L_5 ) ;
V_31 = - V_44 ;
goto V_42;
}
V_9 -> V_45 = V_33 ;
V_9 -> V_17 . V_43 = & V_39 -> V_17 ;
V_9 -> V_46 [ 0 ] = F_29 ( V_47 ) | F_29 ( V_48 ) ;
V_9 -> V_49 [ F_30 ( V_23 ) ] = F_29 ( V_23 ) ;
F_31 ( V_9 , V_19 , 0 , 0xfff , 0 , 0 ) ;
F_31 ( V_9 , V_20 , 0 , 0xfff , 0 , 0 ) ;
F_31 ( V_9 , V_22 , 0 , 0xfff , 0 , 0 ) ;
V_9 -> V_50 = F_13 ;
V_9 -> V_51 = F_20 ;
F_32 ( V_9 , V_4 ) ;
V_31 = F_33 ( V_4 -> V_9 ) ;
if ( V_31 ) {
F_28 ( & V_39 -> V_17 ,
L_6 , V_31 ) ;
goto V_42;
}
F_34 ( V_39 , V_4 ) ;
return 0 ;
V_42:
F_35 ( V_9 ) ;
F_36 ( V_4 ) ;
return V_31 ;
}
static int F_37 ( struct V_38 * V_39 )
{
struct V_3 * V_4 = F_38 ( V_39 ) ;
F_39 ( V_4 -> V_9 ) ;
F_36 ( V_4 ) ;
return 0 ;
}
