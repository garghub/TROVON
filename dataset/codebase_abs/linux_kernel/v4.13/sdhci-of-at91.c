static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int clock )
{
T_2 V_7 ;
unsigned long V_8 ;
V_2 -> V_9 -> V_10 = 0 ;
V_7 = F_5 ( V_2 , V_11 ) ;
V_7 &= V_12 ;
F_6 ( V_2 , V_7 , V_11 ) ;
if ( clock == 0 )
return;
V_7 = F_7 ( V_2 , clock , & V_2 -> V_9 -> V_10 ) ;
V_7 |= V_12 ;
F_6 ( V_2 , V_7 , V_11 ) ;
V_8 = 20 ;
while ( ! ( ( V_7 = F_5 ( V_2 , V_11 ) )
& V_13 ) ) {
if ( V_8 == 0 ) {
F_8 ( L_1 ,
F_9 ( V_2 -> V_9 ) ) ;
return;
}
V_8 -- ;
F_10 ( 1 ) ;
}
V_7 |= V_14 ;
F_6 ( V_2 , V_7 , V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned char V_15 ,
unsigned short V_16 )
{
if ( ! F_12 ( V_2 -> V_9 -> V_17 . V_18 ) ) {
struct V_19 * V_9 = V_2 -> V_9 ;
F_13 ( V_9 , V_9 -> V_17 . V_18 , V_16 ) ;
}
F_14 ( V_2 , V_15 , V_16 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_20 )
{
if ( V_20 == V_21 )
F_16 ( V_2 , V_22 , V_5 ) ;
F_17 ( V_2 , V_20 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_23 )
{
F_19 ( V_2 , V_23 ) ;
if ( V_2 -> V_9 -> V_24 & V_25 )
F_1 ( V_2 ) ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
int V_32 ;
V_32 = F_24 ( V_2 ) ;
if ( V_2 -> V_33 != V_34 )
F_25 ( V_2 -> V_9 ) ;
F_26 ( V_31 -> V_35 ) ;
F_26 ( V_31 -> V_36 ) ;
F_26 ( V_31 -> V_37 ) ;
return V_32 ;
}
static int F_27 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
int V_32 ;
V_32 = F_28 ( V_31 -> V_37 ) ;
if ( V_32 ) {
F_29 ( V_27 , L_2 ) ;
return V_32 ;
}
V_32 = F_28 ( V_31 -> V_36 ) ;
if ( V_32 ) {
F_29 ( V_27 , L_3 ) ;
return V_32 ;
}
V_32 = F_28 ( V_31 -> V_35 ) ;
if ( V_32 ) {
F_29 ( V_27 , L_4 ) ;
return V_32 ;
}
return F_30 ( V_2 ) ;
}
static int F_31 ( struct V_38 * V_39 )
{
const struct V_40 * V_41 ;
const struct V_42 * V_43 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
unsigned int V_44 , V_45 ;
unsigned int V_46 , V_47 ;
unsigned int V_48 , V_49 ;
int V_32 ;
unsigned int V_50 ;
V_41 = F_32 ( V_51 , & V_39 -> V_27 ) ;
if ( ! V_41 )
return - V_52 ;
V_43 = V_41 -> V_53 ;
V_2 = F_33 ( V_39 , V_43 , sizeof( * V_31 ) ) ;
if ( F_12 ( V_2 ) )
return F_34 ( V_2 ) ;
V_29 = F_22 ( V_2 ) ;
V_31 = F_23 ( V_29 ) ;
V_31 -> V_37 = F_35 ( & V_39 -> V_27 , L_5 ) ;
if ( F_12 ( V_31 -> V_37 ) ) {
F_29 ( & V_39 -> V_27 , L_6 ) ;
return F_34 ( V_31 -> V_37 ) ;
}
V_31 -> V_36 = F_35 ( & V_39 -> V_27 , L_7 ) ;
if ( F_12 ( V_31 -> V_36 ) ) {
F_29 ( & V_39 -> V_27 , L_8 ) ;
return F_34 ( V_31 -> V_36 ) ;
}
V_31 -> V_35 = F_35 ( & V_39 -> V_27 , L_9 ) ;
if ( F_12 ( V_31 -> V_35 ) ) {
F_29 ( & V_39 -> V_27 , L_10 ) ;
return F_34 ( V_31 -> V_35 ) ;
}
F_28 ( V_31 -> V_36 ) ;
V_44 = F_36 ( V_2 -> V_4 + V_54 ) ;
V_45 = F_36 ( V_2 -> V_4 + V_55 ) ;
V_46 = ( V_44 & V_56 ) >> V_57 ;
V_47 = ( V_45 & V_58 ) >> V_59 ;
V_48 = V_46 * 1000000 * ( V_47 + 1 ) ;
V_32 = F_37 ( V_31 -> V_35 , V_48 ) ;
if ( V_32 < 0 ) {
F_29 ( & V_39 -> V_27 , L_11 ) ;
goto V_60;
}
V_49 = F_38 ( V_31 -> V_35 ) ;
if ( V_49 != V_48 ) {
V_47 = V_49 / ( V_46 * 1000000 ) - 1 ;
V_45 &= ( ~ V_58 ) ;
V_45 |= ( ( V_47 << V_59 ) & V_58 ) ;
F_39 ( V_61 | V_62 , V_2 -> V_4 + V_63 ) ;
F_39 ( V_45 , V_2 -> V_4 + V_55 ) ;
F_39 ( 0 , V_2 -> V_4 + V_63 ) ;
F_40 ( & V_39 -> V_27 , L_12 ,
V_47 , V_49 ) ;
}
V_50 = F_41 ( V_49 , 24000000 ) - 1 ;
F_42 ( V_64 | V_50 ,
V_2 -> V_4 + V_65 ) ;
V_50 = F_41 ( V_49 , 50000000 ) - 1 ;
F_42 ( V_64 | V_50 ,
V_2 -> V_4 + V_66 ) ;
V_50 = F_41 ( V_49 , 100000000 ) - 1 ;
F_42 ( V_64 | V_50 ,
V_2 -> V_4 + V_67 ) ;
V_50 = F_41 ( V_49 , 120000000 ) - 1 ;
F_42 ( V_64 | V_50 ,
V_2 -> V_4 + V_68 ) ;
V_50 = F_41 ( V_49 , 50000000 ) - 1 ;
F_42 ( V_64 | V_50 ,
V_2 -> V_4 + V_69 ) ;
F_28 ( V_31 -> V_37 ) ;
F_28 ( V_31 -> V_35 ) ;
V_32 = F_43 ( V_2 -> V_9 ) ;
if ( V_32 )
goto V_70;
F_44 ( V_39 ) ;
F_45 ( & V_39 -> V_27 ) ;
F_46 ( & V_39 -> V_27 ) ;
F_47 ( & V_39 -> V_27 ) ;
F_48 ( & V_39 -> V_27 , 50 ) ;
F_49 ( & V_39 -> V_27 ) ;
V_32 = F_50 ( V_2 ) ;
if ( V_32 )
goto V_71;
if ( F_51 ( V_2 -> V_9 ) &&
F_52 ( V_2 -> V_9 ) < 0 ) {
V_2 -> V_9 -> V_24 |= V_72 ;
V_2 -> V_73 &= ~ V_74 ;
}
if ( V_2 -> V_9 -> V_24 & V_25 )
F_1 ( V_2 ) ;
F_53 ( & V_39 -> V_27 ) ;
return 0 ;
V_71:
V_71 ( & V_39 -> V_27 ) ;
F_54 ( & V_39 -> V_27 ) ;
F_55 ( & V_39 -> V_27 ) ;
V_70:
F_26 ( V_31 -> V_35 ) ;
F_26 ( V_31 -> V_37 ) ;
V_60:
F_26 ( V_31 -> V_36 ) ;
F_56 ( V_39 ) ;
return V_32 ;
}
static int F_57 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_58 ( V_39 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
struct V_7 * V_35 = V_31 -> V_35 ;
struct V_7 * V_36 = V_31 -> V_36 ;
struct V_7 * V_37 = V_31 -> V_37 ;
F_59 ( & V_39 -> V_27 ) ;
V_71 ( & V_39 -> V_27 ) ;
F_55 ( & V_39 -> V_27 ) ;
F_60 ( V_39 ) ;
F_26 ( V_35 ) ;
F_26 ( V_36 ) ;
F_26 ( V_37 ) ;
return 0 ;
}
