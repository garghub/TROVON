static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_6 , V_8 , & V_4 -> V_9 ) ;
F_4 ( V_6 , V_10 , & V_4 -> V_11 ) ;
F_3 ( V_6 , V_12 , & V_4 -> V_13 ) ;
F_3 ( V_6 , V_8 , & V_4 -> V_14 ) ;
F_5 ( V_6 , V_8 , 0x0003 , 0x0003 ) ;
if ( ! ( V_4 -> V_14 & 0x0003 ) )
return;
if ( ( V_4 -> V_9 ^ V_4 -> V_14 ) & 0x0003 ) {
F_4 ( V_6 , V_10 , & V_4 -> V_11 ) ;
F_3 ( V_6 , V_12 , & V_4 -> V_13 ) ;
}
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_15 )
{
struct V_16 * V_17 ;
int V_18 ;
if ( ! ( V_4 -> V_14 & 0x0003 ) )
return 0 ;
if ( ! V_15 )
return 1 ;
if ( ( V_4 -> V_9 ^ V_4 -> V_14 ) & 0x0003 ) {
F_7 ( V_19 , V_2 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_1 , L_2 , NULL ) ;
V_4 -> V_9 = V_4 -> V_14 ;
}
V_4 -> V_11 >>= V_20 ;
V_18 = F_8 ( V_2 , V_4 -> V_11 ) ;
V_17 = V_2 -> V_21 [ V_18 ] . V_22 [ 0 ] . V_17 ;
if ( V_4 -> V_9 & 0x0002 )
F_7 ( V_19 , V_2 ,
V_4 -> V_11 , 0 , 0 ,
V_17 -> V_23 [ 0 ] , V_17 -> V_23 [ 1 ] , - 1 ,
L_3 , L_2 , NULL ) ;
else
F_7 ( V_19 , V_2 ,
V_4 -> V_11 , 0 , V_4 -> V_13 ,
V_17 -> V_23 [ 0 ] , V_17 -> V_23 [ 1 ] , - 1 ,
L_4 , L_2 , NULL ) ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( L_5 , V_2 -> V_24 , V_25 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_26 ;
T_1 V_27 ;
T_1 V_28 ;
T_2 V_29 ;
struct V_30 * V_31 ;
struct V_16 * V_17 ;
int V_32 ;
F_3 ( V_6 , V_33 , & V_27 ) ;
V_27 = V_27 & 0x180 ;
V_26 = 0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_34 ; V_32 ++ ) {
V_31 = & V_2 -> V_21 [ V_32 ] ;
V_17 = V_31 -> V_22 [ 0 ] . V_17 ;
F_3 ( V_6 , V_35 + V_32 * 2 , & V_28 ) ;
V_29 = ( V_28 & V_36 ) <<
( V_37 - V_20 ) ;
F_12 ( L_6 , V_25 , V_32 ,
V_29 ) ;
if ( V_29 == V_26 )
continue;
V_31 -> V_38 = V_26 ;
V_31 -> V_39 = V_29 - 1 ;
V_17 -> V_40 = V_29 - V_26 ;
V_26 = V_29 ;
V_17 -> V_41 = 1 << 12 ;
V_17 -> V_42 = V_43 ;
V_17 -> V_44 = V_45 ;
V_17 -> V_46 = V_27 ? V_47 : V_48 ;
}
}
static int F_13 ( struct V_5 * V_6 , int V_49 )
{
struct V_1 * V_2 ;
struct V_50 V_51 [ 2 ] ;
struct V_3 V_52 ;
V_51 [ 0 ] . type = V_53 ;
V_51 [ 0 ] . V_54 = 2 ;
V_51 [ 0 ] . V_55 = true ;
V_51 [ 1 ] . type = V_56 ;
V_51 [ 1 ] . V_54 = 8 ;
V_51 [ 1 ] . V_55 = true ;
V_2 = F_14 ( 0 , F_15 ( V_51 ) , V_51 , 0 ) ;
if ( ! V_2 )
return - V_57 ;
F_12 ( L_7 , V_25 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = V_61 | V_62 ;
V_2 -> V_63 = V_62 ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = V_69 [ V_49 ] . V_68 ;
V_2 -> V_70 = F_16 ( V_6 ) ;
V_2 -> V_71 = F_9 ;
V_2 -> V_72 = NULL ;
F_11 ( V_2 , V_6 ) ;
F_1 ( V_2 , & V_52 ) ;
if ( F_17 ( V_2 ) ) {
F_12 ( L_8 , V_25 ) ;
goto V_73;
}
V_74 = F_18 ( & V_6 -> V_7 , V_65 ) ;
if ( ! V_74 ) {
F_19 ( V_75
L_9 ,
V_25 ) ;
F_19 ( V_75
L_10 ,
V_25 ) ;
}
F_12 ( L_11 , V_25 ) ;
return 0 ;
V_73:
F_20 ( V_2 ) ;
return - V_76 ;
}
static int T_3 F_21 ( struct V_5 * V_6 ,
const struct V_77 * V_78 )
{
int V_79 ;
F_22 ( L_12 , V_25 ) ;
F_23 ( V_80 , L_13 ) ;
if ( F_24 ( V_6 ) < 0 )
return - V_81 ;
V_79 = F_13 ( V_6 , V_78 -> V_82 ) ;
if ( V_79 == 0 )
V_83 = F_25 ( V_6 ) ;
return V_79 ;
}
static void T_4 F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_22 ( L_12 , V_25 ) ;
if ( V_74 )
F_27 ( V_74 ) ;
if ( ( V_2 = F_28 ( & V_6 -> V_7 ) ) == NULL )
return;
F_20 ( V_2 ) ;
}
static int T_5 F_29 ( void )
{
int V_84 ;
F_12 ( L_12 , V_25 ) ;
F_30 () ;
if ( ( V_84 = F_31 ( & V_85 ) ) < 0 )
goto V_86;
if ( ! V_83 ) {
V_83 = F_32 ( V_87 ,
V_88 , NULL ) ;
if ( V_83 == NULL ) {
F_22 ( L_14 ) ;
V_84 = - V_76 ;
goto V_89;
}
V_84 = F_21 ( V_83 , V_90 ) ;
if ( V_84 < 0 ) {
F_22 ( L_15 ) ;
V_84 = - V_76 ;
goto V_89;
}
}
return 0 ;
V_89:
F_33 ( & V_85 ) ;
V_86:
if ( V_83 != NULL )
F_34 ( V_83 ) ;
return V_84 ;
}
static void T_6 F_35 ( void )
{
F_12 ( L_12 , V_25 ) ;
F_33 ( & V_85 ) ;
if ( V_83 != NULL )
F_34 ( V_83 ) ;
}
