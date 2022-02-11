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
static void F_7 ( struct V_1 * V_2 ,
int type , const struct V_10 * V_11 )
{
T_1 V_12 ;
if ( V_2 -> V_7 )
F_7 ( V_2 -> V_7 , V_13 , V_11 ) ;
F_6 ( V_11 -> V_14 , V_2 -> V_8 + V_15 ) ;
F_6 ( V_11 -> V_16 * 2 , V_2 -> V_8 + V_17 ) ;
V_12 = ( V_11 -> V_16 - V_11 -> V_18 + 1 ) << 16 ;
V_12 |= V_11 -> V_14 - V_11 -> V_19 ;
F_6 ( V_12 , V_2 -> V_8 + V_20 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_21 ) ;
V_12 = ( V_11 -> V_22 + V_11 -> V_16 - V_11 -> V_18 + 1 ) << 16 ;
V_12 |= V_11 -> V_23 + V_11 -> V_14 - V_11 -> V_19 ;
F_6 ( V_12 , V_2 -> V_8 + V_24 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_25 ) ;
V_12 = ( V_11 -> V_26 - V_11 -> V_19 + V_27 ) << 16 ;
V_12 |= V_27 ;
F_6 ( V_12 , V_2 -> V_8 + V_28 ) ;
V_12 = ( V_11 -> V_29 - V_11 -> V_18 + 1 ) << 16 ;
V_12 |= 1 ;
F_6 ( V_12 , V_2 -> V_8 + V_30 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_31 ) ;
F_6 ( 0 , V_2 -> V_8 + V_32 ) ;
F_6 ( 0 , V_2 -> V_8 + V_33 ) ;
V_12 = ( V_11 -> V_26 - V_11 -> V_19 ) << 16 ;
F_6 ( V_12 , V_2 -> V_8 + V_34 ) ;
V_12 = ( V_11 -> V_29 - V_11 -> V_18 + 1 ) << 16 ;
V_12 |= 1 ;
F_6 ( V_12 , V_2 -> V_8 + V_35 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_36 ) ;
F_6 ( 0 , V_2 -> V_8 + V_37 ) ;
F_6 ( 0 , V_2 -> V_8 + V_38 ) ;
V_12 = ( V_11 -> V_26 - V_11 -> V_19 + V_39 ) << 16 ;
V_12 |= V_11 -> V_14 + V_39 ;
F_6 ( V_12 , V_2 -> V_8 + V_40 ) ;
V_12 = ( V_11 -> V_29 - V_11 -> V_18 ) << 16 ;
V_12 |= V_11 -> V_16 ;
F_6 ( V_12 , V_2 -> V_8 + V_41 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_42 ) ;
V_12 = ( V_11 -> V_14 + V_39 ) << 16 ;
V_12 |= V_11 -> V_14 + V_39 ;
F_6 ( V_12 , V_2 -> V_8 + V_43 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_44 ) ;
V_12 = ( V_11 -> V_26 - V_11 -> V_19 ) << 16 ;
F_6 ( V_12 , V_2 -> V_8 + V_45 ) ;
V_12 = ( V_11 -> V_29 - V_11 -> V_18 + 1 ) << 16 ;
V_12 |= 1 ;
F_6 ( V_12 , V_2 -> V_8 + V_46 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_47 ) ;
F_6 ( 0 , V_2 -> V_8 + V_48 ) ;
F_6 ( 0 , V_2 -> V_8 + V_49 ) ;
F_6 ( type , V_2 -> V_8 + V_50 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( 0xFFFF , V_2 -> V_8 + V_51 ) ;
F_6 ( 0xFFFF , V_2 -> V_8 + V_52 ) ;
F_6 ( V_53 , V_2 -> V_8 + V_54 ) ;
}
void F_9 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
F_7 ( V_2 , V_55 , V_11 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_7 )
F_8 ( V_2 -> V_7 ) ;
else
F_8 ( V_2 ) ;
}
T_1 F_10 ( struct V_10 V_11 , int V_56 )
{
T_1 V_57 = V_11 . V_16 - V_11 . V_18 + 1 ;
if ( V_11 . V_58 & V_59 )
V_57 *= 2 ;
return V_57 + V_56 ;
}
T_1 F_11 ( struct V_10 V_11 , int V_60 )
{
return V_11 . V_14 - V_11 . V_19 + V_60 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_61 * V_62 , int V_63 )
{
if ( V_2 -> V_7 )
return F_12 ( V_2 -> V_7 , V_62 , V_63 ) ;
V_2 -> V_63 = V_63 ;
return F_13 ( & V_2 -> V_64 , V_62 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
if ( V_2 -> V_7 )
return F_14 ( V_2 -> V_7 , V_62 ) ;
return F_15 ( & V_2 -> V_64 , V_62 ) ;
}
static T_2 F_16 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
T_1 V_67 ;
V_67 = ( V_2 -> V_68 & V_69 ) ?
V_70 : V_71 ;
F_17 ( & V_2 -> V_64 , V_67 , & V_2 -> V_63 ) ;
return V_72 ;
}
static T_2 F_18 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
V_2 -> V_68 = F_19 ( V_2 -> V_8 + V_73 ) ;
F_6 ( V_2 -> V_68 , V_2 -> V_8 + V_51 ) ;
F_19 ( V_2 -> V_8 + V_73 ) ;
return V_74 ;
}
static int F_20 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = & V_76 -> V_78 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_79 * V_80 ;
char V_81 [ 32 ] ;
int V_82 ;
V_2 = F_21 ( V_78 , sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_78 = V_78 ;
V_2 -> V_6 = V_76 -> V_78 . V_85 ;
V_80 = F_22 ( V_76 , V_86 , 0 ) ;
if ( ! V_80 ) {
F_23 ( L_1 ) ;
return - V_84 ;
}
V_2 -> V_8 = F_24 ( V_78 , V_80 -> V_87 , F_25 ( V_80 ) ) ;
V_6 = F_26 ( V_76 -> V_78 . V_85 , L_2 , 0 ) ;
if ( V_6 ) {
V_2 -> V_7 = F_3 ( V_6 ) ;
if ( ! V_2 -> V_7 )
return - V_88 ;
} else {
V_2 -> V_65 = F_27 ( V_76 , 0 ) ;
if ( F_28 ( V_2 -> V_65 ) ) {
F_23 ( L_3 ) ;
return V_2 -> V_65 ;
}
snprintf ( V_81 , sizeof( V_81 ) , L_4 ,
F_29 ( V_2 -> V_78 ) ) ;
F_30 ( & V_2 -> V_64 ) ;
V_82 = F_31 ( V_78 , V_2 -> V_65 , F_18 ,
F_16 , V_89 , V_81 , V_2 ) ;
if ( F_28 ( V_82 ) ) {
F_23 ( L_5 ) ;
return V_82 ;
}
}
F_1 ( V_2 ) ;
F_32 ( V_76 , V_2 ) ;
F_33 ( L_6 , V_90 , F_29 ( V_2 -> V_78 ) ) ;
return 0 ;
}
static int F_34 ( struct V_75 * V_76 )
{
return 0 ;
}
