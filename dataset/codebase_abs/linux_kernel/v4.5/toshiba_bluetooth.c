static int F_1 ( T_1 V_1 )
{
T_2 V_2 ;
T_3 V_3 ;
V_2 = F_2 ( V_1 , L_1 , NULL , & V_3 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_2 ) ;
return - V_4 ;
} else if ( ! V_3 ) {
F_5 ( L_3 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_6 ( T_1 V_1 )
{
T_2 V_2 ;
T_3 V_6 ;
V_2 = F_2 ( V_1 , L_4 , NULL , & V_6 ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_5 ) ;
return - V_4 ;
}
return V_6 ;
}
static int F_7 ( T_1 V_1 )
{
T_2 V_2 ;
V_2 = F_8 ( V_1 , L_6 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_7 ) ;
return - V_4 ;
}
V_2 = F_8 ( V_1 , L_8 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_9 ) ;
return - V_4 ;
}
return 0 ;
}
static int F_9 ( T_1 V_1 )
{
T_2 V_2 ;
V_2 = F_8 ( V_1 , L_10 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_11 ) ;
return - V_4 ;
}
V_2 = F_8 ( V_1 , L_12 , NULL , NULL ) ;
if ( F_3 ( V_2 ) ) {
F_4 ( L_13 ) ;
return - V_4 ;
}
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
int V_6 ;
V_6 = F_6 ( V_8 -> V_9 -> V_1 ) ;
if ( V_6 < 0 ) {
F_4 ( L_14 ) ;
return V_6 ;
}
V_8 -> V_10 = ( V_6 & V_11 ) ? true : false ;
V_8 -> V_12 = ( V_6 & V_13 ) ? true : false ;
V_8 -> V_14 = ( V_6 & V_15 ) ? true : false ;
F_11 ( L_15 ,
V_6 , V_8 -> V_10 , V_8 -> V_12 , V_8 -> V_14 ) ;
return 0 ;
}
static int F_12 ( void * V_16 , bool V_17 )
{
struct V_7 * V_8 = V_16 ;
int V_18 ;
V_18 = F_10 ( V_8 ) ;
if ( V_18 )
return V_18 ;
if ( ! V_8 -> V_10 )
return 0 ;
if ( V_17 )
V_18 = F_9 ( V_8 -> V_9 -> V_1 ) ;
else
V_18 = F_7 ( V_8 -> V_9 -> V_1 ) ;
return V_18 ;
}
static void F_13 ( struct V_19 * V_19 , void * V_16 )
{
struct V_7 * V_8 = V_16 ;
if ( F_10 ( V_8 ) )
return;
F_14 ( V_8 -> V_20 , ! V_8 -> V_10 ) ;
}
static void F_15 ( struct V_21 * V_22 , T_4 V_23 )
{
struct V_7 * V_8 = F_16 ( V_22 ) ;
if ( F_10 ( V_8 ) )
return;
F_14 ( V_8 -> V_20 , ! V_8 -> V_10 ) ;
}
static int F_17 ( struct V_22 * V_24 )
{
struct V_7 * V_8 ;
int V_18 ;
V_8 = F_16 ( F_18 ( V_24 ) ) ;
V_18 = F_10 ( V_8 ) ;
if ( V_18 )
return V_18 ;
F_14 ( V_8 -> V_20 , ! V_8 -> V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_7 * V_8 ;
int V_2 ;
V_2 = F_1 ( V_22 -> V_1 ) ;
if ( V_2 )
return V_2 ;
F_5 ( L_16 ) ;
V_8 = F_20 ( sizeof( * V_8 ) , V_25 ) ;
if ( ! V_8 )
return - V_26 ;
V_8 -> V_9 = V_22 ;
V_22 -> V_27 = V_8 ;
F_21 ( & V_22 -> V_24 , V_8 ) ;
V_2 = F_10 ( V_8 ) ;
if ( V_2 ) {
F_22 ( V_8 ) ;
return V_2 ;
}
V_8 -> V_20 = F_23 ( L_17 ,
& V_22 -> V_24 ,
V_28 ,
& V_29 ,
V_8 ) ;
if ( ! V_8 -> V_20 ) {
F_4 ( L_18 ) ;
F_22 ( V_8 ) ;
return - V_26 ;
}
F_14 ( V_8 -> V_20 , ! V_8 -> V_10 ) ;
V_2 = F_24 ( V_8 -> V_20 ) ;
if ( V_2 ) {
F_4 ( L_19 ) ;
F_25 ( V_8 -> V_20 ) ;
F_22 ( V_8 ) ;
}
return V_2 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_7 * V_8 = F_16 ( V_22 ) ;
if ( V_8 -> V_20 ) {
F_27 ( V_8 -> V_20 ) ;
F_25 ( V_8 -> V_20 ) ;
}
F_22 ( V_8 ) ;
return F_9 ( V_22 -> V_1 ) ;
}
