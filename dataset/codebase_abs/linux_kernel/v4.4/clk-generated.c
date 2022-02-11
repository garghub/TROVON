static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_3 ( L_1 ,
V_8 , V_4 -> V_9 , V_4 -> V_10 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_11 , ( V_4 -> V_12 & V_13 ) ) ;
V_7 = F_6 ( V_6 , V_11 ) &
~ ( V_14 | V_15 ) ;
F_5 ( V_6 , V_11 , V_7 | F_7 ( V_4 -> V_10 )
| V_16
| F_8 ( V_4 -> V_9 )
| V_17 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_11 , ( V_4 -> V_12 & V_13 ) ) ;
V_7 = F_6 ( V_6 , V_11 ) & ~ V_17 ;
F_5 ( V_6 , V_11 , V_7 | V_16 ) ;
F_9 ( V_6 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_18 ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_11 , ( V_4 -> V_12 & V_13 ) ) ;
V_18 = ! ! ( F_6 ( V_6 , V_11 ) & V_17 ) ;
F_9 ( V_6 ) ;
return V_18 ;
}
static unsigned long
F_12 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_13 ( V_19 , V_4 -> V_9 + 1 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_22 = NULL ;
long V_23 = - V_24 ;
unsigned long V_25 , V_26 ;
int V_27 = - 1 ;
int V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_15 ( V_2 ) ; V_29 ++ ) {
T_1 div ;
unsigned long V_19 ;
V_22 = F_16 ( V_2 , V_29 ) ;
if ( ! V_22 )
continue;
V_19 = F_17 ( V_22 ) ;
V_26 = F_13 ( V_19 , V_30 + 1 ) ;
if ( ! V_19 ||
( V_4 -> V_31 . V_32 && V_26 > V_4 -> V_31 . V_32 ) )
continue;
for ( div = 1 ; div < V_30 + 2 ; div ++ ) {
V_25 = F_13 ( V_19 , div ) ;
V_28 = abs ( V_21 -> V_33 - V_25 ) ;
if ( V_27 < 0 || V_27 > V_28 ) {
V_23 = V_25 ;
V_27 = V_28 ;
V_21 -> V_34 = V_19 ;
V_21 -> V_35 = V_22 ;
}
if ( ! V_27 || V_25 < V_21 -> V_33 )
break;
}
if ( ! V_27 )
break;
}
F_3 ( L_2 ,
V_8 , V_23 ,
F_18 ( ( V_21 -> V_35 ) -> V_36 ) ,
V_21 -> V_34 ) ;
if ( V_23 < 0 )
return V_23 ;
V_21 -> V_33 = V_23 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_37 >= F_15 ( V_2 ) )
return - V_24 ;
V_4 -> V_10 = V_37 ;
return 0 ;
}
static T_2 F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_10 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned long V_33 ,
unsigned long V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div ;
if ( ! V_33 )
return - V_24 ;
if ( V_4 -> V_31 . V_32 && V_33 > V_4 -> V_31 . V_32 )
return - V_24 ;
div = F_13 ( V_19 , V_33 ) ;
if ( div > V_30 + 1 || ! div )
return - V_24 ;
V_4 -> V_9 = div - 1 ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_11 , ( V_4 -> V_12 & V_13 ) ) ;
V_7 = F_6 ( V_6 , V_11 ) ;
F_9 ( V_6 ) ;
V_4 -> V_10 = ( V_7 & V_15 )
>> V_38 ;
V_4 -> V_9 = ( V_7 & V_14 )
>> V_39 ;
}
static struct V_36 * T_3
F_23 ( struct V_5 * V_6 , const char * V_40 ,
const char * * V_41 , T_2 V_42 ,
T_2 V_12 , const struct V_43 * V_31 )
{
struct V_3 * V_4 ;
struct V_36 * V_36 = NULL ;
struct V_44 V_45 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_47 ) ;
V_45 . V_40 = V_40 ;
V_45 . V_48 = & V_49 ;
V_45 . V_41 = V_41 ;
V_45 . V_42 = V_42 ;
V_45 . V_50 = V_51 | V_52 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_2 . V_45 = & V_45 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_31 = * V_31 ;
V_36 = F_26 ( NULL , & V_4 -> V_2 ) ;
if ( F_27 ( V_36 ) )
F_28 ( V_4 ) ;
else
F_22 ( V_4 ) ;
return V_36 ;
}
void T_3 F_29 ( struct V_53 * V_54 ,
struct V_5 * V_6 )
{
int V_55 ;
T_1 V_12 ;
const char * V_40 ;
struct V_36 * V_36 ;
int V_42 ;
const char * V_41 [ V_56 ] ;
struct V_53 * V_57 ;
struct V_43 V_31 = F_30 ( 0 , 0 ) ;
V_42 = F_31 ( V_54 ) ;
if ( V_42 <= 0 || V_42 > V_56 )
return;
F_32 ( V_54 , V_41 , V_42 ) ;
V_55 = F_33 ( V_54 ) ;
if ( ! V_55 || V_55 > V_58 )
return;
F_34 (np, gcknp) {
if ( F_35 ( V_57 , L_3 , & V_12 ) )
continue;
if ( V_12 < V_59 || V_12 >= V_58 )
continue;
if ( F_36 ( V_54 , L_4 , & V_40 ) )
V_40 = V_57 -> V_40 ;
F_37 ( V_57 , L_5 ,
& V_31 ) ;
V_36 = F_23 ( V_6 , V_40 , V_41 ,
V_42 , V_12 , & V_31 ) ;
if ( F_27 ( V_36 ) )
continue;
F_38 ( V_57 , V_60 , V_36 ) ;
}
}
