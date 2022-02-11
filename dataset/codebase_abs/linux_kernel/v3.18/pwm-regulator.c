static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
V_7 = F_4 ( V_4 -> V_10 ) ;
V_8 = ( V_7 *
V_4 -> V_11 [ V_6 ] . V_8 ) / 100 ;
V_9 = F_5 ( V_4 -> V_10 , V_8 , V_7 ) ;
if ( V_9 ) {
F_6 ( & V_2 -> V_2 , L_1 ) ;
return V_9 ;
}
V_4 -> V_5 = V_6 ;
if ( ! V_4 -> V_12 ) {
V_9 = F_7 ( V_4 -> V_10 ) ;
if ( V_9 ) {
F_6 ( & V_2 -> V_2 , L_2 ) ;
return V_9 ;
}
V_4 -> V_12 = true ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_4 -> V_13 . V_14 )
return - V_15 ;
return V_4 -> V_11 [ V_6 ] . V_16 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 ;
struct V_1 * V_21 ;
struct V_22 V_23 = { } ;
struct V_24 * V_25 = V_18 -> V_2 . V_26 ;
int V_27 , V_9 ;
if ( ! V_25 ) {
F_6 ( & V_18 -> V_2 , L_3 ) ;
return - V_15 ;
}
V_4 = F_10 ( & V_18 -> V_2 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_29 ;
memcpy ( & V_4 -> V_13 , & V_30 , sizeof( V_30 ) ) ;
V_20 = F_11 ( V_25 , L_4 , & V_27 ) ;
if ( ! V_20 ) {
F_6 ( & V_18 -> V_2 , L_5 ) ;
return - V_15 ;
}
if ( ( V_27 < sizeof( * V_4 -> V_11 ) ) ||
( V_27 % sizeof( * V_4 -> V_11 ) ) ) {
F_6 ( & V_18 -> V_2 , L_6 ,
V_27 ) ;
return - V_15 ;
}
V_4 -> V_13 . V_14 = V_27 / sizeof( * V_4 -> V_11 ) ;
V_4 -> V_11 = F_10 ( & V_18 -> V_2 ,
V_27 , V_28 ) ;
if ( ! V_4 -> V_11 )
return - V_29 ;
V_9 = F_12 ( V_25 , L_4 ,
( V_31 * ) V_4 -> V_11 ,
V_27 / sizeof( V_31 ) ) ;
if ( V_9 < 0 ) {
F_6 ( & V_18 -> V_2 , L_7 ) ;
return V_9 ;
}
V_23 . V_32 = F_13 ( & V_18 -> V_2 , V_25 ) ;
if ( ! V_23 . V_32 )
return - V_29 ;
V_23 . V_26 = V_25 ;
V_23 . V_2 = & V_18 -> V_2 ;
V_23 . V_33 = V_4 ;
V_4 -> V_10 = F_14 ( & V_18 -> V_2 , NULL ) ;
if ( F_15 ( V_4 -> V_10 ) ) {
F_6 ( & V_18 -> V_2 , L_8 ) ;
return F_16 ( V_4 -> V_10 ) ;
}
V_21 = F_17 ( & V_18 -> V_2 ,
& V_4 -> V_13 , & V_23 ) ;
if ( F_15 ( V_21 ) ) {
F_6 ( & V_18 -> V_2 , L_9 ,
V_4 -> V_13 . V_34 ) ;
return F_16 ( V_21 ) ;
}
return 0 ;
}
