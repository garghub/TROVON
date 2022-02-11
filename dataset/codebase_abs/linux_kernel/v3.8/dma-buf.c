static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
V_4 -> V_7 -> V_8 ( V_4 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_2 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
if ( V_10 -> V_11 + ( ( V_10 -> V_12 - V_10 -> V_13 ) >> V_14 ) >
V_4 -> V_15 >> V_14 )
return - V_5 ;
return V_4 -> V_7 -> V_16 ( V_4 , V_10 ) ;
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_17 == & V_18 ;
}
struct V_3 * F_5 ( void * V_19 , const struct V_20 * V_7 ,
T_1 V_15 , int V_21 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
if ( F_6 ( ! V_19 || ! V_7
|| ! V_7 -> V_22
|| ! V_7 -> V_23
|| ! V_7 -> V_8
|| ! V_7 -> V_24
|| ! V_7 -> V_25
|| ! V_7 -> V_16 ) ) {
return F_7 ( - V_5 ) ;
}
V_4 = F_8 ( sizeof( struct V_3 ) , V_26 ) ;
if ( V_4 == NULL )
return F_7 ( - V_27 ) ;
V_4 -> V_19 = V_19 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_15 = V_15 ;
V_2 = F_9 ( L_1 , & V_18 , V_4 , V_21 ) ;
V_4 -> V_2 = V_2 ;
F_10 ( & V_4 -> V_28 ) ;
F_11 ( & V_4 -> V_29 ) ;
return V_4 ;
}
int F_12 ( struct V_3 * V_4 , int V_21 )
{
int error , V_30 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
error = F_13 ( V_21 ) ;
if ( error < 0 )
return error ;
V_30 = error ;
F_14 ( V_30 , V_4 -> V_2 ) ;
return V_30 ;
}
struct V_3 * F_15 ( int V_30 )
{
struct V_2 * V_2 ;
V_2 = F_16 ( V_30 ) ;
if ( ! V_2 )
return F_7 ( - V_31 ) ;
if ( ! F_2 ( V_2 ) ) {
F_17 ( V_2 ) ;
return F_7 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_18 ( struct V_3 * V_4 )
{
if ( F_6 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_17 ( V_4 -> V_2 ) ;
}
struct V_32 * F_19 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_32 * V_35 ;
int V_36 ;
if ( F_6 ( ! V_4 || ! V_34 ) )
return F_7 ( - V_5 ) ;
V_35 = F_8 ( sizeof( struct V_32 ) , V_26 ) ;
if ( V_35 == NULL )
return F_7 ( - V_27 ) ;
V_35 -> V_34 = V_34 ;
V_35 -> V_4 = V_4 ;
F_20 ( & V_4 -> V_28 ) ;
if ( V_4 -> V_7 -> V_35 ) {
V_36 = V_4 -> V_7 -> V_35 ( V_4 , V_34 , V_35 ) ;
if ( V_36 )
goto V_37;
}
F_21 ( & V_35 -> V_38 , & V_4 -> V_29 ) ;
F_22 ( & V_4 -> V_28 ) ;
return V_35 ;
V_37:
F_3 ( V_35 ) ;
F_22 ( & V_4 -> V_28 ) ;
return F_7 ( V_36 ) ;
}
void F_23 ( struct V_3 * V_4 , struct V_32 * V_35 )
{
if ( F_6 ( ! V_4 || ! V_35 ) )
return;
F_20 ( & V_4 -> V_28 ) ;
F_24 ( & V_35 -> V_38 ) ;
if ( V_4 -> V_7 -> V_39 )
V_4 -> V_7 -> V_39 ( V_4 , V_35 ) ;
F_22 ( & V_4 -> V_28 ) ;
F_3 ( V_35 ) ;
}
struct V_40 * F_25 ( struct V_32 * V_35 ,
enum V_41 V_42 )
{
struct V_40 * V_40 = F_7 ( - V_5 ) ;
F_26 () ;
if ( F_6 ( ! V_35 || ! V_35 -> V_4 ) )
return F_7 ( - V_5 ) ;
V_40 = V_35 -> V_4 -> V_7 -> V_22 ( V_35 , V_42 ) ;
return V_40 ;
}
void F_27 ( struct V_32 * V_35 ,
struct V_40 * V_40 ,
enum V_41 V_42 )
{
F_26 () ;
if ( F_6 ( ! V_35 || ! V_35 -> V_4 || ! V_40 ) )
return;
V_35 -> V_4 -> V_7 -> V_23 ( V_35 , V_40 ,
V_42 ) ;
}
int F_28 ( struct V_3 * V_4 , T_1 V_43 , T_1 V_44 ,
enum V_41 V_42 )
{
int V_36 = 0 ;
if ( F_6 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_7 -> V_45 )
V_36 = V_4 -> V_7 -> V_45 ( V_4 , V_43 , V_44 , V_42 ) ;
return V_36 ;
}
void F_29 ( struct V_3 * V_4 , T_1 V_43 , T_1 V_44 ,
enum V_41 V_42 )
{
F_6 ( ! V_4 ) ;
if ( V_4 -> V_7 -> V_46 )
V_4 -> V_7 -> V_46 ( V_4 , V_43 , V_44 , V_42 ) ;
}
void * F_30 ( struct V_3 * V_4 , unsigned long V_47 )
{
F_6 ( ! V_4 ) ;
return V_4 -> V_7 -> V_24 ( V_4 , V_47 ) ;
}
void F_31 ( struct V_3 * V_4 , unsigned long V_47 ,
void * V_48 )
{
F_6 ( ! V_4 ) ;
if ( V_4 -> V_7 -> V_49 )
V_4 -> V_7 -> V_49 ( V_4 , V_47 , V_48 ) ;
}
void * F_32 ( struct V_3 * V_4 , unsigned long V_47 )
{
F_6 ( ! V_4 ) ;
return V_4 -> V_7 -> V_25 ( V_4 , V_47 ) ;
}
void F_33 ( struct V_3 * V_4 , unsigned long V_47 ,
void * V_48 )
{
F_6 ( ! V_4 ) ;
if ( V_4 -> V_7 -> V_50 )
V_4 -> V_7 -> V_50 ( V_4 , V_47 , V_48 ) ;
}
int F_34 ( struct V_3 * V_4 , struct V_9 * V_10 ,
unsigned long V_51 )
{
if ( F_6 ( ! V_4 || ! V_10 ) )
return - V_5 ;
if ( V_51 + ( ( V_10 -> V_12 - V_10 -> V_13 ) >> V_14 ) < V_51 )
return - V_52 ;
if ( V_51 + ( ( V_10 -> V_12 - V_10 -> V_13 ) >> V_14 ) >
V_4 -> V_15 >> V_14 )
return - V_5 ;
if ( V_10 -> V_53 )
F_17 ( V_10 -> V_53 ) ;
V_10 -> V_53 = F_35 ( V_4 -> V_2 ) ;
V_10 -> V_11 = V_51 ;
return V_4 -> V_7 -> V_16 ( V_4 , V_10 ) ;
}
void * F_36 ( struct V_3 * V_4 )
{
if ( F_6 ( ! V_4 ) )
return NULL ;
if ( V_4 -> V_7 -> V_54 )
return V_4 -> V_7 -> V_54 ( V_4 ) ;
return NULL ;
}
void F_37 ( struct V_3 * V_4 , void * V_48 )
{
if ( F_6 ( ! V_4 ) )
return;
if ( V_4 -> V_7 -> V_55 )
V_4 -> V_7 -> V_55 ( V_4 , V_48 ) ;
}
