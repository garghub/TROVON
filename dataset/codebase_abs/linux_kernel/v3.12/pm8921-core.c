static int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
return F_3 ( V_8 -> V_2 -> V_10 , V_3 , V_4 , 1 ) ;
}
static int F_4 ( const struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
return F_5 ( V_8 -> V_2 -> V_10 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( const struct V_1 * V_2 , T_1 V_3 , T_2 * V_11 ,
int V_12 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
return F_3 ( V_8 -> V_2 -> V_10 , V_3 , V_11 , V_12 ) ;
}
static int F_7 ( const struct V_1 * V_2 , T_1 V_3 , T_2 * V_11 ,
int V_12 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
return F_5 ( V_8 -> V_2 -> V_10 , V_3 , V_11 , V_12 ) ;
}
static int F_8 ( const struct V_1 * V_2 , int V_13 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_6 -> V_9 ;
return F_9 ( V_8 -> V_14 , V_13 ) ;
}
static int F_10 ( const struct V_15
* V_16 ,
struct V_7 * V_8 ,
T_3 V_17 )
{
int V_18 = 0 , V_19 = 0 ;
struct V_20 * V_14 ;
if ( V_16 -> V_21 ) {
V_16 -> V_21 -> V_22 . V_23 = V_24 ;
V_16 -> V_21 -> V_22 . V_17 = V_17 ;
V_19 = V_16 -> V_21 -> V_19 ;
V_14 = F_11 ( V_8 -> V_2 , V_16 -> V_21 ) ;
if ( F_12 ( V_14 ) ) {
F_13 ( L_1 ,
F_14 ( V_14 ) ) ;
return F_14 ( V_14 ) ;
}
V_8 -> V_14 = V_14 ;
}
return V_18 ;
}
static int F_15 ( struct V_25 * V_26 )
{
const struct V_15 * V_16 = F_16 ( & V_26 -> V_2 ) ;
struct V_7 * V_8 ;
int V_27 ;
T_2 V_4 ;
T_3 V_17 ;
if ( ! V_16 ) {
F_13 ( L_2 ) ;
return - V_28 ;
}
V_8 = F_17 ( & V_26 -> V_2 , sizeof( struct V_7 ) , V_29 ) ;
if ( ! V_8 ) {
F_13 ( L_3 ) ;
return - V_30 ;
}
V_27 = F_3 ( V_26 -> V_2 . V_10 , V_31 , & V_4 , sizeof( V_4 ) ) ;
if ( V_27 ) {
F_13 ( L_4 , V_31 , V_27 ) ;
return V_27 ;
}
F_18 ( L_5 , V_4 ) ;
V_17 = V_4 ;
V_27 = F_3 ( V_26 -> V_2 . V_10 , V_32 , & V_4 , sizeof( V_4 ) ) ;
if ( V_27 ) {
F_13 ( L_6 ,
V_32 , V_27 ) ;
return V_27 ;
}
F_18 ( L_7 , V_4 ) ;
V_17 |= V_4 << V_33 ;
V_8 -> V_2 = & V_26 -> V_2 ;
V_6 . V_9 = V_8 ;
F_19 ( V_26 , & V_6 ) ;
V_27 = F_10 ( V_16 , V_8 , V_17 ) ;
if ( V_27 ) {
F_13 ( L_8 , V_27 ) ;
goto V_34;
}
F_20 ( V_8 -> V_14 == NULL ) ;
return 0 ;
V_34:
F_21 ( V_8 -> V_2 ) ;
return V_27 ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_5 * V_35 ;
struct V_7 * V_8 = NULL ;
V_35 = F_23 ( V_26 ) ;
if ( V_35 )
V_8 = V_35 -> V_9 ;
if ( V_8 )
F_21 ( V_8 -> V_2 ) ;
if ( V_8 -> V_14 ) {
F_24 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
}
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_36 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_36 ) ;
}
