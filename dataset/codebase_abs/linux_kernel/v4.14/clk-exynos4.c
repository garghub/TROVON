static void F_1 ( T_1 V_1 )
{
T_1 V_2 = F_2 ( V_3 + V_1 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_3 + V_1 ) ;
while ( ! ( V_2 & V_5 ) ) {
F_4 () ;
V_2 = F_2 ( V_3 + V_1 ) ;
}
}
static void F_5 ( T_1 V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 + V_1 ) ;
if ( ! ( V_2 & V_4 ) )
return;
while ( ! ( V_2 & V_5 ) ) {
F_4 () ;
V_2 = F_2 ( V_3 + V_1 ) ;
}
}
static int F_6 ( void )
{
F_7 ( V_3 , V_6 ,
F_8 ( V_7 ) ) ;
F_7 ( V_3 , V_8 ,
F_8 ( V_9 ) ) ;
F_1 ( V_10 ) ;
F_1 ( V_11 ) ;
if ( V_12 == V_13 ) {
F_7 ( V_3 , V_14 ,
F_8 ( V_15 ) ) ;
F_9 ( V_3 , V_16 ,
F_8 ( V_16 ) ) ;
} else {
F_7 ( V_3 , V_14 ,
F_8 ( V_17 ) ) ;
}
F_9 ( V_3 , V_18 ,
F_8 ( V_18 ) ) ;
return 0 ;
}
static void F_10 ( void )
{
F_9 ( V_3 , V_8 ,
F_8 ( V_9 ) ) ;
F_5 ( V_10 ) ;
F_5 ( V_11 ) ;
F_9 ( V_3 , V_6 ,
F_8 ( V_7 ) ) ;
if ( V_12 == V_13 )
F_9 ( V_3 , V_14 ,
F_8 ( V_15 ) ) ;
else
F_9 ( V_3 , V_14 ,
F_8 ( V_17 ) ) ;
}
static void T_2 F_11 ( void )
{
V_6 = F_12 ( V_7 ,
F_8 ( V_7 ) ) ;
if ( ! V_6 )
goto V_19;
if ( V_12 == V_13 )
V_14 = F_12 (
V_15 ,
F_8 ( V_15 ) ) ;
else
V_14 = F_12 (
V_17 ,
F_8 ( V_17 ) ) ;
if ( ! V_14 )
goto V_20;
V_8 = F_12 ( V_9 ,
F_8 ( V_9 ) ) ;
if ( ! V_8 )
goto V_21;
F_13 ( & V_22 ) ;
return;
V_21:
F_14 ( V_14 ) ;
V_20:
F_14 ( V_6 ) ;
V_19:
F_15 ( L_1 ,
V_23 ) ;
}
static void T_2 F_11 ( void ) {}
static unsigned long T_2 F_16 ( void )
{
unsigned long V_24 = 0 ;
void T_3 * V_25 ;
struct V_26 * V_27 ;
V_27 = F_17 ( NULL , NULL , L_2 ) ;
if ( V_27 ) {
V_25 = F_18 ( V_27 , 0 ) ;
if ( V_25 )
V_24 = F_2 ( V_25 + 8 ) ;
F_19 ( V_25 ) ;
}
return V_24 ;
}
static void T_2 F_20 ( struct V_28 * V_29 )
{
struct V_30 V_31 ;
struct V_32 * V_32 ;
unsigned long V_33 = 24000000 ;
char * V_34 ;
unsigned int V_24 = F_16 () ;
V_34 = V_24 & 1 ? L_3 : L_4 ;
V_32 = F_21 ( NULL , V_34 ) ;
if ( F_22 ( V_32 ) ) {
F_23 ( L_5
L_6 , V_23 ,
V_34 ) ;
} else {
V_33 = F_24 ( V_32 ) ;
}
V_31 . V_35 = V_36 ;
V_31 . V_37 = L_7 ;
V_31 . V_34 = NULL ;
V_31 . V_38 = 0 ;
V_31 . V_39 = V_33 ;
F_25 ( V_29 , & V_31 , 1 ) ;
}
static void T_2 F_26 ( void )
{
unsigned int V_40 ;
V_40 = ( F_27 ( 7 ) | F_28 ( 7 ) |
V_41 | V_42 |
V_43 | V_44 |
V_45 | V_46 ) ;
if ( F_29 () == 4 )
V_40 |= V_47 | V_48 |
V_49 | V_50 ;
F_30 ( V_40 , V_3 + V_51 ) ;
F_30 ( 0x0 , V_3 + V_52 ) ;
}
static void T_2 F_31 ( struct V_26 * V_27 ,
enum V_12 V_53 )
{
struct V_28 * V_29 ;
V_12 = V_53 ;
V_3 = F_18 ( V_27 , 0 ) ;
if ( ! V_3 )
F_32 ( L_8 , V_23 ) ;
V_29 = F_33 ( V_27 , V_3 , V_54 ) ;
F_34 ( V_29 , V_55 ,
F_8 ( V_55 ) ,
V_56 ) ;
F_20 ( V_29 ) ;
if ( V_12 == V_13 ) {
F_35 ( V_29 , V_57 ,
F_8 ( V_57 ) ) ;
if ( F_36 ( L_7 ) == 24000000 ) {
V_58 [ V_59 ] . V_60 =
V_61 ;
V_58 [ V_62 ] . V_60 =
V_63 ;
}
if ( F_36 ( L_9 ) == 24000000 )
V_58 [ V_64 ] . V_60 =
V_65 ;
F_37 ( V_29 , V_58 ,
F_8 ( V_58 ) , V_3 ) ;
} else {
if ( F_36 ( L_7 ) == 24000000 ) {
V_66 [ V_59 ] . V_60 =
V_67 ;
V_66 [ V_62 ] . V_60 =
V_68 ;
V_66 [ V_64 ] . V_60 =
V_69 ;
}
F_37 ( V_29 , V_66 ,
F_8 ( V_66 ) , V_3 ) ;
}
F_25 ( V_29 , V_70 ,
F_8 ( V_70 ) ) ;
F_35 ( V_29 , V_71 ,
F_8 ( V_71 ) ) ;
F_38 ( V_29 , V_72 ,
F_8 ( V_72 ) ) ;
F_39 ( V_29 , V_73 ,
F_8 ( V_73 ) ) ;
F_40 ( V_29 , V_74 ,
F_8 ( V_74 ) ) ;
if ( V_12 == V_13 ) {
F_25 ( V_29 , V_75 ,
F_8 ( V_75 ) ) ;
F_35 ( V_29 , V_76 ,
F_8 ( V_76 ) ) ;
F_38 ( V_29 , V_77 ,
F_8 ( V_77 ) ) ;
F_39 ( V_29 , V_78 ,
F_8 ( V_78 ) ) ;
F_41 ( V_29 , V_79 ,
F_8 ( V_79 ) ) ;
F_40 ( V_29 ,
V_80 ,
F_8 ( V_80 ) ) ;
F_42 ( V_29 , V_81 , L_10 ,
V_82 [ 0 ] , V_82 [ 1 ] , 0x14200 ,
V_83 , F_8 ( V_83 ) ,
V_84 | V_85 ) ;
} else {
F_35 ( V_29 , V_86 ,
F_8 ( V_86 ) ) ;
F_38 ( V_29 , V_87 ,
F_8 ( V_87 ) ) ;
F_39 ( V_29 , V_88 ,
F_8 ( V_88 ) ) ;
F_41 ( V_29 , V_89 ,
F_8 ( V_89 ) ) ;
F_40 ( V_29 ,
V_90 ,
F_8 ( V_90 ) ) ;
if ( F_43 ( L_11 ) ) {
F_42 ( V_29 , V_81 , L_10 ,
V_91 [ 0 ] , V_91 [ 1 ] , 0x14200 ,
V_92 , F_8 ( V_92 ) ,
V_84 | V_85 ) ;
} else {
F_42 ( V_29 , V_81 , L_10 ,
V_91 [ 0 ] , V_91 [ 1 ] , 0x14200 ,
V_93 , F_8 ( V_93 ) ,
V_84 | V_85 ) ;
}
}
F_41 ( V_29 , V_94 ,
F_8 ( V_94 ) ) ;
if ( V_53 == V_95 )
F_26 () ;
F_11 () ;
F_44 ( V_27 , V_29 ) ;
F_45 ( L_12
L_13 ,
V_12 == V_13 ? L_14 : L_15 ,
F_36 ( L_16 ) , F_36 ( L_17 ) ,
F_36 ( L_18 ) , F_36 ( L_19 ) ,
F_36 ( L_20 ) ) ;
}
static void T_2 F_46 ( struct V_26 * V_27 )
{
F_31 ( V_27 , V_13 ) ;
}
static void T_2 F_47 ( struct V_26 * V_27 )
{
F_31 ( V_27 , V_95 ) ;
}
