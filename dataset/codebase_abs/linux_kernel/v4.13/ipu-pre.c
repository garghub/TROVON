int F_1 ( void )
{
return V_1 ;
}
struct V_2 *
F_2 ( struct V_3 * V_4 , const char * V_5 , int V_6 )
{
struct V_7 * V_8 = F_3 ( V_4 -> V_9 ,
V_5 , V_6 ) ;
struct V_2 * V_10 ;
F_4 ( & V_11 ) ;
F_5 (pre, &ipu_pre_list, list) {
if ( V_8 == V_10 -> V_4 -> V_9 ) {
F_6 ( & V_11 ) ;
F_7 ( V_4 , V_10 -> V_4 , V_12 ) ;
return V_10 ;
}
}
F_6 ( & V_11 ) ;
return NULL ;
}
int F_8 ( struct V_2 * V_10 )
{
T_1 V_13 ;
if ( V_10 -> V_14 )
return - V_15 ;
F_9 ( 0 , V_10 -> V_16 + V_17 ) ;
V_13 = V_18 |
V_19 |
V_20 |
V_21 | V_22 ;
F_9 ( V_13 , V_10 -> V_16 + V_17 ) ;
V_10 -> V_14 = true ;
return 0 ;
}
void F_10 ( struct V_2 * V_10 )
{
F_9 ( V_23 , V_10 -> V_16 + V_17 ) ;
V_10 -> V_14 = false ;
}
void F_11 ( struct V_2 * V_10 , unsigned int V_24 ,
unsigned int V_25 , unsigned int V_26 , T_1 V_27 ,
unsigned int V_28 )
{
const struct V_29 * V_30 = V_29 ( V_27 ) ;
T_1 V_31 = V_30 -> V_32 [ 0 ] >> 1 ;
T_1 V_13 ;
F_9 ( V_28 , V_10 -> V_16 + V_33 ) ;
F_9 ( V_28 , V_10 -> V_16 + V_34 ) ;
V_13 = F_12 ( 0 ) |
F_13 ( V_31 ) |
F_14 ( 4 ) |
V_35 |
V_36 ;
F_9 ( V_13 , V_10 -> V_16 + V_37 ) ;
V_13 = F_15 ( V_24 ) |
F_16 ( V_25 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_38 ) ;
V_13 = F_17 ( V_26 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_39 ) ;
V_13 = F_18 ( V_31 ) |
F_19 ( 4 ) |
V_40 ;
F_9 ( V_13 , V_10 -> V_16 + V_41 ) ;
V_13 = F_20 ( V_24 ) |
F_21 ( V_25 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_42 ) ;
V_13 = F_22 ( V_26 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_43 ) ;
F_9 ( V_10 -> V_44 , V_10 -> V_16 + V_45 ) ;
V_13 = F_23 ( V_10 -> V_16 + V_17 ) ;
V_13 |= V_46 | V_47 |
V_22 ;
F_9 ( V_13 , V_10 -> V_16 + V_17 ) ;
}
void F_24 ( struct V_2 * V_10 , unsigned int V_28 )
{
F_9 ( V_28 , V_10 -> V_16 + V_34 ) ;
F_9 ( V_22 , V_10 -> V_16 + V_48 ) ;
}
T_1 F_25 ( struct V_2 * V_10 )
{
return ( T_1 ) V_10 -> V_44 ;
}
static int F_26 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = & V_50 -> V_4 ;
struct V_51 * V_52 ;
struct V_2 * V_10 ;
V_10 = F_27 ( V_4 , sizeof( * V_10 ) , V_53 ) ;
if ( ! V_10 )
return - V_54 ;
V_52 = F_28 ( V_50 , V_55 , 0 ) ;
V_10 -> V_16 = F_29 ( & V_50 -> V_4 , V_52 ) ;
if ( F_30 ( V_10 -> V_16 ) )
return F_31 ( V_10 -> V_16 ) ;
V_10 -> V_56 = F_32 ( V_4 , L_1 ) ;
if ( F_30 ( V_10 -> V_56 ) )
return F_31 ( V_10 -> V_56 ) ;
V_10 -> V_57 = F_33 ( V_4 -> V_9 , L_2 , 0 ) ;
if ( ! V_10 -> V_57 )
return - V_58 ;
V_10 -> V_59 = F_34 ( V_10 -> V_57 , V_60 *
V_61 * 4 ,
& V_10 -> V_44 ) ;
if ( ! V_10 -> V_59 )
return - V_54 ;
F_35 ( V_10 -> V_56 ) ;
V_10 -> V_4 = V_4 ;
F_36 ( V_50 , V_10 ) ;
F_4 ( & V_11 ) ;
F_37 ( & V_10 -> V_62 , & V_63 ) ;
V_1 ++ ;
F_6 ( & V_11 ) ;
return 0 ;
}
static int F_38 ( struct V_49 * V_50 )
{
struct V_2 * V_10 = F_39 ( V_50 ) ;
F_4 ( & V_11 ) ;
F_40 ( & V_10 -> V_62 ) ;
V_1 -- ;
F_6 ( & V_11 ) ;
F_41 ( V_10 -> V_56 ) ;
if ( V_10 -> V_59 )
F_42 ( V_10 -> V_57 , ( unsigned long ) V_10 -> V_59 ,
V_60 * V_61 * 4 ) ;
return 0 ;
}
