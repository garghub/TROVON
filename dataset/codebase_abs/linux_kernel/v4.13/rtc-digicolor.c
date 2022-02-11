static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , int V_4 )
{
T_1 V_5 ;
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
F_2 ( ( V_3 [ V_6 ] & V_8 ) | V_9 ,
V_2 -> V_10 + V_11 ) ;
V_7 = F_3 (
V_2 -> V_10 + V_11 , V_5 ,
! ( V_5 & V_9 ) , V_12 , V_13 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long * V_5 )
{
static const T_1 V_14 [] = { V_15 , V_16 } ;
T_2 V_17 , V_18 , V_19 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_14 , F_5 ( V_14 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_17 = F_6 ( V_2 -> V_10 + V_20 ) ;
V_18 = F_6 ( V_2 -> V_10 + V_21 ) ;
while ( 1 ) {
V_19 = F_6 ( V_2 -> V_10 + V_21 ) ;
if ( V_18 == V_19 )
break;
V_18 = V_19 ;
}
* V_5 = V_17 + V_18 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_5 )
{
static const T_1 V_22 [] = { V_23 , V_16 , V_24 , V_16 } ;
F_8 ( V_5 , V_2 -> V_10 + V_20 ) ;
return F_1 ( V_2 , V_22 , F_5 ( V_22 ) ) ;
}
static int F_9 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
unsigned long V_29 ;
int V_7 ;
V_7 = F_4 ( V_2 , & V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
F_11 ( V_29 , V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 , unsigned long V_30 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
return F_7 ( V_2 , V_30 ) ;
}
static int F_13 ( struct V_25 * V_26 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
T_2 V_33 , V_17 ;
unsigned long V_29 ;
int V_7 ;
V_33 = F_6 ( V_2 -> V_10 + V_34 ) ;
V_17 = F_6 ( V_2 -> V_10 + V_20 ) ;
F_11 ( V_17 + V_33 , & V_32 -> time ) ;
V_7 = F_4 ( V_2 , & V_29 ) ;
if ( V_7 < 0 )
return V_7 ;
V_32 -> V_35 = V_33 + V_17 > V_29 ;
V_32 -> V_36 = F_6 ( V_2 -> V_10 + V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
T_3 V_38 ;
T_2 V_17 ;
V_38 = F_15 ( & V_32 -> time ) ;
V_17 = F_6 ( V_2 -> V_10 + V_20 ) ;
F_8 ( V_38 - V_17 , V_2 -> V_10 + V_34 ) ;
F_2 ( ! ! V_32 -> V_36 , V_2 -> V_10 + V_37 ) ;
return 0 ;
}
static int F_16 ( struct V_25 * V_26 , unsigned int V_36 )
{
struct V_1 * V_2 = F_10 ( V_26 ) ;
F_2 ( ! ! V_36 , V_2 -> V_10 + V_37 ) ;
return 0 ;
}
static T_4 F_17 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
F_2 ( 1 , V_2 -> V_10 + V_41 ) ;
F_18 ( V_2 -> V_42 , 1 , V_43 | V_44 ) ;
return V_45 ;
}
static int T_5 F_19 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_1 * V_2 ;
int V_39 , V_7 ;
V_2 = F_20 ( & V_47 -> V_26 , sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_49 = F_21 ( V_47 , V_52 , 0 ) ;
V_2 -> V_10 = F_22 ( & V_47 -> V_26 , V_49 ) ;
if ( F_23 ( V_2 -> V_10 ) )
return F_24 ( V_2 -> V_10 ) ;
V_39 = F_25 ( V_47 , 0 ) ;
if ( V_39 < 0 )
return V_39 ;
V_7 = F_26 ( & V_47 -> V_26 , V_39 , F_17 , 0 , V_47 -> V_53 , V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_27 ( V_47 , V_2 ) ;
V_2 -> V_42 = F_28 ( & V_47 -> V_26 , V_47 -> V_53 ,
& V_54 , V_55 ) ;
if ( F_23 ( V_2 -> V_42 ) )
return F_24 ( V_2 -> V_42 ) ;
return 0 ;
}
