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
F_10 ( & V_2 -> V_16 ) ;
F_11 ( V_5 , V_5 -> V_13 . V_14 , V_12 ) ;
F_12 ( & V_2 -> V_16 ) ;
}
F_13 ( V_2 , V_11 , V_12 ) ;
}
void F_14 ( struct V_1 * V_2 , unsigned int V_17 )
{
if ( V_17 == V_18 )
F_15 ( V_2 , V_19 , V_20 ) ;
F_16 ( V_2 , V_17 ) ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_23 * V_24 = F_19 ( V_2 ) ;
struct V_25 * V_26 = F_20 ( V_24 ) ;
int V_27 ;
V_27 = F_21 ( V_2 ) ;
F_22 ( V_26 -> V_28 ) ;
F_22 ( V_26 -> V_29 ) ;
F_22 ( V_26 -> V_30 ) ;
return V_27 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_23 * V_24 = F_19 ( V_2 ) ;
struct V_25 * V_26 = F_20 ( V_24 ) ;
int V_27 ;
V_27 = F_24 ( V_26 -> V_30 ) ;
if ( V_27 ) {
F_25 ( V_22 , L_2 ) ;
return V_27 ;
}
V_27 = F_24 ( V_26 -> V_29 ) ;
if ( V_27 ) {
F_25 ( V_22 , L_3 ) ;
return V_27 ;
}
V_27 = F_24 ( V_26 -> V_28 ) ;
if ( V_27 ) {
F_25 ( V_22 , L_4 ) ;
return V_27 ;
}
return F_26 ( V_2 ) ;
}
static int F_27 ( struct V_31 * V_32 )
{
const struct V_33 * V_34 ;
const struct V_35 * V_36 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
unsigned int V_37 , V_38 ;
unsigned int V_39 , V_40 ;
unsigned int V_41 , V_42 ;
int V_27 ;
unsigned int V_43 ;
V_34 = F_28 ( V_44 , & V_32 -> V_22 ) ;
if ( ! V_34 )
return - V_45 ;
V_36 = V_34 -> V_46 ;
V_2 = F_29 ( V_32 , V_36 , sizeof( * V_26 ) ) ;
if ( F_9 ( V_2 ) )
return F_30 ( V_2 ) ;
V_24 = F_19 ( V_2 ) ;
V_26 = F_20 ( V_24 ) ;
V_26 -> V_30 = F_31 ( & V_32 -> V_22 , L_5 ) ;
if ( F_9 ( V_26 -> V_30 ) ) {
F_25 ( & V_32 -> V_22 , L_6 ) ;
return F_30 ( V_26 -> V_30 ) ;
}
V_26 -> V_29 = F_31 ( & V_32 -> V_22 , L_7 ) ;
if ( F_9 ( V_26 -> V_29 ) ) {
F_25 ( & V_32 -> V_22 , L_8 ) ;
return F_30 ( V_26 -> V_29 ) ;
}
V_26 -> V_28 = F_31 ( & V_32 -> V_22 , L_9 ) ;
if ( F_9 ( V_26 -> V_28 ) ) {
F_25 ( & V_32 -> V_22 , L_10 ) ;
return F_30 ( V_26 -> V_28 ) ;
}
F_24 ( V_26 -> V_29 ) ;
V_37 = F_32 ( V_2 -> V_47 + V_48 ) ;
V_38 = F_32 ( V_2 -> V_47 + V_49 ) ;
V_39 = ( V_37 & V_50 ) >> V_51 ;
V_40 = ( V_38 & V_52 ) >> V_53 ;
V_41 = V_39 * 1000000 * ( V_40 + 1 ) ;
V_27 = F_33 ( V_26 -> V_28 , V_41 ) ;
if ( V_27 < 0 ) {
F_25 ( & V_32 -> V_22 , L_11 ) ;
goto V_54;
}
V_42 = F_34 ( V_26 -> V_28 ) ;
if ( V_42 != V_41 ) {
V_40 = V_42 / ( V_39 * 1000000 ) - 1 ;
V_38 &= ( ~ V_52 ) ;
V_38 |= ( ( V_40 << V_53 ) & V_52 ) ;
F_35 ( V_55 | V_56 , V_2 -> V_47 + V_57 ) ;
F_35 ( V_38 , V_2 -> V_47 + V_49 ) ;
F_35 ( 0 , V_2 -> V_47 + V_57 ) ;
F_36 ( & V_32 -> V_22 , L_12 ,
V_40 , V_42 ) ;
}
V_43 = F_37 ( V_42 , 24000000 ) - 1 ;
F_38 ( V_58 | V_43 ,
V_2 -> V_47 + V_59 ) ;
V_43 = F_37 ( V_42 , 50000000 ) - 1 ;
F_38 ( V_58 | V_43 ,
V_2 -> V_47 + V_60 ) ;
V_43 = F_37 ( V_42 , 100000000 ) - 1 ;
F_38 ( V_58 | V_43 ,
V_2 -> V_47 + V_61 ) ;
V_43 = F_37 ( V_42 , 120000000 ) - 1 ;
F_38 ( V_58 | V_43 ,
V_2 -> V_47 + V_62 ) ;
V_43 = F_37 ( V_42 , 50000000 ) - 1 ;
F_38 ( V_58 | V_43 ,
V_2 -> V_47 + V_63 ) ;
F_24 ( V_26 -> V_30 ) ;
F_24 ( V_26 -> V_28 ) ;
V_27 = F_39 ( V_2 -> V_5 ) ;
if ( V_27 )
goto V_64;
F_40 ( V_32 ) ;
F_41 ( & V_32 -> V_22 ) ;
F_42 ( & V_32 -> V_22 ) ;
F_43 ( & V_32 -> V_22 ) ;
F_44 ( & V_32 -> V_22 , 50 ) ;
F_45 ( & V_32 -> V_22 ) ;
V_27 = F_46 ( V_2 ) ;
if ( V_27 )
goto V_65;
if ( F_47 ( V_2 -> V_5 ) &&
F_48 ( V_2 -> V_5 ) < 0 ) {
V_2 -> V_5 -> V_66 |= V_67 ;
V_2 -> V_68 &= ~ V_69 ;
}
F_49 ( & V_32 -> V_22 ) ;
return 0 ;
V_65:
V_65 ( & V_32 -> V_22 ) ;
F_50 ( & V_32 -> V_22 ) ;
F_51 ( & V_32 -> V_22 ) ;
V_64:
F_22 ( V_26 -> V_28 ) ;
F_22 ( V_26 -> V_30 ) ;
V_54:
F_22 ( V_26 -> V_29 ) ;
F_52 ( V_32 ) ;
return V_27 ;
}
static int F_53 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_54 ( V_32 ) ;
struct V_23 * V_24 = F_19 ( V_2 ) ;
struct V_25 * V_26 = F_20 ( V_24 ) ;
struct V_3 * V_28 = V_26 -> V_28 ;
struct V_3 * V_29 = V_26 -> V_29 ;
struct V_3 * V_30 = V_26 -> V_30 ;
F_55 ( & V_32 -> V_22 ) ;
V_65 ( & V_32 -> V_22 ) ;
F_51 ( & V_32 -> V_22 ) ;
F_56 ( V_32 ) ;
F_22 ( V_28 ) ;
F_22 ( V_29 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
