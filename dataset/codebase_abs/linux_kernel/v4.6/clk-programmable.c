static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , F_4 ( V_5 -> V_8 ) , & V_6 ) ;
return V_3 >> F_5 ( V_5 -> V_9 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_1 * V_12 ;
long V_13 = - V_14 ;
unsigned long V_3 ;
unsigned long V_15 ;
int V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_7 ( V_2 ) ; V_17 ++ ) {
V_12 = F_8 ( V_2 , V_17 ) ;
if ( ! V_12 )
continue;
V_3 = F_9 ( V_12 ) ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
V_15 = V_3 >> V_16 ;
if ( V_15 <= V_11 -> V_19 )
break;
}
if ( V_15 > V_11 -> V_19 )
continue;
if ( V_13 < 0 ||
( V_11 -> V_19 - V_15 ) < ( V_11 -> V_19 - V_13 ) ) {
V_13 = V_15 ;
V_11 -> V_20 = V_3 ;
V_11 -> V_21 = V_12 ;
}
if ( ! V_13 )
break;
}
if ( V_13 < 0 )
return V_13 ;
V_11 -> V_19 = V_13 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_23 * V_9 = V_5 -> V_9 ;
unsigned int V_24 = V_9 -> V_25 ;
unsigned int V_6 = 0 ;
if ( V_9 -> V_26 )
V_24 |= V_27 ;
if ( V_22 > V_9 -> V_25 ) {
if ( V_22 > V_28 && ! V_9 -> V_26 )
return - V_14 ;
V_6 |= V_27 ;
}
F_11 ( V_5 -> V_7 , F_4 ( V_5 -> V_8 ) , V_24 , V_6 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_23 * V_9 = V_5 -> V_9 ;
unsigned int V_6 ;
T_1 V_29 ;
F_3 ( V_5 -> V_7 , F_4 ( V_5 -> V_8 ) , & V_6 ) ;
V_29 = V_6 & V_9 -> V_25 ;
if ( V_9 -> V_26 && ( V_6 & V_27 ) && ! V_29 )
V_29 = V_28 + 1 ;
return V_29 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_23 * V_9 = V_5 -> V_9 ;
unsigned long div = V_3 / V_19 ;
unsigned int V_6 ;
int V_16 = 0 ;
F_3 ( V_5 -> V_7 , F_4 ( V_5 -> V_8 ) , & V_6 ) ;
if ( ! div )
return - V_14 ;
V_16 = F_14 ( div ) - 1 ;
if ( div != ( 1 << V_16 ) )
return - V_14 ;
if ( V_16 >= V_18 )
return - V_14 ;
F_11 ( V_5 -> V_7 , F_4 ( V_5 -> V_8 ) ,
V_18 << V_9 -> V_30 ,
V_16 << V_9 -> V_30 ) ;
return 0 ;
}
static struct V_31 * T_2
F_15 ( struct V_7 * V_7 ,
const char * V_32 , const char * * V_33 ,
T_1 V_34 , T_1 V_8 ,
const struct V_23 * V_9 )
{
struct V_4 * V_5 ;
struct V_31 * V_31 = NULL ;
struct V_35 V_36 ;
if ( V_8 > V_37 )
return F_16 ( - V_14 ) ;
V_5 = F_17 ( sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return F_16 ( - V_39 ) ;
V_36 . V_32 = V_32 ;
V_36 . V_40 = & V_41 ;
V_36 . V_33 = V_33 ;
V_36 . V_34 = V_34 ;
V_36 . V_42 = V_43 | V_44 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_2 . V_36 = & V_36 ;
V_5 -> V_7 = V_7 ;
V_31 = F_18 ( NULL , & V_5 -> V_2 ) ;
if ( F_19 ( V_31 ) )
F_20 ( V_5 ) ;
return V_31 ;
}
static void T_2
F_21 ( struct V_45 * V_46 ,
const struct V_23 * V_9 )
{
int V_47 ;
T_3 V_8 ;
struct V_31 * V_31 ;
unsigned int V_34 ;
const char * V_33 [ V_48 ] ;
const char * V_32 ;
struct V_45 * V_49 ;
struct V_7 * V_7 ;
V_34 = F_22 ( V_46 ) ;
if ( V_34 == 0 || V_34 > V_48 )
return;
F_23 ( V_46 , V_33 , V_34 ) ;
V_47 = F_24 ( V_46 ) ;
if ( ! V_47 || V_47 > ( V_37 + 1 ) )
return;
V_7 = F_25 ( F_26 ( V_46 ) ) ;
if ( F_19 ( V_7 ) )
return;
F_27 (np, progclknp) {
if ( F_28 ( V_49 , L_1 , & V_8 ) )
continue;
if ( F_29 ( V_46 , L_2 , & V_32 ) )
V_32 = V_49 -> V_32 ;
V_31 = F_15 ( V_7 , V_32 ,
V_33 , V_34 ,
V_8 , V_9 ) ;
if ( F_19 ( V_31 ) )
continue;
F_30 ( V_49 , V_50 , V_31 ) ;
}
}
static void T_2 F_31 ( struct V_45 * V_46 )
{
F_21 ( V_46 , & V_51 ) ;
}
static void T_2 F_32 ( struct V_45 * V_46 )
{
F_21 ( V_46 , & V_52 ) ;
}
static void T_2 F_33 ( struct V_45 * V_46 )
{
F_21 ( V_46 , & V_53 ) ;
}
