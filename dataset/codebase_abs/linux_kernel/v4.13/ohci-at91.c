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
F_33 ( V_42 -> V_45 [ V_43 ] , V_44 ) ;
}
static int F_34 ( struct V_18 * V_42 , int V_43 )
{
if ( ! F_32 ( V_43 ) )
return - V_46 ;
return F_35 ( V_42 -> V_45 [ V_43 ] ) ;
}
static int F_36 ( struct V_9 * V_10 , char * V_47 )
{
struct V_18 * V_42 = V_10 -> V_34 . V_35 -> V_36 ;
int V_48 = F_37 ( V_10 , V_47 ) ;
int V_43 ;
F_38 (port) {
if ( V_42 -> V_49 [ V_43 ] ) {
if ( ! V_48 )
V_48 = 1 ;
V_47 [ 0 ] |= 1 << ( V_43 + 1 ) ;
}
}
return V_48 ;
}
static int F_39 ( struct V_15 * V_15 , T_2 V_50 )
{
T_3 V_51 ;
int V_52 ;
if ( ! V_15 )
return 0 ;
V_52 = F_40 ( V_15 , V_53 , & V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_50 )
V_51 |= V_54 ;
else
V_51 &= ~ V_54 ;
F_41 ( V_15 , V_53 , V_51 ) ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 , T_4 V_55 , T_4 V_56 ,
T_4 V_57 , char * V_47 , T_4 V_58 )
{
struct V_18 * V_42 = F_43 ( V_10 -> V_34 . V_35 ) ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_59 * V_60 ;
int V_52 = - V_46 ;
T_3 * V_61 = ( T_3 * ) V_47 ;
F_9 ( V_10 -> V_34 . V_35 ,
L_13 ,
V_10 , V_55 , V_56 , V_57 , V_47 , V_58 ) ;
V_57 -- ;
switch ( V_55 ) {
case V_62 :
switch ( V_56 ) {
case V_63 :
F_9 ( V_10 -> V_34 . V_35 , L_14 ) ;
if ( F_32 ( V_57 ) ) {
F_31 ( V_42 , V_57 , 1 ) ;
V_52 = 0 ;
}
goto V_64;
case V_65 :
F_9 ( V_10 -> V_34 . V_35 , L_15 ) ;
if ( F_32 ( V_57 ) && V_2 -> V_33 ) {
F_39 ( V_2 -> V_33 ,
1 ) ;
return 0 ;
}
break;
}
break;
case V_66 :
switch ( V_56 ) {
case V_67 :
F_9 ( V_10 -> V_34 . V_35 ,
L_16 ) ;
if ( F_32 ( V_57 ) ) {
V_42 -> V_49 [ V_57 ] = 0 ;
V_42 -> V_68 [ V_57 ] = 0 ;
}
goto V_64;
case V_69 :
F_9 ( V_10 -> V_34 . V_35 ,
L_17 ) ;
if ( F_32 ( V_57 ) )
V_42 -> V_68 [ V_57 ] = 0 ;
goto V_64;
case V_63 :
F_9 ( V_10 -> V_34 . V_35 ,
L_18 ) ;
if ( F_32 ( V_57 ) ) {
F_31 ( V_42 , V_57 , 0 ) ;
return 0 ;
}
break;
case V_65 :
F_9 ( V_10 -> V_34 . V_35 , L_19 ) ;
if ( F_32 ( V_57 ) && V_2 -> V_33 ) {
F_39 ( V_2 -> V_33 ,
0 ) ;
return 0 ;
}
break;
}
break;
}
V_52 = F_44 ( V_10 , V_55 , V_56 , V_57 + 1 , V_47 , V_58 ) ;
if ( V_52 )
goto V_64;
switch ( V_55 ) {
case V_70 :
V_60 = (struct V_59 * ) V_47 ;
F_9 ( V_10 -> V_34 . V_35 , L_20 ,
V_60 -> V_71 ) ;
V_60 -> V_71 &= ~ F_45 ( V_72 ) ;
V_60 -> V_71 |=
F_45 ( V_73 ) ;
if ( V_42 -> V_74 ) {
V_60 -> V_71 &= ~ F_45 ( V_75 ) ;
V_60 -> V_71 |=
F_45 ( V_76 ) ;
}
F_9 ( V_10 -> V_34 . V_35 , L_21 ,
V_60 -> V_71 ) ;
return V_52 ;
case V_77 :
F_9 ( V_10 -> V_34 . V_35 , L_22 , V_57 ) ;
if ( F_32 ( V_57 ) ) {
if ( ! F_34 ( V_42 , V_57 ) )
* V_61 &= ~ F_46 ( V_78 ) ;
if ( V_42 -> V_49 [ V_57 ] )
* V_61 |= F_46 ( V_79 ) ;
if ( V_42 -> V_68 [ V_57 ] )
* V_61 |= F_46 ( V_80 ) ;
}
}
V_64:
return V_52 ;
}
static T_5 F_47 ( int V_26 , void * V_61 )
{
struct V_7 * V_8 = V_61 ;
struct V_18 * V_42 = F_43 ( & V_8 -> V_13 ) ;
int V_81 , V_43 ;
F_38 (port) {
if ( F_48 ( V_42 -> V_82 [ V_43 ] ) == V_26 )
break;
}
if ( V_43 == V_83 ) {
F_23 ( & V_8 -> V_13 , L_23 ) ;
return V_84 ;
}
V_81 = F_35 ( V_42 -> V_82 [ V_43 ] ) ;
if ( ! V_81 ) {
F_31 ( V_42 , V_43 , 0 ) ;
V_42 -> V_68 [ V_43 ] = 1 ;
V_42 -> V_49 [ V_43 ] = 1 ;
}
F_9 ( & V_8 -> V_13 , L_24 ,
V_81 ? L_25 : L_26 ) ;
return V_84 ;
}
static int F_49 ( struct V_7 * V_8 )
{
struct V_85 * V_86 = V_8 -> V_13 . V_87 ;
struct V_18 * V_42 ;
int V_88 ;
int V_52 ;
int V_29 ;
T_3 V_38 ;
V_52 = F_50 ( & V_8 -> V_13 , F_51 ( 32 ) ) ;
if ( V_52 )
return V_52 ;
V_42 = F_52 ( & V_8 -> V_13 , sizeof( * V_42 ) , V_89 ) ;
if ( ! V_42 )
return - V_27 ;
V_8 -> V_13 . V_36 = V_42 ;
if ( ! F_53 ( V_86 , L_27 , & V_38 ) )
V_42 -> V_38 = V_38 ;
F_38 (i) {
if ( V_88 >= V_42 -> V_38 )
break;
V_42 -> V_45 [ V_88 ] =
F_54 ( & V_8 -> V_13 , L_28 ,
V_88 , V_90 ) ;
if ( F_14 ( V_42 -> V_45 [ V_88 ] ) ) {
V_29 = F_20 ( V_42 -> V_45 [ V_88 ] ) ;
F_23 ( & V_8 -> V_13 , L_29 , V_29 ) ;
continue;
}
}
F_38 (i) {
if ( V_88 >= V_42 -> V_38 )
break;
V_42 -> V_82 [ V_88 ] =
F_54 ( & V_8 -> V_13 , L_30 ,
V_88 , V_91 ) ;
if ( F_14 ( V_42 -> V_82 [ V_88 ] ) ) {
V_29 = F_20 ( V_42 -> V_82 [ V_88 ] ) ;
F_23 ( & V_8 -> V_13 , L_31 , V_29 ) ;
continue;
}
V_52 = F_55 ( & V_8 -> V_13 ,
F_48 ( V_42 -> V_82 [ V_88 ] ) ,
F_47 ,
V_41 ,
L_32 , V_8 ) ;
if ( V_52 )
F_56 ( & V_8 -> V_13 , L_33 ) ;
}
F_57 ( & V_8 -> V_13 , 1 ) ;
return F_15 ( & V_92 , V_8 ) ;
}
static int F_58 ( struct V_7 * V_8 )
{
struct V_18 * V_42 = F_43 ( & V_8 -> V_13 ) ;
int V_88 ;
if ( V_42 ) {
F_38 (i)
F_31 ( V_42 , V_88 , 0 ) ;
}
F_57 ( & V_8 -> V_13 , 0 ) ;
F_29 ( F_7 ( V_8 ) , V_8 ) ;
return 0 ;
}
static int T_6
F_59 ( struct V_23 * V_13 )
{
struct V_9 * V_10 = F_60 ( V_13 ) ;
struct V_20 * V_21 = F_25 ( V_10 ) ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
int V_52 ;
V_2 -> V_93 = F_61 ( V_13 )
&& ! F_62 () ;
if ( V_2 -> V_93 )
F_63 ( V_10 -> V_26 ) ;
F_39 ( V_2 -> V_33 , 1 ) ;
V_52 = F_64 ( V_10 , V_2 -> V_93 ) ;
if ( V_52 ) {
if ( V_2 -> V_93 )
F_65 ( V_10 -> V_26 ) ;
return V_52 ;
}
if ( ! V_2 -> V_93 ) {
V_21 -> V_94 = V_95 ;
( void ) F_66 ( V_21 , & V_21 -> V_12 -> V_14 ) ;
F_4 ( V_2 ) ;
}
return V_52 ;
}
static int T_6
F_67 ( struct V_23 * V_13 )
{
struct V_9 * V_10 = F_60 ( V_13 ) ;
struct V_1 * V_2 = F_8 ( V_10 ) ;
if ( V_2 -> V_93 )
F_65 ( V_10 -> V_26 ) ;
F_1 ( V_2 ) ;
F_68 ( V_10 , false ) ;
F_39 ( V_2 -> V_33 , 0 ) ;
return 0 ;
}
static int T_7 F_69 ( void )
{
if ( F_70 () )
return - V_96 ;
F_71 ( L_34 V_97 L_35 , V_98 ) ;
F_72 ( & V_92 , & V_99 ) ;
V_92 . V_100 = F_36 ;
V_92 . V_101 = F_42 ;
return F_73 ( & V_102 ) ;
}
static void T_8 F_74 ( void )
{
F_75 ( & V_102 ) ;
}
