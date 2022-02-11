int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
int V_10 = 0 ;
F_3 ( & V_8 -> V_11 ) ;
if ( V_6 -> V_9 ) {
V_9 = 1 ;
F_4 ( V_2 , 1 ) ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , L_1 ) ;
V_6 -> V_12 . V_3 = V_3 ;
V_6 -> V_12 . V_4 = V_4 ;
if ( V_4 != V_13 )
V_2 -> V_14 &= ~ V_15 ;
else
V_2 -> V_14 |= V_15 ;
V_10 = F_7 ( V_6 ) ;
if ( V_10 ) {
F_8 ( V_6 , L_2 ) ;
goto V_16;
}
if ( V_9 ) {
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
F_8 ( V_6 , L_3 ) ;
}
V_16:
F_10 ( & V_8 -> V_11 ) ;
F_11 ( V_2 ) ;
return V_10 ;
}
static T_1 F_12 ( const struct V_17 * V_18 )
{
struct V_7 * V_8 =
F_13 ( V_18 , struct V_7 , V_19 ) ;
struct V_20 * V_2 = V_8 -> V_2 ;
return F_14 ( V_2 ) & V_18 -> V_21 ;
}
T_2 F_15 ( struct V_22 * V_23 )
{
T_2 V_24 , V_25 ;
struct V_26 * V_27 = (struct V_26 * ) V_23 ;
V_25 = ( T_2 ) F_16 ( V_27 -> V_28 ) ;
V_24 = ( ( T_2 ) F_17 ( V_27 -> V_29 ) + ! V_25 ) << 16 ;
return V_24 | V_25 ;
}
void F_18 ( struct V_7 * V_8 ,
struct V_30 * V_31 ,
T_2 V_32 )
{
T_2 V_33 ;
V_33 = F_19 ( & V_8 -> clock , V_32 ) ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_34 = F_20 ( V_33 ) ;
}
void F_21 ( struct V_7 * V_8 )
{
struct V_20 * V_2 = V_8 -> V_2 ;
T_2 V_35 ;
memset ( & V_8 -> V_19 , 0 , sizeof( V_8 -> V_19 ) ) ;
V_8 -> V_19 . V_36 = F_12 ;
V_8 -> V_19 . V_21 = F_22 ( 48 ) ;
V_8 -> V_19 . V_37 = 14 ;
V_8 -> V_19 . V_38 =
F_23 ( 1000 * V_2 -> V_39 . V_40 , V_8 -> V_19 . V_37 ) ;
F_24 ( & V_8 -> clock , & V_8 -> V_19 ,
F_25 ( F_26 () ) ) ;
V_35 = F_27 ( & V_8 -> V_19 , V_8 -> V_19 . V_21 ) ;
F_28 ( V_35 , V_41 / 2 / V_42 ) ;
V_8 -> V_43 = V_35 ;
}
void F_29 ( struct V_7 * V_8 )
{
bool V_44 = F_30 ( V_8 -> V_45 +
V_8 -> V_43 ) ;
if ( V_44 ) {
F_31 ( & V_8 -> clock ) ;
V_8 -> V_45 = V_46 ;
}
}
