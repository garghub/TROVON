static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 * V_10 ;
int V_11 ;
if ( V_4 -> V_12 -> V_13 . V_14
!= V_15 ) {
F_4 ( V_2 , NULL ) ;
return 0 ;
}
V_10 = F_5 ( sizeof( * V_10 ) , V_16 ) ;
if ( ! V_10 ) {
F_6 ( V_2 , L_1 ) ;
return - V_17 ;
}
F_4 ( V_2 , V_10 ) ;
V_11 = F_7 ( V_8 , V_10 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_2 ) ;
goto V_18;
}
V_11 = F_8 ( V_19 , V_2 ,
sizeof( struct V_20 ) ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 , L_3 ) ;
} else {
V_10 -> V_21 = V_11 ;
V_10 -> V_22 = 1 ;
}
return 0 ;
V_18:
F_9 ( V_10 ) ;
return V_11 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_9 * V_10 ;
if ( V_4 -> V_12 -> V_13 . V_14
!= V_15 )
return;
V_10 = F_11 ( V_2 ) ;
if ( V_10 -> V_22 )
F_12 ( V_10 -> V_21 ) ;
F_9 ( V_10 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
int V_11 ;
V_11 = F_14 ( V_2 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_4 ) ;
goto exit;
}
V_11 = F_15 ( V_2 , V_25 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_5 ) ;
goto exit;
}
V_11 = F_1 ( V_2 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_6 ) ;
goto V_26;
}
return 0 ;
V_26:
F_16 ( V_2 ) ;
exit:
return V_11 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static void F_18 ( struct V_9 const * V_10 ,
T_1 const * V_27 )
{
struct V_20 V_28 ;
struct V_29 const * V_30 ;
if ( V_27 [ 0 ] != V_31 )
return;
V_30 = (struct V_29 const * ) V_27 ;
V_28 . type = V_30 -> type ;
V_28 . V_27 [ 0 ] = V_30 -> V_27 [ 0 ] ;
V_28 . V_27 [ 1 ] = V_30 -> V_27 [ 1 ] ;
F_19 ( V_10 -> V_21 ,
( V_32 const * ) & V_28 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 * V_27 , int V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_9 * V_10 = F_11 ( V_2 ) ;
if ( V_4 -> V_12 -> V_13 . V_14
!= V_15 )
return 0 ;
if ( V_10 == NULL )
return 0 ;
if ( V_10 -> V_22 )
F_18 ( V_10 , V_27 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
int V_11 ;
V_19 = F_22 ( V_36 , L_7 ) ;
if ( F_23 ( V_19 ) )
return F_24 ( V_19 ) ;
V_19 -> V_37 = V_38 ;
V_11 = F_25 ( & V_39 ) ;
if ( V_11 )
F_26 ( V_19 ) ;
return V_11 ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_39 ) ;
F_26 ( V_19 ) ;
}
