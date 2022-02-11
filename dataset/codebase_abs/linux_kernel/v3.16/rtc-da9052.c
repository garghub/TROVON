static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 | V_8 ,
V_7 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_1 , V_4 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 | V_8 , 0 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_2 , V_4 ) ;
}
return V_4 ;
}
static T_1 F_4 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
F_5 ( V_2 -> V_2 , 1 , V_11 | V_12 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_4 ;
T_2 V_16 [ 5 ] ;
V_4 = F_7 ( V_2 -> V_5 , V_17 , 5 , V_16 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 , L_3 , V_4 ) ;
return V_4 ;
}
V_15 -> V_18 = ( V_16 [ 4 ] & V_19 ) + 100 ;
V_15 -> V_20 = ( V_16 [ 3 ] & V_21 ) - 1 ;
V_15 -> V_22 = V_16 [ 2 ] & V_23 ;
V_15 -> V_24 = V_16 [ 1 ] & V_25 ;
V_15 -> V_26 = V_16 [ 0 ] & V_27 ;
V_4 = F_8 ( V_15 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
unsigned long V_28 ;
int V_4 ;
T_2 V_16 [ 3 ] ;
V_4 = F_10 ( V_15 , & V_28 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_15 -> V_29 > 0 ) {
V_28 += 60 - V_15 -> V_29 ;
F_11 ( V_28 , V_15 ) ;
}
F_12 ( V_15 -> V_29 ) ;
V_15 -> V_18 -= 100 ;
V_15 -> V_20 += 1 ;
V_4 = F_2 ( V_5 , V_17 ,
V_27 , V_15 -> V_26 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 , L_4 , V_4 ) ;
return V_4 ;
}
V_16 [ 0 ] = V_15 -> V_24 ;
V_16 [ 1 ] = V_15 -> V_22 ;
V_16 [ 2 ] = V_15 -> V_20 ;
V_4 = F_13 ( V_5 , V_30 , 3 , V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_5 , V_6 ,
V_19 , V_15 -> V_18 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_5 , V_4 ) ;
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_15 ( V_2 -> V_5 , V_6 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 , L_6 , V_4 ) ;
return V_4 ;
}
return ! ! ( V_4 & V_7 ) ;
}
static int F_16 ( struct V_31 * V_32 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_17 ( V_32 ) ;
T_2 V_16 [ 6 ] ;
int V_4 ;
V_4 = F_7 ( V_2 -> V_5 , V_33 , 6 , V_16 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 , L_7 , V_4 ) ;
return V_4 ;
}
V_15 -> V_18 = ( V_16 [ 5 ] & V_19 ) + 100 ;
V_15 -> V_20 = ( V_16 [ 4 ] & V_21 ) - 1 ;
V_15 -> V_22 = V_16 [ 3 ] & V_23 ;
V_15 -> V_24 = V_16 [ 2 ] & V_25 ;
V_15 -> V_26 = V_16 [ 1 ] & V_27 ;
V_15 -> V_29 = V_16 [ 0 ] & V_34 ;
V_4 = F_8 ( V_15 ) ;
return V_4 ;
}
static int F_18 ( struct V_31 * V_32 , struct V_14 * V_35 )
{
struct V_1 * V_2 ;
T_2 V_16 [ 6 ] ;
int V_4 ;
V_2 = F_17 ( V_32 ) ;
V_16 [ 0 ] = V_35 -> V_29 ;
V_16 [ 1 ] = V_35 -> V_26 ;
V_16 [ 2 ] = V_35 -> V_24 ;
V_16 [ 3 ] = V_35 -> V_22 ;
V_16 [ 4 ] = V_35 -> V_20 + 1 ;
V_16 [ 5 ] = V_35 -> V_18 - 100 ;
V_4 = F_13 ( V_2 -> V_5 , V_33 , 6 , V_16 ) ;
if ( V_4 < 0 )
F_3 ( V_2 , L_8 , V_4 ) ;
return V_4 ;
}
static int F_19 ( struct V_31 * V_32 , struct V_36 * V_37 )
{
int V_4 ;
struct V_14 * V_35 = & V_37 -> time ;
struct V_1 * V_2 = F_17 ( V_32 ) ;
V_4 = F_6 ( V_2 , V_35 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 , L_9 , V_4 ) ;
return V_4 ;
}
V_37 -> V_38 = F_14 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 , struct V_36 * V_37 )
{
int V_4 ;
struct V_14 * V_35 = & V_37 -> time ;
struct V_1 * V_2 = F_17 ( V_32 ) ;
V_4 = F_1 ( V_2 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_9 ( V_2 , V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_1 ( V_2 , 1 ) ;
return V_4 ;
}
static int F_21 ( struct V_31 * V_32 , unsigned int V_38 )
{
struct V_1 * V_2 = F_17 ( V_32 ) ;
return F_1 ( V_2 , V_38 ) ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
int V_4 ;
V_2 = F_23 ( & V_40 -> V_32 , sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_2 -> V_5 = F_17 ( V_40 -> V_32 . V_43 ) ;
F_24 ( V_40 , V_2 ) ;
V_4 = F_25 ( V_2 -> V_5 , V_44 , 0xFE ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 ,
L_10 , V_4 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_8 , 0 ) ;
if ( V_4 != 0 )
F_3 ( V_2 , L_11 , V_4 ) ;
V_4 = F_26 ( V_2 -> V_5 , V_45 , L_12 ,
F_4 , V_2 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 , L_13 , V_4 ) ;
return V_4 ;
}
V_2 -> V_2 = F_27 ( & V_40 -> V_32 , V_40 -> V_46 ,
& V_47 , V_48 ) ;
return F_28 ( V_2 -> V_2 ) ;
}
