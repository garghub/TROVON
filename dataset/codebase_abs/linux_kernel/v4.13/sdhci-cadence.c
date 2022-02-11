static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_7 ;
T_3 V_8 ;
int V_9 ;
V_8 = ( V_4 << V_10 ) |
( V_3 << V_11 ) ;
F_2 ( V_8 , V_5 ) ;
V_8 |= V_12 ;
F_2 ( V_8 , V_5 ) ;
V_9 = F_3 ( V_5 , V_8 , V_8 & V_13 , 0 , 10 ) ;
if ( V_9 )
return V_9 ;
V_8 &= ~ V_12 ;
F_2 ( V_8 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
T_3 V_16 ;
int V_9 , V_17 ;
for ( V_17 = 0 ; V_17 < F_5 ( V_18 ) ; V_17 ++ ) {
V_9 = F_6 ( V_15 , V_18 [ V_17 ] . V_19 ,
& V_16 ) ;
if ( V_9 )
continue;
V_9 = F_1 ( V_2 ,
V_18 [ V_17 ] . V_3 ,
V_16 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static inline void * V_1 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_21 ) ;
return F_8 ( V_23 ) ;
}
static unsigned int F_9 ( struct V_20 * V_21 )
{
return V_21 -> V_24 ;
}
static void F_10 ( struct V_1 * V_2 , T_3 V_25 )
{
T_3 V_8 ;
V_8 = F_11 ( V_2 -> V_6 + V_26 ) ;
V_8 &= ~ V_27 ;
V_8 |= V_25 ;
F_2 ( V_8 , V_2 -> V_6 + V_26 ) ;
}
static T_3 F_12 ( struct V_1 * V_2 )
{
T_3 V_8 ;
V_8 = F_11 ( V_2 -> V_6 + V_26 ) ;
return V_8 & V_27 ;
}
static void F_13 ( struct V_20 * V_21 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_1 ( V_21 ) ;
T_3 V_25 ;
switch ( V_28 ) {
case V_29 :
V_25 = V_30 ;
break;
case V_31 :
V_25 = V_32 ;
break;
case V_33 :
V_25 = V_34 ;
break;
case V_35 :
if ( V_2 -> V_36 )
V_25 = V_37 ;
else
V_25 = V_38 ;
break;
default:
V_25 = V_39 ;
break;
}
F_10 ( V_2 , V_25 ) ;
if ( V_25 == V_39 )
F_14 ( V_21 , V_28 ) ;
}
static int F_15 ( struct V_20 * V_21 , unsigned int V_16 )
{
struct V_1 * V_2 = V_1 ( V_21 ) ;
void T_2 * V_5 = V_2 -> V_6 + V_26 ;
T_3 V_8 ;
if ( F_16 ( V_16 > V_40 ) )
return - V_41 ;
V_8 = F_11 ( V_5 ) ;
V_8 &= ~ ( V_40 << V_42 ) ;
V_8 |= V_16 << V_42 ;
V_8 |= V_43 ;
F_2 ( V_8 , V_5 ) ;
return F_3 ( V_5 , V_8 , ! ( V_8 & V_43 ) ,
0 , 1 ) ;
}
static int F_17 ( struct V_44 * V_45 , T_3 V_46 )
{
struct V_20 * V_21 = F_18 ( V_45 ) ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 = 0 ;
int V_17 ;
if ( V_21 -> V_28 != V_33 )
return F_19 ( V_45 , V_46 ) ;
if ( F_16 ( V_46 != V_50 ) )
return - V_41 ;
for ( V_17 = 0 ; V_17 < V_51 ; V_17 ++ ) {
if ( F_15 ( V_21 , V_17 ) ||
F_20 ( V_21 -> V_45 , V_46 , NULL ) ) {
V_47 = 0 ;
} else {
V_47 ++ ;
if ( V_47 > V_48 ) {
V_48 = V_47 ;
V_49 = V_17 ;
}
}
}
if ( ! V_48 ) {
F_21 ( F_22 ( V_21 -> V_45 ) , L_1 ) ;
return - V_52 ;
}
return F_15 ( V_21 , V_49 - V_48 / 2 ) ;
}
static void F_23 ( struct V_44 * V_45 ,
struct V_53 * V_54 )
{
struct V_20 * V_21 = F_18 ( V_45 ) ;
struct V_1 * V_2 = V_1 ( V_21 ) ;
T_3 V_25 ;
V_2 -> V_36 = V_54 -> V_36 ;
V_25 = F_12 ( V_2 ) ;
if ( V_25 == V_38 && V_54 -> V_36 )
F_10 ( V_2 ,
V_37 ) ;
if ( V_25 == V_37 && ! V_54 -> V_36 )
F_10 ( V_2 ,
V_38 ) ;
}
static int F_24 ( struct V_55 * V_56 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_57 * V_57 ;
int V_9 ;
struct V_58 * V_59 = & V_56 -> V_59 ;
V_57 = F_25 ( V_59 , NULL ) ;
if ( F_26 ( V_57 ) )
return F_27 ( V_57 ) ;
V_9 = F_28 ( V_57 ) ;
if ( V_9 )
return V_9 ;
V_21 = F_29 ( V_56 , & V_60 , sizeof( * V_2 ) ) ;
if ( F_26 ( V_21 ) ) {
V_9 = F_27 ( V_21 ) ;
goto V_61;
}
V_23 = F_7 ( V_21 ) ;
V_23 -> V_57 = V_57 ;
V_2 = V_1 ( V_21 ) ;
V_2 -> V_6 = V_21 -> V_62 ;
V_2 -> V_36 = false ;
V_21 -> V_62 += V_63 ;
V_21 -> V_64 . V_65 = F_17 ;
V_21 -> V_64 . V_66 =
F_23 ;
F_30 ( V_56 ) ;
V_9 = F_31 ( V_21 -> V_45 ) ;
if ( V_9 )
goto free;
V_9 = F_4 ( V_59 -> V_67 , V_2 ) ;
if ( V_9 )
goto free;
V_9 = F_32 ( V_21 ) ;
if ( V_9 )
goto free;
return 0 ;
free:
F_33 ( V_56 ) ;
V_61:
F_34 ( V_57 ) ;
return V_9 ;
}
