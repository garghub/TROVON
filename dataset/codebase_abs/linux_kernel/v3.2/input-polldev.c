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
unsigned long V_20 ;
if ( F_14 ( V_17 , 0 , & V_20 ) )
return - V_21 ;
if ( V_20 < V_18 -> V_22 )
return - V_21 ;
if ( V_20 > V_18 -> V_23 )
return - V_21 ;
F_15 ( & V_11 -> V_24 ) ;
V_18 -> V_4 = V_20 ;
if ( V_11 -> V_25 ) {
F_10 ( & V_18 -> V_7 ) ;
if ( V_18 -> V_4 > 0 )
F_1 ( V_18 ) ;
}
F_16 ( & V_11 -> V_24 ) ;
return V_19 ;
}
static T_1 F_17 ( struct V_14 * V_2 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_18 = F_12 ( V_2 ) ;
return sprintf ( V_17 , L_1 , V_18 -> V_23 ) ;
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
V_2 = F_20 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = F_21 () ;
if ( ! V_2 -> V_11 ) {
F_22 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_23 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_24 ( V_2 -> V_11 ) ;
F_22 ( V_2 ) ;
}
}
int F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int error ;
F_26 ( V_11 , V_2 ) ;
F_27 ( & V_2 -> V_7 , F_5 ) ;
if ( ! V_2 -> V_4 )
V_2 -> V_4 = 500 ;
if ( ! V_2 -> V_23 )
V_2 -> V_23 = V_2 -> V_4 ;
V_11 -> V_12 = F_7 ;
V_11 -> V_13 = F_9 ;
error = F_28 ( V_11 ) ;
if ( error )
return error ;
error = F_29 ( & V_11 -> V_2 . V_27 ,
& V_28 ) ;
if ( error ) {
F_30 ( V_11 ) ;
return error ;
}
F_31 ( V_11 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_11 -> V_2 . V_27 ,
& V_28 ) ;
F_30 ( V_2 -> V_11 ) ;
}
