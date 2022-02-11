void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_4 -> V_8 = V_9 | V_10 ;
V_4 -> V_11 = V_6 -> V_11 ;
memset ( V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
if ( V_4 -> V_11 & V_10 ) {
V_7 = F_3 ( V_6 , V_13 ) ;
F_4 ( V_7 , & V_4 -> V_12 [ 0 ] ) ;
V_7 = F_3 ( V_6 , V_14 ) ;
F_5 ( V_7 , & V_4 -> V_12 [ 2 ] ) ;
}
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = & V_6 -> V_17 -> V_2 ;
T_1 V_7 ;
if ( ! F_7 ( V_16 ) )
return - V_18 ;
if ( V_4 -> V_11 & ~ ( V_9 | V_10 ) )
return - V_19 ;
if ( V_4 -> V_11 & V_10 ) {
F_8 ( V_6 , F_9 ( & V_4 -> V_12 [ 0 ] ) ,
V_13 ) ;
F_8 ( V_6 , F_10 ( & V_4 -> V_12 [ 2 ] ) ,
V_14 ) ;
V_7 = F_3 ( V_6 , V_20 ) ;
V_7 |= V_21 ;
F_8 ( V_6 , V_7 , V_20 ) ;
}
if ( V_4 -> V_11 ) {
F_11 ( V_16 , 1 ) ;
if ( V_6 -> V_22 )
F_12 ( V_6 -> V_23 ) ;
V_6 -> V_22 = false ;
} else {
F_11 ( V_16 , 0 ) ;
if ( ! V_6 -> V_22 )
F_13 ( V_6 -> V_23 ) ;
V_6 -> V_22 = true ;
}
V_6 -> V_11 = V_4 -> V_11 ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_24 = 0 ;
while ( ! ( F_15 ( V_6 , V_25 )
& V_26 ) ) {
V_24 ++ ;
if ( V_24 > 5 ) {
F_16 ( V_2 , L_1 ) ;
return - V_27 ;
}
F_17 ( 1 ) ;
}
return V_24 ;
}
int F_18 ( struct V_5 * V_6 ,
enum V_28 V_29 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
T_1 V_30 ;
int V_24 = 0 ;
T_1 V_7 ;
if ( V_29 != V_31 ) {
F_19 ( V_6 , V_4 , V_2 , L_2 , V_29 ) ;
return - V_19 ;
}
V_7 = F_3 ( V_6 , V_32 ) ;
V_7 &= ~ V_33 ;
F_8 ( V_6 , V_7 , V_32 ) ;
F_17 ( 10 ) ;
V_7 = F_3 ( V_6 , V_20 ) ;
V_7 |= V_34 ;
F_8 ( V_6 , V_7 , V_20 ) ;
V_24 = F_14 ( V_6 ) ;
if ( V_24 < 0 ) {
V_7 = F_3 ( V_6 , V_20 ) ;
V_7 &= ~ V_34 ;
F_8 ( V_6 , V_7 , V_20 ) ;
return V_24 ;
}
F_20 ( V_6 , V_4 , V_2 , L_3 ,
V_24 ) ;
V_7 = F_3 ( V_6 , V_32 ) ;
V_6 -> V_35 = 1 ;
V_7 |= V_36 ;
V_7 |= V_33 ;
F_8 ( V_6 , V_7 , V_32 ) ;
if ( V_6 -> V_37 -> V_38 & V_39 ) {
V_7 = F_21 ( V_6 , V_40 ) ;
V_7 &= ~ V_41 ;
F_22 ( V_6 , V_7 , V_40 ) ;
}
V_30 = V_42 ;
F_23 ( V_6 , V_30 , V_43 ) ;
return 0 ;
}
void F_24 ( struct V_5 * V_6 ,
enum V_28 V_29 )
{
T_1 V_44 ;
T_1 V_7 ;
if ( V_29 != V_31 ) {
F_19 ( V_6 , V_4 , V_6 -> V_2 , L_4 , V_29 ) ;
return;
}
V_7 = F_3 ( V_6 , V_20 ) ;
V_7 &= ~ V_34 ;
F_8 ( V_6 , V_7 , V_20 ) ;
V_7 = F_3 ( V_6 , V_32 ) ;
V_7 &= ~ V_36 ;
F_8 ( V_6 , V_7 , V_32 ) ;
V_6 -> V_35 = 0 ;
V_44 = V_42 ;
F_23 ( V_6 , V_44 , V_45 ) ;
}
