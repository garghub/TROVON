static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return;
if ( F_2 ( V_4 ) ) {
F_3 ( V_2 -> V_5 , 48000000 ) ;
F_4 ( V_2 -> V_5 ) ;
}
F_4 ( V_2 -> V_6 ) ;
F_4 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_8 ) ;
V_2 -> V_3 = true ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_6 ( V_2 -> V_8 ) ;
F_6 ( V_2 -> V_7 ) ;
F_6 ( V_2 -> V_6 ) ;
if ( F_2 ( V_4 ) )
F_6 ( V_2 -> V_5 ) ;
V_2 -> V_3 = false ;
}
static void F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_13 T_1 * V_14 = V_12 -> V_14 ;
struct V_1 * V_2 = F_9 ( V_12 ) ;
F_10 ( & V_10 -> V_15 , L_1 ) ;
F_1 ( V_2 ) ;
F_11 ( 0 , & V_14 -> V_16 ) ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_13 T_1 * V_14 = V_12 -> V_14 ;
struct V_1 * V_2 = F_9 ( V_12 ) ;
F_10 ( & V_10 -> V_15 , L_2 ) ;
F_11 ( 0 , & V_14 -> V_16 ) ;
F_5 ( V_2 ) ;
}
static int F_13 ( const struct V_17 * V_18 ,
struct V_9 * V_10 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_24 * V_15 = & V_10 -> V_15 ;
struct V_25 * V_26 ;
int V_27 ;
V_27 = F_14 ( V_10 , 0 ) ;
if ( V_27 < 0 ) {
F_10 ( V_15 , L_3 ) ;
return V_27 ;
}
V_12 = F_15 ( V_18 , V_15 , L_4 ) ;
if ( ! V_12 )
return - V_28 ;
V_2 = F_9 ( V_12 ) ;
V_26 = F_16 ( V_10 , V_29 , 0 ) ;
V_12 -> V_14 = F_17 ( V_15 , V_26 ) ;
if ( F_18 ( V_12 -> V_14 ) ) {
V_23 = F_19 ( V_12 -> V_14 ) ;
goto V_30;
}
V_12 -> V_31 = V_26 -> V_32 ;
V_12 -> V_33 = F_20 ( V_26 ) ;
V_2 -> V_7 = F_21 ( V_15 , L_5 ) ;
if ( F_18 ( V_2 -> V_7 ) ) {
F_22 ( V_15 , L_6 ) ;
V_23 = F_19 ( V_2 -> V_7 ) ;
goto V_30;
}
V_2 -> V_8 = F_21 ( V_15 , L_7 ) ;
if ( F_18 ( V_2 -> V_8 ) ) {
F_22 ( V_15 , L_8 ) ;
V_23 = F_19 ( V_2 -> V_8 ) ;
goto V_30;
}
V_2 -> V_6 = F_21 ( V_15 , L_9 ) ;
if ( F_18 ( V_2 -> V_6 ) ) {
F_22 ( V_15 , L_10 ) ;
V_23 = F_19 ( V_2 -> V_6 ) ;
goto V_30;
}
if ( F_2 ( V_4 ) ) {
V_2 -> V_5 = F_21 ( V_15 , L_11 ) ;
if ( F_18 ( V_2 -> V_5 ) ) {
F_22 ( V_15 , L_12 ) ;
V_23 = F_19 ( V_2 -> V_5 ) ;
goto V_30;
}
}
V_20 = V_12 -> V_34 . V_35 -> V_36 ;
V_22 = F_23 ( V_12 ) ;
V_22 -> V_37 = V_20 -> V_38 ;
F_7 ( V_10 ) ;
V_23 = F_24 ( V_12 , V_27 , V_39 ) ;
if ( V_23 == 0 ) {
F_25 ( V_12 -> V_34 . V_35 ) ;
return V_23 ;
}
F_12 ( V_10 ) ;
V_30:
F_26 ( V_12 ) ;
return V_23 ;
}
static void F_27 ( struct V_11 * V_12 ,
struct V_9 * V_10 )
{
F_28 ( V_12 ) ;
F_12 ( V_10 ) ;
F_26 ( V_12 ) ;
}
static void F_29 ( struct V_19 * V_40 , int V_41 , int V_42 )
{
if ( ! F_30 ( V_41 ) )
return;
if ( ! F_31 ( V_40 -> V_43 [ V_41 ] ) )
return;
F_32 ( V_40 -> V_43 [ V_41 ] ,
V_40 -> V_44 [ V_41 ] ^ V_42 ) ;
}
static int F_33 ( struct V_19 * V_40 , int V_41 )
{
if ( ! F_30 ( V_41 ) )
return - V_45 ;
if ( ! F_31 ( V_40 -> V_43 [ V_41 ] ) )
return - V_45 ;
return F_34 ( V_40 -> V_43 [ V_41 ] ) ^
V_40 -> V_44 [ V_41 ] ;
}
static int F_35 ( struct V_11 * V_12 , char * V_46 )
{
struct V_19 * V_40 = V_12 -> V_34 . V_35 -> V_36 ;
int V_47 = F_36 ( V_12 , V_46 ) ;
int V_41 ;
F_37 (port) {
if ( V_40 -> V_48 [ V_41 ] ) {
if ( ! V_47 )
V_47 = 1 ;
V_46 [ 0 ] |= 1 << ( V_41 + 1 ) ;
}
}
return V_47 ;
}
static int F_38 ( struct V_11 * V_12 , T_2 V_49 , T_2 V_50 ,
T_2 V_51 , char * V_46 , T_2 V_52 )
{
struct V_19 * V_40 = F_39 ( V_12 -> V_34 . V_35 ) ;
struct V_53 * V_54 ;
int V_55 = - V_45 ;
T_3 * V_56 = ( T_3 * ) V_46 ;
F_10 ( V_12 -> V_34 . V_35 ,
L_13 ,
V_12 , V_49 , V_50 , V_51 , V_46 , V_52 ) ;
V_51 -- ;
switch ( V_49 ) {
case V_57 :
if ( V_50 == V_58 ) {
F_10 ( V_12 -> V_34 . V_35 , L_14 ) ;
if ( F_30 ( V_51 ) ) {
F_29 ( V_40 , V_51 , 1 ) ;
V_55 = 0 ;
}
goto V_59;
}
break;
case V_60 :
switch ( V_50 ) {
case V_61 :
F_10 ( V_12 -> V_34 . V_35 ,
L_15 ) ;
if ( F_30 ( V_51 ) ) {
V_40 -> V_48 [ V_51 ] = 0 ;
V_40 -> V_62 [ V_51 ] = 0 ;
}
goto V_59;
case V_63 :
F_10 ( V_12 -> V_34 . V_35 ,
L_16 ) ;
if ( F_30 ( V_51 ) )
V_40 -> V_62 [ V_51 ] = 0 ;
goto V_59;
case V_58 :
F_10 ( V_12 -> V_34 . V_35 ,
L_17 ) ;
if ( F_30 ( V_51 ) ) {
F_29 ( V_40 , V_51 , 0 ) ;
return 0 ;
}
}
break;
}
V_55 = F_40 ( V_12 , V_49 , V_50 , V_51 + 1 , V_46 , V_52 ) ;
if ( V_55 )
goto V_59;
switch ( V_49 ) {
case V_64 :
V_54 = (struct V_53 * ) V_46 ;
F_10 ( V_12 -> V_34 . V_35 , L_18 ,
V_54 -> V_65 ) ;
V_54 -> V_65 &= ~ F_41 ( V_66 ) ;
V_54 -> V_65 |=
F_41 ( V_67 ) ;
if ( V_40 -> V_68 ) {
V_54 -> V_65 &= ~ F_41 ( V_69 ) ;
V_54 -> V_65 |=
F_41 ( V_70 ) ;
}
F_10 ( V_12 -> V_34 . V_35 , L_19 ,
V_54 -> V_65 ) ;
return V_55 ;
case V_71 :
F_10 ( V_12 -> V_34 . V_35 , L_20 , V_51 ) ;
if ( F_30 ( V_51 ) ) {
if ( ! F_33 ( V_40 , V_51 ) )
* V_56 &= ~ F_42 ( V_72 ) ;
if ( V_40 -> V_48 [ V_51 ] )
* V_56 |= F_42 ( V_73 ) ;
if ( V_40 -> V_62 [ V_51 ] )
* V_56 |= F_42 ( V_74 ) ;
}
}
V_59:
return V_55 ;
}
static T_4 F_43 ( int V_27 , void * V_56 )
{
struct V_9 * V_10 = V_56 ;
struct V_19 * V_40 = F_39 ( & V_10 -> V_15 ) ;
int V_75 , V_76 , V_41 ;
F_37 (port) {
if ( F_31 ( V_40 -> V_77 [ V_41 ] ) &&
F_44 ( V_40 -> V_77 [ V_41 ] ) == V_27 ) {
V_76 = V_40 -> V_77 [ V_41 ] ;
break;
}
}
if ( V_41 == V_78 ) {
F_22 ( & V_10 -> V_15 , L_21 ) ;
return V_79 ;
}
V_75 = F_34 ( V_76 ) ;
if ( ! V_75 ) {
F_29 ( V_40 , V_41 , 0 ) ;
V_40 -> V_62 [ V_41 ] = 1 ;
V_40 -> V_48 [ V_41 ] = 1 ;
}
F_10 ( & V_10 -> V_15 , L_22 ,
V_75 ? L_23 : L_24 ) ;
return V_79 ;
}
static int F_45 ( struct V_9 * V_10 )
{
struct V_80 * V_81 = V_10 -> V_15 . V_82 ;
int V_83 , V_76 , V_55 ;
enum V_84 V_85 ;
struct V_19 * V_40 ;
T_3 V_38 ;
if ( ! V_81 )
return 0 ;
V_55 = F_46 ( & V_10 -> V_15 , F_47 ( 32 ) ) ;
if ( V_55 )
return V_55 ;
V_40 = F_48 ( & V_10 -> V_15 , sizeof( * V_40 ) , V_86 ) ;
if ( ! V_40 )
return - V_28 ;
if ( ! F_49 ( V_81 , L_25 , & V_38 ) )
V_40 -> V_38 = V_38 ;
F_37 (i) {
V_76 = F_50 ( V_81 , L_26 , V_83 , & V_85 ) ;
V_40 -> V_43 [ V_83 ] = V_76 ;
if ( ! F_31 ( V_76 ) )
continue;
V_40 -> V_44 [ V_83 ] = V_85 & V_87 ;
}
F_37 (i)
V_40 -> V_77 [ V_83 ] =
F_50 ( V_81 , L_27 , V_83 , & V_85 ) ;
V_10 -> V_15 . V_36 = V_40 ;
return 0 ;
}
static int F_45 ( struct V_9 * V_10 )
{
return 0 ;
}
static int F_51 ( struct V_9 * V_10 )
{
struct V_19 * V_40 ;
int V_83 ;
int V_76 ;
int V_55 ;
V_55 = F_45 ( V_10 ) ;
if ( V_55 )
return V_55 ;
V_40 = F_39 ( & V_10 -> V_15 ) ;
if ( V_40 ) {
F_37 (i) {
if ( V_83 >= V_40 -> V_38 ) {
V_40 -> V_43 [ V_83 ] = - V_45 ;
V_40 -> V_77 [ V_83 ] = - V_45 ;
break;
}
if ( ! F_31 ( V_40 -> V_43 [ V_83 ] ) )
continue;
V_76 = V_40 -> V_43 [ V_83 ] ;
V_55 = F_52 ( V_76 , L_28 ) ;
if ( V_55 ) {
F_22 ( & V_10 -> V_15 ,
L_29 , V_76 ) ;
continue;
}
V_55 = F_53 ( V_76 ,
! V_40 -> V_44 [ V_83 ] ) ;
if ( V_55 ) {
F_22 ( & V_10 -> V_15 ,
L_30 ,
V_76 , ! V_40 -> V_44 [ V_83 ] ) ;
F_54 ( V_76 ) ;
continue;
}
F_29 ( V_40 , V_83 , 1 ) ;
}
F_37 (i) {
if ( ! F_31 ( V_40 -> V_77 [ V_83 ] ) )
continue;
V_76 = V_40 -> V_77 [ V_83 ] ;
V_55 = F_52 ( V_76 , L_31 ) ;
if ( V_55 ) {
F_22 ( & V_10 -> V_15 ,
L_32 ,
V_76 ) ;
continue;
}
V_55 = F_55 ( V_76 ) ;
if ( V_55 ) {
F_22 ( & V_10 -> V_15 ,
L_33 ,
V_76 ) ;
F_54 ( V_76 ) ;
continue;
}
V_55 = F_56 ( F_44 ( V_76 ) ,
F_43 ,
V_39 , L_31 , V_10 ) ;
if ( V_55 ) {
F_54 ( V_76 ) ;
F_22 ( & V_10 -> V_15 ,
L_34 ) ;
}
}
}
F_57 ( & V_10 -> V_15 , 1 ) ;
return F_13 ( & V_88 , V_10 ) ;
}
static int F_58 ( struct V_9 * V_10 )
{
struct V_19 * V_40 = F_39 ( & V_10 -> V_15 ) ;
int V_83 ;
if ( V_40 ) {
F_37 (i) {
if ( ! F_31 ( V_40 -> V_43 [ V_83 ] ) )
continue;
F_29 ( V_40 , V_83 , 0 ) ;
F_54 ( V_40 -> V_43 [ V_83 ] ) ;
}
F_37 (i) {
if ( ! F_31 ( V_40 -> V_77 [ V_83 ] ) )
continue;
F_59 ( F_44 ( V_40 -> V_77 [ V_83 ] ) , V_10 ) ;
F_54 ( V_40 -> V_77 [ V_83 ] ) ;
}
}
F_57 ( & V_10 -> V_15 , 0 ) ;
F_27 ( F_8 ( V_10 ) , V_10 ) ;
return 0 ;
}
static int
F_60 ( struct V_24 * V_15 )
{
struct V_11 * V_12 = F_61 ( V_15 ) ;
struct V_21 * V_22 = F_23 ( V_12 ) ;
struct V_1 * V_2 = F_9 ( V_12 ) ;
int V_55 ;
V_2 -> V_89 = F_62 ( V_15 )
&& ! F_63 () ;
if ( V_2 -> V_89 )
F_64 ( V_12 -> V_27 ) ;
V_55 = F_65 ( V_12 , V_2 -> V_89 ) ;
if ( V_55 ) {
if ( V_2 -> V_89 )
F_66 ( V_12 -> V_27 ) ;
return V_55 ;
}
if ( ! V_2 -> V_89 ) {
V_22 -> V_90 = F_67 ( V_22 , & V_22 -> V_14 -> V_16 ) ;
V_22 -> V_90 &= V_91 ;
F_68 ( V_22 , V_22 -> V_90 , & V_22 -> V_14 -> V_16 ) ;
V_22 -> V_92 = V_93 ;
( void ) F_67 ( V_22 , & V_22 -> V_14 -> V_16 ) ;
F_5 ( V_2 ) ;
}
return V_55 ;
}
static int F_69 ( struct V_24 * V_15 )
{
struct V_11 * V_12 = F_61 ( V_15 ) ;
struct V_1 * V_2 = F_9 ( V_12 ) ;
if ( V_2 -> V_89 )
F_66 ( V_12 -> V_27 ) ;
F_1 ( V_2 ) ;
F_70 ( V_12 , false ) ;
return 0 ;
}
static int T_5 F_71 ( void )
{
if ( F_72 () )
return - V_94 ;
F_73 ( L_35 V_95 L_36 , V_96 ) ;
F_74 ( & V_88 , & V_97 ) ;
V_88 . V_98 = F_35 ;
V_88 . V_99 = F_38 ;
return F_75 ( & V_100 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_100 ) ;
}
