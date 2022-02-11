static void T_1 F_1 ( void )
{
V_1 [ 0 ] . V_2 = F_2 () ;
}
static void T_1 F_3 ( void )
{
T_2 V_3 ;
V_3 = F_4 ( V_4 ) ;
V_3 &= ~ V_5 ;
V_3 |= V_6 ;
F_5 ( V_3 , V_4 ) ;
if ( F_6 () ) {
V_3 = F_4 ( V_7 ) ;
V_3 |= V_8 ;
F_5 ( V_3 , V_7 ) ;
}
}
static void T_1 F_7 ( void )
{
T_2 V_3 ;
V_3 = F_4 ( V_9 ) ;
V_3 |= V_10 ;
F_5 ( V_3 , V_9 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
unsigned V_13 ,
unsigned V_14 )
{
int V_15 ;
V_15 = F_9 ( V_13 + 2 , V_16 ,
L_1 ) ;
if ( V_15 )
return V_15 ;
F_10 ( V_13 , 0 ) ;
return 0 ;
}
static void T_1 F_11 ( int V_13 , char * V_17 )
{
int V_18 = F_9 ( V_13 , V_19 , V_17 ) ;
if ( V_18 ) {
F_12 ( L_2 ,
V_17 , V_18 ) ;
return;
}
F_10 ( V_13 , 0 ) ;
F_13 ( 10 ) ;
F_14 ( V_13 , 1 ) ;
F_15 ( 1 ) ;
}
static void T_1 F_16 ( void )
{
V_20 . V_21 = F_8 ;
}
static void T_1 F_17 ( void )
{
F_11 ( 167 , L_3 ) ;
}
static void T_1 F_18 ( void )
{
F_11 ( 167 , L_3 ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( & V_22 ) ;
F_20 ( & V_23 ) ;
}
static void T_1 F_21 ( void )
{
F_20 ( & V_22 ) ;
F_20 ( & V_23 ) ;
}
static void T_1 F_22 ( void )
{
F_7 () ;
}
static void F_23 ( void )
{
T_2 V_24 ;
V_24 = F_4 ( V_25 ) ;
V_24 |= ( V_26 | V_27 |
V_28 | V_29 ) ;
F_5 ( V_24 , V_25 ) ;
F_4 ( V_25 ) ;
}
static void F_24 ( void )
{
T_2 V_24 ;
V_24 = F_4 ( V_25 ) ;
V_24 |= ( V_26 | V_27 ) ;
F_5 ( V_24 , V_25 ) ;
F_4 ( V_25 ) ;
}
static void T_1 F_25 ( void )
{
T_2 V_24 ;
V_24 = F_4 ( V_30 ) ;
V_24 &= ~ V_31 ;
F_5 ( V_24 , V_30 ) ;
F_4 ( V_30 ) ;
}
static void T_1 F_26 ( void )
{
int V_18 = F_27 ( V_32 ,
F_28 ( V_32 ) ) ;
if ( V_18 ) {
F_12 ( L_4 , V_18 ) ;
return;
}
F_10 ( V_32 [ 0 ] . V_13 , 0 ) ;
F_10 ( V_32 [ 1 ] . V_13 , 0 ) ;
F_15 ( 100 ) ;
F_14 ( V_32 [ 1 ] . V_13 , 0 ) ;
}
static void T_1 F_29 ( void )
{
F_11 ( 152 , L_5 ) ;
F_11 ( 98 , L_3 ) ;
F_25 () ;
F_7 () ;
F_26 () ;
}
static void T_1 F_30 ( void )
{
F_25 () ;
}
static void T_1 F_31 ( void )
{
F_7 () ;
if ( F_32 () == V_33 ) {
if ( F_33 ( V_34 ) ) {
F_34 ( L_6 ) ;
F_35 ( F_36 ( 6 ) , 0 ) ;
} else {
F_37 ( L_7 ) ;
F_37 ( L_8 ) ;
}
F_34 ( L_9 ) ;
F_20 ( & V_35 ) ;
}
}
static void T_1 F_38 ( void )
{
F_7 () ;
}
static void T_1 F_39 ( void )
{
F_3 () ;
F_20 ( & V_36 ) ;
F_20 ( & V_23 ) ;
}
static void F_40 ( struct V_37 * V_38 )
{
if ( V_38 -> type == V_39 || V_38 -> type == V_40 ) {
V_38 -> V_41 |= V_42 ;
V_38 -> V_43 . V_44 = 1 ;
V_38 -> V_45 . V_46 = 0x104c ;
V_38 -> V_45 . V_11 = 0x9066 ;
V_38 -> V_45 . V_47 = 512 ;
V_38 -> V_45 . V_48 = 24000000 ;
V_38 -> V_49 = 0x80 ;
}
}
static void T_1 F_41 ( void )
{
struct V_50 V_51 ;
int V_52 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_53 = - 1 ;
V_52 = F_9 ( V_54 , V_55 , L_10 ) ;
if ( V_52 < 0 )
goto V_56;
V_51 . V_57 = F_42 ( V_54 ) ;
if ( V_51 . V_57 < 0 )
goto V_58;
V_51 . V_59 = true ;
V_52 = F_43 ( & V_51 ) ;
if ( V_52 < 0 )
goto V_58;
return;
V_58:
F_44 ( V_54 ) ;
V_56:
F_12 ( L_11 ) ;
}
static void T_1 F_45 ( void )
{
F_20 ( & V_60 ) ;
F_20 ( & V_61 ) ;
F_46 ( V_62 ) ;
F_47 ( V_62 ) ;
F_41 () ;
}
static void T_1 F_48 ( void )
{
}
void F_49 ( int V_57 , void (* F_50)( void ) )
{
V_63 . V_57 = V_57 ;
V_63 . F_50 = F_50 ;
}
void F_51 ( struct V_11 * V_12 )
{
if ( V_12 -> V_2 )
return;
if ( strcmp ( L_12 , F_52 ( V_12 ) ) )
return;
V_12 -> V_2 = & V_20 ;
}
static void F_53 ( struct V_64 * V_41 )
{
while ( V_41 -> V_65 ) {
if ( F_54 ( V_41 -> V_65 ) ) {
if ( V_41 -> V_66 )
V_41 -> V_66 () ;
break;
}
V_41 ++ ;
}
}
void T_1 F_55 ( const struct V_67 * V_68 )
{
if ( F_54 ( L_13 ) ||
F_54 ( L_14 ) )
F_56 ( NULL , NULL ) ;
F_53 ( V_69 ) ;
F_57 ( NULL , V_68 ,
V_1 , NULL ) ;
F_53 ( V_70 ) ;
}
