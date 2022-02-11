static struct V_1 *
F_1 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_9 ) ;
if ( ! V_5 )
return F_3 ( - V_10 ) ;
V_7 = & V_5 -> V_11 ;
V_8 = F_4 ( V_3 , V_7 , V_4 ) ;
if ( V_8 )
goto error;
V_8 = F_5 ( V_7 ) ;
if ( V_8 ) {
F_6 ( V_7 ) ;
goto error;
}
return V_5 ;
error:
F_7 ( V_5 ) ;
return F_3 ( V_8 ) ;
}
struct V_1 * F_8 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_12 * V_13 = NULL ;
int V_8 ;
V_4 = F_9 ( V_4 , V_14 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_10 ( V_5 ) )
return V_5 ;
V_5 -> V_15 = F_11 ( V_3 -> V_16 , V_4 ,
& V_5 -> V_17 , V_9 | V_18 ) ;
if ( ! V_5 -> V_15 ) {
F_12 ( V_3 -> V_16 , L_1 ,
V_4 ) ;
V_8 = - V_10 ;
goto error;
}
V_13 = F_2 ( sizeof( * V_5 -> V_13 ) , V_9 ) ;
if ( V_13 == NULL ) {
V_8 = - V_10 ;
goto error;
}
V_8 = F_13 ( V_3 -> V_16 , V_13 , V_5 -> V_15 ,
V_5 -> V_17 , V_4 ) ;
if ( V_8 < 0 )
goto error;
V_5 -> V_13 = V_13 ;
return V_5 ;
error:
F_7 ( V_13 ) ;
F_14 ( & V_5 -> V_11 ) ;
return F_3 ( V_8 ) ;
}
static struct V_1 * F_15 (
struct V_19 * V_20 ,
struct V_2 * V_3 , unsigned int V_4 ,
unsigned int * V_21 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_8 ( V_3 , V_4 ) ;
if ( F_10 ( V_5 ) )
return V_5 ;
V_7 = & V_5 -> V_11 ;
V_8 = F_16 ( V_20 , V_7 , V_21 ) ;
if ( V_8 )
goto V_22;
F_17 ( V_7 ) ;
return V_5 ;
V_22:
F_14 ( V_7 ) ;
return F_3 ( V_8 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_5 ;
F_18 ( V_7 ) ;
V_5 = F_19 ( V_7 ) ;
if ( V_5 -> V_15 ) {
F_20 ( V_7 -> V_16 -> V_16 , V_5 -> V_11 . V_4 ,
V_5 -> V_15 , V_5 -> V_17 ) ;
if ( V_5 -> V_13 ) {
F_21 ( V_5 -> V_13 ) ;
F_7 ( V_5 -> V_13 ) ;
}
} else if ( V_7 -> V_23 ) {
F_22 ( V_7 , V_5 -> V_13 ) ;
}
F_6 ( V_7 ) ;
F_7 ( V_5 ) ;
}
int F_23 ( struct V_19 * V_20 ,
struct V_2 * V_16 , struct V_24 * args )
{
struct V_1 * V_5 ;
int V_25 = F_24 ( args -> V_26 * args -> V_27 , 8 ) ;
if ( args -> V_28 < V_25 )
args -> V_28 = V_25 ;
if ( args -> V_4 < args -> V_28 * args -> V_29 )
args -> V_4 = args -> V_28 * args -> V_29 ;
V_5 = F_15 ( V_20 , V_16 ,
args -> V_4 , & args -> V_21 ) ;
return F_25 ( V_5 ) ;
}
int F_26 ( struct V_19 * V_20 ,
struct V_2 * V_3 , T_1 V_21 , T_2 * V_30 )
{
struct V_6 * V_7 ;
F_27 ( & V_3 -> V_31 ) ;
V_7 = F_28 ( V_3 , V_20 , V_21 ) ;
if ( ! V_7 ) {
F_12 ( V_3 -> V_16 , L_2 ) ;
F_29 ( & V_3 -> V_31 ) ;
return - V_32 ;
}
* V_30 = F_30 ( & V_7 -> V_33 ) ;
F_31 ( V_7 ) ;
F_29 ( & V_3 -> V_31 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_5 ,
struct V_34 * V_35 )
{
int V_8 ;
V_8 = F_33 ( V_35 , V_35 -> V_36 , V_5 -> V_17 >> V_37 ,
V_35 -> V_38 - V_35 -> V_36 , V_35 -> V_39 ) ;
if ( V_8 )
F_34 ( V_35 ) ;
return V_8 ;
}
int F_35 ( struct V_40 * V_41 , struct V_34 * V_35 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_36 ( V_41 , V_35 ) ;
if ( V_8 )
return V_8 ;
V_7 = V_35 -> V_42 ;
V_5 = F_19 ( V_7 ) ;
return F_32 ( V_5 , V_35 ) ;
}
void F_37 ( struct V_1 * V_5 , struct V_43 * V_44 )
{
struct V_6 * V_45 = & V_5 -> V_11 ;
struct V_2 * V_16 = V_45 -> V_16 ;
T_2 V_46 ;
F_38 ( ! F_39 ( & V_16 -> V_31 ) ) ;
V_46 = F_40 ( & V_45 -> V_33 ) ;
F_41 ( V_44 , L_3 ,
V_45 -> V_47 , V_45 -> V_48 . V_48 . V_49 ,
V_46 , V_5 -> V_17 , V_5 -> V_15 , V_45 -> V_4 ) ;
F_41 ( V_44 , L_4 ) ;
}
struct V_12 * F_42 ( struct V_6 * V_45 )
{
struct V_1 * V_5 = F_19 ( V_45 ) ;
struct V_12 * V_13 ;
int V_8 ;
V_13 = F_2 ( sizeof( * V_13 ) , V_9 ) ;
if ( ! V_13 )
return NULL ;
V_8 = F_13 ( V_45 -> V_16 -> V_16 , V_13 , V_5 -> V_15 ,
V_5 -> V_17 , V_45 -> V_4 ) ;
if ( V_8 < 0 )
goto V_50;
return V_13 ;
V_50:
F_7 ( V_13 ) ;
return NULL ;
}
struct V_6 *
F_43 ( struct V_2 * V_16 , T_3 V_4 ,
struct V_12 * V_13 )
{
struct V_1 * V_5 ;
if ( V_13 -> V_51 != 1 )
return F_3 ( - V_32 ) ;
V_5 = F_1 ( V_16 , V_4 ) ;
if ( F_10 ( V_5 ) )
return F_3 ( F_44 ( V_5 ) ) ;
V_5 -> V_17 = F_45 ( V_13 -> V_52 ) ;
V_5 -> V_13 = V_13 ;
F_46 ( L_5 , V_5 -> V_17 , V_4 ) ;
return & V_5 -> V_11 ;
}
int F_47 ( struct V_6 * V_45 ,
struct V_34 * V_35 )
{
struct V_1 * V_5 ;
struct V_2 * V_16 = V_45 -> V_16 ;
int V_8 ;
F_27 ( & V_16 -> V_31 ) ;
V_8 = F_48 ( V_45 , V_45 -> V_4 , V_35 ) ;
F_29 ( & V_16 -> V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_19 ( V_45 ) ;
return F_32 ( V_5 , V_35 ) ;
}
void * F_49 ( struct V_6 * V_45 )
{
struct V_1 * V_5 = F_19 ( V_45 ) ;
return V_5 -> V_15 ;
}
void F_50 ( struct V_6 * V_45 , void * V_15 )
{
}
