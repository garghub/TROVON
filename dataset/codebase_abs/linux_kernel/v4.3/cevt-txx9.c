static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_3 ( & V_4 -> V_5 -> V_6 ) ;
}
static T_2 T_3 F_4 ( void )
{
return F_3 ( & V_3 . V_5 -> V_6 ) ;
}
void T_4 F_5 ( unsigned long V_7 ,
unsigned int V_8 )
{
struct V_9 T_5 * V_5 ;
F_6 ( & V_3 . V_2 , F_7 ( V_8 ) ) ;
V_5 = F_8 ( V_7 , sizeof( struct V_9 ) ) ;
F_9 ( V_10 , & V_5 -> V_11 ) ;
F_9 ( 0 , & V_5 -> V_12 ) ;
F_9 ( V_13 , & V_5 -> V_14 ) ;
F_9 ( V_15 , & V_5 -> V_16 ) ;
F_9 ( 1 << V_17 , & V_5 -> V_18 ) ;
F_9 ( V_10 | V_19 , & V_5 -> V_11 ) ;
V_3 . V_5 = V_5 ;
F_10 ( F_4 , V_17 ,
F_7 ( V_8 ) ) ;
}
static void F_11 ( struct V_9 T_5 * V_5 )
{
F_9 ( V_10 , & V_5 -> V_11 ) ;
F_9 ( 0 , & V_5 -> V_12 ) ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_2 ( V_21 , struct V_22 , V_24 ) ;
struct V_9 T_5 * V_5 = V_23 -> V_5 ;
F_11 ( V_5 ) ;
F_9 ( V_25 | V_15 , & V_5 -> V_16 ) ;
F_9 ( ( ( T_2 ) ( V_26 / V_27 ) * V_21 -> V_28 ) >> V_21 -> V_29 ,
& V_5 -> V_18 ) ;
F_9 ( V_10 | V_19 , & V_5 -> V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_2 ( V_21 , struct V_22 , V_24 ) ;
struct V_9 T_5 * V_5 = V_23 -> V_5 ;
F_11 ( V_5 ) ;
F_9 ( V_25 , & V_5 -> V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_2 ( V_21 , struct V_22 , V_24 ) ;
struct V_9 T_5 * V_5 = V_23 -> V_5 ;
F_11 ( V_5 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_2 ( V_21 , struct V_22 , V_24 ) ;
struct V_9 T_5 * V_5 = V_23 -> V_5 ;
F_11 ( V_5 ) ;
F_9 ( V_13 , & V_5 -> V_14 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
return 0 ;
}
static int F_16 ( unsigned long V_30 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_2 ( V_21 , struct V_22 , V_24 ) ;
struct V_9 T_5 * V_5 = V_23 -> V_5 ;
F_11 ( V_5 ) ;
F_9 ( V_30 , & V_5 -> V_18 ) ;
F_9 ( V_10 | V_19 , & V_5 -> V_11 ) ;
return 0 ;
}
static T_6 F_17 ( int V_31 , void * V_32 )
{
struct V_22 * V_23 = V_32 ;
struct V_20 * V_24 = & V_23 -> V_24 ;
struct V_9 T_5 * V_5 = V_23 -> V_5 ;
F_9 ( 0 , & V_5 -> V_12 ) ;
V_24 -> V_33 ( V_24 ) ;
return V_34 ;
}
void T_4 F_18 ( unsigned long V_7 , int V_31 ,
unsigned int V_8 )
{
struct V_20 * V_24 = & V_22 . V_24 ;
struct V_9 T_5 * V_5 ;
V_5 = F_8 ( V_7 , sizeof( struct V_9 ) ) ;
F_11 ( V_5 ) ;
F_9 ( V_13 , & V_5 -> V_14 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
V_22 . V_5 = V_5 ;
F_19 ( V_24 , F_7 ( V_8 ) ) ;
V_24 -> V_35 =
F_20 ( 0xffffffff >> ( 32 - V_36 ) , V_24 ) ;
V_24 -> V_37 = F_20 ( 0xf , V_24 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_38 = F_21 ( 0 ) ,
F_22 ( V_24 ) ;
F_23 ( V_31 , & V_39 ) ;
F_24 ( V_40 L_1 ,
V_7 , V_31 ) ;
}
void T_4 F_25 ( unsigned long V_7 )
{
struct V_9 T_5 * V_5 ;
V_5 = F_8 ( V_7 , sizeof( struct V_9 ) ) ;
F_9 ( V_41 | V_19 , & V_5 -> V_11 ) ;
F_9 ( V_41 , & V_5 -> V_11 ) ;
F_9 ( 0 , & V_5 -> V_12 ) ;
F_9 ( 0xffffffff , & V_5 -> V_18 ) ;
F_9 ( 0 , & V_5 -> V_16 ) ;
F_9 ( 0 , & V_5 -> V_14 ) ;
F_9 ( 0 , & V_5 -> V_42 ) ;
F_26 ( V_5 ) ;
}
