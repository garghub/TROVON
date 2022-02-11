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
static void F_17 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
struct V_18 * V_20 )
{
struct V_9 * V_9 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_21 , V_22 , V_23 , V_24 ;
T_1 V_25 , V_26 ;
T_1 V_27 , V_28 ;
V_19 = V_20 ;
F_8 ( L_6 ,
V_19 -> V_11 . V_29 , V_19 -> V_30 ,
V_19 -> V_31 , V_19 -> clock ,
V_19 -> V_32 , V_19 -> V_33 ,
V_19 -> V_34 , V_19 -> V_35 ,
V_19 -> V_36 , V_19 -> V_37 ,
V_19 -> V_38 , V_19 -> V_39 ,
V_19 -> type , V_19 -> V_40 ) ;
V_9 -> V_41 = V_19 -> clock * 1000 ;
F_8 ( L_7 , V_9 -> V_41 ) ;
V_24 = 0 ;
if ( V_19 -> V_40 & V_42 )
V_24 |= V_43 ;
if ( V_19 -> V_40 & V_44 )
V_24 |= V_45 ;
V_21 = 0 ;
V_27 = ( V_19 -> V_35 - V_19 -> V_33 ) ;
V_28 = V_19 -> V_35 - ( V_19 -> V_33 - V_19 -> V_32 ) - 1 ;
V_22 = V_19 -> V_39 * V_19 -> V_35 ;
V_23 = ( V_19 -> V_38 - V_19 -> V_37 ) * V_19 -> V_35 ;
V_25 = ( V_19 -> V_39 - V_19 -> V_37 ) * V_19 -> V_35 + V_21 ;
V_26 = V_22 - ( ( V_19 -> V_37 - V_19 -> V_36 ) * V_19 -> V_35 ) + V_21 - 1 ;
F_18 ( V_1 , V_46 ,
F_19 ( V_19 -> V_34 - V_19 -> V_33 ) |
F_20 ( V_19 -> V_35 ) ) ;
F_18 ( V_1 , V_47 , V_22 ) ;
F_18 ( V_1 , V_48 , V_23 ) ;
F_18 ( V_1 , V_49 ,
F_21 ( V_27 ) |
F_22 ( V_28 ) ) ;
F_18 ( V_1 , V_50 , V_25 ) ;
F_18 ( V_1 , V_51 , V_26 ) ;
F_18 ( V_1 , V_52 , 0 ) ;
F_18 ( V_1 , V_53 ,
V_54 |
F_23 ( 0xff ) ) ;
F_18 ( V_1 , V_55 , V_21 ) ;
F_18 ( V_1 , V_56 , V_24 ) ;
F_18 ( V_1 , V_57 ,
F_24 ( 0 ) |
F_25 ( 0 ) ) ;
F_18 ( V_1 , V_58 , 0 ) ;
F_18 ( V_1 , V_59 , 0 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( F_27 ( ! V_9 -> V_60 ) )
return;
F_18 ( V_1 , V_61 , 0 ) ;
F_28 ( & V_1 -> V_11 , V_62 ) ;
F_29 ( V_9 -> V_63 ) ;
F_29 ( V_9 -> V_64 ) ;
F_11 ( V_9 , 0 ) ;
V_9 -> V_60 = false ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_65 = V_9 -> V_41 ;
int V_66 ;
if ( F_27 ( V_9 -> V_60 ) )
return;
F_31 ( V_3 -> V_67 ,
F_32 ( V_68 ) |
F_33 ( V_68 ) |
F_34 ( V_68 ) |
F_35 ( 0x21 ) ) ;
F_36 ( V_3 -> V_67 , V_69 , 1 ) ;
F_11 ( V_9 , 1 ) ;
F_8 ( L_8 , V_65 ) ;
V_66 = F_37 ( V_9 -> V_64 , V_65 ) ;
if ( V_66 )
F_6 ( V_6 -> V_6 , L_9 ,
V_65 , V_66 ) ;
V_66 = F_38 ( V_9 -> V_64 ) ;
if ( V_66 )
F_6 ( V_6 -> V_6 , L_10 , V_66 ) ;
V_66 = F_38 ( V_9 -> V_63 ) ;
if ( V_66 )
F_6 ( V_6 -> V_6 , L_11 , V_66 ) ;
F_18 ( V_1 , V_61 , 1 ) ;
V_9 -> V_60 = true ;
}
long F_39 ( struct V_2 * V_3 , unsigned long V_70 )
{
struct V_9 * V_9 = F_14 ( V_3 ) ;
return F_40 ( V_9 -> V_64 , V_70 ) ;
}
struct V_2 * F_41 ( struct V_10 * V_6 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_66 ;
V_9 = F_42 ( sizeof( * V_9 ) , V_71 ) ;
if ( ! V_9 ) {
V_66 = - V_72 ;
goto V_73;
}
V_3 = & V_9 -> V_11 ;
F_43 ( V_6 , V_3 , & V_74 ,
V_75 , NULL ) ;
F_44 ( V_3 , & V_76 ) ;
V_9 -> V_63 = F_45 ( V_6 -> V_6 , L_12 ) ;
if ( F_46 ( V_9 -> V_63 ) ) {
F_6 ( V_6 -> V_6 , L_13 ) ;
V_66 = F_47 ( V_9 -> V_63 ) ;
goto V_73;
}
V_9 -> V_64 = F_45 ( V_6 -> V_6 , L_14 ) ;
if ( F_46 ( V_9 -> V_64 ) ) {
F_6 ( V_6 -> V_6 , L_15 ) ;
V_66 = F_47 ( V_9 -> V_64 ) ;
goto V_73;
}
F_4 ( V_9 ) ;
return V_3 ;
V_73:
if ( V_3 )
F_13 ( V_3 ) ;
return F_48 ( V_66 ) ;
}
