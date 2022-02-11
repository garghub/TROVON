static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_1 , V_2 ) ;
return F_3 ( 1 ) ;
}
static int F_4 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
V_9 [ 1 ] = F_5 ( V_11 -> V_13 + V_14 ) ;
return V_8 -> V_15 ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
V_6 -> V_16 = F_5 ( V_11 -> V_13 + V_17 ) ;
if ( F_7 ( V_6 , V_9 ) )
F_8 ( V_6 -> V_16 , V_11 -> V_13 + V_17 ) ;
V_9 [ 1 ] = V_6 -> V_16 ;
return V_8 -> V_15 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
V_18 = 0 ;
F_8 ( 0x0 , V_11 -> V_13 + V_19 ) ;
F_5 ( V_11 -> V_13 + V_20 ) ;
F_8 ( 0x0 , V_11 -> V_13 + V_21 ) ;
F_8 ( 0x0 , V_11 -> V_13 + V_22 ) ;
F_8 ( 0x0 , V_11 -> V_13 + V_17 ) ;
F_8 ( 0x0 , V_11 -> V_13 + V_23 ) ;
F_10 ( V_11 -> V_13 + V_24 ) ;
F_8 ( 0x0 , V_11 -> V_13 + V_25 ) ;
F_8 ( 0x0 , V_11 -> V_13 + V_26 ) ;
F_8 ( 0x0 , V_4 -> V_27 + F_11 ( V_28 ) ) ;
F_8 ( 0x0 , V_4 -> V_27 + F_11 ( V_29 ) ) ;
F_8 ( 0x0 , V_4 -> V_27 + F_11 ( V_30 ) ) ;
F_8 ( 0x0 , V_4 -> V_27 + F_11 ( V_31 ) ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
unsigned long V_32 )
{
struct V_33 * V_34 = F_13 ( V_4 ) ;
struct V_10 * V_11 ;
struct V_5 * V_6 ;
int V_35 ;
V_4 -> V_36 = V_4 -> V_37 -> V_38 ;
V_11 = F_14 ( V_4 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_39 ;
V_35 = F_15 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_4 -> V_27 = F_16 ( V_34 , 1 ) ;
V_11 -> V_13 = F_16 ( V_34 , 0 ) ;
F_9 ( V_4 ) ;
if ( V_34 -> V_1 > 0 ) {
V_35 = F_17 ( V_34 -> V_1 , F_1 , V_40 ,
V_4 -> V_36 , V_4 ) ;
if ( V_35 == 0 )
V_4 -> V_1 = V_34 -> V_1 ;
}
V_35 = F_18 ( V_4 , 3 ) ;
if ( V_35 )
return V_35 ;
V_6 = & V_4 -> V_41 [ 0 ] ;
V_6 -> type = V_42 ;
V_6 -> V_43 = V_44 ;
V_6 -> V_45 = 32 ;
V_6 -> V_46 = 1 ;
V_6 -> V_47 = 32 ;
V_6 -> V_48 = & V_49 ;
V_6 -> V_50 = V_51 ;
V_6 -> V_52 = F_4 ;
V_6 = & V_4 -> V_41 [ 1 ] ;
V_6 -> type = V_53 ;
V_6 -> V_43 = V_54 ;
V_6 -> V_45 = 32 ;
V_6 -> V_46 = 0xffffffff ;
V_6 -> V_47 = 32 ;
V_6 -> V_48 = & V_49 ;
V_6 -> V_50 = V_55 ;
V_6 -> V_52 = F_6 ;
V_6 -> V_56 = V_57 ;
V_6 = & V_4 -> V_41 [ 2 ] ;
V_6 -> type = V_58 ;
V_6 -> V_43 = V_54 ;
V_6 -> V_45 = 1 ;
V_6 -> V_46 = 0 ;
V_6 -> V_47 = 1 ;
V_6 -> V_48 = & V_49 ;
V_6 -> V_59 = V_60 ;
V_6 -> V_56 = V_61 ;
V_6 -> V_50 = V_62 ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
if ( V_11 ) {
if ( V_4 -> V_27 )
F_9 ( V_4 ) ;
if ( V_4 -> V_1 )
F_20 ( V_4 -> V_1 , V_4 ) ;
}
F_21 ( V_4 ) ;
}
static int F_22 ( struct V_33 * V_4 ,
const struct V_63 * V_64 )
{
return F_23 ( V_4 , & V_65 , V_64 -> V_66 ) ;
}
