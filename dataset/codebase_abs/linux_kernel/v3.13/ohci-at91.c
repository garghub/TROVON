static void F_1 ( void )
{
if ( F_2 ( V_1 ) ) {
F_3 ( V_2 , 48000000 ) ;
F_4 ( V_2 ) ;
}
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_4 ( V_5 ) ;
V_6 = 1 ;
}
static void F_5 ( void )
{
F_6 ( V_5 ) ;
F_6 ( V_4 ) ;
F_6 ( V_3 ) ;
if ( F_2 ( V_1 ) )
F_6 ( V_2 ) ;
V_6 = 0 ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
struct V_11 T_1 * V_12 = V_10 -> V_12 ;
F_9 ( & V_8 -> V_13 , L_1 ) ;
F_1 () ;
F_10 ( 0 , & V_12 -> V_14 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
struct V_11 T_1 * V_12 = V_10 -> V_12 ;
F_9 ( & V_8 -> V_13 , L_2 ) ;
F_10 ( 0 , & V_12 -> V_14 ) ;
F_5 () ;
}
static int F_12 ( const struct V_15 * V_16 ,
struct V_7 * V_8 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
struct V_9 * V_10 = NULL ;
struct V_22 * V_13 = & V_8 -> V_13 ;
struct V_23 * V_24 ;
int V_25 ;
V_24 = F_13 ( V_8 , V_26 , 0 ) ;
if ( ! V_24 ) {
F_9 ( V_13 , L_3 ) ;
return - V_27 ;
}
V_25 = F_14 ( V_8 , 0 ) ;
if ( V_25 < 0 ) {
F_9 ( V_13 , L_4 ) ;
return V_25 ;
}
V_10 = F_15 ( V_16 , & V_8 -> V_13 , L_5 ) ;
if ( ! V_10 )
return - V_28 ;
V_10 -> V_29 = V_24 -> V_30 ;
V_10 -> V_31 = F_16 ( V_24 ) ;
if ( ! F_17 ( V_10 -> V_29 , V_10 -> V_31 , V_32 ) ) {
F_18 ( L_6 ) ;
V_21 = - V_33 ;
goto V_34;
}
V_10 -> V_12 = F_19 ( V_10 -> V_29 , V_10 -> V_31 ) ;
if ( ! V_10 -> V_12 ) {
F_18 ( L_7 ) ;
V_21 = - V_35 ;
goto V_36;
}
V_4 = F_20 ( & V_8 -> V_13 , L_8 ) ;
if ( F_21 ( V_4 ) ) {
F_22 ( & V_8 -> V_13 , L_9 ) ;
V_21 = F_23 ( V_4 ) ;
goto V_37;
}
V_5 = F_20 ( & V_8 -> V_13 , L_10 ) ;
if ( F_21 ( V_5 ) ) {
F_22 ( & V_8 -> V_13 , L_11 ) ;
V_21 = F_23 ( V_5 ) ;
goto V_38;
}
V_3 = F_20 ( & V_8 -> V_13 , L_12 ) ;
if ( F_21 ( V_3 ) ) {
F_22 ( & V_8 -> V_13 , L_13 ) ;
V_21 = F_23 ( V_3 ) ;
goto V_39;
}
if ( F_2 ( V_1 ) ) {
V_2 = F_20 ( & V_8 -> V_13 , L_14 ) ;
if ( F_21 ( V_2 ) ) {
F_22 ( & V_8 -> V_13 , L_15 ) ;
V_21 = F_23 ( V_2 ) ;
goto V_40;
}
}
V_18 = V_10 -> V_41 . V_42 -> V_43 ;
V_20 = F_24 ( V_10 ) ;
V_20 -> V_44 = V_18 -> V_45 ;
F_7 ( V_8 ) ;
V_21 = F_25 ( V_10 , V_25 , V_46 ) ;
if ( V_21 == 0 )
return V_21 ;
F_11 ( V_8 ) ;
if ( F_2 ( V_1 ) )
F_26 ( V_2 ) ;
V_40:
F_26 ( V_3 ) ;
V_39:
F_26 ( V_5 ) ;
V_38:
F_26 ( V_4 ) ;
V_37:
F_27 ( V_10 -> V_12 ) ;
V_36:
F_28 ( V_10 -> V_29 , V_10 -> V_31 ) ;
V_34:
F_29 ( V_10 ) ;
return V_21 ;
}
static void F_30 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
F_31 ( V_10 ) ;
F_11 ( V_8 ) ;
F_27 ( V_10 -> V_12 ) ;
F_28 ( V_10 -> V_29 , V_10 -> V_31 ) ;
F_29 ( V_10 ) ;
if ( F_2 ( V_1 ) )
F_26 ( V_2 ) ;
F_26 ( V_3 ) ;
F_26 ( V_5 ) ;
F_26 ( V_4 ) ;
V_5 = V_4 = V_3 = NULL ;
}
static void F_32 ( struct V_17 * V_47 , int V_48 , int V_49 )
{
if ( ! F_33 ( V_48 ) )
return;
if ( ! F_34 ( V_47 -> V_50 [ V_48 ] ) )
return;
F_35 ( V_47 -> V_50 [ V_48 ] ,
V_47 -> V_51 [ V_48 ] ^ V_49 ) ;
}
static int F_36 ( struct V_17 * V_47 , int V_48 )
{
if ( ! F_33 ( V_48 ) )
return - V_52 ;
if ( ! F_34 ( V_47 -> V_50 [ V_48 ] ) )
return - V_52 ;
return F_37 ( V_47 -> V_50 [ V_48 ] ) ^
V_47 -> V_51 [ V_48 ] ;
}
static int F_38 ( struct V_9 * V_10 , char * V_53 )
{
struct V_17 * V_47 = V_10 -> V_41 . V_42 -> V_43 ;
int V_54 = F_39 ( V_10 , V_53 ) ;
int V_48 ;
F_40 (port) {
if ( V_47 -> V_55 [ V_48 ] ) {
if ( ! V_54 )
V_54 = 1 ;
V_53 [ 0 ] |= 1 << ( V_48 + 1 ) ;
}
}
return V_54 ;
}
static int F_41 ( struct V_9 * V_10 , T_2 V_56 , T_2 V_57 ,
T_2 V_58 , char * V_53 , T_2 V_59 )
{
struct V_17 * V_47 = F_42 ( V_10 -> V_41 . V_42 ) ;
struct V_60 * V_61 ;
int V_62 = - V_52 ;
T_3 * V_63 = ( T_3 * ) V_53 ;
F_9 ( V_10 -> V_41 . V_42 ,
L_16 ,
V_10 , V_56 , V_57 , V_58 , V_53 , V_59 ) ;
V_58 -- ;
switch ( V_56 ) {
case V_64 :
if ( V_57 == V_65 ) {
F_9 ( V_10 -> V_41 . V_42 , L_17 ) ;
if ( F_33 ( V_58 ) ) {
F_32 ( V_47 , V_58 , 1 ) ;
V_62 = 0 ;
}
goto V_66;
}
break;
case V_67 :
switch ( V_57 ) {
case V_68 :
F_9 ( V_10 -> V_41 . V_42 ,
L_18 ) ;
if ( F_33 ( V_58 ) ) {
V_47 -> V_55 [ V_58 ] = 0 ;
V_47 -> V_69 [ V_58 ] = 0 ;
}
goto V_66;
case V_70 :
F_9 ( V_10 -> V_41 . V_42 ,
L_19 ) ;
if ( F_33 ( V_58 ) )
V_47 -> V_69 [ V_58 ] = 0 ;
goto V_66;
case V_65 :
F_9 ( V_10 -> V_41 . V_42 ,
L_20 ) ;
if ( F_33 ( V_58 ) ) {
F_32 ( V_47 , V_58 , 0 ) ;
return 0 ;
}
}
break;
}
V_62 = F_43 ( V_10 , V_56 , V_57 , V_58 + 1 ,
V_53 , V_59 ) ;
if ( V_62 )
goto V_66;
switch ( V_56 ) {
case V_71 :
V_61 = (struct V_60 * ) V_53 ;
F_9 ( V_10 -> V_41 . V_42 , L_21 ,
V_61 -> V_72 ) ;
V_61 -> V_72 &= ~ F_44 ( V_73 ) ;
V_61 -> V_72 |= F_44 ( 0x0001 ) ;
if ( V_47 -> V_74 ) {
V_61 -> V_72 &= ~ F_44 ( V_75 ) ;
V_61 -> V_72 |= F_44 ( 0x0008 | 0x0001 ) ;
}
F_9 ( V_10 -> V_41 . V_42 , L_22 ,
V_61 -> V_72 ) ;
return V_62 ;
case V_76 :
F_9 ( V_10 -> V_41 . V_42 , L_23 , V_58 ) ;
if ( F_33 ( V_58 ) ) {
if ( ! F_36 ( V_47 , V_58 ) )
* V_63 &= ~ F_45 ( V_77 ) ;
if ( V_47 -> V_55 [ V_58 ] )
* V_63 |= F_45 ( V_78 ) ;
if ( V_47 -> V_69 [ V_58 ] )
* V_63 |= F_45 ( V_79 ) ;
}
}
V_66:
return V_62 ;
}
static T_4 F_46 ( int V_25 , void * V_63 )
{
struct V_7 * V_8 = V_63 ;
struct V_17 * V_47 = F_42 ( & V_8 -> V_13 ) ;
int V_80 , V_81 , V_48 ;
F_40 (port) {
if ( F_34 ( V_47 -> V_82 [ V_48 ] ) &&
F_47 ( V_47 -> V_82 [ V_48 ] ) == V_25 ) {
V_81 = V_47 -> V_82 [ V_48 ] ;
break;
}
}
if ( V_48 == V_83 ) {
F_22 ( & V_8 -> V_13 , L_24 ) ;
return V_84 ;
}
V_80 = F_37 ( V_81 ) ;
if ( ! V_80 ) {
F_32 ( V_47 , V_48 , 0 ) ;
V_47 -> V_69 [ V_48 ] = 1 ;
V_47 -> V_55 [ V_48 ] = 1 ;
}
F_9 ( & V_8 -> V_13 , L_25 ,
V_80 ? L_26 : L_27 ) ;
return V_84 ;
}
static int F_48 ( struct V_7 * V_8 )
{
struct V_85 * V_86 = V_8 -> V_13 . V_87 ;
int V_88 , V_81 , V_62 ;
enum V_89 V_90 ;
struct V_17 * V_47 ;
T_3 V_45 ;
if ( ! V_86 )
return 0 ;
V_62 = F_49 ( & V_8 -> V_13 , F_50 ( 32 ) ) ;
if ( V_62 )
return V_62 ;
V_47 = F_51 ( & V_8 -> V_13 , sizeof( * V_47 ) , V_91 ) ;
if ( ! V_47 )
return - V_28 ;
if ( ! F_52 ( V_86 , L_28 , & V_45 ) )
V_47 -> V_45 = V_45 ;
F_40 (i) {
V_81 = F_53 ( V_86 , L_29 , V_88 , & V_90 ) ;
V_47 -> V_50 [ V_88 ] = V_81 ;
if ( ! F_34 ( V_81 ) )
continue;
V_47 -> V_51 [ V_88 ] = V_90 & V_92 ;
}
F_40 (i)
V_47 -> V_82 [ V_88 ] =
F_53 ( V_86 , L_30 , V_88 , & V_90 ) ;
V_8 -> V_13 . V_43 = V_47 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_54 ( struct V_7 * V_8 )
{
struct V_17 * V_47 ;
int V_88 ;
int V_81 ;
int V_62 ;
V_62 = F_48 ( V_8 ) ;
if ( V_62 )
return V_62 ;
V_47 = F_42 ( & V_8 -> V_13 ) ;
if ( V_47 ) {
F_40 (i) {
if ( V_88 >= V_47 -> V_45 ) {
V_47 -> V_50 [ V_88 ] = - V_52 ;
V_47 -> V_82 [ V_88 ] = - V_52 ;
break;
}
if ( ! F_34 ( V_47 -> V_50 [ V_88 ] ) )
continue;
V_81 = V_47 -> V_50 [ V_88 ] ;
V_62 = F_55 ( V_81 , L_31 ) ;
if ( V_62 ) {
F_22 ( & V_8 -> V_13 ,
L_32 , V_81 ) ;
continue;
}
V_62 = F_56 ( V_81 ,
! V_47 -> V_51 [ V_88 ] ) ;
if ( V_62 ) {
F_22 ( & V_8 -> V_13 ,
L_33 ,
V_81 , ! V_47 -> V_51 [ V_88 ] ) ;
F_57 ( V_81 ) ;
continue;
}
F_32 ( V_47 , V_88 , 1 ) ;
}
F_40 (i) {
if ( ! F_34 ( V_47 -> V_82 [ V_88 ] ) )
continue;
V_81 = V_47 -> V_82 [ V_88 ] ;
V_62 = F_55 ( V_81 , L_34 ) ;
if ( V_62 ) {
F_22 ( & V_8 -> V_13 ,
L_35 ,
V_81 ) ;
continue;
}
V_62 = F_58 ( V_81 ) ;
if ( V_62 ) {
F_22 ( & V_8 -> V_13 ,
L_36 ,
V_81 ) ;
F_57 ( V_81 ) ;
continue;
}
V_62 = F_59 ( F_47 ( V_81 ) ,
F_46 ,
V_46 , L_34 , V_8 ) ;
if ( V_62 ) {
F_57 ( V_81 ) ;
F_22 ( & V_8 -> V_13 ,
L_37 ) ;
}
}
}
F_60 ( & V_8 -> V_13 , 1 ) ;
return F_12 ( & V_93 , V_8 ) ;
}
static int F_61 ( struct V_7 * V_8 )
{
struct V_17 * V_47 = F_42 ( & V_8 -> V_13 ) ;
int V_88 ;
if ( V_47 ) {
F_40 (i) {
if ( ! F_34 ( V_47 -> V_50 [ V_88 ] ) )
continue;
F_32 ( V_47 , V_88 , 0 ) ;
F_57 ( V_47 -> V_50 [ V_88 ] ) ;
}
F_40 (i) {
if ( ! F_34 ( V_47 -> V_82 [ V_88 ] ) )
continue;
F_62 ( F_47 ( V_47 -> V_82 [ V_88 ] ) , V_8 ) ;
F_57 ( V_47 -> V_82 [ V_88 ] ) ;
}
}
F_60 ( & V_8 -> V_13 , 0 ) ;
F_30 ( F_8 ( V_8 ) , V_8 ) ;
return 0 ;
}
static int
F_63 ( struct V_7 * V_8 , T_5 V_94 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
struct V_19 * V_20 = F_24 ( V_10 ) ;
if ( F_64 ( & V_8 -> V_13 ) )
F_65 ( V_10 -> V_25 ) ;
if ( F_66 () ) {
V_20 -> V_95 = F_67 ( V_20 , & V_20 -> V_12 -> V_14 ) ;
V_20 -> V_95 &= V_96 ;
F_68 ( V_20 , V_20 -> V_95 , & V_20 -> V_12 -> V_14 ) ;
V_20 -> V_97 = V_98 ;
( void ) F_67 ( V_20 , & V_20 -> V_12 -> V_14 ) ;
F_5 () ;
}
return 0 ;
}
static int F_69 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
if ( F_64 ( & V_8 -> V_13 ) )
F_70 ( V_10 -> V_25 ) ;
if ( ! V_6 )
F_1 () ;
F_71 ( V_10 , false ) ;
return 0 ;
}
static int T_6 F_72 ( void )
{
if ( F_73 () )
return - V_99 ;
F_74 ( L_38 V_100 L_39 , V_32 ) ;
F_75 ( & V_93 , NULL ) ;
F_43 = V_93 . V_101 ;
F_39 = V_93 . V_102 ;
V_93 . V_102 = F_38 ;
V_93 . V_101 = F_41 ;
return F_76 ( & V_103 ) ;
}
static void T_7 F_77 ( void )
{
F_78 ( & V_103 ) ;
}
