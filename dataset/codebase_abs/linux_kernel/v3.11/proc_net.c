static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static struct V_1 * F_2 ( const struct V_6 * V_6 )
{
return F_3 ( F_1 ( F_4 ( V_6 ) ) ) ;
}
int F_5 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_1 ;
struct V_13 * V_14 ;
F_6 ( V_12 < sizeof( * V_14 ) ) ;
V_1 = F_2 ( V_7 ) ;
if ( V_1 == NULL )
return - V_15 ;
V_14 = F_7 ( V_9 , V_11 , V_12 ) ;
if ( V_14 == NULL ) {
F_8 ( V_1 ) ;
return - V_16 ;
}
#ifdef F_9
V_14 -> V_1 = V_1 ;
#endif
return 0 ;
}
int F_10 ( struct V_6 * V_6 , struct V_8 * V_8 ,
int (* F_11)( struct V_17 * , void * ) )
{
int V_18 ;
struct V_1 * V_1 ;
V_18 = - V_15 ;
V_1 = F_2 ( V_6 ) ;
if ( V_1 == NULL )
goto V_19;
V_18 = F_12 ( V_8 , F_11 , V_1 ) ;
if ( V_18 < 0 )
goto V_20;
return 0 ;
V_20:
F_8 ( V_1 ) ;
V_19:
return V_18 ;
}
int F_13 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_17 * V_21 ;
V_21 = V_9 -> V_22 ;
F_8 ( F_14 ( V_21 ) ) ;
F_15 ( V_7 , V_9 ) ;
return 0 ;
}
int F_16 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_17 * V_21 = V_9 -> V_22 ;
F_8 ( V_21 -> V_23 ) ;
return F_17 ( V_7 , V_9 ) ;
}
static struct V_1 * F_18 ( struct V_6 * V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_1 * V_1 = NULL ;
F_19 () ;
V_26 = F_20 ( F_21 ( V_24 ) , V_29 ) ;
if ( V_26 != NULL ) {
V_28 = F_22 ( V_26 ) ;
if ( V_28 != NULL )
V_1 = F_23 ( V_28 -> V_30 ) ;
}
F_24 () ;
return V_1 ;
}
static struct V_31 * F_25 ( struct V_6 * V_24 ,
struct V_31 * V_31 , unsigned int V_32 )
{
struct V_31 * V_33 ;
struct V_1 * V_1 ;
V_33 = F_26 ( - V_34 ) ;
V_1 = F_18 ( V_24 ) ;
if ( V_1 != NULL ) {
V_33 = F_27 ( V_1 -> V_35 , V_24 , V_31 ) ;
F_8 ( V_1 ) ;
}
return V_33 ;
}
static int F_28 ( struct V_36 * V_37 , struct V_31 * V_31 ,
struct V_38 * V_39 )
{
struct V_6 * V_6 = V_31 -> V_40 ;
struct V_1 * V_1 ;
V_1 = F_18 ( V_6 ) ;
F_29 ( V_6 , V_39 ) ;
if ( V_1 != NULL ) {
V_39 -> V_41 = V_1 -> V_35 -> V_41 ;
F_8 ( V_1 ) ;
}
return 0 ;
}
static int F_30 ( struct V_8 * V_8 , struct V_42 * V_43 )
{
int V_44 ;
struct V_1 * V_1 ;
V_44 = - V_45 ;
V_1 = F_18 ( F_31 ( V_8 ) ) ;
if ( V_1 != NULL ) {
V_44 = F_32 ( V_1 -> V_35 , V_8 , V_43 ) ;
F_8 ( V_1 ) ;
}
return V_44 ;
}
static T_1 int F_33 ( struct V_1 * V_1 )
{
struct V_2 * V_46 , * V_47 ;
int V_18 ;
V_18 = - V_16 ;
V_46 = F_34 ( sizeof( * V_46 ) + 4 , V_48 ) ;
if ( ! V_46 )
goto V_49;
V_46 -> V_5 = V_1 ;
V_46 -> V_41 = 2 ;
V_46 -> V_50 = 3 ;
V_46 -> V_4 = & V_51 ;
memcpy ( V_46 -> V_52 , L_1 , 4 ) ;
V_18 = - V_53 ;
V_47 = F_35 ( V_1 , L_2 , V_46 ) ;
if ( ! V_47 )
goto V_54;
V_1 -> V_35 = V_46 ;
V_1 -> V_55 = V_47 ;
return 0 ;
V_54:
F_36 ( V_46 ) ;
V_49:
return V_18 ;
}
static T_2 void F_37 ( struct V_1 * V_1 )
{
F_38 ( L_2 , V_1 -> V_35 ) ;
F_36 ( V_1 -> V_35 ) ;
}
int T_3 F_39 ( void )
{
F_40 ( L_1 , NULL , L_3 ) ;
return F_41 ( & V_56 ) ;
}
