static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = 0 ;
if ( V_2 -> V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 -> V_5 ) ;
if ( V_9 -> V_10 )
V_4 = V_9 -> V_10 ( V_7 ) ;
else
F_4 ( V_2 ) ;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = 0 ;
if ( V_2 -> V_5 ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 -> V_5 ) ;
if ( V_9 -> V_11 )
V_4 = V_9 -> V_11 ( V_7 ) ;
} else
V_4 = F_6 ( V_2 ) ;
return V_4 ;
}
int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_12 = V_7 -> V_2 . V_12 ;
int V_4 = 0 ;
if ( F_8 ( V_12 ) )
return - V_13 ;
V_4 = F_9 ( V_12 , V_12 , F_1 ) ;
if ( V_4 >= 0 )
V_4 = F_9 ( V_12 , V_12 , F_5 ) ;
F_10 ( V_12 ) ;
return V_4 ;
}
int F_11 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
const struct V_14 * V_15 = V_9 -> V_16 ;
struct V_17 * V_18 ;
if ( V_7 -> V_2 . V_12 -> V_19 != & V_20 )
return 0 ;
V_18 = F_12 ( V_7 -> V_2 . V_12 ) ;
return F_13 ( V_15 , V_18 ) != NULL ;
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = 0 ;
if ( ! V_2 -> V_5 )
V_4 = F_6 ( V_2 ) ;
return V_4 ;
}
static void F_15 ( struct V_1 * V_12 )
{
int V_21 ;
V_21 = F_9 ( V_12 , NULL , F_14 ) ;
if ( V_21 < 0 )
F_16 ( V_22 L_1 ,
V_23 , V_21 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_8 = F_3 ( V_25 ) ;
if ( V_7 -> V_26 == V_8 -> V_26 ) {
if ( V_8 -> V_27 )
return V_8 -> V_27 ( V_8 , V_7 ) ;
else
return 1 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_21 ;
V_8 = F_3 ( V_2 -> V_5 ) ;
V_7 = F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
V_21 = V_8 -> V_28 ( V_7 ) ;
if ( V_21 )
F_20 ( V_2 ) ;
else
F_15 ( V_2 -> V_12 ) ;
return V_21 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
V_8 = F_3 ( V_2 -> V_5 ) ;
V_7 = F_2 ( V_2 ) ;
V_8 -> remove ( V_7 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_29 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_21 = 0 ;
V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 ) {
V_8 = F_3 ( V_2 -> V_5 ) ;
if ( V_8 -> V_30 )
V_21 = V_8 -> V_30 ( V_7 , V_29 ) ;
}
return V_21 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_21 = 0 ;
V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 ) {
V_8 = F_3 ( V_2 -> V_5 ) ;
if ( V_8 -> V_31 )
V_21 = V_8 -> V_31 ( V_7 ) ;
}
return V_21 ;
}
static T_2 F_24 ( struct V_1 * V_2 , struct V_32 * V_33 , char * V_34 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_34 , L_2 , V_7 -> V_26 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , struct V_32 * V_33 , char * V_34 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_34 , L_3 , V_7 -> V_35 ) ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_36 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_36 ) ;
}
