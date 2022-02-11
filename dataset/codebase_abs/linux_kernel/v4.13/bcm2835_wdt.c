static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
return ! ! ( V_3 & V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_3 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
F_6 ( V_11 | ( F_7 ( V_8 -> V_12 ) &
V_13 ) , V_2 -> V_4 + V_14 ) ;
V_3 = F_8 ( V_2 -> V_4 + V_5 ) ;
F_6 ( V_11 | ( V_3 & V_15 ) |
V_6 , V_2 -> V_4 + V_5 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_6 ( V_11 | V_16 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static unsigned int F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_17 = F_8 ( V_2 -> V_4 + V_14 ) ;
return F_12 ( V_17 & V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_18 ;
F_6 ( 10 | V_11 , V_2 -> V_4 + V_14 ) ;
V_18 = F_8 ( V_2 -> V_4 + V_5 ) ;
V_18 &= V_15 ;
V_18 |= V_11 | V_6 ;
F_6 ( V_18 , V_2 -> V_4 + V_5 ) ;
F_14 ( 1 ) ;
}
static int F_15 ( struct V_7 * V_8 ,
unsigned long V_19 , void * V_20 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static void F_16 ( void )
{
struct V_21 * V_22 =
F_17 ( NULL , NULL , L_1 ) ;
struct V_23 * V_24 = F_18 ( V_22 ) ;
struct V_1 * V_2 = F_19 ( V_24 ) ;
T_2 V_18 ;
V_18 = F_8 ( V_2 -> V_4 + V_25 ) ;
V_18 |= V_11 | V_26 ;
F_6 ( V_18 , V_2 -> V_4 + V_25 ) ;
F_13 ( V_2 ) ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 = & V_24 -> V_30 ;
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_21 ( V_30 , sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
F_22 ( V_24 , V_2 ) ;
F_23 ( & V_2 -> V_10 ) ;
V_28 = F_24 ( V_24 , V_34 , 0 ) ;
V_2 -> V_4 = F_25 ( V_30 , V_28 ) ;
if ( F_26 ( V_2 -> V_4 ) )
return F_27 ( V_2 -> V_4 ) ;
F_28 ( & V_35 , V_2 ) ;
F_29 ( & V_35 , V_36 , V_30 ) ;
F_30 ( & V_35 , V_37 ) ;
V_35 . V_38 = V_30 ;
if ( F_1 ( V_2 ) ) {
F_31 ( V_39 , & V_35 . V_40 ) ;
}
F_32 ( & V_35 , 128 ) ;
F_33 ( & V_35 ) ;
V_31 = F_34 ( V_30 , & V_35 ) ;
if ( V_31 ) {
F_35 ( V_30 , L_2 ) ;
return V_31 ;
}
if ( V_41 == NULL )
V_41 = F_16 ;
F_36 ( V_30 , L_3 ) ;
return 0 ;
}
static int F_37 ( struct V_23 * V_24 )
{
if ( V_41 == F_16 )
V_41 = NULL ;
return 0 ;
}
