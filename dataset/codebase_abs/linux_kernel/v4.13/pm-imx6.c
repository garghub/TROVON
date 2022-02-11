void F_1 ( bool V_1 )
{
T_1 V_2 = F_2 ( V_3 + V_4 ) ;
V_2 &= ~ V_5 ;
if ( V_1 )
V_2 |= V_5 ;
F_3 ( V_2 , V_3 + V_4 ) ;
}
void F_4 ( bool V_1 )
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
if ( F_11 () || F_12 () || F_13 () ||
F_14 () )
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
if ( F_11 () || F_12 () )
V_2 |= V_22 ;
if ( F_11 () || F_12 () || F_13 () ||
F_14 () )
V_2 |= V_23 ;
else
V_2 |= V_24 ;
break;
default:
return - V_28 ;
}
F_15 ( 0 ) ;
F_3 ( V_2 , V_3 + V_9 ) ;
F_16 ( 0 ) ;
return 0 ;
}
static int F_17 ( unsigned long V_2 )
{
if ( ! V_29 ) {
F_18 () ;
} else {
F_19 () ;
if ( ! ( (struct V_30 * )
V_31 ) -> V_32 . V_33 )
F_20 () ;
V_29 ( V_31 ) ;
}
return 0 ;
}
static int F_21 ( T_2 V_34 )
{
switch ( V_34 ) {
case V_35 :
F_10 ( V_19 ) ;
F_1 ( true ) ;
F_22 ( false ) ;
if ( F_11 () )
F_23 ( true ) ;
F_18 () ;
if ( F_11 () )
F_23 ( false ) ;
F_24 () ;
F_10 ( V_15 ) ;
break;
case V_36 :
F_10 ( V_26 ) ;
F_1 ( false ) ;
F_9 ( true ) ;
if ( ! V_29 )
F_4 ( true ) ;
F_22 ( true ) ;
F_25 () ;
F_26 ( 0 , F_17 ) ;
if ( F_27 () || F_28 () )
F_29 () ;
F_30 () ;
F_24 () ;
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
static int F_31 ( T_2 V_34 )
{
return ( V_34 == V_35 || V_34 == V_36 ) ;
}
static int T_3 F_32 ( struct V_37 * V_38 ,
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
V_38 -> V_48 = V_43 . V_49 ;
V_38 -> V_33 = F_35 ( V_43 . V_49 , F_36 ( & V_43 ) ) ;
if ( ! V_38 -> V_33 )
V_44 = - V_50 ;
V_47:
F_37 ( V_41 ) ;
V_46:
return V_44 ;
}
static int T_3 F_38 ( const struct V_51 * V_52 )
{
T_4 V_53 ;
struct V_40 * V_41 ;
struct V_54 * V_55 ;
struct V_30 * V_56 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
int V_60 , V_44 = 0 ;
const T_1 * V_61 ;
F_39 ( & V_62 ) ;
if ( ! V_52 ) {
F_40 ( L_1 , V_63 ) ;
return - V_28 ;
}
V_41 = F_33 ( NULL , NULL , L_2 ) ;
if ( ! V_41 ) {
F_40 ( L_3 , V_63 ) ;
return - V_45 ;
}
V_55 = F_41 ( V_41 ) ;
if ( ! V_55 ) {
F_40 ( L_4 , V_63 ) ;
V_44 = - V_45 ;
goto V_47;
}
V_58 = F_42 ( & V_55 -> V_64 , NULL ) ;
if ( ! V_58 ) {
F_40 ( L_5 , V_63 ) ;
V_44 = - V_45 ;
goto V_47;
}
V_59 = F_43 ( V_58 , V_65 ) ;
if ( ! V_59 ) {
F_40 ( L_6 , V_63 ) ;
V_44 = - V_50 ;
goto V_47;
}
V_53 = F_44 ( V_58 , V_59 ) ;
V_31 = F_45 ( V_53 ,
V_65 , false ) ;
memset ( V_31 , 0 , sizeof( * V_56 ) ) ;
V_56 = V_31 ;
V_56 -> V_48 = V_53 ;
V_56 -> V_66 = F_46 ( V_67 ) ;
V_56 -> V_68 = sizeof( * V_56 ) ;
V_56 -> V_3 . V_33 = V_3 ;
V_44 = F_32 ( & V_56 -> V_69 , V_52 -> V_70 ) ;
if ( V_44 ) {
F_40 ( L_7 , V_63 , V_44 ) ;
goto V_47;
}
V_44 = F_32 ( & V_56 -> V_71 , V_52 -> V_72 ) ;
if ( V_44 ) {
F_40 ( L_8 , V_63 , V_44 ) ;
goto V_73;
}
V_44 = F_32 ( & V_56 -> V_74 , V_52 -> V_75 ) ;
if ( V_44 ) {
F_40 ( L_9 , V_63 , V_44 ) ;
goto V_76;
}
V_44 = F_32 ( & V_56 -> V_77 , V_52 -> V_78 ) ;
if ( V_44 ) {
F_40 ( L_10 , V_63 , V_44 ) ;
goto V_79;
}
if ( V_52 -> V_80 ) {
V_44 = F_32 ( & V_56 -> V_32 , V_52 -> V_80 ) ;
if ( V_44 ) {
F_40 ( L_11 ,
V_63 , V_44 ) ;
goto V_81;
}
}
V_56 -> V_82 = F_47 () ;
V_56 -> V_83 = V_52 -> V_83 ;
V_61 = V_52 -> V_84 ;
for ( V_60 = 0 ; V_60 < V_56 -> V_83 ; V_60 ++ ) {
V_56 -> V_85 [ V_60 ] [ 0 ] =
V_61 [ V_60 ] ;
V_56 -> V_85 [ V_60 ] [ 1 ] =
F_2 ( V_56 -> V_74 . V_33 +
V_61 [ V_60 ] ) ;
}
V_29 = F_48 (
V_31 + sizeof( * V_56 ) ,
& V_86 ,
V_65 - sizeof( * V_56 ) ) ;
goto V_47;
V_81:
F_49 ( V_56 -> V_77 . V_33 ) ;
V_79:
F_49 ( V_56 -> V_74 . V_33 ) ;
V_76:
F_49 ( V_56 -> V_71 . V_33 ) ;
V_73:
F_49 ( V_56 -> V_69 . V_33 ) ;
V_47:
F_37 ( V_41 ) ;
return V_44 ;
}
static void T_3 F_50 ( const struct V_51
* V_52 )
{
struct V_87 * V_88 ;
int V_44 ;
F_51 ( ! V_3 ) ;
if ( F_52 ( V_89 ) ) {
V_44 = F_38 ( V_52 ) ;
if ( V_44 )
F_40 ( L_12 ,
V_63 , V_44 ) ;
}
V_88 = F_53 ( L_13 ) ;
if ( ! F_54 ( V_88 ) )
F_55 ( V_88 , V_90 , V_91 ,
V_91 ) ;
}
void T_3 F_56 ( const char * V_92 )
{
struct V_40 * V_93 ;
T_1 V_2 ;
V_93 = F_33 ( NULL , NULL , V_92 ) ;
V_3 = F_57 ( V_93 , 0 ) ;
F_58 ( ! V_3 ) ;
V_2 = F_2 ( V_3 + V_9 ) ;
V_2 &= ~ V_14 ;
F_3 ( V_2 , V_3 + V_9 ) ;
}
void T_3 F_59 ( void )
{
F_50 ( & V_94 ) ;
}
void T_3 F_60 ( void )
{
F_50 ( & V_95 ) ;
}
void T_3 F_61 ( void )
{
F_50 ( & V_96 ) ;
}
void T_3 F_62 ( void )
{
F_50 ( & V_97 ) ;
}
void T_3 F_63 ( void )
{
F_50 ( & V_98 ) ;
}
