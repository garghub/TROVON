static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( & V_2 -> V_9 ) ;
F_3 ( V_10 , & V_2 -> V_9 ) ;
V_2 -> V_11 = F_4 ( V_7 -> V_8 , V_4 -> V_12 ,
& V_2 -> V_13 , V_14 ,
& V_2 -> V_9 ) ;
if ( F_5 ( V_2 -> V_11 ) ) {
int V_15 = F_6 ( V_2 -> V_11 ) ;
F_7 ( L_1 ,
V_4 -> V_12 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_9 ( V_7 -> V_8 , V_4 -> V_12 , V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_9 ) ;
}
int F_10 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
unsigned long V_18 ;
V_17 -> V_19 |= V_20 | V_21 | V_22 ;
V_18 = V_17 -> V_23 - V_17 -> V_24 ;
if ( V_18 > V_4 -> V_12 )
return - V_25 ;
return F_12 ( V_7 -> V_8 , V_17 , V_2 -> V_11 , V_2 -> V_13 ,
V_4 -> V_12 , & V_2 -> V_9 ) ;
}
int F_13 ( struct V_26 * V_27 , struct V_16 * V_17 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_6 * V_8 = V_29 -> V_31 -> V_8 ;
struct V_3 * V_4 ;
struct V_32 * V_33 ;
int V_15 ;
if ( F_14 ( V_8 ) )
return - V_34 ;
F_15 ( & V_8 -> V_35 ) ;
V_33 = F_16 ( V_8 -> V_36 ,
V_17 -> V_37 ,
F_17 ( V_17 ) ) ;
if ( ! V_33 ) {
F_18 ( & V_8 -> V_35 ) ;
F_7 ( L_2 ) ;
return - V_25 ;
} else if ( ! F_19 ( V_33 , V_27 ) ) {
F_18 ( & V_8 -> V_35 ) ;
return - V_38 ;
}
V_4 = F_20 ( V_33 , struct V_3 , V_39 ) ;
V_15 = F_10 ( V_4 , V_17 ) ;
F_18 ( & V_8 -> V_35 ) ;
return V_15 ;
}
struct V_1 *
F_21 ( struct V_6 * V_7 , unsigned int V_12 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_12 = F_22 ( V_12 , V_40 ) ;
V_2 = F_23 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return F_24 ( - V_41 ) ;
V_4 = & V_2 -> V_5 ;
F_25 ( V_7 , V_4 , V_12 ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
goto V_42;
return V_2 ;
V_42:
F_26 ( V_2 ) ;
return F_24 ( V_15 ) ;
}
void F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_28 ( V_4 ) ;
V_2 = F_11 ( V_4 ) ;
F_8 ( V_2 ) ;
F_26 ( V_2 ) ;
}
static struct V_1 *
F_29 ( struct V_28 * V_43 ,
struct V_6 * V_7 , unsigned int V_12 ,
unsigned int * V_44 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_15 ;
V_2 = F_21 ( V_7 , V_12 ) ;
if ( F_5 ( V_2 ) )
return F_30 ( V_2 ) ;
V_4 = & V_2 -> V_5 ;
V_15 = F_31 ( V_43 , V_4 , V_44 ) ;
if ( V_15 )
goto V_45;
F_32 ( V_4 ) ;
return V_2 ;
V_45:
F_27 ( V_4 ) ;
return F_24 ( V_15 ) ;
}
int F_33 ( struct V_28 * V_43 ,
struct V_6 * V_8 , T_1 V_44 ,
T_2 * V_46 )
{
struct V_3 * V_4 ;
int V_15 ;
F_15 ( & V_8 -> V_35 ) ;
V_4 = F_34 ( V_8 , V_43 , V_44 ) ;
if ( ! V_4 ) {
F_7 ( L_3 ) ;
V_15 = - V_25 ;
goto V_47;
}
V_15 = F_35 ( V_4 ) ;
if ( V_15 )
goto V_48;
* V_46 = F_36 ( & V_4 -> V_39 ) ;
F_37 ( L_4 , * V_46 ) ;
V_48:
F_38 ( V_4 ) ;
V_47:
F_18 ( & V_8 -> V_35 ) ;
return V_15 ;
}
int F_39 ( struct V_28 * V_43 ,
struct V_6 * V_8 ,
struct V_49 * args )
{
struct V_1 * V_2 ;
int V_50 = F_40 ( args -> V_51 * args -> V_52 , 8 ) ;
V_50 = F_41 ( V_50 , 64 ) ;
if ( args -> V_53 < V_50 )
args -> V_53 = V_50 ;
if ( args -> V_12 < args -> V_53 * args -> V_54 )
args -> V_12 = args -> V_53 * args -> V_54 ;
V_2 = F_29 ( V_43 , V_8 , args -> V_12 ,
& args -> V_44 ) ;
return F_42 ( V_2 ) ;
}
struct V_55 * F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_55 * V_56 ;
int V_15 ;
V_56 = F_23 ( sizeof( * V_56 ) , V_14 ) ;
if ( ! V_56 )
return F_24 ( - V_41 ) ;
V_15 = F_44 ( V_7 -> V_8 , V_56 , V_2 -> V_11 ,
V_2 -> V_13 , V_4 -> V_12 ,
& V_2 -> V_9 ) ;
if ( V_15 ) {
F_7 ( L_5 , V_15 ) ;
F_26 ( V_56 ) ;
return F_24 ( V_15 ) ;
}
return V_56 ;
}
void * F_45 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_11 ( V_4 ) ;
return V_2 -> V_11 ;
}
void F_46 ( struct V_3 * V_4 , void * V_57 )
{
}
