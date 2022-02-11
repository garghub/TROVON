static inline bool F_1 ( unsigned long V_1 , unsigned long V_2 )
{
return ( ! ( V_1 & V_3 ) &&
! ( V_2 & V_3 ) ) ;
}
static void F_2 ( unsigned long V_4 )
{
unsigned long V_1 ;
unsigned long V_2 ;
bool V_5 ;
V_1 = F_3 ( V_6 . V_7 + V_8 ) ;
V_2 = F_3 ( V_6 . V_7 + V_9 ) ;
V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_5 ) {
if ( V_6 . V_10 == ( 1 << V_6 . V_11 ) ) {
V_6 . V_12 >>= V_6 . V_11 ;
V_6 . V_13 >>= V_6 . V_11 ;
F_4 ( V_6 . V_14 , L_1 ,
V_15 , V_6 . V_12 , V_6 . V_13 , V_6 . V_10 ) ;
F_5 ( V_6 . V_16 , V_17 , V_6 . V_12 ) ;
F_5 ( V_6 . V_16 , V_18 , V_6 . V_13 ) ;
F_6 ( V_6 . V_16 , V_19 , 1 ) ;
F_7 ( V_6 . V_16 ) ;
V_6 . V_12 = 0 ;
V_6 . V_13 = 0 ;
V_6 . V_10 = 0 ;
}
F_8 ( V_6 . V_20 , 0 , 1 << V_6 . V_11 ) ;
} else {
V_6 . V_12 = 0 ;
V_6 . V_13 = 0 ;
V_6 . V_10 = 0 ;
F_6 ( V_6 . V_16 , V_19 , 0 ) ;
F_7 ( V_6 . V_16 ) ;
F_9 ( V_21 | V_22 , V_6 . V_7 + V_23 ) ;
}
}
static T_1 F_10 ( int V_24 , void * V_25 )
{
unsigned long V_1 ;
unsigned long V_2 ;
bool V_5 ;
V_1 = F_3 ( V_6 . V_7 + V_8 ) ;
V_2 = F_3 ( V_6 . V_7 + V_9 ) ;
V_5 = F_1 ( V_1 , V_2 ) ;
if ( V_5 )
F_8 ( V_6 . V_20 , 0 , 1 << V_6 . V_11 ) ;
else
F_4 ( V_6 . V_14 , L_2 , V_15 , V_6 . V_10 ) ;
if ( V_6 . V_26 & V_27 ) {
F_9 ( 0x0 , V_6 . V_7 + V_28 ) ;
}
return V_29 ;
}
static void F_11 ( struct V_30 * V_20 ,
unsigned V_1 , unsigned V_2 ,
unsigned * V_31 )
{
F_4 ( V_6 . V_14 , L_3 , V_15 , V_1 , V_2 ) ;
V_6 . V_12 += V_1 ;
V_6 . V_13 += V_2 ;
V_6 . V_10 ++ ;
}
static void F_12 ( struct V_30 * V_20 , unsigned V_32 )
{
if ( V_32 ) {
F_9 ( V_33 | V_34 ,
V_6 . V_7 + V_23 ) ;
} else {
F_13 ( & V_35 , V_36 + 1 ) ;
F_9 ( V_21 | V_37 , V_6 . V_7 + V_23 ) ;
}
}
static int T_2 F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_14 = & V_39 -> V_14 ;
struct V_43 * V_43 ;
struct V_44 * V_45 ;
int V_46 = - V_47 ;
memset ( & V_6 , 0 , sizeof( struct V_48 ) ) ;
V_6 . V_14 = V_14 ;
V_41 = V_39 -> V_14 . V_49 ;
if ( ! V_41 ) {
F_15 ( V_14 , L_4 ) ;
return - V_47 ;
}
F_4 ( V_14 , L_5 ) ;
V_6 . clock = F_16 ( V_14 , L_6 ) ;
if ( F_17 ( V_6 . clock ) ) {
F_15 ( V_14 , L_7 ) ;
return - V_50 ;
}
F_18 ( V_6 . clock ) ;
F_4 ( V_14 , L_8 ) ;
V_6 . V_51 = V_46 = F_19 ( V_39 , 0 ) ;
if ( V_46 < 0 ) {
F_15 ( V_14 , L_9 ) ;
goto V_52;
}
V_45 = F_20 ( V_39 , V_53 , 0 ) ;
if ( ! V_45 ) {
F_15 ( V_14 , L_10 ) ;
V_46 = - V_50 ;
goto V_52;
}
V_6 . V_7 = F_21 ( V_45 -> V_54 , F_22 ( V_45 ) ) ;
if ( V_6 . V_7 == NULL ) {
F_15 ( V_14 , L_11 ) ;
V_46 = - V_55 ;
goto V_52;
}
if ( V_41 -> V_56 )
V_41 -> V_56 ( F_23 ( V_6 . V_14 ) ) ;
V_6 . V_20 = F_24 ( V_39 , F_12 ,
F_11 , 1 ) ;
if ( F_17 ( V_6 . V_20 ) ) {
F_15 ( V_14 , L_12 ) ;
V_46 = F_25 ( V_6 . V_20 ) ;
goto V_57;
}
if ( ( V_41 -> V_58 & 0xffff ) > 0 )
F_9 ( V_41 -> V_58 & 0xffff , V_6 . V_7 + V_59 ) ;
F_9 ( V_21 | V_22 , V_6 . V_7 + V_23 ) ;
V_43 = F_26 () ;
if ( ! V_43 ) {
F_15 ( V_14 , L_13 ) ;
V_46 = - V_55 ;
goto V_57;
}
V_6 . V_16 = V_43 ;
V_6 . V_16 -> V_60 [ 0 ] = F_27 ( V_61 ) | F_27 ( V_62 ) ;
V_6 . V_16 -> V_63 [ F_28 ( V_19 ) ] = F_27 ( V_19 ) ;
F_29 ( V_6 . V_16 , V_17 , 0 , 0x3FF , 0 , 0 ) ;
F_29 ( V_6 . V_16 , V_18 , 0 , 0x3FF , 0 , 0 ) ;
V_6 . V_16 -> V_64 = L_14 ;
V_6 . V_16 -> V_65 . V_66 = V_67 ;
V_6 . V_16 -> V_65 . V_68 = 0xDEAD ;
V_6 . V_16 -> V_65 . V_69 = 0xBEEF ;
V_6 . V_16 -> V_65 . V_70 = 0x0102 ;
V_6 . V_11 = V_41 -> V_71 ;
V_6 . V_26 = F_30 ( V_39 ) -> V_72 ;
V_46 = F_31 ( V_6 . V_51 , F_10 , 0 ,
L_15 , V_6 . V_16 ) ;
if ( V_46 ) {
F_15 ( V_14 , L_16 ) ;
goto V_73;
}
F_32 ( V_14 , L_17 ) ;
V_46 = F_33 ( V_6 . V_16 ) ;
if ( V_46 < 0 ) {
F_15 ( V_14 , L_18 ) ;
V_46 = - V_74 ;
goto V_75;
}
return 0 ;
V_75:
F_34 ( V_6 . V_51 , V_6 . V_16 ) ;
V_73:
F_35 ( V_6 . V_16 ) ;
V_57:
F_36 ( V_6 . V_7 ) ;
V_52:
F_37 ( & V_35 ) ;
F_38 ( V_6 . clock ) ;
return V_46 ;
}
static int T_3 F_39 ( struct V_38 * V_39 )
{
F_34 ( V_6 . V_51 , V_6 . V_16 ) ;
F_37 ( & V_35 ) ;
F_40 ( V_6 . clock ) ;
F_38 ( V_6 . clock ) ;
F_41 ( V_6 . V_16 ) ;
F_36 ( V_6 . V_7 ) ;
return 0 ;
}
static int F_42 ( struct V_42 * V_14 )
{
F_9 ( V_76 , V_6 . V_7 + V_23 ) ;
F_43 ( V_6 . V_51 ) ;
F_40 ( V_6 . clock ) ;
return 0 ;
}
static int F_44 ( struct V_42 * V_14 )
{
struct V_38 * V_39 = F_23 ( V_14 ) ;
struct V_40 * V_41 = V_39 -> V_14 . V_49 ;
F_18 ( V_6 . clock ) ;
F_45 ( V_6 . V_51 ) ;
if ( ( V_41 -> V_58 & 0xffff ) > 0 )
F_9 ( V_41 -> V_58 & 0xffff , V_6 . V_7 + V_59 ) ;
F_9 ( V_21 | V_22 , V_6 . V_7 + V_23 ) ;
return 0 ;
}
