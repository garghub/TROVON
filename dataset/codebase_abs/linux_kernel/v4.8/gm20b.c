static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
int V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_6 = V_2 -> V_8 -> V_9 ;
if ( V_6 > V_2 -> V_10 ) {
F_3 ( V_4 , L_1 ) ;
F_3 ( V_4 , L_2 , V_6 ) ;
F_3 ( V_4 , L_3 , V_2 -> V_10 ) ;
return - V_11 ;
}
return 0 ;
}
static void
F_4 ( const struct V_12 * V_13 , void * V_7 )
{
struct V_14 * V_15 = V_7 ;
T_1 V_16 ;
memcpy ( V_15 -> V_17 , V_13 -> V_17 , sizeof( V_15 -> V_17 ) ) ;
memcpy ( V_15 -> V_18 , V_13 -> V_18 , sizeof( V_15 -> V_18 ) ) ;
V_15 -> V_19 = V_13 -> V_19 ;
V_16 = V_13 -> V_20 . V_21 ;
V_16 <<= 32 ;
V_16 |= V_13 -> V_20 . V_22 ;
V_15 -> V_20 = F_5 ( V_16 >> 8 ) ;
V_15 -> V_23 = V_13 -> V_23 ;
V_15 -> V_24 = V_13 -> V_24 ;
V_15 -> V_25 = V_13 -> V_25 ;
V_15 -> V_26 = V_13 -> V_26 ;
V_15 -> V_27 = V_13 -> V_27 ;
V_16 = V_13 -> V_28 . V_21 ;
V_16 <<= 32 ;
V_16 |= V_13 -> V_28 . V_22 ;
V_15 -> V_28 = F_5 ( V_16 >> 8 ) ;
V_15 -> V_29 = V_13 -> V_29 ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_30 * V_13 )
{
V_13 -> V_31 = V_2 -> V_32 -> V_16 ;
V_13 -> V_33 = V_2 -> V_32 -> V_9 ;
V_13 -> V_34 = 0 ;
}
static int
F_7 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = & V_2 -> V_5 ;
void T_2 * V_37 ;
T_3 V_38 ;
V_37 = F_8 ( V_39 , 0xd00 ) ;
if ( ! V_37 ) {
F_3 ( & V_36 -> V_4 , L_4 ) ;
return F_9 ( V_37 ) ;
}
V_2 -> V_40 = F_10 ( V_37 + V_41 ) |
( ( T_1 ) F_10 ( V_37 + V_42 ) << 32 ) ;
V_2 -> V_10 = F_10 ( V_37 + V_43 )
<< 17 ;
V_38 = F_10 ( V_37 + V_44 ) ;
F_11 ( V_37 ) ;
if ( V_2 -> V_10 == 0 ) {
F_3 ( & V_36 -> V_4 , L_5 ) ;
return - V_45 ;
}
if ( ! ( V_38 & V_46 ) ) {
F_3 ( & V_36 -> V_4 , L_6 ) ;
return - V_45 ;
}
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_5 . V_4 , L_7 ) ;
return - V_45 ;
}
static int
F_12 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_1 ( V_36 ) ;
int V_7 ;
V_7 = F_7 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return F_13 ( V_36 ) ;
}
int
F_14 ( struct V_47 * V_48 , int V_49 ,
struct V_35 * * V_50 )
{
int V_7 ;
struct V_1 * V_2 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 ) {
V_50 = NULL ;
return - V_52 ;
}
* V_50 = & V_2 -> V_5 ;
V_7 = F_16 ( & V_53 , V_48 , V_49 , & V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_54 = & V_55 ;
return 0 ;
}
