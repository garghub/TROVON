static T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_2 V_4 , V_5 ;
F_2 ( V_3 ) ;
do {
V_5 = F_3 ( V_6 + F_4 ( 1 , V_7 ) ) ;
V_4 = F_3 ( V_6 + F_4 ( 0 , V_7 ) ) ;
} while ( V_5 != F_3 ( V_6 + F_4 ( 1 , V_7 ) ) );
F_5 ( V_3 ) ;
return ( V_5 << 16 ) | V_4 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
return F_3 ( V_6 + F_4 ( 0 , V_7 ) ) ;
}
static struct V_8 * F_7 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , struct V_8 , V_10 ) ;
}
static int F_9 ( struct V_9 * V_11 )
{
struct V_8 * V_12 = F_7 ( V_11 ) ;
void T_3 * V_13 = V_12 -> V_13 ;
F_10 ( 0xff , V_13 + F_4 ( 2 , V_14 ) ) ;
F_10 ( V_15 , V_13 + F_4 ( 2 , V_16 ) ) ;
if ( ! F_11 ( V_11 ) )
F_12 ( V_12 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_11 )
{
struct V_8 * V_12 = F_7 ( V_11 ) ;
void T_3 * V_13 = V_12 -> V_13 ;
if ( F_14 ( V_11 ) || F_15 ( V_11 ) )
F_9 ( V_11 ) ;
F_16 ( V_12 -> V_17 ) ;
F_10 ( V_18 | V_19 | V_20 |
V_21 , V_13 + F_4 ( 2 , V_22 ) ) ;
F_10 ( V_23 , V_13 + F_4 ( 2 , V_24 ) ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_11 )
{
struct V_8 * V_12 = F_7 ( V_11 ) ;
void T_3 * V_13 = V_12 -> V_13 ;
if ( F_14 ( V_11 ) || F_15 ( V_11 ) )
F_9 ( V_11 ) ;
F_16 ( V_12 -> V_17 ) ;
F_10 ( V_18 | V_20 | V_21 ,
V_13 + F_4 ( 2 , V_22 ) ) ;
F_10 ( ( 32768 + V_25 / 2 ) / V_25 , V_6 + F_4 ( 2 , V_26 ) ) ;
F_10 ( V_23 , V_13 + F_4 ( 2 , V_24 ) ) ;
F_10 ( V_27 | V_28 , V_13 +
F_4 ( 2 , V_16 ) ) ;
return 0 ;
}
static int F_18 ( unsigned long V_29 , struct V_9 * V_11 )
{
F_10 ( V_29 , V_6 + F_4 ( 2 , V_26 ) ) ;
F_10 ( V_27 | V_28 ,
V_6 + F_4 ( 2 , V_16 ) ) ;
return 0 ;
}
static T_4 F_19 ( int V_30 , void * V_31 )
{
struct V_8 * V_32 = V_31 ;
unsigned int V_33 ;
V_33 = F_3 ( V_32 -> V_13 + F_4 ( 2 , V_34 ) ) ;
if ( V_33 & V_23 ) {
V_32 -> V_10 . V_35 ( & V_32 -> V_10 ) ;
return V_36 ;
}
return V_37 ;
}
static int T_5 F_20 ( struct V_38 * V_39 , int V_40 )
{
int V_41 ;
struct V_17 * V_42 = V_39 -> V_17 [ 2 ] ;
int V_30 = V_39 -> V_30 [ 2 ] ;
V_41 = F_21 ( V_39 -> V_43 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_21 ( V_42 ) ;
if ( V_41 ) {
F_22 ( V_39 -> V_43 ) ;
return V_41 ;
}
F_12 ( V_42 ) ;
V_10 . V_13 = V_39 -> V_13 ;
V_10 . V_17 = V_42 ;
V_18 = V_40 ;
V_10 . V_10 . V_44 = F_23 ( 0 ) ;
V_41 = F_24 ( V_30 , F_19 , V_45 , L_1 , & V_10 ) ;
if ( V_41 ) {
F_25 ( V_42 ) ;
F_22 ( V_39 -> V_43 ) ;
return V_41 ;
}
F_26 ( & V_10 . V_10 , 32768 , 1 , 0xffff ) ;
return V_41 ;
}
static int T_5 F_20 ( struct V_38 * V_39 , int V_40 )
{
return 0 ;
}
static void T_5 F_27 ( struct V_38 * V_39 , int V_46 )
{
F_10 ( V_46
| V_20
| V_47
| V_48
| V_49 ,
V_6 + F_4 ( 0 , V_22 ) ) ;
F_10 ( 0x0000 , V_6 + F_4 ( 0 , V_50 ) ) ;
F_10 ( 0x8000 , V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_14 ) ) ;
F_10 ( V_27 , V_6 + F_4 ( 0 , V_16 ) ) ;
F_10 ( V_51
| V_20
| V_47 ,
V_6 + F_4 ( 1 , V_22 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 1 , V_14 ) ) ;
F_10 ( V_27 , V_6 + F_4 ( 1 , V_16 ) ) ;
F_10 ( V_52 , V_6 + V_53 ) ;
F_10 ( V_54 , V_6 + V_55 ) ;
}
static void T_5 F_28 ( struct V_38 * V_39 , int V_46 )
{
F_10 ( V_46
| V_20
| V_47 ,
V_6 + F_4 ( 0 , V_22 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_14 ) ) ;
F_10 ( V_27 , V_6 + F_4 ( 0 , V_16 ) ) ;
F_10 ( V_54 , V_6 + V_55 ) ;
}
static int T_5 F_29 ( void )
{
static char V_56 [] V_57
= V_58 L_2 ;
struct V_59 * V_60 ;
struct V_38 * V_39 ;
struct V_17 * V_61 ;
T_2 V_62 , V_63 = 0 ;
int V_64 = - 1 ;
int V_40 = - 1 ;
int V_65 ;
int V_41 ;
V_39 = F_30 ( V_66 ) ;
if ( ! V_39 ) {
F_31 ( L_3 ) ;
return - V_67 ;
}
V_6 = V_39 -> V_13 ;
V_60 = V_39 -> V_60 ;
V_61 = V_39 -> V_17 [ 0 ] ;
V_41 = F_21 ( V_61 ) ;
if ( V_41 ) {
F_31 ( L_4 ) ;
goto V_68;
}
V_62 = ( T_2 ) F_32 ( V_61 ) ;
for ( V_65 = 0 ; V_65 < 5 ; V_65 ++ ) {
unsigned V_69 = V_70 [ V_65 ] ;
unsigned V_71 ;
if ( ! V_69 ) {
V_40 = V_65 ;
continue;
}
V_71 = V_62 / V_69 ;
F_31 ( L_5 , V_62 , V_69 , V_65 , V_71 ) ;
if ( V_64 > 0 ) {
if ( V_71 < 5 * 1000 * 1000 )
continue;
}
V_63 = V_71 ;
V_64 = V_65 ;
}
F_33 ( V_56 , V_72 . V_73 , V_66 ,
V_63 / 1000000 ,
( ( V_63 + 500000 ) % 1000000 ) / 1000 ) ;
if ( V_39 -> V_74 && V_39 -> V_74 -> V_75 == 32 ) {
V_72 . V_76 = F_6 ;
F_28 ( V_39 , V_64 ) ;
} else {
V_41 = F_21 ( V_39 -> V_17 [ 1 ] ) ;
if ( V_41 ) {
F_31 ( L_6 ) ;
goto V_77;
}
F_27 ( V_39 , V_64 ) ;
}
V_41 = F_34 ( & V_72 , V_63 ) ;
if ( V_41 )
goto V_78;
V_41 = F_20 ( V_39 , V_40 ) ;
if ( V_41 )
goto V_79;
return 0 ;
V_79:
F_35 ( & V_72 ) ;
V_78:
if ( ! V_39 -> V_74 || V_39 -> V_74 -> V_75 != 32 )
F_22 ( V_39 -> V_17 [ 1 ] ) ;
V_77:
F_22 ( V_61 ) ;
V_68:
F_36 ( V_39 ) ;
return V_41 ;
}
