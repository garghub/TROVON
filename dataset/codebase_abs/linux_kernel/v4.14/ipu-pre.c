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
V_10 -> V_33 = V_25 - 2 ;
F_9 ( V_28 , V_10 -> V_16 + V_34 ) ;
F_9 ( V_28 , V_10 -> V_16 + V_35 ) ;
V_13 = F_12 ( 0 ) |
F_13 ( V_31 ) |
F_14 ( 4 ) |
V_36 |
V_37 ;
F_9 ( V_13 , V_10 -> V_16 + V_38 ) ;
V_13 = F_15 ( V_24 ) |
F_16 ( V_25 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_39 ) ;
V_13 = F_17 ( V_26 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_40 ) ;
V_13 = F_18 ( V_31 ) |
F_19 ( 4 ) |
V_41 ;
F_9 ( V_13 , V_10 -> V_16 + V_42 ) ;
V_13 = F_20 ( V_24 ) |
F_21 ( V_25 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_43 ) ;
V_13 = F_22 ( V_26 ) ;
F_9 ( V_13 , V_10 -> V_16 + V_44 ) ;
F_9 ( V_10 -> V_45 , V_10 -> V_16 + V_46 ) ;
V_13 = F_23 ( V_10 -> V_16 + V_17 ) ;
V_13 |= V_47 | V_48 |
V_22 ;
F_9 ( V_13 , V_10 -> V_16 + V_17 ) ;
}
void F_24 ( struct V_2 * V_10 , unsigned int V_28 )
{
unsigned long V_49 = V_50 + F_25 ( 5 ) ;
unsigned short V_51 ;
T_1 V_13 ;
F_9 ( V_28 , V_10 -> V_16 + V_35 ) ;
do {
if ( F_26 ( V_50 , V_49 ) ) {
F_27 ( V_10 -> V_4 , L_1 ) ;
return;
}
V_13 = F_23 ( V_10 -> V_16 + V_52 ) ;
V_51 =
( V_13 >> V_53 ) &
V_54 ;
} while ( V_51 == 0 || V_51 >= V_10 -> V_33 );
F_9 ( V_22 , V_10 -> V_16 + V_55 ) ;
}
T_1 F_28 ( struct V_2 * V_10 )
{
return ( T_1 ) V_10 -> V_45 ;
}
static int F_29 ( struct V_56 * V_57 )
{
struct V_3 * V_4 = & V_57 -> V_4 ;
struct V_58 * V_59 ;
struct V_2 * V_10 ;
V_10 = F_30 ( V_4 , sizeof( * V_10 ) , V_60 ) ;
if ( ! V_10 )
return - V_61 ;
V_59 = F_31 ( V_57 , V_62 , 0 ) ;
V_10 -> V_16 = F_32 ( & V_57 -> V_4 , V_59 ) ;
if ( F_33 ( V_10 -> V_16 ) )
return F_34 ( V_10 -> V_16 ) ;
V_10 -> V_63 = F_35 ( V_4 , L_2 ) ;
if ( F_33 ( V_10 -> V_63 ) )
return F_34 ( V_10 -> V_63 ) ;
V_10 -> V_64 = F_36 ( V_4 -> V_9 , L_3 , 0 ) ;
if ( ! V_10 -> V_64 )
return - V_65 ;
V_10 -> V_66 = F_37 ( V_10 -> V_64 , V_67 *
V_68 * 4 ,
& V_10 -> V_45 ) ;
if ( ! V_10 -> V_66 )
return - V_61 ;
F_38 ( V_10 -> V_63 ) ;
V_10 -> V_4 = V_4 ;
F_39 ( V_57 , V_10 ) ;
F_4 ( & V_11 ) ;
F_40 ( & V_10 -> V_69 , & V_70 ) ;
V_1 ++ ;
F_6 ( & V_11 ) ;
return 0 ;
}
static int F_41 ( struct V_56 * V_57 )
{
struct V_2 * V_10 = F_42 ( V_57 ) ;
F_4 ( & V_11 ) ;
F_43 ( & V_10 -> V_69 ) ;
V_1 -- ;
F_6 ( & V_11 ) ;
F_44 ( V_10 -> V_63 ) ;
if ( V_10 -> V_66 )
F_45 ( V_10 -> V_64 , ( unsigned long ) V_10 -> V_66 ,
V_67 * V_68 * 4 ) ;
return 0 ;
}
