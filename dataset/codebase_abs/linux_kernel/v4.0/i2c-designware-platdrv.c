static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static void F_3 ( struct V_4 * V_5 , char V_6 [] ,
T_2 * V_7 , T_2 * V_8 , T_1 * V_9 )
{
struct V_10 V_11 = { V_12 } ;
T_3 V_13 = F_4 ( & V_5 -> V_2 ) ;
union V_14 * V_15 ;
if ( F_5 ( F_6 ( V_13 , V_6 , NULL , & V_11 ) ) )
return;
V_15 = (union V_14 * ) V_11 . V_16 ;
if ( V_15 -> type == V_17 && V_15 -> V_18 . V_19 == 3 ) {
const union V_14 * V_20 = V_15 -> V_18 . V_21 ;
* V_7 = ( T_2 ) V_20 [ 0 ] . integer . V_22 ;
* V_8 = ( T_2 ) V_20 [ 1 ] . integer . V_22 ;
if ( V_9 )
* V_9 = ( T_1 ) V_20 [ 2 ] . integer . V_22 ;
}
F_7 ( V_11 . V_16 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
const struct V_23 * V_24 ;
V_2 -> V_25 . V_26 = - 1 ;
V_2 -> V_27 = 32 ;
V_2 -> V_28 = 32 ;
F_3 ( V_5 , L_1 , & V_2 -> V_29 , & V_2 -> V_30 , NULL ) ;
F_3 ( V_5 , L_2 , & V_2 -> V_31 , & V_2 -> V_32 ,
& V_2 -> V_33 ) ;
V_24 = F_10 ( V_5 -> V_2 . V_34 -> V_35 , & V_5 -> V_2 ) ;
if ( V_24 && V_24 -> V_36 )
F_11 ( & V_5 -> V_2 , F_12 ( & V_5 -> V_2 ) , NULL ,
V_37 , V_24 -> V_36 ) ;
return 0 ;
}
static void F_13 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
const struct V_23 * V_24 ;
V_24 = F_10 ( V_5 -> V_2 . V_34 -> V_35 , & V_5 -> V_2 ) ;
if ( V_24 && V_24 -> V_36 )
F_14 ( V_2 -> V_3 ) ;
}
static inline int F_8 ( struct V_4 * V_5 )
{
return - V_38 ;
}
static inline void F_13 ( struct V_4 * V_5 ) { }
static int F_15 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_45 , V_46 ;
T_1 V_47 , V_48 = 0 ;
V_45 = F_16 ( V_5 , 0 ) ;
if ( V_45 < 0 ) {
F_17 ( & V_5 -> V_2 , L_3 ) ;
return V_45 ;
}
V_2 = F_18 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_42 = F_19 ( V_5 , V_51 , 0 ) ;
V_2 -> V_52 = F_20 ( & V_5 -> V_2 , V_42 ) ;
if ( F_21 ( V_2 -> V_52 ) )
return F_22 ( V_2 -> V_52 ) ;
F_23 ( & V_2 -> V_53 ) ;
F_24 ( & V_2 -> V_54 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_45 = V_45 ;
F_25 ( V_5 , V_2 ) ;
V_47 = 400000 ;
if ( F_26 ( & V_5 -> V_2 ) ) {
F_8 ( V_5 ) ;
} else if ( V_5 -> V_2 . V_55 ) {
F_27 ( V_5 -> V_2 . V_55 ,
L_4 , & V_48 ) ;
F_27 ( V_5 -> V_2 . V_55 ,
L_5 ,
& V_2 -> V_56 ) ;
F_27 ( V_5 -> V_2 . V_55 ,
L_6 ,
& V_2 -> V_57 ) ;
F_27 ( V_5 -> V_2 . V_55 , L_7 ,
& V_47 ) ;
if ( V_47 != 100000 && V_47 != 400000 ) {
F_17 ( & V_5 -> V_2 , L_8 ) ;
return - V_58 ;
}
} else {
V_44 = F_28 ( & V_5 -> V_2 ) ;
if ( V_44 )
V_47 = V_44 -> V_59 ;
}
V_46 = F_29 ( V_2 ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_60 =
V_61 |
V_62 |
V_63 |
V_64 |
V_65 |
V_66 ;
if ( V_47 == 100000 )
V_2 -> V_67 = V_68 | V_69 |
V_70 | V_71 ;
else
V_2 -> V_67 = V_68 | V_69 |
V_70 | V_72 ;
V_2 -> V_3 = F_30 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_73 = F_1 ;
if ( F_21 ( V_2 -> V_3 ) )
return F_22 ( V_2 -> V_3 ) ;
F_31 ( V_2 -> V_3 ) ;
if ( ! V_2 -> V_33 && V_48 ) {
T_1 V_74 = V_2 -> V_73 ( V_2 ) ;
V_2 -> V_33 = F_32 ( ( V_75 ) V_74 * V_48 + 500000 ,
1000000 ) ;
}
if ( ! V_2 -> V_27 ) {
T_1 V_76 = F_33 ( V_2 ) ;
V_2 -> V_27 = ( ( V_76 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_28 = ( ( V_76 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_25 . V_26 = V_5 -> V_24 ;
}
V_46 = F_34 ( V_2 ) ;
if ( V_46 )
return V_46 ;
F_35 ( V_2 ) ;
V_46 = F_36 ( & V_5 -> V_2 , V_2 -> V_45 , V_77 , V_78 ,
V_5 -> V_79 , V_2 ) ;
if ( V_46 ) {
F_17 ( & V_5 -> V_2 , L_9 , V_2 -> V_45 ) ;
return V_46 ;
}
V_40 = & V_2 -> V_25 ;
F_37 ( V_40 , V_2 ) ;
V_40 -> V_80 = V_81 ;
V_40 -> V_82 = V_83 ;
F_38 ( V_40 -> V_79 , L_10 ,
sizeof( V_40 -> V_79 ) ) ;
V_40 -> V_84 = & V_85 ;
V_40 -> V_2 . V_86 = & V_5 -> V_2 ;
V_40 -> V_2 . V_55 = V_5 -> V_2 . V_55 ;
V_46 = F_39 ( V_40 ) ;
if ( V_46 ) {
F_17 ( & V_5 -> V_2 , L_11 ) ;
return V_46 ;
}
if ( V_2 -> V_87 ) {
F_40 ( & V_5 -> V_2 ) ;
} else {
F_41 ( & V_5 -> V_2 , 1000 ) ;
F_42 ( & V_5 -> V_2 ) ;
F_43 ( & V_5 -> V_2 ) ;
F_44 ( & V_5 -> V_2 ) ;
}
return 0 ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
F_46 ( & V_5 -> V_2 ) ;
F_47 ( & V_2 -> V_25 ) ;
F_48 ( V_2 ) ;
F_49 ( & V_5 -> V_2 ) ;
F_50 ( & V_5 -> V_2 ) ;
if ( F_26 ( & V_5 -> V_2 ) )
F_13 ( V_5 ) ;
return 0 ;
}
static int F_51 ( struct V_88 * V_2 )
{
struct V_4 * V_5 = F_52 ( V_2 ) ;
struct V_1 * V_89 = F_9 ( V_5 ) ;
F_48 ( V_89 ) ;
F_53 ( V_89 -> V_3 ) ;
return 0 ;
}
static int F_54 ( struct V_88 * V_2 )
{
struct V_4 * V_5 = F_52 ( V_2 ) ;
struct V_1 * V_89 = F_9 ( V_5 ) ;
F_31 ( V_89 -> V_3 ) ;
if ( ! V_89 -> V_87 )
F_34 ( V_89 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
return F_56 ( & V_90 ) ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_90 ) ;
}
