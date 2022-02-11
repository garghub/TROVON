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
if ( ! F_8 ( V_12 ) )
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
if ( ! F_12 ( V_7 -> V_2 . V_12 ) )
return 0 ;
V_18 = F_13 ( V_7 -> V_2 . V_12 ) ;
return F_14 ( V_15 , V_18 ) != NULL ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = 0 ;
if ( ! V_2 -> V_5 )
V_4 = F_6 ( V_2 ) ;
return V_4 ;
}
static void F_16 ( struct V_1 * V_12 )
{
int V_19 ;
V_19 = F_9 ( V_12 , NULL , F_15 ) ;
if ( V_19 < 0 )
F_17 ( V_20 L_1 ,
V_21 , V_19 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_8 = F_3 ( V_23 ) ;
if ( V_7 -> V_24 == V_8 -> V_24 ) {
if ( V_8 -> V_25 )
return V_8 -> V_25 ( V_8 , V_7 ) ;
else
return 1 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_19 ;
V_8 = F_3 ( V_2 -> V_5 ) ;
V_7 = F_2 ( V_2 ) ;
F_20 ( V_2 ) ;
V_19 = V_8 -> V_26 ( V_7 ) ;
if ( V_19 )
F_21 ( V_2 ) ;
else
F_16 ( V_2 -> V_12 ) ;
return V_19 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
V_8 = F_3 ( V_2 -> V_5 ) ;
V_7 = F_2 ( V_2 ) ;
V_8 -> remove ( V_7 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_27 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_19 = 0 ;
V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 ) {
V_8 = F_3 ( V_2 -> V_5 ) ;
if ( V_8 -> V_28 )
V_19 = V_8 -> V_28 ( V_7 , V_27 ) ;
}
return V_19 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
int V_19 = 0 ;
V_7 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 ) {
V_8 = F_3 ( V_2 -> V_5 ) ;
if ( V_8 -> V_29 )
V_19 = V_8 -> V_29 ( V_7 ) ;
}
return V_19 ;
}
static T_2 F_25 ( struct V_1 * V_2 , struct V_30 * V_31 , char * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_32 , L_2 , V_7 -> V_24 ) ;
}
static T_2 F_26 ( struct V_1 * V_2 , struct V_30 * V_31 , char * V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_32 , L_3 , V_7 -> V_33 ) ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_34 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_34 ) ;
}
