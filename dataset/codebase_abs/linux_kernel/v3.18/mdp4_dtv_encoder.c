static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
struct V_10 * V_6 = V_9 -> V_11 . V_6 ;
struct V_12 * V_13 = F_5 ( L_1 ) ;
if ( ! V_13 ) {
F_6 ( V_6 -> V_6 , L_2 ) ;
return;
}
if ( V_13 -> V_14 ) {
V_9 -> V_15 = F_7 (
V_13 -> V_14 ) ;
F_8 ( L_3 , V_9 -> V_15 ) ;
F_8 ( L_4 , V_13 -> V_16 ) ;
if ( V_13 -> V_16 )
V_13 -> V_16 ( 1 ) ;
}
}
static void F_9 ( struct V_9 * V_9 )
{
if ( V_9 -> V_15 ) {
F_10 ( V_9 -> V_15 ) ;
V_9 -> V_15 = 0 ;
}
}
static void F_11 ( struct V_9 * V_9 , int V_17 )
{
if ( V_9 -> V_15 ) {
F_8 ( L_5 , V_17 ) ;
F_12 ( V_9 -> V_15 , V_17 ) ;
}
}
static void F_4 ( struct V_9 * V_9 ) {}
static void F_9 ( struct V_9 * V_9 ) {}
static void F_11 ( struct V_9 * V_9 , int V_17 ) {}
static void F_13 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_14 ( V_3 ) ;
F_9 ( V_9 ) ;
F_15 ( V_3 ) ;
F_16 ( V_9 ) ;
}
static void F_17 ( struct V_2 * V_3 , int V_18 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
bool V_19 = ( V_18 == V_20 ) ;
F_8 ( L_6 , V_18 ) ;
if ( V_19 == V_9 -> V_19 )
return;
if ( V_19 ) {
unsigned long V_21 = V_9 -> V_22 ;
int V_23 ;
F_11 ( V_9 , 1 ) ;
F_8 ( L_7 , V_21 ) ;
V_23 = F_18 ( V_9 -> V_24 , V_21 ) ;
if ( V_23 )
F_6 ( V_6 -> V_6 , L_8 , V_21 , V_23 ) ;
F_19 ( V_9 -> V_24 ) ;
V_23 = F_19 ( V_9 -> V_25 ) ;
if ( V_23 )
F_6 ( V_6 -> V_6 , L_9 , V_23 ) ;
V_23 = F_19 ( V_9 -> V_26 ) ;
if ( V_23 )
F_6 ( V_6 -> V_6 , L_10 , V_23 ) ;
F_20 ( V_1 , V_27 , 1 ) ;
} else {
F_20 ( V_1 , V_27 , 0 ) ;
F_21 ( & V_1 -> V_11 , V_28 ) ;
F_22 ( V_9 -> V_24 ) ;
F_22 ( V_9 -> V_25 ) ;
F_22 ( V_9 -> V_26 ) ;
F_11 ( V_9 , 0 ) ;
}
V_9 -> V_19 = V_19 ;
}
static bool F_23 ( struct V_2 * V_3 ,
const struct V_29 * V_18 ,
struct V_29 * V_30 )
{
return true ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_29 * V_18 ,
struct V_29 * V_30 )
{
struct V_9 * V_9 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_31 , V_32 , V_33 , V_34 ;
T_1 V_35 , V_36 ;
T_1 V_37 , V_38 ;
V_18 = V_30 ;
F_8 ( L_11 ,
V_18 -> V_11 . V_39 , V_18 -> V_40 ,
V_18 -> V_41 , V_18 -> clock ,
V_18 -> V_42 , V_18 -> V_43 ,
V_18 -> V_44 , V_18 -> V_45 ,
V_18 -> V_46 , V_18 -> V_47 ,
V_18 -> V_48 , V_18 -> V_49 ,
V_18 -> type , V_18 -> V_50 ) ;
V_9 -> V_22 = V_18 -> clock * 1000 ;
F_8 ( L_12 , V_9 -> V_22 ) ;
V_34 = 0 ;
if ( V_18 -> V_50 & V_51 )
V_34 |= V_52 ;
if ( V_18 -> V_50 & V_53 )
V_34 |= V_54 ;
V_31 = 0 ;
V_37 = ( V_18 -> V_45 - V_18 -> V_43 ) ;
V_38 = V_18 -> V_45 - ( V_18 -> V_43 - V_18 -> V_42 ) - 1 ;
V_32 = V_18 -> V_49 * V_18 -> V_45 ;
V_33 = ( V_18 -> V_48 - V_18 -> V_47 ) * V_18 -> V_45 ;
V_35 = ( V_18 -> V_49 - V_18 -> V_47 ) * V_18 -> V_45 + V_31 ;
V_36 = V_32 - ( ( V_18 -> V_47 - V_18 -> V_46 ) * V_18 -> V_45 ) + V_31 - 1 ;
F_20 ( V_1 , V_55 ,
F_25 ( V_18 -> V_44 - V_18 -> V_43 ) |
F_26 ( V_18 -> V_45 ) ) ;
F_20 ( V_1 , V_56 , V_32 ) ;
F_20 ( V_1 , V_57 , V_33 ) ;
F_20 ( V_1 , V_58 ,
F_27 ( V_37 ) |
F_28 ( V_38 ) ) ;
F_20 ( V_1 , V_59 , V_35 ) ;
F_20 ( V_1 , V_60 , V_36 ) ;
F_20 ( V_1 , V_61 , 0 ) ;
F_20 ( V_1 , V_62 ,
V_63 |
F_29 ( 0xff ) ) ;
F_20 ( V_1 , V_64 , V_31 ) ;
F_20 ( V_1 , V_65 , V_34 ) ;
F_20 ( V_1 , V_66 ,
F_30 ( 0 ) |
F_31 ( 0 ) ) ;
F_20 ( V_1 , V_67 , 0 ) ;
F_20 ( V_1 , V_68 , 0 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
F_17 ( V_3 , V_69 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
F_34 ( V_3 -> V_70 ,
F_35 ( V_71 ) |
F_36 ( V_71 ) |
F_37 ( V_71 ) |
F_38 ( 0x21 ) ) ;
F_39 ( V_3 -> V_70 , V_72 , 1 ) ;
F_17 ( V_3 , V_20 ) ;
}
long F_40 ( struct V_2 * V_3 , unsigned long V_73 )
{
struct V_9 * V_9 = F_14 ( V_3 ) ;
return F_41 ( V_9 -> V_24 , V_73 ) ;
}
struct V_2 * F_42 ( struct V_10 * V_6 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_23 ;
V_9 = F_43 ( sizeof( * V_9 ) , V_74 ) ;
if ( ! V_9 ) {
V_23 = - V_75 ;
goto V_76;
}
V_3 = & V_9 -> V_11 ;
F_44 ( V_6 , V_3 , & V_77 ,
V_78 ) ;
F_45 ( V_3 , & V_79 ) ;
V_9 -> V_24 = F_46 ( V_6 -> V_6 , L_13 ) ;
if ( F_47 ( V_9 -> V_24 ) ) {
F_6 ( V_6 -> V_6 , L_14 ) ;
V_23 = F_48 ( V_9 -> V_24 ) ;
goto V_76;
}
V_9 -> V_25 = F_46 ( V_6 -> V_6 , L_15 ) ;
if ( F_47 ( V_9 -> V_25 ) ) {
F_6 ( V_6 -> V_6 , L_16 ) ;
V_23 = F_48 ( V_9 -> V_25 ) ;
goto V_76;
}
V_9 -> V_26 = F_46 ( V_6 -> V_6 , L_17 ) ;
if ( F_47 ( V_9 -> V_26 ) ) {
F_6 ( V_6 -> V_6 , L_18 ) ;
V_23 = F_48 ( V_9 -> V_26 ) ;
goto V_76;
}
F_4 ( V_9 ) ;
return V_3 ;
V_76:
if ( V_3 )
F_13 ( V_3 ) ;
return F_49 ( V_23 ) ;
}
