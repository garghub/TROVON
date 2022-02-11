void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 ) ;
F_3 ( V_4 -> V_6 ) ;
}
struct V_7 *
F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_7 * V_14 ;
void * V_15 ;
V_15 = F_5 ( V_9 -> V_16 ) ;
if ( ! V_15 ) {
F_6 ( L_2 ) ;
return F_7 ( - V_17 ) ;
}
V_14 = F_8 ( V_2 , V_9 , V_11 ) ;
if ( F_9 ( V_14 ) ) {
F_10 ( V_9 -> V_16 , V_15 ) ;
return V_14 ;
}
V_13 = F_11 ( V_14 ) ;
V_13 -> V_15 = V_15 ;
return V_14 ;
}
void F_12 ( struct V_7 * V_18 )
{
if ( V_18 -> V_19 ) {
struct V_12 * V_13 ;
V_13 = F_11 ( V_18 ) ;
F_10 ( V_18 -> V_19 -> V_16 , V_13 -> V_15 ) ;
V_13 -> V_15 = NULL ;
}
F_13 ( V_18 ) ;
}
static struct V_20 *
F_14 ( struct V_1 * V_2 , struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return F_15 ( V_2 , V_22 , V_24 ,
V_4 -> V_25 ) ;
}
static int F_16 ( struct V_26 * V_27 , struct V_3 * V_4 ,
const struct V_28 * V_25 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 ;
F_17 ( & V_4 -> V_31 ) ;
V_4 -> V_25 = V_25 ;
V_2 = F_18 ( V_30 , V_27 ) ;
if ( F_9 ( V_2 ) )
return F_19 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
F_20 ( V_2 ) ;
V_2 -> V_32 . V_33 = & V_34 ;
return 0 ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_22 ( V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_31 ) ;
V_4 -> V_2 -> V_5 = NULL ;
F_24 ( V_4 -> V_2 ) ;
}
static void F_25 ( void * V_35 )
{
F_21 ( V_35 ) ;
}
int F_26 ( struct V_26 * V_27 , struct V_3 * V_4 ,
const struct V_28 * V_25 ,
struct V_29 * V_30 )
{
int V_36 ;
V_36 = F_16 ( V_27 , V_4 , V_25 , V_30 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_27 ( V_27 , F_25 , V_4 ) ;
if ( V_36 )
F_21 ( V_4 ) ;
return V_36 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_37 = V_2 -> V_32 . V_38 ;
struct V_39 * V_40 ;
int V_36 ;
V_36 = F_29 ( V_4 -> V_2 , 0 ) ;
if ( V_36 )
return V_36 ;
V_40 = F_30 ( V_2 , V_37 ? V_37 : 32 ,
V_2 -> V_32 . V_41 ,
V_4 -> V_25 ) ;
if ( F_9 ( V_40 ) )
F_6 ( L_3 , F_19 ( V_40 ) ) ;
else
V_4 -> V_6 = V_40 ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_39 * V_6 = V_4 -> V_6 ;
F_32 ( V_4 -> V_2 ) ;
V_4 -> V_6 = NULL ;
F_33 ( V_4 -> V_2 ) ;
if ( V_6 )
F_34 ( V_6 ) ;
}
static void F_35 ( void * V_35 )
{
F_31 ( V_35 ) ;
}
int F_36 ( struct V_3 * V_4 )
{
struct V_26 * V_42 = V_4 -> V_2 -> V_42 ;
int V_36 ;
V_36 = F_28 ( V_4 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_27 ( V_42 , F_35 , V_4 ) ;
if ( V_36 )
F_31 ( V_4 ) ;
return V_36 ;
}
void F_37 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_2 ) ;
}
int F_38 ( struct V_3 * V_4 )
{
struct V_43 * V_44 ;
if ( V_4 -> V_45 ) {
F_6 ( L_4 ) ;
return - V_46 ;
}
F_39 ( V_4 -> V_6 , 1 ) ;
V_44 = F_40 ( V_4 -> V_2 ) ;
if ( F_9 ( V_44 ) ) {
F_39 ( V_4 -> V_6 , 0 ) ;
return F_19 ( V_44 ) ;
}
V_4 -> V_45 = V_44 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 )
{
struct V_43 * V_44 = V_4 -> V_45 ;
int V_36 ;
if ( ! V_44 ) {
F_6 ( L_5 ) ;
return - V_46 ;
}
V_4 -> V_45 = NULL ;
V_36 = F_42 ( V_4 -> V_2 , V_44 ) ;
if ( V_36 ) {
F_6 ( L_6 , V_36 ) ;
return V_36 ;
}
F_39 ( V_4 -> V_6 , 0 ) ;
return 0 ;
}
