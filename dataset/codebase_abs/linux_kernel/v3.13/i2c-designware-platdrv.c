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
bool V_23 = V_2 -> V_24 & V_25 ;
if ( ! F_4 ( & V_5 -> V_2 ) )
return - V_26 ;
V_2 -> V_27 . V_28 = - 1 ;
V_2 -> V_29 = 32 ;
V_2 -> V_30 = 32 ;
F_3 ( V_5 , L_1 , & V_2 -> V_31 , & V_2 -> V_32 ,
V_23 ? NULL : & V_2 -> V_33 ) ;
F_3 ( V_5 , L_2 , & V_2 -> V_34 , & V_2 -> V_35 ,
V_23 ? & V_2 -> V_33 : NULL ) ;
return 0 ;
}
static inline int F_8 ( struct V_4 * V_5 )
{
return - V_26 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_40 , V_41 ;
V_40 = F_11 ( V_5 , 0 ) ;
if ( V_40 < 0 ) {
F_12 ( & V_5 -> V_2 , L_3 ) ;
return V_40 ;
}
V_2 = F_13 ( & V_5 -> V_2 , sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_39 = F_14 ( V_5 , V_44 , 0 ) ;
V_2 -> V_45 = F_15 ( & V_5 -> V_2 , V_39 ) ;
if ( F_16 ( V_2 -> V_45 ) )
return F_17 ( V_2 -> V_45 ) ;
F_18 ( & V_2 -> V_46 ) ;
F_19 ( & V_2 -> V_47 ) ;
V_2 -> V_2 = & V_5 -> V_2 ;
V_2 -> V_40 = V_40 ;
F_20 ( V_5 , V_2 ) ;
V_2 -> V_3 = F_21 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_48 = F_1 ;
if ( F_16 ( V_2 -> V_3 ) )
return F_17 ( V_2 -> V_3 ) ;
F_22 ( V_2 -> V_3 ) ;
if ( V_5 -> V_2 . V_49 ) {
T_1 V_50 = 0 ;
T_1 V_51 = V_2 -> V_48 ( V_2 ) ;
F_23 ( V_5 -> V_2 . V_49 ,
L_4 , & V_50 ) ;
V_2 -> V_33 = F_24 ( ( V_52 ) V_51 * V_50 + 500000 ,
1000000 ) ;
}
V_2 -> V_53 =
V_54 |
V_55 |
V_56 |
V_57 |
V_58 |
V_59 ;
V_2 -> V_24 = V_60 | V_61 |
V_62 | V_25 ;
V_41 = F_8 ( V_5 ) ;
if ( V_41 ) {
T_1 V_63 = F_25 ( V_2 ) ;
V_2 -> V_29 = ( ( V_63 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_30 = ( ( V_63 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_27 . V_28 = V_5 -> V_64 ;
}
V_41 = F_26 ( V_2 ) ;
if ( V_41 )
return V_41 ;
F_27 ( V_2 ) ;
V_41 = F_28 ( & V_5 -> V_2 , V_2 -> V_40 , V_65 , V_66 ,
V_5 -> V_67 , V_2 ) ;
if ( V_41 ) {
F_12 ( & V_5 -> V_2 , L_5 , V_2 -> V_40 ) ;
return V_41 ;
}
V_37 = & V_2 -> V_27 ;
F_29 ( V_37 , V_2 ) ;
V_37 -> V_68 = V_69 ;
V_37 -> V_70 = V_71 ;
F_30 ( V_37 -> V_67 , L_6 ,
sizeof( V_37 -> V_67 ) ) ;
V_37 -> V_72 = & V_73 ;
V_37 -> V_2 . V_74 = & V_5 -> V_2 ;
V_37 -> V_2 . V_49 = V_5 -> V_2 . V_49 ;
V_41 = F_31 ( V_37 ) ;
if ( V_41 ) {
F_12 ( & V_5 -> V_2 , L_7 ) ;
return V_41 ;
}
F_32 ( & V_5 -> V_2 , 1000 ) ;
F_33 ( & V_5 -> V_2 ) ;
F_34 ( & V_5 -> V_2 ) ;
F_35 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
F_37 ( & V_5 -> V_2 ) ;
F_38 ( & V_2 -> V_27 ) ;
F_39 ( V_2 ) ;
F_40 ( & V_5 -> V_2 ) ;
F_41 ( & V_5 -> V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_75 * V_2 )
{
struct V_4 * V_5 = F_43 ( V_2 ) ;
struct V_1 * V_76 = F_9 ( V_5 ) ;
F_44 ( V_76 -> V_3 ) ;
return 0 ;
}
static int F_45 ( struct V_75 * V_2 )
{
struct V_4 * V_5 = F_43 ( V_2 ) ;
struct V_1 * V_76 = F_9 ( V_5 ) ;
F_22 ( V_76 -> V_3 ) ;
F_26 ( V_76 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
return F_47 ( & V_77 ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_77 ) ;
}
