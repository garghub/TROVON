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
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_9 == & V_10 ;
}
struct V_3 * F_4 ( void * V_11 , const struct V_12 * V_7 ,
T_1 V_13 , int V_14 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
if ( F_5 ( ! V_11 || ! V_7
|| ! V_7 -> V_15
|| ! V_7 -> V_16
|| ! V_7 -> V_8
|| ! V_7 -> V_17
|| ! V_7 -> V_18 ) ) {
return F_6 ( - V_5 ) ;
}
V_4 = F_7 ( sizeof( struct V_3 ) , V_19 ) ;
if ( V_4 == NULL )
return F_6 ( - V_20 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_13 = V_13 ;
V_2 = F_8 ( L_1 , & V_10 , V_4 , V_14 ) ;
V_4 -> V_2 = V_2 ;
F_9 ( & V_4 -> V_21 ) ;
F_10 ( & V_4 -> V_22 ) ;
return V_4 ;
}
int F_11 ( struct V_3 * V_4 , int V_14 )
{
int error , V_23 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
error = F_12 ( V_14 ) ;
if ( error < 0 )
return error ;
V_23 = error ;
F_13 ( V_23 , V_4 -> V_2 ) ;
return V_23 ;
}
struct V_3 * F_14 ( int V_23 )
{
struct V_2 * V_2 ;
V_2 = F_15 ( V_23 ) ;
if ( ! V_2 )
return F_6 ( - V_24 ) ;
if ( ! F_2 ( V_2 ) ) {
F_16 ( V_2 ) ;
return F_6 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_17 ( struct V_3 * V_4 )
{
if ( F_5 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_16 ( V_4 -> V_2 ) ;
}
struct V_25 * F_18 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_25 * V_28 ;
int V_29 ;
if ( F_5 ( ! V_4 || ! V_27 ) )
return F_6 ( - V_5 ) ;
V_28 = F_7 ( sizeof( struct V_25 ) , V_19 ) ;
if ( V_28 == NULL )
return F_6 ( - V_20 ) ;
V_28 -> V_27 = V_27 ;
V_28 -> V_4 = V_4 ;
F_19 ( & V_4 -> V_21 ) ;
if ( V_4 -> V_7 -> V_28 ) {
V_29 = V_4 -> V_7 -> V_28 ( V_4 , V_27 , V_28 ) ;
if ( V_29 )
goto V_30;
}
F_20 ( & V_28 -> V_31 , & V_4 -> V_22 ) ;
F_21 ( & V_4 -> V_21 ) ;
return V_28 ;
V_30:
F_3 ( V_28 ) ;
F_21 ( & V_4 -> V_21 ) ;
return F_6 ( V_29 ) ;
}
void F_22 ( struct V_3 * V_4 , struct V_25 * V_28 )
{
if ( F_5 ( ! V_4 || ! V_28 ) )
return;
F_19 ( & V_4 -> V_21 ) ;
F_23 ( & V_28 -> V_31 ) ;
if ( V_4 -> V_7 -> V_32 )
V_4 -> V_7 -> V_32 ( V_4 , V_28 ) ;
F_21 ( & V_4 -> V_21 ) ;
F_3 ( V_28 ) ;
}
struct V_33 * F_24 ( struct V_25 * V_28 ,
enum V_34 V_35 )
{
struct V_33 * V_33 = F_6 ( - V_5 ) ;
F_25 () ;
if ( F_5 ( ! V_28 || ! V_28 -> V_4 ) )
return F_6 ( - V_5 ) ;
V_33 = V_28 -> V_4 -> V_7 -> V_15 ( V_28 , V_35 ) ;
return V_33 ;
}
void F_26 ( struct V_25 * V_28 ,
struct V_33 * V_33 ,
enum V_34 V_35 )
{
if ( F_5 ( ! V_28 || ! V_28 -> V_4 || ! V_33 ) )
return;
V_28 -> V_4 -> V_7 -> V_16 ( V_28 , V_33 ,
V_35 ) ;
}
int F_27 ( struct V_3 * V_4 , T_1 V_36 , T_1 V_37 ,
enum V_34 V_35 )
{
int V_29 = 0 ;
if ( F_5 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_7 -> V_38 )
V_29 = V_4 -> V_7 -> V_38 ( V_4 , V_36 , V_37 , V_35 ) ;
return V_29 ;
}
void F_28 ( struct V_3 * V_4 , T_1 V_36 , T_1 V_37 ,
enum V_34 V_35 )
{
F_5 ( ! V_4 ) ;
if ( V_4 -> V_7 -> V_39 )
V_4 -> V_7 -> V_39 ( V_4 , V_36 , V_37 , V_35 ) ;
}
void * F_29 ( struct V_3 * V_4 , unsigned long V_40 )
{
F_5 ( ! V_4 ) ;
return V_4 -> V_7 -> V_17 ( V_4 , V_40 ) ;
}
void F_30 ( struct V_3 * V_4 , unsigned long V_40 ,
void * V_41 )
{
F_5 ( ! V_4 ) ;
if ( V_4 -> V_7 -> V_42 )
V_4 -> V_7 -> V_42 ( V_4 , V_40 , V_41 ) ;
}
void * F_31 ( struct V_3 * V_4 , unsigned long V_40 )
{
F_5 ( ! V_4 ) ;
return V_4 -> V_7 -> V_18 ( V_4 , V_40 ) ;
}
void F_32 ( struct V_3 * V_4 , unsigned long V_40 ,
void * V_41 )
{
F_5 ( ! V_4 ) ;
if ( V_4 -> V_7 -> V_43 )
V_4 -> V_7 -> V_43 ( V_4 , V_40 , V_41 ) ;
}
