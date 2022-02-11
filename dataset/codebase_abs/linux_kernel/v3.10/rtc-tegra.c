static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_4 ) & 1 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
int V_7 = 500 ;
while ( F_1 ( V_2 ) ) {
if ( ! V_7 -- )
goto V_8;
F_5 ( 1 ) ;
}
return 0 ;
V_8:
F_6 ( V_6 , L_1 ) ;
return - V_9 ;
}
static int F_7 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
unsigned long V_12 , V_13 ;
unsigned long V_14 ;
F_8 ( & V_2 -> V_15 , V_14 ) ;
V_13 = F_2 ( V_2 -> V_3 + V_16 ) ;
V_12 = F_2 ( V_2 -> V_3 + V_17 ) ;
F_9 ( & V_2 -> V_15 , V_14 ) ;
F_10 ( V_12 , V_11 ) ;
F_11 ( V_6 , L_2 ,
V_12 ,
V_11 -> V_18 + 1 ,
V_11 -> V_19 ,
V_11 -> V_20 + 1900 ,
V_11 -> V_21 ,
V_11 -> V_22 ,
V_11 -> V_23
) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
unsigned long V_12 ;
int V_24 ;
V_24 = F_13 ( V_11 ) ;
if ( V_24 )
return V_24 ;
F_14 ( V_11 , & V_12 ) ;
F_11 ( V_6 , L_3 ,
V_12 ,
V_11 -> V_18 + 1 ,
V_11 -> V_19 ,
V_11 -> V_20 + 1900 ,
V_11 -> V_21 ,
V_11 -> V_22 ,
V_11 -> V_23
) ;
V_24 = F_3 ( V_6 ) ;
if ( ! V_24 )
F_15 ( V_12 , V_2 -> V_3 + V_25 ) ;
F_11 ( V_6 , L_4 ,
F_2 ( V_2 -> V_3 + V_25 ) ) ;
return V_24 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
unsigned long V_12 ;
unsigned V_28 ;
V_12 = F_2 ( V_2 -> V_3 + V_29 ) ;
if ( V_12 == 0 ) {
V_27 -> V_30 = 0 ;
V_27 -> time . V_18 = - 1 ;
V_27 -> time . V_19 = - 1 ;
V_27 -> time . V_20 = - 1 ;
V_27 -> time . V_21 = - 1 ;
V_27 -> time . V_22 = - 1 ;
V_27 -> time . V_23 = - 1 ;
} else {
V_27 -> V_30 = 1 ;
F_10 ( V_12 , & V_27 -> time ) ;
}
V_28 = F_2 ( V_2 -> V_3 + V_31 ) ;
V_27 -> V_32 = ( V_28 & V_33 ) != 0 ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , unsigned int V_30 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
unsigned V_34 ;
unsigned long V_14 ;
F_3 ( V_6 ) ;
F_8 ( & V_2 -> V_15 , V_14 ) ;
V_34 = F_2 ( V_2 -> V_3 + V_35 ) ;
if ( V_30 )
V_34 |= V_36 ;
else
V_34 &= ~ V_36 ;
F_15 ( V_34 , V_2 -> V_3 + V_35 ) ;
F_9 ( & V_2 -> V_15 , V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
unsigned long V_12 ;
if ( V_27 -> V_30 )
F_14 ( & V_27 -> time , & V_12 ) ;
else
V_12 = 0 ;
F_3 ( V_6 ) ;
F_15 ( V_12 , V_2 -> V_3 + V_29 ) ;
F_11 ( V_6 , L_5 ,
F_2 ( V_2 -> V_3 + V_29 ) ) ;
if ( V_12 ) {
F_17 ( V_6 , 1 ) ;
F_11 ( V_6 , L_6 ,
V_12 ,
V_27 -> time . V_18 + 1 ,
V_27 -> time . V_19 ,
V_27 -> time . V_20 + 1900 ,
V_27 -> time . V_21 ,
V_27 -> time . V_22 ,
V_27 -> time . V_23 ) ;
} else {
F_11 ( V_6 , L_7 ) ;
F_17 ( V_6 , 0 ) ;
}
return 0 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_37 * V_38 )
{
if ( ! V_6 || ! V_6 -> V_39 )
return 0 ;
return F_20 ( V_38 , L_8 , F_21 ( V_6 ) ) ;
}
static T_2 F_22 ( int V_40 , void * V_41 )
{
struct V_5 * V_6 = V_41 ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
unsigned long V_42 = 0 ;
unsigned V_34 ;
unsigned long V_14 ;
V_34 = F_2 ( V_2 -> V_3 + V_31 ) ;
if ( V_34 ) {
F_3 ( V_6 ) ;
F_8 ( & V_2 -> V_15 , V_14 ) ;
F_15 ( 0 , V_2 -> V_3 + V_35 ) ;
F_15 ( V_34 , V_2 -> V_3 + V_31 ) ;
F_9 ( & V_2 -> V_15 , V_14 ) ;
}
if ( ( V_34 & V_33 ) )
V_42 |= V_43 | V_44 ;
if ( ( V_34 & V_45 ) )
V_42 |= V_43 | V_46 ;
F_23 ( V_2 -> V_47 , 1 , V_42 ) ;
return V_48 ;
}
static int T_3 F_24 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_24 ;
V_2 = F_25 ( & V_50 -> V_6 , sizeof( struct V_1 ) ,
V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_52 = F_26 ( V_50 , V_55 , 0 ) ;
V_2 -> V_3 = F_27 ( & V_50 -> V_6 , V_52 ) ;
if ( F_28 ( V_2 -> V_3 ) )
return F_29 ( V_2 -> V_3 ) ;
V_2 -> V_56 = F_30 ( V_50 , 0 ) ;
if ( V_2 -> V_56 <= 0 )
return - V_57 ;
V_2 -> V_50 = V_50 ;
F_31 ( & V_2 -> V_15 ) ;
F_32 ( V_50 , V_2 ) ;
F_15 ( 0 , V_2 -> V_3 + V_29 ) ;
F_15 ( 0xffffffff , V_2 -> V_3 + V_31 ) ;
F_15 ( 0 , V_2 -> V_3 + V_35 ) ;
F_33 ( & V_50 -> V_6 , 1 ) ;
V_2 -> V_47 = F_34 ( & V_50 -> V_6 ,
F_21 ( & V_50 -> V_6 ) , & V_58 ,
V_59 ) ;
if ( F_28 ( V_2 -> V_47 ) ) {
V_24 = F_29 ( V_2 -> V_47 ) ;
F_6 ( & V_50 -> V_6 , L_9 ,
V_24 ) ;
return V_24 ;
}
V_24 = F_35 ( & V_50 -> V_6 , V_2 -> V_56 ,
F_22 , V_60 ,
F_21 ( & V_50 -> V_6 ) , & V_50 -> V_6 ) ;
if ( V_24 ) {
F_6 ( & V_50 -> V_6 ,
L_10 ,
V_24 ) ;
return V_24 ;
}
F_36 ( & V_50 -> V_6 , L_11 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
F_3 ( V_6 ) ;
F_15 ( 0xffffffff , V_2 -> V_3 + V_31 ) ;
F_15 ( V_33 ,
V_2 -> V_3 + V_35 ) ;
F_11 ( V_6 , L_12 ,
F_2 ( V_2 -> V_3 + V_29 ) ) ;
F_11 ( V_6 , L_13 ,
F_38 ( V_6 ) , V_2 -> V_56 ) ;
if ( F_38 ( V_6 ) )
F_39 ( V_2 -> V_56 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
F_11 ( V_6 , L_14 ,
F_38 ( V_6 ) ) ;
if ( F_38 ( V_6 ) )
F_41 ( V_2 -> V_56 ) ;
return 0 ;
}
static void F_42 ( struct V_49 * V_50 )
{
F_11 ( & V_50 -> V_6 , L_15 ) ;
F_17 ( & V_50 -> V_6 , 0 ) ;
}
