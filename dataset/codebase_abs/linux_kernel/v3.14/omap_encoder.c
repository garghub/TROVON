struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_4 ( V_3 , false ) ;
F_5 ( V_3 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_2 * V_3 , int V_6 )
{
}
static bool F_8 ( struct V_2 * V_3 ,
const struct V_7 * V_6 ,
struct V_7 * V_8 )
{
return true ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_7 * V_6 ,
struct V_7 * V_8 )
{
}
static void F_10 ( struct V_2 * V_3 )
{
}
static void F_11 ( struct V_2 * V_3 )
{
}
int F_4 ( struct V_2 * V_3 , bool V_9 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_10 * V_11 = V_5 -> V_12 ;
if ( V_9 ) {
return V_11 -> V_13 ( V_5 ) ;
} else {
V_11 -> V_14 ( V_5 ) ;
return 0 ;
}
}
int F_12 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_3 -> V_20 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_1 * V_5 = V_4 -> V_5 ;
struct V_10 * V_11 = V_5 -> V_12 ;
int V_21 ;
V_5 -> V_22 -> V_23 = V_16 ;
if ( V_11 -> V_24 ) {
V_21 = V_11 -> V_24 ( V_5 , V_18 ) ;
} else {
struct V_17 V_25 = { 0 } ;
V_11 -> V_26 ( V_5 , & V_25 ) ;
if ( memcmp ( V_18 , & V_25 , sizeof( struct V_17 ) ) )
V_21 = - V_27 ;
else
V_21 = 0 ;
}
if ( V_21 ) {
F_13 ( V_20 -> V_20 , L_1 , V_21 ) ;
return V_21 ;
}
if ( V_11 -> V_28 )
V_11 -> V_28 ( V_5 , V_18 ) ;
return 0 ;
}
struct V_2 * F_14 ( struct V_19 * V_20 ,
struct V_1 * V_5 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
goto V_30;
V_4 -> V_5 = V_5 ;
V_3 = & V_4 -> V_31 ;
F_16 ( V_20 , V_3 , & V_32 ,
V_33 ) ;
F_17 ( V_3 , & V_34 ) ;
return V_3 ;
V_30:
if ( V_3 )
F_3 ( V_3 ) ;
return NULL ;
}
