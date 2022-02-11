static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_5 ) ;
T_2 V_6 ;
V_6 = V_4 -> V_7 . V_8 ( V_4 ) ;
return V_6 ;
}
static int F_3 ( struct V_9 * V_10 , T_3 V_11 )
{
struct V_3 * V_4 = F_2 ( V_10 ,
struct V_3 ,
V_9 ) ;
unsigned long V_12 ;
T_2 V_13 ;
T_4 V_14 , V_15 ;
unsigned int V_16 = 0 ;
if ( V_11 < 0 ) {
V_16 = 1 ;
V_11 = - V_11 ;
}
V_13 = V_4 -> V_17 ;
V_13 *= V_11 ;
V_15 = F_4 ( V_13 , 1000000000UL ) ;
V_14 = ( V_16 ) ? V_4 -> V_17 - V_15 :
V_4 -> V_17 + V_15 ;
F_5 ( & V_4 -> V_18 , V_12 ) ;
V_4 -> V_7 . V_19 ( V_4 , V_14 ) ;
F_6 ( & V_4 -> V_18 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 , T_5 V_11 )
{
struct V_3 * V_4 = F_2 ( V_10 ,
struct V_3 ,
V_9 ) ;
unsigned long V_12 ;
F_5 ( & V_4 -> V_18 , V_12 ) ;
F_8 ( & V_4 -> V_20 , V_11 ) ;
F_6 ( & V_4 -> V_18 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_10 ,
struct V_3 ,
V_9 ) ;
unsigned long V_12 ;
T_2 V_6 ;
F_5 ( & V_4 -> V_18 , V_12 ) ;
V_6 = F_10 ( & V_4 -> V_20 ) ;
F_6 ( & V_4 -> V_18 , V_12 ) ;
* V_22 = F_11 ( V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
const struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_10 ,
struct V_3 ,
V_9 ) ;
unsigned long V_12 ;
T_2 V_6 ;
V_6 = F_13 ( V_22 ) ;
F_5 ( & V_4 -> V_18 , V_12 ) ;
F_14 ( & V_4 -> V_20 , & V_4 -> V_5 , V_6 ) ;
F_6 ( & V_4 -> V_18 , V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_23 * V_24 , int V_25 )
{
return - V_26 ;
}
void F_16 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_9 ;
struct V_27 * clock ;
struct V_1 * V_2 = & V_4 -> V_5 ;
T_2 V_28 ;
snprintf ( V_10 -> V_29 , sizeof( V_10 -> V_29 ) , L_1 ,
F_17 ( V_4 -> V_30 ) ) ;
V_10 -> V_31 = V_32 ;
V_10 -> V_33 = V_4 -> V_34 ;
V_10 -> V_35 = F_3 ;
V_10 -> V_36 = F_7 ;
V_10 -> V_37 = F_9 ;
V_10 -> V_38 = F_12 ;
V_10 -> V_39 = F_15 ;
clock = F_18 ( V_10 , V_4 -> V_40 ) ;
if ( F_19 ( clock ) ) {
F_20 ( V_4 -> V_40 , L_2 ) ;
return;
}
V_4 -> V_27 = clock ;
V_28 = 50000000 ;
V_28 <<= 32 ;
V_4 -> V_17 = F_4 ( V_28 , V_4 -> V_34 ) ;
V_2 -> V_41 = F_1 ;
V_2 -> V_42 = F_21 ( 64 ) ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 0 ;
F_14 ( & V_4 -> V_20 , & V_4 -> V_5 ,
F_22 ( F_23 () ) ) ;
F_24 ( V_4 , V_45 , 0 ) ;
V_4 -> V_46 . V_47 = V_48 ;
V_4 -> V_46 . V_49 = V_50 ;
}
void F_25 ( struct V_3 * V_4 )
{
if ( V_4 -> V_27 )
F_26 ( V_4 -> V_27 ) ;
}
