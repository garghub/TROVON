T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_7 = F_3 ( V_6 -> V_8 , V_3 ) ;
if ( ! V_7 )
return V_9 ;
return V_7 ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_10 ,
unsigned long V_3 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( V_10 == V_9 )
return;
F_5 ( V_6 -> V_8 , V_10 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_1 * V_10 , T_2 * V_13 )
{
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 * V_17 = F_7 ( V_15 -> V_18 ) ;
T_1 V_19 = F_8 ( F_9 ( V_17 ) ) ;
* V_10 = V_19 ;
* V_13 = V_12 -> V_3 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_20 )
{
struct V_14 * V_15 ;
T_1 V_19 ;
int V_21 ;
if ( V_4 > V_22 )
return - V_23 ;
V_15 = F_11 ( sizeof( * V_15 ) , V_24 ) ;
if ( ! V_15 )
return - V_25 ;
V_21 = F_12 ( V_15 , 1 , V_24 ) ;
if ( V_21 )
goto V_26;
V_19 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_19 == V_9 ) {
V_21 = - V_25 ;
goto V_27;
}
F_13 ( V_15 -> V_18 , F_14 ( F_15 ( V_19 ) ) , V_3 , 0 ) ;
V_12 -> V_16 = V_15 ;
return 0 ;
V_27:
F_16 ( V_15 ) ;
V_26:
F_17 ( V_15 ) ;
return V_21 ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 * V_17 = F_7 ( V_15 -> V_18 ) ;
T_1 V_19 = F_8 ( F_9 ( V_17 ) ) ;
F_19 ( V_12 ) ;
if ( F_20 ( V_12 ) )
F_21 ( NULL , V_15 -> V_18 , V_15 -> V_28 ,
V_29 ) ;
F_4 ( V_2 , V_19 , V_12 -> V_3 ) ;
F_16 ( V_15 ) ;
F_17 ( V_15 ) ;
}
static struct V_14 * F_22 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return V_12 -> V_16 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
}
struct V_1 * F_24 ( struct V_30 * V_31 )
{
struct V_5 * V_6 ;
int V_21 ;
struct V_17 * V_17 ;
T_2 V_3 ;
V_17 = F_14 ( F_15 ( V_31 -> V_32 ) ) ;
V_3 = V_31 -> V_3 ;
F_25 ( NULL , V_17 , V_3 , V_29 ) ;
V_21 = F_26 ( V_17 , V_3 , F_27 ( V_33 ) ) ;
if ( V_21 )
return F_28 ( V_21 ) ;
V_6 = F_29 ( sizeof( * V_6 ) , V_24 ) ;
if ( ! V_6 )
return F_28 ( - V_25 ) ;
V_6 -> V_8 = F_30 ( V_34 , - 1 ) ;
if ( ! V_6 -> V_8 ) {
F_17 ( V_6 ) ;
return F_28 ( - V_25 ) ;
}
V_6 -> V_32 = V_31 -> V_32 ;
F_31 ( V_6 -> V_8 , V_6 -> V_32 , V_31 -> V_3 ,
- 1 ) ;
V_6 -> V_2 . V_35 = & V_36 ;
V_6 -> V_2 . type = V_37 ;
V_6 -> V_2 . V_20 = V_38 ;
return & V_6 -> V_2 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
F_33 ( V_6 -> V_8 ) ;
F_17 ( V_6 ) ;
V_6 = NULL ;
}
