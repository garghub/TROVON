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
F_9 ( V_2 -> V_17 , L_1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_18 )
{
V_2 -> V_9 = V_18 ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_19 = F_6 ( V_4 -> V_11 + V_12 ) ;
return F_12 ( V_19 & V_10 ) ;
}
static int
F_13 ( struct V_20 * V_21 , unsigned long V_22 , void * V_23 )
{
struct V_3 * V_4 = F_14 ( V_21 , struct V_3 ,
V_24 ) ;
T_2 V_25 ;
F_4 ( 10 | V_8 , V_4 -> V_11 + V_12 ) ;
V_25 = F_6 ( V_4 -> V_11 + V_13 ) ;
V_25 &= V_14 ;
V_25 |= V_8 | V_15 ;
F_4 ( V_25 , V_4 -> V_11 + V_13 ) ;
F_15 ( 1 ) ;
return 0 ;
}
static void F_16 ( void )
{
struct V_26 * V_27 =
F_17 ( NULL , NULL , L_2 ) ;
struct V_28 * V_29 = F_18 ( V_27 ) ;
struct V_3 * V_4 = F_19 ( V_29 ) ;
T_2 V_25 ;
V_25 = F_6 ( V_4 -> V_11 + V_30 ) ;
V_25 |= V_8 | V_31 ;
F_4 ( V_25 , V_4 -> V_11 + V_30 ) ;
F_13 ( & V_4 -> V_24 , V_32 , NULL ) ;
}
static int F_20 ( struct V_28 * V_29 )
{
struct V_33 * V_17 = & V_29 -> V_17 ;
struct V_26 * V_27 = V_17 -> V_34 ;
struct V_3 * V_4 ;
int V_35 ;
V_4 = F_21 ( V_17 , sizeof( struct V_3 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
F_22 ( V_29 , V_4 ) ;
F_23 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = F_24 ( V_27 , 0 ) ;
if ( ! V_4 -> V_11 ) {
F_25 ( V_17 , L_3 ) ;
return - V_38 ;
}
F_26 ( & V_39 , V_4 ) ;
F_27 ( & V_39 , V_40 , V_17 ) ;
F_28 ( & V_39 , V_41 ) ;
V_39 . V_42 = & V_29 -> V_17 ;
V_35 = F_29 ( & V_39 ) ;
if ( V_35 ) {
F_25 ( V_17 , L_4 ) ;
F_30 ( V_4 -> V_11 ) ;
return V_35 ;
}
V_4 -> V_24 . V_43 = F_13 ;
V_4 -> V_24 . V_44 = 128 ;
F_31 ( & V_4 -> V_24 ) ;
if ( V_45 == NULL )
V_45 = F_16 ;
F_9 ( V_17 , L_5 ) ;
return 0 ;
}
static int F_32 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_19 ( V_29 ) ;
F_33 ( & V_4 -> V_24 ) ;
if ( V_45 == F_16 )
V_45 = NULL ;
F_34 ( & V_39 ) ;
F_30 ( V_4 -> V_11 ) ;
return 0 ;
}
static void F_35 ( struct V_28 * V_29 )
{
F_8 ( & V_39 ) ;
}
