static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 ( V_10 , & V_2 -> V_9 ) ;
V_2 -> V_11 = F_4 ( V_7 -> V_8 , V_4 -> V_12 ,
& V_2 -> V_13 , V_14 ,
& V_2 -> V_9 ) ;
if ( ! V_2 -> V_11 ) {
F_5 ( L_1 , V_4 -> V_12 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_7 ( V_7 -> V_8 , V_4 -> V_12 , V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_9 ) ;
}
int F_8 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
unsigned long V_18 ;
V_17 -> V_19 |= V_20 | V_21 | V_22 ;
V_18 = V_17 -> V_23 - V_17 -> V_24 ;
if ( V_18 > V_4 -> V_12 )
return - V_25 ;
return F_10 ( V_7 -> V_8 , V_17 , V_2 -> V_11 , V_2 -> V_13 ,
V_4 -> V_12 , & V_2 -> V_9 ) ;
}
int F_11 ( struct V_26 * V_27 , struct V_16 * V_17 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_6 * V_8 = V_29 -> V_31 -> V_8 ;
struct V_3 * V_4 ;
struct V_32 * V_33 ;
int V_34 ;
if ( F_12 ( V_8 ) )
return - V_35 ;
F_13 ( & V_8 -> V_36 ) ;
V_33 = F_14 ( V_8 -> V_37 ,
V_17 -> V_38 ,
F_15 ( V_17 ) ) ;
if ( ! V_33 ) {
F_16 ( & V_8 -> V_36 ) ;
F_5 ( L_2 ) ;
return - V_25 ;
} else if ( ! F_17 ( V_33 , V_27 ) ) {
F_16 ( & V_8 -> V_36 ) ;
return - V_39 ;
}
V_4 = F_18 ( V_33 , struct V_3 , V_40 ) ;
V_34 = F_8 ( V_4 , V_17 ) ;
F_16 ( & V_8 -> V_36 ) ;
return V_34 ;
}
struct V_1 *
F_19 ( struct V_6 * V_7 , unsigned int V_12 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_34 ;
V_12 = F_20 ( V_12 , V_41 ) ;
V_2 = F_21 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return F_22 ( - V_15 ) ;
V_4 = & V_2 -> V_5 ;
F_23 ( V_7 , V_4 , V_12 ) ;
V_34 = F_1 ( V_2 ) ;
if ( V_34 )
goto V_42;
return V_2 ;
V_42:
F_24 ( V_2 ) ;
return F_22 ( V_34 ) ;
}
void F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_26 ( V_4 ) ;
V_2 = F_9 ( V_4 ) ;
F_6 ( V_2 ) ;
F_24 ( V_2 ) ;
}
static struct V_1 *
F_27 ( struct V_28 * V_43 ,
struct V_6 * V_7 , unsigned int V_12 ,
unsigned int * V_44 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_34 ;
V_2 = F_19 ( V_7 , V_12 ) ;
if ( F_28 ( V_2 ) )
return F_29 ( V_2 ) ;
V_4 = & V_2 -> V_5 ;
V_34 = F_30 ( V_43 , V_4 , V_44 ) ;
if ( V_34 )
goto V_45;
F_31 ( V_4 ) ;
return V_2 ;
V_45:
F_25 ( V_4 ) ;
return F_22 ( V_34 ) ;
}
int F_32 ( struct V_28 * V_43 ,
struct V_6 * V_8 , T_1 V_44 ,
T_2 * V_46 )
{
struct V_3 * V_4 ;
int V_34 ;
F_13 ( & V_8 -> V_36 ) ;
V_4 = F_33 ( V_8 , V_43 , V_44 ) ;
if ( ! V_4 ) {
F_5 ( L_3 ) ;
V_34 = - V_25 ;
goto V_47;
}
V_34 = F_34 ( V_4 ) ;
if ( V_34 )
goto V_48;
* V_46 = F_35 ( & V_4 -> V_40 ) ;
F_36 ( L_4 , * V_46 ) ;
V_48:
F_37 ( V_4 ) ;
V_47:
F_16 ( & V_8 -> V_36 ) ;
return V_34 ;
}
int F_38 ( struct V_28 * V_43 ,
struct V_6 * V_8 ,
struct V_49 * args )
{
struct V_1 * V_2 ;
int V_50 = F_39 ( args -> V_51 * args -> V_52 , 8 ) ;
V_50 = F_40 ( V_50 , 64 ) ;
if ( args -> V_53 < V_50 )
args -> V_53 = V_50 ;
if ( args -> V_12 < args -> V_53 * args -> V_54 )
args -> V_12 = args -> V_53 * args -> V_54 ;
V_2 = F_27 ( V_43 , V_8 , args -> V_12 ,
& args -> V_44 ) ;
return F_41 ( V_2 ) ;
}
struct V_55 * F_42 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_55 * V_56 ;
int V_34 ;
V_56 = F_21 ( sizeof( * V_56 ) , V_14 ) ;
if ( ! V_56 )
return F_22 ( - V_15 ) ;
V_34 = F_43 ( V_7 -> V_8 , V_56 , V_2 -> V_11 ,
V_2 -> V_13 , V_4 -> V_12 ,
& V_2 -> V_9 ) ;
if ( V_34 ) {
F_5 ( L_5 , V_34 ) ;
F_24 ( V_56 ) ;
return F_22 ( V_34 ) ;
}
return V_56 ;
}
void * F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 ) ;
return V_2 -> V_11 ;
}
void F_45 ( struct V_3 * V_4 , void * V_57 )
{
}
