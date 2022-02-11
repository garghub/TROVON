static void F_1 ( struct V_1 * V_2 , unsigned int clock )
{
T_1 V_3 ;
unsigned long V_4 ;
V_2 -> V_5 -> V_6 = 0 ;
V_3 = F_2 ( V_2 , V_7 ) ;
V_3 &= V_8 ;
F_3 ( V_2 , V_3 , V_7 ) ;
if ( clock == 0 )
return;
V_3 = F_4 ( V_2 , clock , & V_2 -> V_5 -> V_6 ) ;
V_3 |= V_8 ;
F_3 ( V_2 , V_3 , V_7 ) ;
V_4 = 20 ;
while ( ! ( ( V_3 = F_2 ( V_2 , V_7 ) )
& V_9 ) ) {
if ( V_4 == 0 ) {
F_5 ( L_1 ,
F_6 ( V_2 -> V_5 ) ) ;
return;
}
V_4 -- ;
F_7 ( 1 ) ;
}
V_3 |= V_10 ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned char V_11 ,
unsigned short V_12 )
{
if ( ! F_9 ( V_2 -> V_5 -> V_13 . V_14 ) ) {
struct V_15 * V_5 = V_2 -> V_5 ;
F_10 ( V_5 , V_5 -> V_13 . V_14 , V_12 ) ;
}
F_11 ( V_2 , V_11 , V_12 ) ;
}
void F_12 ( struct V_1 * V_2 , unsigned int V_16 )
{
if ( V_16 == V_17 )
F_13 ( V_2 , V_18 , V_19 ) ;
F_14 ( V_2 , V_16 ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_22 * V_23 = F_17 ( V_2 ) ;
struct V_24 * V_25 = F_18 ( V_23 ) ;
int V_26 ;
V_26 = F_19 ( V_2 ) ;
if ( V_2 -> V_27 != V_28 )
F_20 ( V_2 -> V_5 ) ;
F_21 ( V_25 -> V_29 ) ;
F_21 ( V_25 -> V_30 ) ;
F_21 ( V_25 -> V_31 ) ;
return V_26 ;
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 ) ;
struct V_22 * V_23 = F_17 ( V_2 ) ;
struct V_24 * V_25 = F_18 ( V_23 ) ;
int V_26 ;
V_26 = F_23 ( V_25 -> V_31 ) ;
if ( V_26 ) {
F_24 ( V_21 , L_2 ) ;
return V_26 ;
}
V_26 = F_23 ( V_25 -> V_30 ) ;
if ( V_26 ) {
F_24 ( V_21 , L_3 ) ;
return V_26 ;
}
V_26 = F_23 ( V_25 -> V_29 ) ;
if ( V_26 ) {
F_24 ( V_21 , L_4 ) ;
return V_26 ;
}
return F_25 ( V_2 ) ;
}
static int F_26 ( struct V_32 * V_33 )
{
const struct V_34 * V_35 ;
const struct V_36 * V_37 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_38 , V_39 ;
unsigned int V_40 , V_41 ;
unsigned int V_42 , V_43 ;
int V_26 ;
unsigned int V_44 ;
V_35 = F_27 ( V_45 , & V_33 -> V_21 ) ;
if ( ! V_35 )
return - V_46 ;
V_37 = V_35 -> V_47 ;
V_2 = F_28 ( V_33 , V_37 , sizeof( * V_25 ) ) ;
if ( F_9 ( V_2 ) )
return F_29 ( V_2 ) ;
V_23 = F_17 ( V_2 ) ;
V_25 = F_18 ( V_23 ) ;
V_25 -> V_31 = F_30 ( & V_33 -> V_21 , L_5 ) ;
if ( F_9 ( V_25 -> V_31 ) ) {
F_24 ( & V_33 -> V_21 , L_6 ) ;
return F_29 ( V_25 -> V_31 ) ;
}
V_25 -> V_30 = F_30 ( & V_33 -> V_21 , L_7 ) ;
if ( F_9 ( V_25 -> V_30 ) ) {
F_24 ( & V_33 -> V_21 , L_8 ) ;
return F_29 ( V_25 -> V_30 ) ;
}
V_25 -> V_29 = F_30 ( & V_33 -> V_21 , L_9 ) ;
if ( F_9 ( V_25 -> V_29 ) ) {
F_24 ( & V_33 -> V_21 , L_10 ) ;
return F_29 ( V_25 -> V_29 ) ;
}
F_23 ( V_25 -> V_30 ) ;
V_38 = F_31 ( V_2 -> V_48 + V_49 ) ;
V_39 = F_31 ( V_2 -> V_48 + V_50 ) ;
V_40 = ( V_38 & V_51 ) >> V_52 ;
V_41 = ( V_39 & V_53 ) >> V_54 ;
V_42 = V_40 * 1000000 * ( V_41 + 1 ) ;
V_26 = F_32 ( V_25 -> V_29 , V_42 ) ;
if ( V_26 < 0 ) {
F_24 ( & V_33 -> V_21 , L_11 ) ;
goto V_55;
}
V_43 = F_33 ( V_25 -> V_29 ) ;
if ( V_43 != V_42 ) {
V_41 = V_43 / ( V_40 * 1000000 ) - 1 ;
V_39 &= ( ~ V_53 ) ;
V_39 |= ( ( V_41 << V_54 ) & V_53 ) ;
F_34 ( V_56 | V_57 , V_2 -> V_48 + V_58 ) ;
F_34 ( V_39 , V_2 -> V_48 + V_50 ) ;
F_34 ( 0 , V_2 -> V_48 + V_58 ) ;
F_35 ( & V_33 -> V_21 , L_12 ,
V_41 , V_43 ) ;
}
V_44 = F_36 ( V_43 , 24000000 ) - 1 ;
F_37 ( V_59 | V_44 ,
V_2 -> V_48 + V_60 ) ;
V_44 = F_36 ( V_43 , 50000000 ) - 1 ;
F_37 ( V_59 | V_44 ,
V_2 -> V_48 + V_61 ) ;
V_44 = F_36 ( V_43 , 100000000 ) - 1 ;
F_37 ( V_59 | V_44 ,
V_2 -> V_48 + V_62 ) ;
V_44 = F_36 ( V_43 , 120000000 ) - 1 ;
F_37 ( V_59 | V_44 ,
V_2 -> V_48 + V_63 ) ;
V_44 = F_36 ( V_43 , 50000000 ) - 1 ;
F_37 ( V_59 | V_44 ,
V_2 -> V_48 + V_64 ) ;
F_23 ( V_25 -> V_31 ) ;
F_23 ( V_25 -> V_29 ) ;
V_26 = F_38 ( V_2 -> V_5 ) ;
if ( V_26 )
goto V_65;
F_39 ( V_33 ) ;
F_40 ( & V_33 -> V_21 ) ;
F_41 ( & V_33 -> V_21 ) ;
F_42 ( & V_33 -> V_21 ) ;
F_43 ( & V_33 -> V_21 , 50 ) ;
F_44 ( & V_33 -> V_21 ) ;
V_26 = F_45 ( V_2 ) ;
if ( V_26 )
goto V_66;
if ( F_46 ( V_2 -> V_5 ) &&
F_47 ( V_2 -> V_5 ) < 0 ) {
V_2 -> V_5 -> V_67 |= V_68 ;
V_2 -> V_69 &= ~ V_70 ;
}
F_48 ( & V_33 -> V_21 ) ;
return 0 ;
V_66:
V_66 ( & V_33 -> V_21 ) ;
F_49 ( & V_33 -> V_21 ) ;
F_50 ( & V_33 -> V_21 ) ;
V_65:
F_21 ( V_25 -> V_29 ) ;
F_21 ( V_25 -> V_31 ) ;
V_55:
F_21 ( V_25 -> V_30 ) ;
F_51 ( V_33 ) ;
return V_26 ;
}
static int F_52 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_53 ( V_33 ) ;
struct V_22 * V_23 = F_17 ( V_2 ) ;
struct V_24 * V_25 = F_18 ( V_23 ) ;
struct V_3 * V_29 = V_25 -> V_29 ;
struct V_3 * V_30 = V_25 -> V_30 ;
struct V_3 * V_31 = V_25 -> V_31 ;
F_54 ( & V_33 -> V_21 ) ;
V_66 ( & V_33 -> V_21 ) ;
F_50 ( & V_33 -> V_21 ) ;
F_55 ( V_33 ) ;
F_21 ( V_29 ) ;
F_21 ( V_30 ) ;
F_21 ( V_31 ) ;
return 0 ;
}
