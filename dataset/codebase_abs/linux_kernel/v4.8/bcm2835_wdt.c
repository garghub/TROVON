static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned long V_6 ;
F_3 ( & V_4 -> V_7 , V_6 ) ;
F_4 ( V_8 | ( F_5 ( V_2 -> V_9 ) &
V_10 ) , V_4 -> V_11 + V_12 ) ;
V_5 = F_6 ( V_4 -> V_11 + V_13 ) ;
F_4 ( V_8 | ( V_5 & V_14 ) |
V_15 , V_4 -> V_11 + V_13 ) ;
F_7 ( & V_4 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_4 ( V_8 | V_16 , V_4 -> V_11 + V_13 ) ;
return 0 ;
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_17 = F_6 ( V_4 -> V_11 + V_12 ) ;
return F_10 ( V_17 & V_10 ) ;
}
static int
F_11 ( struct V_18 * V_19 , unsigned long V_20 , void * V_21 )
{
struct V_3 * V_4 = F_12 ( V_19 , struct V_3 ,
V_22 ) ;
T_2 V_23 ;
F_4 ( 10 | V_8 , V_4 -> V_11 + V_12 ) ;
V_23 = F_6 ( V_4 -> V_11 + V_13 ) ;
V_23 &= V_14 ;
V_23 |= V_8 | V_15 ;
F_4 ( V_23 , V_4 -> V_11 + V_13 ) ;
F_13 ( 1 ) ;
return 0 ;
}
static void F_14 ( void )
{
struct V_24 * V_25 =
F_15 ( NULL , NULL , L_1 ) ;
struct V_26 * V_27 = F_16 ( V_25 ) ;
struct V_3 * V_4 = F_17 ( V_27 ) ;
T_2 V_23 ;
V_23 = F_6 ( V_4 -> V_11 + V_28 ) ;
V_23 |= V_8 | V_29 ;
F_4 ( V_23 , V_4 -> V_11 + V_28 ) ;
F_11 ( & V_4 -> V_22 , V_30 , NULL ) ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = & V_27 -> V_32 ;
struct V_24 * V_25 = V_32 -> V_33 ;
struct V_3 * V_4 ;
int V_34 ;
V_4 = F_19 ( V_32 , sizeof( struct V_3 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
F_20 ( V_27 , V_4 ) ;
F_21 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = F_22 ( V_25 , 0 ) ;
if ( ! V_4 -> V_11 ) {
F_23 ( V_32 , L_2 ) ;
return - V_37 ;
}
F_24 ( & V_38 , V_4 ) ;
F_25 ( & V_38 , V_39 , V_32 ) ;
F_26 ( & V_38 , V_40 ) ;
V_38 . V_41 = & V_27 -> V_32 ;
V_34 = F_27 ( & V_38 ) ;
if ( V_34 ) {
F_23 ( V_32 , L_3 ) ;
F_28 ( V_4 -> V_11 ) ;
return V_34 ;
}
V_4 -> V_22 . V_42 = F_11 ;
V_4 -> V_22 . V_43 = 128 ;
F_29 ( & V_4 -> V_22 ) ;
if ( V_44 == NULL )
V_44 = F_14 ;
F_30 ( V_32 , L_4 ) ;
return 0 ;
}
static int F_31 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_17 ( V_27 ) ;
F_32 ( & V_4 -> V_22 ) ;
if ( V_44 == F_14 )
V_44 = NULL ;
F_33 ( & V_38 ) ;
F_28 ( V_4 -> V_11 ) ;
return 0 ;
}
static void F_34 ( struct V_26 * V_27 )
{
F_8 ( & V_38 ) ;
}
