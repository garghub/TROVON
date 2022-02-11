static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_8 ) ;
F_4 ( V_6 , V_9 , & V_4 -> V_10 ) ;
F_3 ( V_6 , V_11 , & V_4 -> V_12 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_13 ) ;
F_5 ( V_6 , V_7 , 0x0003 , 0x0003 ) ;
if ( ! ( V_4 -> V_13 & 0x0003 ) )
return;
if ( ( V_4 -> V_8 ^ V_4 -> V_13 ) & 0x0003 ) {
F_4 ( V_6 , V_9 , & V_4 -> V_10 ) ;
F_3 ( V_6 , V_11 , & V_4 -> V_12 ) ;
}
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_14 )
{
struct V_15 * V_16 ;
int V_17 ;
if ( ! ( V_4 -> V_13 & 0x0003 ) )
return 0 ;
if ( ! V_14 )
return 1 ;
if ( ( V_4 -> V_8 ^ V_4 -> V_13 ) & 0x0003 ) {
F_7 ( V_18 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_1 , L_2 ) ;
V_4 -> V_8 = V_4 -> V_13 ;
}
V_4 -> V_10 >>= V_19 ;
V_17 = F_8 ( V_2 , V_4 -> V_10 ) ;
V_16 = V_2 -> V_20 [ V_17 ] -> V_21 [ 0 ] -> V_16 ;
if ( V_4 -> V_8 & 0x0002 )
F_7 ( V_18 , V_2 , 1 ,
V_4 -> V_10 , 0 , 0 ,
V_16 -> V_22 [ 0 ] , V_16 -> V_22 [ 1 ] , - 1 ,
L_3 , L_2 ) ;
else
F_7 ( V_23 , V_2 , 1 ,
V_4 -> V_10 , 0 , V_4 -> V_12 ,
V_16 -> V_22 [ 0 ] , V_16 -> V_22 [ 1 ] , - 1 ,
L_4 , L_2 ) ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( 1 , L_5 , V_2 -> V_24 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_25 ;
T_1 V_26 ;
T_1 V_27 ;
T_2 V_28 ;
struct V_29 * V_30 ;
struct V_15 * V_16 ;
int V_31 ;
F_3 ( V_6 , V_32 , & V_26 ) ;
V_26 = V_26 & 0x180 ;
V_25 = 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_33 ; V_31 ++ ) {
V_30 = V_2 -> V_20 [ V_31 ] ;
V_16 = V_30 -> V_21 [ 0 ] -> V_16 ;
F_3 ( V_6 , V_34 + V_31 * 2 , & V_27 ) ;
V_28 = ( V_27 & V_35 ) <<
( V_36 - V_19 ) ;
F_10 ( 3 , L_6 , V_31 , V_28 ) ;
if ( V_28 == V_25 )
continue;
V_30 -> V_37 = V_25 ;
V_30 -> V_38 = V_28 - 1 ;
V_16 -> V_39 = V_28 - V_25 ;
V_25 = V_28 ;
V_16 -> V_40 = 1 << 12 ;
V_16 -> V_41 = V_42 ;
V_16 -> V_43 = V_44 ;
V_16 -> V_45 = V_26 ? V_46 : V_47 ;
}
}
static int F_12 ( struct V_5 * V_6 , int V_48 )
{
struct V_1 * V_2 ;
struct V_49 V_50 [ 2 ] ;
struct V_3 V_51 ;
V_50 [ 0 ] . type = V_52 ;
V_50 [ 0 ] . V_53 = 2 ;
V_50 [ 0 ] . V_54 = true ;
V_50 [ 1 ] . type = V_55 ;
V_50 [ 1 ] . V_53 = 8 ;
V_50 [ 1 ] . V_54 = true ;
V_2 = F_13 ( 0 , F_14 ( V_50 ) , V_50 , 0 ) ;
if ( ! V_2 )
return - V_56 ;
F_10 ( 3 , L_7 ) ;
V_2 -> V_6 = & V_6 -> V_57 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = V_61 | V_62 ;
V_2 -> V_63 = V_62 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_67 [ V_48 ] . V_66 ;
V_2 -> V_68 = F_15 ( V_6 ) ;
V_2 -> V_69 = F_9 ;
V_2 -> V_70 = NULL ;
F_11 ( V_2 , V_6 ) ;
F_1 ( V_2 , & V_51 ) ;
if ( F_16 ( V_2 ) ) {
F_10 ( 3 , L_8 ) ;
goto V_71;
}
V_72 = F_17 ( & V_6 -> V_57 , V_65 ) ;
if ( ! V_72 ) {
F_18 ( V_73
L_9 ,
V_74 ) ;
F_18 ( V_73
L_10 ,
V_74 ) ;
}
F_10 ( 3 , L_11 ) ;
return 0 ;
V_71:
F_19 ( V_2 ) ;
return - V_75 ;
}
static int F_20 ( struct V_5 * V_6 ,
const struct V_76 * V_77 )
{
int V_78 ;
F_10 ( 0 , L_12 ) ;
F_21 ( V_79 , L_13 ) ;
if ( F_22 ( V_6 ) < 0 )
return - V_80 ;
V_78 = F_12 ( V_6 , V_77 -> V_81 ) ;
if ( V_78 == 0 )
V_82 = F_23 ( V_6 ) ;
return V_78 ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_10 ( 0 , L_12 ) ;
if ( V_72 )
F_25 ( V_72 ) ;
if ( ( V_2 = F_26 ( & V_6 -> V_57 ) ) == NULL )
return;
F_19 ( V_2 ) ;
}
static int T_3 F_27 ( void )
{
int V_83 ;
F_10 ( 3 , L_12 ) ;
F_28 () ;
if ( ( V_83 = F_29 ( & V_84 ) ) < 0 )
goto V_85;
if ( ! V_82 ) {
V_82 = F_30 ( V_86 ,
V_87 , NULL ) ;
if ( V_82 == NULL ) {
F_10 ( 0 , L_14 ) ;
V_83 = - V_75 ;
goto V_88;
}
V_83 = F_20 ( V_82 , V_89 ) ;
if ( V_83 < 0 ) {
F_10 ( 0 , L_15 ) ;
V_83 = - V_75 ;
goto V_88;
}
}
return 0 ;
V_88:
F_31 ( & V_84 ) ;
V_85:
F_32 ( V_82 ) ;
return V_83 ;
}
static void T_4 F_33 ( void )
{
F_10 ( 3 , L_12 ) ;
F_31 ( & V_84 ) ;
F_32 ( V_82 ) ;
}
