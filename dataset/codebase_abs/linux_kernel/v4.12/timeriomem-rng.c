static int F_1 ( struct V_1 * V_1 , void * V_2 ,
T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 =
F_2 ( V_1 , struct V_5 , V_7 ) ;
int V_8 = 0 ;
int V_9 = F_3 ( V_6 -> V_10 ) ;
if ( V_3 < sizeof( V_11 ) )
return 0 ;
if ( ! V_4 && ! V_6 -> V_12 )
return 0 ;
F_4 ( & V_6 -> V_13 ) ;
do {
if ( V_8 > 0 )
F_5 ( V_9 ,
V_9 + F_6 ( 1 , V_9 / 100 ) ) ;
* ( V_11 * ) V_2 = F_7 ( V_6 -> V_14 ) ;
V_8 += sizeof( V_11 ) ;
V_2 += sizeof( V_11 ) ;
V_3 -= sizeof( V_11 ) ;
} while ( V_4 && V_3 > sizeof( V_11 ) );
V_6 -> V_12 = 0 ;
F_8 ( & V_6 -> V_13 ) ;
F_9 ( & V_6 -> V_15 , V_6 -> V_10 ) ;
F_10 ( & V_6 -> V_15 ) ;
return V_8 ;
}
static enum F_10 F_11 ( struct V_16 * V_15 )
{
struct V_5 * V_6
= F_2 ( V_15 , struct V_5 , V_15 ) ;
V_6 -> V_12 = 1 ;
F_12 ( & V_6 -> V_13 ) ;
return V_17 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 . V_23 ;
struct V_5 * V_6 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
int V_10 ;
if ( ! V_19 -> V_22 . V_27 && ! V_21 ) {
F_14 ( & V_19 -> V_22 , L_1 ) ;
return - V_28 ;
}
V_25 = F_15 ( V_19 , V_29 , 0 ) ;
if ( ! V_25 )
return - V_30 ;
if ( V_25 -> V_31 % 4 != 0 || F_16 ( V_25 ) != 4 ) {
F_14 ( & V_19 -> V_22 ,
L_2 ) ;
return - V_28 ;
}
V_6 = F_17 ( & V_19 -> V_22 ,
sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
F_18 ( V_19 , V_6 ) ;
if ( V_19 -> V_22 . V_27 ) {
int V_34 ;
if ( ! F_19 ( V_19 -> V_22 . V_27 ,
L_3 , & V_34 ) )
V_10 = V_34 ;
else {
F_14 ( & V_19 -> V_22 , L_4 ) ;
return - V_28 ;
}
} else {
V_10 = V_21 -> V_10 ;
}
V_6 -> V_10 = F_20 ( V_10 * V_35 ) ;
F_21 ( & V_6 -> V_13 ) ;
F_22 ( & V_6 -> V_15 , V_36 , V_37 ) ;
V_6 -> V_15 . V_38 = F_11 ;
V_6 -> V_7 . V_39 = F_23 ( & V_19 -> V_22 ) ;
V_6 -> V_7 . V_40 = F_1 ;
V_6 -> V_14 = F_24 ( & V_19 -> V_22 , V_25 ) ;
if ( F_25 ( V_6 -> V_14 ) ) {
return F_26 ( V_6 -> V_14 ) ;
}
V_6 -> V_12 = 1 ;
F_12 ( & V_6 -> V_13 ) ;
V_26 = F_27 ( & V_6 -> V_7 ) ;
if ( V_26 ) {
F_14 ( & V_19 -> V_22 , L_5 ) ;
return V_26 ;
}
F_28 ( & V_19 -> V_22 , L_6 ,
V_6 -> V_14 , V_10 ) ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_30 ( V_19 ) ;
F_31 ( & V_6 -> V_7 ) ;
F_32 ( & V_6 -> V_15 ) ;
return 0 ;
}
