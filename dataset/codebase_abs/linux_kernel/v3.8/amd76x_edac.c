static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_6 , V_7 ,
& V_4 -> V_8 ) ;
if ( V_4 -> V_8 & F_4 ( 8 ) )
F_5 ( V_6 , V_7 ,
( V_9 ) F_4 ( 8 ) , ( V_9 ) F_4 ( 8 ) ) ;
if ( V_4 -> V_8 & F_4 ( 9 ) )
F_5 ( V_6 , V_7 ,
( V_9 ) F_4 ( 9 ) , ( V_9 ) F_4 ( 9 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_10 )
{
int V_11 ;
V_9 V_12 ;
V_11 = 0 ;
if ( V_4 -> V_8 & F_4 ( 8 ) ) {
V_11 = 1 ;
if ( V_10 ) {
V_12 = ( V_4 -> V_8 >> 4 ) & 0xf ;
F_7 ( V_13 , V_2 , 1 ,
V_2 -> V_14 [ V_12 ] -> V_15 , 0 , 0 ,
V_12 , 0 , - 1 ,
V_2 -> V_16 , L_1 ) ;
}
}
if ( V_4 -> V_8 & F_4 ( 9 ) ) {
V_11 = 1 ;
if ( V_10 ) {
V_12 = V_4 -> V_8 & 0xf ;
F_7 ( V_17 , V_2 , 1 ,
V_2 -> V_14 [ V_12 ] -> V_15 , 0 , 0 ,
V_12 , 0 , - 1 ,
V_2 -> V_16 , L_1 ) ;
}
}
return V_11 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_9 ( 3 , L_2 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_5 * V_6 ,
enum V_18 V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_9 V_24 , V_25 , V_26 , V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ ) {
V_21 = V_2 -> V_14 [ V_28 ] ;
V_23 = V_21 -> V_30 [ 0 ] -> V_23 ;
F_3 ( V_6 ,
V_31 + ( V_28 * 4 ) , & V_24 ) ;
if ( ! ( V_24 & F_4 ( 0 ) ) )
continue;
V_25 = V_24 & 0xff800000UL ;
V_26 = ( ( V_24 & 0xff80 ) << 16 ) | 0x7fffffUL ;
F_3 ( V_6 , V_32 , & V_27 ) ;
V_21 -> V_15 = V_25 >> V_33 ;
V_23 -> V_34 = ( V_26 + 1 ) >> V_33 ;
V_21 -> V_35 = V_21 -> V_15 + V_23 -> V_34 - 1 ;
V_21 -> V_36 = V_26 >> V_33 ;
V_23 -> V_37 = V_23 -> V_34 << V_33 ;
V_23 -> V_38 = V_39 ;
V_23 -> V_40 = ( ( V_27 >> V_28 ) & 0x1 ) ? V_41 : V_42 ;
V_23 -> V_19 = V_19 ;
}
}
static int F_11 ( struct V_5 * V_6 , int V_43 )
{
static const enum V_18 V_44 [] = {
V_45 ,
V_46 ,
V_47 ,
V_47
} ;
struct V_1 * V_2 ;
struct V_48 V_49 [ 2 ] ;
V_9 V_50 ;
V_9 V_51 ;
struct V_3 V_52 ;
F_9 ( 0 , L_2 ) ;
F_3 ( V_6 , V_7 , & V_50 ) ;
V_51 = ( V_50 >> 10 ) & 0x3 ;
V_49 [ 0 ] . type = V_53 ;
V_49 [ 0 ] . V_54 = V_55 ;
V_49 [ 0 ] . V_56 = true ;
V_49 [ 1 ] . type = V_57 ;
V_49 [ 1 ] . V_54 = 1 ;
V_49 [ 1 ] . V_56 = false ;
V_2 = F_12 ( 0 , F_13 ( V_49 ) , V_49 , 0 ) ;
if ( V_2 == NULL )
return - V_58 ;
F_9 ( 0 , L_3 , V_2 ) ;
V_2 -> V_6 = & V_6 -> V_59 ;
V_2 -> V_60 = V_61 ;
V_2 -> V_62 = V_63 | V_64 | V_65 ;
V_2 -> V_66 = V_51 ?
( V_64 | V_65 ) : V_63 ;
V_2 -> V_67 = V_68 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_16 = V_71 [ V_43 ] . V_16 ;
V_2 -> V_72 = F_14 ( V_6 ) ;
V_2 -> V_73 = F_8 ;
V_2 -> V_74 = NULL ;
F_10 ( V_2 , V_6 , V_44 [ V_51 ] ) ;
F_1 ( V_2 , & V_52 ) ;
if ( F_15 ( V_2 ) ) {
F_9 ( 3 , L_4 ) ;
goto V_75;
}
V_76 = F_16 ( & V_6 -> V_59 , V_68 ) ;
if ( ! V_76 ) {
F_17 ( V_77
L_5 ,
V_78 ) ;
F_17 ( V_77
L_6 ,
V_78 ) ;
}
F_9 ( 3 , L_7 ) ;
return 0 ;
V_75:
F_18 ( V_2 ) ;
return - V_79 ;
}
static int F_19 ( struct V_5 * V_6 ,
const struct V_80 * V_81 )
{
F_9 ( 0 , L_2 ) ;
return F_11 ( V_6 , V_81 -> V_82 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_9 ( 0 , L_2 ) ;
if ( V_76 )
F_21 ( V_76 ) ;
if ( ( V_2 = F_22 ( & V_6 -> V_59 ) ) == NULL )
return;
F_18 ( V_2 ) ;
}
static int T_1 F_23 ( void )
{
F_24 () ;
return F_25 ( & V_83 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_83 ) ;
}
