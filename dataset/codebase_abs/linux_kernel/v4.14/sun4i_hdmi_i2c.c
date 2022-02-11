static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 , bool V_5 )
{
const unsigned long V_6 = 100 ;
const T_2 V_7 = V_8 |
V_9 |
V_10 ;
T_2 V_11 ;
V_4 = F_2 ( int , V_4 , V_5 ? ( V_12 + 1 ) :
( V_13 - V_14 + 1 ) ) ;
if ( F_3 ( V_2 -> V_15 + V_16 , V_11 ,
V_11 & V_7 , V_4 * V_6 , 100000 ) )
return - V_17 ;
if ( V_11 & V_8 )
return - V_18 ;
if ( V_5 )
F_4 ( V_2 -> V_15 + V_19 , V_3 , V_4 ) ;
else
F_5 ( V_2 -> V_15 + V_19 , V_3 , V_4 ) ;
F_6 ( V_9 ,
V_2 -> V_15 + V_16 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 , V_4 ;
T_2 V_11 ;
V_11 = F_8 ( V_2 -> V_15 + V_23 ) ;
V_11 &= ~ V_24 ;
V_11 |= ( V_21 -> V_25 & V_26 ) ?
V_27 :
V_28 ;
F_6 ( V_11 , V_2 -> V_15 + V_23 ) ;
F_6 ( F_9 ( V_21 -> V_29 ) ,
V_2 -> V_15 + V_30 ) ;
V_11 = F_8 ( V_2 -> V_15 + V_31 ) ;
V_11 |= V_32 ;
V_11 &= ~ V_33 ;
V_11 |= F_10 ( V_12 ) ;
V_11 &= ~ V_34 ;
V_11 |= F_11 ( V_14 ) ;
F_6 ( V_11 , V_2 -> V_15 + V_31 ) ;
if ( F_3 ( V_2 -> V_15 + V_31 ,
V_11 ,
! ( V_11 & V_32 ) ,
100 , 2000 ) )
return - V_18 ;
F_6 ( V_21 -> V_4 , V_2 -> V_15 + V_35 ) ;
F_6 ( V_21 -> V_25 & V_26 ?
V_36 :
V_37 ,
V_2 -> V_15 + V_38 ) ;
F_6 ( V_8 |
V_9 |
V_10 ,
V_2 -> V_15 + V_16 ) ;
V_11 = F_8 ( V_2 -> V_15 + V_23 ) ;
F_6 ( V_11 | V_39 ,
V_2 -> V_15 + V_23 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_4 ; V_22 += V_4 ) {
V_4 = F_1 ( V_2 , V_21 -> V_3 + V_22 , V_21 -> V_4 - V_22 ,
V_21 -> V_25 & V_26 ) ;
if ( V_4 <= 0 )
return V_4 ;
}
if ( F_3 ( V_2 -> V_15 + V_23 ,
V_11 ,
! ( V_11 & V_39 ) ,
100 , 100000 ) )
return - V_18 ;
V_11 = F_8 ( V_2 -> V_15 + V_16 ) ;
if ( ( V_11 & V_8 ) ||
! ( V_11 & V_10 ) ) {
return - V_18 ;
}
return 0 ;
}
static int F_12 ( struct V_40 * V_41 ,
struct V_20 * V_42 , int V_43 )
{
struct V_1 * V_2 = F_13 ( V_41 ) ;
T_2 V_11 ;
int V_44 , V_22 , V_45 = V_43 ;
for ( V_22 = 0 ; V_22 < V_43 ; V_22 ++ ) {
if ( ! V_42 [ V_22 ] . V_4 )
return - V_46 ;
if ( V_42 [ V_22 ] . V_4 > V_47 )
return - V_46 ;
}
F_6 ( V_48 | V_49 ,
V_2 -> V_15 + V_23 ) ;
if ( F_3 ( V_2 -> V_15 + V_23 , V_11 ,
! ( V_11 & V_49 ) ,
100 , 2000 ) )
return - V_18 ;
F_6 ( V_50 |
V_51 ,
V_2 -> V_15 + V_52 ) ;
F_14 ( V_2 -> V_53 ) ;
F_15 ( V_2 -> V_53 , 100000 ) ;
for ( V_22 = 0 ; V_22 < V_43 ; V_22 ++ ) {
V_44 = F_7 ( V_2 , & V_42 [ V_22 ] ) ;
if ( V_44 ) {
V_45 = V_44 ;
break;
}
}
F_16 ( V_2 -> V_53 ) ;
return V_45 ;
}
static T_2 F_17 ( struct V_40 * V_41 )
{
return V_54 | V_55 ;
}
int F_18 ( struct V_56 * V_57 , struct V_1 * V_2 )
{
struct V_40 * V_41 ;
int V_45 = 0 ;
V_45 = F_19 ( V_2 , V_2 -> V_58 ) ;
if ( V_45 )
return V_45 ;
V_41 = F_20 ( V_57 , sizeof( * V_41 ) , V_59 ) ;
if ( ! V_41 )
return - V_60 ;
V_41 -> V_61 = V_62 ;
V_41 -> V_63 = V_64 ;
V_41 -> V_65 = & V_66 ;
F_21 ( V_41 -> V_67 , L_1 , sizeof( V_41 -> V_67 ) ) ;
F_22 ( V_41 , V_2 ) ;
V_45 = F_23 ( V_41 ) ;
if ( V_45 )
return V_45 ;
V_2 -> V_68 = V_41 ;
return V_45 ;
}
