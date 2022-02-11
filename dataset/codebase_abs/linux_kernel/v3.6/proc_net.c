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
struct V_27 * V_27 , unsigned int V_28 )
{
struct V_27 * V_29 ;
struct V_1 * V_1 ;
V_29 = F_26 ( - V_30 ) ;
V_1 = F_18 ( V_20 ) ;
if ( V_1 != NULL ) {
V_29 = F_27 ( V_1 -> V_31 , V_20 , V_27 ) ;
F_8 ( V_1 ) ;
}
return V_29 ;
}
static int F_28 ( struct V_32 * V_33 , struct V_27 * V_27 ,
struct V_34 * V_35 )
{
struct V_2 * V_2 = V_27 -> V_36 ;
struct V_1 * V_1 ;
V_1 = F_18 ( V_2 ) ;
F_29 ( V_2 , V_35 ) ;
if ( V_1 != NULL ) {
V_35 -> V_37 = V_1 -> V_31 -> V_37 ;
F_8 ( V_1 ) ;
}
return 0 ;
}
static int F_30 ( struct V_4 * V_38 , void * V_39 ,
T_1 V_40 )
{
int V_41 ;
struct V_1 * V_1 ;
V_41 = - V_42 ;
V_1 = F_18 ( V_38 -> V_43 . V_27 -> V_36 ) ;
if ( V_1 != NULL ) {
V_41 = F_31 ( V_1 -> V_31 , V_38 , V_39 , V_40 ) ;
F_8 ( V_1 ) ;
}
return V_41 ;
}
struct V_44 * F_32 ( struct V_1 * V_1 ,
const char * V_45 , T_2 V_46 , const struct V_47 * V_48 )
{
return F_33 ( V_45 , V_46 , V_1 -> V_31 , V_48 ) ;
}
void F_34 ( struct V_1 * V_1 , const char * V_45 )
{
F_35 ( V_45 , V_1 -> V_31 ) ;
}
static T_3 int F_36 ( struct V_1 * V_1 )
{
struct V_44 * V_49 , * V_50 ;
int V_14 ;
V_14 = - V_12 ;
V_49 = F_37 ( sizeof( * V_49 ) + 4 , V_51 ) ;
if ( ! V_49 )
goto V_52;
V_49 -> V_53 = V_1 ;
V_49 -> V_37 = 2 ;
V_49 -> V_54 = 3 ;
V_49 -> V_55 = & V_56 ;
memcpy ( V_49 -> V_45 , L_1 , 4 ) ;
V_14 = - V_57 ;
V_50 = F_38 ( V_1 , L_2 , V_49 ) ;
if ( ! V_50 )
goto V_58;
V_1 -> V_31 = V_49 ;
V_1 -> V_59 = V_50 ;
return 0 ;
V_58:
F_39 ( V_49 ) ;
V_52:
return V_14 ;
}
static T_4 void F_40 ( struct V_1 * V_1 )
{
F_35 ( L_2 , V_1 -> V_31 ) ;
F_39 ( V_1 -> V_31 ) ;
}
int T_5 F_41 ( void )
{
F_42 ( L_1 , NULL , L_3 ) ;
return F_43 ( & V_60 ) ;
}
