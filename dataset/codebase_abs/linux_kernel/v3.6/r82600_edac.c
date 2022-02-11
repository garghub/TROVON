static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_8 ) ;
if ( V_4 -> V_8 & F_4 ( 0 ) )
F_5 ( V_6 , V_7 ,
( ( V_9 ) F_4 ( 0 ) & ( V_9 ) F_4 ( 1 ) ) ,
( ( V_9 ) F_4 ( 0 ) & ( V_9 ) F_4 ( 1 ) ) ) ;
if ( V_4 -> V_8 & F_4 ( 1 ) )
F_5 ( V_6 , V_7 ,
( ( V_9 ) F_4 ( 0 ) & ( V_9 ) F_4 ( 1 ) ) ,
( ( V_9 ) F_4 ( 0 ) & ( V_9 ) F_4 ( 1 ) ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_10 )
{
int V_11 ;
V_9 V_12 , V_13 ;
V_9 V_14 ;
V_11 = 0 ;
V_12 = ( ( V_4 -> V_8 >> 12 ) & 0x7FFF ) << 13 ;
V_14 = ( V_4 -> V_8 >> 4 ) & 0xFF ;
V_13 = V_12 >> V_15 ;
if ( V_4 -> V_8 & F_4 ( 0 ) ) {
V_11 = 1 ;
if ( V_10 )
F_7 ( V_16 , V_2 , 1 ,
V_13 , 0 , V_14 ,
F_8 ( V_2 , V_13 ) ,
0 , - 1 ,
V_2 -> V_17 , L_1 ) ;
}
if ( V_4 -> V_8 & F_4 ( 1 ) ) {
V_11 = 1 ;
if ( V_10 )
F_7 ( V_18 , V_2 , 1 ,
V_13 , 0 , 0 ,
F_8 ( V_2 , V_13 ) ,
0 , - 1 ,
V_2 -> V_17 , L_1 ) ;
}
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( 1 , L_2 , V_2 -> V_19 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static inline int F_11 ( T_1 V_20 )
{
return V_20 & F_4 ( 5 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
T_1 V_26 ;
V_9 V_27 , V_28 ;
V_9 V_29 , V_30 , V_31 ;
V_30 = F_11 ( V_20 ) ;
V_29 = V_20 & F_4 ( 4 ) ;
V_28 = 0 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_32 ; V_25 ++ ) {
V_22 = V_2 -> V_33 [ V_25 ] ;
V_24 = V_22 -> V_34 [ 0 ] -> V_24 ;
F_13 ( V_6 , V_35 + V_25 , & V_26 ) ;
F_10 ( 1 , L_3 , V_25 , V_26 ) ;
V_27 = ( ( V_9 ) V_26 << 24 ) ;
F_10 ( 1 , L_4 ,
V_25 , V_27 , V_28 ) ;
if ( V_27 == V_28 )
continue;
V_31 = V_28 ;
V_22 -> V_36 = V_31 >> V_15 ;
V_22 -> V_37 = ( V_27 >> V_15 ) - 1 ;
V_24 -> V_38 = V_22 -> V_37 - V_22 -> V_36 + 1 ;
V_24 -> V_39 = 1 << 14 ;
V_24 -> V_40 = V_29 ? V_41 : V_42 ;
V_24 -> V_43 = V_44 ;
V_24 -> V_45 = V_30 ? V_46 : V_47 ;
V_28 = V_27 ;
}
}
static int F_14 ( struct V_5 * V_6 , int V_48 )
{
struct V_1 * V_2 ;
struct V_49 V_50 [ 2 ] ;
T_1 V_20 ;
V_9 V_8 ;
V_9 V_51 ;
V_9 V_52 ;
struct V_3 V_53 ;
F_10 ( 0 , L_5 ) ;
F_13 ( V_6 , V_54 , & V_20 ) ;
F_3 ( V_6 , V_7 , & V_8 ) ;
V_51 = V_8 & F_4 ( 31 ) ;
V_52 = V_20 & ( F_4 ( 0 ) | F_4 ( 1 ) ) ;
F_10 ( 2 , L_6 , V_52 ) ;
F_10 ( 2 , L_7 , V_20 ) ;
V_50 [ 0 ] . type = V_55 ;
V_50 [ 0 ] . V_56 = V_57 ;
V_50 [ 0 ] . V_58 = true ;
V_50 [ 1 ] . type = V_59 ;
V_50 [ 1 ] . V_56 = V_60 ;
V_50 [ 1 ] . V_58 = false ;
V_2 = F_15 ( 0 , F_16 ( V_50 ) , V_50 , 0 ) ;
if ( V_2 == NULL )
return - V_61 ;
F_10 ( 0 , L_8 , V_2 ) ;
V_2 -> V_6 = & V_6 -> V_62 ;
V_2 -> V_63 = V_64 | V_65 ;
V_2 -> V_66 = V_67 | V_68 | V_69 ;
V_2 -> V_70 = V_67 | V_68 | V_69 ;
if ( F_11 ( V_20 ) ) {
if ( V_51 )
F_10 ( 3 , L_9 ,
V_2 , V_8 ) ;
} else
V_2 -> V_70 = V_67 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_17 = L_10 ;
V_2 -> V_75 = F_17 ( V_6 ) ;
V_2 -> V_76 = F_9 ;
V_2 -> V_77 = NULL ;
F_12 ( V_2 , V_6 , V_20 ) ;
F_1 ( V_2 , & V_53 ) ;
if ( F_18 ( V_2 ) ) {
F_10 ( 3 , L_11 ) ;
goto V_78;
}
if ( V_79 ) {
F_10 ( 3 , L_12 ) ;
F_5 ( V_6 , V_7 , F_4 ( 31 ) , F_4 ( 31 ) ) ;
}
V_80 = F_19 ( & V_6 -> V_62 , V_72 ) ;
if ( ! V_80 ) {
F_20 ( V_81
L_13 ,
V_82 ) ;
F_20 ( V_81
L_14 ,
V_82 ) ;
}
F_10 ( 3 , L_15 ) ;
return 0 ;
V_78:
F_21 ( V_2 ) ;
return - V_83 ;
}
static int T_2 F_22 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
F_10 ( 0 , L_5 ) ;
return F_14 ( V_6 , V_85 -> V_86 ) ;
}
static void T_3 F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_10 ( 0 , L_5 ) ;
if ( V_80 )
F_24 ( V_80 ) ;
if ( ( V_2 = F_25 ( & V_6 -> V_62 ) ) == NULL )
return;
F_21 ( V_2 ) ;
}
static int T_4 F_26 ( void )
{
F_27 () ;
return F_28 ( & V_87 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_87 ) ;
}
