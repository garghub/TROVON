static unsigned int F_1 ( struct V_1 * V_2 )
{
return ( unsigned int ) V_2 -> V_3 . V_4 . V_5 << V_6 ;
}
static struct V_7 *
F_2 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_7 * V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_11 = F_3 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return F_4 ( - V_15 ) ;
V_12 = & V_11 -> V_16 ;
V_13 = F_5 ( V_9 , V_12 , V_10 ) ;
if ( V_13 )
goto error;
V_13 = F_6 ( V_12 ) ;
if ( V_13 ) {
F_7 ( V_12 ) ;
goto error;
}
return V_11 ;
error:
F_8 ( V_11 ) ;
return F_4 ( V_13 ) ;
}
struct V_7 * F_9 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
struct V_7 * V_11 ;
struct V_17 * V_18 = NULL ;
int V_13 ;
V_10 = F_10 ( V_10 , V_19 ) ;
V_11 = F_2 ( V_9 , V_10 ) ;
if ( F_11 ( V_11 ) )
return V_11 ;
V_11 -> V_20 = F_12 ( V_9 -> V_21 , V_10 ,
& V_11 -> V_22 , V_14 | V_23 ) ;
if ( ! V_11 -> V_20 ) {
F_13 ( V_9 -> V_21 , L_1 ,
V_10 ) ;
V_13 = - V_15 ;
goto error;
}
V_18 = F_3 ( sizeof( * V_11 -> V_18 ) , V_14 ) ;
if ( V_18 == NULL ) {
V_13 = - V_15 ;
goto error;
}
V_13 = F_14 ( V_9 -> V_21 , V_18 , V_11 -> V_20 ,
V_11 -> V_22 , V_10 ) ;
if ( V_13 < 0 )
goto error;
V_11 -> V_18 = V_18 ;
return V_11 ;
error:
F_8 ( V_18 ) ;
F_15 ( & V_11 -> V_16 ) ;
return F_4 ( V_13 ) ;
}
static struct V_7 * F_16 (
struct V_24 * V_25 ,
struct V_8 * V_9 , unsigned int V_10 ,
unsigned int * V_26 )
{
struct V_7 * V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_11 = F_9 ( V_9 , V_10 ) ;
if ( F_11 ( V_11 ) )
return V_11 ;
V_12 = & V_11 -> V_16 ;
V_13 = F_17 ( V_25 , V_12 , V_26 ) ;
if ( V_13 )
goto V_27;
F_18 ( V_12 ) ;
return V_11 ;
V_27:
F_15 ( V_12 ) ;
return F_4 ( V_13 ) ;
}
void F_15 ( struct V_1 * V_12 )
{
struct V_7 * V_11 ;
if ( V_12 -> V_3 . V_28 )
F_19 ( V_12 ) ;
V_11 = F_20 ( V_12 ) ;
if ( V_11 -> V_20 ) {
F_21 ( V_12 -> V_21 -> V_21 , V_11 -> V_16 . V_10 ,
V_11 -> V_20 , V_11 -> V_22 ) ;
if ( V_11 -> V_18 ) {
F_22 ( V_11 -> V_18 ) ;
F_8 ( V_11 -> V_18 ) ;
}
} else if ( V_12 -> V_29 ) {
F_23 ( V_12 , V_11 -> V_18 ) ;
}
F_7 ( V_12 ) ;
F_8 ( V_11 ) ;
}
int F_24 ( struct V_24 * V_25 ,
struct V_8 * V_21 , struct V_30 * args )
{
struct V_7 * V_11 ;
int V_31 = F_25 ( args -> V_32 * args -> V_33 , 8 ) ;
if ( args -> V_34 < V_31 )
args -> V_34 = V_31 ;
if ( args -> V_10 < args -> V_34 * args -> V_35 )
args -> V_10 = args -> V_34 * args -> V_35 ;
V_11 = F_16 ( V_25 , V_21 ,
args -> V_10 , & args -> V_26 ) ;
return F_26 ( V_11 ) ;
}
int F_27 ( struct V_24 * V_25 ,
struct V_8 * V_9 , T_1 V_26 , T_2 * V_36 )
{
struct V_1 * V_12 ;
F_28 ( & V_9 -> V_37 ) ;
V_12 = F_29 ( V_9 , V_25 , V_26 ) ;
if ( ! V_12 ) {
F_13 ( V_9 -> V_21 , L_2 ) ;
F_30 ( & V_9 -> V_37 ) ;
return - V_38 ;
}
* V_36 = F_1 ( V_12 ) ;
F_31 ( V_12 ) ;
F_30 ( & V_9 -> V_37 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_11 ,
struct V_39 * V_40 )
{
int V_13 ;
V_13 = F_33 ( V_40 , V_40 -> V_41 , V_11 -> V_22 >> V_6 ,
V_40 -> V_42 - V_40 -> V_41 , V_40 -> V_43 ) ;
if ( V_13 )
F_34 ( V_40 ) ;
return V_13 ;
}
int F_35 ( struct V_44 * V_45 , struct V_39 * V_40 )
{
struct V_7 * V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_13 = F_36 ( V_45 , V_40 ) ;
if ( V_13 )
return V_13 ;
V_12 = V_40 -> V_46 ;
V_11 = F_20 ( V_12 ) ;
return F_32 ( V_11 , V_40 ) ;
}
int F_37 ( struct V_24 * V_25 ,
struct V_8 * V_9 , unsigned int V_26 )
{
return F_38 ( V_25 , V_26 ) ;
}
void F_39 ( struct V_7 * V_11 , struct V_47 * V_48 )
{
struct V_1 * V_2 = & V_11 -> V_16 ;
struct V_8 * V_21 = V_2 -> V_21 ;
T_2 V_49 = 0 ;
F_40 ( ! F_41 ( & V_21 -> V_37 ) ) ;
if ( V_2 -> V_3 . V_28 )
V_49 = ( T_2 ) V_2 -> V_3 . V_4 . V_5 ;
F_42 ( V_48 , L_3 ,
V_2 -> V_50 , V_2 -> V_51 . V_51 . V_52 ,
V_49 , V_11 -> V_22 , V_11 -> V_20 , V_2 -> V_10 ) ;
F_42 ( V_48 , L_4 ) ;
}
struct V_17 * F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_11 = F_20 ( V_2 ) ;
struct V_17 * V_18 ;
int V_13 ;
V_18 = F_3 ( sizeof( * V_18 ) , V_14 ) ;
if ( ! V_18 )
return NULL ;
V_13 = F_14 ( V_2 -> V_21 -> V_21 , V_18 , V_11 -> V_20 ,
V_11 -> V_22 , V_2 -> V_10 ) ;
if ( V_13 < 0 )
goto V_53;
return V_18 ;
V_53:
F_8 ( V_18 ) ;
return NULL ;
}
struct V_1 *
F_44 ( struct V_8 * V_21 , T_3 V_10 ,
struct V_17 * V_18 )
{
struct V_7 * V_11 ;
if ( V_18 -> V_54 != 1 )
return F_4 ( - V_38 ) ;
V_11 = F_2 ( V_21 , V_10 ) ;
if ( F_11 ( V_11 ) )
return F_4 ( F_45 ( V_11 ) ) ;
V_11 -> V_22 = F_46 ( V_18 -> V_55 ) ;
V_11 -> V_18 = V_18 ;
F_47 ( L_5 , V_11 -> V_22 , V_10 ) ;
return & V_11 -> V_16 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_7 * V_11 ;
struct V_8 * V_21 = V_2 -> V_21 ;
int V_13 ;
F_28 ( & V_21 -> V_37 ) ;
V_13 = F_49 ( V_2 , V_2 -> V_10 , V_40 ) ;
F_30 ( & V_21 -> V_37 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = F_20 ( V_2 ) ;
return F_32 ( V_11 , V_40 ) ;
}
void * F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_11 = F_20 ( V_2 ) ;
return V_11 -> V_20 ;
}
void F_51 ( struct V_1 * V_2 , void * V_20 )
{
}
