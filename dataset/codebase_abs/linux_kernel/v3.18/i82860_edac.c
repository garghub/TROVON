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
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = V_69 [ V_48 ] . V_68 ;
V_2 -> V_70 = F_15 ( V_6 ) ;
V_2 -> V_71 = F_9 ;
V_2 -> V_72 = NULL ;
F_11 ( V_2 , V_6 ) ;
F_1 ( V_2 , & V_51 ) ;
if ( F_16 ( V_2 ) ) {
F_10 ( 3 , L_8 ) ;
goto V_73;
}
V_74 = F_17 ( & V_6 -> V_57 , V_65 ) ;
if ( ! V_74 ) {
F_18 ( V_75
L_9 ,
V_76 ) ;
F_18 ( V_75
L_10 ,
V_76 ) ;
}
F_10 ( 3 , L_11 ) ;
return 0 ;
V_73:
F_19 ( V_2 ) ;
return - V_77 ;
}
static int F_20 ( struct V_5 * V_6 ,
const struct V_78 * V_79 )
{
int V_80 ;
F_10 ( 0 , L_12 ) ;
F_21 ( V_81 , L_13 ) ;
if ( F_22 ( V_6 ) < 0 )
return - V_82 ;
V_80 = F_12 ( V_6 , V_79 -> V_83 ) ;
if ( V_80 == 0 )
V_84 = F_23 ( V_6 ) ;
return V_80 ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_10 ( 0 , L_12 ) ;
if ( V_74 )
F_25 ( V_74 ) ;
if ( ( V_2 = F_26 ( & V_6 -> V_57 ) ) == NULL )
return;
F_19 ( V_2 ) ;
}
static int T_3 F_27 ( void )
{
int V_85 ;
F_10 ( 3 , L_12 ) ;
F_28 () ;
if ( ( V_85 = F_29 ( & V_86 ) ) < 0 )
goto V_87;
if ( ! V_84 ) {
V_84 = F_30 ( V_88 ,
V_89 , NULL ) ;
if ( V_84 == NULL ) {
F_10 ( 0 , L_14 ) ;
V_85 = - V_77 ;
goto V_90;
}
V_85 = F_20 ( V_84 , V_91 ) ;
if ( V_85 < 0 ) {
F_10 ( 0 , L_15 ) ;
V_85 = - V_77 ;
goto V_90;
}
}
return 0 ;
V_90:
F_31 ( & V_86 ) ;
V_87:
if ( V_84 != NULL )
F_32 ( V_84 ) ;
return V_85 ;
}
static void T_4 F_33 ( void )
{
F_10 ( 3 , L_12 ) ;
F_31 ( & V_86 ) ;
if ( V_84 != NULL )
F_32 ( V_84 ) ;
}
