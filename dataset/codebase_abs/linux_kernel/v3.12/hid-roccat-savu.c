static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 , T_2 V_6 , T_3 V_7 ,
T_3 V_8 , T_4 V_9 )
{
struct V_10 * V_11 =
F_2 ( V_4 , struct V_10 , V_4 ) -> V_12 -> V_12 ;
struct V_13 * V_14 = F_3 ( F_4 ( V_11 ) ) ;
struct V_15 * V_16 = F_5 ( F_6 ( V_11 ) ) ;
int V_17 ;
if ( V_6 >= V_8 )
return 0 ;
if ( V_6 != 0 || V_7 != V_8 )
return - V_18 ;
F_7 ( & V_14 -> V_19 ) ;
V_17 = F_8 ( V_16 , V_9 , V_5 , V_8 ) ;
F_9 ( & V_14 -> V_19 ) ;
return V_17 ? V_17 : V_8 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void const * V_5 , T_2 V_6 , T_3 V_7 ,
T_3 V_8 , T_4 V_9 )
{
struct V_10 * V_11 =
F_2 ( V_4 , struct V_10 , V_4 ) -> V_12 -> V_12 ;
struct V_13 * V_14 = F_3 ( F_4 ( V_11 ) ) ;
struct V_15 * V_16 = F_5 ( F_6 ( V_11 ) ) ;
int V_17 ;
if ( V_6 != 0 || V_7 != V_8 )
return - V_18 ;
F_7 ( & V_14 -> V_19 ) ;
V_17 = F_11 ( V_16 , V_9 ,
( void * ) V_5 , V_8 ) ;
F_9 ( & V_14 -> V_19 ) ;
return V_17 ? V_17 : V_8 ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_13 * V_14 )
{
F_13 ( & V_14 -> V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_6 ( V_21 -> V_11 . V_12 ) ;
struct V_15 * V_16 = F_5 ( V_23 ) ;
struct V_13 * V_14 ;
int V_17 ;
if ( V_23 -> V_24 -> V_25 . V_26
!= V_27 ) {
F_15 ( V_21 , NULL ) ;
return 0 ;
}
V_14 = F_16 ( sizeof( * V_14 ) , V_28 ) ;
if ( ! V_14 ) {
F_17 ( V_21 , L_1 ) ;
return - V_29 ;
}
F_15 ( V_21 , V_14 ) ;
V_17 = F_12 ( V_16 , V_14 ) ;
if ( V_17 ) {
F_17 ( V_21 , L_2 ) ;
goto V_30;
}
V_17 = F_18 ( V_31 , V_21 ,
sizeof( struct V_32 ) ) ;
if ( V_17 < 0 ) {
F_17 ( V_21 , L_3 ) ;
} else {
V_14 -> V_33 = V_17 ;
V_14 -> V_34 = 1 ;
}
return 0 ;
V_30:
F_19 ( V_14 ) ;
return V_17 ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_6 ( V_21 -> V_11 . V_12 ) ;
struct V_13 * V_14 ;
if ( V_23 -> V_24 -> V_25 . V_26
!= V_27 )
return;
V_14 = F_3 ( V_21 ) ;
if ( V_14 -> V_34 )
F_21 ( V_14 -> V_33 ) ;
F_19 ( V_14 ) ;
}
static int F_22 ( struct V_20 * V_21 ,
const struct V_35 * V_36 )
{
int V_17 ;
V_17 = F_23 ( V_21 ) ;
if ( V_17 ) {
F_17 ( V_21 , L_4 ) ;
goto exit;
}
V_17 = F_24 ( V_21 , V_37 ) ;
if ( V_17 ) {
F_17 ( V_21 , L_5 ) ;
goto exit;
}
V_17 = F_14 ( V_21 ) ;
if ( V_17 ) {
F_17 ( V_21 , L_6 ) ;
goto V_38;
}
return 0 ;
V_38:
F_25 ( V_21 ) ;
exit:
return V_17 ;
}
static void F_26 ( struct V_20 * V_21 )
{
F_20 ( V_21 ) ;
F_25 ( V_21 ) ;
}
static void F_27 ( struct V_13 const * V_14 ,
T_5 const * V_39 )
{
struct V_32 V_40 ;
struct V_41 const * V_42 ;
if ( V_39 [ 0 ] != V_43 )
return;
V_42 = (struct V_41 const * ) V_39 ;
V_40 . type = V_42 -> type ;
V_40 . V_39 [ 0 ] = V_42 -> V_39 [ 0 ] ;
V_40 . V_39 [ 1 ] = V_42 -> V_39 [ 1 ] ;
F_28 ( V_14 -> V_33 ,
( V_44 const * ) & V_40 ) ;
}
static int F_29 ( struct V_20 * V_21 ,
struct V_45 * V_46 , T_5 * V_39 , int V_47 )
{
struct V_22 * V_23 = F_6 ( V_21 -> V_11 . V_12 ) ;
struct V_13 * V_14 = F_3 ( V_21 ) ;
if ( V_23 -> V_24 -> V_25 . V_26
!= V_27 )
return 0 ;
if ( V_14 == NULL )
return 0 ;
if ( V_14 -> V_34 )
F_27 ( V_14 , V_39 ) ;
return 0 ;
}
static int T_6 F_30 ( void )
{
int V_17 ;
V_31 = F_31 ( V_48 , L_7 ) ;
if ( F_32 ( V_31 ) )
return F_33 ( V_31 ) ;
V_31 -> V_49 = V_50 ;
V_17 = F_34 ( & V_51 ) ;
if ( V_17 )
F_35 ( V_31 ) ;
return V_17 ;
}
static void T_7 F_36 ( void )
{
F_37 ( & V_51 ) ;
F_35 ( V_31 ) ;
}
