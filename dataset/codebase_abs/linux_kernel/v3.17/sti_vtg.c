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
V_12 = ( V_11 -> V_26 - V_11 -> V_19 ) << 16 ;
F_6 ( V_12 , V_2 -> V_8 + V_27 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_28 ) ;
V_12 = ( V_11 -> V_29 - V_11 -> V_18 + 1 ) << 16 ;
V_12 |= 1 ;
F_6 ( V_12 , V_2 -> V_8 + V_30 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_31 ) ;
F_6 ( 0 , V_2 -> V_8 + V_32 ) ;
F_6 ( 0 , V_2 -> V_8 + V_33 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_34 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_35 ) ;
F_6 ( 0 , V_2 -> V_8 + V_36 ) ;
F_6 ( 0 , V_2 -> V_8 + V_37 ) ;
V_12 = ( V_11 -> V_26 - V_11 -> V_19 + V_38 ) << 16 ;
V_12 |= V_11 -> V_14 + V_38 ;
F_6 ( V_12 , V_2 -> V_8 + V_39 ) ;
V_12 = ( V_11 -> V_29 - V_11 -> V_18 ) << 16 ;
V_12 |= V_11 -> V_16 ;
F_6 ( V_12 , V_2 -> V_8 + V_40 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_41 ) ;
V_12 = ( V_11 -> V_14 + V_38 ) << 16 ;
V_12 |= V_11 -> V_14 + V_38 ;
F_6 ( V_12 , V_2 -> V_8 + V_42 ) ;
F_6 ( V_12 , V_2 -> V_8 + V_43 ) ;
F_6 ( type , V_2 -> V_8 + V_44 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( 0xFFFF , V_2 -> V_8 + V_45 ) ;
F_6 ( 0xFFFF , V_2 -> V_8 + V_46 ) ;
F_6 ( V_47 , V_2 -> V_8 + V_48 ) ;
}
void F_9 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
F_7 ( V_2 , V_49 , V_11 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_7 )
F_8 ( V_2 -> V_7 ) ;
else
F_8 ( V_2 ) ;
}
T_1 F_10 ( struct V_10 V_11 , int V_50 )
{
T_1 V_51 = V_11 . V_16 - V_11 . V_18 + 1 ;
if ( V_11 . V_52 & V_53 )
V_51 *= 2 ;
return V_51 + V_50 ;
}
T_1 F_11 ( struct V_10 V_11 , int V_54 )
{
return V_11 . V_14 - V_11 . V_19 + V_54 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_55 * V_56 , int V_57 )
{
if ( V_2 -> V_7 )
return F_12 ( V_2 -> V_7 , V_56 , V_57 ) ;
V_2 -> V_57 = V_57 ;
return F_13 ( & V_2 -> V_58 , V_56 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
if ( V_2 -> V_7 )
return F_14 ( V_2 -> V_7 , V_56 ) ;
return F_15 ( & V_2 -> V_58 , V_56 ) ;
}
static T_2 F_16 ( int V_59 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
T_1 V_61 ;
V_61 = ( V_2 -> V_62 & V_63 ) ?
V_64 : V_65 ;
F_17 ( & V_2 -> V_58 , V_61 , & V_2 -> V_57 ) ;
return V_66 ;
}
static T_2 F_18 ( int V_59 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
V_2 -> V_62 = F_19 ( V_2 -> V_8 + V_67 ) ;
F_6 ( V_2 -> V_62 , V_2 -> V_8 + V_45 ) ;
F_19 ( V_2 -> V_8 + V_67 ) ;
return V_68 ;
}
static int F_20 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = & V_70 -> V_72 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
char V_75 [ 32 ] ;
int V_76 ;
V_2 = F_21 ( V_72 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_6 = V_70 -> V_72 . V_79 ;
V_74 = F_22 ( V_70 , V_80 , 0 ) ;
if ( ! V_74 ) {
F_23 ( L_1 ) ;
return - V_78 ;
}
V_2 -> V_8 = F_24 ( V_72 , V_74 -> V_81 , F_25 ( V_74 ) ) ;
V_6 = F_26 ( V_70 -> V_72 . V_79 , L_2 , 0 ) ;
if ( V_6 ) {
V_2 -> V_7 = F_3 ( V_6 ) ;
if ( ! V_2 -> V_7 )
return - V_82 ;
} else {
V_2 -> V_59 = F_27 ( V_70 , 0 ) ;
if ( F_28 ( V_2 -> V_59 ) ) {
F_23 ( L_3 ) ;
return V_2 -> V_59 ;
}
snprintf ( V_75 , sizeof( V_75 ) , L_4 ,
F_29 ( V_2 -> V_72 ) ) ;
F_30 ( & V_2 -> V_58 ) ;
V_76 = F_31 ( V_72 , V_2 -> V_59 , F_18 ,
F_16 , V_83 , V_75 , V_2 ) ;
if ( F_28 ( V_76 ) ) {
F_23 ( L_5 ) ;
return V_76 ;
}
}
F_1 ( V_2 ) ;
F_32 ( V_70 , V_2 ) ;
F_33 ( L_6 , V_84 , F_29 ( V_2 -> V_72 ) ) ;
return 0 ;
}
static int F_34 ( struct V_69 * V_70 )
{
return 0 ;
}
