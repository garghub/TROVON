static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_2 ( & V_2 -> V_10 ) ;
F_3 ( V_11 , & V_2 -> V_10 ) ;
if ( ! V_3 )
F_3 ( V_12 , & V_2 -> V_10 ) ;
V_2 -> V_13 = F_4 ( V_8 -> V_9 , V_5 -> V_14 ,
& V_2 -> V_15 , V_16 ,
& V_2 -> V_10 ) ;
if ( ! V_2 -> V_13 ) {
F_5 ( L_1 , V_5 -> V_14 ) ;
return - V_17 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_7 ( V_8 -> V_9 , V_5 -> V_14 , V_2 -> V_13 , V_2 -> V_15 ,
& V_2 -> V_10 ) ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
int V_20 ;
struct V_1 * V_2 = F_9 ( V_5 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
V_19 -> V_21 &= ~ V_22 ;
V_19 -> V_23 = 0 ;
V_20 = F_10 ( V_8 -> V_9 , V_19 , V_2 -> V_13 , V_2 -> V_15 ,
V_5 -> V_14 , & V_2 -> V_10 ) ;
if ( V_20 )
F_11 ( V_19 ) ;
return V_20 ;
}
int F_12 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
int V_20 ;
V_20 = F_13 ( V_5 , V_5 -> V_14 , V_19 ) ;
if ( V_20 )
return V_20 ;
return F_8 ( V_5 , V_19 ) ;
}
int F_14 ( struct V_24 * V_25 , struct V_18 * V_19 )
{
struct V_4 * V_5 ;
int V_20 ;
V_20 = F_15 ( V_25 , V_19 ) ;
if ( V_20 )
return V_20 ;
V_5 = V_19 -> V_26 ;
return F_8 ( V_5 , V_19 ) ;
}
struct V_1 *
F_16 ( struct V_7 * V_8 , unsigned int V_14 ,
bool V_3 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_20 ;
V_14 = F_17 ( V_14 , V_27 ) ;
V_2 = F_18 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return F_19 ( - V_17 ) ;
V_5 = & V_2 -> V_6 ;
F_20 ( V_8 , V_5 , V_14 ) ;
V_20 = F_1 ( V_2 , V_3 ) ;
if ( V_20 )
goto V_28;
return V_2 ;
V_28:
F_21 ( V_2 ) ;
return F_19 ( V_20 ) ;
}
void F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_23 ( V_5 ) ;
V_2 = F_9 ( V_5 ) ;
F_6 ( V_2 ) ;
F_21 ( V_2 ) ;
}
static struct V_1 *
F_24 ( struct V_29 * V_30 ,
struct V_7 * V_8 , unsigned int V_14 ,
unsigned int * V_31 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_20 ;
V_2 = F_16 ( V_8 , V_14 , false ) ;
if ( F_25 ( V_2 ) )
return F_26 ( V_2 ) ;
V_5 = & V_2 -> V_6 ;
V_20 = F_27 ( V_30 , V_5 , V_31 ) ;
if ( V_20 )
goto V_32;
F_28 ( V_5 ) ;
return V_2 ;
V_32:
F_22 ( V_5 ) ;
return F_19 ( V_20 ) ;
}
int F_29 ( struct V_29 * V_30 ,
struct V_7 * V_9 , T_1 V_31 ,
T_2 * V_33 )
{
struct V_4 * V_5 ;
int V_20 ;
V_5 = F_30 ( V_30 , V_31 ) ;
if ( ! V_5 ) {
F_5 ( L_2 ) ;
return - V_34 ;
}
V_20 = F_31 ( V_5 ) ;
if ( V_20 )
goto V_35;
* V_33 = F_32 ( & V_5 -> V_36 ) ;
F_33 ( L_3 , * V_33 ) ;
V_35:
F_28 ( V_5 ) ;
return 0 ;
}
int F_34 ( struct V_29 * V_30 ,
struct V_7 * V_9 ,
struct V_37 * args )
{
struct V_1 * V_2 ;
int V_38 = F_35 ( args -> V_39 * args -> V_40 , 8 ) ;
args -> V_41 = F_36 ( V_38 , 64 ) ;
args -> V_14 = args -> V_41 * args -> V_42 ;
V_2 = F_24 ( V_30 , V_9 , args -> V_14 ,
& args -> V_31 ) ;
return F_37 ( V_2 ) ;
}
struct V_43 * F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_43 * V_44 ;
int V_20 ;
V_44 = F_18 ( sizeof( * V_44 ) , V_16 ) ;
if ( ! V_44 )
return F_19 ( - V_17 ) ;
V_20 = F_39 ( V_8 -> V_9 , V_44 , V_2 -> V_13 ,
V_2 -> V_15 , V_5 -> V_14 ,
& V_2 -> V_10 ) ;
if ( V_20 ) {
F_5 ( L_4 , V_20 ) ;
F_21 ( V_44 ) ;
return F_19 ( V_20 ) ;
}
return V_44 ;
}
void * F_40 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
if ( F_41 ( V_12 , & V_2 -> V_10 ) )
return NULL ;
return V_2 -> V_13 ;
}
void F_42 ( struct V_4 * V_5 , void * V_45 )
{
}
