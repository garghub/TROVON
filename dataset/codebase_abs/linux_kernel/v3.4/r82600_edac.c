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
F_7 ( V_2 , V_14 , 0 ,
V_15 ,
F_8 ( V_2 , V_14 ) ,
0 , V_2 -> V_17 ) ;
}
if ( V_4 -> V_9 & F_4 ( 1 ) ) {
V_12 = 1 ;
if ( V_11 )
F_9 ( V_2 , V_14 , 0 ,
F_8 ( V_2 , V_14 ) ,
V_2 -> V_17 ) ;
}
return V_12 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_11 ( L_1 , V_2 -> V_18 , V_19 ) ;
F_1 ( V_2 , & V_4 ) ;
F_6 ( V_2 , & V_4 , 1 ) ;
}
static inline int F_12 ( T_1 V_20 )
{
return V_20 & F_4 ( 5 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
T_1 V_24 ;
V_10 V_25 , V_26 ;
V_10 V_27 , V_28 , V_29 ;
V_28 = F_12 ( V_20 ) ;
V_27 = V_20 & F_4 ( 4 ) ;
V_26 = 0 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_30 ; V_23 ++ ) {
V_22 = & V_2 -> V_31 [ V_23 ] ;
F_14 ( V_6 , V_32 + V_23 , & V_24 ) ;
F_11 ( L_2 , V_19 , V_23 , V_24 ) ;
V_25 = ( ( V_10 ) V_24 << 24 ) ;
F_11 ( L_3 ,
V_19 , V_23 , V_25 , V_26 ) ;
if ( V_25 == V_26 )
continue;
V_29 = V_26 ;
V_22 -> V_33 = V_29 >> V_16 ;
V_22 -> V_34 = ( V_25 >> V_16 ) - 1 ;
V_22 -> V_35 = V_22 -> V_34 - V_22 -> V_33 + 1 ;
V_22 -> V_36 = 1 << 14 ;
V_22 -> V_37 = V_27 ? V_38 : V_39 ;
V_22 -> V_40 = V_41 ;
V_22 -> V_42 = V_28 ? V_43 : V_44 ;
V_26 = V_25 ;
}
}
static int F_15 ( struct V_5 * V_6 , int V_45 )
{
struct V_1 * V_2 ;
T_1 V_20 ;
V_10 V_9 ;
V_10 V_46 ;
V_10 V_47 ;
struct V_3 V_48 ;
F_16 ( L_4 , V_19 ) ;
F_14 ( V_6 , V_49 , & V_20 ) ;
F_3 ( V_6 , V_8 , & V_9 ) ;
V_46 = V_9 & F_4 ( 31 ) ;
V_47 = V_20 & ( F_4 ( 0 ) | F_4 ( 1 ) ) ;
F_17 ( L_5 , V_19 ,
V_47 ) ;
F_17 ( L_6 , V_19 , V_20 ) ;
V_2 = F_18 ( 0 , V_50 , V_51 , 0 ) ;
if ( V_2 == NULL )
return - V_52 ;
F_16 ( L_7 , V_19 , V_2 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_53 = V_54 | V_55 ;
V_2 -> V_56 = V_57 | V_58 | V_59 ;
V_2 -> V_60 = V_57 | V_58 | V_59 ;
if ( F_12 ( V_20 ) ) {
if ( V_46 )
F_19 ( L_8
L_9 , V_19 , V_2 , V_9 ) ;
} else
V_2 -> V_60 = V_57 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_17 = L_10 ;
V_2 -> V_65 = F_20 ( V_6 ) ;
V_2 -> V_66 = F_10 ;
V_2 -> V_67 = NULL ;
F_13 ( V_2 , V_6 , V_20 ) ;
F_1 ( V_2 , & V_48 ) ;
if ( F_21 ( V_2 ) ) {
F_19 ( L_11 , V_19 ) ;
goto V_68;
}
if ( V_69 ) {
F_19 ( L_12 ,
V_19 ) ;
F_5 ( V_6 , V_8 , F_4 ( 31 ) , F_4 ( 31 ) ) ;
}
V_70 = F_22 ( & V_6 -> V_7 , V_62 ) ;
if ( ! V_70 ) {
F_23 ( V_71
L_13 ,
V_19 ) ;
F_23 ( V_71
L_14 ,
V_19 ) ;
}
F_19 ( L_15 , V_19 ) ;
return 0 ;
V_68:
F_24 ( V_2 ) ;
return - V_72 ;
}
static int T_2 F_25 ( struct V_5 * V_6 ,
const struct V_73 * V_74 )
{
F_16 ( L_4 , V_19 ) ;
return F_15 ( V_6 , V_74 -> V_75 ) ;
}
static void T_3 F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_16 ( L_4 , V_19 ) ;
if ( V_70 )
F_27 ( V_70 ) ;
if ( ( V_2 = F_28 ( & V_6 -> V_7 ) ) == NULL )
return;
F_24 ( V_2 ) ;
}
static int T_4 F_29 ( void )
{
F_30 () ;
return F_31 ( & V_76 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_76 ) ;
}
