static void F_1 ( T_1 V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 + V_1 ) ;
if ( ! ( V_2 & V_4 ) )
return;
while ( ! ( V_2 & V_5 ) ) {
F_3 () ;
V_2 = F_2 ( V_3 + V_1 ) ;
}
}
static int F_4 ( void )
{
F_5 ( V_3 , V_6 ,
F_6 ( V_7 ) ) ;
F_5 ( V_3 , V_8 ,
F_6 ( V_9 ) ) ;
if ( V_10 == V_11 ) {
F_5 ( V_3 , V_12 ,
F_6 ( V_13 ) ) ;
F_7 ( V_3 , V_14 ,
F_6 ( V_14 ) ) ;
} else {
F_5 ( V_3 , V_12 ,
F_6 ( V_15 ) ) ;
}
F_7 ( V_3 , V_16 ,
F_6 ( V_16 ) ) ;
return 0 ;
}
static void F_8 ( void )
{
F_7 ( V_3 , V_8 ,
F_6 ( V_9 ) ) ;
F_1 ( V_17 ) ;
F_1 ( V_18 ) ;
F_7 ( V_3 , V_6 ,
F_6 ( V_7 ) ) ;
if ( V_10 == V_11 )
F_7 ( V_3 , V_12 ,
F_6 ( V_13 ) ) ;
else
F_7 ( V_3 , V_12 ,
F_6 ( V_15 ) ) ;
}
static void T_2 F_9 ( void )
{
V_6 = F_10 ( V_7 ,
F_6 ( V_7 ) ) ;
if ( ! V_6 )
goto V_19;
if ( V_10 == V_11 )
V_12 = F_10 (
V_13 ,
F_6 ( V_13 ) ) ;
else
V_12 = F_10 (
V_15 ,
F_6 ( V_15 ) ) ;
if ( ! V_12 )
goto V_20;
V_8 = F_10 ( V_9 ,
F_6 ( V_9 ) ) ;
if ( ! V_8 )
goto V_21;
F_11 ( & V_22 ) ;
return;
V_21:
F_12 ( V_12 ) ;
V_20:
F_12 ( V_6 ) ;
V_19:
F_13 ( L_1 ,
V_23 ) ;
}
static void T_2 F_9 ( void ) {}
static unsigned long F_14 ( void )
{
unsigned long V_24 = 0 ;
void T_3 * V_25 ;
struct V_26 * V_27 ;
V_27 = F_15 ( NULL , NULL , L_2 ) ;
if ( V_27 ) {
V_25 = F_16 ( V_27 , 0 ) ;
if ( V_25 )
V_24 = F_2 ( V_25 + 8 ) ;
F_17 ( V_25 ) ;
}
return V_24 ;
}
static void T_2 F_18 ( struct V_28 * V_29 )
{
struct V_30 V_31 ;
struct V_32 * V_32 ;
unsigned long V_33 = 24000000 ;
char * V_34 ;
unsigned int V_24 = F_14 () ;
V_34 = V_24 & 1 ? L_3 : L_4 ;
V_32 = F_19 ( NULL , V_34 ) ;
if ( F_20 ( V_32 ) ) {
F_21 ( L_5
L_6 , V_23 ,
V_34 ) ;
} else {
V_33 = F_22 ( V_32 ) ;
}
V_31 . V_35 = V_36 ;
V_31 . V_37 = L_7 ;
V_31 . V_34 = NULL ;
V_31 . V_38 = V_39 ;
V_31 . V_40 = V_33 ;
F_23 ( V_29 , & V_31 , 1 ) ;
}
static void T_2 F_24 ( struct V_26 * V_27 ,
enum V_10 V_41 )
{
struct V_28 * V_29 ;
V_10 = V_41 ;
V_3 = F_16 ( V_27 , 0 ) ;
if ( ! V_3 )
F_25 ( L_8 , V_23 ) ;
V_29 = F_26 ( V_27 , V_3 , V_42 ) ;
if ( ! V_29 )
F_25 ( L_9 , V_23 ) ;
F_27 ( V_29 , V_43 ,
F_6 ( V_43 ) ,
V_44 ) ;
F_18 ( V_29 ) ;
if ( V_10 == V_11 ) {
F_28 ( V_29 , V_45 ,
F_6 ( V_45 ) ) ;
if ( F_29 ( L_7 ) == 24000000 ) {
V_46 [ V_47 ] . V_48 =
V_49 ;
V_46 [ V_50 ] . V_48 =
V_51 ;
}
if ( F_29 ( L_10 ) == 24000000 )
V_46 [ V_52 ] . V_48 =
V_53 ;
F_30 ( V_29 , V_46 ,
F_6 ( V_46 ) , V_3 ) ;
} else {
if ( F_29 ( L_7 ) == 24000000 ) {
V_54 [ V_47 ] . V_48 =
V_55 ;
V_54 [ V_50 ] . V_48 =
V_56 ;
V_54 [ V_52 ] . V_48 =
V_57 ;
}
F_30 ( V_29 , V_54 ,
F_6 ( V_54 ) , V_3 ) ;
}
F_23 ( V_29 , V_58 ,
F_6 ( V_58 ) ) ;
F_28 ( V_29 , V_59 ,
F_6 ( V_59 ) ) ;
F_31 ( V_29 , V_60 ,
F_6 ( V_60 ) ) ;
F_32 ( V_29 , V_61 ,
F_6 ( V_61 ) ) ;
if ( V_10 == V_11 ) {
F_23 ( V_29 , V_62 ,
F_6 ( V_62 ) ) ;
F_28 ( V_29 , V_63 ,
F_6 ( V_63 ) ) ;
F_31 ( V_29 , V_64 ,
F_6 ( V_64 ) ) ;
F_32 ( V_29 , V_65 ,
F_6 ( V_65 ) ) ;
F_33 ( V_29 , V_66 ,
F_6 ( V_66 ) ) ;
} else {
F_28 ( V_29 , V_67 ,
F_6 ( V_67 ) ) ;
F_31 ( V_29 , V_68 ,
F_6 ( V_68 ) ) ;
F_32 ( V_29 , V_69 ,
F_6 ( V_69 ) ) ;
F_33 ( V_29 , V_70 ,
F_6 ( V_70 ) ) ;
}
F_33 ( V_29 , V_71 ,
F_6 ( V_71 ) ) ;
F_9 () ;
F_34 ( L_11
L_12 ,
V_10 == V_11 ? L_13 : L_14 ,
F_29 ( L_15 ) , F_29 ( L_16 ) ,
F_29 ( L_17 ) , F_29 ( L_18 ) ,
F_29 ( L_19 ) ) ;
}
static void T_2 F_35 ( struct V_26 * V_27 )
{
F_24 ( V_27 , V_11 ) ;
}
static void T_2 F_36 ( struct V_26 * V_27 )
{
F_24 ( V_27 , V_72 ) ;
}
