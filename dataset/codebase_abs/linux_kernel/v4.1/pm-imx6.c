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
F_13 ( 0 ) ;
F_3 ( V_2 , V_3 + V_9 ) ;
F_14 ( 0 ) ;
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
F_23 ( 0 , F_15 ) ;
if ( F_24 () || F_25 () )
F_26 () ;
F_27 () ;
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
static int F_28 ( T_2 V_31 )
{
return ( V_31 == V_32 || V_31 == V_33 ) ;
}
void T_3 F_29 ( void T_4 * V_34 )
{
V_3 = V_34 ;
}
static int T_3 F_30 ( struct V_35 * V_34 ,
const char * V_36 )
{
struct V_37 * V_38 ;
struct V_39 V_40 ;
int V_41 = 0 ;
V_38 = F_31 ( NULL , NULL , V_36 ) ;
if ( ! V_38 ) {
V_41 = - V_42 ;
goto V_43;
}
V_41 = F_32 ( V_38 , 0 , & V_40 ) ;
if ( V_41 )
goto V_44;
V_34 -> V_45 = V_40 . V_46 ;
V_34 -> V_47 = F_33 ( V_40 . V_46 , F_34 ( & V_40 ) ) ;
if ( ! V_34 -> V_47 )
V_41 = - V_48 ;
V_44:
F_35 ( V_38 ) ;
V_43:
return V_41 ;
}
static int T_3 F_36 ( const struct V_49 * V_50 )
{
T_5 V_51 ;
struct V_37 * V_38 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
int V_59 , V_41 = 0 ;
const T_1 * V_60 ;
F_37 ( & V_61 ) ;
if ( ! V_50 ) {
F_38 ( L_1 , V_62 ) ;
return - V_28 ;
}
V_38 = F_31 ( NULL , NULL , L_2 ) ;
if ( ! V_38 ) {
F_38 ( L_3 , V_62 ) ;
return - V_42 ;
}
V_53 = F_39 ( V_38 ) ;
if ( ! V_53 ) {
F_38 ( L_4 , V_62 ) ;
V_41 = - V_42 ;
goto V_44;
}
V_57 = F_40 ( & V_53 -> V_63 ) ;
if ( ! V_57 ) {
F_38 ( L_5 , V_62 ) ;
V_41 = - V_42 ;
goto V_44;
}
V_58 = F_41 ( V_57 , V_64 ) ;
if ( ! V_58 ) {
F_38 ( L_6 , V_62 ) ;
V_41 = - V_48 ;
goto V_44;
}
V_51 = F_42 ( V_57 , V_58 ) ;
V_30 = F_43 ( V_51 ,
V_64 , false ) ;
V_55 = V_30 ;
V_55 -> V_45 = V_51 ;
V_55 -> V_65 = F_44 ( V_66 ) ;
V_55 -> V_67 = sizeof( * V_55 ) ;
V_55 -> V_3 . V_47 = V_3 ;
V_41 = F_30 ( & V_55 -> V_68 , V_50 -> V_69 ) ;
if ( V_41 ) {
F_38 ( L_7 , V_62 , V_41 ) ;
goto V_44;
}
V_41 = F_30 ( & V_55 -> V_70 , V_50 -> V_71 ) ;
if ( V_41 ) {
F_38 ( L_8 , V_62 , V_41 ) ;
goto V_72;
}
V_41 = F_30 ( & V_55 -> V_73 , V_50 -> V_74 ) ;
if ( V_41 ) {
F_38 ( L_9 , V_62 , V_41 ) ;
goto V_75;
}
V_41 = F_30 ( & V_55 -> V_76 , V_50 -> V_77 ) ;
if ( V_41 ) {
F_38 ( L_10 , V_62 , V_41 ) ;
goto V_78;
}
V_41 = F_30 ( & V_55 -> V_79 , L_11 ) ;
if ( V_41 ) {
F_38 ( L_12 ,
V_62 , V_41 ) ;
goto V_80;
}
V_55 -> V_81 = F_45 () ;
V_55 -> V_82 = V_50 -> V_82 ;
V_60 = V_50 -> V_83 ;
for ( V_59 = 0 ; V_59 < V_55 -> V_82 ; V_59 ++ ) {
V_55 -> V_84 [ V_59 ] [ 0 ] =
V_60 [ V_59 ] ;
V_55 -> V_84 [ V_59 ] [ 1 ] =
F_2 ( V_55 -> V_73 . V_47 +
V_60 [ V_59 ] ) ;
}
V_29 = F_46 (
V_30 + sizeof( * V_55 ) ,
& V_85 ,
V_64 - sizeof( * V_55 ) ) ;
goto V_44;
V_80:
F_47 ( & V_55 -> V_76 . V_47 ) ;
V_78:
F_47 ( & V_55 -> V_73 . V_47 ) ;
V_75:
F_47 ( & V_55 -> V_70 . V_47 ) ;
V_72:
F_47 ( & V_55 -> V_68 . V_47 ) ;
V_44:
F_35 ( V_38 ) ;
return V_41 ;
}
static void T_3 F_48 ( const struct V_49
* V_50 )
{
struct V_86 * V_87 ;
int V_41 ;
F_49 ( ! V_3 ) ;
if ( F_50 ( V_88 ) ) {
V_41 = F_36 ( V_50 ) ;
if ( V_41 )
F_38 ( L_13 ,
V_62 , V_41 ) ;
}
V_87 = F_51 ( L_14 ) ;
if ( ! F_52 ( V_87 ) )
F_53 ( V_87 , V_89 , V_90 ,
V_90 ) ;
}
void T_3 F_54 ( void )
{
F_48 ( & V_91 ) ;
}
void T_3 F_55 ( void )
{
F_48 ( & V_92 ) ;
}
void T_3 F_56 ( void )
{
F_48 ( & V_93 ) ;
}
void T_3 F_57 ( void )
{
F_48 ( & V_94 ) ;
}
