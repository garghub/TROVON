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
int V_8 ;
V_4 = F_9 ( V_4 , V_12 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_10 ( V_5 ) )
return V_5 ;
V_5 -> V_13 = F_11 ( V_3 -> V_14 , V_4 ,
& V_5 -> V_15 , V_9 | V_16 ) ;
if ( ! V_5 -> V_13 ) {
F_12 ( V_3 -> V_14 , L_1 ,
V_4 ) ;
V_8 = - V_10 ;
goto error;
}
return V_5 ;
error:
F_13 ( & V_5 -> V_11 ) ;
return F_3 ( V_8 ) ;
}
static struct V_1 * F_14 (
struct V_17 * V_18 ,
struct V_2 * V_3 , unsigned int V_4 ,
unsigned int * V_19 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_8 ( V_3 , V_4 ) ;
if ( F_10 ( V_5 ) )
return V_5 ;
V_7 = & V_5 -> V_11 ;
V_8 = F_15 ( V_18 , V_7 , V_19 ) ;
if ( V_8 )
goto V_20;
F_16 ( V_7 ) ;
return V_5 ;
V_20:
F_13 ( V_7 ) ;
return F_3 ( V_8 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_5 ;
F_17 ( V_7 ) ;
V_5 = F_18 ( V_7 ) ;
if ( V_5 -> V_13 ) {
F_19 ( V_7 -> V_14 -> V_14 , V_5 -> V_11 . V_4 ,
V_5 -> V_13 , V_5 -> V_15 ) ;
} else if ( V_7 -> V_21 ) {
F_20 ( V_7 , V_5 -> V_22 ) ;
}
F_6 ( V_7 ) ;
F_7 ( V_5 ) ;
}
int F_21 ( struct V_17 * V_18 ,
struct V_2 * V_14 , struct V_23 * args )
{
struct V_1 * V_5 ;
int V_24 = F_22 ( args -> V_25 * args -> V_26 , 8 ) ;
if ( args -> V_27 < V_24 )
args -> V_27 = V_24 ;
if ( args -> V_4 < args -> V_27 * args -> V_28 )
args -> V_4 = args -> V_27 * args -> V_28 ;
V_5 = F_14 ( V_18 , V_14 ,
args -> V_4 , & args -> V_19 ) ;
return F_23 ( V_5 ) ;
}
int F_24 ( struct V_17 * V_18 ,
struct V_2 * V_3 , T_1 V_19 , T_2 * V_29 )
{
struct V_6 * V_7 ;
F_25 ( & V_3 -> V_30 ) ;
V_7 = F_26 ( V_3 , V_18 , V_19 ) ;
if ( ! V_7 ) {
F_12 ( V_3 -> V_14 , L_2 ) ;
F_27 ( & V_3 -> V_30 ) ;
return - V_31 ;
}
* V_29 = F_28 ( & V_7 -> V_32 ) ;
F_29 ( V_7 ) ;
F_27 ( & V_3 -> V_30 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_5 ,
struct V_33 * V_34 )
{
int V_8 ;
V_34 -> V_35 &= ~ V_36 ;
V_34 -> V_37 = 0 ;
V_8 = F_31 ( V_5 -> V_11 . V_14 -> V_14 , V_34 ,
V_5 -> V_13 , V_5 -> V_15 ,
V_34 -> V_38 - V_34 -> V_39 ) ;
if ( V_8 )
F_32 ( V_34 ) ;
return V_8 ;
}
int F_33 ( struct V_40 * V_41 , struct V_33 * V_34 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_34 ( V_41 , V_34 ) ;
if ( V_8 )
return V_8 ;
V_7 = V_34 -> V_42 ;
V_5 = F_18 ( V_7 ) ;
return F_30 ( V_5 , V_34 ) ;
}
void F_35 ( struct V_1 * V_5 , struct V_43 * V_44 )
{
struct V_6 * V_45 = & V_5 -> V_11 ;
struct V_2 * V_14 = V_45 -> V_14 ;
T_2 V_46 ;
F_36 ( ! F_37 ( & V_14 -> V_30 ) ) ;
V_46 = F_38 ( & V_45 -> V_32 ) ;
F_39 ( V_44 , L_3 ,
V_45 -> V_47 , V_45 -> V_48 . V_48 . V_49 ,
V_46 , & V_5 -> V_15 , V_5 -> V_13 , V_45 -> V_4 ) ;
F_39 ( V_44 , L_4 ) ;
}
struct V_50 * F_40 ( struct V_6 * V_45 )
{
struct V_1 * V_5 = F_18 ( V_45 ) ;
struct V_50 * V_22 ;
int V_8 ;
V_22 = F_2 ( sizeof( * V_22 ) , V_9 ) ;
if ( ! V_22 )
return NULL ;
V_8 = F_41 ( V_45 -> V_14 -> V_14 , V_22 , V_5 -> V_13 ,
V_5 -> V_15 , V_45 -> V_4 ) ;
if ( V_8 < 0 )
goto V_51;
return V_22 ;
V_51:
F_7 ( V_22 ) ;
return NULL ;
}
struct V_6 *
F_42 ( struct V_2 * V_14 , T_3 V_4 ,
struct V_50 * V_22 )
{
struct V_1 * V_5 ;
if ( V_22 -> V_52 != 1 )
return F_3 ( - V_31 ) ;
V_5 = F_1 ( V_14 , V_4 ) ;
if ( F_10 ( V_5 ) )
return F_43 ( V_5 ) ;
V_5 -> V_15 = F_44 ( V_22 -> V_53 ) ;
V_5 -> V_22 = V_22 ;
F_45 ( L_5 , & V_5 -> V_15 , V_4 ) ;
return & V_5 -> V_11 ;
}
int F_46 ( struct V_6 * V_45 ,
struct V_33 * V_34 )
{
struct V_1 * V_5 ;
struct V_2 * V_14 = V_45 -> V_14 ;
int V_8 ;
F_25 ( & V_14 -> V_30 ) ;
V_8 = F_47 ( V_45 , V_45 -> V_4 , V_34 ) ;
F_27 ( & V_14 -> V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_18 ( V_45 ) ;
return F_30 ( V_5 , V_34 ) ;
}
void * F_48 ( struct V_6 * V_45 )
{
struct V_1 * V_5 = F_18 ( V_45 ) ;
return V_5 -> V_13 ;
}
void F_49 ( struct V_6 * V_45 , void * V_13 )
{
}
