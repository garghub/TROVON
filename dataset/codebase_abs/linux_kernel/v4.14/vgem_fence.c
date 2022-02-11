static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
return L_2 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return false ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return true ;
}
static void F_5 ( struct V_1 * V_3 )
{
struct V_4 * V_2 = F_6 ( V_3 , F_7 ( * V_2 ) , V_3 ) ;
F_8 ( & V_2 -> V_5 ) ;
F_9 ( & V_2 -> V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 , char * V_6 , int V_7 )
{
snprintf ( V_6 , V_7 , L_3 , V_2 -> V_8 ) ;
}
static void F_11 ( struct V_1 * V_2 , char * V_6 ,
int V_7 )
{
snprintf ( V_6 , V_7 , L_3 ,
F_12 ( V_2 ) ? V_2 -> V_8 : 0 ) ;
}
static void F_13 ( unsigned long V_9 )
{
struct V_4 * V_2 = (struct V_4 * ) V_9 ;
F_14 ( & V_2 -> V_3 ) ;
}
static struct V_1 * F_15 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_4 * V_2 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return NULL ;
F_17 ( & V_2 -> V_14 ) ;
F_18 ( & V_2 -> V_3 , & V_15 , & V_2 -> V_14 ,
F_19 ( 1 ) , 1 ) ;
F_20 ( & V_2 -> V_5 , F_13 , ( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_5 , V_16 + V_17 ) ;
return & V_2 -> V_3 ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 ;
if ( V_21 -> V_22 )
return 0 ;
V_23 = V_19 -> V_24 -> V_25 ( V_19 , V_21 , 0 ) ;
if ( F_23 ( V_23 ) )
return F_24 ( V_23 ) ;
V_21 -> V_22 = V_23 ;
return 0 ;
}
int F_25 ( struct V_18 * V_19 ,
void * V_9 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_9 ;
struct V_10 * V_11 = V_27 -> V_30 ;
struct V_31 * V_32 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_33 ;
if ( V_29 -> V_12 & ~ V_34 )
return - V_35 ;
if ( V_29 -> V_36 )
return - V_35 ;
V_21 = F_26 ( V_27 , V_29 -> V_37 ) ;
if ( ! V_21 )
return - V_38 ;
V_33 = F_22 ( V_19 , V_21 ) ;
if ( V_33 )
goto V_39;
V_2 = F_15 ( V_11 , V_29 -> V_12 ) ;
if ( ! V_2 ) {
V_33 = - V_40 ;
goto V_39;
}
V_32 = V_21 -> V_22 -> V_32 ;
if ( ! F_27 ( V_32 ,
V_29 -> V_12 & V_34 ) ) {
V_33 = - V_41 ;
goto V_42;
}
V_33 = 0 ;
F_28 ( V_32 , NULL ) ;
if ( V_29 -> V_12 & V_34 )
F_29 ( V_32 , V_2 ) ;
else if ( ( V_33 = F_30 ( V_32 ) ) == 0 )
F_31 ( V_32 , V_2 ) ;
F_32 ( V_32 ) ;
if ( V_33 == 0 ) {
F_33 ( & V_11 -> V_43 ) ;
V_33 = F_34 ( & V_11 -> V_44 , V_2 , 1 , 0 , V_13 ) ;
F_35 ( & V_11 -> V_43 ) ;
if ( V_33 > 0 ) {
V_29 -> V_45 = V_33 ;
V_33 = 0 ;
}
}
V_42:
if ( V_33 ) {
F_14 ( V_2 ) ;
F_36 ( V_2 ) ;
}
V_39:
F_37 ( V_21 ) ;
return V_33 ;
}
int F_38 ( struct V_18 * V_19 ,
void * V_9 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = V_27 -> V_30 ;
struct V_46 * V_29 = V_9 ;
struct V_1 * V_2 ;
int V_33 = 0 ;
if ( V_29 -> V_12 )
return - V_35 ;
F_33 ( & V_11 -> V_43 ) ;
V_2 = F_39 ( & V_11 -> V_44 , NULL , V_29 -> V_2 ) ;
F_35 ( & V_11 -> V_43 ) ;
if ( ! V_2 )
return - V_38 ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
if ( F_12 ( V_2 ) )
V_33 = - V_47 ;
F_14 ( V_2 ) ;
F_36 ( V_2 ) ;
return V_33 ;
}
int F_40 ( struct V_10 * V_11 )
{
F_41 ( & V_11 -> V_43 ) ;
F_42 ( & V_11 -> V_44 ) ;
return 0 ;
}
static int F_43 ( int V_48 , void * V_49 , void * V_9 )
{
F_14 ( V_49 ) ;
F_36 ( V_49 ) ;
return 0 ;
}
void F_44 ( struct V_10 * V_11 )
{
F_45 ( & V_11 -> V_44 , F_43 , V_11 ) ;
F_46 ( & V_11 -> V_44 ) ;
}
