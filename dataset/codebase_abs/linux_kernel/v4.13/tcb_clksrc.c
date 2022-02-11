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
void F_7 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_8 ( V_9 ) ; V_8 ++ ) {
V_9 [ V_8 ] . V_10 = F_9 ( V_6 + F_4 ( V_8 , V_11 ) ) ;
V_9 [ V_8 ] . V_12 = F_9 ( V_6 + F_4 ( V_8 , V_13 ) ) ;
V_9 [ V_8 ] . V_14 = F_9 ( V_6 + F_4 ( V_8 , V_15 ) ) ;
V_9 [ V_8 ] . V_16 = ! ! ( F_9 ( V_6 + F_4 ( V_8 , V_17 ) ) &
V_18 ) ;
}
V_19 = F_9 ( V_6 + V_20 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_8 ( V_9 ) ; V_8 ++ ) {
F_11 ( V_9 [ V_8 ] . V_10 , V_6 + F_4 ( V_8 , V_11 ) ) ;
F_11 ( V_9 [ V_8 ] . V_14 , V_6 + F_4 ( V_8 , V_15 ) ) ;
F_11 ( 0 , V_6 + F_4 ( V_8 , V_21 ) ) ;
F_11 ( 0 , V_6 + F_4 ( V_8 , V_22 ) ) ;
F_11 ( 0xff , V_6 + F_4 ( V_8 , V_23 ) ) ;
F_11 ( V_9 [ V_8 ] . V_12 , V_6 + F_4 ( V_8 , V_24 ) ) ;
if ( V_9 [ V_8 ] . V_16 )
F_11 ( V_25 , V_6 + F_4 ( V_8 , V_26 ) ) ;
}
F_11 ( V_19 , V_6 + V_20 ) ;
F_11 ( V_27 , V_6 + V_28 ) ;
}
static struct V_29 * F_12 ( struct V_30 * V_31 )
{
return F_13 ( V_31 , struct V_29 , V_31 ) ;
}
static int F_14 ( struct V_30 * V_32 )
{
struct V_29 * V_33 = F_12 ( V_32 ) ;
void T_3 * V_34 = V_33 -> V_34 ;
F_11 ( 0xff , V_34 + F_4 ( 2 , V_23 ) ) ;
F_11 ( V_35 , V_34 + F_4 ( 2 , V_26 ) ) ;
if ( ! F_15 ( V_32 ) )
F_16 ( V_33 -> V_36 ) ;
return 0 ;
}
static int F_17 ( struct V_30 * V_32 )
{
struct V_29 * V_33 = F_12 ( V_32 ) ;
void T_3 * V_34 = V_33 -> V_34 ;
if ( F_18 ( V_32 ) || F_19 ( V_32 ) )
F_14 ( V_32 ) ;
F_20 ( V_33 -> V_36 ) ;
F_11 ( V_37 | V_38 | V_39 |
V_40 , V_34 + F_4 ( 2 , V_11 ) ) ;
F_11 ( V_41 , V_34 + F_4 ( 2 , V_24 ) ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_32 )
{
struct V_29 * V_33 = F_12 ( V_32 ) ;
void T_3 * V_34 = V_33 -> V_34 ;
if ( F_18 ( V_32 ) || F_19 ( V_32 ) )
F_14 ( V_32 ) ;
F_20 ( V_33 -> V_36 ) ;
F_11 ( V_37 | V_39 | V_40 ,
V_34 + F_4 ( 2 , V_11 ) ) ;
F_11 ( ( 32768 + V_42 / 2 ) / V_42 , V_6 + F_4 ( 2 , V_15 ) ) ;
F_11 ( V_41 , V_34 + F_4 ( 2 , V_24 ) ) ;
F_11 ( V_25 | V_43 , V_34 +
F_4 ( 2 , V_26 ) ) ;
return 0 ;
}
static int F_22 ( unsigned long V_44 , struct V_30 * V_32 )
{
F_23 ( V_44 , V_6 + F_4 ( 2 , V_15 ) ) ;
F_23 ( V_25 | V_43 ,
V_6 + F_4 ( 2 , V_26 ) ) ;
return 0 ;
}
static T_4 F_24 ( int V_45 , void * V_46 )
{
struct V_29 * V_47 = V_46 ;
unsigned int V_48 ;
V_48 = F_3 ( V_47 -> V_34 + F_4 ( 2 , V_17 ) ) ;
if ( V_48 & V_41 ) {
V_47 -> V_31 . V_49 ( & V_47 -> V_31 ) ;
return V_50 ;
}
return V_51 ;
}
static int T_5 F_25 ( struct V_52 * V_53 , int V_54 )
{
int V_55 ;
struct V_36 * V_56 = V_53 -> V_36 [ 2 ] ;
int V_45 = V_53 -> V_45 [ 2 ] ;
V_55 = F_26 ( V_53 -> V_57 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_26 ( V_56 ) ;
if ( V_55 ) {
F_27 ( V_53 -> V_57 ) ;
return V_55 ;
}
F_16 ( V_56 ) ;
V_31 . V_34 = V_53 -> V_34 ;
V_31 . V_36 = V_56 ;
V_37 = V_54 ;
V_31 . V_31 . V_58 = F_28 ( 0 ) ;
V_55 = F_29 ( V_45 , F_24 , V_59 , L_1 , & V_31 ) ;
if ( V_55 ) {
F_30 ( V_56 ) ;
F_27 ( V_53 -> V_57 ) ;
return V_55 ;
}
F_31 ( & V_31 . V_31 , 32768 , 1 , 0xffff ) ;
return V_55 ;
}
static int T_5 F_25 ( struct V_52 * V_53 , int V_54 )
{
return 0 ;
}
static void T_5 F_32 ( struct V_52 * V_53 , int V_60 )
{
F_11 ( V_60
| V_39
| V_61
| V_62
| V_63 ,
V_6 + F_4 ( 0 , V_11 ) ) ;
F_11 ( 0x0000 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_11 ( 0x8000 , V_6 + F_4 ( 0 , V_15 ) ) ;
F_11 ( 0xff , V_6 + F_4 ( 0 , V_23 ) ) ;
F_11 ( V_25 , V_6 + F_4 ( 0 , V_26 ) ) ;
F_11 ( V_64
| V_39
| V_61 ,
V_6 + F_4 ( 1 , V_11 ) ) ;
F_11 ( 0xff , V_6 + F_4 ( 1 , V_23 ) ) ;
F_11 ( V_25 , V_6 + F_4 ( 1 , V_26 ) ) ;
F_11 ( V_65 , V_6 + V_20 ) ;
F_11 ( V_27 , V_6 + V_28 ) ;
}
static void T_5 F_33 ( struct V_52 * V_53 , int V_60 )
{
F_11 ( V_60
| V_39
| V_61 ,
V_6 + F_4 ( 0 , V_11 ) ) ;
F_11 ( 0xff , V_6 + F_4 ( 0 , V_23 ) ) ;
F_11 ( V_25 , V_6 + F_4 ( 0 , V_26 ) ) ;
F_11 ( V_27 , V_6 + V_28 ) ;
}
static int T_5 F_34 ( void )
{
static char V_66 [] V_67
= V_68 L_2 ;
struct V_69 * V_70 ;
struct V_52 * V_53 ;
struct V_36 * V_71 ;
T_2 V_72 , V_73 = 0 ;
int V_74 = - 1 ;
int V_54 = - 1 ;
int V_8 ;
int V_55 ;
V_53 = F_35 ( V_75 ) ;
if ( ! V_53 ) {
F_36 ( L_3 ) ;
return - V_76 ;
}
V_6 = V_53 -> V_34 ;
V_70 = V_53 -> V_70 ;
V_71 = V_53 -> V_36 [ 0 ] ;
V_55 = F_26 ( V_71 ) ;
if ( V_55 ) {
F_36 ( L_4 ) ;
goto V_77;
}
V_72 = ( T_2 ) F_37 ( V_71 ) ;
for ( V_8 = 0 ; V_8 < 5 ; V_8 ++ ) {
unsigned V_78 = V_79 [ V_8 ] ;
unsigned V_80 ;
if ( ! V_78 ) {
V_54 = V_8 ;
continue;
}
V_80 = V_72 / V_78 ;
F_36 ( L_5 , V_72 , V_78 , V_8 , V_80 ) ;
if ( V_74 > 0 ) {
if ( V_80 < 5 * 1000 * 1000 )
continue;
}
V_73 = V_80 ;
V_74 = V_8 ;
}
F_38 ( V_66 , V_81 . V_82 , V_75 ,
V_73 / 1000000 ,
( ( V_73 + 500000 ) % 1000000 ) / 1000 ) ;
if ( V_53 -> V_83 && V_53 -> V_83 -> V_84 == 32 ) {
V_81 . V_85 = F_6 ;
F_33 ( V_53 , V_74 ) ;
} else {
V_55 = F_26 ( V_53 -> V_36 [ 1 ] ) ;
if ( V_55 ) {
F_36 ( L_6 ) ;
goto V_86;
}
F_32 ( V_53 , V_74 ) ;
}
V_55 = F_39 ( & V_81 , V_73 ) ;
if ( V_55 )
goto V_87;
V_55 = F_25 ( V_53 , V_54 ) ;
if ( V_55 )
goto V_88;
return 0 ;
V_88:
F_40 ( & V_81 ) ;
V_87:
if ( ! V_53 -> V_83 || V_53 -> V_83 -> V_84 != 32 )
F_27 ( V_53 -> V_36 [ 1 ] ) ;
V_86:
F_27 ( V_71 ) ;
V_77:
F_41 ( V_53 ) ;
return V_55 ;
}
