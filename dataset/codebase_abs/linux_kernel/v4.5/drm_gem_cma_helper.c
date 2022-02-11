static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
if ( V_3 -> V_9 -> V_10 )
V_7 = V_3 -> V_9 -> V_10 ( V_3 , V_4 ) ;
else
V_7 = F_2 ( sizeof( * V_5 ) , V_11 ) ;
if ( ! V_7 )
return F_3 ( - V_12 ) ;
V_5 = F_4 ( V_7 , struct V_1 , V_13 ) ;
V_8 = F_5 ( V_3 , V_7 , V_4 ) ;
if ( V_8 )
goto error;
V_8 = F_6 ( V_7 ) ;
if ( V_8 ) {
F_7 ( V_7 ) ;
goto error;
}
return V_5 ;
error:
F_8 ( V_5 ) ;
return F_3 ( V_8 ) ;
}
struct V_1 * F_9 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
int V_8 ;
V_4 = F_10 ( V_4 , V_14 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( F_11 ( V_5 ) )
return V_5 ;
V_5 -> V_15 = F_12 ( V_3 -> V_16 , V_4 ,
& V_5 -> V_17 , V_11 | V_18 ) ;
if ( ! V_5 -> V_15 ) {
F_13 ( V_3 -> V_16 , L_1 ,
V_4 ) ;
V_8 = - V_12 ;
goto error;
}
return V_5 ;
error:
V_3 -> V_9 -> V_19 ( & V_5 -> V_13 ) ;
return F_3 ( V_8 ) ;
}
static struct V_1 *
F_14 ( struct V_20 * V_21 ,
struct V_2 * V_3 , T_1 V_4 ,
T_2 * V_22 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_9 ( V_3 , V_4 ) ;
if ( F_11 ( V_5 ) )
return V_5 ;
V_7 = & V_5 -> V_13 ;
V_8 = F_15 ( V_21 , V_7 , V_22 ) ;
if ( V_8 )
goto V_23;
F_16 ( V_7 ) ;
return V_5 ;
V_23:
V_3 -> V_9 -> V_19 ( V_7 ) ;
return F_3 ( V_8 ) ;
}
void F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_5 ;
V_5 = F_18 ( V_7 ) ;
if ( V_5 -> V_15 ) {
F_19 ( V_7 -> V_16 -> V_16 , V_5 -> V_13 . V_4 ,
V_5 -> V_15 , V_5 -> V_17 ) ;
} else if ( V_7 -> V_24 ) {
F_20 ( V_7 , V_5 -> V_25 ) ;
}
F_7 ( V_7 ) ;
F_8 ( V_5 ) ;
}
int F_21 ( struct V_20 * V_21 ,
struct V_2 * V_3 ,
struct V_26 * args )
{
unsigned int V_27 = F_22 ( args -> V_28 * args -> V_29 , 8 ) ;
struct V_1 * V_5 ;
if ( args -> V_30 < V_27 )
args -> V_30 = V_27 ;
if ( args -> V_4 < args -> V_30 * args -> V_31 )
args -> V_4 = args -> V_30 * args -> V_31 ;
V_5 = F_14 ( V_21 , V_3 , args -> V_4 ,
& args -> V_22 ) ;
return F_23 ( V_5 ) ;
}
int F_24 ( struct V_20 * V_21 ,
struct V_2 * V_3 ,
struct V_26 * args )
{
struct V_1 * V_5 ;
args -> V_30 = F_22 ( args -> V_28 * args -> V_29 , 8 ) ;
args -> V_4 = args -> V_30 * args -> V_31 ;
V_5 = F_14 ( V_21 , V_3 , args -> V_4 ,
& args -> V_22 ) ;
return F_23 ( V_5 ) ;
}
int F_25 ( struct V_20 * V_21 ,
struct V_2 * V_3 , T_3 V_22 ,
T_4 * V_32 )
{
struct V_6 * V_7 ;
V_7 = F_26 ( V_3 , V_21 , V_22 ) ;
if ( ! V_7 ) {
F_13 ( V_3 -> V_16 , L_2 ) ;
return - V_33 ;
}
* V_32 = F_27 ( & V_7 -> V_34 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_5 ,
struct V_35 * V_36 )
{
int V_8 ;
V_36 -> V_37 &= ~ V_38 ;
V_36 -> V_39 = 0 ;
V_8 = F_29 ( V_5 -> V_13 . V_16 -> V_16 , V_36 ,
V_5 -> V_15 , V_5 -> V_17 ,
V_36 -> V_40 - V_36 -> V_41 ) ;
if ( V_8 )
F_30 ( V_36 ) ;
return V_8 ;
}
int F_31 ( struct V_42 * V_43 , struct V_35 * V_36 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_32 ( V_43 , V_36 ) ;
if ( V_8 )
return V_8 ;
V_7 = V_36 -> V_44 ;
V_5 = F_18 ( V_7 ) ;
return F_28 ( V_5 , V_36 ) ;
}
void F_33 ( struct V_1 * V_5 ,
struct V_45 * V_46 )
{
struct V_6 * V_47 = & V_5 -> V_13 ;
T_5 V_48 ;
V_48 = F_34 ( & V_47 -> V_34 ) ;
F_35 ( V_46 , L_3 ,
V_47 -> V_49 , V_47 -> V_50 . V_50 . V_51 ,
V_48 , & V_5 -> V_17 , V_5 -> V_15 , V_47 -> V_4 ) ;
F_35 ( V_46 , L_4 ) ;
}
struct V_52 * F_36 ( struct V_6 * V_47 )
{
struct V_1 * V_5 = F_18 ( V_47 ) ;
struct V_52 * V_25 ;
int V_8 ;
V_25 = F_2 ( sizeof( * V_25 ) , V_11 ) ;
if ( ! V_25 )
return NULL ;
V_8 = F_37 ( V_47 -> V_16 -> V_16 , V_25 , V_5 -> V_15 ,
V_5 -> V_17 , V_47 -> V_4 ) ;
if ( V_8 < 0 )
goto V_53;
return V_25 ;
V_53:
F_8 ( V_25 ) ;
return NULL ;
}
struct V_6 *
F_38 ( struct V_2 * V_16 ,
struct V_54 * V_55 ,
struct V_52 * V_25 )
{
struct V_1 * V_5 ;
if ( V_25 -> V_56 != 1 )
return F_3 ( - V_33 ) ;
V_5 = F_1 ( V_16 , V_55 -> V_57 -> V_4 ) ;
if ( F_11 ( V_5 ) )
return F_39 ( V_5 ) ;
V_5 -> V_17 = F_40 ( V_25 -> V_58 ) ;
V_5 -> V_25 = V_25 ;
F_41 ( L_5 , & V_5 -> V_17 , V_55 -> V_57 -> V_4 ) ;
return & V_5 -> V_13 ;
}
int F_42 ( struct V_6 * V_47 ,
struct V_35 * V_36 )
{
struct V_1 * V_5 ;
int V_8 ;
V_8 = F_43 ( V_47 , V_47 -> V_4 , V_36 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_18 ( V_47 ) ;
return F_28 ( V_5 , V_36 ) ;
}
void * F_44 ( struct V_6 * V_47 )
{
struct V_1 * V_5 = F_18 ( V_47 ) ;
return V_5 -> V_15 ;
}
void F_45 ( struct V_6 * V_47 , void * V_15 )
{
}
