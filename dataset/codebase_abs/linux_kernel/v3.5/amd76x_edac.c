static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_6 , V_8 ,
& V_4 -> V_9 ) ;
if ( V_4 -> V_9 & F_4 ( 8 ) )
F_5 ( V_6 , V_8 ,
( V_10 ) F_4 ( 8 ) , ( V_10 ) F_4 ( 8 ) ) ;
if ( V_4 -> V_9 & F_4 ( 9 ) )
F_5 ( V_6 , V_8 ,
( V_10 ) F_4 ( 9 ) , ( V_10 ) F_4 ( 9 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_11 )
{
int V_12 ;
V_10 V_13 ;
V_12 = 0 ;
if ( V_4 -> V_9 & F_4 ( 8 ) ) {
V_12 = 1 ;
if ( V_11 ) {
V_13 = ( V_4 -> V_9 >> 4 ) & 0xf ;
F_7 ( V_14 , V_2 ,
V_2 -> V_15 [ V_13 ] . V_16 , 0 , 0 ,
V_13 , 0 , - 1 ,
V_2 -> V_17 , L_1 , NULL ) ;
}
}
if ( V_4 -> V_9 & F_4 ( 9 ) ) {
V_12 = 1 ;
if ( V_11 ) {
V_13 = V_4 -> V_9 & 0xf ;
F_7 ( V_18 , V_2 ,
V_2 -> V_15 [ V_13 ] . V_16 , 0 , 0 ,
V_13 , 0 , - 1 ,
V_2 -> V_17 , L_1 , NULL ) ;
}
}
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_9 ( L_2 , V_19 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_5 * V_6 ,
enum V_20 V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_10 V_26 , V_27 , V_28 , V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_23 = & V_2 -> V_15 [ V_30 ] ;
V_25 = V_23 -> V_32 [ 0 ] . V_25 ;
F_3 ( V_6 ,
V_33 + ( V_30 * 4 ) , & V_26 ) ;
if ( ! ( V_26 & F_4 ( 0 ) ) )
continue;
V_27 = V_26 & 0xff800000UL ;
V_28 = ( ( V_26 & 0xff80 ) << 16 ) | 0x7fffffUL ;
F_3 ( V_6 , V_34 , & V_29 ) ;
V_23 -> V_16 = V_27 >> V_35 ;
V_25 -> V_36 = ( V_28 + 1 ) >> V_35 ;
V_23 -> V_37 = V_23 -> V_16 + V_25 -> V_36 - 1 ;
V_23 -> V_38 = V_28 >> V_35 ;
V_25 -> V_39 = V_25 -> V_36 << V_35 ;
V_25 -> V_40 = V_41 ;
V_25 -> V_42 = ( ( V_29 >> V_30 ) & 0x1 ) ? V_43 : V_44 ;
V_25 -> V_21 = V_21 ;
}
}
static int F_11 ( struct V_5 * V_6 , int V_45 )
{
static const enum V_20 V_46 [] = {
V_47 ,
V_48 ,
V_49 ,
V_49
} ;
struct V_1 * V_2 ;
struct V_50 V_51 [ 2 ] ;
V_10 V_52 ;
V_10 V_53 ;
struct V_3 V_54 ;
F_12 ( L_2 , V_19 ) ;
F_3 ( V_6 , V_8 , & V_52 ) ;
V_53 = ( V_52 >> 10 ) & 0x3 ;
V_51 [ 0 ] . type = V_55 ;
V_51 [ 0 ] . V_56 = V_57 ;
V_51 [ 0 ] . V_58 = true ;
V_51 [ 1 ] . type = V_59 ;
V_51 [ 1 ] . V_56 = 1 ;
V_51 [ 1 ] . V_58 = false ;
V_2 = F_13 ( 0 , F_14 ( V_51 ) , V_51 , 0 ) ;
if ( V_2 == NULL )
return - V_60 ;
F_12 ( L_3 , V_19 , V_2 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_63 = V_64 | V_65 | V_66 ;
V_2 -> V_67 = V_53 ?
( V_65 | V_66 ) : V_64 ;
V_2 -> V_68 = V_69 ;
V_2 -> V_70 = V_71 ;
V_2 -> V_17 = V_72 [ V_45 ] . V_17 ;
V_2 -> V_73 = F_15 ( V_6 ) ;
V_2 -> V_74 = F_8 ;
V_2 -> V_75 = NULL ;
F_10 ( V_2 , V_6 , V_46 [ V_53 ] ) ;
F_1 ( V_2 , & V_54 ) ;
if ( F_16 ( V_2 ) ) {
F_9 ( L_4 , V_19 ) ;
goto V_76;
}
V_77 = F_17 ( & V_6 -> V_7 , V_69 ) ;
if ( ! V_77 ) {
F_18 ( V_78
L_5 ,
V_19 ) ;
F_18 ( V_78
L_6 ,
V_19 ) ;
}
F_9 ( L_7 , V_19 ) ;
return 0 ;
V_76:
F_19 ( V_2 ) ;
return - V_79 ;
}
static int T_1 F_20 ( struct V_5 * V_6 ,
const struct V_80 * V_81 )
{
F_12 ( L_2 , V_19 ) ;
return F_11 ( V_6 , V_81 -> V_82 ) ;
}
static void T_2 F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_12 ( L_2 , V_19 ) ;
if ( V_77 )
F_22 ( V_77 ) ;
if ( ( V_2 = F_23 ( & V_6 -> V_7 ) ) == NULL )
return;
F_19 ( V_2 ) ;
}
static int T_3 F_24 ( void )
{
F_25 () ;
return F_26 ( & V_83 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_83 ) ;
}
