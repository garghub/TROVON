static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , & V_4 ) ;
}
struct V_1 * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_4 (vtg, &vtg_lookup, link) {
if ( V_2 -> V_6 == V_6 )
return V_2 ;
}
return NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_5 ( V_2 -> V_7 ) ;
F_6 ( 1 , V_2 -> V_8 + V_9 ) ;
}
static void F_7 ( void T_1 * V_8 ,
const struct V_10 * V_11 )
{
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
T_2 V_16 = F_8 ( * V_11 , 0 ) ;
T_2 V_17 = F_9 ( * V_11 , 0 ) ;
T_2 V_18 = F_8 ( * V_11 , V_11 -> V_19 - 1 ) ;
T_2 V_20 = F_9 ( * V_11 , V_11 -> V_21 - 1 ) ;
V_12 = ( V_17 << 16 ) | V_16 ;
V_13 = ( V_20 << 16 ) | V_18 ;
V_14 = V_12 ;
V_15 = V_13 ;
F_6 ( V_12 , V_8 + V_22 ) ;
F_6 ( V_13 , V_8 + V_23 ) ;
F_6 ( V_14 , V_8 + V_24 ) ;
F_6 ( V_15 , V_8 + V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
int type , const struct V_10 * V_11 )
{
T_2 V_26 ;
if ( V_2 -> V_7 )
F_10 ( V_2 -> V_7 , V_27 , V_11 ) ;
F_6 ( V_11 -> V_28 , V_2 -> V_8 + V_29 ) ;
F_6 ( V_11 -> V_30 * 2 , V_2 -> V_8 + V_31 ) ;
F_7 ( V_2 -> V_8 , V_11 ) ;
V_26 = ( V_11 -> V_32 - V_11 -> V_33 + V_34 ) << 16 ;
V_26 |= V_34 ;
F_6 ( V_26 , V_2 -> V_8 + V_35 ) ;
V_26 = ( V_11 -> V_36 - V_11 -> V_37 + 1 ) << 16 ;
V_26 |= 1 ;
F_6 ( V_26 , V_2 -> V_8 + V_38 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_39 ) ;
V_26 = V_34 << 16 ;
V_26 |= V_34 ;
F_6 ( V_26 , V_2 -> V_8 + V_40 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_41 ) ;
V_26 = ( V_11 -> V_32 - V_11 -> V_33 ) << 16 ;
F_6 ( V_26 , V_2 -> V_8 + V_42 ) ;
V_26 = ( V_11 -> V_36 - V_11 -> V_37 + 1 ) << 16 ;
V_26 |= 1 ;
F_6 ( V_26 , V_2 -> V_8 + V_43 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_44 ) ;
F_6 ( 0 , V_2 -> V_8 + V_45 ) ;
F_6 ( 0 , V_2 -> V_8 + V_46 ) ;
V_26 = ( V_11 -> V_32 - V_11 -> V_33 + V_47 ) << 16 ;
V_26 |= V_11 -> V_28 + V_47 ;
F_6 ( V_26 , V_2 -> V_8 + V_48 ) ;
V_26 = ( V_11 -> V_36 - V_11 -> V_37 ) << 16 ;
V_26 |= V_11 -> V_30 ;
F_6 ( V_26 , V_2 -> V_8 + V_49 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_50 ) ;
V_26 = ( V_11 -> V_28 + V_47 ) << 16 ;
V_26 |= V_11 -> V_28 + V_47 ;
F_6 ( V_26 , V_2 -> V_8 + V_51 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_52 ) ;
V_26 = ( V_11 -> V_32 - V_11 -> V_33 ) << 16 ;
F_6 ( V_26 , V_2 -> V_8 + V_53 ) ;
V_26 = ( V_11 -> V_36 - V_11 -> V_37 + 1 ) << 16 ;
V_26 |= 1 ;
F_6 ( V_26 , V_2 -> V_8 + V_54 ) ;
F_6 ( V_26 , V_2 -> V_8 + V_55 ) ;
F_6 ( 0 , V_2 -> V_8 + V_56 ) ;
F_6 ( 0 , V_2 -> V_8 + V_57 ) ;
F_6 ( type , V_2 -> V_8 + V_58 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_6 ( 0xFFFF , V_2 -> V_8 + V_59 ) ;
F_6 ( 0xFFFF , V_2 -> V_8 + V_60 ) ;
F_6 ( V_61 , V_2 -> V_8 + V_62 ) ;
}
void F_12 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
F_10 ( V_2 , V_63 , V_11 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_7 )
F_11 ( V_2 -> V_7 ) ;
else
F_11 ( V_2 ) ;
}
T_2 F_9 ( struct V_10 V_11 , int V_64 )
{
T_2 V_65 = V_11 . V_30 - V_11 . V_37 + 1 ;
if ( V_11 . V_66 & V_67 )
V_65 *= 2 ;
return V_65 + V_64 ;
}
T_2 F_8 ( struct V_10 V_11 , int V_68 )
{
return V_11 . V_28 - V_11 . V_33 + V_68 ;
}
int F_13 ( struct V_1 * V_2 , struct V_69 * V_70 ,
struct V_71 * V_72 )
{
if ( V_2 -> V_7 )
return F_13 ( V_2 -> V_7 , V_70 , V_72 ) ;
V_2 -> V_72 = V_72 ;
return F_14 ( & V_2 -> V_73 , V_70 ) ;
}
int F_15 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
if ( V_2 -> V_7 )
return F_15 ( V_2 -> V_7 , V_70 ) ;
return F_16 ( & V_2 -> V_73 , V_70 ) ;
}
static T_3 F_17 ( int V_74 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
T_2 V_76 ;
V_76 = ( V_2 -> V_77 & V_78 ) ?
V_79 : V_80 ;
F_18 ( & V_2 -> V_73 , V_76 , V_2 -> V_72 ) ;
return V_81 ;
}
static T_3 F_19 ( int V_74 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
V_2 -> V_77 = F_20 ( V_2 -> V_8 + V_82 ) ;
F_6 ( V_2 -> V_77 , V_2 -> V_8 + V_59 ) ;
F_20 ( V_2 -> V_8 + V_82 ) ;
return V_83 ;
}
static int F_21 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = & V_85 -> V_87 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_88 * V_89 ;
int V_90 ;
V_2 = F_22 ( V_87 , sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_6 = V_85 -> V_87 . V_93 ;
V_89 = F_23 ( V_85 , V_94 , 0 ) ;
if ( ! V_89 ) {
F_24 ( L_1 ) ;
return - V_92 ;
}
V_2 -> V_8 = F_25 ( V_87 , V_89 -> V_95 , F_26 ( V_89 ) ) ;
V_6 = F_27 ( V_85 -> V_87 . V_93 , L_2 , 0 ) ;
if ( V_6 ) {
V_2 -> V_7 = F_3 ( V_6 ) ;
if ( ! V_2 -> V_7 )
return - V_96 ;
} else {
V_2 -> V_74 = F_28 ( V_85 , 0 ) ;
if ( F_29 ( V_2 -> V_74 ) ) {
F_24 ( L_3 ) ;
return V_2 -> V_74 ;
}
F_30 ( & V_2 -> V_73 ) ;
V_90 = F_31 ( V_87 , V_2 -> V_74 , F_19 ,
F_17 , V_97 ,
F_32 ( V_87 ) , V_2 ) ;
if ( F_29 ( V_90 ) ) {
F_24 ( L_4 ) ;
return V_90 ;
}
}
F_1 ( V_2 ) ;
F_33 ( V_85 , V_2 ) ;
F_34 ( L_5 , V_98 , F_32 ( V_2 -> V_87 ) ) ;
return 0 ;
}
static int F_35 ( struct V_84 * V_85 )
{
return 0 ;
}
