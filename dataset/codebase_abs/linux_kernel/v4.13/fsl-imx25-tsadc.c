static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_7 ;
F_4 ( V_6 , V_2 ) ;
F_5 ( V_4 -> V_8 , V_9 , & V_7 ) ;
if ( V_7 & V_10 )
F_6 ( F_7 ( V_4 -> V_11 , 1 ) ) ;
if ( V_7 & V_12 )
F_6 ( F_7 ( V_4 -> V_11 , 0 ) ) ;
F_8 ( V_6 , V_2 ) ;
}
static int F_9 ( struct V_13 * V_14 , unsigned int V_15 ,
T_2 V_16 )
{
struct V_3 * V_4 = V_14 -> V_17 ;
F_10 ( V_15 , V_4 ) ;
F_11 ( V_15 , & V_18 ,
V_19 ) ;
F_12 ( V_15 , V_20 , V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
int V_15 ;
V_15 = F_14 ( V_23 , 0 ) ;
if ( V_15 <= 0 ) {
F_15 ( V_25 , L_1 ) ;
return V_15 ;
}
V_4 -> V_11 = F_16 ( V_27 , 2 , 0 , & V_29 ,
V_4 ) ;
if ( ! V_4 -> V_11 ) {
F_15 ( V_25 , L_2 ) ;
return - V_30 ;
}
F_17 ( V_15 , F_1 ) ;
F_18 ( V_15 , V_4 ) ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
unsigned V_31 ;
F_20 ( & V_23 -> V_25 , L_3 ,
F_21 ( V_4 -> V_32 ) ) ;
V_31 = F_22 ( F_21 ( V_4 -> V_32 ) , 1750000 ) ;
F_20 ( & V_23 -> V_25 , L_4 , V_31 ) ;
V_31 -= 2 ;
V_31 /= 2 ;
V_31 = F_23 ( unsigned , 4 , V_31 ) ;
F_20 ( & V_23 -> V_25 , L_5 ,
F_21 ( V_4 -> V_32 ) / ( 2 * V_31 + 2 ) ) ;
F_24 ( V_4 -> V_8 , V_33 ,
F_25 ( 0x1f ) ,
F_25 ( V_31 ) ) ;
}
static int F_26 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
int V_36 ;
void T_3 * V_37 ;
V_4 = F_27 ( V_25 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_30 ;
V_35 = F_28 ( V_23 , V_39 , 0 ) ;
V_37 = F_29 ( V_25 , V_35 ) ;
if ( F_30 ( V_37 ) )
return F_31 ( V_37 ) ;
V_4 -> V_8 = F_32 ( V_25 , V_37 ,
& V_40 ) ;
if ( F_30 ( V_4 -> V_8 ) ) {
F_15 ( V_25 , L_6 ) ;
return F_31 ( V_4 -> V_8 ) ;
}
V_4 -> V_32 = F_33 ( V_25 , L_7 ) ;
if ( F_30 ( V_4 -> V_32 ) ) {
F_15 ( V_25 , L_8 ) ;
return F_31 ( V_4 -> V_32 ) ;
}
F_19 ( V_23 , V_4 ) ;
F_24 ( V_4 -> V_8 , V_33 , V_41 ,
V_41 ) ;
F_24 ( V_4 -> V_8 , V_33 , V_42 ,
V_42 ) ;
F_24 ( V_4 -> V_8 , V_33 , V_43 ,
V_44 ) ;
F_24 ( V_4 -> V_8 , V_33 , V_45 ,
V_45 ) ;
V_36 = F_13 ( V_23 , V_4 ) ;
if ( V_36 )
return V_36 ;
F_34 ( V_23 , V_4 ) ;
return F_35 ( V_25 ) ;
}
