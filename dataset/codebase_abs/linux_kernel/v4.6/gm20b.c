static void
F_1 ( const struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
memcpy ( V_5 -> V_7 , V_2 -> V_7 , sizeof( V_5 -> V_7 ) ) ;
memcpy ( V_5 -> V_8 , V_2 -> V_8 , sizeof( V_5 -> V_8 ) ) ;
V_5 -> V_9 = V_2 -> V_9 ;
V_6 = V_2 -> V_10 . V_11 ;
V_6 <<= 32 ;
V_6 |= V_2 -> V_10 . V_12 ;
V_5 -> V_10 = F_2 ( V_6 >> 8 ) ;
V_5 -> V_13 = V_2 -> V_13 ;
V_5 -> V_14 = V_2 -> V_14 ;
V_5 -> V_15 = V_2 -> V_15 ;
V_5 -> V_16 = V_2 -> V_16 ;
V_5 -> V_17 = V_2 -> V_17 ;
V_6 = V_2 -> V_18 . V_11 ;
V_6 <<= 32 ;
V_6 |= V_2 -> V_18 . V_12 ;
V_5 -> V_18 = F_2 ( V_6 >> 8 ) ;
V_5 -> V_19 = V_2 -> V_19 ;
}
static void
F_3 ( struct V_20 * V_21 ,
struct V_22 * V_2 )
{
V_2 -> V_23 = V_21 -> V_24 -> V_6 ;
V_2 -> V_25 = V_21 -> V_24 -> V_26 ;
V_2 -> V_27 = 0 ;
}
static int
F_4 ( struct V_20 * V_21 )
{
struct V_28 * V_29 = & V_21 -> V_30 ;
void T_2 * V_31 ;
T_3 V_32 ;
V_31 = F_5 ( V_33 , 0xd00 ) ;
if ( ! V_31 ) {
F_6 ( & V_29 -> V_34 , L_1 ) ;
return F_7 ( V_31 ) ;
}
V_21 -> V_35 = F_8 ( V_31 + V_36 ) |
( ( T_1 ) F_8 ( V_31 + V_37 ) << 32 ) ;
V_21 -> V_38 = F_8 ( V_31 + V_39 )
<< 17 ;
V_32 = F_8 ( V_31 + V_40 ) ;
F_9 ( V_31 ) ;
if ( V_21 -> V_38 == 0 ) {
F_6 ( & V_29 -> V_34 , L_2 ) ;
return - V_41 ;
}
if ( ! ( V_32 & V_42 ) ) {
F_6 ( & V_29 -> V_34 , L_3 ) ;
return - V_41 ;
}
return 0 ;
}
static int
F_4 ( struct V_20 * V_21 )
{
F_6 ( & V_21 -> V_30 . V_34 , L_4 ) ;
return - V_41 ;
}
static int
F_10 ( struct V_28 * V_29 )
{
struct V_20 * V_21 = V_20 ( V_29 ) ;
int V_43 ;
int V_3 ;
V_3 = F_11 ( V_21 ) ;
if ( V_3 )
return V_3 ;
V_43 = V_21 -> V_44 -> V_26 ;
if ( V_43 > V_21 -> V_38 ) {
F_6 ( & V_29 -> V_34 , L_5 ) ;
F_6 ( & V_29 -> V_34 , L_6 , V_43 ) ;
F_6 ( & V_29 -> V_34 , L_7 , V_21 -> V_38 ) ;
return - V_45 ;
}
return 0 ;
}
static int
F_12 ( struct V_28 * V_29 )
{
struct V_20 * V_21 = V_20 ( V_29 ) ;
int V_3 ;
V_3 = F_4 ( V_21 ) ;
if ( V_3 )
return V_3 ;
return F_13 ( V_29 ) ;
}
int
F_14 ( struct V_46 * V_47 , int V_48 ,
struct V_28 * * V_49 )
{
int V_3 ;
struct V_20 * V_21 ;
V_21 = F_15 ( sizeof( * V_21 ) , V_50 ) ;
if ( ! V_21 ) {
V_49 = NULL ;
return - V_51 ;
}
* V_49 = & V_21 -> V_30 ;
V_3 = F_16 ( & V_52 , V_47 , V_48 , & V_21 -> V_30 ) ;
if ( V_3 )
return V_3 ;
V_21 -> V_53 = & V_54 ;
return 0 ;
}
