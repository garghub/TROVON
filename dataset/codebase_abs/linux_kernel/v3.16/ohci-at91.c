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
V_10 = F_15 ( V_16 , V_13 , L_5 ) ;
if ( ! V_10 )
return - V_28 ;
V_10 -> V_29 = V_24 -> V_30 ;
V_10 -> V_31 = F_16 ( V_24 ) ;
V_10 -> V_12 = F_17 ( V_13 , V_24 ) ;
if ( F_18 ( V_10 -> V_12 ) ) {
V_21 = F_19 ( V_10 -> V_12 ) ;
goto V_32;
}
V_4 = F_20 ( V_13 , L_6 ) ;
if ( F_18 ( V_4 ) ) {
F_21 ( V_13 , L_7 ) ;
V_21 = F_19 ( V_4 ) ;
goto V_32;
}
V_5 = F_20 ( V_13 , L_8 ) ;
if ( F_18 ( V_5 ) ) {
F_21 ( V_13 , L_9 ) ;
V_21 = F_19 ( V_5 ) ;
goto V_32;
}
V_3 = F_20 ( V_13 , L_10 ) ;
if ( F_18 ( V_3 ) ) {
F_21 ( V_13 , L_11 ) ;
V_21 = F_19 ( V_3 ) ;
goto V_32;
}
if ( F_2 ( V_1 ) ) {
V_2 = F_20 ( V_13 , L_12 ) ;
if ( F_18 ( V_2 ) ) {
F_21 ( V_13 , L_13 ) ;
V_21 = F_19 ( V_2 ) ;
goto V_32;
}
}
V_18 = V_10 -> V_33 . V_34 -> V_35 ;
V_20 = F_22 ( V_10 ) ;
V_20 -> V_36 = V_18 -> V_37 ;
F_7 ( V_8 ) ;
V_21 = F_23 ( V_10 , V_25 , V_38 ) ;
if ( V_21 == 0 ) {
F_24 ( V_10 -> V_33 . V_34 ) ;
return V_21 ;
}
F_11 ( V_8 ) ;
V_32:
F_25 ( V_10 ) ;
return V_21 ;
}
static void F_26 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
F_27 ( V_10 ) ;
F_11 ( V_8 ) ;
F_25 ( V_10 ) ;
}
static void F_28 ( struct V_17 * V_39 , int V_40 , int V_41 )
{
if ( ! F_29 ( V_40 ) )
return;
if ( ! F_30 ( V_39 -> V_42 [ V_40 ] ) )
return;
F_31 ( V_39 -> V_42 [ V_40 ] ,
V_39 -> V_43 [ V_40 ] ^ V_41 ) ;
}
static int F_32 ( struct V_17 * V_39 , int V_40 )
{
if ( ! F_29 ( V_40 ) )
return - V_44 ;
if ( ! F_30 ( V_39 -> V_42 [ V_40 ] ) )
return - V_44 ;
return F_33 ( V_39 -> V_42 [ V_40 ] ) ^
V_39 -> V_43 [ V_40 ] ;
}
static int F_34 ( struct V_9 * V_10 , char * V_45 )
{
struct V_17 * V_39 = V_10 -> V_33 . V_34 -> V_35 ;
int V_46 = F_35 ( V_10 , V_45 ) ;
int V_40 ;
F_36 (port) {
if ( V_39 -> V_47 [ V_40 ] ) {
if ( ! V_46 )
V_46 = 1 ;
V_45 [ 0 ] |= 1 << ( V_40 + 1 ) ;
}
}
return V_46 ;
}
static int F_37 ( struct V_9 * V_10 , T_2 V_48 , T_2 V_49 ,
T_2 V_50 , char * V_45 , T_2 V_51 )
{
struct V_17 * V_39 = F_38 ( V_10 -> V_33 . V_34 ) ;
struct V_52 * V_53 ;
int V_54 = - V_44 ;
T_3 * V_55 = ( T_3 * ) V_45 ;
F_9 ( V_10 -> V_33 . V_34 ,
L_14 ,
V_10 , V_48 , V_49 , V_50 , V_45 , V_51 ) ;
V_50 -- ;
switch ( V_48 ) {
case V_56 :
if ( V_49 == V_57 ) {
F_9 ( V_10 -> V_33 . V_34 , L_15 ) ;
if ( F_29 ( V_50 ) ) {
F_28 ( V_39 , V_50 , 1 ) ;
V_54 = 0 ;
}
goto V_58;
}
break;
case V_59 :
switch ( V_49 ) {
case V_60 :
F_9 ( V_10 -> V_33 . V_34 ,
L_16 ) ;
if ( F_29 ( V_50 ) ) {
V_39 -> V_47 [ V_50 ] = 0 ;
V_39 -> V_61 [ V_50 ] = 0 ;
}
goto V_58;
case V_62 :
F_9 ( V_10 -> V_33 . V_34 ,
L_17 ) ;
if ( F_29 ( V_50 ) )
V_39 -> V_61 [ V_50 ] = 0 ;
goto V_58;
case V_57 :
F_9 ( V_10 -> V_33 . V_34 ,
L_18 ) ;
if ( F_29 ( V_50 ) ) {
F_28 ( V_39 , V_50 , 0 ) ;
return 0 ;
}
}
break;
}
V_54 = F_39 ( V_10 , V_48 , V_49 , V_50 + 1 , V_45 , V_51 ) ;
if ( V_54 )
goto V_58;
switch ( V_48 ) {
case V_63 :
V_53 = (struct V_52 * ) V_45 ;
F_9 ( V_10 -> V_33 . V_34 , L_19 ,
V_53 -> V_64 ) ;
V_53 -> V_64 &= ~ F_40 ( V_65 ) ;
V_53 -> V_64 |= F_40 ( 0x0001 ) ;
if ( V_39 -> V_66 ) {
V_53 -> V_64 &= ~ F_40 ( V_67 ) ;
V_53 -> V_64 |= F_40 ( 0x0008 | 0x0001 ) ;
}
F_9 ( V_10 -> V_33 . V_34 , L_20 ,
V_53 -> V_64 ) ;
return V_54 ;
case V_68 :
F_9 ( V_10 -> V_33 . V_34 , L_21 , V_50 ) ;
if ( F_29 ( V_50 ) ) {
if ( ! F_32 ( V_39 , V_50 ) )
* V_55 &= ~ F_41 ( V_69 ) ;
if ( V_39 -> V_47 [ V_50 ] )
* V_55 |= F_41 ( V_70 ) ;
if ( V_39 -> V_61 [ V_50 ] )
* V_55 |= F_41 ( V_71 ) ;
}
}
V_58:
return V_54 ;
}
static T_4 F_42 ( int V_25 , void * V_55 )
{
struct V_7 * V_8 = V_55 ;
struct V_17 * V_39 = F_38 ( & V_8 -> V_13 ) ;
int V_72 , V_73 , V_40 ;
F_36 (port) {
if ( F_30 ( V_39 -> V_74 [ V_40 ] ) &&
F_43 ( V_39 -> V_74 [ V_40 ] ) == V_25 ) {
V_73 = V_39 -> V_74 [ V_40 ] ;
break;
}
}
if ( V_40 == V_75 ) {
F_21 ( & V_8 -> V_13 , L_22 ) ;
return V_76 ;
}
V_72 = F_33 ( V_73 ) ;
if ( ! V_72 ) {
F_28 ( V_39 , V_40 , 0 ) ;
V_39 -> V_61 [ V_40 ] = 1 ;
V_39 -> V_47 [ V_40 ] = 1 ;
}
F_9 ( & V_8 -> V_13 , L_23 ,
V_72 ? L_24 : L_25 ) ;
return V_76 ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_77 * V_78 = V_8 -> V_13 . V_79 ;
int V_80 , V_73 , V_54 ;
enum V_81 V_82 ;
struct V_17 * V_39 ;
T_3 V_37 ;
if ( ! V_78 )
return 0 ;
V_54 = F_45 ( & V_8 -> V_13 , F_46 ( 32 ) ) ;
if ( V_54 )
return V_54 ;
V_39 = F_47 ( & V_8 -> V_13 , sizeof( * V_39 ) , V_83 ) ;
if ( ! V_39 )
return - V_28 ;
if ( ! F_48 ( V_78 , L_26 , & V_37 ) )
V_39 -> V_37 = V_37 ;
F_36 (i) {
V_73 = F_49 ( V_78 , L_27 , V_80 , & V_82 ) ;
V_39 -> V_42 [ V_80 ] = V_73 ;
if ( ! F_30 ( V_73 ) )
continue;
V_39 -> V_43 [ V_80 ] = V_82 & V_84 ;
}
F_36 (i)
V_39 -> V_74 [ V_80 ] =
F_49 ( V_78 , L_28 , V_80 , & V_82 ) ;
V_8 -> V_13 . V_35 = V_39 ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_50 ( struct V_7 * V_8 )
{
struct V_17 * V_39 ;
int V_80 ;
int V_73 ;
int V_54 ;
V_54 = F_44 ( V_8 ) ;
if ( V_54 )
return V_54 ;
V_39 = F_38 ( & V_8 -> V_13 ) ;
if ( V_39 ) {
F_36 (i) {
if ( V_80 >= V_39 -> V_37 ) {
V_39 -> V_42 [ V_80 ] = - V_44 ;
V_39 -> V_74 [ V_80 ] = - V_44 ;
break;
}
if ( ! F_30 ( V_39 -> V_42 [ V_80 ] ) )
continue;
V_73 = V_39 -> V_42 [ V_80 ] ;
V_54 = F_51 ( V_73 , L_29 ) ;
if ( V_54 ) {
F_21 ( & V_8 -> V_13 ,
L_30 , V_73 ) ;
continue;
}
V_54 = F_52 ( V_73 ,
! V_39 -> V_43 [ V_80 ] ) ;
if ( V_54 ) {
F_21 ( & V_8 -> V_13 ,
L_31 ,
V_73 , ! V_39 -> V_43 [ V_80 ] ) ;
F_53 ( V_73 ) ;
continue;
}
F_28 ( V_39 , V_80 , 1 ) ;
}
F_36 (i) {
if ( ! F_30 ( V_39 -> V_74 [ V_80 ] ) )
continue;
V_73 = V_39 -> V_74 [ V_80 ] ;
V_54 = F_51 ( V_73 , L_32 ) ;
if ( V_54 ) {
F_21 ( & V_8 -> V_13 ,
L_33 ,
V_73 ) ;
continue;
}
V_54 = F_54 ( V_73 ) ;
if ( V_54 ) {
F_21 ( & V_8 -> V_13 ,
L_34 ,
V_73 ) ;
F_53 ( V_73 ) ;
continue;
}
V_54 = F_55 ( F_43 ( V_73 ) ,
F_42 ,
V_38 , L_32 , V_8 ) ;
if ( V_54 ) {
F_53 ( V_73 ) ;
F_21 ( & V_8 -> V_13 ,
L_35 ) ;
}
}
}
F_56 ( & V_8 -> V_13 , 1 ) ;
return F_12 ( & V_85 , V_8 ) ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_17 * V_39 = F_38 ( & V_8 -> V_13 ) ;
int V_80 ;
if ( V_39 ) {
F_36 (i) {
if ( ! F_30 ( V_39 -> V_42 [ V_80 ] ) )
continue;
F_28 ( V_39 , V_80 , 0 ) ;
F_53 ( V_39 -> V_42 [ V_80 ] ) ;
}
F_36 (i) {
if ( ! F_30 ( V_39 -> V_74 [ V_80 ] ) )
continue;
F_58 ( F_43 ( V_39 -> V_74 [ V_80 ] ) , V_8 ) ;
F_53 ( V_39 -> V_74 [ V_80 ] ) ;
}
}
F_56 ( & V_8 -> V_13 , 0 ) ;
F_26 ( F_8 ( V_8 ) , V_8 ) ;
return 0 ;
}
static int
F_59 ( struct V_7 * V_8 , T_5 V_86 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
struct V_19 * V_20 = F_22 ( V_10 ) ;
bool V_87 = F_60 ( & V_8 -> V_13 ) ;
int V_54 ;
if ( V_87 )
F_61 ( V_10 -> V_25 ) ;
V_54 = F_62 ( V_10 , V_87 ) ;
if ( V_54 ) {
F_63 ( V_10 -> V_25 ) ;
return V_54 ;
}
if ( F_64 () ) {
V_20 -> V_88 = F_65 ( V_20 , & V_20 -> V_12 -> V_14 ) ;
V_20 -> V_88 &= V_89 ;
F_66 ( V_20 , V_20 -> V_88 , & V_20 -> V_12 -> V_14 ) ;
V_20 -> V_90 = V_91 ;
( void ) F_65 ( V_20 , & V_20 -> V_12 -> V_14 ) ;
F_5 () ;
}
return V_54 ;
}
static int F_67 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
if ( F_60 ( & V_8 -> V_13 ) )
F_63 ( V_10 -> V_25 ) ;
if ( ! V_6 )
F_1 () ;
F_68 ( V_10 , false ) ;
return 0 ;
}
static int T_6 F_69 ( void )
{
if ( F_70 () )
return - V_92 ;
F_71 ( L_36 V_93 L_37 , V_94 ) ;
F_72 ( & V_85 , NULL ) ;
V_85 . V_95 = F_34 ;
V_85 . V_96 = F_37 ;
return F_73 ( & V_97 ) ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_97 ) ;
}
