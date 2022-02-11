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
static int
F_13 ( struct V_18 * V_19 , unsigned long V_20 , void * V_21 )
{
struct V_1 * V_2 = F_14 ( V_19 , struct V_1 ,
V_22 ) ;
T_2 V_23 ;
F_6 ( 10 | V_11 , V_2 -> V_4 + V_14 ) ;
V_23 = F_8 ( V_2 -> V_4 + V_5 ) ;
V_23 &= V_15 ;
V_23 |= V_11 | V_6 ;
F_6 ( V_23 , V_2 -> V_4 + V_5 ) ;
F_15 ( 1 ) ;
return 0 ;
}
static void F_16 ( void )
{
struct V_24 * V_25 =
F_17 ( NULL , NULL , L_1 ) ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
struct V_1 * V_2 = F_19 ( V_27 ) ;
T_2 V_23 ;
V_23 = F_8 ( V_2 -> V_4 + V_28 ) ;
V_23 |= V_11 | V_29 ;
F_6 ( V_23 , V_2 -> V_4 + V_28 ) ;
F_13 ( & V_2 -> V_22 , V_30 , NULL ) ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = & V_27 -> V_32 ;
struct V_24 * V_25 = V_32 -> V_33 ;
struct V_1 * V_2 ;
int V_34 ;
V_2 = F_21 ( V_32 , sizeof( struct V_1 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_22 ( V_27 , V_2 ) ;
F_23 ( & V_2 -> V_10 ) ;
V_2 -> V_4 = F_24 ( V_25 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_25 ( V_32 , L_2 ) ;
return - V_37 ;
}
F_26 ( & V_38 , V_2 ) ;
F_27 ( & V_38 , V_39 , V_32 ) ;
F_28 ( & V_38 , V_40 ) ;
V_38 . V_41 = & V_27 -> V_32 ;
if ( F_1 ( V_2 ) ) {
F_29 ( V_42 , & V_38 . V_43 ) ;
}
V_34 = F_30 ( & V_38 ) ;
if ( V_34 ) {
F_25 ( V_32 , L_3 ) ;
F_31 ( V_2 -> V_4 ) ;
return V_34 ;
}
V_2 -> V_22 . V_44 = F_13 ;
V_2 -> V_22 . V_45 = 128 ;
F_32 ( & V_2 -> V_22 ) ;
if ( V_46 == NULL )
V_46 = F_16 ;
F_33 ( V_32 , L_4 ) ;
return 0 ;
}
static int F_34 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
F_35 ( & V_2 -> V_22 ) ;
if ( V_46 == F_16 )
V_46 = NULL ;
F_36 ( & V_38 ) ;
F_31 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_37 ( struct V_26 * V_27 )
{
F_10 ( & V_38 ) ;
}
