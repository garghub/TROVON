void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + V_3 ) ;
V_1 |= V_4 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static void F_4 ( bool V_5 )
{
T_1 V_1 ;
F_5 () ;
V_1 = F_2 ( V_2 + V_6 ) ;
V_1 &= ~ V_7 ;
V_1 |= V_5 ? V_7 : 0 ;
F_3 ( V_1 , V_2 + V_6 ) ;
V_1 = F_2 ( V_2 + V_6 ) ;
V_1 &= ~ V_8 ;
V_1 |= V_5 ? V_8 : 0 ;
F_6 ( V_1 , V_2 + V_6 ) ;
F_7 ( 65 ) ;
F_8 () ;
}
static void F_9 ( bool V_5 )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_9 ) ;
V_1 &= ~ V_10 ;
V_1 |= V_5 ? V_10 : 0 ;
F_3 ( V_1 , V_2 + V_9 ) ;
V_1 = F_2 ( V_2 + V_6 ) ;
V_1 &= ~ V_11 ;
V_1 |= V_5 ? V_11 : 0 ;
F_3 ( V_1 , V_2 + V_6 ) ;
}
int F_10 ( enum V_12 V_13 )
{
struct V_14 * V_15 = F_11 ( 32 ) ;
T_1 V_1 = F_2 ( V_2 + V_9 ) ;
V_1 &= ~ V_16 ;
switch ( V_13 ) {
case V_17 :
break;
case V_18 :
V_1 |= 0x1 << V_19 ;
V_1 |= V_20 ;
break;
case V_21 :
V_1 |= 0x2 << V_19 ;
break;
case V_22 :
V_1 |= 0x1 << V_19 ;
V_1 &= ~ V_23 ;
V_1 &= ~ V_24 ;
break;
case V_25 :
V_1 |= 0x2 << V_19 ;
V_1 |= 0x3 << V_26 ;
V_1 |= V_23 ;
V_1 |= V_24 ;
if ( F_12 () ) {
V_1 |= V_27 ;
V_1 |= V_28 ;
} else {
V_1 |= V_29 ;
}
break;
default:
return - V_30 ;
}
F_13 ( V_15 ) ;
F_3 ( V_1 , V_2 + V_9 ) ;
F_14 ( V_15 ) ;
return 0 ;
}
static int F_15 ( unsigned long V_1 )
{
if ( ! V_31 ) {
F_16 () ;
} else {
F_17 () ;
V_31 ( V_32 ) ;
}
return 0 ;
}
static int F_18 ( T_2 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_10 ( V_25 ) ;
F_9 ( true ) ;
if ( ! V_31 )
F_4 ( true ) ;
F_19 () ;
F_20 () ;
F_21 ( 0 , V_35 ) ;
F_22 ( 0 , F_15 ) ;
if ( F_23 () || F_24 () )
F_25 () ;
F_26 () ;
F_27 () ;
F_4 ( false ) ;
F_9 ( false ) ;
F_10 ( V_17 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
void T_3 F_28 ( void T_4 * V_36 )
{
V_2 = V_36 ;
}
static int T_3 F_29 ( struct V_37 * V_36 ,
const char * V_38 )
{
struct V_39 * V_40 ;
struct V_41 V_42 ;
int V_43 = 0 ;
V_40 = F_30 ( NULL , NULL , V_38 ) ;
if ( ! V_40 ) {
V_43 = - V_44 ;
goto V_45;
}
V_43 = F_31 ( V_40 , 0 , & V_42 ) ;
if ( V_43 )
goto V_46;
V_36 -> V_47 = V_42 . V_48 ;
V_36 -> V_49 = F_32 ( V_42 . V_48 , F_33 ( & V_42 ) ) ;
if ( ! V_36 -> V_49 )
V_43 = - V_50 ;
V_46:
F_34 ( V_40 ) ;
V_45:
return V_43 ;
}
static int T_3 F_35 ( const struct V_51 * V_52 )
{
T_5 V_53 ;
struct V_39 * V_40 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
unsigned long V_60 ;
int V_61 , V_43 = 0 ;
const T_1 * V_62 ;
F_36 ( & V_63 ) ;
if ( ! V_52 ) {
F_37 ( L_1 , V_64 ) ;
return - V_30 ;
}
V_40 = F_30 ( NULL , NULL , L_2 ) ;
if ( ! V_40 ) {
F_37 ( L_3 , V_64 ) ;
return - V_44 ;
}
V_55 = F_38 ( V_40 ) ;
if ( ! V_55 ) {
F_37 ( L_4 , V_64 ) ;
V_43 = - V_44 ;
goto V_46;
}
V_59 = F_39 ( & V_55 -> V_65 ) ;
if ( ! V_59 ) {
F_37 ( L_5 , V_64 ) ;
V_43 = - V_44 ;
goto V_46;
}
V_60 = F_40 ( V_59 , V_66 ) ;
if ( ! V_60 ) {
F_37 ( L_6 , V_64 ) ;
V_43 = - V_50 ;
goto V_46;
}
V_53 = F_41 ( V_59 , V_60 ) ;
V_32 = F_42 ( V_53 ,
V_66 , false ) ;
V_57 = V_32 ;
V_57 -> V_47 = V_53 ;
V_57 -> V_67 = F_43 ( V_35 ) ;
V_57 -> V_68 = sizeof( * V_57 ) ;
V_57 -> V_2 . V_49 = V_2 ;
V_43 = F_29 ( & V_57 -> V_69 , V_52 -> V_70 ) ;
if ( V_43 ) {
F_37 ( L_7 , V_64 , V_43 ) ;
goto V_46;
}
V_43 = F_29 ( & V_57 -> V_71 , V_52 -> V_72 ) ;
if ( V_43 ) {
F_37 ( L_8 , V_64 , V_43 ) ;
goto V_73;
}
V_43 = F_29 ( & V_57 -> V_74 , V_52 -> V_75 ) ;
if ( V_43 ) {
F_37 ( L_9 , V_64 , V_43 ) ;
goto V_76;
}
V_43 = F_29 ( & V_57 -> V_77 , V_52 -> V_78 ) ;
if ( V_43 ) {
F_37 ( L_10 , V_64 , V_43 ) ;
goto V_79;
}
V_43 = F_29 ( & V_57 -> V_80 , L_11 ) ;
if ( V_43 ) {
F_37 ( L_12 ,
V_64 , V_43 ) ;
goto V_81;
}
V_57 -> V_82 = V_52 -> V_82 ;
V_57 -> V_83 = V_52 -> V_83 ;
V_62 = V_52 -> V_84 ;
for ( V_61 = 0 ; V_61 < V_57 -> V_83 ; V_61 ++ ) {
V_57 -> V_85 [ V_61 ] [ 0 ] =
V_62 [ V_61 ] ;
V_57 -> V_85 [ V_61 ] [ 1 ] =
F_2 ( V_57 -> V_74 . V_49 +
V_62 [ V_61 ] ) ;
}
V_31 = F_44 (
V_32 + sizeof( * V_57 ) ,
& V_86 ,
V_66 - sizeof( * V_57 ) ) ;
goto V_46;
V_81:
F_45 ( & V_57 -> V_77 . V_49 ) ;
V_79:
F_45 ( & V_57 -> V_74 . V_49 ) ;
V_76:
F_45 ( & V_57 -> V_71 . V_49 ) ;
V_73:
F_45 ( & V_57 -> V_69 . V_49 ) ;
V_46:
F_34 ( V_40 ) ;
return V_43 ;
}
static void T_3 F_46 ( const struct V_51
* V_52 )
{
struct V_87 * V_88 ;
int V_43 ;
F_47 ( ! V_2 ) ;
if ( F_48 ( V_89 ) ) {
V_43 = F_35 ( V_52 ) ;
if ( V_43 )
F_37 ( L_13 ,
V_64 , V_43 ) ;
}
V_88 = F_49 ( L_14 ) ;
if ( ! F_50 ( V_88 ) )
F_51 ( V_88 , V_90 , V_91 ,
V_91 ) ;
}
void T_3 F_52 ( void )
{
F_46 ( & V_92 ) ;
}
void T_3 F_53 ( void )
{
F_46 ( & V_93 ) ;
}
void T_3 F_54 ( void )
{
F_46 ( & V_94 ) ;
}
