static void F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 > 0 )
F_2 ( V_2 -> V_4 [ -- V_2 -> V_3 ] ) ;
V_2 -> V_3 = V_5 ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
void * V_6 , T_2 V_7 )
{
T_3 * V_8 ;
T_2 V_9 ;
int V_10 ;
void * V_11 ;
if ( V_7 < sizeof( T_3 ) )
return 0 ;
V_8 = V_6 - V_2 -> V_12 ;
V_9 = F_4 ( V_8 -> V_13 , V_14 ) >> V_15 ;
if ( V_9 == 0 ) {
F_5 ( L_1 , V_16 ) ;
return - V_17 ;
}
V_10 = F_6 ( V_8 -> V_18 , V_8 -> V_19 ,
V_8 -> V_13 ,
& V_2 -> V_20 ) ;
if ( V_10 ) {
F_5 ( L_2 ,
V_16 ) ;
return V_10 ;
}
V_2 -> V_21 = V_8 -> V_13 ;
V_11 = F_7 ( V_2 -> V_4 ,
V_9 * sizeof( void * ) ,
V_22 | V_23 ) ;
if ( ! V_11 ) {
F_8 ( L_3 , V_16 ) ;
return - V_24 ;
}
V_2 -> V_4 = V_11 ;
V_2 -> V_25 = true ;
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
int V_10 ;
void * V_26 ;
V_26 = F_10 ( V_2 -> V_4 [ 0 ] ) ;
if ( ! V_26 ) {
F_8 ( L_4 , V_16 ) ;
return - V_27 ;
}
V_10 = F_11 ( V_26 , V_2 -> V_4 ) ;
F_12 ( V_2 -> V_4 [ 0 ] ) ;
if ( V_10 ) {
F_5 ( L_5 , V_16 ) ;
return V_10 ;
}
V_2 -> V_3 = V_5 ;
F_13 ( L_6 ,
V_16 , ! V_2 -> V_20 ? L_7 :
V_2 -> V_20 == 1 ? L_8 :
L_9 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_28 * V_28 , const char T_4 * V_29 ,
T_2 V_12 , T_5 * V_30 )
{
int V_10 = 0 ;
struct V_1 * V_2 = V_28 -> V_31 ;
struct V_32 * V_32 ;
void * V_6 = NULL ;
T_2 V_33 ;
if ( V_12 == 0 )
return 0 ;
if ( V_2 -> V_3 < 0 )
return - V_34 ;
if ( ! V_2 -> V_35 ) {
V_32 = F_15 ( V_22 ) ;
if ( ! V_32 ) {
F_8 ( L_10 , V_16 ) ;
V_10 = - V_24 ;
goto V_36;
}
V_2 -> V_4 [ V_2 -> V_3 ++ ] = V_32 ;
V_2 -> V_35 = V_14 ;
}
V_32 = V_2 -> V_4 [ V_2 -> V_3 - 1 ] ;
V_6 = F_10 ( V_32 ) ;
if ( ! V_6 ) {
F_8 ( L_4 , V_16 ) ;
V_10 = - V_27 ;
goto V_36;
}
V_6 += V_14 - V_2 -> V_35 ;
V_33 = F_16 ( T_2 , V_12 , V_2 -> V_35 ) ;
if ( F_17 ( V_6 , V_29 , V_33 ) ) {
F_8 ( L_11 , V_16 ) ;
V_10 = - V_27 ;
goto V_37;
}
V_2 -> V_35 -= V_33 ;
if ( ! V_2 -> V_25 ) {
V_10 = F_3 ( V_2 , V_6 ,
V_2 -> V_12 + V_33 ) ;
if ( V_10 )
goto V_37;
}
V_2 -> V_12 += V_33 ;
F_12 ( V_32 ) ;
if ( V_2 -> V_25 &&
V_2 -> V_12 >= V_2 -> V_21 ) {
if ( V_2 -> V_12 > V_2 -> V_21 ) {
F_5 ( L_12 ,
V_16 ) ;
V_10 = - V_17 ;
goto V_36;
}
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
goto V_36;
}
return V_33 ;
V_37:
F_12 ( V_32 ) ;
V_36:
F_1 ( V_2 ) ;
return V_10 ;
}
static int F_18 ( struct V_28 * V_28 , T_6 V_38 )
{
int V_10 = 0 ;
struct V_1 * V_2 = V_28 -> V_31 ;
if ( V_2 -> V_3 > 0 ) {
F_5 ( L_13 , V_16 ) ;
F_1 ( V_2 ) ;
V_10 = - V_39 ;
}
return V_10 ;
}
static int F_19 ( struct V_40 * V_40 , struct V_28 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_31 ;
F_20 ( V_2 -> V_4 ) ;
F_20 ( V_28 -> V_31 ) ;
V_28 -> V_31 = NULL ;
return 0 ;
}
static int F_21 ( struct V_40 * V_40 , struct V_28 * V_28 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_4 = F_22 ( sizeof( void * ) , V_22 ) ;
if ( ! V_2 -> V_4 ) {
F_20 ( V_2 ) ;
return - V_24 ;
}
V_28 -> V_31 = V_2 ;
return 0 ;
}
static int T_7 F_23 ( void )
{
int V_10 ;
if ( ! F_24 ( V_41 ) )
return - V_42 ;
V_10 = F_25 ( & V_43 ) ;
if ( V_10 )
F_5 ( L_14 ,
V_16 ) ;
return V_10 ;
}
static void T_8 F_26 ( void )
{
F_27 ( & V_43 ) ;
}
