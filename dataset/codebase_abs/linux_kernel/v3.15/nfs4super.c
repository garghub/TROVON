static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_4 == 0 )
V_4 = F_3 ( V_1 ,
V_3 -> V_5 == V_6 ) ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_7 ) ;
F_6 ( V_1 ) ;
F_7 ( V_1 ) ;
F_8 ( F_9 ( V_1 ) ) ;
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
}
static struct V_8 *
F_12 ( struct V_9 * V_10 , int V_11 ,
const char * V_12 , void * V_13 )
{
struct V_14 * V_15 = V_13 ;
struct V_16 * V_17 ;
struct V_8 * V_18 = F_13 ( - V_19 ) ;
V_15 -> V_20 = V_21 ;
V_17 = F_14 ( V_15 , & V_22 ) ;
if ( F_15 ( V_17 ) ) {
V_18 = F_16 ( V_17 ) ;
goto V_23;
}
V_18 = F_17 ( V_17 , V_11 , V_12 , V_15 , & V_22 ) ;
V_23:
return V_18 ;
}
static struct V_24 * F_18 ( struct V_9 * V_10 ,
int V_11 , void * V_25 , const char * V_26 )
{
struct V_24 * V_27 ;
char * V_28 ;
T_1 V_29 ;
V_29 = strlen ( V_26 ) + 5 ;
V_28 = F_19 ( V_29 , V_30 ) ;
if ( V_28 == NULL )
return F_13 ( - V_19 ) ;
if ( strchr ( V_26 , ':' ) )
snprintf ( V_28 , V_29 , L_1 , V_26 ) ;
else
snprintf ( V_28 , V_29 , L_2 , V_26 ) ;
V_27 = F_20 ( V_10 , V_11 , V_28 , V_25 ) ;
F_21 ( V_28 ) ;
return V_27 ;
}
static struct V_31 * F_22 ( void )
{
struct V_31 * V_32 ;
F_23 (p, &nfs_referral_count_list, list) {
if ( V_32 -> V_33 == V_34 )
return V_32 ;
}
return NULL ;
}
static int F_24 ( void )
{
struct V_31 * V_32 , * V_35 ;
int V_4 = - V_19 ;
V_35 = F_19 ( sizeof( * V_35 ) , V_30 ) ;
if ( ! V_35 )
goto V_23;
V_35 -> V_33 = V_34 ;
V_35 -> V_36 = 1 ;
V_4 = 0 ;
F_25 ( & V_37 ) ;
V_32 = F_22 () ;
if ( V_32 != NULL ) {
if ( V_32 -> V_36 >= V_38 )
V_4 = - V_39 ;
else
V_32 -> V_36 ++ ;
} else {
F_26 ( & V_35 -> V_40 , & V_41 ) ;
V_35 = NULL ;
}
F_27 ( & V_37 ) ;
F_21 ( V_35 ) ;
V_23:
return V_4 ;
}
static void F_28 ( void )
{
struct V_31 * V_32 ;
F_25 ( & V_37 ) ;
V_32 = F_22 () ;
V_32 -> V_36 -- ;
if ( V_32 -> V_36 == 0 )
F_29 ( & V_32 -> V_40 ) ;
else
V_32 = NULL ;
F_27 ( & V_37 ) ;
F_21 ( V_32 ) ;
}
static struct V_8 * F_30 ( struct V_24 * V_27 ,
const char * V_42 )
{
struct V_8 * V_8 ;
int V_43 ;
if ( F_15 ( V_27 ) )
return F_16 ( V_27 ) ;
V_43 = F_24 () ;
if ( V_43 ) {
F_31 ( V_27 ) ;
return F_13 ( V_43 ) ;
}
V_8 = F_32 ( V_27 , V_42 ) ;
F_28 () ;
return V_8 ;
}
struct V_8 * F_33 ( int V_11 , const char * V_12 ,
struct V_14 * V_15 ,
struct V_44 * V_45 )
{
char * V_42 ;
struct V_24 * V_27 ;
struct V_8 * V_46 ;
struct V_47 * V_25 = V_15 -> V_48 ;
F_34 ( V_49 , L_3 ) ;
V_42 = V_25 -> V_16 . V_42 ;
V_25 -> V_16 . V_42 = L_4 ;
V_27 = F_18 ( & V_50 , V_11 , V_15 ,
V_25 -> V_16 . V_26 ) ;
V_25 -> V_16 . V_42 = V_42 ;
V_46 = F_30 ( V_27 , V_42 ) ;
F_34 ( V_49 , L_5 ,
F_35 ( V_46 ) ,
F_15 ( V_46 ) ? L_6 : L_7 ) ;
return V_46 ;
}
static struct V_8 *
F_36 ( struct V_9 * V_10 , int V_11 ,
const char * V_12 , void * V_51 )
{
struct V_14 V_15 = {
. V_52 = V_53 ,
. V_20 = V_54 ,
. V_55 = V_51 ,
} ;
struct V_16 * V_17 ;
struct V_8 * V_18 = F_13 ( - V_19 ) ;
F_37 ( L_8 ) ;
V_15 . V_56 = F_38 () ;
if ( V_15 . V_55 == NULL || V_15 . V_56 == NULL )
goto V_23;
V_17 = F_39 ( V_15 . V_55 , V_15 . V_56 ) ;
if ( F_15 ( V_17 ) ) {
V_18 = F_16 ( V_17 ) ;
goto V_23;
}
V_18 = F_17 ( V_17 , V_11 , V_12 , & V_15 , & V_22 ) ;
V_23:
F_40 ( V_15 . V_56 ) ;
return V_18 ;
}
static struct V_8 * F_41 ( struct V_9 * V_10 ,
int V_11 , const char * V_12 , void * V_51 )
{
struct V_57 * V_25 = V_51 ;
char * V_42 ;
struct V_24 * V_27 ;
struct V_8 * V_46 ;
F_37 ( L_9 ) ;
V_42 = V_25 -> V_58 ;
V_25 -> V_58 = L_4 ;
V_27 = F_18 ( & V_59 ,
V_11 , V_25 , V_25 -> V_26 ) ;
V_25 -> V_58 = V_42 ;
V_46 = F_30 ( V_27 , V_42 ) ;
F_37 ( L_10 ,
F_35 ( V_46 ) ,
F_15 ( V_46 ) ? L_6 : L_7 ) ;
return V_46 ;
}
static int T_2 F_42 ( void )
{
int V_43 ;
V_43 = F_43 () ;
if ( V_43 )
goto V_23;
V_43 = F_44 () ;
if ( V_43 )
goto V_60;
V_43 = F_45 () ;
if ( V_43 )
goto V_61;
F_46 ( & V_22 ) ;
return 0 ;
V_61:
F_47 () ;
V_60:
F_48 () ;
V_23:
return V_43 ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_22 ) ;
F_51 () ;
F_47 () ;
F_48 () ;
}
