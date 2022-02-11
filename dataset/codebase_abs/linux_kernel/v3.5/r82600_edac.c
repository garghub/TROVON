static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_6 , V_8 , & V_4 -> V_9 ) ;
if ( V_4 -> V_9 & F_4 ( 0 ) )
F_5 ( V_6 , V_8 ,
( ( V_10 ) F_4 ( 0 ) & ( V_10 ) F_4 ( 1 ) ) ,
( ( V_10 ) F_4 ( 0 ) & ( V_10 ) F_4 ( 1 ) ) ) ;
if ( V_4 -> V_9 & F_4 ( 1 ) )
F_5 ( V_6 , V_8 ,
( ( V_10 ) F_4 ( 0 ) & ( V_10 ) F_4 ( 1 ) ) ,
( ( V_10 ) F_4 ( 0 ) & ( V_10 ) F_4 ( 1 ) ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_11 )
{
int V_12 ;
V_10 V_13 , V_14 ;
V_10 V_15 ;
V_12 = 0 ;
V_13 = ( ( V_4 -> V_9 >> 12 ) & 0x7FFF ) << 13 ;
V_15 = ( V_4 -> V_9 >> 4 ) & 0xFF ;
V_14 = V_13 >> V_16 ;
if ( V_4 -> V_9 & F_4 ( 0 ) ) {
V_12 = 1 ;
if ( V_11 )
F_7 ( V_17 , V_2 ,
V_14 , 0 , V_15 ,
F_8 ( V_2 , V_14 ) ,
0 , - 1 ,
V_2 -> V_18 , L_1 , NULL ) ;
}
if ( V_4 -> V_9 & F_4 ( 1 ) ) {
V_12 = 1 ;
if ( V_11 )
F_7 ( V_19 , V_2 ,
V_14 , 0 , 0 ,
F_8 ( V_2 , V_14 ) ,
0 , - 1 ,
V_2 -> V_18 , L_1 , NULL ) ;
}
return V_12 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( L_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static inline int F_11 ( T_1 V_22 )
{
return V_22 & F_4 ( 5 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_27 ;
T_1 V_28 ;
V_10 V_29 , V_30 ;
V_10 V_31 , V_32 , V_33 ;
V_32 = F_11 ( V_22 ) ;
V_31 = V_22 & F_4 ( 4 ) ;
V_30 = 0 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_34 ; V_27 ++ ) {
V_24 = & V_2 -> V_35 [ V_27 ] ;
V_26 = V_24 -> V_36 [ 0 ] . V_26 ;
F_13 ( V_6 , V_37 + V_27 , & V_28 ) ;
F_10 ( L_3 , V_21 , V_27 , V_28 ) ;
V_29 = ( ( V_10 ) V_28 << 24 ) ;
F_10 ( L_4 ,
V_21 , V_27 , V_29 , V_30 ) ;
if ( V_29 == V_30 )
continue;
V_33 = V_30 ;
V_24 -> V_38 = V_33 >> V_16 ;
V_24 -> V_39 = ( V_29 >> V_16 ) - 1 ;
V_26 -> V_40 = V_24 -> V_39 - V_24 -> V_38 + 1 ;
V_26 -> V_41 = 1 << 14 ;
V_26 -> V_42 = V_31 ? V_43 : V_44 ;
V_26 -> V_45 = V_46 ;
V_26 -> V_47 = V_32 ? V_48 : V_49 ;
V_30 = V_29 ;
}
}
static int F_14 ( struct V_5 * V_6 , int V_50 )
{
struct V_1 * V_2 ;
struct V_51 V_52 [ 2 ] ;
T_1 V_22 ;
V_10 V_9 ;
V_10 V_53 ;
V_10 V_54 ;
struct V_3 V_55 ;
F_15 ( L_5 , V_21 ) ;
F_13 ( V_6 , V_56 , & V_22 ) ;
F_3 ( V_6 , V_8 , & V_9 ) ;
V_53 = V_9 & F_4 ( 31 ) ;
V_54 = V_22 & ( F_4 ( 0 ) | F_4 ( 1 ) ) ;
F_16 ( L_6 , V_21 ,
V_54 ) ;
F_16 ( L_7 , V_21 , V_22 ) ;
V_52 [ 0 ] . type = V_57 ;
V_52 [ 0 ] . V_58 = V_59 ;
V_52 [ 0 ] . V_60 = true ;
V_52 [ 1 ] . type = V_61 ;
V_52 [ 1 ] . V_58 = V_62 ;
V_52 [ 1 ] . V_60 = false ;
V_2 = F_17 ( 0 , F_18 ( V_52 ) , V_52 , 0 ) ;
if ( V_2 == NULL )
return - V_63 ;
F_15 ( L_8 , V_21 , V_2 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_64 = V_65 | V_66 ;
V_2 -> V_67 = V_68 | V_69 | V_70 ;
V_2 -> V_71 = V_68 | V_69 | V_70 ;
if ( F_11 ( V_22 ) ) {
if ( V_53 )
F_19 ( L_9
L_10 , V_21 , V_2 , V_9 ) ;
} else
V_2 -> V_71 = V_68 ;
V_2 -> V_72 = V_73 ;
V_2 -> V_74 = V_75 ;
V_2 -> V_18 = L_11 ;
V_2 -> V_76 = F_20 ( V_6 ) ;
V_2 -> V_77 = F_9 ;
V_2 -> V_78 = NULL ;
F_12 ( V_2 , V_6 , V_22 ) ;
F_1 ( V_2 , & V_55 ) ;
if ( F_21 ( V_2 ) ) {
F_19 ( L_12 , V_21 ) ;
goto V_79;
}
if ( V_80 ) {
F_19 ( L_13 ,
V_21 ) ;
F_5 ( V_6 , V_8 , F_4 ( 31 ) , F_4 ( 31 ) ) ;
}
V_81 = F_22 ( & V_6 -> V_7 , V_73 ) ;
if ( ! V_81 ) {
F_23 ( V_82
L_14 ,
V_21 ) ;
F_23 ( V_82
L_15 ,
V_21 ) ;
}
F_19 ( L_16 , V_21 ) ;
return 0 ;
V_79:
F_24 ( V_2 ) ;
return - V_83 ;
}
static int T_2 F_25 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
F_15 ( L_5 , V_21 ) ;
return F_14 ( V_6 , V_85 -> V_86 ) ;
}
static void T_3 F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_15 ( L_5 , V_21 ) ;
if ( V_81 )
F_27 ( V_81 ) ;
if ( ( V_2 = F_28 ( & V_6 -> V_7 ) ) == NULL )
return;
F_24 ( V_2 ) ;
}
static int T_4 F_29 ( void )
{
F_30 () ;
return F_31 ( & V_87 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_87 ) ;
}
