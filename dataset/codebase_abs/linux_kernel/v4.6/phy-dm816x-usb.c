static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 = V_4 ;
if ( ! V_4 )
V_2 -> V_5 = V_6 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_2 -> V_8 = V_8 ;
if ( ! V_8 )
V_2 -> V_5 = V_6 ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_9 = F_4 ( V_10 ) ;
unsigned int V_12 ;
int error ;
if ( F_5 ( V_9 -> V_13 ) != 24000000 )
F_6 ( V_9 -> V_14 , L_1 ) ;
error = F_7 ( V_9 -> V_15 , V_9 -> V_16 ,
V_17 |
V_18 |
V_19 ,
0 ) ;
F_8 ( V_9 -> V_15 , V_9 -> V_16 , & V_12 ) ;
if ( ( V_12 & 3 ) != 0 )
F_9 ( V_9 -> V_14 ,
L_2 ,
V_12 ) ;
F_8 ( V_9 -> V_15 , V_9 -> V_20 , & V_12 ) ;
V_12 |= V_21 |
V_22 |
V_23 ;
F_10 ( V_9 -> V_15 , V_9 -> V_20 , V_12 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_24 * V_14 )
{
struct V_11 * V_9 = F_12 ( V_14 ) ;
unsigned int V_25 , V_12 ;
int error = 0 ;
V_25 = F_13 ( V_9 -> V_26 ) ;
V_12 = ~ F_13 ( V_9 -> V_26 ) ;
error = F_7 ( V_9 -> V_15 , V_9 -> V_16 ,
V_25 , V_12 ) ;
if ( error )
F_14 ( V_9 -> V_14 , L_3 ,
V_9 -> V_26 ) ;
F_15 ( V_9 -> V_13 ) ;
return 0 ;
}
static int T_1 F_16 ( struct V_24 * V_14 )
{
struct V_11 * V_9 = F_12 ( V_14 ) ;
unsigned int V_25 , V_12 ;
int error ;
error = F_17 ( V_9 -> V_13 ) ;
if ( error )
return error ;
V_25 = F_13 ( V_9 -> V_26 ) ;
V_12 = F_13 ( V_9 -> V_26 ) ;
error = F_7 ( V_9 -> V_15 , V_9 -> V_16 ,
V_25 , V_12 ) ;
if ( error ) {
F_14 ( V_9 -> V_14 , L_4 ,
V_9 -> V_26 ) ;
F_15 ( V_9 -> V_13 ) ;
return error ;
}
return 0 ;
}
static int F_18 ( struct V_27 * V_28 )
{
struct V_11 * V_9 ;
struct V_29 * V_30 ;
struct V_9 * V_31 ;
struct V_32 * V_32 ;
struct V_1 * V_2 ;
const struct V_33 * V_34 ;
const struct V_35 * V_36 ;
int error ;
V_34 = F_19 ( F_20 ( V_37 ) ,
& V_28 -> V_14 ) ;
if ( ! V_34 )
return - V_38 ;
V_9 = F_21 ( & V_28 -> V_14 , sizeof( * V_9 ) , V_39 ) ;
if ( ! V_9 )
return - V_40 ;
V_30 = F_22 ( V_28 , V_41 , 0 ) ;
if ( ! V_30 )
return - V_42 ;
V_9 -> V_15 = F_23 ( V_28 -> V_14 . V_43 ,
L_5 ) ;
if ( F_24 ( V_9 -> V_15 ) )
return F_25 ( V_9 -> V_15 ) ;
V_9 -> V_16 = 0x20 ;
V_9 -> V_20 = ( V_30 -> V_44 & 0xff ) + 4 ;
if ( V_9 -> V_20 == 0x2c )
V_9 -> V_26 = 1 ;
V_36 = V_34 -> V_45 ;
V_2 = F_21 ( & V_28 -> V_14 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_9 -> V_14 = & V_28 -> V_14 ;
V_9 -> V_9 . V_14 = V_9 -> V_14 ;
V_9 -> V_9 . V_46 = L_6 ;
V_9 -> V_9 . V_2 = V_2 ;
V_9 -> V_9 . type = V_47 ;
V_2 -> V_48 = F_1 ;
V_2 -> V_49 = F_2 ;
V_2 -> V_50 = & V_9 -> V_9 ;
F_26 ( V_28 , V_9 ) ;
V_9 -> V_13 = F_27 ( V_9 -> V_14 , L_7 ) ;
if ( F_24 ( V_9 -> V_13 ) )
return F_25 ( V_9 -> V_13 ) ;
error = F_28 ( V_9 -> V_13 ) ;
if ( error )
return error ;
F_29 ( V_9 -> V_14 ) ;
V_31 = F_30 ( V_9 -> V_14 , NULL , & V_51 ) ;
if ( F_24 ( V_31 ) )
return F_25 ( V_31 ) ;
F_31 ( V_31 , V_9 ) ;
V_32 = F_32 ( V_9 -> V_14 ,
V_52 ) ;
if ( F_24 ( V_32 ) )
return F_25 ( V_32 ) ;
F_33 ( & V_9 -> V_9 ) ;
return 0 ;
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_11 * V_9 = F_35 ( V_28 ) ;
F_36 ( & V_9 -> V_9 ) ;
F_37 ( V_9 -> V_14 ) ;
F_38 ( V_9 -> V_13 ) ;
return 0 ;
}
