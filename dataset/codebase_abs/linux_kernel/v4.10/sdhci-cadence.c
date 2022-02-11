static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_7 ;
T_3 V_8 ;
V_8 = ( V_4 << V_9 ) |
( V_3 << V_10 ) ;
F_2 ( V_8 , V_5 ) ;
V_8 |= V_11 ;
F_2 ( V_8 , V_5 ) ;
V_8 &= ~ V_11 ;
F_2 ( V_8 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 , 4 ) ;
F_1 ( V_2 , V_13 , 4 ) ;
F_1 ( V_2 , V_14 , 9 ) ;
F_1 ( V_2 , V_15 , 2 ) ;
F_1 ( V_2 , V_16 , 3 ) ;
}
static inline void * V_1 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_4 ( V_18 ) ;
return F_5 ( V_20 ) ;
}
static unsigned int F_6 ( struct V_17 * V_18 )
{
return V_18 -> V_21 / 1000 ;
}
static void F_7 ( struct V_17 * V_18 ,
unsigned int V_22 )
{
struct V_1 * V_2 = V_1 ( V_18 ) ;
T_3 V_23 , V_8 ;
switch ( V_22 ) {
case V_24 :
V_23 = V_25 ;
break;
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
V_23 = V_29 ;
break;
case V_30 :
V_23 = V_31 ;
break;
default:
V_23 = V_32 ;
break;
}
V_8 = F_8 ( V_2 -> V_6 + V_33 ) ;
V_8 &= ~ V_34 ;
V_8 |= V_23 ;
F_2 ( V_8 , V_2 -> V_6 + V_33 ) ;
if ( V_23 == V_32 )
F_9 ( V_18 , V_22 ) ;
}
static int F_10 ( struct V_17 * V_18 , unsigned int V_35 )
{
struct V_1 * V_2 = V_1 ( V_18 ) ;
void T_2 * V_5 = V_2 -> V_6 + V_33 ;
T_3 V_8 ;
if ( F_11 ( V_35 > V_36 ) )
return - V_37 ;
V_8 = F_8 ( V_5 ) ;
V_8 &= ~ ( V_36 << V_38 ) ;
V_8 |= V_35 << V_38 ;
V_8 |= V_39 ;
F_2 ( V_8 , V_5 ) ;
return F_12 ( V_5 , V_8 , ! ( V_8 & V_39 ) ,
0 , 1 ) ;
}
static int F_13 ( struct V_40 * V_41 , T_3 V_42 )
{
struct V_17 * V_18 = F_14 ( V_41 ) ;
int V_43 = 0 ;
int V_44 = 0 ;
int V_45 = 0 ;
int V_46 ;
if ( V_18 -> V_22 != V_28 )
return F_15 ( V_41 , V_42 ) ;
if ( F_11 ( V_42 != V_47 ) )
return - V_37 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if ( F_10 ( V_18 , V_46 ) ||
F_16 ( V_18 -> V_41 , V_42 , NULL ) ) {
V_43 = 0 ;
} else {
V_43 ++ ;
if ( V_43 > V_44 ) {
V_44 = V_43 ;
V_45 = V_46 ;
}
}
}
if ( ! V_44 ) {
F_17 ( F_18 ( V_18 -> V_41 ) , L_1 ) ;
return - V_49 ;
}
return F_10 ( V_18 , V_45 - V_44 / 2 ) ;
}
static int F_19 ( struct V_50 * V_51 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_52 * V_52 ;
int V_53 ;
V_52 = F_20 ( & V_51 -> V_54 , NULL ) ;
if ( F_21 ( V_52 ) )
return F_22 ( V_52 ) ;
V_53 = F_23 ( V_52 ) ;
if ( V_53 )
return V_53 ;
V_18 = F_24 ( V_51 , & V_55 , sizeof( * V_2 ) ) ;
if ( F_21 ( V_18 ) ) {
V_53 = F_22 ( V_18 ) ;
goto V_56;
}
V_20 = F_4 ( V_18 ) ;
V_20 -> V_52 = V_52 ;
V_2 = V_1 ( V_18 ) ;
V_2 -> V_6 = V_18 -> V_57 ;
V_18 -> V_57 += V_58 ;
V_18 -> V_59 . V_60 = F_13 ;
V_53 = F_25 ( V_18 -> V_41 ) ;
if ( V_53 )
goto free;
F_3 ( V_2 ) ;
V_53 = F_26 ( V_18 ) ;
if ( V_53 )
goto free;
return 0 ;
free:
F_27 ( V_51 ) ;
V_56:
F_28 ( V_52 ) ;
return V_53 ;
}
