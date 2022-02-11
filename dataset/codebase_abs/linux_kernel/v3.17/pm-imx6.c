void F_1 ( bool V_1 )
{
T_1 V_2 = F_2 ( V_3 + V_4 ) ;
V_2 &= ~ V_5 ;
if ( V_1 )
V_2 |= V_5 ;
F_3 ( V_2 , V_3 + V_4 ) ;
}
static void F_4 ( bool V_1 )
{
T_1 V_2 ;
F_5 () ;
V_2 = F_2 ( V_3 + V_6 ) ;
V_2 &= ~ V_7 ;
V_2 |= V_1 ? V_7 : 0 ;
F_3 ( V_2 , V_3 + V_6 ) ;
V_2 = F_2 ( V_3 + V_6 ) ;
V_2 &= ~ V_8 ;
V_2 |= V_1 ? V_8 : 0 ;
F_6 ( V_2 , V_3 + V_6 ) ;
F_7 ( 65 ) ;
F_8 () ;
}
static void F_9 ( bool V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 + V_9 ) ;
V_2 &= ~ V_10 ;
V_2 |= V_1 ? V_10 : 0 ;
F_3 ( V_2 , V_3 + V_9 ) ;
V_2 = F_2 ( V_3 + V_6 ) ;
V_2 &= ~ V_11 ;
V_2 |= V_1 ? V_11 : 0 ;
F_3 ( V_2 , V_3 + V_6 ) ;
}
int F_10 ( enum V_12 V_13 )
{
struct V_14 * V_15 = F_11 ( 32 ) ;
T_1 V_2 = F_2 ( V_3 + V_9 ) ;
V_2 &= ~ V_16 ;
switch ( V_13 ) {
case V_17 :
break;
case V_18 :
V_2 |= 0x1 << V_19 ;
V_2 |= V_20 ;
break;
case V_21 :
V_2 |= 0x2 << V_19 ;
V_2 &= ~ V_22 ;
V_2 &= ~ V_23 ;
if ( F_12 () )
V_2 |= V_24 ;
if ( F_12 () || F_13 () )
V_2 |= V_25 ;
else
V_2 |= V_26 ;
break;
case V_27 :
V_2 |= 0x1 << V_19 ;
V_2 &= ~ V_22 ;
V_2 &= ~ V_23 ;
break;
case V_28 :
V_2 |= 0x2 << V_19 ;
V_2 |= 0x3 << V_29 ;
V_2 |= V_22 ;
V_2 |= V_23 ;
if ( F_12 () )
V_2 |= V_24 ;
if ( F_12 () || F_13 () )
V_2 |= V_25 ;
else
V_2 |= V_26 ;
break;
default:
return - V_30 ;
}
F_14 ( V_15 ) ;
F_3 ( V_2 , V_3 + V_9 ) ;
F_15 ( V_15 ) ;
return 0 ;
}
static int F_16 ( unsigned long V_2 )
{
if ( ! V_31 ) {
F_17 () ;
} else {
F_18 () ;
V_31 ( V_32 ) ;
}
return 0 ;
}
static int F_19 ( T_2 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_10 ( V_21 ) ;
F_1 ( true ) ;
F_20 ( false ) ;
if ( F_12 () )
F_21 ( true ) ;
F_17 () ;
if ( F_12 () )
F_21 ( false ) ;
F_22 () ;
F_10 ( V_17 ) ;
break;
case V_35 :
F_10 ( V_28 ) ;
F_1 ( false ) ;
F_9 ( true ) ;
if ( ! V_31 )
F_4 ( true ) ;
F_20 ( true ) ;
F_23 () ;
F_24 ( 0 , V_36 ) ;
F_25 ( 0 , F_16 ) ;
if ( F_26 () || F_27 () )
F_28 () ;
F_29 () ;
F_22 () ;
F_4 ( false ) ;
F_9 ( false ) ;
F_1 ( true ) ;
F_10 ( V_17 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_30 ( T_2 V_33 )
{
return ( V_33 == V_34 || V_33 == V_35 ) ;
}
void T_3 F_31 ( void T_4 * V_37 )
{
V_3 = V_37 ;
}
static int T_3 F_32 ( struct V_38 * V_37 ,
const char * V_39 )
{
struct V_40 * V_41 ;
struct V_42 V_43 ;
int V_44 = 0 ;
V_41 = F_33 ( NULL , NULL , V_39 ) ;
if ( ! V_41 ) {
V_44 = - V_45 ;
goto V_46;
}
V_44 = F_34 ( V_41 , 0 , & V_43 ) ;
if ( V_44 )
goto V_47;
V_37 -> V_48 = V_43 . V_49 ;
V_37 -> V_50 = F_35 ( V_43 . V_49 , F_36 ( & V_43 ) ) ;
if ( ! V_37 -> V_50 )
V_44 = - V_51 ;
V_47:
F_37 ( V_41 ) ;
V_46:
return V_44 ;
}
static int T_3 F_38 ( const struct V_52 * V_53 )
{
T_5 V_54 ;
struct V_40 * V_41 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
unsigned long V_61 ;
int V_62 , V_44 = 0 ;
const T_1 * V_63 ;
F_39 ( & V_64 ) ;
if ( ! V_53 ) {
F_40 ( L_1 , V_65 ) ;
return - V_30 ;
}
V_41 = F_33 ( NULL , NULL , L_2 ) ;
if ( ! V_41 ) {
F_40 ( L_3 , V_65 ) ;
return - V_45 ;
}
V_56 = F_41 ( V_41 ) ;
if ( ! V_56 ) {
F_40 ( L_4 , V_65 ) ;
V_44 = - V_45 ;
goto V_47;
}
V_60 = F_42 ( & V_56 -> V_66 ) ;
if ( ! V_60 ) {
F_40 ( L_5 , V_65 ) ;
V_44 = - V_45 ;
goto V_47;
}
V_61 = F_43 ( V_60 , V_67 ) ;
if ( ! V_61 ) {
F_40 ( L_6 , V_65 ) ;
V_44 = - V_51 ;
goto V_47;
}
V_54 = F_44 ( V_60 , V_61 ) ;
V_32 = F_45 ( V_54 ,
V_67 , false ) ;
V_58 = V_32 ;
V_58 -> V_48 = V_54 ;
V_58 -> V_68 = F_46 ( V_36 ) ;
V_58 -> V_69 = sizeof( * V_58 ) ;
V_58 -> V_3 . V_50 = V_3 ;
V_44 = F_32 ( & V_58 -> V_70 , V_53 -> V_71 ) ;
if ( V_44 ) {
F_40 ( L_7 , V_65 , V_44 ) ;
goto V_47;
}
V_44 = F_32 ( & V_58 -> V_72 , V_53 -> V_73 ) ;
if ( V_44 ) {
F_40 ( L_8 , V_65 , V_44 ) ;
goto V_74;
}
V_44 = F_32 ( & V_58 -> V_75 , V_53 -> V_76 ) ;
if ( V_44 ) {
F_40 ( L_9 , V_65 , V_44 ) ;
goto V_77;
}
V_44 = F_32 ( & V_58 -> V_78 , V_53 -> V_79 ) ;
if ( V_44 ) {
F_40 ( L_10 , V_65 , V_44 ) ;
goto V_80;
}
V_44 = F_32 ( & V_58 -> V_81 , L_11 ) ;
if ( V_44 ) {
F_40 ( L_12 ,
V_65 , V_44 ) ;
goto V_82;
}
V_58 -> V_83 = V_53 -> V_83 ;
V_58 -> V_84 = V_53 -> V_84 ;
V_63 = V_53 -> V_85 ;
for ( V_62 = 0 ; V_62 < V_58 -> V_84 ; V_62 ++ ) {
V_58 -> V_86 [ V_62 ] [ 0 ] =
V_63 [ V_62 ] ;
V_58 -> V_86 [ V_62 ] [ 1 ] =
F_2 ( V_58 -> V_75 . V_50 +
V_63 [ V_62 ] ) ;
}
V_31 = F_47 (
V_32 + sizeof( * V_58 ) ,
& V_87 ,
V_67 - sizeof( * V_58 ) ) ;
goto V_47;
V_82:
F_48 ( & V_58 -> V_78 . V_50 ) ;
V_80:
F_48 ( & V_58 -> V_75 . V_50 ) ;
V_77:
F_48 ( & V_58 -> V_72 . V_50 ) ;
V_74:
F_48 ( & V_58 -> V_70 . V_50 ) ;
V_47:
F_37 ( V_41 ) ;
return V_44 ;
}
static void T_3 F_49 ( const struct V_52
* V_53 )
{
struct V_88 * V_89 ;
int V_44 ;
F_50 ( ! V_3 ) ;
if ( F_51 ( V_90 ) ) {
V_44 = F_38 ( V_53 ) ;
if ( V_44 )
F_40 ( L_13 ,
V_65 , V_44 ) ;
}
V_89 = F_52 ( L_14 ) ;
if ( ! F_53 ( V_89 ) )
F_54 ( V_89 , V_91 , V_92 ,
V_92 ) ;
}
void T_3 F_55 ( void )
{
F_49 ( & V_93 ) ;
}
void T_3 F_56 ( void )
{
F_49 ( & V_94 ) ;
}
void T_3 F_57 ( void )
{
F_49 ( & V_95 ) ;
}
void T_3 F_58 ( void )
{
F_49 ( & V_96 ) ;
}
