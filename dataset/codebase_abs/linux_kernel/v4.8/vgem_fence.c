static const char * F_1 ( struct V_1 * V_1 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_1 )
{
return L_2 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return false ;
}
static bool F_4 ( struct V_1 * V_1 )
{
return true ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_6 ( V_2 , F_7 ( * V_1 ) , V_2 ) ;
F_8 ( & V_1 -> V_4 ) ;
F_9 ( & V_1 -> V_2 ) ;
}
static void F_10 ( struct V_1 * V_1 , char * V_5 , int V_6 )
{
snprintf ( V_5 , V_6 , L_3 , V_1 -> V_7 ) ;
}
static void F_11 ( struct V_1 * V_1 , char * V_5 ,
int V_6 )
{
snprintf ( V_5 , V_6 , L_3 , F_12 ( V_1 ) ? V_1 -> V_7 : 0 ) ;
}
static void F_13 ( unsigned long V_8 )
{
struct V_3 * V_1 = (struct V_3 * ) V_8 ;
F_14 ( & V_1 -> V_2 ) ;
}
static struct V_1 * F_15 ( struct V_9 * V_10 ,
unsigned int V_11 )
{
struct V_3 * V_1 ;
V_1 = F_16 ( sizeof( * V_1 ) , V_12 ) ;
if ( ! V_1 )
return NULL ;
F_17 ( & V_1 -> V_13 ) ;
F_18 ( & V_1 -> V_2 , & V_14 , & V_1 -> V_13 ,
F_19 ( 1 ) , 1 ) ;
F_20 ( & V_1 -> V_4 , F_13 , ( unsigned long ) V_1 ) ;
F_21 ( & V_1 -> V_4 , V_15 + V_16 ) ;
return & V_1 -> V_2 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
if ( V_20 -> V_21 )
return 0 ;
V_22 = V_18 -> V_23 -> V_24 ( V_18 , V_20 , 0 ) ;
if ( F_23 ( V_22 ) )
return F_24 ( V_22 ) ;
V_20 -> V_21 = V_22 ;
F_25 ( V_20 ) ;
return 0 ;
}
int F_26 ( struct V_17 * V_18 ,
void * V_8 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_8 ;
struct V_9 * V_10 = V_26 -> V_29 ;
struct V_30 * V_31 ;
struct V_19 * V_20 ;
struct V_1 * V_1 ;
int V_32 ;
if ( V_28 -> V_11 & ~ V_33 )
return - V_34 ;
if ( V_28 -> V_35 )
return - V_34 ;
V_20 = F_27 ( V_26 , V_28 -> V_36 ) ;
if ( ! V_20 )
return - V_37 ;
V_32 = F_22 ( V_18 , V_20 ) ;
if ( V_32 )
goto V_38;
V_1 = F_15 ( V_10 , V_28 -> V_11 ) ;
if ( ! V_1 ) {
V_32 = - V_39 ;
goto V_38;
}
V_31 = V_20 -> V_21 -> V_31 ;
if ( ! F_28 ( V_31 ,
V_28 -> V_11 & V_33 ) ) {
V_32 = - V_40 ;
goto V_41;
}
V_32 = 0 ;
F_29 ( & V_31 -> V_13 . V_2 ) ;
if ( V_28 -> V_11 & V_33 )
F_30 ( V_31 , V_1 ) ;
else if ( ( V_32 = F_31 ( V_31 ) ) == 0 )
F_32 ( V_31 , V_1 ) ;
F_33 ( & V_31 -> V_13 . V_2 ) ;
if ( V_32 == 0 ) {
F_29 ( & V_10 -> V_42 ) ;
V_32 = F_34 ( & V_10 -> V_43 , V_1 , 1 , 0 , V_12 ) ;
F_33 ( & V_10 -> V_42 ) ;
if ( V_32 > 0 ) {
V_28 -> V_44 = V_32 ;
V_32 = 0 ;
}
}
V_41:
if ( V_32 ) {
F_14 ( V_1 ) ;
F_35 ( V_1 ) ;
}
V_38:
F_36 ( V_20 ) ;
return V_32 ;
}
int F_37 ( struct V_17 * V_18 ,
void * V_8 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_26 -> V_29 ;
struct V_45 * V_28 = V_8 ;
struct V_1 * V_1 ;
int V_32 = 0 ;
if ( V_28 -> V_11 )
return - V_34 ;
F_29 ( & V_10 -> V_42 ) ;
V_1 = F_38 ( & V_10 -> V_43 , NULL , V_28 -> V_1 ) ;
F_33 ( & V_10 -> V_42 ) ;
if ( ! V_1 )
return - V_37 ;
if ( F_23 ( V_1 ) )
return F_24 ( V_1 ) ;
if ( F_12 ( V_1 ) )
V_32 = - V_46 ;
F_14 ( V_1 ) ;
F_35 ( V_1 ) ;
return V_32 ;
}
int F_39 ( struct V_9 * V_10 )
{
F_40 ( & V_10 -> V_42 ) ;
F_41 ( & V_10 -> V_43 ) ;
return 0 ;
}
static int F_42 ( int V_47 , void * V_48 , void * V_8 )
{
F_14 ( V_48 ) ;
F_35 ( V_48 ) ;
return 0 ;
}
void F_43 ( struct V_9 * V_10 )
{
F_44 ( & V_10 -> V_43 , F_42 , V_10 ) ;
F_45 ( & V_10 -> V_43 ) ;
}
