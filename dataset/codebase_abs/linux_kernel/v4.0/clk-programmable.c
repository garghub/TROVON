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
static long F_5 ( struct V_1 * V_2 ,
unsigned long V_14 ,
unsigned long V_15 ,
unsigned long V_16 ,
unsigned long * V_17 ,
struct V_1 * * V_18 )
{
struct V_19 * V_20 = NULL ;
long V_21 = - V_22 ;
unsigned long V_3 ;
unsigned long V_23 ;
int V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_6 ( V_2 -> V_19 ) ; V_25 ++ ) {
V_20 = F_7 ( V_2 -> V_19 , V_25 ) ;
if ( ! V_20 )
continue;
V_3 = F_8 ( V_20 ) ;
for ( V_24 = 0 ; V_24 < V_13 ; V_24 ++ ) {
V_23 = V_3 >> V_24 ;
if ( V_23 <= V_14 )
break;
}
if ( V_23 > V_14 )
continue;
if ( V_21 < 0 || ( V_14 - V_23 ) < ( V_14 - V_21 ) ) {
V_21 = V_23 ;
* V_17 = V_3 ;
* V_18 = F_9 ( V_20 ) ;
}
if ( ! V_21 )
break;
}
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) & ~ V_10 -> V_28 ;
if ( V_10 -> V_29 )
V_27 &= V_30 ;
if ( V_26 > V_10 -> V_28 ) {
if ( V_26 > V_31 && V_10 -> V_29 ) {
V_27 |= V_30 ;
return 0 ;
} else {
return - V_22 ;
}
}
F_11 ( V_8 , F_4 ( V_6 -> V_11 ) , V_27 | V_26 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
T_1 V_27 ;
T_2 V_32 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
V_27 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) ;
V_32 = V_27 & V_10 -> V_28 ;
if ( V_10 -> V_29 && ( V_27 & V_30 ) && ! V_32 )
V_32 = V_31 + 1 ;
return V_32 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned long V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
unsigned long div = V_3 / V_14 ;
int V_24 = 0 ;
T_1 V_27 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) &
~ ( V_13 << V_10 -> V_12 ) ;
if ( ! div )
return - V_22 ;
V_24 = F_14 ( div ) - 1 ;
if ( div != ( 1 << V_24 ) )
return - V_22 ;
if ( V_24 >= V_13 )
return - V_22 ;
F_11 ( V_8 , F_4 ( V_6 -> V_11 ) ,
V_27 | ( V_24 << V_10 -> V_12 ) ) ;
return 0 ;
}
static struct V_19 * T_3
F_15 ( struct V_7 * V_8 ,
const char * V_33 , const char * * V_34 ,
T_2 V_35 , T_2 V_11 ,
const struct V_9 * V_10 )
{
struct V_5 * V_6 ;
struct V_19 * V_19 = NULL ;
struct V_36 V_37 ;
if ( V_11 > V_38 )
return F_16 ( - V_22 ) ;
V_6 = F_17 ( sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return F_16 ( - V_40 ) ;
V_37 . V_33 = V_33 ;
V_37 . V_41 = & V_42 ;
V_37 . V_34 = V_34 ;
V_37 . V_35 = V_35 ;
V_37 . V_43 = V_44 | V_45 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_2 . V_37 = & V_37 ;
V_6 -> V_8 = V_8 ;
V_19 = F_18 ( NULL , & V_6 -> V_2 ) ;
if ( F_19 ( V_19 ) )
F_20 ( V_6 ) ;
return V_19 ;
}
static void T_3
F_21 ( struct V_46 * V_47 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
int V_48 ;
T_1 V_11 ;
int V_25 ;
struct V_19 * V_19 ;
int V_35 ;
const char * V_34 [ V_49 ] ;
const char * V_33 ;
struct V_46 * V_50 ;
V_35 = F_22 ( V_47 , L_1 , L_2 ) ;
if ( V_35 <= 0 || V_35 > V_49 )
return;
for ( V_25 = 0 ; V_25 < V_35 ; ++ V_25 ) {
V_34 [ V_25 ] = F_23 ( V_47 , V_25 ) ;
if ( ! V_34 [ V_25 ] )
return;
}
V_48 = F_24 ( V_47 ) ;
if ( ! V_48 || V_48 > ( V_38 + 1 ) )
return;
F_25 (np, progclknp) {
if ( F_26 ( V_50 , L_3 , & V_11 ) )
continue;
if ( F_27 ( V_47 , L_4 , & V_33 ) )
V_33 = V_50 -> V_33 ;
V_19 = F_15 ( V_8 , V_33 ,
V_34 , V_35 ,
V_11 , V_10 ) ;
if ( F_19 ( V_19 ) )
continue;
F_28 ( V_50 , V_51 , V_19 ) ;
}
}
void T_3 F_29 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
F_21 ( V_47 , V_8 , & V_52 ) ;
}
void T_3 F_30 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
F_21 ( V_47 , V_8 , & V_53 ) ;
}
void T_3 F_31 ( struct V_46 * V_47 ,
struct V_7 * V_8 )
{
F_21 ( V_47 , V_8 , & V_54 ) ;
}
