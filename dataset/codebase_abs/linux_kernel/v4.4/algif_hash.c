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
V_16 = F_4 ( & V_13 -> V_19 ) ;
if ( V_16 )
goto V_20;
}
V_13 -> V_18 = 0 ;
while ( F_5 ( V_4 ) ) {
int V_21 = F_5 ( V_4 ) ;
if ( V_21 > V_6 )
V_21 = V_6 ;
V_21 = F_6 ( & V_13 -> V_22 , & V_4 -> V_23 , V_21 ) ;
if ( V_21 < 0 ) {
V_16 = V_15 ? 0 : V_21 ;
goto V_20;
}
F_7 ( & V_13 -> V_19 , V_13 -> V_22 . V_24 , NULL , V_21 ) ;
V_16 = F_8 ( F_9 ( & V_13 -> V_19 ) ,
& V_13 -> V_25 ) ;
F_10 ( & V_13 -> V_22 ) ;
if ( V_16 )
goto V_20;
V_15 += V_21 ;
F_11 ( & V_4 -> V_23 , V_21 ) ;
}
V_16 = 0 ;
V_13 -> V_18 = V_4 -> V_26 & V_27 ;
if ( ! V_13 -> V_18 ) {
F_7 ( & V_13 -> V_19 , NULL , V_13 -> V_28 , 0 ) ;
V_16 = F_8 ( F_12 ( & V_13 -> V_19 ) ,
& V_13 -> V_25 ) ;
}
V_20:
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
F_15 ( V_13 -> V_22 . V_24 , 1 ) ;
F_16 ( V_13 -> V_22 . V_24 , V_29 , V_31 , V_30 ) ;
F_7 ( & V_13 -> V_19 , V_13 -> V_22 . V_24 , V_13 -> V_28 , V_31 ) ;
if ( ! ( V_32 & V_27 ) ) {
if ( V_13 -> V_18 )
V_16 = F_17 ( & V_13 -> V_19 ) ;
else
V_16 = F_18 ( & V_13 -> V_19 ) ;
} else {
if ( ! V_13 -> V_18 ) {
V_16 = F_4 ( & V_13 -> V_19 ) ;
if ( V_16 )
goto V_20;
}
V_16 = F_9 ( & V_13 -> V_19 ) ;
}
V_16 = F_8 ( V_16 , & V_13 -> V_25 ) ;
if ( V_16 )
goto V_20;
V_13 -> V_18 = V_32 & V_27 ;
V_20:
F_13 ( V_9 ) ;
return V_16 ? : V_31 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_21 ,
int V_32 )
{
struct V_2 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
unsigned V_34 = F_20 ( F_21 ( & V_13 -> V_19 ) ) ;
int V_16 ;
if ( V_21 > V_34 )
V_21 = V_34 ;
else if ( V_21 < V_34 )
V_4 -> V_26 |= V_35 ;
F_3 ( V_9 ) ;
if ( V_13 -> V_18 ) {
V_13 -> V_18 = 0 ;
F_7 ( & V_13 -> V_19 , NULL , V_13 -> V_28 , 0 ) ;
V_16 = F_8 ( F_12 ( & V_13 -> V_19 ) ,
& V_13 -> V_25 ) ;
if ( V_16 )
goto V_20;
}
V_16 = F_22 ( V_4 , V_13 -> V_28 , V_21 ) ;
V_20:
F_13 ( V_9 ) ;
return V_16 ? : V_21 ;
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
static void * F_30 ( const char * V_43 , T_3 type , T_3 V_44 )
{
return F_31 ( V_43 , type , V_44 ) ;
}
static void F_32 ( void * V_14 )
{
F_33 ( V_14 ) ;
}
static int F_34 ( void * V_14 , const T_4 * V_45 , unsigned int V_46 )
{
return F_35 ( V_14 , V_45 , V_46 ) ;
}
static void F_36 ( struct V_2 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_37 ( V_9 , V_13 -> V_28 ,
F_20 ( F_21 ( & V_13 -> V_19 ) ) ) ;
F_38 ( V_9 , V_13 , V_13 -> V_21 ) ;
F_39 ( V_9 ) ;
}
static int F_40 ( void * V_14 , struct V_2 * V_9 )
{
struct V_12 * V_13 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
unsigned V_21 = sizeof( * V_13 ) + F_41 ( V_14 ) ;
unsigned V_34 = F_20 ( V_14 ) ;
V_13 = F_42 ( V_9 , V_21 , V_47 ) ;
if ( ! V_13 )
return - V_48 ;
V_13 -> V_28 = F_42 ( V_9 , V_34 , V_47 ) ;
if ( ! V_13 -> V_28 ) {
F_38 ( V_9 , V_13 , V_21 ) ;
return - V_48 ;
}
memset ( V_13 -> V_28 , 0 , V_34 ) ;
V_13 -> V_21 = V_21 ;
V_13 -> V_18 = 0 ;
F_43 ( & V_13 -> V_25 ) ;
V_11 -> V_14 = V_13 ;
F_44 ( & V_13 -> V_19 , V_14 ) ;
F_45 ( & V_13 -> V_19 , V_49 ,
V_50 , & V_13 -> V_25 ) ;
V_9 -> V_51 = F_36 ;
return 0 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_52 ) ;
}
static void T_6 F_48 ( void )
{
int V_16 = F_49 ( & V_52 ) ;
F_50 ( V_16 ) ;
}
