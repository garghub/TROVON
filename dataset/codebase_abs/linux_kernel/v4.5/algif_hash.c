static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
int V_6 = V_7 * V_8 ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
long V_15 = 0 ;
int V_16 ;
if ( V_6 > V_9 -> V_17 )
V_6 = V_9 -> V_17 ;
F_3 ( V_9 ) ;
if ( ! V_13 -> V_18 ) {
V_16 = F_4 ( F_5 ( & V_13 -> V_19 ) ,
& V_13 -> V_20 ) ;
if ( V_16 )
goto V_21;
}
V_13 -> V_18 = 0 ;
while ( F_6 ( V_4 ) ) {
int V_22 = F_6 ( V_4 ) ;
if ( V_22 > V_6 )
V_22 = V_6 ;
V_22 = F_7 ( & V_13 -> V_23 , & V_4 -> V_24 , V_22 ) ;
if ( V_22 < 0 ) {
V_16 = V_15 ? 0 : V_22 ;
goto V_21;
}
F_8 ( & V_13 -> V_19 , V_13 -> V_23 . V_25 , NULL , V_22 ) ;
V_16 = F_4 ( F_9 ( & V_13 -> V_19 ) ,
& V_13 -> V_20 ) ;
F_10 ( & V_13 -> V_23 ) ;
if ( V_16 )
goto V_21;
V_15 += V_22 ;
F_11 ( & V_4 -> V_24 , V_22 ) ;
}
V_16 = 0 ;
V_13 -> V_18 = V_4 -> V_26 & V_27 ;
if ( ! V_13 -> V_18 ) {
F_8 ( & V_13 -> V_19 , NULL , V_13 -> V_28 , 0 ) ;
V_16 = F_4 ( F_12 ( & V_13 -> V_19 ) ,
& V_13 -> V_20 ) ;
}
V_21:
F_13 ( V_9 ) ;
return V_16 ? : V_15 ;
}
static T_2 F_14 ( struct V_1 * V_2 , struct V_29 * V_29 ,
int V_30 , T_1 V_31 , int V_32 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
int V_16 ;
if ( V_32 & V_33 )
V_32 |= V_27 ;
F_3 ( V_9 ) ;
F_15 ( V_13 -> V_23 . V_25 , 1 ) ;
F_16 ( V_13 -> V_23 . V_25 , V_29 , V_31 , V_30 ) ;
F_8 ( & V_13 -> V_19 , V_13 -> V_23 . V_25 , V_13 -> V_28 , V_31 ) ;
if ( ! ( V_32 & V_27 ) ) {
if ( V_13 -> V_18 )
V_16 = F_17 ( & V_13 -> V_19 ) ;
else
V_16 = F_18 ( & V_13 -> V_19 ) ;
} else {
if ( ! V_13 -> V_18 ) {
V_16 = F_5 ( & V_13 -> V_19 ) ;
V_16 = F_4 ( V_16 , & V_13 -> V_20 ) ;
if ( V_16 )
goto V_21;
}
V_16 = F_9 ( & V_13 -> V_19 ) ;
}
V_16 = F_4 ( V_16 , & V_13 -> V_20 ) ;
if ( V_16 )
goto V_21;
V_13 -> V_18 = V_32 & V_27 ;
V_21:
F_13 ( V_9 ) ;
return V_16 ? : V_31 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_22 ,
int V_32 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
unsigned V_34 = F_20 ( F_21 ( & V_13 -> V_19 ) ) ;
int V_16 ;
if ( V_22 > V_34 )
V_22 = V_34 ;
else if ( V_22 < V_34 )
V_4 -> V_26 |= V_35 ;
F_3 ( V_9 ) ;
if ( V_13 -> V_18 ) {
V_13 -> V_18 = 0 ;
F_8 ( & V_13 -> V_19 , NULL , V_13 -> V_28 , 0 ) ;
V_16 = F_4 ( F_12 ( & V_13 -> V_19 ) ,
& V_13 -> V_20 ) ;
if ( V_16 )
goto V_21;
}
V_16 = F_22 ( V_4 , V_13 -> V_28 , V_22 ) ;
V_21:
F_13 ( V_9 ) ;
return V_16 ? : V_22 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_1 * V_36 , int V_32 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_37 * V_19 = & V_13 -> V_19 ;
char V_38 [ F_24 ( F_21 ( V_19 ) ) ] ;
struct V_2 * V_39 ;
struct V_10 * V_40 ;
struct V_12 * V_41 ;
bool V_18 ;
int V_16 ;
F_3 ( V_9 ) ;
V_18 = V_13 -> V_18 ;
V_16 = V_18 ? F_25 ( V_19 , V_38 ) : 0 ;
F_13 ( V_9 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_26 ( V_11 -> V_42 , V_36 ) ;
if ( V_16 )
return V_16 ;
V_39 = V_36 -> V_9 ;
V_40 = F_2 ( V_39 ) ;
V_41 = V_40 -> V_14 ;
V_41 -> V_18 = V_18 ;
if ( ! V_18 )
return V_16 ;
V_16 = F_27 ( & V_41 -> V_19 , V_38 ) ;
if ( V_16 ) {
F_28 ( V_39 ) ;
F_29 ( V_39 ) ;
}
return V_16 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
struct V_2 * V_43 ;
struct V_10 * V_44 ;
struct V_45 * V_46 ;
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
F_3 ( V_9 ) ;
if ( V_11 -> V_47 )
goto V_48;
V_43 = V_11 -> V_42 ;
V_44 = F_2 ( V_11 -> V_42 ) ;
V_46 = V_44 -> V_14 ;
V_16 = - V_49 ;
F_31 ( V_43 , V_50 ) ;
if ( ! V_46 -> V_51 )
goto V_21;
if ( ! V_44 -> V_47 ++ )
F_32 ( V_43 ) ;
V_11 -> V_47 = 1 ;
F_29 ( V_43 ) ;
V_16 = 0 ;
V_21:
F_13 ( V_43 ) ;
V_48:
F_13 ( V_9 ) ;
return V_16 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_31 )
{
int V_16 ;
V_16 = F_30 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_1 ( V_2 , V_4 , V_31 ) ;
}
static T_2 F_34 ( struct V_1 * V_2 , struct V_29 * V_29 ,
int V_30 , T_1 V_31 , int V_32 )
{
int V_16 ;
V_16 = F_30 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_14 ( V_2 , V_29 , V_30 , V_31 , V_32 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , int V_32 )
{
int V_16 ;
V_16 = F_30 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_19 ( V_2 , V_4 , V_5 , V_32 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_1 * V_36 ,
int V_32 )
{
int V_16 ;
V_16 = F_30 ( V_2 ) ;
if ( V_16 )
return V_16 ;
return F_23 ( V_2 , V_36 , V_32 ) ;
}
static void * F_37 ( const char * V_52 , T_3 type , T_3 V_53 )
{
struct V_45 * V_46 ;
struct V_54 * V_55 ;
V_46 = F_38 ( sizeof( * V_46 ) , V_56 ) ;
if ( ! V_46 )
return F_39 ( - V_57 ) ;
V_55 = F_40 ( V_52 , type , V_53 ) ;
if ( F_41 ( V_55 ) ) {
F_42 ( V_46 ) ;
return F_43 ( V_55 ) ;
}
V_46 -> V_55 = V_55 ;
return V_46 ;
}
static void F_44 ( void * V_14 )
{
struct V_45 * V_46 = V_14 ;
F_45 ( V_46 -> V_55 ) ;
F_42 ( V_46 ) ;
}
static int F_46 ( void * V_14 , const T_4 * V_58 , unsigned int V_59 )
{
struct V_45 * V_46 = V_14 ;
int V_16 ;
V_16 = F_47 ( V_46 -> V_55 , V_58 , V_59 ) ;
V_46 -> V_51 = ! V_16 ;
return V_16 ;
}
static void F_48 ( struct V_2 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_49 ( V_9 , V_13 -> V_28 ,
F_20 ( F_21 ( & V_13 -> V_19 ) ) ) ;
F_50 ( V_9 , V_13 , V_13 -> V_22 ) ;
F_51 ( V_9 ) ;
}
static int F_52 ( void * V_14 , struct V_2 * V_9 )
{
struct V_12 * V_13 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_45 * V_46 = V_14 ;
struct V_54 * V_55 = V_46 -> V_55 ;
unsigned V_22 = sizeof( * V_13 ) + F_53 ( V_55 ) ;
unsigned V_34 = F_20 ( V_55 ) ;
V_13 = F_54 ( V_9 , V_22 , V_56 ) ;
if ( ! V_13 )
return - V_57 ;
V_13 -> V_28 = F_54 ( V_9 , V_34 , V_56 ) ;
if ( ! V_13 -> V_28 ) {
F_50 ( V_9 , V_13 , V_22 ) ;
return - V_57 ;
}
memset ( V_13 -> V_28 , 0 , V_34 ) ;
V_13 -> V_22 = V_22 ;
V_13 -> V_18 = 0 ;
F_55 ( & V_13 -> V_20 ) ;
V_11 -> V_14 = V_13 ;
F_56 ( & V_13 -> V_19 , V_55 ) ;
F_57 ( & V_13 -> V_19 , V_60 ,
V_61 , & V_13 -> V_20 ) ;
V_9 -> V_62 = F_48 ;
return 0 ;
}
static int F_58 ( void * V_14 , struct V_2 * V_9 )
{
struct V_45 * V_46 = V_14 ;
if ( ! V_46 -> V_51 && F_59 ( V_46 -> V_55 ) )
return - V_49 ;
return F_52 ( V_14 , V_9 ) ;
}
static int T_5 F_60 ( void )
{
return F_61 ( & V_63 ) ;
}
static void T_6 F_62 ( void )
{
int V_16 = F_63 ( & V_63 ) ;
F_64 ( V_16 ) ;
}
