static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , unsigned long V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 ;
F_3 ( V_11 , L_1 , V_5 ) ;
if ( V_4 -> V_7 & V_14 )
return - V_15 ;
if ( V_6 > V_16 )
return - V_15 ;
V_13 = F_4 ( sizeof( struct V_12 ) , V_17 ) ;
if ( ! V_13 )
return V_18 ;
V_13 -> V_19 = F_5 ( V_11 , V_5 , & ( V_13 -> V_20 ) ,
V_21 | V_22 ) ;
if ( ! V_13 -> V_19 ) {
F_6 ( V_11 , L_2 ) ;
goto V_23;
}
V_13 -> V_24 = F_7 ( sizeof( struct V_25 ) , V_17 ) ;
if ( ! V_13 -> V_24 )
goto V_26;
if ( F_8 ( V_11 , V_13 -> V_24 , V_13 -> V_19 , V_13 -> V_20 ,
V_5 ) )
goto V_27;
V_4 -> V_28 = V_13 ;
F_3 ( V_11 , L_3 , V_4 ) ;
return 0 ;
V_27:
F_9 ( V_13 -> V_24 ) ;
V_26:
F_10 ( V_11 , V_5 , V_13 -> V_19 , V_13 -> V_20 ) ;
V_23:
F_9 ( V_13 ) ;
return V_18 ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_4 -> V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_4 -> V_28 ;
F_3 ( V_11 , L_4 , V_4 ) ;
F_10 ( V_11 , V_4 -> V_29 , V_13 -> V_19 , V_13 -> V_20 ) ;
F_12 ( V_13 -> V_24 ) ;
F_9 ( V_13 -> V_24 ) ;
F_9 ( V_13 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_30 , T_2 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_4 -> V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_4 -> V_28 ;
F_3 ( V_11 , L_5 , V_4 ,
& V_13 -> V_20 ) ;
* V_30 = V_13 -> V_20 ;
* V_5 = V_4 -> V_29 ;
return 0 ;
}
static struct V_25 * F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_28 ;
return V_13 -> V_24 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static int F_16 ( struct V_1 * V_31 , struct V_3 * V_4 ,
struct V_32 * V_33 )
{
struct V_8 * V_9 = F_2 ( V_4 -> V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_4 -> V_28 ;
return F_17 ( V_11 , V_33 , V_13 -> V_19 , V_13 -> V_20 ,
V_4 -> V_29 ) ;
}
static void * F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_28 ;
return V_13 -> V_19 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
struct V_1 * F_20 ( struct V_34 * V_35 )
{
struct V_8 * V_9 ;
V_9 = F_4 ( sizeof( struct V_8 ) , V_17 ) ;
if ( ! V_9 )
return F_21 ( - V_36 ) ;
V_9 -> V_2 . V_37 = & V_38 ;
V_9 -> V_11 = V_35 -> V_39 ;
V_9 -> V_2 . type = V_40 ;
return & V_9 -> V_2 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( V_9 ) ;
}
