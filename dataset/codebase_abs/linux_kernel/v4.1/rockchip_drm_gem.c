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
int F_8 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
unsigned long V_20 ;
V_19 -> V_21 |= V_22 | V_23 | V_24 ;
V_20 = V_19 -> V_25 - V_19 -> V_26 ;
if ( V_20 > V_5 -> V_14 )
return - V_27 ;
return F_10 ( V_8 -> V_9 , V_19 , V_2 -> V_13 , V_2 -> V_15 ,
V_5 -> V_14 , & V_2 -> V_10 ) ;
}
int F_11 ( struct V_28 * V_29 , struct V_18 * V_19 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
struct V_7 * V_9 = V_31 -> V_33 -> V_9 ;
struct V_4 * V_5 ;
struct V_34 * V_35 ;
int V_36 ;
if ( F_12 ( V_9 ) )
return - V_37 ;
F_13 ( & V_9 -> V_38 ) ;
V_35 = F_14 ( V_9 -> V_39 ,
V_19 -> V_40 ,
F_15 ( V_19 ) ) ;
if ( ! V_35 ) {
F_16 ( & V_9 -> V_38 ) ;
F_5 ( L_2 ) ;
return - V_27 ;
} else if ( ! F_17 ( V_35 , V_29 ) ) {
F_16 ( & V_9 -> V_38 ) ;
return - V_41 ;
}
V_5 = F_18 ( V_35 , struct V_4 , V_42 ) ;
V_36 = F_8 ( V_5 , V_19 ) ;
F_16 ( & V_9 -> V_38 ) ;
return V_36 ;
}
struct V_1 *
F_19 ( struct V_7 * V_8 , unsigned int V_14 ,
bool V_3 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_36 ;
V_14 = F_20 ( V_14 , V_43 ) ;
V_2 = F_21 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return F_22 ( - V_17 ) ;
V_5 = & V_2 -> V_6 ;
F_23 ( V_8 , V_5 , V_14 ) ;
V_36 = F_1 ( V_2 , V_3 ) ;
if ( V_36 )
goto V_44;
return V_2 ;
V_44:
F_24 ( V_2 ) ;
return F_22 ( V_36 ) ;
}
void F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
F_26 ( V_5 ) ;
V_2 = F_9 ( V_5 ) ;
F_6 ( V_2 ) ;
F_24 ( V_2 ) ;
}
static struct V_1 *
F_27 ( struct V_30 * V_45 ,
struct V_7 * V_8 , unsigned int V_14 ,
unsigned int * V_46 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_36 ;
V_2 = F_19 ( V_8 , V_14 , false ) ;
if ( F_28 ( V_2 ) )
return F_29 ( V_2 ) ;
V_5 = & V_2 -> V_6 ;
V_36 = F_30 ( V_45 , V_5 , V_46 ) ;
if ( V_36 )
goto V_47;
F_31 ( V_5 ) ;
return V_2 ;
V_47:
F_25 ( V_5 ) ;
return F_22 ( V_36 ) ;
}
int F_32 ( struct V_30 * V_45 ,
struct V_7 * V_9 , T_1 V_46 ,
T_2 * V_48 )
{
struct V_4 * V_5 ;
int V_36 ;
F_13 ( & V_9 -> V_38 ) ;
V_5 = F_33 ( V_9 , V_45 , V_46 ) ;
if ( ! V_5 ) {
F_5 ( L_3 ) ;
V_36 = - V_27 ;
goto V_49;
}
V_36 = F_34 ( V_5 ) ;
if ( V_36 )
goto V_50;
* V_48 = F_35 ( & V_5 -> V_42 ) ;
F_36 ( L_4 , * V_48 ) ;
V_50:
F_37 ( V_5 ) ;
V_49:
F_16 ( & V_9 -> V_38 ) ;
return V_36 ;
}
int F_38 ( struct V_30 * V_45 ,
struct V_7 * V_9 ,
struct V_51 * args )
{
struct V_1 * V_2 ;
int V_52 = F_39 ( args -> V_53 * args -> V_54 , 8 ) ;
V_52 = F_40 ( V_52 , 64 ) ;
if ( args -> V_55 < V_52 )
args -> V_55 = V_52 ;
if ( args -> V_14 < args -> V_55 * args -> V_56 )
args -> V_14 = args -> V_55 * args -> V_56 ;
V_2 = F_27 ( V_45 , V_9 , args -> V_14 ,
& args -> V_46 ) ;
return F_41 ( V_2 ) ;
}
struct V_57 * F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_57 * V_58 ;
int V_36 ;
V_58 = F_21 ( sizeof( * V_58 ) , V_16 ) ;
if ( ! V_58 )
return F_22 ( - V_17 ) ;
V_36 = F_43 ( V_8 -> V_9 , V_58 , V_2 -> V_13 ,
V_2 -> V_15 , V_5 -> V_14 ,
& V_2 -> V_10 ) ;
if ( V_36 ) {
F_5 ( L_5 , V_36 ) ;
F_24 ( V_58 ) ;
return F_22 ( V_36 ) ;
}
return V_58 ;
}
void * F_44 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
if ( F_45 ( V_12 , & V_2 -> V_10 ) )
return NULL ;
return V_2 -> V_13 ;
}
void F_46 ( struct V_4 * V_5 , void * V_59 )
{
}
