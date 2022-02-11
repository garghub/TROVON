static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static inline void F_3 ( struct V_2 * V_5 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
F_4 ( V_7 -> V_8 -> V_9 , V_6 ? 1 : 0 ) ;
}
static inline void F_5 ( struct V_2 * V_5 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
F_4 ( V_7 -> V_8 -> V_10 , V_6 ? 1 : 0 ) ;
}
static inline T_1 F_6 ( struct V_2 * V_5 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
return F_7 ( V_7 -> V_8 -> V_11 ) ? 1 : 0 ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
unsigned V_12 , T_1 V_13 , T_2 V_14 )
{
return F_9 ( V_3 , V_12 , 0 , 0 , V_13 , V_14 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
unsigned V_12 , T_1 V_13 , T_2 V_14 )
{
return F_11 ( V_3 , V_12 , 0 , 0 , V_13 , V_14 ) ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
unsigned V_12 , T_1 V_13 , T_2 V_14 )
{
return F_9 ( V_3 , V_12 , 1 , 0 , V_13 , V_14 ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
unsigned V_12 , T_1 V_13 , T_2 V_14 )
{
return F_11 ( V_3 , V_12 , 1 , 0 , V_13 , V_14 ) ;
}
static void F_14 ( struct V_2 * V_5 , int V_15 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
if ( V_7 -> V_8 && V_7 -> V_8 -> V_16 )
( V_7 -> V_8 -> V_16 ) ( V_7 -> V_8 , V_15 ) ;
}
static int F_15 ( struct V_17 * V_5 )
{
struct V_18 * V_8 ;
struct V_19 * V_4 ;
struct V_1 * V_20 ;
int V_21 ;
V_4 = F_16 ( & V_5 -> V_5 , sizeof( struct V_1 ) ) ;
if ( V_4 == NULL ) {
F_17 ( & V_5 -> V_5 , L_1 ) ;
V_21 = - V_22 ;
goto V_23;
}
V_20 = F_2 ( V_4 ) ;
F_18 ( V_5 , V_20 ) ;
V_8 = V_20 -> V_8 = V_5 -> V_5 . V_24 ;
V_20 -> V_25 . V_4 = F_19 ( V_4 ) ;
V_20 -> V_25 . V_4 -> V_26 = V_8 -> V_26 ;
V_20 -> V_25 . V_4 -> V_27 = V_8 -> V_27 ;
V_20 -> V_25 . V_28 = F_14 ;
V_20 -> V_25 . V_29 [ V_30 ] = F_8 ;
V_20 -> V_25 . V_29 [ V_31 ] = F_10 ;
V_20 -> V_25 . V_29 [ V_32 ] = F_12 ;
V_20 -> V_25 . V_29 [ V_33 ] = F_13 ;
F_4 ( V_8 -> V_9 , 0 ) ;
F_20 ( V_8 -> V_9 , V_34 ) ;
if ( V_8 -> V_10 < V_35 ) {
F_4 ( V_8 -> V_10 , 0 ) ;
F_20 ( V_8 -> V_10 , V_34 ) ;
}
if ( V_8 -> V_11 != V_36 && V_8 -> V_11 < V_35 )
F_20 ( V_8 -> V_11 , V_37 ) ;
V_21 = F_21 ( & V_20 -> V_25 ) ;
if ( V_21 )
goto V_38;
return 0 ;
V_38:
F_22 ( V_20 -> V_25 . V_4 ) ;
V_23:
return V_21 ;
}
static int F_23 ( struct V_17 * V_5 )
{
struct V_1 * V_20 = F_24 ( V_5 ) ;
F_25 ( & V_20 -> V_25 ) ;
F_22 ( V_20 -> V_25 . V_4 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_39 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_39 ) ;
}
