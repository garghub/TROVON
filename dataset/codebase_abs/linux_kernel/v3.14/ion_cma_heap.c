static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_5 , T_1 V_6 , T_2 V_7 )
{
struct V_8 * V_8 = F_2 ( V_5 ) ;
int V_9 ;
V_9 = F_3 ( V_4 , 1 , V_10 ) ;
if ( F_4 ( V_9 ) )
return V_9 ;
F_5 ( V_4 -> V_11 , V_8 , F_6 ( V_7 ) , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 , struct V_14 * V_15 ,
unsigned long V_16 , unsigned long V_17 ,
unsigned long V_18 )
{
struct V_19 * V_20 = F_8 ( V_13 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 ;
F_9 ( V_2 , L_1 , V_16 ) ;
if ( V_15 -> V_18 & V_23 )
return - V_24 ;
if ( V_17 > V_25 )
return - V_24 ;
V_22 = F_10 ( sizeof( struct V_21 ) , V_10 ) ;
if ( ! V_22 ) {
F_11 ( V_2 , L_2 ) ;
return V_26 ;
}
V_22 -> V_5 = F_12 ( V_2 , V_16 , & ( V_22 -> V_6 ) ,
V_27 | V_28 ) ;
if ( ! V_22 -> V_5 ) {
F_11 ( V_2 , L_3 ) ;
goto V_29;
}
V_22 -> V_30 = F_13 ( sizeof( struct V_3 ) , V_10 ) ;
if ( ! V_22 -> V_30 ) {
F_11 ( V_2 , L_4 ) ;
goto V_31;
}
if ( F_1
( V_2 , V_22 -> V_30 , V_22 -> V_5 , V_22 -> V_6 , V_16 ) )
goto V_32;
V_15 -> V_33 = V_22 ;
F_9 ( V_2 , L_5 , V_15 ) ;
return 0 ;
V_32:
F_14 ( V_22 -> V_30 ) ;
V_31:
F_15 ( V_2 , V_16 , V_22 -> V_5 , V_22 -> V_6 ) ;
V_29:
F_14 ( V_22 ) ;
return V_26 ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_19 * V_20 = F_8 ( V_15 -> V_13 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = V_15 -> V_33 ;
F_9 ( V_2 , L_6 , V_15 ) ;
F_15 ( V_2 , V_15 -> V_7 , V_22 -> V_5 , V_22 -> V_6 ) ;
F_17 ( V_22 -> V_30 ) ;
F_14 ( V_22 -> V_30 ) ;
F_14 ( V_22 ) ;
}
static int F_18 ( struct V_12 * V_13 , struct V_14 * V_15 ,
T_3 * V_34 , T_2 * V_16 )
{
struct V_19 * V_20 = F_8 ( V_15 -> V_13 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = V_15 -> V_33 ;
F_9 ( V_2 , L_7 , V_15 ,
& V_22 -> V_6 ) ;
* V_34 = V_22 -> V_6 ;
* V_16 = V_15 -> V_7 ;
return 0 ;
}
static struct V_3 * F_19 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_21 * V_22 = V_15 -> V_33 ;
return V_22 -> V_30 ;
}
static void F_20 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
return;
}
static int F_21 ( struct V_12 * V_35 , struct V_14 * V_15 ,
struct V_36 * V_37 )
{
struct V_19 * V_20 = F_8 ( V_15 -> V_13 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = V_15 -> V_33 ;
return F_22 ( V_2 , V_37 , V_22 -> V_5 , V_22 -> V_6 ,
V_15 -> V_7 ) ;
}
static void * F_23 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_21 * V_22 = V_15 -> V_33 ;
return V_22 -> V_5 ;
}
static void F_24 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
}
struct V_12 * F_25 ( struct V_38 * V_39 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( sizeof( struct V_19 ) , V_10 ) ;
if ( ! V_20 )
return F_26 ( - V_40 ) ;
V_20 -> V_13 . V_41 = & V_42 ;
V_20 -> V_2 = V_39 -> V_43 ;
V_20 -> V_13 . type = V_44 ;
return & V_20 -> V_13 ;
}
void F_27 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = F_8 ( V_13 ) ;
F_14 ( V_20 ) ;
}
