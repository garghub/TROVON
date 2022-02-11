static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
int V_3 ;
if ( V_2 ) {
V_3 = F_2 ( V_1 , V_4 ,
V_5 ,
V_5 ) ;
if ( V_3 != 0 )
F_3 ( V_1 , L_1 , V_3 ) ;
} else {
V_3 = F_2 ( V_1 , V_4 ,
V_5 , 0 ) ;
if ( V_3 != 0 )
F_3 ( V_1 , L_2 , V_3 ) ;
}
return V_3 ;
}
static T_1 F_4 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
int V_3 ;
V_3 = F_5 ( V_9 -> V_1 , V_10 ) ;
if ( V_3 < 0 ) {
F_3 ( V_9 -> V_1 , L_3 , V_3 ) ;
return V_11 ;
}
if ( V_3 & V_12 ) {
F_1 ( V_9 -> V_1 , 0 ) ;
F_6 ( V_9 -> V_9 , 1 , V_13 | V_14 ) ;
} else
F_6 ( V_9 -> V_9 , 1 , V_13 | V_15 ) ;
return V_16 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
int V_3 ;
T_2 V_19 [ 5 ] ;
V_3 = F_8 ( V_1 , V_10 , 5 , V_19 ) ;
if ( V_3 != 0 ) {
F_3 ( V_1 , L_4 , V_3 ) ;
return V_3 ;
}
V_18 -> V_20 = ( V_19 [ 4 ] & V_21 ) + 100 ;
V_18 -> V_22 = ( V_19 [ 3 ] & V_23 ) - 1 ;
V_18 -> V_24 = V_19 [ 2 ] & V_25 ;
V_18 -> V_26 = V_19 [ 1 ] & V_27 ;
V_18 -> V_28 = V_19 [ 0 ] & V_29 ;
V_3 = F_9 ( V_18 ) ;
if ( V_3 != 0 )
return V_3 ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
int V_3 ;
T_2 V_19 [ 3 ] ;
V_18 -> V_20 -= 100 ;
V_18 -> V_22 += 1 ;
V_3 = F_2 ( V_1 , V_10 ,
V_29 , V_18 -> V_28 ) ;
if ( V_3 != 0 ) {
F_3 ( V_1 , L_5 , V_3 ) ;
return V_3 ;
}
V_19 [ 0 ] = V_18 -> V_26 ;
V_19 [ 1 ] = V_18 -> V_24 ;
V_19 [ 2 ] = V_18 -> V_22 ;
V_3 = F_11 ( V_1 , V_30 , 3 , V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_4 ,
V_21 , V_18 -> V_20 ) ;
if ( V_3 != 0 )
F_3 ( V_1 , L_6 , V_3 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_5 ( V_1 , V_4 ) ;
if ( V_3 < 0 ) {
F_3 ( V_1 , L_7 , V_3 ) ;
return V_3 ;
}
V_3 &= V_5 ;
return ( V_3 > 0 ) ? 1 : 0 ;
}
static int F_13 ( struct V_31 * V_32 , struct V_17 * V_18 )
{
struct V_8 * V_9 = F_14 ( V_32 ) ;
T_2 V_19 [ 6 ] ;
int V_3 ;
V_3 = F_8 ( V_9 -> V_1 , V_33 , 6 , V_19 ) ;
if ( V_3 < 0 ) {
F_3 ( V_9 -> V_1 , L_8 , V_3 ) ;
return V_3 ;
}
V_18 -> V_20 = ( V_19 [ 5 ] & V_21 ) + 100 ;
V_18 -> V_22 = ( V_19 [ 4 ] & V_23 ) - 1 ;
V_18 -> V_24 = V_19 [ 3 ] & V_25 ;
V_18 -> V_26 = V_19 [ 2 ] & V_27 ;
V_18 -> V_28 = V_19 [ 1 ] & V_29 ;
V_18 -> V_34 = V_19 [ 0 ] & V_35 ;
V_3 = F_9 ( V_18 ) ;
if ( V_3 != 0 ) {
F_3 ( V_9 -> V_1 , L_9 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static int F_15 ( struct V_31 * V_32 , struct V_17 * V_36 )
{
struct V_8 * V_9 ;
T_2 V_19 [ 6 ] ;
V_9 = F_14 ( V_32 ) ;
V_19 [ 0 ] = V_36 -> V_34 ;
V_19 [ 1 ] = V_36 -> V_28 ;
V_19 [ 2 ] = V_36 -> V_26 ;
V_19 [ 3 ] = V_36 -> V_24 ;
V_19 [ 4 ] = V_36 -> V_22 + 1 ;
V_19 [ 5 ] = V_36 -> V_20 - 100 ;
return F_11 ( V_9 -> V_1 , V_33 , 6 , V_19 ) ;
}
static int F_16 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
int V_3 ;
struct V_17 * V_36 = & V_38 -> time ;
struct V_8 * V_9 = F_14 ( V_32 ) ;
V_3 = F_7 ( V_9 -> V_1 , V_36 ) ;
if ( V_3 )
return V_3 ;
V_38 -> V_39 = F_12 ( V_9 -> V_1 ) ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
int V_3 ;
struct V_17 * V_36 = & V_38 -> time ;
struct V_8 * V_9 = F_14 ( V_32 ) ;
V_3 = F_1 ( V_9 -> V_1 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_10 ( V_9 -> V_1 , V_36 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_1 ( V_9 -> V_1 , 1 ) ;
return V_3 ;
}
static int F_18 ( struct V_31 * V_32 , unsigned int V_39 )
{
struct V_8 * V_9 = F_14 ( V_32 ) ;
return F_1 ( V_9 -> V_1 , V_39 ) ;
}
static int F_19 ( struct V_40 * V_41 )
{
struct V_8 * V_9 ;
int V_3 ;
V_9 = F_20 ( & V_41 -> V_32 , sizeof( struct V_8 ) , V_42 ) ;
if ( ! V_9 )
return - V_43 ;
V_9 -> V_1 = F_14 ( V_41 -> V_32 . V_44 ) ;
F_21 ( V_41 , V_9 ) ;
V_3 = F_22 ( V_9 -> V_1 , V_45 , L_10 ,
F_4 , V_9 ) ;
if ( V_3 != 0 ) {
F_3 ( V_9 -> V_1 , L_11 , V_3 ) ;
return V_3 ;
}
V_9 -> V_9 = F_23 ( & V_41 -> V_32 , V_41 -> V_46 ,
& V_47 , V_48 ) ;
return F_24 ( V_9 -> V_9 ) ;
}
