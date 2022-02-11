static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
V_4 = ( F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) >> V_10 -> V_12 ) &
V_13 ;
return V_3 >> V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_1 * V_16 ;
long V_17 = - V_18 ;
unsigned long V_3 ;
unsigned long V_19 ;
int V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_6 ( V_2 ) ; V_21 ++ ) {
V_16 = F_7 ( V_2 , V_21 ) ;
if ( ! V_16 )
continue;
V_3 = F_8 ( V_16 ) ;
for ( V_20 = 0 ; V_20 < V_13 ; V_20 ++ ) {
V_19 = V_3 >> V_20 ;
if ( V_19 <= V_15 -> V_22 )
break;
}
if ( V_19 > V_15 -> V_22 )
continue;
if ( V_17 < 0 ||
( V_15 -> V_22 - V_19 ) < ( V_15 -> V_22 - V_17 ) ) {
V_17 = V_19 ;
V_15 -> V_23 = V_3 ;
V_15 -> V_24 = V_16 ;
}
if ( ! V_17 )
break;
}
if ( V_17 < 0 )
return V_17 ;
V_15 -> V_22 = V_17 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_26 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) & ~ V_10 -> V_27 ;
if ( V_10 -> V_28 )
V_26 &= V_29 ;
if ( V_25 > V_10 -> V_27 ) {
if ( V_25 > V_30 && V_10 -> V_28 ) {
V_26 |= V_29 ;
return 0 ;
} else {
return - V_18 ;
}
}
F_10 ( V_8 , F_4 ( V_6 -> V_11 ) , V_26 | V_25 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
T_1 V_26 ;
T_2 V_31 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
V_26 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) ;
V_31 = V_26 & V_10 -> V_27 ;
if ( V_10 -> V_28 && ( V_26 & V_29 ) && ! V_31 )
V_31 = V_30 + 1 ;
return V_31 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
unsigned long div = V_3 / V_22 ;
int V_20 = 0 ;
T_1 V_26 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) &
~ ( V_13 << V_10 -> V_12 ) ;
if ( ! div )
return - V_18 ;
V_20 = F_13 ( div ) - 1 ;
if ( div != ( 1 << V_20 ) )
return - V_18 ;
if ( V_20 >= V_13 )
return - V_18 ;
F_10 ( V_8 , F_4 ( V_6 -> V_11 ) ,
V_26 | ( V_20 << V_10 -> V_12 ) ) ;
return 0 ;
}
static struct V_32 * T_3
F_14 ( struct V_7 * V_8 ,
const char * V_33 , const char * * V_34 ,
T_2 V_35 , T_2 V_11 ,
const struct V_9 * V_10 )
{
struct V_5 * V_6 ;
struct V_32 * V_32 = NULL ;
struct V_36 V_37 ;
if ( V_11 > V_38 )
return F_15 ( - V_18 ) ;
V_6 = F_16 ( sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return F_15 ( - V_40 ) ;
V_37 . V_33 = V_33 ;
V_37 . V_41 = & V_42 ;
V_37 . V_34 = V_34 ;
V_37 . V_35 = V_35 ;
V_37 . V_43 = V_44 | V_45 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_2 . V_37 = & V_37 ;
V_6 -> V_8 = V_8 ;
V_32 = F_17 ( NULL , & V_6 -> V_2 ) ;
if ( F_18 ( V_32 ) )
F_19 ( V_6 ) ;
return V_32 ;
}
static void T_3
F_20 ( struct V_46 * V_47 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
int V_48 ;
T_1 V_11 ;
struct V_32 * V_32 ;
int V_35 ;
const char * V_34 [ V_49 ] ;
const char * V_33 ;
struct V_46 * V_50 ;
V_35 = F_21 ( V_47 ) ;
if ( V_35 <= 0 || V_35 > V_49 )
return;
F_22 ( V_47 , V_34 , V_35 ) ;
V_48 = F_23 ( V_47 ) ;
if ( ! V_48 || V_48 > ( V_38 + 1 ) )
return;
F_24 (np, progclknp) {
if ( F_25 ( V_50 , L_1 , & V_11 ) )
continue;
if ( F_26 ( V_47 , L_2 , & V_33 ) )
V_33 = V_50 -> V_33 ;
V_32 = F_14 ( V_8 , V_33 ,
V_34 , V_35 ,
V_11 , V_10 ) ;
if ( F_18 ( V_32 ) )
continue;
F_27 ( V_50 , V_51 , V_32 ) ;
}
}
void T_3 F_28 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
F_20 ( V_47 , V_8 , & V_52 ) ;
}
void T_3 F_29 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
F_20 ( V_47 , V_8 , & V_53 ) ;
}
void T_3 F_30 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
F_20 ( V_47 , V_8 , & V_54 ) ;
}
