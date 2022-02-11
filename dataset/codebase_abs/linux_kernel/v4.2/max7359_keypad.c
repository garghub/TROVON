static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_1 ,
V_7 , V_3 , V_4 , V_5 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_5 = F_5 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 , L_2 ,
V_7 , V_3 , V_5 ) ;
return V_5 ;
}
static T_2 F_6 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_12 * V_12 = V_11 -> V_12 ;
int V_4 , V_13 , V_14 , V_15 , V_16 ;
V_4 = F_4 ( V_11 -> V_2 , V_17 ) ;
V_13 = V_4 & 0x7 ;
V_14 = ( V_4 >> 3 ) & 0x7 ;
V_15 = V_4 & 0x40 ;
V_16 = F_7 ( V_13 , V_14 , V_18 ) ;
F_8 ( & V_11 -> V_2 -> V_6 ,
L_3 , V_13 , V_14 , V_15 ? L_4 : L_5 ) ;
F_9 ( V_12 , V_19 , V_20 , V_16 ) ;
F_10 ( V_12 , V_11 -> V_21 [ V_16 ] , ! V_15 ) ;
F_11 ( V_12 ) ;
return V_22 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_23 , V_24 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_23 , V_25 ) ;
}
static int F_14 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_15 ( V_6 ) ;
F_13 ( V_11 -> V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_12 * V_6 )
{
struct V_10 * V_11 = F_15 ( V_6 ) ;
F_12 ( V_11 -> V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_26 ,
V_27 |
V_28 ) ;
F_1 ( V_2 , V_29 , 0x1F ) ;
F_1 ( V_2 , V_30 , 0x01 ) ;
F_12 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_31 * V_32 )
{
const struct V_33 * V_34 =
F_19 ( & V_2 -> V_6 ) ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
int V_5 ;
int error ;
if ( ! V_2 -> V_8 ) {
F_3 ( & V_2 -> V_6 , L_6 ) ;
return - V_35 ;
}
V_5 = F_4 ( V_2 , V_17 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return - V_36 ;
}
F_8 ( & V_2 -> V_6 , L_8 , V_5 ) ;
V_11 = F_20 ( & V_2 -> V_6 , sizeof( struct V_10 ) ,
V_37 ) ;
if ( ! V_11 ) {
F_3 ( & V_2 -> V_6 , L_9 ) ;
return - V_38 ;
}
V_12 = F_21 ( & V_2 -> V_6 ) ;
if ( ! V_12 ) {
F_3 ( & V_2 -> V_6 , L_10 ) ;
return - V_38 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_12 = V_12 ;
V_12 -> V_39 = V_2 -> V_39 ;
V_12 -> V_32 . V_40 = V_41 ;
V_12 -> V_42 = F_14 ;
V_12 -> V_43 = F_16 ;
V_12 -> V_6 . V_44 = & V_2 -> V_6 ;
V_12 -> V_45 [ 0 ] = F_22 ( V_46 ) | F_22 ( V_47 ) ;
V_12 -> V_48 = sizeof( V_11 -> V_21 [ 0 ] ) ;
V_12 -> V_49 = F_23 ( V_11 -> V_21 ) ;
V_12 -> V_50 = V_11 -> V_21 ;
F_24 ( V_12 , V_19 , V_20 ) ;
F_25 ( V_12 , V_11 ) ;
error = F_26 ( V_34 , NULL ,
V_51 ,
V_52 ,
V_11 -> V_21 ,
V_12 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 , L_11 ) ;
return error ;
}
error = F_27 ( & V_2 -> V_6 , V_2 -> V_8 , NULL ,
F_6 ,
V_53 | V_54 ,
V_2 -> V_39 , V_11 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 , L_12 ) ;
return error ;
}
error = F_28 ( V_12 ) ;
if ( error ) {
F_3 ( & V_2 -> V_6 , L_13 ) ;
return error ;
}
F_17 ( V_2 ) ;
F_29 ( V_2 , V_11 ) ;
F_30 ( & V_2 -> V_6 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_55 * V_6 )
{
struct V_1 * V_2 = F_32 ( V_6 ) ;
F_12 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_6 ) )
F_34 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_35 ( struct V_55 * V_6 )
{
struct V_1 * V_2 = F_32 ( V_6 ) ;
if ( F_33 ( & V_2 -> V_6 ) )
F_36 ( V_2 -> V_8 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
