static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
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
T_1 V_4 )
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
static struct V_1 *
F_14 ( struct V_17 * V_18 ,
struct V_2 * V_3 , T_1 V_4 ,
T_2 * V_19 )
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
V_5 = F_17 ( V_7 ) ;
if ( V_5 -> V_13 ) {
F_18 ( V_7 -> V_14 -> V_14 , V_5 -> V_11 . V_4 ,
V_5 -> V_13 , V_5 -> V_15 ) ;
} else if ( V_7 -> V_21 ) {
F_19 ( V_7 , V_5 -> V_22 ) ;
}
F_6 ( V_7 ) ;
F_7 ( V_5 ) ;
}
int F_20 ( struct V_17 * V_18 ,
struct V_2 * V_3 ,
struct V_23 * args )
{
unsigned int V_24 = F_21 ( args -> V_25 * args -> V_26 , 8 ) ;
struct V_1 * V_5 ;
if ( args -> V_27 < V_24 )
args -> V_27 = V_24 ;
if ( args -> V_4 < args -> V_27 * args -> V_28 )
args -> V_4 = args -> V_27 * args -> V_28 ;
V_5 = F_14 ( V_18 , V_3 , args -> V_4 ,
& args -> V_19 ) ;
return F_22 ( V_5 ) ;
}
int F_23 ( struct V_17 * V_18 ,
struct V_2 * V_3 ,
struct V_23 * args )
{
struct V_1 * V_5 ;
args -> V_27 = F_21 ( args -> V_25 * args -> V_26 , 8 ) ;
args -> V_4 = args -> V_27 * args -> V_28 ;
V_5 = F_14 ( V_18 , V_3 , args -> V_4 ,
& args -> V_19 ) ;
return F_22 ( V_5 ) ;
}
int F_24 ( struct V_17 * V_18 ,
struct V_2 * V_3 , T_3 V_19 ,
T_4 * V_29 )
{
struct V_6 * V_7 ;
V_7 = F_25 ( V_3 , V_18 , V_19 ) ;
if ( ! V_7 ) {
F_12 ( V_3 -> V_14 , L_2 ) ;
return - V_30 ;
}
* V_29 = F_26 ( & V_7 -> V_31 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_5 ,
struct V_32 * V_33 )
{
int V_8 ;
V_33 -> V_34 &= ~ V_35 ;
V_33 -> V_36 = 0 ;
V_8 = F_28 ( V_5 -> V_11 . V_14 -> V_14 , V_33 ,
V_5 -> V_13 , V_5 -> V_15 ,
V_33 -> V_37 - V_33 -> V_38 ) ;
if ( V_8 )
F_29 ( V_33 ) ;
return V_8 ;
}
int F_30 ( struct V_39 * V_40 , struct V_32 * V_33 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_31 ( V_40 , V_33 ) ;
if ( V_8 )
return V_8 ;
V_7 = V_33 -> V_41 ;
V_5 = F_17 ( V_7 ) ;
return F_27 ( V_5 , V_33 ) ;
}
void F_32 ( struct V_1 * V_5 ,
struct V_42 * V_43 )
{
struct V_6 * V_44 = & V_5 -> V_11 ;
T_5 V_45 ;
V_45 = F_33 ( & V_44 -> V_31 ) ;
F_34 ( V_43 , L_3 ,
V_44 -> V_46 , V_44 -> V_47 . V_47 . V_48 ,
V_45 , & V_5 -> V_15 , V_5 -> V_13 , V_44 -> V_4 ) ;
F_34 ( V_43 , L_4 ) ;
}
struct V_49 * F_35 ( struct V_6 * V_44 )
{
struct V_1 * V_5 = F_17 ( V_44 ) ;
struct V_49 * V_22 ;
int V_8 ;
V_22 = F_2 ( sizeof( * V_22 ) , V_9 ) ;
if ( ! V_22 )
return NULL ;
V_8 = F_36 ( V_44 -> V_14 -> V_14 , V_22 , V_5 -> V_13 ,
V_5 -> V_15 , V_44 -> V_4 ) ;
if ( V_8 < 0 )
goto V_50;
return V_22 ;
V_50:
F_7 ( V_22 ) ;
return NULL ;
}
struct V_6 *
F_37 ( struct V_2 * V_14 ,
struct V_51 * V_52 ,
struct V_49 * V_22 )
{
struct V_1 * V_5 ;
if ( V_22 -> V_53 != 1 )
return F_3 ( - V_30 ) ;
V_5 = F_1 ( V_14 , V_52 -> V_54 -> V_4 ) ;
if ( F_10 ( V_5 ) )
return F_38 ( V_5 ) ;
V_5 -> V_15 = F_39 ( V_22 -> V_55 ) ;
V_5 -> V_22 = V_22 ;
F_40 ( L_5 , & V_5 -> V_15 , V_52 -> V_54 -> V_4 ) ;
return & V_5 -> V_11 ;
}
int F_41 ( struct V_6 * V_44 ,
struct V_32 * V_33 )
{
struct V_1 * V_5 ;
int V_8 ;
V_8 = F_42 ( V_44 , V_44 -> V_4 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_17 ( V_44 ) ;
return F_27 ( V_5 , V_33 ) ;
}
void * F_43 ( struct V_6 * V_44 )
{
struct V_1 * V_5 = F_17 ( V_44 ) ;
return V_5 -> V_13 ;
}
void F_44 ( struct V_6 * V_44 , void * V_13 )
{
}
