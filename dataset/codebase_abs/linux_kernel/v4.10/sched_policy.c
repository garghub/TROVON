static bool F_1 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
struct V_5 * V_6 ;
F_2 (engine, vgpu->gvt->dev_priv, i) {
if ( ! F_3 ( F_4 ( V_2 , V_4 ) ) )
return true ;
}
return false ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_10 ;
enum V_3 V_4 ;
struct V_5 * V_6 ;
if ( ! V_10 -> V_11 )
return;
F_6 ( L_1 ,
V_10 -> V_11 -> V_12 ) ;
V_10 -> V_13 = true ;
F_2 (engine, gvt->dev_priv, i) {
if ( V_10 -> V_14 [ V_4 ] ) {
F_6 ( L_2 ) ;
return;
}
}
F_6 ( L_3 ,
V_10 -> V_11 -> V_12 ) ;
V_10 -> V_15 = V_10 -> V_11 ;
V_10 -> V_11 = NULL ;
V_10 -> V_13 = false ;
F_2 (engine, gvt->dev_priv, i)
F_7 ( & V_10 -> V_16 [ V_4 ] ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_9 ( V_18 ,
struct V_19 , V_18 . V_18 ) ;
struct V_21 * V_22 ;
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_1 * V_2 = NULL ;
struct V_23 * V_24 , * V_25 ;
F_10 ( & V_8 -> V_26 ) ;
if ( F_3 ( & V_20 -> V_27 ) || V_10 -> V_11 )
goto V_28;
if ( V_10 -> V_15 ) {
V_22 = V_10 -> V_15 -> V_20 ;
V_25 = & V_22 -> V_29 ;
} else {
F_6 ( L_4 ) ;
V_25 = & V_20 -> V_27 ;
}
F_11 (pos, head) {
if ( V_24 == & V_20 -> V_27 )
continue;
V_22 = F_9 ( V_24 , struct V_21 , V_29 ) ;
if ( ! F_1 ( V_22 -> V_2 ) )
continue;
V_2 = V_22 -> V_2 ;
break;
}
if ( V_2 ) {
V_10 -> V_11 = V_2 ;
F_6 ( L_5 , V_2 -> V_12 ) ;
}
V_28:
if ( V_10 -> V_11 ) {
F_6 ( L_1 ,
V_10 -> V_11 -> V_12 ) ;
F_5 ( V_8 ) ;
}
if ( ! F_3 ( & V_20 -> V_27 ) || V_10 -> V_11 )
F_12 ( & V_20 -> V_18 , V_20 -> V_30 ) ;
F_13 ( & V_8 -> V_26 ) ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_9 * V_10 =
& V_8 -> V_10 ;
struct V_19 * V_31 ;
V_31 = F_15 ( sizeof( * V_31 ) , V_32 ) ;
if ( ! V_31 )
return - V_33 ;
F_16 ( & V_31 -> V_27 ) ;
F_17 ( & V_31 -> V_18 , F_8 ) ;
V_31 -> V_30 = V_34 ;
V_31 -> V_8 = V_8 ;
V_10 -> V_20 = V_31 ;
return 0 ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_9 * V_10 =
& V_8 -> V_10 ;
struct V_19 * V_31 = V_10 -> V_20 ;
F_19 ( & V_31 -> V_18 ) ;
F_20 ( V_31 ) ;
V_10 -> V_20 = NULL ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_21 * V_31 ;
V_31 = F_15 ( sizeof( * V_31 ) , V_32 ) ;
if ( ! V_31 )
return - V_33 ;
V_31 -> V_2 = V_2 ;
F_16 ( & V_31 -> V_29 ) ;
V_2 -> V_20 = V_31 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_8 -> V_10 . V_20 ;
struct V_21 * V_22 = V_2 -> V_20 ;
if ( ! F_3 ( & V_22 -> V_29 ) )
return;
F_24 ( & V_22 -> V_29 , & V_20 -> V_27 ) ;
F_12 ( & V_20 -> V_18 , V_20 -> V_30 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_20 ;
F_26 ( & V_22 -> V_29 ) ;
}
int F_27 ( struct V_7 * V_8 )
{
V_8 -> V_10 . V_35 = & V_36 ;
return V_8 -> V_10 . V_35 -> V_37 ( V_8 ) ;
}
void F_28 ( struct V_7 * V_8 )
{
V_8 -> V_10 . V_35 -> V_38 ( V_8 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
return V_2 -> V_8 -> V_10 . V_35 -> V_39 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
V_2 -> V_8 -> V_10 . V_35 -> V_40 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_32 ( L_6 , V_2 -> V_12 ) ;
V_2 -> V_8 -> V_10 . V_35 -> V_41 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_9 * V_10 =
& V_2 -> V_8 -> V_10 ;
F_32 ( L_7 , V_2 -> V_12 ) ;
V_10 -> V_35 -> V_42 ( V_2 ) ;
if ( V_10 -> V_11 == V_2 )
V_10 -> V_11 = NULL ;
if ( V_10 -> V_15 == V_2 ) {
V_10 -> V_13 = true ;
V_10 -> V_15 = NULL ;
}
}
