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
unsigned int V_33 , V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_37 , V_38 ;
unsigned int V_39 ;
F_24 ( V_31 -> V_40 ) ;
V_33 = F_25 ( V_2 -> V_4 + V_41 ) ;
V_34 = F_25 ( V_2 -> V_4 + V_42 ) ;
V_35 = ( V_33 & V_43 ) >> V_44 ;
V_36 = ( V_34 & V_45 ) >> V_46 ;
V_37 = V_35 * 1000000 * ( V_36 + 1 ) ;
V_32 = F_26 ( V_31 -> V_47 , V_37 ) ;
if ( V_32 < 0 ) {
F_27 ( V_27 , L_2 ) ;
F_28 ( V_31 -> V_40 ) ;
return V_32 ;
}
V_38 = F_29 ( V_31 -> V_47 ) ;
if ( V_38 != V_37 ) {
V_36 = V_38 / ( V_35 * 1000000 ) - 1 ;
V_34 &= ( ~ V_45 ) ;
V_34 |= ( ( V_36 << V_46 ) &
V_45 ) ;
F_30 ( V_48 | V_49 ,
V_2 -> V_4 + V_50 ) ;
F_30 ( V_34 , V_2 -> V_4 + V_42 ) ;
F_30 ( 0 , V_2 -> V_4 + V_50 ) ;
F_31 ( V_27 , L_3 ,
V_36 , V_38 ) ;
}
V_39 = F_32 ( V_38 , 24000000 ) - 1 ;
F_33 ( V_51 | V_39 ,
V_2 -> V_4 + V_52 ) ;
V_39 = F_32 ( V_38 , 50000000 ) - 1 ;
F_33 ( V_51 | V_39 ,
V_2 -> V_4 + V_53 ) ;
V_39 = F_32 ( V_38 , 100000000 ) - 1 ;
F_33 ( V_51 | V_39 ,
V_2 -> V_4 + V_54 ) ;
V_39 = F_32 ( V_38 , 120000000 ) - 1 ;
F_33 ( V_51 | V_39 ,
V_2 -> V_4 + V_55 ) ;
V_39 = F_32 ( V_38 , 50000000 ) - 1 ;
F_33 ( V_51 | V_39 ,
V_2 -> V_4 + V_56 ) ;
F_24 ( V_31 -> V_57 ) ;
F_24 ( V_31 -> V_47 ) ;
return 0 ;
}
static int F_34 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
int V_32 ;
V_32 = F_35 ( V_27 ) ;
V_31 -> V_58 = true ;
return V_32 ;
}
static int F_36 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
int V_32 ;
V_32 = F_37 ( V_2 ) ;
if ( V_2 -> V_59 != V_60 )
F_38 ( V_2 -> V_9 ) ;
F_28 ( V_31 -> V_47 ) ;
F_28 ( V_31 -> V_40 ) ;
F_28 ( V_31 -> V_57 ) ;
return V_32 ;
}
static int F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( V_27 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
int V_32 ;
if ( V_31 -> V_58 ) {
V_32 = F_20 ( V_27 ) ;
if ( V_32 )
return V_32 ;
V_31 -> V_58 = false ;
goto V_61;
}
V_32 = F_24 ( V_31 -> V_57 ) ;
if ( V_32 ) {
F_27 ( V_27 , L_4 ) ;
return V_32 ;
}
V_32 = F_24 ( V_31 -> V_40 ) ;
if ( V_32 ) {
F_27 ( V_27 , L_5 ) ;
return V_32 ;
}
V_32 = F_24 ( V_31 -> V_47 ) ;
if ( V_32 ) {
F_27 ( V_27 , L_6 ) ;
return V_32 ;
}
V_61:
return F_40 ( V_2 ) ;
}
static int F_41 ( struct V_62 * V_63 )
{
const struct V_64 * V_65 ;
const struct V_66 * V_67 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_65 = F_42 ( V_68 , & V_63 -> V_27 ) ;
if ( ! V_65 )
return - V_69 ;
V_67 = V_65 -> V_70 ;
V_2 = F_43 ( V_63 , V_67 , sizeof( * V_31 ) ) ;
if ( F_12 ( V_2 ) )
return F_44 ( V_2 ) ;
V_29 = F_22 ( V_2 ) ;
V_31 = F_23 ( V_29 ) ;
V_31 -> V_57 = F_45 ( & V_63 -> V_27 , L_7 ) ;
if ( F_12 ( V_31 -> V_57 ) ) {
F_27 ( & V_63 -> V_27 , L_8 ) ;
return F_44 ( V_31 -> V_57 ) ;
}
V_31 -> V_40 = F_45 ( & V_63 -> V_27 , L_9 ) ;
if ( F_12 ( V_31 -> V_40 ) ) {
F_27 ( & V_63 -> V_27 , L_10 ) ;
return F_44 ( V_31 -> V_40 ) ;
}
V_31 -> V_47 = F_45 ( & V_63 -> V_27 , L_11 ) ;
if ( F_12 ( V_31 -> V_47 ) ) {
F_27 ( & V_63 -> V_27 , L_12 ) ;
return F_44 ( V_31 -> V_47 ) ;
}
V_32 = F_20 ( & V_63 -> V_27 ) ;
if ( V_32 )
goto V_71;
V_31 -> V_58 = false ;
V_32 = F_46 ( V_2 -> V_9 ) ;
if ( V_32 )
goto V_72;
F_47 ( V_63 ) ;
F_48 ( & V_63 -> V_27 ) ;
F_49 ( & V_63 -> V_27 ) ;
F_50 ( & V_63 -> V_27 ) ;
F_51 ( & V_63 -> V_27 , 50 ) ;
F_52 ( & V_63 -> V_27 ) ;
V_32 = F_53 ( V_2 ) ;
if ( V_32 )
goto V_73;
if ( F_54 ( V_2 -> V_9 ) &&
F_55 ( V_2 -> V_9 ) < 0 ) {
V_2 -> V_9 -> V_24 |= V_74 ;
V_2 -> V_75 &= ~ V_76 ;
}
if ( V_2 -> V_9 -> V_24 & V_25 )
F_1 ( V_2 ) ;
F_56 ( & V_63 -> V_27 ) ;
return 0 ;
V_73:
V_73 ( & V_63 -> V_27 ) ;
F_57 ( & V_63 -> V_27 ) ;
F_58 ( & V_63 -> V_27 ) ;
V_72:
F_28 ( V_31 -> V_47 ) ;
F_28 ( V_31 -> V_57 ) ;
F_28 ( V_31 -> V_40 ) ;
V_71:
V_71 ( V_63 ) ;
return V_32 ;
}
static int F_59 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_60 ( V_63 ) ;
struct V_28 * V_29 = F_22 ( V_2 ) ;
struct V_30 * V_31 = F_23 ( V_29 ) ;
struct V_7 * V_47 = V_31 -> V_47 ;
struct V_7 * V_40 = V_31 -> V_40 ;
struct V_7 * V_57 = V_31 -> V_57 ;
F_61 ( & V_63 -> V_27 ) ;
V_73 ( & V_63 -> V_27 ) ;
F_58 ( & V_63 -> V_27 ) ;
F_62 ( V_63 ) ;
F_28 ( V_47 ) ;
F_28 ( V_40 ) ;
F_28 ( V_57 ) ;
return 0 ;
}
