static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
F_3 ( V_4 -> V_7 ) ;
V_4 -> V_8 -> V_9 ( V_4 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
if ( V_11 -> V_12 + ( ( V_11 -> V_13 - V_11 -> V_14 ) >> V_15 ) >
V_4 -> V_16 >> V_15 )
return - V_5 ;
return V_4 -> V_8 -> V_17 ( V_4 , V_11 ) ;
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_18 == & V_19 ;
}
struct V_3 * F_6 ( void * V_20 , const struct V_21 * V_8 ,
T_1 V_16 , int V_22 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
if ( F_7 ( ! V_20 || ! V_8
|| ! V_8 -> V_23
|| ! V_8 -> V_24
|| ! V_8 -> V_9
|| ! V_8 -> V_25
|| ! V_8 -> V_26
|| ! V_8 -> V_17 ) ) {
return F_8 ( - V_5 ) ;
}
V_4 = F_9 ( sizeof( struct V_3 ) , V_27 ) ;
if ( V_4 == NULL )
return F_8 ( - V_28 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_16 = V_16 ;
V_2 = F_10 ( L_1 , & V_19 , V_4 , V_22 ) ;
V_4 -> V_2 = V_2 ;
F_11 ( & V_4 -> V_29 ) ;
F_12 ( & V_4 -> V_30 ) ;
return V_4 ;
}
int F_13 ( struct V_3 * V_4 , int V_22 )
{
int V_31 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_31 = F_14 ( V_22 ) ;
if ( V_31 < 0 )
return V_31 ;
F_15 ( V_31 , V_4 -> V_2 ) ;
return V_31 ;
}
struct V_3 * F_16 ( int V_31 )
{
struct V_2 * V_2 ;
V_2 = F_17 ( V_31 ) ;
if ( ! V_2 )
return F_8 ( - V_32 ) ;
if ( ! F_2 ( V_2 ) ) {
F_18 ( V_2 ) ;
return F_8 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_19 ( struct V_3 * V_4 )
{
if ( F_7 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_18 ( V_4 -> V_2 ) ;
}
struct V_33 * F_20 ( struct V_3 * V_4 ,
struct V_34 * V_35 )
{
struct V_33 * V_36 ;
int V_37 ;
if ( F_7 ( ! V_4 || ! V_35 ) )
return F_8 ( - V_5 ) ;
V_36 = F_9 ( sizeof( struct V_33 ) , V_27 ) ;
if ( V_36 == NULL )
return F_8 ( - V_28 ) ;
V_36 -> V_35 = V_35 ;
V_36 -> V_4 = V_4 ;
F_21 ( & V_4 -> V_29 ) ;
if ( V_4 -> V_8 -> V_36 ) {
V_37 = V_4 -> V_8 -> V_36 ( V_4 , V_35 , V_36 ) ;
if ( V_37 )
goto V_38;
}
F_22 ( & V_36 -> V_39 , & V_4 -> V_30 ) ;
F_23 ( & V_4 -> V_29 ) ;
return V_36 ;
V_38:
F_4 ( V_36 ) ;
F_23 ( & V_4 -> V_29 ) ;
return F_8 ( V_37 ) ;
}
void F_24 ( struct V_3 * V_4 , struct V_33 * V_36 )
{
if ( F_7 ( ! V_4 || ! V_36 ) )
return;
F_21 ( & V_4 -> V_29 ) ;
F_25 ( & V_36 -> V_39 ) ;
if ( V_4 -> V_8 -> V_40 )
V_4 -> V_8 -> V_40 ( V_4 , V_36 ) ;
F_23 ( & V_4 -> V_29 ) ;
F_4 ( V_36 ) ;
}
struct V_41 * F_26 ( struct V_33 * V_36 ,
enum V_42 V_43 )
{
struct V_41 * V_41 = F_8 ( - V_5 ) ;
F_27 () ;
if ( F_7 ( ! V_36 || ! V_36 -> V_4 ) )
return F_8 ( - V_5 ) ;
V_41 = V_36 -> V_4 -> V_8 -> V_23 ( V_36 , V_43 ) ;
return V_41 ;
}
void F_28 ( struct V_33 * V_36 ,
struct V_41 * V_41 ,
enum V_42 V_43 )
{
F_27 () ;
if ( F_7 ( ! V_36 || ! V_36 -> V_4 || ! V_41 ) )
return;
V_36 -> V_4 -> V_8 -> V_24 ( V_36 , V_41 ,
V_43 ) ;
}
int F_29 ( struct V_3 * V_4 , T_1 V_44 , T_1 V_45 ,
enum V_42 V_43 )
{
int V_37 = 0 ;
if ( F_7 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_8 -> V_46 )
V_37 = V_4 -> V_8 -> V_46 ( V_4 , V_44 , V_45 , V_43 ) ;
return V_37 ;
}
void F_30 ( struct V_3 * V_4 , T_1 V_44 , T_1 V_45 ,
enum V_42 V_43 )
{
F_7 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_47 )
V_4 -> V_8 -> V_47 ( V_4 , V_44 , V_45 , V_43 ) ;
}
void * F_31 ( struct V_3 * V_4 , unsigned long V_48 )
{
F_7 ( ! V_4 ) ;
return V_4 -> V_8 -> V_25 ( V_4 , V_48 ) ;
}
void F_32 ( struct V_3 * V_4 , unsigned long V_48 ,
void * V_49 )
{
F_7 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_50 )
V_4 -> V_8 -> V_50 ( V_4 , V_48 , V_49 ) ;
}
void * F_33 ( struct V_3 * V_4 , unsigned long V_48 )
{
F_7 ( ! V_4 ) ;
return V_4 -> V_8 -> V_26 ( V_4 , V_48 ) ;
}
void F_34 ( struct V_3 * V_4 , unsigned long V_48 ,
void * V_49 )
{
F_7 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_51 )
V_4 -> V_8 -> V_51 ( V_4 , V_48 , V_49 ) ;
}
int F_35 ( struct V_3 * V_4 , struct V_10 * V_11 ,
unsigned long V_52 )
{
struct V_2 * V_53 ;
int V_37 ;
if ( F_7 ( ! V_4 || ! V_11 ) )
return - V_5 ;
if ( V_52 + ( ( V_11 -> V_13 - V_11 -> V_14 ) >> V_15 ) < V_52 )
return - V_54 ;
if ( V_52 + ( ( V_11 -> V_13 - V_11 -> V_14 ) >> V_15 ) >
V_4 -> V_16 >> V_15 )
return - V_5 ;
F_36 ( V_4 -> V_2 ) ;
V_53 = V_11 -> V_55 ;
V_11 -> V_55 = V_4 -> V_2 ;
V_11 -> V_12 = V_52 ;
V_37 = V_4 -> V_8 -> V_17 ( V_4 , V_11 ) ;
if ( V_37 ) {
V_11 -> V_55 = V_53 ;
F_18 ( V_4 -> V_2 ) ;
} else {
if ( V_53 )
F_18 ( V_53 ) ;
}
return V_37 ;
}
void * F_37 ( struct V_3 * V_4 )
{
void * V_56 ;
if ( F_7 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_8 -> V_57 )
return NULL ;
F_21 ( & V_4 -> V_29 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_58 ) ;
V_56 = V_4 -> V_58 ;
goto V_59;
}
F_3 ( V_4 -> V_58 ) ;
V_56 = V_4 -> V_8 -> V_57 ( V_4 ) ;
if ( F_38 ( V_56 ) )
goto V_59;
V_4 -> V_58 = V_56 ;
V_4 -> V_7 = 1 ;
V_59:
F_23 ( & V_4 -> V_29 ) ;
return V_56 ;
}
void F_39 ( struct V_3 * V_4 , void * V_49 )
{
if ( F_7 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_58 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_58 != V_49 ) ;
F_21 ( & V_4 -> V_29 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_8 -> V_60 )
V_4 -> V_8 -> V_60 ( V_4 , V_49 ) ;
V_4 -> V_58 = NULL ;
}
F_23 ( & V_4 -> V_29 ) ;
}
