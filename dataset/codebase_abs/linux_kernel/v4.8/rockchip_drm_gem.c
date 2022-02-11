static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
V_2 -> V_10 = V_11 ;
if ( ! V_3 )
V_2 -> V_10 |= V_12 ;
V_2 -> V_13 = F_2 ( V_8 -> V_9 , V_5 -> V_14 ,
& V_2 -> V_15 , V_16 ,
V_2 -> V_10 ) ;
if ( ! V_2 -> V_13 ) {
F_3 ( L_1 , V_5 -> V_14 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_5 ( V_8 -> V_9 , V_5 -> V_14 , V_2 -> V_13 , V_2 -> V_15 ,
V_2 -> V_10 ) ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
int V_20 ;
struct V_1 * V_2 = F_7 ( V_5 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
V_19 -> V_21 &= ~ V_22 ;
V_19 -> V_23 = 0 ;
V_20 = F_8 ( V_8 -> V_9 , V_19 , V_2 -> V_13 , V_2 -> V_15 ,
V_5 -> V_14 , V_2 -> V_10 ) ;
if ( V_20 )
F_9 ( V_19 ) ;
return V_20 ;
}
int F_10 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
int V_20 ;
V_20 = F_11 ( V_5 , V_5 -> V_14 , V_19 ) ;
if ( V_20 )
return V_20 ;
return F_6 ( V_5 , V_19 ) ;
}
int F_12 ( struct V_24 * V_25 , struct V_18 * V_19 )
{
struct V_4 * V_5 ;
int V_20 ;
V_20 = F_13 ( V_25 , V_19 ) ;
if ( V_20 )
return V_20 ;
V_5 = V_19 -> V_26 ;
return F_6 ( V_5 , V_19 ) ;
}
struct V_1 *
F_14 ( struct V_7 * V_8 , unsigned int V_14 ,
bool V_3 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_20 ;
V_14 = F_15 ( V_14 , V_27 ) ;
V_2 = F_16 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return F_17 ( - V_17 ) ;
V_5 = & V_2 -> V_6 ;
F_18 ( V_8 , V_5 , V_14 ) ;
V_20 = F_1 ( V_2 , V_3 ) ;
if ( V_20 )
goto V_28;
return V_2 ;
V_28:
F_19 ( V_2 ) ;
return F_17 ( V_20 ) ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_21 ( V_5 ) ;
V_2 = F_7 ( V_5 ) ;
F_4 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static struct V_1 *
F_22 ( struct V_29 * V_30 ,
struct V_7 * V_8 , unsigned int V_14 ,
unsigned int * V_31 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_20 ;
V_2 = F_14 ( V_8 , V_14 , false ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
V_5 = & V_2 -> V_6 ;
V_20 = F_25 ( V_30 , V_5 , V_31 ) ;
if ( V_20 )
goto V_32;
F_26 ( V_5 ) ;
return V_2 ;
V_32:
F_20 ( V_5 ) ;
return F_17 ( V_20 ) ;
}
int F_27 ( struct V_29 * V_30 ,
struct V_7 * V_9 , T_1 V_31 ,
T_2 * V_33 )
{
struct V_4 * V_5 ;
int V_20 ;
V_5 = F_28 ( V_30 , V_31 ) ;
if ( ! V_5 ) {
F_3 ( L_2 ) ;
return - V_34 ;
}
V_20 = F_29 ( V_5 ) ;
if ( V_20 )
goto V_35;
* V_33 = F_30 ( & V_5 -> V_36 ) ;
F_31 ( L_3 , * V_33 ) ;
V_35:
F_26 ( V_5 ) ;
return 0 ;
}
int F_32 ( struct V_29 * V_30 ,
struct V_7 * V_9 ,
struct V_37 * args )
{
struct V_1 * V_2 ;
int V_38 = F_33 ( args -> V_39 * args -> V_40 , 8 ) ;
args -> V_41 = F_34 ( V_38 , 64 ) ;
args -> V_14 = args -> V_41 * args -> V_42 ;
V_2 = F_22 ( V_30 , V_9 , args -> V_14 ,
& args -> V_31 ) ;
return F_35 ( V_2 ) ;
}
struct V_43 * F_36 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_43 * V_44 ;
int V_20 ;
V_44 = F_16 ( sizeof( * V_44 ) , V_16 ) ;
if ( ! V_44 )
return F_17 ( - V_17 ) ;
V_20 = F_37 ( V_8 -> V_9 , V_44 , V_2 -> V_13 ,
V_2 -> V_15 , V_5 -> V_14 ,
V_2 -> V_10 ) ;
if ( V_20 ) {
F_3 ( L_4 , V_20 ) ;
F_19 ( V_44 ) ;
return F_17 ( V_20 ) ;
}
return V_44 ;
}
void * F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_7 ( V_5 ) ;
if ( V_2 -> V_10 & V_12 )
return NULL ;
return V_2 -> V_13 ;
}
void F_39 ( struct V_4 * V_5 , void * V_45 )
{
}
