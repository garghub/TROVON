static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_4 >= 0 && F_3 ( V_5 , & F_4 ( V_1 ) -> V_6 ) ) {
int V_7 ;
bool V_8 = true ;
if ( V_3 -> V_9 == V_10 )
V_8 = false ;
V_7 = F_5 ( V_1 , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return V_4 ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_7 ( & V_1 -> V_11 , 0 ) ;
F_8 ( V_1 ) ;
F_9 ( V_1 ) ;
F_10 ( F_4 ( V_1 ) ) ;
F_11 ( V_1 ) ;
F_12 ( V_1 ) ;
}
static struct V_12 *
F_13 ( struct V_13 * V_14 , int V_6 ,
const char * V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_19 * V_20 ;
struct V_12 * V_21 = F_14 ( - V_22 ) ;
V_18 -> V_23 = V_24 ;
V_20 = F_15 ( V_18 , & V_25 ) ;
if ( F_16 ( V_20 ) ) {
V_21 = F_17 ( V_20 ) ;
goto V_26;
}
V_21 = F_18 ( V_20 , V_6 , V_15 , V_18 , & V_25 ) ;
V_26:
return V_21 ;
}
static struct V_27 * F_19 ( struct V_13 * V_14 ,
int V_6 , void * V_28 , const char * V_29 )
{
struct V_27 * V_30 ;
char * V_31 ;
T_1 V_32 ;
V_32 = strlen ( V_29 ) + 5 ;
V_31 = F_20 ( V_32 , V_33 ) ;
if ( V_31 == NULL )
return F_14 ( - V_22 ) ;
if ( strchr ( V_29 , ':' ) )
snprintf ( V_31 , V_32 , L_1 , V_29 ) ;
else
snprintf ( V_31 , V_32 , L_2 , V_29 ) ;
V_30 = F_21 ( V_14 , V_6 , V_31 , V_28 ) ;
F_22 ( V_31 ) ;
return V_30 ;
}
static struct V_34 * F_23 ( void )
{
struct V_34 * V_35 ;
F_24 (p, &nfs_referral_count_list, list) {
if ( V_35 -> V_36 == V_37 )
return V_35 ;
}
return NULL ;
}
static int F_25 ( void )
{
struct V_34 * V_35 , * V_38 ;
int V_4 = - V_22 ;
V_38 = F_20 ( sizeof( * V_38 ) , V_33 ) ;
if ( ! V_38 )
goto V_26;
V_38 -> V_36 = V_37 ;
V_38 -> V_39 = 1 ;
V_4 = 0 ;
F_26 ( & V_40 ) ;
V_35 = F_23 () ;
if ( V_35 != NULL ) {
if ( V_35 -> V_39 >= V_41 )
V_4 = - V_42 ;
else
V_35 -> V_39 ++ ;
} else {
F_27 ( & V_38 -> V_43 , & V_44 ) ;
V_38 = NULL ;
}
F_28 ( & V_40 ) ;
F_22 ( V_38 ) ;
V_26:
return V_4 ;
}
static void F_29 ( void )
{
struct V_34 * V_35 ;
F_26 ( & V_40 ) ;
V_35 = F_23 () ;
V_35 -> V_39 -- ;
if ( V_35 -> V_39 == 0 )
F_30 ( & V_35 -> V_43 ) ;
else
V_35 = NULL ;
F_28 ( & V_40 ) ;
F_22 ( V_35 ) ;
}
static struct V_12 * F_31 ( struct V_27 * V_30 ,
const char * V_45 )
{
struct V_12 * V_12 ;
int V_46 ;
if ( F_16 ( V_30 ) )
return F_17 ( V_30 ) ;
V_46 = F_25 () ;
if ( V_46 ) {
F_32 ( V_30 ) ;
return F_14 ( V_46 ) ;
}
V_12 = F_33 ( V_30 , V_45 ) ;
F_29 () ;
return V_12 ;
}
struct V_12 * F_34 ( int V_6 , const char * V_15 ,
struct V_17 * V_18 ,
struct V_47 * V_48 )
{
char * V_45 ;
struct V_27 * V_30 ;
struct V_12 * V_49 ;
struct V_50 * V_28 = V_18 -> V_51 ;
F_35 ( V_52 , L_3 ) ;
if ( V_28 -> V_53 [ 0 ] == V_54 )
V_28 -> V_53 [ 0 ] = V_55 ;
V_45 = V_28 -> V_19 . V_45 ;
V_28 -> V_19 . V_45 = L_4 ;
V_30 = F_19 ( & V_56 , V_6 , V_18 ,
V_28 -> V_19 . V_29 ) ;
V_28 -> V_19 . V_45 = V_45 ;
V_49 = F_31 ( V_30 , V_45 ) ;
F_35 ( V_52 , L_5 ,
F_16 ( V_49 ) ? F_36 ( V_49 ) : 0 ,
F_16 ( V_49 ) ? L_6 : L_7 ) ;
return V_49 ;
}
static struct V_12 *
F_37 ( struct V_13 * V_14 , int V_6 ,
const char * V_15 , void * V_57 )
{
struct V_17 V_18 = {
. V_58 = V_59 ,
. V_23 = V_60 ,
. V_61 = V_57 ,
} ;
struct V_19 * V_20 ;
struct V_12 * V_21 = F_14 ( - V_22 ) ;
F_38 ( L_8 ) ;
V_18 . V_62 = F_39 () ;
if ( V_18 . V_61 == NULL || V_18 . V_62 == NULL )
goto V_26;
V_20 = F_40 ( V_18 . V_61 , V_18 . V_62 ) ;
if ( F_16 ( V_20 ) ) {
V_21 = F_17 ( V_20 ) ;
goto V_26;
}
V_21 = F_18 ( V_20 , V_6 , V_15 , & V_18 , & V_25 ) ;
V_26:
F_41 ( V_18 . V_62 ) ;
return V_21 ;
}
static struct V_12 * F_42 ( struct V_13 * V_14 ,
int V_6 , const char * V_15 , void * V_57 )
{
struct V_63 * V_28 = V_57 ;
char * V_45 ;
struct V_27 * V_30 ;
struct V_12 * V_49 ;
F_38 ( L_9 ) ;
V_45 = V_28 -> V_64 ;
V_28 -> V_64 = L_4 ;
V_30 = F_19 ( & V_65 ,
V_6 , V_28 , V_28 -> V_29 ) ;
V_28 -> V_64 = V_45 ;
V_49 = F_31 ( V_30 , V_45 ) ;
F_38 ( L_10 ,
F_16 ( V_49 ) ? F_36 ( V_49 ) : 0 ,
F_16 ( V_49 ) ? L_6 : L_7 ) ;
return V_49 ;
}
static int T_2 F_43 ( void )
{
int V_46 ;
V_46 = F_44 () ;
if ( V_46 )
goto V_26;
V_46 = F_45 () ;
if ( V_46 )
goto V_66;
F_46 ( & V_25 ) ;
return 0 ;
V_66:
F_47 () ;
V_26:
return V_46 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_25 ) ;
F_50 () ;
F_47 () ;
}
