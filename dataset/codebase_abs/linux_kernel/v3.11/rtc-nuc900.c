static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 = 0 , V_6 ;
V_6 = F_2 ( V_4 -> V_7 + V_8 ) ;
if ( V_6 & V_9 ) {
V_6 &= ~ V_9 ;
F_3 ( V_6 , V_4 -> V_7 + V_8 ) ;
V_5 |= V_10 | V_11 ;
}
if ( V_6 & V_12 ) {
V_6 &= ~ V_12 ;
F_3 ( V_6 , V_4 -> V_7 + V_8 ) ;
V_5 |= V_13 | V_11 ;
}
F_4 ( V_4 -> V_14 , 1 , V_5 ) ;
return V_15 ;
}
static int * F_5 ( struct V_3 * V_3 )
{
unsigned int V_16 = 0x1000 ;
F_3 ( V_17 , V_3 -> V_7 + V_18 ) ;
F_6 ( 10 ) ;
F_3 ( V_19 , V_3 -> V_7 + V_20 ) ;
while ( ! ( F_2 ( V_3 -> V_7 + V_20 ) & V_21 )
&& V_16 -- )
F_6 ( 1 ) ;
if ( ! V_16 )
return F_7 ( - V_22 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_23 ,
unsigned int V_24 , struct V_25 * V_26 )
{
V_26 -> V_27 = F_9 ( V_24 >> 0 ) ;
V_26 -> V_28 = F_9 ( V_24 >> 8 ) ;
V_26 -> V_29 = F_9 ( V_24 >> 16 ) + 100 ;
V_26 -> V_30 = F_9 ( V_23 >> 0 ) ;
V_26 -> V_31 = F_9 ( V_23 >> 8 ) ;
V_26 -> V_32 = F_9 ( V_23 >> 16 ) ;
return F_10 ( V_26 ) ;
}
static void F_11 ( struct V_33 * V_34 , struct V_25 * V_35 ,
struct V_36 * V_37 )
{
V_37 -> V_38 = F_12 ( V_35 -> V_27 ) << 0 ;
V_37 -> V_39 = F_12 ( V_35 -> V_28 ) << 8 ;
if ( V_35 -> V_29 < 100 ) {
F_13 ( V_34 , L_1 ) ;
V_37 -> V_40 = F_12 ( V_35 -> V_29 ) << 16 ;
} else {
V_37 -> V_40 = F_12 ( V_35 -> V_29 - 100 ) << 16 ;
}
V_37 -> V_41 = F_12 ( V_35 -> V_30 ) << 0 ;
V_37 -> V_42 = F_12 ( V_35 -> V_31 ) << 8 ;
V_37 -> V_43 = F_12 ( V_35 -> V_32 ) << 16 ;
}
static int F_14 ( struct V_33 * V_34 , unsigned int V_44 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
if ( V_44 )
F_3 ( F_2 ( V_4 -> V_7 + V_45 ) |
( V_9 ) , V_4 -> V_7 + V_45 ) ;
else
F_3 ( F_2 ( V_4 -> V_7 + V_45 ) &
( ~ V_9 ) , V_4 -> V_7 + V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_33 * V_34 , struct V_25 * V_26 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
unsigned int V_46 , V_47 ;
V_46 = F_2 ( V_4 -> V_7 + V_48 ) ;
V_47 = F_2 ( V_4 -> V_7 + V_49 ) ;
return F_8 ( V_46 , V_47 , V_26 ) ;
}
static int F_17 ( struct V_33 * V_34 , struct V_25 * V_26 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
struct V_36 V_37 ;
unsigned long V_50 ;
int * V_51 ;
F_11 ( V_34 , V_26 , & V_37 ) ;
V_51 = F_5 ( V_4 ) ;
if ( F_18 ( V_51 ) )
return F_19 ( V_51 ) ;
V_50 = V_37 . V_38 | V_37 . V_39 | V_37 . V_40 ;
F_3 ( V_50 , V_4 -> V_7 + V_49 ) ;
V_50 = V_37 . V_41 | V_37 . V_42 | V_37 . V_43 ;
F_3 ( V_50 , V_4 -> V_7 + V_48 ) ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 , struct V_52 * V_53 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
unsigned int V_46 , V_54 ;
V_46 = F_2 ( V_4 -> V_7 + V_55 ) ;
V_54 = F_2 ( V_4 -> V_7 + V_56 ) ;
return F_8 ( V_46 , V_54 , & V_53 -> time ) ;
}
static int F_21 ( struct V_33 * V_34 , struct V_52 * V_53 )
{
struct V_3 * V_4 = F_15 ( V_34 ) ;
struct V_36 V_26 ;
unsigned long V_50 ;
int * V_51 ;
F_11 ( V_34 , & V_53 -> time , & V_26 ) ;
V_51 = F_5 ( V_4 ) ;
if ( F_18 ( V_51 ) )
return F_19 ( V_51 ) ;
V_50 = V_26 . V_38 | V_26 . V_39 | V_26 . V_40 ;
F_3 ( V_50 , V_4 -> V_7 + V_56 ) ;
V_50 = V_26 . V_41 | V_26 . V_42 | V_26 . V_43 ;
F_3 ( V_50 , V_4 -> V_7 + V_55 ) ;
return 0 ;
}
static int T_2 F_22 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_3 * V_3 ;
V_3 = F_23 ( & V_58 -> V_34 , sizeof( struct V_3 ) ,
V_61 ) ;
if ( ! V_3 ) {
F_24 ( & V_58 -> V_34 , L_2 ) ;
return - V_62 ;
}
V_60 = F_25 ( V_58 , V_63 , 0 ) ;
V_3 -> V_7 = F_26 ( & V_58 -> V_34 , V_60 ) ;
if ( F_18 ( V_3 -> V_7 ) )
return F_19 ( V_3 -> V_7 ) ;
F_27 ( V_58 , V_3 ) ;
V_3 -> V_14 = F_28 ( & V_58 -> V_34 , V_58 -> V_64 ,
& V_65 , V_66 ) ;
if ( F_18 ( V_3 -> V_14 ) ) {
F_24 ( & V_58 -> V_34 , L_3 ) ;
return F_19 ( V_3 -> V_14 ) ;
}
F_3 ( F_2 ( V_3 -> V_7 + V_67 ) | V_68 ,
V_3 -> V_7 + V_67 ) ;
V_3 -> V_69 = F_29 ( V_58 , 0 ) ;
if ( F_30 ( & V_58 -> V_34 , V_3 -> V_69 ,
F_1 , 0 , L_4 , V_3 ) ) {
F_24 ( & V_58 -> V_34 , L_5 ) ;
return - V_70 ;
}
return 0 ;
}
