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
int V_16 ;
if ( ! ( V_4 -> V_14 & 0x0003 ) )
return 0 ;
if ( ! V_15 )
return 1 ;
if ( ( V_4 -> V_9 ^ V_4 -> V_14 ) & 0x0003 ) {
F_7 ( V_2 , L_1 ) ;
V_4 -> V_9 = V_4 -> V_14 ;
}
V_4 -> V_11 >>= V_17 ;
V_16 = F_8 ( V_2 , V_4 -> V_11 ) ;
if ( V_4 -> V_9 & 0x0002 )
F_9 ( V_2 , V_4 -> V_11 , 0 , V_16 , L_2 ) ;
else
F_10 ( V_2 , V_4 -> V_11 , 0 , V_4 -> V_13 , V_16 , 0 ,
L_2 ) ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_12 ( L_3 , V_2 -> V_18 , V_19 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned long V_20 ;
T_1 V_21 ;
T_1 V_22 ;
T_2 V_23 ;
struct V_24 * V_25 ;
int V_26 ;
F_3 ( V_6 , V_27 , & V_21 ) ;
V_21 = V_21 & 0x180 ;
V_20 = 0 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_28 ; V_26 ++ ) {
V_25 = & V_2 -> V_29 [ V_26 ] ;
F_3 ( V_6 , V_30 + V_26 * 2 , & V_22 ) ;
V_23 = ( V_22 & V_31 ) <<
( V_32 - V_17 ) ;
F_14 ( L_4 , V_19 , V_26 ,
V_23 ) ;
if ( V_23 == V_20 )
continue;
V_25 -> V_33 = V_20 ;
V_25 -> V_34 = V_23 - 1 ;
V_25 -> V_35 = V_23 - V_20 ;
V_20 = V_23 ;
V_25 -> V_36 = 1 << 12 ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_40 ;
V_25 -> V_41 = V_21 ? V_42 : V_43 ;
}
}
static int F_15 ( struct V_5 * V_6 , int V_44 )
{
struct V_1 * V_2 ;
struct V_3 V_45 ;
V_2 = F_16 ( 0 , 16 , 1 , 0 ) ;
if ( ! V_2 )
return - V_46 ;
F_14 ( L_5 , V_19 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = V_50 | V_51 ;
V_2 -> V_52 = V_51 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = V_58 [ V_44 ] . V_57 ;
V_2 -> V_59 = F_17 ( V_6 ) ;
V_2 -> V_60 = F_11 ;
V_2 -> V_61 = NULL ;
F_13 ( V_2 , V_6 ) ;
F_1 ( V_2 , & V_45 ) ;
if ( F_18 ( V_2 ) ) {
F_14 ( L_6 , V_19 ) ;
goto V_62;
}
V_63 = F_19 ( & V_6 -> V_7 , V_54 ) ;
if ( ! V_63 ) {
F_20 ( V_64
L_7 ,
V_19 ) ;
F_20 ( V_64
L_8 ,
V_19 ) ;
}
F_14 ( L_9 , V_19 ) ;
return 0 ;
V_62:
F_21 ( V_2 ) ;
return - V_65 ;
}
static int T_3 F_22 ( struct V_5 * V_6 ,
const struct V_66 * V_67 )
{
int V_68 ;
F_23 ( L_10 , V_19 ) ;
F_24 ( V_69 , L_11 ) ;
if ( F_25 ( V_6 ) < 0 )
return - V_70 ;
V_68 = F_15 ( V_6 , V_67 -> V_71 ) ;
if ( V_68 == 0 )
V_72 = F_26 ( V_6 ) ;
return V_68 ;
}
static void T_4 F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_23 ( L_10 , V_19 ) ;
if ( V_63 )
F_28 ( V_63 ) ;
if ( ( V_2 = F_29 ( & V_6 -> V_7 ) ) == NULL )
return;
F_21 ( V_2 ) ;
}
static int T_5 F_30 ( void )
{
int V_73 ;
F_14 ( L_10 , V_19 ) ;
F_31 () ;
if ( ( V_73 = F_32 ( & V_74 ) ) < 0 )
goto V_75;
if ( ! V_72 ) {
V_72 = F_33 ( V_76 ,
V_77 , NULL ) ;
if ( V_72 == NULL ) {
F_23 ( L_12 ) ;
V_73 = - V_65 ;
goto V_78;
}
V_73 = F_22 ( V_72 , V_79 ) ;
if ( V_73 < 0 ) {
F_23 ( L_13 ) ;
V_73 = - V_65 ;
goto V_78;
}
}
return 0 ;
V_78:
F_34 ( & V_74 ) ;
V_75:
if ( V_72 != NULL )
F_35 ( V_72 ) ;
return V_73 ;
}
static void T_6 F_36 ( void )
{
F_14 ( L_10 , V_19 ) ;
F_34 ( & V_74 ) ;
if ( V_72 != NULL )
F_35 ( V_72 ) ;
}
