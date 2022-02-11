static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_2 * V_3 , int V_5 , int V_6 )
{
V_5 &= V_7 ;
F_4 ( V_3 , V_8 , 0x00 ) ;
F_4 ( V_3 , V_9 , 0x01 ) ;
F_4 ( V_3 , V_10 , V_5 | V_6 |
V_11 | V_12 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_14 ;
V_14 = V_13 -> V_15 ;
if ( ! V_13 -> V_16 [ V_14 ] )
return;
F_3 ( V_3 , V_13 -> V_16 [ V_14 ] -> V_17 , V_13 -> V_16 [ V_14 ] -> V_6 ) ;
}
static int
F_6 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_14 , V_20 ;
F_7 ( & V_13 -> V_21 ) ;
V_14 = V_13 -> V_15 ;
V_20 = V_13 -> V_22 ;
if ( V_13 -> V_16 [ V_20 ] ) {
F_8 ( & V_13 -> V_21 ) ;
F_9 ( V_3 -> V_23 , L_1 ) ;
return - V_24 ;
}
V_13 -> V_16 [ V_20 ] = V_19 ;
if ( V_14 == V_20 )
F_5 ( V_3 ) ;
V_13 -> V_22 = ( V_20 + 1 ) & ( V_25 - 1 ) ;
F_8 ( & V_13 -> V_21 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 , void * V_26 ,
int V_27 )
{
struct V_28 * V_19 = V_26 ;
V_19 -> V_27 = V_27 ;
F_11 ( & V_19 -> V_29 ) ;
}
int F_12 ( struct V_2 * V_3 , int V_17 , int V_6 )
{
struct V_28 V_19 ;
int V_30 ;
F_13 ( & V_19 . V_29 ) ;
V_30 = F_14 ( V_3 , V_17 , V_6 ,
F_10 , & V_19 ) ;
if ( V_30 )
return V_30 ;
F_15 ( & V_19 . V_29 ) ;
return V_19 . V_27 ;
}
int F_14 ( struct V_2 * V_3 , int V_17 , int V_6 ,
void (* F_16)( struct V_2 * , void * , int ) ,
void * V_31 )
{
struct V_18 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_32 ) ;
if ( ! V_19 )
return - V_33 ;
V_19 -> V_17 = V_17 ;
V_19 -> V_6 = V_6 ;
V_19 -> F_16 = F_16 ;
V_19 -> V_31 = V_31 ;
return F_6 ( V_3 , V_19 ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
T_1 V_34 , V_35 ;
T_2 V_27 ;
V_34 = F_19 ( V_3 , V_36 ) ;
V_35 = F_19 ( V_3 , V_37 ) ;
V_27 = ( V_34 << 2 ) | ( V_35 & V_38 ) ;
F_20 ( V_3 -> V_23 , L_2 , V_27 ) ;
return V_27 ;
}
static void F_21 ( int V_39 , void * V_40 )
{
struct V_1 * V_13 = V_40 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_18 * V_19 ;
int V_14 , V_41 ;
F_7 ( & V_13 -> V_21 ) ;
V_14 = V_13 -> V_15 ;
V_19 = V_13 -> V_16 [ V_14 ] ;
if ( F_22 ( ! V_19 ) ) {
F_9 ( V_3 -> V_23 , L_3 ) ;
F_8 ( & V_13 -> V_21 ) ;
return;
}
V_13 -> V_16 [ V_14 ] = NULL ;
V_13 -> V_15 = ( V_14 + 1 ) &
( V_25 - 1 ) ;
V_41 = F_18 ( V_3 ) ;
F_5 ( V_3 ) ;
F_8 ( & V_13 -> V_21 ) ;
V_19 -> F_16 ( V_3 , V_19 -> V_31 , V_41 ) ;
F_23 ( V_19 ) ;
}
static int T_3 F_24 ( struct V_42 * V_43 )
{
struct V_1 * V_13 ;
V_13 = F_25 ( sizeof( * V_13 ) , V_32 ) ;
if ( ! V_13 )
return - V_33 ;
V_13 -> V_3 = F_26 ( V_43 -> V_23 . V_44 ) ;
F_27 ( V_43 , V_13 ) ;
F_28 ( V_13 -> V_3 , V_45 ,
F_21 , V_13 ) ;
F_29 ( & V_13 -> V_21 ) ;
return 0 ;
}
static int T_4 F_30 ( struct V_42 * V_43 )
{
struct V_1 * V_13 = F_2 ( V_43 ) ;
int V_46 , V_14 ;
F_31 ( V_13 -> V_3 , V_45 ) ;
F_7 ( & V_13 -> V_21 ) ;
V_14 = V_13 -> V_15 ;
if ( F_22 ( V_13 -> V_16 [ V_14 ] ) )
F_9 ( V_13 -> V_3 -> V_23 ,
L_4 ) ;
for ( V_46 = 0 ; V_46 < V_25 ; V_46 ++ )
F_23 ( V_13 -> V_16 [ V_46 ] ) ;
F_8 ( & V_13 -> V_21 ) ;
F_23 ( V_13 ) ;
return 0 ;
}
