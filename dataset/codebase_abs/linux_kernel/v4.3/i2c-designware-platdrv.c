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
if ( F_5 ( V_16 ) )
return;
if ( F_6 ( F_7 ( V_13 , V_6 , NULL , & V_11 ) ) )
return;
V_15 = (union V_14 * ) V_11 . V_17 ;
if ( V_15 -> type == V_18 && V_15 -> V_19 . V_20 == 3 ) {
const union V_14 * V_21 = V_15 -> V_19 . V_22 ;
* V_7 = ( T_2 ) V_21 [ 0 ] . integer . V_23 ;
* V_8 = ( T_2 ) V_21 [ 1 ] . integer . V_23 ;
if ( V_9 )
* V_9 = ( T_1 ) V_21 [ 2 ] . integer . V_23 ;
}
F_8 ( V_11 . V_17 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
const struct V_24 * V_25 ;
V_2 -> V_26 . V_27 = - 1 ;
V_2 -> V_28 = 32 ;
V_2 -> V_29 = 32 ;
F_3 ( V_5 , L_1 , & V_2 -> V_30 , & V_2 -> V_31 , NULL ) ;
F_3 ( V_5 , L_2 , & V_2 -> V_32 , & V_2 -> V_33 ,
& V_2 -> V_34 ) ;
V_25 = F_11 ( V_5 -> V_2 . V_35 -> V_36 , & V_5 -> V_2 ) ;
if ( V_25 && V_25 -> V_37 )
F_12 ( & V_5 -> V_2 , F_13 ( & V_5 -> V_2 ) , NULL ,
V_38 , V_25 -> V_37 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
const struct V_24 * V_25 ;
V_25 = F_11 ( V_5 -> V_2 . V_35 -> V_36 , & V_5 -> V_2 ) ;
if ( V_25 && V_25 -> V_37 )
F_15 ( V_2 -> V_3 ) ;
}
static inline int F_9 ( struct V_4 * V_5 )
{
return - V_39 ;
}
static inline void F_14 ( struct V_4 * V_5 ) { }
static int F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_46 , V_47 ;
T_1 V_48 , V_49 = 0 ;
V_46 = F_17 ( V_5 , 0 ) ;
if ( V_46 < 0 )
return V_46 ;
V_2 = F_18 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_43 = F_19 ( V_5 , V_52 , 0 ) ;
V_2 -> V_53 = F_20 ( & V_5 -> V_2 , V_43 ) ;
if ( F_21 ( V_2 -> V_53 ) )
return F_22 ( V_2 -> V_53 ) ;
F_23 ( & V_2 -> V_54 ) ;
F_24 ( & V_2 -> V_55 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_46 = V_46 ;
F_25 ( V_5 , V_2 ) ;
V_48 = 400000 ;
if ( F_26 ( & V_5 -> V_2 ) ) {
F_9 ( V_5 ) ;
} else if ( V_5 -> V_2 . V_56 ) {
F_27 ( V_5 -> V_2 . V_56 ,
L_3 , & V_49 ) ;
F_27 ( V_5 -> V_2 . V_56 ,
L_4 ,
& V_2 -> V_57 ) ;
F_27 ( V_5 -> V_2 . V_56 ,
L_5 ,
& V_2 -> V_58 ) ;
F_27 ( V_5 -> V_2 . V_56 , L_6 ,
& V_48 ) ;
if ( V_48 != 100000 && V_48 != 400000 ) {
F_28 ( & V_5 -> V_2 , L_7 ) ;
return - V_59 ;
}
} else {
V_45 = F_29 ( & V_5 -> V_2 ) ;
if ( V_45 )
V_48 = V_45 -> V_60 ;
}
V_47 = F_30 ( V_2 ) ;
if ( V_47 )
return V_47 ;
V_2 -> V_61 =
V_62 |
V_63 |
V_64 |
V_65 |
V_66 |
V_67 ;
if ( V_48 == 100000 )
V_2 -> V_68 = V_69 | V_70 |
V_71 | V_72 ;
else
V_2 -> V_68 = V_69 | V_70 |
V_71 | V_73 ;
V_2 -> V_3 = F_31 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_74 = F_1 ;
if ( F_21 ( V_2 -> V_3 ) )
return F_22 ( V_2 -> V_3 ) ;
F_32 ( V_2 -> V_3 ) ;
if ( ! V_2 -> V_34 && V_49 ) {
T_1 V_75 = V_2 -> V_74 ( V_2 ) ;
V_2 -> V_34 = F_33 ( ( V_76 ) V_75 * V_49 + 500000 ,
1000000 ) ;
}
if ( ! V_2 -> V_28 ) {
T_1 V_77 = F_34 ( V_2 ) ;
V_2 -> V_28 = ( ( V_77 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_29 = ( ( V_77 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_26 . V_27 = V_5 -> V_25 ;
}
V_47 = F_35 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_36 ( V_2 ) ;
V_47 = F_37 ( & V_5 -> V_2 , V_2 -> V_46 , V_78 , V_79 ,
V_5 -> V_80 , V_2 ) ;
if ( V_47 ) {
F_28 ( & V_5 -> V_2 , L_8 , V_2 -> V_46 ) ;
return V_47 ;
}
V_41 = & V_2 -> V_26 ;
F_38 ( V_41 , V_2 ) ;
V_41 -> V_81 = V_82 ;
V_41 -> V_83 = V_84 ;
F_39 ( V_41 -> V_80 , L_9 ,
sizeof( V_41 -> V_80 ) ) ;
V_41 -> V_85 = & V_86 ;
V_41 -> V_2 . V_87 = & V_5 -> V_2 ;
V_41 -> V_2 . V_56 = V_5 -> V_2 . V_56 ;
if ( V_2 -> V_88 ) {
F_40 ( & V_5 -> V_2 ) ;
} else {
F_41 ( & V_5 -> V_2 , 1000 ) ;
F_42 ( & V_5 -> V_2 ) ;
F_43 ( & V_5 -> V_2 ) ;
F_44 ( & V_5 -> V_2 ) ;
}
V_47 = F_45 ( V_41 ) ;
if ( V_47 ) {
F_28 ( & V_5 -> V_2 , L_10 ) ;
F_46 ( & V_5 -> V_2 ) ;
return V_47 ;
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_10 ( V_5 ) ;
F_48 ( & V_5 -> V_2 ) ;
F_49 ( & V_2 -> V_26 ) ;
F_50 ( V_2 ) ;
F_51 ( & V_5 -> V_2 ) ;
F_52 ( & V_5 -> V_2 ) ;
F_46 ( & V_5 -> V_2 ) ;
if ( F_26 ( & V_5 -> V_2 ) )
F_14 ( V_5 ) ;
return 0 ;
}
static int F_53 ( struct V_89 * V_2 )
{
return F_54 ( V_2 ) ;
}
static void F_55 ( struct V_89 * V_2 )
{
if ( V_2 -> V_90 . V_91 )
F_56 ( V_2 ) ;
}
static int F_57 ( struct V_89 * V_2 )
{
struct V_4 * V_5 = F_58 ( V_2 ) ;
struct V_1 * V_92 = F_10 ( V_5 ) ;
F_50 ( V_92 ) ;
F_59 ( V_92 -> V_3 ) ;
return 0 ;
}
static int F_60 ( struct V_89 * V_2 )
{
struct V_4 * V_5 = F_58 ( V_2 ) ;
struct V_1 * V_92 = F_10 ( V_5 ) ;
F_32 ( V_92 -> V_3 ) ;
if ( ! V_92 -> V_88 )
F_35 ( V_92 ) ;
return 0 ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_93 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_93 ) ;
}
