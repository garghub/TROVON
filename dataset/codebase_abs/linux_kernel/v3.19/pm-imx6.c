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
T_1 V_2 = F_2 ( V_3 + V_9 ) ;
V_2 &= ~ V_14 ;
switch ( V_13 ) {
case V_15 :
break;
case V_16 :
V_2 |= 0x1 << V_17 ;
V_2 |= V_18 ;
break;
case V_19 :
V_2 |= 0x2 << V_17 ;
V_2 &= ~ V_20 ;
V_2 &= ~ V_21 ;
if ( F_11 () )
V_2 |= V_22 ;
if ( F_11 () || F_12 () )
V_2 |= V_23 ;
else
V_2 |= V_24 ;
break;
case V_25 :
V_2 |= 0x1 << V_17 ;
V_2 &= ~ V_20 ;
V_2 &= ~ V_21 ;
break;
case V_26 :
V_2 |= 0x2 << V_17 ;
V_2 |= 0x3 << V_27 ;
V_2 |= V_20 ;
V_2 |= V_21 ;
if ( F_11 () )
V_2 |= V_22 ;
if ( F_11 () || F_12 () )
V_2 |= V_23 ;
else
V_2 |= V_24 ;
break;
default:
return - V_28 ;
}
F_13 ( 32 ) ;
F_3 ( V_2 , V_3 + V_9 ) ;
F_14 ( 32 ) ;
return 0 ;
}
static int F_15 ( unsigned long V_2 )
{
if ( ! V_29 ) {
F_16 () ;
} else {
F_17 () ;
V_29 ( V_30 ) ;
}
return 0 ;
}
static int F_18 ( T_2 V_31 )
{
switch ( V_31 ) {
case V_32 :
F_10 ( V_19 ) ;
F_1 ( true ) ;
F_19 ( false ) ;
if ( F_11 () )
F_20 ( true ) ;
F_16 () ;
if ( F_11 () )
F_20 ( false ) ;
F_21 () ;
F_10 ( V_15 ) ;
break;
case V_33 :
F_10 ( V_26 ) ;
F_1 ( false ) ;
F_9 ( true ) ;
if ( ! V_29 )
F_4 ( true ) ;
F_19 ( true ) ;
F_22 () ;
F_23 ( 0 , V_34 ) ;
F_24 ( 0 , F_15 ) ;
if ( F_25 () || F_26 () )
F_27 () ;
F_28 () ;
F_21 () ;
F_4 ( false ) ;
F_9 ( false ) ;
F_1 ( true ) ;
F_10 ( V_15 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_29 ( T_2 V_31 )
{
return ( V_31 == V_32 || V_31 == V_33 ) ;
}
void T_3 F_30 ( void T_4 * V_35 )
{
V_3 = V_35 ;
}
static int T_3 F_31 ( struct V_36 * V_35 ,
const char * V_37 )
{
struct V_38 * V_39 ;
struct V_40 V_41 ;
int V_42 = 0 ;
V_39 = F_32 ( NULL , NULL , V_37 ) ;
if ( ! V_39 ) {
V_42 = - V_43 ;
goto V_44;
}
V_42 = F_33 ( V_39 , 0 , & V_41 ) ;
if ( V_42 )
goto V_45;
V_35 -> V_46 = V_41 . V_47 ;
V_35 -> V_48 = F_34 ( V_41 . V_47 , F_35 ( & V_41 ) ) ;
if ( ! V_35 -> V_48 )
V_42 = - V_49 ;
V_45:
F_36 ( V_39 ) ;
V_44:
return V_42 ;
}
static int T_3 F_37 ( const struct V_50 * V_51 )
{
T_5 V_52 ;
struct V_38 * V_39 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
int V_60 , V_42 = 0 ;
const T_1 * V_61 ;
F_38 ( & V_62 ) ;
if ( ! V_51 ) {
F_39 ( L_1 , V_63 ) ;
return - V_28 ;
}
V_39 = F_32 ( NULL , NULL , L_2 ) ;
if ( ! V_39 ) {
F_39 ( L_3 , V_63 ) ;
return - V_43 ;
}
V_54 = F_40 ( V_39 ) ;
if ( ! V_54 ) {
F_39 ( L_4 , V_63 ) ;
V_42 = - V_43 ;
goto V_45;
}
V_58 = F_41 ( & V_54 -> V_64 ) ;
if ( ! V_58 ) {
F_39 ( L_5 , V_63 ) ;
V_42 = - V_43 ;
goto V_45;
}
V_59 = F_42 ( V_58 , V_65 ) ;
if ( ! V_59 ) {
F_39 ( L_6 , V_63 ) ;
V_42 = - V_49 ;
goto V_45;
}
V_52 = F_43 ( V_58 , V_59 ) ;
V_30 = F_44 ( V_52 ,
V_65 , false ) ;
V_56 = V_30 ;
V_56 -> V_46 = V_52 ;
V_56 -> V_66 = F_45 ( V_34 ) ;
V_56 -> V_67 = sizeof( * V_56 ) ;
V_56 -> V_3 . V_48 = V_3 ;
V_42 = F_31 ( & V_56 -> V_68 , V_51 -> V_69 ) ;
if ( V_42 ) {
F_39 ( L_7 , V_63 , V_42 ) ;
goto V_45;
}
V_42 = F_31 ( & V_56 -> V_70 , V_51 -> V_71 ) ;
if ( V_42 ) {
F_39 ( L_8 , V_63 , V_42 ) ;
goto V_72;
}
V_42 = F_31 ( & V_56 -> V_73 , V_51 -> V_74 ) ;
if ( V_42 ) {
F_39 ( L_9 , V_63 , V_42 ) ;
goto V_75;
}
V_42 = F_31 ( & V_56 -> V_76 , V_51 -> V_77 ) ;
if ( V_42 ) {
F_39 ( L_10 , V_63 , V_42 ) ;
goto V_78;
}
V_42 = F_31 ( & V_56 -> V_79 , L_11 ) ;
if ( V_42 ) {
F_39 ( L_12 ,
V_63 , V_42 ) ;
goto V_80;
}
V_56 -> V_81 = F_46 () ;
V_56 -> V_82 = V_51 -> V_82 ;
V_61 = V_51 -> V_83 ;
for ( V_60 = 0 ; V_60 < V_56 -> V_82 ; V_60 ++ ) {
V_56 -> V_84 [ V_60 ] [ 0 ] =
V_61 [ V_60 ] ;
V_56 -> V_84 [ V_60 ] [ 1 ] =
F_2 ( V_56 -> V_73 . V_48 +
V_61 [ V_60 ] ) ;
}
V_29 = F_47 (
V_30 + sizeof( * V_56 ) ,
& V_85 ,
V_65 - sizeof( * V_56 ) ) ;
goto V_45;
V_80:
F_48 ( & V_56 -> V_76 . V_48 ) ;
V_78:
F_48 ( & V_56 -> V_73 . V_48 ) ;
V_75:
F_48 ( & V_56 -> V_70 . V_48 ) ;
V_72:
F_48 ( & V_56 -> V_68 . V_48 ) ;
V_45:
F_36 ( V_39 ) ;
return V_42 ;
}
static void T_3 F_49 ( const struct V_50
* V_51 )
{
struct V_86 * V_87 ;
int V_42 ;
F_50 ( ! V_3 ) ;
if ( F_51 ( V_88 ) ) {
V_42 = F_37 ( V_51 ) ;
if ( V_42 )
F_39 ( L_13 ,
V_63 , V_42 ) ;
}
V_87 = F_52 ( L_14 ) ;
if ( ! F_53 ( V_87 ) )
F_54 ( V_87 , V_89 , V_90 ,
V_90 ) ;
}
void T_3 F_55 ( void )
{
F_49 ( & V_91 ) ;
}
void T_3 F_56 ( void )
{
F_49 ( & V_92 ) ;
}
void T_3 F_57 ( void )
{
F_49 ( & V_93 ) ;
}
void T_3 F_58 ( void )
{
F_49 ( & V_94 ) ;
}
