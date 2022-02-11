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
F_7 ( V_2 , V_2 -> V_14 [ V_13 ] . V_15 , 0 ,
V_13 , V_2 -> V_16 ) ;
}
}
if ( V_4 -> V_9 & F_4 ( 9 ) ) {
V_12 = 1 ;
if ( V_11 ) {
V_13 = V_4 -> V_9 & 0xf ;
F_8 ( V_2 , V_2 -> V_14 [ V_13 ] . V_15 , 0 ,
0 , V_13 , 0 , V_2 -> V_16 ) ;
}
}
return V_12 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_10 ( L_1 , V_17 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_5 * V_6 ,
enum V_18 V_19 )
{
struct V_20 * V_21 ;
V_10 V_22 , V_23 , V_24 , V_25 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 ; V_26 ++ ) {
V_21 = & V_2 -> V_14 [ V_26 ] ;
F_3 ( V_6 ,
V_28 + ( V_26 * 4 ) , & V_22 ) ;
if ( ! ( V_22 & F_4 ( 0 ) ) )
continue;
V_23 = V_22 & 0xff800000UL ;
V_24 = ( ( V_22 & 0xff80 ) << 16 ) | 0x7fffffUL ;
F_3 ( V_6 , V_29 , & V_25 ) ;
V_21 -> V_15 = V_23 >> V_30 ;
V_21 -> V_31 = ( V_24 + 1 ) >> V_30 ;
V_21 -> V_32 = V_21 -> V_15 + V_21 -> V_31 - 1 ;
V_21 -> V_33 = V_24 >> V_30 ;
V_21 -> V_34 = V_21 -> V_31 << V_30 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_37 = ( ( V_25 >> V_26 ) & 0x1 ) ? V_38 : V_39 ;
V_21 -> V_19 = V_19 ;
}
}
static int F_12 ( struct V_5 * V_6 , int V_40 )
{
static const enum V_18 V_41 [] = {
V_42 ,
V_43 ,
V_44 ,
V_44
} ;
struct V_1 * V_2 = NULL ;
V_10 V_45 ;
V_10 V_46 ;
struct V_3 V_47 ;
F_13 ( L_1 , V_17 ) ;
F_3 ( V_6 , V_8 , & V_45 ) ;
V_46 = ( V_45 >> 10 ) & 0x3 ;
V_2 = F_14 ( 0 , V_48 , V_49 , 0 ) ;
if ( V_2 == NULL ) {
return - V_50 ;
}
F_13 ( L_2 , V_17 , V_2 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = V_54 | V_55 | V_56 ;
V_2 -> V_57 = V_46 ?
( V_55 | V_56 ) : V_54 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = V_61 ;
V_2 -> V_16 = V_62 [ V_40 ] . V_16 ;
V_2 -> V_63 = F_15 ( V_6 ) ;
V_2 -> V_64 = F_9 ;
V_2 -> V_65 = NULL ;
F_11 ( V_2 , V_6 , V_41 [ V_46 ] ) ;
F_1 ( V_2 , & V_47 ) ;
if ( F_16 ( V_2 ) ) {
F_10 ( L_3 , V_17 ) ;
goto V_66;
}
V_67 = F_17 ( & V_6 -> V_7 , V_59 ) ;
if ( ! V_67 ) {
F_18 ( V_68
L_4 ,
V_17 ) ;
F_18 ( V_68
L_5 ,
V_17 ) ;
}
F_10 ( L_6 , V_17 ) ;
return 0 ;
V_66:
F_19 ( V_2 ) ;
return - V_69 ;
}
static int T_1 F_20 ( struct V_5 * V_6 ,
const struct V_70 * V_71 )
{
F_13 ( L_1 , V_17 ) ;
return F_12 ( V_6 , V_71 -> V_72 ) ;
}
static void T_2 F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_13 ( L_1 , V_17 ) ;
if ( V_67 )
F_22 ( V_67 ) ;
if ( ( V_2 = F_23 ( & V_6 -> V_7 ) ) == NULL )
return;
F_19 ( V_2 ) ;
}
static int T_3 F_24 ( void )
{
F_25 () ;
return F_26 ( & V_73 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_73 ) ;
}
