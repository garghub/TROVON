void F_1 ( void )
{
if ( V_1 && V_2 ) {
F_2 ( F_3 ( V_1 ) , V_1 ) ;
F_2 ( F_3 ( V_2 ) , V_2 ) ;
F_4 () ;
}
}
int T_1 F_5 ( void )
{
V_3 = F_6 ( V_4 , V_5 ) ;
V_6 = F_7 ( V_3 , V_5 ) ;
return 0 ;
}
void T_1 F_8 ( void )
{
struct V_7 V_8 [ 1 ] ;
V_8 [ 0 ] . V_9 = V_10 ;
V_8 [ 0 ] . V_11 = F_9 ( V_6 ) ;
V_8 [ 0 ] . V_12 = V_3 ;
V_8 [ 0 ] . type = V_13 ;
F_10 ( V_8 , F_11 ( V_8 ) ) ;
V_1 = ( void V_14 * ) V_8 [ 0 ] . V_9 ;
V_2 = ( void V_14 * ) V_15 ;
F_12 ( L_1 ,
( long long ) V_6 , V_8 [ 0 ] . V_9 ) ;
}
void T_1 F_8 ( void )
{}
void T_1 F_13 ( void )
{
void V_14 * V_16 ;
V_17 = F_14 ( V_18 , V_19 ) ;
F_15 ( ! V_17 ) ;
V_20 = F_14 ( V_21 , V_19 ) ;
F_15 ( ! V_20 ) ;
V_16 = F_14 ( V_22 , V_23 ) ;
F_15 ( ! V_16 ) ;
F_16 () ;
F_17 ( 0 , 29 , V_17 , V_16 ) ;
}
void F_18 ( void )
{
if ( V_17 )
F_19 ( 0x0 , V_17 + V_24 ) ;
}
bool F_20 ( void )
{
return ! ( F_21 ( V_17 + V_24 ) & 0x1 ) ;
}
void F_22 ( void )
{
T_2 V_25 = F_21 ( V_20 + V_26 ) ;
T_2 V_27 = F_21 ( V_17 + V_28 ) ;
T_2 V_29 = F_21 ( V_20 + V_30 ) ;
if ( V_25 && ! ( V_27 & F_23 ( V_31 ) ) ) {
F_24 ( L_2 , V_32 ) ;
F_19 ( 1 , V_20 + V_26 ) ;
if ( ! ( V_29 & V_33 ) ) {
F_19 ( 1 , V_20 + V_34 ) ;
V_29 |= V_35 ;
F_19 ( V_29 , V_20 + V_30 ) ;
}
}
}
void V_14 * F_25 ( void )
{
return V_36 ;
}
static void F_26 ( void )
{
F_27 ( 0x102 , 0x0 ) ;
}
static void F_28 ( unsigned long V_37 )
{
F_27 ( 0x100 , V_37 ) ;
}
static int T_1 F_29 ( void )
{
T_2 V_38 = 0 ;
if ( ! F_30 () )
return - V_39 ;
V_36 = F_14 ( V_40 , V_19 ) ;
if ( F_31 ( ! V_36 ) )
return - V_41 ;
V_38 = ( ( 1 << V_42 ) |
( 0x1 << 25 ) |
( 0x1 << V_43 ) |
( 0x1 << V_44 ) ) ;
if ( F_32 () == V_45 ) {
V_38 |= 0x2 << V_46 ;
} else {
V_38 |= ( ( 0x3 << V_46 ) |
( 1 << V_47 ) |
( 1 << V_48 ) |
( 1 << V_49 ) |
( 1 << V_50 ) ) ;
}
if ( F_32 () != V_45 )
F_27 ( 0x109 , V_38 ) ;
F_27 ( 0x102 , 0x1 ) ;
if ( F_33 () )
F_34 ( V_38 , V_51 ) ;
else
F_35 ( V_36 , V_38 , V_51 ) ;
V_52 . V_53 = F_26 ;
V_52 . V_54 = F_28 ;
return 0 ;
}
void V_14 * F_36 ( void )
{
return V_55 ;
}
static int T_1 F_37 ( void )
{
unsigned long V_56 ;
if ( F_30 () )
V_56 = V_57 ;
else if ( F_38 () )
V_56 = V_58 ;
else
return - V_41 ;
V_55 = F_14 ( V_56 , V_59 ) ;
if ( F_31 ( ! V_55 ) )
return - V_41 ;
return 0 ;
}
void T_1 F_39 ( void )
{
struct V_60 * V_61 ;
if ( ! F_40 () )
goto V_62;
V_61 = F_41 ( NULL , NULL , L_3 ) ;
V_17 = F_42 ( V_61 , 0 ) ;
F_31 ( ! V_17 ) ;
V_61 = F_41 ( NULL , NULL , L_4 ) ;
V_20 = F_42 ( V_61 , 0 ) ;
F_31 ( ! V_20 ) ;
V_62:
F_16 () ;
F_43 () ;
}
static int F_44 ( struct V_63 * V_64 )
{
int V_65 = 0 ;
struct V_66 * V_67 = F_45 ( V_64 ,
struct V_66 , V_64 ) ;
struct V_68 * V_69 = V_64 -> V_70 ;
if ( V_67 -> V_71 == 0 ) {
V_65 = F_46 () ;
if ( V_65 < 0 ) {
F_47 ( V_64 , L_5 ,
V_32 , V_65 ) ;
return V_65 ;
}
V_69 -> V_72 [ 0 ] . V_73 = V_65 ;
V_69 -> V_72 [ 0 ] . V_74 = V_75 ;
}
return 0 ;
}
static T_1 void F_48 ( struct V_63 * V_64 )
{
struct V_68 * V_69 ;
if ( ! V_64 ) {
F_49 ( L_6 , V_32 ) ;
return;
}
V_69 = V_64 -> V_70 ;
V_69 -> V_76 = F_44 ;
}
int T_1 F_50 ( struct V_77 * V_78 )
{
struct V_77 * V_79 ;
F_51 ( V_78 ) ;
for ( V_79 = V_78 ; V_79 -> V_80 ; V_79 ++ ) {
if ( ! V_79 -> V_67 )
continue;
F_48 ( & V_79 -> V_67 -> V_64 ) ;
}
return 0 ;
}
int T_1 F_50 ( struct V_77 * V_78 )
{
return 0 ;
}
void F_52 ( char V_81 , const char * V_82 )
{
F_53 () ;
while ( 1 ) ;
}
