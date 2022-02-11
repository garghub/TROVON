static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_2 V_5 , void * V_6 , T_3 V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_4 != 0 )
return - V_10 ;
V_5 += V_9 -> V_5 + ( V_3 * V_11 ) ;
return F_3 ( V_9 -> V_12 -> V_13 , V_5 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , T_2 V_5 , const void * V_6 , T_3 V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_4 != 0 )
return - V_10 ;
V_5 += V_9 -> V_5 + ( V_3 * V_11 ) ;
return F_5 ( V_9 -> V_12 -> V_13 , V_5 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_5 , V_14 ;
V_5 = 0x4 ;
V_14 = F_7 ( 0xc0de0000 ) ;
return F_4 ( V_2 , V_3 , 0 , V_5 , & V_14 , sizeof( V_14 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_15 , V_16 ;
T_4 V_17 ;
int V_18 ;
V_15 = V_3 / 32 ;
V_16 = V_3 % 32 ;
V_17 = F_7 ( 0x80000000 >> V_16 ) ;
V_18 = F_9 ( V_9 -> V_12 , V_19 + ( 4 * V_15 ) , & V_17 , 4 ) ;
F_10 ( V_20 ) ;
F_11 ( V_9 -> V_12 , V_21 + ( 4 * V_15 ) , & V_17 , 4 ) ;
return V_18 ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = F_2 ( F_13 ( V_23 ) ) ;
F_14 ( V_9 ) ;
}
static inline T_5 F_15 ( T_5 V_24 )
{
return ( V_24 & V_25 ) << V_26 ;
}
static inline T_5 F_16 ( T_5 V_24 )
{
return ( V_24 & V_27 ) << V_28 ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_29 * V_23 = V_9 -> V_12 ;
T_4 V_17 ;
int V_18 ;
V_17 = F_7 ( V_30 | V_31
| V_32 | V_33 ) ;
V_18 = F_9 ( V_23 , V_34 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( V_30 | V_31
| V_32 | V_33 ) ;
V_18 = F_9 ( V_23 , V_34 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( V_35 | V_36 ) ;
V_18 = F_9 ( V_23 , V_37 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( V_38 | V_39 | V_40
| F_15 ( 1 ) | F_16 ( 1 )
| V_41 ) ;
V_18 = F_9 ( V_23 , V_42 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( 0xffff0000 ) ;
V_18 = F_9 ( V_23 , V_43 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = ~ 0 ;
V_18 = F_9 ( V_23 , V_19 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
F_10 ( V_20 ) ;
V_18 = F_9 ( V_23 , V_44 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( V_23 , V_45 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( V_30 | V_31 ) ;
V_18 = F_9 ( V_23 , V_34 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( V_23 , V_46 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( V_47 ) ;
V_18 = F_9 ( V_23 , V_48 , & V_17 , sizeof( V_17 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_7 ( V_49 ) ;
return F_9 ( V_23 , V_48 , & V_17 , sizeof( V_17 ) ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_29 * V_50 = F_19 ( V_23 ) ;
struct V_8 * V_9 ;
T_2 V_17 , V_51 ;
T_4 V_52 ;
int V_18 ;
V_18 = F_11 ( V_50 , V_53 , & V_52 , sizeof( V_52 ) ) ;
if ( V_18 )
return V_18 ;
V_17 = F_20 ( V_52 ) ;
V_51 = ( V_17 >> 8 ) & 0xff ;
F_21 ( V_23 , L_1 , V_17 , V_51 ) ;
V_18 = F_22 ( V_50 -> V_13 , V_54 ,
V_11 * V_51 ) ;
if ( V_18 ) {
F_23 ( V_23 , L_2 ) ;
return V_18 ;
}
V_9 = F_24 ( sizeof( * V_9 ) , V_55 ) ;
if ( ! V_9 ) {
V_18 = - V_56 ;
goto V_57;
}
V_9 -> V_5 = V_54 ;
V_9 -> V_7 = V_11 * V_51 ;
V_9 -> V_12 = V_50 ;
V_9 -> V_2 . V_23 . V_58 = V_23 ;
V_9 -> V_2 . V_23 . V_59 = F_12 ;
V_9 -> V_2 . V_60 = V_51 ;
V_9 -> V_2 . V_61 = F_1 ;
V_9 -> V_2 . V_62 = F_4 ;
V_9 -> V_2 . V_63 = F_6 ;
V_9 -> V_2 . V_64 = F_8 ;
F_25 ( V_23 , V_9 ) ;
F_17 ( V_9 ) ;
V_18 = F_26 ( & V_9 -> V_2 ) ;
if ( ! V_18 )
return 0 ;
F_14 ( V_9 ) ;
V_57:
F_27 ( V_50 -> V_13 , V_54 ,
V_11 * V_51 ) ;
return V_18 ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_8 * V_9 = F_29 ( V_23 ) ;
F_30 ( & V_9 -> V_2 ) ;
F_27 ( V_9 -> V_12 -> V_13 , V_9 -> V_5 , V_9 -> V_7 ) ;
return 0 ;
}
