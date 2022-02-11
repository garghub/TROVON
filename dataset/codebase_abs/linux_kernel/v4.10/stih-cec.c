static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 ) {
unsigned long V_7 = F_2 ( V_5 -> V_8 ) ;
T_1 V_9 = V_7 / 10000 ;
F_3 ( V_9 , V_5 -> V_10 + V_11 ) ;
F_3 ( V_12 | ( V_13 << 4 ) ,
V_5 -> V_10 + V_14 ) ;
F_3 ( V_15 | V_16 ,
V_5 -> V_10 + V_17 ) ;
F_3 ( F_4 ( 5 ) | F_4 ( 7 ) , V_5 -> V_10 + V_18 ) ;
F_3 ( V_19 | V_20 | V_21 ,
V_5 -> V_10 + V_22 ) ;
F_3 ( V_23 | V_24 | V_25 ,
V_5 -> V_10 + V_26 ) ;
F_3 ( 0 , V_5 -> V_10 + V_27 ) ;
F_3 ( 0x0 , V_5 -> V_10 + V_28 ) ;
F_3 ( V_29 | V_30 |
V_31 | V_32 |
V_33 ,
V_5 -> V_10 + V_34 ) ;
} else {
F_3 ( 0 , V_5 -> V_10 + V_27 ) ;
F_3 ( 0x0 , V_5 -> V_10 + V_28 ) ;
F_3 ( 0 , V_5 -> V_10 + V_34 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_35 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_36 = F_6 ( V_5 -> V_10 + V_27 ) ;
V_36 |= 1 << V_35 ;
if ( V_35 == V_37 )
V_36 = 0 ;
F_3 ( V_36 , V_5 -> V_10 + V_27 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_38 ,
T_1 V_39 , struct V_40 * V_41 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 -> V_43 ; V_42 ++ )
F_8 ( V_41 -> V_41 [ V_42 ] , V_5 -> V_10 + V_44 + V_42 ) ;
F_3 ( V_45 | V_46 | V_47 |
V_41 -> V_43 , V_5 -> V_10 + V_48 ) ;
return 0 ;
}
static void F_9 ( struct V_4 * V_5 , T_1 V_49 )
{
if ( V_49 & V_50 ) {
F_10 ( V_5 -> V_2 , V_51 , 0 , 0 , 0 , 1 ) ;
return;
}
if ( V_49 & V_52 ) {
F_10 ( V_5 -> V_2 ,
V_53 , 1 , 0 , 0 , 0 ) ;
return;
}
if ( ! ( V_49 & V_54 ) ) {
F_10 ( V_5 -> V_2 , V_55 , 0 , 1 , 0 , 0 ) ;
return;
}
F_10 ( V_5 -> V_2 , V_56 , 0 , 0 , 0 , 0 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_49 )
{
struct V_40 V_41 = {} ;
T_2 V_42 ;
if ( V_49 & V_57 )
return;
if ( V_49 & V_58 )
return;
V_41 . V_43 = F_6 ( V_5 -> V_10 + V_59 ) & 0x1f ;
if ( ! V_41 . V_43 )
return;
if ( V_41 . V_43 > 16 )
V_41 . V_43 = 16 ;
for ( V_42 = 0 ; V_42 < V_41 . V_43 ; V_42 ++ )
V_41 . V_41 [ V_42 ] = F_6 ( V_5 -> V_10 + V_60 + V_42 ) ;
F_12 ( V_5 -> V_2 , & V_41 ) ;
}
static T_3 F_13 ( int V_61 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
if ( V_5 -> V_62 & V_63 )
F_9 ( V_5 , V_5 -> V_62 ) ;
if ( V_5 -> V_62 & V_64 )
F_11 ( V_5 , V_5 -> V_62 ) ;
V_5 -> V_62 = 0 ;
return V_65 ;
}
static T_3 F_14 ( int V_61 , void * V_6 )
{
struct V_4 * V_5 = V_6 ;
V_5 -> V_62 = F_6 ( V_5 -> V_10 + V_28 ) ;
F_3 ( V_5 -> V_62 , V_5 -> V_10 + V_28 ) ;
return V_66 ;
}
static int F_15 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = & V_68 -> V_70 ;
struct V_71 * V_72 ;
struct V_4 * V_5 ;
int V_73 ;
V_5 = F_16 ( V_70 , sizeof( * V_5 ) , V_74 ) ;
if ( ! V_5 )
return - V_75 ;
V_5 -> V_70 = V_70 ;
V_72 = F_17 ( V_68 , V_76 , 0 ) ;
V_5 -> V_10 = F_18 ( V_70 , V_72 ) ;
if ( F_19 ( V_5 -> V_10 ) )
return F_20 ( V_5 -> V_10 ) ;
V_5 -> V_61 = F_21 ( V_68 , 0 ) ;
if ( V_5 -> V_61 < 0 )
return V_5 -> V_61 ;
V_73 = F_22 ( V_70 , V_5 -> V_61 , F_14 ,
F_13 , 0 ,
V_68 -> V_77 , V_5 ) ;
if ( V_73 )
return V_73 ;
V_5 -> V_8 = F_23 ( V_70 , L_1 ) ;
if ( F_19 ( V_5 -> V_8 ) ) {
F_24 ( V_70 , L_2 ) ;
return F_20 ( V_5 -> V_8 ) ;
}
V_5 -> V_2 = F_25 ( & V_78 , V_5 ,
V_79 ,
V_80 | V_81 |
V_82 | V_83 , 1 ) ;
V_73 = F_26 ( V_5 -> V_2 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_27 ( V_5 -> V_2 , & V_68 -> V_70 ) ;
if ( V_73 ) {
F_28 ( V_5 -> V_2 ) ;
return V_73 ;
}
F_29 ( V_68 , V_5 ) ;
return 0 ;
}
static int F_30 ( struct V_67 * V_68 )
{
return 0 ;
}
