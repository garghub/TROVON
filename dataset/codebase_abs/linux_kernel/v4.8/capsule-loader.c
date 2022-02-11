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
V_26 = F_10 ( V_2 -> V_4 , V_2 -> V_3 ,
V_27 , V_28 ) ;
if ( ! V_26 ) {
F_8 ( L_4 , V_16 ) ;
return - V_29 ;
}
V_10 = F_11 ( V_26 , V_2 -> V_4 ) ;
F_12 ( V_26 ) ;
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
static T_1 F_14 ( struct V_30 * V_30 , const char T_4 * V_31 ,
T_2 V_12 , T_5 * V_32 )
{
int V_10 = 0 ;
struct V_1 * V_2 = V_30 -> V_33 ;
struct V_34 * V_34 ;
void * V_6 = NULL ;
T_2 V_35 ;
if ( V_12 == 0 )
return 0 ;
if ( V_2 -> V_3 < 0 )
return - V_36 ;
if ( ! V_2 -> V_37 ) {
V_34 = F_15 ( V_22 ) ;
if ( ! V_34 ) {
F_8 ( L_10 , V_16 ) ;
V_10 = - V_24 ;
goto V_38;
}
V_2 -> V_4 [ V_2 -> V_3 ++ ] = V_34 ;
V_2 -> V_37 = V_14 ;
}
V_34 = V_2 -> V_4 [ V_2 -> V_3 - 1 ] ;
V_6 = F_16 ( V_34 ) ;
if ( ! V_6 ) {
F_8 ( L_11 , V_16 ) ;
V_10 = - V_29 ;
goto V_38;
}
V_6 += V_14 - V_2 -> V_37 ;
V_35 = F_17 ( T_2 , V_12 , V_2 -> V_37 ) ;
if ( F_18 ( V_6 , V_31 , V_35 ) ) {
F_8 ( L_12 , V_16 ) ;
V_10 = - V_29 ;
goto V_39;
}
V_2 -> V_37 -= V_35 ;
if ( ! V_2 -> V_25 ) {
V_10 = F_3 ( V_2 , V_6 ,
V_2 -> V_12 + V_35 ) ;
if ( V_10 )
goto V_39;
}
V_2 -> V_12 += V_35 ;
F_19 ( V_34 ) ;
if ( V_2 -> V_25 &&
V_2 -> V_12 >= V_2 -> V_21 ) {
if ( V_2 -> V_12 > V_2 -> V_21 ) {
F_5 ( L_13 ,
V_16 ) ;
V_10 = - V_17 ;
goto V_38;
}
V_10 = F_9 ( V_2 ) ;
if ( V_10 )
goto V_38;
}
return V_35 ;
V_39:
F_19 ( V_34 ) ;
V_38:
F_1 ( V_2 ) ;
return V_10 ;
}
static int F_20 ( struct V_30 * V_30 , T_6 V_40 )
{
int V_10 = 0 ;
struct V_1 * V_2 = V_30 -> V_33 ;
if ( V_2 -> V_3 > 0 ) {
F_5 ( L_14 , V_16 ) ;
F_1 ( V_2 ) ;
V_10 = - V_41 ;
}
return V_10 ;
}
static int F_21 ( struct V_42 * V_42 , struct V_30 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_33 ;
F_22 ( V_2 -> V_4 ) ;
F_22 ( V_30 -> V_33 ) ;
V_30 -> V_33 = NULL ;
return 0 ;
}
static int F_23 ( struct V_42 * V_42 , struct V_30 * V_30 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_4 = F_24 ( sizeof( void * ) , V_22 ) ;
if ( ! V_2 -> V_4 ) {
F_22 ( V_2 ) ;
return - V_24 ;
}
V_30 -> V_33 = V_2 ;
return 0 ;
}
static int T_7 F_25 ( void )
{
int V_10 ;
if ( ! F_26 ( V_43 ) )
return - V_44 ;
V_10 = F_27 ( & V_45 ) ;
if ( V_10 )
F_5 ( L_15 ,
V_16 ) ;
return V_10 ;
}
static void T_8 F_28 ( void )
{
F_29 ( & V_45 ) ;
}
