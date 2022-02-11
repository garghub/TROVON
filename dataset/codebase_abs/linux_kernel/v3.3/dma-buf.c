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
struct V_3 * F_4 ( void * V_11 , struct V_12 * V_7 ,
T_1 V_13 , int V_14 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
if ( F_5 ( ! V_11 || ! V_7
|| ! V_7 -> V_15
|| ! V_7 -> V_16
|| ! V_7 -> V_8 ) ) {
return F_6 ( - V_5 ) ;
}
V_4 = F_7 ( sizeof( struct V_3 ) , V_17 ) ;
if ( V_4 == NULL )
return F_6 ( - V_18 ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_13 = V_13 ;
V_2 = F_8 ( L_1 , & V_10 , V_4 , V_14 ) ;
V_4 -> V_2 = V_2 ;
F_9 ( & V_4 -> V_19 ) ;
F_10 ( & V_4 -> V_20 ) ;
return V_4 ;
}
int F_11 ( struct V_3 * V_4 )
{
int error , V_21 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
error = F_12 () ;
if ( error < 0 )
return error ;
V_21 = error ;
F_13 ( V_21 , V_4 -> V_2 ) ;
return V_21 ;
}
struct V_3 * F_14 ( int V_21 )
{
struct V_2 * V_2 ;
V_2 = F_15 ( V_21 ) ;
if ( ! V_2 )
return F_6 ( - V_22 ) ;
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
struct V_23 * F_18 ( struct V_3 * V_4 ,
struct V_24 * V_25 )
{
struct V_23 * V_26 ;
int V_27 ;
if ( F_5 ( ! V_4 || ! V_25 || ! V_4 -> V_7 ) )
return F_6 ( - V_5 ) ;
V_26 = F_7 ( sizeof( struct V_23 ) , V_17 ) ;
if ( V_26 == NULL )
goto V_28;
F_19 ( & V_4 -> V_19 ) ;
V_26 -> V_25 = V_25 ;
V_26 -> V_4 = V_4 ;
if ( V_4 -> V_7 -> V_26 ) {
V_27 = V_4 -> V_7 -> V_26 ( V_4 , V_25 , V_26 ) ;
if ( V_27 )
goto V_29;
}
F_20 ( & V_26 -> V_30 , & V_4 -> V_20 ) ;
F_21 ( & V_4 -> V_19 ) ;
return V_26 ;
V_28:
return F_6 ( - V_18 ) ;
V_29:
F_3 ( V_26 ) ;
F_21 ( & V_4 -> V_19 ) ;
return F_6 ( V_27 ) ;
}
void F_22 ( struct V_3 * V_4 , struct V_23 * V_26 )
{
if ( F_5 ( ! V_4 || ! V_26 || ! V_4 -> V_7 ) )
return;
F_19 ( & V_4 -> V_19 ) ;
F_23 ( & V_26 -> V_30 ) ;
if ( V_4 -> V_7 -> V_31 )
V_4 -> V_7 -> V_31 ( V_4 , V_26 ) ;
F_21 ( & V_4 -> V_19 ) ;
F_3 ( V_26 ) ;
}
struct V_32 * F_24 ( struct V_23 * V_26 ,
enum V_33 V_34 )
{
struct V_32 * V_32 = F_6 ( - V_5 ) ;
F_25 () ;
if ( F_5 ( ! V_26 || ! V_26 -> V_4 || ! V_26 -> V_4 -> V_7 ) )
return F_6 ( - V_5 ) ;
F_19 ( & V_26 -> V_4 -> V_19 ) ;
if ( V_26 -> V_4 -> V_7 -> V_15 )
V_32 = V_26 -> V_4 -> V_7 -> V_15 ( V_26 , V_34 ) ;
F_21 ( & V_26 -> V_4 -> V_19 ) ;
return V_32 ;
}
void F_26 ( struct V_23 * V_26 ,
struct V_32 * V_32 )
{
if ( F_5 ( ! V_26 || ! V_26 -> V_4 || ! V_32
|| ! V_26 -> V_4 -> V_7 ) )
return;
F_19 ( & V_26 -> V_4 -> V_19 ) ;
if ( V_26 -> V_4 -> V_7 -> V_16 )
V_26 -> V_4 -> V_7 -> V_16 ( V_26 , V_32 ) ;
F_21 ( & V_26 -> V_4 -> V_19 ) ;
}
