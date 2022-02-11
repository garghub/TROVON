static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_3 ( L_1 ,
V_6 , V_4 -> V_7 , V_4 -> V_8 ) ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_6 ( V_4 -> V_10 , V_11 ,
V_14 | V_15 |
V_16 | V_17 ,
F_7 ( V_4 -> V_8 ) |
V_16 |
F_8 ( V_4 -> V_7 ) |
V_17 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_6 ( V_4 -> V_10 , V_11 ,
V_16 | V_17 ,
V_16 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
unsigned int V_18 ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_12 ( V_4 -> V_10 , V_11 , & V_18 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
return V_18 & V_17 ? 1 : 0 ;
}
static unsigned long
F_13 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_14 ( V_19 , V_4 -> V_7 + 1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_22 = NULL ;
long V_23 = - V_24 ;
unsigned long V_25 , V_26 ;
int V_27 = - 1 ;
int V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_16 ( V_2 ) ; V_29 ++ ) {
T_1 div ;
unsigned long V_19 ;
V_22 = F_17 ( V_2 , V_29 ) ;
if ( ! V_22 )
continue;
V_19 = F_18 ( V_22 ) ;
V_26 = F_14 ( V_19 , V_30 + 1 ) ;
if ( ! V_19 ||
( V_4 -> V_31 . V_32 && V_26 > V_4 -> V_31 . V_32 ) )
continue;
for ( div = 1 ; div < V_30 + 2 ; div ++ ) {
V_25 = F_14 ( V_19 , div ) ;
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
V_6 , V_23 ,
F_19 ( ( V_21 -> V_35 ) -> V_36 ) ,
V_21 -> V_34 ) ;
if ( V_23 < 0 )
return V_23 ;
V_21 -> V_33 = V_23 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_37 >= F_16 ( V_2 ) )
return - V_24 ;
V_4 -> V_8 = V_37 ;
return 0 ;
}
static T_2 F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_33 ,
unsigned long V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div ;
if ( ! V_33 )
return - V_24 ;
if ( V_4 -> V_31 . V_32 && V_33 > V_4 -> V_31 . V_32 )
return - V_24 ;
div = F_14 ( V_19 , V_33 ) ;
if ( div > V_30 + 1 || ! div )
return - V_24 ;
V_4 -> V_7 = div - 1 ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 )
{
T_1 V_38 ;
unsigned long V_5 ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_12 ( V_4 -> V_10 , V_11 , & V_38 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
V_4 -> V_8 = ( V_38 & V_15 )
>> V_39 ;
V_4 -> V_7 = ( V_38 & V_14 )
>> V_40 ;
}
static struct V_1 * T_3
F_24 ( struct V_10 * V_10 , T_4 * V_9 ,
const char * V_41 , const char * * V_42 ,
T_2 V_43 , T_2 V_12 ,
const struct V_44 * V_31 )
{
struct V_3 * V_4 ;
struct V_45 V_46 ;
struct V_1 * V_2 ;
int V_47 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return F_26 ( - V_49 ) ;
V_46 . V_41 = V_41 ;
V_46 . V_50 = & V_51 ;
V_46 . V_42 = V_42 ;
V_46 . V_43 = V_43 ;
V_46 . V_5 = V_52 | V_53 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_2 . V_46 = & V_46 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_31 = * V_31 ;
V_2 = & V_4 -> V_2 ;
V_47 = F_27 ( NULL , & V_4 -> V_2 ) ;
if ( V_47 ) {
F_28 ( V_4 ) ;
V_2 = F_26 ( V_47 ) ;
} else
F_23 ( V_4 ) ;
return V_2 ;
}
static void T_3 F_29 ( struct V_54 * V_55 )
{
int V_56 ;
T_1 V_12 ;
const char * V_41 ;
struct V_1 * V_2 ;
unsigned int V_43 ;
const char * V_42 [ V_57 ] ;
struct V_54 * V_58 ;
struct V_44 V_31 = F_30 ( 0 , 0 ) ;
struct V_10 * V_10 ;
V_43 = F_31 ( V_55 ) ;
if ( V_43 == 0 || V_43 > V_57 )
return;
F_32 ( V_55 , V_42 , V_43 ) ;
V_56 = F_33 ( V_55 ) ;
if ( ! V_56 || V_56 > V_59 )
return;
V_10 = F_34 ( F_35 ( V_55 ) ) ;
if ( F_36 ( V_10 ) )
return;
F_37 (np, gcknp) {
if ( F_38 ( V_58 , L_3 , & V_12 ) )
continue;
if ( V_12 < V_60 || V_12 >= V_59 )
continue;
if ( F_39 ( V_55 , L_4 , & V_41 ) )
V_41 = V_58 -> V_41 ;
F_40 ( V_58 , L_5 ,
& V_31 ) ;
V_2 = F_24 ( V_10 , & V_61 , V_41 ,
V_42 , V_43 ,
V_12 , & V_31 ) ;
if ( F_36 ( V_2 ) )
continue;
F_41 ( V_58 , V_62 , V_2 ) ;
}
}
