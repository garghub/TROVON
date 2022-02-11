struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_6 ) ;
V_5 = F_3 ( & V_3 -> V_7 , V_4 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
void F_6 ( struct V_1 * V_5 ,
struct V_8 * V_9 )
{
struct V_8 * V_10 ;
if ( V_9 )
F_7 ( V_9 ) ;
V_10 = F_8 ( & V_5 -> V_9 , V_9 ) ;
F_9 ( V_10 ) ;
}
int F_10 ( struct V_2 * V_3 ,
T_1 V_4 ,
struct V_8 * * V_9 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
int V_11 = 0 ;
if ( ! V_5 )
return - V_12 ;
* V_9 = F_7 ( V_5 -> V_9 ) ;
if ( ! * V_9 ) {
V_11 = - V_13 ;
}
F_11 ( V_5 ) ;
return V_11 ;
}
void F_12 ( struct V_14 * V_14 )
{
struct V_1 * V_5 = F_13 ( V_14 ,
struct V_1 ,
V_15 ) ;
F_9 ( V_5 -> V_9 ) ;
F_14 ( V_5 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
T_1 * V_4 )
{
int V_11 ;
struct V_1 * V_5 ;
V_5 = F_16 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_5 )
return - V_17 ;
F_17 ( & V_5 -> V_15 ) ;
F_18 ( V_16 ) ;
F_2 ( & V_3 -> V_6 ) ;
V_11 = F_19 ( & V_3 -> V_7 , V_5 , 1 , 0 , V_18 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_20 () ;
if ( V_11 < 0 ) {
F_11 ( V_5 ) ;
return V_11 ;
}
* V_4 = V_11 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 ( & V_3 -> V_6 ) ;
V_5 = F_22 ( & V_3 -> V_7 , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( ! V_5 )
return - V_13 ;
F_11 ( V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_1 * V_5 = V_20 -> V_21 ;
F_11 ( V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_5 )
{
struct V_20 * V_20 = F_25 ( L_1 ,
& V_22 ,
V_5 , 0 ) ;
if ( F_26 ( V_20 ) )
return F_27 ( V_20 ) ;
F_4 ( V_5 ) ;
if ( F_28 ( & V_5 -> V_20 , NULL , V_20 ) ) {
F_29 ( V_20 ) ;
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
T_1 V_4 , int * V_23 )
{
struct V_1 * V_5 = F_1 ( V_3 , V_4 ) ;
int V_11 ;
int V_24 ;
if ( ! V_5 )
return - V_13 ;
V_24 = F_31 ( V_25 ) ;
if ( V_24 < 0 ) {
F_11 ( V_5 ) ;
return V_24 ;
}
if ( ! V_5 -> V_20 ) {
V_11 = F_24 ( V_5 ) ;
if ( V_11 )
goto V_26;
}
F_32 ( V_24 , V_5 -> V_20 ) ;
F_11 ( V_5 ) ;
* V_23 = V_24 ;
return 0 ;
V_26:
F_33 ( V_24 ) ;
F_11 ( V_5 ) ;
return V_11 ;
}
static struct V_1 * F_34 ( int V_24 )
{
struct V_20 * V_20 = F_35 ( V_24 ) ;
if ( ! V_20 )
return NULL ;
if ( V_20 -> V_27 != & V_22 )
goto V_28;
return V_20 -> V_21 ;
V_28:
F_29 ( V_20 ) ;
return NULL ;
}
static int F_36 ( struct V_2 * V_3 ,
int V_24 , T_1 * V_4 )
{
struct V_1 * V_5 = F_34 ( V_24 ) ;
int V_11 ;
if ( ! V_5 )
return - V_13 ;
F_4 ( V_5 ) ;
F_18 ( V_16 ) ;
F_2 ( & V_3 -> V_6 ) ;
V_11 = F_19 ( & V_3 -> V_7 , V_5 , 1 , 0 , V_18 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_20 () ;
if ( V_11 < 0 ) {
F_29 ( V_5 -> V_20 ) ;
return V_11 ;
}
* V_4 = V_11 ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 ,
int V_24 , int V_4 )
{
struct V_8 * V_9 = F_38 ( V_24 ) ;
struct V_1 * V_5 ;
if ( ! V_9 )
return - V_13 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_9 ( V_9 ) ;
return - V_12 ;
}
F_6 ( V_5 , V_9 ) ;
F_9 ( V_9 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
int F_39 ( struct V_2 * V_3 ,
int V_4 , int * V_23 )
{
int V_11 ;
struct V_8 * V_9 ;
struct V_29 * V_29 ;
int V_24 = F_31 ( V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_11 = F_10 ( V_3 , V_4 , & V_9 ) ;
if ( V_11 )
goto V_30;
V_29 = F_40 ( V_9 ) ;
F_9 ( V_9 ) ;
if ( ! V_29 ) {
V_11 = - V_13 ;
goto V_30;
}
F_32 ( V_24 , V_29 -> V_20 ) ;
* V_23 = V_24 ;
return 0 ;
V_30:
F_33 ( V_24 ) ;
return V_11 ;
}
void
F_41 ( struct V_2 * V_3 )
{
F_42 ( & V_3 -> V_7 ) ;
F_43 ( & V_3 -> V_6 ) ;
}
static int
F_44 ( int V_31 , void * V_32 , void * V_33 )
{
struct V_1 * V_5 = V_32 ;
F_11 ( V_5 ) ;
return 0 ;
}
void
F_45 ( struct V_2 * V_3 )
{
F_46 ( & V_3 -> V_7 ,
& F_44 , V_3 ) ;
F_47 ( & V_3 -> V_7 ) ;
}
int
F_48 ( struct V_34 * V_35 , void * V_33 ,
struct V_2 * V_3 )
{
struct F_15 * args = V_33 ;
if ( ! F_49 ( V_35 , V_36 ) )
return - V_37 ;
if ( args -> V_38 )
return - V_13 ;
return F_15 ( V_3 ,
& args -> V_4 ) ;
}
int
F_50 ( struct V_34 * V_35 , void * V_33 ,
struct V_2 * V_3 )
{
struct F_21 * args = V_33 ;
if ( ! F_49 ( V_35 , V_36 ) )
return - V_37 ;
if ( args -> V_39 )
return - V_13 ;
return F_21 ( V_3 , args -> V_4 ) ;
}
int
F_51 ( struct V_34 * V_35 , void * V_33 ,
struct V_2 * V_3 )
{
struct V_40 * args = V_33 ;
if ( ! F_49 ( V_35 , V_36 ) )
return - V_37 ;
if ( args -> V_39 )
return - V_13 ;
if ( args -> V_38 != 0 &&
args -> V_38 != V_41 )
return - V_13 ;
if ( args -> V_38 & V_41 )
return F_39 ( V_3 , args -> V_4 ,
& args -> V_24 ) ;
return F_30 ( V_3 , args -> V_4 ,
& args -> V_24 ) ;
}
int
F_52 ( struct V_34 * V_35 , void * V_33 ,
struct V_2 * V_3 )
{
struct V_40 * args = V_33 ;
if ( ! F_49 ( V_35 , V_36 ) )
return - V_37 ;
if ( args -> V_39 )
return - V_13 ;
if ( args -> V_38 != 0 &&
args -> V_38 != V_42 )
return - V_13 ;
if ( args -> V_38 & V_42 )
return F_37 ( V_3 ,
args -> V_24 ,
args -> V_4 ) ;
return F_36 ( V_3 , args -> V_24 ,
& args -> V_4 ) ;
}
