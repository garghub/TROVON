static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned V_5 ;
if ( V_4 -> V_6 )
return 0 ;
V_5 = F_2 ( F_3 ( & V_4 -> V_7 ) ) ;
V_4 -> V_6 = F_4 ( V_2 , V_5 , V_8 ) ;
if ( ! V_4 -> V_6 )
return - V_9 ;
memset ( V_4 -> V_6 , 0 , V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned V_5 ;
if ( ! V_4 -> V_6 )
return;
V_5 = F_2 ( F_3 ( & V_4 -> V_7 ) ) ;
F_6 ( V_2 , V_4 -> V_6 , V_5 ) ;
V_4 -> V_6 = NULL ;
}
static int F_7 ( struct V_10 * V_1 , struct V_11 * V_12 ,
T_1 V_13 )
{
int V_14 = V_15 * V_16 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 = V_18 -> V_19 ;
long V_20 = 0 ;
int V_21 ;
if ( V_14 > V_2 -> V_22 )
V_14 = V_2 -> V_22 ;
F_9 ( V_2 ) ;
if ( ! V_4 -> V_23 ) {
if ( ( V_12 -> V_24 & V_25 ) )
F_5 ( V_2 , V_4 ) ;
V_21 = F_10 ( F_11 ( & V_4 -> V_7 ) ,
& V_4 -> V_26 ) ;
if ( V_21 )
goto V_27;
}
V_4 -> V_23 = 0 ;
while ( F_12 ( V_12 ) ) {
int V_28 = F_12 ( V_12 ) ;
if ( V_28 > V_14 )
V_28 = V_14 ;
V_28 = F_13 ( & V_4 -> V_29 , & V_12 -> V_30 , V_28 ) ;
if ( V_28 < 0 ) {
V_21 = V_20 ? 0 : V_28 ;
goto V_27;
}
F_14 ( & V_4 -> V_7 , V_4 -> V_29 . V_31 , NULL , V_28 ) ;
V_21 = F_10 ( F_15 ( & V_4 -> V_7 ) ,
& V_4 -> V_26 ) ;
F_16 ( & V_4 -> V_29 ) ;
if ( V_21 )
goto V_27;
V_20 += V_28 ;
F_17 ( & V_12 -> V_30 , V_28 ) ;
}
V_21 = 0 ;
V_4 -> V_23 = V_12 -> V_24 & V_25 ;
if ( ! V_4 -> V_23 ) {
V_21 = F_1 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_27;
F_14 ( & V_4 -> V_7 , NULL , V_4 -> V_6 , 0 ) ;
V_21 = F_10 ( F_18 ( & V_4 -> V_7 ) ,
& V_4 -> V_26 ) ;
}
V_27:
F_19 ( V_2 ) ;
return V_21 ? : V_20 ;
}
static T_2 F_20 ( struct V_10 * V_1 , struct V_32 * V_32 ,
int V_33 , T_1 V_34 , int V_35 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 = V_18 -> V_19 ;
int V_21 ;
if ( V_35 & V_36 )
V_35 |= V_25 ;
F_9 ( V_2 ) ;
F_21 ( V_4 -> V_29 . V_31 , 1 ) ;
F_22 ( V_4 -> V_29 . V_31 , V_32 , V_34 , V_33 ) ;
if ( ! ( V_35 & V_25 ) ) {
V_21 = F_1 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_27;
} else if ( ! V_4 -> V_23 )
F_5 ( V_2 , V_4 ) ;
F_14 ( & V_4 -> V_7 , V_4 -> V_29 . V_31 , V_4 -> V_6 , V_34 ) ;
if ( ! ( V_35 & V_25 ) ) {
if ( V_4 -> V_23 )
V_21 = F_23 ( & V_4 -> V_7 ) ;
else
V_21 = F_24 ( & V_4 -> V_7 ) ;
} else {
if ( ! V_4 -> V_23 ) {
V_21 = F_11 ( & V_4 -> V_7 ) ;
V_21 = F_10 ( V_21 , & V_4 -> V_26 ) ;
if ( V_21 )
goto V_27;
}
V_21 = F_15 ( & V_4 -> V_7 ) ;
}
V_21 = F_10 ( V_21 , & V_4 -> V_26 ) ;
if ( V_21 )
goto V_27;
V_4 -> V_23 = V_35 & V_25 ;
V_27:
F_19 ( V_2 ) ;
return V_21 ? : V_34 ;
}
static int F_25 ( struct V_10 * V_1 , struct V_11 * V_12 , T_1 V_28 ,
int V_35 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 = V_18 -> V_19 ;
unsigned V_5 = F_2 ( F_3 ( & V_4 -> V_7 ) ) ;
bool V_6 ;
int V_21 ;
if ( V_28 > V_5 )
V_28 = V_5 ;
else if ( V_28 < V_5 )
V_12 -> V_24 |= V_37 ;
F_9 ( V_2 ) ;
V_6 = V_4 -> V_6 ;
V_21 = F_1 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_27;
F_14 ( & V_4 -> V_7 , NULL , V_4 -> V_6 , 0 ) ;
if ( ! V_6 && ! V_4 -> V_23 ) {
V_21 = F_10 (
F_11 ( & V_4 -> V_7 ) ,
& V_4 -> V_26 ) ;
if ( V_21 )
goto V_27;
}
if ( ! V_6 || V_4 -> V_23 ) {
V_4 -> V_23 = 0 ;
V_21 = F_10 ( F_18 ( & V_4 -> V_7 ) ,
& V_4 -> V_26 ) ;
if ( V_21 )
goto V_27;
}
V_21 = F_26 ( V_12 , V_4 -> V_6 , V_28 ) ;
V_27:
F_5 ( V_2 , V_4 ) ;
F_19 ( V_2 ) ;
return V_21 ? : V_28 ;
}
static int F_27 ( struct V_10 * V_1 , struct V_10 * V_38 , int V_35 ,
bool V_39 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 = V_18 -> V_19 ;
struct V_40 * V_7 = & V_4 -> V_7 ;
char V_41 [ F_28 ( F_3 ( V_7 ) ) ? : 1 ] ;
struct V_1 * V_42 ;
struct V_17 * V_43 ;
struct V_3 * V_44 ;
bool V_23 ;
int V_21 ;
F_9 ( V_2 ) ;
V_23 = V_4 -> V_23 ;
V_21 = V_23 ? F_29 ( V_7 , V_41 ) : 0 ;
F_19 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_30 ( V_18 -> V_45 , V_38 , V_39 ) ;
if ( V_21 )
return V_21 ;
V_42 = V_38 -> V_2 ;
V_43 = F_8 ( V_42 ) ;
V_44 = V_43 -> V_19 ;
V_44 -> V_23 = V_23 ;
if ( ! V_23 )
return V_21 ;
V_21 = F_31 ( & V_44 -> V_7 , V_41 ) ;
if ( V_21 ) {
F_32 ( V_42 ) ;
F_33 ( V_42 ) ;
}
return V_21 ;
}
static int F_34 ( struct V_10 * V_1 )
{
int V_21 = 0 ;
struct V_1 * V_46 ;
struct V_17 * V_47 ;
struct V_48 * V_49 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( V_18 -> V_50 )
goto V_51;
V_46 = V_18 -> V_45 ;
V_47 = F_8 ( V_18 -> V_45 ) ;
V_49 = V_47 -> V_19 ;
V_21 = - V_52 ;
F_35 ( V_46 , V_53 ) ;
if ( ! V_49 -> V_54 )
goto V_27;
if ( ! V_47 -> V_50 ++ )
F_36 ( V_46 ) ;
V_18 -> V_50 = 1 ;
F_33 ( V_46 ) ;
V_21 = 0 ;
V_27:
F_19 ( V_46 ) ;
V_51:
F_19 ( V_2 ) ;
return V_21 ;
}
static int F_37 ( struct V_10 * V_1 , struct V_11 * V_12 ,
T_1 V_34 )
{
int V_21 ;
V_21 = F_34 ( V_1 ) ;
if ( V_21 )
return V_21 ;
return F_7 ( V_1 , V_12 , V_34 ) ;
}
static T_2 F_38 ( struct V_10 * V_1 , struct V_32 * V_32 ,
int V_33 , T_1 V_34 , int V_35 )
{
int V_21 ;
V_21 = F_34 ( V_1 ) ;
if ( V_21 )
return V_21 ;
return F_20 ( V_1 , V_32 , V_33 , V_34 , V_35 ) ;
}
static int F_39 ( struct V_10 * V_1 , struct V_11 * V_12 ,
T_1 V_13 , int V_35 )
{
int V_21 ;
V_21 = F_34 ( V_1 ) ;
if ( V_21 )
return V_21 ;
return F_25 ( V_1 , V_12 , V_13 , V_35 ) ;
}
static int F_40 ( struct V_10 * V_1 , struct V_10 * V_38 ,
int V_35 , bool V_39 )
{
int V_21 ;
V_21 = F_34 ( V_1 ) ;
if ( V_21 )
return V_21 ;
return F_27 ( V_1 , V_38 , V_35 , V_39 ) ;
}
static void * F_41 ( const char * V_55 , T_3 type , T_3 V_56 )
{
struct V_48 * V_49 ;
struct V_57 * V_58 ;
V_49 = F_42 ( sizeof( * V_49 ) , V_8 ) ;
if ( ! V_49 )
return F_43 ( - V_9 ) ;
V_58 = F_44 ( V_55 , type , V_56 ) ;
if ( F_45 ( V_58 ) ) {
F_46 ( V_49 ) ;
return F_47 ( V_58 ) ;
}
V_49 -> V_58 = V_58 ;
return V_49 ;
}
static void F_48 ( void * V_19 )
{
struct V_48 * V_49 = V_19 ;
F_49 ( V_49 -> V_58 ) ;
F_46 ( V_49 ) ;
}
static int F_50 ( void * V_19 , const T_4 * V_59 , unsigned int V_60 )
{
struct V_48 * V_49 = V_19 ;
int V_21 ;
V_21 = F_51 ( V_49 -> V_58 , V_59 , V_60 ) ;
V_49 -> V_54 = ! V_21 ;
return V_21 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 = V_18 -> V_19 ;
F_5 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 , V_4 -> V_28 ) ;
F_54 ( V_2 ) ;
}
static int F_55 ( void * V_19 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_48 * V_49 = V_19 ;
struct V_57 * V_58 = V_49 -> V_58 ;
unsigned V_28 = sizeof( * V_4 ) + F_56 ( V_58 ) ;
V_4 = F_4 ( V_2 , V_28 , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_4 -> V_6 = NULL ;
V_4 -> V_28 = V_28 ;
V_4 -> V_23 = 0 ;
F_57 ( & V_4 -> V_26 ) ;
V_18 -> V_19 = V_4 ;
F_58 ( & V_4 -> V_7 , V_58 ) ;
F_59 ( & V_4 -> V_7 , V_61 ,
V_62 , & V_4 -> V_26 ) ;
V_2 -> V_63 = F_52 ;
return 0 ;
}
static int F_60 ( void * V_19 , struct V_1 * V_2 )
{
struct V_48 * V_49 = V_19 ;
if ( ! V_49 -> V_54 && F_61 ( V_49 -> V_58 ) )
return - V_52 ;
return F_55 ( V_19 , V_2 ) ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_64 ) ;
}
static void T_6 F_64 ( void )
{
int V_21 = F_65 ( & V_64 ) ;
F_66 ( V_21 ) ;
}
