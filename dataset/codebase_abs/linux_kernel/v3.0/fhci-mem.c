static void F_1 ( struct V_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
F_2 ( & V_1 -> V_2 ) ;
F_2 ( & V_1 -> V_3 ) ;
}
static void F_3 ( struct V_4 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_2 ( & V_4 -> V_5 ) ;
F_2 ( & V_4 -> V_2 ) ;
}
static struct V_1 * F_4 ( struct V_6 * V_7 )
{
struct V_1 * V_1 ;
if ( ! F_5 ( & V_7 -> V_8 ) ) {
V_1 = F_6 ( V_7 -> V_8 . V_9 , struct V_1 , V_2 ) ;
F_7 ( V_7 -> V_8 . V_9 ) ;
} else {
V_1 = F_8 ( sizeof( * V_1 ) , V_10 ) ;
if ( ! V_1 )
F_9 ( V_7 , L_1 ) ;
else
F_1 ( V_1 ) ;
}
return V_1 ;
}
void F_10 ( struct V_6 * V_7 , struct V_1 * V_1 )
{
F_1 ( V_1 ) ;
F_11 ( & V_1 -> V_2 , & V_7 -> V_8 ) ;
}
struct V_4 * F_12 ( struct V_6 * V_7 )
{
struct V_4 * V_4 ;
if ( ! F_5 ( & V_7 -> V_11 ) ) {
V_4 = F_6 ( V_7 -> V_11 . V_9 , struct V_4 , V_2 ) ;
F_7 ( V_7 -> V_11 . V_9 ) ;
} else {
V_4 = F_8 ( sizeof( * V_4 ) , V_10 ) ;
if ( ! V_4 )
F_9 ( V_7 , L_2 ) ;
else
F_3 ( V_4 ) ;
}
return V_4 ;
}
void F_13 ( struct V_6 * V_7 , struct V_4 * V_4 )
{
F_3 ( V_4 ) ;
F_11 ( & V_4 -> V_2 , & V_7 -> V_11 ) ;
}
struct V_1 * F_14 ( struct V_6 * V_7 , struct V_12 * V_12 ,
struct V_13 * V_13 , struct V_4 * V_4 , T_1 V_14 ,
enum V_15 type , int V_16 , T_2 * V_17 , T_3 V_18 ,
T_1 V_19 , T_1 V_20 , bool V_21 )
{
struct V_1 * V_1 = F_4 ( V_7 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_12 = V_12 ;
V_1 -> V_4 = V_4 ;
V_1 -> type = type ;
V_1 -> V_16 = V_16 ;
V_1 -> V_17 = V_17 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_22 = V_14 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_20 = V_20 ;
V_1 -> V_21 = V_21 ;
V_1 -> V_23 = V_24 ;
V_13 -> V_25 [ V_14 ] = V_1 ;
return V_1 ;
}
