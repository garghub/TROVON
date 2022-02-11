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
void F_11 ( struct V_1 * V_5 )
{
F_5 ( V_5 ) -> F_12 ( V_5 , V_20 ) ;
}
void F_13 ( struct V_1 * V_5 )
{
F_5 ( V_5 ) -> F_12 ( V_5 , V_21 ) ;
}
bool F_14 ( struct V_1 * V_5 ,
const struct V_22 * V_23 , struct V_22 * V_24 )
{
return true ;
}
int F_15 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_25 = V_26 ;
if ( V_5 ) {
struct V_27 * V_28 = F_16 ( V_5 ) ;
V_25 = V_28 -> V_29 -> V_30 ( V_5 , V_23 ) ;
}
return V_25 ;
}
int F_17 ( struct V_2 * V_3 ,
struct V_15 * V_16 , T_1 V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_31 = - V_19 ;
if ( V_5 ) {
struct V_27 * V_28 = F_16 ( V_5 ) ;
V_31 = V_28 -> V_29 -> V_18 ( V_5 , V_3 , V_16 ,
V_17 ) ;
}
return V_31 ;
}
int F_18 ( struct V_32 * V_6 ,
const struct V_33 * type , const void * V_34 )
{
struct V_10 * V_11 ;
int V_35 ;
V_11 = F_19 ( sizeof( * V_11 ) , V_36 ) ;
if ( ! V_11 )
return - V_37 ;
V_11 -> type = type ;
V_35 = F_20 ( V_6 , & V_11 -> V_3 , & V_38 ,
type -> V_39 ) ;
if ( V_35 ) {
F_21 ( L_1 ) ;
goto V_40;
}
V_35 = type -> V_41 ( & V_11 -> V_3 , V_34 ) ;
if ( V_35 )
goto V_42;
V_35 = F_22 ( & V_11 -> V_3 ) ;
if ( V_35 )
goto V_43;
return 0 ;
V_43:
if ( V_11 -> V_3 . V_5 )
V_11 -> V_3 . V_5 -> V_44 -> V_45 ( V_11 -> V_3 . V_5 ) ;
V_42:
F_8 ( & V_11 -> V_3 ) ;
V_40:
F_9 ( V_11 ) ;
return V_35 ;
}
