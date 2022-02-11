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
static int F_9 ( struct V_1 * V_2 , unsigned int V_17 )
{
V_2 -> V_9 = V_17 ;
return 0 ;
}
static unsigned int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_18 = F_6 ( V_4 -> V_11 + V_12 ) ;
return F_11 ( V_18 & V_10 ) ;
}
static int
F_12 ( struct V_19 * V_20 , unsigned long V_21 , void * V_22 )
{
struct V_3 * V_4 = F_13 ( V_20 , struct V_3 ,
V_23 ) ;
T_2 V_24 ;
F_4 ( 10 | V_8 , V_4 -> V_11 + V_12 ) ;
V_24 = F_6 ( V_4 -> V_11 + V_13 ) ;
V_24 &= V_14 ;
V_24 |= V_8 | V_15 ;
F_4 ( V_24 , V_4 -> V_11 + V_13 ) ;
F_14 ( 1 ) ;
return 0 ;
}
static void F_15 ( void )
{
struct V_25 * V_26 =
F_16 ( NULL , NULL , L_1 ) ;
struct V_27 * V_28 = F_17 ( V_26 ) ;
struct V_3 * V_4 = F_18 ( V_28 ) ;
T_2 V_24 ;
V_24 = F_6 ( V_4 -> V_11 + V_29 ) ;
V_24 |= V_8 | V_30 ;
F_4 ( V_24 , V_4 -> V_11 + V_29 ) ;
F_12 ( & V_4 -> V_23 , V_31 , NULL ) ;
}
static int F_19 ( struct V_27 * V_28 )
{
struct V_32 * V_33 = & V_28 -> V_33 ;
struct V_25 * V_26 = V_33 -> V_34 ;
struct V_3 * V_4 ;
int V_35 ;
V_4 = F_20 ( V_33 , sizeof( struct V_3 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
F_21 ( V_28 , V_4 ) ;
F_22 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = F_23 ( V_26 , 0 ) ;
if ( ! V_4 -> V_11 ) {
F_24 ( V_33 , L_2 ) ;
return - V_38 ;
}
F_25 ( & V_39 , V_4 ) ;
F_26 ( & V_39 , V_40 , V_33 ) ;
F_27 ( & V_39 , V_41 ) ;
V_39 . V_42 = & V_28 -> V_33 ;
V_35 = F_28 ( & V_39 ) ;
if ( V_35 ) {
F_24 ( V_33 , L_3 ) ;
F_29 ( V_4 -> V_11 ) ;
return V_35 ;
}
V_4 -> V_23 . V_43 = F_12 ;
V_4 -> V_23 . V_44 = 128 ;
F_30 ( & V_4 -> V_23 ) ;
if ( V_45 == NULL )
V_45 = F_15 ;
F_31 ( V_33 , L_4 ) ;
return 0 ;
}
static int F_32 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_18 ( V_28 ) ;
F_33 ( & V_4 -> V_23 ) ;
if ( V_45 == F_15 )
V_45 = NULL ;
F_34 ( & V_39 ) ;
F_29 ( V_4 -> V_11 ) ;
return 0 ;
}
static void F_35 ( struct V_27 * V_28 )
{
F_8 ( & V_39 ) ;
}
