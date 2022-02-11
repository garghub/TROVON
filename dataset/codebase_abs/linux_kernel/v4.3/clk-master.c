static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( V_4 -> V_1 ) ;
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
while ( ! ( F_6 ( V_10 , V_11 ) & V_12 ) ) {
F_7 ( V_4 -> V_1 ) ;
F_8 ( V_4 -> V_5 ,
F_6 ( V_10 , V_11 ) & V_12 ) ;
}
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
return ! ! ( F_6 ( V_4 -> V_10 , V_11 ) & V_12 ) ;
}
static unsigned long F_10 ( struct V_7 * V_8 ,
unsigned long V_13 )
{
T_2 V_14 ;
T_2 div ;
unsigned long V_15 = V_13 ;
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
const struct V_16 * V_17 = V_4 -> V_17 ;
const struct V_18 * V_19 =
V_4 -> V_19 ;
T_3 V_20 ;
F_11 ( V_10 ) ;
V_20 = F_6 ( V_10 , V_21 ) & V_17 -> V_22 ;
F_12 ( V_10 ) ;
V_14 = ( V_20 >> V_17 -> V_23 ) & V_24 ;
div = ( V_20 >> V_25 ) & V_26 ;
if ( V_19 -> V_27 && V_14 == V_28 )
V_15 /= 3 ;
else
V_15 >>= V_14 ;
V_15 /= V_19 -> V_29 [ div ] ;
if ( V_15 < V_19 -> V_30 . V_31 )
F_13 ( L_1 ) ;
else if ( V_15 > V_19 -> V_30 . V_32 )
F_13 ( L_2 ) ;
return V_15 ;
}
static T_2 F_14 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
return F_6 ( V_10 , V_21 ) & V_33 ;
}
static struct V_34 * T_4
F_15 ( struct V_9 * V_10 , unsigned int V_1 ,
const char * V_35 , int V_36 ,
const char * * V_37 ,
const struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
int V_38 ;
struct V_3 * V_4 ;
struct V_34 * V_34 = NULL ;
struct V_39 V_40 ;
if ( ! V_10 || ! V_1 || ! V_35 || ! V_36 || ! V_37 )
return F_16 ( - V_41 ) ;
V_4 = F_17 ( sizeof( * V_4 ) , V_42 ) ;
if ( ! V_4 )
return F_16 ( - V_43 ) ;
V_40 . V_35 = V_35 ;
V_40 . V_44 = & V_45 ;
V_40 . V_37 = V_37 ;
V_40 . V_36 = V_36 ;
V_40 . V_46 = 0 ;
V_4 -> V_8 . V_40 = & V_40 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_1 = V_1 ;
F_18 ( & V_4 -> V_5 ) ;
F_19 ( V_4 -> V_1 , V_47 ) ;
V_38 = F_20 ( V_4 -> V_1 , F_1 ,
V_48 , L_3 , V_4 ) ;
if ( V_38 ) {
F_21 ( V_4 ) ;
return F_16 ( V_38 ) ;
}
V_34 = F_22 ( NULL , & V_4 -> V_8 ) ;
if ( F_23 ( V_34 ) ) {
F_24 ( V_4 -> V_1 , V_4 ) ;
F_21 ( V_4 ) ;
}
return V_34 ;
}
static struct V_18 * T_4
F_25 ( struct V_49 * V_50 )
{
struct V_18 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_42 ) ;
if ( ! V_19 )
return NULL ;
if ( F_26 ( V_50 , L_4 , & V_19 -> V_30 ) )
goto V_51;
F_27 ( V_50 , L_5 ,
V_19 -> V_29 , 4 ) ;
V_19 -> V_27 =
F_28 ( V_50 , L_6 ) ;
return V_19 ;
V_51:
F_21 ( V_19 ) ;
return NULL ;
}
static void T_4
F_29 ( struct V_49 * V_50 , struct V_9 * V_10 ,
const struct V_16 * V_17 )
{
struct V_34 * V_34 ;
int V_36 ;
unsigned int V_1 ;
const char * V_37 [ V_52 ] ;
const char * V_35 = V_50 -> V_35 ;
struct V_18 * V_19 ;
V_36 = F_30 ( V_50 ) ;
if ( V_36 <= 0 || V_36 > V_52 )
return;
F_31 ( V_50 , V_37 , V_36 ) ;
F_32 ( V_50 , L_7 , & V_35 ) ;
V_19 = F_25 ( V_50 ) ;
if ( ! V_19 )
return;
V_1 = F_33 ( V_50 , 0 ) ;
if ( ! V_1 )
goto V_51;
V_34 = F_15 ( V_10 , V_1 , V_35 , V_36 ,
V_37 , V_17 ,
V_19 ) ;
if ( F_23 ( V_34 ) )
goto V_51;
F_34 ( V_50 , V_53 , V_34 ) ;
return;
V_51:
F_21 ( V_19 ) ;
}
void T_4 F_35 ( struct V_49 * V_50 ,
struct V_9 * V_10 )
{
F_29 ( V_50 , V_10 , & V_54 ) ;
}
void T_4 F_36 ( struct V_49 * V_50 ,
struct V_9 * V_10 )
{
F_29 ( V_50 , V_10 , & V_55 ) ;
}
