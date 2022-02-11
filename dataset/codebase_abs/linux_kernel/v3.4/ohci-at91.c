static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
V_4 = 1 ;
}
static void F_3 ( void )
{
F_4 ( V_3 ) ;
F_4 ( V_2 ) ;
F_4 ( V_1 ) ;
V_4 = 0 ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_9 T_1 * V_10 = V_8 -> V_10 ;
F_7 ( & V_6 -> V_11 , L_1 ) ;
F_1 () ;
F_8 ( 0 , & V_10 -> V_12 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_9 T_1 * V_10 = V_8 -> V_10 ;
F_7 ( & V_6 -> V_11 , L_2 ) ;
F_8 ( 0 , & V_10 -> V_12 ) ;
F_3 () ;
}
static int T_2 F_10 ( const struct V_13 * V_14 ,
struct V_5 * V_6 )
{
int V_15 ;
struct V_7 * V_8 = NULL ;
if ( V_6 -> V_16 != 2 ) {
F_11 ( L_3 ) ;
return - V_17 ;
}
if ( ( V_6 -> V_18 [ 0 ] . V_19 != V_20 )
|| ( V_6 -> V_18 [ 1 ] . V_19 != V_21 ) ) {
F_11 ( L_4 ) ;
return - V_17 ;
}
V_8 = F_12 ( V_14 , & V_6 -> V_11 , L_5 ) ;
if ( ! V_8 )
return - V_22 ;
V_8 -> V_23 = V_6 -> V_18 [ 0 ] . V_24 ;
V_8 -> V_25 = V_6 -> V_18 [ 0 ] . V_26 - V_6 -> V_18 [ 0 ] . V_24 + 1 ;
if ( ! F_13 ( V_8 -> V_23 , V_8 -> V_25 , V_27 ) ) {
F_11 ( L_6 ) ;
V_15 = - V_28 ;
goto V_29;
}
V_8 -> V_10 = F_14 ( V_8 -> V_23 , V_8 -> V_25 ) ;
if ( ! V_8 -> V_10 ) {
F_11 ( L_7 ) ;
V_15 = - V_30 ;
goto V_31;
}
V_2 = F_15 ( & V_6 -> V_11 , L_8 ) ;
if ( F_16 ( V_2 ) ) {
F_17 ( & V_6 -> V_11 , L_9 ) ;
V_15 = F_18 ( V_2 ) ;
goto V_32;
}
V_3 = F_15 ( & V_6 -> V_11 , L_10 ) ;
if ( F_16 ( V_3 ) ) {
F_17 ( & V_6 -> V_11 , L_11 ) ;
V_15 = F_18 ( V_3 ) ;
goto V_33;
}
V_1 = F_15 ( & V_6 -> V_11 , L_12 ) ;
if ( F_16 ( V_1 ) ) {
F_17 ( & V_6 -> V_11 , L_13 ) ;
V_15 = F_18 ( V_1 ) ;
goto V_34;
}
F_5 ( V_6 ) ;
F_19 ( F_20 ( V_8 ) ) ;
V_15 = F_21 ( V_8 , V_6 -> V_18 [ 1 ] . V_24 , V_35 ) ;
if ( V_15 == 0 )
return V_15 ;
F_9 ( V_6 ) ;
F_22 ( V_1 ) ;
V_34:
F_22 ( V_3 ) ;
V_33:
F_22 ( V_2 ) ;
V_32:
F_23 ( V_8 -> V_10 ) ;
V_31:
F_24 ( V_8 -> V_23 , V_8 -> V_25 ) ;
V_29:
F_25 ( V_8 ) ;
return V_15 ;
}
static void T_3 F_26 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_27 ( V_8 ) ;
F_9 ( V_6 ) ;
F_23 ( V_8 -> V_10 ) ;
F_24 ( V_8 -> V_23 , V_8 -> V_25 ) ;
F_25 ( V_8 ) ;
F_22 ( V_1 ) ;
F_22 ( V_3 ) ;
F_22 ( V_2 ) ;
V_3 = V_2 = V_1 = NULL ;
F_28 ( & V_6 -> V_11 , NULL ) ;
}
static int T_2
F_29 ( struct V_7 * V_8 )
{
struct V_36 * V_37 = V_8 -> V_38 . V_39 -> V_40 ;
struct V_41 * V_42 = F_20 ( V_8 ) ;
int V_43 ;
if ( ( V_43 = F_30 ( V_42 ) ) < 0 )
return V_43 ;
V_42 -> V_44 = V_37 -> V_45 ;
if ( ( V_43 = F_31 ( V_42 ) ) < 0 ) {
F_32 ( L_14 , V_8 -> V_38 . V_46 ) ;
F_33 ( V_8 ) ;
return V_43 ;
}
return 0 ;
}
static void F_34 ( struct V_36 * V_47 , int V_48 , int V_49 )
{
if ( ! F_35 ( V_48 ) )
return;
if ( ! F_36 ( V_47 -> V_50 [ V_48 ] ) )
return;
F_37 ( V_47 -> V_50 [ V_48 ] ,
V_47 -> V_51 [ V_48 ] ^ V_49 ) ;
}
static int F_38 ( struct V_36 * V_47 , int V_48 )
{
if ( ! F_35 ( V_48 ) )
return - V_52 ;
if ( ! F_36 ( V_47 -> V_50 [ V_48 ] ) )
return - V_52 ;
return F_39 ( V_47 -> V_50 [ V_48 ] ) ^
V_47 -> V_51 [ V_48 ] ;
}
static int F_40 ( struct V_7 * V_8 , char * V_53 )
{
struct V_36 * V_47 = V_8 -> V_38 . V_39 -> V_40 ;
int V_54 = F_41 ( V_8 , V_53 ) ;
int V_48 ;
F_42 (port) {
if ( V_47 -> V_55 [ V_48 ] ) {
if ( ! V_54 )
V_54 = 1 ;
V_53 [ 0 ] |= 1 << ( V_48 + 1 ) ;
}
}
return V_54 ;
}
static int F_43 ( struct V_7 * V_8 , T_4 V_56 , T_4 V_57 ,
T_4 V_58 , char * V_53 , T_4 V_59 )
{
struct V_36 * V_47 = V_8 -> V_38 . V_39 -> V_40 ;
struct V_60 * V_61 ;
int V_43 = - V_52 ;
T_5 * V_62 = ( T_5 * ) V_53 ;
F_7 ( V_8 -> V_38 . V_39 ,
L_15 ,
V_8 , V_56 , V_57 , V_58 , V_53 , V_59 ) ;
V_58 -- ;
switch ( V_56 ) {
case V_63 :
if ( V_57 == V_64 ) {
F_7 ( V_8 -> V_38 . V_39 , L_16 ) ;
if ( F_35 ( V_58 ) ) {
F_34 ( V_47 , V_58 , 1 ) ;
V_43 = 0 ;
}
goto V_65;
}
break;
case V_66 :
switch ( V_57 ) {
case V_67 :
F_7 ( V_8 -> V_38 . V_39 ,
L_17 ) ;
if ( F_35 ( V_58 ) ) {
V_47 -> V_55 [ V_58 ] = 0 ;
V_47 -> V_68 [ V_58 ] = 0 ;
}
goto V_65;
case V_69 :
F_7 ( V_8 -> V_38 . V_39 ,
L_18 ) ;
if ( F_35 ( V_58 ) )
V_47 -> V_68 [ V_58 ] = 0 ;
goto V_65;
case V_64 :
F_7 ( V_8 -> V_38 . V_39 ,
L_19 ) ;
if ( F_35 ( V_58 ) ) {
F_34 ( V_47 , V_58 , 0 ) ;
return 0 ;
}
}
break;
}
V_43 = F_44 ( V_8 , V_56 , V_57 , V_58 + 1 , V_53 , V_59 ) ;
if ( V_43 )
goto V_65;
switch ( V_56 ) {
case V_70 :
V_61 = (struct V_60 * ) V_53 ;
F_7 ( V_8 -> V_38 . V_39 , L_20 ,
V_61 -> V_71 ) ;
V_61 -> V_71 &= ~ F_45 ( V_72 ) ;
V_61 -> V_71 |= F_45 ( 0x0001 ) ;
if ( V_47 -> V_73 ) {
V_61 -> V_71 &= ~ F_45 ( V_74 ) ;
V_61 -> V_71 |= F_45 ( 0x0008 | 0x0001 ) ;
}
F_7 ( V_8 -> V_38 . V_39 , L_21 ,
V_61 -> V_71 ) ;
return V_43 ;
case V_75 :
F_7 ( V_8 -> V_38 . V_39 , L_22 , V_58 ) ;
if ( F_35 ( V_58 ) ) {
if ( ! F_38 ( V_47 , V_58 ) )
* V_62 &= ~ F_46 ( V_76 ) ;
if ( V_47 -> V_55 [ V_58 ] )
* V_62 |= F_46 ( V_77 ) ;
if ( V_47 -> V_68 [ V_58 ] )
* V_62 |= F_46 ( V_78 ) ;
}
}
V_65:
return V_43 ;
}
static T_6 F_47 ( int V_79 , void * V_62 )
{
struct V_5 * V_6 = V_62 ;
struct V_36 * V_47 = V_6 -> V_11 . V_40 ;
int V_80 , V_81 , V_48 ;
F_42 (port) {
if ( F_48 ( V_47 -> V_82 [ V_48 ] ) == V_79 ) {
V_81 = V_47 -> V_82 [ V_48 ] ;
break;
}
}
if ( V_48 == V_83 ) {
F_17 ( & V_6 -> V_11 , L_23 ) ;
return V_84 ;
}
V_80 = F_39 ( V_81 ) ;
if ( ! V_80 ) {
F_34 ( V_47 , V_48 , 0 ) ;
V_47 -> V_68 [ V_48 ] = 1 ;
V_47 -> V_55 [ V_48 ] = 1 ;
}
F_7 ( & V_6 -> V_11 , L_24 ,
V_80 ? L_25 : L_26 ) ;
return V_84 ;
}
static int T_2 F_49 ( struct V_5 * V_6 )
{
struct V_85 * V_86 = V_6 -> V_11 . V_87 ;
int V_88 , V_81 ;
enum V_89 V_19 ;
struct V_36 * V_47 ;
T_5 V_45 ;
if ( ! V_86 )
return 0 ;
if ( ! V_6 -> V_11 . V_90 )
V_6 -> V_11 . V_90 = & V_91 ;
V_47 = F_50 ( & V_6 -> V_11 , sizeof( * V_47 ) , V_92 ) ;
if ( ! V_47 )
return - V_22 ;
if ( ! F_51 ( V_86 , L_27 , & V_45 ) )
V_47 -> V_45 = V_45 ;
F_42 (i) {
V_81 = F_52 ( V_86 , L_28 , V_88 , & V_19 ) ;
V_47 -> V_50 [ V_88 ] = V_81 ;
if ( ! F_36 ( V_81 ) )
continue;
V_47 -> V_51 [ V_88 ] = V_19 & V_93 ;
}
F_42 (i)
V_47 -> V_82 [ V_88 ] =
F_52 ( V_86 , L_29 , V_88 , & V_19 ) ;
V_6 -> V_11 . V_40 = V_47 ;
return 0 ;
}
static int T_2 F_49 ( struct V_5 * V_6 )
{
return 0 ;
}
static int T_2 F_53 ( struct V_5 * V_6 )
{
struct V_36 * V_47 ;
int V_88 ;
int V_81 ;
int V_43 ;
V_43 = F_49 ( V_6 ) ;
if ( V_43 )
return V_43 ;
V_47 = V_6 -> V_11 . V_40 ;
if ( V_47 ) {
F_42 (i) {
if ( ! F_36 ( V_47 -> V_50 [ V_88 ] ) )
continue;
V_81 = V_47 -> V_50 [ V_88 ] ;
V_43 = F_54 ( V_81 , L_30 ) ;
if ( V_43 ) {
F_17 ( & V_6 -> V_11 ,
L_31 , V_81 ) ;
continue;
}
V_43 = F_55 ( V_81 ,
! V_47 -> V_51 [ V_88 ] ) ;
if ( V_43 ) {
F_17 ( & V_6 -> V_11 ,
L_32 ,
V_81 , ! V_47 -> V_51 [ V_88 ] ) ;
F_56 ( V_81 ) ;
continue;
}
F_34 ( V_47 , V_88 , 1 ) ;
}
F_42 (i) {
if ( ! F_36 ( V_47 -> V_82 [ V_88 ] ) )
continue;
V_81 = V_47 -> V_82 [ V_88 ] ;
V_43 = F_54 ( V_81 , L_33 ) ;
if ( V_43 ) {
F_17 ( & V_6 -> V_11 ,
L_34 ,
V_81 ) ;
continue;
}
V_43 = F_57 ( V_81 ) ;
if ( V_43 ) {
F_17 ( & V_6 -> V_11 ,
L_35 ,
V_81 ) ;
F_56 ( V_81 ) ;
continue;
}
V_43 = F_58 ( F_48 ( V_81 ) ,
F_47 ,
V_35 , L_33 , V_6 ) ;
if ( V_43 ) {
F_56 ( V_81 ) ;
F_17 ( & V_6 -> V_11 ,
L_36 ) ;
}
}
}
F_59 ( & V_6 -> V_11 , 1 ) ;
return F_10 ( & V_94 , V_6 ) ;
}
static int T_3 F_60 ( struct V_5 * V_6 )
{
struct V_36 * V_47 = V_6 -> V_11 . V_40 ;
int V_88 ;
if ( V_47 ) {
F_42 (i) {
if ( ! F_36 ( V_47 -> V_50 [ V_88 ] ) )
continue;
F_34 ( V_47 , V_88 , 0 ) ;
F_56 ( V_47 -> V_50 [ V_88 ] ) ;
}
F_42 (i) {
if ( ! F_36 ( V_47 -> V_82 [ V_88 ] ) )
continue;
F_61 ( F_48 ( V_47 -> V_82 [ V_88 ] ) , V_6 ) ;
F_56 ( V_47 -> V_82 [ V_88 ] ) ;
}
}
F_59 ( & V_6 -> V_11 , 0 ) ;
F_26 ( F_6 ( V_6 ) , V_6 ) ;
return 0 ;
}
static int
F_62 ( struct V_5 * V_6 , T_7 V_95 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_41 * V_42 = F_20 ( V_8 ) ;
if ( F_63 ( & V_6 -> V_11 ) )
F_64 ( V_8 -> V_79 ) ;
if ( F_65 () ) {
F_66 ( V_42 ) ;
( void ) F_67 ( V_42 , & V_42 -> V_10 -> V_12 ) ;
F_3 () ;
}
return 0 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
if ( F_63 ( & V_6 -> V_11 ) )
F_69 ( V_8 -> V_79 ) ;
if ( ! V_4 )
F_1 () ;
F_70 ( V_8 ) ;
return 0 ;
}
