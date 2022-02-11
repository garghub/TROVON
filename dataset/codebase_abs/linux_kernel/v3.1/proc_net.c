static struct V_1 * F_1 ( const struct V_2 * V_2 )
{
return F_2 ( F_3 ( F_4 ( V_2 ) ) ) ;
}
int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 , int V_8 )
{
struct V_1 * V_1 ;
struct V_9 * V_10 ;
F_6 ( V_8 < sizeof( * V_10 ) ) ;
V_1 = F_1 ( V_3 ) ;
if ( V_1 == NULL )
return - V_11 ;
V_10 = F_7 ( V_5 , V_7 , V_8 ) ;
if ( V_10 == NULL ) {
F_8 ( V_1 ) ;
return - V_12 ;
}
#ifdef F_9
V_10 -> V_1 = V_1 ;
#endif
return 0 ;
}
int F_10 ( struct V_2 * V_2 , struct V_4 * V_4 ,
int (* F_11)( struct V_13 * , void * ) )
{
int V_14 ;
struct V_1 * V_1 ;
V_14 = - V_11 ;
V_1 = F_1 ( V_2 ) ;
if ( V_1 == NULL )
goto V_15;
V_14 = F_12 ( V_4 , F_11 , V_1 ) ;
if ( V_14 < 0 )
goto V_16;
return 0 ;
V_16:
F_8 ( V_1 ) ;
V_15:
return V_14 ;
}
int F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_13 * V_17 ;
V_17 = V_5 -> V_18 ;
F_8 ( F_14 ( V_17 ) ) ;
F_15 ( V_3 , V_5 ) ;
return 0 ;
}
int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_13 * V_17 = V_5 -> V_18 ;
F_8 ( V_17 -> V_19 ) ;
return F_17 ( V_3 , V_5 ) ;
}
static struct V_1 * F_18 ( struct V_2 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_1 * V_1 = NULL ;
F_19 () ;
V_22 = F_20 ( F_21 ( V_20 ) , V_25 ) ;
if ( V_22 != NULL ) {
V_24 = F_22 ( V_22 ) ;
if ( V_24 != NULL )
V_1 = F_23 ( V_24 -> V_26 ) ;
}
F_24 () ;
return V_1 ;
}
static struct V_27 * F_25 ( struct V_2 * V_20 ,
struct V_27 * V_27 , struct V_28 * V_29 )
{
struct V_27 * V_30 ;
struct V_1 * V_1 ;
V_30 = F_26 ( - V_31 ) ;
V_1 = F_18 ( V_20 ) ;
if ( V_1 != NULL ) {
V_30 = F_27 ( V_1 -> V_32 , V_20 , V_27 ) ;
F_8 ( V_1 ) ;
}
return V_30 ;
}
static int F_28 ( struct V_33 * V_34 , struct V_27 * V_27 ,
struct V_35 * V_36 )
{
struct V_2 * V_2 = V_27 -> V_37 ;
struct V_1 * V_1 ;
V_1 = F_18 ( V_2 ) ;
F_29 ( V_2 , V_36 ) ;
if ( V_1 != NULL ) {
V_36 -> V_38 = V_1 -> V_32 -> V_38 ;
F_8 ( V_1 ) ;
}
return 0 ;
}
static int F_30 ( struct V_4 * V_39 , void * V_40 ,
T_1 V_41 )
{
int V_42 ;
struct V_1 * V_1 ;
V_42 = - V_43 ;
V_1 = F_18 ( V_39 -> V_44 . V_27 -> V_37 ) ;
if ( V_1 != NULL ) {
V_42 = F_31 ( V_1 -> V_32 , V_39 , V_40 , V_41 ) ;
F_8 ( V_1 ) ;
}
return V_42 ;
}
struct V_45 * F_32 ( struct V_1 * V_1 ,
const char * V_46 , T_2 V_47 , const struct V_48 * V_49 )
{
return F_33 ( V_46 , V_47 , V_1 -> V_32 , V_49 ) ;
}
void F_34 ( struct V_1 * V_1 , const char * V_46 )
{
F_35 ( V_46 , V_1 -> V_32 ) ;
}
static T_3 int F_36 ( struct V_1 * V_1 )
{
struct V_45 * V_50 , * V_51 ;
int V_14 ;
V_14 = - V_12 ;
V_50 = F_37 ( sizeof( * V_50 ) + 4 , V_52 ) ;
if ( ! V_50 )
goto V_53;
V_50 -> V_54 = V_1 ;
V_50 -> V_38 = 2 ;
V_50 -> V_55 = 3 ;
V_50 -> V_56 = & V_57 ;
memcpy ( V_50 -> V_46 , L_1 , 4 ) ;
V_14 = - V_58 ;
V_51 = F_38 ( V_1 , L_2 , V_50 ) ;
if ( ! V_51 )
goto V_59;
V_1 -> V_32 = V_50 ;
V_1 -> V_60 = V_51 ;
return 0 ;
V_59:
F_39 ( V_50 ) ;
V_53:
return V_14 ;
}
static T_4 void F_40 ( struct V_1 * V_1 )
{
F_35 ( L_2 , V_1 -> V_32 ) ;
F_39 ( V_1 -> V_32 ) ;
}
int T_5 F_41 ( void )
{
F_42 ( L_1 , NULL , L_3 ) ;
return F_43 ( & V_61 ) ;
}
