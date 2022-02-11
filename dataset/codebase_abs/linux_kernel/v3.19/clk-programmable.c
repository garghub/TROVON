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
unsigned long * V_15 ,
struct V_1 * * V_16 )
{
struct V_17 * V_18 = NULL ;
long V_19 = - V_20 ;
unsigned long V_3 ;
unsigned long V_21 ;
int V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_6 ( V_2 -> V_17 ) ; V_23 ++ ) {
V_18 = F_7 ( V_2 -> V_17 , V_23 ) ;
if ( ! V_18 )
continue;
V_3 = F_8 ( V_18 ) ;
for ( V_22 = 0 ; V_22 < V_13 ; V_22 ++ ) {
V_21 = V_3 >> V_22 ;
if ( V_21 <= V_14 )
break;
}
if ( V_21 > V_14 )
continue;
if ( V_19 < 0 || ( V_14 - V_21 ) < ( V_14 - V_19 ) ) {
V_19 = V_21 ;
* V_15 = V_3 ;
* V_16 = F_9 ( V_18 ) ;
}
if ( ! V_19 )
break;
}
return V_19 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_25 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) & ~ V_10 -> V_26 ;
if ( V_10 -> V_27 )
V_25 &= V_28 ;
if ( V_24 > V_10 -> V_26 ) {
if ( V_24 > V_29 && V_10 -> V_27 ) {
V_25 |= V_28 ;
return 0 ;
} else {
return - V_20 ;
}
}
F_11 ( V_8 , F_4 ( V_6 -> V_11 ) , V_25 | V_24 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_2 V_30 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
V_25 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) ;
V_30 = V_25 & V_10 -> V_26 ;
if ( V_10 -> V_27 && ( V_25 & V_28 ) && ! V_30 )
V_30 = V_29 + 1 ;
return V_30 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned long V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_10 ;
unsigned long div = V_3 / V_14 ;
int V_22 = 0 ;
T_1 V_25 = F_3 ( V_8 , F_4 ( V_6 -> V_11 ) ) &
~ ( V_13 << V_10 -> V_12 ) ;
if ( ! div )
return - V_20 ;
V_22 = F_14 ( div ) - 1 ;
if ( div != ( 1 << V_22 ) )
return - V_20 ;
if ( V_22 >= V_13 )
return - V_20 ;
F_11 ( V_8 , F_4 ( V_6 -> V_11 ) ,
V_25 | ( V_22 << V_10 -> V_12 ) ) ;
return 0 ;
}
static struct V_17 * T_3
F_15 ( struct V_7 * V_8 ,
const char * V_31 , const char * * V_32 ,
T_2 V_33 , T_2 V_11 ,
const struct V_9 * V_10 )
{
struct V_5 * V_6 ;
struct V_17 * V_17 = NULL ;
struct V_34 V_35 ;
if ( V_11 > V_36 )
return F_16 ( - V_20 ) ;
V_6 = F_17 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return F_16 ( - V_38 ) ;
V_35 . V_31 = V_31 ;
V_35 . V_39 = & V_40 ;
V_35 . V_32 = V_32 ;
V_35 . V_33 = V_33 ;
V_35 . V_41 = V_42 | V_43 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_2 . V_35 = & V_35 ;
V_6 -> V_8 = V_8 ;
V_17 = F_18 ( NULL , & V_6 -> V_2 ) ;
if ( F_19 ( V_17 ) )
F_20 ( V_6 ) ;
return V_17 ;
}
static void T_3
F_21 ( struct V_44 * V_45 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
int V_46 ;
T_1 V_11 ;
int V_23 ;
struct V_17 * V_17 ;
int V_33 ;
const char * V_32 [ V_47 ] ;
const char * V_31 ;
struct V_44 * V_48 ;
V_33 = F_22 ( V_45 , L_1 , L_2 ) ;
if ( V_33 <= 0 || V_33 > V_47 )
return;
for ( V_23 = 0 ; V_23 < V_33 ; ++ V_23 ) {
V_32 [ V_23 ] = F_23 ( V_45 , V_23 ) ;
if ( ! V_32 [ V_23 ] )
return;
}
V_46 = F_24 ( V_45 ) ;
if ( ! V_46 || V_46 > ( V_36 + 1 ) )
return;
F_25 (np, progclknp) {
if ( F_26 ( V_48 , L_3 , & V_11 ) )
continue;
if ( F_27 ( V_45 , L_4 , & V_31 ) )
V_31 = V_48 -> V_31 ;
V_17 = F_15 ( V_8 , V_31 ,
V_32 , V_33 ,
V_11 , V_10 ) ;
if ( F_19 ( V_17 ) )
continue;
F_28 ( V_48 , V_49 , V_17 ) ;
}
}
void T_3 F_29 ( struct V_44 * V_45 ,
struct V_7 * V_8 )
{
F_21 ( V_45 , V_8 , & V_50 ) ;
}
void T_3 F_30 ( struct V_44 * V_45 ,
struct V_7 * V_8 )
{
F_21 ( V_45 , V_8 , & V_51 ) ;
}
void T_3 F_31 ( struct V_44 * V_45 ,
struct V_7 * V_8 )
{
F_21 ( V_45 , V_8 , & V_52 ) ;
}
