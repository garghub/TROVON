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
static int T_3 F_10 ( const struct V_15
* V_16 ,
struct V_7 * V_8 ,
T_4 V_17 )
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
static int T_3 F_15 ( struct V_25 * V_26 )
{
const struct V_15 * V_16 = V_26 -> V_2 . V_27 ;
struct V_7 * V_8 ;
int V_28 ;
T_2 V_4 ;
T_4 V_17 ;
if ( ! V_16 ) {
F_13 ( L_2 ) ;
return - V_29 ;
}
V_8 = F_16 ( sizeof( struct V_7 ) , V_30 ) ;
if ( ! V_8 ) {
F_13 ( L_3 ) ;
return - V_31 ;
}
V_28 = F_3 ( V_26 -> V_2 . V_10 , V_32 , & V_4 , sizeof( V_4 ) ) ;
if ( V_28 ) {
F_13 ( L_4 , V_32 , V_28 ) ;
goto V_33;
}
F_17 ( L_5 , V_4 ) ;
V_17 = V_4 ;
V_28 = F_3 ( V_26 -> V_2 . V_10 , V_34 , & V_4 , sizeof( V_4 ) ) ;
if ( V_28 ) {
F_13 ( L_6 ,
V_34 , V_28 ) ;
goto V_33;
}
F_17 ( L_7 , V_4 ) ;
V_17 |= V_4 << V_35 ;
V_8 -> V_2 = & V_26 -> V_2 ;
V_6 . V_9 = V_8 ;
F_18 ( V_26 , & V_6 ) ;
V_28 = F_10 ( V_16 , V_8 , V_17 ) ;
if ( V_28 ) {
F_13 ( L_8 , V_28 ) ;
goto V_36;
}
F_19 ( V_8 -> V_14 == NULL ) ;
return 0 ;
V_36:
F_20 ( V_8 -> V_2 ) ;
F_18 ( V_26 , NULL ) ;
V_33:
F_21 ( V_8 ) ;
return V_28 ;
}
static int T_5 F_22 ( struct V_25 * V_26 )
{
struct V_5 * V_37 ;
struct V_7 * V_8 = NULL ;
V_37 = F_23 ( V_26 ) ;
if ( V_37 )
V_8 = V_37 -> V_9 ;
if ( V_8 )
F_20 ( V_8 -> V_2 ) ;
if ( V_8 -> V_14 ) {
F_24 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
}
F_18 ( V_26 , NULL ) ;
F_21 ( V_8 ) ;
return 0 ;
}
static int T_6 F_25 ( void )
{
return F_26 ( & V_38 ) ;
}
static void T_7 F_27 ( void )
{
F_28 ( & V_38 ) ;
}
