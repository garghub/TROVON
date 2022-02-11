static void F_1 ( T_1 V_1 , T_1 T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static T_1 F_3 ( T_1 T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_5 ( T_3 V_1 , T_3 T_2 * V_2 )
{
F_6 ( V_1 , V_2 ) ;
}
static T_3 F_7 ( T_3 T_2 * V_2 )
{
return F_8 ( V_2 ) ;
}
static void F_9 ( T_4 V_1 , T_4 T_2 * V_2 )
{
F_10 ( V_1 , V_2 ) ;
}
static T_4 F_11 ( T_4 T_2 * V_2 )
{
return F_12 ( V_2 ) ;
}
static int F_13 ( struct V_3 * V_4 , int type ,
T_5 V_5 , struct V_6 * V_7 )
{
return F_14 ( type , V_4 -> V_8 , V_5 , V_7 ) ;
}
static void F_15 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
}
int F_17 ( struct V_9 * V_10 , struct V_11 * V_8 ,
const struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
int V_16 ;
static int V_17 ;
if ( V_15 == NULL )
V_15 = & V_18 ;
V_16 = F_18 ( & V_10 -> V_4 , V_8 , V_13 , V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
F_19 ( & V_10 -> V_19 ) ;
V_10 -> V_17 = V_17 ++ ;
return 0 ;
}
void F_20 ( struct V_9 * V_10 )
{
F_21 ( & V_10 -> V_4 ) ;
F_22 ( ! F_23 ( & V_10 -> V_19 ) ) ;
}
static void F_24 ( struct V_11 * V_8 )
{
F_25 ( F_26 ( V_8 , struct V_20 , V_8 ) ) ;
}
int F_27 ( struct V_9 * V_10 , int V_2 )
{
struct V_20 * V_21 = NULL ;
struct V_3 * V_4 = F_28 ( V_10 ) ;
char V_22 [ 15 ] ;
int V_16 ;
V_21 = F_29 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return - V_24 ;
snprintf ( V_22 , sizeof( V_22 ) , L_1 , V_10 -> V_17 , V_2 ) ;
V_16 = F_30 ( V_21 , V_4 , V_22 , V_2 ) ;
if ( V_16 < 0 ) {
F_31 ( V_4 -> V_8 , L_2 ) ;
return V_16 ;
}
V_21 -> type = V_25 ;
V_21 -> V_8 . V_26 = F_24 ;
V_16 = F_32 ( V_21 ) ;
if ( V_16 ) {
F_31 ( V_4 -> V_8 , L_3 ) ;
F_25 ( V_21 ) ;
return V_16 ;
}
return 0 ;
}
void F_25 ( struct V_20 * V_21 )
{
F_33 ( V_21 ) ;
F_34 ( V_21 ) ;
}
