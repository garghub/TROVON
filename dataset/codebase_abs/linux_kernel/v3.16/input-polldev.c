static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 >= V_5 )
V_3 = F_3 ( V_3 ) ;
F_4 ( V_6 , & V_2 -> V_7 , V_3 ) ;
}
static void F_5 ( struct V_8 * V_7 )
{
struct V_1 * V_2 =
F_6 ( V_7 , struct V_1 , V_7 . V_7 ) ;
V_2 -> V_9 ( V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 ) ;
if ( V_2 -> V_4 > 0 ) {
V_2 -> V_9 ( V_2 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
F_10 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_13 )
V_2 -> V_13 ( V_2 ) ;
}
static T_1 F_11 ( struct V_14 * V_2 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_18 = F_12 ( V_2 ) ;
return sprintf ( V_17 , L_1 , V_18 -> V_4 ) ;
}
static T_1 F_13 ( struct V_14 * V_2 ,
struct V_15 * V_16 , const char * V_17 ,
T_2 V_19 )
{
struct V_1 * V_18 = F_12 ( V_2 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned int V_20 ;
int V_21 ;
V_21 = F_14 ( V_17 , 0 , & V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_20 < V_18 -> V_22 )
return - V_23 ;
if ( V_20 > V_18 -> V_24 )
return - V_23 ;
F_15 ( & V_11 -> V_25 ) ;
V_18 -> V_4 = V_20 ;
if ( V_11 -> V_26 ) {
F_10 ( & V_18 -> V_7 ) ;
if ( V_18 -> V_4 > 0 )
F_1 ( V_18 ) ;
}
F_16 ( & V_11 -> V_25 ) ;
return V_19 ;
}
static T_1 F_17 ( struct V_14 * V_2 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_18 = F_12 ( V_2 ) ;
return sprintf ( V_17 , L_1 , V_18 -> V_24 ) ;
}
static T_1 F_18 ( struct V_14 * V_2 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_18 = F_12 ( V_2 ) ;
return sprintf ( V_17 , L_1 , V_18 -> V_22 ) ;
}
struct V_1 * F_19 ( void )
{
struct V_1 * V_2 ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_21 () ;
if ( ! V_2 -> V_11 ) {
F_22 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static int F_23 ( struct V_14 * V_2 , void * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 ;
return V_31 -> V_18 == V_29 ;
}
static void F_24 ( struct V_14 * V_2 , void * V_28 )
{
struct V_30 * V_31 = V_28 ;
struct V_1 * V_18 = V_31 -> V_18 ;
F_25 ( V_2 , L_2 ,
V_32 , F_26 ( & V_18 -> V_11 -> V_2 ) ) ;
F_27 ( V_18 -> V_11 ) ;
F_22 ( V_18 ) ;
}
static void F_28 ( struct V_14 * V_2 , void * V_28 )
{
struct V_30 * V_31 = V_28 ;
struct V_1 * V_18 = V_31 -> V_18 ;
F_25 ( V_2 , L_3 ,
V_32 , F_26 ( & V_18 -> V_11 -> V_2 ) ) ;
F_29 ( V_18 -> V_11 ) ;
}
struct V_1 * F_30 ( struct V_14 * V_2 )
{
struct V_1 * V_18 ;
struct V_30 * V_31 ;
V_31 = F_31 ( F_24 , sizeof( * V_31 ) ,
V_27 ) ;
if ( ! V_31 )
return NULL ;
V_18 = F_19 () ;
if ( ! V_18 ) {
F_32 ( V_31 ) ;
return NULL ;
}
V_18 -> V_11 -> V_2 . V_33 = V_2 ;
V_18 -> V_34 = true ;
V_31 -> V_18 = V_18 ;
F_33 ( V_2 , V_31 ) ;
return V_18 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_34 )
F_35 ( F_36 ( V_2 -> V_11 -> V_2 . V_33 ,
F_24 ,
F_23 ,
V_2 ) ) ;
F_27 ( V_2 -> V_11 ) ;
F_22 ( V_2 ) ;
}
}
int F_37 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = NULL ;
struct V_10 * V_11 = V_2 -> V_11 ;
int error ;
if ( V_2 -> V_34 ) {
V_31 = F_31 ( F_28 ,
sizeof( * V_31 ) , V_27 ) ;
if ( ! V_31 )
return - V_35 ;
V_31 -> V_18 = V_2 ;
}
F_38 ( V_11 , V_2 ) ;
F_39 ( & V_2 -> V_7 , F_5 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = 500 ;
if ( ! V_2 -> V_24 )
V_2 -> V_24 = V_2 -> V_4 ;
V_11 -> V_12 = F_7 ;
V_11 -> V_13 = F_9 ;
V_11 -> V_2 . V_36 = V_37 ;
error = F_40 ( V_11 ) ;
if ( error ) {
F_32 ( V_31 ) ;
return error ;
}
F_41 ( V_11 ) ;
if ( V_2 -> V_34 ) {
F_25 ( V_11 -> V_2 . V_33 , L_4 ,
V_32 , F_26 ( & V_11 -> V_2 ) ) ;
F_33 ( V_11 -> V_2 . V_33 , V_31 ) ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 )
F_35 ( F_36 ( V_2 -> V_11 -> V_2 . V_33 ,
F_28 ,
F_23 ,
V_2 ) ) ;
F_29 ( V_2 -> V_11 ) ;
}
