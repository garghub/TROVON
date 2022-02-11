static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 ) {
unsigned long V_6 = F_3 ( V_5 -> V_7 ) ;
T_1 V_8 = V_6 / 10000 ;
F_4 ( V_8 , V_5 -> V_9 + V_10 ) ;
F_4 ( V_11 | ( V_12 << 4 ) ,
V_5 -> V_9 + V_13 ) ;
F_4 ( V_14 | V_15 ,
V_5 -> V_9 + V_16 ) ;
F_4 ( F_5 ( 5 ) | F_5 ( 7 ) , V_5 -> V_9 + V_17 ) ;
F_4 ( V_18 | V_19 | V_20 ,
V_5 -> V_9 + V_21 ) ;
F_4 ( V_22 | V_23 | V_24 ,
V_5 -> V_9 + V_25 ) ;
F_4 ( 0 , V_5 -> V_9 + V_26 ) ;
F_4 ( 0x0 , V_5 -> V_9 + V_27 ) ;
F_4 ( V_28 | V_29 |
V_30 | V_31 |
V_32 ,
V_5 -> V_9 + V_33 ) ;
} else {
F_4 ( 0 , V_5 -> V_9 + V_26 ) ;
F_4 ( 0x0 , V_5 -> V_9 + V_27 ) ;
F_4 ( 0 , V_5 -> V_9 + V_33 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_34 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_35 = F_7 ( V_5 -> V_9 + V_26 ) ;
V_35 |= 1 << V_34 ;
if ( V_34 == V_36 )
V_35 = 0 ;
F_4 ( V_35 , V_5 -> V_9 + V_26 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_37 ,
T_1 V_38 , struct V_39 * V_40 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_40 -> V_42 ; V_41 ++ )
F_9 ( V_40 -> V_40 [ V_41 ] , V_5 -> V_9 + V_43 + V_41 ) ;
F_4 ( V_44 | V_45 | V_46 |
V_40 -> V_42 , V_5 -> V_9 + V_47 ) ;
return 0 ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_48 )
{
if ( V_48 & V_49 ) {
F_11 ( V_5 -> V_2 , V_50 ) ;
return;
}
if ( V_48 & V_51 ) {
F_11 ( V_5 -> V_2 , V_52 ) ;
return;
}
if ( ! ( V_48 & V_53 ) ) {
F_11 ( V_5 -> V_2 , V_54 ) ;
return;
}
F_11 ( V_5 -> V_2 , V_55 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_48 )
{
struct V_39 V_40 = {} ;
T_2 V_41 ;
if ( V_48 & V_56 )
return;
if ( V_48 & V_57 )
return;
V_40 . V_42 = F_7 ( V_5 -> V_9 + V_58 ) & 0x1f ;
if ( ! V_40 . V_42 )
return;
if ( V_40 . V_42 > 16 )
V_40 . V_42 = 16 ;
for ( V_41 = 0 ; V_41 < V_40 . V_42 ; V_41 ++ )
V_40 . V_40 [ V_41 ] = F_7 ( V_5 -> V_9 + V_59 + V_41 ) ;
F_13 ( V_5 -> V_2 , & V_40 ) ;
}
static T_3 F_14 ( int V_60 , void * V_61 )
{
struct V_4 * V_5 = V_61 ;
if ( V_5 -> V_62 & V_63 )
F_10 ( V_5 , V_5 -> V_62 ) ;
if ( V_5 -> V_62 & V_64 )
F_12 ( V_5 , V_5 -> V_62 ) ;
V_5 -> V_62 = 0 ;
return V_65 ;
}
static T_3 F_15 ( int V_60 , void * V_61 )
{
struct V_4 * V_5 = V_61 ;
V_5 -> V_62 = F_7 ( V_5 -> V_9 + V_27 ) ;
F_4 ( V_5 -> V_62 , V_5 -> V_9 + V_27 ) ;
return V_66 ;
}
static int F_16 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = & V_68 -> V_70 ;
struct V_71 * V_72 ;
struct V_4 * V_5 ;
struct V_73 * V_74 ;
struct V_67 * V_75 ;
int V_76 ;
V_5 = F_17 ( V_70 , sizeof( * V_5 ) , V_77 ) ;
if ( ! V_5 )
return - V_78 ;
V_74 = F_18 ( V_68 -> V_70 . V_79 , L_1 , 0 ) ;
if ( ! V_74 ) {
F_19 ( & V_68 -> V_70 , L_2 ) ;
return - V_80 ;
}
V_75 = F_20 ( V_74 ) ;
if ( ! V_75 )
return - V_81 ;
V_5 -> V_82 = F_21 ( & V_75 -> V_70 ) ;
if ( ! V_5 -> V_82 )
return - V_78 ;
V_5 -> V_70 = V_70 ;
V_72 = F_22 ( V_68 , V_83 , 0 ) ;
V_5 -> V_9 = F_23 ( V_70 , V_72 ) ;
if ( F_24 ( V_5 -> V_9 ) )
return F_25 ( V_5 -> V_9 ) ;
V_5 -> V_60 = F_26 ( V_68 , 0 ) ;
if ( V_5 -> V_60 < 0 )
return V_5 -> V_60 ;
V_76 = F_27 ( V_70 , V_5 -> V_60 , F_15 ,
F_14 , 0 ,
V_68 -> V_84 , V_5 ) ;
if ( V_76 )
return V_76 ;
V_5 -> V_7 = F_28 ( V_70 , L_3 ) ;
if ( F_24 ( V_5 -> V_7 ) ) {
F_19 ( V_70 , L_4 ) ;
return F_25 ( V_5 -> V_7 ) ;
}
V_5 -> V_2 = F_29 ( & V_85 , V_5 ,
V_86 ,
V_87 | V_88 |
V_89 , V_90 ) ;
V_76 = F_30 ( V_5 -> V_2 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_31 ( V_5 -> V_2 , & V_68 -> V_70 ) ;
if ( V_76 ) {
F_32 ( V_5 -> V_2 ) ;
return V_76 ;
}
F_33 ( V_5 -> V_2 , V_5 -> V_82 ) ;
F_34 ( V_68 , V_5 ) ;
return 0 ;
}
static int F_35 ( struct V_67 * V_68 )
{
struct V_4 * V_5 = F_36 ( V_68 ) ;
F_37 ( V_5 -> V_2 ) ;
F_38 ( V_5 -> V_82 ) ;
return 0 ;
}
