static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 -> V_3 , struct V_1 ,
V_4 ) ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
unsigned long V_8 = V_6 -> V_9 - V_6 -> V_10 ;
T_1 V_11 = V_6 -> V_12 ;
if ( V_6 -> V_13 + V_8 > V_7 -> V_14 + V_7 -> V_15 )
return - V_16 ;
V_11 = F_4 ( V_11 ) ;
if ( F_5 ( V_6 , V_6 -> V_10 ,
( V_7 -> V_14 >> V_17 ) + V_6 -> V_13 ,
V_8 , V_11 ) )
return - V_18 ;
return 0 ;
}
static long F_6 ( struct V_2 * V_2 , unsigned int V_19 ,
unsigned long V_20 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
void T_2 * V_21 = ( void T_2 * ) V_20 ;
struct V_22 V_23 ;
T_3 V_24 ;
T_3 V_25 ;
long V_26 ;
if ( F_7 ( & V_23 , V_21 , sizeof( V_23 ) ) )
return - V_27 ;
if ( V_23 . V_28 != 0 )
return - V_16 ;
switch ( V_19 ) {
case V_29 :
if ( V_23 . V_30 != V_31 )
return - V_16 ;
if ( V_23 . V_32 != 0 )
return - V_16 ;
V_23 . V_25 = V_7 -> V_15 ;
return F_8 ( V_21 , & V_23 , sizeof( V_23 ) ) ? - V_27 : 0 ;
case V_33 :
if ( ( V_23 . V_25 & 0x0000ffff ) || ( V_23 . V_34 & 0x0000ffff ) )
return - V_16 ;
if ( V_23 . V_34 & ( V_23 . V_25 - 1 ) )
return - V_16 ;
if ( V_23 . V_30 == V_35 ) {
V_24 = V_7 -> V_36 ;
V_25 = V_7 -> V_37 ;
} else if ( V_23 . V_30 == V_31 ) {
V_24 = V_7 -> V_14 ;
V_25 = V_7 -> V_15 ;
} else {
return - V_16 ;
}
if ( V_23 . V_34 + V_23 . V_25 < V_23 . V_34 ||
V_23 . V_34 + V_23 . V_25 > V_25 )
return - V_16 ;
if ( V_23 . V_25 == 0 || V_23 . V_25 > V_25 )
return - V_16 ;
V_24 += V_23 . V_34 ;
V_26 = F_9 ( V_7 -> V_38 , V_39 ,
( V_24 | ( V_23 . V_24 >> 16 ) ) ) ;
if ( V_26 )
return V_26 ;
return F_9 ( V_7 -> V_38 , V_40 ,
( ~ ( V_23 . V_25 - 1 ) ) | ( ( V_23 . V_25 >> 16 ) - 1 ) ) ;
}
return - V_16 ;
}
static int F_10 ( struct V_41 * V_42 )
{
struct V_1 * V_7 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
int V_26 ;
V_48 = & V_42 -> V_48 ;
V_7 = F_11 ( V_48 , sizeof( * V_7 ) , V_49 ) ;
if ( ! V_7 )
return - V_50 ;
V_44 = F_12 ( V_48 -> V_51 , L_1 , 0 ) ;
if ( ! V_44 ) {
F_13 ( V_48 , L_2 ) ;
return - V_52 ;
}
V_26 = F_14 ( V_44 , 1 , & V_46 ) ;
F_15 ( V_44 ) ;
if ( V_26 ) {
F_13 ( V_48 , L_3 ) ;
return V_26 ;
}
V_7 -> V_37 = F_16 ( & V_46 ) ;
V_7 -> V_36 = V_46 . V_53 ;
F_17 ( & V_42 -> V_48 , V_7 ) ;
V_44 = F_12 ( V_48 -> V_51 , L_4 , 0 ) ;
if ( ! V_44 ) {
F_13 ( V_48 , L_5 ) ;
return - V_16 ;
}
V_26 = F_14 ( V_44 , 0 , & V_46 ) ;
F_15 ( V_44 ) ;
if ( V_26 ) {
F_13 ( V_48 , L_6 ) ;
return - V_50 ;
}
V_7 -> V_15 = F_16 ( & V_46 ) ;
V_7 -> V_14 = V_46 . V_53 ;
V_7 -> V_38 = F_18 (
V_42 -> V_48 . V_54 -> V_51 ) ;
if ( F_19 ( V_7 -> V_38 ) ) {
F_13 ( V_48 , L_7 ) ;
return - V_52 ;
}
V_7 -> V_4 . V_55 = V_56 ;
V_7 -> V_4 . V_57 = V_58 ;
V_7 -> V_4 . V_59 = & V_60 ;
V_7 -> V_4 . V_54 = V_48 ;
V_26 = F_20 ( & V_7 -> V_4 ) ;
if ( V_26 )
F_13 ( V_48 , L_8 ) ;
else
F_21 ( V_48 , L_9 , & V_46 ) ;
return V_26 ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_1 * V_7 = F_23 ( & V_42 -> V_48 ) ;
F_24 ( & V_7 -> V_4 ) ;
return 0 ;
}
