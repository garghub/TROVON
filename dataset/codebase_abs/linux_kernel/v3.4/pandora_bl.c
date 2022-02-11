static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_3 ;
T_1 V_5 ;
if ( V_2 -> V_4 . V_6 != V_7 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_9 )
V_3 = 0 ;
if ( V_2 -> V_4 . V_8 & V_10 )
V_3 = 0 ;
if ( ( unsigned int ) V_3 > V_11 )
V_3 = V_11 ;
if ( V_3 == 0 ) {
if ( V_2 -> V_4 . V_8 & V_12 )
goto V_13;
F_2 ( V_14 , & V_5 , V_15 ) ;
V_5 &= ~ V_16 ;
F_3 ( V_14 , V_5 , V_15 ) ;
V_5 &= ~ V_17 ;
F_3 ( V_14 , V_5 , V_15 ) ;
goto V_13;
}
if ( V_2 -> V_4 . V_8 & V_12 ) {
F_3 ( V_18 , V_19 ,
V_20 ) ;
F_2 ( V_14 , & V_5 , V_15 ) ;
V_5 &= ~ V_16 ;
V_5 |= V_17 ;
F_3 ( V_14 , V_5 , V_15 ) ;
V_5 |= V_16 ;
F_3 ( V_14 , V_5 , V_15 ) ;
F_4 ( 2000 , 10000 ) ;
}
F_3 ( V_18 , V_21 + V_3 ,
V_20 ) ;
V_13:
if ( V_3 != 0 )
V_2 -> V_4 . V_8 &= ~ V_12 ;
else
V_2 -> V_4 . V_8 |= V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_3 ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_24 V_4 ;
struct V_1 * V_2 ;
T_1 V_5 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_25 = V_11 ;
V_4 . type = V_26 ;
V_2 = F_7 ( V_23 -> V_27 , & V_23 -> V_28 ,
NULL , & V_29 , & V_4 ) ;
if ( F_8 ( V_2 ) ) {
F_9 ( & V_23 -> V_28 , L_1 ) ;
return F_10 ( V_2 ) ;
}
F_11 ( V_23 , V_2 ) ;
F_3 ( V_18 , 0x80 , V_30 ) ;
V_2 -> V_4 . V_8 |= V_12 ;
V_2 -> V_4 . V_3 = V_11 ;
F_12 ( V_2 ) ;
F_2 ( V_14 , & V_5 , V_31 ) ;
V_5 &= ~ V_32 ;
V_5 |= V_33 ;
F_3 ( V_14 , V_5 , V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
