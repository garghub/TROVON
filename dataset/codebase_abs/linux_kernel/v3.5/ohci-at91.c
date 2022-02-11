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
V_8 -> V_25 = F_13 ( & V_6 -> V_18 [ 0 ] ) ;
if ( ! F_14 ( V_8 -> V_23 , V_8 -> V_25 , V_26 ) ) {
F_11 ( L_6 ) ;
V_15 = - V_27 ;
goto V_28;
}
V_8 -> V_10 = F_15 ( V_8 -> V_23 , V_8 -> V_25 ) ;
if ( ! V_8 -> V_10 ) {
F_11 ( L_7 ) ;
V_15 = - V_29 ;
goto V_30;
}
V_2 = F_16 ( & V_6 -> V_11 , L_8 ) ;
if ( F_17 ( V_2 ) ) {
F_18 ( & V_6 -> V_11 , L_9 ) ;
V_15 = F_19 ( V_2 ) ;
goto V_31;
}
V_3 = F_16 ( & V_6 -> V_11 , L_10 ) ;
if ( F_17 ( V_3 ) ) {
F_18 ( & V_6 -> V_11 , L_11 ) ;
V_15 = F_19 ( V_3 ) ;
goto V_32;
}
V_1 = F_16 ( & V_6 -> V_11 , L_12 ) ;
if ( F_17 ( V_1 ) ) {
F_18 ( & V_6 -> V_11 , L_13 ) ;
V_15 = F_19 ( V_1 ) ;
goto V_33;
}
F_5 ( V_6 ) ;
F_20 ( F_21 ( V_8 ) ) ;
V_15 = F_22 ( V_8 , V_6 -> V_18 [ 1 ] . V_24 , V_34 ) ;
if ( V_15 == 0 )
return V_15 ;
F_9 ( V_6 ) ;
F_23 ( V_1 ) ;
V_33:
F_23 ( V_3 ) ;
V_32:
F_23 ( V_2 ) ;
V_31:
F_24 ( V_8 -> V_10 ) ;
V_30:
F_25 ( V_8 -> V_23 , V_8 -> V_25 ) ;
V_28:
F_26 ( V_8 ) ;
return V_15 ;
}
static void T_3 F_27 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_28 ( V_8 ) ;
F_9 ( V_6 ) ;
F_24 ( V_8 -> V_10 ) ;
F_25 ( V_8 -> V_23 , V_8 -> V_25 ) ;
F_26 ( V_8 ) ;
F_23 ( V_1 ) ;
F_23 ( V_3 ) ;
F_23 ( V_2 ) ;
V_3 = V_2 = V_1 = NULL ;
F_29 ( & V_6 -> V_11 , NULL ) ;
}
static int T_2
F_30 ( struct V_7 * V_8 )
{
struct V_35 * V_36 = V_8 -> V_37 . V_38 -> V_39 ;
struct V_40 * V_41 = F_21 ( V_8 ) ;
int V_42 ;
if ( ( V_42 = F_31 ( V_41 ) ) < 0 )
return V_42 ;
V_41 -> V_43 = V_36 -> V_44 ;
return 0 ;
}
static int T_2
F_32 ( struct V_7 * V_8 )
{
struct V_40 * V_41 = F_21 ( V_8 ) ;
int V_42 ;
if ( ( V_42 = F_33 ( V_41 ) ) < 0 ) {
F_18 ( V_8 -> V_37 . V_38 , L_14 ,
V_8 -> V_37 . V_45 ) ;
F_34 ( V_8 ) ;
return V_42 ;
}
return 0 ;
}
static void F_35 ( struct V_35 * V_46 , int V_47 , int V_48 )
{
if ( ! F_36 ( V_47 ) )
return;
if ( ! F_37 ( V_46 -> V_49 [ V_47 ] ) )
return;
F_38 ( V_46 -> V_49 [ V_47 ] ,
V_46 -> V_50 [ V_47 ] ^ V_48 ) ;
}
static int F_39 ( struct V_35 * V_46 , int V_47 )
{
if ( ! F_36 ( V_47 ) )
return - V_51 ;
if ( ! F_37 ( V_46 -> V_49 [ V_47 ] ) )
return - V_51 ;
return F_40 ( V_46 -> V_49 [ V_47 ] ) ^
V_46 -> V_50 [ V_47 ] ;
}
static int F_41 ( struct V_7 * V_8 , char * V_52 )
{
struct V_35 * V_46 = V_8 -> V_37 . V_38 -> V_39 ;
int V_53 = F_42 ( V_8 , V_52 ) ;
int V_47 ;
F_43 (port) {
if ( V_46 -> V_54 [ V_47 ] ) {
if ( ! V_53 )
V_53 = 1 ;
V_52 [ 0 ] |= 1 << ( V_47 + 1 ) ;
}
}
return V_53 ;
}
static int F_44 ( struct V_7 * V_8 , T_4 V_55 , T_4 V_56 ,
T_4 V_57 , char * V_52 , T_4 V_58 )
{
struct V_35 * V_46 = V_8 -> V_37 . V_38 -> V_39 ;
struct V_59 * V_60 ;
int V_42 = - V_51 ;
T_5 * V_61 = ( T_5 * ) V_52 ;
F_7 ( V_8 -> V_37 . V_38 ,
L_15 ,
V_8 , V_55 , V_56 , V_57 , V_52 , V_58 ) ;
V_57 -- ;
switch ( V_55 ) {
case V_62 :
if ( V_56 == V_63 ) {
F_7 ( V_8 -> V_37 . V_38 , L_16 ) ;
if ( F_36 ( V_57 ) ) {
F_35 ( V_46 , V_57 , 1 ) ;
V_42 = 0 ;
}
goto V_64;
}
break;
case V_65 :
switch ( V_56 ) {
case V_66 :
F_7 ( V_8 -> V_37 . V_38 ,
L_17 ) ;
if ( F_36 ( V_57 ) ) {
V_46 -> V_54 [ V_57 ] = 0 ;
V_46 -> V_67 [ V_57 ] = 0 ;
}
goto V_64;
case V_68 :
F_7 ( V_8 -> V_37 . V_38 ,
L_18 ) ;
if ( F_36 ( V_57 ) )
V_46 -> V_67 [ V_57 ] = 0 ;
goto V_64;
case V_63 :
F_7 ( V_8 -> V_37 . V_38 ,
L_19 ) ;
if ( F_36 ( V_57 ) ) {
F_35 ( V_46 , V_57 , 0 ) ;
return 0 ;
}
}
break;
}
V_42 = F_45 ( V_8 , V_55 , V_56 , V_57 + 1 , V_52 , V_58 ) ;
if ( V_42 )
goto V_64;
switch ( V_55 ) {
case V_69 :
V_60 = (struct V_59 * ) V_52 ;
F_7 ( V_8 -> V_37 . V_38 , L_20 ,
V_60 -> V_70 ) ;
V_60 -> V_70 &= ~ F_46 ( V_71 ) ;
V_60 -> V_70 |= F_46 ( 0x0001 ) ;
if ( V_46 -> V_72 ) {
V_60 -> V_70 &= ~ F_46 ( V_73 ) ;
V_60 -> V_70 |= F_46 ( 0x0008 | 0x0001 ) ;
}
F_7 ( V_8 -> V_37 . V_38 , L_21 ,
V_60 -> V_70 ) ;
return V_42 ;
case V_74 :
F_7 ( V_8 -> V_37 . V_38 , L_22 , V_57 ) ;
if ( F_36 ( V_57 ) ) {
if ( ! F_39 ( V_46 , V_57 ) )
* V_61 &= ~ F_47 ( V_75 ) ;
if ( V_46 -> V_54 [ V_57 ] )
* V_61 |= F_47 ( V_76 ) ;
if ( V_46 -> V_67 [ V_57 ] )
* V_61 |= F_47 ( V_77 ) ;
}
}
V_64:
return V_42 ;
}
static T_6 F_48 ( int V_78 , void * V_61 )
{
struct V_5 * V_6 = V_61 ;
struct V_35 * V_46 = V_6 -> V_11 . V_39 ;
int V_79 , V_80 , V_47 ;
F_43 (port) {
if ( F_49 ( V_46 -> V_81 [ V_47 ] ) == V_78 ) {
V_80 = V_46 -> V_81 [ V_47 ] ;
break;
}
}
if ( V_47 == V_82 ) {
F_18 ( & V_6 -> V_11 , L_23 ) ;
return V_83 ;
}
V_79 = F_40 ( V_80 ) ;
if ( ! V_79 ) {
F_35 ( V_46 , V_47 , 0 ) ;
V_46 -> V_67 [ V_47 ] = 1 ;
V_46 -> V_54 [ V_47 ] = 1 ;
}
F_7 ( & V_6 -> V_11 , L_24 ,
V_79 ? L_25 : L_26 ) ;
return V_83 ;
}
static int T_2 F_50 ( struct V_5 * V_6 )
{
struct V_84 * V_85 = V_6 -> V_11 . V_86 ;
int V_87 , V_80 ;
enum V_88 V_19 ;
struct V_35 * V_46 ;
T_5 V_44 ;
if ( ! V_85 )
return 0 ;
if ( ! V_6 -> V_11 . V_89 )
V_6 -> V_11 . V_89 = & V_90 ;
V_46 = F_51 ( & V_6 -> V_11 , sizeof( * V_46 ) , V_91 ) ;
if ( ! V_46 )
return - V_22 ;
if ( ! F_52 ( V_85 , L_27 , & V_44 ) )
V_46 -> V_44 = V_44 ;
F_43 (i) {
V_80 = F_53 ( V_85 , L_28 , V_87 , & V_19 ) ;
V_46 -> V_49 [ V_87 ] = V_80 ;
if ( ! F_37 ( V_80 ) )
continue;
V_46 -> V_50 [ V_87 ] = V_19 & V_92 ;
}
F_43 (i)
V_46 -> V_81 [ V_87 ] =
F_53 ( V_85 , L_29 , V_87 , & V_19 ) ;
V_6 -> V_11 . V_39 = V_46 ;
return 0 ;
}
static int T_2 F_50 ( struct V_5 * V_6 )
{
return 0 ;
}
static int T_2 F_54 ( struct V_5 * V_6 )
{
struct V_35 * V_46 ;
int V_87 ;
int V_80 ;
int V_42 ;
V_42 = F_50 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_46 = V_6 -> V_11 . V_39 ;
if ( V_46 ) {
F_43 (i) {
if ( ! F_37 ( V_46 -> V_49 [ V_87 ] ) )
continue;
V_80 = V_46 -> V_49 [ V_87 ] ;
V_42 = F_55 ( V_80 , L_30 ) ;
if ( V_42 ) {
F_18 ( & V_6 -> V_11 ,
L_31 , V_80 ) ;
continue;
}
V_42 = F_56 ( V_80 ,
! V_46 -> V_50 [ V_87 ] ) ;
if ( V_42 ) {
F_18 ( & V_6 -> V_11 ,
L_32 ,
V_80 , ! V_46 -> V_50 [ V_87 ] ) ;
F_57 ( V_80 ) ;
continue;
}
F_35 ( V_46 , V_87 , 1 ) ;
}
F_43 (i) {
if ( ! F_37 ( V_46 -> V_81 [ V_87 ] ) )
continue;
V_80 = V_46 -> V_81 [ V_87 ] ;
V_42 = F_55 ( V_80 , L_33 ) ;
if ( V_42 ) {
F_18 ( & V_6 -> V_11 ,
L_34 ,
V_80 ) ;
continue;
}
V_42 = F_58 ( V_80 ) ;
if ( V_42 ) {
F_18 ( & V_6 -> V_11 ,
L_35 ,
V_80 ) ;
F_57 ( V_80 ) ;
continue;
}
V_42 = F_59 ( F_49 ( V_80 ) ,
F_48 ,
V_34 , L_33 , V_6 ) ;
if ( V_42 ) {
F_57 ( V_80 ) ;
F_18 ( & V_6 -> V_11 ,
L_36 ) ;
}
}
}
F_60 ( & V_6 -> V_11 , 1 ) ;
return F_10 ( & V_93 , V_6 ) ;
}
static int T_3 F_61 ( struct V_5 * V_6 )
{
struct V_35 * V_46 = V_6 -> V_11 . V_39 ;
int V_87 ;
if ( V_46 ) {
F_43 (i) {
if ( ! F_37 ( V_46 -> V_49 [ V_87 ] ) )
continue;
F_35 ( V_46 , V_87 , 0 ) ;
F_57 ( V_46 -> V_49 [ V_87 ] ) ;
}
F_43 (i) {
if ( ! F_37 ( V_46 -> V_81 [ V_87 ] ) )
continue;
F_62 ( F_49 ( V_46 -> V_81 [ V_87 ] ) , V_6 ) ;
F_57 ( V_46 -> V_81 [ V_87 ] ) ;
}
}
F_60 ( & V_6 -> V_11 , 0 ) ;
F_27 ( F_6 ( V_6 ) , V_6 ) ;
return 0 ;
}
static int
F_63 ( struct V_5 * V_6 , T_7 V_94 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_40 * V_41 = F_21 ( V_8 ) ;
if ( F_64 ( & V_6 -> V_11 ) )
F_65 ( V_8 -> V_78 ) ;
if ( F_66 () ) {
F_67 ( V_41 ) ;
( void ) F_68 ( V_41 , & V_41 -> V_10 -> V_12 ) ;
F_3 () ;
}
return 0 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
if ( F_64 ( & V_6 -> V_11 ) )
F_70 ( V_8 -> V_78 ) ;
if ( ! V_4 )
F_1 () ;
F_71 ( V_8 ) ;
return 0 ;
}
