static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return;
F_2 ( V_2 -> V_4 , 48000000 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_3 = true ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_5 ( V_2 -> V_4 ) ;
F_5 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_5 ) ;
V_2 -> V_3 = false ;
}
static void F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ) ;
struct V_11 T_1 * V_12 = V_10 -> V_12 ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
F_9 ( & V_8 -> V_13 , L_1 ) ;
F_1 ( V_2 ) ;
F_10 ( 0 , & V_12 -> V_14 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ) ;
struct V_11 T_1 * V_12 = V_10 -> V_12 ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
F_9 ( & V_8 -> V_13 , L_2 ) ;
F_10 ( 0 , & V_12 -> V_14 ) ;
F_4 ( V_2 ) ;
}
static struct V_15 * F_12 ( void )
{
struct V_15 * V_15 ;
V_15 = F_13 ( L_3 ) ;
if ( F_14 ( V_15 ) )
V_15 = NULL ;
return V_15 ;
}
static int F_15 ( const struct V_16 * V_17 ,
struct V_7 * V_8 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_23 * V_13 = & V_8 -> V_13 ;
struct V_24 * V_25 ;
int V_26 ;
V_26 = F_16 ( V_8 , 0 ) ;
if ( V_26 < 0 ) {
F_9 ( V_13 , L_4 ) ;
return V_26 ;
}
V_10 = F_17 ( V_17 , V_13 , L_5 ) ;
if ( ! V_10 )
return - V_27 ;
V_2 = F_8 ( V_10 ) ;
V_25 = F_18 ( V_8 , V_28 , 0 ) ;
V_10 -> V_12 = F_19 ( V_13 , V_25 ) ;
if ( F_14 ( V_10 -> V_12 ) ) {
V_22 = F_20 ( V_10 -> V_12 ) ;
goto V_29;
}
V_10 -> V_30 = V_25 -> V_31 ;
V_10 -> V_32 = F_21 ( V_25 ) ;
V_2 -> V_6 = F_22 ( V_13 , L_6 ) ;
if ( F_14 ( V_2 -> V_6 ) ) {
F_23 ( V_13 , L_7 ) ;
V_22 = F_20 ( V_2 -> V_6 ) ;
goto V_29;
}
V_2 -> V_4 = F_22 ( V_13 , L_8 ) ;
if ( F_14 ( V_2 -> V_4 ) ) {
F_23 ( V_13 , L_9 ) ;
V_22 = F_20 ( V_2 -> V_4 ) ;
goto V_29;
}
V_2 -> V_5 = F_22 ( V_13 , L_10 ) ;
if ( F_14 ( V_2 -> V_5 ) ) {
F_23 ( V_13 , L_11 ) ;
V_22 = F_20 ( V_2 -> V_5 ) ;
goto V_29;
}
V_2 -> V_33 = F_12 () ;
if ( ! V_2 -> V_33 )
F_24 ( V_13 , L_12 ) ;
V_19 = V_10 -> V_34 . V_35 -> V_36 ;
V_21 = F_25 ( V_10 ) ;
V_21 -> V_37 = V_19 -> V_38 ;
F_6 ( V_8 ) ;
V_21 -> V_39 = V_40 ;
V_22 = F_26 ( V_10 , V_26 , V_41 ) ;
if ( V_22 == 0 ) {
F_27 ( V_10 -> V_34 . V_35 ) ;
return V_22 ;
}
F_11 ( V_8 ) ;
V_29:
F_28 ( V_10 ) ;
return V_22 ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
F_30 ( V_10 ) ;
F_11 ( V_8 ) ;
F_28 ( V_10 ) ;
}
static void F_31 ( struct V_18 * V_42 , int V_43 , int V_44 )
{
if ( ! F_32 ( V_43 ) )
return;
if ( ! F_33 ( V_42 -> V_45 [ V_43 ] ) )
return;
F_34 ( V_42 -> V_45 [ V_43 ] ,
V_42 -> V_46 [ V_43 ] ^ V_44 ) ;
}
static int F_35 ( struct V_18 * V_42 , int V_43 )
{
if ( ! F_32 ( V_43 ) )
return - V_47 ;
if ( ! F_33 ( V_42 -> V_45 [ V_43 ] ) )
return - V_47 ;
return F_36 ( V_42 -> V_45 [ V_43 ] ) ^
V_42 -> V_46 [ V_43 ] ;
}
static int F_37 ( struct V_9 * V_10 , char * V_48 )
{
struct V_18 * V_42 = V_10 -> V_34 . V_35 -> V_36 ;
int V_49 = F_38 ( V_10 , V_48 ) ;
int V_43 ;
F_39 (port) {
if ( V_42 -> V_50 [ V_43 ] ) {
if ( ! V_49 )
V_49 = 1 ;
V_48 [ 0 ] |= 1 << ( V_43 + 1 ) ;
}
}
return V_49 ;
}
static int F_40 ( struct V_15 * V_15 , T_2 V_51 )
{
T_3 V_52 ;
int V_53 ;
if ( ! V_15 )
return 0 ;
V_53 = F_41 ( V_15 , V_54 , & V_52 ) ;
if ( V_53 )
return V_53 ;
if ( V_51 )
V_52 |= V_55 ;
else
V_52 &= ~ V_55 ;
F_42 ( V_15 , V_54 , V_52 ) ;
return 0 ;
}
static int F_43 ( struct V_9 * V_10 , T_4 V_56 , T_4 V_57 ,
T_4 V_58 , char * V_48 , T_4 V_59 )
{
struct V_18 * V_42 = F_44 ( V_10 -> V_34 . V_35 ) ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_60 * V_61 ;
int V_53 = - V_47 ;
T_3 * V_62 = ( T_3 * ) V_48 ;
F_9 ( V_10 -> V_34 . V_35 ,
L_13 ,
V_10 , V_56 , V_57 , V_58 , V_48 , V_59 ) ;
V_58 -- ;
switch ( V_56 ) {
case V_63 :
switch ( V_57 ) {
case V_64 :
F_9 ( V_10 -> V_34 . V_35 , L_14 ) ;
if ( F_32 ( V_58 ) ) {
F_31 ( V_42 , V_58 , 1 ) ;
V_53 = 0 ;
}
goto V_65;
case V_66 :
F_9 ( V_10 -> V_34 . V_35 , L_15 ) ;
if ( F_32 ( V_58 ) ) {
F_40 ( V_2 -> V_33 ,
1 ) ;
return 0 ;
}
break;
}
break;
case V_67 :
switch ( V_57 ) {
case V_68 :
F_9 ( V_10 -> V_34 . V_35 ,
L_16 ) ;
if ( F_32 ( V_58 ) ) {
V_42 -> V_50 [ V_58 ] = 0 ;
V_42 -> V_69 [ V_58 ] = 0 ;
}
goto V_65;
case V_70 :
F_9 ( V_10 -> V_34 . V_35 ,
L_17 ) ;
if ( F_32 ( V_58 ) )
V_42 -> V_69 [ V_58 ] = 0 ;
goto V_65;
case V_64 :
F_9 ( V_10 -> V_34 . V_35 ,
L_18 ) ;
if ( F_32 ( V_58 ) ) {
F_31 ( V_42 , V_58 , 0 ) ;
return 0 ;
}
break;
case V_66 :
F_9 ( V_10 -> V_34 . V_35 , L_19 ) ;
if ( F_32 ( V_58 ) ) {
F_40 ( V_2 -> V_33 ,
0 ) ;
return 0 ;
}
break;
}
break;
}
V_53 = F_45 ( V_10 , V_56 , V_57 , V_58 + 1 , V_48 , V_59 ) ;
if ( V_53 )
goto V_65;
switch ( V_56 ) {
case V_71 :
V_61 = (struct V_60 * ) V_48 ;
F_9 ( V_10 -> V_34 . V_35 , L_20 ,
V_61 -> V_72 ) ;
V_61 -> V_72 &= ~ F_46 ( V_73 ) ;
V_61 -> V_72 |=
F_46 ( V_74 ) ;
if ( V_42 -> V_75 ) {
V_61 -> V_72 &= ~ F_46 ( V_76 ) ;
V_61 -> V_72 |=
F_46 ( V_77 ) ;
}
F_9 ( V_10 -> V_34 . V_35 , L_21 ,
V_61 -> V_72 ) ;
return V_53 ;
case V_78 :
F_9 ( V_10 -> V_34 . V_35 , L_22 , V_58 ) ;
if ( F_32 ( V_58 ) ) {
if ( ! F_35 ( V_42 , V_58 ) )
* V_62 &= ~ F_47 ( V_79 ) ;
if ( V_42 -> V_50 [ V_58 ] )
* V_62 |= F_47 ( V_80 ) ;
if ( V_42 -> V_69 [ V_58 ] )
* V_62 |= F_47 ( V_81 ) ;
}
}
V_65:
return V_53 ;
}
static T_5 F_48 ( int V_26 , void * V_62 )
{
struct V_7 * V_8 = V_62 ;
struct V_18 * V_42 = F_44 ( & V_8 -> V_13 ) ;
int V_82 , V_83 , V_43 ;
F_39 (port) {
if ( F_33 ( V_42 -> V_84 [ V_43 ] ) &&
F_49 ( V_42 -> V_84 [ V_43 ] ) == V_26 ) {
V_83 = V_42 -> V_84 [ V_43 ] ;
break;
}
}
if ( V_43 == V_85 ) {
F_23 ( & V_8 -> V_13 , L_23 ) ;
return V_86 ;
}
V_82 = F_36 ( V_83 ) ;
if ( ! V_82 ) {
F_31 ( V_42 , V_43 , 0 ) ;
V_42 -> V_69 [ V_43 ] = 1 ;
V_42 -> V_50 [ V_43 ] = 1 ;
}
F_9 ( & V_8 -> V_13 , L_24 ,
V_82 ? L_25 : L_26 ) ;
return V_86 ;
}
static int F_50 ( struct V_7 * V_8 )
{
struct V_87 * V_88 = V_8 -> V_13 . V_89 ;
struct V_18 * V_42 ;
int V_90 ;
int V_83 ;
int V_53 ;
enum V_91 V_92 ;
T_3 V_38 ;
V_53 = F_51 ( & V_8 -> V_13 , F_52 ( 32 ) ) ;
if ( V_53 )
return V_53 ;
V_42 = F_53 ( & V_8 -> V_13 , sizeof( * V_42 ) , V_93 ) ;
if ( ! V_42 )
return - V_27 ;
V_8 -> V_13 . V_36 = V_42 ;
if ( ! F_54 ( V_88 , L_27 , & V_38 ) )
V_42 -> V_38 = V_38 ;
F_39 (i) {
if ( V_90 >= V_42 -> V_38 ) {
V_42 -> V_45 [ V_90 ] = - V_47 ;
V_42 -> V_84 [ V_90 ] = - V_47 ;
continue;
}
V_83 = F_55 ( V_88 , L_28 , V_90 ,
& V_92 ) ;
V_42 -> V_45 [ V_90 ] = V_83 ;
if ( ! F_33 ( V_83 ) )
continue;
V_42 -> V_46 [ V_90 ] = V_92 & V_94 ;
V_53 = F_56 ( V_83 , L_29 ) ;
if ( V_53 ) {
F_23 ( & V_8 -> V_13 ,
L_30 , V_83 ) ;
continue;
}
V_53 = F_57 ( V_83 ,
! V_42 -> V_46 [ V_90 ] ) ;
if ( V_53 ) {
F_23 ( & V_8 -> V_13 ,
L_31 ,
V_83 , ! V_42 -> V_46 [ V_90 ] ) ;
F_58 ( V_83 ) ;
continue;
}
F_31 ( V_42 , V_90 , 1 ) ;
}
F_39 (i) {
if ( V_90 >= V_42 -> V_38 )
break;
V_42 -> V_84 [ V_90 ] =
F_55 ( V_88 , L_32 , V_90 , & V_92 ) ;
if ( ! F_33 ( V_42 -> V_84 [ V_90 ] ) )
continue;
V_83 = V_42 -> V_84 [ V_90 ] ;
V_53 = F_56 ( V_83 , L_33 ) ;
if ( V_53 ) {
F_23 ( & V_8 -> V_13 ,
L_34 ,
V_83 ) ;
continue;
}
V_53 = F_59 ( V_83 ) ;
if ( V_53 ) {
F_23 ( & V_8 -> V_13 ,
L_35 ,
V_83 ) ;
F_58 ( V_83 ) ;
continue;
}
V_53 = F_60 ( F_49 ( V_83 ) ,
F_48 ,
V_41 , L_33 , V_8 ) ;
if ( V_53 ) {
F_58 ( V_83 ) ;
F_23 ( & V_8 -> V_13 ,
L_36 ) ;
}
}
F_61 ( & V_8 -> V_13 , 1 ) ;
return F_15 ( & V_95 , V_8 ) ;
}
static int F_62 ( struct V_7 * V_8 )
{
struct V_18 * V_42 = F_44 ( & V_8 -> V_13 ) ;
int V_90 ;
if ( V_42 ) {
F_39 (i) {
if ( ! F_33 ( V_42 -> V_45 [ V_90 ] ) )
continue;
F_31 ( V_42 , V_90 , 0 ) ;
F_58 ( V_42 -> V_45 [ V_90 ] ) ;
}
F_39 (i) {
if ( ! F_33 ( V_42 -> V_84 [ V_90 ] ) )
continue;
F_63 ( F_49 ( V_42 -> V_84 [ V_90 ] ) , V_8 ) ;
F_58 ( V_42 -> V_84 [ V_90 ] ) ;
}
}
F_61 ( & V_8 -> V_13 , 0 ) ;
F_29 ( F_7 ( V_8 ) , V_8 ) ;
return 0 ;
}
static int T_6
F_64 ( struct V_23 * V_13 )
{
struct V_9 * V_10 = F_65 ( V_13 ) ;
struct V_20 * V_21 = F_25 ( V_10 ) ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
int V_53 ;
V_2 -> V_96 = F_66 ( V_13 )
&& ! F_67 () ;
if ( V_2 -> V_96 )
F_68 ( V_10 -> V_26 ) ;
F_40 ( V_2 -> V_33 , 1 ) ;
V_53 = F_69 ( V_10 , V_2 -> V_96 ) ;
if ( V_53 ) {
if ( V_2 -> V_96 )
F_70 ( V_10 -> V_26 ) ;
return V_53 ;
}
if ( ! V_2 -> V_96 ) {
V_21 -> V_97 = V_98 ;
( void ) F_71 ( V_21 , & V_21 -> V_12 -> V_14 ) ;
F_4 ( V_2 ) ;
}
return V_53 ;
}
static int T_6
F_72 ( struct V_23 * V_13 )
{
struct V_9 * V_10 = F_65 ( V_13 ) ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
if ( V_2 -> V_96 )
F_70 ( V_10 -> V_26 ) ;
F_1 ( V_2 ) ;
F_73 ( V_10 , false ) ;
F_40 ( V_2 -> V_33 , 0 ) ;
return 0 ;
}
static int T_7 F_74 ( void )
{
if ( F_75 () )
return - V_99 ;
F_76 ( L_37 V_100 L_38 , V_101 ) ;
F_77 ( & V_95 , & V_102 ) ;
V_95 . V_103 = F_37 ;
V_95 . V_104 = F_43 ;
return F_78 ( & V_105 ) ;
}
static void T_8 F_79 ( void )
{
F_80 ( & V_105 ) ;
}
