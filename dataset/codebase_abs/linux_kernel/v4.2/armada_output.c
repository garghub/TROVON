struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
return V_4 ? V_4 : F_2 ( V_3 -> V_6 , V_3 -> V_7 [ 0 ] ) ;
}
static enum V_8 F_3 (
struct V_2 * V_3 , bool V_9 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
enum V_8 V_12 = V_13 ;
if ( V_11 -> type -> V_14 ) {
V_12 = V_11 -> type -> V_14 ( V_3 , V_9 ) ;
} else {
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( V_4 )
V_12 = F_5 ( V_4 ) -> V_14 ( V_4 , V_3 ) ;
}
return V_12 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( V_11 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_15 * V_16 , T_1 V_17 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
if ( ! V_11 -> type -> V_18 )
return - V_19 ;
return V_11 -> type -> V_18 ( V_3 , V_16 , V_17 ) ;
}
int F_11 ( struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_22 = V_23 ;
if ( V_5 ) {
struct V_24 * V_25 = F_12 ( V_5 ) ;
V_22 = V_25 -> V_26 -> V_27 ( V_5 , V_21 ) ;
}
return V_22 ;
}
int F_13 ( struct V_2 * V_3 ,
struct V_15 * V_16 , T_1 V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_28 = - V_19 ;
if ( V_5 ) {
struct V_24 * V_25 = F_12 ( V_5 ) ;
V_28 = V_25 -> V_26 -> V_18 ( V_5 , V_3 , V_16 ,
V_17 ) ;
}
return V_28 ;
}
int F_14 ( struct V_29 * V_6 ,
const struct V_30 * type , const void * V_31 )
{
struct V_10 * V_11 ;
int V_32 ;
V_11 = F_15 ( sizeof( * V_11 ) , V_33 ) ;
if ( ! V_11 )
return - V_34 ;
V_11 -> type = type ;
V_32 = F_16 ( V_6 , & V_11 -> V_3 , & V_35 ,
type -> V_36 ) ;
if ( V_32 ) {
F_17 ( L_1 ) ;
goto V_37;
}
V_32 = type -> V_38 ( & V_11 -> V_3 , V_31 ) ;
if ( V_32 )
goto V_39;
V_32 = F_18 ( & V_11 -> V_3 ) ;
if ( V_32 )
goto V_40;
return 0 ;
V_40:
if ( V_11 -> V_3 . V_5 )
V_11 -> V_3 . V_5 -> V_41 -> V_42 ( V_11 -> V_3 . V_5 ) ;
V_39:
F_8 ( & V_11 -> V_3 ) ;
V_37:
F_9 ( V_11 ) ;
return V_32 ;
}
