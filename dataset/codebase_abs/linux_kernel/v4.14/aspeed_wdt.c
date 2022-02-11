static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , int V_5 )
{
V_4 -> V_6 |= V_7 ;
F_4 ( 0 , V_4 -> V_8 + V_9 ) ;
F_4 ( V_5 , V_4 -> V_8 + V_10 ) ;
F_4 ( V_11 , V_4 -> V_8 + V_12 ) ;
F_4 ( V_4 -> V_6 , V_4 -> V_8 + V_9 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 , V_3 -> V_13 * V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_6 &= ~ V_7 ;
F_4 ( V_4 -> V_6 , V_4 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( V_11 , V_4 -> V_8 + V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned int V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_15 ;
V_3 -> V_13 = V_13 ;
V_15 = F_9 ( V_13 , V_3 -> V_16 * 1000 ) ;
F_4 ( V_15 * V_14 , V_4 -> V_8 + V_10 ) ;
F_4 ( V_11 , V_4 -> V_8 + V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned long V_17 , void * V_18 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 , 128 * V_14 / 1000 ) ;
F_11 ( 1000 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
const struct V_21 * V_22 ;
const struct V_23 * V_24 ;
struct V_1 * V_4 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
const char * V_29 ;
T_1 V_30 ;
int V_31 ;
V_4 = F_13 ( & V_20 -> V_32 , sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_26 = F_14 ( V_20 , V_35 , 0 ) ;
V_4 -> V_8 = F_15 ( & V_20 -> V_32 , V_26 ) ;
if ( F_16 ( V_4 -> V_8 ) )
return F_17 ( V_4 -> V_8 ) ;
V_4 -> V_3 . V_36 = & V_37 ;
V_4 -> V_3 . V_38 = & V_39 ;
V_4 -> V_3 . V_16 = V_40 ;
V_4 -> V_3 . V_41 = & V_20 -> V_32 ;
V_4 -> V_3 . V_13 = V_42 ;
F_18 ( & V_4 -> V_3 , 0 , & V_20 -> V_32 ) ;
V_28 = V_20 -> V_32 . V_43 ;
V_24 = F_19 ( V_44 , V_28 ) ;
if ( ! V_24 )
return - V_45 ;
V_22 = V_24 -> V_18 ;
V_4 -> V_6 = V_46 ;
V_31 = F_20 ( V_28 , L_1 , & V_29 ) ;
if ( V_31 ) {
V_4 -> V_6 |= V_47 | V_48 ;
} else {
if ( ! strcmp ( V_29 , L_2 ) )
V_4 -> V_6 |= V_49 ;
else if ( ! strcmp ( V_29 , L_3 ) )
V_4 -> V_6 |= V_47 ;
else if ( ! strcmp ( V_29 , L_4 ) )
V_4 -> V_6 |= V_48 ;
else if ( strcmp ( V_29 , L_5 ) )
return - V_45 ;
}
if ( F_21 ( V_28 , L_6 ) )
V_4 -> V_6 |= V_50 ;
F_4 ( V_4 -> V_6 , V_4 -> V_8 + V_9 ) ;
if ( F_22 ( V_4 -> V_8 + V_9 ) & V_7 ) {
F_5 ( & V_4 -> V_3 ) ;
F_23 ( V_51 , & V_4 -> V_3 . V_52 ) ;
}
if ( F_24 ( V_28 , L_7 ) ) {
T_1 V_53 = F_22 ( V_4 -> V_8 + V_54 ) ;
V_53 &= V_22 -> V_55 ;
if ( F_21 ( V_28 , L_8 ) )
V_53 |= V_56 ;
else
V_53 |= V_57 ;
F_4 ( V_53 , V_4 -> V_8 + V_54 ) ;
V_53 &= V_22 -> V_55 ;
if ( F_21 ( V_28 , L_9 ) )
V_53 |= V_58 ;
else
V_53 |= V_59 ;
F_4 ( V_53 , V_4 -> V_8 + V_54 ) ;
}
if ( ! F_25 ( V_28 , L_10 , & V_30 ) ) {
T_1 V_60 = V_22 -> V_55 + 1 ;
if ( V_30 == 0 || V_30 > V_60 ) {
F_26 ( & V_20 -> V_32 , L_11 ,
V_30 ) ;
V_30 = F_27 ( 1U , F_9 ( V_60 , V_30 ) ) ;
F_28 ( & V_20 -> V_32 , L_12 ,
V_30 ) ;
}
F_4 ( V_30 - 1 , V_4 -> V_8 + V_54 ) ;
}
V_31 = F_29 ( & V_20 -> V_32 , & V_4 -> V_3 ) ;
if ( V_31 ) {
F_26 ( & V_20 -> V_32 , L_13 ) ;
return V_31 ;
}
return 0 ;
}
