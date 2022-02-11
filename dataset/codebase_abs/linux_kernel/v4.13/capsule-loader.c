static void F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 > 0 )
F_2 ( F_3 ( V_2 -> V_4 [ -- V_2 -> V_3 ] ) ) ;
V_2 -> V_3 = V_5 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_7 ;
void * V_8 ;
V_6 = F_5 ( V_2 -> V_9 , V_10 ) / V_10 ;
if ( V_6 == 0 ) {
F_6 ( L_1 ) ;
return - V_11 ;
}
V_7 = F_7 ( V_2 -> V_12 . V_13 ,
V_2 -> V_12 . V_14 ,
V_2 -> V_12 . V_15 ,
& V_2 -> V_16 ) ;
if ( V_7 ) {
F_6 ( L_2 ) ;
return V_7 ;
}
V_8 = F_8 ( V_2 -> V_4 ,
V_6 * sizeof( void * ) ,
V_17 | V_18 ) ;
if ( ! V_8 )
return - V_19 ;
V_2 -> V_4 = V_8 ;
return 0 ;
}
int __weak F_9 ( struct V_1 * V_2 , void * V_20 ,
T_1 V_21 )
{
if ( V_21 < sizeof( V_22 ) )
return 0 ;
memcpy ( & V_2 -> V_12 , V_20 , sizeof( V_2 -> V_12 ) ) ;
V_2 -> V_9 = V_2 -> V_12 . V_15 ;
return F_4 ( V_2 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_11 ( & V_2 -> V_12 , V_2 -> V_4 ) ;
if ( V_7 ) {
F_6 ( L_3 ) ;
return V_7 ;
}
V_2 -> V_3 = V_5 ;
F_12 ( L_4 ,
! V_2 -> V_16 ? L_5 :
V_2 -> V_16 == 1 ? L_6 :
L_7 ) ;
return 0 ;
}
static T_2 F_13 ( struct V_23 * V_23 , const char T_3 * V_24 ,
T_1 V_25 , T_4 * V_26 )
{
int V_7 = 0 ;
struct V_1 * V_2 = V_23 -> V_27 ;
struct V_28 * V_28 ;
void * V_20 = NULL ;
T_1 V_29 ;
if ( V_25 == 0 )
return 0 ;
if ( V_2 -> V_3 < 0 )
return - V_30 ;
if ( ! V_2 -> V_31 ) {
V_28 = F_14 ( V_17 ) ;
if ( ! V_28 ) {
V_7 = - V_19 ;
goto V_32;
}
V_2 -> V_4 [ V_2 -> V_3 ++ ] = F_15 ( V_28 ) ;
V_2 -> V_31 = V_10 ;
} else {
V_28 = F_3 ( V_2 -> V_4 [ V_2 -> V_3 - 1 ] ) ;
}
V_20 = F_16 ( V_28 ) ;
V_20 += V_10 - V_2 -> V_31 ;
V_29 = F_17 ( T_1 , V_25 , V_2 -> V_31 ) ;
if ( F_18 ( V_20 , V_24 , V_29 ) ) {
V_7 = - V_33 ;
goto V_34;
}
V_2 -> V_31 -= V_29 ;
if ( V_2 -> V_12 . V_35 == 0 ) {
V_7 = F_9 ( V_2 , V_20 - V_2 -> V_25 ,
V_2 -> V_25 + V_29 ) ;
if ( V_7 )
goto V_34;
}
V_2 -> V_25 += V_29 ;
F_19 ( V_28 ) ;
if ( V_2 -> V_12 . V_35 > 0 &&
V_2 -> V_25 >= V_2 -> V_9 ) {
if ( V_2 -> V_25 > V_2 -> V_9 ) {
F_6 ( L_8 ) ;
V_7 = - V_11 ;
goto V_32;
}
V_7 = F_10 ( V_2 ) ;
if ( V_7 )
goto V_32;
}
return V_29 ;
V_34:
F_19 ( V_28 ) ;
V_32:
F_1 ( V_2 ) ;
return V_7 ;
}
static int F_20 ( struct V_23 * V_23 , T_5 V_36 )
{
int V_7 = 0 ;
struct V_1 * V_2 = V_23 -> V_27 ;
if ( V_2 -> V_3 > 0 ) {
F_6 ( L_9 ) ;
F_1 ( V_2 ) ;
V_7 = - V_37 ;
}
return V_7 ;
}
static int F_21 ( struct V_38 * V_38 , struct V_23 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_27 ;
F_22 ( V_2 -> V_4 ) ;
F_22 ( V_23 -> V_27 ) ;
V_23 -> V_27 = NULL ;
return 0 ;
}
static int F_23 ( struct V_38 * V_38 , struct V_23 * V_23 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_4 = F_24 ( sizeof( void * ) , V_17 ) ;
if ( ! V_2 -> V_4 ) {
F_22 ( V_2 ) ;
return - V_19 ;
}
V_23 -> V_27 = V_2 ;
return 0 ;
}
static int T_6 F_25 ( void )
{
int V_7 ;
if ( ! F_26 ( V_39 ) )
return - V_40 ;
V_7 = F_27 ( & V_41 ) ;
if ( V_7 )
F_6 ( L_10 ) ;
return V_7 ;
}
static void T_7 F_28 ( void )
{
F_29 ( & V_41 ) ;
}
