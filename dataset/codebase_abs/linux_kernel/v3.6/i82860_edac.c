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
F_7 ( V_18 , V_2 , 1 ,
V_4 -> V_10 , 0 , V_4 -> V_12 ,
V_16 -> V_22 [ 0 ] , V_16 -> V_22 [ 1 ] , - 1 ,
L_4 , L_2 ) ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( 1 , L_5 , V_2 -> V_23 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_24 ;
T_1 V_25 ;
T_1 V_26 ;
T_2 V_27 ;
struct V_28 * V_29 ;
struct V_15 * V_16 ;
int V_30 ;
F_3 ( V_6 , V_31 , & V_25 ) ;
V_25 = V_25 & 0x180 ;
V_24 = 0 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_32 ; V_30 ++ ) {
V_29 = V_2 -> V_20 [ V_30 ] ;
V_16 = V_29 -> V_21 [ 0 ] -> V_16 ;
F_3 ( V_6 , V_33 + V_30 * 2 , & V_26 ) ;
V_27 = ( V_26 & V_34 ) <<
( V_35 - V_19 ) ;
F_10 ( 3 , L_6 , V_30 , V_27 ) ;
if ( V_27 == V_24 )
continue;
V_29 -> V_36 = V_24 ;
V_29 -> V_37 = V_27 - 1 ;
V_16 -> V_38 = V_27 - V_24 ;
V_24 = V_27 ;
V_16 -> V_39 = 1 << 12 ;
V_16 -> V_40 = V_41 ;
V_16 -> V_42 = V_43 ;
V_16 -> V_44 = V_25 ? V_45 : V_46 ;
}
}
static int F_12 ( struct V_5 * V_6 , int V_47 )
{
struct V_1 * V_2 ;
struct V_48 V_49 [ 2 ] ;
struct V_3 V_50 ;
V_49 [ 0 ] . type = V_51 ;
V_49 [ 0 ] . V_52 = 2 ;
V_49 [ 0 ] . V_53 = true ;
V_49 [ 1 ] . type = V_54 ;
V_49 [ 1 ] . V_52 = 8 ;
V_49 [ 1 ] . V_53 = true ;
V_2 = F_13 ( 0 , F_14 ( V_49 ) , V_49 , 0 ) ;
if ( ! V_2 )
return - V_55 ;
F_10 ( 3 , L_7 ) ;
V_2 -> V_6 = & V_6 -> V_56 ;
V_2 -> V_57 = V_58 ;
V_2 -> V_59 = V_60 | V_61 ;
V_2 -> V_62 = V_61 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = V_68 [ V_47 ] . V_67 ;
V_2 -> V_69 = F_15 ( V_6 ) ;
V_2 -> V_70 = F_9 ;
V_2 -> V_71 = NULL ;
F_11 ( V_2 , V_6 ) ;
F_1 ( V_2 , & V_50 ) ;
if ( F_16 ( V_2 ) ) {
F_10 ( 3 , L_8 ) ;
goto V_72;
}
V_73 = F_17 ( & V_6 -> V_56 , V_64 ) ;
if ( ! V_73 ) {
F_18 ( V_74
L_9 ,
V_75 ) ;
F_18 ( V_74
L_10 ,
V_75 ) ;
}
F_10 ( 3 , L_11 ) ;
return 0 ;
V_72:
F_19 ( V_2 ) ;
return - V_76 ;
}
static int T_3 F_20 ( struct V_5 * V_6 ,
const struct V_77 * V_78 )
{
int V_79 ;
F_10 ( 0 , L_12 ) ;
F_21 ( V_80 , L_13 ) ;
if ( F_22 ( V_6 ) < 0 )
return - V_81 ;
V_79 = F_12 ( V_6 , V_78 -> V_82 ) ;
if ( V_79 == 0 )
V_83 = F_23 ( V_6 ) ;
return V_79 ;
}
static void T_4 F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_10 ( 0 , L_12 ) ;
if ( V_73 )
F_25 ( V_73 ) ;
if ( ( V_2 = F_26 ( & V_6 -> V_56 ) ) == NULL )
return;
F_19 ( V_2 ) ;
}
static int T_5 F_27 ( void )
{
int V_84 ;
F_10 ( 3 , L_12 ) ;
F_28 () ;
if ( ( V_84 = F_29 ( & V_85 ) ) < 0 )
goto V_86;
if ( ! V_83 ) {
V_83 = F_30 ( V_87 ,
V_88 , NULL ) ;
if ( V_83 == NULL ) {
F_10 ( 0 , L_14 ) ;
V_84 = - V_76 ;
goto V_89;
}
V_84 = F_20 ( V_83 , V_90 ) ;
if ( V_84 < 0 ) {
F_10 ( 0 , L_15 ) ;
V_84 = - V_76 ;
goto V_89;
}
}
return 0 ;
V_89:
F_31 ( & V_85 ) ;
V_86:
if ( V_83 != NULL )
F_32 ( V_83 ) ;
return V_84 ;
}
static void T_6 F_33 ( void )
{
F_10 ( 3 , L_12 ) ;
F_31 ( & V_85 ) ;
if ( V_83 != NULL )
F_32 ( V_83 ) ;
}
