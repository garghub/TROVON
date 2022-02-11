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
static unsigned int F_4 ( struct V_14 * V_15 )
{
unsigned int V_16 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_5 ( V_18 ) ; V_17 ++ )
if ( F_6 ( V_15 , V_18 [ V_17 ] . V_19 ) )
V_16 ++ ;
return V_16 ;
}
static void F_7 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_22 ;
T_3 V_23 ;
int V_9 , V_17 ;
for ( V_17 = 0 ; V_17 < F_5 ( V_18 ) ; V_17 ++ ) {
V_9 = F_8 ( V_15 , V_18 [ V_17 ] . V_19 ,
& V_23 ) ;
if ( V_9 )
continue;
V_21 -> V_3 = V_18 [ V_17 ] . V_3 ;
V_21 -> V_4 = V_23 ;
V_21 ++ ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
int V_9 , V_17 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_24 ; V_17 ++ ) {
V_9 = F_1 ( V_2 , V_2 -> V_22 [ V_17 ] . V_3 ,
V_2 -> V_22 [ V_17 ] . V_4 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static inline void * V_1 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_10 ( V_26 ) ;
return F_11 ( V_28 ) ;
}
static unsigned int F_12 ( struct V_25 * V_26 )
{
return V_26 -> V_29 ;
}
static void F_13 ( struct V_1 * V_2 , T_3 V_30 )
{
T_3 V_8 ;
V_8 = F_14 ( V_2 -> V_6 + V_31 ) ;
V_8 &= ~ V_32 ;
V_8 |= V_30 ;
F_2 ( V_8 , V_2 -> V_6 + V_31 ) ;
}
static T_3 F_15 ( struct V_1 * V_2 )
{
T_3 V_8 ;
V_8 = F_14 ( V_2 -> V_6 + V_31 ) ;
return V_8 & V_32 ;
}
static void F_16 ( struct V_25 * V_26 ,
unsigned int V_33 )
{
struct V_1 * V_2 = V_1 ( V_26 ) ;
T_3 V_30 ;
switch ( V_33 ) {
case V_34 :
V_30 = V_35 ;
break;
case V_36 :
V_30 = V_37 ;
break;
case V_38 :
V_30 = V_39 ;
break;
case V_40 :
if ( V_2 -> V_41 )
V_30 = V_42 ;
else
V_30 = V_43 ;
break;
default:
V_30 = V_44 ;
break;
}
F_13 ( V_2 , V_30 ) ;
if ( V_30 == V_44 )
F_17 ( V_26 , V_33 ) ;
}
static int F_18 ( struct V_25 * V_26 , unsigned int V_23 )
{
struct V_1 * V_2 = V_1 ( V_26 ) ;
void T_2 * V_5 = V_2 -> V_6 + V_31 ;
T_3 V_8 ;
if ( F_19 ( V_23 > V_45 ) )
return - V_46 ;
V_8 = F_14 ( V_5 ) ;
V_8 &= ~ ( V_45 << V_47 ) ;
V_8 |= V_23 << V_47 ;
V_8 |= V_48 ;
F_2 ( V_8 , V_5 ) ;
return F_3 ( V_5 , V_8 , ! ( V_8 & V_48 ) ,
0 , 1 ) ;
}
static int F_20 ( struct V_49 * V_50 , T_3 V_51 )
{
struct V_25 * V_26 = F_21 ( V_50 ) ;
int V_52 = 0 ;
int V_53 = 0 ;
int V_54 = 0 ;
int V_17 ;
if ( V_26 -> V_33 != V_38 )
return F_22 ( V_50 , V_51 ) ;
if ( F_19 ( V_51 != V_55 ) )
return - V_46 ;
for ( V_17 = 0 ; V_17 < V_56 ; V_17 ++ ) {
if ( F_18 ( V_26 , V_17 ) ||
F_23 ( V_26 -> V_50 , V_51 , NULL ) ) {
V_52 = 0 ;
} else {
V_52 ++ ;
if ( V_52 > V_53 ) {
V_53 = V_52 ;
V_54 = V_17 ;
}
}
}
if ( ! V_53 ) {
F_24 ( F_25 ( V_26 -> V_50 ) , L_1 ) ;
return - V_57 ;
}
return F_18 ( V_26 , V_54 - V_53 / 2 ) ;
}
static void F_26 ( struct V_49 * V_50 ,
struct V_58 * V_59 )
{
struct V_25 * V_26 = F_21 ( V_50 ) ;
struct V_1 * V_2 = V_1 ( V_26 ) ;
T_3 V_30 ;
V_2 -> V_41 = V_59 -> V_41 ;
V_30 = F_15 ( V_2 ) ;
if ( V_30 == V_43 && V_59 -> V_41 )
F_13 ( V_2 ,
V_42 ) ;
if ( V_30 == V_42 && ! V_59 -> V_41 )
F_13 ( V_2 ,
V_43 ) ;
}
static int F_27 ( struct V_60 * V_61 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
struct V_62 * V_62 ;
T_4 V_63 ;
unsigned int V_24 ;
int V_9 ;
struct V_64 * V_65 = & V_61 -> V_65 ;
V_62 = F_28 ( V_65 , NULL ) ;
if ( F_29 ( V_62 ) )
return F_30 ( V_62 ) ;
V_9 = F_31 ( V_62 ) ;
if ( V_9 )
return V_9 ;
V_24 = F_4 ( V_65 -> V_66 ) ;
V_63 = sizeof( * V_2 ) + sizeof( V_2 -> V_22 [ 0 ] ) * V_24 ;
V_26 = F_32 ( V_61 , & V_67 , V_63 ) ;
if ( F_29 ( V_26 ) ) {
V_9 = F_30 ( V_26 ) ;
goto V_68;
}
V_28 = F_10 ( V_26 ) ;
V_28 -> V_62 = V_62 ;
V_2 = F_11 ( V_28 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_6 = V_26 -> V_69 ;
V_2 -> V_41 = false ;
V_26 -> V_69 += V_70 ;
V_26 -> V_71 . V_72 = F_20 ;
V_26 -> V_71 . V_73 =
F_26 ;
F_33 ( V_61 ) ;
V_9 = F_34 ( V_26 -> V_50 ) ;
if ( V_9 )
goto free;
F_7 ( V_65 -> V_66 , V_2 ) ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 )
goto free;
V_9 = F_35 ( V_26 ) ;
if ( V_9 )
goto free;
return 0 ;
free:
F_36 ( V_61 ) ;
V_68:
F_37 ( V_62 ) ;
return V_9 ;
}
static int F_38 ( struct V_64 * V_65 )
{
struct V_25 * V_26 = F_39 ( V_65 ) ;
struct V_27 * V_28 = F_10 ( V_26 ) ;
struct V_1 * V_2 = F_11 ( V_28 ) ;
int V_9 ;
V_9 = F_31 ( V_28 -> V_62 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_9 ( V_2 ) ;
if ( V_9 )
goto V_68;
V_9 = F_40 ( V_26 ) ;
if ( V_9 )
goto V_68;
return 0 ;
V_68:
F_37 ( V_28 -> V_62 ) ;
return V_9 ;
}
