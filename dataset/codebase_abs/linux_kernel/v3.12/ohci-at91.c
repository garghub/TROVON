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
int V_17 ;
struct V_9 * V_10 = NULL ;
if ( V_8 -> V_18 != 2 ) {
F_13 ( L_3 ) ;
return - V_19 ;
}
if ( ( V_8 -> V_20 [ 0 ] . V_21 != V_22 )
|| ( V_8 -> V_20 [ 1 ] . V_21 != V_23 ) ) {
F_13 ( L_4 ) ;
return - V_19 ;
}
V_10 = F_14 ( V_16 , & V_8 -> V_13 , L_5 ) ;
if ( ! V_10 )
return - V_24 ;
V_10 -> V_25 = V_8 -> V_20 [ 0 ] . V_26 ;
V_10 -> V_27 = F_15 ( & V_8 -> V_20 [ 0 ] ) ;
if ( ! F_16 ( V_10 -> V_25 , V_10 -> V_27 , V_28 ) ) {
F_13 ( L_6 ) ;
V_17 = - V_29 ;
goto V_30;
}
V_10 -> V_12 = F_17 ( V_10 -> V_25 , V_10 -> V_27 ) ;
if ( ! V_10 -> V_12 ) {
F_13 ( L_7 ) ;
V_17 = - V_31 ;
goto V_32;
}
V_4 = F_18 ( & V_8 -> V_13 , L_8 ) ;
if ( F_19 ( V_4 ) ) {
F_20 ( & V_8 -> V_13 , L_9 ) ;
V_17 = F_21 ( V_4 ) ;
goto V_33;
}
V_5 = F_18 ( & V_8 -> V_13 , L_10 ) ;
if ( F_19 ( V_5 ) ) {
F_20 ( & V_8 -> V_13 , L_11 ) ;
V_17 = F_21 ( V_5 ) ;
goto V_34;
}
V_3 = F_18 ( & V_8 -> V_13 , L_12 ) ;
if ( F_19 ( V_3 ) ) {
F_20 ( & V_8 -> V_13 , L_13 ) ;
V_17 = F_21 ( V_3 ) ;
goto V_35;
}
if ( F_2 ( V_1 ) ) {
V_2 = F_18 ( & V_8 -> V_13 , L_14 ) ;
if ( F_19 ( V_2 ) ) {
F_20 ( & V_8 -> V_13 , L_15 ) ;
V_17 = F_21 ( V_2 ) ;
goto V_36;
}
}
F_7 ( V_8 ) ;
F_22 ( F_23 ( V_10 ) ) ;
V_17 = F_24 ( V_10 , V_8 -> V_20 [ 1 ] . V_26 , V_37 ) ;
if ( V_17 == 0 )
return V_17 ;
F_11 ( V_8 ) ;
if ( F_2 ( V_1 ) )
F_25 ( V_2 ) ;
V_36:
F_25 ( V_3 ) ;
V_35:
F_25 ( V_5 ) ;
V_34:
F_25 ( V_4 ) ;
V_33:
F_26 ( V_10 -> V_12 ) ;
V_32:
F_27 ( V_10 -> V_25 , V_10 -> V_27 ) ;
V_30:
F_28 ( V_10 ) ;
return V_17 ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
F_30 ( V_10 ) ;
F_11 ( V_8 ) ;
F_26 ( V_10 -> V_12 ) ;
F_27 ( V_10 -> V_25 , V_10 -> V_27 ) ;
F_28 ( V_10 ) ;
if ( F_2 ( V_1 ) )
F_25 ( V_2 ) ;
F_25 ( V_3 ) ;
F_25 ( V_5 ) ;
F_25 ( V_4 ) ;
V_5 = V_4 = V_3 = NULL ;
}
static int
F_31 ( struct V_9 * V_10 )
{
struct V_38 * V_39 = F_32 ( V_10 -> V_40 . V_41 ) ;
struct V_42 * V_43 = F_23 ( V_10 ) ;
int V_44 ;
if ( ( V_44 = F_33 ( V_43 ) ) < 0 )
return V_44 ;
V_43 -> V_45 = V_39 -> V_46 ;
return 0 ;
}
static int
F_34 ( struct V_9 * V_10 )
{
struct V_42 * V_43 = F_23 ( V_10 ) ;
int V_44 ;
if ( ( V_44 = F_35 ( V_43 ) ) < 0 ) {
F_20 ( V_10 -> V_40 . V_41 , L_16 ,
V_10 -> V_40 . V_47 ) ;
F_36 ( V_10 ) ;
return V_44 ;
}
return 0 ;
}
static void F_37 ( struct V_38 * V_48 , int V_49 , int V_50 )
{
if ( ! F_38 ( V_49 ) )
return;
if ( ! F_39 ( V_48 -> V_51 [ V_49 ] ) )
return;
F_40 ( V_48 -> V_51 [ V_49 ] ,
V_48 -> V_52 [ V_49 ] ^ V_50 ) ;
}
static int F_41 ( struct V_38 * V_48 , int V_49 )
{
if ( ! F_38 ( V_49 ) )
return - V_53 ;
if ( ! F_39 ( V_48 -> V_51 [ V_49 ] ) )
return - V_53 ;
return F_42 ( V_48 -> V_51 [ V_49 ] ) ^
V_48 -> V_52 [ V_49 ] ;
}
static int F_43 ( struct V_9 * V_10 , char * V_54 )
{
struct V_38 * V_48 = F_32 ( V_10 -> V_40 . V_41 ) ;
int V_55 = F_44 ( V_10 , V_54 ) ;
int V_49 ;
F_45 (port) {
if ( V_48 -> V_56 [ V_49 ] ) {
if ( ! V_55 )
V_55 = 1 ;
V_54 [ 0 ] |= 1 << ( V_49 + 1 ) ;
}
}
return V_55 ;
}
static int F_46 ( struct V_9 * V_10 , T_2 V_57 , T_2 V_58 ,
T_2 V_59 , char * V_54 , T_2 V_60 )
{
struct V_38 * V_48 = F_32 ( V_10 -> V_40 . V_41 ) ;
struct V_61 * V_62 ;
int V_44 = - V_53 ;
T_3 * V_63 = ( T_3 * ) V_54 ;
F_9 ( V_10 -> V_40 . V_41 ,
L_17 ,
V_10 , V_57 , V_58 , V_59 , V_54 , V_60 ) ;
V_59 -- ;
switch ( V_57 ) {
case V_64 :
if ( V_58 == V_65 ) {
F_9 ( V_10 -> V_40 . V_41 , L_18 ) ;
if ( F_38 ( V_59 ) ) {
F_37 ( V_48 , V_59 , 1 ) ;
V_44 = 0 ;
}
goto V_66;
}
break;
case V_67 :
switch ( V_58 ) {
case V_68 :
F_9 ( V_10 -> V_40 . V_41 ,
L_19 ) ;
if ( F_38 ( V_59 ) ) {
V_48 -> V_56 [ V_59 ] = 0 ;
V_48 -> V_69 [ V_59 ] = 0 ;
}
goto V_66;
case V_70 :
F_9 ( V_10 -> V_40 . V_41 ,
L_20 ) ;
if ( F_38 ( V_59 ) )
V_48 -> V_69 [ V_59 ] = 0 ;
goto V_66;
case V_65 :
F_9 ( V_10 -> V_40 . V_41 ,
L_21 ) ;
if ( F_38 ( V_59 ) ) {
F_37 ( V_48 , V_59 , 0 ) ;
return 0 ;
}
}
break;
}
V_44 = F_47 ( V_10 , V_57 , V_58 , V_59 + 1 , V_54 , V_60 ) ;
if ( V_44 )
goto V_66;
switch ( V_57 ) {
case V_71 :
V_62 = (struct V_61 * ) V_54 ;
F_9 ( V_10 -> V_40 . V_41 , L_22 ,
V_62 -> V_72 ) ;
V_62 -> V_72 &= ~ F_48 ( V_73 ) ;
V_62 -> V_72 |= F_48 ( 0x0001 ) ;
if ( V_48 -> V_74 ) {
V_62 -> V_72 &= ~ F_48 ( V_75 ) ;
V_62 -> V_72 |= F_48 ( 0x0008 | 0x0001 ) ;
}
F_9 ( V_10 -> V_40 . V_41 , L_23 ,
V_62 -> V_72 ) ;
return V_44 ;
case V_76 :
F_9 ( V_10 -> V_40 . V_41 , L_24 , V_59 ) ;
if ( F_38 ( V_59 ) ) {
if ( ! F_41 ( V_48 , V_59 ) )
* V_63 &= ~ F_49 ( V_77 ) ;
if ( V_48 -> V_56 [ V_59 ] )
* V_63 |= F_49 ( V_78 ) ;
if ( V_48 -> V_69 [ V_59 ] )
* V_63 |= F_49 ( V_79 ) ;
}
}
V_66:
return V_44 ;
}
static T_4 F_50 ( int V_80 , void * V_63 )
{
struct V_7 * V_8 = V_63 ;
struct V_38 * V_48 = F_32 ( & V_8 -> V_13 ) ;
int V_81 , V_82 , V_49 ;
F_45 (port) {
if ( F_39 ( V_48 -> V_83 [ V_49 ] ) &&
F_51 ( V_48 -> V_83 [ V_49 ] ) == V_80 ) {
V_82 = V_48 -> V_83 [ V_49 ] ;
break;
}
}
if ( V_49 == V_84 ) {
F_20 ( & V_8 -> V_13 , L_25 ) ;
return V_85 ;
}
V_81 = F_42 ( V_82 ) ;
if ( ! V_81 ) {
F_37 ( V_48 , V_49 , 0 ) ;
V_48 -> V_69 [ V_49 ] = 1 ;
V_48 -> V_56 [ V_49 ] = 1 ;
}
F_9 ( & V_8 -> V_13 , L_26 ,
V_81 ? L_27 : L_28 ) ;
return V_85 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_86 * V_87 = V_8 -> V_13 . V_88 ;
int V_89 , V_82 ;
enum V_90 V_21 ;
struct V_38 * V_48 ;
T_3 V_46 ;
if ( ! V_87 )
return 0 ;
if ( ! V_8 -> V_13 . V_91 )
V_8 -> V_13 . V_91 = & V_8 -> V_13 . V_92 ;
if ( ! V_8 -> V_13 . V_92 )
V_8 -> V_13 . V_92 = F_53 ( 32 ) ;
V_48 = F_54 ( & V_8 -> V_13 , sizeof( * V_48 ) , V_93 ) ;
if ( ! V_48 )
return - V_24 ;
if ( ! F_55 ( V_87 , L_29 , & V_46 ) )
V_48 -> V_46 = V_46 ;
F_45 (i) {
V_82 = F_56 ( V_87 , L_30 , V_89 , & V_21 ) ;
V_48 -> V_51 [ V_89 ] = V_82 ;
if ( ! F_39 ( V_82 ) )
continue;
V_48 -> V_52 [ V_89 ] = V_21 & V_94 ;
}
F_45 (i)
V_48 -> V_83 [ V_89 ] =
F_56 ( V_87 , L_31 , V_89 , & V_21 ) ;
V_8 -> V_13 . V_95 = V_48 ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_38 * V_48 ;
int V_89 ;
int V_82 ;
int V_44 ;
V_44 = F_52 ( V_8 ) ;
if ( V_44 )
return V_44 ;
V_48 = F_32 ( & V_8 -> V_13 ) ;
if ( V_48 ) {
F_45 (i) {
if ( V_89 >= V_48 -> V_46 ) {
V_48 -> V_51 [ V_89 ] = - V_53 ;
V_48 -> V_83 [ V_89 ] = - V_53 ;
break;
}
if ( ! F_39 ( V_48 -> V_51 [ V_89 ] ) )
continue;
V_82 = V_48 -> V_51 [ V_89 ] ;
V_44 = F_58 ( V_82 , L_32 ) ;
if ( V_44 ) {
F_20 ( & V_8 -> V_13 ,
L_33 , V_82 ) ;
continue;
}
V_44 = F_59 ( V_82 ,
! V_48 -> V_52 [ V_89 ] ) ;
if ( V_44 ) {
F_20 ( & V_8 -> V_13 ,
L_34 ,
V_82 , ! V_48 -> V_52 [ V_89 ] ) ;
F_60 ( V_82 ) ;
continue;
}
F_37 ( V_48 , V_89 , 1 ) ;
}
F_45 (i) {
if ( ! F_39 ( V_48 -> V_83 [ V_89 ] ) )
continue;
V_82 = V_48 -> V_83 [ V_89 ] ;
V_44 = F_58 ( V_82 , L_35 ) ;
if ( V_44 ) {
F_20 ( & V_8 -> V_13 ,
L_36 ,
V_82 ) ;
continue;
}
V_44 = F_61 ( V_82 ) ;
if ( V_44 ) {
F_20 ( & V_8 -> V_13 ,
L_37 ,
V_82 ) ;
F_60 ( V_82 ) ;
continue;
}
V_44 = F_62 ( F_51 ( V_82 ) ,
F_50 ,
V_37 , L_35 , V_8 ) ;
if ( V_44 ) {
F_60 ( V_82 ) ;
F_20 ( & V_8 -> V_13 ,
L_38 ) ;
}
}
}
F_63 ( & V_8 -> V_13 , 1 ) ;
return F_12 ( & V_96 , V_8 ) ;
}
static int F_64 ( struct V_7 * V_8 )
{
struct V_38 * V_48 = F_32 ( & V_8 -> V_13 ) ;
int V_89 ;
if ( V_48 ) {
F_45 (i) {
if ( ! F_39 ( V_48 -> V_51 [ V_89 ] ) )
continue;
F_37 ( V_48 , V_89 , 0 ) ;
F_60 ( V_48 -> V_51 [ V_89 ] ) ;
}
F_45 (i) {
if ( ! F_39 ( V_48 -> V_83 [ V_89 ] ) )
continue;
F_65 ( F_51 ( V_48 -> V_83 [ V_89 ] ) , V_8 ) ;
F_60 ( V_48 -> V_83 [ V_89 ] ) ;
}
}
F_63 ( & V_8 -> V_13 , 0 ) ;
F_29 ( F_8 ( V_8 ) , V_8 ) ;
return 0 ;
}
static int
F_66 ( struct V_7 * V_8 , T_5 V_97 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
struct V_42 * V_43 = F_23 ( V_10 ) ;
if ( F_67 ( & V_8 -> V_13 ) )
F_68 ( V_10 -> V_80 ) ;
if ( F_69 () ) {
F_70 ( V_43 ) ;
( void ) F_71 ( V_43 , & V_43 -> V_12 -> V_14 ) ;
F_5 () ;
}
return 0 ;
}
static int F_72 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
if ( F_67 ( & V_8 -> V_13 ) )
F_73 ( V_10 -> V_80 ) ;
if ( ! V_6 )
F_1 () ;
F_74 ( V_10 , false ) ;
return 0 ;
}
