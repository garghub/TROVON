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
V_25 = F_13 ( V_8 , 0 ) ;
if ( V_25 < 0 ) {
F_9 ( V_13 , L_3 ) ;
return V_25 ;
}
V_10 = F_14 ( V_16 , V_13 , L_4 ) ;
if ( ! V_10 )
return - V_26 ;
V_24 = F_15 ( V_8 , V_27 , 0 ) ;
V_10 -> V_12 = F_16 ( V_13 , V_24 ) ;
if ( F_17 ( V_10 -> V_12 ) ) {
V_21 = F_18 ( V_10 -> V_12 ) ;
goto V_28;
}
V_10 -> V_29 = V_24 -> V_30 ;
V_10 -> V_31 = F_19 ( V_24 ) ;
V_4 = F_20 ( V_13 , L_5 ) ;
if ( F_17 ( V_4 ) ) {
F_21 ( V_13 , L_6 ) ;
V_21 = F_18 ( V_4 ) ;
goto V_28;
}
V_5 = F_20 ( V_13 , L_7 ) ;
if ( F_17 ( V_5 ) ) {
F_21 ( V_13 , L_8 ) ;
V_21 = F_18 ( V_5 ) ;
goto V_28;
}
V_3 = F_20 ( V_13 , L_9 ) ;
if ( F_17 ( V_3 ) ) {
F_21 ( V_13 , L_10 ) ;
V_21 = F_18 ( V_3 ) ;
goto V_28;
}
if ( F_2 ( V_1 ) ) {
V_2 = F_20 ( V_13 , L_11 ) ;
if ( F_17 ( V_2 ) ) {
F_21 ( V_13 , L_12 ) ;
V_21 = F_18 ( V_2 ) ;
goto V_28;
}
}
V_18 = V_10 -> V_32 . V_33 -> V_34 ;
V_20 = F_22 ( V_10 ) ;
V_20 -> V_35 = V_18 -> V_36 ;
F_7 ( V_8 ) ;
V_21 = F_23 ( V_10 , V_25 , V_37 ) ;
if ( V_21 == 0 ) {
F_24 ( V_10 -> V_32 . V_33 ) ;
return V_21 ;
}
F_11 ( V_8 ) ;
V_28:
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
static void F_28 ( struct V_17 * V_38 , int V_39 , int V_40 )
{
if ( ! F_29 ( V_39 ) )
return;
if ( ! F_30 ( V_38 -> V_41 [ V_39 ] ) )
return;
F_31 ( V_38 -> V_41 [ V_39 ] ,
V_38 -> V_42 [ V_39 ] ^ V_40 ) ;
}
static int F_32 ( struct V_17 * V_38 , int V_39 )
{
if ( ! F_29 ( V_39 ) )
return - V_43 ;
if ( ! F_30 ( V_38 -> V_41 [ V_39 ] ) )
return - V_43 ;
return F_33 ( V_38 -> V_41 [ V_39 ] ) ^
V_38 -> V_42 [ V_39 ] ;
}
static int F_34 ( struct V_9 * V_10 , char * V_44 )
{
struct V_17 * V_38 = V_10 -> V_32 . V_33 -> V_34 ;
int V_45 = F_35 ( V_10 , V_44 ) ;
int V_39 ;
F_36 (port) {
if ( V_38 -> V_46 [ V_39 ] ) {
if ( ! V_45 )
V_45 = 1 ;
V_44 [ 0 ] |= 1 << ( V_39 + 1 ) ;
}
}
return V_45 ;
}
static int F_37 ( struct V_9 * V_10 , T_2 V_47 , T_2 V_48 ,
T_2 V_49 , char * V_44 , T_2 V_50 )
{
struct V_17 * V_38 = F_38 ( V_10 -> V_32 . V_33 ) ;
struct V_51 * V_52 ;
int V_53 = - V_43 ;
T_3 * V_54 = ( T_3 * ) V_44 ;
F_9 ( V_10 -> V_32 . V_33 ,
L_13 ,
V_10 , V_47 , V_48 , V_49 , V_44 , V_50 ) ;
V_49 -- ;
switch ( V_47 ) {
case V_55 :
if ( V_48 == V_56 ) {
F_9 ( V_10 -> V_32 . V_33 , L_14 ) ;
if ( F_29 ( V_49 ) ) {
F_28 ( V_38 , V_49 , 1 ) ;
V_53 = 0 ;
}
goto V_57;
}
break;
case V_58 :
switch ( V_48 ) {
case V_59 :
F_9 ( V_10 -> V_32 . V_33 ,
L_15 ) ;
if ( F_29 ( V_49 ) ) {
V_38 -> V_46 [ V_49 ] = 0 ;
V_38 -> V_60 [ V_49 ] = 0 ;
}
goto V_57;
case V_61 :
F_9 ( V_10 -> V_32 . V_33 ,
L_16 ) ;
if ( F_29 ( V_49 ) )
V_38 -> V_60 [ V_49 ] = 0 ;
goto V_57;
case V_56 :
F_9 ( V_10 -> V_32 . V_33 ,
L_17 ) ;
if ( F_29 ( V_49 ) ) {
F_28 ( V_38 , V_49 , 0 ) ;
return 0 ;
}
}
break;
}
V_53 = F_39 ( V_10 , V_47 , V_48 , V_49 + 1 , V_44 , V_50 ) ;
if ( V_53 )
goto V_57;
switch ( V_47 ) {
case V_62 :
V_52 = (struct V_51 * ) V_44 ;
F_9 ( V_10 -> V_32 . V_33 , L_18 ,
V_52 -> V_63 ) ;
V_52 -> V_63 &= ~ F_40 ( V_64 ) ;
V_52 -> V_63 |= F_40 ( 0x0001 ) ;
if ( V_38 -> V_65 ) {
V_52 -> V_63 &= ~ F_40 ( V_66 ) ;
V_52 -> V_63 |= F_40 ( 0x0008 | 0x0001 ) ;
}
F_9 ( V_10 -> V_32 . V_33 , L_19 ,
V_52 -> V_63 ) ;
return V_53 ;
case V_67 :
F_9 ( V_10 -> V_32 . V_33 , L_20 , V_49 ) ;
if ( F_29 ( V_49 ) ) {
if ( ! F_32 ( V_38 , V_49 ) )
* V_54 &= ~ F_41 ( V_68 ) ;
if ( V_38 -> V_46 [ V_49 ] )
* V_54 |= F_41 ( V_69 ) ;
if ( V_38 -> V_60 [ V_49 ] )
* V_54 |= F_41 ( V_70 ) ;
}
}
V_57:
return V_53 ;
}
static T_4 F_42 ( int V_25 , void * V_54 )
{
struct V_7 * V_8 = V_54 ;
struct V_17 * V_38 = F_38 ( & V_8 -> V_13 ) ;
int V_71 , V_72 , V_39 ;
F_36 (port) {
if ( F_30 ( V_38 -> V_73 [ V_39 ] ) &&
F_43 ( V_38 -> V_73 [ V_39 ] ) == V_25 ) {
V_72 = V_38 -> V_73 [ V_39 ] ;
break;
}
}
if ( V_39 == V_74 ) {
F_21 ( & V_8 -> V_13 , L_21 ) ;
return V_75 ;
}
V_71 = F_33 ( V_72 ) ;
if ( ! V_71 ) {
F_28 ( V_38 , V_39 , 0 ) ;
V_38 -> V_60 [ V_39 ] = 1 ;
V_38 -> V_46 [ V_39 ] = 1 ;
}
F_9 ( & V_8 -> V_13 , L_22 ,
V_71 ? L_23 : L_24 ) ;
return V_75 ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_76 * V_77 = V_8 -> V_13 . V_78 ;
int V_79 , V_72 , V_53 ;
enum V_80 V_81 ;
struct V_17 * V_38 ;
T_3 V_36 ;
if ( ! V_77 )
return 0 ;
V_53 = F_45 ( & V_8 -> V_13 , F_46 ( 32 ) ) ;
if ( V_53 )
return V_53 ;
V_38 = F_47 ( & V_8 -> V_13 , sizeof( * V_38 ) , V_82 ) ;
if ( ! V_38 )
return - V_26 ;
if ( ! F_48 ( V_77 , L_25 , & V_36 ) )
V_38 -> V_36 = V_36 ;
F_36 (i) {
V_72 = F_49 ( V_77 , L_26 , V_79 , & V_81 ) ;
V_38 -> V_41 [ V_79 ] = V_72 ;
if ( ! F_30 ( V_72 ) )
continue;
V_38 -> V_42 [ V_79 ] = V_81 & V_83 ;
}
F_36 (i)
V_38 -> V_73 [ V_79 ] =
F_49 ( V_77 , L_27 , V_79 , & V_81 ) ;
V_8 -> V_13 . V_34 = V_38 ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 )
{
return 0 ;
}
static int F_50 ( struct V_7 * V_8 )
{
struct V_17 * V_38 ;
int V_79 ;
int V_72 ;
int V_53 ;
V_53 = F_44 ( V_8 ) ;
if ( V_53 )
return V_53 ;
V_38 = F_38 ( & V_8 -> V_13 ) ;
if ( V_38 ) {
F_36 (i) {
if ( V_79 >= V_38 -> V_36 ) {
V_38 -> V_41 [ V_79 ] = - V_43 ;
V_38 -> V_73 [ V_79 ] = - V_43 ;
break;
}
if ( ! F_30 ( V_38 -> V_41 [ V_79 ] ) )
continue;
V_72 = V_38 -> V_41 [ V_79 ] ;
V_53 = F_51 ( V_72 , L_28 ) ;
if ( V_53 ) {
F_21 ( & V_8 -> V_13 ,
L_29 , V_72 ) ;
continue;
}
V_53 = F_52 ( V_72 ,
! V_38 -> V_42 [ V_79 ] ) ;
if ( V_53 ) {
F_21 ( & V_8 -> V_13 ,
L_30 ,
V_72 , ! V_38 -> V_42 [ V_79 ] ) ;
F_53 ( V_72 ) ;
continue;
}
F_28 ( V_38 , V_79 , 1 ) ;
}
F_36 (i) {
if ( ! F_30 ( V_38 -> V_73 [ V_79 ] ) )
continue;
V_72 = V_38 -> V_73 [ V_79 ] ;
V_53 = F_51 ( V_72 , L_31 ) ;
if ( V_53 ) {
F_21 ( & V_8 -> V_13 ,
L_32 ,
V_72 ) ;
continue;
}
V_53 = F_54 ( V_72 ) ;
if ( V_53 ) {
F_21 ( & V_8 -> V_13 ,
L_33 ,
V_72 ) ;
F_53 ( V_72 ) ;
continue;
}
V_53 = F_55 ( F_43 ( V_72 ) ,
F_42 ,
V_37 , L_31 , V_8 ) ;
if ( V_53 ) {
F_53 ( V_72 ) ;
F_21 ( & V_8 -> V_13 ,
L_34 ) ;
}
}
}
F_56 ( & V_8 -> V_13 , 1 ) ;
return F_12 ( & V_84 , V_8 ) ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_17 * V_38 = F_38 ( & V_8 -> V_13 ) ;
int V_79 ;
if ( V_38 ) {
F_36 (i) {
if ( ! F_30 ( V_38 -> V_41 [ V_79 ] ) )
continue;
F_28 ( V_38 , V_79 , 0 ) ;
F_53 ( V_38 -> V_41 [ V_79 ] ) ;
}
F_36 (i) {
if ( ! F_30 ( V_38 -> V_73 [ V_79 ] ) )
continue;
F_58 ( F_43 ( V_38 -> V_73 [ V_79 ] ) , V_8 ) ;
F_53 ( V_38 -> V_73 [ V_79 ] ) ;
}
}
F_56 ( & V_8 -> V_13 , 0 ) ;
F_26 ( F_8 ( V_8 ) , V_8 ) ;
return 0 ;
}
static int
F_59 ( struct V_7 * V_8 , T_5 V_85 )
{
struct V_9 * V_10 = F_8 ( V_8 ) ;
struct V_19 * V_20 = F_22 ( V_10 ) ;
bool V_86 = F_60 ( & V_8 -> V_13 ) ;
int V_53 ;
if ( V_86 )
F_61 ( V_10 -> V_25 ) ;
V_53 = F_62 ( V_10 , V_86 ) ;
if ( V_53 ) {
F_63 ( V_10 -> V_25 ) ;
return V_53 ;
}
if ( F_64 () ) {
V_20 -> V_87 = F_65 ( V_20 , & V_20 -> V_12 -> V_14 ) ;
V_20 -> V_87 &= V_88 ;
F_66 ( V_20 , V_20 -> V_87 , & V_20 -> V_12 -> V_14 ) ;
V_20 -> V_89 = V_90 ;
( void ) F_65 ( V_20 , & V_20 -> V_12 -> V_14 ) ;
F_5 () ;
}
return V_53 ;
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
return - V_91 ;
F_71 ( L_35 V_92 L_36 , V_93 ) ;
F_72 ( & V_84 , NULL ) ;
V_84 . V_94 = F_34 ;
V_84 . V_95 = F_37 ;
return F_73 ( & V_96 ) ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_96 ) ;
}
